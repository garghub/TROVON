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
#line 40 "../../asn1/h450-ros/h450-ros.cnf"
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
#line 68 "../../asn1/h450-ros/h450-ros.cnf"
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
#line 8 "../../asn1/ros/ros-inv.cnf"
T_10 V_15 = NULL ;
const T_11 * V_16 = L_1 ;
V_3 = NULL ;
T_6 = F_16 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_17 , V_18 ) ;
#line 13 "../../asn1/ros/ros-inv.cnf"
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
V_16 = F_22 ( L_2 , T_8 -> V_6 -> V_7 . V_8 ) ;
else if ( T_8 -> V_6 -> V_7 . V_12 == 1 )
V_16 = F_22 ( L_3 , T_8 -> V_6 -> V_7 . V_9 ) ;
} else {
V_16 = F_22 ( L_4 ) ;
}
if ( T_8 -> V_6 -> V_22 >= 0 )
F_23 ( F_24 ( F_25 ( T_5 ) , T_8 -> V_6 -> V_22 ) , L_5 , V_16 ) ;
if ( T_8 -> V_6 -> V_23 && F_26 ( T_8 -> T_3 -> V_24 , V_25 ) )
F_27 ( T_8 -> T_3 -> V_24 , V_25 , V_16 ) ;
if ( T_8 -> V_6 -> V_26 )
F_28 ( T_8 -> V_6 -> V_26 , V_16 , T_8 -> V_6 -> V_27 ) ;
if ( ! V_3 ) {
V_3 = F_29 ( V_1 , ( T_8 -> V_28 == V_29 ) ? T_6 >> 3 : T_6 , 0 , 0 ) ;
}
T_8 -> T_3 -> V_30 = T_8 -> V_6 ;
F_30 ( ( V_15 ) ? V_15 : V_31 , V_3 , T_8 -> T_3 , T_5 ) ;
if ( ! V_15 ) {
F_31 ( T_8 -> T_3 , T_5 , V_32 , V_33 , L_6 , V_16 ) ;
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
V_34 , V_35 ) ;
return T_6 ;
}
static int
F_34 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
#line 7 "../../asn1/ros/ros-res.cnf"
T_10 V_36 = NULL ;
const T_11 * V_16 = L_1 ;
T_8 -> V_6 -> V_7 . V_12 = - 1 ;
V_4 = NULL ;
T_6 = F_16 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_37 , V_38 ) ;
#line 13 "../../asn1/ros/ros-res.cnf"
T_8 -> V_6 -> V_7 . V_19 = 2 ;
if ( ( T_8 -> V_6 -> V_7 . V_12 == 0 ) && T_8 -> V_6 -> V_39 ) {
V_36 = F_17 ( T_8 -> V_6 -> V_39 , T_8 -> V_6 -> V_7 . V_8 ) ;
} else if ( ( T_8 -> V_6 -> V_7 . V_12 == 1 ) && T_8 -> V_6 -> V_40 ) {
V_36 = F_18 ( T_8 -> V_6 -> V_40 , T_8 -> V_6 -> V_7 . V_9 ) ;
} else {
V_36 = NULL ;
}
if ( ! V_36 ||
! F_19 ( F_20 ( F_21 ( V_36 ) ) ) ) {
if ( T_8 -> V_6 -> V_7 . V_12 == 0 )
V_16 = F_22 ( L_7 , T_8 -> V_6 -> V_7 . V_8 ) ;
else if ( T_8 -> V_6 -> V_7 . V_12 == 1 )
V_16 = F_22 ( L_8 , T_8 -> V_6 -> V_7 . V_9 ) ;
} else {
V_16 = F_22 ( L_9 ) ;
}
if ( T_8 -> V_6 -> V_22 >= 0 )
F_23 ( F_24 ( F_25 ( T_5 ) , T_8 -> V_6 -> V_22 ) , L_5 , V_16 ) ;
if ( T_8 -> V_6 -> V_23 && F_26 ( T_8 -> T_3 -> V_24 , V_25 ) )
F_27 ( T_8 -> T_3 -> V_24 , V_25 , V_16 ) ;
if ( T_8 -> V_6 -> V_26 )
F_28 ( T_8 -> V_6 -> V_26 , V_16 , T_8 -> V_6 -> V_27 ) ;
if ( T_8 -> V_6 -> V_7 . V_12 != - 1 ) {
if ( ! V_4 ) {
V_4 = F_29 ( V_1 , ( T_8 -> V_28 == V_29 ) ? T_6 >> 3 : T_6 , 0 , 0 ) ;
}
T_8 -> T_3 -> V_30 = T_8 -> V_6 ;
F_30 ( ( V_36 ) ? V_36 : V_31 , V_4 , T_8 -> T_3 , T_5 ) ;
if ( ! V_36 ) {
F_31 ( T_8 -> T_3 , T_5 , V_32 , V_33 , L_6 , V_16 ) ;
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
#line 7 "../../asn1/ros/ros-err.cnf"
T_10 V_41 = NULL ;
const T_11 * V_16 = L_1 ;
V_5 = NULL ;
T_6 = F_16 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_42 , V_43 ) ;
#line 12 "../../asn1/ros/ros-err.cnf"
T_8 -> V_6 -> V_7 . V_19 = 3 ;
if ( ( T_8 -> V_6 -> V_7 . V_12 == 0 ) && T_8 -> V_6 -> V_44 ) {
V_41 = F_17 ( T_8 -> V_6 -> V_44 , T_8 -> V_6 -> V_7 . V_8 ) ;
} else if ( ( T_8 -> V_6 -> V_7 . V_12 == 1 ) && T_8 -> V_6 -> V_45 ) {
V_41 = F_18 ( T_8 -> V_6 -> V_45 , T_8 -> V_6 -> V_7 . V_9 ) ;
} else {
V_41 = NULL ;
}
if ( ! V_41 ||
! F_19 ( F_20 ( F_21 ( V_41 ) ) ) ) {
if ( T_8 -> V_6 -> V_7 . V_12 == 0 )
V_16 = F_22 ( L_10 , T_8 -> V_6 -> V_7 . V_8 ) ;
else if ( T_8 -> V_6 -> V_7 . V_12 == 1 )
V_16 = F_22 ( L_11 , T_8 -> V_6 -> V_7 . V_9 ) ;
} else {
V_16 = F_22 ( L_12 ) ;
}
if ( T_8 -> V_6 -> V_22 >= 0 )
F_23 ( F_24 ( F_25 ( T_5 ) , T_8 -> V_6 -> V_22 ) , L_5 , V_16 ) ;
if ( T_8 -> V_6 -> V_23 && F_26 ( T_8 -> T_3 -> V_24 , V_25 ) )
F_27 ( T_8 -> T_3 -> V_24 , V_25 , V_16 ) ;
if ( T_8 -> V_6 -> V_26 )
F_28 ( T_8 -> V_6 -> V_26 , V_16 , T_8 -> V_6 -> V_27 ) ;
if ( ! V_5 ) {
V_5 = F_29 ( V_1 , ( T_8 -> V_28 == V_29 ) ? T_6 >> 3 : T_6 , 0 , 0 ) ;
}
T_8 -> T_3 -> V_30 = T_8 -> V_6 ;
F_30 ( ( V_41 ) ? V_41 : V_31 , V_5 , T_8 -> T_3 , T_5 ) ;
if ( ! V_41 ) {
F_31 ( T_8 -> T_3 , T_5 , V_32 , V_33 , L_6 , V_16 ) ;
}
return T_6 ;
}
static int
F_37 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_5 ( V_1 , T_6 , T_8 , T_5 , T_9 , & V_46 ) ;
#line 51 "../../asn1/h450-ros/h450-ros.cnf"
F_38 ( V_47 , F_39 ( V_46 , F_40 ( V_48 ) , L_1 ) , 64 ) ;
V_47 [ 64 - 1 ] = '\0' ;
return T_6 ;
}
static int
F_41 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_5 ( V_1 , T_6 , T_8 , T_5 , T_9 , & V_46 ) ;
#line 54 "../../asn1/h450-ros/h450-ros.cnf"
F_38 ( V_47 , F_39 ( V_46 , F_40 ( V_49 ) , L_1 ) , 64 ) ;
V_47 [ 64 - 1 ] = '\0' ;
return T_6 ;
}
static int
F_42 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_5 ( V_1 , T_6 , T_8 , T_5 , T_9 , & V_46 ) ;
#line 57 "../../asn1/h450-ros/h450-ros.cnf"
F_38 ( V_47 , F_39 ( V_46 , F_40 ( V_50 ) , L_1 ) , 64 ) ;
V_47 [ 64 - 1 ] = '\0' ;
return T_6 ;
}
static int
F_43 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_5 ( V_1 , T_6 , T_8 , T_5 , T_9 , & V_46 ) ;
#line 60 "../../asn1/h450-ros/h450-ros.cnf"
F_38 ( V_47 , F_39 ( V_46 , F_40 ( V_51 ) , L_1 ) , 64 ) ;
V_47 [ 64 - 1 ] = '\0' ;
return T_6 ;
}
static int
F_44 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
T_6 = F_9 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_52 , V_53 ,
NULL ) ;
return T_6 ;
}
static int
F_45 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
#line 7 "../../asn1/ros/ros-rej.cnf"
const T_11 * V_16 = L_1 ;
V_47 [ 0 ] = '\0' ;
T_6 = F_16 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_54 , V_55 ) ;
#line 11 "../../asn1/ros/ros-rej.cnf"
V_16 = F_22 ( L_13 , V_47 ) ;
if ( T_8 -> V_6 -> V_22 >= 0 )
F_23 ( F_24 ( F_25 ( T_5 ) , T_8 -> V_6 -> V_22 ) , L_5 , V_16 ) ;
if ( T_8 -> V_6 -> V_23 && F_26 ( T_8 -> T_3 -> V_24 , V_25 ) )
F_27 ( T_8 -> T_3 -> V_24 , V_25 , V_16 ) ;
if ( T_8 -> V_6 -> V_26 )
F_28 ( T_8 -> V_6 -> V_26 , V_16 , T_8 -> V_6 -> V_27 ) ;
return T_6 ;
}
int
F_46 ( T_1 * V_1 V_2 , int T_6 V_2 , T_7 * T_8 V_2 , T_4 * T_5 V_2 , int T_9 V_2 ) {
#line 29 "../../asn1/h450-ros/h450-ros.cnf"
F_47 ( T_8 -> V_6 ) ;
F_48 ( T_8 -> V_6 ) ;
T_6 = F_9 ( V_1 , T_6 , T_8 , T_5 , T_9 ,
V_56 , V_57 ,
NULL ) ;
return T_6 ;
}
void F_49 ( void ) {
static T_12 V_58 [] = {
#line 1 "../../asn1/h450-ros/packet-h450-ros-hfarr.c"
{ & V_59 ,
{ L_14 , L_15 ,
V_60 , V_61 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_63 ,
{ L_16 , L_17 ,
V_64 , V_65 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_66 ,
{ L_18 , L_19 ,
V_67 , V_65 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_68 ,
{ L_20 , L_21 ,
V_67 , V_65 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_69 ,
{ L_22 , L_23 ,
V_67 , V_65 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_70 ,
{ L_24 , L_25 ,
V_67 , V_65 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_71 ,
{ L_26 , L_27 ,
V_60 , V_61 , NULL , 0 ,
L_28 , V_62 } } ,
{ & V_72 ,
{ L_29 , L_30 ,
V_60 , V_61 , NULL , 0 ,
L_31 , V_62 } } ,
{ & V_73 ,
{ L_32 , L_33 ,
V_74 , V_61 , F_40 ( V_75 ) , 0 ,
L_34 , V_62 } } ,
{ & V_76 ,
{ L_35 , L_36 ,
V_77 , V_65 , NULL , 0 ,
L_37 , V_62 } } ,
{ & V_78 ,
{ L_26 , L_27 ,
V_60 , V_61 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_79 ,
{ L_38 , L_39 ,
V_67 , V_65 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_80 ,
{ L_38 , L_39 ,
V_77 , V_65 , NULL , 0 ,
L_40 , V_62 } } ,
{ & V_81 ,
{ L_41 , L_42 ,
V_74 , V_61 , F_40 ( V_75 ) , 0 ,
L_34 , V_62 } } ,
{ & V_82 ,
{ L_43 , L_44 ,
V_77 , V_65 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_83 ,
{ L_45 , L_46 ,
V_74 , V_61 , F_40 ( V_84 ) , 0 ,
NULL , V_62 } } ,
{ & V_85 ,
{ L_47 , L_48 ,
V_60 , V_61 , F_40 ( V_48 ) , 0 ,
L_49 , V_62 } } ,
{ & V_86 ,
{ L_18 , L_19 ,
V_60 , V_61 , F_40 ( V_49 ) , 0 ,
L_50 , V_62 } } ,
{ & V_87 ,
{ L_20 , L_21 ,
V_60 , V_61 , F_40 ( V_50 ) , 0 ,
L_51 , V_62 } } ,
{ & V_88 ,
{ L_22 , L_23 ,
V_60 , V_61 , F_40 ( V_51 ) , 0 ,
L_52 , V_62 } } ,
#line 81 "../../asn1/h450-ros/packet-h450-ros-template.c"
} ;
static T_13 * V_89 [] = {
#line 1 "../../asn1/h450-ros/packet-h450-ros-ettarr.c"
& V_10 ,
& V_56 ,
& V_17 ,
& V_37 ,
& V_34 ,
& V_42 ,
& V_54 ,
& V_52 ,
#line 86 "../../asn1/h450-ros/packet-h450-ros-template.c"
} ;
V_90 = F_50 ( V_91 , V_92 , V_93 ) ;
F_51 ( V_90 ) ;
F_52 ( V_90 , V_58 , F_53 ( V_58 ) ) ;
F_54 ( V_89 , F_53 ( V_89 ) ) ;
}
void F_55 ( void ) {
V_31 = F_56 ( L_53 ) ;
}
