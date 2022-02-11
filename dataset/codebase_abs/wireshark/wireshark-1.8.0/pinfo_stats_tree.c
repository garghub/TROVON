static const T_1 * F_1 ( T_2 type ) {
switch ( type ) {
case V_1 : return L_1 ;
case V_2 : return L_2 ;
case V_3 : return L_3 ;
case V_4 : return L_4 ;
case V_5 : return L_5 ;
case V_6 : return L_6 ;
case V_7 : return L_7 ;
case V_8 : return L_8 ;
case V_9 : return L_9 ;
case V_10 : return L_10 ;
default: return L_11 ;
}
}
static void F_2 ( T_3 * V_11 ) {
V_12 = F_3 ( V_11 , V_13 , 0 , TRUE ) ;
}
static int F_4 ( T_3 * V_11 , T_4 * V_14 , T_5 * T_6 V_15 , const void * T_7 V_15 ) {
F_5 ( V_11 , V_13 , 0 , FALSE ) ;
F_5 ( V_11 , F_6 ( & V_14 -> V_16 ) , V_12 , FALSE ) ;
F_5 ( V_11 , F_6 ( & V_14 -> V_17 ) , V_12 , FALSE ) ;
return 1 ;
}
static void F_7 ( T_3 * V_11 ) {
V_18 = F_8 ( V_11 , V_19 , 0 ) ;
}
static int F_9 ( T_3 * V_11 , T_4 * V_14 , T_5 * T_6 V_15 , const void * T_7 V_15 ) {
const T_1 * V_20 ;
V_20 = F_1 ( V_14 -> V_20 ) ;
F_10 ( V_11 , V_18 , V_20 ) ;
return 1 ;
}
static void F_11 ( T_3 * V_11 ) {
V_21 = F_12 ( V_11 , V_22 , 0 , L_12 , L_13 , L_14 , L_15 , L_16 , L_17 , L_18 , L_19 , L_20 , L_21 , NULL ) ;
}
static int F_13 ( T_3 * V_11 , T_4 * V_14 , T_5 * T_6 V_15 , const void * T_7 V_15 ) {
F_5 ( V_11 , V_22 , 0 , FALSE ) ;
F_14 ( V_11 , V_22 , 0 , V_14 -> V_23 -> V_24 ) ;
return 1 ;
}
static void F_15 ( T_3 * V_11 ) {
V_25 = F_3 ( V_11 , V_26 , 0 , TRUE ) ;
}
static int F_16 ( T_3 * V_11 , T_4 * V_14 , T_5 * T_6 V_15 , const void * T_7 V_15 ) {
static T_1 V_27 [ 128 ] ;
int V_28 ;
int V_29 ;
F_5 ( V_11 , V_26 , 0 , FALSE ) ;
V_28 = F_5 ( V_11 , F_6 ( & V_14 -> V_16 ) , V_25 , TRUE ) ;
V_29 = F_5 ( V_11 , F_1 ( V_14 -> V_20 ) , V_28 , TRUE ) ;
F_17 ( V_27 , sizeof( V_27 ) , L_22 , V_14 -> V_30 ) ;
F_5 ( V_11 , V_27 , V_29 , TRUE ) ;
return 1 ;
}
void F_18 ( void ) {
F_19 ( L_23 , L_24 , V_13 , 0 , F_4 , F_2 , NULL ) ;
F_19 ( L_23 , L_25 , V_19 , 0 , F_9 , F_7 , NULL ) ;
F_20 ( L_26 , L_27 , V_22 , 0 , F_13 , F_11 , NULL , V_31 ) ;
F_19 ( L_23 , L_28 , V_26 , 0 , F_16 , F_15 , NULL ) ;
}
