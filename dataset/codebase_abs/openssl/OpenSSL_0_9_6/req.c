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
char * V_37 = NULL ;
char * V_38 = NULL , * V_39 = NULL ;
char * V_40 = NULL , * V_41 = NULL ;
char * V_42 ;
const T_7 * V_43 = NULL , * V_44 = F_2 () ;
#ifndef F_3
T_8 char V_45 [ 256 ] ;
#endif
V_46 = NULL ;
#ifndef F_4
V_35 = F_5 () ;
#endif
F_6 () ;
if ( V_47 == NULL )
if ( ( V_47 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_47 , V_48 , V_49 | V_50 ) ;
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
if ( -- V_1 < 1 ) goto V_51;
V_17 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_18 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_30 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
V_14 = V_52 ;
V_12 = 1 ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_31 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_22 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_27 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_28 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_32 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_38 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_39 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_37 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
int V_53 ;
if ( -- V_1 < 1 ) goto V_51;
V_42 = * ( ++ V_2 ) ;
V_53 = V_42 [ 0 ] >= '0' && V_42 [ 0 ] <= '9' ;
if ( strncmp ( L_14 , V_42 , 4 ) == 0 || V_53 )
{
V_14 = V_52 ;
if( ! V_53 )
V_42 += 4 ;
V_13 = atoi ( V_42 ) ;
}
else
#ifndef F_1
if ( strncmp ( L_15 , V_42 , 4 ) == 0 )
{
T_2 * V_54 = NULL ;
T_4 * V_55 ;
V_14 = V_56 ;
V_42 += 4 ;
if ( ( V_15 = F_11 ( V_42 , L_16 ) ) == NULL )
{
perror ( V_42 ) ;
goto V_57;
}
if ( ( V_3 = F_12 ( V_15 , NULL , NULL , NULL ) ) == NULL )
{
F_13 () ;
( void ) F_14 ( V_15 ) ;
if ( ( V_54 = F_15 ( V_15 , NULL , NULL , NULL ) ) == NULL )
{
F_16 ( V_47 , L_17 ) ;
goto V_57;
}
V_55 = F_17 ( V_54 ) ;
if ( V_55 -> type == V_58 )
V_3 = F_18 ( V_55 -> V_9 . V_59 ) ;
F_19 ( V_55 ) ;
F_20 ( V_54 ) ;
if ( V_3 == NULL )
{
F_16 ( V_47 , L_18 ) ;
goto V_57;
}
}
F_21 ( V_15 ) ;
V_13 = F_22 ( V_3 -> V_42 ) ;
V_15 = NULL ;
}
else
#endif
#ifndef F_23
if ( strncmp ( L_19 , V_42 , 4 ) == 0 )
{
V_14 = V_60 ;
V_42 += 3 ;
}
else
#endif
V_14 = V_52 ;
V_12 = 1 ;
}
else if ( strcmp ( * V_2 , L_20 ) == 0 )
V_26 = 1 ;
else if ( strcmp ( * V_2 , L_21 ) == 0 )
V_36 = 1 ;
else if ( strcmp ( * V_2 , L_22 ) == 0 )
V_19 = 1 ;
else if ( strcmp ( * V_2 , L_23 ) == 0 )
V_24 = 1 ;
else if ( strcmp ( * V_2 , L_24 ) == 0 )
V_20 = 1 ;
else if ( strcmp ( * V_2 , L_25 ) == 0 )
V_21 = 1 ;
else if ( strcmp ( * V_2 , L_26 ) == 0 )
V_5 = 1 ;
else if ( strcmp ( * V_2 , L_27 ) == 0 )
V_25 = 1 ;
else if ( strcmp ( * V_2 , L_28 ) == 0 )
V_25 = 0 ;
else if ( strcmp ( * V_2 , L_29 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_6 = atoi ( * ( ++ V_2 ) ) ;
if ( V_6 == 0 ) V_6 = 30 ;
}
else if ( ( V_43 = F_24 ( & ( ( * V_2 ) [ 1 ] ) ) ) != NULL )
{
V_44 = V_43 ;
}
else if ( strcmp ( * V_2 , L_30 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_33 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_31 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_51;
V_34 = * ( ++ V_2 ) ;
}
else
{
F_16 ( V_47 , L_32 , * V_2 ) ;
V_11 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_11 )
{
V_51:
F_16 ( V_47 , L_33 , V_29 ) ;
F_16 ( V_47 , L_34 ) ;
F_16 ( V_47 , L_35 ) ;
F_16 ( V_47 , L_36 ) ;
F_16 ( V_47 , L_37 ) ;
F_16 ( V_47 , L_38 ) ;
F_16 ( V_47 , L_39 ) ;
F_16 ( V_47 , L_40 ) ;
F_16 ( V_47 , L_41 ) ;
F_16 ( V_47 , L_42 ) ;
F_16 ( V_47 , L_43 ) ;
F_16 ( V_47 , L_44 ) ;
F_16 ( V_47 , L_45 ) ;
F_16 ( V_47 , L_46 ) ;
F_16 ( V_47 , L_47 , V_61 , V_61 ) ;
F_16 ( V_47 , L_48 ) ;
F_16 ( V_47 , L_49 ) ;
F_16 ( V_47 , L_50 ) ;
F_16 ( V_47 , L_51 ) ;
F_16 ( V_47 , L_52 ) ;
F_16 ( V_47 , L_53 ) ;
F_16 ( V_47 , L_54 ) ;
F_16 ( V_47 , L_55 ) ;
F_16 ( V_47 , L_56 ) ;
F_16 ( V_47 , L_57 ) ;
F_16 ( V_47 , L_58 ) ;
F_16 ( V_47 , L_59 ) ;
F_16 ( V_47 , L_60 ) ;
F_16 ( V_47 , L_61 ) ;
goto V_57;
}
F_25 () ;
if( ! F_26 ( V_47 , V_38 , V_39 , & V_40 , & V_41 ) ) {
F_16 ( V_47 , L_62 ) ;
goto V_57;
}
#ifndef F_3
V_42 = getenv ( L_63 ) ;
if ( V_42 == NULL )
V_42 = getenv ( L_64 ) ;
if ( V_42 == NULL )
{
strcpy ( V_45 , F_27 () ) ;
#ifndef F_28
strcat ( V_45 , L_65 ) ;
#endif
strcat ( V_45 , V_62 ) ;
V_42 = V_45 ;
}
V_63 = V_42 ;
V_64 = F_29 ( V_64 , V_42 , NULL ) ;
#endif
if ( V_31 != NULL )
{
long V_65 ;
F_16 ( V_47 , L_66 , V_31 ) ;
V_46 = F_29 ( NULL , V_31 , & V_65 ) ;
if ( V_46 == NULL )
{
F_16 ( V_47 , L_67 , V_65 , V_31 ) ;
goto V_57;
}
}
else
{
V_46 = V_64 ;
F_16 ( V_47 , L_66 ,
V_63 ) ;
if ( V_46 == NULL )
{
F_16 ( V_47 , L_68 ) ;
}
}
if ( V_46 != NULL )
{
V_42 = F_30 ( V_46 , NULL , L_69 ) ;
if ( V_42 != NULL )
{
T_5 * V_66 ;
V_66 = F_11 ( V_42 , L_16 ) ;
if ( V_66 == NULL )
{
}
else
{
F_31 ( V_66 ) ;
F_21 ( V_66 ) ;
}
}
}
if( ! F_32 ( V_47 , V_46 ) ) goto V_57;
if ( ( V_43 == NULL ) &&
( ( V_42 = F_30 ( V_46 , V_67 , L_70 ) ) != NULL ) )
{
if ( ( V_43 = F_24 ( V_42 ) ) != NULL )
V_44 = V_43 ;
}
if( ! V_33 )
V_33 = F_30 ( V_46 , V_67 , V_68 ) ;
if( V_33 ) {
T_9 V_69 ;
F_33 ( & V_69 ) ;
F_34 ( & V_69 , V_46 ) ;
if( ! F_35 ( V_46 , & V_69 , V_33 , NULL ) ) {
F_16 ( V_47 ,
L_71 , V_33 ) ;
goto V_57;
}
}
if( ! V_40 )
V_40 = F_30 ( V_46 , V_67 , L_72 ) ;
if( ! V_41 )
V_41 = F_30 ( V_46 , V_67 , L_73 ) ;
V_42 = F_30 ( V_46 , V_67 , V_70 ) ;
if( V_42 && ! F_36 ( V_42 ) ) {
F_16 ( V_47 , L_74 , V_42 ) ;
goto V_57;
}
if( ! V_34 )
V_34 = F_30 ( V_46 , V_67 , V_71 ) ;
if( V_34 ) {
T_9 V_69 ;
F_33 ( & V_69 ) ;
F_34 ( & V_69 , V_46 ) ;
if( ! F_35 ( V_46 , & V_69 , V_34 , NULL ) ) {
F_16 ( V_47 ,
L_75 ,
V_34 ) ;
goto V_57;
}
}
V_15 = F_7 ( F_8 () ) ;
V_16 = F_7 ( F_8 () ) ;
if ( ( V_15 == NULL ) || ( V_16 == NULL ) )
goto V_57;
if ( V_30 != NULL )
{
if ( F_37 ( V_15 , V_30 ) <= 0 )
{
perror ( V_30 ) ;
goto V_57;
}
if ( V_22 == V_72 )
V_9 = F_38 ( V_15 , NULL ) ;
else if ( V_22 == V_23 )
{
V_9 = F_39 ( V_15 , NULL , NULL , V_40 ) ;
}
else
{
F_16 ( V_47 , L_76 ) ;
goto V_57;
}
if ( V_9 == NULL )
{
F_16 ( V_47 , L_77 ) ;
goto V_57;
}
if ( F_40 ( V_9 -> type ) == V_58 )
{
char * V_73 = F_30 ( V_46 , V_67 , L_78 ) ;
F_41 ( V_73 , V_47 , 0 ) ;
}
}
if ( V_12 && ( V_9 == NULL ) )
{
char * V_73 = F_30 ( V_46 , V_67 , L_78 ) ;
F_41 ( V_73 , V_47 , 0 ) ;
if ( V_37 )
F_42 ( V_37 ) ;
if ( V_13 <= 0 )
{
V_13 = ( int ) F_43 ( V_46 , V_67 , V_74 ) ;
if ( V_13 <= 0 )
V_13 = V_75 ;
}
if ( V_13 < V_76 )
{
F_16 ( V_47 , L_79 ) ;
F_16 ( V_47 , L_80 , V_76 , V_13 ) ;
goto V_57;
}
F_16 ( V_47 , L_81 ,
V_13 , ( V_14 == V_52 ) ? L_82 : L_83 ) ;
if ( ( V_9 = F_44 () ) == NULL ) goto V_57;
#ifndef F_45
if ( V_14 == V_52 )
{
if ( ! F_46 ( V_9 ,
F_47 ( V_13 , 0x10001 ,
V_77 , V_47 ) ) )
goto V_57;
}
else
#endif
#ifndef F_1
if ( V_14 == V_56 )
{
if ( ! F_48 ( V_3 ) ) goto V_57;
if ( ! F_49 ( V_9 , V_3 ) ) goto V_57;
V_3 = NULL ;
}
#endif
F_50 ( V_73 , V_47 ) ;
if ( V_9 == NULL ) goto V_57;
if ( V_32 == NULL )
V_32 = F_30 ( V_46 , V_67 , V_78 ) ;
if ( V_32 == NULL )
{
F_16 ( V_47 , L_84 ) ;
F_9 ( V_16 , stdout , V_49 ) ;
#ifdef F_28
{
T_5 * V_79 = F_7 ( F_51 () ) ;
V_16 = F_52 ( V_79 , V_16 ) ;
}
#endif
}
else
{
F_16 ( V_47 , L_85 , V_32 ) ;
if ( F_53 ( V_16 , V_32 ) <= 0 )
{
perror ( V_32 ) ;
goto V_57;
}
}
V_42 = F_30 ( V_46 , V_67 , L_86 ) ;
if ( V_42 == NULL )
V_42 = F_30 ( V_46 , V_67 , L_87 ) ;
if ( ( V_42 != NULL ) && ( strcmp ( V_42 , L_88 ) == 0 ) )
V_35 = NULL ;
if ( V_24 ) V_35 = NULL ;
V_10 = 0 ;
V_80:
if ( ! F_54 ( V_16 , V_9 , V_35 ,
NULL , 0 , NULL , V_41 ) )
{
if ( ( F_55 ( F_56 () ) ==
V_81 ) && ( V_10 < 3 ) )
{
F_13 () ;
V_10 ++ ;
goto V_80;
}
goto V_57;
}
F_16 ( V_47 , L_89 ) ;
}
if ( ! V_12 )
{
V_25 = - 1 ;
if ( V_27 == NULL )
F_9 ( V_15 , V_82 , V_49 ) ;
else
{
if ( F_37 ( V_15 , V_27 ) <= 0 )
{
perror ( V_27 ) ;
goto V_57;
}
}
if ( V_17 == V_72 )
V_8 = F_57 ( V_15 , NULL ) ;
else if ( V_17 == V_23 )
V_8 = F_58 ( V_15 , NULL , NULL , NULL ) ;
else
{
F_16 ( V_47 , L_76 ) ;
goto V_57;
}
if ( V_8 == NULL )
{
F_16 ( V_47 , L_90 ) ;
goto V_57;
}
}
if ( V_12 || V_5 )
{
#ifndef F_1
if ( V_9 -> type == V_58 )
V_44 = F_59 () ;
#endif
if ( V_9 == NULL )
{
F_16 ( V_47 , L_91 ) ;
goto V_57;
}
if ( V_8 == NULL )
{
V_8 = F_60 () ;
if ( V_8 == NULL )
{
goto V_57;
}
V_10 = F_61 ( V_8 , V_9 , ! V_5 ) ;
if ( V_25 >= 0 )
V_8 -> V_83 -> V_84 = V_25 ;
if ( ! V_10 )
{
F_16 ( V_47 , L_92 ) ;
goto V_57;
}
}
if ( V_5 )
{
T_4 * V_85 ;
T_9 V_86 ;
if ( ( V_7 = F_62 () ) == NULL ) goto V_57;
if( ! F_63 ( V_7 , 2 ) ) goto V_57;
F_64 ( F_65 ( V_7 ) , 0L ) ;
F_66 ( V_7 ,
F_67 ( V_8 ) ) ;
F_68 ( F_69 ( V_7 ) , 0 ) ;
F_68 ( F_70 ( V_7 ) ,
( long ) 60 * 60 * 24 * V_6 ) ;
F_71 ( V_7 ,
F_67 ( V_8 ) ) ;
V_85 = F_72 ( V_8 ) ;
F_73 ( V_7 , V_85 ) ;
F_19 ( V_85 ) ;
F_74 ( & V_86 , V_7 , V_7 , NULL , NULL , 0 ) ;
F_34 ( & V_86 , V_46 ) ;
if( V_33 && ! F_35 ( V_46 ,
& V_86 , V_33 , V_7 ) )
{
F_16 ( V_47 ,
L_71 ,
V_33 ) ;
goto V_57;
}
if ( ! ( V_10 = F_75 ( V_7 , V_9 , V_44 ) ) )
goto V_57;
}
else
{
T_9 V_86 ;
F_74 ( & V_86 , NULL , NULL , V_8 , NULL , 0 ) ;
F_34 ( & V_86 , V_46 ) ;
if( V_34 && ! F_76 ( V_46 ,
& V_86 , V_34 , V_8 ) )
{
F_16 ( V_47 ,
L_71 ,
V_34 ) ;
goto V_57;
}
if ( ! ( V_10 = F_77 ( V_8 , V_9 , V_44 ) ) )
goto V_57;
}
}
if ( V_19 && ! V_5 )
{
int V_87 = 0 ;
if ( V_9 == NULL )
{
V_9 = F_72 ( V_8 ) ;
V_87 = 1 ;
if ( V_9 == NULL ) goto V_57;
}
V_10 = F_78 ( V_8 , V_9 ) ;
if ( V_87 ) {
F_19 ( V_9 ) ;
V_9 = NULL ;
}
if ( V_10 < 0 )
{
goto V_57;
}
else if ( V_10 == 0 )
{
F_16 ( V_47 , L_93 ) ;
}
else
F_16 ( V_47 , L_94 ) ;
}
if ( V_20 && ! V_21 && ! V_36 )
{
V_4 = 0 ;
goto V_57;
}
if ( V_28 == NULL )
{
F_9 ( V_16 , stdout , V_49 ) ;
#ifdef F_28
{
T_5 * V_79 = F_7 ( F_51 () ) ;
V_16 = F_52 ( V_79 , V_16 ) ;
}
#endif
}
else
{
if ( ( V_32 != NULL ) && ( strcmp ( V_28 , V_32 ) == 0 ) )
V_10 = ( int ) F_79 ( V_16 , V_28 ) ;
else
V_10 = ( int ) F_53 ( V_16 , V_28 ) ;
if ( ! V_10 )
{
perror ( V_28 ) ;
goto V_57;
}
}
if ( V_21 )
{
if ( V_5 )
F_80 ( V_16 , V_7 ) ;
else
F_81 ( V_16 , V_8 ) ;
}
if ( V_36 )
{
T_4 * V_88 ;
if ( V_5 )
V_88 = F_17 ( V_7 ) ;
else
V_88 = F_72 ( V_8 ) ;
if ( V_88 == NULL )
{
fprintf ( stdout , L_95 ) ;
goto V_57;
}
fprintf ( stdout , L_96 ) ;
#ifndef F_45
if ( V_88 -> type == V_89 )
F_82 ( V_16 , V_88 -> V_9 . V_90 -> V_91 ) ;
else
#endif
fprintf ( stdout , L_97 ) ;
fprintf ( stdout , L_98 ) ;
}
if ( ! V_20 && ! V_5 )
{
if ( V_18 == V_72 )
V_10 = F_83 ( V_16 , V_8 ) ;
else if ( V_18 == V_23 ) {
if( V_26 ) V_10 = F_84 ( V_16 , V_8 ) ;
else V_10 = F_85 ( V_16 , V_8 ) ;
} else {
F_16 ( V_47 , L_99 ) ;
goto V_57;
}
if ( ! V_10 )
{
F_16 ( V_47 , L_100 ) ;
goto V_57;
}
}
if ( ! V_20 && V_5 && ( V_7 != NULL ) )
{
if ( V_18 == V_72 )
V_10 = F_86 ( V_16 , V_7 ) ;
else if ( V_18 == V_23 )
V_10 = F_87 ( V_16 , V_7 ) ;
else {
F_16 ( V_47 , L_99 ) ;
goto V_57;
}
if ( ! V_10 )
{
F_16 ( V_47 , L_101 ) ;
goto V_57;
}
}
V_4 = 0 ;
V_57:
if ( V_4 )
{
F_88 ( V_47 ) ;
}
if ( ( V_46 != NULL ) && ( V_46 != V_64 ) ) F_89 ( V_46 ) ;
F_21 ( V_15 ) ;
F_90 ( V_16 ) ;
F_19 ( V_9 ) ;
F_91 ( V_8 ) ;
F_20 ( V_7 ) ;
if( V_38 && V_40 ) F_92 ( V_40 ) ;
if( V_39 && V_41 ) F_92 ( V_41 ) ;
F_93 () ;
#ifndef F_1
if ( V_3 != NULL ) F_94 ( V_3 ) ;
#endif
EXIT ( V_4 ) ;
}
static int F_61 ( T_3 * V_8 , T_4 * V_9 , int V_92 )
{
int V_93 = 0 , V_10 ;
char V_94 = 0 ;
F_95 ( V_95 ) * V_96 , * V_97 = NULL ;
char * V_87 , * V_98 , * V_99 ;
V_87 = F_30 ( V_46 , V_67 , V_100 ) ;
if( ( V_87 != NULL ) && ! strcmp ( V_87 , L_88 ) ) V_94 = 1 ;
V_98 = F_30 ( V_46 , V_67 , V_101 ) ;
if ( V_98 == NULL )
{
F_16 ( V_47 , L_102 ,
V_101 ) ;
goto V_102;
}
V_96 = F_96 ( V_46 , V_98 ) ;
if ( V_96 == NULL )
{
F_16 ( V_47 , L_103 , V_98 ) ;
goto V_102;
}
V_99 = F_30 ( V_46 , V_67 , V_103 ) ;
if ( V_99 == NULL )
V_97 = NULL ;
else
{
V_97 = F_96 ( V_46 , V_99 ) ;
if ( V_97 == NULL )
{
F_16 ( V_47 , L_103 , V_99 ) ;
goto V_102;
}
}
if ( ! F_97 ( V_8 , 0L ) ) goto V_102;
if( V_94 ) V_10 = F_98 ( V_8 , V_96 , V_97 , V_92 ) ;
else V_10 = F_99 ( V_8 , V_96 , V_98 , V_97 , V_99 , V_92 ) ;
if( ! V_10 ) goto V_102;
F_100 ( V_8 , V_9 ) ;
V_93 = 1 ;
V_102:
return ( V_93 ) ;
}
static int F_101 ( T_10 * V_91 , char * V_21 , char * V_104 , char * V_105 ,
int V_106 , int V_107 , int V_108 )
{
int V_10 , V_93 = 0 ;
T_8 char V_109 [ 1024 ] ;
V_110:
F_16 ( V_47 , L_104 , V_21 , V_104 ) ;
( void ) F_102 ( V_47 ) ;
if ( V_105 != NULL )
{
strcpy ( V_109 , V_105 ) ;
strcat ( V_109 , L_98 ) ;
F_16 ( V_47 , L_105 , V_105 ) ;
}
else
{
V_109 [ 0 ] = '\0' ;
fgets ( V_109 , 1024 , V_82 ) ;
}
if ( V_109 [ 0 ] == '\0' ) return ( 0 ) ;
else if ( V_109 [ 0 ] == '\n' )
{
if ( ( V_104 == NULL ) || ( V_104 [ 0 ] == '\0' ) )
return ( 1 ) ;
strcpy ( V_109 , V_104 ) ;
strcat ( V_109 , L_98 ) ;
}
else if ( ( V_109 [ 0 ] == '.' ) && ( V_109 [ 1 ] == '\n' ) ) return ( 1 ) ;
V_10 = strlen ( V_109 ) ;
if ( V_109 [ V_10 - 1 ] != '\n' )
{
F_16 ( V_47 , L_106 ) ;
return ( 0 ) ;
}
V_109 [ -- V_10 ] = '\0' ;
#ifdef F_103
F_104 ( V_109 , V_109 , V_10 ) ;
#endif
if( ! F_105 ( V_10 , V_107 , V_108 ) ) goto V_110;
if ( ! F_106 ( V_91 , V_106 , V_111 ,
( unsigned char * ) V_109 , - 1 , - 1 , 0 ) ) goto V_102;
V_93 = 1 ;
V_102:
return ( V_93 ) ;
}
static int F_107 ( T_3 * V_8 , char * V_21 ,
char * V_104 , char * V_105 , int V_106 , int V_107 ,
int V_108 )
{
int V_10 ;
static char V_109 [ 1024 ] ;
V_110:
F_16 ( V_47 , L_104 , V_21 , V_104 ) ;
( void ) F_102 ( V_47 ) ;
if ( V_105 != NULL )
{
strcpy ( V_109 , V_105 ) ;
strcat ( V_109 , L_98 ) ;
F_16 ( V_47 , L_105 , V_105 ) ;
}
else
{
V_109 [ 0 ] = '\0' ;
fgets ( V_109 , 1024 , V_82 ) ;
}
if ( V_109 [ 0 ] == '\0' ) return ( 0 ) ;
else if ( V_109 [ 0 ] == '\n' )
{
if ( ( V_104 == NULL ) || ( V_104 [ 0 ] == '\0' ) )
return ( 1 ) ;
strcpy ( V_109 , V_104 ) ;
strcat ( V_109 , L_98 ) ;
}
else if ( ( V_109 [ 0 ] == '.' ) && ( V_109 [ 1 ] == '\n' ) ) return ( 1 ) ;
V_10 = strlen ( V_109 ) ;
if ( V_109 [ V_10 - 1 ] != '\n' )
{
F_16 ( V_47 , L_106 ) ;
return ( 0 ) ;
}
V_109 [ -- V_10 ] = '\0' ;
#ifdef F_103
F_104 ( V_109 , V_109 , V_10 ) ;
#endif
if( ! F_105 ( V_10 , V_107 , V_108 ) ) goto V_110;
if( ! F_108 ( V_8 , V_106 , V_111 ,
( unsigned char * ) V_109 , - 1 ) ) {
F_16 ( V_47 , L_107 ) ;
F_88 ( V_47 ) ;
goto V_102;
}
return ( 1 ) ;
V_102:
return ( 0 ) ;
}
static void T_11 V_77 ( int V_42 , int V_91 , void * V_112 )
{
char V_113 = '*' ;
if ( V_42 == 0 ) V_113 = '.' ;
if ( V_42 == 1 ) V_113 = '+' ;
if ( V_42 == 2 ) V_113 = '*' ;
if ( V_42 == 3 ) V_113 = '\n' ;
F_109 ( ( T_5 * ) V_112 , & V_113 , 1 ) ;
( void ) F_102 ( ( T_5 * ) V_112 ) ;
#ifdef F_110
V_42 = V_91 ;
#endif
}
static int F_105 ( int V_114 , int V_107 , int V_108 )
{
if ( V_114 < V_107 )
{
F_16 ( V_47 , L_108 , V_107 ) ;
return ( 0 ) ;
}
if ( ( V_108 != 0 ) && ( V_114 > V_108 ) )
{
F_16 ( V_47 , L_109 , V_108 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_111 ( char * V_115 , char * V_57 )
{
int V_116 , V_117 ;
char * V_87 ;
V_116 = strlen ( V_57 ) ;
V_117 = strlen ( V_115 ) ;
if( V_116 > V_117 ) return 1 ;
V_87 = V_115 + V_117 - V_116 ;
return strcmp ( V_87 , V_57 ) ;
}
