static unsigned int F_1 ( T_1 * V_1 , const char * V_2 , char * V_3 ,
unsigned int V_4 ,
unsigned char * V_5 ,
unsigned int V_6 )
{
unsigned int V_7 = 0 ;
int V_8 ;
T_2 * V_9 = NULL ;
if ( V_10 )
F_2 ( V_11 , L_1 ) ;
if ( ! V_2 ) {
if ( V_10 )
F_2 ( V_11 ,
L_2 ) ;
} else if ( V_10 )
F_2 ( V_11 , L_3 , V_2 ) ;
V_8 = F_3 ( V_3 , V_4 , L_4 , V_12 ) ;
if ( V_8 < 0 || ( unsigned int ) V_8 > V_4 )
goto V_13;
if ( V_10 )
F_2 ( V_11 , L_5 , V_3 ,
V_8 ) ;
V_8 = F_4 ( & V_9 , V_14 ) ;
if ( ! V_8 ) {
F_2 ( V_15 , L_6 ,
V_14 ) ;
if ( V_9 )
F_5 ( V_9 ) ;
return 0 ;
}
if ( ( unsigned int ) F_6 ( V_9 ) > V_6 ) {
F_2 ( V_15 ,
L_7 ,
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
F_2 ( V_15 ,
L_14 ,
V_16 , V_17 ) ;
F_2 ( V_15 ,
L_15 ) ;
F_2 ( V_15 ,
L_16 ) ;
F_2 ( V_15 ,
L_17 ) ;
F_2 ( V_15 ,
L_18 ) ;
F_2 ( V_15 ,
L_19 ) ;
F_2 ( V_15 ,
L_20 ) ;
F_2 ( V_15 ,
L_21 ) ;
F_2 ( V_15 ,
L_22 ) ;
F_2 ( V_15 , L_23 ) ;
F_2 ( V_15 ,
L_24 ) ;
F_2 ( V_15 ,
L_25 ) ;
F_2 ( V_15 , L_26 ) ;
F_2 ( V_15 , L_27 ) ;
F_2 ( V_15 ,
L_28 ) ;
F_2 ( V_15 ,
L_29 ) ;
F_2 ( V_15 ,
L_30 ) ;
F_2 ( V_15 ,
L_31 ) ;
F_2 ( V_15 , L_32 ) ;
#ifdef F_9
F_2 ( V_15 , L_33 ) ;
#endif
F_2 ( V_15 , L_34 ) ;
F_2 ( V_15 , L_35 ) ;
F_2 ( V_15 , L_36 ) ;
#ifdef F_10
F_2 ( V_15 , L_37 ) ;
#endif
F_2 ( V_15 ,
L_38 ) ;
F_2 ( V_15 , L_39 ) ;
F_2 ( V_15 ,
L_40 ) ;
F_2 ( V_15 , L_41 ) ;
#ifndef F_11
F_2 ( V_15 , L_42 ) ;
F_2 ( V_15 , L_43 ) ;
# ifndef F_12
F_2 ( V_15 , L_44 ) ;
# endif
#endif
#ifndef F_13
F_2 ( V_15 ,
L_45 ) ;
F_2 ( V_15 , L_46 ) ;
F_2 ( V_15 ,
L_47 ) ;
F_2 ( V_15 ,
L_48 ) ;
F_2 ( V_15 ,
L_49 ,
V_18 ) ;
#endif
F_2 ( V_15 , L_50 ) ;
#ifndef F_14
F_2 ( V_15 , L_51 ) ;
#endif
F_2 ( V_15 , L_52 ) ;
F_2 ( V_15 , L_53 ) ;
F_2 ( V_15 , L_54 ) ;
F_2 ( V_15 , L_55 ) ;
F_2 ( V_15 , L_56 ) ;
F_2 ( V_15 , L_57 ) ;
F_2 ( V_15 ,
L_58 ) ;
F_2 ( V_15 ,
L_59 ) ;
F_2 ( V_15 ,
L_60 ) ;
F_2 ( V_15 ,
L_61 ) ;
F_2 ( V_15 ,
L_62 ) ;
F_2 ( V_15 ,
L_63 ) ;
F_2 ( V_15 ,
L_64 ) ;
F_2 ( V_15 ,
L_65 ) ;
F_2 ( V_15 ,
L_66 ) ;
F_2 ( V_15 , L_67 ) ;
#ifndef F_15
F_2 ( V_15 ,
L_68 ) ;
#endif
F_2 ( V_15 , L_69 , V_19 ,
V_19 ) ;
F_2 ( V_15 , L_70 ) ;
F_2 ( V_15 , L_71 ) ;
#ifndef F_16
F_2 ( V_15 ,
L_72 ) ;
F_2 ( V_15 ,
L_73 ) ;
F_2 ( V_15 ,
L_74 ) ;
F_2 ( V_15 ,
L_75 ) ;
F_2 ( V_15 ,
L_76 ) ;
#endif
#ifndef F_17
F_2 ( V_15 ,
L_77 ) ;
#endif
F_2 ( V_15 ,
L_78 ) ;
F_2 ( V_15 ,
L_79 ) ;
#ifndef F_18
F_2 ( V_15 ,
L_80 ) ;
#endif
F_2 ( V_15 ,
L_81 ) ;
F_2 ( V_15 ,
L_82 ) ;
}
static int T_3 F_19 ( T_1 * V_20 , int * V_21 , void * V_22 )
{
T_4 * V_23 = ( T_4 * ) V_22 ;
const char * V_24 = F_20 ( V_20 , V_25 ) ;
if ( F_21 ( V_20 ) != - 1 )
V_23 -> V_26 = ! F_22 ( V_20 ) && V_24 != NULL ;
else
F_2 ( V_15 , L_83 ) ;
return V_27 ;
}
static int F_23 ( T_2 * V_28 , T_2 * V_29 )
{
T_5 * V_30 = F_24 () ;
T_2 * V_23 = F_25 () ;
T_2 * V_31 = F_25 () ;
int V_8 =
V_29 != NULL && V_28 != NULL && V_30 != NULL && F_26 ( V_28 ) &&
F_27 ( V_28 , V_32 , V_30 , NULL ) &&
V_23 != NULL && F_28 ( V_23 , V_28 ) &&
F_27 ( V_23 , V_32 , V_30 , NULL ) &&
V_31 != NULL &&
F_29 ( V_31 , V_29 , V_23 , V_28 , V_30 ) &&
F_30 ( V_31 , 1 ) && F_31 ( V_31 , V_28 ) == 0 ;
if ( V_31 )
F_5 ( V_31 ) ;
if ( V_23 )
F_5 ( V_23 ) ;
if ( V_30 )
F_32 ( V_30 ) ;
return V_8 ;
}
static int T_3 F_33 ( T_1 * V_20 , void * V_22 )
{
T_6 * V_33 = ( T_6 * ) V_22 ;
T_2 * V_28 = NULL , * V_29 = NULL ;
if ( ! ( V_28 = F_34 ( V_20 ) ) || ! ( V_29 = F_35 ( V_20 ) ) )
return 0 ;
if ( V_33 -> V_34 || V_33 -> V_35 || V_33 -> V_36 == 1 ) {
F_2 ( V_15 , L_84 ) ;
F_2 ( V_15 , L_85 ) ;
F_36 ( V_15 , V_28 ) ;
F_2 ( V_15 , L_86 ) ;
F_36 ( V_15 , V_29 ) ;
F_2 ( V_15 , L_11 ) ;
}
if ( F_37 ( V_29 , V_28 ) )
return 1 ;
if ( V_33 -> V_36 == 1 ) {
if ( V_33 -> V_34 )
F_2 ( V_15 ,
L_87 ) ;
if ( F_38 ( V_29 ) <= V_37 && F_23 ( V_28 , V_29 ) )
return 1 ;
}
F_2 ( V_15 , L_88 ) ;
return 0 ;
}
static char * T_3 F_39 ( T_1 * V_20 , void * V_22 )
{
T_6 * V_33 = ( T_6 * ) V_22 ;
char * V_38 = ( char * ) F_40 ( V_39 + 1 ) ;
T_7 V_40 ;
int V_41 ;
V_40 . V_42 = ( char * ) V_33 -> V_43 ;
V_40 . V_44 = L_89 ;
if ( ( V_41 = F_41 ( V_38 , V_39 , 0 , & V_40 ) ) < 0 ) {
F_2 ( V_15 , L_90 ) ;
F_42 ( V_38 ) ;
return NULL ;
}
* ( V_38 + V_41 ) = '\0' ;
return V_38 ;
}
static int F_43 ( T_1 * V_20 , unsigned char * * V_45 , unsigned char * V_46 ,
const unsigned char * V_47 , unsigned int V_48 ,
void * V_22 )
{
T_8 * V_49 = V_22 ;
if ( ! V_50 ) {
unsigned V_51 ;
F_2 ( V_11 , L_91 ) ;
for ( V_51 = 0 ; V_51 < V_48 ; ) {
if ( V_51 )
F_44 ( V_11 , L_92 , 2 ) ;
F_44 ( V_11 , & V_47 [ V_51 + 1 ] , V_47 [ V_51 ] ) ;
V_51 += V_47 [ V_51 ] + 1 ;
}
F_44 ( V_11 , L_11 , 1 ) ;
}
V_49 -> V_52 =
F_45 ( V_45 , V_46 , V_47 , V_48 , V_49 -> V_53 , V_49 -> V_54 ) ;
return V_27 ;
}
static int F_46 ( T_1 * V_20 , unsigned int V_55 ,
const unsigned char * V_47 , T_9 V_48 ,
int * V_56 , void * V_22 )
{
char V_57 [ 100 ] ;
unsigned char V_58 [ 4 + 65536 ] ;
V_58 [ 0 ] = V_55 >> 8 ;
V_58 [ 1 ] = V_55 & 0xFF ;
V_58 [ 2 ] = V_48 >> 8 ;
V_58 [ 3 ] = V_48 & 0xFF ;
memcpy ( V_58 + 4 , V_47 , V_48 ) ;
F_3 ( V_57 , sizeof( V_57 ) , L_93 ,
V_55 ) ;
F_47 ( V_11 , V_57 , L_94 , V_58 , 4 + V_48 ) ;
return 1 ;
}
int MAIN ( int V_59 , char * * V_60 )
{
int V_61 = 0 ;
T_1 * V_62 = NULL ;
#ifndef F_48
T_10 * V_63 ;
#endif
int V_20 , V_64 , V_65 , V_66 = 0 ;
char * V_67 = NULL , * V_68 = NULL , * V_69 = NULL ;
int V_70 , V_71 ;
int V_72 , V_73 ;
T_11 V_74 , V_75 ;
short V_76 = V_77 ;
int V_78 = 1 ;
char * V_79 = V_16 ;
char * V_80 = NULL , * V_81 = NULL , * V_82 = NULL ;
int V_83 = V_84 , V_85 = V_84 ;
char * V_86 = NULL , * V_38 = NULL ;
T_12 * V_87 = NULL ;
T_13 * V_88 = NULL ;
F_49 ( T_12 ) * V_89 = NULL ;
char * V_90 = NULL , * V_91 = NULL ;
char * V_92 = NULL , * V_93 = NULL ;
char * V_94 = NULL , * V_95 = NULL ;
int V_96 = 0 , V_97 = 0 , V_98 = V_99 ;
int V_100 = 0 ;
int V_101 , V_102 , V_103 , V_104 , V_105 , V_106 ;
T_14 * V_49 = NULL ;
int V_8 = 1 , V_107 = 1 , V_51 , V_108 = 0 ;
int V_109 = V_110 ;
int V_111 = 0 ;
T_15 * V_112 = NULL ;
int V_113 = 0 ;
const T_16 * V_114 = NULL ;
int V_115 = V_116 ;
T_17 * V_117 ;
char * V_118 = NULL ;
int V_119 = 0 ;
struct V_120 V_121 , * V_122 ;
#ifndef F_15
char * V_123 = NULL ;
char * V_124 = NULL ;
T_18 * V_125 = NULL ;
#endif
T_18 * V_126 = NULL ;
#if F_50 ( V_127 ) || F_50 ( V_128 ) || F_50 ( V_129 ) || F_50 ( V_130 )
struct V_120 V_131 ;
# if F_50 ( V_130 )
int V_132 = 0 ;
# endif
#endif
#ifndef F_16
char * V_133 = NULL ;
T_4 V_134 = { NULL , 0 } ;
# ifndef F_17
const char * V_135 = NULL ;
# endif
const char * V_136 = NULL ;
# define F_51 100
unsigned short V_137 [ F_51 ] ;
int V_138 = 0 ;
#endif
char * V_139 = NULL ;
char * V_140 = NULL ;
struct V_141 V_142 ;
int V_143 = sizeof( V_142 ) ;
int V_144 = 0 ;
int V_145 = 0 ;
long V_146 = 0 ;
#ifndef F_12
static char * V_147 = NULL ;
# define F_52 !jpake_secret
#else
# define F_52 1
#endif
#ifndef F_13
char * V_148 = NULL ;
int V_149 = 0 ;
T_6 V_33 = { NULL , NULL , 0 , 0 , 0 , 1024 } ;
#endif
T_19 * V_150 = NULL ;
T_20 * V_151 = NULL ;
F_49 ( V_152 ) * V_153 = NULL ;
char * V_154 = NULL ;
int V_155 = V_84 ;
int V_156 = 0 ;
F_49 ( V_157 ) * V_158 = NULL ;
V_114 = F_53 () ;
F_54 () ;
V_159 = 0 ;
V_50 = 0 ;
V_160 = 0 ;
V_10 = 0 ;
V_161 = 0 ;
V_162 = 0 ;
if ( V_15 == NULL )
V_15 = F_55 ( V_163 , V_164 ) ;
if ( ! F_56 ( V_15 , NULL ) )
goto V_165;
V_151 = F_57 () ;
if ( ! V_151 )
goto V_165;
F_58 ( V_151 , V_166 ) ;
F_58 ( V_151 , V_167 ) ;
if ( ( ( V_67 = F_40 ( V_168 ) ) == NULL ) ||
( ( V_68 = F_40 ( V_168 ) ) == NULL ) ||
( ( V_69 = F_40 ( V_168 ) ) == NULL ) ) {
F_2 ( V_15 , L_95 ) ;
goto V_165;
}
V_169 = 0 ;
V_170 = V_171 ;
#ifdef F_10
V_172 = 0 ;
#endif
V_59 -- ;
V_60 ++ ;
while ( V_59 >= 1 ) {
if ( strcmp ( * V_60 , L_96 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_79 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_97 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_76 = atoi ( * ( ++ V_60 ) ) ;
if ( V_76 == 0 )
goto V_173;
} else if ( strcmp ( * V_60 , L_98 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
if ( ! F_59 ( * ( ++ V_60 ) , & V_79 , NULL , & V_76 ) )
goto V_173;
} else if ( strcmp ( * V_60 , L_99 ) == 0 ) {
V_98 = V_174 ;
if ( -- V_59 < 1 )
goto V_173;
V_169 = atoi ( * ( ++ V_60 ) ) ;
if ( ! V_50 )
F_2 ( V_15 , L_100 , V_169 ) ;
} else if ( strcmp ( * V_60 , L_101 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_80 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_102 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_154 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_103 ) == 0 )
V_156 = 1 ;
else if ( strcmp ( * V_60 , L_104 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_140 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_105 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_139 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_106 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_83 = F_60 ( * ( ++ V_60 ) ) ;
} else if ( strcmp ( * V_60 , L_107 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_155 = F_60 ( * ( ++ V_60 ) ) ;
} else if ( F_61 ( & V_60 , & V_59 , & V_113 , V_15 , & V_112 ) ) {
if ( V_113 )
goto V_173;
continue;
} else if ( strcmp ( * V_60 , L_108 ) == 0 )
V_175 = 1 ;
else if ( strcmp ( * V_60 , L_109 ) == 0 )
V_176 = 1 ;
else if ( strcmp ( * V_60 , L_110 ) == 0 ) {
V_177 = 1 ;
V_176 = 1 ;
V_50 = 1 ;
} else if ( F_62 ( & V_60 , & V_59 , & V_113 , V_15 , & V_150 ) ) {
if ( V_113 )
goto V_173;
continue;
} else if ( F_63 ( & V_60 , & V_59 , V_151 , & V_113 , V_15 , & V_153 ) ) {
if ( V_113 )
goto V_173;
continue;
} else if ( strcmp ( * V_60 , L_111 ) == 0 )
V_111 = 1 ;
else if ( strcmp ( * V_60 , L_112 ) == 0 )
V_100 = 1 ;
else if ( strcmp ( * V_60 , L_113 ) == 0 ) {
V_50 = 1 ;
V_160 = 1 ;
} else if ( strcmp ( * V_60 , L_114 ) == 0 )
V_160 = 1 ;
else if ( strcmp ( * V_60 , L_115 ) == 0 )
V_160 = 0 ;
else if ( strcmp ( * V_60 , L_116 ) == 0 )
V_159 = 1 ;
else if ( strcmp ( * V_60 , L_117 ) == 0 )
V_10 = 1 ;
#ifndef F_16
else if ( strcmp ( * V_60 , L_118 ) == 0 )
V_178 = 1 ;
else if ( strcmp ( * V_60 , L_119 ) == 0 )
V_179 = 1 ;
#endif
#ifdef F_9
else if ( strcmp ( * V_60 , L_120 ) == 0 )
F_64 () ;
#endif
else if ( strcmp ( * V_60 , L_121 ) == 0 )
V_161 = 1 ;
else if ( strcmp ( * V_60 , L_122 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_180 = F_65 ( * ( ++ V_60 ) , L_123 ) ;
}
#ifndef F_66
else if ( strcmp ( * V_60 , L_124 ) == 0 )
V_161 = 2 ;
#endif
else if ( strcmp ( * V_60 , L_125 ) == 0 )
V_162 = 1 ;
else if ( strcmp ( * V_60 , L_126 ) == 0 )
V_108 = 1 ;
else if ( strcmp ( * V_60 , L_127 ) == 0 )
V_66 = 1 ;
#ifndef F_11
else if ( strcmp ( * V_60 , L_128 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_12 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_129 ) == 0 ) {
T_9 V_181 ;
if ( -- V_59 < 1 )
goto V_173;
V_14 = * ( ++ V_60 ) ;
for ( V_181 = 0 ; V_181 < strlen ( V_14 ) ; V_181 ++ ) {
if ( isxdigit ( ( unsigned char ) V_14 [ V_181 ] ) )
continue;
F_2 ( V_15 , L_130 , * V_60 ) ;
goto V_173;
}
}
#endif
#ifndef F_13
else if ( strcmp ( * V_60 , L_131 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_33 . V_182 = * ( ++ V_60 ) ;
V_114 = F_67 () ;
} else if ( strcmp ( * V_60 , L_132 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_148 = * ( ++ V_60 ) ;
V_114 = F_67 () ;
} else if ( strcmp ( * V_60 , L_133 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_33 . V_183 = atoi ( * ( ++ V_60 ) ) ;
F_2 ( V_15 , L_134 ,
V_33 . V_183 ) ;
V_114 = F_67 () ;
} else if ( strcmp ( * V_60 , L_135 ) == 0 ) {
V_149 = 1 ;
V_114 = F_67 () ;
} else if ( strcmp ( * V_60 , L_136 ) == 0 ) {
V_33 . V_36 = 1 ;
V_114 = F_67 () ;
}
#endif
#ifndef F_68
else if ( strcmp ( * V_60 , L_137 ) == 0 )
V_114 = F_69 () ;
#endif
#ifndef F_14
else if ( strcmp ( * V_60 , L_138 ) == 0 )
V_114 = F_70 () ;
#endif
#ifndef F_71
else if ( strcmp ( * V_60 , L_139 ) == 0 )
V_114 = F_72 () ;
else if ( strcmp ( * V_60 , L_140 ) == 0 )
V_114 = F_73 () ;
else if ( strcmp ( * V_60 , L_141 ) == 0 )
V_114 = F_67 () ;
#endif
#ifndef F_74
else if ( strcmp ( * V_60 , L_142 ) == 0 ) {
V_114 = F_75 () ;
V_115 = V_184 ;
} else if ( strcmp ( * V_60 , L_143 ) == 0 ) {
V_114 = F_76 () ;
V_115 = V_184 ;
} else if ( strcmp ( * V_60 , L_144 ) == 0 ) {
V_114 = F_77 () ;
V_115 = V_184 ;
} else if ( strcmp ( * V_60 , L_145 ) == 0 )
V_145 = 1 ;
else if ( strcmp ( * V_60 , L_146 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_146 = atol ( * ( ++ V_60 ) ) ;
}
#endif
else if ( strcmp ( * V_60 , L_147 ) == 0 ) {
V_144 = 1 ;
} else if ( strcmp ( * V_60 , L_148 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_85 = F_60 ( * ( ++ V_60 ) ) ;
} else if ( strcmp ( * V_60 , L_149 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_86 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_150 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_82 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_151 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_81 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_152 ) == 0 ) {
V_96 = 5 ;
} else if ( strcmp ( * V_60 , L_153 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_90 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_154 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_92 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_155 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_94 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_156 ) == 0 )
V_61 = 1 ;
else if ( strcmp ( * V_60 , L_157 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_91 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_158 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_93 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_159 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_95 = * ( ++ V_60 ) ;
}
#ifndef F_16
# ifndef F_17
else if ( strcmp ( * V_60 , L_160 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_135 = * ( ++ V_60 ) ;
}
# endif
else if ( strcmp ( * V_60 , L_161 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_136 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_162 ) == 0 ) {
char * V_185 ;
int V_186 = 0 ;
int V_54 ;
if ( -- V_59 < 1 )
goto V_173;
V_185 = * ( ++ V_60 ) ;
V_138 = 0 ;
V_54 = strlen ( V_185 ) ;
for ( V_51 = 0 ; V_51 <= V_54 ; ++ V_51 ) {
if ( V_51 == V_54 || V_185 [ V_51 ] == ',' ) {
V_137 [ V_138 ]
= atoi ( V_185 + V_186 ) ;
V_138 ++ ;
V_186 = V_51 + 1 ;
}
if ( V_138 == F_51 )
break;
}
}
#endif
#ifdef F_10
else if ( strcmp ( * V_60 , L_163 ) == 0 ) {
V_172 = 1 ;
}
#endif
else if ( strcmp ( * V_60 , L_164 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
++ V_60 ;
if ( strcmp ( * V_60 , L_165 ) == 0 )
V_109 = V_187 ;
else if ( strcmp ( * V_60 , L_166 ) == 0 )
V_109 = V_188 ;
else if ( strcmp ( * V_60 , L_167 ) == 0 )
V_109 = V_189 ;
else if ( strcmp ( * V_60 , L_168 ) == 0 )
V_109 = V_190 ;
else if ( strcmp ( * V_60 , L_169 ) == 0 )
V_109 = V_191 ;
else
goto V_173;
}
#ifndef F_15
else if ( strcmp ( * V_60 , L_170 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_123 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_171 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_124 = * ( ++ V_60 ) ;
}
#endif
else if ( strcmp ( * V_60 , L_172 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_118 = * ( ++ V_60 ) ;
}
#ifndef F_16
else if ( strcmp ( * V_60 , L_173 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_133 = * ( ++ V_60 ) ;
}
#endif
#ifndef F_12
else if ( strcmp ( * V_60 , L_174 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_147 = * ++ V_60 ;
}
#endif
#ifndef F_18
else if ( strcmp ( * V_60 , L_175 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_192 = * ( ++ V_60 ) ;
}
#endif
else if ( strcmp ( * V_60 , L_176 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_193 = * ( ++ V_60 ) ;
} else if ( strcmp ( * V_60 , L_177 ) == 0 ) {
if ( -- V_59 < 1 )
goto V_173;
V_194 = atoi ( * ( ++ V_60 ) ) ;
if ( V_194 == 0 )
goto V_173;
} else {
F_2 ( V_15 , L_178 , * V_60 ) ;
V_97 = 1 ;
break;
}
V_59 -- ;
V_60 ++ ;
}
if ( V_97 ) {
V_173:
F_8 () ;
goto V_165;
}
#if ! F_50 ( F_12 ) && ! F_50 ( F_11 )
if ( V_147 ) {
if ( V_14 ) {
F_2 ( V_15 , L_179 ) ;
goto V_165;
}
V_12 = L_180 ;
}
#endif
F_78 () ;
F_79 () ;
#if ! F_50 ( F_16 ) && ! F_50 ( F_17 )
V_195 . V_52 = - 1 ;
if ( V_135 ) {
V_195 . V_53 =
F_80 ( & V_195 . V_54 , V_135 ) ;
if ( V_195 . V_53 == NULL ) {
F_2 ( V_15 , L_181 ) ;
goto V_165;
}
} else
V_195 . V_53 = NULL ;
#endif
#ifndef F_15
V_126 = F_81 ( V_15 , V_123 , 1 ) ;
if ( V_124 ) {
V_125 = F_82 ( V_124 ) ;
if ( ! V_125 ) {
F_2 ( V_15 , L_182 ) ;
goto V_165;
}
}
#endif
if ( ! F_83 ( V_15 , V_86 , NULL , & V_38 , NULL ) ) {
F_2 ( V_15 , L_183 ) ;
goto V_165;
}
if ( V_81 == NULL )
V_81 = V_80 ;
if ( V_81 ) {
V_88 = F_84 ( V_15 , V_81 , V_85 , 0 , V_38 , V_126 ,
L_184 ) ;
if ( ! V_88 ) {
F_85 ( V_15 ) ;
goto V_165;
}
}
if ( V_80 ) {
V_87 = F_86 ( V_15 , V_80 , V_83 ,
NULL , V_126 , L_185 ) ;
if ( ! V_87 ) {
F_85 ( V_15 ) ;
goto V_165;
}
}
if ( V_82 ) {
V_89 = F_87 ( V_15 , V_82 , V_84 ,
NULL , V_126 , L_186 ) ;
if ( ! V_89 )
goto V_165;
}
if ( V_154 ) {
V_157 * V_196 ;
V_196 = F_88 ( V_154 , V_155 ) ;
if ( ! V_196 ) {
F_89 ( V_15 , L_187 ) ;
F_85 ( V_15 ) ;
goto V_165;
}
V_158 = F_90 () ;
if ( ! V_158 || ! F_91 ( V_158 , V_196 ) ) {
F_89 ( V_15 , L_188 ) ;
F_85 ( V_15 ) ;
F_92 ( V_196 ) ;
goto V_165;
}
}
if ( ! F_93 ( & V_150 , V_15 ) )
goto V_165;
if ( ! F_94 ( NULL , V_15 , 1 ) && V_118 == NULL
&& ! F_95 () ) {
F_2 ( V_15 ,
L_189 ) ;
}
if ( V_118 != NULL )
F_2 ( V_15 , L_190 ,
F_96 ( V_118 ) ) ;
if ( V_11 == NULL ) {
if ( V_50 && ! V_10 ) {
V_11 = F_97 ( F_98 () ) ;
if ( V_161 && ! V_180 )
V_180 = F_55 ( stdout , V_164 ) ;
} else {
if ( V_11 == NULL )
V_11 = F_55 ( stdout , V_164 ) ;
}
}
#ifndef F_13
if ( ! F_83 ( V_15 , V_148 , NULL , & V_33 . V_43 , NULL ) ) {
F_2 ( V_15 , L_183 ) ;
goto V_165;
}
#endif
V_49 = F_99 ( V_114 ) ;
if ( V_49 == NULL ) {
F_85 ( V_15 ) ;
goto V_165;
}
if ( V_112 )
F_100 ( V_49 , V_112 ) ;
if ( ! F_101 ( V_49 , V_15 , V_151 , V_153 , 1 , F_52 ) ) {
F_85 ( V_15 ) ;
goto V_165;
}
if ( ! F_102 ( V_49 , V_94 , V_95 , V_92 , V_93 ,
V_158 , V_156 ) ) {
F_2 ( V_15 , L_191 ) ;
F_85 ( V_15 ) ;
goto V_165;
}
#ifndef F_15
if ( V_125 ) {
if ( ! F_103 ( V_49 , V_125 ) ) {
F_89 ( V_15 , L_192 ) ;
F_85 ( V_15 ) ;
F_104 ( V_125 ) ;
goto V_165;
}
F_104 ( V_125 ) ;
}
#endif
#ifndef F_11
# ifdef F_12
if ( V_14 != NULL )
# else
if ( V_14 != NULL || V_147 )
# endif
{
if ( V_10 )
F_2 ( V_11 ,
L_193 ) ;
F_105 ( V_49 , F_1 ) ;
}
#endif
#ifndef F_18
if ( V_192 != NULL )
F_106 ( V_49 , V_192 ) ;
#endif
if ( V_150 )
F_107 ( V_49 , V_150 ) ;
if ( V_115 == V_184 )
F_108 ( V_49 , 1 ) ;
#if ! F_50 ( F_16 )
# if ! F_50 ( F_17 )
if ( V_195 . V_53 )
F_109 ( V_49 , F_43 , & V_195 ) ;
# endif
if ( V_136 ) {
unsigned short V_197 ;
unsigned char * V_198 = F_80 ( & V_197 , V_136 ) ;
if ( V_198 == NULL ) {
F_2 ( V_15 , L_194 ) ;
goto V_165;
}
F_110 ( V_49 , V_198 , V_197 ) ;
F_42 ( V_198 ) ;
}
#endif
#ifndef F_16
for ( V_51 = 0 ; V_51 < V_138 ; V_51 ++ ) {
F_111 ( V_49 ,
V_137 [ V_51 ] ,
NULL , NULL , NULL ,
F_46 , NULL ) ;
}
#endif
if ( V_66 )
F_112 ( V_49 , V_199 ) ;
#if 0
else
SSL_CTX_set_cipher_list(ctx, getenv("SSL_CIPHER"));
#endif
F_113 ( V_49 , V_98 , V_200 ) ;
if ( ( ! F_114 ( V_49 , V_91 , V_90 ) ) ||
( ! F_115 ( V_49 ) ) ) {
F_85 ( V_15 ) ;
}
F_116 ( V_49 , V_158 , V_156 ) ;
if ( ! F_117 ( V_49 , V_87 , V_88 , V_89 , V_61 ) )
goto V_165;
#ifndef F_16
if ( V_133 != NULL ) {
V_134 . V_201 = V_15 ;
F_118 ( V_49 , F_19 ) ;
F_119 ( V_49 , & V_134 ) ;
}
# ifndef F_13
if ( V_33 . V_182 ) {
if ( ! V_149 && ! F_120 ( V_49 , V_33 . V_182 ) ) {
F_2 ( V_15 , L_195 ) ;
goto V_165;
}
V_33 . V_35 = V_161 ;
V_33 . V_34 = V_10 ;
F_121 ( V_49 , & V_33 ) ;
F_122 ( V_49 , F_39 ) ;
F_123 ( V_49 , V_33 . V_183 ) ;
if ( V_161 || V_10 || V_33 . V_36 == 0 )
F_124 ( V_49 ,
F_33 ) ;
}
# endif
#endif
V_62 = F_125 ( V_49 ) ;
if ( V_139 ) {
T_21 * V_202 ;
T_17 * V_203 = F_65 ( V_139 , L_196 ) ;
if ( ! V_203 ) {
F_2 ( V_15 , L_197 , V_139 ) ;
F_85 ( V_15 ) ;
goto V_165;
}
V_202 = F_126 ( V_203 , NULL , 0 , NULL ) ;
F_127 ( V_203 ) ;
if ( ! V_202 ) {
F_2 ( V_15 , L_197 , V_139 ) ;
F_85 ( V_15 ) ;
goto V_165;
}
F_128 ( V_62 , V_202 ) ;
F_129 ( V_202 ) ;
}
if ( V_144 )
F_130 ( V_62 , V_204 ) ;
#ifndef F_16
if ( V_133 != NULL ) {
if ( ! F_131 ( V_62 , V_133 ) ) {
F_2 ( V_15 , L_198 ) ;
F_85 ( V_15 ) ;
goto V_165;
}
}
#endif
#ifndef F_48
if ( V_62 && ( V_63 = F_132 () ) != NULL ) {
F_133 ( V_62 , V_63 ) ;
F_134 ( V_63 , V_205 , V_79 ) ;
}
#endif
#if 0
# ifdef F_135
SSL_set_tlsext_opaque_prf_input(con, "Test client", 11);
# endif
#endif
V_206:
if ( F_136 ( & V_20 , V_79 , V_76 , V_115 ) == 0 ) {
F_2 ( V_15 , L_199 , F_137 () ) ;
F_138 ( V_20 ) ;
goto V_165;
}
F_2 ( V_11 , L_200 , V_20 ) ;
#ifdef F_10
if ( V_172 ) {
unsigned long V_41 = 1 ;
F_2 ( V_11 , L_201 ) ;
if ( F_139 ( V_20 , F_10 , & V_41 ) < 0 ) {
F_85 ( V_15 ) ;
goto V_165;
}
}
#endif
if ( V_159 & 0x01 )
F_140 ( V_62 , 1 ) ;
if ( V_115 == V_184 ) {
V_117 = F_141 ( V_20 , V_164 ) ;
if ( F_142 ( V_20 , & V_142 , ( void * ) & V_143 ) < 0 ) {
F_2 ( V_15 , L_202 ,
F_137 () ) ;
F_138 ( V_20 ) ;
goto V_165;
}
( void ) F_143 ( V_117 , 1 , & V_142 ) ;
if ( V_145 ) {
V_121 . V_207 = 0 ;
V_121 . V_208 = V_209 ;
F_144 ( V_117 , V_210 , 0 , & V_121 ) ;
V_121 . V_207 = 0 ;
V_121 . V_208 = V_211 ;
F_144 ( V_117 , V_212 , 0 , & V_121 ) ;
}
if ( V_146 ) {
if ( V_146 < F_145 ( V_62 ) ) {
F_2 ( V_15 , L_203 ,
F_145 ( V_62 ) ) ;
F_127 ( V_117 ) ;
goto V_213;
}
F_146 ( V_62 , V_214 ) ;
if ( ! F_147 ( V_62 , V_146 ) ) {
F_2 ( V_15 , L_204 ) ;
F_127 ( V_117 ) ;
goto V_213;
}
} else
F_144 ( V_117 , V_215 , 0 , NULL ) ;
} else
V_117 = F_148 ( V_20 , V_164 ) ;
if ( V_108 ) {
T_17 * V_216 ;
V_216 = F_97 ( F_149 () ) ;
V_117 = F_150 ( V_216 , V_117 ) ;
}
if ( V_10 ) {
F_140 ( V_62 , 1 ) ;
F_151 ( V_117 , V_217 ) ;
F_152 ( V_117 , ( char * ) V_11 ) ;
}
if ( V_161 ) {
#ifndef F_66
if ( V_161 == 2 )
F_153 ( V_62 , V_218 ) ;
else
#endif
F_153 ( V_62 , V_219 ) ;
F_154 ( V_62 , V_180 ? V_180 : V_11 ) ;
}
#ifndef F_16
if ( V_178 ) {
F_155 ( V_62 , V_220 ) ;
F_156 ( V_62 , V_11 ) ;
}
if ( V_179 ) {
F_157 ( V_62 , V_221 ) ;
F_158 ( V_49 , V_222 ) ;
F_159 ( V_49 , V_11 ) ;
# if 0
{
STACK_OF(OCSP_RESPID) *ids = sk_OCSP_RESPID_new_null();
OCSP_RESPID *id = OCSP_RESPID_new();
id->value.byKey = ASN1_OCTET_STRING_new();
id->type = V_OCSP_RESPID_KEY;
ASN1_STRING_set(id->value.byKey, "Hello World", -1);
sk_OCSP_RESPID_push(ids, id);
SSL_set_tlsext_status_ids(con, ids);
}
# endif
}
#endif
#ifndef F_12
if ( V_147 )
F_160 ( V_11 , V_117 , V_147 ) ;
#endif
F_161 ( V_62 , V_117 , V_117 ) ;
F_162 ( V_62 ) ;
V_65 = F_163 ( V_62 ) + 1 ;
V_102 = 1 ;
V_101 = 0 ;
V_105 = 0 ;
V_104 = 1 ;
V_103 = 1 ;
V_70 = 0 ;
V_71 = 0 ;
V_72 = 0 ;
V_73 = 0 ;
if ( V_109 == V_187 ) {
int V_223 = 0 ;
T_17 * V_224 = F_97 ( F_164 () ) ;
F_150 ( V_224 , V_117 ) ;
do {
V_119 = F_165 ( V_224 , V_69 , V_168 ) ;
}
while ( V_119 > 3 && V_69 [ 3 ] == '-' );
F_2 ( V_224 , L_205 ) ;
( void ) F_166 ( V_224 ) ;
do {
V_119 = F_165 ( V_224 , V_69 , V_168 ) ;
if ( strstr ( V_69 , L_206 ) )
V_223 = 1 ;
}
while ( V_119 > 3 && V_69 [ 3 ] == '-' );
( void ) F_166 ( V_224 ) ;
F_167 ( V_224 ) ;
F_127 ( V_224 ) ;
if ( ! V_223 )
F_2 ( V_15 ,
L_207
L_208 ) ;
F_2 ( V_117 , L_209 ) ;
F_168 ( V_117 , V_68 , V_168 ) ;
} else if ( V_109 == V_188 ) {
F_168 ( V_117 , V_69 , V_168 ) ;
F_2 ( V_117 , L_210 ) ;
F_168 ( V_117 , V_68 , V_168 ) ;
} else if ( V_109 == V_189 ) {
int V_223 = 0 ;
T_17 * V_224 = F_97 ( F_164 () ) ;
F_150 ( V_224 , V_117 ) ;
F_165 ( V_224 , V_69 , V_168 ) ;
F_2 ( V_224 , L_211 ) ;
( void ) F_166 ( V_224 ) ;
do {
V_119 = F_165 ( V_224 , V_69 , V_168 ) ;
if ( strstr ( V_69 , L_206 ) )
V_223 = 1 ;
}
while ( V_119 > 3 && V_69 [ 0 ] != '.' );
( void ) F_166 ( V_224 ) ;
F_167 ( V_224 ) ;
F_127 ( V_224 ) ;
if ( ! V_223 )
F_2 ( V_15 ,
L_212
L_208 ) ;
F_2 ( V_117 , L_213 ) ;
F_168 ( V_117 , V_68 , V_168 ) ;
} else if ( V_109 == V_190 ) {
T_17 * V_224 = F_97 ( F_164 () ) ;
F_150 ( V_224 , V_117 ) ;
do {
V_119 = F_165 ( V_224 , V_69 , V_168 ) ;
}
while ( V_119 > 3 && V_69 [ 3 ] == '-' );
( void ) F_166 ( V_224 ) ;
F_167 ( V_224 ) ;
F_127 ( V_224 ) ;
F_2 ( V_117 , L_214 ) ;
F_168 ( V_117 , V_68 , V_168 ) ;
}
if ( V_109 == V_191 ) {
int V_225 = 0 ;
F_2 ( V_117 , L_215
L_216
L_217 , V_79 ) ;
V_225 = F_168 ( V_117 , V_69 , V_168 ) ;
V_69 [ V_225 ] = 0 ;
while ( ! strstr
( V_69 , L_218 ) ) {
if ( strstr ( V_69 , L_219 ) )
goto V_213;
V_225 = F_168 ( V_117 , V_69 , V_168 ) ;
V_69 [ V_225 ] = 0 ;
}
F_2 ( V_117 ,
L_220 ) ;
V_225 = F_168 ( V_117 , V_68 , V_168 ) ;
V_68 [ V_225 ] = 0 ;
if ( ! strstr ( V_68 , L_221 ) )
goto V_213;
V_69 [ 0 ] = 0 ;
}
for (; ; ) {
F_169 ( & V_74 ) ;
F_169 ( & V_75 ) ;
if ( ( F_170 ( V_62 ) == V_226 ) &&
F_171 ( V_62 , & V_121 ) )
V_122 = & V_121 ;
else
V_122 = NULL ;
if ( F_172 ( V_62 ) && ! F_173 ( V_62 ) ) {
V_107 = 1 ;
V_105 = 0 ;
} else {
V_105 = 1 ;
if ( V_107 ) {
V_107 = 0 ;
#if 0
# ifndef F_16
if (servername != NULL && !SSL_session_reused(con)) {
BIO_printf(bio_c_out,
"Server did %sacknowledge servername extension.\n",
tlsextcbp.ack ? "" : "not ");
}
# endif
#endif
if ( V_140 ) {
T_17 * V_203 = F_65 ( V_140 , L_123 ) ;
if ( V_203 ) {
F_174 ( V_203 , F_175 ( V_62 ) ) ;
F_127 ( V_203 ) ;
} else
F_2 ( V_15 , L_222 ,
V_140 ) ;
}
if ( V_177 ) {
F_89 ( V_15 , L_223 ) ;
F_176 ( V_15 , V_62 ) ;
}
F_177 ( V_11 , V_62 , V_78 ) ;
if ( V_78 > 0 )
V_78 -- ;
if ( V_109 ) {
F_2 ( V_15 , L_4 , V_69 ) ;
V_109 = V_110 ;
}
if ( V_96 ) {
V_96 -- ;
F_2 ( V_11 ,
L_224 ) ;
F_178 ( V_62 ) ;
F_162 ( V_62 ) ;
F_138 ( F_163 ( V_62 ) ) ;
goto V_206;
}
}
}
V_106 = V_104 && F_179 ( V_62 ) ;
if ( ! V_106 ) {
#if ! F_50 ( V_127 ) && ! F_50 ( V_128 ) && ! F_50 ( V_129 ) && ! F_50 ( V_130 )
if ( V_105 ) {
if ( V_102 )
F_180 ( fileno ( V_227 ) , & V_74 ) ;
if ( V_101 )
F_180 ( fileno ( stdout ) , & V_75 ) ;
}
if ( V_104 )
F_180 ( F_163 ( V_62 ) , & V_74 ) ;
if ( V_103 )
F_180 ( F_163 ( V_62 ) , & V_75 ) ;
#else
if ( ! V_105 || ! V_101 ) {
if ( V_104 )
F_180 ( F_163 ( V_62 ) , & V_74 ) ;
if ( V_103 )
F_180 ( F_163 ( V_62 ) , & V_75 ) ;
}
#endif
#if F_50 ( V_127 ) || F_50 ( V_128 )
V_51 = 0 ;
if ( ! V_101 ) {
if ( V_102 ) {
V_131 . V_207 = 1 ;
V_131 . V_208 = 0 ;
V_51 = F_181 ( V_65 , ( void * ) & V_74 , ( void * ) & V_75 ,
NULL , & V_131 ) ;
# if F_50 ( V_228 ) || F_50 ( V_128 )
if ( ! V_51 && ( ! F_182 () || ! V_102 ) )
continue;
# else
if ( ! V_51 && ( ! ( ( F_182 () )
|| ( V_229 ==
F_183 ( F_184
( V_230 ) ,
0 ) ) )
|| ! V_102 ) )
continue;
# endif
} else
V_51 = F_181 ( V_65 , ( void * ) & V_74 , ( void * ) & V_75 ,
NULL , V_122 ) ;
}
#elif F_50 ( V_129 )
if ( ! V_101 ) {
if ( V_102 ) {
V_131 . V_207 = 1 ;
V_131 . V_208 = 0 ;
V_51 = F_181 ( V_65 , ( void * ) & V_74 , ( void * ) & V_75 ,
NULL , & V_131 ) ;
} else
V_51 = F_181 ( V_65 , ( void * ) & V_74 , ( void * ) & V_75 ,
NULL , V_122 ) ;
}
#elif F_50 ( V_130 )
V_51 = 0 ;
V_132 = 0 ;
( void ) F_185 ( fileno ( V_227 ) , V_231 , V_232 ) ;
if ( ! V_101 ) {
if ( V_102 ) {
V_131 . V_207 = 1 ;
V_131 . V_208 = 0 ;
V_51 = F_181 ( V_65 , ( void * ) & V_74 , ( void * ) & V_75 ,
NULL , & V_131 ) ;
if ( F_186 ( fileno ( V_227 ) , V_68 , 0 ) >= 0 )
V_132 = 1 ;
if ( ! V_51 && ( V_132 != 1 || ! V_102 ) )
continue;
} else
V_51 = F_181 ( V_65 , ( void * ) & V_74 , ( void * ) & V_75 ,
NULL , V_122 ) ;
}
( void ) F_185 ( fileno ( V_227 ) , V_231 , 0 ) ;
#else
V_51 = F_181 ( V_65 , ( void * ) & V_74 , ( void * ) & V_75 ,
NULL , V_122 ) ;
#endif
if ( V_51 < 0 ) {
F_2 ( V_15 , L_225 ,
F_137 () ) ;
goto V_213;
}
}
if ( ( F_170 ( V_62 ) == V_226 )
&& F_187 ( V_62 ) > 0 ) {
F_2 ( V_15 , L_226 ) ;
}
if ( ! V_106 && F_188 ( F_163 ( V_62 ) , & V_75 ) ) {
V_64 = F_189 ( V_62 , & ( V_67 [ V_71 ] ) , ( unsigned int ) V_70 ) ;
switch ( F_190 ( V_62 , V_64 ) ) {
case V_233 :
V_71 += V_64 ;
V_70 -= V_64 ;
if ( V_64 <= 0 )
goto V_165;
if ( V_70 <= 0 ) {
V_102 = 1 ;
V_103 = 0 ;
} else {
V_102 = 0 ;
V_103 = 1 ;
}
break;
case V_234 :
F_2 ( V_11 , L_227 ) ;
V_103 = 1 ;
V_102 = 0 ;
break;
case V_235 :
F_2 ( V_11 , L_228 ) ;
V_101 = 0 ;
V_104 = 1 ;
V_103 = 0 ;
break;
case V_236 :
F_2 ( V_11 , L_229 ) ;
break;
case V_237 :
if ( V_70 != 0 ) {
F_2 ( V_11 , L_230 ) ;
V_8 = 0 ;
goto V_213;
} else {
V_102 = 1 ;
V_103 = 0 ;
break;
}
case V_238 :
if ( ( V_64 != 0 ) || ( V_70 != 0 ) ) {
F_2 ( V_15 , L_231 ,
F_137 () ) ;
goto V_213;
} else {
V_102 = 1 ;
V_103 = 0 ;
}
break;
case V_239 :
F_85 ( V_15 ) ;
goto V_213;
}
}
#if F_50 ( V_127 ) || F_50 ( V_128 ) || F_50 ( V_129 ) || F_50 ( V_130 )
else if ( ! V_106 && V_101 )
#else
else if ( ! V_106 && F_188 ( fileno ( stdout ) , & V_75 ) )
#endif
{
#ifdef F_191
F_192 ( & ( V_68 [ V_73 ] ) , & ( V_68 [ V_73 ] ) , V_72 ) ;
#endif
V_51 = F_193 ( & ( V_68 [ V_73 ] ) , V_72 ) ;
if ( V_51 <= 0 ) {
F_2 ( V_11 , L_232 ) ;
V_8 = 0 ;
goto V_213;
}
V_72 -= V_51 ; ;
V_73 += V_51 ;
if ( V_72 <= 0 ) {
V_104 = 1 ;
V_101 = 0 ;
}
} else if ( V_106 || F_188 ( F_163 ( V_62 ) , & V_74 ) ) {
#ifdef F_194
{
static int V_240 ;
if ( ++ V_240 == 52 ) {
F_195 ( V_62 ) ;
V_240 = 0 ;
}
}
#endif
#if 1
V_64 = F_196 ( V_62 , V_68 , 1024 ) ;
#else
V_64 = F_196 ( V_62 , V_68 , 16 ) ;
{
char V_241 [ 10240 ] ;
printf ( L_233 , V_64 , F_179 ( V_62 ) ,
F_197 ( V_62 , V_241 , 10240 ) ) ;
}
#endif
switch ( F_190 ( V_62 , V_64 ) ) {
case V_233 :
if ( V_64 <= 0 )
goto V_165;
V_73 = 0 ;
V_72 = V_64 ;
V_104 = 0 ;
V_101 = 1 ;
break;
case V_234 :
F_2 ( V_11 , L_234 ) ;
V_103 = 1 ;
V_102 = 0 ;
break;
case V_235 :
F_2 ( V_11 , L_235 ) ;
V_101 = 0 ;
V_104 = 1 ;
if ( ( V_102 == 0 ) && ( V_103 == 0 ) )
V_103 = 1 ;
break;
case V_236 :
F_2 ( V_11 , L_236 ) ;
break;
case V_238 :
V_8 = F_137 () ;
if ( V_177 )
F_89 ( V_15 , L_237 ) ;
else
F_2 ( V_15 , L_238 , V_8 ) ;
goto V_213;
case V_237 :
F_2 ( V_11 , L_239 ) ;
V_8 = 0 ;
goto V_213;
case V_239 :
F_85 ( V_15 ) ;
goto V_213;
}
}
#if F_50 ( V_127 ) || F_50 ( V_128 )
# if F_50 ( V_228 ) || F_50 ( V_128 )
else if ( F_182 () )
# else
else if ( ( F_182 () )
|| ( V_229 ==
F_183 ( F_184 ( V_230 ) , 0 ) ) )
# endif
#elif F_50 ( V_129 )
else if ( F_182 () )
#elif F_50 ( V_130 )
else if ( V_132 )
#else
else if ( F_188 ( fileno ( V_227 ) , & V_74 ) )
#endif
{
if ( V_100 ) {
int V_181 , V_242 ;
V_51 = F_198 ( V_67 , V_168 / 2 ) ;
V_242 = 0 ;
for ( V_181 = 0 ; V_181 < V_51 ; V_181 ++ )
if ( V_67 [ V_181 ] == '\n' )
V_242 ++ ;
for ( V_181 = V_51 - 1 ; V_181 >= 0 ; V_181 -- ) {
V_67 [ V_181 + V_242 ] = V_67 [ V_181 ] ;
if ( V_67 [ V_181 ] == '\n' ) {
V_242 -- ;
V_51 ++ ;
V_67 [ V_181 + V_242 ] = '\r' ;
}
}
assert ( V_242 == 0 ) ;
} else
V_51 = F_198 ( V_67 , V_168 ) ;
if ( ( ! V_160 ) && ( ( V_51 <= 0 ) || ( V_67 [ 0 ] == 'Q' ) ) ) {
F_2 ( V_15 , L_232 ) ;
V_8 = 0 ;
goto V_213;
}
if ( ( ! V_160 ) && ( V_67 [ 0 ] == 'R' ) ) {
F_2 ( V_15 , L_240 ) ;
F_195 ( V_62 ) ;
V_70 = 0 ;
}
#ifndef F_199
else if ( ( ! V_160 ) && ( V_67 [ 0 ] == 'B' ) ) {
F_2 ( V_15 , L_241 ) ;
F_200 ( V_62 ) ;
V_70 = 0 ;
}
#endif
else {
V_70 = V_51 ;
V_71 = 0 ;
#ifdef F_191
F_201 ( V_67 , V_67 , V_51 ) ;
#endif
}
V_103 = 1 ;
V_102 = 0 ;
}
}
V_8 = 0 ;
V_213:
if ( V_107 )
F_177 ( V_11 , V_62 , V_78 ) ;
F_178 ( V_62 ) ;
F_138 ( F_163 ( V_62 ) ) ;
V_165:
if ( V_62 != NULL ) {
if ( V_111 != 0 )
F_177 ( V_11 , V_62 , 1 ) ;
F_202 ( V_62 ) ;
}
#if ! F_50 ( F_16 ) && ! F_50 ( F_17 )
if ( V_195 . V_53 )
F_42 ( V_195 . V_53 ) ;
#endif
if ( V_49 != NULL )
F_203 ( V_49 ) ;
if ( V_87 )
F_204 ( V_87 ) ;
if ( V_158 )
F_205 ( V_158 , F_92 ) ;
if ( V_88 )
F_206 ( V_88 ) ;
if ( V_89 )
F_207 ( V_89 , F_204 ) ;
if ( V_38 )
F_42 ( V_38 ) ;
if ( V_112 )
F_208 ( V_112 ) ;
F_209 ( V_150 ) ;
if ( V_153 )
F_210 ( V_153 ) ;
if ( V_151 )
F_211 ( V_151 ) ;
#ifndef F_12
if ( V_147 && V_14 )
F_42 ( V_14 ) ;
#endif
if ( V_67 != NULL ) {
F_212 ( V_67 , V_168 ) ;
F_42 ( V_67 ) ;
}
if ( V_68 != NULL ) {
F_212 ( V_68 , V_168 ) ;
F_42 ( V_68 ) ;
}
if ( V_69 != NULL ) {
F_212 ( V_69 , V_168 ) ;
F_42 ( V_69 ) ;
}
if ( V_11 != NULL ) {
F_127 ( V_11 ) ;
V_11 = NULL ;
}
if ( V_180 != NULL ) {
F_127 ( V_180 ) ;
V_180 = NULL ;
}
F_213 () ;
F_214 ( V_8 ) ;
}
static void F_177 ( T_17 * V_243 , T_1 * V_20 , int V_244 )
{
T_12 * V_142 = NULL ;
char * V_23 ;
static const char * V_245 = L_242 ;
char V_246 [ V_247 ] ;
F_49 ( T_12 ) * V_248 ;
F_49 ( V_249 ) * V_250 ;
const T_22 * V_185 ;
V_249 * V_251 ;
int V_181 , V_51 ;
#ifndef F_215
const T_23 * V_252 , * V_253 ;
#endif
unsigned char * V_254 ;
if ( V_244 ) {
int V_255 = 0 ;
V_248 = F_216 ( V_20 ) ;
if ( V_248 != NULL ) {
V_255 = 1 ;
F_2 ( V_243 , L_243 ) ;
for ( V_51 = 0 ; V_51 < F_217 ( V_248 ) ; V_51 ++ ) {
F_218 ( F_219 ( F_220 ( V_248 , V_51 ) ) ,
V_246 , sizeof V_246 ) ;
F_2 ( V_243 , L_244 , V_51 , V_246 ) ;
F_218 ( F_221 ( F_220 ( V_248 , V_51 ) ) ,
V_246 , sizeof V_246 ) ;
F_2 ( V_243 , L_245 , V_246 ) ;
if ( V_162 )
F_222 ( V_243 , F_220 ( V_248 , V_51 ) ) ;
}
}
F_2 ( V_243 , L_246 ) ;
V_142 = F_223 ( V_20 ) ;
if ( V_142 != NULL ) {
F_2 ( V_243 , L_247 ) ;
if ( ! ( V_162 && V_255 ) )
F_222 ( V_243 , V_142 ) ;
F_218 ( F_219 ( V_142 ) , V_246 , sizeof V_246 ) ;
F_2 ( V_243 , L_248 , V_246 ) ;
F_218 ( F_221 ( V_142 ) , V_246 , sizeof V_246 ) ;
F_2 ( V_243 , L_249 , V_246 ) ;
} else
F_2 ( V_243 , L_250 ) ;
V_250 = F_224 ( V_20 ) ;
if ( ( V_250 != NULL ) && ( F_225 ( V_250 ) > 0 ) ) {
F_2 ( V_243 , L_251 ) ;
for ( V_51 = 0 ; V_51 < F_225 ( V_250 ) ; V_51 ++ ) {
V_251 = F_226 ( V_250 , V_51 ) ;
F_218 ( V_251 , V_246 , sizeof( V_246 ) ) ;
F_44 ( V_243 , V_246 , strlen ( V_246 ) ) ;
F_44 ( V_243 , L_11 , 1 ) ;
}
} else {
F_2 ( V_243 , L_252 ) ;
}
V_23 = F_227 ( V_20 , V_246 , sizeof V_246 ) ;
if ( V_23 != NULL ) {
F_2 ( V_243 ,
L_253 ) ;
V_181 = V_51 = 0 ;
while ( * V_23 ) {
if ( * V_23 == ':' ) {
F_44 ( V_243 , V_245 , 15 - V_181 % 25 ) ;
V_51 ++ ;
V_181 = 0 ;
F_44 ( V_243 , ( ( V_51 % 3 ) ? L_254 : L_11 ) , 1 ) ;
} else {
F_44 ( V_243 , V_23 , 1 ) ;
V_181 ++ ;
}
V_23 ++ ;
}
F_44 ( V_243 , L_11 , 1 ) ;
}
F_228 ( V_243 , V_20 ) ;
F_229 ( V_243 , V_20 ) ;
F_2 ( V_243 ,
L_255 ,
F_230 ( F_231 ( V_20 ) ) ,
F_232 ( F_233 ( V_20 ) ) ) ;
}
F_2 ( V_243 , ( F_234 ( V_20 ) ? L_256 : L_257 ) ) ;
V_185 = F_235 ( V_20 ) ;
F_2 ( V_243 , L_258 ,
F_236 ( V_185 ) , F_237 ( V_185 ) ) ;
if ( V_142 != NULL ) {
T_13 * V_256 ;
V_256 = F_238 ( V_142 ) ;
F_2 ( V_243 , L_259 ,
F_239 ( V_256 ) ) ;
F_206 ( V_256 ) ;
}
F_2 ( V_243 , L_260 ,
F_240 ( V_20 ) ? L_94 : L_261 ) ;
#ifndef F_215
V_252 = F_241 ( V_20 ) ;
V_253 = F_242 ( V_20 ) ;
F_2 ( V_243 , L_262 ,
V_252 ? F_243 ( V_252 ) : L_263 ) ;
F_2 ( V_243 , L_264 ,
V_253 ? F_243 ( V_253 ) : L_263 ) ;
#endif
#ifdef F_244
{
int V_257 ;
struct V_258 V_259 ;
T_24 V_260 = sizeof( V_259 ) ;
V_257 = F_163 ( V_20 ) ;
F_142 ( V_257 , (struct V_141 * ) & V_259 , & V_260 ) ;
F_2 ( V_11 , L_265 , F_245 ( V_259 . V_261 ) ) ;
}
#endif
#if ! F_50 ( F_16 )
# if ! F_50 ( F_17 )
if ( V_195 . V_52 != - 1 ) {
const unsigned char * V_262 ;
unsigned int V_263 ;
F_246 ( V_20 , & V_262 , & V_263 ) ;
F_2 ( V_243 , L_266 , V_195 . V_52 ) ;
F_44 ( V_243 , V_262 , V_263 ) ;
F_44 ( V_243 , L_11 , 1 ) ;
}
# endif
{
const unsigned char * V_262 ;
unsigned int V_263 ;
F_247 ( V_20 , & V_262 , & V_263 ) ;
if ( V_263 > 0 ) {
F_2 ( V_243 , L_267 ) ;
F_44 ( V_243 , V_262 , V_263 ) ;
F_44 ( V_243 , L_11 , 1 ) ;
} else
F_2 ( V_243 , L_268 ) ;
}
#endif
#ifndef F_18
{
T_25 * V_264 =
F_248 ( V_20 ) ;
if ( V_264 )
F_2 ( V_243 , L_269 ,
V_264 -> V_265 ) ;
}
#endif
F_249 ( V_243 , F_175 ( V_20 ) ) ;
if ( V_193 != NULL ) {
F_2 ( V_243 , L_270 ) ;
F_2 ( V_243 , L_271 , V_193 ) ;
F_2 ( V_243 , L_272 , V_194 ) ;
V_254 = F_40 ( V_194 ) ;
if ( V_254 != NULL ) {
if ( ! F_250 ( V_20 , V_254 ,
V_194 ,
V_193 ,
strlen ( V_193 ) ,
NULL , 0 , 0 ) ) {
F_2 ( V_243 , L_273 ) ;
} else {
F_2 ( V_243 , L_274 ) ;
for ( V_51 = 0 ; V_51 < V_194 ; V_51 ++ )
F_2 ( V_243 , L_275 , V_254 [ V_51 ] ) ;
F_2 ( V_243 , L_11 ) ;
}
F_42 ( V_254 ) ;
}
}
F_2 ( V_243 , L_246 ) ;
if ( V_142 != NULL )
F_204 ( V_142 ) ;
( void ) F_166 ( V_243 ) ;
}
static int V_222 ( T_1 * V_20 , void * V_22 )
{
const unsigned char * V_23 ;
int V_54 ;
T_26 * V_266 ;
V_54 = F_251 ( V_20 , & V_23 ) ;
F_89 ( V_22 , L_276 ) ;
if ( ! V_23 ) {
F_89 ( V_22 , L_277 ) ;
return 1 ;
}
V_266 = F_252 ( NULL , & V_23 , V_54 ) ;
if ( ! V_266 ) {
F_89 ( V_22 , L_278 ) ;
F_253 ( V_22 , ( char * ) V_23 , V_54 , 4 ) ;
return 0 ;
}
F_89 ( V_22 , L_279 ) ;
F_254 ( V_22 , V_266 , 0 ) ;
F_89 ( V_22 , L_280 ) ;
F_255 ( V_266 ) ;
return 1 ;
}
