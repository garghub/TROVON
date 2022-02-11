static T_1 * F_1 ( T_2 * V_1 , int V_2 , int V_3 )
{
static T_1 * V_4 ;
F_2 ( & V_4 , F_3 ( F_4 ( V_1 , V_2 ) ) , ( V_5 ) F_5 ( V_1 , V_3 ) ) ;
return V_4 ;
}
static T_3 * F_6 ( T_2 * V_1 , int V_6 )
{
double V_7 ;
const T_4 * V_8 , * V_9 ;
T_3 * V_4 , V_10 = { NULL , NULL , - 1 } ;
T_5 * V_11 = F_7 ( TRUE , TRUE , sizeof( T_3 ) ) ;
F_8 ( V_1 , V_6 , V_12 ) ;
F_9 ( V_1 ) ;
while ( F_10 ( V_1 , V_6 ) ) {
T_3 V_13 = { NULL , NULL , - 1 } ;
F_8 ( V_1 , - 1 , V_12 ) ;
F_9 ( V_1 ) ;
F_10 ( V_1 , - 2 ) ;
if ( ! F_11 ( V_1 , - 1 ) ) {
F_12 ( V_1 , V_6 , L_1 ) ;
F_13 ( V_11 , TRUE ) ;
return NULL ;
}
V_8 = F_14 ( V_1 , - 1 ) ;
F_15 ( V_1 , 1 ) ;
F_10 ( V_1 , - 2 ) ;
if ( ! F_11 ( V_1 , - 1 ) ) {
F_12 ( V_1 , V_6 , L_2 ) ;
F_13 ( V_11 , TRUE ) ;
return NULL ;
}
V_9 = F_14 ( V_1 , - 1 ) ;
F_15 ( V_1 , 1 ) ;
F_10 ( V_1 , - 2 ) ;
if ( ! F_16 ( V_1 , - 1 ) ) {
F_12 ( V_1 , V_6 , L_3 ) ;
F_13 ( V_11 , TRUE ) ;
return NULL ;
}
V_7 = F_5 ( V_1 , - 1 ) ;
V_13 . V_14 = F_3 ( V_8 ) ;
V_13 . V_15 = F_3 ( V_9 ) ;
V_13 . V_16 = ( V_5 ) V_7 ;
F_17 ( V_11 , V_13 ) ;
F_15 ( V_1 , 3 ) ;
}
F_17 ( V_11 , V_10 ) ;
V_4 = ( T_3 * ) V_11 -> V_17 ;
F_13 ( V_11 , FALSE ) ;
return V_4 ;
}
static int F_18 ( T_2 * V_1 , T_6 type ) {
const T_4 * V_18 = F_19 ( V_1 , 1 , NULL ) ;
const T_4 * V_19 = F_19 ( V_1 , 3 , L_4 ) ;
T_7 V_20 = ( V_21 * ) F_20 ( sizeof( V_21 ) ) ;
V_20 -> V_14 = NULL ;
V_20 -> V_18 = V_18 ? F_3 ( V_18 ) : NULL ;
V_20 -> V_22 = F_3 ( V_19 ) ;
V_20 -> type = type ;
V_20 -> V_23 = NULL ;
V_20 -> V_24 = NULL ;
switch( type ) {
case V_25 : {
T_8 V_26 = F_21 ( V_1 , 2 ) ;
V_20 -> V_16 . V_27 = V_26 ;
break;
}
case V_28 : {
V_5 V_26 = ( V_5 ) F_22 ( V_1 , 2 , 0 ) ;
V_20 -> V_16 . V_29 = V_26 ;
break;
}
case V_30 : {
T_4 * V_26 = F_3 ( F_19 ( V_1 , 2 , L_4 ) ) ;
V_20 -> V_16 . V_31 = V_26 ;
break;
}
case V_32 : {
V_5 V_26 = ( V_5 ) F_22 ( V_1 , 2 , 0 ) ;
T_3 * V_33 = F_6 ( V_1 , 4 ) ;
T_8 V_34 = F_21 ( V_1 , 5 ) ;
V_20 -> V_16 . V_13 = V_26 ;
V_20 -> V_35 . V_36 . V_37 = V_33 ;
V_20 -> V_35 . V_36 . V_38 = V_34 ;
break;
}
case V_39 : {
T_1 * V_40 = F_1 ( V_1 , 2 , 4 ) ;
V_5 V_41 = ( V_5 ) F_22 ( V_1 , 4 , 0 ) ;
V_20 -> V_16 . V_42 = V_40 ;
V_20 -> V_35 . V_43 = V_41 ;
break;
}
case V_44 : {
break;
}
default:
F_23 () ;
break;
}
F_24 ( V_1 , V_20 ) ;
return 1 ;
}
T_9 F_25 ( T_2 * V_1 ) {
#define F_26 1
#define F_27 2
#define F_28 3
return F_18 ( V_1 , V_25 ) ;
}
T_9 F_29 ( T_2 * V_1 ) {
#define F_30 1
#define F_31 2
#define F_32 3
return F_18 ( V_1 , V_28 ) ;
}
T_9 F_33 ( T_2 * V_1 ) {
#define F_34 1
#define F_35 2
#define F_36 3
return F_18 ( V_1 , V_30 ) ;
}
T_9 F_37 ( T_2 * V_1 ) {
#define F_38 1
#define F_39 2
#define F_40 3
#define F_41 4
#define F_42 5
return F_18 ( V_1 , V_32 ) ;
}
T_9 F_43 ( T_2 * V_1 ) {
#define F_44 1
#define F_45 2
#define F_46 3
#define F_47 4
return F_18 ( V_1 , V_39 ) ;
}
T_9 F_48 ( T_2 * V_1 ) {
#define F_49 1
#define F_50 2
return F_18 ( V_1 , V_44 ) ;
}
static int F_51 ( T_2 * V_1 ) {
T_7 V_20 = F_52 ( V_1 , 1 ) ;
if ( V_20 && ! V_20 -> V_14 ) {
F_53 ( V_20 -> V_18 ) ;
F_53 ( V_20 -> V_22 ) ;
if ( V_20 -> type == V_30 )
F_53 ( ( void * ) V_20 -> V_16 . V_31 ) ;
F_53 ( V_20 ) ;
}
return 0 ;
}
T_10 F_54 ( T_2 * V_1 ) {
F_55 ( T_7 ) ;
return 1 ;
}
T_11 F_56 ( T_2 * V_1 ) {
#define F_57 2
#define F_58 3
T_7 V_45 = F_59 ( V_1 , 1 ) ;
const T_4 * V_14 = F_4 ( V_1 , F_57 ) ;
T_7 V_20 = F_52 ( V_1 , F_58 ) ;
T_7 V_46 ;
const T_4 * V_47 ;
if ( ! V_45 ) return 0 ;
if ( ! V_14 )
F_60 ( F_56 , V_48 , L_5 ) ;
if ( ! V_20 )
F_60 ( F_56 , V_49 , L_6 ) ;
if ( V_20 -> V_14 )
F_60 ( F_56 , V_48 , L_7 ) ;
if ( V_20 -> V_24 )
F_60 ( F_56 , V_49 , L_8 ) ;
V_46 = V_45 ;
do {
if ( V_46 -> V_14 && F_61 ( V_46 -> V_14 , V_14 ) ) {
F_62 ( V_1 , L_9 , V_14 ) ;
return 0 ;
}
for ( V_47 = V_14 ; * V_47 != '\0' ; V_47 ++ ) {
if ( ! isascii ( ( V_50 ) * V_47 ) ||
( ! islower ( ( V_50 ) * V_47 ) && ! isdigit ( ( V_50 ) * V_47 ) && * V_47 != '_' && * V_47 != '.' ) )
{
F_62 ( V_1 , L_10 , V_14 ) ;
return 0 ;
}
}
if ( ! V_46 -> V_23 ) {
V_46 -> V_23 = V_20 ;
V_20 -> V_14 = F_3 ( V_14 ) ;
if ( ! V_20 -> V_18 )
V_20 -> V_18 = F_3 ( V_14 ) ;
if ( ! V_45 -> V_24 -> V_51 ) {
V_45 -> V_24 -> V_51 = F_63 ( V_45 -> V_24 -> V_52 , NULL ) ;
}
switch( V_20 -> type ) {
case V_25 :
F_64 ( V_45 -> V_24 -> V_51 ,
V_20 -> V_14 ,
V_20 -> V_18 ,
V_20 -> V_22 ,
& ( V_20 -> V_16 . V_27 ) ) ;
break;
case V_28 :
F_65 ( V_45 -> V_24 -> V_51 ,
V_20 -> V_14 ,
V_20 -> V_18 ,
V_20 -> V_22 ,
10 ,
& ( V_20 -> V_16 . V_29 ) ) ;
break;
case V_30 :
F_66 ( V_45 -> V_24 -> V_51 ,
V_20 -> V_14 ,
V_20 -> V_18 ,
V_20 -> V_22 ,
& ( V_20 -> V_16 . V_31 ) ) ;
break;
case V_32 :
F_67 ( V_45 -> V_24 -> V_51 ,
V_20 -> V_14 ,
V_20 -> V_18 ,
V_20 -> V_22 ,
& ( V_20 -> V_16 . V_13 ) ,
V_20 -> V_35 . V_36 . V_37 ,
V_20 -> V_35 . V_36 . V_38 ) ;
break;
case V_39 :
F_68 ( V_45 -> V_24 -> V_51 ,
V_20 -> V_14 ,
V_20 -> V_18 ,
V_20 -> V_22 ,
& ( V_20 -> V_16 . V_42 ) ,
V_20 -> V_35 . V_43 ) ;
break;
case V_44 :
F_69 ( V_45 -> V_24 -> V_51 ,
V_20 -> V_14 ,
V_20 -> V_18 ,
V_20 -> V_22 ) ;
break;
default:
F_70 ( F_56 , L_11 ) ;
}
V_20 -> V_24 = V_46 -> V_24 ;
F_71 ( 0 ) ;
}
} while ( ( V_46 = V_46 -> V_23 ) );
F_62 ( V_1 , L_12 ) ;
F_71 ( 0 ) ;
}
T_11 F_72 ( T_2 * V_1 ) {
#define F_73 2
T_7 V_45 = F_59 ( V_1 , 1 ) ;
const T_4 * V_14 = F_4 ( V_1 , F_73 ) ;
if ( ! ( V_14 && V_45 ) ) return 0 ;
V_45 = V_45 -> V_23 ;
do {
if ( F_61 ( V_45 -> V_14 , V_14 ) ) {
switch ( V_45 -> type ) {
case V_25 : F_74 ( V_1 , V_45 -> V_16 . V_27 ) ; break;
case V_28 : F_75 ( V_1 , ( V_53 ) V_45 -> V_16 . V_29 ) ; break;
case V_30 : F_76 ( V_1 , V_45 -> V_16 . V_31 ) ; break;
case V_32 : F_75 ( V_1 , ( V_53 ) V_45 -> V_16 . V_13 ) ; break;
case V_39 : F_76 ( V_1 , F_77 ( V_45 -> V_16 . V_42 ) ) ; break;
default: F_70 ( F_72 , L_11 ) ;
}
F_71 ( 1 ) ;
}
} while ( ( V_45 = V_45 -> V_23 ) );
F_60 ( F_72 , V_48 , L_13 ) ;
}
static int F_78 ( T_2 * V_1 V_54 ) {
return 0 ;
}
T_10 F_79 ( T_2 * V_1 ) {
F_80 ( V_55 ) ;
return 1 ;
}
static enum V_56 F_81 ( const T_4 * type ) {
const T_12 * V_57 ;
for ( V_57 = V_58 ; V_57 -> V_59 ; V_57 ++ ) {
if ( F_61 ( V_57 -> V_59 , type ) ) {
return V_57 -> V_60 ;
}
}
return V_61 ;
}
static const T_4 * F_82 ( enum V_56 V_62 ) {
const T_12 * V_57 ;
for ( V_57 = V_58 ; V_57 -> V_59 ; V_57 ++ ) {
if ( V_57 -> V_60 == V_62 ) {
return V_57 -> V_59 ;
}
}
return NULL ;
}
static const T_4 * F_83 ( unsigned V_63 ) {
const struct V_64 * V_27 ;
for ( V_27 = V_65 ; V_27 -> V_59 ; V_27 ++ ) {
if ( V_63 == V_27 -> V_63 )
return V_27 -> V_59 ;
}
return NULL ;
}
static unsigned F_84 ( const T_4 * V_59 ) {
const struct V_64 * V_27 ;
for ( V_27 = V_65 ; V_27 -> V_59 ; V_27 ++ ) {
if ( F_61 ( V_59 , V_27 -> V_59 ) )
return V_27 -> V_63 ;
}
return V_66 ;
}
static T_13 * F_85 ( T_2 * V_1 , int V_6 ) {
T_5 * V_67 = F_7 ( TRUE , TRUE , sizeof( T_13 ) ) ;
T_13 * V_4 ;
if( F_86 ( V_1 , V_6 ) ) {
return NULL ;
} else if ( ! F_87 ( V_1 , V_6 ) ) {
F_12 ( V_1 , V_6 , L_14 ) ;
F_13 ( V_67 , TRUE ) ;
return NULL ;
}
F_9 ( V_1 ) ;
while ( F_10 ( V_1 , V_6 ) != 0 ) {
T_13 V_68 = { 0 , NULL } ;
if ( ! F_16 ( V_1 , - 2 ) ) {
F_12 ( V_1 , V_6 , L_15 ) ;
F_13 ( V_67 , TRUE ) ;
return NULL ;
}
if ( ! F_11 ( V_1 , - 1 ) ) {
F_12 ( V_1 , V_6 , L_16 ) ;
F_13 ( V_67 , TRUE ) ;
return NULL ;
}
V_68 . V_16 = ( V_5 ) F_5 ( V_1 , - 2 ) ;
V_68 . V_69 = F_3 ( F_14 ( V_1 , - 1 ) ) ;
F_17 ( V_67 , V_68 ) ;
F_15 ( V_1 , 1 ) ;
}
V_4 = ( T_13 * ) V_67 -> V_17 ;
F_13 ( V_67 , FALSE ) ;
return V_4 ;
}
static T_14 * F_88 ( T_2 * V_1 , int V_6 ) {
T_5 * V_70 = F_7 ( TRUE , TRUE , sizeof( T_14 ) ) ;
T_14 * V_4 ;
T_14 V_71 = { L_17 , L_18 } ;
if ( F_86 ( V_1 , V_6 ) ) {
return NULL ;
} else if ( ! F_87 ( V_1 , V_6 ) ) {
F_12 ( V_1 , V_6 , L_14 ) ;
F_13 ( V_70 , TRUE ) ;
return NULL ;
}
F_9 ( V_1 ) ;
while ( F_10 ( V_1 , V_6 ) ) {
if ( ! F_16 ( V_1 , - 2 ) ) {
F_12 ( V_1 , V_6 , L_19 ) ;
F_13 ( V_70 , TRUE ) ;
return NULL ;
}
if ( ! F_11 ( V_1 , - 1 ) ) {
F_12 ( V_1 , V_6 , L_20 ) ;
F_13 ( V_70 , TRUE ) ;
return NULL ;
}
if ( ( V_5 ) F_5 ( V_1 , - 2 ) == 1 )
V_71 . V_72 = F_3 ( F_14 ( V_1 , - 1 ) ) ;
if ( ( V_5 ) F_5 ( V_1 , - 2 ) == 2 )
V_71 . V_73 = F_3 ( F_14 ( V_1 , - 1 ) ) ;
F_15 ( V_1 , 1 ) ;
}
F_17 ( V_70 , V_71 ) ;
V_4 = ( T_14 * ) V_70 -> V_17 ;
F_13 ( V_70 , FALSE ) ;
return V_4 ;
}
T_9 F_89 ( T_2 * V_1 ) {
#define F_90 1
#define F_91 2
#define F_92 3
#define F_93 4
#define F_94 5
#define F_95 6
#define F_96 7
T_15 V_74 = ( V_75 * ) F_20 ( sizeof( V_75 ) ) ;
T_13 * V_67 = NULL ;
T_14 * V_70 = NULL ;
const T_4 * V_76 ;
V_74 -> V_52 = - 2 ;
V_74 -> V_77 = - 1 ;
V_74 -> V_14 = F_3 ( F_4 ( V_1 , F_90 ) ) ;
V_74 -> V_78 = F_3 ( F_4 ( V_1 , F_91 ) ) ;
V_74 -> type = F_81 ( F_4 ( V_1 , F_92 ) ) ;
if ( V_74 -> type == V_61 ) {
F_53 ( V_74 -> V_14 ) ;
F_53 ( V_74 -> V_78 ) ;
F_53 ( V_74 ) ;
F_60 ( F_89 , TYPE , L_21 ) ;
}
if ( ! V_74 -> V_78 || ! V_74 -> V_78 [ 0 ] ) {
F_60 ( F_89 , V_79 , L_22 ) ;
}
if ( F_97 ( V_74 -> V_78 ) ) {
F_53 ( V_74 -> V_14 ) ;
F_53 ( V_74 -> V_78 ) ;
F_53 ( V_74 ) ;
F_60 ( F_89 , V_79 , L_23 ) ;
}
if ( ! F_86 ( V_1 , F_93 ) ) {
if ( V_74 -> type == V_80 ) {
V_70 = F_88 ( V_1 , F_93 ) ;
}
else {
V_67 = F_85 ( V_1 , F_93 ) ;
}
if ( V_67 ) {
V_74 -> V_67 = F_98 ( V_67 ) ;
} else if ( V_70 ) {
V_74 -> V_67 = F_99 ( V_70 ) ;
} else {
F_53 ( V_74 -> V_14 ) ;
F_53 ( V_74 -> V_78 ) ;
F_53 ( V_74 ) ;
return 0 ;
}
} else {
V_74 -> V_67 = NULL ;
}
V_74 -> V_63 = F_84 ( F_19 ( V_1 , F_94 , L_24 ) ) ;
V_74 -> V_81 = F_100 ( V_1 , F_95 , 0x0 ) ;
V_76 = F_19 ( V_1 , F_96 , NULL ) ;
if ( V_76 && strcmp ( V_76 , V_74 -> V_14 ) != 0 ) {
V_74 -> V_76 = F_3 ( V_76 ) ;
} else {
V_74 -> V_76 = NULL ;
}
F_101 ( V_1 , V_74 ) ;
F_71 ( 1 ) ;
}
static int F_102 ( T_2 * V_1 , enum V_56 type ) {
T_15 V_74 ;
const T_4 * V_78 = F_4 ( V_1 , 1 ) ;
const T_4 * V_14 = F_19 ( V_1 , 2 , V_78 ) ;
unsigned V_63 = F_100 ( V_1 , 3 , V_82 ) ;
T_13 * V_67 = ( F_103 ( V_1 ) > 3 ) ? F_85 ( V_1 , 4 ) : NULL ;
V_5 V_81 = F_100 ( V_1 , 5 , 0x0 ) ;
const T_4 * V_76 = F_19 ( V_1 , 6 , NULL ) ;
if ( type == V_83 ) {
if ( V_63 != V_66 )
F_12 ( V_1 , 3 , L_25 ) ;
else if ( V_81 )
F_12 ( V_1 , 3 , L_26 ) ;
} else if ( V_63 < V_82 || V_63 > V_84 ) {
F_12 ( V_1 , 3 , L_27
L_28 ) ;
return 0 ;
} else if ( V_67 && ( type == V_85 || type == V_86 ) ) {
F_12 ( V_1 , 4 , L_29 ) ;
return 0 ;
} else if ( ( V_63 == V_87 || V_63 == V_88 ) &&
( type == V_89 || type == V_90 || type == V_91 || type == V_92 || type == V_85 ) ) {
F_12 ( V_1 , 3 , L_30 ) ;
return 0 ;
}
if ( ! V_78 || ! V_78 [ 0 ] ) {
F_12 ( V_1 , 1 , L_22 ) ;
return 0 ;
}
if ( F_97 ( V_78 ) ) {
F_12 ( V_1 , 1 , L_23 ) ;
return 0 ;
}
V_74 = F_104 ( V_75 , 1 ) ;
V_74 -> V_52 = - 2 ;
V_74 -> V_77 = - 1 ;
V_74 -> V_14 = F_3 ( V_14 ) ;
V_74 -> V_78 = F_3 ( V_78 ) ;
V_74 -> type = type ;
V_74 -> V_67 = F_98 ( V_67 ) ;
V_74 -> V_63 = V_63 ;
V_74 -> V_81 = V_81 ;
if ( V_76 && strcmp ( V_76 , V_74 -> V_14 ) != 0 ) {
V_74 -> V_76 = F_3 ( V_76 ) ;
} else {
V_74 -> V_76 = NULL ;
}
F_101 ( V_1 , V_74 ) ;
return 1 ;
}
static int F_105 ( T_2 * V_1 , enum V_56 type ) {
T_15 V_74 ;
const T_4 * V_78 = F_4 ( V_1 , 1 ) ;
const T_4 * V_14 = F_19 ( V_1 , 2 , V_78 ) ;
unsigned V_63 = F_100 ( V_1 , 3 , V_66 ) ;
T_14 * V_70 = ( F_103 ( V_1 ) > 3 ) ? F_88 ( V_1 , 4 ) : NULL ;
int V_81 = F_100 ( V_1 , 5 , 0x0 ) ;
const T_4 * V_76 = F_19 ( V_1 , 6 , NULL ) ;
if ( V_81 == 0x0 && V_63 != V_66 ) {
F_12 ( V_1 , 2 , L_31
L_32 ) ;
return 0 ;
}
if ( V_81 != 0x0 && ( V_63 < 1 || V_63 > 64 ) ) {
F_12 ( V_1 , 2 , L_33
L_34 ) ;
return 0 ;
}
if ( ! V_78 || ! V_78 [ 0 ] ) {
F_12 ( V_1 , 1 , L_22 ) ;
return 0 ;
}
if ( F_97 ( V_78 ) ) {
F_12 ( V_1 , 1 , L_23 ) ;
return 0 ;
}
V_74 = F_104 ( V_75 , 1 ) ;
V_74 -> V_52 = - 2 ;
V_74 -> V_77 = - 1 ;
V_74 -> V_14 = F_3 ( V_14 ) ;
V_74 -> V_78 = F_3 ( V_78 ) ;
V_74 -> type = type ;
V_74 -> V_67 = F_99 ( V_70 ) ;
V_74 -> V_63 = V_63 ;
V_74 -> V_81 = V_81 ;
if ( V_76 && strcmp ( V_76 , V_74 -> V_14 ) != 0 ) {
V_74 -> V_76 = F_3 ( V_76 ) ;
} else {
V_74 -> V_76 = NULL ;
}
F_101 ( V_1 , V_74 ) ;
return 1 ;
}
static int F_106 ( T_2 * V_1 , enum V_56 type ) {
T_15 V_74 ;
const T_4 * V_78 = F_4 ( V_1 , 1 ) ;
const T_4 * V_14 = F_19 ( V_1 , 2 , V_78 ) ;
unsigned V_63 = F_100 ( V_1 , 3 , V_93 ) ;
const T_4 * V_76 = F_19 ( V_1 , 4 , NULL ) ;
if ( ! V_78 || ! V_78 [ 0 ] ) {
F_12 ( V_1 , 1 , L_22 ) ;
return 0 ;
}
if ( F_97 ( V_78 ) ) {
F_12 ( V_1 , 1 , L_23 ) ;
return 0 ;
}
if ( type == V_94 ) {
if ( V_63 < V_93 || V_63 > V_95 ) {
F_12 ( V_1 , 3 , L_35 ) ;
return 0 ;
}
}
V_74 = F_104 ( V_75 , 1 ) ;
V_74 -> V_52 = - 2 ;
V_74 -> V_77 = - 1 ;
V_74 -> V_14 = F_3 ( V_14 ) ;
V_74 -> V_78 = F_3 ( V_78 ) ;
V_74 -> type = type ;
V_74 -> V_67 = NULL ;
V_74 -> V_63 = V_63 ;
V_74 -> V_81 = 0 ;
if ( V_76 && strcmp ( V_76 , V_74 -> V_14 ) != 0 ) {
V_74 -> V_76 = F_3 ( V_76 ) ;
} else {
V_74 -> V_76 = NULL ;
}
F_101 ( V_1 , V_74 ) ;
return 1 ;
}
static int F_107 ( T_2 * V_1 , enum V_56 type ) {
T_15 V_74 ;
const T_4 * V_78 = F_4 ( V_1 , 1 ) ;
const T_4 * V_14 = F_19 ( V_1 , 2 , V_78 ) ;
const T_4 * V_76 = F_19 ( V_1 , 3 , NULL ) ;
if ( ! V_78 || ! V_78 [ 0 ] ) {
F_12 ( V_1 , 1 , L_22 ) ;
return 0 ;
}
if ( F_97 ( V_78 ) ) {
F_12 ( V_1 , 1 , L_23 ) ;
return 0 ;
}
V_74 = F_104 ( V_75 , 1 ) ;
V_74 -> V_52 = - 2 ;
V_74 -> V_77 = - 1 ;
V_74 -> V_14 = F_3 ( V_14 ) ;
V_74 -> V_78 = F_3 ( V_78 ) ;
V_74 -> type = type ;
V_74 -> V_67 = NULL ;
V_74 -> V_63 = V_66 ;
V_74 -> V_81 = 0 ;
if ( V_76 && strcmp ( V_76 , V_74 -> V_14 ) != 0 ) {
V_74 -> V_76 = F_3 ( V_76 ) ;
} else {
V_74 -> V_76 = NULL ;
}
F_101 ( V_1 , V_74 ) ;
return 1 ;
}
T_11 F_108 ( T_2 * V_1 ) {
T_15 V_74 = F_109 ( V_1 , 1 ) ;
T_4 * V_31 = ( T_4 * ) F_110 ( L_36 , V_74 -> V_52 , V_74 -> V_14 , V_74 -> V_78 , F_82 ( V_74 -> type ) , F_83 ( V_74 -> V_63 ) , V_74 -> V_67 , V_74 -> V_81 , V_74 -> V_76 ) ;
F_76 ( V_1 , V_31 ) ;
return 1 ;
}
static int F_111 ( T_2 * V_1 ) {
T_15 V_74 = F_109 ( V_1 , 1 ) ;
if ( ! V_74 ) {
F_12 ( V_1 , 1 , L_37 ) ;
} else if ( V_74 -> V_52 == - 2 ) {
F_53 ( V_74 -> V_14 ) ;
F_53 ( V_74 -> V_78 ) ;
F_53 ( V_74 -> V_76 ) ;
F_53 ( V_74 ) ;
}
return 0 ;
}
int F_112 ( T_2 * V_1 ) {
F_55 ( T_15 ) ;
return 1 ;
}
T_9 F_113 ( T_2 * V_1 ) {
#define F_114 1
#define F_115 2
const T_4 * V_14 = F_4 ( V_1 , F_114 ) ;
const T_4 * V_22 = F_4 ( V_1 , F_115 ) ;
if ( V_14 ) {
T_4 * V_96 ;
int V_97 ;
V_96 = F_116 ( V_14 , - 1 ) ;
V_97 = F_117 ( V_96 ) ;
F_53 ( V_96 ) ;
if ( V_97 > 0 ) {
F_60 ( F_113 , V_48 , L_38 ) ;
} else {
T_16 V_24 = ( V_98 * ) F_20 ( sizeof( V_98 ) ) ;
T_4 * V_99 = F_116 ( V_14 , - 1 ) ;
T_4 * V_100 = F_118 ( V_14 , - 1 ) ;
V_24 -> V_14 = V_100 ;
V_24 -> V_22 = F_3 ( V_22 ) ;
V_24 -> V_52 = F_119 ( V_24 -> V_22 , V_100 , V_99 ) ;
V_24 -> V_77 = - 1 ;
V_24 -> V_101 = FALSE ;
F_120 ( V_1 ) ;
V_24 -> V_102 = F_121 ( V_1 , V_103 ) ;
V_24 -> V_104 . V_14 = NULL ;
V_24 -> V_104 . V_18 = NULL ;
V_24 -> V_104 . V_22 = NULL ;
V_24 -> V_104 . V_16 . V_29 = 0 ;
V_24 -> V_104 . V_23 = NULL ;
V_24 -> V_104 . V_24 = V_24 ;
V_24 -> V_51 = NULL ;
V_24 -> V_105 = NULL ;
F_122 ( V_1 , V_103 , V_106 ) ;
F_76 ( V_1 , V_99 ) ;
F_123 ( V_1 , V_24 ) ;
F_124 ( V_1 , - 3 ) ;
F_123 ( V_1 , V_24 ) ;
F_71 ( 1 ) ;
}
} else
F_60 ( F_113 , V_48 , L_5 ) ;
return 0 ;
}
static int F_125 ( T_2 * V_1 ) {
T_16 V_24 = F_126 ( V_1 , 1 ) ;
T_4 * V_31 ;
if ( ! V_24 ) return 0 ;
V_31 = F_110 ( L_39 , V_24 -> V_14 ) ;
F_76 ( V_1 , V_31 ) ;
return 1 ;
}
T_17 F_127 ( T_2 * V_1 ) {
#define F_128 1
T_16 V_24 = F_126 ( V_1 , F_128 ) ;
if ( ! V_24 ) return 0 ;
if( ! V_24 -> V_101 ) {
if ( ! V_24 -> V_105 ) {
V_24 -> V_105 = F_129 ( V_107 , V_24 -> V_52 ) ;
}
F_130 ( V_24 -> V_105 ) ;
} else {
F_12 ( V_1 , 1 , L_40 ) ;
}
return 0 ;
}
static int F_131 ( T_2 * V_1 ) {
T_16 V_24 = F_132 ( V_1 , 1 ) ;
if ( V_24 -> V_105 ) {
F_133 ( V_1 , V_24 -> V_105 ) ;
return 1 ;
} else {
F_62 ( V_1 , L_41 ) ;
return 0 ;
}
}
static int F_134 ( T_2 * V_1 ) {
T_16 V_24 = F_132 ( V_1 , 1 ) ;
if ( F_135 ( V_1 , 3 ) ) {
T_4 * V_99 = F_116 ( V_24 -> V_14 , - 1 ) ;
F_122 ( V_1 , V_103 , V_108 ) ;
F_136 ( V_1 , 1 ) ;
F_76 ( V_1 , V_24 -> V_14 ) ;
F_136 ( V_1 , 2 ) ;
F_124 ( V_1 , 1 ) ;
V_24 -> V_105 = F_129 ( V_107 , V_24 -> V_52 ) ;
F_137 ( V_99 , V_107 , V_24 -> V_52 ) ;
return 0 ;
} else {
F_12 ( V_1 , 3 , L_42 ) ;
return 0 ;
}
}
static int F_138 ( T_2 * V_1 ) {
T_16 V_24 = F_132 ( V_1 , 1 ) ;
F_139 ( V_1 , & V_24 -> V_104 ) ;
return 1 ;
}
static int F_140 ( T_2 * V_1 ) {
T_16 V_24 = F_132 ( V_1 , 1 ) ;
if ( F_135 ( V_1 , 3 ) ) {
F_76 ( V_1 , V_109 ) ;
#if V_110 >= 502
F_141 ( V_1 ) ;
#else
F_142 ( V_1 , V_111 ) ;
#endif
F_136 ( V_1 , 1 ) ;
F_76 ( V_1 , V_24 -> V_14 ) ;
F_136 ( V_1 , 2 ) ;
F_124 ( V_1 , 1 ) ;
#if V_110 >= 502
F_15 ( V_1 , 1 ) ;
#endif
return 0 ;
} else {
F_12 ( V_1 , 3 , L_43 ) ;
return 0 ;
}
}
static int F_143 ( T_2 * V_1 ) {
T_16 V_24 = F_132 ( V_1 , 1 ) ;
F_76 ( V_1 , V_24 -> V_14 ) ;
return 1 ;
}
static int F_144 ( T_2 * V_1 ) {
T_16 V_24 = F_132 ( V_1 , 1 ) ;
F_76 ( V_1 , V_24 -> V_22 ) ;
return 1 ;
}
static int F_145 ( T_2 * V_1 ) {
T_16 V_24 = F_132 ( V_1 , 1 ) ;
F_122 ( V_1 , V_103 , V_24 -> V_102 ) ;
return 1 ;
}
void F_146 ( char * V_31 , T_2 * V_1 ) {
int V_112 ;
for ( V_112 = 1 ; V_112 <= F_103 ( V_1 ) ; V_112 ++ ) {
printf ( L_44 , V_31 , V_112 , F_147 ( V_1 , F_148 ( V_1 , V_112 ) ) ) ;
}
printf ( L_45 ) ;
}
static int F_149 ( T_2 * V_1 ) {
T_16 V_24 = F_132 ( V_1 , 1 ) ;
#define F_150 2
#define F_151 3
#define F_152 3
F_122 ( V_1 , V_103 , V_24 -> V_102 ) ;
F_136 ( V_1 , F_150 ) ;
if( F_87 ( V_1 , F_151 ) ) {
for ( F_9 ( V_1 ) ; F_10 ( V_1 , F_151 ) ; ) {
if ( F_153 ( V_1 , 5 ) ) {
F_121 ( V_1 , F_150 ) ;
} else if ( ! F_86 ( V_1 , 5 ) ) {
return F_62 ( V_1 , L_46 ) ;
}
}
} else if ( F_153 ( V_1 , F_152 ) ) {
F_154 ( V_1 , F_152 ) ;
F_121 ( V_1 , F_150 ) ;
} else {
return F_62 ( V_1 , L_47 ) ;
}
F_154 ( V_1 , 3 ) ;
return 1 ;
}
static int F_155 ( T_2 * V_1 ) {
T_16 V_24 = F_126 ( V_1 , 1 ) ;
const T_4 * V_14 = F_4 ( V_1 , 2 ) ;
const T_18 * V_113 ;
if ( ! ( V_24 && V_14 ) ) return 0 ;
for ( V_113 = V_114 ; V_113 -> V_14 ; V_113 ++ ) {
if ( F_61 ( V_14 , V_113 -> V_14 ) ) {
if ( V_113 -> V_115 ) {
return V_113 -> V_115 ( V_1 ) ;
} else {
F_62 ( V_1 , L_48 , V_14 ) ;
return 0 ;
}
}
}
F_62 ( V_1 , L_49 , V_14 ) ;
return 0 ;
}
static int F_156 ( T_2 * V_1 ) {
T_16 V_24 = F_126 ( V_1 , 1 ) ;
const T_4 * V_14 = F_4 ( V_1 , 2 ) ;
const T_18 * V_113 ;
if ( ! ( V_24 && V_14 ) ) return 0 ;
for ( V_113 = V_114 ; V_113 -> V_14 ; V_113 ++ ) {
if ( F_61 ( V_14 , V_113 -> V_14 ) ) {
if ( V_113 -> V_116 ) {
return V_113 -> V_116 ( V_1 ) ;
} else {
F_62 ( V_1 , L_50 , V_14 ) ;
return 0 ;
}
}
}
F_62 ( V_1 , L_49 , V_14 ) ;
return 0 ;
}
static int F_157 ( T_2 * V_1 V_54 ) {
return 0 ;
}
int F_158 ( T_2 * V_1 ) {
F_80 ( T_16 ) ;
F_120 ( V_1 ) ;
V_106 = F_121 ( V_1 , V_103 ) ;
F_159 ( V_1 , F_113 ) ;
F_160 ( V_1 , L_51 ) ;
return 1 ;
}
int F_161 ( T_2 * V_1 ) {
F_162 ( V_1 , 0 ) ;
F_122 ( V_1 , V_103 , V_106 ) ;
for ( F_9 ( V_1 ) ; F_10 ( V_1 , 1 ) ; F_15 ( V_1 , 2 ) ) {
T_5 * V_117 = F_7 ( TRUE , TRUE , sizeof( V_118 ) ) ;
T_5 * V_119 = F_7 ( TRUE , TRUE , sizeof( V_120 * ) ) ;
T_16 V_24 ;
V_24 = F_126 ( V_1 , 3 ) ;
F_122 ( V_1 , V_103 , V_24 -> V_102 ) ;
for ( F_9 ( V_1 ) ; F_10 ( V_1 , 4 ) ; F_15 ( V_1 , 1 ) ) {
T_15 V_74 = F_109 ( V_1 , 6 ) ;
V_118 V_121 = { & ( V_74 -> V_52 ) , { V_74 -> V_14 , V_74 -> V_78 , V_74 -> type , V_74 -> V_63 , F_98 ( V_74 -> V_67 ) , V_74 -> V_81 , V_74 -> V_76 , V_122 } } ;
V_120 * V_123 = & ( V_74 -> V_77 ) ;
if ( V_74 -> V_52 != - 2 ) {
return F_62 ( V_1 , L_52 ) ;
}
V_74 -> V_52 = - 1 ;
F_17 ( V_117 , V_121 ) ;
F_17 ( V_119 , V_123 ) ;
}
F_163 ( V_24 -> V_52 , ( V_118 * ) V_117 -> V_17 , V_117 -> V_124 ) ;
F_164 ( ( V_120 * * ) V_119 -> V_17 , V_119 -> V_124 ) ;
F_13 ( V_117 , FALSE ) ;
F_13 ( V_119 , FALSE ) ;
}
return 0 ;
}
T_9 F_165 ( T_2 * V_1 ) {
#define F_166 1
const T_4 * V_14 = F_4 ( V_1 , F_166 ) ;
T_19 V_125 ;
if ( ! V_14 )
F_60 ( F_165 , V_48 , L_5 ) ;
if ( ( V_125 = F_167 ( V_14 ) ) ) {
F_133 ( V_1 , V_125 ) ;
F_71 ( 1 ) ;
} else
F_60 ( F_165 , V_48 , L_53 ) ;
}
T_20 F_168 ( T_2 * V_1 ) {
#define F_169 2
#define F_170 3
#define F_171 4
T_19 V_125 = F_172 ( V_1 , 1 ) ;
T_21 V_126 = F_173 ( V_1 , F_169 ) ;
T_22 V_127 = F_174 ( V_1 , F_170 ) ;
T_23 V_128 = F_175 ( V_1 , F_171 ) ;
const char * volatile error = NULL ;
if ( ! ( V_125 && V_126 && V_127 ) ) return 0 ;
F_176 {
F_177 ( V_125 , V_126 -> V_129 , V_127 -> V_130 , V_128 -> V_131 ) ;
} F_178 {
F_179 ( V_126 -> V_129 , V_127 -> V_130 , V_128 -> V_131 , V_132 , V_133 ) ;
error = L_54 ;
} V_134 ;
if ( error ) { F_70 ( F_168 , error ) ; }
return 0 ;
}
T_11 F_180 ( T_2 * V_1 ) {
T_19 V_125 = F_172 ( V_1 , 1 ) ;
if ( ! V_125 ) return 0 ;
F_76 ( V_1 , F_181 ( V_125 ) ) ;
F_71 ( 1 ) ;
}
static int F_182 ( T_2 * V_1 V_54 ) {
return 0 ;
}
int F_183 ( T_2 * V_1 ) {
F_55 ( T_19 ) ;
return 1 ;
}
T_9 F_184 ( T_2 * V_1 ) {
#define F_185 1
#define F_186 2
#define F_187 3
#define F_188 4
const T_4 * V_14 = ( const T_4 * ) F_4 ( V_1 , F_185 ) ;
const T_4 * V_135 = ( const T_4 * ) F_19 ( V_1 , F_186 , V_14 ) ;
enum V_56 type = (enum V_56 ) F_100 ( V_1 , F_187 , V_136 ) ;
unsigned V_63 = ( unsigned ) F_100 ( V_1 , F_188 , V_82 ) ;
if( ! ( V_14 && V_135 ) ) return 0 ;
switch( type ) {
case V_137 :
V_63 = V_66 ;
case V_138 :
case V_139 :
case V_140 :
case V_136 :
{
T_24 V_141 = ( T_24 ) F_20 ( sizeof( struct V_142 ) ) ;
V_14 = F_3 ( V_14 ) ;
V_135 = F_3 ( V_135 ) ;
V_141 -> V_143 = F_189 ( V_14 , V_135 , type , V_63 ) ;
V_141 -> V_14 = V_14 ;
F_190 ( V_1 , V_141 ) ;
}
F_71 ( 1 ) ;
default:
F_191 ( F_184 , TYPE , L_55 ) ;
}
return 0 ;
}
T_9 F_192 ( T_2 * V_1 ) {
#define F_193 1
const T_4 * V_14 = F_4 ( V_1 , F_193 ) ;
T_25 V_143 ;
if( ! V_14 ) return 0 ;
V_143 = F_194 ( V_14 ) ;
if ( V_143 ) {
T_24 V_141 = ( T_24 ) F_20 ( sizeof( struct V_142 ) ) ;
V_141 -> V_143 = V_143 ;
V_141 -> V_14 = F_3 ( V_14 ) ;
F_190 ( V_1 , V_141 ) ;
F_71 ( 1 ) ;
} else
F_60 ( F_192 , V_144 , L_56 ) ;
}
T_20 F_195 ( T_2 * V_1 ) {
#define F_196 2
#define F_197 3
T_24 V_141 = F_198 ( V_1 , 1 ) ;
T_26 type ;
T_19 V_105 ;
if ( ! V_141 ) return 0 ;
if( F_199 ( V_1 , F_197 ) ) {
T_16 V_46 ;
V_46 = F_132 ( V_1 , F_197 ) ;
V_105 = V_46 -> V_105 ;
if ( ! V_105 )
F_60 ( F_195 , V_145 , L_57 ) ;
} else if ( F_200 ( V_1 , F_197 ) ) {
V_105 = F_201 ( V_1 , F_197 ) ;
} else
F_60 ( F_195 , V_145 , L_58 ) ;
type = F_202 ( V_141 -> V_14 ) ;
if ( type == V_137 ) {
T_4 * V_146 = F_3 ( F_4 ( V_1 , F_196 ) ) ;
F_203 ( V_141 -> V_14 , V_146 , V_105 ) ;
} else if ( type == V_136 || type == V_139 || type == V_138 || type == V_140 ) {
int V_147 = F_204 ( V_1 , F_196 ) ;
F_205 ( V_141 -> V_14 , V_147 , V_105 ) ;
} else {
F_62 ( V_1 , L_59 , type ) ;
}
return 0 ;
}
T_20 F_206 ( T_2 * V_1 ) {
#define F_207 2
#define F_208 3
T_24 V_141 = F_198 ( V_1 , 1 ) ;
T_26 type ;
T_19 V_105 ;
if ( ! V_141 ) return 0 ;
if( F_199 ( V_1 , F_208 ) ) {
T_16 V_46 ;
V_46 = F_132 ( V_1 , F_208 ) ;
V_105 = V_46 -> V_105 ;
} else if ( F_200 ( V_1 , F_208 ) ) {
V_105 = F_201 ( V_1 , F_208 ) ;
} else
F_60 ( F_195 , V_145 , L_58 ) ;
type = F_202 ( V_141 -> V_14 ) ;
if ( type == V_137 ) {
T_4 * V_146 = F_3 ( F_4 ( V_1 , F_207 ) ) ;
F_209 ( V_141 -> V_14 , V_146 , V_105 ) ;
} else if ( type == V_136 || type == V_139 || type == V_138 || type == V_140 ) {
int V_147 = F_204 ( V_1 , F_207 ) ;
F_210 ( V_141 -> V_14 , V_147 , V_105 ) ;
}
return 0 ;
}
T_20 F_211 ( T_2 * V_1 ) {
#define F_212 2
#define F_213 3
#define F_214 4
#define F_215 5
T_24 V_141 = F_198 ( V_1 , 1 ) ;
T_21 V_126 = F_173 ( V_1 , F_213 ) ;
T_22 V_127 = F_174 ( V_1 , F_214 ) ;
T_23 V_128 = F_175 ( V_1 , F_215 ) ;
T_26 type ;
T_8 V_148 = FALSE ;
const T_4 * volatile error = NULL ;
if ( ! ( V_141 && V_126 && V_126 -> V_129 && V_127 && V_128 ) ) return 0 ;
type = F_202 ( V_141 -> V_14 ) ;
F_176 {
if ( type == V_137 ) {
const T_4 * V_146 = F_4 ( V_1 , F_212 ) ;
if ( ! V_146 )
V_148 = TRUE ;
else if ( F_216 ( V_141 -> V_143 , V_146 , V_126 -> V_129 , V_127 -> V_130 , V_128 -> V_131 ) )
V_148 = TRUE ;
} else if ( type == V_136 || type == V_139 || type == V_138 || type == V_140 ) {
int V_147 = F_204 ( V_1 , F_212 ) ;
if ( F_217 ( V_141 -> V_143 , V_147 , V_126 -> V_129 , V_127 -> V_130 , V_128 -> V_131 ) )
V_148 = TRUE ;
} else {
F_62 ( V_1 , L_60 ) ;
}
if ( ! V_148 )
F_177 ( V_149 , V_126 -> V_129 , V_127 -> V_130 , V_128 -> V_131 ) ;
} F_178 {
F_179 ( V_126 -> V_129 , V_127 -> V_130 , V_128 -> V_131 , V_132 , V_133 ) ;
error = L_54 ;
} V_134 ;
if ( error ) { F_70 ( F_211 , error ) ; }
return 0 ;
}
T_20 F_218 ( T_2 * V_1 ) {
#define F_212 2
T_24 V_141 = F_198 ( V_1 , 1 ) ;
T_26 type ;
T_27 V_105 = V_149 ;
if ( ! V_141 ) return 0 ;
type = F_202 ( V_141 -> V_14 ) ;
if ( type == V_137 ) {
const T_4 * V_146 = F_4 ( V_1 , F_212 ) ;
if ( ! V_146 ) F_60 ( F_211 , V_150 , L_5 ) ;
V_105 = F_219 ( V_141 -> V_143 , V_146 ) ;
} else if ( type == V_136 || type == V_139 || type == V_138 || type == V_140 ) {
int V_147 = F_204 ( V_1 , F_212 ) ;
V_105 = F_220 ( V_141 -> V_143 , V_147 ) ;
}
if ( V_105 ) {
F_133 ( V_1 , V_105 ) ;
F_71 ( 1 ) ;
} else {
F_9 ( V_1 ) ;
F_71 ( 1 ) ;
}
}
T_11 F_221 ( T_2 * V_1 ) {
T_24 V_141 = F_198 ( V_1 , 1 ) ;
T_28 * V_31 ;
T_26 type ;
if ( ! V_141 ) return 0 ;
type = F_202 ( V_141 -> V_14 ) ;
V_31 = F_222 ( L_61 ) ;
switch( type ) {
case V_137 :
{
F_223 ( V_31 , L_62 , V_141 -> V_14 ) ;
break;
}
case V_138 :
case V_139 :
case V_140 :
case V_136 :
{
int V_63 = F_224 ( V_141 -> V_14 ) ;
F_223 ( V_31 , L_63 , V_141 -> V_14 , V_63 ) ;
break;
}
default:
F_62 ( V_1 , L_64 ) ;
}
F_76 ( V_1 , V_31 -> V_59 ) ;
F_225 ( V_31 , TRUE ) ;
F_71 ( 1 ) ;
}
static int F_226 ( T_2 * V_1 V_54 ) {
return 0 ;
}
int F_227 ( T_2 * V_1 ) {
F_55 ( T_24 ) ;
return 1 ;
}
