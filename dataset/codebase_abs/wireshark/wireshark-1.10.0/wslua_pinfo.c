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
F_23 ( V_16 , L_2 ) ;
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
F_23 ( V_16 , L_2 ) ;
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
F_23 ( V_16 , L_2 ) ;
if ( F_24 ( V_12 , V_13 ) < 0 )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
static int F_28 ( T_2 * V_1 ) {
T_5 V_7 = F_29 ( V_1 , 1 ) ;
F_30 ( V_1 , ( V_17 ) ( V_7 -> V_9 ) ) ;
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
F_30 ( V_1 , ( V_17 ) ( V_7 -> V_11 ) ) ;
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
const T_8 * V_18 = F_36 ( V_1 , 2 ) ;
const T_9 * V_19 ;
if ( ! ( V_7 && V_18 ) ) return 0 ;
for ( V_19 = V_20 ; V_19 -> V_18 ; V_19 ++ ) {
if ( F_37 ( V_18 , V_19 -> V_18 ) ) {
if ( V_19 -> V_21 ) {
return V_19 -> V_21 ( V_1 ) ;
} else {
F_38 ( V_1 , L_3 , V_18 ) ;
return 0 ;
}
}
}
F_38 ( V_1 , L_4 , V_18 ) ;
return 0 ;
}
static int F_39 ( T_2 * V_1 ) {
T_5 V_7 = F_12 ( V_1 , 1 ) ;
const T_8 * V_18 = F_36 ( V_1 , 2 ) ;
const T_9 * V_19 ;
if ( ! ( V_7 && V_18 ) ) return 0 ;
for ( V_19 = V_20 ; V_19 -> V_18 ; V_19 ++ ) {
if ( F_37 ( V_18 , V_19 -> V_18 ) ) {
if ( V_19 -> V_22 ) {
return V_19 -> V_22 ( V_1 ) ;
} else {
F_38 ( V_1 , L_5 , V_18 ) ;
return 0 ;
}
}
}
F_38 ( V_1 , L_4 , V_18 ) ;
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
T_10 V_23 = ( T_10 ) F_2 ( sizeof( V_24 ) ) ;
T_11 * V_25 = ( T_11 * ) F_2 ( sizeof( T_11 ) ) ;
const T_8 * V_18 = F_36 ( V_1 , F_47 ) ;
if ( ! F_48 ( V_18 , ( T_11 * ) V_25 ) ) {
* V_25 = 0 ;
}
F_49 ( V_23 , V_26 , 4 , V_25 ) ;
F_50 ( V_1 , V_23 ) ;
F_10 ( 1 ) ;
}
T_6 F_51 ( T_2 * V_1 ) {
T_10 V_23 = F_52 ( V_1 , 1 ) ;
F_13 ( V_1 , F_53 ( V_23 ) ) ;
F_10 ( 1 ) ;
}
static int F_54 ( T_2 * V_1 ) {
T_10 V_23 = F_52 ( V_1 , 1 ) ;
if ( V_23 ) {
F_41 ( ( void * ) V_23 -> V_27 ) ;
F_41 ( ( void * ) V_23 ) ;
}
return 0 ;
}
T_6 F_55 ( T_2 * V_1 ) {
T_10 V_28 = F_52 ( V_1 , 1 ) ;
T_10 V_29 = F_52 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_56 ( V_28 , V_29 ) )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_57 ( T_2 * V_1 ) {
T_10 V_28 = F_52 ( V_1 , 1 ) ;
T_10 V_29 = F_52 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_58 ( V_28 , V_29 ) <= 0 )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_59 ( T_2 * V_1 ) {
T_10 V_28 = F_52 ( V_1 , 1 ) ;
T_10 V_29 = F_52 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_58 ( V_28 , V_29 ) < 0 )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
int F_60 ( T_2 * V_1 ) {
F_61 ( T_10 ) ;
return 1 ;
}
static T_12 F_62 ( const T_8 * V_18 ) {
const struct V_30 * V_31 ;
for( V_31 = V_32 ; V_31 -> V_18 ; V_31 ++ ) {
if ( F_37 ( V_31 -> V_18 , V_18 ) ) {
return V_31 -> V_33 ;
}
}
return 0 ;
}
static const T_8 * F_63 ( T_12 V_33 ) {
const struct V_30 * V_31 ;
for( V_31 = V_32 ; V_31 -> V_18 ; V_31 ++ ) {
if ( V_31 -> V_33 == V_33 ) {
return V_31 -> V_18 ;
}
}
return NULL ;
}
T_6 F_64 ( T_2 * V_1 ) {
T_13 V_34 = F_65 ( V_1 , 1 ) ;
const T_8 * V_35 ;
if ( ! V_34 ) {
F_13 ( V_1 , L_7 ) ;
}
else if ( ! V_34 -> V_36 ) {
V_35 = F_63 ( V_34 -> V_37 ) ;
F_66 ( V_1 , L_8 , V_35 ? V_35 : L_9 ) ;
}
else {
V_35 = F_67 ( V_34 -> V_36 , V_34 -> V_37 ) ;
F_13 ( V_1 , V_35 ? V_35 : L_7 ) ;
}
F_10 ( 1 ) ;
}
static int F_68 ( T_2 * V_1 ) {
T_13 V_37 = F_65 ( V_1 , 1 ) ;
if ( ! V_37 ) return 0 ;
if ( ! V_37 -> V_5 )
V_37 -> V_5 = TRUE ;
else
F_41 ( V_37 ) ;
return 0 ;
}
T_14 F_69 ( T_2 * V_1 ) {
T_13 V_34 = F_65 ( V_1 , 1 ) ;
if ( ! ( V_34 && V_34 -> V_36 ) ) return 0 ;
F_70 ( V_34 -> V_36 , V_34 -> V_37 ) ;
return 0 ;
}
T_14 F_71 ( T_2 * V_1 ) {
#define F_72 2
T_13 V_34 = F_65 ( V_1 , 1 ) ;
const T_8 * V_38 = F_36 ( V_1 , F_72 ) ;
if ( ! ( V_34 && V_34 -> V_36 ) )
return 0 ;
if ( ! V_38 ) F_73 ( F_71 , V_39 , L_10 ) ;
F_74 ( V_34 -> V_36 , V_34 -> V_37 , V_38 ) ;
return 0 ;
}
T_14 F_75 ( T_2 * V_1 ) {
#define F_76 2
T_13 V_34 = F_65 ( V_1 , 1 ) ;
const T_8 * V_38 = F_36 ( V_1 , F_76 ) ;
if ( ! ( V_34 && V_34 -> V_36 ) )
return 0 ;
if ( ! V_38 ) F_73 ( F_75 , V_39 , L_10 ) ;
F_77 ( V_34 -> V_36 , V_34 -> V_37 , V_38 ) ;
return 0 ;
}
T_14 F_78 ( T_2 * V_1 ) {
#define F_79 2
T_13 V_34 = F_65 ( V_1 , 1 ) ;
const T_8 * V_38 = F_36 ( V_1 , F_79 ) ;
if ( ! ( V_34 && V_34 -> V_36 ) )
return 0 ;
if ( ! V_38 ) F_73 ( F_78 , V_39 , L_10 ) ;
if ( F_80 ( V_34 -> V_36 , V_34 -> V_37 ) )
F_81 ( V_34 -> V_36 , V_34 -> V_37 , L_11 , V_38 ) ;
return 0 ;
}
T_14 F_82 ( T_2 * V_1 ) {
T_13 V_34 = F_65 ( V_1 , 1 ) ;
if ( V_34 && V_34 -> V_36 )
F_83 ( V_34 -> V_36 , V_34 -> V_37 ) ;
return 0 ;
}
int F_84 ( T_2 * V_1 ) {
F_61 ( T_13 ) ;
return 1 ;
}
T_6 F_85 ( T_2 * V_1 ) {
F_13 ( V_1 , L_12 ) ;
F_10 ( 1 ) ;
}
T_6 F_86 ( T_2 * V_1 ) {
#define F_87 2
#define F_88 3
T_15 V_40 = F_89 ( V_1 , 1 ) ;
const struct V_30 * V_31 ;
const char * V_41 ;
const char * V_35 ;
if ( ! V_40 ) return 0 ;
if ( V_40 -> V_5 ) {
F_38 ( V_1 , L_13 ) ;
return 0 ;
}
V_41 = F_36 ( V_1 , F_87 ) ;
V_35 = F_36 ( V_1 , F_88 ) ;
for( V_31 = V_32 ; V_31 -> V_18 ; V_31 ++ ) {
if( F_37 ( V_31 -> V_18 , V_41 ) ) {
F_74 ( V_40 -> V_36 , V_31 -> V_33 , V_35 ) ;
return 0 ;
}
}
F_73 ( F_86 , V_42 , L_14 ) ;
}
T_6 F_90 ( T_2 * V_1 ) {
T_15 V_40 = F_89 ( V_1 , 1 ) ;
const struct V_30 * V_31 ;
const char * V_41 = F_36 ( V_1 , 2 ) ;
if ( ! V_40 ) {
T_13 V_34 = ( T_13 ) F_2 ( sizeof( struct V_43 ) ) ;
V_34 -> V_36 = NULL ;
V_34 -> V_37 = F_62 ( V_41 ) ;
V_34 -> V_5 = FALSE ;
F_91 ( V_1 , V_34 ) ;
return 1 ;
}
if ( V_40 -> V_5 ) {
F_38 ( V_1 , L_13 ) ;
return 0 ;
}
if ( ! V_41 ) return 0 ;
for( V_31 = V_32 ; V_31 -> V_18 ; V_31 ++ ) {
if( F_37 ( V_31 -> V_18 , V_41 ) ) {
T_13 V_34 = ( T_13 ) F_2 ( sizeof( struct V_43 ) ) ;
V_34 -> V_36 = V_40 -> V_36 ;
V_34 -> V_37 = F_62 ( V_41 ) ;
V_34 -> V_5 = FALSE ;
F_91 ( V_1 , V_34 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_92 ( T_2 * V_1 ) {
T_15 V_40 = F_89 ( V_1 , 1 ) ;
if ( ! V_40 ) return 0 ;
if ( ! V_40 -> V_5 )
V_40 -> V_5 = TRUE ;
else
F_41 ( V_40 ) ;
return 0 ;
}
int F_93 ( T_2 * V_1 ) {
F_43 ( T_15 ) ;
return 1 ;
}
T_6 F_94 ( T_2 * V_1 ) {
T_16 V_44 = F_95 ( V_1 , 1 ) ;
T_17 * V_45 ;
T_18 * V_46 , * V_47 ;
if ( ! V_44 ) return 0 ;
V_45 = F_96 ( L_15 ) ;
V_46 = F_97 ( V_44 -> V_48 ) ;
V_47 = F_98 ( V_46 ) ;
while ( V_47 ) {
V_45 = F_99 ( V_45 , ( const T_8 * ) V_47 -> V_27 ) ;
V_47 = F_100 ( V_47 ) ;
if ( V_47 ) {
V_45 = F_101 ( V_45 , ',' ) ;
}
}
F_13 ( V_1 , V_45 -> V_49 ) ;
F_102 ( V_45 , TRUE ) ;
F_103 ( V_46 ) ;
F_10 ( 1 ) ;
}
static int F_104 ( T_2 * V_1 ) {
T_16 V_44 = F_95 ( V_1 , 1 ) ;
const T_8 * V_18 = F_36 ( V_1 , 2 ) ;
const T_8 * string ;
if ( ! ( V_44 && V_18 ) ) return 0 ;
if ( V_44 -> V_5 ) {
F_38 ( V_1 , L_16 ) ;
return 0 ;
}
string = ( const T_8 * ) F_105 ( V_44 -> V_48 , ( V_50 ) V_18 ) ;
if ( string ) {
F_13 ( V_1 , string ) ;
} else {
F_106 ( V_1 ) ;
}
return 1 ;
}
static int F_107 ( T_2 * V_1 ) {
T_16 V_44 = F_95 ( V_1 , 1 ) ;
const T_8 * V_18 = F_36 ( V_1 , 2 ) ;
const T_8 * string = NULL ;
if ( ! ( V_44 && V_18 ) ) return 0 ;
if ( V_44 -> V_5 ) {
F_38 ( V_1 , L_16 ) ;
return 0 ;
}
if ( F_108 ( V_1 , 3 ) ) {
string = F_36 ( V_1 , 3 ) ;
} else if ( F_109 ( V_1 , 3 ) ) {
string = F_110 ( V_1 , 3 ) ? L_15 : NULL ;
} else if ( ! F_111 ( V_1 , 3 ) ) {
F_38 ( V_1 , L_17 , F_112 ( V_1 , 3 ) ) ;
return 0 ;
}
if ( string ) {
F_113 ( V_44 -> V_48 , ( V_50 ) F_114 ( V_18 ) , ( V_50 ) F_114 ( string ) ) ;
} else {
F_115 ( V_44 -> V_48 , ( V_50 ) V_18 ) ;
}
return 1 ;
}
static int F_116 ( T_2 * V_1 ) {
T_16 V_44 = F_95 ( V_1 , 1 ) ;
if ( ! V_44 ) return 0 ;
if ( ! V_44 -> V_5 ) {
V_44 -> V_5 = TRUE ;
} else {
if ( V_44 -> V_51 ) {
F_117 ( V_44 -> V_48 ) ;
}
F_41 ( V_44 ) ;
}
return 0 ;
}
int F_118 ( T_2 * V_1 ) {
F_43 ( T_16 ) ;
return 1 ;
}
static int F_119 ( T_2 * V_1 ) { F_13 ( V_1 , L_18 ) ; return 1 ; }
static double
F_120 ( const V_8 * V_7 )
{
return ( ( ( double ) V_7 -> V_9 ) + ( ( ( double ) V_7 -> V_11 ) / 1000000000.0 ) ) ;
}
static double
F_121 ( const T_19 * V_52 , const T_19 * V_53 )
{
V_8 V_54 ;
F_122 ( V_52 , V_53 , & V_54 ) ;
return F_120 ( & V_54 ) ;
}
static int F_123 ( T_2 * V_1 ) {
T_1 V_3 = F_124 ( V_1 , 1 ) ;
if ( ! V_3 ) return 0 ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
if ( V_3 -> V_2 -> V_55 ) {
F_13 ( V_1 , V_3 -> V_2 -> V_55 ) ;
} else {
F_30 ( V_1 , ( V_17 ) ( V_3 -> V_2 -> V_56 ) ) ;
}
return 1 ;
}
static int F_125 ( T_2 * V_1 ) {
T_15 V_40 = NULL ;
T_1 V_3 = F_124 ( V_1 , 1 ) ;
const T_8 * V_41 = F_126 ( V_1 , 2 , NULL ) ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
V_40 = ( T_15 ) F_2 ( sizeof( struct V_57 ) ) ;
V_40 -> V_36 = V_3 -> V_2 -> V_36 ;
V_40 -> V_5 = FALSE ;
if ( ! V_41 ) {
F_127 ( V_1 , V_40 ) ;
} else {
F_128 ( V_1 , 0 ) ;
F_127 ( V_1 , V_40 ) ;
F_13 ( V_1 , V_41 ) ;
return F_90 ( V_1 ) ;
}
return 1 ;
}
static int F_129 ( T_2 * V_1 ) {
T_16 V_44 = NULL ;
T_1 V_3 = F_124 ( V_1 , 1 ) ;
const T_8 * V_58 = F_126 ( V_1 , 2 , NULL ) ;
T_7 V_51 = FALSE ;
if ( ! V_3 ) return 0 ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_16 ) ;
return 0 ;
}
if ( ! V_3 -> V_2 -> V_59 ) {
V_3 -> V_2 -> V_59 = F_130 ( V_60 , F_37 ) ;
V_51 = TRUE ;
}
V_44 = ( T_16 ) F_2 ( sizeof( struct V_61 ) ) ;
V_44 -> V_48 = V_3 -> V_2 -> V_59 ;
V_44 -> V_51 = V_51 ;
V_44 -> V_5 = FALSE ;
if ( ! V_58 ) {
F_131 ( V_1 , V_44 ) ;
} else {
F_128 ( V_1 , 0 ) ;
F_131 ( V_1 , V_44 ) ;
F_13 ( V_1 , V_58 ) ;
return F_104 ( V_1 ) ;
}
return 1 ;
}
static int F_132 ( T_2 * V_1 , T_3 * V_3 V_62 , T_20 T_21 V_62 ) {
F_106 ( V_1 ) ;
return 1 ;
}
static int F_133 ( T_2 * V_1 , T_3 * V_3 , T_20 T_21 ) {
const V_24 * V_63 = F_52 ( V_1 , 1 ) ;
V_24 * V_64 ;
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
F_134 ( ! L_21 ) ;
return 0 ;
}
F_135 ( V_64 , V_63 ) ;
return 0 ;
}
static int F_136 ( T_2 * V_1 , T_3 * V_3 , T_20 T_21 ) {
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
V_3 -> V_85 = ( T_11 ) V_77 ;
return 0 ;
case V_86 :
V_3 -> V_87 = ( int ) V_77 ;
return 0 ;
case V_88 :
V_3 -> V_89 = ( T_11 ) V_77 ;
return 0 ;
default:
F_134 ( ! L_21 ) ;
}
return 0 ;
}
static int F_137 ( T_2 * V_1 ) {
T_1 V_3 = F_124 ( V_1 , 1 ) ;
T_10 V_23 ;
if ( ! V_3 ) return 0 ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
V_23 = ( T_10 ) F_2 ( sizeof( V_24 ) ) ;
if ( F_58 ( & ( V_3 -> V_2 -> V_66 ) , & ( V_3 -> V_2 -> V_68 ) ) >= 0 ) {
F_135 ( V_23 , & ( V_3 -> V_2 -> V_66 ) ) ;
} else {
F_135 ( V_23 , & ( V_3 -> V_2 -> V_68 ) ) ;
}
F_50 ( V_1 , V_23 ) ;
return 1 ;
}
static int F_138 ( T_2 * V_1 ) {
T_1 V_3 = F_124 ( V_1 , 1 ) ;
T_10 V_23 ;
if ( ! V_3 ) return 0 ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
V_23 = ( T_10 ) F_2 ( sizeof( V_24 ) ) ;
if ( F_58 ( & ( V_3 -> V_2 -> V_66 ) , & ( V_3 -> V_2 -> V_68 ) ) < 0 ) {
F_135 ( V_23 , & ( V_3 -> V_2 -> V_66 ) ) ;
} else {
F_135 ( V_23 , & ( V_3 -> V_2 -> V_68 ) ) ;
}
F_50 ( V_1 , V_23 ) ;
return 1 ;
}
static int F_139 ( T_2 * V_1 ) {
F_106 ( V_1 ) ;
return 1 ;
}
static int F_140 ( T_2 * V_1 ) {
T_1 V_3 = F_124 ( V_1 , 1 ) ;
const T_8 * V_18 = F_36 ( V_1 , 2 ) ;
T_23 V_90 = F_139 ;
const T_24 * V_91 ;
if ( ! ( V_3 && V_18 ) ) {
F_106 ( V_1 ) ;
return 1 ;
}
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
for ( V_91 = V_92 ; V_91 -> V_18 ; V_91 ++ ) {
if ( F_37 ( V_91 -> V_18 , V_18 ) ) {
V_90 = V_91 -> V_21 ;
break;
}
}
F_128 ( V_1 , 1 ) ;
return V_90 ( V_1 ) ;
}
static int F_141 ( T_2 * V_1 ) {
T_1 V_3 = F_124 ( V_1 , 1 ) ;
const T_8 * V_18 = F_36 ( V_1 , 2 ) ;
int (* V_90)( T_2 * , T_3 * V_3 , T_20 ) = F_132 ;
const T_24 * V_91 ;
T_20 V_93 = V_94 ;
if ( ! ( V_3 && V_18 ) ) {
return 0 ;
}
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_19 ) ;
return 0 ;
}
for ( V_91 = V_92 ; V_91 -> V_18 ; V_91 ++ ) {
if ( F_37 ( V_91 -> V_18 , V_18 ) ) {
V_90 = V_91 -> V_22 ;
V_93 = V_91 -> V_95 ;
break;
}
}
F_142 ( V_1 , 1 ) ;
F_142 ( V_1 , 1 ) ;
return V_90 ( V_1 , V_3 -> V_2 , V_93 ) ;
}
static int F_143 ( T_2 * V_1 ) {
T_1 V_3 = F_124 ( V_1 , 1 ) ;
if ( ! V_3 ) return 0 ;
if ( ! V_3 -> V_5 )
V_3 -> V_5 = TRUE ;
else
F_41 ( V_3 ) ;
return 0 ;
}
int F_144 ( T_2 * V_1 ) {
F_43 ( T_1 ) ;
V_6 = F_145 () ;
V_96 = F_145 () ;
V_97 = F_145 () ;
V_98 = F_145 () ;
return 1 ;
}
