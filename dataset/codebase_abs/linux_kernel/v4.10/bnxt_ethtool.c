static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = V_6 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_9 = V_4 -> V_10 ;
V_8 -> V_11 = V_4 -> V_12 / 2 ;
V_8 -> V_13 = V_4 -> V_14 ;
V_8 -> V_15 = V_4 -> V_16 / 2 ;
V_8 -> V_17 = V_4 -> V_18 ;
V_8 -> V_19 = V_4 -> V_20 ;
V_8 -> V_21 = V_4 -> V_22 ;
V_8 -> V_23 = V_4 -> V_24 ;
V_8 -> V_25 = V_4 -> V_26 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_27 = false ;
int V_28 = 0 ;
V_4 -> V_10 = V_8 -> V_9 ;
V_4 -> V_12 = V_8 -> V_11 * 2 ;
V_4 -> V_14 = V_8 -> V_13 ;
V_4 -> V_16 = V_8 -> V_15 * 2 ;
V_4 -> V_18 = V_8 -> V_17 ;
V_4 -> V_20 = V_8 -> V_19 ;
V_4 -> V_22 = V_8 -> V_21 ;
V_4 -> V_24 = V_8 -> V_23 ;
if ( V_4 -> V_26 != V_8 -> V_25 ) {
T_1 V_29 = V_8 -> V_25 ;
V_29 = F_6 ( T_1 , V_29 ,
V_30 ,
V_31 ) ;
V_29 = F_7 ( V_29 , V_30 ) ;
V_4 -> V_26 = V_29 ;
V_27 = true ;
}
if ( F_8 ( V_2 ) ) {
if ( V_27 ) {
V_28 = F_9 ( V_4 , true , false ) ;
if ( ! V_28 )
V_28 = F_10 ( V_4 , true , false ) ;
} else {
V_28 = F_11 ( V_4 ) ;
}
}
return V_28 ;
}
static int F_12 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_32 ) {
case V_33 : {
int V_34 = V_35 * V_4 -> V_36 ;
if ( V_4 -> V_37 & V_38 )
V_34 += V_39 ;
return V_34 ;
}
default:
return - V_40 ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_41 * V_42 , T_2 * V_43 )
{
T_1 V_44 , V_45 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_46 = sizeof( struct V_47 ) * V_4 -> V_36 ;
T_1 V_48 = sizeof( struct V_47 ) / 8 ;
memset ( V_43 , 0 , V_46 ) ;
if ( ! V_4 -> V_49 )
return;
for ( V_44 = 0 ; V_44 < V_4 -> V_36 ; V_44 ++ ) {
struct V_50 * V_49 = V_4 -> V_49 [ V_44 ] ;
struct V_51 * V_52 = & V_49 -> V_53 ;
T_3 * V_54 = ( T_3 * ) V_52 -> V_54 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_48 ; V_45 ++ , V_55 ++ )
V_43 [ V_45 ] = F_14 ( V_54 [ V_55 ] ) ;
V_43 [ V_45 ++ ] = V_52 -> V_56 ;
}
if ( V_4 -> V_37 & V_38 ) {
T_3 * V_57 = ( T_3 * ) V_4 -> V_58 ;
for ( V_44 = 0 ; V_44 < V_39 ; V_44 ++ , V_45 ++ ) {
V_43 [ V_45 ] = F_14 ( * ( V_57 +
V_59 [ V_44 ] . V_60 ) ) ;
}
}
}
static void F_15 ( struct V_1 * V_2 , T_1 V_61 , T_4 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_44 ;
switch ( V_61 ) {
case V_33 :
for ( V_44 = 0 ; V_44 < V_4 -> V_36 ; V_44 ++ ) {
sprintf ( V_43 , L_1 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_2 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_3 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_4 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_5 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_6 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_7 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_8 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_9 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_10 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_11 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_12 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_13 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_14 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_15 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_16 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_17 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_18 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_19 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_20 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_21 , V_44 ) ;
V_43 += V_62 ;
}
if ( V_4 -> V_37 & V_38 ) {
for ( V_44 = 0 ; V_44 < V_39 ; V_44 ++ ) {
strcpy ( V_43 , V_59 [ V_44 ] . string ) ;
V_43 += V_62 ;
}
}
break;
default:
F_16 ( V_4 -> V_2 , L_22 ,
V_61 ) ;
break;
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_64 -> V_65 = V_66 ;
V_64 -> V_67 = V_68 ;
V_64 -> V_69 = V_70 ;
V_64 -> V_71 = V_4 -> V_72 ;
V_64 -> V_73 = V_4 -> V_74 ;
V_64 -> V_75 = V_4 -> V_76 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ( V_64 -> V_71 > V_66 ) ||
( V_64 -> V_75 > V_70 ) ||
( V_64 -> V_75 <= V_77 ) )
return - V_78 ;
if ( F_8 ( V_2 ) )
F_9 ( V_4 , false , false ) ;
V_4 -> V_72 = V_64 -> V_71 ;
V_4 -> V_76 = V_64 -> V_75 ;
F_19 ( V_4 ) ;
if ( F_8 ( V_2 ) )
return F_10 ( V_4 , false , false ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_81 , V_82 , V_83 ;
F_21 ( V_4 , & V_81 , & V_82 , true ) ;
V_80 -> V_84 = F_22 ( int , V_81 , V_82 ) ;
if ( F_21 ( V_4 , & V_81 , & V_82 , false ) ) {
V_81 = 0 ;
V_82 = 0 ;
}
V_83 = F_23 ( V_2 ) ;
if ( V_83 > 1 )
V_82 /= V_83 ;
V_80 -> V_85 = V_81 ;
V_80 -> V_86 = V_82 ;
V_80 -> V_87 = 0 ;
if ( V_4 -> V_37 & V_88 ) {
V_80 -> V_89 = V_4 -> V_90 ;
if ( F_24 ( V_4 ) )
V_80 -> V_89 -- ;
} else {
if ( ! F_24 ( V_4 ) ) {
V_80 -> V_91 = V_4 -> V_90 ;
V_80 -> V_92 = V_4 -> V_93 ;
}
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_81 , V_82 , V_83 ;
T_1 V_28 = 0 ;
bool V_94 = false ;
if ( V_80 -> V_95 )
return - V_78 ;
if ( ! V_80 -> V_89 &&
( ! V_80 -> V_91 || ! V_80 -> V_92 ) )
return - V_78 ;
if ( V_80 -> V_89 &&
( V_80 -> V_91 || V_80 -> V_92 ) )
return - V_78 ;
if ( F_24 ( V_4 ) && ( V_80 -> V_91 ||
V_80 -> V_92 ) )
return - V_78 ;
if ( V_80 -> V_89 )
V_94 = true ;
F_21 ( V_4 , & V_81 , & V_82 , V_94 ) ;
V_83 = F_23 ( V_2 ) ;
if ( V_83 > 1 )
V_82 /= V_83 ;
if ( V_94 &&
V_80 -> V_89 > F_22 ( int , V_81 , V_82 ) )
return - V_96 ;
if ( ! V_94 && ( V_80 -> V_91 > V_81 ||
V_80 -> V_92 > V_82 ) )
return - V_96 ;
if ( F_8 ( V_2 ) ) {
if ( F_26 ( V_4 ) ) {
}
V_28 = F_9 ( V_4 , true , false ) ;
if ( V_28 ) {
F_16 ( V_4 -> V_2 , L_23 ,
V_28 ) ;
return V_28 ;
}
}
if ( V_94 ) {
V_4 -> V_37 |= V_88 ;
V_4 -> V_90 = F_27 ( int , V_80 -> V_89 ,
V_81 ) ;
V_4 -> V_93 = F_27 ( int , V_80 -> V_89 ,
V_82 ) ;
} else {
V_4 -> V_37 &= ~ V_88 ;
V_4 -> V_90 = V_80 -> V_91 ;
V_4 -> V_93 = V_80 -> V_92 ;
}
V_4 -> V_97 = V_4 -> V_93 ;
if ( V_83 > 1 )
V_4 -> V_97 = V_4 -> V_93 * V_83 ;
V_4 -> V_36 = V_94 ? F_22 ( int , V_4 -> V_97 , V_4 -> V_90 ) :
V_4 -> V_97 + V_4 -> V_90 ;
V_4 -> V_98 = V_4 -> V_36 ;
F_28 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
V_28 = F_10 ( V_4 , true , false ) ;
if ( ( ! V_28 ) && F_26 ( V_4 ) ) {
}
}
return V_28 ;
}
static int F_29 ( struct V_3 * V_4 , struct V_99 * V_100 ,
T_1 * V_101 )
{
int V_44 , V_45 = 0 ;
V_100 -> V_102 = V_4 -> V_103 ;
for ( V_44 = 0 ; V_44 < V_104 ; V_44 ++ ) {
struct V_105 * V_106 ;
struct V_107 * V_108 ;
V_106 = & V_4 -> V_109 [ V_44 ] ;
F_30 () ;
F_31 (fltr, head, hash) {
if ( V_45 == V_100 -> V_110 )
break;
V_101 [ V_45 ++ ] = V_108 -> V_111 ;
}
F_32 () ;
if ( V_45 == V_100 -> V_110 )
break;
}
V_100 -> V_110 = V_45 ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 , struct V_99 * V_100 )
{
struct V_112 * V_113 =
(struct V_112 * ) & V_100 -> V_113 ;
struct V_107 * V_108 ;
struct V_114 * V_115 ;
int V_44 , V_28 = - V_78 ;
if ( V_113 -> V_116 < 0 || V_113 -> V_116 >= V_117 )
return V_28 ;
for ( V_44 = 0 ; V_44 < V_104 ; V_44 ++ ) {
struct V_105 * V_106 ;
V_106 = & V_4 -> V_109 [ V_44 ] ;
F_30 () ;
F_31 (fltr, head, hash) {
if ( V_108 -> V_111 == V_113 -> V_116 )
goto V_118;
}
F_32 () ;
}
return V_28 ;
V_118:
V_115 = & V_108 -> V_115 ;
if ( V_115 -> V_119 . V_120 == V_121 )
V_113 -> V_122 = V_123 ;
else if ( V_115 -> V_119 . V_120 == V_124 )
V_113 -> V_122 = V_125 ;
else
goto V_126;
V_113 -> V_127 . V_128 . V_129 = V_115 -> V_130 . V_131 . V_132 ;
V_113 -> V_133 . V_128 . V_129 = F_34 ( ~ 0 ) ;
V_113 -> V_127 . V_128 . V_134 = V_115 -> V_130 . V_131 . V_135 ;
V_113 -> V_133 . V_128 . V_134 = F_34 ( ~ 0 ) ;
V_113 -> V_127 . V_128 . V_136 = V_115 -> V_137 . V_132 ;
V_113 -> V_133 . V_128 . V_136 = F_35 ( ~ 0 ) ;
V_113 -> V_127 . V_128 . V_138 = V_115 -> V_137 . V_135 ;
V_113 -> V_133 . V_128 . V_138 = F_35 ( ~ 0 ) ;
V_113 -> V_139 = V_108 -> V_140 ;
V_28 = 0 ;
V_126:
F_32 () ;
return V_28 ;
}
static T_2 F_36 ( struct V_3 * V_4 )
{
if ( V_4 -> V_141 & V_142 )
return V_143 | V_144 ;
return 0 ;
}
static T_2 F_37 ( struct V_3 * V_4 )
{
if ( V_4 -> V_141 & V_145 )
return V_143 | V_144 ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 , struct V_99 * V_100 )
{
V_100 -> V_102 = 0 ;
switch ( V_100 -> V_122 ) {
case V_123 :
if ( V_4 -> V_141 & V_146 )
V_100 -> V_102 |= V_143 | V_144 |
V_147 | V_148 ;
V_100 -> V_102 |= F_36 ( V_4 ) ;
break;
case V_125 :
if ( V_4 -> V_141 & V_149 )
V_100 -> V_102 |= V_143 | V_144 |
V_147 | V_148 ;
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
V_100 -> V_102 |= F_36 ( V_4 ) ;
break;
case V_155 :
if ( V_4 -> V_141 & V_156 )
V_100 -> V_102 |= V_143 | V_144 |
V_147 | V_148 ;
V_100 -> V_102 |= F_37 ( V_4 ) ;
break;
case V_157 :
if ( V_4 -> V_141 & V_158 )
V_100 -> V_102 |= V_143 | V_144 |
V_147 | V_148 ;
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
V_100 -> V_102 |= F_37 ( V_4 ) ;
break;
}
return 0 ;
}
static int F_39 ( struct V_3 * V_4 , struct V_99 * V_100 )
{
T_1 V_141 = V_4 -> V_141 ;
int V_164 , V_28 = 0 ;
if ( V_100 -> V_102 == V_165 )
V_164 = 4 ;
else if ( V_100 -> V_102 == V_166 )
V_164 = 2 ;
else if ( ! V_100 -> V_102 )
V_164 = 0 ;
else
return - V_78 ;
if ( V_100 -> V_122 == V_123 ) {
V_141 &= ~ V_146 ;
if ( V_164 == 4 )
V_141 |= V_146 ;
} else if ( V_100 -> V_122 == V_125 ) {
if ( V_164 == 4 && ! ( V_4 -> V_37 & V_167 ) )
return - V_78 ;
V_141 &= ~ V_149 ;
if ( V_164 == 4 )
V_141 |= V_149 ;
} else if ( V_100 -> V_122 == V_155 ) {
V_141 &= ~ V_156 ;
if ( V_164 == 4 )
V_141 |= V_156 ;
} else if ( V_100 -> V_122 == V_157 ) {
if ( V_164 == 4 && ! ( V_4 -> V_37 & V_167 ) )
return - V_78 ;
V_141 &= ~ V_158 ;
if ( V_164 == 4 )
V_141 |= V_158 ;
} else if ( V_164 == 4 ) {
return - V_78 ;
}
switch ( V_100 -> V_122 ) {
case V_123 :
case V_125 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
if ( V_164 == 2 )
V_141 |= V_142 ;
else if ( ! V_164 )
V_141 &= ~ V_142 ;
break;
case V_155 :
case V_157 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
if ( V_164 == 2 )
V_141 |= V_145 ;
else if ( ! V_164 )
V_141 &= ~ V_145 ;
break;
}
if ( V_4 -> V_141 == V_141 )
return 0 ;
V_4 -> V_141 = V_141 ;
if ( F_8 ( V_4 -> V_2 ) ) {
F_9 ( V_4 , false , false ) ;
V_28 = F_10 ( V_4 , false , false ) ;
}
return V_28 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_99 * V_100 ,
T_1 * V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 = 0 ;
switch ( V_100 -> V_100 ) {
#ifdef F_41
case V_168 :
V_100 -> V_102 = V_4 -> V_90 ;
break;
case V_169 :
V_100 -> V_110 = V_4 -> V_103 ;
V_100 -> V_102 = V_117 ;
break;
case V_170 :
V_28 = F_29 ( V_4 , V_100 , ( T_1 * ) V_101 ) ;
break;
case V_171 :
V_28 = F_33 ( V_4 , V_100 ) ;
break;
#endif
case V_172 :
V_28 = F_38 ( V_4 , V_100 ) ;
break;
default:
V_28 = - V_40 ;
break;
}
return V_28 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_99 * V_100 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
switch ( V_100 -> V_100 ) {
case V_173 :
V_28 = F_39 ( V_4 , V_100 ) ;
break;
default:
V_28 = - V_40 ;
break;
}
return V_28 ;
}
static T_1 F_43 ( struct V_1 * V_2 )
{
return V_174 ;
}
static T_1 F_44 ( struct V_1 * V_2 )
{
return V_175 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 * V_176 , T_4 * V_177 ,
T_4 * V_178 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_179 * V_180 = & V_4 -> V_181 [ 0 ] ;
int V_44 = 0 ;
if ( V_178 )
* V_178 = V_182 ;
if ( V_176 )
for ( V_44 = 0 ; V_44 < V_174 ; V_44 ++ )
V_176 [ V_44 ] = F_46 ( V_180 -> V_183 [ V_44 ] ) ;
if ( V_177 )
memcpy ( V_177 , V_180 -> V_184 , V_175 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_185 * V_186 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
char * V_187 ;
char * V_188 = NULL ;
V_187 = F_48 ( V_189 , V_190 ) ;
if ( V_187 )
V_188 = F_49 ( V_2 , V_187 , V_189 ) ;
F_50 ( V_186 -> V_191 , V_192 , sizeof( V_186 -> V_191 ) ) ;
F_50 ( V_186 -> V_193 , V_194 , sizeof( V_186 -> V_193 ) ) ;
if ( V_188 && * V_188 != 0 && isdigit ( * V_188 ) )
snprintf ( V_186 -> V_195 , sizeof( V_186 -> V_195 ) - 1 ,
L_24 , V_4 -> V_196 , V_188 ) ;
else
F_50 ( V_186 -> V_195 , V_4 -> V_196 ,
sizeof( V_186 -> V_195 ) ) ;
F_50 ( V_186 -> V_197 , F_51 ( V_4 -> V_198 ) , sizeof( V_186 -> V_197 ) ) ;
V_186 -> V_199 = V_35 * V_4 -> V_36 ;
V_186 -> V_200 = F_52 ( V_4 ) ;
V_186 -> V_201 = 0 ;
V_186 -> V_202 = 0 ;
F_53 ( V_187 ) ;
}
T_1 F_54 ( T_5 V_203 , T_4 V_204 )
{
T_1 V_205 = 0 ;
if ( V_203 & V_206 )
V_205 |= V_207 ;
if ( V_203 & V_208 )
V_205 |= V_209 ;
if ( V_203 & V_210 )
V_205 |= V_211 ;
if ( V_203 & V_212 )
V_205 |= V_213 ;
if ( V_203 & V_214 )
V_205 |= V_215 ;
if ( ( V_204 & V_216 ) == V_216 )
V_205 |= V_217 ;
else if ( V_204 & V_218 )
V_205 |= V_219 ;
else if ( V_204 & V_220 )
V_205 |= V_217 | V_219 ;
return V_205 ;
}
static void F_55 ( struct V_221 * V_222 ,
struct V_223 * V_224 )
{
T_5 V_203 = V_222 -> V_225 ;
T_4 V_204 = 0 ;
if ( V_222 -> V_226 & V_227 )
V_204 = V_222 -> V_228 ;
F_56 ( V_203 , V_204 , V_224 , V_229 ) ;
}
static void F_57 ( struct V_221 * V_222 ,
struct V_223 * V_224 )
{
T_5 V_203 = V_222 -> V_230 ;
T_4 V_204 = 0 ;
if ( V_222 -> V_226 & V_227 )
V_204 = V_222 -> V_231 ;
F_56 ( V_203 , V_204 , V_224 ,
V_232 ) ;
}
static void F_58 ( struct V_221 * V_222 ,
struct V_223 * V_224 )
{
T_5 V_203 = V_222 -> V_233 ;
F_56 ( V_203 , 0 , V_224 , V_234 ) ;
F_59 ( V_224 , V_234 , V_235 ) ;
F_59 ( V_224 , V_234 ,
V_236 ) ;
if ( V_222 -> V_237 )
F_59 ( V_224 , V_234 ,
V_238 ) ;
}
T_1 F_60 ( T_5 V_239 )
{
switch ( V_239 ) {
case V_240 :
return V_241 ;
case V_242 :
return V_243 ;
case V_244 :
return V_245 ;
case V_246 :
return V_247 ;
case V_248 :
return V_249 ;
case V_250 :
return V_251 ;
case V_252 :
return V_253 ;
case V_254 :
return V_255 ;
default:
return V_256 ;
}
}
static int F_61 ( struct V_1 * V_2 ,
struct V_223 * V_224 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_221 * V_222 = & V_4 -> V_222 ;
struct V_257 * V_258 = & V_224 -> V_258 ;
T_1 V_259 ;
F_62 ( V_224 , V_234 ) ;
F_58 ( V_222 , V_224 ) ;
F_62 ( V_224 , V_229 ) ;
if ( V_222 -> V_226 ) {
F_55 ( V_222 , V_224 ) ;
F_59 ( V_224 ,
V_229 , V_238 ) ;
V_258 -> V_226 = V_260 ;
if ( V_222 -> V_261 == V_262 )
F_57 ( V_222 , V_224 ) ;
V_259 = F_60 ( V_222 -> V_263 ) ;
if ( ! F_63 ( V_2 ) )
V_258 -> V_264 = V_265 ;
else if ( V_222 -> V_264 & V_266 )
V_258 -> V_264 = V_267 ;
else
V_258 -> V_264 = V_268 ;
} else {
V_258 -> V_226 = V_269 ;
V_259 =
F_60 ( V_222 -> V_270 ) ;
V_258 -> V_264 = V_268 ;
if ( V_222 -> V_271 == V_266 )
V_258 -> V_264 = V_267 ;
}
V_258 -> V_272 = V_259 ;
V_258 -> V_273 = V_274 ;
if ( V_222 -> V_275 == V_276 ) {
V_258 -> V_273 = V_277 ;
F_59 ( V_224 , V_234 ,
V_278 ) ;
F_59 ( V_224 , V_229 ,
V_278 ) ;
} else {
F_59 ( V_224 , V_234 ,
V_279 ) ;
F_59 ( V_224 , V_229 ,
V_279 ) ;
if ( V_222 -> V_275 == V_280 )
V_258 -> V_273 = V_281 ;
else if ( V_222 -> V_275 ==
V_282 )
V_258 -> V_273 = V_283 ;
}
V_258 -> V_284 = V_222 -> V_285 ;
return 0 ;
}
static T_1 F_64 ( struct V_1 * V_2 , T_5 V_259 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_221 * V_222 = & V_4 -> V_222 ;
T_5 V_286 = V_222 -> V_233 ;
T_1 V_287 = 0 ;
switch ( V_259 ) {
case V_241 :
if ( V_286 & V_206 )
V_287 = V_288 ;
break;
case V_243 :
if ( V_286 & V_208 )
V_287 = V_289 ;
break;
case V_245 :
if ( V_286 & V_210 )
V_287 = V_290 ;
break;
case V_247 :
if ( V_286 & V_212 )
V_287 = V_291 ;
break;
case V_249 :
if ( V_286 & V_292 )
V_287 = V_293 ;
break;
case V_251 :
if ( V_286 & V_294 )
V_287 = V_295 ;
break;
case V_253 :
if ( V_286 & V_214 )
V_287 = V_296 ;
break;
case V_255 :
if ( V_286 & V_297 )
V_287 = V_298 ;
break;
default:
F_16 ( V_2 , L_25 ) ;
break;
}
return V_287 ;
}
T_5 F_65 ( T_1 V_229 )
{
T_5 V_299 = 0 ;
if ( V_229 & ( V_207 |
V_300 ) ) {
V_299 |= V_206 ;
}
if ( V_229 & ( V_209 |
V_301 ) ) {
V_299 |= V_208 ;
}
if ( V_229 & V_213 )
V_299 |= V_212 ;
if ( V_229 & V_215 )
V_299 |= V_214 ;
return V_299 ;
}
static int F_66 ( struct V_1 * V_2 ,
const struct V_223 * V_224 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_221 * V_222 = & V_4 -> V_222 ;
const struct V_257 * V_258 = & V_224 -> V_258 ;
T_1 V_272 , V_302 = 0 ;
bool V_303 = false ;
int V_28 = 0 ;
if ( ! F_67 ( V_4 ) )
return - V_40 ;
if ( V_258 -> V_226 == V_260 ) {
F_68 ( V_302 , V_224 ,
V_229 ) ;
V_222 -> V_226 |= V_304 ;
if ( ! V_302 )
V_222 -> V_229 = V_222 -> V_237 ;
else
V_222 -> V_229 = V_302 ;
V_303 = true ;
} else {
T_5 V_287 ;
T_4 V_305 = V_222 -> V_305 ;
if ( V_305 == V_306 ||
V_305 == V_307 ||
V_222 -> V_275 == V_276 ) {
F_16 ( V_2 , L_26 ) ;
V_28 = - V_78 ;
goto V_308;
}
if ( V_258 -> V_264 == V_268 ) {
F_16 ( V_2 , L_27 ) ;
V_28 = - V_78 ;
goto V_308;
}
V_272 = V_258 -> V_272 ;
V_287 = F_64 ( V_2 , V_272 ) ;
if ( ! V_287 ) {
V_28 = - V_78 ;
goto V_308;
}
V_222 -> V_270 = V_287 ;
V_222 -> V_271 = V_266 ;
V_222 -> V_226 = 0 ;
V_222 -> V_229 = 0 ;
}
if ( F_8 ( V_2 ) )
V_28 = F_69 ( V_4 , V_303 , false ) ;
V_308:
return V_28 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_309 * V_310 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_221 * V_222 = & V_4 -> V_222 ;
if ( F_71 ( V_4 ) )
return;
V_310 -> V_226 = ! ! ( V_222 -> V_226 & V_227 ) ;
V_310 -> V_311 = ! ! ( V_222 -> V_312 & V_220 ) ;
V_310 -> V_313 = ! ! ( V_222 -> V_312 & V_218 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_309 * V_310 )
{
int V_28 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_221 * V_222 = & V_4 -> V_222 ;
if ( ! F_67 ( V_4 ) )
return - V_40 ;
if ( V_310 -> V_226 ) {
if ( ! ( V_222 -> V_226 & V_304 ) )
return - V_78 ;
V_222 -> V_226 |= V_227 ;
if ( V_4 -> V_314 >= 0x10201 )
V_222 -> V_312 =
V_315 ;
} else {
if ( V_222 -> V_226 & V_227 )
V_222 -> V_316 = true ;
V_222 -> V_226 &= ~ V_227 ;
V_222 -> V_312 = 0 ;
}
if ( V_310 -> V_311 )
V_222 -> V_312 |= V_220 ;
if ( V_310 -> V_313 )
V_222 -> V_312 |= V_218 ;
if ( F_8 ( V_2 ) )
V_28 = F_73 ( V_4 ) ;
return V_28 ;
}
static T_1 F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_222 . V_317 ;
}
static int F_75 ( struct V_1 * V_2 ,
T_5 V_318 ,
T_5 V_319 ,
T_5 V_320 ,
T_5 V_321 ,
const T_4 * V_102 ,
T_6 V_322 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_323 V_324 = { 0 } ;
T_7 V_325 ;
T_4 * V_326 ;
F_76 ( V_4 , & V_324 , V_327 , - 1 , - 1 ) ;
V_324 . V_318 = F_77 ( V_318 ) ;
V_324 . V_319 = F_77 ( V_319 ) ;
V_324 . V_320 = F_77 ( V_320 ) ;
V_324 . V_321 = F_77 ( V_321 ) ;
V_324 . V_328 = F_78 ( V_322 ) ;
V_326 = F_79 ( & V_4 -> V_198 -> V_2 , V_322 , & V_325 ,
V_190 ) ;
if ( ! V_326 ) {
F_16 ( V_2 , L_28 ,
( unsigned ) V_322 ) ;
return - V_96 ;
}
memcpy ( V_326 , V_102 , V_322 ) ;
V_324 . V_329 = F_80 ( V_325 ) ;
V_28 = F_81 ( V_4 , & V_324 , sizeof( V_324 ) , V_330 ) ;
F_82 ( & V_4 -> V_198 -> V_2 , V_322 , V_326 , V_325 ) ;
return V_28 ;
}
static int F_83 ( struct V_1 * V_2 ,
T_5 V_318 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_331 V_324 = { 0 } ;
F_76 ( V_4 , & V_324 , V_332 , - 1 , - 1 ) ;
switch ( V_318 ) {
case V_333 :
case V_334 :
case V_335 :
V_324 . V_336 = V_337 ;
V_324 . V_338 = V_339 ;
break;
case V_340 :
case V_341 :
V_324 . V_336 = V_342 ;
V_324 . V_338 = V_339 ;
break;
case V_343 :
case V_344 :
V_324 . V_336 =
V_345 ;
break;
case V_346 :
case V_347 :
V_324 . V_336 = V_348 ;
break;
default:
return - V_78 ;
}
return F_81 ( V_4 , & V_324 , sizeof( V_324 ) , V_349 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
T_5 V_318 ,
const T_4 * V_350 ,
T_6 V_351 )
{
int V_28 = 0 ;
T_5 V_352 ;
T_1 V_353 ;
T_1 V_354 ;
struct V_355 * V_356 = (struct V_355 * ) V_350 ;
switch ( V_318 ) {
case V_334 :
case V_335 :
V_352 = V_357 ;
break;
case V_333 :
V_352 = V_358 ;
break;
case V_340 :
V_352 = V_359 ;
break;
case V_341 :
V_352 = V_360 ;
break;
case V_343 :
V_352 = V_361 ;
break;
case V_344 :
V_352 = V_362 ;
break;
case V_346 :
V_352 = V_363 ;
break;
case V_347 :
V_352 = V_364 ;
break;
default:
F_16 ( V_2 , L_29 ,
V_318 ) ;
return - V_78 ;
}
if ( V_351 < sizeof( struct V_355 ) ) {
F_16 ( V_2 , L_30 ,
( unsigned int ) V_351 ) ;
return - V_78 ;
}
if ( V_356 -> V_365 != F_78 ( V_366 ) ) {
F_16 ( V_2 , L_31 ,
F_85 ( V_356 -> V_365 ) ) ;
return - V_78 ;
}
if ( V_356 -> V_352 != V_352 ) {
F_16 ( V_2 , L_32 ,
V_352 , V_356 -> V_352 ) ;
return - V_78 ;
}
if ( V_356 -> V_367 != V_368 ) {
F_16 ( V_2 , L_33 ,
V_368 , V_356 -> V_367 ) ;
return - V_78 ;
}
V_353 = F_85 ( * ( V_369 * ) ( V_350 + V_351 -
sizeof( V_353 ) ) ) ;
V_354 = ~ F_86 ( ~ 0 , V_350 , V_351 - sizeof( V_353 ) ) ;
if ( V_354 != V_353 ) {
F_16 ( V_2 , L_34 ,
( unsigned long ) V_353 ,
( unsigned long ) V_354 ) ;
return - V_78 ;
}
V_28 = F_75 ( V_2 , V_318 , V_370 ,
0 , 0 , V_350 , V_351 ) ;
if ( V_28 == 0 )
V_28 = F_83 ( V_2 , V_318 ) ;
return V_28 ;
}
static int F_87 ( struct V_1 * V_2 ,
T_5 V_318 ,
const T_4 * V_350 ,
T_6 V_351 )
{
struct V_371 * V_372 ;
T_1 V_354 ;
T_1 V_353 ;
int V_28 = 0 ;
if ( V_351 < sizeof( struct V_371 ) ) {
F_16 ( V_2 , L_35 ,
( unsigned int ) V_351 ) ;
return - V_78 ;
}
V_372 = (struct V_371 * ) ( V_350 + ( V_351 -
sizeof( * V_372 ) ) ) ;
if ( V_372 -> V_373 != F_78 ( V_374 ) ) {
F_16 ( V_2 , L_36 ,
F_85 ( V_372 -> V_373 ) ) ;
return - V_78 ;
}
if ( F_46 ( V_372 -> V_318 ) != V_318 ) {
F_16 ( V_2 , L_37 ,
V_318 , F_46 ( V_372 -> V_318 ) ) ;
return - V_78 ;
}
if ( F_46 ( V_372 -> V_375 ) <
sizeof( struct V_371 ) ) {
F_16 ( V_2 , L_38 ,
F_46 ( V_372 -> V_375 ) ) ;
return - V_78 ;
}
V_353 = F_85 ( * ( V_369 * ) ( V_350 + V_351 -
sizeof( V_353 ) ) ) ;
V_354 = ~ F_86 ( ~ 0 , V_350 , V_351 - sizeof( V_353 ) ) ;
if ( V_354 != V_353 ) {
F_16 ( V_2 ,
L_39 ,
( unsigned long ) V_353 ,
( unsigned long ) V_354 ) ;
return - V_78 ;
}
V_28 = F_75 ( V_2 , V_318 , V_370 ,
0 , 0 , V_350 , V_351 ) ;
return V_28 ;
}
static bool F_88 ( T_5 V_318 )
{
switch ( V_318 ) {
case V_333 :
case V_334 :
case V_335 :
case V_340 :
case V_341 :
case V_343 :
case V_344 :
case V_346 :
case V_347 :
return true ;
}
return false ;
}
static bool F_89 ( T_5 V_318 )
{
switch ( V_318 ) {
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
return true ;
}
return false ;
}
static bool F_90 ( T_5 V_318 )
{
return F_88 ( V_318 ) ||
F_89 ( V_318 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
T_5 V_318 ,
const char * V_385 )
{
const struct V_386 * V_387 ;
int V_28 ;
V_28 = F_92 ( & V_387 , V_385 , & V_2 -> V_2 ) ;
if ( V_28 != 0 ) {
F_16 ( V_2 , L_40 ,
V_28 , V_385 ) ;
return V_28 ;
}
if ( F_88 ( V_318 ) == true )
V_28 = F_84 ( V_2 , V_318 , V_387 -> V_102 , V_387 -> V_388 ) ;
else if ( F_89 ( V_318 ) == true )
V_28 = F_87 ( V_2 , V_318 , V_387 -> V_102 , V_387 -> V_388 ) ;
else
V_28 = F_75 ( V_2 , V_318 , V_370 ,
0 , 0 , V_387 -> V_102 , V_387 -> V_388 ) ;
F_93 ( V_387 ) ;
return V_28 ;
}
static int F_94 ( struct V_1 * V_2 ,
char * V_385 , T_1 V_389 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_390 * V_391 = V_4 -> V_392 ;
struct V_393 V_394 = { 0 } ;
const struct V_386 * V_387 ;
T_1 V_395 ;
T_5 V_396 ;
int V_28 ;
F_95 ( V_4 ) ;
if ( F_96 ( V_2 , V_397 ,
V_370 , V_398 ,
& V_396 , & V_395 , NULL ) != 0 ) {
F_16 ( V_2 , L_41 ) ;
return - V_399 ;
}
V_28 = F_92 ( & V_387 , V_385 , & V_2 -> V_2 ) ;
if ( V_28 != 0 ) {
F_16 ( V_2 , L_42 ,
V_28 , V_385 ) ;
return V_28 ;
}
if ( V_387 -> V_388 > V_395 ) {
F_16 ( V_2 , L_43 ,
( unsigned long ) V_387 -> V_388 ) ;
V_28 = - V_400 ;
} else {
T_7 V_325 ;
T_4 * V_326 ;
struct V_401 V_402 = { 0 } ;
F_76 ( V_4 , & V_402 , V_403 , - 1 , - 1 ) ;
V_402 . V_404 = F_77 ( V_396 ) ;
V_402 . V_405 = F_78 ( V_387 -> V_388 ) ;
V_326 = F_79 ( & V_4 -> V_198 -> V_2 , V_387 -> V_388 ,
& V_325 , V_190 ) ;
if ( ! V_326 ) {
F_16 ( V_2 ,
L_28 ,
( unsigned int ) V_387 -> V_388 ) ;
V_28 = - V_96 ;
} else {
memcpy ( V_326 , V_387 -> V_102 , V_387 -> V_388 ) ;
V_402 . V_329 = F_80 ( V_325 ) ;
V_28 = F_81 ( V_4 , & V_402 , sizeof( V_402 ) ,
V_406 ) ;
F_82 ( & V_4 -> V_198 -> V_2 , V_387 -> V_388 , V_326 ,
V_325 ) ;
}
}
F_93 ( V_387 ) ;
if ( V_28 )
return V_28 ;
if ( ( V_389 & 0xffff ) == 0 )
V_389 >>= 16 ;
F_76 ( V_4 , & V_394 , V_407 , - 1 , - 1 ) ;
V_394 . V_389 = F_78 ( V_389 ) ;
V_28 = F_81 ( V_4 , & V_394 , sizeof( V_394 ) ,
V_408 ) ;
if ( V_28 )
return - V_40 ;
if ( V_391 -> V_409 ) {
F_16 ( V_2 , L_44 ,
( V_410 ) V_391 -> V_409 , ( int ) V_391 -> V_411 ) ;
return - V_412 ;
}
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_413 * V_414 )
{
if ( ! F_26 ( (struct V_3 * ) F_2 ( V_2 ) ) ) {
F_16 ( V_2 , L_45 ) ;
return - V_78 ;
}
if ( V_414 -> V_415 == V_416 ||
V_414 -> V_415 > 0xffff )
return F_94 ( V_2 , V_414 -> V_102 ,
V_414 -> V_415 ) ;
return F_91 ( V_2 , V_414 -> V_415 , V_414 -> V_102 ) ;
}
static int F_98 ( struct V_1 * V_2 , T_1 * V_417 , T_1 * V_418 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_419 V_324 = { 0 } ;
struct V_420 * V_421 = V_4 -> V_392 ;
F_76 ( V_4 , & V_324 , V_422 , - 1 , - 1 ) ;
F_99 ( & V_4 -> V_423 ) ;
V_28 = F_100 ( V_4 , & V_324 , sizeof( V_324 ) , V_349 ) ;
if ( ! V_28 ) {
* V_417 = F_85 ( V_421 -> V_417 ) ;
* V_418 = F_85 ( V_421 -> V_424 ) ;
}
F_101 ( & V_4 -> V_423 ) ;
return V_28 ;
}
static int F_102 ( struct V_1 * V_2 )
{
return - 1 ;
}
static int F_103 ( struct V_1 * V_2 , T_1 V_405 , T_4 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
T_1 V_425 ;
T_1 V_424 ;
T_4 * V_43 ;
T_6 V_426 ;
T_7 V_325 ;
struct V_427 V_324 = { 0 } ;
V_28 = F_98 ( V_2 , & V_425 , & V_424 ) ;
if ( V_28 != 0 )
return V_28 ;
if ( V_405 < 2 )
return - V_78 ;
* V_102 ++ = V_425 ;
* V_102 ++ = V_424 ;
V_405 -= 2 ;
memset ( V_102 , 0xff , V_405 ) ;
V_426 = V_425 * V_424 ;
V_43 = F_79 ( & V_4 -> V_198 -> V_2 , V_426 , & V_325 ,
V_190 ) ;
if ( ! V_43 ) {
F_16 ( V_2 , L_28 ,
( unsigned ) V_426 ) ;
return - V_96 ;
}
F_76 ( V_4 , & V_324 , V_428 , - 1 , - 1 ) ;
V_324 . V_429 = F_80 ( V_325 ) ;
V_28 = F_81 ( V_4 , & V_324 , sizeof( V_324 ) , V_349 ) ;
if ( V_28 == 0 )
memcpy ( V_102 , V_43 , V_405 > V_426 ? V_426 : V_405 ) ;
F_82 ( & V_4 -> V_198 -> V_2 , V_426 , V_43 , V_325 ) ;
return V_28 ;
}
static int F_104 ( struct V_1 * V_2 , T_1 V_396 , T_1 V_60 ,
T_1 V_418 , T_4 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
T_4 * V_43 ;
T_7 V_325 ;
struct V_430 V_324 = { 0 } ;
V_43 = F_79 ( & V_4 -> V_198 -> V_2 , V_418 , & V_325 ,
V_190 ) ;
if ( ! V_43 ) {
F_16 ( V_2 , L_28 ,
( unsigned ) V_418 ) ;
return - V_96 ;
}
F_76 ( V_4 , & V_324 , V_431 , - 1 , - 1 ) ;
V_324 . V_429 = F_80 ( V_325 ) ;
V_324 . V_404 = F_77 ( V_396 ) ;
V_324 . V_60 = F_78 ( V_60 ) ;
V_324 . V_405 = F_78 ( V_418 ) ;
V_28 = F_81 ( V_4 , & V_324 , sizeof( V_324 ) , V_349 ) ;
if ( V_28 == 0 )
memcpy ( V_102 , V_43 , V_418 ) ;
F_82 ( & V_4 -> V_198 -> V_2 , V_418 , V_43 , V_325 ) ;
return V_28 ;
}
static int F_96 ( struct V_1 * V_2 , T_5 type , T_5 V_432 ,
T_5 V_433 , T_5 * V_396 , T_1 * V_434 ,
T_1 * V_435 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_436 V_324 = { 0 } ;
struct V_437 * V_421 = V_4 -> V_392 ;
F_76 ( V_4 , & V_324 , V_438 , - 1 , - 1 ) ;
V_324 . V_439 = 0 ;
V_324 . V_404 = 0 ;
V_324 . V_318 = F_77 ( type ) ;
V_324 . V_319 = F_77 ( V_432 ) ;
V_324 . V_320 = F_77 ( V_433 ) ;
V_324 . V_440 = V_441 ;
V_28 = F_105 ( V_4 , & V_324 , sizeof( V_324 ) , V_349 ) ;
if ( V_28 == 0 ) {
if ( V_396 )
* V_396 = F_46 ( V_421 -> V_404 ) ;
if ( V_434 )
* V_434 = F_85 ( V_421 -> V_442 ) ;
if ( V_435 )
* V_435 = F_85 ( V_421 -> V_328 ) ;
}
return V_28 ;
}
static char * F_106 ( int V_443 , T_4 * V_102 , T_6 V_444 )
{
char * V_445 = NULL ;
char * V_446 ;
char * V_6 ;
int V_447 = 0 ;
if ( V_444 < 1 )
return NULL ;
V_102 [ V_444 - 1 ] = 0 ;
for ( V_446 = V_102 ; * V_446 != 0 ; V_446 ++ ) {
V_447 = 0 ;
V_445 = NULL ;
while ( * V_446 != 0 && * V_446 != '\n' ) {
V_6 = V_446 ;
while ( * V_446 != 0 && * V_446 != '\t' && * V_446 != '\n' )
V_446 ++ ;
if ( V_447 == V_443 )
V_445 = V_6 ;
if ( * V_446 != '\t' )
break;
* V_446 = 0 ;
V_447 ++ ;
V_446 ++ ;
}
if ( * V_446 == 0 )
break;
* V_446 = 0 ;
}
return V_445 ;
}
static char * F_49 ( struct V_1 * V_2 , char * V_43 , T_6 V_426 )
{
T_5 V_396 = 0 ;
T_1 V_444 ;
if ( F_96 ( V_2 , V_448 ,
V_370 , V_398 ,
& V_396 , NULL , & V_444 ) != 0 )
return NULL ;
memset ( V_43 , 0 , V_426 ) ;
if ( F_104 ( V_2 , V_396 , 0 , V_444 , V_43 ) != 0 )
return NULL ;
return F_106 ( V_449 , V_43 ,
V_444 ) ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_450 * V_451 ,
T_4 * V_102 )
{
T_1 V_396 ;
T_1 V_60 ;
if ( V_451 -> V_60 == 0 )
return F_103 ( V_2 , V_451 -> V_405 , V_102 ) ;
V_396 = V_451 -> V_60 >> 24 ;
V_60 = V_451 -> V_60 & 0xffffff ;
if ( V_396 == 0 ) {
F_16 ( V_2 , L_46 , V_396 ) ;
return - V_78 ;
}
return F_104 ( V_2 , V_396 - 1 , V_60 , V_451 -> V_405 , V_102 ) ;
}
static int F_108 ( struct V_1 * V_2 , T_4 V_396 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_452 V_324 = { 0 } ;
F_76 ( V_4 , & V_324 , V_453 , - 1 , - 1 ) ;
V_324 . V_404 = F_77 ( V_396 ) ;
return F_81 ( V_4 , & V_324 , sizeof( V_324 ) , V_349 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_450 * V_451 ,
T_4 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 V_396 , V_454 ;
T_5 type , V_433 , V_432 , V_455 ;
if ( ! F_26 ( V_4 ) ) {
F_16 ( V_2 , L_47 ) ;
return - V_78 ;
}
type = V_451 -> V_456 >> 16 ;
if ( type == 0xffff ) {
V_396 = V_451 -> V_456 & 0xff ;
V_454 = V_451 -> V_456 >> 8 ;
if ( V_396 == 0 )
return - V_78 ;
switch ( V_454 ) {
case 0x0e :
if ( V_451 -> V_60 != ~ V_451 -> V_456 )
return - V_78 ;
return F_108 ( V_2 , V_396 - 1 ) ;
default:
return - V_78 ;
}
}
if ( F_90 ( type ) == true )
return - V_40 ;
V_433 = V_451 -> V_456 & 0xffff ;
V_432 = V_451 -> V_60 >> 16 ;
V_455 = V_451 -> V_60 & 0xffff ;
return F_75 ( V_2 , type , V_432 , V_433 , V_455 , V_102 ,
V_451 -> V_405 ) ;
}
static int F_110 ( struct V_1 * V_2 , struct V_457 * V_458 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_457 * V_459 = & V_4 -> V_459 ;
struct V_221 * V_222 = & V_4 -> V_222 ;
T_1 V_229 =
F_54 ( V_222 -> V_229 , 0 ) ;
int V_28 = 0 ;
if ( ! F_67 ( V_4 ) )
return - V_40 ;
if ( ! ( V_4 -> V_37 & V_460 ) )
return - V_40 ;
if ( ! V_458 -> V_461 )
goto V_462;
if ( ! ( V_222 -> V_226 & V_304 ) ) {
F_111 ( V_2 , L_48 ) ;
return - V_78 ;
}
if ( V_458 -> V_463 ) {
if ( V_4 -> V_464 && ( V_458 -> V_465 > V_4 -> V_464 ||
V_458 -> V_465 < V_4 -> V_466 ) ) {
F_111 ( V_2 , L_49 ,
V_4 -> V_466 , V_4 -> V_464 ) ;
return - V_78 ;
} else if ( ! V_4 -> V_464 ) {
V_458 -> V_465 = V_459 -> V_465 ;
}
}
if ( ! V_458 -> V_467 ) {
V_458 -> V_467 = V_229 & V_459 -> V_234 ;
} else if ( V_458 -> V_467 & ~ V_229 ) {
F_111 ( V_2 , L_50 ,
V_458 -> V_467 , V_229 ) ;
return - V_78 ;
}
V_459 -> V_467 = V_458 -> V_467 ;
V_459 -> V_463 = V_458 -> V_463 ;
V_459 -> V_465 = V_458 -> V_465 ;
V_462:
V_459 -> V_461 = V_458 -> V_461 ;
if ( F_8 ( V_2 ) )
V_28 = F_69 ( V_4 , false , true ) ;
return V_28 ;
}
static int F_112 ( struct V_1 * V_2 , struct V_457 * V_458 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! ( V_4 -> V_37 & V_460 ) )
return - V_40 ;
* V_458 = V_4 -> V_459 ;
if ( ! V_4 -> V_459 . V_461 ) {
V_458 -> V_467 = 0 ;
V_458 -> V_463 = 0 ;
}
if ( ! V_4 -> V_459 . V_468 )
V_458 -> V_469 = 0 ;
return 0 ;
}
static int F_113 ( struct V_3 * V_4 , T_5 V_470 ,
T_5 V_471 , T_5 V_472 ,
T_5 V_435 , T_4 * V_43 )
{
struct V_473 V_324 = { 0 } ;
struct V_474 * V_421 = V_4 -> V_392 ;
int V_28 , V_475 = 0 ;
F_76 ( V_4 , & V_324 , V_476 , - 1 , - 1 ) ;
V_324 . V_477 = V_470 ;
V_324 . V_471 = F_77 ( V_471 ) ;
V_324 . V_478 = F_77 ( V_4 -> V_479 . V_478 ) ;
do {
T_5 V_480 ;
V_480 = F_27 ( T_5 , V_435 , V_481 ) ;
V_435 -= V_480 ;
V_324 . V_482 = F_77 ( V_472 + V_475 ) ;
V_324 . V_435 = V_480 ;
V_324 . V_439 = F_78 ( V_472 + V_475 ?
V_483 : 0 ) ;
F_99 ( & V_4 -> V_423 ) ;
V_28 = F_100 ( V_4 , & V_324 , sizeof( V_324 ) ,
V_349 ) ;
if ( ! V_28 )
memcpy ( V_43 + V_475 , V_421 -> V_102 , V_480 ) ;
F_101 ( & V_4 -> V_423 ) ;
V_475 += V_480 ;
} while ( ! V_28 && V_435 > 0 );
return V_28 ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_484 * V_485 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_473 V_324 = { 0 } ;
struct V_474 * V_421 = V_4 -> V_392 ;
int V_28 ;
if ( V_4 -> V_222 . V_486 >
V_487 )
return - V_40 ;
if ( V_4 -> V_314 < 0x10202 )
return - V_40 ;
F_76 ( V_4 , & V_324 , V_476 , - 1 , - 1 ) ;
V_324 . V_477 = V_488 ;
V_324 . V_471 = 0 ;
V_324 . V_482 = F_77 ( V_489 ) ;
V_324 . V_435 = V_490 ;
V_324 . V_478 = F_77 ( V_4 -> V_479 . V_478 ) ;
F_99 ( & V_4 -> V_423 ) ;
V_28 = F_100 ( V_4 , & V_324 , sizeof( V_324 ) , V_349 ) ;
if ( ! V_28 ) {
T_1 V_491 = F_85 ( V_421 -> V_102 [ 0 ] ) ;
switch ( V_491 ) {
case V_492 :
V_485 -> type = V_493 ;
V_485 -> V_494 = V_495 ;
break;
case V_496 :
case V_497 :
V_485 -> type = V_498 ;
V_485 -> V_494 = V_499 ;
break;
case V_500 :
V_485 -> type = V_501 ;
V_485 -> V_494 = V_502 ;
break;
default:
V_28 = - V_40 ;
break;
}
}
F_101 ( & V_4 -> V_423 ) ;
return V_28 ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_450 * V_451 ,
T_4 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_5 V_503 = V_451 -> V_60 , V_418 = V_451 -> V_405 ;
int V_28 = 0 ;
memset ( V_102 , 0 , V_451 -> V_405 ) ;
if ( V_503 < V_499 ) {
if ( V_503 + V_451 -> V_405 > V_499 )
V_418 = V_499 - V_503 ;
V_28 = F_113 ( V_4 , V_488 , 0 ,
V_503 , V_418 , V_102 ) ;
if ( V_28 )
return V_28 ;
V_503 += V_418 ;
V_102 += V_418 ;
V_418 = V_451 -> V_405 - V_418 ;
}
if ( V_418 ) {
V_503 -= V_499 ;
F_113 ( V_4 , V_504 , 1 , V_503 ,
V_418 , V_102 ) ;
}
return V_28 ;
}
static int F_116 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_221 * V_222 = & V_4 -> V_222 ;
if ( ! F_67 ( V_4 ) )
return - V_40 ;
if ( ! ( V_222 -> V_226 & V_304 ) )
return - V_78 ;
if ( F_8 ( V_2 ) )
V_28 = F_69 ( V_4 , true , false ) ;
return V_28 ;
}
