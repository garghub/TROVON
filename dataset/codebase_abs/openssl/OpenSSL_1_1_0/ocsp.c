int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL , * V_5 = NULL , * V_6 = NULL ;
const T_2 * V_7 = NULL , * V_8 = NULL ;
int V_9 = 0 ;
T_3 * V_10 = NULL ;
T_4 * V_11 = NULL , * V_12 = NULL ;
T_5 * V_13 = NULL ;
T_6 * V_14 = NULL ;
T_7 * V_15 = NULL ;
F_2 ( V_16 ) * V_17 = NULL ;
F_2 ( V_18 ) * V_19 = NULL ;
F_2 ( V_20 ) * V_21 = NULL ;
F_2 ( V_22 ) * V_23 = NULL , * V_24 = NULL , * V_25 = NULL ;
F_2 ( V_22 ) * V_26 = NULL ;
V_22 * V_27 = NULL , * V_28 = NULL , * V_29 = NULL ;
V_22 * V_30 = NULL , * V_31 = NULL ;
T_8 * V_32 = NULL ;
T_9 * V_33 = NULL ;
const char * V_34 = NULL , * V_35 = NULL ;
char * V_36 , * V_37 ;
char * V_38 = NULL , * V_39 = NULL , * V_40 = L_1 , * V_41 = NULL ;
char * V_42 = NULL , * V_43 = NULL , * V_44 = NULL ;
char * V_45 = NULL , * V_46 = NULL , * V_47 = NULL ;
char * V_48 = NULL , * V_49 = NULL ;
char * V_50 = NULL , * V_51 = NULL , * V_52 = NULL ;
char * V_53 = NULL , * V_54 = NULL ;
char * V_55 = NULL , * V_56 = NULL , * V_57 = NULL ;
int V_58 = 0 , V_59 = 0 ;
int V_60 = - 1 , V_61 = 1 , V_62 = 0 , V_63 = - 1 ;
int V_64 = 0 , V_65 = 0 , V_66 , V_67 = 0 , V_68 = 0 , V_69 = - 1 ;
int V_70 = 0 , V_71 = 0 , V_72 = 1 ;
#ifndef F_3
int V_73 = - 1 ;
#endif
long V_74 = V_75 , V_76 = - 1 ;
unsigned long V_77 = 0 , V_78 = 0 , V_79 = 0 ;
T_10 V_80 ;
char * V_81 ;
V_21 = F_4 () ;
if ( ! V_21 )
goto V_82;
V_19 = F_5 () ;
if ( ! V_19 )
goto V_82;
if ( ( V_33 = F_6 () ) == NULL )
return 1 ;
V_81 = F_7 ( V_1 , V_2 , V_83 ) ;
while ( ( V_80 = F_8 () ) != V_84 ) {
switch ( V_80 ) {
case V_84 :
case V_85 :
V_86:
F_9 ( V_87 , L_2 , V_81 ) ;
goto V_82;
case V_88 :
V_72 = 0 ;
F_10 ( V_83 ) ;
goto V_82;
case V_89 :
V_41 = F_11 () ;
break;
case V_90 :
#ifndef F_3
V_73 = atoi ( F_11 () ) ;
#endif
break;
case V_91 :
F_12 ( V_55 ) ;
F_12 ( V_56 ) ;
F_12 ( V_57 ) ;
V_55 = V_56 = V_57 = NULL ;
if ( ! F_13 ( F_11 () , & V_38 , & V_39 , & V_40 , & V_63 ) ) {
F_9 ( V_87 , L_3 , V_81 ) ;
goto V_82;
}
V_55 = V_38 ;
V_56 = V_39 ;
V_57 = V_40 ;
break;
case V_92 :
V_38 = F_11 () ;
break;
case V_93 :
V_39 = F_11 () ;
break;
case V_94 :
V_67 = 1 ;
break;
case V_95 :
V_62 = 1 ;
break;
case V_96 :
V_61 = 2 ;
break;
case V_97 :
V_61 = 0 ;
break;
case V_98 :
V_79 |= V_99 ;
break;
case V_100 :
V_79 |= V_101 ;
break;
case V_102 :
V_77 |= V_99 ;
break;
case V_103 :
V_78 |= V_104 ;
break;
case V_105 :
V_78 |= V_106 ;
break;
case V_107 :
V_78 |= V_108 ;
break;
case V_109 :
V_78 |= V_110 ;
break;
case V_111 :
V_78 |= V_112 ;
break;
case V_113 :
V_78 |= V_114 ;
break;
case V_115 :
V_78 |= V_116 ;
break;
case V_117 :
V_65 = 1 ;
break;
case V_118 :
V_70 = V_71 = 1 ;
break;
case V_119 :
V_70 = 1 ;
break;
case V_120 :
V_71 = 1 ;
break;
case V_121 :
V_43 = F_11 () ;
break;
case V_122 :
V_44 = F_11 () ;
break;
case V_123 :
V_53 = F_11 () ;
break;
case V_124 :
V_51 = F_11 () ;
V_78 |= V_114 ;
break;
case V_125 :
V_50 = F_11 () ;
break;
case V_126 :
V_51 = F_11 () ;
break;
case V_127 :
V_34 = F_11 () ;
break;
case V_128 :
V_35 = F_11 () ;
break;
case V_129 :
V_58 = 1 ;
break;
case V_130 :
V_59 = 1 ;
break;
case V_131 :
if ( ! F_14 ( V_80 , V_33 ) )
goto V_82;
V_64 ++ ;
break;
case V_132 :
F_15 ( F_11 () , & V_74 ) ;
break;
case V_133 :
F_15 ( F_11 () , & V_76 ) ;
break;
case V_134 :
V_54 = F_11 () ;
break;
case V_135 :
V_45 = F_11 () ;
break;
case V_136 :
V_46 = F_11 () ;
break;
case V_137 :
V_40 = F_11 () ;
break;
case V_138 :
V_27 = F_16 ( F_11 () , V_139 , L_4 ) ;
if ( V_27 == NULL )
goto V_82;
if ( V_26 == NULL ) {
if ( ( V_26 = F_17 () ) == NULL )
goto V_82;
}
F_18 ( V_26 , V_27 ) ;
break;
case V_140 :
F_19 ( V_28 ) ;
V_28 = F_16 ( F_11 () , V_139 , L_5 ) ;
if ( V_28 == NULL )
goto V_82;
if ( V_7 == NULL )
V_7 = F_20 () ;
if ( ! F_21 ( & V_14 , V_28 , V_7 , V_27 , V_19 ) )
goto V_82;
if ( ! F_22 ( V_21 , F_11 () ) )
goto V_82;
V_9 = 0 ;
break;
case V_141 :
if ( V_7 == NULL )
V_7 = F_20 () ;
if ( ! F_23 ( & V_14 , F_11 () , V_7 , V_27 , V_19 ) )
goto V_82;
if ( ! F_22 ( V_21 , F_11 () ) )
goto V_82;
V_9 = 0 ;
break;
case V_142 :
V_47 = F_11 () ;
break;
case V_143 :
V_42 = F_11 () ;
break;
case V_144 :
F_24 ( F_11 () , & V_68 ) ;
if ( V_69 == - 1 )
V_69 = 0 ;
break;
case V_145 :
F_24 ( F_11 () , & V_60 ) ;
break;
case V_146 :
V_69 = atoi ( F_11 () ) ;
break;
case V_147 :
V_48 = F_11 () ;
break;
case V_148 :
V_49 = F_11 () ;
break;
case V_149 :
V_52 = F_11 () ;
break;
case V_150 :
if ( ! F_25 ( F_11 () , & V_8 ) )
goto V_82;
break;
case V_151 :
V_36 = F_11 () ;
V_37 = strchr ( V_36 , '=' ) ;
if ( V_37 == NULL ) {
F_9 ( V_87 , L_6 ) ;
goto V_86;
}
* V_37 ++ = '\0' ;
if ( ! F_26 ( V_36 , V_37 , & V_17 ) )
goto V_82;
break;
case V_152 :
if ( V_9 ) {
F_9 ( V_87 ,
L_7 ,
V_81 ) ;
goto V_86;
}
if ( ! F_25 ( F_27 () , & V_7 ) )
goto V_86;
V_9 = 1 ;
break;
}
}
if ( V_9 ) {
F_9 ( V_87 , L_7 ,
V_81 ) ;
goto V_86;
}
V_1 = F_28 () ;
if ( V_1 != 0 )
goto V_86;
if ( ! V_14 && ! V_43 && ! V_44 && ! ( V_39 && V_47 ) )
goto V_86;
V_6 = F_29 ( V_41 , 'w' , V_153 ) ;
if ( V_6 == NULL )
goto V_82;
if ( ! V_14 && ( V_61 != 2 ) )
V_61 = 0 ;
if ( ! V_14 && V_43 ) {
V_5 = F_29 ( V_43 , 'r' , V_154 ) ;
if ( V_5 == NULL )
goto V_82;
V_14 = F_30 ( V_5 , NULL ) ;
F_31 ( V_5 ) ;
if ( ! V_14 ) {
F_9 ( V_87 , L_8 ) ;
goto V_82;
}
}
if ( ! V_14 && V_39 ) {
V_3 = F_32 ( V_39 ) ;
if ( ! V_3 )
goto V_82;
}
if ( V_48 ) {
if ( ! V_49 )
V_49 = V_48 ;
V_31 = F_16 ( V_48 , V_139 , L_9 ) ;
if ( ! V_31 ) {
F_9 ( V_87 , L_10 ) ;
goto V_82;
}
V_29 = F_16 ( V_42 , V_139 , L_11 ) ;
if ( V_52 ) {
if ( ! F_33 ( V_52 , & V_25 , V_139 , NULL ,
L_12 ) )
goto V_82;
}
V_12 = F_34 ( V_49 , V_139 , 0 , NULL , NULL ,
L_13 ) ;
if ( ! V_12 )
goto V_82;
}
if ( V_3 )
F_9 ( V_87 , L_14 ) ;
V_155:
if ( V_3 ) {
if ( ! F_35 ( & V_14 , & V_4 , V_3 ) )
goto V_82;
if ( ! V_14 ) {
V_15 =
F_36 ( V_156 ,
NULL ) ;
F_37 ( V_4 , V_15 ) ;
goto V_157;
}
}
if ( ! V_14 && ( V_53 || V_45 || V_38 || V_61 || V_47 ) ) {
F_9 ( V_87 , L_15 ) ;
goto V_82;
}
if ( V_14 && V_61 )
F_38 ( V_14 , NULL , - 1 ) ;
if ( V_53 ) {
if ( ! V_54 )
V_54 = V_53 ;
V_30 = F_16 ( V_53 , V_139 , L_16 ) ;
if ( ! V_30 ) {
F_9 ( V_87 , L_17 ) ;
goto V_82;
}
if ( V_50 ) {
if ( ! F_33 ( V_50 , & V_23 , V_139 , NULL ,
L_18 ) )
goto V_82;
}
V_11 = F_34 ( V_54 , V_139 , 0 , NULL , NULL ,
L_19 ) ;
if ( ! V_11 )
goto V_82;
if ( ! F_39
( V_14 , V_30 , V_11 , NULL , V_23 , V_77 ) ) {
F_9 ( V_87 , L_20 ) ;
goto V_82;
}
}
if ( V_70 && V_14 )
F_40 ( V_6 , V_14 , 0 ) ;
if ( V_45 ) {
V_5 = F_29 ( V_45 , 'w' , V_154 ) ;
if ( V_5 == NULL )
goto V_82;
F_41 ( V_5 , V_14 ) ;
F_31 ( V_5 ) ;
}
if ( V_47 && ( ! V_12 || ! V_31 || ! V_29 ) ) {
F_9 ( V_87 ,
L_21 ) ;
goto V_82;
}
if ( V_47 && ! V_10 ) {
V_10 = F_42 ( V_47 , NULL ) ;
if ( ! V_10 )
goto V_82;
if ( ! F_43 ( V_10 ) )
goto V_82;
}
if ( V_10 ) {
F_44 ( & V_15 , V_14 , V_10 , V_29 , V_31 , V_12 ,
V_8 , V_25 , V_79 , V_68 , V_69 , V_65 ) ;
if ( V_4 )
F_37 ( V_4 , V_15 ) ;
} else if ( V_38 ) {
# ifndef F_3
V_15 = F_45 ( V_14 , V_38 , V_40 ,
V_39 , V_63 , V_17 , V_73 ) ;
if ( ! V_15 )
goto V_82;
# else
F_9 ( V_87 ,
L_22 ) ;
goto V_82;
# endif
} else if ( V_44 ) {
V_5 = F_29 ( V_44 , 'r' , V_154 ) ;
if ( V_5 == NULL )
goto V_82;
V_15 = F_46 ( V_5 , NULL ) ;
F_31 ( V_5 ) ;
if ( ! V_15 ) {
F_9 ( V_87 , L_23 ) ;
goto V_82;
}
} else {
V_72 = 0 ;
goto V_82;
}
V_157:
if ( V_46 ) {
V_5 = F_29 ( V_46 , 'w' , V_154 ) ;
if ( V_5 == NULL )
goto V_82;
F_47 ( V_5 , V_15 ) ;
F_31 ( V_5 ) ;
}
V_66 = F_48 ( V_15 ) ;
if ( V_66 != V_158 ) {
F_9 ( V_6 , L_24 ,
F_49 ( V_66 ) , V_66 ) ;
if ( V_67 )
goto V_155;
V_72 = 0 ;
goto V_82;
}
if ( V_71 )
F_50 ( V_6 , V_15 , 0 ) ;
if ( V_4 ) {
if ( V_60 != - 1 && -- V_60 <= 0 ) {
V_72 = 0 ;
goto V_82;
}
F_51 ( V_4 ) ;
V_4 = NULL ;
F_52 ( V_14 ) ;
V_14 = NULL ;
F_53 ( V_15 ) ;
V_15 = NULL ;
goto V_155;
}
if ( V_47 ) {
V_72 = 0 ;
goto V_82;
}
if ( ! V_32 ) {
V_32 = F_54 ( V_34 , V_35 , V_58 , V_59 ) ;
if ( ! V_32 )
goto V_82;
}
if ( V_64 )
F_55 ( V_32 , V_33 ) ;
if ( V_51 ) {
if ( ! F_33 ( V_51 , & V_24 , V_139 , NULL ,
L_25 ) )
goto V_82;
}
V_13 = F_56 ( V_15 ) ;
if ( ! V_13 ) {
F_9 ( V_87 , L_26 ) ;
goto V_82;
}
V_72 = 0 ;
if ( ! V_62 ) {
if ( V_14 && ( ( V_66 = F_57 ( V_14 , V_13 ) ) <= 0 ) ) {
if ( V_66 == - 1 )
F_9 ( V_87 , L_27 ) ;
else {
F_9 ( V_87 , L_28 ) ;
V_72 = 1 ;
goto V_82;
}
}
V_66 = F_58 ( V_13 , V_24 , V_32 , V_78 ) ;
if ( V_66 <= 0 && V_26 ) {
V_66 = F_58 ( V_13 , V_26 , V_32 , V_114 ) ;
if ( V_66 > 0 )
F_59 () ;
}
if ( V_66 <= 0 ) {
F_9 ( V_87 , L_29 ) ;
F_60 ( V_87 ) ;
V_72 = 1 ;
} else
F_9 ( V_87 , L_30 ) ;
}
F_61 ( V_6 , V_13 , V_14 , V_21 , V_19 , V_74 , V_76 ) ;
V_82:
F_60 ( V_87 ) ;
F_19 ( V_30 ) ;
F_62 ( V_32 ) ;
F_63 ( V_33 ) ;
F_64 ( V_11 ) ;
F_64 ( V_12 ) ;
F_19 ( V_28 ) ;
F_65 ( V_26 , F_19 ) ;
F_19 ( V_31 ) ;
F_19 ( V_29 ) ;
F_66 ( V_10 ) ;
F_51 ( V_4 ) ;
F_51 ( V_3 ) ;
F_31 ( V_6 ) ;
F_52 ( V_14 ) ;
F_53 ( V_15 ) ;
F_67 ( V_13 ) ;
F_68 ( V_21 ) ;
F_69 ( V_19 ) ;
F_65 ( V_23 , F_19 ) ;
F_65 ( V_24 , F_19 ) ;
F_70 ( V_17 , V_159 ) ;
F_12 ( V_55 ) ;
F_12 ( V_56 ) ;
F_12 ( V_57 ) ;
return ( V_72 ) ;
}
static char * * F_71 ( T_3 * V_160 , T_11 * V_161 )
{
int V_66 ;
T_12 * V_162 = NULL ;
char * V_163 , * V_164 [ V_165 ] , * * V_166 ;
for ( V_66 = 0 ; V_66 < V_165 ; V_66 ++ )
V_164 [ V_66 ] = NULL ;
V_162 = F_72 ( V_161 , NULL ) ;
F_73 ( V_162 ) ;
if ( F_74 ( V_162 ) )
V_163 = F_75 ( L_31 ) ;
else
V_163 = F_76 ( V_162 ) ;
V_164 [ V_167 ] = V_163 ;
F_77 ( V_162 ) ;
V_166 = F_78 ( V_160 -> V_160 , V_167 , V_164 ) ;
F_12 ( V_163 ) ;
return V_166 ;
}
static T_1 * F_32 ( const char * V_39 )
{
# ifdef F_3
F_9 ( V_87 ,
L_32 ) ;
return NULL ;
# else
T_1 * V_3 = NULL , * V_168 = NULL ;
V_168 = F_79 ( F_80 () ) ;
if ( V_168 == NULL )
goto V_169;
V_3 = F_79 ( F_81 () ) ;
if ( V_3 == NULL
|| F_82 ( V_3 , V_170 ) < 0
|| F_83 ( V_3 , V_39 ) < 0 ) {
F_9 ( V_87 , L_33 ) ;
F_60 ( V_87 ) ;
goto V_169;
}
F_84 ( V_3 , V_168 ) ;
V_168 = NULL ;
if ( F_85 ( V_3 ) <= 0 ) {
F_9 ( V_87 , L_34 ) ;
F_60 ( V_87 ) ;
goto V_169;
}
return V_3 ;
V_169:
F_51 ( V_3 ) ;
F_31 ( V_168 ) ;
return NULL ;
# endif
}
static int F_86 ( char * V_171 )
{
unsigned char * V_6 = ( unsigned char * ) V_171 ;
unsigned char * V_172 = V_6 ;
for (; * V_171 ; V_171 ++ ) {
if ( * V_171 != '%' )
* V_6 ++ = * V_171 ;
else if ( isxdigit ( F_87 ( V_171 [ 1 ] ) ) && isxdigit ( F_87 ( V_171 [ 2 ] ) ) ) {
* V_6 ++ = ( F_88 ( V_171 [ 1 ] ) << 4 )
| F_88 ( V_171 [ 2 ] ) ;
V_171 += 2 ;
}
else
return - 1 ;
}
* V_6 = '\0' ;
return ( int ) ( V_6 - V_172 ) ;
}
static int F_35 ( T_6 * * V_173 , T_1 * * V_174 , T_1 * V_3 )
{
# ifdef F_3
return 0 ;
# else
int V_175 ;
T_6 * V_14 = NULL ;
char V_176 [ 2048 ] , V_177 [ 2048 ] ;
char * V_171 , * V_178 ;
T_1 * V_4 = NULL , * V_179 = NULL , * V_180 = NULL ;
if ( F_85 ( V_3 ) <= 0 ) {
F_9 ( V_87 , L_35 ) ;
F_60 ( V_87 ) ;
return 0 ;
}
V_4 = F_89 ( V_3 ) ;
* V_174 = V_4 ;
V_175 = F_90 ( V_4 , V_177 , sizeof V_177 ) ;
if ( V_175 <= 0 )
return 1 ;
if ( strncmp ( V_177 , L_36 , 4 ) == 0 ) {
for ( V_171 = V_177 + 4 ; * V_171 == ' ' ; ++ V_171 )
continue;
if ( * V_171 != '/' ) {
F_9 ( V_87 , L_37 ) ;
return 1 ;
}
V_171 ++ ;
for ( V_178 = V_171 ; * V_178 ; V_178 ++ )
if ( * V_178 == ' ' )
break;
if ( strncmp ( V_178 , L_38 , 8 ) != 0 ) {
F_9 ( V_87 , L_39 ) ;
return 1 ;
}
* V_178 = '\0' ;
V_175 = F_86 ( V_171 ) ;
if ( V_175 <= 0 ) {
F_9 ( V_87 , L_40 ) ;
return 1 ;
}
if ( ( V_179 = F_91 ( V_171 , V_175 ) ) == NULL
|| ( V_180 = F_79 ( F_92 () ) ) == NULL ) {
F_9 ( V_87 , L_41 ) ;
F_60 ( V_87 ) ;
return 1 ;
}
F_93 ( V_180 , V_181 ) ;
V_179 = F_94 ( V_180 , V_179 ) ;
} else if ( strncmp ( V_177 , L_42 , 5 ) != 0 ) {
F_9 ( V_87 , L_43 ) ;
return 1 ;
}
for (; ; ) {
V_175 = F_90 ( V_4 , V_176 , sizeof V_176 ) ;
if ( V_175 <= 0 )
return 1 ;
if ( ( V_176 [ 0 ] == '\r' ) || ( V_176 [ 0 ] == '\n' ) )
break;
}
if ( V_179 ) {
V_14 = F_30 ( V_179 , NULL ) ;
F_51 ( V_179 ) ;
} else
V_14 = F_30 ( V_4 , NULL ) ;
if ( ! V_14 ) {
F_9 ( V_87 , L_44 ) ;
F_60 ( V_87 ) ;
}
* V_173 = V_14 ;
return 1 ;
# endif
}
static int F_37 ( T_1 * V_4 , T_7 * V_15 )
{
char V_182 [] =
L_45
L_46 ;
if ( ! V_4 )
return 0 ;
F_9 ( V_4 , V_182 , F_95 ( V_15 , NULL ) ) ;
F_47 ( V_4 , V_15 ) ;
( void ) F_96 ( V_4 ) ;
return 1 ;
}
