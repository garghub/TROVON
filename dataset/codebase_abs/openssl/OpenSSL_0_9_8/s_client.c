static void F_1 ( void )
{
F_2 ( V_1 , L_1 ) ;
F_2 ( V_1 , L_2 ) ;
F_2 ( V_1 , L_3 ) ;
F_2 ( V_1 , L_4 ) ;
F_2 ( V_1 , L_5 , V_2 , V_3 ) ;
F_2 ( V_1 , L_6 ) ;
F_2 ( V_1 , L_7 ) ;
F_2 ( V_1 , L_8 ) ;
F_2 ( V_1 , L_9 ) ;
F_2 ( V_1 , L_10 ) ;
F_2 ( V_1 , L_11 ) ;
F_2 ( V_1 , L_12 ) ;
F_2 ( V_1 , L_13 ) ;
F_2 ( V_1 , L_14 ) ;
F_2 ( V_1 , L_15 ) ;
F_2 ( V_1 , L_16 ) ;
F_2 ( V_1 , L_17 ) ;
F_2 ( V_1 , L_18 ) ;
#ifdef F_3
F_2 ( V_1 , L_19 ) ;
#endif
F_2 ( V_1 , L_20 ) ;
F_2 ( V_1 , L_21 ) ;
F_2 ( V_1 , L_22 ) ;
#ifdef F_4
F_2 ( V_1 , L_23 ) ;
#endif
F_2 ( V_1 , L_24 ) ;
F_2 ( V_1 , L_25 ) ;
F_2 ( V_1 , L_26 ) ;
F_2 ( V_1 , L_27 ) ;
F_2 ( V_1 , L_28 ) ;
F_2 ( V_1 , L_29 ) ;
F_2 ( V_1 , L_30 ) ;
F_2 ( V_1 , L_31 ) ;
F_2 ( V_1 , L_32 ) ;
F_2 ( V_1 , L_33 ) ;
F_2 ( V_1 , L_34 ) ;
F_2 ( V_1 , L_35 ) ;
F_2 ( V_1 , L_36 ) ;
F_2 ( V_1 , L_37 ) ;
F_2 ( V_1 , L_38 ) ;
F_2 ( V_1 , L_39 ) ;
F_2 ( V_1 , L_40 ) ;
#ifndef F_5
F_2 ( V_1 , L_41 ) ;
#endif
F_2 ( V_1 , L_42 , V_4 , V_4 ) ;
}
int MAIN ( int V_5 , char * * V_6 )
{
int V_7 = 0 ;
T_1 * V_8 = NULL , * V_9 = NULL ;
T_2 * V_10 = NULL ;
int V_11 , V_12 , V_13 , V_14 = 0 ;
char * V_15 = NULL , * V_16 = NULL , * V_17 = NULL ;
int V_18 , V_19 ;
int V_20 , V_21 ;
T_3 V_22 , V_23 ;
short V_24 = V_25 ;
int V_26 = 1 ;
char * V_27 = V_2 ;
char * V_28 = NULL , * V_29 = NULL ;
int V_30 = V_31 , V_32 = V_31 ;
char * V_33 = NULL , * V_34 = NULL ;
T_4 * V_35 = NULL ;
T_5 * V_36 = NULL ;
char * V_37 = NULL , * V_38 = NULL , * V_39 = NULL ;
int V_40 = 0 , V_41 = 0 , V_42 = V_43 , V_44 = 0 ;
int V_45 = 0 ;
int V_46 , V_47 , V_48 , V_49 , V_50 , V_51 ;
T_6 * V_52 = NULL ;
int V_53 = 1 , V_54 = 1 , V_55 , V_56 = 0 ;
int V_57 = 0 ;
int V_58 = 0 , V_59 = 0 ;
T_7 * V_60 = NULL ;
#ifdef F_6
#undef F_6
#endif
int F_6 = V_61 ;
T_8 * V_62 ;
char * V_63 = NULL ;
#ifndef F_5
char * V_64 = NULL ;
T_9 * V_65 = NULL ;
#endif
#if F_7 ( V_66 ) || F_7 ( V_67 ) || F_7 ( V_68 )
struct V_69 V_70 ;
#endif
struct V_71 V_72 ;
int V_73 = sizeof( V_72 ) ;
int V_74 = 0 ;
long V_75 = 0 ;
#if ! F_7 ( V_76 ) && ! F_7 ( V_77 )
V_60 = F_8 () ;
#elif ! F_7 ( V_77 )
V_60 = F_9 () ;
#elif ! F_7 ( V_76 )
V_60 = F_10 () ;
#endif
F_11 () ;
V_78 = 0 ;
V_79 = 0 ;
V_80 = 0 ;
V_81 = 0 ;
V_82 = 0 ;
V_83 = 0 ;
if ( V_1 == NULL )
V_1 = F_12 ( V_84 , V_85 ) ;
if ( ! F_13 ( V_1 , NULL ) )
goto V_86;
if ( ( ( V_15 = F_14 ( V_87 ) ) == NULL ) ||
( ( V_16 = F_14 ( V_87 ) ) == NULL ) ||
( ( V_17 = F_14 ( V_87 ) ) == NULL ) )
{
F_2 ( V_1 , L_43 ) ;
goto V_86;
}
V_88 = 0 ;
V_89 = V_90 ;
#ifdef F_4
V_91 = 0 ;
#endif
V_5 -- ;
V_6 ++ ;
while ( V_5 >= 1 )
{
if ( strcmp ( * V_6 , L_44 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_27 = * ( ++ V_6 ) ;
}
else if ( strcmp ( * V_6 , L_45 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_24 = atoi ( * ( ++ V_6 ) ) ;
if ( V_24 == 0 ) goto V_92;
}
else if ( strcmp ( * V_6 , L_46 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
if ( ! F_15 ( * ( ++ V_6 ) , & V_27 , NULL , & V_24 ) )
goto V_92;
}
else if ( strcmp ( * V_6 , L_47 ) == 0 )
{
V_42 = V_93 ;
if ( -- V_5 < 1 ) goto V_92;
V_88 = atoi ( * ( ++ V_6 ) ) ;
F_2 ( V_1 , L_48 , V_88 ) ;
}
else if ( strcmp ( * V_6 , L_49 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_28 = * ( ++ V_6 ) ;
}
else if ( strcmp ( * V_6 , L_50 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_30 = F_16 ( * ( ++ V_6 ) ) ;
}
else if ( strcmp ( * V_6 , L_51 ) == 0 )
V_59 |= V_94 ;
else if ( strcmp ( * V_6 , L_52 ) == 0 )
V_59 |= V_94 | V_95 ;
else if ( strcmp ( * V_6 , L_53 ) == 0 )
V_58 = 1 ;
else if ( strcmp ( * V_6 , L_54 ) == 0 )
V_45 = 1 ;
else if ( strcmp ( * V_6 , L_55 ) == 0 )
{
V_79 = 1 ;
V_80 = 1 ;
}
else if ( strcmp ( * V_6 , L_56 ) == 0 )
V_80 = 1 ;
else if ( strcmp ( * V_6 , L_57 ) == 0 )
V_78 = 1 ;
else if ( strcmp ( * V_6 , L_58 ) == 0 )
V_81 = 1 ;
#ifdef F_3
else if ( strcmp ( * V_6 , L_59 ) == 0 )
F_17 () ;
#endif
else if ( strcmp ( * V_6 , L_60 ) == 0 )
V_82 = 1 ;
else if ( strcmp ( * V_6 , L_61 ) == 0 )
V_83 = 1 ;
else if ( strcmp ( * V_6 , L_62 ) == 0 )
V_56 = 1 ;
else if ( strcmp ( * V_6 , L_63 ) == 0 )
V_14 = 1 ;
#ifndef V_76
else if ( strcmp ( * V_6 , L_64 ) == 0 )
V_60 = F_10 () ;
#endif
#ifndef V_77
else if ( strcmp ( * V_6 , L_65 ) == 0 )
V_60 = F_9 () ;
#endif
#ifndef F_18
else if ( strcmp ( * V_6 , L_66 ) == 0 )
V_60 = F_19 () ;
#endif
#ifndef F_20
else if ( strcmp ( * V_6 , L_67 ) == 0 )
{
V_60 = F_21 () ;
F_6 = V_96 ;
}
else if ( strcmp ( * V_6 , L_68 ) == 0 )
V_74 = 1 ;
else if ( strcmp ( * V_6 , L_69 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_75 = atol ( * ( ++ V_6 ) ) ;
}
#endif
else if ( strcmp ( * V_6 , L_70 ) == 0 )
V_44 = 1 ;
else if ( strcmp ( * V_6 , L_71 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_32 = F_16 ( * ( ++ V_6 ) ) ;
}
else if ( strcmp ( * V_6 , L_72 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_33 = * ( ++ V_6 ) ;
}
else if ( strcmp ( * V_6 , L_73 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_29 = * ( ++ V_6 ) ;
}
else if ( strcmp ( * V_6 , L_74 ) == 0 )
{
V_40 = 5 ;
}
else if ( strcmp ( * V_6 , L_75 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_37 = * ( ++ V_6 ) ;
}
else if ( strcmp ( * V_6 , L_76 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_38 = * ( ++ V_6 ) ;
}
else if ( strcmp ( * V_6 , L_77 ) == 0 )
V_7 |= V_97 ;
else if ( strcmp ( * V_6 , L_78 ) == 0 )
V_7 |= V_98 ;
else if ( strcmp ( * V_6 , L_79 ) == 0 )
V_7 |= V_99 ;
else if ( strcmp ( * V_6 , L_80 ) == 0 )
V_7 |= V_100 ;
else if ( strcmp ( * V_6 , L_81 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_39 = * ( ++ V_6 ) ;
}
#ifdef F_4
else if ( strcmp ( * V_6 , L_82 ) == 0 )
{ V_91 = 1 ; }
#endif
else if ( strcmp ( * V_6 , L_83 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
++ V_6 ;
if ( strcmp ( * V_6 , L_84 ) == 0 )
V_57 = 1 ;
else if ( strcmp ( * V_6 , L_85 ) == 0 )
V_57 = 2 ;
else
goto V_92;
}
#ifndef F_5
else if ( strcmp ( * V_6 , L_86 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_64 = * ( ++ V_6 ) ;
}
#endif
else if ( strcmp ( * V_6 , L_87 ) == 0 )
{
if ( -- V_5 < 1 ) goto V_92;
V_63 = * ( ++ V_6 ) ;
}
else
{
F_2 ( V_1 , L_88 , * V_6 ) ;
V_41 = 1 ;
break;
}
V_5 -- ;
V_6 ++ ;
}
if ( V_41 )
{
V_92:
F_1 () ;
goto V_86;
}
F_22 () ;
F_23 () ;
#ifndef F_5
V_65 = F_24 ( V_1 , V_64 , 1 ) ;
#endif
if ( ! F_25 ( V_1 , V_33 , NULL , & V_34 , NULL ) )
{
F_2 ( V_1 , L_89 ) ;
goto V_86;
}
if ( V_29 == NULL )
V_29 = V_28 ;
if ( V_29 )
{
V_36 = F_26 ( V_1 , V_29 , V_32 , 0 , V_34 , V_65 ,
L_90 ) ;
if ( ! V_36 )
{
F_27 ( V_1 ) ;
goto V_86;
}
}
if ( V_28 )
{
V_35 = F_28 ( V_1 , V_28 , V_30 ,
NULL , V_65 , L_91 ) ;
if ( ! V_35 )
{
F_27 ( V_1 ) ;
goto V_86;
}
}
if ( ! F_29 ( NULL , V_1 , 1 ) && V_63 == NULL
&& ! F_30 () )
{
F_2 ( V_1 , L_92 ) ;
}
if ( V_63 != NULL )
F_2 ( V_1 , L_93 ,
F_31 ( V_63 ) ) ;
if ( V_101 == NULL )
{
if ( V_79 && ! V_81 && ! V_82 )
{
V_101 = F_32 ( F_33 () ) ;
}
else
{
if ( V_101 == NULL )
V_101 = F_12 ( stdout , V_85 ) ;
}
}
V_52 = F_34 ( V_60 ) ;
if ( V_52 == NULL )
{
F_27 ( V_1 ) ;
goto V_86;
}
if ( V_44 )
F_35 ( V_52 , V_102 | V_7 ) ;
else
F_35 ( V_52 , V_7 ) ;
if ( F_6 == V_96 ) F_36 ( V_52 , 1 ) ;
if ( V_14 ) F_37 ( V_52 , V_103 ) ;
if ( V_39 != NULL )
if( ! F_38 ( V_52 , V_39 ) ) {
F_2 ( V_1 , L_94 ) ;
F_27 ( V_1 ) ;
goto V_86;
}
#if 0
else
SSL_CTX_set_cipher_list(ctx,getenv("SSL_CIPHER"));
#endif
F_39 ( V_52 , V_42 , V_104 ) ;
if ( ! F_40 ( V_52 , V_35 , V_36 ) )
goto V_86;
if ( ( ! F_41 ( V_52 , V_38 , V_37 ) ) ||
( ! F_42 ( V_52 ) ) )
{
F_27 ( V_1 ) ;
}
V_10 = F_43 ( V_52 ) ;
F_44 ( V_10 , V_59 ) ;
V_8 = F_45 ( V_52 ) ;
#ifndef F_46
if ( V_8 && ( V_8 -> V_105 = F_47 () ) != NULL )
{
F_48 ( V_8 -> V_105 , V_106 , V_27 ) ;
}
#endif
V_107:
if ( F_49 ( & V_11 , V_27 , V_24 , F_6 ) == 0 )
{
F_2 ( V_1 , L_95 , F_50 () ) ;
F_51 ( V_11 ) ;
goto V_86;
}
F_2 ( V_101 , L_96 , V_11 ) ;
#ifdef F_4
if ( V_91 )
{
unsigned long V_108 = 1 ;
F_2 ( V_101 , L_97 ) ;
if ( F_52 ( V_11 , F_4 , & V_108 ) < 0 )
{
F_27 ( V_1 ) ;
goto V_86;
}
}
#endif
if ( V_78 & 0x01 ) V_8 -> V_109 = 1 ;
if ( F_53 ( V_8 ) == V_110 )
{
struct V_69 V_111 ;
V_62 = F_54 ( V_11 , V_85 ) ;
if ( F_55 ( V_11 , & V_72 , ( void * ) & V_73 ) < 0 )
{
F_2 ( V_1 , L_98 ,
F_50 () ) ;
F_51 ( V_11 ) ;
goto V_86;
}
F_56 ( V_62 , 1 , & V_72 ) ;
if ( V_74 )
{
V_111 . V_112 = 0 ;
V_111 . V_113 = V_114 ;
F_57 ( V_62 , V_115 , 0 , & V_111 ) ;
V_111 . V_112 = 0 ;
V_111 . V_113 = V_116 ;
F_57 ( V_62 , V_117 , 0 , & V_111 ) ;
}
if ( V_75 > 0 )
{
F_58 ( V_8 , V_118 ) ;
F_59 ( V_8 , V_75 ) ;
}
else
F_57 ( V_62 , V_119 , 0 , NULL ) ;
}
else
V_62 = F_60 ( V_11 , V_85 ) ;
if ( V_56 )
{
T_8 * V_120 ;
V_120 = F_32 ( F_61 () ) ;
V_62 = F_62 ( V_120 , V_62 ) ;
}
if ( V_81 )
{
V_8 -> V_109 = 1 ;
F_63 ( V_62 , V_121 ) ;
F_64 ( V_62 , V_101 ) ;
}
if ( V_82 )
{
F_65 ( V_8 , V_122 ) ;
F_66 ( V_8 , V_101 ) ;
}
F_67 ( V_8 , V_62 , V_62 ) ;
F_68 ( V_8 ) ;
V_13 = F_69 ( V_8 ) + 1 ;
V_47 = 1 ;
V_46 = 0 ;
V_50 = 0 ;
V_49 = 1 ;
V_48 = 1 ;
V_18 = 0 ;
V_19 = 0 ;
V_20 = 0 ;
V_21 = 0 ;
if ( V_57 == 1 )
{
F_70 ( V_62 , V_17 , V_87 ) ;
F_2 ( V_62 , L_99 ) ;
F_70 ( V_62 , V_16 , V_87 ) ;
}
if ( V_57 == 2 )
{
F_70 ( V_62 , V_17 , V_87 ) ;
F_2 ( V_62 , L_100 ) ;
F_70 ( V_62 , V_16 , V_87 ) ;
}
for (; ; )
{
F_71 ( & V_22 ) ;
F_71 ( & V_23 ) ;
if ( F_72 ( V_8 ) && ! F_73 ( V_8 ) )
{
V_54 = 1 ;
V_50 = 0 ;
}
else
{
V_50 = 1 ;
if ( V_54 )
{
V_54 = 0 ;
F_74 ( V_101 , V_8 , V_26 ) ;
if ( V_26 > 0 ) V_26 -- ;
if ( V_57 )
{
F_2 ( V_1 , L_101 , V_17 ) ;
V_57 = 0 ;
}
if ( V_40 )
{
V_40 -- ;
F_2 ( V_101 , L_102 ) ;
F_75 ( V_8 ) ;
F_68 ( V_8 ) ;
F_51 ( F_69 ( V_8 ) ) ;
goto V_107;
}
}
}
V_51 = V_49 && F_76 ( V_8 ) ;
if ( ! V_51 )
{
#if ! F_7 ( V_66 ) && ! F_7 ( V_67 ) && ! F_7 ( V_68 )
if ( V_50 )
{
if ( V_47 ) F_77 ( fileno ( V_123 ) , & V_22 ) ;
if ( V_46 ) F_77 ( fileno ( stdout ) , & V_23 ) ;
}
if ( V_49 )
F_77 ( F_69 ( V_8 ) , & V_22 ) ;
if ( V_48 )
F_77 ( F_69 ( V_8 ) , & V_23 ) ;
#else
if( ! V_50 || ! V_46 ) {
if ( V_49 )
F_77 ( F_69 ( V_8 ) , & V_22 ) ;
if ( V_48 )
F_77 ( F_69 ( V_8 ) , & V_23 ) ;
}
#endif
#if F_7 ( V_66 ) || F_7 ( V_67 )
V_55 = 0 ;
if( ! V_46 ) {
if( V_47 ) {
V_70 . V_112 = 1 ;
V_70 . V_113 = 0 ;
V_55 = F_78 ( V_13 , ( void * ) & V_22 , ( void * ) & V_23 ,
NULL , & V_70 ) ;
#if F_7 ( V_124 ) || F_7 ( V_67 )
if( ! V_55 && ( ! F_79 () || ! V_47 ) ) continue;
#else
if( ! V_55 && ( ! ( ( F_79 () ) || ( V_125 == F_80 ( F_81 ( V_126 ) , 0 ) ) ) || ! V_47 ) ) continue;
#endif
} else V_55 = F_78 ( V_13 , ( void * ) & V_22 , ( void * ) & V_23 ,
NULL , NULL ) ;
}
#elif F_7 ( V_68 )
if( ! V_46 ) {
if( V_47 ) {
V_70 . V_112 = 1 ;
V_70 . V_113 = 0 ;
V_55 = F_78 ( V_13 , ( void * ) & V_22 , ( void * ) & V_23 ,
NULL , & V_70 ) ;
} else V_55 = F_78 ( V_13 , ( void * ) & V_22 , ( void * ) & V_23 ,
NULL , NULL ) ;
}
#else
V_55 = F_78 ( V_13 , ( void * ) & V_22 , ( void * ) & V_23 ,
NULL , NULL ) ;
#endif
if ( V_55 < 0 )
{
F_2 ( V_1 , L_103 ,
F_50 () ) ;
goto V_127;
}
}
if ( ! V_51 && F_82 ( F_69 ( V_8 ) , & V_23 ) )
{
V_12 = F_83 ( V_8 , & ( V_15 [ V_19 ] ) ,
( unsigned int ) V_18 ) ;
switch ( F_84 ( V_8 , V_12 ) )
{
case V_128 :
V_19 += V_12 ;
V_18 -= V_12 ;
if ( V_12 <= 0 ) goto V_86;
if ( V_18 <= 0 )
{
V_47 = 1 ;
V_48 = 0 ;
}
else
{
V_47 = 0 ;
V_48 = 1 ;
}
break;
case V_129 :
F_2 ( V_101 , L_104 ) ;
V_48 = 1 ;
V_47 = 0 ;
break;
case V_130 :
F_2 ( V_101 , L_105 ) ;
V_46 = 0 ;
V_49 = 1 ;
V_48 = 0 ;
break;
case V_131 :
F_2 ( V_101 , L_106 ) ;
break;
case V_132 :
if ( V_18 != 0 )
{
F_2 ( V_101 , L_107 ) ;
goto V_127;
}
else
{
V_47 = 1 ;
V_48 = 0 ;
break;
}
case V_133 :
if ( ( V_12 != 0 ) || ( V_18 != 0 ) )
{
F_2 ( V_1 , L_108 ,
F_50 () ) ;
goto V_127;
}
else
{
V_47 = 1 ;
V_48 = 0 ;
}
break;
case V_134 :
F_27 ( V_1 ) ;
goto V_127;
}
}
#if F_7 ( V_66 ) || F_7 ( V_67 ) || F_7 ( V_68 )
else if ( ! V_51 && V_46 )
#else
else if ( ! V_51 && F_82 ( fileno ( stdout ) , & V_23 ) )
#endif
{
#ifdef F_85
F_86 ( & ( V_16 [ V_21 ] ) , & ( V_16 [ V_21 ] ) , V_20 ) ;
#endif
V_55 = F_87 ( fileno ( stdout ) , & ( V_16 [ V_21 ] ) , V_20 ) ;
if ( V_55 <= 0 )
{
F_2 ( V_101 , L_109 ) ;
goto V_127;
}
V_20 -= V_55 ; ;
V_21 += V_55 ;
if ( V_20 <= 0 )
{
V_49 = 1 ;
V_46 = 0 ;
}
}
else if ( V_51 || F_82 ( F_69 ( V_8 ) , & V_22 ) )
{
#ifdef F_88
{ static int V_135 ; if ( ++ V_135 == 52 ) { F_89 ( V_8 ) ; V_135 = 0 ; } }
#endif
#if 1
V_12 = F_90 ( V_8 , V_16 , 1024 ) ;
#else
V_12 = F_90 ( V_8 , V_16 , 16 ) ;
{ char V_136 [ 10240 ] ;
printf ( L_110 , V_12 , F_76 ( V_8 ) , F_91 ( V_8 , V_136 , 10240 ) ) ;
}
#endif
switch ( F_84 ( V_8 , V_12 ) )
{
case V_128 :
if ( V_12 <= 0 )
goto V_86;
V_21 = 0 ;
V_20 = V_12 ;
V_49 = 0 ;
V_46 = 1 ;
break;
case V_129 :
F_2 ( V_101 , L_111 ) ;
V_48 = 1 ;
V_47 = 0 ;
break;
case V_130 :
F_2 ( V_101 , L_112 ) ;
V_46 = 0 ;
V_49 = 1 ;
if ( ( V_47 == 0 ) && ( V_48 == 0 ) )
V_48 = 1 ;
break;
case V_131 :
F_2 ( V_101 , L_113 ) ;
break;
case V_133 :
F_2 ( V_1 , L_114 , F_50 () ) ;
goto V_127;
case V_132 :
F_2 ( V_101 , L_115 ) ;
goto V_127;
case V_134 :
F_27 ( V_1 ) ;
goto V_127;
}
}
#if F_7 ( V_66 ) || F_7 ( V_67 )
#if F_7 ( V_124 ) || F_7 ( V_67 )
else if ( F_79 () )
#else
else if ( ( F_79 () ) || ( V_125 == F_80 ( F_81 ( V_126 ) , 0 ) ) )
#endif
#elif F_7 ( V_68 )
else if ( F_79 () )
#else
else if ( F_82 ( fileno ( V_123 ) , & V_22 ) )
#endif
{
if ( V_45 )
{
int V_137 , V_138 ;
V_55 = F_92 ( fileno ( V_123 ) , V_15 , V_87 / 2 ) ;
V_138 = 0 ;
for ( V_137 = 0 ; V_137 < V_55 ; V_137 ++ )
if ( V_15 [ V_137 ] == '\n' )
V_138 ++ ;
for ( V_137 = V_55 - 1 ; V_137 >= 0 ; V_137 -- )
{
V_15 [ V_137 + V_138 ] = V_15 [ V_137 ] ;
if ( V_15 [ V_137 ] == '\n' )
{
V_138 -- ;
V_55 ++ ;
V_15 [ V_137 + V_138 ] = '\r' ;
}
}
assert ( V_138 == 0 ) ;
}
else
V_55 = F_92 ( fileno ( V_123 ) , V_15 , V_87 ) ;
if ( ( ! V_80 ) && ( ( V_55 <= 0 ) || ( V_15 [ 0 ] == 'Q' ) ) )
{
F_2 ( V_1 , L_109 ) ;
goto V_127;
}
if ( ( ! V_80 ) && ( V_15 [ 0 ] == 'R' ) )
{
F_2 ( V_1 , L_116 ) ;
F_89 ( V_8 ) ;
V_18 = 0 ;
}
else
{
V_18 = V_55 ;
V_19 = 0 ;
#ifdef F_85
F_93 ( V_15 , V_15 , V_55 ) ;
#endif
}
V_48 = 1 ;
V_47 = 0 ;
}
}
V_127:
F_75 ( V_8 ) ;
F_51 ( F_69 ( V_8 ) ) ;
V_53 = 0 ;
V_86:
if( V_58 ) F_74 ( V_101 , V_8 , 1 ) ;
if ( V_8 != NULL ) F_94 ( V_8 ) ;
if ( V_9 != NULL ) F_94 ( V_9 ) ;
if ( V_52 != NULL ) F_95 ( V_52 ) ;
if ( V_35 )
F_96 ( V_35 ) ;
if ( V_36 )
F_97 ( V_36 ) ;
if ( V_34 )
F_98 ( V_34 ) ;
if ( V_15 != NULL ) { F_99 ( V_15 , V_87 ) ; F_98 ( V_15 ) ; }
if ( V_16 != NULL ) { F_99 ( V_16 , V_87 ) ; F_98 ( V_16 ) ; }
if ( V_17 != NULL ) { F_99 ( V_17 , V_87 ) ; F_98 ( V_17 ) ; }
if ( V_101 != NULL )
{
F_100 ( V_101 ) ;
V_101 = NULL ;
}
F_101 () ;
F_102 ( V_53 ) ;
}
static void F_74 ( T_8 * V_139 , T_1 * V_11 , int V_140 )
{
T_4 * V_72 = NULL ;
char * V_141 ;
static const char * V_142 = L_117 ;
char V_143 [ V_144 ] ;
F_103 ( T_4 ) * V_145 ;
F_103 ( V_146 ) * V_147 ;
T_10 * V_148 ;
V_146 * V_149 ;
int V_137 , V_55 ;
const T_11 * V_150 , * V_151 ;
if ( V_140 )
{
int V_152 = 0 ;
V_145 = F_104 ( V_11 ) ;
if ( V_145 != NULL )
{
V_152 = 1 ;
F_2 ( V_139 , L_118 ) ;
for ( V_55 = 0 ; V_55 < F_105 ( V_145 ) ; V_55 ++ )
{
F_106 ( F_107 (
F_108 ( V_145 , V_55 ) ) , V_143 , sizeof V_143 ) ;
F_2 ( V_139 , L_119 , V_55 , V_143 ) ;
F_106 ( F_109 (
F_108 ( V_145 , V_55 ) ) , V_143 , sizeof V_143 ) ;
F_2 ( V_139 , L_120 , V_143 ) ;
if ( V_83 )
F_110 ( V_139 , F_108 ( V_145 , V_55 ) ) ;
}
}
F_2 ( V_139 , L_121 ) ;
V_72 = F_111 ( V_11 ) ;
if ( V_72 != NULL )
{
F_2 ( V_139 , L_122 ) ;
if ( ! ( V_83 && V_152 ) )
F_110 ( V_139 , V_72 ) ;
F_106 ( F_107 ( V_72 ) ,
V_143 , sizeof V_143 ) ;
F_2 ( V_139 , L_123 , V_143 ) ;
F_106 ( F_109 ( V_72 ) ,
V_143 , sizeof V_143 ) ;
F_2 ( V_139 , L_124 , V_143 ) ;
}
else
F_2 ( V_139 , L_125 ) ;
V_147 = F_112 ( V_11 ) ;
if ( ( V_147 != NULL ) && ( F_113 ( V_147 ) > 0 ) )
{
F_2 ( V_139 , L_126 ) ;
for ( V_55 = 0 ; V_55 < F_113 ( V_147 ) ; V_55 ++ )
{
V_149 = F_114 ( V_147 , V_55 ) ;
F_106 ( V_149 , V_143 , sizeof( V_143 ) ) ;
F_115 ( V_139 , V_143 , strlen ( V_143 ) ) ;
F_115 ( V_139 , L_2 , 1 ) ;
}
}
else
{
F_2 ( V_139 , L_127 ) ;
}
V_141 = F_116 ( V_11 , V_143 , sizeof V_143 ) ;
if ( V_141 != NULL )
{
F_2 ( V_139 , L_128 ) ;
V_137 = V_55 = 0 ;
while ( * V_141 )
{
if ( * V_141 == ':' )
{
F_115 ( V_139 , V_142 , 15 - V_137 % 25 ) ;
V_55 ++ ;
V_137 = 0 ;
F_115 ( V_139 , ( ( V_55 % 3 ) ? L_129 : L_2 ) , 1 ) ;
}
else
{
F_115 ( V_139 , V_141 , 1 ) ;
V_137 ++ ;
}
V_141 ++ ;
}
F_115 ( V_139 , L_2 , 1 ) ;
}
F_2 ( V_139 , L_130 ,
F_117 ( F_118 ( V_11 ) ) ,
F_119 ( F_120 ( V_11 ) ) ) ;
}
F_2 ( V_139 , ( ( V_11 -> V_153 ) ? L_131 : L_132 ) ) ;
V_148 = F_121 ( V_11 ) ;
F_2 ( V_139 , L_133 ,
F_122 ( V_148 ) ,
F_123 ( V_148 ) ) ;
if ( V_72 != NULL ) {
T_5 * V_154 ;
V_154 = F_124 ( V_72 ) ;
F_2 ( V_139 , L_134 ,
F_125 ( V_154 ) ) ;
F_97 ( V_154 ) ;
}
V_150 = F_126 ( V_11 ) ;
V_151 = F_127 ( V_11 ) ;
F_2 ( V_139 , L_135 ,
V_150 ? F_128 ( V_150 ) : L_136 ) ;
F_2 ( V_139 , L_137 ,
V_151 ? F_128 ( V_151 ) : L_136 ) ;
F_129 ( V_139 , F_130 ( V_11 ) ) ;
F_2 ( V_139 , L_121 ) ;
if ( V_72 != NULL )
F_96 ( V_72 ) ;
F_131 ( V_139 ) ;
}
