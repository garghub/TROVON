int MAIN ( int V_1 , char * * V_2 )
{
char * V_3 = NULL , * V_4 = NULL , * V_5 = NULL ;
char * V_6 = NULL ;
T_1 * V_7 = NULL , * V_8 = NULL , * V_9 = NULL , * V_10 = NULL ;
char * * args ;
char * V_11 = NULL ;
T_2 * V_12 = NULL ;
char V_13 [ 50 ] , V_14 [ 50 ] ;
int V_15 = 0 ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 = 0 ;
int V_19 = V_20 ;
int V_21 = V_20 ;
int V_22 = 0 ;
int V_23 = 0 ;
int V_24 = V_25 ;
int V_26 = V_27 ;
int V_28 = 1 ;
int V_29 = 1 ;
int V_30 = 0 ;
T_3 * V_31 = NULL ;
char * V_32 = NULL , * V_33 = NULL ;
char * V_34 = NULL , * V_35 = NULL , * V_36 = NULL ;
char * V_37 = NULL , * V_38 = NULL ;
char * V_39 = NULL ;
F_1 () ;
V_40 = F_2 () ;
if ( V_41 == NULL ) V_41 = F_3 ( V_42 , V_43 ) ;
args = V_2 + 1 ;
while ( * args ) {
if ( * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_1 ) ) V_16 |= V_44 ;
else if ( ! strcmp ( * args , L_2 ) ) V_23 = V_45 ;
else if ( ! strcmp ( * args , L_3 ) ) V_23 = V_46 ;
else if ( ! strcmp ( * args , L_4 ) ) V_16 |= V_47 ;
else if ( ! strcmp ( * args , L_5 ) ) V_16 |= V_48 ;
else if ( ! strcmp ( * args , L_6 ) ) V_16 |= V_49 ;
else if ( ! strcmp ( * args , L_7 ) ) V_16 |= ( V_44 | V_47 ) ;
else if ( ! strcmp ( * args , L_8 ) ) V_16 |= V_50 ;
else if ( ! strcmp ( * args , L_9 ) ) V_17 = 1 ;
else if ( ! strcmp ( * args , L_10 ) ) V_22 = 1 ;
else if ( ! strcmp ( * args , L_11 ) ) V_29 = 0 ;
else if ( ! strcmp ( * args , L_12 ) )
V_24 = V_27 ;
else if ( ! strcmp ( * args , L_13 ) ) V_15 = 1 ;
else if ( ! strcmp ( * args , L_14 ) ) V_40 = F_4 () ;
#ifndef F_5
else if ( ! strcmp ( * args , L_15 ) ) V_40 = F_6 () ;
#endif
else if ( ! strcmp ( * args , L_16 ) ) V_40 = F_2 () ;
else if ( ! strcmp ( * args , L_17 ) ) V_19 = 1 ;
else if ( ! strcmp ( * args , L_18 ) )
V_21 = V_20 ;
else if ( ! strcmp ( * args , L_19 ) )
V_21 = 1 ;
else if ( ! strcmp ( * args , L_20 ) ) V_40 = NULL ;
else if ( ! strcmp ( * args , L_21 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_24 = F_7 ( * args ) ;
if( V_24 == V_51 ) {
F_8 ( V_41 ,
L_22 , * args ) ;
V_18 = 1 ;
}
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_23 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_26 = F_7 ( * args ) ;
if( V_26 == V_51 ) {
F_8 ( V_41 ,
L_22 , * args ) ;
V_18 = 1 ;
}
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_24 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_39 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_25 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_5 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_26 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_6 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_27 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_11 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_28 ) ) {
if ( args [ 1 ] ) {
args ++ ;
if ( ! V_31 ) V_31 = F_9 ( NULL ) ;
F_10 ( V_31 , * args ) ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_29 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_3 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_30 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_4 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_31 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_34 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_32 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_35 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_33 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_36 = * args ;
V_30 = 1 ;
} else V_18 = 1 ;
} else V_18 = 1 ;
} else V_18 = 1 ;
args ++ ;
}
if ( V_18 ) {
F_8 ( V_41 , L_34 ) ;
F_8 ( V_41 , L_35 ) ;
F_8 ( V_41 , L_36 ) ;
F_8 ( V_41 , L_37 ) ;
F_8 ( V_41 , L_38 ) ;
F_8 ( V_41 , L_39 ) ;
F_8 ( V_41 , L_40 ) ;
F_8 ( V_41 , L_41 ) ;
F_8 ( V_41 , L_42 ) ;
F_8 ( V_41 , L_43 ) ;
F_8 ( V_41 , L_44 ) ;
F_8 ( V_41 , L_45 ) ;
F_8 ( V_41 , L_46 ) ;
F_8 ( V_41 , L_47 ) ;
F_8 ( V_41 , L_48 ) ;
F_8 ( V_41 , L_49 ) ;
F_8 ( V_41 , L_50 ) ;
F_8 ( V_41 , L_51 ) ;
F_8 ( V_41 , L_52 ) ;
#ifndef F_5
F_8 ( V_41 , L_53 ) ;
#endif
F_8 ( V_41 , L_54 ) ;
F_8 ( V_41 , L_55 ) ;
F_8 ( V_41 , L_56 ) ;
F_8 ( V_41 , L_57 ) ;
F_8 ( V_41 , L_58 ) ;
F_8 ( V_41 , L_59 ) ;
F_8 ( V_41 , L_60 ) ;
F_8 ( V_41 , L_61 ) ;
F_8 ( V_41 , L_62 ) ;
F_8 ( V_41 , L_63 ) ;
F_8 ( V_41 , L_64 ) ;
F_8 ( V_41 , L_65 ) ;
F_8 ( V_41 , L_66 ) ;
F_8 ( V_41 , L_67 ) ;
F_8 ( V_41 , L_68 ) ;
goto V_52;
}
if( V_36 ) {
if( V_15 ) V_35 = V_36 ;
else V_34 = V_36 ;
}
if( ! F_11 ( V_41 , V_34 , V_35 , & V_37 , & V_38 ) ) {
F_8 ( V_41 , L_69 ) ;
goto V_52;
}
if( ! V_32 ) {
if( V_15 ) V_32 = V_38 ;
else V_32 = V_37 ;
}
if( V_32 ) {
V_33 = V_32 ;
V_30 = 1 ;
} else {
V_32 = V_13 ;
V_33 = V_14 ;
}
if( V_15 || V_39 ) {
F_12 ( NULL , V_41 , ( V_39 != NULL ) ) ;
if ( V_39 != NULL )
F_8 ( V_41 , L_70 ,
F_13 ( V_39 ) ) ;
}
F_14 () ;
#ifdef F_15
F_16 ( L_71 ) ;
#endif
if ( ! V_3 ) V_7 = F_3 ( V_53 , V_43 ) ;
else V_7 = F_17 ( V_3 , L_72 ) ;
if ( ! V_7 ) {
F_8 ( V_41 , L_73 ,
V_3 ? V_3 : L_74 ) ;
perror ( V_3 ) ;
goto V_52;
}
if ( V_6 ) {
if( ! ( V_10 = F_17 ( V_6 , L_75 ) ) ) {
F_8 ( V_41 , L_76 , V_6 ) ;
perror ( V_6 ) ;
goto V_52;
}
}
if ( V_5 ) {
if( ! ( V_9 = F_17 ( V_5 , L_75 ) ) ) {
F_8 ( V_41 , L_77 , V_5 ) ;
perror ( V_5 ) ;
goto V_52;
}
}
#ifdef F_15
F_18 () ;
F_16 ( L_78 ) ;
#endif
if ( ! V_4 ) V_8 = F_3 ( stdout , V_43 ) ;
else V_8 = F_17 ( V_4 , L_79 ) ;
if ( ! V_8 ) {
F_8 ( V_41 , L_80 ,
V_4 ? V_4 : L_81 ) ;
perror ( V_4 ) ;
goto V_52;
}
if ( V_22 ) {
#ifdef F_15
F_16 ( L_82 ) ;
#endif
if( F_19 ( V_14 , 50 , L_83 , V_15 ) )
{
F_8 ( V_41 , L_84 ) ;
goto V_52;
}
#ifdef F_15
F_18 () ;
#endif
}
if ( V_15 ) {
T_4 * V_54 ;
T_3 * V_55 , * V_56 ;
T_5 * V_57 ;
T_6 * V_58 ;
T_7 * V_59 ;
T_8 * V_60 = NULL ;
F_20 ( T_8 ) * V_61 = NULL ;
char * V_62 ;
int V_63 ;
unsigned char V_64 [ V_65 ] ;
unsigned int V_66 = 0 ;
#ifdef F_15
F_16 ( L_85 ) ;
#endif
V_54 = F_21 ( V_9 ? V_9 : V_7 , NULL , NULL , V_37 ) ;
if ( ! V_9 ) ( void ) F_22 ( V_7 ) ;
else F_23 ( V_9 ) ;
if ( ! V_54 ) {
F_8 ( V_41 , L_86 ) ;
F_24 ( V_41 ) ;
goto V_52;
}
V_61 = F_25 ( NULL ) ;
if( ! F_26 ( V_7 , V_61 ) ) {
F_8 ( V_41 , L_87 ) ;
F_24 ( V_41 ) ;
goto V_52;
}
for( V_63 = 0 ; V_63 < F_27 ( V_61 ) ; V_63 ++ ) {
V_60 = F_28 ( V_61 , V_63 ) ;
if( F_29 ( V_60 , V_54 ) ) {
F_30 ( V_60 , F_31 () , V_64 , & V_66 ) ;
break;
}
}
if( ! V_66 ) {
F_8 ( V_41 , L_88 ) ;
goto V_52;
}
V_55 = F_9 ( NULL ) ;
if ( V_10 ) {
if( ! F_26 ( V_10 , V_61 ) ) {
F_8 ( V_41 , L_89 ) ;
F_24 ( V_41 ) ;
goto V_52;
}
F_23 ( V_10 ) ;
}
if ( V_17 ) {
int V_67 ;
F_20 ( T_8 ) * V_68 ;
V_67 = F_32 ( V_60 , & V_68 ) ;
if ( V_67 ) {
F_8 ( V_41 , L_90 ,
F_33 ( V_67 ) ) ;
goto V_52;
}
for ( V_63 = 1 ; V_63 < F_27 ( V_68 ) ; V_63 ++ )
F_34 ( V_61 , F_28 ( V_68 , V_63 ) ) ;
F_35 ( V_68 ) ;
}
for( V_63 = 0 ; V_63 < F_27 ( V_61 ) ; V_63 ++ ) {
T_8 * V_69 = NULL ;
V_69 = F_28 ( V_61 , V_63 ) ;
V_57 = F_36 ( V_69 ) ;
if( V_69 == V_60 ) {
if( V_11 ) F_37 ( V_57 , V_11 , - 1 ) ;
F_38 ( V_57 , V_64 , V_66 ) ;
} else if( ( V_62 = F_39 ( V_31 ) ) )
F_37 ( V_57 , V_62 , - 1 ) ;
F_10 ( V_55 , ( char * ) V_57 ) ;
}
F_40 ( V_61 , V_70 ) ;
if ( V_31 ) F_41 ( V_31 ) ;
if( ! V_30 &&
F_19 ( V_13 , 50 , L_91 , 1 ) ) {
F_8 ( V_41 , L_84 ) ;
goto V_52;
}
if ( ! V_22 ) strcpy ( V_14 , V_13 ) ;
V_59 = F_42 ( V_24 , V_32 , - 1 , NULL , 0 ,
V_19 , V_55 ) ;
F_43 ( V_55 , V_71 ) ;
if ( ! V_59 ) {
F_24 ( V_41 ) ;
goto V_52;
}
V_56 = F_9 ( NULL ) ;
F_10 ( V_56 , ( char * ) V_59 ) ;
V_58 = F_44 ( V_54 ) ;
F_45 ( V_54 ) ;
if( V_23 ) F_46 ( V_58 , V_23 ) ;
V_57 = F_47 ( V_26 , V_32 , - 1 , NULL , 0 , V_19 , V_58 ) ;
F_48 ( V_58 ) ;
if ( V_11 ) F_37 ( V_57 , V_11 , - 1 ) ;
F_38 ( V_57 , V_64 , V_66 ) ;
V_55 = F_9 ( NULL ) ;
F_10 ( V_55 , ( char * ) V_57 ) ;
V_59 = F_49 ( V_55 ) ;
F_43 ( V_55 , V_71 ) ;
F_10 ( V_56 , ( char * ) V_59 ) ;
V_12 = F_50 ( V_72 ) ;
F_51 ( V_12 , V_56 ) ;
F_43 ( V_56 , V_73 ) ;
F_52 ( V_12 , V_33 , - 1 , NULL , 0 , V_21 , NULL ) ;
F_53 ( V_8 , V_12 ) ;
F_54 ( V_12 ) ;
V_28 = 0 ;
#ifdef F_15
F_18 () ;
#endif
goto V_52;
}
if ( ! ( V_12 = F_55 ( V_7 , NULL ) ) ) {
F_24 ( V_41 ) ;
goto V_52;
}
#ifdef F_15
F_16 ( L_92 ) ;
#endif
if( ! V_30 && F_19 ( V_13 , 50 , L_93 , 0 ) ) {
F_8 ( V_41 , L_84 ) ;
goto V_52;
}
#ifdef F_15
F_18 () ;
#endif
if ( ! V_22 ) strcpy ( V_14 , V_13 ) ;
if ( V_16 & V_50 ) F_8 ( V_41 , L_94 , V_12 -> V_74 -> V_19 ? F_56 ( V_12 -> V_74 -> V_19 ) : 1 ) ;
if( V_29 ) {
#ifdef F_15
F_16 ( L_95 ) ;
#endif
if ( ! F_57 ( V_12 , V_33 , - 1 ) ) {
F_8 ( V_41 , L_96 ) ;
F_24 ( V_41 ) ;
goto V_52;
} else F_8 ( V_41 , L_97 ) ;
#ifdef F_15
F_18 () ;
#endif
}
#ifdef F_15
F_16 ( L_98 ) ;
#endif
if ( ! F_58 ( V_8 , V_12 , V_32 , - 1 , V_16 , V_38 ) ) {
F_8 ( V_41 , L_99 ) ;
F_24 ( V_41 ) ;
goto V_52;
}
#ifdef F_15
F_18 () ;
#endif
F_54 ( V_12 ) ;
V_28 = 0 ;
V_52:
if( V_15 || V_39 ) F_59 ( NULL , V_41 ) ;
#ifdef F_15
F_60 () ;
#endif
F_23 ( V_7 ) ;
F_23 ( V_8 ) ;
if( V_37 ) Free ( V_37 ) ;
if( V_38 ) Free ( V_38 ) ;
EXIT ( V_28 ) ;
}
int F_58 ( T_1 * V_8 , T_2 * V_12 , char * V_13 ,
int V_75 , int V_16 , char * V_76 )
{
T_3 * V_77 , * V_55 ;
int V_63 , V_78 ;
T_7 * V_79 ;
if ( ! ( V_77 = F_61 ( V_12 ) ) ) return 0 ;
for ( V_63 = 0 ; V_63 < F_62 ( V_77 ) ; V_63 ++ ) {
V_79 = ( T_7 * ) F_63 ( V_77 , V_63 ) ;
V_78 = F_64 ( V_79 -> type ) ;
if ( V_78 == V_72 ) {
V_55 = F_65 ( V_79 ) ;
if ( V_16 & V_50 ) F_8 ( V_41 , L_100 ) ;
} else if ( V_78 == V_80 ) {
if ( V_16 & V_50 ) {
F_8 ( V_41 , L_101 ) ;
F_66 ( V_41 ,
V_79 -> V_81 . V_82 -> V_83 -> V_84 ) ;
}
V_55 = F_67 ( V_79 , V_13 , V_75 ) ;
} else continue;
if ( ! V_55 ) return 0 ;
if ( ! F_68 ( V_8 , V_55 , V_13 , V_75 ,
V_16 , V_76 ) ) {
F_43 ( V_55 , V_71 ) ;
return 0 ;
}
F_43 ( V_55 , V_71 ) ;
}
F_43 ( V_77 , V_73 ) ;
return 1 ;
}
int F_68 ( T_1 * V_8 , T_3 * V_55 , char * V_13 ,
int V_75 , int V_16 , char * V_76 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < F_62 ( V_55 ) ; V_63 ++ ) {
if ( ! F_69 ( V_8 ,
( T_5 * ) F_63 ( V_55 , V_63 ) , V_13 , V_75 ,
V_16 , V_76 ) ) return 0 ;
}
return 1 ;
}
int F_69 ( T_1 * V_8 , T_5 * V_57 , char * V_13 ,
int V_75 , int V_16 , char * V_76 )
{
T_4 * V_85 ;
T_6 * V_58 ;
T_8 * V_86 ;
switch ( F_70 ( V_57 ) )
{
case V_87 :
if ( V_16 & V_50 ) F_8 ( V_41 , L_102 ) ;
if ( V_16 & V_44 ) return 1 ;
F_71 ( V_8 , V_57 -> V_88 , L_103 ) ;
V_58 = V_57 -> V_89 . V_90 ;
if ( ! ( V_85 = F_72 ( V_58 ) ) ) return 0 ;
F_71 ( V_8 , V_58 -> V_91 , L_104 ) ;
F_73 ( V_8 , V_85 , V_40 , NULL , 0 , NULL , V_76 ) ;
F_45 ( V_85 ) ;
break;
case V_92 :
if ( V_16 & V_50 ) {
F_8 ( V_41 , L_105 ) ;
F_66 ( V_41 , V_57 -> V_89 . V_93 -> V_94 ) ;
}
if ( V_16 & V_44 ) return 1 ;
F_71 ( V_8 , V_57 -> V_88 , L_103 ) ;
if ( ! ( V_58 = F_74 ( V_57 , V_13 , V_75 ) ) )
return 0 ;
if ( ! ( V_85 = F_72 ( V_58 ) ) ) return 0 ;
F_71 ( V_8 , V_58 -> V_91 , L_104 ) ;
F_48 ( V_58 ) ;
F_73 ( V_8 , V_85 , V_40 , NULL , 0 , NULL , V_76 ) ;
F_45 ( V_85 ) ;
break;
case V_95 :
if ( V_16 & V_50 ) F_8 ( V_41 , L_106 ) ;
if ( V_16 & V_47 ) return 1 ;
if ( F_75 ( V_57 , V_96 ) ) {
if ( V_16 & V_49 ) return 1 ;
} else if ( V_16 & V_48 ) return 1 ;
F_71 ( V_8 , V_57 -> V_88 , L_103 ) ;
if ( F_76 ( V_57 ) != V_97 )
return 1 ;
if ( ! ( V_86 = F_77 ( V_57 ) ) ) return 0 ;
F_78 ( V_8 , V_86 ) ;
F_79 ( V_8 , V_86 ) ;
V_70 ( V_86 ) ;
break;
case V_98 :
if ( V_16 & V_50 ) F_8 ( V_41 , L_107 ) ;
F_71 ( V_8 , V_57 -> V_88 , L_103 ) ;
return F_68 ( V_8 , V_57 -> V_89 . V_56 , V_13 ,
V_75 , V_16 , V_76 ) ;
default:
F_8 ( V_41 , L_108 ) ;
F_80 ( V_41 , V_57 -> type ) ;
F_8 ( V_41 , L_109 ) ;
return 1 ;
break;
}
return 1 ;
}
int F_66 ( T_1 * V_99 , T_9 * V_100 )
{
T_10 * V_101 ;
unsigned char * V_102 ;
V_102 = V_100 -> V_103 -> V_89 . V_104 -> V_105 ;
V_101 = F_81 ( NULL , & V_102 , V_100 -> V_103 -> V_89 . V_104 -> V_106 ) ;
F_8 ( V_41 , L_110 ,
F_82 ( F_64 ( V_100 -> V_84 ) ) , F_56 ( V_101 -> V_19 ) ) ;
F_83 ( V_101 ) ;
return 0 ;
}
void F_84 ( T_1 * V_8 , unsigned char * V_107 , int V_108 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_108 ; V_63 ++ ) F_8 ( V_8 , L_111 , V_107 [ V_63 ] ) ;
}
