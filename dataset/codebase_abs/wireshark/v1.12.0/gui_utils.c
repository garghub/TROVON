static void
F_1 ( T_1 * V_1 ,
T_2 T_3 V_2 )
{
#ifndef F_2
T_4 * V_3 = NULL ;
T_5 * V_4 ;
V_4 = F_3 ( - 1 , V_5 , FALSE , NULL ) ;
V_3 = F_4 ( V_3 , V_4 ) ;
V_4 = F_3 ( - 1 , V_6 , FALSE , NULL ) ;
V_3 = F_4 ( V_3 , V_4 ) ;
V_4 = F_3 ( - 1 , V_7 , FALSE , NULL ) ;
V_3 = F_4 ( V_3 , V_4 ) ;
V_4 = F_3 ( - 1 , V_8 , FALSE , NULL ) ;
V_3 = F_4 ( V_3 , V_4 ) ;
F_5 ( F_6 ( V_1 ) , V_3 ) ;
F_7 ( V_3 , ( V_9 ) V_10 , NULL ) ;
F_8 ( V_3 ) ;
F_9 ( F_6 ( V_1 ) , L_1 ) ;
#endif
}
T_1 *
F_10 ( T_6 type ,
const T_7 * V_11 )
{
T_1 * V_1 ;
V_1 = F_11 ( type ) ;
if ( V_11 != NULL )
F_12 ( F_6 ( V_1 ) , V_11 ) ;
F_13 ( V_1 , L_2 , F_14 ( F_1 ) , NULL ) ;
F_15 ( F_6 ( V_1 ) , V_12 ) ;
if ( V_13 ) {
T_8 * V_14 ;
T_9 V_15 , V_16 , V_17 ;
V_14 = F_16 () ;
V_17 = F_17 ( V_14 ) ;
if ( V_17 > 1 ) {
F_18 ( F_6 ( V_13 ) , & V_15 , & V_16 ) ;
V_17 = F_19 ( V_14 , V_15 , V_16 ) ;
if ( V_17 > 0 )
F_20 ( F_6 ( V_1 ) , V_15 + 40 , V_16 + 30 ) ;
}
}
return V_1 ;
}
T_1 *
F_21 ( T_6 type ,
const T_7 * V_11 ,
const T_7 * V_18 )
{
T_10 V_19 ;
T_1 * V_1 = F_10 ( type , V_11 ) ;
F_22 ( F_23 ( V_1 ) , V_20 , ( T_2 ) F_24 ( V_18 ) ) ;
if( V_18 ) {
if( F_25 ( V_18 , & V_19 ) ) {
V_19 . V_21 = TRUE ;
V_19 . V_22 = TRUE ;
V_19 . V_23 = FALSE ;
F_26 ( V_1 , & V_19 ) ;
}
}
return V_1 ;
}
T_1 *
F_27 ( void )
{
T_1 * V_1 ;
V_1 = F_10 ( V_24 , L_3 ) ;
F_28 ( F_6 ( V_1 ) , FALSE ) ;
F_15 ( F_6 ( V_1 ) , V_25 ) ;
return V_1 ;
}
void
F_29 ( T_1 * V_1 )
{
T_10 V_19 ;
const T_7 * V_26 ;
F_30 ( F_6 ( V_1 ) ) ;
V_26 = ( const T_7 * ) F_31 ( F_23 ( V_1 ) , V_20 ) ;
if( V_26 ) {
if( F_25 ( V_26 , & V_19 ) ) {
V_19 . V_21 = TRUE ;
V_19 . V_22 = TRUE ;
V_19 . V_23 = TRUE ;
F_26 ( V_1 , & V_19 ) ;
}
}
}
static T_11
F_32 ( T_1 * V_27 ,
T_12 * V_28 ,
T_2 V_29 )
{
F_33 ( V_27 != NULL , FALSE ) ;
F_33 ( V_28 != NULL , FALSE ) ;
if ( V_28 -> V_30 == V_31 ) {
F_34 ( F_35 ( V_29 ) ) ;
return TRUE ;
}
return FALSE ;
}
static void
F_36 ( T_1 * V_27 ,
T_1 * V_29 )
{
F_13 ( V_27 , L_4 , F_14 ( F_32 ) , V_29 ) ;
}
void
F_37 ( T_1 * V_1 ,
T_1 * V_32 ,
T_13 V_33 )
{
if( V_33 )
F_13 ( V_32 , L_5 , F_14 ( V_33 ) , V_1 ) ;
F_38 ( V_32 ) ;
F_36 ( V_1 , V_32 ) ;
}
void
F_39 ( T_1 * T_14 V_2 ,
T_2 T_3 )
{
F_40 ( F_35 ( T_3 ) ) ;
}
T_11
F_41 ( T_1 * V_1 ,
T_15 * V_28 V_2 ,
T_2 T_16 V_2 )
{
F_40 ( V_1 ) ;
return TRUE ;
}
void
F_42 ( T_1 * V_27 ,
T_10 * V_19 )
{
T_17 V_34 ;
T_18 * V_35 ;
memset ( V_19 , 0 , sizeof( T_10 ) ) ;
V_35 = F_43 ( V_27 ) ;
F_44 ( V_35 ,
& V_19 -> V_15 ,
& V_19 -> V_16 ) ;
#if F_45 ( 2 , 24 , 0 )
V_19 -> V_36 = F_46 ( V_35 ) ;
V_19 -> V_37 = F_47 ( V_35 ) ;
#else
F_48 ( V_35 ,
& V_19 -> V_36 ,
& V_19 -> V_37 ) ;
#endif
V_34 = F_49 ( V_35 ) ;
V_19 -> V_38 = ( ( V_34 & V_39 ) != 0 ) ;
}
static void
F_50 ( T_10 * V_19 )
{
T_19 V_40 ;
T_20 V_41 ;
T_21 V_42 , V_43 ;
T_22 V_44 = V_45 ;
V_43 . V_15 = F_51 ( V_46 ) ;
V_43 . V_16 = F_51 ( V_47 ) ;
V_42 . V_15 = V_19 -> V_15 + V_43 . V_15 ;
V_42 . V_16 = V_19 -> V_16 + V_43 . V_16 ;
V_40 . V_48 = sizeof( T_19 ) ;
V_41 = F_52 ( V_42 , V_44 ) ;
if ( F_53 ( V_41 , & V_40 ) ) {
if ( V_42 . V_15 < V_40 . V_49 . V_50 )
V_19 -> V_15 += V_40 . V_49 . V_50 - V_42 . V_15 ;
if ( V_42 . V_16 < V_40 . V_49 . V_51 )
V_19 -> V_16 += V_40 . V_49 . V_51 - V_42 . V_16 ;
}
}
void
F_26 ( T_1 * V_27 ,
T_10 * V_19 )
{
T_8 * V_14 ;
T_23 V_52 ;
T_9 V_53 ;
if ( V_19 -> V_21 && V_19 -> V_15 != - 32000 && V_19 -> V_16 != - 32000 ) {
V_14 = F_16 () ;
V_53 = F_19 ( V_14 ,
V_19 -> V_15 , V_19 -> V_16 ) ;
F_54 ( V_14 , V_53 ,
& V_52 ) ;
if( V_19 -> V_15 < V_52 . V_15 || V_19 -> V_15 > ( V_52 . V_15 + V_52 . V_36 ) )
V_19 -> V_15 = V_52 . V_15 ;
if( V_19 -> V_16 < V_52 . V_16 || V_19 -> V_16 > ( V_52 . V_16 + V_52 . V_37 ) )
V_19 -> V_16 = V_52 . V_16 ;
#ifdef F_2
F_50 ( V_19 ) ;
#endif
F_20 ( F_6 ( V_27 ) ,
V_19 -> V_15 ,
V_19 -> V_16 ) ;
}
if ( V_19 -> V_22 ) {
F_55 ( F_6 ( V_27 ) ,
V_19 -> V_36 ,
V_19 -> V_37 ) ;
}
if( V_19 -> V_23 ) {
if ( V_19 -> V_38 ) {
F_56 ( F_43 ( V_27 ) ) ;
} else {
F_57 ( F_43 ( V_27 ) ) ;
}
}
}
void
F_40 ( T_1 * V_1 )
{
T_10 V_19 ;
const T_7 * V_26 ;
if ( ! V_1 )
return;
if( F_58 ( V_1 ) && F_59 ( V_1 ) ) {
F_42 ( V_1 , & V_19 ) ;
V_26 = ( const T_7 * ) F_31 ( F_23 ( V_1 ) , V_20 ) ;
if( V_26 ) {
F_60 ( V_26 , & V_19 ) ;
F_61 ( ( T_2 ) V_26 ) ;
}
}
F_62 ( V_1 ) ;
}
static T_1 *
F_63 ( T_5 * V_54 ) {
T_1 * V_27 ;
V_27 = F_64 ( V_54 ) ;
V_10 ( V_54 ) ;
return V_27 ;
}
T_1 *
F_65 ( const char * * V_55 ) {
T_5 * V_54 ;
V_54 = F_66 ( V_55 ) ;
return F_63 ( V_54 ) ;
}
T_1 *
F_67 ( const T_24 * V_56 ) {
T_5 * V_54 ;
V_54 = F_3 ( - 1 , V_56 , FALSE , NULL ) ;
return F_63 ( V_54 ) ;
}
void
F_68 ( T_1 * V_57 ,
const char * V_58 )
{
T_1 * V_59 ;
V_59 = F_69 ( F_6 ( V_57 ) ,
V_60 ,
V_61 ,
V_62 ,
L_6 ,
V_58 , V_63 ) ;
F_70 ( F_71 ( V_59 ) ,
L_7 ) ;
F_72 ( F_73 ( V_59 ) ) ;
F_62 ( V_59 ) ;
}
void
F_74 ( void )
{
while ( F_75 () )
F_76 () ;
}
void
F_77 ( void )
{
if ( F_78 () > 0 )
F_79 () ;
}
void
F_80 ( void )
{
F_79 () ;
}
static T_11
F_81 ( T_2 T_3 )
{
T_25 V_64 ;
T_22 V_65 = 0 ;
T_11 V_66 ;
T_22 V_67 ;
T_26 * V_68 = T_3 ;
T_9 V_69 = 0 ;
while( V_69 < 5 ) {
V_64 = ( T_25 ) F_82 ( V_68 -> V_70 ) ;
V_66 = F_83 ( V_64 , NULL , 0 , NULL , & V_65 , NULL ) ;
F_84 ( ( T_25 ) * ( V_68 -> V_71 ) , & V_67 ) ;
if ( ! V_66 || V_65 > 0 || V_67 != V_72 ) {
if( V_68 -> V_73 != 0 ) {
F_85 ( V_68 -> V_73 ) ;
V_68 -> V_73 = 0 ;
}
if ( ! V_68 -> V_74 ( V_68 -> V_70 , V_68 -> T_16 ) ) {
F_86 ( NULL , V_75 , L_8 , V_69 ) ;
return FALSE ;
}
}
else {
break;
}
V_69 ++ ;
}
if( V_68 -> V_73 == 0 ) {
V_68 -> V_73 = F_87 ( 200 , F_81 , T_3 ) ;
return FALSE ;
} else {
return TRUE ;
}
}
static T_11
F_88 ( T_27 * V_70 V_2 ,
T_28 T_29 V_2 ,
T_2 T_3 )
{
T_26 * V_68 = ( T_26 * ) T_3 ;
F_85 ( V_68 -> V_73 ) ;
if ( V_68 -> V_74 ( V_68 -> V_70 , V_68 -> T_16 ) ) {
V_68 -> V_73 = F_89 ( V_68 -> V_76 ,
V_77 ,
( T_28 ) ( V_78 | V_79 | V_80 ) ,
F_88 ,
V_68 ,
NULL ) ;
}
return TRUE ;
}
void
F_90 ( T_9 V_70 ,
T_2 T_16 ,
int * V_71 ,
T_30 V_74 )
{
static T_26 V_68 ;
V_68 . V_70 = V_70 ;
V_68 . V_71 = V_71 ;
V_68 . T_16 = T_16 ;
V_68 . V_74 = V_74 ;
#ifdef F_2
V_68 . V_73 = F_87 ( 200 , F_81 , & V_68 ) ;
#else
V_68 . V_76 = F_91 ( V_70 ) ;
F_92 ( V_68 . V_76 , NULL , NULL ) ;
V_68 . V_73 = F_89 ( V_68 . V_76 ,
V_77 ,
( T_28 ) ( V_78 | V_79 | V_80 ) ,
F_88 ,
& V_68 ,
NULL ) ;
#endif
}
void
F_93 ( T_1 * V_1 )
{
T_18 * V_81 ;
V_81 = F_43 ( V_1 ) ;
F_94 ( V_81 ) ;
F_95 ( V_81 ) ;
}
T_1 *
F_96 ( T_31 * V_82 ,
T_31 * V_83 )
{
T_1 * V_84 ;
V_84 = F_97 ( V_82 , V_83 ) ;
F_98 ( V_84 ) ;
return V_84 ;
}
static void
F_98 ( T_1 * V_84 )
{
F_99 ( F_100 ( V_84 ) ,
V_85 , V_85 ) ;
V_86 = F_4 ( V_86 , V_84 ) ;
F_13 ( V_84 , L_9 , F_14 ( V_87 ) , NULL ) ;
}
static void
V_87 ( T_1 * V_84 ,
T_2 T_3 V_2 )
{
V_86 = F_101 ( V_86 , V_84 ) ;
}
T_1 *
F_102 ( T_32 * V_88 )
{
T_1 * V_89 ;
V_89 = F_103 ( V_88 ) ;
F_104 ( V_89 ) ;
return V_89 ;
}
static void
F_104 ( T_1 * V_89 )
{
F_105 ( V_89 ) ;
V_90 = F_4 ( V_90 , V_89 ) ;
F_13 ( V_89 , L_9 , F_14 ( V_91 ) , NULL ) ;
F_13 ( V_89 , L_10 , F_14 ( V_92 ) , NULL ) ;
}
static void
V_91 ( T_1 * V_89 ,
T_2 T_3 V_2 )
{
V_90 = F_101 ( V_90 , V_89 ) ;
}
static void
F_105 ( T_1 * V_89 )
{
F_106 ( V_93 . V_94 >= 0 && V_93 . V_94 <= 1 ) ;
F_107 ( F_108 ( V_89 ) ,
V_93 . V_94 ) ;
}
static void
F_109 ( T_2 T_3 ,
T_2 T_16 V_2 )
{
F_105 ( ( T_1 * ) T_3 ) ;
}
void
F_110 ( void )
{
F_7 ( V_90 , F_109 , NULL ) ;
}
T_11
F_111 ( T_33 * V_89 ,
T_11 V_95 )
{
T_34 V_96 , V_97 ;
T_32 * V_88 ;
T_35 * V_98 ;
T_36 * V_99 , * V_100 ;
V_98 = F_112 ( V_89 ) ;
if ( ! F_113 ( V_98 , & V_88 , & V_96 ) ) {
return FALSE ;
}
V_99 = F_114 ( V_88 , & V_96 ) ;
if ( ! V_99 ) {
return FALSE ;
}
V_100 = F_115 ( V_99 ) ;
if ( V_95 ) {
F_116 ( V_100 ) ;
} else {
F_117 ( V_100 ) ;
}
if ( F_118 ( V_99 , V_100 ) == 0 ) {
F_119 ( V_99 ) ;
F_119 ( V_100 ) ;
return FALSE ;
}
F_120 ( V_88 , & V_97 , V_100 ) ;
F_121 ( F_122 ( V_88 ) , & V_96 , & V_97 ) ;
F_119 ( V_99 ) ;
F_119 ( V_100 ) ;
return TRUE ;
}
T_9
F_123 ( T_33 * V_89 ) {
T_34 V_101 ;
T_32 * V_88 ;
T_35 * V_98 ;
T_36 * V_102 ;
T_7 * V_103 ;
T_9 V_104 ;
V_98 = F_112 ( V_89 ) ;
if ( ! F_113 ( V_98 , & V_88 , & V_101 ) ) {
return - 1 ;
}
V_102 = F_114 ( V_88 , & V_101 ) ;
if ( ! V_102 ) {
return FALSE ;
}
V_103 = F_124 ( V_102 ) ;
F_119 ( V_102 ) ;
V_104 = ( T_9 ) strtol ( V_103 , NULL , 10 ) ;
F_61 ( V_103 ) ;
return V_104 ;
}
void
F_125 ( T_1 * V_105 ,
... )
{
T_37 V_106 ;
T_34 V_101 ;
T_38 * V_107 ;
va_start ( V_106 , V_105 ) ;
V_107 = F_122 ( F_126 ( F_108 ( V_105 ) ) ) ;
F_127 ( V_107 , & V_101 ) ;
F_128 ( V_107 , & V_101 , V_106 ) ;
va_end ( V_106 ) ;
}
T_1 *
F_129 ( T_9 V_108 ,
const T_7 * * V_109 ) {
T_1 * V_110 ;
int V_111 ;
T_38 * V_107 ;
T_39 * V_112 ;
T_40 * V_113 ;
F_106 ( V_108 <= 10 ) ;
V_107 = F_130 ( V_108 ,
V_114 , V_114 , V_114 , V_114 , V_114 ,
V_114 , V_114 , V_114 , V_114 , V_114 ) ;
V_110 = F_102 ( F_131 ( V_107 ) ) ;
V_10 ( F_23 ( V_107 ) ) ;
F_132 ( F_108 ( V_110 ) , ( V_109 != NULL ) ) ;
for( V_111 = 0 ; V_111 < V_108 ; V_111 ++ ) {
V_112 = F_133 () ;
V_113 = F_134 ( V_109 ? V_109 [ V_111 ] : L_11 , V_112 ,
L_12 , V_111 , NULL ) ;
F_135 ( V_113 , V_111 ) ;
F_136 ( F_108 ( V_110 ) , V_113 ) ;
}
return V_110 ;
}
void
F_137 ( T_39 * V_115 )
{
F_138 ( V_115 , L_13 , L_14 , NULL ) ;
F_138 ( V_115 , L_15 , TRUE , NULL ) ;
F_138 ( V_115 , L_16 , V_116 , NULL ) ;
F_138 ( V_115 , L_17 , TRUE , NULL ) ;
}
void
F_139 ( T_1 * V_105 ,
T_9 V_117 )
{
T_40 * V_118 ;
T_4 * V_119 ;
T_39 * V_120 ;
V_118 = F_140 ( F_108 ( V_105 ) , V_117 ) ;
V_119 = F_141 ( F_142 ( V_118 ) ) ;
if( V_119 != NULL ) {
V_120 = ( T_39 * ) V_119 -> T_3 ;
F_137 ( V_120 ) ;
F_8 ( V_119 ) ;
}
}
void
F_143 ( T_41 * V_121 )
{
T_42 * V_33 ;
V_33 = F_144 ( V_122 ) ;
F_145 ( V_33 , V_121 -> V_121 , - 1 ) ;
}
static T_43 *
F_146 ( const T_24 * T_3 ,
int V_123 )
{
T_43 * V_124 ;
F_106 ( V_123 > 0 ) ;
V_124 = F_147 ( T_43 , 1 ) ;
V_124 -> T_3 = F_147 ( T_24 , V_123 ) ;
V_124 -> V_123 = V_123 ;
memcpy ( V_124 -> T_3 , T_3 , V_123 * sizeof( T_24 ) ) ;
return V_124 ;
}
static void
F_148 ( T_43 * V_124 ) {
F_61 ( V_124 -> T_3 ) ;
F_61 ( V_124 ) ;
}
static void
F_149 ( T_42 * T_44 V_2 ,
T_2 V_125 )
{
F_148 ( ( T_43 * ) V_125 ) ;
}
static void
F_150 ( T_42 * T_44 V_2 ,
T_45 * V_126 ,
T_46 T_47 V_2 ,
T_2 V_125 )
{
T_43 * V_124 ;
V_124 = ( T_43 * ) V_125 ;
F_151 ( V_126 , V_127 , 8 , V_124 -> T_3 , V_124 -> V_123 ) ;
}
void
F_152 ( const T_24 * V_128 ,
int V_123 )
{
static T_48 V_129 [] = {
{ ( char * ) L_18 , 0 , 0 } } ;
T_42 * V_33 ;
T_43 * V_124 ;
T_11 V_130 ;
if( V_123 <= 0 ) {
return;
}
V_33 = F_144 ( V_122 ) ;
V_124 = F_146 ( V_128 , V_123 ) ;
V_130 = F_153 ( V_33 , V_129 , 1 ,
F_150 , F_149 , V_124 ) ;
if( ! V_130 ) {
F_148 ( V_124 ) ;
}
}
T_7 *
F_154 ( const T_7 * V_131 )
{
if ( V_131 == NULL )
return F_24 ( L_11 ) ;
if ( ( V_93 . V_132 == NULL ) || ( * V_93 . V_132 == '\0' ) )
return F_24 ( V_131 ) ;
return F_155 ( L_19 , V_131 , V_93 . V_132 ) ;
}
void
F_156 ( T_1 * V_1 ,
const T_7 * V_131 )
{
char * V_11 ;
char * V_133 ;
V_133 = F_157 ( & V_134 ) ;
V_11 = F_155 ( L_20 , V_131 , V_133 ) ;
F_61 ( V_133 ) ;
F_12 ( F_6 ( V_1 ) , V_11 ) ;
F_61 ( V_11 ) ;
}
static void
F_158 ( T_33 * V_135 , T_32 * V_88 , T_36 * V_102 ,
T_34 * V_101 )
{
T_34 V_136 ;
if ( F_159 ( V_135 , V_102 ) ) {
if ( F_160 ( V_88 , & V_136 , V_101 ) ) {
F_161 ( V_102 ) ;
do {
if ( F_159 ( V_135 , V_102 ) ) {
F_158 ( V_135 , V_88 , V_102 , & V_136 ) ;
}
F_117 ( V_102 ) ;
} while ( F_162 ( V_88 , & V_136 ) );
F_163 ( V_102 ) ;
F_164 ( V_135 , V_102 ) ;
}
}
}
void
F_165 ( T_33 * V_135 , T_36 * V_102 )
{
T_34 V_101 ;
T_32 * V_88 ;
V_88 = F_126 ( V_135 ) ;
F_120 ( V_88 , & V_101 , V_102 ) ;
F_158 ( V_135 , V_88 , V_102 , & V_101 ) ;
}
static T_11
V_92 ( T_1 * V_89 ,
T_12 * V_28 ,
T_2 T_16 V_2 )
{
T_35 * V_137 ;
T_34 V_101 ;
T_34 V_57 ;
T_32 * V_88 ;
T_36 * V_102 ;
T_11 V_138 , V_139 ;
int V_140 = FALSE ;
V_137 = F_112 ( F_108 ( V_89 ) ) ;
if( ! V_137 ) {
return FALSE ;
}
if( ! F_113 ( V_137 , & V_88 , & V_101 ) ) {
return FALSE ;
}
V_102 = F_114 ( V_88 , & V_101 ) ;
if( ! V_102 ) {
return FALSE ;
}
V_138 = F_159 ( F_108 ( V_89 ) , V_102 ) ;
V_139 = F_166 ( V_88 , & V_101 ) ;
switch ( V_28 -> V_30 ) {
case V_141 :
if( V_138 ) {
if ( V_28 -> V_34 & V_142 )
{
F_158 ( F_108 ( V_89 ) , V_88 , V_102 , & V_101 ) ;
}
else
F_164 ( F_108 ( V_89 ) , V_102 ) ;
V_140 = TRUE ;
break;
}
case V_143 :
if ( ! V_138 ) {
if( ! F_167 ( V_88 , & V_57 , & V_101 ) ) {
V_140 = FALSE ;
break;
}
F_119 ( V_102 ) ;
V_102 = F_114 ( V_88 , & V_57 ) ;
if( ! V_102 ) {
return FALSE ;
}
F_168 ( F_108 ( V_89 ) , V_102 ,
NULL ,
FALSE ) ;
V_140 = TRUE ;
break;
}
break;
case V_144 :
if ( V_139 ) {
F_169 ( F_108 ( V_89 ) , V_102 , FALSE ) ;
V_140 = TRUE ;
break;
} else {
V_140 = FALSE ;
break;
}
case V_145 :
case V_146 :
if ( V_138 )
F_164 ( F_108 ( V_89 ) , V_102 ) ;
else
F_169 ( F_108 ( V_89 ) , V_102 , FALSE ) ;
V_140 = TRUE ;
break;
}
if( V_102 ) {
F_119 ( V_102 ) ;
}
return V_140 ;
}
void
F_170 ( T_33 * V_147 )
{
T_9 V_148 ;
T_40 * V_113 ;
T_4 * V_149 , * V_105 ;
V_149 = F_171 ( F_108 ( V_147 ) ) ;
V_105 = V_149 ;
while( V_149 ) {
V_113 = ( T_40 * ) V_149 -> T_3 ;
V_148 = F_172 ( V_113 ) ;
F_173 ( V_113 , V_150 ) ;
if ( V_148 > F_174 ( V_113 ) )
F_175 ( V_113 , V_148 ) ;
V_149 = F_176 ( V_149 ) ;
}
F_8 ( V_105 ) ;
F_177 ( V_147 , TRUE ) ;
}
T_9
F_178 ( T_1 * V_147 ,
const T_7 * V_121 )
{
T_49 * V_151 ;
T_9 V_152 ;
V_151 = F_179 ( V_147 , V_121 ) ;
F_180 ( V_151 ,
& V_152 ,
NULL ) ;
V_10 ( F_23 ( V_151 ) ) ;
return V_152 + ( F_181 ( F_182 () ) / V_153 ) ;
}
void
F_183 ( T_40 * V_113 V_2 ,
T_39 * V_112 ,
T_32 * V_88 ,
T_34 * V_101 ,
T_2 T_16 )
{
T_50 V_154 ;
T_7 V_155 [ 20 ] ;
char * V_156 ;
T_9 V_157 = F_184 ( T_16 ) ;
F_185 ( V_88 , V_101 , V_157 , & V_154 , - 1 ) ;
V_156 = F_24 ( setlocale ( V_158 , NULL ) ) ;
setlocale ( V_158 , L_21 ) ;
F_186 ( V_155 , sizeof( V_155 ) , L_22 , V_154 ) ;
setlocale ( V_158 , V_156 ) ;
F_61 ( V_156 ) ;
F_138 ( V_112 , L_12 , V_155 , NULL ) ;
}
void
F_187 ( T_40 * V_113 V_2 ,
T_39 * V_112 ,
T_32 * V_88 ,
T_34 * V_101 ,
T_2 T_16 )
{
T_46 V_159 ;
T_7 V_155 [ 35 ] ;
T_9 V_117 = F_184 ( T_16 ) ;
F_185 ( V_88 , V_101 , V_117 , & V_159 , - 1 ) ;
F_186 ( V_155 , sizeof( V_155 ) , L_23 , V_159 ) ;
F_138 ( V_112 , L_12 , V_155 , NULL ) ;
}
void
F_188 ( T_40 * V_113 V_2 ,
T_39 * V_112 ,
T_32 * V_88 ,
T_34 * V_101 ,
T_2 T_16 )
{
T_51 V_159 ;
int V_111 = 0 ;
T_7 * V_160 ;
T_7 V_155 [ 35 ] ;
T_9 V_117 = F_184 ( T_16 ) ;
F_185 ( V_88 , V_101 , V_117 , & V_159 , - 1 ) ;
V_160 = & V_155 [ 34 ] ;
* V_160 = 0 ;
do {
* -- V_160 = ( T_7 ) ( V_159 % 10 ) + '0' ;
if ( ! ( ++ V_111 % 3 ) ) {
* -- V_160 = ' ' ;
}
} while ( ( V_159 /= 10 ) != 0 && V_160 > V_155 );
F_138 ( V_112 , L_12 , V_160 , NULL ) ;
}
void
F_189 ( T_40 * V_113 V_2 ,
T_39 * V_112 ,
T_32 * V_88 ,
T_34 * V_101 ,
T_2 T_16 )
{
const T_7 * V_121 = NULL ;
T_9 V_161 = F_184 ( T_16 ) ;
F_185 ( V_88 , V_101 , V_161 , & V_121 , - 1 ) ;
F_138 ( V_112 , L_12 , V_121 , NULL ) ;
}
T_9
F_190 ( T_32 * V_88 ,
T_34 * V_162 ,
T_34 * V_163 ,
T_2 T_16 )
{
const T_7 * V_164 = NULL ;
const T_7 * V_165 = NULL ;
T_9 V_130 = 0 ;
T_9 V_161 = F_184 ( T_16 ) ;
F_185 ( V_88 , V_162 , V_161 , & V_164 , - 1 ) ;
F_185 ( V_88 , V_163 , V_161 , & V_165 , - 1 ) ;
if ( V_164 == V_165 ) {
return 0 ;
}
else if ( V_164 == NULL || V_165 == NULL ) {
V_130 = ( V_164 == NULL ) ? - 1 : 1 ;
}
else {
V_130 = F_191 ( V_164 , V_165 ) ;
}
return V_130 ;
}
T_1 *
F_192 ( T_39 * * V_166 ) {
T_1 * V_167 ;
T_39 * V_115 ;
T_52 * V_107 ;
V_107 = F_193 ( 3 , V_114 , V_168 , V_169 ) ;
V_167 = F_194 ( F_131 ( V_107 ) ) ;
V_10 ( V_107 ) ;
V_115 = F_133 () ;
F_195 ( F_142 ( V_167 ) , V_115 , TRUE ) ;
F_196 ( F_142 ( V_167 ) , V_115 ,
L_12 , 0 , L_24 , 2 ,
NULL ) ;
if ( V_166 != NULL ) {
* V_166 = V_115 ;
}
return V_167 ;
}
T_1 *
F_197 ( void ) {
return F_192 ( NULL ) ;
}
void
F_198 ( T_53 * V_167 )
{
F_199 ( F_200 ( F_201 ( V_167 ) ) ) ;
}
T_34
F_202 ( T_53 * V_167 ,
T_34 * V_170 ,
const T_7 * V_171 ,
const T_2 V_172 ,
const T_11 V_173 )
{
T_34 V_101 ;
T_52 * V_107 ;
V_107 = F_200 ( F_201 ( V_167 ) ) ;
F_203 ( V_107 , & V_101 , V_170 ) ;
F_204 ( V_107 , & V_101 , 0 , V_171 , 1 , V_172 , 2 , V_173 , - 1 ) ;
return V_101 ;
}
T_34
F_205 ( T_53 * V_167 ,
const T_7 * V_171 ,
const T_2 V_172 )
{
return F_202 ( V_167 , NULL , V_171 , V_172 , TRUE ) ;
}
T_11
F_206 ( T_53 * V_167 ,
T_2 * V_172 )
{
T_52 * V_107 ;
T_34 V_101 ;
* V_172 = NULL ;
if ( F_207 ( V_167 , & V_101 ) ) {
V_107 = F_200 ( F_201 ( V_167 ) ) ;
F_185 ( F_131 ( V_107 ) , & V_101 ,
1 , V_172 , - 1 ) ;
return TRUE ;
}
return FALSE ;
}
T_9
F_208 ( T_53 * V_167 )
{
return F_209 ( V_167 ) ;
}
void
F_210 ( T_53 * V_167 ,
T_9 V_174 )
{
F_211 ( V_167 , V_174 ) ;
}
void
F_212 ( T_53 * V_167 , T_34 * V_101 )
{
F_213 ( V_167 , V_101 ) ;
}
static T_54
F_214 ( T_55 V_175 )
{
switch ( V_175 )
{
case V_176 :
return V_177 ;
case V_178 :
return V_179 ;
case V_180 :
default:
return V_181 ;
}
}
static T_56 *
F_215 ( T_56 * V_182 ,
T_55 V_175 ,
int V_183 ,
int V_184 ,
int V_36 ,
int V_37 )
{
T_56 * V_185 ;
T_57 * V_186 ;
V_185 = F_216 ( F_214 ( V_175 ) ,
V_36 ,
V_37 ) ;
V_186 = F_217 ( V_185 ) ;
F_218 ( V_186 , V_187 ) ;
F_219 ( V_186 , V_182 , - V_183 , - V_184 ) ;
F_220 ( V_186 ) ;
F_221 ( V_186 ) ;
return V_185 ;
}
static void
F_222 ( T_58 * V_188 ,
int V_189 ,
T_58 * V_190 ,
int V_191 ,
int V_183 ,
int V_184 ,
int V_36 ,
int V_37 )
{
int V_15 , V_16 ;
V_190 += V_191 * V_184 + V_183 * 4 ;
for ( V_16 = 0 ; V_16 < V_37 ; V_16 ++ ) {
T_59 * V_192 = ( T_59 * ) V_190 ;
for ( V_15 = 0 ; V_15 < V_36 ; V_15 ++ ) {
T_46 V_193 = V_192 [ V_15 ] >> 24 ;
if ( V_193 == 0 )
{
V_188 [ V_15 * 4 + 0 ] = 0 ;
V_188 [ V_15 * 4 + 1 ] = 0 ;
V_188 [ V_15 * 4 + 2 ] = 0 ;
}
else
{
V_188 [ V_15 * 4 + 0 ] = ( ( ( V_192 [ V_15 ] & 0xff0000 ) >> 16 ) * 255 + V_193 / 2 ) / V_193 ;
V_188 [ V_15 * 4 + 1 ] = ( ( ( V_192 [ V_15 ] & 0x00ff00 ) >> 8 ) * 255 + V_193 / 2 ) / V_193 ;
V_188 [ V_15 * 4 + 2 ] = ( ( ( V_192 [ V_15 ] & 0x0000ff ) >> 0 ) * 255 + V_193 / 2 ) / V_193 ;
}
V_188 [ V_15 * 4 + 3 ] = V_193 ;
}
V_190 += V_191 ;
V_188 += V_189 ;
}
}
static void
F_223 ( T_58 * V_188 ,
int V_189 ,
T_58 * V_190 ,
int V_191 ,
int V_183 ,
int V_184 ,
int V_36 ,
int V_37 )
{
int V_15 , V_16 ;
V_190 += V_191 * V_184 + V_183 * 4 ;
for ( V_16 = 0 ; V_16 < V_37 ; V_16 ++ ) {
T_59 * V_192 = ( T_59 * ) V_190 ;
for ( V_15 = 0 ; V_15 < V_36 ; V_15 ++ ) {
V_188 [ V_15 * 3 + 0 ] = V_192 [ V_15 ] >> 16 ;
V_188 [ V_15 * 3 + 1 ] = V_192 [ V_15 ] >> 8 ;
V_188 [ V_15 * 3 + 2 ] = V_192 [ V_15 ] ;
}
V_190 += V_191 ;
V_188 += V_189 ;
}
}
T_5 *
F_224 ( T_56 * V_182 ,
T_9 V_183 ,
T_9 V_184 ,
T_9 V_36 ,
T_9 V_37 )
{
T_55 V_175 ;
T_5 * V_194 ;
F_33 ( V_182 != NULL , NULL ) ;
F_33 ( V_36 > 0 && V_37 > 0 , NULL ) ;
V_175 = ( T_55 ) ( F_225 ( V_182 ) | V_176 ) ;
V_194 = F_226 ( V_195 ,
! ! ( V_175 & V_178 ) ,
8 ,
V_36 , V_37 ) ;
V_182 = F_215 ( V_182 , V_175 ,
V_183 , V_184 ,
V_36 , V_37 ) ;
F_227 ( V_182 ) ;
if ( F_228 ( V_182 ) || V_194 == NULL )
{
F_229 ( V_182 ) ;
return NULL ;
}
if ( F_230 ( V_194 ) )
F_222 ( F_231 ( V_194 ) ,
F_232 ( V_194 ) ,
F_233 ( V_182 ) ,
F_234 ( V_182 ) ,
0 , 0 ,
V_36 , V_37 ) ;
else
F_223 ( F_231 ( V_194 ) ,
F_232 ( V_194 ) ,
F_233 ( V_182 ) ,
F_234 ( V_182 ) ,
0 , 0 ,
V_36 , V_37 ) ;
F_229 ( V_182 ) ;
return V_194 ;
}
T_1 *
F_235 ( T_60 V_196 ,
T_9 V_197 ,
T_11 V_198 )
{
#if ! F_45 ( 3 , 0 , 0 )
if ( V_196 == V_199 )
return F_236 ( V_198 , V_197 ) ;
else
return F_237 ( V_198 , V_197 ) ;
#else
T_1 * V_27 ;
V_27 = F_238 ( V_196 , V_197 ) ;
F_239 ( F_240 ( V_27 ) , V_198 ) ;
return V_27 ;
#endif
}
T_1 *
F_241 ( T_60 V_196 )
{
if ( V_196 == V_199 ) {
return F_242 () ;
} else {
return F_243 () ;
}
}
T_1 *
F_244 ( T_60 V_196 ,
T_31 * V_200 )
{
if ( V_196 == V_199 ) {
return F_245 ( V_200 ) ;
} else {
return F_246 ( V_200 ) ;
}
}
T_1 *
F_247 ( T_60 V_196 )
{
if( V_196 == V_199 ) {
return F_248 () ;
} else {
return F_249 () ;
}
}
T_1 *
F_250 ( T_60 V_196 )
{
if ( V_196 == V_199 ) {
return F_251 () ;
} else {
return F_252 () ;
}
}
T_1 *
F_253 ( const T_7 * V_11 ) {
T_1 * V_201 , * V_202 ;
T_41 * V_203 = F_254 ( L_11 ) ;
V_201 = F_255 ( NULL ) ;
F_256 ( F_257 ( V_201 ) , V_204 ) ;
if ( V_11 ) {
#if F_258 ( F_2 ) || F_258 ( V_205 )
F_259 ( V_203 , L_25 , V_11 ) ;
#else
F_259 ( V_203 , L_26 , V_11 ) ;
#endif
V_202 = F_260 ( NULL ) ;
F_261 ( F_262 ( V_202 ) , V_203 -> V_121 ) ;
F_263 ( F_257 ( V_201 ) , V_202 ) ;
}
F_264 ( V_203 , TRUE ) ;
return V_201 ;
}
void
F_265 ( T_61 * V_206 , T_1 * V_136 , T_9 V_50 , T_9 V_51 , T_9 V_36 , T_9 V_37 )
{
F_266 ( V_206 , V_136 , V_50 , V_51 , V_36 , V_37 ,
( V_207 ) ( V_208 | V_209 ) , ( V_207 ) ( V_208 | V_209 ) , 0 , 0 ) ;
}
void
F_266 ( T_61 * V_206 , T_1 * V_136 ,
T_9 V_50 , T_9 V_51 , T_9 V_36 , T_9 V_37 ,
V_207 V_210 , V_207 V_211 ,
T_46 V_212 , T_46 V_213 )
{
F_267 ( V_206 , V_136 , V_50 , V_51 , V_36 , V_37 ) ;
if ( V_210 & V_208 )
F_268 ( V_136 , TRUE ) ;
if ( V_211 & V_208 )
F_269 ( V_136 , TRUE ) ;
F_270 ( V_136 , ( V_210 & V_209 ) ? V_214 : V_215 ) ;
F_271 ( V_136 , ( V_211 & V_209 ) ? V_214 : V_215 ) ;
if ( V_212 != 0 ) {
F_272 ( V_136 , V_212 ) ;
F_273 ( V_136 , V_212 ) ;
}
if ( V_213 != 0 ) {
F_274 ( V_136 , V_213 ) ;
F_275 ( V_136 , V_213 ) ;
}
}
void
F_276 ( T_61 * V_206 , T_11 V_198 )
{
F_277 ( V_206 , V_198 ) ;
F_278 ( V_206 , V_198 ) ;
}
void
F_279 ( T_57 * V_186 , const T_62 * V_216 )
{
T_63 V_217 ;
F_280 ( & V_217 , V_216 ) ;
F_281 ( V_186 , & V_217 ) ;
}
