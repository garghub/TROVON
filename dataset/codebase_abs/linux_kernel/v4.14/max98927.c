static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
unsigned int V_8 = 0 ;
unsigned int V_9 = 0 ;
unsigned int V_10 = 0 ;
F_3 ( V_5 -> V_11 , L_1 , V_12 , V_3 ) ;
switch ( V_3 & V_13 ) {
case V_14 :
V_8 = V_15 ;
break;
case V_16 :
V_7 -> V_17 = true ;
V_8 = V_18 ;
break;
default:
F_4 ( V_5 -> V_11 , L_2 ) ;
return - V_19 ;
}
F_5 ( V_7 -> V_20 ,
V_21 ,
V_22 ,
V_8 ) ;
switch ( V_3 & V_23 ) {
case V_24 :
break;
case V_25 :
V_10 = V_26 ;
break;
default:
F_4 ( V_5 -> V_11 , L_3 ) ;
return - V_19 ;
}
F_5 ( V_7 -> V_20 ,
V_27 ,
V_26 ,
V_10 ) ;
switch ( V_3 & V_28 ) {
case V_29 :
V_7 -> V_30 |= V_29 ;
V_9 = V_31 ;
break;
case V_32 :
V_7 -> V_30 |= V_32 ;
V_9 = V_33 ;
break;
case V_34 :
V_7 -> V_30 |= V_34 ;
break;
default:
return - V_19 ;
}
if ( V_7 -> V_30 & ( V_29 | V_32 ) ) {
F_5 ( V_7 -> V_20 ,
V_35 ,
V_36 | V_37 ,
V_36 | V_37 ) ;
F_5 ( V_7 -> V_20 ,
V_27 ,
V_38 ,
V_9 << V_39 ) ;
F_5 ( V_7 -> V_20 ,
V_40 ,
V_41 , 0 ) ;
} else
F_5 ( V_7 -> V_20 ,
V_35 ,
V_36 | V_37 , 0 ) ;
if ( V_7 -> V_30 & V_34 ) {
F_5 ( V_7 -> V_20 ,
V_42 ,
V_43 , 1 ) ;
F_5 ( V_7 -> V_20 ,
V_40 ,
V_41 , 3 ) ;
} else
F_5 ( V_7 -> V_20 ,
V_42 ,
V_43 , 0 ) ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_44 * V_45 )
{
struct V_4 * V_5 = V_7 -> V_5 ;
int V_46 = F_7 ( V_45 ) * V_7 -> V_47 ;
int V_48 ;
if ( V_7 -> V_17 ) {
int V_49 ;
for ( V_49 = 0 ; V_49 < F_8 ( V_50 ) ; V_49 ++ ) {
if ( V_50 [ V_49 ] >= V_7 -> V_51 )
break;
}
if ( V_49 == F_8 ( V_50 ) ) {
F_4 ( V_5 -> V_11 , L_4 ) ;
return - V_19 ;
}
F_5 ( V_7 -> V_20 ,
V_21 ,
V_52 ,
V_49 << V_53 ) ;
}
switch ( V_46 ) {
case 32 :
V_48 = 2 ;
break;
case 48 :
V_48 = 3 ;
break;
case 64 :
V_48 = 4 ;
break;
default:
return - V_19 ;
}
F_5 ( V_7 -> V_20 ,
V_54 ,
V_55 ,
V_48 ) ;
return 0 ;
}
static int F_9 ( struct V_56 * V_57 ,
struct V_44 * V_45 ,
struct V_1 * V_58 )
{
struct V_4 * V_5 = V_58 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
unsigned int V_59 = 0 ;
unsigned int V_60 = 0 ;
switch ( F_10 ( F_11 ( V_45 ) ) ) {
case 16 :
V_60 = V_61 ;
break;
case 24 :
V_60 = V_62 ;
break;
case 32 :
V_60 = V_63 ;
break;
default:
F_4 ( V_5 -> V_11 , L_5 ,
F_11 ( V_45 ) ) ;
goto V_64;
}
V_7 -> V_47 = F_10 ( F_11 ( V_45 ) ) ;
F_5 ( V_7 -> V_20 ,
V_27 ,
V_65 , V_60 ) ;
F_3 ( V_5 -> V_11 , L_6 ,
F_11 ( V_45 ) ) ;
switch ( F_12 ( V_45 ) ) {
case 8000 :
V_59 = V_66 ;
break;
case 11025 :
V_59 = V_67 ;
break;
case 12000 :
V_59 = V_68 ;
break;
case 16000 :
V_59 = V_69 ;
break;
case 22050 :
V_59 = V_70 ;
break;
case 24000 :
V_59 = V_71 ;
break;
case 32000 :
V_59 = V_72 ;
break;
case 44100 :
V_59 = V_73 ;
break;
case 48000 :
V_59 = V_74 ;
break;
default:
F_4 ( V_5 -> V_11 , L_7 ,
F_12 ( V_45 ) ) ;
goto V_64;
}
F_5 ( V_7 -> V_20 ,
V_75 ,
V_76 ,
V_59 ) ;
F_5 ( V_7 -> V_20 ,
V_77 ,
V_78 ,
V_59 << V_79 ) ;
if ( V_7 -> V_80 &&
V_59 > V_69 )
F_5 ( V_7 -> V_20 ,
V_77 ,
V_81 ,
V_59 - 3 ) ;
else
F_5 ( V_7 -> V_20 ,
V_77 ,
V_81 ,
V_59 ) ;
return F_6 ( V_7 , V_45 ) ;
V_64:
return - V_19 ;
}
static int F_13 ( struct V_1 * V_58 ,
int V_82 , unsigned int V_83 , int V_84 )
{
struct V_4 * V_5 = V_58 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
V_7 -> V_51 = V_83 ;
return 0 ;
}
static int F_14 ( struct V_85 * V_86 ,
struct V_87 * V_88 , int V_89 )
{
struct V_4 * V_5 = F_15 ( V_86 -> V_90 ) ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
switch ( V_89 ) {
case V_91 :
F_5 ( V_7 -> V_20 ,
V_92 ,
V_93 , 1 ) ;
F_5 ( V_7 -> V_20 ,
V_94 ,
V_95 , 1 ) ;
break;
case V_96 :
F_5 ( V_7 -> V_20 ,
V_94 ,
V_95 , 0 ) ;
F_5 ( V_7 -> V_20 ,
V_92 ,
V_93 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static bool F_16 ( struct V_97 * V_11 , unsigned int V_98 )
{
switch ( V_98 ) {
case V_99 ... V_100 :
case V_101 ... V_102 :
case V_103
... V_104 :
case V_105
... V_106 :
case V_107
... V_108 :
case V_109
... V_110 :
case V_94 :
case V_111 :
case V_112 :
return true ;
default:
return false ;
}
}
static bool F_17 ( struct V_97 * V_11 , unsigned int V_98 )
{
switch ( V_98 ) {
case V_99 ... V_113 :
case V_114 :
case V_115 :
case V_104 :
case V_105 :
case V_110 :
case V_112 :
case V_111 :
return true ;
default:
return false ;
}
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
V_5 -> V_116 = V_7 -> V_20 ;
F_19 ( V_7 -> V_20 ,
V_111 , V_117 ) ;
F_19 ( V_7 -> V_20 ,
V_118 ,
0xFF ) ;
F_19 ( V_7 -> V_20 ,
V_119 ,
0xFF ) ;
F_19 ( V_7 -> V_20 ,
V_120 ,
0x80 ) ;
F_19 ( V_7 -> V_20 ,
V_121 ,
0x1 ) ;
F_19 ( V_7 -> V_20 ,
V_122 ,
0x38 ) ;
F_19 ( V_7 -> V_20 ,
V_123 ,
0x05 ) ;
F_19 ( V_7 -> V_20 ,
V_124 ,
0x03 ) ;
F_19 ( V_7 -> V_20 ,
V_125 ,
0xF7 ) ;
F_19 ( V_7 -> V_20 ,
V_126 ,
0x1C ) ;
F_19 ( V_7 -> V_20 ,
V_127 ,
0x3E ) ;
F_19 ( V_7 -> V_20 ,
V_128 ,
0x04 ) ;
F_19 ( V_7 -> V_20 ,
V_129 ,
0x00 ) ;
F_19 ( V_7 -> V_20 ,
V_130 ,
0x24 ) ;
F_19 ( V_7 -> V_20 ,
V_131 ,
0x06 ) ;
F_19 ( V_7 -> V_20 ,
V_132 ,
0x08 ) ;
F_19 ( V_7 -> V_20 ,
V_133 ,
0x01 ) ;
F_19 ( V_7 -> V_20 ,
V_110 ,
0x10 ) ;
F_19 ( V_7 -> V_20 ,
V_134 ,
( V_7 -> V_135 << V_136 |
V_7 -> V_137 ) & 0xFF ) ;
if ( V_7 -> V_137 < 8 ) {
F_5 ( V_7 -> V_20 ,
V_118 ,
1 << V_7 -> V_137 , 0 ) ;
F_5 ( V_7 -> V_20 ,
V_138 ,
1 << V_7 -> V_137 ,
1 << V_7 -> V_137 ) ;
} else {
F_5 ( V_7 -> V_20 ,
V_119 ,
1 << ( V_7 -> V_137 - 8 ) , 0 ) ;
F_5 ( V_7 -> V_20 ,
V_139 ,
1 << ( V_7 -> V_137 - 8 ) ,
1 << ( V_7 -> V_137 - 8 ) ) ;
}
if ( V_7 -> V_135 < 8 ) {
F_5 ( V_7 -> V_20 ,
V_118 ,
1 << V_7 -> V_135 , 0 ) ;
F_5 ( V_7 -> V_20 ,
V_138 ,
1 << V_7 -> V_135 ,
1 << V_7 -> V_135 ) ;
} else {
F_5 ( V_7 -> V_20 ,
V_119 ,
1 << ( V_7 -> V_135 - 8 ) , 0 ) ;
F_5 ( V_7 -> V_20 ,
V_139 ,
1 << ( V_7 -> V_135 - 8 ) ,
1 << ( V_7 -> V_135 - 8 ) ) ;
}
if ( V_7 -> V_80 )
F_5 ( V_7 -> V_20 ,
V_140 ,
V_141 ,
V_141 ) ;
return 0 ;
}
static int F_20 ( struct V_97 * V_11 )
{
struct V_6 * V_7 = F_21 ( V_11 ) ;
F_22 ( V_7 -> V_20 , true ) ;
F_23 ( V_7 -> V_20 ) ;
return 0 ;
}
static int F_24 ( struct V_97 * V_11 )
{
struct V_6 * V_7 = F_21 ( V_11 ) ;
F_19 ( V_7 -> V_20 ,
V_111 , V_117 ) ;
F_22 ( V_7 -> V_20 , false ) ;
F_25 ( V_7 -> V_20 ) ;
return 0 ;
}
static void F_26 ( struct V_142 * V_143 ,
struct V_6 * V_7 )
{
int V_48 ;
struct V_97 * V_11 = & V_143 -> V_11 ;
if ( ! F_27 ( V_11 , L_8 , & V_48 ) )
V_7 -> V_137 = V_48 & 0xF ;
else
V_7 -> V_137 = 0 ;
if ( ! F_27 ( V_11 , L_9 , & V_48 ) )
V_7 -> V_135 = V_48 & 0xF ;
else
V_7 -> V_135 = 1 ;
}
static int F_28 ( struct V_142 * V_143 ,
const struct V_144 * V_145 )
{
int V_146 = 0 , V_48 ;
int V_98 = 0 ;
struct V_6 * V_7 = NULL ;
V_7 = F_29 ( & V_143 -> V_11 ,
sizeof( * V_7 ) , V_147 ) ;
if ( ! V_7 ) {
V_146 = - V_148 ;
return V_146 ;
}
F_30 ( V_143 , V_7 ) ;
if ( ! F_31 ( V_143 -> V_11 . V_149 ,
L_10 , & V_48 ) ) {
if ( V_48 > 0 )
V_7 -> V_80 = 1 ;
else
V_7 -> V_80 = 0 ;
} else
V_7 -> V_80 = 0 ;
V_7 -> V_20
= F_32 ( V_143 , & V_150 ) ;
if ( F_33 ( V_7 -> V_20 ) ) {
V_146 = F_34 ( V_7 -> V_20 ) ;
F_4 ( & V_143 -> V_11 ,
L_11 , V_146 ) ;
return V_146 ;
}
V_146 = F_35 ( V_7 -> V_20 ,
V_112 , & V_98 ) ;
if ( V_146 < 0 ) {
F_4 ( & V_143 -> V_11 ,
L_12 , V_112 ) ;
return V_146 ;
}
F_36 ( & V_143 -> V_11 , L_13 , V_98 ) ;
F_26 ( V_143 , V_7 ) ;
V_146 = F_37 ( & V_143 -> V_11 , & V_151 ,
V_152 , F_8 ( V_152 ) ) ;
if ( V_146 < 0 )
F_4 ( & V_143 -> V_11 , L_14 , V_146 ) ;
return V_146 ;
}
static int F_38 ( struct V_142 * V_153 )
{
F_39 ( & V_153 -> V_11 ) ;
return 0 ;
}
