static int
F_1 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& T_7 -> V_2 -> V_3 . V_4 ) ;
return T_5 ;
}
static int
F_3 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_4 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 , & T_7 -> V_2 -> V_3 . V_5 ) ;
return T_5 ;
}
static int
F_5 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_7 , T_9 , T_4 , T_5 ,
V_6 , T_10 , V_7 ,
& T_7 -> V_2 -> V_3 . V_8 ) ;
#line 42 "../../asn1/q932-ros/q932-ros.cnf"
T_7 -> V_2 -> V_3 . V_9 = T_7 -> V_10 ;
return T_5 ;
}
static int
F_7 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_8 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_9 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ) ;
return T_5 ;
}
static int
F_10 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_7 , T_9 , T_4 , T_5 ,
V_11 , T_10 , V_12 ,
NULL ) ;
return T_5 ;
}
static int
F_11 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_12 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_11 ( T_2 , T_4 , T_5 , T_7 , T_9 , T_10 ) ;
return T_5 ;
}
static int
F_13 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_7 , T_9 , T_4 , T_5 ,
V_13 , T_10 , V_14 ,
NULL ) ;
return T_5 ;
}
static int
F_14 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 68 "../../asn1/q932-ros/q932-ros.cnf"
T_11 V_15 ;
V_15 = F_15 ( T_4 , T_5 ) ;
if ( V_15 )
F_16 ( T_9 , T_10 , T_4 , T_5 , V_15 , V_16 ) ;
V_17 = F_17 ( T_4 , T_5 ) ;
T_5 += F_15 ( T_4 , T_5 ) ;
return T_5 ;
}
static int
F_18 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 6 "../../asn1/ros/ros-inv.cnf"
T_12 V_18 = NULL ;
const T_13 * V_19 = L_1 ;
V_17 = NULL ;
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_20 , T_10 , V_21 ) ;
#line 11 "../../asn1/ros/ros-inv.cnf"
T_7 -> V_2 -> V_3 . V_22 = 1 ;
if ( ( T_7 -> V_2 -> V_3 . V_8 == 0 ) && T_7 -> V_2 -> V_23 ) {
V_18 = F_20 ( T_7 -> V_2 -> V_23 , T_7 -> V_2 -> V_3 . V_4 ) ;
} else if ( ( T_7 -> V_2 -> V_3 . V_8 == 1 ) && T_7 -> V_2 -> V_24 ) {
V_18 = F_21 ( T_7 -> V_2 -> V_24 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_18 = NULL ;
}
if ( ! V_18 ||
! F_22 ( F_23 ( F_24 ( V_18 ) ) ) ) {
if ( T_7 -> V_2 -> V_3 . V_8 == 0 )
V_19 = F_25 ( F_26 () , L_2 , T_7 -> V_2 -> V_3 . V_4 ) ;
else if ( T_7 -> V_2 -> V_3 . V_8 == 1 )
V_19 = F_25 ( F_26 () , L_3 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_19 = F_25 ( F_26 () , L_4 ) ;
}
if ( T_7 -> V_2 -> V_25 >= 0 )
F_27 ( F_28 ( F_29 ( T_9 ) , T_7 -> V_2 -> V_25 ) , L_5 , V_19 ) ;
if ( T_7 -> V_2 -> V_26 )
F_30 ( T_7 -> V_27 -> V_28 , V_29 , V_19 ) ;
if ( T_7 -> V_2 -> V_30 )
F_31 ( T_7 -> V_2 -> V_30 , V_19 , T_7 -> V_2 -> V_31 ) ;
if ( ! V_17 ) {
V_17 = F_32 ( T_4 , ( T_7 -> V_32 == V_33 ) ? T_5 >> 3 : T_5 , 0 , 0 ) ;
}
F_33 ( ( V_18 ) ? V_18 : V_34 , V_17 , T_7 -> V_27 , T_9 , T_7 -> V_2 ) ;
if ( ! V_18 ) {
F_34 ( T_7 -> V_27 , T_9 , & V_35 , L_6 , V_19 ) ;
}
return T_5 ;
}
static int
F_35 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 86 "../../asn1/q932-ros/q932-ros.cnf"
T_11 V_15 ;
V_15 = F_15 ( T_4 , T_5 ) ;
if ( V_15 )
F_16 ( T_9 , T_10 , T_4 , T_5 , V_15 , V_16 ) ;
V_36 = F_17 ( T_4 , T_5 ) ;
T_5 += F_15 ( T_4 , T_5 ) ;
return T_5 ;
}
static int
F_36 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_37 , T_10 , V_38 ) ;
return T_5 ;
}
static int
F_37 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 6 "../../asn1/ros/ros-res.cnf"
T_12 V_39 = NULL ;
const T_13 * V_19 = L_1 ;
T_7 -> V_2 -> V_3 . V_8 = - 1 ;
V_36 = NULL ;
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_40 , T_10 , V_41 ) ;
#line 12 "../../asn1/ros/ros-res.cnf"
T_7 -> V_2 -> V_3 . V_22 = 2 ;
if ( ( T_7 -> V_2 -> V_3 . V_8 == 0 ) && T_7 -> V_2 -> V_42 ) {
V_39 = F_20 ( T_7 -> V_2 -> V_42 , T_7 -> V_2 -> V_3 . V_4 ) ;
} else if ( ( T_7 -> V_2 -> V_3 . V_8 == 1 ) && T_7 -> V_2 -> V_43 ) {
V_39 = F_21 ( T_7 -> V_2 -> V_43 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_39 = NULL ;
}
if ( ! V_39 ||
! F_22 ( F_23 ( F_24 ( V_39 ) ) ) ) {
if ( T_7 -> V_2 -> V_3 . V_8 == 0 )
V_19 = F_25 ( F_26 () , L_7 , T_7 -> V_2 -> V_3 . V_4 ) ;
else if ( T_7 -> V_2 -> V_3 . V_8 == 1 )
V_19 = F_25 ( F_26 () , L_8 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_19 = F_25 ( F_26 () , L_9 ) ;
}
if ( T_7 -> V_2 -> V_25 >= 0 )
F_27 ( F_28 ( F_29 ( T_9 ) , T_7 -> V_2 -> V_25 ) , L_5 , V_19 ) ;
if ( T_7 -> V_2 -> V_26 )
F_30 ( T_7 -> V_27 -> V_28 , V_29 , V_19 ) ;
if ( T_7 -> V_2 -> V_30 )
F_31 ( T_7 -> V_2 -> V_30 , V_19 , T_7 -> V_2 -> V_31 ) ;
if ( T_7 -> V_2 -> V_3 . V_8 != - 1 ) {
if ( ! V_36 ) {
V_36 = F_32 ( T_4 , ( T_7 -> V_32 == V_33 ) ? T_5 >> 3 : T_5 , 0 , 0 ) ;
}
F_33 ( ( V_39 ) ? V_39 : V_34 , V_36 , T_7 -> V_27 , T_9 , T_7 -> V_2 ) ;
if ( ! V_39 ) {
F_34 ( T_7 -> V_27 , T_9 , & V_35 , L_6 , V_19 ) ;
}
}
return T_5 ;
}
static int
F_38 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 105 "../../asn1/q932-ros/q932-ros.cnf"
T_11 V_15 ;
V_15 = F_15 ( T_4 , T_5 ) ;
if ( V_15 )
F_16 ( T_9 , T_10 , T_4 , T_5 , V_15 , V_16 ) ;
V_44 = F_17 ( T_4 , T_5 ) ;
T_5 += F_15 ( T_4 , T_5 ) ;
return T_5 ;
}
static int
F_39 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 6 "../../asn1/ros/ros-err.cnf"
T_12 V_45 = NULL ;
const T_13 * V_19 = L_1 ;
V_44 = NULL ;
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_46 , T_10 , V_47 ) ;
#line 11 "../../asn1/ros/ros-err.cnf"
T_7 -> V_2 -> V_3 . V_22 = 3 ;
if ( ( T_7 -> V_2 -> V_3 . V_8 == 0 ) && T_7 -> V_2 -> V_48 ) {
V_45 = F_20 ( T_7 -> V_2 -> V_48 , T_7 -> V_2 -> V_3 . V_4 ) ;
} else if ( ( T_7 -> V_2 -> V_3 . V_8 == 1 ) && T_7 -> V_2 -> V_49 ) {
V_45 = F_21 ( T_7 -> V_2 -> V_49 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_45 = NULL ;
}
if ( ! V_45 ||
! F_22 ( F_23 ( F_24 ( V_45 ) ) ) ) {
if ( T_7 -> V_2 -> V_3 . V_8 == 0 )
V_19 = F_25 ( F_26 () , L_10 , T_7 -> V_2 -> V_3 . V_4 ) ;
else if ( T_7 -> V_2 -> V_3 . V_8 == 1 )
V_19 = F_25 ( F_26 () , L_11 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_19 = F_25 ( F_26 () , L_12 ) ;
}
if ( T_7 -> V_2 -> V_25 >= 0 )
F_27 ( F_28 ( F_29 ( T_9 ) , T_7 -> V_2 -> V_25 ) , L_5 , V_19 ) ;
if ( T_7 -> V_2 -> V_26 )
F_30 ( T_7 -> V_27 -> V_28 , V_29 , V_19 ) ;
if ( T_7 -> V_2 -> V_30 )
F_31 ( T_7 -> V_2 -> V_30 , V_19 , T_7 -> V_2 -> V_31 ) ;
if ( ! V_44 ) {
V_44 = F_32 ( T_4 , ( T_7 -> V_32 == V_33 ) ? T_5 >> 3 : T_5 , 0 , 0 ) ;
}
F_33 ( ( V_45 ) ? V_45 : V_34 , V_44 , T_7 -> V_27 , T_9 , T_7 -> V_2 ) ;
if ( ! V_45 ) {
F_34 ( T_7 -> V_27 , T_9 , & V_35 , L_6 , V_19 ) ;
}
return T_5 ;
}
static int
F_40 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_50 ) ;
#line 53 "../../asn1/q932-ros/q932-ros.cnf"
F_41 ( V_51 , F_42 ( V_50 , F_43 ( V_52 ) , L_1 ) , 64 ) ;
return T_5 ;
}
static int
F_44 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_50 ) ;
#line 55 "../../asn1/q932-ros/q932-ros.cnf"
F_41 ( V_51 , F_42 ( V_50 , F_43 ( V_53 ) , L_1 ) , 64 ) ;
return T_5 ;
}
static int
F_45 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_50 ) ;
#line 57 "../../asn1/q932-ros/q932-ros.cnf"
F_41 ( V_51 , F_42 ( V_50 , F_43 ( V_54 ) , L_1 ) , 64 ) ;
return T_5 ;
}
static int
F_46 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_50 ) ;
#line 59 "../../asn1/q932-ros/q932-ros.cnf"
F_41 ( V_51 , F_42 ( V_50 , F_43 ( V_55 ) , L_1 ) , 64 ) ;
return T_5 ;
}
static int
F_47 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_7 , T_9 , T_4 , T_5 ,
V_56 , T_10 , V_57 ,
NULL ) ;
return T_5 ;
}
static int
F_48 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 6 "../../asn1/ros/ros-rej.cnf"
const T_13 * V_19 = L_1 ;
V_51 [ 0 ] = '\0' ;
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_58 , T_10 , V_59 ) ;
#line 10 "../../asn1/ros/ros-rej.cnf"
V_19 = F_25 ( F_26 () , L_13 , V_51 ) ;
if ( T_7 -> V_2 -> V_25 >= 0 )
F_27 ( F_28 ( F_29 ( T_9 ) , T_7 -> V_2 -> V_25 ) , L_5 , V_19 ) ;
if ( T_7 -> V_2 -> V_26 )
F_30 ( T_7 -> V_27 -> V_28 , V_29 , V_19 ) ;
if ( T_7 -> V_2 -> V_30 )
F_31 ( T_7 -> V_2 -> V_30 , V_19 , T_7 -> V_2 -> V_31 ) ;
return T_5 ;
}
static int
F_49 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 30 "../../asn1/q932-ros/q932-ros.cnf"
T_7 -> V_2 = V_60 ;
F_50 ( T_7 -> V_2 ) ;
T_5 = F_6 ( T_7 , T_9 , T_4 , T_5 ,
V_61 , T_10 , V_62 ,
NULL ) ;
return T_5 ;
}
static int F_51 ( T_3 * T_4 V_1 , T_14 * V_27 V_1 , T_8 * T_9 V_1 , void * T_15 V_1 ) {
int T_5 = 0 ;
T_6 V_63 ;
F_52 ( & V_63 , V_64 , TRUE , V_27 ) ;
T_5 = F_49 ( FALSE , T_4 , T_5 , & V_63 , T_9 , V_65 ) ;
return T_5 ;
}
static int F_53 ( T_3 * T_4 , T_14 * V_27 , T_8 * T_9 , void * T_15 ) {
if ( T_15 == NULL )
return 0 ;
V_60 = F_54 ( T_15 ) ;
F_55 ( V_60 ) ;
return F_51 ( T_4 , V_27 , T_9 , NULL ) ;
}
void F_56 ( void ) {
static T_16 V_66 [] = {
#line 1 "../../asn1/q932-ros/packet-q932-ros-hfarr.c"
{ & V_65 ,
{ L_14 , L_15 ,
V_67 , V_68 , F_43 ( V_69 ) , 0 ,
NULL , V_70 } } ,
{ & V_71 ,
{ L_16 , L_17 ,
V_72 , V_68 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_73 ,
{ L_18 , L_19 ,
V_74 , V_75 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_76 ,
{ L_20 , L_21 ,
V_77 , V_75 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_78 ,
{ L_22 , L_23 ,
V_77 , V_75 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_79 ,
{ L_24 , L_25 ,
V_77 , V_75 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_80 ,
{ L_26 , L_27 ,
V_77 , V_75 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_81 ,
{ L_28 , L_29 ,
V_67 , V_68 , F_43 ( V_82 ) , 0 ,
NULL , V_70 } } ,
{ & V_83 ,
{ L_30 , L_31 ,
V_67 , V_68 , F_43 ( V_84 ) , 0 ,
NULL , V_70 } } ,
{ & V_85 ,
{ L_32 , L_33 ,
V_72 , V_68 , NULL , 0 ,
L_34 , V_70 } } ,
{ & V_86 ,
{ L_35 , L_36 ,
V_77 , V_75 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_87 ,
{ L_37 , L_38 ,
V_67 , V_68 , F_43 ( V_88 ) , 0 ,
L_39 , V_70 } } ,
{ & V_89 ,
{ L_40 , L_41 ,
V_90 , V_75 , NULL , 0 ,
L_42 , V_70 } } ,
{ & V_91 ,
{ L_43 , L_44 ,
V_77 , V_75 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_92 ,
{ L_43 , L_45 ,
V_90 , V_75 , NULL , 0 ,
L_46 , V_70 } } ,
{ & V_93 ,
{ L_47 , L_48 ,
V_67 , V_68 , F_43 ( V_88 ) , 0 ,
L_39 , V_70 } } ,
{ & V_94 ,
{ L_49 , L_50 ,
V_90 , V_75 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_95 ,
{ L_51 , L_52 ,
V_67 , V_68 , F_43 ( V_96 ) , 0 ,
NULL , V_70 } } ,
{ & V_97 ,
{ L_53 , L_54 ,
V_72 , V_68 , F_43 ( V_52 ) , 0 ,
L_55 , V_70 } } ,
{ & V_98 ,
{ L_20 , L_56 ,
V_72 , V_68 , F_43 ( V_53 ) , 0 ,
L_57 , V_70 } } ,
{ & V_99 ,
{ L_22 , L_58 ,
V_72 , V_68 , F_43 ( V_54 ) , 0 ,
L_59 , V_70 } } ,
{ & V_100 ,
{ L_24 , L_60 ,
V_72 , V_68 , F_43 ( V_55 ) , 0 ,
L_61 , V_70 } } ,
{ & V_101 ,
{ L_32 , L_33 ,
V_72 , V_68 , NULL , 0 ,
L_62 , V_70 } } ,
{ & V_102 ,
{ L_63 , L_64 ,
V_72 , V_68 , NULL , 0 ,
L_65 , V_70 } } ,
#line 81 "../../asn1/q932-ros/packet-q932-ros-template.c"
} ;
static T_11 * V_103 [] = {
#line 1 "../../asn1/q932-ros/packet-q932-ros-ettarr.c"
& V_7 ,
& V_62 ,
& V_21 ,
& V_14 ,
& V_41 ,
& V_38 ,
& V_47 ,
& V_59 ,
& V_57 ,
& V_12 ,
#line 86 "../../asn1/q932-ros/packet-q932-ros-template.c"
} ;
static T_17 V_104 [] = {
{ & V_35 , { L_66 , V_105 , V_106 , L_67 , V_107 } } ,
} ;
T_18 * V_108 ;
V_109 = F_57 ( V_110 , V_111 , V_112 ) ;
F_58 ( V_109 ) ;
F_59 ( V_109 , V_66 , F_60 ( V_66 ) ) ;
F_61 ( V_103 , F_60 ( V_103 ) ) ;
V_108 = F_62 ( V_109 ) ;
F_63 ( V_108 , V_104 , F_60 ( V_104 ) ) ;
F_64 ( V_112 , F_53 , V_109 ) ;
}
void F_65 ( void ) {
V_34 = F_66 ( L_68 ) ;
}
