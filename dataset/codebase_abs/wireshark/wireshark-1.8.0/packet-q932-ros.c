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
#line 43 "../../asn1/q932-ros/q932-ros.cnf"
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
#line 69 "../../asn1/q932-ros/q932-ros.cnf"
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
V_19 = F_25 ( L_2 , T_7 -> V_2 -> V_3 . V_4 ) ;
else if ( T_7 -> V_2 -> V_3 . V_8 == 1 )
V_19 = F_25 ( L_3 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_19 = F_25 ( L_4 ) ;
}
if ( T_7 -> V_2 -> V_25 >= 0 )
F_26 ( F_27 ( F_28 ( T_9 ) , T_7 -> V_2 -> V_25 ) , L_5 , V_19 ) ;
if ( T_7 -> V_2 -> V_26 && F_29 ( T_7 -> V_27 -> V_28 , V_29 ) )
F_30 ( T_7 -> V_27 -> V_28 , V_29 , V_19 ) ;
if ( T_7 -> V_2 -> V_30 )
F_31 ( T_7 -> V_2 -> V_30 , V_19 , T_7 -> V_2 -> V_31 ) ;
if ( ! V_17 ) {
V_17 = F_17 ( T_4 , ( T_7 -> V_32 == V_33 ) ? T_5 >> 3 : T_5 , 0 , 0 ) ;
}
T_7 -> V_27 -> V_34 = T_7 -> V_2 ;
F_32 ( ( V_18 ) ? V_18 : V_35 , V_17 , T_7 -> V_27 , T_9 ) ;
if ( ! V_18 ) {
F_33 ( T_7 -> V_27 , T_9 , V_36 , V_37 , L_6 , V_19 ) ;
}
return T_5 ;
}
static int
F_34 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 87 "../../asn1/q932-ros/q932-ros.cnf"
T_11 V_15 ;
V_15 = F_15 ( T_4 , T_5 ) ;
if ( V_15 )
F_16 ( T_9 , T_10 , T_4 , T_5 , V_15 , V_16 ) ;
V_38 = F_17 ( T_4 , T_5 , V_15 , V_15 ) ;
T_5 += F_15 ( T_4 , T_5 ) ;
return T_5 ;
}
static int
F_35 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_39 , T_10 , V_40 ) ;
return T_5 ;
}
static int
F_36 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 7 "../../asn1/ros/ros-res.cnf"
T_12 V_41 = NULL ;
const T_13 * V_19 = L_1 ;
T_7 -> V_2 -> V_3 . V_8 = - 1 ;
V_38 = NULL ;
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_42 , T_10 , V_43 ) ;
#line 13 "../../asn1/ros/ros-res.cnf"
T_7 -> V_2 -> V_3 . V_22 = 2 ;
if ( ( T_7 -> V_2 -> V_3 . V_8 == 0 ) && T_7 -> V_2 -> V_44 ) {
V_41 = F_20 ( T_7 -> V_2 -> V_44 , T_7 -> V_2 -> V_3 . V_4 ) ;
} else if ( ( T_7 -> V_2 -> V_3 . V_8 == 1 ) && T_7 -> V_2 -> V_45 ) {
V_41 = F_21 ( T_7 -> V_2 -> V_45 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_41 = NULL ;
}
if ( ! V_41 ||
! F_22 ( F_23 ( F_24 ( V_41 ) ) ) ) {
if ( T_7 -> V_2 -> V_3 . V_8 == 0 )
V_19 = F_25 ( L_7 , T_7 -> V_2 -> V_3 . V_4 ) ;
else if ( T_7 -> V_2 -> V_3 . V_8 == 1 )
V_19 = F_25 ( L_8 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_19 = F_25 ( L_9 ) ;
}
if ( T_7 -> V_2 -> V_25 >= 0 )
F_26 ( F_27 ( F_28 ( T_9 ) , T_7 -> V_2 -> V_25 ) , L_5 , V_19 ) ;
if ( T_7 -> V_2 -> V_26 && F_29 ( T_7 -> V_27 -> V_28 , V_29 ) )
F_30 ( T_7 -> V_27 -> V_28 , V_29 , V_19 ) ;
if ( T_7 -> V_2 -> V_30 )
F_31 ( T_7 -> V_2 -> V_30 , V_19 , T_7 -> V_2 -> V_31 ) ;
if ( T_7 -> V_2 -> V_3 . V_8 != - 1 ) {
if ( ! V_38 ) {
V_38 = F_17 ( T_4 , ( T_7 -> V_32 == V_33 ) ? T_5 >> 3 : T_5 , 0 , 0 ) ;
}
T_7 -> V_27 -> V_34 = T_7 -> V_2 ;
F_32 ( ( V_41 ) ? V_41 : V_35 , V_38 , T_7 -> V_27 , T_9 ) ;
if ( ! V_41 ) {
F_33 ( T_7 -> V_27 , T_9 , V_36 , V_37 , L_6 , V_19 ) ;
}
}
return T_5 ;
}
static int
F_37 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 106 "../../asn1/q932-ros/q932-ros.cnf"
T_11 V_15 ;
V_15 = F_15 ( T_4 , T_5 ) ;
if ( V_15 )
F_16 ( T_9 , T_10 , T_4 , T_5 , V_15 , V_16 ) ;
V_46 = F_17 ( T_4 , T_5 , V_15 , V_15 ) ;
T_5 += F_15 ( T_4 , T_5 ) ;
return T_5 ;
}
static int
F_38 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 7 "../../asn1/ros/ros-err.cnf"
T_12 V_47 = NULL ;
const T_13 * V_19 = L_1 ;
V_46 = NULL ;
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_48 , T_10 , V_49 ) ;
#line 12 "../../asn1/ros/ros-err.cnf"
T_7 -> V_2 -> V_3 . V_22 = 3 ;
if ( ( T_7 -> V_2 -> V_3 . V_8 == 0 ) && T_7 -> V_2 -> V_50 ) {
V_47 = F_20 ( T_7 -> V_2 -> V_50 , T_7 -> V_2 -> V_3 . V_4 ) ;
} else if ( ( T_7 -> V_2 -> V_3 . V_8 == 1 ) && T_7 -> V_2 -> V_51 ) {
V_47 = F_21 ( T_7 -> V_2 -> V_51 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_47 = NULL ;
}
if ( ! V_47 ||
! F_22 ( F_23 ( F_24 ( V_47 ) ) ) ) {
if ( T_7 -> V_2 -> V_3 . V_8 == 0 )
V_19 = F_25 ( L_10 , T_7 -> V_2 -> V_3 . V_4 ) ;
else if ( T_7 -> V_2 -> V_3 . V_8 == 1 )
V_19 = F_25 ( L_11 , T_7 -> V_2 -> V_3 . V_5 ) ;
} else {
V_19 = F_25 ( L_12 ) ;
}
if ( T_7 -> V_2 -> V_25 >= 0 )
F_26 ( F_27 ( F_28 ( T_9 ) , T_7 -> V_2 -> V_25 ) , L_5 , V_19 ) ;
if ( T_7 -> V_2 -> V_26 && F_29 ( T_7 -> V_27 -> V_28 , V_29 ) )
F_30 ( T_7 -> V_27 -> V_28 , V_29 , V_19 ) ;
if ( T_7 -> V_2 -> V_30 )
F_31 ( T_7 -> V_2 -> V_30 , V_19 , T_7 -> V_2 -> V_31 ) ;
if ( ! V_46 ) {
V_46 = F_17 ( T_4 , ( T_7 -> V_32 == V_33 ) ? T_5 >> 3 : T_5 , 0 , 0 ) ;
}
T_7 -> V_27 -> V_34 = T_7 -> V_2 ;
F_32 ( ( V_47 ) ? V_47 : V_35 , V_46 , T_7 -> V_27 , T_9 ) ;
if ( ! V_47 ) {
F_33 ( T_7 -> V_27 , T_9 , V_36 , V_37 , L_6 , V_19 ) ;
}
return T_5 ;
}
static int
F_39 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_52 ) ;
#line 54 "../../asn1/q932-ros/q932-ros.cnf"
F_40 ( V_53 , F_41 ( V_52 , F_42 ( V_54 ) , L_1 ) , 64 ) ;
return T_5 ;
}
static int
F_43 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_52 ) ;
#line 56 "../../asn1/q932-ros/q932-ros.cnf"
F_40 ( V_53 , F_41 ( V_52 , F_42 ( V_55 ) , L_1 ) , 64 ) ;
return T_5 ;
}
static int
F_44 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_52 ) ;
#line 58 "../../asn1/q932-ros/q932-ros.cnf"
F_40 ( V_53 , F_41 ( V_52 , F_42 ( V_56 ) , L_1 ) , 64 ) ;
return T_5 ;
}
static int
F_45 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_52 ) ;
#line 60 "../../asn1/q932-ros/q932-ros.cnf"
F_40 ( V_53 , F_41 ( V_52 , F_42 ( V_57 ) , L_1 ) , 64 ) ;
return T_5 ;
}
static int
F_46 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_7 , T_9 , T_4 , T_5 ,
V_58 , T_10 , V_59 ,
NULL ) ;
return T_5 ;
}
static int
F_47 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 7 "../../asn1/ros/ros-rej.cnf"
const T_13 * V_19 = L_1 ;
V_53 [ 0 ] = '\0' ;
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_60 , T_10 , V_61 ) ;
#line 11 "../../asn1/ros/ros-rej.cnf"
V_19 = F_25 ( L_13 , V_53 ) ;
if ( T_7 -> V_2 -> V_25 >= 0 )
F_26 ( F_27 ( F_28 ( T_9 ) , T_7 -> V_2 -> V_25 ) , L_5 , V_19 ) ;
if ( T_7 -> V_2 -> V_26 && F_29 ( T_7 -> V_27 -> V_28 , V_29 ) )
F_30 ( T_7 -> V_27 -> V_28 , V_29 , V_19 ) ;
if ( T_7 -> V_2 -> V_30 )
F_31 ( T_7 -> V_2 -> V_30 , V_19 , T_7 -> V_2 -> V_31 ) ;
return T_5 ;
}
static int
F_48 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 31 "../../asn1/q932-ros/q932-ros.cnf"
T_7 -> V_2 = V_62 ;
F_49 ( T_7 -> V_2 ) ;
T_5 = F_6 ( T_7 , T_9 , T_4 , T_5 ,
V_63 , T_10 , V_64 ,
NULL ) ;
return T_5 ;
}
static int F_50 ( T_3 * T_4 V_1 , T_14 * V_27 V_1 , T_8 * T_9 V_1 ) {
int T_5 = 0 ;
T_6 V_65 ;
F_51 ( & V_65 , V_66 , TRUE , V_27 ) ;
T_5 = F_48 ( FALSE , T_4 , T_5 , & V_65 , T_9 , V_67 ) ;
return T_5 ;
}
static int F_52 ( T_3 * T_4 , T_14 * V_27 , T_8 * T_9 ) {
V_62 = F_53 ( V_27 -> V_34 ) ;
F_54 ( V_62 ) ;
return F_50 ( T_4 , V_27 , T_9 ) ;
}
void F_55 ( void ) {
static T_15 V_68 [] = {
#line 1 "../../asn1/q932-ros/packet-q932-ros-hfarr.c"
{ & V_67 ,
{ L_14 , L_15 ,
V_69 , V_70 , F_42 ( V_71 ) , 0 ,
NULL , V_72 } } ,
{ & V_73 ,
{ L_16 , L_17 ,
V_74 , V_70 , NULL , 0 ,
NULL , V_72 } } ,
{ & V_75 ,
{ L_18 , L_19 ,
V_76 , V_77 , NULL , 0 ,
NULL , V_72 } } ,
{ & V_78 ,
{ L_20 , L_21 ,
V_79 , V_77 , NULL , 0 ,
NULL , V_72 } } ,
{ & V_80 ,
{ L_22 , L_23 ,
V_79 , V_77 , NULL , 0 ,
NULL , V_72 } } ,
{ & V_81 ,
{ L_24 , L_25 ,
V_79 , V_77 , NULL , 0 ,
NULL , V_72 } } ,
{ & V_82 ,
{ L_26 , L_27 ,
V_79 , V_77 , NULL , 0 ,
NULL , V_72 } } ,
{ & V_83 ,
{ L_28 , L_29 ,
V_69 , V_70 , F_42 ( V_84 ) , 0 ,
NULL , V_72 } } ,
{ & V_85 ,
{ L_30 , L_31 ,
V_69 , V_70 , F_42 ( V_86 ) , 0 ,
NULL , V_72 } } ,
{ & V_87 ,
{ L_32 , L_33 ,
V_74 , V_70 , NULL , 0 ,
L_34 , V_72 } } ,
{ & V_88 ,
{ L_35 , L_36 ,
V_79 , V_77 , NULL , 0 ,
NULL , V_72 } } ,
{ & V_89 ,
{ L_37 , L_38 ,
V_69 , V_70 , F_42 ( V_90 ) , 0 ,
L_39 , V_72 } } ,
{ & V_91 ,
{ L_40 , L_41 ,
V_92 , V_77 , NULL , 0 ,
L_42 , V_72 } } ,
{ & V_93 ,
{ L_43 , L_44 ,
V_79 , V_77 , NULL , 0 ,
NULL , V_72 } } ,
{ & V_94 ,
{ L_43 , L_44 ,
V_92 , V_77 , NULL , 0 ,
L_45 , V_72 } } ,
{ & V_95 ,
{ L_46 , L_47 ,
V_69 , V_70 , F_42 ( V_90 ) , 0 ,
L_39 , V_72 } } ,
{ & V_96 ,
{ L_48 , L_49 ,
V_92 , V_77 , NULL , 0 ,
NULL , V_72 } } ,
{ & V_97 ,
{ L_50 , L_51 ,
V_69 , V_70 , F_42 ( V_98 ) , 0 ,
NULL , V_72 } } ,
{ & V_99 ,
{ L_52 , L_53 ,
V_74 , V_70 , F_42 ( V_54 ) , 0 ,
L_54 , V_72 } } ,
{ & V_100 ,
{ L_20 , L_21 ,
V_74 , V_70 , F_42 ( V_55 ) , 0 ,
L_55 , V_72 } } ,
{ & V_101 ,
{ L_22 , L_23 ,
V_74 , V_70 , F_42 ( V_56 ) , 0 ,
L_56 , V_72 } } ,
{ & V_102 ,
{ L_24 , L_25 ,
V_74 , V_70 , F_42 ( V_57 ) , 0 ,
L_57 , V_72 } } ,
{ & V_103 ,
{ L_32 , L_33 ,
V_74 , V_70 , NULL , 0 ,
L_58 , V_72 } } ,
{ & V_104 ,
{ L_59 , L_60 ,
V_74 , V_70 , NULL , 0 ,
L_61 , V_72 } } ,
#line 76 "../../asn1/q932-ros/packet-q932-ros-template.c"
} ;
static T_11 * V_105 [] = {
#line 1 "../../asn1/q932-ros/packet-q932-ros-ettarr.c"
& V_7 ,
& V_64 ,
& V_21 ,
& V_14 ,
& V_43 ,
& V_40 ,
& V_49 ,
& V_61 ,
& V_59 ,
& V_12 ,
#line 81 "../../asn1/q932-ros/packet-q932-ros-template.c"
} ;
V_106 = F_56 ( V_107 , V_108 , V_109 ) ;
F_57 ( V_106 ) ;
F_58 ( V_106 , V_68 , F_59 ( V_68 ) ) ;
F_60 ( V_105 , F_59 ( V_105 ) ) ;
F_61 ( V_109 , F_52 , V_106 ) ;
}
void F_62 ( void ) {
V_35 = F_63 ( L_62 ) ;
}
