static inline struct V_1 T_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return V_5 -> V_8 + V_3 -> V_9 ;
}
static void F_2 ( struct V_2 * V_3 , T_2 V_10 , T_2 V_11 )
{
struct V_1 T_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_12 = ( V_10 >> 8 ) % 160 ;
T_2 V_13 = V_10 & 0xff ;
T_2 V_14 = ( V_10 >> 8 ) / 160 ;
T_2 V_15 = V_12 / 32 ;
T_2 V_16 = V_12 % 32 ;
T_2 V_17 = ( 1 << V_13 ) - 1 ;
T_2 V_18 ;
F_3 ( L_1 , V_19 , V_14 , V_12 , V_13 ) ;
V_18 = F_4 ( & V_8 -> V_14 [ V_14 ] . V_20 [ V_15 ] ) ;
V_18 &= ~ ( V_17 << V_16 ) ;
V_18 |= V_11 << V_16 ;
F_5 ( V_18 , & V_8 -> V_14 [ V_14 ] . V_20 [ V_15 ] ) ;
if ( ( V_12 + V_13 - 1 ) / 32 > V_15 ) {
V_18 = F_4 ( & V_8 -> V_14 [ V_14 ] . V_20 [ V_15 + 1 ] ) ;
V_18 &= ~ ( V_17 >> ( V_16 ? ( 32 - V_16 ) : 0 ) ) ;
V_18 |= V_11 >> ( V_16 ? ( 32 - V_16 ) : 0 ) ;
F_5 ( V_18 , & V_8 -> V_14 [ V_14 ] . V_20 [ V_15 + 1 ] ) ;
}
}
static T_2 F_6 ( struct V_2 * V_3 , T_2 V_10 )
{
struct V_1 T_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_12 = ( V_10 >> 8 ) % 160 ;
T_2 V_13 = V_10 & 0xff ;
T_2 V_14 = ( V_10 >> 8 ) / 160 ;
T_2 V_15 = V_12 / 32 ;
T_2 V_16 = V_12 % 32 ;
T_2 V_17 = ( 1 << V_13 ) - 1 ;
T_2 V_18 = 0 ;
F_3 ( L_1 , V_19 , V_14 , V_12 , V_13 ) ;
V_18 = ( F_4 ( & V_8 -> V_14 [ V_14 ] . V_20 [ V_15 ] ) >> V_16 ) & V_17 ;
if ( ( V_12 + V_13 - 1 ) / 32 > V_15 ) {
T_2 V_21 ;
V_21 = F_4 ( & V_8 -> V_14 [ V_14 ] . V_20 [ V_15 + 1 ] ) ;
V_21 &= V_17 >> ( V_16 ? ( 32 - V_16 ) : 0 ) ;
V_18 |= V_21 << ( V_16 ? ( 32 - V_16 ) : 0 ) ;
}
return V_18 ;
}
static int F_7 ( T_2 V_22 )
{
switch ( V_22 ) {
case V_23 :
return V_24 ;
case V_25 :
return V_26 ;
case V_27 :
return V_28 ;
case V_29 :
return V_30 ;
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
case V_35 :
return V_36 ;
case V_37 :
return V_38 ;
case V_39 :
return V_40 ;
case V_41 :
return V_42 ;
case V_43 :
return V_44 ;
case V_45 :
return V_46 ;
}
return - V_47 ;
}
void F_8 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_48 = F_1 ( V_3 ) ;
void T_1 * V_8 = V_48 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < sizeof( * V_48 ) / sizeof( T_2 ) ; V_15 ++ )
F_5 ( 0 , V_8 + V_15 * sizeof( T_2 ) ) ;
}
void F_9 ( struct V_2 * V_3 , int V_49 , int V_50 )
{
F_2 ( V_3 , V_51 , V_49 - 1 ) ;
F_2 ( V_3 , V_52 , V_50 - 1 ) ;
}
void F_10 ( struct V_2 * V_3 )
{
F_2 ( V_3 , V_53 , 1 ) ;
}
void F_11 ( struct V_2 * V_3 , int V_54 )
{
F_2 ( V_3 , V_55 , V_54 - 1 ) ;
}
void F_12 ( struct V_2 * V_3 )
{
struct V_56 * V_6 = V_3 -> V_6 ;
T_2 V_18 ;
if ( V_6 -> V_57 == V_58 )
F_2 ( V_3 , V_59 , 1 ) ;
V_18 = F_13 ( V_6 , F_14 ( V_3 -> V_9 ) ) ;
V_18 |= 1 << ( V_3 -> V_9 % 32 ) ;
F_15 ( V_6 , V_18 , F_14 ( V_3 -> V_9 ) ) ;
}
void F_16 ( struct V_2 * V_3 , int V_60 , T_3 V_61 )
{
if ( V_60 )
F_2 ( V_3 , V_62 , V_61 >> 3 ) ;
else
F_2 ( V_3 , V_63 , V_61 >> 3 ) ;
}
void F_17 ( struct V_2 * V_3 , T_2 V_64 , T_2 V_65 )
{
F_2 ( V_3 , V_66 , V_64 / 8 ) ;
F_2 ( V_3 , V_67 , V_65 / 8 ) ;
}
void F_18 ( struct V_2 * V_3 , int V_54 )
{
F_2 ( V_3 , V_68 , 1 ) ;
F_2 ( V_3 , V_69 , V_54 / 8 ) ;
F_2 ( V_3 , V_55 , ( V_54 * 2 ) - 1 ) ;
}
void F_19 ( struct V_2 * V_3 , T_2 V_70 )
{
V_70 &= 0x3 ;
F_2 ( V_3 , V_59 , V_70 ) ;
}
int F_20 ( struct V_2 * V_3 )
{
return F_6 ( V_3 , V_71 ) + 1 ;
}
void F_21 ( struct V_2 * V_3 , int V_72 )
{
F_2 ( V_3 , V_71 , V_72 - 1 ) ;
}
void F_22 ( struct V_2 * V_3 )
{
F_2 ( V_3 , V_73 , 1 ) ;
}
void F_23 ( struct V_2 * V_3 ,
enum V_74 V_75 )
{
T_2 V_76 = F_24 ( V_75 ) >> 5 ;
F_2 ( V_3 , V_77 , V_76 ) ;
}
int F_25 ( struct V_2 * V_3 ,
const struct V_78 * V_79 )
{
int V_80 = 0 , V_81 = 0 , V_82 , V_83 , V_84 , V_85 ;
V_82 = V_79 -> V_86 - V_79 -> V_87 . V_88 - V_79 -> V_87 . V_89 ;
V_83 = V_79 -> V_86 - V_79 -> V_90 . V_88 - V_79 -> V_90 . V_89 ;
V_84 = V_79 -> V_86 - V_79 -> V_91 . V_88 - V_79 -> V_91 . V_89 ;
V_85 = V_79 -> V_86 - V_79 -> V_92 . V_88 - V_79 -> V_92 . V_89 ;
F_2 ( V_3 , V_93 , V_79 -> V_87 . V_88 - 1 ) ;
F_2 ( V_3 , V_94 , V_82 ) ;
F_2 ( V_3 , V_95 , V_79 -> V_90 . V_88 - 1 ) ;
F_2 ( V_3 , V_96 , V_83 ) ;
F_2 ( V_3 , V_97 , V_79 -> V_91 . V_88 - 1 ) ;
F_2 ( V_3 , V_98 , V_84 ) ;
if ( V_79 -> V_92 . V_88 ) {
F_2 ( V_3 , V_99 ,
V_79 -> V_92 . V_88 - 1 ) ;
F_2 ( V_3 , V_100 , V_85 ) ;
} else {
F_2 ( V_3 , V_99 , 7 ) ;
F_2 ( V_3 , V_100 ,
V_79 -> V_86 ) ;
}
switch ( V_79 -> V_86 ) {
case 32 :
V_80 = 0 ;
V_81 = 15 ;
break;
case 24 :
V_80 = 1 ;
V_81 = 19 ;
break;
case 16 :
V_80 = 3 ;
V_81 = 31 ;
break;
case 8 :
V_80 = 5 ;
V_81 = 63 ;
break;
default:
return - V_47 ;
}
F_2 ( V_3 , V_101 , V_80 ) ;
F_2 ( V_3 , V_71 , V_81 ) ;
F_2 ( V_3 , V_102 , 7 ) ;
return 0 ;
}
int F_26 ( struct V_2 * V_3 , int V_103 )
{
int V_80 = 0 , V_81 = 0 ;
switch ( V_103 ) {
case 32 :
V_80 = 0 ;
V_81 = 15 ;
break;
case 24 :
V_80 = 1 ;
V_81 = 19 ;
break;
case 16 :
V_80 = 3 ;
V_81 = 31 ;
break;
case 8 :
V_80 = 5 ;
V_81 = 63 ;
break;
default:
return - V_47 ;
}
F_2 ( V_3 , V_101 , V_80 ) ;
F_2 ( V_3 , V_71 , V_81 ) ;
F_2 ( V_3 , V_102 , 6 ) ;
return 0 ;
}
void F_27 ( struct V_2 * V_3 , T_2 V_104 )
{
switch ( V_104 ) {
case V_33 :
F_2 ( V_3 , V_101 , 3 ) ;
F_2 ( V_3 , V_102 , 0xA ) ;
F_2 ( V_3 , V_71 , 31 ) ;
break;
case V_35 :
F_2 ( V_3 , V_101 , 3 ) ;
F_2 ( V_3 , V_102 , 0x8 ) ;
F_2 ( V_3 , V_71 , 31 ) ;
break;
}
}
void F_28 ( struct V_2 * V_3 ,
unsigned int V_105 ,
unsigned int V_106 , unsigned int V_107 )
{
F_2 ( V_3 , V_108 , V_105 - 1 ) ;
F_2 ( V_3 , V_66 , V_106 / 8 ) ;
F_2 ( V_3 , V_67 , V_107 / 8 ) ;
}
static int F_29 ( int V_109 )
{
switch ( V_109 ) {
case V_110 : return 0 ;
case V_111 : return 1 ;
case V_112 : return 2 ;
case V_113 : return 3 ;
case V_114 : return 4 ;
case V_115 : return 5 ;
case V_116 : return 6 ;
default:
return - V_47 ;
}
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_56 * V_6 = V_3 -> V_6 ;
int V_117 ;
T_2 V_18 ;
V_117 = F_29 ( V_3 -> V_9 ) ;
if ( V_117 < 0 )
return;
F_2 ( V_3 , V_118 , 1 ) ;
F_2 ( V_3 , V_119 , V_117 ) ;
F_2 ( V_3 , V_120 , 1 ) ;
V_18 = F_13 ( V_6 , V_121 ) ;
V_18 |= F_31 ( V_3 -> V_9 ) ;
F_15 ( V_6 , V_18 , V_121 ) ;
}
int F_32 ( struct V_2 * V_3 , T_2 V_122 )
{
switch ( V_122 ) {
case V_38 :
case V_42 :
F_2 ( V_3 , V_102 , 2 ) ;
F_2 ( V_3 , V_71 , 31 ) ;
break;
case V_40 :
case V_123 :
F_2 ( V_3 , V_102 , 1 ) ;
F_2 ( V_3 , V_71 , 31 ) ;
break;
case V_124 :
case V_125 :
F_2 ( V_3 , V_102 , 0 ) ;
F_2 ( V_3 , V_71 , 31 ) ;
break;
case V_44 :
F_2 ( V_3 , V_102 , 4 ) ;
F_2 ( V_3 , V_71 , 31 ) ;
break;
case V_46 :
F_2 ( V_3 , V_102 , 3 ) ;
F_2 ( V_3 , V_71 , 31 ) ;
break;
case V_34 :
F_2 ( V_3 , V_101 , 3 ) ;
F_2 ( V_3 , V_102 , 0xA ) ;
F_2 ( V_3 , V_71 , 31 ) ;
break;
case V_36 :
F_2 ( V_3 , V_101 , 3 ) ;
F_2 ( V_3 , V_102 , 0x8 ) ;
F_2 ( V_3 , V_71 , 31 ) ;
break;
case V_126 :
case V_32 :
F_25 ( V_3 , & V_127 ) ;
break;
case V_128 :
case V_30 :
F_25 ( V_3 , & V_129 ) ;
break;
case V_130 :
case V_131 :
case V_132 :
F_25 ( V_3 , & V_133 ) ;
break;
case V_134 :
case V_135 :
case V_136 :
F_25 ( V_3 , & V_137 ) ;
break;
case V_28 :
case V_138 :
F_25 ( V_3 , & V_139 ) ;
break;
case V_26 :
case V_140 :
F_25 ( V_3 , & V_141 ) ;
break;
case V_24 :
case V_142 :
F_25 ( V_3 , & V_143 ) ;
break;
case V_144 :
case V_145 :
F_25 ( V_3 , & V_146 ) ;
break;
case V_147 :
F_25 ( V_3 , & V_148 ) ;
break;
case V_149 :
F_25 ( V_3 , & V_150 ) ;
break;
case V_151 :
F_25 ( V_3 , & V_152 ) ;
break;
case V_153 :
F_25 ( V_3 , & V_154 ) ;
break;
case V_155 :
F_25 ( V_3 , & V_156 ) ;
break;
default:
return - V_47 ;
}
switch ( V_122 ) {
case V_142 :
case V_145 :
case V_140 :
case V_138 :
case V_132 :
case V_136 :
F_2 ( V_3 , V_99 , 7 ) ;
F_30 ( V_3 ) ;
break;
default:
break;
}
return 0 ;
}
int F_33 ( struct V_2 * V_3 , struct V_157 * V_158 )
{
struct V_159 * V_160 = & V_158 -> V_160 ;
int V_89 , V_106 , V_107 ;
int V_161 = 0 ;
F_3 ( L_2 ,
V_19 , V_160 -> V_103 , V_160 -> V_162 ,
V_160 -> V_163 ) ;
F_9 ( V_3 , V_158 -> V_164 . V_103 , V_158 -> V_164 . V_162 ) ;
F_11 ( V_3 , V_160 -> V_163 ) ;
F_32 ( V_3 , F_7 ( V_160 -> V_22 ) ) ;
switch ( V_160 -> V_22 ) {
case V_37 :
V_89 = F_34 ( V_160 , V_158 -> V_164 . V_165 , V_158 -> V_164 . V_166 ) ;
V_106 = F_35 ( V_160 , V_158 -> V_164 . V_165 ,
V_158 -> V_164 . V_166 ) - V_89 ;
V_107 = F_36 ( V_160 , V_158 -> V_164 . V_165 ,
V_158 -> V_164 . V_166 ) - V_89 ;
F_28 ( V_3 , V_160 -> V_163 / 2 ,
V_106 , V_107 ) ;
break;
case V_41 :
V_89 = F_34 ( V_160 , V_158 -> V_164 . V_165 , V_158 -> V_164 . V_166 ) ;
V_106 = F_35 ( V_160 , V_158 -> V_164 . V_165 ,
V_158 -> V_164 . V_166 ) - V_89 ;
V_107 = F_36 ( V_160 , V_158 -> V_164 . V_165 ,
V_158 -> V_164 . V_166 ) - V_89 ;
F_28 ( V_3 , V_160 -> V_163 / 2 ,
V_107 , V_106 ) ;
break;
case V_39 :
V_89 = F_34 ( V_160 , V_158 -> V_164 . V_165 , V_158 -> V_164 . V_166 ) ;
V_106 = F_37 ( V_160 , V_158 -> V_164 . V_165 ,
V_158 -> V_164 . V_166 ) - V_89 ;
V_107 = F_38 ( V_160 , V_158 -> V_164 . V_165 ,
V_158 -> V_164 . V_166 ) - V_89 ;
F_28 ( V_3 , V_160 -> V_163 / 2 ,
V_106 , V_107 ) ;
break;
case V_43 :
V_89 = F_34 ( V_160 , V_158 -> V_164 . V_165 , V_158 -> V_164 . V_166 ) ;
V_106 = F_39 ( V_160 , V_158 -> V_164 . V_165 ,
V_158 -> V_164 . V_166 ) - V_89 ;
V_107 = 0 ;
F_28 ( V_3 , V_160 -> V_163 ,
V_106 , V_107 ) ;
break;
case V_45 :
V_89 = F_34 ( V_160 , V_158 -> V_164 . V_165 , V_158 -> V_164 . V_166 ) ;
V_106 = F_40 ( V_160 , V_158 -> V_164 . V_165 ,
V_158 -> V_164 . V_166 ) - V_89 ;
V_107 = 0 ;
F_28 ( V_3 , V_160 -> V_163 ,
V_106 , V_107 ) ;
break;
case V_33 :
case V_35 :
case V_23 :
V_89 = V_158 -> V_164 . V_165 * 2 +
V_158 -> V_164 . V_166 * V_160 -> V_163 ;
break;
case V_31 :
case V_29 :
V_89 = V_158 -> V_164 . V_165 * 4 +
V_158 -> V_164 . V_166 * V_160 -> V_163 ;
break;
case V_27 :
case V_25 :
V_89 = V_158 -> V_164 . V_165 * 3 +
V_158 -> V_164 . V_166 * V_160 -> V_163 ;
break;
case V_167 :
case V_168 :
case V_169 :
case V_170 :
V_89 = V_158 -> V_164 . V_165 + V_158 -> V_164 . V_166 * V_160 -> V_163 ;
break;
case V_171 :
case V_172 :
case V_173 :
case V_174 :
V_89 = V_158 -> V_164 . V_165 * 2 +
V_158 -> V_164 . V_166 * V_160 -> V_163 ;
break;
default:
F_41 ( 1 ) ;
V_89 = 0 ;
V_161 = - V_47 ;
}
F_16 ( V_3 , 0 , V_158 -> V_175 + V_89 ) ;
F_16 ( V_3 , 1 , V_158 -> V_176 + V_89 ) ;
return V_161 ;
}
void F_42 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_48 = F_1 ( V_3 ) ;
struct V_56 * V_6 = V_3 -> V_6 ;
int V_177 = V_3 -> V_9 ;
F_43 ( V_6 -> V_178 , L_3 , V_177 ,
F_4 ( & V_48 -> V_14 [ 0 ] . V_20 [ 0 ] ) ,
F_4 ( & V_48 -> V_14 [ 0 ] . V_20 [ 1 ] ) ,
F_4 ( & V_48 -> V_14 [ 0 ] . V_20 [ 2 ] ) ,
F_4 ( & V_48 -> V_14 [ 0 ] . V_20 [ 3 ] ) ,
F_4 ( & V_48 -> V_14 [ 0 ] . V_20 [ 4 ] ) ) ;
F_43 ( V_6 -> V_178 , L_4 , V_177 ,
F_4 ( & V_48 -> V_14 [ 1 ] . V_20 [ 0 ] ) ,
F_4 ( & V_48 -> V_14 [ 1 ] . V_20 [ 1 ] ) ,
F_4 ( & V_48 -> V_14 [ 1 ] . V_20 [ 2 ] ) ,
F_4 ( & V_48 -> V_14 [ 1 ] . V_20 [ 3 ] ) ,
F_4 ( & V_48 -> V_14 [ 1 ] . V_20 [ 4 ] ) ) ;
F_43 ( V_6 -> V_178 , L_5 ,
F_6 ( V_3 , V_102 ) ) ;
F_43 ( V_6 -> V_178 , L_6 ,
F_6 ( V_3 , V_101 ) ) ;
F_43 ( V_6 -> V_178 , L_7 ,
F_6 ( V_3 , V_71 ) ) ;
F_43 ( V_6 -> V_178 , L_8 ,
F_6 ( V_3 , V_51 ) ) ;
F_43 ( V_6 -> V_178 , L_9 ,
F_6 ( V_3 , V_52 ) ) ;
F_43 ( V_6 -> V_178 , L_10 ,
F_6 ( V_3 , V_63 ) << 3 ) ;
F_43 ( V_6 -> V_178 , L_11 ,
F_6 ( V_3 , V_62 ) << 3 ) ;
F_43 ( V_6 -> V_178 , L_12 ,
F_6 ( V_3 , V_179 ) ) ;
F_43 ( V_6 -> V_178 , L_13 ,
F_6 ( V_3 , V_68 ) ) ;
F_43 ( V_6 -> V_178 , L_14 ,
F_6 ( V_3 , V_108 ) ) ;
F_43 ( V_6 -> V_178 , L_15 ,
F_6 ( V_3 , V_66 ) << 3 ) ;
F_43 ( V_6 -> V_178 , L_16 ,
F_6 ( V_3 , V_67 ) << 3 ) ;
F_43 ( V_6 -> V_178 , L_17 ,
F_6 ( V_3 , V_93 ) ) ;
F_43 ( V_6 -> V_178 , L_18 ,
F_6 ( V_3 , V_95 ) ) ;
F_43 ( V_6 -> V_178 , L_19 ,
F_6 ( V_3 , V_97 ) ) ;
F_43 ( V_6 -> V_178 , L_20 ,
F_6 ( V_3 , V_99 ) ) ;
F_43 ( V_6 -> V_178 , L_21 ,
F_6 ( V_3 , V_94 ) ) ;
F_43 ( V_6 -> V_178 , L_22 ,
F_6 ( V_3 , V_96 ) ) ;
F_43 ( V_6 -> V_178 , L_23 ,
F_6 ( V_3 , V_98 ) ) ;
F_43 ( V_6 -> V_178 , L_24 ,
F_6 ( V_3 , V_100 ) ) ;
}
int F_44 ( struct V_56 * V_6 , struct V_180 * V_178 , unsigned long V_8 )
{
struct V_4 * V_5 ;
V_5 = F_45 ( V_178 , sizeof( * V_5 ) , V_181 ) ;
if ( ! V_5 )
return - V_182 ;
V_6 -> V_7 = V_5 ;
F_46 ( & V_5 -> V_183 ) ;
V_5 -> V_8 = F_47 ( V_178 , V_8 , V_184 ) ;
if ( ! V_5 -> V_8 )
return - V_182 ;
F_43 ( V_178 , L_25 ,
V_8 , V_5 -> V_8 ) ;
V_5 -> V_6 = V_6 ;
return 0 ;
}
void F_48 ( struct V_56 * V_6 )
{
}
