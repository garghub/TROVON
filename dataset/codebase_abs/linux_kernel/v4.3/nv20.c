static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 = ( V_6 -> V_8 >= 0x25 ? 0x300 : 0x900 ) ;
T_1 V_9 , V_10 ;
struct V_11 * V_12 ;
V_12 = F_2 ( V_6 ) ;
if ( ! V_12 ) {
F_3 ( V_4 , L_1 ) ;
return;
}
F_4 ( V_6 , V_13 , V_14 ) ;
F_5 ( V_6 , V_15 , 0 , V_7 ) ;
V_9 = F_6 ( V_6 , 0x10020c ) ;
for ( V_10 = V_9 ; V_10 > 0x2000000 ; V_10 -= 0x2000000 )
F_7 ( V_12 , V_10 - 4 , V_10 ) ;
V_9 = F_6 ( V_6 , 0x10020c ) ;
if ( V_9 != F_8 ( V_12 , V_9 - 4 ) )
F_5 ( V_6 , V_15 , V_7 , 0 ) ;
F_9 ( V_12 ) ;
}
int
F_10 ( struct V_5 * V_6 , int V_16 ,
struct V_1 * * V_17 )
{
return F_11 ( & V_18 , V_6 , V_16 , V_17 ) ;
}
