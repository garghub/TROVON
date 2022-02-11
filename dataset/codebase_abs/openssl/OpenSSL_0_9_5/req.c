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
int V_24 = 0 , V_25 = 0 , V_26 = 0 ;
char * V_27 , * V_28 , * V_29 , * V_30 = NULL , * V_31 = NULL , * V_32 = NULL ;
char * V_33 = NULL ;
char * V_34 = NULL ;
T_6 * V_35 = NULL ;
int V_36 = 0 ;
char * V_37 = NULL , * V_38 = NULL ;
char * V_39 = NULL , * V_40 = NULL ;
char * V_41 ;
const T_7 * V_42 = NULL , * V_43 = F_2 () ;
#ifndef F_3
T_8 char V_44 [ 256 ] ;
#endif
V_45 = NULL ;
#ifndef F_4
V_35 = F_5 () ;
#endif
F_6 () ;
if ( V_46 == NULL )
if ( ( V_46 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_46 , V_47 , V_48 | V_49 ) ;
V_27 = NULL ;
V_28 = NULL ;
V_17 = V_23 ;
V_18 = V_23 ;
V_29 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_17 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_18 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_30 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
V_14 = V_51 ;
V_12 = 1 ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_31 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_22 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_27 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_28 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_32 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_37 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_38 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
int V_52 ;
if ( -- V_1 < 1 ) goto V_50;
V_41 = * ( ++ V_2 ) ;
V_52 = V_41 [ 0 ] >= '0' && V_41 [ 0 ] <= '9' ;
if ( strncmp ( L_13 , V_41 , 4 ) == 0 || V_52 )
{
V_14 = V_51 ;
if( ! V_52 )
V_41 += 4 ;
V_13 = atoi ( V_41 ) ;
}
else
#ifndef F_1
if ( strncmp ( L_14 , V_41 , 4 ) == 0 )
{
T_2 * V_53 = NULL ;
T_4 * V_54 ;
V_14 = V_55 ;
V_41 += 4 ;
if ( ( V_15 = F_11 ( V_41 , L_15 ) ) == NULL )
{
perror ( V_41 ) ;
goto V_56;
}
if ( ( V_3 = F_12 ( V_15 , NULL , NULL , NULL ) ) == NULL )
{
F_13 () ;
( void ) F_14 ( V_15 ) ;
if ( ( V_53 = F_15 ( V_15 , NULL , NULL , NULL ) ) == NULL )
{
F_16 ( V_46 , L_16 ) ;
goto V_56;
}
V_54 = F_17 ( V_53 ) ;
if ( V_54 -> type == V_57 )
V_3 = F_18 ( V_54 -> V_9 . V_58 ) ;
F_19 ( V_54 ) ;
F_20 ( V_53 ) ;
if ( V_3 == NULL )
{
F_16 ( V_46 , L_17 ) ;
goto V_56;
}
}
F_21 ( V_15 ) ;
V_13 = F_22 ( V_3 -> V_41 ) ;
V_15 = NULL ;
}
else
#endif
#ifndef F_23
if ( strncmp ( L_18 , V_41 , 4 ) == 0 )
{
V_14 = V_59 ;
V_41 += 3 ;
}
else
#endif
V_14 = V_51 ;
V_12 = 1 ;
}
else if ( strcmp ( * V_2 , L_19 ) == 0 )
V_26 = 1 ;
else if ( strcmp ( * V_2 , L_20 ) == 0 )
V_36 = 1 ;
else if ( strcmp ( * V_2 , L_21 ) == 0 )
V_19 = 1 ;
else if ( strcmp ( * V_2 , L_22 ) == 0 )
V_24 = 1 ;
else if ( strcmp ( * V_2 , L_23 ) == 0 )
V_20 = 1 ;
else if ( strcmp ( * V_2 , L_24 ) == 0 )
V_21 = 1 ;
else if ( strcmp ( * V_2 , L_25 ) == 0 )
V_5 = 1 ;
else if ( strcmp ( * V_2 , L_26 ) == 0 )
V_25 = 1 ;
else if ( strcmp ( * V_2 , L_27 ) == 0 )
V_25 = 0 ;
else if ( strcmp ( * V_2 , L_28 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_6 = atoi ( * ( ++ V_2 ) ) ;
if ( V_6 == 0 ) V_6 = 30 ;
}
else if ( ( V_42 = F_24 ( & ( ( * V_2 ) [ 1 ] ) ) ) != NULL )
{
V_43 = V_42 ;
}
else if ( strcmp ( * V_2 , L_29 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_33 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_30 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_50;
V_34 = * ( ++ V_2 ) ;
}
else
{
F_16 ( V_46 , L_31 , * V_2 ) ;
V_11 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_11 )
{
V_50:
F_16 ( V_46 , L_32 , V_29 ) ;
F_16 ( V_46 , L_33 ) ;
F_16 ( V_46 , L_34 ) ;
F_16 ( V_46 , L_35 ) ;
F_16 ( V_46 , L_36 ) ;
F_16 ( V_46 , L_37 ) ;
F_16 ( V_46 , L_38 ) ;
F_16 ( V_46 , L_39 ) ;
F_16 ( V_46 , L_40 ) ;
F_16 ( V_46 , L_41 ) ;
F_16 ( V_46 , L_42 ) ;
F_16 ( V_46 , L_43 ) ;
F_16 ( V_46 , L_44 ) ;
F_16 ( V_46 , L_45 ) ;
F_16 ( V_46 , L_46 ) ;
F_16 ( V_46 , L_47 ) ;
F_16 ( V_46 , L_48 ) ;
F_16 ( V_46 , L_49 ) ;
F_16 ( V_46 , L_50 ) ;
F_16 ( V_46 , L_51 ) ;
F_16 ( V_46 , L_52 ) ;
F_16 ( V_46 , L_53 ) ;
F_16 ( V_46 , L_54 ) ;
F_16 ( V_46 , L_55 ) ;
F_16 ( V_46 , L_56 ) ;
F_16 ( V_46 , L_57 ) ;
goto V_56;
}
F_25 () ;
if( ! F_26 ( V_46 , V_37 , V_38 , & V_39 , & V_40 ) ) {
F_16 ( V_46 , L_58 ) ;
goto V_56;
}
#ifndef F_3
V_41 = getenv ( L_59 ) ;
if ( V_41 == NULL )
V_41 = getenv ( L_60 ) ;
if ( V_41 == NULL )
{
strcpy ( V_44 , F_27 () ) ;
#ifndef F_28
strcat ( V_44 , L_61 ) ;
#endif
strcat ( V_44 , V_60 ) ;
V_41 = V_44 ;
}
V_61 = V_41 ;
V_62 = F_29 ( V_62 , V_41 , NULL ) ;
#endif
if ( V_31 != NULL )
{
long V_63 ;
F_16 ( V_46 , L_62 , V_31 ) ;
V_45 = F_29 ( NULL , V_31 , & V_63 ) ;
if ( V_45 == NULL )
{
F_16 ( V_46 , L_63 , V_63 , V_31 ) ;
goto V_56;
}
}
else
{
V_45 = V_62 ;
F_16 ( V_46 , L_62 ,
V_61 ) ;
if ( V_45 == NULL )
{
F_16 ( V_46 , L_64 ) ;
}
}
if ( V_45 != NULL )
{
V_41 = F_30 ( V_45 , NULL , L_65 ) ;
if ( V_41 != NULL )
{
T_5 * V_64 ;
V_64 = F_11 ( V_41 , L_15 ) ;
if ( V_64 == NULL )
{
}
else
{
F_31 ( V_64 ) ;
F_21 ( V_64 ) ;
}
}
}
if( ! F_32 ( V_45 ) ) goto V_56;
if ( ( V_42 == NULL ) &&
( ( V_41 = F_30 ( V_45 , V_65 , L_66 ) ) != NULL ) )
{
if ( ( V_42 = F_24 ( V_41 ) ) != NULL )
V_43 = V_42 ;
}
if( ! V_33 )
V_33 = F_30 ( V_45 , V_65 , V_66 ) ;
if( V_33 ) {
T_9 V_67 ;
F_33 ( & V_67 ) ;
F_34 ( & V_67 , V_45 ) ;
if( ! F_35 ( V_45 , & V_67 , V_33 , NULL ) ) {
F_16 ( V_46 ,
L_67 , V_33 ) ;
goto V_56;
}
}
if( ! V_39 )
V_39 = F_30 ( V_45 , V_65 , L_68 ) ;
if( ! V_40 )
V_40 = F_30 ( V_45 , V_65 , L_69 ) ;
V_41 = F_30 ( V_45 , V_65 , V_68 ) ;
if( V_41 && ! F_36 ( V_41 ) ) {
F_16 ( V_46 , L_70 , V_41 ) ;
goto V_56;
}
if( ! V_34 )
V_34 = F_30 ( V_45 , V_65 , V_69 ) ;
if( V_34 ) {
T_9 V_67 ;
F_33 ( & V_67 ) ;
F_34 ( & V_67 , V_45 ) ;
if( ! F_35 ( V_45 , & V_67 , V_34 , NULL ) ) {
F_16 ( V_46 ,
L_71 ,
V_34 ) ;
goto V_56;
}
}
V_15 = F_7 ( F_8 () ) ;
V_16 = F_7 ( F_8 () ) ;
if ( ( V_15 == NULL ) || ( V_16 == NULL ) )
goto V_56;
if ( V_30 != NULL )
{
if ( F_37 ( V_15 , V_30 ) <= 0 )
{
perror ( V_30 ) ;
goto V_56;
}
if ( V_22 == V_70 )
V_9 = F_38 ( V_15 , NULL ) ;
else if ( V_22 == V_23 )
{
V_9 = F_39 ( V_15 , NULL , NULL , V_39 ) ;
}
else
{
F_16 ( V_46 , L_72 ) ;
goto V_56;
}
if ( V_9 == NULL )
{
F_16 ( V_46 , L_73 ) ;
goto V_56;
}
}
if ( V_12 && ( V_9 == NULL ) )
{
char * V_71 = F_30 ( V_45 , V_65 , L_74 ) ;
F_40 ( V_71 , V_46 , 0 ) ;
if ( V_13 <= 0 )
{
V_13 = ( int ) F_41 ( V_45 , V_65 , V_72 ) ;
if ( V_13 <= 0 )
V_13 = V_73 ;
}
if ( V_13 < V_74 )
{
F_16 ( V_46 , L_75 ) ;
F_16 ( V_46 , L_76 , V_74 , V_13 ) ;
goto V_56;
}
F_16 ( V_46 , L_77 ,
V_13 , ( V_14 == V_51 ) ? L_78 : L_79 ) ;
if ( ( V_9 = F_42 () ) == NULL ) goto V_56;
#ifndef F_43
if ( V_14 == V_51 )
{
if ( ! F_44 ( V_9 ,
F_45 ( V_13 , 0x10001 ,
V_75 , V_46 ) ) )
goto V_56;
}
else
#endif
#ifndef F_1
if ( V_14 == V_55 )
{
if ( ! F_46 ( V_3 ) ) goto V_56;
if ( ! F_47 ( V_9 , V_3 ) ) goto V_56;
V_3 = NULL ;
}
#endif
F_48 ( V_71 , V_46 ) ;
if ( V_9 == NULL ) goto V_56;
if ( V_32 == NULL )
V_32 = F_30 ( V_45 , V_65 , V_76 ) ;
if ( V_32 == NULL )
{
F_16 ( V_46 , L_80 ) ;
F_9 ( V_16 , stdout , V_48 ) ;
}
else
{
F_16 ( V_46 , L_81 , V_32 ) ;
if ( F_49 ( V_16 , V_32 ) <= 0 )
{
perror ( V_32 ) ;
goto V_56;
}
}
V_41 = F_30 ( V_45 , V_65 , L_82 ) ;
if ( V_41 == NULL )
V_41 = F_30 ( V_45 , V_65 , L_83 ) ;
if ( ( V_41 != NULL ) && ( strcmp ( V_41 , L_84 ) == 0 ) )
V_35 = NULL ;
if ( V_24 ) V_35 = NULL ;
V_10 = 0 ;
V_77:
if ( ! F_50 ( V_16 , V_9 , V_35 ,
NULL , 0 , NULL , V_40 ) )
{
if ( ( F_51 ( F_52 () ) ==
V_78 ) && ( V_10 < 3 ) )
{
F_13 () ;
V_10 ++ ;
goto V_77;
}
goto V_56;
}
F_16 ( V_46 , L_85 ) ;
}
if ( ! V_12 )
{
V_25 = - 1 ;
if ( V_27 == NULL )
F_9 ( V_15 , V_79 , V_48 ) ;
else
{
if ( F_37 ( V_15 , V_27 ) <= 0 )
{
perror ( V_27 ) ;
goto V_56;
}
}
if ( V_17 == V_70 )
V_8 = F_53 ( V_15 , NULL ) ;
else if ( V_17 == V_23 )
V_8 = F_54 ( V_15 , NULL , NULL , NULL ) ;
else
{
F_16 ( V_46 , L_72 ) ;
goto V_56;
}
if ( V_8 == NULL )
{
F_16 ( V_46 , L_86 ) ;
goto V_56;
}
}
if ( V_12 || V_5 )
{
#ifndef F_1
if ( V_9 -> type == V_57 )
V_43 = F_55 () ;
#endif
if ( V_9 == NULL )
{
F_16 ( V_46 , L_87 ) ;
goto V_56;
}
if ( V_8 == NULL )
{
V_8 = F_56 () ;
if ( V_8 == NULL )
{
goto V_56;
}
V_10 = F_57 ( V_8 , V_9 , ! V_5 ) ;
if ( V_25 >= 0 )
V_8 -> V_80 -> V_81 = V_25 ;
if ( ! V_10 )
{
F_16 ( V_46 , L_88 ) ;
goto V_56;
}
}
if ( V_5 )
{
T_4 * V_82 ;
T_9 V_83 ;
if ( ( V_7 = F_58 () ) == NULL ) goto V_56;
if( ! F_59 ( V_7 , 2 ) ) goto V_56;
F_60 ( F_61 ( V_7 ) , 0L ) ;
F_62 ( V_7 ,
F_63 ( V_8 ) ) ;
F_64 ( F_65 ( V_7 ) , 0 ) ;
F_64 ( F_66 ( V_7 ) ,
( long ) 60 * 60 * 24 * V_6 ) ;
F_67 ( V_7 ,
F_63 ( V_8 ) ) ;
V_82 = F_68 ( V_8 ) ;
F_69 ( V_7 , V_82 ) ;
F_19 ( V_82 ) ;
F_70 ( & V_83 , V_7 , V_7 , NULL , NULL , 0 ) ;
F_34 ( & V_83 , V_45 ) ;
if( V_33 && ! F_35 ( V_45 ,
& V_83 , V_33 , V_7 ) )
{
F_16 ( V_46 ,
L_67 ,
V_33 ) ;
goto V_56;
}
if ( ! ( V_10 = F_71 ( V_7 , V_9 , V_43 ) ) )
goto V_56;
}
else
{
T_9 V_83 ;
F_70 ( & V_83 , NULL , NULL , V_8 , NULL , 0 ) ;
F_34 ( & V_83 , V_45 ) ;
if( V_34 && ! F_72 ( V_45 ,
& V_83 , V_34 , V_8 ) )
{
F_16 ( V_46 ,
L_67 ,
V_34 ) ;
goto V_56;
}
if ( ! ( V_10 = F_73 ( V_8 , V_9 , V_43 ) ) )
goto V_56;
}
}
if ( V_19 && ! V_5 )
{
int V_84 = 0 ;
if ( V_9 == NULL )
{
V_9 = F_68 ( V_8 ) ;
V_84 = 1 ;
if ( V_9 == NULL ) goto V_56;
}
V_10 = F_74 ( V_8 , V_9 ) ;
if ( V_84 ) {
F_19 ( V_9 ) ;
V_9 = NULL ;
}
if ( V_10 < 0 )
{
goto V_56;
}
else if ( V_10 == 0 )
{
F_16 ( V_46 , L_89 ) ;
}
else
F_16 ( V_46 , L_90 ) ;
}
if ( V_20 && ! V_21 && ! V_36 )
{
V_4 = 0 ;
goto V_56;
}
if ( V_28 == NULL )
F_9 ( V_16 , stdout , V_48 ) ;
else
{
if ( ( V_32 != NULL ) && ( strcmp ( V_28 , V_32 ) == 0 ) )
V_10 = ( int ) F_75 ( V_16 , V_28 ) ;
else
V_10 = ( int ) F_49 ( V_16 , V_28 ) ;
if ( ! V_10 )
{
perror ( V_28 ) ;
goto V_56;
}
}
if ( V_21 )
{
if ( V_5 )
F_76 ( V_16 , V_7 ) ;
else
F_77 ( V_16 , V_8 ) ;
}
if ( V_36 )
{
T_4 * V_85 ;
if ( V_5 )
V_85 = F_17 ( V_7 ) ;
else
V_85 = F_68 ( V_8 ) ;
if ( V_85 == NULL )
{
fprintf ( stdout , L_91 ) ;
goto V_56;
}
fprintf ( stdout , L_92 ) ;
#ifndef F_43
if ( V_85 -> type == V_86 )
F_78 ( V_16 , V_85 -> V_9 . V_87 -> V_88 ) ;
else
#endif
fprintf ( stdout , L_93 ) ;
fprintf ( stdout , L_94 ) ;
}
if ( ! V_20 && ! V_5 )
{
if ( V_18 == V_70 )
V_10 = F_79 ( V_16 , V_8 ) ;
else if ( V_18 == V_23 ) {
if( V_26 ) V_10 = F_80 ( V_16 , V_8 ) ;
else V_10 = F_81 ( V_16 , V_8 ) ;
} else {
F_16 ( V_46 , L_95 ) ;
goto V_56;
}
if ( ! V_10 )
{
F_16 ( V_46 , L_96 ) ;
goto V_56;
}
}
if ( ! V_20 && V_5 && ( V_7 != NULL ) )
{
if ( V_18 == V_70 )
V_10 = F_82 ( V_16 , V_7 ) ;
else if ( V_18 == V_23 )
V_10 = F_83 ( V_16 , V_7 ) ;
else {
F_16 ( V_46 , L_95 ) ;
goto V_56;
}
if ( ! V_10 )
{
F_16 ( V_46 , L_97 ) ;
goto V_56;
}
}
V_4 = 0 ;
V_56:
if ( V_4 )
{
F_84 ( V_46 ) ;
}
if ( ( V_45 != NULL ) && ( V_45 != V_62 ) ) F_85 ( V_45 ) ;
F_21 ( V_15 ) ;
F_21 ( V_16 ) ;
F_19 ( V_9 ) ;
F_86 ( V_8 ) ;
F_20 ( V_7 ) ;
if( V_39 ) Free ( V_39 ) ;
if( V_40 ) Free ( V_40 ) ;
F_87 () ;
#ifndef F_1
if ( V_3 != NULL ) F_88 ( V_3 ) ;
#endif
EXIT ( V_4 ) ;
}
static int F_57 ( T_3 * V_8 , T_4 * V_9 , int V_89 )
{
int V_90 = 0 , V_10 ;
char V_91 = 0 ;
F_89 ( V_92 ) * V_93 , * V_94 = NULL ;
char * V_84 , * V_95 , * V_96 ;
V_84 = F_30 ( V_45 , V_65 , V_97 ) ;
if( ( V_84 != NULL ) && ! strcmp ( V_84 , L_84 ) ) V_91 = 1 ;
V_95 = F_30 ( V_45 , V_65 , V_98 ) ;
if ( V_95 == NULL )
{
F_16 ( V_46 , L_98 ,
V_98 ) ;
goto V_99;
}
V_93 = F_90 ( V_45 , V_95 ) ;
if ( V_93 == NULL )
{
F_16 ( V_46 , L_99 , V_95 ) ;
goto V_99;
}
V_96 = F_30 ( V_45 , V_65 , V_100 ) ;
if ( V_96 == NULL )
V_94 = NULL ;
else
{
V_94 = F_90 ( V_45 , V_96 ) ;
if ( V_94 == NULL )
{
F_16 ( V_46 , L_99 , V_96 ) ;
goto V_99;
}
}
if ( ! F_91 ( V_8 , 0L ) ) goto V_99;
if( V_91 ) V_10 = F_92 ( V_8 , V_93 , V_94 , V_89 ) ;
else V_10 = F_93 ( V_8 , V_93 , V_95 , V_94 , V_96 , V_89 ) ;
if( ! V_10 ) goto V_99;
F_94 ( V_8 , V_9 ) ;
V_90 = 1 ;
V_99:
return ( V_90 ) ;
}
static int F_95 ( T_10 * V_88 , char * V_21 , char * V_101 , char * V_102 ,
int V_103 , int V_104 , int V_105 )
{
int V_10 , V_90 = 0 ;
T_8 char V_106 [ 1024 ] ;
V_107:
F_16 ( V_46 , L_100 , V_21 , V_101 ) ;
( void ) F_96 ( V_46 ) ;
if ( V_102 != NULL )
{
strcpy ( V_106 , V_102 ) ;
strcat ( V_106 , L_94 ) ;
F_16 ( V_46 , L_101 , V_102 ) ;
}
else
{
V_106 [ 0 ] = '\0' ;
fgets ( V_106 , 1024 , V_79 ) ;
}
if ( V_106 [ 0 ] == '\0' ) return ( 0 ) ;
else if ( V_106 [ 0 ] == '\n' )
{
if ( ( V_101 == NULL ) || ( V_101 [ 0 ] == '\0' ) )
return ( 1 ) ;
strcpy ( V_106 , V_101 ) ;
strcat ( V_106 , L_94 ) ;
}
else if ( ( V_106 [ 0 ] == '.' ) && ( V_106 [ 1 ] == '\n' ) ) return ( 1 ) ;
V_10 = strlen ( V_106 ) ;
if ( V_106 [ V_10 - 1 ] != '\n' )
{
F_16 ( V_46 , L_102 ) ;
return ( 0 ) ;
}
V_106 [ -- V_10 ] = '\0' ;
#ifdef F_97
F_98 ( V_106 , V_106 , V_10 ) ;
#endif
if( ! F_99 ( V_10 , V_104 , V_105 ) ) goto V_107;
if ( ! F_100 ( V_88 , V_103 , V_108 ,
( unsigned char * ) V_106 , - 1 , - 1 , 0 ) ) goto V_99;
V_90 = 1 ;
V_99:
return ( V_90 ) ;
}
static int F_101 ( T_3 * V_8 , char * V_21 ,
char * V_101 , char * V_102 , int V_103 , int V_104 ,
int V_105 )
{
int V_10 ;
static char V_106 [ 1024 ] ;
V_107:
F_16 ( V_46 , L_100 , V_21 , V_101 ) ;
( void ) F_96 ( V_46 ) ;
if ( V_102 != NULL )
{
strcpy ( V_106 , V_102 ) ;
strcat ( V_106 , L_94 ) ;
F_16 ( V_46 , L_101 , V_102 ) ;
}
else
{
V_106 [ 0 ] = '\0' ;
fgets ( V_106 , 1024 , V_79 ) ;
}
if ( V_106 [ 0 ] == '\0' ) return ( 0 ) ;
else if ( V_106 [ 0 ] == '\n' )
{
if ( ( V_101 == NULL ) || ( V_101 [ 0 ] == '\0' ) )
return ( 1 ) ;
strcpy ( V_106 , V_101 ) ;
strcat ( V_106 , L_94 ) ;
}
else if ( ( V_106 [ 0 ] == '.' ) && ( V_106 [ 1 ] == '\n' ) ) return ( 1 ) ;
V_10 = strlen ( V_106 ) ;
if ( V_106 [ V_10 - 1 ] != '\n' )
{
F_16 ( V_46 , L_102 ) ;
return ( 0 ) ;
}
V_106 [ -- V_10 ] = '\0' ;
if( ! F_99 ( V_10 , V_104 , V_105 ) ) goto V_107;
if( ! F_102 ( V_8 , V_103 , V_108 ,
( unsigned char * ) V_106 , - 1 ) ) {
F_16 ( V_46 , L_103 ) ;
F_84 ( V_46 ) ;
goto V_99;
}
return ( 1 ) ;
V_99:
return ( 0 ) ;
}
static void T_11 V_75 ( int V_41 , int V_88 , void * V_109 )
{
char V_110 = '*' ;
if ( V_41 == 0 ) V_110 = '.' ;
if ( V_41 == 1 ) V_110 = '+' ;
if ( V_41 == 2 ) V_110 = '*' ;
if ( V_41 == 3 ) V_110 = '\n' ;
F_103 ( ( T_5 * ) V_109 , & V_110 , 1 ) ;
( void ) F_96 ( ( T_5 * ) V_109 ) ;
#ifdef F_104
V_41 = V_88 ;
#endif
}
static int F_99 ( int V_111 , int V_104 , int V_105 )
{
if ( V_111 < V_104 )
{
F_16 ( V_46 , L_104 , V_104 ) ;
return ( 0 ) ;
}
if ( ( V_105 != 0 ) && ( V_111 > V_105 ) )
{
F_16 ( V_46 , L_105 , V_105 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_105 ( char * V_112 , char * V_56 )
{
int V_113 , V_114 ;
char * V_84 ;
V_113 = strlen ( V_56 ) ;
V_114 = strlen ( V_112 ) ;
if( V_113 > V_114 ) return 1 ;
V_84 = V_112 + V_114 - V_113 ;
return strcmp ( V_84 , V_56 ) ;
}
static int F_32 ( T_12 * V_115 )
{
char * V_41 ;
F_89 ( V_92 ) * V_116 ;
V_92 * V_117 ;
int V_10 ;
if( ! ( V_41 = F_30 ( V_115 , NULL , L_106 ) ) ) return 1 ;
if( ! ( V_116 = F_90 ( V_115 , V_41 ) ) ) {
F_16 ( V_46 , L_107 , V_41 ) ;
return 0 ;
}
for( V_10 = 0 ; V_10 < F_106 ( V_116 ) ; V_10 ++ ) {
V_117 = F_107 ( V_116 , V_10 ) ;
if( F_108 ( V_117 -> V_102 , V_117 -> V_118 , V_117 -> V_118 ) == V_119 ) {
F_16 ( V_46 , L_108 ,
V_117 -> V_118 , V_117 -> V_102 ) ;
return 0 ;
}
}
return 1 ;
}
