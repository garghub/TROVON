int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 = 0 ;
if ( V_2 -> V_6 -> V_7 < 2 && F_2 ( V_2 -> V_8 ) < 12 )
V_5 = V_9 [ V_2 -> V_6 -> V_7 ] [ F_2 ( V_2 -> V_8 ) ] ;
return V_5 + V_10 + 4 ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_8 ) == 6 && V_2 -> V_6 -> V_7 == 0 ) {
F_4 ( V_2 , V_11 , 0 ) ;
F_4 ( V_2 , V_12 , 0x10 ) ;
F_5 ( V_2 , V_13 , 4 ) ;
}
}
int F_6 ( struct V_1 * V_2 )
{
return 0 ;
}
