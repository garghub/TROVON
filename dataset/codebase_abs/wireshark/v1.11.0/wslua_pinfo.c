T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 ) {
T_1 V_3 = NULL ;
if ( V_2 ) {
V_3 = ( T_1 ) F_2 ( sizeof( struct V_4 ) ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_5 = FALSE ;
F_3 ( V_6 , V_3 ) ;
}
return F_4 ( V_1 , V_3 ) ;
}
T_4 F_5 ( T_2 * V_1 ) {
#define F_6 1
#define F_7 2
T_5 V_7 = ( T_5 ) F_2 ( sizeof( V_8 ) ) ;
if ( ! V_7 ) return 0 ;
V_7 -> V_9 = ( V_10 ) F_8 ( V_1 , F_6 , 0 ) ;
V_7 -> V_11 = F_8 ( V_1 , F_7 , 0 ) ;
F_9 ( V_1 , V_7 ) ;
F_10 ( 1 ) ;
}
T_6 F_11 ( T_2 * V_1 ) {
T_5 V_7 = F_12 ( V_1 , 1 ) ;
if ( ! V_7 ) return 0 ;
F_13 ( V_1 , F_14 ( L_1 , ( long ) V_7 -> V_9 , V_7 -> V_11 ) ) ;
F_10 ( 1 ) ;
}
T_6 F_15 ( T_2 * V_1 ) {
T_5 V_12 = F_12 ( V_1 , 1 ) ;
T_5 V_13 = F_12 ( V_1 , 2 ) ;
T_5 V_14 = ( T_5 ) F_2 ( sizeof ( V_8 ) ) ;
F_16 ( V_14 , V_12 , V_13 ) ;
F_9 ( V_1 , V_14 ) ;
return 1 ;
}
T_6 F_17 ( T_2 * V_1 ) {
T_5 V_12 = F_12 ( V_1 , 1 ) ;
T_5 V_13 = F_12 ( V_1 , 2 ) ;
T_5 V_14 = ( T_5 ) F_2 ( sizeof ( V_8 ) ) ;
F_18 ( V_14 , V_12 , V_13 ) ;
F_9 ( V_1 , V_14 ) ;
return 1 ;
}
T_6 F_19 ( T_2 * V_1 ) {
T_5 V_12 = F_12 ( V_1 , 1 ) ;
T_5 V_13 = ( T_5 ) F_2 ( sizeof ( V_8 ) ) ;
F_20 ( V_13 ) ;
F_21 ( V_13 , V_12 ) ;
F_9 ( V_1 , V_13 ) ;
return 1 ;
}
T_6 F_22 ( T_2 * V_1 ) {
T_5 V_12 = F_12 ( V_1 , 1 ) ;
T_5 V_13 = F_12 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( ! V_12 || ! V_13 )
F_23 ( F_22 , L_2 ) ;
if ( F_24 ( V_12 , V_13 ) == 0 )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_26 ( T_2 * V_1 ) {
T_5 V_12 = F_12 ( V_1 , 1 ) ;
T_5 V_13 = F_12 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( ! V_12 || ! V_13 )
F_23 ( F_26 , L_2 ) ;
if ( F_24 ( V_12 , V_13 ) <= 0 )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_27 ( T_2 * V_1 ) {
T_5 V_12 = F_12 ( V_1 , 1 ) ;
T_5 V_13 = F_12 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( ! V_12 || ! V_13 )
F_23 ( F_27 , L_2 ) ;
if ( F_24 ( V_12 , V_13 ) < 0 )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
static int F_28 ( T_2 * V_1 ) {
T_5 V_7 = F_29 ( V_1 , 1 ) ;
F_30 ( V_1 , ( V_16 ) ( V_7 -> V_9 ) ) ;
return 1 ;
}
static int F_31 ( T_2 * V_1 )
{
T_5 V_7 = F_29 ( V_1 , 1 ) ;
V_10 V_9 = F_32 ( V_1 , 3 ) ;
V_7 -> V_9 = V_9 ;
return 0 ;
}
static int F_33 ( T_2 * V_1 ) {
T_5 V_7 = F_29 ( V_1 , 1 ) ;
F_30 ( V_1 , ( V_16 ) ( V_7 -> V_11 ) ) ;
return 1 ;
}
static int F_34 ( T_2 * V_1 ) {
T_5 V_7 = F_29 ( V_1 , 1 ) ;
int V_11 = F_32 ( V_1 , 3 ) ;
V_7 -> V_11 = V_11 ;
return 0 ;
}
static int F_35 ( T_2 * V_1 ) {
T_5 V_7 = F_12 ( V_1 , 1 ) ;
const T_8 * V_17 = F_36 ( V_1 , 2 ) ;
const T_9 * V_18 ;
if ( ! ( V_7 && V_17 ) ) return 0 ;
for ( V_18 = V_19 ; V_18 -> V_17 ; V_18 ++ ) {
if ( F_37 ( V_17 , V_18 -> V_17 ) ) {
if ( V_18 -> V_20 ) {
return V_18 -> V_20 ( V_1 ) ;
} else {
F_38 ( V_1 , L_3 , V_17 ) ;
return 0 ;
}
}
}
F_38 ( V_1 , L_4 , V_17 ) ;
return 0 ;
}
static int F_39 ( T_2 * V_1 ) {
T_5 V_7 = F_12 ( V_1 , 1 ) ;
const T_8 * V_17 = F_36 ( V_1 , 2 ) ;
const T_9 * V_18 ;
if ( ! ( V_7 && V_17 ) ) return 0 ;
for ( V_18 = V_19 ; V_18 -> V_17 ; V_18 ++ ) {
if ( F_37 ( V_17 , V_18 -> V_17 ) ) {
if ( V_18 -> V_21 ) {
return V_18 -> V_21 ( V_1 ) ;
} else {
F_38 ( V_1 , L_5 , V_17 ) ;
return 0 ;
}
}
}
F_38 ( V_1 , L_4 , V_17 ) ;
return 0 ;
}
static int F_40 ( T_2 * V_1 ) {
T_5 V_7 = F_12 ( V_1 , 1 ) ;
if ( ! V_7 ) return 0 ;
F_41 ( V_7 ) ;
return 0 ;
}
int F_42 ( T_2 * V_1 ) {
F_43 ( T_5 ) ;
F_44 ( V_1 , F_5 ) ;
F_45 ( V_1 , L_6 ) ;
return 1 ;
}
T_4 F_46 ( T_2 * V_1 ) {
#define F_47 1
T_10 V_22 = ( T_10 ) F_2 ( sizeof( V_23 ) ) ;
T_11 * V_24 = ( T_11 * ) F_2 ( sizeof( T_11 ) ) ;
const T_8 * V_17 = F_36 ( V_1 , F_47 ) ;
if ( ! F_48 ( V_17 , ( T_11 * ) V_24 ) ) {
* V_24 = 0 ;
}
F_49 ( V_22 , V_25 , 4 , V_24 ) ;
F_50 ( V_1 , V_22 ) ;
F_10 ( 1 ) ;
}
T_6 F_51 ( T_2 * V_1 ) {
T_10 V_22 = F_52 ( V_1 , 1 ) ;
F_13 ( V_1 , F_53 ( V_22 ) ) ;
F_10 ( 1 ) ;
}
static int F_54 ( T_2 * V_1 ) {
T_10 V_22 = F_52 ( V_1 , 1 ) ;
if ( V_22 ) {
F_41 ( ( void * ) V_22 -> V_26 ) ;
F_41 ( ( void * ) V_22 ) ;
}
return 0 ;
}
T_6 F_55 ( T_2 * V_1 ) {
T_10 V_27 = F_52 ( V_1 , 1 ) ;
T_10 V_28 = F_52 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_56 ( V_27 , V_28 ) )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_57 ( T_2 * V_1 ) {
T_10 V_27 = F_52 ( V_1 , 1 ) ;
T_10 V_28 = F_52 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_58 ( V_27 , V_28 ) <= 0 )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_59 ( T_2 * V_1 ) {
T_10 V_27 = F_52 ( V_1 , 1 ) ;
T_10 V_28 = F_52 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_58 ( V_27 , V_28 ) < 0 )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
int F_60 ( T_2 * V_1 ) {
F_61 ( T_10 ) ;
return 1 ;
}
static T_12 F_62 ( const T_8 * V_17 ) {
const struct V_29 * V_30 ;
for( V_30 = V_31 ; V_30 -> V_17 ; V_30 ++ ) {
if ( F_37 ( V_30 -> V_17 , V_17 ) ) {
return V_30 -> V_32 ;
}
}
return 0 ;
}
static const T_8 * F_63 ( T_12 V_32 ) {
const struct V_29 * V_30 ;
for( V_30 = V_31 ; V_30 -> V_17 ; V_30 ++ ) {
if ( V_30 -> V_32 == V_32 ) {
return V_30 -> V_17 ;
}
}
return NULL ;
}
T_6 F_64 ( T_2 * V_1 ) {
T_13 V_33 = F_65 ( V_1 , 1 ) ;
const T_8 * V_34 ;
if ( ! V_33 ) {
F_13 ( V_1 , L_7 ) ;
}
else if ( ! V_33 -> V_35 ) {
V_34 = F_63 ( V_33 -> V_36 ) ;
F_66 ( V_1 , L_8 , V_34 ? V_34 : L_9 ) ;
}
else {
V_34 = F_67 ( V_33 -> V_35 , V_33 -> V_36 ) ;
F_13 ( V_1 , V_34 ? V_34 : L_7 ) ;
}
F_10 ( 1 ) ;
}
static int F_68 ( T_2 * V_1 ) {
T_13 V_36 = F_65 ( V_1 , 1 ) ;
if ( ! V_36 ) return 0 ;
if ( ! V_36 -> V_5 )
V_36 -> V_5 = TRUE ;
else
F_41 ( V_36 ) ;
return 0 ;
}
T_14 F_69 ( T_2 * V_1 ) {
T_13 V_33 = F_65 ( V_1 , 1 ) ;
if ( ! ( V_33 && V_33 -> V_35 ) ) return 0 ;
F_70 ( V_33 -> V_35 , V_33 -> V_36 ) ;
return 0 ;
}
T_14 F_71 ( T_2 * V_1 ) {
#define F_72 2
T_13 V_33 = F_65 ( V_1 , 1 ) ;
const T_8 * V_37 = F_36 ( V_1 , F_72 ) ;
if ( ! ( V_33 && V_33 -> V_35 ) )
return 0 ;
if ( ! V_37 ) F_73 ( F_71 , V_38 , L_10 ) ;
F_74 ( V_33 -> V_35 , V_33 -> V_36 , V_37 ) ;
return 0 ;
}
T_14 F_75 ( T_2 * V_1 ) {
#define F_76 2
T_13 V_33 = F_65 ( V_1 , 1 ) ;
const T_8 * V_37 = F_36 ( V_1 , F_76 ) ;
if ( ! ( V_33 && V_33 -> V_35 ) )
return 0 ;
if ( ! V_37 ) F_73 ( F_75 , V_38 , L_10 ) ;
F_77 ( V_33 -> V_35 , V_33 -> V_36 , V_37 ) ;
return 0 ;
}
T_14 F_78 ( T_2 * V_1 ) {
#define F_79 2
T_13 V_33 = F_65 ( V_1 , 1 ) ;
const T_8 * V_37 = F_36 ( V_1 , F_79 ) ;
if ( ! ( V_33 && V_33 -> V_35 ) )
return 0 ;
if ( ! V_37 ) F_73 ( F_78 , V_38 , L_10 ) ;
F_80 ( V_33 -> V_35 , V_33 -> V_36 , L_11 , V_37 ) ;
return 0 ;
}
T_14 F_81 ( T_2 * V_1 ) {
T_13 V_33 = F_65 ( V_1 , 1 ) ;
if ( V_33 && V_33 -> V_35 )
F_82 ( V_33 -> V_35 , V_33 -> V_36 ) ;
return 0 ;
}
int F_83 ( T_2 * V_1 ) {
F_61 ( T_13 ) ;
return 1 ;
}
T_6 F_84 ( T_2 * V_1 ) {
F_13 ( V_1 , L_12 ) ;
F_10 ( 1 ) ;
}
T_6 F_85 ( T_2 * V_1 ) {
#define F_86 2
#define F_87 3
T_15 V_39 = F_88 ( V_1 , 1 ) ;
const struct V_29 * V_30 ;
const char * V_40 ;
const char * V_34 ;
if ( ! V_39 ) return 0 ;
if ( V_39 -> V_5 ) {
F_38 ( V_1 , L_13 ) ;
return 0 ;
}
V_40 = F_36 ( V_1 , F_86 ) ;
V_34 = F_36 ( V_1 , F_87 ) ;
for( V_30 = V_31 ; V_30 -> V_17 ; V_30 ++ ) {
if( F_37 ( V_30 -> V_17 , V_40 ) ) {
F_74 ( V_39 -> V_35 , V_30 -> V_32 , V_34 ) ;
return 0 ;
}
}
F_73 ( F_85 , V_41 , L_14 ) ;
}
T_6 F_89 ( T_2 * V_1 ) {
T_15 V_39 = F_88 ( V_1 , 1 ) ;
const struct V_29 * V_30 ;
const char * V_40 = F_36 ( V_1 , 2 ) ;
if ( ! V_39 ) {
T_13 V_33 = ( T_13 ) F_2 ( sizeof( struct V_42 ) ) ;
V_33 -> V_35 = NULL ;
V_33 -> V_36 = F_62 ( V_40 ) ;
V_33 -> V_5 = FALSE ;
F_90 ( V_1 , V_33 ) ;
return 1 ;
}
if ( V_39 -> V_5 ) {
F_38 ( V_1 , L_13 ) ;
return 0 ;
}
if ( ! V_40 ) return 0 ;
for( V_30 = V_31 ; V_30 -> V_17 ; V_30 ++ ) {
if( F_37 ( V_30 -> V_17 , V_40 ) ) {
T_13 V_33 = ( T_13 ) F_2 ( sizeof( struct V_42 ) ) ;
V_33 -> V_35 = V_39 -> V_35 ;
V_33 -> V_36 = F_62 ( V_40 ) ;
V_33 -> V_5 = FALSE ;
F_90 ( V_1 , V_33 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_91 ( T_2 * V_1 ) {
T_15 V_39 = F_88 ( V_1 , 1 ) ;
if ( ! V_39 ) return 0 ;
if ( ! V_39 -> V_5 )
V_39 -> V_5 = TRUE ;
else
F_41 ( V_39 ) ;
return 0 ;
}
int F_92 ( T_2 * V_1 ) {
F_43 ( T_15 ) ;
return 1 ;
}
T_6 F_93 ( T_2 * V_1 ) {
T_16 V_43 = F_94 ( V_1 , 1 ) ;
T_17 * V_44 ;
T_18 * V_45 , * V_46 ;
if ( ! V_43 ) return 0 ;
V_44 = F_95 ( L_15 ) ;
V_45 = F_96 ( V_43 -> V_47 ) ;
V_46 = F_97 ( V_45 ) ;
while ( V_46 ) {
V_44 = F_98 ( V_44 , ( const T_8 * ) V_46 -> V_26 ) ;
V_46 = F_99 ( V_46 ) ;
if ( V_46 ) {
V_44 = F_100 ( V_44 , ',' ) ;
}
}
F_13 ( V_1 , V_44 -> V_48 ) ;
F_101 ( V_44 , TRUE ) ;
F_102 ( V_45 ) ;
F_10 ( 1 ) ;
}
static int F_103 ( T_2 * V_1 ) {
T_16 V_43 = F_94 ( V_1 , 1 ) ;
const T_8 * V_17 = F_36 ( V_1 , 2 ) ;
const T_8 * string ;
if ( ! ( V_43 && V_17 ) ) return 0 ;
if ( V_43 -> V_5 ) {
F_38 ( V_1 , L_16 ) ;
return 0 ;
}
string = ( const T_8 * ) F_104 ( V_43 -> V_47 , ( V_49 ) V_17 ) ;
if ( string ) {
F_13 ( V_1 , string ) ;
} else {
F_105 ( V_1 ) ;
}
return 1 ;
}
static int F_106 ( T_2 * V_1 ) {
T_16 V_43 = F_94 ( V_1 , 1 ) ;
const T_8 * V_17 = F_36 ( V_1 , 2 ) ;
const T_8 * string = NULL ;
if ( ! ( V_43 && V_17 ) ) return 0 ;
if ( V_43 -> V_5 ) {
F_38 ( V_1 , L_16 ) ;
return 0 ;
}
if ( F_107 ( V_1 , 3 ) ) {
string = F_36 ( V_1 , 3 ) ;
} else if ( F_108 ( V_1 , 3 ) ) {
string = F_109 ( V_1 , 3 ) ? L_15 : NULL ;
} else if ( ! F_110 ( V_1 , 3 ) ) {
F_38 ( V_1 , L_17 , F_111 ( V_1 , 3 ) ) ;
return 0 ;
}
if ( string ) {
F_112 ( V_43 -> V_47 , ( V_49 ) F_113 ( V_17 ) , ( V_49 ) F_113 ( string ) ) ;
} else {
F_114 ( V_43 -> V_47 , ( V_49 ) V_17 ) ;
}
return 1 ;
}
static int F_115 ( T_2 * V_1 ) {
T_16 V_43 = F_94 ( V_1 , 1 ) ;
if ( ! V_43 ) return 0 ;
if ( ! V_43 -> V_5 ) {
V_43 -> V_5 = TRUE ;
} else {
if ( V_43 -> V_50 ) {
F_116 ( V_43 -> V_47 ) ;
}
F_41 ( V_43 ) ;
}
return 0 ;
}
int F_117 ( T_2 * V_1 ) {
F_43 ( T_16 ) ;
return 1 ;
}
static int F_118 ( T_2 * V_1 ) { F_13 ( V_1 , L_18 ) ; return 1 ; }
static double
F_119 ( const V_8 * V_7 )
{
return ( ( ( double ) V_7 -> V_9 ) + ( ( ( double ) V_7 -> V_11 ) / 1000000000.0 ) ) ;
}
static double
F_120 ( const T_1 V_3 , const T_19 * V_51 , T_11 V_52 )
{
V_8 V_53 ;
F_121 ( V_3 -> V_2 -> V_54 , V_51 , V_52 , & V_53 ) ;
return F_119 ( & V_53 ) ;
}
static int F_122 ( T_2 * V_1 ) {
T_1 V_3 = F_123 ( V_1 , 1 ) ;
if ( ! V_3 ) return 0 ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
if ( V_3 -> V_2 -> V_55 ) {
F_13 ( V_1 , V_3 -> V_2 -> V_55 ) ;
} else {
F_30 ( V_1 , ( V_16 ) ( V_3 -> V_2 -> V_56 ) ) ;
}
return 1 ;
}
static int F_124 ( T_2 * V_1 ) {
T_15 V_39 = NULL ;
T_1 V_3 = F_123 ( V_1 , 1 ) ;
const T_8 * V_40 = F_125 ( V_1 , 2 , NULL ) ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
V_39 = ( T_15 ) F_2 ( sizeof( struct V_57 ) ) ;
V_39 -> V_35 = V_3 -> V_2 -> V_35 ;
V_39 -> V_5 = FALSE ;
if ( ! V_40 ) {
F_126 ( V_1 , V_39 ) ;
} else {
F_127 ( V_1 , 0 ) ;
F_126 ( V_1 , V_39 ) ;
F_13 ( V_1 , V_40 ) ;
return F_89 ( V_1 ) ;
}
return 1 ;
}
static int F_128 ( T_2 * V_1 ) {
T_16 V_43 = NULL ;
T_1 V_3 = F_123 ( V_1 , 1 ) ;
const T_8 * V_58 = F_125 ( V_1 , 2 , NULL ) ;
T_7 V_50 = FALSE ;
if ( ! V_3 ) return 0 ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_16 ) ;
return 0 ;
}
if ( ! V_3 -> V_2 -> V_59 ) {
V_3 -> V_2 -> V_59 = F_129 ( V_60 , F_37 ) ;
V_50 = TRUE ;
}
V_43 = ( T_16 ) F_2 ( sizeof( struct V_61 ) ) ;
V_43 -> V_47 = V_3 -> V_2 -> V_59 ;
V_43 -> V_50 = V_50 ;
V_43 -> V_5 = FALSE ;
if ( ! V_58 ) {
F_130 ( V_1 , V_43 ) ;
} else {
F_127 ( V_1 , 0 ) ;
F_130 ( V_1 , V_43 ) ;
F_13 ( V_1 , V_58 ) ;
return F_103 ( V_1 ) ;
}
return 1 ;
}
static int F_131 ( T_2 * V_1 , T_3 * V_3 V_62 , T_20 T_21 V_62 ) {
F_105 ( V_1 ) ;
return 1 ;
}
static int F_132 ( T_2 * V_1 , T_3 * V_3 , T_20 T_21 ) {
const V_23 * V_63 = F_52 ( V_1 , 1 ) ;
V_23 * V_64 ;
if ( ! V_63 ) {
F_38 ( V_1 , L_20 ) ;
return 0 ;
}
if ( ! V_3 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
switch( T_21 ) {
case V_65 :
V_64 = & ( V_3 -> V_66 ) ;
break;
case V_67 :
V_64 = & ( V_3 -> V_68 ) ;
break;
case V_69 :
V_64 = & ( V_3 -> V_70 ) ;
break;
case V_71 :
V_64 = & ( V_3 -> V_72 ) ;
break;
case V_73 :
V_64 = & ( V_3 -> V_74 ) ;
break;
case V_75 :
V_64 = & ( V_3 -> V_76 ) ;
break;
default:
F_133 ( ! L_21 ) ;
return 0 ;
}
F_134 ( V_64 , V_63 ) ;
return 0 ;
}
static int F_135 ( T_2 * V_1 , T_3 * V_3 , T_20 T_21 ) {
T_22 V_77 = F_32 ( V_1 , 1 ) ;
if ( ! V_3 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
switch( T_21 ) {
case V_78 :
V_3 -> V_79 = ( T_11 ) V_77 ;
return 0 ;
case V_80 :
V_3 -> V_81 = ( T_11 ) V_77 ;
return 0 ;
case V_82 :
V_3 -> V_83 = ( T_11 ) V_77 ;
return 0 ;
case V_84 :
V_3 -> V_85 = ( V_86 ) V_77 ;
return 0 ;
case V_87 :
V_3 -> V_88 = ( T_11 ) V_77 ;
return 0 ;
case V_89 :
V_3 -> V_90 = ( int ) V_77 ;
return 0 ;
case V_91 :
V_3 -> V_92 = ( T_11 ) V_77 ;
return 0 ;
default:
F_133 ( ! L_21 ) ;
}
return 0 ;
}
static int F_136 ( T_2 * V_1 ) {
T_1 V_3 = F_123 ( V_1 , 1 ) ;
T_10 V_22 ;
if ( ! V_3 ) return 0 ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
V_22 = ( T_10 ) F_2 ( sizeof( V_23 ) ) ;
if ( F_58 ( & ( V_3 -> V_2 -> V_66 ) , & ( V_3 -> V_2 -> V_68 ) ) >= 0 ) {
F_134 ( V_22 , & ( V_3 -> V_2 -> V_66 ) ) ;
} else {
F_134 ( V_22 , & ( V_3 -> V_2 -> V_68 ) ) ;
}
F_50 ( V_1 , V_22 ) ;
return 1 ;
}
static int F_137 ( T_2 * V_1 ) {
T_1 V_3 = F_123 ( V_1 , 1 ) ;
T_10 V_22 ;
if ( ! V_3 ) return 0 ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
V_22 = ( T_10 ) F_2 ( sizeof( V_23 ) ) ;
if ( F_58 ( & ( V_3 -> V_2 -> V_66 ) , & ( V_3 -> V_2 -> V_68 ) ) < 0 ) {
F_134 ( V_22 , & ( V_3 -> V_2 -> V_66 ) ) ;
} else {
F_134 ( V_22 , & ( V_3 -> V_2 -> V_68 ) ) ;
}
F_50 ( V_1 , V_22 ) ;
return 1 ;
}
static int F_138 ( T_2 * V_1 ) {
F_105 ( V_1 ) ;
return 1 ;
}
static int F_139 ( T_2 * V_1 ) {
T_1 V_3 = F_123 ( V_1 , 1 ) ;
const T_8 * V_17 = F_36 ( V_1 , 2 ) ;
T_23 V_93 = F_138 ;
const T_24 * V_94 ;
if ( ! ( V_3 && V_17 ) ) {
F_105 ( V_1 ) ;
return 1 ;
}
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
for ( V_94 = V_95 ; V_94 -> V_17 ; V_94 ++ ) {
if ( F_37 ( V_94 -> V_17 , V_17 ) ) {
V_93 = V_94 -> V_20 ;
break;
}
}
F_127 ( V_1 , 1 ) ;
return V_93 ( V_1 ) ;
}
static int F_140 ( T_2 * V_1 ) {
T_1 V_3 = F_123 ( V_1 , 1 ) ;
const T_8 * V_17 = F_36 ( V_1 , 2 ) ;
int (* V_93)( T_2 * , T_3 * V_3 , T_20 ) = F_131 ;
const T_24 * V_94 ;
T_20 V_96 = V_97 ;
if ( ! ( V_3 && V_17 ) ) {
return 0 ;
}
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
for ( V_94 = V_95 ; V_94 -> V_17 ; V_94 ++ ) {
if ( F_37 ( V_94 -> V_17 , V_17 ) ) {
V_93 = V_94 -> V_21 ;
V_96 = V_94 -> V_98 ;
break;
}
}
F_141 ( V_1 , 1 ) ;
F_141 ( V_1 , 1 ) ;
return V_93 ( V_1 , V_3 -> V_2 , V_96 ) ;
}
static int F_142 ( T_2 * V_1 ) {
T_1 V_3 = F_123 ( V_1 , 1 ) ;
if ( ! V_3 ) return 0 ;
if ( ! V_3 -> V_5 )
V_3 -> V_5 = TRUE ;
else
F_41 ( V_3 ) ;
return 0 ;
}
int F_143 ( T_2 * V_1 ) {
F_43 ( T_1 ) ;
V_6 = F_144 () ;
V_99 = F_144 () ;
V_100 = F_144 () ;
V_101 = F_144 () ;
return 1 ;
}
