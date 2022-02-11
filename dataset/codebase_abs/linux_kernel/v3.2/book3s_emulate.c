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
* V_15 = 0 ;
V_2 -> V_5 . V_8 -> V_66 = V_59 ;
F_15 ( V_2 ) -> V_67 = V_59 ;
V_61 = V_68 ;
if ( V_62 == - V_64 )
V_61 |= V_69 ;
else if ( V_62 == - V_65 )
V_61 |= V_70 ;
V_2 -> V_5 . V_8 -> V_61 = V_61 ;
F_15 ( V_2 ) -> V_71 = V_61 ;
F_16 ( V_2 ,
V_72 ) ;
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
V_16 = F_17 ( V_13 , V_2 ) ;
return V_16 ;
}
void F_18 ( struct V_1 * V_2 , struct V_73 * V_74 , bool V_75 ,
T_2 V_76 )
{
if ( V_75 ) {
T_2 V_77 = ( V_76 >> 2 ) & 0x7ff ;
V_74 -> V_78 = ( ~ V_77 << 17 ) ;
V_74 -> V_79 = V_76 & 0xfffe0000 ;
V_74 -> V_80 = ( V_76 & 2 ) ? 1 : 0 ;
V_74 -> V_81 = ( V_76 & 1 ) ? 1 : 0 ;
V_74 -> V_82 = ( V_74 -> V_82 & 0xffffffff00000000ULL ) | V_76 ;
} else {
V_74 -> V_83 = V_76 & 0xfffe0000 ;
V_74 -> V_84 = ( V_76 >> 3 ) & 0xf ;
V_74 -> V_85 = V_76 & 3 ;
V_74 -> V_82 = ( V_74 -> V_82 & 0x00000000ffffffffULL ) | ( ( V_86 ) V_76 << 32 ) ;
}
}
static struct V_73 * F_19 ( struct V_1 * V_2 , int V_87 )
{
struct V_88 * V_89 = F_20 ( V_2 ) ;
struct V_73 * V_74 ;
switch ( V_87 ) {
case V_90 ... V_91 :
V_74 = & V_89 -> V_92 [ ( V_87 - V_90 ) / 2 ] ;
break;
case V_93 ... V_94 :
V_74 = & V_89 -> V_92 [ 4 + ( ( V_87 - V_93 ) / 2 ) ] ;
break;
case V_95 ... V_96 :
V_74 = & V_89 -> V_97 [ ( V_87 - V_95 ) / 2 ] ;
break;
case V_98 ... V_99 :
V_74 = & V_89 -> V_97 [ 4 + ( ( V_87 - V_98 ) / 2 ) ] ;
break;
default:
F_21 () ;
}
return V_74 ;
}
int F_22 ( struct V_1 * V_2 , int V_87 , int V_25 )
{
int V_16 = V_17 ;
T_1 V_100 = F_9 ( V_2 , V_25 ) ;
switch ( V_87 ) {
case V_101 :
if ( ! F_1 ( V_2 , V_102 ) )
goto V_103;
F_20 ( V_2 ) -> V_104 = V_100 ;
break;
case V_105 :
V_2 -> V_5 . V_8 -> V_61 = V_100 ;
break;
case V_106 :
V_2 -> V_5 . V_8 -> V_66 = V_100 ;
break;
case V_107 :
F_20 ( V_2 ) -> V_108 = V_100 ;
break;
case V_90 ... V_91 :
case V_93 ... V_94 :
case V_95 ... V_96 :
case V_98 ... V_99 :
{
struct V_73 * V_74 = F_19 ( V_2 , V_87 ) ;
F_18 ( V_2 , V_74 , ! ( V_87 % 2 ) , ( T_2 ) V_100 ) ;
F_23 ( V_2 , 0 , 0 ) ;
F_24 ( V_2 ) ;
break;
}
case V_109 :
F_20 ( V_2 ) -> V_110 [ 0 ] = V_100 ;
break;
case V_111 :
F_20 ( V_2 ) -> V_110 [ 1 ] = V_100 ;
break;
case V_112 :
F_20 ( V_2 ) -> V_110 [ 2 ] = V_100 ;
break;
case V_113 :
F_20 ( V_2 ) -> V_110 [ 2 ] = V_100 ;
switch ( V_2 -> V_5 . V_114 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
if ( V_2 -> V_5 . V_115 & V_116 ) {
} else if ( V_100 & ( 1 << 29 ) ) {
V_2 -> V_5 . V_115 |= V_117 ;
F_25 ( V_2 , V_118 ) ;
} else {
V_2 -> V_5 . V_115 &= ~ V_117 ;
}
break;
}
break;
case V_119 :
case V_120 :
F_20 ( V_2 ) -> V_110 [ 4 ] = V_100 ;
break;
case V_121 :
F_20 ( V_2 ) -> V_110 [ 5 ] = V_100 ;
if ( V_2 -> V_5 . V_31 . V_122 ( V_2 ) &&
( F_26 () & V_123 ) )
V_2 -> V_5 . V_115 |= V_124 ;
break;
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
F_20 ( V_2 ) -> V_133 [ V_87 - V_125 ] = V_100 ;
break;
case V_134 :
case V_135 :
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
break;
V_103:
default:
F_27 ( V_148 L_1 , V_87 ) ;
#ifndef F_28
V_16 = V_22 ;
#endif
break;
}
return V_16 ;
}
int F_29 ( struct V_1 * V_2 , int V_87 , int V_149 )
{
int V_16 = V_17 ;
switch ( V_87 ) {
case V_90 ... V_91 :
case V_93 ... V_94 :
case V_95 ... V_96 :
case V_98 ... V_99 :
{
struct V_73 * V_74 = F_19 ( V_2 , V_87 ) ;
if ( V_87 % 2 )
F_7 ( V_2 , V_149 , V_74 -> V_82 >> 32 ) ;
else
F_7 ( V_2 , V_149 , V_74 -> V_82 ) ;
break;
}
case V_101 :
if ( ! F_1 ( V_2 , V_102 ) )
goto V_103;
F_7 ( V_2 , V_149 , F_20 ( V_2 ) -> V_104 ) ;
break;
case V_105 :
F_7 ( V_2 , V_149 , V_2 -> V_5 . V_8 -> V_61 ) ;
break;
case V_106 :
F_7 ( V_2 , V_149 , V_2 -> V_5 . V_8 -> V_66 ) ;
break;
case V_107 :
F_7 ( V_2 , V_149 , F_20 ( V_2 ) -> V_108 ) ;
break;
case V_109 :
F_7 ( V_2 , V_149 , F_20 ( V_2 ) -> V_110 [ 0 ] ) ;
break;
case V_111 :
F_7 ( V_2 , V_149 , F_20 ( V_2 ) -> V_110 [ 1 ] ) ;
break;
case V_112 :
case V_113 :
F_7 ( V_2 , V_149 , F_20 ( V_2 ) -> V_110 [ 2 ] ) ;
break;
case V_119 :
case V_120 :
F_7 ( V_2 , V_149 , F_20 ( V_2 ) -> V_110 [ 4 ] ) ;
break;
case V_121 :
F_7 ( V_2 , V_149 , F_20 ( V_2 ) -> V_110 [ 5 ] ) ;
break;
case V_150 :
case V_151 :
F_7 ( V_2 , V_149 , 0 ) ;
break;
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
F_7 ( V_2 , V_149 ,
F_20 ( V_2 ) -> V_133 [ V_87 - V_125 ] ) ;
break;
case V_135 :
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
F_7 ( V_2 , V_149 , 0 ) ;
break;
default:
V_103:
F_27 ( V_148 L_2 , V_87 ) ;
#ifndef F_28
V_16 = V_22 ;
#endif
break;
}
return V_16 ;
}
T_2 F_30 ( struct V_1 * V_2 , unsigned int V_14 )
{
T_2 V_61 = 0 ;
switch ( F_3 ( V_14 ) ) {
case V_152 :
case V_153 :
case V_154 :
case V_155 :
V_61 |= ( V_14 >> 12 ) & 0x4000 ;
V_61 |= ( V_14 >> 17 ) & 0x3c00 ;
break;
case 31 :
V_61 |= ( V_14 << 14 ) & 0x18000 ;
V_61 |= ( V_14 << 8 ) & 0x04000 ;
V_61 |= ( V_14 << 3 ) & 0x03c00 ;
break;
default:
F_27 ( V_148 L_3 , V_14 ) ;
break;
}
V_61 |= ( V_14 >> 16 ) & 0x03ff ;
return V_61 ;
}
T_1 F_31 ( struct V_1 * V_2 , unsigned int V_14 )
{
T_1 V_66 = 0 ;
T_1 V_58 ;
switch ( F_3 ( V_14 ) ) {
case V_152 :
case V_153 :
case V_154 :
case V_155 :
V_58 = F_13 ( V_14 ) ;
if ( V_58 )
V_66 = F_9 ( V_2 , V_58 ) ;
V_66 += ( V_156 ) ( ( V_157 ) V_14 ) ;
break;
case 31 :
V_58 = F_13 ( V_14 ) ;
if ( V_58 )
V_66 = F_9 ( V_2 , V_58 ) ;
V_66 += F_9 ( V_2 , F_12 ( V_14 ) ) ;
break;
default:
F_27 ( V_148 L_3 , V_14 ) ;
break;
}
return V_66 ;
}
