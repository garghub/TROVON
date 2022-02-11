static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( ! F_2 ( V_2 , 0 ) )
return V_8 ;
if ( F_3 ( V_4 ) != V_9 )
F_4 ( F_5 ( V_2 ) -> V_10 ,
F_6 ( F_7 ( V_4 ) ) -> V_11 -> V_12 -> V_13 ) ;
else
F_4 ( F_5 ( V_2 ) -> V_10 , F_7 ( V_4 ) -> V_13 ) ;
V_2 -> V_14 = V_15 ;
return V_6 -> V_16 ;
}
static int F_8 ( const struct V_17 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_18 ;
if ( V_19 && V_6 -> V_16 == V_20 )
return - V_21 ;
V_18 = V_4 -> V_18 & ~ ( 1 << V_22 ) ;
if ( ( strcmp ( V_4 -> V_23 , L_1 ) != 0 ||
V_18 & ~ ( 1 << V_24 ) ) &&
( strcmp ( V_4 -> V_23 , L_2 ) != 0 ||
V_18 & ~ ( 1 << V_9 ) ) )
return - V_21 ;
if ( F_9 ( V_6 -> V_16 ) )
return - V_21 ;
return 0 ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_25 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_25 ) ;
}
