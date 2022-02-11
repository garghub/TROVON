int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
char * V_4 = NULL , * V_5 = NULL , * V_6 = NULL ;
char * V_7 = NULL ;
T_2 * V_8 = NULL , * V_9 = NULL ;
char * * args ;
char * V_10 = NULL ;
char * V_11 = NULL ;
int V_12 = 0 ;
T_3 * V_13 = NULL ;
char V_14 [ 50 ] , V_15 [ 50 ] ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 = 0 ;
int V_19 = 0 ;
int V_20 = V_21 ;
int V_22 = V_21 ;
int V_23 = 0 ;
int V_24 = 0 ;
int V_25 ;
int V_26 = V_27 ;
int V_28 = 1 ;
int V_29 = 1 ;
int V_30 = 0 ;
F_1 ( V_31 ) * V_32 = NULL ;
char * V_33 = NULL , * V_34 = NULL ;
char * V_35 = NULL , * V_36 = NULL , * V_37 = NULL ;
char * V_38 = NULL , * V_39 = NULL ;
char * V_40 = NULL ;
char * V_41 = NULL ;
char * V_42 = NULL , * V_43 = NULL ;
# ifndef F_2
char * V_44 = NULL ;
# endif
F_3 () ;
# ifdef F_4
if ( F_5 () )
V_25 = V_27 ;
else
# endif
V_25 = V_45 ;
V_46 = F_6 () ;
if ( V_47 == NULL )
V_47 = F_7 ( V_48 , V_49 ) ;
if ( ! F_8 ( V_47 , NULL ) )
goto V_50;
args = V_2 + 1 ;
while ( * args ) {
if ( * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_1 ) )
V_17 |= V_51 ;
else if ( ! strcmp ( * args , L_2 ) )
V_24 = V_52 ;
else if ( ! strcmp ( * args , L_3 ) )
V_24 = V_53 ;
else if ( ! strcmp ( * args , L_4 ) )
V_17 |= V_54 ;
else if ( ! strcmp ( * args , L_5 ) )
V_17 |= V_55 ;
else if ( ! strcmp ( * args , L_6 ) )
V_17 |= V_56 ;
else if ( ! strcmp ( * args , L_7 ) )
V_17 |= ( V_51 | V_54 ) ;
else if ( ! strcmp ( * args , L_8 ) )
V_17 |= V_57 ;
else if ( ! strcmp ( * args , L_9 ) )
V_18 = 1 ;
else if ( ! strcmp ( * args , L_10 ) )
V_23 = 1 ;
else if ( ! strcmp ( * args , L_11 ) )
V_29 = 0 ;
else if ( ! strcmp ( * args , L_12 ) )
V_25 = V_27 ;
else if ( ! strcmp ( * args , L_13 ) )
V_16 = 1 ;
else if ( ! strcmp ( * args , L_14 ) )
V_46 = F_9 () ;
else if ( ! strcmp ( * args , L_15 ) )
V_46 = F_6 () ;
# ifndef F_10
else if ( ! strcmp ( * args , L_16 ) )
V_46 = F_11 () ;
# endif
# ifndef F_12
else if ( ! strcmp ( * args , L_17 ) )
V_46 = F_13 () ;
# endif
# ifndef F_14
else if ( ! strcmp ( * args , L_18 ) )
V_46 = F_15 () ;
else if ( ! strcmp ( * args , L_19 ) )
V_46 = F_16 () ;
else if ( ! strcmp ( * args , L_20 ) )
V_46 = F_17 () ;
# endif
# ifndef F_18
else if ( ! strcmp ( * args , L_21 ) )
V_46 = F_19 () ;
else if ( ! strcmp ( * args , L_22 ) )
V_46 = F_20 () ;
else if ( ! strcmp ( * args , L_23 ) )
V_46 = F_21 () ;
# endif
else if ( ! strcmp ( * args , L_24 ) )
V_20 = 1 ;
else if ( ! strcmp ( * args , L_25 ) )
V_22 = V_21 ;
else if ( ! strcmp ( * args , L_26 ) )
V_22 = 1 ;
else if ( ! strcmp ( * args , L_27 ) )
V_22 = - 1 ;
else if ( ! strcmp ( * args , L_28 ) )
if ( args [ 1 ] ) {
args ++ ;
V_41 = * args ;
} else
V_19 = 1 ;
else if ( ! strcmp ( * args , L_29 ) )
V_46 = NULL ;
else if ( ! strcmp ( * args , L_30 ) ) {
if ( ! F_22 ( V_47 , & V_25 , * ++ args ) )
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_31 ) ) {
if ( ! F_22 ( V_47 , & V_26 , * ++ args ) )
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_32 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_40 = * args ;
} else
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_33 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_6 = * args ;
} else
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_34 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_7 = * args ;
} else
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_35 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_10 = * args ;
} else
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_36 ) )
V_12 = 1 ;
else if ( ! strcmp ( * args , L_37 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_11 = * args ;
} else
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_38 ) ) {
if ( args [ 1 ] ) {
args ++ ;
if ( ! V_32 )
V_32 = F_23 () ;
F_24 ( V_32 , * args ) ;
} else
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_39 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_4 = * args ;
} else
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_40 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_5 = * args ;
} else
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_41 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_35 = * args ;
} else
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_42 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_36 = * args ;
} else
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_43 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_37 = * args ;
V_30 = 1 ;
} else
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_44 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_42 = * args ;
} else
V_19 = 1 ;
} else if ( ! strcmp ( * args , L_45 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_43 = * args ;
} else
V_19 = 1 ;
# ifndef F_2
} else if ( ! strcmp ( * args , L_46 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_44 = * args ;
} else
V_19 = 1 ;
# endif
} else
V_19 = 1 ;
} else
V_19 = 1 ;
args ++ ;
}
if ( V_19 ) {
F_25 ( V_47 , L_47 ) ;
F_25 ( V_47 , L_48 ) ;
F_25 ( V_47 , L_49 ) ;
F_25 ( V_47 , L_50 ) ;
F_25 ( V_47 , L_51 ) ;
F_25 ( V_47 , L_52 ) ;
F_25 ( V_47 , L_53 ) ;
F_25 ( V_47 , L_54 ) ;
F_25 ( V_47 , L_55 ) ;
F_25 ( V_47 ,
L_56 ) ;
F_25 ( V_47 , L_57 ) ;
F_25 ( V_47 , L_58 ) ;
F_25 ( V_47 ,
L_59 ) ;
F_25 ( V_47 , L_60 ) ;
F_25 ( V_47 , L_61 ) ;
F_25 ( V_47 ,
L_62 ) ;
F_25 ( V_47 , L_63 ) ;
F_25 ( V_47 , L_64 ) ;
F_25 ( V_47 ,
L_65 ) ;
F_25 ( V_47 , L_66 ) ;
F_25 ( V_47 ,
L_67 ) ;
# ifndef F_10
F_25 ( V_47 , L_68 ) ;
# endif
# ifndef F_12
F_25 ( V_47 , L_69 ) ;
# endif
# ifndef F_14
F_25 ( V_47 , L_70 ) ;
F_25 ( V_47 ,
L_71 ) ;
# endif
# ifndef F_18
F_25 ( V_47 , L_72 ) ;
F_25 ( V_47 ,
L_73 ) ;
# endif
F_25 ( V_47 , L_74 ) ;
F_25 ( V_47 , L_75 ) ;
F_25 ( V_47 , L_76 ) ;
F_25 ( V_47 , L_77 ) ;
F_25 ( V_47 , L_78 ) ;
F_25 ( V_47 ,
L_79 ) ;
F_25 ( V_47 ,
L_80 ) ;
F_25 ( V_47 ,
L_81 ) ;
F_25 ( V_47 ,
L_82 ) ;
F_25 ( V_47 ,
L_83 ) ;
F_25 ( V_47 , L_84 ) ;
F_25 ( V_47 , L_85 ) ;
F_25 ( V_47 ,
L_86 ) ;
F_25 ( V_47 , L_87 ) ;
F_25 ( V_47 , L_88 ) ;
# ifndef F_2
F_25 ( V_47 ,
L_89 ) ;
# endif
F_25 ( V_47 , L_90 , V_58 ,
V_58 ) ;
F_25 ( V_47 ,
L_91 ) ;
F_25 ( V_47 , L_92 ) ;
F_25 ( V_47 , L_93 ) ;
F_25 ( V_47 ,
L_94 ) ;
goto V_50;
}
# ifndef F_2
V_3 = F_26 ( V_47 , V_44 , 0 ) ;
# endif
if ( V_37 ) {
if ( V_16 )
V_36 = V_37 ;
else
V_35 = V_37 ;
}
if ( ! F_27 ( V_47 , V_35 , V_36 , & V_38 , & V_39 ) ) {
F_25 ( V_47 , L_95 ) ;
goto V_50;
}
if ( ! V_33 ) {
if ( V_16 )
V_33 = V_39 ;
else
V_33 = V_38 ;
}
if ( V_33 ) {
V_34 = V_33 ;
V_30 = 1 ;
} else {
V_33 = V_14 ;
V_34 = V_15 ;
}
if ( V_16 || V_40 ) {
F_28 ( NULL , V_47 , ( V_40 != NULL ) ) ;
if ( V_40 != NULL )
F_25 ( V_47 , L_96 ,
F_29 ( V_40 ) ) ;
}
F_30 () ;
# ifdef F_31
F_32 ( L_97 ) ;
# endif
if ( ! V_4 )
V_8 = F_7 ( V_59 , V_49 ) ;
else
V_8 = F_33 ( V_4 , L_98 ) ;
if ( ! V_8 ) {
F_25 ( V_47 , L_99 ,
V_4 ? V_4 : L_100 ) ;
perror ( V_4 ) ;
goto V_50;
}
# ifdef F_31
F_34 () ;
F_32 ( L_101 ) ;
# endif
if ( ! V_5 ) {
V_9 = F_7 ( stdout , V_49 ) ;
# ifdef F_35
{
T_2 * V_60 = F_36 ( F_37 () ) ;
V_9 = F_38 ( V_60 , V_9 ) ;
}
# endif
} else
V_9 = F_33 ( V_5 , L_102 ) ;
if ( ! V_9 ) {
F_25 ( V_47 , L_103 ,
V_5 ? V_5 : L_104 ) ;
perror ( V_5 ) ;
goto V_50;
}
if ( V_23 ) {
# ifdef F_31
F_32 ( L_105 ) ;
# endif
if ( F_39
( V_15 , sizeof V_15 , L_106 , V_16 ) ) {
F_25 ( V_47 , L_107 ) ;
goto V_50;
}
# ifdef F_31
F_34 () ;
# endif
}
if ( V_16 ) {
T_4 * V_61 = NULL ;
T_5 * V_62 = NULL , * V_63 = NULL ;
F_1 ( T_5 ) * V_64 = NULL ;
const T_6 * V_65 = NULL ;
unsigned char * V_66 = NULL ;
int V_67 ;
if ( ( V_17 & ( V_54 | V_51 ) ) == ( V_54 | V_51 ) ) {
F_25 ( V_47 , L_108 ) ;
goto V_68;
}
if ( V_17 & V_54 )
V_18 = 0 ;
# ifdef F_31
F_32 ( L_109 ) ;
F_32 ( L_110 ) ;
# endif
if ( ! ( V_17 & V_51 ) ) {
V_61 = F_40 ( V_47 , V_6 ? V_6 : V_4 ,
V_69 , 1 , V_38 , V_3 , L_111 ) ;
if ( ! V_61 )
goto V_68;
}
# ifdef F_31
F_34 () ;
F_32 ( L_112 ) ;
# endif
if ( ! ( V_17 & V_54 ) ) {
V_64 = F_41 ( V_47 , V_4 , V_69 , NULL , V_3 ,
L_113 ) ;
if ( ! V_64 )
goto V_68;
if ( V_61 ) {
for ( V_67 = 0 ; V_67 < F_42 ( V_64 ) ; V_67 ++ ) {
V_63 = F_43 ( V_64 , V_67 ) ;
if ( F_44 ( V_63 , V_61 ) ) {
V_62 = V_63 ;
F_45 ( V_62 , NULL , 0 ) ;
F_46 ( V_62 , NULL , 0 ) ;
( void ) F_47 ( V_64 , V_67 ) ;
break;
}
}
if ( ! V_62 ) {
F_25 ( V_47 ,
L_114 ) ;
goto V_68;
}
}
}
# ifdef F_31
F_34 () ;
F_32 ( L_115 ) ;
# endif
if ( V_7 ) {
F_1 ( T_5 ) * V_70 = NULL ;
if ( ! ( V_70 = F_41 ( V_47 , V_7 , V_69 ,
NULL , V_3 ,
L_116 ) ) )
goto V_68;
while ( F_42 ( V_70 ) > 0 )
F_48 ( V_64 , F_49 ( V_70 ) ) ;
F_50 ( V_70 ) ;
}
# ifdef F_31
F_34 () ;
F_32 ( L_117 ) ;
# endif
# ifdef F_31
F_34 () ;
F_32 ( L_118 ) ;
# endif
if ( V_18 ) {
int V_71 ;
F_1 ( T_5 ) * V_72 ;
T_7 * V_73 = F_51 () ;
if ( ! V_73 ) {
F_25 ( V_47 , L_119 ) ;
goto V_68;
}
if ( ! F_52 ( V_73 , V_43 , V_42 ) )
F_53 ( V_73 ) ;
V_71 = F_54 ( V_62 , V_73 , & V_72 ) ;
F_55 ( V_73 ) ;
if ( ! V_71 ) {
for ( V_67 = 1 ; V_67 < F_42 ( V_72 ) ; V_67 ++ )
F_48 ( V_64 , F_43 ( V_72 , V_67 ) ) ;
F_56 ( F_43 ( V_72 , 0 ) ) ;
F_50 ( V_72 ) ;
} else {
if ( V_71 >= 0 )
F_25 ( V_47 , L_120 ,
F_57 ( V_71 ) ) ;
else
F_58 ( V_47 ) ;
goto V_68;
}
}
for ( V_67 = 0 ; V_67 < F_59 ( V_32 ) ; V_67 ++ ) {
V_66 = ( unsigned char * ) F_60 ( V_32 , V_67 ) ;
F_46 ( F_43 ( V_64 , V_67 ) , V_66 , - 1 ) ;
}
if ( V_11 && V_61 )
F_61 ( V_61 , V_74 ,
V_75 , ( unsigned char * ) V_11 ,
- 1 ) ;
if ( V_12 && V_61 )
F_61 ( V_61 , V_76 , 0 , NULL , - 1 ) ;
# ifdef F_31
F_34 () ;
F_32 ( L_121 ) ;
# endif
if ( ! V_30 &&
F_39 ( V_14 , sizeof V_14 , L_122 ,
1 ) ) {
F_25 ( V_47 , L_107 ) ;
goto V_68;
}
if ( ! V_23 )
F_62 ( V_15 , V_14 , sizeof V_15 ) ;
# ifdef F_31
F_34 () ;
F_32 ( L_123 ) ;
# endif
V_13 = F_63 ( V_33 , V_10 , V_61 , V_62 , V_64 ,
V_26 , V_25 , V_20 , - 1 , V_24 ) ;
if ( ! V_13 ) {
F_58 ( V_47 ) ;
goto V_68;
}
if ( V_41 ) {
V_65 = F_64 ( V_41 ) ;
if ( ! V_65 ) {
F_25 ( V_47 , L_124 , V_41 ) ;
}
}
if ( V_22 != - 1 )
F_65 ( V_13 , V_34 , - 1 , NULL , 0 , V_22 , V_65 ) ;
# ifdef F_31
F_34 () ;
F_32 ( L_125 ) ;
# endif
F_66 ( V_9 , V_13 ) ;
V_28 = 0 ;
V_68:
# ifdef F_31
F_34 () ;
F_34 () ;
F_32 ( L_126 ) ;
# endif
if ( V_61 )
F_67 ( V_61 ) ;
if ( V_64 )
F_68 ( V_64 , F_56 ) ;
if ( V_62 )
F_56 ( V_62 ) ;
# ifdef F_31
F_34 () ;
# endif
goto V_50;
}
if ( ! ( V_13 = F_69 ( V_8 , NULL ) ) ) {
F_58 ( V_47 ) ;
goto V_50;
}
# ifdef F_31
F_32 ( L_127 ) ;
# endif
if ( ! V_30
&& F_39 ( V_14 , sizeof V_14 , L_128 ,
0 ) ) {
F_25 ( V_47 , L_107 ) ;
goto V_50;
}
# ifdef F_31
F_34 () ;
# endif
if ( ! V_23 )
F_62 ( V_15 , V_14 , sizeof V_15 ) ;
if ( ( V_17 & V_57 ) && V_13 -> V_77 )
F_25 ( V_47 , L_129 ,
V_13 -> V_77 -> V_20 ? F_70 ( V_13 -> V_77 -> V_20 ) : 1 ) ;
if ( V_29 ) {
# ifdef F_31
F_32 ( L_130 ) ;
# endif
if ( ! V_34 [ 0 ] && F_71 ( V_13 , NULL , 0 ) ) {
if ( ! V_23 )
V_33 = NULL ;
} else if ( ! F_71 ( V_13 , V_34 , - 1 ) ) {
F_25 ( V_47 , L_131 ) ;
F_58 ( V_47 ) ;
goto V_50;
}
F_25 ( V_47 , L_132 ) ;
# ifdef F_31
F_34 () ;
# endif
}
# ifdef F_31
F_32 ( L_133 ) ;
# endif
if ( ! F_72 ( V_9 , V_13 , V_33 , - 1 , V_17 , V_39 ) ) {
F_25 ( V_47 , L_134 ) ;
F_58 ( V_47 ) ;
goto V_50;
}
# ifdef F_31
F_34 () ;
# endif
V_28 = 0 ;
V_50:
if ( V_13 )
F_73 ( V_13 ) ;
if ( V_16 || V_40 )
F_74 ( NULL , V_47 ) ;
# ifdef F_31
F_75 () ;
# endif
F_76 ( V_8 ) ;
F_77 ( V_9 ) ;
if ( V_32 )
F_78 ( V_32 ) ;
if ( V_38 )
F_79 ( V_38 ) ;
if ( V_39 )
F_79 ( V_39 ) ;
F_80 () ;
F_81 ( V_28 ) ;
}
int F_72 ( T_2 * V_9 , T_3 * V_13 , char * V_14 ,
int V_78 , int V_17 , char * V_79 )
{
F_1 ( V_80 ) * V_81 = NULL ;
F_1 ( V_82 ) * V_83 ;
int V_67 , V_84 ;
int V_28 = 0 ;
V_80 * V_85 ;
if ( ! ( V_81 = F_82 ( V_13 ) ) )
return 0 ;
for ( V_67 = 0 ; V_67 < F_83 ( V_81 ) ; V_67 ++ ) {
V_85 = F_84 ( V_81 , V_67 ) ;
V_84 = F_85 ( V_85 -> type ) ;
if ( V_84 == V_86 ) {
V_83 = F_86 ( V_85 ) ;
if ( V_17 & V_57 )
F_25 ( V_47 , L_135 ) ;
} else if ( V_84 == V_87 ) {
if ( V_17 & V_57 ) {
F_25 ( V_47 , L_136 ) ;
F_87 ( V_47 , V_85 -> V_88 . V_89 -> V_90 -> V_91 ) ;
}
V_83 = F_88 ( V_85 , V_14 , V_78 ) ;
} else
continue;
if ( ! V_83 )
goto V_92;
if ( ! F_89 ( V_9 , V_83 , V_14 , V_78 ,
V_17 , V_79 ) ) {
F_90 ( V_83 , V_93 ) ;
goto V_92;
}
F_90 ( V_83 , V_93 ) ;
V_83 = NULL ;
}
V_28 = 1 ;
V_92:
if ( V_81 )
F_91 ( V_81 , V_94 ) ;
return V_28 ;
}
int F_92 ( T_2 * V_9 , V_82 * V_95 , char * V_14 ,
int V_78 , int V_17 , char * V_79 )
{
T_4 * V_96 ;
T_8 * V_97 ;
T_5 * V_98 ;
switch ( F_93 ( V_95 ) ) {
case V_99 :
if ( V_17 & V_57 )
F_25 ( V_47 , L_137 ) ;
if ( V_17 & V_51 )
return 1 ;
F_94 ( V_9 , V_95 -> V_100 , L_138 ) ;
V_97 = V_95 -> V_101 . V_102 ;
if ( ! ( V_96 = F_95 ( V_97 ) ) )
return 0 ;
F_94 ( V_9 , V_97 -> V_103 , L_139 ) ;
F_96 ( V_9 , V_96 , V_46 , NULL , 0 , NULL , V_79 ) ;
F_67 ( V_96 ) ;
break;
case V_104 :
if ( V_17 & V_57 ) {
F_25 ( V_47 , L_140 ) ;
F_87 ( V_47 , V_95 -> V_101 . V_105 -> V_106 ) ;
}
if ( V_17 & V_51 )
return 1 ;
F_94 ( V_9 , V_95 -> V_100 , L_138 ) ;
if ( ! ( V_97 = F_97 ( V_95 , V_14 , V_78 ) ) )
return 0 ;
if ( ! ( V_96 = F_95 ( V_97 ) ) ) {
F_98 ( V_97 ) ;
return 0 ;
}
F_94 ( V_9 , V_97 -> V_103 , L_139 ) ;
F_98 ( V_97 ) ;
F_96 ( V_9 , V_96 , V_46 , NULL , 0 , NULL , V_79 ) ;
F_67 ( V_96 ) ;
break;
case V_107 :
if ( V_17 & V_57 )
F_25 ( V_47 , L_141 ) ;
if ( V_17 & V_54 )
return 1 ;
if ( F_99 ( V_95 , V_108 ) ) {
if ( V_17 & V_56 )
return 1 ;
} else if ( V_17 & V_55 )
return 1 ;
F_94 ( V_9 , V_95 -> V_100 , L_138 ) ;
if ( F_100 ( V_95 ) != V_109 )
return 1 ;
if ( ! ( V_98 = F_101 ( V_95 ) ) )
return 0 ;
F_102 ( V_9 , V_98 ) ;
F_103 ( V_9 , V_98 ) ;
F_56 ( V_98 ) ;
break;
case V_110 :
if ( V_17 & V_57 )
F_25 ( V_47 , L_142 ) ;
F_94 ( V_9 , V_95 -> V_100 , L_138 ) ;
return F_89 ( V_9 , V_95 -> V_101 . V_111 , V_14 ,
V_78 , V_17 , V_79 ) ;
default:
F_25 ( V_47 , L_143 ) ;
F_104 ( V_47 , V_95 -> type ) ;
F_25 ( V_47 , L_144 ) ;
return 1 ;
break;
}
return 1 ;
}
int F_87 ( T_2 * V_63 , T_9 * V_112 )
{
T_10 * V_113 ;
const unsigned char * V_114 ;
V_114 = V_112 -> V_115 -> V_101 . V_116 -> V_117 ;
V_113 = F_105 ( NULL , & V_114 , V_112 -> V_115 -> V_101 . V_116 -> V_118 ) ;
if ( ! V_113 )
return 1 ;
F_25 ( V_47 , L_145 ,
F_106 ( F_85 ( V_112 -> V_91 ) ) ,
F_70 ( V_113 -> V_20 ) ) ;
F_107 ( V_113 ) ;
return 1 ;
}
void F_108 ( T_2 * V_9 , unsigned char * V_119 , int V_120 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_120 ; V_67 ++ )
F_25 ( V_9 , L_146 , V_119 [ V_67 ] ) ;
}
static int F_22 ( T_2 * V_92 , int * V_121 , const char * V_122 )
{
if ( ! V_122 )
return 0 ;
if ( ! strcmp ( V_122 , L_147 ) ) {
* V_121 = - 1 ;
return 1 ;
}
* V_121 = F_109 ( V_122 ) ;
if ( * V_121 == V_123 ) {
F_25 ( V_47 , L_148 , V_122 ) ;
return 0 ;
}
return 1 ;
}
