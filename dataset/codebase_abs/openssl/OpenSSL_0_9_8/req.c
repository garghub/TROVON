int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
#ifndef F_1
T_2 * V_4 = NULL ;
#endif
#ifndef F_2
T_3 * V_5 = NULL ;
#endif
unsigned long V_6 = 0 , V_7 = 0 ;
int V_8 = 1 , V_9 = 0 , V_10 = 30 ;
T_4 * V_11 = NULL ;
T_5 * V_12 = NULL ;
T_6 * V_13 = NULL ;
int V_14 = 0 , V_15 = 0 , V_16 = 0 , V_17 = 0 , V_18 = V_19 ;
long V_20 = - 1 ;
T_7 * V_21 = NULL , * V_22 = NULL ;
int V_23 , V_24 , V_25 = 0 , V_26 = 0 , V_27 = 0 , V_28 = V_29 ;
int V_30 = 0 , V_31 = 0 , V_32 = 0 , V_33 = 0 , V_34 = 0 ;
char * V_35 , * V_36 , * V_37 , * V_38 = NULL , * V_39 = NULL , * V_40 = NULL ;
#ifndef F_3
char * V_41 = NULL ;
#endif
char * V_42 = NULL ;
char * V_43 = NULL ;
const T_8 * V_44 = NULL ;
T_9 * V_45 = NULL ;
int V_46 = 0 ;
char * V_47 = NULL ;
char * V_48 = NULL , * V_49 = NULL ;
char * V_50 = NULL , * V_51 = NULL ;
char * V_52 ;
char * V_53 = NULL ;
int V_54 = 0 ;
const T_10 * V_55 = NULL , * V_56 = F_4 () ;
unsigned long V_57 = V_58 ;
#ifndef F_5
char * V_59 ;
long V_60 ;
#endif
V_61 = NULL ;
#ifndef F_6
V_44 = F_7 () ;
#endif
F_8 () ;
if ( V_62 == NULL )
if ( ( V_62 = F_9 ( F_10 () ) ) != NULL )
F_11 ( V_62 , V_63 , V_64 | V_65 ) ;
V_35 = NULL ;
V_36 = NULL ;
V_23 = V_29 ;
V_24 = V_29 ;
V_37 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_23 = F_12 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_24 = F_12 ( * ( ++ V_2 ) ) ;
}
#ifndef F_3
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_41 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_38 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
V_34 = 1 ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
V_16 = 1 ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_39 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_28 = F_12 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_35 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_36 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_40 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_48 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_49 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_47 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
{
int V_67 ;
if ( -- V_1 < 1 ) goto V_66;
V_52 = * ( ++ V_2 ) ;
V_67 = V_52 [ 0 ] >= '0' && V_52 [ 0 ] <= '9' ;
if ( strncmp ( L_16 , V_52 , 4 ) == 0 || V_67 )
{
V_18 = V_19 ;
if( ! V_67 )
V_52 += 4 ;
V_20 = atoi ( V_52 ) ;
}
else
#ifndef F_1
if ( strncmp ( L_17 , V_52 , 4 ) == 0 )
{
T_4 * V_68 = NULL ;
T_6 * V_69 ;
V_18 = V_70 ;
V_52 += 4 ;
if ( ( V_21 = F_13 ( V_52 , L_18 ) ) == NULL )
{
perror ( V_52 ) ;
goto V_71;
}
if ( ( V_4 = F_14 ( V_21 , NULL , NULL , NULL ) ) == NULL )
{
F_15 () ;
( void ) F_16 ( V_21 ) ;
if ( ( V_68 = F_17 ( V_21 , NULL , NULL , NULL ) ) == NULL )
{
F_18 ( V_62 , L_19 ) ;
goto V_71;
}
if ( ( V_69 = F_19 ( V_68 ) ) == NULL ) goto V_71;
if ( V_69 -> type == V_72 )
V_4 = F_20 ( V_69 -> V_13 . V_73 ) ;
F_21 ( V_69 ) ;
F_22 ( V_68 ) ;
if ( V_4 == NULL )
{
F_18 ( V_62 , L_20 ) ;
goto V_71;
}
}
F_23 ( V_21 ) ;
V_21 = NULL ;
V_20 = F_24 ( V_4 -> V_52 ) ;
}
else
#endif
#ifndef F_2
if ( strncmp ( L_21 , V_52 , 3 ) == 0 )
{
T_4 * V_68 = NULL ;
T_6 * V_69 ;
T_11 * V_74 ;
V_18 = V_75 ;
V_52 += 3 ;
if ( ( V_21 = F_13 ( V_52 , L_18 ) ) == NULL )
{
perror ( V_52 ) ;
goto V_71;
}
if ( ( V_5 = F_25 () ) == NULL )
goto V_71;
V_74 = F_26 ( V_21 , NULL , NULL , NULL ) ;
if ( V_74 == NULL )
{
F_27 ( V_5 ) ;
F_15 () ;
( void ) F_16 ( V_21 ) ;
if ( ( V_68 = F_17 ( V_21 , NULL , NULL , NULL ) ) == NULL )
{
F_18 ( V_62 , L_22 ) ;
goto V_71;
}
if ( ( V_69 = F_19 ( V_68 ) ) == NULL )
goto V_71;
if ( V_69 -> type == V_76 )
V_5 = F_28 ( V_69 -> V_13 . V_77 ) ;
F_21 ( V_69 ) ;
F_22 ( V_68 ) ;
if ( V_5 == NULL )
{
F_18 ( V_62 , L_23 ) ;
goto V_71;
}
}
else
{
if ( F_29 ( V_5 , V_74 ) == 0 )
goto V_71;
F_30 ( V_74 ) ;
}
F_23 ( V_21 ) ;
V_21 = NULL ;
V_20 = F_31 ( F_32 ( V_5 ) ) ;
}
else
#endif
#ifndef F_33
if ( strncmp ( L_24 , V_52 , 4 ) == 0 )
{
V_18 = V_78 ;
V_52 += 3 ;
}
else
#endif
{
goto V_66;
}
V_16 = 1 ;
}
else if ( strcmp ( * V_2 , L_25 ) == 0 )
V_79 = 1 ;
else if ( strcmp ( * V_2 , L_26 ) == 0 )
V_32 = 1 ;
else if ( strcmp ( * V_2 , L_27 ) == 0 )
V_46 = 1 ;
else if ( strcmp ( * V_2 , L_28 ) == 0 )
V_25 = 1 ;
else if ( strcmp ( * V_2 , L_29 ) == 0 )
V_30 = 1 ;
else if ( strcmp ( * V_2 , L_30 ) == 0 )
V_26 = 1 ;
else if ( strcmp ( * V_2 , L_31 ) == 0 )
V_17 = 1 ;
else if ( strcmp ( * V_2 , L_32 ) == 0 )
V_57 = V_80 ;
else if ( strcmp ( * V_2 , L_33 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
if ( ! F_34 ( & V_6 , * ( ++ V_2 ) ) ) goto V_66;
}
else if ( strcmp ( * V_2 , L_34 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
if ( ! F_35 ( & V_7 , * ( ++ V_2 ) ) ) goto V_66;
}
else if ( strcmp ( * V_2 , L_35 ) == 0 )
V_33 = 1 ;
else if ( strcmp ( * V_2 , L_36 ) == 0 )
V_27 = 1 ;
else if ( strcmp ( * V_2 , L_37 ) == 0 )
V_9 = 1 ;
else if ( strcmp ( * V_2 , L_38 ) == 0 )
V_31 = 1 ;
else if ( strcmp ( * V_2 , L_39 ) == 0 )
V_31 = 0 ;
else if ( strcmp ( * V_2 , L_40 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_53 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_41 ) == 0 )
V_54 = 1 ;
else if ( strcmp ( * V_2 , L_42 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_10 = atoi ( * ( ++ V_2 ) ) ;
if ( V_10 == 0 ) V_10 = 30 ;
}
else if ( strcmp ( * V_2 , L_43 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_45 = F_36 ( NULL , * ( ++ V_2 ) ) ;
if ( ! V_45 ) goto V_66;
}
else if ( ( V_55 = F_37 ( & ( ( * V_2 ) [ 1 ] ) ) ) != NULL )
{
V_56 = V_55 ;
}
else if ( strcmp ( * V_2 , L_44 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_42 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_45 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_66;
V_43 = * ( ++ V_2 ) ;
}
else
{
F_18 ( V_62 , L_46 , * V_2 ) ;
V_15 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_15 )
{
V_66:
F_18 ( V_62 , L_47 , V_37 ) ;
F_18 ( V_62 , L_48 ) ;
F_18 ( V_62 , L_49 ) ;
F_18 ( V_62 , L_50 ) ;
F_18 ( V_62 , L_51 ) ;
F_18 ( V_62 , L_52 ) ;
F_18 ( V_62 , L_53 ) ;
F_18 ( V_62 , L_54 ) ;
F_18 ( V_62 , L_55 ) ;
F_18 ( V_62 , L_56 ) ;
F_18 ( V_62 , L_57 ) ;
F_18 ( V_62 , L_58 ) ;
#ifndef F_3
F_18 ( V_62 , L_59 ) ;
#endif
F_18 ( V_62 , L_60 ) ;
F_18 ( V_62 , L_61 ) ;
F_18 ( V_62 , L_62 ) ;
F_18 ( V_62 , L_63 ) ;
F_18 ( V_62 , L_64 ) ;
F_18 ( V_62 , L_65 , V_81 , V_81 ) ;
F_18 ( V_62 , L_66 ) ;
F_18 ( V_62 , L_67 ) ;
F_18 ( V_62 , L_68 ) ;
F_18 ( V_62 , L_69 ) ;
#ifndef F_2
F_18 ( V_62 , L_70 ) ;
#endif
F_18 ( V_62 , L_71 ) ;
F_18 ( V_62 , L_72 ) ;
F_18 ( V_62 , L_73 ) ;
F_18 ( V_62 , L_74 ) ;
F_18 ( V_62 , L_75 ) ;
F_18 ( V_62 , L_76 ) ;
F_18 ( V_62 , L_77 ) ;
F_18 ( V_62 , L_78 ) ;
F_18 ( V_62 , L_79 ) ;
F_18 ( V_62 , L_80 ) ;
F_18 ( V_62 , L_81 ) ;
F_18 ( V_62 , L_82 ) ;
F_18 ( V_62 , L_83 ) ;
F_18 ( V_62 , L_84 ) ;
F_18 ( V_62 , L_85 ) ;
F_18 ( V_62 , L_86 ) ;
F_18 ( V_62 , L_87 ) ;
goto V_71;
}
F_38 () ;
if( ! F_39 ( V_62 , V_48 , V_49 , & V_50 , & V_51 ) ) {
F_18 ( V_62 , L_88 ) ;
goto V_71;
}
#ifndef F_5
V_52 = getenv ( L_89 ) ;
if ( V_52 == NULL )
V_52 = getenv ( L_90 ) ;
if ( V_52 == NULL )
V_52 = V_59 = F_40 () ;
V_82 = V_52 ;
V_83 = F_41 ( NULL ) ;
V_14 = F_42 ( V_83 , V_52 , & V_60 ) ;
#endif
if ( V_39 != NULL )
{
long V_60 = - 1 ;
if( V_17 )
F_18 ( V_62 , L_91 , V_39 ) ;
V_61 = F_41 ( NULL ) ;
V_14 = F_42 ( V_61 , V_39 , & V_60 ) ;
if ( V_14 == 0 )
{
F_18 ( V_62 , L_92 , V_60 , V_39 ) ;
goto V_71;
}
}
else
{
V_61 = V_83 ;
if ( V_61 == NULL )
{
F_18 ( V_62 , L_93 , V_82 ) ;
if ( V_16 )
goto V_71;
}
else if( V_17 )
F_18 ( V_62 , L_91 ,
V_82 ) ;
}
if ( V_61 != NULL )
{
if ( ! F_43 ( V_62 , V_61 ) )
goto V_71;
V_52 = F_44 ( V_61 , NULL , L_94 ) ;
if ( V_52 == NULL )
F_15 () ;
if ( V_52 != NULL )
{
T_7 * V_84 ;
V_84 = F_13 ( V_52 , L_18 ) ;
if ( V_84 == NULL )
{
}
else
{
F_45 ( V_84 ) ;
F_23 ( V_84 ) ;
}
}
}
if( ! F_46 ( V_62 , V_61 ) ) goto V_71;
if ( V_55 == NULL )
{
V_52 = F_44 ( V_61 , V_85 , L_95 ) ;
if ( V_52 == NULL )
F_15 () ;
if ( V_52 != NULL )
{
if ( ( V_55 = F_37 ( V_52 ) ) != NULL )
V_56 = V_55 ;
}
}
if ( ! V_42 )
{
V_42 = F_44 ( V_61 , V_85 , V_86 ) ;
if ( ! V_42 )
F_15 () ;
}
if ( V_42 ) {
T_12 V_87 ;
F_47 ( & V_87 ) ;
F_48 ( & V_87 , V_61 ) ;
if( ! F_49 ( V_61 , & V_87 , V_42 , NULL ) ) {
F_18 ( V_62 ,
L_96 , V_42 ) ;
goto V_71;
}
}
if( ! V_50 )
{
V_50 = F_44 ( V_61 , V_85 , L_97 ) ;
if ( ! V_50 )
F_15 () ;
}
if( ! V_51 )
{
V_51 = F_44 ( V_61 , V_85 , L_98 ) ;
if ( ! V_51 )
F_15 () ;
}
V_52 = F_44 ( V_61 , V_85 , V_88 ) ;
if ( ! V_52 )
F_15 () ;
if( V_52 && ! F_50 ( V_52 ) ) {
F_18 ( V_62 , L_99 , V_52 ) ;
goto V_71;
}
if ( V_57 != V_80 )
{
V_52 = F_44 ( V_61 , V_85 , V_89 ) ;
if ( ! V_52 )
F_15 () ;
else if ( ! strcmp ( V_52 , L_100 ) )
V_57 = V_80 ;
}
if( ! V_43 )
{
V_43 = F_44 ( V_61 , V_85 , V_90 ) ;
if ( ! V_43 )
F_15 () ;
}
if( V_43 ) {
T_12 V_87 ;
F_47 ( & V_87 ) ;
F_48 ( & V_87 , V_61 ) ;
if( ! F_49 ( V_61 , & V_87 , V_43 , NULL ) ) {
F_18 ( V_62 ,
L_101 ,
V_43 ) ;
goto V_71;
}
}
V_21 = F_9 ( F_10 () ) ;
V_22 = F_9 ( F_10 () ) ;
if ( ( V_21 == NULL ) || ( V_22 == NULL ) )
goto V_71;
#ifndef F_3
V_3 = F_51 ( V_62 , V_41 , 0 ) ;
#endif
if ( V_38 != NULL )
{
V_13 = F_52 ( V_62 , V_38 , V_28 , 0 , V_50 , V_3 ,
L_102 ) ;
if ( ! V_13 )
{
goto V_71;
}
if ( F_53 ( V_13 -> type ) == V_72 ||
F_53 ( V_13 -> type ) == V_76 )
{
char * V_91 = F_44 ( V_61 , V_85 , L_103 ) ;
if ( V_91 == NULL )
F_15 () ;
F_54 ( V_91 , V_62 , 0 ) ;
}
}
if ( V_16 && ( V_13 == NULL ) )
{
T_13 V_92 ;
char * V_91 = F_44 ( V_61 , V_85 , L_103 ) ;
if ( V_91 == NULL )
F_15 () ;
F_54 ( V_91 , V_62 , 0 ) ;
if ( V_47 )
F_55 ( V_47 ) ;
if ( V_20 <= 0 )
{
if ( ! F_56 ( V_61 , V_85 , V_93 , & V_20 ) )
V_20 = V_94 ;
}
if ( V_20 < V_95 && ( V_18 == V_19 || V_18 == V_70 ) )
{
F_18 ( V_62 , L_104 ) ;
F_18 ( V_62 , L_105 , V_95 , V_20 ) ;
goto V_71;
}
F_18 ( V_62 , L_106 ,
V_20 , ( V_18 == V_19 ) ? L_107 :
( V_18 == V_70 ) ? L_108 : L_109 ) ;
if ( ( V_13 = F_57 () ) == NULL ) goto V_71;
#ifndef F_58
F_59 ( & V_92 , V_96 , V_62 ) ;
if ( V_18 == V_19 )
{
T_14 * V_97 = F_60 () ;
T_15 * V_98 = F_61 () ;
if( ! V_98 || ! V_97 || ! F_62 ( V_98 , 0x10001 ) ||
! F_63 ( V_97 , V_20 , V_98 , & V_92 ) ||
! F_64 ( V_13 , V_97 ) )
{
if( V_98 ) F_65 ( V_98 ) ;
if( V_97 ) F_66 ( V_97 ) ;
goto V_71;
}
F_65 ( V_98 ) ;
}
else
#endif
#ifndef F_1
if ( V_18 == V_70 )
{
if ( ! F_67 ( V_4 ) ) goto V_71;
if ( ! F_68 ( V_13 , V_4 ) ) goto V_71;
V_4 = NULL ;
}
#endif
#ifndef F_2
if ( V_18 == V_75 )
{
if ( ! F_69 ( V_5 ) ) goto V_71;
if ( ! F_70 ( V_13 , V_5 ) )
goto V_71;
V_5 = NULL ;
}
#endif
F_71 ( V_91 , V_62 ) ;
if ( V_13 == NULL ) goto V_71;
if ( V_40 == NULL )
{
V_40 = F_44 ( V_61 , V_85 , V_99 ) ;
if ( V_40 == NULL )
F_15 () ;
}
if ( V_40 == NULL )
{
F_18 ( V_62 , L_110 ) ;
F_11 ( V_22 , stdout , V_64 ) ;
#ifdef F_72
{
T_7 * V_100 = F_9 ( F_73 () ) ;
V_22 = F_74 ( V_100 , V_22 ) ;
}
#endif
}
else
{
F_18 ( V_62 , L_111 , V_40 ) ;
if ( F_75 ( V_22 , V_40 ) <= 0 )
{
perror ( V_40 ) ;
goto V_71;
}
}
V_52 = F_44 ( V_61 , V_85 , L_112 ) ;
if ( V_52 == NULL )
{
F_15 () ;
V_52 = F_44 ( V_61 , V_85 , L_113 ) ;
if ( V_52 == NULL )
F_15 () ;
}
if ( ( V_52 != NULL ) && ( strcmp ( V_52 , L_114 ) == 0 ) )
V_44 = NULL ;
if ( V_30 ) V_44 = NULL ;
V_14 = 0 ;
V_101:
if ( ! F_76 ( V_22 , V_13 , V_44 ,
NULL , 0 , NULL , V_51 ) )
{
if ( ( F_77 ( F_78 () ) ==
V_102 ) && ( V_14 < 3 ) )
{
F_15 () ;
V_14 ++ ;
goto V_101;
}
goto V_71;
}
F_18 ( V_62 , L_115 ) ;
}
if ( ! V_16 )
{
V_31 = - 1 ;
if ( V_35 == NULL )
F_11 ( V_21 , V_103 , V_64 ) ;
else
{
if ( F_79 ( V_21 , V_35 ) <= 0 )
{
perror ( V_35 ) ;
goto V_71;
}
}
if ( V_23 == V_104 )
V_12 = F_80 ( V_21 , NULL ) ;
else if ( V_23 == V_29 )
V_12 = F_81 ( V_21 , NULL , NULL , NULL ) ;
else
{
F_18 ( V_62 , L_116 ) ;
goto V_71;
}
if ( V_12 == NULL )
{
F_18 ( V_62 , L_117 ) ;
goto V_71;
}
}
if ( V_16 || V_9 )
{
if ( V_13 == NULL )
{
F_18 ( V_62 , L_118 ) ;
goto V_71;
}
#ifndef F_1
if ( V_13 -> type == V_72 )
V_56 = F_82 () ;
#endif
#ifndef F_2
if ( V_13 -> type == V_76 )
V_56 = F_83 () ;
#endif
if ( V_12 == NULL )
{
V_12 = F_84 () ;
if ( V_12 == NULL )
{
goto V_71;
}
V_14 = F_85 ( V_12 , V_13 , V_53 , V_54 , ! V_9 , V_57 ) ;
V_53 = NULL ;
if ( ( V_31 > 0 ) && ! F_86 ( V_12 -> V_105 -> V_106 ) )
{
F_87 ( V_12 -> V_105 -> V_106 ) ;
V_12 -> V_105 -> V_106 = NULL ;
}
if ( ! V_14 )
{
F_18 ( V_62 , L_119 ) ;
goto V_71;
}
}
if ( V_9 )
{
T_6 * V_107 ;
T_12 V_108 ;
if ( ( V_11 = F_88 () ) == NULL ) goto V_71;
if( V_42 && ! F_89 ( V_11 , 2 ) ) goto V_71;
if ( V_45 )
{
if ( ! F_90 ( V_11 , V_45 ) ) goto V_71;
}
else
{
if ( ! F_91 ( NULL ,
F_92 ( V_11 ) ) )
goto V_71;
}
if ( ! F_93 ( V_11 , F_94 ( V_12 ) ) ) goto V_71;
if ( ! F_95 ( F_96 ( V_11 ) , 0 ) ) goto V_71;
if ( ! F_95 ( F_97 ( V_11 ) , ( long ) 60 * 60 * 24 * V_10 ) ) goto V_71;
if ( ! F_98 ( V_11 , F_94 ( V_12 ) ) ) goto V_71;
V_107 = F_99 ( V_12 ) ;
if ( ! V_107 || ! F_100 ( V_11 , V_107 ) ) goto V_71;
F_21 ( V_107 ) ;
F_101 ( & V_108 , V_11 , V_11 , NULL , NULL , 0 ) ;
F_48 ( & V_108 , V_61 ) ;
if( V_42 && ! F_49 ( V_61 ,
& V_108 , V_42 , V_11 ) )
{
F_18 ( V_62 ,
L_96 ,
V_42 ) ;
goto V_71;
}
if ( ! ( V_14 = F_102 ( V_11 , V_13 , V_56 ) ) )
goto V_71;
}
else
{
T_12 V_108 ;
F_101 ( & V_108 , NULL , NULL , V_12 , NULL , 0 ) ;
F_48 ( & V_108 , V_61 ) ;
if( V_43 && ! F_103 ( V_61 ,
& V_108 , V_43 , V_12 ) )
{
F_18 ( V_62 ,
L_96 ,
V_43 ) ;
goto V_71;
}
if ( ! ( V_14 = F_104 ( V_12 , V_13 , V_56 ) ) )
goto V_71;
}
}
if ( V_53 && V_9 )
{
F_18 ( V_62 , L_120 ) ;
goto V_71;
}
if ( V_53 && ! V_9 )
{
if ( V_17 )
{
F_18 ( V_62 , L_121 ) ;
F_105 ( V_62 , L_122 , F_94 ( V_12 ) , V_6 ) ;
}
if ( F_106 ( V_12 , V_53 , V_57 , V_54 ) == 0 )
{
F_18 ( V_62 , L_123 ) ;
V_8 = 1 ;
goto V_71;
}
V_12 -> V_105 -> V_109 . V_110 = 1 ;
if ( V_17 )
{
F_105 ( V_62 , L_124 , F_94 ( V_12 ) , V_6 ) ;
}
}
if ( V_25 && ! V_9 )
{
int V_111 = 0 ;
if ( V_13 == NULL )
{
V_13 = F_99 ( V_12 ) ;
V_111 = 1 ;
if ( V_13 == NULL ) goto V_71;
}
V_14 = F_107 ( V_12 , V_13 ) ;
if ( V_111 ) {
F_21 ( V_13 ) ;
V_13 = NULL ;
}
if ( V_14 < 0 )
{
goto V_71;
}
else if ( V_14 == 0 )
{
F_18 ( V_62 , L_125 ) ;
F_108 ( V_62 ) ;
}
else
F_18 ( V_62 , L_126 ) ;
}
if ( V_26 && ! V_27 && ! V_46 && ! V_33 && ! V_34 )
{
V_8 = 0 ;
goto V_71;
}
if ( V_36 == NULL )
{
F_11 ( V_22 , stdout , V_64 ) ;
#ifdef F_72
{
T_7 * V_100 = F_9 ( F_73 () ) ;
V_22 = F_74 ( V_100 , V_22 ) ;
}
#endif
}
else
{
if ( ( V_40 != NULL ) && ( strcmp ( V_36 , V_40 ) == 0 ) )
V_14 = ( int ) F_109 ( V_22 , V_36 ) ;
else
V_14 = ( int ) F_75 ( V_22 , V_36 ) ;
if ( ! V_14 )
{
perror ( V_36 ) ;
goto V_71;
}
}
if ( V_34 )
{
T_6 * V_112 ;
V_112 = F_99 ( V_12 ) ;
if ( V_112 == NULL )
{
F_18 ( V_62 , L_127 ) ;
F_108 ( V_62 ) ;
goto V_71;
}
F_110 ( V_22 , V_112 ) ;
F_21 ( V_112 ) ;
}
if ( V_27 )
{
if ( V_9 )
F_111 ( V_22 , V_11 , V_6 , V_7 ) ;
else
F_112 ( V_22 , V_12 , V_6 , V_7 ) ;
}
if( V_33 )
{
if( V_9 )
F_105 ( V_22 , L_128 , F_113 ( V_11 ) , V_6 ) ;
else
F_105 ( V_22 , L_128 , F_94 ( V_12 ) , V_6 ) ;
}
if ( V_46 )
{
T_6 * V_112 ;
if ( V_9 )
V_112 = F_19 ( V_11 ) ;
else
V_112 = F_99 ( V_12 ) ;
if ( V_112 == NULL )
{
fprintf ( stdout , L_129 ) ;
goto V_71;
}
fprintf ( stdout , L_130 ) ;
#ifndef F_58
if ( V_112 -> type == V_113 )
F_114 ( V_22 , V_112 -> V_13 . V_97 -> V_114 ) ;
else
#endif
fprintf ( stdout , L_131 ) ;
F_21 ( V_112 ) ;
fprintf ( stdout , L_132 ) ;
}
if ( ! V_26 && ! V_9 )
{
if ( V_24 == V_104 )
V_14 = F_115 ( V_22 , V_12 ) ;
else if ( V_24 == V_29 ) {
if( V_32 ) V_14 = F_116 ( V_22 , V_12 ) ;
else V_14 = F_117 ( V_22 , V_12 ) ;
} else {
F_18 ( V_62 , L_133 ) ;
goto V_71;
}
if ( ! V_14 )
{
F_18 ( V_62 , L_134 ) ;
goto V_71;
}
}
if ( ! V_26 && V_9 && ( V_11 != NULL ) )
{
if ( V_24 == V_104 )
V_14 = F_118 ( V_22 , V_11 ) ;
else if ( V_24 == V_29 )
V_14 = F_119 ( V_22 , V_11 ) ;
else {
F_18 ( V_62 , L_133 ) ;
goto V_71;
}
if ( ! V_14 )
{
F_18 ( V_62 , L_135 ) ;
goto V_71;
}
}
V_8 = 0 ;
V_71:
#ifndef F_5
if( V_59 )
F_120 ( V_59 ) ;
#endif
if ( V_8 )
{
F_108 ( V_62 ) ;
}
if ( ( V_61 != NULL ) && ( V_61 != V_83 ) ) F_121 ( V_61 ) ;
F_23 ( V_21 ) ;
F_122 ( V_22 ) ;
F_21 ( V_13 ) ;
F_123 ( V_12 ) ;
F_22 ( V_11 ) ;
F_124 ( V_45 ) ;
if( V_48 && V_50 ) F_120 ( V_50 ) ;
if( V_49 && V_51 ) F_120 ( V_51 ) ;
F_125 () ;
#ifndef F_1
if ( V_4 != NULL ) F_126 ( V_4 ) ;
#endif
#ifndef F_2
if ( V_5 != NULL ) F_27 ( V_5 ) ;
#endif
F_127 () ;
F_128 ( V_8 ) ;
}
static int F_85 ( T_5 * V_12 , T_6 * V_13 , char * V_53 , int V_54 ,
int V_115 , unsigned long V_57 )
{
int V_116 = 0 , V_14 ;
char V_117 = 0 ;
F_129 ( V_118 ) * V_119 , * V_120 = NULL ;
char * V_111 , * V_121 , * V_122 ;
V_111 = F_44 ( V_61 , V_85 , V_123 ) ;
if ( V_111 == NULL )
F_15 () ;
if( ( V_111 != NULL ) && ! strcmp ( V_111 , L_114 ) ) V_117 = 1 ;
V_121 = F_44 ( V_61 , V_85 , V_124 ) ;
if ( V_121 == NULL )
{
F_18 ( V_62 , L_136 ,
V_124 ) ;
goto V_125;
}
V_119 = F_130 ( V_61 , V_121 ) ;
if ( V_119 == NULL )
{
F_18 ( V_62 , L_137 , V_121 ) ;
goto V_125;
}
V_122 = F_44 ( V_61 , V_85 , V_126 ) ;
if ( V_122 == NULL )
{
F_15 () ;
V_120 = NULL ;
}
else
{
V_120 = F_130 ( V_61 , V_122 ) ;
if ( V_120 == NULL )
{
F_18 ( V_62 , L_137 , V_122 ) ;
goto V_125;
}
}
if ( ! F_131 ( V_12 , 0L ) ) goto V_125;
if ( V_117 )
V_14 = F_132 ( V_12 , V_119 , V_120 , V_115 , V_57 ) ;
else
{
if ( V_53 )
V_14 = F_106 ( V_12 , V_53 , V_57 , V_54 ) ;
else
V_14 = F_133 ( V_12 , V_119 , V_121 , V_120 , V_122 , V_115 , V_57 ) ;
}
if( ! V_14 ) goto V_125;
if ( ! F_134 ( V_12 , V_13 ) ) goto V_125;
V_116 = 1 ;
V_125:
return ( V_116 ) ;
}
static int F_106 ( T_5 * V_12 , char * V_33 , unsigned long V_57 , int V_54 )
{
T_16 * V_114 ;
if ( ! ( V_114 = F_135 ( V_33 , V_57 , V_54 ) ) )
return 0 ;
if ( ! F_136 ( V_12 , V_114 ) )
{
F_137 ( V_114 ) ;
return 0 ;
}
F_137 ( V_114 ) ;
return 1 ;
}
static int F_138 ( T_16 * V_114 , char * V_27 , const char * V_127 , char * V_128 ,
int V_129 , int V_130 , int V_131 , unsigned long V_57 , int V_132 )
{
int V_14 , V_116 = 0 ;
T_17 char V_133 [ 1024 ] ;
V_134:
if ( ! V_79 ) F_18 ( V_62 , L_138 , V_27 , V_127 ) ;
( void ) F_139 ( V_62 ) ;
if( V_128 != NULL )
{
F_140 ( V_133 , V_128 , sizeof V_133 ) ;
F_141 ( V_133 , L_132 , sizeof V_133 ) ;
F_18 ( V_62 , L_139 , V_128 ) ;
}
else
{
V_133 [ 0 ] = '\0' ;
if ( ! V_79 )
{
fgets ( V_133 , sizeof V_133 , V_103 ) ;
}
else
{
V_133 [ 0 ] = '\n' ;
V_133 [ 1 ] = '\0' ;
}
}
if ( V_133 [ 0 ] == '\0' ) return ( 0 ) ;
else if ( V_133 [ 0 ] == '\n' )
{
if ( ( V_127 == NULL ) || ( V_127 [ 0 ] == '\0' ) )
return ( 1 ) ;
F_140 ( V_133 , V_127 , sizeof V_133 ) ;
F_141 ( V_133 , L_132 , sizeof V_133 ) ;
}
else if ( ( V_133 [ 0 ] == '.' ) && ( V_133 [ 1 ] == '\n' ) ) return ( 1 ) ;
V_14 = strlen ( V_133 ) ;
if ( V_133 [ V_14 - 1 ] != '\n' )
{
F_18 ( V_62 , L_140 ) ;
return ( 0 ) ;
}
V_133 [ -- V_14 ] = '\0' ;
#ifdef F_142
F_143 ( V_133 , V_133 , V_14 ) ;
#endif
if( ! F_144 ( V_14 , V_130 , V_131 ) ) goto V_134;
if ( ! F_145 ( V_114 , V_129 , V_57 ,
( unsigned char * ) V_133 , - 1 , - 1 , V_132 ) ) goto V_125;
V_116 = 1 ;
V_125:
return ( V_116 ) ;
}
static int F_146 ( T_5 * V_12 , char * V_27 , const char * V_127 ,
char * V_128 , int V_129 , int V_130 ,
int V_131 , unsigned long V_57 )
{
int V_14 ;
static char V_133 [ 1024 ] ;
V_134:
if ( ! V_79 ) F_18 ( V_62 , L_138 , V_27 , V_127 ) ;
( void ) F_139 ( V_62 ) ;
if ( V_128 != NULL )
{
F_140 ( V_133 , V_128 , sizeof V_133 ) ;
F_141 ( V_133 , L_132 , sizeof V_133 ) ;
F_18 ( V_62 , L_139 , V_128 ) ;
}
else
{
V_133 [ 0 ] = '\0' ;
if ( ! V_79 )
{
fgets ( V_133 , sizeof V_133 , V_103 ) ;
}
else
{
V_133 [ 0 ] = '\n' ;
V_133 [ 1 ] = '\0' ;
}
}
if ( V_133 [ 0 ] == '\0' ) return ( 0 ) ;
else if ( V_133 [ 0 ] == '\n' )
{
if ( ( V_127 == NULL ) || ( V_127 [ 0 ] == '\0' ) )
return ( 1 ) ;
F_140 ( V_133 , V_127 , sizeof V_133 ) ;
F_141 ( V_133 , L_132 , sizeof V_133 ) ;
}
else if ( ( V_133 [ 0 ] == '.' ) && ( V_133 [ 1 ] == '\n' ) ) return ( 1 ) ;
V_14 = strlen ( V_133 ) ;
if ( V_133 [ V_14 - 1 ] != '\n' )
{
F_18 ( V_62 , L_140 ) ;
return ( 0 ) ;
}
V_133 [ -- V_14 ] = '\0' ;
#ifdef F_142
F_143 ( V_133 , V_133 , V_14 ) ;
#endif
if( ! F_144 ( V_14 , V_130 , V_131 ) ) goto V_134;
if( ! F_147 ( V_12 , V_129 , V_57 ,
( unsigned char * ) V_133 , - 1 ) ) {
F_18 ( V_62 , L_141 ) ;
F_108 ( V_62 ) ;
goto V_125;
}
return ( 1 ) ;
V_125:
return ( 0 ) ;
}
static int T_18 V_96 ( int V_52 , int V_114 , T_13 * V_92 )
{
char V_135 = '*' ;
if ( V_52 == 0 ) V_135 = '.' ;
if ( V_52 == 1 ) V_135 = '+' ;
if ( V_52 == 2 ) V_135 = '*' ;
if ( V_52 == 3 ) V_135 = '\n' ;
F_148 ( V_92 -> V_136 , & V_135 , 1 ) ;
( void ) F_139 ( V_92 -> V_136 ) ;
#ifdef F_149
V_52 = V_114 ;
#endif
return 1 ;
}
static int F_144 ( int V_137 , int V_130 , int V_131 )
{
if ( ( V_130 > 0 ) && ( V_137 < V_130 ) )
{
F_18 ( V_62 , L_142 , V_130 ) ;
return ( 0 ) ;
}
if ( ( V_131 >= 0 ) && ( V_137 > V_131 ) )
{
F_18 ( V_62 , L_143 , V_131 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_150 ( const char * V_138 , const char * V_71 )
{
int V_139 , V_140 ;
const char * V_111 ;
V_139 = strlen ( V_71 ) ;
V_140 = strlen ( V_138 ) ;
if( V_139 > V_140 ) return 1 ;
V_111 = V_138 + V_140 - V_139 ;
return strcmp ( V_111 , V_71 ) ;
}
