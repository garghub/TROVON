T_1 F_1 ( T_2 * V_1 ) {
#define F_2 1
const T_3 * V_2 = F_3 ( V_1 , F_2 ) ;
T_4 V_3 ;
if ( ( V_3 = F_4 ( V_2 ) ) ) {
F_5 ( V_1 , V_3 ) ;
F_6 ( 1 ) ;
}
F_7 ( F_1 , V_4 , L_1 ) ;
return 0 ;
}
static T_5
F_8 ( T_6 V_5 , T_6 V_6 )
{
return strcmp ( ( const char * ) V_5 , ( const char * ) V_6 ) ;
}
T_1 F_9 ( T_2 * V_1 ) {
T_7 * V_7 = F_10 () ;
T_7 * V_8 = NULL ;
int V_9 = 1 ;
if ( ! V_7 ) return F_11 ( V_1 , L_2 ) ;
V_7 = F_12 ( V_7 , ( V_10 ) F_8 ) ;
V_8 = F_13 ( V_7 ) ;
F_14 ( V_1 ) ;
for ( V_9 = 1 ; V_8 ; V_9 ++ , V_8 = F_15 ( V_8 ) ) {
F_16 ( V_1 , ( const char * ) V_8 -> V_11 ) ;
F_17 ( V_1 , 1 , V_9 ) ;
}
F_18 ( V_7 ) ;
F_6 ( 1 ) ;
}
T_8 F_19 ( T_2 * V_1 ) {
#define F_20 2
#define F_21 3
#define F_22 4
T_4 volatile V_3 = F_23 ( V_1 , 1 ) ;
T_9 V_12 = F_24 ( V_1 , F_20 ) ;
T_10 V_13 = F_25 ( V_1 , F_21 ) ;
T_11 V_14 = F_26 ( V_1 , F_22 ) ;
const char * volatile error = NULL ;
int V_15 = 0 ;
if ( ! ( V_3 && V_12 && V_13 ) ) return 0 ;
F_27 {
V_15 = F_28 ( V_3 , V_12 -> V_16 , V_13 -> V_17 , V_14 -> V_18 ) ;
} F_29 {
F_30 ( V_12 -> V_16 , V_13 -> V_17 , V_14 -> V_18 , V_19 , V_20 ) ;
error = L_3 ;
} V_21 ;
if ( error ) { F_31 ( F_19 , error ) ; }
F_32 ( V_1 , ( V_22 ) V_15 ) ;
F_6 ( 1 ) ;
}
T_12 F_33 ( T_2 * V_1 ) {
#define F_34 2
#define F_35 3
#define F_36 4
return F_19 ( V_1 ) ;
}
T_12 F_37 ( T_2 * V_1 ) {
T_4 V_3 = F_23 ( V_1 , 1 ) ;
if ( ! V_3 ) return 0 ;
F_16 ( V_1 , F_38 ( V_3 ) ) ;
F_6 ( 1 ) ;
}
static int F_39 ( T_2 * V_1 V_23 ) {
return 0 ;
}
int F_40 ( T_2 * V_1 ) {
F_41 ( T_4 ) ;
return 0 ;
}
T_1 F_42 ( T_2 * V_1 ) {
#define F_43 1
#define F_44 2
#define F_45 3
#define F_46 4
const T_3 * V_2 = ( const T_3 * ) F_3 ( V_1 , F_43 ) ;
const T_3 * V_24 = ( const T_3 * ) F_47 ( V_1 , F_44 , V_2 ) ;
enum V_25 type = (enum V_25 ) F_48 ( V_1 , F_45 , V_26 ) ;
unsigned V_27 = ( unsigned ) F_48 ( V_1 , F_46 , V_28 ) ;
switch( type ) {
case V_29 :
V_27 = V_30 ;
case V_31 :
case V_32 :
case V_33 :
case V_26 :
{
T_13 V_34 = ( T_13 ) F_49 ( sizeof( struct V_35 ) ) ;
V_2 = F_50 ( V_2 ) ;
V_24 = F_50 ( V_24 ) ;
V_34 -> V_36 = F_51 ( V_2 , V_24 , - 1 , type , V_27 ) ;
V_34 -> V_2 = V_2 ;
V_34 -> V_24 = V_24 ;
V_34 -> V_37 = TRUE ;
V_34 -> V_38 = FALSE ;
F_52 ( V_1 , V_39 , V_40 ) ;
F_16 ( V_1 , V_2 ) ;
F_53 ( V_1 , V_34 ) ;
F_54 ( V_1 , - 3 ) ;
F_53 ( V_1 , V_34 ) ;
}
F_6 ( 1 ) ;
default:
F_55 ( F_42 , TYPE , L_4 ) ;
break;
}
return 0 ;
}
static void
F_56 ( const T_3 * V_41 , const T_3 * V_24 V_23 , T_14 V_42 ) {
T_15 * V_11 = ( T_15 * ) V_42 ;
F_16 ( V_11 -> V_1 , V_41 ) ;
F_17 ( V_11 -> V_1 , 1 , V_11 -> V_43 ) ;
V_11 -> V_43 = V_11 -> V_43 + 1 ;
}
T_1 F_57 ( T_2 * V_1 ) {
T_15 V_11 = { 1 , V_1 } ;
F_14 ( V_1 ) ;
F_58 ( F_56 , ( T_14 ) & V_11 ,
( V_10 ) F_8 ) ;
F_6 ( 1 ) ;
}
static void
F_59 ( const T_3 * V_41 , struct V_44 * V_36 V_23 , T_14 V_42 ) {
T_15 * V_11 = ( T_15 * ) V_42 ;
F_16 ( V_11 -> V_1 , V_41 ) ;
F_17 ( V_11 -> V_1 , 1 , V_11 -> V_43 ) ;
V_11 -> V_43 = V_11 -> V_43 + 1 ;
}
T_1 F_60 ( T_2 * V_1 ) {
T_15 V_11 = { 1 , V_1 } ;
F_14 ( V_1 ) ;
F_61 ( F_59 , ( T_14 ) & V_11 , NULL ) ;
F_6 ( 1 ) ;
}
T_1 F_62 ( T_2 * V_1 ) {
#define F_63 1
const T_3 * V_2 = F_3 ( V_1 , F_63 ) ;
T_16 V_36 = F_64 ( V_2 ) ;
if ( V_36 ) {
T_13 V_34 = ( T_13 ) F_49 ( sizeof( struct V_35 ) ) ;
V_34 -> V_36 = V_36 ;
V_34 -> V_2 = F_50 ( V_2 ) ;
V_34 -> V_24 = NULL ;
V_34 -> V_37 = FALSE ;
V_34 -> V_38 = FALSE ;
F_53 ( V_1 , V_34 ) ;
F_6 ( 1 ) ;
}
F_7 ( F_62 , V_45 , L_5 ) ;
return 0 ;
}
T_8 F_65 ( T_2 * V_1 ) {
#define F_66 2
#define F_67 3
T_13 V_34 = F_68 ( V_1 , 1 ) ;
T_17 type ;
T_4 V_46 ;
if ( ! V_34 ) return 0 ;
if( F_69 ( V_1 , F_67 ) ) {
T_18 V_47 ;
V_47 = F_70 ( V_1 , F_67 ) ;
V_46 = V_47 -> V_46 ;
if ( ! V_46 ) {
F_7 ( F_65 , V_48 , L_6 ) ;
return 0 ;
}
} else if ( F_71 ( V_1 , F_67 ) ) {
V_46 = F_72 ( V_1 , F_67 ) ;
} else {
F_7 ( F_65 , V_48 , L_7 ) ;
return 0 ;
}
type = F_73 ( V_34 -> V_2 ) ;
if ( type == V_29 ) {
T_3 * V_49 = F_50 ( F_3 ( V_1 , F_66 ) ) ;
F_74 ( V_34 -> V_2 , V_49 , V_46 ) ;
F_75 ( V_49 ) ;
} else if ( type == V_26 || type == V_32 || type == V_31 || type == V_33 ) {
if ( F_76 ( V_1 , F_66 ) ) {
int V_50 = ( int ) F_77 ( V_1 , F_66 ) ;
F_78 ( V_34 -> V_2 , V_50 , V_46 ) ;
} else {
const T_3 * V_49 = F_3 ( V_1 , F_66 ) ;
T_19 * V_51 = NULL ;
if ( F_79 ( NULL , & V_51 , V_49 , V_52 ) == V_53 ) {
F_80 ( V_34 -> V_2 , V_51 , V_46 ) ;
} else {
F_81 ( NULL , V_51 ) ;
F_7 ( F_65 , V_54 , L_8 ) ;
return 0 ;
}
F_81 ( NULL , V_51 ) ;
}
} else {
F_11 ( V_1 , L_9 , type ) ;
}
return 0 ;
}
T_8 F_82 ( T_2 * V_1 ) {
#define F_83 2
#define F_84 3
T_13 V_34 = F_68 ( V_1 , 1 ) ;
T_17 type ;
T_4 V_46 ;
if ( ! V_34 ) return 0 ;
if( F_69 ( V_1 , F_84 ) ) {
T_18 V_47 ;
V_47 = F_70 ( V_1 , F_84 ) ;
V_46 = V_47 -> V_46 ;
if ( ! V_46 ) {
F_7 ( F_82 , V_48 , L_10 ) ;
return 0 ;
}
} else if ( F_71 ( V_1 , F_84 ) ) {
V_46 = F_72 ( V_1 , F_84 ) ;
} else {
F_7 ( F_82 , V_48 , L_7 ) ;
return 0 ;
}
type = F_73 ( V_34 -> V_2 ) ;
if ( type == V_29 ) {
const T_3 * V_49 = F_3 ( V_1 , F_83 ) ;
F_85 ( V_34 -> V_2 , V_46 ) ;
F_74 ( V_34 -> V_2 , V_49 , V_46 ) ;
} else if ( type == V_26 || type == V_32 || type == V_31 || type == V_33 ) {
if ( F_76 ( V_1 , F_83 ) ) {
int V_50 = ( int ) F_77 ( V_1 , F_83 ) ;
F_85 ( V_34 -> V_2 , V_46 ) ;
F_78 ( V_34 -> V_2 , V_50 , V_46 ) ;
} else {
const T_3 * V_49 = F_3 ( V_1 , F_83 ) ;
T_19 * V_51 = NULL ;
if ( F_79 ( NULL , & V_51 , V_49 , V_52 ) == V_53 ) {
F_85 ( V_34 -> V_2 , V_46 ) ;
F_80 ( V_34 -> V_2 , V_51 , V_46 ) ;
} else {
F_81 ( NULL , V_51 ) ;
F_7 ( F_82 , V_54 , L_8 ) ;
return 0 ;
}
F_81 ( NULL , V_51 ) ;
}
} else {
F_11 ( V_1 , L_9 , type ) ;
}
return 0 ;
}
T_8 F_86 ( T_2 * V_1 ) {
#define F_87 2
#define F_88 3
T_13 V_34 = F_68 ( V_1 , 1 ) ;
T_17 type ;
T_4 V_46 ;
if ( ! V_34 ) return 0 ;
if( F_69 ( V_1 , F_88 ) ) {
T_18 V_47 ;
V_47 = F_70 ( V_1 , F_88 ) ;
V_46 = V_47 -> V_46 ;
} else if ( F_71 ( V_1 , F_88 ) ) {
V_46 = F_72 ( V_1 , F_88 ) ;
} else {
F_7 ( F_86 , V_48 , L_7 ) ;
return 0 ;
}
type = F_73 ( V_34 -> V_2 ) ;
if ( type == V_29 ) {
T_3 * V_49 = F_50 ( F_3 ( V_1 , F_87 ) ) ;
F_89 ( V_34 -> V_2 , V_49 , V_46 ) ;
F_75 ( V_49 ) ;
} else if ( type == V_26 || type == V_32 || type == V_31 || type == V_33 ) {
if ( F_76 ( V_1 , F_87 ) ) {
int V_50 = ( int ) F_77 ( V_1 , F_87 ) ;
F_90 ( V_34 -> V_2 , V_50 , V_46 ) ;
} else {
const T_3 * V_49 = F_3 ( V_1 , F_87 ) ;
T_19 * V_51 = NULL ;
if ( F_79 ( NULL , & V_51 , V_49 , V_52 ) == V_53 )
F_91 ( V_34 -> V_2 , V_51 , V_46 ) ;
else {
F_81 ( NULL , V_51 ) ;
F_7 ( F_86 , V_54 , L_8 ) ;
return 0 ;
}
F_81 ( NULL , V_51 ) ;
}
}
return 0 ;
}
T_8 F_92 ( T_2 * V_1 ) {
#define F_93 2
T_13 V_34 = F_68 ( V_1 , 1 ) ;
T_4 V_46 ;
if ( ! V_34 ) return 0 ;
if( F_69 ( V_1 , F_93 ) ) {
T_18 V_47 ;
V_47 = F_70 ( V_1 , F_93 ) ;
V_46 = V_47 -> V_46 ;
} else if ( F_71 ( V_1 , F_93 ) ) {
V_46 = F_72 ( V_1 , F_93 ) ;
} else {
F_7 ( F_92 , V_48 , L_7 ) ;
return 0 ;
}
F_85 ( V_34 -> V_2 , V_46 ) ;
return 0 ;
}
T_8 F_94 ( T_2 * V_1 ) {
#define F_95 2
#define F_96 3
#define F_97 4
#define F_98 5
T_13 volatile V_34 = F_68 ( V_1 , 1 ) ;
T_9 V_12 = F_24 ( V_1 , F_96 ) ;
T_10 V_13 = F_25 ( V_1 , F_97 ) ;
T_11 V_14 = F_26 ( V_1 , F_98 ) ;
T_17 type ;
T_20 V_55 = FALSE ;
const T_3 * volatile error = NULL ;
int V_15 = 0 ;
if ( ! ( V_34 && V_12 && V_12 -> V_16 && V_13 && V_14 ) ) return 0 ;
type = F_73 ( V_34 -> V_2 ) ;
F_27 {
if ( type == V_29 ) {
const T_3 * V_49 = F_3 ( V_1 , F_95 ) ;
V_15 = F_99 ( V_34 -> V_36 , V_49 , V_12 -> V_16 , V_13 -> V_17 , V_14 -> V_18 , NULL ) ;
if ( V_15 > 0 ) {
V_55 = TRUE ;
}
} else if ( type == V_26 || type == V_32 || type == V_31 || type == V_33 ) {
int V_50 = ( int ) F_77 ( V_1 , F_95 ) ;
V_15 = F_100 ( V_34 -> V_36 , V_50 , V_12 -> V_16 , V_13 -> V_17 , V_14 -> V_18 ) ;
if ( V_15 > 0 ) {
V_55 = TRUE ;
}
} else {
F_11 ( V_1 , L_11 ) ;
}
if ( ! V_55 ) {
V_15 = F_28 ( V_56 , V_12 -> V_16 , V_13 -> V_17 , V_14 -> V_18 ) ;
}
} F_29 {
F_30 ( V_12 -> V_16 , V_13 -> V_17 , V_14 -> V_18 , V_19 , V_20 ) ;
error = L_3 ;
} V_21 ;
if ( error ) { F_31 ( F_94 , error ) ; }
F_32 ( V_1 , ( V_22 ) V_15 ) ;
F_6 ( 1 ) ;
}
T_8 F_101 ( T_2 * V_1 ) {
#define F_102 2
T_13 V_34 = F_68 ( V_1 , 1 ) ;
T_17 type ;
T_21 V_46 = V_56 ;
if ( ! V_34 ) return 0 ;
type = F_73 ( V_34 -> V_2 ) ;
if ( type == V_29 ) {
const T_3 * V_49 = F_3 ( V_1 , F_102 ) ;
V_46 = F_103 ( V_34 -> V_36 , V_49 ) ;
} else if ( type == V_26 || type == V_32 || type == V_31 || type == V_33 ) {
int V_50 = ( int ) F_77 ( V_1 , F_102 ) ;
V_46 = F_104 ( V_34 -> V_36 , V_50 ) ;
}
if ( V_46 ) {
F_5 ( V_1 , V_46 ) ;
F_6 ( 1 ) ;
} else {
F_105 ( V_1 ) ;
F_6 ( 1 ) ;
}
}
T_8 F_106 ( T_2 * V_1 ) {
#define F_107 2
T_13 V_34 = F_68 ( V_1 , 1 ) ;
T_18 V_57 = F_70 ( V_1 , F_107 ) ;
T_21 V_46 = NULL ;
if ( ! V_57 -> V_46 ) {
V_57 -> V_46 = F_108 ( V_57 -> V_58 , V_59 , V_57 -> V_60 ) ;
}
V_46 = V_57 -> V_46 ;
F_109 ( V_34 -> V_2 , V_46 ) ;
return 0 ;
}
T_12 F_110 ( T_2 * V_1 ) {
T_13 V_34 = F_68 ( V_1 , 1 ) ;
T_22 * V_61 ;
T_17 type ;
if ( ! V_34 ) return 0 ;
type = F_73 ( V_34 -> V_2 ) ;
V_61 = F_111 ( L_12 ) ;
switch( type ) {
case V_29 :
{
F_112 ( V_61 , L_13 , V_34 -> V_2 ) ;
break;
}
case V_31 :
case V_32 :
case V_33 :
case V_26 :
{
int V_27 = F_113 ( V_34 -> V_2 ) ;
F_112 ( V_61 , L_14 , V_34 -> V_2 , V_27 ) ;
break;
}
default:
F_11 ( V_1 , L_15 ) ;
}
F_16 ( V_1 , V_61 -> V_62 ) ;
F_114 ( V_61 , TRUE ) ;
F_6 ( 1 ) ;
}
static int F_115 ( T_2 * V_1 ) {
T_13 V_34 = F_116 ( V_1 , 1 ) ;
if ( V_34 -> V_37 && ! V_34 -> V_38 ) {
V_34 -> V_38 = TRUE ;
} else {
F_75 ( ( char * ) V_34 -> V_2 ) ;
F_75 ( ( char * ) V_34 -> V_24 ) ;
F_75 ( V_34 ) ;
}
return 0 ;
}
int F_117 ( T_2 * V_1 ) {
F_41 ( T_13 ) ;
F_14 ( V_1 ) ;
V_40 = F_118 ( V_1 , V_39 ) ;
return 0 ;
}
int F_119 ( T_2 * V_1 ) {
F_52 ( V_1 , V_39 , V_40 ) ;
for ( F_105 ( V_1 ) ; F_120 ( V_1 , - 2 ) ; F_121 ( V_1 , 1 ) ) {
T_13 V_34 = F_68 ( V_1 , - 1 ) ;
if ( V_34 -> V_37 ) {
F_122 ( V_34 -> V_2 ) ;
}
}
F_121 ( V_1 , 1 ) ;
return 0 ;
}
