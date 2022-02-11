static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( ! F_2 ( V_2 , 0 ) )
return V_8 ;
if ( V_4 -> V_9 != V_10 )
F_3 ( F_4 ( V_2 ) -> V_11 ,
F_5 ( V_4 -> V_12 ) -> V_13 -> V_14 -> V_15 ) ;
else
F_3 ( F_4 ( V_2 ) -> V_11 , V_4 -> V_12 -> V_15 ) ;
V_2 -> V_16 = V_17 ;
return V_6 -> V_18 ;
}
static int F_6 ( const struct V_19 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_20 ;
if ( V_21 && V_6 -> V_18 == V_22 )
return - V_23 ;
V_20 = V_4 -> V_20 & ~ ( 1 << V_24 ) ;
if ( ( strcmp ( V_4 -> V_25 , L_1 ) != 0 ||
V_20 & ~ ( 1 << V_26 ) ) &&
( strcmp ( V_4 -> V_25 , L_2 ) != 0 ||
V_20 & ~ ( 1 << V_10 ) ) )
return - V_23 ;
if ( V_27 )
return - V_23 ;
return 0 ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_28 ) ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_28 ) ;
}
