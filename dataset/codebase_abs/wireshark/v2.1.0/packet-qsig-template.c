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
T_2 V_1 = 0 , V_14 ;
const T_1 * V_15 ;
const T_8 * V_16 ;
T_9 * V_17 , * V_18 ;
T_6 * V_19 ;
if ( V_11 == NULL )
return 0 ;
V_13 = F_6 ( V_11 ) ;
F_7 ( V_13 ) ;
if ( V_13 -> V_20 . V_21 != 1 )
return V_12 ;
if ( V_13 -> V_20 . V_22 == 0 ) {
V_1 = V_13 -> V_20 . V_23 ;
V_15 = F_1 ( V_1 ) ;
} else if ( V_13 -> V_20 . V_22 == 1 ) {
V_15 = ( T_1 * ) F_8 ( V_24 , V_13 -> V_20 . V_25 ) ;
if ( V_15 ) V_1 = V_15 -> V_1 ;
} else {
return V_12 ;
}
if ( ! V_15 )
return V_12 ;
V_14 = F_3 ( V_1 ) ;
V_17 = F_9 ( V_10 , V_26 , V_8 , V_12 , F_10 ( V_8 ) , V_27 ) ;
V_19 = F_11 ( V_17 , V_28 ) ;
F_12 ( V_19 , V_29 , V_8 , 0 , 0 , V_1 ) ;
V_16 = F_13 ( V_1 , F_14 ( V_30 ) ) ;
if ( V_16 ) {
F_15 ( V_17 , L_1 , V_16 ) ;
F_15 ( V_13 -> V_20 . V_31 , L_2 , V_16 ) ;
if ( V_13 -> V_32 >= 0 )
F_15 ( F_16 ( F_17 ( V_10 ) , V_13 -> V_32 ) , L_3 , V_16 ) ;
}
V_18 = F_12 ( V_19 , V_33 , V_8 , 0 , 0 , V_14 ) ;
V_16 = F_13 ( V_14 , F_14 ( V_34 ) ) ;
if ( V_16 ) F_15 ( V_18 , L_2 , V_16 ) ;
if ( V_15 -> V_35 )
V_12 = V_15 -> V_35 ( V_8 , V_9 , V_19 , NULL ) ;
else
if ( F_18 ( V_8 , V_12 ) > 0 ) {
F_19 ( V_10 , V_9 , & V_36 , V_8 , V_12 , - 1 ) ;
V_12 += F_20 ( V_8 , V_12 ) ;
}
return V_12 ;
}
static int
F_21 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , void * V_11 ) {
T_10 V_12 = 0 ;
T_7 * V_13 ;
T_2 V_1 , V_14 ;
const T_1 * V_15 ;
const T_8 * V_16 ;
T_9 * V_17 , * V_18 ;
T_6 * V_19 ;
if ( V_11 == NULL )
return 0 ;
V_13 = F_6 ( V_11 ) ;
F_7 ( V_13 ) ;
if ( V_13 -> V_20 . V_21 != 2 )
return V_12 ;
if ( V_13 -> V_20 . V_22 != 0 )
return V_12 ;
V_1 = V_13 -> V_20 . V_23 ;
V_15 = F_1 ( V_1 ) ;
if ( ! V_15 )
return V_12 ;
V_14 = F_3 ( V_1 ) ;
V_17 = F_9 ( V_10 , V_26 , V_8 , V_12 , F_10 ( V_8 ) , V_27 ) ;
V_19 = F_11 ( V_17 , V_28 ) ;
F_12 ( V_19 , V_29 , V_8 , 0 , 0 , V_1 ) ;
V_16 = F_13 ( V_1 , F_14 ( V_30 ) ) ;
if ( V_16 ) {
F_15 ( V_17 , L_1 , V_16 ) ;
F_15 ( V_13 -> V_20 . V_31 , L_2 , V_16 ) ;
if ( V_13 -> V_32 >= 0 )
F_15 ( F_16 ( F_17 ( V_10 ) , V_13 -> V_32 ) , L_3 , V_16 ) ;
}
V_18 = F_12 ( V_19 , V_33 , V_8 , 0 , 0 , V_14 ) ;
V_16 = F_13 ( V_14 , F_14 ( V_34 ) ) ;
if ( V_16 ) F_15 ( V_18 , L_2 , V_16 ) ;
if ( V_15 -> V_37 )
V_12 = V_15 -> V_37 ( V_8 , V_9 , V_19 , NULL ) ;
else
if ( F_18 ( V_8 , V_12 ) > 0 ) {
F_19 ( V_10 , V_9 , & V_38 , V_8 , V_12 , - 1 ) ;
V_12 += F_20 ( V_8 , V_12 ) ;
}
return V_12 ;
}
static int
F_22 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , void * V_11 ) {
int V_12 = 0 ;
T_7 * V_13 ;
T_2 V_6 ;
const T_3 * V_39 ;
const T_8 * V_16 ;
T_9 * V_17 ;
T_6 * V_19 ;
if ( V_11 == NULL )
return 0 ;
V_13 = F_6 ( V_11 ) ;
F_7 ( V_13 ) ;
if ( V_13 -> V_20 . V_21 != 3 )
return V_12 ;
if ( V_13 -> V_20 . V_22 != 0 )
return V_12 ;
V_6 = V_13 -> V_20 . V_23 ;
V_39 = F_4 ( V_6 ) ;
if ( ! V_39 )
return V_12 ;
V_17 = F_9 ( V_10 , V_26 , V_8 , V_12 , F_10 ( V_8 ) , V_27 ) ;
V_19 = F_11 ( V_17 , V_28 ) ;
F_12 ( V_19 , V_40 , V_8 , 0 , 0 , V_6 ) ;
V_16 = F_13 ( V_6 , F_14 ( V_41 ) ) ;
if ( V_16 ) {
F_15 ( V_17 , L_1 , V_16 ) ;
F_15 ( V_13 -> V_20 . V_31 , L_2 , V_16 ) ;
if ( V_13 -> V_32 >= 0 )
F_15 ( F_16 ( F_17 ( V_10 ) , V_13 -> V_32 ) , L_3 , V_16 ) ;
}
if ( V_39 -> V_42 )
V_12 = V_39 -> V_42 ( V_8 , V_9 , V_19 , NULL ) ;
else
if ( F_18 ( V_8 , V_12 ) > 0 ) {
F_19 ( V_10 , V_9 , & V_36 , V_8 , V_12 , - 1 ) ;
V_12 += F_20 ( V_8 , V_12 ) ;
}
return V_12 ;
}
static int
F_23 ( T_4 * V_8 , int V_12 , T_5 * V_9 V_43 , T_6 * V_10 , int T_11 V_43 ) {
F_9 ( V_10 , V_44 , V_8 , V_12 , 1 , V_45 ) ;
V_12 ++ ;
return V_12 ;
}
static int
F_24 ( T_4 * V_8 , int V_12 , T_5 * V_9 V_43 , T_6 * V_10 , int T_11 V_43 ) {
F_9 ( V_10 , V_46 , V_8 , V_12 , 1 , V_45 ) ;
V_12 ++ ;
return V_12 ;
}
static void
F_25 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , int V_47 ) {
T_10 V_12 ;
T_9 * V_17 , * V_48 ;
T_6 * V_49 ;
T_12 V_50 , V_51 ;
V_12 = 0 ;
V_17 = F_9 ( V_10 , V_26 , V_8 , V_12 , - 1 , V_27 ) ;
F_26 ( V_17 ) ;
V_50 = F_27 ( V_8 , V_12 ) ;
V_51 = F_27 ( V_8 , V_12 + 1 ) ;
V_49 = F_28 ( V_10 , V_8 , V_12 , - 1 , V_52 , NULL ,
F_29 ( V_50 , F_14 ( V_53 [ V_47 ] ) , L_4 ) ) ;
F_9 ( V_49 , * V_54 [ V_47 ] , V_8 , V_12 , 1 , V_45 ) ;
V_48 = F_9 ( V_49 , V_55 , V_8 , V_12 , 1 , V_45 ) ;
F_26 ( V_48 ) ;
F_9 ( V_49 , V_56 , V_8 , V_12 + 1 , 1 , V_45 ) ;
V_12 += 2 ;
if ( F_18 ( V_8 , V_12 ) <= 0 )
return;
switch ( ( V_47 << 8 ) | V_50 ) {
case V_57 | V_58 :
F_23 ( V_8 , V_12 , V_9 , V_49 , V_51 ) ;
break;
case V_59 | V_60 :
F_24 ( V_8 , V_12 , V_9 , V_49 , V_51 ) ;
break;
default:
if ( V_51 > 0 ) {
if ( V_10 ) F_9 ( V_49 , V_61 , V_8 , V_12 , V_51 , V_27 ) ;
}
}
}
static int
F_30 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , void * V_11 V_43 ) {
F_25 ( V_8 , V_9 , V_10 , 4 ) ;
return F_10 ( V_8 ) ;
}
static int
F_31 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , void * V_11 V_43 ) {
F_25 ( V_8 , V_9 , V_10 , 5 ) ;
return F_10 ( V_8 ) ;
}
static void F_32 ( void ) {
T_13 V_2 ;
T_10 V_1 , * V_62 ;
T_8 * V_63 ;
if ( V_64 )
F_33 ( V_64 ) ;
V_64 = F_34 ( V_65 , V_66 , V_67 , V_67 ) ;
if ( V_24 )
F_33 ( V_24 ) ;
V_24 = F_34 ( V_68 , V_69 , V_67 , NULL ) ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ ) {
V_1 = V_3 [ V_2 ] . V_1 ;
V_63 = F_35 ( L_5 , V_1 ) ;
V_62 = ( T_10 * ) F_36 ( sizeof( T_10 ) ) ;
* V_62 = V_1 ;
F_37 ( V_64 , V_62 , V_63 ) ;
F_37 ( V_24 , F_38 ( V_63 ) , ( V_70 ) & V_3 [ V_2 ] ) ;
}
}
void F_39 ( void ) {
static T_14 V_71 [] = {
{ & V_29 , { L_6 , L_7 ,
V_72 , V_73 , F_14 ( V_30 ) , 0x0 ,
NULL , V_74 } } ,
{ & V_33 , { L_8 , L_9 ,
V_72 , V_73 , F_14 ( V_75 ) , 0x0 ,
L_10 , V_74 } } ,
{ & V_40 , { L_11 , L_12 ,
V_72 , V_73 , F_14 ( V_41 ) , 0x0 ,
NULL , V_74 } } ,
{ & V_55 , { L_13 , L_14 ,
V_72 , V_76 , NULL , 0x0 ,
L_15 , V_74 } } ,
{ & V_77 , { L_13 , L_16 ,
V_72 , V_76 , F_14 ( V_78 ) , 0x0 ,
L_17 , V_74 } } ,
{ & V_79 , { L_13 , L_18 ,
V_72 , V_76 , F_14 ( V_80 ) , 0x0 ,
L_19 , V_74 } } ,
{ & V_56 , { L_20 , L_21 ,
V_72 , V_73 , NULL , 0x0 ,
L_22 , V_74 } } ,
{ & V_61 , { L_23 , L_24 ,
V_81 , V_82 , NULL , 0x0 ,
NULL , V_74 } } ,
{ & V_44 , { L_25 , L_26 ,
V_72 , V_73 , NULL , 0x1F ,
NULL , V_74 } } ,
{ & V_46 , { L_27 , L_28 ,
V_72 , V_76 , F_14 ( V_83 ) , 0x07 ,
NULL , V_74 } } ,
#include "packet-qsig-hfarr.c"
} ;
static T_10 * V_84 [] = {
& V_28 ,
& V_52 ,
& V_85 ,
#include "packet-qsig-ettarr.c"
& V_86 ,
} ;
static T_15 V_87 [] = {
#if 0
{ &ei_qsig_unsupported_arg_type, { "qsig.unsupported.arg_type", PI_UNDECODED, PI_WARN, "UNSUPPORTED ARGUMENT TYPE (QSIG)", EXPFILL }},
#endif
{ & V_38 , { L_29 , V_88 , V_89 , L_30 , V_90 } } ,
{ & V_36 , { L_31 , V_88 , V_89 , L_32 , V_90 } } ,
} ;
T_16 * V_91 ;
V_26 = F_40 ( V_92 , V_93 , V_94 ) ;
F_41 ( V_26 , V_71 , F_2 ( V_71 ) ) ;
F_42 ( V_84 , F_2 ( V_84 ) ) ;
V_91 = F_43 ( V_26 ) ;
F_44 ( V_91 , V_87 , F_2 ( V_87 ) ) ;
V_95 = F_45 ( L_33 , L_34 , V_26 , V_96 , V_82 , V_97 ) ;
F_32 () ;
}
void F_46 ( void ) {
int V_2 ;
T_10 V_62 ;
const T_8 * V_63 ;
T_17 V_98 ;
T_17 V_99 ;
T_17 V_100 ;
T_17 V_101 ;
T_17 V_102 ;
V_98 = F_47 ( L_35 , V_26 ) ;
V_103 = F_47 ( L_36 , V_26 ) ;
V_99 = F_48 ( F_5 , V_26 ) ;
V_100 = F_48 ( F_21 , V_26 ) ;
for ( V_2 = 0 ; V_2 < ( int ) F_2 ( V_3 ) ; V_2 ++ ) {
F_49 ( L_37 , V_3 [ V_2 ] . V_1 , V_99 ) ;
F_49 ( L_38 , V_3 [ V_2 ] . V_1 , V_100 ) ;
V_62 = V_3 [ V_2 ] . V_1 ;
V_63 = ( const T_8 * ) F_8 ( V_64 , & V_62 ) ;
if ( V_63 ) {
F_50 ( L_39 , V_63 , V_99 ) ;
F_50 ( L_40 , V_63 , V_100 ) ;
}
}
V_101 = F_48 ( F_22 , V_26 ) ;
for ( V_2 = 0 ; V_2 < ( int ) F_2 ( V_7 ) ; V_2 ++ ) {
F_49 ( L_41 , V_7 [ V_2 ] . V_6 , V_101 ) ;
}
V_102 = F_48 ( F_30 , V_26 ) ;
F_49 ( L_36 , V_57 | V_58 , V_102 ) ;
V_102 = F_48 ( F_31 , V_26 ) ;
F_49 ( L_36 , V_59 | V_60 , V_102 ) ;
F_50 ( L_42 , L_43 , V_98 ) ;
}
