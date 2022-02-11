static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_5 = false ;
bool V_6 = false ;
if ( V_4 -> V_7 ) {
T_1 V_8 ;
F_2 ( sizeof( V_8 ) != V_9 ) ;
memcpy ( V_2 -> V_10 . V_11 . V_12 . V_8 ,
V_4 -> V_7 , V_9 ) ;
memcpy ( V_2 -> V_10 . V_11 . V_12 . V_13 ,
V_4 -> V_7 + V_9 ,
V_14 ) ;
F_3 ( V_2 , V_15 ) ;
memcpy ( & V_8 , V_4 -> V_7 ,
V_9 ) ;
V_5 = V_8 != 0 ;
}
if ( V_4 -> V_16 ) {
V_6 =
F_4 ( V_4 -> V_16 ) ;
F_5 ( V_2 -> V_17 . V_18 . V_19 ,
V_4 -> V_16 ) ;
}
V_2 -> V_10 . V_20 = V_5 || V_6 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_1 * V_23 ;
if ( V_4 -> V_24 && F_7 ( V_2 ) ) {
T_2 V_25 = V_26 | V_27 ;
if ( ( V_4 -> V_24 & V_25 ) != ( V_2 -> V_17 . V_18 . V_24 & V_25 ) )
return - V_28 ;
}
V_23 = F_8 ( V_22 -> V_23 ) ;
if ( ! V_23 &&
( V_4 -> V_7 || V_4 -> V_16 ) )
return - V_29 ;
if ( V_23 )
F_1 ( V_23 , V_4 ) ;
if ( V_4 -> V_24 ) {
if ( F_7 ( V_2 ) ) {
F_9 ( V_2 , - 1 ) ;
V_2 -> V_17 . V_18 . V_24 = V_4 -> V_24 ;
F_9 ( V_2 , 1 ) ;
F_10 ( V_22 ) ;
} else {
V_2 -> V_17 . V_18 . V_24 = V_4 -> V_24 ;
}
}
return 0 ;
}
static struct V_30 * F_11 ( struct V_31 * V_31 ,
const char * V_32 ,
unsigned char V_33 ,
enum V_34 type ,
struct V_3 * V_4 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
struct V_30 * V_35 ;
struct V_1 * V_2 ;
int V_36 ;
V_36 = F_13 ( V_22 , V_32 , V_33 , & V_35 , type , V_4 ) ;
if ( V_36 )
return F_14 ( V_36 ) ;
V_2 = F_15 ( V_35 ) ;
if ( type == V_37 ) {
V_36 = F_6 ( V_2 , V_4 ) ;
if ( V_36 ) {
F_16 ( V_2 ) ;
return NULL ;
}
}
return V_35 ;
}
static int F_17 ( struct V_31 * V_31 , struct V_30 * V_35 )
{
F_16 ( F_15 ( V_35 ) ) ;
return 0 ;
}
static int F_18 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
enum V_34 type ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
int V_40 ;
V_40 = F_20 ( V_2 , type ) ;
if ( V_40 )
return V_40 ;
if ( type == V_41 &&
V_4 && V_4 -> V_42 == 0 ) {
F_21 ( V_2 -> V_17 . V_43 . V_44 , NULL ) ;
F_22 ( V_2 ) ;
} else if ( type == V_45 &&
V_4 && V_4 -> V_42 >= 0 ) {
V_2 -> V_17 . V_46 . V_42 = V_4 -> V_42 ;
}
if ( V_2 -> V_10 . type == V_37 ) {
V_40 = F_6 ( V_2 , V_4 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_23 ( struct V_31 * V_31 ,
struct V_30 * V_35 )
{
struct V_1 * V_2 = F_15 ( V_35 ) ;
int V_40 ;
F_24 ( & V_2 -> V_22 -> V_47 ) ;
V_40 = F_25 ( V_2 , NULL , 0 , 0 ) ;
F_26 ( & V_2 -> V_22 -> V_47 ) ;
if ( V_40 < 0 )
return V_40 ;
return F_27 ( V_35 , true ) ;
}
static void F_28 ( struct V_31 * V_31 ,
struct V_30 * V_35 )
{
F_29 ( F_15 ( V_35 ) ) ;
}
static int F_30 ( struct V_31 * V_31 ,
struct V_30 * V_35 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_15 ( V_35 ) ;
int V_40 ;
F_24 ( & V_2 -> V_22 -> V_47 ) ;
V_40 = F_25 ( V_2 , NULL , 0 , 0 ) ;
F_26 ( & V_2 -> V_22 -> V_47 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_27 ( V_35 , true ) ;
if ( V_40 )
return V_40 ;
V_40 = F_31 ( V_2 -> V_22 , V_2 , V_49 ) ;
if ( V_40 )
F_29 ( V_2 ) ;
V_2 -> V_17 . V_50 . V_49 = * V_49 ;
return V_40 ;
}
static void F_32 ( struct V_31 * V_31 ,
struct V_30 * V_35 )
{
struct V_1 * V_2 = F_15 ( V_35 ) ;
F_33 ( V_2 -> V_22 , V_2 ) ;
F_29 ( V_2 ) ;
}
static int F_34 ( struct V_31 * V_31 ,
struct V_30 * V_35 ,
struct V_48 * V_49 ,
T_2 V_51 )
{
struct V_1 * V_2 = F_15 ( V_35 ) ;
struct V_48 V_52 ;
int V_40 = 0 ;
if ( V_2 -> V_10 . type != V_53 )
return - V_29 ;
if ( ! F_7 ( V_2 ) )
return - V_54 ;
V_52 = V_2 -> V_17 . V_50 . V_49 ;
if ( V_51 & V_55 )
V_52 . V_56 = V_49 -> V_56 ;
if ( V_51 & V_57 )
V_52 . V_58 = V_49 -> V_58 ;
V_40 = F_35 ( V_2 -> V_22 , V_2 , & V_52 , V_51 ) ;
if ( ! V_40 )
V_2 -> V_17 . V_50 . V_49 = V_52 ;
return V_40 ;
}
static int F_36 ( struct V_31 * V_31 ,
struct V_30 * V_35 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_15 ( V_35 ) ;
int V_40 ;
if ( V_2 -> V_10 . type != V_53 )
return - V_29 ;
if ( ! F_7 ( V_2 ) )
return - V_54 ;
F_37 ( & V_2 -> V_17 . V_50 . V_61 ) ;
V_40 = F_38 ( & V_2 -> V_17 . V_50 . V_62 ,
V_60 , 1 , V_2 -> V_22 -> V_63 . V_64 + 1 ,
V_65 ) ;
F_39 ( & V_2 -> V_17 . V_50 . V_61 ) ;
if ( V_40 < 0 )
return V_40 ;
V_60 -> V_66 = V_40 ;
F_40 ( V_60 -> V_66 == 0 ) ;
V_40 = F_41 ( V_2 -> V_22 , V_2 , V_60 ) ;
if ( V_40 ) {
F_37 ( & V_2 -> V_17 . V_50 . V_61 ) ;
F_42 ( & V_2 -> V_17 . V_50 . V_62 ,
V_60 -> V_66 ) ;
F_39 ( & V_2 -> V_17 . V_50 . V_61 ) ;
}
return V_40 ;
}
static struct V_59 *
F_43 ( struct V_1 * V_2 ,
T_1 V_67 )
{
struct V_59 * V_68 ;
int V_69 ;
F_44 ( & V_2 -> V_17 . V_50 . V_61 ) ;
F_45 (&sdata->u.nan.function_inst_ids, func, id) {
if ( V_68 -> V_67 == V_67 )
return V_68 ;
}
return NULL ;
}
static void F_46 ( struct V_31 * V_31 ,
struct V_30 * V_35 , T_1 V_67 )
{
struct V_1 * V_2 = F_15 ( V_35 ) ;
struct V_59 * V_68 ;
T_3 V_66 = 0 ;
if ( V_2 -> V_10 . type != V_53 ||
! F_7 ( V_2 ) )
return;
F_37 ( & V_2 -> V_17 . V_50 . V_61 ) ;
V_68 = F_43 ( V_2 , V_67 ) ;
if ( V_68 )
V_66 = V_68 -> V_66 ;
F_39 ( & V_2 -> V_17 . V_50 . V_61 ) ;
if ( V_66 )
F_47 ( V_2 -> V_22 , V_2 , V_66 ) ;
}
static int F_48 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
T_4 V_70 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
V_2 -> V_70 = V_70 ;
F_49 ( V_2 ) ;
return 0 ;
}
static int F_50 ( struct V_31 * V_31 , struct V_38 * V_39 ,
T_3 V_71 , bool V_72 , const T_3 * V_73 ,
struct V_74 * V_4 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_75 * V_44 = NULL ;
const struct V_76 * V_77 = NULL ;
struct V_78 * V_79 ;
int V_36 ;
if ( ! F_7 ( V_2 ) )
return - V_54 ;
switch ( V_4 -> V_80 ) {
case V_81 :
case V_82 :
case V_83 :
if ( F_51 ( V_22 -> V_84 ) )
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
V_77 = F_52 ( V_22 , V_4 -> V_80 , V_2 -> V_10 . type ) ;
break;
}
V_79 = F_53 ( V_4 -> V_80 , V_71 , V_4 -> V_94 ,
V_4 -> V_79 , V_4 -> V_95 , V_4 -> V_96 ,
V_77 ) ;
if ( F_51 ( V_79 ) )
return F_54 ( V_79 ) ;
if ( V_72 )
V_79 -> V_49 . V_24 |= V_97 ;
F_24 ( & V_22 -> V_98 ) ;
if ( V_73 ) {
V_44 = F_55 ( V_2 , V_73 ) ;
if ( ! V_44 || ! F_56 ( V_44 , V_99 ) ) {
F_57 ( V_79 ) ;
V_36 = - V_100 ;
goto V_101;
}
}
switch ( V_2 -> V_10 . type ) {
case V_45 :
if ( V_2 -> V_17 . V_46 . V_102 != V_103 )
V_79 -> V_49 . V_24 |= V_104 ;
break;
case V_105 :
case V_41 :
if ( V_79 -> V_44 && F_56 ( V_79 -> V_44 , V_106 ) )
V_79 -> V_49 . V_24 |= V_104 ;
break;
case V_107 :
break;
case V_108 :
#ifdef F_58
if ( V_2 -> V_17 . V_109 . V_110 != V_111 )
V_79 -> V_49 . V_24 |= V_104 ;
break;
#endif
case V_112 :
case V_37 :
case V_113 :
case V_53 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
F_59 ( 1 ) ;
break;
}
if ( V_44 )
V_44 -> V_119 = V_77 ;
V_36 = F_60 ( V_79 , V_2 , V_44 ) ;
V_101:
F_26 ( & V_22 -> V_98 ) ;
return V_36 ;
}
static int F_61 ( struct V_31 * V_31 , struct V_38 * V_39 ,
T_3 V_71 , bool V_72 , const T_3 * V_73 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_75 * V_44 ;
struct V_78 * V_79 = NULL ;
int V_40 ;
F_24 ( & V_22 -> V_98 ) ;
F_24 ( & V_22 -> V_120 ) ;
if ( V_73 ) {
V_40 = - V_100 ;
V_44 = F_55 ( V_2 , V_73 ) ;
if ( ! V_44 )
goto V_101;
if ( V_72 )
V_79 = F_62 ( V_22 , V_44 -> V_121 [ V_71 ] ) ;
else
V_79 = F_62 ( V_22 , V_44 -> V_122 [ V_71 ] ) ;
} else
V_79 = F_62 ( V_22 , V_2 -> V_123 [ V_71 ] ) ;
if ( ! V_79 ) {
V_40 = - V_100 ;
goto V_101;
}
F_63 ( V_79 , true ) ;
V_40 = 0 ;
V_101:
F_26 ( & V_22 -> V_120 ) ;
F_26 ( & V_22 -> V_98 ) ;
return V_40 ;
}
static int F_64 ( struct V_31 * V_31 , struct V_38 * V_39 ,
T_3 V_71 , bool V_72 , const T_3 * V_73 ,
void * V_67 ,
void (* F_65)( void * V_67 ,
struct V_74 * V_4 ) )
{
struct V_1 * V_2 ;
struct V_75 * V_44 = NULL ;
T_3 V_96 [ 6 ] = { 0 } ;
struct V_74 V_4 ;
struct V_78 * V_79 = NULL ;
T_1 V_124 ;
T_2 V_125 ;
T_4 V_126 ;
int V_36 = - V_100 ;
struct V_127 V_128 = {} ;
V_2 = F_19 ( V_39 ) ;
F_66 () ;
if ( V_73 ) {
V_44 = F_55 ( V_2 , V_73 ) ;
if ( ! V_44 )
goto V_129;
if ( V_72 && V_71 < V_130 )
V_79 = F_67 ( V_44 -> V_121 [ V_71 ] ) ;
else if ( ! V_72 &&
V_71 < V_130 + V_131 )
V_79 = F_67 ( V_44 -> V_122 [ V_71 ] ) ;
} else
V_79 = F_67 ( V_2 -> V_123 [ V_71 ] ) ;
if ( ! V_79 )
goto V_129;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_80 = V_79 -> V_49 . V_80 ;
switch ( V_79 -> V_49 . V_80 ) {
case V_82 :
V_124 = F_68 ( & V_79 -> V_49 . V_132 ) ;
V_125 = F_69 ( V_124 ) ;
V_126 = F_70 ( V_124 ) ;
if ( V_79 -> V_24 & V_133 &&
! ( V_79 -> V_49 . V_24 & V_134 ) ) {
F_71 ( V_2 -> V_22 , V_79 , & V_128 ) ;
V_125 = V_128 . V_135 . V_125 ;
V_126 = V_128 . V_135 . V_126 ;
}
V_96 [ 0 ] = V_126 & 0xff ;
V_96 [ 1 ] = ( V_126 >> 8 ) & 0xff ;
V_96 [ 2 ] = V_125 & 0xff ;
V_96 [ 3 ] = ( V_125 >> 8 ) & 0xff ;
V_96 [ 4 ] = ( V_125 >> 16 ) & 0xff ;
V_96 [ 5 ] = ( V_125 >> 24 ) & 0xff ;
V_4 . V_96 = V_96 ;
V_4 . V_95 = 6 ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
F_2 ( F_72 ( F_73 ( V_128 ) , V_136 ) !=
F_72 ( F_73 ( V_128 ) , V_137 ) ) ;
case V_90 :
case V_91 :
F_2 ( F_72 ( F_73 ( V_128 ) , V_136 ) !=
F_72 ( F_73 ( V_128 ) , V_138 ) ) ;
case V_92 :
case V_93 :
F_2 ( F_72 ( F_73 ( V_128 ) , V_136 ) !=
F_72 ( F_73 ( V_128 ) , V_139 ) ) ;
if ( V_79 -> V_24 & V_133 &&
! ( V_79 -> V_49 . V_24 & V_134 ) ) {
F_71 ( V_2 -> V_22 , V_79 , & V_128 ) ;
memcpy ( V_96 , V_128 . V_136 . V_140 , 6 ) ;
} else {
V_124 = F_68 ( & V_79 -> V_49 . V_132 ) ;
V_96 [ 0 ] = V_124 ;
V_96 [ 1 ] = V_124 >> 8 ;
V_96 [ 2 ] = V_124 >> 16 ;
V_96 [ 3 ] = V_124 >> 24 ;
V_96 [ 4 ] = V_124 >> 32 ;
V_96 [ 5 ] = V_124 >> 40 ;
}
V_4 . V_96 = V_96 ;
V_4 . V_95 = 6 ;
break;
default:
if ( ! ( V_79 -> V_24 & V_133 ) )
break;
if ( F_40 ( V_79 -> V_49 . V_24 & V_134 ) )
break;
F_71 ( V_2 -> V_22 , V_79 , & V_128 ) ;
V_4 . V_96 = V_128 . V_63 . V_96 ;
V_4 . V_95 = V_128 . V_63 . V_95 ;
break;
}
V_4 . V_79 = V_79 -> V_49 . V_79 ;
V_4 . V_94 = V_79 -> V_49 . V_141 ;
F_65 ( V_67 , & V_4 ) ;
V_36 = 0 ;
V_129:
F_74 () ;
return V_36 ;
}
static int F_75 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
T_3 V_71 , bool V_142 ,
bool V_143 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
F_76 ( V_2 , V_71 , V_142 , V_143 ) ;
return 0 ;
}
static int F_77 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
T_3 V_71 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
F_78 ( V_2 , V_71 ) ;
return 0 ;
}
void F_79 ( struct V_75 * V_44 ,
const struct V_144 * V_145 ,
struct V_146 * V_147 )
{
V_147 -> V_24 = 0 ;
if ( V_145 -> V_24 & V_148 ) {
V_147 -> V_24 |= V_149 ;
V_147 -> V_150 = V_145 -> V_151 ;
} else if ( V_145 -> V_24 & V_152 ) {
V_147 -> V_24 |= V_153 ;
V_147 -> V_150 = F_80 ( V_145 ) ;
V_147 -> V_154 = F_81 ( V_145 ) ;
} else {
struct V_155 * V_156 ;
int V_157 = F_82 ( & V_44 -> V_2 -> V_10 ) ;
T_4 V_158 ;
V_156 = F_83 ( V_44 -> V_2 ) ;
if ( V_156 ) {
V_158 = V_156 -> V_159 [ V_145 -> V_151 ] . V_160 ;
V_147 -> V_161 = F_84 ( V_158 , 1 << V_157 ) ;
}
}
if ( V_145 -> V_24 & V_162 )
V_147 -> V_163 = V_164 ;
else if ( V_145 -> V_24 & V_165 )
V_147 -> V_163 = V_166 ;
else if ( V_145 -> V_24 & V_167 )
V_147 -> V_163 = V_168 ;
else
V_147 -> V_163 = V_169 ;
if ( V_145 -> V_24 & V_170 )
V_147 -> V_24 |= V_171 ;
}
static int F_85 ( struct V_31 * V_31 , struct V_38 * V_39 ,
int V_151 , T_3 * V_172 , struct V_173 * V_174 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_75 * V_44 ;
int V_40 = - V_100 ;
F_24 ( & V_22 -> V_98 ) ;
V_44 = F_86 ( V_2 , V_151 ) ;
if ( V_44 ) {
V_40 = 0 ;
memcpy ( V_172 , V_44 -> V_44 . V_175 , V_176 ) ;
F_87 ( V_44 , V_174 ) ;
}
F_26 ( & V_22 -> V_98 ) ;
return V_40 ;
}
static int F_88 ( struct V_31 * V_31 , struct V_38 * V_39 ,
int V_151 , struct V_177 * V_178 )
{
struct V_21 * V_22 = F_89 ( V_39 -> V_179 ) ;
return F_90 ( V_22 , V_151 , V_178 ) ;
}
static int F_91 ( struct V_31 * V_31 , struct V_38 * V_39 ,
const T_3 * V_172 , struct V_173 * V_174 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_75 * V_44 ;
int V_40 = - V_100 ;
F_24 ( & V_22 -> V_98 ) ;
V_44 = F_55 ( V_2 , V_172 ) ;
if ( V_44 ) {
V_40 = 0 ;
F_87 ( V_44 , V_174 ) ;
}
F_26 ( & V_22 -> V_98 ) ;
return V_40 ;
}
static int F_92 ( struct V_31 * V_31 ,
struct V_180 * V_181 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
struct V_1 * V_2 ;
int V_40 = 0 ;
if ( F_93 ( & V_22 -> V_182 , V_181 ) )
return 0 ;
F_24 ( & V_22 -> V_183 ) ;
if ( V_22 -> V_184 ) {
V_2 = F_8 ( V_22 -> V_23 ) ;
if ( V_2 ) {
F_94 ( V_2 ) ;
V_40 = F_95 ( V_2 , V_181 ,
V_185 ) ;
}
} else if ( V_22 -> V_186 == V_22 -> V_187 ) {
V_22 -> V_188 = * V_181 ;
F_96 ( V_22 , 0 ) ;
}
if ( V_40 == 0 )
V_22 -> V_182 = * V_181 ;
F_26 ( & V_22 -> V_183 ) ;
return V_40 ;
}
static int F_97 ( struct V_1 * V_2 ,
const T_3 * V_189 , T_5 V_190 ,
const struct V_191 * V_192 )
{
struct V_193 * V_194 , * V_195 ;
if ( ! V_189 || ! V_190 )
return 1 ;
V_195 = F_98 ( V_2 -> V_17 . V_196 . V_193 , V_2 ) ;
V_194 = F_99 ( sizeof( struct V_193 ) + V_190 , V_197 ) ;
if ( ! V_194 )
return - V_198 ;
V_194 -> V_199 = V_190 ;
memcpy ( V_194 -> V_200 , V_189 , V_190 ) ;
if ( V_192 )
memcpy ( V_194 -> V_201 , V_192 -> V_202 ,
V_192 -> V_203 *
sizeof( V_194 -> V_201 [ 0 ] ) ) ;
F_100 ( V_2 -> V_17 . V_196 . V_193 , V_194 ) ;
if ( V_195 )
F_101 ( V_195 , V_204 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_205 * V_4 ,
const struct V_191 * V_192 )
{
struct V_206 * V_194 , * V_195 ;
int V_207 , V_208 ;
int V_209 , V_36 ;
T_2 V_210 = V_211 ;
V_195 = F_98 ( V_2 -> V_17 . V_196 . V_212 , V_2 ) ;
if ( ! V_4 -> V_213 && ! V_195 )
return - V_85 ;
if ( V_4 -> V_213 )
V_207 = V_4 -> V_214 ;
else
V_207 = V_195 -> V_214 ;
if ( V_4 -> V_215 || ! V_195 )
V_208 = V_4 -> V_216 ;
else
V_208 = V_195 -> V_216 ;
V_209 = sizeof( * V_194 ) + V_207 + V_208 ;
V_194 = F_99 ( V_209 , V_197 ) ;
if ( ! V_194 )
return - V_198 ;
V_194 -> V_213 = ( ( T_3 * ) V_194 ) + sizeof( * V_194 ) ;
V_194 -> V_215 = V_194 -> V_213 + V_207 ;
V_194 -> V_214 = V_207 ;
V_194 -> V_216 = V_208 ;
if ( V_192 ) {
V_194 -> V_217 = V_192 -> V_218 ;
memcpy ( V_194 -> V_201 , V_192 -> V_219 ,
V_192 -> V_220 *
sizeof( V_194 -> V_201 [ 0 ] ) ) ;
}
if ( V_4 -> V_213 )
memcpy ( V_194 -> V_213 , V_4 -> V_213 , V_207 ) ;
else
memcpy ( V_194 -> V_213 , V_195 -> V_213 , V_207 ) ;
if ( V_4 -> V_215 )
memcpy ( V_194 -> V_215 , V_4 -> V_215 , V_208 ) ;
else
if ( V_195 )
memcpy ( V_194 -> V_215 , V_195 -> V_215 , V_208 ) ;
V_36 = F_97 ( V_2 , V_4 -> V_193 ,
V_4 -> V_221 , V_192 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_36 == 0 )
V_210 |= V_222 ;
F_100 ( V_2 -> V_17 . V_196 . V_212 , V_194 ) ;
if ( V_195 )
F_101 ( V_195 , V_204 ) ;
return V_210 ;
}
static int F_103 ( struct V_31 * V_31 , struct V_38 * V_39 ,
struct V_223 * V_4 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_206 * V_195 ;
struct V_1 * V_43 ;
T_2 V_210 = V_224 |
V_225 |
V_211 |
V_226 |
V_227 |
V_228 ;
int V_36 ;
V_195 = F_98 ( V_2 -> V_17 . V_196 . V_212 , V_2 ) ;
if ( V_195 )
return - V_229 ;
switch ( V_4 -> V_230 ) {
case V_231 :
V_2 -> V_230 = V_232 ;
break;
case V_233 :
V_2 -> V_230 = V_234 ;
break;
case V_235 :
V_2 -> V_230 = V_236 ;
break;
default:
return - V_85 ;
}
V_2 -> V_17 . V_196 . V_237 = V_2 -> V_230 ;
V_2 -> V_238 = V_2 -> V_22 -> V_239 ;
V_2 -> V_10 . V_11 . V_240 = V_4 -> V_241 ;
F_24 ( & V_22 -> V_183 ) ;
V_36 = F_95 ( V_2 , & V_4 -> V_181 ,
V_242 ) ;
if ( ! V_36 )
F_104 ( V_2 , false ) ;
F_26 ( & V_22 -> V_183 ) ;
if ( V_36 )
return V_36 ;
V_2 -> V_243 = V_4 -> V_244 . V_245 ;
V_2 -> V_246 = V_4 -> V_244 . V_246 ;
V_2 -> V_247 = F_105 ( V_2 -> V_22 ,
& V_4 -> V_244 ,
V_2 -> V_10 . type ) ;
F_106 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_43 -> V_243 =
V_4 -> V_244 . V_245 ;
V_43 -> V_246 =
V_4 -> V_244 . V_246 ;
V_43 -> V_247 =
F_105 ( V_2 -> V_22 ,
& V_4 -> V_244 ,
V_43 -> V_10 . type ) ;
}
V_2 -> V_10 . V_11 . V_248 = V_4 -> V_248 ;
V_2 -> V_10 . V_11 . V_249 = true ;
V_2 -> V_10 . V_11 . V_250 = V_2 -> V_10 . V_251 ;
V_2 -> V_10 . V_11 . V_252 = V_4 -> V_252 ;
if ( V_4 -> V_252 )
memcpy ( V_2 -> V_10 . V_11 . V_253 , V_4 -> V_253 ,
V_4 -> V_252 ) ;
V_2 -> V_10 . V_11 . V_254 =
( V_4 -> V_254 != V_255 ) ;
memset ( & V_2 -> V_10 . V_11 . V_256 , 0 ,
sizeof( V_2 -> V_10 . V_11 . V_256 ) ) ;
V_2 -> V_10 . V_11 . V_256 . V_257 =
V_4 -> V_258 & V_259 ;
if ( V_4 -> V_260 )
V_2 -> V_10 . V_11 . V_256 . V_257 |=
V_261 ;
V_36 = F_102 ( V_2 , & V_4 -> V_212 , NULL ) ;
if ( V_36 < 0 ) {
F_94 ( V_2 ) ;
return V_36 ;
}
V_210 |= V_36 ;
V_36 = F_107 ( V_2 -> V_22 , V_2 ) ;
if ( V_36 ) {
V_195 = F_98 ( V_2 -> V_17 . V_196 . V_212 , V_2 ) ;
if ( V_195 )
F_101 ( V_195 , V_204 ) ;
F_21 ( V_2 -> V_17 . V_196 . V_212 , NULL ) ;
F_94 ( V_2 ) ;
return V_36 ;
}
F_108 ( V_22 , V_2 ) ;
F_3 ( V_2 , V_210 ) ;
F_109 ( V_39 ) ;
F_106 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_109 ( V_43 -> V_39 ) ;
return 0 ;
}
static int F_110 ( struct V_31 * V_31 , struct V_38 * V_39 ,
struct V_205 * V_4 )
{
struct V_1 * V_2 ;
struct V_206 * V_195 ;
int V_36 ;
V_2 = F_19 ( V_39 ) ;
F_111 ( V_2 ) ;
if ( V_2 -> V_10 . V_262 )
return - V_28 ;
V_195 = F_98 ( V_2 -> V_17 . V_196 . V_212 , V_2 ) ;
if ( ! V_195 )
return - V_100 ;
V_36 = F_102 ( V_2 , V_4 , NULL ) ;
if ( V_36 < 0 )
return V_36 ;
F_3 ( V_2 , V_36 ) ;
return 0 ;
}
static int F_112 ( struct V_31 * V_31 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_1 * V_43 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_206 * V_263 ;
struct V_193 * V_264 ;
struct V_180 V_181 ;
F_111 ( V_2 ) ;
V_263 = F_98 ( V_2 -> V_17 . V_196 . V_212 , V_2 ) ;
if ( ! V_263 )
return - V_100 ;
V_264 = F_98 ( V_2 -> V_17 . V_196 . V_193 , V_2 ) ;
F_24 ( & V_22 -> V_183 ) ;
V_2 -> V_10 . V_262 = false ;
if ( V_2 -> V_265 ) {
F_113 ( V_22 , V_2 ,
V_266 ) ;
V_2 -> V_265 = false ;
}
F_26 ( & V_22 -> V_183 ) ;
F_114 ( V_2 -> V_17 . V_196 . V_267 ) ;
V_2 -> V_17 . V_196 . V_267 = NULL ;
F_106 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_115 ( V_43 -> V_39 ) ;
F_115 ( V_39 ) ;
F_21 ( V_2 -> V_17 . V_196 . V_212 , NULL ) ;
F_21 ( V_2 -> V_17 . V_196 . V_193 , NULL ) ;
F_101 ( V_263 , V_204 ) ;
if ( V_264 )
F_101 ( V_264 , V_204 ) ;
V_2 -> V_17 . V_196 . V_268 = V_232 ;
F_116 ( V_2 , true ) ;
F_117 ( V_2 , true ) ;
V_2 -> V_10 . V_11 . V_249 = false ;
V_2 -> V_10 . V_11 . V_252 = 0 ;
F_118 ( V_269 , & V_2 -> V_270 ) ;
F_3 ( V_2 , V_225 ) ;
if ( V_2 -> V_35 . V_271 ) {
V_181 = V_2 -> V_10 . V_11 . V_181 ;
F_119 ( & V_2 -> V_272 ) ;
F_120 ( V_2 -> V_39 , & V_181 ,
V_273 ,
V_197 ) ;
}
F_121 ( V_2 -> V_22 , V_2 ) ;
V_22 -> V_274 -= F_122 ( & V_2 -> V_17 . V_196 . V_275 . V_276 ) ;
F_123 ( & V_22 -> V_63 , & V_2 -> V_17 . V_196 . V_275 . V_276 ) ;
F_24 ( & V_22 -> V_183 ) ;
F_104 ( V_2 , true ) ;
F_94 ( V_2 ) ;
F_26 ( & V_22 -> V_183 ) ;
return 0 ;
}
static void F_124 ( struct V_75 * V_44 )
{
struct V_277 * V_278 ;
struct V_279 * V_280 ;
V_280 = F_125 ( sizeof( * V_278 ) ) ;
if ( ! V_280 )
return;
V_278 = (struct V_277 * ) F_126 ( V_280 , sizeof( * V_278 ) ) ;
F_127 ( V_278 -> V_281 ) ;
memcpy ( V_278 -> V_282 , V_44 -> V_44 . V_175 , V_176 ) ;
V_278 -> V_199 = F_128 ( 6 ) ;
V_278 -> V_283 = 0 ;
V_278 -> V_284 = 0x01 ;
V_278 -> V_285 = 0xaf ;
V_278 -> V_286 [ 0 ] = 0x81 ;
V_278 -> V_286 [ 1 ] = 1 ;
V_278 -> V_286 [ 2 ] = 0 ;
V_280 -> V_39 = V_44 -> V_2 -> V_39 ;
V_280 -> V_287 = F_129 ( V_280 , V_44 -> V_2 -> V_39 ) ;
memset ( V_280 -> V_288 , 0 , sizeof( V_280 -> V_288 ) ) ;
F_130 ( V_280 ) ;
}
static int F_131 ( struct V_21 * V_22 ,
struct V_75 * V_44 ,
T_2 V_25 , T_2 V_289 )
{
int V_40 ;
if ( V_25 & F_132 ( V_290 ) &&
V_289 & F_132 ( V_290 ) &&
! F_56 ( V_44 , V_291 ) ) {
V_40 = F_133 ( V_44 , V_292 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_25 & F_132 ( V_293 ) &&
V_289 & F_132 ( V_293 ) &&
! F_56 ( V_44 , V_99 ) ) {
if ( ! F_56 ( V_44 , V_294 ) )
F_134 ( V_44 ) ;
V_40 = F_133 ( V_44 , V_295 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_25 & F_132 ( V_296 ) ) {
if ( V_289 & F_132 ( V_296 ) )
V_40 = F_133 ( V_44 , V_297 ) ;
else if ( F_56 ( V_44 , V_298 ) )
V_40 = F_133 ( V_44 , V_295 ) ;
else
V_40 = 0 ;
if ( V_40 )
return V_40 ;
}
if ( V_25 & F_132 ( V_293 ) &&
! ( V_289 & F_132 ( V_293 ) ) &&
F_56 ( V_44 , V_99 ) ) {
V_40 = F_133 ( V_44 , V_292 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_25 & F_132 ( V_290 ) &&
! ( V_289 & F_132 ( V_290 ) ) &&
F_56 ( V_44 , V_291 ) ) {
V_40 = F_133 ( V_44 , V_299 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static void F_135 ( struct V_21 * V_22 ,
struct V_75 * V_44 ,
struct V_300 * V_4 )
{
#ifdef F_58
struct V_1 * V_2 = V_44 -> V_2 ;
T_2 V_210 = 0 ;
if ( V_4 -> V_301 & V_302 ) {
switch ( V_4 -> V_303 ) {
case V_304 :
if ( V_44 -> V_109 -> V_303 != V_304 )
V_210 = F_136 ( V_2 ) ;
V_44 -> V_109 -> V_303 = V_4 -> V_303 ;
V_44 -> V_109 -> V_305 = V_4 -> V_306 ;
F_137 ( V_44 ) ;
V_210 |= F_138 ( V_44 ,
V_2 -> V_17 . V_109 . V_307 . V_308 ) ;
break;
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
if ( V_44 -> V_109 -> V_303 == V_304 )
V_210 = F_139 ( V_2 ) ;
V_44 -> V_109 -> V_303 = V_4 -> V_303 ;
F_137 ( V_44 ) ;
V_210 |= F_138 ( V_44 ,
V_315 ) ;
break;
default:
break;
}
}
switch ( V_4 -> V_316 ) {
case V_317 :
break;
case V_318 :
V_210 |= F_140 ( V_44 ) ;
break;
case V_319 :
V_210 |= F_141 ( V_44 ) ;
break;
}
if ( V_4 -> V_320 )
V_210 |= F_138 ( V_44 ,
V_4 -> V_320 ) ;
F_142 ( V_2 , V_210 ) ;
#endif
}
static int F_143 ( struct V_21 * V_22 ,
struct V_75 * V_44 ,
struct V_300 * V_4 )
{
int V_40 = 0 ;
struct V_155 * V_156 ;
struct V_1 * V_2 = V_44 -> V_2 ;
T_2 V_25 , V_289 ;
V_156 = F_83 ( V_2 ) ;
if ( ! V_156 )
return - V_85 ;
V_25 = V_4 -> V_321 ;
V_289 = V_4 -> V_322 ;
if ( F_144 ( & V_2 -> V_10 ) ) {
if ( V_25 & F_132 ( V_290 ) )
V_25 |= F_132 ( V_293 ) ;
if ( V_289 & F_132 ( V_290 ) )
V_289 |= F_132 ( V_293 ) ;
} else if ( F_56 ( V_44 , V_323 ) ) {
if ( V_289 & F_132 ( V_296 ) ) {
V_289 |= F_132 ( V_290 ) |
F_132 ( V_293 ) ;
V_25 |= F_132 ( V_290 ) |
F_132 ( V_293 ) ;
}
}
if ( V_25 & F_132 ( V_324 ) &&
V_22 -> V_63 . V_325 >= V_326 )
V_44 -> V_44 . V_327 = V_289 & F_132 ( V_324 ) ;
if ( ! F_56 ( V_44 , V_323 ) &&
! ( ( V_25 & F_132 ( V_293 ) ) &&
( V_289 & F_132 ( V_293 ) ) ) ) {
V_40 = F_131 ( V_22 , V_44 , V_25 , V_289 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_25 & F_132 ( V_328 ) ) {
if ( V_289 & F_132 ( V_328 ) )
F_145 ( V_44 , V_329 ) ;
else
F_146 ( V_44 , V_329 ) ;
}
if ( V_25 & F_132 ( V_330 ) ) {
V_44 -> V_44 . V_102 = ! ! ( V_289 & F_132 ( V_330 ) ) ;
if ( V_289 & F_132 ( V_330 ) )
F_145 ( V_44 , V_106 ) ;
else
F_146 ( V_44 , V_106 ) ;
}
if ( V_25 & F_132 ( V_331 ) ) {
if ( V_289 & F_132 ( V_331 ) )
F_145 ( V_44 , V_323 ) ;
else
F_146 ( V_44 , V_323 ) ;
}
if ( F_56 ( V_44 , V_323 ) &&
! V_2 -> V_17 . V_46 . V_332 &&
V_4 -> V_333 >= 4 &&
V_4 -> V_334 [ 3 ] & V_335 )
F_145 ( V_44 , V_336 ) ;
if ( F_56 ( V_44 , V_323 ) &&
! V_2 -> V_17 . V_46 . V_337 &&
F_147 ( & V_22 -> V_63 , V_338 ) &&
V_4 -> V_333 >= 8 &&
V_4 -> V_334 [ 7 ] & V_339 )
F_145 ( V_44 , V_340 ) ;
if ( V_4 -> V_301 & V_341 ) {
V_44 -> V_44 . V_342 = V_4 -> V_342 ;
V_44 -> V_44 . V_343 = V_4 -> V_343 ;
}
if ( V_4 -> V_333 >= 8 ) {
T_3 V_344 = ( V_4 -> V_334 [ 7 ] &
V_345 ) >> 7 ;
if ( V_4 -> V_333 >= 9 ) {
T_3 V_346 = V_4 -> V_334 [ 8 ] &
V_347 ;
V_346 <<= 1 ;
V_344 |= V_346 ;
}
switch ( V_344 ) {
case 1 :
V_44 -> V_44 . V_348 = 32 ;
break;
case 2 :
V_44 -> V_44 . V_348 = 16 ;
break;
case 3 :
V_44 -> V_44 . V_348 = 8 ;
break;
default:
V_44 -> V_44 . V_348 = 0 ;
}
}
if ( V_4 -> V_305 )
V_44 -> V_44 . V_305 = V_4 -> V_305 ;
if ( V_4 -> V_349 >= 0 )
V_44 -> V_349 = V_4 -> V_349 ;
if ( V_4 -> V_350 ) {
F_148 ( & V_2 -> V_10 . V_11 . V_181 ,
V_156 , V_4 -> V_350 ,
V_4 -> V_351 ,
& V_44 -> V_44 . V_352 [ V_156 -> V_353 ] ) ;
}
if ( V_4 -> V_354 )
F_149 ( V_2 , V_156 ,
V_4 -> V_354 , V_44 ) ;
if ( V_4 -> V_355 )
F_150 ( V_2 , V_156 ,
V_4 -> V_355 , V_44 ) ;
if ( V_4 -> V_356 ) {
F_151 ( V_2 , V_44 , V_4 -> V_357 ,
V_156 -> V_353 ) ;
}
if ( V_4 -> V_358 >= 0 )
V_44 -> V_44 . V_358 = V_4 -> V_358 ;
if ( F_144 ( & V_2 -> V_10 ) )
F_135 ( V_22 , V_44 , V_4 ) ;
if ( F_56 ( V_44 , V_323 ) ||
V_289 & F_132 ( V_293 ) ) {
V_40 = F_131 ( V_22 , V_44 , V_25 , V_289 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_152 ( struct V_31 * V_31 , struct V_38 * V_39 ,
const T_3 * V_172 ,
struct V_300 * V_4 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
struct V_75 * V_44 ;
struct V_1 * V_2 ;
int V_36 ;
int V_359 ;
if ( V_4 -> V_43 ) {
V_2 = F_19 ( V_4 -> V_43 ) ;
if ( V_2 -> V_10 . type != V_41 &&
V_2 -> V_10 . type != V_105 )
return - V_85 ;
} else
V_2 = F_19 ( V_39 ) ;
if ( F_153 ( V_172 , V_2 -> V_10 . V_175 ) )
return - V_85 ;
if ( F_154 ( V_172 ) )
return - V_85 ;
V_44 = F_155 ( V_2 , V_172 , V_197 ) ;
if ( ! V_44 )
return - V_198 ;
if ( V_4 -> V_322 & F_132 ( V_331 ) )
V_44 -> V_44 . V_360 = true ;
V_36 = F_143 ( V_22 , V_44 , V_4 ) ;
if ( V_36 ) {
F_156 ( V_22 , V_44 ) ;
return V_36 ;
}
if ( ! F_56 ( V_44 , V_323 ) &&
F_56 ( V_44 , V_99 ) )
F_134 ( V_44 ) ;
V_359 = V_2 -> V_10 . type == V_41 ||
V_2 -> V_10 . type == V_105 ;
V_36 = F_157 ( V_44 ) ;
if ( V_36 ) {
F_74 () ;
return V_36 ;
}
if ( V_359 )
F_124 ( V_44 ) ;
F_74 () ;
return 0 ;
}
static int F_158 ( struct V_31 * V_31 , struct V_38 * V_39 ,
struct V_361 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_39 ) ;
if ( V_4 -> V_172 )
return F_159 ( V_2 , V_4 -> V_172 ) ;
F_160 ( V_2 ) ;
return 0 ;
}
static int F_161 ( struct V_31 * V_31 ,
struct V_38 * V_39 , const T_3 * V_172 ,
struct V_300 * V_4 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_21 * V_22 = F_12 ( V_31 ) ;
struct V_75 * V_44 ;
struct V_1 * V_362 ;
enum V_363 V_364 ;
int V_36 ;
F_24 ( & V_22 -> V_98 ) ;
V_44 = F_55 ( V_2 , V_172 ) ;
if ( ! V_44 ) {
V_36 = - V_100 ;
goto V_365;
}
switch ( V_2 -> V_10 . type ) {
case V_108 :
if ( V_2 -> V_17 . V_109 . V_366 )
V_364 = V_367 ;
else
V_364 = V_368 ;
break;
case V_107 :
V_364 = V_369 ;
break;
case V_45 :
if ( ! F_56 ( V_44 , V_323 ) ) {
V_364 = V_370 ;
break;
}
if ( F_56 ( V_44 , V_298 ) )
V_364 = V_371 ;
else
V_364 = V_372 ;
break;
case V_105 :
case V_41 :
if ( F_56 ( V_44 , V_99 ) )
V_364 = V_373 ;
else
V_364 = V_374 ;
break;
default:
V_36 = - V_29 ;
goto V_365;
}
V_36 = F_162 ( V_31 , V_4 , V_364 ) ;
if ( V_36 )
goto V_365;
if ( V_4 -> V_43 && V_4 -> V_43 != V_44 -> V_2 -> V_39 ) {
V_362 = F_19 ( V_4 -> V_43 ) ;
if ( V_4 -> V_43 -> V_179 -> V_42 ) {
if ( V_362 -> V_17 . V_43 . V_44 ) {
V_36 = - V_28 ;
goto V_365;
}
F_100 ( V_362 -> V_17 . V_43 . V_44 , V_44 ) ;
F_163 ( V_362 ) ;
}
if ( V_44 -> V_2 -> V_10 . type == V_41 &&
V_44 -> V_2 -> V_17 . V_43 . V_44 )
F_21 ( V_44 -> V_2 -> V_17 . V_43 . V_44 , NULL ) ;
if ( F_56 ( V_44 , V_298 ) )
F_164 ( V_44 -> V_2 ) ;
V_44 -> V_2 = V_362 ;
F_165 ( V_44 ) ;
if ( F_56 ( V_44 , V_298 ) )
F_166 ( V_44 -> V_2 ) ;
F_124 ( V_44 ) ;
}
V_36 = F_143 ( V_22 , V_44 , V_4 ) ;
if ( V_36 )
goto V_365;
F_26 ( & V_22 -> V_98 ) ;
if ( ( V_2 -> V_10 . type == V_105 ||
V_2 -> V_10 . type == V_41 ) &&
V_44 -> V_375 != V_44 -> V_2 -> V_376 -> V_237 &&
F_56 ( V_44 , V_298 ) &&
F_167 ( V_44 ) != 1 ) {
F_168 ( V_44 -> V_2 ,
L_1 ,
V_44 -> V_44 . V_175 ) ;
F_169 ( V_44 -> V_2 ,
V_44 -> V_2 -> V_376 -> V_237 ,
V_44 -> V_44 . V_175 ,
V_44 -> V_2 -> V_10 . V_11 . V_377 ) ;
}
if ( V_2 -> V_10 . type == V_45 &&
V_4 -> V_321 & F_132 ( V_296 ) ) {
F_170 ( V_22 ) ;
F_171 ( V_2 ) ;
}
return 0 ;
V_365:
F_26 ( & V_22 -> V_98 ) ;
return V_36 ;
}
static int F_172 ( struct V_31 * V_31 , struct V_38 * V_39 ,
const T_3 * V_378 , const T_3 * V_379 )
{
struct V_1 * V_2 ;
struct V_380 * V_381 ;
struct V_75 * V_44 ;
V_2 = F_19 ( V_39 ) ;
F_66 () ;
V_44 = F_173 ( V_2 , V_379 ) ;
if ( ! V_44 ) {
F_74 () ;
return - V_100 ;
}
V_381 = F_174 ( V_2 , V_378 ) ;
if ( F_51 ( V_381 ) ) {
F_74 () ;
return F_54 ( V_381 ) ;
}
F_175 ( V_381 , V_44 ) ;
F_74 () ;
return 0 ;
}
static int F_176 ( struct V_31 * V_31 , struct V_38 * V_39 ,
const T_3 * V_378 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
if ( V_378 )
return F_177 ( V_2 , V_378 ) ;
F_178 ( V_2 ) ;
return 0 ;
}
static int F_179 ( struct V_31 * V_31 , struct V_38 * V_39 ,
const T_3 * V_378 , const T_3 * V_379 )
{
struct V_1 * V_2 ;
struct V_380 * V_381 ;
struct V_75 * V_44 ;
V_2 = F_19 ( V_39 ) ;
F_66 () ;
V_44 = F_173 ( V_2 , V_379 ) ;
if ( ! V_44 ) {
F_74 () ;
return - V_100 ;
}
V_381 = F_180 ( V_2 , V_378 ) ;
if ( ! V_381 ) {
F_74 () ;
return - V_100 ;
}
F_175 ( V_381 , V_44 ) ;
F_74 () ;
return 0 ;
}
static void F_181 ( struct V_380 * V_381 , T_3 * V_379 ,
struct V_382 * V_383 )
{
struct V_75 * V_384 = F_67 ( V_381 -> V_379 ) ;
if ( V_384 )
memcpy ( V_379 , V_384 -> V_44 . V_175 , V_176 ) ;
else
F_182 ( V_379 ) ;
memset ( V_383 , 0 , sizeof( * V_383 ) ) ;
V_383 -> V_385 = V_381 -> V_2 -> V_17 . V_109 . V_386 ;
V_383 -> V_387 = V_388 |
V_389 |
V_390 |
V_391 |
V_392 |
V_393 |
V_394 ;
V_383 -> V_395 = V_381 -> V_396 . V_397 ;
V_383 -> V_398 = V_381 -> V_398 ;
V_383 -> V_399 = V_381 -> V_399 ;
if ( F_183 ( V_400 , V_381 -> V_401 ) )
V_383 -> V_402 = F_184 ( V_381 -> V_401 - V_400 ) ;
V_383 -> V_403 =
F_184 ( V_381 -> V_403 ) ;
V_383 -> V_404 = V_381 -> V_404 ;
if ( V_381 -> V_24 & V_405 )
V_383 -> V_24 |= V_406 ;
if ( V_381 -> V_24 & V_407 )
V_383 -> V_24 |= V_408 ;
if ( V_381 -> V_24 & V_409 )
V_383 -> V_24 |= V_410 ;
if ( V_381 -> V_24 & V_411 )
V_383 -> V_24 |= V_412 ;
if ( V_381 -> V_24 & V_413 )
V_383 -> V_24 |= V_414 ;
}
static int F_185 ( struct V_31 * V_31 , struct V_38 * V_39 ,
T_3 * V_378 , T_3 * V_379 , struct V_382 * V_383 )
{
struct V_1 * V_2 ;
struct V_380 * V_381 ;
V_2 = F_19 ( V_39 ) ;
F_66 () ;
V_381 = F_180 ( V_2 , V_378 ) ;
if ( ! V_381 ) {
F_74 () ;
return - V_100 ;
}
memcpy ( V_378 , V_381 -> V_378 , V_176 ) ;
F_181 ( V_381 , V_379 , V_383 ) ;
F_74 () ;
return 0 ;
}
static int F_186 ( struct V_31 * V_31 , struct V_38 * V_39 ,
int V_151 , T_3 * V_378 , T_3 * V_379 ,
struct V_382 * V_383 )
{
struct V_1 * V_2 ;
struct V_380 * V_381 ;
V_2 = F_19 ( V_39 ) ;
F_66 () ;
V_381 = F_187 ( V_2 , V_151 ) ;
if ( ! V_381 ) {
F_74 () ;
return - V_100 ;
}
memcpy ( V_378 , V_381 -> V_378 , V_176 ) ;
F_181 ( V_381 , V_379 , V_383 ) ;
F_74 () ;
return 0 ;
}
static void F_188 ( struct V_380 * V_381 , T_3 * V_415 ,
struct V_382 * V_383 )
{
memset ( V_383 , 0 , sizeof( * V_383 ) ) ;
memcpy ( V_415 , V_381 -> V_415 , V_176 ) ;
V_383 -> V_385 = V_381 -> V_2 -> V_17 . V_109 . V_416 ;
}
static int F_189 ( struct V_31 * V_31 , struct V_38 * V_39 ,
T_3 * V_378 , T_3 * V_415 , struct V_382 * V_383 )
{
struct V_1 * V_2 ;
struct V_380 * V_381 ;
V_2 = F_19 ( V_39 ) ;
F_66 () ;
V_381 = F_190 ( V_2 , V_378 ) ;
if ( ! V_381 ) {
F_74 () ;
return - V_100 ;
}
memcpy ( V_378 , V_381 -> V_378 , V_176 ) ;
F_188 ( V_381 , V_415 , V_383 ) ;
F_74 () ;
return 0 ;
}
static int F_191 ( struct V_31 * V_31 , struct V_38 * V_39 ,
int V_151 , T_3 * V_378 , T_3 * V_415 ,
struct V_382 * V_383 )
{
struct V_1 * V_2 ;
struct V_380 * V_381 ;
V_2 = F_19 ( V_39 ) ;
F_66 () ;
V_381 = F_192 ( V_2 , V_151 ) ;
if ( ! V_381 ) {
F_74 () ;
return - V_100 ;
}
memcpy ( V_378 , V_381 -> V_378 , V_176 ) ;
F_188 ( V_381 , V_415 , V_383 ) ;
F_74 () ;
return 0 ;
}
static int F_193 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
struct V_417 * V_49 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_39 ) ;
memcpy ( V_49 , & ( V_2 -> V_17 . V_109 . V_307 ) , sizeof( struct V_417 ) ) ;
return 0 ;
}
static inline bool F_194 ( enum V_418 V_419 , T_2 V_25 )
{
return ( V_25 >> ( V_419 - 1 ) ) & 0x1 ;
}
static int F_195 ( struct V_420 * V_421 ,
const struct V_422 * V_423 )
{
T_3 * V_424 ;
const T_3 * V_425 ;
struct V_1 * V_2 = F_196 ( V_421 ,
struct V_1 , V_17 . V_109 ) ;
V_424 = NULL ;
V_425 = V_421 -> V_426 ;
if ( V_423 -> V_427 ) {
V_424 = F_197 ( V_423 -> V_426 , V_423 -> V_427 ,
V_197 ) ;
if ( ! V_424 )
return - V_198 ;
}
V_421 -> V_427 = V_423 -> V_427 ;
V_421 -> V_426 = V_424 ;
F_114 ( V_425 ) ;
V_421 -> V_428 = V_423 -> V_428 ;
memcpy ( V_421 -> V_429 , V_423 -> V_429 , V_421 -> V_428 ) ;
V_421 -> V_430 = V_423 -> V_431 ;
V_421 -> V_432 = V_423 -> V_433 ;
V_421 -> V_434 = V_423 -> V_435 ;
V_421 -> V_366 = V_423 -> V_366 ;
V_421 -> V_436 = V_423 -> V_437 ;
V_421 -> V_110 = V_111 ;
if ( V_423 -> V_438 )
V_421 -> V_110 |= V_439 ;
if ( V_423 -> V_440 )
V_421 -> V_110 |= V_441 ;
memcpy ( V_2 -> V_10 . V_11 . V_442 , V_423 -> V_442 ,
sizeof( V_423 -> V_442 ) ) ;
V_2 -> V_10 . V_11 . V_443 = V_423 -> V_443 ;
V_2 -> V_10 . V_11 . V_240 = V_423 -> V_241 ;
V_2 -> V_10 . V_11 . V_248 = V_423 -> V_248 ;
return 0 ;
}
static int F_198 ( struct V_31 * V_31 ,
struct V_38 * V_39 , T_2 V_25 ,
const struct V_417 * V_444 )
{
struct V_417 * V_49 ;
struct V_1 * V_2 ;
struct V_420 * V_421 ;
V_2 = F_19 ( V_39 ) ;
V_421 = & V_2 -> V_17 . V_109 ;
V_49 = & ( V_2 -> V_17 . V_109 . V_307 ) ;
if ( F_194 ( V_445 , V_25 ) )
V_49 -> V_446 = V_444 -> V_446 ;
if ( F_194 ( V_447 , V_25 ) )
V_49 -> V_448 = V_444 -> V_448 ;
if ( F_194 ( V_449 , V_25 ) )
V_49 -> V_450 = V_444 -> V_450 ;
if ( F_194 ( V_451 , V_25 ) )
V_49 -> V_452 = V_444 -> V_452 ;
if ( F_194 ( V_453 , V_25 ) )
V_49 -> V_454 = V_444 -> V_454 ;
if ( F_194 ( V_455 , V_25 ) )
V_49 -> V_456 = V_444 -> V_456 ;
if ( F_194 ( V_457 , V_25 ) )
V_49 -> V_458 = V_444 -> V_458 ;
if ( F_194 ( V_459 , V_25 ) ) {
if ( V_421 -> V_366 )
return - V_28 ;
V_49 -> V_460 = V_444 -> V_460 ;
}
if ( F_194 ( V_461 , V_25 ) )
V_49 -> V_462 =
V_444 -> V_462 ;
if ( F_194 ( V_463 , V_25 ) )
V_49 -> V_464 =
V_444 -> V_464 ;
if ( F_194 ( V_465 , V_25 ) )
V_49 -> V_466 = V_444 -> V_466 ;
if ( F_194 ( V_467 , V_25 ) )
V_49 -> V_468 = V_444 -> V_468 ;
if ( F_194 ( V_469 , V_25 ) )
V_49 -> V_470 =
V_444 -> V_470 ;
if ( F_194 ( V_471 , V_25 ) )
V_49 -> V_472 =
V_444 -> V_472 ;
if ( F_194 ( V_473 , V_25 ) )
V_49 -> V_474 =
V_444 -> V_474 ;
if ( F_194 ( V_475 ,
V_25 ) )
V_49 -> V_476 =
V_444 -> V_476 ;
if ( F_194 ( V_477 , V_25 ) ) {
V_49 -> V_478 = V_444 -> V_478 ;
F_199 ( V_421 ) ;
}
if ( F_194 ( V_479 , V_25 ) ) {
if ( V_444 -> V_480 &&
! ( V_49 -> V_478 > V_481 ) ) {
V_49 -> V_478 = V_482 ;
F_199 ( V_421 ) ;
}
V_49 -> V_480 =
V_444 -> V_480 ;
}
if ( F_194 ( V_483 , V_25 ) )
V_49 -> V_484 =
V_444 -> V_484 ;
if ( F_194 ( V_485 , V_25 ) )
V_49 -> V_486 = V_444 -> V_486 ;
if ( F_194 ( V_487 , V_25 ) ) {
if ( ! F_147 ( & V_2 -> V_22 -> V_63 , V_488 ) )
return - V_489 ;
V_49 -> V_490 = V_444 -> V_490 ;
}
if ( F_194 ( V_491 , V_25 ) ) {
V_49 -> V_492 = V_444 -> V_492 ;
V_2 -> V_10 . V_11 . V_493 = V_444 -> V_492 ;
F_3 ( V_2 , V_494 ) ;
}
if ( F_194 ( V_495 , V_25 ) )
V_49 -> V_496 =
V_444 -> V_496 ;
if ( F_194 ( V_497 , V_25 ) )
V_49 -> V_498 =
V_444 -> V_498 ;
if ( F_194 ( V_499 , V_25 ) )
V_49 -> V_500 =
V_444 -> V_500 ;
if ( F_194 ( V_501 , V_25 ) ) {
V_49 -> V_308 = V_444 -> V_308 ;
F_200 ( V_2 ) ;
}
if ( F_194 ( V_502 , V_25 ) )
V_49 -> V_503 =
V_444 -> V_503 ;
if ( F_194 ( V_504 , V_25 ) )
V_49 -> V_505 = V_444 -> V_505 ;
F_142 ( V_2 , V_211 ) ;
return 0 ;
}
static int F_201 ( struct V_31 * V_31 , struct V_38 * V_39 ,
const struct V_417 * V_49 ,
const struct V_422 * V_423 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_420 * V_421 = & V_2 -> V_17 . V_109 ;
int V_36 ;
memcpy ( & V_421 -> V_307 , V_49 , sizeof( struct V_417 ) ) ;
V_36 = F_195 ( V_421 , V_423 ) ;
if ( V_36 )
return V_36 ;
V_2 -> V_230 = V_232 ;
V_2 -> V_238 = V_2 -> V_22 -> V_239 ;
F_24 ( & V_2 -> V_22 -> V_183 ) ;
V_36 = F_95 ( V_2 , & V_423 -> V_181 ,
V_242 ) ;
F_26 ( & V_2 -> V_22 -> V_183 ) ;
if ( V_36 )
return V_36 ;
return F_202 ( V_2 ) ;
}
static int F_203 ( struct V_31 * V_31 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
F_204 ( V_2 ) ;
F_24 ( & V_2 -> V_22 -> V_183 ) ;
F_94 ( V_2 ) ;
F_26 ( & V_2 -> V_22 -> V_183 ) ;
return 0 ;
}
static int F_205 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
struct V_506 * V_4 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_155 * V_156 ;
T_2 V_210 = 0 ;
if ( ! F_98 ( V_2 -> V_17 . V_196 . V_212 , V_2 ) )
return - V_100 ;
V_156 = F_83 ( V_2 ) ;
if ( ! V_156 )
return - V_85 ;
if ( V_4 -> V_507 >= 0 ) {
V_2 -> V_10 . V_11 . V_507 = V_4 -> V_507 ;
V_210 |= V_508 ;
}
if ( V_4 -> V_509 >= 0 ) {
V_2 -> V_10 . V_11 . V_509 =
V_4 -> V_509 ;
V_210 |= V_510 ;
}
if ( ! V_2 -> V_10 . V_11 . V_511 &&
V_156 -> V_353 == V_512 ) {
V_2 -> V_10 . V_11 . V_511 = true ;
V_210 |= V_513 ;
}
if ( V_4 -> V_514 >= 0 ) {
V_2 -> V_10 . V_11 . V_511 =
V_4 -> V_514 ;
V_210 |= V_513 ;
}
if ( V_4 -> V_443 ) {
F_148 ( & V_2 -> V_10 . V_11 . V_181 ,
V_31 -> V_58 [ V_156 -> V_353 ] ,
V_4 -> V_443 ,
V_4 -> V_515 ,
& V_2 -> V_10 . V_11 . V_443 ) ;
V_210 |= V_516 ;
F_206 ( V_2 ) ;
}
if ( V_4 -> V_517 >= 0 ) {
if ( V_4 -> V_517 )
V_2 -> V_24 |= V_518 ;
else
V_2 -> V_24 &= ~ V_518 ;
F_22 ( V_2 ) ;
}
if ( V_4 -> V_492 >= 0 ) {
V_2 -> V_10 . V_11 . V_493 =
( T_4 ) V_4 -> V_492 ;
V_210 |= V_494 ;
}
if ( V_4 -> V_258 >= 0 ) {
V_2 -> V_10 . V_11 . V_256 . V_257 &=
~ V_259 ;
V_2 -> V_10 . V_11 . V_256 . V_257 |=
V_4 -> V_258 & V_259 ;
V_210 |= V_227 ;
}
if ( V_4 -> V_260 > 0 ) {
V_2 -> V_10 . V_11 . V_256 . V_257 |=
V_261 ;
V_210 |= V_227 ;
} else if ( V_4 -> V_260 == 0 ) {
V_2 -> V_10 . V_11 . V_256 . V_257 &=
~ V_261 ;
V_210 |= V_227 ;
}
F_3 ( V_2 , V_210 ) ;
return 0 ;
}
static int F_207 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
struct V_519 * V_4 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_520 V_521 ;
if ( ! V_22 -> V_522 -> V_523 )
return - V_29 ;
if ( V_22 -> V_63 . V_325 < V_326 )
return - V_29 ;
memset ( & V_521 , 0 , sizeof( V_521 ) ) ;
V_521 . V_524 = V_4 -> V_524 ;
V_521 . V_525 = V_4 -> V_526 ;
V_521 . V_527 = V_4 -> V_528 ;
V_521 . V_529 = V_4 -> V_529 ;
V_521 . V_530 = false ;
V_2 -> V_531 [ V_4 -> V_532 ] = V_521 ;
if ( F_208 ( V_22 , V_2 , V_4 -> V_532 , & V_521 ) ) {
F_209 ( V_22 -> V_63 . V_31 ,
L_2 ,
V_4 -> V_532 ) ;
return - V_85 ;
}
F_3 ( V_2 , V_533 ) ;
return 0 ;
}
static int F_210 ( struct V_31 * V_31 ,
struct V_534 * V_535 )
{
return F_211 ( F_12 ( V_31 ) , V_535 ) ;
}
static int F_212 ( struct V_31 * V_31 )
{
return F_213 ( F_12 ( V_31 ) ) ;
}
static int F_214 ( struct V_31 * V_31 ,
struct V_536 * V_537 )
{
struct V_1 * V_2 ;
V_2 = F_15 ( V_537 -> V_35 ) ;
switch ( F_215 ( & V_2 -> V_10 ) ) {
case V_45 :
case V_107 :
case V_108 :
case V_116 :
case V_113 :
break;
case V_117 :
if ( V_2 -> V_22 -> V_522 -> V_538 )
break;
case V_105 :
if ( V_2 -> V_17 . V_196 . V_212 &&
( ! ( V_31 -> V_539 & V_540 ) ||
! ( V_537 -> V_24 & V_541 ) ) )
return - V_29 ;
break;
case V_53 :
default:
return - V_29 ;
}
return F_216 ( V_2 , V_537 ) ;
}
static void F_217 ( struct V_31 * V_31 , struct V_30 * V_35 )
{
F_218 ( F_12 ( V_31 ) ) ;
}
static int
F_219 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
struct V_542 * V_537 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
if ( ! V_2 -> V_22 -> V_522 -> V_543 )
return - V_29 ;
return F_220 ( V_2 , V_537 ) ;
}
static int
F_221 ( struct V_31 * V_31 , struct V_38 * V_39 ,
T_1 V_544 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
if ( ! V_22 -> V_522 -> V_545 )
return - V_29 ;
return F_222 ( V_22 ) ;
}
static int F_223 ( struct V_31 * V_31 , struct V_38 * V_39 ,
struct V_546 * V_537 )
{
return F_224 ( F_19 ( V_39 ) , V_537 ) ;
}
static int F_225 ( struct V_31 * V_31 , struct V_38 * V_39 ,
struct V_547 * V_537 )
{
return F_226 ( F_19 ( V_39 ) , V_537 ) ;
}
static int F_227 ( struct V_31 * V_31 , struct V_38 * V_39 ,
struct V_548 * V_537 )
{
return F_228 ( F_19 ( V_39 ) , V_537 ) ;
}
static int F_229 ( struct V_31 * V_31 , struct V_38 * V_39 ,
struct V_549 * V_537 )
{
return F_230 ( F_19 ( V_39 ) , V_537 ) ;
}
static int F_231 ( struct V_31 * V_31 , struct V_38 * V_39 ,
struct V_550 * V_4 )
{
return F_232 ( F_19 ( V_39 ) , V_4 ) ;
}
static int F_233 ( struct V_31 * V_31 , struct V_38 * V_39 )
{
return F_234 ( F_19 ( V_39 ) ) ;
}
static int F_235 ( struct V_31 * V_31 , struct V_38 * V_39 ,
struct V_551 * V_423 )
{
return F_236 ( F_19 ( V_39 ) , V_423 ) ;
}
static int F_237 ( struct V_31 * V_31 , struct V_38 * V_39 )
{
return F_238 ( F_19 ( V_39 ) ) ;
}
static int F_239 ( struct V_31 * V_31 , struct V_38 * V_39 ,
int V_145 [ V_552 ] )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
memcpy ( V_2 -> V_10 . V_11 . V_442 , V_145 ,
sizeof( int ) * V_552 ) ;
return 0 ;
}
static int F_240 ( struct V_31 * V_31 , T_2 V_210 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
int V_36 ;
if ( V_210 & V_553 ) {
F_241 ( V_22 ) ;
V_36 = F_242 ( V_22 , V_31 -> V_554 ) ;
if ( V_36 ) {
F_241 ( V_22 ) ;
return V_36 ;
}
}
if ( ( V_210 & V_555 ) ||
( V_210 & V_556 ) ) {
T_6 V_557 ;
V_557 = V_210 & V_555 ?
V_31 -> V_557 : - 1 ;
V_36 = F_243 ( V_22 , V_557 ) ;
if ( V_36 )
return V_36 ;
}
if ( V_210 & V_558 ) {
V_36 = F_244 ( V_22 , V_31 -> V_559 ) ;
if ( V_36 )
return V_36 ;
}
if ( V_210 & V_560 ) {
if ( V_31 -> V_561 > V_562 )
return - V_85 ;
V_22 -> V_63 . V_49 . V_563 = V_31 -> V_561 ;
}
if ( V_210 & V_564 ) {
if ( V_31 -> V_565 > V_562 )
return - V_85 ;
V_22 -> V_63 . V_49 . V_566 = V_31 -> V_565 ;
}
if ( V_210 &
( V_560 | V_564 ) )
F_96 ( V_22 , V_567 ) ;
return 0 ;
}
static int F_245 ( struct V_31 * V_31 ,
struct V_30 * V_35 ,
enum V_568 type , int V_569 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
struct V_1 * V_2 ;
enum V_568 V_570 = type ;
bool V_571 = false ;
if ( V_35 ) {
V_2 = F_15 ( V_35 ) ;
switch ( type ) {
case V_572 :
V_2 -> V_573 = V_574 ;
V_570 = V_575 ;
break;
case V_575 :
case V_576 :
if ( V_569 < 0 || ( V_569 % 100 ) )
return - V_29 ;
V_2 -> V_573 = F_246 ( V_569 ) ;
break;
}
if ( V_570 != V_2 -> V_10 . V_11 . V_577 ) {
V_571 = true ;
V_2 -> V_10 . V_11 . V_577 = V_570 ;
}
F_247 ( V_2 , V_571 ) ;
return 0 ;
}
switch ( type ) {
case V_572 :
V_22 -> V_573 = V_574 ;
V_570 = V_575 ;
break;
case V_575 :
case V_576 :
if ( V_569 < 0 || ( V_569 % 100 ) )
return - V_29 ;
V_22 -> V_573 = F_246 ( V_569 ) ;
break;
}
F_24 ( & V_22 -> V_578 ) ;
F_106 (sdata, &local->interfaces, list) {
V_2 -> V_573 = V_22 -> V_573 ;
if ( V_570 != V_2 -> V_10 . V_11 . V_577 )
V_571 = true ;
V_2 -> V_10 . V_11 . V_577 = V_570 ;
}
F_106 (sdata, &local->interfaces, list)
F_247 ( V_2 , V_571 ) ;
F_26 ( & V_22 -> V_578 ) ;
return 0 ;
}
static int F_248 ( struct V_31 * V_31 ,
struct V_30 * V_35 ,
int * V_579 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
struct V_1 * V_2 = F_15 ( V_35 ) ;
if ( V_22 -> V_522 -> V_580 )
return F_249 ( V_22 , V_2 , V_579 ) ;
if ( ! V_22 -> V_184 )
* V_579 = V_22 -> V_63 . V_49 . V_581 ;
else
* V_579 = V_2 -> V_10 . V_11 . V_582 ;
return 0 ;
}
static int F_250 ( struct V_31 * V_31 , struct V_38 * V_39 ,
const T_3 * V_175 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
memcpy ( & V_2 -> V_17 . V_583 . V_584 , V_175 , V_176 ) ;
return 0 ;
}
static void F_251 ( struct V_31 * V_31 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
F_252 ( V_22 ) ;
}
static int F_253 ( struct V_31 * V_31 ,
struct V_30 * V_35 ,
void * V_200 , int V_199 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
struct V_585 * V_10 = NULL ;
if ( ! V_22 -> V_522 -> V_586 )
return - V_29 ;
if ( V_35 ) {
struct V_1 * V_2 ;
V_2 = F_15 ( V_35 ) ;
if ( V_2 -> V_24 & V_587 )
V_10 = & V_2 -> V_10 ;
}
return V_22 -> V_522 -> V_586 ( & V_22 -> V_63 , V_10 , V_200 , V_199 ) ;
}
static int F_254 ( struct V_31 * V_31 ,
struct V_279 * V_280 ,
struct V_588 * V_288 ,
void * V_200 , int V_199 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
if ( ! V_22 -> V_522 -> V_589 )
return - V_29 ;
return V_22 -> V_522 -> V_589 ( & V_22 -> V_63 , V_280 , V_288 , V_200 , V_199 ) ;
}
int F_255 ( struct V_1 * V_2 ,
enum V_590 V_230 )
{
struct V_75 * V_44 ;
enum V_590 V_591 ;
if ( F_59 ( V_2 -> V_10 . type != V_105 ) )
return - V_85 ;
if ( V_2 -> V_10 . V_11 . V_181 . V_592 == V_593 )
return 0 ;
V_591 = V_2 -> V_17 . V_196 . V_237 ;
V_2 -> V_17 . V_196 . V_237 = V_230 ;
if ( V_591 == V_230 ||
V_230 == V_594 )
return 0 ;
F_168 ( V_2 ,
L_3 ,
V_230 , F_256 ( & V_2 -> V_17 . V_196 . V_595 ) ) ;
F_24 ( & V_2 -> V_22 -> V_98 ) ;
F_106 (sta, &sdata->local->sta_list, list) {
if ( V_44 -> V_2 -> V_376 != & V_2 -> V_17 . V_196 )
continue;
if ( F_167 ( V_44 ) == 1 )
continue;
if ( F_56 ( V_44 , V_596 ) &&
! F_257 ( V_44 -> V_375 ,
V_230 ) ) {
F_168 ( V_2 , L_4 ,
V_44 -> V_44 . V_175 ) ;
continue;
}
if ( ! F_56 ( V_44 , V_298 ) )
continue;
F_168 ( V_2 , L_5 , V_44 -> V_44 . V_175 ) ;
F_169 ( V_2 , V_230 , V_44 -> V_44 . V_175 ,
V_2 -> V_10 . V_11 . V_377 ) ;
}
F_26 ( & V_2 -> V_22 -> V_98 ) ;
V_2 -> V_230 = V_230 ;
F_258 ( & V_2 -> V_22 -> V_63 , & V_2 -> V_597 ) ;
return 0 ;
}
int F_259 ( struct V_1 * V_2 ,
enum V_590 V_230 )
{
const T_3 * V_196 ;
enum V_590 V_591 ;
int V_36 ;
struct V_75 * V_44 ;
bool V_598 = false ;
F_44 ( & V_2 -> V_35 . V_183 ) ;
if ( F_59 ( V_2 -> V_10 . type != V_45 ) )
return - V_85 ;
V_591 = V_2 -> V_17 . V_46 . V_237 ;
V_2 -> V_17 . V_46 . V_237 = V_230 ;
if ( V_591 == V_230 &&
V_230 != V_594 )
return 0 ;
if ( ! V_2 -> V_17 . V_46 . V_599 ||
V_2 -> V_10 . V_11 . V_181 . V_592 == V_593 )
return 0 ;
V_196 = V_2 -> V_17 . V_46 . V_599 -> V_377 ;
F_66 () ;
F_260 (sta, &sdata->local->sta_list, list) {
if ( ! V_44 -> V_44 . V_360 || V_44 -> V_2 != V_2 || ! V_44 -> V_600 ||
! F_56 ( V_44 , V_298 ) )
continue;
V_598 = true ;
break;
}
F_74 () ;
if ( V_230 == V_594 ) {
if ( V_598 || ! V_2 -> V_17 . V_46 . V_601 )
V_230 = V_232 ;
else
V_230 = V_236 ;
}
V_36 = F_169 ( V_2 , V_230 ,
V_196 , V_196 ) ;
if ( V_36 )
V_2 -> V_17 . V_46 . V_237 = V_591 ;
else if ( V_230 != V_232 && V_598 )
F_261 ( V_2 ) ;
return V_36 ;
}
static int F_262 ( struct V_31 * V_31 , struct V_38 * V_39 ,
bool V_602 , int V_603 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_21 * V_22 = F_89 ( V_39 -> V_179 ) ;
if ( V_2 -> V_10 . type != V_45 )
return - V_29 ;
if ( ! F_147 ( & V_22 -> V_63 , V_604 ) )
return - V_29 ;
if ( V_602 == V_2 -> V_17 . V_46 . V_601 &&
V_603 == V_22 -> V_605 )
return 0 ;
V_2 -> V_17 . V_46 . V_601 = V_602 ;
V_22 -> V_605 = V_603 ;
F_263 ( V_2 ) ;
F_259 ( V_2 , V_2 -> V_17 . V_46 . V_237 ) ;
F_264 ( V_2 ) ;
if ( F_147 ( & V_22 -> V_63 , V_606 ) )
F_96 ( V_22 , V_607 ) ;
F_170 ( V_22 ) ;
F_171 ( V_2 ) ;
return 0 ;
}
static int F_265 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
T_7 V_608 , T_2 V_609 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_585 * V_10 = & V_2 -> V_10 ;
struct V_610 * V_11 = & V_10 -> V_11 ;
if ( V_608 == V_11 -> V_611 &&
V_609 == V_11 -> V_612 )
return 0 ;
if ( V_2 -> V_10 . V_613 & V_614 &&
! ( V_2 -> V_10 . V_613 & V_615 ) )
return - V_29 ;
V_11 -> V_611 = V_608 ;
V_11 -> V_612 = V_609 ;
V_11 -> V_616 = 0 ;
V_11 -> V_617 = 0 ;
V_2 -> V_17 . V_46 . V_618 = 0 ;
if ( V_2 -> V_17 . V_46 . V_599 &&
V_2 -> V_10 . V_613 & V_615 )
F_3 ( V_2 , V_619 ) ;
return 0 ;
}
static int F_266 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
T_7 V_620 , T_7 V_621 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_585 * V_10 = & V_2 -> V_10 ;
struct V_610 * V_11 = & V_10 -> V_11 ;
if ( V_2 -> V_10 . V_613 & V_614 )
return - V_29 ;
V_11 -> V_616 = V_620 ;
V_11 -> V_617 = V_621 ;
V_11 -> V_611 = 0 ;
V_11 -> V_612 = 0 ;
V_2 -> V_17 . V_46 . V_618 = 0 ;
if ( V_2 -> V_17 . V_46 . V_599 &&
V_2 -> V_10 . V_613 & V_615 )
F_3 ( V_2 , V_619 ) ;
return 0 ;
}
static int F_267 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
const T_3 * V_175 ,
const struct V_622 * V_25 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_21 * V_22 = F_89 ( V_39 -> V_179 ) ;
int V_623 , V_40 ;
if ( ! F_7 ( V_2 ) )
return - V_54 ;
if ( F_147 ( & V_22 -> V_63 , V_624 ) ) {
V_40 = F_268 ( V_22 , V_2 , V_25 ) ;
if ( V_40 )
return V_40 ;
}
if ( F_269 ( V_2 -> V_10 . V_625 ) &&
V_2 -> V_10 . V_11 . V_181 . V_626 ) {
T_2 V_443 = V_2 -> V_10 . V_11 . V_443 ;
enum V_627 V_353 = V_2 -> V_10 . V_11 . V_181 . V_626 -> V_353 ;
if ( ! ( V_25 -> V_285 [ V_353 ] . V_161 & V_443 ) )
return - V_85 ;
}
for ( V_623 = 0 ; V_623 < V_552 ; V_623 ++ ) {
struct V_155 * V_156 = V_31 -> V_58 [ V_623 ] ;
int V_628 ;
V_2 -> V_629 [ V_623 ] = V_25 -> V_285 [ V_623 ] . V_161 ;
memcpy ( V_2 -> V_630 [ V_623 ] , V_25 -> V_285 [ V_623 ] . V_631 ,
sizeof( V_25 -> V_285 [ V_623 ] . V_631 ) ) ;
memcpy ( V_2 -> V_632 [ V_623 ] ,
V_25 -> V_285 [ V_623 ] . V_633 ,
sizeof( V_25 -> V_285 [ V_623 ] . V_633 ) ) ;
V_2 -> V_634 [ V_623 ] = false ;
V_2 -> V_635 [ V_623 ] = false ;
if ( ! V_156 )
continue;
for ( V_628 = 0 ; V_628 < V_636 ; V_628 ++ ) {
if ( ~ V_2 -> V_630 [ V_623 ] [ V_628 ] ) {
V_2 -> V_634 [ V_623 ] = true ;
break;
}
}
for ( V_628 = 0 ; V_628 < V_637 ; V_628 ++ ) {
if ( ~ V_2 -> V_632 [ V_623 ] [ V_628 ] ) {
V_2 -> V_635 [ V_623 ] = true ;
break;
}
}
}
return 0 ;
}
static int F_270 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
struct V_180 * V_181 ,
T_2 V_638 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_36 ;
F_24 ( & V_22 -> V_183 ) ;
if ( ! F_271 ( & V_22 -> V_639 ) || V_22 -> V_640 ) {
V_36 = - V_28 ;
goto V_101;
}
V_2 -> V_230 = V_232 ;
V_2 -> V_238 = V_22 -> V_239 ;
V_36 = F_95 ( V_2 , V_181 ,
V_242 ) ;
if ( V_36 )
goto V_101;
F_272 ( & V_2 -> V_22 -> V_63 ,
& V_2 -> V_272 ,
F_273 ( V_638 ) ) ;
V_101:
F_26 ( & V_22 -> V_183 ) ;
return V_36 ;
}
static struct V_205 *
F_274 ( struct V_205 * V_212 )
{
struct V_205 * V_641 ;
T_3 * V_642 ;
int V_199 ;
V_199 = V_212 -> V_214 + V_212 -> V_216 + V_212 -> V_643 +
V_212 -> V_644 + V_212 -> V_645 +
V_212 -> V_221 ;
V_641 = F_99 ( sizeof( * V_641 ) + V_199 , V_197 ) ;
if ( ! V_641 )
return NULL ;
V_642 = ( T_3 * ) ( V_641 + 1 ) ;
if ( V_212 -> V_214 ) {
V_641 -> V_214 = V_212 -> V_214 ;
V_641 -> V_213 = V_642 ;
memcpy ( V_642 , V_212 -> V_213 , V_212 -> V_214 ) ;
V_642 += V_212 -> V_214 ;
}
if ( V_212 -> V_216 ) {
V_641 -> V_216 = V_212 -> V_216 ;
V_641 -> V_215 = V_642 ;
memcpy ( V_642 , V_212 -> V_215 , V_212 -> V_216 ) ;
V_642 += V_212 -> V_216 ;
}
if ( V_212 -> V_643 ) {
V_641 -> V_643 = V_212 -> V_643 ;
V_641 -> V_646 = V_642 ;
memcpy ( V_642 , V_212 -> V_646 , V_212 -> V_643 ) ;
V_642 += V_212 -> V_643 ;
}
if ( V_212 -> V_644 ) {
V_641 -> V_644 = V_212 -> V_644 ;
V_641 -> V_647 = V_642 ;
memcpy ( V_642 , V_212 -> V_647 , V_212 -> V_644 ) ;
V_642 += V_212 -> V_644 ;
}
if ( V_212 -> V_645 ) {
V_641 -> V_645 = V_212 -> V_645 ;
V_641 -> V_648 = V_642 ;
memcpy ( V_642 , V_212 -> V_648 , V_212 -> V_645 ) ;
V_642 += V_212 -> V_645 ;
}
if ( V_212 -> V_221 ) {
V_641 -> V_221 = V_212 -> V_221 ;
V_212 -> V_193 = V_642 ;
memcpy ( V_642 , V_212 -> V_193 , V_212 -> V_221 ) ;
V_642 += V_212 -> V_221 ;
}
return V_641 ;
}
void F_275 ( struct V_585 * V_10 )
{
struct V_1 * V_2 = F_276 ( V_10 ) ;
F_258 ( & V_2 -> V_22 -> V_63 ,
& V_2 -> V_649 ) ;
}
static int F_277 ( struct V_1 * V_2 ,
T_2 * V_210 )
{
int V_36 ;
switch ( V_2 -> V_10 . type ) {
case V_105 :
V_36 = F_102 ( V_2 , V_2 -> V_17 . V_196 . V_267 ,
NULL ) ;
F_114 ( V_2 -> V_17 . V_196 . V_267 ) ;
V_2 -> V_17 . V_196 . V_267 = NULL ;
if ( V_36 < 0 )
return V_36 ;
* V_210 |= V_36 ;
break;
case V_107 :
V_36 = F_278 ( V_2 ) ;
if ( V_36 < 0 )
return V_36 ;
* V_210 |= V_36 ;
break;
#ifdef F_58
case V_108 :
V_36 = F_279 ( V_2 ) ;
if ( V_36 < 0 )
return V_36 ;
* V_210 |= V_36 ;
break;
#endif
default:
F_40 ( 1 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_280 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_210 = 0 ;
int V_36 ;
F_111 ( V_2 ) ;
F_44 ( & V_22 -> V_183 ) ;
F_44 ( & V_22 -> V_47 ) ;
if ( V_2 -> V_650 ) {
if ( V_2 -> V_651 )
return 0 ;
return F_281 ( V_2 ) ;
}
if ( ! F_93 ( & V_2 -> V_10 . V_11 . V_181 ,
& V_2 -> V_652 ) )
return - V_85 ;
V_2 -> V_10 . V_262 = false ;
V_36 = F_277 ( V_2 , & V_210 ) ;
if ( V_36 )
return V_36 ;
F_3 ( V_2 , V_210 ) ;
if ( V_2 -> V_265 ) {
F_113 ( V_22 , V_2 ,
V_266 ) ;
V_2 -> V_265 = false ;
}
V_36 = F_282 ( V_2 ) ;
if ( V_36 )
return V_36 ;
F_283 ( V_2 -> V_39 , & V_2 -> V_652 ) ;
return 0 ;
}
static void F_284 ( struct V_1 * V_2 )
{
if ( F_280 ( V_2 ) ) {
F_285 ( V_2 , L_6 ) ;
F_286 ( V_2 -> V_22 -> V_63 . V_31 , & V_2 -> V_35 ,
V_197 ) ;
}
}
void F_287 ( struct V_653 * V_654 )
{
struct V_1 * V_2 =
F_196 ( V_654 , struct V_1 ,
V_649 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
F_263 ( V_2 ) ;
F_24 ( & V_22 -> V_183 ) ;
F_24 ( & V_22 -> V_47 ) ;
if ( ! V_2 -> V_10 . V_262 )
goto V_655;
if ( ! F_7 ( V_2 ) )
goto V_655;
F_284 ( V_2 ) ;
V_655:
F_26 ( & V_22 -> V_47 ) ;
F_26 ( & V_22 -> V_183 ) ;
F_264 ( V_2 ) ;
}
static int F_288 ( struct V_1 * V_2 ,
struct V_656 * V_4 ,
T_2 * V_210 )
{
struct V_191 V_192 = {} ;
int V_36 ;
switch ( V_2 -> V_10 . type ) {
case V_105 :
V_2 -> V_17 . V_196 . V_267 =
F_274 ( & V_4 -> V_657 ) ;
if ( ! V_2 -> V_17 . V_196 . V_267 )
return - V_198 ;
if ( V_4 -> V_218 <= 1 )
break;
if ( ( V_4 -> V_220 >
V_658 ) ||
( V_4 -> V_203 >
V_658 ) )
return - V_85 ;
V_192 . V_219 = V_4 -> V_219 ;
V_192 . V_202 = V_4 -> V_202 ;
V_192 . V_220 = V_4 -> V_220 ;
V_192 . V_203 = V_4 -> V_203 ;
V_192 . V_218 = V_4 -> V_218 ;
V_36 = F_102 ( V_2 , & V_4 -> V_659 , & V_192 ) ;
if ( V_36 < 0 ) {
F_114 ( V_2 -> V_17 . V_196 . V_267 ) ;
return V_36 ;
}
* V_210 |= V_36 ;
break;
case V_107 :
if ( ! V_2 -> V_10 . V_11 . V_660 )
return - V_85 ;
if ( V_4 -> V_181 . V_592 != V_2 -> V_17 . V_661 . V_181 . V_592 )
return - V_85 ;
switch ( V_4 -> V_181 . V_592 ) {
case V_662 :
if ( F_289 ( & V_4 -> V_181 ) !=
F_289 ( & V_2 -> V_17 . V_661 . V_181 ) )
return - V_85 ;
case V_663 :
case V_664 :
case V_593 :
case V_665 :
break;
default:
return - V_85 ;
}
if ( V_2 -> V_17 . V_661 . V_181 . V_626 -> V_353 !=
V_4 -> V_181 . V_626 -> V_353 )
return - V_85 ;
if ( V_4 -> V_218 > 1 ) {
V_36 = F_290 ( V_2 , V_4 ) ;
if ( V_36 < 0 )
return V_36 ;
* V_210 |= V_36 ;
}
F_291 ( V_2 , V_4 ) ;
break;
#ifdef F_58
case V_108 : {
struct V_420 * V_421 = & V_2 -> V_17 . V_109 ;
if ( V_4 -> V_181 . V_592 != V_2 -> V_10 . V_11 . V_181 . V_592 )
return - V_85 ;
if ( V_2 -> V_10 . V_11 . V_181 . V_626 -> V_353 !=
V_4 -> V_181 . V_626 -> V_353 )
return - V_85 ;
if ( V_421 -> V_666 == V_667 ) {
V_421 -> V_666 = V_668 ;
if ( ! V_421 -> V_669 )
V_421 -> V_669 = 1 ;
else
V_421 -> V_669 ++ ;
}
if ( V_4 -> V_218 > 1 ) {
V_36 = F_292 ( V_2 , V_4 ) ;
if ( V_36 < 0 ) {
V_421 -> V_666 = V_667 ;
return V_36 ;
}
* V_210 |= V_36 ;
}
if ( V_421 -> V_666 == V_668 )
F_291 ( V_2 , V_4 ) ;
break;
}
#endif
default:
return - V_29 ;
}
return 0 ;
}
static int
F_293 ( struct V_31 * V_31 , struct V_38 * V_39 ,
struct V_656 * V_4 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_670 V_671 ;
struct V_672 * V_49 ;
struct V_673 * V_674 ;
T_2 V_210 = 0 ;
int V_36 ;
F_111 ( V_2 ) ;
F_44 ( & V_22 -> V_183 ) ;
if ( ! F_271 ( & V_22 -> V_639 ) || V_22 -> V_640 )
return - V_28 ;
if ( V_2 -> V_35 . V_271 )
return - V_28 ;
if ( F_93 ( & V_4 -> V_181 ,
& V_2 -> V_10 . V_11 . V_181 ) )
return - V_85 ;
if ( V_2 -> V_10 . V_262 )
return - V_28 ;
F_24 ( & V_22 -> V_47 ) ;
V_49 = F_294 ( V_2 -> V_10 . V_625 ,
F_295 ( & V_22 -> V_47 ) ) ;
if ( ! V_49 ) {
V_36 = - V_28 ;
goto V_129;
}
V_674 = F_196 ( V_49 , struct V_673 , V_49 ) ;
V_671 . V_675 = 0 ;
V_671 . V_676 = 0 ;
V_671 . V_677 = V_4 -> V_677 ;
V_671 . V_181 = V_4 -> V_181 ;
V_671 . V_218 = V_4 -> V_218 ;
V_36 = F_296 ( V_2 , & V_671 ) ;
if ( V_36 )
goto V_129;
V_36 = F_297 ( V_2 , & V_4 -> V_181 ,
V_674 -> V_678 ,
V_4 -> V_679 ) ;
if ( V_36 )
goto V_129;
V_36 = F_25 ( V_2 , NULL , V_674 -> V_678 , 0 ) ;
if ( V_36 ) {
F_298 ( V_2 ) ;
goto V_129;
}
V_36 = F_288 ( V_2 , V_4 , & V_210 ) ;
if ( V_36 ) {
F_298 ( V_2 ) ;
goto V_129;
}
V_2 -> V_652 = V_4 -> V_181 ;
V_2 -> V_265 = V_4 -> V_677 ;
V_2 -> V_10 . V_262 = true ;
if ( V_2 -> V_265 )
F_299 ( V_22 , V_2 ,
V_266 ) ;
F_300 ( V_2 -> V_39 , & V_2 -> V_652 ,
V_4 -> V_218 ) ;
if ( V_210 ) {
F_3 ( V_2 , V_210 ) ;
F_301 ( V_2 , & V_4 -> V_181 ) ;
} else {
F_284 ( V_2 ) ;
}
V_129:
F_26 ( & V_22 -> V_47 ) ;
return V_36 ;
}
int V_670 ( struct V_31 * V_31 , struct V_38 * V_39 ,
struct V_656 * V_4 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_36 ;
F_24 ( & V_22 -> V_183 ) ;
V_36 = F_293 ( V_31 , V_39 , V_4 ) ;
F_26 ( & V_22 -> V_183 ) ;
return V_36 ;
}
T_1 F_302 ( struct V_21 * V_22 )
{
F_44 ( & V_22 -> V_183 ) ;
V_22 -> V_680 ++ ;
if ( F_40 ( V_22 -> V_680 == 0 ) )
V_22 -> V_680 ++ ;
return V_22 -> V_680 ;
}
int F_303 ( struct V_21 * V_22 , struct V_279 * V_280 ,
T_1 * V_67 , T_8 V_681 )
{
unsigned long V_682 ;
struct V_279 * V_683 ;
int V_69 ;
V_683 = F_304 ( V_280 , V_681 ) ;
if ( ! V_683 )
return - V_198 ;
F_305 ( & V_22 -> V_684 , V_682 ) ;
V_69 = F_38 ( & V_22 -> V_685 , V_683 ,
1 , 0x10000 , V_65 ) ;
F_306 ( & V_22 -> V_684 , V_682 ) ;
if ( V_69 < 0 ) {
F_307 ( V_683 ) ;
return - V_198 ;
}
F_308 ( V_280 ) -> V_686 = V_69 ;
* V_67 = F_302 ( V_22 ) ;
F_308 ( V_683 ) -> V_687 . V_67 = * V_67 ;
return 0 ;
}
static void F_309 ( struct V_31 * V_31 ,
struct V_30 * V_35 ,
T_4 V_688 , bool V_689 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
struct V_1 * V_2 = F_15 ( V_35 ) ;
switch ( V_688 ) {
case V_690 | V_691 :
if ( V_689 ) {
V_22 -> V_692 ++ ;
V_2 -> V_10 . V_692 ++ ;
} else {
if ( V_22 -> V_692 )
V_22 -> V_692 -- ;
if ( V_2 -> V_10 . V_692 )
V_2 -> V_10 . V_692 -- ;
}
if ( ! V_22 -> V_186 )
break;
if ( V_2 -> V_10 . V_692 == 1 )
F_310 ( V_22 , V_2 , V_693 ,
V_693 ) ;
else if ( V_2 -> V_10 . V_692 == 0 )
F_310 ( V_22 , V_2 , 0 ,
V_693 ) ;
F_10 ( V_22 ) ;
break;
default:
break;
}
}
static int F_311 ( struct V_31 * V_31 , T_2 V_694 , T_2 V_695 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
if ( V_22 -> V_696 )
return - V_29 ;
return F_312 ( V_22 , V_694 , V_695 ) ;
}
static int F_313 ( struct V_31 * V_31 , T_2 * V_694 , T_2 * V_695 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
return F_314 ( V_22 , V_694 , V_695 ) ;
}
static int F_315 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
struct V_697 * V_200 )
{
struct V_21 * V_22 = F_12 ( V_31 ) ;
struct V_1 * V_2 = F_19 ( V_39 ) ;
if ( ! V_22 -> V_522 -> V_698 )
return - V_29 ;
F_316 ( V_22 , V_2 , V_200 ) ;
return 0 ;
}
static int F_317 ( struct V_31 * V_31 , struct V_38 * V_39 ,
const T_3 * V_699 , T_1 * V_67 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_700 * V_701 ;
struct V_279 * V_280 ;
int V_209 = sizeof( * V_701 ) ;
T_9 V_702 ;
bool V_703 ;
struct V_704 * V_705 ;
struct V_75 * V_44 ;
struct V_672 * V_625 ;
enum V_627 V_353 ;
int V_40 ;
F_24 ( & V_22 -> V_183 ) ;
F_66 () ;
V_625 = F_67 ( V_2 -> V_10 . V_625 ) ;
if ( F_40 ( ! V_625 ) ) {
V_40 = - V_85 ;
goto V_655;
}
V_353 = V_625 -> V_706 . V_626 -> V_353 ;
V_44 = F_55 ( V_2 , V_699 ) ;
if ( V_44 ) {
V_703 = V_44 -> V_44 . V_327 ;
} else {
V_40 = - V_707 ;
goto V_655;
}
if ( V_703 ) {
V_702 = F_318 ( V_708 |
V_709 |
V_710 ) ;
} else {
V_209 -= 2 ;
V_702 = F_318 ( V_708 |
V_711 |
V_710 ) ;
}
V_280 = F_125 ( V_22 -> V_63 . V_712 + V_209 ) ;
if ( ! V_280 ) {
V_40 = - V_198 ;
goto V_655;
}
V_280 -> V_39 = V_39 ;
F_319 ( V_280 , V_22 -> V_63 . V_712 ) ;
V_701 = ( void * ) F_126 ( V_280 , V_209 ) ;
V_701 -> V_713 = V_702 ;
V_701 -> V_714 = 0 ;
memcpy ( V_701 -> V_715 , V_44 -> V_44 . V_175 , V_176 ) ;
memcpy ( V_701 -> V_716 , V_2 -> V_10 . V_175 , V_176 ) ;
memcpy ( V_701 -> V_717 , V_2 -> V_10 . V_175 , V_176 ) ;
V_701 -> V_718 = 0 ;
V_705 = F_308 ( V_280 ) ;
V_705 -> V_24 |= V_719 |
V_720 ;
V_705 -> V_353 = V_353 ;
F_320 ( V_280 , V_721 ) ;
V_280 -> V_722 = 7 ;
if ( V_703 )
V_701 -> V_723 = F_318 ( 7 ) ;
V_40 = F_303 ( V_22 , V_280 , V_67 , V_65 ) ;
if ( V_40 ) {
F_307 ( V_280 ) ;
goto V_655;
}
F_321 () ;
F_322 ( V_2 , V_44 , V_280 ) ;
F_323 () ;
V_40 = 0 ;
V_655:
F_74 () ;
F_26 ( & V_22 -> V_183 ) ;
return V_40 ;
}
static int F_324 ( struct V_31 * V_31 ,
struct V_30 * V_35 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = F_15 ( V_35 ) ;
struct V_21 * V_22 = F_12 ( V_31 ) ;
struct V_672 * V_625 ;
int V_40 = - V_724 ;
F_66 () ;
V_625 = F_67 ( V_2 -> V_10 . V_625 ) ;
if ( V_625 ) {
* V_181 = V_2 -> V_10 . V_11 . V_181 ;
V_40 = 0 ;
} else if ( V_22 -> V_186 > 0 &&
V_22 -> V_186 == V_22 -> V_187 &&
V_2 -> V_10 . type == V_37 ) {
if ( V_22 -> V_184 )
* V_181 = V_22 -> V_182 ;
else
* V_181 = V_22 -> V_188 ;
V_40 = 0 ;
}
F_74 () ;
return V_40 ;
}
static void F_325 ( struct V_31 * V_31 , bool V_602 )
{
F_326 ( F_12 ( V_31 ) , V_602 ) ;
}
static int F_327 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
struct V_725 * V_726 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_727 * V_728 , * V_729 ;
if ( V_726 ) {
V_728 = F_99 ( sizeof( * V_728 ) , V_197 ) ;
if ( ! V_728 )
return - V_198 ;
memcpy ( & V_728 -> V_726 , V_726 , sizeof( * V_726 ) ) ;
} else {
V_728 = NULL ;
}
V_729 = F_98 ( V_2 -> V_726 , V_2 ) ;
F_100 ( V_2 -> V_726 , V_728 ) ;
if ( V_729 )
F_101 ( V_729 , V_204 ) ;
return 0 ;
}
static int F_328 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
int V_40 ;
T_2 V_210 = 0 ;
V_40 = F_329 ( V_2 , V_181 , & V_210 ) ;
if ( V_40 == 0 )
F_3 ( V_2 , V_210 ) ;
return V_40 ;
}
static int F_330 ( struct V_31 * V_31 , struct V_38 * V_39 ,
T_3 V_730 , const T_3 * V_699 , T_3 V_731 ,
T_4 V_732 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_733 * V_734 = & V_2 -> V_17 . V_46 ;
int V_532 = V_735 [ V_731 ] ;
if ( V_2 -> V_10 . type != V_45 )
return - V_29 ;
if ( ! ( V_2 -> V_736 & F_132 ( V_731 ) ) )
return - V_85 ;
if ( V_734 -> V_737 [ V_532 ] . V_732 )
return - V_28 ;
if ( V_732 ) {
V_734 -> V_737 [ V_532 ] . V_732 = 32 * V_732 ;
V_734 -> V_737 [ V_532 ] . V_730 = V_730 ;
V_734 -> V_737 [ V_532 ] . V_731 = V_731 ;
}
return 0 ;
}
static int F_331 ( struct V_31 * V_31 , struct V_38 * V_39 ,
T_3 V_730 , const T_3 * V_699 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
struct V_733 * V_734 = & V_2 -> V_17 . V_46 ;
struct V_21 * V_22 = F_12 ( V_31 ) ;
int V_532 ;
for ( V_532 = 0 ; V_532 < V_326 ; V_532 ++ ) {
struct V_738 * V_737 = & V_734 -> V_737 [ V_532 ] ;
if ( ! V_737 -> V_732 )
continue;
if ( V_737 -> V_730 != V_730 )
continue;
V_737 -> V_731 = - 1 ;
F_332 () ;
F_333 ( V_22 , V_2 , false ) ;
V_737 -> V_739 = V_740 ;
V_737 -> V_741 = false ;
F_334 ( V_2 ) ;
memset ( V_737 , 0 , sizeof( * V_737 ) ) ;
return 0 ;
}
return - V_100 ;
}
void F_335 ( struct V_585 * V_10 ,
T_3 V_742 ,
enum V_743 V_744 ,
T_8 V_681 )
{
struct V_1 * V_2 = F_276 ( V_10 ) ;
struct V_59 * V_68 ;
T_1 V_67 ;
if ( F_40 ( V_10 -> type != V_53 ) )
return;
F_37 ( & V_2 -> V_17 . V_50 . V_61 ) ;
V_68 = F_336 ( & V_2 -> V_17 . V_50 . V_62 , V_742 ) ;
if ( F_40 ( ! V_68 ) ) {
F_39 ( & V_2 -> V_17 . V_50 . V_61 ) ;
return;
}
V_67 = V_68 -> V_67 ;
F_42 ( & V_2 -> V_17 . V_50 . V_62 , V_742 ) ;
F_39 ( & V_2 -> V_17 . V_50 . V_61 ) ;
F_337 ( V_68 ) ;
F_338 ( F_339 ( V_10 ) , V_742 ,
V_744 , V_67 , V_681 ) ;
}
void F_340 ( struct V_585 * V_10 ,
struct V_745 * V_746 ,
T_8 V_681 )
{
struct V_1 * V_2 = F_276 ( V_10 ) ;
struct V_59 * V_68 ;
if ( F_40 ( V_10 -> type != V_53 ) )
return;
F_37 ( & V_2 -> V_17 . V_50 . V_61 ) ;
V_68 = F_336 ( & V_2 -> V_17 . V_50 . V_62 , V_746 -> V_742 ) ;
if ( F_40 ( ! V_68 ) ) {
F_39 ( & V_2 -> V_17 . V_50 . V_61 ) ;
return;
}
V_746 -> V_67 = V_68 -> V_67 ;
F_39 ( & V_2 -> V_17 . V_50 . V_61 ) ;
F_341 ( F_339 ( V_10 ) , V_746 , V_681 ) ;
}
static int F_342 ( struct V_31 * V_31 ,
struct V_38 * V_39 ,
const bool V_602 )
{
struct V_1 * V_2 = F_19 ( V_39 ) ;
V_2 -> V_17 . V_196 . V_747 = V_602 ;
return 0 ;
}
