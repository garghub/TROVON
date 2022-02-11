const T_1 *
F_1 ( void ) {
return V_1 ;
}
static void
F_2 ( void * T_2 V_2 , int V_3 , const char * V_4 , T_3 args )
{
T_4 V_5 = V_6 ;
switch ( V_3 ) {
case V_7 :
case V_8 :
case V_9 :
default:
return;
case V_10 :
case V_11 :
V_5 = V_6 ;
break;
case V_12 :
V_5 = V_13 ;
break;
case V_14 :
V_5 = V_15 ;
break;
}
F_3 ( NULL , V_5 , V_4 , args ) ;
}
void
F_4 ( void )
{
#ifdef F_5
F_6 () ;
F_7 () ;
#endif
}
T_5
F_8 ( void (* F_9)( T_6 V_16 , T_7 V_17 ) ,
void (* F_10)( T_6 V_16 , T_7 V_17 ) ,
T_6 V_16 ,
T_7 V_17 )
{
volatile T_5 V_18 = TRUE ;
F_11 () ;
F_12 () ;
F_13 () ;
F_14 () ;
F_15 ( NULL ) ;
#if F_16 ( V_19 )
F_17 ( F_2 , NULL ) ;
#endif
F_18 ( V_20 , 0 ) ;
F_18 ( V_21 , 0 ) ;
#ifdef F_19
F_20 () ;
#endif
#ifdef F_21
F_22 () ;
V_22 ;
#endif
F_23 {
F_24 () ;
F_25 () ;
F_26 () ;
F_27 () ;
F_28 () ;
F_29 () ;
F_30 () ;
F_31 ( F_9 , F_10 ,
V_16 , V_17 ) ;
F_32 () ;
F_33 () ;
F_34 () ;
F_35 () ;
F_36 () ;
F_37 () ;
#ifdef F_38
F_39 ( V_16 , V_17 ) ;
#endif
}
F_40 (DissectorError) {
const char * V_23 = V_24 ;
static const char V_25 [] =
L_1 ;
F_41 ( L_2 ,
V_23 == NULL ?
V_25 : V_23 ) ;
if ( getenv ( L_3 ) != NULL )
abort () ;
V_18 = FALSE ;
}
V_26 ;
return V_18 ;
}
T_8 *
F_42 ( void )
{
T_8 * V_27 ;
F_43 () ;
V_27 = F_44 () ;
F_45 () ;
return V_27 ;
}
void
F_46 ( void )
{
F_47 () ;
F_48 () ;
F_49 () ;
F_50 () ;
F_51 () ;
F_52 () ;
F_53 () ;
F_54 () ;
F_55 () ;
F_56 () ;
F_57 () ;
F_58 () ;
F_59 () ;
F_60 ( NULL ) ;
#ifdef F_38
F_61 () ;
#endif
#ifdef F_19
F_62 () ;
#endif
#ifdef F_21
F_63 () ;
#endif
F_64 () ;
F_65 () ;
if ( V_28 != NULL ) {
F_66 ( V_28 ) ;
V_28 = NULL ;
}
F_67 () ;
}
T_9 *
F_68 ( void )
{
T_9 * V_29 = F_69 ( T_9 ) ;
F_70 () ;
return V_29 ;
}
const char *
F_71 ( const T_9 * V_29 , const T_10 * V_30 )
{
if ( V_29 -> V_31 )
return V_29 -> V_31 ( V_29 -> V_32 , V_30 ) ;
return NULL ;
}
const char *
F_72 ( const T_9 * V_29 , T_11 V_33 )
{
if ( V_29 -> V_34 )
return V_29 -> V_34 ( V_29 -> V_32 , V_33 ) ;
return NULL ;
}
const char *
F_73 ( const T_9 * V_29 , T_11 V_33 )
{
if ( V_29 -> V_35 )
return V_29 -> V_35 ( V_29 -> V_32 , V_33 ) ;
return NULL ;
}
const T_12 *
F_74 ( const T_9 * V_29 , T_11 V_36 )
{
const T_12 * V_37 = NULL ;
if ( V_29 -> V_38 )
V_37 = V_29 -> V_38 ( V_29 -> V_32 , V_36 ) ;
if ( ! V_37 )
F_75 ( L_4 , V_36 ) ;
return V_37 ;
}
void
F_76 ( T_9 * V_29 )
{
if ( V_29 ) {
F_77 () ;
F_78 ( T_9 , V_29 ) ;
}
}
void
F_79 ( void )
{
F_80 () ;
}
void
F_81 ( void )
{
F_82 () ;
}
void
F_83 ( void )
{
F_84 () ;
}
void
F_85 ( T_5 V_39 )
{
if ( V_39 )
V_40 ++ ;
else if ( V_40 > 0 )
V_40 -- ;
}
void
F_86 ( T_13 * V_41 , T_9 * V_29 , const T_5 V_42 , const T_5 V_43 )
{
F_87 ( V_41 ) ;
V_41 -> V_29 = V_29 ;
memset ( & V_41 -> V_44 , 0 , sizeof( V_41 -> V_44 ) ) ;
if ( V_28 != NULL ) {
V_41 -> V_44 . V_45 = V_28 ;
V_28 = NULL ;
}
else {
V_41 -> V_44 . V_45 = F_88 ( V_46 ) ;
}
if ( V_42 ) {
V_41 -> V_47 = F_89 ( & V_41 -> V_44 ) ;
F_90 ( V_41 -> V_47 , ( V_40 > 0 ) ? TRUE : V_43 ) ;
}
else {
V_41 -> V_47 = NULL ;
}
V_41 -> V_48 = NULL ;
}
void
F_91 ( T_13 * V_41 )
{
T_14 * V_49 ;
F_87 ( V_41 ) ;
F_92 ( V_41 -> V_44 . V_50 ) ;
F_92 ( V_41 -> V_44 . V_51 ) ;
F_93 ( & V_41 -> V_44 ) ;
if ( V_41 -> V_48 ) {
F_94 ( V_41 -> V_48 ) ;
V_41 -> V_48 = NULL ;
}
if ( V_41 -> V_47 )
F_95 ( V_41 -> V_47 ) ;
V_49 = V_41 -> V_44 . V_45 ;
F_96 ( V_49 ) ;
memset ( & V_41 -> V_44 , 0 , sizeof( V_41 -> V_44 ) ) ;
V_41 -> V_44 . V_45 = V_49 ;
}
T_13 *
F_97 ( T_9 * V_29 , const T_5 V_42 , const T_5 V_43 )
{
T_13 * V_41 ;
V_41 = F_98 ( T_13 , 1 ) ;
F_86 ( V_41 , V_29 , V_42 , V_43 ) ;
return V_41 ;
}
void
F_99 ( T_13 * V_41 , const T_5 V_52 )
{
if ( V_41 )
F_100 ( V_41 -> V_47 , V_52 ) ;
}
void
F_101 ( T_13 * V_41 , int V_53 ,
struct V_54 * V_55 , T_15 * V_48 , T_10 * V_30 ,
T_16 * V_56 )
{
#ifdef F_38
F_102 ( V_41 ) ;
#endif
F_103 () ;
F_104 ( V_41 , V_53 , V_55 , V_48 , V_30 , V_56 ) ;
F_105 () ;
}
void
F_106 ( T_13 * V_41 , int V_53 ,
struct V_54 * V_55 , T_15 * V_48 , T_10 * V_30 ,
T_16 * V_56 )
{
F_103 () ;
F_107 ( V_41 ) ;
F_104 ( V_41 , V_53 , V_55 , V_48 , V_30 , V_56 ) ;
F_108 ( V_41 ) ;
F_105 () ;
}
void
F_109 ( T_13 * V_41 , struct V_54 * V_55 ,
T_15 * V_48 , T_10 * V_30 , T_16 * V_56 )
{
#ifdef F_38
F_102 ( V_41 ) ;
#endif
F_103 () ;
F_110 ( V_41 , V_55 , V_48 , V_30 , V_56 ) ;
F_105 () ;
}
void
F_111 ( T_13 * V_41 , struct V_54 * V_55 ,
T_15 * V_48 , T_10 * V_30 , T_16 * V_56 )
{
F_103 () ;
F_107 ( V_41 ) ;
F_110 ( V_41 , V_55 , V_48 , V_30 , V_56 ) ;
F_108 ( V_41 ) ;
F_105 () ;
}
void
F_112 ( T_13 * V_41 )
{
F_87 ( V_41 ) ;
F_92 ( V_41 -> V_44 . V_50 ) ;
F_92 ( V_41 -> V_44 . V_51 ) ;
F_93 ( & V_41 -> V_44 ) ;
if ( V_41 -> V_48 ) {
F_94 ( V_41 -> V_48 ) ;
}
if ( V_41 -> V_47 ) {
F_113 ( V_41 -> V_47 ) ;
}
if ( V_28 == NULL ) {
F_96 ( V_41 -> V_44 . V_45 ) ;
V_28 = V_41 -> V_44 . V_45 ;
}
else {
F_66 ( V_41 -> V_44 . V_45 ) ;
}
}
void
F_114 ( T_13 * V_41 )
{
F_112 ( V_41 ) ;
F_115 ( V_41 ) ;
}
void
F_116 ( T_13 * V_41 , const T_17 * V_57 )
{
F_117 ( V_57 , V_41 -> V_47 ) ;
}
void
F_118 ( T_13 * V_41 , int V_58 )
{
F_119 ( V_41 -> V_47 , V_58 ) ;
}
void
F_120 ( T_13 * V_41 , T_18 * V_59 )
{
T_19 V_60 ;
for ( V_60 = 0 ; V_60 < V_59 -> V_61 ; V_60 ++ ) {
F_119 ( V_41 -> V_47 ,
F_121 ( V_59 , int , V_60 ) ) ;
}
}
const T_1 *
F_122 ( T_13 * V_41 , T_20 * V_62 ,
T_21 V_63 ,
T_1 * V_64 ,
T_1 * V_65 , const int V_66 )
{
return F_123 ( V_41 -> V_47 , V_62 , V_63 , V_64 , V_65 , V_66 ) ;
}
void
F_124 ( T_13 * V_41 , const T_5 V_67 , const T_5 V_68 )
{
F_125 ( V_41 , V_41 -> V_44 . V_56 ) ;
F_126 ( & V_41 -> V_44 , V_67 , V_68 ) ;
}
T_5
F_127 ( T_13 * V_41 ,
const char * V_69 )
{
T_22 * V_70 ;
int V_71 ;
T_5 V_72 ;
if ( ! V_41 || ! V_41 -> V_47 )
return FALSE ;
V_71 = F_128 ( V_69 ) ;
if ( V_71 < 0 )
return FALSE ;
V_70 = F_129 ( V_41 -> V_47 , V_71 ) ;
V_72 = ( V_70 -> V_61 > 0 ) ? TRUE : FALSE ;
F_130 ( V_70 , TRUE ) ;
return V_72 ;
}
void
F_131 ( T_23 * V_73 )
{
F_132 ( V_73 , L_5 ) ;
#ifdef F_133
F_132 ( V_73 , L_6 V_74 ) ;
#else
F_132 ( V_73 , L_7 ) ;
#endif
F_132 ( V_73 , L_5 ) ;
#ifdef F_134
F_132 ( V_73 , L_8 V_75 ) ;
#else
F_132 ( V_73 , L_9 ) ;
#endif
F_132 ( V_73 , L_5 ) ;
#ifdef F_38
F_132 ( V_73 , L_10 ) ;
F_132 ( V_73 , V_76 ) ;
#else
F_132 ( V_73 , L_11 ) ;
#endif
F_132 ( V_73 , L_5 ) ;
#ifdef F_19
F_132 ( V_73 , L_12 V_77 ) ;
#else
F_132 ( V_73 , L_13 ) ;
#endif
F_132 ( V_73 , L_5 ) ;
F_132 ( V_73 , L_14 V_78 ) ;
F_132 ( V_73 , L_5 ) ;
#ifdef F_135
#ifdef F_136
F_132 ( V_73 , L_15 ) ;
#else
F_132 ( V_73 , L_16 ) ;
#endif
#else
F_132 ( V_73 , L_17 ) ;
#endif
F_132 ( V_73 , L_5 ) ;
#ifdef F_137
F_132 ( V_73 , L_18 ) ;
#else
F_132 ( V_73 , L_19 ) ;
#endif
F_132 ( V_73 , L_5 ) ;
#ifdef F_138
F_132 ( V_73 , L_20 V_79 ) ;
#else
F_132 ( V_73 , L_21 ) ;
#endif
F_132 ( V_73 , L_5 ) ;
#ifdef F_139
F_132 ( V_73 , L_22 ) ;
#else
F_132 ( V_73 , L_23 ) ;
#endif
F_132 ( V_73 , L_5 ) ;
#ifdef F_140
F_132 ( V_73 , L_24 ) ;
#else
F_132 ( V_73 , L_25 ) ;
#endif
F_132 ( V_73 , L_5 ) ;
#ifdef F_21
F_132 ( V_73 , L_26 V_80 ) ;
#else
F_132 ( V_73 , L_27 ) ;
#endif
}
void
F_141 ( T_23 * V_73 )
{
#ifdef F_19
F_142 ( V_73 , L_28 , F_143 ( NULL ) ) ;
#endif
F_142 ( V_73 , L_29 , F_15 ( NULL ) ) ;
}
