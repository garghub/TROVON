static void
F_1 ( T_1 V_1 )
{
static struct V_2 V_3 ;
static volatile T_1 V_4 ;
static T_2 V_5 ;
T_1 V_6 ;
enum { V_7 = V_8 * 60 };
switch ( V_1 ) {
case V_9 :
F_2 ( & V_3 ) ;
F_3 ( & V_5 ) ;
V_3 . V_10 = V_11 ;
V_3 . V_12 = F_1 ;
V_4 = 0 ;
case V_11 :
F_4 ( & V_5 , V_6 ) ;
if ( ! V_4 ) {
V_3 . V_13 = V_14 + V_7 ;
F_5 ( & V_3 ) ;
}
F_6 ( & V_5 , V_6 ) ;
F_7 ( 0xffff , 0xff ) ;
return;
case V_15 :
F_4 ( & V_5 , V_6 ) ;
V_4 = 1 ;
F_6 ( & V_5 , V_6 ) ;
F_8 ( & V_3 ) ;
default:
return;
}
}
static void
F_9 ( void )
{
F_1 ( V_15 ) ;
F_10 () ;
F_11 ( V_16 , V_17 ) ;
F_12 () ;
F_13 () ;
F_14 () ;
F_15 () ;
}
static int T_3
F_16 ( void )
{
int V_18 ;
V_18 = F_17 () ;
if ( V_18 )
return V_18 ;
V_18 = F_18 () ;
if ( V_18 )
goto V_19;
V_18 = F_19 () ;
if ( V_18 )
goto V_20;
V_18 = F_20 () ;
if ( V_18 )
goto V_21;
V_18 = F_21 () ;
if ( V_18 )
goto V_22;
V_18 = F_22 ( V_16 , V_17 ) ;
if ( V_18 < 0 ) {
F_23 ( V_23 L_1 ) ;
goto V_24;
}
F_23 ( V_25 L_2 , V_26 ) ;
F_1 ( V_9 ) ;
return 0 ;
V_24:
F_12 () ;
V_22:
F_10 () ;
V_21:
F_15 () ;
V_20:
F_13 () ;
V_19:
F_14 () ;
F_23 ( V_25 L_3 ) ;
return V_18 ;
}
