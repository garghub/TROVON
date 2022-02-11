static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( ! F_2 ( V_2 , 0 ) )
return V_8 ;
memcpy ( F_3 ( V_2 ) -> V_9 , V_6 -> V_10 , V_11 ) ;
return V_6 -> V_12 ;
}
static int F_4 ( const struct V_13 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_14 ;
if ( V_15 && V_6 -> V_12 == V_16 )
return - V_17 ;
V_14 = V_4 -> V_14 & ~ ( 1 << V_18 ) ;
if ( ( strcmp ( V_4 -> V_19 , L_1 ) != 0 ||
( V_14 & ~ ( ( 1 << V_20 ) |
( 1 << V_21 ) ) ) ) &&
( strcmp ( V_4 -> V_19 , L_2 ) != 0 ||
V_14 & ~ ( 1 << V_22 ) ) )
return - V_17 ;
if ( V_23 )
return - V_17 ;
return 0 ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_24 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_24 ) ;
}
