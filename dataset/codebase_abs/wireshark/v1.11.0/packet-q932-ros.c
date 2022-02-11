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
#line 44 "../../asn1/q932-ros/q932-ros.cnf"
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
#line 70 "../../asn1/q932-ros/q932-ros.cnf"
T_11 V_15 ;
V_15 = F_15 ( T_4 , T_5 ) ;
if ( V_15 )
F_16 ( T_9 , T_10 , T_4 , T_5 , V_15 , V_16 ) ;
V_17 = F_17 ( T_4 , T_5 , V_15 , V_15 ) ;
T_5 += F_15 ( T_4 , T_5 ) ;
return T_5 ;
}
static int
F_18 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 8 "../../asn1/ros/ros-inv.cnf"
T_12 V_18 = NULL ;
const T_13 * V_19 = L_1 ;
V_17 = NULL ;
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_20 , T_10 , V_21 ) ;
#line 13 "../../asn1/ros/ros-inv.cnf"
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
V_17 = F_17 ( T_4 , ( T_7 -> V_32 == V_33 ) ? T_5 >> 3 : T_5 , 0 , 0 ) ;
}
T_7 -> V_27 -> V_34 = T_7 -> V_2 ;
F_32 ( ( V_18 ) ? V_18 : V_35 , V_17 , T_7 -> V_27 , T_9 ) ;
if ( ! V_18 ) {
F_33 ( T_7 -> V_27 , T_9 , & V_36 , L_6 , V_19 ) ;
}
return T_5 ;
}
static int
F_34 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 88 "../../asn1/q932-ros/q932-ros.cnf"
T_11 V_15 ;
V_15 = F_15 ( T_4 , T_5 ) ;
if ( V_15 )
F_16 ( T_9 , T_10 , T_4 , T_5 , V_15 , V_16 ) ;
V_37 = F_17 ( T_4 , T_5 , V_15 , V_15 ) ;
T_5 += F_15 ( T_4 , T_5 ) ;
return T_5 ;
}
static int
F_35 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_38 , T_10 , V_39 ) ;
return T_5 ;
}
static int
F_36 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 7 "../../asn1/ros/ros-res.cnf"
T_12 V_40 = NULL ;
const T_13 * V_19 = L_1 ;
T_7 -> V_2 -> V_3 . V_8 = - 1 ;
V_37 = NULL ;
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_41 , T_10 , V_42 ) ;
#line 13 "../../asn1/ros/ros-res.cnf"
T_7 -> V_2 -> V_3 . V_22 = 2 ;
if ( ( T_7 -> V_2 -> V_3 . V_8 == 0 ) && T_7 -> V_2 -> V_43 ) {
V_40 = F_20 ( T_7 -> V_2 -> V_43 , T_7 -> V_2 -> V_3 . V_4 ) ;
} else if ( ( T_7 -> V_2 -> V_3 . V_8 == 1 ) && T_7 -> V_2 -> V_44 ) {
V_40 = F_21 ( T_7 -> V_2 -> V_44 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_40 = NULL ;
}
if ( ! V_40 ||
! F_22 ( F_23 ( F_24 ( V_40 ) ) ) ) {
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
if ( ! V_37 ) {
V_37 = F_17 ( T_4 , ( T_7 -> V_32 == V_33 ) ? T_5 >> 3 : T_5 , 0 , 0 ) ;
}
T_7 -> V_27 -> V_34 = T_7 -> V_2 ;
F_32 ( ( V_40 ) ? V_40 : V_35 , V_37 , T_7 -> V_27 , T_9 ) ;
if ( ! V_40 ) {
F_33 ( T_7 -> V_27 , T_9 , & V_36 , L_6 , V_19 ) ;
}
}
return T_5 ;
}
static int
F_37 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 107 "../../asn1/q932-ros/q932-ros.cnf"
T_11 V_15 ;
V_15 = F_15 ( T_4 , T_5 ) ;
if ( V_15 )
F_16 ( T_9 , T_10 , T_4 , T_5 , V_15 , V_16 ) ;
V_45 = F_17 ( T_4 , T_5 , V_15 , V_15 ) ;
T_5 += F_15 ( T_4 , T_5 ) ;
return T_5 ;
}
static int
F_38 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 7 "../../asn1/ros/ros-err.cnf"
T_12 V_46 = NULL ;
const T_13 * V_19 = L_1 ;
V_45 = NULL ;
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_47 , T_10 , V_48 ) ;
#line 12 "../../asn1/ros/ros-err.cnf"
T_7 -> V_2 -> V_3 . V_22 = 3 ;
if ( ( T_7 -> V_2 -> V_3 . V_8 == 0 ) && T_7 -> V_2 -> V_49 ) {
V_46 = F_20 ( T_7 -> V_2 -> V_49 , T_7 -> V_2 -> V_3 . V_4 ) ;
} else if ( ( T_7 -> V_2 -> V_3 . V_8 == 1 ) && T_7 -> V_2 -> V_50 ) {
V_46 = F_21 ( T_7 -> V_2 -> V_50 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_46 = NULL ;
}
if ( ! V_46 ||
! F_22 ( F_23 ( F_24 ( V_46 ) ) ) ) {
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
if ( ! V_45 ) {
V_45 = F_17 ( T_4 , ( T_7 -> V_32 == V_33 ) ? T_5 >> 3 : T_5 , 0 , 0 ) ;
}
T_7 -> V_27 -> V_34 = T_7 -> V_2 ;
F_32 ( ( V_46 ) ? V_46 : V_35 , V_45 , T_7 -> V_27 , T_9 ) ;
if ( ! V_46 ) {
F_33 ( T_7 -> V_27 , T_9 , & V_36 , L_6 , V_19 ) ;
}
return T_5 ;
}
static int
F_39 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_51 ) ;
#line 55 "../../asn1/q932-ros/q932-ros.cnf"
F_40 ( V_52 , F_41 ( V_51 , F_42 ( V_53 ) , L_1 ) , 64 ) ;
return T_5 ;
}
static int
F_43 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_51 ) ;
#line 57 "../../asn1/q932-ros/q932-ros.cnf"
F_40 ( V_52 , F_41 ( V_51 , F_42 ( V_54 ) , L_1 ) , 64 ) ;
return T_5 ;
}
static int
F_44 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_51 ) ;
#line 59 "../../asn1/q932-ros/q932-ros.cnf"
F_40 ( V_52 , F_41 ( V_51 , F_42 ( V_55 ) , L_1 ) , 64 ) ;
return T_5 ;
}
static int
F_45 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_51 ) ;
#line 61 "../../asn1/q932-ros/q932-ros.cnf"
F_40 ( V_52 , F_41 ( V_51 , F_42 ( V_56 ) , L_1 ) , 64 ) ;
return T_5 ;
}
static int
F_46 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_7 , T_9 , T_4 , T_5 ,
V_57 , T_10 , V_58 ,
NULL ) ;
return T_5 ;
}
static int
F_47 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 7 "../../asn1/ros/ros-rej.cnf"
const T_13 * V_19 = L_1 ;
V_52 [ 0 ] = '\0' ;
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_59 , T_10 , V_60 ) ;
#line 11 "../../asn1/ros/ros-rej.cnf"
V_19 = F_25 ( F_26 () , L_13 , V_52 ) ;
if ( T_7 -> V_2 -> V_25 >= 0 )
F_27 ( F_28 ( F_29 ( T_9 ) , T_7 -> V_2 -> V_25 ) , L_5 , V_19 ) ;
if ( T_7 -> V_2 -> V_26 )
F_30 ( T_7 -> V_27 -> V_28 , V_29 , V_19 ) ;
if ( T_7 -> V_2 -> V_30 )
F_31 ( T_7 -> V_2 -> V_30 , V_19 , T_7 -> V_2 -> V_31 ) ;
return T_5 ;
}
static int
F_48 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 32 "../../asn1/q932-ros/q932-ros.cnf"
T_7 -> V_2 = V_61 ;
F_49 ( T_7 -> V_2 ) ;
T_5 = F_6 ( T_7 , T_9 , T_4 , T_5 ,
V_62 , T_10 , V_63 ,
NULL ) ;
return T_5 ;
}
static int F_50 ( T_3 * T_4 V_1 , T_14 * V_27 V_1 , T_8 * T_9 V_1 , void * T_15 V_1 ) {
int T_5 = 0 ;
T_6 V_64 ;
F_51 ( & V_64 , V_65 , TRUE , V_27 ) ;
T_5 = F_48 ( FALSE , T_4 , T_5 , & V_64 , T_9 , V_66 ) ;
return T_5 ;
}
static int F_52 ( T_3 * T_4 , T_14 * V_27 , T_8 * T_9 , void * T_15 V_1 ) {
V_61 = F_53 ( V_27 -> V_34 ) ;
F_54 ( V_61 ) ;
return F_50 ( T_4 , V_27 , T_9 , NULL ) ;
}
void F_55 ( void ) {
static T_16 V_67 [] = {
#line 1 "../../asn1/q932-ros/packet-q932-ros-hfarr.c"
{ & V_66 ,
{ L_14 , L_15 ,
V_68 , V_69 , F_42 ( V_70 ) , 0 ,
NULL , V_71 } } ,
{ & V_72 ,
{ L_16 , L_17 ,
V_73 , V_69 , NULL , 0 ,
NULL , V_71 } } ,
{ & V_74 ,
{ L_18 , L_19 ,
V_75 , V_76 , NULL , 0 ,
NULL , V_71 } } ,
{ & V_77 ,
{ L_20 , L_21 ,
V_78 , V_76 , NULL , 0 ,
NULL , V_71 } } ,
{ & V_79 ,
{ L_22 , L_23 ,
V_78 , V_76 , NULL , 0 ,
NULL , V_71 } } ,
{ & V_80 ,
{ L_24 , L_25 ,
V_78 , V_76 , NULL , 0 ,
NULL , V_71 } } ,
{ & V_81 ,
{ L_26 , L_27 ,
V_78 , V_76 , NULL , 0 ,
NULL , V_71 } } ,
{ & V_82 ,
{ L_28 , L_29 ,
V_68 , V_69 , F_42 ( V_83 ) , 0 ,
NULL , V_71 } } ,
{ & V_84 ,
{ L_30 , L_31 ,
V_68 , V_69 , F_42 ( V_85 ) , 0 ,
NULL , V_71 } } ,
{ & V_86 ,
{ L_32 , L_33 ,
V_73 , V_69 , NULL , 0 ,
L_34 , V_71 } } ,
{ & V_87 ,
{ L_35 , L_36 ,
V_78 , V_76 , NULL , 0 ,
NULL , V_71 } } ,
{ & V_88 ,
{ L_37 , L_38 ,
V_68 , V_69 , F_42 ( V_89 ) , 0 ,
L_39 , V_71 } } ,
{ & V_90 ,
{ L_40 , L_41 ,
V_91 , V_76 , NULL , 0 ,
L_42 , V_71 } } ,
{ & V_92 ,
{ L_43 , L_44 ,
V_78 , V_76 , NULL , 0 ,
NULL , V_71 } } ,
{ & V_93 ,
{ L_43 , L_45 ,
V_91 , V_76 , NULL , 0 ,
L_46 , V_71 } } ,
{ & V_94 ,
{ L_47 , L_48 ,
V_68 , V_69 , F_42 ( V_89 ) , 0 ,
L_39 , V_71 } } ,
{ & V_95 ,
{ L_49 , L_50 ,
V_91 , V_76 , NULL , 0 ,
NULL , V_71 } } ,
{ & V_96 ,
{ L_51 , L_52 ,
V_68 , V_69 , F_42 ( V_97 ) , 0 ,
NULL , V_71 } } ,
{ & V_98 ,
{ L_53 , L_54 ,
V_73 , V_69 , F_42 ( V_53 ) , 0 ,
L_55 , V_71 } } ,
{ & V_99 ,
{ L_20 , L_56 ,
V_73 , V_69 , F_42 ( V_54 ) , 0 ,
L_57 , V_71 } } ,
{ & V_100 ,
{ L_22 , L_58 ,
V_73 , V_69 , F_42 ( V_55 ) , 0 ,
L_59 , V_71 } } ,
{ & V_101 ,
{ L_24 , L_60 ,
V_73 , V_69 , F_42 ( V_56 ) , 0 ,
L_61 , V_71 } } ,
{ & V_102 ,
{ L_32 , L_33 ,
V_73 , V_69 , NULL , 0 ,
L_62 , V_71 } } ,
{ & V_103 ,
{ L_63 , L_64 ,
V_73 , V_69 , NULL , 0 ,
L_65 , V_71 } } ,
#line 77 "../../asn1/q932-ros/packet-q932-ros-template.c"
} ;
static T_11 * V_104 [] = {
#line 1 "../../asn1/q932-ros/packet-q932-ros-ettarr.c"
& V_7 ,
& V_63 ,
& V_21 ,
& V_14 ,
& V_42 ,
& V_39 ,
& V_48 ,
& V_60 ,
& V_58 ,
& V_12 ,
#line 82 "../../asn1/q932-ros/packet-q932-ros-template.c"
} ;
static T_17 V_105 [] = {
{ & V_36 , { L_66 , V_106 , V_107 , L_67 , V_108 } } ,
} ;
T_18 * V_109 ;
V_110 = F_56 ( V_111 , V_112 , V_113 ) ;
F_57 ( V_110 ) ;
F_58 ( V_110 , V_67 , F_59 ( V_67 ) ) ;
F_60 ( V_104 , F_59 ( V_104 ) ) ;
V_109 = F_61 ( V_110 ) ;
F_62 ( V_109 , V_105 , F_59 ( V_105 ) ) ;
F_63 ( V_113 , F_52 , V_110 ) ;
}
void F_64 ( void ) {
V_35 = F_65 ( L_68 ) ;
}
