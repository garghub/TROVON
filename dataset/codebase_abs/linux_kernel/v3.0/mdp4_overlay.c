void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = V_5 ;
if ( V_2 -> V_6 == V_7 )
V_4 |= V_8 ;
else
V_4 |= V_9 ;
if ( V_2 -> V_10 . V_11 == 18 ) {
V_4 |= V_12 |
V_13 | V_14 ;
} else if ( V_2 -> V_10 . V_11 == 16 ) {
V_4 |= V_12 |
V_15 | V_16 ;
} else {
V_4 |= V_17 |
V_18 | V_19 ;
}
if ( V_3 )
V_4 |= V_20 ;
F_2 ( V_21 + 0x90000 , V_4 ) ;
}
void F_3 ( struct V_22 * V_23 )
{
F_2 ( V_21 + 0x90004 ,
( V_23 -> V_24 << 16 | V_23 -> V_25 ) ) ;
F_2 ( V_21 + 0x90008 , V_23 -> V_26 ) ;
F_2 ( V_21 + 0x9000c , V_23 -> V_27 ) ;
F_2 ( V_21 + 0x90010 , ( V_23 -> V_28 << 16 | V_23 -> V_29 ) ) ;
}
static int F_4 ( T_1 V_30 )
{
T_1 V_31 = 0x80000000 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < 32 ; V_32 ++ ) {
if ( V_31 & V_30 )
return V_32 ;
V_31 >>= 1 ;
}
return V_32 ;
}
static T_1 F_5 ( int V_33 , T_1 V_34 , T_1 V_35 )
{
T_1 V_36 ;
int V_37 ;
V_37 = F_4 ( V_34 ) ;
if ( V_37 > V_33 )
V_37 = V_33 ;
V_36 = V_34 << V_37 ;
V_36 /= V_35 ;
if ( V_37 < V_33 ) {
V_37 = V_33 - V_37 ;
V_36 <<= V_37 ;
}
return V_36 ;
}
static void F_6 ( struct V_22 * V_23 )
{
V_23 -> V_38 = V_39 ;
V_23 -> V_40 = V_39 ;
if ( V_23 -> V_41 && V_23 -> V_42 != V_23 -> V_41 ) {
if ( V_23 -> V_41 >= V_23 -> V_42 * 8 )
return;
V_23 -> V_43 |= V_44 ;
if ( V_23 -> V_45 == V_46 ) {
if ( V_23 -> V_41 <= ( V_23 -> V_42 / 4 ) )
V_23 -> V_43 |= V_47 ;
else
V_23 -> V_43 |= V_48 ;
}
V_23 -> V_40 = F_5 ( 29 ,
V_23 -> V_42 , V_23 -> V_41 ) ;
}
if ( V_23 -> V_49 && V_23 -> V_50 != V_23 -> V_49 ) {
if ( V_23 -> V_49 >= V_23 -> V_50 * 8 )
return;
V_23 -> V_43 |= V_51 ;
if ( V_23 -> V_45 == V_46 ) {
if ( V_23 -> V_49 <= ( V_23 -> V_50 / 4 ) )
V_23 -> V_43 |= V_47 ;
else
V_23 -> V_43 |= V_48 ;
}
V_23 -> V_38 = F_5 ( 29 ,
V_23 -> V_50 , V_23 -> V_49 ) ;
}
}
void F_7 ( struct V_22 * V_23 )
{
char * V_52 ;
T_1 V_53 , V_54 , V_55 , V_56 ;
T_1 V_57 , V_58 ;
V_52 = V_21 + V_59 ;
V_52 += ( V_60 * V_23 -> V_61 ) ;
V_53 = ( ( V_23 -> V_42 << 16 ) | V_23 -> V_50 ) ;
V_54 = ( ( V_23 -> V_62 << 16 ) | V_23 -> V_63 ) ;
V_55 = ( ( V_23 -> V_41 << 16 ) | V_23 -> V_49 ) ;
V_56 = ( ( V_23 -> V_28 << 16 ) | V_23 -> V_29 ) ;
V_57 = F_8 ( V_23 ) ;
V_58 = F_9 ( V_23 ) ;
V_23 -> V_43 |= V_64 ;
F_6 ( V_23 ) ;
F_10 ( V_52 + 0x0000 , V_53 ) ;
F_10 ( V_52 + 0x0004 , V_54 ) ;
F_10 ( V_52 + 0x0008 , V_55 ) ;
F_10 ( V_52 + 0x000c , V_56 ) ;
F_10 ( V_52 + 0x0010 , V_23 -> V_26 ) ;
F_10 ( V_52 + 0x0040 , V_23 -> V_27 ) ;
F_10 ( V_52 + 0x0050 , V_57 ) ;
F_10 ( V_52 + 0x0054 , V_58 ) ;
F_10 ( V_52 + 0x0058 , V_23 -> V_43 ) ;
F_10 ( V_52 + 0x005c , V_23 -> V_38 ) ;
F_10 ( V_52 + 0x0060 , V_23 -> V_40 ) ;
F_10 ( V_52 + 0x1004 , 0xc2 ) ;
}
void F_11 ( struct V_22 * V_23 )
{
char * V_65 ;
T_1 V_66 , V_53 , V_54 , V_55 , V_56 ;
T_1 V_57 , V_58 ;
V_65 = V_21 + V_67 ;
V_65 += ( V_68 * V_23 -> V_61 ) ;
V_66 = ( ( V_23 -> V_24 << 16 ) | V_23 -> V_25 ) ;
V_53 = ( ( V_23 -> V_42 << 16 ) | V_23 -> V_50 ) ;
V_54 = ( ( V_23 -> V_62 << 16 ) | V_23 -> V_63 ) ;
V_55 = ( ( V_23 -> V_41 << 16 ) | V_23 -> V_49 ) ;
V_56 = ( ( V_23 -> V_28 << 16 ) | V_23 -> V_29 ) ;
V_57 = F_8 ( V_23 ) ;
V_58 = F_9 ( V_23 ) ;
V_23 -> V_43 |= ( V_69 | V_70 |
V_64 ) ;
F_6 ( V_23 ) ;
F_10 ( V_65 + 0x0000 , V_53 ) ;
F_10 ( V_65 + 0x0004 , V_54 ) ;
F_10 ( V_65 + 0x0008 , V_55 ) ;
F_10 ( V_65 + 0x000c , V_56 ) ;
F_10 ( V_65 + 0x0048 , V_66 ) ;
F_10 ( V_65 + 0x0010 , V_23 -> V_26 ) ;
F_10 ( V_65 + 0x0014 , V_23 -> V_71 ) ;
F_10 ( V_65 + 0x0040 ,
V_23 -> V_72 << 16 | V_23 -> V_27 ) ;
F_10 ( V_65 + 0x0050 , V_57 ) ;
F_10 ( V_65 + 0x0054 , V_58 ) ;
F_10 ( V_65 + 0x0058 , V_23 -> V_43 ) ;
F_10 ( V_65 + 0x005c , V_23 -> V_38 ) ;
F_10 ( V_65 + 0x0060 , V_23 -> V_40 ) ;
if ( V_23 -> V_43 & V_73 ) {
F_10 ( V_65 + 0x0068 ,
V_23 -> V_74 << 4 | V_23 -> V_75 << 2 | V_23 -> V_76 ) ;
}
F_10 ( V_65 + 0x1004 , 0xc2 ) ;
}
int F_12 ( T_1 V_57 )
{
switch ( V_57 ) {
case V_77 :
case V_78 :
case V_7 :
case V_79 :
case V_80 :
case V_81 :
return V_82 ;
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
return V_46 ;
default:
return - V_90 ;
}
}
int F_13 ( struct V_22 * V_23 )
{
switch ( V_23 -> V_91 ) {
case V_77 :
V_23 -> V_92 = V_93 ;
V_23 -> V_94 = V_95 ;
V_23 -> V_96 = 0 ;
V_23 -> V_74 = 1 ;
V_23 -> V_75 = 1 ;
V_23 -> V_76 = 2 ;
V_23 -> V_97 = 0 ;
V_23 -> V_98 = 1 ;
V_23 -> V_99 = 0 ;
V_23 -> V_100 = 2 ;
V_23 -> V_101 = V_102 ;
V_23 -> V_103 = V_104 ;
V_23 -> V_105 = V_106 ;
V_23 -> V_11 = 2 ;
break;
case V_78 :
V_23 -> V_92 = V_93 ;
V_23 -> V_94 = V_95 ;
V_23 -> V_96 = 0 ;
V_23 -> V_74 = 3 ;
V_23 -> V_75 = 3 ;
V_23 -> V_76 = 3 ;
V_23 -> V_97 = 0 ;
V_23 -> V_98 = 1 ;
V_23 -> V_99 = 0 ;
V_23 -> V_100 = 2 ;
V_23 -> V_101 = V_102 ;
V_23 -> V_103 = V_104 ;
V_23 -> V_105 = V_106 ;
V_23 -> V_11 = 3 ;
break;
case V_7 :
V_23 -> V_92 = V_93 ;
V_23 -> V_94 = V_95 ;
V_23 -> V_96 = 0 ;
V_23 -> V_74 = 1 ;
V_23 -> V_75 = 1 ;
V_23 -> V_76 = 2 ;
V_23 -> V_97 = 0 ;
V_23 -> V_98 = 1 ;
V_23 -> V_99 = 0 ;
V_23 -> V_100 = 2 ;
V_23 -> V_101 = V_106 ;
V_23 -> V_103 = V_104 ;
V_23 -> V_105 = V_102 ;
V_23 -> V_11 = 2 ;
break;
case V_79 :
V_23 -> V_92 = V_93 ;
V_23 -> V_94 = V_95 ;
V_23 -> V_96 = 3 ;
V_23 -> V_74 = 3 ;
V_23 -> V_75 = 3 ;
V_23 -> V_76 = 3 ;
V_23 -> V_97 = 1 ;
V_23 -> V_98 = 1 ;
V_23 -> V_99 = 0 ;
V_23 -> V_100 = 3 ;
V_23 -> V_107 = V_108 ;
V_23 -> V_101 = V_102 ;
V_23 -> V_103 = V_104 ;
V_23 -> V_105 = V_106 ;
V_23 -> V_11 = 4 ;
break;
case V_80 :
V_23 -> V_92 = V_93 ;
V_23 -> V_94 = V_95 ;
V_23 -> V_96 = 3 ;
V_23 -> V_74 = 3 ;
V_23 -> V_75 = 3 ;
V_23 -> V_76 = 3 ;
V_23 -> V_97 = 1 ;
V_23 -> V_98 = 1 ;
V_23 -> V_99 = 0 ;
V_23 -> V_100 = 3 ;
V_23 -> V_107 = V_102 ;
V_23 -> V_101 = V_104 ;
V_23 -> V_103 = V_106 ;
V_23 -> V_105 = V_108 ;
V_23 -> V_11 = 4 ;
break;
case V_81 :
V_23 -> V_92 = V_93 ;
V_23 -> V_94 = V_95 ;
V_23 -> V_96 = 3 ;
V_23 -> V_74 = 3 ;
V_23 -> V_75 = 3 ;
V_23 -> V_76 = 3 ;
V_23 -> V_97 = 1 ;
V_23 -> V_98 = 1 ;
V_23 -> V_99 = 0 ;
V_23 -> V_100 = 3 ;
V_23 -> V_107 = V_106 ;
V_23 -> V_101 = V_104 ;
V_23 -> V_103 = V_102 ;
V_23 -> V_105 = V_108 ;
V_23 -> V_11 = 4 ;
break;
case V_83 :
V_23 -> V_92 = V_93 ;
V_23 -> V_94 = V_95 ;
V_23 -> V_96 = 0 ;
V_23 -> V_74 = 3 ;
V_23 -> V_75 = 3 ;
V_23 -> V_76 = 3 ;
V_23 -> V_97 = 0 ;
V_23 -> V_98 = 1 ;
V_23 -> V_99 = 0 ;
V_23 -> V_100 = 3 ;
V_23 -> V_107 = V_104 ;
V_23 -> V_101 = V_102 ;
V_23 -> V_103 = V_104 ;
V_23 -> V_105 = V_106 ;
V_23 -> V_11 = 2 ;
V_23 -> V_109 = V_110 ;
break;
case V_84 :
case V_85 :
case V_86 :
case V_87 :
V_23 -> V_92 = V_93 ;
V_23 -> V_94 = V_111 ;
V_23 -> V_96 = 0 ;
V_23 -> V_74 = 3 ;
V_23 -> V_75 = 3 ;
V_23 -> V_76 = 3 ;
V_23 -> V_97 = 0 ;
V_23 -> V_98 = 1 ;
V_23 -> V_99 = 0 ;
V_23 -> V_100 = 1 ;
V_23 -> V_107 = V_104 ;
V_23 -> V_101 = V_104 ;
if ( V_23 -> V_91 == V_84 ) {
V_23 -> V_103 = V_102 ;
V_23 -> V_105 = V_106 ;
V_23 -> V_109 = V_110 ;
} else if ( V_23 -> V_91 == V_85 ) {
V_23 -> V_103 = V_106 ;
V_23 -> V_105 = V_102 ;
V_23 -> V_109 = V_110 ;
} else if ( V_23 -> V_91 == V_86 ) {
V_23 -> V_103 = V_102 ;
V_23 -> V_105 = V_106 ;
V_23 -> V_109 = V_112 ;
} else if ( V_23 -> V_91 == V_87 ) {
V_23 -> V_103 = V_106 ;
V_23 -> V_105 = V_102 ;
V_23 -> V_109 = V_112 ;
}
V_23 -> V_11 = 2 ;
break;
case V_88 :
case V_89 :
V_23 -> V_92 = V_113 ;
V_23 -> V_94 = V_111 ;
V_23 -> V_96 = 0 ;
V_23 -> V_74 = 3 ;
V_23 -> V_75 = 3 ;
V_23 -> V_76 = 3 ;
V_23 -> V_97 = 0 ;
V_23 -> V_98 = 1 ;
V_23 -> V_99 = 0 ;
V_23 -> V_100 = 1 ;
V_23 -> V_107 = V_104 ;
V_23 -> V_101 = V_104 ;
if ( V_23 -> V_91 == V_89 ) {
V_23 -> V_103 = V_102 ;
V_23 -> V_105 = V_106 ;
V_23 -> V_109 = V_112 ;
} else if ( V_23 -> V_91 == V_88 ) {
V_23 -> V_103 = V_106 ;
V_23 -> V_105 = V_102 ;
V_23 -> V_109 = V_112 ;
}
V_23 -> V_11 = 2 ;
break;
default:
return - V_90 ;
}
return 0 ;
}
static T_1 F_14 ( int V_114 , int V_30 , T_1 V_115 )
{
T_1 V_116 ;
V_116 = ( V_115 >> V_114 ) & ( ( 1 << V_30 ) - 1 ) ;
if ( V_30 == 5 )
V_116 = ( V_116 << 7 ) + ( V_116 << 2 ) + ( V_116 >> 3 ) ;
else if ( V_30 == 6 )
V_116 = ( V_116 << 6 ) + V_116 ;
else
V_116 = ( V_116 << 4 ) + ( V_116 >> 4 ) ;
return V_116 ;
}
void F_15 ( int V_57 , T_1 V_117 ,
T_1 * V_118 , T_1 * V_119 , T_1 * V_120 )
{
int V_121 , V_122 , V_123 ;
int V_124 , V_125 , V_126 ;
switch ( V_57 ) {
case V_77 :
V_121 = 0 ;
V_122 = 5 ;
V_123 = 11 ;
V_126 = 5 ;
V_125 = 6 ;
V_124 = 5 ;
break;
case V_78 :
case V_127 :
case V_79 :
V_121 = 0 ;
V_122 = 8 ;
V_123 = 16 ;
V_126 = 8 ;
V_125 = 8 ;
V_124 = 8 ;
break;
case V_7 :
V_121 = 11 ;
V_122 = 5 ;
V_123 = 0 ;
V_126 = 5 ;
V_125 = 6 ;
V_124 = 5 ;
break;
case V_87 :
case V_85 :
V_121 = 8 ;
V_122 = 16 ;
V_123 = 0 ;
V_126 = 8 ;
V_125 = 8 ;
V_124 = 8 ;
break;
case V_86 :
case V_84 :
V_121 = 0 ;
V_122 = 16 ;
V_123 = 8 ;
V_126 = 8 ;
V_125 = 8 ;
V_124 = 8 ;
break;
default:
V_121 = 0 ;
V_122 = 8 ;
V_123 = 16 ;
V_126 = 8 ;
V_125 = 8 ;
V_124 = 8 ;
break;
}
* V_118 = F_14 ( V_122 , V_125 , V_117 ) ;
* V_119 = F_14 ( V_121 , V_124 , V_117 ) ;
* V_120 = F_14 ( V_123 , V_126 , V_117 ) ;
}
T_1 F_8 ( struct V_22 * V_23 )
{
T_1 V_57 ;
V_57 = 0 ;
if ( V_23 -> V_128 )
V_57 |= V_129 ;
if ( V_23 -> V_99 )
V_57 |= V_130 ;
if ( V_23 -> V_98 )
V_57 |= V_131 ;
if ( V_23 -> V_97 )
V_57 |= V_132 ;
V_57 |= ( V_23 -> V_100 << 13 ) ;
V_57 |= ( ( V_23 -> V_11 - 1 ) << 9 ) ;
V_57 |= ( V_23 -> V_96 << 6 ) ;
V_57 |= ( V_23 -> V_74 << 4 ) ;
V_57 |= ( V_23 -> V_75 << 2 ) ;
V_57 |= V_23 -> V_76 ;
V_57 |= ( V_23 -> V_92 << 29 ) ;
if ( V_23 -> V_94 == V_111 ) {
V_57 |= ( V_23 -> V_94 << 19 ) ;
V_57 |= ( V_23 -> V_133 << 28 ) ;
V_57 |= ( V_23 -> V_109 << 26 ) ;
}
return V_57 ;
}
T_1 F_9 ( struct V_22 * V_23 )
{
return ( V_23 -> V_107 << 24 ) | ( V_23 -> V_101 << 16 ) |
( V_23 -> V_103 << 8 ) | V_23 -> V_105 ;
}
void F_16 ( struct V_22 * V_23 )
{
T_1 V_116 ;
char * V_134 ;
if ( V_23 -> V_135 == V_136 )
V_134 = V_21 + V_137 ;
else
V_134 = V_21 + V_138 ;
F_10 ( V_134 + 0x0004 , 0x01 ) ;
V_116 = V_23 -> V_24 ;
V_116 <<= 16 ;
V_116 |= V_23 -> V_25 ;
F_10 ( V_134 + 0x0008 , V_116 ) ;
F_10 ( V_134 + 0x000c , V_23 -> V_26 ) ;
F_10 ( V_134 + 0x0010 , V_23 -> V_27 ) ;
F_10 ( V_134 + 0x0014 , 0x4 ) ;
}
int F_17 ( int V_139 )
{
T_1 V_116 , V_140 , V_32 ;
int V_141 , V_142 ;
V_116 = F_18 ( V_21 + 0x10100 ) ;
V_141 = 0 ;
V_142 = 0 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
V_140 = V_116 & 0x0f ;
if ( V_140 ) {
if ( V_140 <= 4 )
V_141 ++ ;
else
V_142 ++ ;
}
V_116 >>= 4 ;
}
if ( V_139 )
return V_142 ;
else
return V_141 ;
}
void F_19 ( struct V_22 * V_23 )
{
T_1 V_116 , V_140 , V_143 , V_144 , V_139 ;
V_144 = V_23 -> V_145 ;
V_139 = V_23 -> V_135 ;
V_116 = F_18 ( V_21 + 0x10100 ) ;
if ( V_139 == V_136 )
V_144 += 8 ;
if ( V_23 -> V_45 == V_46 ) {
V_143 = 0 ;
V_143 += ( 4 * V_23 -> V_61 ) ;
} else {
V_143 = 8 ;
V_143 += ( 4 * V_23 -> V_61 ) ;
}
V_140 = 0x0f ;
V_140 <<= V_143 ;
V_144 <<= V_143 ;
V_116 &= ~ V_140 ;
V_116 |= V_144 ;
F_10 ( V_21 + 0x10100 , V_116 ) ;
V_116 = F_18 ( V_21 + 0x10100 ) ;
V_146 -> V_144 [ V_23 -> V_135 ] [ V_23 -> V_145 ] = V_23 ;
}
void F_20 ( struct V_22 * V_23 )
{
T_1 V_116 , V_140 , V_143 , V_144 , V_139 ;
V_144 = V_23 -> V_145 ;
V_139 = V_23 -> V_135 ;
if ( V_23 != V_146 -> V_144 [ V_139 ] [ V_144 ] )
return;
V_116 = F_18 ( V_21 + 0x10100 ) ;
if ( V_139 == V_136 )
V_144 += 8 ;
if ( V_23 -> V_45 == V_46 ) {
V_143 = 0 ;
V_143 += ( 4 * V_23 -> V_61 ) ;
} else {
V_143 = 8 ;
V_143 += ( 4 * V_23 -> V_61 ) ;
}
V_140 = 0x0f ;
V_140 <<= V_143 ;
V_116 &= ~ V_140 ;
F_10 ( V_21 + 0x10100 , V_116 ) ;
V_116 = F_18 ( V_21 + 0x10100 ) ;
V_146 -> V_144 [ V_23 -> V_135 ] [ V_23 -> V_145 ] = NULL ;
}
void F_21 ( struct V_22 * V_23 )
{
unsigned char * V_134 ;
T_1 V_118 , V_119 , V_120 , V_147 ;
int V_148 ;
if ( V_23 -> V_135 )
V_134 = V_21 + V_137 ;
else
V_134 = V_21 + V_138 ;
V_148 = 0x20 * ( V_23 -> V_145 - V_149 ) ;
V_147 = 0 ;
if ( V_23 -> V_97 )
V_147 = V_150 |
V_151 ;
else
V_147 = ( V_152 |
V_153 ) ;
if ( V_23 -> V_97 == 0 ) {
if ( V_23 -> V_154 ) {
F_10 ( V_134 + V_148 + 0x108 , V_23 -> V_155 ) ;
F_10 ( V_134 + V_148 + 0x10c , 0xff - V_23 -> V_155 ) ;
} else {
F_10 ( V_134 + V_148 + 0x108 , 0xff - V_23 -> V_155 ) ;
F_10 ( V_134 + V_148 + 0x10c , V_23 -> V_155 ) ;
}
}
if ( V_23 -> V_117 != V_156 ) {
F_15 ( V_23 -> V_91 , V_23 -> V_117 , & V_118 , & V_119 , & V_120 ) ;
if ( V_23 -> V_154 ) {
V_147 |= V_157 ;
if ( V_118 > 0x10 )
V_118 -= 0x10 ;
if ( V_119 > 0x10 )
V_119 -= 0x10 ;
if ( V_120 > 0x10 )
V_120 -= 0x10 ;
F_10 ( V_134 + V_148 + 0x110 ,
( V_119 << 16 | V_118 ) ) ;
F_10 ( V_134 + V_148 + 0x114 , V_120 ) ;
if ( ( V_118 + 0x20 ) < 0x0fff )
V_118 += 0x20 ;
else
V_118 = 0x0fff ;
if ( ( V_119 + 0x20 ) < 0x0fff )
V_119 += 0x20 ;
else
V_119 = 0x0fff ;
if ( ( V_120 + 0x20 ) < 0x0fff )
V_120 += 0x20 ;
else
V_120 = 0x0fff ;
F_10 ( V_134 + V_148 + 0x118 ,
( V_119 << 16 | V_118 ) ) ;
F_10 ( V_134 + V_148 + 0x11c , V_120 ) ;
} else {
V_147 |= V_158 ;
if ( V_118 > 0x10 )
V_118 -= 0x10 ;
if ( V_119 > 0x10 )
V_119 -= 0x10 ;
if ( V_120 > 0x10 )
V_120 -= 0x10 ;
F_10 ( V_134 + 0x180 ,
( V_119 << 16 | V_118 ) ) ;
F_10 ( V_134 + 0x184 , V_120 ) ;
if ( ( V_118 + 0x20 ) < 0x0fff )
V_118 += 0x20 ;
else
V_118 = 0x0fff ;
if ( ( V_119 + 0x20 ) < 0x0fff )
V_119 += 0x20 ;
else
V_119 = 0x0fff ;
if ( ( V_120 + 0x20 ) < 0x0fff )
V_120 += 0x20 ;
else
V_120 = 0x0fff ;
F_10 ( V_134 + 0x188 ,
( V_119 << 16 | V_118 ) ) ;
F_10 ( V_134 + 0x18c , V_120 ) ;
}
}
F_10 ( V_134 + V_148 + 0x104 , V_147 ) ;
}
void F_22 ( struct V_22 * V_23 , int V_159 )
{
T_1 V_160 = 0 ;
if ( V_23 -> V_135 == V_136 )
V_160 |= 0x02 ;
else
V_160 |= 0x01 ;
if ( V_159 ) {
if ( V_23 -> V_45 == V_82 ) {
if ( V_23 -> V_61 == V_161 )
V_160 |= 0x20 ;
else
V_160 |= 0x10 ;
} else {
if ( V_23 -> V_61 == V_162 )
V_160 |= 0x08 ;
else
V_160 |= 0x04 ;
}
}
F_10 ( V_21 + 0x18000 , V_160 ) ;
while ( F_18 ( V_21 + 0x18000 ) & V_160 )
;
}
struct V_22 * F_23 ( int V_163 )
{
struct V_22 * V_23 ;
if ( V_163 == 0 || V_163 >= V_164 )
return NULL ;
V_23 = & V_146 -> V_165 [ V_163 - 1 ] ;
if ( V_23 -> V_166 == 0 )
return NULL ;
return V_23 ;
}
struct V_22 * F_24 ( void )
{
int V_32 ;
struct V_22 * V_23 ;
V_23 = & V_146 -> V_165 [ 0 ] ;
for ( V_32 = 0 ; V_32 < V_164 ; V_32 ++ ) {
if ( V_23 -> V_166 == 0 ) {
V_23 -> V_166 = V_32 + 1 ;
F_25 ( & V_23 -> V_167 ) ;
F_26 ( V_168 L_1 ,
V_23 , V_23 -> V_166 ) ;
return V_23 ;
}
V_23 ++ ;
}
return NULL ;
}
void F_27 ( struct V_22 * V_23 )
{
F_26 ( V_168 L_2 ,
V_23 , V_23 -> V_166 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
}
static int F_28 ( int V_169 , int V_144 )
{
if ( V_169 == V_82 ) {
if ( V_144 == V_170 )
return V_171 ;
else
return V_161 ;
} else {
if ( V_144 == V_149 )
return V_172 ;
else
return V_162 ;
}
}
int F_29 ( T_1 V_173 , T_1 V_174 , T_1 V_139 )
{
struct V_22 * V_23 ;
V_23 = V_146 -> V_144 [ V_139 ] [ V_174 ] ;
if ( V_23 == NULL )
return 0 ;
if ( V_23 -> V_166 == V_173 )
return 0 ;
return - V_175 ;
}
static int F_30 ( struct V_176 * V_177 , int V_139 ,
struct V_22 * * V_178 )
{
struct V_22 * V_23 ;
int V_179 , V_169 ;
if ( V_139 >= V_180 ) {
F_26 ( V_181 L_3 ) ;
return - V_90 ;
}
if ( V_177 -> V_174 < 0 || V_177 -> V_174 > 2 ) {
F_26 ( V_181 L_4 ,
V_177 -> V_174 ) ;
return - V_90 ;
}
if ( V_177 -> V_182 . V_183 == 0 || V_177 -> V_182 . V_184 == 0 ) {
F_26 ( V_181 L_5 ) ;
return - V_185 ;
}
V_179 = F_29 ( V_177 -> V_173 , V_177 -> V_174 , V_139 ) ;
if ( V_179 < 0 )
return V_179 ;
V_169 = F_12 ( V_177 -> V_34 . V_57 ) ;
if ( V_169 < 0 )
return V_169 ;
if ( V_177 -> V_173 == V_186 )
V_23 = F_24 () ;
else
V_23 = F_23 ( V_177 -> V_173 ) ;
if ( V_23 == NULL )
return - V_187 ;
V_23 -> V_91 = V_177 -> V_34 . V_57 ;
V_179 = F_13 ( V_23 ) ;
if ( V_179 < 0 )
return V_179 ;
if ( V_177 -> V_173 == V_186 ) {
V_23 -> V_145 = V_177 -> V_174 + V_149 ;
V_23 -> V_45 = V_169 ;
V_23 -> V_61 = F_28 ( V_169 , V_23 -> V_145 ) ;
F_26 ( V_168 L_6 ,
V_177 -> V_174 , V_23 -> V_61 ) ;
}
V_23 -> V_25 = V_177 -> V_34 . V_188 & 0x07ff ;
V_23 -> V_24 = V_177 -> V_34 . V_189 & 0x07ff ;
V_23 -> V_42 = V_177 -> V_182 . V_183 & 0x07ff ;
V_23 -> V_50 = V_177 -> V_182 . V_184 & 0x07ff ;
V_23 -> V_62 = V_177 -> V_182 . V_190 & 0x07ff ;
V_23 -> V_63 = V_177 -> V_182 . V_191 & 0x07ff ;
V_23 -> V_41 = V_177 -> V_192 . V_183 & 0x07ff ;
V_23 -> V_49 = V_177 -> V_192 . V_184 & 0x07ff ;
V_23 -> V_28 = V_177 -> V_192 . V_190 & 0x07ff ;
V_23 -> V_29 = V_177 -> V_192 . V_191 & 0x07ff ;
if ( V_177 -> V_193 & V_194 )
V_23 -> V_43 |= V_195 ;
if ( V_177 -> V_193 & V_196 )
V_23 -> V_43 |= V_197 ;
if ( V_177 -> V_193 & V_198 )
V_23 -> V_43 |= V_73 ;
if ( V_177 -> V_193 & V_199 )
V_23 -> V_43 |= V_200 ;
V_23 -> V_154 = V_177 -> V_154 ;
V_23 -> V_155 = V_177 -> V_155 & 0x0ff ;
V_23 -> V_117 = V_177 -> V_201 ;
* V_178 = V_23 ;
return 0 ;
}
int F_31 ( struct V_202 * V_203 , struct V_204 * V_205 ,
unsigned long * V_114 , unsigned long * V_206 , struct V_207 * * V_208 )
{
int V_209 , V_179 = 0 ;
struct V_207 * V_207 ;
#ifdef F_32
unsigned long V_210 ;
#endif
#ifdef F_32
if ( ! F_33 ( V_203 -> V_211 , V_114 , & V_210 , V_206 , V_208 ) )
return 0 ;
#endif
V_207 = F_34 ( V_203 -> V_211 , & V_209 ) ;
if ( V_207 == NULL )
return - 1 ;
if ( F_35 ( V_207 -> V_212 -> V_213 -> V_214 ) == V_215 ) {
* V_114 = V_205 -> V_216 . V_217 ;
* V_206 = V_205 -> V_216 . V_218 ;
* V_208 = V_207 ;
} else {
V_179 = - 1 ;
F_36 ( V_207 , V_209 ) ;
}
return V_179 ;
}
int F_37 ( struct V_204 * V_205 , struct V_176 * V_177 )
{
struct V_22 * V_23 ;
V_23 = F_23 ( V_177 -> V_173 ) ;
if ( V_23 == NULL )
return - V_219 ;
* V_177 = V_23 -> V_220 ;
return 0 ;
}
int F_38 ( struct V_204 * V_205 , struct V_176 * V_177 )
{
struct V_1 * V_2 = (struct V_1 * ) V_205 -> V_221 ;
int V_179 , V_139 ;
struct V_22 * V_23 ;
int V_3 ;
if ( V_2 == NULL )
return - V_219 ;
if ( V_177 -> V_34 . V_57 == V_222 )
V_177 -> V_34 . V_57 = V_2 -> V_6 ;
if ( F_39 ( & V_2 -> V_223 -> V_224 ) )
return - V_225 ;
V_139 = V_205 -> V_226 ;
V_179 = F_30 ( V_177 , V_139 , & V_23 ) ;
if ( V_179 < 0 ) {
F_40 ( & V_2 -> V_223 -> V_224 ) ;
return V_179 ;
}
V_3 = F_18 ( V_21 + 0xc0000 ) ;
if ( V_3 == 0 ) {
F_41 ( V_227 , V_228 , FALSE ) ;
}
V_177 -> V_173 = V_23 -> V_166 ;
V_23 -> V_220 = * V_177 ;
F_40 ( & V_2 -> V_223 -> V_224 ) ;
return 0 ;
}
int F_42 ( struct V_204 * V_205 , int V_163 )
{
struct V_1 * V_2 = (struct V_1 * ) V_205 -> V_221 ;
struct V_22 * V_23 ;
int V_3 ;
if ( V_2 == NULL )
return - V_219 ;
if ( F_39 ( & V_2 -> V_223 -> V_224 ) )
return - V_225 ;
V_23 = F_23 ( V_163 ) ;
if ( V_23 == NULL ) {
F_40 ( & V_2 -> V_223 -> V_224 ) ;
return - V_219 ;
}
V_3 = F_18 ( V_21 + 0xc0000 ) ;
F_20 ( V_23 ) ;
if ( V_3 == 0 ) {
F_41 ( V_227 , V_229 , FALSE ) ;
}
if ( V_3 )
F_22 ( V_23 , 0 ) ;
F_27 ( V_23 ) ;
if ( V_3 == 0 ) {
F_43 () ;
}
F_40 ( & V_2 -> V_223 -> V_224 ) ;
return 0 ;
}
void F_44 ( struct V_230 * V_231 )
{
V_231 -> V_188 = 64 ;
V_231 -> V_232 = 2 ;
V_231 -> V_189 = 32 ;
V_231 -> V_233 = 1 ;
}
T_1 F_45 ( struct V_22 * V_23 , struct V_230 * V_231 )
{
T_1 V_234 , V_235 ;
T_1 V_236 , V_237 ;
V_234 = V_231 -> V_188 * V_231 -> V_232 ;
V_235 = V_231 -> V_189 * V_231 -> V_233 ;
V_236 = ( V_23 -> V_25 + V_234 - 1 ) / V_234 ;
V_237 = ( V_23 -> V_24 + V_235 - 1 ) / V_235 ;
return V_236 * V_237 * V_234 * V_235 ;
}
int F_46 ( struct V_204 * V_205 , struct V_238 * V_177 ,
struct V_207 * * V_239 )
{
struct V_1 * V_2 = (struct V_1 * ) V_205 -> V_221 ;
struct V_202 * V_203 ;
struct V_22 * V_23 ;
T_2 V_114 , V_240 ;
T_2 V_206 = 0 ;
struct V_207 * V_241 = 0 ;
int V_3 ;
if ( V_2 == NULL )
return - V_219 ;
V_23 = F_23 ( V_177 -> V_173 ) ;
if ( V_23 == NULL )
return - V_219 ;
if ( F_39 ( & V_2 -> V_223 -> V_224 ) )
return - V_225 ;
V_203 = & V_177 -> V_116 ;
F_31 ( V_203 , V_205 , & V_114 , & V_206 , & V_241 ) ;
if ( V_206 == 0 ) {
F_40 ( & V_2 -> V_223 -> V_224 ) ;
F_26 ( V_181 L_7
L_8 ) ;
return - 1 ;
}
* V_239 = V_241 ;
V_240 = V_114 + V_203 -> V_242 ;
V_23 -> V_26 = V_240 ;
V_23 -> V_27 = V_23 -> V_25 * V_23 -> V_11 ;
if ( V_23 -> V_94 == V_111 ) {
if ( V_23 -> V_92 == V_113 ) {
struct V_230 V_243 ;
F_44 ( & V_243 ) ;
V_23 -> V_71 = V_240 + F_45 ( V_23 , & V_243 ) ;
} else
V_23 -> V_71 = V_240 +
V_23 -> V_25 * V_23 -> V_24 ;
V_23 -> V_27 = V_23 -> V_25 ;
V_23 -> V_72 = V_23 -> V_25 ;
}
V_3 = F_18 ( V_21 + 0xc0000 ) ;
V_3 &= 0x01 ;
if ( V_23 -> V_45 == V_46 )
F_11 ( V_23 ) ;
else
F_7 ( V_23 ) ;
F_21 ( V_23 ) ;
F_19 ( V_23 ) ;
if ( V_3 ) {
F_22 ( V_23 , 1 ) ;
}
if ( V_3 ) {
if ( V_23 -> V_145 != V_170 ) {
F_40 ( & V_2 -> V_223 -> V_224 ) ;
return 0 ;
}
}
if ( V_3 == 0 ) {
#ifdef F_47
if ( V_2 -> V_244 )
#else
if ( ! V_2 -> V_223 -> V_245 && V_2 -> V_244 )
#endif
F_48 ( V_2 , V_23 ) ;
}
F_40 ( & V_2 -> V_223 -> V_224 ) ;
return 0 ;
}
