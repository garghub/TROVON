void T_1 F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_2 * V_4 ;
F_2 ( 1 << V_5 ) ;
V_4 = F_3 ( V_3 ) ;
F_4 () ;
#ifdef F_5
F_6 () ;
#endif
F_7 () ;
F_3 ( V_4 ) ;
}
void F_8 ( void )
{
F_9 ( 1 << V_5 ) ;
}
static T_2 F_10 ( void )
{
T_2 V_6 ;
F_11 ( V_6 ) ;
return V_6 ;
}
static void F_12 ( T_2 V_6 )
{
F_13 ( V_6 ) ;
}
static void F_14 ( T_2 V_6 )
{
unsigned long V_7 ;
V_7 = F_15 ( V_8 , V_6 ) ;
if ( V_7 != V_9 )
F_13 ( V_6 ) ;
}
static int T_3 F_16 ( void )
{
if ( V_10 == V_11 ) {
switch ( V_12 ) {
case V_13 :
V_14 = V_15 ;
break;
case V_16 :
V_14 = V_17 ;
break;
default:
return - V_18 ;
}
V_19 = 1 ;
V_20 = 0 ;
if ( F_17 ( V_14 ,
V_19 ,
& V_20 ) ) {
F_18 ( L_1 ) ;
return - V_18 ;
}
}
return 0 ;
}
static void T_3 F_19 ( void )
{
if ( V_10 != V_11 )
return;
F_20 ( V_14 ) ;
}
int T_3 F_21 ( void )
{
int V_21 = F_16 () ;
if ( V_21 )
return V_21 ;
switch ( V_10 ) {
case V_11 :
V_22 = & V_23 ;
V_24 = V_25 ;
V_26 = 2 ;
break;
case V_27 :
case V_28 :
V_22 = & V_29 ;
V_24 = V_30 ;
break;
case V_31 :
default:
V_21 = - V_18 ;
goto V_32;
}
return F_22 () ;
V_32:
F_19 () ;
return V_21 ;
}
