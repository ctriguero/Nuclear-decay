# Nuclear-decay
## Learn about nuclear decay by doing different simulations of stochastic processes. The package is composed by different programs.

## (1) Decay of one nucleus.

- Do first the experiment with a die (or a coin) for example.

If you roll the die 10 times you can obtain: 10 times the result 1 roll. Only 5 times the result 2 rolls. etc etc, Only 1 times the result 10 rolls. This is unfair. To have the same possibilities for all the possible results we can multiplicate the frequency times the number of rolls. In this way the reweighted distribution is properly calculated. The price to pay is larger fluctuations in the distribution when the number of rolls grow. If the number of rolls i large the error or fluctuations in the distribution es larger. For example in a normal die. The event of getting one is measured over several trials and the following results are obtained:

| Number of rolls to get 1  |  Frequency     | Reweighted distribution |
|---------------------------|----------------|-------------------------|
|1                          |  10            |  1 x 10=10              |
|2                          |  6             |  2 x 6=12               |
|3                          |  4             |  3 x 4=12               |
|4                          |  3             |  4 x 3=12               |
|5                          |  2             |  5 x 2=10               |
|6                          |  1             |  6 x 1=6                |
|7                          |  0             |  7 x 0=0                |
|8                          |  1             |  8 x 1=8                |
|9                          |  2             |  9 x 2=18               |
|10                         |  0             |  10 x 0=0               |

- Plot the graph Number of rolls to get 1 vs Reweighted distribution. Observe where is the maximum of the distribution.

- Learn how to obtain the **distribution of durations**, D(t), for different decay probabilities (**duration** is the time you have to wait for the nucleus to decay). To obtain the right distribution you will need to learn how to reweight a distribution.
- Compare the obtained distributions with the **[binomial distribution](https://en.wikipedia.org/wiki/Binomial_distribution#:~:text=In%20probability%20theory%20and%20statistics,%2Fone%20(with%20probability%20p))**. Fit parameters.

**N1_Radioactivity_2020529.cpp**: Use this program for 1 nucleus calculations. The histogram functionality is not implemented inside yet. You can use **2020608_Integer_Histogram.cpp** for post-processing the duration histogram. Compilation. In both cases ca be compiled directly with the g++ C++ compiler. The only parameters you can set are the *decay probability* p=1/s setting s and the *number of realizations*.

After the generation of the numbers **N1_Radioactivity_2020529.cpp** reweights the distribution in order to get the correct distribution as was explained in the example with the die.


## (2) Decay of an arbitrary number of nuclei.

- Obtain the decay law experimentally with a set of (at least 20) dice or coins. Take into account that the event of decay (getting an specific number) is independent. There is no correlation between the dice. Build a table with number of rolls and undecayed nucleus.

| Number of rolls           |  Undecayed nucleus     |
|---------------------------|----------------|
|0                          |  20            |
|1                          |  12            |
|2                          |  6             |
|3                          |  4             |
|4                          |  3             |


- Plot the graph  Undecayed nucleus vs Number of rolls.
- Obtain the half life for the dice experiment. In other words, how many number of rolls are needed to have half of the initial dice undecayed?. Check that the obtained half-life is compatible with:

$T_{1/2}=\frac{\ln(2)}{\lambda}$

<a href="https://www.codecogs.com/eqnedit.php?latex=T_{1/2}=\frac{\ln(2)}{\lambda}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?T_{1/2}=\frac{\ln(2)}{\lambda}" title="T_{1/2}=\frac{\ln(2)}{\lambda}" /></a>
