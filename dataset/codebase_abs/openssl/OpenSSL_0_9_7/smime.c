int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 0 ;
int V_5 = 0 ;
char * * args ;
char * V_6 = L_1 , * V_7 = L_2 ;
char * V_8 = NULL , * V_9 = NULL ;
char * V_10 = NULL , * V_11 = NULL ;
char * V_12 = NULL , * V_13 = NULL , * V_14 = NULL ;
const T_2 * V_15 = NULL ;
T_3 * V_16 = NULL ;
T_4 * V_17 = NULL ;
T_5 * V_18 = NULL , * V_19 = NULL , * V_20 = NULL ;
T_6 * V_21 = NULL ;
F_1 ( T_5 ) * V_22 = NULL , * V_23 = NULL ;
T_7 * V_24 = NULL , * V_25 = NULL , * V_26 = NULL ;
int V_27 = 0 ;
int V_28 = V_29 , V_30 = 0 ;
char * V_31 = NULL , * V_32 = NULL , * V_33 = NULL ;
char * V_34 = NULL , * V_35 = NULL ;
char * V_36 = NULL , * V_37 = NULL ;
char * V_38 = NULL ;
int V_39 = 0 ;
int V_40 = V_41 , V_42 = V_41 ;
int V_43 = V_44 ;
char * V_45 = NULL ;
args = V_2 + 1 ;
V_5 = 1 ;
F_2 () ;
if ( V_46 == NULL )
if ( ( V_46 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_46 , V_47 , V_48 | V_49 ) ;
if ( ! F_6 ( V_46 , NULL ) )
goto V_50;
while ( ! V_27 && * args && * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_3 ) ) V_4 = V_51 ;
else if ( ! strcmp ( * args , L_4 ) ) V_4 = V_52 ;
else if ( ! strcmp ( * args , L_5 ) ) V_4 = V_53 ;
else if ( ! strcmp ( * args , L_6 ) ) V_4 = V_54 ;
else if ( ! strcmp ( * args , L_7 ) ) V_4 = V_55 ;
#ifndef F_7
else if ( ! strcmp ( * args , L_8 ) )
V_15 = F_8 () ;
else if ( ! strcmp ( * args , L_9 ) )
V_15 = F_9 () ;
#endif
#ifndef F_10
else if ( ! strcmp ( * args , L_10 ) )
V_15 = F_11 () ;
else if ( ! strcmp ( * args , L_11 ) )
V_15 = F_12 () ;
else if ( ! strcmp ( * args , L_12 ) )
V_15 = F_13 () ;
#endif
#ifndef F_14
else if ( ! strcmp ( * args , L_13 ) )
V_15 = F_15 () ;
else if ( ! strcmp ( * args , L_14 ) )
V_15 = F_16 () ;
else if ( ! strcmp ( * args , L_15 ) )
V_15 = F_17 () ;
#endif
else if ( ! strcmp ( * args , L_16 ) )
V_28 |= V_56 ;
else if ( ! strcmp ( * args , L_17 ) )
V_28 |= V_57 ;
else if ( ! strcmp ( * args , L_18 ) )
V_28 |= V_58 ;
else if ( ! strcmp ( * args , L_19 ) )
V_28 |= V_59 ;
else if ( ! strcmp ( * args , L_20 ) )
V_28 |= V_60 ;
else if ( ! strcmp ( * args , L_21 ) )
V_28 |= V_61 ;
else if ( ! strcmp ( * args , L_22 ) )
V_28 &= ~ V_29 ;
else if ( ! strcmp ( * args , L_23 ) )
V_28 |= V_62 ;
else if ( ! strcmp ( * args , L_24 ) )
V_28 |= V_63 ;
else if ( ! strcmp ( * args , L_25 ) )
V_28 |= V_64 ;
else if ( ! strcmp ( * args , L_26 ) )
V_30 |= V_65 ;
else if ( ! strcmp ( * args , L_27 ) )
V_30 |= V_65 | V_66 ;
else if ( ! strcmp ( * args , L_28 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_38 = * args ;
} else V_27 = 1 ;
V_39 = 1 ;
} else if ( ! strcmp ( * args , L_29 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_45 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_30 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_36 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_31 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_31 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_32 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_32 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_33 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_33 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_34 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_10 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_35 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_11 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_36 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_13 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_37 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_43 = F_18 ( * args ) ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_38 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_12 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_39 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_34 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_40 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_35 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_41 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_8 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_42 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_40 = F_18 ( * args ) ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_43 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_42 = F_18 ( * args ) ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_44 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_9 = * args ;
} else V_27 = 1 ;
} else if ( ! strcmp ( * args , L_45 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_14 = * args ;
} else V_27 = 1 ;
} else V_27 = 1 ;
args ++ ;
}
if( V_4 == V_53 ) {
if( ! V_10 ) {
F_19 ( V_46 , L_46 ) ;
V_27 = 1 ;
}
V_39 = 1 ;
} else if( V_4 == V_52 ) {
if( ! V_11 ) {
F_19 ( V_46 , L_47 ) ;
V_27 = 1 ;
}
} else if( V_4 == V_51 ) {
if( ! * args ) {
F_19 ( V_46 , L_48 ) ;
V_27 = 1 ;
}
V_39 = 1 ;
} else if( ! V_4 ) V_27 = 1 ;
if ( V_27 ) {
F_19 ( V_46 , L_49 ) ;
F_19 ( V_46 , L_50 ) ;
F_19 ( V_46 , L_51 ) ;
F_19 ( V_46 , L_52 ) ;
F_19 ( V_46 , L_53 ) ;
F_19 ( V_46 , L_54 ) ;
F_19 ( V_46 , L_55 ) ;
#ifndef F_7
F_19 ( V_46 , L_56 ) ;
F_19 ( V_46 , L_57 ) ;
#endif
#ifndef F_10
F_19 ( V_46 , L_58 ) ;
F_19 ( V_46 , L_59 ) ;
F_19 ( V_46 , L_60 ) ;
#endif
#ifndef F_14
F_19 ( V_46 , L_61 ) ;
F_19 ( V_46 , L_62 ) ;
#endif
F_19 ( V_46 , L_63 ) ;
F_19 ( V_46 , L_64 ) ;
F_19 ( V_46 , L_65 ) ;
F_19 ( V_46 , L_66 ) ;
F_19 ( V_46 , L_67 ) ;
F_19 ( V_46 , L_68 ) ;
F_19 ( V_46 , L_69 ) ;
F_19 ( V_46 , L_70 ) ;
F_19 ( V_46 , L_71 ) ;
F_19 ( V_46 , L_72 ) ;
F_19 ( V_46 , L_73 ) ;
F_19 ( V_46 , L_74 ) ;
F_19 ( V_46 , L_75 ) ;
F_19 ( V_46 , L_76 ) ;
F_19 ( V_46 , L_77 ) ;
F_19 ( V_46 , L_78 ) ;
F_19 ( V_46 , L_79 ) ;
F_19 ( V_46 , L_80 ) ;
F_19 ( V_46 , L_81 ) ;
F_19 ( V_46 , L_82 ) ;
F_19 ( V_46 , L_83 ) ;
F_19 ( V_46 , L_84 ) ;
F_19 ( V_46 , L_85 ) ;
F_19 ( V_46 , L_86 ) ;
F_19 ( V_46 , L_87 ) ;
F_19 ( V_46 , L_88 ) ;
F_19 ( V_46 , L_89 ) ;
F_19 ( V_46 , L_90 , V_67 , V_67 ) ;
F_19 ( V_46 , L_91 ) ;
F_19 ( V_46 , L_92 ) ;
F_19 ( V_46 , L_93 ) ;
goto V_50;
}
V_3 = F_20 ( V_46 , V_45 , 0 ) ;
if( ! F_21 ( V_46 , V_36 , NULL , & V_37 , NULL ) ) {
F_19 ( V_46 , L_94 ) ;
goto V_50;
}
if ( V_39 ) {
F_22 ( NULL , V_46 , ( V_38 != NULL ) ) ;
if ( V_38 != NULL )
F_19 ( V_46 , L_95 ,
F_23 ( V_38 ) ) ;
}
V_5 = 2 ;
if( V_4 != V_53 ) V_28 &= ~ V_29 ;
if( V_4 & V_68 ) {
if( V_28 & V_63 ) V_6 = L_96 ;
if( V_42 == V_69 ) V_7 = L_97 ;
} else {
if( V_28 & V_63 ) V_7 = L_97 ;
if( V_40 == V_69 ) V_6 = L_96 ;
}
if( V_4 == V_51 ) {
if ( ! V_15 ) {
#ifndef F_10
V_15 = F_11 () ;
#else
F_19 ( V_46 , L_98 ) ;
goto V_50;
#endif
}
V_22 = F_24 () ;
while ( * args ) {
if( ! ( V_18 = F_25 ( V_46 , * args , V_44 ,
NULL , V_3 , L_99 ) ) ) {
#if 0
BIO_printf(bio_err, "Can't read recipient certificate file %s\n", *args);
#endif
goto V_50;
}
F_26 ( V_22 , V_18 ) ;
V_18 = NULL ;
args ++ ;
}
}
if( V_10 && ( V_4 == V_53 ) ) {
if( ! ( V_20 = F_25 ( V_46 , V_10 , V_44 , NULL ,
V_3 , L_100 ) ) ) {
#if 0
BIO_printf(bio_err, "Can't read signer certificate file %s\n", signerfile);
#endif
goto V_50;
}
}
if( V_12 ) {
if( ! ( V_23 = F_27 ( V_46 , V_12 , V_44 , NULL ,
V_3 , L_101 ) ) ) {
#if 0
BIO_printf(bio_err, "Can't read certificate file %s\n", certfile);
#endif
F_28 ( V_46 ) ;
goto V_50;
}
}
if( V_11 && ( V_4 == V_52 ) ) {
if( ! ( V_19 = F_25 ( V_46 , V_11 , V_44 , NULL ,
V_3 , L_99 ) ) ) {
#if 0
BIO_printf(bio_err, "Can't read recipient certificate file %s\n", recipfile);
#endif
F_28 ( V_46 ) ;
goto V_50;
}
}
if( V_4 == V_52 ) {
if( ! V_13 ) V_13 = V_11 ;
} else if( V_4 == V_53 ) {
if( ! V_13 ) V_13 = V_10 ;
} else V_13 = NULL ;
if( V_13 ) {
V_21 = F_29 ( V_46 , V_13 , V_43 , 0 , V_37 , V_3 ,
L_102 ) ;
if ( ! V_21 ) {
goto V_50;
}
}
if ( V_8 ) {
if ( ! ( V_24 = F_30 ( V_8 , V_6 ) ) ) {
F_19 ( V_46 ,
L_103 , V_8 ) ;
goto V_50;
}
} else V_24 = F_31 ( V_70 , V_48 ) ;
if ( V_9 ) {
if ( ! ( V_25 = F_30 ( V_9 , V_7 ) ) ) {
F_19 ( V_46 ,
L_104 , V_9 ) ;
goto V_50;
}
} else {
V_25 = F_31 ( stdout , V_48 ) ;
#ifdef F_32
{
T_7 * V_71 = F_3 ( F_33 () ) ;
V_25 = F_34 ( V_71 , V_25 ) ;
}
#endif
}
if( V_4 == V_54 ) {
if( ! ( V_17 = F_35 ( V_46 , V_34 , V_35 ) ) ) goto V_50;
F_36 ( V_17 , V_30 ) ;
}
V_5 = 3 ;
if( V_4 == V_51 ) {
V_16 = F_37 ( V_22 , V_24 , V_15 , V_28 ) ;
} else if( V_4 == V_53 ) {
V_16 = F_38 ( V_20 , V_21 , V_23 , V_24 , V_28 ) ;
if ( F_39 ( V_24 ) != 0 && ( V_28 & V_29 ) ) {
F_19 ( V_46 , L_105 ) ;
goto V_50;
}
} else {
if( V_40 == V_41 )
V_16 = F_40 ( V_24 , & V_26 ) ;
else if( V_40 == V_44 )
V_16 = F_41 ( V_24 , NULL , NULL , NULL ) ;
else if( V_40 == V_69 )
V_16 = F_42 ( V_24 , NULL ) ;
else {
F_19 ( V_46 , L_106 ) ;
goto V_50;
}
if( ! V_16 ) {
F_19 ( V_46 , L_107 ) ;
goto V_50;
}
if( V_14 ) {
F_43 ( V_26 ) ;
if( ! ( V_26 = F_30 ( V_14 , L_96 ) ) ) {
F_19 ( V_46 , L_108 , V_14 ) ;
goto V_50;
}
}
}
if( ! V_16 ) {
F_19 ( V_46 , L_109 ) ;
goto V_50;
}
V_5 = 4 ;
if( V_4 == V_52 ) {
if( ! F_44 ( V_16 , V_21 , V_19 , V_25 , V_28 ) ) {
F_19 ( V_46 , L_110 ) ;
goto V_50;
}
} else if( V_4 == V_54 ) {
F_1 ( T_5 ) * V_72 ;
if( F_45 ( V_16 , V_23 , V_17 , V_26 , V_25 , V_28 ) ) {
F_19 ( V_46 , L_111 ) ;
} else {
F_19 ( V_46 , L_112 ) ;
goto V_50;
}
V_72 = F_46 ( V_16 , V_23 , V_28 ) ;
if( ! F_47 ( V_10 , V_72 ) ) {
F_19 ( V_46 , L_113 ,
V_10 ) ;
V_5 = 5 ;
goto V_50;
}
F_48 ( V_72 ) ;
} else if( V_4 == V_55 ) {
F_49 ( V_25 , V_16 ) ;
} else {
if( V_31 ) F_19 ( V_25 , L_114 , V_31 ) ;
if( V_32 ) F_19 ( V_25 , L_115 , V_32 ) ;
if( V_33 ) F_19 ( V_25 , L_116 , V_33 ) ;
if( V_42 == V_41 )
F_50 ( V_25 , V_16 , V_24 , V_28 ) ;
else if( V_42 == V_44 )
F_49 ( V_25 , V_16 ) ;
else if( V_42 == V_69 )
F_51 ( V_25 , V_16 ) ;
else {
F_19 ( V_46 , L_117 ) ;
goto V_50;
}
}
V_5 = 0 ;
V_50:
if ( V_39 )
F_52 ( NULL , V_46 ) ;
if( V_5 ) F_28 ( V_46 ) ;
F_53 ( V_22 , V_73 ) ;
F_53 ( V_23 , V_73 ) ;
F_54 ( V_17 ) ;
V_73 ( V_18 ) ;
V_73 ( V_19 ) ;
V_73 ( V_20 ) ;
F_55 ( V_21 ) ;
F_56 ( V_16 ) ;
F_43 ( V_24 ) ;
F_43 ( V_26 ) ;
F_57 ( V_25 ) ;
if( V_37 ) F_58 ( V_37 ) ;
return ( V_5 ) ;
}
