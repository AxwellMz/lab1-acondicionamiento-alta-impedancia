"""
Cálculo de errores porcentuales - Laboratorio 1, Instrumentación Biomédica III (UNMSM)

    e% = (V_medido - V_teórico) / V_teórico * 100

Uso:
    pip install pandas matplotlib
    python analysis/calculo_errores.py
"""
from pathlib import Path
import pandas as pd

DATA = Path(__file__).resolve().parent.parent / "data"

t1 = pd.read_csv(DATA / "tabla1_gpio25_teorico.csv")
t2 = pd.read_csv(DATA / "tabla2_nodoA_sin_buffer.csv")
t3 = pd.read_csv(DATA / "tabla3_nodoB_con_buffer.csv")

df = t1[["pH", "V_verificado_V"]].rename(columns={"V_verificado_V": "V_teorico"})
df = df.merge(t2, on="pH").merge(t3, on="pH")


def err(v_med, v_teo):
    return (v_med - v_teo) / v_teo * 100


df["e_NodoA_mult_%"] = err(df["V_multimetro_V"], df["V_teorico"])
df["e_NodoA_osc_%"] = err(df["V_osciloscopio_V"], df["V_teorico"])
df["e_TL084_%"] = err(df["V_TL084_V"], df["V_teorico"])
df["e_LM324_%"] = err(df["V_LM324_V"], df["V_teorico"])

# Resistencia de entrada efectiva del instrumento (divisor con Rs = 1 MOhm)
RS = 1e6
df["Rin_mult_MOhm"] = RS * df["V_multimetro_V"] / (df["V_teorico"] - df["V_multimetro_V"]) / 1e6
df["Rin_osc_MOhm"] = RS * df["V_osciloscopio_V"] / (df["V_teorico"] - df["V_osciloscopio_V"]) / 1e6

pd.set_option("display.width", 160)
print(df.round(3).to_string(index=False))
df.round(4).to_csv(DATA / "resultados_errores.csv", index=False)
print(f"\nResultados guardados en {DATA / 'resultados_errores.csv'}")

try:
    import matplotlib.pyplot as plt

    cols = ["e_NodoA_mult_%", "e_NodoA_osc_%", "e_TL084_%", "e_LM324_%"]
    labels = ["Nodo A - multímetro", "Nodo A - osciloscopio", "Nodo B - TL084", "Nodo B - LM324"]
    plot_df = df.set_index("pH")[cols]
    plot_df.columns = labels
    ax = plot_df.plot.bar(figsize=(9, 5), rot=0, color=["#e4572e", "#f3a712", "#29335c", "#669bbc"])
    ax.axhline(0, color="black", lw=0.8)
    for c in ax.containers:
        ax.bar_label(c, fmt="%.1f", fontsize=7, padding=2)
    ax.set_ylabel("Error relativo (%)")
    ax.set_title("Error porcentual: sin buffer (Nodo A) vs. con buffer (Nodo B)")
    ax.set_xlabel("pH simulado")
    ax.legend(loc="lower left", bbox_to_anchor=(0, 1.08), ncol=4, fontsize=8, frameon=False)
    ax.set_ylim(-68, 10)
    plt.tight_layout()
    out = Path(__file__).resolve().parent / "grafico_errores.png"
    plt.savefig(out, dpi=150)
    print(f"Gráfico guardado en {out}")
except ImportError:
    print("matplotlib no instalado: se omite el gráfico.")
