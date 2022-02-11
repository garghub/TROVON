static T_1 * F_1 ( T_2 * V_1 , int V_2 )
{
double V_3 ;
const T_3 * V_4 , * V_5 ;
T_1 * V_6 , V_7 = { NULL , NULL , - 1 } ;
T_4 * V_8 = F_2 ( TRUE , TRUE , sizeof( T_1 ) ) ;
F_3 ( V_1 , V_2 , V_9 ) ;
F_4 ( V_1 ) ;
while ( F_5 ( V_1 , V_2 ) ) {
T_1 V_10 = { NULL , NULL , - 1 } ;
F_3 ( V_1 , - 1 , V_9 ) ;
F_4 ( V_1 ) ;
F_5 ( V_1 , - 2 ) ;
if ( ! F_6 ( V_1 , - 1 ) ) {
F_7 ( V_1 , V_2 , L_1 ) ;
F_8 ( V_8 , TRUE ) ;
return NULL ;
}
V_4 = F_9 ( V_1 , - 1 ) ;
F_10 ( V_1 , 1 ) ;
F_5 ( V_1 , - 2 ) ;
if ( ! F_6 ( V_1 , - 1 ) ) {
F_7 ( V_1 , V_2 , L_2 ) ;
F_8 ( V_8 , TRUE ) ;
return NULL ;
}
V_5 = F_9 ( V_1 , - 1 ) ;
F_10 ( V_1 , 1 ) ;
F_5 ( V_1 , - 2 ) ;
if ( ! F_11 ( V_1 , - 1 ) ) {
F_7 ( V_1 , V_2 , L_3 ) ;
F_8 ( V_8 , TRUE ) ;
return NULL ;
}
V_3 = F_12 ( V_1 , - 1 ) ;
V_10 . V_11 = F_13 ( V_4 ) ;
V_10 . V_12 = F_13 ( V_5 ) ;
V_10 . V_13 = ( V_14 ) V_3 ;
F_14 ( V_8 , V_10 ) ;
F_10 ( V_1 , 3 ) ;
}
F_14 ( V_8 , V_7 ) ;
V_6 = ( T_1 * ) ( void * ) V_8 -> V_15 ;
F_8 ( V_8 , FALSE ) ;
return V_6 ;
}
static int F_15 ( T_2 * V_1 , T_5 type ) {
const T_3 * V_16 = F_16 ( V_1 , 1 , NULL ) ;
const T_3 * V_17 = F_16 ( V_1 , 3 , L_4 ) ;
T_6 V_18 = ( V_19 * ) F_17 ( sizeof( V_19 ) ) ;
V_18 -> V_11 = NULL ;
V_18 -> V_16 = V_16 ? F_13 ( V_16 ) : NULL ;
V_18 -> V_20 = F_13 ( V_17 ) ;
V_18 -> type = type ;
V_18 -> V_21 = NULL ;
V_18 -> V_22 = NULL ;
switch( type ) {
case V_23 : {
T_7 V_24 = F_18 ( V_1 , 2 ) ;
V_18 -> V_13 . V_25 = V_24 ;
break;
}
case V_26 : {
V_14 V_24 = F_19 ( V_1 , 2 , 0 ) ;
V_18 -> V_13 . V_27 = V_24 ;
break;
}
case V_28 : {
T_3 * V_24 = F_13 ( F_16 ( V_1 , 2 , L_4 ) ) ;
V_18 -> V_13 . V_29 = V_24 ;
break;
}
case V_30 : {
V_14 V_24 = F_19 ( V_1 , 2 , 0 ) ;
T_1 * V_31 = F_1 ( V_1 , 4 ) ;
T_7 V_32 = F_18 ( V_1 , 5 ) ;
V_18 -> V_13 . V_10 = V_24 ;
V_18 -> V_33 . V_34 . V_35 = V_31 ;
V_18 -> V_33 . V_34 . V_36 = V_32 ;
break;
}
case V_37 : {
T_8 * V_38 = F_20 ( V_1 , 2 , 4 ) ;
V_14 V_39 = F_19 ( V_1 , 4 , 0 ) ;
V_18 -> V_13 . V_40 = V_38 ;
V_18 -> V_33 . V_41 = V_39 ;
break;
}
case V_42 : {
break;
}
default:
F_21 () ;
break;
}
F_22 ( V_1 , V_18 ) ;
return 1 ;
}
T_9 F_23 ( T_2 * V_1 ) {
#define F_24 1
#define F_25 2
#define F_26 3
return F_15 ( V_1 , V_23 ) ;
}
T_9 F_27 ( T_2 * V_1 ) {
#define F_28 1
#define F_29 2
#define F_30 3
return F_15 ( V_1 , V_26 ) ;
}
T_9 F_31 ( T_2 * V_1 ) {
#define F_32 1
#define F_33 2
#define F_34 3
return F_15 ( V_1 , V_28 ) ;
}
T_9 F_35 ( T_2 * V_1 ) {
#define F_36 1
#define F_37 2
#define F_38 3
#define F_39 4
#define F_40 5
return F_15 ( V_1 , V_30 ) ;
}
T_9 F_41 ( T_2 * V_1 ) {
#define F_42 1
#define F_43 2
#define F_44 3
#define F_45 4
return F_15 ( V_1 , V_37 ) ;
}
T_9 F_46 ( T_2 * V_1 ) {
#define F_47 1
#define F_48 2
return F_15 ( V_1 , V_42 ) ;
}
static T_8 * F_20 ( T_2 * V_1 , int V_43 , int V_44 )
{
static T_8 * V_6 = NULL ;
const T_3 * V_45 = F_49 ( V_1 , V_43 ) ;
switch ( F_50 ( & V_6 , V_45 , F_51 ( V_1 , V_44 ) ) ) {
case V_46 :
break;
case V_47 :
F_52 ( F_41 , DEFAULT , L_5 ) ;
return 0 ;
case V_48 :
F_52 ( F_41 , DEFAULT , L_6 ) ;
return 0 ;
default:
F_52 ( F_41 , DEFAULT , L_7 ) ;
return 0 ;
}
return V_6 ;
}
static int F_53 ( T_2 * V_1 ) {
T_6 V_18 = F_54 ( V_1 , 1 ) ;
if ( V_18 && ! V_18 -> V_11 ) {
F_55 ( V_18 -> V_16 ) ;
F_55 ( V_18 -> V_20 ) ;
if ( V_18 -> type == V_28 )
F_55 ( ( void * ) V_18 -> V_13 . V_29 ) ;
F_55 ( V_18 ) ;
}
return 0 ;
}
T_10 F_56 ( T_2 * V_1 ) {
F_57 ( T_6 ) ;
return 0 ;
}
T_11 F_58 ( T_2 * V_1 ) {
#define F_59 2
#define F_60 3
T_6 V_49 = F_61 ( V_1 , 1 ) ;
const T_3 * V_11 = F_49 ( V_1 , F_59 ) ;
T_6 V_18 = F_54 ( V_1 , F_60 ) ;
T_6 V_50 ;
const T_3 * V_51 ;
if ( ! V_49 ) return 0 ;
if ( ! V_11 ) {
F_52 ( F_58 , V_52 , L_8 ) ;
return 0 ;
}
if ( ! V_18 ) {
F_52 ( F_58 , V_53 , L_9 ) ;
return 0 ;
}
if ( V_18 -> V_11 ) {
F_52 ( F_58 , V_52 , L_10 ) ;
return 0 ;
}
if ( V_18 -> V_22 ) {
F_52 ( F_58 , V_53 , L_11 ) ;
return 0 ;
}
V_50 = V_49 ;
do {
if ( V_50 -> V_11 && F_62 ( V_50 -> V_11 , V_11 ) ) {
F_63 ( V_1 , L_12 , V_11 ) ;
return 0 ;
}
for ( V_51 = V_11 ; * V_51 != '\0' ; V_51 ++ ) {
if ( ! isascii ( ( V_54 ) * V_51 ) ||
( ! islower ( ( V_54 ) * V_51 ) && ! isdigit ( ( V_54 ) * V_51 ) && * V_51 != '_' && * V_51 != '.' ) )
{
F_63 ( V_1 , L_13
L_14 , V_11 ) ;
return 0 ;
}
}
if ( ! V_50 -> V_21 ) {
V_50 -> V_21 = V_18 ;
V_18 -> V_11 = F_13 ( V_11 ) ;
if ( ! V_18 -> V_16 )
V_18 -> V_16 = F_13 ( V_11 ) ;
if ( ! V_49 -> V_22 -> V_55 ) {
V_49 -> V_22 -> V_55 = F_64 ( V_49 -> V_22 -> V_56 ,
V_57 ) ;
}
switch( V_18 -> type ) {
case V_23 :
F_65 ( V_49 -> V_22 -> V_55 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
& ( V_18 -> V_13 . V_25 ) ) ;
break;
case V_26 :
F_66 ( V_49 -> V_22 -> V_55 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
10 ,
& ( V_18 -> V_13 . V_27 ) ) ;
break;
case V_28 :
F_67 ( V_49 -> V_22 -> V_55 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
( const char * * ) ( & ( V_18 -> V_13 . V_29 ) ) ) ;
break;
case V_30 :
F_68 ( V_49 -> V_22 -> V_55 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
& ( V_18 -> V_13 . V_10 ) ,
V_18 -> V_33 . V_34 . V_35 ,
V_18 -> V_33 . V_34 . V_36 ) ;
break;
case V_37 :
F_69 ( V_49 -> V_22 -> V_55 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
& ( V_18 -> V_13 . V_40 ) ,
V_18 -> V_33 . V_41 ) ;
break;
case V_42 :
F_70 ( V_49 -> V_22 -> V_55 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ) ;
break;
default:
F_71 ( F_58 , L_15 ) ;
break;
}
V_18 -> V_22 = V_50 -> V_22 ;
F_72 ( 0 ) ;
}
} while ( ( V_50 = V_50 -> V_21 ) );
F_63 ( V_1 , L_16 ) ;
F_72 ( 0 ) ;
}
T_11 F_73 ( T_2 * V_1 ) {
#define F_74 2
T_6 V_49 = F_61 ( V_1 , 1 ) ;
const T_3 * V_11 = F_49 ( V_1 , F_74 ) ;
if ( ! ( V_11 && V_49 ) ) return 0 ;
if ( ! V_49 -> V_21 ) {
F_63 ( V_1 , L_17 ) ;
return 0 ;
}
V_49 = V_49 -> V_21 ;
do {
if ( F_62 ( V_49 -> V_11 , V_11 ) ) {
switch ( V_49 -> type ) {
case V_23 : F_75 ( V_1 , V_49 -> V_13 . V_25 ) ; break;
case V_26 : F_76 ( V_1 , ( V_58 ) V_49 -> V_13 . V_27 ) ; break;
case V_28 : F_77 ( V_1 , V_49 -> V_13 . V_29 ) ; break;
case V_30 : F_76 ( V_1 , ( V_58 ) V_49 -> V_13 . V_10 ) ; break;
case V_37 : F_77 ( V_1 , F_78 ( V_49 -> V_13 . V_40 ) ) ; break;
default: F_71 ( F_73 , L_15 ) ; return 0 ;
}
F_72 ( 1 ) ;
}
} while ( ( V_49 = V_49 -> V_21 ) );
F_52 ( F_73 , V_52 , L_18 ) ;
return 0 ;
}
static int F_79 ( T_2 * V_1 V_59 ) {
return 0 ;
}
T_10 F_80 ( T_2 * V_1 ) {
F_81 ( V_60 ) ;
return 0 ;
}
static enum V_61 F_82 ( const T_3 * type ) {
const T_12 * V_62 ;
for ( V_62 = V_63 ; V_62 -> V_64 ; V_62 ++ ) {
if ( F_62 ( V_62 -> V_64 , type ) ) {
return V_62 -> V_65 ;
}
}
return V_66 ;
}
static const T_3 * F_83 ( enum V_61 V_67 ) {
const T_12 * V_62 ;
for ( V_62 = V_63 ; V_62 -> V_64 ; V_62 ++ ) {
if ( V_62 -> V_65 == V_67 ) {
return V_62 -> V_64 ;
}
}
return NULL ;
}
static const T_3 * F_84 ( unsigned V_68 ) {
const struct V_69 * V_25 ;
for ( V_25 = V_70 ; V_25 -> V_64 ; V_25 ++ ) {
if ( V_68 == V_25 -> V_68 )
return V_25 -> V_64 ;
}
return NULL ;
}
static unsigned F_85 ( const T_3 * V_64 ) {
const struct V_69 * V_25 ;
for ( V_25 = V_70 ; V_25 -> V_64 ; V_25 ++ ) {
if ( F_62 ( V_64 , V_25 -> V_64 ) )
return V_25 -> V_68 ;
}
return V_71 ;
}
static T_13 * F_86 ( T_2 * V_1 , int V_2 ) {
T_4 * V_72 = F_2 ( TRUE , TRUE , sizeof( T_13 ) ) ;
T_13 * V_6 ;
if( F_87 ( V_1 , V_2 ) ) {
return NULL ;
} else if ( ! F_88 ( V_1 , V_2 ) ) {
F_7 ( V_1 , V_2 , L_19 ) ;
F_8 ( V_72 , TRUE ) ;
return NULL ;
}
F_4 ( V_1 ) ;
while ( F_5 ( V_1 , V_2 ) != 0 ) {
T_13 V_73 = { 0 , NULL } ;
if ( ! F_11 ( V_1 , - 2 ) ) {
F_7 ( V_1 , V_2 , L_20 ) ;
F_8 ( V_72 , TRUE ) ;
return NULL ;
}
if ( ! F_6 ( V_1 , - 1 ) ) {
F_7 ( V_1 , V_2 , L_21 ) ;
F_8 ( V_72 , TRUE ) ;
return NULL ;
}
V_73 . V_13 = F_89 ( V_1 , - 2 ) ;
V_73 . V_74 = F_13 ( F_9 ( V_1 , - 1 ) ) ;
F_14 ( V_72 , V_73 ) ;
F_10 ( V_1 , 1 ) ;
}
V_6 = ( T_13 * ) ( void * ) V_72 -> V_15 ;
F_8 ( V_72 , FALSE ) ;
return V_6 ;
}
static T_14 * F_90 ( T_2 * V_1 , int V_2 ) {
T_4 * V_72 = F_2 ( TRUE , TRUE , sizeof( T_14 ) ) ;
T_14 * V_6 ;
if( F_87 ( V_1 , V_2 ) ) {
return NULL ;
} else if ( ! F_88 ( V_1 , V_2 ) ) {
F_7 ( V_1 , V_2 , L_19 ) ;
F_8 ( V_72 , TRUE ) ;
return NULL ;
}
F_4 ( V_1 ) ;
while ( F_5 ( V_1 , V_2 ) != 0 ) {
T_14 V_73 = { 0 , NULL } ;
if ( ! F_11 ( V_1 , - 2 ) ) {
F_7 ( V_1 , V_2 , L_22 ) ;
F_8 ( V_72 , TRUE ) ;
return NULL ;
}
if ( ! F_6 ( V_1 , - 1 ) ) {
F_7 ( V_1 , V_2 , L_23 ) ;
F_8 ( V_72 , TRUE ) ;
return NULL ;
}
V_73 . V_13 = F_91 ( V_1 , - 2 ) ;
V_73 . V_74 = F_13 ( F_9 ( V_1 , - 1 ) ) ;
F_14 ( V_72 , V_73 ) ;
F_10 ( V_1 , 1 ) ;
}
V_6 = ( T_14 * ) ( void * ) V_72 -> V_15 ;
F_8 ( V_72 , FALSE ) ;
return V_6 ;
}
static T_15 * F_92 ( T_2 * V_1 , int V_2 ) {
T_4 * V_75 = F_2 ( TRUE , TRUE , sizeof( T_15 ) ) ;
T_15 * V_6 ;
T_15 V_76 = { L_24 , L_25 } ;
if ( F_87 ( V_1 , V_2 ) ) {
return NULL ;
} else if ( ! F_88 ( V_1 , V_2 ) ) {
F_7 ( V_1 , V_2 , L_19 ) ;
F_8 ( V_75 , TRUE ) ;
return NULL ;
}
F_4 ( V_1 ) ;
while ( F_5 ( V_1 , V_2 ) ) {
if ( ! F_11 ( V_1 , - 2 ) ) {
F_7 ( V_1 , V_2 , L_26 ) ;
F_8 ( V_75 , TRUE ) ;
return NULL ;
}
if ( ! F_6 ( V_1 , - 1 ) ) {
F_7 ( V_1 , V_2 , L_27 ) ;
F_8 ( V_75 , TRUE ) ;
return NULL ;
}
if ( F_93 ( V_1 , - 2 ) == 1 )
V_76 . V_77 = F_13 ( F_9 ( V_1 , - 1 ) ) ;
if ( F_93 ( V_1 , - 2 ) == 2 )
V_76 . V_78 = F_13 ( F_9 ( V_1 , - 1 ) ) ;
F_10 ( V_1 , 1 ) ;
}
F_14 ( V_75 , V_76 ) ;
V_6 = ( T_15 * ) ( void * ) V_75 -> V_15 ;
F_8 ( V_75 , FALSE ) ;
return V_6 ;
}
static const T_3 * F_94 ( T_2 * V_1 , const int V_79 , const enum V_61 type ) {
const T_3 * V_80 = F_49 ( V_1 , V_79 ) ;
const T_16 * V_81 = NULL ;
if ( ! V_80 [ 0 ] ) {
F_7 ( V_1 , V_79 , L_28 ) ;
return NULL ;
}
if ( F_95 ( V_80 ) ) {
F_7 ( V_1 , V_79 , L_29 ) ;
return NULL ;
}
V_81 = F_96 ( V_80 ) ;
if ( V_81 && ! F_97 ( type , V_81 -> type ) ) {
F_7 ( V_1 , V_79 , L_30 ) ;
return NULL ;
}
return V_80 ;
}
T_9 F_98 ( T_2 * V_1 ) {
#define F_99 1
#define F_100 2
#define F_101 3
#define F_102 4
#define F_103 5
#define F_104 6
#define F_105 7
T_17 V_82 ;
int V_83 = F_106 ( V_1 ) ;
const T_3 * V_11 = F_49 ( V_1 , F_99 ) ;
const T_3 * V_80 = NULL ;
enum V_61 type ;
T_13 * V_84 = NULL ;
T_14 * V_85 = NULL ;
T_15 * V_75 = NULL ;
unsigned V_68 ;
V_14 V_86 = F_107 ( V_1 , F_104 , 0x0 ) ;
const T_3 * V_87 = F_16 ( V_1 , F_105 , NULL ) ;
if ( F_11 ( V_1 , F_101 ) ) {
type = (enum V_61 ) F_108 ( V_1 , F_101 ) ;
} else {
type = F_82 ( F_49 ( V_1 , F_101 ) ) ;
}
V_80 = F_94 ( V_1 , F_100 , type ) ;
if ( F_11 ( V_1 , F_103 ) ) {
V_68 = F_109 ( V_1 , F_103 , V_71 ) ;
} else {
V_68 = F_85 ( F_16 ( V_1 , F_103 , L_31 ) ) ;
}
switch ( type ) {
case V_88 :
if ( V_68 != V_71 ) {
F_110 ( F_98 , V_89 , L_32 ) ;
return 0 ;
}
if ( V_86 ) {
F_110 ( F_98 , V_90 , L_33 ) ;
return 0 ;
}
break;
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
if ( V_68 == V_71 ) {
V_68 = V_101 ;
} else if ( V_68 < V_101 || V_68 > V_102 ) {
F_110 ( F_98 , V_89 , L_34
L_35 ) ;
return 0 ;
}
if ( ( V_68 == V_103 || V_68 == V_104 ) &&
( type == V_96 || type == V_97 || type == V_98 || type == V_99 || type == V_100 ) )
{
F_110 ( F_98 , V_89 , L_36 ) ;
return 0 ;
}
if ( V_83 >= F_102 && ! F_87 ( V_1 , F_102 ) ) {
if ( type == V_95 || type == V_100 ) {
V_85 = F_90 ( V_1 , F_102 ) ;
} else {
V_84 = F_86 ( V_1 , F_102 ) ;
}
}
break;
case V_105 :
if ( V_86 == 0x0 && V_68 != V_71 ) {
F_110 ( F_98 , V_89 , L_37 ) ;
return 0 ;
}
if ( V_86 != 0x0 && ( V_68 < 1 || V_68 > 64 ) ) {
F_110 ( F_98 , V_89 , L_38 ) ;
return 0 ;
}
if ( V_83 >= F_102 && ! F_87 ( V_1 , F_102 ) ) {
V_75 = F_92 ( V_1 , F_102 ) ;
}
break;
case V_106 :
if ( V_68 == V_71 ) {
V_68 = V_107 ;
} else if ( V_68 < V_107 || V_68 > V_108 ) {
F_110 ( F_98 , V_89 , L_39 ) ;
return 0 ;
}
if ( V_86 ) {
F_110 ( F_98 , V_90 , L_40 ) ;
return 0 ;
}
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
if ( V_68 != V_71 ) {
F_110 ( F_98 , V_89 , L_41 ) ;
return 0 ;
}
if ( V_86 ) {
F_110 ( F_98 , V_90 , L_42 ) ;
return 0 ;
}
break;
case V_66 :
default:
F_52 ( F_98 , TYPE , L_43 ) ;
break;
}
V_82 = F_111 ( V_124 , 1 ) ;
V_82 -> V_56 = - 2 ;
V_82 -> V_125 = - 1 ;
V_82 -> V_11 = F_13 ( V_11 ) ;
V_82 -> V_80 = F_13 ( V_80 ) ;
V_82 -> type = type ;
V_82 -> V_68 = V_68 ;
if ( V_75 ) {
V_82 -> V_72 = F_112 ( V_75 ) ;
} else if ( V_84 ) {
V_82 -> V_72 = F_113 ( V_84 ) ;
} else if ( V_85 ) {
V_82 -> V_68 |= V_126 ;
V_82 -> V_72 = F_113 ( V_85 ) ;
} else {
V_82 -> V_72 = NULL ;
}
V_82 -> V_86 = V_86 ;
if ( V_87 && strcmp ( V_87 , V_82 -> V_11 ) != 0 ) {
V_82 -> V_87 = F_13 ( V_87 ) ;
} else {
V_82 -> V_87 = NULL ;
}
F_114 ( V_1 , V_82 ) ;
F_72 ( 1 ) ;
}
static int F_115 ( T_2 * V_1 , enum V_61 type ) {
T_17 V_82 ;
const T_3 * V_80 = F_94 ( V_1 , 1 , type ) ;
const T_3 * V_11 = F_16 ( V_1 , 2 , V_80 ) ;
unsigned V_68 = F_109 ( V_1 , 3 , V_101 ) ;
T_13 * V_84 = NULL ;
T_14 * V_85 = NULL ;
V_14 V_86 = F_107 ( V_1 , 5 , 0 ) ;
const T_3 * V_87 = F_16 ( V_1 , 6 , NULL ) ;
if ( F_106 ( V_1 ) > 3 ) {
if ( type == V_95 || type == V_100 ) {
V_85 = F_90 ( V_1 , 4 ) ;
} else {
V_84 = F_86 ( V_1 , 4 ) ;
}
}
if ( type == V_88 ) {
if ( V_68 != V_71 )
F_7 ( V_1 , 3 , L_44 ) ;
else if ( V_86 )
F_7 ( V_1 , 3 , L_45 ) ;
} else if ( V_68 < V_101 || V_68 > V_102 ) {
F_7 ( V_1 , 3 , L_34
L_35 ) ;
return 0 ;
} else if ( ( V_68 == V_103 || V_68 == V_104 ) &&
( type == V_96 || type == V_97 || type == V_98 || type == V_99 || type == V_100 ) ) {
F_7 ( V_1 , 3 , L_36 ) ;
return 0 ;
}
V_82 = F_111 ( V_124 , 1 ) ;
V_82 -> V_56 = - 2 ;
V_82 -> V_125 = - 1 ;
V_82 -> V_11 = F_13 ( V_11 ) ;
V_82 -> V_80 = F_13 ( V_80 ) ;
V_82 -> type = type ;
V_82 -> V_68 = V_68 ;
if ( V_85 ) {
V_82 -> V_68 |= V_126 ;
V_82 -> V_72 = F_113 ( V_85 ) ;
} else {
V_82 -> V_72 = F_113 ( V_84 ) ;
}
V_82 -> V_86 = V_86 ;
if ( V_87 && strcmp ( V_87 , V_82 -> V_11 ) != 0 ) {
V_82 -> V_87 = F_13 ( V_87 ) ;
} else {
V_82 -> V_87 = NULL ;
}
F_114 ( V_1 , V_82 ) ;
return 1 ;
}
static int F_116 ( T_2 * V_1 , enum V_61 type ) {
T_17 V_82 ;
const T_3 * V_80 = F_94 ( V_1 , 1 , type ) ;
const T_3 * V_11 = F_16 ( V_1 , 2 , V_80 ) ;
unsigned V_68 = F_109 ( V_1 , 3 , V_71 ) ;
T_15 * V_75 = NULL ;
V_14 V_86 = F_107 ( V_1 , 5 , 0 ) ;
const T_3 * V_87 = F_16 ( V_1 , 6 , NULL ) ;
if ( V_86 == 0x0 && V_68 != V_71 ) {
F_7 ( V_1 , 2 , L_46
L_47 ) ;
return 0 ;
}
if ( V_86 != 0x0 && ( V_68 < 1 || V_68 > 64 ) ) {
F_7 ( V_1 , 2 , L_48
L_49 ) ;
return 0 ;
}
if ( F_106 ( V_1 ) > 3 && ! F_87 ( V_1 , 4 ) ) {
V_75 = F_92 ( V_1 , 4 ) ;
}
V_82 = F_111 ( V_124 , 1 ) ;
V_82 -> V_56 = - 2 ;
V_82 -> V_125 = - 1 ;
V_82 -> V_11 = F_13 ( V_11 ) ;
V_82 -> V_80 = F_13 ( V_80 ) ;
V_82 -> type = type ;
V_82 -> V_72 = F_112 ( V_75 ) ;
V_82 -> V_68 = V_68 ;
V_82 -> V_86 = V_86 ;
if ( V_87 && strcmp ( V_87 , V_82 -> V_11 ) != 0 ) {
V_82 -> V_87 = F_13 ( V_87 ) ;
} else {
V_82 -> V_87 = NULL ;
}
F_114 ( V_1 , V_82 ) ;
return 1 ;
}
static int F_117 ( T_2 * V_1 , enum V_61 type ) {
T_17 V_82 ;
const T_3 * V_80 = NULL ;
const T_3 * V_11 = F_16 ( V_1 , 2 , V_80 ) ;
unsigned V_68 = F_109 ( V_1 , 3 , V_107 ) ;
const T_3 * V_87 = NULL ;
if ( type == V_106 ) {
V_80 = F_94 ( V_1 , 1 , type ) ;
V_87 = F_16 ( V_1 , 4 , NULL ) ;
if ( V_68 < V_107 || V_68 > V_108 ) {
F_7 ( V_1 , 3 , L_39 ) ;
return 0 ;
}
} else {
V_80 = F_94 ( V_1 , 1 , type ) ;
V_87 = F_16 ( V_1 , 3 , NULL ) ;
}
V_82 = F_111 ( V_124 , 1 ) ;
V_82 -> V_56 = - 2 ;
V_82 -> V_125 = - 1 ;
V_82 -> V_11 = F_13 ( V_11 ) ;
V_82 -> V_80 = F_13 ( V_80 ) ;
V_82 -> type = type ;
V_82 -> V_72 = NULL ;
V_82 -> V_68 = V_68 ;
V_82 -> V_86 = 0 ;
if ( V_87 && strcmp ( V_87 , V_82 -> V_11 ) != 0 ) {
V_82 -> V_87 = F_13 ( V_87 ) ;
} else {
V_82 -> V_87 = NULL ;
}
F_114 ( V_1 , V_82 ) ;
return 1 ;
}
static int F_118 ( T_2 * V_1 , enum V_61 type ) {
T_17 V_82 ;
const T_3 * V_80 = F_94 ( V_1 , 1 , type ) ;
const T_3 * V_11 = F_16 ( V_1 , 2 , V_80 ) ;
const T_3 * V_87 = F_16 ( V_1 , 3 , NULL ) ;
V_82 = F_111 ( V_124 , 1 ) ;
V_82 -> V_56 = - 2 ;
V_82 -> V_125 = - 1 ;
V_82 -> V_11 = F_13 ( V_11 ) ;
V_82 -> V_80 = F_13 ( V_80 ) ;
V_82 -> type = type ;
V_82 -> V_72 = NULL ;
V_82 -> V_68 = V_71 ;
V_82 -> V_86 = 0 ;
if ( V_87 && strcmp ( V_87 , V_82 -> V_11 ) != 0 ) {
V_82 -> V_87 = F_13 ( V_87 ) ;
} else {
V_82 -> V_87 = NULL ;
}
F_114 ( V_1 , V_82 ) ;
return 1 ;
}
T_11 F_119 ( T_2 * V_1 ) {
T_17 V_82 = F_120 ( V_1 , 1 ) ;
T_3 * V_29 = ( T_3 * ) F_121 ( L_50 ,
V_82 -> V_56 , V_82 -> V_11 , V_82 -> V_80 ,
F_83 ( V_82 -> type ) ,
F_84 ( V_82 -> V_68 ) ,
V_82 -> V_72 , V_82 -> V_86 , V_82 -> V_87 ) ;
F_77 ( V_1 , V_29 ) ;
return 1 ;
}
static int F_122 ( T_2 * V_1 ) {
T_17 V_82 = F_123 ( V_1 , 1 ) ;
if ( ! V_82 ) {
F_7 ( V_1 , 1 , L_51 ) ;
} else if ( V_82 -> V_56 == - 2 ) {
F_55 ( V_82 -> V_11 ) ;
F_55 ( V_82 -> V_80 ) ;
F_55 ( V_82 -> V_87 ) ;
F_55 ( V_82 ) ;
}
return 0 ;
}
int F_124 ( T_2 * V_1 ) {
F_57 ( T_17 ) ;
return 0 ;
}
T_9 F_125 ( T_2 * V_1 ) {
#define F_126 1
#define F_127 2
#define F_128 3
#define F_129 4
T_18 V_127 = NULL ;
const T_3 * V_80 = F_130 ( V_1 , F_126 ) ;
const T_3 * V_128 = F_130 ( V_1 , F_127 ) ;
int V_129 = F_108 ( V_1 , F_128 ) ;
int V_130 = F_108 ( V_1 , F_129 ) ;
V_127 = F_111 ( V_131 , 1 ) ;
V_127 -> V_132 . V_133 = V_134 ;
V_127 -> V_132 . V_135 = V_136 ;
V_127 -> V_80 = F_13 ( V_80 ) ;
V_127 -> V_128 = F_13 ( V_128 ) ;
V_127 -> V_129 = V_129 ;
V_127 -> V_130 = V_130 ;
F_131 ( V_1 , V_127 ) ;
F_72 ( 1 ) ;
}
T_11 F_132 ( T_2 * V_1 ) {
T_18 V_127 = F_133 ( V_1 , 1 ) ;
if ( ! V_127 ) {
F_77 ( V_1 , L_52 ) ;
} else {
F_134 ( V_1 , L_53 ,
V_127 -> V_132 . V_133 , V_127 -> V_132 . V_135 , V_127 -> V_80 , V_127 -> V_128 , V_127 -> V_129 , V_127 -> V_130 ) ;
}
return 1 ;
}
static int F_135 ( T_2 * V_1 ) {
T_18 V_127 = F_133 ( V_1 , 1 ) ;
if ( V_127 ) {
F_7 ( V_1 , 1 , L_54 ) ;
}
return 0 ;
}
int F_136 ( T_2 * V_1 ) {
F_57 ( T_18 ) ;
return 0 ;
}
T_9 F_137 ( T_2 * V_1 ) {
#define F_138 1
#define F_139 2
const T_3 * V_11 = F_49 ( V_1 , F_138 ) ;
const T_3 * V_20 = F_49 ( V_1 , F_139 ) ;
if ( ! V_11 [ 0 ] || ! V_20 [ 0 ] )
F_7 ( V_1 , F_138 , L_55 ) ;
if ( V_11 ) {
T_3 * V_137 ;
int V_138 ;
V_137 = F_140 ( V_11 , - 1 ) ;
V_138 = F_141 ( V_137 ) ;
F_55 ( V_137 ) ;
if ( V_138 > 0 ) {
F_52 ( F_137 , V_52 , L_56 ) ;
return 0 ;
} else {
T_19 V_22 = ( V_139 * ) F_17 ( sizeof( V_139 ) ) ;
T_3 * V_140 = F_140 ( V_11 , - 1 ) ;
T_3 * V_141 = F_142 ( V_11 , - 1 ) ;
V_22 -> V_11 = V_141 ;
V_22 -> V_20 = F_13 ( V_20 ) ;
V_22 -> V_56 = F_143 ( V_22 -> V_20 , V_141 , V_140 ) ;
V_22 -> V_125 = - 1 ;
V_22 -> V_142 = FALSE ;
F_144 ( V_1 ) ;
V_22 -> V_143 = F_145 ( V_1 , V_144 ) ;
F_144 ( V_1 ) ;
V_22 -> V_145 = F_145 ( V_1 , V_144 ) ;
V_22 -> V_146 = F_146 ( V_22 -> V_56 ) ;
V_22 -> V_147 . V_11 = NULL ;
V_22 -> V_147 . V_16 = NULL ;
V_22 -> V_147 . V_20 = NULL ;
V_22 -> V_147 . V_13 . V_27 = 0 ;
V_22 -> V_147 . V_21 = NULL ;
V_22 -> V_147 . V_22 = V_22 ;
V_22 -> V_55 = NULL ;
V_22 -> V_148 = NULL ;
F_147 ( V_1 , V_144 , V_149 ) ;
F_77 ( V_1 , V_140 ) ;
F_148 ( V_1 , V_22 ) ;
F_149 ( V_1 , - 3 ) ;
F_148 ( V_1 , V_22 ) ;
F_72 ( 1 ) ;
}
}
F_52 ( F_137 , V_52 , L_8 ) ;
return 0 ;
}
T_11 F_150 ( T_2 * V_1 ) {
#define F_151 1
#define F_152 2
F_153 ( V_1 , 1 ) ;
F_72 ( F_137 ( V_1 ) ) ;
}
static int F_154 ( T_2 * V_1 ) {
T_19 V_22 = F_155 ( V_1 , 1 ) ;
T_3 * V_29 ;
V_29 = F_121 ( L_57 , V_22 -> V_11 ) ;
F_77 ( V_1 , V_29 ) ;
return 1 ;
}
T_20 F_156 ( T_2 * V_1 ) {
#define F_157 1
#define F_158 2
T_19 V_22 = F_155 ( V_1 , F_157 ) ;
const T_7 V_150 = F_159 ( V_1 , F_158 , FALSE ) ;
if( ! V_22 -> V_142 ) {
if ( ! V_22 -> V_148 ) {
V_22 -> V_148 = F_160 ( V_151 , V_22 -> V_56 ) ;
}
F_161 ( V_22 -> V_148 ) ;
} else {
F_7 ( V_1 , 1 , L_58 ) ;
}
if ( V_150 ) {
F_162 ( TRUE ) ;
}
return 0 ;
}
T_21 F_163 ( T_2 * V_1 ) {
#define F_164 2
#define F_165 3
T_19 V_22 = F_155 ( V_1 , 1 ) ;
const T_3 * V_152 = F_49 ( V_1 , F_164 ) ;
const T_3 * V_153 = V_22 -> V_11 ;
const int V_154 = F_106 ( V_1 ) ;
if ( ! V_153 || V_22 -> V_56 == - 1 ) {
F_63 ( V_1 , L_59 ) ;
return 0 ;
}
if ( ! F_166 ( V_152 ) ) {
F_63 ( V_1 , L_60 , V_152 ) ;
return 0 ;
}
if ( F_167 ( V_1 , F_165 ) ) {
F_147 ( V_1 , V_144 , V_155 ) ;
if ( ! F_88 ( V_1 , - 1 ) ) {
F_63 ( V_1 , L_61 ) ;
return 0 ;
}
if ( ! F_168 ( V_1 , - 1 , V_152 ) ) {
F_144 ( V_1 ) ;
F_169 ( V_1 , - 1 ) ;
F_170 ( V_1 , - 3 , V_152 ) ;
}
else if ( F_171 ( V_1 , - 1 , V_153 ) ) {
F_63 ( V_1 , L_62 , V_153 , V_152 ) ;
return 0 ;
}
F_169 ( V_1 , F_165 ) ;
F_170 ( V_1 , - 2 , V_153 ) ;
F_10 ( V_1 , 2 ) ;
F_172 ( V_154 == F_106 ( V_1 ) ) ;
F_173 ( V_152 , V_156 , V_22 -> V_56 ) ;
} else {
F_7 ( V_1 , 3 , L_63 ) ;
}
return 0 ;
}
static int F_174 ( T_2 * V_1 ) {
T_19 V_22 = F_155 ( V_1 , 1 ) ;
if ( V_22 -> V_148 ) {
F_175 ( V_1 , V_22 -> V_148 ) ;
return 1 ;
} else {
F_63 ( V_1 , L_64 ) ;
return 0 ;
}
}
static int F_176 ( T_2 * V_1 ) {
T_19 V_22 = F_155 ( V_1 , 1 ) ;
if ( F_167 ( V_1 , 2 ) ) {
T_3 * V_140 = F_140 ( V_22 -> V_11 , - 1 ) ;
F_147 ( V_1 , V_144 , V_157 ) ;
F_177 ( V_1 , 1 ) ;
F_77 ( V_1 , V_22 -> V_11 ) ;
F_178 ( V_1 , 2 ) ;
F_149 ( V_1 , 1 ) ;
V_22 -> V_148 = F_160 ( V_151 , V_22 -> V_56 ) ;
F_179 ( V_140 , V_151 , V_22 -> V_56 ) ;
} else {
F_7 ( V_1 , 2 , L_65 ) ;
}
return 0 ;
}
static int F_180 ( T_2 * V_1 ) {
T_19 V_22 = F_155 ( V_1 , 1 ) ;
F_181 ( V_1 , & V_22 -> V_147 ) ;
return 1 ;
}
static int F_182 ( T_2 * V_1 ) {
T_19 V_22 = F_155 ( V_1 , 1 ) ;
if ( F_167 ( V_1 , 2 ) ) {
F_183 ( V_1 , V_158 ) ;
F_177 ( V_1 , 1 ) ;
F_77 ( V_1 , V_22 -> V_11 ) ;
F_178 ( V_1 , 2 ) ;
F_149 ( V_1 , 1 ) ;
} else {
F_7 ( V_1 , 2 , L_66 ) ;
}
return 0 ;
}
static int F_184 ( T_2 * V_1 ) {
T_19 V_22 = F_155 ( V_1 , 1 ) ;
if ( F_167 ( V_1 , 2 ) ) {
F_183 ( V_1 , V_159 ) ;
F_177 ( V_1 , 1 ) ;
F_77 ( V_1 , V_22 -> V_11 ) ;
F_178 ( V_1 , 2 ) ;
F_149 ( V_1 , 1 ) ;
} else {
F_7 ( V_1 , 2 , L_67 ) ;
}
return 0 ;
}
static int F_185 ( T_2 * V_1 ) {
T_19 V_22 = F_155 ( V_1 , 1 ) ;
F_147 ( V_1 , V_144 , V_22 -> V_143 ) ;
return 1 ;
}
static int F_186 ( T_2 * V_1 ) {
T_19 V_22 = F_155 ( V_1 , 1 ) ;
#define F_187 2
#define F_188 3
#define F_189 3
F_147 ( V_1 , V_144 , V_22 -> V_143 ) ;
F_178 ( V_1 , F_187 ) ;
if( F_88 ( V_1 , F_188 ) ) {
for ( F_4 ( V_1 ) ; F_5 ( V_1 , F_188 ) ; ) {
if ( F_190 ( V_1 , 5 ) ) {
F_145 ( V_1 , F_187 ) ;
} else if ( ! F_87 ( V_1 , 5 ) ) {
return F_63 ( V_1 , L_68 ) ;
}
}
} else if ( F_190 ( V_1 , F_189 ) ) {
F_169 ( V_1 , F_189 ) ;
F_145 ( V_1 , F_187 ) ;
} else {
return F_63 ( V_1 , L_69 ) ;
}
F_169 ( V_1 , 3 ) ;
return 1 ;
}
static int F_191 ( T_2 * V_1 ) {
T_19 V_22 = F_155 ( V_1 , 1 ) ;
F_147 ( V_1 , V_144 , V_22 -> V_145 ) ;
return 1 ;
}
static int F_192 ( T_2 * V_1 ) {
T_19 V_22 = F_155 ( V_1 , 1 ) ;
#define F_193 2
#define F_188 3
#define F_189 3
F_147 ( V_1 , V_144 , V_22 -> V_145 ) ;
F_178 ( V_1 , F_193 ) ;
if( F_88 ( V_1 , F_188 ) ) {
for ( F_4 ( V_1 ) ; F_5 ( V_1 , F_188 ) ; ) {
if ( F_194 ( V_1 , 5 ) ) {
F_145 ( V_1 , F_193 ) ;
} else if ( ! F_87 ( V_1 , 5 ) ) {
return F_63 ( V_1 , L_70 ) ;
}
}
} else if ( F_194 ( V_1 , F_189 ) ) {
F_169 ( V_1 , F_189 ) ;
F_145 ( V_1 , F_193 ) ;
} else {
return F_63 ( V_1 , L_71 ) ;
}
F_169 ( V_1 , 3 ) ;
return 1 ;
}
static int F_195 ( T_2 * V_1 V_59 ) {
return 0 ;
}
int F_196 ( T_2 * V_1 ) {
F_57 ( T_19 ) ;
F_197 ( T_19 ) ;
F_144 ( V_1 ) ;
V_149 = F_145 ( V_1 , V_144 ) ;
return 0 ;
}
int F_198 ( T_2 * V_1 , const char * V_160 ) {
F_147 ( V_1 , V_144 , V_149 ) ;
F_4 ( V_1 ) ;
while ( F_5 ( V_1 , - 2 ) ) {
T_19 V_22 ;
V_22 = F_155 ( V_1 , - 1 ) ;
F_147 ( V_1 , V_144 , V_22 -> V_143 ) ;
F_4 ( V_1 ) ;
while ( F_5 ( V_1 , - 2 ) ) {
T_17 V_82 = F_120 ( V_1 , - 1 ) ;
if ( strcmp ( V_160 , V_82 -> V_80 ) == 0 ) {
F_10 ( V_1 , 6 ) ;
return 1 ;
}
F_10 ( V_1 , 1 ) ;
}
F_10 ( V_1 , 2 ) ;
}
F_10 ( V_1 , 1 ) ;
return 0 ;
}
int F_199 ( T_2 * V_1 ) {
F_200 ( V_1 , 0 ) ;
F_147 ( V_1 , V_144 , V_149 ) ;
for ( F_4 ( V_1 ) ; F_5 ( V_1 , 1 ) ; F_10 ( V_1 , 2 ) ) {
T_4 * V_161 = F_2 ( TRUE , TRUE , sizeof( V_162 ) ) ;
T_4 * V_163 = F_2 ( TRUE , TRUE , sizeof( V_164 * ) ) ;
T_4 * V_165 = F_2 ( TRUE , TRUE , sizeof( V_166 ) ) ;
T_19 V_22 ;
V_22 = F_155 ( V_1 , 3 ) ;
F_147 ( V_1 , V_144 , V_22 -> V_143 ) ;
for ( F_4 ( V_1 ) ; F_5 ( V_1 , 4 ) ; F_10 ( V_1 , 1 ) ) {
T_17 V_82 = F_120 ( V_1 , 6 ) ;
V_162 V_167 = { NULL , { NULL , NULL , V_66 , 0 , NULL , 0 , NULL , V_168 } } ;
V_164 * V_169 = & ( V_82 -> V_125 ) ;
V_167 . V_170 = & ( V_82 -> V_56 ) ;
V_167 . V_81 . V_11 = V_82 -> V_11 ;
V_167 . V_81 . V_171 = V_82 -> V_80 ;
V_167 . V_81 . type = V_82 -> type ;
V_167 . V_81 . V_172 = V_82 -> V_68 ;
V_167 . V_81 . V_173 = F_113 ( V_82 -> V_72 ) ;
V_167 . V_81 . V_174 = V_82 -> V_86 ;
V_167 . V_81 . V_175 = V_82 -> V_87 ;
if ( V_82 -> V_56 != - 2 ) {
return F_63 ( V_1 , L_72 ) ;
}
V_82 -> V_56 = - 1 ;
F_14 ( V_161 , V_167 ) ;
F_14 ( V_163 , V_169 ) ;
}
F_201 ( V_22 -> V_56 , ( V_162 * ) ( void * ) V_161 -> V_15 , V_161 -> V_176 ) ;
F_202 ( ( V_164 * * ) ( void * ) V_163 -> V_15 , V_163 -> V_176 ) ;
F_10 ( V_1 , 1 ) ;
F_147 ( V_1 , V_144 , V_22 -> V_145 ) ;
for ( F_4 ( V_1 ) ; F_5 ( V_1 , 4 ) ; F_10 ( V_1 , 1 ) ) {
T_18 V_10 = F_203 ( V_1 , 6 ) ;
V_166 V_177 = { NULL , { NULL , 0 , 0 , NULL , V_178 } } ;
V_177 . V_132 = & ( V_10 -> V_132 ) ;
V_177 . V_179 . V_11 = V_10 -> V_80 ;
V_177 . V_179 . V_129 = V_10 -> V_129 ;
V_177 . V_179 . V_130 = V_10 -> V_130 ;
V_177 . V_179 . V_180 = V_10 -> V_128 ;
if ( V_10 -> V_132 . V_133 != V_134 || V_10 -> V_132 . V_135 != V_136 ) {
return F_63 ( V_1 , L_73 ) ;
}
F_14 ( V_165 , V_177 ) ;
}
F_204 ( V_22 -> V_146 , ( V_166 * ) ( void * ) V_165 -> V_15 , V_165 -> V_176 ) ;
F_8 ( V_161 , FALSE ) ;
F_8 ( V_163 , FALSE ) ;
F_8 ( V_165 , FALSE ) ;
}
F_10 ( V_1 , 1 ) ;
return 0 ;
}
T_9 F_205 ( T_2 * V_1 ) {
#define F_206 1
const T_3 * V_11 = F_49 ( V_1 , F_206 ) ;
T_22 V_181 ;
if ( ! V_11 ) {
F_52 ( F_205 , V_52 , L_8 ) ;
return 0 ;
}
if ( ( V_181 = F_207 ( V_11 ) ) ) {
F_175 ( V_1 , V_181 ) ;
F_72 ( 1 ) ;
}
F_52 ( F_205 , V_52 , L_74 ) ;
return 0 ;
}
static V_164
F_208 ( T_23 V_182 , T_23 V_183 )
{
return strcmp ( ( const char * ) V_182 , ( const char * ) V_183 ) ;
}
T_9 F_209 ( T_2 * V_1 ) {
T_24 * V_184 = F_210 () ;
T_24 * V_185 = NULL ;
int V_186 = 1 ;
if ( ! V_184 ) return F_63 ( V_1 , L_75 ) ;
V_184 = F_211 ( V_184 , ( V_187 ) F_208 ) ;
V_185 = F_212 ( V_184 ) ;
F_144 ( V_1 ) ;
for ( V_186 = 1 ; V_185 ; V_186 ++ , V_185 = F_213 ( V_185 ) ) {
F_77 ( V_1 , ( const char * ) V_185 -> V_15 ) ;
F_214 ( V_1 , 1 , V_186 ) ;
}
F_215 ( V_184 ) ;
F_72 ( 1 ) ;
}
T_21 F_216 ( T_2 * V_1 ) {
#define F_217 2
#define F_218 3
#define F_219 4
T_22 V_181 = F_220 ( V_1 , 1 ) ;
T_25 V_188 = F_221 ( V_1 , F_217 ) ;
T_26 V_189 = F_222 ( V_1 , F_218 ) ;
T_27 V_190 = F_223 ( V_1 , F_219 ) ;
const char * volatile error = NULL ;
int V_6 = 0 ;
if ( ! ( V_181 && V_188 && V_189 ) ) return 0 ;
F_224 {
V_6 = F_225 ( V_181 , V_188 -> V_191 , V_189 -> V_192 , V_190 -> V_193 ) ;
} F_226 {
F_227 ( V_188 -> V_191 , V_189 -> V_192 , V_190 -> V_193 , V_194 , V_195 ) ;
error = L_76 ;
} V_196 ;
if ( error ) { F_71 ( F_216 , error ) ; }
F_76 ( V_1 , ( V_58 ) V_6 ) ;
F_72 ( 1 ) ;
}
T_11 F_228 ( T_2 * V_1 ) {
#define F_229 2
#define F_230 3
#define F_231 4
return F_216 ( V_1 ) ;
}
T_11 F_232 ( T_2 * V_1 ) {
T_22 V_181 = F_220 ( V_1 , 1 ) ;
if ( ! V_181 ) return 0 ;
F_77 ( V_1 , F_233 ( V_181 ) ) ;
F_72 ( 1 ) ;
}
static int F_234 ( T_2 * V_1 V_59 ) {
return 0 ;
}
int F_235 ( T_2 * V_1 ) {
F_57 ( T_22 ) ;
return 0 ;
}
T_9 F_236 ( T_2 * V_1 ) {
#define F_237 1
#define F_238 2
#define F_239 3
#define F_240 4
const T_3 * V_11 = ( const T_3 * ) F_49 ( V_1 , F_237 ) ;
const T_3 * V_197 = ( const T_3 * ) F_16 ( V_1 , F_238 , V_11 ) ;
enum V_61 type = (enum V_61 ) F_109 ( V_1 , F_239 , V_94 ) ;
unsigned V_68 = ( unsigned ) F_109 ( V_1 , F_240 , V_101 ) ;
if( ! ( V_11 && V_197 ) ) return 0 ;
switch( type ) {
case V_116 :
V_68 = V_71 ;
case V_91 :
case V_92 :
case V_93 :
case V_94 :
{
T_28 V_198 = ( T_28 ) F_17 ( sizeof( struct V_199 ) ) ;
V_11 = F_13 ( V_11 ) ;
V_197 = F_13 ( V_197 ) ;
V_198 -> V_200 = F_241 ( V_11 , V_197 , type , V_68 ) ;
V_198 -> V_11 = V_11 ;
F_242 ( V_1 , V_198 ) ;
}
F_72 ( 1 ) ;
default:
F_110 ( F_236 , TYPE , L_77 ) ;
break;
}
return 0 ;
}
static void
F_243 ( const T_3 * V_201 , const T_3 * V_197 V_59 , T_29 V_202 ) {
T_30 * V_15 = ( T_30 * ) V_202 ;
F_77 ( V_15 -> V_1 , V_201 ) ;
F_214 ( V_15 -> V_1 , 1 , V_15 -> V_203 ) ;
V_15 -> V_203 = V_15 -> V_203 + 1 ;
}
T_9 F_244 ( T_2 * V_1 ) {
T_30 V_15 = { 1 , V_1 } ;
F_144 ( V_1 ) ;
F_245 ( F_243 , ( T_29 ) & V_15 ,
( V_187 ) F_208 ) ;
F_72 ( 1 ) ;
}
static void
F_246 ( const T_3 * V_201 , T_29 V_200 V_59 , T_29 V_202 ) {
T_30 * V_15 = ( T_30 * ) V_202 ;
F_77 ( V_15 -> V_1 , V_201 ) ;
F_214 ( V_15 -> V_1 , 1 , V_15 -> V_203 ) ;
V_15 -> V_203 = V_15 -> V_203 + 1 ;
}
T_9 F_247 ( T_2 * V_1 ) {
T_30 V_15 = { 1 , V_1 } ;
F_144 ( V_1 ) ;
F_248 ( F_246 , ( T_29 ) & V_15 ) ;
F_72 ( 1 ) ;
}
T_9 F_249 ( T_2 * V_1 ) {
#define F_250 1
const T_3 * V_11 = F_49 ( V_1 , F_250 ) ;
T_31 V_200 ;
if( ! V_11 ) return 0 ;
V_200 = F_251 ( V_11 ) ;
if ( V_200 ) {
T_28 V_198 = ( T_28 ) F_17 ( sizeof( struct V_199 ) ) ;
V_198 -> V_200 = V_200 ;
V_198 -> V_11 = F_13 ( V_11 ) ;
F_242 ( V_1 , V_198 ) ;
F_72 ( 1 ) ;
}
F_52 ( F_249 , V_204 , L_78 ) ;
return 0 ;
}
T_21 F_252 ( T_2 * V_1 ) {
#define F_253 2
#define F_254 3
T_28 V_198 = F_255 ( V_1 , 1 ) ;
T_32 type ;
T_22 V_148 ;
if ( ! V_198 ) return 0 ;
if( F_256 ( V_1 , F_254 ) ) {
T_19 V_50 ;
V_50 = F_155 ( V_1 , F_254 ) ;
V_148 = V_50 -> V_148 ;
if ( ! V_148 ) {
F_52 ( F_252 , V_205 , L_79 ) ;
return 0 ;
}
} else if ( F_257 ( V_1 , F_254 ) ) {
V_148 = F_258 ( V_1 , F_254 ) ;
} else {
F_52 ( F_252 , V_205 , L_80 ) ;
return 0 ;
}
type = F_259 ( V_198 -> V_11 ) ;
if ( type == V_116 ) {
T_3 * V_45 = F_13 ( F_49 ( V_1 , F_253 ) ) ;
F_260 ( V_198 -> V_11 , V_45 , V_148 ) ;
F_55 ( V_45 ) ;
} else if ( type == V_94 || type == V_92 || type == V_91 || type == V_93 ) {
if ( F_11 ( V_1 , F_253 ) ) {
int V_206 = F_108 ( V_1 , F_253 ) ;
F_261 ( V_198 -> V_11 , V_206 , V_148 ) ;
} else {
T_3 * V_45 = F_13 ( F_49 ( V_1 , F_253 ) ) ;
T_8 * V_38 ;
if ( F_50 ( & V_38 , V_45 , V_207 ) == V_46 ) {
F_262 ( V_198 -> V_11 , V_38 , V_148 ) ;
} else {
F_55 ( V_45 ) ;
F_52 ( F_252 , V_208 , L_81 ) ;
return 0 ;
}
F_55 ( V_45 ) ;
}
} else {
F_63 ( V_1 , L_82 , type ) ;
}
return 0 ;
}
T_21 F_263 ( T_2 * V_1 ) {
#define F_264 2
#define F_265 3
T_28 V_198 = F_255 ( V_1 , 1 ) ;
T_32 type ;
T_22 V_148 ;
if ( ! V_198 ) return 0 ;
if( F_256 ( V_1 , F_265 ) ) {
T_19 V_50 ;
V_50 = F_155 ( V_1 , F_265 ) ;
V_148 = V_50 -> V_148 ;
if ( ! V_148 ) {
F_52 ( F_263 , V_205 , L_83 ) ;
return 0 ;
}
} else if ( F_257 ( V_1 , F_265 ) ) {
V_148 = F_258 ( V_1 , F_265 ) ;
} else {
F_52 ( F_263 , V_205 , L_80 ) ;
return 0 ;
}
type = F_259 ( V_198 -> V_11 ) ;
if ( type == V_116 ) {
const T_3 * V_45 = F_49 ( V_1 , F_264 ) ;
F_266 ( V_198 -> V_11 , V_148 ) ;
F_260 ( V_198 -> V_11 , V_45 , V_148 ) ;
} else if ( type == V_94 || type == V_92 || type == V_91 || type == V_93 ) {
if ( F_11 ( V_1 , F_264 ) ) {
int V_206 = F_108 ( V_1 , F_264 ) ;
F_266 ( V_198 -> V_11 , V_148 ) ;
F_261 ( V_198 -> V_11 , V_206 , V_148 ) ;
} else {
const T_3 * V_45 = F_49 ( V_1 , F_264 ) ;
T_8 * V_38 ;
if ( F_50 ( & V_38 , V_45 , V_207 ) == V_46 ) {
F_266 ( V_198 -> V_11 , V_148 ) ;
F_262 ( V_198 -> V_11 , V_38 , V_148 ) ;
} else {
F_52 ( F_263 , V_208 , L_81 ) ;
return 0 ;
}
}
} else {
F_63 ( V_1 , L_82 , type ) ;
}
return 0 ;
}
T_21 F_267 ( T_2 * V_1 ) {
#define F_268 2
#define F_269 3
T_28 V_198 = F_255 ( V_1 , 1 ) ;
T_32 type ;
T_22 V_148 ;
if ( ! V_198 ) return 0 ;
if( F_256 ( V_1 , F_269 ) ) {
T_19 V_50 ;
V_50 = F_155 ( V_1 , F_269 ) ;
V_148 = V_50 -> V_148 ;
} else if ( F_257 ( V_1 , F_269 ) ) {
V_148 = F_258 ( V_1 , F_269 ) ;
} else {
F_52 ( F_267 , V_205 , L_80 ) ;
return 0 ;
}
type = F_259 ( V_198 -> V_11 ) ;
if ( type == V_116 ) {
T_3 * V_45 = F_13 ( F_49 ( V_1 , F_268 ) ) ;
F_270 ( V_198 -> V_11 , V_45 , V_148 ) ;
F_55 ( V_45 ) ;
} else if ( type == V_94 || type == V_92 || type == V_91 || type == V_93 ) {
if ( F_11 ( V_1 , F_268 ) ) {
int V_206 = F_108 ( V_1 , F_268 ) ;
F_271 ( V_198 -> V_11 , V_206 , V_148 ) ;
} else {
T_3 * V_45 = F_13 ( F_49 ( V_1 , F_268 ) ) ;
T_8 * V_38 ;
if ( F_50 ( & V_38 , V_45 , V_207 ) == V_46 )
F_272 ( V_198 -> V_11 , V_38 , V_148 ) ;
else {
F_55 ( V_45 ) ;
F_52 ( F_267 , V_208 , L_81 ) ;
return 0 ;
}
F_55 ( V_45 ) ;
}
}
return 0 ;
}
T_21 F_273 ( T_2 * V_1 ) {
#define F_274 2
T_28 V_198 = F_255 ( V_1 , 1 ) ;
T_22 V_148 ;
if ( ! V_198 ) return 0 ;
if( F_256 ( V_1 , F_274 ) ) {
T_19 V_50 ;
V_50 = F_155 ( V_1 , F_274 ) ;
V_148 = V_50 -> V_148 ;
} else if ( F_257 ( V_1 , F_274 ) ) {
V_148 = F_258 ( V_1 , F_274 ) ;
} else {
F_52 ( F_273 , V_205 , L_80 ) ;
return 0 ;
}
F_266 ( V_198 -> V_11 , V_148 ) ;
return 0 ;
}
T_21 F_275 ( T_2 * V_1 ) {
#define F_276 2
#define F_277 3
#define F_278 4
#define F_279 5
T_28 V_198 = F_255 ( V_1 , 1 ) ;
T_25 V_188 = F_221 ( V_1 , F_277 ) ;
T_26 V_189 = F_222 ( V_1 , F_278 ) ;
T_27 V_190 = F_223 ( V_1 , F_279 ) ;
T_32 type ;
T_7 V_209 = FALSE ;
const T_3 * volatile error = NULL ;
if ( ! ( V_198 && V_188 && V_188 -> V_191 && V_189 && V_190 ) ) return 0 ;
type = F_259 ( V_198 -> V_11 ) ;
F_224 {
if ( type == V_116 ) {
const T_3 * V_45 = F_49 ( V_1 , F_276 ) ;
if ( ! V_45 )
V_209 = TRUE ;
else if ( F_280 ( V_198 -> V_200 , V_45 , V_188 -> V_191 , V_189 -> V_192 , V_190 -> V_193 , NULL ) )
V_209 = TRUE ;
} else if ( type == V_94 || type == V_92 || type == V_91 || type == V_93 ) {
int V_206 = F_108 ( V_1 , F_276 ) ;
if ( F_281 ( V_198 -> V_200 , V_206 , V_188 -> V_191 , V_189 -> V_192 , V_190 -> V_193 ) )
V_209 = TRUE ;
} else {
F_63 ( V_1 , L_84 ) ;
}
if ( ! V_209 )
F_225 ( V_210 , V_188 -> V_191 , V_189 -> V_192 , V_190 -> V_193 ) ;
} F_226 {
F_227 ( V_188 -> V_191 , V_189 -> V_192 , V_190 -> V_193 , V_194 , V_195 ) ;
error = L_76 ;
} V_196 ;
if ( error ) { F_71 ( F_275 , error ) ; }
return 0 ;
}
T_21 F_282 ( T_2 * V_1 ) {
#define F_283 2
T_28 V_198 = F_255 ( V_1 , 1 ) ;
T_32 type ;
T_33 V_148 = V_210 ;
if ( ! V_198 ) return 0 ;
type = F_259 ( V_198 -> V_11 ) ;
if ( type == V_116 ) {
const T_3 * V_45 = F_49 ( V_1 , F_283 ) ;
if ( ! V_45 ) {
F_52 ( F_282 , V_208 , L_8 ) ;
return 0 ;
}
V_148 = F_284 ( V_198 -> V_200 , V_45 ) ;
} else if ( type == V_94 || type == V_92 || type == V_91 || type == V_93 ) {
int V_206 = F_108 ( V_1 , F_283 ) ;
V_148 = F_285 ( V_198 -> V_200 , V_206 ) ;
}
if ( V_148 ) {
F_175 ( V_1 , V_148 ) ;
F_72 ( 1 ) ;
} else {
F_4 ( V_1 ) ;
F_72 ( 1 ) ;
}
}
T_11 F_286 ( T_2 * V_1 ) {
T_28 V_198 = F_255 ( V_1 , 1 ) ;
T_34 * V_29 ;
T_32 type ;
if ( ! V_198 ) return 0 ;
type = F_259 ( V_198 -> V_11 ) ;
V_29 = F_287 ( L_85 ) ;
switch( type ) {
case V_116 :
{
F_288 ( V_29 , L_86 , V_198 -> V_11 ) ;
break;
}
case V_91 :
case V_92 :
case V_93 :
case V_94 :
{
int V_68 = F_289 ( V_198 -> V_11 ) ;
F_288 ( V_29 , L_87 , V_198 -> V_11 , V_68 ) ;
break;
}
default:
F_63 ( V_1 , L_88 ) ;
}
F_77 ( V_1 , V_29 -> V_64 ) ;
F_290 ( V_29 , TRUE ) ;
F_72 ( 1 ) ;
}
static int F_291 ( T_2 * V_1 V_59 ) {
return 0 ;
}
int F_292 ( T_2 * V_1 ) {
F_57 ( T_28 ) ;
return 0 ;
}
