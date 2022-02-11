static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
T_1 V_12 = V_5 -> V_5 [ 0 ] ;
switch ( V_9 -> V_13 ) {
case V_14 :
V_11 -> V_15 = V_12 ;
break;
case V_16 :
V_11 -> V_17 = V_12 ;
break;
case V_18 :
V_11 -> V_19 = V_12 ;
break;
#ifdef F_3
case V_20 :
V_11 -> V_21 = V_12 ;
break;
#endif
default:
F_4 ( 1 ) ;
}
}
static int F_5 ( const struct V_1 * V_2 , struct V_22 * V_23 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_23 [ V_24 ] == NULL )
return - V_25 ;
V_9 -> V_13 = F_6 ( F_7 ( V_23 [ V_24 ] ) ) ;
switch ( V_9 -> V_13 ) {
case V_14 :
case V_16 :
case V_18 :
#ifdef F_3
case V_20 :
#endif
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_8 ( struct V_10 * V_11 , const struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( V_11 , V_24 , F_10 ( V_9 -> V_13 ) ) ;
return 0 ;
V_26:
return - 1 ;
}
static int T_2 F_11 ( void )
{
return F_12 ( & V_27 ) ;
}
static void T_3 F_13 ( void )
{
F_14 ( & V_27 ) ;
}
