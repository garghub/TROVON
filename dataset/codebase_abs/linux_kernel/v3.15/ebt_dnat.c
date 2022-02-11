static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( ! F_2 ( V_2 , 0 ) )
return V_8 ;
F_3 ( F_4 ( V_2 ) -> V_9 , V_6 -> V_10 ) ;
return V_6 -> V_11 ;
}
static int F_5 ( const struct V_12 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_13 ;
if ( V_14 && V_6 -> V_11 == V_15 )
return - V_16 ;
V_13 = V_4 -> V_13 & ~ ( 1 << V_17 ) ;
if ( ( strcmp ( V_4 -> V_18 , L_1 ) != 0 ||
( V_13 & ~ ( ( 1 << V_19 ) |
( 1 << V_20 ) ) ) ) &&
( strcmp ( V_4 -> V_18 , L_2 ) != 0 ||
V_13 & ~ ( 1 << V_21 ) ) )
return - V_16 ;
if ( V_22 )
return - V_16 ;
return 0 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_23 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_23 ) ;
}
