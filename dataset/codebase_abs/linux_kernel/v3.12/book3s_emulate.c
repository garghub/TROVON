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
#ifdef F_14
case V_48 :
{
T_1 V_49 = F_12 ( V_2 , 3 ) ;
int V_50 ;
if ( ( V_2 -> V_5 . V_8 -> V_9 & V_10 ) ||
! V_2 -> V_5 . V_6 ) {
V_16 = V_26 ;
break;
}
if ( F_15 ( V_2 , V_49 ) == V_17 )
break;
V_13 -> V_51 . V_52 = V_49 ;
for ( V_50 = 0 ; V_50 < 9 ; ++ V_50 ) {
T_1 V_53 = F_12 ( V_2 , 4 + V_50 ) ;
V_13 -> V_51 . args [ V_50 ] = V_53 ;
}
V_13 -> V_54 = V_55 ;
V_2 -> V_5 . V_56 = 1 ;
V_16 = V_57 ;
break;
}
#endif
case V_58 :
break;
case V_59 :
if ( ! V_2 -> V_5 . V_36 . V_60 )
return V_26 ;
V_2 -> V_5 . V_36 . V_60 ( V_2 ,
F_12 ( V_2 , V_19 ) ,
F_12 ( V_2 , V_21 ) ) ;
break;
case V_61 :
if ( ! V_2 -> V_5 . V_36 . V_62 )
return V_26 ;
V_2 -> V_5 . V_36 . V_62 ( V_2 ,
F_12 ( V_2 , V_21 ) ) ;
break;
case V_63 :
if ( ! V_2 -> V_5 . V_36 . V_64 )
return V_26 ;
V_2 -> V_5 . V_36 . V_64 ( V_2 ) ;
break;
case V_65 :
if ( ! V_2 -> V_5 . V_36 . V_66 ) {
V_16 = V_26 ;
} else {
T_1 V_67 , V_68 ;
V_68 = F_12 ( V_2 , V_21 ) ;
V_67 = V_2 -> V_5 . V_36 . V_66 ( V_2 , V_68 ) ;
F_11 ( V_2 , V_18 , V_67 ) ;
}
break;
case V_69 :
if ( ! V_2 -> V_5 . V_36 . V_70 ) {
V_16 = V_26 ;
} else {
T_1 V_67 , V_68 ;
V_68 = F_12 ( V_2 , V_21 ) ;
V_67 = V_2 -> V_5 . V_36 . V_70 ( V_2 , V_68 ) ;
F_11 ( V_2 , V_18 , V_67 ) ;
}
break;
case V_71 :
break;
case V_72 :
{
T_1 V_68 = F_12 ( V_2 , V_21 ) ;
T_1 V_73 = 0 ;
T_1 V_46 , V_74 ;
T_2 V_75 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_76 ;
int V_77 ;
if ( V_20 )
V_73 = F_12 ( V_2 , V_20 ) ;
V_46 = ( V_73 + V_68 ) & ~ 31ULL ;
if ( ! ( V_2 -> V_5 . V_8 -> V_9 & V_78 ) )
V_46 &= 0xffffffff ;
V_74 = V_46 ;
V_77 = F_16 ( V_2 , & V_46 , 32 , V_75 , true ) ;
if ( ( V_77 == - V_79 ) || ( V_77 == - V_80 ) ) {
struct V_81 * V_82 ;
V_82 = F_17 ( V_2 ) ;
* V_15 = 0 ;
V_2 -> V_5 . V_8 -> V_83 = V_74 ;
V_82 -> V_84 = V_74 ;
V_76 = V_85 ;
if ( V_77 == - V_79 )
V_76 |= V_86 ;
else if ( V_77 == - V_80 )
V_76 |= V_87 ;
V_2 -> V_5 . V_8 -> V_76 = V_76 ;
V_82 -> V_88 = V_76 ;
F_18 ( V_82 ) ;
F_19 ( V_2 ,
V_89 ) ;
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
V_16 = F_20 ( V_13 , V_2 ) ;
return V_16 ;
}
void F_21 ( struct V_1 * V_2 , struct V_90 * V_91 , bool V_92 ,
T_2 V_93 )
{
if ( V_92 ) {
T_2 V_94 = ( V_93 >> 2 ) & 0x7ff ;
V_91 -> V_95 = ( ~ V_94 << 17 ) ;
V_91 -> V_96 = V_93 & 0xfffe0000 ;
V_91 -> V_97 = ( V_93 & 2 ) ? 1 : 0 ;
V_91 -> V_98 = ( V_93 & 1 ) ? 1 : 0 ;
V_91 -> V_99 = ( V_91 -> V_99 & 0xffffffff00000000ULL ) | V_93 ;
} else {
V_91 -> V_100 = V_93 & 0xfffe0000 ;
V_91 -> V_101 = ( V_93 >> 3 ) & 0xf ;
V_91 -> V_102 = V_93 & 3 ;
V_91 -> V_99 = ( V_91 -> V_99 & 0x00000000ffffffffULL ) | ( ( V_103 ) V_93 << 32 ) ;
}
}
static struct V_90 * F_22 ( struct V_1 * V_2 , int V_104 )
{
struct V_105 * V_106 = F_23 ( V_2 ) ;
struct V_90 * V_91 ;
switch ( V_104 ) {
case V_107 ... V_108 :
V_91 = & V_106 -> V_109 [ ( V_104 - V_107 ) / 2 ] ;
break;
case V_110 ... V_111 :
V_91 = & V_106 -> V_109 [ 4 + ( ( V_104 - V_110 ) / 2 ) ] ;
break;
case V_112 ... V_113 :
V_91 = & V_106 -> V_114 [ ( V_104 - V_112 ) / 2 ] ;
break;
case V_115 ... V_116 :
V_91 = & V_106 -> V_114 [ 4 + ( ( V_104 - V_115 ) / 2 ) ] ;
break;
default:
F_24 () ;
}
return V_91 ;
}
int F_25 ( struct V_1 * V_2 , int V_104 , T_1 V_117 )
{
int V_16 = V_17 ;
switch ( V_104 ) {
case V_118 :
if ( ! F_1 ( V_2 , V_119 ) )
goto V_120;
F_23 ( V_2 ) -> V_121 = V_117 ;
break;
case V_122 :
V_2 -> V_5 . V_8 -> V_76 = V_117 ;
break;
case V_123 :
V_2 -> V_5 . V_8 -> V_83 = V_117 ;
break;
case V_124 :
F_23 ( V_2 ) -> V_125 = V_117 ;
break;
case V_107 ... V_108 :
case V_110 ... V_111 :
case V_112 ... V_113 :
case V_115 ... V_116 :
{
struct V_90 * V_91 = F_22 ( V_2 , V_104 ) ;
F_21 ( V_2 , V_91 , ! ( V_104 % 2 ) , ( T_2 ) V_117 ) ;
F_26 ( V_2 , 0 , 0 ) ;
F_27 ( V_2 ) ;
break;
}
case V_126 :
F_23 ( V_2 ) -> V_127 [ 0 ] = V_117 ;
break;
case V_128 :
F_23 ( V_2 ) -> V_127 [ 1 ] = V_117 ;
break;
case V_129 :
F_23 ( V_2 ) -> V_127 [ 2 ] = V_117 ;
break;
case V_130 :
F_23 ( V_2 ) -> V_127 [ 2 ] = V_117 ;
switch ( V_2 -> V_5 . V_131 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
if ( V_2 -> V_5 . V_132 & V_133 ) {
} else if ( V_117 & ( 1 << 29 ) ) {
V_2 -> V_5 . V_132 |= V_134 ;
F_28 ( V_2 , V_135 ) ;
} else {
V_2 -> V_5 . V_132 &= ~ V_134 ;
}
break;
}
break;
case V_136 :
case V_137 :
F_23 ( V_2 ) -> V_127 [ 4 ] = V_117 ;
break;
case V_138 :
F_23 ( V_2 ) -> V_127 [ 5 ] = V_117 ;
if ( V_2 -> V_5 . V_36 . V_139 ( V_2 ) &&
( F_29 () & V_140 ) )
V_2 -> V_5 . V_132 |= V_141 ;
break;
case V_142 :
F_23 ( V_2 ) -> V_143 = V_117 - F_30 () ;
break;
case V_144 :
F_23 ( V_2 ) -> V_145 = V_117 - F_30 () ;
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
F_23 ( V_2 ) -> V_154 [ V_104 - V_146 ] = V_117 ;
break;
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
break;
V_120:
default:
F_31 ( V_172 L_1 , V_104 ) ;
#ifndef F_32
V_16 = V_26 ;
#endif
break;
}
return V_16 ;
}
int F_33 ( struct V_1 * V_2 , int V_104 , T_1 * V_117 )
{
int V_16 = V_17 ;
switch ( V_104 ) {
case V_107 ... V_108 :
case V_110 ... V_111 :
case V_112 ... V_113 :
case V_115 ... V_116 :
{
struct V_90 * V_91 = F_22 ( V_2 , V_104 ) ;
if ( V_104 % 2 )
* V_117 = V_91 -> V_99 >> 32 ;
else
* V_117 = V_91 -> V_99 ;
break;
}
case V_118 :
if ( ! F_1 ( V_2 , V_119 ) )
goto V_120;
* V_117 = F_23 ( V_2 ) -> V_121 ;
break;
case V_122 :
* V_117 = V_2 -> V_5 . V_8 -> V_76 ;
break;
case V_123 :
* V_117 = V_2 -> V_5 . V_8 -> V_83 ;
break;
case V_124 :
* V_117 = F_23 ( V_2 ) -> V_125 ;
break;
case V_126 :
* V_117 = F_23 ( V_2 ) -> V_127 [ 0 ] ;
break;
case V_128 :
* V_117 = F_23 ( V_2 ) -> V_127 [ 1 ] ;
break;
case V_129 :
case V_130 :
* V_117 = F_23 ( V_2 ) -> V_127 [ 2 ] ;
break;
case V_136 :
case V_137 :
* V_117 = F_23 ( V_2 ) -> V_127 [ 4 ] ;
break;
case V_138 :
* V_117 = F_23 ( V_2 ) -> V_127 [ 5 ] ;
break;
case V_173 :
case V_162 :
* V_117 = 0 ;
break;
case V_142 :
* V_117 = F_30 () + F_23 ( V_2 ) -> V_143 ;
break;
case V_144 :
* V_117 = F_30 () + F_23 ( V_2 ) -> V_143 ;
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
* V_117 = F_23 ( V_2 ) -> V_154 [ V_104 - V_146 ] ;
break;
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
* V_117 = 0 ;
break;
default:
V_120:
F_31 ( V_172 L_2 , V_104 ) ;
#ifndef F_32
V_16 = V_26 ;
#endif
break;
}
return V_16 ;
}
T_2 F_34 ( struct V_1 * V_2 , unsigned int V_14 )
{
T_2 V_76 = 0 ;
switch ( F_7 ( V_14 ) ) {
case V_174 :
case V_175 :
case V_176 :
case V_177 :
V_76 |= ( V_14 >> 12 ) & 0x4000 ;
V_76 |= ( V_14 >> 17 ) & 0x3c00 ;
break;
case 31 :
V_76 |= ( V_14 << 14 ) & 0x18000 ;
V_76 |= ( V_14 << 8 ) & 0x04000 ;
V_76 |= ( V_14 << 3 ) & 0x03c00 ;
break;
default:
F_31 ( V_172 L_3 , V_14 ) ;
break;
}
V_76 |= ( V_14 >> 16 ) & 0x03ff ;
return V_76 ;
}
T_1 F_35 ( struct V_1 * V_2 , unsigned int V_14 )
{
T_1 V_83 = 0 ;
T_1 V_20 = F_5 ( V_14 ) ;
T_1 V_21 = F_6 ( V_14 ) ;
switch ( F_7 ( V_14 ) ) {
case V_174 :
case V_175 :
case V_176 :
case V_177 :
if ( V_20 )
V_83 = F_12 ( V_2 , V_20 ) ;
V_83 += ( V_178 ) ( ( V_179 ) V_14 ) ;
break;
case 31 :
if ( V_20 )
V_83 = F_12 ( V_2 , V_20 ) ;
V_83 += F_12 ( V_2 , V_21 ) ;
break;
default:
F_31 ( V_172 L_3 , V_14 ) ;
break;
}
return V_83 ;
}
