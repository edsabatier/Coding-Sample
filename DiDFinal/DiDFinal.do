/* SETUP */
clear all           
set more off

cd "C:\Users\irony\OneDrive\Desktop\STATA\DiDFinal"
log using "DiDFinal.log", name("DiDFinal") replace

/* REPLICATION */
use "data\maindata.dta"
xtreg   lnhouseprice   L1.wtotaldeaths time9 time10 time12 time13 time14 time15 time16 time17 time18 time19 time21 time22 time23 time24 time25 time26 time27 time28 time29 time30 time31 time32 time33 time34 time35 time36 time37 time38 time39 time40 time41 time42 time43 time44 time45 time46 time47 time48 time49 time50 time51 time52 time53 time54 time55 time56 time57 time58 time59 time60 time61 time62 time63 time64 time65 time66 time67 time68 time69 time70 time71 time72 time73 time74 time75 time76 time77 time78 time79 time80 time81 time82 time83 time84 time85 time86 time87 time88 time89 time90 time91 time92 time93 time94 time95 time96 time97 time98 time99 time100 time101 time102 time103 time104 time105, fe cluster(region)


/* DiD APPROACH */
//Restructuring data
//We need to keep unemployment, region, time, lnhouseprice, wtotaldeaths, houseprice, and totaldeaths
keep unemp time region lnhouseprice wtotaldeaths houseprice totaldeaths

//Naive, with no dynamic effects
did_multiplegt lnhouseprice region time totaldeaths
graph save "results/STDDiD.gph", replace
graph export "results/STDDiD.png", replace
ereturn list
scalar t_stat = e(effect_0)/e(se_effect_0)
scalar p_val = 2*normal(-abs(t_stat))

di as text "T-stat: " as result t_stat
di as text "P-Test: " as result p_val

//Dynamic Effects Without Threshold
did_multiplegt lnhouseprice region time totaldeaths, robust_dynamic dynamic(4) average_effect placebo(4) longdiff_placebo breps(50) cluster(region) threshold_stable_treatment(4)
graph save "results/DynamicDiD.gph", replace
graph export "results/DynamicDiD.png", replace
ereturn list
scalar t_stat = e(effect_0)/e(se_effect_0)
scalar p_val = 2*normal(-abs(t_stat))

di as text "T-stat: " as result t_stat
di as text "P-Test: " as result p_val