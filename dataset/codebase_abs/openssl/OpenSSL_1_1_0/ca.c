int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL ;
T_3 * V_5 = NULL , * V_6 = NULL ;
T_4 * V_7 = NULL ;
T_5 * V_8 = NULL , * V_9 = NULL , * V_10 = NULL ;
T_6 * V_11 ;
T_7 * V_12 ;
T_8 * V_13 = NULL ;
T_9 V_14 ;
F_2 ( V_15 ) * V_16 = NULL ;
F_2 ( V_17 ) * V_18 = NULL ;
F_2 ( V_19 ) * V_20 = NULL ;
T_10 * V_21 = NULL ;
const T_11 * V_22 = NULL ;
char * V_23 = V_24 , * V_25 = NULL ;
char * V_26 = NULL , * V_27 = NULL , * V_28 = NULL ;
char * V_29 = NULL , * V_30 = NULL , * V_31 = NULL , * V_32 = NULL ;
const char * V_33 = NULL , * V_34 = NULL , * V_35 = NULL ;
const char * V_36 = NULL , * V_37 = NULL , * V_38 = NULL ;
char * V_39 = NULL , * V_40 = NULL , * V_41 = NULL , * V_42 = NULL ;
const char * V_43 = NULL , * V_44 = NULL ;
char * V_45 , * V_46 = NULL , * V_47 = NULL ;
char * V_48 = NULL , * V_49 , * V_50 = NULL ;
char V_51 [ 3 ] [ V_52 ] ;
char * const * V_53 ;
const char * V_54 ;
int V_55 = 0 , V_56 = 0 , V_57 = 0 , V_58 = 0 ;
int V_59 = 0 , V_60 = 1 , V_61 = 0 , V_62 = V_63 ;
int V_64 = V_65 , V_66 = 0 , V_67 = 0 , V_68 = 0 ;
int V_69 = 1 , V_70 = 1 , V_71 = 0 , V_72 = 0 , V_73 = 0 , V_74 = 0 ;
int V_75 , V_76 , V_77 = V_78 , V_79 = 0 ;
long V_80 = 0 , V_81 = 0 , V_82 = 0 , V_83 = 0 ;
unsigned long V_84 = V_85 , V_86 = 0 , V_87 = 0 ;
V_19 * V_88 = NULL , * V_89 = NULL , * V_90 = NULL ;
T_12 * V_91 = NULL ;
T_13 V_92 ;
V_45 = F_3 ( V_1 , V_2 , V_93 ) ;
while ( ( V_92 = F_4 () ) != V_94 ) {
switch ( V_92 ) {
case V_94 :
case V_95 :
V_96:
F_5 ( V_97 , L_1 , V_45 ) ;
goto V_98;
case V_99 :
F_6 ( V_93 ) ;
V_69 = 0 ;
goto V_98;
case V_100 :
V_71 = 1 ;
V_33 = F_7 () ;
break;
case V_101 :
V_40 = F_7 () ;
break;
case V_102 :
V_72 = 1 ;
break;
case V_103 :
V_23 = F_7 () ;
break;
case V_104 :
V_25 = F_7 () ;
break;
case V_105 :
V_44 = F_7 () ;
break;
case V_106 :
V_84 = V_107 ;
break;
case V_108 :
V_55 = 1 ;
break;
case V_109 :
V_66 = 1 ;
break;
case V_110 :
V_46 = F_7 () ;
break;
case V_111 :
V_47 = F_7 () ;
break;
case V_112 :
V_83 = atoi ( F_7 () ) ;
break;
case V_113 :
V_26 = F_7 () ;
break;
case V_114 :
V_27 = F_7 () ;
break;
case V_115 :
V_28 = F_7 () ;
break;
case V_116 :
if ( ! F_8 ( F_7 () , V_117 , & V_64 ) )
goto V_96;
break;
case V_118 :
V_38 = F_7 () ;
break;
case V_119 :
V_32 = F_7 () ;
break;
case V_120 :
V_29 = F_7 () ;
break;
case V_121 :
V_79 = 1 ;
break;
case V_122 :
V_39 = F_7 () ;
break;
case V_123 :
if ( V_18 == NULL )
V_18 = F_9 () ;
if ( V_18 == NULL
|| ! F_10 ( V_18 , F_7 () ) )
goto V_98;
break;
case V_124 :
V_67 = 1 ;
break;
case V_125 :
V_59 = 1 ;
break;
case V_126 :
V_127 = 1 ;
break;
case V_128 :
V_70 = 0 ;
break;
case V_129 :
V_73 = 1 ;
break;
case V_130 :
V_131 = 1 ;
break;
case V_132 :
V_80 = atol ( F_7 () ) ;
break;
case V_133 :
V_81 = atol ( F_7 () ) ;
break;
case V_134 :
V_82 = atol ( F_7 () ) ;
break;
case V_135 :
V_71 = 1 ;
goto V_136;
case V_137 :
V_35 = F_7 () ;
V_71 = 1 ;
break;
case V_138 :
V_34 = F_7 () ;
V_71 = 1 ;
break;
case V_139 :
V_33 = F_7 () ;
V_74 = 1 ;
break;
case V_140 :
V_33 = F_7 () ;
V_74 = 2 ;
break;
case V_141 :
V_36 = F_7 () ;
break;
case V_142 :
V_37 = F_7 () ;
break;
case V_143 :
V_42 = F_7 () ;
break;
case V_144 :
V_61 = 1 ;
break;
case V_145 :
V_30 = F_7 () ;
break;
case V_146 :
V_41 = F_7 () ;
V_77 = V_147 ;
break;
case V_148 :
V_41 = F_7 () ;
V_77 = V_149 ;
break;
case V_150 :
V_41 = F_7 () ;
V_77 = V_151 ;
break;
case V_152 :
V_41 = F_7 () ;
V_77 = V_153 ;
break;
case V_154 :
V_4 = F_11 ( F_7 () , 0 ) ;
break;
}
}
V_136:
V_1 = F_12 () ;
V_2 = F_13 () ;
F_5 ( V_97 , L_2 , V_23 ) ;
if ( ( V_3 = F_14 ( V_23 ) ) == NULL )
goto V_98;
if ( V_23 != V_24 && ! F_15 ( V_3 ) )
goto V_98;
if ( V_25 == NULL
&& ( V_25 = F_16 ( V_3 , V_155 , V_156 ) ) == NULL )
goto V_98;
if ( V_3 != NULL ) {
V_54 = F_17 ( V_3 , NULL , L_3 ) ;
if ( V_54 == NULL )
F_18 () ;
if ( V_54 != NULL ) {
T_5 * V_157 ;
V_157 = F_19 ( V_54 , L_4 ) ;
if ( V_157 == NULL ) {
F_18 () ;
} else {
F_20 ( V_157 ) ;
F_21 ( V_157 ) ;
}
}
if ( ! F_22 ( V_3 ) ) {
F_23 ( V_97 ) ;
goto V_98;
}
}
V_50 = F_17 ( V_3 , V_155 , L_5 ) ;
if ( V_50 == NULL )
F_18 () ;
F_24 ( V_50 , 0 ) ;
V_49 = F_17 ( V_3 , V_25 , V_158 ) ;
if ( ! V_49 )
F_18 () ;
if ( V_49 && ! F_25 ( V_49 ) ) {
F_5 ( V_97 , L_6 , V_49 ) ;
goto V_98;
}
if ( V_84 != V_107 ) {
V_49 = F_17 ( V_3 , V_25 , V_159 ) ;
if ( ! V_49 )
F_18 () ;
else if ( strcmp ( V_49 , L_7 ) == 0 )
V_84 = V_107 ;
}
V_14 . V_160 = 1 ;
V_54 = F_17 ( V_3 , V_25 , V_161 ) ;
if ( V_54 ) {
V_14 . V_160 = F_26 ( V_54 , 1 ) ;
} else
F_18 () ;
if ( V_42 ) {
V_48 = F_16 ( V_3 , V_25 , V_162 ) ;
if ( V_48 == NULL )
goto V_98;
V_13 = F_27 ( V_48 , & V_14 ) ;
if ( V_13 == NULL )
goto V_98;
if ( ! F_28 ( V_13 ) )
goto V_98;
if ( F_29 ( V_42 , V_13 ) != 1 )
F_5 ( V_97 , L_8 , V_42 ) ;
goto V_98;
}
if ( V_28 == NULL
&& ( V_28 = F_16 ( V_3 , V_25 , V_163 ) ) == NULL )
goto V_98;
if ( ! V_32 ) {
V_56 = 1 ;
if ( ! F_30 ( V_38 , NULL , & V_32 , NULL ) ) {
F_5 ( V_97 , L_9 ) ;
goto V_98;
}
}
V_7 = F_31 ( V_28 , V_64 , 0 , V_32 , V_4 , L_10 ) ;
if ( V_32 )
F_32 ( V_32 , strlen ( V_32 ) ) ;
if ( V_7 == NULL ) {
goto V_98;
}
if ( ! V_79 || V_34 || V_35 || V_73 ) {
if ( V_29 == NULL
&& ( V_29 = F_16 ( V_3 , V_25 , V_164 ) ) == NULL )
goto V_98;
V_88 = F_33 ( V_29 , V_65 , L_11 ) ;
if ( V_88 == NULL )
goto V_98;
if ( ! F_34 ( V_88 , V_7 ) ) {
F_5 ( V_97 ,
L_12 ) ;
goto V_98;
}
}
if ( ! V_79 )
V_89 = V_88 ;
V_49 = F_17 ( V_3 , V_155 , V_165 ) ;
if ( V_49 == NULL )
F_18 () ;
if ( ( V_49 != NULL ) && ( ( * V_49 == 'y' ) || ( * V_49 == 'Y' ) ) )
V_127 = 1 ;
V_49 = F_17 ( V_3 , V_155 , V_166 ) ;
if ( V_49 == NULL )
F_18 () ;
if ( ( V_49 != NULL ) && ( ( * V_49 == 'y' ) || ( * V_49 == 'Y' ) ) )
V_131 = 1 ;
V_49 = F_17 ( V_3 , V_25 , V_167 ) ;
if ( V_49 ) {
if ( ! F_35 ( & V_86 , V_49 ) ) {
F_5 ( V_97 , L_13 , V_49 ) ;
goto V_98;
}
V_60 = 0 ;
} else {
V_86 = V_168 ;
F_18 () ;
}
V_49 = F_17 ( V_3 , V_25 , V_169 ) ;
if ( V_49 ) {
if ( ! F_36 ( & V_87 , V_49 ) ) {
F_5 ( V_97 , L_14 , V_49 ) ;
goto V_98;
}
V_60 = 0 ;
} else
F_18 () ;
V_49 = F_17 ( V_3 , V_25 , V_170 ) ;
if ( V_49 ) {
if ( ! F_37 ( & V_62 , V_49 ) ) {
F_5 ( V_97 , L_15 , V_49 ) ;
goto V_98;
}
} else
F_18 () ;
if ( ( V_39 == NULL ) && ( V_71 ) ) {
V_39 = F_17 ( V_3 , V_25 , V_171 ) ;
if ( V_39 == NULL ) {
F_5 ( V_97 ,
L_16 ) ;
goto V_98;
}
#ifndef F_38
if ( F_39 ( V_39 ) <= 0 ) {
F_5 ( V_97 , L_17 , V_45 , V_39 ) ;
perror ( V_39 ) ;
goto V_98;
}
#endif
}
V_48 = F_16 ( V_3 , V_25 , V_162 ) ;
if ( V_48 == NULL )
goto V_98;
V_13 = F_27 ( V_48 , & V_14 ) ;
if ( V_13 == NULL )
goto V_98;
for ( V_75 = 0 ; V_75 < F_40 ( V_13 -> V_13 -> V_172 ) ; V_75 ++ ) {
V_53 = F_41 ( V_13 -> V_13 -> V_172 , V_75 ) ;
if ( ( V_53 [ V_173 ] [ 0 ] != V_174 ) && ( V_53 [ V_175 ] [ 0 ] != '\0' ) ) {
F_5 ( V_97 ,
L_18 ,
V_75 + 1 ) ;
goto V_98;
}
if ( ( V_53 [ V_173 ] [ 0 ] == V_174 ) &&
! F_42 ( NULL , V_53 [ V_175 ] ) ) {
F_5 ( V_97 , L_19 , V_75 + 1 ) ;
goto V_98;
}
if ( ! F_43 ( ( char * ) V_53 [ V_176 ] ) ) {
F_5 ( V_97 , L_20 , V_75 + 1 ) ;
goto V_98;
}
V_54 = V_53 [ V_177 ] ;
V_76 = strlen ( V_54 ) ;
if ( * V_54 == '-' ) {
V_54 ++ ;
V_76 -- ;
}
if ( ( V_76 & 1 ) || ( V_76 < 2 ) ) {
F_5 ( V_97 , L_21 ,
V_75 + 1 , V_76 ) ;
goto V_98;
}
for ( ; * V_54 ; V_54 ++ ) {
if ( ! isxdigit ( F_44 ( * V_54 ) ) ) {
F_5 ( V_97 ,
L_22 ,
V_75 + 1 , * V_54 , * V_54 ) ;
goto V_98;
}
}
}
if ( V_72 ) {
F_45 ( V_178 , V_13 -> V_13 ) ;
F_5 ( V_97 , L_23 ,
F_40 ( V_13 -> V_13 -> V_172 ) ) ;
F_5 ( V_97 , L_24 ) ;
}
if ( ! F_28 ( V_13 ) )
goto V_98;
if ( V_61 ) {
if ( V_72 )
F_5 ( V_97 , L_25 , V_48 ) ;
V_75 = F_46 ( V_13 ) ;
if ( V_75 == - 1 ) {
F_5 ( V_97 , L_26 ) ;
goto V_98;
} else if ( V_75 == 0 ) {
if ( V_72 )
F_5 ( V_97 , L_27 ) ;
} else {
if ( ! F_47 ( V_48 , L_28 , V_13 ) )
goto V_98;
if ( ! F_48 ( V_48 , L_28 , L_29 ) )
goto V_98;
if ( V_72 )
F_5 ( V_97 ,
L_30 , V_75 ) ;
}
}
if ( V_37 ) {
if ( ( V_179 = F_14 ( V_37 ) ) == NULL ) {
V_69 = 1 ;
goto V_98;
}
if ( V_72 )
F_5 ( V_97 , L_31 ,
V_37 ) ;
if ( V_36 == NULL ) {
V_36 = F_17 ( V_179 , L_32 , L_33 ) ;
if ( V_36 == NULL )
V_36 = L_32 ;
}
}
if ( V_71 || V_73 ) {
V_10 = F_49 ( V_40 , 'w' , V_180 ) ;
if ( V_10 == NULL )
goto V_98;
}
if ( V_26 == NULL
&& ( V_26 = F_16 ( V_3 , V_25 , V_181 ) ) == NULL )
goto V_98;
if ( strcmp ( V_26 , L_32 ) == 0 ) {
int V_182 ;
if ( F_50 ( V_7 , & V_182 ) <= 0 ) {
F_51 ( V_97 , L_34 ) ;
goto V_98;
}
V_26 = ( char * ) F_52 ( V_182 ) ;
}
if ( ! F_53 ( V_26 , & V_22 ) ) {
goto V_98;
}
if ( V_71 ) {
if ( V_70 == 1 ) {
char * V_183 = NULL ;
V_183 = F_17 ( V_3 , V_25 , V_184 ) ;
if ( V_183 != NULL && strcmp ( V_183 , L_35 ) == 0 )
V_70 = 0 ;
}
if ( V_72 )
F_5 ( V_97 , L_36 ,
F_54 ( F_55 ( V_22 ) ) ) ;
if ( V_27 == NULL
&& ( V_27 = F_16 ( V_3 , V_25 , V_185 ) ) == NULL )
goto V_98;
if ( V_72 )
F_5 ( V_97 , L_37 , V_27 ) ;
V_43 = F_16 ( V_3 , V_25 , V_186 ) ;
if ( V_43 == NULL )
goto V_98;
if ( ! V_179 ) {
if ( ! V_36 ) {
V_36 = F_17 ( V_3 , V_25 , V_187 ) ;
if ( ! V_36 )
F_18 () ;
}
if ( V_36 ) {
T_14 V_188 ;
F_56 ( & V_188 ) ;
F_57 ( & V_188 , V_3 ) ;
if ( ! F_58 ( V_3 , & V_188 , V_36 , NULL ) ) {
F_5 ( V_97 ,
L_38 ,
V_36 ) ;
V_69 = 1 ;
goto V_98;
}
}
}
if ( V_46 == NULL ) {
V_46 = F_17 ( V_3 , V_25 ,
V_189 ) ;
if ( V_46 == NULL )
F_18 () ;
}
if ( V_46 && ! F_59 ( NULL , V_46 ) ) {
F_5 ( V_97 ,
L_39 ) ;
goto V_98;
}
if ( V_46 == NULL )
V_46 = L_40 ;
if ( V_47 == NULL ) {
V_47 = F_17 ( V_3 , V_25 , V_190 ) ;
if ( V_47 == NULL )
F_18 () ;
}
if ( V_47 && ! F_59 ( NULL , V_47 ) ) {
F_5 ( V_97 ,
L_41 ) ;
goto V_98;
}
if ( V_83 == 0 ) {
if ( ! F_60 ( V_3 , V_25 , V_191 , & V_83 ) )
V_83 = 0 ;
}
if ( ! V_47 && ( V_83 == 0 ) ) {
F_5 ( V_97 ,
L_42 ) ;
goto V_98;
}
if ( ( V_6 = F_61 ( V_43 , V_55 , NULL ) ) == NULL ) {
F_5 ( V_97 , L_43 ) ;
goto V_98;
}
if ( V_72 ) {
if ( F_62 ( V_6 ) )
F_5 ( V_97 , L_44 ) ;
else {
if ( ( V_49 = F_63 ( V_6 ) ) == NULL )
goto V_98;
F_5 ( V_97 , L_45 , V_49 ) ;
F_64 ( V_49 ) ;
}
}
if ( ( V_16 = F_65 ( V_3 , V_27 ) ) == NULL ) {
F_5 ( V_97 , L_46 , V_27 ) ;
goto V_98;
}
if ( ( V_20 = F_66 () ) == NULL ) {
F_5 ( V_97 , L_47 ) ;
goto V_98;
}
if ( V_34 != NULL ) {
V_57 ++ ;
V_76 = F_67 ( & V_90 , V_34 , V_7 , V_88 , V_22 , V_18 ,
V_16 , V_13 , V_6 , V_44 , V_84 , V_66 ,
V_70 , V_46 , V_47 , V_83 , V_36 ,
V_3 , V_72 , V_87 , V_86 , V_60 ,
V_62 ) ;
if ( V_76 < 0 )
goto V_98;
if ( V_76 > 0 ) {
V_58 ++ ;
F_5 ( V_97 , L_48 ) ;
if ( ! F_68 ( V_6 , 1 ) )
goto V_98;
if ( ! F_69 ( V_20 , V_90 ) ) {
F_5 ( V_97 , L_47 ) ;
goto V_98;
}
if ( V_40 ) {
V_68 = 1 ;
V_59 = 1 ;
}
}
}
if ( V_35 != NULL ) {
V_57 ++ ;
V_76 = F_70 ( & V_90 , V_35 , V_7 , V_88 , V_22 , V_18 ,
V_16 ,
V_13 , V_6 , V_44 , V_84 , V_66 , V_70 ,
V_46 , V_47 , V_83 , V_59 , V_36 ,
V_3 , V_72 , V_87 , V_86 , V_60 ,
V_62 ) ;
if ( V_76 < 0 )
goto V_98;
if ( V_76 > 0 ) {
V_58 ++ ;
F_5 ( V_97 , L_48 ) ;
if ( ! F_68 ( V_6 , 1 ) )
goto V_98;
if ( ! F_69 ( V_20 , V_90 ) ) {
F_5 ( V_97 , L_47 ) ;
goto V_98;
}
}
}
if ( V_33 != NULL ) {
V_57 ++ ;
V_76 = F_71 ( & V_90 , V_33 , V_7 , V_89 , V_22 , V_18 , V_16 , V_13 ,
V_6 , V_44 , V_84 , V_66 , V_70 , V_46 ,
V_47 , V_83 , V_59 , V_36 , V_3 , V_72 ,
V_87 , V_86 , V_60 , V_62 , V_79 ) ;
if ( V_76 < 0 )
goto V_98;
if ( V_76 > 0 ) {
V_58 ++ ;
F_5 ( V_97 , L_48 ) ;
if ( ! F_68 ( V_6 , 1 ) )
goto V_98;
if ( ! F_69 ( V_20 , V_90 ) ) {
F_5 ( V_97 , L_47 ) ;
goto V_98;
}
}
}
for ( V_75 = 0 ; V_75 < V_1 ; V_75 ++ ) {
V_57 ++ ;
V_76 = F_71 ( & V_90 , V_2 [ V_75 ] , V_7 , V_89 , V_22 , V_18 , V_16 , V_13 ,
V_6 , V_44 , V_84 , V_66 , V_70 , V_46 ,
V_47 , V_83 , V_59 , V_36 , V_3 , V_72 ,
V_87 , V_86 , V_60 , V_62 , V_79 ) ;
if ( V_76 < 0 )
goto V_98;
if ( V_76 > 0 ) {
V_58 ++ ;
F_5 ( V_97 , L_48 ) ;
if ( ! F_68 ( V_6 , 1 ) )
goto V_98;
if ( ! F_69 ( V_20 , V_90 ) ) {
F_5 ( V_97 , L_47 ) ;
goto V_98;
}
}
}
if ( F_72 ( V_20 ) > 0 ) {
if ( ! V_59 ) {
F_5 ( V_97 ,
L_49 ,
V_58 , V_57 ) ;
( void ) F_73 ( V_97 ) ;
V_51 [ 0 ] [ 0 ] = '\0' ;
if ( ! fgets ( V_51 [ 0 ] , 10 , V_192 ) ) {
F_5 ( V_97 ,
L_50 ) ;
V_69 = 0 ;
goto V_98;
}
if ( ( V_51 [ 0 ] [ 0 ] != 'y' ) && ( V_51 [ 0 ] [ 0 ] != 'Y' ) ) {
F_5 ( V_97 , L_51 ) ;
V_69 = 0 ;
goto V_98;
}
}
F_5 ( V_97 , L_52 ,
F_72 ( V_20 ) ) ;
if ( ! F_74 ( V_43 , L_28 , V_6 , NULL ) )
goto V_98;
if ( ! F_47 ( V_48 , L_28 , V_13 ) )
goto V_98;
}
if ( V_72 )
F_5 ( V_97 , L_53 ) ;
for ( V_75 = 0 ; V_75 < F_72 ( V_20 ) ; V_75 ++ ) {
T_5 * V_193 = NULL ;
T_6 * V_194 = F_75 ( V_90 ) ;
int V_195 ;
char * V_196 ;
V_90 = F_76 ( V_20 , V_75 ) ;
V_76 = F_77 ( V_194 ) ;
V_54 = ( const char * ) F_78 ( V_194 ) ;
if ( strlen ( V_39 ) >= ( V_197 ) ( V_76 ? V_52 - V_76 * 2 - 6 : V_52 - 8 ) ) {
F_5 ( V_97 , L_54 ) ;
goto V_98;
}
strcpy ( V_51 [ 2 ] , V_39 ) ;
#ifndef F_38
F_79 ( V_51 [ 2 ] , L_55 , sizeof( V_51 [ 2 ] ) ) ;
#endif
V_196 = ( char * ) & ( V_51 [ 2 ] [ strlen ( V_51 [ 2 ] ) ] ) ;
if ( V_76 > 0 ) {
for ( V_195 = 0 ; V_195 < V_76 ; V_195 ++ ) {
if ( V_196 >= & ( V_51 [ 2 ] [ sizeof( V_51 [ 2 ] ) ] ) )
break;
F_80 ( V_196 ,
& V_51 [ 2 ] [ 0 ] + sizeof( V_51 [ 2 ] ) - V_196 ,
L_56 , ( unsigned char ) * ( V_54 ++ ) ) ;
V_196 += 2 ;
}
} else {
* ( V_196 ++ ) = '0' ;
* ( V_196 ++ ) = '0' ;
}
* ( V_196 ++ ) = '.' ;
* ( V_196 ++ ) = 'p' ;
* ( V_196 ++ ) = 'e' ;
* ( V_196 ++ ) = 'm' ;
* V_196 = '\0' ;
if ( V_72 )
F_5 ( V_97 , L_57 , V_51 [ 2 ] ) ;
V_193 = F_19 ( V_51 [ 2 ] , L_58 ) ;
if ( V_193 == NULL ) {
perror ( V_51 [ 2 ] ) ;
goto V_98;
}
F_81 ( V_193 , V_90 , 0 , V_67 ) ;
F_81 ( V_10 , V_90 , V_68 , V_67 ) ;
F_82 ( V_193 ) ;
}
if ( F_72 ( V_20 ) ) {
if ( ! F_83 ( V_43 , L_28 , L_29 ) )
goto V_98;
if ( ! F_48 ( V_48 , L_28 , L_29 ) )
goto V_98;
F_5 ( V_97 , L_59 ) ;
}
}
if ( V_73 ) {
int V_198 = 0 ;
if ( ! V_30 ) {
V_30 = F_17 ( V_3 , V_25 , V_199 ) ;
if ( ! V_30 )
F_18 () ;
}
if ( V_30 ) {
T_14 V_188 ;
F_56 ( & V_188 ) ;
F_57 ( & V_188 , V_3 ) ;
if ( ! F_58 ( V_3 , & V_188 , V_30 , NULL ) ) {
F_5 ( V_97 ,
L_60 ,
V_30 ) ;
V_69 = 1 ;
goto V_98;
}
}
if ( ( V_31 = F_17 ( V_3 , V_25 , V_200 ) )
!= NULL )
if ( ( V_5 = F_61 ( V_31 , 0 , NULL ) ) == NULL ) {
F_5 ( V_97 , L_61 ) ;
goto V_98;
}
if ( ! V_80 && ! V_81 && ! V_82 ) {
if ( ! F_60 ( V_3 , V_25 ,
V_201 , & V_80 ) )
V_80 = 0 ;
if ( ! F_60 ( V_3 , V_25 ,
V_202 , & V_81 ) )
V_81 = 0 ;
F_18 () ;
}
if ( ( V_80 == 0 ) && ( V_81 == 0 ) && ( V_82 == 0 ) ) {
F_5 ( V_97 ,
L_62 ) ;
goto V_98;
}
if ( V_72 )
F_5 ( V_97 , L_63 ) ;
if ( ( V_21 = F_84 () ) == NULL )
goto V_98;
if ( ! F_85 ( V_21 , F_86 ( V_88 ) ) )
goto V_98;
V_12 = F_87 () ;
if ( V_12 == NULL )
goto V_98;
F_88 ( V_12 , 0 ) ;
F_89 ( V_21 , V_12 ) ;
if ( ! F_90 ( V_12 , V_80 , V_81 * 60 * 60 + V_82 ,
NULL ) ) {
F_51 ( V_97 , L_64 ) ;
goto V_98;
}
F_91 ( V_21 , V_12 ) ;
F_92 ( V_12 ) ;
for ( V_75 = 0 ; V_75 < F_40 ( V_13 -> V_13 -> V_172 ) ; V_75 ++ ) {
V_53 = F_41 ( V_13 -> V_13 -> V_172 , V_75 ) ;
if ( V_53 [ V_173 ] [ 0 ] == V_174 ) {
if ( ( V_91 = F_93 () ) == NULL )
goto V_98;
V_76 = F_42 ( V_91 , V_53 [ V_175 ] ) ;
if ( ! V_76 )
goto V_98;
if ( V_76 == 2 )
V_198 = 1 ;
if ( ! F_94 ( & V_6 , V_53 [ V_177 ] ) )
goto V_98;
V_11 = F_95 ( V_6 , NULL ) ;
F_96 ( V_6 ) ;
V_6 = NULL ;
if ( ! V_11 )
goto V_98;
F_97 ( V_91 , V_11 ) ;
F_98 ( V_11 ) ;
F_99 ( V_21 , V_91 ) ;
}
}
F_100 ( V_21 ) ;
if ( V_72 )
F_5 ( V_97 , L_65 ) ;
if ( V_30 || V_31 != NULL ) {
T_14 V_203 ;
F_101 ( & V_203 , V_88 , NULL , NULL , V_21 , 0 ) ;
F_57 ( & V_203 , V_3 ) ;
if ( V_30 )
if ( ! F_102 ( V_3 , & V_203 , V_30 , V_21 ) )
goto V_98;
if ( V_31 != NULL ) {
V_11 = F_95 ( V_5 , NULL ) ;
if ( ! V_11 )
goto V_98;
F_103 ( V_21 , V_204 , V_11 , 0 , 0 ) ;
F_98 ( V_11 ) ;
V_198 = 1 ;
if ( ! F_68 ( V_5 , 1 ) )
goto V_98;
}
}
if ( V_30 || V_198 ) {
if ( ! F_104 ( V_21 , 1 ) )
goto V_98;
}
if ( V_31 != NULL )
if ( ! F_74 ( V_31 , L_28 , V_5 , NULL ) )
goto V_98;
F_96 ( V_5 ) ;
V_5 = NULL ;
if ( ! F_105 ( V_21 , V_7 , V_22 , V_18 ) )
goto V_98;
F_106 ( V_10 , V_21 ) ;
if ( V_31 != NULL )
if ( ! F_83 ( V_31 , L_28 , L_29 ) )
goto V_98;
}
if ( V_74 ) {
if ( V_33 == NULL ) {
F_5 ( V_97 , L_66 ) ;
goto V_98;
} else {
V_19 * V_205 ;
V_205 = F_33 ( V_33 , V_65 , V_33 ) ;
if ( V_205 == NULL )
goto V_98;
if ( V_74 == 2 )
V_77 = - 1 ;
V_76 = F_107 ( V_205 , V_13 , V_77 , V_41 ) ;
if ( V_76 <= 0 )
goto V_98;
F_108 ( V_205 ) ;
if ( ! F_47 ( V_48 , L_28 , V_13 ) )
goto V_98;
if ( ! F_48 ( V_48 , L_28 , L_29 ) )
goto V_98;
F_5 ( V_97 , L_59 ) ;
}
}
V_69 = 0 ;
V_98:
F_82 ( V_10 ) ;
F_82 ( V_9 ) ;
F_82 ( V_8 ) ;
F_109 ( V_20 , F_108 ) ;
if ( V_69 )
F_23 ( V_97 ) ;
F_110 ( V_50 ) ;
if ( V_56 )
F_64 ( V_32 ) ;
F_96 ( V_6 ) ;
F_96 ( V_5 ) ;
F_111 ( V_13 ) ;
F_112 ( V_18 ) ;
F_113 ( V_7 ) ;
F_108 ( V_88 ) ;
F_114 ( V_21 ) ;
F_115 ( V_3 ) ;
F_115 ( V_179 ) ;
return ( V_69 ) ;
}
static char * F_16 ( const T_1 * V_3 , const char * V_25 , const char * V_206 )
{
char * V_207 = F_17 ( V_3 , V_25 , V_206 ) ;
if ( V_207 == NULL )
F_5 ( V_97 , L_67 , V_25 , V_206 ) ;
return V_207 ;
}
static void F_81 ( T_5 * V_208 , V_19 * V_90 , int V_68 ,
int V_67 )
{
if ( V_68 ) {
( void ) F_116 ( V_208 , V_90 ) ;
return;
}
if ( ! V_67 )
F_117 ( V_208 , V_90 ) ;
F_118 ( V_208 , V_90 ) ;
}
static int F_43 ( const char * V_209 )
{
return F_59 ( NULL , V_209 ) ;
}
static int F_107 ( V_19 * V_88 , T_8 * V_13 , int type , char * V_210 )
{
const T_7 * V_211 = NULL ;
char * V_212 [ V_213 ] , * * V_214 , * * V_215 ;
char * V_216 = NULL ;
T_3 * V_217 = NULL ;
int V_218 = - 1 , V_75 ;
for ( V_75 = 0 ; V_75 < V_213 ; V_75 ++ )
V_212 [ V_75 ] = NULL ;
V_212 [ V_219 ] = F_119 ( F_86 ( V_88 ) , NULL , 0 ) ;
V_217 = F_120 ( F_75 ( V_88 ) , NULL ) ;
if ( ! V_217 )
goto V_98;
if ( F_62 ( V_217 ) )
V_212 [ V_177 ] = F_121 ( L_68 ) ;
else
V_212 [ V_177 ] = F_63 ( V_217 ) ;
F_96 ( V_217 ) ;
if ( ( V_212 [ V_219 ] == NULL ) || ( V_212 [ V_177 ] == NULL ) ) {
F_5 ( V_97 , L_47 ) ;
goto V_98;
}
V_214 = F_122 ( V_13 -> V_13 , V_177 , V_212 ) ;
if ( V_214 == NULL ) {
F_5 ( V_97 ,
L_69 ,
V_212 [ V_177 ] , V_212 [ V_219 ] ) ;
V_212 [ V_173 ] = F_121 ( L_70 ) ;
V_211 = F_123 ( V_88 ) ;
V_212 [ V_176 ] = F_124 ( V_211 -> V_220 + 1 , L_71 ) ;
memcpy ( V_212 [ V_176 ] , V_211 -> V_172 , V_211 -> V_220 ) ;
V_212 [ V_176 ] [ V_211 -> V_220 ] = '\0' ;
V_212 [ V_175 ] = NULL ;
V_212 [ V_221 ] = F_121 ( L_72 ) ;
V_215 = F_124 ( sizeof( * V_215 ) * ( V_213 + 1 ) , L_73 ) ;
for ( V_75 = 0 ; V_75 < V_213 ; V_75 ++ ) {
V_215 [ V_75 ] = V_212 [ V_75 ] ;
V_212 [ V_75 ] = NULL ;
}
V_215 [ V_213 ] = NULL ;
if ( ! F_125 ( V_13 -> V_13 , V_215 ) ) {
F_5 ( V_97 , L_74 ) ;
F_5 ( V_97 , L_75 , V_13 -> V_13 -> error ) ;
goto V_98;
}
if ( type == - 1 )
V_218 = 1 ;
else
V_218 = F_107 ( V_88 , V_13 , type , V_210 ) ;
goto V_98;
} else if ( F_126 ( V_212 , V_214 ) ) {
F_5 ( V_97 , L_76 , V_212 [ V_219 ] ) ;
goto V_98;
} else if ( type == - 1 ) {
F_5 ( V_97 , L_77 ,
V_212 [ V_177 ] ) ;
goto V_98;
} else if ( V_214 [ V_173 ] [ 0 ] == 'R' ) {
F_5 ( V_97 , L_78 ,
V_212 [ V_177 ] ) ;
goto V_98;
} else {
F_5 ( V_97 , L_79 , V_214 [ V_177 ] ) ;
V_216 = F_127 ( type , V_210 ) ;
if ( ! V_216 ) {
F_5 ( V_97 , L_80 ) ;
goto V_98;
}
V_214 [ V_173 ] [ 0 ] = 'R' ;
V_214 [ V_173 ] [ 1 ] = '\0' ;
V_214 [ V_175 ] = V_216 ;
}
V_218 = 1 ;
V_98:
for ( V_75 = 0 ; V_75 < V_213 ; V_75 ++ ) {
F_64 ( V_212 [ V_75 ] ) ;
}
return ( V_218 ) ;
}
static int F_29 ( const char * V_6 , T_8 * V_13 )
{
char * V_212 [ V_213 ] , * * V_214 ;
int V_218 = - 1 , V_75 ;
V_197 V_222 = strlen ( V_6 ) ;
for ( V_75 = 0 ; V_75 < V_213 ; V_75 ++ )
V_212 [ V_75 ] = NULL ;
V_212 [ V_177 ] = F_124 ( V_222 + 2 , L_81 ) ;
if ( V_222 % 2 ) {
;
V_212 [ V_177 ] [ 0 ] = '0' ;
memcpy ( V_212 [ V_177 ] + 1 , V_6 , V_222 ) ;
V_212 [ V_177 ] [ V_222 + 1 ] = '\0' ;
} else {
memcpy ( V_212 [ V_177 ] , V_6 , V_222 ) ;
V_212 [ V_177 ] [ V_222 ] = '\0' ;
}
for ( V_75 = 0 ; V_212 [ V_177 ] [ V_75 ] != '\0' ; V_75 ++ )
V_212 [ V_177 ] [ V_75 ] = toupper ( ( unsigned char ) V_212 [ V_177 ] [ V_75 ] ) ;
V_218 = 1 ;
V_214 = F_122 ( V_13 -> V_13 , V_177 , V_212 ) ;
if ( V_214 == NULL ) {
F_5 ( V_97 , L_82 , V_212 [ V_177 ] ) ;
V_218 = - 1 ;
goto V_98;
} else if ( V_214 [ V_173 ] [ 0 ] == 'V' ) {
F_5 ( V_97 , L_83 ,
V_212 [ V_177 ] , V_214 [ V_173 ] [ 0 ] ) ;
goto V_98;
} else if ( V_214 [ V_173 ] [ 0 ] == 'R' ) {
F_5 ( V_97 , L_84 ,
V_212 [ V_177 ] , V_214 [ V_173 ] [ 0 ] ) ;
goto V_98;
} else if ( V_214 [ V_173 ] [ 0 ] == 'E' ) {
F_5 ( V_97 , L_85 ,
V_212 [ V_177 ] , V_214 [ V_173 ] [ 0 ] ) ;
goto V_98;
} else if ( V_214 [ V_173 ] [ 0 ] == 'S' ) {
F_5 ( V_97 , L_86 ,
V_212 [ V_177 ] , V_214 [ V_173 ] [ 0 ] ) ;
goto V_98;
} else {
F_5 ( V_97 , L_87 ,
V_212 [ V_177 ] , V_214 [ V_173 ] [ 0 ] ) ;
V_218 = - 1 ;
}
V_98:
for ( V_75 = 0 ; V_75 < V_213 ; V_75 ++ ) {
F_64 ( V_212 [ V_75 ] ) ;
}
return ( V_218 ) ;
}
static int F_46 ( T_8 * V_13 )
{
T_15 * V_223 = NULL ;
int V_75 , V_224 = 0 ;
int V_225 , V_226 ;
char * * V_214 , * V_227 ;
V_223 = F_128 () ;
if ( V_223 == NULL )
return - 1 ;
V_223 = F_88 ( V_223 , 0 ) ;
V_227 = F_124 ( V_223 -> V_220 + 1 , L_88 ) ;
memcpy ( V_227 , V_223 -> V_172 , V_223 -> V_220 ) ;
V_227 [ V_223 -> V_220 ] = '\0' ;
if ( strncmp ( V_227 , L_89 , 2 ) <= 0 )
V_226 = 1 ;
else
V_226 = 0 ;
for ( V_75 = 0 ; V_75 < F_40 ( V_13 -> V_13 -> V_172 ) ; V_75 ++ ) {
V_214 = F_41 ( V_13 -> V_13 -> V_172 , V_75 ) ;
if ( V_214 [ V_173 ] [ 0 ] == 'V' ) {
if ( strncmp ( V_214 [ V_176 ] , L_89 , 2 ) <= 0 )
V_225 = 1 ;
else
V_225 = 0 ;
if ( V_225 == V_226 ) {
if ( strcmp ( V_214 [ V_176 ] , V_227 ) <= 0 ) {
V_214 [ V_173 ] [ 0 ] = 'E' ;
V_214 [ V_173 ] [ 1 ] = '\0' ;
V_224 ++ ;
F_5 ( V_97 , L_90 , V_214 [ V_177 ] ) ;
}
} else if ( V_225 < V_226 ) {
V_214 [ V_173 ] [ 0 ] = 'E' ;
V_214 [ V_173 ] [ 1 ] = '\0' ;
V_224 ++ ;
F_5 ( V_97 , L_90 , V_214 [ V_177 ] ) ;
}
}
}
F_129 ( V_223 ) ;
F_64 ( V_227 ) ;
return ( V_224 ) ;
}
char * F_127 ( int V_77 , char * V_41 )
{
char * V_209 ;
const char * V_228 = NULL ;
const char * V_229 = NULL ;
T_16 * V_230 ;
T_15 * V_231 = NULL ;
int V_75 ;
switch ( V_77 ) {
case V_78 :
break;
case V_147 :
for ( V_75 = 0 ; V_75 < 8 ; V_75 ++ ) {
if ( strcasecmp ( V_41 , V_232 [ V_75 ] ) == 0 ) {
V_229 = V_232 [ V_75 ] ;
break;
}
}
if ( V_229 == NULL ) {
F_5 ( V_97 , L_91 , V_41 ) ;
return NULL ;
}
break;
case V_149 :
V_230 = F_130 ( V_41 , 0 ) ;
F_131 ( V_230 ) ;
if ( V_230 == NULL ) {
F_5 ( V_97 , L_92 , V_41 ) ;
return NULL ;
}
V_229 = L_93 ;
V_228 = V_41 ;
break;
case V_151 :
case V_153 :
if ( ! F_132 ( NULL , V_41 ) ) {
F_5 ( V_97 ,
L_94 ,
V_41 ) ;
return NULL ;
}
V_228 = V_41 ;
if ( V_77 == V_151 )
V_229 = L_95 ;
else
V_229 = L_96 ;
break;
}
V_231 = F_88 ( NULL , 0 ) ;
if ( ! V_231 )
return NULL ;
V_75 = V_231 -> V_220 + 1 ;
if ( V_229 )
V_75 += strlen ( V_229 ) + 1 ;
if ( V_228 )
V_75 += strlen ( V_228 ) + 1 ;
V_209 = F_124 ( V_75 , L_97 ) ;
F_133 ( V_209 , ( char * ) V_231 -> V_172 , V_75 ) ;
if ( V_229 ) {
F_79 ( V_209 , L_98 , V_75 ) ;
F_79 ( V_209 , V_229 , V_75 ) ;
}
if ( V_228 ) {
F_79 ( V_209 , L_98 , V_75 ) ;
F_79 ( V_209 , V_228 , V_75 ) ;
}
F_129 ( V_231 ) ;
return V_209 ;
}
int F_42 ( T_12 * V_233 , const char * V_209 )
{
char * V_234 = NULL ;
int V_235 = - 1 ;
int V_75 , V_69 = 0 ;
T_16 * V_236 = NULL ;
T_17 * V_237 = NULL ;
T_18 * V_238 = NULL ;
T_7 * V_239 = NULL ;
V_75 = F_134 ( & V_239 , & V_235 , & V_236 , & V_237 , V_209 ) ;
if ( V_75 == 0 )
goto V_98;
if ( V_233 && ! F_135 ( V_233 , V_239 ) )
goto V_98;
if ( V_233 && ( V_235 != V_240 ) ) {
V_238 = F_136 () ;
if ( V_238 == NULL || ! F_137 ( V_238 , V_235 ) )
goto V_98;
if ( ! F_138 ( V_233 , V_241 , V_238 , 0 , 0 ) )
goto V_98;
}
if ( V_233 && V_237 ) {
if ( ! F_138
( V_233 , V_242 , V_237 , 0 , 0 ) )
goto V_98;
}
if ( V_233 && V_236 ) {
if ( ! F_138
( V_233 , V_243 , V_236 , 0 , 0 ) )
goto V_98;
}
if ( V_235 != V_240 )
V_69 = 2 ;
else
V_69 = 1 ;
V_98:
F_64 ( V_234 ) ;
F_131 ( V_236 ) ;
F_139 ( V_237 ) ;
F_140 ( V_238 ) ;
F_92 ( V_239 ) ;
return V_69 ;
}
static int F_141 ( const T_16 * V_244 , const T_19 * V_209 )
{
char V_51 [ 25 ] , * V_245 ;
const char * V_54 ;
int V_76 ;
V_76 = F_142 ( V_97 , V_244 ) ;
V_245 = V_51 ;
for ( V_76 = 22 - V_76 ; V_76 > 0 ; V_76 -- )
* ( V_245 ++ ) = ' ' ;
* ( V_245 ++ ) = ':' ;
* ( V_245 ++ ) = '\0' ;
F_51 ( V_97 , V_51 ) ;
if ( V_209 -> type == V_246 )
F_5 ( V_97 , L_99 ) ;
else if ( V_209 -> type == V_247 )
F_5 ( V_97 , L_100 ) ;
else if ( V_209 -> type == V_248 )
F_5 ( V_97 , L_101 ) ;
else if ( V_209 -> type == V_249 )
F_5 ( V_97 , L_102 ) ;
else
F_5 ( V_97 , L_103 , V_209 -> type ) ;
V_54 = ( const char * ) V_209 -> V_172 ;
for ( V_76 = V_209 -> V_220 ; V_76 > 0 ; V_76 -- ) {
if ( ( * V_54 >= ' ' ) && ( * V_54 <= '~' ) )
F_5 ( V_97 , L_104 , * V_54 ) ;
else if ( * V_54 & 0x80 )
F_5 ( V_97 , L_105 , * V_54 ) ;
else if ( ( unsigned char ) * V_54 == 0xf7 )
F_5 ( V_97 , L_106 ) ;
else
F_5 ( V_97 , L_107 , * V_54 + '@' ) ;
V_54 ++ ;
}
F_5 ( V_97 , L_108 ) ;
return 1 ;
}
int F_134 ( T_7 * * V_250 , int * V_251 , T_16 * * V_252 ,
T_17 * * V_253 , const char * V_209 )
{
char * V_234 ;
char * V_254 , * V_255 = NULL , * V_256 = NULL , * V_54 ;
int V_235 = - 1 ;
int V_69 = 0 ;
unsigned int V_75 ;
T_16 * V_236 = NULL ;
T_17 * V_237 = NULL ;
V_234 = F_121 ( V_209 ) ;
if ( ! V_234 ) {
F_5 ( V_97 , L_109 ) ;
goto V_98;
}
V_54 = strchr ( V_234 , ',' ) ;
V_254 = V_234 ;
if ( V_54 ) {
* V_54 = '\0' ;
V_54 ++ ;
V_255 = V_54 ;
V_54 = strchr ( V_54 , ',' ) ;
if ( V_54 ) {
* V_54 = '\0' ;
V_256 = V_54 + 1 ;
}
}
if ( V_250 ) {
* V_250 = F_128 () ;
if ( * V_250 == NULL ) {
F_5 ( V_97 , L_109 ) ;
goto V_98;
}
if ( ! F_143 ( * V_250 , V_254 ) ) {
F_5 ( V_97 , L_110 , V_254 ) ;
goto V_98;
}
}
if ( V_255 ) {
for ( V_75 = 0 ; V_75 < V_257 ; V_75 ++ ) {
if ( strcasecmp ( V_255 , V_232 [ V_75 ] ) == 0 ) {
V_235 = V_75 ;
break;
}
}
if ( V_235 == V_240 ) {
F_5 ( V_97 , L_111 , V_255 ) ;
goto V_98;
}
if ( V_235 == 7 )
V_235 = V_258 ;
else if ( V_235 == 8 ) {
if ( ! V_256 ) {
F_5 ( V_97 , L_112 ) ;
goto V_98;
}
V_235 = V_259 ;
V_236 = F_130 ( V_256 , 0 ) ;
if ( ! V_236 ) {
F_5 ( V_97 , L_113 ,
V_256 ) ;
goto V_98;
}
if ( V_252 )
* V_252 = V_236 ;
else
F_131 ( V_236 ) ;
} else if ( ( V_235 == 9 ) || ( V_235 == 10 ) ) {
if ( ! V_256 ) {
F_5 ( V_97 , L_114 ) ;
goto V_98;
}
V_237 = F_144 () ;
if ( V_237 == NULL ) {
F_5 ( V_97 , L_109 ) ;
goto V_98;
}
if ( ! F_132 ( V_237 , V_256 ) ) {
F_5 ( V_97 , L_115 , V_256 ) ;
goto V_98;
}
if ( V_235 == 9 )
V_235 = V_260 ;
else
V_235 = V_261 ;
}
}
if ( V_251 )
* V_251 = V_235 ;
if ( V_253 ) {
* V_253 = V_237 ;
V_237 = NULL ;
}
V_69 = 1 ;
V_98:
F_64 ( V_234 ) ;
F_139 ( V_237 ) ;
return V_69 ;
}
