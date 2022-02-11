static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 = V_3 ;
}
static void F_2 ( struct V_5 * V_6 , T_1 V_7 , T_1 V_8 )
{
F_3 ( V_8 , V_6 -> V_9 + V_7 ) ;
}
static T_1 F_4 ( struct V_5 * V_6 , T_1 V_7 )
{
return F_5 ( V_6 -> V_9 + V_7 ) ;
}
static int F_6 ( struct V_5 * V_6 , T_1 V_10 ,
T_1 V_11 , enum V_12 V_13 )
{
T_1 V_14 , V_15 ;
switch ( V_13 ) {
case V_16 :
V_15 = V_17 ;
break;
case V_18 :
V_15 = V_19 ;
break;
case V_20 :
V_15 = V_21 ;
break;
case V_22 :
V_15 = V_23 ;
break;
case V_24 :
V_15 = V_25 ;
break;
default:
return - V_26 ;
}
F_2 ( V_6 , V_27 , V_28 ) ;
V_14 = F_4 ( V_6 , V_29 ) ;
V_14 &= ~ V_30 ;
V_14 |= V_15 ;
V_14 &= ~ ( V_31 ) ;
V_14 |= ( ( V_10 - 1 ) << V_32 ) &
V_31 ;
V_14 &= ~ ( V_33 ) ;
V_14 |= ( ( V_11 - 1 ) << V_34 )
& V_33 ;
F_2 ( V_6 , V_29 , V_14 ) ;
return 0 ;
}
static T_2 F_7 ( struct V_5 * V_6 )
{
if ( V_6 -> V_35 ) {
struct V_36 * V_37 = & V_6 -> V_35 -> V_37 ;
struct V_38 * V_39 = V_6 -> V_35 ;
F_8 ( & V_39 -> V_40 ) ;
F_9 ( & V_37 -> V_41 . V_42 ) ;
V_37 -> V_41 . V_43 = V_6 -> V_43 ++ ;
F_10 ( V_37 , V_44 ) ;
}
if ( F_11 ( & V_6 -> V_45 ) ) {
V_6 -> V_35 = NULL ;
} else {
V_6 -> V_35 = F_12 ( V_6 -> V_45 . V_46 ,
struct V_38 , V_40 ) ;
F_2 ( V_6 , V_47 ,
V_6 -> V_35 -> V_48 -> V_49 ) ;
F_2 ( V_6 , V_50 ,
V_51 | V_52 ) ;
F_2 ( V_6 , V_53 , V_54 ) ;
}
return V_55 ;
}
static T_2 F_13 ( int V_56 , void * V_57 )
{
struct V_5 * V_6 = V_57 ;
T_1 V_58 , V_59 , V_60 ;
T_2 V_61 = V_62 ;
F_14 ( & V_6 -> V_63 ) ;
V_58 = F_4 ( V_6 , V_64 ) ;
V_59 = F_4 ( V_6 , V_65 ) ;
V_60 = V_58 & V_59 ;
if ( V_60 & V_66 ) {
F_15 ( & V_6 -> F_15 ) ;
F_2 ( V_6 , V_67 , V_66 ) ;
V_61 = V_55 ;
} else if ( V_60 & V_28 ) {
F_15 ( & V_6 -> F_15 ) ;
F_2 ( V_6 , V_67 , V_28 ) ;
V_61 = V_55 ;
} else {
if ( F_16 ( V_60 & V_68 ) )
V_61 = F_7 ( V_6 ) ;
}
F_17 ( & V_6 -> V_63 ) ;
return V_61 ;
}
static int F_18 ( struct V_5 * V_6 , int V_69 )
{
unsigned long V_70 ;
F_19 ( & V_6 -> F_15 ) ;
if ( V_69 ) {
F_2 ( V_6 , V_71 , V_66 ) ;
F_2 ( V_6 , V_27 , V_66 ) ;
} else {
F_2 ( V_6 , V_71 , V_28 ) ;
F_2 ( V_6 , V_27 , V_28 ) ;
}
V_70 = F_20 ( & V_6 -> F_15 ,
F_21 ( 100 ) ) ;
if ( V_70 == 0 )
return - V_72 ;
return 0 ;
}
static int F_22 ( struct V_73 * V_74 , const struct V_75 * V_76 ,
unsigned int * V_77 , unsigned int * V_78 ,
unsigned int V_79 [] , void * V_80 [] )
{
struct V_81 * V_82 = F_23 ( V_74 ) ;
struct V_83 * V_84 = F_24 ( V_82 -> V_85 ) ;
struct V_5 * V_6 = V_84 -> V_86 ;
unsigned long V_87 ;
V_87 = V_82 -> V_88 ;
if ( ! * V_77 || * V_77 > V_89 )
* V_77 = V_89 ;
if ( V_87 * * V_77 > V_90 )
* V_77 = V_90 / V_87 ;
* V_78 = 1 ;
V_79 [ 0 ] = V_87 ;
V_80 [ 0 ] = V_6 -> V_91 ;
V_6 -> V_43 = 0 ;
V_6 -> V_35 = NULL ;
F_25 ( V_82 -> V_85 , L_1 , V_92 ,
* V_77 , V_87 ) ;
return 0 ;
}
static int F_26 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = F_27 ( V_37 , struct V_38 , V_37 ) ;
V_39 -> V_48 = NULL ;
F_28 ( & V_39 -> V_40 ) ;
return 0 ;
}
static int F_29 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = F_23 ( V_37 -> V_73 ) ;
struct V_38 * V_39 = F_27 ( V_37 , struct V_38 , V_37 ) ;
struct V_83 * V_84 = F_24 ( V_82 -> V_85 ) ;
struct V_5 * V_6 = V_84 -> V_86 ;
unsigned long V_87 ;
struct V_93 * V_94 ;
V_87 = V_82 -> V_88 ;
if ( F_30 ( V_37 , 0 ) < V_87 ) {
F_31 ( V_82 -> V_85 , L_2 ,
V_92 , F_30 ( V_37 , 0 ) , V_87 ) ;
return - V_26 ;
}
F_32 ( & V_39 -> V_37 , 0 , V_87 ) ;
if ( ! V_39 -> V_48 ) {
if ( F_11 ( & V_6 -> V_95 ) ) {
F_31 ( V_82 -> V_85 , L_3 ) ;
return - V_26 ;
} else {
V_94 = F_12 ( V_6 -> V_95 . V_46 ,
struct V_93 , V_40 ) ;
F_8 ( & V_94 -> V_40 ) ;
V_94 -> V_96 -> V_97 =
F_33 ( V_37 , 0 ) ;
V_94 -> V_96 -> V_98 = 0 ;
F_1 ( V_94 -> V_96 , V_99 ) ;
V_39 -> V_48 = V_94 ;
}
}
return 0 ;
}
static void F_34 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = F_23 ( V_37 -> V_73 ) ;
struct V_83 * V_84 = F_24 ( V_82 -> V_85 ) ;
struct V_5 * V_6 = V_84 -> V_86 ;
struct V_38 * V_39 = F_27 ( V_37 , struct V_38 , V_37 ) ;
if ( V_39 -> V_48 )
F_35 ( & V_39 -> V_48 -> V_40 , & V_6 -> V_95 ) ;
}
static void F_36 ( struct V_5 * V_6 , struct V_38 * V_100 )
{
T_1 V_3 , V_101 ;
V_101 = F_4 ( V_6 , V_102 ) ;
F_2 ( V_6 , V_71 ,
V_68 | V_103 ) ;
if ( F_4 ( V_6 , V_64 ) & V_104 ) {
F_31 ( V_6 -> V_105 . V_82 -> V_85 , L_4 ) ;
return;
}
F_2 ( V_6 , V_47 , V_100 -> V_48 -> V_49 ) ;
F_2 ( V_6 , V_50 , V_51 | V_52 ) ;
F_2 ( V_6 , V_53 , V_54 ) ;
V_101 &= ~ V_106 ;
V_101 |= V_6 -> V_107 . V_108 | V_109 ;
V_3 = V_104 | V_110 ;
F_2 ( V_6 , V_27 , V_3 ) ;
F_2 ( V_6 , V_102 , V_101 ) ;
}
static void F_37 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = F_23 ( V_37 -> V_73 ) ;
struct V_83 * V_84 = F_24 ( V_82 -> V_85 ) ;
struct V_5 * V_6 = V_84 -> V_86 ;
struct V_38 * V_39 = F_27 ( V_37 , struct V_38 , V_37 ) ;
unsigned long V_111 = 0 ;
F_38 ( & V_6 -> V_63 , V_111 ) ;
F_39 ( & V_39 -> V_40 , & V_6 -> V_45 ) ;
if ( V_6 -> V_35 == NULL ) {
V_6 -> V_35 = V_39 ;
if ( F_40 ( V_37 -> V_73 ) )
F_36 ( V_6 , V_39 ) ;
}
F_41 ( & V_6 -> V_63 , V_111 ) ;
}
static int F_42 ( struct V_73 * V_74 , unsigned int V_112 )
{
struct V_81 * V_82 = F_23 ( V_74 ) ;
struct V_83 * V_84 = F_24 ( V_82 -> V_85 ) ;
struct V_5 * V_6 = V_84 -> V_86 ;
T_1 V_113 = 0 ;
int V_61 ;
V_61 = F_18 ( V_6 , V_114 ) ;
if ( V_61 < 0 ) {
F_31 ( V_82 -> V_85 , L_5 ) ;
return V_61 ;
}
F_2 ( V_6 , V_67 , ~ 0UL ) ;
F_43 ( & V_6 -> V_63 ) ;
V_113 = F_4 ( V_6 , V_64 ) ;
if ( V_112 )
F_36 ( V_6 , V_6 -> V_35 ) ;
F_44 ( & V_6 -> V_63 ) ;
return 0 ;
}
static void F_45 ( struct V_73 * V_74 )
{
struct V_81 * V_82 = F_23 ( V_74 ) ;
struct V_83 * V_84 = F_24 ( V_82 -> V_85 ) ;
struct V_5 * V_6 = V_84 -> V_86 ;
struct V_38 * V_39 , * V_115 ;
int V_61 = 0 ;
unsigned long V_70 ;
F_43 ( & V_6 -> V_63 ) ;
V_6 -> V_35 = NULL ;
F_46 (buf, node, &isi->video_buffer_list, list) {
F_8 ( & V_39 -> V_40 ) ;
F_10 ( & V_39 -> V_37 , V_116 ) ;
}
F_44 ( & V_6 -> V_63 ) ;
V_70 = V_117 + V_118 * V_119 ;
while ( ( F_4 ( V_6 , V_64 ) & V_104 ) &&
F_47 ( V_117 , V_70 ) )
F_48 ( 1 ) ;
if ( F_49 ( V_117 , V_70 ) ) {
F_31 ( V_82 -> V_85 ,
L_6 ) ;
return;
}
F_2 ( V_6 , V_67 ,
V_68 | V_103 ) ;
V_61 = F_18 ( V_6 , V_120 ) ;
if ( V_61 < 0 )
F_31 ( V_82 -> V_85 , L_7 ) ;
}
static int F_50 ( struct V_73 * V_121 ,
struct V_81 * V_82 )
{
V_121 -> type = V_122 ;
V_121 -> V_123 = V_124 ;
V_121 -> V_125 = V_82 ;
V_121 -> V_126 = sizeof( struct V_38 ) ;
V_121 -> V_127 = & V_128 ;
V_121 -> V_129 = & V_130 ;
V_121 -> V_131 = V_132 ;
return F_51 ( V_121 ) ;
}
static int F_52 ( struct V_81 * V_82 ,
struct V_75 * V_133 )
{
struct V_83 * V_84 = F_24 ( V_82 -> V_85 ) ;
struct V_5 * V_6 = V_84 -> V_86 ;
struct V_134 * V_135 = F_53 ( V_82 ) ;
const struct V_136 * V_137 ;
struct V_138 * V_139 = & V_133 -> V_76 . V_139 ;
struct V_140 V_141 ;
int V_61 ;
V_137 = F_54 ( V_82 , V_139 -> V_142 ) ;
if ( ! V_137 ) {
F_55 ( V_82 -> V_85 , L_8 ,
V_139 -> V_142 ) ;
return - V_26 ;
}
F_25 ( V_82 -> V_85 , L_9 ,
V_139 -> V_10 , V_139 -> V_11 ) ;
V_141 . V_10 = V_139 -> V_10 ;
V_141 . V_11 = V_139 -> V_11 ;
V_141 . V_143 = V_139 -> V_143 ;
V_141 . V_144 = V_139 -> V_144 ;
V_141 . V_13 = V_137 -> V_13 ;
V_61 = F_56 ( V_135 , V_145 , V_146 , & V_141 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( V_141 . V_13 != V_137 -> V_13 )
return - V_26 ;
V_61 = F_6 ( V_6 , V_139 -> V_10 , V_139 -> V_11 , V_137 -> V_13 ) ;
if ( V_61 < 0 )
return V_61 ;
V_139 -> V_10 = V_141 . V_10 ;
V_139 -> V_11 = V_141 . V_11 ;
V_139 -> V_143 = V_141 . V_143 ;
V_139 -> V_144 = V_141 . V_144 ;
V_82 -> V_147 = V_137 ;
F_25 ( V_82 -> V_85 , L_10 ,
V_139 -> V_10 , V_139 -> V_11 ) ;
return V_61 ;
}
static int F_57 ( struct V_81 * V_82 ,
struct V_75 * V_133 )
{
struct V_134 * V_135 = F_53 ( V_82 ) ;
const struct V_136 * V_137 ;
struct V_138 * V_139 = & V_133 -> V_76 . V_139 ;
struct V_140 V_141 ;
T_1 V_148 = V_139 -> V_142 ;
int V_61 ;
V_137 = F_54 ( V_82 , V_148 ) ;
if ( V_148 && ! V_137 ) {
F_55 ( V_82 -> V_85 , L_8 , V_148 ) ;
return - V_26 ;
}
if ( V_139 -> V_11 > V_149 )
V_139 -> V_11 = V_149 ;
if ( V_139 -> V_10 > V_150 )
V_139 -> V_10 = V_150 ;
V_141 . V_10 = V_139 -> V_10 ;
V_141 . V_11 = V_139 -> V_11 ;
V_141 . V_143 = V_139 -> V_143 ;
V_141 . V_144 = V_139 -> V_144 ;
V_141 . V_13 = V_137 -> V_13 ;
V_61 = F_56 ( V_135 , V_145 , V_151 , & V_141 ) ;
if ( V_61 < 0 )
return V_61 ;
V_139 -> V_10 = V_141 . V_10 ;
V_139 -> V_11 = V_141 . V_11 ;
V_139 -> V_144 = V_141 . V_144 ;
switch ( V_141 . V_143 ) {
case V_152 :
V_139 -> V_143 = V_153 ;
break;
case V_153 :
break;
default:
F_31 ( V_82 -> V_85 , L_11 ,
V_141 . V_143 ) ;
V_61 = - V_26 ;
}
return V_61 ;
}
static bool F_58 ( const struct V_154 * V_76 )
{
return V_76 -> V_155 == V_156 ||
( V_76 -> V_157 == 8 &&
V_76 -> V_155 == V_158 ) ||
( V_76 -> V_157 > 8 &&
V_76 -> V_155 == V_159 ) ;
}
static int F_59 ( struct V_81 * V_82 ,
unsigned char V_160 )
{
struct V_134 * V_135 = F_53 ( V_82 ) ;
struct V_83 * V_84 = F_24 ( V_82 -> V_85 ) ;
struct V_5 * V_6 = V_84 -> V_86 ;
struct V_161 V_162 = { . type = V_163 ,} ;
unsigned long V_164 ;
int V_61 ;
V_61 = F_56 ( V_135 , V_145 , V_165 , & V_162 ) ;
if ( ! V_61 ) {
V_164 = F_60 ( & V_162 ,
V_166 ) ;
if ( ! V_164 ) {
F_55 ( V_82 -> V_85 ,
L_12 ,
V_162 . V_111 , V_166 ) ;
return - V_26 ;
}
} else if ( V_61 != - V_167 ) {
return V_61 ;
}
if ( ( 1 << ( V_160 - 1 ) ) & V_6 -> V_168 )
return 0 ;
return - V_26 ;
}
static int F_61 ( struct V_81 * V_82 ,
unsigned int V_169 ,
struct V_136 * V_137 )
{
struct V_134 * V_135 = F_53 ( V_82 ) ;
int V_170 = 0 , V_61 ;
enum V_12 V_13 ;
const struct V_154 * V_76 ;
V_61 = F_56 ( V_135 , V_145 , V_171 , V_169 , & V_13 ) ;
if ( V_61 < 0 )
return 0 ;
V_76 = F_62 ( V_13 ) ;
if ( ! V_76 ) {
F_31 ( V_82 -> V_85 ,
L_13 , V_169 , V_13 ) ;
return 0 ;
}
V_61 = F_59 ( V_82 , V_76 -> V_157 ) ;
if ( V_61 < 0 ) {
F_31 ( V_82 -> V_85 ,
L_14 ) ;
return 0 ;
}
switch ( V_13 ) {
case V_20 :
case V_18 :
case V_24 :
case V_22 :
V_170 ++ ;
if ( V_137 ) {
V_137 -> V_172 = & V_173 [ 0 ] ;
V_137 -> V_13 = V_13 ;
V_137 ++ ;
F_25 ( V_82 -> V_85 , L_15 ,
V_173 [ 0 ] . V_174 , V_13 ) ;
}
break;
default:
if ( ! F_58 ( V_76 ) )
return 0 ;
if ( V_137 )
F_25 ( V_82 -> V_85 ,
L_16 ,
V_76 -> V_174 ) ;
}
V_170 ++ ;
if ( V_137 ) {
V_137 -> V_172 = V_76 ;
V_137 -> V_13 = V_13 ;
V_137 ++ ;
}
return V_170 ;
}
static int F_63 ( struct V_81 * V_82 )
{
F_25 ( V_82 -> V_85 , L_17 ,
V_82 -> V_175 ) ;
return 0 ;
}
static void F_64 ( struct V_81 * V_82 )
{
F_25 ( V_82 -> V_85 , L_18 ,
V_82 -> V_175 ) ;
}
static int F_65 ( struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_86 ;
int V_61 ;
V_61 = F_66 ( V_6 -> V_176 ) ;
if ( V_61 )
return V_61 ;
if ( ! F_67 ( V_6 -> V_177 ) ) {
V_61 = F_66 ( V_6 -> V_177 ) ;
if ( V_61 ) {
F_68 ( V_6 -> V_176 ) ;
return V_61 ;
}
}
return 0 ;
}
static void F_69 ( struct V_83 * V_84 )
{
struct V_5 * V_6 = V_84 -> V_86 ;
if ( ! F_67 ( V_6 -> V_177 ) )
F_68 ( V_6 -> V_177 ) ;
F_68 ( V_6 -> V_176 ) ;
}
static unsigned int F_70 ( struct V_178 * V_178 , T_3 * V_179 )
{
struct V_81 * V_82 = V_178 -> V_180 ;
return F_71 ( & V_82 -> V_181 , V_178 , V_179 ) ;
}
static int F_72 ( struct V_83 * V_84 ,
struct V_182 * V_183 )
{
strcpy ( V_183 -> V_184 , L_19 ) ;
strcpy ( V_183 -> V_185 , L_20 ) ;
V_183 -> V_186 = ( V_187 |
V_188 ) ;
return 0 ;
}
static int F_73 ( struct V_81 * V_82 )
{
struct V_134 * V_135 = F_53 ( V_82 ) ;
struct V_83 * V_84 = F_24 ( V_82 -> V_85 ) ;
struct V_5 * V_6 = V_84 -> V_86 ;
struct V_161 V_162 = { . type = V_163 ,} ;
unsigned long V_164 ;
int V_61 ;
T_1 V_101 = 0 ;
V_61 = F_56 ( V_135 , V_145 , V_165 , & V_162 ) ;
if ( ! V_61 ) {
V_164 = F_60 ( & V_162 ,
V_166 ) ;
if ( ! V_164 ) {
F_55 ( V_82 -> V_85 ,
L_12 ,
V_162 . V_111 , V_166 ) ;
return - V_26 ;
}
} else if ( V_61 != - V_167 ) {
return V_61 ;
} else {
V_164 = V_166 ;
}
F_25 ( V_82 -> V_85 , L_21 ,
V_162 . V_111 , V_166 , V_164 ) ;
if ( ( V_164 & V_189 ) &&
( V_164 & V_190 ) ) {
if ( V_6 -> V_107 . V_191 )
V_164 &= ~ V_189 ;
else
V_164 &= ~ V_190 ;
}
if ( ( V_164 & V_192 ) &&
( V_164 & V_193 ) ) {
if ( V_6 -> V_107 . V_194 )
V_164 &= ~ V_192 ;
else
V_164 &= ~ V_193 ;
}
if ( ( V_164 & V_195 ) &&
( V_164 & V_196 ) ) {
if ( V_6 -> V_107 . V_197 )
V_164 &= ~ V_195 ;
else
V_164 &= ~ V_196 ;
}
V_162 . V_111 = V_164 ;
V_61 = F_56 ( V_135 , V_145 , V_198 , & V_162 ) ;
if ( V_61 < 0 && V_61 != - V_167 ) {
F_25 ( V_82 -> V_85 , L_22 ,
V_164 , V_61 ) ;
return V_61 ;
}
if ( V_164 & V_190 )
V_101 |= V_199 ;
if ( V_164 & V_193 )
V_101 |= V_200 ;
if ( V_164 & V_196 )
V_101 |= V_201 ;
if ( V_6 -> V_107 . V_202 )
V_101 |= V_203 ;
if ( V_6 -> V_107 . V_204 )
V_101 |= V_205 ;
F_2 ( V_6 , V_27 , V_28 ) ;
F_2 ( V_6 , V_102 , V_101 ) ;
return 0 ;
}
static int F_74 ( struct V_206 * V_207 )
{
struct V_83 * V_105 = F_24 ( & V_207 -> V_208 ) ;
struct V_5 * V_6 = F_27 ( V_105 ,
struct V_5 , V_105 ) ;
F_75 ( V_105 ) ;
F_76 ( V_6 -> V_91 ) ;
F_77 ( & V_207 -> V_208 ,
sizeof( struct V_1 ) * V_89 ,
V_6 -> V_209 ,
V_6 -> V_210 ) ;
return 0 ;
}
static int F_78 ( struct V_5 * V_6 ,
struct V_206 * V_207 )
{
struct V_211 * V_212 = V_207 -> V_208 . V_213 ;
struct V_214 V_215 ;
int V_216 ;
V_6 -> V_107 . V_204 = 1 ;
V_6 -> V_107 . V_217 = V_218 ;
V_6 -> V_107 . V_108 = V_219 ;
V_212 = F_79 ( V_212 , NULL ) ;
if ( ! V_212 ) {
F_31 ( & V_207 -> V_208 , L_23 ) ;
return - V_26 ;
}
V_216 = F_80 ( V_212 , & V_215 ) ;
if ( V_216 ) {
F_31 ( & V_207 -> V_208 , L_24 ) ;
goto V_220;
}
switch ( V_215 . V_221 . V_222 . V_223 ) {
case 8 :
V_6 -> V_107 . V_224 = V_225 ;
break;
case 10 :
V_6 -> V_107 . V_224 =
V_225 | V_226 ;
break;
default:
F_31 ( & V_207 -> V_208 , L_25 ,
V_215 . V_221 . V_222 . V_223 ) ;
V_216 = - V_26 ;
goto V_220;
}
V_220:
F_81 ( V_212 ) ;
return V_216 ;
}
static int F_82 ( struct V_206 * V_207 )
{
unsigned int V_56 ;
struct V_5 * V_6 ;
struct V_227 * V_9 ;
int V_61 , V_228 ;
struct V_229 * V_208 = & V_207 -> V_208 ;
struct V_83 * V_105 ;
struct V_230 * V_107 ;
V_107 = V_208 -> V_231 ;
if ( ( ! V_107 || ! V_107 -> V_224 ) && ! V_207 -> V_208 . V_213 ) {
F_31 ( & V_207 -> V_208 ,
L_26 ) ;
return - V_26 ;
}
V_6 = F_83 ( & V_207 -> V_208 , sizeof( struct V_5 ) , V_232 ) ;
if ( ! V_6 ) {
F_31 ( & V_207 -> V_208 , L_27 ) ;
return - V_233 ;
}
V_6 -> V_176 = F_84 ( & V_207 -> V_208 , L_28 ) ;
if ( F_67 ( V_6 -> V_176 ) )
return F_85 ( V_6 -> V_176 ) ;
if ( V_107 ) {
memcpy ( & V_6 -> V_107 , V_107 , sizeof( V_6 -> V_107 ) ) ;
} else {
V_61 = F_78 ( V_6 , V_207 ) ;
if ( V_61 )
return V_61 ;
}
V_6 -> V_35 = NULL ;
F_86 ( & V_6 -> V_63 ) ;
F_28 ( & V_6 -> V_45 ) ;
F_28 ( & V_6 -> V_95 ) ;
V_6 -> V_177 = F_84 ( V_208 , L_29 ) ;
if ( ! F_67 ( V_6 -> V_177 ) ) {
V_61 = F_87 ( V_6 -> V_177 , V_6 -> V_107 . V_217 ) ;
if ( V_61 < 0 )
return V_61 ;
}
V_6 -> V_209 = F_88 ( & V_207 -> V_208 ,
sizeof( struct V_1 ) * V_89 ,
& V_6 -> V_210 ,
V_232 ) ;
if ( ! V_6 -> V_209 ) {
F_31 ( & V_207 -> V_208 , L_30 ) ;
return - V_233 ;
}
for ( V_228 = 0 ; V_228 < V_89 ; V_228 ++ ) {
V_6 -> V_234 [ V_228 ] . V_96 = V_6 -> V_209 + V_228 ;
V_6 -> V_234 [ V_228 ] . V_49 = V_6 -> V_210 +
V_228 * sizeof( struct V_1 ) ;
F_35 ( & V_6 -> V_234 [ V_228 ] . V_40 , & V_6 -> V_95 ) ;
}
V_6 -> V_91 = F_89 ( & V_207 -> V_208 ) ;
if ( F_67 ( V_6 -> V_91 ) ) {
V_61 = F_85 ( V_6 -> V_91 ) ;
goto V_235;
}
V_9 = F_90 ( V_207 , V_236 , 0 ) ;
V_6 -> V_9 = F_91 ( & V_207 -> V_208 , V_9 ) ;
if ( F_67 ( V_6 -> V_9 ) ) {
V_61 = F_85 ( V_6 -> V_9 ) ;
goto V_237;
}
if ( V_6 -> V_107 . V_224 & V_225 )
V_6 -> V_168 = 1 << 7 ;
if ( V_6 -> V_107 . V_224 & V_226 )
V_6 -> V_168 |= 1 << 9 ;
F_2 ( V_6 , V_27 , V_28 ) ;
V_56 = F_92 ( V_207 , 0 ) ;
if ( F_93 ( V_56 ) ) {
V_61 = V_56 ;
goto V_238;
}
V_61 = F_94 ( & V_207 -> V_208 , V_56 , F_13 , 0 , L_31 , V_6 ) ;
if ( V_61 ) {
F_31 ( & V_207 -> V_208 , L_32 , V_56 ) ;
goto V_238;
}
V_6 -> V_56 = V_56 ;
V_105 = & V_6 -> V_105 ;
V_105 -> V_239 = L_33 ;
V_105 -> V_127 = & V_240 ;
V_105 -> V_86 = V_6 ;
V_105 -> V_241 . V_208 = & V_207 -> V_208 ;
V_105 -> V_242 = V_207 -> V_243 ;
if ( V_6 -> V_107 . V_244 ) {
V_105 -> V_245 = V_6 -> V_107 . V_245 ;
V_105 -> V_244 = V_6 -> V_107 . V_244 ;
}
V_61 = F_95 ( V_105 ) ;
if ( V_61 ) {
F_31 ( & V_207 -> V_208 , L_34 ) ;
goto V_246;
}
return 0 ;
V_246:
V_238:
V_237:
F_76 ( V_6 -> V_91 ) ;
V_235:
F_77 ( & V_207 -> V_208 ,
sizeof( struct V_1 ) * V_89 ,
V_6 -> V_209 ,
V_6 -> V_210 ) ;
return V_61 ;
}
