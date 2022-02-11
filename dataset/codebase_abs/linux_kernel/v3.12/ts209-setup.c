void T_1 F_1 ( void )
{
int V_1 ;
V_1 = V_2 ;
if ( F_2 ( V_1 , L_1 ) == 0 ) {
if ( F_3 ( V_1 ) == 0 ) {
F_4 ( F_5 ( V_1 ) , V_3 ) ;
} else {
F_6 ( V_4 L_2
L_3 , V_1 ) ;
F_7 ( V_1 ) ;
}
} else {
F_6 ( V_4 L_4
L_5 , V_1 ) ;
}
V_1 = V_5 ;
if ( F_2 ( V_1 , L_6 ) == 0 ) {
if ( F_3 ( V_1 ) == 0 ) {
F_4 ( F_5 ( V_1 ) , V_3 ) ;
} else {
F_6 ( V_4 L_7
L_8 , V_1 ) ;
F_7 ( V_1 ) ;
}
} else {
F_6 ( V_4 L_4
L_5 , V_1 ) ;
}
}
static int T_1 F_8 ( const struct V_6 * V_7 , T_2 V_8 ,
T_2 V_1 )
{
int V_9 ;
V_9 = F_9 ( V_7 , V_8 , V_1 ) ;
if ( V_9 != - 1 )
return V_9 ;
switch ( V_8 - V_10 ) {
case 0 :
return F_5 ( V_2 ) ;
case 1 :
return F_5 ( V_5 ) ;
default:
return - 1 ;
}
}
static int T_1 F_10 ( void )
{
if ( F_11 () )
F_12 ( & V_11 ) ;
return 0 ;
}
static void T_1 F_13 ( void )
{
F_14 () ;
F_15 ( V_12 ) ;
F_16 ( V_13 ,
V_14 ,
V_15 ,
V_16 ) ;
F_17 ( & V_17 ) ;
F_18 () ;
F_19 () ;
F_20 ( V_15 +
V_18 [ 5 ] . V_19 ,
V_18 [ 5 ] . V_20 ) ;
F_21 ( & V_21 ) ;
F_22 () ;
F_23 ( & V_22 ) ;
F_24 () ;
F_25 () ;
F_26 () ;
F_17 ( & V_23 ) ;
if ( F_2 ( V_24 , L_9 ) == 0 ) {
if ( F_3 ( V_24 ) == 0 )
V_25 . V_9 = F_5 ( V_24 ) ;
else
F_7 ( V_24 ) ;
}
if ( V_25 . V_9 == 0 )
F_27 ( L_10 ) ;
F_28 ( 0 , & V_25 , 1 ) ;
V_26 = V_27 ;
}
