void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
double V_3 ;
V_1 -> V_4 ++ ;
V_3 = V_2 - V_1 -> V_5 ;
V_1 -> V_5 += V_3 / V_1 -> V_4 ;
V_1 -> V_6 += V_3 * ( V_2 - V_1 -> V_5 ) ;
}
double F_2 ( struct V_1 * V_1 )
{
return V_1 -> V_5 ;
}
double F_3 ( struct V_1 * V_1 )
{
double V_7 , V_8 ;
if ( ! V_1 -> V_4 )
return 0.0 ;
V_7 = V_1 -> V_6 / ( V_1 -> V_4 - 1 ) ;
V_8 = V_7 / V_1 -> V_4 ;
return sqrt ( V_8 ) ;
}
double F_4 ( double V_9 , double V_10 )
{
double V_11 = 0.0 ;
if ( V_10 )
V_11 = 100.0 * V_9 / V_10 ;
return V_11 ;
}
