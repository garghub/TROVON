static void F_1 ( unsigned long V_1 )
{
static int V_2 = 0 ;
F_2 ( 0 , V_3 + ( V_2 << 4 ) ) ;
V_2 = ( V_2 + 1 ) & 7 ;
F_3 ( & V_4 , V_5 + 2 * V_6 ) ;
}
static int T_1 F_4 ( void )
{
if ( F_5 () ) {
V_3 = F_6 ( V_7 ,
V_8 ) ;
if ( ! V_3 ) {
F_7 ( V_9 L_1 ) ;
return - V_10 ;
}
F_8 ( & V_4 , F_1 , 0 ) ;
F_3 ( & V_4 , V_5 + 2 * V_6 ) ;
}
return 0 ;
}
void T_1 F_9 ( void )
{
int V_11 ;
V_11 = V_12 ;
if ( F_10 ( V_11 , L_2 ) == 0 ) {
if ( F_11 ( V_11 ) == 0 ) {
F_12 ( F_13 ( V_11 ) , V_13 ) ;
} else {
F_7 ( V_9 L_3
L_4 , V_11 ) ;
F_14 ( V_11 ) ;
}
} else {
F_7 ( V_9 L_5 , V_11 ) ;
}
V_11 = V_14 ;
if ( F_10 ( V_11 , L_6 ) == 0 ) {
if ( F_11 ( V_11 ) == 0 ) {
F_12 ( F_13 ( V_11 ) , V_13 ) ;
} else {
F_7 ( V_9 L_7
L_8 , V_11 ) ;
F_14 ( V_11 ) ;
}
} else {
F_7 ( V_9 L_5 , V_11 ) ;
}
}
static int T_1 F_15 ( const struct V_15 * V_16 , T_2 V_17 ,
T_2 V_11 )
{
int V_18 ;
V_18 = F_16 ( V_16 , V_17 , V_11 ) ;
if ( V_18 != - 1 )
return V_18 ;
switch ( V_17 - V_19 ) {
case 0 :
return F_13 ( V_12 ) ;
case 1 :
case 2 :
return F_13 ( V_14 ) ;
default:
return - 1 ;
}
}
static int T_1 F_17 ( void )
{
if ( F_5 () )
F_18 ( & V_20 ) ;
return 0 ;
}
static void T_1 F_19 ( void )
{
F_20 () ;
F_21 ( V_21 ) ;
F_2 ( 0 , V_22 ) ;
F_22 () ;
F_23 ( & V_23 ) ;
F_24 () ;
F_25 () ;
F_26 () ;
F_27 ( V_24 ,
V_25 ) ;
F_28 ( & V_26 ) ;
F_29 ( V_7 , V_8 ) ;
F_30 ( V_27 , V_28 ) ;
F_28 ( & V_29 ) ;
F_31 ( V_30 , V_31 ) ;
F_28 ( & V_32 ) ;
F_32 ( 0 , & V_33 , 1 ) ;
}
