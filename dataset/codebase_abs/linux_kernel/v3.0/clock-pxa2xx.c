void F_1 ( struct V_1 * V_1 )
{
V_2 |= 1 << V_1 -> V_3 ;
}
void F_2 ( struct V_1 * V_1 )
{
V_2 &= ~ ( 1 << V_1 -> V_3 ) ;
}
static int F_3 ( void )
{
V_4 = V_2 ;
return 0 ;
}
static void F_4 ( void )
{
V_2 = V_4 ;
}
