static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( ! F_2 ( V_2 , 0 ) )
return V_8 ;
if ( V_4 -> V_9 != V_10 )
memcpy ( F_3 ( V_2 ) -> V_11 ,
F_4 ( V_4 -> V_12 ) -> V_13 -> V_14 -> V_15 , V_16 ) ;
else
memcpy ( F_3 ( V_2 ) -> V_11 , V_4 -> V_12 -> V_15 , V_16 ) ;
V_2 -> V_17 = V_18 ;
return V_6 -> V_19 ;
}
static int F_5 ( const struct V_20 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_21 ;
if ( V_22 && V_6 -> V_19 == V_23 )
return - V_24 ;
V_21 = V_4 -> V_21 & ~ ( 1 << V_25 ) ;
if ( ( strcmp ( V_4 -> V_26 , L_1 ) != 0 ||
V_21 & ~ ( 1 << V_27 ) ) &&
( strcmp ( V_4 -> V_26 , L_2 ) != 0 ||
V_21 & ~ ( 1 << V_10 ) ) )
return - V_24 ;
if ( V_28 )
return - V_24 ;
return 0 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_29 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_29 ) ;
}
