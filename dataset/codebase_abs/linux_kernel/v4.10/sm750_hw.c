int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_4 ;
V_4 = 0 ;
V_1 -> V_5 = F_2 ( V_3 , 1 ) ;
V_1 -> V_6 = V_7 ;
F_3 ( L_1 , V_1 -> V_5 ) ;
V_4 = F_4 ( V_3 , 1 , L_2 ) ;
if ( V_4 ) {
F_5 ( L_3 ) ;
goto exit;
}
V_1 -> V_8 = F_6 ( V_1 -> V_5 ,
V_1 -> V_6 ) ;
if ( ! V_1 -> V_8 ) {
F_5 ( L_4 ) ;
V_4 = - V_9 ;
goto exit;
} else {
F_3 ( L_5 , V_1 -> V_8 ) ;
}
V_1 -> V_10 . V_11 = V_1 -> V_8 + V_12 ;
V_1 -> V_10 . V_13 = V_1 -> V_8 + V_14 ;
V_15 = V_1 -> V_8 ;
F_7 ( V_1 -> V_16 , V_1 -> V_17 ) ;
V_1 -> V_18 = F_2 ( V_3 , 0 ) ;
V_1 -> V_19 = F_8 () ;
F_3 ( L_6 ,
V_1 -> V_18 , V_1 -> V_19 ) ;
V_1 -> V_20 = F_9 ( V_1 -> V_18 ,
V_1 -> V_19 ) ;
if ( ! V_1 -> V_20 ) {
F_5 ( L_7 ) ;
V_4 = - V_9 ;
goto exit;
} else {
F_3 ( L_8 , V_1 -> V_20 ) ;
}
exit:
return V_4 ;
}
int F_10 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_21 * V_22 ;
V_22 = & V_1 -> V_23 ;
if ( V_22 -> V_24 == 0 )
V_22 -> V_24 = ( F_11 () == V_25 ) ?
V_26 :
V_27 ;
if ( V_22 -> V_28 == 0 )
V_22 -> V_28 = V_22 -> V_24 ;
if ( V_22 -> V_29 == 0 )
V_22 -> V_29 = V_22 -> V_24 / 3 ;
F_12 ( (struct V_30 * ) & V_1 -> V_23 ) ;
if ( V_1 -> V_16 == 0x718 ) {
F_13 ( V_31 ,
F_14 ( V_31 ) | V_32 ) ;
}
if ( F_11 () != V_25 ) {
unsigned int V_33 ;
if ( V_1 -> V_34 ) {
F_13 ( V_35 ,
F_14 ( V_35 ) | V_36 ) ;
V_33 = F_14 ( V_31 ) & ~ V_37 ;
V_33 |= V_38 ;
F_13 ( V_31 , V_33 ) ;
} else {
F_13 ( V_35 ,
F_14 ( V_35 ) & ~ V_36 ) ;
V_33 = F_14 ( V_31 ) & ~ V_37 ;
V_33 |= V_39 ;
F_13 ( V_31 , V_33 ) ;
}
V_33 = F_14 ( V_40 ) &
~ ( V_41 |
V_42 ) ;
switch ( V_1 -> V_43 ) {
case V_44 :
break;
case V_45 :
V_33 |= V_42 ;
break;
case V_46 :
V_33 |= V_41 ;
break;
}
F_13 ( V_40 , V_33 ) ;
} else {
F_15 ( 0 , 1 ) ;
if ( F_16 ( 0xec , 0x4a ) == 0x95 ) {
F_3 ( L_9 ) ;
F_17 ( 0xec , 0x1d , 0x16 ) ;
F_17 ( 0xec , 0x21 , 0x9 ) ;
F_17 ( 0xec , 0x49 , 0xC0 ) ;
F_3 ( L_10 ) ;
}
}
if ( ! V_1 -> V_47 )
F_18 ( V_1 ) ;
return 0 ;
}
int F_19 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_52 * V_53 )
{
int V_4 ;
T_1 V_54 ;
int V_55 ;
V_4 = 0 ;
V_54 = 0 ;
V_55 = * V_49 -> V_55 ;
if ( F_11 () != V_25 ) {
if ( V_55 == V_56 ) {
F_3 ( L_11 ) ;
if ( V_49 -> V_57 & V_58 )
V_54 |= V_59 ;
if ( V_49 -> V_57 & V_60 )
V_54 |= V_61 ;
} else {
F_3 ( L_12 ) ;
if ( V_49 -> V_57 & V_58 )
V_54 |= V_62 ;
if ( V_49 -> V_57 & V_60 )
V_54 |= V_63 ;
}
F_20 ( V_54 ) ;
} else {
T_2 V_64 ;
V_64 = F_14 ( V_65 ) ;
V_64 |= 0xf ;
F_13 ( V_65 , V_64 ) ;
}
F_3 ( L_13 ) ;
return V_4 ;
}
int F_21 ( struct V_66 * V_67 ,
struct V_50 * V_51 )
{
struct V_1 * V_1 ;
struct V_68 * V_69 = F_22 ( V_67 , struct V_68 , V_67 ) ;
V_1 = V_69 -> V_70 ;
switch ( V_51 -> V_71 ) {
case 8 :
case 16 :
break;
case 32 :
if ( V_1 -> V_17 == V_72 ) {
F_23 ( L_14 ) ;
return - V_73 ;
}
break;
default:
return - V_73 ;
}
return 0 ;
}
int F_24 ( struct V_66 * V_67 ,
struct V_50 * V_51 ,
struct V_52 * V_53 )
{
int V_4 , V_74 ;
T_2 V_64 ;
T_3 V_75 ;
T_4 clock ;
struct V_1 * V_1 ;
struct V_68 * V_69 ;
V_4 = 0 ;
V_69 = F_22 ( V_67 , struct V_68 , V_67 ) ;
V_1 = V_69 -> V_70 ;
if ( ! V_1 -> V_47 ) {
switch ( V_51 -> V_71 ) {
case 8 :
V_74 = 0 ;
break;
case 16 :
V_74 = 1 ;
break;
case 32 :
default:
V_74 = 2 ;
break;
}
F_25 ( & V_1 -> V_10 , V_74 ) ;
}
V_75 . V_76 = F_26 ( V_51 -> V_77 ) ;
V_75 . V_78 = ( V_51 -> V_79 & V_80 )
? V_81 : V_82 ;
V_75 . V_83 = ( V_51 -> V_79 & V_84 )
? V_81 : V_82 ;
V_75 . V_85 = ( V_51 -> V_79 & V_86 )
? V_81 : V_82 ;
V_75 . V_87 = V_51 -> V_88 ;
V_75 . V_89 = V_51 -> V_90 ;
V_75 . V_91 = V_51 -> V_88 + V_51 -> V_92 ;
V_75 . V_93 = V_51 -> V_88 + V_51 -> V_94 +
V_51 -> V_92 + V_51 -> V_90 ;
V_75 . V_95 = V_51 -> V_96 ;
V_75 . V_97 = V_51 -> V_98 ;
V_75 . V_99 = V_51 -> V_96 + V_51 -> V_100 ;
V_75 . V_101 = V_51 -> V_96 + V_51 -> V_102 +
V_51 -> V_100 + V_51 -> V_98 ;
if ( V_67 -> V_55 != V_103 )
clock = V_104 ;
else
clock = V_105 ;
F_23 ( L_15 , V_75 . V_76 ) ;
V_4 = F_27 ( & V_75 , clock ) ;
if ( V_4 ) {
F_5 ( L_16 ) ;
goto exit;
}
if ( V_67 -> V_55 != V_103 ) {
F_13 ( V_106 ,
V_67 -> V_107 & V_108 ) ;
V_64 = V_51 -> V_88 * ( V_51 -> V_71 >> 3 ) ;
V_64 = F_28 ( V_64 , V_67 -> V_109 ) ;
V_64 = ( V_64 << V_110 ) &
V_111 ;
V_64 |= ( V_53 -> V_112 & V_113 ) ;
F_13 ( V_114 , V_64 ) ;
V_64 = ( ( V_51 -> V_88 - 1 ) << V_115 ) &
V_116 ;
V_64 |= ( V_51 -> V_117 & V_118 ) ;
F_13 ( V_119 , V_64 ) ;
V_64 = ( V_51 -> V_120 - 1 ) <<
V_121 ;
V_64 &= V_122 ;
V_64 |= ( V_51 -> V_123 & V_124 ) ;
F_13 ( V_125 , V_64 ) ;
F_13 ( V_126 , 0 ) ;
V_64 = ( ( V_51 -> V_96 - 1 ) << V_127 ) &
V_128 ;
V_64 |= ( ( V_51 -> V_88 - 1 ) & V_129 ) ;
F_13 ( V_130 , V_64 ) ;
V_64 = F_14 ( V_40 ) ;
F_13 ( V_40 , V_64 | ( V_51 -> V_71 >> 4 ) ) ;
} else {
F_13 ( V_131 , V_67 -> V_107 ) ;
V_64 = V_51 -> V_88 * ( V_51 -> V_71 >> 3 ) ;
V_64 = F_28 ( V_64 , V_67 -> V_109 ) << V_132 ;
V_64 &= V_133 ;
V_64 |= ( V_53 -> V_112 & V_134 ) ;
F_13 ( V_135 , V_64 ) ;
V_64 = F_14 ( V_136 ) ;
V_64 |= ( ( V_51 -> V_71 >> 4 ) &
V_137 ) ;
F_13 ( V_136 , V_64 ) ;
}
exit:
return V_4 ;
}
int F_29 ( struct V_66 * V_67 , T_5 V_138 ,
T_5 V_139 , T_5 V_140 , T_5 V_141 )
{
static unsigned int V_142 [] = { V_143 , V_144 } ;
F_13 ( V_142 [ V_67 -> V_55 ] + V_138 * 4 ,
( V_139 << 16 ) | ( V_140 << 8 ) | V_141 ) ;
return 0 ;
}
int F_30 ( struct V_48 * V_49 , int V_145 )
{
int V_146 , V_147 ;
switch ( V_145 ) {
case V_148 :
V_146 = V_149 ;
V_147 = 0 ;
break;
case V_150 :
V_146 = V_149 ;
V_147 = V_151 ;
break;
case V_152 :
V_146 = V_153 ;
V_147 = V_151 ;
break;
case V_154 :
V_146 = V_155 ;
V_147 = V_151 ;
break;
case V_156 :
V_146 = V_157 ;
V_147 = V_151 ;
break;
default:
return - V_73 ;
}
if ( V_49 -> V_57 & V_60 ) {
unsigned int V_33 ;
V_33 = F_14 ( V_136 ) & ~ V_158 ;
F_13 ( V_136 , V_33 | V_146 ) ;
V_33 = F_14 ( V_136 ) & ~ V_151 ;
F_13 ( V_136 , V_33 | V_147 ) ;
}
return 0 ;
}
int F_31 ( struct V_48 * V_49 , int V_145 )
{
unsigned int V_146 , V_159 , V_147 ;
V_146 = 0 ;
V_159 = 0 ;
V_147 = 0 ;
switch ( V_145 ) {
case V_148 :
F_23 ( L_17 ) ;
V_146 = V_39 ;
V_159 = V_160 ;
break;
case V_150 :
F_23 ( L_18 ) ;
V_146 = V_39 ;
V_147 = V_151 ;
break;
case V_152 :
V_146 = V_161 ;
V_147 = V_151 ;
break;
case V_154 :
V_146 = V_38 ;
V_147 = V_151 ;
break;
case V_156 :
V_146 = V_162 ;
V_147 = V_151 ;
break;
}
if ( V_49 -> V_57 & V_60 ) {
unsigned int V_33 = F_14 ( V_31 ) & ~ V_37 ;
F_13 ( V_31 , V_33 | V_146 ) ;
V_33 = F_14 ( V_136 ) & ~ V_151 ;
F_13 ( V_136 , V_33 | V_147 ) ;
}
if ( V_49 -> V_57 & V_58 ) {
unsigned int V_33 = F_14 ( V_40 ) ;
V_33 &= ~ V_160 ;
V_33 |= V_159 ;
F_13 ( V_40 , V_33 ) ;
}
return 0 ;
}
void F_18 ( struct V_1 * V_1 )
{
T_2 V_64 ;
F_32 ( 1 ) ;
if ( F_11 () == V_25 ) {
V_64 = F_14 ( V_163 ) ;
V_64 |= V_164 ;
F_13 ( V_163 , V_64 ) ;
V_64 = F_14 ( V_163 ) ;
V_64 &= ~ V_164 ;
F_13 ( V_163 , V_64 ) ;
} else {
V_64 = F_14 ( V_31 ) ;
V_64 |= V_165 ;
F_13 ( V_31 , V_64 ) ;
V_64 = F_14 ( V_31 ) ;
V_64 &= ~ V_165 ;
F_13 ( V_31 , V_64 ) ;
}
V_1 -> V_10 . V_166 ( & V_1 -> V_10 ) ;
}
int F_33 ( void )
{
int V_167 = 0x10000000 ;
unsigned int V_168 = V_169 | V_170 |
V_171 ;
while ( V_167 -- ) {
unsigned int V_33 = F_14 ( V_172 ) ;
if ( ( V_33 & V_168 ) ==
( V_170 | V_171 ) )
return 0 ;
}
return - 1 ;
}
int F_34 ( void )
{
int V_167 = 0x10000000 ;
unsigned int V_168 = V_173 |
V_174 |
V_175 ;
while ( V_167 -- ) {
unsigned int V_33 = F_14 ( V_31 ) ;
if ( ( V_33 & V_168 ) ==
( V_174 | V_175 ) )
return 0 ;
}
return - 1 ;
}
int F_35 ( struct V_66 * V_67 ,
const struct V_50 * V_51 ,
const struct V_176 * V_177 )
{
T_2 V_178 ;
if ( ( V_51 -> V_117 + V_51 -> V_88 > V_51 -> V_179 ) ||
( V_51 -> V_123 + V_51 -> V_96 > V_51 -> V_120 ) ) {
return - V_73 ;
}
V_178 = V_51 -> V_123 * V_177 -> V_53 . V_112 +
( ( V_51 -> V_117 * V_51 -> V_71 ) >> 3 ) ;
V_178 += V_67 -> V_107 ;
if ( V_67 -> V_55 == V_56 ) {
F_13 ( V_106 ,
F_14 ( V_106 ) |
( V_178 & V_108 ) ) ;
} else {
F_13 ( V_131 ,
F_14 ( V_131 ) |
( V_178 & V_180 ) ) ;
}
return 0 ;
}
