int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
char * V_4 = NULL , * V_5 = NULL ;
int V_6 = 0 ;
int V_7 = 0 ;
int V_8 = 0 ;
int V_9 = 0 ;
int V_10 = 0 ;
int V_11 = 1 ;
int V_12 = 1 ;
int V_13 = 0 ;
int V_14 = 0 ;
int V_15 = 0 ;
int V_16 = 0 ;
int V_17 = 0 ;
long V_18 = 0 ;
long V_19 = 0 ;
long V_20 = 0 ;
long V_21 = - 1 ;
char * V_22 = NULL ;
char * V_23 = NULL ;
char * V_24 = NULL ;
char * V_25 = NULL ;
char * V_26 = NULL ;
int V_27 = V_28 ;
char * V_29 = NULL ;
char * V_30 = NULL ;
char * V_31 = NULL ;
char * V_32 = NULL ;
T_2 * V_33 = NULL ;
int V_34 = 0 ;
char * V_35 = NULL ;
char * V_36 = NULL ;
char * V_37 = NULL ;
char * V_38 = NULL ;
char * V_39 = NULL ;
char * V_40 = NULL ;
char * V_41 = NULL ;
unsigned long V_42 = V_43 ;
int V_44 = 0 ;
char * V_45 = NULL ;
char * V_46 = NULL ;
int V_47 = V_48 ;
char * V_49 = NULL ;
T_3 * V_50 = NULL ;
T_3 * V_51 = NULL ;
char * V_52 = NULL ;
char * V_53 = NULL ;
long V_54 = 0 ;
int V_55 = 0 ;
int V_56 = 0 ;
unsigned long V_57 = 0 , V_58 = 0 ;
int V_59 = 1 ;
int V_60 = V_61 ;
int V_62 = 0 ;
T_4 * V_63 = NULL , * V_64 = NULL ;
T_4 * V_65 = NULL ;
T_5 * V_66 = NULL , * V_67 = NULL , * V_68 = NULL , * V_69 = NULL ;
char * V_70 = NULL ;
T_6 * V_71 = NULL ;
T_7 * V_72 = NULL ;
T_8 * V_73 = NULL ;
T_9 * V_74 ;
T_10 * V_75 ;
char * V_76 ;
const char * V_77 ;
char * const * V_78 ;
int V_79 , V_80 ;
const T_11 * V_81 = NULL ;
F_1 ( V_82 ) * V_83 = NULL ;
F_1 ( T_4 ) * V_84 = NULL ;
#undef V_85
#define V_85 256
T_12 char V_86 [ 3 ] [ V_85 ] ;
char * V_87 = NULL ;
#ifndef F_2
char * V_88 = NULL ;
#endif
char * V_89 = NULL ;
T_13 V_90 ;
#ifdef F_3
V_91 = 1 ;
V_92 = 1 ;
V_93 = 0 ;
#endif
F_4 () ;
V_94 = NULL ;
V_4 = NULL ;
V_95 = NULL ;
V_96 = 0 ;
V_97 = 0 ;
if ( V_98 == NULL )
if ( ( V_98 = F_5 ( F_6 () ) ) != NULL )
F_7 ( V_98 , V_99 , V_100 | V_101 ) ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_22 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_95 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_41 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_42 = V_103 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_6 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_44 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_52 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_53 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_54 = atoi ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_23 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_24 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_25 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_27 = F_8 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_5 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_16 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_4 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_17 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_26 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_18 ) == 0 )
V_62 = 1 ;
else if ( strcmp ( * V_2 , L_19 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_29 = * ( ++ V_2 ) ;
V_13 = 1 ;
}
else if ( strcmp ( * V_2 , L_20 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_35 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_21 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_36 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_22 ) == 0 )
V_56 = 1 ;
else if ( strcmp ( * V_2 , L_23 ) == 0 )
V_55 = 1 ;
else if ( strcmp ( * V_2 , L_24 ) == 0 )
V_96 = 1 ;
else if ( strcmp ( * V_2 , L_25 ) == 0 )
V_12 = 0 ;
else if ( strcmp ( * V_2 , L_26 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_27 ) == 0 )
V_97 = 1 ;
else if ( strcmp ( * V_2 , L_28 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_18 = atol ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_29 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_19 = atol ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_30 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_20 = atol ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_31 ) == 0 )
{
V_1 -- ;
V_2 ++ ;
V_13 = 1 ;
break;
}
else if ( strcmp ( * V_2 , L_32 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_31 = * ( ++ V_2 ) ;
V_13 = 1 ;
}
else if ( strcmp ( * V_2 , L_33 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_30 = * ( ++ V_2 ) ;
V_13 = 1 ;
}
else if ( strcmp ( * V_2 , L_34 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_29 = * ( ++ V_2 ) ;
V_16 = 1 ;
}
else if ( strcmp ( * V_2 , L_35 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_39 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_36 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_40 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_37 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_32 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_38 ) == 0 )
{
V_17 = 1 ;
}
else if ( strcmp ( * V_2 , L_39 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_46 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_40 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_49 = * ( ++ V_2 ) ;
V_47 = V_104 ;
}
else if ( strcmp ( * V_2 , L_41 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_49 = * ( ++ V_2 ) ;
V_47 = V_105 ;
}
else if ( strcmp ( * V_2 , L_42 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_49 = * ( ++ V_2 ) ;
V_47 = V_106 ;
}
else if ( strcmp ( * V_2 , L_43 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_49 = * ( ++ V_2 ) ;
V_47 = V_107 ;
}
#ifndef F_2
else if ( strcmp ( * V_2 , L_44 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_102;
V_88 = * ( ++ V_2 ) ;
}
#endif
else
{
V_102:
F_9 ( V_98 , L_45 , * V_2 ) ;
V_10 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_10 )
{
const char * * V_108 ;
for ( V_108 = V_109 ; ( * V_108 != NULL ) ; V_108 ++ )
F_9 ( V_98 , L_46 , * V_108 ) ;
goto V_110;
}
F_10 () ;
V_89 = NULL ;
if ( V_22 == NULL ) V_22 = getenv ( L_47 ) ;
if ( V_22 == NULL ) V_22 = getenv ( L_48 ) ;
if ( V_22 == NULL )
{
const char * V_111 = F_11 () ;
T_14 V_112 ;
#ifdef F_12
V_112 = strlen ( V_111 ) + sizeof( V_113 ) ;
V_89 = F_13 ( V_112 ) ;
strcpy ( V_89 , V_111 ) ;
#else
V_112 = strlen ( V_111 ) + sizeof( V_113 ) + 1 ;
V_89 = F_13 ( V_112 ) ;
F_14 ( V_89 , V_111 , V_112 ) ;
F_15 ( V_89 , L_49 , V_112 ) ;
#endif
F_15 ( V_89 , V_113 , V_112 ) ;
V_22 = V_89 ;
}
F_9 ( V_98 , L_50 , V_22 ) ;
V_94 = F_16 ( NULL ) ;
if ( F_17 ( V_94 , V_22 , & V_21 ) <= 0 )
{
if ( V_21 <= 0 )
F_9 ( V_98 , L_51 ,
V_22 ) ;
else
F_9 ( V_98 , L_52
, V_21 , V_22 ) ;
goto V_110;
}
if( V_89 )
{
F_18 ( V_89 ) ;
V_89 = NULL ;
}
if ( ! F_19 ( V_98 , V_94 ) )
goto V_110;
#ifndef F_2
V_3 = F_20 ( V_98 , V_88 , 0 ) ;
#endif
if ( V_95 == NULL )
{
V_95 = F_21 ( V_94 , V_114 , V_115 ) ;
if ( V_95 == NULL )
{
F_22 ( V_114 , V_115 ) ;
goto V_110;
}
}
if ( V_94 != NULL )
{
V_77 = F_21 ( V_94 , NULL , L_53 ) ;
if ( V_77 == NULL )
F_23 () ;
if ( V_77 != NULL )
{
T_5 * V_116 ;
V_116 = F_24 ( V_77 , L_54 ) ;
if ( V_116 == NULL )
{
F_23 () ;
}
else
{
F_25 ( V_116 ) ;
F_26 ( V_116 ) ;
}
}
if ( ! F_27 ( V_98 , V_94 ) )
{
F_28 ( V_98 ) ;
goto V_110;
}
}
V_87 = F_21 ( V_94 , V_114 , L_55 ) ;
if ( V_87 == NULL )
F_23 () ;
F_29 ( V_87 , V_98 , 0 ) ;
V_76 = F_21 ( V_94 , V_95 , V_117 ) ;
if ( ! V_76 )
F_23 () ;
if( V_76 && ! F_30 ( V_76 ) ) {
F_9 ( V_98 , L_56 , V_76 ) ;
goto V_110;
}
if ( V_42 != V_103 ) {
V_76 = F_21 ( V_94 , V_95 , V_118 ) ;
if ( ! V_76 )
F_23 () ;
else if ( ! strcmp ( V_76 , L_57 ) )
V_42 = V_103 ;
}
V_90 . V_119 = 1 ;
V_77 = F_21 ( V_94 , V_95 , V_120 ) ;
if ( V_77 )
{
#ifdef F_31
F_9 ( V_98 , L_58 , V_77 ) ;
#endif
V_90 . V_119 = F_32 ( V_77 , 1 ) ;
}
else
F_23 () ;
#ifdef F_31
if ( ! V_77 )
F_9 ( V_98 , L_59 , V_77 ) ;
#endif
#ifdef F_31
F_9 ( V_98 , L_60 ,
V_90 . V_119 ) ;
#endif
V_66 = F_5 ( F_6 () ) ;
V_67 = F_5 ( F_6 () ) ;
V_68 = F_5 ( F_6 () ) ;
V_69 = F_5 ( F_6 () ) ;
if ( ( V_66 == NULL ) || ( V_67 == NULL ) || ( V_68 == NULL ) || ( V_69 == NULL ) )
{
F_28 ( V_98 ) ;
goto V_110;
}
if ( V_32 )
{
if ( ( V_70 = F_21 ( V_94 , V_95 , V_121 ) ) == NULL )
{
F_22 ( V_95 , V_121 ) ;
goto V_110;
}
V_71 = F_33 ( V_70 , & V_90 ) ;
if ( V_71 == NULL ) goto V_110;
if ( ! F_34 ( V_71 ) ) goto V_110;
if ( F_35 ( V_32 , V_71 ) != 1 )
F_9 ( V_98 , L_61 ,
V_32 ) ;
goto V_110;
}
if ( ( V_25 == NULL ) && ( ( V_25 = F_21 ( V_94 ,
V_95 , V_122 ) ) == NULL ) )
{
F_22 ( V_95 , V_122 ) ;
goto V_110;
}
if ( ! V_4 )
{
V_7 = 1 ;
if ( ! F_36 ( V_98 , V_5 , NULL , & V_4 , NULL ) )
{
F_9 ( V_98 , L_62 ) ;
goto V_110;
}
}
V_33 = F_37 ( V_98 , V_25 , V_27 , 0 , V_4 , V_3 ,
L_63 ) ;
if ( V_4 ) F_38 ( V_4 , strlen ( V_4 ) ) ;
if ( V_33 == NULL )
{
goto V_110;
}
if ( ! V_62 || V_30 || V_31 || V_15 )
{
if ( ( V_26 == NULL )
&& ( ( V_26 = F_21 ( V_94 ,
V_95 , V_123 ) ) == NULL ) )
{
F_22 ( V_95 , V_123 ) ;
goto V_110;
}
V_63 = F_39 ( V_98 , V_26 , V_28 , NULL , V_3 ,
L_64 ) ;
if ( V_63 == NULL )
goto V_110;
if ( ! F_40 ( V_63 , V_33 ) )
{
F_9 ( V_98 , L_65 ) ;
goto V_110;
}
}
if ( ! V_62 ) V_64 = V_63 ;
V_76 = F_21 ( V_94 , V_114 , V_124 ) ;
if ( V_76 == NULL )
F_23 () ;
if ( ( V_76 != NULL ) && ( ( * V_76 == 'y' ) || ( * V_76 == 'Y' ) ) )
V_96 = 1 ;
V_76 = F_21 ( V_94 , V_114 , V_125 ) ;
if ( V_76 == NULL )
F_23 () ;
if ( ( V_76 != NULL ) && ( ( * V_76 == 'y' ) || ( * V_76 == 'Y' ) ) )
V_97 = 1 ;
V_76 = F_21 ( V_94 , V_95 , V_126 ) ;
if ( V_76 )
{
if ( ! F_41 ( & V_57 , V_76 ) )
{
F_9 ( V_98 , L_66 , V_76 ) ;
goto V_110;
}
V_59 = 0 ;
}
else
F_23 () ;
V_76 = F_21 ( V_94 , V_95 , V_127 ) ;
if ( V_76 )
{
if ( ! F_42 ( & V_58 , V_76 ) )
{
F_9 ( V_98 , L_67 , V_76 ) ;
goto V_110;
}
V_59 = 0 ;
}
else
F_23 () ;
V_76 = F_21 ( V_94 , V_95 , V_128 ) ;
if ( V_76 )
{
if ( ! F_43 ( & V_60 , V_76 ) )
{
F_9 ( V_98 , L_68 , V_76 ) ;
goto V_110;
}
}
else
F_23 () ;
if ( ( V_36 == NULL ) && ( V_13 ) )
{
if ( ( V_36 = F_21 ( V_94 , V_95 , V_129 ) )
== NULL )
{
F_9 ( V_98 , L_69 ) ;
goto V_110;
}
#ifndef F_12
#ifndef F_44
if ( F_45 ( V_36 , V_130 | V_131 | V_132 ) != 0 )
#else
if ( F_46 ( V_36 , V_130 | V_131 | V_132 ) != 0 )
#endif
{
F_9 ( V_98 , L_70 , V_36 ) ;
perror ( V_36 ) ;
goto V_110;
}
if ( F_47 ( V_36 ) <= 0 )
{
F_9 ( V_98 , L_71 , V_36 ) ;
perror ( V_36 ) ;
goto V_110;
}
#endif
}
if ( ( V_70 = F_21 ( V_94 , V_95 , V_121 ) ) == NULL )
{
F_22 ( V_95 , V_121 ) ;
goto V_110;
}
V_71 = F_33 ( V_70 , & V_90 ) ;
if ( V_71 == NULL ) goto V_110;
for ( V_79 = 0 ; V_79 < F_48 ( V_71 -> V_71 -> V_133 ) ; V_79 ++ )
{
V_78 = F_49 ( V_71 -> V_71 -> V_133 , V_79 ) ;
if ( ( V_78 [ V_134 ] [ 0 ] != V_135 ) &&
( V_78 [ V_136 ] [ 0 ] != '\0' ) )
{
F_9 ( V_98 , L_72 , V_79 + 1 ) ;
goto V_110;
}
if ( ( V_78 [ V_134 ] [ 0 ] == V_135 ) &&
! F_50 ( NULL , V_78 [ V_136 ] ) )
{
F_9 ( V_98 , L_73 , V_79 + 1 ) ;
goto V_110;
}
if ( ! F_51 ( ( char * ) V_78 [ V_137 ] ) )
{
F_9 ( V_98 , L_74 , V_79 + 1 ) ;
goto V_110;
}
V_77 = V_78 [ V_138 ] ;
V_80 = strlen ( V_77 ) ;
if ( * V_77 == '-' )
{
V_77 ++ ;
V_80 -- ;
}
if ( ( V_80 & 1 ) || ( V_80 < 2 ) )
{
F_9 ( V_98 , L_75 , V_79 + 1 , V_80 ) ;
goto V_110;
}
while ( * V_77 )
{
if ( ! ( ( ( * V_77 >= '0' ) && ( * V_77 <= '9' ) ) ||
( ( * V_77 >= 'A' ) && ( * V_77 <= 'F' ) ) ||
( ( * V_77 >= 'a' ) && ( * V_77 <= 'f' ) ) ) )
{
F_9 ( V_98 , L_76 , V_79 + 1 , ( long ) ( V_77 - V_78 [ V_138 ] ) , * V_77 ) ;
goto V_110;
}
V_77 ++ ;
}
}
if ( V_14 )
{
F_7 ( V_67 , stdout , V_100 | V_101 ) ;
#ifdef F_12
{
T_5 * V_139 = F_5 ( F_52 () ) ;
V_67 = F_53 ( V_139 , V_67 ) ;
}
#endif
F_54 ( V_67 , V_71 -> V_71 ) ;
F_9 ( V_98 , L_77 ,
F_48 ( V_71 -> V_71 -> V_133 ) ) ;
F_9 ( V_98 , L_78 ) ;
}
if ( ! F_34 ( V_71 ) ) goto V_110;
if ( V_17 )
{
if ( V_14 )
F_9 ( V_98 , L_79 ,
V_70 ) ;
V_79 = F_55 ( V_71 ) ;
if ( V_79 == - 1 )
{
F_9 ( V_98 , L_80 ) ;
goto V_110;
}
else if ( V_79 == 0 )
{
if ( V_14 ) F_9 ( V_98 ,
L_81 ) ;
}
else
{
if ( ! F_56 ( V_70 , L_82 , V_71 ) ) goto V_110;
if ( ! F_57 ( V_70 , L_82 , L_83 ) ) goto V_110;
if ( V_14 ) F_9 ( V_98 ,
L_84 , V_79 ) ;
}
}
if ( V_40 )
{
V_140 = F_16 ( NULL ) ;
if ( F_17 ( V_140 , V_40 , & V_21 ) <= 0 )
{
if ( V_21 <= 0 )
F_9 ( V_98 , L_85 ,
V_40 ) ;
else
F_9 ( V_98 , L_86 ,
V_21 , V_40 ) ;
V_11 = 1 ;
goto V_110;
}
if ( V_14 )
F_9 ( V_98 , L_87 , V_40 ) ;
if ( ! V_39 && ! ( V_39 = F_21 ( V_140 , L_88 , L_89 ) ) )
V_39 = L_88 ;
}
if ( V_13 || V_15 )
{
if ( V_35 != NULL )
{
if ( F_58 ( V_68 , V_35 ) <= 0 )
{
perror ( V_35 ) ;
goto V_110;
}
}
else
{
F_7 ( V_68 , stdout , V_100 | V_101 ) ;
#ifdef F_12
{
T_5 * V_139 = F_5 ( F_52 () ) ;
V_68 = F_53 ( V_139 , V_68 ) ;
}
#endif
}
}
if ( ( V_23 == NULL ) && ( ( V_23 = F_21 ( V_94 ,
V_95 , V_141 ) ) == NULL ) )
{
F_22 ( V_95 , V_141 ) ;
goto V_110;
}
if ( ! strcmp ( V_23 , L_88 ) )
{
int V_142 ;
if ( F_59 ( V_33 , & V_142 ) <= 0 )
{
F_60 ( V_98 , L_90 ) ;
goto V_110;
}
V_23 = ( char * ) F_61 ( V_142 ) ;
}
if ( ( V_81 = F_62 ( V_23 ) ) == NULL )
{
F_9 ( V_98 , L_91 , V_23 ) ;
goto V_110;
}
if ( V_13 )
{
if ( ( V_12 == 1 ) && ( ( V_45 = F_21 ( V_94 ,
V_95 , V_143 ) ) != NULL ) )
{
if( strcmp ( V_45 , L_92 ) == 0 )
V_12 = 0 ;
}
if ( V_14 )
F_9 ( V_98 , L_93 ,
F_63 ( V_81 -> type ) ) ;
if ( ( V_24 == NULL ) && ( ( V_24 = F_21 ( V_94 ,
V_95 , V_144 ) ) == NULL ) )
{
F_22 ( V_95 , V_144 ) ;
goto V_110;
}
if ( V_14 )
F_9 ( V_98 , L_94 , V_24 ) ;
if ( ( V_37 = F_21 ( V_94 , V_95 , V_145 ) )
== NULL )
{
F_22 ( V_95 , V_145 ) ;
goto V_110;
}
if ( ! V_140 )
{
if ( ! V_39 )
{
V_39 = F_21 ( V_94 , V_95 ,
V_146 ) ;
if ( ! V_39 )
F_23 () ;
}
if ( V_39 )
{
T_15 V_147 ;
F_64 ( & V_147 ) ;
F_65 ( & V_147 , V_94 ) ;
if ( ! F_66 ( V_94 , & V_147 , V_39 ,
NULL ) )
{
F_9 ( V_98 ,
L_95 ,
V_39 ) ;
V_11 = 1 ;
goto V_110;
}
}
}
if ( V_52 == NULL )
{
V_52 = F_21 ( V_94 , V_95 ,
V_148 ) ;
if ( V_52 == NULL )
F_23 () ;
}
if ( V_52 && ! F_67 ( NULL , V_52 ) )
{
F_9 ( V_98 , L_96 ) ;
goto V_110;
}
if ( V_52 == NULL ) V_52 = L_97 ;
if ( V_53 == NULL )
{
V_53 = F_21 ( V_94 , V_95 ,
V_149 ) ;
if ( V_53 == NULL )
F_23 () ;
}
if ( V_53 && ! F_67 ( NULL , V_53 ) )
{
F_9 ( V_98 , L_98 ) ;
goto V_110;
}
if ( V_54 == 0 )
{
if( ! F_68 ( V_94 , V_95 , V_150 , & V_54 ) )
V_54 = 0 ;
}
if ( ! V_53 && ( V_54 == 0 ) )
{
F_9 ( V_98 , L_99 ) ;
goto V_110;
}
if ( ( V_50 = F_69 ( V_37 , V_6 , NULL ) ) == NULL )
{
F_9 ( V_98 , L_100 ) ;
goto V_110;
}
if ( V_14 )
{
if ( F_70 ( V_50 ) )
F_9 ( V_98 , L_101 ) ;
else
{
if ( ( V_76 = F_71 ( V_50 ) ) == NULL ) goto V_110;
F_9 ( V_98 , L_102 , V_76 ) ;
F_18 ( V_76 ) ;
}
}
if ( ( V_83 = F_72 ( V_94 , V_24 ) ) == NULL )
{
F_9 ( V_98 , L_103 , V_24 ) ;
goto V_110;
}
if ( ( V_84 = F_73 () ) == NULL )
{
F_9 ( V_98 , L_104 ) ;
goto V_110;
}
if ( V_30 != NULL )
{
V_8 ++ ;
V_80 = F_74 ( & V_65 , V_30 , V_33 , V_63 , V_81 , V_83 , V_71 ,
V_50 , V_41 , V_42 , V_44 , V_12 , V_52 , V_53 , V_54 , V_39 ,
V_94 , V_14 , V_58 , V_57 , V_59 , V_60 ) ;
if ( V_80 < 0 ) goto V_110;
if ( V_80 > 0 )
{
V_9 ++ ;
F_9 ( V_98 , L_105 ) ;
if ( ! F_75 ( V_50 , 1 ) ) goto V_110;
if ( ! F_76 ( V_84 , V_65 ) )
{
F_9 ( V_98 , L_104 ) ;
goto V_110;
}
if ( V_35 )
{
V_34 = 1 ;
V_55 = 1 ;
}
}
}
if ( V_31 != NULL )
{
V_8 ++ ;
V_80 = F_77 ( & V_65 , V_31 , V_33 , V_63 , V_81 , V_83 ,
V_71 , V_50 , V_41 , V_42 , V_44 , V_12 , V_52 , V_53 , V_54 , V_55 ,
V_39 , V_94 , V_14 , V_58 , V_57 ,
V_59 , V_60 , V_3 ) ;
if ( V_80 < 0 ) goto V_110;
if ( V_80 > 0 )
{
V_9 ++ ;
F_9 ( V_98 , L_105 ) ;
if ( ! F_75 ( V_50 , 1 ) ) goto V_110;
if ( ! F_76 ( V_84 , V_65 ) )
{
F_9 ( V_98 , L_104 ) ;
goto V_110;
}
}
}
if ( V_29 != NULL )
{
V_8 ++ ;
V_80 = F_78 ( & V_65 , V_29 , V_33 , V_64 , V_81 , V_83 , V_71 ,
V_50 , V_41 , V_42 , V_44 , V_12 , V_52 , V_53 , V_54 , V_55 ,
V_39 , V_94 , V_14 , V_58 , V_57 ,
V_59 , V_60 , V_62 ) ;
if ( V_80 < 0 ) goto V_110;
if ( V_80 > 0 )
{
V_9 ++ ;
F_9 ( V_98 , L_105 ) ;
if ( ! F_75 ( V_50 , 1 ) ) goto V_110;
if ( ! F_76 ( V_84 , V_65 ) )
{
F_9 ( V_98 , L_104 ) ;
goto V_110;
}
}
}
for ( V_79 = 0 ; V_79 < V_1 ; V_79 ++ )
{
V_8 ++ ;
V_80 = F_78 ( & V_65 , V_2 [ V_79 ] , V_33 , V_64 , V_81 , V_83 , V_71 ,
V_50 , V_41 , V_42 , V_44 , V_12 , V_52 , V_53 , V_54 , V_55 ,
V_39 , V_94 , V_14 , V_58 , V_57 ,
V_59 , V_60 , V_62 ) ;
if ( V_80 < 0 ) goto V_110;
if ( V_80 > 0 )
{
V_9 ++ ;
F_9 ( V_98 , L_105 ) ;
if ( ! F_75 ( V_50 , 1 ) ) goto V_110;
if ( ! F_76 ( V_84 , V_65 ) )
{
F_9 ( V_98 , L_104 ) ;
goto V_110;
}
}
}
if ( F_79 ( V_84 ) > 0 )
{
if ( ! V_55 )
{
F_9 ( V_98 , L_106 , V_9 , V_8 ) ;
( void ) F_80 ( V_98 ) ;
V_86 [ 0 ] [ 0 ] = '\0' ;
if ( ! fgets ( V_86 [ 0 ] , 10 , V_151 ) )
{
F_9 ( V_98 , L_107 ) ;
V_11 = 0 ;
goto V_110;
}
if ( ( V_86 [ 0 ] [ 0 ] != 'y' ) && ( V_86 [ 0 ] [ 0 ] != 'Y' ) )
{
F_9 ( V_98 , L_108 ) ;
V_11 = 0 ;
goto V_110;
}
}
F_9 ( V_98 , L_109 , F_79 ( V_84 ) ) ;
if ( ! F_81 ( V_37 , L_82 , V_50 , NULL ) ) goto V_110;
if ( ! F_56 ( V_70 , L_82 , V_71 ) ) goto V_110;
}
if ( V_14 )
F_9 ( V_98 , L_110 ) ;
for ( V_79 = 0 ; V_79 < F_79 ( V_84 ) ; V_79 ++ )
{
int V_152 ;
char * V_153 ;
V_65 = F_82 ( V_84 , V_79 ) ;
V_80 = V_65 -> V_154 -> V_155 -> V_156 ;
V_77 = ( const char * ) V_65 -> V_154 -> V_155 -> V_133 ;
if( strlen ( V_36 ) >= ( T_14 ) ( V_80 ? V_85 - V_80 * 2 - 6 : V_85 - 8 ) )
{
F_9 ( V_98 , L_111 ) ;
goto V_110;
}
strcpy ( V_86 [ 2 ] , V_36 ) ;
#ifndef F_12
F_15 ( V_86 [ 2 ] , L_49 , sizeof( V_86 [ 2 ] ) ) ;
#endif
V_153 = ( char * ) & ( V_86 [ 2 ] [ strlen ( V_86 [ 2 ] ) ] ) ;
if ( V_80 > 0 )
{
for ( V_152 = 0 ; V_152 < V_80 ; V_152 ++ )
{
if ( V_153 >= & ( V_86 [ 2 ] [ sizeof( V_86 [ 2 ] ) ] ) )
break;
F_83 ( V_153 ,
& V_86 [ 2 ] [ 0 ] + sizeof( V_86 [ 2 ] ) - V_153 ,
L_112 , ( unsigned char ) * ( V_77 ++ ) ) ;
V_153 += 2 ;
}
}
else
{
* ( V_153 ++ ) = '0' ;
* ( V_153 ++ ) = '0' ;
}
* ( V_153 ++ ) = '.' ; * ( V_153 ++ ) = 'p' ; * ( V_153 ++ ) = 'e' ; * ( V_153 ++ ) = 'm' ;
* V_153 = '\0' ;
if ( V_14 )
F_9 ( V_98 , L_113 , V_86 [ 2 ] ) ;
if ( F_58 ( V_69 , V_86 [ 2 ] ) <= 0 )
{
perror ( V_86 [ 2 ] ) ;
goto V_110;
}
F_84 ( V_69 , V_65 , 0 , V_56 ) ;
F_84 ( V_68 , V_65 , V_34 , V_56 ) ;
}
if ( F_79 ( V_84 ) )
{
if ( ! F_85 ( V_37 , L_82 , L_83 ) ) goto V_110;
if ( ! F_57 ( V_70 , L_82 , L_83 ) ) goto V_110;
F_9 ( V_98 , L_114 ) ;
}
}
if ( V_15 )
{
int V_157 = 0 ;
if ( ! V_46 )
{
V_46 = F_21 ( V_94 , V_95 , V_158 ) ;
if ( ! V_46 )
F_23 () ;
}
if ( V_46 )
{
T_15 V_147 ;
F_64 ( & V_147 ) ;
F_65 ( & V_147 , V_94 ) ;
if ( ! F_66 ( V_94 , & V_147 , V_46 , NULL ) )
{
F_9 ( V_98 ,
L_115 ,
V_46 ) ;
V_11 = 1 ;
goto V_110;
}
}
if ( ( V_38 = F_21 ( V_94 , V_95 , V_159 ) )
!= NULL )
if ( ( V_51 = F_69 ( V_38 , 0 , NULL ) ) == NULL )
{
F_9 ( V_98 , L_116 ) ;
goto V_110;
}
if ( ! V_18 && ! V_19 && ! V_20 )
{
if ( ! F_68 ( V_94 , V_95 ,
V_160 , & V_18 ) )
V_18 = 0 ;
if ( ! F_68 ( V_94 , V_95 ,
V_161 , & V_19 ) )
V_19 = 0 ;
}
if ( ( V_18 == 0 ) && ( V_19 == 0 ) && ( V_20 == 0 ) )
{
F_9 ( V_98 , L_117 ) ;
goto V_110;
}
if ( V_14 ) F_9 ( V_98 , L_118 ) ;
if ( ( V_72 = F_86 () ) == NULL ) goto V_110;
if ( ! F_87 ( V_72 , F_88 ( V_63 ) ) ) goto V_110;
V_74 = F_89 () ;
if ( ! V_74 ) goto V_110;
F_90 ( V_74 , 0 ) ;
F_91 ( V_72 , V_74 ) ;
if ( ! F_92 ( V_74 , V_18 , V_19 * 60 * 60 + V_20 ,
NULL ) )
{
F_60 ( V_98 , L_119 ) ;
goto V_110;
}
F_93 ( V_72 , V_74 ) ;
F_94 ( V_74 ) ;
for ( V_79 = 0 ; V_79 < F_48 ( V_71 -> V_71 -> V_133 ) ; V_79 ++ )
{
V_78 = F_49 ( V_71 -> V_71 -> V_133 , V_79 ) ;
if ( V_78 [ V_134 ] [ 0 ] == V_135 )
{
if ( ( V_73 = F_95 () ) == NULL ) goto V_110;
V_80 = F_50 ( V_73 , V_78 [ V_136 ] ) ;
if ( ! V_80 ) goto V_110;
if ( V_80 == 2 ) V_157 = 1 ;
if ( ! F_96 ( & V_50 , V_78 [ V_138 ] ) )
goto V_110;
V_75 = F_97 ( V_50 , NULL ) ;
F_98 ( V_50 ) ;
V_50 = NULL ;
if ( ! V_75 )
goto V_110;
F_99 ( V_73 , V_75 ) ;
F_100 ( V_75 ) ;
F_101 ( V_72 , V_73 ) ;
}
}
F_102 ( V_72 ) ;
if ( V_14 ) F_9 ( V_98 , L_120 ) ;
if ( V_46 || V_38 != NULL )
{
T_15 V_162 ;
F_103 ( & V_162 , V_63 , NULL , NULL , V_72 , 0 ) ;
F_65 ( & V_162 , V_94 ) ;
if ( V_46 )
if ( ! F_104 ( V_94 , & V_162 ,
V_46 , V_72 ) ) goto V_110;
if ( V_38 != NULL )
{
V_75 = F_97 ( V_51 , NULL ) ;
if ( ! V_75 ) goto V_110;
F_105 ( V_72 , V_163 , V_75 , 0 , 0 ) ;
F_100 ( V_75 ) ;
V_157 = 1 ;
if ( ! F_75 ( V_51 , 1 ) ) goto V_110;
}
}
if ( V_46 || V_157 )
{
if ( ! F_106 ( V_72 , 1 ) )
goto V_110;
}
if ( V_38 != NULL )
if ( ! F_81 ( V_38 , L_82 , V_51 , NULL ) ) goto V_110;
if ( V_51 )
{
F_98 ( V_51 ) ;
V_51 = NULL ;
}
if ( ! F_107 ( V_72 , V_33 , V_81 ) ) goto V_110;
F_108 ( V_68 , V_72 ) ;
if ( V_38 != NULL )
if ( ! F_85 ( V_38 , L_82 , L_83 ) ) goto V_110;
}
if ( V_16 )
{
if ( V_29 == NULL )
{
F_9 ( V_98 , L_121 ) ;
goto V_110;
}
else
{
T_4 * V_164 ;
V_164 = F_39 ( V_98 , V_29 , V_28 ,
NULL , V_3 , V_29 ) ;
if ( V_164 == NULL )
goto V_110;
V_80 = F_109 ( V_164 , V_71 , V_47 , V_49 ) ;
if ( V_80 <= 0 ) goto V_110;
F_110 ( V_164 ) ;
if ( ! F_56 ( V_70 , L_82 , V_71 ) ) goto V_110;
if ( ! F_57 ( V_70 , L_82 , L_83 ) ) goto V_110;
F_9 ( V_98 , L_114 ) ;
}
}
V_11 = 0 ;
V_110:
if( V_89 )
F_18 ( V_89 ) ;
F_111 ( V_69 ) ;
F_111 ( V_68 ) ;
F_111 ( V_67 ) ;
F_111 ( V_66 ) ;
if ( V_84 )
F_112 ( V_84 , F_110 ) ;
if ( V_11 ) F_28 ( V_98 ) ;
F_113 ( V_87 , V_98 ) ;
if ( V_7 && V_4 )
F_18 ( V_4 ) ;
F_98 ( V_50 ) ;
F_98 ( V_51 ) ;
F_114 ( V_71 ) ;
F_115 ( V_33 ) ;
if ( V_63 ) F_110 ( V_63 ) ;
F_116 ( V_72 ) ;
F_117 ( V_94 ) ;
F_117 ( V_140 ) ;
F_118 () ;
F_119 () ;
F_120 ( V_11 ) ;
}
static void F_22 ( const char * V_165 , const char * V_166 )
{
F_9 ( V_98 , L_122 , V_165 , V_166 ) ;
}
static void F_84 ( T_5 * V_167 , T_4 * V_65 , int V_34 , int V_56 )
{
if ( V_34 )
{
( void ) F_121 ( V_167 , V_65 ) ;
return;
}
#if 0
f=X509_NAME_oneline(X509_get_issuer_name(x),buf,256);
BIO_printf(bp,"issuer :%s\n",f);
f=X509_NAME_oneline(X509_get_subject_name(x),buf,256);
BIO_printf(bp,"subject:%s\n",f);
BIO_puts(bp,"serial :");
i2a_ASN1_INTEGER(bp,x->cert_info->serialNumber);
BIO_puts(bp,"\n\n");
#endif
if ( ! V_56 ) F_122 ( V_167 , V_65 ) ;
F_123 ( V_167 , V_65 ) ;
}
static int F_51 ( const char * V_168 )
{
return F_67 ( NULL , V_168 ) ;
}
static int F_109 ( T_4 * V_63 , T_6 * V_71 , int type , char * V_169 )
{
T_16 * V_170 = NULL ;
char * V_171 [ V_172 ] , * * V_173 , * * V_174 ;
char * V_175 = NULL ;
T_3 * V_176 = NULL ;
int V_177 = - 1 , V_79 ;
for ( V_79 = 0 ; V_79 < V_172 ; V_79 ++ )
V_171 [ V_79 ] = NULL ;
V_171 [ V_178 ] = F_124 ( F_88 ( V_63 ) , NULL , 0 ) ;
V_176 = F_125 ( F_126 ( V_63 ) , NULL ) ;
if ( ! V_176 )
goto V_110;
if ( F_70 ( V_176 ) )
V_171 [ V_138 ] = F_127 ( L_123 ) ;
else
V_171 [ V_138 ] = F_71 ( V_176 ) ;
F_98 ( V_176 ) ;
if ( ( V_171 [ V_178 ] == NULL ) || ( V_171 [ V_138 ] == NULL ) )
{
F_9 ( V_98 , L_104 ) ;
goto V_110;
}
V_173 = F_128 ( V_71 -> V_71 , V_138 , V_171 ) ;
if ( V_173 == NULL )
{
F_9 ( V_98 , L_124 , V_171 [ V_138 ] , V_171 [ V_178 ] ) ;
V_171 [ V_134 ] = ( char * ) F_13 ( 2 ) ;
V_170 = F_129 ( V_63 ) ;
V_171 [ V_137 ] = ( char * ) F_13 ( V_170 -> V_156 + 1 ) ;
memcpy ( V_171 [ V_137 ] , V_170 -> V_133 , V_170 -> V_156 ) ;
V_171 [ V_137 ] [ V_170 -> V_156 ] = '\0' ;
V_171 [ V_136 ] = NULL ;
V_171 [ V_179 ] = ( char * ) F_13 ( 8 ) ;
if ( ( V_171 [ V_134 ] == NULL ) || ( V_171 [ V_137 ] == NULL ) ||
( V_171 [ V_179 ] == NULL ) )
{
F_9 ( V_98 , L_104 ) ;
goto V_110;
}
F_14 ( V_171 [ V_179 ] , L_125 , 8 ) ;
V_171 [ V_134 ] [ 0 ] = 'V' ;
V_171 [ V_134 ] [ 1 ] = '\0' ;
if ( ( V_174 = ( char * * ) F_13 ( sizeof( char * ) * ( V_172 + 1 ) ) ) == NULL )
{
F_9 ( V_98 , L_104 ) ;
goto V_110;
}
for ( V_79 = 0 ; V_79 < V_172 ; V_79 ++ )
{
V_174 [ V_79 ] = V_171 [ V_79 ] ;
V_171 [ V_79 ] = NULL ;
}
V_174 [ V_172 ] = NULL ;
if ( ! F_130 ( V_71 -> V_71 , V_174 ) )
{
F_9 ( V_98 , L_126 ) ;
F_9 ( V_98 , L_127 , V_71 -> V_71 -> error ) ;
goto V_110;
}
V_177 = F_109 ( V_63 , V_71 , type , V_169 ) ;
goto V_110;
}
else if ( F_131 ( V_171 , V_173 ) )
{
F_9 ( V_98 , L_128 ,
V_171 [ V_178 ] ) ;
goto V_110;
}
else if ( V_173 [ V_134 ] [ 0 ] == 'R' )
{
F_9 ( V_98 , L_129 ,
V_171 [ V_138 ] ) ;
goto V_110;
}
else
{
F_9 ( V_98 , L_130 , V_173 [ V_138 ] ) ;
V_175 = F_132 ( type , V_169 ) ;
if ( ! V_175 )
{
F_9 ( V_98 , L_131 ) ;
goto V_110;
}
V_173 [ V_134 ] [ 0 ] = 'R' ;
V_173 [ V_134 ] [ 1 ] = '\0' ;
V_173 [ V_136 ] = V_175 ;
}
V_177 = 1 ;
V_110:
for ( V_79 = 0 ; V_79 < V_172 ; V_79 ++ )
{
if ( V_171 [ V_79 ] != NULL )
F_18 ( V_171 [ V_79 ] ) ;
}
return ( V_177 ) ;
}
static int F_35 ( const char * V_50 , T_6 * V_71 )
{
char * V_171 [ V_172 ] , * * V_173 ;
int V_177 = - 1 , V_79 ;
for ( V_79 = 0 ; V_79 < V_172 ; V_79 ++ )
V_171 [ V_79 ] = NULL ;
V_171 [ V_138 ] = F_13 ( strlen ( V_50 ) + 2 ) ;
if ( V_171 [ V_138 ] == NULL )
{
F_9 ( V_98 , L_80 ) ;
goto V_110;
}
if ( strlen ( V_50 ) % 2 )
{
;
V_171 [ V_138 ] [ 0 ] = '0' ;
memcpy ( V_171 [ V_138 ] + 1 , V_50 , strlen ( V_50 ) ) ;
V_171 [ V_138 ] [ strlen ( V_50 ) + 1 ] = '\0' ;
}
else
{
memcpy ( V_171 [ V_138 ] , V_50 , strlen ( V_50 ) ) ;
V_171 [ V_138 ] [ strlen ( V_50 ) ] = '\0' ;
}
for ( V_79 = 0 ; V_171 [ V_138 ] [ V_79 ] != '\0' ; V_79 ++ )
V_171 [ V_138 ] [ V_79 ] = toupper ( V_171 [ V_138 ] [ V_79 ] ) ;
V_177 = 1 ;
V_173 = F_128 ( V_71 -> V_71 , V_138 , V_171 ) ;
if ( V_173 == NULL )
{
F_9 ( V_98 , L_132 ,
V_171 [ V_138 ] ) ;
V_177 = - 1 ;
goto V_110;
}
else if ( V_173 [ V_134 ] [ 0 ] == 'V' )
{
F_9 ( V_98 , L_133 ,
V_171 [ V_138 ] , V_173 [ V_134 ] [ 0 ] ) ;
goto V_110;
}
else if ( V_173 [ V_134 ] [ 0 ] == 'R' )
{
F_9 ( V_98 , L_134 ,
V_171 [ V_138 ] , V_173 [ V_134 ] [ 0 ] ) ;
goto V_110;
}
else if ( V_173 [ V_134 ] [ 0 ] == 'E' )
{
F_9 ( V_98 , L_135 ,
V_171 [ V_138 ] , V_173 [ V_134 ] [ 0 ] ) ;
goto V_110;
}
else if ( V_173 [ V_134 ] [ 0 ] == 'S' )
{
F_9 ( V_98 , L_136 ,
V_171 [ V_138 ] , V_173 [ V_134 ] [ 0 ] ) ;
goto V_110;
}
else
{
F_9 ( V_98 , L_137 ,
V_171 [ V_138 ] , V_173 [ V_134 ] [ 0 ] ) ;
V_177 = - 1 ;
}
V_110:
for ( V_79 = 0 ; V_79 < V_172 ; V_79 ++ )
{
if ( V_171 [ V_79 ] != NULL )
F_18 ( V_171 [ V_79 ] ) ;
}
return ( V_177 ) ;
}
static int F_55 ( T_6 * V_71 )
{
T_16 * V_180 = NULL ;
int V_79 , V_181 = 0 ;
int V_182 , V_183 ;
char * * V_173 , * V_184 ;
V_180 = F_133 () ;
V_180 = F_90 ( V_180 , 0 ) ;
V_184 = ( char * ) F_13 ( V_180 -> V_156 + 1 ) ;
if ( V_184 == NULL )
{
V_181 = - 1 ;
goto V_110;
}
memcpy ( V_184 , V_180 -> V_133 , V_180 -> V_156 ) ;
V_184 [ V_180 -> V_156 ] = '\0' ;
if ( strncmp ( V_184 , L_138 , 2 ) <= 0 )
V_183 = 1 ;
else
V_183 = 0 ;
for ( V_79 = 0 ; V_79 < F_48 ( V_71 -> V_71 -> V_133 ) ; V_79 ++ )
{
V_173 = F_49 ( V_71 -> V_71 -> V_133 , V_79 ) ;
if ( V_173 [ V_134 ] [ 0 ] == 'V' )
{
if ( strncmp ( V_173 [ V_137 ] , L_138 , 2 ) <= 0 )
V_182 = 1 ;
else
V_182 = 0 ;
if ( V_182 == V_183 )
{
if ( strcmp ( V_173 [ V_137 ] , V_184 ) <= 0 )
{
V_173 [ V_134 ] [ 0 ] = 'E' ;
V_173 [ V_134 ] [ 1 ] = '\0' ;
V_181 ++ ;
F_9 ( V_98 , L_139 ,
V_173 [ V_138 ] ) ;
}
}
else if ( V_182 < V_183 )
{
V_173 [ V_134 ] [ 0 ] = 'E' ;
V_173 [ V_134 ] [ 1 ] = '\0' ;
V_181 ++ ;
F_9 ( V_98 , L_139 ,
V_173 [ V_138 ] ) ;
}
}
}
V_110:
F_134 ( V_180 ) ;
F_18 ( V_184 ) ;
return ( V_181 ) ;
}
char * F_132 ( int V_47 , char * V_49 )
{
char * V_185 = NULL , * V_168 ;
const char * V_186 = NULL ;
T_17 * V_187 ;
T_16 * V_188 = NULL ;
int V_79 ;
switch ( V_47 )
{
case V_48 :
break;
case V_104 :
for ( V_79 = 0 ; V_79 < 8 ; V_79 ++ )
{
if ( ! strcasecmp ( V_49 , V_189 [ V_79 ] ) )
{
V_186 = V_189 [ V_79 ] ;
break;
}
}
if ( V_186 == NULL )
{
F_9 ( V_98 , L_140 , V_49 ) ;
return NULL ;
}
break;
case V_105 :
V_187 = F_135 ( V_49 , 0 ) ;
F_136 ( V_187 ) ;
if ( V_187 == NULL )
{
F_9 ( V_98 , L_141 , V_49 ) ;
return NULL ;
}
V_186 = L_142 ;
V_185 = V_49 ;
break;
case V_106 :
case V_107 :
if ( ! F_137 ( NULL , V_49 ) )
{
F_9 ( V_98 , L_143 , V_49 ) ;
return NULL ;
}
V_185 = V_49 ;
if ( V_47 == V_106 )
V_186 = L_144 ;
else
V_186 = L_145 ;
break;
}
V_188 = F_90 ( NULL , 0 ) ;
V_79 = V_188 -> V_156 + 1 ;
if ( V_186 ) V_79 += strlen ( V_186 ) + 1 ;
if ( V_185 ) V_79 += strlen ( V_185 ) + 1 ;
V_168 = F_13 ( V_79 ) ;
if ( ! V_168 ) return NULL ;
F_14 ( V_168 , ( char * ) V_188 -> V_133 , V_79 ) ;
if ( V_186 )
{
F_15 ( V_168 , L_146 , V_79 ) ;
F_15 ( V_168 , V_186 , V_79 ) ;
}
if ( V_185 )
{
F_15 ( V_168 , L_146 , V_79 ) ;
F_15 ( V_168 , V_185 , V_79 ) ;
}
F_134 ( V_188 ) ;
return V_168 ;
}
int F_50 ( T_8 * V_190 , const char * V_168 )
{
char * V_191 = NULL ;
int V_192 = - 1 ;
int V_79 , V_11 = 0 ;
T_17 * V_193 = NULL ;
T_18 * V_194 = NULL ;
T_19 * V_195 = NULL ;
T_9 * V_196 = NULL ;
V_79 = F_138 ( & V_196 , & V_192 , & V_193 , & V_194 , V_168 ) ;
if ( V_79 == 0 )
goto V_110;
if ( V_190 && ! F_139 ( V_190 , V_196 ) )
goto V_110;
if ( V_190 && ( V_192 != V_197 ) )
{
V_195 = F_140 () ;
if ( ! V_195 || ! F_141 ( V_195 , V_192 ) )
goto V_110;
if ( ! F_142 ( V_190 , V_198 , V_195 , 0 , 0 ) )
goto V_110;
}
if ( V_190 && V_194 )
{
if ( ! F_142 ( V_190 , V_199 , V_194 , 0 , 0 ) )
goto V_110;
}
if ( V_190 && V_193 )
{
if ( ! F_142 ( V_190 , V_200 , V_193 , 0 , 0 ) )
goto V_110;
}
if ( V_192 != V_197 )
V_11 = 2 ;
else V_11 = 1 ;
V_110:
if ( V_191 ) F_18 ( V_191 ) ;
F_136 ( V_193 ) ;
F_143 ( V_194 ) ;
F_144 ( V_195 ) ;
F_94 ( V_196 ) ;
return V_11 ;
}
int F_145 ( T_5 * V_167 , T_17 * V_201 , T_20 * V_168 )
{
char V_86 [ 25 ] , * V_202 , * V_77 ;
int V_80 ;
V_80 = F_146 ( V_167 , V_201 ) ;
V_202 = V_86 ;
for ( V_80 = 22 - V_80 ; V_80 > 0 ; V_80 -- )
* ( V_202 ++ ) = ' ' ;
* ( V_202 ++ ) = ':' ;
* ( V_202 ++ ) = '\0' ;
F_60 ( V_167 , V_86 ) ;
if ( V_168 -> type == V_203 )
F_9 ( V_167 , L_147 ) ;
else if ( V_168 -> type == V_204 )
F_9 ( V_167 , L_148 ) ;
else if ( V_168 -> type == V_205 )
F_9 ( V_167 , L_149 ) ;
else if ( V_168 -> type == V_206 )
F_9 ( V_167 , L_150 ) ;
else
F_9 ( V_167 , L_151 , V_168 -> type ) ;
V_77 = ( char * ) V_168 -> V_133 ;
for ( V_80 = V_168 -> V_156 ; V_80 > 0 ; V_80 -- )
{
if ( ( * V_77 >= ' ' ) && ( * V_77 <= '~' ) )
F_9 ( V_167 , L_152 , * V_77 ) ;
else if ( * V_77 & 0x80 )
F_9 ( V_167 , L_153 , * V_77 ) ;
else if ( ( unsigned char ) * V_77 == 0xf7 )
F_9 ( V_167 , L_154 ) ;
else F_9 ( V_167 , L_155 , * V_77 + '@' ) ;
V_77 ++ ;
}
F_9 ( V_167 , L_156 ) ;
return 1 ;
}
int F_138 ( T_9 * * V_207 , int * V_208 , T_17 * * V_209 , T_18 * * V_210 , const char * V_168 )
{
char * V_191 = NULL ;
char * V_211 , * V_212 = NULL , * V_213 = NULL , * V_77 ;
int V_192 = - 1 ;
int V_11 = 0 ;
unsigned int V_79 ;
T_17 * V_193 = NULL ;
T_18 * V_194 = NULL ;
V_191 = F_127 ( V_168 ) ;
V_77 = strchr ( V_191 , ',' ) ;
V_211 = V_191 ;
if ( V_77 )
{
* V_77 = '\0' ;
V_77 ++ ;
V_212 = V_77 ;
V_77 = strchr ( V_77 , ',' ) ;
if ( V_77 )
{
* V_77 = '\0' ;
V_213 = V_77 + 1 ;
}
}
if ( V_207 )
{
* V_207 = F_133 () ;
if ( ! F_147 ( * V_207 , V_211 ) )
{
F_9 ( V_98 , L_157 , V_211 ) ;
goto V_110;
}
}
if ( V_212 )
{
for ( V_79 = 0 ; V_79 < V_214 ; V_79 ++ )
{
if( ! strcasecmp ( V_212 , V_189 [ V_79 ] ) )
{
V_192 = V_79 ;
break;
}
}
if ( V_192 == V_197 )
{
F_9 ( V_98 , L_158 , V_212 ) ;
goto V_110;
}
if ( V_192 == 7 )
V_192 = V_215 ;
else if ( V_192 == 8 )
{
if ( ! V_213 )
{
F_9 ( V_98 , L_159 ) ;
goto V_110;
}
V_192 = V_216 ;
V_193 = F_135 ( V_213 , 0 ) ;
if ( ! V_193 )
{
F_9 ( V_98 , L_160 , V_213 ) ;
goto V_110;
}
if ( V_209 ) * V_209 = V_193 ;
}
else if ( ( V_192 == 9 ) || ( V_192 == 10 ) )
{
if ( ! V_213 )
{
F_9 ( V_98 , L_161 ) ;
goto V_110;
}
V_194 = F_148 () ;
if ( ! F_137 ( V_194 , V_213 ) )
{
F_9 ( V_98 , L_162 , V_213 ) ;
goto V_110;
}
if ( V_192 == 9 )
V_192 = V_217 ;
else
V_192 = V_218 ;
}
}
if ( V_208 ) * V_208 = V_192 ;
if ( V_210 ) * V_210 = V_194 ;
else F_143 ( V_194 ) ;
V_11 = 1 ;
V_110:
if ( V_191 ) F_18 ( V_191 ) ;
if ( ! V_209 ) F_136 ( V_193 ) ;
if ( ! V_210 ) F_143 ( V_194 ) ;
return V_11 ;
}
