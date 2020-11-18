# Nuclear-decay
## Learn about nuclear decay by doing different simulations of stochastic processes. The package is composed by different programs.

## (1) Decay of one nucleus.

- Learn how to obtain the **distribution of durations**, D(t), for different decay probabilities.
- Compare the obtained distributions with the **[binomial distribution](https://en.wikipedia.org/wiki/Binomial_distribution#:~:text=In%20probability%20theory%20and%20statistics,%2Fone%20(with%20probability%20p))**. Fit parameters.

**N1_Radioactivity_2020529.cpp**: Use this program for 1 nucleus calculations. The histogram functionality is not implemented inside yet. You can use **2020608_Integer_Histogram.cpp** for post-processing the duration histogram. Compilation. In both cases ca be compiled directly with the g++ C++ compiler. The only parameters you can set is the *decay probability* p=1/s setting s and the *number of realizations*.

After the generation of the numbers **N1_Radioactivity_2020529.cpp** reweights the distribution in order to get the correct distribution. For example:

If you roll the die 10 times you can obtain: 10 times the result 1 roll. Only 5 times the result 2 rolls. etc etc, Only 1 times the result 10 rolls. This is unfair. To have the same possibilities for all the possible results we can multiplicate the frequency times the number of rolls. In this way the reweighted distribution is properly calculated. The price to pay is larger fluctuations in the distribution when the number of rolls grow. If the number of rolls i large the error or fluctuations in the distribution es larger. For example in a normal die. The event of getting one is measured over several trials and the following results are obtained:

Number of rolls to get 1  |  Frequency     | Reweighted distribution
----------------------------------------------------------------------
1                         |  10            |  1 * 10=10
2                         |  6             |  2 * 6=12
3                         |  4             |  3 * 4=12
4                         |  3             |  4 * 3=12
5                         |  2             |  5 * 2=10
6                         |  1             |  6 * 1=6
7                         |  0             |  7 * 0=0
8                         |  1             |  8 * 1=8
9                         |  2             |  9 * 2=18
10                        |  0             |  10 * 0=0

## (2) Decay of an arbitrary number of nucleus.
