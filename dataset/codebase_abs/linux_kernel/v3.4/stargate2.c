static void F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
V_3 |= V_4 | V_5 | V_6 ;
break;
case V_7 :
V_3 &= ~ ( V_4 | V_5 | V_6 ) ;
break;
}
}
static void T_1 F_2 ( void )
{
F_3 ( F_4 ( V_8 ) ) ;
F_5 ( NULL ) ;
F_6 ( NULL ) ;
F_7 ( NULL ) ;
F_8 ( 1 , & V_9 ) ;
F_8 ( 2 , & V_10 ) ;
F_8 ( 3 , & V_11 ) ;
F_9 ( V_12 , F_10 ( V_12 ) ) ;
F_11 ( & V_13 ) ;
F_12 ( & V_14 ) ;
}
static int F_13 ( struct V_15 * V_16 )
{
return 0 ;
}
static void T_1 F_14 ( void )
{
F_3 ( F_4 ( V_17 ) ) ;
F_2 () ;
F_15 ( V_18 , F_10 ( V_18 ) ) ;
F_16 ( 0 , V_19 ,
F_10 ( V_19 ) ) ;
F_16 ( 1 , V_20 ,
F_10 ( V_20 ) ) ;
F_17 ( & V_21 ) ;
F_18 ( & V_22 ) ;
}
static int F_19 ( struct V_15 * V_16 ,
T_2 V_23 ,
void * V_24 )
{
int V_25 ;
V_25 = F_20 ( V_26 , L_1 ) ;
if ( V_25 ) {
F_21 ( V_27 L_2 ) ;
goto V_28;
}
F_22 ( V_26 , 0 ) ;
V_25 = F_20 ( V_29 , L_3 ) ;
if ( V_25 ) {
F_21 ( V_27 L_4 ) ;
goto V_30;
}
F_23 ( V_29 ) ;
V_25 = F_24 ( F_25 ( V_29 ) ,
V_23 ,
V_31 ,
L_5 ,
V_24 ) ;
if ( V_25 ) {
F_21 ( V_27 L_6 ) ;
goto V_32;
}
return 0 ;
V_32:
F_26 ( V_29 ) ;
V_30:
F_26 ( V_26 ) ;
V_28:
return V_25 ;
}
static void F_27 ( struct V_15 * V_16 , unsigned int V_33 )
{
F_28 ( V_26 , ! ! V_33 ) ;
}
static void F_29 ( struct V_15 * V_16 , void * V_24 )
{
F_30 ( F_25 ( V_29 ) , V_24 ) ;
F_26 ( V_26 ) ;
F_26 ( V_29 ) ;
}
static int F_31 ( void )
{
int V_25 ;
V_25 = F_20 ( V_34 , L_7 ) ;
if ( V_25 ) {
F_21 ( V_27 L_8 ) ;
return V_25 ;
}
F_22 ( V_34 , 1 ) ;
F_32 ( 5 ) ;
F_28 ( V_34 , 0 ) ;
F_32 ( 10 ) ;
F_28 ( V_34 , 1 ) ;
F_26 ( V_34 ) ;
return 0 ;
}
static int F_33 ( void )
{
return 1 ;
}
static void T_1 F_34 ( void )
{
F_35 ( F_36 ( V_35 ) & ~ V_36 , V_35 ) ;
F_3 ( F_4 ( V_37 ) ) ;
F_2 () ;
F_15 ( F_4 ( V_38 ) ) ;
F_16 ( 0 , F_4 ( V_39 ) ) ;
F_16 ( 1 , V_40 ,
F_10 ( V_40 ) ) ;
F_17 ( & V_41 ) ;
F_18 ( & V_42 ) ;
F_31 () ;
}
