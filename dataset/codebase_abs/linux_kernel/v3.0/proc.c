static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
if ( ! F_2 ( V_3 ) )
return 0 ;
V_2 = F_3 ( L_1 , 0 ) ;
if ( ! V_2 )
return 1 ;
return 0 ;
}
static int F_4 ( struct V_4 * V_5 , void * V_6 )
{
unsigned long V_7 , V_8 ;
V_7 = F_5 () ;
V_8 = F_6 () ;
F_7 ( V_5 , L_2 ) ;
F_7 ( V_5 , L_3 , V_7 ) ;
F_7 ( V_5 , L_4 , V_8 ) ;
F_7 ( V_5 , L_5 ,
V_9 [ 0 ] . V_10 ) ;
F_7 ( V_5 , L_6 ,
V_9 [ 0 ] . V_11 ) ;
F_7 ( V_5 , L_7 , V_12 ) ;
F_7 ( V_5 , L_8 , V_13 ) ;
if ( ! V_14 ) {
V_14 = V_8 ;
V_15 = V_7 ;
} else {
unsigned long V_16 = ( V_8 - V_14 ) >> 12 ;
unsigned long V_17 = ( V_7 - V_15 ) ;
unsigned long V_18 = V_16 / ( 1000000 / V_19 ) ;
unsigned long V_20 = V_18 * ( 1000000 / V_19 ) ;
unsigned long V_21 =
V_16 - V_20 ;
unsigned long V_22 = V_17 / V_12 ;
unsigned long V_23 = V_22 * V_12 ;
unsigned long V_24 = V_17 - V_23 ;
unsigned long V_25 =
V_24 / V_13 ;
unsigned long V_26 =
( V_17 * ( 1000000 / V_19 ) ) / V_16 ;
F_7 ( V_5 , L_9 , V_16 ) ;
F_7 ( V_5 , L_10 , V_17 ) ;
F_7 ( V_5 , L_11 , V_18 ,
V_21 ) ;
F_7 ( V_5 , L_12 , V_22 ,
V_25 ) ;
F_7 ( V_5 , L_13 ,
V_26 ) ;
}
return 0 ;
}
static int F_8 ( struct V_27 * V_27 , struct V_28 * V_28 )
{
return F_9 ( V_28 , F_4 , NULL ) ;
}
static int T_1 F_10 ( void )
{
if ( ! F_2 ( V_3 ) )
return 0 ;
F_11 ( L_14 , V_29 | V_30 , NULL ,
& V_31 ) ;
return 0 ;
}
