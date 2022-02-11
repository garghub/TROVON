T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 ) {
T_1 V_3 = NULL ;
if ( V_2 ) {
V_3 = F_2 ( sizeof( struct V_4 ) ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_5 = FALSE ;
F_3 ( V_6 , V_3 ) ;
}
return F_4 ( V_1 , V_3 ) ;
}
T_4 F_5 ( T_2 * V_1 ) {
#define F_6 1
#define F_7 2
T_5 time = F_2 ( sizeof( V_7 ) ) ;
if ( ! time ) return 0 ;
time -> V_8 = ( V_9 ) F_8 ( V_1 , F_6 , 0 ) ;
time -> V_10 = F_8 ( V_1 , F_7 , 0 ) ;
F_9 ( V_1 , time ) ;
F_10 ( 1 ) ;
}
T_6 F_11 ( T_2 * V_1 ) {
T_5 V_11 = F_12 ( V_1 , 1 ) ;
if ( ! V_11 ) return 0 ;
F_13 ( V_1 , F_14 ( L_1 , ( long ) V_11 -> V_8 , V_11 -> V_10 ) ) ;
F_10 ( 1 ) ;
}
T_6 F_15 ( T_2 * V_1 ) {
T_5 V_12 = F_12 ( V_1 , 1 ) ;
T_5 V_13 = F_12 ( V_1 , 2 ) ;
T_5 V_14 = F_2 ( sizeof ( V_7 ) ) ;
F_16 ( V_14 , V_12 , V_13 ) ;
F_9 ( V_1 , V_14 ) ;
return 1 ;
}
T_6 F_17 ( T_2 * V_1 ) {
T_5 V_12 = F_12 ( V_1 , 1 ) ;
T_5 V_13 = F_12 ( V_1 , 2 ) ;
T_5 V_14 = F_2 ( sizeof ( V_7 ) ) ;
F_18 ( V_14 , V_12 , V_13 ) ;
F_9 ( V_1 , V_14 ) ;
return 1 ;
}
T_6 F_19 ( T_2 * V_1 ) {
T_5 V_12 = F_12 ( V_1 , 1 ) ;
T_5 V_13 = F_2 ( sizeof ( V_7 ) ) ;
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
T_5 time = F_29 ( V_1 , 1 ) ;
F_30 ( V_1 , ( V_17 ) ( time -> V_8 ) ) ;
return 1 ;
}
static int F_31 ( T_2 * V_1 )
{
T_5 time = F_29 ( V_1 , 1 ) ;
V_9 V_8 = F_32 ( V_1 , 3 ) ;
time -> V_8 = V_8 ;
return 0 ;
}
static int F_33 ( T_2 * V_1 ) {
T_5 time = F_29 ( V_1 , 1 ) ;
F_30 ( V_1 , ( V_17 ) ( time -> V_10 ) ) ;
return 1 ;
}
static int F_34 ( T_2 * V_1 ) {
T_5 time = F_29 ( V_1 , 1 ) ;
int V_10 = F_32 ( V_1 , 3 ) ;
time -> V_10 = V_10 ;
return 0 ;
}
static int F_35 ( T_2 * V_1 ) {
T_5 time = F_12 ( V_1 , 1 ) ;
const T_8 * V_18 = F_36 ( V_1 , 2 ) ;
const T_9 * V_19 ;
if ( ! ( time && V_18 ) ) return 0 ;
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
T_5 time = F_12 ( V_1 , 1 ) ;
const T_8 * V_18 = F_36 ( V_1 , 2 ) ;
const T_9 * V_19 ;
if ( ! ( time && V_18 ) ) return 0 ;
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
T_5 V_11 = F_12 ( V_1 , 1 ) ;
if ( ! V_11 ) return 0 ;
F_41 ( V_11 ) ;
return 0 ;
}
int F_42 ( T_2 * V_1 ) {
F_43 ( T_5 ) ;
F_13 ( V_1 , L_6 ) ;
F_44 ( V_1 , F_5 ) ;
F_45 ( V_1 , V_23 ) ;
return 1 ;
}
T_4 F_46 ( T_2 * V_1 ) {
#define F_47 1
T_10 V_24 = F_2 ( sizeof( V_25 ) ) ;
T_11 * V_26 = F_2 ( sizeof( T_11 ) ) ;
const T_8 * V_18 = F_36 ( V_1 , F_47 ) ;
if ( ! F_48 ( V_18 , ( T_11 * ) V_26 ) ) {
* V_26 = 0 ;
}
F_49 ( V_24 , V_27 , 4 , V_26 ) ;
F_50 ( V_1 , V_24 ) ;
F_10 ( 1 ) ;
}
T_6 F_51 ( T_2 * V_1 ) {
T_10 V_24 = F_52 ( V_1 , 1 ) ;
F_13 ( V_1 , F_53 ( V_24 ) ) ;
F_10 ( 1 ) ;
}
static int F_54 ( T_2 * V_1 ) {
T_10 V_24 = F_52 ( V_1 , 1 ) ;
if ( V_24 ) {
F_41 ( ( void * ) V_24 -> V_28 ) ;
F_41 ( ( void * ) V_24 ) ;
}
return 0 ;
}
T_6 F_55 ( T_2 * V_1 ) {
T_10 V_29 = F_52 ( V_1 , 1 ) ;
T_10 V_30 = F_52 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_56 ( V_29 , V_30 ) )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_57 ( T_2 * V_1 ) {
T_10 V_29 = F_52 ( V_1 , 1 ) ;
T_10 V_30 = F_52 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_58 ( V_29 , V_30 ) <= 0 )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
T_6 F_59 ( T_2 * V_1 ) {
T_10 V_29 = F_52 ( V_1 , 1 ) ;
T_10 V_30 = F_52 ( V_1 , 2 ) ;
T_7 V_15 = FALSE ;
if ( F_58 ( V_29 , V_30 ) < 0 )
V_15 = TRUE ;
F_25 ( V_1 , V_15 ) ;
return 1 ;
}
int F_60 ( T_2 * V_1 ) {
F_61 ( T_10 ) ;
return 1 ;
}
static T_12 F_62 ( const T_8 * V_18 ) {
const struct V_31 * V_32 ;
for( V_32 = V_33 ; V_32 -> V_18 ; V_32 ++ ) {
if ( F_37 ( V_32 -> V_18 , V_18 ) ) {
return V_32 -> V_34 ;
}
}
return 0 ;
}
static const T_8 * F_63 ( T_12 V_34 ) {
const struct V_31 * V_32 ;
for( V_32 = V_33 ; V_32 -> V_18 ; V_32 ++ ) {
if ( V_32 -> V_34 == V_34 ) {
return V_32 -> V_18 ;
}
}
return NULL ;
}
T_6 F_64 ( T_2 * V_1 ) {
T_13 V_35 = F_65 ( V_1 , 1 ) ;
const T_8 * V_18 ;
if ( ! ( V_35 ) ) {
return 0 ;
}
V_18 = F_63 ( V_35 -> V_36 ) ;
F_13 ( V_1 , V_18 ? V_18 : L_7 ) ;
F_10 ( 1 ) ;
}
static int F_66 ( T_2 * V_1 ) {
T_13 V_36 = F_65 ( V_1 , 1 ) ;
if ( ! V_36 ) return 0 ;
if ( ! V_36 -> V_5 )
V_36 -> V_5 = TRUE ;
else
F_41 ( V_36 ) ;
return 0 ;
}
T_14 F_67 ( T_2 * V_1 ) {
T_13 V_35 = F_65 ( V_1 , 1 ) ;
if ( ! ( V_35 && V_35 -> V_37 ) ) return 0 ;
F_68 ( V_35 -> V_37 , V_35 -> V_36 ) ;
return 0 ;
}
T_14 F_69 ( T_2 * V_1 ) {
#define F_70 2
T_13 V_35 = F_65 ( V_1 , 1 ) ;
const T_8 * V_38 = F_36 ( V_1 , F_70 ) ;
if ( ! ( V_35 && V_35 -> V_37 ) )
return 0 ;
if ( ! V_38 ) F_71 ( F_69 , V_39 , L_8 ) ;
F_72 ( V_35 -> V_37 , V_35 -> V_36 , V_38 ) ;
return 0 ;
}
T_14 F_73 ( T_2 * V_1 ) {
#define F_74 2
T_13 V_35 = F_65 ( V_1 , 1 ) ;
const T_8 * V_38 = F_36 ( V_1 , F_74 ) ;
if ( ! ( V_35 && V_35 -> V_37 ) )
return 0 ;
if ( ! V_38 ) F_71 ( F_73 , V_39 , L_8 ) ;
F_75 ( V_35 -> V_37 , V_35 -> V_36 , V_38 ) ;
return 0 ;
}
T_14 F_76 ( T_2 * V_1 ) {
#define F_77 2
T_13 V_35 = F_65 ( V_1 , 1 ) ;
const T_8 * V_38 = F_36 ( V_1 , F_77 ) ;
if ( ! ( V_35 && V_35 -> V_37 ) )
return 0 ;
if ( ! V_38 ) F_71 ( V_40 , V_39 , L_8 ) ;
if ( F_78 ( V_35 -> V_37 , V_35 -> V_36 ) )
F_79 ( V_35 -> V_37 , V_35 -> V_36 , L_9 , V_38 ) ;
return 0 ;
}
int F_80 ( T_2 * V_1 ) {
F_61 ( T_13 ) ;
return 1 ;
}
T_6 F_81 ( T_2 * V_1 ) {
F_13 ( V_1 , L_10 ) ;
F_10 ( 1 ) ;
}
T_6 F_82 ( T_2 * V_1 ) {
#define F_83 2
#define F_84 3
T_15 V_41 = F_85 ( V_1 , 1 ) ;
const struct V_31 * V_32 ;
const char * V_42 ;
const char * V_43 ;
if ( ! V_41 ) return 0 ;
if ( V_41 -> V_5 ) {
F_38 ( V_1 , L_11 ) ;
return 0 ;
}
V_42 = F_36 ( V_1 , F_83 ) ;
V_43 = F_36 ( V_1 , F_84 ) ;
for( V_32 = V_33 ; V_32 -> V_18 ; V_32 ++ ) {
if( F_37 ( V_32 -> V_18 , V_42 ) ) {
F_72 ( V_41 -> V_37 , V_32 -> V_34 , V_43 ) ;
return 0 ;
}
}
F_71 ( F_82 , V_44 , L_12 ) ;
}
T_6 F_86 ( T_2 * V_1 ) {
T_15 V_41 = F_85 ( V_1 , 1 ) ;
const struct V_31 * V_32 ;
const char * V_42 = F_36 ( V_1 , 2 ) ;
if ( ! V_41 ) {
T_13 V_35 = F_2 ( sizeof( struct V_45 ) ) ;
V_35 -> V_37 = NULL ;
V_35 -> V_36 = F_62 ( V_42 ) ;
V_35 -> V_5 = FALSE ;
F_87 ( V_1 , V_35 ) ;
return 1 ;
}
if ( V_41 -> V_5 ) {
F_38 ( V_1 , L_11 ) ;
return 0 ;
}
if ( ! V_42 ) return 0 ;
for( V_32 = V_33 ; V_32 -> V_18 ; V_32 ++ ) {
if( F_37 ( V_32 -> V_18 , V_42 ) ) {
T_13 V_35 = F_2 ( sizeof( struct V_45 ) ) ;
V_35 -> V_37 = V_41 -> V_37 ;
V_35 -> V_36 = F_62 ( V_42 ) ;
V_35 -> V_5 = FALSE ;
F_87 ( V_1 , V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_88 ( T_2 * V_1 ) {
T_15 V_41 = F_85 ( V_1 , 1 ) ;
if ( ! V_41 ) return 0 ;
if ( ! V_41 -> V_5 )
V_41 -> V_5 = TRUE ;
else
F_41 ( V_41 ) ;
return 0 ;
}
int F_89 ( T_2 * V_1 ) {
F_43 ( T_15 ) ;
return 1 ;
}
T_6 F_90 ( T_2 * V_1 ) {
T_16 V_46 = F_91 ( V_1 , 1 ) ;
T_17 * V_47 ;
T_18 * V_48 , * V_49 ;
if ( ! V_46 ) return 0 ;
V_47 = F_92 ( L_13 ) ;
V_48 = F_93 ( V_46 -> V_50 ) ;
V_49 = F_94 ( V_48 ) ;
while ( V_49 ) {
V_47 = F_95 ( V_47 , V_49 -> V_28 ) ;
V_49 = F_96 ( V_49 ) ;
if ( V_49 ) {
V_47 = F_97 ( V_47 , ',' ) ;
}
}
F_13 ( V_1 , V_47 -> V_51 ) ;
F_98 ( V_47 , TRUE ) ;
F_99 ( V_48 ) ;
F_10 ( 1 ) ;
}
static int F_100 ( T_2 * V_1 ) {
T_16 V_46 = F_91 ( V_1 , 1 ) ;
const T_8 * V_18 = F_36 ( V_1 , 2 ) ;
const T_8 * string ;
if ( ! ( V_46 && V_18 ) ) return 0 ;
if ( V_46 -> V_5 ) {
F_38 ( V_1 , L_14 ) ;
return 0 ;
}
string = F_101 ( V_46 -> V_50 , ( V_52 ) V_18 ) ;
if ( string ) {
F_13 ( V_1 , string ) ;
} else {
F_102 ( V_1 ) ;
}
return 1 ;
}
static int F_103 ( T_2 * V_1 ) {
T_16 V_46 = F_91 ( V_1 , 1 ) ;
const T_8 * V_18 = F_36 ( V_1 , 2 ) ;
const T_8 * string = NULL ;
if ( ! ( V_46 && V_18 ) ) return 0 ;
if ( V_46 -> V_5 ) {
F_38 ( V_1 , L_14 ) ;
return 0 ;
}
if ( F_104 ( V_1 , 3 ) ) {
string = F_36 ( V_1 , 3 ) ;
} else if ( F_105 ( V_1 , 3 ) ) {
string = F_106 ( V_1 , 3 ) ? L_13 : NULL ;
} else if ( ! F_107 ( V_1 , 3 ) ) {
F_38 ( V_1 , L_15 , F_108 ( V_1 , 3 ) ) ;
return 0 ;
}
if ( string ) {
F_109 ( V_46 -> V_50 , ( V_52 ) F_110 ( V_18 ) , ( V_52 ) F_110 ( string ) ) ;
} else {
F_111 ( V_46 -> V_50 , ( V_52 ) V_18 ) ;
}
return 1 ;
}
static int F_112 ( T_2 * V_1 ) {
T_16 V_46 = F_91 ( V_1 , 1 ) ;
if ( ! V_46 ) return 0 ;
if ( ! V_46 -> V_5 ) {
V_46 -> V_5 = TRUE ;
} else {
if ( V_46 -> V_53 ) {
F_113 ( V_46 -> V_50 ) ;
}
F_41 ( V_46 ) ;
}
return 0 ;
}
int F_114 ( T_2 * V_1 ) {
F_43 ( T_16 ) ;
return 1 ;
}
static int F_115 ( T_2 * V_1 ) { F_13 ( V_1 , L_16 ) ; return 1 ; }
static int F_116 ( T_2 * V_1 ) {
T_1 V_3 = F_117 ( V_1 , 1 ) ;
if ( ! V_3 ) return 0 ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_17 ) ;
return 0 ;
}
if ( V_3 -> V_2 -> V_54 ) {
F_13 ( V_1 , V_3 -> V_2 -> V_54 ) ;
} else {
F_30 ( V_1 , ( V_17 ) ( V_3 -> V_2 -> V_55 ) ) ;
}
return 1 ;
}
static int F_118 ( T_2 * V_1 ) {
T_15 V_41 = NULL ;
T_1 V_3 = F_117 ( V_1 , 1 ) ;
const T_8 * V_42 = F_119 ( V_1 , 2 , NULL ) ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_17 ) ;
return 0 ;
}
V_41 = F_2 ( sizeof( struct V_56 ) ) ;
V_41 -> V_37 = V_3 -> V_2 -> V_37 ;
V_41 -> V_5 = FALSE ;
if ( ! V_42 ) {
F_120 ( V_1 , V_41 ) ;
} else {
F_121 ( V_1 , 0 ) ;
F_120 ( V_1 , V_41 ) ;
F_13 ( V_1 , V_42 ) ;
return F_86 ( V_1 ) ;
}
return 1 ;
}
static int F_122 ( T_2 * V_1 ) {
T_16 V_46 = NULL ;
T_1 V_3 = F_117 ( V_1 , 1 ) ;
const T_8 * V_57 = F_119 ( V_1 , 2 , NULL ) ;
T_7 V_53 = FALSE ;
if ( ! V_3 ) return 0 ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_14 ) ;
return 0 ;
}
if ( ! V_3 -> V_2 -> V_58 ) {
V_3 -> V_2 -> V_58 = F_123 ( V_59 , F_37 ) ;
V_53 = TRUE ;
}
V_46 = F_2 ( sizeof( struct V_60 ) ) ;
V_46 -> V_50 = V_3 -> V_2 -> V_58 ;
V_46 -> V_53 = V_53 ;
V_46 -> V_5 = FALSE ;
if ( ! V_57 ) {
F_124 ( V_1 , V_46 ) ;
} else {
F_121 ( V_1 , 0 ) ;
F_124 ( V_1 , V_46 ) ;
F_13 ( V_1 , V_57 ) ;
return F_100 ( V_1 ) ;
}
return 1 ;
}
static int F_125 ( T_2 * V_1 , T_3 * V_3 V_61 , T_19 T_20 V_61 ) {
F_102 ( V_1 ) ;
return 1 ;
}
static int F_126 ( T_2 * V_1 , T_3 * V_3 , T_19 T_20 ) {
const V_25 * V_62 = F_52 ( V_1 , 1 ) ;
V_25 * V_63 ;
if ( ! V_62 ) {
F_38 ( V_1 , L_18 ) ;
return 0 ;
}
if ( ! V_3 ) {
F_38 ( V_1 , L_17 ) ;
return 0 ;
}
switch( T_20 ) {
case V_64 :
V_63 = & ( V_3 -> V_65 ) ;
break;
case V_66 :
V_63 = & ( V_3 -> V_67 ) ;
break;
case V_68 :
V_63 = & ( V_3 -> V_69 ) ;
break;
case V_70 :
V_63 = & ( V_3 -> V_71 ) ;
break;
case V_72 :
V_63 = & ( V_3 -> V_73 ) ;
break;
case V_74 :
V_63 = & ( V_3 -> V_75 ) ;
break;
default:
F_127 ( ! L_19 ) ;
return 0 ;
}
F_128 ( V_63 , V_62 ) ;
return 0 ;
}
static int F_129 ( T_2 * V_1 , T_3 * V_3 , T_19 T_20 ) {
T_21 V_76 = F_32 ( V_1 , 1 ) ;
if ( ! V_3 ) {
F_38 ( V_1 , L_17 ) ;
return 0 ;
}
switch( T_20 ) {
case V_77 :
V_3 -> V_78 = ( T_11 ) V_76 ;
return 0 ;
case V_79 :
V_3 -> V_80 = ( T_11 ) V_76 ;
return 0 ;
case V_81 :
V_3 -> V_82 = ( T_11 ) V_76 ;
return 0 ;
case V_83 :
V_3 -> V_84 = ( T_11 ) V_76 ;
return 0 ;
case V_85 :
V_3 -> V_86 = ( int ) V_76 ;
return 0 ;
case V_87 :
V_3 -> V_88 = ( T_11 ) V_76 ;
return 0 ;
default:
F_127 ( ! L_19 ) ;
}
return 0 ;
}
static int F_130 ( T_2 * V_1 ) {
T_1 V_3 = F_117 ( V_1 , 1 ) ;
T_10 V_24 ;
if ( ! V_3 ) return 0 ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_17 ) ;
return 0 ;
}
V_24 = F_2 ( sizeof( V_25 ) ) ;
if ( F_58 ( & ( V_3 -> V_2 -> V_65 ) , & ( V_3 -> V_2 -> V_67 ) ) >= 0 ) {
F_128 ( V_24 , & ( V_3 -> V_2 -> V_65 ) ) ;
} else {
F_128 ( V_24 , & ( V_3 -> V_2 -> V_67 ) ) ;
}
F_50 ( V_1 , V_24 ) ;
return 1 ;
}
static int F_131 ( T_2 * V_1 ) {
T_1 V_3 = F_117 ( V_1 , 1 ) ;
T_10 V_24 ;
if ( ! V_3 ) return 0 ;
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_17 ) ;
return 0 ;
}
V_24 = F_2 ( sizeof( V_25 ) ) ;
if ( F_58 ( & ( V_3 -> V_2 -> V_65 ) , & ( V_3 -> V_2 -> V_67 ) ) < 0 ) {
F_128 ( V_24 , & ( V_3 -> V_2 -> V_65 ) ) ;
} else {
F_128 ( V_24 , & ( V_3 -> V_2 -> V_67 ) ) ;
}
F_50 ( V_1 , V_24 ) ;
return 1 ;
}
static int F_132 ( T_2 * V_1 ) {
F_102 ( V_1 ) ;
return 1 ;
}
static int F_133 ( T_2 * V_1 ) {
T_1 V_3 = F_117 ( V_1 , 1 ) ;
const T_8 * V_18 = F_36 ( V_1 , 2 ) ;
T_22 V_89 = F_132 ;
const T_23 * V_90 ;
if ( ! ( V_3 && V_18 ) ) {
F_102 ( V_1 ) ;
return 1 ;
}
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_17 ) ;
return 0 ;
}
for ( V_90 = V_91 ; V_90 -> V_18 ; V_90 ++ ) {
if ( F_37 ( V_90 -> V_18 , V_18 ) ) {
V_89 = V_90 -> V_21 ;
break;
}
}
F_121 ( V_1 , 1 ) ;
return V_89 ( V_1 ) ;
}
static int F_134 ( T_2 * V_1 ) {
T_1 V_3 = F_117 ( V_1 , 1 ) ;
const T_8 * V_18 = F_36 ( V_1 , 2 ) ;
int (* V_89)( T_2 * , T_3 * V_3 , T_19 ) = F_125 ;
const T_23 * V_90 ;
T_19 V_92 = V_93 ;
if ( ! ( V_3 && V_18 ) ) {
return 0 ;
}
if ( V_3 -> V_5 ) {
F_38 ( V_1 , L_17 ) ;
return 0 ;
}
for ( V_90 = V_91 ; V_90 -> V_18 ; V_90 ++ ) {
if ( F_37 ( V_90 -> V_18 , V_18 ) ) {
V_89 = V_90 -> V_22 ;
V_92 = V_90 -> V_94 ;
break;
}
}
F_135 ( V_1 , 1 ) ;
F_135 ( V_1 , 1 ) ;
return V_89 ( V_1 , V_3 -> V_2 , V_92 ) ;
}
static int F_136 ( T_2 * V_1 ) {
T_1 V_3 = F_117 ( V_1 , 1 ) ;
if ( ! V_3 ) return 0 ;
if ( ! V_3 -> V_5 )
V_3 -> V_5 = TRUE ;
else
F_41 ( V_3 ) ;
return 0 ;
}
int F_137 ( T_2 * V_1 ) {
F_43 ( T_1 ) ;
V_6 = F_138 () ;
V_95 = F_138 () ;
V_96 = F_138 () ;
V_97 = F_138 () ;
return 1 ;
}
