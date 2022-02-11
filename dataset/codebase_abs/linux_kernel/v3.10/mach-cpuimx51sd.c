static int F_1 ( void )
{
if ( F_2 () < V_1 )
return ! F_3 ( V_2 ) ;
else
return ! F_3 ( V_3 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
T_1 V_6 ;
void T_2 * V_7 ;
void T_2 * V_8 ;
V_7 = F_5 ( V_9 , V_10 ) ;
if ( ! V_7 )
return - V_11 ;
V_8 = V_7 + V_12 ;
V_6 = F_6 ( V_8 + V_13 ) ;
V_6 &= ~ V_14 ;
V_6 |= V_15 ;
F_7 ( V_6 , V_8 + V_13 ) ;
F_8 ( V_7 ) ;
F_9 ( 10 ) ;
return F_10 ( 0 , V_16 ) ;
}
static int F_11 ( struct V_4 * V_5 )
{
T_1 V_6 ;
void T_2 * V_7 ;
void T_2 * V_8 ;
V_7 = F_5 ( V_9 , V_10 ) ;
if ( ! V_7 )
return - V_11 ;
V_8 = V_7 + V_12 ;
V_6 = F_6 ( V_8 + V_17 ) ;
F_7 ( V_6 | V_18 ,
V_8 + V_17 ) ;
F_8 ( V_7 ) ;
F_9 ( 10 ) ;
return F_10 ( 1 , V_19 |
V_20 ) ;
}
static int T_3 F_12 ( char * V_21 )
{
if ( ! strcmp ( V_21 , L_1 ) )
V_22 = true ;
else if ( ! strcmp ( V_21 , L_2 ) )
V_22 = false ;
else
F_13 ( L_3
L_4 ) ;
return 1 ;
}
static void T_3 F_14 ( void )
{
F_15 () ;
F_16 ( V_23 ,
F_17 ( V_23 ) ) ;
F_18 ( 0 , & V_24 ) ;
F_19 ( & V_25 ) ;
F_20 ( 0 ) ;
F_21 ( V_26 , L_5 ) ;
F_22 ( V_26 , 1 ) ;
F_23 ( NULL ) ;
F_21 ( V_27 , L_6 ) ;
F_24 ( V_27 ) ;
F_25 ( V_27 ) ;
F_21 ( V_28 , L_7 ) ;
F_26 ( V_28 , 1 ) ;
F_25 ( V_28 ) ;
F_21 ( V_29 , L_8 ) ;
F_26 ( V_29 , 0 ) ;
F_27 ( 20 ) ;
F_22 ( V_29 , 1 ) ;
F_28 ( 0 , & V_30 ) ;
V_31 [ 0 ] . V_32 = F_29 ( V_27 ) ;
F_30 ( V_31 ,
F_17 ( V_31 ) ) ;
if ( F_2 () < V_1 ) {
V_33 [ 1 ] . V_32 =
F_29 ( V_2 ) ,
F_31 ( V_34 ,
F_17 ( V_34 ) ) ;
F_21 ( V_2 , L_9 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
} else {
V_33 [ 1 ] . V_32 =
F_29 ( V_3 ) ,
F_32 ( 0 , & V_35 ) ;
F_21 ( V_3 , L_9 ) ;
F_24 ( V_3 ) ;
F_25 ( V_3 ) ;
}
F_33 ( 0 , V_33 ,
F_17 ( V_33 ) ) ;
if ( V_22 )
F_34 ( & V_36 ) ;
else {
F_4 ( NULL ) ;
F_35 ( & V_37 ) ;
}
F_21 ( V_38 , L_10 ) ;
F_26 ( V_38 , 0 ) ;
F_27 ( 20 ) ;
F_22 ( V_38 , 1 ) ;
F_36 ( 1 , & V_39 ) ;
#ifdef F_37
F_38 () ;
#endif
}
static void T_3 F_39 ( void )
{
F_40 ( 32768 , 24000000 , 22579200 , 0 ) ;
}
