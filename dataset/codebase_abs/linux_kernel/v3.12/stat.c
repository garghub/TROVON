void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
double V_3 ;
V_1 -> V_4 ++ ;
V_3 = V_2 - V_1 -> V_5 ;
V_1 -> V_5 += V_3 / V_1 -> V_4 ;
V_1 -> V_6 += V_3 * ( V_2 - V_1 -> V_5 ) ;
if ( V_2 > V_1 -> V_7 )
V_1 -> V_7 = V_2 ;
if ( V_2 < V_1 -> V_8 )
V_1 -> V_8 = V_2 ;
}
double F_2 ( struct V_1 * V_1 )
{
return V_1 -> V_5 ;
}
double F_3 ( struct V_1 * V_1 )
{
double V_9 , V_10 ;
if ( V_1 -> V_4 < 2 )
return 0.0 ;
V_9 = V_1 -> V_6 / ( V_1 -> V_4 - 1 ) ;
V_10 = V_9 / V_1 -> V_4 ;
return sqrt ( V_10 ) ;
}
double F_4 ( double V_11 , double V_12 )
{
double V_13 = 0.0 ;
if ( V_12 )
V_13 = 100.0 * V_11 / V_12 ;
return V_13 ;
}
