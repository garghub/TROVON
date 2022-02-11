static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 + V_5 ) ;
V_3 &= ~ ( 0x1 << ( V_2 -> V_6 - V_7 ) ) ;
F_3 ( V_3 , V_4 + V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 + V_5 ) ;
V_3 |= ( 0x1 << ( V_2 -> V_6 - V_7 ) ) ;
F_3 ( V_3 , V_4 + V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( 0x1 << ( V_2 -> V_6 - V_7 ) , V_4 + V_8 ) ;
}
static int T_2 F_6 ( void )
{
int V_6 ;
for ( V_6 = V_7 ; ( V_6 <= V_9 ) ; V_6 ++ ) {
F_7 ( V_6 , & V_10 ) ;
F_8 ( V_6 , V_11 ) ;
}
return 0 ;
}
