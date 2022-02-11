static int F_1 ( struct V_1 * V_2 )
{
if ( F_2 () < V_3 )
return ! F_3 ( V_4 ) ;
else
return ! F_3 ( V_5 ) ;
}
static int F_4 ( struct V_6 * V_7 )
{
T_1 V_8 ;
void T_2 * V_9 ;
void T_2 * V_10 ;
V_9 = F_5 ( V_11 , V_12 ) ;
if ( ! V_9 )
return - V_13 ;
V_10 = V_9 + V_14 ;
V_8 = F_6 ( V_10 + V_15 ) ;
V_8 &= ~ V_16 ;
V_8 |= V_17 ;
F_7 ( V_8 , V_10 + V_15 ) ;
F_8 ( V_9 ) ;
F_9 ( 10 ) ;
return F_10 ( 0 , V_18 ) ;
}
static int F_11 ( struct V_6 * V_7 )
{
T_1 V_8 ;
void T_2 * V_9 ;
void T_2 * V_10 ;
V_9 = F_5 ( V_11 , V_12 ) ;
if ( ! V_9 )
return - V_13 ;
V_10 = V_9 + V_14 ;
V_8 = F_6 ( V_10 + V_19 ) ;
F_7 ( V_8 | V_20 ,
V_10 + V_19 ) ;
F_8 ( V_9 ) ;
F_9 ( 10 ) ;
return F_10 ( 1 , V_21 |
V_22 ) ;
}
static int T_3 F_12 ( char * V_23 )
{
if ( ! strcmp ( V_23 , L_1 ) )
V_24 = true ;
else if ( ! strcmp ( V_23 , L_2 ) )
V_24 = false ;
else
F_13 ( L_3
L_4 ) ;
return 1 ;
}
static void T_3 F_14 ( void )
{
F_15 () ;
F_16 ( V_25 ,
F_17 ( V_25 ) ) ;
F_18 ( 0 , & V_26 ) ;
F_19 ( & V_27 ) ;
F_20 ( 0 ) ;
F_21 ( V_28 , L_5 ) ;
F_22 ( V_28 , 1 ) ;
F_23 ( NULL ) ;
F_21 ( V_29 , L_6 ) ;
F_24 ( V_29 ) ;
F_25 ( V_29 ) ;
F_21 ( V_30 , L_7 ) ;
F_26 ( V_30 , 1 ) ;
F_25 ( V_30 ) ;
F_21 ( V_31 , L_8 ) ;
F_26 ( V_31 , 0 ) ;
F_27 ( 20 ) ;
F_22 ( V_31 , 1 ) ;
F_28 ( 0 , & V_32 ) ;
V_33 [ 0 ] . V_34 = F_29 ( V_29 ) ;
F_30 ( V_33 ,
F_17 ( V_33 ) ) ;
if ( F_2 () < V_3 ) {
V_35 [ 1 ] . V_34 =
F_29 ( V_4 ) ,
F_31 ( V_36 ,
F_17 ( V_36 ) ) ;
F_21 ( V_4 , L_9 ) ;
F_24 ( V_4 ) ;
F_25 ( V_4 ) ;
} else {
V_35 [ 1 ] . V_34 =
F_29 ( V_5 ) ,
F_32 ( 0 , & V_37 ) ;
F_21 ( V_5 , L_9 ) ;
F_24 ( V_5 ) ;
F_25 ( V_5 ) ;
}
F_33 ( 0 , V_35 ,
F_17 ( V_35 ) ) ;
if ( V_24 )
F_34 ( & V_38 ) ;
else {
F_4 ( NULL ) ;
F_35 ( & V_39 ) ;
}
F_21 ( V_40 , L_10 ) ;
F_26 ( V_40 , 0 ) ;
F_27 ( 20 ) ;
F_22 ( V_40 , 1 ) ;
F_36 ( 1 , & V_41 ) ;
#ifdef F_37
F_38 () ;
#endif
}
static void T_3 F_39 ( void )
{
F_40 ( 32768 , 24000000 , 22579200 , 0 ) ;
}
