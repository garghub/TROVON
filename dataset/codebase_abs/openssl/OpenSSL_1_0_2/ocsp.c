int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
char * * args ;
char * V_4 = NULL , * V_5 = NULL , * V_6 = L_1 ;
char * V_7 = NULL , * V_8 = NULL , * V_9 = NULL ;
char * V_10 = NULL , * V_11 = NULL ;
char * V_12 = NULL , * V_13 = NULL ;
char * V_14 = NULL , * V_15 = NULL ;
char * V_16 = NULL , * V_17 = NULL ;
char * V_18 = NULL ;
int V_19 = 1 , V_20 = 0 , V_21 = - 1 ;
F_1 ( V_22 ) * V_23 = NULL ;
T_2 * V_24 = NULL ;
T_3 * V_25 = NULL ;
T_4 * V_26 = NULL ;
T_5 * V_27 = NULL , * V_28 = NULL ;
T_5 * V_29 = NULL , * V_30 = NULL ;
T_6 * V_31 = NULL , * V_32 = NULL ;
T_7 * V_33 = NULL , * V_34 = NULL ;
T_7 * V_35 = NULL ;
T_7 * V_36 = NULL ;
int V_37 = - 1 ;
int V_38 = 0 , V_39 = 0 ;
long V_40 = V_41 , V_42 = - 1 ;
char * V_43 = NULL , * V_44 = NULL ;
T_8 * V_45 = NULL ;
T_9 * V_46 = NULL ;
F_1 ( T_5 ) * V_47 = NULL , * V_48 = NULL , * V_49 = NULL ;
char * V_50 = NULL , * V_51 = NULL , * V_52 = NULL ;
unsigned long V_53 = 0 , V_54 = 0 , V_55 = 0 ;
int V_56 = 1 ;
int V_57 = - 1 ;
int V_58 = 0 ;
int V_59 = 0 ;
int V_60 ;
int V_61 = 0 ;
F_1 ( V_62 ) * V_63 = NULL ;
F_1 ( V_64 ) * V_65 = NULL ;
T_5 * V_66 = NULL ;
char * V_67 = NULL ;
char * V_68 = NULL ;
T_10 * V_69 = NULL ;
int V_70 = 0 , V_71 = - 1 ;
const T_11 * V_72 = NULL , * V_73 = NULL ;
if ( V_74 == NULL )
V_74 = F_2 ( V_75 , V_76 ) ;
if ( ! F_3 ( V_74 , NULL ) )
goto V_77;
F_4 () ;
F_5 () ;
args = V_2 + 1 ;
V_63 = F_6 () ;
V_65 = F_7 () ;
while ( ! V_58 && * args && * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_2 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_18 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_3 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_37 = atol ( * args ) ;
if ( V_37 < 0 ) {
F_8 ( V_74 , L_4 , * args ) ;
V_58 = 1 ;
}
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_5 ) ) {
if ( V_7 )
F_9 ( V_7 ) ;
if ( V_8 )
F_9 ( V_8 ) ;
if ( V_9 )
F_9 ( V_9 ) ;
if ( args [ 1 ] ) {
args ++ ;
if ( ! F_10 ( * args , & V_4 , & V_5 , & V_6 , & V_21 ) ) {
F_8 ( V_74 , L_6 ) ;
V_58 = 1 ;
}
V_7 = V_4 ;
V_8 = V_5 ;
V_9 = V_6 ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_7 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_4 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_8 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_5 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_9 ) ) {
if ( args [ 1 ] && args [ 2 ] ) {
if ( ! F_11 ( args [ 1 ] , args [ 2 ] , & V_23 ) )
goto V_77;
args += 2 ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_10 ) )
V_61 = 1 ;
else if ( ! strcmp ( * args , L_11 ) )
V_20 = 1 ;
else if ( ! strcmp ( * args , L_12 ) )
V_19 = 2 ;
else if ( ! strcmp ( * args , L_13 ) )
V_19 = 0 ;
else if ( ! strcmp ( * args , L_14 ) )
V_55 |= V_78 ;
else if ( ! strcmp ( * args , L_15 ) )
V_55 |= V_79 ;
else if ( ! strcmp ( * args , L_16 ) )
V_53 |= V_78 ;
else if ( ! strcmp ( * args , L_17 ) )
V_54 |= V_80 ;
else if ( ! strcmp ( * args , L_18 ) )
V_54 |= V_81 ;
else if ( ! strcmp ( * args , L_19 ) )
V_54 |= V_82 ;
else if ( ! strcmp ( * args , L_20 ) )
V_54 |= V_83 ;
else if ( ! strcmp ( * args , L_21 ) )
V_54 |= V_84 ;
else if ( ! strcmp ( * args , L_22 ) )
V_54 |= V_85 ;
else if ( ! strcmp ( * args , L_23 ) )
V_54 |= V_86 ;
else if ( ! strcmp ( * args , L_24 ) )
V_59 = 1 ;
else if ( ! strcmp ( * args , L_25 ) ) {
V_38 = 1 ;
V_39 = 1 ;
} else if ( ! strcmp ( * args , L_26 ) )
V_38 = 1 ;
else if ( ! strcmp ( * args , L_27 ) )
V_39 = 1 ;
else if ( ! strcmp ( * args , L_28 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_10 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_29 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_11 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_30 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_14 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_31 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_51 = * args ;
V_54 |= V_85 ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_32 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_50 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_33 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_51 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_34 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_43 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_35 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_44 = * args ;
} else
V_58 = 1 ;
} else if ( F_12 ( & args , NULL , & V_58 , V_74 , & V_46 ) ) {
if ( V_58 )
goto V_77;
continue;
} else if ( ! strcmp ( * args , L_36 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_40 = atol ( * args ) ;
if ( V_40 < 0 ) {
F_8 ( V_74 ,
L_37 , * args ) ;
V_58 = 1 ;
}
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_38 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_42 = atol ( * args ) ;
if ( V_42 < 0 ) {
F_8 ( V_74 , L_39 , * args ) ;
V_58 = 1 ;
}
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_40 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_15 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_41 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_12 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_42 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_13 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_43 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_6 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_44 ) ) {
if ( args [ 1 ] ) {
args ++ ;
F_13 ( V_27 ) ;
V_27 = F_14 ( V_74 , * args , V_87 ,
NULL , V_3 , L_45 ) ;
if ( ! V_27 )
goto V_77;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_46 ) ) {
if ( args [ 1 ] ) {
args ++ ;
F_13 ( V_28 ) ;
V_28 = F_14 ( V_74 , * args , V_87 ,
NULL , V_3 , L_47 ) ;
if ( ! V_28 )
goto V_77;
if ( ! V_72 )
V_72 = F_15 () ;
if ( ! F_16 ( & V_24 , V_28 , V_72 , V_27 , V_65 ) )
goto V_77;
if ( ! F_17 ( V_63 , * args ) )
goto V_77;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_48 ) ) {
if ( args [ 1 ] ) {
args ++ ;
if ( ! V_72 )
V_72 = F_15 () ;
if ( ! F_18 ( & V_24 , * args , V_72 , V_27 , V_65 ) )
goto V_77;
if ( ! F_17 ( V_63 , * args ) )
goto V_77;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_49 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_67 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_50 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_68 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_51 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_70 = atol ( * args ) ;
if ( V_70 < 0 ) {
F_8 ( V_74 , L_52 , * args ) ;
V_58 = 1 ;
}
}
if ( V_71 == - 1 )
V_71 = 0 ;
else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_53 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_57 = atol ( * args ) ;
if ( V_57 < 0 ) {
F_8 ( V_74 , L_54 , * args ) ;
V_58 = 1 ;
}
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_55 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_71 = atol ( * args ) ;
if ( V_71 < 0 ) {
F_8 ( V_74 , L_52 , * args ) ;
V_58 = 1 ;
}
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_56 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_16 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_57 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_17 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_58 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_52 = * args ;
} else
V_58 = 1 ;
} else if ( ! strcmp ( * args , L_59 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_73 = F_19 ( * args ) ;
if ( ! V_73 )
V_58 = 1 ;
} else
V_58 = 1 ;
} else if ( ( V_72 = F_19 ( ( * args ) + 1 ) ) == NULL ) {
V_58 = 1 ;
}
args ++ ;
}
if ( ! V_24 && ! V_10 && ! V_11 && ! ( V_5 && V_67 ) )
V_58 = 1 ;
if ( V_58 ) {
F_8 ( V_74 , L_60 ) ;
F_8 ( V_74 , L_61 ) ;
F_8 ( V_74 , L_62 ) ;
F_8 ( V_74 , L_63 ) ;
F_8 ( V_74 , L_64 ) ;
F_8 ( V_74 , L_65 ) ;
F_8 ( V_74 , L_66 ) ;
F_8 ( V_74 ,
L_67 ) ;
F_8 ( V_74 ,
L_68 ) ;
F_8 ( V_74 ,
L_69 ) ;
F_8 ( V_74 ,
L_70 ) ;
F_8 ( V_74 ,
L_71 ) ;
F_8 ( V_74 ,
L_72 ) ;
F_8 ( V_74 ,
L_73 ) ;
F_8 ( V_74 ,
L_74 ) ;
F_8 ( V_74 ,
L_75 ) ;
F_8 ( V_74 ,
L_76 ) ;
F_8 ( V_74 ,
L_77 ) ;
F_8 ( V_74 ,
L_78 ) ;
F_8 ( V_74 ,
L_79 ) ;
F_8 ( V_74 , L_80 ) ;
F_8 ( V_74 ,
L_81 ) ;
F_8 ( V_74 ,
L_82 ) ;
F_8 ( V_74 ,
L_83 ) ;
F_8 ( V_74 ,
L_84 ) ;
F_8 ( V_74 ,
L_85 ) ;
F_8 ( V_74 ,
L_86 ) ;
F_8 ( V_74 ,
L_87 ) ;
F_8 ( V_74 ,
L_88 ) ;
F_8 ( V_74 ,
L_89 ) ;
F_8 ( V_74 ,
L_90 ) ;
F_8 ( V_74 ,
L_91 ) ;
F_8 ( V_74 ,
L_92 ) ;
F_8 ( V_74 ,
L_93 ) ;
F_8 ( V_74 ,
L_94 ) ;
F_8 ( V_74 ,
L_95 ) ;
F_8 ( V_74 ,
L_96 ) ;
F_8 ( V_74 ,
L_97 ) ;
F_8 ( V_74 , L_98 ) ;
F_8 ( V_74 ,
L_99 ) ;
F_8 ( V_74 ,
L_100 ) ;
F_8 ( V_74 ,
L_101 ) ;
F_8 ( V_74 ,
L_102 ) ;
F_8 ( V_74 ,
L_103 ) ;
F_8 ( V_74 ,
L_104 ) ;
F_8 ( V_74 ,
L_105 ) ;
F_8 ( V_74 ,
L_106 ) ;
F_8 ( V_74 ,
L_107 ) ;
F_8 ( V_74 ,
L_108 ) ;
goto V_77;
}
if ( V_18 )
V_36 = F_20 ( V_18 , L_109 ) ;
else
V_36 = F_2 ( stdout , V_76 ) ;
if ( ! V_36 ) {
F_8 ( V_74 , L_110 ) ;
goto V_77;
}
if ( ! V_24 && ( V_19 != 2 ) )
V_19 = 0 ;
if ( ! V_24 && V_10 ) {
if ( ! strcmp ( V_10 , L_111 ) )
V_35 = F_2 ( V_88 , V_76 ) ;
else
V_35 = F_20 ( V_10 , L_112 ) ;
if ( ! V_35 ) {
F_8 ( V_74 , L_113 ) ;
goto V_77;
}
V_24 = F_21 ( V_35 , NULL ) ;
F_22 ( V_35 ) ;
if ( ! V_24 ) {
F_8 ( V_74 , L_114 ) ;
goto V_77;
}
}
if ( ! V_24 && V_5 ) {
V_33 = F_23 ( V_5 ) ;
if ( ! V_33 )
goto V_77;
}
if ( V_16 && ! V_69 ) {
if ( ! V_17 )
V_17 = V_16 ;
V_30 = F_14 ( V_74 , V_16 , V_87 ,
NULL , V_3 , L_115 ) ;
if ( ! V_30 ) {
F_8 ( V_74 , L_116 ) ;
goto V_77;
}
V_66 = F_14 ( V_74 , V_68 , V_87 ,
NULL , V_3 , L_117 ) ;
if ( V_52 ) {
V_49 = F_24 ( V_74 , V_52 , V_87 ,
NULL , V_3 , L_118 ) ;
if ( ! V_49 )
goto V_77;
}
V_32 = F_25 ( V_74 , V_17 , V_87 , 0 , NULL , NULL ,
L_119 ) ;
if ( ! V_32 )
goto V_77;
}
if ( V_33 )
F_8 ( V_74 , L_120 ) ;
V_89:
if ( V_33 ) {
if ( ! F_26 ( & V_24 , & V_34 , V_33 , V_5 ) )
goto V_77;
if ( ! V_24 ) {
V_25 =
F_27 ( V_90 ,
NULL ) ;
F_28 ( V_34 , V_25 ) ;
goto V_91;
}
}
if ( ! V_24 && ( V_14 || V_12 || V_4 || V_19 || V_67 ) ) {
F_8 ( V_74 , L_121 ) ;
goto V_77;
}
if ( V_24 && V_19 )
F_29 ( V_24 , NULL , - 1 ) ;
if ( V_14 ) {
if ( ! V_15 )
V_15 = V_14 ;
V_29 = F_14 ( V_74 , V_14 , V_87 ,
NULL , V_3 , L_122 ) ;
if ( ! V_29 ) {
F_8 ( V_74 , L_123 ) ;
goto V_77;
}
if ( V_50 ) {
V_47 = F_24 ( V_74 , V_50 , V_87 ,
NULL , V_3 , L_124 ) ;
if ( ! V_47 )
goto V_77;
}
V_31 = F_25 ( V_74 , V_15 , V_87 , 0 , NULL , NULL ,
L_125 ) ;
if ( ! V_31 )
goto V_77;
if ( ! F_30
( V_24 , V_29 , V_31 , NULL , V_47 , V_53 ) ) {
F_8 ( V_74 , L_126 ) ;
goto V_77;
}
}
if ( V_38 && V_24 )
F_31 ( V_36 , V_24 , 0 ) ;
if ( V_12 ) {
if ( ! strcmp ( V_12 , L_111 ) )
V_35 = F_2 ( stdout , V_76 ) ;
else
V_35 = F_20 ( V_12 , L_127 ) ;
if ( ! V_35 ) {
F_8 ( V_74 , L_128 , V_12 ) ;
goto V_77;
}
F_32 ( V_35 , V_24 ) ;
F_22 ( V_35 ) ;
}
if ( V_67 && ( ! V_32 || ! V_30 || ! V_66 ) ) {
F_8 ( V_74 ,
L_129 ) ;
goto V_77;
}
if ( V_67 && ! V_69 ) {
V_69 = F_33 ( V_67 , NULL ) ;
if ( ! V_69 )
goto V_77;
if ( ! F_34 ( V_69 ) )
goto V_77;
}
if ( V_69 ) {
V_60 = F_35 ( & V_25 , V_24 , V_69 , V_66 , V_30 , V_32 ,
V_73 , V_49 , V_55 , V_70 , V_71 , V_59 ) ;
if ( V_34 )
F_28 ( V_34 , V_25 ) ;
} else if ( V_4 ) {
# ifndef F_36
V_25 = F_37 ( V_74 , V_24 , V_4 , V_6 ,
V_5 , V_21 , V_23 , V_37 ) ;
if ( ! V_25 )
goto V_77;
# else
F_8 ( V_74 ,
L_130 ) ;
goto V_77;
# endif
} else if ( V_11 ) {
if ( ! strcmp ( V_11 , L_111 ) )
V_35 = F_2 ( V_88 , V_76 ) ;
else
V_35 = F_20 ( V_11 , L_112 ) ;
if ( ! V_35 ) {
F_8 ( V_74 , L_131 ) ;
goto V_77;
}
V_25 = F_38 ( V_35 , NULL ) ;
F_22 ( V_35 ) ;
if ( ! V_25 ) {
F_8 ( V_74 , L_132 ) ;
goto V_77;
}
} else {
V_56 = 0 ;
goto V_77;
}
V_91:
if ( V_13 ) {
if ( ! strcmp ( V_13 , L_111 ) )
V_35 = F_2 ( stdout , V_76 ) ;
else
V_35 = F_20 ( V_13 , L_127 ) ;
if ( ! V_35 ) {
F_8 ( V_74 , L_128 , V_13 ) ;
goto V_77;
}
F_39 ( V_35 , V_25 ) ;
F_22 ( V_35 ) ;
}
V_60 = F_40 ( V_25 ) ;
if ( V_60 != V_92 ) {
F_8 ( V_36 , L_133 ,
F_41 ( V_60 ) , V_60 ) ;
if ( V_61 )
goto V_89;
V_56 = 0 ;
goto V_77;
}
if ( V_39 )
F_42 ( V_36 , V_25 , 0 ) ;
if ( V_34 ) {
if ( V_57 > 0 )
V_57 -- ;
if ( V_57 ) {
F_43 ( V_34 ) ;
V_34 = NULL ;
F_44 ( V_24 ) ;
V_24 = NULL ;
F_45 ( V_25 ) ;
V_25 = NULL ;
goto V_89;
}
V_56 = 0 ;
goto V_77;
} else if ( V_67 ) {
V_56 = 0 ;
goto V_77;
}
if ( ! V_45 )
V_45 = F_46 ( V_74 , V_43 , V_44 ) ;
if ( ! V_45 )
goto V_77;
if ( V_46 )
F_47 ( V_45 , V_46 ) ;
if ( V_51 ) {
V_48 = F_24 ( V_74 , V_51 , V_87 ,
NULL , V_3 , L_134 ) ;
if ( ! V_48 )
goto V_77;
}
V_26 = F_48 ( V_25 ) ;
if ( ! V_26 ) {
F_8 ( V_74 , L_135 ) ;
goto V_77;
}
V_56 = 0 ;
if ( ! V_20 ) {
if ( V_24 && ( ( V_60 = F_49 ( V_24 , V_26 ) ) <= 0 ) ) {
if ( V_60 == - 1 )
F_8 ( V_74 , L_136 ) ;
else {
F_8 ( V_74 , L_137 ) ;
V_56 = 1 ;
goto V_77;
}
}
V_60 = F_50 ( V_26 , V_48 , V_45 , V_54 ) ;
if ( V_60 <= 0 ) {
F_8 ( V_74 , L_138 ) ;
F_51 ( V_74 ) ;
V_56 = 1 ;
} else
F_8 ( V_74 , L_139 ) ;
}
if ( ! F_52 ( V_36 , V_26 , V_24 , V_63 , V_65 , V_40 , V_42 ) )
V_56 = 1 ;
V_77:
F_51 ( V_74 ) ;
F_13 ( V_29 ) ;
F_53 ( V_45 ) ;
if ( V_46 )
F_54 ( V_46 ) ;
F_55 ( V_31 ) ;
F_55 ( V_32 ) ;
F_13 ( V_27 ) ;
F_13 ( V_28 ) ;
F_13 ( V_30 ) ;
F_13 ( V_66 ) ;
F_56 ( V_69 ) ;
F_43 ( V_34 ) ;
F_43 ( V_33 ) ;
F_22 ( V_36 ) ;
F_44 ( V_24 ) ;
F_45 ( V_25 ) ;
F_57 ( V_26 ) ;
F_58 ( V_63 ) ;
F_59 ( V_65 ) ;
F_60 ( V_47 , F_13 ) ;
F_60 ( V_48 , F_13 ) ;
F_61 ( V_23 , V_93 ) ;
if ( V_7 )
F_9 ( V_7 ) ;
if ( V_8 )
F_9 ( V_8 ) ;
if ( V_9 )
F_9 ( V_9 ) ;
F_62 ( V_56 ) ;
}
static char * * F_63 ( T_10 * V_94 , T_12 * V_95 )
{
int V_60 ;
T_13 * V_96 = NULL ;
char * V_97 , * V_98 [ V_99 ] , * * V_100 ;
for ( V_60 = 0 ; V_60 < V_99 ; V_60 ++ )
V_98 [ V_60 ] = NULL ;
V_96 = F_64 ( V_95 , NULL ) ;
F_65 ( V_96 ) ;
if ( F_66 ( V_96 ) )
V_97 = F_67 ( L_140 ) ;
else
V_97 = F_68 ( V_96 ) ;
V_98 [ V_101 ] = V_97 ;
F_69 ( V_96 ) ;
V_100 = F_70 ( V_94 -> V_94 , V_101 , V_98 ) ;
F_9 ( V_97 ) ;
return V_100 ;
}
static T_7 * F_23 ( const char * V_5 )
{
T_7 * V_33 = NULL , * V_102 = NULL ;
V_102 = F_71 ( F_72 () ) ;
if ( ! V_102 )
goto V_103;
# ifndef F_36
V_33 = F_73 ( V_5 ) ;
# else
F_8 ( V_74 ,
L_141 ) ;
# endif
if ( ! V_33 )
goto V_103;
F_74 ( V_33 , V_102 ) ;
V_102 = NULL ;
if ( F_75 ( V_33 ) <= 0 ) {
F_8 ( V_74 , L_142 ) ;
F_51 ( V_74 ) ;
goto V_103;
}
return V_33 ;
V_103:
F_43 ( V_33 ) ;
F_22 ( V_102 ) ;
return NULL ;
}
static int F_26 ( T_2 * * V_104 , T_7 * * V_105 , T_7 * V_33 ,
const char * V_5 )
{
int V_106 = 0 , V_107 ;
T_2 * V_24 = NULL ;
char V_108 [ 1024 ] ;
T_7 * V_34 = NULL ;
if ( F_75 ( V_33 ) <= 0 ) {
F_8 ( V_74 , L_143 ) ;
F_51 ( V_74 ) ;
return 0 ;
}
V_34 = F_76 ( V_33 ) ;
* V_105 = V_34 ;
for (; ; ) {
V_107 = F_77 ( V_34 , V_108 , sizeof V_108 ) ;
if ( V_107 <= 0 )
return 1 ;
if ( ! V_106 ) {
if ( strncmp ( V_108 , L_144 , 4 ) ) {
F_8 ( V_74 , L_145 ) ;
return 1 ;
}
V_106 = 1 ;
}
if ( ( V_108 [ 0 ] == '\r' ) || ( V_108 [ 0 ] == '\n' ) )
break;
}
V_24 = F_21 ( V_34 , NULL ) ;
if ( ! V_24 ) {
F_8 ( V_74 , L_146 ) ;
F_51 ( V_74 ) ;
}
* V_104 = V_24 ;
return 1 ;
}
static int F_28 ( T_7 * V_34 , T_3 * V_25 )
{
char V_109 [] =
L_147
L_148 ;
if ( ! V_34 )
return 0 ;
F_8 ( V_34 , V_109 , F_78 ( V_25 , NULL ) ) ;
F_39 ( V_34 , V_25 ) ;
( void ) F_79 ( V_34 ) ;
return 1 ;
}
