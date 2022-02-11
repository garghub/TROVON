static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = & V_7 ;
F_2 ( V_4 , V_8 ) ;
V_6 -> V_9 ( V_6 ) ;
return V_10 ;
}
static int F_3 ( unsigned long V_11 ,
struct V_5 * V_6 )
{
F_4 ( V_12 , 0 , 0xffffffff - V_11 ) ;
return 0 ;
}
static void F_5 ( enum V_13 V_14 ,
struct V_5 * V_6 )
{
T_2 V_15 ;
F_6 ( V_12 ) ;
switch ( V_14 ) {
case V_16 :
V_15 = F_7 ( F_8 ( V_12 ) ) / V_17 ;
V_15 -= 1 ;
F_4 ( V_12 , 1 , 0xffffffff - V_15 ) ;
break;
case V_18 :
break;
case V_19 :
case V_20 :
case V_21 :
break;
}
}
int T_3 F_9 ( T_4 V_22 )
{
if ( V_22 < 1 || V_22 > V_23 )
return - V_24 ;
F_10 ( V_25 ) ;
V_26 = V_22 ;
return 0 ;
}
static void T_3 F_11 ( void )
{
T_2 V_27 ;
int V_28 ;
char V_29 [ 8 ] ;
V_25 = 1 ;
sprintf ( V_29 , L_1 , V_26 ) ;
F_12 ( V_29 ) ;
V_12 = F_13 ( V_26 ) ;
F_10 ( V_12 == NULL ) ;
V_30 = V_12 ;
#if F_14 ( V_31 )
V_28 = V_32 ;
#else
V_28 = V_33 ;
F_15 ( V_26 == 12 , L_2
L_3 ) ;
#endif
if ( V_26 != 12 )
F_15 ( F_16 ( F_17 ( V_12 , V_28 ) ) ,
L_4 ) ;
V_27 = F_7 ( F_8 ( V_12 ) ) ;
F_18 ( L_5 ,
V_26 , V_27 ) ;
V_34 . V_2 = ( void * ) V_12 ;
F_19 ( F_20 ( V_12 ) , & V_34 ) ;
F_21 ( V_12 , V_8 ) ;
V_7 . V_35 = F_22 ( V_27 , V_36 ,
V_7 . V_37 ) ;
V_7 . V_38 =
F_23 ( 0xffffffff , & V_7 ) ;
V_7 . V_39 =
F_23 ( 3 , & V_7 ) ;
V_7 . V_40 = F_24 ( 0 ) ;
F_25 ( & V_7 ) ;
}
static void T_3 F_26 ( void )
{
F_27 () ;
}
static T_5 F_28 ( struct V_41 * V_42 )
{
return ( T_5 ) F_29 ( V_43 ) ;
}
static void T_6 F_30 ( void )
{
T_2 V_44 ;
V_44 = F_29 ( V_43 ) ;
F_31 ( & V_45 , V_44 , ( T_2 ) ~ 0 ) ;
}
static void T_3 F_26 ( void )
{
static struct V_3 * V_4 ;
T_2 V_27 ;
static char V_46 [] V_47 = V_48
L_6 ;
static char V_49 [] V_47 = V_48
L_7 ;
V_4 = F_32 () ;
if ( ! V_4 )
F_33 ( V_46 , V_50 . V_51 ) ;
V_43 = V_4 ;
F_17 ( V_4 , V_33 ) ;
V_27 = F_7 ( F_8 ( V_4 ) ) ;
F_4 ( V_4 , 1 , 0 ) ;
F_34 ( & V_45 , F_30 , 32 , V_27 ) ;
if ( F_35 ( & V_50 , V_27 ) )
F_33 ( V_49 , V_50 . V_51 ) ;
}
static void T_3 F_36 ( void )
{
#ifdef F_37
if ( F_38 () ) {
V_52 = F_39 ( V_53 , V_54 ) ;
F_10 ( ! V_52 ) ;
}
#endif
F_40 () ;
F_11 () ;
F_26 () ;
}
