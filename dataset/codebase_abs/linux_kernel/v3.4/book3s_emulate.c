static bool F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
if ( V_2 -> V_5 . V_6 && ( V_4 > V_7 ) )
return false ;
if ( ( V_2 -> V_5 . V_8 -> V_9 & V_10 ) && V_4 > V_11 )
return false ;
return true ;
}
int F_2 ( struct V_12 * V_13 , struct V_1 * V_2 ,
unsigned int V_14 , int * V_15 )
{
int V_16 = V_17 ;
switch ( F_3 ( V_14 ) ) {
case 19 :
switch ( F_4 ( V_14 ) ) {
case V_18 :
case V_19 :
F_5 ( V_2 , V_2 -> V_5 . V_8 -> V_20 ) ;
F_6 ( V_2 , V_2 -> V_5 . V_8 -> V_21 ) ;
* V_15 = 0 ;
break;
default:
V_16 = V_22 ;
break;
}
break;
case 31 :
switch ( F_4 ( V_14 ) ) {
case V_23 :
F_7 ( V_2 , F_8 ( V_14 ) ,
V_2 -> V_5 . V_8 -> V_9 ) ;
break;
case V_24 :
{
T_1 V_25 = F_9 ( V_2 , F_10 ( V_14 ) ) ;
if ( V_14 & 0x10000 ) {
V_2 -> V_5 . V_8 -> V_9 &= ~ ( V_26 | V_27 ) ;
V_2 -> V_5 . V_8 -> V_9 |= V_25 & ( V_26 | V_27 ) ;
} else
F_6 ( V_2 , V_25 ) ;
break;
}
case V_28 :
F_6 ( V_2 , F_9 ( V_2 , F_10 ( V_14 ) ) ) ;
break;
case V_29 :
{
int V_30 ;
V_30 = F_11 ( V_14 , 12 + 32 , 15 + 32 ) ;
if ( V_2 -> V_5 . V_31 . V_32 ) {
T_2 V_33 ;
V_33 = V_2 -> V_5 . V_31 . V_32 ( V_2 , V_30 ) ;
F_7 ( V_2 , F_8 ( V_14 ) , V_33 ) ;
}
break;
}
case V_34 :
{
int V_30 ;
V_30 = ( F_9 ( V_2 , F_12 ( V_14 ) ) >> 28 ) & 0xf ;
if ( V_2 -> V_5 . V_31 . V_32 ) {
T_2 V_33 ;
V_33 = V_2 -> V_5 . V_31 . V_32 ( V_2 , V_30 ) ;
F_7 ( V_2 , F_8 ( V_14 ) , V_33 ) ;
}
break;
}
case V_35 :
V_2 -> V_5 . V_31 . V_36 ( V_2 ,
( V_14 >> 16 ) & 0xf ,
F_9 ( V_2 , F_10 ( V_14 ) ) ) ;
break;
case V_37 :
V_2 -> V_5 . V_31 . V_36 ( V_2 ,
( F_9 ( V_2 , F_12 ( V_14 ) ) >> 28 ) & 0xf ,
F_9 ( V_2 , F_10 ( V_14 ) ) ) ;
break;
case V_38 :
case V_39 :
{
bool V_40 = ( V_14 & 0x00200000 ) ? true : false ;
T_1 V_41 = F_9 ( V_2 , F_12 ( V_14 ) ) ;
V_2 -> V_5 . V_31 . V_42 ( V_2 , V_41 , V_40 ) ;
break;
}
case V_43 :
break;
case V_44 :
if ( ! V_2 -> V_5 . V_31 . V_45 )
return V_22 ;
V_2 -> V_5 . V_31 . V_45 ( V_2 ,
F_9 ( V_2 , F_10 ( V_14 ) ) ,
F_9 ( V_2 , F_12 ( V_14 ) ) ) ;
break;
case V_46 :
if ( ! V_2 -> V_5 . V_31 . V_47 )
return V_22 ;
V_2 -> V_5 . V_31 . V_47 ( V_2 ,
F_9 ( V_2 , F_12 ( V_14 ) ) ) ;
break;
case V_48 :
if ( ! V_2 -> V_5 . V_31 . V_49 )
return V_22 ;
V_2 -> V_5 . V_31 . V_49 ( V_2 ) ;
break;
case V_50 :
if ( ! V_2 -> V_5 . V_31 . V_51 ) {
V_16 = V_22 ;
} else {
T_1 V_52 , V_53 ;
V_53 = F_9 ( V_2 , F_12 ( V_14 ) ) ;
V_52 = V_2 -> V_5 . V_31 . V_51 ( V_2 , V_53 ) ;
F_7 ( V_2 , F_8 ( V_14 ) , V_52 ) ;
}
break;
case V_54 :
if ( ! V_2 -> V_5 . V_31 . V_55 ) {
V_16 = V_22 ;
} else {
T_1 V_52 , V_53 ;
V_53 = F_9 ( V_2 , F_12 ( V_14 ) ) ;
V_52 = V_2 -> V_5 . V_31 . V_55 ( V_2 , V_53 ) ;
F_7 ( V_2 , F_8 ( V_14 ) , V_52 ) ;
}
break;
case V_56 :
break;
case V_57 :
{
T_1 V_53 = F_9 ( V_2 , F_12 ( V_14 ) ) ;
T_1 V_58 = 0 ;
T_1 V_41 , V_59 ;
T_2 V_60 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_61 ;
int V_62 ;
if ( F_13 ( V_14 ) )
V_58 = F_9 ( V_2 , F_13 ( V_14 ) ) ;
V_41 = ( V_58 + V_53 ) & ~ 31ULL ;
if ( ! ( V_2 -> V_5 . V_8 -> V_9 & V_63 ) )
V_41 &= 0xffffffff ;
V_59 = V_41 ;
V_62 = F_14 ( V_2 , & V_41 , 32 , V_60 , true ) ;
if ( ( V_62 == - V_64 ) || ( V_62 == - V_65 ) ) {
struct V_66 * V_67 ;
V_67 = F_15 ( V_2 ) ;
* V_15 = 0 ;
V_2 -> V_5 . V_8 -> V_68 = V_59 ;
V_67 -> V_69 = V_59 ;
V_61 = V_70 ;
if ( V_62 == - V_64 )
V_61 |= V_71 ;
else if ( V_62 == - V_65 )
V_61 |= V_72 ;
V_2 -> V_5 . V_8 -> V_61 = V_61 ;
V_67 -> V_73 = V_61 ;
F_16 ( V_67 ) ;
F_17 ( V_2 ,
V_74 ) ;
}
break;
}
default:
V_16 = V_22 ;
}
break;
default:
V_16 = V_22 ;
}
if ( V_16 == V_22 )
V_16 = F_18 ( V_13 , V_2 ) ;
return V_16 ;
}
void F_19 ( struct V_1 * V_2 , struct V_75 * V_76 , bool V_77 ,
T_2 V_78 )
{
if ( V_77 ) {
T_2 V_79 = ( V_78 >> 2 ) & 0x7ff ;
V_76 -> V_80 = ( ~ V_79 << 17 ) ;
V_76 -> V_81 = V_78 & 0xfffe0000 ;
V_76 -> V_82 = ( V_78 & 2 ) ? 1 : 0 ;
V_76 -> V_83 = ( V_78 & 1 ) ? 1 : 0 ;
V_76 -> V_84 = ( V_76 -> V_84 & 0xffffffff00000000ULL ) | V_78 ;
} else {
V_76 -> V_85 = V_78 & 0xfffe0000 ;
V_76 -> V_86 = ( V_78 >> 3 ) & 0xf ;
V_76 -> V_87 = V_78 & 3 ;
V_76 -> V_84 = ( V_76 -> V_84 & 0x00000000ffffffffULL ) | ( ( V_88 ) V_78 << 32 ) ;
}
}
static struct V_75 * F_20 ( struct V_1 * V_2 , int V_89 )
{
struct V_90 * V_91 = F_21 ( V_2 ) ;
struct V_75 * V_76 ;
switch ( V_89 ) {
case V_92 ... V_93 :
V_76 = & V_91 -> V_94 [ ( V_89 - V_92 ) / 2 ] ;
break;
case V_95 ... V_96 :
V_76 = & V_91 -> V_94 [ 4 + ( ( V_89 - V_95 ) / 2 ) ] ;
break;
case V_97 ... V_98 :
V_76 = & V_91 -> V_99 [ ( V_89 - V_97 ) / 2 ] ;
break;
case V_100 ... V_101 :
V_76 = & V_91 -> V_99 [ 4 + ( ( V_89 - V_100 ) / 2 ) ] ;
break;
default:
F_22 () ;
}
return V_76 ;
}
int F_23 ( struct V_1 * V_2 , int V_89 , int V_25 )
{
int V_16 = V_17 ;
T_1 V_102 = F_9 ( V_2 , V_25 ) ;
switch ( V_89 ) {
case V_103 :
if ( ! F_1 ( V_2 , V_104 ) )
goto V_105;
F_21 ( V_2 ) -> V_106 = V_102 ;
break;
case V_107 :
V_2 -> V_5 . V_8 -> V_61 = V_102 ;
break;
case V_108 :
V_2 -> V_5 . V_8 -> V_68 = V_102 ;
break;
case V_109 :
F_21 ( V_2 ) -> V_110 = V_102 ;
break;
case V_92 ... V_93 :
case V_95 ... V_96 :
case V_97 ... V_98 :
case V_100 ... V_101 :
{
struct V_75 * V_76 = F_20 ( V_2 , V_89 ) ;
F_19 ( V_2 , V_76 , ! ( V_89 % 2 ) , ( T_2 ) V_102 ) ;
F_24 ( V_2 , 0 , 0 ) ;
F_25 ( V_2 ) ;
break;
}
case V_111 :
F_21 ( V_2 ) -> V_112 [ 0 ] = V_102 ;
break;
case V_113 :
F_21 ( V_2 ) -> V_112 [ 1 ] = V_102 ;
break;
case V_114 :
F_21 ( V_2 ) -> V_112 [ 2 ] = V_102 ;
break;
case V_115 :
F_21 ( V_2 ) -> V_112 [ 2 ] = V_102 ;
switch ( V_2 -> V_5 . V_116 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
if ( V_2 -> V_5 . V_117 & V_118 ) {
} else if ( V_102 & ( 1 << 29 ) ) {
V_2 -> V_5 . V_117 |= V_119 ;
F_26 ( V_2 , V_120 ) ;
} else {
V_2 -> V_5 . V_117 &= ~ V_119 ;
}
break;
}
break;
case V_121 :
case V_122 :
F_21 ( V_2 ) -> V_112 [ 4 ] = V_102 ;
break;
case V_123 :
F_21 ( V_2 ) -> V_112 [ 5 ] = V_102 ;
if ( V_2 -> V_5 . V_31 . V_124 ( V_2 ) &&
( F_27 () & V_125 ) )
V_2 -> V_5 . V_117 |= V_126 ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
F_21 ( V_2 ) -> V_135 [ V_89 - V_127 ] = V_102 ;
break;
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
break;
V_105:
default:
F_28 ( V_150 L_1 , V_89 ) ;
#ifndef F_29
V_16 = V_22 ;
#endif
break;
}
return V_16 ;
}
int F_30 ( struct V_1 * V_2 , int V_89 , int V_151 )
{
int V_16 = V_17 ;
switch ( V_89 ) {
case V_92 ... V_93 :
case V_95 ... V_96 :
case V_97 ... V_98 :
case V_100 ... V_101 :
{
struct V_75 * V_76 = F_20 ( V_2 , V_89 ) ;
if ( V_89 % 2 )
F_7 ( V_2 , V_151 , V_76 -> V_84 >> 32 ) ;
else
F_7 ( V_2 , V_151 , V_76 -> V_84 ) ;
break;
}
case V_103 :
if ( ! F_1 ( V_2 , V_104 ) )
goto V_105;
F_7 ( V_2 , V_151 , F_21 ( V_2 ) -> V_106 ) ;
break;
case V_107 :
F_7 ( V_2 , V_151 , V_2 -> V_5 . V_8 -> V_61 ) ;
break;
case V_108 :
F_7 ( V_2 , V_151 , V_2 -> V_5 . V_8 -> V_68 ) ;
break;
case V_109 :
F_7 ( V_2 , V_151 , F_21 ( V_2 ) -> V_110 ) ;
break;
case V_111 :
F_7 ( V_2 , V_151 , F_21 ( V_2 ) -> V_112 [ 0 ] ) ;
break;
case V_113 :
F_7 ( V_2 , V_151 , F_21 ( V_2 ) -> V_112 [ 1 ] ) ;
break;
case V_114 :
case V_115 :
F_7 ( V_2 , V_151 , F_21 ( V_2 ) -> V_112 [ 2 ] ) ;
break;
case V_121 :
case V_122 :
F_7 ( V_2 , V_151 , F_21 ( V_2 ) -> V_112 [ 4 ] ) ;
break;
case V_123 :
F_7 ( V_2 , V_151 , F_21 ( V_2 ) -> V_112 [ 5 ] ) ;
break;
case V_152 :
case V_153 :
F_7 ( V_2 , V_151 , 0 ) ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
F_7 ( V_2 , V_151 ,
F_21 ( V_2 ) -> V_135 [ V_89 - V_127 ] ) ;
break;
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
F_7 ( V_2 , V_151 , 0 ) ;
break;
default:
V_105:
F_28 ( V_150 L_2 , V_89 ) ;
#ifndef F_29
V_16 = V_22 ;
#endif
break;
}
return V_16 ;
}
T_2 F_31 ( struct V_1 * V_2 , unsigned int V_14 )
{
T_2 V_61 = 0 ;
switch ( F_3 ( V_14 ) ) {
case V_154 :
case V_155 :
case V_156 :
case V_157 :
V_61 |= ( V_14 >> 12 ) & 0x4000 ;
V_61 |= ( V_14 >> 17 ) & 0x3c00 ;
break;
case 31 :
V_61 |= ( V_14 << 14 ) & 0x18000 ;
V_61 |= ( V_14 << 8 ) & 0x04000 ;
V_61 |= ( V_14 << 3 ) & 0x03c00 ;
break;
default:
F_28 ( V_150 L_3 , V_14 ) ;
break;
}
V_61 |= ( V_14 >> 16 ) & 0x03ff ;
return V_61 ;
}
T_1 F_32 ( struct V_1 * V_2 , unsigned int V_14 )
{
T_1 V_68 = 0 ;
T_1 V_58 ;
switch ( F_3 ( V_14 ) ) {
case V_154 :
case V_155 :
case V_156 :
case V_157 :
V_58 = F_13 ( V_14 ) ;
if ( V_58 )
V_68 = F_9 ( V_2 , V_58 ) ;
V_68 += ( V_158 ) ( ( V_159 ) V_14 ) ;
break;
case 31 :
V_58 = F_13 ( V_14 ) ;
if ( V_58 )
V_68 = F_9 ( V_2 , V_58 ) ;
V_68 += F_9 ( V_2 , F_12 ( V_14 ) ) ;
break;
default:
F_28 ( V_150 L_3 , V_14 ) ;
break;
}
return V_68 ;
}
