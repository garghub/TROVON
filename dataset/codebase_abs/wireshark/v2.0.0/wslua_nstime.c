T_1 F_1 ( T_2 * V_1 ) {
#define F_2 1
#define F_3 2
T_3 V_2 = ( T_3 ) F_4 ( sizeof( V_3 ) ) ;
if ( ! V_2 ) return 0 ;
V_2 -> V_4 = ( V_5 ) F_5 ( V_1 , F_2 , 0 ) ;
V_2 -> V_6 = ( int ) F_5 ( V_1 , F_3 , 0 ) ;
F_6 ( V_1 , V_2 ) ;
F_7 ( 1 ) ;
}
T_4 F_8 ( T_2 * V_1 ) {
#define F_9 1
#define F_10 2
F_11 ( V_1 , 1 ) ;
F_7 ( F_1 ( V_1 ) ) ;
}
T_4 F_12 ( T_2 * V_1 ) {
T_3 V_2 = F_13 ( V_1 , 1 ) ;
T_5 * V_7 ;
V_7 = F_14 ( NULL , L_1 , ( long ) V_2 -> V_4 , V_2 -> V_6 ) ;
F_15 ( V_1 , V_7 ) ;
F_16 ( NULL , V_7 ) ;
F_7 ( 1 ) ;
}
T_4 F_17 ( T_2 * V_1 ) {
T_3 V_8 = F_13 ( V_1 , 1 ) ;
T_3 V_9 = F_13 ( V_1 , 2 ) ;
T_3 V_10 = ( T_3 ) F_4 ( sizeof ( V_3 ) ) ;
F_18 ( V_10 , V_8 , V_9 ) ;
F_6 ( V_1 , V_10 ) ;
return 1 ;
}
T_4 F_19 ( T_2 * V_1 ) {
T_3 V_8 = F_13 ( V_1 , 1 ) ;
T_3 V_9 = F_13 ( V_1 , 2 ) ;
T_3 V_10 = ( T_3 ) F_4 ( sizeof ( V_3 ) ) ;
F_20 ( V_10 , V_8 , V_9 ) ;
F_6 ( V_1 , V_10 ) ;
return 1 ;
}
T_4 F_21 ( T_2 * V_1 ) {
T_3 V_8 = F_13 ( V_1 , 1 ) ;
T_3 V_9 = ( T_3 ) F_4 ( sizeof ( V_3 ) ) ;
F_22 ( V_9 ) ;
F_23 ( V_9 , V_8 ) ;
F_6 ( V_1 , V_9 ) ;
return 1 ;
}
T_4 F_24 ( T_2 * V_1 ) {
T_3 V_8 = F_13 ( V_1 , 1 ) ;
T_3 V_9 = F_13 ( V_1 , 2 ) ;
T_6 V_11 = FALSE ;
if ( F_25 ( V_8 , V_9 ) == 0 )
V_11 = TRUE ;
F_26 ( V_1 , V_11 ) ;
return 1 ;
}
T_4 F_27 ( T_2 * V_1 ) {
T_3 V_8 = F_13 ( V_1 , 1 ) ;
T_3 V_9 = F_13 ( V_1 , 2 ) ;
T_6 V_11 = FALSE ;
if ( F_25 ( V_8 , V_9 ) <= 0 )
V_11 = TRUE ;
F_26 ( V_1 , V_11 ) ;
return 1 ;
}
T_4 F_28 ( T_2 * V_1 ) {
T_3 V_8 = F_13 ( V_1 , 1 ) ;
T_3 V_9 = F_13 ( V_1 , 2 ) ;
T_6 V_11 = FALSE ;
if ( F_25 ( V_8 , V_9 ) < 0 )
V_11 = TRUE ;
F_26 ( V_1 , V_11 ) ;
return 1 ;
}
static int F_29 ( T_2 * V_1 ) {
T_3 V_2 = F_30 ( V_1 , 1 ) ;
if ( ! V_2 ) return 0 ;
F_31 ( V_2 ) ;
return 0 ;
}
int F_32 ( T_2 * V_1 ) {
F_33 ( T_3 ) ;
F_34 ( T_3 ) ;
return 0 ;
}
