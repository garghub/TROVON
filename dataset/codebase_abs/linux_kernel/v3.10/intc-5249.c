static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 &= ~ ( 0x1 << ( V_2 -> V_5 - V_6 ) ) ;
F_3 ( V_3 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 |= ( 0x1 << ( V_2 -> V_5 - V_6 ) ) ;
F_3 ( V_3 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( 0x1 << ( V_2 -> V_5 - V_6 ) , V_7 ) ;
}
static int T_2 F_6 ( void )
{
int V_5 ;
for ( V_5 = V_6 ; ( V_5 <= V_8 ) ; V_5 ++ ) {
F_7 ( V_5 , & V_9 ) ;
F_8 ( V_5 , V_10 ) ;
}
return 0 ;
}
