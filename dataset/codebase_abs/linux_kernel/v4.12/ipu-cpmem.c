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
void F_10 ( struct V_2 * V_3 , int V_53 )
{
F_2 ( V_3 , V_54 , V_53 - 1 ) ;
}
void F_11 ( struct V_2 * V_3 )
{
struct V_55 * V_6 = V_3 -> V_6 ;
T_2 V_18 ;
if ( V_6 -> V_56 == V_57 )
F_2 ( V_3 , V_58 , 1 ) ;
V_18 = F_12 ( V_6 , F_13 ( V_3 -> V_9 ) ) ;
V_18 |= 1 << ( V_3 -> V_9 % 32 ) ;
F_14 ( V_6 , V_18 , F_13 ( V_3 -> V_9 ) ) ;
}
void F_15 ( struct V_2 * V_3 , int V_59 , T_3 V_60 )
{
if ( V_59 )
F_2 ( V_3 , V_61 , V_60 >> 3 ) ;
else
F_2 ( V_3 , V_62 , V_60 >> 3 ) ;
}
void F_16 ( struct V_2 * V_3 , T_2 V_63 , T_2 V_64 )
{
F_2 ( V_3 , V_65 , V_63 / 8 ) ;
F_2 ( V_3 , V_66 , V_64 / 8 ) ;
}
void F_17 ( struct V_2 * V_3 , int V_53 )
{
F_2 ( V_3 , V_67 , 1 ) ;
F_2 ( V_3 , V_68 , V_53 / 8 ) ;
F_2 ( V_3 , V_54 , ( V_53 * 2 ) - 1 ) ;
}
void F_18 ( struct V_2 * V_3 , T_2 V_69 )
{
V_69 &= 0x3 ;
F_2 ( V_3 , V_58 , V_69 ) ;
}
int F_19 ( struct V_2 * V_3 )
{
return F_6 ( V_3 , V_70 ) + 1 ;
}
void F_20 ( struct V_2 * V_3 , int V_71 )
{
F_2 ( V_3 , V_70 , V_71 - 1 ) ;
}
void F_21 ( struct V_2 * V_3 )
{
F_2 ( V_3 , V_72 , 1 ) ;
}
void F_22 ( struct V_2 * V_3 ,
enum V_73 V_74 )
{
T_2 V_75 = F_23 ( V_74 ) >> 5 ;
F_2 ( V_3 , V_76 , V_75 ) ;
}
int F_24 ( struct V_2 * V_3 ,
const struct V_77 * V_78 )
{
int V_79 = 0 , V_80 = 0 , V_81 , V_82 , V_83 , V_84 ;
V_81 = V_78 -> V_85 - V_78 -> V_86 . V_87 - V_78 -> V_86 . V_88 ;
V_82 = V_78 -> V_85 - V_78 -> V_89 . V_87 - V_78 -> V_89 . V_88 ;
V_83 = V_78 -> V_85 - V_78 -> V_90 . V_87 - V_78 -> V_90 . V_88 ;
V_84 = V_78 -> V_85 - V_78 -> V_91 . V_87 - V_78 -> V_91 . V_88 ;
F_2 ( V_3 , V_92 , V_78 -> V_86 . V_87 - 1 ) ;
F_2 ( V_3 , V_93 , V_81 ) ;
F_2 ( V_3 , V_94 , V_78 -> V_89 . V_87 - 1 ) ;
F_2 ( V_3 , V_95 , V_82 ) ;
F_2 ( V_3 , V_96 , V_78 -> V_90 . V_87 - 1 ) ;
F_2 ( V_3 , V_97 , V_83 ) ;
if ( V_78 -> V_91 . V_87 ) {
F_2 ( V_3 , V_98 ,
V_78 -> V_91 . V_87 - 1 ) ;
F_2 ( V_3 , V_99 , V_84 ) ;
} else {
F_2 ( V_3 , V_98 , 7 ) ;
F_2 ( V_3 , V_99 ,
V_78 -> V_85 ) ;
}
switch ( V_78 -> V_85 ) {
case 32 :
V_79 = 0 ;
V_80 = 15 ;
break;
case 24 :
V_79 = 1 ;
V_80 = 19 ;
break;
case 16 :
V_79 = 3 ;
V_80 = 31 ;
break;
case 8 :
V_79 = 5 ;
V_80 = 63 ;
break;
default:
return - V_47 ;
}
F_2 ( V_3 , V_100 , V_79 ) ;
F_2 ( V_3 , V_70 , V_80 ) ;
F_2 ( V_3 , V_101 , 7 ) ;
return 0 ;
}
int F_25 ( struct V_2 * V_3 , int V_102 )
{
int V_79 = 0 , V_80 = 0 ;
switch ( V_102 ) {
case 32 :
V_79 = 0 ;
V_80 = 15 ;
break;
case 24 :
V_79 = 1 ;
V_80 = 19 ;
break;
case 16 :
V_79 = 3 ;
V_80 = 31 ;
break;
case 8 :
V_79 = 5 ;
V_80 = 63 ;
break;
default:
return - V_47 ;
}
F_2 ( V_3 , V_100 , V_79 ) ;
F_2 ( V_3 , V_70 , V_80 ) ;
F_2 ( V_3 , V_101 , 6 ) ;
return 0 ;
}
void F_26 ( struct V_2 * V_3 , T_2 V_103 )
{
switch ( V_103 ) {
case V_33 :
F_2 ( V_3 , V_100 , 3 ) ;
F_2 ( V_3 , V_101 , 0xA ) ;
F_2 ( V_3 , V_70 , 31 ) ;
break;
case V_35 :
F_2 ( V_3 , V_100 , 3 ) ;
F_2 ( V_3 , V_101 , 0x8 ) ;
F_2 ( V_3 , V_70 , 31 ) ;
break;
}
}
void F_27 ( struct V_2 * V_3 ,
unsigned int V_104 ,
unsigned int V_105 , unsigned int V_106 )
{
F_2 ( V_3 , V_107 , V_104 - 1 ) ;
F_2 ( V_3 , V_65 , V_105 / 8 ) ;
F_2 ( V_3 , V_66 , V_106 / 8 ) ;
}
static int F_28 ( int V_108 )
{
switch ( V_108 ) {
case V_109 : return 0 ;
case V_110 : return 1 ;
case V_111 : return 2 ;
case V_112 : return 3 ;
case V_113 : return 4 ;
case V_114 : return 5 ;
case V_115 : return 6 ;
default:
return - V_47 ;
}
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_55 * V_6 = V_3 -> V_6 ;
int V_116 ;
T_2 V_18 ;
V_116 = F_28 ( V_3 -> V_9 ) ;
if ( V_116 < 0 )
return;
F_2 ( V_3 , V_117 , 1 ) ;
F_2 ( V_3 , V_118 , V_116 ) ;
F_2 ( V_3 , V_119 , 1 ) ;
V_18 = F_12 ( V_6 , V_120 ) ;
V_18 |= F_30 ( V_3 -> V_9 ) ;
F_14 ( V_6 , V_18 , V_120 ) ;
}
int F_31 ( struct V_2 * V_3 , T_2 V_121 )
{
switch ( V_121 ) {
case V_38 :
case V_42 :
F_2 ( V_3 , V_101 , 2 ) ;
F_2 ( V_3 , V_70 , 31 ) ;
break;
case V_40 :
case V_122 :
F_2 ( V_3 , V_101 , 1 ) ;
F_2 ( V_3 , V_70 , 31 ) ;
break;
case V_123 :
case V_124 :
F_2 ( V_3 , V_101 , 0 ) ;
F_2 ( V_3 , V_70 , 31 ) ;
break;
case V_44 :
F_2 ( V_3 , V_101 , 4 ) ;
F_2 ( V_3 , V_70 , 31 ) ;
break;
case V_46 :
F_2 ( V_3 , V_101 , 3 ) ;
F_2 ( V_3 , V_70 , 31 ) ;
break;
case V_34 :
F_2 ( V_3 , V_100 , 3 ) ;
F_2 ( V_3 , V_101 , 0xA ) ;
F_2 ( V_3 , V_70 , 31 ) ;
break;
case V_36 :
F_2 ( V_3 , V_100 , 3 ) ;
F_2 ( V_3 , V_101 , 0x8 ) ;
F_2 ( V_3 , V_70 , 31 ) ;
break;
case V_125 :
case V_32 :
F_24 ( V_3 , & V_126 ) ;
break;
case V_127 :
case V_30 :
F_24 ( V_3 , & V_128 ) ;
break;
case V_129 :
case V_130 :
case V_131 :
F_24 ( V_3 , & V_132 ) ;
break;
case V_133 :
case V_134 :
case V_135 :
F_24 ( V_3 , & V_136 ) ;
break;
case V_28 :
case V_137 :
F_24 ( V_3 , & V_138 ) ;
break;
case V_26 :
case V_139 :
F_24 ( V_3 , & V_140 ) ;
break;
case V_24 :
case V_141 :
F_24 ( V_3 , & V_142 ) ;
break;
case V_143 :
case V_144 :
F_24 ( V_3 , & V_145 ) ;
break;
case V_146 :
F_24 ( V_3 , & V_147 ) ;
break;
case V_148 :
F_24 ( V_3 , & V_149 ) ;
break;
case V_150 :
F_24 ( V_3 , & V_151 ) ;
break;
case V_152 :
F_24 ( V_3 , & V_153 ) ;
break;
case V_154 :
F_24 ( V_3 , & V_155 ) ;
break;
default:
return - V_47 ;
}
switch ( V_121 ) {
case V_141 :
case V_144 :
case V_139 :
case V_137 :
case V_131 :
case V_135 :
F_2 ( V_3 , V_98 , 7 ) ;
F_29 ( V_3 ) ;
break;
default:
break;
}
return 0 ;
}
int F_32 ( struct V_2 * V_3 , struct V_156 * V_157 )
{
struct V_158 * V_159 = & V_157 -> V_159 ;
int V_88 , V_105 , V_106 ;
int V_160 = 0 ;
F_3 ( L_2 ,
V_19 , V_159 -> V_102 , V_159 -> V_161 ,
V_159 -> V_162 ) ;
F_9 ( V_3 , V_157 -> V_163 . V_102 , V_157 -> V_163 . V_161 ) ;
F_10 ( V_3 , V_159 -> V_162 ) ;
F_31 ( V_3 , F_7 ( V_159 -> V_22 ) ) ;
switch ( V_159 -> V_22 ) {
case V_37 :
V_88 = F_33 ( V_159 , V_157 -> V_163 . V_164 , V_157 -> V_163 . V_165 ) ;
V_105 = F_34 ( V_159 , V_157 -> V_163 . V_164 ,
V_157 -> V_163 . V_165 ) - V_88 ;
V_106 = F_35 ( V_159 , V_157 -> V_163 . V_164 ,
V_157 -> V_163 . V_165 ) - V_88 ;
F_27 ( V_3 , V_159 -> V_162 / 2 ,
V_105 , V_106 ) ;
break;
case V_41 :
V_88 = F_33 ( V_159 , V_157 -> V_163 . V_164 , V_157 -> V_163 . V_165 ) ;
V_105 = F_34 ( V_159 , V_157 -> V_163 . V_164 ,
V_157 -> V_163 . V_165 ) - V_88 ;
V_106 = F_35 ( V_159 , V_157 -> V_163 . V_164 ,
V_157 -> V_163 . V_165 ) - V_88 ;
F_27 ( V_3 , V_159 -> V_162 / 2 ,
V_106 , V_105 ) ;
break;
case V_39 :
V_88 = F_33 ( V_159 , V_157 -> V_163 . V_164 , V_157 -> V_163 . V_165 ) ;
V_105 = F_36 ( V_159 , V_157 -> V_163 . V_164 ,
V_157 -> V_163 . V_165 ) - V_88 ;
V_106 = F_37 ( V_159 , V_157 -> V_163 . V_164 ,
V_157 -> V_163 . V_165 ) - V_88 ;
F_27 ( V_3 , V_159 -> V_162 / 2 ,
V_105 , V_106 ) ;
break;
case V_43 :
V_88 = F_33 ( V_159 , V_157 -> V_163 . V_164 , V_157 -> V_163 . V_165 ) ;
V_105 = F_38 ( V_159 , V_157 -> V_163 . V_164 ,
V_157 -> V_163 . V_165 ) - V_88 ;
V_106 = 0 ;
F_27 ( V_3 , V_159 -> V_162 ,
V_105 , V_106 ) ;
break;
case V_45 :
V_88 = F_33 ( V_159 , V_157 -> V_163 . V_164 , V_157 -> V_163 . V_165 ) ;
V_105 = F_39 ( V_159 , V_157 -> V_163 . V_164 ,
V_157 -> V_163 . V_165 ) - V_88 ;
V_106 = 0 ;
F_27 ( V_3 , V_159 -> V_162 ,
V_105 , V_106 ) ;
break;
case V_33 :
case V_35 :
case V_23 :
V_88 = V_157 -> V_163 . V_164 * 2 +
V_157 -> V_163 . V_165 * V_159 -> V_162 ;
break;
case V_31 :
case V_29 :
V_88 = V_157 -> V_163 . V_164 * 4 +
V_157 -> V_163 . V_165 * V_159 -> V_162 ;
break;
case V_27 :
case V_25 :
V_88 = V_157 -> V_163 . V_164 * 3 +
V_157 -> V_163 . V_165 * V_159 -> V_162 ;
break;
case V_166 :
case V_167 :
case V_168 :
case V_169 :
V_88 = V_157 -> V_163 . V_164 + V_157 -> V_163 . V_165 * V_159 -> V_162 ;
break;
case V_170 :
case V_171 :
case V_172 :
case V_173 :
V_88 = V_157 -> V_163 . V_164 * 2 +
V_157 -> V_163 . V_165 * V_159 -> V_162 ;
break;
default:
F_40 ( 1 ) ;
V_88 = 0 ;
V_160 = - V_47 ;
}
F_15 ( V_3 , 0 , V_157 -> V_174 + V_88 ) ;
F_15 ( V_3 , 1 , V_157 -> V_175 + V_88 ) ;
return V_160 ;
}
void F_41 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_48 = F_1 ( V_3 ) ;
struct V_55 * V_6 = V_3 -> V_6 ;
int V_176 = V_3 -> V_9 ;
F_42 ( V_6 -> V_177 , L_3 , V_176 ,
F_4 ( & V_48 -> V_14 [ 0 ] . V_20 [ 0 ] ) ,
F_4 ( & V_48 -> V_14 [ 0 ] . V_20 [ 1 ] ) ,
F_4 ( & V_48 -> V_14 [ 0 ] . V_20 [ 2 ] ) ,
F_4 ( & V_48 -> V_14 [ 0 ] . V_20 [ 3 ] ) ,
F_4 ( & V_48 -> V_14 [ 0 ] . V_20 [ 4 ] ) ) ;
F_42 ( V_6 -> V_177 , L_4 , V_176 ,
F_4 ( & V_48 -> V_14 [ 1 ] . V_20 [ 0 ] ) ,
F_4 ( & V_48 -> V_14 [ 1 ] . V_20 [ 1 ] ) ,
F_4 ( & V_48 -> V_14 [ 1 ] . V_20 [ 2 ] ) ,
F_4 ( & V_48 -> V_14 [ 1 ] . V_20 [ 3 ] ) ,
F_4 ( & V_48 -> V_14 [ 1 ] . V_20 [ 4 ] ) ) ;
F_42 ( V_6 -> V_177 , L_5 ,
F_6 ( V_3 , V_101 ) ) ;
F_42 ( V_6 -> V_177 , L_6 ,
F_6 ( V_3 , V_100 ) ) ;
F_42 ( V_6 -> V_177 , L_7 ,
F_6 ( V_3 , V_70 ) ) ;
F_42 ( V_6 -> V_177 , L_8 ,
F_6 ( V_3 , V_51 ) ) ;
F_42 ( V_6 -> V_177 , L_9 ,
F_6 ( V_3 , V_52 ) ) ;
F_42 ( V_6 -> V_177 , L_10 ,
F_6 ( V_3 , V_62 ) << 3 ) ;
F_42 ( V_6 -> V_177 , L_11 ,
F_6 ( V_3 , V_61 ) << 3 ) ;
F_42 ( V_6 -> V_177 , L_12 ,
F_6 ( V_3 , V_178 ) ) ;
F_42 ( V_6 -> V_177 , L_13 ,
F_6 ( V_3 , V_67 ) ) ;
F_42 ( V_6 -> V_177 , L_14 ,
F_6 ( V_3 , V_107 ) ) ;
F_42 ( V_6 -> V_177 , L_15 ,
F_6 ( V_3 , V_65 ) << 3 ) ;
F_42 ( V_6 -> V_177 , L_16 ,
F_6 ( V_3 , V_66 ) << 3 ) ;
F_42 ( V_6 -> V_177 , L_17 ,
F_6 ( V_3 , V_92 ) ) ;
F_42 ( V_6 -> V_177 , L_18 ,
F_6 ( V_3 , V_94 ) ) ;
F_42 ( V_6 -> V_177 , L_19 ,
F_6 ( V_3 , V_96 ) ) ;
F_42 ( V_6 -> V_177 , L_20 ,
F_6 ( V_3 , V_98 ) ) ;
F_42 ( V_6 -> V_177 , L_21 ,
F_6 ( V_3 , V_93 ) ) ;
F_42 ( V_6 -> V_177 , L_22 ,
F_6 ( V_3 , V_95 ) ) ;
F_42 ( V_6 -> V_177 , L_23 ,
F_6 ( V_3 , V_97 ) ) ;
F_42 ( V_6 -> V_177 , L_24 ,
F_6 ( V_3 , V_99 ) ) ;
}
int F_43 ( struct V_55 * V_6 , struct V_179 * V_177 , unsigned long V_8 )
{
struct V_4 * V_5 ;
V_5 = F_44 ( V_177 , sizeof( * V_5 ) , V_180 ) ;
if ( ! V_5 )
return - V_181 ;
V_6 -> V_7 = V_5 ;
F_45 ( & V_5 -> V_182 ) ;
V_5 -> V_8 = F_46 ( V_177 , V_8 , V_183 ) ;
if ( ! V_5 -> V_8 )
return - V_181 ;
F_42 ( V_177 , L_25 ,
V_8 , V_5 -> V_8 ) ;
V_5 -> V_6 = V_6 ;
return 0 ;
}
void F_47 ( struct V_55 * V_6 )
{
}
