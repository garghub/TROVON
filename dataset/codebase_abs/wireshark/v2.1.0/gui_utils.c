static void
F_1 ( T_1 * V_1 ,
T_2 T_3 V_2 )
{
#ifndef F_2
T_4 * V_3 = NULL ;
T_5 * V_4 , * V_5 , * V_6 , * V_7 ;
#ifdef F_3
V_4 = F_4 ( L_1 ) ;
V_5 = F_4 ( L_2 ) ;
V_6 = F_4 ( L_3 ) ;
V_7 = F_4 ( L_4 ) ;
#else
V_4 = F_5 ( - 1 , V_8 , FALSE , NULL ) ;
V_5 = F_5 ( - 1 , V_9 , FALSE , NULL ) ;
V_6 = F_5 ( - 1 , V_10 , FALSE , NULL ) ;
V_7 = F_5 ( - 1 , V_11 , FALSE , NULL ) ;
#endif
V_3 = F_6 ( V_3 , V_4 ) ;
V_3 = F_6 ( V_3 , V_5 ) ;
V_3 = F_6 ( V_3 , V_6 ) ;
V_3 = F_6 ( V_3 , V_7 ) ;
F_7 ( F_8 ( V_1 ) , V_3 ) ;
F_9 ( V_3 , ( V_12 ) V_13 , NULL ) ;
F_10 ( V_3 ) ;
F_11 ( F_8 ( V_1 ) , L_5 ) ;
#endif
}
T_1 *
F_12 ( T_6 type ,
const T_7 * V_14 )
{
T_1 * V_1 ;
V_1 = F_13 ( type ) ;
if ( V_14 != NULL )
F_14 ( F_8 ( V_1 ) , V_14 ) ;
F_15 ( V_1 , L_6 , F_16 ( F_1 ) , NULL ) ;
F_17 ( F_8 ( V_1 ) , V_15 ) ;
if ( V_16 ) {
T_8 * V_17 ;
T_9 V_18 , V_19 , V_20 ;
V_17 = F_18 () ;
V_20 = F_19 ( V_17 ) ;
if ( V_20 > 1 ) {
F_20 ( F_8 ( V_16 ) , & V_18 , & V_19 ) ;
V_20 = F_21 ( V_17 , V_18 , V_19 ) ;
if ( V_20 > 0 )
F_22 ( F_8 ( V_1 ) , V_18 + 40 , V_19 + 30 ) ;
}
}
return V_1 ;
}
T_1 *
F_23 ( T_6 type ,
const T_7 * V_14 ,
const T_7 * V_21 ,
T_10 V_22 )
{
T_11 V_23 ;
T_1 * V_1 = F_12 ( type , V_14 ) ;
F_24 ( F_25 ( V_1 ) , V_24 , ( T_2 ) F_26 ( V_21 ) ) ;
if( V_21 ) {
if( F_27 ( V_21 , & V_23 ) ) {
V_23 . V_25 = TRUE ;
V_23 . V_26 = TRUE ;
V_23 . V_27 = FALSE ;
F_28 ( V_1 , & V_23 ) ;
} else if ( V_22 != V_15 ) {
#ifdef F_2
if ( V_22 == V_28 )
V_22 = V_29 ;
#endif
F_17 ( F_8 ( V_1 ) , V_22 ) ;
}
}
return V_1 ;
}
T_1 *
F_29 ( void )
{
T_1 * V_1 ;
V_1 = F_12 ( V_30 , L_7 ) ;
F_30 ( F_8 ( V_1 ) , FALSE ) ;
F_17 ( F_8 ( V_1 ) , V_29 ) ;
return V_1 ;
}
void
F_31 ( T_1 * V_1 )
{
T_11 V_23 ;
const T_7 * V_31 ;
F_32 ( F_8 ( V_1 ) ) ;
V_31 = ( const T_7 * ) F_33 ( F_25 ( V_1 ) , V_24 ) ;
if( V_31 ) {
if( F_27 ( V_31 , & V_23 ) ) {
V_23 . V_25 = TRUE ;
V_23 . V_26 = TRUE ;
V_23 . V_27 = TRUE ;
F_28 ( V_1 , & V_23 ) ;
}
}
}
static T_12
F_34 ( T_1 * V_32 ,
T_13 * V_33 ,
T_2 V_34 )
{
F_35 ( V_32 != NULL , FALSE ) ;
F_35 ( V_33 != NULL , FALSE ) ;
if ( V_33 -> V_35 == V_36 ) {
F_36 ( F_37 ( V_34 ) ) ;
return TRUE ;
}
return FALSE ;
}
static void
F_38 ( T_1 * V_32 ,
T_1 * V_34 )
{
F_15 ( V_32 , L_8 , F_16 ( F_34 ) , V_34 ) ;
}
void
F_39 ( T_1 * V_1 ,
T_1 * V_37 ,
T_14 V_38 )
{
if( V_38 )
F_15 ( V_37 , L_9 , F_16 ( V_38 ) , V_1 ) ;
F_40 ( V_37 ) ;
F_38 ( V_1 , V_37 ) ;
}
void
F_41 ( T_1 * T_15 V_2 ,
T_2 T_3 )
{
F_42 ( F_37 ( T_3 ) ) ;
}
T_12
F_43 ( T_1 * V_1 ,
T_16 * V_33 V_2 ,
T_2 T_17 V_2 )
{
F_42 ( V_1 ) ;
return TRUE ;
}
void
F_44 ( T_1 * V_32 ,
T_11 * V_23 )
{
T_18 V_39 ;
T_19 * V_40 ;
memset ( V_23 , 0 , sizeof( T_11 ) ) ;
V_40 = F_45 ( V_32 ) ;
F_46 ( V_40 ,
& V_23 -> V_18 ,
& V_23 -> V_19 ) ;
#if F_47 ( 2 , 24 , 0 )
V_23 -> V_41 = F_48 ( V_40 ) ;
V_23 -> V_42 = F_49 ( V_40 ) ;
#else
F_50 ( V_40 ,
& V_23 -> V_41 ,
& V_23 -> V_42 ) ;
#endif
V_39 = F_51 ( V_40 ) ;
V_23 -> V_43 = ( ( V_39 & V_44 ) != 0 ) ;
}
static void
F_52 ( T_11 * V_23 )
{
T_20 V_45 ;
T_21 V_46 ;
T_22 V_47 , V_48 ;
T_23 V_49 = V_50 ;
V_48 . V_18 = F_53 ( V_51 ) ;
V_48 . V_19 = F_53 ( V_52 ) ;
V_47 . V_18 = V_23 -> V_18 + V_48 . V_18 ;
V_47 . V_19 = V_23 -> V_19 + V_48 . V_19 ;
V_45 . V_53 = sizeof( T_20 ) ;
V_46 = F_54 ( V_47 , V_49 ) ;
if ( F_55 ( V_46 , & V_45 ) ) {
if ( V_47 . V_18 < V_45 . V_54 . V_55 )
V_23 -> V_18 += V_45 . V_54 . V_55 - V_47 . V_18 ;
if ( V_47 . V_19 < V_45 . V_54 . V_56 )
V_23 -> V_19 += V_45 . V_54 . V_56 - V_47 . V_19 ;
}
}
void
F_28 ( T_1 * V_32 ,
T_11 * V_23 )
{
T_8 * V_17 ;
T_24 V_57 ;
T_9 V_58 ;
if ( V_23 -> V_25 && V_23 -> V_18 != - 32000 && V_23 -> V_19 != - 32000 ) {
V_17 = F_18 () ;
V_58 = F_21 ( V_17 ,
V_23 -> V_18 , V_23 -> V_19 ) ;
F_56 ( V_17 , V_58 ,
& V_57 ) ;
if( V_23 -> V_18 < V_57 . V_18 || V_23 -> V_18 > ( V_57 . V_18 + V_57 . V_41 ) )
V_23 -> V_18 = V_57 . V_18 ;
if( V_23 -> V_19 < V_57 . V_19 || V_23 -> V_19 > ( V_57 . V_19 + V_57 . V_42 ) )
V_23 -> V_19 = V_57 . V_19 ;
#ifdef F_2
F_52 ( V_23 ) ;
#endif
F_22 ( F_8 ( V_32 ) ,
V_23 -> V_18 ,
V_23 -> V_19 ) ;
}
if ( V_23 -> V_26 ) {
F_57 ( F_8 ( V_32 ) ,
V_23 -> V_41 ,
V_23 -> V_42 ) ;
}
if( V_23 -> V_27 ) {
if ( V_23 -> V_43 ) {
F_58 ( F_45 ( V_32 ) ) ;
} else {
F_59 ( F_45 ( V_32 ) ) ;
}
}
}
void
F_42 ( T_1 * V_1 )
{
T_11 V_23 ;
const T_7 * V_31 ;
if ( ! V_1 )
return;
if( F_60 ( V_1 ) && F_61 ( V_1 ) ) {
F_44 ( V_1 , & V_23 ) ;
V_31 = ( const T_7 * ) F_33 ( F_25 ( V_1 ) , V_24 ) ;
if( V_31 ) {
F_62 ( V_31 , & V_23 ) ;
F_63 ( ( T_2 ) V_31 ) ;
}
}
F_64 ( V_1 ) ;
}
static T_1 *
F_65 ( T_5 * V_59 ) {
T_1 * V_32 ;
V_32 = F_66 ( V_59 ) ;
V_13 ( V_59 ) ;
return V_32 ;
}
T_1 *
F_67 ( const char * * V_60 ) {
T_5 * V_59 ;
V_59 = F_68 ( V_60 ) ;
return F_65 ( V_59 ) ;
}
void
F_69 ( T_1 * V_61 ,
const char * V_62 ,
T_7 * V_63 )
{
T_1 * V_64 ;
V_64 = F_70 ( F_8 ( V_61 ) ,
V_65 ,
V_66 ,
V_67 ,
L_10 ,
V_62 , V_63 ) ;
F_71 ( F_72 ( V_64 ) ,
L_11 ) ;
F_73 ( F_74 ( V_64 ) ) ;
F_64 ( V_64 ) ;
}
void
F_75 ( void )
{
while ( F_76 () )
F_77 () ;
}
void
F_78 ( void )
{
if ( F_79 () > 0 )
F_80 () ;
}
void
F_81 ( void )
{
F_80 () ;
}
static T_12
F_82 ( T_2 T_3 )
{
T_25 V_68 ;
T_23 V_69 = 0 ;
T_12 V_70 ;
T_23 V_71 ;
T_26 * V_72 = T_3 ;
T_9 V_73 = 0 ;
while( V_73 < 5 ) {
V_68 = ( T_25 ) F_83 ( V_72 -> V_74 ) ;
V_70 = F_84 ( V_68 , NULL , 0 , NULL , & V_69 , NULL ) ;
F_85 ( ( T_25 ) * ( V_72 -> V_75 ) , & V_71 ) ;
if ( ! V_70 || V_69 > 0 || V_71 != V_76 ) {
if( V_72 -> V_77 != 0 ) {
F_86 ( V_72 -> V_77 ) ;
V_72 -> V_77 = 0 ;
}
if ( ! V_72 -> V_78 ( V_72 -> V_74 , V_72 -> T_17 ) ) {
F_87 ( NULL , V_79 , L_12 , V_73 ) ;
return FALSE ;
}
}
else {
break;
}
V_73 ++ ;
}
if( V_72 -> V_77 == 0 ) {
V_72 -> V_77 = F_88 ( 200 , F_82 , T_3 ) ;
return FALSE ;
} else {
return TRUE ;
}
}
static T_12
F_89 ( T_27 * V_74 V_2 ,
T_28 T_29 V_2 ,
T_2 T_3 )
{
T_26 * V_72 = ( T_26 * ) T_3 ;
F_86 ( V_72 -> V_77 ) ;
if ( V_72 -> V_78 ( V_72 -> V_74 , V_72 -> T_17 ) ) {
V_72 -> V_77 = F_90 ( V_72 -> V_80 ,
V_81 ,
( T_28 ) ( V_82 | V_83 | V_84 ) ,
F_89 ,
V_72 ,
NULL ) ;
}
return TRUE ;
}
void
F_91 ( T_9 V_74 ,
T_2 T_17 ,
T_30 * V_75 ,
T_31 V_78 )
{
static T_26 V_72 ;
V_72 . V_74 = V_74 ;
V_72 . V_75 = V_75 ;
V_72 . T_17 = T_17 ;
V_72 . V_78 = V_78 ;
#ifdef F_2
V_72 . V_77 = F_88 ( 200 , F_82 , & V_72 ) ;
#else
V_72 . V_80 = F_92 ( V_74 ) ;
F_93 ( V_72 . V_80 , NULL , NULL ) ;
V_72 . V_77 = F_90 ( V_72 . V_80 ,
V_81 ,
( T_28 ) ( V_82 | V_83 | V_84 ) ,
F_89 ,
& V_72 ,
NULL ) ;
#endif
}
void
F_94 ( T_1 * V_1 )
{
T_19 * V_85 ;
V_85 = F_45 ( V_1 ) ;
F_95 ( V_85 ) ;
F_96 ( V_85 ) ;
}
T_1 *
F_97 ( T_32 * V_86 ,
T_32 * V_87 )
{
T_1 * V_88 ;
V_88 = F_98 ( V_86 , V_87 ) ;
F_99 ( V_88 ) ;
return V_88 ;
}
static void
F_99 ( T_1 * V_88 )
{
F_100 ( F_101 ( V_88 ) ,
V_89 , V_89 ) ;
#if F_47 ( 3 , 16 , 0 )
F_102 ( F_101 ( V_88 ) , FALSE ) ;
#endif
V_90 = F_6 ( V_90 , V_88 ) ;
F_15 ( V_88 , L_13 , F_16 ( V_91 ) , NULL ) ;
}
static void
V_91 ( T_1 * V_88 ,
T_2 T_3 V_2 )
{
V_90 = F_103 ( V_90 , V_88 ) ;
}
T_1 *
F_104 ( T_33 * V_92 )
{
T_1 * V_93 ;
V_93 = F_105 ( V_92 ) ;
F_106 ( V_93 ) ;
return V_93 ;
}
static void
F_106 ( T_1 * V_93 )
{
F_107 ( V_93 ) ;
V_94 = F_6 ( V_94 , V_93 ) ;
F_15 ( V_93 , L_13 , F_16 ( V_95 ) , NULL ) ;
F_15 ( V_93 , L_14 , F_16 ( V_96 ) , NULL ) ;
}
static void
V_95 ( T_1 * V_93 ,
T_2 T_3 V_2 )
{
V_94 = F_103 ( V_94 , V_93 ) ;
}
static void
F_107 ( T_1 * V_93 )
{
F_108 ( V_97 . V_98 >= 0 && V_97 . V_98 <= 1 ) ;
F_109 ( F_110 ( V_93 ) ,
V_97 . V_98 ) ;
}
static void
F_111 ( T_2 T_3 ,
T_2 T_17 V_2 )
{
F_107 ( ( T_1 * ) T_3 ) ;
}
void
F_112 ( void )
{
F_9 ( V_94 , F_111 , NULL ) ;
}
T_12
F_113 ( T_34 * V_93 ,
T_12 V_99 )
{
T_35 V_100 , V_101 ;
T_33 * V_92 ;
T_36 * V_102 ;
T_37 * V_103 , * V_104 ;
V_102 = F_114 ( V_93 ) ;
if ( ! F_115 ( V_102 , & V_92 , & V_100 ) ) {
return FALSE ;
}
V_103 = F_116 ( V_92 , & V_100 ) ;
if ( ! V_103 ) {
return FALSE ;
}
V_104 = F_117 ( V_103 ) ;
if ( V_99 ) {
F_118 ( V_104 ) ;
} else {
F_119 ( V_104 ) ;
}
if ( F_120 ( V_103 , V_104 ) == 0 ) {
F_121 ( V_103 ) ;
F_121 ( V_104 ) ;
return FALSE ;
}
F_122 ( V_92 , & V_101 , V_104 ) ;
F_123 ( F_124 ( V_92 ) , & V_100 , & V_101 ) ;
F_121 ( V_103 ) ;
F_121 ( V_104 ) ;
return TRUE ;
}
T_9
F_125 ( T_34 * V_93 ) {
T_35 V_105 ;
T_33 * V_92 ;
T_36 * V_102 ;
T_37 * V_106 ;
T_7 * V_107 ;
T_9 V_108 ;
V_102 = F_114 ( V_93 ) ;
if ( ! F_115 ( V_102 , & V_92 , & V_105 ) ) {
return - 1 ;
}
V_106 = F_116 ( V_92 , & V_105 ) ;
if ( ! V_106 ) {
return FALSE ;
}
V_107 = F_126 ( V_106 ) ;
F_121 ( V_106 ) ;
V_108 = ( T_9 ) strtol ( V_107 , NULL , 10 ) ;
F_63 ( V_107 ) ;
return V_108 ;
}
void
F_127 ( T_1 * V_109 ,
... )
{
T_38 V_110 ;
T_35 V_105 ;
T_39 * V_111 ;
va_start ( V_110 , V_109 ) ;
V_111 = F_124 ( F_128 ( F_110 ( V_109 ) ) ) ;
F_129 ( V_111 , & V_105 ) ;
F_130 ( V_111 , & V_105 , V_110 ) ;
va_end ( V_110 ) ;
}
T_1 *
F_131 ( T_9 V_112 ,
const T_7 * * V_113 ) {
T_1 * V_114 ;
int V_115 ;
T_39 * V_111 ;
T_40 * V_116 ;
T_41 * V_117 ;
F_108 ( V_112 <= 10 ) ;
V_111 = F_132 ( V_112 ,
V_118 , V_118 , V_118 , V_118 , V_118 ,
V_118 , V_118 , V_118 , V_118 , V_118 ) ;
V_114 = F_104 ( F_133 ( V_111 ) ) ;
V_13 ( F_25 ( V_111 ) ) ;
F_134 ( F_110 ( V_114 ) , ( V_113 != NULL ) ) ;
for( V_115 = 0 ; V_115 < V_112 ; V_115 ++ ) {
V_116 = F_135 () ;
V_117 = F_136 ( V_113 ? V_113 [ V_115 ] : L_15 , V_116 ,
L_16 , V_115 , NULL ) ;
F_137 ( V_117 , V_115 ) ;
F_138 ( F_110 ( V_114 ) , V_117 ) ;
}
return V_114 ;
}
void
F_139 ( T_40 * V_119 )
{
F_140 ( V_119 , L_17 , L_18 , NULL ) ;
F_140 ( V_119 , L_19 , TRUE , NULL ) ;
F_140 ( V_119 , L_20 , V_120 , NULL ) ;
F_140 ( V_119 , L_21 , TRUE , NULL ) ;
}
void
F_141 ( T_1 * V_109 ,
T_9 V_121 )
{
T_41 * V_122 ;
T_4 * V_123 ;
T_40 * V_124 ;
V_122 = F_142 ( F_110 ( V_109 ) , V_121 ) ;
V_123 = F_143 ( F_144 ( V_122 ) ) ;
if( V_123 != NULL ) {
V_124 = ( T_40 * ) V_123 -> T_3 ;
F_139 ( V_124 ) ;
F_10 ( V_123 ) ;
}
}
void
F_145 ( T_42 * V_125 )
{
T_43 * V_38 ;
V_38 = F_146 ( V_126 ) ;
F_147 ( V_38 , V_125 -> V_125 , - 1 ) ;
}
static T_44 *
F_148 ( const T_45 * T_3 ,
int V_127 )
{
T_44 * V_128 ;
F_108 ( V_127 > 0 ) ;
V_128 = F_149 ( T_44 , 1 ) ;
V_128 -> T_3 = F_149 ( T_45 , V_127 ) ;
V_128 -> V_127 = V_127 ;
memcpy ( V_128 -> T_3 , T_3 , V_127 * sizeof( T_45 ) ) ;
return V_128 ;
}
static void
F_150 ( T_44 * V_128 ) {
F_63 ( V_128 -> T_3 ) ;
F_63 ( V_128 ) ;
}
static void
F_151 ( T_43 * T_46 V_2 ,
T_2 V_129 )
{
F_150 ( ( T_44 * ) V_129 ) ;
}
static void
F_152 ( T_43 * T_46 V_2 ,
T_47 * V_130 ,
T_48 T_49 V_2 ,
T_2 V_129 )
{
T_44 * V_128 ;
V_128 = ( T_44 * ) V_129 ;
F_153 ( V_130 , V_131 , 8 , V_128 -> T_3 , V_128 -> V_127 ) ;
}
void
F_154 ( const T_45 * V_132 ,
int V_127 )
{
static T_50 V_133 [] = {
{ L_22 , 0 , 0 } } ;
T_43 * V_38 ;
T_44 * V_128 ;
T_12 V_134 ;
if( V_127 <= 0 ) {
return;
}
V_38 = F_146 ( V_126 ) ;
V_128 = F_148 ( V_132 , V_127 ) ;
V_134 = F_155 ( V_38 , V_133 , 1 ,
F_152 , F_151 , V_128 ) ;
if( ! V_134 ) {
F_150 ( V_128 ) ;
}
}
T_7 *
F_156 ( const T_7 * V_135 )
{
if ( V_135 == NULL )
return F_26 ( L_15 ) ;
if ( ( V_97 . V_136 == NULL ) || ( * V_97 . V_136 == '\0' ) )
return F_26 ( V_135 ) ;
return F_157 ( L_23 , V_135 , V_97 . V_136 ) ;
}
void
F_158 ( T_1 * V_1 ,
const T_7 * V_135 )
{
char * V_14 ;
char * V_137 ;
V_137 = F_159 ( & V_138 ) ;
V_14 = F_157 ( L_24 , V_135 , V_137 ) ;
F_63 ( V_137 ) ;
F_14 ( F_8 ( V_1 ) , V_14 ) ;
F_63 ( V_14 ) ;
}
static void
F_160 ( T_34 * V_139 , T_33 * V_92 , T_37 * V_106 ,
T_35 * V_105 )
{
T_35 V_140 ;
if ( F_161 ( V_139 , V_106 ) ) {
if ( F_162 ( V_92 , & V_140 , V_105 ) ) {
F_163 ( V_106 ) ;
do {
if ( F_161 ( V_139 , V_106 ) ) {
F_160 ( V_139 , V_92 , V_106 , & V_140 ) ;
}
F_119 ( V_106 ) ;
} while ( F_164 ( V_92 , & V_140 ) );
F_165 ( V_106 ) ;
F_166 ( V_139 , V_106 ) ;
}
}
}
void
F_167 ( T_34 * V_139 , T_37 * V_106 )
{
T_35 V_105 ;
T_33 * V_92 ;
V_92 = F_128 ( V_139 ) ;
F_122 ( V_92 , & V_105 , V_106 ) ;
F_160 ( V_139 , V_92 , V_106 , & V_105 ) ;
}
static T_12
V_96 ( T_1 * V_93 ,
T_13 * V_33 ,
T_2 T_17 V_2 )
{
T_36 * V_141 ;
T_35 V_105 ;
T_35 V_61 ;
T_33 * V_92 ;
T_37 * V_106 ;
T_12 V_142 , V_143 ;
int V_144 = FALSE ;
V_141 = F_114 ( F_110 ( V_93 ) ) ;
if( ! V_141 ) {
return FALSE ;
}
if( ! F_115 ( V_141 , & V_92 , & V_105 ) ) {
return FALSE ;
}
V_106 = F_116 ( V_92 , & V_105 ) ;
if( ! V_106 ) {
return FALSE ;
}
V_142 = F_161 ( F_110 ( V_93 ) , V_106 ) ;
V_143 = F_168 ( V_92 , & V_105 ) ;
switch ( V_33 -> V_35 ) {
case V_145 :
if( V_142 ) {
if ( V_33 -> V_39 & V_146 )
{
F_160 ( F_110 ( V_93 ) , V_92 , V_106 , & V_105 ) ;
}
else
F_166 ( F_110 ( V_93 ) , V_106 ) ;
V_144 = TRUE ;
break;
}
case V_147 :
if ( ! V_142 ) {
if( ! F_169 ( V_92 , & V_61 , & V_105 ) ) {
V_144 = FALSE ;
break;
}
F_121 ( V_106 ) ;
V_106 = F_116 ( V_92 , & V_61 ) ;
if( ! V_106 ) {
return FALSE ;
}
F_170 ( F_110 ( V_93 ) , V_106 ,
NULL ,
FALSE ) ;
V_144 = TRUE ;
break;
}
break;
case V_148 :
if ( V_143 ) {
F_171 ( F_110 ( V_93 ) , V_106 , FALSE ) ;
V_144 = TRUE ;
break;
} else {
V_144 = FALSE ;
break;
}
case V_149 :
case V_150 :
if ( V_142 )
F_166 ( F_110 ( V_93 ) , V_106 ) ;
else
F_171 ( F_110 ( V_93 ) , V_106 , FALSE ) ;
V_144 = TRUE ;
break;
}
if( V_106 ) {
F_121 ( V_106 ) ;
}
return V_144 ;
}
void
F_172 ( T_34 * V_151 )
{
T_9 V_152 ;
T_41 * V_117 ;
T_4 * V_153 , * V_109 ;
V_153 = F_173 ( F_110 ( V_151 ) ) ;
V_109 = V_153 ;
while( V_153 ) {
V_117 = ( T_41 * ) V_153 -> T_3 ;
V_152 = F_174 ( V_117 ) ;
F_175 ( V_117 , V_154 ) ;
if ( V_152 > F_176 ( V_117 ) )
F_177 ( V_117 , V_152 ) ;
V_153 = F_178 ( V_153 ) ;
}
F_10 ( V_109 ) ;
F_179 ( V_151 , TRUE ) ;
}
T_9
F_180 ( T_1 * V_151 ,
const T_7 * V_125 )
{
T_51 * V_155 ;
T_9 V_156 ;
V_155 = F_181 ( V_151 , V_125 ) ;
F_182 ( V_155 ,
& V_156 ,
NULL ) ;
V_13 ( F_25 ( V_155 ) ) ;
return V_156 + ( F_183 ( F_184 () ) / V_157 ) ;
}
void
F_185 ( T_41 * V_117 V_2 ,
T_40 * V_116 ,
T_33 * V_92 ,
T_35 * V_105 ,
T_2 T_17 )
{
T_52 V_158 ;
T_7 V_159 [ 20 ] ;
char * V_160 ;
T_9 V_161 = F_186 ( T_17 ) ;
F_187 ( V_92 , V_105 , V_161 , & V_158 , - 1 ) ;
V_160 = F_26 ( setlocale ( V_162 , NULL ) ) ;
setlocale ( V_162 , L_25 ) ;
F_188 ( V_159 , sizeof( V_159 ) , L_26 , V_158 ) ;
setlocale ( V_162 , V_160 ) ;
F_63 ( V_160 ) ;
F_140 ( V_116 , L_16 , V_159 , NULL ) ;
}
void
F_189 ( T_41 * V_117 V_2 ,
T_40 * V_116 ,
T_33 * V_92 ,
T_35 * V_105 ,
T_2 T_17 )
{
T_48 V_163 ;
T_7 V_159 [ 35 ] ;
T_9 V_121 = F_186 ( T_17 ) ;
F_187 ( V_92 , V_105 , V_121 , & V_163 , - 1 ) ;
F_188 ( V_159 , sizeof( V_159 ) , L_27 , V_163 ) ;
F_140 ( V_116 , L_16 , V_159 , NULL ) ;
}
void
F_190 ( T_41 * V_117 V_2 ,
T_40 * V_116 ,
T_33 * V_92 ,
T_35 * V_105 ,
T_2 T_17 )
{
T_53 V_163 ;
int V_115 = 0 ;
T_7 * V_164 ;
T_7 V_159 [ 35 ] ;
T_9 V_121 = F_186 ( T_17 ) ;
F_187 ( V_92 , V_105 , V_121 , & V_163 , - 1 ) ;
V_164 = & V_159 [ 34 ] ;
* V_164 = 0 ;
do {
* -- V_164 = ( T_7 ) ( V_163 % 10 ) + '0' ;
if ( ! ( ++ V_115 % 3 ) ) {
* -- V_164 = ' ' ;
}
} while ( ( V_163 /= 10 ) != 0 && V_164 > V_159 );
F_140 ( V_116 , L_16 , V_164 , NULL ) ;
}
void
F_191 ( T_41 * V_117 V_2 ,
T_40 * V_116 ,
T_33 * V_92 ,
T_35 * V_105 ,
T_2 T_17 )
{
const T_7 * V_125 = NULL ;
T_9 V_165 = F_186 ( T_17 ) ;
F_187 ( V_92 , V_105 , V_165 , & V_125 , - 1 ) ;
F_140 ( V_116 , L_16 , V_125 , NULL ) ;
}
T_9
F_192 ( T_33 * V_92 ,
T_35 * V_166 ,
T_35 * V_167 ,
T_2 T_17 )
{
const T_7 * V_168 = NULL ;
const T_7 * V_169 = NULL ;
T_9 V_134 = 0 ;
T_9 V_165 = F_186 ( T_17 ) ;
F_187 ( V_92 , V_166 , V_165 , & V_168 , - 1 ) ;
F_187 ( V_92 , V_167 , V_165 , & V_169 , - 1 ) ;
if ( V_168 == V_169 ) {
return 0 ;
}
else if ( V_168 == NULL || V_169 == NULL ) {
V_134 = ( V_168 == NULL ) ? - 1 : 1 ;
}
else {
V_134 = F_193 ( V_168 , V_169 ) ;
}
return V_134 ;
}
T_1 *
F_194 ( T_40 * * V_170 ) {
T_1 * V_171 ;
T_40 * V_119 ;
T_54 * V_111 ;
V_111 = F_195 ( 3 , V_118 , V_172 , V_173 ) ;
V_171 = F_196 ( F_133 ( V_111 ) ) ;
V_13 ( V_111 ) ;
V_119 = F_135 () ;
F_197 ( F_144 ( V_171 ) , V_119 , TRUE ) ;
F_198 ( F_144 ( V_171 ) , V_119 ,
L_16 , 0 , L_28 , 2 ,
NULL ) ;
if ( V_170 != NULL ) {
* V_170 = V_119 ;
}
return V_171 ;
}
T_1 *
F_199 ( void ) {
return F_194 ( NULL ) ;
}
void
F_200 ( T_55 * V_171 )
{
F_201 ( F_202 ( F_203 ( V_171 ) ) ) ;
}
T_35
F_204 ( T_55 * V_171 ,
T_35 * V_174 ,
const T_7 * V_175 ,
T_56 V_176 ,
T_12 V_177 )
{
T_35 V_105 ;
T_54 * V_111 ;
V_111 = F_202 ( F_203 ( V_171 ) ) ;
F_205 ( V_111 , & V_105 , V_174 ) ;
F_206 ( V_111 , & V_105 , 0 , V_175 , 1 , V_176 , 2 , V_177 , - 1 ) ;
return V_105 ;
}
T_35
F_207 ( T_55 * V_171 ,
const T_7 * V_175 ,
T_56 V_176 )
{
return F_204 ( V_171 , NULL , V_175 , V_176 , TRUE ) ;
}
T_12
F_208 ( T_55 * V_171 ,
T_2 * V_176 )
{
T_54 * V_111 ;
T_35 V_105 ;
* V_176 = NULL ;
if ( F_209 ( V_171 , & V_105 ) ) {
V_111 = F_202 ( F_203 ( V_171 ) ) ;
F_187 ( F_133 ( V_111 ) , & V_105 ,
1 , V_176 , - 1 ) ;
return TRUE ;
}
return FALSE ;
}
T_9
F_210 ( T_55 * V_171 )
{
return F_211 ( V_171 ) ;
}
void
F_212 ( T_55 * V_171 ,
T_9 V_178 )
{
F_213 ( V_171 , V_178 ) ;
}
void
F_214 ( T_55 * V_171 , T_35 * V_105 )
{
F_215 ( V_171 , V_105 ) ;
}
static T_57
F_216 ( T_58 V_179 )
{
switch ( V_179 )
{
case V_180 :
return V_181 ;
case V_182 :
return V_183 ;
case V_184 :
default:
return V_185 ;
}
}
static T_59 *
F_217 ( T_59 * V_186 ,
T_58 V_179 ,
int V_187 ,
int V_188 ,
int V_41 ,
int V_42 )
{
T_59 * V_189 ;
T_60 * V_190 ;
V_189 = F_218 ( F_216 ( V_179 ) ,
V_41 ,
V_42 ) ;
V_190 = F_219 ( V_189 ) ;
F_220 ( V_190 , V_191 ) ;
F_221 ( V_190 , V_186 , - V_187 , - V_188 ) ;
F_222 ( V_190 ) ;
F_223 ( V_190 ) ;
return V_189 ;
}
static void
F_224 ( T_61 * V_192 ,
int V_193 ,
T_61 * V_194 ,
int V_195 ,
int V_187 ,
int V_188 ,
int V_41 ,
int V_42 )
{
int V_18 , V_19 ;
V_194 += V_195 * V_188 + V_187 * 4 ;
for ( V_19 = 0 ; V_19 < V_42 ; V_19 ++ ) {
T_62 * V_196 = ( T_62 * ) V_194 ;
for ( V_18 = 0 ; V_18 < V_41 ; V_18 ++ ) {
T_48 V_197 = V_196 [ V_18 ] >> 24 ;
if ( V_197 == 0 )
{
V_192 [ V_18 * 4 + 0 ] = 0 ;
V_192 [ V_18 * 4 + 1 ] = 0 ;
V_192 [ V_18 * 4 + 2 ] = 0 ;
}
else
{
V_192 [ V_18 * 4 + 0 ] = ( ( ( V_196 [ V_18 ] & 0xff0000 ) >> 16 ) * 255 + V_197 / 2 ) / V_197 ;
V_192 [ V_18 * 4 + 1 ] = ( ( ( V_196 [ V_18 ] & 0x00ff00 ) >> 8 ) * 255 + V_197 / 2 ) / V_197 ;
V_192 [ V_18 * 4 + 2 ] = ( ( ( V_196 [ V_18 ] & 0x0000ff ) >> 0 ) * 255 + V_197 / 2 ) / V_197 ;
}
V_192 [ V_18 * 4 + 3 ] = V_197 ;
}
V_194 += V_195 ;
V_192 += V_193 ;
}
}
static void
F_225 ( T_61 * V_192 ,
int V_193 ,
T_61 * V_194 ,
int V_195 ,
int V_187 ,
int V_188 ,
int V_41 ,
int V_42 )
{
int V_18 , V_19 ;
V_194 += V_195 * V_188 + V_187 * 4 ;
for ( V_19 = 0 ; V_19 < V_42 ; V_19 ++ ) {
T_62 * V_196 = ( T_62 * ) V_194 ;
for ( V_18 = 0 ; V_18 < V_41 ; V_18 ++ ) {
V_192 [ V_18 * 3 + 0 ] = V_196 [ V_18 ] >> 16 ;
V_192 [ V_18 * 3 + 1 ] = V_196 [ V_18 ] >> 8 ;
V_192 [ V_18 * 3 + 2 ] = V_196 [ V_18 ] ;
}
V_194 += V_195 ;
V_192 += V_193 ;
}
}
T_5 *
F_226 ( T_59 * V_186 ,
T_9 V_187 ,
T_9 V_188 ,
T_9 V_41 ,
T_9 V_42 )
{
T_58 V_179 ;
T_5 * V_198 ;
F_35 ( V_186 != NULL , NULL ) ;
F_35 ( V_41 > 0 && V_42 > 0 , NULL ) ;
V_179 = ( T_58 ) ( F_227 ( V_186 ) | V_180 ) ;
V_198 = F_228 ( V_199 ,
! ! ( V_179 & V_182 ) ,
8 ,
V_41 , V_42 ) ;
V_186 = F_217 ( V_186 , V_179 ,
V_187 , V_188 ,
V_41 , V_42 ) ;
F_229 ( V_186 ) ;
if ( F_230 ( V_186 ) || V_198 == NULL )
{
F_231 ( V_186 ) ;
return NULL ;
}
if ( F_232 ( V_198 ) )
F_224 ( F_233 ( V_198 ) ,
F_234 ( V_198 ) ,
F_235 ( V_186 ) ,
F_236 ( V_186 ) ,
0 , 0 ,
V_41 , V_42 ) ;
else
F_225 ( F_233 ( V_198 ) ,
F_234 ( V_198 ) ,
F_235 ( V_186 ) ,
F_236 ( V_186 ) ,
0 , 0 ,
V_41 , V_42 ) ;
F_231 ( V_186 ) ;
return V_198 ;
}
T_1 *
F_237 ( T_63 V_200 ,
T_9 V_201 ,
T_12 V_202 )
{
#if ! F_47 ( 3 , 0 , 0 )
if ( V_200 == V_203 )
return F_238 ( V_202 , V_201 ) ;
else
return F_239 ( V_202 , V_201 ) ;
#else
T_1 * V_32 ;
V_32 = F_240 ( V_200 , V_201 ) ;
F_241 ( F_242 ( V_32 ) , V_202 ) ;
return V_32 ;
#endif
}
T_1 *
F_243 ( T_63 V_200 )
{
if ( V_200 == V_203 ) {
return F_244 () ;
} else {
return F_245 () ;
}
}
T_1 *
F_246 ( T_63 V_200 ,
T_32 * V_204 )
{
if ( V_200 == V_203 ) {
return F_247 ( V_204 ) ;
} else {
return F_248 ( V_204 ) ;
}
}
T_1 *
F_249 ( T_63 V_200 )
{
if( V_200 == V_203 ) {
return F_250 () ;
} else {
return F_251 () ;
}
}
T_1 *
F_252 ( T_63 V_200 )
{
if ( V_200 == V_203 ) {
return F_253 () ;
} else {
return F_254 () ;
}
}
T_1 *
F_255 ( const T_7 * V_14 ) {
T_1 * V_205 , * V_206 ;
T_42 * V_207 = F_256 ( L_15 ) ;
V_205 = F_257 ( NULL ) ;
F_258 ( F_259 ( V_205 ) , V_208 ) ;
if ( V_14 ) {
#if F_260 ( F_2 ) || F_260 ( V_209 )
F_261 ( V_207 , L_29 , V_14 ) ;
#else
F_261 ( V_207 , L_30 , V_14 ) ;
#endif
V_206 = F_262 ( NULL ) ;
F_263 ( F_264 ( V_206 ) , V_207 -> V_125 ) ;
F_265 ( F_259 ( V_205 ) , V_206 ) ;
}
F_266 ( V_207 , TRUE ) ;
return V_205 ;
}
void
F_267 ( T_64 * V_210 , T_1 * V_140 , T_9 V_55 , T_9 V_56 , T_9 V_41 , T_9 V_42 )
{
F_268 ( V_210 , V_140 , V_55 , V_56 , V_41 , V_42 ,
( V_211 ) ( V_212 | V_213 ) , ( V_211 ) ( V_212 | V_213 ) , 0 , 0 ) ;
}
void
F_268 ( T_64 * V_210 , T_1 * V_140 ,
T_9 V_55 , T_9 V_56 , T_9 V_41 , T_9 V_42 ,
V_211 V_214 , V_211 V_215 ,
T_48 V_216 , T_48 V_217 )
{
F_269 ( V_210 , V_140 , V_55 , V_56 , V_41 , V_42 ) ;
if ( V_214 & V_212 )
F_270 ( V_140 , TRUE ) ;
if ( V_215 & V_212 )
F_271 ( V_140 , TRUE ) ;
F_272 ( V_140 , ( V_214 & V_213 ) ? V_218 : V_219 ) ;
F_273 ( V_140 , ( V_215 & V_213 ) ? V_218 : V_219 ) ;
if ( V_216 != 0 ) {
F_274 ( V_140 , V_216 ) ;
F_275 ( V_140 , V_216 ) ;
}
if ( V_217 != 0 ) {
F_276 ( V_140 , V_217 ) ;
F_277 ( V_140 , V_217 ) ;
}
}
void
F_278 ( T_64 * V_210 , T_12 V_202 )
{
F_279 ( V_210 , V_202 ) ;
F_280 ( V_210 , V_202 ) ;
}
void
F_281 ( T_60 * V_190 , const T_65 * V_220 )
{
T_66 V_221 ;
F_282 ( & V_221 , V_220 ) ;
F_283 ( V_190 , & V_221 ) ;
}
T_5 *
F_4 ( const char * V_106 )
{
T_5 * V_59 ;
T_67 * V_222 = NULL ;
V_59 = F_284 ( V_106 , & V_222 ) ;
F_285 ( V_222 ) ;
return V_59 ;
}
