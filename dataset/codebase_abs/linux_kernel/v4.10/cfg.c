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
V_13 -> V_16 . V_17 . V_6 = * V_6 ;
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
V_8 && V_8 -> V_22 == 0 ) {
F_11 ( V_13 -> V_16 . V_23 . V_24 , NULL ) ;
F_12 ( V_13 ) ;
} else if ( type == V_25 &&
V_8 && V_8 -> V_22 >= 0 ) {
V_13 -> V_16 . V_26 . V_22 = V_8 -> V_22 ;
}
if ( V_13 -> V_27 . type == V_15 ) {
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_12 * V_28 ;
T_1 V_29 = V_30 ;
V_28 = F_13 ( V_10 -> V_28 ) ;
if ( V_28 &&
F_14 ( V_2 , V_29 ) ) {
memcpy ( V_28 -> V_27 . V_31 . V_32 . V_33 ,
V_8 -> V_34 , V_35 ) ;
memcpy ( V_28 -> V_27 . V_31 . V_32 . V_36 ,
V_8 -> V_34 + V_35 ,
V_37 ) ;
V_28 -> V_27 . V_38 = true ;
F_15 ( V_28 ,
V_39 ) ;
F_16 ( V_28 -> V_16 . V_17 . V_40 ,
V_8 -> V_41 ) ;
}
if ( ! V_6 )
return 0 ;
if ( F_17 ( V_13 ) ) {
T_1 V_42 = V_43 |
V_44 ;
if ( ( * V_6 & V_42 ) != ( V_13 -> V_16 . V_17 . V_6 & V_42 ) )
return - V_45 ;
F_18 ( V_13 , - 1 ) ;
V_13 -> V_16 . V_17 . V_6 = * V_6 ;
F_18 ( V_13 , 1 ) ;
F_19 ( V_10 ) ;
} else {
V_13 -> V_16 . V_17 . V_6 = * V_6 ;
}
}
return 0 ;
}
static int F_20 ( struct V_2 * V_2 ,
struct V_1 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_20 ;
F_21 ( & V_13 -> V_10 -> V_46 ) ;
V_20 = F_22 ( V_13 , NULL , 0 , 0 ) ;
F_23 ( & V_13 -> V_10 -> V_46 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_24 ( V_11 , true ) ;
}
static void F_25 ( struct V_2 * V_2 ,
struct V_1 * V_11 )
{
F_26 ( F_5 ( V_11 ) ) ;
}
static int F_27 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_47 * V_48 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_20 ;
F_21 ( & V_13 -> V_10 -> V_46 ) ;
V_20 = F_22 ( V_13 , NULL , 0 , 0 ) ;
F_23 ( & V_13 -> V_10 -> V_46 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_24 ( V_11 , true ) ;
if ( V_20 )
return V_20 ;
V_20 = F_28 ( V_13 -> V_10 , V_13 , V_48 ) ;
if ( V_20 )
F_26 ( V_13 ) ;
V_13 -> V_16 . V_49 . V_48 = * V_48 ;
return V_20 ;
}
static void F_29 ( struct V_2 * V_2 ,
struct V_1 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_30 ( V_13 -> V_10 , V_13 ) ;
F_26 ( V_13 ) ;
}
static int F_31 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_47 * V_48 ,
T_1 V_50 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_47 V_51 ;
int V_20 = 0 ;
if ( V_13 -> V_27 . type != V_52 )
return - V_53 ;
if ( ! F_17 ( V_13 ) )
return - V_54 ;
V_51 = V_13 -> V_16 . V_49 . V_48 ;
if ( V_50 & V_55 )
V_51 . V_56 = V_48 -> V_56 ;
if ( V_50 & V_57 )
V_51 . V_58 = V_48 -> V_58 ;
V_20 = F_32 ( V_13 -> V_10 , V_13 , & V_51 , V_50 ) ;
if ( ! V_20 )
V_13 -> V_16 . V_49 . V_48 = V_51 ;
return V_20 ;
}
static int F_33 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_59 * V_60 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_20 ;
if ( V_13 -> V_27 . type != V_52 )
return - V_53 ;
if ( ! F_17 ( V_13 ) )
return - V_54 ;
F_34 ( & V_13 -> V_16 . V_49 . V_61 ) ;
V_20 = F_35 ( & V_13 -> V_16 . V_49 . V_62 ,
V_60 , 1 , V_13 -> V_10 -> V_63 . V_64 + 1 ,
V_65 ) ;
F_36 ( & V_13 -> V_16 . V_49 . V_61 ) ;
if ( V_20 < 0 )
return V_20 ;
V_60 -> V_66 = V_20 ;
F_37 ( V_60 -> V_66 == 0 ) ;
V_20 = F_38 ( V_13 -> V_10 , V_13 , V_60 ) ;
if ( V_20 ) {
F_34 ( & V_13 -> V_16 . V_49 . V_61 ) ;
F_39 ( & V_13 -> V_16 . V_49 . V_62 ,
V_60 -> V_66 ) ;
F_36 ( & V_13 -> V_16 . V_49 . V_61 ) ;
}
return V_20 ;
}
static struct V_59 *
F_40 ( struct V_12 * V_13 ,
T_2 V_67 )
{
struct V_59 * V_68 ;
int V_69 ;
F_41 ( & V_13 -> V_16 . V_49 . V_61 ) ;
F_42 (&sdata->u.nan.function_inst_ids, func, id) {
if ( V_68 -> V_67 == V_67 )
return V_68 ;
}
return NULL ;
}
static void F_43 ( struct V_2 * V_2 ,
struct V_1 * V_11 , T_2 V_67 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_59 * V_68 ;
T_3 V_66 = 0 ;
if ( V_13 -> V_27 . type != V_52 ||
! F_17 ( V_13 ) )
return;
F_34 ( & V_13 -> V_16 . V_49 . V_61 ) ;
V_68 = F_40 ( V_13 , V_67 ) ;
if ( V_68 )
V_66 = V_68 -> V_66 ;
F_36 ( & V_13 -> V_16 . V_49 . V_61 ) ;
if ( V_66 )
F_44 ( V_13 -> V_10 , V_13 , V_66 ) ;
}
static int F_45 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_4 V_70 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
V_13 -> V_70 = V_70 ;
F_46 ( V_13 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_71 , bool V_72 , const T_3 * V_73 ,
struct V_74 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_75 * V_24 = NULL ;
const struct V_76 * V_77 = NULL ;
struct V_78 * V_79 ;
int V_14 ;
if ( ! F_17 ( V_13 ) )
return - V_54 ;
switch ( V_8 -> V_80 ) {
case V_81 :
case V_82 :
case V_83 :
if ( F_48 ( V_10 -> V_84 ) )
return - V_85 ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
break;
default:
V_77 = F_49 ( V_10 , V_8 -> V_80 , V_13 -> V_27 . type ) ;
break;
}
V_79 = F_50 ( V_8 -> V_80 , V_71 , V_8 -> V_94 ,
V_8 -> V_79 , V_8 -> V_95 , V_8 -> V_96 ,
V_77 ) ;
if ( F_48 ( V_79 ) )
return F_51 ( V_79 ) ;
if ( V_72 )
V_79 -> V_48 . V_6 |= V_97 ;
F_21 ( & V_10 -> V_98 ) ;
if ( V_73 ) {
V_24 = F_52 ( V_13 , V_73 ) ;
if ( ! V_24 || ! F_53 ( V_24 , V_99 ) ) {
F_54 ( V_79 ) ;
V_14 = - V_100 ;
goto V_101;
}
}
switch ( V_13 -> V_27 . type ) {
case V_25 :
if ( V_13 -> V_16 . V_26 . V_102 != V_103 )
V_79 -> V_48 . V_6 |= V_104 ;
break;
case V_105 :
case V_21 :
if ( V_79 -> V_24 && F_53 ( V_79 -> V_24 , V_106 ) )
V_79 -> V_48 . V_6 |= V_104 ;
break;
case V_107 :
break;
case V_108 :
#ifdef F_55
if ( V_13 -> V_16 . V_109 . V_110 != V_111 )
V_79 -> V_48 . V_6 |= V_104 ;
break;
#endif
case V_112 :
case V_15 :
case V_113 :
case V_52 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
F_56 ( 1 ) ;
break;
}
if ( V_24 )
V_24 -> V_119 = V_77 ;
V_14 = F_57 ( V_79 , V_13 , V_24 ) ;
V_101:
F_23 ( & V_10 -> V_98 ) ;
return V_14 ;
}
static int F_58 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_71 , bool V_72 , const T_3 * V_73 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_75 * V_24 ;
struct V_78 * V_79 = NULL ;
int V_20 ;
F_21 ( & V_10 -> V_98 ) ;
F_21 ( & V_10 -> V_120 ) ;
if ( V_73 ) {
V_20 = - V_100 ;
V_24 = F_52 ( V_13 , V_73 ) ;
if ( ! V_24 )
goto V_101;
if ( V_72 )
V_79 = F_59 ( V_10 , V_24 -> V_121 [ V_71 ] ) ;
else
V_79 = F_59 ( V_10 , V_24 -> V_122 [ V_71 ] ) ;
} else
V_79 = F_59 ( V_10 , V_13 -> V_123 [ V_71 ] ) ;
if ( ! V_79 ) {
V_20 = - V_100 ;
goto V_101;
}
F_60 ( V_79 , true ) ;
V_20 = 0 ;
V_101:
F_23 ( & V_10 -> V_120 ) ;
F_23 ( & V_10 -> V_98 ) ;
return V_20 ;
}
static int F_61 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_71 , bool V_72 , const T_3 * V_73 ,
void * V_67 ,
void (* F_62)( void * V_67 ,
struct V_74 * V_8 ) )
{
struct V_12 * V_13 ;
struct V_75 * V_24 = NULL ;
T_3 V_96 [ 6 ] = { 0 } ;
struct V_74 V_8 ;
struct V_78 * V_79 = NULL ;
T_2 V_124 ;
T_1 V_125 ;
T_4 V_126 ;
int V_14 = - V_100 ;
struct V_127 V_128 = {} ;
V_13 = F_9 ( V_19 ) ;
F_63 () ;
if ( V_73 ) {
V_24 = F_52 ( V_13 , V_73 ) ;
if ( ! V_24 )
goto V_129;
if ( V_72 && V_71 < V_130 )
V_79 = F_64 ( V_24 -> V_121 [ V_71 ] ) ;
else if ( ! V_72 &&
V_71 < V_130 + V_131 )
V_79 = F_64 ( V_24 -> V_122 [ V_71 ] ) ;
} else
V_79 = F_64 ( V_13 -> V_123 [ V_71 ] ) ;
if ( ! V_79 )
goto V_129;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_80 = V_79 -> V_48 . V_80 ;
switch ( V_79 -> V_48 . V_80 ) {
case V_82 :
V_124 = F_65 ( & V_79 -> V_48 . V_132 ) ;
V_125 = F_66 ( V_124 ) ;
V_126 = F_67 ( V_124 ) ;
if ( V_79 -> V_6 & V_133 &&
! ( V_79 -> V_48 . V_6 & V_134 ) ) {
F_68 ( V_13 -> V_10 , V_79 , & V_128 ) ;
V_125 = V_128 . V_135 . V_125 ;
V_126 = V_128 . V_135 . V_126 ;
}
V_96 [ 0 ] = V_126 & 0xff ;
V_96 [ 1 ] = ( V_126 >> 8 ) & 0xff ;
V_96 [ 2 ] = V_125 & 0xff ;
V_96 [ 3 ] = ( V_125 >> 8 ) & 0xff ;
V_96 [ 4 ] = ( V_125 >> 16 ) & 0xff ;
V_96 [ 5 ] = ( V_125 >> 24 ) & 0xff ;
V_8 . V_96 = V_96 ;
V_8 . V_95 = 6 ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
F_69 ( F_70 ( F_71 ( V_128 ) , V_136 ) !=
F_70 ( F_71 ( V_128 ) , V_137 ) ) ;
case V_90 :
case V_91 :
F_69 ( F_70 ( F_71 ( V_128 ) , V_136 ) !=
F_70 ( F_71 ( V_128 ) , V_138 ) ) ;
case V_92 :
case V_93 :
F_69 ( F_70 ( F_71 ( V_128 ) , V_136 ) !=
F_70 ( F_71 ( V_128 ) , V_139 ) ) ;
if ( V_79 -> V_6 & V_133 &&
! ( V_79 -> V_48 . V_6 & V_134 ) ) {
F_68 ( V_13 -> V_10 , V_79 , & V_128 ) ;
memcpy ( V_96 , V_128 . V_136 . V_140 , 6 ) ;
} else {
V_124 = F_65 ( & V_79 -> V_48 . V_132 ) ;
V_96 [ 0 ] = V_124 ;
V_96 [ 1 ] = V_124 >> 8 ;
V_96 [ 2 ] = V_124 >> 16 ;
V_96 [ 3 ] = V_124 >> 24 ;
V_96 [ 4 ] = V_124 >> 32 ;
V_96 [ 5 ] = V_124 >> 40 ;
}
V_8 . V_96 = V_96 ;
V_8 . V_95 = 6 ;
break;
default:
if ( ! ( V_79 -> V_6 & V_133 ) )
break;
if ( F_37 ( V_79 -> V_48 . V_6 & V_134 ) )
break;
F_68 ( V_13 -> V_10 , V_79 , & V_128 ) ;
V_8 . V_96 = V_128 . V_63 . V_96 ;
V_8 . V_95 = V_128 . V_63 . V_95 ;
break;
}
V_8 . V_79 = V_79 -> V_48 . V_79 ;
V_8 . V_94 = V_79 -> V_48 . V_141 ;
F_62 ( V_67 , & V_8 ) ;
V_14 = 0 ;
V_129:
F_72 () ;
return V_14 ;
}
static int F_73 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_3 V_71 , bool V_142 ,
bool V_143 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_74 ( V_13 , V_71 , V_142 , V_143 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_3 V_71 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_76 ( V_13 , V_71 ) ;
return 0 ;
}
void F_77 ( struct V_75 * V_24 ,
const struct V_144 * V_145 ,
struct V_146 * V_147 )
{
V_147 -> V_6 = 0 ;
if ( V_145 -> V_6 & V_148 ) {
V_147 -> V_6 |= V_149 ;
V_147 -> V_150 = V_145 -> V_151 ;
} else if ( V_145 -> V_6 & V_152 ) {
V_147 -> V_6 |= V_153 ;
V_147 -> V_150 = F_78 ( V_145 ) ;
V_147 -> V_154 = F_79 ( V_145 ) ;
} else {
struct V_155 * V_156 ;
int V_157 = F_80 ( & V_24 -> V_13 -> V_27 ) ;
T_4 V_158 ;
V_156 = V_24 -> V_10 -> V_63 . V_2 -> V_159 [
F_81 ( V_24 -> V_13 ) ] ;
V_158 = V_156 -> V_160 [ V_145 -> V_151 ] . V_161 ;
V_147 -> V_162 = F_82 ( V_158 , 1 << V_157 ) ;
}
if ( V_145 -> V_6 & V_163 )
V_147 -> V_164 = V_165 ;
else if ( V_145 -> V_6 & V_166 )
V_147 -> V_164 = V_167 ;
else if ( V_145 -> V_6 & V_168 )
V_147 -> V_164 = V_169 ;
else
V_147 -> V_164 = V_170 ;
if ( V_145 -> V_6 & V_171 )
V_147 -> V_6 |= V_172 ;
}
static int F_83 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_151 , T_3 * V_173 , struct V_174 * V_175 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_75 * V_24 ;
int V_20 = - V_100 ;
F_21 ( & V_10 -> V_98 ) ;
V_24 = F_84 ( V_13 , V_151 ) ;
if ( V_24 ) {
V_20 = 0 ;
memcpy ( V_173 , V_24 -> V_24 . V_176 , V_177 ) ;
F_85 ( V_24 , V_175 ) ;
}
F_23 ( & V_10 -> V_98 ) ;
return V_20 ;
}
static int F_86 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_151 , struct V_178 * V_179 )
{
struct V_9 * V_10 = F_87 ( V_19 -> V_180 ) ;
return F_88 ( V_10 , V_151 , V_179 ) ;
}
static int F_89 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_173 , struct V_174 * V_175 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_75 * V_24 ;
int V_20 = - V_100 ;
F_21 ( & V_10 -> V_98 ) ;
V_24 = F_52 ( V_13 , V_173 ) ;
if ( V_24 ) {
V_20 = 0 ;
F_85 ( V_24 , V_175 ) ;
}
F_23 ( & V_10 -> V_98 ) ;
return V_20 ;
}
static int F_90 ( struct V_2 * V_2 ,
struct V_181 * V_182 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
int V_20 = 0 ;
if ( F_91 ( & V_10 -> V_183 , V_182 ) )
return 0 ;
F_21 ( & V_10 -> V_184 ) ;
F_21 ( & V_10 -> V_185 ) ;
if ( V_10 -> V_186 ) {
V_13 = F_92 (
V_10 -> V_28 ,
F_93 ( & V_10 -> V_185 ) ) ;
if ( V_13 ) {
F_94 ( V_13 ) ;
V_20 = F_95 ( V_13 , V_182 ,
V_187 ) ;
}
} else if ( V_10 -> V_188 == V_10 -> V_189 ) {
V_10 -> V_190 = * V_182 ;
F_96 ( V_10 , 0 ) ;
}
if ( V_20 == 0 )
V_10 -> V_183 = * V_182 ;
F_23 ( & V_10 -> V_185 ) ;
F_23 ( & V_10 -> V_184 ) ;
return V_20 ;
}
static int F_97 ( struct V_12 * V_13 ,
const T_3 * V_191 , T_5 V_192 ,
const struct V_193 * V_194 )
{
struct V_195 * V_196 , * V_197 ;
if ( ! V_191 || ! V_192 )
return 1 ;
V_197 = F_98 ( V_13 -> V_16 . V_198 . V_195 , V_13 ) ;
V_196 = F_99 ( sizeof( struct V_195 ) + V_192 , V_199 ) ;
if ( ! V_196 )
return - V_200 ;
V_196 -> V_201 = V_192 ;
memcpy ( V_196 -> V_202 , V_191 , V_192 ) ;
if ( V_194 )
memcpy ( V_196 -> V_203 , V_194 -> V_204 ,
V_194 -> V_205 *
sizeof( V_196 -> V_203 [ 0 ] ) ) ;
F_100 ( V_13 -> V_16 . V_198 . V_195 , V_196 ) ;
if ( V_197 )
F_101 ( V_197 , V_206 ) ;
return 0 ;
}
static int F_102 ( struct V_12 * V_13 ,
struct V_207 * V_8 ,
const struct V_193 * V_194 )
{
struct V_208 * V_196 , * V_197 ;
int V_209 , V_210 ;
int V_211 , V_14 ;
T_1 V_212 = V_213 ;
V_197 = F_98 ( V_13 -> V_16 . V_198 . V_214 , V_13 ) ;
if ( ! V_8 -> V_215 && ! V_197 )
return - V_85 ;
if ( V_8 -> V_215 )
V_209 = V_8 -> V_216 ;
else
V_209 = V_197 -> V_216 ;
if ( V_8 -> V_217 || ! V_197 )
V_210 = V_8 -> V_218 ;
else
V_210 = V_197 -> V_218 ;
V_211 = sizeof( * V_196 ) + V_209 + V_210 ;
V_196 = F_99 ( V_211 , V_199 ) ;
if ( ! V_196 )
return - V_200 ;
V_196 -> V_215 = ( ( T_3 * ) V_196 ) + sizeof( * V_196 ) ;
V_196 -> V_217 = V_196 -> V_215 + V_209 ;
V_196 -> V_216 = V_209 ;
V_196 -> V_218 = V_210 ;
if ( V_194 ) {
V_196 -> V_219 = V_194 -> V_220 ;
memcpy ( V_196 -> V_203 , V_194 -> V_221 ,
V_194 -> V_222 *
sizeof( V_196 -> V_203 [ 0 ] ) ) ;
}
if ( V_8 -> V_215 )
memcpy ( V_196 -> V_215 , V_8 -> V_215 , V_209 ) ;
else
memcpy ( V_196 -> V_215 , V_197 -> V_215 , V_209 ) ;
if ( V_8 -> V_217 )
memcpy ( V_196 -> V_217 , V_8 -> V_217 , V_210 ) ;
else
if ( V_197 )
memcpy ( V_196 -> V_217 , V_197 -> V_217 , V_210 ) ;
V_14 = F_97 ( V_13 , V_8 -> V_195 ,
V_8 -> V_223 , V_194 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == 0 )
V_212 |= V_224 ;
F_100 ( V_13 -> V_16 . V_198 . V_214 , V_196 ) ;
if ( V_197 )
F_101 ( V_197 , V_206 ) ;
return V_212 ;
}
static int F_103 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_225 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_208 * V_197 ;
struct V_12 * V_23 ;
T_1 V_212 = V_226 |
V_227 |
V_213 |
V_228 |
V_229 |
V_230 ;
int V_14 ;
V_197 = F_98 ( V_13 -> V_16 . V_198 . V_214 , V_13 ) ;
if ( V_197 )
return - V_231 ;
switch ( V_8 -> V_232 ) {
case V_233 :
V_13 -> V_232 = V_234 ;
break;
case V_235 :
V_13 -> V_232 = V_236 ;
break;
case V_237 :
V_13 -> V_232 = V_238 ;
break;
default:
return - V_85 ;
}
V_13 -> V_239 = V_13 -> V_10 -> V_240 ;
V_13 -> V_27 . V_31 . V_241 = V_8 -> V_242 ;
F_21 ( & V_10 -> V_184 ) ;
V_14 = F_95 ( V_13 , & V_8 -> V_182 ,
V_243 ) ;
if ( ! V_14 )
F_104 ( V_13 , false ) ;
F_23 ( & V_10 -> V_184 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_244 = V_8 -> V_245 . V_246 ;
V_13 -> V_247 = V_8 -> V_245 . V_247 ;
V_13 -> V_248 = F_105 ( V_13 -> V_10 ,
& V_8 -> V_245 ,
V_13 -> V_27 . type ) ;
F_106 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_23 -> V_244 =
V_8 -> V_245 . V_246 ;
V_23 -> V_247 =
V_8 -> V_245 . V_247 ;
V_23 -> V_248 =
F_105 ( V_13 -> V_10 ,
& V_8 -> V_245 ,
V_23 -> V_27 . type ) ;
}
V_13 -> V_27 . V_31 . V_249 = V_8 -> V_249 ;
V_13 -> V_27 . V_31 . V_250 = true ;
V_13 -> V_27 . V_31 . V_251 = V_13 -> V_27 . V_252 ;
V_13 -> V_27 . V_31 . V_253 = V_8 -> V_253 ;
if ( V_8 -> V_253 )
memcpy ( V_13 -> V_27 . V_31 . V_254 , V_8 -> V_254 ,
V_8 -> V_253 ) ;
V_13 -> V_27 . V_31 . V_255 =
( V_8 -> V_255 != V_256 ) ;
memset ( & V_13 -> V_27 . V_31 . V_257 , 0 ,
sizeof( V_13 -> V_27 . V_31 . V_257 ) ) ;
V_13 -> V_27 . V_31 . V_257 . V_258 =
V_8 -> V_259 & V_260 ;
if ( V_8 -> V_261 )
V_13 -> V_27 . V_31 . V_257 . V_258 |=
V_262 ;
V_14 = F_102 ( V_13 , & V_8 -> V_214 , NULL ) ;
if ( V_14 < 0 ) {
F_94 ( V_13 ) ;
return V_14 ;
}
V_212 |= V_14 ;
V_14 = F_107 ( V_13 -> V_10 , V_13 ) ;
if ( V_14 ) {
V_197 = F_98 ( V_13 -> V_16 . V_198 . V_214 , V_13 ) ;
if ( V_197 )
F_101 ( V_197 , V_206 ) ;
F_11 ( V_13 -> V_16 . V_198 . V_214 , NULL ) ;
F_94 ( V_13 ) ;
return V_14 ;
}
F_108 ( V_10 , V_13 ) ;
F_15 ( V_13 , V_212 ) ;
F_109 ( V_19 ) ;
F_106 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_109 ( V_23 -> V_19 ) ;
return 0 ;
}
static int F_110 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_207 * V_8 )
{
struct V_12 * V_13 ;
struct V_208 * V_197 ;
int V_14 ;
V_13 = F_9 ( V_19 ) ;
F_111 ( V_13 ) ;
if ( V_13 -> V_27 . V_263 )
return - V_45 ;
V_197 = F_98 ( V_13 -> V_16 . V_198 . V_214 , V_13 ) ;
if ( ! V_197 )
return - V_100 ;
V_14 = F_102 ( V_13 , V_8 , NULL ) ;
if ( V_14 < 0 )
return V_14 ;
F_15 ( V_13 , V_14 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_12 * V_23 ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_208 * V_264 ;
struct V_195 * V_265 ;
struct V_181 V_182 ;
F_111 ( V_13 ) ;
V_264 = F_98 ( V_13 -> V_16 . V_198 . V_214 , V_13 ) ;
if ( ! V_264 )
return - V_100 ;
V_265 = F_98 ( V_13 -> V_16 . V_198 . V_195 , V_13 ) ;
F_21 ( & V_10 -> V_184 ) ;
V_13 -> V_27 . V_263 = false ;
if ( V_13 -> V_266 ) {
F_113 ( V_10 , V_13 ,
V_267 ) ;
V_13 -> V_266 = false ;
}
F_23 ( & V_10 -> V_184 ) ;
F_114 ( V_13 -> V_16 . V_198 . V_268 ) ;
V_13 -> V_16 . V_198 . V_268 = NULL ;
F_106 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_115 ( V_23 -> V_19 ) ;
F_115 ( V_19 ) ;
F_11 ( V_13 -> V_16 . V_198 . V_214 , NULL ) ;
F_11 ( V_13 -> V_16 . V_198 . V_195 , NULL ) ;
F_101 ( V_264 , V_206 ) ;
if ( V_265 )
F_101 ( V_265 , V_206 ) ;
V_13 -> V_16 . V_198 . V_269 = V_234 ;
F_116 ( V_13 , true ) ;
F_117 ( V_13 , true ) ;
V_13 -> V_27 . V_31 . V_250 = false ;
V_13 -> V_27 . V_31 . V_253 = 0 ;
F_118 ( V_270 , & V_13 -> V_271 ) ;
F_15 ( V_13 , V_227 ) ;
if ( V_13 -> V_11 . V_272 ) {
V_182 = V_13 -> V_27 . V_31 . V_182 ;
F_119 ( & V_13 -> V_273 ) ;
F_120 ( V_13 -> V_19 , & V_182 ,
V_274 ,
V_199 ) ;
}
F_121 ( V_13 -> V_10 , V_13 ) ;
V_10 -> V_275 -= F_122 ( & V_13 -> V_16 . V_198 . V_276 . V_277 ) ;
F_123 ( & V_10 -> V_63 , & V_13 -> V_16 . V_198 . V_276 . V_277 ) ;
F_21 ( & V_10 -> V_184 ) ;
F_104 ( V_13 , true ) ;
F_94 ( V_13 ) ;
F_23 ( & V_10 -> V_184 ) ;
return 0 ;
}
static void F_124 ( struct V_75 * V_24 )
{
struct V_278 * V_279 ;
struct V_280 * V_281 ;
V_281 = F_125 ( sizeof( * V_279 ) ) ;
if ( ! V_281 )
return;
V_279 = (struct V_278 * ) F_126 ( V_281 , sizeof( * V_279 ) ) ;
F_127 ( V_279 -> V_282 ) ;
memcpy ( V_279 -> V_283 , V_24 -> V_24 . V_176 , V_177 ) ;
V_279 -> V_201 = F_128 ( 6 ) ;
V_279 -> V_284 = 0 ;
V_279 -> V_285 = 0x01 ;
V_279 -> V_286 = 0xaf ;
V_279 -> V_287 [ 0 ] = 0x81 ;
V_279 -> V_287 [ 1 ] = 1 ;
V_279 -> V_287 [ 2 ] = 0 ;
V_281 -> V_19 = V_24 -> V_13 -> V_19 ;
V_281 -> V_288 = F_129 ( V_281 , V_24 -> V_13 -> V_19 ) ;
memset ( V_281 -> V_289 , 0 , sizeof( V_281 -> V_289 ) ) ;
F_130 ( V_281 ) ;
}
static int F_131 ( struct V_9 * V_10 ,
struct V_75 * V_24 ,
T_1 V_42 , T_1 V_290 )
{
int V_20 ;
if ( V_42 & F_132 ( V_291 ) &&
V_290 & F_132 ( V_291 ) &&
! F_53 ( V_24 , V_292 ) ) {
V_20 = F_133 ( V_24 , V_293 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_42 & F_132 ( V_294 ) &&
V_290 & F_132 ( V_294 ) &&
! F_53 ( V_24 , V_99 ) ) {
if ( ! F_53 ( V_24 , V_295 ) )
F_134 ( V_24 ) ;
V_20 = F_133 ( V_24 , V_296 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_42 & F_132 ( V_297 ) ) {
if ( V_290 & F_132 ( V_297 ) )
V_20 = F_133 ( V_24 , V_298 ) ;
else if ( F_53 ( V_24 , V_299 ) )
V_20 = F_133 ( V_24 , V_296 ) ;
else
V_20 = 0 ;
if ( V_20 )
return V_20 ;
}
if ( V_42 & F_132 ( V_294 ) &&
! ( V_290 & F_132 ( V_294 ) ) &&
F_53 ( V_24 , V_99 ) ) {
V_20 = F_133 ( V_24 , V_293 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_42 & F_132 ( V_291 ) &&
! ( V_290 & F_132 ( V_291 ) ) &&
F_53 ( V_24 , V_292 ) ) {
V_20 = F_133 ( V_24 , V_300 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static void F_135 ( struct V_9 * V_10 ,
struct V_75 * V_24 ,
struct V_301 * V_8 )
{
#ifdef F_55
struct V_12 * V_13 = V_24 -> V_13 ;
T_1 V_212 = 0 ;
if ( V_8 -> V_302 & V_303 ) {
switch ( V_8 -> V_304 ) {
case V_305 :
if ( V_24 -> V_109 -> V_304 != V_305 )
V_212 = F_136 ( V_13 ) ;
V_24 -> V_109 -> V_304 = V_8 -> V_304 ;
V_24 -> V_109 -> V_306 = V_8 -> V_307 ;
F_137 ( V_24 ) ;
V_212 |= F_138 ( V_24 ,
V_13 -> V_16 . V_109 . V_308 . V_309 ) ;
break;
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
if ( V_24 -> V_109 -> V_304 == V_305 )
V_212 = F_139 ( V_13 ) ;
V_24 -> V_109 -> V_304 = V_8 -> V_304 ;
F_137 ( V_24 ) ;
V_212 |= F_138 ( V_24 ,
V_316 ) ;
break;
default:
break;
}
}
switch ( V_8 -> V_317 ) {
case V_318 :
break;
case V_319 :
V_212 |= F_140 ( V_24 ) ;
break;
case V_320 :
V_212 |= F_141 ( V_24 ) ;
break;
}
if ( V_8 -> V_321 )
V_212 |= F_138 ( V_24 ,
V_8 -> V_321 ) ;
F_142 ( V_13 , V_212 ) ;
#endif
}
static int F_143 ( struct V_9 * V_10 ,
struct V_75 * V_24 ,
struct V_301 * V_8 )
{
int V_20 = 0 ;
struct V_155 * V_156 ;
struct V_12 * V_13 = V_24 -> V_13 ;
enum V_322 V_323 = F_81 ( V_13 ) ;
T_1 V_42 , V_290 ;
V_156 = V_10 -> V_63 . V_2 -> V_159 [ V_323 ] ;
V_42 = V_8 -> V_324 ;
V_290 = V_8 -> V_325 ;
if ( F_144 ( & V_13 -> V_27 ) ) {
if ( V_42 & F_132 ( V_291 ) )
V_42 |= F_132 ( V_294 ) ;
if ( V_290 & F_132 ( V_291 ) )
V_290 |= F_132 ( V_294 ) ;
} else if ( F_53 ( V_24 , V_326 ) ) {
if ( V_290 & F_132 ( V_297 ) ) {
V_290 |= F_132 ( V_291 ) |
F_132 ( V_294 ) ;
V_42 |= F_132 ( V_291 ) |
F_132 ( V_294 ) ;
}
}
if ( V_42 & F_132 ( V_327 ) &&
V_10 -> V_63 . V_328 >= V_329 )
V_24 -> V_24 . V_330 = V_290 & F_132 ( V_327 ) ;
if ( ! F_53 ( V_24 , V_326 ) &&
! ( ( V_42 & F_132 ( V_294 ) ) &&
( V_290 & F_132 ( V_294 ) ) ) ) {
V_20 = F_131 ( V_10 , V_24 , V_42 , V_290 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_42 & F_132 ( V_331 ) ) {
if ( V_290 & F_132 ( V_331 ) )
F_145 ( V_24 , V_332 ) ;
else
F_146 ( V_24 , V_332 ) ;
}
if ( V_42 & F_132 ( V_333 ) ) {
V_24 -> V_24 . V_102 = ! ! ( V_290 & F_132 ( V_333 ) ) ;
if ( V_290 & F_132 ( V_333 ) )
F_145 ( V_24 , V_106 ) ;
else
F_146 ( V_24 , V_106 ) ;
}
if ( V_42 & F_132 ( V_334 ) ) {
if ( V_290 & F_132 ( V_334 ) )
F_145 ( V_24 , V_326 ) ;
else
F_146 ( V_24 , V_326 ) ;
}
if ( F_53 ( V_24 , V_326 ) &&
! V_13 -> V_16 . V_26 . V_335 &&
V_8 -> V_336 >= 4 &&
V_8 -> V_337 [ 3 ] & V_338 )
F_145 ( V_24 , V_339 ) ;
if ( F_53 ( V_24 , V_326 ) &&
! V_13 -> V_16 . V_26 . V_340 &&
F_147 ( & V_10 -> V_63 , V_341 ) &&
V_8 -> V_336 >= 8 &&
V_8 -> V_337 [ 7 ] & V_342 )
F_145 ( V_24 , V_343 ) ;
if ( V_8 -> V_302 & V_344 ) {
V_24 -> V_24 . V_345 = V_8 -> V_345 ;
V_24 -> V_24 . V_346 = V_8 -> V_346 ;
}
if ( V_8 -> V_336 >= 8 ) {
T_3 V_347 = ( V_8 -> V_337 [ 7 ] &
V_348 ) >> 7 ;
if ( V_8 -> V_336 >= 9 ) {
T_3 V_349 = V_8 -> V_337 [ 8 ] &
V_350 ;
V_349 <<= 1 ;
V_347 |= V_349 ;
}
switch ( V_347 ) {
case 1 :
V_24 -> V_24 . V_351 = 32 ;
break;
case 2 :
V_24 -> V_24 . V_351 = 16 ;
break;
case 3 :
V_24 -> V_24 . V_351 = 8 ;
break;
default:
V_24 -> V_24 . V_351 = 0 ;
}
}
if ( V_8 -> V_306 )
V_24 -> V_24 . V_306 = V_8 -> V_306 ;
if ( V_8 -> V_352 >= 0 )
V_24 -> V_352 = V_8 -> V_352 ;
if ( V_8 -> V_353 ) {
F_148 ( & V_13 -> V_27 . V_31 . V_182 ,
V_156 , V_8 -> V_353 ,
V_8 -> V_354 ,
& V_24 -> V_24 . V_355 [ V_323 ] ) ;
}
if ( V_8 -> V_356 )
F_149 ( V_13 , V_156 ,
V_8 -> V_356 , V_24 ) ;
if ( V_8 -> V_357 )
F_150 ( V_13 , V_156 ,
V_8 -> V_357 , V_24 ) ;
if ( V_8 -> V_358 ) {
F_151 ( V_13 , V_24 ,
V_8 -> V_359 , V_323 ) ;
}
if ( V_8 -> V_360 >= 0 )
V_24 -> V_24 . V_360 = V_8 -> V_360 ;
if ( F_144 ( & V_13 -> V_27 ) )
F_135 ( V_10 , V_24 , V_8 ) ;
if ( F_53 ( V_24 , V_326 ) ||
V_290 & F_132 ( V_294 ) ) {
V_20 = F_131 ( V_10 , V_24 , V_42 , V_290 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_152 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_173 ,
struct V_301 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_75 * V_24 ;
struct V_12 * V_13 ;
int V_14 ;
int V_361 ;
if ( V_8 -> V_23 ) {
V_13 = F_9 ( V_8 -> V_23 ) ;
if ( V_13 -> V_27 . type != V_21 &&
V_13 -> V_27 . type != V_105 )
return - V_85 ;
} else
V_13 = F_9 ( V_19 ) ;
if ( F_153 ( V_173 , V_13 -> V_27 . V_176 ) )
return - V_85 ;
if ( F_154 ( V_173 ) )
return - V_85 ;
V_24 = F_155 ( V_13 , V_173 , V_199 ) ;
if ( ! V_24 )
return - V_200 ;
if ( V_8 -> V_325 & F_132 ( V_334 ) )
V_24 -> V_24 . V_362 = true ;
V_14 = F_143 ( V_10 , V_24 , V_8 ) ;
if ( V_14 ) {
F_156 ( V_10 , V_24 ) ;
return V_14 ;
}
if ( ! F_53 ( V_24 , V_326 ) &&
F_53 ( V_24 , V_99 ) )
F_134 ( V_24 ) ;
V_361 = V_13 -> V_27 . type == V_21 ||
V_13 -> V_27 . type == V_105 ;
V_14 = F_157 ( V_24 ) ;
if ( V_14 ) {
F_72 () ;
return V_14 ;
}
if ( V_361 )
F_124 ( V_24 ) ;
F_72 () ;
return 0 ;
}
static int F_158 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_363 * V_8 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
if ( V_8 -> V_173 )
return F_159 ( V_13 , V_8 -> V_173 ) ;
F_160 ( V_13 ) ;
return 0 ;
}
static int F_161 ( struct V_2 * V_2 ,
struct V_18 * V_19 , const T_3 * V_173 ,
struct V_301 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_75 * V_24 ;
struct V_12 * V_364 ;
enum V_365 V_366 ;
int V_14 ;
F_21 ( & V_10 -> V_98 ) ;
V_24 = F_52 ( V_13 , V_173 ) ;
if ( ! V_24 ) {
V_14 = - V_100 ;
goto V_367;
}
switch ( V_13 -> V_27 . type ) {
case V_108 :
if ( V_13 -> V_16 . V_109 . V_368 )
V_366 = V_369 ;
else
V_366 = V_370 ;
break;
case V_107 :
V_366 = V_371 ;
break;
case V_25 :
if ( ! F_53 ( V_24 , V_326 ) ) {
V_366 = V_372 ;
break;
}
if ( F_53 ( V_24 , V_299 ) )
V_366 = V_373 ;
else
V_366 = V_374 ;
break;
case V_105 :
case V_21 :
if ( F_53 ( V_24 , V_99 ) )
V_366 = V_375 ;
else
V_366 = V_376 ;
break;
default:
V_14 = - V_53 ;
goto V_367;
}
V_14 = F_162 ( V_2 , V_8 , V_366 ) ;
if ( V_14 )
goto V_367;
if ( V_8 -> V_23 && V_8 -> V_23 != V_24 -> V_13 -> V_19 ) {
V_364 = F_9 ( V_8 -> V_23 ) ;
if ( V_8 -> V_23 -> V_180 -> V_22 ) {
if ( V_364 -> V_16 . V_23 . V_24 ) {
V_14 = - V_45 ;
goto V_367;
}
F_100 ( V_364 -> V_16 . V_23 . V_24 , V_24 ) ;
F_163 ( V_364 ) ;
}
if ( V_24 -> V_13 -> V_27 . type == V_21 &&
V_24 -> V_13 -> V_16 . V_23 . V_24 )
F_11 ( V_24 -> V_13 -> V_16 . V_23 . V_24 , NULL ) ;
if ( F_53 ( V_24 , V_299 ) )
F_164 ( V_24 -> V_13 ) ;
V_24 -> V_13 = V_364 ;
F_165 ( V_24 ) ;
if ( F_53 ( V_24 , V_299 ) )
F_166 ( V_24 -> V_13 ) ;
F_124 ( V_24 ) ;
}
V_14 = F_143 ( V_10 , V_24 , V_8 ) ;
if ( V_14 )
goto V_367;
F_23 ( & V_10 -> V_98 ) ;
if ( ( V_13 -> V_27 . type == V_105 ||
V_13 -> V_27 . type == V_21 ) &&
V_24 -> V_377 != V_24 -> V_13 -> V_378 -> V_379 &&
F_53 ( V_24 , V_299 ) &&
F_167 ( V_24 ) != 1 ) {
F_168 ( V_24 -> V_13 ,
L_1 ,
V_24 -> V_24 . V_176 ) ;
F_169 ( V_24 -> V_13 ,
V_24 -> V_13 -> V_378 -> V_379 ,
V_24 -> V_24 . V_176 ,
V_24 -> V_13 -> V_27 . V_31 . V_380 ) ;
}
if ( V_13 -> V_27 . type == V_25 &&
V_8 -> V_324 & F_132 ( V_297 ) ) {
F_170 ( V_10 ) ;
F_171 ( V_13 ) ;
}
return 0 ;
V_367:
F_23 ( & V_10 -> V_98 ) ;
return V_14 ;
}
static int F_172 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_381 , const T_3 * V_382 )
{
struct V_12 * V_13 ;
struct V_383 * V_384 ;
struct V_75 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_63 () ;
V_24 = F_173 ( V_13 , V_382 ) ;
if ( ! V_24 ) {
F_72 () ;
return - V_100 ;
}
V_384 = F_174 ( V_13 , V_381 ) ;
if ( F_48 ( V_384 ) ) {
F_72 () ;
return F_51 ( V_384 ) ;
}
F_175 ( V_384 , V_24 ) ;
F_72 () ;
return 0 ;
}
static int F_176 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_381 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( V_381 )
return F_177 ( V_13 , V_381 ) ;
F_178 ( V_13 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_381 , const T_3 * V_382 )
{
struct V_12 * V_13 ;
struct V_383 * V_384 ;
struct V_75 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_63 () ;
V_24 = F_173 ( V_13 , V_382 ) ;
if ( ! V_24 ) {
F_72 () ;
return - V_100 ;
}
V_384 = F_180 ( V_13 , V_381 ) ;
if ( ! V_384 ) {
F_72 () ;
return - V_100 ;
}
F_175 ( V_384 , V_24 ) ;
F_72 () ;
return 0 ;
}
static void F_181 ( struct V_383 * V_384 , T_3 * V_382 ,
struct V_385 * V_386 )
{
struct V_75 * V_387 = F_64 ( V_384 -> V_382 ) ;
if ( V_387 )
memcpy ( V_382 , V_387 -> V_24 . V_176 , V_177 ) ;
else
F_182 ( V_382 ) ;
memset ( V_386 , 0 , sizeof( * V_386 ) ) ;
V_386 -> V_388 = V_384 -> V_13 -> V_16 . V_109 . V_389 ;
V_386 -> V_390 = V_391 |
V_392 |
V_393 |
V_394 |
V_395 |
V_396 |
V_397 ;
V_386 -> V_398 = V_384 -> V_399 . V_400 ;
V_386 -> V_401 = V_384 -> V_401 ;
V_386 -> V_402 = V_384 -> V_402 ;
if ( F_183 ( V_403 , V_384 -> V_404 ) )
V_386 -> V_405 = F_184 ( V_384 -> V_404 - V_403 ) ;
V_386 -> V_406 =
F_184 ( V_384 -> V_406 ) ;
V_386 -> V_407 = V_384 -> V_407 ;
if ( V_384 -> V_6 & V_408 )
V_386 -> V_6 |= V_409 ;
if ( V_384 -> V_6 & V_410 )
V_386 -> V_6 |= V_411 ;
if ( V_384 -> V_6 & V_412 )
V_386 -> V_6 |= V_413 ;
if ( V_384 -> V_6 & V_414 )
V_386 -> V_6 |= V_415 ;
if ( V_384 -> V_6 & V_416 )
V_386 -> V_6 |= V_417 ;
}
static int F_185 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_381 , T_3 * V_382 , struct V_385 * V_386 )
{
struct V_12 * V_13 ;
struct V_383 * V_384 ;
V_13 = F_9 ( V_19 ) ;
F_63 () ;
V_384 = F_180 ( V_13 , V_381 ) ;
if ( ! V_384 ) {
F_72 () ;
return - V_100 ;
}
memcpy ( V_381 , V_384 -> V_381 , V_177 ) ;
F_181 ( V_384 , V_382 , V_386 ) ;
F_72 () ;
return 0 ;
}
static int F_186 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_151 , T_3 * V_381 , T_3 * V_382 ,
struct V_385 * V_386 )
{
struct V_12 * V_13 ;
struct V_383 * V_384 ;
V_13 = F_9 ( V_19 ) ;
F_63 () ;
V_384 = F_187 ( V_13 , V_151 ) ;
if ( ! V_384 ) {
F_72 () ;
return - V_100 ;
}
memcpy ( V_381 , V_384 -> V_381 , V_177 ) ;
F_181 ( V_384 , V_382 , V_386 ) ;
F_72 () ;
return 0 ;
}
static void F_188 ( struct V_383 * V_384 , T_3 * V_418 ,
struct V_385 * V_386 )
{
memset ( V_386 , 0 , sizeof( * V_386 ) ) ;
memcpy ( V_418 , V_384 -> V_418 , V_177 ) ;
V_386 -> V_388 = V_384 -> V_13 -> V_16 . V_109 . V_419 ;
}
static int F_189 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_381 , T_3 * V_418 , struct V_385 * V_386 )
{
struct V_12 * V_13 ;
struct V_383 * V_384 ;
V_13 = F_9 ( V_19 ) ;
F_63 () ;
V_384 = F_190 ( V_13 , V_381 ) ;
if ( ! V_384 ) {
F_72 () ;
return - V_100 ;
}
memcpy ( V_381 , V_384 -> V_381 , V_177 ) ;
F_188 ( V_384 , V_418 , V_386 ) ;
F_72 () ;
return 0 ;
}
static int F_191 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_151 , T_3 * V_381 , T_3 * V_418 ,
struct V_385 * V_386 )
{
struct V_12 * V_13 ;
struct V_383 * V_384 ;
V_13 = F_9 ( V_19 ) ;
F_63 () ;
V_384 = F_192 ( V_13 , V_151 ) ;
if ( ! V_384 ) {
F_72 () ;
return - V_100 ;
}
memcpy ( V_381 , V_384 -> V_381 , V_177 ) ;
F_188 ( V_384 , V_418 , V_386 ) ;
F_72 () ;
return 0 ;
}
static int F_193 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_420 * V_48 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
memcpy ( V_48 , & ( V_13 -> V_16 . V_109 . V_308 ) , sizeof( struct V_420 ) ) ;
return 0 ;
}
static inline bool F_194 ( enum V_421 V_422 , T_1 V_42 )
{
return ( V_42 >> ( V_422 - 1 ) ) & 0x1 ;
}
static int F_195 ( struct V_423 * V_424 ,
const struct V_425 * V_426 )
{
T_3 * V_427 ;
const T_3 * V_428 ;
struct V_12 * V_13 = F_196 ( V_424 ,
struct V_12 , V_16 . V_109 ) ;
V_427 = NULL ;
V_428 = V_424 -> V_429 ;
if ( V_426 -> V_430 ) {
V_427 = F_197 ( V_426 -> V_429 , V_426 -> V_430 ,
V_199 ) ;
if ( ! V_427 )
return - V_200 ;
}
V_424 -> V_430 = V_426 -> V_430 ;
V_424 -> V_429 = V_427 ;
F_114 ( V_428 ) ;
V_424 -> V_431 = V_426 -> V_431 ;
memcpy ( V_424 -> V_432 , V_426 -> V_432 , V_424 -> V_431 ) ;
V_424 -> V_433 = V_426 -> V_434 ;
V_424 -> V_435 = V_426 -> V_436 ;
V_424 -> V_437 = V_426 -> V_438 ;
V_424 -> V_368 = V_426 -> V_368 ;
V_424 -> V_439 = V_426 -> V_440 ;
V_424 -> V_110 = V_111 ;
if ( V_426 -> V_441 )
V_424 -> V_110 |= V_442 ;
if ( V_426 -> V_443 )
V_424 -> V_110 |= V_444 ;
memcpy ( V_13 -> V_27 . V_31 . V_445 , V_426 -> V_445 ,
sizeof( V_426 -> V_445 ) ) ;
V_13 -> V_27 . V_31 . V_446 = V_426 -> V_446 ;
V_13 -> V_27 . V_31 . V_241 = V_426 -> V_242 ;
V_13 -> V_27 . V_31 . V_249 = V_426 -> V_249 ;
return 0 ;
}
static int F_198 ( struct V_2 * V_2 ,
struct V_18 * V_19 , T_1 V_42 ,
const struct V_420 * V_447 )
{
struct V_420 * V_48 ;
struct V_12 * V_13 ;
struct V_423 * V_424 ;
V_13 = F_9 ( V_19 ) ;
V_424 = & V_13 -> V_16 . V_109 ;
V_48 = & ( V_13 -> V_16 . V_109 . V_308 ) ;
if ( F_194 ( V_448 , V_42 ) )
V_48 -> V_449 = V_447 -> V_449 ;
if ( F_194 ( V_450 , V_42 ) )
V_48 -> V_451 = V_447 -> V_451 ;
if ( F_194 ( V_452 , V_42 ) )
V_48 -> V_453 = V_447 -> V_453 ;
if ( F_194 ( V_454 , V_42 ) )
V_48 -> V_455 = V_447 -> V_455 ;
if ( F_194 ( V_456 , V_42 ) )
V_48 -> V_457 = V_447 -> V_457 ;
if ( F_194 ( V_458 , V_42 ) )
V_48 -> V_459 = V_447 -> V_459 ;
if ( F_194 ( V_460 , V_42 ) )
V_48 -> V_461 = V_447 -> V_461 ;
if ( F_194 ( V_462 , V_42 ) ) {
if ( V_424 -> V_368 )
return - V_45 ;
V_48 -> V_463 = V_447 -> V_463 ;
}
if ( F_194 ( V_464 , V_42 ) )
V_48 -> V_465 =
V_447 -> V_465 ;
if ( F_194 ( V_466 , V_42 ) )
V_48 -> V_467 =
V_447 -> V_467 ;
if ( F_194 ( V_468 , V_42 ) )
V_48 -> V_469 = V_447 -> V_469 ;
if ( F_194 ( V_470 , V_42 ) )
V_48 -> V_471 = V_447 -> V_471 ;
if ( F_194 ( V_472 , V_42 ) )
V_48 -> V_473 =
V_447 -> V_473 ;
if ( F_194 ( V_474 , V_42 ) )
V_48 -> V_475 =
V_447 -> V_475 ;
if ( F_194 ( V_476 , V_42 ) )
V_48 -> V_477 =
V_447 -> V_477 ;
if ( F_194 ( V_478 ,
V_42 ) )
V_48 -> V_479 =
V_447 -> V_479 ;
if ( F_194 ( V_480 , V_42 ) ) {
V_48 -> V_481 = V_447 -> V_481 ;
F_199 ( V_424 ) ;
}
if ( F_194 ( V_482 , V_42 ) ) {
if ( V_447 -> V_483 &&
! ( V_48 -> V_481 > V_484 ) ) {
V_48 -> V_481 = V_485 ;
F_199 ( V_424 ) ;
}
V_48 -> V_483 =
V_447 -> V_483 ;
}
if ( F_194 ( V_486 , V_42 ) )
V_48 -> V_487 =
V_447 -> V_487 ;
if ( F_194 ( V_488 , V_42 ) )
V_48 -> V_489 = V_447 -> V_489 ;
if ( F_194 ( V_490 , V_42 ) ) {
if ( ! F_147 ( & V_13 -> V_10 -> V_63 , V_491 ) )
return - V_492 ;
V_48 -> V_493 = V_447 -> V_493 ;
}
if ( F_194 ( V_494 , V_42 ) ) {
V_48 -> V_495 = V_447 -> V_495 ;
V_13 -> V_27 . V_31 . V_496 = V_447 -> V_495 ;
F_15 ( V_13 , V_497 ) ;
}
if ( F_194 ( V_498 , V_42 ) )
V_48 -> V_499 =
V_447 -> V_499 ;
if ( F_194 ( V_500 , V_42 ) )
V_48 -> V_501 =
V_447 -> V_501 ;
if ( F_194 ( V_502 , V_42 ) )
V_48 -> V_503 =
V_447 -> V_503 ;
if ( F_194 ( V_504 , V_42 ) ) {
V_48 -> V_309 = V_447 -> V_309 ;
F_200 ( V_13 ) ;
}
if ( F_194 ( V_505 , V_42 ) )
V_48 -> V_506 =
V_447 -> V_506 ;
if ( F_194 ( V_507 , V_42 ) )
V_48 -> V_508 = V_447 -> V_508 ;
F_142 ( V_13 , V_213 ) ;
return 0 ;
}
static int F_201 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const struct V_420 * V_48 ,
const struct V_425 * V_426 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_423 * V_424 = & V_13 -> V_16 . V_109 ;
int V_14 ;
memcpy ( & V_424 -> V_308 , V_48 , sizeof( struct V_420 ) ) ;
V_14 = F_195 ( V_424 , V_426 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_232 = V_234 ;
V_13 -> V_239 = V_13 -> V_10 -> V_240 ;
F_21 ( & V_13 -> V_10 -> V_184 ) ;
V_14 = F_95 ( V_13 , & V_426 -> V_182 ,
V_243 ) ;
F_23 ( & V_13 -> V_10 -> V_184 ) ;
if ( V_14 )
return V_14 ;
return F_202 ( V_13 ) ;
}
static int F_203 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_204 ( V_13 ) ;
F_21 ( & V_13 -> V_10 -> V_184 ) ;
F_94 ( V_13 ) ;
F_23 ( & V_13 -> V_10 -> V_184 ) ;
return 0 ;
}
static int F_205 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_509 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
enum V_322 V_323 ;
T_1 V_212 = 0 ;
if ( ! F_98 ( V_13 -> V_16 . V_198 . V_214 , V_13 ) )
return - V_100 ;
V_323 = F_81 ( V_13 ) ;
if ( V_8 -> V_510 >= 0 ) {
V_13 -> V_27 . V_31 . V_510 = V_8 -> V_510 ;
V_212 |= V_511 ;
}
if ( V_8 -> V_512 >= 0 ) {
V_13 -> V_27 . V_31 . V_512 =
V_8 -> V_512 ;
V_212 |= V_513 ;
}
if ( ! V_13 -> V_27 . V_31 . V_514 &&
V_323 == V_515 ) {
V_13 -> V_27 . V_31 . V_514 = true ;
V_212 |= V_516 ;
}
if ( V_8 -> V_517 >= 0 ) {
V_13 -> V_27 . V_31 . V_514 =
V_8 -> V_517 ;
V_212 |= V_516 ;
}
if ( V_8 -> V_446 ) {
F_148 ( & V_13 -> V_27 . V_31 . V_182 ,
V_2 -> V_159 [ V_323 ] ,
V_8 -> V_446 ,
V_8 -> V_518 ,
& V_13 -> V_27 . V_31 . V_446 ) ;
V_212 |= V_519 ;
}
if ( V_8 -> V_520 >= 0 ) {
if ( V_8 -> V_520 )
V_13 -> V_6 |= V_521 ;
else
V_13 -> V_6 &= ~ V_521 ;
F_12 ( V_13 ) ;
}
if ( V_8 -> V_495 >= 0 ) {
V_13 -> V_27 . V_31 . V_496 =
( T_4 ) V_8 -> V_495 ;
V_212 |= V_497 ;
}
if ( V_8 -> V_259 >= 0 ) {
V_13 -> V_27 . V_31 . V_257 . V_258 &=
~ V_260 ;
V_13 -> V_27 . V_31 . V_257 . V_258 |=
V_8 -> V_259 & V_260 ;
V_212 |= V_229 ;
}
if ( V_8 -> V_261 > 0 ) {
V_13 -> V_27 . V_31 . V_257 . V_258 |=
V_262 ;
V_212 |= V_229 ;
} else if ( V_8 -> V_261 == 0 ) {
V_13 -> V_27 . V_31 . V_257 . V_258 &=
~ V_262 ;
V_212 |= V_229 ;
}
F_15 ( V_13 , V_212 ) ;
return 0 ;
}
static int F_206 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_522 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_523 V_524 ;
if ( ! V_10 -> V_525 -> V_526 )
return - V_53 ;
if ( V_10 -> V_63 . V_328 < V_329 )
return - V_53 ;
memset ( & V_524 , 0 , sizeof( V_524 ) ) ;
V_524 . V_527 = V_8 -> V_527 ;
V_524 . V_528 = V_8 -> V_529 ;
V_524 . V_530 = V_8 -> V_531 ;
V_524 . V_532 = V_8 -> V_532 ;
V_524 . V_533 = false ;
V_13 -> V_534 [ V_8 -> V_535 ] = V_524 ;
if ( F_207 ( V_10 , V_13 , V_8 -> V_535 , & V_524 ) ) {
F_208 ( V_10 -> V_63 . V_2 ,
L_2 ,
V_8 -> V_535 ) ;
return - V_85 ;
}
F_15 ( V_13 , V_536 ) ;
return 0 ;
}
static int F_209 ( struct V_2 * V_2 ,
struct V_537 * V_538 )
{
return F_210 ( F_2 ( V_2 ) , V_538 ) ;
}
static int F_211 ( struct V_2 * V_2 )
{
return F_212 ( F_2 ( V_2 ) ) ;
}
static int F_213 ( struct V_2 * V_2 ,
struct V_539 * V_540 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_540 -> V_11 ) ;
switch ( F_214 ( & V_13 -> V_27 ) ) {
case V_25 :
case V_107 :
case V_108 :
case V_116 :
case V_113 :
break;
case V_117 :
if ( V_13 -> V_10 -> V_525 -> V_541 )
break;
case V_105 :
if ( V_13 -> V_16 . V_198 . V_214 &&
( ! ( V_2 -> V_542 & V_543 ) ||
! ( V_540 -> V_6 & V_544 ) ) )
return - V_53 ;
break;
case V_52 :
default:
return - V_53 ;
}
return F_215 ( V_13 , V_540 ) ;
}
static void F_216 ( struct V_2 * V_2 , struct V_1 * V_11 )
{
F_217 ( F_2 ( V_2 ) ) ;
}
static int
F_218 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_545 * V_540 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_525 -> V_546 )
return - V_53 ;
return F_219 ( V_13 , V_540 ) ;
}
static int
F_220 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_525 -> V_547 )
return - V_53 ;
return F_221 ( V_10 ) ;
}
static int F_222 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_548 * V_540 )
{
return F_223 ( F_9 ( V_19 ) , V_540 ) ;
}
static int F_224 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_549 * V_540 )
{
return F_225 ( F_9 ( V_19 ) , V_540 ) ;
}
static int F_226 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_550 * V_540 )
{
return F_227 ( F_9 ( V_19 ) , V_540 ) ;
}
static int F_228 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_551 * V_540 )
{
return F_229 ( F_9 ( V_19 ) , V_540 ) ;
}
static int F_230 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_552 * V_8 )
{
return F_231 ( F_9 ( V_19 ) , V_8 ) ;
}
static int F_232 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_233 ( F_9 ( V_19 ) ) ;
}
static int F_234 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_553 * V_426 )
{
return F_235 ( F_9 ( V_19 ) , V_426 ) ;
}
static int F_236 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_237 ( F_9 ( V_19 ) ) ;
}
static int F_238 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_145 [ V_554 ] )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( V_13 -> V_27 . V_31 . V_445 , V_145 ,
sizeof( int ) * V_554 ) ;
return 0 ;
}
static int F_239 ( struct V_2 * V_2 , T_1 V_212 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_212 & V_555 ) {
F_240 ( V_10 ) ;
V_14 = F_241 ( V_10 , V_2 -> V_556 ) ;
if ( V_14 ) {
F_240 ( V_10 ) ;
return V_14 ;
}
}
if ( ( V_212 & V_557 ) ||
( V_212 & V_558 ) ) {
T_6 V_559 ;
V_559 = V_212 & V_557 ?
V_2 -> V_559 : - 1 ;
V_14 = F_242 ( V_10 , V_559 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_212 & V_560 ) {
V_14 = F_243 ( V_10 , V_2 -> V_561 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_212 & V_562 ) {
if ( V_2 -> V_563 > V_564 )
return - V_85 ;
V_10 -> V_63 . V_48 . V_565 = V_2 -> V_563 ;
}
if ( V_212 & V_566 ) {
if ( V_2 -> V_567 > V_564 )
return - V_85 ;
V_10 -> V_63 . V_48 . V_568 = V_2 -> V_567 ;
}
if ( V_212 &
( V_562 | V_566 ) )
F_96 ( V_10 , V_569 ) ;
return 0 ;
}
static int F_244 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
enum V_570 type , int V_571 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
enum V_570 V_572 = type ;
bool V_573 = false ;
if ( V_11 ) {
V_13 = F_5 ( V_11 ) ;
switch ( type ) {
case V_574 :
V_13 -> V_575 = V_576 ;
V_572 = V_577 ;
break;
case V_577 :
case V_578 :
if ( V_571 < 0 || ( V_571 % 100 ) )
return - V_53 ;
V_13 -> V_575 = F_245 ( V_571 ) ;
break;
}
if ( V_572 != V_13 -> V_27 . V_31 . V_579 ) {
V_573 = true ;
V_13 -> V_27 . V_31 . V_579 = V_572 ;
}
F_246 ( V_13 , V_573 ) ;
return 0 ;
}
switch ( type ) {
case V_574 :
V_10 -> V_575 = V_576 ;
V_572 = V_577 ;
break;
case V_577 :
case V_578 :
if ( V_571 < 0 || ( V_571 % 100 ) )
return - V_53 ;
V_10 -> V_575 = F_245 ( V_571 ) ;
break;
}
F_21 ( & V_10 -> V_185 ) ;
F_106 (sdata, &local->interfaces, list) {
V_13 -> V_575 = V_10 -> V_575 ;
if ( V_572 != V_13 -> V_27 . V_31 . V_579 )
V_573 = true ;
V_13 -> V_27 . V_31 . V_579 = V_572 ;
}
F_106 (sdata, &local->interfaces, list)
F_246 ( V_13 , V_573 ) ;
F_23 ( & V_10 -> V_185 ) ;
return 0 ;
}
static int F_247 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
int * V_580 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_10 -> V_525 -> V_581 )
return F_248 ( V_10 , V_13 , V_580 ) ;
if ( ! V_10 -> V_186 )
* V_580 = V_10 -> V_63 . V_48 . V_582 ;
else
* V_580 = V_13 -> V_27 . V_31 . V_583 ;
return 0 ;
}
static int F_249 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_176 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( & V_13 -> V_16 . V_584 . V_585 , V_176 , V_177 ) ;
return 0 ;
}
static void F_250 ( struct V_2 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_251 ( V_10 ) ;
}
static int F_252 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
void * V_202 , int V_201 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_586 * V_27 = NULL ;
if ( ! V_10 -> V_525 -> V_587 )
return - V_53 ;
if ( V_11 ) {
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 -> V_6 & V_588 )
V_27 = & V_13 -> V_27 ;
}
return V_10 -> V_525 -> V_587 ( & V_10 -> V_63 , V_27 , V_202 , V_201 ) ;
}
static int F_253 ( struct V_2 * V_2 ,
struct V_280 * V_281 ,
struct V_589 * V_289 ,
void * V_202 , int V_201 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_525 -> V_590 )
return - V_53 ;
return V_10 -> V_525 -> V_590 ( & V_10 -> V_63 , V_281 , V_289 , V_202 , V_201 ) ;
}
int F_254 ( struct V_12 * V_13 ,
enum V_591 V_232 )
{
struct V_75 * V_24 ;
enum V_591 V_592 ;
if ( F_56 ( V_13 -> V_27 . type != V_105 ) )
return - V_85 ;
if ( V_13 -> V_27 . V_31 . V_182 . V_593 == V_594 )
return 0 ;
V_592 = V_13 -> V_16 . V_198 . V_379 ;
V_13 -> V_16 . V_198 . V_379 = V_232 ;
if ( V_592 == V_232 ||
V_232 == V_595 )
return 0 ;
F_168 ( V_13 ,
L_3 ,
V_232 , F_255 ( & V_13 -> V_16 . V_198 . V_596 ) ) ;
F_21 ( & V_13 -> V_10 -> V_98 ) ;
F_106 (sta, &sdata->local->sta_list, list) {
if ( V_24 -> V_13 -> V_378 != & V_13 -> V_16 . V_198 )
continue;
if ( F_167 ( V_24 ) == 1 )
continue;
if ( F_53 ( V_24 , V_597 ) &&
! F_256 ( V_24 -> V_377 ,
V_232 ) ) {
F_168 ( V_13 , L_4 ,
V_24 -> V_24 . V_176 ) ;
continue;
}
if ( ! F_53 ( V_24 , V_299 ) )
continue;
F_168 ( V_13 , L_5 , V_24 -> V_24 . V_176 ) ;
F_169 ( V_13 , V_232 , V_24 -> V_24 . V_176 ,
V_13 -> V_27 . V_31 . V_380 ) ;
}
F_23 ( & V_13 -> V_10 -> V_98 ) ;
V_13 -> V_232 = V_232 ;
F_257 ( & V_13 -> V_10 -> V_63 , & V_13 -> V_598 ) ;
return 0 ;
}
int F_258 ( struct V_12 * V_13 ,
enum V_591 V_232 )
{
const T_3 * V_198 ;
enum V_591 V_592 ;
int V_14 ;
struct V_75 * V_24 ;
bool V_599 = false ;
F_41 ( & V_13 -> V_11 . V_184 ) ;
if ( F_56 ( V_13 -> V_27 . type != V_25 ) )
return - V_85 ;
V_592 = V_13 -> V_16 . V_26 . V_379 ;
V_13 -> V_16 . V_26 . V_379 = V_232 ;
if ( V_592 == V_232 &&
V_232 != V_595 )
return 0 ;
if ( ! V_13 -> V_16 . V_26 . V_600 ||
V_13 -> V_27 . V_31 . V_182 . V_593 == V_594 )
return 0 ;
V_198 = V_13 -> V_16 . V_26 . V_600 -> V_380 ;
F_63 () ;
F_259 (sta, &sdata->local->sta_list, list) {
if ( ! V_24 -> V_24 . V_362 || V_24 -> V_13 != V_13 || ! V_24 -> V_601 ||
! F_53 ( V_24 , V_299 ) )
continue;
V_599 = true ;
break;
}
F_72 () ;
if ( V_232 == V_595 ) {
if ( V_599 || ! V_13 -> V_16 . V_26 . V_602 )
V_232 = V_234 ;
else
V_232 = V_238 ;
}
V_14 = F_169 ( V_13 , V_232 ,
V_198 , V_198 ) ;
if ( V_14 )
V_13 -> V_16 . V_26 . V_379 = V_592 ;
else if ( V_232 != V_234 && V_599 )
F_260 ( V_13 ) ;
return V_14 ;
}
static int F_261 ( struct V_2 * V_2 , struct V_18 * V_19 ,
bool V_603 , int V_604 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_87 ( V_19 -> V_180 ) ;
if ( V_13 -> V_27 . type != V_25 )
return - V_53 ;
if ( ! F_147 ( & V_10 -> V_63 , V_605 ) )
return - V_53 ;
if ( V_603 == V_13 -> V_16 . V_26 . V_602 &&
V_604 == V_10 -> V_606 )
return 0 ;
V_13 -> V_16 . V_26 . V_602 = V_603 ;
V_10 -> V_606 = V_604 ;
F_262 ( V_13 ) ;
F_258 ( V_13 , V_13 -> V_16 . V_26 . V_379 ) ;
F_263 ( V_13 ) ;
if ( F_147 ( & V_10 -> V_63 , V_607 ) )
F_96 ( V_10 , V_608 ) ;
F_170 ( V_10 ) ;
F_171 ( V_13 ) ;
return 0 ;
}
static int F_264 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_7 V_609 , T_1 V_610 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_586 * V_27 = & V_13 -> V_27 ;
struct V_611 * V_31 = & V_27 -> V_31 ;
if ( V_609 == V_31 -> V_612 &&
V_610 == V_31 -> V_613 )
return 0 ;
if ( V_13 -> V_27 . V_614 & V_615 &&
! ( V_13 -> V_27 . V_614 & V_616 ) )
return - V_53 ;
V_31 -> V_612 = V_609 ;
V_31 -> V_613 = V_610 ;
V_13 -> V_16 . V_26 . V_617 = 0 ;
if ( V_13 -> V_16 . V_26 . V_600 &&
V_13 -> V_27 . V_614 & V_616 )
F_15 ( V_13 , V_618 ) ;
return 0 ;
}
static int F_265 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
const T_3 * V_176 ,
const struct V_619 * V_42 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_87 ( V_19 -> V_180 ) ;
int V_620 , V_20 ;
if ( ! F_17 ( V_13 ) )
return - V_54 ;
if ( F_147 ( & V_10 -> V_63 , V_621 ) ) {
V_20 = F_266 ( V_10 , V_13 , V_42 ) ;
if ( V_20 )
return V_20 ;
}
for ( V_620 = 0 ; V_620 < V_554 ; V_620 ++ ) {
struct V_155 * V_156 = V_2 -> V_159 [ V_620 ] ;
int V_622 ;
V_13 -> V_623 [ V_620 ] = V_42 -> V_286 [ V_620 ] . V_162 ;
memcpy ( V_13 -> V_624 [ V_620 ] , V_42 -> V_286 [ V_620 ] . V_625 ,
sizeof( V_42 -> V_286 [ V_620 ] . V_625 ) ) ;
memcpy ( V_13 -> V_626 [ V_620 ] ,
V_42 -> V_286 [ V_620 ] . V_627 ,
sizeof( V_42 -> V_286 [ V_620 ] . V_627 ) ) ;
V_13 -> V_628 [ V_620 ] = false ;
V_13 -> V_629 [ V_620 ] = false ;
if ( ! V_156 )
continue;
for ( V_622 = 0 ; V_622 < V_630 ; V_622 ++ ) {
if ( ~ V_13 -> V_624 [ V_620 ] [ V_622 ] ) {
V_13 -> V_628 [ V_620 ] = true ;
break;
}
}
for ( V_622 = 0 ; V_622 < V_631 ; V_622 ++ ) {
if ( ~ V_13 -> V_626 [ V_620 ] [ V_622 ] ) {
V_13 -> V_629 [ V_620 ] = true ;
break;
}
}
}
return 0 ;
}
static int F_267 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_181 * V_182 ,
T_1 V_632 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_21 ( & V_10 -> V_184 ) ;
if ( ! F_268 ( & V_10 -> V_633 ) || V_10 -> V_634 ) {
V_14 = - V_45 ;
goto V_101;
}
V_13 -> V_232 = V_234 ;
V_13 -> V_239 = V_10 -> V_240 ;
V_14 = F_95 ( V_13 , V_182 ,
V_243 ) ;
if ( V_14 )
goto V_101;
F_269 ( & V_13 -> V_10 -> V_63 ,
& V_13 -> V_273 ,
F_270 ( V_632 ) ) ;
V_101:
F_23 ( & V_10 -> V_184 ) ;
return V_14 ;
}
static struct V_207 *
F_271 ( struct V_207 * V_214 )
{
struct V_207 * V_635 ;
T_3 * V_636 ;
int V_201 ;
V_201 = V_214 -> V_216 + V_214 -> V_218 + V_214 -> V_637 +
V_214 -> V_638 + V_214 -> V_639 +
V_214 -> V_223 ;
V_635 = F_99 ( sizeof( * V_635 ) + V_201 , V_199 ) ;
if ( ! V_635 )
return NULL ;
V_636 = ( T_3 * ) ( V_635 + 1 ) ;
if ( V_214 -> V_216 ) {
V_635 -> V_216 = V_214 -> V_216 ;
V_635 -> V_215 = V_636 ;
memcpy ( V_636 , V_214 -> V_215 , V_214 -> V_216 ) ;
V_636 += V_214 -> V_216 ;
}
if ( V_214 -> V_218 ) {
V_635 -> V_218 = V_214 -> V_218 ;
V_635 -> V_217 = V_636 ;
memcpy ( V_636 , V_214 -> V_217 , V_214 -> V_218 ) ;
V_636 += V_214 -> V_218 ;
}
if ( V_214 -> V_637 ) {
V_635 -> V_637 = V_214 -> V_637 ;
V_635 -> V_640 = V_636 ;
memcpy ( V_636 , V_214 -> V_640 , V_214 -> V_637 ) ;
V_636 += V_214 -> V_637 ;
}
if ( V_214 -> V_638 ) {
V_635 -> V_638 = V_214 -> V_638 ;
V_635 -> V_641 = V_636 ;
memcpy ( V_636 , V_214 -> V_641 , V_214 -> V_638 ) ;
V_636 += V_214 -> V_638 ;
}
if ( V_214 -> V_639 ) {
V_635 -> V_639 = V_214 -> V_639 ;
V_635 -> V_642 = V_636 ;
memcpy ( V_636 , V_214 -> V_642 , V_214 -> V_639 ) ;
V_636 += V_214 -> V_639 ;
}
if ( V_214 -> V_223 ) {
V_635 -> V_223 = V_214 -> V_223 ;
V_214 -> V_195 = V_636 ;
memcpy ( V_636 , V_214 -> V_195 , V_214 -> V_223 ) ;
V_636 += V_214 -> V_223 ;
}
return V_635 ;
}
void F_272 ( struct V_586 * V_27 )
{
struct V_12 * V_13 = F_273 ( V_27 ) ;
F_257 ( & V_13 -> V_10 -> V_63 ,
& V_13 -> V_643 ) ;
}
static int F_274 ( struct V_12 * V_13 ,
T_1 * V_212 )
{
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_105 :
V_14 = F_102 ( V_13 , V_13 -> V_16 . V_198 . V_268 ,
NULL ) ;
F_114 ( V_13 -> V_16 . V_198 . V_268 ) ;
V_13 -> V_16 . V_198 . V_268 = NULL ;
if ( V_14 < 0 )
return V_14 ;
* V_212 |= V_14 ;
break;
case V_107 :
V_14 = F_275 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_212 |= V_14 ;
break;
#ifdef F_55
case V_108 :
V_14 = F_276 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_212 |= V_14 ;
break;
#endif
default:
F_37 ( 1 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_277 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_10 ;
T_1 V_212 = 0 ;
int V_14 ;
F_111 ( V_13 ) ;
F_41 ( & V_10 -> V_184 ) ;
F_41 ( & V_10 -> V_46 ) ;
if ( V_13 -> V_644 ) {
if ( V_13 -> V_645 )
return 0 ;
return F_278 ( V_13 ) ;
}
if ( ! F_91 ( & V_13 -> V_27 . V_31 . V_182 ,
& V_13 -> V_646 ) )
return - V_85 ;
V_13 -> V_27 . V_263 = false ;
V_14 = F_274 ( V_13 , & V_212 ) ;
if ( V_14 )
return V_14 ;
F_15 ( V_13 , V_212 ) ;
if ( V_13 -> V_266 ) {
F_113 ( V_10 , V_13 ,
V_267 ) ;
V_13 -> V_266 = false ;
}
V_14 = F_279 ( V_13 ) ;
if ( V_14 )
return V_14 ;
F_280 ( V_13 -> V_19 , & V_13 -> V_646 ) ;
return 0 ;
}
static void F_281 ( struct V_12 * V_13 )
{
if ( F_277 ( V_13 ) ) {
F_282 ( V_13 , L_6 ) ;
F_283 ( V_13 -> V_10 -> V_63 . V_2 , & V_13 -> V_11 ,
V_199 ) ;
}
}
void F_284 ( struct V_647 * V_648 )
{
struct V_12 * V_13 =
F_196 ( V_648 , struct V_12 ,
V_643 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
F_262 ( V_13 ) ;
F_21 ( & V_10 -> V_184 ) ;
F_21 ( & V_10 -> V_46 ) ;
if ( ! V_13 -> V_27 . V_263 )
goto V_649;
if ( ! F_17 ( V_13 ) )
goto V_649;
F_281 ( V_13 ) ;
V_649:
F_23 ( & V_10 -> V_46 ) ;
F_23 ( & V_10 -> V_184 ) ;
F_263 ( V_13 ) ;
}
static int F_285 ( struct V_12 * V_13 ,
struct V_650 * V_8 ,
T_1 * V_212 )
{
struct V_193 V_194 = {} ;
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_105 :
V_13 -> V_16 . V_198 . V_268 =
F_271 ( & V_8 -> V_651 ) ;
if ( ! V_13 -> V_16 . V_198 . V_268 )
return - V_200 ;
if ( V_8 -> V_220 <= 1 )
break;
if ( ( V_8 -> V_222 >
V_652 ) ||
( V_8 -> V_205 >
V_652 ) )
return - V_85 ;
V_194 . V_221 = V_8 -> V_221 ;
V_194 . V_204 = V_8 -> V_204 ;
V_194 . V_222 = V_8 -> V_222 ;
V_194 . V_205 = V_8 -> V_205 ;
V_194 . V_220 = V_8 -> V_220 ;
V_14 = F_102 ( V_13 , & V_8 -> V_653 , & V_194 ) ;
if ( V_14 < 0 ) {
F_114 ( V_13 -> V_16 . V_198 . V_268 ) ;
return V_14 ;
}
* V_212 |= V_14 ;
break;
case V_107 :
if ( ! V_13 -> V_27 . V_31 . V_654 )
return - V_85 ;
if ( V_8 -> V_182 . V_593 != V_13 -> V_16 . V_655 . V_182 . V_593 )
return - V_85 ;
switch ( V_8 -> V_182 . V_593 ) {
case V_656 :
if ( F_286 ( & V_8 -> V_182 ) !=
F_286 ( & V_13 -> V_16 . V_655 . V_182 ) )
return - V_85 ;
case V_657 :
case V_658 :
case V_594 :
case V_659 :
break;
default:
return - V_85 ;
}
if ( V_13 -> V_16 . V_655 . V_182 . V_660 -> V_323 !=
V_8 -> V_182 . V_660 -> V_323 )
return - V_85 ;
if ( V_8 -> V_220 > 1 ) {
V_14 = F_287 ( V_13 , V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_212 |= V_14 ;
}
F_288 ( V_13 , V_8 ) ;
break;
#ifdef F_55
case V_108 : {
struct V_423 * V_424 = & V_13 -> V_16 . V_109 ;
if ( V_8 -> V_182 . V_593 != V_13 -> V_27 . V_31 . V_182 . V_593 )
return - V_85 ;
if ( V_13 -> V_27 . V_31 . V_182 . V_660 -> V_323 !=
V_8 -> V_182 . V_660 -> V_323 )
return - V_85 ;
if ( V_424 -> V_661 == V_662 ) {
V_424 -> V_661 = V_663 ;
if ( ! V_424 -> V_664 )
V_424 -> V_664 = 1 ;
else
V_424 -> V_664 ++ ;
}
if ( V_8 -> V_220 > 1 ) {
V_14 = F_289 ( V_13 , V_8 ) ;
if ( V_14 < 0 ) {
V_424 -> V_661 = V_662 ;
return V_14 ;
}
* V_212 |= V_14 ;
}
if ( V_424 -> V_661 == V_663 )
F_288 ( V_13 , V_8 ) ;
break;
}
#endif
default:
return - V_53 ;
}
return 0 ;
}
static int
F_290 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_650 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_665 V_666 ;
struct V_667 * V_48 ;
struct V_668 * V_669 ;
T_1 V_212 = 0 ;
int V_14 ;
F_111 ( V_13 ) ;
F_41 ( & V_10 -> V_184 ) ;
if ( ! F_268 ( & V_10 -> V_633 ) || V_10 -> V_634 )
return - V_45 ;
if ( V_13 -> V_11 . V_272 )
return - V_45 ;
if ( F_91 ( & V_8 -> V_182 ,
& V_13 -> V_27 . V_31 . V_182 ) )
return - V_85 ;
if ( V_13 -> V_27 . V_263 )
return - V_45 ;
F_21 ( & V_10 -> V_46 ) ;
V_48 = F_92 ( V_13 -> V_27 . V_670 ,
F_93 ( & V_10 -> V_46 ) ) ;
if ( ! V_48 ) {
V_14 = - V_45 ;
goto V_129;
}
V_669 = F_196 ( V_48 , struct V_668 , V_48 ) ;
V_666 . V_671 = 0 ;
V_666 . V_672 = 0 ;
V_666 . V_673 = V_8 -> V_673 ;
V_666 . V_182 = V_8 -> V_182 ;
V_666 . V_220 = V_8 -> V_220 ;
V_14 = F_291 ( V_13 , & V_666 ) ;
if ( V_14 )
goto V_129;
V_14 = F_292 ( V_13 , & V_8 -> V_182 ,
V_669 -> V_674 ,
V_8 -> V_675 ) ;
if ( V_14 )
goto V_129;
V_14 = F_22 ( V_13 , NULL , V_669 -> V_674 , 0 ) ;
if ( V_14 ) {
F_293 ( V_13 ) ;
goto V_129;
}
V_14 = F_285 ( V_13 , V_8 , & V_212 ) ;
if ( V_14 ) {
F_293 ( V_13 ) ;
goto V_129;
}
V_13 -> V_646 = V_8 -> V_182 ;
V_13 -> V_266 = V_8 -> V_673 ;
V_13 -> V_27 . V_263 = true ;
if ( V_13 -> V_266 )
F_294 ( V_10 , V_13 ,
V_267 ) ;
F_295 ( V_13 -> V_19 , & V_13 -> V_646 ,
V_8 -> V_220 ) ;
if ( V_212 ) {
F_15 ( V_13 , V_212 ) ;
F_296 ( V_13 , & V_8 -> V_182 ) ;
} else {
F_281 ( V_13 ) ;
}
V_129:
F_23 ( & V_10 -> V_46 ) ;
return V_14 ;
}
int V_665 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_650 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_21 ( & V_10 -> V_184 ) ;
V_14 = F_290 ( V_2 , V_19 , V_8 ) ;
F_23 ( & V_10 -> V_184 ) ;
return V_14 ;
}
T_2 F_297 ( struct V_9 * V_10 )
{
F_41 ( & V_10 -> V_184 ) ;
V_10 -> V_676 ++ ;
if ( F_37 ( V_10 -> V_676 == 0 ) )
V_10 -> V_676 ++ ;
return V_10 -> V_676 ;
}
int F_298 ( struct V_9 * V_10 , struct V_280 * V_281 ,
T_2 * V_67 , T_8 V_677 )
{
unsigned long V_678 ;
struct V_280 * V_679 ;
int V_69 ;
V_679 = F_299 ( V_281 , V_677 ) ;
if ( ! V_679 )
return - V_200 ;
F_300 ( & V_10 -> V_680 , V_678 ) ;
V_69 = F_35 ( & V_10 -> V_681 , V_679 ,
1 , 0x10000 , V_65 ) ;
F_301 ( & V_10 -> V_680 , V_678 ) ;
if ( V_69 < 0 ) {
F_302 ( V_679 ) ;
return - V_200 ;
}
F_303 ( V_281 ) -> V_682 = V_69 ;
* V_67 = F_297 ( V_10 ) ;
F_303 ( V_679 ) -> V_683 . V_67 = * V_67 ;
return 0 ;
}
static void F_304 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_4 V_684 , bool V_685 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
switch ( V_684 ) {
case V_686 | V_687 :
if ( V_685 ) {
V_10 -> V_688 ++ ;
V_13 -> V_27 . V_688 ++ ;
} else {
if ( V_10 -> V_688 )
V_10 -> V_688 -- ;
if ( V_13 -> V_27 . V_688 )
V_13 -> V_27 . V_688 -- ;
}
if ( ! V_10 -> V_188 )
break;
if ( V_13 -> V_27 . V_688 == 1 )
F_305 ( V_10 , V_13 , V_689 ,
V_689 ) ;
else if ( V_13 -> V_27 . V_688 == 0 )
F_305 ( V_10 , V_13 , 0 ,
V_689 ) ;
F_19 ( V_10 ) ;
break;
default:
break;
}
}
static int F_306 ( struct V_2 * V_2 , T_1 V_690 , T_1 V_691 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_692 )
return - V_53 ;
return F_307 ( V_10 , V_690 , V_691 ) ;
}
static int F_308 ( struct V_2 * V_2 , T_1 * V_690 , T_1 * V_691 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_309 ( V_10 , V_690 , V_691 ) ;
}
static int F_310 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_693 * V_202 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_10 -> V_525 -> V_694 )
return - V_53 ;
F_311 ( V_10 , V_13 , V_202 ) ;
return 0 ;
}
static int F_312 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_695 , T_2 * V_67 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_696 * V_697 ;
struct V_280 * V_281 ;
int V_211 = sizeof( * V_697 ) ;
T_9 V_698 ;
bool V_699 ;
struct V_700 * V_701 ;
struct V_75 * V_24 ;
struct V_667 * V_670 ;
enum V_322 V_323 ;
int V_20 ;
F_21 ( & V_10 -> V_184 ) ;
F_63 () ;
V_670 = F_64 ( V_13 -> V_27 . V_670 ) ;
if ( F_37 ( ! V_670 ) ) {
V_20 = - V_85 ;
goto V_649;
}
V_323 = V_670 -> V_702 . V_660 -> V_323 ;
V_24 = F_52 ( V_13 , V_695 ) ;
if ( V_24 ) {
V_699 = V_24 -> V_24 . V_330 ;
} else {
V_20 = - V_703 ;
goto V_649;
}
if ( V_699 ) {
V_698 = F_313 ( V_704 |
V_705 |
V_706 ) ;
} else {
V_211 -= 2 ;
V_698 = F_313 ( V_704 |
V_707 |
V_706 ) ;
}
V_281 = F_125 ( V_10 -> V_63 . V_708 + V_211 ) ;
if ( ! V_281 ) {
V_20 = - V_200 ;
goto V_649;
}
V_281 -> V_19 = V_19 ;
F_314 ( V_281 , V_10 -> V_63 . V_708 ) ;
V_697 = ( void * ) F_126 ( V_281 , V_211 ) ;
V_697 -> V_709 = V_698 ;
V_697 -> V_710 = 0 ;
memcpy ( V_697 -> V_711 , V_24 -> V_24 . V_176 , V_177 ) ;
memcpy ( V_697 -> V_712 , V_13 -> V_27 . V_176 , V_177 ) ;
memcpy ( V_697 -> V_713 , V_13 -> V_27 . V_176 , V_177 ) ;
V_697 -> V_714 = 0 ;
V_701 = F_303 ( V_281 ) ;
V_701 -> V_6 |= V_715 |
V_716 ;
V_701 -> V_323 = V_323 ;
F_315 ( V_281 , V_717 ) ;
V_281 -> V_718 = 7 ;
if ( V_699 )
V_697 -> V_719 = F_313 ( 7 ) ;
V_20 = F_298 ( V_10 , V_281 , V_67 , V_65 ) ;
if ( V_20 ) {
F_302 ( V_281 ) ;
goto V_649;
}
F_316 () ;
F_317 ( V_13 , V_24 , V_281 ) ;
F_318 () ;
V_20 = 0 ;
V_649:
F_72 () ;
F_23 ( & V_10 -> V_184 ) ;
return V_20 ;
}
static int F_319 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_181 * V_182 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_667 * V_670 ;
int V_20 = - V_720 ;
F_63 () ;
V_670 = F_64 ( V_13 -> V_27 . V_670 ) ;
if ( V_670 ) {
* V_182 = V_13 -> V_27 . V_31 . V_182 ;
V_20 = 0 ;
} else if ( V_10 -> V_188 > 0 &&
V_10 -> V_188 == V_10 -> V_189 &&
V_13 -> V_27 . type == V_15 ) {
if ( V_10 -> V_186 )
* V_182 = V_10 -> V_183 ;
else
* V_182 = V_10 -> V_190 ;
V_20 = 0 ;
}
F_72 () ;
return V_20 ;
}
static void F_320 ( struct V_2 * V_2 , bool V_603 )
{
F_321 ( F_2 ( V_2 ) , V_603 ) ;
}
static int F_322 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_721 * V_722 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_723 * V_724 , * V_725 ;
if ( V_722 ) {
V_724 = F_99 ( sizeof( * V_724 ) , V_199 ) ;
if ( ! V_724 )
return - V_200 ;
memcpy ( & V_724 -> V_722 , V_722 , sizeof( * V_722 ) ) ;
} else {
V_724 = NULL ;
}
V_725 = F_98 ( V_13 -> V_722 , V_13 ) ;
F_100 ( V_13 -> V_722 , V_724 ) ;
if ( V_725 )
F_101 ( V_725 , V_206 ) ;
return 0 ;
}
static int F_323 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_181 * V_182 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
int V_20 ;
T_1 V_212 = 0 ;
V_20 = F_324 ( V_13 , V_182 , & V_212 ) ;
if ( V_20 == 0 )
F_15 ( V_13 , V_212 ) ;
return V_20 ;
}
static int F_325 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_726 , const T_3 * V_695 , T_3 V_727 ,
T_4 V_728 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_729 * V_730 = & V_13 -> V_16 . V_26 ;
int V_535 = V_731 [ V_727 ] ;
if ( V_13 -> V_27 . type != V_25 )
return - V_53 ;
if ( ! ( V_13 -> V_732 & F_132 ( V_727 ) ) )
return - V_85 ;
if ( V_730 -> V_733 [ V_535 ] . V_728 )
return - V_45 ;
if ( V_728 ) {
V_730 -> V_733 [ V_535 ] . V_728 = 32 * V_728 ;
V_730 -> V_733 [ V_535 ] . V_726 = V_726 ;
V_730 -> V_733 [ V_535 ] . V_727 = V_727 ;
}
return 0 ;
}
static int F_326 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_726 , const T_3 * V_695 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_729 * V_730 = & V_13 -> V_16 . V_26 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_535 ;
for ( V_535 = 0 ; V_535 < V_329 ; V_535 ++ ) {
struct V_734 * V_733 = & V_730 -> V_733 [ V_535 ] ;
if ( ! V_733 -> V_728 )
continue;
if ( V_733 -> V_726 != V_726 )
continue;
V_733 -> V_727 = - 1 ;
F_327 () ;
F_328 ( V_10 , V_13 , false ) ;
V_733 -> V_735 = V_736 ;
V_733 -> V_737 = false ;
F_329 ( V_13 ) ;
memset ( V_733 , 0 , sizeof( * V_733 ) ) ;
return 0 ;
}
return - V_100 ;
}
void F_330 ( struct V_586 * V_27 ,
T_3 V_738 ,
enum V_739 V_740 ,
T_8 V_677 )
{
struct V_12 * V_13 = F_273 ( V_27 ) ;
struct V_59 * V_68 ;
T_2 V_67 ;
if ( F_37 ( V_27 -> type != V_52 ) )
return;
F_34 ( & V_13 -> V_16 . V_49 . V_61 ) ;
V_68 = F_331 ( & V_13 -> V_16 . V_49 . V_62 , V_738 ) ;
if ( F_37 ( ! V_68 ) ) {
F_36 ( & V_13 -> V_16 . V_49 . V_61 ) ;
return;
}
V_67 = V_68 -> V_67 ;
F_39 ( & V_13 -> V_16 . V_49 . V_62 , V_738 ) ;
F_36 ( & V_13 -> V_16 . V_49 . V_61 ) ;
F_332 ( V_68 ) ;
F_333 ( F_334 ( V_27 ) , V_738 ,
V_740 , V_67 , V_677 ) ;
}
void F_335 ( struct V_586 * V_27 ,
struct V_741 * V_742 ,
T_8 V_677 )
{
struct V_12 * V_13 = F_273 ( V_27 ) ;
struct V_59 * V_68 ;
if ( F_37 ( V_27 -> type != V_52 ) )
return;
F_34 ( & V_13 -> V_16 . V_49 . V_61 ) ;
V_68 = F_331 ( & V_13 -> V_16 . V_49 . V_62 , V_742 -> V_738 ) ;
if ( F_37 ( ! V_68 ) ) {
F_36 ( & V_13 -> V_16 . V_49 . V_61 ) ;
return;
}
V_742 -> V_67 = V_68 -> V_67 ;
F_36 ( & V_13 -> V_16 . V_49 . V_61 ) ;
F_336 ( F_334 ( V_27 ) , V_742 , V_677 ) ;
}
