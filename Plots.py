
import numpy as np
import matplotlib.pyplot as plt


# ============================================================
# READ 211 DATA
# ============================================================

data_211 = np.loadtxt("difference_211.txt")

P_211 = data_211[:, 0]
difference_211 = data_211[:, 1]
uncertainty_211 = data_211[:, 2]


# ============================================================
# READ 2212 DATA
# ============================================================

data_2212 = np.loadtxt("difference_2212.txt")

P_2212 = data_2212[:, 0]
difference_2212 = data_2212[:, 1]
uncertainty_2212 = data_2212[:, 2]


# ============================================================
# FUNCTION TO PLOT DATA AND TRENDLINE
# ============================================================

def PlotDifference(P, difference, uncertainty, title, filename):

    fig, ax = plt.subplots(facecolor='white')
    ax.set_facecolor('white')

    # Plot data with error bars
    ax.errorbar(
        P,
        difference,
        yerr=uncertainty,
        fmt='o',
        capsize=4,
        label='Data'
    )

    # Calculate linear trendline: y = mx + b
    m, b = np.polyfit(P, difference, 1)

    # Calculate predicted values
    predicted = m * P + b

    # Calculate R-squared
    SS_res = np.sum((difference - predicted)**2)
    SS_tot = np.sum((difference - np.mean(difference))**2)

    R_squared = 1 - (SS_res / SS_tot) if SS_tot > 0 else np.nan

    # Plot the trendline
    P_line = np.linspace(min(P), max(P), 200)

    ax.plot(
        P_line,
        m * P_line + b,
        color='red',
        label='Linear trendline'
    )

    # Horizontal zero line
    ax.axhline(
        0,
        linestyle='--',
        color='black'
    )

    # Axis labels and title
    ax.set_xlabel("Momentum P")
    ax.set_ylabel("Mean difference")
    ax.set_title(title)

    ax.grid(True)

    # ========================================================
    # LEGEND (KEY)
    # ========================================================

    ax.legend(loc='upper right')

    # ========================================================
    # EQUATION AND R-SQUARED BELOW LEGEND
    # ========================================================

    equation = (
        f"y = {m:.4f}x {b:+.4f}\n"
        f"$R^2$ = {R_squared:.4f}"
    )

    ax.text(
        0.95,
        0.80,
        equation,
        transform=ax.transAxes,
        fontsize=11,
        horizontalalignment='right',
        verticalalignment='top',
        bbox=dict(
            facecolor='white',
            edgecolor='gray',
            alpha=0.9
        )
    )

    plt.tight_layout()

    # ========================================================
    # SAVE PLOT
    # ========================================================

    plt.savefig(
        filename,
        dpi=300,
        facecolor='white',
        transparent=False
    )

    # Print results in terminal
    print(f"\n{title}")
    print(f"Trendline: y = {m:.6f}x {b:+.6f}")
    print(f"R-squared: {R_squared:.6f}")

    plt.show()
    plt.close()


# ============================================================
# PLOT 211 - (-211)
# ============================================================

PlotDifference(
    P_211,
    difference_211,
    uncertainty_211,
    "211 - (-211)",
    "difference_211.png"
)


# ============================================================
# PLOT 2212 - (-2212)
# ============================================================

PlotDifference(
    P_2212,
    difference_2212,
    uncertainty_2212,
    "2212 - (-2212)",
    "difference_2212.png"
)
