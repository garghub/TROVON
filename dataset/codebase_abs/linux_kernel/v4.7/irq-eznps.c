static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
unsigned int V_4 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_5 ) ;
V_3 &= ~ ( 1 << V_4 ) ;
F_4 ( V_5 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
unsigned int V_4 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_5 ) ;
V_3 |= ( 1 << V_4 ) ;
F_4 ( V_5 , V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int T_1 V_4 = F_2 ( V_2 ) ;
F_4 ( V_6 , 1 << V_4 ) ;
F_7 () ;
F_8 () ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int T_1 V_4 = F_2 ( V_2 ) ;
F_4 ( V_6 , 1 << V_4 ) ;
}
static int F_10 ( struct V_7 * V_8 , unsigned int V_9 ,
T_2 V_10 )
{
switch ( V_10 ) {
case V_11 :
#ifdef F_11
case V_12 :
#endif
F_12 ( V_9 ) ;
F_13 ( V_9 , & V_13 ,
V_14 ) ;
break;
default:
F_13 ( V_9 , & V_15 ,
V_16 ) ;
break;
}
return 0 ;
}
static int T_3 F_14 ( struct V_17 * V_18 ,
struct V_17 * V_19 )
{
static struct V_7 * V_20 ;
if ( V_19 ) {
F_15 ( L_1 ) ;
return - V_21 ;
}
V_20 = F_16 ( V_18 , V_22 ,
& V_23 , NULL ) ;
if ( ! V_20 ) {
F_15 ( L_2 ) ;
return - V_24 ;
}
F_17 ( V_20 ) ;
#ifdef F_11
F_18 ( V_20 , V_12 ) ;
#endif
return 0 ;
}
