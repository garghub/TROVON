static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
V_2 -> V_3 = V_2 -> V_5 -> V_6 -> V_7 ( V_2 , V_8 ) << 16 ;
V_2 -> V_3 |= V_2 -> V_5 -> V_6 -> V_7 ( V_2 , V_9 ) ;
if ( V_2 -> V_3 == 0x0 || V_2 -> V_3 == 0xffffffff )
return false ;
if ( V_3 != 0 && V_3 != ( V_2 -> V_3 & V_4 ) )
return false ;
return true ;
}
int F_2 ( struct V_1 * V_2 , bool V_10 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_11 * V_6 = V_2 -> V_5 -> V_6 ;
if ( V_10 && V_6 -> V_12 ) {
V_6 -> V_12 ( V_2 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
return 1 ;
}
if ( V_6 -> V_13 )
V_6 -> V_13 ( V_2 ) ;
if ( V_6 -> V_12 )
V_6 -> V_12 ( V_2 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
return 0 ;
return - V_14 ;
}
static int F_3 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
return 1 ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_19 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_19 ) ;
}
