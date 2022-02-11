int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL ;
T_3 * V_5 = NULL ;
T_4 * V_6 = NULL ;
T_5 * V_7 = NULL , * V_8 = NULL , * V_9 = NULL ;
F_2 ( T_2 ) * V_10 = NULL , * V_11 = NULL ;
F_2 ( V_12 ) * V_13 = NULL ;
T_6 * V_14 = NULL , * V_15 = NULL ;
T_7 * V_16 = NULL , * V_17 = NULL ;
T_8 * V_18 = NULL ;
const T_9 * V_19 = NULL ;
char * V_20 = NULL , * V_21 = NULL , * V_22 = NULL , * V_23 = NULL ;
char * V_24 = NULL , * V_25 = NULL , * V_26 = NULL ;
char * V_27 = NULL , * V_28 = NULL , * V_29 = NULL , * V_30 = NULL ;
char * V_31 = NULL , * V_32 = NULL , * V_33 = NULL , * V_34 = NULL ;
char V_35 [ 256 ] , * V_36 ;
int V_37 = 0 , V_38 = V_39 , V_40 = 0 , V_41 = 0 , V_42 = 0 ;
int V_43 = 0 , V_44 = V_45 , V_46 = V_45 ;
int V_47 = 0 , V_48 = 0 , V_49 = 0 , V_50 = 0 ;
int V_51 = V_45 , V_52 = V_45 , V_53 = V_45 ;
int V_54 = 0 , V_55 = 0 , V_56 = 0 , V_57 = 0 ;
int V_58 = 0 , V_59 = 0 , V_60 = 0 , V_61 = 0 , V_62 = 0 ;
int V_63 = 0 , V_64 = 0 , V_65 = 0 , V_66 = 0 , V_67 = 0 ;
int V_68 = 1 , V_69 , V_70 = 0 , V_71 = 0 , V_72 = 0 , V_73 = 0 ;
int V_74 = 0 , V_75 = 0 , V_76 = 0 , V_77 = 0 , V_78 = 0 ;
int V_79 = 0 ;
T_10 V_80 = 0 ;
unsigned long V_81 = 0 , V_82 = 0 ;
char V_83 = 0 ;
T_11 V_84 ;
T_12 * V_85 = NULL ;
#ifndef F_3
int V_86 = 0 , V_87 = 0 ;
#endif
V_18 = F_4 () ;
if ( V_18 == NULL )
goto V_88;
F_5 ( V_18 , V_89 ) ;
V_36 = F_6 ( V_1 , V_2 , V_90 ) ;
while ( ( V_84 = F_7 () ) != V_91 ) {
switch ( V_84 ) {
case V_91 :
case V_92 :
V_93:
F_8 ( V_94 , L_1 , V_36 ) ;
goto V_88;
case V_95 :
F_9 ( V_90 ) ;
V_68 = 0 ;
goto V_88;
case V_96 :
if ( ! F_10 ( F_11 () , V_97 , & V_51 ) )
goto V_93;
break;
case V_98 :
V_31 = F_11 () ;
break;
case V_99 :
if ( ! F_10 ( F_11 () , V_97 , & V_52 ) )
goto V_93;
break;
case V_100 :
if ( ! F_10 ( F_11 () , V_101 , & V_53 ) )
goto V_93;
break;
case V_102 :
if ( ! F_10 ( F_11 () , V_101 , & V_44 ) )
goto V_93;
break;
case V_103 :
if ( ! F_10 ( F_11 () , V_97 , & V_46 ) )
goto V_93;
break;
case V_104 :
V_32 = F_11 () ;
break;
case V_105 :
V_48 = V_49 = 1 ;
break;
case V_106 :
if ( ! V_13 )
V_13 = F_12 () ;
if ( ! V_13 || ! F_13 ( V_13 , F_11 () ) )
goto V_93;
break;
case V_107 :
V_38 = atoi ( F_11 () ) ;
break;
case V_108 :
V_30 = F_11 () ;
break;
case V_109 :
V_28 = F_11 () ;
break;
case V_110 :
V_27 = F_11 () ;
break;
case V_111 :
V_33 = F_11 () ;
V_59 = ++ V_70 ;
V_49 = 1 ;
break;
case V_112 :
V_34 = F_11 () ;
V_60 = ++ V_70 ;
V_49 = 1 ;
break;
case V_113 :
V_20 = F_11 () ;
break;
case V_114 :
V_21 = F_11 () ;
break;
case V_115 :
if ( V_3 != NULL ) {
F_8 ( V_94 , L_2 ) ;
goto V_93;
}
if ( ( V_3 = F_14 ( NULL , F_11 () ) ) == NULL )
goto V_93;
break;
case V_116 :
V_22 = F_11 () ;
break;
case V_117 :
if ( ( V_4 = F_15 ( F_11 () , 0 ) ) == NULL ) {
F_8 ( V_94 ,
L_3 ,
V_36 , F_11 () ) ;
goto V_93;
}
if ( V_10 == NULL && ( V_10 = F_16 () ) == NULL )
goto V_88;
F_17 ( V_10 , V_4 ) ;
V_4 = NULL ;
V_64 = 1 ;
break;
case V_118 :
if ( ( V_4 = F_15 ( F_11 () , 0 ) ) == NULL ) {
F_8 ( V_94 ,
L_4 ,
V_36 , F_11 () ) ;
goto V_93;
}
if ( V_11 == NULL
&& ( V_11 = F_16 () ) == NULL )
goto V_88;
F_17 ( V_11 , V_4 ) ;
V_4 = NULL ;
V_64 = 1 ;
break;
case V_119 :
V_23 = F_11 () ;
V_64 = 1 ;
break;
case V_120 :
if ( ! F_18 ( & V_82 , F_11 () ) )
goto V_93;
break;
case V_121 :
V_83 = 1 ;
if ( ! F_19 ( & V_81 , F_11 () ) )
goto V_93;
break;
case V_122 :
V_85 = F_20 ( F_11 () , 0 ) ;
break;
case V_123 :
V_43 = ++ V_70 ;
break;
case V_124 :
V_62 = ++ V_70 ;
break;
case V_125 :
V_63 = ++ V_70 ;
break;
case V_126 :
V_75 = ++ V_70 ;
break;
case V_127 :
V_54 = ++ V_70 ;
break;
case V_128 :
V_40 = ++ V_70 ;
break;
case V_129 :
V_41 = ++ V_70 ;
break;
case V_130 :
V_37 = ++ V_70 ;
break;
case V_131 :
V_74 = ++ V_70 ;
break;
case V_132 :
V_76 = ++ V_70 ;
break;
case V_133 :
V_77 = ++ V_70 ;
break;
case V_134 :
V_47 = ++ V_70 ;
break;
case V_135 :
V_55 = ++ V_70 ;
break;
case V_136 :
V_56 = ++ V_70 ;
break;
case V_137 :
V_42 = ++ V_70 ;
break;
case V_138 :
V_78 = ++ V_70 ;
break;
case V_139 :
V_79 = ++ V_70 ;
break;
case V_140 :
V_58 = ++ V_70 ;
break;
case V_141 :
V_73 = 1 ;
break;
case V_142 :
V_64 = 1 ;
break;
case V_143 :
V_65 = ++ V_70 ;
break;
case V_144 :
V_66 = ++ V_70 ;
break;
case V_145 :
V_67 = ++ V_70 ;
break;
case V_146 :
V_61 = ++ V_70 ;
break;
case V_147 :
V_72 = 1 ;
break;
case V_148 :
V_57 = ++ V_70 ;
break;
case V_149 :
V_71 = 1 ;
break;
#ifndef F_3
case V_150 :
V_86 = ++ V_70 ;
break;
case V_151 :
V_87 = ++ V_70 ;
break;
#else
case V_150 :
case V_151 :
break;
#endif
case V_152 :
V_78 = ++ V_70 ;
V_79 = ++ V_70 ;
break;
case V_153 :
V_50 = 1 ;
{
T_13 V_154 = 0 ;
if ( ! F_21 ( F_11 () , & V_154 ) )
goto V_93;
V_80 = ( T_10 ) V_154 ;
if ( ( T_13 ) V_80 != V_154 ) {
F_8 ( V_94 , L_5 ,
V_36 , F_11 () ) ;
goto V_93;
}
}
break;
case V_155 :
V_24 = F_11 () ;
break;
case V_156 :
V_25 = F_11 () ;
break;
case V_157 :
V_26 = F_11 () ;
break;
case V_158 :
if ( ! F_22 ( F_23 () , & V_19 ) )
goto V_93;
}
}
V_1 = F_24 () ;
V_2 = F_25 () ;
if ( V_1 != 0 ) {
F_8 ( V_94 , L_6 , V_36 , V_2 [ 0 ] ) ;
goto V_93;
}
if ( ! V_83 )
V_81 = V_159 ;
V_5 = F_26 ( V_32 , 'w' , V_52 ) ;
if ( V_5 == NULL )
goto V_88;
if ( V_49 )
F_27 ( NULL , 0 ) ;
if ( ! F_28 ( V_30 , NULL , & V_29 , NULL ) ) {
F_8 ( V_94 , L_7 ) ;
goto V_88;
}
if ( ! F_29 ( V_18 ) ) {
F_30 ( V_94 ) ;
goto V_88;
}
if ( V_22 ) {
V_9 = F_31 ( V_22 , V_53 , 0 , NULL , V_85 , L_8 ) ;
if ( V_9 == NULL )
goto V_88;
}
if ( ( V_20 == NULL ) && ( V_60 ) && ( V_44 == V_45 ) ) {
V_20 = V_34 ;
} else if ( ( V_60 ) && ( V_20 == NULL ) ) {
F_8 ( V_94 ,
L_9 ) ;
goto V_88;
}
if ( V_28 ) {
T_14 V_160 ;
if ( ( V_6 = F_32 ( V_28 ) ) == NULL )
goto V_88;
if ( ! V_27 ) {
V_27 = F_33 ( V_6 , L_10 , L_11 ) ;
if ( ! V_27 ) {
F_34 () ;
V_27 = L_10 ;
}
}
F_35 ( & V_160 ) ;
F_36 ( & V_160 , V_6 ) ;
if ( ! F_37 ( V_6 , & V_160 , V_27 , NULL ) ) {
F_8 ( V_94 ,
L_12 , V_27 ) ;
F_30 ( V_94 ) ;
goto V_88;
}
}
if ( V_48 ) {
T_5 * V_161 ;
T_3 * V_162 ;
if ( ! V_59 && ! V_60 ) {
F_8 ( V_94 , L_13 ) ;
goto V_88;
}
V_162 = F_26 ( V_31 , 'r' , V_51 ) ;
if ( V_162 == NULL )
goto V_88;
V_16 = F_38 ( V_162 , NULL , NULL , NULL ) ;
F_39 ( V_162 ) ;
if ( V_16 == NULL ) {
F_30 ( V_94 ) ;
goto V_88;
}
if ( ( V_161 = F_40 ( V_16 ) ) == NULL ) {
F_8 ( V_94 , L_14 ) ;
goto V_88;
}
V_69 = F_41 ( V_16 , V_161 ) ;
if ( V_69 < 0 ) {
F_8 ( V_94 , L_15 ) ;
F_30 ( V_94 ) ;
goto V_88;
}
if ( V_69 == 0 ) {
F_8 ( V_94 ,
L_16 ) ;
goto V_88;
} else
F_8 ( V_94 , L_17 ) ;
F_42 ( V_94 , L_18 , F_43 ( V_16 ) ,
V_81 ) ;
if ( ( V_14 = F_44 () ) == NULL )
goto V_88;
if ( V_3 == NULL ) {
V_3 = F_45 () ;
if ( V_3 == NULL || ! F_46 ( NULL , V_3 ) )
goto V_88;
if ( ! F_47 ( V_14 , V_3 ) )
goto V_88;
F_48 ( V_3 ) ;
V_3 = NULL ;
} else if ( ! F_47 ( V_14 , V_3 ) )
goto V_88;
if ( ! F_49 ( V_14 , F_43 ( V_16 ) ) )
goto V_88;
if ( ! F_50 ( V_14 , F_43 ( V_16 ) ) )
goto V_88;
if ( ! F_51 ( V_14 , NULL , NULL , V_38 ) )
goto V_88;
if ( V_9 )
F_52 ( V_14 , V_9 ) ;
else {
V_161 = F_40 ( V_16 ) ;
F_52 ( V_14 , V_161 ) ;
}
} else
V_14 = F_53 ( V_31 , V_51 , L_19 ) ;
if ( V_14 == NULL )
goto V_88;
if ( V_60 ) {
V_15 = F_53 ( V_34 , V_44 , L_20 ) ;
if ( V_15 == NULL )
goto V_88;
}
if ( ! V_58 || V_74 || V_54 ) {
F_54 ( L_21 , L_22 , L_23 ) ;
}
if ( V_23 )
F_55 ( V_14 , ( unsigned char * ) V_23 , - 1 ) ;
if ( V_65 )
F_56 ( V_14 ) ;
if ( V_66 )
F_57 ( V_14 ) ;
if ( V_10 ) {
for ( V_69 = 0 ; V_69 < F_58 ( V_10 ) ; V_69 ++ ) {
V_4 = F_59 ( V_10 , V_69 ) ;
F_60 ( V_14 , V_4 ) ;
}
V_4 = NULL ;
}
if ( V_11 ) {
for ( V_69 = 0 ; V_69 < F_58 ( V_11 ) ; V_69 ++ ) {
V_4 = F_59 ( V_11 , V_69 ) ;
F_61 ( V_14 , V_4 ) ;
}
V_4 = NULL ;
}
if ( V_71 ) {
const T_15 * V_163 ;
F_62 ( & V_163 , NULL , V_14 ) ;
F_63 ( V_163 ) ;
}
if ( V_70 ) {
for ( V_69 = 1 ; V_69 <= V_70 ; V_69 ++ ) {
if ( V_77 == V_69 ) {
F_42 ( V_5 , L_24 , F_64 ( V_14 ) , V_81 ) ;
} else if ( V_76 == V_69 ) {
F_42 ( V_5 , L_18 ,
F_65 ( V_14 ) , V_81 ) ;
} else if ( V_75 == V_69 ) {
F_8 ( V_5 , L_25 ) ;
F_66 ( V_5 , F_67 ( V_14 ) ) ;
F_8 ( V_5 , L_26 ) ;
} else if ( V_54 == V_69 ) {
T_16 * V_164 ;
T_1 * V_165 ;
V_165 = F_67 ( V_14 ) ;
V_164 = F_68 ( V_165 , NULL ) ;
if ( ! V_164 )
goto V_88;
if ( ! F_69 ( V_164 , 1 ) )
goto V_88;
V_165 = F_70 ( V_164 , NULL ) ;
if ( ! V_165 )
goto V_88;
F_71 ( V_164 ) ;
F_66 ( V_5 , V_165 ) ;
F_48 ( V_165 ) ;
F_72 ( V_5 , L_26 ) ;
} else if ( ( V_62 == V_69 ) || ( V_63 == V_69 ) ) {
int V_166 ;
F_2 ( V_12 ) * V_167 ;
if ( V_62 == V_69 )
V_167 = F_73 ( V_14 ) ;
else
V_167 = F_74 ( V_14 ) ;
for ( V_166 = 0 ; V_166 < F_75 ( V_167 ) ; V_166 ++ )
F_8 ( V_5 , L_27 ,
F_76 ( V_167 , V_166 ) ) ;
F_77 ( V_167 ) ;
} else if ( V_67 == V_69 ) {
unsigned char * V_168 ;
V_168 = F_78 ( V_14 , NULL ) ;
if ( V_168 )
F_8 ( V_5 , L_27 , V_168 ) ;
else
F_72 ( V_5 , L_28 ) ;
} else if ( V_55 == V_69 ) {
F_8 ( V_5 , L_29 , F_79 ( V_14 ) ) ;
}
#ifndef F_3
else if ( V_86 == V_69 ) {
F_8 ( V_5 , L_29 , F_80 ( V_14 ) ) ;
}
#endif
else if ( V_56 == V_69 ) {
F_8 ( V_5 , L_29 , F_81 ( V_14 ) ) ;
}
#ifndef F_3
else if ( V_87 == V_69 ) {
F_8 ( V_5 , L_29 , F_82 ( V_14 ) ) ;
}
#endif
else if ( V_42 == V_69 ) {
T_17 * V_169 ;
int V_166 ;
F_8 ( V_5 , L_30 ) ;
for ( V_166 = 0 ; V_166 < F_83 () ; V_166 ++ ) {
V_169 = F_84 ( V_166 ) ;
F_85 ( V_5 , V_14 , V_169 ) ;
}
} else if ( V_40 == V_69 ) {
T_5 * V_161 ;
V_161 = F_86 ( V_14 ) ;
if ( V_161 == NULL ) {
F_8 ( V_94 , L_31 ) ;
F_30 ( V_94 ) ;
goto V_88;
}
F_8 ( V_5 , L_32 ) ;
#ifndef F_87
if ( F_88 ( V_161 ) == V_170 ) {
const T_16 * V_171 ;
F_89 ( F_90 ( V_161 ) , & V_171 , NULL , NULL ) ;
F_91 ( V_5 , V_171 ) ;
} else
#endif
#ifndef F_92
if ( F_88 ( V_161 ) == V_172 ) {
const T_16 * V_173 = NULL ;
F_93 ( F_94 ( V_161 ) , & V_173 , NULL ) ;
F_91 ( V_5 , V_173 ) ;
} else
#endif
{
F_8 ( V_5 , L_33 ) ;
}
F_8 ( V_5 , L_26 ) ;
} else if ( V_41 == V_69 ) {
T_5 * V_161 ;
V_161 = F_86 ( V_14 ) ;
if ( V_161 == NULL ) {
F_8 ( V_94 , L_34 ) ;
F_30 ( V_94 ) ;
goto V_88;
}
F_95 ( V_5 , V_161 ) ;
} else if ( V_43 == V_69 ) {
unsigned char * V_174 ;
char * V_175 ;
int V_176 ;
F_96 ( F_65 ( V_14 ) , V_35 , sizeof V_35 ) ;
F_8 ( V_5 , L_35
L_36 , V_35 ) ;
F_96 ( F_64 ( V_14 ) , V_35 , sizeof V_35 ) ;
F_8 ( V_5 , L_37
L_38 , V_35 ) ;
V_176 = F_97 ( V_14 , NULL ) ;
V_175 = F_98 ( V_176 , L_39 ) ;
V_174 = ( unsigned char * ) V_175 ;
V_176 = F_99 ( F_65 ( V_14 ) , & V_174 ) ;
F_100 ( V_5 , L_40 , V_176 , ( unsigned char * ) V_175 ) ;
V_174 = ( unsigned char * ) V_175 ;
V_176 = F_101 ( F_102 ( V_14 ) , & V_174 ) ;
F_100 ( V_5 , L_41 , V_176 , ( unsigned char * ) V_175 ) ;
V_174 = ( unsigned char * ) V_175 ;
V_176 = F_97 ( V_14 , & V_174 ) ;
F_100 ( V_5 , L_42 , V_176 , ( unsigned char * ) V_175 ) ;
F_103 ( V_175 ) ;
} else if ( V_74 == V_69 ) {
F_104 ( V_5 , V_14 , V_81 , V_82 ) ;
} else if ( V_78 == V_69 ) {
F_72 ( V_5 , L_43 ) ;
F_105 ( V_5 , F_106 ( V_14 ) ) ;
F_72 ( V_5 , L_26 ) ;
} else if ( V_79 == V_69 ) {
F_72 ( V_5 , L_44 ) ;
F_105 ( V_5 , F_107 ( V_14 ) ) ;
F_72 ( V_5 , L_26 ) ;
} else if ( V_47 == V_69 ) {
int V_166 ;
unsigned int V_171 ;
unsigned char V_177 [ V_178 ] ;
const T_9 * V_179 = V_19 ;
if ( ! V_179 )
V_179 = F_108 () ;
if ( ! F_109 ( V_14 , V_179 , V_177 , & V_171 ) ) {
F_8 ( V_94 , L_45 ) ;
goto V_88;
}
F_8 ( V_5 , L_46 ,
F_110 ( F_111 ( V_179 ) ) ) ;
for ( V_166 = 0 ; V_166 < ( int ) V_171 ; V_166 ++ ) {
F_8 ( V_5 , L_47 , V_177 [ V_166 ] , ( V_166 + 1 == ( int ) V_171 )
? '\n' : ':' ) ;
}
}
else if ( ( V_59 == V_69 ) && ( V_37 == 0 ) ) {
F_8 ( V_94 , L_48 ) ;
if ( V_7 == NULL ) {
V_7 = F_112 ( V_33 , V_53 , 0 ,
V_29 , V_85 , L_49 ) ;
if ( V_7 == NULL )
goto V_88;
}
assert ( V_49 ) ;
if ( ! F_113 ( V_14 , V_7 , V_38 , V_72 , V_19 , V_6 , V_27 ) )
goto V_88;
} else if ( V_60 == V_69 ) {
F_8 ( V_94 , L_50 ) ;
if ( V_20 != NULL ) {
V_8 = F_112 ( V_20 , V_46 ,
0 , V_29 , V_85 , L_51 ) ;
if ( V_8 == NULL )
goto V_88;
}
assert ( V_49 ) ;
if ( ! F_114 ( V_18 , V_34 , V_19 , V_14 , V_15 ,
V_8 , V_13 ,
V_21 , V_61 , V_38 , V_72 ,
V_6 , V_27 , V_3 , V_48 ) )
goto V_88;
} else if ( V_37 == V_69 ) {
T_5 * V_180 ;
F_8 ( V_94 , L_52 ) ;
if ( V_33 == NULL ) {
F_8 ( V_94 , L_53 ) ;
goto V_88;
} else {
V_180 = F_112 ( V_33 , V_53 , 0 ,
V_29 , V_85 , L_54 ) ;
if ( V_180 == NULL )
goto V_88;
}
F_8 ( V_94 , L_55 ) ;
V_17 = F_115 ( V_14 , V_180 , V_19 ) ;
F_116 ( V_180 ) ;
if ( V_17 == NULL ) {
F_30 ( V_94 ) ;
goto V_88;
}
if ( ! V_58 ) {
F_117 ( V_5 , V_17 ) ;
F_118 ( V_5 , V_17 ) ;
}
V_58 = 1 ;
} else if ( V_57 == V_69 ) {
F_119 ( V_5 , V_14 ) ;
}
}
}
if ( V_50 ) {
T_10 V_181 = time ( NULL ) + V_80 ;
if ( F_120 ( F_107 ( V_14 ) , & V_181 ) < 0 ) {
F_8 ( V_5 , L_56 ) ;
V_68 = 1 ;
} else {
F_8 ( V_5 , L_57 ) ;
V_68 = 0 ;
}
goto V_88;
}
F_121 ( V_5 , V_14 , V_24 , V_25 , V_26 ) ;
if ( V_58 || V_73 ) {
V_68 = 0 ;
goto V_88;
}
if ( V_52 == V_182 )
V_69 = F_122 ( V_5 , V_14 ) ;
else if ( V_52 == V_45 ) {
if ( V_64 )
V_69 = F_123 ( V_5 , V_14 ) ;
else
V_69 = F_124 ( V_5 , V_14 ) ;
} else {
F_8 ( V_94 , L_58 ) ;
goto V_88;
}
if ( ! V_69 ) {
F_8 ( V_94 , L_59 ) ;
F_30 ( V_94 ) ;
goto V_88;
}
V_68 = 0 ;
V_88:
if ( V_49 )
F_125 ( NULL ) ;
F_126 ( V_6 ) ;
F_127 ( V_5 ) ;
F_128 ( V_18 ) ;
F_129 ( V_16 ) ;
F_130 ( V_14 ) ;
F_130 ( V_15 ) ;
F_116 ( V_7 ) ;
F_116 ( V_8 ) ;
F_116 ( V_9 ) ;
F_131 ( V_13 ) ;
F_129 ( V_17 ) ;
F_48 ( V_3 ) ;
F_132 ( V_10 , V_183 ) ;
F_132 ( V_11 , V_183 ) ;
V_183 ( V_4 ) ;
F_103 ( V_29 ) ;
return ( V_68 ) ;
}
static T_1 * F_133 ( const char * V_34 , const char * V_184 ,
int V_185 )
{
char * V_35 = NULL , * V_186 ;
T_1 * V_187 = NULL ;
T_16 * V_75 = NULL ;
T_18 V_176 ;
V_176 = ( ( V_184 == NULL )
? ( strlen ( V_34 ) + strlen ( V_188 ) + 1 )
: ( strlen ( V_184 ) ) ) + 1 ;
V_35 = F_98 ( V_176 , L_60 ) ;
if ( V_184 == NULL ) {
F_134 ( V_35 , V_34 , V_176 ) ;
for ( V_186 = V_35 ; * V_186 ; V_186 ++ )
if ( * V_186 == '.' ) {
* V_186 = '\0' ;
break;
}
F_135 ( V_35 , V_188 , V_176 ) ;
} else
F_134 ( V_35 , V_184 , V_176 ) ;
V_75 = F_136 ( V_35 , V_185 , NULL ) ;
if ( V_75 == NULL )
goto V_88;
if ( ! F_69 ( V_75 , 1 ) ) {
F_8 ( V_94 , L_61 ) ;
goto V_88;
}
if ( ! F_137 ( V_35 , NULL , V_75 , & V_187 ) )
goto V_88;
V_88:
F_103 ( V_35 ) ;
F_71 ( V_75 ) ;
return V_187 ;
}
static int V_89 ( int V_189 , T_19 * V_18 )
{
int V_190 ;
T_6 * V_191 ;
V_190 = F_138 ( V_18 ) ;
if ( V_190 == V_192 )
return 1 ;
if ( V_189 ) {
F_8 ( V_94 ,
L_62 ) ;
return 0 ;
} else {
V_191 = F_139 ( V_18 ) ;
F_42 ( V_94 , NULL , F_65 ( V_191 ) , 0 ) ;
F_8 ( V_94 ,
L_63 , V_190 ,
F_140 ( V_18 ) ,
F_141 ( V_190 ) ) ;
return 1 ;
}
}
static int F_113 ( T_6 * V_14 , T_5 * V_161 , int V_38 , int V_72 ,
const T_9 * V_19 , T_4 * V_193 , const char * V_194 )
{
if ( ! F_49 ( V_14 , F_65 ( V_14 ) ) )
goto V_190;
if ( ! F_51 ( V_14 , NULL , NULL , V_38 ) )
goto V_190;
if ( ! F_52 ( V_14 , V_161 ) )
goto V_190;
if ( V_72 ) {
while ( F_142 ( V_14 ) > 0 )
F_143 ( V_14 , 0 ) ;
}
if ( V_193 ) {
T_14 V_18 ;
F_144 ( V_14 , 2 ) ;
F_145 ( & V_18 , V_14 , V_14 , NULL , NULL , 0 ) ;
F_36 ( & V_18 , V_193 ) ;
if ( ! F_37 ( V_193 , & V_18 , V_194 , V_14 ) )
goto V_190;
}
if ( ! F_146 ( V_14 , V_161 , V_19 ) )
goto V_190;
return 1 ;
V_190:
F_30 ( V_94 ) ;
return 0 ;
}
static int F_85 ( T_3 * V_195 , T_6 * V_196 , T_17 * V_197 )
{
int V_198 , V_69 , V_199 ;
const char * V_200 ;
V_198 = F_147 ( V_197 ) ;
V_200 = F_148 ( V_197 ) ;
for ( V_69 = 0 ; V_69 < 2 ; V_69 ++ ) {
V_199 = F_149 ( V_196 , V_198 , V_69 ) ;
F_8 ( V_195 , L_64 , V_200 , V_69 ? L_65 : L_66 ) ;
if ( V_199 == 1 )
F_8 ( V_195 , L_67 ) ;
else if ( V_199 == 0 )
F_8 ( V_195 , L_68 ) ;
else
F_8 ( V_195 , L_69 , V_199 ) ;
}
return 1 ;
}
