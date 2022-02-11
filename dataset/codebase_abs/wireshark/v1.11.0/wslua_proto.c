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
V_6 = ( T_1 * ) V_8 -> V_15 ;
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
V_14 V_24 = ( V_14 ) F_19 ( V_1 , 2 , 0 ) ;
V_18 -> V_13 . V_27 = V_24 ;
break;
}
case V_28 : {
T_3 * V_24 = F_13 ( F_16 ( V_1 , 2 , L_4 ) ) ;
V_18 -> V_13 . V_29 = V_24 ;
break;
}
case V_30 : {
V_14 V_24 = ( V_14 ) F_19 ( V_1 , 2 , 0 ) ;
T_1 * V_31 = F_1 ( V_1 , 4 ) ;
T_7 V_32 = F_18 ( V_1 , 5 ) ;
V_18 -> V_13 . V_10 = V_24 ;
V_18 -> V_33 . V_34 . V_35 = V_31 ;
V_18 -> V_33 . V_34 . V_36 = V_32 ;
break;
}
case V_37 : {
T_8 * V_38 = F_20 ( V_1 , 2 , 4 ) ;
V_14 V_39 = ( V_14 ) F_19 ( V_1 , 4 , 0 ) ;
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
T_3 * V_45 = F_13 ( F_49 ( V_1 , V_43 ) ) ;
switch ( F_50 ( & V_6 , V_45 , ( V_14 ) F_12 ( V_1 , V_44 ) ) ) {
case V_46 :
break;
case V_47 :
F_51 ( F_41 , DEFAULT , L_5 ) ;
break;
case V_48 :
F_51 ( F_41 , DEFAULT , L_6 ) ;
break;
default:
F_51 ( F_41 , DEFAULT , L_7 ) ;
break;
}
F_52 ( V_45 ) ;
return V_6 ;
}
static int F_53 ( T_2 * V_1 ) {
T_6 V_18 = F_54 ( V_1 , 1 ) ;
if ( V_18 && ! V_18 -> V_11 ) {
F_52 ( V_18 -> V_16 ) ;
F_52 ( V_18 -> V_20 ) ;
if ( V_18 -> type == V_28 )
F_52 ( ( void * ) V_18 -> V_13 . V_29 ) ;
F_52 ( V_18 ) ;
}
return 0 ;
}
T_10 F_55 ( T_2 * V_1 ) {
F_56 ( T_6 ) ;
return 1 ;
}
T_11 F_57 ( T_2 * V_1 ) {
#define F_58 2
#define F_59 3
T_6 V_49 = F_60 ( V_1 , 1 ) ;
const T_3 * V_11 = F_49 ( V_1 , F_58 ) ;
T_6 V_18 = F_54 ( V_1 , F_59 ) ;
T_6 V_50 ;
const T_3 * V_51 ;
if ( ! V_49 ) return 0 ;
if ( ! V_11 )
F_51 ( F_57 , V_52 , L_8 ) ;
if ( ! V_18 )
F_51 ( F_57 , V_53 , L_9 ) ;
if ( V_18 -> V_11 )
F_51 ( F_57 , V_52 , L_10 ) ;
if ( V_18 -> V_22 )
F_51 ( F_57 , V_53 , L_11 ) ;
V_50 = V_49 ;
do {
if ( V_50 -> V_11 && F_61 ( V_50 -> V_11 , V_11 ) ) {
F_62 ( V_1 , L_12 , V_11 ) ;
return 0 ;
}
for ( V_51 = V_11 ; * V_51 != '\0' ; V_51 ++ ) {
if ( ! isascii ( ( V_54 ) * V_51 ) ||
( ! islower ( ( V_54 ) * V_51 ) && ! isdigit ( ( V_54 ) * V_51 ) && * V_51 != '_' && * V_51 != '.' ) )
{
F_62 ( V_1 , L_13 , V_11 ) ;
return 0 ;
}
}
if ( ! V_50 -> V_21 ) {
V_50 -> V_21 = V_18 ;
V_18 -> V_11 = F_13 ( V_11 ) ;
if ( ! V_18 -> V_16 )
V_18 -> V_16 = F_13 ( V_11 ) ;
if ( ! V_49 -> V_22 -> V_55 ) {
V_49 -> V_22 -> V_55 = F_63 ( V_49 -> V_22 -> V_56 , V_57 ) ;
}
switch( V_18 -> type ) {
case V_23 :
F_64 ( V_49 -> V_22 -> V_55 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
& ( V_18 -> V_13 . V_25 ) ) ;
break;
case V_26 :
F_65 ( V_49 -> V_22 -> V_55 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
10 ,
& ( V_18 -> V_13 . V_27 ) ) ;
break;
case V_28 :
F_66 ( V_49 -> V_22 -> V_55 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
& ( V_18 -> V_13 . V_29 ) ) ;
break;
case V_30 :
F_67 ( V_49 -> V_22 -> V_55 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
& ( V_18 -> V_13 . V_10 ) ,
V_18 -> V_33 . V_34 . V_35 ,
V_18 -> V_33 . V_34 . V_36 ) ;
break;
case V_37 :
F_68 ( V_49 -> V_22 -> V_55 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
& ( V_18 -> V_13 . V_40 ) ,
V_18 -> V_33 . V_41 ) ;
break;
case V_42 :
F_69 ( V_49 -> V_22 -> V_55 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ) ;
break;
default:
F_70 ( F_57 , L_14 ) ;
}
V_18 -> V_22 = V_50 -> V_22 ;
F_71 ( 0 ) ;
}
} while ( ( V_50 = V_50 -> V_21 ) );
F_62 ( V_1 , L_15 ) ;
F_71 ( 0 ) ;
}
T_11 F_72 ( T_2 * V_1 ) {
#define F_73 2
T_6 V_49 = F_60 ( V_1 , 1 ) ;
const T_3 * V_11 = F_49 ( V_1 , F_73 ) ;
if ( ! ( V_11 && V_49 ) ) return 0 ;
V_49 = V_49 -> V_21 ;
do {
if ( F_61 ( V_49 -> V_11 , V_11 ) ) {
switch ( V_49 -> type ) {
case V_23 : F_74 ( V_1 , V_49 -> V_13 . V_25 ) ; break;
case V_26 : F_75 ( V_1 , ( V_58 ) V_49 -> V_13 . V_27 ) ; break;
case V_28 : F_76 ( V_1 , V_49 -> V_13 . V_29 ) ; break;
case V_30 : F_75 ( V_1 , ( V_58 ) V_49 -> V_13 . V_10 ) ; break;
case V_37 : F_76 ( V_1 , F_77 ( V_49 -> V_13 . V_40 ) ) ; break;
default: F_70 ( F_72 , L_14 ) ;
}
F_71 ( 1 ) ;
}
} while ( ( V_49 = V_49 -> V_21 ) );
F_51 ( F_72 , V_52 , L_16 ) ;
}
static int F_78 ( T_2 * V_1 V_59 ) {
return 0 ;
}
T_10 F_79 ( T_2 * V_1 ) {
F_80 ( V_60 ) ;
return 1 ;
}
static enum V_61 F_81 ( const T_3 * type ) {
const T_12 * V_62 ;
for ( V_62 = V_63 ; V_62 -> V_64 ; V_62 ++ ) {
if ( F_61 ( V_62 -> V_64 , type ) ) {
return V_62 -> V_65 ;
}
}
return V_66 ;
}
static const T_3 * F_82 ( enum V_61 V_67 ) {
const T_12 * V_62 ;
for ( V_62 = V_63 ; V_62 -> V_64 ; V_62 ++ ) {
if ( V_62 -> V_65 == V_67 ) {
return V_62 -> V_64 ;
}
}
return NULL ;
}
static const T_3 * F_83 ( unsigned V_68 ) {
const struct V_69 * V_25 ;
for ( V_25 = V_70 ; V_25 -> V_64 ; V_25 ++ ) {
if ( V_68 == V_25 -> V_68 )
return V_25 -> V_64 ;
}
return NULL ;
}
static unsigned F_84 ( const T_3 * V_64 ) {
const struct V_69 * V_25 ;
for ( V_25 = V_70 ; V_25 -> V_64 ; V_25 ++ ) {
if ( F_61 ( V_64 , V_25 -> V_64 ) )
return V_25 -> V_68 ;
}
return V_71 ;
}
static T_13 * F_85 ( T_2 * V_1 , int V_2 ) {
T_4 * V_72 = F_2 ( TRUE , TRUE , sizeof( T_13 ) ) ;
T_13 * V_6 ;
if( F_86 ( V_1 , V_2 ) ) {
return NULL ;
} else if ( ! F_87 ( V_1 , V_2 ) ) {
F_7 ( V_1 , V_2 , L_17 ) ;
F_8 ( V_72 , TRUE ) ;
return NULL ;
}
F_4 ( V_1 ) ;
while ( F_5 ( V_1 , V_2 ) != 0 ) {
T_13 V_73 = { 0 , NULL } ;
if ( ! F_11 ( V_1 , - 2 ) ) {
F_7 ( V_1 , V_2 , L_18 ) ;
F_8 ( V_72 , TRUE ) ;
return NULL ;
}
if ( ! F_6 ( V_1 , - 1 ) ) {
F_7 ( V_1 , V_2 , L_19 ) ;
F_8 ( V_72 , TRUE ) ;
return NULL ;
}
V_73 . V_13 = ( V_14 ) F_12 ( V_1 , - 2 ) ;
V_73 . V_74 = F_13 ( F_9 ( V_1 , - 1 ) ) ;
F_14 ( V_72 , V_73 ) ;
F_10 ( V_1 , 1 ) ;
}
V_6 = ( T_13 * ) V_72 -> V_15 ;
F_8 ( V_72 , FALSE ) ;
return V_6 ;
}
static T_14 * F_88 ( T_2 * V_1 , int V_2 ) {
T_4 * V_72 = F_2 ( TRUE , TRUE , sizeof( T_14 ) ) ;
T_14 * V_6 ;
if( F_86 ( V_1 , V_2 ) ) {
return NULL ;
} else if ( ! F_87 ( V_1 , V_2 ) ) {
F_7 ( V_1 , V_2 , L_17 ) ;
F_8 ( V_72 , TRUE ) ;
return NULL ;
}
F_4 ( V_1 ) ;
while ( F_5 ( V_1 , V_2 ) != 0 ) {
T_14 V_73 = { 0 , NULL } ;
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
V_73 . V_13 = ( V_75 ) F_12 ( V_1 , - 2 ) ;
V_73 . V_74 = F_13 ( F_9 ( V_1 , - 1 ) ) ;
F_14 ( V_72 , V_73 ) ;
F_10 ( V_1 , 1 ) ;
}
V_6 = ( T_14 * ) V_72 -> V_15 ;
F_8 ( V_72 , FALSE ) ;
return V_6 ;
}
static T_15 * F_89 ( T_2 * V_1 , int V_2 ) {
T_4 * V_76 = F_2 ( TRUE , TRUE , sizeof( T_15 ) ) ;
T_15 * V_6 ;
T_15 V_77 = { L_22 , L_23 } ;
if ( F_86 ( V_1 , V_2 ) ) {
return NULL ;
} else if ( ! F_87 ( V_1 , V_2 ) ) {
F_7 ( V_1 , V_2 , L_17 ) ;
F_8 ( V_76 , TRUE ) ;
return NULL ;
}
F_4 ( V_1 ) ;
while ( F_5 ( V_1 , V_2 ) ) {
if ( ! F_11 ( V_1 , - 2 ) ) {
F_7 ( V_1 , V_2 , L_24 ) ;
F_8 ( V_76 , TRUE ) ;
return NULL ;
}
if ( ! F_6 ( V_1 , - 1 ) ) {
F_7 ( V_1 , V_2 , L_25 ) ;
F_8 ( V_76 , TRUE ) ;
return NULL ;
}
if ( ( V_14 ) F_12 ( V_1 , - 2 ) == 1 )
V_77 . V_78 = F_13 ( F_9 ( V_1 , - 1 ) ) ;
if ( ( V_14 ) F_12 ( V_1 , - 2 ) == 2 )
V_77 . V_79 = F_13 ( F_9 ( V_1 , - 1 ) ) ;
F_10 ( V_1 , 1 ) ;
}
F_14 ( V_76 , V_77 ) ;
V_6 = ( T_15 * ) V_76 -> V_15 ;
F_8 ( V_76 , FALSE ) ;
return V_6 ;
}
T_9 F_90 ( T_2 * V_1 ) {
#define F_91 1
#define F_92 2
#define F_93 3
#define F_94 4
#define F_95 5
#define F_96 6
#define F_97 7
T_16 V_80 = ( V_81 * ) F_17 ( sizeof( V_81 ) ) ;
T_13 * V_82 = NULL ;
T_14 * V_83 = NULL ;
T_15 * V_76 = NULL ;
const T_3 * V_84 ;
V_80 -> V_56 = - 2 ;
V_80 -> V_85 = - 1 ;
V_80 -> V_11 = F_13 ( F_49 ( V_1 , F_91 ) ) ;
V_80 -> V_86 = F_13 ( F_49 ( V_1 , F_92 ) ) ;
V_80 -> type = F_81 ( F_49 ( V_1 , F_93 ) ) ;
if ( V_80 -> type == V_66 ) {
F_52 ( V_80 -> V_11 ) ;
F_52 ( V_80 -> V_86 ) ;
F_52 ( V_80 ) ;
F_51 ( F_90 , TYPE , L_26 ) ;
}
if ( ! V_80 -> V_86 || ! V_80 -> V_86 [ 0 ] ) {
F_51 ( F_90 , V_87 , L_27 ) ;
}
if ( F_98 ( V_80 -> V_86 ) ) {
F_52 ( V_80 -> V_11 ) ;
F_52 ( V_80 -> V_86 ) ;
F_52 ( V_80 ) ;
F_51 ( F_90 , V_87 , L_28 ) ;
}
if ( ! F_86 ( V_1 , F_94 ) ) {
if ( V_80 -> type == V_88 ) {
V_76 = F_89 ( V_1 , F_94 ) ;
}
else if ( V_80 -> type == V_89 || V_80 -> type == V_90 ) {
V_83 = F_88 ( V_1 , F_94 ) ;
}
else {
V_82 = F_85 ( V_1 , F_94 ) ;
}
if ( V_82 ) {
V_80 -> V_72 = F_99 ( V_82 ) ;
} else if ( V_76 ) {
V_80 -> V_72 = F_100 ( V_76 ) ;
} else if ( V_83 ) {
V_80 -> V_72 = F_99 ( V_83 ) ;
} else {
F_52 ( V_80 -> V_11 ) ;
F_52 ( V_80 -> V_86 ) ;
F_52 ( V_80 ) ;
return 0 ;
}
} else {
V_80 -> V_72 = NULL ;
}
V_80 -> V_68 = F_84 ( F_16 ( V_1 , F_95 , L_29 ) ) ;
if ( V_83 ) {
V_80 -> V_68 |= V_91 ;
}
V_80 -> V_92 = ( V_14 ) F_19 ( V_1 , F_96 , 0x0 ) ;
V_84 = F_16 ( V_1 , F_97 , NULL ) ;
if ( V_84 && strcmp ( V_84 , V_80 -> V_11 ) != 0 ) {
V_80 -> V_84 = F_13 ( V_84 ) ;
} else {
V_80 -> V_84 = NULL ;
}
F_101 ( V_1 , V_80 ) ;
F_71 ( 1 ) ;
}
static int F_102 ( T_2 * V_1 , enum V_61 type ) {
T_16 V_80 ;
const T_3 * V_86 = F_49 ( V_1 , 1 ) ;
const T_3 * V_11 = F_16 ( V_1 , 2 , V_86 ) ;
unsigned V_68 = F_103 ( V_1 , 3 , V_93 ) ;
T_13 * V_82 = NULL ;
T_14 * V_83 = NULL ;
V_14 V_92 = ( V_14 ) F_19 ( V_1 , 5 , 0 ) ;
const T_3 * V_84 = F_16 ( V_1 , 6 , NULL ) ;
if ( F_104 ( V_1 ) > 3 ) {
if ( type == V_89 || type == V_90 ) {
V_83 = F_88 ( V_1 , 4 ) ;
} else {
V_82 = F_85 ( V_1 , 4 ) ;
}
}
if ( type == V_94 ) {
if ( V_68 != V_71 )
F_7 ( V_1 , 3 , L_30 ) ;
else if ( V_92 )
F_7 ( V_1 , 3 , L_31 ) ;
} else if ( V_68 < V_93 || V_68 > V_95 ) {
F_7 ( V_1 , 3 , L_32
L_33 ) ;
return 0 ;
} else if ( ( V_68 == V_96 || V_68 == V_97 ) &&
( type == V_98 || type == V_99 || type == V_100 || type == V_101 || type == V_90 ) ) {
F_7 ( V_1 , 3 , L_34 ) ;
return 0 ;
}
if ( ! V_86 || ! V_86 [ 0 ] ) {
F_7 ( V_1 , 1 , L_27 ) ;
return 0 ;
}
if ( F_98 ( V_86 ) ) {
F_7 ( V_1 , 1 , L_28 ) ;
return 0 ;
}
V_80 = F_105 ( V_81 , 1 ) ;
V_80 -> V_56 = - 2 ;
V_80 -> V_85 = - 1 ;
V_80 -> V_11 = F_13 ( V_11 ) ;
V_80 -> V_86 = F_13 ( V_86 ) ;
V_80 -> type = type ;
V_80 -> V_68 = V_68 ;
if ( V_83 ) {
V_80 -> V_68 |= V_91 ;
V_80 -> V_72 = F_99 ( V_83 ) ;
} else {
V_80 -> V_72 = F_99 ( V_82 ) ;
}
V_80 -> V_92 = V_92 ;
if ( V_84 && strcmp ( V_84 , V_80 -> V_11 ) != 0 ) {
V_80 -> V_84 = F_13 ( V_84 ) ;
} else {
V_80 -> V_84 = NULL ;
}
F_101 ( V_1 , V_80 ) ;
return 1 ;
}
static int F_106 ( T_2 * V_1 , enum V_61 type ) {
T_16 V_80 ;
const T_3 * V_86 = F_49 ( V_1 , 1 ) ;
const T_3 * V_11 = F_16 ( V_1 , 2 , V_86 ) ;
unsigned V_68 = F_103 ( V_1 , 3 , V_71 ) ;
T_15 * V_76 = ( F_104 ( V_1 ) > 3 ) ? F_89 ( V_1 , 4 ) : NULL ;
V_14 V_92 = ( V_14 ) F_19 ( V_1 , 5 , 0 ) ;
const T_3 * V_84 = F_16 ( V_1 , 6 , NULL ) ;
if ( V_92 == 0x0 && V_68 != V_71 ) {
F_7 ( V_1 , 2 , L_35
L_36 ) ;
return 0 ;
}
if ( V_92 != 0x0 && ( V_68 < 1 || V_68 > 64 ) ) {
F_7 ( V_1 , 2 , L_37
L_38 ) ;
return 0 ;
}
if ( ! V_86 || ! V_86 [ 0 ] ) {
F_7 ( V_1 , 1 , L_27 ) ;
return 0 ;
}
if ( F_98 ( V_86 ) ) {
F_7 ( V_1 , 1 , L_28 ) ;
return 0 ;
}
V_80 = F_105 ( V_81 , 1 ) ;
V_80 -> V_56 = - 2 ;
V_80 -> V_85 = - 1 ;
V_80 -> V_11 = F_13 ( V_11 ) ;
V_80 -> V_86 = F_13 ( V_86 ) ;
V_80 -> type = type ;
V_80 -> V_72 = F_100 ( V_76 ) ;
V_80 -> V_68 = V_68 ;
V_80 -> V_92 = V_92 ;
if ( V_84 && strcmp ( V_84 , V_80 -> V_11 ) != 0 ) {
V_80 -> V_84 = F_13 ( V_84 ) ;
} else {
V_80 -> V_84 = NULL ;
}
F_101 ( V_1 , V_80 ) ;
return 1 ;
}
static int F_107 ( T_2 * V_1 , enum V_61 type ) {
T_16 V_80 ;
const T_3 * V_86 = F_49 ( V_1 , 1 ) ;
const T_3 * V_11 = F_16 ( V_1 , 2 , V_86 ) ;
unsigned V_68 = F_103 ( V_1 , 3 , V_102 ) ;
const T_3 * V_84 = F_16 ( V_1 , 4 , NULL ) ;
if ( ! V_86 || ! V_86 [ 0 ] ) {
F_7 ( V_1 , 1 , L_27 ) ;
return 0 ;
}
if ( F_98 ( V_86 ) ) {
F_7 ( V_1 , 1 , L_28 ) ;
return 0 ;
}
if ( type == V_103 ) {
if ( V_68 < V_102 || V_68 > V_104 ) {
F_7 ( V_1 , 3 , L_39 ) ;
return 0 ;
}
}
V_80 = F_105 ( V_81 , 1 ) ;
V_80 -> V_56 = - 2 ;
V_80 -> V_85 = - 1 ;
V_80 -> V_11 = F_13 ( V_11 ) ;
V_80 -> V_86 = F_13 ( V_86 ) ;
V_80 -> type = type ;
V_80 -> V_72 = NULL ;
V_80 -> V_68 = V_68 ;
V_80 -> V_92 = 0 ;
if ( V_84 && strcmp ( V_84 , V_80 -> V_11 ) != 0 ) {
V_80 -> V_84 = F_13 ( V_84 ) ;
} else {
V_80 -> V_84 = NULL ;
}
F_101 ( V_1 , V_80 ) ;
return 1 ;
}
static int F_108 ( T_2 * V_1 , enum V_61 type ) {
T_16 V_80 ;
const T_3 * V_86 = F_49 ( V_1 , 1 ) ;
const T_3 * V_11 = F_16 ( V_1 , 2 , V_86 ) ;
const T_3 * V_84 = F_16 ( V_1 , 3 , NULL ) ;
if ( ! V_86 || ! V_86 [ 0 ] ) {
F_7 ( V_1 , 1 , L_27 ) ;
return 0 ;
}
if ( F_98 ( V_86 ) ) {
F_7 ( V_1 , 1 , L_28 ) ;
return 0 ;
}
V_80 = F_105 ( V_81 , 1 ) ;
V_80 -> V_56 = - 2 ;
V_80 -> V_85 = - 1 ;
V_80 -> V_11 = F_13 ( V_11 ) ;
V_80 -> V_86 = F_13 ( V_86 ) ;
V_80 -> type = type ;
V_80 -> V_72 = NULL ;
V_80 -> V_68 = V_71 ;
V_80 -> V_92 = 0 ;
if ( V_84 && strcmp ( V_84 , V_80 -> V_11 ) != 0 ) {
V_80 -> V_84 = F_13 ( V_84 ) ;
} else {
V_80 -> V_84 = NULL ;
}
F_101 ( V_1 , V_80 ) ;
return 1 ;
}
T_11 F_109 ( T_2 * V_1 ) {
T_16 V_80 = F_110 ( V_1 , 1 ) ;
T_3 * V_29 = ( T_3 * ) F_111 ( L_40 , V_80 -> V_56 , V_80 -> V_11 , V_80 -> V_86 , F_82 ( V_80 -> type ) , F_83 ( V_80 -> V_68 ) , V_80 -> V_72 , V_80 -> V_92 , V_80 -> V_84 ) ;
F_76 ( V_1 , V_29 ) ;
return 1 ;
}
static int F_112 ( T_2 * V_1 ) {
T_16 V_80 = F_110 ( V_1 , 1 ) ;
if ( ! V_80 ) {
F_7 ( V_1 , 1 , L_41 ) ;
} else if ( V_80 -> V_56 == - 2 ) {
F_52 ( V_80 -> V_11 ) ;
F_52 ( V_80 -> V_86 ) ;
F_52 ( V_80 -> V_84 ) ;
F_52 ( V_80 ) ;
}
return 0 ;
}
int F_113 ( T_2 * V_1 ) {
F_56 ( T_16 ) ;
return 1 ;
}
T_9 F_114 ( T_2 * V_1 ) {
#define F_115 1
#define F_116 2
const T_3 * V_11 = F_49 ( V_1 , F_115 ) ;
const T_3 * V_20 = F_49 ( V_1 , F_116 ) ;
if ( V_11 ) {
T_3 * V_105 ;
int V_106 ;
V_105 = F_117 ( V_11 , - 1 ) ;
V_106 = F_118 ( V_105 ) ;
F_52 ( V_105 ) ;
if ( V_106 > 0 ) {
F_51 ( F_114 , V_52 , L_42 ) ;
} else {
T_17 V_22 = ( V_107 * ) F_17 ( sizeof( V_107 ) ) ;
T_3 * V_108 = F_117 ( V_11 , - 1 ) ;
T_3 * V_109 = F_119 ( V_11 , - 1 ) ;
V_22 -> V_11 = V_109 ;
V_22 -> V_20 = F_13 ( V_20 ) ;
V_22 -> V_56 = F_120 ( V_22 -> V_20 , V_109 , V_108 ) ;
V_22 -> V_85 = - 1 ;
V_22 -> V_110 = FALSE ;
F_121 ( V_1 ) ;
V_22 -> V_111 = F_122 ( V_1 , V_112 ) ;
V_22 -> V_113 . V_11 = NULL ;
V_22 -> V_113 . V_16 = NULL ;
V_22 -> V_113 . V_20 = NULL ;
V_22 -> V_113 . V_13 . V_27 = 0 ;
V_22 -> V_113 . V_21 = NULL ;
V_22 -> V_113 . V_22 = V_22 ;
V_22 -> V_55 = NULL ;
V_22 -> V_114 = NULL ;
F_123 ( V_1 , V_112 , V_115 ) ;
F_76 ( V_1 , V_108 ) ;
F_124 ( V_1 , V_22 ) ;
F_125 ( V_1 , - 3 ) ;
F_124 ( V_1 , V_22 ) ;
F_71 ( 1 ) ;
}
} else
F_51 ( F_114 , V_52 , L_8 ) ;
return 0 ;
}
static int F_126 ( T_2 * V_1 ) {
T_17 V_22 = F_127 ( V_1 , 1 ) ;
T_3 * V_29 ;
if ( ! V_22 ) return 0 ;
V_29 = F_111 ( L_43 , V_22 -> V_11 ) ;
F_76 ( V_1 , V_29 ) ;
return 1 ;
}
T_18 F_128 ( T_2 * V_1 ) {
#define F_129 1
T_17 V_22 = F_127 ( V_1 , F_129 ) ;
if ( ! V_22 ) return 0 ;
if( ! V_22 -> V_110 ) {
if ( ! V_22 -> V_114 ) {
V_22 -> V_114 = F_130 ( V_116 , V_22 -> V_56 ) ;
}
F_131 ( V_22 -> V_114 ) ;
} else {
F_7 ( V_1 , 1 , L_44 ) ;
}
return 0 ;
}
static int F_132 ( T_2 * V_1 ) {
T_17 V_22 = F_133 ( V_1 , 1 ) ;
if ( V_22 -> V_114 ) {
F_134 ( V_1 , V_22 -> V_114 ) ;
return 1 ;
} else {
F_62 ( V_1 , L_45 ) ;
return 0 ;
}
}
static int F_135 ( T_2 * V_1 ) {
T_17 V_22 = F_133 ( V_1 , 1 ) ;
if ( F_136 ( V_1 , 3 ) ) {
T_3 * V_108 = F_117 ( V_22 -> V_11 , - 1 ) ;
F_123 ( V_1 , V_112 , V_117 ) ;
F_137 ( V_1 , 1 ) ;
F_76 ( V_1 , V_22 -> V_11 ) ;
F_137 ( V_1 , 2 ) ;
F_125 ( V_1 , 1 ) ;
V_22 -> V_114 = F_130 ( V_116 , V_22 -> V_56 ) ;
F_138 ( V_108 , V_116 , V_22 -> V_56 ) ;
return 0 ;
} else {
F_7 ( V_1 , 3 , L_46 ) ;
return 0 ;
}
}
static int F_139 ( T_2 * V_1 ) {
T_17 V_22 = F_133 ( V_1 , 1 ) ;
F_140 ( V_1 , & V_22 -> V_113 ) ;
return 1 ;
}
static int F_141 ( T_2 * V_1 ) {
T_17 V_22 = F_133 ( V_1 , 1 ) ;
if ( F_136 ( V_1 , 3 ) ) {
F_142 ( V_1 , V_118 ) ;
F_137 ( V_1 , 1 ) ;
F_76 ( V_1 , V_22 -> V_11 ) ;
F_137 ( V_1 , 2 ) ;
F_125 ( V_1 , 1 ) ;
} else {
F_7 ( V_1 , 3 , L_47 ) ;
}
return 0 ;
}
static int F_143 ( T_2 * V_1 ) {
T_17 V_22 = F_133 ( V_1 , 1 ) ;
if ( F_136 ( V_1 , 3 ) ) {
F_142 ( V_1 , V_119 ) ;
F_137 ( V_1 , 1 ) ;
F_76 ( V_1 , V_22 -> V_11 ) ;
F_137 ( V_1 , 2 ) ;
F_125 ( V_1 , 1 ) ;
return 0 ;
} else {
F_7 ( V_1 , 3 , L_48 ) ;
return 0 ;
}
}
static int F_144 ( T_2 * V_1 ) {
T_17 V_22 = F_133 ( V_1 , 1 ) ;
F_76 ( V_1 , V_22 -> V_11 ) ;
return 1 ;
}
static int F_145 ( T_2 * V_1 ) {
T_17 V_22 = F_133 ( V_1 , 1 ) ;
F_76 ( V_1 , V_22 -> V_20 ) ;
return 1 ;
}
static int F_146 ( T_2 * V_1 ) {
T_17 V_22 = F_133 ( V_1 , 1 ) ;
F_123 ( V_1 , V_112 , V_22 -> V_111 ) ;
return 1 ;
}
void F_147 ( char * V_29 , T_2 * V_1 ) {
int V_120 ;
for ( V_120 = 1 ; V_120 <= F_104 ( V_1 ) ; V_120 ++ ) {
printf ( L_49 , V_29 , V_120 , F_148 ( V_1 , F_149 ( V_1 , V_120 ) ) ) ;
}
printf ( L_50 ) ;
}
static int F_150 ( T_2 * V_1 ) {
T_17 V_22 = F_133 ( V_1 , 1 ) ;
#define F_151 2
#define F_152 3
#define F_153 3
F_123 ( V_1 , V_112 , V_22 -> V_111 ) ;
F_137 ( V_1 , F_151 ) ;
if( F_87 ( V_1 , F_152 ) ) {
for ( F_4 ( V_1 ) ; F_5 ( V_1 , F_152 ) ; ) {
if ( F_154 ( V_1 , 5 ) ) {
F_122 ( V_1 , F_151 ) ;
} else if ( ! F_86 ( V_1 , 5 ) ) {
return F_62 ( V_1 , L_51 ) ;
}
}
} else if ( F_154 ( V_1 , F_153 ) ) {
F_155 ( V_1 , F_153 ) ;
F_122 ( V_1 , F_151 ) ;
} else {
return F_62 ( V_1 , L_52 ) ;
}
F_155 ( V_1 , 3 ) ;
return 1 ;
}
static int F_156 ( T_2 * V_1 ) {
T_17 V_22 = F_127 ( V_1 , 1 ) ;
const T_3 * V_11 = F_49 ( V_1 , 2 ) ;
const T_19 * V_121 ;
if ( ! ( V_22 && V_11 ) ) return 0 ;
for ( V_121 = V_122 ; V_121 -> V_11 ; V_121 ++ ) {
if ( F_61 ( V_11 , V_121 -> V_11 ) ) {
if ( V_121 -> V_123 ) {
return V_121 -> V_123 ( V_1 ) ;
} else {
F_62 ( V_1 , L_53 , V_11 ) ;
return 0 ;
}
}
}
F_62 ( V_1 , L_54 , V_11 ) ;
return 0 ;
}
static int F_157 ( T_2 * V_1 ) {
T_17 V_22 = F_127 ( V_1 , 1 ) ;
const T_3 * V_11 = F_49 ( V_1 , 2 ) ;
const T_19 * V_121 ;
if ( ! ( V_22 && V_11 ) ) return 0 ;
for ( V_121 = V_122 ; V_121 -> V_11 ; V_121 ++ ) {
if ( F_61 ( V_11 , V_121 -> V_11 ) ) {
if ( V_121 -> V_124 ) {
return V_121 -> V_124 ( V_1 ) ;
} else {
F_62 ( V_1 , L_55 , V_11 ) ;
return 0 ;
}
}
}
F_62 ( V_1 , L_54 , V_11 ) ;
return 0 ;
}
static int F_158 ( T_2 * V_1 V_59 ) {
return 0 ;
}
int F_159 ( T_2 * V_1 ) {
F_80 ( T_17 ) ;
F_121 ( V_1 ) ;
V_115 = F_122 ( V_1 , V_112 ) ;
F_160 ( V_1 , F_114 ) ;
F_161 ( V_1 , L_56 ) ;
return 1 ;
}
int F_162 ( T_2 * V_1 ) {
F_163 ( V_1 , 0 ) ;
F_123 ( V_1 , V_112 , V_115 ) ;
for ( F_4 ( V_1 ) ; F_5 ( V_1 , 1 ) ; F_10 ( V_1 , 2 ) ) {
T_4 * V_125 = F_2 ( TRUE , TRUE , sizeof( V_126 ) ) ;
T_4 * V_127 = F_2 ( TRUE , TRUE , sizeof( V_128 * ) ) ;
T_17 V_22 ;
V_22 = F_127 ( V_1 , 3 ) ;
F_123 ( V_1 , V_112 , V_22 -> V_111 ) ;
for ( F_4 ( V_1 ) ; F_5 ( V_1 , 4 ) ; F_10 ( V_1 , 1 ) ) {
T_16 V_80 = F_110 ( V_1 , 6 ) ;
V_126 V_129 = { & ( V_80 -> V_56 ) , { V_80 -> V_11 , V_80 -> V_86 , V_80 -> type , V_80 -> V_68 , F_99 ( V_80 -> V_72 ) , V_80 -> V_92 , V_80 -> V_84 , V_130 } } ;
V_128 * V_131 = & ( V_80 -> V_85 ) ;
if ( V_80 -> V_56 != - 2 ) {
return F_62 ( V_1 , L_57 ) ;
}
V_80 -> V_56 = - 1 ;
F_14 ( V_125 , V_129 ) ;
F_14 ( V_127 , V_131 ) ;
}
F_164 ( V_22 -> V_56 , ( V_126 * ) V_125 -> V_15 , V_125 -> V_132 ) ;
F_165 ( ( V_128 * * ) V_127 -> V_15 , V_127 -> V_132 ) ;
F_8 ( V_125 , FALSE ) ;
F_8 ( V_127 , FALSE ) ;
}
return 0 ;
}
T_9 F_166 ( T_2 * V_1 ) {
#define F_167 1
const T_3 * V_11 = F_49 ( V_1 , F_167 ) ;
T_20 V_133 ;
if ( ! V_11 )
F_51 ( F_166 , V_52 , L_8 ) ;
if ( ( V_133 = F_168 ( V_11 ) ) ) {
F_134 ( V_1 , V_133 ) ;
F_71 ( 1 ) ;
} else
F_51 ( F_166 , V_52 , L_58 ) ;
}
T_21 F_169 ( T_2 * V_1 ) {
#define F_170 2
#define F_171 3
#define F_172 4
T_20 V_133 = F_173 ( V_1 , 1 ) ;
T_22 V_134 = F_174 ( V_1 , F_170 ) ;
T_23 V_135 = F_175 ( V_1 , F_171 ) ;
T_24 V_136 = F_176 ( V_1 , F_172 ) ;
const char * volatile error = NULL ;
if ( ! ( V_133 && V_134 && V_135 ) ) return 0 ;
F_177 {
F_178 ( V_133 , V_134 -> V_137 , V_135 -> V_138 , V_136 -> V_139 ) ;
} F_179 {
F_180 ( V_134 -> V_137 , V_135 -> V_138 , V_136 -> V_139 , V_140 , V_141 ) ;
error = L_59 ;
} V_142 ;
if ( error ) { F_70 ( F_169 , error ) ; }
return 0 ;
}
T_11 F_181 ( T_2 * V_1 ) {
T_20 V_133 = F_173 ( V_1 , 1 ) ;
if ( ! V_133 ) return 0 ;
F_76 ( V_1 , F_182 ( V_133 ) ) ;
F_71 ( 1 ) ;
}
static int F_183 ( T_2 * V_1 V_59 ) {
return 0 ;
}
int F_184 ( T_2 * V_1 ) {
F_56 ( T_20 ) ;
return 1 ;
}
T_9 F_185 ( T_2 * V_1 ) {
#define F_186 1
#define F_187 2
#define F_188 3
#define F_189 4
const T_3 * V_11 = ( const T_3 * ) F_49 ( V_1 , F_186 ) ;
const T_3 * V_143 = ( const T_3 * ) F_16 ( V_1 , F_187 , V_11 ) ;
enum V_61 type = (enum V_61 ) F_103 ( V_1 , F_188 , V_144 ) ;
unsigned V_68 = ( unsigned ) F_103 ( V_1 , F_189 , V_93 ) ;
if( ! ( V_11 && V_143 ) ) return 0 ;
switch( type ) {
case V_145 :
V_68 = V_71 ;
case V_146 :
case V_147 :
case V_148 :
case V_144 :
{
T_25 V_149 = ( T_25 ) F_17 ( sizeof( struct V_150 ) ) ;
V_11 = F_13 ( V_11 ) ;
V_143 = F_13 ( V_143 ) ;
V_149 -> V_151 = F_190 ( V_11 , V_143 , type , V_68 ) ;
V_149 -> V_11 = V_11 ;
F_191 ( V_1 , V_149 ) ;
}
F_71 ( 1 ) ;
default:
F_192 ( F_185 , TYPE , L_60 ) ;
}
return 0 ;
}
T_9 F_193 ( T_2 * V_1 ) {
#define F_194 1
const T_3 * V_11 = F_49 ( V_1 , F_194 ) ;
T_26 V_151 ;
if( ! V_11 ) return 0 ;
V_151 = F_195 ( V_11 ) ;
if ( V_151 ) {
T_25 V_149 = ( T_25 ) F_17 ( sizeof( struct V_150 ) ) ;
V_149 -> V_151 = V_151 ;
V_149 -> V_11 = F_13 ( V_11 ) ;
F_191 ( V_1 , V_149 ) ;
F_71 ( 1 ) ;
} else
F_51 ( F_193 , V_152 , L_61 ) ;
}
T_21 F_196 ( T_2 * V_1 ) {
#define F_197 2
#define F_198 3
T_25 V_149 = F_199 ( V_1 , 1 ) ;
T_27 type ;
T_20 V_114 ;
if ( ! V_149 ) return 0 ;
if( F_200 ( V_1 , F_198 ) ) {
T_17 V_50 ;
V_50 = F_133 ( V_1 , F_198 ) ;
V_114 = V_50 -> V_114 ;
if ( ! V_114 )
F_51 ( F_196 , V_153 , L_62 ) ;
} else if ( F_201 ( V_1 , F_198 ) ) {
V_114 = F_202 ( V_1 , F_198 ) ;
} else
F_51 ( F_196 , V_153 , L_63 ) ;
type = F_203 ( V_149 -> V_11 ) ;
if ( type == V_145 ) {
T_3 * V_45 = F_13 ( F_49 ( V_1 , F_197 ) ) ;
F_204 ( V_149 -> V_11 , V_45 , V_114 ) ;
F_52 ( V_45 ) ;
} else if ( type == V_144 || type == V_147 || type == V_146 || type == V_148 ) {
if ( F_11 ( V_1 , F_197 ) ) {
int V_154 = F_205 ( V_1 , F_197 ) ;
F_206 ( V_149 -> V_11 , V_154 , V_114 ) ;
} else {
T_3 * V_45 = F_13 ( F_49 ( V_1 , F_197 ) ) ;
T_8 * V_38 ;
if ( F_50 ( & V_38 , V_45 , V_155 ) == V_46 )
F_207 ( V_149 -> V_11 , V_38 , V_114 ) ;
else
F_51 ( F_196 , V_156 , L_64 ) ;
F_52 ( V_45 ) ;
}
} else {
F_62 ( V_1 , L_65 , type ) ;
}
return 0 ;
}
T_21 F_208 ( T_2 * V_1 ) {
#define F_209 2
#define F_210 3
T_25 V_149 = F_199 ( V_1 , 1 ) ;
T_27 type ;
T_20 V_114 ;
if ( ! V_149 ) return 0 ;
if( F_200 ( V_1 , F_210 ) ) {
T_17 V_50 ;
V_50 = F_133 ( V_1 , F_210 ) ;
V_114 = V_50 -> V_114 ;
if ( ! V_114 )
F_51 ( F_208 , V_153 , L_66 ) ;
} else if ( F_201 ( V_1 , F_210 ) ) {
V_114 = F_202 ( V_1 , F_210 ) ;
} else
F_51 ( F_208 , V_153 , L_63 ) ;
type = F_203 ( V_149 -> V_11 ) ;
if ( type == V_145 ) {
T_3 * V_45 = F_13 ( F_49 ( V_1 , F_209 ) ) ;
F_211 ( V_149 -> V_11 , V_114 ) ;
F_204 ( V_149 -> V_11 , V_45 , V_114 ) ;
F_52 ( V_45 ) ;
} else if ( type == V_144 || type == V_147 || type == V_146 || type == V_148 ) {
if ( F_11 ( V_1 , F_209 ) ) {
int V_154 = F_205 ( V_1 , F_209 ) ;
F_211 ( V_149 -> V_11 , V_114 ) ;
F_206 ( V_149 -> V_11 , V_154 , V_114 ) ;
} else {
T_3 * V_45 = F_13 ( F_49 ( V_1 , F_209 ) ) ;
T_8 * V_38 ;
if ( F_50 ( & V_38 , V_45 , V_155 ) == V_46 ) {
F_211 ( V_149 -> V_11 , V_114 ) ;
F_207 ( V_149 -> V_11 , V_38 , V_114 ) ;
} else {
F_51 ( F_208 , V_156 , L_64 ) ;
}
F_52 ( V_45 ) ;
}
} else {
F_62 ( V_1 , L_65 , type ) ;
}
return 0 ;
}
T_21 F_212 ( T_2 * V_1 ) {
#define F_213 2
#define F_214 3
T_25 V_149 = F_199 ( V_1 , 1 ) ;
T_27 type ;
T_20 V_114 ;
if ( ! V_149 ) return 0 ;
if( F_200 ( V_1 , F_214 ) ) {
T_17 V_50 ;
V_50 = F_133 ( V_1 , F_214 ) ;
V_114 = V_50 -> V_114 ;
} else if ( F_201 ( V_1 , F_214 ) ) {
V_114 = F_202 ( V_1 , F_214 ) ;
} else
F_51 ( F_212 , V_153 , L_63 ) ;
type = F_203 ( V_149 -> V_11 ) ;
if ( type == V_145 ) {
T_3 * V_45 = F_13 ( F_49 ( V_1 , F_213 ) ) ;
F_215 ( V_149 -> V_11 , V_45 , V_114 ) ;
F_52 ( V_45 ) ;
} else if ( type == V_144 || type == V_147 || type == V_146 || type == V_148 ) {
if ( F_11 ( V_1 , F_213 ) ) {
int V_154 = F_205 ( V_1 , F_213 ) ;
F_216 ( V_149 -> V_11 , V_154 , V_114 ) ;
} else {
T_3 * V_45 = F_13 ( F_49 ( V_1 , F_213 ) ) ;
T_8 * V_38 ;
if ( F_50 ( & V_38 , V_45 , V_155 ) == V_46 )
F_217 ( V_149 -> V_11 , V_38 , V_114 ) ;
else
F_51 ( F_212 , V_156 , L_64 ) ;
F_52 ( V_45 ) ;
}
}
return 0 ;
}
T_21 F_218 ( T_2 * V_1 ) {
#define F_219 2
T_25 V_149 = F_199 ( V_1 , 1 ) ;
T_20 V_114 ;
if ( ! V_149 ) return 0 ;
if( F_200 ( V_1 , F_219 ) ) {
T_17 V_50 ;
V_50 = F_133 ( V_1 , F_219 ) ;
V_114 = V_50 -> V_114 ;
} else if ( F_201 ( V_1 , F_219 ) ) {
V_114 = F_202 ( V_1 , F_219 ) ;
} else
F_51 ( F_218 , V_153 , L_63 ) ;
F_211 ( V_149 -> V_11 , V_114 ) ;
return 0 ;
}
T_21 F_220 ( T_2 * V_1 ) {
#define F_221 2
#define F_222 3
#define F_223 4
#define F_224 5
T_25 V_149 = F_199 ( V_1 , 1 ) ;
T_22 V_134 = F_174 ( V_1 , F_222 ) ;
T_23 V_135 = F_175 ( V_1 , F_223 ) ;
T_24 V_136 = F_176 ( V_1 , F_224 ) ;
T_27 type ;
T_7 V_157 = FALSE ;
const T_3 * volatile error = NULL ;
if ( ! ( V_149 && V_134 && V_134 -> V_137 && V_135 && V_136 ) ) return 0 ;
type = F_203 ( V_149 -> V_11 ) ;
F_177 {
if ( type == V_145 ) {
const T_3 * V_45 = F_49 ( V_1 , F_221 ) ;
if ( ! V_45 )
V_157 = TRUE ;
else if ( F_225 ( V_149 -> V_151 , V_45 , V_134 -> V_137 , V_135 -> V_138 , V_136 -> V_139 ) )
V_157 = TRUE ;
} else if ( type == V_144 || type == V_147 || type == V_146 || type == V_148 ) {
int V_154 = F_205 ( V_1 , F_221 ) ;
if ( F_226 ( V_149 -> V_151 , V_154 , V_134 -> V_137 , V_135 -> V_138 , V_136 -> V_139 ) )
V_157 = TRUE ;
} else {
F_62 ( V_1 , L_67 ) ;
}
if ( ! V_157 )
F_178 ( V_158 , V_134 -> V_137 , V_135 -> V_138 , V_136 -> V_139 ) ;
} F_179 {
F_180 ( V_134 -> V_137 , V_135 -> V_138 , V_136 -> V_139 , V_140 , V_141 ) ;
error = L_59 ;
} V_142 ;
if ( error ) { F_70 ( F_220 , error ) ; }
return 0 ;
}
T_21 F_227 ( T_2 * V_1 ) {
#define F_221 2
T_25 V_149 = F_199 ( V_1 , 1 ) ;
T_27 type ;
T_28 V_114 = V_158 ;
if ( ! V_149 ) return 0 ;
type = F_203 ( V_149 -> V_11 ) ;
if ( type == V_145 ) {
const T_3 * V_45 = F_49 ( V_1 , F_221 ) ;
if ( ! V_45 ) F_51 ( F_220 , V_156 , L_8 ) ;
V_114 = F_228 ( V_149 -> V_151 , V_45 ) ;
} else if ( type == V_144 || type == V_147 || type == V_146 || type == V_148 ) {
int V_154 = F_205 ( V_1 , F_221 ) ;
V_114 = F_229 ( V_149 -> V_151 , V_154 ) ;
}
if ( V_114 ) {
F_134 ( V_1 , V_114 ) ;
F_71 ( 1 ) ;
} else {
F_4 ( V_1 ) ;
F_71 ( 1 ) ;
}
}
T_11 F_230 ( T_2 * V_1 ) {
T_25 V_149 = F_199 ( V_1 , 1 ) ;
T_29 * V_29 ;
T_27 type ;
if ( ! V_149 ) return 0 ;
type = F_203 ( V_149 -> V_11 ) ;
V_29 = F_231 ( L_68 ) ;
switch( type ) {
case V_145 :
{
F_232 ( V_29 , L_69 , V_149 -> V_11 ) ;
break;
}
case V_146 :
case V_147 :
case V_148 :
case V_144 :
{
int V_68 = F_233 ( V_149 -> V_11 ) ;
F_232 ( V_29 , L_70 , V_149 -> V_11 , V_68 ) ;
break;
}
default:
F_62 ( V_1 , L_71 ) ;
}
F_76 ( V_1 , V_29 -> V_64 ) ;
F_234 ( V_29 , TRUE ) ;
F_71 ( 1 ) ;
}
static int F_235 ( T_2 * V_1 V_59 ) {
return 0 ;
}
int F_236 ( T_2 * V_1 ) {
F_56 ( T_25 ) ;
return 1 ;
}
