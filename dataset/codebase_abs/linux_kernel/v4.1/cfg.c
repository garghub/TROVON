static struct V_1 * F_1 ( struct V_2 * V_2 ,
const char * V_3 ,
unsigned char V_4 ,
enum V_5 type ,
T_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_1 * V_11 ;
struct V_12 * V_13 ;
int V_14 ;
V_14 = F_3 ( V_10 , V_3 , V_4 , & V_11 , type , V_8 ) ;
if ( V_14 )
return F_4 ( V_14 ) ;
if ( type == V_15 && V_6 ) {
V_13 = F_5 ( V_11 ) ;
V_13 -> V_16 . V_17 = * V_6 ;
}
return V_11 ;
}
static int F_6 ( struct V_2 * V_2 , struct V_1 * V_11 )
{
F_7 ( F_5 ( V_11 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
enum V_5 type , T_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
int V_20 ;
V_20 = F_10 ( V_13 , type ) ;
if ( V_20 )
return V_20 ;
if ( type == V_21 &&
V_8 && V_8 -> V_22 == 0 )
F_11 ( V_13 -> V_16 . V_23 . V_24 , NULL ) ;
else if ( type == V_25 &&
V_8 && V_8 -> V_22 >= 0 )
V_13 -> V_16 . V_26 . V_22 = V_8 -> V_22 ;
if ( V_13 -> V_27 . type == V_15 && V_6 ) {
struct V_9 * V_10 = V_13 -> V_10 ;
if ( F_12 ( V_13 ) ) {
T_1 V_28 = V_29 |
V_30 ;
if ( ( * V_6 & V_28 ) != ( V_13 -> V_16 . V_17 & V_28 ) )
return - V_31 ;
F_13 ( V_13 , - 1 ) ;
V_13 -> V_16 . V_17 = * V_6 ;
F_13 ( V_13 , 1 ) ;
F_14 ( V_10 ) ;
} else {
V_13 -> V_16 . V_17 = * V_6 ;
}
}
return 0 ;
}
static int F_15 ( struct V_2 * V_2 ,
struct V_1 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_20 ;
F_16 ( & V_13 -> V_10 -> V_32 ) ;
V_20 = F_17 ( V_13 , NULL , 0 , 0 ) ;
F_18 ( & V_13 -> V_10 -> V_32 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_19 ( V_11 , true ) ;
}
static void F_20 ( struct V_2 * V_2 ,
struct V_1 * V_11 )
{
F_21 ( F_5 ( V_11 ) ) ;
}
static int F_22 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_2 V_33 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
V_13 -> V_33 = V_33 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_34 , bool V_35 , const T_3 * V_36 ,
struct V_37 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 = NULL ;
const struct V_39 * V_40 = NULL ;
struct V_41 * V_42 ;
int V_14 ;
if ( ! F_12 ( V_13 ) )
return - V_43 ;
switch ( V_8 -> V_44 ) {
case V_45 :
case V_46 :
case V_47 :
if ( F_24 ( V_10 -> V_48 ) )
return - V_49 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
break;
default:
V_40 = F_25 ( V_10 , V_8 -> V_44 , V_13 -> V_27 . type ) ;
break;
}
V_42 = F_26 ( V_8 -> V_44 , V_34 , V_8 -> V_58 ,
V_8 -> V_42 , V_8 -> V_59 , V_8 -> V_60 ,
V_40 ) ;
if ( F_24 ( V_42 ) )
return F_27 ( V_42 ) ;
if ( V_35 )
V_42 -> V_61 . V_6 |= V_62 ;
F_16 ( & V_10 -> V_63 ) ;
if ( V_36 ) {
if ( F_28 ( & V_13 -> V_27 ) )
V_24 = F_29 ( V_13 , V_36 ) ;
else
V_24 = F_30 ( V_13 , V_36 ) ;
if ( ! V_24 || ! F_31 ( V_24 , V_64 ) ) {
F_32 ( V_42 ) ;
V_14 = - V_65 ;
goto V_66;
}
}
switch ( V_13 -> V_27 . type ) {
case V_25 :
if ( V_13 -> V_16 . V_26 . V_67 != V_68 )
V_42 -> V_61 . V_6 |= V_69 ;
break;
case V_70 :
case V_21 :
if ( V_42 -> V_24 && F_31 ( V_42 -> V_24 , V_71 ) )
V_42 -> V_61 . V_6 |= V_69 ;
break;
case V_72 :
break;
case V_73 :
#ifdef F_33
if ( V_13 -> V_16 . V_74 . V_75 != V_76 )
V_42 -> V_61 . V_6 |= V_69 ;
break;
#endif
case V_77 :
case V_15 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
F_34 ( 1 ) ;
break;
}
if ( V_24 )
V_24 -> V_84 = V_40 ;
V_14 = F_35 ( V_42 , V_13 , V_24 ) ;
V_66:
F_18 ( & V_10 -> V_63 ) ;
return V_14 ;
}
static int F_36 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_34 , bool V_35 , const T_3 * V_36 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
struct V_41 * V_42 = NULL ;
int V_20 ;
F_16 ( & V_10 -> V_63 ) ;
F_16 ( & V_10 -> V_85 ) ;
if ( V_36 ) {
V_20 = - V_65 ;
V_24 = F_30 ( V_13 , V_36 ) ;
if ( ! V_24 )
goto V_66;
if ( V_35 )
V_42 = F_37 ( V_10 , V_24 -> V_86 [ V_34 ] ) ;
else
V_42 = F_37 ( V_10 , V_24 -> V_87 [ V_34 ] ) ;
} else
V_42 = F_37 ( V_10 , V_13 -> V_88 [ V_34 ] ) ;
if ( ! V_42 ) {
V_20 = - V_65 ;
goto V_66;
}
F_38 ( V_42 , true ) ;
V_20 = 0 ;
V_66:
F_18 ( & V_10 -> V_85 ) ;
F_18 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_39 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_34 , bool V_35 , const T_3 * V_36 ,
void * V_89 ,
void (* F_40)( void * V_89 ,
struct V_37 * V_8 ) )
{
struct V_12 * V_13 ;
struct V_38 * V_24 = NULL ;
T_3 V_60 [ 6 ] = { 0 } ;
struct V_37 V_8 ;
struct V_41 * V_42 = NULL ;
T_4 V_90 ;
T_1 V_91 ;
T_2 V_92 ;
int V_14 = - V_65 ;
V_13 = F_9 ( V_19 ) ;
F_41 () ;
if ( V_36 ) {
V_24 = F_30 ( V_13 , V_36 ) ;
if ( ! V_24 )
goto V_93;
if ( V_35 && V_34 < V_94 )
V_42 = F_42 ( V_24 -> V_86 [ V_34 ] ) ;
else if ( ! V_35 &&
V_34 < V_94 + V_95 )
V_42 = F_42 ( V_24 -> V_87 [ V_34 ] ) ;
} else
V_42 = F_42 ( V_13 -> V_88 [ V_34 ] ) ;
if ( ! V_42 )
goto V_93;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_44 = V_42 -> V_61 . V_44 ;
switch ( V_42 -> V_61 . V_44 ) {
case V_46 :
V_91 = V_42 -> V_16 . V_96 . V_97 . V_91 ;
V_92 = V_42 -> V_16 . V_96 . V_97 . V_92 ;
if ( V_42 -> V_6 & V_98 )
F_43 ( V_13 -> V_10 ,
V_42 -> V_61 . V_99 ,
& V_91 , & V_92 ) ;
V_60 [ 0 ] = V_92 & 0xff ;
V_60 [ 1 ] = ( V_92 >> 8 ) & 0xff ;
V_60 [ 2 ] = V_91 & 0xff ;
V_60 [ 3 ] = ( V_91 >> 8 ) & 0xff ;
V_60 [ 4 ] = ( V_91 >> 16 ) & 0xff ;
V_60 [ 5 ] = ( V_91 >> 24 ) & 0xff ;
V_8 . V_60 = V_60 ;
V_8 . V_59 = 6 ;
break;
case V_50 :
case V_51 :
V_90 = F_44 ( & V_42 -> V_16 . V_100 . V_101 ) ;
V_60 [ 0 ] = V_90 ;
V_60 [ 1 ] = V_90 >> 8 ;
V_60 [ 2 ] = V_90 >> 16 ;
V_60 [ 3 ] = V_90 >> 24 ;
V_60 [ 4 ] = V_90 >> 32 ;
V_60 [ 5 ] = V_90 >> 40 ;
V_8 . V_60 = V_60 ;
V_8 . V_59 = 6 ;
break;
case V_52 :
case V_53 :
V_90 = F_44 ( & V_42 -> V_16 . V_102 . V_101 ) ;
V_60 [ 0 ] = V_90 ;
V_60 [ 1 ] = V_90 >> 8 ;
V_60 [ 2 ] = V_90 >> 16 ;
V_60 [ 3 ] = V_90 >> 24 ;
V_60 [ 4 ] = V_90 >> 32 ;
V_60 [ 5 ] = V_90 >> 40 ;
V_8 . V_60 = V_60 ;
V_8 . V_59 = 6 ;
break;
case V_54 :
case V_55 :
V_90 = F_44 ( & V_42 -> V_16 . V_103 . V_101 ) ;
V_60 [ 0 ] = V_90 ;
V_60 [ 1 ] = V_90 >> 8 ;
V_60 [ 2 ] = V_90 >> 16 ;
V_60 [ 3 ] = V_90 >> 24 ;
V_60 [ 4 ] = V_90 >> 32 ;
V_60 [ 5 ] = V_90 >> 40 ;
V_8 . V_60 = V_60 ;
V_8 . V_59 = 6 ;
break;
case V_56 :
case V_57 :
V_90 = F_44 ( & V_42 -> V_16 . V_104 . V_101 ) ;
V_60 [ 0 ] = V_90 ;
V_60 [ 1 ] = V_90 >> 8 ;
V_60 [ 2 ] = V_90 >> 16 ;
V_60 [ 3 ] = V_90 >> 24 ;
V_60 [ 4 ] = V_90 >> 32 ;
V_60 [ 5 ] = V_90 >> 40 ;
V_8 . V_60 = V_60 ;
V_8 . V_59 = 6 ;
break;
}
V_8 . V_42 = V_42 -> V_61 . V_42 ;
V_8 . V_58 = V_42 -> V_61 . V_105 ;
F_40 ( V_89 , & V_8 ) ;
V_14 = 0 ;
V_93:
F_45 () ;
return V_14 ;
}
static int F_46 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_3 V_34 , bool V_106 ,
bool V_107 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_47 ( V_13 , V_34 , V_106 , V_107 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_3 V_34 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_49 ( V_13 , V_34 ) ;
return 0 ;
}
void F_50 ( struct V_38 * V_24 ,
const struct V_108 * V_109 ,
struct V_110 * V_111 )
{
V_111 -> V_6 = 0 ;
if ( V_109 -> V_6 & V_112 ) {
V_111 -> V_6 |= V_113 ;
V_111 -> V_114 = V_109 -> V_115 ;
} else if ( V_109 -> V_6 & V_116 ) {
V_111 -> V_6 |= V_117 ;
V_111 -> V_114 = F_51 ( V_109 ) ;
V_111 -> V_118 = F_52 ( V_109 ) ;
} else {
struct V_119 * V_120 ;
int V_121 = F_53 ( & V_24 -> V_13 -> V_27 ) ;
T_2 V_122 ;
V_120 = V_24 -> V_10 -> V_123 . V_2 -> V_124 [
F_54 ( V_24 -> V_13 ) ] ;
V_122 = V_120 -> V_125 [ V_109 -> V_115 ] . V_126 ;
V_111 -> V_127 = F_55 ( V_122 , 1 << V_121 ) ;
}
if ( V_109 -> V_6 & V_128 )
V_111 -> V_129 = V_130 ;
else if ( V_109 -> V_6 & V_131 )
V_111 -> V_129 = V_132 ;
else if ( V_109 -> V_6 & V_133 )
V_111 -> V_129 = V_134 ;
else
V_111 -> V_129 = V_135 ;
if ( V_109 -> V_6 & V_136 )
V_111 -> V_6 |= V_137 ;
}
void F_56 ( struct V_38 * V_24 , struct V_110 * V_111 )
{
V_111 -> V_6 = 0 ;
if ( V_24 -> V_138 & V_139 ) {
V_111 -> V_6 |= V_113 ;
V_111 -> V_114 = V_24 -> V_140 ;
} else if ( V_24 -> V_138 & V_141 ) {
V_111 -> V_6 |= V_117 ;
V_111 -> V_118 = V_24 -> V_142 ;
V_111 -> V_114 = V_24 -> V_140 ;
} else {
struct V_119 * V_120 ;
int V_121 = F_53 ( & V_24 -> V_13 -> V_27 ) ;
T_2 V_122 ;
V_120 = V_24 -> V_10 -> V_123 . V_2 -> V_124 [
F_54 ( V_24 -> V_13 ) ] ;
V_122 = V_120 -> V_125 [ V_24 -> V_140 ] . V_126 ;
V_111 -> V_127 = F_55 ( V_122 , 1 << V_121 ) ;
}
if ( V_24 -> V_138 & V_143 )
V_111 -> V_6 |= V_137 ;
if ( V_24 -> V_138 & V_144 )
V_111 -> V_129 = V_145 ;
else if ( V_24 -> V_138 & V_146 )
V_111 -> V_129 = V_147 ;
else if ( V_24 -> V_138 & V_148 )
V_111 -> V_129 = V_130 ;
else if ( V_24 -> V_149 & V_150 )
V_111 -> V_129 = V_132 ;
else if ( V_24 -> V_149 & V_151 )
V_111 -> V_129 = V_134 ;
else
V_111 -> V_129 = V_135 ;
}
static int F_57 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_115 , T_3 * V_152 , struct V_153 * V_154 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
int V_20 = - V_65 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_58 ( V_13 , V_115 ) ;
if ( V_24 ) {
V_20 = 0 ;
memcpy ( V_152 , V_24 -> V_24 . V_155 , V_156 ) ;
F_59 ( V_24 , V_154 ) ;
}
F_18 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_60 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_115 , struct V_157 * V_158 )
{
struct V_9 * V_10 = F_61 ( V_19 -> V_159 ) ;
return F_62 ( V_10 , V_115 , V_158 ) ;
}
static int F_63 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_152 , struct V_153 * V_154 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
int V_20 = - V_65 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_30 ( V_13 , V_152 ) ;
if ( V_24 ) {
V_20 = 0 ;
F_59 ( V_24 , V_154 ) ;
}
F_18 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_64 ( struct V_2 * V_2 ,
struct V_160 * V_161 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
int V_20 = 0 ;
if ( F_65 ( & V_10 -> V_162 , V_161 ) )
return 0 ;
F_16 ( & V_10 -> V_163 ) ;
F_16 ( & V_10 -> V_164 ) ;
if ( V_10 -> V_165 ) {
V_13 = F_66 (
V_10 -> V_166 ,
F_67 ( & V_10 -> V_164 ) ) ;
if ( V_13 ) {
F_68 ( V_13 ) ;
V_20 = F_69 ( V_13 , V_161 ,
V_167 ) ;
}
} else if ( V_10 -> V_168 == V_10 -> V_169 ) {
V_10 -> V_170 = * V_161 ;
F_70 ( V_10 , 0 ) ;
}
if ( V_20 == 0 )
V_10 -> V_162 = * V_161 ;
F_18 ( & V_10 -> V_164 ) ;
F_18 ( & V_10 -> V_163 ) ;
return V_20 ;
}
static int F_71 ( struct V_12 * V_13 ,
const T_3 * V_171 , T_5 V_172 ,
const struct V_173 * V_174 )
{
struct V_175 * V_176 , * V_177 ;
if ( ! V_171 || ! V_172 )
return 1 ;
V_177 = F_72 ( V_13 -> V_16 . V_178 . V_175 , V_13 ) ;
V_176 = F_73 ( sizeof( struct V_175 ) + V_172 , V_179 ) ;
if ( ! V_176 )
return - V_180 ;
V_176 -> V_181 = V_172 ;
memcpy ( V_176 -> V_182 , V_171 , V_172 ) ;
if ( V_174 )
memcpy ( V_176 -> V_183 , V_174 -> V_184 ,
V_174 -> V_185 *
sizeof( V_176 -> V_183 [ 0 ] ) ) ;
F_74 ( V_13 -> V_16 . V_178 . V_175 , V_176 ) ;
if ( V_177 )
F_75 ( V_177 , V_186 ) ;
return 0 ;
}
static int F_76 ( struct V_12 * V_13 ,
struct V_187 * V_8 ,
const struct V_173 * V_174 )
{
struct V_188 * V_176 , * V_177 ;
int V_189 , V_190 ;
int V_191 , V_14 ;
T_1 V_192 = V_193 ;
V_177 = F_72 ( V_13 -> V_16 . V_178 . V_194 , V_13 ) ;
if ( ! V_8 -> V_195 && ! V_177 )
return - V_49 ;
if ( V_8 -> V_195 )
V_189 = V_8 -> V_196 ;
else
V_189 = V_177 -> V_196 ;
if ( V_8 -> V_197 || ! V_177 )
V_190 = V_8 -> V_198 ;
else
V_190 = V_177 -> V_198 ;
V_191 = sizeof( * V_176 ) + V_189 + V_190 ;
V_176 = F_73 ( V_191 , V_179 ) ;
if ( ! V_176 )
return - V_180 ;
V_176 -> V_195 = ( ( T_3 * ) V_176 ) + sizeof( * V_176 ) ;
V_176 -> V_197 = V_176 -> V_195 + V_189 ;
V_176 -> V_196 = V_189 ;
V_176 -> V_198 = V_190 ;
if ( V_174 ) {
V_176 -> V_199 = V_174 -> V_200 ;
memcpy ( V_176 -> V_183 , V_174 -> V_201 ,
V_174 -> V_202 *
sizeof( V_176 -> V_183 [ 0 ] ) ) ;
}
if ( V_8 -> V_195 )
memcpy ( V_176 -> V_195 , V_8 -> V_195 , V_189 ) ;
else
memcpy ( V_176 -> V_195 , V_177 -> V_195 , V_189 ) ;
if ( V_8 -> V_197 )
memcpy ( V_176 -> V_197 , V_8 -> V_197 , V_190 ) ;
else
if ( V_177 )
memcpy ( V_176 -> V_197 , V_177 -> V_197 , V_190 ) ;
V_14 = F_71 ( V_13 , V_8 -> V_175 ,
V_8 -> V_203 , V_174 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == 0 )
V_192 |= V_204 ;
F_74 ( V_13 -> V_16 . V_178 . V_194 , V_176 ) ;
if ( V_177 )
F_75 ( V_177 , V_186 ) ;
return V_192 ;
}
static int F_77 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_205 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_188 * V_177 ;
struct V_12 * V_23 ;
T_1 V_192 = V_206 |
V_207 |
V_193 |
V_208 |
V_209 |
V_210 ;
int V_14 ;
V_177 = F_72 ( V_13 -> V_16 . V_178 . V_194 , V_13 ) ;
if ( V_177 )
return - V_211 ;
switch ( V_8 -> V_212 ) {
case V_213 :
V_13 -> V_212 = V_214 ;
break;
case V_215 :
V_13 -> V_212 = V_216 ;
break;
case V_217 :
V_13 -> V_212 = V_218 ;
break;
default:
return - V_49 ;
}
V_13 -> V_219 = V_13 -> V_10 -> V_220 ;
F_16 ( & V_10 -> V_163 ) ;
V_14 = F_69 ( V_13 , & V_8 -> V_161 ,
V_221 ) ;
if ( ! V_14 )
F_78 ( V_13 , false ) ;
F_18 ( & V_10 -> V_163 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_222 = V_8 -> V_223 . V_224 ;
V_13 -> V_225 = V_8 -> V_223 . V_225 ;
V_13 -> V_226 = F_79 ( V_13 -> V_10 ,
& V_8 -> V_223 ,
V_13 -> V_27 . type ) ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_23 -> V_222 =
V_8 -> V_223 . V_224 ;
V_23 -> V_225 =
V_8 -> V_223 . V_225 ;
V_23 -> V_226 =
F_79 ( V_13 -> V_10 ,
& V_8 -> V_223 ,
V_23 -> V_27 . type ) ;
}
V_13 -> V_27 . V_227 . V_228 = V_8 -> V_229 ;
V_13 -> V_27 . V_227 . V_230 = V_8 -> V_230 ;
V_13 -> V_27 . V_227 . V_231 = true ;
V_13 -> V_27 . V_227 . V_232 = V_8 -> V_232 ;
if ( V_8 -> V_232 )
memcpy ( V_13 -> V_27 . V_227 . V_233 , V_8 -> V_233 ,
V_8 -> V_232 ) ;
V_13 -> V_27 . V_227 . V_234 =
( V_8 -> V_234 != V_235 ) ;
memset ( & V_13 -> V_27 . V_227 . V_236 , 0 ,
sizeof( V_13 -> V_27 . V_227 . V_236 ) ) ;
V_13 -> V_27 . V_227 . V_236 . V_237 =
V_8 -> V_238 & V_239 ;
if ( V_8 -> V_240 )
V_13 -> V_27 . V_227 . V_236 . V_237 |=
V_241 ;
V_14 = F_76 ( V_13 , & V_8 -> V_194 , NULL ) ;
if ( V_14 < 0 ) {
F_68 ( V_13 ) ;
return V_14 ;
}
V_192 |= V_14 ;
V_14 = F_81 ( V_13 -> V_10 , V_13 ) ;
if ( V_14 ) {
V_177 = F_72 ( V_13 -> V_16 . V_178 . V_194 , V_13 ) ;
if ( V_177 )
F_75 ( V_177 , V_186 ) ;
F_11 ( V_13 -> V_16 . V_178 . V_194 , NULL ) ;
F_68 ( V_13 ) ;
return V_14 ;
}
F_82 ( V_10 , V_13 ) ;
F_83 ( V_13 , V_192 ) ;
F_84 ( V_19 ) ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_84 ( V_23 -> V_19 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_187 * V_8 )
{
struct V_12 * V_13 ;
struct V_188 * V_177 ;
int V_14 ;
V_13 = F_9 ( V_19 ) ;
F_86 ( V_13 ) ;
if ( V_13 -> V_27 . V_242 )
return - V_31 ;
V_177 = F_72 ( V_13 -> V_16 . V_178 . V_194 , V_13 ) ;
if ( ! V_177 )
return - V_65 ;
V_14 = F_76 ( V_13 , V_8 , NULL ) ;
if ( V_14 < 0 )
return V_14 ;
F_83 ( V_13 , V_14 ) ;
return 0 ;
}
static int F_87 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_12 * V_23 ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_188 * V_243 ;
struct V_175 * V_244 ;
struct V_160 V_161 ;
F_86 ( V_13 ) ;
V_243 = F_72 ( V_13 -> V_16 . V_178 . V_194 , V_13 ) ;
if ( ! V_243 )
return - V_65 ;
V_244 = F_72 ( V_13 -> V_16 . V_178 . V_175 , V_13 ) ;
F_16 ( & V_10 -> V_163 ) ;
V_13 -> V_27 . V_242 = false ;
if ( V_13 -> V_245 ) {
F_88 ( V_10 , V_13 ,
V_246 ) ;
V_13 -> V_245 = false ;
}
F_18 ( & V_10 -> V_163 ) ;
F_89 ( V_13 -> V_16 . V_178 . V_247 ) ;
V_13 -> V_16 . V_178 . V_247 = NULL ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_90 ( V_23 -> V_19 ) ;
F_90 ( V_19 ) ;
F_11 ( V_13 -> V_16 . V_178 . V_194 , NULL ) ;
F_11 ( V_13 -> V_16 . V_178 . V_175 , NULL ) ;
F_75 ( V_243 , V_186 ) ;
if ( V_244 )
F_75 ( V_244 , V_186 ) ;
V_13 -> V_16 . V_178 . V_248 = V_214 ;
F_91 ( V_13 , true ) ;
F_92 ( V_13 , true ) ;
V_13 -> V_27 . V_227 . V_231 = false ;
V_13 -> V_27 . V_227 . V_232 = 0 ;
F_93 ( V_249 , & V_13 -> V_250 ) ;
F_83 ( V_13 , V_207 ) ;
if ( V_13 -> V_11 . V_251 ) {
V_161 = V_13 -> V_27 . V_227 . V_161 ;
F_94 ( & V_13 -> V_252 ) ;
F_95 ( V_13 -> V_19 , & V_161 ,
V_253 ,
V_179 ) ;
}
F_96 ( V_13 -> V_10 , V_13 ) ;
V_10 -> V_254 -= F_97 ( & V_13 -> V_16 . V_178 . V_255 . V_256 ) ;
F_98 ( & V_13 -> V_16 . V_178 . V_255 . V_256 ) ;
F_16 ( & V_10 -> V_163 ) ;
F_78 ( V_13 , true ) ;
F_68 ( V_13 ) ;
F_18 ( & V_10 -> V_163 ) ;
return 0 ;
}
static void F_99 ( struct V_38 * V_24 )
{
struct V_257 * V_258 ;
struct V_259 * V_260 ;
V_260 = F_100 ( sizeof( * V_258 ) ) ;
if ( ! V_260 )
return;
V_258 = (struct V_257 * ) F_101 ( V_260 , sizeof( * V_258 ) ) ;
F_102 ( V_258 -> V_261 ) ;
memcpy ( V_258 -> V_262 , V_24 -> V_24 . V_155 , V_156 ) ;
V_258 -> V_181 = F_103 ( 6 ) ;
V_258 -> V_263 = 0 ;
V_258 -> V_264 = 0x01 ;
V_258 -> V_265 = 0xaf ;
V_258 -> V_266 [ 0 ] = 0x81 ;
V_258 -> V_266 [ 1 ] = 1 ;
V_258 -> V_266 [ 2 ] = 0 ;
V_260 -> V_19 = V_24 -> V_13 -> V_19 ;
V_260 -> V_267 = F_104 ( V_260 , V_24 -> V_13 -> V_19 ) ;
memset ( V_260 -> V_268 , 0 , sizeof( V_260 -> V_268 ) ) ;
F_105 ( V_260 ) ;
}
static int F_106 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
T_1 V_28 , T_1 V_269 )
{
int V_20 ;
if ( V_28 & F_107 ( V_270 ) &&
V_269 & F_107 ( V_270 ) &&
! F_31 ( V_24 , V_271 ) ) {
V_20 = F_108 ( V_24 , V_272 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_107 ( V_273 ) &&
V_269 & F_107 ( V_273 ) &&
! F_31 ( V_24 , V_64 ) ) {
if ( F_31 ( V_24 , V_274 ) )
F_109 ( V_24 ) ;
V_20 = F_108 ( V_24 , V_275 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_107 ( V_276 ) ) {
if ( V_269 & F_107 ( V_276 ) )
V_20 = F_108 ( V_24 , V_277 ) ;
else if ( F_31 ( V_24 , V_278 ) )
V_20 = F_108 ( V_24 , V_275 ) ;
else
V_20 = 0 ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_107 ( V_273 ) &&
! ( V_269 & F_107 ( V_273 ) ) &&
F_31 ( V_24 , V_64 ) ) {
V_20 = F_108 ( V_24 , V_272 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_107 ( V_270 ) &&
! ( V_269 & F_107 ( V_270 ) ) &&
F_31 ( V_24 , V_271 ) ) {
V_20 = F_108 ( V_24 , V_279 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_110 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
struct V_280 * V_8 )
{
int V_20 = 0 ;
struct V_119 * V_120 ;
struct V_12 * V_13 = V_24 -> V_13 ;
enum V_281 V_282 = F_54 ( V_13 ) ;
T_1 V_28 , V_269 ;
V_120 = V_10 -> V_123 . V_2 -> V_124 [ V_282 ] ;
V_28 = V_8 -> V_283 ;
V_269 = V_8 -> V_284 ;
if ( F_28 ( & V_13 -> V_27 ) ) {
if ( V_28 & F_107 ( V_270 ) )
V_28 |= F_107 ( V_273 ) ;
if ( V_269 & F_107 ( V_270 ) )
V_269 |= F_107 ( V_273 ) ;
} else if ( F_31 ( V_24 , V_274 ) ) {
if ( V_269 & F_107 ( V_276 ) ) {
V_269 |= F_107 ( V_270 ) |
F_107 ( V_273 ) ;
V_28 |= F_107 ( V_270 ) |
F_107 ( V_273 ) ;
}
}
if ( V_28 & F_107 ( V_285 ) &&
V_10 -> V_123 . V_286 >= V_287 )
V_24 -> V_24 . V_288 = V_269 & F_107 ( V_285 ) ;
if ( ! F_31 ( V_24 , V_274 ) ) {
V_20 = F_106 ( V_10 , V_24 , V_28 , V_269 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_107 ( V_289 ) ) {
if ( V_269 & F_107 ( V_289 ) )
F_111 ( V_24 , V_290 ) ;
else
F_112 ( V_24 , V_290 ) ;
}
if ( V_28 & F_107 ( V_291 ) ) {
V_24 -> V_24 . V_67 = ! ! ( V_269 & F_107 ( V_291 ) ) ;
if ( V_269 & F_107 ( V_291 ) )
F_111 ( V_24 , V_71 ) ;
else
F_112 ( V_24 , V_71 ) ;
}
if ( V_28 & F_107 ( V_292 ) ) {
if ( V_269 & F_107 ( V_292 ) )
F_111 ( V_24 , V_274 ) ;
else
F_112 ( V_24 , V_274 ) ;
}
if ( F_31 ( V_24 , V_274 ) &&
! V_13 -> V_16 . V_26 . V_293 &&
V_8 -> V_294 >= 4 &&
V_8 -> V_295 [ 3 ] & V_296 )
F_111 ( V_24 , V_297 ) ;
if ( V_8 -> V_298 & V_299 ) {
V_24 -> V_24 . V_300 = V_8 -> V_300 ;
V_24 -> V_24 . V_301 = V_8 -> V_301 ;
}
if ( V_8 -> V_302 )
V_24 -> V_24 . V_302 = V_8 -> V_302 ;
if ( V_8 -> V_303 >= 0 )
V_24 -> V_303 = V_8 -> V_303 ;
if ( V_8 -> V_304 ) {
F_113 ( & V_13 -> V_27 . V_227 . V_161 ,
V_120 , V_8 -> V_304 ,
V_8 -> V_305 ,
& V_24 -> V_24 . V_306 [ V_282 ] ) ;
}
if ( V_8 -> V_307 )
F_114 ( V_13 , V_120 ,
V_8 -> V_307 , V_24 ) ;
if ( V_8 -> V_308 )
F_115 ( V_13 , V_120 ,
V_8 -> V_308 , V_24 ) ;
if ( V_8 -> V_309 ) {
F_116 ( V_13 , V_24 ,
V_8 -> V_310 ,
V_282 , false ) ;
}
if ( F_28 ( & V_13 -> V_27 ) ) {
#ifdef F_33
T_1 V_192 = 0 ;
if ( V_8 -> V_298 & V_311 ) {
switch ( V_8 -> V_312 ) {
case V_313 :
if ( V_24 -> V_312 != V_313 )
V_192 = F_117 (
V_13 ) ;
V_24 -> V_312 = V_8 -> V_312 ;
F_118 ( V_24 ) ;
V_192 |= F_119 ( V_24 ,
V_13 -> V_16 . V_74 . V_314 . V_315 ) ;
break;
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
if ( V_24 -> V_312 == V_313 )
V_192 = F_120 (
V_13 ) ;
V_24 -> V_312 = V_8 -> V_312 ;
F_118 ( V_24 ) ;
V_192 |= F_119 ( V_24 ,
V_322 ) ;
break;
default:
break;
}
}
switch ( V_8 -> V_323 ) {
case V_324 :
break;
case V_325 :
V_192 |= F_121 ( V_24 ) ;
break;
case V_326 :
V_192 |= F_122 ( V_24 ) ;
break;
}
if ( V_8 -> V_327 )
V_192 |=
F_119 ( V_24 ,
V_8 -> V_327 ) ;
F_123 ( V_13 , V_192 ) ;
#endif
}
if ( F_31 ( V_24 , V_274 ) ) {
V_20 = F_106 ( V_10 , V_24 , V_28 , V_269 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_124 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_152 ,
struct V_280 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_38 * V_24 ;
struct V_12 * V_13 ;
int V_14 ;
int V_328 ;
if ( V_8 -> V_23 ) {
V_13 = F_9 ( V_8 -> V_23 ) ;
if ( V_13 -> V_27 . type != V_21 &&
V_13 -> V_27 . type != V_70 )
return - V_49 ;
} else
V_13 = F_9 ( V_19 ) ;
if ( F_125 ( V_152 , V_13 -> V_27 . V_155 ) )
return - V_49 ;
if ( F_126 ( V_152 ) )
return - V_49 ;
V_24 = F_127 ( V_13 , V_152 , V_179 ) ;
if ( ! V_24 )
return - V_180 ;
if ( ! ( V_8 -> V_284 & F_107 ( V_292 ) ) ) {
F_128 ( V_24 , V_272 ) ;
F_128 ( V_24 , V_275 ) ;
} else {
V_24 -> V_24 . V_329 = true ;
}
V_14 = F_110 ( V_10 , V_24 , V_8 ) ;
if ( V_14 ) {
F_129 ( V_10 , V_24 ) ;
return V_14 ;
}
if ( ! F_31 ( V_24 , V_274 ) )
F_109 ( V_24 ) ;
V_328 = V_13 -> V_27 . type == V_21 ||
V_13 -> V_27 . type == V_70 ;
V_14 = F_130 ( V_24 ) ;
if ( V_14 ) {
F_45 () ;
return V_14 ;
}
if ( V_328 )
F_99 ( V_24 ) ;
F_45 () ;
return 0 ;
}
static int F_131 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_330 * V_8 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
if ( V_8 -> V_152 )
return F_132 ( V_13 , V_8 -> V_152 ) ;
F_133 ( V_13 ) ;
return 0 ;
}
static int F_134 ( struct V_2 * V_2 ,
struct V_18 * V_19 , const T_3 * V_152 ,
struct V_280 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_38 * V_24 ;
struct V_12 * V_331 ;
enum V_332 V_333 ;
int V_14 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_30 ( V_13 , V_152 ) ;
if ( ! V_24 ) {
V_14 = - V_65 ;
goto V_334;
}
switch ( V_13 -> V_27 . type ) {
case V_73 :
if ( V_13 -> V_16 . V_74 . V_335 )
V_333 = V_336 ;
else
V_333 = V_337 ;
break;
case V_72 :
V_333 = V_338 ;
break;
case V_25 :
if ( ! F_31 ( V_24 , V_274 ) ) {
V_333 = V_339 ;
break;
}
if ( F_31 ( V_24 , V_278 ) )
V_333 = V_340 ;
else
V_333 = V_341 ;
break;
case V_70 :
case V_21 :
V_333 = V_342 ;
break;
default:
V_14 = - V_343 ;
goto V_334;
}
V_14 = F_135 ( V_2 , V_8 , V_333 ) ;
if ( V_14 )
goto V_334;
if ( V_8 -> V_23 && V_8 -> V_23 != V_24 -> V_13 -> V_19 ) {
bool V_344 = false ;
bool V_345 = false ;
V_331 = F_9 ( V_8 -> V_23 ) ;
if ( V_8 -> V_23 -> V_159 -> V_22 ) {
if ( V_331 -> V_16 . V_23 . V_24 ) {
V_14 = - V_31 ;
goto V_334;
}
F_74 ( V_331 -> V_16 . V_23 . V_24 , V_24 ) ;
V_345 = true ;
}
if ( V_24 -> V_13 -> V_27 . type == V_21 &&
V_24 -> V_13 -> V_16 . V_23 . V_24 ) {
F_11 ( V_24 -> V_13 -> V_16 . V_23 . V_24 , NULL ) ;
V_344 = true ;
}
V_24 -> V_13 = V_331 ;
if ( V_24 -> V_346 == V_277 &&
V_344 != V_345 ) {
if ( V_345 )
F_136 ( & V_24 -> V_13 -> V_347 -> V_348 ) ;
else
F_137 ( & V_24 -> V_13 -> V_347 -> V_348 ) ;
}
F_99 ( V_24 ) ;
}
V_14 = F_110 ( V_10 , V_24 , V_8 ) ;
if ( V_14 )
goto V_334;
F_18 ( & V_10 -> V_63 ) ;
if ( ( V_13 -> V_27 . type == V_70 ||
V_13 -> V_27 . type == V_21 ) &&
V_24 -> V_349 != V_24 -> V_13 -> V_347 -> V_350 &&
F_31 ( V_24 , V_278 ) &&
F_138 ( V_24 ) != 1 ) {
F_139 ( V_24 -> V_13 ,
L_1 ,
V_24 -> V_24 . V_155 ) ;
F_140 ( V_24 -> V_13 ,
V_24 -> V_13 -> V_347 -> V_350 ,
V_24 -> V_24 . V_155 ,
V_24 -> V_13 -> V_27 . V_227 . V_351 ) ;
}
if ( V_13 -> V_27 . type == V_25 &&
V_8 -> V_283 & F_107 ( V_276 ) ) {
F_141 ( V_10 , - 1 ) ;
F_142 ( V_13 ) ;
}
return 0 ;
V_334:
F_18 ( & V_10 -> V_63 ) ;
return V_14 ;
}
static int F_143 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_352 , const T_3 * V_353 )
{
struct V_12 * V_13 ;
struct V_354 * V_355 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_41 () ;
V_24 = F_29 ( V_13 , V_353 ) ;
if ( ! V_24 ) {
F_45 () ;
return - V_65 ;
}
V_355 = F_144 ( V_13 , V_352 ) ;
if ( F_24 ( V_355 ) ) {
F_45 () ;
return F_27 ( V_355 ) ;
}
F_145 ( V_355 , V_24 ) ;
F_45 () ;
return 0 ;
}
static int F_146 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_352 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( V_352 )
return F_147 ( V_13 , V_352 ) ;
F_148 ( V_13 ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_352 , const T_3 * V_353 )
{
struct V_12 * V_13 ;
struct V_354 * V_355 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_41 () ;
V_24 = F_29 ( V_13 , V_353 ) ;
if ( ! V_24 ) {
F_45 () ;
return - V_65 ;
}
V_355 = F_150 ( V_13 , V_352 ) ;
if ( ! V_355 ) {
F_45 () ;
return - V_65 ;
}
F_145 ( V_355 , V_24 ) ;
F_45 () ;
return 0 ;
}
static void F_151 ( struct V_354 * V_355 , T_3 * V_353 ,
struct V_356 * V_357 )
{
struct V_38 * V_358 = F_42 ( V_355 -> V_353 ) ;
if ( V_358 )
memcpy ( V_353 , V_358 -> V_24 . V_155 , V_156 ) ;
else
F_152 ( V_353 ) ;
memset ( V_357 , 0 , sizeof( * V_357 ) ) ;
V_357 -> V_359 = V_360 ;
V_357 -> V_361 = V_362 |
V_363 |
V_364 |
V_365 |
V_366 |
V_367 |
V_368 ;
V_357 -> V_369 = V_355 -> V_370 . V_371 ;
V_357 -> V_372 = V_355 -> V_372 ;
V_357 -> V_373 = V_355 -> V_373 ;
if ( F_153 ( V_374 , V_355 -> V_375 ) )
V_357 -> V_376 = F_154 ( V_355 -> V_375 - V_374 ) ;
V_357 -> V_377 =
F_154 ( V_355 -> V_377 ) ;
V_357 -> V_378 = V_355 -> V_378 ;
if ( V_355 -> V_6 & V_379 )
V_357 -> V_6 |= V_380 ;
if ( V_355 -> V_6 & V_381 )
V_357 -> V_6 |= V_382 ;
if ( V_355 -> V_6 & V_383 )
V_357 -> V_6 |= V_384 ;
if ( V_355 -> V_6 & V_385 )
V_357 -> V_6 |= V_386 ;
if ( V_355 -> V_6 & V_387 )
V_357 -> V_6 |= V_388 ;
}
static int F_155 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_352 , T_3 * V_353 , struct V_356 * V_357 )
{
struct V_12 * V_13 ;
struct V_354 * V_355 ;
V_13 = F_9 ( V_19 ) ;
F_41 () ;
V_355 = F_150 ( V_13 , V_352 ) ;
if ( ! V_355 ) {
F_45 () ;
return - V_65 ;
}
memcpy ( V_352 , V_355 -> V_352 , V_156 ) ;
F_151 ( V_355 , V_353 , V_357 ) ;
F_45 () ;
return 0 ;
}
static int F_156 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_115 , T_3 * V_352 , T_3 * V_353 ,
struct V_356 * V_357 )
{
struct V_12 * V_13 ;
struct V_354 * V_355 ;
V_13 = F_9 ( V_19 ) ;
F_41 () ;
V_355 = F_157 ( V_13 , V_115 ) ;
if ( ! V_355 ) {
F_45 () ;
return - V_65 ;
}
memcpy ( V_352 , V_355 -> V_352 , V_156 ) ;
F_151 ( V_355 , V_353 , V_357 ) ;
F_45 () ;
return 0 ;
}
static void F_158 ( struct V_354 * V_355 , T_3 * V_389 ,
struct V_356 * V_357 )
{
memset ( V_357 , 0 , sizeof( * V_357 ) ) ;
memcpy ( V_389 , V_355 -> V_389 , V_156 ) ;
V_357 -> V_359 = V_390 ;
}
static int F_159 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_352 , T_3 * V_389 , struct V_356 * V_357 )
{
struct V_12 * V_13 ;
struct V_354 * V_355 ;
V_13 = F_9 ( V_19 ) ;
F_41 () ;
V_355 = F_160 ( V_13 , V_352 ) ;
if ( ! V_355 ) {
F_45 () ;
return - V_65 ;
}
memcpy ( V_352 , V_355 -> V_352 , V_156 ) ;
F_158 ( V_355 , V_389 , V_357 ) ;
F_45 () ;
return 0 ;
}
static int F_161 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_115 , T_3 * V_352 , T_3 * V_389 ,
struct V_356 * V_357 )
{
struct V_12 * V_13 ;
struct V_354 * V_355 ;
V_13 = F_9 ( V_19 ) ;
F_41 () ;
V_355 = F_162 ( V_13 , V_115 ) ;
if ( ! V_355 ) {
F_45 () ;
return - V_65 ;
}
memcpy ( V_352 , V_355 -> V_352 , V_156 ) ;
F_158 ( V_355 , V_389 , V_357 ) ;
F_45 () ;
return 0 ;
}
static int F_163 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_391 * V_61 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
memcpy ( V_61 , & ( V_13 -> V_16 . V_74 . V_314 ) , sizeof( struct V_391 ) ) ;
return 0 ;
}
static inline bool F_164 ( enum V_392 V_393 , T_1 V_28 )
{
return ( V_28 >> ( V_393 - 1 ) ) & 0x1 ;
}
static int F_165 ( struct V_394 * V_395 ,
const struct V_396 * V_397 )
{
T_3 * V_398 ;
const T_3 * V_399 ;
struct V_12 * V_13 = F_166 ( V_395 ,
struct V_12 , V_16 . V_74 ) ;
V_398 = NULL ;
V_399 = V_395 -> V_400 ;
if ( V_397 -> V_401 ) {
V_398 = F_167 ( V_397 -> V_400 , V_397 -> V_401 ,
V_179 ) ;
if ( ! V_398 )
return - V_180 ;
}
V_395 -> V_401 = V_397 -> V_401 ;
V_395 -> V_400 = V_398 ;
F_89 ( V_399 ) ;
V_395 -> V_402 = V_397 -> V_402 ;
memcpy ( V_395 -> V_403 , V_397 -> V_403 , V_395 -> V_402 ) ;
V_395 -> V_404 = V_397 -> V_405 ;
V_395 -> V_406 = V_397 -> V_407 ;
V_395 -> V_408 = V_397 -> V_409 ;
V_395 -> V_335 = V_397 -> V_335 ;
V_395 -> V_410 = V_397 -> V_411 ;
V_395 -> V_75 = V_76 ;
if ( V_397 -> V_412 )
V_395 -> V_75 |= V_413 ;
if ( V_397 -> V_414 )
V_395 -> V_75 |= V_415 ;
memcpy ( V_13 -> V_27 . V_227 . V_416 , V_397 -> V_416 ,
sizeof( V_397 -> V_416 ) ) ;
V_13 -> V_27 . V_227 . V_417 = V_397 -> V_417 ;
V_13 -> V_27 . V_227 . V_228 = V_397 -> V_229 ;
V_13 -> V_27 . V_227 . V_230 = V_397 -> V_230 ;
return 0 ;
}
static int F_168 ( struct V_2 * V_2 ,
struct V_18 * V_19 , T_1 V_28 ,
const struct V_391 * V_418 )
{
struct V_391 * V_61 ;
struct V_12 * V_13 ;
struct V_394 * V_395 ;
V_13 = F_9 ( V_19 ) ;
V_395 = & V_13 -> V_16 . V_74 ;
V_61 = & ( V_13 -> V_16 . V_74 . V_314 ) ;
if ( F_164 ( V_419 , V_28 ) )
V_61 -> V_420 = V_418 -> V_420 ;
if ( F_164 ( V_421 , V_28 ) )
V_61 -> V_422 = V_418 -> V_422 ;
if ( F_164 ( V_423 , V_28 ) )
V_61 -> V_424 = V_418 -> V_424 ;
if ( F_164 ( V_425 , V_28 ) )
V_61 -> V_426 = V_418 -> V_426 ;
if ( F_164 ( V_427 , V_28 ) )
V_61 -> V_428 = V_418 -> V_428 ;
if ( F_164 ( V_429 , V_28 ) )
V_61 -> V_430 = V_418 -> V_430 ;
if ( F_164 ( V_431 , V_28 ) )
V_61 -> V_432 = V_418 -> V_432 ;
if ( F_164 ( V_433 , V_28 ) ) {
if ( V_395 -> V_335 )
return - V_31 ;
V_61 -> V_434 = V_418 -> V_434 ;
}
if ( F_164 ( V_435 , V_28 ) )
V_61 -> V_436 =
V_418 -> V_436 ;
if ( F_164 ( V_437 , V_28 ) )
V_61 -> V_438 =
V_418 -> V_438 ;
if ( F_164 ( V_439 , V_28 ) )
V_61 -> V_440 = V_418 -> V_440 ;
if ( F_164 ( V_441 , V_28 ) )
V_61 -> V_442 = V_418 -> V_442 ;
if ( F_164 ( V_443 , V_28 ) )
V_61 -> V_444 =
V_418 -> V_444 ;
if ( F_164 ( V_445 , V_28 ) )
V_61 -> V_446 =
V_418 -> V_446 ;
if ( F_164 ( V_447 , V_28 ) )
V_61 -> V_448 =
V_418 -> V_448 ;
if ( F_164 ( V_449 ,
V_28 ) )
V_61 -> V_450 =
V_418 -> V_450 ;
if ( F_164 ( V_451 , V_28 ) ) {
V_61 -> V_452 = V_418 -> V_452 ;
F_169 ( V_395 ) ;
}
if ( F_164 ( V_453 , V_28 ) ) {
if ( V_418 -> V_454 &&
! ( V_61 -> V_452 > V_455 ) ) {
V_61 -> V_452 = V_456 ;
F_169 ( V_395 ) ;
}
V_61 -> V_454 =
V_418 -> V_454 ;
}
if ( F_164 ( V_457 , V_28 ) )
V_61 -> V_458 =
V_418 -> V_458 ;
if ( F_164 ( V_459 , V_28 ) )
V_61 -> V_460 = V_418 -> V_460 ;
if ( F_164 ( V_461 , V_28 ) ) {
if ( ! ( V_13 -> V_10 -> V_123 . V_6 & V_462 ) )
return - V_463 ;
V_61 -> V_464 = V_418 -> V_464 ;
}
if ( F_164 ( V_465 , V_28 ) ) {
V_61 -> V_466 = V_418 -> V_466 ;
V_13 -> V_27 . V_227 . V_467 = V_418 -> V_466 ;
F_83 ( V_13 , V_468 ) ;
}
if ( F_164 ( V_469 , V_28 ) )
V_61 -> V_470 =
V_418 -> V_470 ;
if ( F_164 ( V_471 , V_28 ) )
V_61 -> V_472 =
V_418 -> V_472 ;
if ( F_164 ( V_473 , V_28 ) )
V_61 -> V_474 =
V_418 -> V_474 ;
if ( F_164 ( V_475 , V_28 ) ) {
V_61 -> V_315 = V_418 -> V_315 ;
F_170 ( V_13 ) ;
}
if ( F_164 ( V_476 , V_28 ) )
V_61 -> V_477 =
V_418 -> V_477 ;
if ( F_164 ( V_478 , V_28 ) )
V_61 -> V_479 = V_418 -> V_479 ;
F_123 ( V_13 , V_193 ) ;
return 0 ;
}
static int F_171 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const struct V_391 * V_61 ,
const struct V_396 * V_397 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_394 * V_395 = & V_13 -> V_16 . V_74 ;
int V_14 ;
memcpy ( & V_395 -> V_314 , V_61 , sizeof( struct V_391 ) ) ;
V_14 = F_165 ( V_395 , V_397 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_212 = V_214 ;
V_13 -> V_219 = V_13 -> V_10 -> V_220 ;
F_16 ( & V_13 -> V_10 -> V_163 ) ;
V_14 = F_69 ( V_13 , & V_397 -> V_161 ,
V_221 ) ;
F_18 ( & V_13 -> V_10 -> V_163 ) ;
if ( V_14 )
return V_14 ;
return F_172 ( V_13 ) ;
}
static int F_173 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_174 ( V_13 ) ;
F_16 ( & V_13 -> V_10 -> V_163 ) ;
F_68 ( V_13 ) ;
F_18 ( & V_13 -> V_10 -> V_163 ) ;
return 0 ;
}
static int F_175 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_480 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
enum V_281 V_282 ;
T_1 V_192 = 0 ;
if ( ! F_72 ( V_13 -> V_16 . V_178 . V_194 , V_13 ) )
return - V_65 ;
V_282 = F_54 ( V_13 ) ;
if ( V_8 -> V_481 >= 0 ) {
V_13 -> V_27 . V_227 . V_481 = V_8 -> V_481 ;
V_192 |= V_482 ;
}
if ( V_8 -> V_483 >= 0 ) {
V_13 -> V_27 . V_227 . V_483 =
V_8 -> V_483 ;
V_192 |= V_484 ;
}
if ( ! V_13 -> V_27 . V_227 . V_485 &&
V_282 == V_486 ) {
V_13 -> V_27 . V_227 . V_485 = true ;
V_192 |= V_487 ;
}
if ( V_8 -> V_488 >= 0 ) {
V_13 -> V_27 . V_227 . V_485 =
V_8 -> V_488 ;
V_192 |= V_487 ;
}
if ( V_8 -> V_417 ) {
F_113 ( & V_13 -> V_27 . V_227 . V_161 ,
V_2 -> V_124 [ V_282 ] ,
V_8 -> V_417 ,
V_8 -> V_489 ,
& V_13 -> V_27 . V_227 . V_417 ) ;
V_192 |= V_490 ;
}
if ( V_8 -> V_491 >= 0 ) {
if ( V_8 -> V_491 )
V_13 -> V_6 |= V_492 ;
else
V_13 -> V_6 &= ~ V_492 ;
}
if ( V_8 -> V_466 >= 0 ) {
V_13 -> V_27 . V_227 . V_467 =
( T_2 ) V_8 -> V_466 ;
V_192 |= V_468 ;
}
if ( V_8 -> V_238 >= 0 ) {
V_13 -> V_27 . V_227 . V_236 . V_237 &=
~ V_239 ;
V_13 -> V_27 . V_227 . V_236 . V_237 |=
V_8 -> V_238 & V_239 ;
V_192 |= V_209 ;
}
if ( V_8 -> V_240 > 0 ) {
V_13 -> V_27 . V_227 . V_236 . V_237 |=
V_241 ;
V_192 |= V_209 ;
} else if ( V_8 -> V_240 == 0 ) {
V_13 -> V_27 . V_227 . V_236 . V_237 &=
~ V_241 ;
V_192 |= V_209 ;
}
F_83 ( V_13 , V_192 ) ;
return 0 ;
}
static int F_176 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_493 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_494 V_495 ;
if ( ! V_10 -> V_496 -> V_497 )
return - V_343 ;
if ( V_10 -> V_123 . V_286 < V_287 )
return - V_343 ;
memset ( & V_495 , 0 , sizeof( V_495 ) ) ;
V_495 . V_498 = V_8 -> V_498 ;
V_495 . V_499 = V_8 -> V_500 ;
V_495 . V_501 = V_8 -> V_502 ;
V_495 . V_503 = V_8 -> V_503 ;
V_495 . V_504 = false ;
V_13 -> V_505 [ V_8 -> V_506 ] = V_495 ;
if ( F_177 ( V_10 , V_13 , V_8 -> V_506 , & V_495 ) ) {
F_178 ( V_10 -> V_123 . V_2 ,
L_2 ,
V_8 -> V_506 ) ;
return - V_49 ;
}
F_83 ( V_13 , V_507 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_2 ,
struct V_508 * V_509 )
{
return F_180 ( F_2 ( V_2 ) , V_509 ) ;
}
static int F_181 ( struct V_2 * V_2 )
{
return F_182 ( F_2 ( V_2 ) ) ;
}
static int F_183 ( struct V_2 * V_2 ,
struct V_510 * V_511 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_511 -> V_11 ) ;
switch ( F_184 ( & V_13 -> V_27 ) ) {
case V_25 :
case V_72 :
case V_73 :
case V_81 :
case V_78 :
break;
case V_82 :
if ( V_13 -> V_10 -> V_496 -> V_512 )
break;
case V_70 :
if ( V_13 -> V_16 . V_178 . V_194 &&
( ! ( V_2 -> V_513 & V_514 ) ||
! ( V_511 -> V_6 & V_515 ) ) )
return - V_343 ;
break;
default:
return - V_343 ;
}
return F_185 ( V_13 , V_511 ) ;
}
static int
F_186 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_516 * V_511 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_496 -> V_517 )
return - V_343 ;
return F_187 ( V_13 , V_511 ) ;
}
static int
F_188 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_496 -> V_518 )
return - V_343 ;
return F_189 ( V_13 ) ;
}
static int F_190 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_519 * V_511 )
{
return F_191 ( F_9 ( V_19 ) , V_511 ) ;
}
static int F_192 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_520 * V_511 )
{
return F_193 ( F_9 ( V_19 ) , V_511 ) ;
}
static int F_194 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_521 * V_511 )
{
return F_195 ( F_9 ( V_19 ) , V_511 ) ;
}
static int F_196 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_522 * V_511 )
{
return F_197 ( F_9 ( V_19 ) , V_511 ) ;
}
static int F_198 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_523 * V_8 )
{
return F_199 ( F_9 ( V_19 ) , V_8 ) ;
}
static int F_200 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_201 ( F_9 ( V_19 ) ) ;
}
static int F_202 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_524 * V_397 )
{
return F_203 ( F_9 ( V_19 ) , V_397 ) ;
}
static int F_204 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_205 ( F_9 ( V_19 ) ) ;
}
static int F_206 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_109 [ V_525 ] )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( V_13 -> V_27 . V_227 . V_416 , V_109 ,
sizeof( int ) * V_525 ) ;
return 0 ;
}
static int F_207 ( struct V_2 * V_2 , T_1 V_192 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_192 & V_526 ) {
V_14 = F_208 ( V_10 , V_2 -> V_527 ) ;
if ( V_14 )
return V_14 ;
}
if ( ( V_192 & V_528 ) ||
( V_192 & V_529 ) ) {
T_6 V_530 ;
V_530 = V_192 & V_528 ?
V_2 -> V_530 : - 1 ;
V_14 = F_209 ( V_10 , V_530 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_192 & V_531 ) {
V_14 = F_210 ( V_10 , V_2 -> V_532 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_192 & V_533 ) {
if ( V_2 -> V_534 > V_535 )
return - V_49 ;
V_10 -> V_123 . V_61 . V_536 = V_2 -> V_534 ;
}
if ( V_192 & V_537 ) {
if ( V_2 -> V_538 > V_535 )
return - V_49 ;
V_10 -> V_123 . V_61 . V_539 = V_2 -> V_538 ;
}
if ( V_192 &
( V_533 | V_537 ) )
F_70 ( V_10 , V_540 ) ;
return 0 ;
}
static int F_211 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
enum V_541 type , int V_542 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
enum V_541 V_543 = type ;
bool V_544 = false ;
if ( V_11 ) {
V_13 = F_5 ( V_11 ) ;
switch ( type ) {
case V_545 :
V_13 -> V_546 = V_547 ;
V_543 = V_548 ;
break;
case V_548 :
case V_549 :
if ( V_542 < 0 || ( V_542 % 100 ) )
return - V_343 ;
V_13 -> V_546 = F_212 ( V_542 ) ;
break;
}
if ( V_543 != V_13 -> V_27 . V_227 . V_550 ) {
V_544 = true ;
V_13 -> V_27 . V_227 . V_550 = V_543 ;
}
F_213 ( V_13 , V_544 ) ;
return 0 ;
}
switch ( type ) {
case V_545 :
V_10 -> V_546 = V_547 ;
V_543 = V_548 ;
break;
case V_548 :
case V_549 :
if ( V_542 < 0 || ( V_542 % 100 ) )
return - V_343 ;
V_10 -> V_546 = F_212 ( V_542 ) ;
break;
}
F_16 ( & V_10 -> V_164 ) ;
F_80 (sdata, &local->interfaces, list) {
V_13 -> V_546 = V_10 -> V_546 ;
if ( V_543 != V_13 -> V_27 . V_227 . V_550 )
V_544 = true ;
V_13 -> V_27 . V_227 . V_550 = V_543 ;
}
F_80 (sdata, &local->interfaces, list)
F_213 ( V_13 , V_544 ) ;
F_18 ( & V_10 -> V_164 ) ;
return 0 ;
}
static int F_214 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
int * V_551 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_10 -> V_496 -> V_552 )
return F_215 ( V_10 , V_13 , V_551 ) ;
if ( ! V_10 -> V_165 )
* V_551 = V_10 -> V_123 . V_61 . V_553 ;
else
* V_551 = V_13 -> V_27 . V_227 . V_554 ;
return 0 ;
}
static int F_216 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_155 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( & V_13 -> V_16 . V_555 . V_556 , V_155 , V_156 ) ;
return 0 ;
}
static void F_217 ( struct V_2 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_218 ( V_10 ) ;
}
static int F_219 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
void * V_182 , int V_181 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_557 * V_27 = NULL ;
if ( ! V_10 -> V_496 -> V_558 )
return - V_343 ;
if ( V_11 ) {
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 -> V_6 & V_559 )
V_27 = & V_13 -> V_27 ;
}
return V_10 -> V_496 -> V_558 ( & V_10 -> V_123 , V_27 , V_182 , V_181 ) ;
}
static int F_220 ( struct V_2 * V_2 ,
struct V_259 * V_260 ,
struct V_560 * V_268 ,
void * V_182 , int V_181 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_496 -> V_561 )
return - V_343 ;
return V_10 -> V_496 -> V_561 ( & V_10 -> V_123 , V_260 , V_268 , V_182 , V_181 ) ;
}
int F_221 ( struct V_12 * V_13 ,
enum V_562 V_212 )
{
struct V_38 * V_24 ;
enum V_562 V_563 ;
if ( F_34 ( V_13 -> V_27 . type != V_70 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_227 . V_161 . V_564 == V_565 )
return 0 ;
V_563 = V_13 -> V_16 . V_178 . V_350 ;
V_13 -> V_16 . V_178 . V_350 = V_212 ;
if ( V_563 == V_212 ||
V_212 == V_566 )
return 0 ;
if ( ! F_222 ( & V_13 -> V_16 . V_178 . V_348 ) ) {
V_13 -> V_212 = V_212 ;
F_223 ( & V_13 -> V_10 -> V_123 , & V_13 -> V_567 ) ;
return 0 ;
}
F_139 ( V_13 ,
L_3 ,
V_212 , F_222 ( & V_13 -> V_16 . V_178 . V_348 ) ) ;
F_16 ( & V_13 -> V_10 -> V_63 ) ;
F_80 (sta, &sdata->local->sta_list, list) {
if ( V_24 -> V_13 -> V_347 != & V_13 -> V_16 . V_178 )
continue;
if ( F_138 ( V_24 ) == 1 )
continue;
if ( F_31 ( V_24 , V_568 ) &&
! F_224 ( V_24 -> V_349 ,
V_212 ) ) {
F_139 ( V_13 , L_4 ,
V_24 -> V_24 . V_155 ) ;
continue;
}
if ( ! F_31 ( V_24 , V_278 ) )
continue;
F_139 ( V_13 , L_5 , V_24 -> V_24 . V_155 ) ;
F_140 ( V_13 , V_212 , V_24 -> V_24 . V_155 ,
V_13 -> V_27 . V_227 . V_351 ) ;
}
F_18 ( & V_13 -> V_10 -> V_63 ) ;
V_13 -> V_212 = V_212 ;
F_223 ( & V_13 -> V_10 -> V_123 , & V_13 -> V_567 ) ;
return 0 ;
}
int F_225 ( struct V_12 * V_13 ,
enum V_562 V_212 )
{
const T_3 * V_178 ;
enum V_562 V_563 ;
int V_14 ;
F_226 ( & V_13 -> V_11 . V_163 ) ;
if ( F_34 ( V_13 -> V_27 . type != V_25 ) )
return - V_49 ;
V_563 = V_13 -> V_16 . V_26 . V_350 ;
V_13 -> V_16 . V_26 . V_350 = V_212 ;
if ( V_563 == V_212 &&
V_212 != V_566 )
return 0 ;
if ( ! V_13 -> V_16 . V_26 . V_569 ||
V_13 -> V_27 . V_227 . V_161 . V_564 == V_565 )
return 0 ;
V_178 = V_13 -> V_16 . V_26 . V_569 -> V_351 ;
if ( V_212 == V_566 ) {
if ( V_13 -> V_16 . V_26 . V_570 )
V_212 = V_218 ;
else
V_212 = V_214 ;
}
V_14 = F_140 ( V_13 , V_212 ,
V_178 , V_178 ) ;
if ( V_14 )
V_13 -> V_16 . V_26 . V_350 = V_563 ;
return V_14 ;
}
static int F_227 ( struct V_2 * V_2 , struct V_18 * V_19 ,
bool V_571 , int V_572 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_61 ( V_19 -> V_159 ) ;
if ( V_13 -> V_27 . type != V_25 )
return - V_343 ;
if ( ! ( V_10 -> V_123 . V_6 & V_573 ) )
return - V_343 ;
if ( V_571 == V_13 -> V_16 . V_26 . V_570 &&
V_572 == V_10 -> V_574 )
return 0 ;
V_13 -> V_16 . V_26 . V_570 = V_571 ;
V_10 -> V_574 = V_572 ;
F_228 ( V_13 ) ;
F_225 ( V_13 , V_13 -> V_16 . V_26 . V_350 ) ;
F_229 ( V_13 ) ;
if ( V_10 -> V_123 . V_6 & V_575 )
F_70 ( V_10 , V_576 ) ;
F_141 ( V_10 , - 1 ) ;
F_142 ( V_13 ) ;
return 0 ;
}
static int F_230 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_7 V_577 , T_1 V_578 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_557 * V_27 = & V_13 -> V_27 ;
struct V_579 * V_227 = & V_27 -> V_227 ;
if ( V_577 == V_227 -> V_580 &&
V_578 == V_227 -> V_581 )
return 0 ;
V_227 -> V_580 = V_577 ;
V_227 -> V_581 = V_578 ;
if ( V_13 -> V_16 . V_26 . V_569 &&
V_13 -> V_27 . V_582 & V_583 )
F_83 ( V_13 , V_584 ) ;
return 0 ;
}
static int F_231 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
const T_3 * V_155 ,
const struct V_585 * V_28 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_61 ( V_19 -> V_159 ) ;
int V_586 , V_20 ;
if ( ! F_12 ( V_13 ) )
return - V_43 ;
if ( V_10 -> V_123 . V_6 & V_587 ) {
V_20 = F_232 ( V_10 , V_13 , V_28 ) ;
if ( V_20 )
return V_20 ;
}
for ( V_586 = 0 ; V_586 < V_525 ; V_586 ++ ) {
struct V_119 * V_120 = V_2 -> V_124 [ V_586 ] ;
int V_588 ;
V_13 -> V_589 [ V_586 ] = V_28 -> V_265 [ V_586 ] . V_127 ;
memcpy ( V_13 -> V_590 [ V_586 ] , V_28 -> V_265 [ V_586 ] . V_591 ,
sizeof( V_28 -> V_265 [ V_586 ] . V_591 ) ) ;
V_13 -> V_592 [ V_586 ] = false ;
if ( ! V_120 )
continue;
for ( V_588 = 0 ; V_588 < V_593 ; V_588 ++ )
if ( ~ V_13 -> V_590 [ V_586 ] [ V_588 ] ) {
V_13 -> V_592 [ V_586 ] = true ;
break;
}
}
return 0 ;
}
static bool F_233 ( struct V_9 * V_10 ,
struct V_594 * V_595 ,
struct V_594 * V_596 )
{
unsigned long V_597 = V_374 ;
unsigned long V_598 = V_596 -> V_599 +
F_234 ( V_596 -> V_600 ) -
V_597 ;
if ( F_235 ( ! V_596 -> V_601 || ! V_596 -> V_602 ) )
return false ;
if ( V_595 -> V_600 > F_154 ( V_598 ) )
return false ;
F_236 ( V_595 ) ;
F_237 ( & V_595 -> V_603 , & V_596 -> V_604 ) ;
return true ;
}
static int F_238 ( struct V_9 * V_10 ,
struct V_12 * V_13 ,
struct V_605 * V_606 ,
unsigned int V_600 , T_4 * V_89 ,
struct V_259 * V_607 ,
enum V_608 type )
{
struct V_594 * V_609 , * V_610 ;
bool V_611 = false ;
int V_20 ;
F_226 ( & V_10 -> V_163 ) ;
if ( V_10 -> V_165 && ! V_10 -> V_496 -> V_612 )
return - V_343 ;
V_609 = F_73 ( sizeof( * V_609 ) , V_179 ) ;
if ( ! V_609 )
return - V_180 ;
if ( ! V_600 )
V_600 = 10 ;
V_609 -> V_613 = V_606 ;
V_609 -> V_600 = V_600 ;
V_609 -> V_614 = V_600 ;
V_609 -> V_615 = V_607 ;
V_609 -> type = type ;
V_609 -> V_616 = ( unsigned long ) V_607 ;
V_609 -> V_13 = V_13 ;
F_239 ( & V_609 -> V_617 , V_618 ) ;
F_240 ( & V_609 -> V_604 ) ;
if ( ! V_607 ) {
V_10 -> V_619 ++ ;
V_609 -> V_89 = V_10 -> V_619 ;
if ( F_235 ( V_609 -> V_89 == 0 ) ) {
V_609 -> V_89 = 1 ;
V_10 -> V_619 ++ ;
}
* V_89 = V_609 -> V_89 ;
} else {
* V_89 = ( unsigned long ) V_607 ;
}
if ( ! F_241 ( & V_10 -> V_620 ) ||
V_10 -> V_621 || F_242 ( V_10 ) )
goto V_622;
if ( ! V_10 -> V_496 -> V_612 ) {
F_243 ( & V_10 -> V_123 , & V_609 -> V_617 , 0 ) ;
goto V_623;
}
V_20 = F_244 ( V_10 , V_13 , V_606 , V_600 , type ) ;
if ( V_20 ) {
F_89 ( V_609 ) ;
return V_20 ;
}
V_609 -> V_601 = true ;
goto V_623;
V_622:
F_80 (tmp, &local->roc_list, list) {
if ( V_610 -> V_613 != V_606 || V_610 -> V_13 != V_13 )
continue;
if ( ! V_610 -> V_601 ) {
F_237 ( & V_609 -> V_603 , & V_610 -> V_604 ) ;
V_610 -> V_600 = F_245 ( V_610 -> V_600 , V_609 -> V_600 ) ;
V_610 -> type = F_245 ( V_610 -> type , V_609 -> type ) ;
V_611 = true ;
break;
}
if ( V_10 -> V_496 -> V_612 ) {
if ( ! V_610 -> V_602 ) {
F_237 ( & V_609 -> V_603 , & V_610 -> V_604 ) ;
V_611 = true ;
break;
}
if ( F_233 ( V_10 , V_609 , V_610 ) )
V_611 = true ;
} else if ( F_246 ( & V_610 -> V_617 . V_624 ) ) {
unsigned long V_625 ;
F_237 ( & V_609 -> V_603 , & V_610 -> V_604 ) ;
V_611 = true ;
V_625 = V_374 + F_234 ( V_609 -> V_600 ) ;
if ( F_247 ( V_625 , V_610 -> V_617 . V_624 . V_626 ) )
F_248 ( & V_610 -> V_617 . V_624 , V_625 ) ;
else
F_249 ( & V_610 -> V_617 . V_624 ) ;
F_236 ( V_609 ) ;
}
break;
}
V_623:
if ( ! V_611 )
F_237 ( & V_609 -> V_603 , & V_10 -> V_620 ) ;
return 0 ;
}
static int F_250 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_605 * V_613 ,
unsigned int V_600 ,
T_4 * V_89 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_20 ;
F_16 ( & V_10 -> V_163 ) ;
V_20 = F_238 ( V_10 , V_13 , V_613 ,
V_600 , V_89 , NULL ,
V_627 ) ;
F_18 ( & V_10 -> V_163 ) ;
return V_20 ;
}
static int F_251 ( struct V_9 * V_10 ,
T_4 V_89 , bool V_628 )
{
struct V_594 * V_609 , * V_610 , * V_629 = NULL ;
int V_20 ;
F_16 ( & V_10 -> V_163 ) ;
F_252 (roc, tmp, &local->roc_list, list) {
struct V_594 * V_630 , * V_631 ;
F_252 (dep, tmp2, &roc->dependents, list) {
if ( ! V_628 && V_630 -> V_89 != V_89 )
continue;
else if ( V_628 && V_630 -> V_616 != V_89 )
continue;
F_253 ( & V_630 -> V_603 ) ;
F_18 ( & V_10 -> V_163 ) ;
F_254 ( V_630 , true ) ;
return 0 ;
}
if ( ! V_628 && V_609 -> V_89 != V_89 )
continue;
else if ( V_628 && V_609 -> V_616 != V_89 )
continue;
V_629 = V_609 ;
break;
}
if ( ! V_629 ) {
F_18 ( & V_10 -> V_163 ) ;
return - V_65 ;
}
if ( V_10 -> V_496 -> V_612 ) {
if ( V_629 -> V_601 ) {
V_20 = F_255 ( V_10 ) ;
if ( F_34 ( V_20 ) ) {
F_18 ( & V_10 -> V_163 ) ;
return V_20 ;
}
}
F_253 ( & V_629 -> V_603 ) ;
if ( V_629 -> V_601 )
F_256 ( V_10 ) ;
F_18 ( & V_10 -> V_163 ) ;
F_254 ( V_629 , true ) ;
} else {
V_629 -> abort = true ;
F_243 ( & V_10 -> V_123 , & V_629 -> V_617 , 0 ) ;
F_18 ( & V_10 -> V_163 ) ;
F_257 ( & V_629 -> V_617 ) ;
F_235 ( ! V_629 -> V_632 ) ;
F_89 ( V_629 ) ;
}
return 0 ;
}
static int F_258 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_4 V_89 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
return F_251 ( V_10 , V_89 , false ) ;
}
static int F_259 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_160 * V_161 ,
T_1 V_633 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_16 ( & V_10 -> V_163 ) ;
if ( ! F_241 ( & V_10 -> V_620 ) || V_10 -> V_621 ) {
V_14 = - V_31 ;
goto V_66;
}
V_13 -> V_212 = V_214 ;
V_13 -> V_219 = V_10 -> V_220 ;
V_14 = F_69 ( V_13 , V_161 ,
V_221 ) ;
if ( V_14 )
goto V_66;
F_243 ( & V_13 -> V_10 -> V_123 ,
& V_13 -> V_252 ,
F_234 ( V_633 ) ) ;
V_66:
F_18 ( & V_10 -> V_163 ) ;
return V_14 ;
}
static struct V_187 *
F_260 ( struct V_187 * V_194 )
{
struct V_187 * V_634 ;
T_3 * V_635 ;
int V_181 ;
V_181 = V_194 -> V_196 + V_194 -> V_198 + V_194 -> V_636 +
V_194 -> V_637 + V_194 -> V_638 +
V_194 -> V_203 ;
V_634 = F_73 ( sizeof( * V_634 ) + V_181 , V_179 ) ;
if ( ! V_634 )
return NULL ;
V_635 = ( T_3 * ) ( V_634 + 1 ) ;
if ( V_194 -> V_196 ) {
V_634 -> V_196 = V_194 -> V_196 ;
V_634 -> V_195 = V_635 ;
memcpy ( V_635 , V_194 -> V_195 , V_194 -> V_196 ) ;
V_635 += V_194 -> V_196 ;
}
if ( V_194 -> V_198 ) {
V_634 -> V_198 = V_194 -> V_198 ;
V_634 -> V_197 = V_635 ;
memcpy ( V_635 , V_194 -> V_197 , V_194 -> V_198 ) ;
V_635 += V_194 -> V_198 ;
}
if ( V_194 -> V_636 ) {
V_634 -> V_636 = V_194 -> V_636 ;
V_634 -> V_639 = V_635 ;
memcpy ( V_635 , V_194 -> V_639 , V_194 -> V_636 ) ;
V_635 += V_194 -> V_636 ;
}
if ( V_194 -> V_637 ) {
V_634 -> V_637 = V_194 -> V_637 ;
V_634 -> V_640 = V_635 ;
memcpy ( V_635 , V_194 -> V_640 , V_194 -> V_637 ) ;
V_635 += V_194 -> V_637 ;
}
if ( V_194 -> V_638 ) {
V_634 -> V_638 = V_194 -> V_638 ;
V_634 -> V_641 = V_635 ;
memcpy ( V_635 , V_194 -> V_641 , V_194 -> V_638 ) ;
V_635 += V_194 -> V_638 ;
}
if ( V_194 -> V_203 ) {
V_634 -> V_203 = V_194 -> V_203 ;
V_194 -> V_175 = V_635 ;
memcpy ( V_635 , V_194 -> V_175 , V_194 -> V_203 ) ;
V_635 += V_194 -> V_203 ;
}
return V_634 ;
}
void F_261 ( struct V_557 * V_27 )
{
struct V_12 * V_13 = F_262 ( V_27 ) ;
F_223 ( & V_13 -> V_10 -> V_123 ,
& V_13 -> V_642 ) ;
}
static int F_263 ( struct V_12 * V_13 ,
T_1 * V_192 )
{
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_14 = F_76 ( V_13 , V_13 -> V_16 . V_178 . V_247 ,
NULL ) ;
F_89 ( V_13 -> V_16 . V_178 . V_247 ) ;
V_13 -> V_16 . V_178 . V_247 = NULL ;
if ( V_14 < 0 )
return V_14 ;
* V_192 |= V_14 ;
break;
case V_72 :
V_14 = F_264 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_192 |= V_14 ;
break;
#ifdef F_33
case V_73 :
V_14 = F_265 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_192 |= V_14 ;
break;
#endif
default:
F_235 ( 1 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_266 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_10 ;
T_1 V_192 = 0 ;
int V_14 ;
F_86 ( V_13 ) ;
F_226 ( & V_10 -> V_163 ) ;
F_226 ( & V_10 -> V_32 ) ;
if ( V_13 -> V_643 ) {
if ( V_13 -> V_644 )
return 0 ;
return F_267 ( V_13 ) ;
}
if ( ! F_65 ( & V_13 -> V_27 . V_227 . V_161 ,
& V_13 -> V_645 ) )
return - V_49 ;
V_13 -> V_27 . V_242 = false ;
V_14 = F_263 ( V_13 , & V_192 ) ;
if ( V_14 )
return V_14 ;
F_83 ( V_13 , V_192 ) ;
if ( V_13 -> V_245 ) {
F_88 ( V_10 , V_13 ,
V_246 ) ;
V_13 -> V_245 = false ;
}
V_14 = F_268 ( V_13 ) ;
if ( V_14 )
return V_14 ;
F_269 ( V_13 -> V_19 , & V_13 -> V_645 ) ;
return 0 ;
}
static void F_270 ( struct V_12 * V_13 )
{
if ( F_266 ( V_13 ) ) {
F_271 ( V_13 , L_6 ) ;
F_272 ( V_13 -> V_10 -> V_123 . V_2 , & V_13 -> V_11 ,
V_179 ) ;
}
}
void F_273 ( struct V_646 * V_617 )
{
struct V_12 * V_13 =
F_166 ( V_617 , struct V_12 ,
V_642 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
F_228 ( V_13 ) ;
F_16 ( & V_10 -> V_163 ) ;
F_16 ( & V_10 -> V_32 ) ;
if ( ! V_13 -> V_27 . V_242 )
goto V_647;
if ( ! F_12 ( V_13 ) )
goto V_647;
F_270 ( V_13 ) ;
V_647:
F_18 ( & V_10 -> V_32 ) ;
F_18 ( & V_10 -> V_163 ) ;
F_229 ( V_13 ) ;
}
static int F_274 ( struct V_12 * V_13 ,
struct V_648 * V_8 ,
T_1 * V_192 )
{
struct V_173 V_174 = {} ;
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_13 -> V_16 . V_178 . V_247 =
F_260 ( & V_8 -> V_649 ) ;
if ( ! V_13 -> V_16 . V_178 . V_247 )
return - V_180 ;
if ( V_8 -> V_200 <= 1 )
break;
if ( ( V_8 -> V_202 >
V_650 ) ||
( V_8 -> V_185 >
V_650 ) )
return - V_49 ;
V_174 . V_201 = V_8 -> V_201 ;
V_174 . V_184 = V_8 -> V_184 ;
V_174 . V_202 = V_8 -> V_202 ;
V_174 . V_185 = V_8 -> V_185 ;
V_174 . V_200 = V_8 -> V_200 ;
V_14 = F_76 ( V_13 , & V_8 -> V_651 , & V_174 ) ;
if ( V_14 < 0 ) {
F_89 ( V_13 -> V_16 . V_178 . V_247 ) ;
return V_14 ;
}
* V_192 |= V_14 ;
break;
case V_72 :
if ( ! V_13 -> V_27 . V_227 . V_652 )
return - V_49 ;
if ( V_8 -> V_161 . V_564 != V_13 -> V_16 . V_653 . V_161 . V_564 )
return - V_49 ;
switch ( V_8 -> V_161 . V_564 ) {
case V_654 :
if ( F_275 ( & V_8 -> V_161 ) !=
F_275 ( & V_13 -> V_16 . V_653 . V_161 ) )
return - V_49 ;
case V_655 :
case V_656 :
case V_565 :
case V_657 :
break;
default:
return - V_49 ;
}
if ( V_13 -> V_16 . V_653 . V_161 . V_613 -> V_282 !=
V_8 -> V_161 . V_613 -> V_282 )
return - V_49 ;
if ( V_8 -> V_200 > 1 ) {
V_14 = F_276 ( V_13 , V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_192 |= V_14 ;
}
F_277 ( V_13 , V_8 ) ;
break;
#ifdef F_33
case V_73 : {
struct V_394 * V_395 = & V_13 -> V_16 . V_74 ;
if ( V_8 -> V_161 . V_564 != V_13 -> V_27 . V_227 . V_161 . V_564 )
return - V_49 ;
if ( V_13 -> V_27 . V_227 . V_161 . V_613 -> V_282 !=
V_8 -> V_161 . V_613 -> V_282 )
return - V_49 ;
if ( V_395 -> V_658 == V_659 ) {
V_395 -> V_658 = V_660 ;
if ( ! V_395 -> V_661 )
V_395 -> V_661 = 1 ;
else
V_395 -> V_661 ++ ;
}
if ( V_8 -> V_200 > 1 ) {
V_14 = F_278 ( V_13 , V_8 ) ;
if ( V_14 < 0 ) {
V_395 -> V_658 = V_659 ;
return V_14 ;
}
* V_192 |= V_14 ;
}
if ( V_395 -> V_658 == V_660 )
F_277 ( V_13 , V_8 ) ;
break;
}
#endif
default:
return - V_343 ;
}
return 0 ;
}
static int
F_279 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_648 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_662 V_663 ;
struct V_664 * V_61 ;
struct V_665 * V_666 ;
T_1 V_192 = 0 ;
int V_14 ;
F_86 ( V_13 ) ;
F_226 ( & V_10 -> V_163 ) ;
if ( ! F_241 ( & V_10 -> V_620 ) || V_10 -> V_621 )
return - V_31 ;
if ( V_13 -> V_11 . V_251 )
return - V_31 ;
if ( F_65 ( & V_8 -> V_161 ,
& V_13 -> V_27 . V_227 . V_161 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_242 )
return - V_31 ;
F_16 ( & V_10 -> V_32 ) ;
V_61 = F_66 ( V_13 -> V_27 . V_667 ,
F_67 ( & V_10 -> V_32 ) ) ;
if ( ! V_61 ) {
V_14 = - V_31 ;
goto V_93;
}
V_666 = F_166 ( V_61 , struct V_665 , V_61 ) ;
if ( ! V_666 ) {
V_14 = - V_31 ;
goto V_93;
}
V_663 . V_668 = 0 ;
V_663 . V_669 = 0 ;
V_663 . V_670 = V_8 -> V_670 ;
V_663 . V_161 = V_8 -> V_161 ;
V_663 . V_200 = V_8 -> V_200 ;
V_14 = F_280 ( V_13 , & V_663 ) ;
if ( V_14 )
goto V_93;
V_14 = F_281 ( V_13 , & V_8 -> V_161 ,
V_666 -> V_671 ,
V_8 -> V_672 ) ;
if ( V_14 )
goto V_93;
V_14 = F_17 ( V_13 , NULL , V_666 -> V_671 , 0 ) ;
if ( V_14 ) {
F_282 ( V_13 ) ;
goto V_93;
}
V_14 = F_274 ( V_13 , V_8 , & V_192 ) ;
if ( V_14 ) {
F_282 ( V_13 ) ;
goto V_93;
}
V_13 -> V_645 = V_8 -> V_161 ;
V_13 -> V_245 = V_8 -> V_670 ;
V_13 -> V_27 . V_242 = true ;
if ( V_13 -> V_245 )
F_283 ( V_10 , V_13 ,
V_246 ) ;
F_284 ( V_13 -> V_19 , & V_13 -> V_645 ,
V_8 -> V_200 ) ;
if ( V_192 ) {
F_83 ( V_13 , V_192 ) ;
F_285 ( V_13 , & V_8 -> V_161 ) ;
} else {
F_270 ( V_13 ) ;
}
V_93:
F_18 ( & V_10 -> V_32 ) ;
return V_14 ;
}
int V_662 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_648 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_16 ( & V_10 -> V_163 ) ;
V_14 = F_279 ( V_2 , V_19 , V_8 ) ;
F_18 ( & V_10 -> V_163 ) ;
return V_14 ;
}
static int F_286 ( struct V_2 * V_2 , struct V_1 * V_11 ,
struct V_673 * V_8 ,
T_4 * V_89 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_259 * V_260 ;
struct V_38 * V_24 ;
const struct V_674 * V_675 = ( void * ) V_8 -> V_676 ;
bool V_677 = false ;
T_1 V_6 ;
int V_20 ;
T_3 * V_182 ;
if ( V_8 -> V_678 )
V_6 = V_679 ;
else
V_6 = V_680 |
V_681 ;
if ( V_8 -> V_682 )
V_6 |= V_683 ;
switch ( V_13 -> V_27 . type ) {
case V_72 :
if ( ! V_13 -> V_27 . V_227 . V_652 )
V_677 = true ;
#ifdef F_33
case V_73 :
if ( F_28 ( & V_13 -> V_27 ) &&
! V_13 -> V_16 . V_74 . V_402 )
V_677 = true ;
#endif
case V_70 :
case V_21 :
case V_82 :
if ( V_13 -> V_27 . type != V_72 &&
! F_28 ( & V_13 -> V_27 ) &&
! F_287 ( V_13 -> V_347 -> V_194 ) )
V_677 = true ;
if ( ! F_288 ( V_675 -> V_684 ) ||
V_675 -> V_16 . V_685 . V_686 == V_687 ||
V_675 -> V_16 . V_685 . V_686 == V_688 ||
V_675 -> V_16 . V_685 . V_686 == V_689 )
break;
F_41 () ;
V_24 = F_29 ( V_13 , V_675 -> V_261 ) ;
F_45 () ;
if ( ! V_24 )
return - V_690 ;
break;
case V_25 :
case V_81 :
if ( ! V_13 -> V_16 . V_26 . V_569 )
V_677 = true ;
break;
case V_78 :
V_677 = true ;
break;
default:
return - V_343 ;
}
if ( V_677 && ! V_8 -> V_613 )
return - V_49 ;
F_16 ( & V_10 -> V_163 ) ;
if ( ! V_677 ) {
struct V_664 * V_667 ;
F_41 () ;
V_667 = F_42 ( V_13 -> V_27 . V_667 ) ;
if ( V_667 ) {
V_677 = V_8 -> V_613 &&
( V_8 -> V_613 !=
V_667 -> V_691 . V_613 ) ;
} else if ( ! V_8 -> V_613 ) {
V_20 = - V_49 ;
F_45 () ;
goto V_66;
} else {
V_677 = true ;
}
F_45 () ;
}
if ( V_677 && ! V_8 -> V_692 ) {
V_20 = - V_31 ;
goto V_66;
}
V_260 = F_100 ( V_10 -> V_123 . V_693 + V_8 -> V_181 ) ;
if ( ! V_260 ) {
V_20 = - V_180 ;
goto V_66;
}
F_289 ( V_260 , V_10 -> V_123 . V_693 ) ;
V_182 = F_101 ( V_260 , V_8 -> V_181 ) ;
memcpy ( V_182 , V_8 -> V_676 , V_8 -> V_181 ) ;
if ( V_13 -> V_27 . V_242 &&
( V_13 -> V_27 . type == V_70 ||
V_13 -> V_27 . type == V_72 ) &&
V_8 -> V_694 ) {
int V_586 ;
struct V_188 * V_194 = NULL ;
F_41 () ;
if ( V_13 -> V_27 . type == V_70 )
V_194 = F_42 ( V_13 -> V_16 . V_178 . V_194 ) ;
else if ( V_13 -> V_27 . type == V_72 )
V_194 = F_42 ( V_13 -> V_16 . V_653 . V_695 ) ;
else if ( F_28 ( & V_13 -> V_27 ) )
V_194 = F_42 ( V_13 -> V_16 . V_74 . V_194 ) ;
if ( V_194 )
for ( V_586 = 0 ; V_586 < V_8 -> V_694 ; V_586 ++ )
V_182 [ V_8 -> V_696 [ V_586 ] ] =
V_194 -> V_199 ;
F_45 () ;
}
F_290 ( V_260 ) -> V_6 = V_6 ;
V_260 -> V_19 = V_13 -> V_19 ;
if ( ! V_677 ) {
* V_89 = ( unsigned long ) V_260 ;
F_291 ( V_13 , V_260 ) ;
V_20 = 0 ;
goto V_66;
}
F_290 ( V_260 ) -> V_6 |= V_697 |
V_698 ;
if ( V_10 -> V_123 . V_6 & V_699 )
F_290 ( V_260 ) -> V_700 =
V_10 -> V_123 . V_701 ;
V_20 = F_238 ( V_10 , V_13 , V_8 -> V_613 ,
V_8 -> V_702 , V_89 , V_260 ,
V_703 ) ;
if ( V_20 )
F_292 ( V_260 ) ;
V_66:
F_18 ( & V_10 -> V_163 ) ;
return V_20 ;
}
static int F_293 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_4 V_89 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_251 ( V_10 , V_89 , true ) ;
}
static void F_294 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_2 V_704 , bool V_705 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
switch ( V_704 ) {
case V_706 | V_707 :
if ( V_705 )
V_10 -> V_708 ++ ;
else
V_10 -> V_708 -- ;
if ( ! V_10 -> V_168 )
break;
F_223 ( & V_10 -> V_123 , & V_10 -> V_709 ) ;
break;
default:
break;
}
}
static int F_295 ( struct V_2 * V_2 , T_1 V_710 , T_1 V_711 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_601 )
return - V_343 ;
return F_296 ( V_10 , V_710 , V_711 ) ;
}
static int F_297 ( struct V_2 * V_2 , T_1 * V_710 , T_1 * V_711 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_298 ( V_10 , V_710 , V_711 ) ;
}
static int F_299 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_712 * V_182 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_10 -> V_496 -> V_713 )
return - V_343 ;
F_300 ( V_10 , V_13 , V_182 ) ;
return 0 ;
}
static int F_301 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_714 , T_4 * V_89 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_715 * V_716 ;
struct V_259 * V_260 ;
int V_191 = sizeof( * V_716 ) ;
T_8 V_717 ;
bool V_718 ;
struct V_719 * V_720 ;
struct V_38 * V_24 ;
struct V_664 * V_667 ;
enum V_281 V_282 ;
F_41 () ;
V_667 = F_42 ( V_13 -> V_27 . V_667 ) ;
if ( F_235 ( ! V_667 ) ) {
F_45 () ;
return - V_49 ;
}
V_282 = V_667 -> V_691 . V_613 -> V_282 ;
V_24 = F_30 ( V_13 , V_714 ) ;
if ( V_24 ) {
V_718 = V_24 -> V_24 . V_288 ;
} else {
F_45 () ;
return - V_690 ;
}
if ( V_718 ) {
V_717 = F_302 ( V_721 |
V_722 |
V_723 ) ;
} else {
V_191 -= 2 ;
V_717 = F_302 ( V_721 |
V_724 |
V_723 ) ;
}
V_260 = F_100 ( V_10 -> V_123 . V_693 + V_191 ) ;
if ( ! V_260 ) {
F_45 () ;
return - V_180 ;
}
V_260 -> V_19 = V_19 ;
F_289 ( V_260 , V_10 -> V_123 . V_693 ) ;
V_716 = ( void * ) F_101 ( V_260 , V_191 ) ;
V_716 -> V_684 = V_717 ;
V_716 -> V_725 = 0 ;
memcpy ( V_716 -> V_726 , V_24 -> V_24 . V_155 , V_156 ) ;
memcpy ( V_716 -> V_727 , V_13 -> V_27 . V_155 , V_156 ) ;
memcpy ( V_716 -> V_728 , V_13 -> V_27 . V_155 , V_156 ) ;
V_716 -> V_729 = 0 ;
V_720 = F_290 ( V_260 ) ;
V_720 -> V_6 |= V_681 |
V_680 ;
V_720 -> V_282 = V_282 ;
F_303 ( V_260 , V_730 ) ;
V_260 -> V_731 = 7 ;
if ( V_718 )
V_716 -> V_732 = F_302 ( 7 ) ;
F_304 () ;
F_305 ( V_13 , V_24 , V_260 ) ;
F_306 () ;
F_45 () ;
* V_89 = ( unsigned long ) V_260 ;
return 0 ;
}
static int F_307 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_160 * V_161 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_664 * V_667 ;
int V_20 = - V_733 ;
F_41 () ;
V_667 = F_42 ( V_13 -> V_27 . V_667 ) ;
if ( V_667 ) {
* V_161 = V_13 -> V_27 . V_227 . V_161 ;
V_20 = 0 ;
} else if ( V_10 -> V_168 > 0 &&
V_10 -> V_168 == V_10 -> V_169 &&
V_13 -> V_27 . type == V_15 ) {
if ( V_10 -> V_165 )
* V_161 = V_10 -> V_162 ;
else
* V_161 = V_10 -> V_170 ;
V_20 = 0 ;
}
F_45 () ;
return V_20 ;
}
static void F_308 ( struct V_2 * V_2 , bool V_571 )
{
F_309 ( F_2 ( V_2 ) , V_571 ) ;
}
static int F_310 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_734 * V_735 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_736 * V_737 , * V_738 ;
if ( V_735 ) {
V_737 = F_73 ( sizeof( * V_737 ) , V_179 ) ;
if ( ! V_737 )
return - V_180 ;
memcpy ( & V_737 -> V_735 , V_735 , sizeof( * V_735 ) ) ;
} else {
V_737 = NULL ;
}
V_738 = F_72 ( V_13 -> V_735 , V_13 ) ;
F_74 ( V_13 -> V_735 , V_737 ) ;
if ( V_738 )
F_75 ( V_738 , V_186 ) ;
return 0 ;
}
static int F_311 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_160 * V_161 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
int V_20 ;
T_1 V_192 = 0 ;
V_20 = F_312 ( V_13 , V_161 , & V_192 ) ;
if ( V_20 == 0 )
F_83 ( V_13 , V_192 ) ;
return V_20 ;
}
static int F_313 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_739 , const T_3 * V_714 , T_3 V_740 ,
T_2 V_741 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_742 * V_743 = & V_13 -> V_16 . V_26 ;
int V_506 = V_744 [ V_740 ] ;
if ( V_13 -> V_27 . type != V_25 )
return - V_343 ;
if ( ! ( V_13 -> V_745 & F_107 ( V_740 ) ) )
return - V_49 ;
if ( V_743 -> V_746 [ V_506 ] . V_741 )
return - V_31 ;
if ( V_741 ) {
V_743 -> V_746 [ V_506 ] . V_741 = 32 * V_741 ;
V_743 -> V_746 [ V_506 ] . V_739 = V_739 ;
V_743 -> V_746 [ V_506 ] . V_740 = V_740 ;
}
return 0 ;
}
static int F_314 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_739 , const T_3 * V_714 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_742 * V_743 = & V_13 -> V_16 . V_26 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_506 ;
for ( V_506 = 0 ; V_506 < V_287 ; V_506 ++ ) {
struct V_747 * V_746 = & V_743 -> V_746 [ V_506 ] ;
if ( ! V_746 -> V_741 )
continue;
if ( V_746 -> V_739 != V_739 )
continue;
V_746 -> V_740 = - 1 ;
F_315 () ;
F_316 ( V_10 , V_13 , false ) ;
V_746 -> V_685 = V_748 ;
V_746 -> V_749 = false ;
F_317 ( V_13 ) ;
memset ( V_746 , 0 , sizeof( * V_746 ) ) ;
return 0 ;
}
return - V_65 ;
}
