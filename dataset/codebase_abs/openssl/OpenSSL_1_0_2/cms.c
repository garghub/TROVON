int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 0 ;
int V_5 = 0 ;
char * * args ;
const char * V_6 = L_1 , * V_7 = L_2 ;
char * V_8 = NULL , * V_9 = NULL , * V_10 = NULL ;
char * V_11 = NULL , * V_12 = NULL ;
F_1 ( V_13 ) * V_14 = NULL , * V_15 = NULL ;
char * V_16 = NULL , * V_17 = NULL , * V_18 = NULL ;
char * V_19 = NULL ;
const T_2 * V_20 = NULL , * V_21 = NULL ;
T_3 * V_22 = NULL , * V_23 = NULL ;
T_4 * V_24 = NULL ;
T_5 * V_25 = NULL , * V_26 = NULL , * V_27 = NULL ;
T_6 * V_28 = NULL ;
F_1 ( T_5 ) * V_29 = NULL , * V_30 = NULL ;
T_7 * V_31 = NULL , * V_32 = NULL , * V_33 = NULL , * V_34 = NULL ;
int V_35 = 0 ;
int V_36 = V_37 , V_38 = 0 , V_39 = 0 ;
int V_40 = 0 ;
int V_41 = 0 , V_42 = - 1 ;
F_1 ( V_13 ) * V_43 = NULL , * V_44 = NULL ;
T_8 * V_45 = NULL ;
char * V_46 = NULL , * V_47 = NULL , * V_48 = NULL ;
char * V_49 = NULL , * V_50 = NULL ;
char * V_51 = NULL , * V_52 = NULL ;
char * V_53 = NULL ;
int V_54 = 0 ;
const T_9 * V_55 = NULL ;
int V_56 = V_57 , V_58 = V_57 ;
int V_59 = V_57 , V_60 = V_61 ;
# ifndef F_2
char * V_62 = NULL ;
# endif
unsigned char * V_63 = NULL , * V_64 = NULL ;
unsigned char * V_65 = NULL , * V_66 = NULL ;
T_10 V_67 = 0 , V_68 = 0 ;
T_11 * V_69 = NULL , * V_70 = NULL ;
T_12 * V_71 = NULL ;
T_13 * V_72 = NULL ;
args = V_2 + 1 ;
V_5 = 1 ;
F_3 () ;
if ( V_73 == NULL ) {
if ( ( V_73 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_73 , V_74 , V_75 | V_76 ) ;
}
if ( ! F_7 ( V_73 , NULL ) )
goto V_77;
while ( ! V_35 && * args && * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_3 ) )
V_4 = V_78 ;
else if ( ! strcmp ( * args , L_4 ) )
V_4 = V_79 ;
else if ( ! strcmp ( * args , L_5 ) )
V_4 = V_80 ;
else if ( ! strcmp ( * args , L_6 ) )
V_4 = V_81 ;
else if ( ! strcmp ( * args , L_7 ) )
V_4 = V_82 ;
else if ( ! strcmp ( * args , L_8 ) )
V_4 = V_83 ;
else if ( ! strcmp ( * args , L_9 ) )
V_40 = 1 ;
else if ( ! strcmp ( * args , L_10 ) ) {
V_4 = V_84 ;
if ( ! args [ 1 ] )
goto V_85;
args ++ ;
V_10 = * args ;
} else if ( ! strcmp ( * args , L_11 ) )
V_4 = V_86 ;
else if ( ! strcmp ( * args , L_12 ) )
V_4 = V_87 ;
else if ( ! strcmp ( * args , L_13 ) )
V_4 = V_88 ;
else if ( ! strcmp ( * args , L_14 ) )
V_4 = V_89 ;
else if ( ! strcmp ( * args , L_15 ) )
V_4 = V_90 ;
else if ( ! strcmp ( * args , L_16 ) )
V_4 = V_91 ;
else if ( ! strcmp ( * args , L_17 ) )
V_4 = V_92 ;
else if ( ! strcmp ( * args , L_18 ) )
V_4 = V_93 ;
else if ( ! strcmp ( * args , L_19 ) )
V_4 = V_94 ;
# ifndef F_8
else if ( ! strcmp ( * args , L_20 ) )
V_20 = F_9 () ;
else if ( ! strcmp ( * args , L_21 ) )
V_20 = F_10 () ;
else if ( ! strcmp ( * args , L_22 ) )
V_21 = F_11 () ;
# endif
# ifndef F_12
else if ( ! strcmp ( * args , L_23 ) )
V_20 = F_13 () ;
# endif
# ifndef F_14
else if ( ! strcmp ( * args , L_24 ) )
V_20 = F_15 () ;
else if ( ! strcmp ( * args , L_25 ) )
V_20 = F_16 () ;
else if ( ! strcmp ( * args , L_26 ) )
V_20 = F_17 () ;
# endif
# ifndef F_18
else if ( ! strcmp ( * args , L_27 ) )
V_20 = F_19 () ;
else if ( ! strcmp ( * args , L_28 ) )
V_20 = F_20 () ;
else if ( ! strcmp ( * args , L_29 ) )
V_20 = F_21 () ;
else if ( ! strcmp ( * args , L_30 ) )
V_21 = F_22 () ;
else if ( ! strcmp ( * args , L_31 ) )
V_21 = F_23 () ;
else if ( ! strcmp ( * args , L_32 ) )
V_21 = F_24 () ;
# endif
# ifndef F_25
else if ( ! strcmp ( * args , L_33 ) )
V_20 = F_26 () ;
else if ( ! strcmp ( * args , L_34 ) )
V_20 = F_27 () ;
else if ( ! strcmp ( * args , L_35 ) )
V_20 = F_28 () ;
# endif
else if ( ! strcmp ( * args , L_36 ) )
V_36 |= V_95 ;
else if ( ! strcmp ( * args , L_37 ) )
V_36 |= V_96 ;
else if ( ! strcmp ( * args , L_38 ) )
V_36 |= V_97 ;
else if ( ! strcmp ( * args , L_39 )
|| ! strcmp ( * args , L_40 ) )
V_36 |= V_98 ;
else if ( ! strcmp ( * args , L_41 ) )
V_36 |= V_99 ;
else if ( ! strcmp ( * args , L_42 ) )
V_36 |= V_100 ;
else if ( ! strcmp ( * args , L_43 ) )
V_36 &= ~ V_37 ;
else if ( ! strcmp ( * args , L_44 ) )
V_36 |= V_101 ;
else if ( ! strcmp ( * args , L_45 ) )
V_36 |= V_102 ;
else if ( ! strcmp ( * args , L_46 ) )
V_36 |= V_103 ;
else if ( ! strcmp ( * args , L_47 ) )
V_36 |= V_104 ;
else if ( ! strcmp ( * args , L_48 ) )
V_36 |= V_105 ;
else if ( ! strcmp ( * args , L_49 ) )
V_36 |= V_106 ;
else if ( ! strcmp ( * args , L_50 ) )
V_36 |= V_107 ;
else if ( ! strcmp ( * args , L_51 ) )
V_36 |= V_107 ;
else if ( ! strcmp ( * args , L_52 ) )
V_36 &= ~ V_107 ;
else if ( ! strcmp ( * args , L_53 ) )
V_36 |= V_108 ;
else if ( ! strcmp ( * args , L_54 ) )
V_36 |= V_109 ;
else if ( ! strcmp ( * args , L_55 ) )
V_38 = 1 ;
else if ( ! strcmp ( * args , L_56 ) )
V_41 = 1 ;
else if ( ! strcmp ( * args , L_57 ) )
V_42 = 0 ;
else if ( ! strcmp ( * args , L_58 ) )
V_42 = 1 ;
else if ( ! strcmp ( * args , L_59 ) ) {
if ( ! args [ 1 ] )
goto V_85;
args ++ ;
if ( ! V_44 )
V_44 = F_29 () ;
F_30 ( V_44 , * args ) ;
} else if ( ! strcmp ( * args , L_60 ) ) {
if ( ! args [ 1 ] )
goto V_85;
args ++ ;
if ( ! V_43 )
V_43 = F_29 () ;
F_30 ( V_43 , * args ) ;
} else if ( ! strcmp ( * args , L_61 ) ) {
V_38 = 1 ;
V_39 = 1 ;
} else if ( ! strcmp ( * args , L_62 ) ) {
long V_110 ;
if ( ! args [ 1 ] )
goto V_85;
args ++ ;
V_63 = F_31 ( * args , & V_110 ) ;
if ( ! V_63 ) {
F_32 ( V_73 , L_63 , * args ) ;
goto V_85;
}
V_67 = ( T_10 ) V_110 ;
} else if ( ! strcmp ( * args , L_64 ) ) {
long V_110 ;
if ( ! args [ 1 ] )
goto V_85;
args ++ ;
V_64 = F_31 ( * args , & V_110 ) ;
if ( ! V_64 ) {
F_32 ( V_73 , L_65 , * args ) ;
goto V_85;
}
V_68 = ( T_10 ) V_110 ;
} else if ( ! strcmp ( * args , L_66 ) ) {
if ( ! args [ 1 ] )
goto V_85;
args ++ ;
V_65 = ( unsigned char * ) * args ;
} else if ( ! strcmp ( * args , L_67 ) ) {
if ( ! args [ 1 ] )
goto V_85;
args ++ ;
V_71 = F_33 ( * args , 0 ) ;
if ( ! V_71 ) {
F_32 ( V_73 , L_68 , * args ) ;
goto V_85;
}
} else if ( ! strcmp ( * args , L_69 ) ) {
if ( ! args [ 1 ] )
goto V_85;
args ++ ;
V_53 = * args ;
V_54 = 1 ;
}
# ifndef F_2
else if ( ! strcmp ( * args , L_70 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_62 = * ++ args ;
}
# endif
else if ( ! strcmp ( * args , L_71 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_51 = * ++ args ;
} else if ( ! strcmp ( * args , L_72 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_46 = * ++ args ;
} else if ( ! strcmp ( * args , L_73 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_47 = * ++ args ;
} else if ( ! strcmp ( * args , L_74 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_48 = * ++ args ;
} else if ( ! strcmp ( * args , L_75 ) ) {
if ( ! args [ 1 ] )
goto V_85;
if ( V_11 ) {
if ( ! V_14 )
V_14 = F_29 () ;
F_30 ( V_14 , V_11 ) ;
if ( ! V_17 )
V_17 = V_11 ;
if ( ! V_15 )
V_15 = F_29 () ;
F_30 ( V_15 , V_17 ) ;
V_17 = NULL ;
}
V_11 = * ++ args ;
} else if ( ! strcmp ( * args , L_76 ) ) {
if ( ! args [ 1 ] )
goto V_85;
if ( V_4 == V_78 ) {
if ( ! V_29 )
V_29 = F_34 () ;
V_25 = F_35 ( V_73 , * ++ args , V_61 ,
NULL , V_3 , L_77 ) ;
if ( ! V_25 )
goto V_77;
F_36 ( V_29 , V_25 ) ;
V_25 = NULL ;
} else
V_12 = * ++ args ;
} else if ( ! strcmp ( * args , L_78 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_19 = * ++ args ;
} else if ( ! strcmp ( * args , L_79 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_55 = F_37 ( * ++ args ) ;
if ( V_55 == NULL ) {
F_32 ( V_73 , L_80 , * args ) ;
goto V_85;
}
} else if ( ! strcmp ( * args , L_81 ) ) {
if ( ! args [ 1 ] )
goto V_85;
if ( V_17 ) {
if ( ! V_11 ) {
F_38 ( V_73 , L_82 ) ;
goto V_85;
}
if ( ! V_14 )
V_14 = F_29 () ;
F_30 ( V_14 , V_11 ) ;
V_11 = NULL ;
if ( ! V_15 )
V_15 = F_29 () ;
F_30 ( V_15 , V_17 ) ;
}
V_17 = * ++ args ;
} else if ( ! strcmp ( * args , L_83 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_60 = F_39 ( * ++ args ) ;
} else if ( ! strcmp ( * args , L_84 ) ) {
int V_111 = - 1 ;
if ( ! args [ 1 ] )
goto V_85;
if ( V_4 == V_78 ) {
if ( V_29 )
V_111 += F_40 ( V_29 ) ;
} else {
if ( V_17 || V_11 )
V_111 ++ ;
if ( V_15 )
V_111 += F_41 ( V_15 ) ;
}
if ( V_111 < 0 ) {
F_32 ( V_73 , L_85 ) ;
goto V_85;
}
if ( V_70 == NULL || V_70 -> V_112 != V_111 ) {
T_11 * V_113 ;
V_113 = F_42 ( sizeof( T_11 ) ) ;
V_113 -> V_112 = V_111 ;
V_113 -> V_114 = F_29 () ;
V_113 -> V_115 = NULL ;
if ( V_69 == NULL )
V_69 = V_113 ;
else
V_70 -> V_115 = V_113 ;
V_70 = V_113 ;
}
F_30 ( V_70 -> V_114 , * ++ args ) ;
} else if ( ! strcmp ( * args , L_86 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_59 = F_39 ( * ++ args ) ;
} else if ( ! strcmp ( * args , L_87 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_16 = * ++ args ;
} else if ( ! strcmp ( * args , L_88 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_49 = * ++ args ;
} else if ( ! strcmp ( * args , L_89 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_50 = * ++ args ;
} else if ( ! strcmp ( * args , L_90 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_8 = * ++ args ;
} else if ( ! strcmp ( * args , L_91 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_56 = F_39 ( * ++ args ) ;
} else if ( ! strcmp ( * args , L_92 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_58 = F_39 ( * ++ args ) ;
} else if ( ! strcmp ( * args , L_93 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_9 = * ++ args ;
} else if ( ! strcmp ( * args , L_94 ) ) {
if ( ! args [ 1 ] )
goto V_85;
V_18 = * ++ args ;
} else if ( F_43 ( & args , NULL , & V_35 , V_73 , & V_72 ) )
continue;
else if ( ( V_20 = F_44 ( * args + 1 ) ) == NULL )
V_35 = 1 ;
args ++ ;
}
if ( ( ( V_42 != - 1 ) || V_44 ) && ! V_43 ) {
F_38 ( V_73 , L_95 ) ;
goto V_85;
}
if ( ! ( V_4 & V_116 ) && ( V_43 || V_44 ) ) {
F_38 ( V_73 , L_96 ) ;
goto V_85;
}
if ( ! ( V_4 & V_116 ) && ( V_15 || V_14 ) ) {
F_38 ( V_73 , L_97 ) ;
goto V_85;
}
if ( V_4 & V_116 ) {
if ( V_17 && ! V_11 ) {
F_38 ( V_73 , L_82 ) ;
goto V_85;
}
if ( V_11 ) {
if ( ! V_14 )
V_14 = F_29 () ;
F_30 ( V_14 , V_11 ) ;
if ( ! V_15 )
V_15 = F_29 () ;
if ( ! V_17 )
V_17 = V_11 ;
F_30 ( V_15 , V_17 ) ;
}
if ( ! V_14 ) {
F_32 ( V_73 , L_98 ) ;
V_35 = 1 ;
}
V_11 = NULL ;
V_17 = NULL ;
V_54 = 1 ;
}
else if ( V_4 == V_79 ) {
if ( ! V_12 && ! V_17 && ! V_63 && ! V_65 ) {
F_32 ( V_73 ,
L_99 ) ;
V_35 = 1 ;
}
} else if ( V_4 == V_78 ) {
if ( ! * args && ! V_63 && ! V_65 && ! V_29 ) {
F_32 ( V_73 , L_100 ) ;
V_35 = 1 ;
}
V_54 = 1 ;
} else if ( ! V_4 )
V_35 = 1 ;
if ( V_35 ) {
V_85:
F_32 ( V_73 , L_101 ) ;
F_32 ( V_73 , L_102 ) ;
F_32 ( V_73 , L_103 ) ;
F_32 ( V_73 , L_104 ) ;
F_32 ( V_73 , L_105 ) ;
F_32 ( V_73 , L_106 ) ;
F_32 ( V_73 , L_107 ) ;
# ifndef F_8
F_32 ( V_73 , L_108 ) ;
F_32 ( V_73 , L_109 ) ;
# endif
# ifndef F_12
F_32 ( V_73 , L_110 ) ;
# endif
# ifndef F_14
F_32 ( V_73 , L_111 ) ;
F_32 ( V_73 , L_112 ) ;
F_32 ( V_73 , L_113 ) ;
# endif
# ifndef F_18
F_32 ( V_73 , L_114 ) ;
F_32 ( V_73 ,
L_115 ) ;
# endif
# ifndef F_25
F_32 ( V_73 , L_116 ) ;
F_32 ( V_73 ,
L_117 ) ;
# endif
F_32 ( V_73 ,
L_118 ) ;
F_32 ( V_73 ,
L_119 ) ;
F_32 ( V_73 ,
L_120 ) ;
F_32 ( V_73 ,
L_121 ) ;
F_32 ( V_73 , L_122 ) ;
F_32 ( V_73 ,
L_123 ) ;
F_32 ( V_73 ,
L_124 ) ;
F_32 ( V_73 , L_125 ) ;
F_32 ( V_73 , L_126 ) ;
F_32 ( V_73 , L_127 ) ;
F_32 ( V_73 ,
L_128 ) ;
F_32 ( V_73 , L_129 ) ;
F_32 ( V_73 , L_130 ) ;
F_32 ( V_73 ,
L_131 ) ;
F_32 ( V_73 ,
L_132 ) ;
F_32 ( V_73 ,
L_133 ) ;
F_32 ( V_73 , L_134 ) ;
F_32 ( V_73 , L_135 ) ;
F_32 ( V_73 ,
L_136 ) ;
F_32 ( V_73 ,
L_137 ) ;
F_32 ( V_73 , L_138 ) ;
F_32 ( V_73 , L_139 ) ;
F_32 ( V_73 , L_140 ) ;
F_32 ( V_73 ,
L_141 ) ;
F_32 ( V_73 ,
L_142 ) ;
F_32 ( V_73 , L_143 ) ;
F_32 ( V_73 ,
L_144 ) ;
F_32 ( V_73 ,
L_145 ) ;
# ifndef F_2
F_32 ( V_73 ,
L_146 ) ;
# endif
F_32 ( V_73 , L_147 ) ;
F_32 ( V_73 , L_148 , V_117 ,
V_117 ) ;
F_32 ( V_73 ,
L_149 ) ;
F_32 ( V_73 , L_150 ) ;
F_32 ( V_73 ,
L_151 ) ;
goto V_77;
}
# ifndef F_2
V_3 = F_45 ( V_73 , V_62 , 0 ) ;
# endif
if ( ! F_46 ( V_73 , V_51 , NULL , & V_52 , NULL ) ) {
F_32 ( V_73 , L_152 ) ;
goto V_77;
}
if ( V_54 ) {
F_47 ( NULL , V_73 , ( V_53 != NULL ) ) ;
if ( V_53 != NULL )
F_32 ( V_73 , L_153 ,
F_48 ( V_53 ) ) ;
}
V_5 = 2 ;
if ( ! ( V_4 & V_116 ) )
V_36 &= ~ V_37 ;
if ( V_4 & V_118 ) {
if ( V_58 == V_119 )
V_7 = L_154 ;
} else {
if ( V_36 & V_102 )
V_7 = L_154 ;
}
if ( V_4 & V_120 ) {
if ( V_56 == V_119 )
V_6 = L_155 ;
} else {
if ( V_36 & V_102 )
V_6 = L_155 ;
}
if ( V_4 == V_78 ) {
if ( ! V_20 ) {
# ifndef F_8
V_20 = F_9 () ;
# else
F_32 ( V_73 , L_156 ) ;
goto V_77;
# endif
}
if ( V_63 && ! V_64 ) {
F_32 ( V_73 , L_157 ) ;
goto V_77;
}
if ( * args && ! V_29 )
V_29 = F_34 () ;
while ( * args ) {
if ( ! ( V_25 = F_35 ( V_73 , * args , V_61 ,
NULL , V_3 , L_77 ) ) )
goto V_77;
F_36 ( V_29 , V_25 ) ;
V_25 = NULL ;
args ++ ;
}
}
if ( V_16 ) {
if ( ! ( V_30 = F_49 ( V_73 , V_16 , V_61 , NULL ,
V_3 , L_158 ) ) ) {
F_50 ( V_73 ) ;
goto V_77;
}
}
if ( V_12 && ( V_4 == V_79 ) ) {
if ( ! ( V_26 = F_35 ( V_73 , V_12 , V_61 , NULL ,
V_3 , L_77 ) ) ) {
F_50 ( V_73 ) ;
goto V_77;
}
}
if ( V_4 == V_81 ) {
if ( ! ( V_27 = F_35 ( V_73 , V_11 , V_61 , NULL ,
V_3 , L_159 ) ) ) {
F_50 ( V_73 ) ;
goto V_77;
}
}
if ( V_4 == V_79 ) {
if ( ! V_17 )
V_17 = V_12 ;
} else if ( ( V_4 == V_80 ) || ( V_4 == V_81 ) ) {
if ( ! V_17 )
V_17 = V_11 ;
} else
V_17 = NULL ;
if ( V_17 ) {
V_28 = F_51 ( V_73 , V_17 , V_60 , 0 , V_52 , V_3 ,
L_160 ) ;
if ( ! V_28 )
goto V_77;
}
if ( V_8 ) {
if ( ! ( V_31 = F_52 ( V_8 , V_6 ) ) ) {
F_32 ( V_73 , L_161 , V_8 ) ;
goto V_77;
}
} else
V_31 = F_53 ( V_121 , V_75 ) ;
if ( V_4 & V_120 ) {
if ( V_56 == V_57 )
V_22 = F_54 ( V_31 , & V_33 ) ;
else if ( V_56 == V_61 )
V_22 = F_55 ( V_31 , NULL , NULL , NULL ) ;
else if ( V_56 == V_119 )
V_22 = F_56 ( V_31 , NULL ) ;
else {
F_32 ( V_73 , L_162 ) ;
goto V_77;
}
if ( ! V_22 ) {
F_32 ( V_73 , L_163 ) ;
goto V_77;
}
if ( V_18 ) {
F_57 ( V_33 ) ;
if ( ! ( V_33 = F_52 ( V_18 , L_155 ) ) ) {
F_32 ( V_73 , L_164 , V_18 ) ;
goto V_77;
}
}
if ( V_19 ) {
F_1 ( T_5 ) * V_122 ;
V_122 = F_58 ( V_22 ) ;
if ( ! F_59 ( V_19 , V_122 ) ) {
F_32 ( V_73 ,
L_165 , V_19 ) ;
V_5 = 5 ;
goto V_77;
}
F_60 ( V_122 , V_123 ) ;
}
}
if ( V_10 ) {
char * V_124 = ( V_59 == V_119 ) ? L_155 : L_1 ;
if ( ! ( V_34 = F_52 ( V_10 , V_124 ) ) ) {
F_32 ( V_73 , L_166 , V_10 ) ;
goto V_77;
}
if ( V_59 == V_57 )
V_23 = F_54 ( V_34 , NULL ) ;
else if ( V_59 == V_61 )
V_23 = F_55 ( V_34 , NULL , NULL , NULL ) ;
else if ( V_59 == V_119 )
V_23 = F_56 ( V_34 , NULL ) ;
else {
F_32 ( V_73 , L_167 ) ;
goto V_77;
}
if ( ! V_23 ) {
F_32 ( V_73 , L_168 ) ;
goto V_77;
}
}
if ( V_9 ) {
if ( ! ( V_32 = F_52 ( V_9 , V_7 ) ) ) {
F_32 ( V_73 , L_169 , V_9 ) ;
goto V_77;
}
} else {
V_32 = F_53 ( stdout , V_75 ) ;
# ifdef F_61
{
T_7 * V_125 = F_4 ( F_62 () ) ;
V_32 = F_63 ( V_125 , V_32 ) ;
}
# endif
}
if ( ( V_4 == V_83 ) || ( V_4 == V_84 ) ) {
if ( ! ( V_24 = F_64 ( V_73 , V_49 , V_50 ) ) )
goto V_77;
F_65 ( V_24 , V_126 ) ;
if ( V_72 )
F_66 ( V_24 , V_72 ) ;
}
V_5 = 3 ;
if ( V_4 == V_88 ) {
V_22 = F_67 ( V_31 , V_36 ) ;
} else if ( V_4 == V_90 ) {
V_22 = F_68 ( V_31 , V_55 , V_36 ) ;
} else if ( V_4 == V_91 ) {
V_22 = F_69 ( V_31 , - 1 , V_36 ) ;
} else if ( V_4 == V_78 ) {
int V_127 ;
V_36 |= V_128 ;
V_22 = F_70 ( NULL , V_31 , V_20 , V_36 ) ;
if ( ! V_22 )
goto V_77;
for ( V_127 = 0 ; V_127 < F_40 ( V_29 ) ; V_127 ++ ) {
T_14 * V_129 ;
T_11 * V_130 ;
int V_131 = V_36 ;
T_5 * V_132 = F_71 ( V_29 , V_127 ) ;
for ( V_130 = V_69 ; V_130 ; V_130 = V_130 -> V_115 ) {
if ( V_130 -> V_112 == V_127 ) {
V_131 |= V_133 ;
break;
}
}
V_129 = F_72 ( V_22 , V_132 , V_131 ) ;
if ( ! V_129 )
goto V_77;
if ( V_130 ) {
T_15 * V_134 ;
V_134 = F_73 ( V_129 ) ;
if ( ! F_74 ( V_134 , V_130 -> V_114 ) )
goto V_77;
}
if ( F_75 ( V_129 ) == V_135
&& V_21 ) {
T_16 * V_136 ;
V_136 = F_76 ( V_129 ) ;
F_77 ( V_136 , V_21 , NULL , NULL , NULL ) ;
}
}
if ( V_63 ) {
if ( ! F_78 ( V_22 , V_137 ,
V_63 , V_67 ,
V_64 , V_68 ,
NULL , NULL , NULL ) )
goto V_77;
V_63 = NULL ;
V_64 = NULL ;
}
if ( V_65 ) {
V_66 = ( unsigned char * ) F_79 ( ( char * ) V_65 ) ;
if ( ! V_66 )
goto V_77;
if ( ! F_80 ( V_22 ,
- 1 , V_137 , V_137 ,
V_66 , - 1 , NULL ) )
goto V_77;
V_66 = NULL ;
}
if ( ! ( V_36 & V_107 ) ) {
if ( ! F_81 ( V_22 , V_31 , NULL , V_36 ) )
goto V_77;
}
} else if ( V_4 == V_94 ) {
V_22 = F_82 ( V_31 , V_20 ,
V_63 , V_67 , V_36 ) ;
} else if ( V_4 == V_81 ) {
T_3 * V_138 = NULL ;
F_1 ( V_139 ) * V_140 ;
V_139 * V_141 ;
V_140 = F_83 ( V_22 ) ;
if ( ! V_140 )
goto V_77;
V_141 = F_84 ( V_140 , 0 ) ;
V_138 = F_85 ( V_141 , V_27 , V_28 , V_30 , V_36 ) ;
if ( ! V_138 )
goto V_77;
F_86 ( V_22 ) ;
V_22 = V_138 ;
} else if ( V_4 & V_116 ) {
int V_127 ;
if ( V_4 == V_80 ) {
if ( V_36 & V_37 ) {
if ( V_58 == V_57 )
V_36 |= V_107 ;
}
V_36 |= V_128 ;
V_22 = F_87 ( NULL , NULL , V_30 , V_31 , V_36 ) ;
if ( ! V_22 )
goto V_77;
if ( V_71 )
F_88 ( V_22 , V_71 ) ;
if ( V_43 ) {
V_45 = F_89 ( V_43 , V_42 , V_44 ) ;
if ( ! V_45 ) {
F_38 ( V_73 ,
L_170 ) ;
goto V_77;
}
}
} else
V_36 |= V_142 ;
for ( V_127 = 0 ; V_127 < F_41 ( V_14 ) ; V_127 ++ ) {
V_139 * V_141 ;
T_11 * V_130 ;
int V_131 = V_36 ;
V_11 = F_90 ( V_14 , V_127 ) ;
V_17 = F_90 ( V_15 , V_127 ) ;
V_27 = F_35 ( V_73 , V_11 , V_61 , NULL ,
V_3 , L_171 ) ;
if ( ! V_27 )
goto V_77;
V_28 = F_51 ( V_73 , V_17 , V_60 , 0 , V_52 , V_3 ,
L_160 ) ;
if ( ! V_28 )
goto V_77;
for ( V_130 = V_69 ; V_130 ; V_130 = V_130 -> V_115 ) {
if ( V_130 -> V_112 == V_127 ) {
V_131 |= V_133 ;
break;
}
}
V_141 = F_91 ( V_22 , V_27 , V_28 , V_55 , V_131 ) ;
if ( ! V_141 )
goto V_77;
if ( V_130 ) {
T_15 * V_134 ;
V_134 = F_92 ( V_141 ) ;
if ( ! F_74 ( V_134 , V_130 -> V_114 ) )
goto V_77;
}
if ( V_45 && ! F_93 ( V_141 , V_45 ) )
goto V_77;
V_123 ( V_27 ) ;
V_27 = NULL ;
F_94 ( V_28 ) ;
V_28 = NULL ;
}
if ( ( V_4 == V_80 ) && ! ( V_36 & V_107 ) ) {
if ( ! F_81 ( V_22 , V_31 , NULL , V_36 ) )
goto V_77;
}
}
if ( ! V_22 ) {
F_32 ( V_73 , L_172 ) ;
goto V_77;
}
V_5 = 4 ;
if ( V_4 == V_79 ) {
if ( V_36 & V_95 )
F_95 ( V_22 , NULL , NULL , NULL , NULL , V_36 ) ;
if ( V_63 ) {
if ( ! F_96 ( V_22 ,
V_63 , V_67 ,
V_64 , V_68 ) ) {
F_38 ( V_73 , L_173 ) ;
goto V_77;
}
}
if ( V_28 ) {
if ( ! F_97 ( V_22 , V_28 , V_26 ) ) {
F_38 ( V_73 , L_174 ) ;
goto V_77;
}
}
if ( V_65 ) {
if ( ! F_98 ( V_22 , V_65 , - 1 ) ) {
F_38 ( V_73 , L_175 ) ;
goto V_77;
}
}
if ( ! F_95 ( V_22 , NULL , NULL , V_33 , V_32 , V_36 ) ) {
F_32 ( V_73 , L_176 ) ;
goto V_77;
}
} else if ( V_4 == V_87 ) {
if ( ! F_99 ( V_22 , V_32 , V_36 ) )
goto V_77;
} else if ( V_4 == V_92 ) {
if ( ! F_100 ( V_22 , V_33 , V_32 , V_36 ) )
goto V_77;
} else if ( V_4 == V_89 ) {
if ( F_101 ( V_22 , V_33 , V_32 , V_36 ) > 0 )
F_32 ( V_73 , L_177 ) ;
else {
F_32 ( V_73 , L_178 ) ;
goto V_77;
}
} else if ( V_4 == V_93 ) {
if ( ! F_102 ( V_22 , V_63 , V_67 ,
V_33 , V_32 , V_36 ) )
goto V_77;
} else if ( V_4 == V_83 ) {
if ( F_103 ( V_22 , V_30 , V_24 , V_33 , V_32 , V_36 ) > 0 )
F_32 ( V_73 , L_177 ) ;
else {
F_32 ( V_73 , L_178 ) ;
if ( V_40 )
V_5 = V_143 + 32 ;
goto V_77;
}
if ( V_11 ) {
F_1 ( T_5 ) * V_144 ;
V_144 = F_104 ( V_22 ) ;
if ( ! F_59 ( V_11 , V_144 ) ) {
F_32 ( V_73 ,
L_179 , V_11 ) ;
V_5 = 5 ;
goto V_77;
}
F_105 ( V_144 ) ;
}
if ( V_41 )
F_106 ( V_73 , V_22 ) ;
} else if ( V_4 == V_84 ) {
if ( F_107 ( V_23 , V_22 , V_30 , V_24 , V_36 ) > 0 )
F_32 ( V_73 , L_177 ) ;
else {
F_32 ( V_73 , L_178 ) ;
goto V_77;
}
} else {
if ( V_38 ) {
if ( V_39 )
F_108 ( V_32 , V_22 , 0 , NULL ) ;
} else if ( V_58 == V_57 ) {
if ( V_46 )
F_32 ( V_32 , L_180 , V_46 ) ;
if ( V_47 )
F_32 ( V_32 , L_181 , V_47 ) ;
if ( V_48 )
F_32 ( V_32 , L_182 , V_48 ) ;
if ( V_4 == V_82 )
V_5 = F_109 ( V_32 , V_22 , V_33 , V_36 ) ;
else
V_5 = F_109 ( V_32 , V_22 , V_31 , V_36 ) ;
} else if ( V_58 == V_61 )
V_5 = F_110 ( V_32 , V_22 , V_31 , V_36 ) ;
else if ( V_58 == V_119 )
V_5 = F_111 ( V_32 , V_22 , V_31 , V_36 ) ;
else {
F_32 ( V_73 , L_183 ) ;
goto V_77;
}
if ( V_5 <= 0 ) {
V_5 = 6 ;
goto V_77;
}
}
V_5 = 0 ;
V_77:
if ( V_5 )
F_50 ( V_73 ) ;
if ( V_54 )
F_112 ( NULL , V_73 ) ;
F_60 ( V_29 , V_123 ) ;
F_60 ( V_30 , V_123 ) ;
if ( V_72 )
F_113 ( V_72 ) ;
if ( V_14 )
F_114 ( V_14 ) ;
if ( V_15 )
F_114 ( V_15 ) ;
if ( V_63 )
F_115 ( V_63 ) ;
if ( V_64 )
F_115 ( V_64 ) ;
if ( V_66 )
F_115 ( V_66 ) ;
if ( V_71 )
F_116 ( V_71 ) ;
if ( V_45 )
F_117 ( V_45 ) ;
if ( V_43 )
F_114 ( V_43 ) ;
if ( V_44 )
F_114 ( V_44 ) ;
for ( V_70 = V_69 ; V_70 ; ) {
T_11 * V_145 ;
F_114 ( V_70 -> V_114 ) ;
V_145 = V_70 -> V_115 ;
F_115 ( V_70 ) ;
V_70 = V_145 ;
}
F_118 ( V_24 ) ;
V_123 ( V_25 ) ;
V_123 ( V_26 ) ;
V_123 ( V_27 ) ;
F_94 ( V_28 ) ;
F_86 ( V_22 ) ;
F_86 ( V_23 ) ;
F_57 ( V_34 ) ;
F_57 ( V_31 ) ;
F_57 ( V_33 ) ;
F_119 ( V_32 ) ;
if ( V_52 )
F_115 ( V_52 ) ;
return ( V_5 ) ;
}
static int V_126 ( int V_146 , T_17 * V_147 )
{
int error ;
error = F_120 ( V_147 ) ;
V_143 = error ;
if ( ( error != V_148 )
&& ( ( error != V_149 ) || ( V_146 != 2 ) ) )
return V_146 ;
F_121 ( NULL , V_147 ) ;
return V_146 ;
}
static void F_106 ( T_7 * V_32 , T_3 * V_22 )
{
F_1 ( V_139 ) * V_140 ;
V_139 * V_141 ;
T_8 * V_45 ;
int V_150 ;
F_1 ( V_151 ) * V_152 , * V_153 ;
T_18 * V_154 ;
int V_127 , V_155 ;
V_140 = F_83 ( V_22 ) ;
for ( V_127 = 0 ; V_127 < F_122 ( V_140 ) ; V_127 ++ ) {
V_141 = F_84 ( V_140 , V_127 ) ;
V_155 = F_123 ( V_141 , & V_45 ) ;
F_32 ( V_73 , L_184 , V_127 + 1 ) ;
if ( V_155 == 0 )
F_38 ( V_73 , L_185 ) ;
else if ( V_155 < 0 ) {
F_38 ( V_73 , L_186 ) ;
F_50 ( V_73 ) ;
} else {
char * V_156 ;
int V_157 ;
F_124 ( V_45 , & V_154 , & V_150 ,
& V_153 , & V_152 ) ;
F_38 ( V_32 , L_187 ) ;
V_157 = F_125 ( V_154 ) ;
V_156 = ( char * ) F_126 ( V_154 ) ;
F_127 ( V_32 , V_156 , V_157 , 4 ) ;
F_38 ( V_32 , L_188 ) ;
if ( V_153 ) {
F_38 ( V_32 , L_189 ) ;
F_128 ( V_32 , V_153 ) ;
} else if ( V_150 == 1 )
F_38 ( V_32 , L_190 ) ;
else if ( V_150 == 0 )
F_38 ( V_32 , L_191 ) ;
else
F_32 ( V_32 , L_192 , V_150 ) ;
F_38 ( V_32 , L_193 ) ;
F_128 ( V_32 , V_152 ) ;
}
if ( V_45 )
F_117 ( V_45 ) ;
}
}
