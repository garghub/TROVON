static int
F_1 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_3 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 (
T_2 ,
T_3 ,
T_5 ,
T_7 ,
T_8 ,
1U ,
127U ,
& V_2 ,
TRUE ) ;
return T_3 ;
}
static int
F_5 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_6 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_7 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_8 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL ) ;
return T_3 ;
}
static int
F_9 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_9 * V_4 = T_5 -> V_4 ;
T_1 * V_5 = NULL ;
T_10 * V_6 = NULL ;
T_6 * V_7 = NULL ;
T_11 * V_8 = NULL ;
T_12 * V_9 ;
T_3 = F_10 (
T_2 ,
T_3 ,
T_5 ,
T_7 ,
T_8 ,
V_3 ,
V_3 ,
FALSE ,
& V_5 ,
NULL ) ;
if ( V_5 ) {
switch( V_2 ) {
case 1 :
V_6 = F_11 (
V_10 ,
T_2 ,
T_3 ,
0 ,
V_11 ) ;
V_7 = F_12 ( V_6 , V_12 ) ;
F_13 (
F_14 ( V_5 , 0 ) ,
V_4 ,
V_7 ) ;
break;
case 3 :
V_8 = F_15 (
& V_4 -> V_13 ,
V_4 -> V_14 ,
& V_4 -> V_15 ) ;
if( V_8 ) {
switch( V_8 -> V_16 ) {
case V_17 :
F_16 (
V_18 ,
F_14 ( V_5 , 0 ) ,
V_4 ,
V_10 ,
NULL ) ;
break;
case V_19 :
case V_20 :
F_16 (
V_21 ,
F_14 ( V_5 , 0 ) ,
V_4 ,
V_10 ,
NULL ) ;
break;
default:
F_17 (
V_22 ,
F_14 ( V_5 , 0 ) ,
T_5 -> V_4 ,
V_10 ,
& V_9 ,
NULL ) ;
break;
}
}
else{
F_17 (
V_22 ,
F_14 ( V_5 , 0 ) ,
T_5 -> V_4 ,
V_10 ,
& V_9 ,
NULL ) ;
}
break;
default:
break;
}
}
return T_3 ;
}
static int
F_18 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_19 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_23 , V_24 ,
NULL ) ;
return T_3 ;
}
static int
F_20 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_21 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_25 , V_26 ) ;
return T_3 ;
}
static int
F_22 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_23 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_27 , V_28 ,
1 , 1 , TRUE ) ;
return T_3 ;
}
static int
F_24 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_25 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_26 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_27 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_8 (
T_2 ,
T_3 ,
T_5 ,
T_7 ,
T_8 ,
- 1 ,
- 1 ,
FALSE ,
& T_5 -> V_29 . V_30 ) ;
T_5 -> V_29 . V_31 = TRUE ;
return T_3 ;
}
static int
F_28 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_6 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_29 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_8 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL ) ;
return T_3 ;
}
static int
F_30 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_1 * V_5 = NULL ;
T_9 * V_4 = T_5 -> V_4 ;
T_11 * V_8 = NULL ;
T_12 * V_9 ;
T_3 = F_10 (
T_2 ,
T_3 ,
T_5 ,
T_7 , T_8 ,
V_3 ,
V_3 ,
FALSE ,
& V_5 ,
NULL ) ;
if ( V_5 ) {
if( ( V_4 -> V_14 ) && ( ! V_4 -> V_32 ) ) {
V_8 = F_15 (
& V_4 -> V_13 ,
V_4 -> V_14 ,
& V_4 -> V_15 ) ;
}
if( ( V_4 -> V_32 ) && ( ! V_4 -> V_14 ) ) {
V_8 = F_15 (
& V_4 -> V_15 ,
V_4 -> V_32 ,
& V_4 -> V_13 ) ;
}
if( ( V_4 -> V_32 ) && ( V_4 -> V_14 ) ) {
V_8 = F_15 (
& V_4 -> V_15 ,
V_4 -> V_32 ,
& V_4 -> V_13 ) ;
}
if( V_8 ) {
switch( V_8 -> V_16 ) {
case V_17 :
F_16 (
V_18 ,
F_14 ( V_5 , 0 ) ,
V_4 ,
V_10 ,
NULL ) ;
break;
case V_19 :
case V_20 :
F_16 (
V_21 ,
F_14 ( V_5 , 0 ) ,
V_4 ,
V_10 ,
NULL ) ;
break;
default:
F_17 (
V_22 ,
F_14 ( V_5 , 0 ) ,
T_5 -> V_4 ,
V_10 ,
& V_9 ,
NULL ) ;
break;
}
} else {
F_17 (
V_22 ,
F_14 ( V_5 , 0 ) ,
T_5 -> V_4 ,
V_10 ,
& V_9 ,
NULL ) ;
}
}
T_3 += F_31 ( T_2 , T_3 ) ;
return T_3 ;
}
static int
F_32 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_19 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_33 , V_34 ,
NULL ) ;
return T_3 ;
}
static int
F_33 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_21 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_35 , V_36 ) ;
return T_3 ;
}
static int
F_34 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_10 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL , NULL ) ;
return T_3 ;
}
static int
F_35 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_36 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_37 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_38 ( T_2 , T_3 , T_5 , T_7 , T_8 ) ;
return T_3 ;
}
static int
F_39 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_21 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_37 , V_38 ) ;
return T_3 ;
}
static int
F_40 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_41 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_39 , V_40 ,
1 , V_3 , FALSE ) ;
return T_3 ;
}
static int
F_42 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_43 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_41 , V_42 ) ;
return T_3 ;
}
static int
F_44 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_19 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_43 , V_44 ,
NULL ) ;
return T_3 ;
}
static int
F_45 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_44 ( T_2 , T_3 , T_5 , T_7 , T_8 ) ;
return T_3 ;
}
static int
F_46 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_19 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_45 , V_46 ,
NULL ) ;
return T_3 ;
}
static int
F_47 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_9 * V_4 = T_5 -> V_4 ;
T_11 * V_8 = NULL ;
T_13 V_16 = 0 ;
T_3 = F_26 (
T_2 ,
T_3 ,
T_5 ,
T_7 ,
T_8 ,
& V_16 ) ;
if( ( V_4 -> V_14 ) && ( ! V_4 -> V_32 ) ) {
V_8 = F_15 ( & V_4 -> V_13 ,
V_4 -> V_14 ,
& V_4 -> V_15 ) ;
}
if( ( ! V_4 -> V_14 ) && ( V_4 -> V_32 ) ) {
V_8 = F_15 ( & V_4 -> V_15 ,
V_4 -> V_32 ,
& V_4 -> V_13 ) ;
}
if( V_8 ) {
V_8 -> V_16 = V_16 ;
}
return T_3 ;
}
static int
F_48 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_40 ( T_2 , T_3 , T_5 , T_7 , T_8 ) ;
return T_3 ;
}
static int
F_49 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_19 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_47 , V_48 ,
NULL ) ;
return T_3 ;
}
static int
F_50 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_26 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_51 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_26 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_52 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_10 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL , NULL ) ;
return T_3 ;
}
static int
F_53 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 (
T_2 ,
T_3 ,
T_5 ,
T_7 ,
T_8 ,
NULL ) ;
T_3 = F_2 (
T_2 ,
T_3 ,
T_5 ,
T_7 ,
T_8 ,
NULL ) ;
return T_3 ;
}
static int
F_54 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_10 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL , NULL ) ;
return T_3 ;
}
static int
F_55 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_56 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_57 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_58 (
V_49 ,
T_2 ,
T_3 ,
T_5 -> V_4 ,
T_7 , NULL ) ;
T_3 = F_58 (
V_49 ,
T_2 ,
T_3 ,
T_5 -> V_4 ,
T_7 , NULL ) ;
return T_3 ;
}
static int
F_59 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_21 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_50 , V_51 ) ;
return T_3 ;
}
static int
F_60 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_19 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_52 , V_53 ,
NULL ) ;
return T_3 ;
}
static int
F_61 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_43 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_54 , V_55 ) ;
return T_3 ;
}
static int
F_62 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_8 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL ) ;
return T_3 ;
}
static int
F_63 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_23 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_56 , V_57 ,
1 , 1 , TRUE ) ;
return T_3 ;
}
static int
F_64 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_9 * V_4 = T_5 -> V_4 ;
T_14 * V_58 = NULL ;
T_11 * V_8 = NULL ;
T_13 V_59 = 0 ;
if( ( V_4 -> V_14 ) && ( ! V_4 -> V_32 ) ) {
V_8 = F_15 (
& V_4 -> V_13 ,
V_4 -> V_14 ,
& V_4 -> V_15 ) ;
if( ! V_8 ) {
V_8 = F_65 ( F_66 () , T_11 ) ;
V_8 -> V_16 = V_60 ;
F_67 ( & V_4 -> V_13 ,
V_4 -> V_14 ,
& V_4 -> V_15 ,
V_8 ) ;
}
}
if( ( ! V_4 -> V_14 ) && ( V_4 -> V_32 ) ) {
V_8 = F_15 ( & V_4 -> V_15 ,
V_4 -> V_32 ,
& V_4 -> V_13 ) ;
if( ! V_8 ) {
V_8 = F_65 ( F_66 () , T_11 ) ;
V_8 -> V_16 = V_60 ;
F_67 ( & V_4 -> V_15 ,
V_4 -> V_32 ,
& V_4 -> V_13 ,
V_8 ) ;
}
}
T_3 = F_21 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_61 , V_62 ) ;
V_59 =
F_68 ( V_4 ) ;
V_58 = ( T_14 * ) F_69 (
V_63 ,
V_59 ) ;
if( ! V_58 ) {
V_58 = F_65 ( F_66 () , T_14 ) ;
V_58 -> V_64 = FALSE ;
F_70 ( V_63 , V_59 , ( void * ) V_58 ) ;
}
if ( V_58 -> V_64 == FALSE ) {
memset ( V_58 , 0 , sizeof( T_14 ) ) ;
V_58 -> V_65 = V_8 ;
V_58 -> V_64 = TRUE ;
}
return T_3 ;
}
static int
F_71 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_10 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL , NULL ) ;
return T_3 ;
}
static int
F_72 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 2U , NULL , TRUE ) ;
return T_3 ;
}
static int
F_73 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 14U , NULL , TRUE ) ;
return T_3 ;
}
static int
F_74 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 2U , NULL , TRUE ) ;
return T_3 ;
}
static int
F_75 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_19 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_66 , V_67 ,
NULL ) ;
return T_3 ;
}
static int
F_76 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_9 * V_4 = T_5 -> V_4 ;
T_13 V_59 = 0 ;
T_11 * V_8 = NULL ;
T_14 * V_58 = NULL ;
V_59 = F_68 ( V_4 ) ;
V_58 = ( T_14 * ) F_69 (
V_63 ,
V_59 ) ;
if( ! V_58 ) {
return T_3 ;
}
if( ( V_4 -> V_14 ) && ( ! V_4 -> V_32 ) ) {
V_8 = F_15 ( & V_4 -> V_13 ,
V_4 -> V_14 ,
& V_4 -> V_15 ) ;
if( ! V_8 ) {
F_67 ( & V_4 -> V_13 ,
V_4 -> V_14 ,
& V_4 -> V_15 ,
V_58 -> V_65 ) ;
}
}
if( ( V_4 -> V_14 ) && ( V_4 -> V_32 ) ) {
V_8 = F_15 (
& V_4 -> V_15 ,
V_4 -> V_32 ,
& V_4 -> V_13 ) ;
if( V_8 ) {
F_67 ( & V_4 -> V_13 ,
V_4 -> V_14 ,
& V_4 -> V_15 ,
V_58 -> V_65 ) ;
} else {
F_67 ( & V_4 -> V_15 ,
V_4 -> V_32 ,
& V_4 -> V_13 ,
V_58 -> V_65 ) ;
F_67 ( & V_4 -> V_13 ,
V_4 -> V_14 ,
& V_4 -> V_15 ,
V_58 -> V_65 ) ;
}
}
memset ( V_58 , 0 , sizeof( T_14 ) ) ;
V_58 -> V_64 = FALSE ;
T_3 = F_21 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_68 , V_69 ) ;
return T_3 ;
}
static int
F_77 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 30U , NULL , TRUE ) ;
return T_3 ;
}
static int
F_78 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_21 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_70 , V_71 ) ;
return T_3 ;
}
static int
F_79 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 (
T_2 ,
T_3 ,
T_5 ,
T_7 ,
T_8 ,
0U ,
30U ,
NULL ,
TRUE ) ;
return T_3 ;
}
static int
F_80 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_21 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_72 , V_73 ) ;
return T_3 ;
}
static int
F_81 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 1U , NULL , TRUE ) ;
return T_3 ;
}
static int
F_82 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_83 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
6 , NULL , TRUE , 0 , V_74 ) ;
return T_3 ;
}
static int
F_84 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_21 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_75 , V_76 ) ;
return T_3 ;
}
static int
F_85 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_19 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_77 , V_78 ,
NULL ) ;
return T_3 ;
}
static void F_86 ( T_1 * T_2 V_1 , T_9 * V_4 V_1 , T_6 * T_7 V_1 ) {
T_4 V_79 ;
F_87 ( & V_79 , V_80 , FALSE , V_4 ) ;
F_22 ( T_2 , 0 , & V_79 , T_7 , V_81 ) ;
}
static void F_13 ( T_1 * T_2 V_1 , T_9 * V_4 V_1 , T_6 * T_7 V_1 ) {
T_4 V_79 ;
F_87 ( & V_79 , V_80 , FALSE , V_4 ) ;
F_85 ( T_2 , 0 , & V_79 , T_7 , V_82 ) ;
}
T_13 F_68 (
T_9 * V_4 )
{
const T_15 * V_83 = NULL ;
T_13 V_84 = 0 ;
T_13 V_85 = 0 ;
if( ( V_4 -> V_15 . type != V_86 ) ||
( V_4 -> V_13 . type != V_86 ) ) {
return V_84 ; }
if( ( V_4 -> V_15 . V_87 != 20 ) ||
( V_4 -> V_13 . V_87 != 20 ) ) {
return V_84 ; }
V_83 = ( const T_15 * ) V_4 -> V_15 . V_88 ;
V_85 =
( ( V_83 [ 0 ] << 24 ) |
( V_83 [ 1 ] << 16 ) |
( V_83 [ 2 ] << 8 ) |
V_83 [ 3 ] ) ;
if( ( V_85 == 0x470027c1 ) ||
( V_85 == 0x47002741 ) ) {
V_84 = ( ( V_83 [ 8 ] ) << 16 ) |
( ( V_83 [ 9 ] ) << 8 ) |
( V_83 [ 10 ] ) ;
}
V_83 = ( const T_15 * ) V_4 -> V_13 . V_88 ;
V_85 = ( ( V_83 [ 0 ] << 24 ) |
( V_83 [ 1 ] << 16 ) |
( V_83 [ 2 ] << 8 ) |
V_83 [ 3 ] ) ;
if( ( V_85 == 0x470027c1 ) ||
( V_85 == 0x47002741 ) ) {
V_84 = ( ( V_83 [ 8 ] ) << 16 ) |
( ( V_83 [ 9 ] ) << 8 ) |
( V_83 [ 10 ] ) ;
}
return V_84 ;
}
int F_88 ( T_9 * V_4 V_1 )
{
int V_89 = V_90 ;
const T_15 * V_83 = NULL ;
T_13 V_85 = 0 ;
if( ( V_4 -> V_15 . type != V_86 ) || ( V_4 -> V_13 . type != V_86 ) ) {
return V_89 ; }
if( ( V_4 -> V_15 . V_87 != 20 ) || ( V_4 -> V_13 . V_87 != 20 ) ) {
return V_89 ; }
V_83 = ( const T_15 * ) V_4 -> V_15 . V_88 ;
V_85 = ( ( V_83 [ 0 ] << 24 ) | ( V_83 [ 1 ] << 16 ) | ( V_83 [ 2 ] << 8 ) | V_83 [ 3 ] ) ;
if( ( V_85 == 0x470027c1 ) || ( V_85 == 0x47002741 ) ) {
V_89 = V_91 ;
}
V_83 = ( const T_15 * ) V_4 -> V_13 . V_88 ;
V_85 = ( ( V_83 [ 0 ] << 24 ) | ( V_83 [ 1 ] << 16 ) | ( V_83 [ 2 ] << 8 ) | V_83 [ 3 ] ) ;
if( ( V_85 == 0x470027c1 ) || ( V_85 == 0x47002741 ) ) {
V_89 = V_92 ;
}
return V_89 ;
}
T_16 * F_89 ( void ) {
return V_93 ;
}
T_11 * F_15 (
T_17 * V_94 ,
T_18 V_95 ,
T_17 * V_96 )
{
T_11 * V_65 = NULL ;
T_13 V_97 = 0 ;
T_13 V_98 = 0 ;
F_90 ( V_98 , V_94 ) ;
V_97 = ( V_98 << 16 ) | V_95 ;
F_90 ( V_98 , V_96 ) ;
V_97 = ( V_98 << 24 ) | V_97 ;
V_65 = ( T_11 * )
F_69 ( F_89 () , V_97 ) ;
return V_65 ;
}
T_11 * F_67 (
T_17 * V_94 ,
T_18 V_95 ,
T_17 * V_96 ,
T_11 * V_99 )
{
T_11 * V_65 = NULL ;
T_13 V_97 = 0 ;
T_13 V_98 = 0 ;
F_90 ( V_98 , V_94 ) ;
V_97 = ( V_98 << 16 ) | V_95 ;
F_90 ( V_98 , V_96 ) ;
V_97 = ( V_98 << 24 ) | V_97 ;
V_65 = ( T_11 * )
F_69 (
F_89 () ,
V_97 ) ;
if( V_65 ) {
return NULL ; }
F_70 (
F_89 () ,
V_97 ,
( void * ) V_99 ) ;
return V_99 ;
}
static int
F_91 (
T_1 * T_2 ,
T_9 * V_4 ,
T_6 * T_7 ,
void * V_88 V_1 )
{
int T_3 = 0 ;
T_10 * V_6 = NULL ;
T_6 * V_7 = NULL ;
T_15 V_100 = 0 ;
T_15 V_101 = 0 ;
T_18 V_102 = 0 ;
V_10 = T_7 ;
if ( ( int ) ( V_103 ) V_88 == FALSE )
{
V_6 = F_92 (
T_7 ,
V_104 ,
T_2 ,
0 ,
0 ,
V_105 ) ;
V_7 = F_12 (
V_6 ,
V_106 ) ;
F_86 (
T_2 ,
V_4 ,
V_7 ) ;
return T_3 +
F_31 ( T_2 , T_3 ) ;
}
if ( ( int ) ( V_103 ) V_88 == TRUE )
{
V_102 = F_93 ( T_2 , T_3 ) ;
V_6 = F_11 (
T_7 ,
T_2 ,
T_3 ,
0 ,
V_107 ) ;
V_7 = F_12 (
V_6 ,
V_108 ) ;
V_101 = F_94 ( T_2 , T_3 ) ;
F_92 ( V_7 ,
V_109 ,
T_2 ,
T_3 ,
1 ,
V_110 ) ;
switch( V_101 & V_111 ) {
case V_112 :
case V_113 :
F_92 ( V_7 ,
V_114 ,
T_2 ,
T_3 ,
1 ,
V_110 ) ;
F_92 ( V_7 ,
V_115 ,
T_2 ,
T_3 ,
1 ,
V_110 ) ;
F_92 ( V_7 ,
V_116 ,
T_2 ,
T_3 ,
1 ,
V_110 ) ;
break;
default:
break;
}
T_3 ++ ;
V_6 = F_11 (
T_7 ,
T_2 ,
T_3 ,
0 ,
V_117 ) ;
V_7 = F_12 ( V_6 , V_118 ) ;
V_100 = F_94 ( T_2 , T_3 ) ;
F_11 ( V_7 ,
T_2 ,
T_3 ,
1 ,
L_1 ,
F_95 ( V_102 & V_119 , V_120 , L_2 ) ,
V_100 ) ;
switch( V_101 & V_111 ) {
case V_112 :
case V_113 :
F_92 (
V_7 ,
V_121 ,
T_2 ,
T_3 ,
1 ,
V_110 ) ;
break;
default:
break;
}
T_3 ++ ;
V_6 = F_11 (
T_7 ,
T_2 ,
T_3 ,
0 ,
V_11 ) ;
V_7 = F_12 (
V_6 ,
V_12 ) ;
F_13 (
F_14 ( T_2 , T_3 ) ,
V_4 ,
V_7 ) ;
return T_3 +
F_31 ( T_2 , T_3 ) ;
}
return T_3 ;
}
static T_19 F_96 (
T_1 * T_2 ,
T_9 * V_4 ,
T_6 * T_7 ,
void * V_88 V_1 )
{
if ( F_97 ( T_2 ) < 2 ) {
return FALSE ; }
switch( F_93 ( T_2 , 0 ) & 0xf8ff ) {
case 0xe802 :
case 0xf802 :
case 0xf002 :
case 0xd802 :
case 0xe002 :
case 0xe012 :
case 0xe022 :
case 0xe032 :
case 0xe042 :
case 0xe052 :
case 0xe062 :
case 0xe072 :
case 0xa002 :
case 0xa012 :
case 0xa022 :
case 0xa032 :
case 0xa042 :
case 0xa052 :
case 0xa062 :
case 0xa072 :
F_91 (
T_2 ,
V_4 ,
T_7 ,
( void * ) TRUE ) ;
return TRUE ;
default:
break;
}
switch( F_93 ( T_2 , 0 ) & 0xfff0 ) {
case 0x0020 :
case 0x00a0 :
F_91 ( T_2 , V_4 , T_7 , ( void * ) FALSE ) ;
return TRUE ;
break;
default:
break;
}
return FALSE ;
}
void F_98 ( void )
{
static T_20 V_122 [] = {
#line 1 "../../asn1/atn-ulcs/packet-atn-ulcs-hfarr.c"
{ & V_81 ,
{ L_3 , L_4 ,
V_123 , V_124 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_82 ,
{ L_5 , L_6 ,
V_123 , V_124 , F_99 ( V_126 ) , 0 ,
NULL , V_125 } } ,
{ & V_127 ,
{ L_7 , L_8 ,
V_128 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_130 ,
{ L_9 , L_10 ,
V_131 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_132 ,
{ L_11 , L_12 ,
V_123 , V_124 , F_99 ( V_133 ) , 0 ,
NULL , V_125 } } ,
{ & V_134 ,
{ L_13 , L_14 ,
V_123 , V_124 , F_99 ( V_135 ) , 0 ,
NULL , V_125 } } ,
{ & V_136 ,
{ L_15 , L_16 ,
V_128 , V_129 , NULL , 0 ,
L_17 , V_125 } } ,
{ & V_137 ,
{ L_18 , L_19 ,
V_138 , V_129 , NULL , 0 ,
L_20 , V_125 } } ,
{ & V_139 ,
{ L_21 , L_22 ,
V_138 , V_129 , NULL , 0 ,
L_23 , V_125 } } ,
{ & V_140 ,
{ L_24 , L_25 ,
V_131 , V_129 , NULL , 0 ,
L_26 , V_125 } } ,
{ & V_141 ,
{ L_27 , L_28 ,
V_142 , V_124 , NULL , 0 ,
L_29 , V_125 } } ,
{ & V_143 ,
{ L_30 , L_31 ,
V_144 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_145 ,
{ L_32 , L_33 ,
V_123 , V_124 , F_99 ( V_146 ) , 0 ,
NULL , V_125 } } ,
{ & V_147 ,
{ L_15 , L_16 ,
V_128 , V_129 , NULL , 0 ,
L_34 , V_125 } } ,
{ & V_148 ,
{ L_18 , L_19 ,
V_138 , V_129 , NULL , 0 ,
L_35 , V_125 } } ,
{ & V_149 ,
{ L_21 , L_22 ,
V_138 , V_129 , NULL , 0 ,
L_36 , V_125 } } ,
{ & V_150 ,
{ L_37 , L_38 ,
V_128 , V_129 , NULL , 0 ,
L_39 , V_125 } } ,
{ & V_151 ,
{ L_40 , L_41 ,
V_128 , V_129 , NULL , 0 ,
L_42 , V_125 } } ,
{ & V_152 ,
{ L_43 , L_44 ,
V_128 , V_129 , NULL , 0 ,
L_45 , V_125 } } ,
{ & V_153 ,
{ L_46 , L_47 ,
V_128 , V_129 , NULL , 0 ,
L_48 , V_125 } } ,
{ & V_154 ,
{ L_49 , L_50 ,
V_128 , V_129 , NULL , 0 ,
L_51 , V_125 } } ,
{ & V_155 ,
{ L_52 , L_53 ,
V_138 , V_129 , NULL , 0 ,
L_54 , V_125 } } ,
{ & V_156 ,
{ L_55 , L_56 ,
V_131 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_157 ,
{ L_57 , L_58 ,
V_123 , V_124 , F_99 ( V_158 ) , 0 ,
L_59 , V_125 } } ,
{ & V_159 ,
{ L_60 , L_61 ,
V_123 , V_124 , F_99 ( V_160 ) , 0 ,
L_62 , V_125 } } ,
{ & V_161 ,
{ L_63 , L_64 ,
V_142 , V_124 , NULL , 0 ,
L_65 , V_125 } } ,
{ & V_162 ,
{ L_66 , L_67 ,
V_142 , V_124 , NULL , 0 ,
L_68 , V_125 } } ,
{ & V_163 ,
{ L_69 , L_70 ,
V_123 , V_124 , F_99 ( V_158 ) , 0 ,
L_59 , V_125 } } ,
{ & V_164 ,
{ L_71 , L_72 ,
V_123 , V_124 , F_99 ( V_160 ) , 0 ,
L_62 , V_125 } } ,
{ & V_165 ,
{ L_73 , L_74 ,
V_142 , V_124 , NULL , 0 ,
L_65 , V_125 } } ,
{ & V_166 ,
{ L_75 , L_76 ,
V_142 , V_124 , NULL , 0 ,
L_68 , V_125 } } ,
{ & V_167 ,
{ L_77 , L_78 ,
V_138 , V_129 , NULL , 0 ,
L_79 , V_125 } } ,
{ & V_168 ,
{ L_80 , L_81 ,
V_131 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_169 ,
{ L_82 , L_83 ,
V_123 , V_124 , F_99 ( V_170 ) , 0 ,
L_84 , V_125 } } ,
{ & V_171 ,
{ L_85 , L_86 ,
V_123 , V_124 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_172 ,
{ L_87 , L_88 ,
V_138 , V_129 , NULL , 0 ,
L_89 , V_125 } } ,
{ & V_173 ,
{ L_90 , L_91 ,
V_123 , V_124 , NULL , 0 ,
L_92 , V_125 } } ,
{ & V_174 ,
{ L_52 , L_53 ,
V_138 , V_129 , NULL , 0 ,
L_93 , V_125 } } ,
{ & V_175 ,
{ L_94 , L_95 ,
V_123 , V_124 , F_99 ( V_176 ) , 0 ,
L_96 , V_125 } } ,
{ & V_177 ,
{ L_97 , L_98 ,
V_123 , V_124 , F_99 ( V_178 ) , 0 ,
L_99 , V_125 } } ,
{ & V_179 ,
{ L_100 , L_101 ,
V_123 , V_124 , F_99 ( V_158 ) , 0 ,
L_59 , V_125 } } ,
{ & V_180 ,
{ L_102 , L_103 ,
V_123 , V_124 , F_99 ( V_160 ) , 0 ,
L_62 , V_125 } } ,
{ & V_181 ,
{ L_104 , L_105 ,
V_142 , V_124 , NULL , 0 ,
L_65 , V_125 } } ,
{ & V_182 ,
{ L_106 , L_107 ,
V_142 , V_124 , NULL , 0 ,
L_68 , V_125 } } ,
{ & V_183 ,
{ L_108 , L_109 ,
V_138 , V_129 , NULL , 0 ,
L_79 , V_125 } } ,
{ & V_184 ,
{ L_110 , L_111 ,
V_123 , V_124 , F_99 ( V_170 ) , 0 ,
L_84 , V_125 } } ,
{ & V_185 ,
{ L_112 , L_113 ,
V_123 , V_124 , F_99 ( V_186 ) , 0 ,
L_114 , V_125 } } ,
{ & V_187 ,
{ L_112 , L_113 ,
V_123 , V_124 , F_99 ( V_188 ) , 0 ,
L_115 , V_125 } } ,
{ & V_189 ,
{ L_116 , L_117 ,
V_123 , V_124 , F_99 ( V_190 ) , 0 ,
L_118 , V_125 } } ,
{ & V_191 ,
{ L_119 , L_120 ,
V_123 , V_124 , F_99 ( V_192 ) , 0 ,
L_121 , V_125 } } ,
{ & V_193 ,
{ L_122 , L_123 ,
V_131 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_194 ,
{ L_124 , L_125 ,
V_131 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_195 ,
{ L_126 , L_127 ,
V_123 , V_124 , F_99 ( V_196 ) , 0 ,
NULL , V_125 } } ,
{ & V_197 ,
{ L_128 , L_129 ,
V_142 , V_124 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_198 ,
{ L_130 , L_131 ,
V_123 , V_124 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_199 ,
{ L_132 , L_133 ,
V_123 , V_124 , F_99 ( V_200 ) , 0 ,
NULL , V_125 } } ,
{ & V_201 ,
{ L_134 , L_135 ,
V_123 , V_124 , F_99 ( V_202 ) , 0 ,
NULL , V_125 } } ,
{ & V_203 ,
{ L_136 , L_137 ,
V_128 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_204 ,
{ L_138 , L_139 ,
V_138 , V_129 , NULL , 0 ,
L_20 , V_125 } } ,
{ & V_205 ,
{ L_140 , L_141 ,
V_138 , V_129 , NULL , 0 ,
L_142 , V_125 } } ,
{ & V_206 ,
{ L_143 , L_144 ,
V_128 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_207 ,
{ L_145 , L_146 ,
V_128 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_208 ,
{ L_147 , L_148 ,
V_131 , V_129 , NULL , 0 ,
L_26 , V_125 } } ,
{ & V_209 ,
{ L_149 , L_150 ,
V_128 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_210 ,
{ L_151 , L_152 ,
V_123 , V_124 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_211 ,
{ L_153 , L_154 ,
V_123 , V_124 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_212 ,
{ L_155 , L_156 ,
V_128 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_213 ,
{ L_157 , L_158 ,
V_128 , V_129 , NULL , 0 ,
NULL , V_125 } } ,
{ & V_214 ,
{ L_159 , L_160 ,
V_215 , 8 , NULL , 0x80 ,
NULL , V_125 } } ,
{ & V_216 ,
{ L_159 , L_160 ,
V_215 , 8 , NULL , 0x80 ,
NULL , V_125 } } ,
{ & V_217 ,
{ L_161 , L_162 ,
V_215 , 8 , NULL , 0x80 ,
NULL , V_125 } } ,
{ & V_218 ,
{ L_163 , L_164 ,
V_215 , 8 , NULL , 0x40 ,
NULL , V_125 } } ,
#line 813 "../../asn1/atn-ulcs/packet-atn-ulcs-template.c"
{ & V_109 ,
{ L_165 ,
L_166 ,
V_219 ,
V_220 ,
F_99 ( V_221 ) ,
0xf8 ,
L_167 ,
V_125 } } ,
{ & V_114 ,
{ L_168 ,
L_169 ,
V_219 ,
V_220 ,
F_99 ( V_222 ) ,
V_223 ,
L_167 ,
V_125 } } ,
{ & V_116 ,
{ L_170 ,
L_171 ,
V_219 ,
V_220 ,
F_99 ( V_224 ) ,
0x01 ,
L_172 ,
V_125 } } ,
{ & V_115 ,
{ L_173 ,
L_174 ,
V_219 ,
V_220 ,
F_99 ( V_225 ) ,
0x02 ,
L_175 ,
V_125 } } ,
{ & V_121 ,
{ L_176 , L_177 ,
V_219 ,
V_220 ,
F_99 ( V_226 ) ,
V_227 ,
NULL ,
V_125 } } ,
} ;
static T_21 * V_228 [] = {
#line 1 "../../asn1/atn-ulcs/packet-atn-ulcs-ettarr.c"
& V_27 ,
& V_25 ,
& V_23 ,
& V_35 ,
& V_33 ,
& V_77 ,
& V_61 ,
& V_229 ,
& V_68 ,
& V_230 ,
& V_70 ,
& V_72 ,
& V_75 ,
& V_231 ,
& V_54 ,
& V_45 ,
& V_47 ,
& V_66 ,
& V_56 ,
& V_52 ,
& V_50 ,
& V_43 ,
& V_41 ,
& V_39 ,
& V_37 ,
#line 863 "../../asn1/atn-ulcs/packet-atn-ulcs-template.c"
& V_108 ,
& V_118 ,
& V_12 ,
& V_106
} ;
V_104 = F_100 (
V_232 ,
L_178 ,
L_179 ) ;
F_101 (
V_104 ,
V_122 ,
F_102 ( V_122 ) ) ;
F_103 (
V_228 ,
F_102 ( V_228 ) ) ;
F_104 (
L_179 ,
F_91 ,
V_104 ) ;
V_18 = F_105 ( L_180 ) ;
V_21 = F_105 ( L_181 ) ;
F_106 (
L_179 ,
& V_22 ) ;
V_63 = F_107 ( F_108 () , F_66 () ) ;
V_93 = F_107 ( F_108 () , F_66 () ) ;
}
void F_109 ( void )
{
F_110 (
L_182 ,
F_96 ,
V_104 ) ;
}
