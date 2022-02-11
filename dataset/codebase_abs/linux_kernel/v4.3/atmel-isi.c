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
F_43 ( V_83 -> V_112 . V_113 ) ;
V_60 = F_18 ( V_6 , V_114 ) ;
if ( V_60 < 0 ) {
F_31 ( V_81 -> V_84 , L_5 ) ;
F_44 ( V_83 -> V_112 . V_113 ) ;
return V_60 ;
}
F_2 ( V_6 , V_66 , ( T_1 ) ~ 0UL ) ;
F_45 ( & V_6 -> V_62 ) ;
F_4 ( V_6 , V_63 ) ;
if ( V_111 )
F_36 ( V_6 , V_6 -> V_34 ) ;
F_46 ( & V_6 -> V_62 ) ;
return 0 ;
}
static void F_47 ( struct V_72 * V_73 )
{
struct V_80 * V_81 = F_23 ( V_73 ) ;
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
struct V_37 * V_38 , * V_115 ;
int V_60 = 0 ;
unsigned long V_69 ;
F_45 ( & V_6 -> V_62 ) ;
V_6 -> V_34 = NULL ;
F_48 (buf, node, &isi->video_buffer_list, list) {
F_8 ( & V_38 -> V_39 ) ;
F_10 ( & V_38 -> V_36 , V_116 ) ;
}
F_46 ( & V_6 -> V_62 ) ;
V_69 = V_117 + V_118 * V_119 ;
while ( ( F_4 ( V_6 , V_63 ) & V_103 ) &&
F_49 ( V_117 , V_69 ) )
F_50 ( 1 ) ;
if ( F_51 ( V_117 , V_69 ) )
F_31 ( V_81 -> V_84 ,
L_6 ) ;
F_2 ( V_6 , V_66 ,
V_67 | V_102 ) ;
V_60 = F_18 ( V_6 , V_120 ) ;
if ( V_60 < 0 )
F_31 ( V_81 -> V_84 , L_7 ) ;
F_44 ( V_83 -> V_112 . V_113 ) ;
}
static int F_52 ( struct V_72 * V_121 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
V_121 -> type = V_122 ;
V_121 -> V_123 = V_124 ;
V_121 -> V_125 = V_81 ;
V_121 -> V_126 = sizeof( struct V_37 ) ;
V_121 -> V_127 = & V_128 ;
V_121 -> V_129 = & V_130 ;
V_121 -> V_131 = V_132 ;
V_121 -> V_62 = & V_83 -> V_133 ;
return F_53 ( V_121 ) ;
}
static int F_54 ( struct V_80 * V_81 ,
struct V_74 * V_134 )
{
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
struct V_135 * V_136 = F_55 ( V_81 ) ;
const struct V_137 * V_138 ;
struct V_139 * V_140 = & V_134 -> V_75 . V_140 ;
struct V_141 V_142 = {
. V_143 = V_144 ,
} ;
struct V_145 * V_146 = & V_142 . V_142 ;
int V_60 ;
V_138 = F_56 ( V_81 , V_140 -> V_147 ) ;
if ( ! V_138 ) {
F_57 ( V_81 -> V_84 , L_8 ,
V_140 -> V_147 ) ;
return - V_25 ;
}
F_25 ( V_81 -> V_84 , L_9 ,
V_140 -> V_10 , V_140 -> V_11 ) ;
V_146 -> V_10 = V_140 -> V_10 ;
V_146 -> V_11 = V_140 -> V_11 ;
V_146 -> V_148 = V_140 -> V_148 ;
V_146 -> V_149 = V_140 -> V_149 ;
V_146 -> V_12 = V_138 -> V_12 ;
V_60 = F_58 ( V_136 , V_150 , V_151 , NULL , & V_142 ) ;
if ( V_60 < 0 )
return V_60 ;
if ( V_146 -> V_12 != V_138 -> V_12 )
return - V_25 ;
F_43 ( V_83 -> V_112 . V_113 ) ;
V_60 = F_6 ( V_6 , V_140 -> V_10 , V_140 -> V_11 , V_138 -> V_12 ) ;
F_44 ( V_83 -> V_112 . V_113 ) ;
if ( V_60 < 0 )
return V_60 ;
V_140 -> V_10 = V_146 -> V_10 ;
V_140 -> V_11 = V_146 -> V_11 ;
V_140 -> V_148 = V_146 -> V_148 ;
V_140 -> V_149 = V_146 -> V_149 ;
V_81 -> V_152 = V_138 ;
F_25 ( V_81 -> V_84 , L_10 ,
V_140 -> V_10 , V_140 -> V_11 ) ;
return V_60 ;
}
static int F_59 ( struct V_80 * V_81 ,
struct V_74 * V_134 )
{
struct V_135 * V_136 = F_55 ( V_81 ) ;
const struct V_137 * V_138 ;
struct V_139 * V_140 = & V_134 -> V_75 . V_140 ;
struct V_153 V_154 ;
struct V_141 V_142 = {
. V_143 = V_155 ,
} ;
struct V_145 * V_146 = & V_142 . V_142 ;
T_1 V_156 = V_140 -> V_147 ;
int V_60 ;
V_138 = F_56 ( V_81 , V_156 ) ;
if ( V_156 && ! V_138 ) {
F_57 ( V_81 -> V_84 , L_8 , V_156 ) ;
return - V_25 ;
}
if ( V_140 -> V_11 > V_157 )
V_140 -> V_11 = V_157 ;
if ( V_140 -> V_10 > V_158 )
V_140 -> V_10 = V_158 ;
V_146 -> V_10 = V_140 -> V_10 ;
V_146 -> V_11 = V_140 -> V_11 ;
V_146 -> V_148 = V_140 -> V_148 ;
V_146 -> V_149 = V_140 -> V_149 ;
V_146 -> V_12 = V_138 -> V_12 ;
V_60 = F_58 ( V_136 , V_150 , V_151 , & V_154 , & V_142 ) ;
if ( V_60 < 0 )
return V_60 ;
V_140 -> V_10 = V_146 -> V_10 ;
V_140 -> V_11 = V_146 -> V_11 ;
V_140 -> V_149 = V_146 -> V_149 ;
switch ( V_146 -> V_148 ) {
case V_159 :
V_140 -> V_148 = V_160 ;
break;
case V_160 :
break;
default:
F_31 ( V_81 -> V_84 , L_11 ,
V_146 -> V_148 ) ;
V_60 = - V_25 ;
}
return V_60 ;
}
static bool F_60 ( const struct V_161 * V_75 )
{
return V_75 -> V_162 == V_163 ||
( V_75 -> V_164 == 8 &&
V_75 -> V_162 == V_165 ) ||
( V_75 -> V_164 > 8 &&
V_75 -> V_162 == V_166 ) ;
}
static int F_61 ( struct V_80 * V_81 ,
unsigned char V_167 )
{
struct V_135 * V_136 = F_55 ( V_81 ) ;
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
struct V_168 V_169 = { . type = V_170 ,} ;
unsigned long V_171 ;
int V_60 ;
V_60 = F_58 ( V_136 , V_172 , V_173 , & V_169 ) ;
if ( ! V_60 ) {
V_171 = F_62 ( & V_169 ,
V_174 ) ;
if ( ! V_171 ) {
F_57 ( V_81 -> V_84 ,
L_12 ,
V_169 . V_110 , V_174 ) ;
return - V_25 ;
}
} else if ( V_60 != - V_175 ) {
return V_60 ;
}
if ( ( 1 << ( V_167 - 1 ) ) & V_6 -> V_176 )
return 0 ;
return - V_25 ;
}
static int F_63 ( struct V_80 * V_81 ,
unsigned int V_177 ,
struct V_137 * V_138 )
{
struct V_135 * V_136 = F_55 ( V_81 ) ;
int V_178 = 0 , V_60 ;
struct V_179 V_12 = {
. V_143 = V_144 ,
. V_180 = V_177 ,
} ;
const struct V_161 * V_75 ;
V_60 = F_58 ( V_136 , V_150 , V_181 , NULL , & V_12 ) ;
if ( V_60 < 0 )
return 0 ;
V_75 = F_64 ( V_12 . V_12 ) ;
if ( ! V_75 ) {
F_31 ( V_81 -> V_84 ,
L_13 , V_177 , V_12 . V_12 ) ;
return 0 ;
}
V_60 = F_61 ( V_81 , V_75 -> V_164 ) ;
if ( V_60 < 0 ) {
F_31 ( V_81 -> V_84 ,
L_14 ) ;
return 0 ;
}
switch ( V_12 . V_12 ) {
case V_19 :
case V_17 :
case V_23 :
case V_21 :
V_178 ++ ;
if ( V_138 ) {
V_138 -> V_182 = & V_183 [ 0 ] ;
V_138 -> V_12 = V_12 . V_12 ;
V_138 ++ ;
F_25 ( V_81 -> V_84 , L_15 ,
V_183 [ 0 ] . V_184 , V_12 . V_12 ) ;
}
break;
default:
if ( ! F_60 ( V_75 ) )
return 0 ;
if ( V_138 )
F_25 ( V_81 -> V_84 ,
L_16 ,
V_75 -> V_184 ) ;
}
V_178 ++ ;
if ( V_138 ) {
V_138 -> V_182 = V_75 ;
V_138 -> V_12 = V_12 . V_12 ;
V_138 ++ ;
}
return V_178 ;
}
static int F_65 ( struct V_80 * V_81 )
{
F_25 ( V_81 -> V_84 , L_17 ,
V_81 -> V_185 ) ;
return 0 ;
}
static void F_66 ( struct V_80 * V_81 )
{
F_25 ( V_81 -> V_84 , L_18 ,
V_81 -> V_185 ) ;
}
static unsigned int F_67 ( struct V_186 * V_186 , T_3 * V_187 )
{
struct V_80 * V_81 = V_186 -> V_188 ;
return F_68 ( & V_81 -> V_189 , V_186 , V_187 ) ;
}
static int F_69 ( struct V_82 * V_83 ,
struct V_190 * V_191 )
{
strcpy ( V_191 -> V_192 , L_19 ) ;
strcpy ( V_191 -> V_193 , L_20 ) ;
V_191 -> V_194 = V_195 | V_196 ;
V_191 -> V_197 = V_191 -> V_194 | V_198 ;
return 0 ;
}
static int F_70 ( struct V_80 * V_81 )
{
struct V_135 * V_136 = F_55 ( V_81 ) ;
struct V_82 * V_83 = F_24 ( V_81 -> V_84 ) ;
struct V_5 * V_6 = V_83 -> V_85 ;
struct V_168 V_169 = { . type = V_170 ,} ;
unsigned long V_171 ;
int V_60 ;
T_1 V_100 = 0 ;
V_60 = F_58 ( V_136 , V_172 , V_173 , & V_169 ) ;
if ( ! V_60 ) {
V_171 = F_62 ( & V_169 ,
V_174 ) ;
if ( ! V_171 ) {
F_57 ( V_81 -> V_84 ,
L_12 ,
V_169 . V_110 , V_174 ) ;
return - V_25 ;
}
} else if ( V_60 != - V_175 ) {
return V_60 ;
} else {
V_171 = V_174 ;
}
F_25 ( V_81 -> V_84 , L_21 ,
V_169 . V_110 , V_174 , V_171 ) ;
if ( ( V_171 & V_199 ) &&
( V_171 & V_200 ) ) {
if ( V_6 -> V_106 . V_201 )
V_171 &= ~ V_199 ;
else
V_171 &= ~ V_200 ;
}
if ( ( V_171 & V_202 ) &&
( V_171 & V_203 ) ) {
if ( V_6 -> V_106 . V_204 )
V_171 &= ~ V_202 ;
else
V_171 &= ~ V_203 ;
}
if ( ( V_171 & V_205 ) &&
( V_171 & V_206 ) ) {
if ( V_6 -> V_106 . V_207 )
V_171 &= ~ V_205 ;
else
V_171 &= ~ V_206 ;
}
V_169 . V_110 = V_171 ;
V_60 = F_58 ( V_136 , V_172 , V_208 , & V_169 ) ;
if ( V_60 < 0 && V_60 != - V_175 ) {
F_25 ( V_81 -> V_84 , L_22 ,
V_171 , V_60 ) ;
return V_60 ;
}
if ( V_171 & V_200 )
V_100 |= V_209 ;
if ( V_171 & V_203 )
V_100 |= V_210 ;
if ( V_171 & V_206 )
V_100 |= V_211 ;
if ( V_6 -> V_106 . V_212 )
V_100 |= V_213 ;
if ( V_6 -> V_106 . V_214 )
V_100 |= V_215 ;
V_100 |= V_216 ;
F_43 ( V_83 -> V_112 . V_113 ) ;
F_2 ( V_6 , V_26 , V_27 ) ;
F_2 ( V_6 , V_101 , V_100 ) ;
F_44 ( V_83 -> V_112 . V_113 ) ;
return 0 ;
}
static int F_71 ( struct V_217 * V_218 )
{
struct V_82 * V_104 = F_24 ( & V_218 -> V_113 ) ;
struct V_5 * V_6 = F_27 ( V_104 ,
struct V_5 , V_104 ) ;
F_72 ( V_104 ) ;
F_73 ( V_6 -> V_90 ) ;
F_74 ( & V_218 -> V_113 ,
sizeof( struct V_1 ) * V_88 ,
V_6 -> V_219 ,
V_6 -> V_220 ) ;
F_75 ( & V_218 -> V_113 ) ;
return 0 ;
}
static int F_76 ( struct V_5 * V_6 ,
struct V_217 * V_218 )
{
struct V_221 * V_222 = V_218 -> V_113 . V_223 ;
struct V_224 V_225 ;
int V_226 ;
V_6 -> V_106 . V_214 = 1 ;
V_6 -> V_106 . V_107 = V_227 ;
V_222 = F_77 ( V_222 , NULL ) ;
if ( ! V_222 ) {
F_31 ( & V_218 -> V_113 , L_23 ) ;
return - V_25 ;
}
V_226 = F_78 ( V_222 , & V_225 ) ;
if ( V_226 ) {
F_31 ( & V_218 -> V_113 , L_24 ) ;
goto V_228;
}
switch ( V_225 . V_229 . V_230 . V_231 ) {
case 8 :
V_6 -> V_106 . V_232 = V_233 ;
break;
case 10 :
V_6 -> V_106 . V_232 =
V_233 | V_234 ;
break;
default:
F_31 ( & V_218 -> V_113 , L_25 ,
V_225 . V_229 . V_230 . V_231 ) ;
V_226 = - V_25 ;
goto V_228;
}
V_228:
F_79 ( V_222 ) ;
return V_226 ;
}
static int F_80 ( struct V_217 * V_218 )
{
unsigned int V_55 ;
struct V_5 * V_6 ;
struct V_235 * V_9 ;
int V_60 , V_236 ;
struct V_237 * V_113 = & V_218 -> V_113 ;
struct V_82 * V_104 ;
struct V_238 * V_106 ;
V_106 = V_113 -> V_239 ;
if ( ( ! V_106 || ! V_106 -> V_232 ) && ! V_218 -> V_113 . V_223 ) {
F_31 ( & V_218 -> V_113 ,
L_26 ) ;
return - V_25 ;
}
V_6 = F_81 ( & V_218 -> V_113 , sizeof( struct V_5 ) , V_240 ) ;
if ( ! V_6 ) {
F_31 ( & V_218 -> V_113 , L_27 ) ;
return - V_241 ;
}
V_6 -> V_242 = F_82 ( & V_218 -> V_113 , L_28 ) ;
if ( F_83 ( V_6 -> V_242 ) )
return F_84 ( V_6 -> V_242 ) ;
if ( V_106 ) {
memcpy ( & V_6 -> V_106 , V_106 , sizeof( V_6 -> V_106 ) ) ;
} else {
V_60 = F_76 ( V_6 , V_218 ) ;
if ( V_60 )
return V_60 ;
}
V_6 -> V_34 = NULL ;
F_85 ( & V_6 -> V_62 ) ;
F_28 ( & V_6 -> V_44 ) ;
F_28 ( & V_6 -> V_94 ) ;
V_6 -> V_219 = F_86 ( & V_218 -> V_113 ,
sizeof( struct V_1 ) * V_88 ,
& V_6 -> V_220 ,
V_240 ) ;
if ( ! V_6 -> V_219 ) {
F_31 ( & V_218 -> V_113 , L_29 ) ;
return - V_241 ;
}
for ( V_236 = 0 ; V_236 < V_88 ; V_236 ++ ) {
V_6 -> V_243 [ V_236 ] . V_95 = V_6 -> V_219 + V_236 ;
V_6 -> V_243 [ V_236 ] . V_48 = V_6 -> V_220 +
V_236 * sizeof( struct V_1 ) ;
F_35 ( & V_6 -> V_243 [ V_236 ] . V_39 , & V_6 -> V_94 ) ;
}
V_6 -> V_90 = F_87 ( & V_218 -> V_113 ) ;
if ( F_83 ( V_6 -> V_90 ) ) {
V_60 = F_84 ( V_6 -> V_90 ) ;
goto V_244;
}
V_9 = F_88 ( V_218 , V_245 , 0 ) ;
V_6 -> V_9 = F_89 ( & V_218 -> V_113 , V_9 ) ;
if ( F_83 ( V_6 -> V_9 ) ) {
V_60 = F_84 ( V_6 -> V_9 ) ;
goto V_246;
}
if ( V_6 -> V_106 . V_232 & V_233 )
V_6 -> V_176 = 1 << 7 ;
if ( V_6 -> V_106 . V_232 & V_234 )
V_6 -> V_176 |= 1 << 9 ;
V_55 = F_90 ( V_218 , 0 ) ;
if ( F_91 ( V_55 ) ) {
V_60 = V_55 ;
goto V_247;
}
V_60 = F_92 ( & V_218 -> V_113 , V_55 , F_13 , 0 , L_30 , V_6 ) ;
if ( V_60 ) {
F_31 ( & V_218 -> V_113 , L_31 , V_55 ) ;
goto V_247;
}
V_6 -> V_55 = V_55 ;
V_104 = & V_6 -> V_104 ;
V_104 -> V_248 = L_32 ;
V_104 -> V_127 = & V_249 ;
V_104 -> V_85 = V_6 ;
V_104 -> V_112 . V_113 = & V_218 -> V_113 ;
V_104 -> V_250 = V_218 -> V_251 ;
F_93 ( & V_218 -> V_113 , true ) ;
F_94 ( & V_218 -> V_113 ) ;
if ( V_6 -> V_106 . V_252 ) {
V_104 -> V_253 = V_6 -> V_106 . V_253 ;
V_104 -> V_252 = V_6 -> V_106 . V_252 ;
}
V_60 = F_95 ( V_104 ) ;
if ( V_60 ) {
F_31 ( & V_218 -> V_113 , L_33 ) ;
goto V_254;
}
return 0 ;
V_254:
F_75 ( & V_218 -> V_113 ) ;
V_247:
V_246:
F_73 ( V_6 -> V_90 ) ;
V_244:
F_74 ( & V_218 -> V_113 ,
sizeof( struct V_1 ) * V_88 ,
V_6 -> V_219 ,
V_6 -> V_220 ) ;
return V_60 ;
}
static int F_96 ( struct V_237 * V_113 )
{
struct V_82 * V_104 = F_24 ( V_113 ) ;
struct V_5 * V_6 = F_27 ( V_104 ,
struct V_5 , V_104 ) ;
F_97 ( V_6 -> V_242 ) ;
return 0 ;
}
static int F_98 ( struct V_237 * V_113 )
{
struct V_82 * V_104 = F_24 ( V_113 ) ;
struct V_5 * V_6 = F_27 ( V_104 ,
struct V_5 , V_104 ) ;
return F_99 ( V_6 -> V_242 ) ;
}
