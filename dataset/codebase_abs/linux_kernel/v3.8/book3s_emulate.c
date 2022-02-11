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
int V_18 = F_3 ( V_14 ) ;
int V_19 = F_4 ( V_14 ) ;
int V_20 = F_5 ( V_14 ) ;
int V_21 = F_6 ( V_14 ) ;
switch ( F_7 ( V_14 ) ) {
case 19 :
switch ( F_8 ( V_14 ) ) {
case V_22 :
case V_23 :
F_9 ( V_2 , V_2 -> V_5 . V_8 -> V_24 ) ;
F_10 ( V_2 , V_2 -> V_5 . V_8 -> V_25 ) ;
* V_15 = 0 ;
break;
default:
V_16 = V_26 ;
break;
}
break;
case 31 :
switch ( F_8 ( V_14 ) ) {
case V_27 :
F_11 ( V_2 , V_18 , V_2 -> V_5 . V_8 -> V_9 ) ;
break;
case V_28 :
{
T_1 V_29 = F_12 ( V_2 , V_19 ) ;
if ( V_14 & 0x10000 ) {
T_1 V_30 = V_2 -> V_5 . V_8 -> V_9 ;
V_30 &= ~ ( V_31 | V_32 ) ;
V_30 |= V_29 & ( V_31 | V_32 ) ;
V_2 -> V_5 . V_8 -> V_9 = V_30 ;
} else
F_10 ( V_2 , V_29 ) ;
break;
}
case V_33 :
F_10 ( V_2 , F_12 ( V_2 , V_19 ) ) ;
break;
case V_34 :
{
int V_35 ;
V_35 = F_13 ( V_14 , 12 + 32 , 15 + 32 ) ;
if ( V_2 -> V_5 . V_36 . V_37 ) {
T_2 V_38 ;
V_38 = V_2 -> V_5 . V_36 . V_37 ( V_2 , V_35 ) ;
F_11 ( V_2 , V_18 , V_38 ) ;
}
break;
}
case V_39 :
{
int V_35 ;
V_35 = ( F_12 ( V_2 , V_21 ) >> 28 ) & 0xf ;
if ( V_2 -> V_5 . V_36 . V_37 ) {
T_2 V_38 ;
V_38 = V_2 -> V_5 . V_36 . V_37 ( V_2 , V_35 ) ;
F_11 ( V_2 , V_18 , V_38 ) ;
}
break;
}
case V_40 :
V_2 -> V_5 . V_36 . V_41 ( V_2 ,
( V_14 >> 16 ) & 0xf ,
F_12 ( V_2 , V_19 ) ) ;
break;
case V_42 :
V_2 -> V_5 . V_36 . V_41 ( V_2 ,
( F_12 ( V_2 , V_21 ) >> 28 ) & 0xf ,
F_12 ( V_2 , V_19 ) ) ;
break;
case V_43 :
case V_44 :
{
bool V_45 = ( V_14 & 0x00200000 ) ? true : false ;
T_1 V_46 = F_12 ( V_2 , V_21 ) ;
V_2 -> V_5 . V_36 . V_47 ( V_2 , V_46 , V_45 ) ;
break;
}
case V_48 :
break;
case V_49 :
if ( ! V_2 -> V_5 . V_36 . V_50 )
return V_26 ;
V_2 -> V_5 . V_36 . V_50 ( V_2 ,
F_12 ( V_2 , V_19 ) ,
F_12 ( V_2 , V_21 ) ) ;
break;
case V_51 :
if ( ! V_2 -> V_5 . V_36 . V_52 )
return V_26 ;
V_2 -> V_5 . V_36 . V_52 ( V_2 ,
F_12 ( V_2 , V_21 ) ) ;
break;
case V_53 :
if ( ! V_2 -> V_5 . V_36 . V_54 )
return V_26 ;
V_2 -> V_5 . V_36 . V_54 ( V_2 ) ;
break;
case V_55 :
if ( ! V_2 -> V_5 . V_36 . V_56 ) {
V_16 = V_26 ;
} else {
T_1 V_57 , V_58 ;
V_58 = F_12 ( V_2 , V_21 ) ;
V_57 = V_2 -> V_5 . V_36 . V_56 ( V_2 , V_58 ) ;
F_11 ( V_2 , V_18 , V_57 ) ;
}
break;
case V_59 :
if ( ! V_2 -> V_5 . V_36 . V_60 ) {
V_16 = V_26 ;
} else {
T_1 V_57 , V_58 ;
V_58 = F_12 ( V_2 , V_21 ) ;
V_57 = V_2 -> V_5 . V_36 . V_60 ( V_2 , V_58 ) ;
F_11 ( V_2 , V_18 , V_57 ) ;
}
break;
case V_61 :
break;
case V_62 :
{
T_1 V_58 = F_12 ( V_2 , V_21 ) ;
T_1 V_63 = 0 ;
T_1 V_46 , V_64 ;
T_2 V_65 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_66 ;
int V_67 ;
if ( V_20 )
V_63 = F_12 ( V_2 , V_20 ) ;
V_46 = ( V_63 + V_58 ) & ~ 31ULL ;
if ( ! ( V_2 -> V_5 . V_8 -> V_9 & V_68 ) )
V_46 &= 0xffffffff ;
V_64 = V_46 ;
V_67 = F_14 ( V_2 , & V_46 , 32 , V_65 , true ) ;
if ( ( V_67 == - V_69 ) || ( V_67 == - V_70 ) ) {
struct V_71 * V_72 ;
V_72 = F_15 ( V_2 ) ;
* V_15 = 0 ;
V_2 -> V_5 . V_8 -> V_73 = V_64 ;
V_72 -> V_74 = V_64 ;
V_66 = V_75 ;
if ( V_67 == - V_69 )
V_66 |= V_76 ;
else if ( V_67 == - V_70 )
V_66 |= V_77 ;
V_2 -> V_5 . V_8 -> V_66 = V_66 ;
V_72 -> V_78 = V_66 ;
F_16 ( V_72 ) ;
F_17 ( V_2 ,
V_79 ) ;
}
break;
}
default:
V_16 = V_26 ;
}
break;
default:
V_16 = V_26 ;
}
if ( V_16 == V_26 )
V_16 = F_18 ( V_13 , V_2 ) ;
return V_16 ;
}
void F_19 ( struct V_1 * V_2 , struct V_80 * V_81 , bool V_82 ,
T_2 V_83 )
{
if ( V_82 ) {
T_2 V_84 = ( V_83 >> 2 ) & 0x7ff ;
V_81 -> V_85 = ( ~ V_84 << 17 ) ;
V_81 -> V_86 = V_83 & 0xfffe0000 ;
V_81 -> V_87 = ( V_83 & 2 ) ? 1 : 0 ;
V_81 -> V_88 = ( V_83 & 1 ) ? 1 : 0 ;
V_81 -> V_89 = ( V_81 -> V_89 & 0xffffffff00000000ULL ) | V_83 ;
} else {
V_81 -> V_90 = V_83 & 0xfffe0000 ;
V_81 -> V_91 = ( V_83 >> 3 ) & 0xf ;
V_81 -> V_92 = V_83 & 3 ;
V_81 -> V_89 = ( V_81 -> V_89 & 0x00000000ffffffffULL ) | ( ( V_93 ) V_83 << 32 ) ;
}
}
static struct V_80 * F_20 ( struct V_1 * V_2 , int V_94 )
{
struct V_95 * V_96 = F_21 ( V_2 ) ;
struct V_80 * V_81 ;
switch ( V_94 ) {
case V_97 ... V_98 :
V_81 = & V_96 -> V_99 [ ( V_94 - V_97 ) / 2 ] ;
break;
case V_100 ... V_101 :
V_81 = & V_96 -> V_99 [ 4 + ( ( V_94 - V_100 ) / 2 ) ] ;
break;
case V_102 ... V_103 :
V_81 = & V_96 -> V_104 [ ( V_94 - V_102 ) / 2 ] ;
break;
case V_105 ... V_106 :
V_81 = & V_96 -> V_104 [ 4 + ( ( V_94 - V_105 ) / 2 ) ] ;
break;
default:
F_22 () ;
}
return V_81 ;
}
int F_23 ( struct V_1 * V_2 , int V_94 , T_1 V_107 )
{
int V_16 = V_17 ;
switch ( V_94 ) {
case V_108 :
if ( ! F_1 ( V_2 , V_109 ) )
goto V_110;
F_21 ( V_2 ) -> V_111 = V_107 ;
break;
case V_112 :
V_2 -> V_5 . V_8 -> V_66 = V_107 ;
break;
case V_113 :
V_2 -> V_5 . V_8 -> V_73 = V_107 ;
break;
case V_114 :
F_21 ( V_2 ) -> V_115 = V_107 ;
break;
case V_97 ... V_98 :
case V_100 ... V_101 :
case V_102 ... V_103 :
case V_105 ... V_106 :
{
struct V_80 * V_81 = F_20 ( V_2 , V_94 ) ;
F_19 ( V_2 , V_81 , ! ( V_94 % 2 ) , ( T_2 ) V_107 ) ;
F_24 ( V_2 , 0 , 0 ) ;
F_25 ( V_2 ) ;
break;
}
case V_116 :
F_21 ( V_2 ) -> V_117 [ 0 ] = V_107 ;
break;
case V_118 :
F_21 ( V_2 ) -> V_117 [ 1 ] = V_107 ;
break;
case V_119 :
F_21 ( V_2 ) -> V_117 [ 2 ] = V_107 ;
break;
case V_120 :
F_21 ( V_2 ) -> V_117 [ 2 ] = V_107 ;
switch ( V_2 -> V_5 . V_121 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
if ( V_2 -> V_5 . V_122 & V_123 ) {
} else if ( V_107 & ( 1 << 29 ) ) {
V_2 -> V_5 . V_122 |= V_124 ;
F_26 ( V_2 , V_125 ) ;
} else {
V_2 -> V_5 . V_122 &= ~ V_124 ;
}
break;
}
break;
case V_126 :
case V_127 :
F_21 ( V_2 ) -> V_117 [ 4 ] = V_107 ;
break;
case V_128 :
F_21 ( V_2 ) -> V_117 [ 5 ] = V_107 ;
if ( V_2 -> V_5 . V_36 . V_129 ( V_2 ) &&
( F_27 () & V_130 ) )
V_2 -> V_5 . V_122 |= V_131 ;
break;
case V_132 :
F_21 ( V_2 ) -> V_133 = V_107 - F_28 () ;
break;
case V_134 :
F_21 ( V_2 ) -> V_135 = V_107 - F_28 () ;
break;
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
F_21 ( V_2 ) -> V_144 [ V_94 - V_136 ] = V_107 ;
break;
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
break;
V_110:
default:
F_29 ( V_160 L_1 , V_94 ) ;
#ifndef F_30
V_16 = V_26 ;
#endif
break;
}
return V_16 ;
}
int F_31 ( struct V_1 * V_2 , int V_94 , T_1 * V_107 )
{
int V_16 = V_17 ;
switch ( V_94 ) {
case V_97 ... V_98 :
case V_100 ... V_101 :
case V_102 ... V_103 :
case V_105 ... V_106 :
{
struct V_80 * V_81 = F_20 ( V_2 , V_94 ) ;
if ( V_94 % 2 )
* V_107 = V_81 -> V_89 >> 32 ;
else
* V_107 = V_81 -> V_89 ;
break;
}
case V_108 :
if ( ! F_1 ( V_2 , V_109 ) )
goto V_110;
* V_107 = F_21 ( V_2 ) -> V_111 ;
break;
case V_112 :
* V_107 = V_2 -> V_5 . V_8 -> V_66 ;
break;
case V_113 :
* V_107 = V_2 -> V_5 . V_8 -> V_73 ;
break;
case V_114 :
* V_107 = F_21 ( V_2 ) -> V_115 ;
break;
case V_116 :
* V_107 = F_21 ( V_2 ) -> V_117 [ 0 ] ;
break;
case V_118 :
* V_107 = F_21 ( V_2 ) -> V_117 [ 1 ] ;
break;
case V_119 :
case V_120 :
* V_107 = F_21 ( V_2 ) -> V_117 [ 2 ] ;
break;
case V_126 :
case V_127 :
* V_107 = F_21 ( V_2 ) -> V_117 [ 4 ] ;
break;
case V_128 :
* V_107 = F_21 ( V_2 ) -> V_117 [ 5 ] ;
break;
case V_161 :
case V_152 :
* V_107 = 0 ;
break;
case V_132 :
* V_107 = F_28 () + F_21 ( V_2 ) -> V_133 ;
break;
case V_134 :
* V_107 = F_28 () + F_21 ( V_2 ) -> V_133 ;
break;
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
* V_107 = F_21 ( V_2 ) -> V_144 [ V_94 - V_136 ] ;
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
* V_107 = 0 ;
break;
default:
V_110:
F_29 ( V_160 L_2 , V_94 ) ;
#ifndef F_30
V_16 = V_26 ;
#endif
break;
}
return V_16 ;
}
T_2 F_32 ( struct V_1 * V_2 , unsigned int V_14 )
{
T_2 V_66 = 0 ;
switch ( F_7 ( V_14 ) ) {
case V_162 :
case V_163 :
case V_164 :
case V_165 :
V_66 |= ( V_14 >> 12 ) & 0x4000 ;
V_66 |= ( V_14 >> 17 ) & 0x3c00 ;
break;
case 31 :
V_66 |= ( V_14 << 14 ) & 0x18000 ;
V_66 |= ( V_14 << 8 ) & 0x04000 ;
V_66 |= ( V_14 << 3 ) & 0x03c00 ;
break;
default:
F_29 ( V_160 L_3 , V_14 ) ;
break;
}
V_66 |= ( V_14 >> 16 ) & 0x03ff ;
return V_66 ;
}
T_1 F_33 ( struct V_1 * V_2 , unsigned int V_14 )
{
T_1 V_73 = 0 ;
T_1 V_20 = F_5 ( V_14 ) ;
T_1 V_21 = F_6 ( V_14 ) ;
switch ( F_7 ( V_14 ) ) {
case V_162 :
case V_163 :
case V_164 :
case V_165 :
if ( V_20 )
V_73 = F_12 ( V_2 , V_20 ) ;
V_73 += ( V_166 ) ( ( V_167 ) V_14 ) ;
break;
case 31 :
if ( V_20 )
V_73 = F_12 ( V_2 , V_20 ) ;
V_73 += F_12 ( V_2 , V_21 ) ;
break;
default:
F_29 ( V_160 L_3 , V_14 ) ;
break;
}
return V_73 ;
}
