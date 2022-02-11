T_1
F_1 ( const struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , int V_6 , int * V_7 )
{
T_1 V_8 = F_2 ( V_5 , 0x022438 ) ;
T_1 V_9 = F_2 ( V_5 , 0x02243c ) ;
T_1 V_10 = V_9 / V_8 ;
T_1 V_11 = V_6 * V_10 ;
T_1 V_12 = 0 ;
while ( V_10 -- ) {
if ( ! ( V_3 & F_3 ( V_11 ) ) )
V_12 += V_2 -> V_13 ( V_5 , V_11 ) ;
V_11 ++ ;
}
* V_7 = 1 ;
return V_12 ;
}
int
F_4 ( struct V_14 * V_15 , struct V_16 * * V_17 )
{
return F_5 ( & V_18 , V_15 , V_17 ) ;
}
