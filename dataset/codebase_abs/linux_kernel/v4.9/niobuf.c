static int F_1 ( T_1 * V_1 , void * V_2 , int V_3 ,
T_2 V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , int V_9 , T_3 V_10 ,
unsigned int V_11 )
{
int V_12 ;
T_4 V_13 ;
F_2 ( V_9 != 0 ) ;
F_3 ( V_14 , L_1 , V_8 , F_4 ( V_8 -> V_15 ) ) ;
V_13 . V_16 = V_2 ;
V_13 . V_17 = V_3 ;
V_13 . V_18 = ( V_4 == V_19 ) ? 2 : 1 ;
V_13 . V_20 = V_21 ;
V_13 . V_22 = V_6 ;
V_13 . V_23 = V_24 ;
if ( F_5 ( V_4 == V_19 &&
F_6 ( V_25 ,
V_26 ) ) ) {
V_4 = V_27 ;
}
V_12 = F_7 ( V_13 , V_28 , V_1 ) ;
if ( F_5 ( V_12 != 0 ) ) {
F_8 ( L_2 , V_12 ) ;
F_2 ( V_12 == - V_29 ) ;
return - V_29 ;
}
F_3 ( V_30 , L_3 ,
V_3 , V_9 , V_10 , V_11 ) ;
V_12 = F_9 ( V_8 -> V_31 , * V_1 , V_4 ,
V_8 -> V_15 , V_9 , V_10 , V_11 , 0 ) ;
if ( F_5 ( V_12 != 0 ) ) {
int V_32 ;
F_8 ( L_4 ,
F_4 ( V_8 -> V_15 ) , V_9 , V_10 , V_12 ) ;
V_32 = F_10 ( * V_1 ) ;
F_11 ( V_32 == 0 , L_5 , V_32 ) ;
}
return 0 ;
}
static void F_12 ( T_1 * V_33 , int V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ )
F_10 ( V_33 [ V_35 ] ) ;
}
static int F_13 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
T_5 V_41 ;
int V_12 = 0 ;
int V_32 ;
int V_42 ;
int V_43 ;
T_3 V_10 ;
T_6 V_44 ;
T_4 V_13 ;
if ( F_14 ( V_45 ) )
return 0 ;
F_2 ( V_39 -> V_46 > 0 ) ;
F_2 ( V_39 -> V_47 == 0 ) ;
F_2 ( V_39 -> V_48 <= V_49 ) ;
F_2 ( V_39 -> V_50 <= V_51 ) ;
F_2 ( V_39 -> V_52 ) ;
F_2 ( V_39 -> V_53 == V_54 ||
V_39 -> V_53 == V_55 ) ;
if ( V_37 -> V_56 || V_37 -> V_57 == V_58 )
V_39 -> V_59 = 0 ;
else
F_2 ( V_39 -> V_59 == 0 ) ;
V_39 -> V_60 = 0 ;
V_41 = V_39 -> V_61 -> V_62 -> V_15 ;
F_2 ( V_39 -> V_63 . V_64 == V_65 ) ;
F_2 ( V_39 -> V_63 . V_66 == V_39 ) ;
V_10 = V_37 -> V_67 & ~ ( ( T_3 ) V_39 -> V_48 - 1 ) ;
F_11 ( ! ( V_39 -> V_68 &&
V_37 -> V_57 != V_58 ) ||
V_10 != V_39 -> V_69 ,
L_6 ,
V_39 -> V_68 , V_10 , V_39 -> V_69 ) ;
V_43 = ( V_39 -> V_50 + V_70 - 1 ) / V_70 ;
V_39 -> V_68 = 1 ;
V_39 -> V_69 = V_10 ;
V_39 -> V_47 = V_43 ;
V_13 . V_22 = & V_39 -> V_63 ;
V_13 . V_23 = V_24 ;
V_13 . V_18 = 1 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ , V_10 ++ ) {
V_13 . V_20 = V_21 |
( ( V_39 -> V_53 == V_55 ) ?
V_71 : V_72 ) ;
F_15 ( & V_13 , V_39 , V_42 ) ;
V_12 = F_16 ( V_39 -> V_73 , V_41 , V_10 , 0 ,
V_28 , V_74 , & V_44 ) ;
if ( V_12 != 0 ) {
F_8 ( L_7 ,
V_39 -> V_61 -> V_75 -> V_76 , V_10 ,
V_42 , V_12 ) ;
break;
}
V_12 = F_17 ( V_44 , V_13 , V_28 ,
& V_39 -> V_33 [ V_42 ] ) ;
if ( V_12 != 0 ) {
F_8 ( L_8 ,
V_39 -> V_61 -> V_75 -> V_76 , V_10 ,
V_42 , V_12 ) ;
V_32 = F_18 ( V_44 ) ;
F_2 ( V_32 == 0 ) ;
break;
}
}
if ( V_12 != 0 ) {
F_2 ( V_12 == - V_29 ) ;
F_19 ( & V_39 -> V_77 ) ;
V_39 -> V_47 -= V_43 - V_42 ;
F_20 ( & V_39 -> V_77 ) ;
F_2 ( V_39 -> V_47 >= 0 ) ;
F_12 ( V_39 -> V_33 , V_39 -> V_48 ) ;
V_37 -> V_78 = - V_29 ;
return - V_29 ;
}
V_37 -> V_67 = -- V_10 ;
F_11 ( V_39 -> V_69 == ( V_37 -> V_67 & V_79 ) ,
L_9 ,
V_39 -> V_69 , V_37 -> V_67 ) ;
F_19 ( & V_39 -> V_77 ) ;
if ( V_39 -> V_47 != V_43 )
F_21 ( L_10 ,
V_39 -> V_61 -> V_75 -> V_76 , F_4 ( V_41 ) ,
V_43 - V_39 -> V_47 ) ;
F_20 ( & V_39 -> V_77 ) ;
F_3 ( V_30 , L_11 ,
V_39 -> V_47 ,
V_39 -> V_53 == V_55 ? L_12 : L_13 ,
V_39 -> V_50 , V_39 -> V_46 ,
V_39 -> V_69 , V_37 -> V_67 , V_39 -> V_73 ) ;
return 0 ;
}
int F_22 ( struct V_36 * V_37 , int V_80 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
T_7 * V_81 ;
struct V_82 V_83 ;
int V_12 ;
F_2 ( ! F_23 () ) ;
if ( F_14 ( V_84 ) &&
V_80 && V_37 -> V_85 == 0 && V_86 == 0 )
V_37 -> V_85 = F_24 () + V_87 ;
if ( F_25 ( V_37 ) == 0 )
return 1 ;
F_2 ( V_39 -> V_52 == V_37 ) ;
F_12 ( V_39 -> V_33 , V_39 -> V_48 ) ;
if ( F_25 ( V_37 ) == 0 )
return 1 ;
F_26 ( V_37 , V_88 ) ;
if ( V_80 )
return 0 ;
if ( V_37 -> V_89 )
V_81 = & V_37 -> V_89 -> V_90 ;
else
V_81 = & V_37 -> V_91 ;
for (; ; ) {
V_83 = F_27 ( F_28 ( V_87 ) ,
F_28 ( 1 ) , NULL , NULL ) ;
V_12 = F_29 ( * V_81 , ! F_25 ( V_37 ) , & V_83 ) ;
if ( V_12 == 0 ) {
F_26 ( V_37 , V_37 -> V_92 ) ;
return 1 ;
}
F_2 ( V_12 == - V_93 ) ;
F_30 ( V_94 , V_37 , L_14 ,
V_39 ) ;
}
return 0 ;
}
static void F_31 ( struct V_36 * V_37 , int V_95 )
{
struct V_96 * V_97 = V_37 -> V_98 -> V_99 ;
struct V_100 * V_101 = V_97 -> V_102 ;
int V_103 = F_32 ( int , F_24 () -
V_37 -> V_104 . V_105 , 1 ) ;
if ( ! ( V_95 & V_106 ) &&
( V_37 -> V_107 != V_108 ) && V_37 -> V_109 &&
! ( F_33 ( V_37 -> V_109 ) &
( V_110 | V_111 |
V_112 | V_113 ) ) ) {
int V_114 = F_34 ( & V_97 -> V_115 , V_103 ) ;
if ( V_114 != 0 ) {
F_30 ( V_116 , V_37 ,
L_15 ,
V_101 -> V_117 , V_114 ,
F_35 ( & V_97 -> V_115 ) ) ;
}
}
F_36 ( V_37 -> V_118 , V_103 ) ;
if ( V_37 -> V_107 == V_108 && ! V_37 -> V_119 )
F_37 ( V_37 -> V_118 , 0 ) ;
else
F_37 ( V_37 -> V_118 ,
F_35 ( & V_97 -> V_115 ) ) ;
if ( V_37 -> V_109 &&
! ( F_38 ( V_37 -> V_109 ) & V_120 ) ) {
F_3 ( V_116 , L_16 ,
V_95 , F_33 ( V_37 -> V_109 ) ,
F_39 ( V_37 -> V_109 ) ,
F_39 ( V_37 -> V_118 ) , V_37 -> V_121 ) ;
}
}
int F_40 ( struct V_36 * V_37 , int V_95 )
{
struct V_122 * V_123 = V_37 -> V_124 ;
struct V_7 * V_8 ;
int V_12 ;
F_2 ( V_37 -> V_125 == 0 ) ;
F_2 ( V_37 -> V_126 ) ;
F_2 ( V_123 ) ;
F_2 ( ( V_95 & V_127 ) || ! V_123 -> V_128 ) ;
F_2 ( V_37 -> V_118 ) ;
F_2 ( V_37 -> V_118 == V_123 -> V_129 ) ;
F_2 ( V_123 -> V_130 . V_64 == V_131 ) ;
F_2 ( V_123 -> V_130 . V_66 == V_123 ) ;
if ( F_5 ( V_37 -> V_119 && V_37 -> V_119 -> V_132 &&
V_37 -> V_119 -> V_132 -> V_133 ) ) {
V_37 -> V_107 = V_108 ;
V_37 -> V_78 = - V_134 ;
F_3 ( V_135 , L_17 ,
V_37 -> V_119 -> V_132 -> V_136 ) ;
}
V_37 -> V_121 = F_41 ( V_37 -> V_118 , 0 ,
sizeof( struct V_137 ) , 1 ) ;
if ( V_37 -> V_107 != V_108 )
V_37 -> V_107 = V_138 ;
F_42 ( V_37 -> V_118 , V_37 -> V_107 ) ;
F_43 ( V_37 -> V_118 ,
F_44 ( V_37 -> V_78 ) ) ;
F_45 ( V_37 -> V_118 ,
V_37 -> V_109 ?
F_46 ( V_37 -> V_109 ) : 0 ) ;
F_47 ( V_37 ) ;
F_31 ( V_37 , V_95 ) ;
if ( ! V_37 -> V_119 || ! V_37 -> V_119 -> V_139 )
V_8 = F_48 ( V_37 -> V_140 , V_37 -> V_141 , NULL ) ;
else
V_8 = F_49 ( V_37 -> V_119 -> V_139 ) ;
if ( F_5 ( ! V_8 ) ) {
F_8 ( L_18 ) ;
return - V_142 ;
}
F_50 ( V_123 ) ;
V_12 = F_51 ( V_37 ) ;
if ( F_5 ( V_12 ) )
goto V_143;
V_37 -> V_144 = F_24 () ;
V_12 = F_1 ( & V_123 -> V_145 , V_123 -> V_146 , V_123 -> V_147 ,
( V_123 -> V_128 && ! V_123 -> V_148 ) ?
V_19 : V_27 ,
& V_123 -> V_130 , V_8 ,
F_52 ( V_37 ) -> V_149 ,
V_37 -> V_67 , V_37 -> V_150 ) ;
V_143:
if ( F_5 ( V_12 != 0 ) )
F_53 ( V_37 ) ;
F_54 ( V_8 ) ;
return V_12 ;
}
int F_55 ( struct V_36 * V_37 )
{
if ( V_37 -> V_125 )
return 0 ;
return F_40 ( V_37 , 0 ) ;
}
int F_56 ( struct V_36 * V_37 , int V_151 )
{
int V_12 ;
if ( V_37 -> V_125 )
return 0 ;
if ( ! V_37 -> V_118 ) {
V_12 = F_57 ( V_37 , 1 , NULL , NULL ) ;
if ( V_12 )
return V_12 ;
}
if ( V_37 -> V_78 != - V_152 && V_37 -> V_78 != - V_153 &&
V_37 -> V_78 != - V_154 && V_37 -> V_78 != - V_155 &&
V_37 -> V_78 != - V_156 && V_37 -> V_78 != - V_157 )
V_37 -> V_107 = V_108 ;
V_12 = F_40 ( V_37 , V_151 ) ;
return V_12 ;
}
int F_58 ( struct V_36 * V_37 )
{
return F_56 ( V_37 , 0 ) ;
}
int F_59 ( struct V_36 * V_158 , int V_159 )
{
int V_12 ;
int V_32 ;
int V_160 = 0 ;
struct V_7 * V_161 ;
T_6 V_162 ;
T_4 V_163 ;
struct V_164 * V_165 = V_158 -> V_166 ;
struct V_167 * V_168 = V_165 -> V_75 ;
if ( F_14 ( V_169 ) )
return 0 ;
F_2 ( V_158 -> V_107 == V_170 ) ;
F_2 ( V_158 -> V_171 == 0 ) ;
F_2 ( ! V_158 -> V_172 ) ;
F_2 ( ! ( ( F_33 ( V_158 -> V_109 ) & V_111 ) &&
( V_165 -> V_173 == V_174 ) ) ) ;
if ( F_5 ( V_168 && V_168 -> V_133 ) ) {
F_3 ( V_135 , L_19 ,
V_168 -> V_76 ) ;
F_19 ( & V_158 -> V_175 ) ;
V_158 -> V_176 = 1 ;
F_20 ( & V_158 -> V_175 ) ;
V_158 -> V_78 = - V_134 ;
return - V_134 ;
}
V_161 = V_165 -> V_62 ;
F_60 ( V_158 -> V_109 ,
& V_165 -> V_177 ) ;
F_42 ( V_158 -> V_109 , V_170 ) ;
F_61 ( V_158 -> V_109 , V_165 -> V_178 ) ;
F_62 ( V_158 -> V_109 , V_165 -> V_179 ) ;
F_2 ( V_180 || V_165 -> V_173 != V_174 ||
( V_165 -> V_179 & V_120 ) ||
! ( V_165 -> V_181 . V_182 &
V_183 ) ) ;
if ( V_158 -> V_56 )
F_63 ( V_158 -> V_109 , V_110 ) ;
if ( V_158 -> V_184 )
V_160 = F_64 () ;
V_12 = F_65 ( V_158 ) ;
if ( V_12 )
goto V_143;
if ( V_158 -> V_40 ) {
V_12 = F_13 ( V_158 ) ;
if ( V_12 != 0 )
goto V_143;
}
if ( ! V_159 ) {
F_2 ( V_158 -> V_121 != 0 ) ;
if ( ! V_158 -> V_185 ) {
F_2 ( ! V_158 -> V_186 ) ;
F_2 ( ! V_158 -> V_118 ) ;
V_12 = F_66 ( V_158 ,
V_158 -> V_121 ) ;
if ( V_12 ) {
F_19 ( & V_158 -> V_175 ) ;
V_158 -> V_176 = 1 ;
F_20 ( & V_158 -> V_175 ) ;
V_158 -> V_78 = V_12 ;
goto V_187;
}
} else {
V_158 -> V_186 = NULL ;
V_158 -> V_118 = NULL ;
}
V_12 = F_16 ( V_158 -> V_188 ,
V_161 -> V_15 , V_158 -> V_67 , 0 ,
V_28 , V_74 , & V_162 ) ;
if ( V_12 != 0 ) {
F_8 ( L_20 , V_12 ) ;
F_2 ( V_12 == - V_29 ) ;
V_12 = - V_29 ;
goto V_187;
}
}
F_19 ( & V_158 -> V_175 ) ;
V_158 -> V_189 = V_159 ;
V_158 -> V_172 = ! V_159 ;
V_158 -> V_190 = 0 ;
V_158 -> V_191 = 0 ;
V_158 -> V_176 = 0 ;
V_158 -> V_192 = 0 ;
V_158 -> V_193 = 0 ;
V_158 -> V_56 = 0 ;
V_158 -> V_194 = 0 ;
V_158 -> V_195 = 0 ;
F_20 ( & V_158 -> V_175 ) ;
if ( ! V_159 ) {
V_163 . V_16 = V_158 -> V_185 ;
V_163 . V_17 = V_158 -> V_196 ;
V_163 . V_18 = V_197 ;
V_163 . V_20 = V_21 | V_72 |
V_198 |
V_199 ;
V_163 . V_22 = & V_158 -> V_200 ;
V_163 . V_23 = V_24 ;
V_12 = F_17 ( V_162 , V_163 , V_201 ,
& V_158 -> V_202 ) ;
if ( V_12 != 0 ) {
F_8 ( L_21 , V_12 ) ;
F_2 ( V_12 == - V_29 ) ;
F_19 ( & V_158 -> V_175 ) ;
V_158 -> V_172 = 0 ;
F_20 ( & V_158 -> V_175 ) ;
V_12 = - V_29 ;
goto V_203;
}
F_3 ( V_30 , L_22 ,
V_158 -> V_196 , V_158 -> V_67 ,
V_158 -> V_188 ) ;
}
F_67 ( V_158 ) ;
if ( V_168 && V_168 -> V_204 )
F_68 ( V_168 -> V_204 , V_205 ,
F_69 ( & V_165 -> V_206 ) ) ;
F_70 ( V_207 , V_158 -> V_208 + 5 ) ;
F_71 ( & V_158 -> V_209 ) ;
V_158 -> V_144 = F_24 () ;
V_158 -> V_210 = V_158 -> V_144 + V_158 -> V_208 +
F_72 ( V_158 ) ;
F_73 ( V_165 ) ;
F_30 ( V_14 , V_158 , L_23 ,
F_33 ( V_158 -> V_109 ) ) ;
V_12 = F_1 ( & V_158 -> V_211 ,
V_158 -> V_126 , V_158 -> V_212 ,
V_27 , & V_158 -> V_213 ,
V_161 ,
V_158 -> V_214 ,
V_158 -> V_67 , 0 ) ;
if ( F_74 ( V_12 == 0 ) )
goto V_143;
V_158 -> V_190 = 1 ;
F_75 ( V_158 ) ;
if ( V_159 )
goto V_143;
V_203:
V_32 = F_18 ( V_162 ) ;
F_2 ( V_32 == 0 ) ;
F_2 ( ! V_158 -> V_172 ) ;
V_187:
F_22 ( V_158 , 0 ) ;
V_143:
if ( V_158 -> V_184 )
F_76 ( V_160 ) ;
return V_12 ;
}
int F_77 ( struct V_215 * V_216 )
{
struct V_100 * V_217 = V_216 -> V_99 -> V_102 ;
static T_5 V_218 = { V_219 , V_220 } ;
int V_12 ;
T_4 V_13 ;
T_6 V_44 ;
F_3 ( V_30 , L_24 ,
V_217 -> V_221 ) ;
if ( F_14 ( V_222 ) )
return - V_29 ;
V_12 = F_16 ( V_217 -> V_221 ,
V_218 , 0 , ~ 0 , V_28 ,
V_216 -> V_99 -> V_223 >= 0 ?
V_224 : V_74 , & V_44 ) ;
if ( V_12 != 0 ) {
F_8 ( L_20 , V_12 ) ;
return - V_29 ;
}
F_2 ( V_216 -> V_225 == 0 ) ;
V_216 -> V_225 = 1 ;
V_13 . V_16 = V_216 -> V_226 ;
V_13 . V_17 = V_217 -> V_227 ;
V_13 . V_228 = V_217 -> V_229 ;
V_13 . V_18 = V_197 ;
V_13 . V_20 = V_21 | V_72 | V_230 ;
V_13 . V_22 = & V_216 -> V_231 ;
V_13 . V_23 = V_24 ;
V_12 = F_17 ( V_44 , V_13 , V_28 , & V_216 -> V_232 ) ;
if ( V_12 == 0 )
return 0 ;
F_8 ( L_25 , V_12 ) ;
F_2 ( V_12 == - V_29 ) ;
V_12 = F_18 ( V_44 ) ;
F_2 ( V_12 == 0 ) ;
V_216 -> V_225 = 0 ;
return - V_29 ;
}
