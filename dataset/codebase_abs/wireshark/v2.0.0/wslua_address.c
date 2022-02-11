T_1 F_1 ( T_2 * V_1 ) {
#define F_2 1
T_3 V_2 = ( T_3 ) F_3 ( sizeof( V_3 ) ) ;
T_4 * V_4 = ( T_4 * ) F_3 ( sizeof( T_4 ) ) ;
const T_5 * V_5 = F_4 ( V_1 , F_2 ) ;
if ( ! F_5 ( V_5 , ( T_4 * ) V_4 ) ) {
* V_4 = 0 ;
}
F_6 ( V_2 , V_6 , 4 , V_4 ) ;
F_7 ( V_1 , V_2 ) ;
F_8 ( 1 ) ;
}
T_6 F_9 ( T_2 * V_1 ) {
T_3 V_2 = F_10 ( V_1 , 1 ) ;
const T_5 * V_7 = F_11 ( NULL , V_2 ) ;
F_12 ( V_1 , V_7 ) ;
F_13 ( NULL , ( void * ) V_7 ) ;
F_8 ( 1 ) ;
}
static int F_14 ( T_2 * V_1 ) {
T_3 V_2 = F_15 ( V_1 , 1 ) ;
if ( V_2 ) {
F_16 ( ( void * ) ( V_2 -> V_8 ) ) ;
F_16 ( ( void * ) ( V_2 ) ) ;
}
return 0 ;
}
T_6 F_17 ( T_2 * V_1 ) {
T_3 V_9 = F_10 ( V_1 , 1 ) ;
T_3 V_10 = F_10 ( V_1 , 2 ) ;
T_7 V_11 = FALSE ;
if ( F_18 ( V_9 , V_10 ) )
V_11 = TRUE ;
F_19 ( V_1 , V_11 ) ;
return 1 ;
}
T_6 F_20 ( T_2 * V_1 ) {
T_3 V_9 = F_10 ( V_1 , 1 ) ;
T_3 V_10 = F_10 ( V_1 , 2 ) ;
T_7 V_11 = FALSE ;
if ( F_21 ( V_9 , V_10 ) <= 0 )
V_11 = TRUE ;
F_19 ( V_1 , V_11 ) ;
return 1 ;
}
T_6 F_22 ( T_2 * V_1 ) {
T_3 V_9 = F_10 ( V_1 , 1 ) ;
T_3 V_10 = F_10 ( V_1 , 2 ) ;
T_7 V_11 = FALSE ;
if ( F_21 ( V_9 , V_10 ) < 0 )
V_11 = TRUE ;
F_19 ( V_1 , V_11 ) ;
return 1 ;
}
int F_23 ( T_2 * V_1 ) {
F_24 ( T_3 ) ;
return 0 ;
}
