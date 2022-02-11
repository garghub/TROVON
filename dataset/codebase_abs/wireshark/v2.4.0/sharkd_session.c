static void
F_1 ( char * V_1 )
{
char * V_2 = V_1 ;
while ( * V_1 )
{
char V_3 = * V_1 ++ ;
if ( V_3 == '\\' )
{
V_3 = * V_1 ++ ;
}
* V_2 = V_3 ;
V_2 ++ ;
}
* V_2 = '\0' ;
}
static const char *
F_2 ( const char * V_4 , const T_1 * V_5 , int V_6 , const char * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_6 ; V_8 += 2 )
{
const char * V_9 = & V_4 [ V_5 [ V_8 + 0 ] . V_10 ] ;
const char * V_11 = & V_4 [ V_5 [ V_8 + 1 ] . V_10 ] ;
if ( ! strcmp ( V_9 , V_7 ) )
return V_11 ;
}
return NULL ;
}
static void
F_3 ( const char * V_12 )
{
int V_8 ;
if ( V_12 == NULL )
V_12 = L_1 ;
putchar ( '"' ) ;
for ( V_8 = 0 ; V_12 [ V_8 ] ; V_8 ++ )
{
switch ( V_12 [ V_8 ] )
{
case '\\' :
case '"' :
putchar ( '\\' ) ;
putchar ( V_12 [ V_8 ] ) ;
break;
case '\n' :
putchar ( '\\' ) ;
putchar ( 'n' ) ;
break;
default:
putchar ( V_12 [ V_8 ] ) ;
break;
}
}
putchar ( '"' ) ;
}
static void
F_4 ( const T_2 * V_13 , int * V_14 , int * V_15 )
{
T_3 V_4 [ ( 1 / 3 + 1 ) * 4 + 4 + 1 ] ;
T_4 V_16 ;
if ( V_13 )
V_16 = F_5 ( V_13 , 1 , FALSE , V_4 , V_14 , V_15 ) ;
else
V_16 = F_6 ( FALSE , V_4 , V_14 , V_15 ) ;
if ( V_16 > 0 )
{
V_4 [ V_16 ] = '\0' ;
printf ( L_2 , V_4 ) ;
}
}
static void
F_7 ( const T_2 * V_13 , T_5 V_17 )
{
T_5 V_8 ;
int V_18 = 0 ;
int V_19 = 0 ;
putchar ( '"' ) ;
for ( V_8 = 0 ; V_8 < V_17 ; V_8 ++ )
F_4 ( & V_13 [ V_8 ] , & V_18 , & V_19 ) ;
F_4 ( NULL , & V_18 , & V_19 ) ;
putchar ( '"' ) ;
}
static const T_2 *
F_8 ( const char * V_20 )
{
struct V_21 * V_22 ;
for ( V_22 = V_23 ; V_22 ; V_22 = V_22 -> V_24 )
{
if ( ! strcmp ( V_22 -> V_20 , V_20 ) )
return V_22 -> V_25 ;
}
{
T_2 * V_25 = NULL ;
int V_26 = F_9 ( V_20 , & V_25 ) ;
if ( V_26 == - 1 )
return NULL ;
V_22 = (struct V_21 * ) F_10 ( sizeof( struct V_21 ) ) ;
V_22 -> V_20 = F_11 ( V_20 ) ;
V_22 -> V_25 = V_25 ;
V_22 -> V_24 = V_23 ;
V_23 = V_22 ;
return V_25 ;
}
}
static T_6
F_12 ( struct V_27 * V_28 , const char * V_29 )
{
T_6 V_26 = FALSE ;
char * * V_30 ;
V_30 = F_13 ( V_29 , L_3 , 7 ) ;
if ( F_14 ( V_30 ) != 5 )
goto V_31;
if ( ! F_15 ( V_30 [ 0 ] , & V_28 -> V_32 ) )
goto V_31;
if ( ! F_16 ( V_30 [ 1 ] , NULL , & V_28 -> V_33 ) )
goto V_31;
if ( ! F_15 ( V_30 [ 2 ] , & V_28 -> V_34 ) )
goto V_31;
if ( ! F_16 ( V_30 [ 3 ] , NULL , & V_28 -> V_35 ) )
goto V_31;
if ( ! F_17 ( V_30 [ 4 ] , NULL , & V_28 -> V_36 ) )
goto V_31;
F_18 ( & V_28 -> V_37 , V_38 , 4 , & V_28 -> V_32 ) ;
F_18 ( & V_28 -> V_39 , V_38 , 4 , & V_28 -> V_34 ) ;
V_26 = TRUE ;
V_31:
F_19 ( V_30 ) ;
return V_26 ;
}
static T_6
F_20 ( const struct V_27 * V_28 , const T_7 * V_40 , const struct V_41 * V_42 )
{
if ( V_42 -> V_43 == V_28 -> V_36 &&
V_40 -> V_44 == V_28 -> V_33 &&
V_40 -> V_45 == V_28 -> V_35 &&
F_21 ( & V_40 -> V_46 , & V_28 -> V_37 ) &&
F_21 ( & V_40 -> V_47 , & V_28 -> V_39 ) )
{
return TRUE ;
}
return FALSE ;
}
static T_6
F_22 ( const void * V_48 , void * V_49 , void * V_50 )
{
T_8 * V_51 = ( T_8 * ) V_49 ;
int * V_52 = ( int * ) V_50 ;
printf ( L_4 , ( * V_52 ) ? L_5 : L_1 ) ;
printf ( L_6 , V_51 -> V_53 ) ;
printf ( L_7 , ( const char * ) V_48 ) ;
printf ( L_8 ) ;
* V_52 = * V_52 + 1 ;
return FALSE ;
}
static T_6
F_23 ( const void * V_48 , void * V_49 , void * V_50 )
{
struct V_54 * V_55 = (struct V_54 * ) V_49 ;
int * V_52 = ( int * ) V_50 ;
const char * V_56 = ( const char * ) V_48 ;
if ( F_24 ( V_55 ) )
{
printf ( L_4 , ( * V_52 ) ? L_5 : L_1 ) ;
printf ( L_9 , V_56 ) ;
printf ( L_10 , V_56 ) ;
printf ( L_8 ) ;
* V_52 = * V_52 + 1 ;
}
if ( F_25 ( V_55 ) )
{
printf ( L_4 , ( * V_52 ) ? L_5 : L_1 ) ;
printf ( L_11 , V_56 ) ;
printf ( L_12 , V_56 ) ;
printf ( L_8 ) ;
* V_52 = * V_52 + 1 ;
}
return FALSE ;
}
static T_6
F_26 ( const void * V_48 V_57 , void * V_49 , void * V_58 )
{
T_9 * V_59 = ( T_9 * ) V_49 ;
int * V_52 = ( int * ) V_58 ;
const int V_60 = F_27 ( V_59 ) ;
const char * V_20 = F_28 ( V_60 ) ;
const char * V_56 = F_29 ( F_30 ( V_60 ) ) ;
printf ( L_4 , ( * V_52 ) ? L_5 : L_1 ) ;
printf ( L_13 , V_56 ) ;
printf ( L_14 , V_20 ) ;
printf ( L_8 ) ;
* V_52 = * V_52 + 1 ;
return FALSE ;
}
static T_6
F_31 ( const void * V_48 V_57 , void * V_49 , void * V_58 )
{
T_10 * V_61 = ( T_10 * ) V_49 ;
int * V_52 = ( int * ) V_58 ;
const int V_60 = F_32 ( V_61 ) ;
const char * V_20 = F_28 ( V_60 ) ;
const char * V_56 = F_29 ( F_30 ( V_60 ) ) ;
printf ( L_4 , ( * V_52 ) ? L_5 : L_1 ) ;
printf ( L_15 , V_56 ) ;
printf ( L_16 , V_20 ) ;
printf ( L_8 ) ;
* V_52 = * V_52 + 1 ;
return FALSE ;
}
static T_6
F_33 ( const void * V_48 V_57 , void * V_49 , void * V_58 )
{
T_11 * V_62 = ( T_11 * ) V_49 ;
int * V_52 = ( int * ) V_58 ;
const int V_60 = F_34 ( V_62 ) ;
const char * V_20 = F_28 ( V_60 ) ;
const char * V_56 = F_29 ( F_30 ( V_60 ) ) ;
printf ( L_4 , ( * V_52 ) ? L_5 : L_1 ) ;
printf ( L_17 , V_56 ) ;
printf ( L_18 , V_20 ) ;
printf ( L_8 ) ;
* V_52 = * V_52 + 1 ;
return FALSE ;
}
static T_6
F_35 ( const void * V_48 V_57 , void * V_49 , void * V_58 )
{
T_12 * V_63 = ( T_12 * ) V_49 ;
int * V_52 = ( int * ) V_58 ;
const int V_60 = F_36 ( V_63 ) ;
const char * V_56 = F_29 ( F_30 ( V_60 ) ) ;
const char * V_20 = V_56 ;
printf ( L_4 , ( * V_52 ) ? L_5 : L_1 ) ;
printf ( L_19 , V_56 ) ;
printf ( L_20 , V_20 ) ;
printf ( L_8 ) ;
* V_52 = * V_52 + 1 ;
return FALSE ;
}
static void
F_37 ( void )
{
int V_8 ;
printf ( L_21 ) ;
for ( V_8 = 0 ; V_8 < V_64 ; V_8 ++ )
{
const char * V_65 = F_38 ( V_8 ) ;
const char * V_66 = F_39 ( V_8 ) ;
printf ( L_4 , ( V_8 ) ? L_5 : L_1 ) ;
printf ( L_6 , V_66 ) ;
printf ( L_22 , V_65 ) ;
printf ( L_8 ) ;
}
printf ( L_23 ) ;
printf ( L_24 ) ;
{
T_13 * V_67 = F_40 () ;
T_13 * V_22 ;
const char * V_68 = L_1 ;
for ( V_22 = V_67 ; V_22 ; V_22 = V_22 -> V_24 )
{
T_14 * V_69 = ( T_14 * ) V_22 -> V_13 ;
printf ( L_4 , V_68 ) ;
printf ( L_6 , V_69 -> V_70 ) ;
printf ( L_25 , V_69 -> V_71 ) ;
printf ( L_8 ) ;
V_68 = L_5 ;
}
F_41 ( V_67 ) ;
}
printf ( L_23 ) ;
printf ( L_26 ) ;
for ( V_8 = 0 ; V_8 < V_72 ; V_8 ++ )
{
if ( V_8 )
printf ( L_5 ) ;
F_3 ( F_42 ( ( V_73 ) V_8 ) ) ;
}
printf ( L_23 ) ;
printf ( L_27 ) ;
F_3 ( F_43 () ) ;
printf ( L_28 ) ;
V_8 = 0 ;
F_44 ( F_22 , & V_8 ) ;
printf ( L_23 ) ;
printf ( L_29 ) ;
V_8 = 0 ;
F_45 ( F_23 , & V_8 ) ;
printf ( L_23 ) ;
printf ( L_30 ) ;
{
printf ( L_31 , L_32 , L_33 ) ;
printf ( L_34 , L_35 , L_36 ) ;
}
printf ( L_23 ) ;
printf ( L_37 ) ;
V_8 = 0 ;
F_46 ( F_26 , & V_8 ) ;
printf ( L_23 ) ;
printf ( L_38 ) ;
V_8 = 0 ;
F_47 ( F_31 , & V_8 ) ;
printf ( L_23 ) ;
printf ( L_39 ) ;
V_8 = 0 ;
F_48 ( F_33 , & V_8 ) ;
printf ( L_23 ) ;
printf ( L_40 ) ;
V_8 = 0 ;
F_49 ( F_35 , & V_8 ) ;
printf ( L_23 ) ;
printf ( L_41 ) ;
}
static void
F_50 ( const char * V_4 , const T_1 * V_5 , int V_6 )
{
const char * V_74 = F_2 ( V_4 , V_5 , V_6 , L_42 ) ;
int V_75 = 0 ;
fprintf ( V_76 , L_43 , V_74 ) ;
if ( ! V_74 )
return;
if ( F_51 ( V_74 , V_77 , FALSE , & V_75 ) != V_78 )
{
printf ( L_44 , V_75 ) ;
return;
}
F_52
{
V_75 = F_53 () ;
}
F_54 (OutOfMemoryError)
{
fprintf ( V_76 , L_45 ) ;
V_75 = V_79 ;
}
V_80 ;
printf ( L_44 , V_75 ) ;
}
static void
F_55 ( void )
{
printf ( L_46 , V_81 . V_6 ) ;
printf ( L_47 , F_56 ( & V_81 . V_82 ) ) ;
if ( V_81 . V_83 )
{
char * V_70 = F_57 ( V_81 . V_83 ) ;
printf ( L_48 ) ;
F_3 ( V_70 ) ;
F_58 ( V_70 ) ;
}
if ( V_81 . V_84 )
{
T_15 V_85 = F_59 ( V_81 . V_84 , NULL ) ;
if ( V_85 > 0 )
printf ( L_49 V_86 , V_85 ) ;
}
printf ( L_41 ) ;
}
static void
F_60 ( T_7 * V_52 , T_16 * V_87 , struct V_88 * V_89 , const T_17 * V_90 , void * V_13 )
{
struct V_91 * V_92 = (struct V_91 * ) V_13 ;
T_18 * V_93 = V_52 -> V_94 ;
( void ) V_87 ;
( void ) V_89 ;
( void ) V_90 ;
if ( V_92 -> V_95 == NULL || F_61 ( & V_93 -> V_96 , V_92 -> V_95 ) < 0 )
V_92 -> V_95 = & V_93 -> V_96 ;
if ( V_92 -> V_97 == NULL || F_61 ( & V_93 -> V_96 , V_92 -> V_97 ) > 0 )
V_92 -> V_97 = & V_93 -> V_96 ;
if ( V_52 -> V_98 )
{
T_19 * V_99 ;
for ( V_99 = F_62 ( V_52 -> V_98 ) ; V_99 ; V_99 = F_63 ( V_99 ) )
{
int V_60 = F_64 ( F_65 ( V_99 ) ) ;
if ( ! F_66 ( V_92 -> V_100 , F_67 ( V_60 ) , NULL , NULL ) )
{
F_68 ( V_92 -> V_100 , F_67 ( V_60 ) , F_67 ( V_60 ) ) ;
if ( F_69 ( V_92 -> V_100 ) != 1 )
printf ( L_5 ) ;
F_3 ( F_28 ( V_60 ) ) ;
}
}
}
}
static void
F_70 ( void )
{
unsigned int V_101 ;
struct V_91 V_92 ;
V_92 . V_95 = NULL ;
V_92 . V_97 = NULL ;
V_92 . V_100 = F_71 ( NULL , NULL ) ;
printf ( L_46 , V_81 . V_6 ) ;
printf ( L_50 ) ;
for ( V_101 = 1 ; V_101 <= V_81 . V_6 ; V_101 ++ )
F_72 ( V_101 , & F_60 , 0 , 0 , 0 , & V_92 ) ;
printf ( L_23 ) ;
if ( V_92 . V_95 )
printf ( L_51 , F_56 ( V_92 . V_95 ) ) ;
if ( V_92 . V_97 )
printf ( L_52 , F_56 ( V_92 . V_97 ) ) ;
printf ( L_41 ) ;
F_73 ( V_92 . V_100 ) ;
}
static void
F_74 ( const char * V_4 , const T_1 * V_5 , int V_6 )
{
const char * V_102 = F_2 ( V_4 , V_5 , V_6 , L_53 ) ;
const char * V_103 = F_2 ( V_4 , V_5 , V_6 , L_54 ) ;
const char * V_104 = F_2 ( V_4 , V_5 , V_6 , L_55 ) ;
const T_2 * V_105 = NULL ;
const char * V_106 = L_1 ;
int V_107 ;
T_20 V_101 ;
T_20 V_108 ;
T_20 V_109 ;
T_21 * V_89 = & V_81 . V_89 ;
if ( V_102 )
{
V_105 = F_8 ( V_102 ) ;
if ( ! V_105 )
return;
}
V_108 = 0 ;
if ( V_103 )
{
if ( ! F_75 ( V_103 , NULL , & V_108 ) )
return;
}
V_109 = 0 ;
if ( V_104 )
{
if ( ! F_75 ( V_104 , NULL , & V_109 ) )
return;
}
printf ( L_56 ) ;
for ( V_101 = 1 ; V_101 <= V_81 . V_6 ; V_101 ++ )
{
T_18 * V_93 = F_76 ( V_81 . V_110 , V_101 ) ;
if ( V_105 && ! ( V_105 [ V_101 / 8 ] & ( 1 << ( V_101 % 8 ) ) ) )
continue;
if ( V_108 )
{
V_108 -- ;
continue;
}
F_77 ( V_101 , V_89 , ( V_93 -> V_111 == NULL ) ) ;
printf ( L_57 , V_106 ) ;
for ( V_107 = 0 ; V_107 < V_89 -> V_112 ; ++ V_107 )
{
const T_22 * V_113 = & V_89 -> V_114 [ V_107 ] ;
if ( V_107 )
printf ( L_5 ) ;
F_3 ( V_113 -> V_115 ) ;
}
printf ( L_58 , V_101 ) ;
if ( V_93 -> V_116 . V_117 )
printf ( L_59 ) ;
if ( V_93 -> V_116 . V_118 )
printf ( L_60 ) ;
if ( V_93 -> V_111 )
{
printf ( L_61 , F_78 ( & V_93 -> V_111 -> V_119 ) ) ;
printf ( L_62 , F_78 ( & V_93 -> V_111 -> V_120 ) ) ;
}
printf ( L_8 ) ;
V_106 = L_5 ;
if ( V_109 && -- V_109 == 0 )
break;
}
printf ( L_63 ) ;
if ( V_89 != & V_81 . V_89 )
F_79 ( V_89 ) ;
}
static void
F_80 ( const T_23 * V_121 )
{
T_23 * V_122 ;
const char * V_68 = L_1 ;
printf ( L_56 ) ;
for ( V_122 = V_121 -> V_123 ; V_122 ; V_122 = V_122 -> V_24 )
{
printf ( L_64 , V_68 , V_122 -> V_70 ) ;
printf ( L_65 , V_122 -> V_124 ) ;
if ( V_122 -> V_124 && ( ( V_122 -> V_125 & V_126 ) || V_122 -> V_127 ) )
{
printf ( L_66 , ( ( float ) V_122 -> V_128 ) / V_122 -> V_124 ) ;
printf ( L_67 , V_122 -> V_129 ) ;
printf ( L_68 , V_122 -> V_130 ) ;
}
if ( V_122 -> V_131 -> V_132 )
printf ( L_69 , ( ( float ) V_122 -> V_124 ) / V_122 -> V_131 -> V_132 ) ;
if ( V_122 -> V_133 && V_122 -> V_133 -> V_124 )
printf ( L_70 , ( V_122 -> V_124 * 100.0 ) / V_122 -> V_133 -> V_124 ) ;
else if ( V_122 -> V_133 == & ( V_122 -> V_131 -> V_134 ) )
printf ( L_71 ) ;
if ( V_135 . V_136 && V_122 -> V_137 )
{
if ( V_135 . V_138 )
printf ( L_72 , V_122 -> V_137 ) ;
else
printf ( L_73 , ( ( double ) V_122 -> V_137 ) / V_135 . V_139 ) ;
printf ( L_74 , ( ( double ) V_122 -> V_140 / 1000.0 ) ) ;
}
if ( V_122 -> V_123 )
{
printf ( L_75 ) ;
F_80 ( V_122 ) ;
}
printf ( L_8 ) ;
V_68 = L_5 ;
}
printf ( L_23 ) ;
}
static void
F_81 ( void * V_141 )
{
T_24 * V_131 = ( T_24 * ) V_141 ;
printf ( L_76 , V_131 -> V_69 -> V_71 ) ;
printf ( L_77 , V_131 -> V_69 -> V_70 ) ;
F_80 ( & V_131 -> V_134 ) ;
printf ( L_78 ) ;
}
static void
F_82 ( void * V_141 )
{
T_24 * V_131 = ( T_24 * ) V_141 ;
F_83 ( V_131 ) ;
}
static void
F_84 ( void * V_142 )
{
struct V_143 * V_144 = (struct V_143 * ) V_142 ;
T_17 * V_145 ;
const char * V_68 = L_1 ;
printf ( L_79 , L_36 , L_36 ) ;
printf ( L_80 ) ;
for ( V_145 = V_144 -> V_146 ; V_145 ; V_145 = V_145 -> V_24 )
{
T_25 * V_147 = ( T_25 * ) V_145 -> V_13 ;
const char * V_148 ;
printf ( L_4 , V_68 ) ;
printf ( L_81 , V_147 -> V_149 ) ;
V_148 = F_85 ( V_147 -> V_150 , V_151 ) ;
if ( V_148 )
printf ( L_82 , V_148 ) ;
V_148 = F_85 ( V_147 -> V_152 , V_153 ) ;
if ( V_148 )
printf ( L_83 , V_148 ) ;
printf ( L_84 ) ;
F_3 ( V_147 -> V_154 ) ;
printf ( L_5 ) ;
if ( V_147 -> V_155 )
{
printf ( L_85 ) ;
F_3 ( V_147 -> V_155 ) ;
}
printf ( L_8 ) ;
V_68 = L_5 ;
}
printf ( L_23 ) ;
printf ( L_78 ) ;
}
static T_6
F_86 ( void * V_142 , T_7 * V_40 V_57 , T_26 * T_27 V_57 , const void * V_156 )
{
struct V_143 * V_144 = (struct V_143 * ) V_142 ;
T_25 * V_147 = ( T_25 * ) V_156 ;
V_147 = ( T_25 * ) F_87 ( V_147 , sizeof( * V_147 ) ) ;
V_147 -> V_155 = F_88 ( V_144 -> V_157 , V_147 -> V_155 ) ;
V_147 -> V_154 = F_88 ( V_144 -> V_157 , V_147 -> V_154 ) ;
V_144 -> V_146 = F_89 ( V_144 -> V_146 , V_147 ) ;
return TRUE ;
}
static void
F_90 ( void * V_142 )
{
struct V_143 * V_144 = (struct V_143 * ) V_142 ;
F_91 ( V_144 -> V_146 , F_58 ) ;
F_92 ( V_144 -> V_157 ) ;
F_58 ( V_144 ) ;
}
static int
F_93 ( T_28 * V_158 , const char * V_159 )
{
int V_160 = 0 ;
( void ) V_158 ;
( void ) V_159 ;
#ifdef F_94
if ( V_158 -> type == V_38 )
{
T_20 V_161 = F_95 ( V_158 -> V_13 ) ;
T_29 V_162 = F_96 () ;
T_29 V_163 ;
for ( V_163 = 0 ; V_163 < V_162 ; V_163 ++ )
{
const char * V_164 = NULL ;
char * V_165 ;
int V_166 = F_97 ( V_163 ) ;
switch ( V_166 )
{
case V_167 :
V_164 = L_86 ;
break;
case V_168 :
case V_169 :
V_164 = L_87 ;
break;
case V_170 :
V_164 = L_88 ;
break;
case V_171 :
V_164 = L_89 ;
break;
case V_172 :
V_164 = L_90 ;
break;
case V_173 :
V_164 = L_91 ;
break;
case V_174 :
V_164 = L_92 ;
break;
}
if ( V_164 && ( V_165 = F_98 ( V_163 , V_161 , NULL ) ) )
{
printf ( L_93 , V_164 , V_159 ) ;
F_3 ( V_165 ) ;
V_160 = 1 ;
}
}
}
#ifdef F_99
if ( V_158 -> type == V_175 )
{
const struct V_176 * V_177 = ( const struct V_176 * ) V_158 -> V_13 ;
T_29 V_162 = F_96 () ;
T_29 V_163 ;
for ( V_163 = 0 ; V_163 < V_162 ; V_163 ++ )
{
const char * V_164 = NULL ;
char * V_165 ;
int V_166 = F_97 ( V_163 ) ;
switch ( V_166 )
{
case V_178 :
V_164 = L_86 ;
break;
#if V_179 > 31
case V_180 :
case V_181 :
V_164 = L_87 ;
break;
case V_182 :
V_164 = L_88 ;
break;
case V_183 :
V_164 = L_89 ;
break;
case V_184 :
V_164 = L_90 ;
break;
#endif
case V_173 :
V_164 = L_91 ;
break;
case V_174 :
V_164 = L_92 ;
break;
}
if ( V_164 && ( V_165 = F_100 ( V_163 , * V_177 , NULL ) ) )
{
printf ( L_93 , V_164 , V_159 ) ;
F_3 ( V_165 ) ;
V_160 = 1 ;
}
}
}
#endif
#endif
return V_160 ;
}
static void
F_101 ( void * V_142 )
{
struct V_185 * V_186 = (struct V_185 * ) V_142 ;
F_91 ( V_186 -> V_187 , F_58 ) ;
F_58 ( V_186 ) ;
}
static T_6
F_102 ( void * V_142 , T_7 * V_40 , T_26 * T_27 V_57 , const void * V_156 )
{
struct V_185 * V_186 = (struct V_185 * ) V_142 ;
const struct V_41 * V_188 = ( const struct V_41 * ) V_156 ;
if ( F_20 ( & V_186 -> V_189 , V_40 , V_188 ) )
{
T_30 * V_190 = & ( V_186 -> V_190 ) ;
struct V_191 * V_192 ;
F_103 ( V_190 , V_40 , V_188 ) ;
V_192 = (struct V_191 * ) F_10 ( sizeof( struct V_191 ) ) ;
if ( ! V_186 -> V_187 )
V_186 -> V_193 = F_56 ( & V_40 -> V_96 ) ;
V_192 -> V_194 = V_40 -> V_195 ;
V_192 -> V_196 = V_188 -> V_197 ;
V_192 -> V_198 = ( V_190 -> V_116 & V_199 ) ? 0.0 : V_190 -> V_198 ;
V_192 -> V_200 = ( V_190 -> V_116 & V_199 ) ? 0.0 : V_190 -> V_200 ;
V_192 -> V_201 = ( V_190 -> V_116 & V_199 ) ? 0.0 : V_190 -> V_201 ;
V_192 -> V_202 = V_190 -> V_202 ;
V_192 -> V_203 = V_188 -> V_204 ? TRUE : FALSE ;
V_192 -> V_205 = F_56 ( & V_40 -> V_96 ) - V_186 -> V_193 ;
V_192 -> V_116 = V_190 -> V_116 ;
V_192 -> V_206 = V_190 -> V_206 ;
V_186 -> V_187 = F_104 ( V_186 -> V_187 , V_192 ) ;
}
return TRUE ;
}
static void
F_105 ( void * V_142 )
{
const int V_207 = 1 ;
const int V_208 = 2 ;
const int V_209 = 3 ;
const int V_210 = 4 ;
const struct V_185 * V_186 = (struct V_185 * ) V_142 ;
const T_30 * V_190 = & V_186 -> V_190 ;
const char * V_68 = L_1 ;
T_17 * V_22 ;
printf ( L_94 , V_186 -> V_211 ) ;
printf ( L_95 , V_186 -> V_189 . V_36 ) ;
printf ( L_96 , V_190 -> V_212 ) ;
printf ( L_97 , V_190 -> V_213 ) ;
printf ( L_98 , V_190 -> V_214 ) ;
printf ( L_99 , V_190 -> V_215 ) ;
printf ( L_100 , V_190 -> V_216 ) ;
printf ( L_101 , V_190 -> V_217 ) ;
printf ( L_102 , V_190 -> V_218 ) ;
printf ( L_103 , V_190 -> time - V_190 -> V_193 ) ;
printf ( L_104 ) ;
for ( V_22 = V_186 -> V_187 ; V_22 ; V_22 = V_22 -> V_24 )
{
struct V_191 * V_192 = (struct V_191 * ) V_22 -> V_13 ;
printf ( L_4 , V_68 ) ;
printf ( L_105 , V_192 -> V_194 ) ;
printf ( L_106 , V_192 -> V_205 ) ;
printf ( L_107 , V_192 -> V_196 ) ;
printf ( L_108 , V_192 -> V_198 ) ;
printf ( L_109 , V_192 -> V_200 ) ;
printf ( L_110 , V_192 -> V_201 ) ;
printf ( L_111 , V_192 -> V_202 ) ;
if ( V_192 -> V_206 == V_219 )
printf ( L_112 , L_113 , V_207 ) ;
else if ( V_192 -> V_206 == V_220 )
printf ( L_112 , L_114 , V_207 ) ;
else if ( V_192 -> V_116 & V_221 )
printf ( L_112 , L_115 , V_208 ) ;
else if ( V_192 -> V_116 & V_222 )
printf ( L_112 , L_116 , V_209 ) ;
else if ( V_192 -> V_116 & V_223 )
printf ( L_117 ,
V_192 -> V_206 ,
( V_192 -> V_116 & V_224 ) ? L_118 : L_1 ,
V_209 ) ;
else if ( V_192 -> V_116 & V_225 )
printf ( L_112 , L_119 , V_209 ) ;
else if ( ( V_192 -> V_116 & V_226 )
&& ! ( V_192 -> V_116 & V_199 )
&& ! ( V_192 -> V_116 & V_227 )
&& ( V_192 -> V_116 & V_228 )
&& ! ( V_192 -> V_116 & V_229 ) )
{
printf ( L_112 , L_120 , V_209 ) ;
}
else if ( V_192 -> V_116 & V_224 )
printf ( L_121 , V_192 -> V_206 , V_210 ) ;
else if ( V_192 -> V_116 & V_229 )
printf ( L_122 , V_209 ) ;
if ( V_192 -> V_203 )
printf ( L_123 ) ;
printf ( L_8 ) ;
V_68 = L_5 ;
}
printf ( L_23 ) ;
printf ( L_78 ) ;
}
static void
F_106 ( void * V_230 )
{
T_31 * V_231 = ( T_31 * ) V_230 ;
const struct V_232 * V_233 = (struct V_232 * ) V_231 -> V_58 ;
const char * V_234 ;
int V_235 ;
T_29 V_8 ;
int V_160 = 0 ;
if ( ! strncmp ( V_233 -> type , L_124 , 5 ) )
{
printf ( L_125 , V_233 -> type ) ;
printf ( L_29 ) ;
V_234 = V_233 -> type + 5 ;
}
else if ( ! strncmp ( V_233 -> type , L_126 , 6 ) )
{
printf ( L_127 , V_233 -> type ) ;
printf ( L_128 ) ;
V_234 = V_233 -> type + 6 ;
}
else
{
printf ( L_129 , V_233 -> type ) ;
V_234 = L_1 ;
}
V_235 = ( ! strcmp ( V_234 , L_130 ) || ! strcmp ( V_234 , L_131 ) || ! strcmp ( V_234 , L_132 ) ) ;
if ( V_233 -> V_231 . V_236 != NULL && ! strncmp ( V_233 -> type , L_124 , 5 ) )
{
for ( V_8 = 0 ; V_8 < V_233 -> V_231 . V_236 -> V_17 ; V_8 ++ )
{
T_32 * V_237 = & F_107 ( V_233 -> V_231 . V_236 , T_32 , V_8 ) ;
char * V_37 , * V_39 ;
char * V_33 , * V_35 ;
char * V_238 ;
printf ( L_4 , V_8 ? L_5 : L_1 ) ;
printf ( L_133 , ( V_37 = F_108 ( NULL , & V_237 -> V_239 , V_233 -> V_240 ) ) ) ;
printf ( L_134 , ( V_39 = F_108 ( NULL , & V_237 -> V_241 , V_233 -> V_240 ) ) ) ;
if ( V_235 )
{
printf ( L_135 , ( V_33 = F_109 ( NULL , V_237 -> V_33 , V_237 -> V_242 , V_233 -> V_243 ) ) ) ;
printf ( L_136 , ( V_35 = F_109 ( NULL , V_237 -> V_35 , V_237 -> V_242 , V_233 -> V_243 ) ) ) ;
F_110 ( NULL , V_33 ) ;
F_110 ( NULL , V_35 ) ;
}
printf ( L_137 V_244 , V_237 -> V_245 ) ;
printf ( L_138 V_244 , V_237 -> V_246 ) ;
printf ( L_139 V_244 , V_237 -> V_247 ) ;
printf ( L_140 V_244 , V_237 -> V_248 ) ;
printf ( L_141 , F_56 ( & V_237 -> V_193 ) ) ;
printf ( L_142 , F_56 ( & V_237 -> V_249 ) ) ;
V_238 = F_111 ( V_237 , V_250 ) ;
if ( V_238 )
{
printf ( L_143 , V_238 ) ;
F_58 ( V_238 ) ;
}
F_110 ( NULL , V_37 ) ;
F_110 ( NULL , V_39 ) ;
if ( F_93 ( & ( V_237 -> V_239 ) , L_144 ) )
V_160 = 1 ;
if ( F_93 ( & ( V_237 -> V_241 ) , L_145 ) )
V_160 = 1 ;
printf ( L_8 ) ;
}
}
else if ( V_233 -> V_231 . V_236 != NULL && ! strncmp ( V_233 -> type , L_126 , 6 ) )
{
for ( V_8 = 0 ; V_8 < V_233 -> V_231 . V_236 -> V_17 ; V_8 ++ )
{
T_33 * V_251 = & F_107 ( V_233 -> V_231 . V_236 , T_33 , V_8 ) ;
char * V_252 , * V_253 ;
char * V_238 ;
printf ( L_4 , V_8 ? L_5 : L_1 ) ;
printf ( L_146 , ( V_252 = F_108 ( NULL , & V_251 -> V_254 , V_233 -> V_240 ) ) ) ;
if ( V_235 )
{
printf ( L_147 , ( V_253 = F_109 ( NULL , V_251 -> V_255 , V_251 -> V_242 , V_233 -> V_243 ) ) ) ;
F_110 ( NULL , V_253 ) ;
}
printf ( L_137 V_244 , V_251 -> V_245 ) ;
printf ( L_138 V_244 , V_251 -> V_246 ) ;
printf ( L_139 V_244 , V_251 -> V_247 ) ;
printf ( L_140 V_244 , V_251 -> V_248 ) ;
V_238 = F_112 ( V_251 ) ;
if ( V_238 )
{
printf ( L_143 , V_238 ) ;
F_58 ( V_238 ) ;
}
F_110 ( NULL , V_252 ) ;
if ( F_93 ( & ( V_251 -> V_254 ) , L_1 ) )
V_160 = 1 ;
printf ( L_8 ) ;
}
}
printf ( L_148 , V_234 , V_160 ? L_149 : L_150 ) ;
}
static void
F_113 ( void * V_230 )
{
T_31 * V_231 = ( T_31 * ) V_230 ;
struct V_232 * V_233 = (struct V_232 * ) V_231 -> V_58 ;
if ( ! strncmp ( V_233 -> type , L_124 , 5 ) )
{
F_114 ( V_231 ) ;
}
else if ( ! strncmp ( V_233 -> type , L_126 , 6 ) )
{
F_115 ( V_231 ) ;
}
F_58 ( V_233 ) ;
}
static void
F_116 ( void * V_230 )
{
T_34 * V_256 = ( T_34 * ) V_230 ;
T_29 V_8 , V_257 , V_258 ;
printf ( L_151 , V_256 -> V_259 -> V_260 ) ;
printf ( L_152 ) ;
for ( V_8 = 0 ; V_8 < V_256 -> V_259 -> V_261 ; V_8 ++ )
{
T_35 * V_262 = & ( V_256 -> V_259 -> V_263 [ V_8 ] ) ;
if ( V_8 )
printf ( L_5 ) ;
printf ( L_153 ) ;
printf ( L_154 ) ;
F_3 ( V_262 -> V_264 ) ;
printf ( L_8 ) ;
}
printf ( L_23 ) ;
printf ( L_155 ) ;
for ( V_8 = 0 ; V_8 < V_256 -> V_259 -> V_265 -> V_17 ; V_8 ++ )
{
T_36 * V_55 = F_107 ( V_256 -> V_259 -> V_265 , T_36 * , V_8 ) ;
const char * V_68 = L_1 ;
if ( V_8 )
printf ( L_5 ) ;
printf ( L_153 ) ;
printf ( L_156 ) ;
printf ( L_157 , V_55 -> V_53 ) ;
printf ( L_158 ) ;
for ( V_257 = 0 ; V_257 < V_55 -> V_266 ; V_257 ++ )
{
T_37 * V_267 ;
V_267 = F_117 ( V_55 , V_257 , 0 ) ;
if ( V_267 == NULL || V_267 -> type == V_268 )
continue;
printf ( L_159 , V_68 ) ;
for ( V_258 = 0 ; V_258 < V_55 -> V_269 ; V_258 ++ )
{
V_267 = F_117 ( V_55 , V_257 , V_258 ) ;
if ( V_258 )
printf ( L_5 ) ;
switch ( V_267 -> type )
{
case V_270 :
printf ( L_160 , V_267 -> V_49 . V_271 ) ;
break;
case V_272 :
printf ( L_161 , V_267 -> V_49 . V_271 ) ;
break;
case V_273 :
F_3 ( V_267 -> V_49 . V_274 ) ;
break;
case V_275 :
printf ( L_162 , V_267 -> V_49 . V_276 ) ;
break;
case V_277 :
printf ( L_161 , V_267 -> V_49 . V_278 ) ;
break;
case V_268 :
printf ( L_163 ) ;
break;
}
}
printf ( L_23 ) ;
V_68 = L_5 ;
}
printf ( L_23 ) ;
printf ( L_8 ) ;
}
printf ( L_164 ) ;
}
static void
F_118 ( void * V_230 )
{
T_34 * V_256 = ( T_34 * ) V_230 ;
F_119 ( V_256 -> V_259 , NULL , NULL ) ;
}
static void
F_120 ( void * V_230 )
{
T_38 * V_279 = ( T_38 * ) V_230 ;
T_11 * V_62 = ( T_11 * ) V_279 -> V_58 ;
T_29 V_8 , V_257 ;
const char * V_20 = F_28 ( F_34 ( V_62 ) ) ;
const T_39 * V_280 = F_121 ( V_62 ) ;
const char * V_68 = L_1 ;
printf ( L_165 , V_20 ) ;
if ( V_279 -> V_281 . V_282 == 1 )
{
const T_40 * V_283 = & V_279 -> V_281 . V_284 [ 0 ] ;
printf ( L_166 , V_283 -> V_285 ) ;
printf ( L_167 , V_283 -> V_286 ) ;
printf ( L_168 , V_283 -> V_287 ) ;
printf ( L_169 , V_283 -> V_288 ) ;
}
printf ( L_24 ) ;
for ( V_8 = 0 ; V_8 < V_279 -> V_281 . V_282 ; V_8 ++ )
{
const T_40 * V_283 = & V_279 -> V_281 . V_284 [ V_8 ] ;
for ( V_257 = 0 ; V_257 < V_283 -> V_289 ; V_257 ++ )
{
const char * V_290 ;
if ( V_283 -> V_62 [ V_257 ] . V_195 == 0 )
continue;
printf ( L_4 , V_68 ) ;
if ( V_279 -> V_281 . V_282 == 1 )
V_290 = F_122 ( V_257 , V_280 , L_170 ) ;
else
V_290 = F_122 ( V_8 , V_280 , L_170 ) ;
printf ( L_171 ) ;
F_3 ( V_290 ) ;
printf ( L_172 , V_283 -> V_62 [ V_257 ] . V_195 ) ;
printf ( L_173 , F_56 ( & ( V_283 -> V_62 [ V_257 ] . V_291 ) ) ) ;
printf ( L_174 , F_56 ( & ( V_283 -> V_62 [ V_257 ] . V_292 ) ) ) ;
printf ( L_175 , F_56 ( & ( V_283 -> V_62 [ V_257 ] . V_293 ) ) ) ;
printf ( L_176 , V_283 -> V_62 [ V_257 ] . V_294 ) ;
printf ( L_177 , V_283 -> V_62 [ V_257 ] . V_295 ) ;
if ( V_279 -> V_281 . V_282 != 1 )
{
printf ( L_166 , V_283 -> V_285 ) ;
printf ( L_167 , V_283 -> V_286 ) ;
printf ( L_168 , V_283 -> V_287 ) ;
printf ( L_169 , V_283 -> V_288 ) ;
}
printf ( L_8 ) ;
V_68 = L_5 ;
}
}
printf ( L_164 ) ;
}
static void
F_123 ( void * V_230 )
{
T_38 * V_279 = ( T_38 * ) V_230 ;
F_124 ( & V_279 -> V_281 , NULL , NULL ) ;
F_58 ( V_279 ) ;
}
static void
F_125 ( void * V_230 )
{
T_41 * V_296 = ( T_41 * ) V_230 ;
T_10 * V_61 = ( T_10 * ) V_296 -> V_58 ;
const char * V_20 = F_28 ( F_32 ( V_61 ) ) ;
T_29 V_8 ;
printf ( L_178 , V_20 ) ;
printf ( L_155 ) ;
for ( V_8 = 0 ; V_8 < V_296 -> V_297 -> V_17 ; V_8 ++ )
{
T_42 * V_298 = F_107 ( V_296 -> V_297 , T_42 * , V_8 ) ;
const char * V_68 = L_1 ;
int V_257 ;
if ( V_8 )
printf ( L_5 ) ;
printf ( L_153 ) ;
printf ( L_179 ) ;
if ( V_298 -> V_70 )
F_3 ( V_298 -> V_70 ) ;
else if ( V_298 -> V_299 )
F_3 ( V_298 -> V_299 ) ;
else
printf ( L_180 , V_8 ) ;
if ( V_298 -> V_300 )
{
printf ( L_181 ) ;
F_3 ( V_298 -> V_300 ) ;
}
if ( V_298 -> V_301 )
{
printf ( L_182 ) ;
F_3 ( V_298 -> V_301 ) ;
}
printf ( L_183 ) ;
for ( V_257 = 0 ; V_257 < V_298 -> V_302 ; V_257 ++ )
{
T_43 * V_303 = & V_298 -> V_304 [ V_257 ] ;
if ( V_303 -> V_305 . V_195 == 0 )
continue;
printf ( L_4 , V_68 ) ;
printf ( L_179 ) ;
F_3 ( V_303 -> V_306 ) ;
if ( V_298 -> V_300 )
printf ( L_184 , V_303 -> V_307 ) ;
printf ( L_172 , V_303 -> V_305 . V_195 ) ;
printf ( L_173 , F_56 ( & V_303 -> V_305 . V_291 ) ) ;
printf ( L_174 , F_56 ( & V_303 -> V_305 . V_292 ) ) ;
printf ( L_175 , F_56 ( & V_303 -> V_305 . V_293 ) ) ;
printf ( L_8 ) ;
V_68 = L_5 ;
}
printf ( L_185 ) ;
}
printf ( L_164 ) ;
}
static void
F_126 ( void * V_230 )
{
T_41 * V_296 = ( T_41 * ) V_230 ;
T_10 * V_61 = ( T_10 * ) V_296 -> V_58 ;
F_127 ( V_61 , V_296 -> V_297 , NULL , NULL ) ;
F_128 ( V_296 -> V_297 , TRUE ) ;
F_58 ( V_296 ) ;
}
static void
F_129 ( void * V_142 )
{
T_44 * V_308 = ( T_44 * ) V_142 ;
struct V_309 * V_310 = (struct V_309 * ) V_308 -> V_311 ;
T_17 * V_312 ;
int V_8 = 0 ;
printf ( L_186 , V_310 -> type ) ;
printf ( L_187 , V_310 -> V_234 ) ;
printf ( L_188 ) ;
for ( V_312 = V_310 -> V_313 ; V_312 ; V_312 = V_312 -> V_24 )
{
const T_45 * V_314 = ( T_45 * ) V_312 -> V_13 ;
printf ( L_4 , V_8 ? L_5 : L_1 ) ;
printf ( L_189 , V_314 -> V_315 ) ;
if ( V_314 -> V_316 )
{
printf ( L_190 ) ;
F_3 ( V_314 -> V_316 ) ;
}
if ( V_314 -> V_317 )
{
printf ( L_191 ) ;
F_3 ( V_314 -> V_317 ) ;
}
if ( V_314 -> V_83 )
{
printf ( L_48 ) ;
F_3 ( V_314 -> V_83 ) ;
}
printf ( L_192 , V_310 -> type , V_8 ) ;
printf ( L_193 V_86 , V_314 -> V_318 ) ;
printf ( L_8 ) ;
V_8 ++ ;
}
printf ( L_164 ) ;
}
static void
F_130 ( void * V_311 , T_45 * V_319 )
{
struct V_309 * V_310 = (struct V_309 * ) V_311 ;
V_310 -> V_313 = F_104 ( V_310 -> V_313 , V_319 ) ;
}
static T_45 *
F_131 ( void * V_311 , int V_320 )
{
struct V_309 * V_310 = (struct V_309 * ) V_311 ;
return ( T_45 * ) F_132 ( V_310 -> V_313 , V_320 ) ;
}
static void
F_133 ( void * V_230 )
{
T_46 * V_321 = ( T_46 * ) V_230 ;
T_13 * V_322 ;
const char * V_68 = L_1 ;
printf ( L_79 , L_33 , L_33 ) ;
printf ( L_194 ) ;
for ( V_322 = F_134 ( V_321 -> V_323 ) ; V_322 ; V_322 = V_322 -> V_24 )
{
T_47 * V_324 = ( T_47 * ) V_322 -> V_13 ;
char * V_37 , * V_39 ;
char * V_325 ;
T_20 V_326 ;
V_37 = F_135 ( NULL , & ( V_324 -> V_37 ) ) ;
V_39 = F_135 ( NULL , & ( V_324 -> V_327 ) ) ;
if ( V_324 -> V_328 != NULL )
V_325 = F_136 ( NULL , V_324 -> V_328 ) ;
else
V_325 = F_137 ( NULL , V_324 -> V_329 , & V_330 , L_195 ) ;
printf ( L_196 , V_68 , V_324 -> V_36 ) ;
printf ( L_197 , V_325 ) ;
printf ( L_198 , V_37 ) ;
printf ( L_199 , V_324 -> V_33 ) ;
printf ( L_134 , V_39 ) ;
printf ( L_200 , V_324 -> V_331 ) ;
printf ( L_201 , V_324 -> V_332 ) ;
printf ( L_96 , V_324 -> V_333 . V_212 ) ;
printf ( L_98 , V_324 -> V_333 . V_214 ) ;
printf ( L_99 , V_324 -> V_333 . V_215 ) ;
V_326 = ( V_324 -> V_333 . V_334 + V_324 -> V_333 . V_335 * 65536 ) - V_324 -> V_333 . V_336 + 1 ;
printf ( L_202 , V_326 ) ;
printf ( L_203 , V_324 -> V_333 . V_217 ) ;
printf ( L_204 , V_324 -> V_337 ? L_149 : L_150 ) ;
printf ( L_205 , ( V_324 -> V_37 . type == V_175 ) ? 6 : 4 ) ;
F_110 ( NULL , V_37 ) ;
F_110 ( NULL , V_39 ) ;
F_110 ( NULL , V_325 ) ;
printf ( L_8 ) ;
V_68 = L_5 ;
}
printf ( L_164 ) ;
}
static void
F_138 ( char * V_4 , const T_1 * V_5 , int V_6 )
{
void * V_338 [ 16 ] ;
T_48 V_339 [ 16 ] ;
int V_340 = 0 ;
int V_8 ;
T_46 V_321 =
{ NULL , NULL , NULL , NULL , 0 , NULL , 0 , V_341 , NULL , NULL , NULL , FALSE } ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ )
{
char V_342 [ 32 ] ;
const char * V_343 ;
void * V_344 = NULL ;
T_48 V_345 = NULL ;
const char * V_346 = L_1 ;
T_49 * V_347 = NULL ;
F_139 ( V_342 , sizeof( V_342 ) , L_206 , V_8 ) ;
V_343 = F_2 ( V_4 , V_5 , V_6 , V_342 ) ;
if ( ! V_343 )
break;
if ( ! strncmp ( V_343 , L_207 , 5 ) )
{
T_14 * V_69 = F_140 ( V_343 + 5 ) ;
T_24 * V_131 ;
if ( ! V_69 )
{
fprintf ( V_76 , L_208 , V_343 + 5 ) ;
continue;
}
V_131 = F_141 ( V_69 , NULL , V_346 ) ;
V_347 = F_142 ( V_131 -> V_69 -> V_348 , V_131 , V_131 -> V_20 , V_131 -> V_69 -> V_116 , V_349 , V_350 , F_81 ) ;
if ( ! V_347 && V_69 -> V_351 )
V_69 -> V_351 ( V_131 ) ;
V_344 = V_131 ;
V_345 = F_82 ;
}
else if ( ! strcmp ( V_343 , L_36 ) )
{
struct V_143 * V_352 ;
V_352 = F_143 ( struct V_143 , 1 ) ;
V_352 -> V_157 = F_144 ( 100 ) ;
V_347 = F_142 ( L_36 , V_352 , NULL , 0 , NULL , F_86 , F_84 ) ;
V_344 = V_352 ;
V_345 = F_90 ;
}
else if ( ! strncmp ( V_343 , L_124 , 5 ) || ! strncmp ( V_343 , L_126 , 6 ) )
{
struct V_54 * V_353 = NULL ;
const char * V_354 ;
struct V_232 * V_355 ;
T_50 V_356 = NULL ;
if ( ! strncmp ( V_343 , L_124 , 5 ) )
{
V_353 = F_145 ( F_146 ( V_343 + 5 ) ) ;
if ( ! V_353 || ! ( V_356 = F_24 ( V_353 ) ) )
{
fprintf ( V_76 , L_209 , V_343 + 5 ) ;
continue;
}
}
else if ( ! strncmp ( V_343 , L_126 , 6 ) )
{
V_353 = F_145 ( F_146 ( V_343 + 6 ) ) ;
if ( ! V_353 || ! ( V_356 = F_25 ( V_353 ) ) )
{
fprintf ( V_76 , L_210 , V_343 + 6 ) ;
continue;
}
}
else
{
fprintf ( V_76 , L_211 , V_343 ) ;
continue;
}
V_354 = F_28 ( F_147 ( V_353 ) ) ;
V_355 = (struct V_232 * ) F_148 ( sizeof( struct V_232 ) ) ;
V_355 -> type = V_343 ;
V_355 -> V_231 . V_58 = V_355 ;
V_355 -> V_240 = TRUE ;
V_355 -> V_243 = TRUE ;
V_347 = F_142 ( V_354 , & V_355 -> V_231 , V_346 , 0 , NULL , V_356 , F_106 ) ;
V_344 = & V_355 -> V_231 ;
V_345 = F_113 ;
}
else if ( ! strncmp ( V_343 , L_212 , 6 ) )
{
T_8 * V_357 = F_149 ( V_343 + 6 ) ;
T_34 * V_256 ;
if ( ! V_357 )
{
fprintf ( V_76 , L_213 , V_343 + 6 ) ;
continue;
}
V_357 -> V_358 ( V_357 , NULL , NULL ) ;
V_256 = F_143 ( T_34 , 1 ) ;
V_256 -> V_259 = V_357 ;
V_256 -> V_58 = NULL ;
V_347 = F_142 ( V_357 -> V_211 , V_256 , V_346 , 0 , NULL , V_357 -> V_359 , F_116 ) ;
V_344 = V_256 ;
V_345 = F_118 ;
}
else if ( ! strncmp ( V_343 , L_214 , 4 ) )
{
T_11 * V_62 = F_150 ( V_343 + 4 ) ;
T_38 * V_279 ;
char * V_75 ;
if ( ! V_62 )
{
fprintf ( V_76 , L_215 , V_343 + 4 ) ;
continue;
}
F_151 ( V_62 , L_1 , & V_346 , & V_75 ) ;
if ( V_75 != NULL )
{
fprintf ( V_76 , L_216 , V_343 + 4 , V_75 ) ;
F_58 ( V_75 ) ;
continue;
}
V_279 = F_143 ( T_38 , 1 ) ;
V_279 -> V_58 = V_62 ;
F_152 ( V_62 , & V_279 -> V_281 , NULL , NULL ) ;
V_347 = F_142 ( F_153 ( V_62 ) , V_279 , V_346 , 0 , NULL , F_154 ( V_62 ) , F_120 ) ;
V_344 = V_279 ;
V_345 = F_123 ;
}
else if ( ! strncmp ( V_343 , L_217 , 4 ) )
{
T_10 * V_61 = F_155 ( V_343 + 4 ) ;
T_41 * V_296 ;
char * V_75 ;
if ( ! V_61 )
{
fprintf ( V_76 , L_218 , V_343 + 4 ) ;
continue;
}
F_156 ( V_61 , L_1 , & V_346 , & V_75 ) ;
if ( V_75 != NULL )
{
fprintf ( V_76 , L_219 , V_343 + 4 , V_75 ) ;
F_58 ( V_75 ) ;
continue;
}
V_296 = F_143 ( T_41 , 1 ) ;
V_296 -> V_297 = F_157 ( FALSE , TRUE , sizeof( T_42 * ) ) ;
V_296 -> V_58 = V_61 ;
F_158 ( V_61 , V_296 -> V_297 , NULL , NULL ) ;
V_347 = F_142 ( F_159 ( V_61 ) , V_296 , V_346 , 0 , NULL , F_160 ( V_61 ) , F_125 ) ;
V_344 = V_296 ;
V_345 = F_126 ;
}
else if ( ! strncmp ( V_343 , L_220 , 3 ) )
{
T_9 * V_59 = F_161 ( V_343 + 3 ) ;
T_44 * V_360 ;
struct V_309 * V_310 ;
if ( ! V_59 )
{
fprintf ( V_76 , L_221 , V_343 + 3 ) ;
continue;
}
for ( V_310 = V_361 ; V_310 ; V_310 = V_310 -> V_24 )
{
if ( ! strcmp ( V_310 -> type , V_343 ) )
{
F_91 ( V_310 -> V_313 , ( V_362 ) V_363 ) ;
V_310 -> V_313 = NULL ;
break;
}
}
if ( ! V_310 )
{
V_310 = F_162 ( struct V_309 , 1 ) ;
V_310 -> type = F_11 ( V_343 ) ;
V_310 -> V_234 = F_29 ( F_30 ( F_27 ( V_59 ) ) ) ;
V_310 -> V_313 = NULL ;
V_310 -> V_24 = V_361 ;
V_361 = V_310 ;
}
V_360 = F_143 ( T_44 , 1 ) ;
V_360 -> V_364 = F_130 ;
V_360 -> V_365 = F_131 ;
V_360 -> V_311 = ( void * ) V_310 ;
V_347 = F_142 ( F_163 ( V_59 ) , V_360 , NULL , 0 , NULL , F_164 ( V_59 ) , F_129 ) ;
V_344 = V_360 ;
V_345 = F_58 ;
}
else if ( ! strcmp ( V_343 , L_33 ) )
{
V_347 = F_142 ( L_222 , & V_321 , V_346 , 0 , V_366 , V_367 , F_133 ) ;
V_344 = & V_321 ;
V_345 = V_366 ;
}
else if ( ! strncmp ( V_343 , L_223 , 12 ) )
{
struct V_185 * V_186 ;
V_186 = (struct V_185 * ) F_148 ( sizeof( * V_186 ) ) ;
if ( ! F_12 ( & V_186 -> V_189 , V_343 + 12 ) )
{
F_58 ( V_186 ) ;
continue;
}
V_186 -> V_211 = V_343 ;
V_186 -> V_190 . V_368 = TRUE ;
V_186 -> V_190 . V_369 = V_370 ;
V_347 = F_142 ( L_222 , V_186 , V_346 , 0 , NULL , F_102 , F_105 ) ;
V_344 = V_186 ;
V_345 = F_101 ;
}
else
{
fprintf ( V_76 , L_224 , V_343 ) ;
continue;
}
if ( V_347 )
{
fprintf ( V_76 , L_225 , V_343 , V_347 -> V_12 ) ;
F_165 ( V_347 , TRUE ) ;
if ( V_345 )
V_345 ( V_344 ) ;
continue;
}
V_338 [ V_340 ] = V_344 ;
V_339 [ V_340 ] = V_345 ;
V_340 ++ ;
}
fprintf ( V_76 , L_226 , V_340 ) ;
if ( V_340 == 0 )
return;
printf ( L_227 ) ;
F_166 () ;
printf ( L_228 ) ;
for ( V_8 = 0 ; V_8 < V_340 ; V_8 ++ )
{
if ( V_338 [ V_8 ] )
F_167 ( V_338 [ V_8 ] ) ;
if ( V_339 [ V_8 ] )
V_339 [ V_8 ] ( V_338 [ V_8 ] ) ;
}
}
static void
F_168 ( char * V_4 , const T_1 * V_5 , int V_6 )
{
const char * V_371 = F_2 ( V_4 , V_5 , V_6 , L_229 ) ;
const char * V_102 = F_2 ( V_4 , V_5 , V_6 , L_53 ) ;
T_12 * V_63 ;
T_49 * V_347 ;
T_51 * V_372 ;
const char * V_251 ;
char * V_255 ;
if ( ! V_371 || ! V_102 )
return;
V_63 = F_169 ( V_371 ) ;
if ( ! V_63 )
{
fprintf ( V_76 , L_230 , V_371 ) ;
return;
}
V_372 = F_143 ( T_51 , 1 ) ;
V_347 = F_142 ( F_170 ( V_63 ) , V_372 , V_102 , 0 , NULL , F_171 ( V_63 ) , NULL ) ;
if ( V_347 )
{
fprintf ( V_76 , L_231 , V_371 , V_347 -> V_12 ) ;
F_165 ( V_347 , TRUE ) ;
F_58 ( V_372 ) ;
return;
}
F_166 () ;
printf ( L_153 ) ;
printf ( L_232 ) ;
V_251 = F_172 ( & V_372 -> V_373 ) ;
printf ( L_233 ) ;
F_3 ( V_251 ) ;
V_255 = F_173 ( V_63 ) ( NULL , V_372 -> V_374 ) ;
printf ( L_234 ) ;
F_3 ( V_255 ) ;
F_110 ( NULL , V_255 ) ;
printf ( L_235 , V_372 -> V_375 [ 0 ] ) ;
V_251 = F_172 ( & V_372 -> V_376 ) ;
printf ( L_236 ) ;
F_3 ( V_251 ) ;
V_255 = F_173 ( V_63 ) ( NULL , V_372 -> V_377 ) ;
printf ( L_237 ) ;
F_3 ( V_255 ) ;
F_110 ( NULL , V_255 ) ;
printf ( L_238 , V_372 -> V_375 [ 1 ] ) ;
if ( V_372 -> V_325 )
{
T_52 * V_378 ;
T_13 * V_379 ;
const char * V_68 = L_1 ;
printf ( L_239 ) ;
for ( V_379 = V_372 -> V_325 ; V_379 ; V_379 = F_174 ( V_379 ) )
{
V_378 = ( T_52 * ) V_379 -> V_13 ;
printf ( L_4 , V_68 ) ;
printf ( L_240 , V_378 -> V_149 ) ;
printf ( L_241 ) ;
F_7 ( V_378 -> V_13 -> V_13 , V_378 -> V_13 -> V_17 ) ;
if ( V_378 -> V_380 )
printf ( L_242 , 1 ) ;
printf ( L_8 ) ;
V_68 = L_5 ;
}
printf ( L_23 ) ;
}
printf ( L_41 ) ;
F_167 ( V_372 ) ;
F_175 ( V_372 ) ;
}
static void
F_176 ( T_16 * V_87 , T_53 * * V_381 )
{
T_54 * V_122 ;
const char * V_68 = L_1 ;
printf ( L_56 ) ;
for ( V_122 = V_87 -> V_382 ; V_122 ; V_122 = V_122 -> V_24 )
{
T_55 * V_383 = F_177 ( V_122 ) ;
if ( ! V_383 )
continue;
if ( F_178 ( V_383 , V_384 ) )
continue;
printf ( L_4 , V_68 ) ;
printf ( L_243 ) ;
if ( ! V_383 -> V_385 )
{
char V_386 [ V_387 ] ;
V_386 [ 0 ] = '\0' ;
F_179 ( V_383 , V_386 ) ;
F_3 ( V_386 ) ;
}
else
{
F_3 ( V_383 -> V_385 -> V_388 ) ;
}
if ( V_383 -> V_389 && V_381 && V_381 [ 0 ] != V_383 -> V_389 )
{
int V_390 ;
for ( V_390 = 1 ; V_381 [ V_390 ] ; V_390 ++ )
{
if ( V_381 [ V_390 ] == V_383 -> V_389 )
{
printf ( L_244 , V_390 ) ;
break;
}
}
}
if ( V_383 -> V_10 >= 0 && V_383 -> V_391 > 0 )
printf ( L_245 , V_383 -> V_10 , V_383 -> V_391 ) ;
if ( V_383 -> V_392 >= 0 && V_383 -> V_393 > 0 )
printf ( L_246 , V_383 -> V_392 , V_383 -> V_393 ) ;
if ( V_383 -> V_394 )
{
if ( V_383 -> V_394 -> type == V_395 )
{
printf ( L_247 ) ;
}
else if ( V_383 -> V_394 -> type == V_396 )
{
printf ( L_248 , V_383 -> V_49 . V_49 . V_397 ) ;
}
else if ( F_178 ( V_383 , V_398 ) && F_180 ( V_383 -> V_394 -> type ) )
{
char * V_399 = F_181 ( NULL , & V_383 -> V_49 , V_400 , V_383 -> V_394 -> V_401 ) ;
printf ( L_249 ) ;
F_3 ( V_399 ) ;
F_110 ( NULL , V_399 ) ;
}
}
if ( F_178 ( V_383 , V_402 ) )
{
const char * V_150 = F_85 ( F_178 ( V_383 , V_402 ) , V_151 ) ;
F_182 ( V_150 != NULL ) ;
printf ( L_250 , V_150 ) ;
}
if ( ( ( T_16 * ) V_122 ) -> V_382 ) {
if ( V_383 -> V_403 != - 1 )
printf ( L_251 , V_383 -> V_403 ) ;
printf ( L_252 ) ;
F_176 ( ( T_16 * ) V_122 , V_381 ) ;
}
printf ( L_8 ) ;
V_68 = L_5 ;
}
printf ( L_23 ) ;
}
static T_6
F_183 ( const void * V_48 V_57 , void * V_49 , void * V_58 )
{
T_12 * V_63 = ( T_12 * ) V_49 ;
T_7 * V_52 = ( T_7 * ) V_58 ;
const int V_60 = F_36 ( V_63 ) ;
T_20 V_404 ;
if ( F_184 ( V_52 -> V_98 , F_28 ( V_60 ) ) )
{
const char * V_405 = F_29 ( F_30 ( V_60 ) ) ;
char * V_406 ;
V_406 = F_185 ( V_63 ) ( V_52 , & V_404 ) ;
printf ( L_253 , V_405 ) ;
F_3 ( V_406 ) ;
printf ( L_23 ) ;
F_58 ( V_406 ) ;
}
return FALSE ;
}
static void
F_186 ( T_7 * V_52 , T_16 * V_87 , struct V_88 * V_89 , const T_17 * V_90 , void * V_13 )
{
( void ) V_52 ;
( void ) V_13 ;
printf ( L_153 ) ;
printf ( L_232 ) ;
if ( V_87 )
{
T_53 * * V_381 = NULL ;
printf ( L_254 ) ;
if ( V_90 && V_90 -> V_24 )
{
T_29 V_6 = F_187 ( ( T_17 * ) V_90 ) ;
T_29 V_8 ;
V_381 = ( T_53 * * ) F_10 ( ( V_6 + 1 ) * sizeof( * V_381 ) ) ;
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ )
{
struct V_407 * V_46 = (struct V_407 * ) F_132 ( ( T_17 * ) V_90 , V_8 ) ;
V_381 [ V_8 ] = F_188 ( V_46 ) ;
}
V_381 [ V_6 ] = NULL ;
}
F_176 ( V_87 , V_381 ) ;
F_58 ( V_381 ) ;
}
if ( V_89 )
{
int V_107 ;
printf ( L_255 ) ;
for ( V_107 = 0 ; V_107 < V_89 -> V_112 ; ++ V_107 )
{
const T_22 * V_113 = & V_89 -> V_114 [ V_107 ] ;
printf ( L_256 , ( V_107 ) ? L_5 : L_1 , V_113 -> V_115 ) ;
}
printf ( L_23 ) ;
}
if ( V_90 )
{
struct V_407 * V_46 = (struct V_407 * ) V_90 -> V_13 ;
const char * V_408 = NULL ;
T_53 * V_409 ;
T_29 V_391 ;
V_409 = F_188 ( V_46 ) ;
V_391 = F_189 ( V_409 ) ;
printf ( L_257 ) ;
if ( V_391 != 0 )
{
const T_56 * V_410 = F_190 ( V_409 , 0 , V_391 ) ;
F_7 ( V_410 , V_391 ) ;
}
else
{
F_7 ( L_1 , 0 ) ;
}
V_90 = V_90 -> V_24 ;
if ( V_90 )
{
printf ( L_258 ) ;
V_408 = L_1 ;
}
while ( V_90 )
{
V_46 = (struct V_407 * ) V_90 -> V_13 ;
{
char * V_411 = F_191 ( V_46 ) ;
printf ( L_259 , V_408 ) ;
F_3 ( V_411 ) ;
F_110 ( NULL , V_411 ) ;
}
V_409 = F_188 ( V_46 ) ;
V_391 = F_189 ( V_409 ) ;
printf ( L_257 ) ;
if ( V_391 != 0 )
{
const T_56 * V_410 = F_190 ( V_409 , 0 , V_391 ) ;
F_7 ( V_410 , V_391 ) ;
}
else
{
F_7 ( L_1 , 0 ) ;
}
printf ( L_8 ) ;
V_408 = L_5 ;
V_90 = V_90 -> V_24 ;
}
if ( V_408 != NULL )
printf ( L_23 ) ;
}
printf ( L_260 ) ;
F_49 ( F_183 , V_52 ) ;
printf ( L_23 ) ;
printf ( L_41 ) ;
}
static void
F_192 ( char * V_4 , const T_1 * V_5 , int V_6 )
{
const char * V_412 = F_2 ( V_4 , V_5 , V_6 , L_261 ) ;
const char * V_102 = F_2 ( V_4 , V_5 , V_6 , L_53 ) ;
const T_2 * V_105 = NULL ;
struct
{
unsigned int V_110 ;
T_57 V_413 ;
} V_131 , V_414 ;
T_58 * V_415 = NULL ;
T_20 V_416 = 1000 ;
const char * V_68 = L_1 ;
unsigned int V_101 ;
T_15 V_390 ;
T_15 V_417 = 0 ;
if ( V_412 ) {
if ( ! F_75 ( V_412 , NULL , & V_416 ) || V_416 == 0 ) {
fprintf ( V_76 , L_262 , V_412 ) ;
return;
}
}
if ( V_102 )
{
V_105 = F_8 ( V_102 ) ;
if ( ! V_105 )
return;
}
V_414 . V_110 = 0 ;
V_414 . V_413 = 0 ;
V_131 . V_110 = 0 ;
V_131 . V_413 = 0 ;
V_390 = 0 ;
printf ( L_263 ) ;
for ( V_101 = 1 ; V_101 <= V_81 . V_6 ; V_101 ++ )
{
T_18 * V_93 = F_76 ( V_81 . V_110 , V_101 ) ;
T_15 V_418 ;
T_15 V_419 ;
if ( V_415 == NULL )
V_415 = & V_93 -> V_96 ;
if ( V_105 && ! ( V_105 [ V_101 / 8 ] & ( 1 << ( V_101 % 8 ) ) ) )
continue;
V_418 = ( V_93 -> V_96 . V_420 - V_415 -> V_420 ) * ( T_15 ) 1000 + ( V_93 -> V_96 . V_421 - V_415 -> V_421 ) / 1000000 ;
V_419 = V_418 / V_416 ;
if ( V_390 != V_419 )
{
if ( V_131 . V_110 != 0 )
{
printf ( L_264 V_86 L_265 V_244 L_23 , V_68 , V_390 , V_131 . V_110 , V_131 . V_413 ) ;
V_68 = L_5 ;
}
V_390 = V_419 ;
if ( V_390 > V_417 )
V_417 = V_390 ;
V_131 . V_110 = 0 ;
V_131 . V_413 = 0 ;
}
V_131 . V_110 += 1 ;
V_131 . V_413 += V_93 -> V_422 ;
V_414 . V_110 += 1 ;
V_414 . V_413 += V_93 -> V_422 ;
}
if ( V_131 . V_110 != 0 )
{
printf ( L_264 V_86 L_265 V_244 L_23 , V_68 , V_390 , V_131 . V_110 , V_131 . V_413 ) ;
}
printf ( L_266 V_86 L_267 V_244 L_41 , V_417 , V_414 . V_110 , V_414 . V_413 ) ;
}
static void
F_193 ( char * V_4 , const T_1 * V_5 , int V_6 )
{
const char * V_423 = F_2 ( V_4 , V_5 , V_6 , L_268 ) ;
int V_424 = ( F_2 ( V_4 , V_5 , V_6 , L_269 ) != NULL ) ;
int V_425 = ( F_2 ( V_4 , V_5 , V_6 , L_270 ) != NULL ) ;
int V_426 = ( F_2 ( V_4 , V_5 , V_6 , L_271 ) != NULL ) ;
T_20 V_101 ;
if ( ! V_423 || ! F_75 ( V_423 , NULL , & V_101 ) || V_101 == 0 )
return;
F_72 ( V_101 , & F_186 , V_425 , V_426 , V_424 , NULL ) ;
}
static int
F_194 ( char * V_4 , const T_1 * V_5 , int V_6 )
{
const char * V_102 = F_2 ( V_4 , V_5 , V_6 , L_53 ) ;
printf ( L_272 ) ;
if ( V_102 != NULL )
{
char * V_427 = NULL ;
T_59 * V_428 ;
if ( F_195 ( V_102 , & V_428 , & V_427 ) )
{
const char * V_429 = L_273 ;
if ( F_196 ( V_428 ) )
V_429 = L_274 ;
printf ( L_143 , V_429 ) ;
F_197 ( V_428 ) ;
}
else
{
printf ( L_275 ) ;
F_3 ( V_427 ) ;
F_58 ( V_427 ) ;
}
}
printf ( L_41 ) ;
return 0 ;
}
static T_29
F_198 ( T_60 * V_430 , T_61 V_431 )
{
struct V_432 * V_13 = (struct V_432 * ) V_431 ;
if ( strncmp ( V_13 -> V_433 , V_430 -> V_70 , strlen ( V_13 -> V_433 ) ) != 0 )
return 0 ;
printf ( L_276 , V_13 -> V_68 , V_430 -> V_70 , V_430 -> V_53 ) ;
V_13 -> V_68 = L_5 ;
return 0 ;
}
static T_29
F_199 ( T_62 * V_433 , T_61 V_431 )
{
struct V_432 * V_13 = (struct V_432 * ) V_431 ;
const char * V_434 = F_200 ( V_433 ) ;
const char * V_435 = F_201 ( V_433 ) ;
if ( strncmp ( V_13 -> V_433 , V_434 , strlen ( V_13 -> V_433 ) ) != 0 )
return 0 ;
printf ( L_277 , V_13 -> V_68 , V_13 -> V_430 , V_434 , V_435 ) ;
V_13 -> V_68 = L_5 ;
return 0 ;
}
static int
F_202 ( char * V_4 , const T_1 * V_5 , int V_6 )
{
const char * V_436 = F_2 ( V_4 , V_5 , V_6 , L_278 ) ;
const char * V_437 = F_2 ( V_4 , V_5 , V_6 , L_279 ) ;
printf ( L_272 ) ;
if ( V_436 != NULL && V_436 [ 0 ] )
{
const T_5 V_438 = strlen ( V_436 ) ;
const int V_439 = ! ! strchr ( V_436 , '.' ) ;
void * V_440 ;
void * V_441 ;
int V_60 ;
const char * V_68 = L_1 ;
printf ( L_280 ) ;
for ( V_60 = F_203 ( & V_440 ) ; V_60 != - 1 ; V_60 = F_204 ( & V_440 ) )
{
T_63 * V_155 = F_30 ( V_60 ) ;
const char * V_442 ;
const char * V_443 ;
T_64 * V_394 ;
if ( ! F_205 ( V_155 ) )
continue;
V_443 = F_206 ( V_155 ) ;
V_442 = F_28 ( V_60 ) ;
if ( strlen ( V_442 ) >= V_438 && ! F_207 ( V_436 , V_442 , V_438 ) )
{
printf ( L_4 , V_68 ) ;
{
printf ( L_281 ) ;
F_3 ( V_442 ) ;
printf ( L_122 , V_395 ) ;
printf ( L_252 ) ;
F_3 ( V_443 ) ;
}
printf ( L_8 ) ;
V_68 = L_5 ;
}
if ( ! V_439 )
continue;
for ( V_394 = F_208 ( V_60 , & V_441 ) ; V_394 != NULL ; V_394 = F_209 ( V_60 , & V_441 ) )
{
if ( V_394 -> V_444 != - 1 )
continue;
if ( strlen ( V_394 -> V_445 ) >= V_438 && ! F_207 ( V_436 , V_394 -> V_445 , V_438 ) )
{
printf ( L_4 , V_68 ) ;
{
printf ( L_281 ) ;
F_3 ( V_394 -> V_445 ) ;
if ( V_394 -> V_446 == NULL )
{
printf ( L_122 , V_394 -> type ) ;
printf ( L_252 ) ;
F_3 ( V_394 -> V_70 ) ;
}
}
printf ( L_8 ) ;
V_68 = L_5 ;
}
}
}
printf ( L_23 ) ;
}
if ( V_437 != NULL && V_437 [ 0 ] )
{
struct V_432 V_13 ;
char * V_447 ;
V_13 . V_430 = V_437 ;
V_13 . V_433 = V_437 ;
V_13 . V_68 = L_1 ;
printf ( L_282 ) ;
if ( ( V_447 = strchr ( V_437 , '.' ) ) )
{
T_60 * V_448 ;
* V_447 = '\0' ;
V_13 . V_433 = V_447 + 1 ;
V_448 = F_210 ( V_13 . V_430 ) ;
if ( V_448 )
F_211 ( V_448 , F_199 , & V_13 ) ;
* V_447 = '.' ;
}
else
{
F_212 ( F_198 , & V_13 ) ;
}
printf ( L_23 ) ;
}
printf ( L_41 ) ;
return 0 ;
}
static void
F_213 ( char * V_4 , const T_1 * V_5 , int V_6 )
{
const char * V_449 = F_2 ( V_4 , V_5 , V_6 , L_283 ) ;
const char * V_11 = F_2 ( V_4 , V_5 , V_6 , L_284 ) ;
char V_433 [ 4096 ] ;
char * V_450 = NULL ;
T_65 V_26 ;
if ( ! V_449 || V_449 [ 0 ] == '\0' || ! V_11 )
return;
F_139 ( V_433 , sizeof( V_433 ) , L_285 , V_449 , V_11 ) ;
V_26 = F_214 ( V_433 , & V_450 ) ;
printf ( L_286 , V_26 ) ;
if ( V_450 ) {
printf ( L_287 ) ;
F_3 ( V_450 ) ;
}
printf ( L_41 ) ;
F_58 ( V_450 ) ;
}
static T_29
F_215 ( T_62 * V_433 , T_61 V_431 )
{
struct V_451 * V_13 = (struct V_451 * ) V_431 ;
const char * V_434 = F_200 ( V_433 ) ;
printf ( L_288 , V_13 -> V_68 , V_13 -> V_430 -> V_70 , V_434 ) ;
switch ( F_216 ( V_433 ) )
{
case V_452 :
case V_453 :
printf ( L_289 , F_217 ( V_433 , V_454 ) ) ;
if ( F_218 ( V_433 ) != 10 )
printf ( L_290 , F_218 ( V_433 ) ) ;
break;
case V_455 :
printf ( L_291 , F_219 ( V_433 , V_454 ) ? L_144 : L_292 ) ;
break;
case V_456 :
printf ( L_293 ) ;
F_3 ( F_220 ( V_433 , V_454 ) ) ;
break;
case V_457 :
{
const T_66 * V_458 ;
const char * V_459 = L_1 ;
printf ( L_294 ) ;
for ( V_458 = F_221 ( V_433 ) ; V_458 -> V_70 ; V_458 ++ )
{
printf ( L_295 , V_459 , V_458 -> V_49 ) ;
if ( V_458 -> V_49 == F_222 ( V_433 , V_454 ) )
printf ( L_296 ) ;
printf ( L_241 ) ;
F_3 ( V_458 -> V_460 ) ;
printf ( L_8 ) ;
V_459 = L_5 ;
}
printf ( L_23 ) ;
break;
}
case V_461 :
case V_462 :
{
char * V_463 = F_223 ( NULL , F_224 ( V_433 , V_454 ) ) ;
printf ( L_297 , V_463 ) ;
F_110 ( NULL , V_463 ) ;
break;
}
case V_464 :
{
T_67 * V_465 = F_225 ( V_433 ) ;
T_29 V_390 ;
printf ( L_298 ) ;
for ( V_390 = 0 ; V_390 < V_465 -> V_466 -> V_17 ; V_390 ++ )
{
void * V_467 = F_226 ( V_465 , V_390 ) ;
T_29 V_468 ;
if ( V_390 )
printf ( L_5 ) ;
printf ( L_56 ) ;
for ( V_468 = 0 ; V_468 < V_465 -> V_469 ; V_468 ++ )
{
char * V_12 = F_227 ( V_467 , & ( V_465 -> V_263 [ V_468 ] ) ) ;
if ( V_468 )
printf ( L_5 ) ;
F_3 ( V_12 ) ;
F_58 ( V_12 ) ;
}
printf ( L_23 ) ;
}
printf ( L_23 ) ;
break;
}
case V_470 :
case V_471 :
case V_472 :
case V_473 :
break;
}
#if 0
printf(",\"t\":");
json_puts_string(prefs_get_title(pref));
#endif
printf ( L_8 ) ;
V_13 -> V_68 = L_5 ;
return 0 ;
}
static T_29
F_228 ( T_60 * V_430 , T_61 V_431 )
{
struct V_451 * V_13 = (struct V_451 * ) V_431 ;
V_13 -> V_430 = V_430 ;
F_211 ( V_430 , F_215 , V_13 ) ;
return 0 ;
}
static void
F_229 ( char * V_4 , const T_1 * V_5 , int V_6 )
{
const char * V_437 = F_2 ( V_4 , V_5 , V_6 , L_279 ) ;
T_60 * V_448 ;
char * V_447 ;
if ( ! V_437 )
{
struct V_451 V_13 ;
V_13 . V_430 = NULL ;
V_13 . V_68 = L_1 ;
printf ( L_299 ) ;
F_212 ( F_228 , & V_13 ) ;
printf ( L_300 ) ;
return;
}
if ( ( V_447 = strchr ( V_437 , '.' ) ) )
{
T_62 * V_433 = NULL ;
* V_447 = '\0' ;
V_448 = F_210 ( V_437 ) ;
if ( V_448 )
V_433 = F_230 ( V_448 , V_447 + 1 ) ;
* V_447 = '.' ;
if ( V_433 )
{
struct V_451 V_13 ;
V_13 . V_430 = V_448 ;
V_13 . V_68 = L_1 ;
printf ( L_299 ) ;
F_215 ( V_433 , & V_13 ) ;
printf ( L_300 ) ;
}
return;
}
V_448 = F_210 ( V_437 ) ;
if ( V_448 )
{
struct V_451 V_13 ;
V_13 . V_430 = V_448 ;
V_13 . V_68 = L_1 ;
printf ( L_299 ) ;
F_211 ( V_448 , F_215 , & V_13 ) ;
printf ( L_300 ) ;
}
}
static void
F_231 ( void * V_474 )
{
T_68 * V_475 = ( T_68 * ) V_474 ;
F_58 ( V_475 -> V_476 ) ;
F_58 ( V_475 -> V_477 ) ;
F_58 ( V_475 ) ;
}
static void
F_232 ( struct V_478 * V_28 )
{
static const int V_479 = sizeof( V_480 ) / sizeof( char ) ;
T_20 V_481 = 0 ;
struct V_482 * V_483 = F_233 () ;
struct V_484 * V_485 = NULL ;
T_4 V_486 = 0x1000 ;
V_480 * V_487 = ( V_480 * ) F_10 ( V_486 ) ;
T_69 V_488 = 0 ;
char * V_489 = NULL ;
T_15 V_490 = 0 ;
unsigned V_491 = 0 ;
unsigned V_492 = 0 ;
int V_8 ;
int V_18 = 0 ;
int V_19 = 0 ;
T_17 * V_22 ;
for ( V_22 = V_28 -> V_187 ; V_22 ; V_22 = V_22 -> V_24 )
{
T_68 * V_475 = ( T_68 * ) V_22 -> V_13 ;
V_480 * V_493 = NULL ;
T_5 V_494 ;
V_494 = F_234 ( V_475 , & V_493 , V_483 , & V_491 , & V_492 ) ;
if ( V_494 == 0 || V_492 == 0 )
{
F_58 ( V_493 ) ;
continue;
}
if ( V_481 == 0 )
{
T_20 V_495 ;
T_70 V_496 ;
char V_497 [ 44 ] ;
V_481 = V_492 ;
F_235 ( L_301 , V_481 ) ;
memset ( & V_497 , 0 , sizeof( V_497 ) ) ;
memcpy ( & V_497 [ 0 ] , L_302 , 4 ) ;
memcpy ( & V_497 [ 4 ] , L_303 , 4 ) ;
memcpy ( & V_497 [ 8 ] , L_304 , 4 ) ;
memcpy ( & V_497 [ 12 ] , L_305 , 4 ) ;
memcpy ( & V_497 [ 16 ] , L_306 , 4 ) ;
memcpy ( & V_497 [ 20 ] , L_307 , 2 ) ;
V_496 = V_491 ;
memcpy ( & V_497 [ 22 ] , & V_496 , 2 ) ;
V_495 = V_492 ;
memcpy ( & V_497 [ 24 ] , & V_495 , 4 ) ;
V_495 = V_492 * V_491 * V_479 ;
memcpy ( & V_497 [ 28 ] , & V_495 , 4 ) ;
V_496 = V_491 * V_479 ;
memcpy ( & V_497 [ 32 ] , & V_496 , 2 ) ;
V_496 = 8 * V_479 ;
memcpy ( & V_497 [ 34 ] , & V_496 , 2 ) ;
memcpy ( & V_497 [ 36 ] , L_308 , 4 ) ;
memcpy ( & V_497 [ 40 ] , L_303 , 4 ) ;
for ( V_8 = 0 ; V_8 < ( int ) sizeof( V_497 ) ; V_8 ++ )
F_4 ( & V_497 [ V_8 ] , & V_18 , & V_19 ) ;
}
V_489 = ( char * ) V_493 ;
V_490 = V_494 ;
if ( V_481 != V_492 )
{
T_69 V_498 , V_499 ;
if ( ! V_485 )
{
V_485 = F_236 ( 1 , V_492 , V_481 , 10 , NULL ) ;
F_237 ( V_485 ) ;
F_235 ( L_309 , V_492 , V_481 ) ;
}
else
{
T_69 V_500 ;
F_238 ( V_485 , & V_488 , & V_500 ) ;
if ( V_492 != V_488 )
{
F_239 ( V_485 , V_492 , V_500 ) ;
F_235 ( L_310 , V_488 , V_492 , V_481 ) ;
}
}
V_498 = ( T_69 ) V_475 -> V_476 -> V_501 ;
V_499 = ( V_481 * ( T_69 ) V_475 -> V_476 -> V_501 / V_492 ) + ( V_481 % V_492 != 0 ) ;
if ( V_499 * V_479 > V_486 )
{
while ( ( V_499 * V_479 > V_486 ) )
V_486 *= 2 ;
V_487 = ( V_480 * ) F_240 ( V_487 , V_486 ) ;
}
F_241 ( V_485 , 0 , V_493 , & V_498 , V_487 , & V_499 ) ;
V_489 = ( char * ) V_487 ;
V_490 = V_499 * V_479 ;
}
for ( V_8 = 0 ; V_8 < V_490 ; V_8 ++ )
F_4 ( & V_489 [ V_8 ] , & V_18 , & V_19 ) ;
F_58 ( V_493 ) ;
}
F_4 ( NULL , & V_18 , & V_19 ) ;
F_58 ( V_487 ) ;
F_73 ( V_483 ) ;
}
static T_6
F_242 ( void * V_142 , T_7 * V_40 , T_26 * T_27 V_57 , const void * V_13 )
{
const struct V_41 * V_42 = ( const struct V_41 * ) V_13 ;
struct V_478 * V_502 = (struct V_478 * ) V_142 ;
if ( V_42 -> V_503 == 0 )
return FALSE ;
if ( F_20 ( & V_502 -> V_189 , V_40 , V_42 ) )
{
T_68 * V_475 ;
V_475 = F_143 ( T_68 , 1 ) ;
V_475 -> V_476 = (struct V_41 * ) F_87 ( V_42 , sizeof( struct V_41 ) ) ;
if ( V_42 -> V_504 && V_42 -> V_501 != 0 )
V_475 -> V_477 = ( T_2 * ) F_87 ( & ( V_42 -> V_505 [ V_42 -> V_506 ] ) , V_42 -> V_501 ) ;
if ( ! V_502 -> V_187 )
V_502 -> V_193 = F_56 ( & V_40 -> V_96 ) ;
V_475 -> V_194 = V_40 -> V_195 ;
V_475 -> V_205 = F_56 ( & V_40 -> V_96 ) - V_502 -> V_193 ;
V_502 -> V_187 = F_104 ( V_502 -> V_187 , V_475 ) ;
}
return FALSE ;
}
static void
F_243 ( char * V_4 , const T_1 * V_5 , int V_6 )
{
const char * V_507 = F_2 ( V_4 , V_5 , V_6 , L_311 ) ;
if ( ! V_507 )
return;
if ( ! strncmp ( V_507 , L_220 , 3 ) )
{
struct V_309 * V_310 ;
const T_45 * V_314 = NULL ;
for ( V_310 = V_361 ; V_310 ; V_310 = V_310 -> V_24 )
{
T_5 V_508 = strlen ( V_310 -> type ) ;
if ( ! strncmp ( V_507 , V_310 -> type , V_508 ) && V_507 [ V_508 ] == '_' )
{
int V_320 ;
if ( sscanf ( & V_507 [ V_508 + 1 ] , L_161 , & V_320 ) != 1 )
break;
V_314 = ( T_45 * ) F_132 ( V_310 -> V_313 , V_320 ) ;
break;
}
}
if ( V_314 )
{
const char * V_509 = ( V_314 -> V_317 ) ? V_314 -> V_317 : L_312 ;
const char * V_83 = ( V_314 -> V_83 ) ? V_314 -> V_83 : V_507 ;
printf ( L_313 ) ;
F_3 ( V_83 ) ;
printf ( L_314 ) ;
F_3 ( V_509 ) ;
printf ( L_315 ) ;
F_7 ( V_314 -> V_477 , ( int ) V_314 -> V_318 ) ;
printf ( L_41 ) ;
}
}
else if ( ! strcmp ( V_507 , L_316 ) )
{
char * V_12 = F_244 () ;
if ( V_12 )
{
const char * V_509 = L_317 ;
const char * V_83 = L_318 ;
printf ( L_313 ) ;
F_3 ( V_83 ) ;
printf ( L_314 ) ;
F_3 ( V_509 ) ;
printf ( L_315 ) ;
F_7 ( V_12 , strlen ( V_12 ) ) ;
printf ( L_41 ) ;
}
F_58 ( V_12 ) ;
}
else if ( ! strncmp ( V_507 , L_319 , 4 ) )
{
struct V_478 V_186 ;
T_49 * V_347 ;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
if ( ! F_12 ( & V_186 . V_189 , V_507 + 4 ) )
{
fprintf ( V_76 , L_320 , V_507 ) ;
return;
}
V_347 = F_142 ( L_222 , & V_186 , NULL , 0 , NULL , F_242 , NULL ) ;
if ( V_347 )
{
fprintf ( V_76 , L_321 , V_347 -> V_12 ) ;
F_165 ( V_347 , TRUE ) ;
return;
}
F_166 () ;
F_167 ( & V_186 ) ;
if ( V_186 . V_187 )
{
const char * V_509 = L_322 ;
const char * V_83 = V_507 ;
printf ( L_313 ) ;
F_3 ( V_83 ) ;
printf ( L_314 ) ;
F_3 ( V_509 ) ;
printf ( L_315 ) ;
putchar ( '"' ) ;
F_232 ( & V_186 ) ;
putchar ( '"' ) ;
printf ( L_41 ) ;
F_91 ( V_186 . V_187 , F_231 ) ;
}
}
}
static void
F_245 ( char * V_4 , const T_1 * V_5 , int V_6 )
{
int V_8 ;
if ( V_6 < 1 || V_5 [ 0 ] . type != V_510 )
{
fprintf ( V_76 , L_323 ) ;
return;
}
V_5 ++ ;
V_6 -- ;
if ( V_6 & 1 )
{
fprintf ( V_76 , L_324 , V_6 ) ;
return;
}
for ( V_8 = 0 ; V_8 < V_6 ; V_8 += 2 )
{
if ( V_5 [ V_8 ] . type != V_511 )
{
fprintf ( V_76 , L_325 , V_8 ) ;
return;
}
V_4 [ V_5 [ V_8 + 0 ] . V_512 ] = '\0' ;
V_4 [ V_5 [ V_8 + 1 ] . V_512 ] = '\0' ;
F_1 ( & V_4 [ V_5 [ V_8 + 0 ] . V_10 ] ) ;
F_1 ( & V_4 [ V_5 [ V_8 + 1 ] . V_10 ] ) ;
}
{
const char * V_513 = F_2 ( V_4 , V_5 , V_6 , L_326 ) ;
if ( ! V_513 )
{
fprintf ( V_76 , L_327 ) ;
return;
}
if ( ! strcmp ( V_513 , L_328 ) )
F_50 ( V_4 , V_5 , V_6 ) ;
else if ( ! strcmp ( V_513 , L_329 ) )
F_55 () ;
else if ( ! strcmp ( V_513 , L_330 ) )
F_70 () ;
else if ( ! strcmp ( V_513 , L_331 ) )
F_37 () ;
else if ( ! strcmp ( V_513 , L_332 ) )
F_194 ( V_4 , V_5 , V_6 ) ;
else if ( ! strcmp ( V_513 , L_333 ) )
F_202 ( V_4 , V_5 , V_6 ) ;
else if ( ! strcmp ( V_513 , L_334 ) )
F_74 ( V_4 , V_5 , V_6 ) ;
else if ( ! strcmp ( V_513 , L_335 ) )
F_138 ( V_4 , V_5 , V_6 ) ;
else if ( ! strcmp ( V_513 , L_229 ) )
F_168 ( V_4 , V_5 , V_6 ) ;
else if ( ! strcmp ( V_513 , L_336 ) )
F_192 ( V_4 , V_5 , V_6 ) ;
else if ( ! strcmp ( V_513 , L_268 ) )
F_193 ( V_4 , V_5 , V_6 ) ;
else if ( ! strcmp ( V_513 , L_337 ) )
F_213 ( V_4 , V_5 , V_6 ) ;
else if ( ! strcmp ( V_513 , L_338 ) )
F_229 ( V_4 , V_5 , V_6 ) ;
else if ( ! strcmp ( V_513 , L_339 ) )
F_243 ( V_4 , V_5 , V_6 ) ;
else if ( ! strcmp ( V_513 , L_340 ) )
exit ( 0 ) ;
else
fprintf ( V_76 , L_341 , V_513 ) ;
printf ( L_342 ) ;
fflush ( stdout ) ;
}
}
int
F_246 ( void )
{
char V_4 [ 2 * 1024 ] ;
T_1 * V_5 = NULL ;
int V_514 = - 1 ;
fprintf ( V_76 , L_343 ) ;
while ( fgets ( V_4 , sizeof( V_4 ) , V_515 ) )
{
int V_26 ;
V_26 = F_247 ( V_4 , NULL , 0 ) ;
if ( V_26 < 0 )
{
fprintf ( V_76 , L_344 ) ;
return 1 ;
}
V_26 += 1 ;
if ( V_5 == NULL || V_514 < V_26 )
{
V_514 = V_26 ;
V_5 = ( T_1 * ) F_240 ( V_5 , sizeof( T_1 ) * V_514 ) ;
}
memset ( V_5 , 0 , V_26 * sizeof( T_1 ) ) ;
V_26 = F_247 ( V_4 , V_5 , V_26 ) ;
if ( V_26 < 0 )
{
fprintf ( V_76 , L_345 ) ;
return 2 ;
}
F_245 ( V_4 , V_5 , V_26 ) ;
}
F_58 ( V_5 ) ;
return 0 ;
}
