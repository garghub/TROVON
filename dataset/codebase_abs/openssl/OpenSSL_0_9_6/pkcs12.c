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
char * V_40 = NULL , * V_41 = NULL ;
F_1 () ;
V_42 = F_2 () ;
if ( V_43 == NULL ) V_43 = F_3 ( V_44 , V_45 ) ;
args = V_2 + 1 ;
while ( * args ) {
if ( * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_1 ) ) V_16 |= V_46 ;
else if ( ! strcmp ( * args , L_2 ) ) V_23 = V_47 ;
else if ( ! strcmp ( * args , L_3 ) ) V_23 = V_48 ;
else if ( ! strcmp ( * args , L_4 ) ) V_16 |= V_49 ;
else if ( ! strcmp ( * args , L_5 ) ) V_16 |= V_50 ;
else if ( ! strcmp ( * args , L_6 ) ) V_16 |= V_51 ;
else if ( ! strcmp ( * args , L_7 ) ) V_16 |= ( V_46 | V_49 ) ;
else if ( ! strcmp ( * args , L_8 ) ) V_16 |= V_52 ;
else if ( ! strcmp ( * args , L_9 ) ) V_17 = 1 ;
else if ( ! strcmp ( * args , L_10 ) ) V_22 = 1 ;
else if ( ! strcmp ( * args , L_11 ) ) V_29 = 0 ;
else if ( ! strcmp ( * args , L_12 ) )
V_24 = V_27 ;
else if ( ! strcmp ( * args , L_13 ) ) V_15 = 1 ;
else if ( ! strcmp ( * args , L_14 ) ) V_42 = F_4 () ;
#ifndef F_5
else if ( ! strcmp ( * args , L_15 ) ) V_42 = F_6 () ;
#endif
else if ( ! strcmp ( * args , L_16 ) ) V_42 = F_2 () ;
else if ( ! strcmp ( * args , L_17 ) ) V_19 = 1 ;
else if ( ! strcmp ( * args , L_18 ) )
V_21 = V_20 ;
else if ( ! strcmp ( * args , L_19 ) )
V_21 = 1 ;
else if ( ! strcmp ( * args , L_20 ) ) V_42 = NULL ;
else if ( ! strcmp ( * args , L_21 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_24 = F_7 ( * args ) ;
if( V_24 == V_53 ) {
F_8 ( V_43 ,
L_22 , * args ) ;
V_18 = 1 ;
}
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_23 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_26 = F_7 ( * args ) ;
if( V_26 == V_53 ) {
F_8 ( V_43 ,
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
if ( ! V_31 ) V_31 = F_9 () ;
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
} else if ( ! strcmp ( * args , L_34 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_40 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_35 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_41 = * args ;
} else V_18 = 1 ;
} else V_18 = 1 ;
} else V_18 = 1 ;
args ++ ;
}
if ( V_18 ) {
F_8 ( V_43 , L_36 ) ;
F_8 ( V_43 , L_37 ) ;
F_8 ( V_43 , L_38 ) ;
F_8 ( V_43 , L_39 ) ;
F_8 ( V_43 , L_40 ) ;
F_8 ( V_43 , L_41 ) ;
F_8 ( V_43 , L_42 ) ;
F_8 ( V_43 , L_43 ) ;
F_8 ( V_43 , L_44 ) ;
F_8 ( V_43 , L_45 ) ;
F_8 ( V_43 , L_46 ) ;
F_8 ( V_43 , L_47 ) ;
F_8 ( V_43 , L_48 ) ;
F_8 ( V_43 , L_49 ) ;
F_8 ( V_43 , L_50 ) ;
F_8 ( V_43 , L_51 ) ;
F_8 ( V_43 , L_52 ) ;
F_8 ( V_43 , L_53 ) ;
F_8 ( V_43 , L_54 ) ;
F_8 ( V_43 , L_55 ) ;
F_8 ( V_43 , L_56 ) ;
#ifndef F_5
F_8 ( V_43 , L_57 ) ;
#endif
F_8 ( V_43 , L_58 ) ;
F_8 ( V_43 , L_59 ) ;
F_8 ( V_43 , L_60 ) ;
F_8 ( V_43 , L_61 ) ;
F_8 ( V_43 , L_62 ) ;
F_8 ( V_43 , L_63 ) ;
F_8 ( V_43 , L_64 ) ;
F_8 ( V_43 , L_65 ) ;
F_8 ( V_43 , L_66 ) ;
F_8 ( V_43 , L_67 ) ;
F_8 ( V_43 , L_68 ) ;
F_8 ( V_43 , L_69 ) ;
F_8 ( V_43 , L_70 , V_54 , V_54 ) ;
F_8 ( V_43 , L_71 ) ;
F_8 ( V_43 , L_72 ) ;
goto V_55;
}
if( V_36 ) {
if( V_15 ) V_35 = V_36 ;
else V_34 = V_36 ;
}
if( ! F_11 ( V_43 , V_34 , V_35 , & V_37 , & V_38 ) ) {
F_8 ( V_43 , L_73 ) ;
goto V_55;
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
F_12 ( NULL , V_43 , ( V_39 != NULL ) ) ;
if ( V_39 != NULL )
F_8 ( V_43 , L_74 ,
F_13 ( V_39 ) ) ;
}
F_14 () ;
#ifdef F_15
F_16 ( L_75 ) ;
#endif
if ( ! V_3 ) V_7 = F_3 ( V_56 , V_45 ) ;
else V_7 = F_17 ( V_3 , L_76 ) ;
if ( ! V_7 ) {
F_8 ( V_43 , L_77 ,
V_3 ? V_3 : L_78 ) ;
perror ( V_3 ) ;
goto V_55;
}
if ( V_6 ) {
if( ! ( V_10 = F_17 ( V_6 , L_79 ) ) ) {
F_8 ( V_43 , L_80 , V_6 ) ;
perror ( V_6 ) ;
goto V_55;
}
}
if ( V_5 ) {
if( ! ( V_9 = F_17 ( V_5 , L_79 ) ) ) {
F_8 ( V_43 , L_81 , V_5 ) ;
perror ( V_5 ) ;
goto V_55;
}
}
#ifdef F_15
F_18 () ;
F_16 ( L_82 ) ;
#endif
if ( ! V_4 ) {
V_8 = F_3 ( stdout , V_45 ) ;
#ifdef F_19
{
T_1 * V_57 = F_20 ( F_21 () ) ;
V_8 = F_22 ( V_57 , V_8 ) ;
}
#endif
} else V_8 = F_17 ( V_4 , L_83 ) ;
if ( ! V_8 ) {
F_8 ( V_43 , L_84 ,
V_4 ? V_4 : L_85 ) ;
perror ( V_4 ) ;
goto V_55;
}
if ( V_22 ) {
#ifdef F_15
F_16 ( L_86 ) ;
#endif
if( F_23 ( V_14 , 50 , L_87 , V_15 ) )
{
F_8 ( V_43 , L_88 ) ;
goto V_55;
}
#ifdef F_15
F_18 () ;
#endif
}
if ( V_15 ) {
T_4 * V_58 = NULL ;
F_24 ( V_59 ) * V_60 = NULL ;
F_24 ( V_61 ) * V_62 = NULL ;
V_59 * V_63 = NULL ;
T_5 * V_64 = NULL ;
V_61 * V_65 = NULL ;
T_6 * V_66 = NULL ;
F_24 ( T_6 ) * V_67 = NULL ;
char * V_68 = NULL ;
int V_69 ;
unsigned char V_70 [ V_71 ] ;
unsigned int V_72 = 0 ;
#ifdef F_15
F_16 ( L_89 ) ;
F_16 ( L_90 ) ;
#endif
V_58 = F_25 ( V_9 ? V_9 : V_7 , NULL , NULL , V_37 ) ;
if ( ! V_9 ) ( void ) F_26 ( V_7 ) ;
else F_27 ( V_9 ) ;
if ( ! V_58 ) {
F_8 ( V_43 , L_91 ) ;
F_28 ( V_43 ) ;
goto V_73;
}
#ifdef F_15
F_18 () ;
F_16 ( L_92 ) ;
#endif
V_67 = F_29 () ;
if( ! F_30 ( V_7 , V_67 ) ) {
F_8 ( V_43 , L_93 ) ;
F_28 ( V_43 ) ;
goto V_73;
}
#ifdef F_15
F_18 () ;
F_16 ( L_94 ) ;
#endif
for( V_69 = 0 ; V_69 < F_31 ( V_67 ) ; V_69 ++ ) {
V_66 = F_32 ( V_67 , V_69 ) ;
if( F_33 ( V_66 , V_58 ) ) {
F_34 ( V_66 , F_35 () , V_70 , & V_72 ) ;
break;
}
}
if( ! V_72 ) {
V_66 = NULL ;
F_8 ( V_43 , L_95 ) ;
goto V_73;
}
#ifdef F_15
F_18 () ;
F_16 ( L_96 ) ;
#endif
V_60 = F_36 () ;
if ( V_10 ) {
if( ! F_30 ( V_10 , V_67 ) ) {
F_8 ( V_43 , L_97 ) ;
F_28 ( V_43 ) ;
goto V_73;
}
F_27 ( V_10 ) ;
}
#ifdef F_15
F_18 () ;
F_16 ( L_98 ) ;
#endif
if ( V_17 ) {
int V_74 ;
F_24 ( T_6 ) * V_75 ;
T_7 * V_76 = F_37 () ;
if ( ! V_76 )
{
F_8 ( V_43 , L_99 ) ;
goto V_73;
}
if ( ! F_38 ( V_76 , V_41 , V_40 ) )
F_39 ( V_76 ) ;
V_74 = F_40 ( V_66 , V_76 , & V_75 ) ;
F_41 ( V_76 ) ;
if ( ! V_74 ) {
for ( V_69 = 1 ; V_69 < F_31 ( V_75 ) ; V_69 ++ )
F_42 ( V_67 , F_32 ( V_75 , V_69 ) ) ;
}
F_43 ( V_75 ) ;
if ( V_74 ) {
F_8 ( V_43 , L_100 ,
F_44 ( V_74 ) ) ;
goto V_73;
}
}
#ifdef F_15
F_18 () ;
F_16 ( L_101 ) ;
#endif
for( V_69 = 0 ; V_69 < F_31 ( V_67 ) ; V_69 ++ ) {
T_6 * V_77 = NULL ;
V_77 = F_32 ( V_67 , V_69 ) ;
V_63 = F_45 ( V_77 ) ;
if( V_77 == V_66 ) {
if( V_11 ) F_46 ( V_63 , V_11 , - 1 ) ;
F_47 ( V_63 , V_70 , V_72 ) ;
} else if( ( V_68 = F_48 ( V_31 ) ) )
F_46 ( V_63 , V_68 , - 1 ) ;
F_49 ( V_60 , V_63 ) ;
}
F_50 ( V_67 , V_78 ) ;
V_67 = NULL ;
V_66 = NULL ;
#ifdef F_15
F_18 () ;
F_16 ( L_102 ) ;
#endif
if( ! V_30 &&
F_23 ( V_13 , 50 , L_103 , 1 ) ) {
F_8 ( V_43 , L_88 ) ;
goto V_73;
}
if ( ! V_22 ) strcpy ( V_14 , V_13 ) ;
V_65 = F_51 ( V_24 , V_32 , - 1 , NULL , 0 ,
V_19 , V_60 ) ;
F_52 ( V_60 , V_79 ) ;
V_60 = NULL ;
if ( ! V_65 ) {
F_28 ( V_43 ) ;
goto V_73;
}
V_62 = F_53 () ;
F_54 ( V_62 , V_65 ) ;
#ifdef F_15
F_18 () ;
F_16 ( L_104 ) ;
#endif
V_64 = F_55 ( V_58 ) ;
if( V_23 ) F_56 ( V_64 , V_23 ) ;
V_63 = F_57 ( V_26 , V_32 , - 1 , NULL , 0 , V_19 , V_64 ) ;
F_58 ( V_64 ) ;
V_64 = NULL ;
if ( V_11 ) F_46 ( V_63 , V_11 , - 1 ) ;
F_47 ( V_63 , V_70 , V_72 ) ;
V_60 = F_36 () ;
F_49 ( V_60 , V_63 ) ;
#ifdef F_15
F_18 () ;
F_16 ( L_105 ) ;
#endif
V_65 = F_59 ( V_60 ) ;
F_52 ( V_60 , V_79 ) ;
V_60 = NULL ;
F_54 ( V_62 , V_65 ) ;
#ifdef F_15
F_18 () ;
F_16 ( L_106 ) ;
#endif
V_12 = F_60 ( V_80 ) ;
F_61 ( V_12 , V_62 ) ;
F_62 ( V_62 , V_81 ) ;
V_62 = NULL ;
F_63 ( V_12 , V_33 , - 1 , NULL , 0 , V_21 , NULL ) ;
#ifdef F_15
F_18 () ;
F_16 ( L_107 ) ;
#endif
F_64 ( V_8 , V_12 ) ;
V_28 = 0 ;
V_73:
#ifdef F_15
F_18 () ;
F_18 () ;
F_16 ( L_108 ) ;
#endif
if ( V_58 ) F_65 ( V_58 ) ;
if ( V_67 ) F_50 ( V_67 , V_78 ) ;
if ( V_62 ) F_62 ( V_62 , V_81 ) ;
if ( V_60 ) F_52 ( V_60 , V_79 ) ;
if ( V_66 ) V_78 ( V_66 ) ;
#ifdef F_15
F_18 () ;
#endif
goto V_55;
}
if ( ! ( V_12 = F_66 ( V_7 , NULL ) ) ) {
F_28 ( V_43 ) ;
goto V_55;
}
#ifdef F_15
F_16 ( L_109 ) ;
#endif
if( ! V_30 && F_23 ( V_13 , 50 , L_110 , 0 ) ) {
F_8 ( V_43 , L_88 ) ;
goto V_55;
}
#ifdef F_15
F_18 () ;
#endif
if ( ! V_22 ) strcpy ( V_14 , V_13 ) ;
if ( V_16 & V_52 ) F_8 ( V_43 , L_111 , V_12 -> V_82 -> V_19 ? F_67 ( V_12 -> V_82 -> V_19 ) : 1 ) ;
if( V_29 ) {
#ifdef F_15
F_16 ( L_112 ) ;
#endif
if( ! V_14 [ 0 ] && F_68 ( V_12 , NULL , 0 ) ) {
if( ! V_22 ) V_32 = NULL ;
} else if ( ! F_68 ( V_12 , V_33 , - 1 ) ) {
F_8 ( V_43 , L_113 ) ;
F_28 ( V_43 ) ;
goto V_55;
}
F_8 ( V_43 , L_114 ) ;
#ifdef F_15
F_18 () ;
#endif
}
#ifdef F_15
F_16 ( L_115 ) ;
#endif
if ( ! F_69 ( V_8 , V_12 , V_32 , - 1 , V_16 , V_38 ) ) {
F_8 ( V_43 , L_116 ) ;
F_28 ( V_43 ) ;
goto V_55;
}
#ifdef F_15
F_18 () ;
#endif
V_28 = 0 ;
V_55:
if ( V_12 ) F_70 ( V_12 ) ;
if( V_15 || V_39 ) F_71 ( NULL , V_43 ) ;
#ifdef F_15
F_72 () ;
#endif
F_27 ( V_7 ) ;
F_73 ( V_8 ) ;
if ( V_31 ) F_74 ( V_31 ) ;
if( V_37 ) F_75 ( V_37 ) ;
if( V_38 ) F_75 ( V_38 ) ;
EXIT ( V_28 ) ;
}
int F_69 ( T_1 * V_8 , T_2 * V_12 , char * V_13 ,
int V_83 , int V_16 , char * V_84 )
{
F_24 ( V_61 ) * V_85 ;
F_24 ( V_59 ) * V_60 ;
int V_69 , V_86 ;
V_61 * V_87 ;
if ( ! ( V_85 = F_76 ( V_12 ) ) ) return 0 ;
for ( V_69 = 0 ; V_69 < F_77 ( V_85 ) ; V_69 ++ ) {
V_87 = F_78 ( V_85 , V_69 ) ;
V_86 = F_79 ( V_87 -> type ) ;
if ( V_86 == V_80 ) {
V_60 = F_80 ( V_87 ) ;
if ( V_16 & V_52 ) F_8 ( V_43 , L_117 ) ;
} else if ( V_86 == V_88 ) {
if ( V_16 & V_52 ) {
F_8 ( V_43 , L_118 ) ;
F_81 ( V_43 ,
V_87 -> V_89 . V_90 -> V_91 -> V_92 ) ;
}
V_60 = F_82 ( V_87 , V_13 , V_83 ) ;
} else continue;
if ( ! V_60 ) return 0 ;
if ( ! F_83 ( V_8 , V_60 , V_13 , V_83 ,
V_16 , V_84 ) ) {
F_52 ( V_60 , V_79 ) ;
return 0 ;
}
F_52 ( V_60 , V_79 ) ;
}
F_62 ( V_85 , V_81 ) ;
return 1 ;
}
int F_84 ( T_1 * V_8 , V_59 * V_63 , char * V_13 ,
int V_83 , int V_16 , char * V_84 )
{
T_4 * V_93 ;
T_5 * V_64 ;
T_6 * V_94 ;
switch ( F_85 ( V_63 ) )
{
case V_95 :
if ( V_16 & V_52 ) F_8 ( V_43 , L_119 ) ;
if ( V_16 & V_46 ) return 1 ;
F_86 ( V_8 , V_63 -> V_96 , L_120 ) ;
V_64 = V_63 -> V_97 . V_98 ;
if ( ! ( V_93 = F_87 ( V_64 ) ) ) return 0 ;
F_86 ( V_8 , V_64 -> V_99 , L_121 ) ;
F_88 ( V_8 , V_93 , V_42 , NULL , 0 , NULL , V_84 ) ;
F_65 ( V_93 ) ;
break;
case V_100 :
if ( V_16 & V_52 ) {
F_8 ( V_43 , L_122 ) ;
F_81 ( V_43 , V_63 -> V_97 . V_101 -> V_102 ) ;
}
if ( V_16 & V_46 ) return 1 ;
F_86 ( V_8 , V_63 -> V_96 , L_120 ) ;
if ( ! ( V_64 = F_89 ( V_63 , V_13 , V_83 ) ) )
return 0 ;
if ( ! ( V_93 = F_87 ( V_64 ) ) ) return 0 ;
F_86 ( V_8 , V_64 -> V_99 , L_121 ) ;
F_58 ( V_64 ) ;
F_88 ( V_8 , V_93 , V_42 , NULL , 0 , NULL , V_84 ) ;
F_65 ( V_93 ) ;
break;
case V_103 :
if ( V_16 & V_52 ) F_8 ( V_43 , L_123 ) ;
if ( V_16 & V_49 ) return 1 ;
if ( F_90 ( V_63 , V_104 ) ) {
if ( V_16 & V_51 ) return 1 ;
} else if ( V_16 & V_50 ) return 1 ;
F_86 ( V_8 , V_63 -> V_96 , L_120 ) ;
if ( F_91 ( V_63 ) != V_105 )
return 1 ;
if ( ! ( V_94 = F_92 ( V_63 ) ) ) return 0 ;
F_93 ( V_8 , V_94 ) ;
F_94 ( V_8 , V_94 ) ;
V_78 ( V_94 ) ;
break;
case V_106 :
if ( V_16 & V_52 ) F_8 ( V_43 , L_124 ) ;
F_86 ( V_8 , V_63 -> V_96 , L_120 ) ;
return F_83 ( V_8 , V_63 -> V_97 . V_62 , V_13 ,
V_83 , V_16 , V_84 ) ;
default:
F_8 ( V_43 , L_125 ) ;
F_95 ( V_43 , V_63 -> type ) ;
F_8 ( V_43 , L_126 ) ;
return 1 ;
break;
}
return 1 ;
}
int F_81 ( T_1 * V_107 , T_8 * V_108 )
{
T_9 * V_109 ;
unsigned char * V_110 ;
V_110 = V_108 -> V_111 -> V_97 . V_112 -> V_113 ;
V_109 = F_96 ( NULL , & V_110 , V_108 -> V_111 -> V_97 . V_112 -> V_114 ) ;
F_8 ( V_43 , L_127 ,
F_97 ( F_79 ( V_108 -> V_92 ) ) , F_67 ( V_109 -> V_19 ) ) ;
F_98 ( V_109 ) ;
return 0 ;
}
void F_99 ( T_1 * V_8 , unsigned char * V_115 , int V_116 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_116 ; V_69 ++ ) F_8 ( V_8 , L_128 , V_115 [ V_69 ] ) ;
}
