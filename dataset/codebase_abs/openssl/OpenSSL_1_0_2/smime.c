int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 0 ;
int V_5 = 0 ;
char * * args ;
const char * V_6 = L_1 , * V_7 = L_2 ;
char * V_8 = NULL , * V_9 = NULL ;
char * V_10 = NULL , * V_11 = NULL ;
F_1 ( V_12 ) * V_13 = NULL , * V_14 = NULL ;
char * V_15 = NULL , * V_16 = NULL , * V_17 = NULL ;
const T_2 * V_18 = NULL ;
T_3 * V_19 = NULL ;
T_4 * V_20 = NULL ;
T_5 * V_21 = NULL , * V_22 = NULL , * V_23 = NULL ;
T_6 * V_24 = NULL ;
F_1 ( T_5 ) * V_25 = NULL , * V_26 = NULL ;
T_7 * V_27 = NULL , * V_28 = NULL , * V_29 = NULL ;
int V_30 = 0 ;
int V_31 = V_32 ;
char * V_33 = NULL , * V_34 = NULL , * V_35 = NULL ;
char * V_36 = NULL , * V_37 = NULL ;
char * V_38 = NULL , * V_39 = NULL ;
char * V_40 = NULL ;
int V_41 = 0 ;
int V_42 = 0 ;
const T_8 * V_43 = NULL ;
int V_44 = V_45 , V_46 = V_45 ;
int V_47 = V_48 ;
#ifndef F_2
char * V_49 = NULL ;
#endif
T_9 * V_50 = NULL ;
args = V_2 + 1 ;
V_5 = 1 ;
F_3 () ;
if ( V_51 == NULL ) {
if ( ( V_51 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_51 , V_52 , V_53 | V_54 ) ;
}
if ( ! F_7 ( V_51 , NULL ) )
goto V_55;
while ( ! V_30 && * args && * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_3 ) )
V_4 = V_56 ;
else if ( ! strcmp ( * args , L_4 ) )
V_4 = V_57 ;
else if ( ! strcmp ( * args , L_5 ) )
V_4 = V_58 ;
else if ( ! strcmp ( * args , L_6 ) )
V_4 = V_59 ;
else if ( ! strcmp ( * args , L_7 ) )
V_4 = V_60 ;
else if ( ! strcmp ( * args , L_8 ) )
V_4 = V_61 ;
#ifndef F_8
else if ( ! strcmp ( * args , L_9 ) )
V_18 = F_9 () ;
else if ( ! strcmp ( * args , L_10 ) )
V_18 = F_10 () ;
#endif
#ifndef F_11
else if ( ! strcmp ( * args , L_11 ) )
V_18 = F_12 () ;
#endif
#ifndef F_13
else if ( ! strcmp ( * args , L_12 ) )
V_18 = F_14 () ;
else if ( ! strcmp ( * args , L_13 ) )
V_18 = F_15 () ;
else if ( ! strcmp ( * args , L_14 ) )
V_18 = F_16 () ;
#endif
#ifndef F_17
else if ( ! strcmp ( * args , L_15 ) )
V_18 = F_18 () ;
else if ( ! strcmp ( * args , L_16 ) )
V_18 = F_19 () ;
else if ( ! strcmp ( * args , L_17 ) )
V_18 = F_20 () ;
#endif
#ifndef F_21
else if ( ! strcmp ( * args , L_18 ) )
V_18 = F_22 () ;
else if ( ! strcmp ( * args , L_19 ) )
V_18 = F_23 () ;
else if ( ! strcmp ( * args , L_20 ) )
V_18 = F_24 () ;
#endif
else if ( ! strcmp ( * args , L_21 ) )
V_31 |= V_62 ;
else if ( ! strcmp ( * args , L_22 ) )
V_31 |= V_63 ;
else if ( ! strcmp ( * args , L_23 ) )
V_31 |= V_64 ;
else if ( ! strcmp ( * args , L_24 ) )
V_31 |= V_65 ;
else if ( ! strcmp ( * args , L_25 ) )
V_31 |= V_66 ;
else if ( ! strcmp ( * args , L_26 ) )
V_31 |= V_67 ;
else if ( ! strcmp ( * args , L_27 ) )
V_31 &= ~ V_32 ;
else if ( ! strcmp ( * args , L_28 ) )
V_31 |= V_68 ;
else if ( ! strcmp ( * args , L_29 ) )
V_31 |= V_69 ;
else if ( ! strcmp ( * args , L_30 ) )
V_31 |= V_70 ;
else if ( ! strcmp ( * args , L_31 ) )
V_42 = 1 ;
else if ( ! strcmp ( * args , L_32 ) )
V_42 = 1 ;
else if ( ! strcmp ( * args , L_33 ) )
V_42 = 0 ;
else if ( ! strcmp ( * args , L_34 ) )
V_31 |= V_71 ;
else if ( ! strcmp ( * args , L_35 ) )
V_31 |= V_72 ;
else if ( ! strcmp ( * args , L_36 ) ) {
if ( ! args [ 1 ] )
goto V_73;
args ++ ;
V_40 = * args ;
V_41 = 1 ;
}
#ifndef F_2
else if ( ! strcmp ( * args , L_37 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_49 = * ++ args ;
}
#endif
else if ( ! strcmp ( * args , L_38 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_38 = * ++ args ;
} else if ( ! strcmp ( * args , L_39 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_33 = * ++ args ;
} else if ( ! strcmp ( * args , L_40 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_34 = * ++ args ;
} else if ( ! strcmp ( * args , L_41 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_35 = * ++ args ;
} else if ( ! strcmp ( * args , L_42 ) ) {
if ( ! args [ 1 ] )
goto V_73;
if ( V_10 ) {
if ( ! V_13 )
V_13 = F_25 () ;
F_26 ( V_13 , V_10 ) ;
if ( ! V_16 )
V_16 = V_10 ;
if ( ! V_14 )
V_14 = F_25 () ;
F_26 ( V_14 , V_16 ) ;
V_16 = NULL ;
}
V_10 = * ++ args ;
} else if ( ! strcmp ( * args , L_43 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_11 = * ++ args ;
} else if ( ! strcmp ( * args , L_44 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_43 = F_27 ( * ++ args ) ;
if ( V_43 == NULL ) {
F_28 ( V_51 , L_45 , * args ) ;
goto V_73;
}
} else if ( ! strcmp ( * args , L_46 ) ) {
if ( ! args [ 1 ] )
goto V_73;
if ( V_16 ) {
if ( ! V_10 ) {
F_29 ( V_51 , L_47 ) ;
goto V_73;
}
if ( ! V_13 )
V_13 = F_25 () ;
F_26 ( V_13 , V_10 ) ;
V_10 = NULL ;
if ( ! V_14 )
V_14 = F_25 () ;
F_26 ( V_14 , V_16 ) ;
}
V_16 = * ++ args ;
} else if ( ! strcmp ( * args , L_48 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_47 = F_30 ( * ++ args ) ;
} else if ( ! strcmp ( * args , L_49 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_15 = * ++ args ;
} else if ( ! strcmp ( * args , L_50 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_36 = * ++ args ;
} else if ( ! strcmp ( * args , L_51 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_37 = * ++ args ;
} else if ( ! strcmp ( * args , L_52 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_8 = * ++ args ;
} else if ( ! strcmp ( * args , L_53 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_44 = F_30 ( * ++ args ) ;
} else if ( ! strcmp ( * args , L_54 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_46 = F_30 ( * ++ args ) ;
} else if ( ! strcmp ( * args , L_55 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_9 = * ++ args ;
} else if ( ! strcmp ( * args , L_56 ) ) {
if ( ! args [ 1 ] )
goto V_73;
V_17 = * ++ args ;
} else if ( F_31 ( & args , NULL , & V_30 , V_51 , & V_50 ) )
continue;
else if ( ( V_18 = F_32 ( * args + 1 ) ) == NULL )
V_30 = 1 ;
args ++ ;
}
if ( ! ( V_4 & V_74 ) && ( V_14 || V_13 ) ) {
F_29 ( V_51 , L_57 ) ;
goto V_73;
}
if ( V_4 & V_74 ) {
if ( V_16 && ! V_10 ) {
F_29 ( V_51 , L_47 ) ;
goto V_73;
}
if ( V_10 ) {
if ( ! V_13 )
V_13 = F_25 () ;
F_26 ( V_13 , V_10 ) ;
if ( ! V_14 )
V_14 = F_25 () ;
if ( ! V_16 )
V_16 = V_10 ;
F_26 ( V_14 , V_16 ) ;
}
if ( ! V_13 ) {
F_28 ( V_51 , L_58 ) ;
V_30 = 1 ;
}
V_10 = NULL ;
V_16 = NULL ;
V_41 = 1 ;
} else if ( V_4 == V_57 ) {
if ( ! V_11 && ! V_16 ) {
F_28 ( V_51 ,
L_59 ) ;
V_30 = 1 ;
}
} else if ( V_4 == V_56 ) {
if ( ! * args ) {
F_28 ( V_51 , L_60 ) ;
V_30 = 1 ;
}
V_41 = 1 ;
} else if ( ! V_4 )
V_30 = 1 ;
if ( V_30 ) {
V_73:
F_28 ( V_51 , L_61 ) ;
F_28 ( V_51 , L_62 ) ;
F_28 ( V_51 , L_63 ) ;
F_28 ( V_51 , L_64 ) ;
F_28 ( V_51 , L_65 ) ;
F_28 ( V_51 , L_66 ) ;
F_28 ( V_51 , L_67 ) ;
#ifndef F_8
F_28 ( V_51 , L_68 ) ;
F_28 ( V_51 , L_69 ) ;
#endif
#ifndef F_11
F_28 ( V_51 , L_70 ) ;
#endif
#ifndef F_13
F_28 ( V_51 , L_71 ) ;
F_28 ( V_51 , L_72 ) ;
F_28 ( V_51 , L_73 ) ;
#endif
#ifndef F_17
F_28 ( V_51 , L_74 ) ;
F_28 ( V_51 ,
L_75 ) ;
#endif
#ifndef F_21
F_28 ( V_51 , L_76 ) ;
F_28 ( V_51 ,
L_77 ) ;
#endif
F_28 ( V_51 ,
L_78 ) ;
F_28 ( V_51 ,
L_79 ) ;
F_28 ( V_51 ,
L_80 ) ;
F_28 ( V_51 ,
L_81 ) ;
F_28 ( V_51 , L_82 ) ;
F_28 ( V_51 ,
L_83 ) ;
F_28 ( V_51 ,
L_84 ) ;
F_28 ( V_51 , L_85 ) ;
F_28 ( V_51 , L_86 ) ;
F_28 ( V_51 ,
L_87 ) ;
F_28 ( V_51 , L_88 ) ;
F_28 ( V_51 ,
L_89 ) ;
F_28 ( V_51 ,
L_90 ) ;
F_28 ( V_51 ,
L_91 ) ;
F_28 ( V_51 , L_92 ) ;
F_28 ( V_51 ,
L_93 ) ;
F_28 ( V_51 ,
L_94 ) ;
F_28 ( V_51 , L_95 ) ;
F_28 ( V_51 , L_96 ) ;
F_28 ( V_51 , L_97 ) ;
F_28 ( V_51 ,
L_98 ) ;
F_28 ( V_51 ,
L_99 ) ;
F_28 ( V_51 , L_100 ) ;
F_28 ( V_51 ,
L_101 ) ;
F_28 ( V_51 ,
L_102 ) ;
#ifndef F_2
F_28 ( V_51 ,
L_103 ) ;
#endif
F_28 ( V_51 , L_104 ) ;
F_28 ( V_51 , L_105 , V_75 ,
V_75 ) ;
F_28 ( V_51 ,
L_106 ) ;
F_28 ( V_51 , L_107 ) ;
F_28 ( V_51 ,
L_108 ) ;
goto V_55;
}
#ifndef F_2
V_3 = F_33 ( V_51 , V_49 , 0 ) ;
#endif
if ( ! F_34 ( V_51 , V_38 , NULL , & V_39 , NULL ) ) {
F_28 ( V_51 , L_109 ) ;
goto V_55;
}
if ( V_41 ) {
F_35 ( NULL , V_51 , ( V_40 != NULL ) ) ;
if ( V_40 != NULL )
F_28 ( V_51 , L_110 ,
F_36 ( V_40 ) ) ;
}
V_5 = 2 ;
if ( ! ( V_4 & V_74 ) )
V_31 &= ~ V_32 ;
if ( V_4 & V_76 ) {
if ( V_46 == V_77 )
V_7 = L_111 ;
} else {
if ( V_31 & V_69 )
V_7 = L_111 ;
}
if ( V_4 & V_78 ) {
if ( V_44 == V_77 )
V_6 = L_112 ;
} else {
if ( V_31 & V_69 )
V_6 = L_112 ;
}
if ( V_4 == V_56 ) {
if ( ! V_18 ) {
#ifndef F_8
V_18 = F_9 () ;
#else
F_28 ( V_51 , L_113 ) ;
goto V_55;
#endif
}
V_25 = F_37 () ;
while ( * args ) {
if ( ! ( V_21 = F_38 ( V_51 , * args , V_48 ,
NULL , V_3 , L_114 ) ) ) {
#if 0
BIO_printf(bio_err,
"Can't read recipient certificate file %s\n",
*args);
#endif
goto V_55;
}
F_39 ( V_25 , V_21 ) ;
V_21 = NULL ;
args ++ ;
}
}
if ( V_15 ) {
if ( ! ( V_26 = F_40 ( V_51 , V_15 , V_48 , NULL ,
V_3 , L_115 ) ) ) {
F_41 ( V_51 ) ;
goto V_55;
}
}
if ( V_11 && ( V_4 == V_57 ) ) {
if ( ! ( V_22 = F_38 ( V_51 , V_11 , V_48 , NULL ,
V_3 , L_114 ) ) ) {
F_41 ( V_51 ) ;
goto V_55;
}
}
if ( V_4 == V_57 ) {
if ( ! V_16 )
V_16 = V_11 ;
} else if ( V_4 == V_58 ) {
if ( ! V_16 )
V_16 = V_10 ;
} else
V_16 = NULL ;
if ( V_16 ) {
V_24 = F_42 ( V_51 , V_16 , V_47 , 0 , V_39 , V_3 ,
L_116 ) ;
if ( ! V_24 )
goto V_55;
}
if ( V_8 ) {
if ( ! ( V_27 = F_43 ( V_8 , V_6 ) ) ) {
F_28 ( V_51 , L_117 , V_8 ) ;
goto V_55;
}
} else
V_27 = F_44 ( V_79 , V_53 ) ;
if ( V_4 & V_78 ) {
if ( V_44 == V_45 )
V_19 = F_45 ( V_27 , & V_29 ) ;
else if ( V_44 == V_48 )
V_19 = F_46 ( V_27 , NULL , NULL , NULL ) ;
else if ( V_44 == V_77 )
V_19 = F_47 ( V_27 , NULL ) ;
else {
F_28 ( V_51 , L_118 ) ;
goto V_55;
}
if ( ! V_19 ) {
F_28 ( V_51 , L_119 ) ;
goto V_55;
}
if ( V_17 ) {
F_48 ( V_29 ) ;
if ( ! ( V_29 = F_43 ( V_17 , L_112 ) ) ) {
F_28 ( V_51 , L_120 , V_17 ) ;
goto V_55;
}
}
}
if ( V_9 ) {
if ( ! ( V_28 = F_43 ( V_9 , V_7 ) ) ) {
F_28 ( V_51 , L_121 , V_9 ) ;
goto V_55;
}
} else {
V_28 = F_44 ( stdout , V_53 ) ;
#ifdef F_49
{
T_7 * V_80 = F_4 ( F_50 () ) ;
V_28 = F_51 ( V_80 , V_28 ) ;
}
#endif
}
if ( V_4 == V_60 ) {
if ( ! ( V_20 = F_52 ( V_51 , V_36 , V_37 ) ) )
goto V_55;
F_53 ( V_20 , V_81 ) ;
if ( V_50 )
F_54 ( V_20 , V_50 ) ;
}
V_5 = 3 ;
if ( V_4 == V_56 ) {
if ( V_42 )
V_31 |= V_82 ;
V_19 = F_55 ( V_25 , V_27 , V_18 , V_31 ) ;
} else if ( V_4 & V_74 ) {
int V_83 ;
if ( V_4 == V_58 ) {
if ( V_31 & V_32 ) {
if ( V_46 == V_45 )
V_31 |= V_82 ;
} else if ( V_42 )
V_31 |= V_82 ;
V_31 |= V_84 ;
V_19 = F_56 ( NULL , NULL , V_26 , V_27 , V_31 ) ;
if ( ! V_19 )
goto V_55;
if ( V_31 & V_66 ) {
for ( V_83 = 0 ; V_83 < F_57 ( V_26 ) ; V_83 ++ ) {
T_5 * V_85 = F_58 ( V_26 , V_83 ) ;
F_59 ( V_19 , V_85 ) ;
}
}
} else
V_31 |= V_86 ;
for ( V_83 = 0 ; V_83 < F_60 ( V_13 ) ; V_83 ++ ) {
V_10 = F_61 ( V_13 , V_83 ) ;
V_16 = F_61 ( V_14 , V_83 ) ;
V_23 = F_38 ( V_51 , V_10 , V_48 , NULL ,
V_3 , L_122 ) ;
if ( ! V_23 )
goto V_55;
V_24 = F_42 ( V_51 , V_16 , V_47 , 0 , V_39 , V_3 ,
L_116 ) ;
if ( ! V_24 )
goto V_55;
if ( ! F_62 ( V_19 , V_23 , V_24 , V_43 , V_31 ) )
goto V_55;
F_63 ( V_23 ) ;
V_23 = NULL ;
F_64 ( V_24 ) ;
V_24 = NULL ;
}
if ( ( V_4 == V_58 ) && ! ( V_31 & V_82 ) ) {
if ( ! F_65 ( V_19 , V_27 , V_31 ) )
goto V_55;
}
}
if ( ! V_19 ) {
F_28 ( V_51 , L_123 ) ;
goto V_55;
}
V_5 = 4 ;
if ( V_4 == V_57 ) {
if ( ! F_66 ( V_19 , V_24 , V_22 , V_28 , V_31 ) ) {
F_28 ( V_51 , L_124 ) ;
goto V_55;
}
} else if ( V_4 == V_60 ) {
F_1 ( T_5 ) * V_87 ;
if ( F_67 ( V_19 , V_26 , V_20 , V_29 , V_28 , V_31 ) )
F_28 ( V_51 , L_125 ) ;
else {
F_28 ( V_51 , L_126 ) ;
goto V_55;
}
V_87 = F_68 ( V_19 , V_26 , V_31 ) ;
if ( ! F_69 ( V_10 , V_87 ) ) {
F_28 ( V_51 , L_127 , V_10 ) ;
V_5 = 5 ;
goto V_55;
}
F_70 ( V_87 ) ;
} else if ( V_4 == V_61 )
F_71 ( V_28 , V_19 ) ;
else {
if ( V_33 )
F_28 ( V_28 , L_128 , V_33 ) ;
if ( V_34 )
F_28 ( V_28 , L_129 , V_34 ) ;
if ( V_35 )
F_28 ( V_28 , L_130 , V_35 ) ;
if ( V_46 == V_45 ) {
if ( V_4 == V_59 )
F_72 ( V_28 , V_19 , V_29 , V_31 ) ;
else
F_72 ( V_28 , V_19 , V_27 , V_31 ) ;
} else if ( V_46 == V_48 )
F_73 ( V_28 , V_19 , V_27 , V_31 ) ;
else if ( V_46 == V_77 )
F_74 ( V_28 , V_19 , V_27 , V_31 ) ;
else {
F_28 ( V_51 , L_131 ) ;
goto V_55;
}
}
V_5 = 0 ;
V_55:
if ( V_41 )
F_75 ( NULL , V_51 ) ;
if ( V_5 )
F_41 ( V_51 ) ;
F_76 ( V_25 , F_63 ) ;
F_76 ( V_26 , F_63 ) ;
if ( V_50 )
F_77 ( V_50 ) ;
if ( V_13 )
F_78 ( V_13 ) ;
if ( V_14 )
F_78 ( V_14 ) ;
F_79 ( V_20 ) ;
F_63 ( V_21 ) ;
F_63 ( V_22 ) ;
F_63 ( V_23 ) ;
F_64 ( V_24 ) ;
F_80 ( V_19 ) ;
F_48 ( V_27 ) ;
F_48 ( V_29 ) ;
F_81 ( V_28 ) ;
if ( V_39 )
F_82 ( V_39 ) ;
return ( V_5 ) ;
}
static int V_81 ( int V_88 , T_10 * V_89 )
{
int error ;
error = F_83 ( V_89 ) ;
if ( ( error != V_90 )
&& ( ( error != V_91 ) || ( V_88 != 2 ) ) )
return V_88 ;
F_84 ( NULL , V_89 ) ;
return V_88 ;
}
