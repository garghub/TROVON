T_1
F_1 ( const struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , int V_6 , int * V_7 )
{
T_1 V_8 = F_2 ( V_5 , 0x022450 ) ;
T_1 V_9 = F_2 ( V_5 , 0x022458 ) ;
T_1 V_10 = V_6 * V_9 ;
T_1 V_11 = 0 ;
if ( ! ( F_2 ( V_5 , 0x021d38 ) & F_3 ( V_6 ) ) ) {
T_1 V_12 = F_2 ( V_5 , 0x021d70 + ( V_6 * 4 ) ) ;
T_1 V_13 = ~ V_12 & ( ( 1 << V_8 ) - 1 ) ;
while ( V_9 -- ) {
if ( ! ( V_3 & ( 1 << V_10 ) ) )
V_11 += V_2 -> V_14 ( V_5 , V_10 ) ;
V_10 ++ ;
}
* V_7 = F_4 ( V_13 ) ;
}
return V_11 ;
}
int
F_5 ( struct V_15 * V_16 , struct V_17 * * V_18 )
{
return F_6 ( & V_19 , V_16 , V_18 ) ;
}
