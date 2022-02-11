static void F_1 ( T_1 * T_2 V_1 , T_3 V_2 ) {
T_4 * V_3 = ( T_4 * ) V_2 ;
F_2 ( F_3 ( V_3 -> V_4 ) ) ;
V_3 -> V_4 = NULL ;
if ( V_3 -> V_5 )
V_3 -> V_5 ( V_3 -> V_6 ) ;
}
static void F_4 ( T_1 * T_2 V_1 , T_3 V_2 ) {
T_4 * V_3 = ( T_4 * ) V_2 ;
T_5 V_7 ;
F_2 ( F_3 ( V_3 -> V_4 ) ) ;
V_3 -> V_4 = NULL ;
if ( V_3 -> V_5 )
V_3 -> V_5 ( V_3 -> V_6 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_8 -> V_9 ; V_7 ++ ) {
T_6 * V_10 = ( T_6 * ) F_5 ( V_3 -> V_8 , V_7 ) ;
if ( V_10 -> V_2 && V_10 -> V_11 ) V_10 -> V_11 ( V_10 -> V_2 ) ;
if ( V_10 -> V_12 ) V_10 -> V_12 ( V_10 ) ;
}
F_6 ( V_3 -> V_8 , TRUE ) ;
F_7 ( V_3 ) ;
}
static T_7 F_8 ( T_1 * V_4 V_1 , T_8 * T_9 V_1 , T_3 V_13 ) {
T_4 * V_3 = ( T_4 * ) V_13 ;
T_5 V_7 ;
F_2 ( F_3 ( V_3 -> V_4 ) ) ;
V_3 -> V_4 = NULL ;
if ( V_3 -> V_5 )
V_3 -> V_5 ( V_3 -> V_6 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_8 -> V_9 ; V_7 ++ ) {
T_6 * V_10 = ( T_6 * ) F_5 ( V_3 -> V_8 , V_7 ) ;
if ( V_10 -> V_2 && V_10 -> V_11 ) V_10 -> V_11 ( V_10 -> V_2 ) ;
if ( V_10 -> V_12 ) V_10 -> V_12 ( V_10 ) ;
}
F_6 ( V_3 -> V_8 , TRUE ) ;
F_7 ( V_3 ) ;
return TRUE ;
}
static T_7 F_9 ( T_1 * V_4 V_1 , T_8 * T_9 V_1 , T_3 V_13 )
{
T_4 * V_3 = ( T_4 * ) V_13 ;
F_2 ( F_3 ( V_3 -> V_4 ) ) ;
V_3 -> V_4 = NULL ;
if ( V_3 -> V_5 )
V_3 -> V_5 ( V_3 -> V_6 ) ;
return TRUE ;
}
static T_4 * F_10 ( const char * V_14 ) {
T_4 * V_3 = ( T_4 * ) F_11 ( sizeof( T_4 ) ) ;
T_1 * V_15 , * V_16 , * V_17 ;
V_3 -> V_5 = NULL ;
V_3 -> V_6 = NULL ;
V_3 -> V_8 = F_12 () ;
V_3 -> V_4 = F_13 ( V_14 ) ;
F_14 ( F_15 ( V_3 -> V_4 ) , TRUE ) ;
F_16 ( V_3 -> V_4 , L_1 , F_17 ( F_9 ) , V_3 ) ;
V_15 = F_18 ( NULL , NULL ) ;
V_16 = F_19 ( V_18 , 3 , FALSE ) ;
F_20 ( F_21 ( V_16 ) , 6 ) ;
F_22 ( F_21 ( V_3 -> V_4 ) , V_16 ) ;
F_23 ( F_24 ( V_16 ) , V_15 , TRUE , TRUE , 0 ) ;
F_25 ( F_26 ( V_15 ) ,
V_19 ) ;
F_27 ( F_26 ( V_15 ) ,
V_20 , V_20 ) ;
V_3 -> V_21 = F_28 () ;
F_29 ( F_30 ( V_3 -> V_21 ) , FALSE ) ;
F_31 ( F_30 ( V_3 -> V_21 ) , V_22 ) ;
F_32 ( F_30 ( V_3 -> V_21 ) , FALSE ) ;
F_33 ( F_30 ( V_3 -> V_21 ) , 4 ) ;
F_34 ( F_30 ( V_3 -> V_21 ) , 4 ) ;
V_17 = F_19 ( V_23 , 0 , FALSE ) ;
F_35 ( V_17 ) ;
V_3 -> V_24 = F_36 ( V_23 ) ;
F_37 ( F_38 ( V_3 -> V_24 ) , V_25 ) ;
F_23 ( F_24 ( V_17 ) , V_3 -> V_24 , TRUE , TRUE , 0 ) ;
F_35 ( V_3 -> V_24 ) ;
F_23 ( F_24 ( V_16 ) , V_17 , FALSE , FALSE , 0 ) ;
V_3 -> V_26 = F_39 ( L_2 ) ;
F_40 ( V_3 -> V_26 , TRUE ) ;
F_41 ( F_42 ( V_17 ) , L_2 , V_3 -> V_26 ) ;
F_43 ( F_24 ( V_17 ) , V_3 -> V_26 , FALSE , FALSE , 0 ) ;
F_35 ( V_3 -> V_26 ) ;
F_16 ( V_3 -> V_26 , L_3 , F_17 ( F_1 ) , V_3 ) ;
F_44 ( V_3 -> V_26 ) ;
F_22 ( F_21 ( V_15 ) , V_3 -> V_21 ) ;
F_45 ( F_15 ( V_3 -> V_4 ) , 400 , 300 ) ;
F_46 ( V_3 -> V_4 ) ;
return V_3 ;
}
static void F_47 ( T_4 * V_3 )
{
T_10 * V_27 ;
if ( ! V_3 -> V_4 ) return;
V_27 = F_48 ( F_30 ( V_3 -> V_21 ) ) ;
F_49 ( V_27 , L_4 , 0 ) ;
}
static void F_50 ( T_4 * V_3 , const char * V_28 )
{
T_1 * V_21 ;
int V_29 ;
T_10 * V_27 ;
T_11 V_30 ;
if ( ! V_3 -> V_4 ) return;
V_21 = V_3 -> V_21 ;
V_29 = ( int ) strlen ( V_28 ) ;
V_27 = F_48 ( F_30 ( V_21 ) ) ;
F_51 ( V_27 , & V_30 ) ;
#if F_52 ( 3 , 0 , 0 )
F_53 ( F_3 ( V_21 ) , F_54 () ) ;
#else
F_55 ( F_3 ( V_21 ) , F_54 () ) ;
#endif
if ( ! F_56 ( V_28 , - 1 , NULL ) )
printf ( L_5 , V_28 ) ;
F_57 ( V_27 , & V_30 , V_28 , V_29 ) ;
}
static void F_58 ( T_4 * V_3 , const char * V_31 )
{
if ( ! V_3 -> V_4 ) return;
F_47 ( V_3 ) ;
F_50 ( V_3 , V_31 ) ;
}
static void F_59 ( T_4 * V_3 , const char * V_28 V_1 ) {
T_1 * V_21 ;
int V_29 ;
T_10 * V_27 ;
T_11 V_30 ;
if ( ! V_3 -> V_4 ) return;
V_21 = V_3 -> V_21 ;
V_29 = ( int ) strlen ( V_28 ) ;
V_27 = F_48 ( F_30 ( V_21 ) ) ;
F_60 ( V_27 , & V_30 ) ;
#if F_52 ( 3 , 0 , 0 )
F_53 ( F_3 ( V_21 ) , F_54 () ) ;
#else
F_55 ( F_3 ( V_21 ) , F_54 () ) ;
#endif
if ( ! F_56 ( V_28 , - 1 , NULL ) )
printf ( L_5 , V_28 ) ;
F_57 ( V_27 , & V_30 , V_28 , V_29 ) ;
}
static const T_12 * F_61 ( T_4 * V_3 ) {
T_1 * V_21 ;
T_10 * V_27 ;
T_11 V_32 ;
T_11 V_33 ;
if ( ! V_3 -> V_4 ) return L_4 ;
V_21 = V_3 -> V_21 ;
V_27 = F_48 ( F_30 ( V_21 ) ) ;
F_60 ( V_27 , & V_32 ) ;
F_51 ( V_27 , & V_33 ) ;
return F_62 ( V_27 , & V_32 , & V_33 , FALSE ) ;
}
static void F_63 ( T_4 * V_3 , T_13 V_34 , void * V_2 ) {
V_3 -> V_5 = V_34 ;
V_3 -> V_6 = V_2 ;
}
static void F_64 ( T_4 * V_3 ) {
if ( V_3 -> V_4 ) {
F_16 ( V_3 -> V_26 , L_3 , F_17 ( F_4 ) , V_3 ) ;
F_16 ( V_3 -> V_4 , L_1 , F_17 ( F_8 ) , V_3 ) ;
} else {
T_5 V_7 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_8 -> V_9 ; V_7 ++ ) {
T_6 * V_10 = ( T_6 * ) F_5 ( V_3 -> V_8 , V_7 ) ;
if ( V_10 -> V_2 && V_10 -> V_11 ) V_10 -> V_11 ( V_10 -> V_2 ) ;
if ( V_10 -> V_12 ) V_10 -> V_12 ( V_10 ) ;
}
F_6 ( V_3 -> V_8 , TRUE ) ;
F_7 ( V_3 ) ;
}
}
static void F_65 ( T_4 * V_3 , T_7 V_35 ) {
F_29 ( F_30 ( V_3 -> V_21 ) , V_35 ) ;
F_32 ( F_30 ( V_3 -> V_21 ) , V_35 ) ;
}
static T_7 F_66 ( T_1 * T_2 V_1 , T_3 V_13 )
{
T_6 * V_10 = ( T_6 * ) V_13 ;
if ( V_10 -> V_36 ) {
return V_10 -> V_36 ( V_10 -> V_3 , V_10 -> V_2 ) ;
} else {
return TRUE ;
}
}
static void F_67 ( T_4 * V_3 , T_6 * V_10 , const T_12 * V_37 ) {
T_1 * V_38 ;
V_10 -> V_3 = V_3 ;
F_68 ( V_3 -> V_8 , V_10 ) ;
V_38 = F_39 ( V_37 ) ;
F_40 ( V_38 , TRUE ) ;
F_23 ( F_24 ( V_3 -> V_24 ) , V_38 , FALSE , FALSE , 0 ) ;
F_35 ( V_38 ) ;
F_16 ( V_38 , L_3 , F_17 ( F_66 ) , V_10 ) ;
}
static T_7 F_69 ( T_1 * V_4 V_1 , T_3 V_13 )
{
struct V_39 * V_40 = (struct V_39 * ) V_13 ;
T_5 V_7 ;
T_5 V_9 = V_40 -> V_41 -> V_9 ;
T_14 * V_42 = F_12 () ;
for( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
T_15 * V_43 = ( T_15 * ) F_5 ( V_40 -> V_41 , V_7 ) ;
F_68 ( V_42 , F_70 ( F_71 ( V_43 ) ) ) ;
}
F_68 ( V_42 , NULL ) ;
if ( V_40 -> V_44 )
V_40 -> V_44 ( ( T_12 * * ) V_42 -> V_45 , V_40 -> V_2 ) ;
F_2 ( F_3 ( V_40 -> V_4 ) ) ;
F_6 ( V_42 , FALSE ) ;
return TRUE ;
}
static void F_72 ( T_1 * T_2 V_1 , T_3 V_2 ) {
T_1 * V_4 = ( T_1 * ) V_2 ;
F_2 ( F_3 ( V_4 ) ) ;
}
static void F_73 ( const T_12 * V_14 ,
const T_12 * * V_46 ,
T_16 V_44 ,
void * V_2 ) {
T_1 * V_4 , * V_47 , * V_16 , * V_48 , * V_49 , * V_50 ;
T_5 V_7 ;
const T_12 * V_51 ;
struct V_39 * V_40 = (struct V_39 * ) F_11 ( sizeof( struct V_39 ) ) ;
V_40 -> V_41 = F_12 () ;
V_40 -> V_44 = V_44 ;
V_40 -> V_2 = V_2 ;
V_4 = F_13 ( V_14 ) ;
V_40 -> V_4 = V_4 ;
for ( V_7 = 0 ; V_46 [ V_7 ] ; V_7 ++ ) ;
F_45 ( F_15 ( V_4 ) , 400 , 10 * ( V_7 + 2 ) ) ;
V_16 = F_19 ( V_18 , 5 , FALSE ) ;
F_22 ( F_21 ( V_4 ) , V_16 ) ;
F_20 ( F_21 ( V_16 ) , 6 ) ;
V_47 = F_74 () ;
F_23 ( F_24 ( V_16 ) , V_47 , FALSE , FALSE , 0 ) ;
F_75 ( F_76 ( V_47 ) , 10 ) ;
F_77 ( F_76 ( V_47 ) , 15 ) ;
for ( V_7 = 0 ; ( V_51 = V_46 [ V_7 ] ) ; V_7 ++ ) {
T_1 * V_43 , * V_37 ;
V_37 = F_78 ( V_51 ) ;
F_79 ( F_80 ( V_37 ) , 1.0f , 0.5f ) ;
F_81 ( F_76 ( V_47 ) , V_37 , 0 , V_7 + 1 , 1 , 1 ) ;
F_35 ( V_37 ) ;
V_43 = F_82 () ;
F_68 ( V_40 -> V_41 , V_43 ) ;
F_81 ( F_76 ( V_47 ) , V_43 , 1 , V_7 + 1 , 1 , 1 ) ;
F_35 ( V_43 ) ;
}
V_48 = F_83 ( V_52 , V_53 , NULL ) ;
F_23 ( F_24 ( V_16 ) , V_48 , FALSE , FALSE , 0 ) ;
V_50 = ( T_1 * ) F_84 ( F_42 ( V_48 ) , V_53 ) ;
F_16 ( V_50 , L_3 , F_17 ( F_69 ) , V_40 ) ;
F_44 ( V_50 ) ;
V_49 = ( T_1 * ) F_84 ( F_42 ( V_48 ) , V_52 ) ;
F_16 ( V_49 , L_3 , F_17 ( F_72 ) , V_4 ) ;
F_44 ( V_49 ) ;
F_35 ( V_47 ) ;
F_35 ( V_16 ) ;
F_35 ( V_4 ) ;
}
static const T_12 * F_85 ( T_17 * T_18 V_1 V_1 ) {
return F_71 ( F_86 ( V_54 ) ) ;
}
static void F_87 ( T_17 * T_18 V_1 , const char * V_55 ) {
F_88 ( F_86 ( V_54 ) , V_55 ) ;
}
static void F_89 ( T_19 V_56 , const T_12 * V_55 ) {
T_12 * V_57 = NULL ;
if ( ! F_90 ( V_56 , ( T_12 * ) V_55 , FALSE , & V_57 ) ) {
F_91 ( V_58 , V_59 , L_6 , V_57 ) ;
F_7 ( V_57 ) ;
}
}
static void F_92 ( T_17 * T_18 V_1 ) {
const char * V_55 = F_71 ( F_86 ( V_54 ) ) ;
F_93 ( & V_60 , V_55 , FALSE ) ;
}
static void F_94 ( const T_12 * T_20 V_1 ,
T_21 T_22 V_1 ,
const T_12 * V_61 ,
T_3 V_13 V_1 ) {
fputs ( V_61 , V_62 ) ;
}
static void F_95 ( T_17 * T_18 V_1 ) {
F_96 ( & V_60 ) ;
}
static T_7 F_97 ( T_17 * T_18 V_1 , const char * V_63 , const char * V_64 , char * * V_65 ) {
int V_66 = 0 ;
T_23 * V_67 = NULL ;
* V_65 = NULL ;
switch ( V_60 . V_68 ) {
case V_69 :
case V_70 :
case V_71 :
break;
case V_72 :
* V_65 = F_70 ( L_7 ) ;
return FALSE ;
}
if ( V_64 ) {
if ( ! F_98 ( V_64 , & V_67 , V_65 ) ) {
return FALSE ;
}
}
if ( F_99 ( & V_60 , V_63 , V_73 , FALSE , & V_66 ) != V_74 ) {
* V_65 = F_70 ( F_100 ( V_66 ) ) ;
if ( V_67 != NULL ) F_101 ( V_67 ) ;
return FALSE ;
}
V_60 . V_67 = V_67 ;
switch ( F_102 ( & V_60 , FALSE ) ) {
case V_75 :
case V_76 :
break;
default:
* V_65 = F_70 ( L_8 ) ;
return FALSE ;
}
return TRUE ;
}
static struct V_77 * F_103 ( T_17 * T_18 V_1 , const T_12 * V_37 , const T_12 * V_78 , T_7 V_79 , T_7 * V_80 ) {
return F_104 ( V_81 , V_37 , V_78 , V_79 , V_80 ) ;
}
static void F_105 ( struct V_77 * V_4 , float V_82 , const T_12 * V_78 ) {
F_106 ( V_4 , V_82 , V_78 ) ;
}
static void F_107 ( struct V_77 * V_4 ) {
F_108 ( V_4 ) ;
}
static void F_109 ( T_17 * T_18 V_1 ) {
if ( V_60 . V_68 == V_70 ) F_110 ( & V_60 ) ;
}
static void F_111 ( void * T_24 V_1 , T_3 V_2 ) {
T_25 * V_83 = ( T_25 * ) V_2 ;
V_83 -> V_84 ( V_83 -> V_85 ) ;
if ( V_83 -> V_86 ) F_96 ( & V_60 ) ;
}
static void F_112 ( const char * V_87 ,
T_26 V_88 ,
void (* V_84)( T_3 ) ,
T_3 V_85 ,
T_7 V_86 ) {
T_25 * V_83 = ( T_25 * ) F_11 ( sizeof( T_25 ) ) ;
const char * V_37 = NULL , * V_28 = NULL ;
V_83 -> V_84 = V_84 ;
V_83 -> V_85 = V_85 ;
V_83 -> V_86 = V_86 ;
V_28 = strrchr ( V_87 , '/' ) ;
if( V_28 ) {
V_37 = V_28 + 1 ;
} else{
V_37 = V_87 ;
}
F_113 (
F_114 ( V_88 ) ,
V_87 ,
NULL ,
V_37 ,
NULL ,
NULL ,
F_111 ,
V_83 ,
TRUE ,
NULL ,
NULL ) ;
}
void F_115 ( void ) {
F_116 ( & V_89 ) ;
}
void
F_117 ( void )
{
F_118 ( F_112 ) ;
}
