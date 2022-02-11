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
T_7 V_20 = F_20 ( sizeof( V_21 ) ) ;
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
T_10 F_78 ( T_2 * V_1 ) {
F_79 ( V_54 ) ;
return 1 ;
}
static enum V_55 F_80 ( const T_4 * type ) {
const T_12 * V_56 ;
for ( V_56 = V_57 ; V_56 -> V_58 ; V_56 ++ ) {
if ( F_61 ( V_56 -> V_58 , type ) ) {
return V_56 -> V_59 ;
}
}
return V_60 ;
}
static const T_4 * F_81 ( enum V_55 V_61 ) {
const T_12 * V_56 ;
for ( V_56 = V_57 ; V_56 -> V_58 ; V_56 ++ ) {
if ( V_56 -> V_59 == V_61 ) {
return V_56 -> V_58 ;
}
}
return NULL ;
}
static const T_4 * F_82 ( T_13 V_62 ) {
const struct V_63 * V_27 ;
for ( V_27 = V_64 ; V_27 -> V_58 ; V_27 ++ ) {
if ( V_62 == V_27 -> V_62 )
return V_27 -> V_58 ;
}
return NULL ;
}
static T_13 F_83 ( const T_4 * V_58 ) {
const struct V_63 * V_27 ;
for ( V_27 = V_64 ; V_27 -> V_58 ; V_27 ++ ) {
if ( F_61 ( V_58 , V_27 -> V_58 ) )
return V_27 -> V_62 ;
}
return V_65 ;
}
static T_14 * F_84 ( T_2 * V_1 , int V_6 ) {
T_5 * V_66 = F_7 ( TRUE , TRUE , sizeof( T_14 ) ) ;
T_14 * V_4 ;
if( F_85 ( V_1 , V_6 ) ) {
return NULL ;
} else if ( ! F_86 ( V_1 , V_6 ) ) {
F_12 ( V_1 , V_6 , L_14 ) ;
F_13 ( V_66 , TRUE ) ;
return NULL ;
}
F_9 ( V_1 ) ;
while ( F_10 ( V_1 , V_6 ) != 0 ) {
T_14 V_67 = { 0 , NULL } ;
if ( ! F_16 ( V_1 , - 2 ) ) {
F_12 ( V_1 , V_6 , L_15 ) ;
F_13 ( V_66 , TRUE ) ;
return NULL ;
}
if ( ! F_11 ( V_1 , - 1 ) ) {
F_12 ( V_1 , V_6 , L_16 ) ;
F_13 ( V_66 , TRUE ) ;
return NULL ;
}
V_67 . V_16 = ( V_5 ) F_5 ( V_1 , - 2 ) ;
V_67 . V_68 = F_3 ( F_14 ( V_1 , - 1 ) ) ;
F_17 ( V_66 , V_67 ) ;
F_15 ( V_1 , 1 ) ;
}
V_4 = ( T_14 * ) V_66 -> V_17 ;
F_13 ( V_66 , FALSE ) ;
return V_4 ;
}
static T_15 * F_87 ( T_2 * V_1 , int V_6 ) {
T_5 * V_69 = F_7 ( TRUE , TRUE , sizeof( T_15 ) ) ;
T_15 * V_4 ;
T_15 V_70 = { L_17 , L_18 } ;
if ( F_85 ( V_1 , V_6 ) ) {
return NULL ;
} else if ( ! F_86 ( V_1 , V_6 ) ) {
F_12 ( V_1 , V_6 , L_14 ) ;
F_13 ( V_69 , TRUE ) ;
return NULL ;
}
F_9 ( V_1 ) ;
while ( F_10 ( V_1 , V_6 ) ) {
if ( ! F_16 ( V_1 , - 2 ) ) {
F_12 ( V_1 , V_6 , L_19 ) ;
F_13 ( V_69 , TRUE ) ;
return NULL ;
}
if ( ! F_11 ( V_1 , - 1 ) ) {
F_12 ( V_1 , V_6 , L_20 ) ;
F_13 ( V_69 , TRUE ) ;
return NULL ;
}
if ( ( V_5 ) F_5 ( V_1 , - 2 ) == 1 )
V_70 . V_71 = F_3 ( F_14 ( V_1 , - 1 ) ) ;
if ( ( V_5 ) F_5 ( V_1 , - 2 ) == 2 )
V_70 . V_72 = F_3 ( F_14 ( V_1 , - 1 ) ) ;
F_15 ( V_1 , 1 ) ;
}
F_17 ( V_69 , V_70 ) ;
V_4 = ( T_15 * ) V_69 -> V_17 ;
F_13 ( V_69 , FALSE ) ;
return V_4 ;
}
T_9 F_88 ( T_2 * V_1 ) {
#define F_89 1
#define F_90 2
#define F_91 3
#define F_92 4
#define F_93 5
#define F_94 6
#define F_95 7
T_16 V_73 = F_20 ( sizeof( V_74 ) ) ;
T_14 * V_66 = NULL ;
T_15 * V_69 = NULL ;
const T_4 * V_75 ;
V_73 -> V_52 = - 2 ;
V_73 -> V_76 = - 1 ;
V_73 -> V_14 = F_3 ( F_4 ( V_1 , F_89 ) ) ;
V_73 -> V_77 = F_3 ( F_4 ( V_1 , F_90 ) ) ;
V_73 -> type = F_80 ( F_4 ( V_1 , F_91 ) ) ;
if ( V_73 -> type == V_60 )
F_60 ( F_88 , TYPE , L_21 ) ;
if ( F_96 ( V_73 -> V_77 ) ) {
F_60 ( F_88 , V_78 , L_22 ) ;
return 0 ;
}
if ( ! F_85 ( V_1 , F_92 ) ) {
if ( V_73 -> type == V_79 ) {
V_69 = F_87 ( V_1 , F_92 ) ;
}
else {
V_66 = F_84 ( V_1 , F_92 ) ;
}
if ( V_66 ) {
V_73 -> V_66 = F_97 ( V_66 ) ;
} else if ( V_69 ) {
V_73 -> V_66 = F_98 ( V_69 ) ;
} else {
F_53 ( V_73 ) ;
return 0 ;
}
} else {
V_73 -> V_66 = NULL ;
}
V_73 -> V_62 = F_83 ( F_19 ( V_1 , F_93 , L_23 ) ) ;
V_73 -> V_80 = F_99 ( V_1 , F_94 , 0x0 ) ;
V_75 = F_19 ( V_1 , F_95 , NULL ) ;
if ( V_75 && strcmp ( V_75 , V_73 -> V_14 ) != 0 ) {
V_73 -> V_75 = F_3 ( V_75 ) ;
} else {
V_73 -> V_75 = NULL ;
}
F_100 ( V_1 , V_73 ) ;
F_71 ( 1 ) ;
}
static int F_101 ( T_2 * V_1 , enum V_55 type ) {
T_16 V_73 ;
const T_4 * V_77 = F_4 ( V_1 , 1 ) ;
const T_4 * V_14 = F_19 ( V_1 , 2 , V_77 ) ;
T_13 V_62 = F_99 ( V_1 , 3 , V_81 ) ;
T_14 * V_66 = ( F_102 ( V_1 ) > 3 ) ? F_84 ( V_1 , 4 ) : NULL ;
V_5 V_80 = F_99 ( V_1 , 5 , 0x0 ) ;
const T_4 * V_75 = F_19 ( V_1 , 6 , NULL ) ;
if ( type == V_82 ) {
if ( V_62 != V_65 )
F_12 ( V_1 , 3 , L_24 ) ;
else if ( V_80 )
F_12 ( V_1 , 3 , L_25 ) ;
} else if ( V_62 < V_81 || V_62 > V_83 ) {
F_12 ( V_1 , 3 , L_26
L_27 ) ;
return 0 ;
} else if ( V_66 && ( type == V_84 || type == V_85 ) ) {
F_12 ( V_1 , 4 , L_28 ) ;
return 0 ;
} else if ( ( V_62 == V_86 || V_62 == V_87 ) &&
( type == V_88 || type == V_89 || type == V_90 || type == V_91 || type == V_84 ) ) {
F_12 ( V_1 , 3 , L_29 ) ;
return 0 ;
}
if ( F_96 ( V_77 ) ) {
F_12 ( V_1 , 1 , L_22 ) ;
return 0 ;
}
V_73 = F_103 ( V_74 , 1 ) ;
V_73 -> V_52 = - 2 ;
V_73 -> V_76 = - 1 ;
V_73 -> V_14 = F_3 ( V_14 ) ;
V_73 -> V_77 = F_3 ( V_77 ) ;
V_73 -> type = type ;
V_73 -> V_66 = F_97 ( V_66 ) ;
V_73 -> V_62 = V_62 ;
V_73 -> V_80 = V_80 ;
if ( V_75 && strcmp ( V_75 , V_73 -> V_14 ) != 0 ) {
V_73 -> V_75 = F_3 ( V_75 ) ;
} else {
V_73 -> V_75 = NULL ;
}
F_100 ( V_1 , V_73 ) ;
return 1 ;
}
static int F_104 ( T_2 * V_1 , enum V_55 type ) {
T_16 V_73 ;
const T_4 * V_77 = F_4 ( V_1 , 1 ) ;
const T_4 * V_14 = F_19 ( V_1 , 2 , V_77 ) ;
T_13 V_62 = F_99 ( V_1 , 3 , V_65 ) ;
T_15 * V_69 = ( F_102 ( V_1 ) > 3 ) ? F_87 ( V_1 , 4 ) : NULL ;
int V_80 = F_99 ( V_1 , 5 , 0x0 ) ;
const T_4 * V_75 = F_19 ( V_1 , 6 , NULL ) ;
if ( V_80 == 0x0 && V_62 != V_65 ) {
F_12 ( V_1 , 2 , L_30
L_31 ) ;
return 0 ;
}
if ( V_80 != 0x0 && ( V_62 < 1 || V_62 > 64 ) ) {
F_12 ( V_1 , 2 , L_32
L_33 ) ;
return 0 ;
}
if ( F_96 ( V_77 ) ) {
F_12 ( V_1 , 1 , L_22 ) ;
return 0 ;
}
V_73 = F_103 ( V_74 , 1 ) ;
V_73 -> V_52 = - 2 ;
V_73 -> V_76 = - 1 ;
V_73 -> V_14 = F_3 ( V_14 ) ;
V_73 -> V_77 = F_3 ( V_77 ) ;
V_73 -> type = type ;
V_73 -> V_66 = F_98 ( V_69 ) ;
V_73 -> V_62 = V_62 ;
V_73 -> V_80 = V_80 ;
if ( V_75 && strcmp ( V_75 , V_73 -> V_14 ) != 0 ) {
V_73 -> V_75 = F_3 ( V_75 ) ;
} else {
V_73 -> V_75 = NULL ;
}
F_100 ( V_1 , V_73 ) ;
return 1 ;
}
static int F_105 ( T_2 * V_1 , enum V_55 type ) {
T_16 V_73 ;
const T_4 * V_77 = F_4 ( V_1 , 1 ) ;
const T_4 * V_14 = F_19 ( V_1 , 2 , V_77 ) ;
T_17 V_62 = F_99 ( V_1 , 3 , V_92 ) ;
const T_4 * V_75 = F_19 ( V_1 , 4 , NULL ) ;
if ( F_96 ( V_77 ) ) {
F_12 ( V_1 , 1 , L_22 ) ;
return 0 ;
}
if ( type == V_93 ) {
if ( V_62 < V_92 || V_62 > V_94 ) {
F_12 ( V_1 , 3 , L_34 ) ;
return 0 ;
}
}
V_73 = F_103 ( V_74 , 1 ) ;
V_73 -> V_52 = - 2 ;
V_73 -> V_76 = - 1 ;
V_73 -> V_14 = F_3 ( V_14 ) ;
V_73 -> V_77 = F_3 ( V_77 ) ;
V_73 -> type = type ;
V_73 -> V_66 = NULL ;
V_73 -> V_62 = V_62 ;
V_73 -> V_80 = 0 ;
if ( V_75 && strcmp ( V_75 , V_73 -> V_14 ) != 0 ) {
V_73 -> V_75 = F_3 ( V_75 ) ;
} else {
V_73 -> V_75 = NULL ;
}
F_100 ( V_1 , V_73 ) ;
return 1 ;
}
static int F_106 ( T_2 * V_1 , enum V_55 type ) {
T_16 V_73 ;
const T_4 * V_77 = F_4 ( V_1 , 1 ) ;
const T_4 * V_14 = F_19 ( V_1 , 2 , V_77 ) ;
const T_4 * V_75 = F_19 ( V_1 , 3 , NULL ) ;
if ( F_96 ( V_77 ) ) {
F_12 ( V_1 , 1 , L_22 ) ;
return 0 ;
}
V_73 = F_103 ( V_74 , 1 ) ;
V_73 -> V_52 = - 2 ;
V_73 -> V_76 = - 1 ;
V_73 -> V_14 = F_3 ( V_14 ) ;
V_73 -> V_77 = F_3 ( V_77 ) ;
V_73 -> type = type ;
V_73 -> V_66 = NULL ;
V_73 -> V_62 = V_65 ;
V_73 -> V_80 = 0 ;
if ( V_75 && strcmp ( V_75 , V_73 -> V_14 ) != 0 ) {
V_73 -> V_75 = F_3 ( V_75 ) ;
} else {
V_73 -> V_75 = NULL ;
}
F_100 ( V_1 , V_73 ) ;
return 1 ;
}
T_11 F_107 ( T_2 * V_1 ) {
T_16 V_73 = F_108 ( V_1 , 1 ) ;
T_4 * V_31 = F_109 ( L_35 , V_73 -> V_52 , V_73 -> V_14 , V_73 -> V_77 , F_81 ( V_73 -> type ) , F_82 ( V_73 -> V_62 ) , V_73 -> V_66 , V_73 -> V_80 , V_73 -> V_75 ) ;
F_76 ( V_1 , V_31 ) ;
return 1 ;
}
static int F_110 ( T_2 * V_1 ) {
T_16 V_73 = F_108 ( V_1 , 1 ) ;
if ( ! V_73 ) {
F_12 ( V_1 , 1 , L_36 ) ;
} else if ( V_73 -> V_52 == - 2 ) {
F_53 ( V_73 -> V_14 ) ;
F_53 ( V_73 -> V_77 ) ;
F_53 ( V_73 -> V_75 ) ;
F_53 ( V_73 ) ;
}
return 0 ;
}
int F_111 ( T_2 * V_1 ) {
F_55 ( T_16 ) ;
return 1 ;
}
T_9 F_112 ( T_2 * V_1 ) {
#define F_113 1
#define F_114 2
const T_4 * V_14 = F_4 ( V_1 , F_113 ) ;
const T_4 * V_22 = F_4 ( V_1 , F_114 ) ;
if ( V_14 ) {
T_4 * V_95 ;
int V_96 ;
V_95 = F_115 ( V_14 , - 1 ) ;
V_96 = F_116 ( V_95 ) ;
F_53 ( V_95 ) ;
if ( V_96 > 0 ) {
F_60 ( F_112 , V_48 , L_37 ) ;
} else {
T_18 V_24 = F_20 ( sizeof( V_97 ) ) ;
T_4 * V_98 = F_115 ( V_14 , - 1 ) ;
T_4 * V_99 = F_117 ( V_14 , - 1 ) ;
V_24 -> V_14 = V_99 ;
V_24 -> V_22 = F_3 ( V_22 ) ;
V_24 -> V_52 = F_118 ( V_24 -> V_22 , V_99 , V_98 ) ;
V_24 -> V_76 = - 1 ;
V_24 -> V_100 = FALSE ;
F_119 ( V_1 ) ;
V_24 -> V_101 = F_120 ( V_1 , V_102 ) ;
V_24 -> V_103 . V_14 = NULL ;
V_24 -> V_103 . V_18 = NULL ;
V_24 -> V_103 . V_22 = NULL ;
V_24 -> V_103 . V_16 . V_29 = 0 ;
V_24 -> V_103 . V_23 = NULL ;
V_24 -> V_103 . V_24 = V_24 ;
V_24 -> V_51 = NULL ;
V_24 -> V_104 = NULL ;
F_121 ( V_1 , V_102 , V_105 ) ;
F_76 ( V_1 , V_98 ) ;
F_122 ( V_1 , V_24 ) ;
F_123 ( V_1 , - 3 ) ;
F_122 ( V_1 , V_24 ) ;
F_71 ( 1 ) ;
}
} else
F_60 ( F_112 , V_48 , L_5 ) ;
return 0 ;
}
static int F_124 ( T_2 * V_1 ) {
T_18 V_24 = F_125 ( V_1 , 1 ) ;
T_4 * V_31 ;
if ( ! V_24 ) return 0 ;
V_31 = F_109 ( L_38 , V_24 -> V_14 ) ;
F_76 ( V_1 , V_31 ) ;
return 1 ;
}
T_19 F_126 ( T_2 * V_1 ) {
#define F_127 1
T_18 V_24 = F_125 ( V_1 , F_127 ) ;
if ( ! V_24 ) return 0 ;
if( ! V_24 -> V_100 ) {
if ( ! V_24 -> V_104 ) {
V_24 -> V_104 = F_128 ( V_106 , V_24 -> V_52 ) ;
}
F_129 ( V_24 -> V_104 ) ;
} else {
F_12 ( V_1 , 1 , L_39 ) ;
}
return 0 ;
}
static int F_130 ( T_2 * V_1 ) {
T_18 V_24 = F_131 ( V_1 , 1 ) ;
if ( V_24 -> V_104 ) {
F_132 ( V_1 , V_24 -> V_104 ) ;
return 1 ;
} else {
F_62 ( V_1 , L_40 ) ;
return 0 ;
}
}
static int F_133 ( T_2 * V_1 ) {
T_18 V_24 = F_131 ( V_1 , 1 ) ;
if ( F_134 ( V_1 , 3 ) ) {
T_4 * V_98 = F_115 ( V_24 -> V_14 , - 1 ) ;
F_121 ( V_1 , V_102 , V_107 ) ;
F_135 ( V_1 , 1 ) ;
F_76 ( V_1 , V_24 -> V_14 ) ;
F_135 ( V_1 , 2 ) ;
F_123 ( V_1 , 1 ) ;
V_24 -> V_104 = F_128 ( V_106 , V_24 -> V_52 ) ;
F_136 ( V_98 , V_106 , V_24 -> V_52 ) ;
return 0 ;
} else {
F_12 ( V_1 , 3 , L_41 ) ;
return 0 ;
}
}
static int F_137 ( T_2 * V_1 ) {
T_18 V_24 = F_131 ( V_1 , 1 ) ;
F_138 ( V_1 , & V_24 -> V_103 ) ;
return 1 ;
}
static int F_139 ( T_2 * V_1 ) {
T_18 V_24 = F_131 ( V_1 , 1 ) ;
if ( F_134 ( V_1 , 3 ) ) {
F_76 ( V_1 , V_108 ) ;
F_140 ( V_1 , V_109 ) ;
F_135 ( V_1 , 1 ) ;
F_76 ( V_1 , V_24 -> V_14 ) ;
F_135 ( V_1 , 2 ) ;
F_123 ( V_1 , 1 ) ;
return 0 ;
} else {
F_12 ( V_1 , 3 , L_42 ) ;
return 0 ;
}
}
static int F_141 ( T_2 * V_1 ) {
T_18 V_24 = F_131 ( V_1 , 1 ) ;
F_76 ( V_1 , V_24 -> V_14 ) ;
return 1 ;
}
static int F_142 ( T_2 * V_1 ) {
T_18 V_24 = F_131 ( V_1 , 1 ) ;
F_76 ( V_1 , V_24 -> V_22 ) ;
return 1 ;
}
static int F_143 ( T_2 * V_1 ) {
T_18 V_24 = F_131 ( V_1 , 1 ) ;
F_121 ( V_1 , V_102 , V_24 -> V_101 ) ;
return 1 ;
}
void F_144 ( char * V_31 , T_2 * V_1 ) {
int V_110 ;
for ( V_110 = 1 ; V_110 <= F_102 ( V_1 ) ; V_110 ++ ) {
printf ( L_43 , V_31 , V_110 , F_145 ( V_1 , F_146 ( V_1 , V_110 ) ) ) ;
}
printf ( L_44 ) ;
}
static int F_147 ( T_2 * V_1 ) {
T_18 V_24 = F_131 ( V_1 , 1 ) ;
#define F_148 2
#define F_149 3
#define F_150 3
F_121 ( V_1 , V_102 , V_24 -> V_101 ) ;
F_135 ( V_1 , F_148 ) ;
if( F_86 ( V_1 , F_149 ) ) {
for ( F_9 ( V_1 ) ; F_10 ( V_1 , F_149 ) ; ) {
if ( F_151 ( V_1 , 5 ) ) {
F_120 ( V_1 , F_148 ) ;
} else if ( ! F_85 ( V_1 , 5 ) ) {
return F_62 ( V_1 , L_45 ) ;
}
}
} else if ( F_151 ( V_1 , F_150 ) ) {
F_152 ( V_1 , F_150 ) ;
F_120 ( V_1 , F_148 ) ;
} else {
return F_62 ( V_1 , L_46 ) ;
}
F_152 ( V_1 , 3 ) ;
return 1 ;
}
static int F_153 ( T_2 * V_1 ) {
T_18 V_24 = F_125 ( V_1 , 1 ) ;
const T_4 * V_14 = F_4 ( V_1 , 2 ) ;
const T_20 * V_111 ;
if ( ! ( V_24 && V_14 ) ) return 0 ;
for ( V_111 = V_112 ; V_111 -> V_14 ; V_111 ++ ) {
if ( F_61 ( V_14 , V_111 -> V_14 ) ) {
if ( V_111 -> V_113 ) {
return V_111 -> V_113 ( V_1 ) ;
} else {
F_62 ( V_1 , L_47 , V_14 ) ;
return 0 ;
}
}
}
F_62 ( V_1 , L_48 , V_14 ) ;
return 0 ;
}
static int F_154 ( T_2 * V_1 ) {
T_18 V_24 = F_125 ( V_1 , 1 ) ;
const T_4 * V_14 = F_4 ( V_1 , 2 ) ;
const T_20 * V_111 ;
if ( ! ( V_24 && V_14 ) ) return 0 ;
for ( V_111 = V_112 ; V_111 -> V_14 ; V_111 ++ ) {
if ( F_61 ( V_14 , V_111 -> V_14 ) ) {
if ( V_111 -> V_114 ) {
return V_111 -> V_114 ( V_1 ) ;
} else {
F_62 ( V_1 , L_49 , V_14 ) ;
return 0 ;
}
}
}
F_62 ( V_1 , L_48 , V_14 ) ;
return 0 ;
}
int F_155 ( T_2 * V_1 ) {
F_79 ( T_18 ) ;
F_119 ( V_1 ) ;
V_105 = F_120 ( V_1 , V_102 ) ;
F_76 ( V_1 , L_50 ) ;
F_156 ( V_1 , F_112 ) ;
F_123 ( V_1 , V_109 ) ;
F_54 ( V_1 ) ;
F_78 ( V_1 ) ;
return 1 ;
}
int F_157 ( T_2 * V_1 ) {
F_158 ( V_1 , 0 ) ;
F_121 ( V_1 , V_102 , V_105 ) ;
for ( F_9 ( V_1 ) ; F_10 ( V_1 , 1 ) ; F_15 ( V_1 , 2 ) ) {
T_5 * V_115 = F_7 ( TRUE , TRUE , sizeof( V_116 ) ) ;
T_5 * V_117 = F_7 ( TRUE , TRUE , sizeof( V_118 * ) ) ;
T_18 V_24 ;
V_24 = F_125 ( V_1 , 3 ) ;
F_121 ( V_1 , V_102 , V_24 -> V_101 ) ;
for ( F_9 ( V_1 ) ; F_10 ( V_1 , 4 ) ; F_15 ( V_1 , 1 ) ) {
T_16 V_73 = F_108 ( V_1 , 6 ) ;
V_116 V_119 = { & ( V_73 -> V_52 ) , { V_73 -> V_14 , V_73 -> V_77 , V_73 -> type , V_73 -> V_62 , F_97 ( V_73 -> V_66 ) , V_73 -> V_80 , V_73 -> V_75 , V_120 } } ;
V_118 * V_121 = & ( V_73 -> V_76 ) ;
if ( V_73 -> V_52 != - 2 ) {
return F_62 ( V_1 , L_51 ) ;
}
V_73 -> V_52 = - 1 ;
F_17 ( V_115 , V_119 ) ;
F_17 ( V_117 , V_121 ) ;
}
F_159 ( V_24 -> V_52 , ( V_116 * ) V_115 -> V_17 , V_115 -> V_122 ) ;
F_160 ( ( V_118 * * ) V_117 -> V_17 , V_117 -> V_122 ) ;
F_13 ( V_115 , FALSE ) ;
F_13 ( V_117 , FALSE ) ;
}
return 0 ;
}
T_9 F_161 ( T_2 * V_1 ) {
#define F_162 1
const T_4 * V_14 = F_4 ( V_1 , F_162 ) ;
T_21 V_123 ;
if ( ! V_14 )
F_60 ( F_161 , V_48 , L_5 ) ;
if ( ( V_123 = F_163 ( V_14 ) ) ) {
F_132 ( V_1 , V_123 ) ;
F_71 ( 1 ) ;
} else
F_60 ( F_161 , V_48 , L_52 ) ;
}
T_22 F_164 ( T_2 * V_1 ) {
#define F_165 2
#define F_166 3
#define F_167 4
T_21 V_123 = F_168 ( V_1 , 1 ) ;
T_23 V_124 = F_169 ( V_1 , F_165 ) ;
T_24 V_125 = F_170 ( V_1 , F_166 ) ;
T_25 V_126 = F_171 ( V_1 , F_167 ) ;
char * volatile error = NULL ;
if ( ! ( V_123 && V_124 && V_125 ) ) return 0 ;
F_172 {
F_173 ( V_123 , V_124 -> V_127 , V_125 -> V_128 , V_126 -> V_129 ) ;
} F_174 (ReportedBoundsError) {
F_175 ( V_130 -> V_129 , V_131 , V_132 , 0 , 0 , L_53 ) ;
error = L_54 ;
} V_133 ;
if ( error ) { F_70 ( F_164 , error ) ; }
return 0 ;
}
T_11 F_176 ( T_2 * V_1 ) {
T_21 V_123 = F_168 ( V_1 , 1 ) ;
if ( ! V_123 ) return 0 ;
F_76 ( V_1 , F_177 ( V_123 ) ) ;
return 1 ;
}
int F_178 ( T_2 * V_1 ) {
F_55 ( T_21 ) ;
return 1 ;
}
T_9 F_179 ( T_2 * V_1 ) {
#define F_180 1
#define F_181 2
#define F_182 3
#define F_183 4
T_4 * V_14 = ( void * ) F_4 ( V_1 , F_180 ) ;
T_4 * V_134 = ( void * ) F_19 ( V_1 , F_181 , V_14 ) ;
enum V_55 type = F_99 ( V_1 , F_182 , V_135 ) ;
T_13 V_62 = F_99 ( V_1 , F_183 , V_81 ) ;
if( ! ( V_14 && V_134 ) ) return 0 ;
switch( type ) {
case V_136 :
V_62 = V_65 ;
case V_137 :
case V_138 :
case V_139 :
case V_135 :
{
T_26 V_140 = F_20 ( sizeof( struct V_141 ) ) ;
V_14 = F_3 ( V_14 ) ;
V_134 = F_3 ( V_134 ) ;
V_140 -> V_142 = F_184 ( V_14 , V_134 , type , V_62 ) ;
V_140 -> V_14 = V_14 ;
F_185 ( V_1 , V_140 ) ;
}
F_71 ( 1 ) ;
default:
F_186 ( F_179 , TYPE , L_55 ) ;
}
return 0 ;
}
T_9 F_187 ( T_2 * V_1 ) {
#define F_188 1
const T_4 * V_14 = F_4 ( V_1 , F_188 ) ;
T_27 V_142 ;
if( ! V_14 ) return 0 ;
V_142 = F_189 ( V_14 ) ;
if ( V_142 ) {
T_26 V_140 = F_20 ( sizeof( struct V_141 ) ) ;
V_140 -> V_142 = V_142 ;
V_140 -> V_14 = F_3 ( V_14 ) ;
F_185 ( V_1 , V_140 ) ;
F_71 ( 1 ) ;
} else
F_60 ( F_187 , V_143 , L_56 ) ;
}
T_22 F_190 ( T_2 * V_1 ) {
#define F_191 2
#define F_192 3
T_26 V_140 = F_193 ( V_1 , 1 ) ;
T_28 type ;
T_21 V_104 ;
if ( ! V_140 ) return 0 ;
if( F_194 ( V_1 , F_192 ) ) {
T_18 V_46 ;
V_46 = F_131 ( V_1 , F_192 ) ;
V_104 = V_46 -> V_104 ;
if ( ! V_104 )
F_60 ( F_190 , V_144 , L_57 ) ;
} else if ( F_195 ( V_1 , F_192 ) ) {
V_104 = F_196 ( V_1 , F_192 ) ;
} else
F_60 ( F_190 , V_144 , L_58 ) ;
type = F_197 ( V_140 -> V_14 ) ;
if ( type == V_136 ) {
T_4 * V_145 = F_3 ( F_4 ( V_1 , F_191 ) ) ;
F_198 ( V_140 -> V_14 , V_145 , V_104 ) ;
} else if ( type == V_135 || type == V_138 || type == V_137 || type == V_139 ) {
int V_146 = F_199 ( V_1 , F_191 ) ;
F_200 ( V_140 -> V_14 , V_146 , V_104 ) ;
} else {
F_62 ( V_1 , L_59 , type ) ;
}
return 0 ;
}
T_22 F_201 ( T_2 * V_1 ) {
#define F_202 2
#define F_203 3
T_26 V_140 = F_193 ( V_1 , 1 ) ;
T_28 type ;
T_21 V_104 ;
if ( ! V_140 ) return 0 ;
if( F_194 ( V_1 , F_203 ) ) {
T_18 V_46 ;
V_46 = F_131 ( V_1 , F_203 ) ;
V_104 = V_46 -> V_104 ;
} else if ( F_195 ( V_1 , F_203 ) ) {
V_104 = F_196 ( V_1 , F_203 ) ;
} else
F_60 ( F_190 , V_144 , L_58 ) ;
type = F_197 ( V_140 -> V_14 ) ;
if ( type == V_136 ) {
T_4 * V_145 = F_3 ( F_4 ( V_1 , 2 ) ) ;
F_204 ( V_140 -> V_14 , V_145 , V_104 ) ;
} else if ( type == V_135 || type == V_138 || type == V_137 || type == V_139 ) {
int V_146 = F_199 ( V_1 , 2 ) ;
F_205 ( V_140 -> V_14 , V_146 , V_104 ) ;
}
return 0 ;
}
T_22 F_206 ( T_2 * V_1 ) {
#define F_207 2
#define F_208 3
#define F_209 4
#define F_210 5
T_26 V_140 = F_193 ( V_1 , 1 ) ;
T_23 V_124 = F_169 ( V_1 , 3 ) ;
T_24 V_125 = F_170 ( V_1 , 4 ) ;
T_25 V_126 = F_171 ( V_1 , 5 ) ;
T_28 type ;
T_8 V_147 = FALSE ;
T_4 * volatile error = NULL ;
if ( ! ( V_140 && V_124 && V_124 -> V_127 && V_125 && V_126 ) ) return 0 ;
type = F_197 ( V_140 -> V_14 ) ;
F_172 {
if ( type == V_136 ) {
const T_4 * V_145 = F_4 ( V_1 , 2 ) ;
if ( ! V_145 )
V_147 = TRUE ;
else if ( F_211 ( V_140 -> V_142 , V_145 , V_124 -> V_127 , V_125 -> V_128 , V_126 -> V_129 ) )
V_147 = TRUE ;
} else if ( type == V_135 || type == V_138 || type == V_137 || type == V_139 ) {
int V_146 = F_199 ( V_1 , 2 ) ;
if ( F_212 ( V_140 -> V_142 , V_146 , V_124 -> V_127 , V_125 -> V_128 , V_126 -> V_129 ) )
V_147 = TRUE ;
} else {
F_62 ( V_1 , L_60 ) ;
}
if ( ! V_147 )
F_173 ( V_148 , V_124 -> V_127 , V_125 -> V_128 , V_126 -> V_129 ) ;
} F_174 (ReportedBoundsError) {
F_175 ( V_130 -> V_129 , V_131 , V_132 , 0 , 0 , L_53 ) ;
error = L_54 ;
} V_133 ;
if ( error ) { F_70 ( F_206 , error ) ; }
return 0 ;
}
T_22 F_213 ( T_2 * V_1 ) {
#define F_207 2
T_26 V_140 = F_193 ( V_1 , 1 ) ;
T_28 type ;
T_29 V_104 = V_148 ;
if ( ! V_140 ) return 0 ;
type = F_197 ( V_140 -> V_14 ) ;
if ( type == V_136 ) {
const T_4 * V_145 = F_4 ( V_1 , F_207 ) ;
if ( ! V_145 ) F_60 ( F_206 , V_149 , L_5 ) ;
V_104 = F_214 ( V_140 -> V_142 , V_145 ) ;
} else if ( type == V_135 || type == V_138 || type == V_137 || type == V_139 ) {
int V_146 = F_199 ( V_1 , F_207 ) ;
V_104 = F_215 ( V_140 -> V_142 , V_146 ) ;
}
if ( V_104 ) {
F_132 ( V_1 , V_104 ) ;
F_71 ( 1 ) ;
} else {
F_9 ( V_1 ) ;
F_71 ( 1 ) ;
}
}
T_11 F_216 ( T_2 * V_1 ) {
T_26 V_140 = F_193 ( V_1 , 1 ) ;
T_30 * V_31 ;
T_28 type ;
if ( ! V_140 ) return 0 ;
type = F_197 ( V_140 -> V_14 ) ;
V_31 = F_217 ( L_61 ) ;
switch( type ) {
case V_136 :
{
F_218 ( V_31 , L_62 , V_140 -> V_14 ) ;
break;
}
case V_137 :
case V_138 :
case V_139 :
case V_135 :
{
int V_62 = F_219 ( V_140 -> V_14 ) ;
F_218 ( V_31 , L_63 , V_140 -> V_14 , V_62 ) ;
break;
}
default:
F_62 ( V_1 , L_64 ) ;
}
F_76 ( V_1 , V_31 -> V_58 ) ;
F_220 ( V_31 , TRUE ) ;
return 1 ;
}
int F_221 ( T_2 * V_1 ) {
F_55 ( T_26 ) ;
return 1 ;
}
