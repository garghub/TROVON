static void
F_1 ( T_1 * V_1 , T_2 T_3 V_2 )
{
#ifndef F_2
T_4 * V_3 = NULL ;
T_5 * V_4 ;
V_4 = F_3 ( ( const char * * ) V_5 ) ;
V_3 = F_4 ( V_3 , V_4 ) ;
V_4 = F_3 ( ( const char * * ) V_6 ) ;
V_3 = F_4 ( V_3 , V_4 ) ;
V_4 = F_3 ( ( const char * * ) V_7 ) ;
V_3 = F_4 ( V_3 , V_4 ) ;
V_4 = F_3 ( ( const char * * ) V_8 ) ;
V_3 = F_4 ( V_3 , V_4 ) ;
F_5 ( F_6 ( V_1 ) , V_3 ) ;
F_7 ( F_6 ( V_1 ) , L_1 ) ;
#endif
}
T_1 *
F_8 ( T_6 type , const T_7 * V_9 )
{
T_1 * V_1 ;
V_1 = F_9 ( type ) ;
if ( V_9 != NULL )
F_10 ( F_6 ( V_1 ) , V_9 ) ;
F_11 ( V_1 , L_2 , F_12 ( F_1 ) , NULL ) ;
F_13 ( F_6 ( V_1 ) , V_10 ) ;
return V_1 ;
}
T_1 *
F_14 ( T_6 type , const T_7 * V_9 , const T_7 * V_11 )
{
T_8 V_12 ;
T_1 * V_1 = F_8 ( type , V_9 ) ;
F_15 ( F_16 ( V_1 ) , V_13 , ( T_2 ) F_17 ( V_11 ) ) ;
if( V_11 ) {
if( F_18 ( V_11 , & V_12 ) ) {
V_12 . V_14 = TRUE ;
V_12 . V_15 = TRUE ;
V_12 . V_16 = FALSE ;
F_19 ( V_1 , & V_12 ) ;
}
}
return V_1 ;
}
T_1 *
F_20 ( void )
{
T_1 * V_1 ;
V_1 = F_8 ( V_17 , L_3 ) ;
F_21 ( F_6 ( V_1 ) , FALSE ) ;
F_13 ( F_6 ( V_1 ) , V_18 ) ;
return V_1 ;
}
void
F_22 ( T_1 * V_1 )
{
T_8 V_12 ;
const T_7 * V_19 ;
F_23 ( F_6 ( V_1 ) ) ;
V_19 = F_24 ( F_16 ( V_1 ) , V_13 ) ;
if( V_19 ) {
if( F_18 ( V_19 , & V_12 ) ) {
V_12 . V_14 = TRUE ;
V_12 . V_15 = TRUE ;
V_12 . V_16 = TRUE ;
F_19 ( V_1 , & V_12 ) ;
}
}
}
static T_9
F_25 ( T_1 * V_20 , T_10 * V_21 , T_2 V_22 )
{
F_26 ( V_20 != NULL , FALSE ) ;
F_26 ( V_21 != NULL , FALSE ) ;
if ( V_21 -> V_23 == V_24 ) {
F_27 ( F_28 ( V_22 ) ) ;
return TRUE ;
}
return FALSE ;
}
static void
F_29 ( T_1 * V_20 , T_1 * V_22 )
{
F_11 ( V_20 , L_4 , F_12 ( F_25 ) , V_22 ) ;
}
void F_30 ( T_1 * V_1 , T_1 * V_25 , T_11 V_26 )
{
if( V_26 )
F_11 ( V_25 , L_5 , F_12 ( V_26 ) , V_1 ) ;
F_31 ( V_25 ) ;
F_29 ( V_1 , V_25 ) ;
}
void F_32 ( T_1 * T_12 V_2 , T_2 T_3 )
{
F_33 ( F_28 ( T_3 ) ) ;
}
T_9
F_34 ( T_1 * V_1 , T_13 * V_21 V_2 , T_2 T_14 V_2 )
{
F_33 ( V_1 ) ;
return TRUE ;
}
void
F_35 ( T_1 * V_20 , T_8 * V_12 )
{
T_15 V_27 ;
T_16 * V_28 ;
memset ( V_12 , 0 , sizeof ( T_8 ) ) ;
V_28 = F_36 ( V_20 ) ;
F_37 ( V_28 ,
& V_12 -> V_29 ,
& V_12 -> V_30 ) ;
#if F_38 ( 2 , 24 , 0 )
V_12 -> V_31 = F_39 ( V_28 ) ;
V_12 -> V_32 = F_40 ( V_28 ) ;
#else
F_41 ( V_28 ,
& V_12 -> V_31 ,
& V_12 -> V_32 ) ;
#endif
V_27 = F_42 ( V_28 ) ;
V_12 -> V_33 = ( V_27 == V_34 ) ;
}
void
F_19 ( T_1 * V_20 , T_8 * V_12 )
{
T_17 * V_35 ;
T_18 V_36 ;
T_19 V_37 ;
if ( V_12 -> V_14 && V_12 -> V_29 != - 32000 && V_12 -> V_30 != - 32000 ) {
V_35 = F_43 () ;
V_37 = F_44 ( V_35 ,
V_12 -> V_29 , V_12 -> V_30 ) ;
F_45 ( V_35 , V_37 ,
& V_36 ) ;
if( V_12 -> V_29 < V_36 . V_29 || V_12 -> V_29 > V_36 . V_31 )
V_12 -> V_29 = V_36 . V_29 ;
if( V_12 -> V_30 < V_36 . V_30 || V_12 -> V_30 > V_36 . V_32 )
V_12 -> V_30 = V_36 . V_30 ;
F_46 ( F_6 ( V_20 ) ,
V_12 -> V_29 ,
V_12 -> V_30 ) ;
}
if ( V_12 -> V_15 ) {
F_47 ( F_6 ( V_20 ) ,
V_12 -> V_31 ,
V_12 -> V_32 ) ;
}
if( V_12 -> V_16 ) {
if ( V_12 -> V_33 ) {
F_48 ( F_36 ( V_20 ) ) ;
} else {
F_49 ( F_36 ( V_20 ) ) ;
}
}
}
static void
F_50 ( const T_7 * V_19 , T_8 * V_12 )
{
T_7 * V_38 ;
T_8 * V_39 ;
if( ! V_40 ) {
V_40 = F_51 ( V_41 , V_42 ) ;
}
V_39 = F_52 ( V_40 , V_19 ) ;
if( V_39 ) {
F_53 ( V_40 , V_19 ) ;
F_54 ( V_39 -> V_38 ) ;
F_54 ( V_39 ) ;
}
V_39 = F_55 ( sizeof( * V_12 ) ) ;
* V_39 = * V_12 ;
V_38 = F_17 ( V_19 ) ;
V_39 -> V_38 = V_38 ;
F_56 ( V_40 , V_38 , V_39 ) ;
}
static T_9
F_18 ( const T_7 * V_19 , T_8 * V_12 )
{
T_8 * V_43 ;
if( ! V_40 ) {
V_40 = F_51 ( V_41 , V_42 ) ;
}
V_43 = F_52 ( V_40 , V_19 ) ;
if( V_43 ) {
* V_12 = * V_43 ;
return TRUE ;
} else {
return FALSE ;
}
}
void
F_57 ( const char * V_19 , const char * V_38 , const char * V_44 )
{
T_8 V_12 ;
if( ! F_18 ( V_19 , & V_12 ) ) {
V_12 . V_38 = NULL ;
V_12 . V_14 = FALSE ;
V_12 . V_29 = - 1 ;
V_12 . V_30 = - 1 ;
V_12 . V_15 = FALSE ;
V_12 . V_31 = - 1 ;
V_12 . V_32 = - 1 ;
V_12 . V_16 = FALSE ;
V_12 . V_33 = FALSE ;
}
if ( strcmp ( V_38 , L_6 ) == 0 ) {
V_12 . V_29 = strtol ( V_44 , NULL , 10 ) ;
V_12 . V_14 = TRUE ;
} else if ( strcmp ( V_38 , L_7 ) == 0 ) {
V_12 . V_30 = strtol ( V_44 , NULL , 10 ) ;
V_12 . V_14 = TRUE ;
} else if ( strcmp ( V_38 , L_8 ) == 0 ) {
V_12 . V_31 = strtol ( V_44 , NULL , 10 ) ;
V_12 . V_15 = TRUE ;
} else if ( strcmp ( V_38 , L_9 ) == 0 ) {
V_12 . V_32 = strtol ( V_44 , NULL , 10 ) ;
V_12 . V_15 = TRUE ;
} else if ( strcmp ( V_38 , L_10 ) == 0 ) {
if ( F_58 ( V_44 , L_11 ) == 0 ) {
V_12 . V_33 = TRUE ;
}
else {
V_12 . V_33 = FALSE ;
}
V_12 . V_16 = TRUE ;
} else {
return;
}
F_50 ( V_19 , & V_12 ) ;
}
void
F_59 ( T_2 V_45 )
{
if( ! V_40 ) {
V_40 = F_51 ( V_41 , V_42 ) ;
}
F_60 ( V_40 , V_46 , V_45 ) ;
}
void
F_33 ( T_1 * V_1 )
{
T_8 V_12 ;
const T_7 * V_19 ;
if ( ! V_1 )
return;
if( F_61 ( V_1 ) && F_62 ( V_1 ) ) {
F_35 ( V_1 , & V_12 ) ;
V_19 = F_24 ( F_16 ( V_1 ) , V_13 ) ;
if( V_19 ) {
F_50 ( V_19 , & V_12 ) ;
F_54 ( ( T_2 ) V_19 ) ;
}
}
F_63 ( V_1 ) ;
}
T_1 * F_64 ( const char * * V_47 ) {
T_5 * V_48 ;
V_48 = F_3 ( V_47 ) ;
return F_65 ( V_48 ) ;
}
T_1 * F_66 ( const char * V_49 ) {
T_5 * V_48 ;
V_48 = F_67 ( - 1 , V_49 , FALSE , NULL ) ;
return F_65 ( V_48 ) ;
}
void
F_68 ( T_1 * V_50 , const char * V_51 )
{
T_1 * V_52 ;
V_52 = F_69 ( F_6 ( V_50 ) ,
V_53 ,
V_54 ,
V_55 ,
L_12 ,
V_51 , V_56 ) ;
F_70 ( F_71 ( V_52 ) ,
L_13 ) ;
F_72 ( F_73 ( V_52 ) ) ;
F_63 ( V_52 ) ;
}
void F_74 ( void )
{
while ( F_75 () ) F_76 () ;
}
void F_77 ( void )
{
exit ( 0 ) ;
}
void F_78 ( void )
{
if ( F_79 () > 0 )
F_80 () ;
}
void F_81 ( void )
{
F_80 () ;
}
static T_9
F_82 ( T_2 T_3 )
{
T_20 V_57 ;
T_21 V_58 = 0 ;
T_9 V_59 , V_60 ;
T_21 V_61 ;
T_22 * V_62 = T_3 ;
T_19 V_63 = 0 ;
while( V_63 < 5 ) {
V_57 = ( T_20 ) F_83 ( V_62 -> V_64 ) ;
V_59 = F_84 ( V_57 , NULL , 0 , NULL , & V_58 , NULL ) ;
V_60 = F_85 ( ( T_20 ) * ( V_62 -> V_65 ) ,
& V_61 ) ;
if ( ! V_59 || V_58 > 0 || V_61 != V_66 ) {
if( V_62 -> V_67 != 0 ) {
F_86 ( V_62 -> V_67 ) ;
V_62 -> V_67 = 0 ;
}
if ( ! V_62 -> V_68 ( V_62 -> V_64 , V_62 -> T_14 ) ) {
F_87 ( NULL , V_69 , L_14 , V_63 ) ;
return FALSE ;
}
}
else {
break;
}
V_63 ++ ;
}
if( V_62 -> V_67 == 0 ) {
V_62 -> V_67 = F_88 ( 200 , F_82 , T_3 ) ;
return FALSE ;
} else {
return TRUE ;
}
}
static T_9
F_89 ( T_23 * V_64 V_2 , T_24 T_25 V_2 ,
T_2 T_3 )
{
T_22 * V_62 = T_3 ;
F_86 ( V_62 -> V_67 ) ;
if ( V_62 -> V_68 ( V_62 -> V_64 , V_62 -> T_14 ) ) {
V_62 -> V_67 = F_90 ( V_62 -> V_70 ,
V_71 ,
V_72 | V_73 | V_74 ,
F_89 ,
V_62 ,
NULL ) ;
}
return TRUE ;
}
void F_91 ( T_19 V_64 , T_2 T_14 , int * V_65 , T_26 V_68 )
{
static T_22 V_62 ;
V_62 . V_64 = V_64 ;
V_62 . V_65 = V_65 ;
V_62 . T_14 = T_14 ;
V_62 . V_68 = V_68 ;
#ifdef F_2
V_62 . V_67 = F_88 ( 200 , F_82 , & V_62 ) ;
#else
V_62 . V_70 = F_92 ( V_64 ) ;
F_93 ( V_62 . V_70 , NULL , NULL ) ;
V_62 . V_67 = F_90 ( V_62 . V_70 ,
V_71 ,
V_72 | V_73 | V_74 ,
F_89 ,
& V_62 ,
NULL ) ;
#endif
}
void
F_94 ( T_1 * V_1 )
{
T_16 * V_75 ;
V_75 = F_36 ( V_1 ) ;
F_95 ( V_75 ) ;
F_96 ( V_75 ) ;
}
T_1 *
F_97 ( T_27 * V_76 , T_27 * V_77 )
{
T_1 * V_78 ;
V_78 = F_98 ( V_76 , V_77 ) ;
F_99 ( V_78 ) ;
return V_78 ;
}
static void
F_99 ( T_1 * V_78 )
{
F_100 ( V_78 ) ;
F_101 ( F_102 ( V_78 ) ,
V_79 , V_79 ) ;
V_80 = F_4 ( V_80 , V_78 ) ;
F_11 ( V_78 , L_15 , F_12 ( V_81 ) , NULL ) ;
}
static void
V_81 ( T_1 * V_78 , T_2 T_3 V_2 )
{
V_80 = F_103 ( V_80 , V_78 ) ;
}
static void
F_100 ( T_1 * V_78 )
{
if ( V_82 . V_83 ) {
F_104 ( F_102 ( V_78 ) ,
V_84 ) ;
} else {
F_104 ( F_102 ( V_78 ) ,
V_85 ) ;
}
}
static void
F_105 ( T_2 T_3 , T_2 T_14 V_2 )
{
F_100 ( ( T_1 * ) T_3 ) ;
}
void
F_106 ( void )
{
F_107 ( V_80 , F_105 , NULL ) ;
}
T_1 *
F_108 ( T_28 * V_86 )
{
T_1 * V_87 ;
V_87 = F_109 ( V_86 ) ;
F_110 ( V_87 ) ;
return V_87 ;
}
static void
F_110 ( T_1 * V_87 )
{
F_111 ( V_87 ) ;
V_88 = F_4 ( V_88 , V_87 ) ;
F_11 ( V_87 , L_15 , F_12 ( V_89 ) , NULL ) ;
F_11 ( V_87 , L_16 , F_12 ( V_90 ) , NULL ) ;
}
static void
V_89 ( T_1 * V_87 , T_2 T_3 V_2 )
{
V_88 = F_103 ( V_88 , V_87 ) ;
}
static void
F_111 ( T_1 * V_87 )
{
F_112 ( V_82 . V_91 >= 0 && V_82 . V_91 <= 1 ) ;
F_113 ( F_114 ( V_87 ) ,
V_82 . V_91 ) ;
}
static void
F_115 ( T_2 T_3 , T_2 T_14 V_2 )
{
F_111 ( ( T_1 * ) T_3 ) ;
}
void
F_116 ( void )
{
F_107 ( V_88 , F_115 , NULL ) ;
}
T_9
F_117 ( T_29 * V_87 , T_9 V_92 )
{
T_30 V_93 , V_94 ;
T_28 * V_86 ;
T_31 * V_95 ;
T_32 * V_96 , * V_97 ;
V_95 = F_118 ( V_87 ) ;
if ( ! F_119 ( V_95 , & V_86 , & V_93 ) ) {
return FALSE ;
}
V_96 = F_120 ( V_86 , & V_93 ) ;
if ( ! V_96 ) {
return FALSE ;
}
V_97 = F_121 ( V_96 ) ;
if ( V_92 ) {
F_122 ( V_97 ) ;
} else {
F_123 ( V_97 ) ;
}
if ( F_124 ( V_96 , V_97 ) == 0 ) {
F_125 ( V_96 ) ;
F_125 ( V_97 ) ;
return FALSE ;
}
F_126 ( V_86 , & V_94 , V_97 ) ;
F_127 ( F_128 ( V_86 ) , & V_93 , & V_94 ) ;
F_125 ( V_96 ) ;
F_125 ( V_97 ) ;
return TRUE ;
}
T_19
F_129 ( T_29 * V_87 ) {
T_30 V_98 ;
T_28 * V_86 ;
T_31 * V_95 ;
T_32 * V_99 ;
T_7 * V_100 ;
T_19 V_101 ;
V_95 = F_118 ( V_87 ) ;
if ( ! F_119 ( V_95 , & V_86 , & V_98 ) ) {
return - 1 ;
}
V_99 = F_120 ( V_86 , & V_98 ) ;
if ( ! V_99 ) {
return FALSE ;
}
V_100 = F_130 ( V_99 ) ;
F_125 ( V_99 ) ;
V_101 = ( T_19 ) strtol ( V_100 , NULL , 10 ) ;
F_54 ( V_100 ) ;
return V_101 ;
}
void
F_131 ( T_1 * V_102 , ... )
{
T_33 V_103 ;
T_30 V_98 ;
T_34 * V_104 ;
va_start ( V_103 , V_102 ) ;
V_104 = F_128 ( F_132 ( F_114 ( V_102 ) ) ) ;
F_133 ( V_104 , & V_98 ) ;
F_134 ( V_104 , & V_98 , V_103 ) ;
va_end ( V_103 ) ;
}
T_1 *
F_135 ( T_19 V_105 , const T_7 * * V_106 ) {
T_1 * V_107 ;
int V_108 ;
T_34 * V_104 ;
T_35 * V_109 ;
T_36 * V_110 ;
F_112 ( V_105 <= 10 ) ;
V_104 = F_136 ( V_105 ,
V_111 , V_111 , V_111 , V_111 , V_111 ,
V_111 , V_111 , V_111 , V_111 , V_111 ) ;
V_107 = F_108 ( F_137 ( V_104 ) ) ;
F_138 ( F_16 ( V_104 ) ) ;
F_139 ( F_114 ( V_107 ) , ( V_106 != NULL ) ) ;
for( V_108 = 0 ; V_108 < V_105 ; V_108 ++ ) {
V_109 = F_140 () ;
V_110 = F_141 ( V_106 ? V_106 [ V_108 ] : L_17 , V_109 ,
L_18 , V_108 , NULL ) ;
F_142 ( V_110 , V_108 ) ;
F_143 ( F_114 ( V_107 ) , V_110 ) ;
}
return V_107 ;
}
void F_144 ( T_35 * V_112 )
{
F_145 ( V_112 , L_19 , L_20 , NULL ) ;
F_145 ( V_112 , L_21 , TRUE , NULL ) ;
F_145 ( V_112 , L_22 , V_113 , NULL ) ;
F_145 ( V_112 , L_23 , TRUE , NULL ) ;
}
void F_146 ( T_1 * V_102 , T_19 V_114 )
{
T_36 * V_115 ;
T_4 * V_116 ;
T_35 * V_117 ;
V_115 = F_147 ( F_114 ( V_102 ) , V_114 ) ;
V_116 = F_148 ( F_149 ( V_115 ) ) ;
if( V_116 != NULL ) {
V_117 = ( T_35 * ) V_116 -> T_3 ;
F_144 ( V_117 ) ;
F_150 ( V_116 ) ;
}
}
void
F_151 ( T_37 * V_118 )
{
T_38 * V_26 ;
V_26 = F_152 ( V_119 ) ;
F_153 ( V_26 , V_118 -> V_118 , - 1 ) ;
}
static
T_39 * F_154 ( const T_40 * T_3 , int V_120 )
{
T_39 * V_121 ;
F_112 ( V_120 > 0 ) ;
V_121 = F_155 ( T_39 , 1 ) ;
V_121 -> T_3 = F_155 ( T_40 , V_120 ) ;
V_121 -> V_120 = V_120 ;
memcpy ( V_121 -> T_3 , T_3 , V_120 * sizeof( T_40 ) ) ;
return V_121 ;
}
static void F_156 ( T_39 * V_121 ) {
F_54 ( V_121 -> T_3 ) ;
F_54 ( V_121 ) ;
}
static
void F_157 ( T_38 * T_41 V_2 , T_2 V_122 )
{
T_39 * V_121 ;
V_121 = V_122 ;
F_156 ( V_121 ) ;
}
static
void F_158 ( T_38 * T_41 V_2 , T_42 * V_123 , T_43 T_44 V_2 , T_2 V_122 )
{
T_39 * V_121 ;
V_121 = V_122 ;
F_159 ( V_123 , V_124 , 8 , V_121 -> T_3 , V_121 -> V_120 ) ;
}
void F_160 ( const T_40 * V_125 , int V_120 )
{
static T_45 V_126 [] = {
{ L_24 , 0 , 0 } } ;
T_38 * V_26 ;
T_39 * V_121 ;
T_9 V_127 ;
if( V_120 <= 0 ) {
return;
}
V_26 = F_152 ( V_119 ) ;
V_121 = F_154 ( V_125 , V_120 ) ;
V_127 = F_161 ( V_26 , V_126 , 1 ,
F_158 , F_157 , V_121 ) ;
if( ! V_127 ) {
F_156 ( V_121 ) ;
}
}
T_7 *
F_162 ( const T_7 * V_128 )
{
if ( V_128 == NULL )
return F_17 ( L_17 ) ;
if ( ( V_82 . V_129 == NULL ) || ( * V_82 . V_129 == '\0' ) )
return F_17 ( V_128 ) ;
return F_163 ( L_25 , V_128 , V_82 . V_129 ) ;
}
void
F_164 ( T_1 * V_1 , const T_7 * V_128 )
{
char * V_9 ;
char * V_130 ;
V_130 = F_165 ( & V_131 ) ;
V_9 = F_163 ( L_26 , V_128 , V_130 ) ;
F_54 ( V_130 ) ;
F_10 ( F_6 ( V_1 ) , V_9 ) ;
F_54 ( V_9 ) ;
}
static T_9
V_90 ( T_1 * V_87 , T_10 * V_21 , T_2 T_14 V_2 )
{
T_31 * V_132 ;
T_30 V_98 ;
T_30 V_50 ;
T_28 * V_86 ;
T_32 * V_99 ;
T_9 V_133 , V_134 ;
int V_135 = FALSE ;
V_132 = F_118 ( F_114 ( V_87 ) ) ;
if( ! V_132 ) {
return FALSE ;
}
if( ! F_119 ( V_132 , & V_86 , & V_98 ) ) {
return FALSE ;
}
V_99 = F_120 ( V_86 , & V_98 ) ;
if( ! V_99 ) {
return FALSE ;
}
V_133 = F_166 ( F_114 ( V_87 ) , V_99 ) ;
V_134 = F_167 ( V_86 , & V_98 ) ;
switch ( V_21 -> V_23 ) {
case V_136 :
if( V_133 ) {
F_168 ( F_114 ( V_87 ) , V_99 ) ;
V_135 = TRUE ;
break;
}
case V_137 :
if ( ! V_133 ) {
if( ! F_169 ( V_86 , & V_50 , & V_98 ) ) {
V_135 = FALSE ;
break;
}
F_125 ( V_99 ) ;
V_99 = F_120 ( V_86 , & V_50 ) ;
if( ! V_99 ) {
return FALSE ;
}
F_170 ( F_114 ( V_87 ) , V_99 ,
NULL ,
FALSE ) ;
V_135 = TRUE ;
break;
}
break;
case V_138 :
if ( V_134 ) {
F_171 ( F_114 ( V_87 ) , V_99 , FALSE ) ;
V_135 = TRUE ;
break;
} else {
V_135 = FALSE ;
break;
}
case V_139 :
case V_140 :
if ( V_133 )
F_168 ( F_114 ( V_87 ) , V_99 ) ;
else
F_171 ( F_114 ( V_87 ) , V_99 , FALSE ) ;
V_135 = TRUE ;
break;
}
if( V_99 ) {
F_125 ( V_99 ) ;
}
return V_135 ;
}
void
F_172 ( T_29 * V_141 )
{
T_19 V_142 ;
T_36 * V_110 ;
T_4 * V_143 , * V_102 ;
V_143 = F_173 ( F_114 ( V_141 ) ) ;
V_102 = V_143 ;
while( V_143 ) {
V_110 = V_143 -> T_3 ;
V_142 = F_174 ( V_110 ) ;
F_175 ( V_110 , V_144 ) ;
if ( V_142 > F_176 ( V_110 ) )
F_177 ( V_110 , V_142 ) ;
V_143 = F_178 ( V_143 ) ;
}
F_150 ( V_102 ) ;
F_179 ( V_141 , TRUE ) ;
}
T_19
F_180 ( T_1 * V_141 , const T_7 * V_118 )
{
T_46 * V_145 ;
T_19 V_146 ;
V_145 = F_181 ( V_141 , V_118 ) ;
F_182 ( V_145 ,
& V_146 ,
NULL ) ;
F_138 ( F_16 ( V_145 ) ) ;
return V_146 + ( F_183 ( F_184 () ) / V_147 ) ;
}
void
F_185 ( T_36 * V_110 V_2 ,
T_35 * V_109 ,
T_28 * V_86 ,
T_30 * V_98 ,
T_2 T_14 )
{
T_47 V_148 ;
T_7 V_149 [ 20 ] ;
char * V_150 ;
T_19 V_151 = F_186 ( T_14 ) ;
F_187 ( V_86 , V_98 , V_151 , & V_148 , - 1 ) ;
V_150 = setlocale ( V_152 , NULL ) ;
setlocale ( V_152 , L_27 ) ;
F_188 ( V_149 , sizeof( V_149 ) , L_28 , V_148 ) ;
setlocale ( V_152 , V_150 ) ;
F_145 ( V_109 , L_18 , V_149 , NULL ) ;
}
void
F_189 ( T_36 * V_110 V_2 ,
T_35 * V_109 ,
T_28 * V_86 ,
T_30 * V_98 ,
T_2 T_14 )
{
T_43 V_153 ;
T_7 V_149 [ 35 ] ;
T_19 V_114 = F_186 ( T_14 ) ;
F_187 ( V_86 , V_98 , V_114 , & V_153 , - 1 ) ;
F_188 ( V_149 , sizeof( V_149 ) , L_29 , V_153 ) ;
F_145 ( V_109 , L_18 , V_149 , NULL ) ;
}
void
F_190 ( T_36 * V_110 V_2 ,
T_35 * V_109 ,
T_28 * V_86 ,
T_30 * V_98 ,
T_2 T_14 )
{
T_48 V_153 ;
int V_108 = 0 ;
T_7 * V_154 ;
T_7 V_149 [ 35 ] ;
T_19 V_114 = F_186 ( T_14 ) ;
F_187 ( V_86 , V_98 , V_114 , & V_153 , - 1 ) ;
V_154 = & V_149 [ 34 ] ;
* V_154 = 0 ;
do {
* -- V_154 = ( T_7 ) ( V_153 % 10 ) + '0' ;
if ( ! ( ++ V_108 % 3 ) ) {
* -- V_154 = ' ' ;
}
} while ( ( V_153 /= 10 ) != 0 && V_154 > V_149 );
F_145 ( V_109 , L_18 , V_154 , NULL ) ;
}
void
F_191 ( T_36 * V_110 V_2 ,
T_35 * V_109 ,
T_28 * V_86 ,
T_30 * V_98 ,
T_2 T_14 )
{
const T_7 * V_118 = NULL ;
T_19 V_155 = F_186 ( T_14 ) ;
F_187 ( V_86 , V_98 , V_155 , & V_118 , - 1 ) ;
F_145 ( V_109 , L_18 , V_118 , NULL ) ;
}
T_19
F_192 ( T_28 * V_86 ,
T_30 * V_156 ,
T_30 * V_157 ,
T_2 T_14 )
{
const T_7 * V_158 = NULL ;
const T_7 * V_159 = NULL ;
T_19 V_127 = 0 ;
T_19 V_155 = F_186 ( T_14 ) ;
F_187 ( V_86 , V_156 , V_155 , & V_158 , - 1 ) ;
F_187 ( V_86 , V_157 , V_155 , & V_159 , - 1 ) ;
if ( V_158 == V_159 ) {
return 0 ;
}
else if ( V_158 == NULL || V_159 == NULL ) {
V_127 = ( V_158 == NULL ) ? - 1 : 1 ;
}
else {
V_127 = F_58 ( V_158 , V_159 ) ;
}
return V_127 ;
}
T_1 *
F_193 ( T_35 * * V_160 ) {
T_1 * V_161 ;
T_35 * V_112 ;
T_49 * V_104 ;
V_104 = F_194 ( 3 , V_111 , V_162 , V_163 ) ;
V_161 = F_195 ( F_137 ( V_104 ) ) ;
F_138 ( V_104 ) ;
V_112 = F_140 () ;
F_196 ( F_149 ( V_161 ) , V_112 , TRUE ) ;
F_197 ( F_149 ( V_161 ) , V_112 ,
L_18 , 0 , L_30 , 2 ,
NULL ) ;
if ( V_160 != NULL ) {
* V_160 = V_112 ;
}
return V_161 ;
}
T_1 *
F_198 ( void ) {
return F_193 ( NULL ) ;
}
void
F_199 ( T_50 * V_161 )
{
F_200 ( F_201 ( F_202 ( V_161 ) ) ) ;
}
T_30
F_203 ( T_50 * V_161 ,
T_30 * V_164 ,
const T_7 * V_165 ,
const T_2 V_166 ,
const T_9 V_167 )
{
T_30 V_98 ;
T_49 * V_104 ;
V_104 = F_201 ( F_202 ( V_161 ) ) ;
F_204 ( V_104 , & V_98 , V_164 ) ;
F_205 ( V_104 , & V_98 , 0 , V_165 , 1 , V_166 , 2 , V_167 , - 1 ) ;
return V_98 ;
}
T_30
F_206 ( T_50 * V_161 ,
const T_7 * V_165 ,
const T_2 V_166 )
{
return F_203 ( V_161 , NULL , V_165 , V_166 , TRUE ) ;
}
T_9
F_207 ( T_50 * V_161 , T_2 * V_166 )
{
T_49 * V_104 ;
T_30 V_98 ;
* V_166 = NULL ;
if ( F_208 ( V_161 , & V_98 ) ) {
V_104 = F_201 ( F_202 ( V_161 ) ) ;
F_187 ( F_137 ( V_104 ) , & V_98 ,
1 , V_166 , - 1 ) ;
return TRUE ;
}
return FALSE ;
}
T_19
F_209 ( T_50 * V_161 )
{
return F_210 ( V_161 ) ;
}
void
F_211 ( T_50 * V_161 , T_19 V_168 )
{
F_212 ( V_161 , V_168 ) ;
}
void
F_213 ( T_50 * V_161 , T_30 * V_98 )
{
F_214 ( V_161 , V_98 ) ;
}
static T_51
F_215 ( T_52 V_169 )
{
switch ( V_169 )
{
case V_170 :
return V_171 ;
case V_172 :
return V_173 ;
case V_174 :
default:
return V_175 ;
}
}
static T_53 *
F_216 ( T_53 * V_176 ,
T_52 V_169 ,
int V_177 ,
int V_178 ,
int V_31 ,
int V_32 )
{
T_53 * V_179 ;
T_54 * V_180 ;
V_179 = F_217 ( F_215 ( V_169 ) ,
V_31 ,
V_32 ) ;
V_180 = F_218 ( V_179 ) ;
F_219 ( V_180 , V_181 ) ;
F_220 ( V_180 , V_176 , - V_177 , - V_178 ) ;
F_221 ( V_180 ) ;
F_222 ( V_180 ) ;
return V_179 ;
}
static void
F_223 ( T_55 * V_182 ,
int V_183 ,
T_55 * V_184 ,
int V_185 ,
int V_177 ,
int V_178 ,
int V_31 ,
int V_32 )
{
int V_29 , V_30 ;
V_184 += V_185 * V_178 + V_177 * 4 ;
for ( V_30 = 0 ; V_30 < V_32 ; V_30 ++ ) {
T_56 * V_186 = ( T_56 * ) V_184 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
T_43 V_187 = V_186 [ V_29 ] >> 24 ;
if ( V_187 == 0 )
{
V_182 [ V_29 * 4 + 0 ] = 0 ;
V_182 [ V_29 * 4 + 1 ] = 0 ;
V_182 [ V_29 * 4 + 2 ] = 0 ;
}
else
{
V_182 [ V_29 * 4 + 0 ] = ( ( ( V_186 [ V_29 ] & 0xff0000 ) >> 16 ) * 255 + V_187 / 2 ) / V_187 ;
V_182 [ V_29 * 4 + 1 ] = ( ( ( V_186 [ V_29 ] & 0x00ff00 ) >> 8 ) * 255 + V_187 / 2 ) / V_187 ;
V_182 [ V_29 * 4 + 2 ] = ( ( ( V_186 [ V_29 ] & 0x0000ff ) >> 0 ) * 255 + V_187 / 2 ) / V_187 ;
}
V_182 [ V_29 * 4 + 3 ] = V_187 ;
}
V_184 += V_185 ;
V_182 += V_183 ;
}
}
static void
F_224 ( T_55 * V_182 ,
int V_183 ,
T_55 * V_184 ,
int V_185 ,
int V_177 ,
int V_178 ,
int V_31 ,
int V_32 )
{
int V_29 , V_30 ;
V_184 += V_185 * V_178 + V_177 * 4 ;
for ( V_30 = 0 ; V_30 < V_32 ; V_30 ++ ) {
T_56 * V_186 = ( T_56 * ) V_184 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
V_182 [ V_29 * 3 + 0 ] = V_186 [ V_29 ] >> 16 ;
V_182 [ V_29 * 3 + 1 ] = V_186 [ V_29 ] >> 8 ;
V_182 [ V_29 * 3 + 2 ] = V_186 [ V_29 ] ;
}
V_184 += V_185 ;
V_182 += V_183 ;
}
}
T_5 *
F_225 ( T_53 * V_176 ,
T_19 V_177 ,
T_19 V_178 ,
T_19 V_31 ,
T_19 V_32 )
{
T_52 V_169 ;
T_5 * V_188 ;
F_26 ( V_176 != NULL , NULL ) ;
F_26 ( V_31 > 0 && V_32 > 0 , NULL ) ;
V_169 = F_226 ( V_176 ) | V_170 ;
V_188 = F_227 ( V_189 ,
! ! ( V_169 & V_172 ) ,
8 ,
V_31 , V_32 ) ;
V_176 = F_216 ( V_176 , V_169 ,
V_177 , V_178 ,
V_31 , V_32 ) ;
F_228 ( V_176 ) ;
if ( F_229 ( V_176 ) || V_188 == NULL )
{
F_230 ( V_176 ) ;
return NULL ;
}
if ( F_231 ( V_188 ) )
F_223 ( F_232 ( V_188 ) ,
F_233 ( V_188 ) ,
F_234 ( V_176 ) ,
F_235 ( V_176 ) ,
0 , 0 ,
V_31 , V_32 ) ;
else
F_224 ( F_232 ( V_188 ) ,
F_233 ( V_188 ) ,
F_234 ( V_176 ) ,
F_235 ( V_176 ) ,
0 , 0 ,
V_31 , V_32 ) ;
F_230 ( V_176 ) ;
return V_188 ;
}
T_1 * F_236 ( T_57 V_190 , T_19 V_191 , T_9 V_192 )
{
#if ! F_38 ( 3 , 0 , 0 )
if ( V_190 == V_193 )
return F_237 ( V_192 , V_191 ) ;
else
return F_238 ( V_192 , V_191 ) ;
#else
T_1 * V_20 ;
V_20 = F_239 ( V_190 , V_191 ) ;
F_240 ( F_241 ( V_20 ) , V_192 ) ;
return V_20 ;
#endif
}
T_1 * F_242 ( T_57 V_190 )
{
if ( V_190 == V_193 ) {
return F_243 () ;
} else{
return F_244 () ;
}
}
T_1 * F_245 ( T_57 V_190 , T_27 * V_194 )
{
if ( V_190 == V_193 ) {
return F_246 ( V_194 ) ;
} else{
return F_247 ( V_194 ) ;
}
}
T_1 * F_248 ( T_57 V_190 )
{
if ( V_190 == V_193 ) {
return F_249 () ;
} else{
return F_250 () ;
}
}
T_1 * F_251 ( T_57 V_190 )
{
if ( V_190 == V_193 ) {
return F_252 () ;
} else{
return F_253 () ;
}
}
