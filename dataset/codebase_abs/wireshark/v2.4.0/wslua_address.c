T_1 F_1 ( T_2 * V_1 ) {
#define F_2 1
T_3 V_2 = ( T_3 ) F_3 ( sizeof( V_3 ) ) ;
T_4 V_4 ;
const T_5 * V_5 = F_4 ( V_1 , F_2 ) ;
if ( ! F_5 ( V_5 , & V_4 ) ) {
V_4 = 0 ;
}
F_6 ( NULL , V_2 , V_6 , 4 , & V_4 ) ;
F_7 ( V_1 , V_2 ) ;
F_8 ( 1 ) ;
}
T_1 F_9 ( T_2 * V_1 ) {
#define F_10 1
T_3 V_2 = ( T_3 ) F_3 ( sizeof( V_3 ) ) ;
struct V_7 V_4 ;
const T_5 * V_5 = F_4 ( V_1 , F_10 ) ;
if ( ! F_11 ( V_5 , & V_4 ) ) {
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
}
F_6 ( NULL , V_2 , V_8 , sizeof( V_4 . V_9 ) , & V_4 . V_9 ) ;
F_7 ( V_1 , V_2 ) ;
F_8 ( 1 ) ;
}
T_6 F_12 ( T_2 * V_1 ) {
T_3 V_2 = F_13 ( V_1 , 1 ) ;
T_5 * V_10 = F_14 ( NULL , V_2 ) ;
F_15 ( V_1 , V_10 ) ;
F_16 ( NULL , V_10 ) ;
F_8 ( 1 ) ;
}
static int F_17 ( T_2 * V_1 ) {
T_3 V_2 = F_18 ( V_1 , 1 ) ;
if ( V_2 ) {
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
}
return 0 ;
}
T_6 F_21 ( T_2 * V_1 ) {
T_3 V_11 = F_13 ( V_1 , 1 ) ;
T_3 V_12 = F_13 ( V_1 , 2 ) ;
T_7 V_13 = FALSE ;
if ( F_22 ( V_11 , V_12 ) )
V_13 = TRUE ;
F_23 ( V_1 , V_13 ) ;
return 1 ;
}
T_6 F_24 ( T_2 * V_1 ) {
T_3 V_11 = F_13 ( V_1 , 1 ) ;
T_3 V_12 = F_13 ( V_1 , 2 ) ;
T_7 V_13 = FALSE ;
if ( F_25 ( V_11 , V_12 ) <= 0 )
V_13 = TRUE ;
F_23 ( V_1 , V_13 ) ;
return 1 ;
}
T_6 F_26 ( T_2 * V_1 ) {
T_3 V_11 = F_13 ( V_1 , 1 ) ;
T_3 V_12 = F_13 ( V_1 , 2 ) ;
T_7 V_13 = FALSE ;
if ( F_25 ( V_11 , V_12 ) < 0 )
V_13 = TRUE ;
F_23 ( V_1 , V_13 ) ;
return 1 ;
}
int F_27 ( T_2 * V_1 ) {
F_28 ( T_3 ) ;
return 0 ;
}
