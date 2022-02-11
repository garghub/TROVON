static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_4 ;
unsigned int V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_3 , V_2 -> V_7 + V_8 ) ;
V_5 = F_4 ( V_2 -> V_7 + V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_3 , V_2 -> V_7 + V_8 ) ;
F_3 ( V_5 , V_2 -> V_7 + V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_4 ( V_2 -> V_7 + V_8 ) ;
F_3 ( 0 , V_2 -> V_7 + V_8 ) ;
F_4 ( V_2 -> V_7 + V_8 ) ;
F_3 ( 0 , V_2 -> V_7 + V_8 ) ;
F_3 ( 1 , V_2 -> V_7 + V_8 ) ;
F_3 ( 0 , V_2 -> V_7 + V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
F_6 ( V_2 , 0x00 , V_9 ) ;
F_6 ( V_2 , V_10 |
V_11 |
V_12 ,
V_13 ) ;
F_6 ( V_2 , 0xff , V_14 ) ;
F_6 ( V_2 , 0xff , V_15 ) ;
F_6 ( V_2 , V_10 |
V_11 |
V_12 ,
V_16 ) ;
F_6 ( V_2 , 0x7f , V_14 ) ;
F_6 ( V_2 , 0xff , V_17 ) ;
F_6 ( V_2 , 0x09 , V_18 ) ;
F_6 ( V_2 , 0x0e , V_19 ) ;
F_6 ( V_2 , V_20 , V_21 ) ;
F_6 ( V_2 , V_22 , V_21 ) ;
F_6 ( V_2 , V_20 , V_23 ) ;
F_6 ( V_2 , V_22 , V_23 ) ;
F_6 ( V_2 , V_20 , F_8 ( 0 ) ) ;
F_6 ( V_2 , V_22 , F_8 ( 0 ) ) ;
F_6 ( V_2 , V_20 , F_8 ( 1 ) ) ;
F_6 ( V_2 , V_22 , F_8 ( 1 ) ) ;
F_6 ( V_2 , V_20 , F_8 ( 2 ) ) ;
F_6 ( V_2 , V_22 , F_8 ( 2 ) ) ;
F_6 ( V_2 , 0x00 , V_24 ) ;
}
static void F_9 ( struct V_1 * V_2 , bool V_25 )
{
unsigned int V_26 ;
V_26 = F_1 ( V_2 , V_9 ) ;
if ( V_25 )
V_26 |= ( V_27 | V_28 ) ;
else
V_26 &= ~ ( V_27 | V_28 ) ;
F_6 ( V_2 , V_26 , V_9 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned int V_29 , bool V_25 )
{
unsigned int V_30 ;
unsigned int V_26 ;
if ( V_29 == 0 )
V_30 = V_31 ;
else if ( V_29 == 1 )
V_30 = V_32 ;
else
V_30 = V_33 ;
V_26 = F_1 ( V_2 , V_9 ) ;
if ( V_25 ) {
V_26 |= V_30 ;
} else {
V_26 &= ~ V_30 ;
F_6 ( V_2 , 0x00 , F_8 ( V_29 ) ) ;
}
F_6 ( V_2 , V_26 , V_9 ) ;
}
static bool F_11 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_5 ;
V_5 = F_1 ( V_2 , V_3 ) ;
if ( ( V_5 & V_34 ) == V_34 ) {
V_5 &= 0x0f ;
V_5 |= V_20 ;
F_6 ( V_2 , V_5 , V_3 ) ;
return true ;
}
return false ;
}
static T_1 F_12 ( int V_35 , void * V_36 )
{
struct V_1 * V_2 = V_36 ;
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_40 * V_41 = V_2 -> V_42 ;
unsigned int V_43 = 0 ;
unsigned int V_5 ;
V_5 = F_13 ( V_38 -> V_44 + V_45 ) ;
if ( ! ( V_5 & V_46 ) )
return V_47 ;
if ( F_11 ( V_2 , V_21 ) )
V_43 |= 0x01 ;
if ( F_11 ( V_2 , V_23 ) ) {
V_5 = F_4 ( V_2 -> V_7 + V_48 ) ;
V_5 &= 0xc0 ;
if ( V_5 ) {
if ( V_5 & 0x80 )
V_43 |= 0x40 ;
if ( V_5 & 0x40 )
V_43 |= 0x80 ;
} else {
V_43 |= 0x02 ;
}
}
F_14 ( V_41 , & V_43 , 1 ) ;
F_15 ( V_2 , V_41 ) ;
return V_49 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
F_6 ( V_2 , 0x00 , V_24 ) ;
F_9 ( V_2 , false ) ;
F_11 ( V_2 , V_21 ) ;
F_11 ( V_2 , V_23 ) ;
F_6 ( V_2 , V_22 , V_21 ) ;
F_6 ( V_2 , V_22 , V_23 ) ;
F_9 ( V_2 , true ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
unsigned int V_50 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
struct V_51 * V_52 = & V_41 -> V_53 -> V_52 ;
unsigned int V_54 = V_12 ;
unsigned int V_55 = V_12 ;
unsigned int V_56 = V_50 & 0x01 ;
unsigned int V_57 = ( V_50 >> 1 ) & 0x01 ;
bool V_58 = false ;
unsigned int V_5 ;
if ( V_50 != V_52 -> V_59 )
return - V_60 ;
F_9 ( V_2 , false ) ;
F_6 ( V_2 , V_38 -> V_61 [ V_56 ] & 0xff , V_62 ) ;
F_6 ( V_2 , V_38 -> V_63 [ V_56 ] & 0xff , V_64 ) ;
F_6 ( V_2 , V_38 -> V_65 [ V_56 ] & 0xff , V_66 ) ;
F_6 ( V_2 , ( V_38 -> V_61 [ V_57 ] >> 8 ) & 0xff , V_67 ) ;
F_6 ( V_2 , ( V_38 -> V_63 [ V_57 ] >> 8 ) & 0xff , V_68 ) ;
F_6 ( V_2 , ( V_38 -> V_65 [ V_57 ] >> 8 ) & 0xff , V_69 ) ;
if ( V_38 -> V_61 [ V_56 ] & 0xff ) {
V_54 = V_56 ? V_70
: V_71 ;
V_5 = F_1 ( V_2 , V_13 ) ;
V_5 &= ~ V_72 ;
V_5 |= ( V_54 | V_73 ) ;
F_6 ( V_2 , V_5 , V_13 ) ;
F_6 ( V_2 , V_74 , V_21 ) ;
V_58 = true ;
F_18 ( V_2 -> V_75 ,
L_1 ,
V_56 ? L_2 : L_3 ) ;
}
if ( V_38 -> V_61 [ V_57 ] & 0xff00 ) {
V_55 = V_57 ? V_70
: V_71 ;
V_5 = F_1 ( V_2 , V_16 ) ;
V_5 &= ~ V_72 ;
V_5 |= ( V_55 | V_73 ) ;
F_6 ( V_2 , V_5 , V_16 ) ;
F_6 ( V_2 , V_74 , V_23 ) ;
V_58 = true ;
F_18 ( V_2 -> V_75 ,
L_4 ,
V_57 ? L_2 : L_3 ) ;
}
F_9 ( V_2 , true ) ;
if ( ! V_58 ) {
F_18 ( V_2 -> V_75 ,
L_5 , V_50 ) ;
return - V_60 ;
}
F_6 ( V_2 , V_76 | V_77 ,
V_24 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
V_41 -> V_53 -> V_78 = F_17 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_51 * V_52 )
{
int V_79 = 0 ;
V_79 |= F_21 ( & V_52 -> V_80 , V_81 ) ;
V_79 |= F_21 ( & V_52 -> V_82 , V_83 ) ;
V_79 |= F_21 ( & V_52 -> V_84 , V_85 ) ;
V_79 |= F_21 ( & V_52 -> V_86 , V_87 ) ;
V_79 |= F_21 ( & V_52 -> V_88 , V_89 ) ;
if ( V_79 )
return 1 ;
V_79 |= F_22 ( & V_52 -> V_59 , 3 ) ;
V_79 |= F_23 ( & V_52 -> V_90 , 0 ) ;
V_79 |= F_23 ( & V_52 -> V_91 , 0 ) ;
V_79 |= F_23 ( & V_52 -> V_92 ,
V_52 -> V_93 ) ;
V_79 |= F_23 ( & V_52 -> V_94 , 0 ) ;
if ( V_79 )
return 3 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_95 * V_96 ,
unsigned int * V_97 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
unsigned int V_98 = V_97 [ 1 ] ;
unsigned int V_99 = V_97 [ 3 ] ;
unsigned int V_100 = V_97 [ 4 ] << V_99 ;
unsigned int V_101 = V_97 [ 5 ] << V_99 ;
unsigned int V_102 = V_100 | V_101 ;
unsigned int V_103 = ( 1 << V_99 ) - 1 ;
unsigned int V_61 = V_38 -> V_61 [ V_98 ] & V_103 ;
unsigned int V_63 = V_38 -> V_63 [ V_98 ] & V_103 ;
unsigned int V_65 = V_38 -> V_65 [ V_98 ] & V_103 ;
if ( V_98 > 1 ) {
F_18 ( V_2 -> V_75 ,
L_6 ) ;
return - V_60 ;
}
if ( V_102 > 0xffff ) {
F_18 ( V_2 -> V_75 , L_7 ) ;
return - V_60 ;
}
switch ( V_97 [ 2 ] ) {
case V_104 :
V_61 = 0 ;
V_63 = 0 ;
V_65 = 0 ;
break;
case V_105 :
V_61 |= V_102 ;
V_63 |= V_102 ;
V_65 |= V_100 ;
V_65 &= ~ V_101 ;
break;
case V_106 :
V_61 |= V_102 ;
V_63 &= ~ V_102 ;
V_65 |= V_100 ;
V_65 &= ~ V_101 ;
break;
default:
return - V_60 ;
}
if ( V_98 == 0 ) {
int V_107 = 0 ;
unsigned int V_108 ;
V_108 = V_63 & 0xff ;
if ( V_108 )
V_107 |= F_25 ( V_108 ) ;
V_108 = ( V_63 >> 8 ) & 0xff ;
if ( V_108 )
V_107 |= F_25 ( V_108 ) ;
if ( V_107 ) {
F_18 ( V_2 -> V_75 ,
L_8 ) ;
return V_107 ;
}
}
V_38 -> V_61 [ V_98 ] = V_61 ;
V_38 -> V_63 [ V_98 ] = V_63 ;
V_38 -> V_65 [ V_98 ] = V_65 ;
return V_96 -> V_109 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_95 * V_96 ,
unsigned int * V_97 )
{
switch ( V_97 [ 0 ] ) {
case V_110 :
return F_24 ( V_2 , V_41 , V_96 , V_97 ) ;
default:
return - V_60 ;
}
}
static int F_27 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_95 * V_96 ,
unsigned int * V_97 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
V_97 [ 1 ] = F_28 ( V_38 -> V_111 + V_112 ) ;
return V_96 -> V_109 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_95 * V_96 ,
unsigned int * V_97 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
if ( F_30 ( V_41 , V_97 ) )
F_31 ( V_41 -> V_113 , V_38 -> V_111 + V_114 ) ;
V_97 [ 1 ] = V_41 -> V_113 ;
return V_96 -> V_109 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_95 * V_96 ,
unsigned int * V_97 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
unsigned int V_29 = F_33 ( V_96 -> V_115 ) ;
unsigned int V_5 ;
switch ( V_97 [ 0 ] ) {
case V_116 :
V_5 = V_97 [ 1 ] & V_41 -> V_117 ;
F_6 ( V_2 , V_5 & 0xff , F_34 ( V_29 ) ) ;
F_6 ( V_2 , ( V_5 >> 8 ) & 0xff ,
F_35 ( V_29 ) ) ;
F_10 ( V_2 , V_29 , true ) ;
F_6 ( V_2 , V_118 ,
F_8 ( V_29 ) ) ;
break;
case V_119 :
F_10 ( V_2 , V_29 , false ) ;
break;
case V_120 :
V_97 [ 1 ] = 0 ;
V_5 = F_1 ( V_2 , F_8 ( V_29 ) ) ;
if ( V_5 & V_121 )
V_97 [ 1 ] |= V_122 ;
if ( V_5 & V_118 )
V_97 [ 1 ] |= V_123 ;
if ( V_5 & V_124 ) {
V_97 [ 1 ] |= V_125 ;
F_11 ( V_2 , F_8 ( V_29 ) ) ;
}
V_97 [ 2 ] = V_123 | V_122 |
V_125 ;
break;
case V_126 :
switch ( V_97 [ 1 ] ) {
case V_127 :
V_5 = V_128 |
V_129 ;
break;
case V_130 :
V_5 = V_131 |
V_129 ;
break;
case V_132 :
V_5 = V_133 |
V_134 ;
break;
case V_135 :
V_5 = V_133 |
V_136 ;
break;
case V_137 :
V_5 = V_138 |
V_134 ;
break;
case V_139 :
V_5 = V_140 |
V_131 |
V_138 |
V_134 ;
break;
default:
return - V_60 ;
}
F_10 ( V_2 , V_29 , false ) ;
F_6 ( V_2 , V_5 , F_36 ( V_29 ) ) ;
break;
case V_141 :
if ( V_97 [ 1 ] > 2 )
return - V_60 ;
V_38 -> V_142 = V_97 [ 1 ] ;
if ( V_38 -> V_142 == 2 )
V_38 -> V_142 = 3 ;
F_31 ( V_38 -> V_142 , V_38 -> V_111 + V_143 ) ;
break;
case V_144 :
switch ( V_38 -> V_142 ) {
case 0 :
V_97 [ 1 ] = 0 ;
V_97 [ 2 ] = 17879 ;
break;
case 1 :
V_97 [ 1 ] = 1 ;
V_97 [ 2 ] = 573066 ;
break;
case 3 :
V_97 [ 1 ] = 2 ;
V_97 [ 2 ] = 1164822 ;
break;
default:
return - V_60 ;
}
break;
case V_145 :
if ( V_29 == 0 )
return - V_60 ;
V_5 = F_1 ( V_2 , F_36 ( V_29 ) ) ;
V_5 &= V_146 ;
if ( V_97 [ 1 ] == 1 )
V_5 |= V_146 ;
else if ( V_97 [ 1 ] > 1 )
return - V_60 ;
F_6 ( V_2 , V_5 , F_36 ( V_29 ) ) ;
break;
case V_147 :
if ( V_29 == 0 )
return - V_60 ;
break;
default:
return - V_60 ;
}
return V_96 -> V_109 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_95 * V_96 ,
unsigned int * V_97 )
{
unsigned int V_29 = F_33 ( V_96 -> V_115 ) ;
unsigned int V_52 ;
V_52 = F_1 ( V_2 , F_8 ( V_29 ) ) ;
V_52 &= V_118 ;
V_52 |= V_148 ;
if ( V_96 -> V_109 )
F_6 ( V_2 , V_52 , F_8 ( V_29 ) ) ;
return V_96 -> V_109 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_95 * V_96 ,
unsigned int * V_97 )
{
unsigned int V_29 = F_33 ( V_96 -> V_115 ) ;
unsigned int V_52 ;
unsigned int V_5 ;
int V_149 ;
V_52 = F_1 ( V_2 , F_8 ( V_29 ) ) ;
V_52 &= V_118 ;
V_52 |= V_150 ;
for ( V_149 = 0 ; V_149 < V_96 -> V_109 ; V_149 ++ ) {
F_6 ( V_2 , V_52 , F_8 ( V_29 ) ) ;
V_5 = F_1 ( V_2 , F_39 ( V_29 ) ) << 8 ;
V_5 |= F_1 ( V_2 , F_40 ( V_29 ) ) ;
V_97 [ V_149 ] = V_5 ;
}
return V_96 -> V_109 ;
}
static int F_41 ( struct V_1 * V_2 ,
unsigned long V_151 )
{
struct V_152 * V_153 = F_42 ( V_2 ) ;
struct V_37 * V_38 ;
struct V_40 * V_41 ;
int V_107 ;
V_38 = F_43 ( V_2 , sizeof( * V_38 ) ) ;
if ( ! V_38 )
return - V_154 ;
V_107 = F_44 ( V_2 ) ;
if ( V_107 )
return V_107 ;
V_2 -> V_7 = F_45 ( V_153 , 1 ) ;
V_38 -> V_44 = F_45 ( V_153 , 0 ) ;
V_38 -> V_111 = F_45 ( V_153 , 2 ) ;
F_7 ( V_2 ) ;
if ( V_153 -> V_35 > 0 ) {
V_107 = F_46 ( V_153 -> V_35 , F_12 , V_155 ,
V_2 -> V_156 , V_2 ) ;
if ( V_107 == 0 )
V_2 -> V_35 = V_153 -> V_35 ;
}
V_107 = F_47 ( V_2 , 3 ) ;
if ( V_107 )
return V_107 ;
V_41 = & V_2 -> V_157 [ 0 ] ;
V_41 -> type = V_158 ;
V_41 -> V_159 = V_160 ;
V_41 -> V_161 = 16 ;
V_41 -> V_117 = 1 ;
V_41 -> V_162 = & V_163 ;
V_41 -> V_164 = F_27 ;
if ( V_2 -> V_35 ) {
V_2 -> V_42 = V_41 ;
V_41 -> V_159 |= V_165 ;
V_41 -> V_166 = 1 ;
V_41 -> V_167 = F_26 ;
V_41 -> V_168 = F_20 ;
V_41 -> V_169 = F_19 ;
V_41 -> V_170 = F_16 ;
}
V_41 = & V_2 -> V_157 [ 1 ] ;
V_41 -> type = V_171 ;
V_41 -> V_159 = V_172 ;
V_41 -> V_161 = 16 ;
V_41 -> V_117 = 1 ;
V_41 -> V_162 = & V_163 ;
V_41 -> V_164 = F_29 ;
F_31 ( 0x0 , V_38 -> V_111 + V_114 ) ;
V_41 = & V_2 -> V_157 [ 2 ] ;
V_41 -> type = V_173 ;
V_41 -> V_159 = V_172 | V_160 ;
V_41 -> V_161 = 3 ;
V_41 -> V_117 = 0xffff ;
V_41 -> V_162 = & V_174 ;
V_41 -> V_167 = F_32 ;
V_41 -> V_175 = F_37 ;
V_41 -> V_176 = F_38 ;
if ( V_2 -> V_35 ) {
F_48 ( 0x2000 | V_177 ,
V_38 -> V_44 + V_45 ) ;
F_13 ( V_38 -> V_44 + V_178 ) ;
F_13 ( V_38 -> V_44 + V_45 ) ;
F_48 ( V_179 | 0x2000 | V_177 ,
V_38 -> V_44 + V_45 ) ;
}
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
if ( V_38 -> V_44 )
F_48 ( 0x0 , V_38 -> V_44 + V_45 ) ;
F_50 ( V_2 ) ;
}
static int F_51 ( struct V_152 * V_2 ,
const struct V_180 * V_181 )
{
return F_52 ( V_2 , & V_182 , V_181 -> V_183 ) ;
}
