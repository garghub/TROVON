static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static inline struct V_1 * F_4 ( struct V_8 * V_9 )
{
return F_2 ( V_9 , struct V_1 , V_10 ) ;
}
static void F_5 ( struct V_1 * V_11 , T_1 V_12 , T_1 V_13 , T_1 V_14 )
{
T_1 V_15 = F_6 ( V_11 -> V_16 + V_12 ) ;
F_7 ( ( V_15 & ~ V_13 ) | ( V_14 & V_13 ) , V_11 -> V_16 + V_12 ) ;
}
static void F_8 ( struct V_1 * V_11 )
{
T_1 V_17 , V_18 , V_19 , V_20 ;
T_1 V_21 , V_22 ;
V_21 = 1000 / V_11 -> V_23 + 0x01 ;
V_22 = 8000 / V_11 -> V_23 + 0x01 ;
V_17 = V_24 | V_25 << 8 | V_26 << 16 | V_27 << 24 ;
V_18 = 4 * V_24 | ( 3 * V_24 / 2 ) << 8 | 5 * V_24 << 16 |
V_28 << 24 ;
V_19 = ( ( F_9 ( 0x64 , V_22 ) + 0xa ) << 24 ) |
( F_9 ( 0x150 , V_22 ) << 16 ) ;
V_20 = F_9 ( 0x40 , V_22 ) | ( 2 * V_24 ) << 16 |
F_9 ( 80 + 52 * V_21 , V_22 ) << 8 ;
F_7 ( V_17 , V_11 -> V_16 + V_29 ) ;
F_7 ( V_18 , V_11 -> V_16 + V_30 ) ;
F_7 ( V_19 , V_11 -> V_16 + V_31 ) ;
F_7 ( V_20 , V_11 -> V_16 + V_32 ) ;
}
static void F_10 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_33 , V_34 , V_34 ) ;
}
static void F_11 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_33 , V_34 , 0 ) ;
}
static void F_12 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_33 , V_35 , V_35 ) ;
F_5 ( V_11 , V_33 , V_35 , 0 ) ;
}
static void F_13 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_36 , V_37 , 0 ) ;
F_5 ( V_11 , V_36 , V_38 , 0 ) ;
}
static void F_14 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_36 , V_38 , 0 ) ;
F_5 ( V_11 , V_36 , V_39 , V_39 ) ;
F_5 ( V_11 , V_36 , V_39 , 0 ) ;
}
static void F_15 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_40 , V_41 , 0 ) ;
F_5 ( V_11 , V_40 , V_42 , 0 ) ;
}
static void F_16 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_40 , V_42 , 0 ) ;
F_5 ( V_11 , V_40 , V_43 , V_43 ) ;
F_5 ( V_11 , V_40 , V_43 , 0 ) ;
}
static bool F_17 ( struct V_1 * V_11 )
{
T_1 V_44 ;
V_44 = F_6 ( V_11 -> V_16 + V_36 ) ;
return ( ( V_44 & V_37 ) == 1 ) ? true : false ;
}
static void F_18 ( struct V_1 * V_11 , bool V_45 )
{
if ( V_45 && ! F_17 ( V_11 ) )
F_5 ( V_11 , V_36 , V_37 , V_37 ) ;
else if ( ! V_45 && F_17 ( V_11 ) )
F_5 ( V_11 , V_36 , V_37 , 0 ) ;
}
static void F_19 ( struct V_1 * V_11 )
{
T_1 V_46 = V_47 ;
if ( V_11 -> V_48 & V_49 ) {
if ( V_11 -> V_48 & V_50 )
V_46 = V_51 ;
else if ( V_11 -> V_48 & V_52 )
V_46 = V_53 ;
else
V_46 = V_54 ;
}
F_7 ( V_46 , V_11 -> V_16 + V_55 ) ;
}
static void F_20 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_56 , V_57 , V_57 ) ;
F_5 ( V_11 , V_56 , V_58 , V_58 ) ;
}
static void F_21 ( struct V_1 * V_11 )
{
struct V_59 * V_60 = & V_11 -> V_60 ;
T_1 V_61 , V_62 ;
T_1 V_63 ;
if ( V_11 -> V_64 == V_65 )
V_61 = 2 ;
else
V_61 = 3 ;
V_62 = V_60 -> V_66 * V_61 ;
V_63 = V_62 ;
switch ( V_11 -> V_64 ) {
case V_67 :
V_63 |= V_68 ;
break;
case V_69 :
V_63 |= V_70 ;
break;
case V_71 :
V_63 |= V_72 ;
break;
case V_65 :
V_63 |= V_73 ;
break;
}
F_7 ( V_60 -> V_74 , V_11 -> V_16 + V_75 ) ;
F_7 ( V_63 , V_11 -> V_16 + V_76 ) ;
F_7 ( V_62 , V_11 -> V_16 + V_77 ) ;
}
static void F_22 ( struct V_1 * V_11 )
{
T_1 V_78 ;
switch ( V_11 -> V_79 ) {
case 1 :
V_78 = 1 << 2 ;
break;
case 2 :
V_78 = 3 << 2 ;
break;
case 3 :
V_78 = 7 << 2 ;
break;
case 4 :
V_78 = 0xf << 2 ;
break;
default:
V_78 = 0xf << 2 ;
break;
}
V_78 |= ( V_11 -> V_48 & V_80 ) << 6 ;
V_78 |= ( V_11 -> V_48 & V_81 ) >> 3 ;
F_7 ( V_78 , V_11 -> V_16 + V_82 ) ;
}
static void F_23 ( struct V_1 * V_11 )
{
T_1 V_83 ;
T_1 V_78 ;
switch ( V_11 -> V_64 ) {
case V_67 :
V_78 = V_68 ;
V_83 = 3 ;
break;
case V_69 :
V_78 = V_72 ;
V_83 = 3 ;
break;
case V_71 :
V_78 = V_70 ;
V_83 = 3 ;
break;
case V_65 :
V_78 = V_73 ;
V_83 = 2 ;
break;
default:
V_78 = V_68 ;
V_83 = 3 ;
break;
}
V_78 += V_11 -> V_60 . V_66 * V_83 & V_84 ;
F_7 ( V_78 , V_11 -> V_16 + V_76 ) ;
}
static void F_24 ( struct V_1 * V_11 )
{
T_1 V_85 ;
T_1 V_86 ;
T_1 V_87 ;
T_1 V_83 ;
struct V_59 * V_60 = & V_11 -> V_60 ;
if ( V_11 -> V_64 == V_65 )
V_83 = 2 ;
else
V_83 = 3 ;
F_7 ( V_60 -> V_88 , V_11 -> V_16 + V_89 ) ;
F_7 ( V_60 -> V_90 , V_11 -> V_16 + V_91 ) ;
F_7 ( V_60 -> V_92 , V_11 -> V_16 + V_93 ) ;
F_7 ( V_60 -> V_74 , V_11 -> V_16 + V_75 ) ;
V_85 = ( V_60 -> V_94 * V_83 - 10 ) ;
if ( V_11 -> V_48 & V_52 )
V_86 =
( V_60 -> V_95 * V_83 - 10 ) ;
else
V_86 = ( ( V_60 -> V_95 + V_60 -> V_94 ) *
V_83 - 10 ) ;
V_87 = ( V_60 -> V_96 * V_83 - 12 ) ;
F_7 ( V_85 , V_11 -> V_16 + V_97 ) ;
F_7 ( V_86 , V_11 -> V_16 + V_98 ) ;
F_7 ( V_87 , V_11 -> V_16 + V_99 ) ;
F_23 ( V_11 ) ;
}
static void F_25 ( struct V_1 * V_11 )
{
F_7 ( 0 , V_11 -> V_16 + V_100 ) ;
F_7 ( 1 , V_11 -> V_16 + V_100 ) ;
}
static void F_26 ( struct V_1 * V_11 )
{
F_7 ( 0 , V_11 -> V_16 + V_100 ) ;
}
static void F_27 ( struct V_1 * V_11 )
{
F_7 ( V_47 , V_11 -> V_16 + V_55 ) ;
}
static void F_28 ( struct V_1 * V_11 )
{
T_1 V_101 = V_102 | V_103 | V_104 ;
F_7 ( V_101 , V_11 -> V_16 + V_105 ) ;
}
static void F_29 ( struct V_1 * V_11 , T_1 V_106 )
{
V_11 -> V_107 |= V_106 ;
}
static void F_30 ( struct V_1 * V_11 , T_1 V_106 )
{
V_11 -> V_107 &= ~ V_106 ;
}
static T_2 F_31 ( struct V_1 * V_11 , T_1 V_108 ,
unsigned int V_109 )
{
T_2 V_110 = 0 ;
unsigned long V_111 = F_32 ( V_109 ) ;
V_110 = F_33 ( V_11 -> V_112 ,
V_11 -> V_107 & V_108 ,
V_111 ) ;
if ( V_110 == 0 ) {
F_34 ( L_1 , V_108 ) ;
F_10 ( V_11 ) ;
F_12 ( V_11 ) ;
}
return V_110 ;
}
static T_3 F_35 ( int V_113 , void * V_114 )
{
struct V_1 * V_11 = V_114 ;
T_1 V_115 , V_116 ;
T_1 V_117 = V_102 | V_103 | V_104 ;
V_115 = F_6 ( V_11 -> V_16 + V_118 ) & V_117 ;
if ( V_115 ) {
do {
F_5 ( V_11 , V_119 , V_120 , V_120 ) ;
V_116 = F_6 ( V_11 -> V_16 + V_118 ) ;
} while ( V_116 & V_121 );
F_5 ( V_11 , V_118 , V_115 , 0 ) ;
F_29 ( V_11 , V_115 ) ;
F_36 ( & V_11 -> V_112 ) ;
}
return V_122 ;
}
static T_2 F_37 ( struct V_1 * V_11 , T_4 V_108 , T_1 V_123 )
{
F_30 ( V_11 , V_108 ) ;
F_27 ( V_11 ) ;
if ( ! F_31 ( V_11 , V_108 , V_123 ) ) {
F_38 ( L_2 ) ;
return - V_124 ;
} else {
return 0 ;
}
}
static int F_39 ( struct V_1 * V_11 )
{
struct V_125 * V_126 = V_11 -> V_126 ;
int V_110 ;
T_5 V_127 , V_128 ;
T_1 V_129 , V_130 , V_131 , V_132 , V_133 ;
if ( ++ V_11 -> V_134 != 1 )
return 0 ;
switch ( V_11 -> V_64 ) {
case V_65 :
V_131 = 16 ;
break;
case V_71 :
V_131 = 18 ;
break;
case V_69 :
case V_67 :
default:
V_131 = 24 ;
break;
}
V_127 = V_11 -> V_60 . V_135 * 1000 ;
V_129 = V_11 -> V_60 . V_66 + V_11 -> V_60 . V_95 + V_11 -> V_60 . V_96 +
V_11 -> V_60 . V_94 ;
V_130 = V_129 * V_131 ;
V_132 = V_24 + V_25 + V_26 + V_27 +
V_28 ;
V_133 = V_132 * V_11 -> V_79 * 8 ;
V_128 = V_130 + V_133 ;
V_11 -> V_23 = F_40 ( V_127 * V_128 ,
V_129 * V_11 -> V_79 ) ;
V_110 = F_41 ( V_11 -> V_136 , V_11 -> V_23 ) ;
if ( V_110 < 0 ) {
F_42 ( V_126 , L_3 , V_110 ) ;
goto V_137;
}
F_43 ( V_11 -> V_138 ) ;
V_110 = F_44 ( V_11 -> V_139 ) ;
if ( V_110 < 0 ) {
F_42 ( V_126 , L_4 , V_110 ) ;
goto V_140;
}
V_110 = F_44 ( V_11 -> V_141 ) ;
if ( V_110 < 0 ) {
F_42 ( V_126 , L_5 , V_110 ) ;
goto V_142;
}
F_10 ( V_11 ) ;
F_12 ( V_11 ) ;
F_8 ( V_11 ) ;
F_22 ( V_11 ) ;
F_21 ( V_11 ) ;
F_20 ( V_11 ) ;
F_24 ( V_11 ) ;
F_28 ( V_11 ) ;
F_14 ( V_11 ) ;
F_16 ( V_11 ) ;
F_18 ( V_11 , 0 ) ;
if ( V_11 -> V_143 ) {
if ( F_45 ( V_11 -> V_143 ) ) {
F_38 ( L_6 ) ;
goto V_144;
}
}
return 0 ;
V_144:
F_46 ( V_11 -> V_141 ) ;
V_142:
F_46 ( V_11 -> V_139 ) ;
V_140:
F_47 ( V_11 -> V_138 ) ;
V_137:
V_11 -> V_134 -- ;
return V_110 ;
}
static void F_48 ( struct V_1 * V_11 )
{
if ( F_49 ( V_11 -> V_134 == 0 ) )
return;
if ( -- V_11 -> V_134 != 0 )
return;
if ( ! F_37 ( V_11 , V_104 , 500 ) ) {
if ( V_11 -> V_143 ) {
if ( F_50 ( V_11 -> V_143 ) ) {
F_38 ( L_7 ) ;
return;
}
}
}
F_12 ( V_11 ) ;
F_15 ( V_11 ) ;
F_13 ( V_11 ) ;
F_11 ( V_11 ) ;
F_46 ( V_11 -> V_139 ) ;
F_46 ( V_11 -> V_141 ) ;
F_47 ( V_11 -> V_138 ) ;
}
static void F_51 ( struct V_1 * V_11 )
{
int V_110 ;
if ( V_11 -> V_145 )
return;
V_110 = F_39 ( V_11 ) ;
if ( V_110 < 0 ) {
F_38 ( L_8 ) ;
return;
}
F_19 ( V_11 ) ;
F_18 ( V_11 , 1 ) ;
F_25 ( V_11 ) ;
if ( V_11 -> V_143 ) {
if ( F_52 ( V_11 -> V_143 ) ) {
F_38 ( L_9 ) ;
goto V_146;
}
}
V_11 -> V_145 = true ;
return;
V_146:
F_26 ( V_11 ) ;
F_48 ( V_11 ) ;
}
static void F_53 ( struct V_1 * V_11 )
{
if ( ! V_11 -> V_145 )
return;
if ( V_11 -> V_143 ) {
if ( F_54 ( V_11 -> V_143 ) ) {
F_38 ( L_10 ) ;
return;
}
}
F_26 ( V_11 ) ;
F_48 ( V_11 ) ;
V_11 -> V_145 = false ;
}
static void F_55 ( struct V_2 * V_4 )
{
F_56 ( V_4 ) ;
}
static bool F_57 ( struct V_2 * V_4 ,
const struct V_147 * V_148 ,
struct V_147 * V_149 )
{
return true ;
}
static void F_58 ( struct V_2 * V_4 ,
struct V_147 * V_148 ,
struct V_147 * V_150 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
V_11 -> V_60 . V_135 = V_150 -> clock ;
V_11 -> V_60 . V_66 = V_150 -> V_151 ;
V_11 -> V_60 . V_95 = V_150 -> V_129 - V_150 -> V_152 ;
V_11 -> V_60 . V_96 = V_150 -> V_153 - V_150 -> V_151 ;
V_11 -> V_60 . V_94 = V_150 -> V_152 - V_150 -> V_153 ;
V_11 -> V_60 . V_74 = V_150 -> V_154 ;
V_11 -> V_60 . V_90 = V_150 -> V_155 - V_150 -> V_156 ;
V_11 -> V_60 . V_92 = V_150 -> V_157 - V_150 -> V_154 ;
V_11 -> V_60 . V_88 = V_150 -> V_156 - V_150 -> V_157 ;
}
static void F_59 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_53 ( V_11 ) ;
}
static void F_60 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_51 ( V_11 ) ;
}
static int F_61 ( struct V_5 * V_158 )
{
struct V_1 * V_11 = F_3 ( V_158 ) ;
return F_62 ( V_11 -> V_143 ) ;
}
static int F_63 ( struct V_159 * V_160 , struct V_1 * V_11 )
{
int V_110 ;
V_110 = F_64 ( V_160 , & V_11 -> V_7 , & V_161 ,
V_162 ) ;
if ( V_110 ) {
F_38 ( L_11 ) ;
return V_110 ;
}
F_65 ( & V_11 -> V_7 , & V_163 ) ;
V_11 -> V_7 . V_164 = V_165 ;
F_66 ( & V_11 -> V_7 , & V_11 -> V_4 ) ;
if ( V_11 -> V_143 ) {
V_110 = F_67 ( V_11 -> V_143 , & V_11 -> V_7 ) ;
if ( V_110 ) {
F_38 ( L_12 ) ;
goto V_166;
}
}
return 0 ;
V_166:
F_68 ( & V_11 -> V_7 ) ;
return V_110 ;
}
static int F_69 ( struct V_159 * V_160 , struct V_1 * V_11 )
{
int V_110 ;
V_110 = F_70 ( V_160 , & V_11 -> V_4 , & V_167 ,
V_168 , NULL ) ;
if ( V_110 ) {
F_38 ( L_13 ) ;
return V_110 ;
}
F_71 ( & V_11 -> V_4 , & V_169 ) ;
V_11 -> V_4 . V_170 = 1 ;
V_110 = F_72 ( & V_11 -> V_4 , V_11 -> V_171 , NULL ) ;
if ( V_110 ) {
F_38 ( L_14 ) ;
V_110 = F_63 ( V_160 , V_11 ) ;
if ( V_110 )
goto V_172;
}
return 0 ;
V_172:
F_56 ( & V_11 -> V_4 ) ;
return V_110 ;
}
static void F_73 ( struct V_1 * V_11 )
{
F_56 ( & V_11 -> V_4 ) ;
if ( V_11 -> V_7 . V_126 )
F_68 ( & V_11 -> V_7 ) ;
}
static void F_74 ( struct V_173 * V_174 )
{
struct V_1 * V_11 = F_2 ( V_174 , struct V_1 , V_175 ) ;
F_39 ( V_11 ) ;
}
static void F_75 ( struct V_173 * V_174 )
{
struct V_1 * V_11 = F_2 ( V_174 , struct V_1 , V_175 ) ;
F_48 ( V_11 ) ;
}
static int F_76 ( struct V_8 * V_10 ,
struct V_176 * V_125 )
{
struct V_1 * V_11 = F_4 ( V_10 ) ;
V_11 -> V_79 = V_125 -> V_79 ;
V_11 -> V_64 = V_125 -> V_64 ;
V_11 -> V_48 = V_125 -> V_48 ;
if ( V_11 -> V_7 . V_126 )
F_77 ( V_11 -> V_7 . V_126 ) ;
return 0 ;
}
static int F_78 ( struct V_8 * V_10 ,
struct V_176 * V_125 )
{
struct V_1 * V_11 = F_4 ( V_10 ) ;
if ( V_11 -> V_7 . V_126 )
F_77 ( V_11 -> V_7 . V_126 ) ;
return 0 ;
}
static void F_79 ( struct V_1 * V_11 )
{
int V_110 ;
T_1 V_177 ;
V_110 = F_80 ( V_11 -> V_16 + V_118 , V_177 , ! ( V_177 & V_121 ) ,
4 , 2000000 ) ;
if ( V_110 ) {
F_34 ( L_15 ) ;
F_10 ( V_11 ) ;
F_12 ( V_11 ) ;
}
}
static T_1 F_81 ( T_4 type , T_4 * V_178 )
{
switch ( type ) {
case V_179 :
case V_180 :
return 1 ;
case V_181 :
case V_182 :
return 2 ;
case V_183 :
case V_184 :
return V_178 [ 1 ] + V_178 [ 2 ] * 16 ;
case V_185 :
F_82 ( L_16 ) ;
break;
default:
F_82 ( L_17 , type ) ;
break;
}
return 0 ;
}
static void F_83 ( struct V_1 * V_11 , const struct V_186 * V_187 )
{
const char * V_188 = V_187 -> V_188 ;
T_4 V_189 , V_190 , V_191 , type = V_187 -> type ;
T_1 V_192 , V_193 , V_194 ;
if ( F_84 ( type ) )
V_189 = V_195 ;
else
V_189 = ( V_187 -> V_196 > 2 ) ? V_197 : V_198 ;
if ( V_187 -> V_196 > 2 ) {
V_190 = 1 + ( V_187 -> V_196 + 3 ) / 4 ;
V_191 = 4 ;
V_193 = V_199 | V_200 | V_201 | V_202 ;
V_192 = ( V_187 -> V_196 << 16 ) | ( type << 8 ) | V_189 ;
} else {
V_190 = 1 ;
V_191 = 2 ;
V_193 = V_199 | V_200 ;
V_192 = ( type << 8 ) | V_189 ;
}
for ( V_194 = 0 ; V_194 < V_187 -> V_196 ; V_194 ++ )
F_85 ( V_188 [ V_194 ] , V_11 -> V_16 + V_203 + V_191 + V_194 ) ;
F_5 ( V_11 , V_203 , V_193 , V_192 ) ;
F_5 ( V_11 , V_204 , V_205 , V_190 ) ;
}
static T_6 F_86 ( struct V_1 * V_11 ,
const struct V_186 * V_187 , T_4 V_117 )
{
F_79 ( V_11 ) ;
F_30 ( V_11 , V_117 ) ;
F_83 ( V_11 , V_187 ) ;
F_25 ( V_11 ) ;
if ( ! F_31 ( V_11 , V_117 , 2000 ) )
return - V_124 ;
else
return 0 ;
}
static T_6 F_87 ( struct V_8 * V_10 ,
const struct V_186 * V_187 )
{
struct V_1 * V_11 = F_4 ( V_10 ) ;
T_1 V_206 , V_194 ;
T_4 V_178 [ 16 ] ;
void * V_207 ;
T_4 V_108 = V_103 ;
if ( F_6 ( V_11 -> V_16 + V_55 ) & V_208 ) {
F_38 ( L_18 ) ;
return - V_209 ;
}
if ( F_84 ( V_187 -> type ) )
V_108 |= V_102 ;
if ( F_86 ( V_11 , V_187 , V_108 ) < 0 )
return - V_124 ;
if ( ! F_84 ( V_187 -> type ) )
return 0 ;
if ( ! V_187 -> V_210 ) {
F_38 ( L_19 ) ;
return - V_209 ;
}
for ( V_194 = 0 ; V_194 < 16 ; V_194 ++ )
* ( V_178 + V_194 ) = F_88 ( V_11 -> V_16 + V_211 + V_194 ) ;
V_206 = F_81 ( V_178 [ 0 ] , V_178 ) ;
if ( V_206 > 2 )
V_207 = & V_178 [ 4 ] ;
else
V_207 = & V_178 [ 1 ] ;
if ( V_206 > 10 )
V_206 = 10 ;
if ( V_206 > V_187 -> V_212 )
V_206 = V_187 -> V_212 ;
if ( V_206 )
memcpy ( V_187 -> V_210 , V_207 , V_206 ) ;
F_82 ( L_20 ,
V_206 , * ( ( T_4 * ) ( V_187 -> V_188 ) ) ) ;
return V_206 ;
}
static int F_89 ( struct V_125 * V_126 , struct V_125 * V_213 , void * V_14 )
{
int V_110 ;
struct V_159 * V_160 = V_14 ;
struct V_1 * V_11 = F_90 ( V_126 ) ;
V_110 = F_91 ( V_160 , & V_11 -> V_175 ) ;
if ( V_110 < 0 ) {
F_42 ( V_126 , L_21 ,
V_126 -> V_214 -> V_215 , V_110 ) ;
return V_110 ;
}
V_110 = F_92 ( & V_11 -> V_10 ) ;
if ( V_110 < 0 ) {
F_42 ( V_126 , L_22 , V_110 ) ;
goto V_216;
}
V_110 = F_69 ( V_160 , V_11 ) ;
if ( V_110 ) {
F_38 ( L_23 , V_110 ) ;
goto V_217;
}
return 0 ;
V_217:
F_93 ( & V_11 -> V_10 ) ;
V_216:
F_94 ( V_160 , & V_11 -> V_175 ) ;
return V_110 ;
}
static void F_95 ( struct V_125 * V_126 , struct V_125 * V_213 ,
void * V_14 )
{
struct V_159 * V_160 = V_14 ;
struct V_1 * V_11 = F_90 ( V_126 ) ;
F_73 ( V_11 ) ;
F_93 ( & V_11 -> V_10 ) ;
F_94 ( V_160 , & V_11 -> V_175 ) ;
}
static int F_96 ( struct V_218 * V_219 )
{
struct V_1 * V_11 ;
struct V_125 * V_126 = & V_219 -> V_126 ;
struct V_220 * V_16 ;
int V_221 ;
int V_222 ;
int V_110 ;
V_11 = F_97 ( V_126 , sizeof( * V_11 ) , V_223 ) ;
if ( ! V_11 )
return - V_224 ;
V_11 -> V_10 . V_225 = & V_226 ;
V_11 -> V_10 . V_126 = V_126 ;
V_110 = F_98 ( V_126 -> V_214 , 0 , 0 ,
& V_11 -> V_143 , & V_11 -> V_171 ) ;
if ( V_110 )
return V_110 ;
V_11 -> V_139 = F_99 ( V_126 , L_24 ) ;
if ( F_100 ( V_11 -> V_139 ) ) {
V_110 = F_101 ( V_11 -> V_139 ) ;
F_42 ( V_126 , L_25 , V_110 ) ;
return V_110 ;
}
V_11 -> V_141 = F_99 ( V_126 , L_26 ) ;
if ( F_100 ( V_11 -> V_141 ) ) {
V_110 = F_101 ( V_11 -> V_141 ) ;
F_42 ( V_126 , L_27 , V_110 ) ;
return V_110 ;
}
V_11 -> V_136 = F_99 ( V_126 , L_28 ) ;
if ( F_100 ( V_11 -> V_136 ) ) {
V_110 = F_101 ( V_11 -> V_136 ) ;
F_42 ( V_126 , L_29 , V_110 ) ;
return V_110 ;
}
V_16 = F_102 ( V_219 , V_227 , 0 ) ;
V_11 -> V_16 = F_103 ( V_126 , V_16 ) ;
if ( F_100 ( V_11 -> V_16 ) ) {
V_110 = F_101 ( V_11 -> V_16 ) ;
F_42 ( V_126 , L_30 , V_110 ) ;
return V_110 ;
}
V_11 -> V_138 = F_104 ( V_126 , L_31 ) ;
if ( F_100 ( V_11 -> V_138 ) ) {
V_110 = F_101 ( V_11 -> V_138 ) ;
F_42 ( V_126 , L_32 , V_110 ) ;
return V_110 ;
}
V_222 = F_105 ( V_126 -> V_214 , V_228 ) ;
if ( V_222 < 0 ) {
F_42 ( V_126 , L_33 , V_222 ) ;
return V_222 ;
}
V_110 = F_106 ( V_126 , V_126 -> V_214 , & V_11 -> V_175 , V_222 ,
& V_229 ) ;
if ( V_110 ) {
F_42 ( V_126 , L_34 , V_110 ) ;
return V_110 ;
}
V_221 = F_107 ( V_219 , 0 ) ;
if ( V_221 < 0 ) {
F_42 ( & V_219 -> V_126 , L_35 ) ;
return - V_230 ;
}
F_108 ( V_221 , V_231 ) ;
V_110 = F_109 ( & V_219 -> V_126 , V_221 , F_35 ,
V_232 , F_110 ( & V_219 -> V_126 ) , V_11 ) ;
if ( V_110 ) {
F_42 ( & V_219 -> V_126 , L_36 ) ;
return - V_230 ;
}
F_111 ( & V_11 -> V_112 ) ;
F_112 ( V_219 , V_11 ) ;
return F_113 ( & V_219 -> V_126 , & V_233 ) ;
}
static int F_114 ( struct V_218 * V_219 )
{
struct V_1 * V_11 = F_115 ( V_219 ) ;
F_53 ( V_11 ) ;
F_116 ( & V_219 -> V_126 , & V_233 ) ;
return 0 ;
}
