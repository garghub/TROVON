T_1 F_1 ( T_2 * V_1 ) {
#define F_2 1
#define F_3 2
#define F_4 3
#define F_5 4
T_3 V_2 = NULL ;
const T_4 * V_3 = F_6 ( V_1 , F_2 ) ;
const T_4 * V_4 = F_6 ( V_1 , F_3 ) ;
int V_5 = ( int ) F_7 ( V_1 , F_4 ) ;
int V_6 = ( int ) F_7 ( V_1 , F_5 ) ;
if ( ! V_3 [ 0 ] ) {
F_8 ( V_1 , F_2 , L_1 ) ;
return 0 ;
}
if ( F_9 ( V_3 ) ) {
F_8 ( V_1 , F_2 , L_2 ) ;
return 0 ;
}
if ( F_10 ( V_3 ) ) {
F_8 ( V_1 , F_2 , L_3 ) ;
return 0 ;
}
switch ( V_5 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
break;
default:
F_8 ( V_1 , F_4 , L_4 ) ;
return 0 ;
}
switch ( V_6 ) {
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
break;
default:
F_8 ( V_1 , F_5 , L_5 ) ;
return 0 ;
}
V_2 = F_11 ( V_25 , 1 ) ;
V_2 -> V_26 . V_27 = V_28 ;
V_2 -> V_26 . V_29 = V_30 ;
V_2 -> V_31 = F_12 ( V_3 ) ;
V_2 -> V_4 = F_12 ( V_4 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
F_13 ( V_1 , V_2 ) ;
F_14 ( 1 ) ;
}
T_5 F_15 ( T_2 * V_1 ) {
T_3 V_2 = F_16 ( V_1 , 1 ) ;
if ( ! V_2 ) {
F_17 ( V_1 , L_6 ) ;
} else {
F_18 ( V_1 , L_7 ,
V_2 -> V_26 . V_27 , V_2 -> V_26 . V_29 , V_2 -> V_31 , V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_6 ) ;
}
return 1 ;
}
static int F_19 ( T_2 * V_1 ) {
T_3 V_2 = F_16 ( V_1 , 1 ) ;
if ( V_2 -> V_26 . V_29 == - 2 ) {
F_20 ( V_2 ) ;
}
return 0 ;
}
int F_21 ( T_2 * V_1 ) {
F_22 ( T_3 ) ;
return 0 ;
}
