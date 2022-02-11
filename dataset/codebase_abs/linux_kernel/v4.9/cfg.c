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
if ( F_52 ( & V_13 -> V_27 ) )
V_24 = F_53 ( V_13 , V_73 ) ;
else
V_24 = F_54 ( V_13 , V_73 ) ;
if ( ! V_24 || ! F_55 ( V_24 , V_99 ) ) {
F_56 ( V_79 ) ;
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
if ( V_79 -> V_24 && F_55 ( V_79 -> V_24 , V_106 ) )
V_79 -> V_48 . V_6 |= V_104 ;
break;
case V_107 :
break;
case V_108 :
#ifdef F_57
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
F_58 ( 1 ) ;
break;
}
if ( V_24 )
V_24 -> V_119 = V_77 ;
V_14 = F_59 ( V_79 , V_13 , V_24 ) ;
V_101:
F_23 ( & V_10 -> V_98 ) ;
return V_14 ;
}
static int F_60 ( struct V_2 * V_2 , struct V_18 * V_19 ,
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
V_24 = F_54 ( V_13 , V_73 ) ;
if ( ! V_24 )
goto V_101;
if ( V_72 )
V_79 = F_61 ( V_10 , V_24 -> V_121 [ V_71 ] ) ;
else
V_79 = F_61 ( V_10 , V_24 -> V_122 [ V_71 ] ) ;
} else
V_79 = F_61 ( V_10 , V_13 -> V_123 [ V_71 ] ) ;
if ( ! V_79 ) {
V_20 = - V_100 ;
goto V_101;
}
F_62 ( V_79 , true ) ;
V_20 = 0 ;
V_101:
F_23 ( & V_10 -> V_120 ) ;
F_23 ( & V_10 -> V_98 ) ;
return V_20 ;
}
static int F_63 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_71 , bool V_72 , const T_3 * V_73 ,
void * V_67 ,
void (* F_64)( void * V_67 ,
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
F_65 () ;
if ( V_73 ) {
V_24 = F_54 ( V_13 , V_73 ) ;
if ( ! V_24 )
goto V_129;
if ( V_72 && V_71 < V_130 )
V_79 = F_66 ( V_24 -> V_121 [ V_71 ] ) ;
else if ( ! V_72 &&
V_71 < V_130 + V_131 )
V_79 = F_66 ( V_24 -> V_122 [ V_71 ] ) ;
} else
V_79 = F_66 ( V_13 -> V_123 [ V_71 ] ) ;
if ( ! V_79 )
goto V_129;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_80 = V_79 -> V_48 . V_80 ;
switch ( V_79 -> V_48 . V_80 ) {
case V_82 :
V_124 = F_67 ( & V_79 -> V_48 . V_132 ) ;
V_125 = F_68 ( V_124 ) ;
V_126 = F_69 ( V_124 ) ;
if ( V_79 -> V_6 & V_133 &&
! ( V_79 -> V_48 . V_6 & V_134 ) ) {
F_70 ( V_13 -> V_10 , V_79 , & V_128 ) ;
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
F_71 ( F_72 ( F_73 ( V_128 ) , V_136 ) !=
F_72 ( F_73 ( V_128 ) , V_137 ) ) ;
case V_90 :
case V_91 :
F_71 ( F_72 ( F_73 ( V_128 ) , V_136 ) !=
F_72 ( F_73 ( V_128 ) , V_138 ) ) ;
case V_92 :
case V_93 :
F_71 ( F_72 ( F_73 ( V_128 ) , V_136 ) !=
F_72 ( F_73 ( V_128 ) , V_139 ) ) ;
if ( V_79 -> V_6 & V_133 &&
! ( V_79 -> V_48 . V_6 & V_134 ) ) {
F_70 ( V_13 -> V_10 , V_79 , & V_128 ) ;
memcpy ( V_96 , V_128 . V_136 . V_140 , 6 ) ;
} else {
V_124 = F_67 ( & V_79 -> V_48 . V_132 ) ;
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
F_70 ( V_13 -> V_10 , V_79 , & V_128 ) ;
V_8 . V_96 = V_128 . V_63 . V_96 ;
V_8 . V_95 = V_128 . V_63 . V_95 ;
break;
}
V_8 . V_79 = V_79 -> V_48 . V_79 ;
V_8 . V_94 = V_79 -> V_48 . V_141 ;
F_64 ( V_67 , & V_8 ) ;
V_14 = 0 ;
V_129:
F_74 () ;
return V_14 ;
}
static int F_75 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_3 V_71 , bool V_142 ,
bool V_143 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_76 ( V_13 , V_71 , V_142 , V_143 ) ;
return 0 ;
}
static int F_77 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_3 V_71 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_78 ( V_13 , V_71 ) ;
return 0 ;
}
void F_79 ( struct V_75 * V_24 ,
const struct V_144 * V_145 ,
struct V_146 * V_147 )
{
V_147 -> V_6 = 0 ;
if ( V_145 -> V_6 & V_148 ) {
V_147 -> V_6 |= V_149 ;
V_147 -> V_150 = V_145 -> V_151 ;
} else if ( V_145 -> V_6 & V_152 ) {
V_147 -> V_6 |= V_153 ;
V_147 -> V_150 = F_80 ( V_145 ) ;
V_147 -> V_154 = F_81 ( V_145 ) ;
} else {
struct V_155 * V_156 ;
int V_157 = F_82 ( & V_24 -> V_13 -> V_27 ) ;
T_4 V_158 ;
V_156 = V_24 -> V_10 -> V_63 . V_2 -> V_159 [
F_83 ( V_24 -> V_13 ) ] ;
V_158 = V_156 -> V_160 [ V_145 -> V_151 ] . V_161 ;
V_147 -> V_162 = F_84 ( V_158 , 1 << V_157 ) ;
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
static int F_85 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_151 , T_3 * V_173 , struct V_174 * V_175 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_75 * V_24 ;
int V_20 = - V_100 ;
F_21 ( & V_10 -> V_98 ) ;
V_24 = F_86 ( V_13 , V_151 ) ;
if ( V_24 ) {
V_20 = 0 ;
memcpy ( V_173 , V_24 -> V_24 . V_176 , V_177 ) ;
F_87 ( V_24 , V_175 ) ;
}
F_23 ( & V_10 -> V_98 ) ;
return V_20 ;
}
static int F_88 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_151 , struct V_178 * V_179 )
{
struct V_9 * V_10 = F_89 ( V_19 -> V_180 ) ;
return F_90 ( V_10 , V_151 , V_179 ) ;
}
static int F_91 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_173 , struct V_174 * V_175 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_75 * V_24 ;
int V_20 = - V_100 ;
F_21 ( & V_10 -> V_98 ) ;
V_24 = F_54 ( V_13 , V_173 ) ;
if ( V_24 ) {
V_20 = 0 ;
F_87 ( V_24 , V_175 ) ;
}
F_23 ( & V_10 -> V_98 ) ;
return V_20 ;
}
static int F_92 ( struct V_2 * V_2 ,
struct V_181 * V_182 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
int V_20 = 0 ;
if ( F_93 ( & V_10 -> V_183 , V_182 ) )
return 0 ;
F_21 ( & V_10 -> V_184 ) ;
F_21 ( & V_10 -> V_185 ) ;
if ( V_10 -> V_186 ) {
V_13 = F_94 (
V_10 -> V_28 ,
F_95 ( & V_10 -> V_185 ) ) ;
if ( V_13 ) {
F_96 ( V_13 ) ;
V_20 = F_97 ( V_13 , V_182 ,
V_187 ) ;
}
} else if ( V_10 -> V_188 == V_10 -> V_189 ) {
V_10 -> V_190 = * V_182 ;
F_98 ( V_10 , 0 ) ;
}
if ( V_20 == 0 )
V_10 -> V_183 = * V_182 ;
F_23 ( & V_10 -> V_185 ) ;
F_23 ( & V_10 -> V_184 ) ;
return V_20 ;
}
static int F_99 ( struct V_12 * V_13 ,
const T_3 * V_191 , T_5 V_192 ,
const struct V_193 * V_194 )
{
struct V_195 * V_196 , * V_197 ;
if ( ! V_191 || ! V_192 )
return 1 ;
V_197 = F_100 ( V_13 -> V_16 . V_198 . V_195 , V_13 ) ;
V_196 = F_101 ( sizeof( struct V_195 ) + V_192 , V_199 ) ;
if ( ! V_196 )
return - V_200 ;
V_196 -> V_201 = V_192 ;
memcpy ( V_196 -> V_202 , V_191 , V_192 ) ;
if ( V_194 )
memcpy ( V_196 -> V_203 , V_194 -> V_204 ,
V_194 -> V_205 *
sizeof( V_196 -> V_203 [ 0 ] ) ) ;
F_102 ( V_13 -> V_16 . V_198 . V_195 , V_196 ) ;
if ( V_197 )
F_103 ( V_197 , V_206 ) ;
return 0 ;
}
static int F_104 ( struct V_12 * V_13 ,
struct V_207 * V_8 ,
const struct V_193 * V_194 )
{
struct V_208 * V_196 , * V_197 ;
int V_209 , V_210 ;
int V_211 , V_14 ;
T_1 V_212 = V_213 ;
V_197 = F_100 ( V_13 -> V_16 . V_198 . V_214 , V_13 ) ;
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
V_196 = F_101 ( V_211 , V_199 ) ;
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
V_14 = F_99 ( V_13 , V_8 -> V_195 ,
V_8 -> V_223 , V_194 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == 0 )
V_212 |= V_224 ;
F_102 ( V_13 -> V_16 . V_198 . V_214 , V_196 ) ;
if ( V_197 )
F_103 ( V_197 , V_206 ) ;
return V_212 ;
}
static int F_105 ( struct V_2 * V_2 , struct V_18 * V_19 ,
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
V_197 = F_100 ( V_13 -> V_16 . V_198 . V_214 , V_13 ) ;
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
F_21 ( & V_10 -> V_184 ) ;
V_14 = F_97 ( V_13 , & V_8 -> V_182 ,
V_241 ) ;
if ( ! V_14 )
F_106 ( V_13 , false ) ;
F_23 ( & V_10 -> V_184 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_242 = V_8 -> V_243 . V_244 ;
V_13 -> V_245 = V_8 -> V_243 . V_245 ;
V_13 -> V_246 = F_107 ( V_13 -> V_10 ,
& V_8 -> V_243 ,
V_13 -> V_27 . type ) ;
F_108 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_23 -> V_242 =
V_8 -> V_243 . V_244 ;
V_23 -> V_245 =
V_8 -> V_243 . V_245 ;
V_23 -> V_246 =
F_107 ( V_13 -> V_10 ,
& V_8 -> V_243 ,
V_23 -> V_27 . type ) ;
}
V_13 -> V_27 . V_31 . V_247 = V_8 -> V_248 ;
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
V_14 = F_104 ( V_13 , & V_8 -> V_214 , NULL ) ;
if ( V_14 < 0 ) {
F_96 ( V_13 ) ;
return V_14 ;
}
V_212 |= V_14 ;
V_14 = F_109 ( V_13 -> V_10 , V_13 ) ;
if ( V_14 ) {
V_197 = F_100 ( V_13 -> V_16 . V_198 . V_214 , V_13 ) ;
if ( V_197 )
F_103 ( V_197 , V_206 ) ;
F_11 ( V_13 -> V_16 . V_198 . V_214 , NULL ) ;
F_96 ( V_13 ) ;
return V_14 ;
}
F_110 ( V_10 , V_13 ) ;
F_15 ( V_13 , V_212 ) ;
F_111 ( V_19 ) ;
F_108 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_111 ( V_23 -> V_19 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_207 * V_8 )
{
struct V_12 * V_13 ;
struct V_208 * V_197 ;
int V_14 ;
V_13 = F_9 ( V_19 ) ;
F_113 ( V_13 ) ;
if ( V_13 -> V_27 . V_263 )
return - V_45 ;
V_197 = F_100 ( V_13 -> V_16 . V_198 . V_214 , V_13 ) ;
if ( ! V_197 )
return - V_100 ;
V_14 = F_104 ( V_13 , V_8 , NULL ) ;
if ( V_14 < 0 )
return V_14 ;
F_15 ( V_13 , V_14 ) ;
return 0 ;
}
static int F_114 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_12 * V_23 ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_208 * V_264 ;
struct V_195 * V_265 ;
struct V_181 V_182 ;
F_113 ( V_13 ) ;
V_264 = F_100 ( V_13 -> V_16 . V_198 . V_214 , V_13 ) ;
if ( ! V_264 )
return - V_100 ;
V_265 = F_100 ( V_13 -> V_16 . V_198 . V_195 , V_13 ) ;
F_21 ( & V_10 -> V_184 ) ;
V_13 -> V_27 . V_263 = false ;
if ( V_13 -> V_266 ) {
F_115 ( V_10 , V_13 ,
V_267 ) ;
V_13 -> V_266 = false ;
}
F_23 ( & V_10 -> V_184 ) ;
F_116 ( V_13 -> V_16 . V_198 . V_268 ) ;
V_13 -> V_16 . V_198 . V_268 = NULL ;
F_108 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_117 ( V_23 -> V_19 ) ;
F_117 ( V_19 ) ;
F_11 ( V_13 -> V_16 . V_198 . V_214 , NULL ) ;
F_11 ( V_13 -> V_16 . V_198 . V_195 , NULL ) ;
F_103 ( V_264 , V_206 ) ;
if ( V_265 )
F_103 ( V_265 , V_206 ) ;
V_13 -> V_16 . V_198 . V_269 = V_234 ;
F_118 ( V_13 , true ) ;
F_119 ( V_13 , true ) ;
V_13 -> V_27 . V_31 . V_250 = false ;
V_13 -> V_27 . V_31 . V_253 = 0 ;
F_120 ( V_270 , & V_13 -> V_271 ) ;
F_15 ( V_13 , V_227 ) ;
if ( V_13 -> V_11 . V_272 ) {
V_182 = V_13 -> V_27 . V_31 . V_182 ;
F_121 ( & V_13 -> V_273 ) ;
F_122 ( V_13 -> V_19 , & V_182 ,
V_274 ,
V_199 ) ;
}
F_123 ( V_13 -> V_10 , V_13 ) ;
V_10 -> V_275 -= F_124 ( & V_13 -> V_16 . V_198 . V_276 . V_277 ) ;
F_125 ( & V_10 -> V_63 , & V_13 -> V_16 . V_198 . V_276 . V_277 ) ;
F_21 ( & V_10 -> V_184 ) ;
F_106 ( V_13 , true ) ;
F_96 ( V_13 ) ;
F_23 ( & V_10 -> V_184 ) ;
return 0 ;
}
static void F_126 ( struct V_75 * V_24 )
{
struct V_278 * V_279 ;
struct V_280 * V_281 ;
V_281 = F_127 ( sizeof( * V_279 ) ) ;
if ( ! V_281 )
return;
V_279 = (struct V_278 * ) F_128 ( V_281 , sizeof( * V_279 ) ) ;
F_129 ( V_279 -> V_282 ) ;
memcpy ( V_279 -> V_283 , V_24 -> V_24 . V_176 , V_177 ) ;
V_279 -> V_201 = F_130 ( 6 ) ;
V_279 -> V_284 = 0 ;
V_279 -> V_285 = 0x01 ;
V_279 -> V_286 = 0xaf ;
V_279 -> V_287 [ 0 ] = 0x81 ;
V_279 -> V_287 [ 1 ] = 1 ;
V_279 -> V_287 [ 2 ] = 0 ;
V_281 -> V_19 = V_24 -> V_13 -> V_19 ;
V_281 -> V_288 = F_131 ( V_281 , V_24 -> V_13 -> V_19 ) ;
memset ( V_281 -> V_289 , 0 , sizeof( V_281 -> V_289 ) ) ;
F_132 ( V_281 ) ;
}
static int F_133 ( struct V_9 * V_10 ,
struct V_75 * V_24 ,
T_1 V_42 , T_1 V_290 )
{
int V_20 ;
if ( V_42 & F_134 ( V_291 ) &&
V_290 & F_134 ( V_291 ) &&
! F_55 ( V_24 , V_292 ) ) {
V_20 = F_135 ( V_24 , V_293 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_42 & F_134 ( V_294 ) &&
V_290 & F_134 ( V_294 ) &&
! F_55 ( V_24 , V_99 ) ) {
if ( ! F_55 ( V_24 , V_295 ) )
F_136 ( V_24 ) ;
V_20 = F_135 ( V_24 , V_296 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_42 & F_134 ( V_297 ) ) {
if ( V_290 & F_134 ( V_297 ) )
V_20 = F_135 ( V_24 , V_298 ) ;
else if ( F_55 ( V_24 , V_299 ) )
V_20 = F_135 ( V_24 , V_296 ) ;
else
V_20 = 0 ;
if ( V_20 )
return V_20 ;
}
if ( V_42 & F_134 ( V_294 ) &&
! ( V_290 & F_134 ( V_294 ) ) &&
F_55 ( V_24 , V_99 ) ) {
V_20 = F_135 ( V_24 , V_293 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_42 & F_134 ( V_291 ) &&
! ( V_290 & F_134 ( V_291 ) ) &&
F_55 ( V_24 , V_292 ) ) {
V_20 = F_135 ( V_24 , V_300 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static void F_137 ( struct V_9 * V_10 ,
struct V_75 * V_24 ,
struct V_301 * V_8 )
{
#ifdef F_57
struct V_12 * V_13 = V_24 -> V_13 ;
T_1 V_212 = 0 ;
if ( V_8 -> V_302 & V_303 ) {
switch ( V_8 -> V_304 ) {
case V_305 :
if ( V_24 -> V_109 -> V_304 != V_305 )
V_212 = F_138 ( V_13 ) ;
V_24 -> V_109 -> V_304 = V_8 -> V_304 ;
V_24 -> V_109 -> V_306 = V_8 -> V_307 ;
F_139 ( V_24 ) ;
V_212 |= F_140 ( V_24 ,
V_13 -> V_16 . V_109 . V_308 . V_309 ) ;
break;
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
if ( V_24 -> V_109 -> V_304 == V_305 )
V_212 = F_141 ( V_13 ) ;
V_24 -> V_109 -> V_304 = V_8 -> V_304 ;
F_139 ( V_24 ) ;
V_212 |= F_140 ( V_24 ,
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
V_212 |= F_142 ( V_24 ) ;
break;
case V_320 :
V_212 |= F_143 ( V_24 ) ;
break;
}
if ( V_8 -> V_321 )
V_212 |= F_140 ( V_24 ,
V_8 -> V_321 ) ;
F_144 ( V_13 , V_212 ) ;
#endif
}
static int F_145 ( struct V_9 * V_10 ,
struct V_75 * V_24 ,
struct V_301 * V_8 )
{
int V_20 = 0 ;
struct V_155 * V_156 ;
struct V_12 * V_13 = V_24 -> V_13 ;
enum V_322 V_323 = F_83 ( V_13 ) ;
T_1 V_42 , V_290 ;
V_156 = V_10 -> V_63 . V_2 -> V_159 [ V_323 ] ;
V_42 = V_8 -> V_324 ;
V_290 = V_8 -> V_325 ;
if ( F_52 ( & V_13 -> V_27 ) ) {
if ( V_42 & F_134 ( V_291 ) )
V_42 |= F_134 ( V_294 ) ;
if ( V_290 & F_134 ( V_291 ) )
V_290 |= F_134 ( V_294 ) ;
} else if ( F_55 ( V_24 , V_326 ) ) {
if ( V_290 & F_134 ( V_297 ) ) {
V_290 |= F_134 ( V_291 ) |
F_134 ( V_294 ) ;
V_42 |= F_134 ( V_291 ) |
F_134 ( V_294 ) ;
}
}
if ( V_42 & F_134 ( V_327 ) &&
V_10 -> V_63 . V_328 >= V_329 )
V_24 -> V_24 . V_330 = V_290 & F_134 ( V_327 ) ;
if ( ! F_55 ( V_24 , V_326 ) &&
! ( ( V_42 & F_134 ( V_294 ) ) &&
( V_290 & F_134 ( V_294 ) ) ) ) {
V_20 = F_133 ( V_10 , V_24 , V_42 , V_290 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_42 & F_134 ( V_331 ) ) {
if ( V_290 & F_134 ( V_331 ) )
F_146 ( V_24 , V_332 ) ;
else
F_147 ( V_24 , V_332 ) ;
}
if ( V_42 & F_134 ( V_333 ) ) {
V_24 -> V_24 . V_102 = ! ! ( V_290 & F_134 ( V_333 ) ) ;
if ( V_290 & F_134 ( V_333 ) )
F_146 ( V_24 , V_106 ) ;
else
F_147 ( V_24 , V_106 ) ;
}
if ( V_42 & F_134 ( V_334 ) ) {
if ( V_290 & F_134 ( V_334 ) )
F_146 ( V_24 , V_326 ) ;
else
F_147 ( V_24 , V_326 ) ;
}
if ( F_55 ( V_24 , V_326 ) &&
! V_13 -> V_16 . V_26 . V_335 &&
V_8 -> V_336 >= 4 &&
V_8 -> V_337 [ 3 ] & V_338 )
F_146 ( V_24 , V_339 ) ;
if ( F_55 ( V_24 , V_326 ) &&
! V_13 -> V_16 . V_26 . V_340 &&
F_148 ( & V_10 -> V_63 , V_341 ) &&
V_8 -> V_336 >= 8 &&
V_8 -> V_337 [ 7 ] & V_342 )
F_146 ( V_24 , V_343 ) ;
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
F_149 ( & V_13 -> V_27 . V_31 . V_182 ,
V_156 , V_8 -> V_353 ,
V_8 -> V_354 ,
& V_24 -> V_24 . V_355 [ V_323 ] ) ;
}
if ( V_8 -> V_356 )
F_150 ( V_13 , V_156 ,
V_8 -> V_356 , V_24 ) ;
if ( V_8 -> V_357 )
F_151 ( V_13 , V_156 ,
V_8 -> V_357 , V_24 ) ;
if ( V_8 -> V_358 ) {
F_152 ( V_13 , V_24 ,
V_8 -> V_359 , V_323 ) ;
}
if ( V_8 -> V_360 >= 0 )
V_24 -> V_24 . V_360 = V_8 -> V_360 ;
if ( F_52 ( & V_13 -> V_27 ) )
F_137 ( V_10 , V_24 , V_8 ) ;
if ( F_55 ( V_24 , V_326 ) ||
V_290 & F_134 ( V_294 ) ) {
V_20 = F_133 ( V_10 , V_24 , V_42 , V_290 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_153 ( struct V_2 * V_2 , struct V_18 * V_19 ,
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
if ( F_154 ( V_173 , V_13 -> V_27 . V_176 ) )
return - V_85 ;
if ( F_155 ( V_173 ) )
return - V_85 ;
V_24 = F_156 ( V_13 , V_173 , V_199 ) ;
if ( ! V_24 )
return - V_200 ;
if ( V_8 -> V_325 & F_134 ( V_334 ) )
V_24 -> V_24 . V_362 = true ;
V_14 = F_145 ( V_10 , V_24 , V_8 ) ;
if ( V_14 ) {
F_157 ( V_10 , V_24 ) ;
return V_14 ;
}
if ( ! F_55 ( V_24 , V_326 ) &&
F_55 ( V_24 , V_99 ) )
F_136 ( V_24 ) ;
V_361 = V_13 -> V_27 . type == V_21 ||
V_13 -> V_27 . type == V_105 ;
V_14 = F_158 ( V_24 ) ;
if ( V_14 ) {
F_74 () ;
return V_14 ;
}
if ( V_361 )
F_126 ( V_24 ) ;
F_74 () ;
return 0 ;
}
static int F_159 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_363 * V_8 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
if ( V_8 -> V_173 )
return F_160 ( V_13 , V_8 -> V_173 ) ;
F_161 ( V_13 ) ;
return 0 ;
}
static int F_162 ( struct V_2 * V_2 ,
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
V_24 = F_54 ( V_13 , V_173 ) ;
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
if ( ! F_55 ( V_24 , V_326 ) ) {
V_366 = V_372 ;
break;
}
if ( F_55 ( V_24 , V_299 ) )
V_366 = V_373 ;
else
V_366 = V_374 ;
break;
case V_105 :
case V_21 :
if ( F_55 ( V_24 , V_99 ) )
V_366 = V_375 ;
else
V_366 = V_376 ;
break;
default:
V_14 = - V_53 ;
goto V_367;
}
V_14 = F_163 ( V_2 , V_8 , V_366 ) ;
if ( V_14 )
goto V_367;
if ( V_8 -> V_23 && V_8 -> V_23 != V_24 -> V_13 -> V_19 ) {
bool V_377 = false ;
bool V_378 = false ;
V_364 = F_9 ( V_8 -> V_23 ) ;
if ( V_8 -> V_23 -> V_180 -> V_22 ) {
if ( V_364 -> V_16 . V_23 . V_24 ) {
V_14 = - V_45 ;
goto V_367;
}
F_102 ( V_364 -> V_16 . V_23 . V_24 , V_24 ) ;
V_378 = true ;
F_164 ( V_364 ) ;
}
if ( V_24 -> V_13 -> V_27 . type == V_21 &&
V_24 -> V_13 -> V_16 . V_23 . V_24 ) {
F_11 ( V_24 -> V_13 -> V_16 . V_23 . V_24 , NULL ) ;
V_377 = true ;
}
V_24 -> V_13 = V_364 ;
F_165 ( V_24 ) ;
if ( V_24 -> V_379 == V_298 &&
V_377 != V_378 ) {
if ( V_378 )
F_166 ( & V_24 -> V_13 -> V_380 -> V_381 ) ;
else
F_167 ( & V_24 -> V_13 -> V_380 -> V_381 ) ;
}
F_126 ( V_24 ) ;
}
V_14 = F_145 ( V_10 , V_24 , V_8 ) ;
if ( V_14 )
goto V_367;
F_23 ( & V_10 -> V_98 ) ;
if ( ( V_13 -> V_27 . type == V_105 ||
V_13 -> V_27 . type == V_21 ) &&
V_24 -> V_382 != V_24 -> V_13 -> V_380 -> V_383 &&
F_55 ( V_24 , V_299 ) &&
F_168 ( V_24 ) != 1 ) {
F_169 ( V_24 -> V_13 ,
L_1 ,
V_24 -> V_24 . V_176 ) ;
F_170 ( V_24 -> V_13 ,
V_24 -> V_13 -> V_380 -> V_383 ,
V_24 -> V_24 . V_176 ,
V_24 -> V_13 -> V_27 . V_31 . V_384 ) ;
}
if ( V_13 -> V_27 . type == V_25 &&
V_8 -> V_324 & F_134 ( V_297 ) ) {
F_171 ( V_10 ) ;
F_172 ( V_13 ) ;
}
return 0 ;
V_367:
F_23 ( & V_10 -> V_98 ) ;
return V_14 ;
}
static int F_173 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_385 , const T_3 * V_386 )
{
struct V_12 * V_13 ;
struct V_387 * V_388 ;
struct V_75 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_65 () ;
V_24 = F_53 ( V_13 , V_386 ) ;
if ( ! V_24 ) {
F_74 () ;
return - V_100 ;
}
V_388 = F_174 ( V_13 , V_385 ) ;
if ( F_48 ( V_388 ) ) {
F_74 () ;
return F_51 ( V_388 ) ;
}
F_175 ( V_388 , V_24 ) ;
F_74 () ;
return 0 ;
}
static int F_176 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_385 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( V_385 )
return F_177 ( V_13 , V_385 ) ;
F_178 ( V_13 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_385 , const T_3 * V_386 )
{
struct V_12 * V_13 ;
struct V_387 * V_388 ;
struct V_75 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_65 () ;
V_24 = F_53 ( V_13 , V_386 ) ;
if ( ! V_24 ) {
F_74 () ;
return - V_100 ;
}
V_388 = F_180 ( V_13 , V_385 ) ;
if ( ! V_388 ) {
F_74 () ;
return - V_100 ;
}
F_175 ( V_388 , V_24 ) ;
F_74 () ;
return 0 ;
}
static void F_181 ( struct V_387 * V_388 , T_3 * V_386 ,
struct V_389 * V_390 )
{
struct V_75 * V_391 = F_66 ( V_388 -> V_386 ) ;
if ( V_391 )
memcpy ( V_386 , V_391 -> V_24 . V_176 , V_177 ) ;
else
F_182 ( V_386 ) ;
memset ( V_390 , 0 , sizeof( * V_390 ) ) ;
V_390 -> V_392 = V_388 -> V_13 -> V_16 . V_109 . V_393 ;
V_390 -> V_394 = V_395 |
V_396 |
V_397 |
V_398 |
V_399 |
V_400 |
V_401 ;
V_390 -> V_402 = V_388 -> V_403 . V_404 ;
V_390 -> V_405 = V_388 -> V_405 ;
V_390 -> V_406 = V_388 -> V_406 ;
if ( F_183 ( V_407 , V_388 -> V_408 ) )
V_390 -> V_409 = F_184 ( V_388 -> V_408 - V_407 ) ;
V_390 -> V_410 =
F_184 ( V_388 -> V_410 ) ;
V_390 -> V_411 = V_388 -> V_411 ;
if ( V_388 -> V_6 & V_412 )
V_390 -> V_6 |= V_413 ;
if ( V_388 -> V_6 & V_414 )
V_390 -> V_6 |= V_415 ;
if ( V_388 -> V_6 & V_416 )
V_390 -> V_6 |= V_417 ;
if ( V_388 -> V_6 & V_418 )
V_390 -> V_6 |= V_419 ;
if ( V_388 -> V_6 & V_420 )
V_390 -> V_6 |= V_421 ;
}
static int F_185 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_385 , T_3 * V_386 , struct V_389 * V_390 )
{
struct V_12 * V_13 ;
struct V_387 * V_388 ;
V_13 = F_9 ( V_19 ) ;
F_65 () ;
V_388 = F_180 ( V_13 , V_385 ) ;
if ( ! V_388 ) {
F_74 () ;
return - V_100 ;
}
memcpy ( V_385 , V_388 -> V_385 , V_177 ) ;
F_181 ( V_388 , V_386 , V_390 ) ;
F_74 () ;
return 0 ;
}
static int F_186 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_151 , T_3 * V_385 , T_3 * V_386 ,
struct V_389 * V_390 )
{
struct V_12 * V_13 ;
struct V_387 * V_388 ;
V_13 = F_9 ( V_19 ) ;
F_65 () ;
V_388 = F_187 ( V_13 , V_151 ) ;
if ( ! V_388 ) {
F_74 () ;
return - V_100 ;
}
memcpy ( V_385 , V_388 -> V_385 , V_177 ) ;
F_181 ( V_388 , V_386 , V_390 ) ;
F_74 () ;
return 0 ;
}
static void F_188 ( struct V_387 * V_388 , T_3 * V_422 ,
struct V_389 * V_390 )
{
memset ( V_390 , 0 , sizeof( * V_390 ) ) ;
memcpy ( V_422 , V_388 -> V_422 , V_177 ) ;
V_390 -> V_392 = V_388 -> V_13 -> V_16 . V_109 . V_423 ;
}
static int F_189 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_385 , T_3 * V_422 , struct V_389 * V_390 )
{
struct V_12 * V_13 ;
struct V_387 * V_388 ;
V_13 = F_9 ( V_19 ) ;
F_65 () ;
V_388 = F_190 ( V_13 , V_385 ) ;
if ( ! V_388 ) {
F_74 () ;
return - V_100 ;
}
memcpy ( V_385 , V_388 -> V_385 , V_177 ) ;
F_188 ( V_388 , V_422 , V_390 ) ;
F_74 () ;
return 0 ;
}
static int F_191 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_151 , T_3 * V_385 , T_3 * V_422 ,
struct V_389 * V_390 )
{
struct V_12 * V_13 ;
struct V_387 * V_388 ;
V_13 = F_9 ( V_19 ) ;
F_65 () ;
V_388 = F_192 ( V_13 , V_151 ) ;
if ( ! V_388 ) {
F_74 () ;
return - V_100 ;
}
memcpy ( V_385 , V_388 -> V_385 , V_177 ) ;
F_188 ( V_388 , V_422 , V_390 ) ;
F_74 () ;
return 0 ;
}
static int F_193 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_424 * V_48 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
memcpy ( V_48 , & ( V_13 -> V_16 . V_109 . V_308 ) , sizeof( struct V_424 ) ) ;
return 0 ;
}
static inline bool F_194 ( enum V_425 V_426 , T_1 V_42 )
{
return ( V_42 >> ( V_426 - 1 ) ) & 0x1 ;
}
static int F_195 ( struct V_427 * V_428 ,
const struct V_429 * V_430 )
{
T_3 * V_431 ;
const T_3 * V_432 ;
struct V_12 * V_13 = F_196 ( V_428 ,
struct V_12 , V_16 . V_109 ) ;
V_431 = NULL ;
V_432 = V_428 -> V_433 ;
if ( V_430 -> V_434 ) {
V_431 = F_197 ( V_430 -> V_433 , V_430 -> V_434 ,
V_199 ) ;
if ( ! V_431 )
return - V_200 ;
}
V_428 -> V_434 = V_430 -> V_434 ;
V_428 -> V_433 = V_431 ;
F_116 ( V_432 ) ;
V_428 -> V_435 = V_430 -> V_435 ;
memcpy ( V_428 -> V_436 , V_430 -> V_436 , V_428 -> V_435 ) ;
V_428 -> V_437 = V_430 -> V_438 ;
V_428 -> V_439 = V_430 -> V_440 ;
V_428 -> V_441 = V_430 -> V_442 ;
V_428 -> V_368 = V_430 -> V_368 ;
V_428 -> V_443 = V_430 -> V_444 ;
V_428 -> V_110 = V_111 ;
if ( V_430 -> V_445 )
V_428 -> V_110 |= V_446 ;
if ( V_430 -> V_447 )
V_428 -> V_110 |= V_448 ;
memcpy ( V_13 -> V_27 . V_31 . V_449 , V_430 -> V_449 ,
sizeof( V_430 -> V_449 ) ) ;
V_13 -> V_27 . V_31 . V_450 = V_430 -> V_450 ;
V_13 -> V_27 . V_31 . V_247 = V_430 -> V_248 ;
V_13 -> V_27 . V_31 . V_249 = V_430 -> V_249 ;
return 0 ;
}
static int F_198 ( struct V_2 * V_2 ,
struct V_18 * V_19 , T_1 V_42 ,
const struct V_424 * V_451 )
{
struct V_424 * V_48 ;
struct V_12 * V_13 ;
struct V_427 * V_428 ;
V_13 = F_9 ( V_19 ) ;
V_428 = & V_13 -> V_16 . V_109 ;
V_48 = & ( V_13 -> V_16 . V_109 . V_308 ) ;
if ( F_194 ( V_452 , V_42 ) )
V_48 -> V_453 = V_451 -> V_453 ;
if ( F_194 ( V_454 , V_42 ) )
V_48 -> V_455 = V_451 -> V_455 ;
if ( F_194 ( V_456 , V_42 ) )
V_48 -> V_457 = V_451 -> V_457 ;
if ( F_194 ( V_458 , V_42 ) )
V_48 -> V_459 = V_451 -> V_459 ;
if ( F_194 ( V_460 , V_42 ) )
V_48 -> V_461 = V_451 -> V_461 ;
if ( F_194 ( V_462 , V_42 ) )
V_48 -> V_463 = V_451 -> V_463 ;
if ( F_194 ( V_464 , V_42 ) )
V_48 -> V_465 = V_451 -> V_465 ;
if ( F_194 ( V_466 , V_42 ) ) {
if ( V_428 -> V_368 )
return - V_45 ;
V_48 -> V_467 = V_451 -> V_467 ;
}
if ( F_194 ( V_468 , V_42 ) )
V_48 -> V_469 =
V_451 -> V_469 ;
if ( F_194 ( V_470 , V_42 ) )
V_48 -> V_471 =
V_451 -> V_471 ;
if ( F_194 ( V_472 , V_42 ) )
V_48 -> V_473 = V_451 -> V_473 ;
if ( F_194 ( V_474 , V_42 ) )
V_48 -> V_475 = V_451 -> V_475 ;
if ( F_194 ( V_476 , V_42 ) )
V_48 -> V_477 =
V_451 -> V_477 ;
if ( F_194 ( V_478 , V_42 ) )
V_48 -> V_479 =
V_451 -> V_479 ;
if ( F_194 ( V_480 , V_42 ) )
V_48 -> V_481 =
V_451 -> V_481 ;
if ( F_194 ( V_482 ,
V_42 ) )
V_48 -> V_483 =
V_451 -> V_483 ;
if ( F_194 ( V_484 , V_42 ) ) {
V_48 -> V_485 = V_451 -> V_485 ;
F_199 ( V_428 ) ;
}
if ( F_194 ( V_486 , V_42 ) ) {
if ( V_451 -> V_487 &&
! ( V_48 -> V_485 > V_488 ) ) {
V_48 -> V_485 = V_489 ;
F_199 ( V_428 ) ;
}
V_48 -> V_487 =
V_451 -> V_487 ;
}
if ( F_194 ( V_490 , V_42 ) )
V_48 -> V_491 =
V_451 -> V_491 ;
if ( F_194 ( V_492 , V_42 ) )
V_48 -> V_493 = V_451 -> V_493 ;
if ( F_194 ( V_494 , V_42 ) ) {
if ( ! F_148 ( & V_13 -> V_10 -> V_63 , V_495 ) )
return - V_496 ;
V_48 -> V_497 = V_451 -> V_497 ;
}
if ( F_194 ( V_498 , V_42 ) ) {
V_48 -> V_499 = V_451 -> V_499 ;
V_13 -> V_27 . V_31 . V_500 = V_451 -> V_499 ;
F_15 ( V_13 , V_501 ) ;
}
if ( F_194 ( V_502 , V_42 ) )
V_48 -> V_503 =
V_451 -> V_503 ;
if ( F_194 ( V_504 , V_42 ) )
V_48 -> V_505 =
V_451 -> V_505 ;
if ( F_194 ( V_506 , V_42 ) )
V_48 -> V_507 =
V_451 -> V_507 ;
if ( F_194 ( V_508 , V_42 ) ) {
V_48 -> V_309 = V_451 -> V_309 ;
F_200 ( V_13 ) ;
}
if ( F_194 ( V_509 , V_42 ) )
V_48 -> V_510 =
V_451 -> V_510 ;
if ( F_194 ( V_511 , V_42 ) )
V_48 -> V_512 = V_451 -> V_512 ;
F_144 ( V_13 , V_213 ) ;
return 0 ;
}
static int F_201 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const struct V_424 * V_48 ,
const struct V_429 * V_430 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_427 * V_428 = & V_13 -> V_16 . V_109 ;
int V_14 ;
memcpy ( & V_428 -> V_308 , V_48 , sizeof( struct V_424 ) ) ;
V_14 = F_195 ( V_428 , V_430 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_232 = V_234 ;
V_13 -> V_239 = V_13 -> V_10 -> V_240 ;
F_21 ( & V_13 -> V_10 -> V_184 ) ;
V_14 = F_97 ( V_13 , & V_430 -> V_182 ,
V_241 ) ;
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
F_96 ( V_13 ) ;
F_23 ( & V_13 -> V_10 -> V_184 ) ;
return 0 ;
}
static int F_205 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_513 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
enum V_322 V_323 ;
T_1 V_212 = 0 ;
if ( ! F_100 ( V_13 -> V_16 . V_198 . V_214 , V_13 ) )
return - V_100 ;
V_323 = F_83 ( V_13 ) ;
if ( V_8 -> V_514 >= 0 ) {
V_13 -> V_27 . V_31 . V_514 = V_8 -> V_514 ;
V_212 |= V_515 ;
}
if ( V_8 -> V_516 >= 0 ) {
V_13 -> V_27 . V_31 . V_516 =
V_8 -> V_516 ;
V_212 |= V_517 ;
}
if ( ! V_13 -> V_27 . V_31 . V_518 &&
V_323 == V_519 ) {
V_13 -> V_27 . V_31 . V_518 = true ;
V_212 |= V_520 ;
}
if ( V_8 -> V_521 >= 0 ) {
V_13 -> V_27 . V_31 . V_518 =
V_8 -> V_521 ;
V_212 |= V_520 ;
}
if ( V_8 -> V_450 ) {
F_149 ( & V_13 -> V_27 . V_31 . V_182 ,
V_2 -> V_159 [ V_323 ] ,
V_8 -> V_450 ,
V_8 -> V_522 ,
& V_13 -> V_27 . V_31 . V_450 ) ;
V_212 |= V_523 ;
}
if ( V_8 -> V_524 >= 0 ) {
if ( V_8 -> V_524 )
V_13 -> V_6 |= V_525 ;
else
V_13 -> V_6 &= ~ V_525 ;
F_12 ( V_13 ) ;
}
if ( V_8 -> V_499 >= 0 ) {
V_13 -> V_27 . V_31 . V_500 =
( T_4 ) V_8 -> V_499 ;
V_212 |= V_501 ;
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
struct V_526 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_527 V_528 ;
if ( ! V_10 -> V_529 -> V_530 )
return - V_53 ;
if ( V_10 -> V_63 . V_328 < V_329 )
return - V_53 ;
memset ( & V_528 , 0 , sizeof( V_528 ) ) ;
V_528 . V_531 = V_8 -> V_531 ;
V_528 . V_532 = V_8 -> V_533 ;
V_528 . V_534 = V_8 -> V_535 ;
V_528 . V_536 = V_8 -> V_536 ;
V_528 . V_537 = false ;
V_13 -> V_538 [ V_8 -> V_539 ] = V_528 ;
if ( F_207 ( V_10 , V_13 , V_8 -> V_539 , & V_528 ) ) {
F_208 ( V_10 -> V_63 . V_2 ,
L_2 ,
V_8 -> V_539 ) ;
return - V_85 ;
}
F_15 ( V_13 , V_540 ) ;
return 0 ;
}
static int F_209 ( struct V_2 * V_2 ,
struct V_541 * V_542 )
{
return F_210 ( F_2 ( V_2 ) , V_542 ) ;
}
static int F_211 ( struct V_2 * V_2 )
{
return F_212 ( F_2 ( V_2 ) ) ;
}
static int F_213 ( struct V_2 * V_2 ,
struct V_543 * V_544 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_544 -> V_11 ) ;
switch ( F_214 ( & V_13 -> V_27 ) ) {
case V_25 :
case V_107 :
case V_108 :
case V_116 :
case V_113 :
break;
case V_117 :
if ( V_13 -> V_10 -> V_529 -> V_545 )
break;
case V_105 :
if ( V_13 -> V_16 . V_198 . V_214 &&
( ! ( V_2 -> V_546 & V_547 ) ||
! ( V_544 -> V_6 & V_548 ) ) )
return - V_53 ;
break;
case V_52 :
default:
return - V_53 ;
}
return F_215 ( V_13 , V_544 ) ;
}
static void F_216 ( struct V_2 * V_2 , struct V_1 * V_11 )
{
F_217 ( F_2 ( V_2 ) ) ;
}
static int
F_218 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_549 * V_544 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_529 -> V_550 )
return - V_53 ;
return F_219 ( V_13 , V_544 ) ;
}
static int
F_220 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_529 -> V_551 )
return - V_53 ;
return F_221 ( V_10 ) ;
}
static int F_222 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_552 * V_544 )
{
return F_223 ( F_9 ( V_19 ) , V_544 ) ;
}
static int F_224 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_553 * V_544 )
{
return F_225 ( F_9 ( V_19 ) , V_544 ) ;
}
static int F_226 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_554 * V_544 )
{
return F_227 ( F_9 ( V_19 ) , V_544 ) ;
}
static int F_228 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_555 * V_544 )
{
return F_229 ( F_9 ( V_19 ) , V_544 ) ;
}
static int F_230 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_556 * V_8 )
{
return F_231 ( F_9 ( V_19 ) , V_8 ) ;
}
static int F_232 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_233 ( F_9 ( V_19 ) ) ;
}
static int F_234 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_557 * V_430 )
{
return F_235 ( F_9 ( V_19 ) , V_430 ) ;
}
static int F_236 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_237 ( F_9 ( V_19 ) ) ;
}
static int F_238 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_145 [ V_558 ] )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( V_13 -> V_27 . V_31 . V_449 , V_145 ,
sizeof( int ) * V_558 ) ;
return 0 ;
}
static int F_239 ( struct V_2 * V_2 , T_1 V_212 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_212 & V_559 ) {
F_240 ( V_10 ) ;
V_14 = F_241 ( V_10 , V_2 -> V_560 ) ;
if ( V_14 ) {
F_240 ( V_10 ) ;
return V_14 ;
}
}
if ( ( V_212 & V_561 ) ||
( V_212 & V_562 ) ) {
T_6 V_563 ;
V_563 = V_212 & V_561 ?
V_2 -> V_563 : - 1 ;
V_14 = F_242 ( V_10 , V_563 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_212 & V_564 ) {
V_14 = F_243 ( V_10 , V_2 -> V_565 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_212 & V_566 ) {
if ( V_2 -> V_567 > V_568 )
return - V_85 ;
V_10 -> V_63 . V_48 . V_569 = V_2 -> V_567 ;
}
if ( V_212 & V_570 ) {
if ( V_2 -> V_571 > V_568 )
return - V_85 ;
V_10 -> V_63 . V_48 . V_572 = V_2 -> V_571 ;
}
if ( V_212 &
( V_566 | V_570 ) )
F_98 ( V_10 , V_573 ) ;
return 0 ;
}
static int F_244 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
enum V_574 type , int V_575 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
enum V_574 V_576 = type ;
bool V_577 = false ;
if ( V_11 ) {
V_13 = F_5 ( V_11 ) ;
switch ( type ) {
case V_578 :
V_13 -> V_579 = V_580 ;
V_576 = V_581 ;
break;
case V_581 :
case V_582 :
if ( V_575 < 0 || ( V_575 % 100 ) )
return - V_53 ;
V_13 -> V_579 = F_245 ( V_575 ) ;
break;
}
if ( V_576 != V_13 -> V_27 . V_31 . V_583 ) {
V_577 = true ;
V_13 -> V_27 . V_31 . V_583 = V_576 ;
}
F_246 ( V_13 , V_577 ) ;
return 0 ;
}
switch ( type ) {
case V_578 :
V_10 -> V_579 = V_580 ;
V_576 = V_581 ;
break;
case V_581 :
case V_582 :
if ( V_575 < 0 || ( V_575 % 100 ) )
return - V_53 ;
V_10 -> V_579 = F_245 ( V_575 ) ;
break;
}
F_21 ( & V_10 -> V_185 ) ;
F_108 (sdata, &local->interfaces, list) {
V_13 -> V_579 = V_10 -> V_579 ;
if ( V_576 != V_13 -> V_27 . V_31 . V_583 )
V_577 = true ;
V_13 -> V_27 . V_31 . V_583 = V_576 ;
}
F_108 (sdata, &local->interfaces, list)
F_246 ( V_13 , V_577 ) ;
F_23 ( & V_10 -> V_185 ) ;
return 0 ;
}
static int F_247 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
int * V_584 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_10 -> V_529 -> V_585 )
return F_248 ( V_10 , V_13 , V_584 ) ;
if ( ! V_10 -> V_186 )
* V_584 = V_10 -> V_63 . V_48 . V_586 ;
else
* V_584 = V_13 -> V_27 . V_31 . V_587 ;
return 0 ;
}
static int F_249 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_176 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( & V_13 -> V_16 . V_588 . V_589 , V_176 , V_177 ) ;
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
struct V_590 * V_27 = NULL ;
if ( ! V_10 -> V_529 -> V_591 )
return - V_53 ;
if ( V_11 ) {
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 -> V_6 & V_592 )
V_27 = & V_13 -> V_27 ;
}
return V_10 -> V_529 -> V_591 ( & V_10 -> V_63 , V_27 , V_202 , V_201 ) ;
}
static int F_253 ( struct V_2 * V_2 ,
struct V_280 * V_281 ,
struct V_593 * V_289 ,
void * V_202 , int V_201 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_529 -> V_594 )
return - V_53 ;
return V_10 -> V_529 -> V_594 ( & V_10 -> V_63 , V_281 , V_289 , V_202 , V_201 ) ;
}
int F_254 ( struct V_12 * V_13 ,
enum V_595 V_232 )
{
struct V_75 * V_24 ;
enum V_595 V_596 ;
if ( F_58 ( V_13 -> V_27 . type != V_105 ) )
return - V_85 ;
if ( V_13 -> V_27 . V_31 . V_182 . V_597 == V_598 )
return 0 ;
V_596 = V_13 -> V_16 . V_198 . V_383 ;
V_13 -> V_16 . V_198 . V_383 = V_232 ;
if ( V_596 == V_232 ||
V_232 == V_599 )
return 0 ;
if ( ! F_255 ( & V_13 -> V_16 . V_198 . V_381 ) ) {
V_13 -> V_232 = V_232 ;
F_256 ( & V_13 -> V_10 -> V_63 , & V_13 -> V_600 ) ;
return 0 ;
}
F_169 ( V_13 ,
L_3 ,
V_232 , F_255 ( & V_13 -> V_16 . V_198 . V_381 ) ) ;
F_21 ( & V_13 -> V_10 -> V_98 ) ;
F_108 (sta, &sdata->local->sta_list, list) {
if ( V_24 -> V_13 -> V_380 != & V_13 -> V_16 . V_198 )
continue;
if ( F_168 ( V_24 ) == 1 )
continue;
if ( F_55 ( V_24 , V_601 ) &&
! F_257 ( V_24 -> V_382 ,
V_232 ) ) {
F_169 ( V_13 , L_4 ,
V_24 -> V_24 . V_176 ) ;
continue;
}
if ( ! F_55 ( V_24 , V_299 ) )
continue;
F_169 ( V_13 , L_5 , V_24 -> V_24 . V_176 ) ;
F_170 ( V_13 , V_232 , V_24 -> V_24 . V_176 ,
V_13 -> V_27 . V_31 . V_384 ) ;
}
F_23 ( & V_13 -> V_10 -> V_98 ) ;
V_13 -> V_232 = V_232 ;
F_256 ( & V_13 -> V_10 -> V_63 , & V_13 -> V_600 ) ;
return 0 ;
}
int F_258 ( struct V_12 * V_13 ,
enum V_595 V_232 )
{
const T_3 * V_198 ;
enum V_595 V_596 ;
int V_14 ;
struct V_75 * V_24 ;
bool V_602 = false ;
F_41 ( & V_13 -> V_11 . V_184 ) ;
if ( F_58 ( V_13 -> V_27 . type != V_25 ) )
return - V_85 ;
V_596 = V_13 -> V_16 . V_26 . V_383 ;
V_13 -> V_16 . V_26 . V_383 = V_232 ;
if ( V_596 == V_232 &&
V_232 != V_599 )
return 0 ;
if ( ! V_13 -> V_16 . V_26 . V_603 ||
V_13 -> V_27 . V_31 . V_182 . V_597 == V_598 )
return 0 ;
V_198 = V_13 -> V_16 . V_26 . V_603 -> V_384 ;
F_65 () ;
F_259 (sta, &sdata->local->sta_list, list) {
if ( ! V_24 -> V_24 . V_362 || V_24 -> V_13 != V_13 || ! V_24 -> V_604 ||
! F_55 ( V_24 , V_299 ) )
continue;
V_602 = true ;
break;
}
F_74 () ;
if ( V_232 == V_599 ) {
if ( V_602 || ! V_13 -> V_16 . V_26 . V_605 )
V_232 = V_234 ;
else
V_232 = V_238 ;
}
V_14 = F_170 ( V_13 , V_232 ,
V_198 , V_198 ) ;
if ( V_14 )
V_13 -> V_16 . V_26 . V_383 = V_596 ;
else if ( V_232 != V_234 && V_602 )
F_260 ( V_13 ) ;
return V_14 ;
}
static int F_261 ( struct V_2 * V_2 , struct V_18 * V_19 ,
bool V_606 , int V_607 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_89 ( V_19 -> V_180 ) ;
if ( V_13 -> V_27 . type != V_25 )
return - V_53 ;
if ( ! F_148 ( & V_10 -> V_63 , V_608 ) )
return - V_53 ;
if ( V_606 == V_13 -> V_16 . V_26 . V_605 &&
V_607 == V_10 -> V_609 )
return 0 ;
V_13 -> V_16 . V_26 . V_605 = V_606 ;
V_10 -> V_609 = V_607 ;
F_262 ( V_13 ) ;
F_258 ( V_13 , V_13 -> V_16 . V_26 . V_383 ) ;
F_263 ( V_13 ) ;
if ( F_148 ( & V_10 -> V_63 , V_610 ) )
F_98 ( V_10 , V_611 ) ;
F_171 ( V_10 ) ;
F_172 ( V_13 ) ;
return 0 ;
}
static int F_264 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_7 V_612 , T_1 V_613 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_590 * V_27 = & V_13 -> V_27 ;
struct V_614 * V_31 = & V_27 -> V_31 ;
if ( V_612 == V_31 -> V_615 &&
V_613 == V_31 -> V_616 )
return 0 ;
if ( V_13 -> V_27 . V_617 & V_618 &&
! ( V_13 -> V_27 . V_617 & V_619 ) )
return - V_53 ;
V_31 -> V_615 = V_612 ;
V_31 -> V_616 = V_613 ;
V_13 -> V_16 . V_26 . V_620 = 0 ;
if ( V_13 -> V_16 . V_26 . V_603 &&
V_13 -> V_27 . V_617 & V_619 )
F_15 ( V_13 , V_621 ) ;
return 0 ;
}
static int F_265 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
const T_3 * V_176 ,
const struct V_622 * V_42 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_89 ( V_19 -> V_180 ) ;
int V_623 , V_20 ;
if ( ! F_17 ( V_13 ) )
return - V_54 ;
if ( F_148 ( & V_10 -> V_63 , V_624 ) ) {
V_20 = F_266 ( V_10 , V_13 , V_42 ) ;
if ( V_20 )
return V_20 ;
}
for ( V_623 = 0 ; V_623 < V_558 ; V_623 ++ ) {
struct V_155 * V_156 = V_2 -> V_159 [ V_623 ] ;
int V_625 ;
V_13 -> V_626 [ V_623 ] = V_42 -> V_286 [ V_623 ] . V_162 ;
memcpy ( V_13 -> V_627 [ V_623 ] , V_42 -> V_286 [ V_623 ] . V_628 ,
sizeof( V_42 -> V_286 [ V_623 ] . V_628 ) ) ;
memcpy ( V_13 -> V_629 [ V_623 ] ,
V_42 -> V_286 [ V_623 ] . V_630 ,
sizeof( V_42 -> V_286 [ V_623 ] . V_630 ) ) ;
V_13 -> V_631 [ V_623 ] = false ;
V_13 -> V_632 [ V_623 ] = false ;
if ( ! V_156 )
continue;
for ( V_625 = 0 ; V_625 < V_633 ; V_625 ++ ) {
if ( ~ V_13 -> V_627 [ V_623 ] [ V_625 ] ) {
V_13 -> V_631 [ V_623 ] = true ;
break;
}
}
for ( V_625 = 0 ; V_625 < V_634 ; V_625 ++ ) {
if ( ~ V_13 -> V_629 [ V_623 ] [ V_625 ] ) {
V_13 -> V_632 [ V_623 ] = true ;
break;
}
}
}
return 0 ;
}
static int F_267 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_181 * V_182 ,
T_1 V_635 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_21 ( & V_10 -> V_184 ) ;
if ( ! F_268 ( & V_10 -> V_636 ) || V_10 -> V_637 ) {
V_14 = - V_45 ;
goto V_101;
}
V_13 -> V_232 = V_234 ;
V_13 -> V_239 = V_10 -> V_240 ;
V_14 = F_97 ( V_13 , V_182 ,
V_241 ) ;
if ( V_14 )
goto V_101;
F_269 ( & V_13 -> V_10 -> V_63 ,
& V_13 -> V_273 ,
F_270 ( V_635 ) ) ;
V_101:
F_23 ( & V_10 -> V_184 ) ;
return V_14 ;
}
static struct V_207 *
F_271 ( struct V_207 * V_214 )
{
struct V_207 * V_638 ;
T_3 * V_639 ;
int V_201 ;
V_201 = V_214 -> V_216 + V_214 -> V_218 + V_214 -> V_640 +
V_214 -> V_641 + V_214 -> V_642 +
V_214 -> V_223 ;
V_638 = F_101 ( sizeof( * V_638 ) + V_201 , V_199 ) ;
if ( ! V_638 )
return NULL ;
V_639 = ( T_3 * ) ( V_638 + 1 ) ;
if ( V_214 -> V_216 ) {
V_638 -> V_216 = V_214 -> V_216 ;
V_638 -> V_215 = V_639 ;
memcpy ( V_639 , V_214 -> V_215 , V_214 -> V_216 ) ;
V_639 += V_214 -> V_216 ;
}
if ( V_214 -> V_218 ) {
V_638 -> V_218 = V_214 -> V_218 ;
V_638 -> V_217 = V_639 ;
memcpy ( V_639 , V_214 -> V_217 , V_214 -> V_218 ) ;
V_639 += V_214 -> V_218 ;
}
if ( V_214 -> V_640 ) {
V_638 -> V_640 = V_214 -> V_640 ;
V_638 -> V_643 = V_639 ;
memcpy ( V_639 , V_214 -> V_643 , V_214 -> V_640 ) ;
V_639 += V_214 -> V_640 ;
}
if ( V_214 -> V_641 ) {
V_638 -> V_641 = V_214 -> V_641 ;
V_638 -> V_644 = V_639 ;
memcpy ( V_639 , V_214 -> V_644 , V_214 -> V_641 ) ;
V_639 += V_214 -> V_641 ;
}
if ( V_214 -> V_642 ) {
V_638 -> V_642 = V_214 -> V_642 ;
V_638 -> V_645 = V_639 ;
memcpy ( V_639 , V_214 -> V_645 , V_214 -> V_642 ) ;
V_639 += V_214 -> V_642 ;
}
if ( V_214 -> V_223 ) {
V_638 -> V_223 = V_214 -> V_223 ;
V_214 -> V_195 = V_639 ;
memcpy ( V_639 , V_214 -> V_195 , V_214 -> V_223 ) ;
V_639 += V_214 -> V_223 ;
}
return V_638 ;
}
void F_272 ( struct V_590 * V_27 )
{
struct V_12 * V_13 = F_273 ( V_27 ) ;
F_256 ( & V_13 -> V_10 -> V_63 ,
& V_13 -> V_646 ) ;
}
static int F_274 ( struct V_12 * V_13 ,
T_1 * V_212 )
{
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_105 :
V_14 = F_104 ( V_13 , V_13 -> V_16 . V_198 . V_268 ,
NULL ) ;
F_116 ( V_13 -> V_16 . V_198 . V_268 ) ;
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
#ifdef F_57
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
F_113 ( V_13 ) ;
F_41 ( & V_10 -> V_184 ) ;
F_41 ( & V_10 -> V_46 ) ;
if ( V_13 -> V_647 ) {
if ( V_13 -> V_648 )
return 0 ;
return F_278 ( V_13 ) ;
}
if ( ! F_93 ( & V_13 -> V_27 . V_31 . V_182 ,
& V_13 -> V_649 ) )
return - V_85 ;
V_13 -> V_27 . V_263 = false ;
V_14 = F_274 ( V_13 , & V_212 ) ;
if ( V_14 )
return V_14 ;
F_15 ( V_13 , V_212 ) ;
if ( V_13 -> V_266 ) {
F_115 ( V_10 , V_13 ,
V_267 ) ;
V_13 -> V_266 = false ;
}
V_14 = F_279 ( V_13 ) ;
if ( V_14 )
return V_14 ;
F_280 ( V_13 -> V_19 , & V_13 -> V_649 ) ;
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
void F_284 ( struct V_650 * V_651 )
{
struct V_12 * V_13 =
F_196 ( V_651 , struct V_12 ,
V_646 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
F_262 ( V_13 ) ;
F_21 ( & V_10 -> V_184 ) ;
F_21 ( & V_10 -> V_46 ) ;
if ( ! V_13 -> V_27 . V_263 )
goto V_652;
if ( ! F_17 ( V_13 ) )
goto V_652;
F_281 ( V_13 ) ;
V_652:
F_23 ( & V_10 -> V_46 ) ;
F_23 ( & V_10 -> V_184 ) ;
F_263 ( V_13 ) ;
}
static int F_285 ( struct V_12 * V_13 ,
struct V_653 * V_8 ,
T_1 * V_212 )
{
struct V_193 V_194 = {} ;
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_105 :
V_13 -> V_16 . V_198 . V_268 =
F_271 ( & V_8 -> V_654 ) ;
if ( ! V_13 -> V_16 . V_198 . V_268 )
return - V_200 ;
if ( V_8 -> V_220 <= 1 )
break;
if ( ( V_8 -> V_222 >
V_655 ) ||
( V_8 -> V_205 >
V_655 ) )
return - V_85 ;
V_194 . V_221 = V_8 -> V_221 ;
V_194 . V_204 = V_8 -> V_204 ;
V_194 . V_222 = V_8 -> V_222 ;
V_194 . V_205 = V_8 -> V_205 ;
V_194 . V_220 = V_8 -> V_220 ;
V_14 = F_104 ( V_13 , & V_8 -> V_656 , & V_194 ) ;
if ( V_14 < 0 ) {
F_116 ( V_13 -> V_16 . V_198 . V_268 ) ;
return V_14 ;
}
* V_212 |= V_14 ;
break;
case V_107 :
if ( ! V_13 -> V_27 . V_31 . V_657 )
return - V_85 ;
if ( V_8 -> V_182 . V_597 != V_13 -> V_16 . V_658 . V_182 . V_597 )
return - V_85 ;
switch ( V_8 -> V_182 . V_597 ) {
case V_659 :
if ( F_286 ( & V_8 -> V_182 ) !=
F_286 ( & V_13 -> V_16 . V_658 . V_182 ) )
return - V_85 ;
case V_660 :
case V_661 :
case V_598 :
case V_662 :
break;
default:
return - V_85 ;
}
if ( V_13 -> V_16 . V_658 . V_182 . V_663 -> V_323 !=
V_8 -> V_182 . V_663 -> V_323 )
return - V_85 ;
if ( V_8 -> V_220 > 1 ) {
V_14 = F_287 ( V_13 , V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_212 |= V_14 ;
}
F_288 ( V_13 , V_8 ) ;
break;
#ifdef F_57
case V_108 : {
struct V_427 * V_428 = & V_13 -> V_16 . V_109 ;
if ( V_8 -> V_182 . V_597 != V_13 -> V_27 . V_31 . V_182 . V_597 )
return - V_85 ;
if ( V_13 -> V_27 . V_31 . V_182 . V_663 -> V_323 !=
V_8 -> V_182 . V_663 -> V_323 )
return - V_85 ;
if ( V_428 -> V_664 == V_665 ) {
V_428 -> V_664 = V_666 ;
if ( ! V_428 -> V_667 )
V_428 -> V_667 = 1 ;
else
V_428 -> V_667 ++ ;
}
if ( V_8 -> V_220 > 1 ) {
V_14 = F_289 ( V_13 , V_8 ) ;
if ( V_14 < 0 ) {
V_428 -> V_664 = V_665 ;
return V_14 ;
}
* V_212 |= V_14 ;
}
if ( V_428 -> V_664 == V_666 )
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
struct V_653 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_668 V_669 ;
struct V_670 * V_48 ;
struct V_671 * V_672 ;
T_1 V_212 = 0 ;
int V_14 ;
F_113 ( V_13 ) ;
F_41 ( & V_10 -> V_184 ) ;
if ( ! F_268 ( & V_10 -> V_636 ) || V_10 -> V_637 )
return - V_45 ;
if ( V_13 -> V_11 . V_272 )
return - V_45 ;
if ( F_93 ( & V_8 -> V_182 ,
& V_13 -> V_27 . V_31 . V_182 ) )
return - V_85 ;
if ( V_13 -> V_27 . V_263 )
return - V_45 ;
F_21 ( & V_10 -> V_46 ) ;
V_48 = F_94 ( V_13 -> V_27 . V_673 ,
F_95 ( & V_10 -> V_46 ) ) ;
if ( ! V_48 ) {
V_14 = - V_45 ;
goto V_129;
}
V_672 = F_196 ( V_48 , struct V_671 , V_48 ) ;
V_669 . V_674 = 0 ;
V_669 . V_675 = 0 ;
V_669 . V_676 = V_8 -> V_676 ;
V_669 . V_182 = V_8 -> V_182 ;
V_669 . V_220 = V_8 -> V_220 ;
V_14 = F_291 ( V_13 , & V_669 ) ;
if ( V_14 )
goto V_129;
V_14 = F_292 ( V_13 , & V_8 -> V_182 ,
V_672 -> V_677 ,
V_8 -> V_678 ) ;
if ( V_14 )
goto V_129;
V_14 = F_22 ( V_13 , NULL , V_672 -> V_677 , 0 ) ;
if ( V_14 ) {
F_293 ( V_13 ) ;
goto V_129;
}
V_14 = F_285 ( V_13 , V_8 , & V_212 ) ;
if ( V_14 ) {
F_293 ( V_13 ) ;
goto V_129;
}
V_13 -> V_649 = V_8 -> V_182 ;
V_13 -> V_266 = V_8 -> V_676 ;
V_13 -> V_27 . V_263 = true ;
if ( V_13 -> V_266 )
F_294 ( V_10 , V_13 ,
V_267 ) ;
F_295 ( V_13 -> V_19 , & V_13 -> V_649 ,
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
int V_668 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_653 * V_8 )
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
V_10 -> V_679 ++ ;
if ( F_37 ( V_10 -> V_679 == 0 ) )
V_10 -> V_679 ++ ;
return V_10 -> V_679 ;
}
int F_298 ( struct V_9 * V_10 , struct V_280 * V_281 ,
T_2 * V_67 , T_8 V_680 )
{
unsigned long V_681 ;
struct V_280 * V_682 ;
int V_69 ;
V_682 = F_299 ( V_281 , V_680 ) ;
if ( ! V_682 )
return - V_200 ;
F_300 ( & V_10 -> V_683 , V_681 ) ;
V_69 = F_35 ( & V_10 -> V_684 , V_682 ,
1 , 0x10000 , V_65 ) ;
F_301 ( & V_10 -> V_683 , V_681 ) ;
if ( V_69 < 0 ) {
F_302 ( V_682 ) ;
return - V_200 ;
}
F_303 ( V_281 ) -> V_685 = V_69 ;
* V_67 = F_297 ( V_10 ) ;
F_303 ( V_682 ) -> V_686 . V_67 = * V_67 ;
return 0 ;
}
static void F_304 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_4 V_687 , bool V_688 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
switch ( V_687 ) {
case V_689 | V_690 :
if ( V_688 ) {
V_10 -> V_691 ++ ;
V_13 -> V_27 . V_691 ++ ;
} else {
if ( V_10 -> V_691 )
V_10 -> V_691 -- ;
if ( V_13 -> V_27 . V_691 )
V_13 -> V_27 . V_691 -- ;
}
if ( ! V_10 -> V_188 )
break;
if ( V_13 -> V_27 . V_691 == 1 )
F_305 ( V_10 , V_13 , V_692 ,
V_692 ) ;
else if ( V_13 -> V_27 . V_691 == 0 )
F_305 ( V_10 , V_13 , 0 ,
V_692 ) ;
F_19 ( V_10 ) ;
break;
default:
break;
}
}
static int F_306 ( struct V_2 * V_2 , T_1 V_693 , T_1 V_694 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_695 )
return - V_53 ;
return F_307 ( V_10 , V_693 , V_694 ) ;
}
static int F_308 ( struct V_2 * V_2 , T_1 * V_693 , T_1 * V_694 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_309 ( V_10 , V_693 , V_694 ) ;
}
static int F_310 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_696 * V_202 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_10 -> V_529 -> V_697 )
return - V_53 ;
F_311 ( V_10 , V_13 , V_202 ) ;
return 0 ;
}
static int F_312 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_698 , T_2 * V_67 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_699 * V_700 ;
struct V_280 * V_281 ;
int V_211 = sizeof( * V_700 ) ;
T_9 V_701 ;
bool V_702 ;
struct V_703 * V_704 ;
struct V_75 * V_24 ;
struct V_670 * V_673 ;
enum V_322 V_323 ;
int V_20 ;
F_21 ( & V_10 -> V_184 ) ;
F_65 () ;
V_673 = F_66 ( V_13 -> V_27 . V_673 ) ;
if ( F_37 ( ! V_673 ) ) {
V_20 = - V_85 ;
goto V_652;
}
V_323 = V_673 -> V_705 . V_663 -> V_323 ;
V_24 = F_54 ( V_13 , V_698 ) ;
if ( V_24 ) {
V_702 = V_24 -> V_24 . V_330 ;
} else {
V_20 = - V_706 ;
goto V_652;
}
if ( V_702 ) {
V_701 = F_313 ( V_707 |
V_708 |
V_709 ) ;
} else {
V_211 -= 2 ;
V_701 = F_313 ( V_707 |
V_710 |
V_709 ) ;
}
V_281 = F_127 ( V_10 -> V_63 . V_711 + V_211 ) ;
if ( ! V_281 ) {
V_20 = - V_200 ;
goto V_652;
}
V_281 -> V_19 = V_19 ;
F_314 ( V_281 , V_10 -> V_63 . V_711 ) ;
V_700 = ( void * ) F_128 ( V_281 , V_211 ) ;
V_700 -> V_712 = V_701 ;
V_700 -> V_713 = 0 ;
memcpy ( V_700 -> V_714 , V_24 -> V_24 . V_176 , V_177 ) ;
memcpy ( V_700 -> V_715 , V_13 -> V_27 . V_176 , V_177 ) ;
memcpy ( V_700 -> V_716 , V_13 -> V_27 . V_176 , V_177 ) ;
V_700 -> V_717 = 0 ;
V_704 = F_303 ( V_281 ) ;
V_704 -> V_6 |= V_718 |
V_719 ;
V_704 -> V_323 = V_323 ;
F_315 ( V_281 , V_720 ) ;
V_281 -> V_721 = 7 ;
if ( V_702 )
V_700 -> V_722 = F_313 ( 7 ) ;
V_20 = F_298 ( V_10 , V_281 , V_67 , V_65 ) ;
if ( V_20 ) {
F_302 ( V_281 ) ;
goto V_652;
}
F_316 () ;
F_317 ( V_13 , V_24 , V_281 ) ;
F_318 () ;
V_20 = 0 ;
V_652:
F_74 () ;
F_23 ( & V_10 -> V_184 ) ;
return V_20 ;
}
static int F_319 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_181 * V_182 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_670 * V_673 ;
int V_20 = - V_723 ;
F_65 () ;
V_673 = F_66 ( V_13 -> V_27 . V_673 ) ;
if ( V_673 ) {
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
F_74 () ;
return V_20 ;
}
static void F_320 ( struct V_2 * V_2 , bool V_606 )
{
F_321 ( F_2 ( V_2 ) , V_606 ) ;
}
static int F_322 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_724 * V_725 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_726 * V_727 , * V_728 ;
if ( V_725 ) {
V_727 = F_101 ( sizeof( * V_727 ) , V_199 ) ;
if ( ! V_727 )
return - V_200 ;
memcpy ( & V_727 -> V_725 , V_725 , sizeof( * V_725 ) ) ;
} else {
V_727 = NULL ;
}
V_728 = F_100 ( V_13 -> V_725 , V_13 ) ;
F_102 ( V_13 -> V_725 , V_727 ) ;
if ( V_728 )
F_103 ( V_728 , V_206 ) ;
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
T_3 V_729 , const T_3 * V_698 , T_3 V_730 ,
T_4 V_731 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_732 * V_733 = & V_13 -> V_16 . V_26 ;
int V_539 = V_734 [ V_730 ] ;
if ( V_13 -> V_27 . type != V_25 )
return - V_53 ;
if ( ! ( V_13 -> V_735 & F_134 ( V_730 ) ) )
return - V_85 ;
if ( V_733 -> V_736 [ V_539 ] . V_731 )
return - V_45 ;
if ( V_731 ) {
V_733 -> V_736 [ V_539 ] . V_731 = 32 * V_731 ;
V_733 -> V_736 [ V_539 ] . V_729 = V_729 ;
V_733 -> V_736 [ V_539 ] . V_730 = V_730 ;
}
return 0 ;
}
static int F_326 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_729 , const T_3 * V_698 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_732 * V_733 = & V_13 -> V_16 . V_26 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_539 ;
for ( V_539 = 0 ; V_539 < V_329 ; V_539 ++ ) {
struct V_737 * V_736 = & V_733 -> V_736 [ V_539 ] ;
if ( ! V_736 -> V_731 )
continue;
if ( V_736 -> V_729 != V_729 )
continue;
V_736 -> V_730 = - 1 ;
F_327 () ;
F_328 ( V_10 , V_13 , false ) ;
V_736 -> V_738 = V_739 ;
V_736 -> V_740 = false ;
F_329 ( V_13 ) ;
memset ( V_736 , 0 , sizeof( * V_736 ) ) ;
return 0 ;
}
return - V_100 ;
}
void F_330 ( struct V_590 * V_27 ,
T_3 V_741 ,
enum V_742 V_743 ,
T_8 V_680 )
{
struct V_12 * V_13 = F_273 ( V_27 ) ;
struct V_59 * V_68 ;
T_2 V_67 ;
if ( F_37 ( V_27 -> type != V_52 ) )
return;
F_34 ( & V_13 -> V_16 . V_49 . V_61 ) ;
V_68 = F_331 ( & V_13 -> V_16 . V_49 . V_62 , V_741 ) ;
if ( F_37 ( ! V_68 ) ) {
F_36 ( & V_13 -> V_16 . V_49 . V_61 ) ;
return;
}
V_67 = V_68 -> V_67 ;
F_39 ( & V_13 -> V_16 . V_49 . V_62 , V_741 ) ;
F_36 ( & V_13 -> V_16 . V_49 . V_61 ) ;
F_332 ( V_68 ) ;
F_333 ( F_334 ( V_27 ) , V_741 ,
V_743 , V_67 , V_680 ) ;
}
void F_335 ( struct V_590 * V_27 ,
struct V_744 * V_745 ,
T_8 V_680 )
{
struct V_12 * V_13 = F_273 ( V_27 ) ;
struct V_59 * V_68 ;
if ( F_37 ( V_27 -> type != V_52 ) )
return;
F_34 ( & V_13 -> V_16 . V_49 . V_61 ) ;
V_68 = F_331 ( & V_13 -> V_16 . V_49 . V_62 , V_745 -> V_741 ) ;
if ( F_37 ( ! V_68 ) ) {
F_36 ( & V_13 -> V_16 . V_49 . V_61 ) ;
return;
}
V_745 -> V_67 = V_68 -> V_67 ;
F_36 ( & V_13 -> V_16 . V_49 . V_61 ) ;
F_336 ( F_334 ( V_27 ) , V_745 , V_680 ) ;
}
