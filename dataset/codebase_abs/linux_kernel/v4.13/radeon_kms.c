static inline bool F_1 ( void ) { return false ; }
void F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return;
if ( V_4 -> V_6 == NULL )
goto V_7;
if ( F_3 ( V_2 ) ) {
F_4 ( V_2 -> V_2 ) ;
F_5 ( V_2 -> V_2 ) ;
}
F_6 ( V_4 ) ;
F_7 ( V_4 ) ;
F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
V_7:
F_10 ( V_4 ) ;
V_2 -> V_5 = NULL ;
}
int F_11 ( struct V_1 * V_2 , unsigned long V_8 )
{
struct V_3 * V_4 ;
int V_9 , V_10 ;
if ( ! V_11 ) {
switch ( V_8 & V_12 ) {
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
F_12 ( V_2 -> V_2 ,
L_1 ) ;
return - V_18 ;
}
}
if ( ! V_19 ) {
switch ( V_8 & V_12 ) {
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
F_12 ( V_2 -> V_2 ,
L_2 ) ;
return - V_18 ;
}
}
V_4 = F_13 ( sizeof( struct V_3 ) , V_25 ) ;
if ( V_4 == NULL ) {
return - V_26 ;
}
V_2 -> V_5 = ( void * ) V_4 ;
if ( F_14 ( V_2 -> V_27 , V_28 ) ) {
V_8 |= V_29 ;
} else if ( F_15 ( V_2 -> V_27 ) ) {
V_8 |= V_30 ;
} else {
V_8 |= V_31 ;
}
if ( ( V_32 != 0 ) &&
F_1 () &&
( ( V_8 & V_33 ) == 0 ) &&
! F_16 ( V_2 -> V_27 ) )
V_8 |= V_34 ;
V_9 = F_17 ( V_4 , V_2 , V_2 -> V_27 , V_8 ) ;
if ( V_9 ) {
F_18 ( & V_2 -> V_27 -> V_2 , L_3 ) ;
goto V_35;
}
V_9 = F_19 ( V_4 ) ;
if ( V_9 )
F_18 ( & V_2 -> V_27 -> V_2 , L_4 ) ;
if ( ! V_9 ) {
V_10 = F_20 ( V_4 ) ;
if ( V_10 )
F_21 ( & V_2 -> V_27 -> V_2 ,
L_5 ) ;
}
F_22 ( V_4 ) ;
F_23 ( V_4 ) ;
if ( F_3 ( V_2 ) ) {
F_24 ( V_2 -> V_2 ) ;
F_25 ( V_2 -> V_2 , 5000 ) ;
F_26 ( V_2 -> V_2 ) ;
F_27 ( V_2 -> V_2 ) ;
F_28 ( V_2 -> V_2 ) ;
F_29 ( V_2 -> V_2 ) ;
}
V_35:
if ( V_9 )
F_2 ( V_2 ) ;
return V_9 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_36 * * V_37 ,
struct V_36 * V_38 ,
T_1 * V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_31 ( & V_4 -> V_40 . V_41 ) ;
if ( * V_39 == 1 ) {
if ( ! * V_37 )
* V_37 = V_38 ;
} else if ( * V_39 == 0 ) {
if ( * V_37 == V_38 )
* V_37 = NULL ;
}
* V_39 = * V_37 == V_38 ? 1 : 0 ;
F_32 ( & V_4 -> V_40 . V_41 ) ;
}
static int F_33 ( struct V_1 * V_2 , void * V_42 , struct V_36 * V_43 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_44 * V_45 = V_42 ;
struct V_46 * V_47 = & V_4 -> V_48 ;
T_1 * V_39 , V_49 , * V_50 , V_51 ;
T_2 V_52 ;
struct V_53 * V_54 ;
int V_55 , V_56 ;
V_50 = ( T_1 * ) ( ( unsigned long ) V_45 -> V_39 ) ;
V_39 = & V_49 ;
V_51 = sizeof( T_1 ) ;
switch ( V_45 -> V_57 ) {
case V_58 :
* V_39 = V_2 -> V_27 -> V_59 ;
break;
case V_60 :
* V_39 = V_4 -> V_61 ;
break;
case V_62 :
* V_39 = V_4 -> V_63 ;
break;
case V_64 :
if ( ( V_4 -> V_65 >= V_66 ) && ( V_4 -> V_65 <= V_67 ) )
* V_39 = false ;
else
* V_39 = V_4 -> V_68 ;
break;
case V_69 :
if ( F_34 ( V_39 , V_50 , sizeof( T_1 ) ) ) {
F_35 ( L_6 , V_70 , __LINE__ ) ;
return - V_71 ;
}
for ( V_55 = 0 , V_56 = 0 ; V_55 < V_4 -> V_72 ; V_55 ++ ) {
V_54 = (struct V_53 * ) V_47 -> V_73 [ V_55 ] ;
if ( V_54 && V_54 -> V_74 . V_75 == * V_39 ) {
struct V_76 * V_76 = F_36 ( V_54 ) ;
* V_39 = V_76 -> V_77 ;
V_56 = 1 ;
break;
}
}
if ( ! V_56 ) {
F_37 ( L_7 , * V_39 ) ;
return - V_78 ;
}
break;
case V_79 :
if ( V_4 -> V_65 == V_22 ) {
if ( V_4 -> V_68 ) {
if ( V_4 -> V_80 )
* V_39 = 3 ;
else
* V_39 = 2 ;
} else {
* V_39 = 0 ;
}
} else {
* V_39 = V_4 -> V_68 ;
}
break;
case V_81 :
if ( V_4 -> V_65 >= V_21 )
* V_39 = V_4 -> V_82 . V_83 . V_84 ;
else if ( V_4 -> V_65 >= V_13 )
* V_39 = V_4 -> V_82 . V_85 . V_84 ;
else if ( V_4 -> V_65 >= V_86 )
* V_39 = V_4 -> V_82 . V_87 . V_84 ;
else if ( V_4 -> V_65 >= V_66 )
* V_39 = V_4 -> V_82 . V_88 . V_84 ;
else if ( V_4 -> V_65 >= V_89 )
* V_39 = V_4 -> V_82 . V_90 . V_84 ;
else if ( V_4 -> V_65 >= V_91 )
* V_39 = V_4 -> V_82 . V_92 . V_84 ;
else {
F_37 ( L_8 ) ;
return - V_78 ;
}
break;
case V_93 :
if ( F_34 ( V_39 , V_50 , sizeof( T_1 ) ) ) {
F_35 ( L_6 , V_70 , __LINE__ ) ;
return - V_71 ;
}
if ( * V_39 >= 2 ) {
F_37 ( L_9 , * V_39 ) ;
return - V_78 ;
}
F_30 ( V_2 , & V_4 -> V_94 , V_43 , V_39 ) ;
break;
case V_95 :
if ( F_34 ( V_39 , V_50 , sizeof( T_1 ) ) ) {
F_35 ( L_6 , V_70 , __LINE__ ) ;
return - V_71 ;
}
if ( * V_39 >= 2 ) {
F_37 ( L_10 , * V_39 ) ;
return - V_78 ;
}
F_30 ( V_2 , & V_4 -> V_96 , V_43 , V_39 ) ;
break;
case V_97 :
if ( V_4 -> V_98 -> V_99 )
* V_39 = F_38 ( V_4 ) * 10 ;
else
* V_39 = V_4 -> clock . V_100 . V_101 * 10 ;
break;
case V_102 :
if ( V_4 -> V_65 >= V_21 )
* V_39 = V_4 -> V_82 . V_83 . V_103 *
V_4 -> V_82 . V_83 . V_104 ;
else if ( V_4 -> V_65 >= V_13 )
* V_39 = V_4 -> V_82 . V_85 . V_103 *
V_4 -> V_82 . V_85 . V_104 ;
else if ( V_4 -> V_65 >= V_86 )
* V_39 = V_4 -> V_82 . V_87 . V_103 *
V_4 -> V_82 . V_87 . V_104 ;
else if ( V_4 -> V_65 >= V_66 )
* V_39 = V_4 -> V_82 . V_88 . V_105 ;
else if ( V_4 -> V_65 >= V_89 )
* V_39 = V_4 -> V_82 . V_90 . V_105 ;
else if ( V_4 -> V_65 >= V_91 )
* V_39 = V_4 -> V_82 . V_92 . V_105 ;
else {
return - V_78 ;
}
break;
case V_106 :
if ( V_4 -> V_65 >= V_21 )
* V_39 = V_4 -> V_82 . V_83 . V_107 ;
else if ( V_4 -> V_65 >= V_13 )
* V_39 = V_4 -> V_82 . V_85 . V_107 ;
else if ( V_4 -> V_65 >= V_86 )
* V_39 = V_4 -> V_82 . V_87 . V_107 ;
else if ( V_4 -> V_65 >= V_66 )
* V_39 = V_4 -> V_82 . V_88 . V_107 ;
else if ( V_4 -> V_65 >= V_89 )
* V_39 = V_4 -> V_82 . V_90 . V_107 ;
else if ( V_4 -> V_65 >= V_91 )
* V_39 = V_4 -> V_82 . V_92 . V_107 ;
else {
return - V_78 ;
}
break;
case V_108 :
* V_39 = 1 ;
break;
case V_109 :
if ( V_4 -> V_65 >= V_21 )
* V_39 = V_4 -> V_82 . V_83 . V_110 ;
else if ( V_4 -> V_65 >= V_13 )
* V_39 = V_4 -> V_82 . V_85 . V_110 ;
else if ( V_4 -> V_65 >= V_86 )
* V_39 = V_4 -> V_82 . V_87 . V_110 ;
else if ( V_4 -> V_65 >= V_66 )
* V_39 = V_4 -> V_82 . V_88 . V_110 ;
else if ( V_4 -> V_65 >= V_89 )
* V_39 = V_4 -> V_82 . V_90 . V_110 ;
else if ( V_4 -> V_65 >= V_91 )
* V_39 = V_4 -> V_82 . V_92 . V_110 ;
else {
return - V_78 ;
}
break;
case V_111 :
if ( V_4 -> V_65 < V_86 )
return - V_78 ;
* V_39 = V_112 ;
break;
case V_113 :
if ( V_4 -> V_65 < V_86 )
return - V_78 ;
* V_39 = V_114 ;
break;
case V_115 :
if ( V_4 -> V_65 >= V_21 )
* V_39 = V_4 -> V_82 . V_83 . V_116 ;
else if ( V_4 -> V_65 >= V_13 )
* V_39 = V_4 -> V_82 . V_85 . V_116 ;
else if ( V_4 -> V_65 >= V_86 )
* V_39 = V_4 -> V_82 . V_87 . V_117 ;
else if ( V_4 -> V_65 >= V_66 )
* V_39 = V_4 -> V_82 . V_88 . V_118 ;
else if ( V_4 -> V_65 >= V_89 )
* V_39 = V_4 -> V_82 . V_90 . V_118 ;
else if ( V_4 -> V_65 >= V_91 )
* V_39 = V_4 -> V_82 . V_92 . V_118 ;
else {
return - V_78 ;
}
break;
case V_119 :
if ( V_4 -> V_65 < V_91 ) {
F_37 ( L_11 ) ;
return - V_78 ;
}
V_39 = ( T_1 * ) & V_52 ;
V_51 = sizeof( T_2 ) ;
V_52 = F_39 ( V_4 ) ;
break;
case V_120 :
if ( V_4 -> V_65 >= V_21 )
* V_39 = V_4 -> V_82 . V_83 . V_104 ;
else if ( V_4 -> V_65 >= V_13 )
* V_39 = V_4 -> V_82 . V_85 . V_104 ;
else if ( V_4 -> V_65 >= V_86 )
* V_39 = V_4 -> V_82 . V_87 . V_104 ;
else if ( V_4 -> V_65 >= V_66 )
* V_39 = V_4 -> V_82 . V_88 . V_121 ;
else
* V_39 = 1 ;
break;
case V_122 :
if ( V_4 -> V_65 >= V_21 )
* V_39 = V_4 -> V_82 . V_83 . V_123 ;
else if ( V_4 -> V_65 >= V_13 )
* V_39 = V_4 -> V_82 . V_85 . V_123 ;
else
return - V_78 ;
break;
case V_124 :
* V_39 = V_4 -> V_125 ;
break;
case V_126 :
if ( F_34 ( V_39 , V_50 , sizeof( T_1 ) ) ) {
F_35 ( L_6 , V_70 , __LINE__ ) ;
return - V_71 ;
}
switch ( * V_39 ) {
case V_127 :
case V_128 :
* V_39 = V_4 -> V_129 [ V_130 ] . V_131 ;
break;
case V_132 :
* V_39 = V_4 -> V_129 [ V_133 ] . V_131 ;
* V_39 |= V_4 -> V_129 [ V_134 ] . V_131 ;
break;
case V_135 :
* V_39 = V_4 -> V_129 [ V_136 ] . V_131 ;
break;
case V_137 :
* V_39 = V_4 -> V_129 [ V_138 ] . V_131 ;
break;
default:
return - V_78 ;
}
break;
case V_139 :
if ( V_4 -> V_65 >= V_21 ) {
V_39 = V_4 -> V_82 . V_83 . V_140 ;
V_51 = sizeof( T_1 ) * 32 ;
} else if ( V_4 -> V_65 >= V_13 ) {
V_39 = V_4 -> V_82 . V_85 . V_140 ;
V_51 = sizeof( T_1 ) * 32 ;
} else {
F_37 ( L_12 ) ;
return - V_78 ;
}
break;
case V_141 :
if ( V_4 -> V_65 >= V_21 ) {
V_39 = V_4 -> V_82 . V_83 . V_142 ;
V_51 = sizeof( T_1 ) * 16 ;
} else {
F_37 ( L_13 ) ;
return - V_78 ;
}
break;
case V_143 :
* V_39 = 1 ;
break;
case V_144 :
if ( V_4 -> V_65 >= V_21 ) {
* V_39 = V_4 -> V_82 . V_83 . V_145 ;
} else if ( V_4 -> V_65 >= V_13 ) {
* V_39 = V_4 -> V_82 . V_85 . V_145 ;
} else {
F_37 ( L_14 ) ;
}
break;
case V_146 :
if ( ( V_4 -> V_147 . V_148 == V_149 ) &&
V_4 -> V_147 . V_150 )
* V_39 = V_4 -> V_147 . V_151 . V_152 . V_153 . V_154 * 10 ;
else
* V_39 = V_4 -> V_147 . V_155 * 10 ;
break;
case V_156 :
* V_39 = V_4 -> V_157 . V_158 ;
break;
case V_159 :
* V_39 = V_4 -> V_157 . V_160 ;
break;
case V_161 :
V_39 = ( T_1 * ) & V_52 ;
V_51 = sizeof( T_2 ) ;
V_52 = F_40 ( & V_4 -> V_162 ) ;
break;
case V_163 :
V_39 = ( T_1 * ) & V_52 ;
V_51 = sizeof( T_2 ) ;
V_52 = F_40 ( & V_4 -> V_164 ) ;
break;
case V_165 :
V_39 = ( T_1 * ) & V_52 ;
V_51 = sizeof( T_2 ) ;
V_52 = F_40 ( & V_4 -> V_166 ) ;
break;
case V_167 :
if ( V_4 -> V_65 >= V_21 )
* V_39 = V_4 -> V_82 . V_83 . V_168 ;
else if ( V_4 -> V_65 >= V_13 )
* V_39 = V_4 -> V_82 . V_85 . V_168 ;
else if ( V_4 -> V_65 >= V_86 )
* V_39 = V_4 -> V_82 . V_87 . V_169 ;
else if ( V_4 -> V_65 >= V_66 )
* V_39 = V_4 -> V_82 . V_88 . V_169 ;
else if ( V_4 -> V_65 >= V_89 )
* V_39 = V_4 -> V_82 . V_90 . V_169 ;
else if ( V_4 -> V_65 >= V_91 )
* V_39 = V_4 -> V_82 . V_92 . V_169 ;
else
* V_39 = 1 ;
break;
case V_170 :
if ( V_4 -> V_98 -> V_147 . V_171 )
* V_39 = F_41 ( V_4 ) ;
else
* V_39 = 0 ;
break;
case V_172 :
if ( V_4 -> V_147 . V_150 )
* V_39 = F_42 ( V_4 ) / 100 ;
else
* V_39 = V_4 -> V_147 . V_173 / 100 ;
break;
case V_174 :
if ( V_4 -> V_147 . V_150 )
* V_39 = F_43 ( V_4 ) / 100 ;
else
* V_39 = V_4 -> V_147 . V_175 / 100 ;
break;
case V_176 :
if ( F_34 ( V_39 , V_50 , sizeof( T_1 ) ) ) {
F_35 ( L_6 , V_70 , __LINE__ ) ;
return - V_71 ;
}
if ( F_44 ( V_4 , * V_39 , V_39 ) )
return - V_78 ;
break;
case V_177 :
* V_39 = true ;
break;
case V_178 :
* V_39 = F_45 ( & V_4 -> V_179 ) ;
break;
default:
F_37 ( L_15 , V_45 -> V_57 ) ;
return - V_78 ;
}
if ( F_46 ( V_50 , ( char * ) V_39 , V_51 ) ) {
F_35 ( L_16 , V_70 , __LINE__ ) ;
return - V_71 ;
}
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_48 ( V_4 ) ;
F_49 () ;
}
int F_50 ( struct V_1 * V_2 , struct V_36 * V_180 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
V_180 -> V_181 = NULL ;
V_9 = F_4 ( V_2 -> V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_4 -> V_65 >= V_86 ) {
struct V_182 * V_183 ;
struct V_184 * V_185 ;
V_183 = F_13 ( sizeof( * V_183 ) , V_25 ) ;
if ( F_51 ( ! V_183 ) ) {
V_9 = - V_26 ;
goto V_186;
}
if ( V_4 -> V_68 ) {
V_185 = & V_183 -> V_185 ;
V_9 = F_52 ( V_4 , V_185 ) ;
if ( V_9 ) {
F_10 ( V_183 ) ;
goto V_186;
}
V_9 = F_53 ( V_4 -> V_187 . V_188 , false ) ;
if ( V_9 ) {
F_54 ( V_4 , V_185 ) ;
F_10 ( V_183 ) ;
goto V_186;
}
V_185 -> V_189 = F_55 ( V_4 , V_185 ,
V_4 -> V_187 . V_188 ) ;
V_9 = F_56 ( V_4 , V_185 -> V_189 ,
V_190 ,
V_191 |
V_192 ) ;
if ( V_9 ) {
F_54 ( V_4 , V_185 ) ;
F_10 ( V_183 ) ;
goto V_186;
}
}
V_180 -> V_181 = V_183 ;
}
V_186:
F_28 ( V_2 -> V_2 ) ;
F_29 ( V_2 -> V_2 ) ;
return V_9 ;
}
void F_57 ( struct V_1 * V_2 ,
struct V_36 * V_180 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_4 ( V_2 -> V_2 ) ;
F_31 ( & V_4 -> V_40 . V_41 ) ;
if ( V_4 -> V_94 == V_180 )
V_4 -> V_94 = NULL ;
if ( V_4 -> V_96 == V_180 )
V_4 -> V_96 = NULL ;
F_32 ( & V_4 -> V_40 . V_41 ) ;
F_58 ( V_4 , V_180 ) ;
F_59 ( V_4 , V_180 ) ;
if ( V_4 -> V_65 >= V_86 && V_180 -> V_181 ) {
struct V_182 * V_183 = V_180 -> V_181 ;
struct V_184 * V_185 = & V_183 -> V_185 ;
int V_9 ;
if ( V_4 -> V_68 ) {
V_9 = F_53 ( V_4 -> V_187 . V_188 , false ) ;
if ( ! V_9 ) {
if ( V_185 -> V_189 )
F_60 ( V_4 , V_185 -> V_189 ) ;
F_61 ( V_4 -> V_187 . V_188 ) ;
}
F_54 ( V_4 , V_185 ) ;
}
F_10 ( V_183 ) ;
V_180 -> V_181 = NULL ;
}
F_28 ( V_2 -> V_2 ) ;
F_29 ( V_2 -> V_2 ) ;
}
T_3 F_62 ( struct V_1 * V_2 , unsigned int V_193 )
{
int V_194 , V_195 , V_196 ;
T_3 V_197 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_193 >= V_4 -> V_72 ) {
F_35 ( L_17 , V_193 ) ;
return - V_78 ;
}
if ( V_4 -> V_48 . V_73 [ V_193 ] ) {
do {
V_197 = F_63 ( V_4 , V_193 ) ;
V_196 = F_64 (
V_2 , V_193 , V_198 ,
& V_194 , & V_195 , NULL , NULL ,
& V_4 -> V_48 . V_73 [ V_193 ] -> V_74 . V_199 ) ;
} while ( V_197 != F_63 ( V_4 , V_193 ) );
if ( ( ( V_196 & ( V_200 | V_201 ) ) !=
( V_200 | V_201 ) ) ) {
F_65 ( L_18 , V_196 ) ;
}
else {
F_65 ( L_19 ,
V_193 , V_194 ) ;
if ( V_194 >= 0 )
V_197 ++ ;
}
}
else {
V_197 = F_63 ( V_4 , V_193 ) ;
F_65 ( L_20 ) ;
}
return V_197 ;
}
int F_66 ( struct V_1 * V_2 , int V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_202 ;
int V_9 ;
if ( V_54 < 0 || V_54 >= V_4 -> V_72 ) {
F_35 ( L_21 , V_54 ) ;
return - V_78 ;
}
F_67 ( & V_4 -> V_203 . V_204 , V_202 ) ;
V_4 -> V_203 . V_205 [ V_54 ] = true ;
V_9 = F_68 ( V_4 ) ;
F_69 ( & V_4 -> V_203 . V_204 , V_202 ) ;
return V_9 ;
}
void F_70 ( struct V_1 * V_2 , int V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_202 ;
if ( V_54 < 0 || V_54 >= V_4 -> V_72 ) {
F_35 ( L_21 , V_54 ) ;
return;
}
F_67 ( & V_4 -> V_203 . V_204 , V_202 ) ;
V_4 -> V_203 . V_205 [ V_54 ] = false ;
F_68 ( V_4 ) ;
F_69 ( & V_4 -> V_203 . V_204 , V_202 ) ;
}
