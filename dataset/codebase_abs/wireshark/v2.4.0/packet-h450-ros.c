static int
F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * T_5 V_2 , void * T_6 V_2 ) {
V_3 = V_1 ;
return F_2 ( V_1 ) ;
}
static int
F_3 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * T_5 V_2 , void * T_6 V_2 ) {
V_4 = V_1 ;
return F_2 ( V_1 ) ;
}
static int
F_4 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * T_5 V_2 , void * T_6 V_2 ) {
V_5 = V_1 ;
return F_2 ( V_1 ) ;
}
static int
F_5 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_6 ( V_1 , T_7 , T_9 , T_5 , T_10 , & T_9 -> V_6 -> V_7 . V_8 ) ;
return T_7 ;
}
static int
F_7 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_8 ( V_1 , T_7 , T_9 , T_5 , T_10 , & T_9 -> V_6 -> V_7 . V_9 ) ;
return T_7 ;
}
static int
F_9 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_10 ( V_1 , T_7 , T_9 , T_5 , T_10 ,
V_10 , V_11 ,
& T_9 -> V_6 -> V_7 . V_12 ) ;
#line 39 "./asn1/h450-ros/h450-ros.cnf"
T_9 -> V_6 -> V_7 . V_13 = T_9 -> V_14 ;
return T_7 ;
}
static int
F_11 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_6 ( V_1 , T_7 , T_9 , T_5 , T_10 , NULL ) ;
return T_7 ;
}
static int
F_12 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
#line 67 "./asn1/h450-ros/h450-ros.cnf"
T_7 = F_13 ( V_1 , T_7 , T_9 , T_5 , T_10 ,
0U , 65535U , NULL , TRUE ) ;
return T_7 ;
}
static int
F_14 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_15 ( V_1 , T_7 , T_9 , T_5 , T_10 , F_1 ) ;
return T_7 ;
}
static int
F_16 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
#line 6 "./asn1/ros/ros-inv.cnf"
T_11 V_15 = NULL ;
const T_12 * V_16 = L_1 ;
V_3 = NULL ;
T_7 = F_17 ( V_1 , T_7 , T_9 , T_5 , T_10 ,
V_17 , V_18 ) ;
#line 11 "./asn1/ros/ros-inv.cnf"
T_9 -> V_6 -> V_7 . V_19 = 1 ;
if ( ( T_9 -> V_6 -> V_7 . V_12 == 0 ) && T_9 -> V_6 -> V_20 ) {
V_15 = F_18 ( T_9 -> V_6 -> V_20 , T_9 -> V_6 -> V_7 . V_8 ) ;
} else if ( ( T_9 -> V_6 -> V_7 . V_12 == 1 ) && T_9 -> V_6 -> V_21 ) {
V_15 = F_19 ( T_9 -> V_6 -> V_21 , T_9 -> V_6 -> V_7 . V_9 ) ;
} else {
V_15 = NULL ;
}
if ( ! V_15 ||
! F_20 ( F_21 ( F_22 ( V_15 ) ) ) ) {
if ( T_9 -> V_6 -> V_7 . V_12 == 0 )
V_16 = F_23 ( F_24 () , L_2 , T_9 -> V_6 -> V_7 . V_8 ) ;
else if ( T_9 -> V_6 -> V_7 . V_12 == 1 )
V_16 = F_23 ( F_24 () , L_3 , T_9 -> V_6 -> V_7 . V_9 ) ;
} else {
V_16 = F_25 ( F_24 () , L_4 ) ;
}
if ( T_9 -> V_6 -> V_22 >= 0 )
F_26 ( F_27 ( F_28 ( T_5 ) , T_9 -> V_6 -> V_22 ) , L_5 , V_16 ) ;
if ( T_9 -> V_6 -> V_23 )
F_29 ( T_9 -> T_3 -> V_24 , V_25 , V_16 ) ;
if ( T_9 -> V_6 -> V_26 )
F_30 ( T_9 -> V_6 -> V_26 , V_16 , T_9 -> V_6 -> V_27 ) ;
if ( ! V_3 ) {
V_3 = F_31 ( V_1 , ( T_9 -> V_28 == V_29 ) ? T_7 >> 3 : T_7 , 0 , 0 ) ;
}
F_32 ( ( V_15 ) ? V_15 : V_30 , V_3 , T_9 -> T_3 , T_5 , T_9 -> V_6 ) ;
if ( ! V_15 ) {
F_33 ( T_9 -> T_3 , T_5 , & V_31 , L_6 , V_16 ) ;
}
return T_7 ;
}
static int
F_34 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_15 ( V_1 , T_7 , T_9 , T_5 , T_10 , F_3 ) ;
return T_7 ;
}
static int
F_35 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_17 ( V_1 , T_7 , T_9 , T_5 , T_10 ,
V_32 , V_33 ) ;
return T_7 ;
}
static int
F_36 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
#line 6 "./asn1/ros/ros-res.cnf"
T_11 V_34 = NULL ;
const T_12 * V_16 = L_1 ;
T_9 -> V_6 -> V_7 . V_12 = - 1 ;
V_4 = NULL ;
T_7 = F_17 ( V_1 , T_7 , T_9 , T_5 , T_10 ,
V_35 , V_36 ) ;
#line 12 "./asn1/ros/ros-res.cnf"
T_9 -> V_6 -> V_7 . V_19 = 2 ;
if ( ( T_9 -> V_6 -> V_7 . V_12 == 0 ) && T_9 -> V_6 -> V_37 ) {
V_34 = F_18 ( T_9 -> V_6 -> V_37 , T_9 -> V_6 -> V_7 . V_8 ) ;
} else if ( ( T_9 -> V_6 -> V_7 . V_12 == 1 ) && T_9 -> V_6 -> V_38 ) {
V_34 = F_19 ( T_9 -> V_6 -> V_38 , T_9 -> V_6 -> V_7 . V_9 ) ;
} else {
V_34 = NULL ;
}
if ( ! V_34 ||
! F_20 ( F_21 ( F_22 ( V_34 ) ) ) ) {
if ( T_9 -> V_6 -> V_7 . V_12 == 0 )
V_16 = F_23 ( F_24 () , L_7 , T_9 -> V_6 -> V_7 . V_8 ) ;
else if ( T_9 -> V_6 -> V_7 . V_12 == 1 )
V_16 = F_23 ( F_24 () , L_8 , T_9 -> V_6 -> V_7 . V_9 ) ;
} else {
V_16 = F_25 ( F_24 () , L_9 ) ;
}
if ( T_9 -> V_6 -> V_22 >= 0 )
F_26 ( F_27 ( F_28 ( T_5 ) , T_9 -> V_6 -> V_22 ) , L_5 , V_16 ) ;
if ( T_9 -> V_6 -> V_23 )
F_29 ( T_9 -> T_3 -> V_24 , V_25 , V_16 ) ;
if ( T_9 -> V_6 -> V_26 )
F_30 ( T_9 -> V_6 -> V_26 , V_16 , T_9 -> V_6 -> V_27 ) ;
if ( T_9 -> V_6 -> V_7 . V_12 != - 1 ) {
if ( ! V_4 ) {
V_4 = F_31 ( V_1 , ( T_9 -> V_28 == V_29 ) ? T_7 >> 3 : T_7 , 0 , 0 ) ;
}
F_32 ( ( V_34 ) ? V_34 : V_30 , V_4 , T_9 -> T_3 , T_5 , T_9 -> V_6 ) ;
if ( ! V_34 ) {
F_33 ( T_9 -> T_3 , T_5 , & V_31 , L_6 , V_16 ) ;
}
}
return T_7 ;
}
static int
F_37 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_15 ( V_1 , T_7 , T_9 , T_5 , T_10 , F_4 ) ;
return T_7 ;
}
static int
F_38 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
#line 6 "./asn1/ros/ros-err.cnf"
T_11 V_39 = NULL ;
const T_12 * V_16 = L_1 ;
V_5 = NULL ;
T_7 = F_17 ( V_1 , T_7 , T_9 , T_5 , T_10 ,
V_40 , V_41 ) ;
#line 11 "./asn1/ros/ros-err.cnf"
T_9 -> V_6 -> V_7 . V_19 = 3 ;
if ( ( T_9 -> V_6 -> V_7 . V_12 == 0 ) && T_9 -> V_6 -> V_42 ) {
V_39 = F_18 ( T_9 -> V_6 -> V_42 , T_9 -> V_6 -> V_7 . V_8 ) ;
} else if ( ( T_9 -> V_6 -> V_7 . V_12 == 1 ) && T_9 -> V_6 -> V_43 ) {
V_39 = F_19 ( T_9 -> V_6 -> V_43 , T_9 -> V_6 -> V_7 . V_9 ) ;
} else {
V_39 = NULL ;
}
if ( ! V_39 ||
! F_20 ( F_21 ( F_22 ( V_39 ) ) ) ) {
if ( T_9 -> V_6 -> V_7 . V_12 == 0 )
V_16 = F_23 ( F_24 () , L_10 , T_9 -> V_6 -> V_7 . V_8 ) ;
else if ( T_9 -> V_6 -> V_7 . V_12 == 1 )
V_16 = F_23 ( F_24 () , L_11 , T_9 -> V_6 -> V_7 . V_9 ) ;
} else {
V_16 = F_25 ( F_24 () , L_12 ) ;
}
if ( T_9 -> V_6 -> V_22 >= 0 )
F_26 ( F_27 ( F_28 ( T_5 ) , T_9 -> V_6 -> V_22 ) , L_5 , V_16 ) ;
if ( T_9 -> V_6 -> V_23 )
F_29 ( T_9 -> T_3 -> V_24 , V_25 , V_16 ) ;
if ( T_9 -> V_6 -> V_26 )
F_30 ( T_9 -> V_6 -> V_26 , V_16 , T_9 -> V_6 -> V_27 ) ;
if ( ! V_5 ) {
V_5 = F_31 ( V_1 , ( T_9 -> V_28 == V_29 ) ? T_7 >> 3 : T_7 , 0 , 0 ) ;
}
F_32 ( ( V_39 ) ? V_39 : V_30 , V_5 , T_9 -> T_3 , T_5 , T_9 -> V_6 ) ;
if ( ! V_39 ) {
F_33 ( T_9 -> T_3 , T_5 , & V_31 , L_6 , V_16 ) ;
}
return T_7 ;
}
static int
F_39 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_6 ( V_1 , T_7 , T_9 , T_5 , T_10 , & V_44 ) ;
#line 50 "./asn1/h450-ros/h450-ros.cnf"
F_40 ( V_45 , F_41 ( V_44 , F_42 ( V_46 ) , L_1 ) , 64 ) ;
V_45 [ 64 - 1 ] = '\0' ;
return T_7 ;
}
static int
F_43 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_6 ( V_1 , T_7 , T_9 , T_5 , T_10 , & V_44 ) ;
#line 53 "./asn1/h450-ros/h450-ros.cnf"
F_40 ( V_45 , F_41 ( V_44 , F_42 ( V_47 ) , L_1 ) , 64 ) ;
V_45 [ 64 - 1 ] = '\0' ;
return T_7 ;
}
static int
F_44 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_6 ( V_1 , T_7 , T_9 , T_5 , T_10 , & V_44 ) ;
#line 56 "./asn1/h450-ros/h450-ros.cnf"
F_40 ( V_45 , F_41 ( V_44 , F_42 ( V_48 ) , L_1 ) , 64 ) ;
V_45 [ 64 - 1 ] = '\0' ;
return T_7 ;
}
static int
F_45 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_6 ( V_1 , T_7 , T_9 , T_5 , T_10 , & V_44 ) ;
#line 59 "./asn1/h450-ros/h450-ros.cnf"
F_40 ( V_45 , F_41 ( V_44 , F_42 ( V_49 ) , L_1 ) , 64 ) ;
V_45 [ 64 - 1 ] = '\0' ;
return T_7 ;
}
static int
F_46 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
T_7 = F_10 ( V_1 , T_7 , T_9 , T_5 , T_10 ,
V_50 , V_51 ,
NULL ) ;
return T_7 ;
}
static int
F_47 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
#line 6 "./asn1/ros/ros-rej.cnf"
const T_12 * V_16 = L_1 ;
V_45 [ 0 ] = '\0' ;
T_7 = F_17 ( V_1 , T_7 , T_9 , T_5 , T_10 ,
V_52 , V_53 ) ;
#line 10 "./asn1/ros/ros-rej.cnf"
V_16 = F_23 ( F_24 () , L_13 , V_45 ) ;
if ( T_9 -> V_6 -> V_22 >= 0 )
F_26 ( F_27 ( F_28 ( T_5 ) , T_9 -> V_6 -> V_22 ) , L_5 , V_16 ) ;
if ( T_9 -> V_6 -> V_23 )
F_29 ( T_9 -> T_3 -> V_24 , V_25 , V_16 ) ;
if ( T_9 -> V_6 -> V_26 )
F_30 ( T_9 -> V_6 -> V_26 , V_16 , T_9 -> V_6 -> V_27 ) ;
return T_7 ;
}
int
F_48 ( T_1 * V_1 V_2 , int T_7 V_2 , T_8 * T_9 V_2 , T_4 * T_5 V_2 , int T_10 V_2 ) {
#line 28 "./asn1/h450-ros/h450-ros.cnf"
F_49 ( T_9 -> V_6 ) ;
F_50 ( T_9 -> V_6 ) ;
T_7 = F_10 ( V_1 , T_7 , T_9 , T_5 , T_10 ,
V_54 , V_55 ,
NULL ) ;
return T_7 ;
}
void F_51 ( void ) {
static T_13 V_56 [] = {
#line 1 "./asn1/h450-ros/packet-h450-ros-hfarr.c"
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
V_72 , V_59 , F_42 ( V_73 ) , 0 ,
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
V_72 , V_59 , F_42 ( V_73 ) , 0 ,
L_34 , V_60 } } ,
{ & V_80 ,
{ L_44 , L_45 ,
V_75 , V_63 , NULL , 0 ,
NULL , V_60 } } ,
{ & V_81 ,
{ L_46 , L_47 ,
V_72 , V_59 , F_42 ( V_82 ) , 0 ,
NULL , V_60 } } ,
{ & V_83 ,
{ L_48 , L_49 ,
V_58 , V_59 , F_42 ( V_46 ) , 0 ,
L_50 , V_60 } } ,
{ & V_84 ,
{ L_18 , L_51 ,
V_58 , V_59 , F_42 ( V_47 ) , 0 ,
L_52 , V_60 } } ,
{ & V_85 ,
{ L_20 , L_53 ,
V_58 , V_59 , F_42 ( V_48 ) , 0 ,
L_54 , V_60 } } ,
{ & V_86 ,
{ L_22 , L_55 ,
V_58 , V_59 , F_42 ( V_49 ) , 0 ,
L_56 , V_60 } } ,
#line 86 "./asn1/h450-ros/packet-h450-ros-template.c"
} ;
static T_14 * V_87 [] = {
#line 1 "./asn1/h450-ros/packet-h450-ros-ettarr.c"
& V_10 ,
& V_54 ,
& V_17 ,
& V_35 ,
& V_32 ,
& V_40 ,
& V_52 ,
& V_50 ,
#line 91 "./asn1/h450-ros/packet-h450-ros-template.c"
} ;
static T_15 V_88 [] = {
{ & V_31 , { L_57 , V_89 , V_90 , L_58 , V_91 } } ,
} ;
T_16 * V_92 ;
V_93 = F_52 ( V_94 , V_95 , V_96 ) ;
F_53 ( V_93 ) ;
F_54 ( V_93 , V_56 , F_55 ( V_56 ) ) ;
F_56 ( V_87 , F_55 ( V_87 ) ) ;
V_92 = F_57 ( V_93 ) ;
F_58 ( V_92 , V_88 , F_55 ( V_88 ) ) ;
}
void F_59 ( void ) {
V_30 = F_60 ( L_59 ) ;
}
