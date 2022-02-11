static void F_1 ( T_1 * T_2 V_1 , T_3 V_2 ) {
T_4 * V_3 = V_2 ;
F_2 ( F_3 ( V_3 -> V_4 ) ) ;
V_3 -> V_4 = NULL ;
if ( V_3 -> V_5 )
V_3 -> V_5 ( V_3 -> V_6 ) ;
}
static void F_4 ( T_1 * T_2 V_1 , T_3 V_2 ) {
T_4 * V_3 = V_2 ;
unsigned V_7 ;
F_2 ( F_3 ( V_3 -> V_4 ) ) ;
V_3 -> V_4 = NULL ;
if ( V_3 -> V_5 )
V_3 -> V_5 ( V_3 -> V_6 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_8 -> V_9 ; V_7 ++ ) {
T_5 * V_10 = F_5 ( V_3 -> V_8 , V_7 ) ;
if ( V_10 -> V_2 && V_10 -> V_11 ) V_10 -> V_11 ( V_10 -> V_2 ) ;
if ( V_10 -> V_12 ) V_10 -> V_12 ( V_10 ) ;
}
F_6 ( V_3 -> V_8 , TRUE ) ;
F_7 ( V_3 ) ;
}
static T_6 F_8 ( T_1 * V_4 V_1 , T_7 * T_8 V_1 , T_3 V_13 ) {
T_4 * V_3 = V_13 ;
unsigned V_7 ;
F_2 ( F_3 ( V_3 -> V_4 ) ) ;
V_3 -> V_4 = NULL ;
if ( V_3 -> V_5 )
V_3 -> V_5 ( V_3 -> V_6 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_8 -> V_9 ; V_7 ++ ) {
T_5 * V_10 = F_5 ( V_3 -> V_8 , V_7 ) ;
if ( V_10 -> V_2 && V_10 -> V_11 ) V_10 -> V_11 ( V_10 -> V_2 ) ;
if ( V_10 -> V_12 ) V_10 -> V_12 ( V_10 ) ;
}
F_6 ( V_3 -> V_8 , TRUE ) ;
F_7 ( V_3 ) ;
return TRUE ;
}
static T_6 F_9 ( T_1 * V_4 V_1 , T_7 * T_8 V_1 , T_3 V_13 )
{
T_4 * V_3 = V_13 ;
F_2 ( F_3 ( V_3 -> V_4 ) ) ;
V_3 -> V_4 = NULL ;
if ( V_3 -> V_5 )
V_3 -> V_5 ( V_3 -> V_6 ) ;
return TRUE ;
}
static T_4 * F_10 ( const T_9 * V_14 ) {
T_4 * V_3 = F_11 ( sizeof( T_4 ) ) ;
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
F_22 ( F_21 ( V_16 ) , V_15 ) ;
F_23 ( F_24 ( V_15 ) ,
V_19 ) ;
F_25 ( F_24 ( V_15 ) ,
V_20 , V_20 ) ;
V_3 -> V_21 = F_26 () ;
F_27 ( F_28 ( V_3 -> V_21 ) , FALSE ) ;
F_29 ( F_28 ( V_3 -> V_21 ) , V_22 ) ;
F_30 ( F_28 ( V_3 -> V_21 ) , FALSE ) ;
F_31 ( F_28 ( V_3 -> V_21 ) , 4 ) ;
F_32 ( F_28 ( V_3 -> V_21 ) , 4 ) ;
V_17 = F_19 ( V_23 , 0 , FALSE ) ;
F_33 ( V_17 ) ;
V_3 -> V_24 = F_34 ( V_23 ) ;
F_35 ( F_36 ( V_3 -> V_24 ) , V_25 ) ;
F_37 ( F_38 ( V_17 ) , V_3 -> V_24 , TRUE , TRUE , 0 ) ;
F_33 ( V_3 -> V_24 ) ;
F_37 ( F_38 ( V_16 ) , V_17 , FALSE , FALSE , 0 ) ;
V_3 -> V_26 = F_39 ( L_2 ) ;
#if F_40 ( 2 , 18 , 0 )
F_41 ( V_3 -> V_26 , TRUE ) ;
#else
F_42 ( V_3 -> V_26 , V_27 ) ;
#endif
F_43 ( F_44 ( V_17 ) , L_2 , V_3 -> V_26 ) ;
F_45 ( F_38 ( V_17 ) , V_3 -> V_26 , FALSE , FALSE , 0 ) ;
F_33 ( V_3 -> V_26 ) ;
F_16 ( V_3 -> V_26 , L_3 , F_17 ( F_1 ) , V_3 ) ;
F_46 ( V_3 -> V_26 ) ;
F_22 ( F_21 ( V_15 ) , V_3 -> V_21 ) ;
F_47 ( F_15 ( V_3 -> V_4 ) , 400 , 300 ) ;
F_48 ( V_3 -> V_4 ) ;
return V_3 ;
}
static void F_49 ( T_4 * V_3 )
{
T_10 * V_28 ;
if ( ! V_3 -> V_4 ) return;
V_28 = F_50 ( F_28 ( V_3 -> V_21 ) ) ;
F_51 ( V_28 , L_4 , 0 ) ;
}
static void F_52 ( T_4 * V_3 , const char * V_29 )
{
T_1 * V_21 ;
int V_30 ;
T_10 * V_28 ;
T_11 V_31 ;
if ( ! V_3 -> V_4 ) return;
V_21 = V_3 -> V_21 ;
V_30 = ( int ) strlen ( V_29 ) ;
V_28 = F_50 ( F_28 ( V_21 ) ) ;
F_53 ( V_28 , & V_31 ) ;
#if F_40 ( 3 , 0 , 0 )
F_54 ( F_3 ( V_21 ) , F_55 () ) ;
#else
F_56 ( F_3 ( V_21 ) , F_55 () ) ;
#endif
if ( ! F_57 ( V_29 , - 1 , NULL ) )
printf ( L_5 , V_29 ) ;
F_58 ( V_28 , & V_31 , V_29 , V_30 ) ;
}
static void F_59 ( T_4 * V_3 , const T_9 * V_32 )
{
if ( ! V_3 -> V_4 ) return;
F_49 ( V_3 ) ;
F_52 ( V_3 , V_32 ) ;
}
static void F_60 ( T_4 * V_3 , const char * V_29 V_1 ) {
T_1 * V_21 ;
int V_30 ;
T_10 * V_28 ;
T_11 V_31 ;
if ( ! V_3 -> V_4 ) return;
V_21 = V_3 -> V_21 ;
V_30 = ( int ) strlen ( V_29 ) ;
V_28 = F_50 ( F_28 ( V_21 ) ) ;
F_61 ( V_28 , & V_31 ) ;
#if F_40 ( 3 , 0 , 0 )
F_54 ( F_3 ( V_21 ) , F_55 () ) ;
#else
F_56 ( F_3 ( V_21 ) , F_55 () ) ;
#endif
if ( ! F_57 ( V_29 , - 1 , NULL ) )
printf ( L_5 , V_29 ) ;
F_58 ( V_28 , & V_31 , V_29 , V_30 ) ;
}
static const T_9 * F_62 ( T_4 * V_3 ) {
T_1 * V_21 ;
T_10 * V_28 ;
T_11 V_33 ;
T_11 V_34 ;
if ( ! V_3 -> V_4 ) return L_4 ;
V_21 = V_3 -> V_21 ;
V_28 = F_50 ( F_28 ( V_21 ) ) ;
F_61 ( V_28 , & V_33 ) ;
F_53 ( V_28 , & V_34 ) ;
return F_63 ( V_28 , & V_33 , & V_34 , FALSE ) ;
}
static void F_64 ( T_4 * V_3 , T_12 V_35 , void * V_2 ) {
V_3 -> V_5 = V_35 ;
V_3 -> V_6 = V_2 ;
}
static void F_65 ( T_4 * V_3 ) {
if ( V_3 -> V_4 ) {
F_16 ( V_3 -> V_26 , L_3 , F_17 ( F_4 ) , V_3 ) ;
F_16 ( V_3 -> V_4 , L_1 , F_17 ( F_8 ) , V_3 ) ;
} else {
unsigned V_7 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_8 -> V_9 ; V_7 ++ ) {
T_5 * V_10 = F_5 ( V_3 -> V_8 , V_7 ) ;
if ( V_10 -> V_2 && V_10 -> V_11 ) V_10 -> V_11 ( V_10 -> V_2 ) ;
if ( V_10 -> V_12 ) V_10 -> V_12 ( V_10 ) ;
}
F_6 ( V_3 -> V_8 , TRUE ) ;
F_7 ( V_3 ) ;
}
}
static void F_66 ( T_4 * V_3 , T_6 V_36 ) {
F_27 ( F_28 ( V_3 -> V_21 ) , V_36 ) ;
F_30 ( F_28 ( V_3 -> V_21 ) , V_36 ) ;
}
static T_6 F_67 ( T_1 * T_2 V_1 , T_3 V_13 )
{
T_5 * V_10 = V_13 ;
if ( V_10 -> V_37 ) {
return V_10 -> V_37 ( V_10 -> V_3 , V_10 -> V_2 ) ;
} else {
return TRUE ;
}
}
static void F_68 ( T_4 * V_3 , T_5 * V_10 , const T_9 * V_38 ) {
T_1 * V_39 ;
V_10 -> V_3 = V_3 ;
F_69 ( V_3 -> V_8 , V_10 ) ;
V_39 = F_39 ( V_38 ) ;
#if F_40 ( 2 , 18 , 0 )
F_41 ( V_39 , TRUE ) ;
#else
F_42 ( V_39 , V_27 ) ;
#endif
F_37 ( F_38 ( V_3 -> V_24 ) , V_39 , FALSE , FALSE , 0 ) ;
F_33 ( V_39 ) ;
F_16 ( V_39 , L_3 , F_17 ( F_67 ) , V_10 ) ;
}
static T_6 F_70 ( T_1 * V_4 V_1 , T_3 V_13 )
{
struct V_40 * V_41 = V_13 ;
T_13 V_7 ;
T_13 V_9 = V_41 -> V_42 -> V_9 ;
T_14 * V_43 = F_12 () ;
for( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
T_15 * V_44 = F_5 ( V_41 -> V_42 , V_7 ) ;
F_69 ( V_43 , F_71 ( F_72 ( V_44 ) ) ) ;
}
F_69 ( V_43 , NULL ) ;
if ( V_41 -> V_45 )
V_41 -> V_45 ( ( T_9 * * ) V_43 -> V_46 , V_41 -> V_2 ) ;
F_2 ( F_3 ( V_41 -> V_4 ) ) ;
F_6 ( V_43 , FALSE ) ;
return TRUE ;
}
static void F_73 ( T_1 * T_2 V_1 , T_3 V_2 ) {
T_1 * V_4 = V_2 ;
F_2 ( F_3 ( V_4 ) ) ;
}
static void F_74 ( const T_9 * V_14 ,
const T_9 * * V_47 ,
T_16 V_45 ,
void * V_2 ) {
T_1 * V_4 , * V_48 , * V_16 , * V_49 , * V_50 , * V_51 ;
T_13 V_7 ;
const T_9 * V_52 ;
struct V_40 * V_41 = F_11 ( sizeof( struct V_40 ) ) ;
V_41 -> V_42 = F_12 () ;
V_41 -> V_45 = V_45 ;
V_41 -> V_2 = V_2 ;
for ( V_7 = 0 ; V_47 [ V_7 ] ; V_7 ++ ) ;
V_4 = F_13 ( V_14 ) ;
V_41 -> V_4 = V_4 ;
F_47 ( F_15 ( V_4 ) , 400 , 10 * ( V_7 + 2 ) ) ;
V_16 = F_19 ( V_18 , 5 , FALSE ) ;
F_22 ( F_21 ( V_4 ) , V_16 ) ;
F_20 ( F_21 ( V_16 ) , 6 ) ;
V_48 = F_75 ( V_7 + 1 , 2 , FALSE ) ;
F_37 ( F_38 ( V_16 ) , V_48 , FALSE , FALSE , 0 ) ;
F_76 ( F_77 ( V_48 ) , 10 ) ;
F_78 ( F_77 ( V_48 ) , 15 ) ;
for ( V_7 = 0 ; ( V_52 = V_47 [ V_7 ] ) ; V_7 ++ ) {
T_1 * V_44 , * V_38 ;
V_38 = F_79 ( V_52 ) ;
F_80 ( F_81 ( V_38 ) , 1.0f , 0.5f ) ;
F_82 ( F_77 ( V_48 ) , V_38 , 0 , 1 , V_7 + 1 , V_7 + 2 ) ;
F_33 ( V_38 ) ;
V_44 = F_83 () ;
F_69 ( V_41 -> V_42 , V_44 ) ;
F_82 ( F_77 ( V_48 ) , V_44 , 1 , 2 , V_7 + 1 , V_7 + 2 ) ;
F_33 ( V_44 ) ;
}
V_49 = F_84 ( V_53 , V_54 , NULL ) ;
F_37 ( F_38 ( V_16 ) , V_49 , FALSE , FALSE , 0 ) ;
V_51 = F_85 ( F_44 ( V_49 ) , V_54 ) ;
F_16 ( V_51 , L_3 , F_17 ( F_70 ) , V_41 ) ;
F_46 ( V_51 ) ;
V_50 = F_85 ( F_44 ( V_49 ) , V_53 ) ;
F_16 ( V_50 , L_3 , F_17 ( F_73 ) , V_4 ) ;
F_46 ( V_50 ) ;
F_33 ( V_48 ) ;
F_33 ( V_16 ) ;
F_33 ( V_4 ) ;
}
static void F_86 ( const char * V_55 ) {
F_87 ( F_88 ( V_56 ) , V_55 ) ;
}
static void F_89 ( T_17 V_57 , const T_9 * V_55 ) {
F_90 ( V_57 , ( T_9 * ) V_55 , FALSE ) ;
}
static void F_91 ( void ) {
const char * V_55 = F_72 ( F_88 ( V_56 ) ) ;
F_92 ( & V_58 , V_55 , FALSE ) ;
}
static void F_93 ( const T_9 * T_18 V_1 ,
T_19 T_20 V_1 ,
const T_9 * V_59 ,
T_3 V_13 V_1 ) {
fputs ( V_59 , V_60 ) ;
}
static void F_94 ( void ) {
F_95 ( & V_58 ) ;
}
static T_6 F_96 ( const char * V_61 , const char * V_62 , const char * * V_63 ) {
int V_64 = 0 ;
T_21 * V_65 = NULL ;
* V_63 = L_6 ;
switch ( V_58 . V_66 ) {
case V_67 :
case V_68 :
case V_69 :
break;
case V_70 :
* V_63 = L_7 ;
return FALSE ;
}
if ( V_62 ) {
if ( ! F_97 ( V_62 , & V_65 ) ) {
* V_63 = V_71 ? V_71 : L_8 ;
return FALSE ;
}
}
if ( F_98 ( & V_58 , V_61 , FALSE , & V_64 ) != V_72 ) {
* V_63 = F_99 ( V_64 ) ;
if ( V_65 != NULL ) F_100 ( V_65 ) ;
return FALSE ;
}
V_58 . V_65 = V_65 ;
switch ( F_101 ( & V_58 , FALSE ) ) {
case V_73 :
case V_74 :
break;
default:
* V_63 = L_9 ;
return FALSE ;
}
return TRUE ;
}
static T_22 * F_102 ( const T_9 * V_38 , const T_9 * V_75 , T_6 V_76 , T_6 * V_77 ) {
return ( T_22 * ) F_103 ( V_38 , V_75 , V_76 , V_77 ) ;
}
static void F_104 ( T_22 * V_4 , float V_78 , const T_9 * V_75 ) {
F_105 ( ( V_79 * ) V_4 , V_78 , V_75 ) ;
}
static void F_106 ( T_22 * V_4 ) {
F_107 ( ( V_79 * ) V_4 ) ;
}
static void F_108 ( void ) {
if ( V_58 . V_66 == V_68 ) F_109 ( & V_58 ) ;
}
static void F_110 ( void * T_23 V_1 , T_3 V_2 ) {
T_24 * V_80 = V_2 ;
V_80 -> V_81 ( V_80 -> V_82 ) ;
if ( V_80 -> V_83 ) F_95 ( & V_58 ) ;
}
static const char * F_111 ( T_25 T_26 V_1 ) {
static const T_27 V_84 [] = {
{ V_85 , L_10 } ,
{ V_86 , L_11 } ,
{ V_87 , L_12 } ,
{ V_88 , L_12 } ,
{ V_89 , L_13 } ,
{ V_90 , L_14 } ,
{ V_91 , L_15 } ,
{ V_92 , L_16 } ,
{ V_93 , L_17 } ,
{ 0 , NULL }
} ;
return F_112 ( T_26 , V_84 , L_17 ) ;
}
static void F_113 ( const char * V_94 ,
T_25 T_26 V_1 ,
void (* V_81)( T_3 ) ,
T_3 V_82 ,
T_6 V_83 ) {
T_24 * V_80 = F_11 ( sizeof( T_24 ) ) ;
const char * V_38 = NULL , * V_29 = NULL ;
V_80 -> V_81 = V_81 ;
V_80 -> V_82 = V_82 ;
V_80 -> V_83 = V_83 ;
V_29 = strrchr ( V_94 , '/' ) ;
if( V_29 ) {
V_38 = V_29 + 1 ;
} else{
V_38 = V_94 ;
}
F_114 (
F_111 ( T_26 ) ,
V_94 ,
NULL ,
V_38 ,
NULL ,
NULL ,
F_110 ,
V_80 ,
TRUE ,
NULL ,
NULL ) ;
}
void F_115 ( void ) {
F_116 ( & V_95 ) ;
}
void
F_117 ( void )
{
F_118 ( F_113 ) ;
}
