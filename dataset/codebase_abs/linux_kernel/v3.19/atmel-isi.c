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
T_1 V_11 , T_1 V_12 )
{
T_1 V_13 , V_14 ;
switch ( V_12 ) {
case V_15 :
V_14 = V_16 ;
break;
case V_17 :
V_14 = V_18 ;
break;
case V_19 :
V_14 = V_20 ;
break;
case V_21 :
V_14 = V_22 ;
break;
case V_23 :
V_14 = V_24 ;
break;
default:
return - V_25 ;
}
F_2 ( V_6 , V_26 , V_27 ) ;
V_13 = F_4 ( V_6 , V_28 ) ;
V_13 &= ~ V_29 ;
V_13 |= V_14 ;
V_13 &= ~ ( V_30 ) ;
V_13 |= ( ( V_10 - 1 ) << V_31 ) &
V_30 ;
V_13 &= ~ ( V_32 ) ;
V_13 |= ( ( V_11 - 1 ) << V_33 )
& V_32 ;
F_2 ( V_6 , V_28 , V_13 ) ;
return 0 ;
}
static T_2 F_7 ( struct V_5 * V_6 )
{
if ( V_6 -> V_34 ) {
struct V_35 * V_36 = & V_6 -> V_34 -> V_36 ;
struct V_37 * V_38 = V_6 -> V_34 ;
F_8 ( & V_38 -> V_39 ) ;
F_9 ( & V_36 -> V_40 . V_41 ) ;
V_36 -> V_40 . V_42 = V_6 -> V_42 ++ ;
F_10 ( V_36 , V_43 ) ;
}
if ( F_11 ( & V_6 -> V_44 ) ) {
V_6 -> V_34 = NULL ;
} else {
V_6 -> V_34 = F_12 ( V_6 -> V_44 . V_45 ,
struct V_37 , V_39 ) ;
F_2 ( V_6 , V_46 ,
( T_1 ) V_6 -> V_34 -> V_47 -> V_48 ) ;
F_2 ( V_6 , V_49 ,
V_50 | V_51 ) ;
F_2 ( V_6 , V_52 , V_53 ) ;
}
return V_54 ;
}
static T_2 F_13 ( int V_55 , void * V_56 )
{
struct V_5 * V_6 = V_56 ;
T_1 V_57 , V_58 , V_59 ;
T_2 V_60 = V_61 ;
F_14 ( & V_6 -> V_62 ) ;
V_57 = F_4 ( V_6 , V_63 ) ;
V_58 = F_4 ( V_6 , V_64 ) ;
V_59 = V_57 & V_58 ;
if ( V_59 & V_65 ) {
F_15 ( & V_6 -> F_15 ) ;
F_2 ( V_6 , V_66 , V_65 ) ;
V_60 = V_54 ;
} else if ( V_59 & V_27 ) {
F_15 ( & V_6 -> F_15 ) ;
F_2 ( V_6 , V_66 , V_27 ) ;
V_60 = V_54 ;
} else {
if ( F_16 ( V_59 & V_67 ) )
V_60 = F_7 ( V_6 ) ;
}
F_17 ( & V_6 -> V_62 ) ;
return V_60 ;
}
static int F_18 ( struct V_5 * V_6 , int V_68 )
{
unsigned long V_69 ;
F_19 ( & V_6 -> F_15 ) ;
if ( V_68 ) {
F_2 ( V_6 , V_70 , V_65 ) ;
F_2 ( V_6 , V_26 , V_65 ) ;
} else {
F_2 ( V_6 , V_70 , V_27 ) ;
F_2 ( V_6 , V_26 , V_27 ) ;
}
V_69 = F_20 ( & V_6 -> F_15 ,
F_21 ( 100 ) ) ;
if ( V_69 == 0 )
return - V_71 ;
return 0 ;
}
static int F_22 ( struct V_72 * V_73 , const struct V_74 * V_75 ,
unsigned int * V_76 , unsigned int * V_77 ,
unsigned int V_78 [] , void * V_79 [] )
{
struct V_80 * V_81 = F_23 ( V_73 ) ;
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
unsigned long V_86 ;
V_86 = V_81 -> V_87 ;
if ( ! * V_76 || * V_76 > V_88 )
* V_76 = V_88 ;
if ( V_86 * * V_76 > V_89 )
* V_76 = V_89 / V_86 ;
* V_77 = 1 ;
V_78 [ 0 ] = V_86 ;
V_79 [ 0 ] = V_6 -> V_90 ;
V_6 -> V_42 = 0 ;
V_6 -> V_34 = NULL ;
F_25 ( V_81 -> V_84 , L_1 , V_91 ,
* V_76 , V_86 ) ;
return 0 ;
}
static int F_26 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_27 ( V_36 , struct V_37 , V_36 ) ;
V_38 -> V_47 = NULL ;
F_28 ( & V_38 -> V_39 ) ;
return 0 ;
}
static int F_29 ( struct V_35 * V_36 )
{
struct V_80 * V_81 = F_23 ( V_36 -> V_72 ) ;
struct V_37 * V_38 = F_27 ( V_36 , struct V_37 , V_36 ) ;
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
unsigned long V_86 ;
struct V_92 * V_93 ;
V_86 = V_81 -> V_87 ;
if ( F_30 ( V_36 , 0 ) < V_86 ) {
F_31 ( V_81 -> V_84 , L_2 ,
V_91 , F_30 ( V_36 , 0 ) , V_86 ) ;
return - V_25 ;
}
F_32 ( & V_38 -> V_36 , 0 , V_86 ) ;
if ( ! V_38 -> V_47 ) {
if ( F_11 ( & V_6 -> V_94 ) ) {
F_31 ( V_81 -> V_84 , L_3 ) ;
return - V_25 ;
} else {
V_93 = F_12 ( V_6 -> V_94 . V_45 ,
struct V_92 , V_39 ) ;
F_8 ( & V_93 -> V_39 ) ;
V_93 -> V_95 -> V_96 =
F_33 ( V_36 , 0 ) ;
V_93 -> V_95 -> V_97 = 0 ;
F_1 ( V_93 -> V_95 , V_98 ) ;
V_38 -> V_47 = V_93 ;
}
}
return 0 ;
}
static void F_34 ( struct V_35 * V_36 )
{
struct V_80 * V_81 = F_23 ( V_36 -> V_72 ) ;
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
struct V_37 * V_38 = F_27 ( V_36 , struct V_37 , V_36 ) ;
if ( V_38 -> V_47 )
F_35 ( & V_38 -> V_47 -> V_39 , & V_6 -> V_94 ) ;
}
static void F_36 ( struct V_5 * V_6 , struct V_37 * V_99 )
{
T_1 V_3 , V_100 ;
V_100 = F_4 ( V_6 , V_101 ) ;
F_2 ( V_6 , V_70 ,
V_67 | V_102 ) ;
if ( F_4 ( V_6 , V_63 ) & V_103 ) {
F_31 ( V_6 -> V_104 . V_81 -> V_84 , L_4 ) ;
return;
}
F_2 ( V_6 , V_46 , ( T_1 ) V_99 -> V_47 -> V_48 ) ;
F_2 ( V_6 , V_49 , V_50 | V_51 ) ;
F_2 ( V_6 , V_52 , V_53 ) ;
V_100 &= ~ V_105 ;
V_100 |= V_6 -> V_106 . V_107 | V_108 ;
V_3 = V_103 | V_109 ;
F_2 ( V_6 , V_26 , V_3 ) ;
F_2 ( V_6 , V_101 , V_100 ) ;
}
static void F_37 ( struct V_35 * V_36 )
{
struct V_80 * V_81 = F_23 ( V_36 -> V_72 ) ;
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
struct V_37 * V_38 = F_27 ( V_36 , struct V_37 , V_36 ) ;
unsigned long V_110 = 0 ;
F_38 ( & V_6 -> V_62 , V_110 ) ;
F_39 ( & V_38 -> V_39 , & V_6 -> V_44 ) ;
if ( V_6 -> V_34 == NULL ) {
V_6 -> V_34 = V_38 ;
if ( F_40 ( V_36 -> V_72 ) )
F_36 ( V_6 , V_38 ) ;
}
F_41 ( & V_6 -> V_62 , V_110 ) ;
}
static int F_42 ( struct V_72 * V_73 , unsigned int V_111 )
{
struct V_80 * V_81 = F_23 ( V_73 ) ;
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
int V_60 ;
V_60 = F_18 ( V_6 , V_112 ) ;
if ( V_60 < 0 ) {
F_31 ( V_81 -> V_84 , L_5 ) ;
return V_60 ;
}
F_2 ( V_6 , V_66 , ( T_1 ) ~ 0UL ) ;
F_43 ( & V_6 -> V_62 ) ;
F_4 ( V_6 , V_63 ) ;
if ( V_111 )
F_36 ( V_6 , V_6 -> V_34 ) ;
F_44 ( & V_6 -> V_62 ) ;
return 0 ;
}
static void F_45 ( struct V_72 * V_73 )
{
struct V_80 * V_81 = F_23 ( V_73 ) ;
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
struct V_37 * V_38 , * V_113 ;
int V_60 = 0 ;
unsigned long V_69 ;
F_43 ( & V_6 -> V_62 ) ;
V_6 -> V_34 = NULL ;
F_46 (buf, node, &isi->video_buffer_list, list) {
F_8 ( & V_38 -> V_39 ) ;
F_10 ( & V_38 -> V_36 , V_114 ) ;
}
F_44 ( & V_6 -> V_62 ) ;
V_69 = V_115 + V_116 * V_117 ;
while ( ( F_4 ( V_6 , V_63 ) & V_103 ) &&
F_47 ( V_115 , V_69 ) )
F_48 ( 1 ) ;
if ( F_49 ( V_115 , V_69 ) ) {
F_31 ( V_81 -> V_84 ,
L_6 ) ;
return;
}
F_2 ( V_6 , V_66 ,
V_67 | V_102 ) ;
V_60 = F_18 ( V_6 , V_118 ) ;
if ( V_60 < 0 )
F_31 ( V_81 -> V_84 , L_7 ) ;
}
static int F_50 ( struct V_72 * V_119 ,
struct V_80 * V_81 )
{
V_119 -> type = V_120 ;
V_119 -> V_121 = V_122 ;
V_119 -> V_123 = V_81 ;
V_119 -> V_124 = sizeof( struct V_37 ) ;
V_119 -> V_125 = & V_126 ;
V_119 -> V_127 = & V_128 ;
V_119 -> V_129 = V_130 ;
return F_51 ( V_119 ) ;
}
static int F_52 ( struct V_80 * V_81 ,
struct V_74 * V_131 )
{
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
struct V_132 * V_133 = F_53 ( V_81 ) ;
const struct V_134 * V_135 ;
struct V_136 * V_137 = & V_131 -> V_75 . V_137 ;
struct V_138 V_139 ;
int V_60 ;
V_135 = F_54 ( V_81 , V_137 -> V_140 ) ;
if ( ! V_135 ) {
F_55 ( V_81 -> V_84 , L_8 ,
V_137 -> V_140 ) ;
return - V_25 ;
}
F_25 ( V_81 -> V_84 , L_9 ,
V_137 -> V_10 , V_137 -> V_11 ) ;
V_139 . V_10 = V_137 -> V_10 ;
V_139 . V_11 = V_137 -> V_11 ;
V_139 . V_141 = V_137 -> V_141 ;
V_139 . V_142 = V_137 -> V_142 ;
V_139 . V_12 = V_135 -> V_12 ;
V_60 = F_56 ( V_133 , V_143 , V_144 , & V_139 ) ;
if ( V_60 < 0 )
return V_60 ;
if ( V_139 . V_12 != V_135 -> V_12 )
return - V_25 ;
V_60 = F_6 ( V_6 , V_137 -> V_10 , V_137 -> V_11 , V_135 -> V_12 ) ;
if ( V_60 < 0 )
return V_60 ;
V_137 -> V_10 = V_139 . V_10 ;
V_137 -> V_11 = V_139 . V_11 ;
V_137 -> V_141 = V_139 . V_141 ;
V_137 -> V_142 = V_139 . V_142 ;
V_81 -> V_145 = V_135 ;
F_25 ( V_81 -> V_84 , L_10 ,
V_137 -> V_10 , V_137 -> V_11 ) ;
return V_60 ;
}
static int F_57 ( struct V_80 * V_81 ,
struct V_74 * V_131 )
{
struct V_132 * V_133 = F_53 ( V_81 ) ;
const struct V_134 * V_135 ;
struct V_136 * V_137 = & V_131 -> V_75 . V_137 ;
struct V_138 V_139 ;
T_1 V_146 = V_137 -> V_140 ;
int V_60 ;
V_135 = F_54 ( V_81 , V_146 ) ;
if ( V_146 && ! V_135 ) {
F_55 ( V_81 -> V_84 , L_8 , V_146 ) ;
return - V_25 ;
}
if ( V_137 -> V_11 > V_147 )
V_137 -> V_11 = V_147 ;
if ( V_137 -> V_10 > V_148 )
V_137 -> V_10 = V_148 ;
V_139 . V_10 = V_137 -> V_10 ;
V_139 . V_11 = V_137 -> V_11 ;
V_139 . V_141 = V_137 -> V_141 ;
V_139 . V_142 = V_137 -> V_142 ;
V_139 . V_12 = V_135 -> V_12 ;
V_60 = F_56 ( V_133 , V_143 , V_149 , & V_139 ) ;
if ( V_60 < 0 )
return V_60 ;
V_137 -> V_10 = V_139 . V_10 ;
V_137 -> V_11 = V_139 . V_11 ;
V_137 -> V_142 = V_139 . V_142 ;
switch ( V_139 . V_141 ) {
case V_150 :
V_137 -> V_141 = V_151 ;
break;
case V_151 :
break;
default:
F_31 ( V_81 -> V_84 , L_11 ,
V_139 . V_141 ) ;
V_60 = - V_25 ;
}
return V_60 ;
}
static bool F_58 ( const struct V_152 * V_75 )
{
return V_75 -> V_153 == V_154 ||
( V_75 -> V_155 == 8 &&
V_75 -> V_153 == V_156 ) ||
( V_75 -> V_155 > 8 &&
V_75 -> V_153 == V_157 ) ;
}
static int F_59 ( struct V_80 * V_81 ,
unsigned char V_158 )
{
struct V_132 * V_133 = F_53 ( V_81 ) ;
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
struct V_159 V_160 = { . type = V_161 ,} ;
unsigned long V_162 ;
int V_60 ;
V_60 = F_56 ( V_133 , V_143 , V_163 , & V_160 ) ;
if ( ! V_60 ) {
V_162 = F_60 ( & V_160 ,
V_164 ) ;
if ( ! V_162 ) {
F_55 ( V_81 -> V_84 ,
L_12 ,
V_160 . V_110 , V_164 ) ;
return - V_25 ;
}
} else if ( V_60 != - V_165 ) {
return V_60 ;
}
if ( ( 1 << ( V_158 - 1 ) ) & V_6 -> V_166 )
return 0 ;
return - V_25 ;
}
static int F_61 ( struct V_80 * V_81 ,
unsigned int V_167 ,
struct V_134 * V_135 )
{
struct V_132 * V_133 = F_53 ( V_81 ) ;
int V_168 = 0 , V_60 ;
T_1 V_12 ;
const struct V_152 * V_75 ;
V_60 = F_56 ( V_133 , V_143 , V_169 , V_167 , & V_12 ) ;
if ( V_60 < 0 )
return 0 ;
V_75 = F_62 ( V_12 ) ;
if ( ! V_75 ) {
F_31 ( V_81 -> V_84 ,
L_13 , V_167 , V_12 ) ;
return 0 ;
}
V_60 = F_59 ( V_81 , V_75 -> V_155 ) ;
if ( V_60 < 0 ) {
F_31 ( V_81 -> V_84 ,
L_14 ) ;
return 0 ;
}
switch ( V_12 ) {
case V_19 :
case V_17 :
case V_23 :
case V_21 :
V_168 ++ ;
if ( V_135 ) {
V_135 -> V_170 = & V_171 [ 0 ] ;
V_135 -> V_12 = V_12 ;
V_135 ++ ;
F_25 ( V_81 -> V_84 , L_15 ,
V_171 [ 0 ] . V_172 , V_12 ) ;
}
break;
default:
if ( ! F_58 ( V_75 ) )
return 0 ;
if ( V_135 )
F_25 ( V_81 -> V_84 ,
L_16 ,
V_75 -> V_172 ) ;
}
V_168 ++ ;
if ( V_135 ) {
V_135 -> V_170 = V_75 ;
V_135 -> V_12 = V_12 ;
V_135 ++ ;
}
return V_168 ;
}
static int F_63 ( struct V_80 * V_81 )
{
F_25 ( V_81 -> V_84 , L_17 ,
V_81 -> V_173 ) ;
return 0 ;
}
static void F_64 ( struct V_80 * V_81 )
{
F_25 ( V_81 -> V_84 , L_18 ,
V_81 -> V_173 ) ;
}
static int F_65 ( struct V_82 * V_83 )
{
struct V_5 * V_6 = V_83 -> V_85 ;
int V_60 ;
V_60 = F_66 ( V_6 -> V_174 ) ;
if ( V_60 )
return V_60 ;
if ( ! F_67 ( V_6 -> V_175 ) ) {
V_60 = F_66 ( V_6 -> V_175 ) ;
if ( V_60 ) {
F_68 ( V_6 -> V_174 ) ;
return V_60 ;
}
}
return 0 ;
}
static void F_69 ( struct V_82 * V_83 )
{
struct V_5 * V_6 = V_83 -> V_85 ;
if ( ! F_67 ( V_6 -> V_175 ) )
F_68 ( V_6 -> V_175 ) ;
F_68 ( V_6 -> V_174 ) ;
}
static unsigned int F_70 ( struct V_176 * V_176 , T_3 * V_177 )
{
struct V_80 * V_81 = V_176 -> V_178 ;
return F_71 ( & V_81 -> V_179 , V_176 , V_177 ) ;
}
static int F_72 ( struct V_82 * V_83 ,
struct V_180 * V_181 )
{
strcpy ( V_181 -> V_182 , L_19 ) ;
strcpy ( V_181 -> V_183 , L_20 ) ;
V_181 -> V_184 = V_185 | V_186 ;
V_181 -> V_187 = V_181 -> V_184 | V_188 ;
return 0 ;
}
static int F_73 ( struct V_80 * V_81 )
{
struct V_132 * V_133 = F_53 ( V_81 ) ;
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
struct V_159 V_160 = { . type = V_161 ,} ;
unsigned long V_162 ;
int V_60 ;
T_1 V_100 = 0 ;
V_60 = F_56 ( V_133 , V_143 , V_163 , & V_160 ) ;
if ( ! V_60 ) {
V_162 = F_60 ( & V_160 ,
V_164 ) ;
if ( ! V_162 ) {
F_55 ( V_81 -> V_84 ,
L_12 ,
V_160 . V_110 , V_164 ) ;
return - V_25 ;
}
} else if ( V_60 != - V_165 ) {
return V_60 ;
} else {
V_162 = V_164 ;
}
F_25 ( V_81 -> V_84 , L_21 ,
V_160 . V_110 , V_164 , V_162 ) ;
if ( ( V_162 & V_189 ) &&
( V_162 & V_190 ) ) {
if ( V_6 -> V_106 . V_191 )
V_162 &= ~ V_189 ;
else
V_162 &= ~ V_190 ;
}
if ( ( V_162 & V_192 ) &&
( V_162 & V_193 ) ) {
if ( V_6 -> V_106 . V_194 )
V_162 &= ~ V_192 ;
else
V_162 &= ~ V_193 ;
}
if ( ( V_162 & V_195 ) &&
( V_162 & V_196 ) ) {
if ( V_6 -> V_106 . V_197 )
V_162 &= ~ V_195 ;
else
V_162 &= ~ V_196 ;
}
V_160 . V_110 = V_162 ;
V_60 = F_56 ( V_133 , V_143 , V_198 , & V_160 ) ;
if ( V_60 < 0 && V_60 != - V_165 ) {
F_25 ( V_81 -> V_84 , L_22 ,
V_162 , V_60 ) ;
return V_60 ;
}
if ( V_162 & V_190 )
V_100 |= V_199 ;
if ( V_162 & V_193 )
V_100 |= V_200 ;
if ( V_162 & V_196 )
V_100 |= V_201 ;
if ( V_6 -> V_106 . V_202 )
V_100 |= V_203 ;
if ( V_6 -> V_106 . V_204 )
V_100 |= V_205 ;
F_2 ( V_6 , V_26 , V_27 ) ;
F_2 ( V_6 , V_101 , V_100 ) ;
return 0 ;
}
static int F_74 ( struct V_206 * V_207 )
{
struct V_82 * V_104 = F_24 ( & V_207 -> V_208 ) ;
struct V_5 * V_6 = F_27 ( V_104 ,
struct V_5 , V_104 ) ;
F_75 ( V_104 ) ;
F_76 ( V_6 -> V_90 ) ;
F_77 ( & V_207 -> V_208 ,
sizeof( struct V_1 ) * V_88 ,
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
V_6 -> V_106 . V_204 = 1 ;
V_6 -> V_106 . V_217 = V_218 ;
V_6 -> V_106 . V_107 = V_219 ;
V_212 = F_79 ( V_212 , NULL ) ;
if ( ! V_212 ) {
F_31 ( & V_207 -> V_208 , L_23 ) ;
return - V_25 ;
}
V_216 = F_80 ( V_212 , & V_215 ) ;
if ( V_216 ) {
F_31 ( & V_207 -> V_208 , L_24 ) ;
goto V_220;
}
switch ( V_215 . V_221 . V_222 . V_223 ) {
case 8 :
V_6 -> V_106 . V_224 = V_225 ;
break;
case 10 :
V_6 -> V_106 . V_224 =
V_225 | V_226 ;
break;
default:
F_31 ( & V_207 -> V_208 , L_25 ,
V_215 . V_221 . V_222 . V_223 ) ;
V_216 = - V_25 ;
goto V_220;
}
V_220:
F_81 ( V_212 ) ;
return V_216 ;
}
static int F_82 ( struct V_206 * V_207 )
{
unsigned int V_55 ;
struct V_5 * V_6 ;
struct V_227 * V_9 ;
int V_60 , V_228 ;
struct V_229 * V_208 = & V_207 -> V_208 ;
struct V_82 * V_104 ;
struct V_230 * V_106 ;
V_106 = V_208 -> V_231 ;
if ( ( ! V_106 || ! V_106 -> V_224 ) && ! V_207 -> V_208 . V_213 ) {
F_31 ( & V_207 -> V_208 ,
L_26 ) ;
return - V_25 ;
}
V_6 = F_83 ( & V_207 -> V_208 , sizeof( struct V_5 ) , V_232 ) ;
if ( ! V_6 ) {
F_31 ( & V_207 -> V_208 , L_27 ) ;
return - V_233 ;
}
V_6 -> V_174 = F_84 ( & V_207 -> V_208 , L_28 ) ;
if ( F_67 ( V_6 -> V_174 ) )
return F_85 ( V_6 -> V_174 ) ;
if ( V_106 ) {
memcpy ( & V_6 -> V_106 , V_106 , sizeof( V_6 -> V_106 ) ) ;
} else {
V_60 = F_78 ( V_6 , V_207 ) ;
if ( V_60 )
return V_60 ;
}
V_6 -> V_34 = NULL ;
F_86 ( & V_6 -> V_62 ) ;
F_28 ( & V_6 -> V_44 ) ;
F_28 ( & V_6 -> V_94 ) ;
V_6 -> V_175 = F_84 ( V_208 , L_29 ) ;
if ( ! F_67 ( V_6 -> V_175 ) ) {
V_60 = F_87 ( V_6 -> V_175 , V_6 -> V_106 . V_217 ) ;
if ( V_60 < 0 )
return V_60 ;
}
V_6 -> V_209 = F_88 ( & V_207 -> V_208 ,
sizeof( struct V_1 ) * V_88 ,
& V_6 -> V_210 ,
V_232 ) ;
if ( ! V_6 -> V_209 ) {
F_31 ( & V_207 -> V_208 , L_30 ) ;
return - V_233 ;
}
for ( V_228 = 0 ; V_228 < V_88 ; V_228 ++ ) {
V_6 -> V_234 [ V_228 ] . V_95 = V_6 -> V_209 + V_228 ;
V_6 -> V_234 [ V_228 ] . V_48 = V_6 -> V_210 +
V_228 * sizeof( struct V_1 ) ;
F_35 ( & V_6 -> V_234 [ V_228 ] . V_39 , & V_6 -> V_94 ) ;
}
V_6 -> V_90 = F_89 ( & V_207 -> V_208 ) ;
if ( F_67 ( V_6 -> V_90 ) ) {
V_60 = F_85 ( V_6 -> V_90 ) ;
goto V_235;
}
V_9 = F_90 ( V_207 , V_236 , 0 ) ;
V_6 -> V_9 = F_91 ( & V_207 -> V_208 , V_9 ) ;
if ( F_67 ( V_6 -> V_9 ) ) {
V_60 = F_85 ( V_6 -> V_9 ) ;
goto V_237;
}
if ( V_6 -> V_106 . V_224 & V_225 )
V_6 -> V_166 = 1 << 7 ;
if ( V_6 -> V_106 . V_224 & V_226 )
V_6 -> V_166 |= 1 << 9 ;
F_2 ( V_6 , V_26 , V_27 ) ;
V_55 = F_92 ( V_207 , 0 ) ;
if ( F_93 ( V_55 ) ) {
V_60 = V_55 ;
goto V_238;
}
V_60 = F_94 ( & V_207 -> V_208 , V_55 , F_13 , 0 , L_31 , V_6 ) ;
if ( V_60 ) {
F_31 ( & V_207 -> V_208 , L_32 , V_55 ) ;
goto V_238;
}
V_6 -> V_55 = V_55 ;
V_104 = & V_6 -> V_104 ;
V_104 -> V_239 = L_33 ;
V_104 -> V_125 = & V_240 ;
V_104 -> V_85 = V_6 ;
V_104 -> V_241 . V_208 = & V_207 -> V_208 ;
V_104 -> V_242 = V_207 -> V_243 ;
if ( V_6 -> V_106 . V_244 ) {
V_104 -> V_245 = V_6 -> V_106 . V_245 ;
V_104 -> V_244 = V_6 -> V_106 . V_244 ;
}
V_60 = F_95 ( V_104 ) ;
if ( V_60 ) {
F_31 ( & V_207 -> V_208 , L_34 ) ;
goto V_246;
}
return 0 ;
V_246:
V_238:
V_237:
F_76 ( V_6 -> V_90 ) ;
V_235:
F_77 ( & V_207 -> V_208 ,
sizeof( struct V_1 ) * V_88 ,
V_6 -> V_209 ,
V_6 -> V_210 ) ;
return V_60 ;
}
