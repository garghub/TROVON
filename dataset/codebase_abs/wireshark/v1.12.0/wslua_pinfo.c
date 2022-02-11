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
F_17 ( V_1 , F_18 ( L_1 , ( long ) V_7 -> V_9 , V_7 -> V_11 ) ) ;
F_10 ( 1 ) ;
}
T_6 F_19 ( T_2 * V_1 ) {
T_5 V_12 = F_16 ( V_1 , 1 ) ;
T_5 V_13 = F_16 ( V_1 , 2 ) ;
T_5 V_14 = ( T_5 ) F_2 ( sizeof ( V_8 ) ) ;
F_20 ( V_14 , V_12 , V_13 ) ;
F_9 ( V_1 , V_14 ) ;
return 1 ;
}
T_6 F_21 ( T_2 * V_1 ) {
T_5 V_12 = F_16 ( V_1 , 1 ) ;
T_5 V_13 = F_16 ( V_1 , 2 ) ;
T_5 V_14 = ( T_5 ) F_2 ( sizeof ( V_8 ) ) ;
F_22 ( V_14 , V_12 , V_13 ) ;
F_9 ( V_1 , V_14 ) ;
return 1 ;
}
T_6 F_23 ( T_2 * V_1 ) {
T_5 V_12 = F_16 ( V_1 , 1 ) ;
T_5 V_13 = ( T_5 ) F_2 ( sizeof ( V_8 ) ) ;
F_24 ( V_13 ) ;
F_25 ( V_13 , V_12 ) ;
F_9 ( V_1 , V_13 ) ;
return 1 ;
}
T_6 F_26 ( T_2 * V_1 ) {
T_5 V_12 = F_16 ( V_1 , 1 ) ;
T_5 V_13 = F_16 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_27 ( V_12 , V_13 ) == 0 )
V_15 = TRUE ;
F_28 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_29 ( T_2 * V_1 ) {
T_5 V_12 = F_16 ( V_1 , 1 ) ;
T_5 V_13 = F_16 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_27 ( V_12 , V_13 ) <= 0 )
V_15 = TRUE ;
F_28 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_30 ( T_2 * V_1 ) {
T_5 V_12 = F_16 ( V_1 , 1 ) ;
T_5 V_13 = F_16 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_27 ( V_12 , V_13 ) < 0 )
V_15 = TRUE ;
F_28 ( V_1 , V_15 ) ;
return 1 ;
}
static int F_31 ( T_2 * V_1 ) {
T_5 V_7 = F_32 ( V_1 , 1 ) ;
if ( ! V_7 ) return 0 ;
F_33 ( V_7 ) ;
return 0 ;
}
int F_34 ( T_2 * V_1 ) {
F_35 ( T_5 ) ;
F_36 ( T_5 ) ;
return 0 ;
}
T_4 F_37 ( T_2 * V_1 ) {
#define F_38 1
T_8 V_16 = ( T_8 ) F_2 ( sizeof( V_17 ) ) ;
T_9 * V_18 = ( T_9 * ) F_2 ( sizeof( T_9 ) ) ;
const T_10 * V_19 = F_39 ( V_1 , F_38 ) ;
if ( ! F_40 ( V_19 , ( T_9 * ) V_18 ) ) {
* V_18 = 0 ;
}
F_41 ( V_16 , V_20 , 4 , V_18 ) ;
F_42 ( V_1 , V_16 ) ;
F_10 ( 1 ) ;
}
T_6 F_43 ( T_2 * V_1 ) {
T_8 V_16 = F_44 ( V_1 , 1 ) ;
F_17 ( V_1 , F_45 ( V_16 ) ) ;
F_10 ( 1 ) ;
}
static int F_46 ( T_2 * V_1 ) {
T_8 V_16 = F_47 ( V_1 , 1 ) ;
if ( V_16 ) {
F_33 ( ( void * ) ( V_16 -> V_21 ) ) ;
F_33 ( ( void * ) ( V_16 ) ) ;
}
return 0 ;
}
T_6 F_48 ( T_2 * V_1 ) {
T_8 V_22 = F_44 ( V_1 , 1 ) ;
T_8 V_23 = F_44 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_49 ( V_22 , V_23 ) )
V_15 = TRUE ;
F_28 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_50 ( T_2 * V_1 ) {
T_8 V_22 = F_44 ( V_1 , 1 ) ;
T_8 V_23 = F_44 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_51 ( V_22 , V_23 ) <= 0 )
V_15 = TRUE ;
F_28 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_52 ( T_2 * V_1 ) {
T_8 V_22 = F_44 ( V_1 , 1 ) ;
T_8 V_23 = F_44 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_51 ( V_22 , V_23 ) < 0 )
V_15 = TRUE ;
F_28 ( V_1 , V_15 ) ;
return 1 ;
}
int F_53 ( T_2 * V_1 ) {
F_35 ( T_8 ) ;
return 0 ;
}
static T_11 F_54 ( const T_10 * V_19 ) {
const struct V_24 * V_25 ;
for( V_25 = V_26 ; V_25 -> V_19 ; V_25 ++ ) {
if ( F_55 ( V_25 -> V_19 , V_19 ) ) {
return V_25 -> V_27 ;
}
}
return 0 ;
}
static const T_10 * F_56 ( T_11 V_27 ) {
const struct V_24 * V_25 ;
for( V_25 = V_26 ; V_25 -> V_19 ; V_25 ++ ) {
if ( V_25 -> V_27 == V_27 ) {
return V_25 -> V_19 ;
}
}
return NULL ;
}
T_6 F_57 ( T_2 * V_1 ) {
T_12 V_28 = F_58 ( V_1 , 1 ) ;
const T_10 * V_29 ;
if ( ! V_28 -> V_30 ) {
V_29 = F_56 ( V_28 -> V_31 ) ;
F_59 ( V_1 , L_2 , V_29 ? V_29 : L_3 ) ;
}
else {
V_29 = F_60 ( V_28 -> V_30 , V_28 -> V_31 ) ;
F_17 ( V_1 , V_29 ? V_29 : L_4 ) ;
}
F_10 ( 1 ) ;
}
static int F_61 ( T_2 * V_1 ) {
T_12 V_31 = F_62 ( V_1 , 1 ) ;
if ( ! V_31 ) return 0 ;
if ( ! V_31 -> V_5 )
V_31 -> V_5 = TRUE ;
else
F_33 ( V_31 ) ;
return 0 ;
}
T_13 F_63 ( T_2 * V_1 ) {
T_12 V_28 = F_58 ( V_1 , 1 ) ;
if ( ! ( V_28 -> V_30 ) ) return 0 ;
F_64 ( V_28 -> V_30 , V_28 -> V_31 ) ;
return 0 ;
}
T_13 F_65 ( T_2 * V_1 ) {
#define F_66 2
T_12 V_28 = F_58 ( V_1 , 1 ) ;
const T_10 * V_32 = F_39 ( V_1 , F_66 ) ;
if ( ! ( V_28 -> V_30 ) )
return 0 ;
if ( ! V_32 ) {
F_67 ( F_65 , V_33 , L_5 ) ;
return 0 ;
}
F_68 ( V_28 -> V_30 , V_28 -> V_31 , V_32 ) ;
return 0 ;
}
T_13 F_69 ( T_2 * V_1 ) {
#define F_70 2
T_12 V_28 = F_58 ( V_1 , 1 ) ;
const T_10 * V_32 = F_39 ( V_1 , F_70 ) ;
if ( ! ( V_28 -> V_30 ) )
return 0 ;
if ( ! V_32 ) {
F_67 ( F_69 , V_33 , L_5 ) ;
return 0 ;
}
F_71 ( V_28 -> V_30 , V_28 -> V_31 , V_32 ) ;
return 0 ;
}
T_13 F_72 ( T_2 * V_1 ) {
#define F_73 2
T_12 V_28 = F_58 ( V_1 , 1 ) ;
const T_10 * V_32 = F_39 ( V_1 , F_73 ) ;
if ( ! ( V_28 -> V_30 ) )
return 0 ;
if ( ! V_32 ) {
F_67 ( F_72 , V_33 , L_5 ) ;
return 0 ;
}
F_74 ( V_28 -> V_30 , V_28 -> V_31 , L_6 , V_32 ) ;
return 0 ;
}
T_13 F_75 ( T_2 * V_1 ) {
T_12 V_28 = F_58 ( V_1 , 1 ) ;
if ( V_28 -> V_30 )
F_76 ( V_28 -> V_30 , V_28 -> V_31 ) ;
return 0 ;
}
T_13 F_77 ( T_2 * V_1 ) {
T_12 V_28 = F_58 ( V_1 , 1 ) ;
if ( V_28 -> V_30 )
F_78 ( V_28 -> V_30 , V_28 -> V_31 ) ;
return 0 ;
}
int F_79 ( T_2 * V_1 ) {
F_35 ( T_12 ) ;
return 0 ;
}
T_6 F_80 ( T_2 * V_1 ) {
F_17 ( V_1 , L_7 ) ;
F_10 ( 1 ) ;
}
T_6 F_81 ( T_2 * V_1 ) {
#define F_82 2
#define F_83 3
T_14 V_34 = F_84 ( V_1 , 1 ) ;
const struct V_24 * V_25 ;
const char * V_35 ;
const char * V_29 ;
if ( ! V_34 ) return 0 ;
if ( V_34 -> V_5 ) {
F_85 ( V_1 , L_8 ) ;
return 0 ;
}
V_35 = F_39 ( V_1 , F_82 ) ;
V_29 = F_39 ( V_1 , F_83 ) ;
for( V_25 = V_26 ; V_25 -> V_19 ; V_25 ++ ) {
if( F_55 ( V_25 -> V_19 , V_35 ) ) {
F_68 ( V_34 -> V_30 , V_25 -> V_27 , V_29 ) ;
return 0 ;
}
}
F_67 ( F_81 , V_36 , L_9 ) ;
return 0 ;
}
T_6 F_86 ( T_2 * V_1 ) {
T_14 V_34 = F_84 ( V_1 , 1 ) ;
const struct V_24 * V_25 ;
const char * V_35 = F_39 ( V_1 , 2 ) ;
if ( ! V_34 ) {
T_12 V_28 = ( T_12 ) F_2 ( sizeof( struct V_37 ) ) ;
V_28 -> V_30 = NULL ;
V_28 -> V_31 = F_54 ( V_35 ) ;
V_28 -> V_5 = FALSE ;
F_87 ( V_1 , V_28 ) ;
return 1 ;
}
if ( V_34 -> V_5 ) {
F_85 ( V_1 , L_8 ) ;
return 0 ;
}
if ( ! V_35 ) return 0 ;
for( V_25 = V_26 ; V_25 -> V_19 ; V_25 ++ ) {
if( F_55 ( V_25 -> V_19 , V_35 ) ) {
T_12 V_28 = ( T_12 ) F_2 ( sizeof( struct V_37 ) ) ;
V_28 -> V_30 = V_34 -> V_30 ;
V_28 -> V_31 = F_54 ( V_35 ) ;
V_28 -> V_5 = FALSE ;
F_87 ( V_1 , V_28 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_88 ( T_2 * V_1 ) {
T_14 V_34 = F_89 ( V_1 , 1 ) ;
if ( ! V_34 ) return 0 ;
if ( ! V_34 -> V_5 )
V_34 -> V_5 = TRUE ;
else
F_33 ( V_34 ) ;
return 0 ;
}
int F_90 ( T_2 * V_1 ) {
F_91 ( T_14 ) ;
return 0 ;
}
T_6 F_92 ( T_2 * V_1 ) {
T_15 V_38 = F_93 ( V_1 , 1 ) ;
T_16 * V_39 ;
T_17 * V_40 , * V_41 ;
if ( ! V_38 ) return 0 ;
V_39 = F_94 ( L_10 ) ;
V_40 = F_95 ( V_38 -> V_42 ) ;
V_41 = F_96 ( V_40 ) ;
while ( V_41 ) {
V_39 = F_97 ( V_39 , ( const T_10 * ) V_41 -> V_21 ) ;
V_41 = F_98 ( V_41 ) ;
if ( V_41 ) {
V_39 = F_99 ( V_39 , ',' ) ;
}
}
F_17 ( V_1 , V_39 -> V_43 ) ;
F_100 ( V_39 , TRUE ) ;
F_101 ( V_40 ) ;
F_10 ( 1 ) ;
}
static int F_102 ( T_2 * V_1 ) {
T_15 V_38 = F_103 ( V_1 , 1 ) ;
const T_10 * V_19 = F_39 ( V_1 , 2 ) ;
const T_10 * string ;
string = ( const T_10 * ) ( F_104 ( V_38 -> V_42 , ( V_44 ) V_19 ) ) ;
if ( string ) {
F_17 ( V_1 , string ) ;
} else {
F_105 ( V_1 ) ;
}
return 1 ;
}
static int F_106 ( T_2 * V_1 ) {
T_15 V_38 = F_103 ( V_1 , 1 ) ;
const T_10 * V_19 = F_39 ( V_1 , 2 ) ;
const T_10 * string = NULL ;
if ( F_107 ( V_1 , 3 ) ) {
string = F_39 ( V_1 , 3 ) ;
} else if ( F_108 ( V_1 , 3 ) ) {
string = F_109 ( V_1 , 3 ) ? L_10 : NULL ;
} else if ( ! F_110 ( V_1 , 3 ) ) {
F_85 ( V_1 , L_11 , F_111 ( V_1 , 3 ) ) ;
return 0 ;
}
if ( string ) {
F_112 ( V_38 -> V_42 , ( V_44 ) F_113 ( V_19 ) , ( V_44 ) F_113 ( string ) ) ;
} else {
F_114 ( V_38 -> V_42 , ( V_45 ) V_19 ) ;
}
return 1 ;
}
static int F_115 ( T_2 * V_1 ) {
T_15 V_38 = F_93 ( V_1 , 1 ) ;
if ( ! V_38 ) return 0 ;
if ( ! V_38 -> V_5 ) {
V_38 -> V_5 = TRUE ;
} else {
if ( V_38 -> V_46 ) {
F_116 ( V_38 -> V_42 ) ;
}
F_33 ( V_38 ) ;
}
return 0 ;
}
int F_117 ( T_2 * V_1 ) {
F_91 ( T_15 ) ;
return 0 ;
}
static int F_118 ( T_2 * V_1 ) { F_17 ( V_1 , L_12 ) ; return 1 ; }
static double
F_119 ( const V_8 * V_7 )
{
return ( ( ( double ) V_7 -> V_9 ) + ( ( ( double ) V_7 -> V_11 ) / 1000000000.0 ) ) ;
}
static double
F_120 ( const T_1 V_3 , const T_18 * V_47 , T_9 V_48 )
{
V_8 V_49 ;
F_121 ( V_3 -> V_2 -> V_50 , V_47 , V_48 , & V_49 ) ;
return F_119 ( & V_49 ) ;
}
static int F_122 ( T_2 * V_1 ) {
T_1 V_3 = F_123 ( V_1 , 1 ) ;
if ( V_3 -> V_2 -> V_51 ) {
F_17 ( V_1 , V_3 -> V_2 -> V_51 ) ;
} else {
F_124 ( V_1 , ( V_52 ) ( V_3 -> V_2 -> V_53 ) ) ;
}
return 1 ;
}
static int F_125 ( T_2 * V_1 ) {
T_14 V_34 = NULL ;
T_1 V_3 = F_123 ( V_1 , 1 ) ;
const T_10 * V_35 = F_126 ( V_1 , 2 , NULL ) ;
V_34 = ( T_14 ) F_2 ( sizeof( struct V_54 ) ) ;
V_34 -> V_30 = V_3 -> V_2 -> V_30 ;
V_34 -> V_5 = FALSE ;
if ( ! V_35 ) {
F_127 ( V_1 , V_34 ) ;
} else {
F_128 ( V_1 , 0 ) ;
F_127 ( V_1 , V_34 ) ;
F_17 ( V_1 , V_35 ) ;
return F_86 ( V_1 ) ;
}
return 1 ;
}
static int F_129 ( T_2 * V_1 ) {
T_15 V_38 = NULL ;
T_1 V_3 = F_123 ( V_1 , 1 ) ;
const T_10 * V_55 = F_126 ( V_1 , 2 , NULL ) ;
T_7 V_46 = FALSE ;
if ( ! V_3 -> V_2 -> V_56 ) {
V_3 -> V_2 -> V_56 = F_130 ( V_57 , F_55 ) ;
V_46 = TRUE ;
}
V_38 = ( T_15 ) F_2 ( sizeof( struct V_58 ) ) ;
V_38 -> V_42 = V_3 -> V_2 -> V_56 ;
V_38 -> V_46 = V_46 ;
V_38 -> V_5 = FALSE ;
if ( ! V_55 ) {
F_131 ( V_1 , V_38 ) ;
} else {
F_128 ( V_1 , 0 ) ;
F_131 ( V_1 , V_38 ) ;
F_17 ( V_1 , V_55 ) ;
return F_102 ( V_1 ) ;
}
return 1 ;
}
static int F_132 ( T_2 * V_1 ) {
T_1 V_3 = F_123 ( V_1 , 1 ) ;
T_8 V_16 ;
V_16 = ( T_8 ) F_2 ( sizeof( V_17 ) ) ;
if ( F_51 ( & ( V_3 -> V_2 -> V_59 ) , & ( V_3 -> V_2 -> V_60 ) ) >= 0 ) {
F_133 ( V_16 , & ( V_3 -> V_2 -> V_59 ) ) ;
} else {
F_133 ( V_16 , & ( V_3 -> V_2 -> V_60 ) ) ;
}
F_42 ( V_1 , V_16 ) ;
return 1 ;
}
static int F_134 ( T_2 * V_1 ) {
T_1 V_3 = F_123 ( V_1 , 1 ) ;
T_8 V_16 ;
V_16 = ( T_8 ) F_2 ( sizeof( V_17 ) ) ;
if ( F_51 ( & ( V_3 -> V_2 -> V_59 ) , & ( V_3 -> V_2 -> V_60 ) ) < 0 ) {
F_133 ( V_16 , & ( V_3 -> V_2 -> V_59 ) ) ;
} else {
F_133 ( V_16 , & ( V_3 -> V_2 -> V_60 ) ) ;
}
F_42 ( V_1 , V_16 ) ;
return 1 ;
}
static int F_135 ( T_2 * V_1 ) {
T_1 V_3 = F_123 ( V_1 , 1 ) ;
T_19 V_61 = F_136 ( V_1 , 2 ) ;
T_20 * V_62 ;
if ( ! V_61 -> V_63 ) {
F_85 ( V_1 , L_13 , V_61 -> V_19 ? V_61 -> V_19 : L_14 ) ;
return 0 ;
}
V_62 = F_137 ( V_3 -> V_2 ) ;
F_138 ( V_62 , V_61 -> V_63 ) ;
return 0 ;
}
static int F_139 ( T_2 * V_1 ) {
T_1 V_3 = F_140 ( V_1 , 1 ) ;
if ( ! V_3 ) return 0 ;
if ( ! V_3 -> V_5 )
V_3 -> V_5 = TRUE ;
else
F_33 ( V_3 ) ;
return 0 ;
}
int F_141 ( T_2 * V_1 ) {
F_91 ( T_1 ) ;
F_36 ( T_1 ) ;
V_6 = F_142 () ;
V_64 = F_142 () ;
V_65 = F_142 () ;
V_66 = F_142 () ;
return 0 ;
}
