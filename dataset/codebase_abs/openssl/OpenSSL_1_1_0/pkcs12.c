int F_1 ( int V_1 , char * * V_2 )
{
char * V_3 = NULL , * V_4 = NULL , * V_5 = NULL , * V_6 = NULL ;
char * V_7 = NULL , * V_8 = NULL ;
char V_9 [ 2048 ] = L_1 , V_10 [ 2048 ] = L_1 ;
int V_11 = 0 , V_12 = 0 , V_13 = 0 , V_14 = 0 , V_15 = 0 ;
int V_16 = V_17 , V_18 = V_17 ;
# ifndef F_2
int V_19 = V_20 ;
# else
int V_19 = V_21 ;
# endif
int V_22 = V_21 ;
int V_23 = 1 , V_24 = 1 , V_25 = 0 , V_26 = 0 ;
int V_27 = 0 ;
char * V_28 = NULL , * V_29 = NULL , * V_30 = NULL ;
char * V_31 = NULL , * V_32 = NULL , * V_33 = NULL , * V_34 = NULL ;
char * V_35 = NULL , * V_36 = NULL , * V_37 = NULL ;
const char * V_38 = NULL , * V_39 = NULL , * V_40 ;
int V_41 = 0 , V_42 = 0 ;
T_1 * V_43 = NULL ;
T_2 * V_44 = NULL , * V_45 = NULL ;
T_3 * V_46 = NULL ;
F_3 ( V_47 ) * V_48 = NULL ;
const T_4 * V_49 = F_4 () ;
T_5 V_50 ;
V_40 = F_5 ( V_1 , V_2 , V_51 ) ;
while ( ( V_50 = F_6 () ) != V_52 ) {
switch ( V_50 ) {
case V_52 :
case V_53 :
V_54:
F_7 ( V_55 , L_2 , V_40 ) ;
goto V_56;
case V_57 :
F_8 ( V_51 ) ;
V_23 = 0 ;
goto V_56;
case V_58 :
V_12 |= V_59 ;
break;
case V_60 :
V_15 = V_61 ;
break;
case V_62 :
V_15 = V_63 ;
break;
case V_64 :
V_12 |= V_65 ;
break;
case V_66 :
V_12 |= V_67 ;
break;
case V_68 :
V_12 |= V_69 ;
break;
case V_70 :
V_12 |= ( V_59 | V_65 ) ;
break;
case V_71 :
V_12 |= V_72 ;
break;
case V_73 :
V_13 = 1 ;
break;
case V_74 :
V_14 = 1 ;
break;
case V_75 :
V_24 = 0 ;
break;
case V_76 :
V_19 = V_21 ;
break;
case V_77 :
V_11 = 1 ;
break;
case V_78 :
if ( ! F_9 ( F_10 () , & V_49 ) )
goto V_54;
break;
case V_79 :
V_16 = 1 ;
break;
case V_80 :
V_18 = V_17 ;
break;
case V_81 :
V_18 = 1 ;
break;
case V_82 :
V_18 = - 1 ;
break;
case V_83 :
V_34 = F_11 () ;
break;
case V_84 :
V_49 = NULL ;
break;
case V_85 :
if ( ! F_12 ( & V_19 , F_11 () ) )
goto V_54;
break;
case V_86 :
if ( ! F_12 ( & V_22 , F_11 () ) )
goto V_54;
break;
case V_87 :
V_33 = F_11 () ;
break;
case V_88 :
V_5 = F_11 () ;
break;
case V_89 :
V_6 = F_11 () ;
break;
case V_90 :
V_7 = F_11 () ;
break;
case V_91 :
V_25 = 1 ;
break;
case V_92 :
V_8 = F_11 () ;
break;
case V_93 :
if ( V_48 == NULL
&& ( V_48 = F_13 () ) == NULL )
goto V_56;
F_14 ( V_48 , F_11 () ) ;
break;
case V_94 :
V_3 = F_11 () ;
break;
case V_95 :
V_4 = F_11 () ;
break;
case V_96 :
V_28 = F_11 () ;
break;
case V_97 :
V_29 = F_11 () ;
break;
case V_98 :
V_30 = F_11 () ;
break;
case V_99 :
V_38 = F_11 () ;
break;
case V_100 :
V_39 = F_11 () ;
break;
case V_101 :
V_41 = 1 ;
break;
case V_102 :
V_42 = 1 ;
break;
case V_103 :
V_43 = F_15 ( F_11 () , 0 ) ;
break;
}
}
V_1 = F_16 () ;
if ( V_1 != 0 )
goto V_54;
V_26 = 1 ;
if ( V_30 ) {
if ( V_11 )
V_29 = V_30 ;
else
V_28 = V_30 ;
}
if ( ! F_17 ( V_28 , V_29 , & V_31 , & V_32 ) ) {
F_7 ( V_55 , L_3 ) ;
goto V_56;
}
if ( ! V_35 ) {
if ( V_11 )
V_35 = V_32 ;
else
V_35 = V_31 ;
}
if ( V_35 ) {
V_36 = V_35 ;
V_27 = 1 ;
} else {
V_35 = V_9 ;
V_36 = V_10 ;
}
if ( V_11 || V_33 ) {
F_18 ( NULL , ( V_33 != NULL ) ) ;
if ( V_33 != NULL )
F_7 ( V_55 , L_4 ,
F_19 ( V_33 ) ) ;
}
if ( V_14 ) {
if ( 1 ) {
#ifndef F_20
if ( F_21
( V_10 , sizeof V_10 , L_5 , V_11 ) ) {
F_7 ( V_55 , L_6 ) ;
goto V_56;
}
} else {
#endif
F_7 ( V_55 , L_7 ) ;
goto V_56;
}
}
if ( V_11 ) {
T_6 * V_104 = NULL ;
T_7 * V_105 = NULL , * V_106 = NULL ;
F_3 ( T_7 ) * V_107 = NULL ;
const T_8 * V_108 = NULL ;
unsigned char * V_109 = NULL ;
int V_110 ;
if ( ( V_12 & ( V_65 | V_59 ) ) == ( V_65 | V_59 ) ) {
F_7 ( V_55 , L_8 ) ;
goto V_111;
}
if ( V_12 & V_65 )
V_13 = 0 ;
if ( ! ( V_12 & V_59 ) ) {
V_104 = F_22 ( V_5 ? V_5 : V_3 ,
V_112 , 1 , V_31 , V_43 , L_9 ) ;
if ( ! V_104 )
goto V_111;
}
if ( ! ( V_12 & V_65 ) ) {
if ( ! F_23 ( V_3 , & V_107 , V_112 , NULL ,
L_10 ) )
goto V_111;
if ( V_104 ) {
for ( V_110 = 0 ; V_110 < F_24 ( V_107 ) ; V_110 ++ ) {
V_106 = F_25 ( V_107 , V_110 ) ;
if ( F_26 ( V_106 , V_104 ) ) {
V_105 = V_106 ;
F_27 ( V_105 , NULL , 0 ) ;
F_28 ( V_105 , NULL , 0 ) ;
( void ) F_29 ( V_107 , V_110 ) ;
break;
}
}
if ( ! V_105 ) {
F_7 ( V_55 ,
L_11 ) ;
goto V_111;
}
}
}
if ( V_6 ) {
if ( ! F_23 ( V_6 , & V_107 , V_112 , NULL ,
L_12 ) )
goto V_111;
}
if ( V_13 ) {
int V_113 ;
F_3 ( T_7 ) * V_114 ;
T_9 * V_115 ;
if ( ( V_115 = F_30 ( V_39 , V_38 , V_42 , V_41 ) )
== NULL )
goto V_111;
V_113 = F_31 ( V_105 , V_115 , & V_114 ) ;
F_32 ( V_115 ) ;
if ( V_113 == V_116 ) {
for ( V_110 = 1 ; V_110 < F_24 ( V_114 ) ; V_110 ++ )
F_33 ( V_107 , F_25 ( V_114 , V_110 ) ) ;
F_34 ( F_25 ( V_114 , 0 ) ) ;
F_35 ( V_114 ) ;
} else {
if ( V_113 != V_117 )
F_7 ( V_55 , L_13 ,
F_36 ( V_113 ) ) ;
else
F_37 ( V_55 ) ;
goto V_111;
}
}
for ( V_110 = 0 ; V_110 < F_38 ( V_48 ) ; V_110 ++ ) {
V_109 = ( unsigned char * ) F_39 ( V_48 , V_110 ) ;
F_28 ( F_25 ( V_107 , V_110 ) , V_109 , - 1 ) ;
}
if ( V_8 && V_104 )
F_40 ( V_104 , V_118 ,
V_119 , ( unsigned char * ) V_8 ,
- 1 ) ;
if ( V_25 && V_104 )
F_40 ( V_104 , V_120 , 0 , NULL , - 1 ) ;
if ( ! V_27 ) {
if ( 1 ) {
#ifndef F_20
if ( F_21 ( V_9 , sizeof V_9 , L_14 ,
1 ) ) {
F_7 ( V_55 , L_6 ) ;
goto V_111;
}
} else {
#endif
F_7 ( V_55 , L_15 ) ;
goto V_111;
}
}
if ( ! V_14 )
F_41 ( V_10 , V_9 , sizeof V_10 ) ;
V_46 = F_42 ( V_35 , V_7 , V_104 , V_105 , V_107 ,
V_22 , V_19 , V_16 , - 1 , V_15 ) ;
if ( ! V_46 ) {
F_37 ( V_55 ) ;
goto V_111;
}
if ( V_34 ) {
if ( ! F_43 ( V_34 , & V_108 ) )
goto V_54;
}
if ( V_18 != - 1 )
F_44 ( V_46 , V_36 , - 1 , NULL , 0 , V_18 , V_108 ) ;
assert ( V_26 ) ;
V_45 = F_45 ( V_4 , V_121 , V_26 ) ;
if ( V_45 == NULL )
goto V_56;
F_46 ( V_45 , V_46 ) ;
V_23 = 0 ;
V_111:
F_47 ( V_104 ) ;
F_48 ( V_107 , F_34 ) ;
F_34 ( V_105 ) ;
goto V_56;
}
V_44 = F_49 ( V_3 , 'r' , V_121 ) ;
if ( V_44 == NULL )
goto V_56;
V_45 = F_45 ( V_4 , V_112 , V_26 ) ;
if ( V_45 == NULL )
goto V_56;
if ( ( V_46 = F_50 ( V_44 , NULL ) ) == NULL ) {
F_37 ( V_55 ) ;
goto V_56;
}
if ( ! V_27 ) {
if ( 1 ) {
#ifndef F_20
if ( F_21 ( V_9 , sizeof V_9 , L_16 ,
0 ) ) {
F_7 ( V_55 , L_6 ) ;
goto V_56;
}
} else {
#endif
F_7 ( V_55 , L_15 ) ;
goto V_56;
}
}
if ( ! V_14 )
F_41 ( V_10 , V_9 , sizeof V_10 ) ;
if ( ( V_12 & V_72 ) && F_51 ( V_46 ) ) {
const T_10 * V_122 ;
const T_11 * V_123 ;
const T_12 * V_124 ;
F_52 ( NULL , & V_123 , NULL , & V_122 , V_46 ) ;
F_53 ( & V_124 , NULL , NULL , V_123 ) ;
F_54 ( V_55 , L_17 ) ;
F_55 ( V_55 , V_124 ) ;
F_7 ( V_55 , L_18 ,
V_122 != NULL ? F_56 ( V_122 ) : 1L ) ;
}
if ( V_24 ) {
if ( ! V_36 [ 0 ] && F_57 ( V_46 , NULL , 0 ) ) {
if ( ! V_14 )
V_35 = NULL ;
} else if ( ! F_57 ( V_46 , V_36 , - 1 ) ) {
unsigned char * V_125 ;
int V_126 ;
V_125 = F_58 ( V_36 , - 1 , NULL , & V_126 ) ;
if ( V_125 == NULL )
goto V_56;
V_37 = F_59 ( V_125 , V_126 ) ;
F_60 ( V_125 ) ;
if ( ! F_57 ( V_46 , V_37 , - 1 ) ) {
F_7 ( V_55 , L_19 ) ;
F_37 ( V_55 ) ;
goto V_56;
} else {
F_7 ( V_55 , L_20 ) ;
if ( ! V_14 )
V_35 = V_37 ;
}
}
}
assert ( V_26 ) ;
if ( ! F_61 ( V_45 , V_46 , V_35 , - 1 , V_12 , V_32 , V_49 ) ) {
F_7 ( V_55 , L_21 ) ;
F_37 ( V_55 ) ;
goto V_56;
}
V_23 = 0 ;
V_56:
F_62 ( V_46 ) ;
if ( V_11 || V_33 )
F_63 ( NULL ) ;
F_64 ( V_44 ) ;
F_65 ( V_45 ) ;
F_66 ( V_48 ) ;
F_60 ( V_37 ) ;
F_60 ( V_31 ) ;
F_60 ( V_32 ) ;
return ( V_23 ) ;
}
int F_61 ( T_2 * V_45 , const T_3 * V_46 , const char * V_9 ,
int V_127 , int V_12 , char * V_128 ,
const T_4 * V_49 )
{
F_3 ( V_129 ) * V_130 = NULL ;
F_3 ( V_131 ) * V_132 ;
int V_110 , V_133 ;
int V_23 = 0 ;
V_129 * V_134 ;
if ( ( V_130 = F_67 ( V_46 ) ) == NULL )
return 0 ;
for ( V_110 = 0 ; V_110 < F_68 ( V_130 ) ; V_110 ++ ) {
V_134 = F_69 ( V_130 , V_110 ) ;
V_133 = F_70 ( V_134 -> type ) ;
if ( V_133 == V_135 ) {
V_132 = F_71 ( V_134 ) ;
if ( V_12 & V_72 )
F_7 ( V_55 , L_22 ) ;
} else if ( V_133 == V_136 ) {
if ( V_12 & V_72 ) {
F_7 ( V_55 , L_23 ) ;
F_72 ( V_134 -> V_137 . V_138 -> V_139 -> V_140 ) ;
}
V_132 = F_73 ( V_134 , V_9 , V_127 ) ;
} else
continue;
if ( ! V_132 )
goto V_141;
if ( ! F_74 ( V_45 , V_132 , V_9 , V_127 ,
V_12 , V_128 , V_49 ) ) {
F_75 ( V_132 , V_142 ) ;
goto V_141;
}
F_75 ( V_132 , V_142 ) ;
V_132 = NULL ;
}
V_23 = 1 ;
V_141:
F_76 ( V_130 , V_143 ) ;
return V_23 ;
}
int F_77 ( T_2 * V_45 , const V_131 * V_144 ,
const char * V_9 , int V_127 , int V_12 ,
char * V_128 , const T_4 * V_49 )
{
T_6 * V_145 ;
T_13 * V_146 ;
const T_13 * V_147 ;
T_7 * V_148 ;
const F_3 ( V_149 ) * V_150 ;
int V_23 = 0 ;
V_150 = F_78 ( V_144 ) ;
switch ( F_79 ( V_144 ) ) {
case V_151 :
if ( V_12 & V_72 )
F_7 ( V_55 , L_24 ) ;
if ( V_12 & V_59 )
return 1 ;
F_80 ( V_45 , V_150 , L_25 ) ;
V_147 = F_81 ( V_144 ) ;
if ( ( V_145 = F_82 ( V_147 ) ) == NULL )
return 0 ;
F_80 ( V_45 , F_83 ( V_147 ) , L_26 ) ;
V_23 = F_84 ( V_45 , V_145 , V_49 , NULL , 0 , NULL , V_128 ) ;
F_47 ( V_145 ) ;
break;
case V_152 :
if ( V_12 & V_72 ) {
const T_14 * V_153 ;
const T_11 * V_154 ;
F_7 ( V_55 , L_27 ) ;
V_153 = F_85 ( V_144 ) ;
F_86 ( V_153 , & V_154 , NULL ) ;
F_72 ( V_154 ) ;
}
if ( V_12 & V_59 )
return 1 ;
F_80 ( V_45 , V_150 , L_25 ) ;
if ( ( V_146 = F_87 ( V_144 , V_9 , V_127 ) ) == NULL )
return 0 ;
if ( ( V_145 = F_82 ( V_146 ) ) == NULL ) {
F_88 ( V_146 ) ;
return 0 ;
}
F_80 ( V_45 , F_83 ( V_146 ) , L_26 ) ;
F_88 ( V_146 ) ;
V_23 = F_84 ( V_45 , V_145 , V_49 , NULL , 0 , NULL , V_128 ) ;
F_47 ( V_145 ) ;
break;
case V_155 :
if ( V_12 & V_72 )
F_7 ( V_55 , L_28 ) ;
if ( V_12 & V_65 )
return 1 ;
if ( F_89 ( V_144 , V_156 ) ) {
if ( V_12 & V_69 )
return 1 ;
} else if ( V_12 & V_67 )
return 1 ;
F_80 ( V_45 , V_150 , L_25 ) ;
if ( F_90 ( V_144 ) != V_157 )
return 1 ;
if ( ( V_148 = F_91 ( V_144 ) ) == NULL )
return 0 ;
F_92 ( V_45 , V_148 ) ;
V_23 = F_93 ( V_45 , V_148 ) ;
F_34 ( V_148 ) ;
break;
case V_158 :
if ( V_12 & V_72 )
F_7 ( V_55 , L_29 ) ;
F_80 ( V_45 , V_150 , L_25 ) ;
return F_74 ( V_45 , F_94 ( V_144 ) ,
V_9 , V_127 , V_12 , V_128 , V_49 ) ;
default:
F_7 ( V_55 , L_30 ) ;
F_55 ( V_55 , F_95 ( V_144 ) ) ;
F_7 ( V_55 , L_31 ) ;
return 1 ;
}
return V_23 ;
}
static int F_72 ( const T_11 * V_159 )
{
int V_160 , V_161 ;
const T_12 * V_162 ;
const void * V_163 ;
T_15 * V_164 = NULL ;
F_53 ( & V_162 , & V_161 , & V_163 , V_159 ) ;
V_160 = F_70 ( V_162 ) ;
F_7 ( V_55 , L_32 , F_96 ( V_160 ) ) ;
if ( V_160 == V_165 ) {
T_16 * V_166 = NULL ;
int V_167 ;
if ( V_161 == V_168 )
V_166 = F_97 ( V_163 , F_98 ( T_16 ) ) ;
if ( V_166 == NULL ) {
F_54 ( V_55 , L_33 ) ;
goto V_169;
}
F_53 ( & V_162 , & V_161 , & V_163 , V_166 -> V_170 ) ;
V_160 = F_70 ( V_162 ) ;
F_53 ( & V_162 , NULL , NULL , V_166 -> V_171 ) ;
V_167 = F_70 ( V_162 ) ;
F_7 ( V_55 , L_34 , F_96 ( V_160 ) ,
F_99 ( V_167 ) ) ;
if ( V_160 == V_172 ) {
T_17 * V_173 = NULL ;
int V_174 ;
if ( V_161 == V_168 )
V_173 = F_97 ( V_163 , F_98 ( T_17 ) ) ;
if ( V_173 == NULL ) {
F_54 ( V_55 , L_33 ) ;
goto V_169;
}
if ( V_173 -> V_175 == NULL ) {
V_174 = V_176 ;
} else {
F_53 ( & V_162 , NULL , NULL , V_173 -> V_175 ) ;
V_174 = F_70 ( V_162 ) ;
}
F_7 ( V_55 , L_35 ,
F_56 ( V_173 -> V_16 ) , F_99 ( V_174 ) ) ;
F_100 ( V_173 ) ;
}
F_101 ( V_166 ) ;
} else {
if ( V_161 == V_168 )
V_164 = F_97 ( V_163 , F_98 ( T_15 ) ) ;
if ( V_164 == NULL ) {
F_54 ( V_55 , L_33 ) ;
goto V_169;
}
F_7 ( V_55 , L_36 , F_56 ( V_164 -> V_16 ) ) ;
F_102 ( V_164 ) ;
}
V_169:
F_54 ( V_55 , L_31 ) ;
return 1 ;
}
void F_103 ( T_2 * V_45 , unsigned char * V_177 , int V_178 )
{
int V_110 ;
for ( V_110 = 0 ; V_110 < V_178 ; V_110 ++ )
F_7 ( V_45 , L_37 , V_177 [ V_110 ] ) ;
}
static int F_12 ( int * V_179 , const char * V_180 )
{
if ( ! V_180 )
return 0 ;
if ( strcmp ( V_180 , L_38 ) == 0 ) {
* V_179 = - 1 ;
return 1 ;
}
* V_179 = F_104 ( V_180 ) ;
if ( * V_179 == V_181 ) {
F_7 ( V_55 , L_39 , V_180 ) ;
return 0 ;
}
return 1 ;
}
