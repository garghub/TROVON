int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
#ifndef F_1
T_2 * V_4 = NULL ;
#endif
unsigned long V_5 = 0 , V_6 = 0 ;
int V_7 = 1 , V_8 = 0 , V_9 = 30 ;
T_3 * V_10 = NULL ;
T_4 * V_11 = NULL ;
T_5 * V_12 = NULL ;
int V_13 = 0 , V_14 = 0 , V_15 = 0 , V_16 = 0 , V_17 = V_18 ;
long V_19 = - 1 ;
T_6 * V_20 = NULL , * V_21 = NULL ;
int V_22 , V_23 , V_24 = 0 , V_25 = 0 , V_26 = 0 , V_27 = V_28 ;
int V_29 = 0 , V_30 = 0 , V_31 = 0 , V_32 = 0 , V_33 = 0 ;
char * V_34 , * V_35 , * V_36 , * V_37 = NULL , * V_38 = NULL , * V_39 = NULL ;
char * V_40 = NULL ;
char * V_41 = NULL ;
char * V_42 = NULL ;
const T_7 * V_43 = NULL ;
T_8 * V_44 = NULL ;
int V_45 = 0 ;
char * V_46 = NULL ;
char * V_47 = NULL , * V_48 = NULL ;
char * V_49 = NULL , * V_50 = NULL ;
char * V_51 ;
char * V_52 = NULL ;
const T_9 * V_53 = NULL , * V_54 = F_2 () ;
unsigned long V_55 = V_56 ;
#ifndef F_3
char * V_57 ;
long V_58 ;
#endif
V_59 = NULL ;
#ifndef F_4
V_43 = F_5 () ;
#endif
F_6 () ;
if ( V_60 == NULL )
if ( ( V_60 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_60 , V_61 , V_62 | V_63 ) ;
V_34 = NULL ;
V_35 = NULL ;
V_22 = V_28 ;
V_23 = V_28 ;
V_36 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_22 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_23 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_40 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_37 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
V_33 = 1 ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
V_15 = 1 ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_38 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_27 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_34 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_35 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_39 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_47 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_48 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_46 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_15 ) == 0 )
{
int V_65 ;
if ( -- V_1 < 1 ) goto V_64;
V_51 = * ( ++ V_2 ) ;
V_65 = V_51 [ 0 ] >= '0' && V_51 [ 0 ] <= '9' ;
if ( strncmp ( L_16 , V_51 , 4 ) == 0 || V_65 )
{
V_17 = V_18 ;
if( ! V_65 )
V_51 += 4 ;
V_19 = atoi ( V_51 ) ;
}
else
#ifndef F_1
if ( strncmp ( L_17 , V_51 , 4 ) == 0 )
{
T_3 * V_66 = NULL ;
T_5 * V_67 ;
V_17 = V_68 ;
V_51 += 4 ;
if ( ( V_20 = F_11 ( V_51 , L_18 ) ) == NULL )
{
perror ( V_51 ) ;
goto V_69;
}
if ( ( V_4 = F_12 ( V_20 , NULL , NULL , NULL ) ) == NULL )
{
F_13 () ;
( void ) F_14 ( V_20 ) ;
if ( ( V_66 = F_15 ( V_20 , NULL , NULL , NULL ) ) == NULL )
{
F_16 ( V_60 , L_19 ) ;
goto V_69;
}
if ( ( V_67 = F_17 ( V_66 ) ) == NULL ) goto V_69;
if ( V_67 -> type == V_70 )
V_4 = F_18 ( V_67 -> V_12 . V_71 ) ;
F_19 ( V_67 ) ;
F_20 ( V_66 ) ;
if ( V_4 == NULL )
{
F_16 ( V_60 , L_20 ) ;
goto V_69;
}
}
F_21 ( V_20 ) ;
V_19 = F_22 ( V_4 -> V_51 ) ;
V_20 = NULL ;
}
else
#endif
#ifndef F_23
if ( strncmp ( L_21 , V_51 , 4 ) == 0 )
{
V_17 = V_72 ;
V_51 += 3 ;
}
else
#endif
V_17 = V_18 ;
V_15 = 1 ;
}
else if ( strcmp ( * V_2 , L_22 ) == 0 )
V_73 = 1 ;
else if ( strcmp ( * V_2 , L_23 ) == 0 )
V_31 = 1 ;
else if ( strcmp ( * V_2 , L_24 ) == 0 )
V_45 = 1 ;
else if ( strcmp ( * V_2 , L_25 ) == 0 )
V_24 = 1 ;
else if ( strcmp ( * V_2 , L_26 ) == 0 )
V_29 = 1 ;
else if ( strcmp ( * V_2 , L_27 ) == 0 )
V_25 = 1 ;
else if ( strcmp ( * V_2 , L_28 ) == 0 )
V_16 = 1 ;
else if ( strcmp ( * V_2 , L_29 ) == 0 )
V_55 = V_74 ;
else if ( strcmp ( * V_2 , L_30 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
if ( ! F_24 ( & V_5 , * ( ++ V_2 ) ) ) goto V_64;
}
else if ( strcmp ( * V_2 , L_31 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
if ( ! F_25 ( & V_6 , * ( ++ V_2 ) ) ) goto V_64;
}
else if ( strcmp ( * V_2 , L_32 ) == 0 )
V_32 = 1 ;
else if ( strcmp ( * V_2 , L_33 ) == 0 )
V_26 = 1 ;
else if ( strcmp ( * V_2 , L_34 ) == 0 )
V_8 = 1 ;
else if ( strcmp ( * V_2 , L_35 ) == 0 )
V_30 = 1 ;
else if ( strcmp ( * V_2 , L_36 ) == 0 )
V_30 = 0 ;
else if ( strcmp ( * V_2 , L_37 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_52 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_38 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_9 = atoi ( * ( ++ V_2 ) ) ;
if ( V_9 == 0 ) V_9 = 30 ;
}
else if ( strcmp ( * V_2 , L_39 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_44 = F_26 ( NULL , * ( ++ V_2 ) ) ;
if ( ! V_44 ) goto V_64;
}
else if ( ( V_53 = F_27 ( & ( ( * V_2 ) [ 1 ] ) ) ) != NULL )
{
V_54 = V_53 ;
}
else if ( strcmp ( * V_2 , L_40 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_41 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_41 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_64;
V_42 = * ( ++ V_2 ) ;
}
else
{
F_16 ( V_60 , L_42 , * V_2 ) ;
V_14 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_14 )
{
V_64:
F_16 ( V_60 , L_43 , V_36 ) ;
F_16 ( V_60 , L_44 ) ;
F_16 ( V_60 , L_45 ) ;
F_16 ( V_60 , L_46 ) ;
F_16 ( V_60 , L_47 ) ;
F_16 ( V_60 , L_48 ) ;
F_16 ( V_60 , L_49 ) ;
F_16 ( V_60 , L_50 ) ;
F_16 ( V_60 , L_51 ) ;
F_16 ( V_60 , L_52 ) ;
F_16 ( V_60 , L_53 ) ;
F_16 ( V_60 , L_54 ) ;
F_16 ( V_60 , L_55 ) ;
F_16 ( V_60 , L_56 ) ;
F_16 ( V_60 , L_57 ) ;
F_16 ( V_60 , L_58 ) ;
F_16 ( V_60 , L_59 ) ;
F_16 ( V_60 , L_60 ) ;
F_16 ( V_60 , L_61 , V_75 , V_75 ) ;
F_16 ( V_60 , L_62 ) ;
F_16 ( V_60 , L_63 ) ;
F_16 ( V_60 , L_64 ) ;
F_16 ( V_60 , L_65 ) ;
F_16 ( V_60 , L_66 ) ;
F_16 ( V_60 , L_67 ) ;
F_16 ( V_60 , L_68 ) ;
F_16 ( V_60 , L_69 ) ;
F_16 ( V_60 , L_70 ) ;
F_16 ( V_60 , L_71 ) ;
F_16 ( V_60 , L_72 ) ;
F_16 ( V_60 , L_73 ) ;
F_16 ( V_60 , L_74 ) ;
F_16 ( V_60 , L_75 ) ;
F_16 ( V_60 , L_76 ) ;
F_16 ( V_60 , L_77 ) ;
F_16 ( V_60 , L_78 ) ;
F_16 ( V_60 , L_79 ) ;
F_16 ( V_60 , L_80 ) ;
F_16 ( V_60 , L_81 ) ;
goto V_69;
}
F_28 () ;
if( ! F_29 ( V_60 , V_47 , V_48 , & V_49 , & V_50 ) ) {
F_16 ( V_60 , L_82 ) ;
goto V_69;
}
#ifndef F_3
V_51 = getenv ( L_83 ) ;
if ( V_51 == NULL )
V_51 = getenv ( L_84 ) ;
if ( V_51 == NULL )
V_51 = V_57 = F_30 () ;
V_76 = V_51 ;
V_77 = F_31 ( NULL ) ;
V_13 = F_32 ( V_77 , V_51 , & V_58 ) ;
#endif
if ( V_38 != NULL )
{
long V_58 = - 1 ;
if( V_16 )
F_16 ( V_60 , L_85 , V_38 ) ;
V_59 = F_31 ( NULL ) ;
V_13 = F_32 ( V_59 , V_38 , & V_58 ) ;
if ( V_13 == 0 )
{
F_16 ( V_60 , L_86 , V_58 , V_38 ) ;
goto V_69;
}
}
else
{
V_59 = V_77 ;
if( V_16 )
F_16 ( V_60 , L_85 ,
V_76 ) ;
if ( V_59 == NULL )
{
F_16 ( V_60 , L_87 ) ;
}
}
if ( V_59 != NULL )
{
if ( ! F_33 ( V_60 , V_59 ) )
goto V_69;
V_51 = F_34 ( V_59 , NULL , L_88 ) ;
if ( V_51 == NULL )
F_13 () ;
if ( V_51 != NULL )
{
T_6 * V_78 ;
V_78 = F_11 ( V_51 , L_18 ) ;
if ( V_78 == NULL )
{
}
else
{
F_35 ( V_78 ) ;
F_21 ( V_78 ) ;
}
}
}
if( ! F_36 ( V_60 , V_59 ) ) goto V_69;
if ( V_53 == NULL )
{
V_51 = F_34 ( V_59 , V_79 , L_89 ) ;
if ( V_51 == NULL )
F_13 () ;
if ( V_51 != NULL )
{
if ( ( V_53 = F_27 ( V_51 ) ) != NULL )
V_54 = V_53 ;
}
}
if ( ! V_41 )
{
V_41 = F_34 ( V_59 , V_79 , V_80 ) ;
if ( ! V_41 )
F_13 () ;
}
if ( V_41 ) {
T_10 V_81 ;
F_37 ( & V_81 ) ;
F_38 ( & V_81 , V_59 ) ;
if( ! F_39 ( V_59 , & V_81 , V_41 , NULL ) ) {
F_16 ( V_60 ,
L_90 , V_41 ) ;
goto V_69;
}
}
if( ! V_49 )
{
V_49 = F_34 ( V_59 , V_79 , L_91 ) ;
if ( ! V_49 )
F_13 () ;
}
if( ! V_50 )
{
V_50 = F_34 ( V_59 , V_79 , L_92 ) ;
if ( ! V_50 )
F_13 () ;
}
V_51 = F_34 ( V_59 , V_79 , V_82 ) ;
if ( ! V_51 )
F_13 () ;
if( V_51 && ! F_40 ( V_51 ) ) {
F_16 ( V_60 , L_93 , V_51 ) ;
goto V_69;
}
if ( V_55 != V_74 )
{
V_51 = F_34 ( V_59 , V_79 , V_83 ) ;
if ( ! V_51 )
F_13 () ;
else if ( ! strcmp ( V_51 , L_94 ) )
V_55 = V_74 ;
}
if( ! V_42 )
{
V_42 = F_34 ( V_59 , V_79 , V_84 ) ;
if ( ! V_42 )
F_13 () ;
}
if( V_42 ) {
T_10 V_81 ;
F_37 ( & V_81 ) ;
F_38 ( & V_81 , V_59 ) ;
if( ! F_39 ( V_59 , & V_81 , V_42 , NULL ) ) {
F_16 ( V_60 ,
L_95 ,
V_42 ) ;
goto V_69;
}
}
V_20 = F_7 ( F_8 () ) ;
V_21 = F_7 ( F_8 () ) ;
if ( ( V_20 == NULL ) || ( V_21 == NULL ) )
goto V_69;
V_3 = F_41 ( V_60 , V_40 , 0 ) ;
if ( V_37 != NULL )
{
V_12 = F_42 ( V_60 , V_37 , V_27 , 0 , V_49 , V_3 ,
L_96 ) ;
if ( ! V_12 )
{
goto V_69;
}
if ( F_43 ( V_12 -> type ) == V_70 )
{
char * V_85 = F_34 ( V_59 , V_79 , L_97 ) ;
if ( V_85 == NULL )
F_13 () ;
F_44 ( V_85 , V_60 , 0 ) ;
}
}
if ( V_15 && ( V_12 == NULL ) )
{
char * V_85 = F_34 ( V_59 , V_79 , L_97 ) ;
if ( V_85 == NULL )
F_13 () ;
F_44 ( V_85 , V_60 , 0 ) ;
if ( V_46 )
F_45 ( V_46 ) ;
if ( V_19 <= 0 )
{
if ( ! F_46 ( V_59 , V_79 , V_86 , & V_19 ) )
V_19 = V_87 ;
}
if ( V_19 < V_88 )
{
F_16 ( V_60 , L_98 ) ;
F_16 ( V_60 , L_99 , V_88 , V_19 ) ;
goto V_69;
}
F_16 ( V_60 , L_100 ,
V_19 , ( V_17 == V_18 ) ? L_101 : L_102 ) ;
if ( ( V_12 = F_47 () ) == NULL ) goto V_69;
#ifndef F_48
if ( V_17 == V_18 )
{
if ( ! F_49 ( V_12 ,
F_50 ( V_19 , 0x10001 ,
V_89 , V_60 ) ) )
goto V_69;
}
else
#endif
#ifndef F_1
if ( V_17 == V_68 )
{
if ( ! F_51 ( V_4 ) ) goto V_69;
if ( ! F_52 ( V_12 , V_4 ) ) goto V_69;
V_4 = NULL ;
}
#endif
F_53 ( V_85 , V_60 ) ;
if ( V_12 == NULL ) goto V_69;
if ( V_39 == NULL )
{
V_39 = F_34 ( V_59 , V_79 , V_90 ) ;
if ( V_39 == NULL )
F_13 () ;
}
if ( V_39 == NULL )
{
F_16 ( V_60 , L_103 ) ;
F_9 ( V_21 , stdout , V_62 ) ;
#ifdef F_54
{
T_6 * V_91 = F_7 ( F_55 () ) ;
V_21 = F_56 ( V_91 , V_21 ) ;
}
#endif
}
else
{
F_16 ( V_60 , L_104 , V_39 ) ;
if ( F_57 ( V_21 , V_39 ) <= 0 )
{
perror ( V_39 ) ;
goto V_69;
}
}
V_51 = F_34 ( V_59 , V_79 , L_105 ) ;
if ( V_51 == NULL )
{
F_13 () ;
V_51 = F_34 ( V_59 , V_79 , L_106 ) ;
if ( V_51 == NULL )
F_13 () ;
}
if ( ( V_51 != NULL ) && ( strcmp ( V_51 , L_107 ) == 0 ) )
V_43 = NULL ;
if ( V_29 ) V_43 = NULL ;
V_13 = 0 ;
V_92:
if ( ! F_58 ( V_21 , V_12 , V_43 ,
NULL , 0 , NULL , V_50 ) )
{
if ( ( F_59 ( F_60 () ) ==
V_93 ) && ( V_13 < 3 ) )
{
F_13 () ;
V_13 ++ ;
goto V_92;
}
goto V_69;
}
F_16 ( V_60 , L_108 ) ;
}
if ( ! V_15 )
{
V_30 = - 1 ;
if ( V_34 == NULL )
F_9 ( V_20 , V_94 , V_62 ) ;
else
{
if ( F_61 ( V_20 , V_34 ) <= 0 )
{
perror ( V_34 ) ;
goto V_69;
}
}
if ( V_22 == V_95 )
V_11 = F_62 ( V_20 , NULL ) ;
else if ( V_22 == V_28 )
V_11 = F_63 ( V_20 , NULL , NULL , NULL ) ;
else
{
F_16 ( V_60 , L_109 ) ;
goto V_69;
}
if ( V_11 == NULL )
{
F_16 ( V_60 , L_110 ) ;
goto V_69;
}
}
if ( V_15 || V_8 )
{
if ( V_12 == NULL )
{
F_16 ( V_60 , L_111 ) ;
goto V_69;
}
#ifndef F_1
if ( V_12 -> type == V_70 )
V_54 = F_64 () ;
#endif
if ( V_11 == NULL )
{
V_11 = F_65 () ;
if ( V_11 == NULL )
{
goto V_69;
}
V_13 = F_66 ( V_11 , V_12 , V_52 , ! V_8 , V_55 ) ;
V_52 = NULL ;
if ( ( V_30 > 0 ) && ! F_67 ( V_11 -> V_96 -> V_97 ) )
{
F_68 ( V_11 -> V_96 -> V_97 ) ;
V_11 -> V_96 -> V_97 = NULL ;
}
if ( ! V_13 )
{
F_16 ( V_60 , L_112 ) ;
goto V_69;
}
}
if ( V_8 )
{
T_5 * V_98 ;
T_10 V_99 ;
if ( ( V_10 = F_69 () ) == NULL ) goto V_69;
if( ! F_70 ( V_10 , 2 ) ) goto V_69;
if ( V_44 )
{
if ( ! F_71 ( V_10 , V_44 ) ) goto V_69;
}
else
{
if ( ! F_72 ( F_73 ( V_10 ) , 0L ) ) goto V_69;
}
if ( ! F_74 ( V_10 , F_75 ( V_11 ) ) ) goto V_69;
if ( ! F_76 ( F_77 ( V_10 ) , 0 ) ) goto V_69;
if ( ! F_76 ( F_78 ( V_10 ) , ( long ) 60 * 60 * 24 * V_9 ) ) goto V_69;
if ( ! F_79 ( V_10 , F_75 ( V_11 ) ) ) goto V_69;
V_98 = F_80 ( V_11 ) ;
if ( ! V_98 || ! F_81 ( V_10 , V_98 ) ) goto V_69;
F_19 ( V_98 ) ;
F_82 ( & V_99 , V_10 , V_10 , NULL , NULL , 0 ) ;
F_38 ( & V_99 , V_59 ) ;
if( V_41 && ! F_39 ( V_59 ,
& V_99 , V_41 , V_10 ) )
{
F_16 ( V_60 ,
L_90 ,
V_41 ) ;
goto V_69;
}
if ( ! ( V_13 = F_83 ( V_10 , V_12 , V_54 ) ) )
goto V_69;
}
else
{
T_10 V_99 ;
F_82 ( & V_99 , NULL , NULL , V_11 , NULL , 0 ) ;
F_38 ( & V_99 , V_59 ) ;
if( V_42 && ! F_84 ( V_59 ,
& V_99 , V_42 , V_11 ) )
{
F_16 ( V_60 ,
L_90 ,
V_42 ) ;
goto V_69;
}
if ( ! ( V_13 = F_85 ( V_11 , V_12 , V_54 ) ) )
goto V_69;
}
}
if ( V_52 && V_8 )
{
F_16 ( V_60 , L_113 ) ;
goto V_69;
}
if ( V_52 && ! V_8 )
{
if ( V_16 )
{
F_16 ( V_60 , L_114 ) ;
F_86 ( V_60 , L_115 , F_75 ( V_11 ) , V_5 ) ;
}
if ( F_87 ( V_11 , V_52 , V_55 ) == 0 )
{
F_16 ( V_60 , L_116 ) ;
V_7 = 1 ;
goto V_69;
}
V_11 -> V_96 -> V_100 . V_101 = 1 ;
if ( V_16 )
{
F_86 ( V_60 , L_117 , F_75 ( V_11 ) , V_5 ) ;
}
}
if ( V_24 && ! V_8 )
{
int V_102 = 0 ;
if ( V_12 == NULL )
{
V_12 = F_80 ( V_11 ) ;
V_102 = 1 ;
if ( V_12 == NULL ) goto V_69;
}
V_13 = F_88 ( V_11 , V_12 ) ;
if ( V_102 ) {
F_19 ( V_12 ) ;
V_12 = NULL ;
}
if ( V_13 < 0 )
{
goto V_69;
}
else if ( V_13 == 0 )
{
F_16 ( V_60 , L_118 ) ;
F_89 ( V_60 ) ;
}
else
F_16 ( V_60 , L_119 ) ;
}
if ( V_25 && ! V_26 && ! V_45 && ! V_32 && ! V_33 )
{
V_7 = 0 ;
goto V_69;
}
if ( V_35 == NULL )
{
F_9 ( V_21 , stdout , V_62 ) ;
#ifdef F_54
{
T_6 * V_91 = F_7 ( F_55 () ) ;
V_21 = F_56 ( V_91 , V_21 ) ;
}
#endif
}
else
{
if ( ( V_39 != NULL ) && ( strcmp ( V_35 , V_39 ) == 0 ) )
V_13 = ( int ) F_90 ( V_21 , V_35 ) ;
else
V_13 = ( int ) F_57 ( V_21 , V_35 ) ;
if ( ! V_13 )
{
perror ( V_35 ) ;
goto V_69;
}
}
if ( V_33 )
{
T_5 * V_103 ;
V_103 = F_80 ( V_11 ) ;
if ( V_103 == NULL )
{
F_16 ( V_60 , L_120 ) ;
F_89 ( V_60 ) ;
goto V_69;
}
F_91 ( V_21 , V_103 ) ;
F_19 ( V_103 ) ;
}
if ( V_26 )
{
if ( V_8 )
F_92 ( V_21 , V_10 , V_5 , V_6 ) ;
else
F_93 ( V_21 , V_11 , V_5 , V_6 ) ;
}
if( V_32 )
{
if( V_8 )
F_86 ( V_21 , L_121 , F_94 ( V_10 ) , V_5 ) ;
else
F_86 ( V_21 , L_121 , F_75 ( V_11 ) , V_5 ) ;
}
if ( V_45 )
{
T_5 * V_103 ;
if ( V_8 )
V_103 = F_17 ( V_10 ) ;
else
V_103 = F_80 ( V_11 ) ;
if ( V_103 == NULL )
{
fprintf ( stdout , L_122 ) ;
goto V_69;
}
fprintf ( stdout , L_123 ) ;
#ifndef F_48
if ( V_103 -> type == V_104 )
F_95 ( V_21 , V_103 -> V_12 . V_105 -> V_106 ) ;
else
#endif
fprintf ( stdout , L_124 ) ;
F_19 ( V_103 ) ;
fprintf ( stdout , L_125 ) ;
}
if ( ! V_25 && ! V_8 )
{
if ( V_23 == V_95 )
V_13 = F_96 ( V_21 , V_11 ) ;
else if ( V_23 == V_28 ) {
if( V_31 ) V_13 = F_97 ( V_21 , V_11 ) ;
else V_13 = F_98 ( V_21 , V_11 ) ;
} else {
F_16 ( V_60 , L_126 ) ;
goto V_69;
}
if ( ! V_13 )
{
F_16 ( V_60 , L_127 ) ;
goto V_69;
}
}
if ( ! V_25 && V_8 && ( V_10 != NULL ) )
{
if ( V_23 == V_95 )
V_13 = F_99 ( V_21 , V_10 ) ;
else if ( V_23 == V_28 )
V_13 = F_100 ( V_21 , V_10 ) ;
else {
F_16 ( V_60 , L_126 ) ;
goto V_69;
}
if ( ! V_13 )
{
F_16 ( V_60 , L_128 ) ;
goto V_69;
}
}
V_7 = 0 ;
V_69:
#ifndef F_3
if( V_57 )
F_101 ( V_57 ) ;
#endif
if ( V_7 )
{
F_89 ( V_60 ) ;
}
if ( ( V_59 != NULL ) && ( V_59 != V_77 ) ) F_102 ( V_59 ) ;
F_21 ( V_20 ) ;
F_103 ( V_21 ) ;
F_19 ( V_12 ) ;
F_104 ( V_11 ) ;
F_20 ( V_10 ) ;
F_105 ( V_44 ) ;
if( V_47 && V_49 ) F_101 ( V_49 ) ;
if( V_48 && V_50 ) F_101 ( V_50 ) ;
F_106 () ;
#ifndef F_1
if ( V_4 != NULL ) F_107 ( V_4 ) ;
#endif
F_108 () ;
F_109 ( V_7 ) ;
}
static int F_66 ( T_4 * V_11 , T_5 * V_12 , char * V_52 , int V_107 ,
unsigned long V_55 )
{
int V_108 = 0 , V_13 ;
char V_109 = 0 ;
F_110 ( V_110 ) * V_111 , * V_112 = NULL ;
char * V_102 , * V_113 , * V_114 ;
V_102 = F_34 ( V_59 , V_79 , V_115 ) ;
if ( V_102 == NULL )
F_13 () ;
if( ( V_102 != NULL ) && ! strcmp ( V_102 , L_107 ) ) V_109 = 1 ;
V_113 = F_34 ( V_59 , V_79 , V_116 ) ;
if ( V_113 == NULL )
{
F_16 ( V_60 , L_129 ,
V_116 ) ;
goto V_117;
}
V_111 = F_111 ( V_59 , V_113 ) ;
if ( V_111 == NULL )
{
F_16 ( V_60 , L_130 , V_113 ) ;
goto V_117;
}
V_114 = F_34 ( V_59 , V_79 , V_118 ) ;
if ( V_114 == NULL )
{
F_13 () ;
V_112 = NULL ;
}
else
{
V_112 = F_111 ( V_59 , V_114 ) ;
if ( V_112 == NULL )
{
F_16 ( V_60 , L_130 , V_114 ) ;
goto V_117;
}
}
if ( ! F_112 ( V_11 , 0L ) ) goto V_117;
if ( V_109 )
V_13 = F_113 ( V_11 , V_111 , V_112 , V_107 , V_55 ) ;
else
{
if ( V_52 )
V_13 = F_87 ( V_11 , V_52 , V_55 ) ;
else
V_13 = F_114 ( V_11 , V_111 , V_113 , V_112 , V_114 , V_107 , V_55 ) ;
}
if( ! V_13 ) goto V_117;
if ( ! F_115 ( V_11 , V_12 ) ) goto V_117;
V_108 = 1 ;
V_117:
return ( V_108 ) ;
}
static int F_87 ( T_4 * V_11 , char * V_32 , unsigned long V_55 )
{
T_11 * V_106 ;
if ( ! ( V_106 = F_116 ( V_32 , V_55 ) ) )
return 0 ;
if ( ! F_117 ( V_11 , V_106 ) )
{
F_118 ( V_106 ) ;
return 0 ;
}
F_118 ( V_106 ) ;
return 1 ;
}
static int F_119 ( T_11 * V_106 , char * V_26 , char * V_119 , char * V_120 ,
int V_121 , int V_122 , int V_123 , unsigned long V_55 )
{
int V_13 , V_108 = 0 ;
T_12 char V_124 [ 1024 ] ;
V_125:
if ( ! V_73 ) F_16 ( V_60 , L_131 , V_26 , V_119 ) ;
( void ) F_120 ( V_60 ) ;
if( V_120 != NULL )
{
F_121 ( strlen ( V_120 ) < sizeof V_124 - 2 ) ;
strcpy ( V_124 , V_120 ) ;
strcat ( V_124 , L_125 ) ;
F_16 ( V_60 , L_132 , V_120 ) ;
}
else
{
V_124 [ 0 ] = '\0' ;
if ( ! V_73 )
{
fgets ( V_124 , sizeof V_124 , V_94 ) ;
}
else
{
V_124 [ 0 ] = '\n' ;
V_124 [ 1 ] = '\0' ;
}
}
if ( V_124 [ 0 ] == '\0' ) return ( 0 ) ;
else if ( V_124 [ 0 ] == '\n' )
{
if ( ( V_119 == NULL ) || ( V_119 [ 0 ] == '\0' ) )
return ( 1 ) ;
strcpy ( V_124 , V_119 ) ;
strcat ( V_124 , L_125 ) ;
}
else if ( ( V_124 [ 0 ] == '.' ) && ( V_124 [ 1 ] == '\n' ) ) return ( 1 ) ;
V_13 = strlen ( V_124 ) ;
if ( V_124 [ V_13 - 1 ] != '\n' )
{
F_16 ( V_60 , L_133 ) ;
return ( 0 ) ;
}
V_124 [ -- V_13 ] = '\0' ;
#ifdef F_122
F_123 ( V_124 , V_124 , V_13 ) ;
#endif
if( ! F_124 ( V_13 , V_122 , V_123 ) ) goto V_125;
if ( ! F_125 ( V_106 , V_121 , V_55 ,
( unsigned char * ) V_124 , - 1 , - 1 , 0 ) ) goto V_117;
V_108 = 1 ;
V_117:
return ( V_108 ) ;
}
static int F_126 ( T_4 * V_11 , char * V_26 ,
char * V_119 , char * V_120 , int V_121 , int V_122 ,
int V_123 , unsigned long V_55 )
{
int V_13 ;
static char V_124 [ 1024 ] ;
V_125:
if ( ! V_73 ) F_16 ( V_60 , L_131 , V_26 , V_119 ) ;
( void ) F_120 ( V_60 ) ;
if ( V_120 != NULL )
{
F_121 ( strlen ( V_120 ) < sizeof V_124 - 2 ) ;
strcpy ( V_124 , V_120 ) ;
strcat ( V_124 , L_125 ) ;
F_16 ( V_60 , L_132 , V_120 ) ;
}
else
{
V_124 [ 0 ] = '\0' ;
if ( ! V_73 )
{
fgets ( V_124 , sizeof V_124 , V_94 ) ;
}
else
{
V_124 [ 0 ] = '\n' ;
V_124 [ 1 ] = '\0' ;
}
}
if ( V_124 [ 0 ] == '\0' ) return ( 0 ) ;
else if ( V_124 [ 0 ] == '\n' )
{
if ( ( V_119 == NULL ) || ( V_119 [ 0 ] == '\0' ) )
return ( 1 ) ;
strcpy ( V_124 , V_119 ) ;
strcat ( V_124 , L_125 ) ;
}
else if ( ( V_124 [ 0 ] == '.' ) && ( V_124 [ 1 ] == '\n' ) ) return ( 1 ) ;
V_13 = strlen ( V_124 ) ;
if ( V_124 [ V_13 - 1 ] != '\n' )
{
F_16 ( V_60 , L_133 ) ;
return ( 0 ) ;
}
V_124 [ -- V_13 ] = '\0' ;
#ifdef F_122
F_123 ( V_124 , V_124 , V_13 ) ;
#endif
if( ! F_124 ( V_13 , V_122 , V_123 ) ) goto V_125;
if( ! F_127 ( V_11 , V_121 , V_55 ,
( unsigned char * ) V_124 , - 1 ) ) {
F_16 ( V_60 , L_134 ) ;
F_89 ( V_60 ) ;
goto V_117;
}
return ( 1 ) ;
V_117:
return ( 0 ) ;
}
static void T_13 V_89 ( int V_51 , int V_106 , void * V_126 )
{
char V_127 = '*' ;
if ( V_51 == 0 ) V_127 = '.' ;
if ( V_51 == 1 ) V_127 = '+' ;
if ( V_51 == 2 ) V_127 = '*' ;
if ( V_51 == 3 ) V_127 = '\n' ;
F_128 ( ( T_6 * ) V_126 , & V_127 , 1 ) ;
( void ) F_120 ( ( T_6 * ) V_126 ) ;
#ifdef F_129
V_51 = V_106 ;
#endif
}
static int F_124 ( int V_128 , int V_122 , int V_123 )
{
if ( ( V_122 > 0 ) && ( V_128 < V_122 ) )
{
F_16 ( V_60 , L_135 , V_122 ) ;
return ( 0 ) ;
}
if ( ( V_123 >= 0 ) && ( V_128 > V_123 ) )
{
F_16 ( V_60 , L_136 , V_123 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_130 ( char * V_129 , char * V_69 )
{
int V_130 , V_131 ;
char * V_102 ;
V_130 = strlen ( V_69 ) ;
V_131 = strlen ( V_129 ) ;
if( V_130 > V_131 ) return 1 ;
V_102 = V_129 + V_131 - V_130 ;
return strcmp ( V_102 , V_69 ) ;
}
