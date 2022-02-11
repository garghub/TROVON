static void F_1 ( T_1 V_1 )
{
int V_2 ;
if ( V_1 == V_3 )
V_2 = 1 ;
else if ( V_1 == V_4 )
V_2 = 0 ;
else
return;
F_2 ( V_5 , V_2 ) ;
}
static int T_2 F_3 ( void )
{
int V_6 ;
if ( F_4 () ) {
V_6 = V_5 ;
if ( F_5 ( V_6 , L_1 ) == 0 ) {
if ( F_6 ( V_6 , 0 ) != 0 ) {
F_7 ( V_7 L_2
L_3 , V_6 ) ;
F_8 ( V_6 ) ;
return 0 ;
}
} else {
F_7 ( V_7 L_2
L_4 , V_6 ) ;
return 0 ;
}
V_8 = F_1 ;
}
return 0 ;
}
void T_2 F_9 ( void )
{
int V_6 ;
V_6 = V_9 ;
if ( F_5 ( V_6 , L_5 ) == 0 ) {
if ( F_10 ( V_6 ) == 0 ) {
F_11 ( F_12 ( V_6 ) , V_10 ) ;
} else {
F_7 ( V_7 L_6
L_7 , V_6 ) ;
F_8 ( V_6 ) ;
}
} else {
F_7 ( V_7 L_8 , V_6 ) ;
}
V_6 = V_11 ;
if ( F_5 ( V_6 , L_9 ) == 0 ) {
if ( F_10 ( V_6 ) == 0 ) {
F_11 ( F_12 ( V_6 ) , V_10 ) ;
} else {
F_7 ( V_7 L_6
L_7 , V_6 ) ;
F_8 ( V_6 ) ;
}
} else {
F_7 ( V_7 L_10 , V_6 ) ;
}
}
static int T_2 F_13 ( const struct V_12 * V_13 , T_3 V_14 ,
T_3 V_6 )
{
int V_15 ;
V_15 = F_14 ( V_13 , V_14 , V_6 ) ;
if ( V_15 != - 1 )
return V_15 ;
switch ( V_14 - V_16 ) {
case 0 :
if ( V_6 == 1 )
return F_12 ( V_9 ) ;
else
return F_12 ( V_11 ) ;
default:
return - 1 ;
}
}
static int T_2 F_15 ( void )
{
if ( F_4 () )
F_16 ( & V_17 ) ;
return 0 ;
}
static void T_2 F_17 ( void )
{
F_18 () ;
F_19 ( V_18 ) ;
F_20 () ;
F_21 () ;
F_22 ( & V_19 ) ;
F_23 () ;
F_24 ( & V_20 ) ;
F_25 () ;
F_26 () ;
F_27 ( V_21 ,
V_22 ) ;
F_28 ( V_23 , V_24 ) ;
F_29 ( & V_25 ) ;
F_30 ( 0 , & V_26 , 1 ) ;
}
