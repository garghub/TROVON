static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 ;
if ( ! F_2 ( V_2 , 0 ) )
return V_10 ;
F_3 ( F_4 ( V_2 ) -> V_11 , V_6 -> V_12 ) ;
if ( F_5 ( V_6 -> V_12 ) ) {
if ( F_6 ( V_6 -> V_12 ) )
V_2 -> V_13 = V_14 ;
else
V_2 -> V_13 = V_15 ;
} else {
if ( F_7 ( V_4 ) != V_16 )
V_9 = F_8 ( F_9 ( V_4 ) ) -> V_17 -> V_9 ;
else
V_9 = F_9 ( V_4 ) ;
if ( F_10 ( V_6 -> V_12 , V_9 -> V_18 ) )
V_2 -> V_13 = V_19 ;
else
V_2 -> V_13 = V_20 ;
}
return V_6 -> V_21 ;
}
static int F_11 ( const struct V_22 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_23 ;
if ( V_24 && V_6 -> V_21 == V_25 )
return - V_26 ;
V_23 = V_4 -> V_23 & ~ ( 1 << V_27 ) ;
if ( ( strcmp ( V_4 -> V_28 , L_1 ) != 0 ||
( V_23 & ~ ( ( 1 << V_29 ) |
( 1 << V_30 ) ) ) ) &&
( strcmp ( V_4 -> V_28 , L_2 ) != 0 ||
V_23 & ~ ( 1 << V_16 ) ) )
return - V_26 ;
if ( F_12 ( V_6 -> V_21 ) )
return - V_26 ;
return 0 ;
}
static int T_1 F_13 ( void )
{
return F_14 ( & V_31 ) ;
}
static void T_2 F_15 ( void )
{
F_16 ( & V_31 ) ;
}
