int MAIN ( int V_1 , char * * V_2 )
{
#ifndef F_1
T_1 * V_3 = NULL ;
#endif
int V_4 = 1 , V_5 = 0 , V_6 = 30 ;
T_2 * V_7 = NULL ;
T_3 * V_8 = NULL ;
T_4 * V_9 = NULL ;
int V_10 , V_11 = 0 , V_12 = 0 , V_13 = - 1 , V_14 = 0 ;
T_5 * V_15 = NULL , * V_16 = NULL ;
int V_17 , V_18 , V_19 = 0 , V_20 = 0 , V_21 = 0 , V_22 = V_23 ;
int V_24 = 0 , V_25 = 0 ;
char * V_26 , * V_27 , * V_28 , * V_29 = NULL , * V_30 = NULL , * V_31 = NULL ;
char * V_32 = NULL ;
T_6 * V_33 = NULL ;
int V_34 = 0 ;
char * V_35 ;
const T_7 * V_36 = NULL , * V_37 = F_2 () ;
#ifndef F_3
T_8 char V_38 [ 256 ] ;
#endif
#ifndef F_4
V_33 = F_5 () ;
#endif
F_6 () ;
if ( V_39 == NULL )
if ( ( V_39 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_39 , V_40 , V_41 | V_42 ) ;
V_26 = NULL ;
V_27 = NULL ;
V_17 = V_23 ;
V_18 = V_23 ;
V_28 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_43;
V_17 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_43;
V_18 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_43;
V_29 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
V_14 = V_44 ;
V_12 = 1 ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_43;
V_30 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_43;
V_22 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_43;
V_26 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_43;
V_27 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_43;
V_31 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
int V_45 ;
if ( -- V_1 < 1 ) goto V_43;
V_35 = * ( ++ V_2 ) ;
V_45 = V_35 [ 0 ] >= '0' && V_35 [ 0 ] <= '9' ;
if ( strncmp ( L_11 , V_35 , 4 ) == 0 || V_45 )
{
V_14 = V_44 ;
if( ! V_45 )
V_35 += 4 ;
V_13 = atoi ( V_35 ) ;
}
else
#ifndef F_1
if ( strncmp ( L_12 , V_35 , 4 ) == 0 )
{
T_2 * V_46 = NULL ;
T_4 * V_47 ;
V_14 = V_48 ;
V_35 += 4 ;
if ( ( V_15 = F_11 ( V_35 , L_13 ) ) == NULL )
{
perror ( V_35 ) ;
goto V_49;
}
if ( ( V_3 = F_12 ( V_15 , NULL , NULL ) ) == NULL )
{
F_13 () ;
F_14 ( V_15 ) ;
if ( ( V_46 = F_15 ( V_15 , NULL , NULL ) ) == NULL )
{
F_16 ( V_39 , L_14 ) ;
goto V_49;
}
V_47 = F_17 ( V_46 ) ;
if ( V_47 -> type == V_50 )
V_3 = F_18 ( V_47 -> V_9 . V_51 ) ;
F_19 ( V_47 ) ;
F_20 ( V_46 ) ;
if ( V_3 == NULL )
{
F_16 ( V_39 , L_15 ) ;
goto V_49;
}
}
F_21 ( V_15 ) ;
V_13 = F_22 ( V_3 -> V_35 ) ;
V_15 = NULL ;
}
else
#endif
#ifndef F_23
if ( strncmp ( L_16 , V_35 , 4 ) == 0 )
{
V_14 = V_52 ;
V_35 += 3 ;
}
else
#endif
V_14 = V_44 ;
V_12 = 1 ;
}
else if ( strcmp ( * V_2 , L_17 ) == 0 )
V_34 = 1 ;
else if ( strcmp ( * V_2 , L_18 ) == 0 )
V_19 = 1 ;
else if ( strcmp ( * V_2 , L_19 ) == 0 )
V_24 = 1 ;
else if ( strcmp ( * V_2 , L_20 ) == 0 )
V_20 = 1 ;
else if ( strcmp ( * V_2 , L_21 ) == 0 )
V_21 = 1 ;
else if ( strcmp ( * V_2 , L_22 ) == 0 )
V_5 = 1 ;
else if ( strcmp ( * V_2 , L_23 ) == 0 )
V_25 = 1 ;
else if ( strcmp ( * V_2 , L_24 ) == 0 )
V_25 = 0 ;
else if ( strcmp ( * V_2 , L_25 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_43;
V_6 = atoi ( * ( ++ V_2 ) ) ;
if ( V_6 == 0 ) V_6 = 30 ;
}
else if ( ( V_36 = F_24 ( & ( ( * V_2 ) [ 1 ] ) ) ) != NULL )
{
V_37 = V_36 ;
}
else
{
F_16 ( V_39 , L_26 , * V_2 ) ;
V_11 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_11 )
{
V_43:
F_16 ( V_39 , L_27 , V_28 ) ;
F_16 ( V_39 , L_28 ) ;
F_16 ( V_39 , L_29 ) ;
F_16 ( V_39 , L_30 ) ;
F_16 ( V_39 , L_31 ) ;
F_16 ( V_39 , L_32 ) ;
F_16 ( V_39 , L_33 ) ;
F_16 ( V_39 , L_34 ) ;
F_16 ( V_39 , L_35 ) ;
F_16 ( V_39 , L_36 ) ;
F_16 ( V_39 , L_37 ) ;
F_16 ( V_39 , L_38 ) ;
F_16 ( V_39 , L_39 ) ;
F_16 ( V_39 , L_40 ) ;
F_16 ( V_39 , L_41 ) ;
F_16 ( V_39 , L_42 ) ;
F_16 ( V_39 , L_43 ) ;
F_16 ( V_39 , L_44 ) ;
F_16 ( V_39 , L_45 ) ;
F_16 ( V_39 , L_46 ) ;
F_16 ( V_39 , L_47 ) ;
F_16 ( V_39 , L_48 ) ;
F_16 ( V_39 , L_49 ) ;
F_16 ( V_39 , L_50 ) ;
goto V_49;
}
F_25 () ;
F_26 () ;
#ifndef F_3
V_35 = getenv ( L_51 ) ;
if ( V_35 == NULL )
V_35 = getenv ( L_52 ) ;
if ( V_35 == NULL )
{
strcpy ( V_38 , F_27 () ) ;
#ifndef F_28
strcat ( V_38 , L_53 ) ;
#endif
strcat ( V_38 , V_53 ) ;
V_35 = V_38 ;
}
V_54 = V_35 ;
V_55 = F_29 ( V_55 , V_35 , NULL ) ;
#endif
if ( V_30 != NULL )
{
long V_56 ;
F_16 ( V_39 , L_54 , V_30 ) ;
V_57 = F_29 ( NULL , V_30 , & V_56 ) ;
if ( V_57 == NULL )
{
F_16 ( V_39 , L_55 , V_56 , V_30 ) ;
goto V_49;
}
}
else
{
V_57 = V_55 ;
F_16 ( V_39 , L_54 ,
V_54 ) ;
if ( V_57 == NULL )
{
F_16 ( V_39 , L_56 ) ;
}
}
if ( V_57 != NULL )
{
V_35 = F_30 ( V_57 , NULL , L_57 ) ;
if ( V_35 != NULL )
{
T_5 * V_58 ;
V_58 = F_11 ( V_35 , L_13 ) ;
if ( V_58 == NULL )
{
}
else
{
F_31 ( V_58 ) ;
F_21 ( V_58 ) ;
}
}
}
if( ! F_32 ( V_57 ) ) goto V_49;
if ( ( V_36 == NULL ) &&
( ( V_35 = F_30 ( V_57 , V_59 , L_58 ) ) != NULL ) )
{
if ( ( V_36 = F_24 ( V_35 ) ) != NULL )
V_37 = V_36 ;
}
V_32 = F_30 ( V_57 , V_59 , V_60 ) ;
if( V_32 ) {
T_9 V_61 ;
F_33 ( & V_61 ) ;
F_34 ( & V_61 , V_57 ) ;
if( ! F_35 ( V_57 , & V_61 , V_32 , NULL ) ) {
F_16 ( V_39 ,
L_59 , V_32 ) ;
goto V_49;
}
}
V_15 = F_7 ( F_8 () ) ;
V_16 = F_7 ( F_8 () ) ;
if ( ( V_15 == NULL ) || ( V_16 == NULL ) )
goto V_49;
if ( V_29 != NULL )
{
if ( F_36 ( V_15 , V_29 ) <= 0 )
{
perror ( V_29 ) ;
goto V_49;
}
if ( V_22 == V_23 )
V_9 = F_37 ( V_15 , NULL , NULL ) ;
else
{
F_16 ( V_39 , L_60 ) ;
goto V_49;
}
if ( V_9 == NULL )
{
F_16 ( V_39 , L_61 ) ;
goto V_49;
}
}
if ( V_12 && ( V_9 == NULL ) )
{
char * V_62 ;
char V_63 [ 200 ] ;
if ( ( V_62 = F_30 ( V_57 , V_59 , L_62 ) ) == NULL )
V_62 = F_38 ( V_63 , 200 ) ;
#ifdef F_39
F_16 ( V_39 , L_63 ) ;
F_40 ( V_39 ) ;
F_41 () ;
F_16 ( V_39 , L_64 ) ;
#endif
if ( ( V_62 == NULL ) || ! F_42 ( V_62 , 1024L * 1024L ) )
{
F_16 ( V_39 , L_65 ) ;
F_16 ( V_39 , L_66 ) ;
F_16 ( V_39 , L_67 ) ;
F_16 ( V_39 , L_68 ) ;
F_16 ( V_39 , L_69 ) ;
}
if ( V_13 <= 0 )
{
V_13 = ( int ) F_43 ( V_57 , V_59 , V_64 ) ;
if ( V_13 <= 0 )
V_13 = V_65 ;
}
if ( V_13 < V_66 )
{
F_16 ( V_39 , L_70 ) ;
F_16 ( V_39 , L_71 , V_66 , V_13 ) ;
goto V_49;
}
F_16 ( V_39 , L_72 ,
V_13 , ( V_14 == V_44 ) ? L_73 : L_74 ) ;
if ( ( V_9 = F_44 () ) == NULL ) goto V_49;
#ifndef F_45
if ( V_14 == V_44 )
{
if ( ! F_46 ( V_9 ,
F_47 ( V_13 , 0x10001 ,
V_67 , ( char * ) V_39 ) ) )
goto V_49;
}
else
#endif
#ifndef F_1
if ( V_14 == V_48 )
{
if ( ! F_48 ( V_3 ) ) goto V_49;
if ( ! F_49 ( V_9 , V_3 ) ) goto V_49;
V_3 = NULL ;
}
#endif
if ( ( V_62 == NULL ) || ( F_50 ( V_62 ) == 0 ) )
F_16 ( V_39 , L_75 ) ;
if ( V_9 == NULL ) goto V_49;
if ( V_31 == NULL )
V_31 = F_30 ( V_57 , V_59 , V_68 ) ;
if ( V_31 == NULL )
{
F_16 ( V_39 , L_76 ) ;
F_9 ( V_16 , stdout , V_41 ) ;
}
else
{
F_16 ( V_39 , L_77 , V_31 ) ;
if ( F_51 ( V_16 , V_31 ) <= 0 )
{
perror ( V_31 ) ;
goto V_49;
}
}
V_35 = F_30 ( V_57 , V_59 , L_78 ) ;
if ( V_35 == NULL )
V_35 = F_30 ( V_57 , V_59 , L_79 ) ;
if ( ( V_35 != NULL ) && ( strcmp ( V_35 , L_80 ) == 0 ) )
V_33 = NULL ;
if ( V_24 ) V_33 = NULL ;
V_10 = 0 ;
V_69:
if ( ! F_52 ( V_16 , V_9 , V_33 ,
NULL , 0 , NULL ) )
{
if ( ( F_53 ( F_54 () ) ==
V_70 ) && ( V_10 < 3 ) )
{
F_13 () ;
V_10 ++ ;
goto V_69;
}
goto V_49;
}
F_16 ( V_39 , L_81 ) ;
}
if ( ! V_12 )
{
V_25 = - 1 ;
if ( V_26 == NULL )
F_9 ( V_15 , V_71 , V_41 ) ;
else
{
if ( F_36 ( V_15 , V_26 ) <= 0 )
{
perror ( V_26 ) ;
goto V_49;
}
}
if ( V_17 == V_72 )
V_8 = F_55 ( V_15 , NULL ) ;
else if ( V_17 == V_23 )
V_8 = F_56 ( V_15 , NULL , NULL ) ;
else
{
F_16 ( V_39 , L_60 ) ;
goto V_49;
}
if ( V_8 == NULL )
{
F_16 ( V_39 , L_82 ) ;
goto V_49;
}
}
if ( V_12 || V_5 )
{
#ifndef F_1
if ( V_9 -> type == V_50 )
V_37 = F_57 () ;
#endif
if ( V_9 == NULL )
{
F_16 ( V_39 , L_83 ) ;
goto V_49;
}
if ( V_8 == NULL )
{
V_8 = F_58 () ;
if ( V_8 == NULL )
{
goto V_49;
}
V_10 = F_59 ( V_8 , V_9 , ! V_5 ) ;
if ( V_25 >= 0 )
V_8 -> V_73 -> V_74 = V_25 ;
if ( ! V_10 )
{
F_16 ( V_39 , L_84 ) ;
goto V_49;
}
}
if ( V_5 )
{
T_4 * V_75 ;
T_9 V_76 ;
if ( ( V_7 = F_60 () ) == NULL ) goto V_49;
if( ! F_61 ( V_7 , 2 ) ) goto V_49;
F_62 ( F_63 ( V_7 ) , 0L ) ;
F_64 ( V_7 ,
F_65 ( V_8 ) ) ;
F_66 ( F_67 ( V_7 ) , 0 ) ;
F_66 ( F_68 ( V_7 ) ,
( long ) 60 * 60 * 24 * V_6 ) ;
F_69 ( V_7 ,
F_65 ( V_8 ) ) ;
V_75 = F_70 ( V_8 ) ;
F_71 ( V_7 , V_75 ) ;
F_19 ( V_75 ) ;
F_72 ( & V_76 , V_7 , V_7 , NULL , NULL , 0 ) ;
F_34 ( & V_76 , V_57 ) ;
if( V_32 && ! F_35 ( V_57 ,
& V_76 , V_32 , V_7 ) )
{
F_16 ( V_39 ,
L_59 ,
V_32 ) ;
goto V_49;
}
if ( ! ( V_10 = F_73 ( V_7 , V_9 , V_37 ) ) )
goto V_49;
}
else
{
if ( ! ( V_10 = F_74 ( V_8 , V_9 , V_37 ) ) )
goto V_49;
}
}
if ( V_19 && ! V_5 )
{
int V_77 = 0 ;
if ( V_9 == NULL )
{
V_9 = F_70 ( V_8 ) ;
V_77 = 1 ;
if ( V_9 == NULL ) goto V_49;
}
V_10 = F_75 ( V_8 , V_9 ) ;
if ( V_77 ) {
F_19 ( V_9 ) ;
V_9 = NULL ;
}
if ( V_10 < 0 )
{
goto V_49;
}
else if ( V_10 == 0 )
{
F_16 ( V_39 , L_85 ) ;
}
else
F_16 ( V_39 , L_86 ) ;
}
if ( V_20 && ! V_21 && ! V_34 )
{
V_4 = 0 ;
goto V_49;
}
if ( V_27 == NULL )
F_9 ( V_16 , stdout , V_41 ) ;
else
{
if ( ( V_31 != NULL ) && ( strcmp ( V_27 , V_31 ) == 0 ) )
V_10 = ( int ) F_76 ( V_16 , V_27 ) ;
else
V_10 = ( int ) F_51 ( V_16 , V_27 ) ;
if ( ! V_10 )
{
perror ( V_27 ) ;
goto V_49;
}
}
if ( V_21 )
{
if ( V_5 )
F_77 ( V_16 , V_7 ) ;
else
F_78 ( V_16 , V_8 ) ;
}
if ( V_34 )
{
T_4 * V_78 ;
if ( V_5 )
V_78 = F_17 ( V_7 ) ;
else
V_78 = F_70 ( V_8 ) ;
if ( V_78 == NULL )
{
fprintf ( stdout , L_87 ) ;
goto V_49;
}
fprintf ( stdout , L_88 ) ;
#ifndef F_45
if ( V_78 -> type == V_79 )
F_79 ( V_16 , V_78 -> V_9 . V_80 -> V_81 ) ;
else
#endif
fprintf ( stdout , L_89 ) ;
fprintf ( stdout , L_90 ) ;
}
if ( ! V_20 && ! V_5 )
{
if ( V_18 == V_72 )
V_10 = F_80 ( V_16 , V_8 ) ;
else if ( V_18 == V_23 )
V_10 = F_81 ( V_16 , V_8 ) ;
else {
F_16 ( V_39 , L_91 ) ;
goto V_49;
}
if ( ! V_10 )
{
F_16 ( V_39 , L_92 ) ;
goto V_49;
}
}
if ( ! V_20 && V_5 && ( V_7 != NULL ) )
{
if ( V_18 == V_72 )
V_10 = F_82 ( V_16 , V_7 ) ;
else if ( V_18 == V_23 )
V_10 = F_83 ( V_16 , V_7 ) ;
else {
F_16 ( V_39 , L_91 ) ;
goto V_49;
}
if ( ! V_10 )
{
F_16 ( V_39 , L_93 ) ;
goto V_49;
}
}
V_4 = 0 ;
V_49:
if ( V_4 )
{
F_84 ( V_39 ) ;
}
if ( ( V_57 != NULL ) && ( V_57 != V_55 ) ) F_85 ( V_57 ) ;
F_21 ( V_15 ) ;
F_21 ( V_16 ) ;
F_19 ( V_9 ) ;
F_86 ( V_8 ) ;
F_20 ( V_7 ) ;
F_87 () ;
F_88 () ;
#ifndef F_1
if ( V_3 != NULL ) F_89 ( V_3 ) ;
#endif
EXIT ( V_4 ) ;
}
static int F_59 ( T_3 * V_8 , T_4 * V_9 , int V_82 )
{
int V_83 = 0 , V_10 ;
char * V_35 , * V_84 ;
T_10 * V_85 ;
char V_86 [ 100 ] ;
int V_87 , V_88 , V_89 ;
char * type , * V_90 , * V_77 , * V_91 , * V_92 ;
T_11 * V_93 , * V_94 = NULL ;
T_12 * V_95 ;
V_77 = F_30 ( V_57 , V_59 , V_96 ) ;
if ( V_77 == NULL )
{
F_16 ( V_39 , L_94 ,
V_96 ) ;
goto V_97;
}
V_93 = F_90 ( V_57 , V_77 ) ;
if ( V_93 == NULL )
{
F_16 ( V_39 , L_95 , V_77 ) ;
goto V_97;
}
V_92 = F_30 ( V_57 , V_59 , V_98 ) ;
if ( V_92 == NULL )
V_94 = NULL ;
else
{
V_94 = F_90 ( V_57 , V_92 ) ;
if ( V_94 == NULL )
{
F_16 ( V_39 , L_95 , V_92 ) ;
goto V_97;
}
}
V_85 = V_8 -> V_73 ;
F_16 ( V_39 , L_96 ) ;
F_16 ( V_39 , L_97 ) ;
F_16 ( V_39 , L_98 ) ;
F_16 ( V_39 , L_99 ) ;
F_16 ( V_39 , L_100 ) ;
F_16 ( V_39 , L_101 ) ;
F_16 ( V_39 , L_81 ) ;
if ( ! F_62 ( V_85 -> V_99 , 0L ) ) goto V_97;
if ( F_91 ( V_93 ) )
{
V_10 = - 1 ;
V_100: for (; ; )
{
V_10 ++ ;
if ( ( int ) F_91 ( V_93 ) <= V_10 ) break;
V_95 = ( T_12 * ) F_92 ( V_93 , V_10 ) ;
V_35 = V_84 = NULL ;
type = V_95 -> V_101 ;
if( ! F_93 ( type , L_102 ) || ! F_93 ( type , L_103 ) ||
! F_93 ( type , L_104 ) ||
! F_93 ( type , L_105 ) ) continue;
for( V_35 = V_95 -> V_101 ; * V_35 ; V_35 ++ )
if ( ( * V_35 == ':' ) || ( * V_35 == ',' ) ||
( * V_35 == '.' ) ) {
V_35 ++ ;
if( * V_35 ) type = V_35 ;
break;
}
if ( ( V_87 = F_94 ( type ) ) == V_102 ) goto V_100;
sprintf ( V_86 , L_106 , V_95 -> V_101 ) ;
if ( ( V_90 = F_30 ( V_57 , V_77 , V_86 ) ) == NULL )
V_90 = L_107 ;
sprintf ( V_86 , L_108 , V_95 -> V_101 ) ;
if ( ( V_91 = F_30 ( V_57 , V_77 , V_86 ) ) == NULL )
V_91 = NULL ;
sprintf ( V_86 , L_109 , V_95 -> V_101 ) ;
V_88 = ( int ) F_43 ( V_57 , V_77 , V_86 ) ;
sprintf ( V_86 , L_110 , V_95 -> V_101 ) ;
V_89 = ( int ) F_43 ( V_57 , V_77 , V_86 ) ;
if ( ! F_95 ( V_85 -> V_103 , V_95 -> V_91 , V_90 , V_91 , V_87 ,
V_88 , V_89 ) )
goto V_97;
}
if ( F_96 ( V_85 -> V_103 -> V_104 ) == 0 )
{
F_16 ( V_39 , L_111 ) ;
goto V_97;
}
if ( V_82 )
{
if ( ( V_94 != NULL ) && ( F_91 ( V_94 ) > 0 ) )
{
F_16 ( V_39 , L_112 ) ;
F_16 ( V_39 , L_113 ) ;
}
V_10 = - 1 ;
V_105: for (; ; )
{
V_10 ++ ;
if ( ( V_94 == NULL ) || ( ( int ) F_91 ( V_94 ) <= V_10 ) )
break;
V_95 = ( T_12 * ) F_92 ( V_94 , V_10 ) ;
type = V_95 -> V_101 ;
if ( ( V_87 = F_94 ( type ) ) == V_102 )
goto V_105;
sprintf ( V_86 , L_106 , type ) ;
if ( ( V_90 = F_30 ( V_57 , V_92 , V_86 ) )
== NULL )
V_90 = L_107 ;
sprintf ( V_86 , L_108 , type ) ;
if ( ( V_91 = F_30 ( V_57 , V_92 , V_86 ) )
== NULL )
V_91 = NULL ;
sprintf ( V_86 , L_109 , type ) ;
V_88 = ( int ) F_43 ( V_57 , V_92 , V_86 ) ;
sprintf ( V_86 , L_110 , type ) ;
V_89 = ( int ) F_43 ( V_57 , V_92 , V_86 ) ;
if ( ! F_97 ( V_85 -> V_106 ,
V_95 -> V_91 , V_90 , V_91 , V_87 , V_88 , V_89 ) )
goto V_97;
}
}
}
else
{
F_16 ( V_39 , L_114 ) ;
goto V_97;
}
F_98 ( V_8 , V_9 ) ;
V_83 = 1 ;
V_97:
return ( V_83 ) ;
}
static int F_95 ( T_13 * V_81 , char * V_21 , char * V_90 , char * V_91 ,
int V_87 , int V_88 , int V_89 )
{
int V_10 , V_107 , V_83 = 0 ;
T_14 * V_108 = NULL ;
T_8 char V_86 [ 1024 ] ;
F_16 ( V_39 , L_115 , V_21 , V_90 ) ;
F_40 ( V_39 ) ;
if ( V_91 != NULL )
{
strcpy ( V_86 , V_91 ) ;
strcat ( V_86 , L_90 ) ;
F_16 ( V_39 , L_116 , V_91 ) ;
}
else
{
V_86 [ 0 ] = '\0' ;
fgets ( V_86 , 1024 , V_71 ) ;
}
if ( V_86 [ 0 ] == '\0' ) return ( 0 ) ;
else if ( V_86 [ 0 ] == '\n' )
{
if ( ( V_90 == NULL ) || ( V_90 [ 0 ] == '\0' ) )
return ( 1 ) ;
strcpy ( V_86 , V_90 ) ;
strcat ( V_86 , L_90 ) ;
}
else if ( ( V_86 [ 0 ] == '.' ) && ( V_86 [ 1 ] == '\n' ) ) return ( 1 ) ;
V_10 = strlen ( V_86 ) ;
if ( V_86 [ V_10 - 1 ] != '\n' )
{
F_16 ( V_39 , L_117 ) ;
return ( 0 ) ;
}
V_86 [ -- V_10 ] = '\0' ;
V_107 = F_99 ( ( unsigned char * ) V_86 , - 1 ) ;
if ( F_100 ( V_87 , & V_107 , V_10 , V_88 , V_89 ) == 0 )
goto V_97;
if ( ( V_108 = F_101 ( NULL , V_87 , V_107 , ( unsigned char * ) V_86 ,
strlen ( V_86 ) ) )
== NULL ) goto V_97;
if ( ! F_102 ( V_81 , V_108 , F_103 ( V_81 ) , 0 ) )
goto V_97;
V_83 = 1 ;
V_97:
if ( V_108 != NULL ) F_104 ( V_108 ) ;
return ( V_83 ) ;
}
static void T_15 V_67 ( int V_35 , int V_81 , char * V_109 )
{
char V_110 = '*' ;
if ( V_35 == 0 ) V_110 = '.' ;
if ( V_35 == 1 ) V_110 = '+' ;
if ( V_35 == 2 ) V_110 = '*' ;
if ( V_35 == 3 ) V_110 = '\n' ;
F_105 ( ( T_5 * ) V_109 , & V_110 , 1 ) ;
F_40 ( ( T_5 * ) V_109 ) ;
#ifdef F_106
V_35 = V_81 ;
#endif
}
static int F_100 ( int V_87 , int * type , int V_111 , int V_88 , int V_89 )
{
if ( V_87 == V_112 )
* type = V_113 ;
if ( ( V_87 == V_114 ) && ( * type == V_113 ) )
* type = V_115 ;
if ( ( V_87 == V_116 ) &&
( * type == V_113 ) )
* type = V_115 ;
if ( ( V_87 == V_117 ) &&
( * type == V_115 ) )
{
F_16 ( V_39 , L_118 ) ;
return ( 0 ) ;
}
if ( V_87 == V_117 )
* type = V_113 ;
if ( V_111 < V_88 )
{
F_16 ( V_39 , L_119 , V_88 ) ;
return ( 0 ) ;
}
if ( ( V_89 != 0 ) && ( V_111 > V_89 ) )
{
F_16 ( V_39 , L_120 , V_89 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_93 ( char * V_118 , char * V_49 )
{
int V_119 , V_120 ;
char * V_77 ;
V_119 = strlen ( V_49 ) ;
V_120 = strlen ( V_118 ) ;
if( V_119 > V_120 ) return 1 ;
V_77 = V_118 + V_120 - V_119 ;
return strcmp ( V_77 , V_49 ) ;
}
static int F_32 ( T_16 * V_121 )
{
char * V_35 ;
T_11 * V_122 ;
T_12 * V_123 ;
int V_10 ;
if( ! ( V_35 = F_30 ( V_121 , NULL , L_121 ) ) ) return 1 ;
if( ! ( V_122 = F_90 ( V_121 , V_35 ) ) ) {
F_16 ( V_39 , L_122 , V_35 ) ;
return 0 ;
}
for( V_10 = 0 ; V_10 < F_91 ( V_122 ) ; V_10 ++ ) {
V_123 = ( T_12 * ) F_92 ( V_122 , V_10 ) ;
if( F_107 ( V_123 -> V_91 , V_123 -> V_101 , V_123 -> V_101 ) == V_102 ) {
F_16 ( V_39 , L_123 ,
V_123 -> V_101 , V_123 -> V_91 ) ;
return 0 ;
}
}
return 1 ;
}
