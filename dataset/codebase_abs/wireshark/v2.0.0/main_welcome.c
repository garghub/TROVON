static T_1 *
F_1 ( T_1 * V_1 , T_2 V_2 , T_2 V_3 ) {
T_1 * V_4 ;
V_4 = F_2 ( V_5 , 0 , FALSE ) ;
F_3 ( F_4 ( V_4 ) , F_5 ( V_1 ) , TRUE , TRUE , 0 ) ;
F_6 ( F_7 ( V_4 ) , V_6 , V_1 ) ;
F_6 ( F_7 ( V_4 ) , V_7 , F_8 ( V_2 ) ) ;
F_6 ( F_7 ( V_4 ) , V_8 , F_8 ( V_3 ) ) ;
F_9 ( V_4 ) ;
return V_4 ;
}
static T_1 *
F_10 ( T_1 * V_4 )
{
T_1 * V_1 ;
T_1 * V_9 ;
T_2 V_10 ;
T_2 V_11 ;
T_2 V_3 ;
T_3 * V_12 ;
V_1 = ( T_1 * ) F_11 ( F_7 ( V_4 ) , V_6 ) ;
V_10 = F_12 ( F_11 ( F_7 ( V_4 ) , V_7 ) ) ;
V_12 = F_13 ( F_14 ( V_1 ) ) ;
V_11 = F_15 ( V_12 ) ;
F_16 ( V_12 ) ;
if( V_11 == V_10 ) {
V_9 = F_17 ( NULL , NULL ) ;
V_3 = F_12 ( F_11 ( F_7 ( V_4 ) , V_8 ) ) ;
F_18 ( V_9 , - 1 , V_3 ) ;
F_6 ( F_7 ( V_4 ) , V_13 , V_9 ) ;
F_3 ( F_4 ( V_4 ) , V_9 , TRUE , TRUE , 0 ) ;
F_19 ( V_1 ) ;
F_20 ( F_14 ( V_4 ) , V_1 ) ;
#if ! F_21 ( 3 , 8 , 0 )
F_22 ( F_23 ( V_9 ) , V_1 ) ;
#else
F_24 ( F_14 ( V_9 ) , V_1 ) ;
#endif
F_9 ( V_9 ) ;
}
return V_1 ;
}
static T_1 *
F_25 ( T_1 * V_4 )
{
T_1 * V_1 , * V_9 ;
V_1 = ( T_1 * ) F_11 ( F_7 ( V_4 ) , V_6 ) ;
V_9 = ( T_1 * ) F_11 ( F_7 ( V_4 ) , V_13 ) ;
if( V_9 != NULL ) {
F_19 ( V_1 ) ;
F_20 ( F_14 ( V_4 ) , V_9 ) ;
F_6 ( F_7 ( V_4 ) , V_13 , NULL ) ;
F_3 ( F_4 ( V_4 ) , V_1 , TRUE , TRUE , 0 ) ;
}
return V_1 ;
}
static T_4
F_26 ( T_1 * V_14 , T_5 * T_6 V_15 , T_7 T_8 V_15 )
{
#if F_21 ( 3 , 0 , 0 )
F_27 ( V_14 , V_16 , & V_17 ) ;
#else
F_28 ( V_14 , V_18 , & V_19 ) ;
#endif
return FALSE ;
}
static T_4
F_29 ( T_1 * V_14 , T_5 * T_6 V_15 , T_7 T_8 V_15 )
{
#if F_21 ( 3 , 0 , 0 )
F_27 ( V_14 , V_16 , & V_20 ) ;
#else
F_28 ( V_14 , V_18 , & V_21 ) ;
#endif
return FALSE ;
}
static T_1 *
F_30 ( const T_9 * V_22 ,
const T_9 * V_23 , const T_9 * V_24 , const T_9 * V_25 ,
T_10 V_26 , T_7 V_27 )
{
T_1 * V_14 , * V_28 , * V_29 , * V_30 ;
T_9 * V_31 ;
V_29 = F_2 ( V_32 , 1 , FALSE ) ;
V_14 = F_31 () ;
F_24 ( F_14 ( V_14 ) , V_29 ) ;
#if F_21 ( 3 , 0 , 0 )
F_27 ( V_14 , V_16 , & V_20 ) ;
#else
F_28 ( V_14 , V_18 , & V_21 ) ;
#endif
if( V_25 != NULL ) {
F_32 ( V_14 , V_25 ) ;
}
F_33 ( V_14 , L_1 , F_34 ( F_26 ) , NULL ) ;
F_33 ( V_14 , L_2 , F_34 ( F_29 ) , NULL ) ;
F_33 ( V_14 , L_3 , F_34 ( V_26 ) , V_27 ) ;
V_28 = F_35 ( V_22 , V_33 ) ;
F_3 ( F_4 ( V_29 ) , V_28 , FALSE , FALSE , 5 ) ;
V_30 = F_2 ( V_5 , 3 , FALSE ) ;
V_28 = F_36 ( V_23 ) ;
F_37 ( F_38 ( V_28 ) , 0.0f , 0.5f ) ;
V_31 = F_39 ( L_4 , V_23 ) ;
F_40 ( F_41 ( V_28 ) , V_31 ) ;
F_42 ( V_31 ) ;
F_3 ( F_4 ( V_30 ) , V_28 , FALSE , FALSE , 1 ) ;
V_28 = F_36 ( V_24 ) ;
F_37 ( F_38 ( V_28 ) , 0.0f , 0.5f ) ;
V_31 = F_39 ( L_5 , V_24 ) ;
F_40 ( F_41 ( V_28 ) , V_31 ) ;
F_42 ( V_31 ) ;
F_3 ( F_4 ( V_30 ) , V_28 , FALSE , FALSE , 1 ) ;
F_3 ( F_4 ( V_29 ) , V_30 , TRUE , TRUE , 5 ) ;
return V_14 ;
}
static T_4
F_43 ( T_1 * V_28 , T_11 * T_6 V_15 , T_7 T_8 )
{
void (* F_44)( T_1 * , T_7 ) = ( void ( * ) ( T_1 *,T_7 ) ) T_8 ;
(* F_44)( V_28 , NULL ) ;
return TRUE ;
}
void
F_45 ( T_9 * V_34 ) {
T_12 * V_35 ;
T_13 V_36 = time ( NULL ) ;
struct V_37 * V_38 = localtime ( & V_36 ) ;
V_35 = F_46 ( L_6 ) ;
if ( V_34 ) {
F_47 ( V_35 , V_34 ) ;
} else {
if ( ( V_38 -> V_39 == 3 && V_38 -> V_40 == 1 ) || ( V_38 -> V_39 == 6 && V_38 -> V_40 == 14 ) ) {
F_47 ( V_35 , L_7 ) ;
} else {
F_47 ( V_35 , V_41 . V_42 ) ;
}
if ( ( V_41 . V_43 == V_44 ) ||
( V_41 . V_43 == V_45 ) ) {
F_48 ( V_35 , L_8 ,
F_49 () ) ;
}
}
F_47 ( V_35 , L_9 ) ;
F_40 ( F_41 ( V_46 ) , V_35 -> V_47 ) ;
F_50 ( V_35 , TRUE ) ;
}
static T_1 *
F_51 ( void )
{
T_1 * V_48 ;
T_1 * V_29 ;
T_1 * V_14 ;
T_1 * V_49 ;
V_48 = F_2 ( V_5 , 0 , FALSE ) ;
V_14 = F_31 () ;
F_24 ( F_14 ( V_14 ) , V_48 ) ;
#if F_21 ( 3 , 0 , 0 )
F_27 ( V_14 , V_16 , & V_50 ) ;
#else
F_28 ( V_14 , V_18 , & V_51 ) ;
#endif
V_29 = F_2 ( V_32 , 0 , FALSE ) ;
F_3 ( F_4 ( V_48 ) , V_29 , FALSE , FALSE , 10 ) ;
V_49 = F_52 ( V_52 ) ;
F_3 ( F_4 ( V_29 ) , V_49 , FALSE , FALSE , 10 ) ;
V_46 = F_36 ( NULL ) ;
F_45 ( NULL ) ;
F_53 ( F_41 ( V_46 ) , TRUE ) ;
F_37 ( F_38 ( V_46 ) , 0.0f , 0.5f ) ;
F_3 ( F_4 ( V_29 ) , V_46 , TRUE , TRUE , 5 ) ;
F_9 ( V_14 ) ;
return V_14 ;
}
static void
F_54 ( const T_9 * V_53 , ... ) {
T_14 V_54 ;
T_9 * V_34 ;
va_start ( V_54 , V_53 ) ;
V_34 = F_55 ( V_53 , V_54 ) ;
va_end ( V_54 ) ;
V_55 = F_56 ( V_55 , V_34 ) ;
F_45 ( V_34 ) ;
F_57 ( V_56 ) ;
}
static void
F_58 ( void ) {
T_9 * V_34 = NULL ;
if ( V_55 ) {
F_42 ( V_55 -> V_57 ) ;
V_55 = F_59 ( V_55 , V_55 ) ;
}
if ( V_55 ) {
V_34 = ( T_9 * ) V_55 -> V_57 ;
}
F_45 ( V_34 ) ;
if ( ! V_55 ) {
F_60 ( V_56 ) ;
}
}
static T_1 *
F_61 ( const char * V_58 )
{
T_1 * V_28 ;
T_1 * V_14 ;
T_9 * V_59 ;
V_28 = F_36 ( V_58 ) ;
V_59 = F_39 ( L_10 , V_58 ) ;
F_40 ( F_41 ( V_28 ) , V_59 ) ;
F_42 ( V_59 ) ;
V_14 = F_31 () ;
F_24 ( F_14 ( V_14 ) , V_28 ) ;
#if F_21 ( 3 , 0 , 0 )
F_27 ( V_14 , V_16 , & V_60 ) ;
#else
F_28 ( V_14 , V_18 , & V_61 ) ;
#endif
return V_14 ;
}
static T_1 *
F_62 ( const char * V_58 , T_1 * * V_62 )
{
T_1 * V_63 ;
T_1 * V_64 ;
T_1 * V_65 ;
T_1 * V_66 ;
V_63 = F_2 ( V_5 , 0 , FALSE ) ;
V_66 = F_61 ( V_58 ) ;
F_3 ( F_4 ( V_63 ) , V_66 , FALSE , FALSE , 0 ) ;
V_64 = F_2 ( V_5 , 5 , FALSE ) ;
F_63 ( F_14 ( V_64 ) , 10 ) ;
F_3 ( F_4 ( V_63 ) , V_64 , FALSE , FALSE , 0 ) ;
V_65 = F_31 () ;
F_24 ( F_14 ( V_65 ) , V_63 ) ;
#if F_21 ( 3 , 0 , 0 )
F_27 ( V_65 , V_16 , & V_67 ) ;
#else
F_28 ( V_65 , V_18 , & V_68 ) ;
#endif
* V_62 = V_64 ;
return V_65 ;
}
static T_4
F_64 ( T_1 * T_15 V_15 , T_11 * T_6 V_15 , T_7 V_57 )
{
F_65 ( ( T_9 * ) V_57 ) ;
return FALSE ;
}
static void *
F_66 ( void * V_57 )
{
T_16 * V_69 = ( T_16 * ) V_57 ;
T_17 V_70 ;
T_9 * V_71 ;
int V_72 ;
if ( ! V_69 ) {
return NULL ;
}
V_72 = F_67 ( V_69 -> V_73 , & V_70 ) ;
F_68 ( V_74 ) ;
V_69 -> V_72 = V_72 ;
if( V_72 == 0 ) {
V_71 = F_69 ( V_70 . V_75 , ( V_76 ) ( V_77 | V_78 ) ) ;
F_70 ( V_69 -> V_47 , L_11 ) ;
F_48 ( V_69 -> V_47 , L_12 , V_71 ) ;
F_42 ( V_71 ) ;
} else {
F_47 ( V_69 -> V_47 , L_13 ) ;
}
if ( ! V_69 -> V_79 ) {
F_42 ( V_69 -> V_73 ) ;
F_50 ( V_69 -> V_47 , TRUE ) ;
F_42 ( V_69 ) ;
} else {
V_69 -> V_80 = TRUE ;
}
F_71 ( V_74 ) ;
return NULL ;
}
static T_4
F_72 ( T_7 V_57 )
{
T_16 * V_69 = ( T_16 * ) V_57 ;
T_4 V_81 = TRUE ;
if ( ! V_69 ) {
return FALSE ;
}
F_68 ( V_74 ) ;
if ( V_69 -> V_80 ) {
V_81 = FALSE ;
F_40 ( F_41 ( V_69 -> V_79 ) , V_69 -> V_47 -> V_47 ) ;
if ( V_69 -> V_72 == 0 ) {
F_73 ( V_69 -> V_79 , TRUE ) ;
F_74 ( ( V_82 * ) V_69 -> V_83 , TRUE ) ;
}
V_69 -> V_84 = 0 ;
}
F_71 ( V_74 ) ;
return V_81 ;
}
static void F_75 ( T_1 * V_28 V_15 , T_7 V_57 ) {
T_16 * V_69 = ( T_16 * ) V_57 ;
if ( ! V_69 ) {
return;
}
F_68 ( V_74 ) ;
if ( V_69 -> V_84 ) {
F_76 ( V_69 -> V_84 ) ;
V_69 -> V_84 = 0 ;
}
F_77 ( V_69 -> V_83 ) ;
if ( V_69 -> V_80 ) {
F_42 ( V_69 -> V_73 ) ;
F_50 ( V_69 -> V_47 , TRUE ) ;
F_42 ( V_69 ) ;
} else {
V_69 -> V_79 = NULL ;
}
F_71 ( V_74 ) ;
}
static T_1 *
F_78 ( const T_9 * V_73 , T_1 * * V_79 , T_18 * V_83 )
{
T_1 * V_28 ;
T_1 * V_14 ;
T_12 * V_47 ;
T_9 * V_85 ;
T_19 V_86 ;
T_20 V_87 , V_88 ;
const T_19 V_89 = 60 ;
T_16 * V_69 ;
V_47 = F_46 ( V_73 ) ;
V_86 = F_79 ( V_47 -> V_47 , V_47 -> V_90 ) ;
if ( V_86 > V_89 ) {
V_87 = F_80 ( V_47 -> V_47 , 20 ) - V_47 -> V_47 ;
V_88 = F_80 ( V_47 -> V_47 , V_86 - V_89 ) - V_47 -> V_47 ;
F_81 ( V_47 , V_87 , V_88 ) ;
F_82 ( V_47 , V_87 , L_14 V_91 L_14 ) ;
}
V_85 = F_83 ( V_47 -> V_47 , - 1 ) ;
F_50 ( V_47 , TRUE ) ;
V_28 = F_36 ( V_85 ) ;
* V_79 = V_28 ;
F_84 ( F_38 ( V_28 ) , 5 , 2 ) ;
F_37 ( F_38 ( V_28 ) , 0.0f , 0.0f ) ;
F_73 ( V_28 , FALSE ) ;
V_69 = ( T_16 * ) F_85 ( sizeof( T_16 ) ) ;
V_69 -> V_73 = F_86 ( V_73 ) ;
V_69 -> V_79 = V_28 ;
V_69 -> V_83 = V_83 ;
V_69 -> V_47 = F_46 ( V_85 ) ;
V_69 -> V_80 = FALSE ;
V_69 -> V_84 = 0 ;
F_19 ( F_7 ( V_83 ) ) ;
F_33 ( V_28 , L_15 , F_34 ( F_75 ) , V_69 ) ;
F_42 ( V_85 ) ;
#if F_87 ( 2 , 31 , 0 )
F_88 ( L_16 , F_66 , V_69 ) ;
#else
F_89 ( F_66 , V_69 , FALSE , NULL ) ;
#endif
V_69 -> V_84 = F_90 ( 200 , F_72 , V_69 ) ;
V_14 = F_31 () ;
#if F_21 ( 3 , 0 , 0 )
F_27 ( V_14 , V_16 , & V_20 ) ;
#else
F_28 ( V_14 , V_18 , & V_21 ) ;
#endif
F_24 ( F_14 ( V_14 ) , V_28 ) ;
F_32 ( V_14 , V_73 ) ;
F_33 ( V_14 , L_1 , F_34 ( F_26 ) , V_28 ) ;
F_33 ( V_14 , L_2 , F_34 ( F_29 ) , V_28 ) ;
F_33 ( V_14 , L_17 , F_34 ( F_64 ) , ( T_9 * ) V_73 ) ;
return V_14 ;
}
void
F_91 ( void )
{
T_1 * V_1 ;
T_3 * V_92 ;
T_3 * V_93 ;
if( V_94 ) {
V_1 = F_25 ( V_94 ) ;
V_92 = F_13 ( F_14 ( V_1 ) ) ;
V_93 = V_92 ;
while( V_93 ) {
F_20 ( F_14 ( V_1 ) , ( T_1 * ) V_93 -> V_57 ) ;
V_93 = F_92 ( V_93 ) ;
}
F_16 ( V_92 ) ;
}
}
void
F_93 ( const char * V_95 , T_18 * V_83 )
{
T_1 * V_28 ;
T_1 * V_1 ;
T_1 * V_79 ;
V_28 = F_78 ( V_95 , & V_79 , V_83 ) ;
V_1 = F_10 ( V_94 ) ;
F_3 ( F_4 ( V_1 ) , V_28 , FALSE , FALSE , 0 ) ;
F_9 ( V_28 ) ;
F_9 ( V_1 ) ;
}
static T_4
F_94 ( T_21 * T_22 V_15 ,
T_23 * V_96 ,
T_24 * V_97 ,
T_4 V_98 ,
T_7 V_57 V_15 )
{
T_25 V_99 ;
T_9 * V_100 ;
T_2 V_101 ;
T_26 V_102 ;
F_95 ( V_96 , & V_99 , V_97 ) ;
F_96 ( V_96 , & V_99 , V_103 , & V_100 , - 1 ) ;
for ( V_101 = 0 ; V_101 < V_104 . V_105 -> V_90 ; V_101 ++ ) {
V_102 = F_97 ( V_104 . V_105 , T_26 , V_101 ) ;
if ( strcmp ( V_102 . V_106 , V_100 ) == 0 ) {
if ( ! V_102 . V_107 ) {
if ( V_98 ) {
if ( V_102 . V_108 ) {
V_102 . V_108 = FALSE ;
V_104 . V_109 -- ;
}
} else {
if ( ! V_102 . V_108 ) {
V_102 . V_108 = TRUE ;
V_104 . V_109 ++ ;
}
}
V_102 . V_107 = TRUE ;
V_104 . V_105 = F_98 ( V_104 . V_105 , V_101 ) ;
F_99 ( V_104 . V_105 , V_101 , V_102 ) ;
if ( F_100 () ) {
F_101 ( F_86 ( V_100 ) , V_102 . V_108 ) ;
}
if ( F_102 () ) {
F_103 ( F_86 ( V_100 ) ) ;
}
V_102 . V_107 = FALSE ;
V_104 . V_105 = F_98 ( V_104 . V_105 , V_101 ) ;
F_99 ( V_104 . V_105 , V_101 , V_102 ) ;
}
break;
}
}
F_104 () ;
return TRUE ;
}
void
F_104 ( void )
{
#ifdef F_105
T_4 V_110 = ( V_104 . V_109 > 0 ) ;
F_106 ( V_110 ) ;
F_107 ( V_110 ) ;
#endif
}
static T_4
F_108 ( T_23 * V_96 , T_24 * V_97 V_15 , T_25 * V_99 ,
T_7 V_111 )
{
T_9 * V_100 ;
T_1 * V_112 ;
T_21 * T_22 ;
T_27 * V_113 = ( T_27 * ) V_111 ;
V_112 = ( T_1 * ) F_11 ( F_7 ( V_56 ) , V_114 ) ;
T_22 = F_109 ( F_110 ( V_112 ) ) ;
F_96 ( V_96 , V_99 , V_103 , & V_100 , - 1 ) ;
if ( strcmp ( V_100 , V_113 -> V_106 ) == 0 ) {
if ( V_113 -> V_115 ) {
F_111 ( T_22 , V_99 ) ;
} else {
F_112 ( T_22 , V_99 ) ;
}
return TRUE ;
}
return FALSE ;
}
void
F_113 ( T_9 * V_106 , T_4 V_115 )
{
T_1 * V_112 ;
T_23 * V_96 ;
T_27 V_113 ;
V_112 = ( T_1 * ) F_11 ( F_7 ( V_56 ) , V_114 ) ;
V_96 = F_114 ( F_110 ( V_112 ) ) ;
V_113 . V_106 = F_86 ( V_106 ) ;
V_113 . V_115 = V_115 ;
F_115 ( F_116 ( V_96 ) , ( V_116 ) ( F_108 ) , ( T_7 ) & V_113 ) ;
}
void
F_117 ( T_4 V_110 )
{
T_2 V_101 ;
T_4 V_117 = FALSE ;
T_26 V_102 ;
for ( V_101 = 0 ; V_101 < V_104 . V_105 -> V_90 ; V_101 ++ ) {
V_102 = F_97 ( V_104 . V_105 , T_26 , V_101 ) ;
V_117 = strcmp ( V_102 . V_106 , L_18 ) ;
if ( V_117 ) {
F_113 ( V_102 . V_106 , V_110 ) ;
} else {
F_113 ( V_102 . V_106 , FALSE ) ;
}
}
}
void
F_118 ( T_9 * V_118 , T_2 V_119 )
{
T_1 * V_112 ;
T_23 * V_96 ;
T_25 V_99 ;
T_26 V_102 ;
T_21 * V_113 ;
T_9 * V_120 ;
V_112 = ( T_1 * ) F_11 ( F_7 ( V_56 ) , V_114 ) ;
V_113 = F_109 ( F_110 ( V_112 ) ) ;
V_96 = F_114 ( F_110 ( V_112 ) ) ;
V_102 = F_97 ( V_104 . V_105 , T_26 , V_119 ) ;
if ( F_119 ( V_96 , & V_99 ) ) {
do {
F_96 ( V_96 , & V_99 , V_103 , & V_120 , - 1 ) ;
if ( strcmp ( V_120 , V_118 ) == 0 ) {
F_120 ( F_121 ( V_96 ) , & V_99 , V_121 , F_122 ( F_123 ( F_124 ( & V_102 ) ) ) , V_122 , V_102 . V_123 , V_103 , V_102 . V_106 , - 1 ) ;
if ( V_102 . V_108 ) {
F_111 ( V_113 , & V_99 ) ;
}
break;
}
} while ( F_125 ( V_96 , & V_99 ) );
F_42 ( V_120 ) ;
}
}
void
F_126 ( T_2 V_119 )
{
T_1 * V_112 , * V_49 ;
T_23 * V_96 ;
T_25 V_99 ;
T_28 V_124 ;
T_9 * V_125 ;
T_26 V_102 ;
V_102 = F_97 ( V_104 . V_105 , T_26 , V_119 ) ;
V_49 = F_52 ( V_126 ) ;
V_112 = F_11 ( F_7 ( V_56 ) , V_114 ) ;
V_96 = F_114 ( F_110 ( V_112 ) ) ;
V_124 = F_127 ( V_96 , NULL ) ;
V_125 = F_39 ( L_19 , V_124 - 1 ) ;
if ( F_128 ( V_96 , & V_99 , V_125 ) ) {
F_129 ( F_121 ( V_96 ) , & V_99 ) ;
F_120 ( F_121 ( V_96 ) , & V_99 , V_121 , F_122 ( F_123 ( V_49 ) ) , V_122 , V_102 . V_123 , V_103 , V_102 . V_106 , - 1 ) ;
}
}
static void
F_130 ( void )
{
T_1 * V_29 ;
V_29 = ( T_1 * ) F_11 ( F_7 ( V_56 ) , V_127 ) ;
if ( V_29 ) {
F_131 ( V_29 ) ;
}
V_29 = ( T_1 * ) F_11 ( F_7 ( V_56 ) , V_128 ) ;
if ( V_29 ) {
F_131 ( V_29 ) ;
}
V_29 = ( T_1 * ) F_11 ( F_7 ( V_56 ) , V_129 ) ;
if ( V_29 ) {
F_131 ( V_29 ) ;
}
V_29 = ( T_1 * ) F_11 ( F_7 ( V_56 ) , V_130 ) ;
if ( V_29 ) {
F_131 ( V_29 ) ;
}
if ( V_131 ) {
F_131 ( V_131 ) ;
V_131 = NULL ;
V_132 = NULL ;
}
}
static void
F_132 ( void )
{
T_2 V_101 ;
T_26 V_102 ;
int V_133 = 0 ;
if( V_131 == NULL ) {
return;
}
for ( V_101 = 0 ; V_101 < V_104 . V_105 -> V_90 ; V_101 ++ ) {
V_102 = F_97 ( V_104 . V_105 , T_26 , V_101 ) ;
if ( ! V_102 . V_134 ) {
V_133 ++ ;
}
}
if( V_133 > 10 ) {
V_133 = 10 ;
}
if( V_133 < 2 ) {
V_133 = 2 ;
}
F_18 ( V_131 , FALSE , V_133 * 21 + 4 ) ;
}
static void
F_133 ( void )
{
T_2 V_101 ;
T_29 * V_135 ;
T_25 V_99 ;
T_21 * V_113 ;
T_26 V_102 ;
T_4 V_136 = FALSE ;
V_135 = F_134 ( V_137 , V_138 , V_139 , V_139 ) ;
F_135 ( V_135 ) ;
F_136 ( F_110 ( V_132 ) , F_116 ( V_135 ) ) ;
V_113 = F_109 ( F_110 ( V_132 ) ) ;
for ( V_101 = 0 ; V_101 < V_104 . V_105 -> V_90 ; V_101 ++ ) {
V_102 = F_97 ( V_104 . V_105 , T_26 , V_101 ) ;
if ( ! V_102 . V_134 ) {
F_129 ( V_135 , & V_99 ) ;
F_120 ( V_135 , & V_99 , V_121 , F_122 ( F_123 ( F_124 ( & V_102 ) ) ) , V_122 , V_102 . V_123 , V_103 , V_102 . V_106 , - 1 ) ;
if ( V_102 . V_108 ) {
F_111 ( V_113 , & V_99 ) ;
}
}
}
F_132 () ;
V_136 = TRUE ;
F_137 ( F_138 ( V_113 ) , F_94 , ( T_7 ) & V_136 , NULL ) ;
}
static void
F_139 ( T_1 * V_28 V_15 , T_7 T_8 V_15 )
{
F_130 () ;
F_140 () ;
}
static void
F_141 ( void )
{
T_1 * V_140 , * V_141 ;
T_1 * V_142 , * V_143 , * V_144 , * V_79 , * V_28 ;
T_21 * T_22 ;
T_30 * V_145 ;
T_31 * V_146 ;
int error = 0 ;
T_9 * V_147 = NULL , * V_148 = NULL ;
#ifdef F_142
T_32 V_149 ;
T_32 V_150 = 0 ;
T_32 V_151 = sizeof( V_150 ) ;
#endif
V_79 = ( T_1 * ) F_11 ( F_7 ( V_56 ) , V_152 ) ;
if ( V_79 ) {
F_131 ( V_79 ) ;
}
V_140 = ( T_1 * ) F_11 ( F_7 ( V_56 ) , V_153 ) ;
if ( V_104 . V_105 -> V_90 > 0 ) {
V_142 = F_30 ( V_154 ,
L_20 ,
L_21 ,
L_22 ,
F_43 , V_155 ) ;
F_3 ( F_4 ( V_140 ) , V_142 , FALSE , FALSE , 5 ) ;
V_131 = F_143 ( NULL , NULL ) ;
F_132 () ;
F_144 ( F_23 ( V_131 ) , V_156 ) ;
F_145 ( F_23 ( V_131 ) , V_157 , V_157 ) ;
F_6 ( F_7 ( V_56 ) , V_127 , V_142 ) ;
V_132 = F_146 () ;
F_147 ( F_7 ( V_132 ) , L_23 , FALSE , NULL ) ;
F_33 ( V_132 , L_24 , F_34 ( V_158 ) , ( T_7 ) V_56 ) ;
F_6 ( F_7 ( V_56 ) , V_114 , V_132 ) ;
V_146 = F_148 () ;
V_145 = F_149 () ;
F_150 ( V_146 , V_145 , FALSE ) ;
F_151 ( V_146 , V_145 , L_25 , V_121 , NULL ) ;
V_145 = F_152 () ;
F_150 ( V_146 , V_145 , TRUE ) ;
F_151 ( V_146 , V_145 , L_26 , V_122 , NULL ) ;
F_153 ( F_110 ( V_132 ) , V_146 ) ;
F_154 ( F_155 ( F_110 ( V_132 ) , 0 ) , TRUE ) ;
V_145 = F_152 () ;
V_146 = F_156 ( L_27 ,
F_157 ( V_145 ) ,
L_26 , V_103 ,
NULL ) ;
F_153 ( F_110 ( V_132 ) , V_146 ) ;
F_158 ( V_146 , FALSE ) ;
T_22 = F_109 ( F_110 ( V_132 ) ) ;
F_159 ( T_22 , V_159 ) ;
V_144 = F_30 ( V_160 ,
L_28 ,
L_29 ,
L_30 ,
( T_10 ) V_161 , ( T_7 ) V_132 ) ;
F_3 ( F_4 ( V_140 ) , V_144 , FALSE , FALSE , 5 ) ;
F_133 () ;
F_24 ( F_14 ( V_131 ) , V_132 ) ;
F_24 ( F_14 ( V_140 ) , V_131 ) ;
F_6 ( F_7 ( V_56 ) , V_128 , V_144 ) ;
V_143 = F_30 ( V_162 ,
L_31 ,
L_32 ,
L_33 ,
F_43 , V_163 ) ;
F_3 ( F_4 ( V_140 ) , V_143 , FALSE , FALSE , 5 ) ;
F_6 ( F_7 ( V_56 ) , V_129 , V_143 ) ;
#ifdef F_142
V_149 = F_160 ( V_164 ,
F_161 ( L_34 ) ,
NULL , NULL , ( V_165 ) & V_150 , & V_151 ) ;
if ( V_149 == V_166 && V_150 ) {
F_30 ( V_167 ,
L_35 ,
L_36 ,
F_162 ( V_168 ) ,
V_169 , F_8 ( V_168 ) ) ;
F_3 ( F_4 ( V_140 ) , V_143 , FALSE , FALSE , 5 ) ;
}
#endif
} else {
if ( V_132 ) {
F_130 () ;
}
F_163 ( & error , & V_148 , V_170 ) ;
switch ( error ) {
case 0 :
V_147 = F_86 ( L_37
L_38
L_39
L_40 ) ;
break;
case V_171 :
V_147 = F_39 ( L_37
L_41
L_42
L_39
L_40 ,
V_148 ) ;
break;
case V_172 :
V_147 = F_86 ( L_43
L_44
L_45
L_39
#if F_21 ( 2 , 18 , 0 )
L_46
#else
L_47
#endif
L_39
L_48
L_49
L_50 ) ;
break;
default:
V_147 = F_39 ( L_51 , error ) ;
break;
}
if ( V_148 != NULL )
F_42 ( V_148 ) ;
V_28 = F_36 ( V_147 ) ;
F_40 ( F_41 ( V_28 ) , V_147 ) ;
F_164 ( F_41 ( V_28 ) , TRUE ) ;
F_42 ( V_147 ) ;
F_37 ( F_38 ( V_28 ) , 0.0f , 0.0f ) ;
F_3 ( F_4 ( V_140 ) , V_28 , FALSE , FALSE , 5 ) ;
#if F_21 ( 2 , 18 , 0 )
F_33 ( V_28 , L_52 , F_34 ( V_173 ) , NULL ) ;
#endif
F_6 ( F_7 ( V_56 ) , V_152 , V_28 ) ;
if ( error == V_171 || error == 0 ) {
V_141 = F_30 ( V_174 ,
L_53 ,
L_54 ,
L_55 ,
F_43 , F_139 ) ;
F_3 ( F_4 ( V_140 ) , V_141 , FALSE , FALSE , 5 ) ;
F_6 ( F_7 ( V_56 ) , V_130 , V_141 ) ;
}
}
}
void
F_165 ( void )
{
#ifdef F_105
if ( V_56 ) {
if ( V_132 && V_131 && V_104 . V_105 -> V_90 > 0 ) {
F_133 () ;
} else {
T_1 * V_29 ;
V_29 = ( T_1 * ) F_11 ( F_7 ( V_56 ) , V_130 ) ;
if ( V_29 ) {
F_131 ( V_29 ) ;
}
F_141 () ;
}
F_9 ( V_56 ) ;
}
#endif
}
static void
V_161 ( T_1 * V_28 V_15 , T_7 V_57 V_15 )
{
#ifdef F_166
T_26 V_102 ;
T_2 V_101 ;
#endif
if ( V_104 . V_109 == 0 ) {
F_167 ( V_175 , V_176 ,
L_56 ) ;
return;
}
if ( V_104 . V_177 ) {
F_42 ( V_104 . V_177 ) ;
V_104 . V_177 = NULL ;
}
#ifdef F_166
for ( V_101 = 0 ; V_101 < V_104 . V_105 -> V_90 ; V_101 ++ ) {
V_102 = F_97 ( V_104 . V_105 , T_26 , V_101 ) ;
V_178 = F_168 ( V_179 , V_102 . V_106 ) ;
V_180 = V_178 ;
if ( V_180 ) {
break;
}
}
if ( V_178 )
F_169 ( V_178 ) ;
#endif
F_170 ( NULL , NULL ) ;
}
static T_4
V_173 ( T_33 * V_79 V_15 , T_9 * V_181 , T_7 T_8 V_15 )
{
return F_171 ( V_181 ) ;
}
T_1 *
F_172 ( void )
{
T_1 * V_182 ;
T_1 * V_183 ;
T_1 * V_184 ;
T_1 * V_185 ;
T_1 * V_29 ;
T_1 * V_28 ;
T_1 * V_58 ;
T_1 * V_63 ;
T_1 * V_186 ;
T_1 * V_187 ;
T_9 * V_147 ;
T_1 * V_188 ;
#if 0
get_color(&welcome_bg);
get_color(&header_bar_bg);
get_color(&topic_header_bg);
get_color(&topic_content_bg);
#endif
#if F_21 ( 3 , 0 , 0 )
V_20 = V_67 ;
#else
V_21 = V_68 ;
#endif
#if 0
get_color(&topic_item_entered_bg);
#endif
V_182 = F_17 ( NULL , NULL ) ;
V_184 = F_2 ( V_5 , 0 , FALSE ) ;
V_183 = F_31 () ;
F_24 ( F_14 ( V_183 ) , V_184 ) ;
#if F_21 ( 3 , 0 , 0 )
F_27 ( V_183 , V_16 , & V_189 ) ;
#else
F_28 ( V_183 , V_18 , & V_190 ) ;
#endif
V_58 = F_51 () ;
F_3 ( F_4 ( V_184 ) , V_58 , FALSE , FALSE , 0 ) ;
V_56 = F_2 ( V_32 , 10 , FALSE ) ;
F_63 ( F_14 ( V_56 ) , 10 ) ;
F_3 ( F_4 ( V_184 ) , V_56 , TRUE , TRUE , 0 ) ;
V_185 = F_2 ( V_5 , 10 , FALSE ) ;
#if F_21 ( 3 , 0 , 0 )
F_27 ( V_185 , V_16 , & V_189 ) ;
#else
F_28 ( V_185 , V_18 , & V_190 ) ;
#endif
F_3 ( F_4 ( V_56 ) , V_185 , TRUE , TRUE , 0 ) ;
V_63 = F_62 ( L_57 , & V_187 ) ;
F_3 ( F_4 ( V_185 ) , V_63 , TRUE , TRUE , 0 ) ;
F_6 ( F_7 ( V_56 ) , V_153 , V_187 ) ;
#ifdef F_105
F_173 ( V_170 ) ;
F_141 () ;
V_63 = F_62 ( L_58 , & V_186 ) ;
F_3 ( F_4 ( V_185 ) , V_63 , TRUE , TRUE , 0 ) ;
V_29 = F_30 ( V_167 ,
L_59 ,
L_60 ,
F_162 ( V_191 ) ,
V_169 , F_8 ( V_191 ) ) ;
F_3 ( F_4 ( V_186 ) , V_29 , FALSE , FALSE , 5 ) ;
V_29 = F_30 ( V_167 ,
L_61 ,
L_62 ,
F_162 ( V_192 ) ,
V_169 , F_8 ( V_192 ) ) ;
F_3 ( F_4 ( V_186 ) , V_29 , FALSE , FALSE , 5 ) ;
#else
V_147 = F_86 ( L_63 ) ;
V_28 = F_36 ( V_147 ) ;
F_40 ( F_41 ( V_28 ) , V_147 ) ;
F_42 ( V_147 ) ;
F_37 ( F_38 ( V_28 ) , 0.0f , 0.0f ) ;
F_3 ( F_4 ( V_187 ) , V_28 , FALSE , FALSE , 5 ) ;
#endif
V_28 = F_36 ( L_27 ) ;
F_3 ( F_4 ( V_187 ) , V_28 , TRUE , TRUE , 0 ) ;
V_63 = F_62 ( L_64 , & V_186 ) ;
F_3 ( F_4 ( V_56 ) , V_63 , TRUE , TRUE , 0 ) ;
V_29 = F_30 ( V_193 ,
L_65 ,
L_66 ,
L_67 ,
F_43 , V_194 ) ;
F_3 ( F_4 ( V_186 ) , V_29 , FALSE , FALSE , 5 ) ;
V_147 = F_86 ( L_68 ) ;
V_28 = F_36 ( V_147 ) ;
F_40 ( F_41 ( V_28 ) , V_147 ) ;
F_42 ( V_147 ) ;
F_37 ( F_38 ( V_28 ) , 0.0f , 0.0f ) ;
F_3 ( F_4 ( V_186 ) , V_28 , FALSE , FALSE , 5 ) ;
V_188 = F_2 ( V_5 , 1 , FALSE ) ;
V_94 = F_1 ( F_5 ( V_188 ) , 17 , 300 ) ;
F_3 ( F_4 ( V_186 ) , V_94 , FALSE , FALSE , 0 ) ;
V_29 = F_30 ( V_167 ,
L_69 ,
L_70 ,
F_162 ( V_195 ) ,
V_169 , F_8 ( V_195 ) ) ;
F_3 ( F_4 ( V_186 ) , V_29 , FALSE , FALSE , 5 ) ;
V_28 = F_36 ( L_27 ) ;
F_3 ( F_4 ( V_186 ) , V_28 , TRUE , TRUE , 0 ) ;
V_185 = F_2 ( V_5 , 10 , FALSE ) ;
F_3 ( F_4 ( V_56 ) , V_185 , TRUE , TRUE , 0 ) ;
V_63 = F_62 ( L_71 , & V_186 ) ;
F_3 ( F_4 ( V_185 ) , V_63 , TRUE , TRUE , 0 ) ;
V_29 = F_30 ( V_196 ,
L_72 ,
L_73 ,
F_162 ( V_197 ) ,
V_169 , F_8 ( V_197 ) ) ;
F_3 ( F_4 ( V_186 ) , V_29 , FALSE , FALSE , 5 ) ;
#ifdef F_174
V_29 = F_30 ( V_198 ,
L_74 ,
L_75
L_76 ,
L_77 ,
V_169 , F_8 ( V_199 ) ) ;
#else
V_29 = F_30 ( V_198 ,
L_74 ,
L_75
L_78 ,
F_162 ( V_200 ) ,
V_169 , F_8 ( V_200 ) ) ;
#endif
F_3 ( F_4 ( V_186 ) , V_29 , FALSE , FALSE , 5 ) ;
V_29 = F_30 ( V_167 ,
L_79 ,
L_80 ,
F_162 ( V_201 ) ,
V_169 , F_8 ( V_201 ) ) ;
F_3 ( F_4 ( V_186 ) , V_29 , FALSE , FALSE , 5 ) ;
#if 0
topic_vb = welcome_topic_new("Updates", &topic_to_fill);
gtk_box_pack_start(GTK_BOX(column_vb), topic_vb, TRUE, TRUE, 0);
label_text = g_strdup("<span foreground=\"black\">No updates available!</span>");
w = gtk_label_new(label_text);
gtk_label_set_markup(GTK_LABEL(w), label_text);
g_free (label_text);
gtk_box_pack_start(GTK_BOX(topic_to_fill), w, TRUE, TRUE, 0);
#endif
F_9 ( V_183 ) ;
#if ! F_21 ( 3 , 8 , 0 )
F_22 ( F_23 ( V_182 ) , V_183 ) ;
#else
F_24 ( F_14 ( V_182 ) , V_183 ) ;
#endif
F_9 ( V_182 ) ;
#if F_87 ( 2 , 31 , 0 )
V_74 = ( V_202 * ) F_85 ( sizeof( V_202 ) ) ;
F_175 ( V_74 ) ;
#else
V_74 = F_176 () ;
#endif
return V_182 ;
}
T_1 *
F_177 ( void )
{
return V_56 ;
}
static void
F_178 ( T_34 * T_35 V_15 )
{
F_58 () ;
}
void
F_179 ( T_28 T_6 , T_7 V_57 , T_7 T_8 V_15 )
{
switch( T_6 ) {
case ( V_203 ) :
break;
case ( V_204 ) :
F_178 ( ( T_34 * ) V_57 ) ;
break;
case ( V_205 ) :
break;
case ( V_206 ) :
break;
case ( V_207 ) :
break;
case ( V_208 ) :
break;
case ( V_209 ) :
break;
case ( V_210 ) :
break;
case ( V_211 ) :
break;
case ( V_212 ) :
break;
case ( V_213 ) :
break;
case ( V_214 ) :
break;
case ( V_215 ) :
break;
case ( V_216 ) :
break;
case ( V_217 ) :
break;
case ( V_218 ) :
break;
case ( V_219 ) :
break;
case ( V_220 ) :
break;
case ( V_221 ) :
break;
case ( V_222 ) :
break;
case ( V_223 ) :
break;
case ( V_224 ) :
break;
case ( V_225 ) :
break;
default:
F_180 ( L_81 , T_6 ) ;
F_181 () ;
}
}
static void
F_182 ( T_36 * T_37 V_15 )
{
F_58 () ;
}
static void
F_183 ( T_36 * T_37 )
{
T_38 * V_226 = T_37 -> V_226 ;
T_12 * V_227 ;
F_58 () ;
V_227 = F_184 ( V_226 , 0 ) ;
F_54 ( L_82 , V_227 -> V_47 ) ;
F_50 ( V_227 , TRUE ) ;
}
static void
F_185 ( T_36 * T_37 V_15 )
{
F_58 () ;
}
static void
F_186 ( T_36 * T_37 V_15 )
{
static const T_9 V_34 [] = L_83 ;
F_54 ( V_34 ) ;
}
static void
F_187 ( T_36 * T_37 V_15 )
{
F_58 () ;
}
void
F_188 ( T_28 T_6 , T_36 * T_37 ,
T_7 T_8 V_15 )
{
switch( T_6 ) {
case ( V_228 ) :
F_186 ( T_37 ) ;
break;
case ( V_229 ) :
F_182 ( T_37 ) ;
break;
case ( V_230 ) :
break;
case ( V_231 ) :
break;
case ( V_232 ) :
F_183 ( T_37 ) ;
break;
case ( V_233 ) :
break;
case ( V_234 ) :
F_185 ( T_37 ) ;
break;
case ( V_235 ) :
break;
case ( V_236 ) :
F_187 ( T_37 ) ;
break;
default:
F_180 ( L_84 , T_6 ) ;
F_181 () ;
}
}
