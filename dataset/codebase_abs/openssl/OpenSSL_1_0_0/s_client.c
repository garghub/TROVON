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
F_2 ( V_15 , L_40 ) ;
F_2 ( V_15 , L_41 ) ;
F_2 ( V_15 , L_42 ) ;
F_2 ( V_15 , L_43 ) ;
F_2 ( V_15 , L_44 ) ;
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
#ifndef F_13
F_2 ( V_15 , L_55 ) ;
#endif
F_2 ( V_15 , L_56 , V_18 , V_18 ) ;
F_2 ( V_15 , L_57 ) ;
F_2 ( V_15 , L_58 ) ;
#ifndef F_14
F_2 ( V_15 , L_59 ) ;
F_2 ( V_15 , L_60 ) ;
F_2 ( V_15 , L_61 ) ;
F_2 ( V_15 , L_62 ) ;
#endif
F_2 ( V_15 , L_63 ) ;
}
static int T_3 F_15 ( T_1 * V_19 , int * V_20 , void * V_21 )
{
T_4 * V_22 = ( T_4 * ) V_21 ;
const char * V_23 = F_16 ( V_19 , V_24 ) ;
if ( F_17 ( V_19 ) != - 1 )
V_22 -> V_25 = ! F_18 ( V_19 ) && V_23 != NULL ;
else
F_2 ( V_15 , L_64 ) ;
return V_26 ;
}
int MAIN ( int V_27 , char * * V_28 )
{
unsigned int V_29 = 0 , V_30 = 0 ;
T_1 * V_31 = NULL ;
int V_19 , V_32 , V_33 , V_34 = 0 ;
char * V_35 = NULL , * V_36 = NULL , * V_37 = NULL ;
int V_38 , V_39 ;
int V_40 , V_41 ;
T_5 V_42 , V_43 ;
short V_44 = V_45 ;
int V_46 = 1 ;
char * V_47 = V_16 ;
char * V_48 = NULL , * V_49 = NULL ;
int V_50 = V_51 , V_52 = V_51 ;
char * V_53 = NULL , * V_54 = NULL ;
T_6 * V_55 = NULL ;
T_7 * V_56 = NULL ;
char * V_57 = NULL , * V_58 = NULL , * V_59 = NULL ;
int V_60 = 0 , V_61 = 0 , V_62 = V_63 , V_64 = 0 ;
int V_65 = 0 ;
int V_66 , V_67 , V_68 , V_69 , V_70 , V_71 ;
T_8 * V_72 = NULL ;
int V_8 = 1 , V_73 = 1 , V_74 , V_75 = 0 ;
int V_76 = V_77 ;
int V_78 = 0 ;
T_9 * V_79 = NULL ;
int V_80 = 0 ;
const T_10 * V_81 = NULL ;
int V_82 = V_83 ;
T_11 * V_84 ;
char * V_85 = NULL ;
int V_86 = 0 ;
struct V_87 V_88 , * V_89 ;
#ifndef F_13
char * V_90 = NULL ;
char * V_91 = NULL ;
T_12 * V_92 = NULL ;
#endif
T_12 * V_93 = NULL ;
#if F_19 ( V_94 ) || F_19 ( V_95 ) || F_19 ( V_96 ) || F_19 ( V_97 )
struct V_87 V_98 ;
#if F_19 ( V_97 )
int V_99 = 0 ;
#endif
#endif
#ifndef F_14
char * V_100 = NULL ;
T_4 V_101 =
{ NULL , 0 } ;
#endif
char * V_102 = NULL ;
char * V_103 = NULL ;
struct V_104 V_105 ;
int V_106 = sizeof( V_105 ) ;
int V_107 = 0 ;
long V_108 = 0 ;
#ifndef F_12
char * V_109 = NULL ;
#endif
#if ! F_19 ( V_110 ) && ! F_19 ( V_111 )
V_81 = F_20 () ;
#elif ! F_19 ( V_111 )
V_81 = F_21 () ;
#elif ! F_19 ( V_110 )
V_81 = F_22 () ;
#endif
F_23 () ;
V_112 = 0 ;
V_113 = 0 ;
V_114 = 0 ;
V_10 = 0 ;
V_115 = 0 ;
V_116 = 0 ;
if ( V_15 == NULL )
V_15 = F_24 ( V_117 , V_118 ) ;
if ( ! F_25 ( V_15 , NULL ) )
goto V_119;
if ( ( ( V_35 = F_26 ( V_120 ) ) == NULL ) ||
( ( V_36 = F_26 ( V_120 ) ) == NULL ) ||
( ( V_37 = F_26 ( V_120 ) ) == NULL ) )
{
F_2 ( V_15 , L_65 ) ;
goto V_119;
}
V_121 = 0 ;
V_122 = V_123 ;
#ifdef F_10
V_124 = 0 ;
#endif
V_27 -- ;
V_28 ++ ;
while ( V_27 >= 1 )
{
if ( strcmp ( * V_28 , L_66 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_47 = * ( ++ V_28 ) ;
}
else if ( strcmp ( * V_28 , L_67 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_44 = atoi ( * ( ++ V_28 ) ) ;
if ( V_44 == 0 ) goto V_125;
}
else if ( strcmp ( * V_28 , L_68 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
if ( ! F_27 ( * ( ++ V_28 ) , & V_47 , NULL , & V_44 ) )
goto V_125;
}
else if ( strcmp ( * V_28 , L_69 ) == 0 )
{
V_62 = V_126 ;
if ( -- V_27 < 1 ) goto V_125;
V_121 = atoi ( * ( ++ V_28 ) ) ;
F_2 ( V_15 , L_70 , V_121 ) ;
}
else if ( strcmp ( * V_28 , L_71 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_48 = * ( ++ V_28 ) ;
}
else if ( strcmp ( * V_28 , L_72 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_103 = * ( ++ V_28 ) ;
}
else if ( strcmp ( * V_28 , L_73 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_102 = * ( ++ V_28 ) ;
}
else if ( strcmp ( * V_28 , L_74 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_50 = F_28 ( * ( ++ V_28 ) ) ;
}
else if ( F_29 ( & V_28 , & V_27 , & V_80 , V_15 , & V_79 ) )
{
if ( V_80 )
goto V_125;
continue;
}
else if ( strcmp ( * V_28 , L_75 ) == 0 )
V_127 = 1 ;
else if ( strcmp ( * V_28 , L_76 ) == 0 )
V_78 = 1 ;
else if ( strcmp ( * V_28 , L_77 ) == 0 )
V_65 = 1 ;
else if ( strcmp ( * V_28 , L_78 ) == 0 )
{
V_113 = 1 ;
V_114 = 1 ;
}
else if ( strcmp ( * V_28 , L_79 ) == 0 )
V_114 = 1 ;
else if ( strcmp ( * V_28 , L_80 ) == 0 )
V_114 = 0 ;
else if ( strcmp ( * V_28 , L_81 ) == 0 )
V_112 = 1 ;
else if ( strcmp ( * V_28 , L_82 ) == 0 )
V_10 = 1 ;
#ifndef F_14
else if ( strcmp ( * V_28 , L_83 ) == 0 )
V_128 = 1 ;
else if ( strcmp ( * V_28 , L_84 ) == 0 )
V_129 = 1 ;
#endif
#ifdef F_9
else if ( strcmp ( * V_28 , L_85 ) == 0 )
F_30 () ;
#endif
else if ( strcmp ( * V_28 , L_86 ) == 0 )
V_115 = 1 ;
else if ( strcmp ( * V_28 , L_87 ) == 0 )
V_116 = 1 ;
else if ( strcmp ( * V_28 , L_88 ) == 0 )
V_75 = 1 ;
else if ( strcmp ( * V_28 , L_89 ) == 0 )
V_34 = 1 ;
#ifndef F_11
else if ( strcmp ( * V_28 , L_90 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_12 = * ( ++ V_28 ) ;
}
else if ( strcmp ( * V_28 , L_91 ) == 0 )
{
T_13 V_130 ;
if ( -- V_27 < 1 ) goto V_125;
V_14 = * ( ++ V_28 ) ;
for ( V_130 = 0 ; V_130 < strlen ( V_14 ) ; V_130 ++ )
{
if ( isxdigit ( ( int ) V_14 [ V_130 ] ) )
continue;
F_2 ( V_15 , L_92 , * V_28 ) ;
goto V_125;
}
}
#endif
#ifndef V_110
else if ( strcmp ( * V_28 , L_93 ) == 0 )
V_81 = F_22 () ;
#endif
#ifndef V_111
else if ( strcmp ( * V_28 , L_94 ) == 0 )
V_81 = F_21 () ;
#endif
#ifndef F_31
else if ( strcmp ( * V_28 , L_95 ) == 0 )
V_81 = F_32 () ;
#endif
#ifndef F_33
else if ( strcmp ( * V_28 , L_96 ) == 0 )
{
V_81 = F_34 () ;
V_82 = V_131 ;
}
else if ( strcmp ( * V_28 , L_97 ) == 0 )
V_107 = 1 ;
else if ( strcmp ( * V_28 , L_98 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_108 = atol ( * ( ++ V_28 ) ) ;
}
#endif
else if ( strcmp ( * V_28 , L_99 ) == 0 )
V_64 = 1 ;
else if ( strcmp ( * V_28 , L_100 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_52 = F_28 ( * ( ++ V_28 ) ) ;
}
else if ( strcmp ( * V_28 , L_101 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_53 = * ( ++ V_28 ) ;
}
else if ( strcmp ( * V_28 , L_102 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_49 = * ( ++ V_28 ) ;
}
else if ( strcmp ( * V_28 , L_103 ) == 0 )
{
V_60 = 5 ;
}
else if ( strcmp ( * V_28 , L_104 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_57 = * ( ++ V_28 ) ;
}
else if ( strcmp ( * V_28 , L_105 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_58 = * ( ++ V_28 ) ;
}
else if ( strcmp ( * V_28 , L_106 ) == 0 )
V_29 |= V_132 ;
else if ( strcmp ( * V_28 , L_107 ) == 0 )
V_29 |= V_133 ;
else if ( strcmp ( * V_28 , L_108 ) == 0 )
V_29 |= V_134 ;
else if ( strcmp ( * V_28 , L_109 ) == 0 )
{ V_29 |= V_135 ; }
#ifndef F_14
else if ( strcmp ( * V_28 , L_110 ) == 0 )
{ V_29 |= V_136 ; }
#endif
else if ( strcmp ( * V_28 , L_111 ) == 0 )
V_29 |= V_137 ;
else if ( strcmp ( * V_28 , L_112 ) == 0 )
V_29 |= V_138 ;
else if ( strcmp ( * V_28 , L_113 ) == 0 )
{ V_29 |= V_139 ; }
else if ( strcmp ( * V_28 , L_114 ) == 0 )
{ V_30 |= V_139 ; }
else if ( strcmp ( * V_28 , L_115 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_59 = * ( ++ V_28 ) ;
}
#ifdef F_10
else if ( strcmp ( * V_28 , L_116 ) == 0 )
{ V_124 = 1 ; }
#endif
else if ( strcmp ( * V_28 , L_117 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
++ V_28 ;
if ( strcmp ( * V_28 , L_118 ) == 0 )
V_76 = V_140 ;
else if ( strcmp ( * V_28 , L_119 ) == 0 )
V_76 = V_141 ;
else if ( strcmp ( * V_28 , L_120 ) == 0 )
V_76 = V_142 ;
else if ( strcmp ( * V_28 , L_121 ) == 0 )
V_76 = V_143 ;
else if ( strcmp ( * V_28 , L_122 ) == 0 )
V_76 = V_144 ;
else
goto V_125;
}
#ifndef F_13
else if ( strcmp ( * V_28 , L_123 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_90 = * ( ++ V_28 ) ;
}
else if ( strcmp ( * V_28 , L_124 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_91 = * ( ++ V_28 ) ;
}
#endif
else if ( strcmp ( * V_28 , L_125 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_85 = * ( ++ V_28 ) ;
}
#ifndef F_14
else if ( strcmp ( * V_28 , L_126 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_100 = * ( ++ V_28 ) ;
}
#endif
#ifndef F_12
else if ( strcmp ( * V_28 , L_127 ) == 0 )
{
if ( -- V_27 < 1 ) goto V_125;
V_109 = * ++ V_28 ;
}
#endif
else
{
F_2 ( V_15 , L_128 , * V_28 ) ;
V_61 = 1 ;
break;
}
V_27 -- ;
V_28 ++ ;
}
if ( V_61 )
{
V_125:
F_8 () ;
goto V_119;
}
#if ! F_19 ( F_12 ) && ! F_19 ( F_11 )
if ( V_109 )
{
if ( V_14 )
{
F_2 ( V_15 ,
L_129 ) ;
goto V_119;
}
V_12 = L_130 ;
}
if ( V_59 )
{
F_2 ( V_15 , L_131 ) ;
goto V_119;
}
V_59 = L_132 ;
#endif
F_35 () ;
F_36 () ;
#ifndef F_13
V_93 = F_37 ( V_15 , V_90 , 1 ) ;
if ( V_91 )
{
V_92 = F_38 ( V_91 ) ;
if ( ! V_92 )
{
F_2 ( V_15 ,
L_133 ) ;
goto V_119;
}
}
#endif
if ( ! F_39 ( V_15 , V_53 , NULL , & V_54 , NULL ) )
{
F_2 ( V_15 , L_134 ) ;
goto V_119;
}
if ( V_49 == NULL )
V_49 = V_48 ;
if ( V_49 )
{
V_56 = F_40 ( V_15 , V_49 , V_52 , 0 , V_54 , V_93 ,
L_135 ) ;
if ( ! V_56 )
{
F_41 ( V_15 ) ;
goto V_119;
}
}
if ( V_48 )
{
V_55 = F_42 ( V_15 , V_48 , V_50 ,
NULL , V_93 , L_136 ) ;
if ( ! V_55 )
{
F_41 ( V_15 ) ;
goto V_119;
}
}
if ( ! F_43 ( NULL , V_15 , 1 ) && V_85 == NULL
&& ! F_44 () )
{
F_2 ( V_15 , L_137 ) ;
}
if ( V_85 != NULL )
F_2 ( V_15 , L_138 ,
F_45 ( V_85 ) ) ;
if ( V_11 == NULL )
{
if ( V_113 && ! V_10 && ! V_115 )
{
V_11 = F_46 ( F_47 () ) ;
}
else
{
if ( V_11 == NULL )
V_11 = F_24 ( stdout , V_118 ) ;
}
}
V_72 = F_48 ( V_81 ) ;
if ( V_72 == NULL )
{
F_41 ( V_15 ) ;
goto V_119;
}
if ( V_79 )
F_49 ( V_72 , V_79 ) ;
#ifndef F_13
if ( V_92 )
{
if ( ! F_50 ( V_72 , V_92 ) )
{
F_51 ( V_15 , L_139 ) ;
F_41 ( V_15 ) ;
F_52 ( V_92 ) ;
goto V_119;
}
F_52 ( V_92 ) ;
}
#endif
#ifndef F_11
#ifdef F_12
if ( V_14 != NULL )
#else
if ( V_14 != NULL || V_109 )
#endif
{
if ( V_10 )
F_2 ( V_11 , L_140 ) ;
F_53 ( V_72 , F_1 ) ;
}
#endif
if ( V_64 )
F_54 ( V_72 , V_145 | V_29 ) ;
else
F_54 ( V_72 , V_29 ) ;
if ( V_30 )
F_55 ( V_72 , V_30 ) ;
if ( V_82 == V_131 ) F_56 ( V_72 , 1 ) ;
if ( V_34 ) F_57 ( V_72 , V_146 ) ;
if ( V_59 != NULL )
if( ! F_58 ( V_72 , V_59 ) ) {
F_2 ( V_15 , L_141 ) ;
F_41 ( V_15 ) ;
goto V_119;
}
#if 0
else
SSL_CTX_set_cipher_list(ctx,getenv("SSL_CIPHER"));
#endif
F_59 ( V_72 , V_62 , V_147 ) ;
if ( ! F_60 ( V_72 , V_55 , V_56 ) )
goto V_119;
if ( ( ! F_61 ( V_72 , V_58 , V_57 ) ) ||
( ! F_62 ( V_72 ) ) )
{
F_41 ( V_15 ) ;
}
#ifndef F_14
if ( V_100 != NULL )
{
V_101 . V_148 = V_15 ;
F_63 ( V_72 , F_15 ) ;
F_64 ( V_72 , & V_101 ) ;
}
#endif
V_31 = F_65 ( V_72 ) ;
if ( V_102 )
{
T_14 * V_149 ;
T_11 * V_150 = F_66 ( V_102 , L_142 ) ;
if ( ! V_150 )
{
F_2 ( V_15 , L_143 ,
V_102 ) ;
F_41 ( V_15 ) ;
goto V_119;
}
V_149 = F_67 ( V_150 , NULL , 0 , NULL ) ;
F_68 ( V_150 ) ;
if ( ! V_149 )
{
F_2 ( V_15 , L_143 ,
V_102 ) ;
F_41 ( V_15 ) ;
goto V_119;
}
F_69 ( V_31 , V_149 ) ;
F_70 ( V_149 ) ;
}
#ifndef F_14
if ( V_100 != NULL )
{
if ( ! F_71 ( V_31 , V_100 ) )
{
F_2 ( V_15 , L_144 ) ;
F_41 ( V_15 ) ;
goto V_119;
}
}
#endif
#ifndef F_72
if ( V_31 && ( V_31 -> V_151 = F_73 () ) != NULL )
{
F_74 ( V_31 -> V_151 , V_152 , V_47 ) ;
}
#endif
#if 0
#ifdef F_75
SSL_set_tlsext_opaque_prf_input(con, "Test client", 11);
#endif
#endif
V_153:
if ( F_76 ( & V_19 , V_47 , V_44 , V_82 ) == 0 )
{
F_2 ( V_15 , L_145 , F_77 () ) ;
F_78 ( V_19 ) ;
goto V_119;
}
F_2 ( V_11 , L_146 , V_19 ) ;
#ifdef F_10
if ( V_124 )
{
unsigned long V_154 = 1 ;
F_2 ( V_11 , L_147 ) ;
if ( F_79 ( V_19 , F_10 , & V_154 ) < 0 )
{
F_41 ( V_15 ) ;
goto V_119;
}
}
#endif
if ( V_112 & 0x01 ) V_31 -> V_155 = 1 ;
if ( F_80 ( V_31 ) == V_156 )
{
V_84 = F_81 ( V_19 , V_118 ) ;
if ( F_82 ( V_19 , & V_105 , ( void * ) & V_106 ) < 0 )
{
F_2 ( V_15 , L_148 ,
F_77 () ) ;
F_78 ( V_19 ) ;
goto V_119;
}
( void ) F_83 ( V_84 , 1 , & V_105 ) ;
if ( V_107 )
{
V_88 . V_157 = 0 ;
V_88 . V_158 = V_159 ;
F_84 ( V_84 , V_160 , 0 , & V_88 ) ;
V_88 . V_157 = 0 ;
V_88 . V_158 = V_161 ;
F_84 ( V_84 , V_162 , 0 , & V_88 ) ;
}
if ( V_108 > 28 )
{
F_85 ( V_31 , V_163 ) ;
F_86 ( V_31 , V_108 - 28 ) ;
}
else
F_84 ( V_84 , V_164 , 0 , NULL ) ;
}
else
V_84 = F_87 ( V_19 , V_118 ) ;
if ( V_75 )
{
T_11 * V_165 ;
V_165 = F_46 ( F_88 () ) ;
V_84 = F_89 ( V_165 , V_84 ) ;
}
if ( V_10 )
{
V_31 -> V_155 = 1 ;
F_90 ( V_84 , V_166 ) ;
F_91 ( V_84 , ( char * ) V_11 ) ;
}
if ( V_115 )
{
F_92 ( V_31 , V_167 ) ;
F_93 ( V_31 , V_11 ) ;
}
#ifndef F_14
if ( V_128 )
{
F_94 ( V_31 , V_168 ) ;
F_95 ( V_31 , V_11 ) ;
}
if ( V_129 )
{
F_96 ( V_31 , V_169 ) ;
F_97 ( V_72 , V_170 ) ;
F_98 ( V_72 , V_11 ) ;
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
if ( V_109 )
F_99 ( V_11 , V_84 , V_109 ) ;
#endif
F_100 ( V_31 , V_84 , V_84 ) ;
F_101 ( V_31 ) ;
V_33 = F_102 ( V_31 ) + 1 ;
V_67 = 1 ;
V_66 = 0 ;
V_70 = 0 ;
V_69 = 1 ;
V_68 = 1 ;
V_38 = 0 ;
V_39 = 0 ;
V_40 = 0 ;
V_41 = 0 ;
if ( V_76 == V_140 )
{
int V_171 = 0 ;
T_11 * V_172 = F_46 ( F_103 () ) ;
F_89 ( V_172 , V_84 ) ;
do
{
V_86 = F_104 ( V_172 , V_37 , V_120 ) ;
}
while ( V_86 > 3 && V_37 [ 3 ] == '-' );
F_2 ( V_172 , L_149 ) ;
( void ) F_105 ( V_172 ) ;
do
{
V_86 = F_104 ( V_172 , V_37 , V_120 ) ;
if ( strstr ( V_37 , L_150 ) )
V_171 = 1 ;
}
while ( V_86 > 3 && V_37 [ 3 ] == '-' );
( void ) F_105 ( V_172 ) ;
F_106 ( V_172 ) ;
F_68 ( V_172 ) ;
if ( ! V_171 )
F_2 ( V_15 ,
L_151
L_152 ) ;
F_2 ( V_84 , L_153 ) ;
F_107 ( V_84 , V_36 , V_120 ) ;
}
else if ( V_76 == V_141 )
{
F_107 ( V_84 , V_37 , V_120 ) ;
F_2 ( V_84 , L_154 ) ;
F_107 ( V_84 , V_36 , V_120 ) ;
}
else if ( V_76 == V_142 )
{
int V_171 = 0 ;
T_11 * V_172 = F_46 ( F_103 () ) ;
F_89 ( V_172 , V_84 ) ;
F_104 ( V_172 , V_37 , V_120 ) ;
F_2 ( V_172 , L_155 ) ;
( void ) F_105 ( V_172 ) ;
do
{
V_86 = F_104 ( V_172 , V_37 , V_120 ) ;
if ( strstr ( V_37 , L_150 ) )
V_171 = 1 ;
}
while ( V_86 > 3 && V_37 [ 0 ] != '.' );
( void ) F_105 ( V_172 ) ;
F_106 ( V_172 ) ;
F_68 ( V_172 ) ;
if ( ! V_171 )
F_2 ( V_15 ,
L_156
L_152 ) ;
F_2 ( V_84 , L_157 ) ;
F_107 ( V_84 , V_36 , V_120 ) ;
}
else if ( V_76 == V_143 )
{
T_11 * V_172 = F_46 ( F_103 () ) ;
F_89 ( V_172 , V_84 ) ;
do
{
V_86 = F_104 ( V_172 , V_37 , V_120 ) ;
}
while ( V_86 > 3 && V_37 [ 3 ] == '-' );
( void ) F_105 ( V_172 ) ;
F_106 ( V_172 ) ;
F_68 ( V_172 ) ;
F_2 ( V_84 , L_158 ) ;
F_107 ( V_84 , V_36 , V_120 ) ;
}
if ( V_76 == V_144 )
{
int V_173 = 0 ;
F_2 ( V_84 , L_159
L_160
L_161 , V_47 ) ;
V_173 = F_107 ( V_84 , V_37 , V_120 ) ;
V_37 [ V_173 ] = 0 ;
while ( ! strstr ( V_37 , L_162 ) )
{
if ( strstr ( V_37 , L_163 ) )
goto V_174;
V_173 = F_107 ( V_84 , V_37 , V_120 ) ;
V_37 [ V_173 ] = 0 ;
}
F_2 ( V_84 , L_164 ) ;
V_173 = F_107 ( V_84 , V_36 , V_120 ) ;
V_36 [ V_173 ] = 0 ;
if ( ! strstr ( V_36 , L_165 ) )
goto V_174;
V_37 [ 0 ] = 0 ;
}
for (; ; )
{
F_108 ( & V_42 ) ;
F_108 ( & V_43 ) ;
if ( ( F_80 ( V_31 ) == V_156 ) &&
F_109 ( V_31 , & V_88 ) )
V_89 = & V_88 ;
else
V_89 = NULL ;
if ( F_110 ( V_31 ) && ! F_111 ( V_31 ) )
{
V_73 = 1 ;
V_70 = 0 ;
}
else
{
V_70 = 1 ;
if ( V_73 )
{
V_73 = 0 ;
#if 0
#ifndef F_14
if (servername != NULL && !SSL_session_reused(con))
{
BIO_printf(bio_c_out,"Server did %sacknowledge servername extension.\n",tlsextcbp.ack?"":"not ");
}
#endif
#endif
if ( V_103 )
{
T_11 * V_150 = F_66 ( V_103 , L_166 ) ;
if ( V_150 )
{
F_112 ( V_150 , F_113 ( V_31 ) ) ;
F_68 ( V_150 ) ;
}
else
F_2 ( V_15 , L_167 , V_103 ) ;
}
F_114 ( V_11 , V_31 , V_46 ) ;
if ( V_46 > 0 ) V_46 -- ;
if ( V_76 )
{
F_2 ( V_15 , L_4 , V_37 ) ;
V_76 = V_77 ;
}
if ( V_60 )
{
V_60 -- ;
F_2 ( V_11 , L_168 ) ;
F_115 ( V_31 ) ;
F_101 ( V_31 ) ;
F_78 ( F_102 ( V_31 ) ) ;
goto V_153;
}
}
}
V_71 = V_69 && F_116 ( V_31 ) ;
if ( ! V_71 )
{
#if ! F_19 ( V_94 ) && ! F_19 ( V_95 ) && ! F_19 ( V_96 ) && ! F_19 ( V_97 )
if ( V_70 )
{
if ( V_67 ) F_117 ( fileno ( V_175 ) , & V_42 ) ;
if ( V_66 ) F_117 ( fileno ( stdout ) , & V_43 ) ;
}
if ( V_69 )
F_117 ( F_102 ( V_31 ) , & V_42 ) ;
if ( V_68 )
F_117 ( F_102 ( V_31 ) , & V_43 ) ;
#else
if( ! V_70 || ! V_66 ) {
if ( V_69 )
F_117 ( F_102 ( V_31 ) , & V_42 ) ;
if ( V_68 )
F_117 ( F_102 ( V_31 ) , & V_43 ) ;
}
#endif
#if F_19 ( V_94 ) || F_19 ( V_95 )
V_74 = 0 ;
if( ! V_66 ) {
if( V_67 ) {
V_98 . V_157 = 1 ;
V_98 . V_158 = 0 ;
V_74 = F_118 ( V_33 , ( void * ) & V_42 , ( void * ) & V_43 ,
NULL , & V_98 ) ;
#if F_19 ( V_176 ) || F_19 ( V_95 )
if( ! V_74 && ( ! F_119 () || ! V_67 ) ) continue;
#else
if( ! V_74 && ( ! ( ( F_119 () ) || ( V_177 == F_120 ( F_121 ( V_178 ) , 0 ) ) ) || ! V_67 ) ) continue;
#endif
} else V_74 = F_118 ( V_33 , ( void * ) & V_42 , ( void * ) & V_43 ,
NULL , V_89 ) ;
}
#elif F_19 ( V_96 )
if( ! V_66 ) {
if( V_67 ) {
V_98 . V_157 = 1 ;
V_98 . V_158 = 0 ;
V_74 = F_118 ( V_33 , ( void * ) & V_42 , ( void * ) & V_43 ,
NULL , & V_98 ) ;
} else V_74 = F_118 ( V_33 , ( void * ) & V_42 , ( void * ) & V_43 ,
NULL , V_89 ) ;
}
#elif F_19 ( V_97 )
V_74 = 0 ;
V_99 = 0 ;
( void ) F_122 ( fileno ( V_175 ) , V_179 , V_180 ) ;
if( ! V_66 ) {
if( V_67 ) {
V_98 . V_157 = 1 ;
V_98 . V_158 = 0 ;
V_74 = F_118 ( V_33 , ( void * ) & V_42 , ( void * ) & V_43 ,
NULL , & V_98 ) ;
if ( F_123 ( fileno ( V_175 ) , V_36 , 0 ) >= 0 )
V_99 = 1 ;
if ( ! V_74 && ( V_99 != 1 || ! V_67 ) )
continue;
} else V_74 = F_118 ( V_33 , ( void * ) & V_42 , ( void * ) & V_43 ,
NULL , V_89 ) ;
}
( void ) F_122 ( fileno ( V_175 ) , V_179 , 0 ) ;
#else
V_74 = F_118 ( V_33 , ( void * ) & V_42 , ( void * ) & V_43 ,
NULL , V_89 ) ;
#endif
if ( V_74 < 0 )
{
F_2 ( V_15 , L_169 ,
F_77 () ) ;
goto V_174;
}
}
if ( ( F_80 ( V_31 ) == V_156 ) && F_124 ( V_31 ) > 0 )
{
F_2 ( V_15 , L_170 ) ;
}
if ( ! V_71 && F_125 ( F_102 ( V_31 ) , & V_43 ) )
{
V_32 = F_126 ( V_31 , & ( V_35 [ V_39 ] ) ,
( unsigned int ) V_38 ) ;
switch ( F_127 ( V_31 , V_32 ) )
{
case V_181 :
V_39 += V_32 ;
V_38 -= V_32 ;
if ( V_32 <= 0 ) goto V_119;
if ( V_38 <= 0 )
{
V_67 = 1 ;
V_68 = 0 ;
}
else
{
V_67 = 0 ;
V_68 = 1 ;
}
break;
case V_182 :
F_2 ( V_11 , L_171 ) ;
V_68 = 1 ;
V_67 = 0 ;
break;
case V_183 :
F_2 ( V_11 , L_172 ) ;
V_66 = 0 ;
V_69 = 1 ;
V_68 = 0 ;
break;
case V_184 :
F_2 ( V_11 , L_173 ) ;
break;
case V_185 :
if ( V_38 != 0 )
{
F_2 ( V_11 , L_174 ) ;
V_8 = 0 ;
goto V_174;
}
else
{
V_67 = 1 ;
V_68 = 0 ;
break;
}
case V_186 :
if ( ( V_32 != 0 ) || ( V_38 != 0 ) )
{
F_2 ( V_15 , L_175 ,
F_77 () ) ;
goto V_174;
}
else
{
V_67 = 1 ;
V_68 = 0 ;
}
break;
case V_187 :
F_41 ( V_15 ) ;
goto V_174;
}
}
#if F_19 ( V_94 ) || F_19 ( V_95 ) || F_19 ( V_96 ) || F_19 ( V_97 )
else if ( ! V_71 && V_66 )
#else
else if ( ! V_71 && F_125 ( fileno ( stdout ) , & V_43 ) )
#endif
{
#ifdef F_128
F_129 ( & ( V_36 [ V_41 ] ) , & ( V_36 [ V_41 ] ) , V_40 ) ;
#endif
V_74 = F_130 ( & ( V_36 [ V_41 ] ) , V_40 ) ;
if ( V_74 <= 0 )
{
F_2 ( V_11 , L_176 ) ;
V_8 = 0 ;
goto V_174;
}
V_40 -= V_74 ; ;
V_41 += V_74 ;
if ( V_40 <= 0 )
{
V_69 = 1 ;
V_66 = 0 ;
}
}
else if ( V_71 || F_125 ( F_102 ( V_31 ) , & V_42 ) )
{
#ifdef F_131
{ static int V_188 ; if ( ++ V_188 == 52 ) { F_132 ( V_31 ) ; V_188 = 0 ; } }
#endif
#if 1
V_32 = F_133 ( V_31 , V_36 , 1024 ) ;
#else
V_32 = F_133 ( V_31 , V_36 , 16 ) ;
{ char V_189 [ 10240 ] ;
printf ( L_177 , V_32 , F_116 ( V_31 ) , F_134 ( V_31 , V_189 , 10240 ) ) ;
}
#endif
switch ( F_127 ( V_31 , V_32 ) )
{
case V_181 :
if ( V_32 <= 0 )
goto V_119;
V_41 = 0 ;
V_40 = V_32 ;
V_69 = 0 ;
V_66 = 1 ;
break;
case V_182 :
F_2 ( V_11 , L_178 ) ;
V_68 = 1 ;
V_67 = 0 ;
break;
case V_183 :
F_2 ( V_11 , L_179 ) ;
V_66 = 0 ;
V_69 = 1 ;
if ( ( V_67 == 0 ) && ( V_68 == 0 ) )
V_68 = 1 ;
break;
case V_184 :
F_2 ( V_11 , L_180 ) ;
break;
case V_186 :
V_8 = F_77 () ;
F_2 ( V_15 , L_181 , V_8 ) ;
goto V_174;
case V_185 :
F_2 ( V_11 , L_182 ) ;
V_8 = 0 ;
goto V_174;
case V_187 :
F_41 ( V_15 ) ;
goto V_174;
}
}
#if F_19 ( V_94 ) || F_19 ( V_95 )
#if F_19 ( V_176 ) || F_19 ( V_95 )
else if ( F_119 () )
#else
else if ( ( F_119 () ) || ( V_177 == F_120 ( F_121 ( V_178 ) , 0 ) ) )
#endif
#elif F_19 ( V_96 )
else if ( F_119 () )
#elif F_19 ( V_97 )
else if ( V_99 )
#else
else if ( F_125 ( fileno ( V_175 ) , & V_42 ) )
#endif
{
if ( V_65 )
{
int V_130 , V_190 ;
V_74 = F_135 ( V_35 , V_120 / 2 ) ;
V_190 = 0 ;
for ( V_130 = 0 ; V_130 < V_74 ; V_130 ++ )
if ( V_35 [ V_130 ] == '\n' )
V_190 ++ ;
for ( V_130 = V_74 - 1 ; V_130 >= 0 ; V_130 -- )
{
V_35 [ V_130 + V_190 ] = V_35 [ V_130 ] ;
if ( V_35 [ V_130 ] == '\n' )
{
V_190 -- ;
V_74 ++ ;
V_35 [ V_130 + V_190 ] = '\r' ;
}
}
assert ( V_190 == 0 ) ;
}
else
V_74 = F_135 ( V_35 , V_120 ) ;
if ( ( ! V_114 ) && ( ( V_74 <= 0 ) || ( V_35 [ 0 ] == 'Q' ) ) )
{
F_2 ( V_15 , L_176 ) ;
V_8 = 0 ;
goto V_174;
}
if ( ( ! V_114 ) && ( V_35 [ 0 ] == 'R' ) )
{
F_2 ( V_15 , L_183 ) ;
F_132 ( V_31 ) ;
V_38 = 0 ;
}
else
{
V_38 = V_74 ;
V_39 = 0 ;
#ifdef F_128
F_136 ( V_35 , V_35 , V_74 ) ;
#endif
}
V_68 = 1 ;
V_67 = 0 ;
}
}
V_8 = 0 ;
V_174:
if ( V_73 )
F_114 ( V_11 , V_31 , V_46 ) ;
F_115 ( V_31 ) ;
F_78 ( F_102 ( V_31 ) ) ;
V_119:
if ( V_31 != NULL )
{
if ( V_78 != 0 )
F_114 ( V_11 , V_31 , 1 ) ;
F_137 ( V_31 ) ;
}
if ( V_72 != NULL ) F_138 ( V_72 ) ;
if ( V_55 )
F_139 ( V_55 ) ;
if ( V_56 )
F_140 ( V_56 ) ;
if ( V_54 )
F_141 ( V_54 ) ;
if ( V_35 != NULL ) { F_142 ( V_35 , V_120 ) ; F_141 ( V_35 ) ; }
if ( V_36 != NULL ) { F_142 ( V_36 , V_120 ) ; F_141 ( V_36 ) ; }
if ( V_37 != NULL ) { F_142 ( V_37 , V_120 ) ; F_141 ( V_37 ) ; }
if ( V_11 != NULL )
{
F_68 ( V_11 ) ;
V_11 = NULL ;
}
F_143 () ;
F_144 ( V_8 ) ;
}
static void F_114 ( T_11 * V_191 , T_1 * V_19 , int V_192 )
{
T_6 * V_105 = NULL ;
char * V_22 ;
static const char * V_193 = L_184 ;
char V_194 [ V_195 ] ;
F_145 ( T_6 ) * V_196 ;
F_145 ( V_197 ) * V_198 ;
const T_15 * V_199 ;
V_197 * V_200 ;
int V_130 , V_74 ;
#ifndef F_146
const T_16 * V_201 , * V_202 ;
#endif
if ( V_192 )
{
int V_203 = 0 ;
V_196 = F_147 ( V_19 ) ;
if ( V_196 != NULL )
{
V_203 = 1 ;
F_2 ( V_191 , L_185 ) ;
for ( V_74 = 0 ; V_74 < F_148 ( V_196 ) ; V_74 ++ )
{
F_149 ( F_150 (
F_151 ( V_196 , V_74 ) ) , V_194 , sizeof V_194 ) ;
F_2 ( V_191 , L_186 , V_74 , V_194 ) ;
F_149 ( F_152 (
F_151 ( V_196 , V_74 ) ) , V_194 , sizeof V_194 ) ;
F_2 ( V_191 , L_187 , V_194 ) ;
if ( V_116 )
F_153 ( V_191 , F_151 ( V_196 , V_74 ) ) ;
}
}
F_2 ( V_191 , L_188 ) ;
V_105 = F_154 ( V_19 ) ;
if ( V_105 != NULL )
{
F_2 ( V_191 , L_189 ) ;
if ( ! ( V_116 && V_203 ) )
F_153 ( V_191 , V_105 ) ;
F_149 ( F_150 ( V_105 ) ,
V_194 , sizeof V_194 ) ;
F_2 ( V_191 , L_190 , V_194 ) ;
F_149 ( F_152 ( V_105 ) ,
V_194 , sizeof V_194 ) ;
F_2 ( V_191 , L_191 , V_194 ) ;
}
else
F_2 ( V_191 , L_192 ) ;
V_198 = F_155 ( V_19 ) ;
if ( ( V_198 != NULL ) && ( F_156 ( V_198 ) > 0 ) )
{
F_2 ( V_191 , L_193 ) ;
for ( V_74 = 0 ; V_74 < F_156 ( V_198 ) ; V_74 ++ )
{
V_200 = F_157 ( V_198 , V_74 ) ;
F_149 ( V_200 , V_194 , sizeof( V_194 ) ) ;
F_158 ( V_191 , V_194 , strlen ( V_194 ) ) ;
F_158 ( V_191 , L_11 , 1 ) ;
}
}
else
{
F_2 ( V_191 , L_194 ) ;
}
V_22 = F_159 ( V_19 , V_194 , sizeof V_194 ) ;
if ( V_22 != NULL )
{
F_2 ( V_191 , L_195 ) ;
V_130 = V_74 = 0 ;
while ( * V_22 )
{
if ( * V_22 == ':' )
{
F_158 ( V_191 , V_193 , 15 - V_130 % 25 ) ;
V_74 ++ ;
V_130 = 0 ;
F_158 ( V_191 , ( ( V_74 % 3 ) ? L_196 : L_11 ) , 1 ) ;
}
else
{
F_158 ( V_191 , V_22 , 1 ) ;
V_130 ++ ;
}
V_22 ++ ;
}
F_158 ( V_191 , L_11 , 1 ) ;
}
F_2 ( V_191 , L_197 ,
F_160 ( F_161 ( V_19 ) ) ,
F_162 ( F_163 ( V_19 ) ) ) ;
}
F_2 ( V_191 , ( ( V_19 -> V_204 ) ? L_198 : L_199 ) ) ;
V_199 = F_164 ( V_19 ) ;
F_2 ( V_191 , L_200 ,
F_165 ( V_199 ) ,
F_166 ( V_199 ) ) ;
if ( V_105 != NULL ) {
T_7 * V_205 ;
V_205 = F_167 ( V_105 ) ;
F_2 ( V_191 , L_201 ,
F_168 ( V_205 ) ) ;
F_140 ( V_205 ) ;
}
F_2 ( V_191 , L_202 ,
F_169 ( V_19 ) ? L_203 : L_204 ) ;
#ifndef F_146
V_201 = F_170 ( V_19 ) ;
V_202 = F_171 ( V_19 ) ;
F_2 ( V_191 , L_205 ,
V_201 ? F_172 ( V_201 ) : L_206 ) ;
F_2 ( V_191 , L_207 ,
V_202 ? F_172 ( V_202 ) : L_206 ) ;
#endif
F_173 ( V_191 , F_113 ( V_19 ) ) ;
F_2 ( V_191 , L_188 ) ;
if ( V_105 != NULL )
F_139 ( V_105 ) ;
( void ) F_105 ( V_191 ) ;
}
static int V_170 ( T_1 * V_19 , void * V_21 )
{
const unsigned char * V_22 ;
int V_206 ;
T_17 * V_207 ;
V_206 = F_174 ( V_19 , & V_22 ) ;
F_51 ( V_21 , L_208 ) ;
if ( ! V_22 )
{
F_51 ( V_21 , L_209 ) ;
return 1 ;
}
V_207 = F_175 ( NULL , & V_22 , V_206 ) ;
if ( ! V_207 )
{
F_51 ( V_21 , L_210 ) ;
F_176 ( V_21 , ( char * ) V_22 , V_206 , 4 ) ;
return 0 ;
}
F_51 ( V_21 , L_211 ) ;
F_177 ( V_21 , V_207 , 0 ) ;
F_51 ( V_21 , L_212 ) ;
F_178 ( V_207 ) ;
return 1 ;
}
