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
V_95 | V_96 ,
V_95 | V_96 ) ;
F_5 ( V_7 -> V_20 ,
V_97 ,
V_98 , 1 ) ;
break;
case V_99 :
F_5 ( V_7 -> V_20 ,
V_97 ,
V_98 , 0 ) ;
F_5 ( V_7 -> V_20 ,
V_92 ,
V_93 , 0 ) ;
F_5 ( V_7 -> V_20 ,
V_94 ,
V_95 | V_96 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static bool F_16 ( struct V_100 * V_11 , unsigned int V_101 )
{
switch ( V_101 ) {
case V_102 ... V_103 :
case V_104 ... V_105 :
case V_106
... V_107 :
case V_108
... V_109 :
case V_110
... V_111 :
case V_112
... V_113 :
case V_97 :
case V_114 :
case V_115 :
return true ;
default:
return false ;
}
}
static bool F_17 ( struct V_100 * V_11 , unsigned int V_101 )
{
switch ( V_101 ) {
case V_102 ... V_116 :
return true ;
default:
return false ;
}
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
V_5 -> V_117 = V_7 -> V_20 ;
V_5 -> V_118 = 1 ;
F_19 ( V_7 -> V_20 ,
V_114 , V_119 ) ;
F_19 ( V_7 -> V_20 ,
V_120 ,
0xFF ) ;
F_19 ( V_7 -> V_20 ,
V_121 ,
0xFF ) ;
F_19 ( V_7 -> V_20 ,
V_122 ,
0x80 ) ;
F_19 ( V_7 -> V_20 ,
V_123 ,
0x1 ) ;
F_19 ( V_7 -> V_20 ,
V_124 ,
0x38 ) ;
F_19 ( V_7 -> V_20 ,
V_125 ,
0x05 ) ;
F_19 ( V_7 -> V_20 ,
V_126 ,
0x03 ) ;
F_19 ( V_7 -> V_20 ,
V_127 ,
0xF7 ) ;
F_19 ( V_7 -> V_20 ,
V_128 ,
0x1C ) ;
F_19 ( V_7 -> V_20 ,
V_129 ,
0x3E ) ;
F_19 ( V_7 -> V_20 ,
V_130 ,
0x04 ) ;
F_19 ( V_7 -> V_20 ,
V_131 ,
0x00 ) ;
F_19 ( V_7 -> V_20 ,
V_132 ,
0x24 ) ;
F_19 ( V_7 -> V_20 ,
V_133 ,
0x06 ) ;
F_19 ( V_7 -> V_20 ,
V_134 ,
0x08 ) ;
F_19 ( V_7 -> V_20 ,
V_135 ,
0x01 ) ;
F_19 ( V_7 -> V_20 ,
V_113 ,
0x10 ) ;
F_19 ( V_7 -> V_20 ,
V_136 ,
( V_7 -> V_137 << V_138 |
V_7 -> V_139 ) & 0xFF ) ;
if ( V_7 -> V_139 < 8 ) {
F_5 ( V_7 -> V_20 ,
V_120 ,
1 << V_7 -> V_139 , 0 ) ;
F_5 ( V_7 -> V_20 ,
V_140 ,
1 << V_7 -> V_139 ,
1 << V_7 -> V_139 ) ;
} else {
F_5 ( V_7 -> V_20 ,
V_121 ,
1 << ( V_7 -> V_139 - 8 ) , 0 ) ;
F_5 ( V_7 -> V_20 ,
V_141 ,
1 << ( V_7 -> V_139 - 8 ) ,
1 << ( V_7 -> V_139 - 8 ) ) ;
}
if ( V_7 -> V_137 < 8 ) {
F_5 ( V_7 -> V_20 ,
V_120 ,
1 << V_7 -> V_137 , 0 ) ;
F_5 ( V_7 -> V_20 ,
V_140 ,
1 << V_7 -> V_137 ,
1 << V_7 -> V_137 ) ;
} else {
F_5 ( V_7 -> V_20 ,
V_121 ,
1 << ( V_7 -> V_137 - 8 ) , 0 ) ;
F_5 ( V_7 -> V_20 ,
V_141 ,
1 << ( V_7 -> V_137 - 8 ) ,
1 << ( V_7 -> V_137 - 8 ) ) ;
}
if ( V_7 -> V_80 )
F_5 ( V_7 -> V_20 ,
V_142 ,
V_143 ,
V_143 ) ;
return 0 ;
}
static void F_20 ( struct V_144 * V_145 ,
struct V_6 * V_7 )
{
int V_48 ;
if ( ! F_21 ( V_145 -> V_11 . V_146 ,
L_8 , & V_48 ) )
V_7 -> V_139 = V_48 & 0xF ;
else
V_7 -> V_139 = 0 ;
if ( ! F_21 ( V_145 -> V_11 . V_146 ,
L_9 , & V_48 ) )
V_7 -> V_137 = V_48 & 0xF ;
else
V_7 -> V_137 = 1 ;
}
static int F_22 ( struct V_144 * V_145 ,
const struct V_147 * V_148 )
{
int V_149 = 0 , V_48 ;
int V_101 = 0 ;
struct V_6 * V_7 = NULL ;
V_7 = F_23 ( & V_145 -> V_11 ,
sizeof( * V_7 ) , V_150 ) ;
if ( ! V_7 ) {
V_149 = - V_151 ;
return V_149 ;
}
F_24 ( V_145 , V_7 ) ;
if ( ! F_21 ( V_145 -> V_11 . V_146 ,
L_10 , & V_48 ) ) {
if ( V_48 > 0 )
V_7 -> V_80 = 1 ;
else
V_7 -> V_80 = 0 ;
} else
V_7 -> V_80 = 0 ;
V_7 -> V_20
= F_25 ( V_145 , & V_152 ) ;
if ( F_26 ( V_7 -> V_20 ) ) {
V_149 = F_27 ( V_7 -> V_20 ) ;
F_4 ( & V_145 -> V_11 ,
L_11 , V_149 ) ;
return V_149 ;
}
V_149 = F_28 ( V_7 -> V_20 ,
V_115 , & V_101 ) ;
if ( V_149 < 0 ) {
F_4 ( & V_145 -> V_11 ,
L_12 , V_115 ) ;
return V_149 ;
}
F_29 ( & V_145 -> V_11 , L_13 , V_101 ) ;
F_20 ( V_145 , V_7 ) ;
V_149 = F_30 ( & V_145 -> V_11 , & V_153 ,
V_154 , F_8 ( V_154 ) ) ;
if ( V_149 < 0 )
F_4 ( & V_145 -> V_11 , L_14 , V_149 ) ;
return V_149 ;
}
static int F_31 ( struct V_144 * V_155 )
{
F_32 ( & V_155 -> V_11 ) ;
return 0 ;
}
