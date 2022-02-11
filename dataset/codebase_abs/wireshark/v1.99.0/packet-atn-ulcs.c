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
T_6 * V_6 = NULL ;
T_10 * V_7 = NULL ;
T_11 * V_8 ;
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
V_9 , T_2 , T_3 , 0 ,
V_10 , NULL , V_11 ) ;
F_12 (
F_13 ( V_5 , 0 ) ,
V_4 ,
V_6 ) ;
break;
case 3 :
V_7 = F_14 (
& V_4 -> V_12 ,
V_4 -> V_13 ,
& V_4 -> V_14 ) ;
if( V_7 ) {
switch( V_7 -> V_15 ) {
case V_16 :
F_15 (
V_17 ,
F_13 ( V_5 , 0 ) ,
V_4 ,
V_9 ,
NULL ) ;
break;
case V_18 :
case V_19 :
F_15 (
V_20 ,
F_13 ( V_5 , 0 ) ,
V_4 ,
V_9 ,
NULL ) ;
break;
default:
F_16 (
V_21 ,
F_13 ( V_5 , 0 ) ,
T_5 -> V_4 ,
V_9 ,
& V_8 ,
NULL ) ;
break;
}
}
else{
F_16 (
V_21 ,
F_13 ( V_5 , 0 ) ,
T_5 -> V_4 ,
V_9 ,
& V_8 ,
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
F_17 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_22 , V_23 ,
NULL ) ;
return T_3 ;
}
static int
F_19 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_20 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_24 , V_25 ) ;
return T_3 ;
}
static int
F_21 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_22 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_26 , V_27 ,
1 , 1 , TRUE ) ;
return T_3 ;
}
static int
F_23 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_24 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_25 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_26 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_8 (
T_2 ,
T_3 ,
T_5 ,
T_7 ,
T_8 ,
- 1 ,
- 1 ,
FALSE ,
& T_5 -> V_28 . V_29 ) ;
T_5 -> V_28 . V_30 = TRUE ;
return T_3 ;
}
static int
F_27 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_6 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_28 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_8 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL ) ;
return T_3 ;
}
static int
F_29 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_1 * V_5 = NULL ;
T_9 * V_4 = T_5 -> V_4 ;
T_10 * V_7 = NULL ;
T_11 * V_8 ;
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
if( ( V_4 -> V_13 ) && ( ! V_4 -> V_31 ) ) {
V_7 = F_14 (
& V_4 -> V_12 ,
V_4 -> V_13 ,
& V_4 -> V_14 ) ;
}
if( ( V_4 -> V_31 ) && ( ! V_4 -> V_13 ) ) {
V_7 = F_14 (
& V_4 -> V_14 ,
V_4 -> V_31 ,
& V_4 -> V_12 ) ;
}
if( ( V_4 -> V_31 ) && ( V_4 -> V_13 ) ) {
V_7 = F_14 (
& V_4 -> V_14 ,
V_4 -> V_31 ,
& V_4 -> V_12 ) ;
}
if( V_7 ) {
switch( V_7 -> V_15 ) {
case V_16 :
F_15 (
V_17 ,
F_13 ( V_5 , 0 ) ,
V_4 ,
V_9 ,
NULL ) ;
break;
case V_18 :
case V_19 :
F_15 (
V_20 ,
F_13 ( V_5 , 0 ) ,
V_4 ,
V_9 ,
NULL ) ;
break;
default:
F_16 (
V_21 ,
F_13 ( V_5 , 0 ) ,
T_5 -> V_4 ,
V_9 ,
& V_8 ,
NULL ) ;
break;
}
} else {
F_16 (
V_21 ,
F_13 ( V_5 , 0 ) ,
T_5 -> V_4 ,
V_9 ,
& V_8 ,
NULL ) ;
}
}
T_3 += F_30 ( T_2 , T_3 ) ;
return T_3 ;
}
static int
F_31 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_32 , V_33 ,
NULL ) ;
return T_3 ;
}
static int
F_32 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_20 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_34 , V_35 ) ;
return T_3 ;
}
static int
F_33 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_10 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL , NULL ) ;
return T_3 ;
}
static int
F_34 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_35 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_36 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_37 ( T_2 , T_3 , T_5 , T_7 , T_8 ) ;
return T_3 ;
}
static int
F_38 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_20 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_36 , V_37 ) ;
return T_3 ;
}
static int
F_39 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_40 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_38 , V_39 ,
1 , V_3 , FALSE ) ;
return T_3 ;
}
static int
F_41 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_42 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_40 , V_41 ) ;
return T_3 ;
}
static int
F_43 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_42 , V_43 ,
NULL ) ;
return T_3 ;
}
static int
F_44 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_43 ( T_2 , T_3 , T_5 , T_7 , T_8 ) ;
return T_3 ;
}
static int
F_45 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_44 , V_45 ,
NULL ) ;
return T_3 ;
}
static int
F_46 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_9 * V_4 = T_5 -> V_4 ;
T_10 * V_7 = NULL ;
T_12 V_15 = 0 ;
T_3 = F_25 (
T_2 ,
T_3 ,
T_5 ,
T_7 ,
T_8 ,
& V_15 ) ;
if( ( V_4 -> V_13 ) && ( ! V_4 -> V_31 ) ) {
V_7 = F_14 ( & V_4 -> V_12 ,
V_4 -> V_13 ,
& V_4 -> V_14 ) ;
}
if( ( ! V_4 -> V_13 ) && ( V_4 -> V_31 ) ) {
V_7 = F_14 ( & V_4 -> V_14 ,
V_4 -> V_31 ,
& V_4 -> V_12 ) ;
}
if( V_7 ) {
V_7 -> V_15 = V_15 ;
}
return T_3 ;
}
static int
F_47 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_39 ( T_2 , T_3 , T_5 , T_7 , T_8 ) ;
return T_3 ;
}
static int
F_48 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_46 , V_47 ,
NULL ) ;
return T_3 ;
}
static int
F_49 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_25 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_50 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_25 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_51 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_10 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL , NULL ) ;
return T_3 ;
}
static int
F_52 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
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
F_53 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_10 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL , NULL ) ;
return T_3 ;
}
static int
F_54 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_55 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_56 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_57 (
V_48 ,
T_2 ,
T_3 ,
T_5 -> V_4 ,
T_7 , NULL ) ;
T_3 = F_57 (
V_48 ,
T_2 ,
T_3 ,
T_5 -> V_4 ,
T_7 , NULL ) ;
return T_3 ;
}
static int
F_58 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_20 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_49 , V_50 ) ;
return T_3 ;
}
static int
F_59 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_51 , V_52 ,
NULL ) ;
return T_3 ;
}
static int
F_60 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_42 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_53 , V_54 ) ;
return T_3 ;
}
static int
F_61 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_8 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL ) ;
return T_3 ;
}
static int
F_62 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_22 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_55 , V_56 ,
1 , 1 , TRUE ) ;
return T_3 ;
}
static int
F_63 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_9 * V_4 = T_5 -> V_4 ;
T_13 * V_57 = NULL ;
T_10 * V_7 = NULL ;
T_12 V_58 = 0 ;
if( ( V_4 -> V_13 ) && ( ! V_4 -> V_31 ) ) {
V_7 = F_14 (
& V_4 -> V_12 ,
V_4 -> V_13 ,
& V_4 -> V_14 ) ;
if( ! V_7 ) {
V_7 = F_64 ( F_65 () , T_10 ) ;
V_7 -> V_15 = V_59 ;
F_66 ( & V_4 -> V_12 ,
V_4 -> V_13 ,
& V_4 -> V_14 ,
V_7 ) ;
}
}
if( ( ! V_4 -> V_13 ) && ( V_4 -> V_31 ) ) {
V_7 = F_14 ( & V_4 -> V_14 ,
V_4 -> V_31 ,
& V_4 -> V_12 ) ;
if( ! V_7 ) {
V_7 = F_64 ( F_65 () , T_10 ) ;
V_7 -> V_15 = V_59 ;
F_66 ( & V_4 -> V_14 ,
V_4 -> V_31 ,
& V_4 -> V_12 ,
V_7 ) ;
}
}
T_3 = F_20 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_60 , V_61 ) ;
V_58 =
F_67 ( V_4 ) ;
V_57 = ( T_13 * ) F_68 (
V_62 ,
V_58 ) ;
if( ! V_57 ) {
V_57 = F_64 ( F_65 () , T_13 ) ;
V_57 -> V_63 = FALSE ;
F_69 ( V_62 , V_58 , ( void * ) V_57 ) ;
}
if ( V_57 -> V_63 == FALSE ) {
memset ( V_57 , 0 , sizeof( T_13 ) ) ;
V_57 -> V_64 = V_7 ;
V_57 -> V_63 = TRUE ;
}
return T_3 ;
}
static int
F_70 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_10 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_3 , V_3 , FALSE , NULL , NULL ) ;
return T_3 ;
}
static int
F_71 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 2U , NULL , TRUE ) ;
return T_3 ;
}
static int
F_72 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 14U , NULL , TRUE ) ;
return T_3 ;
}
static int
F_73 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 2U , NULL , TRUE ) ;
return T_3 ;
}
static int
F_74 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_65 , V_66 ,
NULL ) ;
return T_3 ;
}
static int
F_75 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_9 * V_4 = T_5 -> V_4 ;
T_12 V_58 = 0 ;
T_10 * V_7 = NULL ;
T_13 * V_57 = NULL ;
V_58 = F_67 ( V_4 ) ;
V_57 = ( T_13 * ) F_68 (
V_62 ,
V_58 ) ;
if( ! V_57 ) {
return T_3 ;
}
if( ( V_4 -> V_13 ) && ( ! V_4 -> V_31 ) ) {
V_7 = F_14 ( & V_4 -> V_12 ,
V_4 -> V_13 ,
& V_4 -> V_14 ) ;
if( ! V_7 ) {
F_66 ( & V_4 -> V_12 ,
V_4 -> V_13 ,
& V_4 -> V_14 ,
V_57 -> V_64 ) ;
}
}
if( ( V_4 -> V_13 ) && ( V_4 -> V_31 ) ) {
V_7 = F_14 (
& V_4 -> V_14 ,
V_4 -> V_31 ,
& V_4 -> V_12 ) ;
if( V_7 ) {
F_66 ( & V_4 -> V_12 ,
V_4 -> V_13 ,
& V_4 -> V_14 ,
V_57 -> V_64 ) ;
} else {
F_66 ( & V_4 -> V_14 ,
V_4 -> V_31 ,
& V_4 -> V_12 ,
V_57 -> V_64 ) ;
F_66 ( & V_4 -> V_12 ,
V_4 -> V_13 ,
& V_4 -> V_14 ,
V_57 -> V_64 ) ;
}
}
memset ( V_57 , 0 , sizeof( T_13 ) ) ;
V_57 -> V_63 = FALSE ;
T_3 = F_20 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_67 , V_68 ) ;
return T_3 ;
}
static int
F_76 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 30U , NULL , TRUE ) ;
return T_3 ;
}
static int
F_77 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_20 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_69 , V_70 ) ;
return T_3 ;
}
static int
F_78 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
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
F_79 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_20 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_71 , V_72 ) ;
return T_3 ;
}
static int
F_80 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 1U , NULL , TRUE ) ;
return T_3 ;
}
static int
F_81 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_82 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
6 , NULL , TRUE , 0 , V_73 ) ;
return T_3 ;
}
static int
F_83 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_20 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_74 , V_75 ) ;
return T_3 ;
}
static int
F_84 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_76 , V_77 ,
NULL ) ;
return T_3 ;
}
static void F_85 ( T_1 * T_2 V_1 , T_9 * V_4 V_1 , T_6 * T_7 V_1 ) {
T_4 V_78 ;
F_86 ( & V_78 , V_79 , FALSE , V_4 ) ;
F_21 ( T_2 , 0 , & V_78 , T_7 , V_80 ) ;
}
static void F_12 ( T_1 * T_2 V_1 , T_9 * V_4 V_1 , T_6 * T_7 V_1 ) {
T_4 V_78 ;
F_86 ( & V_78 , V_79 , FALSE , V_4 ) ;
F_84 ( T_2 , 0 , & V_78 , T_7 , V_81 ) ;
}
T_12 F_67 (
T_9 * V_4 )
{
const T_14 * V_82 = NULL ;
T_12 V_83 = 0 ;
T_12 V_84 = 0 ;
if( ( V_4 -> V_14 . type != V_85 ) ||
( V_4 -> V_12 . type != V_85 ) ) {
return V_83 ; }
if( ( V_4 -> V_14 . V_86 != 20 ) ||
( V_4 -> V_12 . V_86 != 20 ) ) {
return V_83 ; }
V_82 = ( const T_14 * ) V_4 -> V_14 . V_87 ;
V_84 =
( ( V_82 [ 0 ] << 24 ) |
( V_82 [ 1 ] << 16 ) |
( V_82 [ 2 ] << 8 ) |
V_82 [ 3 ] ) ;
if( ( V_84 == 0x470027c1 ) ||
( V_84 == 0x47002741 ) ) {
V_83 = ( ( V_82 [ 8 ] ) << 16 ) |
( ( V_82 [ 9 ] ) << 8 ) |
( V_82 [ 10 ] ) ;
}
V_82 = ( const T_14 * ) V_4 -> V_12 . V_87 ;
V_84 = ( ( V_82 [ 0 ] << 24 ) |
( V_82 [ 1 ] << 16 ) |
( V_82 [ 2 ] << 8 ) |
V_82 [ 3 ] ) ;
if( ( V_84 == 0x470027c1 ) ||
( V_84 == 0x47002741 ) ) {
V_83 = ( ( V_82 [ 8 ] ) << 16 ) |
( ( V_82 [ 9 ] ) << 8 ) |
( V_82 [ 10 ] ) ;
}
return V_83 ;
}
int F_87 ( T_9 * V_4 V_1 )
{
int V_88 = V_89 ;
const T_14 * V_82 = NULL ;
T_12 V_84 = 0 ;
if( ( V_4 -> V_14 . type != V_85 ) || ( V_4 -> V_12 . type != V_85 ) ) {
return V_88 ; }
if( ( V_4 -> V_14 . V_86 != 20 ) || ( V_4 -> V_12 . V_86 != 20 ) ) {
return V_88 ; }
V_82 = ( const T_14 * ) V_4 -> V_14 . V_87 ;
V_84 = ( ( V_82 [ 0 ] << 24 ) | ( V_82 [ 1 ] << 16 ) | ( V_82 [ 2 ] << 8 ) | V_82 [ 3 ] ) ;
if( ( V_84 == 0x470027c1 ) || ( V_84 == 0x47002741 ) ) {
V_88 = V_90 ;
}
V_82 = ( const T_14 * ) V_4 -> V_12 . V_87 ;
V_84 = ( ( V_82 [ 0 ] << 24 ) | ( V_82 [ 1 ] << 16 ) | ( V_82 [ 2 ] << 8 ) | V_82 [ 3 ] ) ;
if( ( V_84 == 0x470027c1 ) || ( V_84 == 0x47002741 ) ) {
V_88 = V_91 ;
}
return V_88 ;
}
T_15 * F_88 ( void ) {
return V_92 ;
}
T_10 * F_14 (
T_16 * V_93 ,
T_17 V_94 ,
T_16 * V_95 )
{
T_10 * V_64 = NULL ;
T_12 V_96 = 0 ;
T_12 V_97 = 0 ;
F_89 ( V_97 , V_93 ) ;
V_96 = ( V_97 << 16 ) | V_94 ;
F_89 ( V_97 , V_95 ) ;
V_96 = ( V_97 << 24 ) | V_96 ;
V_64 = ( T_10 * )
F_68 ( F_88 () , V_96 ) ;
return V_64 ;
}
T_10 * F_66 (
T_16 * V_93 ,
T_17 V_94 ,
T_16 * V_95 ,
T_10 * V_98 )
{
T_10 * V_64 = NULL ;
T_12 V_96 = 0 ;
T_12 V_97 = 0 ;
F_89 ( V_97 , V_93 ) ;
V_96 = ( V_97 << 16 ) | V_94 ;
F_89 ( V_97 , V_95 ) ;
V_96 = ( V_97 << 24 ) | V_96 ;
V_64 = ( T_10 * )
F_68 (
F_88 () ,
V_96 ) ;
if( V_64 ) {
return NULL ; }
F_69 (
F_88 () ,
V_96 ,
( void * ) V_98 ) ;
return V_98 ;
}
static int
F_90 (
T_1 * T_2 ,
T_9 * V_4 ,
T_6 * T_7 ,
void * V_87 V_1 )
{
int T_3 = 0 ;
T_18 * V_99 = NULL ;
T_6 * V_6 = NULL ;
T_14 V_100 = 0 ;
T_14 V_101 = 0 ;
T_17 V_102 = 0 ;
V_9 = T_7 ;
if ( ( int ) ( V_103 ) V_87 == FALSE )
{
V_99 = F_91 (
T_7 ,
V_104 ,
T_2 ,
0 ,
0 ,
V_105 ) ;
V_6 = F_92 (
V_99 ,
V_106 ) ;
F_85 (
T_2 ,
V_4 ,
V_6 ) ;
return T_3 +
F_30 ( T_2 , T_3 ) ;
}
if ( ( int ) ( V_103 ) V_87 == TRUE )
{
V_102 = F_93 ( T_2 , T_3 ) ;
V_6 = F_11 (
T_7 , T_2 , T_3 , 0 ,
V_107 , NULL , V_108 ) ;
V_101 = F_94 ( T_2 , T_3 ) ;
F_91 ( V_6 ,
V_109 ,
T_2 ,
T_3 ,
1 ,
V_110 ) ;
switch( V_101 & V_111 ) {
case V_112 :
case V_113 :
F_91 ( V_6 ,
V_114 ,
T_2 ,
T_3 ,
1 ,
V_110 ) ;
F_91 ( V_6 ,
V_115 ,
T_2 ,
T_3 ,
1 ,
V_110 ) ;
F_91 ( V_6 ,
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
T_7 , T_2 , T_3 , 0 ,
V_117 , NULL , V_118 ) ;
V_100 = F_94 ( T_2 , T_3 ) ;
F_95 ( V_6 , V_119 ,
T_2 ,
T_3 ,
1 ,
V_102 ,
L_1 ,
F_96 ( V_102 & V_120 , V_121 , L_2 ) ,
V_100 ) ;
switch( V_101 & V_111 ) {
case V_112 :
case V_113 :
F_91 (
V_6 ,
V_122 ,
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
T_7 , T_2 , T_3 , 0 ,
V_10 , NULL , V_11 ) ;
F_12 (
F_13 ( T_2 , T_3 ) ,
V_4 ,
V_6 ) ;
return T_3 +
F_30 ( T_2 , T_3 ) ;
}
return T_3 ;
}
static T_19 F_97 (
T_1 * T_2 ,
T_9 * V_4 ,
T_6 * T_7 ,
void * V_87 V_1 )
{
if ( F_98 ( T_2 ) < 2 ) {
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
F_90 (
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
F_90 ( T_2 , V_4 , T_7 , ( void * ) FALSE ) ;
return TRUE ;
break;
default:
break;
}
return FALSE ;
}
void F_99 ( void )
{
static T_20 V_123 [] = {
#line 1 "../../asn1/atn-ulcs/packet-atn-ulcs-hfarr.c"
{ & V_80 ,
{ L_3 , L_4 ,
V_124 , V_125 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_81 ,
{ L_5 , L_6 ,
V_124 , V_125 , F_100 ( V_127 ) , 0 ,
NULL , V_126 } } ,
{ & V_128 ,
{ L_7 , L_8 ,
V_129 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_131 ,
{ L_9 , L_10 ,
V_132 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_133 ,
{ L_11 , L_12 ,
V_124 , V_125 , F_100 ( V_134 ) , 0 ,
NULL , V_126 } } ,
{ & V_135 ,
{ L_13 , L_14 ,
V_124 , V_125 , F_100 ( V_136 ) , 0 ,
NULL , V_126 } } ,
{ & V_137 ,
{ L_15 , L_16 ,
V_129 , V_130 , NULL , 0 ,
L_17 , V_126 } } ,
{ & V_138 ,
{ L_18 , L_19 ,
V_139 , V_130 , NULL , 0 ,
L_20 , V_126 } } ,
{ & V_140 ,
{ L_21 , L_22 ,
V_139 , V_130 , NULL , 0 ,
L_23 , V_126 } } ,
{ & V_141 ,
{ L_24 , L_25 ,
V_132 , V_130 , NULL , 0 ,
L_26 , V_126 } } ,
{ & V_142 ,
{ L_27 , L_28 ,
V_143 , V_125 , NULL , 0 ,
L_29 , V_126 } } ,
{ & V_144 ,
{ L_30 , L_31 ,
V_145 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_146 ,
{ L_32 , L_33 ,
V_124 , V_125 , F_100 ( V_147 ) , 0 ,
NULL , V_126 } } ,
{ & V_148 ,
{ L_15 , L_16 ,
V_129 , V_130 , NULL , 0 ,
L_34 , V_126 } } ,
{ & V_149 ,
{ L_18 , L_19 ,
V_139 , V_130 , NULL , 0 ,
L_35 , V_126 } } ,
{ & V_150 ,
{ L_21 , L_22 ,
V_139 , V_130 , NULL , 0 ,
L_36 , V_126 } } ,
{ & V_151 ,
{ L_37 , L_38 ,
V_129 , V_130 , NULL , 0 ,
L_39 , V_126 } } ,
{ & V_152 ,
{ L_40 , L_41 ,
V_129 , V_130 , NULL , 0 ,
L_42 , V_126 } } ,
{ & V_153 ,
{ L_43 , L_44 ,
V_129 , V_130 , NULL , 0 ,
L_45 , V_126 } } ,
{ & V_154 ,
{ L_46 , L_47 ,
V_129 , V_130 , NULL , 0 ,
L_48 , V_126 } } ,
{ & V_155 ,
{ L_49 , L_50 ,
V_129 , V_130 , NULL , 0 ,
L_51 , V_126 } } ,
{ & V_156 ,
{ L_52 , L_53 ,
V_139 , V_130 , NULL , 0 ,
L_54 , V_126 } } ,
{ & V_157 ,
{ L_55 , L_56 ,
V_132 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_158 ,
{ L_57 , L_58 ,
V_124 , V_125 , F_100 ( V_159 ) , 0 ,
L_59 , V_126 } } ,
{ & V_160 ,
{ L_60 , L_61 ,
V_124 , V_125 , F_100 ( V_161 ) , 0 ,
L_62 , V_126 } } ,
{ & V_162 ,
{ L_63 , L_64 ,
V_143 , V_125 , NULL , 0 ,
L_65 , V_126 } } ,
{ & V_163 ,
{ L_66 , L_67 ,
V_143 , V_125 , NULL , 0 ,
L_68 , V_126 } } ,
{ & V_164 ,
{ L_69 , L_70 ,
V_124 , V_125 , F_100 ( V_159 ) , 0 ,
L_59 , V_126 } } ,
{ & V_165 ,
{ L_71 , L_72 ,
V_124 , V_125 , F_100 ( V_161 ) , 0 ,
L_62 , V_126 } } ,
{ & V_166 ,
{ L_73 , L_74 ,
V_143 , V_125 , NULL , 0 ,
L_65 , V_126 } } ,
{ & V_167 ,
{ L_75 , L_76 ,
V_143 , V_125 , NULL , 0 ,
L_68 , V_126 } } ,
{ & V_168 ,
{ L_77 , L_78 ,
V_139 , V_130 , NULL , 0 ,
L_79 , V_126 } } ,
{ & V_169 ,
{ L_80 , L_81 ,
V_132 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_170 ,
{ L_82 , L_83 ,
V_124 , V_125 , F_100 ( V_171 ) , 0 ,
L_84 , V_126 } } ,
{ & V_172 ,
{ L_85 , L_86 ,
V_124 , V_125 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_173 ,
{ L_87 , L_88 ,
V_139 , V_130 , NULL , 0 ,
L_89 , V_126 } } ,
{ & V_174 ,
{ L_90 , L_91 ,
V_124 , V_125 , NULL , 0 ,
L_92 , V_126 } } ,
{ & V_175 ,
{ L_52 , L_53 ,
V_139 , V_130 , NULL , 0 ,
L_93 , V_126 } } ,
{ & V_176 ,
{ L_94 , L_95 ,
V_124 , V_125 , F_100 ( V_177 ) , 0 ,
L_96 , V_126 } } ,
{ & V_178 ,
{ L_97 , L_98 ,
V_124 , V_125 , F_100 ( V_179 ) , 0 ,
L_99 , V_126 } } ,
{ & V_180 ,
{ L_100 , L_101 ,
V_124 , V_125 , F_100 ( V_159 ) , 0 ,
L_59 , V_126 } } ,
{ & V_181 ,
{ L_102 , L_103 ,
V_124 , V_125 , F_100 ( V_161 ) , 0 ,
L_62 , V_126 } } ,
{ & V_182 ,
{ L_104 , L_105 ,
V_143 , V_125 , NULL , 0 ,
L_65 , V_126 } } ,
{ & V_183 ,
{ L_106 , L_107 ,
V_143 , V_125 , NULL , 0 ,
L_68 , V_126 } } ,
{ & V_184 ,
{ L_108 , L_109 ,
V_139 , V_130 , NULL , 0 ,
L_79 , V_126 } } ,
{ & V_185 ,
{ L_110 , L_111 ,
V_124 , V_125 , F_100 ( V_171 ) , 0 ,
L_84 , V_126 } } ,
{ & V_186 ,
{ L_112 , L_113 ,
V_124 , V_125 , F_100 ( V_187 ) , 0 ,
L_114 , V_126 } } ,
{ & V_188 ,
{ L_112 , L_113 ,
V_124 , V_125 , F_100 ( V_189 ) , 0 ,
L_115 , V_126 } } ,
{ & V_190 ,
{ L_116 , L_117 ,
V_124 , V_125 , F_100 ( V_191 ) , 0 ,
L_118 , V_126 } } ,
{ & V_192 ,
{ L_119 , L_120 ,
V_124 , V_125 , F_100 ( V_193 ) , 0 ,
L_121 , V_126 } } ,
{ & V_194 ,
{ L_122 , L_123 ,
V_132 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_195 ,
{ L_124 , L_125 ,
V_132 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_196 ,
{ L_126 , L_127 ,
V_124 , V_125 , F_100 ( V_197 ) , 0 ,
NULL , V_126 } } ,
{ & V_198 ,
{ L_128 , L_129 ,
V_143 , V_125 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_199 ,
{ L_130 , L_131 ,
V_124 , V_125 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_200 ,
{ L_132 , L_133 ,
V_124 , V_125 , F_100 ( V_201 ) , 0 ,
NULL , V_126 } } ,
{ & V_202 ,
{ L_134 , L_135 ,
V_124 , V_125 , F_100 ( V_203 ) , 0 ,
NULL , V_126 } } ,
{ & V_204 ,
{ L_136 , L_137 ,
V_129 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_205 ,
{ L_138 , L_139 ,
V_139 , V_130 , NULL , 0 ,
L_20 , V_126 } } ,
{ & V_206 ,
{ L_140 , L_141 ,
V_139 , V_130 , NULL , 0 ,
L_142 , V_126 } } ,
{ & V_207 ,
{ L_143 , L_144 ,
V_129 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_208 ,
{ L_145 , L_146 ,
V_129 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_209 ,
{ L_147 , L_148 ,
V_132 , V_130 , NULL , 0 ,
L_26 , V_126 } } ,
{ & V_210 ,
{ L_149 , L_150 ,
V_129 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_211 ,
{ L_151 , L_152 ,
V_124 , V_125 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_212 ,
{ L_153 , L_154 ,
V_124 , V_125 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_213 ,
{ L_155 , L_156 ,
V_129 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_214 ,
{ L_157 , L_158 ,
V_129 , V_130 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_215 ,
{ L_159 , L_160 ,
V_216 , 8 , NULL , 0x80 ,
NULL , V_126 } } ,
{ & V_217 ,
{ L_159 , L_160 ,
V_216 , 8 , NULL , 0x80 ,
NULL , V_126 } } ,
{ & V_218 ,
{ L_161 , L_162 ,
V_216 , 8 , NULL , 0x80 ,
NULL , V_126 } } ,
{ & V_219 ,
{ L_163 , L_164 ,
V_216 , 8 , NULL , 0x40 ,
NULL , V_126 } } ,
#line 795 "../../asn1/atn-ulcs/packet-atn-ulcs-template.c"
{ & V_109 ,
{ L_165 ,
L_166 ,
V_220 ,
V_221 ,
F_100 ( V_222 ) ,
0xf8 ,
L_167 ,
V_126 } } ,
{ & V_114 ,
{ L_168 ,
L_169 ,
V_220 ,
V_221 ,
F_100 ( V_223 ) ,
V_224 ,
L_167 ,
V_126 } } ,
{ & V_116 ,
{ L_170 ,
L_171 ,
V_220 ,
V_221 ,
F_100 ( V_225 ) ,
0x01 ,
L_172 ,
V_126 } } ,
{ & V_115 ,
{ L_173 ,
L_174 ,
V_220 ,
V_221 ,
F_100 ( V_226 ) ,
0x02 ,
L_175 ,
V_126 } } ,
{ & V_122 ,
{ L_176 , L_177 ,
V_220 ,
V_221 ,
F_100 ( V_227 ) ,
V_228 ,
NULL ,
V_126 } } ,
{ & V_119 ,
{ L_178 , L_179 ,
V_220 ,
V_221 ,
NULL ,
V_120 ,
NULL ,
V_126 } } ,
} ;
static T_21 * V_229 [] = {
#line 1 "../../asn1/atn-ulcs/packet-atn-ulcs-ettarr.c"
& V_26 ,
& V_24 ,
& V_22 ,
& V_34 ,
& V_32 ,
& V_76 ,
& V_60 ,
& V_230 ,
& V_67 ,
& V_231 ,
& V_69 ,
& V_71 ,
& V_74 ,
& V_232 ,
& V_53 ,
& V_44 ,
& V_46 ,
& V_65 ,
& V_55 ,
& V_51 ,
& V_49 ,
& V_42 ,
& V_40 ,
& V_38 ,
& V_36 ,
#line 853 "../../asn1/atn-ulcs/packet-atn-ulcs-template.c"
& V_107 ,
& V_117 ,
& V_10 ,
& V_106
} ;
V_104 = F_101 (
V_233 ,
L_180 ,
L_181 ) ;
F_102 (
V_104 ,
V_123 ,
F_103 ( V_123 ) ) ;
F_104 (
V_229 ,
F_103 ( V_229 ) ) ;
F_105 (
L_181 ,
F_90 ,
V_104 ) ;
V_17 = F_106 ( L_182 ) ;
V_20 = F_106 ( L_183 ) ;
F_107 (
L_181 ,
& V_21 ) ;
V_62 = F_108 ( F_109 () , F_65 () ) ;
V_92 = F_108 ( F_109 () , F_65 () ) ;
}
void F_110 ( void )
{
F_111 (
L_184 ,
F_97 ,
V_104 ) ;
}
