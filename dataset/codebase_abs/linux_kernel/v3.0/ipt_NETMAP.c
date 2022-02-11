static int F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! ( V_4 -> V_6 [ 0 ] . V_7 & V_8 ) ) {
F_2 ( L_1 ) ;
return - V_9 ;
}
if ( V_4 -> V_10 != 1 ) {
F_2 ( L_2 , V_4 -> V_10 ) ;
return - V_9 ;
}
return 0 ;
}
static unsigned int
F_3 ( struct V_11 * V_12 , const struct V_13 * V_2 )
{
struct V_14 * V_15 ;
enum V_16 V_17 ;
T_1 V_18 , V_19 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 V_21 ;
F_4 ( V_2 -> V_22 == V_23 ||
V_2 -> V_22 == V_24 ||
V_2 -> V_22 == V_25 ||
V_2 -> V_22 == V_26 ) ;
V_15 = F_5 ( V_12 , & V_17 ) ;
V_19 = ~ ( V_4 -> V_6 [ 0 ] . V_27 ^ V_4 -> V_6 [ 0 ] . V_28 ) ;
if ( V_2 -> V_22 == V_23 ||
V_2 -> V_22 == V_25 )
V_18 = F_6 ( V_12 ) -> V_29 & ~ V_19 ;
else
V_18 = F_6 ( V_12 ) -> V_30 & ~ V_19 ;
V_18 |= V_4 -> V_6 [ 0 ] . V_27 & V_19 ;
V_21 = ( (struct V_20 )
{ V_4 -> V_6 [ 0 ] . V_7 | V_8 ,
V_18 , V_18 ,
V_4 -> V_6 [ 0 ] . V_31 , V_4 -> V_6 [ 0 ] . V_32 } ) ;
return F_7 ( V_15 , & V_21 , F_8 ( V_2 -> V_22 ) ) ;
}
static int T_2 F_9 ( void )
{
return F_10 ( & V_33 ) ;
}
static void T_3 F_11 ( void )
{
F_12 ( & V_33 ) ;
}
