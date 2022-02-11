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
struct V_101 * V_102 = NULL ;
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
goto V_115;
}
if ( V_9 -> V_34 & V_62 ) {
if ( V_105 > V_107 ) {
if ( V_106 != V_107 || F_36 ( V_9 ) ) {
V_17 = V_117 ;
goto V_115;
}
V_4 -> V_13 . V_105 = V_107 ;
} else {
if ( V_106 != V_105 ) {
V_17 = V_117 ;
goto V_115;
}
if ( ( F_36 ( V_9 ) != ( 0x3 & ( - V_105 ) ) ) ) {
V_17 = V_117 ;
goto V_115;
}
}
}
F_16 ( V_4 -> V_13 . V_118 ) ;
V_4 -> V_13 . V_118 = V_102 ;
return V_110 ;
V_115:
if ( V_102 )
F_8 ( V_102 ) ;
return V_17 ;
}
static enum V_15 F_37 ( struct V_3 * V_4 , void * V_119 ,
int V_120 )
{
int V_115 ;
struct V_1 * V_2 = F_38 ( V_4 -> V_89 . V_88 ) ;
V_115 = F_39 ( V_2 , V_4 -> V_112 , V_121 , & V_4 -> V_13 . V_77 -> V_122 ,
V_119 , V_120 , V_123 , NULL ) ;
if ( F_34 ( V_115 ) )
return ( V_115 == - V_124 ) ? V_117
: V_125 ;
return V_126 ;
}
static enum V_15 F_40 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
enum V_15 V_127 = V_126 ;
int V_115 ;
int V_120 = F_32 ( V_9 ) ;
V_115 = F_41 ( V_4 -> V_13 . V_118 , V_4 -> V_13 . V_103 , F_42 ( V_9 ) ,
V_120 , V_123 , NULL ) ;
if ( V_115 ) {
V_127 = V_114 ;
goto V_128;
}
V_4 -> V_13 . V_103 += V_120 ;
V_4 -> V_13 . V_105 -= V_120 ;
V_128:
return V_127 ;
}
static enum V_15 F_43 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
T_1 V_129 = F_30 ( V_9 ) ;
T_1 * V_130 ;
enum V_15 V_131 ;
struct V_101 * V_118 = V_4 -> V_13 . V_118 ;
if ( V_118 -> V_17 != V_132 ) {
V_131 = V_114 ;
goto V_128;
}
V_130 = F_44 ( V_118 , V_129 , sizeof( T_1 ) ) ;
if ( ! V_130 || ( V_133 ) V_130 & 7 ) {
V_131 = V_134 ;
goto V_128;
}
F_18 ( & V_135 ) ;
V_4 -> V_13 . V_136 = * V_130 ;
if ( V_9 -> V_11 == V_137 ||
V_9 -> V_11 == V_138 ) {
if ( * V_130 == F_45 ( V_9 ) )
* V_130 = F_46 ( V_9 ) ;
} else {
* V_130 += F_46 ( V_9 ) ;
}
F_20 ( & V_135 ) ;
V_131 = V_126 ;
V_128:
return V_131 ;
}
static struct V_5 * F_47 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_8 * V_139 ,
int V_11 ,
int V_140 ,
T_2 V_26 ,
T_3 V_141 ,
T_2 * V_142 )
{
struct V_1 * V_2 = F_38 ( V_4 -> V_89 . V_88 ) ;
struct V_5 * V_6 ;
T_2 V_143 = 0 ;
T_2 * V_144 ;
int V_145 ;
int V_146 ;
int V_115 ;
V_146 = ( - V_140 ) & 0x3 ;
V_145 = V_147 [ V_11 ] . V_148 + V_140 + V_146 + V_149 ;
V_6 = F_48 ( V_2 , & V_4 -> V_150 , V_145 , V_139 ) ;
if ( ! V_6 )
return NULL ;
V_139 -> V_4 = V_4 ;
V_139 -> V_11 = V_11 ;
V_139 -> V_34 = V_147 [ V_11 ] . V_34 ;
V_139 -> V_151 = V_9 -> V_151 ;
V_139 -> V_145 = V_145 ;
memcpy ( V_139 -> V_152 , V_9 -> V_152 , V_9 -> V_151 + V_153 ) ;
F_49 ( V_139 , V_11 ) ;
F_50 ( V_139 , V_4 -> V_59 . V_154 ) ;
F_51 ( V_139 , V_146 ) ;
F_52 ( V_139 , 0 ) ;
F_53 ( V_139 , V_26 ) ;
F_54 ( V_139 , 0 ) ;
V_139 -> V_26 = V_26 ;
if ( V_139 -> V_34 & V_155 ) {
F_55 ( V_139 , V_141 ) ;
F_56 ( V_139 , V_4 -> V_13 . V_156 ) ;
}
if ( V_139 -> V_34 & V_157 )
F_57 ( V_139 , V_4 -> V_13 . V_136 ) ;
V_115 = F_58 ( V_2 , V_139 , V_6 , & V_143 ) ;
if ( V_115 ) {
F_9 ( V_6 ) ;
return NULL ;
}
if ( V_142 ) {
* V_142 = V_143 ;
} else {
V_144 = F_42 ( V_139 ) + V_140 + F_36 ( V_139 ) ;
* V_144 = ~ V_143 ;
}
return V_6 ;
}
static enum V_15 F_59 ( struct V_3 * V_4 ,
struct V_8 * V_158 )
{
struct V_1 * V_2 = F_38 ( V_4 -> V_89 . V_88 ) ;
struct V_8 V_159 ;
struct V_5 * V_6 ;
int V_107 = V_4 -> V_107 ;
enum V_15 V_17 ;
int V_140 ;
int V_11 ;
int V_115 ;
struct V_160 * V_22 = V_4 -> V_13 . V_22 ;
T_2 V_161 ;
T_2 * V_144 ;
if ( ! V_22 ) {
V_22 = & V_4 -> V_13 . V_162 [ V_4 -> V_13 . V_163 ] ;
F_60 ( V_4 , V_22 ) ;
F_61 ( V_4 ) ;
V_22 -> type = V_58 ;
V_22 -> V_164 . V_103 = V_4 -> V_13 . V_103 ;
V_22 -> V_164 . V_165 = V_4 -> V_13 . V_103 ;
V_22 -> V_166 = V_158 -> V_26 ;
if ( F_29 ( V_158 ) ) {
V_22 -> V_167 = ( V_158 -> V_26 +
( F_29 ( V_158 ) + V_107 - 1 ) /
V_107 - 1 ) & V_168 ;
} else {
V_22 -> V_167 = V_22 -> V_166 ;
}
V_22 -> V_169 = V_158 -> V_26 ;
V_22 -> V_164 . V_105 = V_4 -> V_13 . V_105 ;
V_22 -> V_164 . V_148 = V_4 -> V_13 . V_105 ;
V_22 -> V_164 . V_104 = V_4 -> V_13 . V_104 ;
V_22 -> V_164 . V_118 = V_4 -> V_13 . V_118 ;
V_4 -> V_13 . V_118 = NULL ;
V_4 -> V_13 . V_22 = V_22 ;
V_22 -> V_17 = V_170 ;
}
if ( V_22 -> V_17 == V_170 ) {
if ( V_22 -> V_164 . V_105 <= V_107 )
V_11 = V_171 ;
else
V_11 = V_172 ;
} else {
if ( V_22 -> V_164 . V_105 > V_107 )
V_11 = V_173 ;
else
V_11 = V_174 ;
}
V_22 -> V_17 = V_175 ;
V_140 = F_62 ( int , V_22 -> V_164 . V_105 , V_107 ) ;
V_6 = F_47 ( V_4 , V_158 , & V_159 , V_11 , V_140 ,
V_22 -> V_169 , V_176 , & V_161 ) ;
if ( ! V_6 )
return V_80 ;
V_115 = F_41 ( V_22 -> V_164 . V_118 , V_22 -> V_164 . V_103 , F_42 ( & V_159 ) ,
V_140 , V_177 , & V_161 ) ;
if ( V_115 )
F_63 ( L_1 ) ;
V_144 = F_42 ( & V_159 ) + V_140 + F_36 ( & V_159 ) ;
* V_144 = ~ V_161 ;
V_115 = F_64 ( V_2 , V_4 , & V_159 , V_6 ) ;
if ( V_115 ) {
F_63 ( L_2 ) ;
F_9 ( V_6 ) ;
return V_80 ;
}
V_22 -> V_164 . V_103 += V_140 ;
V_22 -> V_164 . V_105 -= V_140 ;
V_22 -> V_169 = ( V_22 -> V_169 + 1 ) & V_168 ;
if ( V_22 -> V_164 . V_105 > 0 ) {
V_17 = V_178 ;
} else {
V_4 -> V_13 . V_22 = NULL ;
V_4 -> V_13 . V_11 = - 1 ;
if ( F_12 ( V_22 -> V_169 , V_4 -> V_13 . V_26 ) >= 0 )
V_4 -> V_13 . V_26 = V_22 -> V_169 ;
V_17 = V_29 ;
}
return V_17 ;
}
static void F_65 ( union V_179 * V_152 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 = F_66 ( V_9 ) ;
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
if ( V_6 -> V_180 == F_67 ( V_181 ) )
memcpy ( & V_152 -> V_182 , F_68 ( V_6 ) , sizeof( V_152 -> V_182 ) ) ;
else if ( V_6 -> V_180 == F_67 ( V_183 ) )
memcpy ( & V_152 -> V_184 , F_69 ( V_6 ) , sizeof( V_152 -> V_184 ) ) ;
}
static enum V_15 F_70 ( struct V_3 * V_4 , struct V_8 * V_9 )
{
enum V_15 V_115 ;
if ( V_9 -> V_34 & V_185 ) {
if ( F_13 ( V_4 ) == V_67 ||
F_13 ( V_4 ) == V_68 ||
F_13 ( V_4 ) == V_69 ) {
union V_179 V_152 ;
F_65 ( & V_152 , V_9 ) ;
V_115 = F_37 ( V_4 , & V_152 , sizeof( V_152 ) ) ;
if ( V_115 )
return V_115 ;
}
V_115 = F_37 ( V_4 , F_42 ( V_9 ) , F_32 ( V_9 ) ) ;
if ( V_115 )
return V_115 ;
} else if ( V_9 -> V_34 & V_62 ) {
V_115 = F_40 ( V_4 , V_9 ) ;
if ( V_115 )
return V_115 ;
} else if ( V_9 -> V_34 & V_58 ) {
V_4 -> V_13 . V_156 ++ ;
return V_23 ;
} else if ( V_9 -> V_34 & V_64 ) {
V_115 = F_43 ( V_4 , V_9 ) ;
if ( V_115 )
return V_115 ;
} else {
F_16 ( 1 ) ;
}
V_4 -> V_13 . V_26 = ( V_9 -> V_26 + 1 ) & V_168 ;
V_4 -> V_13 . V_11 = V_9 -> V_11 ;
V_4 -> V_13 . V_93 = V_186 ;
if ( V_9 -> V_34 & V_187 ) {
V_4 -> V_13 . V_156 ++ ;
return V_95 ;
} else if ( F_13 ( V_4 ) == V_27 )
return V_188 ;
else
return V_29 ;
}
static enum V_15 F_71 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_189 V_190 ;
struct V_191 * V_192 = & V_190 . V_193 ;
struct V_194 * V_195 = & V_190 . V_196 ;
struct V_76 * V_77 = V_4 -> V_13 . V_77 ;
if ( F_34 ( ! V_77 ) )
return V_29 ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_192 -> V_197 = V_77 -> V_197 ;
V_192 -> V_93 = V_4 -> V_13 . V_93 ;
V_192 -> V_4 = & V_4 -> V_89 ;
if ( V_192 -> V_93 == V_186 ) {
V_192 -> V_11 = ( V_9 -> V_34 & V_198 &&
V_9 -> V_34 & V_62 ) ?
V_199 : V_200 ;
V_192 -> V_201 = 0 ;
V_192 -> V_202 = V_77 -> V_122 . V_148 - V_77 -> V_122 . V_105 ;
if ( V_4 -> V_203 -> V_204 ) {
V_195 -> V_205 = V_206 ;
if ( V_9 -> V_34 & V_198 ) {
V_195 -> V_205 |= V_207 ;
V_195 -> V_208 . V_209 =
( V_210 V_211 ) F_72 ( V_9 ) ;
}
if ( V_9 -> V_34 & V_212 ) {
V_195 -> V_205 |= V_213 ;
V_195 -> V_208 . V_214 = F_73 ( V_9 ) ;
}
V_195 -> V_215 = V_4 -> V_89 . V_215 ;
if ( V_9 -> V_34 & V_216 )
V_195 -> V_217 = F_74 ( V_9 ) ;
V_195 -> V_218 = V_4 -> V_59 . V_218 ;
} else {
struct V_5 * V_6 = F_66 ( V_9 ) ;
V_192 -> V_205 = V_206 | V_219 ;
if ( V_6 -> V_180 == F_67 ( V_181 ) )
V_192 -> V_220 = V_221 ;
else
V_192 -> V_220 = V_222 ;
if ( V_9 -> V_34 & V_198 ) {
V_192 -> V_205 |= V_207 ;
V_192 -> V_208 . V_209 = F_72 ( V_9 ) ;
}
if ( V_9 -> V_34 & V_212 ) {
struct V_1 * V_2 = F_38 ( V_4 -> V_89 . V_88 ) ;
struct V_101 * V_223 ;
V_192 -> V_205 |= V_213 ;
V_192 -> V_208 . V_214 = F_73 ( V_9 ) ;
V_223 = F_75 ( & V_2 -> V_224 ,
V_192 -> V_208 . V_214 >> 8 ) ;
if ( F_34 ( ! V_223 ) ) {
F_63 ( L_3 ,
V_192 -> V_208 . V_214 ) ;
return V_225 ;
}
V_223 -> V_17 = V_116 ;
F_8 ( V_223 ) ;
}
V_192 -> V_4 = & V_4 -> V_89 ;
if ( V_9 -> V_34 & V_216 )
V_192 -> V_217 = F_74 ( V_9 ) ;
V_192 -> V_218 = V_4 -> V_59 . V_218 ;
}
}
if ( ! V_4 -> V_71 )
F_21 ( V_4 -> V_74 . V_75 ) ;
V_4 -> V_13 . V_77 = NULL ;
if ( F_76 ( V_4 -> V_203 , & V_190 , V_9 ? F_77 ( V_9 ) : 1 ) )
return V_226 ;
if ( V_4 -> V_13 . V_17 == V_18 )
return V_20 ;
if ( ! V_9 )
return V_178 ;
else if ( F_13 ( V_4 ) == V_27 )
return V_188 ;
else
return V_29 ;
}
static int F_78 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_3 V_141 , T_2 V_26 )
{
int V_115 = 0 ;
struct V_8 V_159 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = F_38 ( V_4 -> V_89 . V_88 ) ;
V_6 = F_47 ( V_4 , V_9 , & V_159 , V_227 ,
0 , V_26 , V_141 , NULL ) ;
if ( ! V_6 ) {
V_115 = - V_228 ;
goto V_229;
}
V_115 = F_64 ( V_2 , V_4 , & V_159 , V_6 ) ;
if ( V_115 ) {
F_79 ( L_4 ) ;
F_9 ( V_6 ) ;
}
V_229:
return V_115 ;
}
static int F_80 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_3 V_141 )
{
int V_127 = 0 ;
struct V_8 V_159 ;
struct V_5 * V_6 ;
struct V_5 * V_230 ;
struct V_1 * V_2 = F_38 ( V_4 -> V_89 . V_88 ) ;
struct V_160 * V_22 ;
V_6 = F_47 ( V_4 , V_9 , & V_159 ,
V_231 , 0 , V_9 -> V_26 ,
V_141 , NULL ) ;
if ( ! V_6 ) {
V_127 = - V_228 ;
goto V_128;
}
V_230 = F_81 ( V_6 , V_232 ) ;
if ( V_230 )
F_82 ( V_4 ) ;
else {
F_83 ( L_5 ) ;
V_127 = - V_228 ;
goto V_128;
}
V_22 = & V_4 -> V_13 . V_162 [ V_4 -> V_13 . V_163 ] ;
F_60 ( V_4 , V_22 ) ;
F_61 ( V_4 ) ;
memcpy ( F_2 ( V_6 ) , & V_159 , sizeof( V_6 -> V_233 ) ) ;
V_22 -> type = V_64 ;
V_22 -> V_234 . V_6 = V_6 ;
V_22 -> V_166 = V_159 . V_26 ;
V_22 -> V_167 = V_159 . V_26 ;
V_22 -> V_169 = V_159 . V_26 ;
V_127 = F_64 ( V_2 , V_4 , & V_159 , V_230 ) ;
if ( V_127 ) {
F_79 ( L_4 ) ;
F_8 ( V_4 ) ;
F_9 ( V_230 ) ;
}
V_128:
return V_127 ;
}
static enum V_15 F_84 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
if ( F_13 ( V_4 ) != V_27 )
return V_29 ;
if ( V_4 -> V_13 . V_235 != V_176 )
F_78 ( V_4 , V_9 , V_4 -> V_13 . V_235 , V_9 -> V_26 ) ;
else if ( V_9 -> V_34 & V_64 )
F_80 ( V_4 , V_9 , V_176 ) ;
else if ( F_85 ( V_9 ) )
F_78 ( V_4 , V_9 , V_176 , V_9 -> V_26 ) ;
return V_29 ;
}
static enum V_15 F_86 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 ;
if ( V_9 ) {
V_6 = F_7 ( & V_4 -> V_10 ) ;
F_8 ( V_4 ) ;
F_9 ( V_6 ) ;
}
if ( V_4 -> V_13 . V_118 ) {
F_8 ( V_4 -> V_13 . V_118 ) ;
V_4 -> V_13 . V_118 = NULL ;
}
return V_178 ;
}
static struct V_160 * F_87 ( struct V_3 * V_4 , T_2 V_26 )
{
int V_236 ;
for ( V_236 = 0 ; V_236 < V_4 -> V_59 . V_237 ; V_236 ++ ) {
struct V_160 * V_22 = & V_4 -> V_13 . V_162 [ V_236 ] ;
if ( V_22 -> type == 0 )
continue;
if ( F_12 ( V_26 , V_22 -> V_166 ) >= 0 &&
F_12 ( V_26 , V_22 -> V_167 ) <= 0 ) {
return V_22 ;
}
}
return NULL ;
}
static enum V_15 F_88 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
enum V_15 V_127 ;
T_2 V_238 = ( V_4 -> V_13 . V_26 - 1 ) & V_168 ;
if ( V_9 -> V_34 & V_185 ||
V_9 -> V_34 & V_62 ) {
if ( F_85 ( V_9 ) )
F_78 ( V_4 , V_9 , V_176 , V_238 ) ;
V_127 = V_29 ;
goto V_128;
} else if ( V_9 -> V_34 & V_58 ) {
struct V_160 * V_22 ;
V_22 = F_87 ( V_4 , V_9 -> V_26 ) ;
if ( ! V_22 ) {
V_127 = V_29 ;
goto V_128;
} else {
T_1 V_129 = F_27 ( V_9 ) ;
T_2 V_105 = F_29 ( V_9 ) ;
if ( V_129 < V_22 -> V_164 . V_165 ||
V_105 > V_22 -> V_164 . V_148 ||
( V_129 + V_105 ) > ( V_22 -> V_164 . V_165 +
V_22 -> V_164 . V_148 ) ) {
V_127 = V_29 ;
goto V_128;
}
if ( F_28 ( V_9 ) != V_22 -> V_164 . V_104 ) {
V_127 = V_29 ;
goto V_128;
}
V_22 -> V_169 = V_9 -> V_26 ;
V_22 -> V_17 = ( V_9 -> V_26 == V_22 -> V_166 ) ?
V_170 :
V_239 ;
V_22 -> V_164 . V_165 = V_129 ;
V_22 -> V_164 . V_103 = V_129 ;
V_22 -> V_164 . V_105 = V_105 ;
V_4 -> V_13 . V_22 = V_22 ;
V_127 = V_23 ;
goto V_128;
}
} else {
struct V_160 * V_22 ;
V_22 = F_87 ( V_4 , V_9 -> V_26 ) ;
if ( V_22 ) {
struct V_5 * V_230 ;
V_230 = F_81 ( V_22 -> V_234 . V_6 , V_232 ) ;
if ( V_230 ) {
F_82 ( V_4 ) ;
} else {
F_83 ( L_6 ) ;
V_127 = V_29 ;
goto V_128;
}
V_127 = F_64 ( F_38 ( V_4 -> V_89 . V_88 ) , V_4 ,
V_9 , V_230 ) ;
if ( V_127 ) {
F_63 ( L_7 ) ;
F_8 ( V_4 ) ;
F_9 ( V_230 ) ;
V_127 = V_29 ;
goto V_128;
}
}
V_127 = V_29 ;
goto V_128;
}
V_128:
return V_127 ;
}
static void F_89 ( struct V_3 * V_4 , T_3 V_141 ,
enum V_240 V_93 )
{
V_4 -> V_13 . V_235 = V_141 ;
V_4 -> V_13 . V_93 = V_93 ;
V_4 -> V_13 . V_241 = 1 ;
}
static enum V_15 F_90 ( struct V_3 * V_4 )
{
if ( V_4 -> V_71 ) {
V_4 -> V_13 . V_33 = 1 ;
if ( V_4 -> V_13 . V_77 ) {
V_4 -> V_13 . V_93 = V_242 ;
return V_95 ;
} else {
return V_29 ;
}
} else {
if ( V_4 -> V_13 . V_77 ) {
V_4 -> V_13 . V_77 -> V_122 . V_105 = V_4 -> V_13 . V_77 -> V_122 . V_148 ;
V_4 -> V_13 . V_77 -> V_122 . V_243 = 0 ;
V_4 -> V_13 . V_77 -> V_122 . V_244 = 0 ;
V_4 -> V_13 . V_11 = - 1 ;
}
if ( V_4 -> V_13 . V_118 ) {
F_8 ( V_4 -> V_13 . V_118 ) ;
V_4 -> V_13 . V_118 = NULL ;
}
return V_29 ;
}
}
void F_91 ( struct V_3 * V_4 , bool V_245 )
{
struct V_5 * V_6 ;
while ( ( V_6 = F_7 ( & V_4 -> V_10 ) ) ) {
F_8 ( V_4 ) ;
F_9 ( V_6 ) ;
}
while ( ! V_4 -> V_71 && V_4 -> V_74 . V_75 && F_19 ( V_4 -> V_74 . V_75 ) )
F_21 ( V_4 -> V_74 . V_75 ) ;
}
int F_92 ( void * V_246 )
{
struct V_3 * V_4 = (struct V_3 * ) V_246 ;
enum V_15 V_17 ;
struct V_8 * V_9 = NULL ;
int V_131 = 0 ;
F_82 ( V_4 ) ;
V_4 -> V_13 . V_235 = V_176 ;
if ( ! V_4 -> V_247 ) {
V_131 = - V_248 ;
goto V_249;
}
switch ( V_4 -> V_13 . V_17 ) {
case V_250 :
V_17 = V_251 ;
break;
default:
V_17 = V_19 ;
break;
}
while ( 1 ) {
F_93 ( L_8 , V_215 ( V_4 ) ,
V_252 [ V_17 ] ) ;
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
V_17 = F_70 ( V_4 , V_9 ) ;
break;
case V_95 :
V_17 = F_71 ( V_4 , V_9 ) ;
break;
case V_23 :
V_17 = F_59 ( V_4 , V_9 ) ;
break;
case V_188 :
V_17 = F_84 ( V_4 , V_9 ) ;
break;
case V_29 :
V_17 = F_86 ( V_4 , V_9 ) ;
break;
case V_31 :
V_17 = F_88 ( V_4 , V_9 ) ;
break;
case V_30 :
F_78 ( V_4 , V_9 , V_253 , V_4 -> V_13 . V_26 ) ;
V_17 = V_29 ;
break;
case V_98 :
case V_48 :
case V_43 :
case V_66 :
case V_134 :
F_89 ( V_4 , V_254 ,
V_242 ) ;
V_17 = V_95 ;
break;
case V_53 :
V_17 = F_90 ( V_4 ) ;
break;
case V_80 :
if ( F_13 ( V_4 ) == V_27 ) {
F_78 ( V_4 , V_9 , V_255 |
( ~ V_256 &
V_4 -> V_59 . V_257 ) ,
V_9 -> V_26 ) ;
} else {
V_4 -> V_13 . V_33 = 1 ;
}
V_17 = V_29 ;
break;
case V_114 :
if ( F_13 ( V_4 ) == V_27 ) {
F_89 ( V_4 , V_258 ,
V_259 ) ;
V_17 = V_95 ;
} else {
V_4 -> V_13 . V_33 = 1 ;
if ( V_4 -> V_71 ) {
V_4 -> V_13 . V_93 = V_259 ;
V_17 = V_95 ;
} else {
V_17 = V_29 ;
}
}
break;
case V_117 :
if ( F_13 ( V_4 ) == V_27 ) {
F_89 ( V_4 , V_254 ,
V_242 ) ;
V_17 = V_95 ;
} else if ( V_4 -> V_71 ) {
V_4 -> V_13 . V_93 = V_242 ;
V_17 = V_95 ;
} else {
V_4 -> V_13 . V_33 = 1 ;
V_17 = V_29 ;
}
break;
case V_125 :
F_89 ( V_4 , V_260 ,
V_261 ) ;
V_17 = V_95 ;
break;
case V_226 :
V_17 = V_225 ;
break;
case V_178 :
if ( V_4 -> V_13 . V_241 ) {
V_17 = V_225 ;
break;
}
goto V_249;
case V_21 :
if ( V_4 -> V_13 . V_241 ) {
V_17 = V_225 ;
break;
}
goto exit;
case V_251 :
F_91 ( V_4 , false ) ;
V_4 -> V_13 . V_77 = NULL ;
goto exit;
case V_225 :
V_4 -> V_13 . V_241 = 0 ;
F_83 ( L_9 , V_215 ( V_4 ) ) ;
F_94 ( V_4 ) ;
goto exit;
default:
F_16 ( 1 ) ;
}
}
exit:
V_131 = - V_262 ;
V_249:
F_8 ( V_4 ) ;
return V_131 ;
}
