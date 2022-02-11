static unsigned int F_1 ( T_1 * V_1 , const char * V_2 , char * V_3 ,
unsigned int V_4 , unsigned char * V_5 ,
unsigned int V_6 )
{
unsigned int V_7 = 0 ;
int V_8 ;
T_2 * V_9 = NULL ;
if ( V_10 )
F_2 ( V_11 , L_1 ) ;
if ( ! V_2 )
{
if ( V_10 )
F_2 ( V_11 , L_2 ) ;
}
else if ( V_10 )
F_2 ( V_11 , L_3 , V_2 ) ;
V_8 = F_3 ( V_3 , V_4 , L_4 , V_12 ) ;
if ( V_8 < 0 || ( unsigned int ) V_8 > V_4 )
goto V_13;
if ( V_10 )
F_2 ( V_11 , L_5 , V_3 , V_8 ) ;
V_8 = F_4 ( & V_9 , V_14 ) ;
if ( ! V_8 )
{
F_2 ( V_15 , L_6 , V_14 ) ;
if ( V_9 )
F_5 ( V_9 ) ;
return 0 ;
}
if ( ( unsigned int ) F_6 ( V_9 ) > V_6 )
{
F_2 ( V_15 , L_7 ,
V_6 , F_6 ( V_9 ) ) ;
F_5 ( V_9 ) ;
return 0 ;
}
V_7 = F_7 ( V_9 , V_5 ) ;
F_5 ( V_9 ) ;
if ( V_7 == 0 )
goto V_13;
if ( V_10 )
F_2 ( V_11 , L_8 , V_7 ) ;
return V_7 ;
V_13:
if ( V_10 )
F_2 ( V_15 , L_9 ) ;
return 0 ;
}
static void F_8 ( void )
{
F_2 ( V_15 , L_10 ) ;
F_2 ( V_15 , L_11 ) ;
F_2 ( V_15 , L_12 ) ;
F_2 ( V_15 , L_13 ) ;
F_2 ( V_15 , L_14 , V_16 , V_17 ) ;
F_2 ( V_15 , L_15 ) ;
F_2 ( V_15 , L_16 ) ;
F_2 ( V_15 , L_17 ) ;
F_2 ( V_15 , L_18 ) ;
F_2 ( V_15 , L_19 ) ;
F_2 ( V_15 , L_20 ) ;
F_2 ( V_15 , L_21 ) ;
F_2 ( V_15 , L_22 ) ;
F_2 ( V_15 , L_23 ) ;
F_2 ( V_15 , L_24 ) ;
F_2 ( V_15 , L_25 ) ;
F_2 ( V_15 , L_26 ) ;
F_2 ( V_15 , L_27 ) ;
#ifdef F_9
F_2 ( V_15 , L_28 ) ;
#endif
F_2 ( V_15 , L_29 ) ;
F_2 ( V_15 , L_30 ) ;
F_2 ( V_15 , L_31 ) ;
#ifdef F_10
F_2 ( V_15 , L_32 ) ;
#endif
F_2 ( V_15 , L_33 ) ;
F_2 ( V_15 , L_34 ) ;
F_2 ( V_15 , L_35 ) ;
F_2 ( V_15 , L_36 ) ;
#ifndef F_11
F_2 ( V_15 , L_37 ) ;
F_2 ( V_15 , L_38 ) ;
# ifndef F_12
F_2 ( V_15 , L_39 ) ;
# endif
#endif
#ifndef F_13
F_2 ( V_15 , L_40 ) ;
F_2 ( V_15 , L_41 ) ;
F_2 ( V_15 , L_42 ) ;
F_2 ( V_15 , L_43 ) ;
F_2 ( V_15 , L_44 , V_18 ) ;
#endif
F_2 ( V_15 , L_45 ) ;
F_2 ( V_15 , L_46 ) ;
F_2 ( V_15 , L_47 ) ;
F_2 ( V_15 , L_48 ) ;
F_2 ( V_15 , L_49 ) ;
F_2 ( V_15 , L_50 ) ;
F_2 ( V_15 , L_51 ) ;
F_2 ( V_15 , L_52 ) ;
F_2 ( V_15 , L_53 ) ;
F_2 ( V_15 , L_54 ) ;
F_2 ( V_15 , L_55 ) ;
F_2 ( V_15 , L_56 ) ;
F_2 ( V_15 , L_57 ) ;
F_2 ( V_15 , L_58 ) ;
F_2 ( V_15 , L_59 ) ;
F_2 ( V_15 , L_60 ) ;
F_2 ( V_15 , L_61 ) ;
#ifndef F_14
F_2 ( V_15 , L_62 ) ;
#endif
F_2 ( V_15 , L_63 , V_19 , V_19 ) ;
F_2 ( V_15 , L_64 ) ;
F_2 ( V_15 , L_65 ) ;
#ifndef F_15
F_2 ( V_15 , L_66 ) ;
F_2 ( V_15 , L_67 ) ;
F_2 ( V_15 , L_68 ) ;
F_2 ( V_15 , L_69 ) ;
# if ! F_16 ( V_20 )
F_2 ( V_15 , L_70 ) ;
# endif
#endif
F_2 ( V_15 , L_71 ) ;
F_2 ( V_15 , L_72 ) ;
F_2 ( V_15 , L_73 ) ;
F_2 ( V_15 , L_74 ) ;
}
static int T_3 F_17 ( T_1 * V_21 , int * V_22 , void * V_23 )
{
T_4 * V_24 = ( T_4 * ) V_23 ;
const char * V_25 = F_18 ( V_21 , V_26 ) ;
if ( F_19 ( V_21 ) != - 1 )
V_24 -> V_27 = ! F_20 ( V_21 ) && V_25 != NULL ;
else
F_2 ( V_15 , L_75 ) ;
return V_28 ;
}
static int F_21 ( T_2 * V_29 , T_2 * V_30 )
{
T_5 * V_31 = F_22 () ;
T_2 * V_24 = F_23 () ;
T_2 * V_32 = F_23 () ;
int V_8 =
V_30 != NULL && V_29 != NULL && V_31 != NULL && F_24 ( V_29 ) &&
F_25 ( V_29 , V_33 , V_31 , NULL ) &&
V_24 != NULL && F_26 ( V_24 , V_29 ) &&
F_25 ( V_24 , V_33 , V_31 , NULL ) &&
V_32 != NULL &&
F_27 ( V_32 , V_30 , V_24 , V_29 , V_31 ) &&
F_28 ( V_32 , 1 ) &&
F_29 ( V_32 , V_29 ) == 0 ;
if( V_32 )
F_5 ( V_32 ) ;
if( V_24 )
F_5 ( V_24 ) ;
if( V_31 )
F_30 ( V_31 ) ;
return V_8 ;
}
static int T_3 F_31 ( T_1 * V_21 , void * V_23 )
{
T_6 * V_34 = ( T_6 * ) V_23 ;
T_2 * V_29 = NULL , * V_30 = NULL ;
if ( ! ( V_29 = F_32 ( V_21 ) ) || ! ( V_30 = F_33 ( V_21 ) ) )
return 0 ;
if ( V_34 -> V_35 || V_34 -> V_36 || V_34 -> V_37 == 1 )
{
F_2 ( V_15 , L_76 ) ;
F_2 ( V_15 , L_77 ) ; F_34 ( V_15 , V_29 ) ;
F_2 ( V_15 , L_78 ) ; F_34 ( V_15 , V_30 ) ;
F_2 ( V_15 , L_11 ) ;
}
if ( F_35 ( V_30 , V_29 ) )
return 1 ;
if ( V_34 -> V_37 == 1 )
{
if ( V_34 -> V_35 )
F_2 ( V_15 , L_79 ) ;
if ( F_36 ( V_30 ) <= V_38 && F_21 ( V_29 , V_30 ) )
return 1 ;
}
F_2 ( V_15 , L_80 ) ;
return 0 ;
}
static char * T_3 F_37 ( T_1 * V_21 , void * V_23 )
{
T_6 * V_34 = ( T_6 * ) V_23 ;
char * V_39 = ( char * ) F_38 ( V_40 + 1 ) ;
T_7 V_41 ;
int V_42 ;
V_41 . V_43 = ( char * ) V_34 -> V_44 ;
V_41 . V_45 = L_81 ;
if ( ( V_42 = F_39 ( V_39 , V_40 , 0 , & V_41 ) ) < 0 )
{
F_2 ( V_15 , L_82 ) ;
F_40 ( V_39 ) ;
return NULL ;
}
* ( V_39 + V_42 ) = '\0' ;
return V_39 ;
}
static int F_41 ( T_1 * V_21 , unsigned char * * V_46 , unsigned char * V_47 , const unsigned char * V_48 , unsigned int V_49 , void * V_23 )
{
T_8 * V_50 = V_23 ;
if ( ! V_51 )
{
unsigned V_52 ;
F_2 ( V_11 , L_83 ) ;
for ( V_52 = 0 ; V_52 < V_49 ; )
{
if ( V_52 )
F_42 ( V_11 , L_84 , 2 ) ;
F_42 ( V_11 , & V_48 [ V_52 + 1 ] , V_48 [ V_52 ] ) ;
V_52 += V_48 [ V_52 ] + 1 ;
}
F_42 ( V_11 , L_11 , 1 ) ;
}
V_50 -> V_53 = F_43 ( V_46 , V_47 , V_48 , V_49 , V_50 -> V_54 , V_50 -> V_55 ) ;
return V_28 ;
}
int MAIN ( int V_56 , char * * V_57 )
{
unsigned int V_58 = 0 , V_59 = 0 ;
T_1 * V_60 = NULL ;
#ifndef F_44
T_9 * V_61 ;
#endif
int V_21 , V_62 , V_63 , V_64 = 0 ;
char * V_65 = NULL , * V_66 = NULL , * V_67 = NULL ;
int V_68 , V_69 ;
int V_70 , V_71 ;
T_10 V_72 , V_73 ;
short V_74 = V_75 ;
int V_76 = 1 ;
char * V_77 = V_16 ;
char * V_78 = NULL , * V_79 = NULL ;
int V_80 = V_81 , V_82 = V_81 ;
char * V_83 = NULL , * V_39 = NULL ;
T_11 * V_84 = NULL ;
T_12 * V_85 = NULL ;
char * V_86 = NULL , * V_87 = NULL , * V_88 = NULL ;
int V_89 = 0 , V_90 = 0 , V_91 = V_92 , V_93 = 0 ;
int V_94 = 0 ;
int V_95 , V_96 , V_97 , V_98 , V_99 , V_100 ;
T_13 * V_50 = NULL ;
int V_8 = 1 , V_101 = 1 , V_52 , V_102 = 0 ;
int V_103 = V_104 ;
int V_105 = 0 ;
T_14 * V_106 = NULL ;
int V_107 = 0 ;
const T_15 * V_108 = NULL ;
int V_109 = V_110 ;
T_16 * V_111 ;
char * V_112 = NULL ;
int V_113 = 0 ;
struct V_114 V_115 , * V_116 ;
#ifndef F_14
char * V_117 = NULL ;
char * V_118 = NULL ;
T_17 * V_119 = NULL ;
#endif
T_17 * V_120 = NULL ;
#if F_16 ( V_121 ) || F_16 ( V_122 ) || F_16 ( V_123 ) || F_16 ( V_124 )
struct V_114 V_125 ;
#if F_16 ( V_124 )
int V_126 = 0 ;
#endif
#endif
#ifndef F_15
char * V_127 = NULL ;
T_4 V_128 =
{ NULL , 0 } ;
# ifndef V_20
const char * V_129 = NULL ;
# endif
#endif
char * V_130 = NULL ;
char * V_131 = NULL ;
struct V_132 V_133 ;
int V_134 = sizeof( V_133 ) ;
int V_135 = 0 ;
long V_136 = 0 ;
#ifndef F_12
char * V_137 = NULL ;
#endif
#ifndef F_13
char * V_138 = NULL ;
int V_139 = 0 ;
T_6 V_34 = { NULL , NULL , 0 , 0 , 0 , 1024 } ;
#endif
#if ! F_16 ( V_140 ) && ! F_16 ( V_141 )
V_108 = F_45 () ;
#elif ! F_16 ( V_141 )
V_108 = F_46 () ;
#elif ! F_16 ( V_140 )
V_108 = F_47 () ;
#endif
F_48 () ;
V_142 = 0 ;
V_51 = 0 ;
V_143 = 0 ;
V_10 = 0 ;
V_144 = 0 ;
V_145 = 0 ;
if ( V_15 == NULL )
V_15 = F_49 ( V_146 , V_147 ) ;
if ( ! F_50 ( V_15 , NULL ) )
goto V_148;
if ( ( ( V_65 = F_38 ( V_149 ) ) == NULL ) ||
( ( V_66 = F_38 ( V_149 ) ) == NULL ) ||
( ( V_67 = F_38 ( V_149 ) ) == NULL ) )
{
F_2 ( V_15 , L_85 ) ;
goto V_148;
}
V_150 = 0 ;
V_151 = V_152 ;
#ifdef F_10
V_153 = 0 ;
#endif
V_56 -- ;
V_57 ++ ;
while ( V_56 >= 1 )
{
if ( strcmp ( * V_57 , L_86 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_77 = * ( ++ V_57 ) ;
}
else if ( strcmp ( * V_57 , L_87 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_74 = atoi ( * ( ++ V_57 ) ) ;
if ( V_74 == 0 ) goto V_154;
}
else if ( strcmp ( * V_57 , L_88 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
if ( ! F_51 ( * ( ++ V_57 ) , & V_77 , NULL , & V_74 ) )
goto V_154;
}
else if ( strcmp ( * V_57 , L_89 ) == 0 )
{
V_91 = V_155 ;
if ( -- V_56 < 1 ) goto V_154;
V_150 = atoi ( * ( ++ V_57 ) ) ;
F_2 ( V_15 , L_90 , V_150 ) ;
}
else if ( strcmp ( * V_57 , L_91 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_78 = * ( ++ V_57 ) ;
}
else if ( strcmp ( * V_57 , L_92 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_131 = * ( ++ V_57 ) ;
}
else if ( strcmp ( * V_57 , L_93 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_130 = * ( ++ V_57 ) ;
}
else if ( strcmp ( * V_57 , L_94 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_80 = F_52 ( * ( ++ V_57 ) ) ;
}
else if ( F_53 ( & V_57 , & V_56 , & V_107 , V_15 , & V_106 ) )
{
if ( V_107 )
goto V_154;
continue;
}
else if ( strcmp ( * V_57 , L_95 ) == 0 )
V_156 = 1 ;
else if ( strcmp ( * V_57 , L_96 ) == 0 )
V_105 = 1 ;
else if ( strcmp ( * V_57 , L_97 ) == 0 )
V_94 = 1 ;
else if ( strcmp ( * V_57 , L_98 ) == 0 )
{
V_51 = 1 ;
V_143 = 1 ;
}
else if ( strcmp ( * V_57 , L_99 ) == 0 )
V_143 = 1 ;
else if ( strcmp ( * V_57 , L_100 ) == 0 )
V_143 = 0 ;
else if ( strcmp ( * V_57 , L_101 ) == 0 )
V_142 = 1 ;
else if ( strcmp ( * V_57 , L_102 ) == 0 )
V_10 = 1 ;
#ifndef F_15
else if ( strcmp ( * V_57 , L_103 ) == 0 )
V_157 = 1 ;
else if ( strcmp ( * V_57 , L_104 ) == 0 )
V_158 = 1 ;
#endif
#ifdef F_9
else if ( strcmp ( * V_57 , L_105 ) == 0 )
F_54 () ;
#endif
else if ( strcmp ( * V_57 , L_106 ) == 0 )
V_144 = 1 ;
else if ( strcmp ( * V_57 , L_107 ) == 0 )
V_145 = 1 ;
else if ( strcmp ( * V_57 , L_108 ) == 0 )
V_102 = 1 ;
else if ( strcmp ( * V_57 , L_109 ) == 0 )
V_64 = 1 ;
#ifndef F_11
else if ( strcmp ( * V_57 , L_110 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_12 = * ( ++ V_57 ) ;
}
else if ( strcmp ( * V_57 , L_111 ) == 0 )
{
T_18 V_159 ;
if ( -- V_56 < 1 ) goto V_154;
V_14 = * ( ++ V_57 ) ;
for ( V_159 = 0 ; V_159 < strlen ( V_14 ) ; V_159 ++ )
{
if ( isxdigit ( ( unsigned char ) V_14 [ V_159 ] ) )
continue;
F_2 ( V_15 , L_112 , * V_57 ) ;
goto V_154;
}
}
#endif
#ifndef F_13
else if ( strcmp ( * V_57 , L_113 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_34 . V_160 = * ( ++ V_57 ) ;
V_108 = F_55 () ;
}
else if ( strcmp ( * V_57 , L_114 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_138 = * ( ++ V_57 ) ;
V_108 = F_55 () ;
}
else if ( strcmp ( * V_57 , L_115 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_34 . V_161 = atoi ( * ( ++ V_57 ) ) ;
F_2 ( V_15 , L_116 , V_34 . V_161 ) ;
V_108 = F_55 () ;
}
else if ( strcmp ( * V_57 , L_117 ) == 0 )
{
V_139 = 1 ;
V_108 = F_55 () ;
}
else if ( strcmp ( * V_57 , L_118 ) == 0 )
{
V_34 . V_37 = 1 ;
V_108 = F_55 () ;
}
#endif
#ifndef V_140
else if ( strcmp ( * V_57 , L_119 ) == 0 )
V_108 = F_47 () ;
#endif
#ifndef V_141
else if ( strcmp ( * V_57 , L_120 ) == 0 )
V_108 = F_46 () ;
#endif
#ifndef F_56
else if ( strcmp ( * V_57 , L_121 ) == 0 )
V_108 = F_57 () ;
else if ( strcmp ( * V_57 , L_122 ) == 0 )
V_108 = F_58 () ;
else if ( strcmp ( * V_57 , L_123 ) == 0 )
V_108 = F_55 () ;
#endif
#ifndef F_59
else if ( strcmp ( * V_57 , L_124 ) == 0 )
{
V_108 = F_60 () ;
V_109 = V_162 ;
}
else if ( strcmp ( * V_57 , L_125 ) == 0 )
V_135 = 1 ;
else if ( strcmp ( * V_57 , L_126 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_136 = atol ( * ( ++ V_57 ) ) ;
}
#endif
else if ( strcmp ( * V_57 , L_127 ) == 0 )
V_93 = 1 ;
else if ( strcmp ( * V_57 , L_128 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_82 = F_52 ( * ( ++ V_57 ) ) ;
}
else if ( strcmp ( * V_57 , L_129 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_83 = * ( ++ V_57 ) ;
}
else if ( strcmp ( * V_57 , L_130 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_79 = * ( ++ V_57 ) ;
}
else if ( strcmp ( * V_57 , L_131 ) == 0 )
{
V_89 = 5 ;
}
else if ( strcmp ( * V_57 , L_132 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_86 = * ( ++ V_57 ) ;
}
else if ( strcmp ( * V_57 , L_133 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_87 = * ( ++ V_57 ) ;
}
else if ( strcmp ( * V_57 , L_134 ) == 0 )
V_58 |= V_163 ;
else if ( strcmp ( * V_57 , L_135 ) == 0 )
V_58 |= V_164 ;
else if ( strcmp ( * V_57 , L_136 ) == 0 )
V_58 |= V_165 ;
else if ( strcmp ( * V_57 , L_137 ) == 0 )
V_58 |= V_166 ;
else if ( strcmp ( * V_57 , L_138 ) == 0 )
V_58 |= V_167 ;
else if ( strcmp ( * V_57 , L_139 ) == 0 )
{ V_58 |= V_168 ; }
#ifndef F_15
else if ( strcmp ( * V_57 , L_140 ) == 0 )
{ V_58 |= V_169 ; }
# ifndef V_20
else if ( strcmp ( * V_57 , L_141 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_129 = * ( ++ V_57 ) ;
}
# endif
#endif
else if ( strcmp ( * V_57 , L_142 ) == 0 )
V_58 |= V_170 ;
else if ( strcmp ( * V_57 , L_143 ) == 0 )
V_58 |= V_171 ;
else if ( strcmp ( * V_57 , L_144 ) == 0 )
{ V_58 |= V_172 ; }
else if ( strcmp ( * V_57 , L_145 ) == 0 )
{ V_59 |= V_172 ; }
else if ( strcmp ( * V_57 , L_146 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_88 = * ( ++ V_57 ) ;
}
#ifdef F_10
else if ( strcmp ( * V_57 , L_147 ) == 0 )
{ V_153 = 1 ; }
#endif
else if ( strcmp ( * V_57 , L_148 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
++ V_57 ;
if ( strcmp ( * V_57 , L_149 ) == 0 )
V_103 = V_173 ;
else if ( strcmp ( * V_57 , L_150 ) == 0 )
V_103 = V_174 ;
else if ( strcmp ( * V_57 , L_151 ) == 0 )
V_103 = V_175 ;
else if ( strcmp ( * V_57 , L_152 ) == 0 )
V_103 = V_176 ;
else if ( strcmp ( * V_57 , L_153 ) == 0 )
V_103 = V_177 ;
else
goto V_154;
}
#ifndef F_14
else if ( strcmp ( * V_57 , L_154 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_117 = * ( ++ V_57 ) ;
}
else if ( strcmp ( * V_57 , L_155 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_118 = * ( ++ V_57 ) ;
}
#endif
else if ( strcmp ( * V_57 , L_156 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_112 = * ( ++ V_57 ) ;
}
#ifndef F_15
else if ( strcmp ( * V_57 , L_157 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_127 = * ( ++ V_57 ) ;
}
#endif
#ifndef F_12
else if ( strcmp ( * V_57 , L_158 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_137 = * ++ V_57 ;
}
#endif
else if ( strcmp ( * V_57 , L_159 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_178 = * ( ++ V_57 ) ;
}
else if ( strcmp ( * V_57 , L_160 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_179 = * ( ++ V_57 ) ;
}
else if ( strcmp ( * V_57 , L_161 ) == 0 )
{
if ( -- V_56 < 1 ) goto V_154;
V_180 = atoi ( * ( ++ V_57 ) ) ;
if ( V_180 == 0 ) goto V_154;
}
else
{
F_2 ( V_15 , L_162 , * V_57 ) ;
V_90 = 1 ;
break;
}
V_56 -- ;
V_57 ++ ;
}
if ( V_90 )
{
V_154:
F_8 () ;
goto V_148;
}
#if ! F_16 ( F_12 ) && ! F_16 ( F_11 )
if ( V_137 )
{
if ( V_14 )
{
F_2 ( V_15 ,
L_163 ) ;
goto V_148;
}
V_12 = L_164 ;
if ( V_88 )
{
F_2 ( V_15 , L_165 ) ;
goto V_148;
}
V_88 = L_166 ;
}
#endif
F_61 () ;
F_62 () ;
#if ! F_16 ( F_15 ) && ! F_16 ( V_20 )
V_181 . V_53 = - 1 ;
if ( V_129 )
{
V_181 . V_54 = F_63 ( & V_181 . V_55 , V_129 ) ;
if ( V_181 . V_54 == NULL )
{
F_2 ( V_15 , L_167 ) ;
goto V_148;
}
}
else
V_181 . V_54 = NULL ;
#endif
#ifndef F_14
V_120 = F_64 ( V_15 , V_117 , 1 ) ;
if ( V_118 )
{
V_119 = F_65 ( V_118 ) ;
if ( ! V_119 )
{
F_2 ( V_15 ,
L_168 ) ;
goto V_148;
}
}
#endif
if ( ! F_66 ( V_15 , V_83 , NULL , & V_39 , NULL ) )
{
F_2 ( V_15 , L_169 ) ;
goto V_148;
}
if ( V_79 == NULL )
V_79 = V_78 ;
if ( V_79 )
{
V_85 = F_67 ( V_15 , V_79 , V_82 , 0 , V_39 , V_120 ,
L_170 ) ;
if ( ! V_85 )
{
F_68 ( V_15 ) ;
goto V_148;
}
}
if ( V_78 )
{
V_84 = F_69 ( V_15 , V_78 , V_80 ,
NULL , V_120 , L_171 ) ;
if ( ! V_84 )
{
F_68 ( V_15 ) ;
goto V_148;
}
}
if ( ! F_70 ( NULL , V_15 , 1 ) && V_112 == NULL
&& ! F_71 () )
{
F_2 ( V_15 , L_172 ) ;
}
if ( V_112 != NULL )
F_2 ( V_15 , L_173 ,
F_72 ( V_112 ) ) ;
if ( V_11 == NULL )
{
if ( V_51 && ! V_10 && ! V_144 )
{
V_11 = F_73 ( F_74 () ) ;
}
else
{
if ( V_11 == NULL )
V_11 = F_49 ( stdout , V_147 ) ;
}
}
#ifndef F_13
if( ! F_66 ( V_15 , V_138 , NULL , & V_34 . V_44 , NULL ) )
{
F_2 ( V_15 , L_169 ) ;
goto V_148;
}
#endif
V_50 = F_75 ( V_108 ) ;
if ( V_50 == NULL )
{
F_68 ( V_15 ) ;
goto V_148;
}
if ( V_106 )
F_76 ( V_50 , V_106 ) ;
#ifndef F_14
if ( V_119 )
{
if ( ! F_77 ( V_50 , V_119 ) )
{
F_78 ( V_15 , L_174 ) ;
F_68 ( V_15 ) ;
F_79 ( V_119 ) ;
goto V_148;
}
F_79 ( V_119 ) ;
}
#endif
#ifndef F_11
#ifdef F_12
if ( V_14 != NULL )
#else
if ( V_14 != NULL || V_137 )
#endif
{
if ( V_10 )
F_2 ( V_11 , L_175 ) ;
F_80 ( V_50 , F_1 ) ;
}
if ( V_178 != NULL )
F_81 ( V_50 , V_178 ) ;
#endif
if ( V_93 )
F_82 ( V_50 , V_182 | V_58 ) ;
else
F_82 ( V_50 , V_58 ) ;
if ( V_59 )
F_83 ( V_50 , V_59 ) ;
if ( V_109 == V_162 ) F_84 ( V_50 , 1 ) ;
#if ! F_16 ( F_15 ) && ! F_16 ( V_20 )
if ( V_181 . V_54 )
F_85 ( V_50 , F_41 , & V_181 ) ;
#endif
if ( V_64 ) F_86 ( V_50 , V_183 ) ;
if ( V_88 != NULL )
if( ! F_87 ( V_50 , V_88 ) ) {
F_2 ( V_15 , L_176 ) ;
F_68 ( V_15 ) ;
goto V_148;
}
#if 0
else
SSL_CTX_set_cipher_list(ctx,getenv("SSL_CIPHER"));
#endif
F_88 ( V_50 , V_91 , V_184 ) ;
if ( ! F_89 ( V_50 , V_84 , V_85 ) )
goto V_148;
if ( ( ! F_90 ( V_50 , V_87 , V_86 ) ) ||
( ! F_91 ( V_50 ) ) )
{
F_68 ( V_15 ) ;
}
#ifndef F_15
if ( V_127 != NULL )
{
V_128 . V_185 = V_15 ;
F_92 ( V_50 , F_17 ) ;
F_93 ( V_50 , & V_128 ) ;
}
#ifndef F_13
if ( V_34 . V_160 )
{
if ( ! V_139 && ! F_94 ( V_50 , V_34 . V_160 ) )
{
F_2 ( V_15 , L_177 ) ;
goto V_148;
}
V_34 . V_36 = V_144 ;
V_34 . V_35 = V_10 ;
F_95 ( V_50 , & V_34 ) ;
F_96 ( V_50 , F_37 ) ;
F_97 ( V_50 , V_34 . V_161 ) ;
if ( V_144 || V_10 || V_34 . V_37 == 0 )
F_98 ( V_50 , F_31 ) ;
}
#endif
#endif
V_60 = F_99 ( V_50 ) ;
if ( V_130 )
{
T_19 * V_186 ;
T_16 * V_187 = F_100 ( V_130 , L_178 ) ;
if ( ! V_187 )
{
F_2 ( V_15 , L_179 ,
V_130 ) ;
F_68 ( V_15 ) ;
goto V_148;
}
V_186 = F_101 ( V_187 , NULL , 0 , NULL ) ;
F_102 ( V_187 ) ;
if ( ! V_186 )
{
F_2 ( V_15 , L_179 ,
V_130 ) ;
F_68 ( V_15 ) ;
goto V_148;
}
F_103 ( V_60 , V_186 ) ;
F_104 ( V_186 ) ;
}
#ifndef F_15
if ( V_127 != NULL )
{
if ( ! F_105 ( V_60 , V_127 ) )
{
F_2 ( V_15 , L_180 ) ;
F_68 ( V_15 ) ;
goto V_148;
}
}
#endif
#ifndef F_44
if ( V_60 && ( V_61 = F_106 () ) != NULL )
{
F_107 ( V_60 , V_61 ) ;
F_108 ( V_61 , V_188 , V_77 ) ;
}
#endif
#if 0
#ifdef F_109
SSL_set_tlsext_opaque_prf_input(con, "Test client", 11);
#endif
#endif
V_189:
if ( F_110 ( & V_21 , V_77 , V_74 , V_109 ) == 0 )
{
F_2 ( V_15 , L_181 , F_111 () ) ;
F_112 ( V_21 ) ;
goto V_148;
}
F_2 ( V_11 , L_182 , V_21 ) ;
#ifdef F_10
if ( V_153 )
{
unsigned long V_42 = 1 ;
F_2 ( V_11 , L_183 ) ;
if ( F_113 ( V_21 , F_10 , & V_42 ) < 0 )
{
F_68 ( V_15 ) ;
goto V_148;
}
}
#endif
if ( V_142 & 0x01 ) F_114 ( V_60 , 1 ) ;
if ( F_115 ( V_60 ) == V_190 )
{
V_111 = F_116 ( V_21 , V_147 ) ;
if ( F_117 ( V_21 , & V_133 , ( void * ) & V_134 ) < 0 )
{
F_2 ( V_15 , L_184 ,
F_111 () ) ;
F_112 ( V_21 ) ;
goto V_148;
}
( void ) F_118 ( V_111 , 1 , & V_133 ) ;
if ( V_135 )
{
V_115 . V_191 = 0 ;
V_115 . V_192 = V_193 ;
F_119 ( V_111 , V_194 , 0 , & V_115 ) ;
V_115 . V_191 = 0 ;
V_115 . V_192 = V_195 ;
F_119 ( V_111 , V_196 , 0 , & V_115 ) ;
}
if ( V_136 > 28 )
{
F_120 ( V_60 , V_197 ) ;
F_121 ( V_60 , V_136 - 28 ) ;
}
else
F_119 ( V_111 , V_198 , 0 , NULL ) ;
}
else
V_111 = F_122 ( V_21 , V_147 ) ;
if ( V_102 )
{
T_16 * V_199 ;
V_199 = F_73 ( F_123 () ) ;
V_111 = F_124 ( V_199 , V_111 ) ;
}
if ( V_10 )
{
F_114 ( V_60 , 1 ) ;
F_125 ( V_111 , V_200 ) ;
F_126 ( V_111 , ( char * ) V_11 ) ;
}
if ( V_144 )
{
F_127 ( V_60 , V_201 ) ;
F_128 ( V_60 , V_11 ) ;
}
#ifndef F_15
if ( V_157 )
{
F_129 ( V_60 , V_202 ) ;
F_130 ( V_60 , V_11 ) ;
}
if ( V_158 )
{
F_131 ( V_60 , V_203 ) ;
F_132 ( V_50 , V_204 ) ;
F_133 ( V_50 , V_11 ) ;
#if 0
{
STACK_OF(OCSP_RESPID) *ids = sk_OCSP_RESPID_new_null();
OCSP_RESPID *id = OCSP_RESPID_new();
id->value.byKey = ASN1_OCTET_STRING_new();
id->type = V_OCSP_RESPID_KEY;
ASN1_STRING_set(id->value.byKey, "Hello World", -1);
sk_OCSP_RESPID_push(ids, id);
SSL_set_tlsext_status_ids(con, ids);
}
#endif
}
#endif
#ifndef F_12
if ( V_137 )
F_134 ( V_11 , V_111 , V_137 ) ;
#endif
F_135 ( V_60 , V_111 , V_111 ) ;
F_136 ( V_60 ) ;
V_63 = F_137 ( V_60 ) + 1 ;
V_96 = 1 ;
V_95 = 0 ;
V_99 = 0 ;
V_98 = 1 ;
V_97 = 1 ;
V_68 = 0 ;
V_69 = 0 ;
V_70 = 0 ;
V_71 = 0 ;
if ( V_103 == V_173 )
{
int V_205 = 0 ;
T_16 * V_206 = F_73 ( F_138 () ) ;
F_124 ( V_206 , V_111 ) ;
do
{
V_113 = F_139 ( V_206 , V_67 , V_149 ) ;
}
while ( V_113 > 3 && V_67 [ 3 ] == '-' );
F_2 ( V_206 , L_185 ) ;
( void ) F_140 ( V_206 ) ;
do
{
V_113 = F_139 ( V_206 , V_67 , V_149 ) ;
if ( strstr ( V_67 , L_186 ) )
V_205 = 1 ;
}
while ( V_113 > 3 && V_67 [ 3 ] == '-' );
( void ) F_140 ( V_206 ) ;
F_141 ( V_206 ) ;
F_102 ( V_206 ) ;
if ( ! V_205 )
F_2 ( V_15 ,
L_187
L_188 ) ;
F_2 ( V_111 , L_189 ) ;
F_142 ( V_111 , V_66 , V_149 ) ;
}
else if ( V_103 == V_174 )
{
F_142 ( V_111 , V_67 , V_149 ) ;
F_2 ( V_111 , L_190 ) ;
F_142 ( V_111 , V_66 , V_149 ) ;
}
else if ( V_103 == V_175 )
{
int V_205 = 0 ;
T_16 * V_206 = F_73 ( F_138 () ) ;
F_124 ( V_206 , V_111 ) ;
F_139 ( V_206 , V_67 , V_149 ) ;
F_2 ( V_206 , L_191 ) ;
( void ) F_140 ( V_206 ) ;
do
{
V_113 = F_139 ( V_206 , V_67 , V_149 ) ;
if ( strstr ( V_67 , L_186 ) )
V_205 = 1 ;
}
while ( V_113 > 3 && V_67 [ 0 ] != '.' );
( void ) F_140 ( V_206 ) ;
F_141 ( V_206 ) ;
F_102 ( V_206 ) ;
if ( ! V_205 )
F_2 ( V_15 ,
L_192
L_188 ) ;
F_2 ( V_111 , L_193 ) ;
F_142 ( V_111 , V_66 , V_149 ) ;
}
else if ( V_103 == V_176 )
{
T_16 * V_206 = F_73 ( F_138 () ) ;
F_124 ( V_206 , V_111 ) ;
do
{
V_113 = F_139 ( V_206 , V_67 , V_149 ) ;
}
while ( V_113 > 3 && V_67 [ 3 ] == '-' );
( void ) F_140 ( V_206 ) ;
F_141 ( V_206 ) ;
F_102 ( V_206 ) ;
F_2 ( V_111 , L_194 ) ;
F_142 ( V_111 , V_66 , V_149 ) ;
}
if ( V_103 == V_177 )
{
int V_207 = 0 ;
F_2 ( V_111 , L_195
L_196
L_197 , V_77 ) ;
V_207 = F_142 ( V_111 , V_67 , V_149 ) ;
V_67 [ V_207 ] = 0 ;
while ( ! strstr ( V_67 , L_198 ) )
{
if ( strstr ( V_67 , L_199 ) )
goto V_208;
V_207 = F_142 ( V_111 , V_67 , V_149 ) ;
V_67 [ V_207 ] = 0 ;
}
F_2 ( V_111 , L_200 ) ;
V_207 = F_142 ( V_111 , V_66 , V_149 ) ;
V_66 [ V_207 ] = 0 ;
if ( ! strstr ( V_66 , L_201 ) )
goto V_208;
V_67 [ 0 ] = 0 ;
}
for (; ; )
{
F_143 ( & V_72 ) ;
F_143 ( & V_73 ) ;
if ( ( F_115 ( V_60 ) == V_190 ) &&
F_144 ( V_60 , & V_115 ) )
V_116 = & V_115 ;
else
V_116 = NULL ;
if ( F_145 ( V_60 ) && ! F_146 ( V_60 ) )
{
V_101 = 1 ;
V_99 = 0 ;
}
else
{
V_99 = 1 ;
if ( V_101 )
{
V_101 = 0 ;
#if 0
#ifndef F_15
if (servername != NULL && !SSL_session_reused(con))
{
BIO_printf(bio_c_out,"Server did %sacknowledge servername extension.\n",tlsextcbp.ack?"":"not ");
}
#endif
#endif
if ( V_131 )
{
T_16 * V_187 = F_100 ( V_131 , L_202 ) ;
if ( V_187 )
{
F_147 ( V_187 , F_148 ( V_60 ) ) ;
F_102 ( V_187 ) ;
}
else
F_2 ( V_15 , L_203 , V_131 ) ;
}
F_149 ( V_11 , V_60 , V_76 ) ;
if ( V_76 > 0 ) V_76 -- ;
if ( V_103 )
{
F_2 ( V_15 , L_4 , V_67 ) ;
V_103 = V_104 ;
}
if ( V_89 )
{
V_89 -- ;
F_2 ( V_11 , L_204 ) ;
F_150 ( V_60 ) ;
F_136 ( V_60 ) ;
F_112 ( F_137 ( V_60 ) ) ;
goto V_189;
}
}
}
V_100 = V_98 && F_151 ( V_60 ) ;
if ( ! V_100 )
{
#if ! F_16 ( V_121 ) && ! F_16 ( V_122 ) && ! F_16 ( V_123 ) && ! F_16 ( V_124 )
if ( V_99 )
{
if ( V_96 ) F_152 ( fileno ( V_209 ) , & V_72 ) ;
if ( V_95 ) F_152 ( fileno ( stdout ) , & V_73 ) ;
}
if ( V_98 )
F_152 ( F_137 ( V_60 ) , & V_72 ) ;
if ( V_97 )
F_152 ( F_137 ( V_60 ) , & V_73 ) ;
#else
if( ! V_99 || ! V_95 ) {
if ( V_98 )
F_152 ( F_137 ( V_60 ) , & V_72 ) ;
if ( V_97 )
F_152 ( F_137 ( V_60 ) , & V_73 ) ;
}
#endif
#if F_16 ( V_121 ) || F_16 ( V_122 )
V_52 = 0 ;
if( ! V_95 ) {
if( V_96 ) {
V_125 . V_191 = 1 ;
V_125 . V_192 = 0 ;
V_52 = F_153 ( V_63 , ( void * ) & V_72 , ( void * ) & V_73 ,
NULL , & V_125 ) ;
#if F_16 ( V_210 ) || F_16 ( V_122 )
if( ! V_52 && ( ! F_154 () || ! V_96 ) ) continue;
#else
if( ! V_52 && ( ! ( ( F_154 () ) || ( V_211 == F_155 ( F_156 ( V_212 ) , 0 ) ) ) || ! V_96 ) ) continue;
#endif
} else V_52 = F_153 ( V_63 , ( void * ) & V_72 , ( void * ) & V_73 ,
NULL , V_116 ) ;
}
#elif F_16 ( V_123 )
if( ! V_95 ) {
if( V_96 ) {
V_125 . V_191 = 1 ;
V_125 . V_192 = 0 ;
V_52 = F_153 ( V_63 , ( void * ) & V_72 , ( void * ) & V_73 ,
NULL , & V_125 ) ;
} else V_52 = F_153 ( V_63 , ( void * ) & V_72 , ( void * ) & V_73 ,
NULL , V_116 ) ;
}
#elif F_16 ( V_124 )
V_52 = 0 ;
V_126 = 0 ;
( void ) F_157 ( fileno ( V_209 ) , V_213 , V_214 ) ;
if( ! V_95 ) {
if( V_96 ) {
V_125 . V_191 = 1 ;
V_125 . V_192 = 0 ;
V_52 = F_153 ( V_63 , ( void * ) & V_72 , ( void * ) & V_73 ,
NULL , & V_125 ) ;
if ( F_158 ( fileno ( V_209 ) , V_66 , 0 ) >= 0 )
V_126 = 1 ;
if ( ! V_52 && ( V_126 != 1 || ! V_96 ) )
continue;
} else V_52 = F_153 ( V_63 , ( void * ) & V_72 , ( void * ) & V_73 ,
NULL , V_116 ) ;
}
( void ) F_157 ( fileno ( V_209 ) , V_213 , 0 ) ;
#else
V_52 = F_153 ( V_63 , ( void * ) & V_72 , ( void * ) & V_73 ,
NULL , V_116 ) ;
#endif
if ( V_52 < 0 )
{
F_2 ( V_15 , L_205 ,
F_111 () ) ;
goto V_208;
}
}
if ( ( F_115 ( V_60 ) == V_190 ) && F_159 ( V_60 ) > 0 )
{
F_2 ( V_15 , L_206 ) ;
}
if ( ! V_100 && F_160 ( F_137 ( V_60 ) , & V_73 ) )
{
V_62 = F_161 ( V_60 , & ( V_65 [ V_69 ] ) ,
( unsigned int ) V_68 ) ;
switch ( F_162 ( V_60 , V_62 ) )
{
case V_215 :
V_69 += V_62 ;
V_68 -= V_62 ;
if ( V_62 <= 0 ) goto V_148;
if ( V_68 <= 0 )
{
V_96 = 1 ;
V_97 = 0 ;
}
else
{
V_96 = 0 ;
V_97 = 1 ;
}
break;
case V_216 :
F_2 ( V_11 , L_207 ) ;
V_97 = 1 ;
V_96 = 0 ;
break;
case V_217 :
F_2 ( V_11 , L_208 ) ;
V_95 = 0 ;
V_98 = 1 ;
V_97 = 0 ;
break;
case V_218 :
F_2 ( V_11 , L_209 ) ;
break;
case V_219 :
if ( V_68 != 0 )
{
F_2 ( V_11 , L_210 ) ;
V_8 = 0 ;
goto V_208;
}
else
{
V_96 = 1 ;
V_97 = 0 ;
break;
}
case V_220 :
if ( ( V_62 != 0 ) || ( V_68 != 0 ) )
{
F_2 ( V_15 , L_211 ,
F_111 () ) ;
goto V_208;
}
else
{
V_96 = 1 ;
V_97 = 0 ;
}
break;
case V_221 :
F_68 ( V_15 ) ;
goto V_208;
}
}
#if F_16 ( V_121 ) || F_16 ( V_122 ) || F_16 ( V_123 ) || F_16 ( V_124 )
else if ( ! V_100 && V_95 )
#else
else if ( ! V_100 && F_160 ( fileno ( stdout ) , & V_73 ) )
#endif
{
#ifdef F_163
F_164 ( & ( V_66 [ V_71 ] ) , & ( V_66 [ V_71 ] ) , V_70 ) ;
#endif
V_52 = F_165 ( & ( V_66 [ V_71 ] ) , V_70 ) ;
if ( V_52 <= 0 )
{
F_2 ( V_11 , L_212 ) ;
V_8 = 0 ;
goto V_208;
}
V_70 -= V_52 ; ;
V_71 += V_52 ;
if ( V_70 <= 0 )
{
V_98 = 1 ;
V_95 = 0 ;
}
}
else if ( V_100 || F_160 ( F_137 ( V_60 ) , & V_72 ) )
{
#ifdef F_166
{ static int V_222 ; if ( ++ V_222 == 52 ) { F_167 ( V_60 ) ; V_222 = 0 ; } }
#endif
#if 1
V_62 = F_168 ( V_60 , V_66 , 1024 ) ;
#else
V_62 = F_168 ( V_60 , V_66 , 16 ) ;
{ char V_223 [ 10240 ] ;
printf ( L_213 , V_62 , F_151 ( V_60 ) , F_169 ( V_60 , V_223 , 10240 ) ) ;
}
#endif
switch ( F_162 ( V_60 , V_62 ) )
{
case V_215 :
if ( V_62 <= 0 )
goto V_148;
V_71 = 0 ;
V_70 = V_62 ;
V_98 = 0 ;
V_95 = 1 ;
break;
case V_216 :
F_2 ( V_11 , L_214 ) ;
V_97 = 1 ;
V_96 = 0 ;
break;
case V_217 :
F_2 ( V_11 , L_215 ) ;
V_95 = 0 ;
V_98 = 1 ;
if ( ( V_96 == 0 ) && ( V_97 == 0 ) )
V_97 = 1 ;
break;
case V_218 :
F_2 ( V_11 , L_216 ) ;
break;
case V_220 :
V_8 = F_111 () ;
F_2 ( V_15 , L_217 , V_8 ) ;
goto V_208;
case V_219 :
F_2 ( V_11 , L_218 ) ;
V_8 = 0 ;
goto V_208;
case V_221 :
F_68 ( V_15 ) ;
goto V_208;
}
}
#if F_16 ( V_121 ) || F_16 ( V_122 )
#if F_16 ( V_210 ) || F_16 ( V_122 )
else if ( F_154 () )
#else
else if ( ( F_154 () ) || ( V_211 == F_155 ( F_156 ( V_212 ) , 0 ) ) )
#endif
#elif F_16 ( V_123 )
else if ( F_154 () )
#elif F_16 ( V_124 )
else if ( V_126 )
#else
else if ( F_160 ( fileno ( V_209 ) , & V_72 ) )
#endif
{
if ( V_94 )
{
int V_159 , V_224 ;
V_52 = F_170 ( V_65 , V_149 / 2 ) ;
V_224 = 0 ;
for ( V_159 = 0 ; V_159 < V_52 ; V_159 ++ )
if ( V_65 [ V_159 ] == '\n' )
V_224 ++ ;
for ( V_159 = V_52 - 1 ; V_159 >= 0 ; V_159 -- )
{
V_65 [ V_159 + V_224 ] = V_65 [ V_159 ] ;
if ( V_65 [ V_159 ] == '\n' )
{
V_224 -- ;
V_52 ++ ;
V_65 [ V_159 + V_224 ] = '\r' ;
}
}
assert ( V_224 == 0 ) ;
}
else
V_52 = F_170 ( V_65 , V_149 ) ;
if ( ( ! V_143 ) && ( ( V_52 <= 0 ) || ( V_65 [ 0 ] == 'Q' ) ) )
{
F_2 ( V_15 , L_212 ) ;
V_8 = 0 ;
goto V_208;
}
if ( ( ! V_143 ) && ( V_65 [ 0 ] == 'R' ) )
{
F_2 ( V_15 , L_219 ) ;
F_167 ( V_60 ) ;
V_68 = 0 ;
}
#ifndef F_171
else if ( ( ! V_143 ) && ( V_65 [ 0 ] == 'B' ) )
{
F_2 ( V_15 , L_220 ) ;
F_172 ( V_60 ) ;
V_68 = 0 ;
}
#endif
else
{
V_68 = V_52 ;
V_69 = 0 ;
#ifdef F_163
F_173 ( V_65 , V_65 , V_52 ) ;
#endif
}
V_97 = 1 ;
V_96 = 0 ;
}
}
V_8 = 0 ;
V_208:
if ( V_101 )
F_149 ( V_11 , V_60 , V_76 ) ;
F_150 ( V_60 ) ;
F_112 ( F_137 ( V_60 ) ) ;
V_148:
if ( V_60 != NULL )
{
if ( V_105 != 0 )
F_149 ( V_11 , V_60 , 1 ) ;
F_174 ( V_60 ) ;
}
if ( V_50 != NULL ) F_175 ( V_50 ) ;
if ( V_84 )
F_176 ( V_84 ) ;
if ( V_85 )
F_177 ( V_85 ) ;
if ( V_39 )
F_40 ( V_39 ) ;
if ( V_65 != NULL ) { F_178 ( V_65 , V_149 ) ; F_40 ( V_65 ) ; }
if ( V_66 != NULL ) { F_178 ( V_66 , V_149 ) ; F_40 ( V_66 ) ; }
if ( V_67 != NULL ) { F_178 ( V_67 , V_149 ) ; F_40 ( V_67 ) ; }
if ( V_11 != NULL )
{
F_102 ( V_11 ) ;
V_11 = NULL ;
}
F_179 () ;
F_180 ( V_8 ) ;
}
static void F_149 ( T_16 * V_225 , T_1 * V_21 , int V_226 )
{
T_11 * V_133 = NULL ;
char * V_24 ;
static const char * V_227 = L_221 ;
char V_228 [ V_229 ] ;
F_181 ( T_11 ) * V_230 ;
F_181 ( V_231 ) * V_232 ;
const T_20 * V_233 ;
V_231 * V_234 ;
int V_159 , V_52 ;
#ifndef F_182
const T_21 * V_235 , * V_236 ;
#endif
unsigned char * V_237 ;
if ( V_226 )
{
int V_238 = 0 ;
V_230 = F_183 ( V_21 ) ;
if ( V_230 != NULL )
{
V_238 = 1 ;
F_2 ( V_225 , L_222 ) ;
for ( V_52 = 0 ; V_52 < F_184 ( V_230 ) ; V_52 ++ )
{
F_185 ( F_186 (
F_187 ( V_230 , V_52 ) ) , V_228 , sizeof V_228 ) ;
F_2 ( V_225 , L_223 , V_52 , V_228 ) ;
F_185 ( F_188 (
F_187 ( V_230 , V_52 ) ) , V_228 , sizeof V_228 ) ;
F_2 ( V_225 , L_224 , V_228 ) ;
if ( V_145 )
F_189 ( V_225 , F_187 ( V_230 , V_52 ) ) ;
}
}
F_2 ( V_225 , L_225 ) ;
V_133 = F_190 ( V_21 ) ;
if ( V_133 != NULL )
{
F_2 ( V_225 , L_226 ) ;
if ( ! ( V_145 && V_238 ) )
F_189 ( V_225 , V_133 ) ;
F_185 ( F_186 ( V_133 ) ,
V_228 , sizeof V_228 ) ;
F_2 ( V_225 , L_227 , V_228 ) ;
F_185 ( F_188 ( V_133 ) ,
V_228 , sizeof V_228 ) ;
F_2 ( V_225 , L_228 , V_228 ) ;
}
else
F_2 ( V_225 , L_229 ) ;
V_232 = F_191 ( V_21 ) ;
if ( ( V_232 != NULL ) && ( F_192 ( V_232 ) > 0 ) )
{
F_2 ( V_225 , L_230 ) ;
for ( V_52 = 0 ; V_52 < F_192 ( V_232 ) ; V_52 ++ )
{
V_234 = F_193 ( V_232 , V_52 ) ;
F_185 ( V_234 , V_228 , sizeof( V_228 ) ) ;
F_42 ( V_225 , V_228 , strlen ( V_228 ) ) ;
F_42 ( V_225 , L_11 , 1 ) ;
}
}
else
{
F_2 ( V_225 , L_231 ) ;
}
V_24 = F_194 ( V_21 , V_228 , sizeof V_228 ) ;
if ( V_24 != NULL )
{
F_2 ( V_225 , L_232 ) ;
V_159 = V_52 = 0 ;
while ( * V_24 )
{
if ( * V_24 == ':' )
{
F_42 ( V_225 , V_227 , 15 - V_159 % 25 ) ;
V_52 ++ ;
V_159 = 0 ;
F_42 ( V_225 , ( ( V_52 % 3 ) ? L_233 : L_11 ) , 1 ) ;
}
else
{
F_42 ( V_225 , V_24 , 1 ) ;
V_159 ++ ;
}
V_24 ++ ;
}
F_42 ( V_225 , L_11 , 1 ) ;
}
F_2 ( V_225 , L_234 ,
F_195 ( F_196 ( V_21 ) ) ,
F_197 ( F_198 ( V_21 ) ) ) ;
}
F_2 ( V_225 , ( F_199 ( V_21 ) ? L_235 : L_236 ) ) ;
V_233 = F_200 ( V_21 ) ;
F_2 ( V_225 , L_237 ,
F_201 ( V_233 ) ,
F_202 ( V_233 ) ) ;
if ( V_133 != NULL ) {
T_12 * V_239 ;
V_239 = F_203 ( V_133 ) ;
F_2 ( V_225 , L_238 ,
F_204 ( V_239 ) ) ;
F_177 ( V_239 ) ;
}
F_2 ( V_225 , L_239 ,
F_205 ( V_21 ) ? L_240 : L_241 ) ;
#ifndef F_182
V_235 = F_206 ( V_21 ) ;
V_236 = F_207 ( V_21 ) ;
F_2 ( V_225 , L_242 ,
V_235 ? F_208 ( V_235 ) : L_243 ) ;
F_2 ( V_225 , L_244 ,
V_236 ? F_208 ( V_236 ) : L_243 ) ;
#endif
#ifdef F_209
{
int V_240 ;
struct V_241 V_242 ;
T_22 V_243 = sizeof( V_242 ) ;
V_240 = F_137 ( V_21 ) ;
F_117 ( V_240 , (struct V_132 * ) & V_242 , & V_243 ) ;
F_2 ( V_11 , L_245 , F_210 ( V_242 . V_244 ) ) ;
}
#endif
#if ! F_16 ( F_15 ) && ! F_16 ( V_20 )
if ( V_181 . V_53 != - 1 ) {
const unsigned char * V_245 ;
unsigned int V_246 ;
F_211 ( V_21 , & V_245 , & V_246 ) ;
F_2 ( V_225 , L_246 , V_181 . V_53 ) ;
F_42 ( V_225 , V_245 , V_246 ) ;
F_42 ( V_225 , L_11 , 1 ) ;
}
#endif
{
T_23 * V_247 = F_212 ( V_21 ) ;
if( V_247 )
F_2 ( V_225 , L_247 ,
V_247 -> V_248 ) ;
}
F_213 ( V_225 , F_148 ( V_21 ) ) ;
if ( V_179 != NULL )
{
F_2 ( V_225 , L_248 ) ;
F_2 ( V_225 , L_249 , V_179 ) ;
F_2 ( V_225 , L_250 , V_180 ) ;
V_237 = F_38 ( V_180 ) ;
if ( V_237 != NULL )
{
if ( ! F_214 ( V_21 , V_237 ,
V_180 ,
V_179 ,
strlen ( V_179 ) ,
NULL , 0 , 0 ) )
{
F_2 ( V_225 , L_251 ) ;
}
else
{
F_2 ( V_225 , L_252 ) ;
for ( V_52 = 0 ; V_52 < V_180 ; V_52 ++ )
F_2 ( V_225 , L_253 ,
V_237 [ V_52 ] ) ;
F_2 ( V_225 , L_11 ) ;
}
F_40 ( V_237 ) ;
}
}
F_2 ( V_225 , L_225 ) ;
if ( V_133 != NULL )
F_176 ( V_133 ) ;
( void ) F_140 ( V_225 ) ;
}
static int V_204 ( T_1 * V_21 , void * V_23 )
{
const unsigned char * V_24 ;
int V_55 ;
T_24 * V_249 ;
V_55 = F_215 ( V_21 , & V_24 ) ;
F_78 ( V_23 , L_254 ) ;
if ( ! V_24 )
{
F_78 ( V_23 , L_255 ) ;
return 1 ;
}
V_249 = F_216 ( NULL , & V_24 , V_55 ) ;
if ( ! V_249 )
{
F_78 ( V_23 , L_256 ) ;
F_217 ( V_23 , ( char * ) V_24 , V_55 , 4 ) ;
return 0 ;
}
F_78 ( V_23 , L_257 ) ;
F_218 ( V_23 , V_249 , 0 ) ;
F_78 ( V_23 , L_258 ) ;
F_219 ( V_249 ) ;
return 1 ;
}
