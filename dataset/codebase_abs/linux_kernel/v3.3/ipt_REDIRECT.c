static int F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 [ 0 ] . V_7 & V_8 ) {
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
T_1 V_18 ;
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_19 V_20 ;
F_4 ( V_2 -> V_21 == V_22 ||
V_2 -> V_21 == V_23 ) ;
V_15 = F_5 ( V_12 , & V_17 ) ;
F_4 ( V_15 && ( V_17 == V_24 || V_17 == V_25 ) ) ;
if ( V_2 -> V_21 == V_23 )
V_18 = F_6 ( 0x7F000001 ) ;
else {
struct V_26 * V_27 ;
struct V_28 * V_29 ;
V_18 = 0 ;
F_7 () ;
V_27 = F_8 ( V_12 -> V_30 ) ;
if ( V_27 && ( V_29 = V_27 -> V_31 ) )
V_18 = V_29 -> V_32 ;
F_9 () ;
if ( ! V_18 )
return V_33 ;
}
V_20 = ( (struct V_19 )
{ V_4 -> V_6 [ 0 ] . V_7 | V_8 ,
V_18 , V_18 ,
V_4 -> V_6 [ 0 ] . V_34 , V_4 -> V_6 [ 0 ] . V_35 } ) ;
return F_10 ( V_15 , & V_20 , V_36 ) ;
}
static int T_2 F_11 ( void )
{
return F_12 ( & V_37 ) ;
}
static void T_3 F_13 ( void )
{
F_14 ( & V_37 ) ;
}
