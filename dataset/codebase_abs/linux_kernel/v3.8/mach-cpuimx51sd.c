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
#if F_18 ( V_24 )
V_25 = V_26 ;
#endif
F_19 ( 0 , & V_27 ) ;
F_20 ( & V_28 ) ;
F_21 ( 0 ) ;
F_22 ( V_29 , L_5 ) ;
F_23 ( V_29 , 1 ) ;
F_24 ( NULL ) ;
F_22 ( V_30 , L_6 ) ;
F_25 ( V_30 ) ;
F_26 ( V_30 ) ;
F_22 ( V_31 , L_7 ) ;
F_27 ( V_31 , 1 ) ;
F_26 ( V_31 ) ;
F_22 ( V_32 , L_8 ) ;
F_27 ( V_32 , 0 ) ;
F_28 ( 20 ) ;
F_23 ( V_32 , 1 ) ;
F_29 ( 0 , & V_33 ) ;
V_34 [ 0 ] . V_35 = F_30 ( V_30 ) ;
F_31 ( V_34 ,
F_17 ( V_34 ) ) ;
if ( F_2 () < V_1 ) {
V_36 [ 1 ] . V_35 =
F_30 ( V_2 ) ,
F_32 ( V_37 ,
F_17 ( V_37 ) ) ;
F_22 ( V_2 , L_9 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
} else {
V_36 [ 1 ] . V_35 =
F_30 ( V_3 ) ,
F_33 ( 0 , & V_38 ) ;
F_22 ( V_3 , L_9 ) ;
F_25 ( V_3 ) ;
F_26 ( V_3 ) ;
}
F_34 ( 0 , V_36 ,
F_17 ( V_36 ) ) ;
if ( V_22 )
F_35 ( & V_39 ) ;
else {
F_4 ( NULL ) ;
F_36 ( & V_40 ) ;
}
F_22 ( V_41 , L_10 ) ;
F_27 ( V_41 , 0 ) ;
F_28 ( 20 ) ;
F_23 ( V_41 , 1 ) ;
F_37 ( 1 , & V_42 ) ;
#ifdef F_38
F_39 () ;
#endif
}
static void T_3 F_40 ( void )
{
F_41 ( 32768 , 24000000 , 22579200 , 0 ) ;
}
