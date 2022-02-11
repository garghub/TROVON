static struct V_1 * F_1 ( struct V_2 * V_2 ,
const char * V_3 ,
enum V_4 type ,
T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_1 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_13 = F_3 ( V_9 , V_3 , & V_10 , type , V_7 ) ;
if ( V_13 )
return F_4 ( V_13 ) ;
if ( type == V_14 && V_5 ) {
V_12 = F_5 ( V_10 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
}
return V_10 ;
}
static int F_6 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
F_7 ( F_5 ( V_10 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
enum V_4 type , T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_19 ;
V_19 = F_10 ( V_12 , type ) ;
if ( V_19 )
return V_19 ;
if ( type == V_20 &&
V_7 && V_7 -> V_21 == 0 )
F_11 ( V_12 -> V_15 . V_22 . V_23 , NULL ) ;
else if ( type == V_24 &&
V_7 && V_7 -> V_21 >= 0 )
V_12 -> V_15 . V_25 . V_21 = V_7 -> V_21 ;
if ( V_12 -> V_26 . type == V_14 && V_5 ) {
struct V_8 * V_9 = V_12 -> V_9 ;
if ( F_12 ( V_12 ) ) {
T_1 V_27 = V_28 |
V_29 ;
if ( ( * V_5 & V_27 ) != ( V_12 -> V_15 . V_16 & V_27 ) )
return - V_30 ;
F_13 ( V_12 , - 1 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
F_13 ( V_12 , 1 ) ;
F_14 ( V_9 ) ;
} else {
V_12 -> V_15 . V_16 = * V_5 ;
}
}
return 0 ;
}
static int F_15 ( struct V_2 * V_2 ,
struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
int V_19 ;
F_16 ( & V_12 -> V_9 -> V_31 ) ;
V_19 = F_17 ( V_12 , NULL , 0 , 0 ) ;
F_18 ( & V_12 -> V_9 -> V_31 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_19 ( V_10 , true ) ;
}
static void F_20 ( struct V_2 * V_2 ,
struct V_1 * V_10 )
{
F_21 ( F_5 ( V_10 ) ) ;
}
static int F_22 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_2 V_32 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
V_12 -> V_32 = V_32 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_33 , bool V_34 , const T_3 * V_35 ,
struct V_36 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 = NULL ;
const struct V_38 * V_39 = NULL ;
struct V_40 * V_41 ;
int V_13 ;
if ( ! F_12 ( V_12 ) )
return - V_42 ;
switch ( V_7 -> V_43 ) {
case V_44 :
case V_45 :
case V_46 :
if ( F_24 ( V_9 -> V_47 ) )
return - V_48 ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
break;
default:
V_39 = F_25 ( V_9 , V_7 -> V_43 , V_12 -> V_26 . type ) ;
break;
}
V_41 = F_26 ( V_7 -> V_43 , V_33 , V_7 -> V_57 ,
V_7 -> V_41 , V_7 -> V_58 , V_7 -> V_59 ,
V_39 ) ;
if ( F_24 ( V_41 ) )
return F_27 ( V_41 ) ;
if ( V_34 )
V_41 -> V_60 . V_5 |= V_61 ;
F_16 ( & V_9 -> V_62 ) ;
if ( V_35 ) {
if ( F_28 ( & V_12 -> V_26 ) )
V_23 = F_29 ( V_12 , V_35 ) ;
else
V_23 = F_30 ( V_12 , V_35 ) ;
if ( ! V_23 || ! F_31 ( V_23 , V_63 ) ) {
F_32 ( V_41 ) ;
V_13 = - V_64 ;
goto V_65;
}
}
switch ( V_12 -> V_26 . type ) {
case V_24 :
if ( V_12 -> V_15 . V_25 . V_66 != V_67 )
V_41 -> V_60 . V_5 |= V_68 ;
break;
case V_69 :
case V_20 :
if ( V_41 -> V_23 && F_31 ( V_41 -> V_23 , V_70 ) )
V_41 -> V_60 . V_5 |= V_68 ;
break;
case V_71 :
break;
case V_72 :
#ifdef F_33
if ( V_12 -> V_15 . V_73 . V_74 != V_75 )
V_41 -> V_60 . V_5 |= V_68 ;
break;
#endif
case V_76 :
case V_14 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
F_34 ( 1 ) ;
break;
}
if ( V_23 )
V_23 -> V_83 = V_39 ;
V_13 = F_35 ( V_41 , V_12 , V_23 ) ;
V_65:
F_18 ( & V_9 -> V_62 ) ;
return V_13 ;
}
static int F_36 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_33 , bool V_34 , const T_3 * V_35 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 ;
struct V_40 * V_41 = NULL ;
int V_19 ;
F_16 ( & V_9 -> V_62 ) ;
F_16 ( & V_9 -> V_84 ) ;
if ( V_35 ) {
V_19 = - V_64 ;
V_23 = F_30 ( V_12 , V_35 ) ;
if ( ! V_23 )
goto V_65;
if ( V_34 )
V_41 = F_37 ( V_9 , V_23 -> V_85 [ V_33 ] ) ;
else
V_41 = F_37 ( V_9 , V_23 -> V_86 [ V_33 ] ) ;
} else
V_41 = F_37 ( V_9 , V_12 -> V_87 [ V_33 ] ) ;
if ( ! V_41 ) {
V_19 = - V_64 ;
goto V_65;
}
F_38 ( V_41 , true ) ;
V_19 = 0 ;
V_65:
F_18 ( & V_9 -> V_84 ) ;
F_18 ( & V_9 -> V_62 ) ;
return V_19 ;
}
static int F_39 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_33 , bool V_34 , const T_3 * V_35 ,
void * V_88 ,
void (* F_40)( void * V_88 ,
struct V_36 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_37 * V_23 = NULL ;
T_3 V_59 [ 6 ] = { 0 } ;
struct V_36 V_7 ;
struct V_40 * V_41 = NULL ;
T_4 V_89 ;
T_1 V_90 ;
T_2 V_91 ;
int V_13 = - V_64 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
if ( V_35 ) {
V_23 = F_30 ( V_12 , V_35 ) ;
if ( ! V_23 )
goto V_92;
if ( V_34 && V_33 < V_93 )
V_41 = F_42 ( V_23 -> V_85 [ V_33 ] ) ;
else if ( ! V_34 &&
V_33 < V_93 + V_94 )
V_41 = F_42 ( V_23 -> V_86 [ V_33 ] ) ;
} else
V_41 = F_42 ( V_12 -> V_87 [ V_33 ] ) ;
if ( ! V_41 )
goto V_92;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_43 = V_41 -> V_60 . V_43 ;
switch ( V_41 -> V_60 . V_43 ) {
case V_45 :
V_90 = V_41 -> V_15 . V_95 . V_96 . V_90 ;
V_91 = V_41 -> V_15 . V_95 . V_96 . V_91 ;
if ( V_41 -> V_5 & V_97 )
F_43 ( V_12 -> V_9 ,
V_41 -> V_60 . V_98 ,
& V_90 , & V_91 ) ;
V_59 [ 0 ] = V_91 & 0xff ;
V_59 [ 1 ] = ( V_91 >> 8 ) & 0xff ;
V_59 [ 2 ] = V_90 & 0xff ;
V_59 [ 3 ] = ( V_90 >> 8 ) & 0xff ;
V_59 [ 4 ] = ( V_90 >> 16 ) & 0xff ;
V_59 [ 5 ] = ( V_90 >> 24 ) & 0xff ;
V_7 . V_59 = V_59 ;
V_7 . V_58 = 6 ;
break;
case V_49 :
case V_50 :
V_89 = F_44 ( & V_41 -> V_15 . V_99 . V_100 ) ;
V_59 [ 0 ] = V_89 ;
V_59 [ 1 ] = V_89 >> 8 ;
V_59 [ 2 ] = V_89 >> 16 ;
V_59 [ 3 ] = V_89 >> 24 ;
V_59 [ 4 ] = V_89 >> 32 ;
V_59 [ 5 ] = V_89 >> 40 ;
V_7 . V_59 = V_59 ;
V_7 . V_58 = 6 ;
break;
case V_51 :
case V_52 :
V_89 = F_44 ( & V_41 -> V_15 . V_101 . V_100 ) ;
V_59 [ 0 ] = V_89 ;
V_59 [ 1 ] = V_89 >> 8 ;
V_59 [ 2 ] = V_89 >> 16 ;
V_59 [ 3 ] = V_89 >> 24 ;
V_59 [ 4 ] = V_89 >> 32 ;
V_59 [ 5 ] = V_89 >> 40 ;
V_7 . V_59 = V_59 ;
V_7 . V_58 = 6 ;
break;
case V_53 :
case V_54 :
V_89 = F_44 ( & V_41 -> V_15 . V_102 . V_100 ) ;
V_59 [ 0 ] = V_89 ;
V_59 [ 1 ] = V_89 >> 8 ;
V_59 [ 2 ] = V_89 >> 16 ;
V_59 [ 3 ] = V_89 >> 24 ;
V_59 [ 4 ] = V_89 >> 32 ;
V_59 [ 5 ] = V_89 >> 40 ;
V_7 . V_59 = V_59 ;
V_7 . V_58 = 6 ;
break;
case V_55 :
case V_56 :
V_89 = F_44 ( & V_41 -> V_15 . V_103 . V_100 ) ;
V_59 [ 0 ] = V_89 ;
V_59 [ 1 ] = V_89 >> 8 ;
V_59 [ 2 ] = V_89 >> 16 ;
V_59 [ 3 ] = V_89 >> 24 ;
V_59 [ 4 ] = V_89 >> 32 ;
V_59 [ 5 ] = V_89 >> 40 ;
V_7 . V_59 = V_59 ;
V_7 . V_58 = 6 ;
break;
}
V_7 . V_41 = V_41 -> V_60 . V_41 ;
V_7 . V_57 = V_41 -> V_60 . V_104 ;
F_40 ( V_88 , & V_7 ) ;
V_13 = 0 ;
V_92:
F_45 () ;
return V_13 ;
}
static int F_46 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_33 , bool V_105 ,
bool V_106 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_47 ( V_12 , V_33 , V_105 , V_106 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_33 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_49 ( V_12 , V_33 ) ;
return 0 ;
}
void F_50 ( struct V_37 * V_23 ,
const struct V_107 * V_108 ,
struct V_109 * V_110 )
{
V_110 -> V_5 = 0 ;
if ( V_108 -> V_5 & V_111 ) {
V_110 -> V_5 |= V_112 ;
V_110 -> V_113 = V_108 -> V_114 ;
} else if ( V_108 -> V_5 & V_115 ) {
V_110 -> V_5 |= V_116 ;
V_110 -> V_113 = F_51 ( V_108 ) ;
V_110 -> V_117 = F_52 ( V_108 ) ;
} else {
struct V_118 * V_119 ;
int V_120 = F_53 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_121 ;
V_119 = V_23 -> V_9 -> V_122 . V_2 -> V_123 [
F_54 ( V_23 -> V_12 ) ] ;
V_121 = V_119 -> V_124 [ V_108 -> V_114 ] . V_125 ;
V_110 -> V_126 = F_55 ( V_121 , 1 << V_120 ) ;
}
if ( V_108 -> V_5 & V_127 )
V_110 -> V_128 = V_129 ;
else if ( V_108 -> V_5 & V_130 )
V_110 -> V_128 = V_131 ;
else if ( V_108 -> V_5 & V_132 )
V_110 -> V_128 = V_133 ;
else
V_110 -> V_128 = V_134 ;
if ( V_108 -> V_5 & V_135 )
V_110 -> V_5 |= V_136 ;
}
void F_56 ( struct V_37 * V_23 , struct V_109 * V_110 )
{
V_110 -> V_5 = 0 ;
if ( V_23 -> V_137 & V_138 ) {
V_110 -> V_5 |= V_112 ;
V_110 -> V_113 = V_23 -> V_139 ;
} else if ( V_23 -> V_137 & V_140 ) {
V_110 -> V_5 |= V_116 ;
V_110 -> V_117 = V_23 -> V_141 ;
V_110 -> V_113 = V_23 -> V_139 ;
} else {
struct V_118 * V_119 ;
int V_120 = F_53 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_121 ;
V_119 = V_23 -> V_9 -> V_122 . V_2 -> V_123 [
F_54 ( V_23 -> V_12 ) ] ;
V_121 = V_119 -> V_124 [ V_23 -> V_139 ] . V_125 ;
V_110 -> V_126 = F_55 ( V_121 , 1 << V_120 ) ;
}
if ( V_23 -> V_137 & V_142 )
V_110 -> V_5 |= V_136 ;
if ( V_23 -> V_137 & V_143 )
V_110 -> V_128 = V_144 ;
else if ( V_23 -> V_137 & V_145 )
V_110 -> V_128 = V_146 ;
else if ( V_23 -> V_137 & V_147 )
V_110 -> V_128 = V_129 ;
else if ( V_23 -> V_148 & V_149 )
V_110 -> V_128 = V_131 ;
else if ( V_23 -> V_148 & V_150 )
V_110 -> V_128 = V_133 ;
else
V_110 -> V_128 = V_134 ;
}
static int F_57 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_114 , T_3 * V_151 , struct V_152 * V_153 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 ;
int V_19 = - V_64 ;
F_16 ( & V_9 -> V_62 ) ;
V_23 = F_58 ( V_12 , V_114 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_151 , V_23 -> V_23 . V_154 , V_155 ) ;
F_59 ( V_23 , V_153 ) ;
}
F_18 ( & V_9 -> V_62 ) ;
return V_19 ;
}
static int F_60 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_114 , struct V_156 * V_157 )
{
struct V_8 * V_9 = F_61 ( V_18 -> V_158 ) ;
return F_62 ( V_9 , V_114 , V_157 ) ;
}
static int F_63 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_151 , struct V_152 * V_153 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 ;
int V_19 = - V_64 ;
F_16 ( & V_9 -> V_62 ) ;
V_23 = F_30 ( V_12 , V_151 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_59 ( V_23 , V_153 ) ;
}
F_18 ( & V_9 -> V_62 ) ;
return V_19 ;
}
static int F_64 ( struct V_2 * V_2 ,
struct V_159 * V_160 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_19 = 0 ;
if ( F_65 ( & V_9 -> V_161 , V_160 ) )
return 0 ;
F_16 ( & V_9 -> V_162 ) ;
F_16 ( & V_9 -> V_163 ) ;
if ( V_9 -> V_164 ) {
V_12 = F_66 (
V_9 -> V_165 ,
F_67 ( & V_9 -> V_163 ) ) ;
if ( V_12 ) {
F_68 ( V_12 ) ;
V_19 = F_69 ( V_12 , V_160 ,
V_166 ) ;
}
} else if ( V_9 -> V_167 == V_9 -> V_168 ) {
V_9 -> V_169 = * V_160 ;
F_70 ( V_9 , 0 ) ;
}
if ( V_19 == 0 )
V_9 -> V_161 = * V_160 ;
F_18 ( & V_9 -> V_163 ) ;
F_18 ( & V_9 -> V_162 ) ;
return V_19 ;
}
static int F_71 ( struct V_11 * V_12 ,
const T_3 * V_170 , T_5 V_171 ,
const struct V_172 * V_173 )
{
struct V_174 * V_175 , * V_176 ;
if ( ! V_170 || ! V_171 )
return 1 ;
V_176 = F_72 ( V_12 -> V_15 . V_177 . V_174 , V_12 ) ;
V_175 = F_73 ( sizeof( struct V_174 ) + V_171 , V_178 ) ;
if ( ! V_175 )
return - V_179 ;
V_175 -> V_180 = V_171 ;
memcpy ( V_175 -> V_181 , V_170 , V_171 ) ;
if ( V_173 )
memcpy ( V_175 -> V_182 , V_173 -> V_183 ,
V_173 -> V_184 *
sizeof( V_175 -> V_182 [ 0 ] ) ) ;
F_74 ( V_12 -> V_15 . V_177 . V_174 , V_175 ) ;
if ( V_176 )
F_75 ( V_176 , V_185 ) ;
return 0 ;
}
static int F_76 ( struct V_11 * V_12 ,
struct V_186 * V_7 ,
const struct V_172 * V_173 )
{
struct V_187 * V_175 , * V_176 ;
int V_188 , V_189 ;
int V_190 , V_13 ;
T_1 V_191 = V_192 ;
V_176 = F_72 ( V_12 -> V_15 . V_177 . V_193 , V_12 ) ;
if ( ! V_7 -> V_194 && ! V_176 )
return - V_48 ;
if ( V_7 -> V_194 )
V_188 = V_7 -> V_195 ;
else
V_188 = V_176 -> V_195 ;
if ( V_7 -> V_196 || ! V_176 )
V_189 = V_7 -> V_197 ;
else
V_189 = V_176 -> V_197 ;
V_190 = sizeof( * V_175 ) + V_188 + V_189 ;
V_175 = F_73 ( V_190 , V_178 ) ;
if ( ! V_175 )
return - V_179 ;
V_175 -> V_194 = ( ( T_3 * ) V_175 ) + sizeof( * V_175 ) ;
V_175 -> V_196 = V_175 -> V_194 + V_188 ;
V_175 -> V_195 = V_188 ;
V_175 -> V_197 = V_189 ;
if ( V_173 ) {
V_175 -> V_198 = V_173 -> V_199 ;
memcpy ( V_175 -> V_182 , V_173 -> V_200 ,
V_173 -> V_201 *
sizeof( V_175 -> V_182 [ 0 ] ) ) ;
}
if ( V_7 -> V_194 )
memcpy ( V_175 -> V_194 , V_7 -> V_194 , V_188 ) ;
else
memcpy ( V_175 -> V_194 , V_176 -> V_194 , V_188 ) ;
if ( V_7 -> V_196 )
memcpy ( V_175 -> V_196 , V_7 -> V_196 , V_189 ) ;
else
if ( V_176 )
memcpy ( V_175 -> V_196 , V_176 -> V_196 , V_189 ) ;
V_13 = F_71 ( V_12 , V_7 -> V_174 ,
V_7 -> V_202 , V_173 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_191 |= V_203 ;
F_74 ( V_12 -> V_15 . V_177 . V_193 , V_175 ) ;
if ( V_176 )
F_75 ( V_176 , V_185 ) ;
return V_191 ;
}
static int F_77 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_204 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_187 * V_176 ;
struct V_11 * V_22 ;
T_1 V_191 = V_205 |
V_206 |
V_192 |
V_207 |
V_208 |
V_209 ;
int V_13 ;
V_176 = F_72 ( V_12 -> V_15 . V_177 . V_193 , V_12 ) ;
if ( V_176 )
return - V_210 ;
switch ( V_7 -> V_211 ) {
case V_212 :
V_12 -> V_211 = V_213 ;
break;
case V_214 :
V_12 -> V_211 = V_215 ;
break;
case V_216 :
V_12 -> V_211 = V_217 ;
break;
default:
return - V_48 ;
}
V_12 -> V_218 = V_12 -> V_9 -> V_219 ;
F_16 ( & V_9 -> V_162 ) ;
V_13 = F_69 ( V_12 , & V_7 -> V_160 ,
V_220 ) ;
if ( ! V_13 )
F_78 ( V_12 , false ) ;
F_18 ( & V_9 -> V_162 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_221 = V_7 -> V_222 . V_223 ;
V_12 -> V_224 = V_7 -> V_222 . V_224 ;
V_12 -> V_225 = F_79 ( V_12 -> V_9 ,
& V_7 -> V_222 ,
V_12 -> V_26 . type ) ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_221 =
V_7 -> V_222 . V_223 ;
V_22 -> V_224 =
V_7 -> V_222 . V_224 ;
V_22 -> V_225 =
F_79 ( V_12 -> V_9 ,
& V_7 -> V_222 ,
V_22 -> V_26 . type ) ;
}
V_12 -> V_26 . V_226 . V_227 = V_7 -> V_228 ;
V_12 -> V_26 . V_226 . V_229 = V_7 -> V_229 ;
V_12 -> V_26 . V_226 . V_230 = true ;
V_12 -> V_26 . V_226 . V_231 = V_7 -> V_231 ;
if ( V_7 -> V_231 )
memcpy ( V_12 -> V_26 . V_226 . V_232 , V_7 -> V_232 ,
V_7 -> V_231 ) ;
V_12 -> V_26 . V_226 . V_233 =
( V_7 -> V_233 != V_234 ) ;
memset ( & V_12 -> V_26 . V_226 . V_235 , 0 ,
sizeof( V_12 -> V_26 . V_226 . V_235 ) ) ;
V_12 -> V_26 . V_226 . V_235 . V_236 =
V_7 -> V_237 & V_238 ;
if ( V_7 -> V_239 )
V_12 -> V_26 . V_226 . V_235 . V_236 |=
V_240 ;
V_13 = F_76 ( V_12 , & V_7 -> V_193 , NULL ) ;
if ( V_13 < 0 ) {
F_68 ( V_12 ) ;
return V_13 ;
}
V_191 |= V_13 ;
V_13 = F_81 ( V_12 -> V_9 , V_12 ) ;
if ( V_13 ) {
V_176 = F_72 ( V_12 -> V_15 . V_177 . V_193 , V_12 ) ;
if ( V_176 )
F_75 ( V_176 , V_185 ) ;
F_11 ( V_12 -> V_15 . V_177 . V_193 , NULL ) ;
F_68 ( V_12 ) ;
return V_13 ;
}
F_82 ( V_9 , V_12 ) ;
F_83 ( V_12 , V_191 ) ;
F_84 ( V_18 ) ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_84 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_186 * V_7 )
{
struct V_11 * V_12 ;
struct V_187 * V_176 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
F_86 ( V_12 ) ;
if ( V_12 -> V_26 . V_241 )
return - V_30 ;
V_176 = F_72 ( V_12 -> V_15 . V_177 . V_193 , V_12 ) ;
if ( ! V_176 )
return - V_64 ;
V_13 = F_76 ( V_12 , V_7 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
F_83 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_87 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_11 * V_22 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_187 * V_242 ;
struct V_174 * V_243 ;
struct V_159 V_160 ;
F_86 ( V_12 ) ;
V_242 = F_72 ( V_12 -> V_15 . V_177 . V_193 , V_12 ) ;
if ( ! V_242 )
return - V_64 ;
V_243 = F_72 ( V_12 -> V_15 . V_177 . V_174 , V_12 ) ;
F_16 ( & V_9 -> V_162 ) ;
V_12 -> V_26 . V_241 = false ;
if ( V_12 -> V_244 ) {
F_88 ( V_9 , V_12 ,
V_245 ) ;
V_12 -> V_244 = false ;
}
F_18 ( & V_9 -> V_162 ) ;
F_89 ( V_12 -> V_15 . V_177 . V_246 ) ;
V_12 -> V_15 . V_177 . V_246 = NULL ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_90 ( V_22 -> V_18 ) ;
F_90 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_177 . V_193 , NULL ) ;
F_11 ( V_12 -> V_15 . V_177 . V_174 , NULL ) ;
F_75 ( V_242 , V_185 ) ;
if ( V_243 )
F_75 ( V_243 , V_185 ) ;
V_12 -> V_15 . V_177 . V_247 = V_213 ;
F_91 ( V_12 , true ) ;
F_92 ( V_12 , true ) ;
V_12 -> V_26 . V_226 . V_230 = false ;
V_12 -> V_26 . V_226 . V_231 = 0 ;
F_93 ( V_248 , & V_12 -> V_249 ) ;
F_83 ( V_12 , V_206 ) ;
if ( V_12 -> V_10 . V_250 ) {
V_160 = V_12 -> V_26 . V_226 . V_160 ;
F_94 ( & V_12 -> V_251 ) ;
F_95 ( V_12 -> V_18 , & V_160 ,
V_252 ,
V_178 ) ;
}
F_96 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_253 -= F_97 ( & V_12 -> V_15 . V_177 . V_254 . V_255 ) ;
F_98 ( & V_12 -> V_15 . V_177 . V_254 . V_255 ) ;
F_16 ( & V_9 -> V_162 ) ;
F_78 ( V_12 , true ) ;
F_68 ( V_12 ) ;
F_18 ( & V_9 -> V_162 ) ;
return 0 ;
}
static void F_99 ( struct V_37 * V_23 )
{
struct V_256 * V_257 ;
struct V_258 * V_259 ;
V_259 = F_100 ( sizeof( * V_257 ) ) ;
if ( ! V_259 )
return;
V_257 = (struct V_256 * ) F_101 ( V_259 , sizeof( * V_257 ) ) ;
F_102 ( V_257 -> V_260 ) ;
memcpy ( V_257 -> V_261 , V_23 -> V_23 . V_154 , V_155 ) ;
V_257 -> V_180 = F_103 ( 6 ) ;
V_257 -> V_262 = 0 ;
V_257 -> V_263 = 0x01 ;
V_257 -> V_264 = 0xaf ;
V_257 -> V_265 [ 0 ] = 0x81 ;
V_257 -> V_265 [ 1 ] = 1 ;
V_257 -> V_265 [ 2 ] = 0 ;
V_259 -> V_18 = V_23 -> V_12 -> V_18 ;
V_259 -> V_266 = F_104 ( V_259 , V_23 -> V_12 -> V_18 ) ;
memset ( V_259 -> V_267 , 0 , sizeof( V_259 -> V_267 ) ) ;
F_105 ( V_259 ) ;
}
static int F_106 ( struct V_8 * V_9 ,
struct V_37 * V_23 ,
T_1 V_27 , T_1 V_268 )
{
int V_19 ;
if ( V_27 & F_107 ( V_269 ) &&
V_268 & F_107 ( V_269 ) &&
! F_31 ( V_23 , V_270 ) ) {
V_19 = F_108 ( V_23 , V_271 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_272 ) &&
V_268 & F_107 ( V_272 ) &&
! F_31 ( V_23 , V_63 ) ) {
V_19 = F_108 ( V_23 , V_273 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_274 ) ) {
if ( V_268 & F_107 ( V_274 ) )
V_19 = F_108 ( V_23 , V_275 ) ;
else if ( F_31 ( V_23 , V_276 ) )
V_19 = F_108 ( V_23 , V_273 ) ;
else
V_19 = 0 ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_272 ) &&
! ( V_268 & F_107 ( V_272 ) ) &&
F_31 ( V_23 , V_63 ) ) {
V_19 = F_108 ( V_23 , V_271 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_269 ) &&
! ( V_268 & F_107 ( V_269 ) ) &&
F_31 ( V_23 , V_270 ) ) {
V_19 = F_108 ( V_23 , V_277 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_109 ( struct V_8 * V_9 ,
struct V_37 * V_23 ,
struct V_278 * V_7 )
{
int V_19 = 0 ;
struct V_118 * V_119 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_279 V_280 = F_54 ( V_12 ) ;
T_1 V_27 , V_268 ;
V_119 = V_9 -> V_122 . V_2 -> V_123 [ V_280 ] ;
V_27 = V_7 -> V_281 ;
V_268 = V_7 -> V_282 ;
if ( F_28 ( & V_12 -> V_26 ) ) {
if ( V_27 & F_107 ( V_269 ) )
V_27 |= F_107 ( V_272 ) ;
if ( V_268 & F_107 ( V_269 ) )
V_268 |= F_107 ( V_272 ) ;
} else if ( F_31 ( V_23 , V_283 ) ) {
if ( V_268 & F_107 ( V_274 ) ) {
V_268 |= F_107 ( V_269 ) |
F_107 ( V_272 ) ;
V_27 |= F_107 ( V_269 ) |
F_107 ( V_272 ) ;
}
}
if ( ! F_31 ( V_23 , V_283 ) ) {
V_19 = F_106 ( V_9 , V_23 , V_27 , V_268 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_284 ) ) {
if ( V_268 & F_107 ( V_284 ) )
F_110 ( V_23 , V_285 ) ;
else
F_111 ( V_23 , V_285 ) ;
}
if ( V_27 & F_107 ( V_286 ) )
V_23 -> V_23 . V_287 = V_268 & F_107 ( V_286 ) ;
if ( V_27 & F_107 ( V_288 ) ) {
if ( V_268 & F_107 ( V_288 ) )
F_110 ( V_23 , V_70 ) ;
else
F_111 ( V_23 , V_70 ) ;
}
if ( V_27 & F_107 ( V_289 ) ) {
if ( V_268 & F_107 ( V_289 ) )
F_110 ( V_23 , V_283 ) ;
else
F_111 ( V_23 , V_283 ) ;
}
if ( F_31 ( V_23 , V_283 ) &&
! V_12 -> V_15 . V_25 . V_290 &&
V_7 -> V_291 >= 4 &&
V_7 -> V_292 [ 3 ] & V_293 )
F_110 ( V_23 , V_294 ) ;
if ( V_7 -> V_295 & V_296 ) {
V_23 -> V_23 . V_297 = V_7 -> V_297 ;
V_23 -> V_23 . V_298 = V_7 -> V_298 ;
}
if ( V_7 -> V_299 )
V_23 -> V_23 . V_299 = V_7 -> V_299 ;
if ( V_7 -> V_300 >= 0 )
V_23 -> V_300 = V_7 -> V_300 ;
if ( V_7 -> V_301 ) {
F_112 ( & V_12 -> V_26 . V_226 . V_160 ,
V_119 , V_7 -> V_301 ,
V_7 -> V_302 ,
& V_23 -> V_23 . V_303 [ V_280 ] ) ;
}
if ( V_7 -> V_304 )
F_113 ( V_12 , V_119 ,
V_7 -> V_304 , V_23 ) ;
if ( V_7 -> V_305 )
F_114 ( V_12 , V_119 ,
V_7 -> V_305 , V_23 ) ;
if ( V_7 -> V_306 ) {
F_115 ( V_12 , V_23 ,
V_7 -> V_307 ,
V_280 , false ) ;
}
if ( F_28 ( & V_12 -> V_26 ) ) {
#ifdef F_33
T_1 V_191 = 0 ;
if ( V_7 -> V_295 & V_308 ) {
switch ( V_7 -> V_309 ) {
case V_310 :
if ( V_23 -> V_309 != V_310 )
V_191 = F_116 (
V_12 ) ;
V_23 -> V_309 = V_7 -> V_309 ;
F_117 ( V_23 ) ;
V_191 |= F_118 ( V_23 ,
V_12 -> V_15 . V_73 . V_311 . V_312 ) ;
break;
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
if ( V_23 -> V_309 == V_310 )
V_191 = F_119 (
V_12 ) ;
V_23 -> V_309 = V_7 -> V_309 ;
F_117 ( V_23 ) ;
V_191 |= F_118 ( V_23 ,
V_319 ) ;
break;
default:
break;
}
}
switch ( V_7 -> V_320 ) {
case V_321 :
break;
case V_322 :
V_191 |= F_120 ( V_23 ) ;
break;
case V_323 :
V_191 |= F_121 ( V_23 ) ;
break;
}
if ( V_7 -> V_324 )
V_191 |=
F_118 ( V_23 ,
V_7 -> V_324 ) ;
F_122 ( V_12 , V_191 ) ;
#endif
}
if ( F_31 ( V_23 , V_283 ) ) {
V_19 = F_106 ( V_9 , V_23 , V_27 , V_268 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_123 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_151 ,
struct V_278 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_37 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_325 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_69 )
return - V_48 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_124 ( V_151 , V_12 -> V_26 . V_154 ) )
return - V_48 ;
if ( F_125 ( V_151 ) )
return - V_48 ;
V_23 = F_126 ( V_12 , V_151 , V_178 ) ;
if ( ! V_23 )
return - V_179 ;
if ( ! ( V_7 -> V_282 & F_107 ( V_289 ) ) ) {
F_127 ( V_23 , V_271 ) ;
F_127 ( V_23 , V_273 ) ;
} else {
V_23 -> V_23 . V_326 = true ;
}
V_13 = F_109 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_128 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_31 ( V_23 , V_283 ) )
F_129 ( V_23 ) ;
V_325 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_69 ;
V_13 = F_130 ( V_23 ) ;
if ( V_13 ) {
F_45 () ;
return V_13 ;
}
if ( V_325 )
F_99 ( V_23 ) ;
F_45 () ;
return 0 ;
}
static int F_131 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_327 * V_7 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_7 -> V_151 )
return F_132 ( V_12 , V_7 -> V_151 ) ;
F_133 ( V_12 ) ;
return 0 ;
}
static int F_134 ( struct V_2 * V_2 ,
struct V_17 * V_18 , const T_3 * V_151 ,
struct V_278 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_37 * V_23 ;
struct V_11 * V_328 ;
enum V_329 V_330 ;
int V_13 ;
F_16 ( & V_9 -> V_62 ) ;
V_23 = F_30 ( V_12 , V_151 ) ;
if ( ! V_23 ) {
V_13 = - V_64 ;
goto V_331;
}
switch ( V_12 -> V_26 . type ) {
case V_72 :
if ( V_12 -> V_15 . V_73 . V_332 )
V_330 = V_333 ;
else
V_330 = V_334 ;
break;
case V_71 :
V_330 = V_335 ;
break;
case V_24 :
if ( ! F_31 ( V_23 , V_283 ) ) {
V_330 = V_336 ;
break;
}
if ( F_31 ( V_23 , V_276 ) )
V_330 = V_337 ;
else
V_330 = V_338 ;
break;
case V_69 :
case V_20 :
V_330 = V_339 ;
break;
default:
V_13 = - V_340 ;
goto V_331;
}
V_13 = F_135 ( V_2 , V_7 , V_330 ) ;
if ( V_13 )
goto V_331;
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_341 = false ;
bool V_342 = false ;
V_328 = F_9 ( V_7 -> V_22 ) ;
if ( V_7 -> V_22 -> V_158 -> V_21 ) {
if ( V_328 -> V_15 . V_22 . V_23 ) {
V_13 = - V_30 ;
goto V_331;
}
F_74 ( V_328 -> V_15 . V_22 . V_23 , V_23 ) ;
V_342 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_11 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_341 = true ;
}
V_23 -> V_12 = V_328 ;
if ( V_23 -> V_343 == V_275 &&
V_341 != V_342 ) {
if ( V_342 )
F_136 ( & V_23 -> V_12 -> V_344 -> V_345 ) ;
else
F_137 ( & V_23 -> V_12 -> V_344 -> V_345 ) ;
}
F_99 ( V_23 ) ;
}
V_13 = F_109 ( V_9 , V_23 , V_7 ) ;
if ( V_13 )
goto V_331;
if ( F_31 ( V_23 , V_283 ) &&
F_31 ( V_23 , V_276 ) )
F_129 ( V_23 ) ;
F_18 ( & V_9 -> V_62 ) ;
if ( ( V_12 -> V_26 . type == V_69 ||
V_12 -> V_26 . type == V_20 ) &&
V_23 -> V_346 != V_23 -> V_12 -> V_344 -> V_347 &&
F_31 ( V_23 , V_276 ) &&
F_138 ( V_23 ) != 1 ) {
F_139 ( V_23 -> V_12 ,
L_1 ,
V_23 -> V_23 . V_154 ) ;
F_140 ( V_23 -> V_12 ,
V_23 -> V_12 -> V_344 -> V_347 ,
V_23 -> V_23 . V_154 ,
V_23 -> V_12 -> V_26 . V_226 . V_348 ) ;
}
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_281 & F_107 ( V_274 ) ) {
F_141 ( V_9 , - 1 ) ;
F_142 ( V_12 ) ;
}
return 0 ;
V_331:
F_18 ( & V_9 -> V_62 ) ;
return V_13 ;
}
static int F_143 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_349 , const T_3 * V_350 )
{
struct V_11 * V_12 ;
struct V_351 * V_352 ;
struct V_37 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_23 = F_29 ( V_12 , V_350 ) ;
if ( ! V_23 ) {
F_45 () ;
return - V_64 ;
}
V_352 = F_144 ( V_12 , V_349 ) ;
if ( F_24 ( V_352 ) ) {
F_45 () ;
return F_27 ( V_352 ) ;
}
F_145 ( V_352 , V_23 ) ;
F_45 () ;
return 0 ;
}
static int F_146 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_349 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_349 )
return F_147 ( V_12 , V_349 ) ;
F_148 ( V_12 ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_349 , const T_3 * V_350 )
{
struct V_11 * V_12 ;
struct V_351 * V_352 ;
struct V_37 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_23 = F_29 ( V_12 , V_350 ) ;
if ( ! V_23 ) {
F_45 () ;
return - V_64 ;
}
V_352 = F_150 ( V_12 , V_349 ) ;
if ( ! V_352 ) {
F_45 () ;
return - V_64 ;
}
F_145 ( V_352 , V_23 ) ;
F_45 () ;
return 0 ;
}
static void F_151 ( struct V_351 * V_352 , T_3 * V_350 ,
struct V_353 * V_354 )
{
struct V_37 * V_355 = F_42 ( V_352 -> V_350 ) ;
if ( V_355 )
memcpy ( V_350 , V_355 -> V_23 . V_154 , V_155 ) ;
else
memset ( V_350 , 0 , V_155 ) ;
memset ( V_354 , 0 , sizeof( * V_354 ) ) ;
V_354 -> V_356 = V_357 ;
V_354 -> V_358 = V_359 |
V_360 |
V_361 |
V_362 |
V_363 |
V_364 |
V_365 ;
V_354 -> V_366 = V_352 -> V_367 . V_368 ;
V_354 -> V_369 = V_352 -> V_369 ;
V_354 -> V_370 = V_352 -> V_370 ;
if ( F_152 ( V_371 , V_352 -> V_372 ) )
V_354 -> V_373 = F_153 ( V_352 -> V_372 - V_371 ) ;
V_354 -> V_374 =
F_153 ( V_352 -> V_374 ) ;
V_354 -> V_375 = V_352 -> V_375 ;
if ( V_352 -> V_5 & V_376 )
V_354 -> V_5 |= V_377 ;
if ( V_352 -> V_5 & V_378 )
V_354 -> V_5 |= V_379 ;
if ( V_352 -> V_5 & V_380 )
V_354 -> V_5 |= V_381 ;
if ( V_352 -> V_5 & V_382 )
V_354 -> V_5 |= V_383 ;
if ( V_352 -> V_5 & V_384 )
V_354 -> V_5 |= V_385 ;
}
static int F_154 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_349 , T_3 * V_350 , struct V_353 * V_354 )
{
struct V_11 * V_12 ;
struct V_351 * V_352 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_352 = F_150 ( V_12 , V_349 ) ;
if ( ! V_352 ) {
F_45 () ;
return - V_64 ;
}
memcpy ( V_349 , V_352 -> V_349 , V_155 ) ;
F_151 ( V_352 , V_350 , V_354 ) ;
F_45 () ;
return 0 ;
}
static int F_155 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_114 , T_3 * V_349 , T_3 * V_350 ,
struct V_353 * V_354 )
{
struct V_11 * V_12 ;
struct V_351 * V_352 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_352 = F_156 ( V_12 , V_114 ) ;
if ( ! V_352 ) {
F_45 () ;
return - V_64 ;
}
memcpy ( V_349 , V_352 -> V_349 , V_155 ) ;
F_151 ( V_352 , V_350 , V_354 ) ;
F_45 () ;
return 0 ;
}
static void F_157 ( struct V_351 * V_352 , T_3 * V_386 ,
struct V_353 * V_354 )
{
memset ( V_354 , 0 , sizeof( * V_354 ) ) ;
memcpy ( V_386 , V_352 -> V_386 , V_155 ) ;
V_354 -> V_356 = V_387 ;
}
static int F_158 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_349 , T_3 * V_386 , struct V_353 * V_354 )
{
struct V_11 * V_12 ;
struct V_351 * V_352 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_352 = F_159 ( V_12 , V_349 ) ;
if ( ! V_352 ) {
F_45 () ;
return - V_64 ;
}
memcpy ( V_349 , V_352 -> V_349 , V_155 ) ;
F_157 ( V_352 , V_386 , V_354 ) ;
F_45 () ;
return 0 ;
}
static int F_160 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_114 , T_3 * V_349 , T_3 * V_386 ,
struct V_353 * V_354 )
{
struct V_11 * V_12 ;
struct V_351 * V_352 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_352 = F_161 ( V_12 , V_114 ) ;
if ( ! V_352 ) {
F_45 () ;
return - V_64 ;
}
memcpy ( V_349 , V_352 -> V_349 , V_155 ) ;
F_157 ( V_352 , V_386 , V_354 ) ;
F_45 () ;
return 0 ;
}
static int F_162 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_388 * V_60 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_60 , & ( V_12 -> V_15 . V_73 . V_311 ) , sizeof( struct V_388 ) ) ;
return 0 ;
}
static inline bool F_163 ( enum V_389 V_390 , T_1 V_27 )
{
return ( V_27 >> ( V_390 - 1 ) ) & 0x1 ;
}
static int F_164 ( struct V_391 * V_392 ,
const struct V_393 * V_394 )
{
T_3 * V_395 ;
const T_3 * V_396 ;
struct V_11 * V_12 = F_165 ( V_392 ,
struct V_11 , V_15 . V_73 ) ;
V_395 = NULL ;
V_396 = V_392 -> V_397 ;
if ( V_394 -> V_398 ) {
V_395 = F_166 ( V_394 -> V_397 , V_394 -> V_398 ,
V_178 ) ;
if ( ! V_395 )
return - V_179 ;
}
V_392 -> V_398 = V_394 -> V_398 ;
V_392 -> V_397 = V_395 ;
F_89 ( V_396 ) ;
V_392 -> V_399 = V_394 -> V_399 ;
memcpy ( V_392 -> V_400 , V_394 -> V_400 , V_392 -> V_399 ) ;
V_392 -> V_401 = V_394 -> V_402 ;
V_392 -> V_403 = V_394 -> V_404 ;
V_392 -> V_405 = V_394 -> V_406 ;
V_392 -> V_332 = V_394 -> V_332 ;
V_392 -> V_407 = V_394 -> V_408 ;
V_392 -> V_74 = V_75 ;
if ( V_394 -> V_409 )
V_392 -> V_74 |= V_410 ;
if ( V_394 -> V_411 )
V_392 -> V_74 |= V_412 ;
memcpy ( V_12 -> V_26 . V_226 . V_413 , V_394 -> V_413 ,
sizeof( V_394 -> V_413 ) ) ;
V_12 -> V_26 . V_226 . V_414 = V_394 -> V_414 ;
V_12 -> V_26 . V_226 . V_227 = V_394 -> V_228 ;
V_12 -> V_26 . V_226 . V_229 = V_394 -> V_229 ;
return 0 ;
}
static int F_167 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_27 ,
const struct V_388 * V_415 )
{
struct V_388 * V_60 ;
struct V_11 * V_12 ;
struct V_391 * V_392 ;
V_12 = F_9 ( V_18 ) ;
V_392 = & V_12 -> V_15 . V_73 ;
V_60 = & ( V_12 -> V_15 . V_73 . V_311 ) ;
if ( F_163 ( V_416 , V_27 ) )
V_60 -> V_417 = V_415 -> V_417 ;
if ( F_163 ( V_418 , V_27 ) )
V_60 -> V_419 = V_415 -> V_419 ;
if ( F_163 ( V_420 , V_27 ) )
V_60 -> V_421 = V_415 -> V_421 ;
if ( F_163 ( V_422 , V_27 ) )
V_60 -> V_423 = V_415 -> V_423 ;
if ( F_163 ( V_424 , V_27 ) )
V_60 -> V_425 = V_415 -> V_425 ;
if ( F_163 ( V_426 , V_27 ) )
V_60 -> V_427 = V_415 -> V_427 ;
if ( F_163 ( V_428 , V_27 ) )
V_60 -> V_429 = V_415 -> V_429 ;
if ( F_163 ( V_430 , V_27 ) ) {
if ( V_392 -> V_332 )
return - V_30 ;
V_60 -> V_431 = V_415 -> V_431 ;
}
if ( F_163 ( V_432 , V_27 ) )
V_60 -> V_433 =
V_415 -> V_433 ;
if ( F_163 ( V_434 , V_27 ) )
V_60 -> V_435 =
V_415 -> V_435 ;
if ( F_163 ( V_436 , V_27 ) )
V_60 -> V_437 = V_415 -> V_437 ;
if ( F_163 ( V_438 , V_27 ) )
V_60 -> V_439 = V_415 -> V_439 ;
if ( F_163 ( V_440 , V_27 ) )
V_60 -> V_441 =
V_415 -> V_441 ;
if ( F_163 ( V_442 , V_27 ) )
V_60 -> V_443 =
V_415 -> V_443 ;
if ( F_163 ( V_444 , V_27 ) )
V_60 -> V_445 =
V_415 -> V_445 ;
if ( F_163 ( V_446 ,
V_27 ) )
V_60 -> V_447 =
V_415 -> V_447 ;
if ( F_163 ( V_448 , V_27 ) ) {
V_60 -> V_449 = V_415 -> V_449 ;
F_168 ( V_392 ) ;
}
if ( F_163 ( V_450 , V_27 ) ) {
if ( V_415 -> V_451 &&
! ( V_60 -> V_449 > V_452 ) ) {
V_60 -> V_449 = V_453 ;
F_168 ( V_392 ) ;
}
V_60 -> V_451 =
V_415 -> V_451 ;
}
if ( F_163 ( V_454 , V_27 ) )
V_60 -> V_455 =
V_415 -> V_455 ;
if ( F_163 ( V_456 , V_27 ) )
V_60 -> V_457 = V_415 -> V_457 ;
if ( F_163 ( V_458 , V_27 ) ) {
if ( ! ( V_12 -> V_9 -> V_122 . V_5 & V_459 ) )
return - V_460 ;
V_60 -> V_461 = V_415 -> V_461 ;
}
if ( F_163 ( V_462 , V_27 ) ) {
V_60 -> V_463 = V_415 -> V_463 ;
V_12 -> V_26 . V_226 . V_464 = V_415 -> V_463 ;
F_83 ( V_12 , V_465 ) ;
}
if ( F_163 ( V_466 , V_27 ) )
V_60 -> V_467 =
V_415 -> V_467 ;
if ( F_163 ( V_468 , V_27 ) )
V_60 -> V_469 =
V_415 -> V_469 ;
if ( F_163 ( V_470 , V_27 ) )
V_60 -> V_471 =
V_415 -> V_471 ;
if ( F_163 ( V_472 , V_27 ) ) {
V_60 -> V_312 = V_415 -> V_312 ;
F_169 ( V_12 ) ;
}
if ( F_163 ( V_473 , V_27 ) )
V_60 -> V_474 =
V_415 -> V_474 ;
if ( F_163 ( V_475 , V_27 ) )
V_60 -> V_476 = V_415 -> V_476 ;
F_122 ( V_12 , V_192 ) ;
return 0 ;
}
static int F_170 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_388 * V_60 ,
const struct V_393 * V_394 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_391 * V_392 = & V_12 -> V_15 . V_73 ;
int V_13 ;
memcpy ( & V_392 -> V_311 , V_60 , sizeof( struct V_388 ) ) ;
V_13 = F_164 ( V_392 , V_394 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_211 = V_213 ;
V_12 -> V_218 = V_12 -> V_9 -> V_219 ;
F_16 ( & V_12 -> V_9 -> V_162 ) ;
V_13 = F_69 ( V_12 , & V_394 -> V_160 ,
V_220 ) ;
F_18 ( & V_12 -> V_9 -> V_162 ) ;
if ( V_13 )
return V_13 ;
return F_171 ( V_12 ) ;
}
static int F_172 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_173 ( V_12 ) ;
F_16 ( & V_12 -> V_9 -> V_162 ) ;
F_68 ( V_12 ) ;
F_18 ( & V_12 -> V_9 -> V_162 ) ;
return 0 ;
}
static int F_174 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_477 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_279 V_280 ;
T_1 V_191 = 0 ;
if ( ! F_72 ( V_12 -> V_15 . V_177 . V_193 , V_12 ) )
return - V_64 ;
V_280 = F_54 ( V_12 ) ;
if ( V_7 -> V_478 >= 0 ) {
V_12 -> V_26 . V_226 . V_478 = V_7 -> V_478 ;
V_191 |= V_479 ;
}
if ( V_7 -> V_480 >= 0 ) {
V_12 -> V_26 . V_226 . V_480 =
V_7 -> V_480 ;
V_191 |= V_481 ;
}
if ( ! V_12 -> V_26 . V_226 . V_482 &&
V_280 == V_483 ) {
V_12 -> V_26 . V_226 . V_482 = true ;
V_191 |= V_484 ;
}
if ( V_7 -> V_485 >= 0 ) {
V_12 -> V_26 . V_226 . V_482 =
V_7 -> V_485 ;
V_191 |= V_484 ;
}
if ( V_7 -> V_414 ) {
F_112 ( & V_12 -> V_26 . V_226 . V_160 ,
V_2 -> V_123 [ V_280 ] ,
V_7 -> V_414 ,
V_7 -> V_486 ,
& V_12 -> V_26 . V_226 . V_414 ) ;
V_191 |= V_487 ;
}
if ( V_7 -> V_488 >= 0 ) {
if ( V_7 -> V_488 )
V_12 -> V_5 |= V_489 ;
else
V_12 -> V_5 &= ~ V_489 ;
}
if ( V_7 -> V_463 >= 0 ) {
V_12 -> V_26 . V_226 . V_464 =
( T_2 ) V_7 -> V_463 ;
V_191 |= V_465 ;
}
if ( V_7 -> V_237 >= 0 ) {
V_12 -> V_26 . V_226 . V_235 . V_236 &=
~ V_238 ;
V_12 -> V_26 . V_226 . V_235 . V_236 |=
V_7 -> V_237 & V_238 ;
V_191 |= V_208 ;
}
if ( V_7 -> V_239 > 0 ) {
V_12 -> V_26 . V_226 . V_235 . V_236 |=
V_240 ;
V_191 |= V_208 ;
} else if ( V_7 -> V_239 == 0 ) {
V_12 -> V_26 . V_226 . V_235 . V_236 &=
~ V_240 ;
V_191 |= V_208 ;
}
F_83 ( V_12 , V_191 ) ;
return 0 ;
}
static int F_175 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_490 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_491 V_492 ;
if ( ! V_9 -> V_493 -> V_494 )
return - V_340 ;
if ( V_9 -> V_122 . V_495 < V_496 )
return - V_340 ;
memset ( & V_492 , 0 , sizeof( V_492 ) ) ;
V_492 . V_497 = V_7 -> V_497 ;
V_492 . V_498 = V_7 -> V_499 ;
V_492 . V_500 = V_7 -> V_501 ;
V_492 . V_502 = V_7 -> V_502 ;
V_492 . V_503 = false ;
V_12 -> V_504 [ V_7 -> V_505 ] = V_492 ;
if ( F_176 ( V_9 , V_12 , V_7 -> V_505 , & V_492 ) ) {
F_177 ( V_9 -> V_122 . V_2 ,
L_2 ,
V_7 -> V_505 ) ;
return - V_48 ;
}
F_83 ( V_12 , V_506 ) ;
return 0 ;
}
static int F_178 ( struct V_2 * V_2 ,
struct V_507 * V_508 )
{
return F_179 ( F_2 ( V_2 ) , V_508 ) ;
}
static int F_180 ( struct V_2 * V_2 )
{
return F_181 ( F_2 ( V_2 ) ) ;
}
static int F_182 ( struct V_2 * V_2 ,
struct V_509 * V_510 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_510 -> V_10 ) ;
switch ( F_183 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_71 :
case V_72 :
case V_80 :
case V_77 :
break;
case V_81 :
if ( V_12 -> V_9 -> V_493 -> V_511 )
break;
case V_69 :
if ( V_12 -> V_15 . V_177 . V_193 &&
( ! ( V_2 -> V_512 & V_513 ) ||
! ( V_510 -> V_5 & V_514 ) ) )
return - V_340 ;
break;
default:
return - V_340 ;
}
return F_184 ( V_12 , V_510 ) ;
}
static int
F_185 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_515 * V_510 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_493 -> V_516 )
return - V_340 ;
return F_186 ( V_12 , V_510 ) ;
}
static int
F_187 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_493 -> V_517 )
return - V_340 ;
return F_188 ( V_12 ) ;
}
static int F_189 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_518 * V_510 )
{
return F_190 ( F_9 ( V_18 ) , V_510 ) ;
}
static int F_191 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_519 * V_510 )
{
return F_192 ( F_9 ( V_18 ) , V_510 ) ;
}
static int F_193 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_520 * V_510 )
{
return F_194 ( F_9 ( V_18 ) , V_510 ) ;
}
static int F_195 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_521 * V_510 )
{
return F_196 ( F_9 ( V_18 ) , V_510 ) ;
}
static int F_197 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_522 * V_7 )
{
return F_198 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_199 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_200 ( F_9 ( V_18 ) ) ;
}
static int F_201 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_523 * V_394 )
{
return F_202 ( F_9 ( V_18 ) , V_394 ) ;
}
static int F_203 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_204 ( F_9 ( V_18 ) ) ;
}
static int F_205 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_108 [ V_524 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_226 . V_413 , V_108 ,
sizeof( int ) * V_524 ) ;
return 0 ;
}
static int F_206 ( struct V_2 * V_2 , T_1 V_191 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_191 & V_525 ) {
V_13 = F_207 ( V_9 , V_2 -> V_526 ) ;
if ( V_13 )
return V_13 ;
}
if ( ( V_191 & V_527 ) ||
( V_191 & V_528 ) ) {
T_6 V_529 ;
V_529 = V_191 & V_527 ?
V_2 -> V_529 : - 1 ;
V_13 = F_208 ( V_9 , V_529 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_191 & V_530 ) {
V_13 = F_209 ( V_9 , V_2 -> V_531 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_191 & V_532 ) {
if ( V_2 -> V_533 > V_534 )
return - V_48 ;
V_9 -> V_122 . V_60 . V_535 = V_2 -> V_533 ;
}
if ( V_191 & V_536 ) {
if ( V_2 -> V_537 > V_534 )
return - V_48 ;
V_9 -> V_122 . V_60 . V_538 = V_2 -> V_537 ;
}
if ( V_191 &
( V_532 | V_536 ) )
F_70 ( V_9 , V_539 ) ;
return 0 ;
}
static int F_210 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_540 type , int V_541 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
enum V_540 V_542 = type ;
bool V_543 = false ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_544 :
V_12 -> V_545 = V_546 ;
V_542 = V_547 ;
break;
case V_547 :
case V_548 :
if ( V_541 < 0 || ( V_541 % 100 ) )
return - V_340 ;
V_12 -> V_545 = F_211 ( V_541 ) ;
break;
}
if ( V_542 != V_12 -> V_26 . V_226 . V_549 ) {
V_543 = true ;
V_12 -> V_26 . V_226 . V_549 = V_542 ;
}
F_212 ( V_12 , V_543 ) ;
return 0 ;
}
switch ( type ) {
case V_544 :
V_9 -> V_545 = V_546 ;
V_542 = V_547 ;
break;
case V_547 :
case V_548 :
if ( V_541 < 0 || ( V_541 % 100 ) )
return - V_340 ;
V_9 -> V_545 = F_211 ( V_541 ) ;
break;
}
F_16 ( & V_9 -> V_163 ) ;
F_80 (sdata, &local->interfaces, list) {
V_12 -> V_545 = V_9 -> V_545 ;
if ( V_542 != V_12 -> V_26 . V_226 . V_549 )
V_543 = true ;
V_12 -> V_26 . V_226 . V_549 = V_542 ;
}
F_80 (sdata, &local->interfaces, list)
F_212 ( V_12 , V_543 ) ;
F_18 ( & V_9 -> V_163 ) ;
return 0 ;
}
static int F_213 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_550 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( V_9 -> V_493 -> V_551 )
return F_214 ( V_9 , V_12 , V_550 ) ;
if ( ! V_9 -> V_164 )
* V_550 = V_9 -> V_122 . V_60 . V_552 ;
else
* V_550 = V_12 -> V_26 . V_226 . V_553 ;
return 0 ;
}
static int F_215 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_154 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_554 . V_555 , V_154 , V_155 ) ;
return 0 ;
}
static void F_216 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_217 ( V_9 ) ;
}
static int F_218 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
void * V_181 , int V_180 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_556 * V_26 = NULL ;
if ( ! V_9 -> V_493 -> V_557 )
return - V_340 ;
if ( V_10 ) {
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_12 -> V_5 & V_558 )
V_26 = & V_12 -> V_26 ;
}
return V_9 -> V_493 -> V_557 ( & V_9 -> V_122 , V_26 , V_181 , V_180 ) ;
}
static int F_219 ( struct V_2 * V_2 ,
struct V_258 * V_259 ,
struct V_559 * V_267 ,
void * V_181 , int V_180 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_493 -> V_560 )
return - V_340 ;
return V_9 -> V_493 -> V_560 ( & V_9 -> V_122 , V_259 , V_267 , V_181 , V_180 ) ;
}
int F_220 ( struct V_11 * V_12 ,
enum V_561 V_211 )
{
struct V_37 * V_23 ;
enum V_561 V_562 ;
int V_563 ;
if ( F_34 ( V_12 -> V_26 . type != V_69 ) )
return - V_48 ;
if ( V_12 -> V_26 . V_226 . V_160 . V_564 == V_565 )
return 0 ;
V_562 = V_12 -> V_15 . V_177 . V_347 ;
V_12 -> V_15 . V_177 . V_347 = V_211 ;
if ( V_562 == V_211 ||
V_211 == V_566 )
return 0 ;
if ( ! F_221 ( & V_12 -> V_15 . V_177 . V_345 ) ) {
V_12 -> V_211 = V_211 ;
F_222 ( & V_12 -> V_9 -> V_122 , & V_12 -> V_567 ) ;
return 0 ;
}
F_139 ( V_12 ,
L_3 ,
V_211 , F_221 ( & V_12 -> V_15 . V_177 . V_345 ) ) ;
F_16 ( & V_12 -> V_9 -> V_62 ) ;
for ( V_563 = 0 ; V_563 < V_568 ; V_563 ++ ) {
for ( V_23 = F_66 ( V_12 -> V_9 -> V_569 [ V_563 ] ,
F_67 ( & V_12 -> V_9 -> V_62 ) ) ;
V_23 ;
V_23 = F_66 ( V_23 -> V_570 ,
F_67 ( & V_12 -> V_9 -> V_62 ) ) ) {
if ( V_23 -> V_12 -> V_344 != & V_12 -> V_15 . V_177 )
continue;
if ( F_138 ( V_23 ) == 1 )
continue;
if ( F_31 ( V_23 , V_571 ) &&
! F_223 ( V_23 -> V_346 ,
V_211 ) ) {
F_139 ( V_12 ,
L_4 ,
V_23 -> V_23 . V_154 ) ;
continue;
}
if ( ! F_31 ( V_23 , V_276 ) )
continue;
F_139 ( V_12 , L_5 , V_23 -> V_23 . V_154 ) ;
F_140 ( V_12 , V_211 ,
V_23 -> V_23 . V_154 ,
V_12 -> V_26 . V_226 . V_348 ) ;
}
}
F_18 ( & V_12 -> V_9 -> V_62 ) ;
V_12 -> V_211 = V_211 ;
F_222 ( & V_12 -> V_9 -> V_122 , & V_12 -> V_567 ) ;
return 0 ;
}
int F_224 ( struct V_11 * V_12 ,
enum V_561 V_211 )
{
const T_3 * V_177 ;
enum V_561 V_562 ;
int V_13 ;
F_225 ( & V_12 -> V_10 . V_162 ) ;
if ( F_34 ( V_12 -> V_26 . type != V_24 ) )
return - V_48 ;
V_562 = V_12 -> V_15 . V_25 . V_347 ;
V_12 -> V_15 . V_25 . V_347 = V_211 ;
if ( V_562 == V_211 &&
V_211 != V_566 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_572 ||
V_12 -> V_26 . V_226 . V_160 . V_564 == V_565 )
return 0 ;
V_177 = V_12 -> V_15 . V_25 . V_572 -> V_348 ;
if ( V_211 == V_566 ) {
if ( V_12 -> V_15 . V_25 . V_573 )
V_211 = V_217 ;
else
V_211 = V_213 ;
}
V_13 = F_140 ( V_12 , V_211 ,
V_177 , V_177 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_347 = V_562 ;
return V_13 ;
}
static int F_226 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_574 , int V_575 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_61 ( V_18 -> V_158 ) ;
if ( V_12 -> V_26 . type != V_24 )
return - V_340 ;
if ( ! ( V_9 -> V_122 . V_5 & V_576 ) )
return - V_340 ;
if ( V_574 == V_12 -> V_15 . V_25 . V_573 &&
V_575 == V_9 -> V_577 )
return 0 ;
V_12 -> V_15 . V_25 . V_573 = V_574 ;
V_9 -> V_577 = V_575 ;
F_227 ( V_12 ) ;
F_224 ( V_12 , V_12 -> V_15 . V_25 . V_347 ) ;
F_228 ( V_12 ) ;
if ( V_9 -> V_122 . V_5 & V_578 )
F_70 ( V_9 , V_579 ) ;
F_141 ( V_9 , - 1 ) ;
F_142 ( V_12 ) ;
return 0 ;
}
static int F_229 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_7 V_580 , T_1 V_581 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_556 * V_26 = & V_12 -> V_26 ;
struct V_582 * V_226 = & V_26 -> V_226 ;
if ( V_580 == V_226 -> V_583 &&
V_581 == V_226 -> V_584 )
return 0 ;
V_226 -> V_583 = V_580 ;
V_226 -> V_584 = V_581 ;
if ( V_12 -> V_15 . V_25 . V_572 &&
V_12 -> V_26 . V_585 & V_586 )
F_83 ( V_12 , V_587 ) ;
return 0 ;
}
static int F_230 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_154 ,
const struct V_588 * V_27 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_61 ( V_18 -> V_158 ) ;
int V_563 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_42 ;
if ( V_9 -> V_122 . V_5 & V_589 ) {
V_19 = F_231 ( V_9 , V_12 , V_27 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_563 = 0 ; V_563 < V_524 ; V_563 ++ ) {
struct V_118 * V_119 = V_2 -> V_123 [ V_563 ] ;
int V_590 ;
V_12 -> V_591 [ V_563 ] = V_27 -> V_264 [ V_563 ] . V_126 ;
memcpy ( V_12 -> V_592 [ V_563 ] , V_27 -> V_264 [ V_563 ] . V_593 ,
sizeof( V_27 -> V_264 [ V_563 ] . V_593 ) ) ;
V_12 -> V_594 [ V_563 ] = false ;
if ( ! V_119 )
continue;
for ( V_590 = 0 ; V_590 < V_595 ; V_590 ++ )
if ( ~ V_12 -> V_592 [ V_563 ] [ V_590 ] ) {
V_12 -> V_594 [ V_563 ] = true ;
break;
}
}
return 0 ;
}
static bool F_232 ( struct V_8 * V_9 ,
struct V_596 * V_597 ,
struct V_596 * V_598 )
{
unsigned long V_590 = V_371 ;
unsigned long V_599 = V_598 -> V_600 +
F_233 ( V_598 -> V_601 ) ;
struct V_596 * V_602 ;
int V_603 ;
if ( F_234 ( ! V_598 -> V_604 || ! V_598 -> V_605 ) )
return false ;
if ( F_235 ( V_590 + V_606 , V_599 ) )
return false ;
F_236 ( V_597 ) ;
V_603 = V_597 -> V_601 - F_153 ( V_599 - V_590 ) ;
if ( V_603 <= 0 ) {
F_237 ( & V_597 -> V_607 , & V_598 -> V_608 ) ;
return true ;
}
V_597 -> V_601 = V_603 ;
V_602 = F_238 ( V_598 -> V_607 . V_609 ,
struct V_596 , V_607 ) ;
if ( & V_602 -> V_607 != & V_9 -> V_610 &&
V_602 -> V_611 == V_597 -> V_611 &&
V_602 -> V_12 == V_597 -> V_12 &&
! F_234 ( V_602 -> V_604 ) ) {
F_237 ( & V_597 -> V_607 , & V_602 -> V_608 ) ;
V_602 -> V_601 = F_239 ( V_602 -> V_601 ,
V_597 -> V_601 ) ;
V_602 -> type = F_239 ( V_602 -> type , V_597 -> type ) ;
return true ;
}
F_240 ( & V_597 -> V_607 , & V_598 -> V_607 ) ;
return true ;
}
static int F_241 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_612 * V_613 ,
unsigned int V_601 , T_4 * V_88 ,
struct V_258 * V_614 ,
enum V_615 type )
{
struct V_596 * V_616 , * V_617 ;
bool V_618 = false ;
int V_19 ;
F_225 ( & V_9 -> V_162 ) ;
if ( V_9 -> V_164 && ! V_9 -> V_493 -> V_619 )
return - V_340 ;
V_616 = F_73 ( sizeof( * V_616 ) , V_178 ) ;
if ( ! V_616 )
return - V_179 ;
if ( ! V_601 )
V_601 = 10 ;
V_616 -> V_611 = V_613 ;
V_616 -> V_601 = V_601 ;
V_616 -> V_620 = V_601 ;
V_616 -> V_621 = V_614 ;
V_616 -> type = type ;
V_616 -> V_622 = ( unsigned long ) V_614 ;
V_616 -> V_12 = V_12 ;
F_242 ( & V_616 -> V_623 , V_624 ) ;
F_243 ( & V_616 -> V_608 ) ;
if ( ! V_614 ) {
V_9 -> V_625 ++ ;
V_616 -> V_88 = V_9 -> V_625 ;
if ( F_234 ( V_616 -> V_88 == 0 ) ) {
V_616 -> V_88 = 1 ;
V_9 -> V_625 ++ ;
}
* V_88 = V_616 -> V_88 ;
} else {
* V_88 = ( unsigned long ) V_614 ;
}
if ( ! F_244 ( & V_9 -> V_610 ) ||
V_9 -> V_626 || F_245 ( V_9 ) )
goto V_627;
if ( ! V_9 -> V_493 -> V_619 ) {
F_246 ( & V_9 -> V_122 , & V_616 -> V_623 , 0 ) ;
goto V_628;
}
V_19 = F_247 ( V_9 , V_12 , V_613 , V_601 , type ) ;
if ( V_19 ) {
F_89 ( V_616 ) ;
return V_19 ;
}
V_616 -> V_604 = true ;
goto V_628;
V_627:
F_80 (tmp, &local->roc_list, list) {
if ( V_617 -> V_611 != V_613 || V_617 -> V_12 != V_12 )
continue;
if ( ! V_617 -> V_604 ) {
F_237 ( & V_616 -> V_607 , & V_617 -> V_608 ) ;
V_617 -> V_601 = F_239 ( V_617 -> V_601 , V_616 -> V_601 ) ;
V_617 -> type = F_239 ( V_617 -> type , V_616 -> type ) ;
V_618 = true ;
break;
}
if ( V_9 -> V_493 -> V_619 ) {
if ( ! V_617 -> V_605 ) {
F_237 ( & V_616 -> V_607 , & V_617 -> V_608 ) ;
V_618 = true ;
break;
}
if ( F_232 ( V_9 , V_616 , V_617 ) )
V_618 = true ;
} else if ( F_248 ( & V_617 -> V_623 . V_629 ) ) {
unsigned long V_630 ;
F_237 ( & V_616 -> V_607 , & V_617 -> V_608 ) ;
V_618 = true ;
V_630 = V_371 + F_233 ( V_616 -> V_601 ) ;
if ( F_235 ( V_630 , V_617 -> V_623 . V_629 . V_631 ) )
F_249 ( & V_617 -> V_623 . V_629 , V_630 ) ;
else
F_250 ( & V_617 -> V_623 . V_629 ) ;
F_236 ( V_616 ) ;
}
break;
}
V_628:
if ( ! V_618 )
F_237 ( & V_616 -> V_607 , & V_9 -> V_610 ) ;
return 0 ;
}
static int F_251 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_612 * V_611 ,
unsigned int V_601 ,
T_4 * V_88 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_16 ( & V_9 -> V_162 ) ;
V_19 = F_241 ( V_9 , V_12 , V_611 ,
V_601 , V_88 , NULL ,
V_632 ) ;
F_18 ( & V_9 -> V_162 ) ;
return V_19 ;
}
static int F_252 ( struct V_8 * V_9 ,
T_4 V_88 , bool V_633 )
{
struct V_596 * V_616 , * V_617 , * V_634 = NULL ;
int V_19 ;
F_16 ( & V_9 -> V_162 ) ;
F_253 (roc, tmp, &local->roc_list, list) {
struct V_596 * V_635 , * V_636 ;
F_253 (dep, tmp2, &roc->dependents, list) {
if ( ! V_633 && V_635 -> V_88 != V_88 )
continue;
else if ( V_633 && V_635 -> V_622 != V_88 )
continue;
F_254 ( & V_635 -> V_607 ) ;
F_18 ( & V_9 -> V_162 ) ;
F_255 ( V_635 , true ) ;
return 0 ;
}
if ( ! V_633 && V_616 -> V_88 != V_88 )
continue;
else if ( V_633 && V_616 -> V_622 != V_88 )
continue;
V_634 = V_616 ;
break;
}
if ( ! V_634 ) {
F_18 ( & V_9 -> V_162 ) ;
return - V_64 ;
}
if ( V_9 -> V_493 -> V_619 ) {
if ( V_634 -> V_604 ) {
V_19 = F_256 ( V_9 ) ;
if ( F_34 ( V_19 ) ) {
F_18 ( & V_9 -> V_162 ) ;
return V_19 ;
}
}
F_254 ( & V_634 -> V_607 ) ;
if ( V_634 -> V_604 )
F_257 ( V_9 ) ;
F_18 ( & V_9 -> V_162 ) ;
F_255 ( V_634 , true ) ;
} else {
V_634 -> abort = true ;
F_246 ( & V_9 -> V_122 , & V_634 -> V_623 , 0 ) ;
F_18 ( & V_9 -> V_162 ) ;
F_258 ( & V_634 -> V_623 ) ;
F_234 ( ! V_634 -> V_637 ) ;
F_89 ( V_634 ) ;
}
return 0 ;
}
static int F_259 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_88 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_252 ( V_9 , V_88 , false ) ;
}
static int F_260 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_159 * V_160 ,
T_1 V_638 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 ;
F_16 ( & V_9 -> V_162 ) ;
if ( ! F_244 ( & V_9 -> V_610 ) || V_9 -> V_626 ) {
V_13 = - V_30 ;
goto V_65;
}
V_12 -> V_211 = V_213 ;
V_12 -> V_218 = V_9 -> V_219 ;
V_13 = F_69 ( V_12 , V_160 ,
V_220 ) ;
if ( V_13 )
goto V_65;
F_246 ( & V_12 -> V_9 -> V_122 ,
& V_12 -> V_251 ,
F_233 ( V_638 ) ) ;
V_65:
F_18 ( & V_9 -> V_162 ) ;
return V_13 ;
}
static struct V_186 *
F_261 ( struct V_186 * V_193 )
{
struct V_186 * V_639 ;
T_3 * V_640 ;
int V_180 ;
V_180 = V_193 -> V_195 + V_193 -> V_197 + V_193 -> V_641 +
V_193 -> V_642 + V_193 -> V_643 +
V_193 -> V_202 ;
V_639 = F_73 ( sizeof( * V_639 ) + V_180 , V_178 ) ;
if ( ! V_639 )
return NULL ;
V_640 = ( T_3 * ) ( V_639 + 1 ) ;
if ( V_193 -> V_195 ) {
V_639 -> V_195 = V_193 -> V_195 ;
V_639 -> V_194 = V_640 ;
memcpy ( V_640 , V_193 -> V_194 , V_193 -> V_195 ) ;
V_640 += V_193 -> V_195 ;
}
if ( V_193 -> V_197 ) {
V_639 -> V_197 = V_193 -> V_197 ;
V_639 -> V_196 = V_640 ;
memcpy ( V_640 , V_193 -> V_196 , V_193 -> V_197 ) ;
V_640 += V_193 -> V_197 ;
}
if ( V_193 -> V_641 ) {
V_639 -> V_641 = V_193 -> V_641 ;
V_639 -> V_644 = V_640 ;
memcpy ( V_640 , V_193 -> V_644 , V_193 -> V_641 ) ;
V_640 += V_193 -> V_641 ;
}
if ( V_193 -> V_642 ) {
V_639 -> V_642 = V_193 -> V_642 ;
V_639 -> V_645 = V_640 ;
memcpy ( V_640 , V_193 -> V_645 , V_193 -> V_642 ) ;
V_640 += V_193 -> V_642 ;
}
if ( V_193 -> V_643 ) {
V_639 -> V_643 = V_193 -> V_643 ;
V_639 -> V_646 = V_640 ;
memcpy ( V_640 , V_193 -> V_646 , V_193 -> V_643 ) ;
V_640 += V_193 -> V_643 ;
}
if ( V_193 -> V_202 ) {
V_639 -> V_202 = V_193 -> V_202 ;
V_193 -> V_174 = V_640 ;
memcpy ( V_640 , V_193 -> V_174 , V_193 -> V_202 ) ;
V_640 += V_193 -> V_202 ;
}
return V_639 ;
}
void F_262 ( struct V_556 * V_26 )
{
struct V_11 * V_12 = F_263 ( V_26 ) ;
F_222 ( & V_12 -> V_9 -> V_122 ,
& V_12 -> V_647 ) ;
}
static int F_264 ( struct V_11 * V_12 ,
T_1 * V_191 )
{
int V_13 ;
switch ( V_12 -> V_26 . type ) {
case V_69 :
V_13 = F_76 ( V_12 , V_12 -> V_15 . V_177 . V_246 ,
NULL ) ;
F_89 ( V_12 -> V_15 . V_177 . V_246 ) ;
V_12 -> V_15 . V_177 . V_246 = NULL ;
if ( V_13 < 0 )
return V_13 ;
* V_191 |= V_13 ;
break;
case V_71 :
V_13 = F_265 ( V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_191 |= V_13 ;
break;
#ifdef F_33
case V_72 :
V_13 = F_266 ( V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_191 |= V_13 ;
break;
#endif
default:
F_234 ( 1 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_267 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_1 V_191 = 0 ;
int V_13 ;
F_86 ( V_12 ) ;
F_225 ( & V_9 -> V_162 ) ;
F_225 ( & V_9 -> V_31 ) ;
if ( V_12 -> V_648 ) {
if ( V_12 -> V_649 )
return 0 ;
return F_268 ( V_12 ) ;
}
if ( ! F_65 ( & V_12 -> V_26 . V_226 . V_160 ,
& V_12 -> V_650 ) )
return - V_48 ;
V_12 -> V_26 . V_241 = false ;
V_13 = F_264 ( V_12 , & V_191 ) ;
if ( V_13 )
return V_13 ;
F_83 ( V_12 , V_191 ) ;
if ( V_12 -> V_244 ) {
F_88 ( V_9 , V_12 ,
V_245 ) ;
V_12 -> V_244 = false ;
}
V_13 = F_269 ( V_12 ) ;
if ( V_13 )
return V_13 ;
F_270 ( V_12 -> V_18 , & V_12 -> V_650 ) ;
return 0 ;
}
static void F_271 ( struct V_11 * V_12 )
{
if ( F_267 ( V_12 ) ) {
F_272 ( V_12 , L_6 ) ;
F_273 ( V_12 -> V_9 -> V_122 . V_2 , & V_12 -> V_10 ,
V_178 ) ;
}
}
void F_274 ( struct V_651 * V_623 )
{
struct V_11 * V_12 =
F_165 ( V_623 , struct V_11 ,
V_647 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
F_227 ( V_12 ) ;
F_16 ( & V_9 -> V_162 ) ;
F_16 ( & V_9 -> V_31 ) ;
if ( ! V_12 -> V_26 . V_241 )
goto V_652;
if ( ! F_12 ( V_12 ) )
goto V_652;
F_271 ( V_12 ) ;
V_652:
F_18 ( & V_9 -> V_31 ) ;
F_18 ( & V_9 -> V_162 ) ;
F_228 ( V_12 ) ;
}
static int F_275 ( struct V_11 * V_12 ,
struct V_653 * V_7 ,
T_1 * V_191 )
{
struct V_172 V_173 = {} ;
int V_13 ;
switch ( V_12 -> V_26 . type ) {
case V_69 :
V_12 -> V_15 . V_177 . V_246 =
F_261 ( & V_7 -> V_654 ) ;
if ( ! V_12 -> V_15 . V_177 . V_246 )
return - V_179 ;
if ( V_7 -> V_199 <= 1 )
break;
if ( ( V_7 -> V_201 >
V_655 ) ||
( V_7 -> V_184 >
V_655 ) )
return - V_48 ;
V_173 . V_200 = V_7 -> V_200 ;
V_173 . V_183 = V_7 -> V_183 ;
V_173 . V_201 = V_7 -> V_201 ;
V_173 . V_184 = V_7 -> V_184 ;
V_173 . V_199 = V_7 -> V_199 ;
V_13 = F_76 ( V_12 , & V_7 -> V_656 , & V_173 ) ;
if ( V_13 < 0 ) {
F_89 ( V_12 -> V_15 . V_177 . V_246 ) ;
return V_13 ;
}
* V_191 |= V_13 ;
break;
case V_71 :
if ( ! V_12 -> V_26 . V_226 . V_657 )
return - V_48 ;
if ( V_7 -> V_160 . V_564 != V_12 -> V_15 . V_658 . V_160 . V_564 )
return - V_48 ;
switch ( V_7 -> V_160 . V_564 ) {
case V_659 :
if ( F_276 ( & V_7 -> V_160 ) !=
F_276 ( & V_12 -> V_15 . V_658 . V_160 ) )
return - V_48 ;
case V_660 :
case V_661 :
case V_565 :
case V_662 :
break;
default:
return - V_48 ;
}
if ( V_12 -> V_15 . V_658 . V_160 . V_611 -> V_280 !=
V_7 -> V_160 . V_611 -> V_280 )
return - V_48 ;
if ( V_7 -> V_199 > 1 ) {
V_13 = F_277 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_191 |= V_13 ;
}
F_278 ( V_12 , V_7 ) ;
break;
#ifdef F_33
case V_72 : {
struct V_391 * V_392 = & V_12 -> V_15 . V_73 ;
if ( V_7 -> V_160 . V_564 != V_12 -> V_26 . V_226 . V_160 . V_564 )
return - V_48 ;
if ( V_12 -> V_26 . V_226 . V_160 . V_611 -> V_280 !=
V_7 -> V_160 . V_611 -> V_280 )
return - V_48 ;
if ( V_392 -> V_663 == V_664 ) {
V_392 -> V_663 = V_665 ;
if ( ! V_392 -> V_666 )
V_392 -> V_666 = 1 ;
else
V_392 -> V_666 ++ ;
}
if ( V_7 -> V_199 > 1 ) {
V_13 = F_279 ( V_12 , V_7 ) ;
if ( V_13 < 0 ) {
V_392 -> V_663 = V_664 ;
return V_13 ;
}
* V_191 |= V_13 ;
}
if ( V_392 -> V_663 == V_665 )
F_278 ( V_12 , V_7 ) ;
break;
}
#endif
default:
return - V_340 ;
}
return 0 ;
}
static int
F_280 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_653 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_667 V_668 ;
struct V_669 * V_60 ;
struct V_670 * V_671 ;
T_1 V_191 = 0 ;
int V_13 ;
F_86 ( V_12 ) ;
F_225 ( & V_9 -> V_162 ) ;
if ( ! F_244 ( & V_9 -> V_610 ) || V_9 -> V_626 )
return - V_30 ;
if ( V_12 -> V_10 . V_250 )
return - V_30 ;
if ( F_65 ( & V_7 -> V_160 ,
& V_12 -> V_26 . V_226 . V_160 ) )
return - V_48 ;
if ( V_12 -> V_26 . V_241 )
return - V_30 ;
F_16 ( & V_9 -> V_31 ) ;
V_60 = F_66 ( V_12 -> V_26 . V_672 ,
F_67 ( & V_9 -> V_31 ) ) ;
if ( ! V_60 ) {
V_13 = - V_30 ;
goto V_92;
}
V_671 = F_165 ( V_60 , struct V_670 , V_60 ) ;
if ( ! V_671 ) {
V_13 = - V_30 ;
goto V_92;
}
V_668 . V_673 = 0 ;
V_668 . V_674 = 0 ;
V_668 . V_675 = V_7 -> V_675 ;
V_668 . V_160 = V_7 -> V_160 ;
V_668 . V_199 = V_7 -> V_199 ;
V_13 = F_281 ( V_12 , & V_668 ) ;
if ( V_13 )
goto V_92;
V_13 = F_282 ( V_12 , & V_7 -> V_160 ,
V_671 -> V_676 ,
V_7 -> V_677 ) ;
if ( V_13 )
goto V_92;
V_13 = F_17 ( V_12 , NULL , V_671 -> V_676 , 0 ) ;
if ( V_13 ) {
F_283 ( V_12 ) ;
goto V_92;
}
V_13 = F_275 ( V_12 , V_7 , & V_191 ) ;
if ( V_13 ) {
F_283 ( V_12 ) ;
goto V_92;
}
V_12 -> V_650 = V_7 -> V_160 ;
V_12 -> V_244 = V_7 -> V_675 ;
V_12 -> V_26 . V_241 = true ;
if ( V_12 -> V_244 )
F_284 ( V_9 , V_12 ,
V_245 ) ;
F_285 ( V_12 -> V_18 , & V_12 -> V_650 ,
V_7 -> V_199 ) ;
if ( V_191 ) {
F_83 ( V_12 , V_191 ) ;
F_286 ( V_12 , & V_7 -> V_160 ) ;
} else {
F_271 ( V_12 ) ;
}
V_92:
F_18 ( & V_9 -> V_31 ) ;
return V_13 ;
}
int V_667 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_653 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 ;
F_16 ( & V_9 -> V_162 ) ;
V_13 = F_280 ( V_2 , V_18 , V_7 ) ;
F_18 ( & V_9 -> V_162 ) ;
return V_13 ;
}
static int F_287 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_678 * V_7 ,
T_4 * V_88 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_258 * V_259 ;
struct V_37 * V_23 ;
const struct V_679 * V_680 = ( void * ) V_7 -> V_681 ;
bool V_682 = false ;
T_1 V_5 ;
int V_19 ;
T_3 * V_181 ;
if ( V_7 -> V_683 )
V_5 = V_684 ;
else
V_5 = V_685 |
V_686 ;
if ( V_7 -> V_687 )
V_5 |= V_688 ;
switch ( V_12 -> V_26 . type ) {
case V_71 :
if ( ! V_12 -> V_26 . V_226 . V_657 )
V_682 = true ;
#ifdef F_33
case V_72 :
if ( F_28 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_73 . V_399 )
V_682 = true ;
#endif
case V_69 :
case V_20 :
case V_81 :
if ( V_12 -> V_26 . type != V_71 &&
! F_28 ( & V_12 -> V_26 ) &&
! F_288 ( V_12 -> V_344 -> V_193 ) )
V_682 = true ;
if ( ! F_289 ( V_680 -> V_689 ) ||
V_680 -> V_15 . V_690 . V_691 == V_692 ||
V_680 -> V_15 . V_690 . V_691 == V_693 ||
V_680 -> V_15 . V_690 . V_691 == V_694 )
break;
F_41 () ;
V_23 = F_29 ( V_12 , V_680 -> V_260 ) ;
F_45 () ;
if ( ! V_23 )
return - V_695 ;
break;
case V_24 :
case V_80 :
if ( ! V_12 -> V_15 . V_25 . V_572 )
V_682 = true ;
break;
case V_77 :
V_682 = true ;
break;
default:
return - V_340 ;
}
if ( V_682 && ! V_7 -> V_611 )
return - V_48 ;
F_16 ( & V_9 -> V_162 ) ;
if ( ! V_682 ) {
struct V_669 * V_672 ;
F_41 () ;
V_672 = F_42 ( V_12 -> V_26 . V_672 ) ;
if ( V_672 ) {
V_682 = V_7 -> V_611 &&
( V_7 -> V_611 !=
V_672 -> V_696 . V_611 ) ;
} else if ( ! V_7 -> V_611 ) {
V_19 = - V_48 ;
F_45 () ;
goto V_65;
} else {
V_682 = true ;
}
F_45 () ;
}
if ( V_682 && ! V_7 -> V_697 ) {
V_19 = - V_30 ;
goto V_65;
}
V_259 = F_100 ( V_9 -> V_122 . V_698 + V_7 -> V_180 ) ;
if ( ! V_259 ) {
V_19 = - V_179 ;
goto V_65;
}
F_290 ( V_259 , V_9 -> V_122 . V_698 ) ;
V_181 = F_101 ( V_259 , V_7 -> V_180 ) ;
memcpy ( V_181 , V_7 -> V_681 , V_7 -> V_180 ) ;
if ( V_12 -> V_26 . V_241 &&
( V_12 -> V_26 . type == V_69 ||
V_12 -> V_26 . type == V_71 ) &&
V_7 -> V_699 ) {
int V_563 ;
struct V_187 * V_193 = NULL ;
F_41 () ;
if ( V_12 -> V_26 . type == V_69 )
V_193 = F_42 ( V_12 -> V_15 . V_177 . V_193 ) ;
else if ( V_12 -> V_26 . type == V_71 )
V_193 = F_42 ( V_12 -> V_15 . V_658 . V_700 ) ;
else if ( F_28 ( & V_12 -> V_26 ) )
V_193 = F_42 ( V_12 -> V_15 . V_73 . V_193 ) ;
if ( V_193 )
for ( V_563 = 0 ; V_563 < V_7 -> V_699 ; V_563 ++ )
V_181 [ V_7 -> V_701 [ V_563 ] ] =
V_193 -> V_198 ;
F_45 () ;
}
F_291 ( V_259 ) -> V_5 = V_5 ;
V_259 -> V_18 = V_12 -> V_18 ;
if ( ! V_682 ) {
* V_88 = ( unsigned long ) V_259 ;
F_292 ( V_12 , V_259 ) ;
V_19 = 0 ;
goto V_65;
}
F_291 ( V_259 ) -> V_5 |= V_702 |
V_703 ;
if ( V_9 -> V_122 . V_5 & V_704 )
F_291 ( V_259 ) -> V_705 =
V_9 -> V_122 . V_706 ;
V_19 = F_241 ( V_9 , V_12 , V_7 -> V_611 ,
V_7 -> V_707 , V_88 , V_259 ,
V_708 ) ;
if ( V_19 )
F_293 ( V_259 ) ;
V_65:
F_18 ( & V_9 -> V_162 ) ;
return V_19 ;
}
static int F_294 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_88 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_252 ( V_9 , V_88 , true ) ;
}
static void F_295 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_709 , bool V_710 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_709 ) {
case V_711 | V_712 :
if ( V_710 )
V_9 -> V_713 ++ ;
else
V_9 -> V_713 -- ;
if ( ! V_9 -> V_167 )
break;
F_222 ( & V_9 -> V_122 , & V_9 -> V_714 ) ;
break;
default:
break;
}
}
static int F_296 ( struct V_2 * V_2 , T_1 V_715 , T_1 V_716 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_604 )
return - V_340 ;
return F_297 ( V_9 , V_715 , V_716 ) ;
}
static int F_298 ( struct V_2 * V_2 , T_1 * V_715 , T_1 * V_716 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_299 ( V_9 , V_715 , V_716 ) ;
}
static int F_300 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_717 * V_181 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_493 -> V_718 )
return - V_340 ;
F_301 ( V_9 , V_12 , V_181 ) ;
return 0 ;
}
static int F_302 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_719 , T_4 * V_88 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_720 * V_721 ;
struct V_258 * V_259 ;
int V_190 = sizeof( * V_721 ) ;
T_8 V_722 ;
bool V_723 ;
struct V_724 * V_725 ;
struct V_37 * V_23 ;
struct V_669 * V_672 ;
enum V_279 V_280 ;
F_41 () ;
V_672 = F_42 ( V_12 -> V_26 . V_672 ) ;
if ( F_234 ( ! V_672 ) ) {
F_45 () ;
return - V_48 ;
}
V_280 = V_672 -> V_696 . V_611 -> V_280 ;
V_23 = F_30 ( V_12 , V_719 ) ;
if ( V_23 ) {
V_723 = V_23 -> V_23 . V_287 ;
} else {
F_45 () ;
return - V_695 ;
}
if ( V_723 ) {
V_722 = F_303 ( V_726 |
V_727 |
V_728 ) ;
} else {
V_190 -= 2 ;
V_722 = F_303 ( V_726 |
V_729 |
V_728 ) ;
}
V_259 = F_100 ( V_9 -> V_122 . V_698 + V_190 ) ;
if ( ! V_259 ) {
F_45 () ;
return - V_179 ;
}
V_259 -> V_18 = V_18 ;
F_290 ( V_259 , V_9 -> V_122 . V_698 ) ;
V_721 = ( void * ) F_101 ( V_259 , V_190 ) ;
V_721 -> V_689 = V_722 ;
V_721 -> V_730 = 0 ;
memcpy ( V_721 -> V_731 , V_23 -> V_23 . V_154 , V_155 ) ;
memcpy ( V_721 -> V_732 , V_12 -> V_26 . V_154 , V_155 ) ;
memcpy ( V_721 -> V_733 , V_12 -> V_26 . V_154 , V_155 ) ;
V_721 -> V_734 = 0 ;
V_725 = F_291 ( V_259 ) ;
V_725 -> V_5 |= V_686 |
V_685 ;
V_725 -> V_280 = V_280 ;
F_304 ( V_259 , V_735 ) ;
V_259 -> V_736 = 7 ;
if ( V_723 )
V_721 -> V_737 = F_303 ( 7 ) ;
F_305 () ;
F_306 ( V_12 , V_259 ) ;
F_307 () ;
F_45 () ;
* V_88 = ( unsigned long ) V_259 ;
return 0 ;
}
static int F_308 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_159 * V_160 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_669 * V_672 ;
int V_19 = - V_738 ;
F_41 () ;
V_672 = F_42 ( V_12 -> V_26 . V_672 ) ;
if ( V_672 ) {
* V_160 = V_12 -> V_26 . V_226 . V_160 ;
V_19 = 0 ;
} else if ( V_9 -> V_167 > 0 &&
V_9 -> V_167 == V_9 -> V_168 &&
V_12 -> V_26 . type == V_14 ) {
if ( V_9 -> V_164 )
* V_160 = V_9 -> V_161 ;
else
* V_160 = V_9 -> V_169 ;
V_19 = 0 ;
}
F_45 () ;
return V_19 ;
}
static void F_309 ( struct V_2 * V_2 , bool V_574 )
{
F_310 ( F_2 ( V_2 ) , V_574 ) ;
}
static int F_311 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_739 * V_740 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_741 * V_742 , * V_743 ;
if ( V_740 ) {
V_742 = F_73 ( sizeof( * V_742 ) , V_178 ) ;
if ( ! V_742 )
return - V_179 ;
memcpy ( & V_742 -> V_740 , V_740 , sizeof( * V_740 ) ) ;
} else {
V_742 = NULL ;
}
V_743 = F_72 ( V_12 -> V_740 , V_12 ) ;
F_74 ( V_12 -> V_740 , V_742 ) ;
if ( V_743 )
F_75 ( V_743 , V_185 ) ;
return 0 ;
}
static int F_312 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_159 * V_160 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_19 ;
T_1 V_191 = 0 ;
V_19 = F_313 ( V_12 , V_160 , & V_191 ) ;
if ( V_19 == 0 )
F_83 ( V_12 , V_191 ) ;
return V_19 ;
}
static int F_314 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_744 , const T_3 * V_719 , T_3 V_745 ,
T_2 V_746 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_747 * V_748 = & V_12 -> V_15 . V_25 ;
int V_505 = V_749 [ V_745 ] ;
if ( V_12 -> V_26 . type != V_24 )
return - V_340 ;
if ( ! ( V_12 -> V_750 & F_107 ( V_745 ) ) )
return - V_48 ;
if ( V_748 -> V_751 [ V_505 ] . V_746 )
return - V_30 ;
if ( V_746 ) {
V_748 -> V_751 [ V_505 ] . V_746 = 32 * V_746 ;
V_748 -> V_751 [ V_505 ] . V_744 = V_744 ;
V_748 -> V_751 [ V_505 ] . V_745 = V_745 ;
}
return 0 ;
}
static int F_315 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_744 , const T_3 * V_719 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_747 * V_748 = & V_12 -> V_15 . V_25 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_505 ;
for ( V_505 = 0 ; V_505 < V_496 ; V_505 ++ ) {
struct V_752 * V_751 = & V_748 -> V_751 [ V_505 ] ;
if ( ! V_751 -> V_746 )
continue;
if ( V_751 -> V_744 != V_744 )
continue;
V_751 -> V_745 = - 1 ;
F_316 () ;
F_317 ( V_9 , V_12 , false ) ;
V_751 -> V_690 = V_753 ;
V_751 -> V_754 = false ;
F_318 ( V_12 ) ;
memset ( V_751 , 0 , sizeof( * V_751 ) ) ;
return 0 ;
}
return - V_64 ;
}
