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
#define F_12 1
#define F_13 2
F_14 ( V_1 , 1 ) ;
F_10 ( F_5 ( V_1 ) ) ;
}
T_6 F_15 ( T_2 * V_1 ) {
T_5 V_7 = F_16 ( V_1 , 1 ) ;
T_7 * V_12 ;
V_12 = F_17 ( NULL , L_1 , ( long ) V_7 -> V_9 , V_7 -> V_11 ) ;
F_18 ( V_1 , V_12 ) ;
F_19 ( NULL , V_12 ) ;
F_10 ( 1 ) ;
}
T_6 F_20 ( T_2 * V_1 ) {
T_5 V_13 = F_16 ( V_1 , 1 ) ;
T_5 V_14 = F_16 ( V_1 , 2 ) ;
T_5 V_15 = ( T_5 ) F_2 ( sizeof ( V_8 ) ) ;
F_21 ( V_15 , V_13 , V_14 ) ;
F_9 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_22 ( T_2 * V_1 ) {
T_5 V_13 = F_16 ( V_1 , 1 ) ;
T_5 V_14 = F_16 ( V_1 , 2 ) ;
T_5 V_15 = ( T_5 ) F_2 ( sizeof ( V_8 ) ) ;
F_23 ( V_15 , V_13 , V_14 ) ;
F_9 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_24 ( T_2 * V_1 ) {
T_5 V_13 = F_16 ( V_1 , 1 ) ;
T_5 V_14 = ( T_5 ) F_2 ( sizeof ( V_8 ) ) ;
F_25 ( V_14 ) ;
F_26 ( V_14 , V_13 ) ;
F_9 ( V_1 , V_14 ) ;
return 1 ;
}
T_6 F_27 ( T_2 * V_1 ) {
T_5 V_13 = F_16 ( V_1 , 1 ) ;
T_5 V_14 = F_16 ( V_1 , 2 ) ;
T_8 V_16 = FALSE ;
if ( F_28 ( V_13 , V_14 ) == 0 )
V_16 = TRUE ;
F_29 ( V_1 , V_16 ) ;
return 1 ;
}
T_6 F_30 ( T_2 * V_1 ) {
T_5 V_13 = F_16 ( V_1 , 1 ) ;
T_5 V_14 = F_16 ( V_1 , 2 ) ;
T_8 V_16 = FALSE ;
if ( F_28 ( V_13 , V_14 ) <= 0 )
V_16 = TRUE ;
F_29 ( V_1 , V_16 ) ;
return 1 ;
}
T_6 F_31 ( T_2 * V_1 ) {
T_5 V_13 = F_16 ( V_1 , 1 ) ;
T_5 V_14 = F_16 ( V_1 , 2 ) ;
T_8 V_16 = FALSE ;
if ( F_28 ( V_13 , V_14 ) < 0 )
V_16 = TRUE ;
F_29 ( V_1 , V_16 ) ;
return 1 ;
}
static int F_32 ( T_2 * V_1 ) {
T_5 V_7 = F_33 ( V_1 , 1 ) ;
if ( ! V_7 ) return 0 ;
F_34 ( V_7 ) ;
return 0 ;
}
int F_35 ( T_2 * V_1 ) {
F_36 ( T_5 ) ;
F_37 ( T_5 ) ;
return 0 ;
}
T_4 F_38 ( T_2 * V_1 ) {
#define F_39 1
T_9 V_17 = ( T_9 ) F_2 ( sizeof( V_18 ) ) ;
T_10 * V_19 = ( T_10 * ) F_2 ( sizeof( T_10 ) ) ;
const T_7 * V_20 = F_40 ( V_1 , F_39 ) ;
if ( ! F_41 ( V_20 , ( T_10 * ) V_19 ) ) {
* V_19 = 0 ;
}
F_42 ( V_17 , V_21 , 4 , V_19 ) ;
F_43 ( V_1 , V_17 ) ;
F_10 ( 1 ) ;
}
T_6 F_44 ( T_2 * V_1 ) {
T_9 V_17 = F_45 ( V_1 , 1 ) ;
F_18 ( V_1 , F_46 ( V_17 ) ) ;
F_10 ( 1 ) ;
}
static int F_47 ( T_2 * V_1 ) {
T_9 V_17 = F_48 ( V_1 , 1 ) ;
if ( V_17 ) {
F_34 ( ( void * ) ( V_17 -> V_22 ) ) ;
F_34 ( ( void * ) ( V_17 ) ) ;
}
return 0 ;
}
T_6 F_49 ( T_2 * V_1 ) {
T_9 V_23 = F_45 ( V_1 , 1 ) ;
T_9 V_24 = F_45 ( V_1 , 2 ) ;
T_8 V_16 = FALSE ;
if ( F_50 ( V_23 , V_24 ) )
V_16 = TRUE ;
F_29 ( V_1 , V_16 ) ;
return 1 ;
}
T_6 F_51 ( T_2 * V_1 ) {
T_9 V_23 = F_45 ( V_1 , 1 ) ;
T_9 V_24 = F_45 ( V_1 , 2 ) ;
T_8 V_16 = FALSE ;
if ( F_52 ( V_23 , V_24 ) <= 0 )
V_16 = TRUE ;
F_29 ( V_1 , V_16 ) ;
return 1 ;
}
T_6 F_53 ( T_2 * V_1 ) {
T_9 V_23 = F_45 ( V_1 , 1 ) ;
T_9 V_24 = F_45 ( V_1 , 2 ) ;
T_8 V_16 = FALSE ;
if ( F_52 ( V_23 , V_24 ) < 0 )
V_16 = TRUE ;
F_29 ( V_1 , V_16 ) ;
return 1 ;
}
int F_54 ( T_2 * V_1 ) {
F_36 ( T_9 ) ;
return 0 ;
}
static T_11 F_55 ( const T_7 * V_20 ) {
const struct V_25 * V_26 ;
for( V_26 = V_27 ; V_26 -> V_20 ; V_26 ++ ) {
if ( F_56 ( V_26 -> V_20 , V_20 ) ) {
return V_26 -> V_28 ;
}
}
return 0 ;
}
static const T_7 * F_57 ( T_11 V_28 ) {
const struct V_25 * V_26 ;
for( V_26 = V_27 ; V_26 -> V_20 ; V_26 ++ ) {
if ( V_26 -> V_28 == V_28 ) {
return V_26 -> V_20 ;
}
}
return NULL ;
}
T_6 F_58 ( T_2 * V_1 ) {
T_12 V_29 = F_59 ( V_1 , 1 ) ;
const T_7 * V_30 ;
if ( ! V_29 -> V_31 ) {
V_30 = F_57 ( V_29 -> V_32 ) ;
F_60 ( V_1 , L_2 , V_30 ? V_30 : L_3 ) ;
}
else {
V_30 = F_61 ( V_29 -> V_31 , V_29 -> V_32 ) ;
F_18 ( V_1 , V_30 ? V_30 : L_4 ) ;
}
F_10 ( 1 ) ;
}
static int F_62 ( T_2 * V_1 ) {
T_12 V_32 = F_63 ( V_1 , 1 ) ;
if ( ! V_32 ) return 0 ;
if ( ! V_32 -> V_5 )
V_32 -> V_5 = TRUE ;
else
F_34 ( V_32 ) ;
return 0 ;
}
T_13 F_64 ( T_2 * V_1 ) {
T_12 V_29 = F_59 ( V_1 , 1 ) ;
if ( ! ( V_29 -> V_31 ) ) return 0 ;
F_65 ( V_29 -> V_31 , V_29 -> V_32 ) ;
return 0 ;
}
T_13 F_66 ( T_2 * V_1 ) {
#define F_67 2
T_12 V_29 = F_59 ( V_1 , 1 ) ;
const T_7 * V_33 = F_40 ( V_1 , F_67 ) ;
if ( ! ( V_29 -> V_31 ) )
return 0 ;
if ( ! V_33 ) {
F_68 ( F_66 , V_34 , L_5 ) ;
return 0 ;
}
F_69 ( V_29 -> V_31 , V_29 -> V_32 , V_33 ) ;
return 0 ;
}
T_13 F_70 ( T_2 * V_1 ) {
#define F_71 2
T_12 V_29 = F_59 ( V_1 , 1 ) ;
const T_7 * V_33 = F_40 ( V_1 , F_71 ) ;
if ( ! ( V_29 -> V_31 ) )
return 0 ;
if ( ! V_33 ) {
F_68 ( F_70 , V_34 , L_5 ) ;
return 0 ;
}
F_72 ( V_29 -> V_31 , V_29 -> V_32 , V_33 ) ;
return 0 ;
}
T_13 F_73 ( T_2 * V_1 ) {
#define F_74 2
T_12 V_29 = F_59 ( V_1 , 1 ) ;
const T_7 * V_33 = F_40 ( V_1 , F_74 ) ;
if ( ! ( V_29 -> V_31 ) )
return 0 ;
if ( ! V_33 ) {
F_68 ( F_73 , V_34 , L_5 ) ;
return 0 ;
}
F_75 ( V_29 -> V_31 , V_29 -> V_32 , L_6 , V_33 ) ;
return 0 ;
}
T_13 F_76 ( T_2 * V_1 ) {
T_12 V_29 = F_59 ( V_1 , 1 ) ;
if ( V_29 -> V_31 )
F_77 ( V_29 -> V_31 , V_29 -> V_32 ) ;
return 0 ;
}
T_13 F_78 ( T_2 * V_1 ) {
T_12 V_29 = F_59 ( V_1 , 1 ) ;
if ( V_29 -> V_31 )
F_79 ( V_29 -> V_31 , V_29 -> V_32 ) ;
return 0 ;
}
int F_80 ( T_2 * V_1 ) {
F_36 ( T_12 ) ;
return 0 ;
}
T_6 F_81 ( T_2 * V_1 ) {
F_18 ( V_1 , L_7 ) ;
F_10 ( 1 ) ;
}
T_6 F_82 ( T_2 * V_1 ) {
#define F_83 2
#define F_84 3
T_14 V_35 = F_85 ( V_1 , 1 ) ;
const struct V_25 * V_26 ;
const char * V_36 ;
const char * V_30 ;
if ( ! V_35 ) return 0 ;
if ( V_35 -> V_5 ) {
F_86 ( V_1 , L_8 ) ;
return 0 ;
}
V_36 = F_40 ( V_1 , F_83 ) ;
V_30 = F_40 ( V_1 , F_84 ) ;
for( V_26 = V_27 ; V_26 -> V_20 ; V_26 ++ ) {
if( F_56 ( V_26 -> V_20 , V_36 ) ) {
F_69 ( V_35 -> V_31 , V_26 -> V_28 , V_30 ) ;
return 0 ;
}
}
F_68 ( F_82 , V_37 , L_9 ) ;
return 0 ;
}
T_6 F_87 ( T_2 * V_1 ) {
T_14 V_35 = F_85 ( V_1 , 1 ) ;
const struct V_25 * V_26 ;
const char * V_36 = F_40 ( V_1 , 2 ) ;
if ( ! V_35 ) {
T_12 V_29 = ( T_12 ) F_2 ( sizeof( struct V_38 ) ) ;
V_29 -> V_31 = NULL ;
V_29 -> V_32 = F_55 ( V_36 ) ;
V_29 -> V_5 = FALSE ;
F_88 ( V_1 , V_29 ) ;
return 1 ;
}
if ( V_35 -> V_5 ) {
F_86 ( V_1 , L_8 ) ;
return 0 ;
}
if ( ! V_36 ) return 0 ;
for( V_26 = V_27 ; V_26 -> V_20 ; V_26 ++ ) {
if( F_56 ( V_26 -> V_20 , V_36 ) ) {
T_12 V_29 = ( T_12 ) F_2 ( sizeof( struct V_38 ) ) ;
V_29 -> V_31 = V_35 -> V_31 ;
V_29 -> V_32 = F_55 ( V_36 ) ;
V_29 -> V_5 = FALSE ;
F_88 ( V_1 , V_29 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_89 ( T_2 * V_1 ) {
T_14 V_35 = F_90 ( V_1 , 1 ) ;
if ( ! V_35 ) return 0 ;
if ( ! V_35 -> V_5 )
V_35 -> V_5 = TRUE ;
else
F_34 ( V_35 ) ;
return 0 ;
}
int F_91 ( T_2 * V_1 ) {
F_92 ( T_14 ) ;
return 0 ;
}
T_6 F_93 ( T_2 * V_1 ) {
T_15 V_39 = F_94 ( V_1 , 1 ) ;
T_16 * V_40 ;
T_17 * V_41 , * V_42 ;
if ( ! V_39 ) return 0 ;
V_40 = F_95 ( L_10 ) ;
V_41 = F_96 ( V_39 -> V_43 ) ;
V_42 = F_97 ( V_41 ) ;
while ( V_42 ) {
V_40 = F_98 ( V_40 , ( const T_7 * ) V_42 -> V_22 ) ;
V_42 = F_99 ( V_42 ) ;
if ( V_42 ) {
V_40 = F_100 ( V_40 , ',' ) ;
}
}
F_18 ( V_1 , V_40 -> V_12 ) ;
F_101 ( V_40 , TRUE ) ;
F_102 ( V_41 ) ;
F_10 ( 1 ) ;
}
static int F_103 ( T_2 * V_1 ) {
T_15 V_39 = F_104 ( V_1 , 1 ) ;
const T_7 * V_20 = F_40 ( V_1 , 2 ) ;
const T_7 * string ;
string = ( const T_7 * ) ( F_105 ( V_39 -> V_43 , ( V_44 ) V_20 ) ) ;
if ( string ) {
F_18 ( V_1 , string ) ;
} else {
F_106 ( V_1 ) ;
}
return 1 ;
}
static int F_107 ( T_2 * V_1 ) {
T_15 V_39 = F_104 ( V_1 , 1 ) ;
const T_7 * V_20 = F_40 ( V_1 , 2 ) ;
const T_7 * string = NULL ;
if ( F_108 ( V_1 , 3 ) ) {
string = F_40 ( V_1 , 3 ) ;
} else if ( F_109 ( V_1 , 3 ) ) {
string = F_110 ( V_1 , 3 ) ? L_10 : NULL ;
} else if ( ! F_111 ( V_1 , 3 ) ) {
F_86 ( V_1 , L_11 , F_112 ( V_1 , 3 ) ) ;
return 0 ;
}
if ( string ) {
F_113 ( V_39 -> V_43 , ( V_44 ) F_114 ( V_20 ) , ( V_44 ) F_114 ( string ) ) ;
} else {
F_115 ( V_39 -> V_43 , ( V_45 ) V_20 ) ;
}
return 1 ;
}
static int F_116 ( T_2 * V_1 ) {
T_15 V_39 = F_94 ( V_1 , 1 ) ;
if ( ! V_39 ) return 0 ;
if ( ! V_39 -> V_5 ) {
V_39 -> V_5 = TRUE ;
} else {
if ( V_39 -> V_46 ) {
F_117 ( V_39 -> V_43 ) ;
}
F_34 ( V_39 ) ;
}
return 0 ;
}
int F_118 ( T_2 * V_1 ) {
F_92 ( T_15 ) ;
return 0 ;
}
static int F_119 ( T_2 * V_1 ) { F_18 ( V_1 , L_12 ) ; return 1 ; }
static double
F_120 ( const V_8 * V_7 )
{
return ( ( ( double ) V_7 -> V_9 ) + ( ( ( double ) V_7 -> V_11 ) / 1000000000.0 ) ) ;
}
static double
F_121 ( const T_1 V_3 , const T_18 * V_47 , T_10 V_48 )
{
V_8 V_49 ;
F_122 ( V_3 -> V_2 -> V_50 , V_47 , V_48 , & V_49 ) ;
return F_120 ( & V_49 ) ;
}
static int F_123 ( T_2 * V_1 ) {
T_1 V_3 = F_124 ( V_1 , 1 ) ;
if ( V_3 -> V_2 -> V_51 ) {
F_18 ( V_1 , V_3 -> V_2 -> V_51 ) ;
} else {
F_125 ( V_1 , ( V_52 ) ( V_3 -> V_2 -> V_53 ) ) ;
}
return 1 ;
}
static int F_126 ( T_2 * V_1 ) {
T_14 V_35 = NULL ;
T_1 V_3 = F_124 ( V_1 , 1 ) ;
const T_7 * V_36 = F_127 ( V_1 , 2 , NULL ) ;
V_35 = ( T_14 ) F_2 ( sizeof( struct V_54 ) ) ;
V_35 -> V_31 = V_3 -> V_2 -> V_31 ;
V_35 -> V_5 = FALSE ;
if ( ! V_36 ) {
F_128 ( V_1 , V_35 ) ;
} else {
F_129 ( V_1 , 0 ) ;
F_128 ( V_1 , V_35 ) ;
F_18 ( V_1 , V_36 ) ;
return F_87 ( V_1 ) ;
}
return 1 ;
}
static int F_130 ( T_2 * V_1 ) {
T_15 V_39 = NULL ;
T_1 V_3 = F_124 ( V_1 , 1 ) ;
const T_7 * V_55 = F_127 ( V_1 , 2 , NULL ) ;
T_8 V_46 = FALSE ;
if ( ! V_3 -> V_2 -> V_56 ) {
V_3 -> V_2 -> V_56 = F_131 ( V_57 , F_56 ) ;
V_46 = TRUE ;
}
V_39 = ( T_15 ) F_2 ( sizeof( struct V_58 ) ) ;
V_39 -> V_43 = V_3 -> V_2 -> V_56 ;
V_39 -> V_46 = V_46 ;
V_39 -> V_5 = FALSE ;
if ( ! V_55 ) {
F_132 ( V_1 , V_39 ) ;
} else {
F_129 ( V_1 , 0 ) ;
F_132 ( V_1 , V_39 ) ;
F_18 ( V_1 , V_55 ) ;
return F_103 ( V_1 ) ;
}
return 1 ;
}
static int F_133 ( T_2 * V_1 ) {
T_1 V_3 = F_124 ( V_1 , 1 ) ;
T_9 V_17 ;
V_17 = ( T_9 ) F_2 ( sizeof( V_18 ) ) ;
if ( F_52 ( & ( V_3 -> V_2 -> V_59 ) , & ( V_3 -> V_2 -> V_60 ) ) >= 0 ) {
F_134 ( V_17 , & ( V_3 -> V_2 -> V_59 ) ) ;
} else {
F_134 ( V_17 , & ( V_3 -> V_2 -> V_60 ) ) ;
}
F_43 ( V_1 , V_17 ) ;
return 1 ;
}
static int F_135 ( T_2 * V_1 ) {
T_1 V_3 = F_124 ( V_1 , 1 ) ;
T_9 V_17 ;
V_17 = ( T_9 ) F_2 ( sizeof( V_18 ) ) ;
if ( F_52 ( & ( V_3 -> V_2 -> V_59 ) , & ( V_3 -> V_2 -> V_60 ) ) < 0 ) {
F_134 ( V_17 , & ( V_3 -> V_2 -> V_59 ) ) ;
} else {
F_134 ( V_17 , & ( V_3 -> V_2 -> V_60 ) ) ;
}
F_43 ( V_1 , V_17 ) ;
return 1 ;
}
static int F_136 ( T_2 * V_1 ) {
T_1 V_3 = F_124 ( V_1 , 1 ) ;
T_19 V_61 = F_137 ( V_1 , 2 ) ;
T_20 * V_62 ;
if ( ! V_61 -> V_63 ) {
F_86 ( V_1 , L_13 , V_61 -> V_20 ? V_61 -> V_20 : L_14 ) ;
return 0 ;
}
V_62 = F_138 ( V_3 -> V_2 ) ;
F_139 ( V_62 , V_61 -> V_63 ) ;
return 0 ;
}
static int F_140 ( T_2 * V_1 ) {
T_1 V_3 = F_141 ( V_1 , 1 ) ;
if ( ! V_3 ) return 0 ;
if ( ! V_3 -> V_5 )
V_3 -> V_5 = TRUE ;
else
F_34 ( V_3 ) ;
return 0 ;
}
int F_142 ( T_2 * V_1 ) {
F_92 ( T_1 ) ;
F_37 ( T_1 ) ;
V_6 = F_143 () ;
V_64 = F_143 () ;
V_65 = F_143 () ;
V_66 = F_143 () ;
return 0 ;
}
