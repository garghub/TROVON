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
struct V_1 * V_2 = F_13 ( V_4 -> V_27 . V_28 ) ;
switch ( F_14 ( V_4 ) ) {
case V_29 :
if ( V_25 > 0 ) {
if ( V_4 -> V_13 . V_30 )
return V_31 ;
V_4 -> V_13 . V_30 = 1 ;
F_15 ( V_2 , V_32 ) ;
return V_33 ;
} else if ( V_25 < 0 ) {
F_15 ( V_2 , V_34 ) ;
return V_35 ;
}
if ( V_4 -> V_13 . V_30 )
V_4 -> V_13 . V_30 = 0 ;
break;
case V_36 :
if ( V_4 -> V_13 . V_37 || V_25 != 0 ) {
if ( V_9 -> V_38 & V_39 ) {
V_4 -> V_13 . V_37 = 0 ;
return V_40 ;
}
V_4 -> V_13 . V_37 = 1 ;
return V_31 ;
}
break;
default:
break;
}
return V_40 ;
}
static enum V_15 F_16 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
switch ( F_14 ( V_4 ) ) {
case V_29 :
switch ( V_4 -> V_13 . V_11 ) {
case V_41 :
case V_42 :
switch ( V_9 -> V_11 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
return V_46 ;
default:
return V_47 ;
}
case V_48 :
case V_49 :
switch ( V_9 -> V_11 ) {
case V_49 :
case V_50 :
case V_51 :
return V_46 ;
default:
return V_47 ;
}
default:
switch ( V_9 -> V_11 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_49 :
case V_50 :
case V_51 :
return V_52 ;
default:
return V_46 ;
}
}
break;
case V_36 :
switch ( V_4 -> V_13 . V_11 ) {
case V_53 :
case V_54 :
switch ( V_9 -> V_11 ) {
case V_54 :
case V_55 :
case V_56 :
return V_46 ;
default:
return V_57 ;
}
case V_58 :
case V_59 :
switch ( V_9 -> V_11 ) {
case V_59 :
case V_60 :
case V_61 :
return V_46 ;
default:
return V_57 ;
}
default:
switch ( V_9 -> V_11 ) {
case V_54 :
case V_55 :
case V_56 :
case V_59 :
case V_60 :
case V_61 :
V_4 -> V_13 . V_37 = 1 ;
return V_31 ;
default:
return V_46 ;
}
}
break;
default:
return V_46 ;
}
}
static enum V_15 F_17 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
switch ( F_14 ( V_4 ) ) {
case V_29 :
if ( ( ( V_9 -> V_38 & V_62 ) &&
! ( V_4 -> V_63 . V_64 & V_65 ) ) ||
( ( V_9 -> V_38 & V_66 ) &&
! ( V_4 -> V_63 . V_64 & V_67 ) ) ||
( ( V_9 -> V_38 & V_68 ) &&
! ( V_4 -> V_63 . V_64 & V_69 ) ) ) {
return V_70 ;
}
break;
case V_36 :
if ( ( V_9 -> V_38 & V_66 ) &&
! ( V_4 -> V_63 . V_64 & V_67 ) ) {
V_4 -> V_13 . V_37 = 1 ;
return V_31 ;
}
break;
case V_71 :
case V_72 :
case V_73 :
break;
default:
F_18 ( 1 ) ;
break;
}
return V_20 ;
}
static enum V_15 F_19 ( struct V_3 * V_4 )
{
struct V_74 * V_75 = V_4 -> V_75 ;
struct V_76 * V_77 = V_75 -> V_78 . V_79 ;
struct V_80 * V_81 ;
struct V_82 V_83 ;
if ( V_75 -> error )
return V_84 ;
F_20 ( & V_75 -> V_78 . V_85 ) ;
V_81 = F_21 ( V_77 ) ;
if ( ! V_81 ) {
F_22 ( & V_75 -> V_78 . V_85 ) ;
return V_84 ;
}
memcpy ( & V_4 -> V_13 . V_86 , V_81 , sizeof( V_4 -> V_13 . V_86 ) ) ;
V_4 -> V_13 . V_81 = & V_4 -> V_13 . V_86 . V_81 ;
F_23 ( V_77 ) ;
if ( V_75 -> V_87 && V_75 -> V_88 . V_89 &&
( F_24 ( V_77 ) < V_75 -> V_87 ) ) {
V_75 -> V_87 = 0 ;
goto V_90;
}
F_22 ( & V_75 -> V_78 . V_85 ) ;
return V_91 ;
V_90:
F_22 ( & V_75 -> V_78 . V_85 ) ;
V_83 . V_28 = V_4 -> V_27 . V_28 ;
V_83 . V_92 . V_75 = V_4 -> V_27 . V_75 ;
V_83 . V_90 = V_93 ;
V_75 -> V_88 . V_89 ( & V_83 , V_75 -> V_88 . V_94 ) ;
return V_91 ;
}
static enum V_15 F_25 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_74 * V_75 = V_4 -> V_75 ;
if ( V_4 -> V_13 . V_17 == V_18 ) {
if ( V_4 -> V_13 . V_81 ) {
V_4 -> V_13 . V_95 = V_96 ;
return V_97 ;
} else if ( ! V_75 ) {
V_4 -> V_13 . V_81 = F_21 ( V_4 -> V_78 . V_79 ) ;
if ( V_4 -> V_13 . V_81 ) {
V_4 -> V_13 . V_95 = V_96 ;
return V_97 ;
} else {
return V_21 ;
}
} else {
return V_21 ;
}
}
if ( V_9 -> V_38 & V_98 ) {
if ( F_26 ( V_4 -> V_63 . V_99 > 0 ) )
return V_91 ;
else
return V_100 ;
}
if ( V_9 -> V_38 & V_101 ) {
if ( V_75 )
return F_19 ( V_4 ) ;
V_4 -> V_13 . V_81 = F_21 ( V_4 -> V_78 . V_79 ) ;
return ( V_4 -> V_13 . V_81 ) ? V_91 : V_84 ;
}
return V_91 ;
}
static enum V_15 F_27 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
switch ( F_14 ( V_4 ) ) {
case V_29 :
return V_102 ;
case V_36 :
return V_102 ;
default:
return V_102 ;
}
}
static enum V_15 F_28 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_103 * V_104 = NULL ;
T_1 V_105 ;
T_2 V_106 ;
T_2 V_107 ;
T_2 V_108 ;
int V_109 = V_4 -> V_109 ;
enum V_15 V_17 ;
int V_110 ;
if ( V_9 -> V_38 & ( V_62 | V_66 ) ) {
if ( V_9 -> V_38 & V_111 ) {
V_4 -> V_13 . V_105 = F_29 ( V_9 ) ;
V_4 -> V_13 . V_106 = F_30 ( V_9 ) ;
V_4 -> V_13 . V_107 = F_31 ( V_9 ) ;
}
V_110 = ( V_9 -> V_38 & V_62 ) ? V_65
: V_67 ;
} else if ( V_9 -> V_38 & V_68 ) {
V_4 -> V_13 . V_105 = F_32 ( V_9 ) ;
V_4 -> V_13 . V_106 = F_33 ( V_9 ) ;
V_4 -> V_13 . V_107 = sizeof( T_1 ) ;
V_110 = V_69 ;
} else {
return V_112 ;
}
if ( ( V_9 -> V_38 & ( V_62 | V_113 ) ) &&
( V_9 -> V_38 & V_111 ) &&
F_31 ( V_9 ) == 0 ) {
return V_112 ;
}
V_105 = V_4 -> V_13 . V_105 ;
V_106 = V_4 -> V_13 . V_106 ;
V_107 = V_4 -> V_13 . V_107 ;
V_108 = F_34 ( V_9 ) ;
V_104 = F_35 ( V_4 -> V_114 , V_110 , V_106 , V_115 ) ;
if ( ! V_104 ) {
V_17 = V_116 ;
goto V_117;
}
if ( F_36 ( V_104 -> V_17 == V_118 ) ) {
V_17 = V_116 ;
goto V_117;
}
if ( F_37 ( V_104 , V_105 , V_107 ) ) {
V_17 = V_116 ;
goto V_117;
}
if ( V_9 -> V_38 & V_66 ) {
if ( V_107 > V_109 ) {
if ( V_108 != V_109 || F_38 ( V_9 ) ) {
V_17 = V_119 ;
goto V_117;
}
} else {
if ( V_108 != V_107 ) {
V_17 = V_119 ;
goto V_117;
}
if ( ( F_38 ( V_9 ) != ( 0x3 & ( - V_107 ) ) ) ) {
V_17 = V_119 ;
goto V_117;
}
}
}
F_18 ( V_4 -> V_13 . V_120 ) ;
V_4 -> V_13 . V_120 = V_104 ;
return V_112 ;
V_117:
if ( V_104 )
F_8 ( V_104 ) ;
return V_17 ;
}
static enum V_15 F_39 ( struct V_3 * V_4 , void * V_121 ,
int V_122 )
{
int V_117 ;
struct V_1 * V_2 = F_13 ( V_4 -> V_27 . V_28 ) ;
V_117 = F_40 ( V_2 , V_4 -> V_114 , V_123 , & V_4 -> V_13 . V_81 -> V_124 ,
V_121 , V_122 , V_125 , NULL ) ;
if ( F_36 ( V_117 ) )
return ( V_117 == - V_126 ) ? V_119
: V_127 ;
return V_128 ;
}
static enum V_15 F_41 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
enum V_15 V_129 = V_128 ;
int V_117 ;
int V_122 = F_34 ( V_9 ) ;
V_117 = F_42 ( V_4 -> V_13 . V_120 , V_4 -> V_13 . V_105 , F_43 ( V_9 ) ,
V_122 , V_125 , NULL ) ;
if ( V_117 ) {
V_129 = V_116 ;
goto V_130;
}
V_4 -> V_13 . V_105 += V_122 ;
V_4 -> V_13 . V_107 -= V_122 ;
V_130:
return V_129 ;
}
static enum V_15 F_44 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
T_1 V_131 = F_32 ( V_9 ) ;
T_1 * V_132 ;
enum V_15 V_133 ;
struct V_103 * V_120 = V_4 -> V_13 . V_120 ;
if ( V_120 -> V_17 != V_134 ) {
V_133 = V_116 ;
goto V_130;
}
V_132 = F_45 ( V_120 , V_131 , sizeof( T_1 ) ) ;
if ( ! V_132 || ( V_135 ) V_132 & 7 ) {
V_133 = V_136 ;
goto V_130;
}
F_20 ( & V_137 ) ;
V_4 -> V_13 . V_138 = * V_132 ;
if ( V_9 -> V_11 == V_139 ||
V_9 -> V_11 == V_140 ) {
if ( * V_132 == F_46 ( V_9 ) )
* V_132 = F_47 ( V_9 ) ;
} else {
* V_132 += F_47 ( V_9 ) ;
}
F_22 ( & V_137 ) ;
V_133 = V_128 ;
V_130:
return V_133 ;
}
static struct V_5 * F_48 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_8 * V_141 ,
int V_11 ,
int V_142 ,
T_2 V_26 ,
T_3 V_143 ,
T_2 * V_144 )
{
struct V_1 * V_2 = F_13 ( V_4 -> V_27 . V_28 ) ;
struct V_5 * V_6 ;
T_2 V_145 = 0 ;
T_2 * V_146 ;
int V_147 ;
int V_148 ;
int V_117 ;
V_148 = ( - V_142 ) & 0x3 ;
V_147 = V_149 [ V_11 ] . V_150 + V_142 + V_148 + V_151 ;
V_6 = F_49 ( V_2 , & V_4 -> V_152 , V_147 , V_141 ) ;
if ( ! V_6 )
return NULL ;
V_141 -> V_4 = V_4 ;
V_141 -> V_11 = V_11 ;
V_141 -> V_38 = V_149 [ V_11 ] . V_38 ;
V_141 -> V_153 = V_9 -> V_153 ;
V_141 -> V_147 = V_147 ;
memcpy ( V_141 -> V_154 , V_9 -> V_154 , V_9 -> V_153 + V_155 ) ;
F_50 ( V_141 , V_11 ) ;
F_51 ( V_141 , V_4 -> V_63 . V_156 ) ;
F_52 ( V_141 , V_148 ) ;
F_53 ( V_141 , 0 ) ;
F_54 ( V_141 , V_26 ) ;
F_55 ( V_141 , 0 ) ;
V_141 -> V_26 = V_26 ;
if ( V_141 -> V_38 & V_157 ) {
F_56 ( V_141 , V_143 ) ;
F_57 ( V_141 , V_4 -> V_13 . V_158 ) ;
}
if ( V_141 -> V_38 & V_159 )
F_58 ( V_141 , V_4 -> V_13 . V_138 ) ;
V_117 = F_59 ( V_2 , V_141 , V_6 , & V_145 ) ;
if ( V_117 ) {
F_9 ( V_6 ) ;
return NULL ;
}
if ( V_144 ) {
* V_144 = V_145 ;
} else {
V_146 = F_43 ( V_141 ) + V_142 + F_38 ( V_141 ) ;
* V_146 = ~ V_145 ;
}
return V_6 ;
}
static enum V_15 F_60 ( struct V_3 * V_4 ,
struct V_8 * V_160 )
{
struct V_1 * V_2 = F_13 ( V_4 -> V_27 . V_28 ) ;
struct V_8 V_161 ;
struct V_5 * V_6 ;
int V_109 = V_4 -> V_109 ;
enum V_15 V_17 ;
int V_142 ;
int V_11 ;
int V_117 ;
struct V_162 * V_22 = V_4 -> V_13 . V_22 ;
T_2 V_163 ;
T_2 * V_146 ;
if ( ! V_22 ) {
V_22 = & V_4 -> V_13 . V_164 [ V_4 -> V_13 . V_165 ] ;
F_61 ( V_4 , V_22 ) ;
F_62 ( V_4 ) ;
V_22 -> type = V_62 ;
V_22 -> V_166 . V_105 = V_4 -> V_13 . V_105 ;
V_22 -> V_166 . V_167 = V_4 -> V_13 . V_105 ;
V_22 -> V_168 = V_160 -> V_26 ;
if ( F_31 ( V_160 ) ) {
V_22 -> V_169 = ( V_160 -> V_26 +
( F_31 ( V_160 ) + V_109 - 1 ) /
V_109 - 1 ) & V_170 ;
} else {
V_22 -> V_169 = V_22 -> V_168 ;
}
V_22 -> V_171 = V_160 -> V_26 ;
V_22 -> V_166 . V_107 = V_4 -> V_13 . V_107 ;
V_22 -> V_166 . V_150 = V_4 -> V_13 . V_107 ;
V_22 -> V_166 . V_106 = V_4 -> V_13 . V_106 ;
V_22 -> V_166 . V_120 = V_4 -> V_13 . V_120 ;
V_4 -> V_13 . V_120 = NULL ;
V_4 -> V_13 . V_22 = V_22 ;
V_22 -> V_17 = V_172 ;
}
if ( V_22 -> V_17 == V_172 ) {
if ( V_22 -> V_166 . V_107 <= V_109 )
V_11 = V_173 ;
else
V_11 = V_174 ;
} else {
if ( V_22 -> V_166 . V_107 > V_109 )
V_11 = V_175 ;
else
V_11 = V_176 ;
}
V_22 -> V_17 = V_177 ;
V_142 = F_63 ( int , V_22 -> V_166 . V_107 , V_109 ) ;
V_6 = F_48 ( V_4 , V_160 , & V_161 , V_11 , V_142 ,
V_22 -> V_171 , V_178 , & V_163 ) ;
if ( ! V_6 )
return V_84 ;
V_117 = F_42 ( V_22 -> V_166 . V_120 , V_22 -> V_166 . V_105 , F_43 ( & V_161 ) ,
V_142 , V_179 , & V_163 ) ;
if ( V_117 )
F_64 ( L_1 ) ;
V_146 = F_43 ( & V_161 ) + V_142 + F_38 ( & V_161 ) ;
* V_146 = ~ V_163 ;
V_117 = F_65 ( V_2 , V_4 , & V_161 , V_6 ) ;
if ( V_117 ) {
F_64 ( L_2 ) ;
F_9 ( V_6 ) ;
return V_84 ;
}
V_22 -> V_166 . V_105 += V_142 ;
V_22 -> V_166 . V_107 -= V_142 ;
V_22 -> V_171 = ( V_22 -> V_171 + 1 ) & V_170 ;
if ( V_22 -> V_166 . V_107 > 0 ) {
V_17 = V_180 ;
} else {
V_4 -> V_13 . V_22 = NULL ;
V_4 -> V_13 . V_11 = - 1 ;
if ( F_12 ( V_22 -> V_171 , V_4 -> V_13 . V_26 ) >= 0 )
V_4 -> V_13 . V_26 = V_22 -> V_171 ;
V_17 = V_31 ;
}
return V_17 ;
}
static void F_66 ( union V_181 * V_154 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 = F_67 ( V_9 ) ;
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
if ( V_6 -> V_182 == F_68 ( V_183 ) )
memcpy ( & V_154 -> V_184 , F_69 ( V_6 ) , sizeof( V_154 -> V_184 ) ) ;
else if ( V_6 -> V_182 == F_68 ( V_185 ) )
memcpy ( & V_154 -> V_186 , F_70 ( V_6 ) , sizeof( V_154 -> V_186 ) ) ;
}
static enum V_15 F_71 ( struct V_3 * V_4 , struct V_8 * V_9 )
{
enum V_15 V_117 ;
if ( V_9 -> V_38 & V_187 ) {
if ( F_14 ( V_4 ) == V_71 ||
F_14 ( V_4 ) == V_72 ||
F_14 ( V_4 ) == V_73 ) {
union V_181 V_154 ;
F_66 ( & V_154 , V_9 ) ;
V_117 = F_39 ( V_4 , & V_154 , sizeof( V_154 ) ) ;
if ( V_117 )
return V_117 ;
}
V_117 = F_39 ( V_4 , F_43 ( V_9 ) , F_34 ( V_9 ) ) ;
if ( V_117 )
return V_117 ;
} else if ( V_9 -> V_38 & V_66 ) {
V_117 = F_41 ( V_4 , V_9 ) ;
if ( V_117 )
return V_117 ;
} else if ( V_9 -> V_38 & V_62 ) {
V_4 -> V_13 . V_158 ++ ;
return V_23 ;
} else if ( V_9 -> V_38 & V_68 ) {
V_117 = F_44 ( V_4 , V_9 ) ;
if ( V_117 )
return V_117 ;
} else {
F_18 ( 1 ) ;
}
V_4 -> V_13 . V_26 = ( V_9 -> V_26 + 1 ) & V_170 ;
V_4 -> V_13 . V_11 = V_9 -> V_11 ;
V_4 -> V_13 . V_95 = V_188 ;
if ( V_9 -> V_38 & V_189 ) {
V_4 -> V_13 . V_158 ++ ;
return V_97 ;
} else if ( F_14 ( V_4 ) == V_29 )
return V_190 ;
else
return V_31 ;
}
static enum V_15 F_72 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_191 V_192 ;
struct V_193 * V_194 = & V_192 . V_195 ;
struct V_196 * V_197 = & V_192 . V_198 ;
struct V_80 * V_81 = V_4 -> V_13 . V_81 ;
if ( F_36 ( ! V_81 ) )
return V_31 ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
V_194 -> V_199 = V_81 -> V_199 ;
V_194 -> V_95 = V_4 -> V_13 . V_95 ;
V_194 -> V_4 = & V_4 -> V_27 ;
if ( V_194 -> V_95 == V_188 ) {
V_194 -> V_11 = ( V_9 -> V_38 & V_200 &&
V_9 -> V_38 & V_66 ) ?
V_201 : V_202 ;
V_194 -> V_203 = 0 ;
V_194 -> V_204 = V_81 -> V_124 . V_150 - V_81 -> V_124 . V_107 ;
if ( V_4 -> V_205 -> V_206 ) {
V_197 -> V_207 = V_208 ;
if ( V_9 -> V_38 & V_200 ) {
V_197 -> V_207 |= V_209 ;
V_197 -> V_210 . V_211 =
( V_212 V_213 ) F_73 ( V_9 ) ;
}
if ( V_9 -> V_38 & V_214 ) {
V_197 -> V_207 |= V_215 ;
V_197 -> V_210 . V_216 = F_74 ( V_9 ) ;
}
V_197 -> V_217 = V_4 -> V_27 . V_217 ;
if ( V_9 -> V_38 & V_218 )
V_197 -> V_219 = F_75 ( V_9 ) ;
V_197 -> V_220 = V_4 -> V_63 . V_220 ;
} else {
struct V_5 * V_6 = F_67 ( V_9 ) ;
V_194 -> V_207 = V_208 | V_221 ;
if ( V_6 -> V_182 == F_68 ( V_183 ) )
V_194 -> V_222 = V_223 ;
else
V_194 -> V_222 = V_224 ;
if ( V_9 -> V_38 & V_200 ) {
V_194 -> V_207 |= V_209 ;
V_194 -> V_210 . V_211 = F_73 ( V_9 ) ;
}
if ( V_9 -> V_38 & V_214 ) {
struct V_1 * V_2 = F_13 ( V_4 -> V_27 . V_28 ) ;
struct V_103 * V_225 ;
V_194 -> V_207 |= V_215 ;
V_194 -> V_210 . V_216 = F_74 ( V_9 ) ;
V_225 = F_76 ( & V_2 -> V_226 ,
V_194 -> V_210 . V_216 >> 8 ) ;
if ( F_36 ( ! V_225 ) ) {
F_64 ( L_3 ,
V_194 -> V_210 . V_216 ) ;
return V_227 ;
}
V_225 -> V_17 = V_118 ;
F_8 ( V_225 ) ;
}
V_194 -> V_4 = & V_4 -> V_27 ;
if ( V_9 -> V_38 & V_218 )
V_194 -> V_219 = F_75 ( V_9 ) ;
V_194 -> V_220 = V_4 -> V_63 . V_220 ;
}
}
if ( ! V_4 -> V_75 )
F_23 ( V_4 -> V_78 . V_79 ) ;
V_4 -> V_13 . V_81 = NULL ;
if ( F_77 ( V_4 -> V_205 , & V_192 , V_9 ? F_78 ( V_9 ) : 1 ) )
return V_228 ;
if ( V_4 -> V_13 . V_17 == V_18 )
return V_20 ;
if ( ! V_9 )
return V_180 ;
else if ( F_14 ( V_4 ) == V_29 )
return V_190 ;
else
return V_31 ;
}
static int F_79 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_3 V_143 , T_2 V_26 )
{
int V_117 = 0 ;
struct V_8 V_161 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = F_13 ( V_4 -> V_27 . V_28 ) ;
V_6 = F_48 ( V_4 , V_9 , & V_161 , V_229 ,
0 , V_26 , V_143 , NULL ) ;
if ( ! V_6 ) {
V_117 = - V_230 ;
goto V_231;
}
V_117 = F_65 ( V_2 , V_4 , & V_161 , V_6 ) ;
if ( V_117 ) {
F_80 ( L_4 ) ;
F_9 ( V_6 ) ;
}
V_231:
return V_117 ;
}
static int F_81 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_3 V_143 )
{
int V_129 = 0 ;
struct V_8 V_161 ;
struct V_5 * V_6 ;
struct V_5 * V_232 ;
struct V_1 * V_2 = F_13 ( V_4 -> V_27 . V_28 ) ;
struct V_162 * V_22 ;
V_6 = F_48 ( V_4 , V_9 , & V_161 ,
V_233 , 0 , V_9 -> V_26 ,
V_143 , NULL ) ;
if ( ! V_6 ) {
V_129 = - V_230 ;
goto V_130;
}
V_232 = F_82 ( V_6 , V_234 ) ;
if ( V_232 )
F_83 ( V_4 ) ;
else {
F_84 ( L_5 ) ;
V_129 = - V_230 ;
goto V_130;
}
V_22 = & V_4 -> V_13 . V_164 [ V_4 -> V_13 . V_165 ] ;
F_61 ( V_4 , V_22 ) ;
F_62 ( V_4 ) ;
memcpy ( F_2 ( V_6 ) , & V_161 , sizeof( V_6 -> V_235 ) ) ;
V_22 -> type = V_68 ;
V_22 -> V_236 . V_6 = V_6 ;
V_22 -> V_168 = V_161 . V_26 ;
V_22 -> V_169 = V_161 . V_26 ;
V_22 -> V_171 = V_161 . V_26 ;
V_129 = F_65 ( V_2 , V_4 , & V_161 , V_232 ) ;
if ( V_129 ) {
F_80 ( L_4 ) ;
F_8 ( V_4 ) ;
F_9 ( V_232 ) ;
}
V_130:
return V_129 ;
}
static enum V_15 F_85 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
if ( F_14 ( V_4 ) != V_29 )
return V_31 ;
if ( V_4 -> V_13 . V_237 != V_178 )
F_79 ( V_4 , V_9 , V_4 -> V_13 . V_237 , V_9 -> V_26 ) ;
else if ( V_9 -> V_38 & V_68 )
F_81 ( V_4 , V_9 , V_178 ) ;
else if ( F_86 ( V_9 ) )
F_79 ( V_4 , V_9 , V_178 , V_9 -> V_26 ) ;
return V_31 ;
}
static enum V_15 F_87 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 ;
if ( V_9 ) {
V_6 = F_7 ( & V_4 -> V_10 ) ;
F_8 ( V_4 ) ;
F_9 ( V_6 ) ;
}
if ( V_4 -> V_13 . V_120 ) {
F_8 ( V_4 -> V_13 . V_120 ) ;
V_4 -> V_13 . V_120 = NULL ;
}
return V_180 ;
}
static struct V_162 * F_88 ( struct V_3 * V_4 , T_2 V_26 )
{
int V_238 ;
for ( V_238 = 0 ; V_238 < V_4 -> V_63 . V_239 ; V_238 ++ ) {
struct V_162 * V_22 = & V_4 -> V_13 . V_164 [ V_238 ] ;
if ( V_22 -> type == 0 )
continue;
if ( F_12 ( V_26 , V_22 -> V_168 ) >= 0 &&
F_12 ( V_26 , V_22 -> V_169 ) <= 0 ) {
return V_22 ;
}
}
return NULL ;
}
static enum V_15 F_89 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
enum V_15 V_129 ;
T_2 V_240 = ( V_4 -> V_13 . V_26 - 1 ) & V_170 ;
if ( V_9 -> V_38 & V_187 ||
V_9 -> V_38 & V_66 ) {
if ( F_86 ( V_9 ) )
F_79 ( V_4 , V_9 , V_178 , V_240 ) ;
V_129 = V_31 ;
goto V_130;
} else if ( V_9 -> V_38 & V_62 ) {
struct V_162 * V_22 ;
V_22 = F_88 ( V_4 , V_9 -> V_26 ) ;
if ( ! V_22 ) {
V_129 = V_31 ;
goto V_130;
} else {
T_1 V_131 = F_29 ( V_9 ) ;
T_2 V_107 = F_31 ( V_9 ) ;
if ( V_131 < V_22 -> V_166 . V_167 ||
V_107 > V_22 -> V_166 . V_150 ||
( V_131 + V_107 ) > ( V_22 -> V_166 . V_167 +
V_22 -> V_166 . V_150 ) ) {
V_129 = V_31 ;
goto V_130;
}
if ( F_30 ( V_9 ) != V_22 -> V_166 . V_106 ) {
V_129 = V_31 ;
goto V_130;
}
V_22 -> V_171 = V_9 -> V_26 ;
V_22 -> V_17 = ( V_9 -> V_26 == V_22 -> V_168 ) ?
V_172 :
V_241 ;
V_22 -> V_166 . V_167 = V_131 ;
V_22 -> V_166 . V_105 = V_131 ;
V_22 -> V_166 . V_107 = V_107 ;
V_4 -> V_13 . V_22 = V_22 ;
V_129 = V_23 ;
goto V_130;
}
} else {
struct V_162 * V_22 ;
V_22 = F_88 ( V_4 , V_9 -> V_26 ) ;
if ( V_22 ) {
struct V_5 * V_232 ;
V_232 = F_82 ( V_22 -> V_236 . V_6 , V_234 ) ;
if ( V_232 ) {
F_83 ( V_4 ) ;
} else {
F_84 ( L_6 ) ;
V_129 = V_31 ;
goto V_130;
}
V_129 = F_65 ( F_13 ( V_4 -> V_27 . V_28 ) , V_4 ,
V_9 , V_232 ) ;
if ( V_129 ) {
F_64 ( L_7 ) ;
F_8 ( V_4 ) ;
F_9 ( V_232 ) ;
V_129 = V_31 ;
goto V_130;
}
}
V_129 = V_31 ;
goto V_130;
}
V_130:
return V_129 ;
}
static void F_90 ( struct V_3 * V_4 , T_3 V_143 ,
enum V_242 V_95 )
{
V_4 -> V_13 . V_237 = V_143 ;
V_4 -> V_13 . V_95 = V_95 ;
V_4 -> V_13 . V_243 = 1 ;
}
static enum V_15 F_91 ( struct V_3 * V_4 )
{
if ( V_4 -> V_75 ) {
V_4 -> V_13 . V_37 = 1 ;
if ( V_4 -> V_13 . V_81 ) {
V_4 -> V_13 . V_95 = V_244 ;
return V_97 ;
} else {
return V_31 ;
}
} else {
if ( V_4 -> V_13 . V_81 ) {
V_4 -> V_13 . V_81 -> V_124 . V_107 = V_4 -> V_13 . V_81 -> V_124 . V_150 ;
V_4 -> V_13 . V_81 -> V_124 . V_245 = 0 ;
V_4 -> V_13 . V_81 -> V_124 . V_246 = 0 ;
V_4 -> V_13 . V_11 = - 1 ;
}
if ( V_4 -> V_13 . V_120 ) {
F_8 ( V_4 -> V_13 . V_120 ) ;
V_4 -> V_13 . V_120 = NULL ;
}
return V_31 ;
}
}
void F_92 ( struct V_3 * V_4 , bool V_247 )
{
struct V_5 * V_6 ;
while ( ( V_6 = F_7 ( & V_4 -> V_10 ) ) ) {
F_8 ( V_4 ) ;
F_9 ( V_6 ) ;
}
while ( ! V_4 -> V_75 && V_4 -> V_78 . V_79 && F_21 ( V_4 -> V_78 . V_79 ) )
F_23 ( V_4 -> V_78 . V_79 ) ;
}
int F_93 ( void * V_248 )
{
struct V_3 * V_4 = (struct V_3 * ) V_248 ;
struct V_1 * V_2 = F_13 ( V_4 -> V_27 . V_28 ) ;
enum V_15 V_17 ;
struct V_8 * V_9 = NULL ;
int V_133 = 0 ;
F_83 ( V_4 ) ;
V_4 -> V_13 . V_237 = V_178 ;
if ( ! V_4 -> V_249 ) {
V_133 = - V_250 ;
goto V_251;
}
switch ( V_4 -> V_13 . V_17 ) {
case V_252 :
V_17 = V_253 ;
break;
default:
V_17 = V_19 ;
break;
}
while ( 1 ) {
F_94 ( L_8 , V_217 ( V_4 ) ,
V_254 [ V_17 ] ) ;
switch ( V_17 ) {
case V_19 :
V_17 = F_6 ( V_4 , & V_9 ) ;
break;
case V_24 :
V_17 = F_11 ( V_4 , V_9 ) ;
break;
case V_40 :
V_17 = F_16 ( V_4 , V_9 ) ;
break;
case V_46 :
V_17 = F_17 ( V_4 , V_9 ) ;
break;
case V_20 :
V_17 = F_25 ( V_4 , V_9 ) ;
break;
case V_91 :
V_17 = F_27 ( V_4 , V_9 ) ;
break;
case V_102 :
V_17 = F_28 ( V_4 , V_9 ) ;
break;
case V_112 :
V_17 = F_71 ( V_4 , V_9 ) ;
break;
case V_97 :
V_17 = F_72 ( V_4 , V_9 ) ;
break;
case V_23 :
V_17 = F_60 ( V_4 , V_9 ) ;
break;
case V_190 :
V_17 = F_85 ( V_4 , V_9 ) ;
break;
case V_31 :
V_17 = F_87 ( V_4 , V_9 ) ;
break;
case V_35 :
V_17 = F_89 ( V_4 , V_9 ) ;
break;
case V_33 :
F_79 ( V_4 , V_9 , V_255 , V_4 -> V_13 . V_26 ) ;
V_17 = V_31 ;
break;
case V_100 :
case V_52 :
case V_47 :
case V_70 :
case V_136 :
F_90 ( V_4 , V_256 ,
V_244 ) ;
V_17 = V_97 ;
break;
case V_57 :
V_17 = F_91 ( V_4 ) ;
break;
case V_84 :
if ( F_14 ( V_4 ) == V_29 ) {
F_15 ( V_2 , V_257 ) ;
F_79 ( V_4 , V_9 , V_258 |
( ~ V_259 &
V_4 -> V_63 . V_260 ) ,
V_9 -> V_26 ) ;
} else {
V_4 -> V_13 . V_37 = 1 ;
}
V_17 = V_31 ;
break;
case V_116 :
if ( F_14 ( V_4 ) == V_29 ) {
F_90 ( V_4 , V_261 ,
V_262 ) ;
V_17 = V_97 ;
} else {
V_4 -> V_13 . V_37 = 1 ;
if ( V_4 -> V_75 ) {
V_4 -> V_13 . V_95 = V_262 ;
V_17 = V_97 ;
} else {
V_17 = V_31 ;
}
}
break;
case V_119 :
if ( F_14 ( V_4 ) == V_29 ) {
F_90 ( V_4 , V_256 ,
V_244 ) ;
V_17 = V_97 ;
} else if ( V_4 -> V_75 ) {
V_4 -> V_13 . V_95 = V_244 ;
V_17 = V_97 ;
} else {
V_4 -> V_13 . V_37 = 1 ;
V_17 = V_31 ;
}
break;
case V_127 :
F_90 ( V_4 , V_263 ,
V_264 ) ;
V_17 = V_97 ;
break;
case V_228 :
V_17 = V_227 ;
break;
case V_180 :
if ( V_4 -> V_13 . V_243 ) {
V_17 = V_227 ;
break;
}
goto V_251;
case V_21 :
if ( V_4 -> V_13 . V_243 ) {
V_17 = V_227 ;
break;
}
goto exit;
case V_253 :
F_92 ( V_4 , false ) ;
V_4 -> V_13 . V_81 = NULL ;
goto exit;
case V_227 :
V_4 -> V_13 . V_243 = 0 ;
F_84 ( L_9 , V_217 ( V_4 ) ) ;
F_95 ( V_4 ) ;
goto exit;
default:
F_18 ( 1 ) ;
}
}
exit:
V_133 = - V_265 ;
V_251:
F_8 ( V_4 ) ;
return V_133 ;
}
