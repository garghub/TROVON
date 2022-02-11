T_1 F_1 ( void * V_1 , const struct V_2 * V_3 ,
T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
T_1 V_8 = V_3 -> V_8 ;
struct V_9 * V_10 ;
if ( V_3 -> V_11 & V_12 && V_8 & 0x300 )
V_8 = ( V_8 + 0x3ff ) & ~ 0x3ff ;
V_8 = ( V_8 + V_5 - 1 ) & ~ ( V_5 - 1 ) ;
V_10 = F_2 ( V_7 -> V_13 ) ;
if ( V_10 -> V_14 )
return V_10 -> V_14 ( V_7 , V_3 ,
V_8 , V_4 , V_5 ) ;
return V_8 ;
}
void F_3 ( struct V_15 * V_13 )
{
F_4 ( V_13 ) ;
}
