# Nuclear-decay
## Learn about nuclear decay by doing different simulations of stochastic processes. The package is composed by different programs.

## (1) Decay of one nucleus.

- Learn how to obtain the **distribution of durations**, D(t), for different decay probabilities.
- Compare the obtained distributions with the **[binomial distribution](https://en.wikipedia.org/wiki/Binomial_distribution#:~:text=In%20probability%20theory%20and%20statistics,%2Fone%20(with%20probability%20p))**. Fit parameters.

**N1_Radioactivity_2020529.cpp**: Use this program for 1 nucleus calculations. The histogram funccionality is not implemented inside yet. You can use **2020608_Integer_Histogram.cpp** for post-processing the duration histogram. Compilation. In both cases ca be compiled directly with the g++ C++ compiler. The only parameters you can set is the *decay probability* p=1/s setting s and the *number of realizations*.

## (2) Decay of an arbitrary number of nucleus.
