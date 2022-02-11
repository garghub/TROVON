static void T_1
F_1 ( struct V_1 * V_2 , char * * V_3 , struct V_4 * V_5 )
{
T_2 * V_6 = F_2 ( V_7 ) ;
* V_3 = F_2 ( V_6 -> V_8 ) ;
#ifdef F_3
if( V_6 -> V_9 )
{
V_10 = F_4 ( V_6 -> V_11 ) ;
V_12 = V_10 + V_6 -> V_13 ;
}
#endif
V_14 . V_15 [ 0 ] . V_16 = V_6 -> V_17 ;
* V_5 = V_14 ;
}
