void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_3 ( & V_4 -> V_10 , V_6 ) ;
V_7 = ( V_9 -> V_11 == V_12 ) ||
( F_4 ( & V_4 -> V_10 ) > 1 ) ;
F_5 ( & V_4 -> V_13 . V_14 , V_7 ) ;
}
static inline enum V_15 F_6 ( struct V_3 * V_4 ,
struct V_8 * * V_16 )
{
struct V_5 * V_6 ;
if ( V_4 -> V_13 . V_17 == V_18 ) {
V_6 = F_7 ( & V_4 -> V_10 ) ;
if ( V_6 ) {
F_8 ( V_4 ) ;
F_9 ( V_6 ) ;
return V_19 ;
}
return V_20 ;
}
V_6 = F_10 ( & V_4 -> V_10 ) ;
if ( ! V_6 )
return V_21 ;
* V_16 = F_2 ( V_6 ) ;
return ( V_4 -> V_13 . V_22 ) ? V_23 : V_24 ;
}
static enum V_15 F_11 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
int V_25 = F_12 ( V_9 -> V_26 , V_4 -> V_13 . V_26 ) ;
switch ( F_13 ( V_4 ) ) {
case V_27 :
if ( V_25 > 0 ) {
if ( V_4 -> V_13 . V_28 )
return V_29 ;
V_4 -> V_13 . V_28 = 1 ;
return V_30 ;
} else if ( V_25 < 0 ) {
return V_31 ;
}
if ( V_4 -> V_13 . V_28 )
V_4 -> V_13 . V_28 = 0 ;
break;
case V_32 :
if ( V_4 -> V_13 . V_33 || V_25 != 0 ) {
if ( V_9 -> V_34 & V_35 ) {
V_4 -> V_13 . V_33 = 0 ;
return V_36 ;
}
V_4 -> V_13 . V_33 = 1 ;
return V_29 ;
}
break;
default:
break;
}
return V_36 ;
}
static enum V_15 F_14 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
switch ( F_13 ( V_4 ) ) {
case V_27 :
switch ( V_4 -> V_13 . V_11 ) {
case V_37 :
case V_38 :
switch ( V_9 -> V_11 ) {
case V_38 :
case V_39 :
case V_40 :
case V_41 :
return V_42 ;
default:
return V_43 ;
}
case V_44 :
case V_45 :
switch ( V_9 -> V_11 ) {
case V_45 :
case V_46 :
case V_47 :
return V_42 ;
default:
return V_43 ;
}
default:
switch ( V_9 -> V_11 ) {
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_45 :
case V_46 :
case V_47 :
return V_48 ;
default:
return V_42 ;
}
}
break;
case V_32 :
switch ( V_4 -> V_13 . V_11 ) {
case V_49 :
case V_50 :
switch ( V_9 -> V_11 ) {
case V_50 :
case V_51 :
case V_52 :
return V_42 ;
default:
return V_53 ;
}
case V_54 :
case V_55 :
switch ( V_9 -> V_11 ) {
case V_55 :
case V_56 :
case V_57 :
return V_42 ;
default:
return V_53 ;
}
default:
switch ( V_9 -> V_11 ) {
case V_50 :
case V_51 :
case V_52 :
case V_55 :
case V_56 :
case V_57 :
V_4 -> V_13 . V_33 = 1 ;
return V_29 ;
default:
return V_42 ;
}
}
break;
default:
return V_42 ;
}
}
static enum V_15 F_15 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
switch ( F_13 ( V_4 ) ) {
case V_27 :
if ( ( ( V_9 -> V_34 & V_58 ) &&
! ( V_4 -> V_59 . V_60 & V_61 ) ) ||
( ( V_9 -> V_34 & V_62 ) &&
! ( V_4 -> V_59 . V_60 & V_63 ) ) ||
( ( V_9 -> V_34 & V_64 ) &&
! ( V_4 -> V_59 . V_60 & V_65 ) ) ) {
return V_66 ;
}
break;
case V_32 :
if ( ( V_9 -> V_34 & V_62 ) &&
! ( V_4 -> V_59 . V_60 & V_63 ) ) {
V_4 -> V_13 . V_33 = 1 ;
return V_29 ;
}
break;
case V_67 :
case V_68 :
case V_69 :
break;
default:
F_16 ( 1 ) ;
break;
}
return V_20 ;
}
static enum V_15 F_17 ( struct V_3 * V_4 )
{
struct V_70 * V_71 = V_4 -> V_71 ;
struct V_72 * V_73 = V_71 -> V_74 . V_75 ;
struct V_76 * V_77 ;
struct V_78 V_79 ;
if ( V_71 -> error )
return V_80 ;
F_18 ( & V_71 -> V_74 . V_81 ) ;
V_77 = F_19 ( V_73 ) ;
if ( ! V_77 ) {
F_20 ( & V_71 -> V_74 . V_81 ) ;
return V_80 ;
}
memcpy ( & V_4 -> V_13 . V_82 , V_77 , sizeof( V_4 -> V_13 . V_82 ) ) ;
V_4 -> V_13 . V_77 = & V_4 -> V_13 . V_82 . V_77 ;
F_21 ( V_73 ) ;
if ( V_71 -> V_83 && V_71 -> V_84 . V_85 &&
( F_22 ( V_73 ) < V_71 -> V_83 ) ) {
V_71 -> V_83 = 0 ;
goto V_86;
}
F_20 ( & V_71 -> V_74 . V_81 ) ;
return V_87 ;
V_86:
F_20 ( & V_71 -> V_74 . V_81 ) ;
V_79 . V_88 = V_4 -> V_89 . V_88 ;
V_79 . V_90 . V_71 = V_4 -> V_89 . V_71 ;
V_79 . V_86 = V_91 ;
V_71 -> V_84 . V_85 ( & V_79 , V_71 -> V_84 . V_92 ) ;
return V_87 ;
}
static enum V_15 F_23 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_70 * V_71 = V_4 -> V_71 ;
if ( V_4 -> V_13 . V_17 == V_18 ) {
if ( V_4 -> V_13 . V_77 ) {
V_4 -> V_13 . V_93 = V_94 ;
return V_95 ;
} else if ( ! V_71 ) {
V_4 -> V_13 . V_77 = F_19 ( V_4 -> V_74 . V_75 ) ;
if ( V_4 -> V_13 . V_77 ) {
V_4 -> V_13 . V_93 = V_94 ;
return V_95 ;
} else {
return V_21 ;
}
} else {
return V_21 ;
}
}
if ( V_9 -> V_34 & V_96 ) {
if ( F_24 ( V_4 -> V_59 . V_97 > 0 ) )
return V_87 ;
else
return V_98 ;
}
if ( V_9 -> V_34 & V_99 ) {
if ( V_71 )
return F_17 ( V_4 ) ;
V_4 -> V_13 . V_77 = F_19 ( V_4 -> V_74 . V_75 ) ;
return ( V_4 -> V_13 . V_77 ) ? V_87 : V_80 ;
}
return V_87 ;
}
static enum V_15 F_25 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
switch ( F_13 ( V_4 ) ) {
case V_27 :
return V_100 ;
case V_32 :
return V_100 ;
default:
return V_100 ;
}
}
static enum V_15 F_26 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_101 * V_102 ;
T_1 V_103 ;
T_2 V_104 ;
T_2 V_105 ;
T_2 V_106 ;
int V_107 = V_4 -> V_107 ;
enum V_15 V_17 ;
int V_108 ;
if ( V_9 -> V_34 & ( V_58 | V_62 ) ) {
if ( V_9 -> V_34 & V_109 ) {
V_4 -> V_13 . V_103 = F_27 ( V_9 ) ;
V_4 -> V_13 . V_104 = F_28 ( V_9 ) ;
V_4 -> V_13 . V_105 = F_29 ( V_9 ) ;
}
V_108 = ( V_9 -> V_34 & V_58 ) ? V_61
: V_63 ;
} else if ( V_9 -> V_34 & V_64 ) {
V_4 -> V_13 . V_103 = F_30 ( V_9 ) ;
V_4 -> V_13 . V_104 = F_31 ( V_9 ) ;
V_4 -> V_13 . V_105 = sizeof( T_1 ) ;
V_108 = V_65 ;
} else {
return V_110 ;
}
if ( ( V_9 -> V_34 & ( V_58 | V_111 ) ) &&
( V_9 -> V_34 & V_109 ) &&
F_29 ( V_9 ) == 0 ) {
return V_110 ;
}
V_103 = V_4 -> V_13 . V_103 ;
V_104 = V_4 -> V_13 . V_104 ;
V_105 = V_4 -> V_13 . V_105 ;
V_106 = F_32 ( V_9 ) ;
V_102 = F_33 ( V_4 -> V_112 , V_108 , V_104 , V_113 ) ;
if ( ! V_102 ) {
V_17 = V_114 ;
goto V_115;
}
if ( F_34 ( V_102 -> V_17 == V_116 ) ) {
V_17 = V_114 ;
goto V_115;
}
if ( F_35 ( V_102 , V_103 , V_105 ) ) {
V_17 = V_114 ;
goto V_117;
}
if ( V_9 -> V_34 & V_62 ) {
if ( V_105 > V_107 ) {
if ( V_106 != V_107 || F_36 ( V_9 ) ) {
V_17 = V_118 ;
goto V_117;
}
V_4 -> V_13 . V_105 = V_107 ;
} else {
if ( V_106 != V_105 ) {
V_17 = V_118 ;
goto V_117;
}
if ( ( F_36 ( V_9 ) != ( 0x3 & ( - V_105 ) ) ) ) {
V_17 = V_118 ;
goto V_117;
}
}
}
F_16 ( V_4 -> V_13 . V_119 ) ;
V_4 -> V_13 . V_119 = V_102 ;
return V_110 ;
V_117:
F_8 ( V_102 ) ;
V_115:
return V_17 ;
}
static enum V_15 F_37 ( struct V_3 * V_4 , void * V_120 ,
int V_121 )
{
int V_122 ;
struct V_1 * V_2 = F_38 ( V_4 -> V_89 . V_88 ) ;
V_122 = F_39 ( V_2 , V_4 -> V_112 , V_123 , & V_4 -> V_13 . V_77 -> V_124 ,
V_120 , V_121 , V_125 , NULL ) ;
if ( F_34 ( V_122 ) )
return ( V_122 == - V_126 ) ? V_118
: V_127 ;
return V_128 ;
}
static enum V_15 F_40 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
enum V_15 V_129 = V_128 ;
int V_122 ;
int V_121 = F_32 ( V_9 ) ;
V_122 = F_41 ( V_4 -> V_13 . V_119 , V_4 -> V_13 . V_103 , F_42 ( V_9 ) ,
V_121 , V_125 , NULL ) ;
if ( V_122 ) {
V_129 = V_114 ;
goto V_130;
}
V_4 -> V_13 . V_103 += V_121 ;
V_4 -> V_13 . V_105 -= V_121 ;
V_130:
return V_129 ;
}
static enum V_15 F_43 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
T_1 V_131 = F_30 ( V_9 ) ;
T_1 * V_132 ;
enum V_15 V_133 ;
struct V_101 * V_119 = V_4 -> V_13 . V_119 ;
if ( V_119 -> V_17 != V_134 ) {
V_133 = V_114 ;
goto V_130;
}
V_132 = F_44 ( V_119 , V_131 , sizeof( T_1 ) ) ;
if ( ! V_132 || ( V_135 ) V_132 & 7 ) {
V_133 = V_136 ;
goto V_130;
}
F_18 ( & V_137 ) ;
V_4 -> V_13 . V_138 = * V_132 ;
if ( V_9 -> V_11 == V_139 ||
V_9 -> V_11 == V_140 ) {
if ( * V_132 == F_45 ( V_9 ) )
* V_132 = F_46 ( V_9 ) ;
} else {
* V_132 += F_46 ( V_9 ) ;
}
F_20 ( & V_137 ) ;
V_133 = V_128 ;
V_130:
return V_133 ;
}
static struct V_5 * F_47 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_8 * V_141 ,
int V_11 ,
int V_142 ,
T_2 V_26 ,
T_3 V_143 ,
T_2 * V_144 )
{
struct V_1 * V_2 = F_38 ( V_4 -> V_89 . V_88 ) ;
struct V_5 * V_6 ;
T_2 V_145 = 0 ;
T_2 * V_146 ;
int V_147 ;
int V_148 ;
int V_122 ;
V_148 = ( - V_142 ) & 0x3 ;
V_147 = V_149 [ V_11 ] . V_150 + V_142 + V_148 + V_151 ;
V_6 = V_2 -> V_152 -> V_153 ( V_2 , & V_4 -> V_154 , V_147 , V_141 ) ;
if ( ! V_6 )
return NULL ;
V_141 -> V_4 = V_4 ;
V_141 -> V_11 = V_11 ;
V_141 -> V_34 = V_149 [ V_11 ] . V_34 ;
V_141 -> V_155 = V_9 -> V_155 ;
V_141 -> V_147 = V_147 ;
memcpy ( V_141 -> V_156 , V_9 -> V_156 , V_9 -> V_155 + V_157 ) ;
F_48 ( V_141 , V_11 ) ;
F_49 ( V_141 , V_4 -> V_59 . V_158 ) ;
F_50 ( V_141 , V_148 ) ;
F_51 ( V_141 , 0 ) ;
F_52 ( V_141 , V_26 ) ;
F_53 ( V_141 , 0 ) ;
V_141 -> V_26 = V_26 ;
if ( V_141 -> V_34 & V_159 ) {
F_54 ( V_141 , V_143 ) ;
F_55 ( V_141 , V_4 -> V_13 . V_160 ) ;
}
if ( V_141 -> V_34 & V_161 )
F_56 ( V_141 , V_4 -> V_13 . V_138 ) ;
V_122 = V_2 -> V_152 -> V_162 ( V_2 , V_141 , V_6 , & V_145 ) ;
if ( V_122 ) {
F_9 ( V_6 ) ;
return NULL ;
}
if ( V_144 ) {
* V_144 = V_145 ;
} else {
V_146 = F_42 ( V_141 ) + V_142 + F_36 ( V_141 ) ;
* V_146 = ~ V_145 ;
}
return V_6 ;
}
static enum V_15 F_57 ( struct V_3 * V_4 ,
struct V_8 * V_163 )
{
struct V_1 * V_2 = F_38 ( V_4 -> V_89 . V_88 ) ;
struct V_8 V_164 ;
struct V_5 * V_6 ;
int V_107 = V_4 -> V_107 ;
enum V_15 V_17 ;
int V_142 ;
int V_11 ;
int V_122 ;
struct V_165 * V_22 = V_4 -> V_13 . V_22 ;
T_2 V_166 ;
T_2 * V_146 ;
if ( ! V_22 ) {
V_22 = & V_4 -> V_13 . V_167 [ V_4 -> V_13 . V_168 ] ;
F_58 ( V_4 , V_22 ) ;
F_59 ( V_4 ) ;
V_22 -> type = V_58 ;
V_22 -> V_169 . V_103 = V_4 -> V_13 . V_103 ;
V_22 -> V_169 . V_170 = V_4 -> V_13 . V_103 ;
V_22 -> V_171 = V_163 -> V_26 ;
if ( F_29 ( V_163 ) ) {
V_22 -> V_172 = ( V_163 -> V_26 +
( F_29 ( V_163 ) + V_107 - 1 ) /
V_107 - 1 ) & V_173 ;
} else {
V_22 -> V_172 = V_22 -> V_171 ;
}
V_22 -> V_174 = V_163 -> V_26 ;
V_22 -> V_169 . V_105 = V_4 -> V_13 . V_105 ;
V_22 -> V_169 . V_150 = V_4 -> V_13 . V_105 ;
V_22 -> V_169 . V_104 = V_4 -> V_13 . V_104 ;
V_22 -> V_169 . V_119 = V_4 -> V_13 . V_119 ;
V_4 -> V_13 . V_119 = NULL ;
V_4 -> V_13 . V_22 = V_22 ;
V_22 -> V_17 = V_175 ;
}
if ( V_22 -> V_17 == V_175 ) {
if ( V_22 -> V_169 . V_105 <= V_107 )
V_11 = V_176 ;
else
V_11 = V_177 ;
} else {
if ( V_22 -> V_169 . V_105 > V_107 )
V_11 = V_178 ;
else
V_11 = V_179 ;
}
V_22 -> V_17 = V_180 ;
V_142 = F_60 ( int , V_22 -> V_169 . V_105 , V_107 ) ;
V_6 = F_47 ( V_4 , V_163 , & V_164 , V_11 , V_142 ,
V_22 -> V_174 , V_181 , & V_166 ) ;
if ( ! V_6 )
return V_80 ;
V_122 = F_41 ( V_22 -> V_169 . V_119 , V_22 -> V_169 . V_103 , F_42 ( & V_164 ) ,
V_142 , V_182 , & V_166 ) ;
if ( V_122 )
F_61 ( L_1 ) ;
V_146 = F_42 ( & V_164 ) + V_142 + F_36 ( & V_164 ) ;
* V_146 = ~ V_166 ;
V_122 = F_62 ( V_2 , V_4 , & V_164 , V_6 ) ;
if ( V_122 ) {
F_61 ( L_2 ) ;
F_9 ( V_6 ) ;
return V_80 ;
}
V_22 -> V_169 . V_103 += V_142 ;
V_22 -> V_169 . V_105 -= V_142 ;
V_22 -> V_174 = ( V_22 -> V_174 + 1 ) & V_173 ;
if ( V_22 -> V_169 . V_105 > 0 ) {
V_17 = V_183 ;
} else {
V_4 -> V_13 . V_22 = NULL ;
V_4 -> V_13 . V_11 = - 1 ;
if ( F_12 ( V_22 -> V_174 , V_4 -> V_13 . V_26 ) >= 0 )
V_4 -> V_13 . V_26 = V_22 -> V_174 ;
V_17 = V_29 ;
}
return V_17 ;
}
static void F_63 ( union V_184 * V_156 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 = F_64 ( V_9 ) ;
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
if ( V_6 -> V_185 == F_65 ( V_186 ) )
memcpy ( & V_156 -> V_187 , F_66 ( V_6 ) , sizeof( V_156 -> V_187 ) ) ;
else if ( V_6 -> V_185 == F_65 ( V_188 ) )
memcpy ( & V_156 -> V_189 , F_67 ( V_6 ) , sizeof( V_156 -> V_189 ) ) ;
}
static enum V_15 F_68 ( struct V_3 * V_4 , struct V_8 * V_9 )
{
enum V_15 V_122 ;
if ( V_9 -> V_34 & V_190 ) {
if ( F_13 ( V_4 ) == V_67 ||
F_13 ( V_4 ) == V_68 ||
F_13 ( V_4 ) == V_69 ) {
union V_184 V_156 ;
F_63 ( & V_156 , V_9 ) ;
V_122 = F_37 ( V_4 , & V_156 , sizeof( V_156 ) ) ;
if ( V_122 )
return V_122 ;
}
V_122 = F_37 ( V_4 , F_42 ( V_9 ) , F_32 ( V_9 ) ) ;
if ( V_122 )
return V_122 ;
} else if ( V_9 -> V_34 & V_62 ) {
V_122 = F_40 ( V_4 , V_9 ) ;
if ( V_122 )
return V_122 ;
} else if ( V_9 -> V_34 & V_58 ) {
V_4 -> V_13 . V_160 ++ ;
return V_23 ;
} else if ( V_9 -> V_34 & V_64 ) {
V_122 = F_43 ( V_4 , V_9 ) ;
if ( V_122 )
return V_122 ;
} else
F_16 ( 1 ) ;
V_4 -> V_13 . V_160 ++ ;
V_4 -> V_13 . V_26 = ( V_9 -> V_26 + 1 ) & V_173 ;
V_4 -> V_13 . V_11 = V_9 -> V_11 ;
V_4 -> V_13 . V_93 = V_191 ;
if ( V_9 -> V_34 & V_192 )
return V_95 ;
else if ( F_13 ( V_4 ) == V_27 )
return V_193 ;
else
return V_29 ;
}
static enum V_15 F_69 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_194 V_195 ;
struct V_196 * V_197 = & V_195 . V_198 ;
struct V_199 * V_200 = & V_195 . V_201 ;
struct V_76 * V_77 = V_4 -> V_13 . V_77 ;
if ( F_34 ( ! V_77 ) )
return V_29 ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_197 -> V_202 = V_77 -> V_202 ;
V_197 -> V_93 = V_4 -> V_13 . V_93 ;
V_197 -> V_4 = & V_4 -> V_89 ;
if ( V_197 -> V_93 == V_191 ) {
V_197 -> V_11 = ( V_9 -> V_34 & V_203 &&
V_9 -> V_34 & V_62 ) ?
V_204 : V_205 ;
V_197 -> V_206 = 0 ;
V_197 -> V_207 = V_77 -> V_124 . V_150 - V_77 -> V_124 . V_105 ;
if ( V_4 -> V_208 -> V_209 ) {
V_200 -> V_210 = V_211 ;
if ( V_9 -> V_34 & V_203 ) {
V_200 -> V_210 |= V_212 ;
V_200 -> V_213 . V_214 =
( V_215 V_216 ) F_70 ( V_9 ) ;
}
if ( V_9 -> V_34 & V_217 ) {
V_200 -> V_210 |= V_218 ;
V_200 -> V_213 . V_219 = F_71 ( V_9 ) ;
}
V_200 -> V_220 = V_4 -> V_89 . V_220 ;
if ( V_9 -> V_34 & V_221 )
V_200 -> V_222 = F_72 ( V_9 ) ;
V_200 -> V_223 = V_4 -> V_59 . V_223 ;
} else {
struct V_5 * V_6 = F_64 ( V_9 ) ;
V_197 -> V_210 = V_211 | V_224 ;
if ( V_6 -> V_185 == F_65 ( V_186 ) )
V_197 -> V_225 = V_226 ;
else
V_197 -> V_225 = V_227 ;
if ( V_9 -> V_34 & V_203 ) {
V_197 -> V_210 |= V_212 ;
V_197 -> V_213 . V_214 = F_70 ( V_9 ) ;
}
if ( V_9 -> V_34 & V_217 ) {
struct V_1 * V_2 = F_38 ( V_4 -> V_89 . V_88 ) ;
struct V_101 * V_228 ;
V_197 -> V_210 |= V_218 ;
V_197 -> V_213 . V_219 = F_71 ( V_9 ) ;
V_228 = F_73 ( & V_2 -> V_229 ,
V_197 -> V_213 . V_219 >> 8 ) ;
if ( F_34 ( ! V_228 ) ) {
F_61 ( L_3 ,
V_197 -> V_213 . V_219 ) ;
return V_230 ;
}
V_228 -> V_17 = V_116 ;
}
V_197 -> V_4 = & V_4 -> V_89 ;
if ( V_9 -> V_34 & V_221 )
V_197 -> V_222 = F_72 ( V_9 ) ;
V_197 -> V_223 = V_4 -> V_59 . V_223 ;
}
}
if ( ! V_4 -> V_71 )
F_21 ( V_4 -> V_74 . V_75 ) ;
V_4 -> V_13 . V_77 = NULL ;
if ( F_74 ( V_4 -> V_208 , & V_195 , V_9 ? F_75 ( V_9 ) : 1 ) )
return V_231 ;
if ( V_4 -> V_13 . V_17 == V_18 )
return V_20 ;
if ( ! V_9 )
return V_183 ;
else if ( F_13 ( V_4 ) == V_27 )
return V_193 ;
else
return V_29 ;
}
static int F_76 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_3 V_143 , T_2 V_26 )
{
int V_122 = 0 ;
struct V_8 V_164 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = F_38 ( V_4 -> V_89 . V_88 ) ;
V_6 = F_47 ( V_4 , V_9 , & V_164 , V_232 ,
0 , V_26 , V_143 , NULL ) ;
if ( ! V_6 ) {
V_122 = - V_233 ;
goto V_115;
}
V_122 = F_62 ( V_2 , V_4 , & V_164 , V_6 ) ;
if ( V_122 ) {
F_77 ( L_4 ) ;
F_9 ( V_6 ) ;
}
V_115:
return V_122 ;
}
static int F_78 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_3 V_143 )
{
int V_129 = 0 ;
struct V_8 V_164 ;
struct V_5 * V_6 ;
struct V_5 * V_234 ;
struct V_1 * V_2 = F_38 ( V_4 -> V_89 . V_88 ) ;
struct V_165 * V_22 ;
V_6 = F_47 ( V_4 , V_9 , & V_164 ,
V_235 , 0 , V_9 -> V_26 ,
V_143 , NULL ) ;
if ( ! V_6 ) {
V_129 = - V_233 ;
goto V_130;
}
V_234 = F_79 ( V_6 , V_236 ) ;
if ( V_234 )
F_80 ( V_4 ) ;
else {
F_81 ( L_5 ) ;
V_129 = - V_233 ;
goto V_130;
}
V_22 = & V_4 -> V_13 . V_167 [ V_4 -> V_13 . V_168 ] ;
F_58 ( V_4 , V_22 ) ;
F_59 ( V_4 ) ;
memcpy ( F_2 ( V_6 ) , & V_164 , sizeof( V_6 -> V_237 ) ) ;
V_22 -> type = V_64 ;
V_22 -> V_238 . V_6 = V_6 ;
V_22 -> V_171 = V_164 . V_26 ;
V_22 -> V_172 = V_164 . V_26 ;
V_22 -> V_174 = V_164 . V_26 ;
V_129 = F_62 ( V_2 , V_4 , & V_164 , V_234 ) ;
if ( V_129 ) {
F_77 ( L_4 ) ;
F_8 ( V_4 ) ;
F_9 ( V_234 ) ;
}
V_130:
return V_129 ;
}
static enum V_15 F_82 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
if ( F_13 ( V_4 ) != V_27 )
return V_29 ;
if ( V_4 -> V_13 . V_239 != V_181 )
F_76 ( V_4 , V_9 , V_4 -> V_13 . V_239 , V_9 -> V_26 ) ;
else if ( V_9 -> V_34 & V_64 )
F_78 ( V_4 , V_9 , V_181 ) ;
else if ( F_83 ( V_9 ) )
F_76 ( V_4 , V_9 , V_181 , V_9 -> V_26 ) ;
return V_29 ;
}
static enum V_15 F_84 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 ;
if ( V_9 ) {
V_6 = F_7 ( & V_4 -> V_10 ) ;
F_8 ( V_4 ) ;
F_9 ( V_6 ) ;
}
if ( V_4 -> V_13 . V_119 ) {
F_8 ( V_4 -> V_13 . V_119 ) ;
V_4 -> V_13 . V_119 = NULL ;
}
return V_183 ;
}
static struct V_165 * F_85 ( struct V_3 * V_4 , T_2 V_26 )
{
int V_240 ;
for ( V_240 = 0 ; V_240 < V_4 -> V_59 . V_241 ; V_240 ++ ) {
struct V_165 * V_22 = & V_4 -> V_13 . V_167 [ V_240 ] ;
if ( V_22 -> type == 0 )
continue;
if ( F_12 ( V_26 , V_22 -> V_171 ) >= 0 &&
F_12 ( V_26 , V_22 -> V_172 ) <= 0 ) {
return V_22 ;
}
}
return NULL ;
}
static enum V_15 F_86 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
enum V_15 V_129 ;
T_2 V_242 = ( V_4 -> V_13 . V_26 - 1 ) & V_173 ;
if ( V_9 -> V_34 & V_190 ||
V_9 -> V_34 & V_62 ) {
if ( F_83 ( V_9 ) )
F_76 ( V_4 , V_9 , V_181 , V_242 ) ;
V_129 = V_29 ;
goto V_130;
} else if ( V_9 -> V_34 & V_58 ) {
struct V_165 * V_22 ;
V_22 = F_85 ( V_4 , V_9 -> V_26 ) ;
if ( ! V_22 ) {
V_129 = V_29 ;
goto V_130;
} else {
T_1 V_131 = F_27 ( V_9 ) ;
T_2 V_105 = F_29 ( V_9 ) ;
if ( V_131 < V_22 -> V_169 . V_170 ||
V_105 > V_22 -> V_169 . V_150 ||
( V_131 + V_105 ) > ( V_22 -> V_169 . V_170 +
V_22 -> V_169 . V_150 ) ) {
V_129 = V_29 ;
goto V_130;
}
if ( F_28 ( V_9 ) != V_22 -> V_169 . V_104 ) {
V_129 = V_29 ;
goto V_130;
}
V_22 -> V_174 = V_9 -> V_26 ;
V_22 -> V_17 = ( V_9 -> V_26 == V_22 -> V_171 ) ?
V_175 :
V_243 ;
V_22 -> V_169 . V_170 = V_131 ;
V_22 -> V_169 . V_103 = V_131 ;
V_22 -> V_169 . V_105 = V_105 ;
V_4 -> V_13 . V_22 = V_22 ;
V_129 = V_23 ;
goto V_130;
}
} else {
struct V_165 * V_22 ;
V_22 = F_85 ( V_4 , V_9 -> V_26 ) ;
if ( V_22 ) {
struct V_5 * V_234 ;
V_234 = F_79 ( V_22 -> V_238 . V_6 , V_236 ) ;
if ( V_234 ) {
F_80 ( V_4 ) ;
} else {
F_81 ( L_6 ) ;
V_129 = V_29 ;
goto V_130;
}
V_129 = F_62 ( F_38 ( V_4 -> V_89 . V_88 ) , V_4 ,
V_9 , V_234 ) ;
if ( V_129 ) {
F_61 ( L_7 ) ;
F_8 ( V_4 ) ;
F_9 ( V_234 ) ;
V_129 = V_29 ;
goto V_130;
}
}
V_129 = V_29 ;
goto V_130;
}
V_130:
return V_129 ;
}
static void F_87 ( struct V_3 * V_4 , T_3 V_143 ,
enum V_244 V_93 )
{
V_4 -> V_13 . V_239 = V_143 ;
V_4 -> V_13 . V_93 = V_93 ;
V_4 -> V_13 . V_245 = 1 ;
}
static enum V_15 F_88 ( struct V_3 * V_4 )
{
if ( V_4 -> V_71 ) {
V_4 -> V_13 . V_33 = 1 ;
if ( V_4 -> V_13 . V_77 ) {
V_4 -> V_13 . V_93 = V_246 ;
return V_95 ;
} else {
return V_29 ;
}
} else {
if ( V_4 -> V_13 . V_77 ) {
V_4 -> V_13 . V_77 -> V_124 . V_105 = V_4 -> V_13 . V_77 -> V_124 . V_150 ;
V_4 -> V_13 . V_77 -> V_124 . V_247 = 0 ;
V_4 -> V_13 . V_77 -> V_124 . V_248 = 0 ;
V_4 -> V_13 . V_11 = - 1 ;
}
if ( V_4 -> V_13 . V_119 ) {
F_8 ( V_4 -> V_13 . V_119 ) ;
V_4 -> V_13 . V_119 = NULL ;
}
return V_29 ;
}
}
int F_89 ( void * V_249 )
{
struct V_3 * V_4 = (struct V_3 * ) V_249 ;
enum V_15 V_17 ;
struct V_8 * V_9 = NULL ;
int V_133 = 0 ;
F_80 ( V_4 ) ;
V_4 -> V_13 . V_239 = V_181 ;
if ( ! V_4 -> V_250 ) {
V_133 = - V_251 ;
goto V_252;
}
switch ( V_4 -> V_13 . V_17 ) {
case V_253 :
V_17 = V_254 ;
break;
default:
V_17 = V_19 ;
break;
}
while ( 1 ) {
F_90 ( L_8 , V_220 ( V_4 ) ,
V_255 [ V_17 ] ) ;
switch ( V_17 ) {
case V_19 :
V_17 = F_6 ( V_4 , & V_9 ) ;
break;
case V_24 :
V_17 = F_11 ( V_4 , V_9 ) ;
break;
case V_36 :
V_17 = F_14 ( V_4 , V_9 ) ;
break;
case V_42 :
V_17 = F_15 ( V_4 , V_9 ) ;
break;
case V_20 :
V_17 = F_23 ( V_4 , V_9 ) ;
break;
case V_87 :
V_17 = F_25 ( V_4 , V_9 ) ;
break;
case V_100 :
V_17 = F_26 ( V_4 , V_9 ) ;
break;
case V_110 :
V_17 = F_68 ( V_4 , V_9 ) ;
break;
case V_95 :
V_17 = F_69 ( V_4 , V_9 ) ;
break;
case V_23 :
V_17 = F_57 ( V_4 , V_9 ) ;
break;
case V_193 :
V_17 = F_82 ( V_4 , V_9 ) ;
break;
case V_29 :
V_17 = F_84 ( V_4 , V_9 ) ;
break;
case V_31 :
V_17 = F_86 ( V_4 , V_9 ) ;
break;
case V_30 :
F_76 ( V_4 , V_9 , V_256 , V_4 -> V_13 . V_26 ) ;
V_17 = V_29 ;
break;
case V_98 :
case V_48 :
case V_43 :
case V_66 :
case V_136 :
F_87 ( V_4 , V_257 ,
V_246 ) ;
V_17 = V_95 ;
break;
case V_53 :
V_17 = F_88 ( V_4 ) ;
break;
case V_80 :
if ( F_13 ( V_4 ) == V_27 ) {
F_76 ( V_4 , V_9 , V_258 |
( ~ V_259 &
V_4 -> V_59 . V_260 ) ,
V_9 -> V_26 ) ;
} else {
V_4 -> V_13 . V_33 = 1 ;
}
V_17 = V_29 ;
break;
case V_114 :
if ( F_13 ( V_4 ) == V_27 ) {
F_87 ( V_4 , V_261 ,
V_262 ) ;
V_17 = V_95 ;
} else {
V_4 -> V_13 . V_33 = 1 ;
if ( V_4 -> V_71 ) {
V_4 -> V_13 . V_93 = V_262 ;
V_17 = V_95 ;
} else {
V_17 = V_29 ;
}
}
break;
case V_118 :
if ( F_13 ( V_4 ) == V_27 ) {
F_87 ( V_4 , V_257 ,
V_246 ) ;
V_17 = V_95 ;
} else if ( V_4 -> V_71 ) {
V_4 -> V_13 . V_93 = V_246 ;
V_17 = V_95 ;
} else {
V_4 -> V_13 . V_33 = 1 ;
V_17 = V_29 ;
}
break;
case V_127 :
F_87 ( V_4 , V_263 ,
V_264 ) ;
V_17 = V_95 ;
break;
case V_231 :
V_17 = V_230 ;
break;
case V_183 :
if ( V_4 -> V_13 . V_245 ) {
V_17 = V_230 ;
break;
}
goto V_252;
case V_21 :
if ( V_4 -> V_13 . V_245 ) {
V_17 = V_230 ;
break;
}
goto exit;
case V_254 : {
struct V_5 * V_6 ;
while ( ( V_6 = F_7 ( & V_4 -> V_10 ) ) ) {
F_8 ( V_4 ) ;
F_9 ( V_6 ) ;
}
while ( ! V_4 -> V_71 && V_4 -> V_74 . V_75 &&
F_19 ( V_4 -> V_74 . V_75 ) )
F_21 ( V_4 -> V_74 . V_75 ) ;
V_4 -> V_13 . V_77 = NULL ;
goto exit;
}
case V_230 :
V_4 -> V_13 . V_245 = 0 ;
F_81 ( L_9 , V_220 ( V_4 ) ) ;
F_91 ( V_4 ) ;
goto exit;
default:
F_16 ( 1 ) ;
}
}
exit:
V_133 = - V_265 ;
V_252:
F_8 ( V_4 ) ;
return V_133 ;
}
