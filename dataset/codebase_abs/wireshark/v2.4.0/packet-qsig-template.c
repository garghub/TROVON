static const T_1 * F_1 ( T_2 V_1 ) {
int V_2 ;
for ( V_2 = F_2 ( V_3 ) - 1 ; V_2 >= 0 ; V_2 -- )
if ( V_3 [ V_2 ] . V_1 == V_1 )
return & V_3 [ V_2 ] ;
return NULL ;
}
static T_2 F_3 ( T_2 V_1 ) {
if ( ( V_1 < 0 ) || ( V_1 >= ( int ) F_2 ( V_4 ) ) )
return V_5 ;
return V_4 [ V_1 ] ;
}
static const T_3 * F_4 ( T_2 V_6 ) {
int V_2 ;
for ( V_2 = F_2 ( V_7 ) - 1 ; V_2 >= 0 ; V_2 -- )
if ( V_7 [ V_2 ] . V_6 == V_6 )
return & V_7 [ V_2 ] ;
return NULL ;
}
static int
F_5 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , void * V_11 ) {
int V_12 = 0 ;
T_7 * V_13 ;
T_2 V_1 = 0 , V_14 , V_15 ;
const T_1 * V_16 = NULL ;
const T_8 * V_17 , * V_18 ;
T_9 * V_19 , * V_20 ;
T_6 * V_21 ;
if ( V_11 == NULL )
return 0 ;
V_13 = F_6 ( V_11 ) ;
F_7 ( V_13 ) ;
if ( V_13 -> V_22 . V_23 != 1 )
return V_12 ;
if ( V_13 -> V_22 . V_24 == 0 ) {
V_1 = V_13 -> V_22 . V_25 ;
V_16 = F_1 ( V_1 ) ;
} else if ( V_13 -> V_22 . V_24 == 1 ) {
V_18 = F_8 ( V_13 -> V_22 . V_26 , L_1 ) ;
if ( V_18 != NULL ) {
if ( F_9 ( V_18 + 1 , NULL , & V_15 ) )
V_16 = F_1 ( V_15 ) ;
}
if ( V_16 )
V_1 = V_16 -> V_1 ;
} else {
return V_12 ;
}
if ( ! V_16 )
return V_12 ;
V_14 = F_3 ( V_1 ) ;
V_19 = F_10 ( V_10 , V_27 , V_8 , V_12 , F_11 ( V_8 ) , V_28 ) ;
V_21 = F_12 ( V_19 , V_29 ) ;
F_13 ( V_21 , V_30 , V_8 , 0 , 0 , V_1 ) ;
V_17 = F_14 ( V_1 , F_15 ( V_31 ) ) ;
if ( V_17 ) {
F_16 ( V_19 , L_2 , V_17 ) ;
F_16 ( V_13 -> V_22 . V_32 , L_3 , V_17 ) ;
if ( V_13 -> V_33 >= 0 )
F_16 ( F_17 ( F_18 ( V_10 ) , V_13 -> V_33 ) , L_4 , V_17 ) ;
}
V_20 = F_13 ( V_21 , V_34 , V_8 , 0 , 0 , V_14 ) ;
V_17 = F_14 ( V_14 , F_15 ( V_35 ) ) ;
if ( V_17 ) F_16 ( V_20 , L_3 , V_17 ) ;
if ( V_16 -> V_36 )
V_12 = V_16 -> V_36 ( V_8 , V_9 , V_21 , NULL ) ;
else
if ( F_19 ( V_8 , V_12 ) > 0 ) {
F_20 ( V_10 , V_9 , & V_37 , V_8 , V_12 , - 1 ) ;
V_12 += F_21 ( V_8 , V_12 ) ;
}
return V_12 ;
}
static int
F_22 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , void * V_11 ) {
T_10 V_12 = 0 ;
T_7 * V_13 ;
T_2 V_1 , V_14 ;
const T_1 * V_16 ;
const T_8 * V_17 ;
T_9 * V_19 , * V_20 ;
T_6 * V_21 ;
if ( V_11 == NULL )
return 0 ;
V_13 = F_6 ( V_11 ) ;
F_7 ( V_13 ) ;
if ( V_13 -> V_22 . V_23 != 2 )
return V_12 ;
if ( V_13 -> V_22 . V_24 != 0 )
return V_12 ;
V_1 = V_13 -> V_22 . V_25 ;
V_16 = F_1 ( V_1 ) ;
if ( ! V_16 )
return V_12 ;
V_14 = F_3 ( V_1 ) ;
V_19 = F_10 ( V_10 , V_27 , V_8 , V_12 , F_11 ( V_8 ) , V_28 ) ;
V_21 = F_12 ( V_19 , V_29 ) ;
F_13 ( V_21 , V_30 , V_8 , 0 , 0 , V_1 ) ;
V_17 = F_14 ( V_1 , F_15 ( V_31 ) ) ;
if ( V_17 ) {
F_16 ( V_19 , L_2 , V_17 ) ;
F_16 ( V_13 -> V_22 . V_32 , L_3 , V_17 ) ;
if ( V_13 -> V_33 >= 0 )
F_16 ( F_17 ( F_18 ( V_10 ) , V_13 -> V_33 ) , L_4 , V_17 ) ;
}
V_20 = F_13 ( V_21 , V_34 , V_8 , 0 , 0 , V_14 ) ;
V_17 = F_14 ( V_14 , F_15 ( V_35 ) ) ;
if ( V_17 ) F_16 ( V_20 , L_3 , V_17 ) ;
if ( V_16 -> V_38 )
V_12 = V_16 -> V_38 ( V_8 , V_9 , V_21 , NULL ) ;
else
if ( F_19 ( V_8 , V_12 ) > 0 ) {
F_20 ( V_10 , V_9 , & V_39 , V_8 , V_12 , - 1 ) ;
V_12 += F_21 ( V_8 , V_12 ) ;
}
return V_12 ;
}
static int
F_23 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , void * V_11 ) {
int V_12 = 0 ;
T_7 * V_13 ;
T_2 V_6 ;
const T_3 * V_40 ;
const T_8 * V_17 ;
T_9 * V_19 ;
T_6 * V_21 ;
if ( V_11 == NULL )
return 0 ;
V_13 = F_6 ( V_11 ) ;
F_7 ( V_13 ) ;
if ( V_13 -> V_22 . V_23 != 3 )
return V_12 ;
if ( V_13 -> V_22 . V_24 != 0 )
return V_12 ;
V_6 = V_13 -> V_22 . V_25 ;
V_40 = F_4 ( V_6 ) ;
if ( ! V_40 )
return V_12 ;
V_19 = F_10 ( V_10 , V_27 , V_8 , V_12 , F_11 ( V_8 ) , V_28 ) ;
V_21 = F_12 ( V_19 , V_29 ) ;
F_13 ( V_21 , V_41 , V_8 , 0 , 0 , V_6 ) ;
V_17 = F_14 ( V_6 , F_15 ( V_42 ) ) ;
if ( V_17 ) {
F_16 ( V_19 , L_2 , V_17 ) ;
F_16 ( V_13 -> V_22 . V_32 , L_3 , V_17 ) ;
if ( V_13 -> V_33 >= 0 )
F_16 ( F_17 ( F_18 ( V_10 ) , V_13 -> V_33 ) , L_4 , V_17 ) ;
}
if ( V_40 -> V_43 )
V_12 = V_40 -> V_43 ( V_8 , V_9 , V_21 , NULL ) ;
else
if ( F_19 ( V_8 , V_12 ) > 0 ) {
F_20 ( V_10 , V_9 , & V_37 , V_8 , V_12 , - 1 ) ;
V_12 += F_21 ( V_8 , V_12 ) ;
}
return V_12 ;
}
static int
F_24 ( T_4 * V_8 , int V_12 , T_5 * V_9 V_44 , T_6 * V_10 , int T_11 V_44 ) {
F_10 ( V_10 , V_45 , V_8 , V_12 , 1 , V_46 ) ;
V_12 ++ ;
return V_12 ;
}
static int
F_25 ( T_4 * V_8 , int V_12 , T_5 * V_9 V_44 , T_6 * V_10 , int T_11 V_44 ) {
F_10 ( V_10 , V_47 , V_8 , V_12 , 1 , V_46 ) ;
V_12 ++ ;
return V_12 ;
}
static void
F_26 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , int V_48 ) {
T_10 V_12 ;
T_9 * V_19 , * V_49 ;
T_6 * V_50 ;
T_12 V_51 , V_52 ;
V_12 = 0 ;
V_19 = F_10 ( V_10 , V_27 , V_8 , V_12 , - 1 , V_28 ) ;
F_27 ( V_19 ) ;
V_51 = F_28 ( V_8 , V_12 ) ;
V_52 = F_28 ( V_8 , V_12 + 1 ) ;
V_50 = F_29 ( V_10 , V_8 , V_12 , - 1 , V_53 , NULL ,
F_30 ( V_51 , F_15 ( V_54 [ V_48 ] ) , L_5 ) ) ;
F_10 ( V_50 , * V_55 [ V_48 ] , V_8 , V_12 , 1 , V_46 ) ;
V_49 = F_10 ( V_50 , V_56 , V_8 , V_12 , 1 , V_46 ) ;
F_27 ( V_49 ) ;
F_10 ( V_50 , V_57 , V_8 , V_12 + 1 , 1 , V_46 ) ;
V_12 += 2 ;
if ( F_19 ( V_8 , V_12 ) <= 0 )
return;
switch ( ( V_48 << 8 ) | V_51 ) {
case V_58 | V_59 :
F_24 ( V_8 , V_12 , V_9 , V_50 , V_52 ) ;
break;
case V_60 | V_61 :
F_25 ( V_8 , V_12 , V_9 , V_50 , V_52 ) ;
break;
default:
if ( V_52 > 0 ) {
if ( V_10 ) F_10 ( V_50 , V_62 , V_8 , V_12 , V_52 , V_28 ) ;
}
}
}
static int
F_31 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , void * V_11 V_44 ) {
F_26 ( V_8 , V_9 , V_10 , 4 ) ;
return F_11 ( V_8 ) ;
}
static int
F_32 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , void * V_11 V_44 ) {
F_26 ( V_8 , V_9 , V_10 , 5 ) ;
return F_11 ( V_8 ) ;
}
void F_33 ( void ) {
static T_13 V_63 [] = {
{ & V_30 , { L_6 , L_7 ,
V_64 , V_65 , F_15 ( V_31 ) , 0x0 ,
NULL , V_66 } } ,
{ & V_34 , { L_8 , L_9 ,
V_64 , V_65 , F_15 ( V_67 ) , 0x0 ,
L_10 , V_66 } } ,
{ & V_41 , { L_11 , L_12 ,
V_64 , V_65 , F_15 ( V_42 ) , 0x0 ,
NULL , V_66 } } ,
{ & V_56 , { L_13 , L_14 ,
V_64 , V_68 , NULL , 0x0 ,
L_15 , V_66 } } ,
{ & V_69 , { L_13 , L_16 ,
V_64 , V_68 , F_15 ( V_70 ) , 0x0 ,
L_17 , V_66 } } ,
{ & V_71 , { L_13 , L_18 ,
V_64 , V_68 , F_15 ( V_72 ) , 0x0 ,
L_19 , V_66 } } ,
{ & V_57 , { L_20 , L_21 ,
V_64 , V_65 , NULL , 0x0 ,
L_22 , V_66 } } ,
{ & V_62 , { L_23 , L_24 ,
V_73 , V_74 , NULL , 0x0 ,
NULL , V_66 } } ,
{ & V_45 , { L_25 , L_26 ,
V_64 , V_65 , NULL , 0x1F ,
NULL , V_66 } } ,
{ & V_47 , { L_27 , L_28 ,
V_64 , V_68 , F_15 ( V_75 ) , 0x07 ,
NULL , V_66 } } ,
#include "packet-qsig-hfarr.c"
} ;
static T_10 * V_76 [] = {
& V_29 ,
& V_53 ,
& V_77 ,
#include "packet-qsig-ettarr.c"
& V_78 ,
} ;
static T_14 V_79 [] = {
#if 0
{ &ei_qsig_unsupported_arg_type, { "qsig.unsupported.arg_type", PI_UNDECODED, PI_WARN, "UNSUPPORTED ARGUMENT TYPE (QSIG)", EXPFILL }},
#endif
{ & V_39 , { L_29 , V_80 , V_81 , L_30 , V_82 } } ,
{ & V_37 , { L_31 , V_80 , V_81 , L_32 , V_82 } } ,
} ;
T_15 * V_83 ;
V_27 = F_34 ( V_84 , V_85 , V_86 ) ;
F_35 ( V_27 , V_63 , F_2 ( V_63 ) ) ;
F_36 ( V_76 , F_2 ( V_76 ) ) ;
V_83 = F_37 ( V_27 ) ;
F_38 ( V_83 , V_79 , F_2 ( V_79 ) ) ;
V_87 = F_39 ( L_33 , L_34 , V_27 , V_88 , V_74 ) ;
}
void F_40 ( void ) {
int V_2 ;
T_8 * V_18 ;
T_16 V_89 ;
T_16 V_90 ;
T_16 V_91 ;
T_16 V_92 ;
T_16 V_93 ;
V_89 = F_41 ( L_35 , V_27 ) ;
V_94 = F_41 ( L_36 , V_27 ) ;
V_90 = F_42 ( F_5 , V_27 ) ;
V_91 = F_42 ( F_22 , V_27 ) ;
for ( V_2 = 0 ; V_2 < ( int ) F_2 ( V_3 ) ; V_2 ++ ) {
F_43 ( L_37 , V_3 [ V_2 ] . V_1 , V_90 ) ;
F_43 ( L_38 , V_3 [ V_2 ] . V_1 , V_91 ) ;
V_18 = F_44 ( NULL , L_39 , V_3 [ V_2 ] . V_1 ) ;
F_45 ( L_40 , V_18 , V_90 ) ;
F_45 ( L_41 , V_18 , V_91 ) ;
F_46 ( NULL , V_18 ) ;
}
V_92 = F_42 ( F_23 , V_27 ) ;
for ( V_2 = 0 ; V_2 < ( int ) F_2 ( V_7 ) ; V_2 ++ ) {
F_43 ( L_42 , V_7 [ V_2 ] . V_6 , V_92 ) ;
}
V_93 = F_42 ( F_31 , V_27 ) ;
F_43 ( L_36 , V_58 | V_59 , V_93 ) ;
V_93 = F_42 ( F_32 , V_27 ) ;
F_43 ( L_36 , V_60 | V_61 , V_93 ) ;
F_45 ( L_43 , L_44 , V_89 ) ;
}
