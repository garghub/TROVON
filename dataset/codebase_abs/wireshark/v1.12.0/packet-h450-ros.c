static void
F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * T_5 V_2 ) {
V_3 = V_1 ;
}
static void
F_2 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * T_5 V_2 ) {
V_4 = V_1 ;
}
static void
F_3 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * T_5 V_2 ) {
V_5 = V_1 ;
}
static int
F_4 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_5 ( V_1 , T_6 , T_8 , T_5 , T_9 , & T_8 -> V_6 -> V_7 . V_8 ) ;
return T_6 ;
}
static int
F_6 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_7 ( V_1 , T_6 , T_8 , T_5 , T_9 , & T_8 -> V_6 -> V_7 . V_9 ) ;
return T_6 ;
}
static int
F_8 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_9 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_10 , V_11 ,
& T_8 -> V_6 -> V_7 . V_12 ) ;
#line 39 "../../asn1/h450-ros/h450-ros.cnf"
T_8 -> V_6 -> V_7 . V_13 = T_8 -> V_14 ;
return T_6 ;
}
static int
F_10 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_5 ( V_1 , T_6 , T_8 , T_5 , T_9 , NULL ) ;
return T_6 ;
}
static int
F_11 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
#line 67 "../../asn1/h450-ros/h450-ros.cnf"
T_6 = F_12 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
0U , 65535U , NULL , TRUE ) ;
return T_6 ;
}
static int
F_13 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_14 ( V_1 , T_6 , T_8 , T_5 , T_9 , F_1 ) ;
return T_6 ;
}
static int
F_15 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
#line 6 "../../asn1/ros/ros-inv.cnf"
T_10 V_15 = NULL ;
const T_11 * V_16 = L_1 ;
V_3 = NULL ;
T_6 = F_16 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_17 , V_18 ) ;
#line 11 "../../asn1/ros/ros-inv.cnf"
T_8 -> V_6 -> V_7 . V_19 = 1 ;
if ( ( T_8 -> V_6 -> V_7 . V_12 == 0 ) && T_8 -> V_6 -> V_20 ) {
V_15 = F_17 ( T_8 -> V_6 -> V_20 , T_8 -> V_6 -> V_7 . V_8 ) ;
} else if ( ( T_8 -> V_6 -> V_7 . V_12 == 1 ) && T_8 -> V_6 -> V_21 ) {
V_15 = F_18 ( T_8 -> V_6 -> V_21 , T_8 -> V_6 -> V_7 . V_9 ) ;
} else {
V_15 = NULL ;
}
if ( ! V_15 ||
! F_19 ( F_20 ( F_21 ( V_15 ) ) ) ) {
if ( T_8 -> V_6 -> V_7 . V_12 == 0 )
V_16 = F_22 ( F_23 () , L_2 , T_8 -> V_6 -> V_7 . V_8 ) ;
else if ( T_8 -> V_6 -> V_7 . V_12 == 1 )
V_16 = F_22 ( F_23 () , L_3 , T_8 -> V_6 -> V_7 . V_9 ) ;
} else {
V_16 = F_22 ( F_23 () , L_4 ) ;
}
if ( T_8 -> V_6 -> V_22 >= 0 )
F_24 ( F_25 ( F_26 ( T_5 ) , T_8 -> V_6 -> V_22 ) , L_5 , V_16 ) ;
if ( T_8 -> V_6 -> V_23 )
F_27 ( T_8 -> T_3 -> V_24 , V_25 , V_16 ) ;
if ( T_8 -> V_6 -> V_26 )
F_28 ( T_8 -> V_6 -> V_26 , V_16 , T_8 -> V_6 -> V_27 ) ;
if ( ! V_3 ) {
V_3 = F_29 ( V_1 , ( T_8 -> V_28 == V_29 ) ? T_6 >> 3 : T_6 , 0 , 0 ) ;
}
F_30 ( ( V_15 ) ? V_15 : V_30 , V_3 , T_8 -> T_3 , T_5 , T_8 -> V_6 ) ;
if ( ! V_15 ) {
F_31 ( T_8 -> T_3 , T_5 , & V_31 , L_6 , V_16 ) ;
}
return T_6 ;
}
static int
F_32 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_14 ( V_1 , T_6 , T_8 , T_5 , T_9 , F_2 ) ;
return T_6 ;
}
static int
F_33 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_16 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_32 , V_33 ) ;
return T_6 ;
}
static int
F_34 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
#line 6 "../../asn1/ros/ros-res.cnf"
T_10 V_34 = NULL ;
const T_11 * V_16 = L_1 ;
T_8 -> V_6 -> V_7 . V_12 = - 1 ;
V_4 = NULL ;
T_6 = F_16 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_35 , V_36 ) ;
#line 12 "../../asn1/ros/ros-res.cnf"
T_8 -> V_6 -> V_7 . V_19 = 2 ;
if ( ( T_8 -> V_6 -> V_7 . V_12 == 0 ) && T_8 -> V_6 -> V_37 ) {
V_34 = F_17 ( T_8 -> V_6 -> V_37 , T_8 -> V_6 -> V_7 . V_8 ) ;
} else if ( ( T_8 -> V_6 -> V_7 . V_12 == 1 ) && T_8 -> V_6 -> V_38 ) {
V_34 = F_18 ( T_8 -> V_6 -> V_38 , T_8 -> V_6 -> V_7 . V_9 ) ;
} else {
V_34 = NULL ;
}
if ( ! V_34 ||
! F_19 ( F_20 ( F_21 ( V_34 ) ) ) ) {
if ( T_8 -> V_6 -> V_7 . V_12 == 0 )
V_16 = F_22 ( F_23 () , L_7 , T_8 -> V_6 -> V_7 . V_8 ) ;
else if ( T_8 -> V_6 -> V_7 . V_12 == 1 )
V_16 = F_22 ( F_23 () , L_8 , T_8 -> V_6 -> V_7 . V_9 ) ;
} else {
V_16 = F_22 ( F_23 () , L_9 ) ;
}
if ( T_8 -> V_6 -> V_22 >= 0 )
F_24 ( F_25 ( F_26 ( T_5 ) , T_8 -> V_6 -> V_22 ) , L_5 , V_16 ) ;
if ( T_8 -> V_6 -> V_23 )
F_27 ( T_8 -> T_3 -> V_24 , V_25 , V_16 ) ;
if ( T_8 -> V_6 -> V_26 )
F_28 ( T_8 -> V_6 -> V_26 , V_16 , T_8 -> V_6 -> V_27 ) ;
if ( T_8 -> V_6 -> V_7 . V_12 != - 1 ) {
if ( ! V_4 ) {
V_4 = F_29 ( V_1 , ( T_8 -> V_28 == V_29 ) ? T_6 >> 3 : T_6 , 0 , 0 ) ;
}
F_30 ( ( V_34 ) ? V_34 : V_30 , V_4 , T_8 -> T_3 , T_5 , T_8 -> V_6 ) ;
if ( ! V_34 ) {
F_31 ( T_8 -> T_3 , T_5 , & V_31 , L_6 , V_16 ) ;
}
}
return T_6 ;
}
static int
F_35 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_14 ( V_1 , T_6 , T_8 , T_5 , T_9 , F_3 ) ;
return T_6 ;
}
static int
F_36 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
#line 6 "../../asn1/ros/ros-err.cnf"
T_10 V_39 = NULL ;
const T_11 * V_16 = L_1 ;
V_5 = NULL ;
T_6 = F_16 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_40 , V_41 ) ;
#line 11 "../../asn1/ros/ros-err.cnf"
T_8 -> V_6 -> V_7 . V_19 = 3 ;
if ( ( T_8 -> V_6 -> V_7 . V_12 == 0 ) && T_8 -> V_6 -> V_42 ) {
V_39 = F_17 ( T_8 -> V_6 -> V_42 , T_8 -> V_6 -> V_7 . V_8 ) ;
} else if ( ( T_8 -> V_6 -> V_7 . V_12 == 1 ) && T_8 -> V_6 -> V_43 ) {
V_39 = F_18 ( T_8 -> V_6 -> V_43 , T_8 -> V_6 -> V_7 . V_9 ) ;
} else {
V_39 = NULL ;
}
if ( ! V_39 ||
! F_19 ( F_20 ( F_21 ( V_39 ) ) ) ) {
if ( T_8 -> V_6 -> V_7 . V_12 == 0 )
V_16 = F_22 ( F_23 () , L_10 , T_8 -> V_6 -> V_7 . V_8 ) ;
else if ( T_8 -> V_6 -> V_7 . V_12 == 1 )
V_16 = F_22 ( F_23 () , L_11 , T_8 -> V_6 -> V_7 . V_9 ) ;
} else {
V_16 = F_22 ( F_23 () , L_12 ) ;
}
if ( T_8 -> V_6 -> V_22 >= 0 )
F_24 ( F_25 ( F_26 ( T_5 ) , T_8 -> V_6 -> V_22 ) , L_5 , V_16 ) ;
if ( T_8 -> V_6 -> V_23 )
F_27 ( T_8 -> T_3 -> V_24 , V_25 , V_16 ) ;
if ( T_8 -> V_6 -> V_26 )
F_28 ( T_8 -> V_6 -> V_26 , V_16 , T_8 -> V_6 -> V_27 ) ;
if ( ! V_5 ) {
V_5 = F_29 ( V_1 , ( T_8 -> V_28 == V_29 ) ? T_6 >> 3 : T_6 , 0 , 0 ) ;
}
F_30 ( ( V_39 ) ? V_39 : V_30 , V_5 , T_8 -> T_3 , T_5 , T_8 -> V_6 ) ;
if ( ! V_39 ) {
F_31 ( T_8 -> T_3 , T_5 , & V_31 , L_6 , V_16 ) ;
}
return T_6 ;
}
static int
F_37 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_5 ( V_1 , T_6 , T_8 , T_5 , T_9 , & V_44 ) ;
#line 50 "../../asn1/h450-ros/h450-ros.cnf"
F_38 ( V_45 , F_39 ( V_44 , F_40 ( V_46 ) , L_1 ) , 64 ) ;
V_45 [ 64 - 1 ] = '\0' ;
return T_6 ;
}
static int
F_41 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_5 ( V_1 , T_6 , T_8 , T_5 , T_9 , & V_44 ) ;
#line 53 "../../asn1/h450-ros/h450-ros.cnf"
F_38 ( V_45 , F_39 ( V_44 , F_40 ( V_47 ) , L_1 ) , 64 ) ;
V_45 [ 64 - 1 ] = '\0' ;
return T_6 ;
}
static int
F_42 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_5 ( V_1 , T_6 , T_8 , T_5 , T_9 , & V_44 ) ;
#line 56 "../../asn1/h450-ros/h450-ros.cnf"
F_38 ( V_45 , F_39 ( V_44 , F_40 ( V_48 ) , L_1 ) , 64 ) ;
V_45 [ 64 - 1 ] = '\0' ;
return T_6 ;
}
static int
F_43 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_5 ( V_1 , T_6 , T_8 , T_5 , T_9 , & V_44 ) ;
#line 59 "../../asn1/h450-ros/h450-ros.cnf"
F_38 ( V_45 , F_39 ( V_44 , F_40 ( V_49 ) , L_1 ) , 64 ) ;
V_45 [ 64 - 1 ] = '\0' ;
return T_6 ;
}
static int
F_44 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_9 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_50 , V_51 ,
NULL ) ;
return T_6 ;
}
static int
F_45 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
#line 6 "../../asn1/ros/ros-rej.cnf"
const T_11 * V_16 = L_1 ;
V_45 [ 0 ] = '\0' ;
T_6 = F_16 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_52 , V_53 ) ;
#line 10 "../../asn1/ros/ros-rej.cnf"
V_16 = F_22 ( F_23 () , L_13 , V_45 ) ;
if ( T_8 -> V_6 -> V_22 >= 0 )
F_24 ( F_25 ( F_26 ( T_5 ) , T_8 -> V_6 -> V_22 ) , L_5 , V_16 ) ;
if ( T_8 -> V_6 -> V_23 )
F_27 ( T_8 -> T_3 -> V_24 , V_25 , V_16 ) ;
if ( T_8 -> V_6 -> V_26 )
F_28 ( T_8 -> V_6 -> V_26 , V_16 , T_8 -> V_6 -> V_27 ) ;
return T_6 ;
}
int
F_46 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
#line 28 "../../asn1/h450-ros/h450-ros.cnf"
F_47 ( T_8 -> V_6 ) ;
F_48 ( T_8 -> V_6 ) ;
T_6 = F_9 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_54 , V_55 ,
NULL ) ;
return T_6 ;
}
void F_49 ( void ) {
static T_12 V_56 [] = {
#line 1 "../../asn1/h450-ros/packet-h450-ros-hfarr.c"
{ & V_57 ,
{ L_14 , L_15 ,
V_58 , V_59 , NULL , 0 ,
NULL , V_60 } } ,
{ & V_61 ,
{ L_16 , L_17 ,
V_62 , V_63 , NULL , 0 ,
NULL , V_60 } } ,
{ & V_64 ,
{ L_18 , L_19 ,
V_65 , V_63 , NULL , 0 ,
NULL , V_60 } } ,
{ & V_66 ,
{ L_20 , L_21 ,
V_65 , V_63 , NULL , 0 ,
NULL , V_60 } } ,
{ & V_67 ,
{ L_22 , L_23 ,
V_65 , V_63 , NULL , 0 ,
NULL , V_60 } } ,
{ & V_68 ,
{ L_24 , L_25 ,
V_65 , V_63 , NULL , 0 ,
NULL , V_60 } } ,
{ & V_69 ,
{ L_26 , L_27 ,
V_58 , V_59 , NULL , 0 ,
L_28 , V_60 } } ,
{ & V_70 ,
{ L_29 , L_30 ,
V_58 , V_59 , NULL , 0 ,
L_31 , V_60 } } ,
{ & V_71 ,
{ L_32 , L_33 ,
V_72 , V_59 , F_40 ( V_73 ) , 0 ,
L_34 , V_60 } } ,
{ & V_74 ,
{ L_35 , L_36 ,
V_75 , V_63 , NULL , 0 ,
L_37 , V_60 } } ,
{ & V_76 ,
{ L_26 , L_27 ,
V_58 , V_59 , NULL , 0 ,
NULL , V_60 } } ,
{ & V_77 ,
{ L_38 , L_39 ,
V_65 , V_63 , NULL , 0 ,
NULL , V_60 } } ,
{ & V_78 ,
{ L_38 , L_40 ,
V_75 , V_63 , NULL , 0 ,
L_41 , V_60 } } ,
{ & V_79 ,
{ L_42 , L_43 ,
V_72 , V_59 , F_40 ( V_73 ) , 0 ,
L_34 , V_60 } } ,
{ & V_80 ,
{ L_44 , L_45 ,
V_75 , V_63 , NULL , 0 ,
NULL , V_60 } } ,
{ & V_81 ,
{ L_46 , L_47 ,
V_72 , V_59 , F_40 ( V_82 ) , 0 ,
NULL , V_60 } } ,
{ & V_83 ,
{ L_48 , L_49 ,
V_58 , V_59 , F_40 ( V_46 ) , 0 ,
L_50 , V_60 } } ,
{ & V_84 ,
{ L_18 , L_51 ,
V_58 , V_59 , F_40 ( V_47 ) , 0 ,
L_52 , V_60 } } ,
{ & V_85 ,
{ L_20 , L_53 ,
V_58 , V_59 , F_40 ( V_48 ) , 0 ,
L_54 , V_60 } } ,
{ & V_86 ,
{ L_22 , L_55 ,
V_58 , V_59 , F_40 ( V_49 ) , 0 ,
L_56 , V_60 } } ,
#line 84 "../../asn1/h450-ros/packet-h450-ros-template.c"
} ;
static T_13 * V_87 [] = {
#line 1 "../../asn1/h450-ros/packet-h450-ros-ettarr.c"
& V_10 ,
& V_54 ,
& V_17 ,
& V_35 ,
& V_32 ,
& V_40 ,
& V_52 ,
& V_50 ,
#line 89 "../../asn1/h450-ros/packet-h450-ros-template.c"
} ;
static T_14 V_88 [] = {
{ & V_31 , { L_57 , V_89 , V_90 , L_58 , V_91 } } ,
} ;
T_15 * V_92 ;
V_93 = F_50 ( V_94 , V_95 , V_96 ) ;
F_51 ( V_93 ) ;
F_52 ( V_93 , V_56 , F_53 ( V_56 ) ) ;
F_54 ( V_87 , F_53 ( V_87 ) ) ;
V_92 = F_55 ( V_93 ) ;
F_56 ( V_92 , V_88 , F_53 ( V_88 ) ) ;
}
void F_57 ( void ) {
V_30 = F_58 ( L_59 ) ;
}
