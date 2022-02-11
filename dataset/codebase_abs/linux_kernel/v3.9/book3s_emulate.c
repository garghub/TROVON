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
V_16 = V_54 ;
break;
}
#endif
case V_55 :
break;
case V_56 :
if ( ! V_2 -> V_5 . V_36 . V_57 )
return V_26 ;
V_2 -> V_5 . V_36 . V_57 ( V_2 ,
F_12 ( V_2 , V_19 ) ,
F_12 ( V_2 , V_21 ) ) ;
break;
case V_58 :
if ( ! V_2 -> V_5 . V_36 . V_59 )
return V_26 ;
V_2 -> V_5 . V_36 . V_59 ( V_2 ,
F_12 ( V_2 , V_21 ) ) ;
break;
case V_60 :
if ( ! V_2 -> V_5 . V_36 . V_61 )
return V_26 ;
V_2 -> V_5 . V_36 . V_61 ( V_2 ) ;
break;
case V_62 :
if ( ! V_2 -> V_5 . V_36 . V_63 ) {
V_16 = V_26 ;
} else {
T_1 V_64 , V_65 ;
V_65 = F_12 ( V_2 , V_21 ) ;
V_64 = V_2 -> V_5 . V_36 . V_63 ( V_2 , V_65 ) ;
F_11 ( V_2 , V_18 , V_64 ) ;
}
break;
case V_66 :
if ( ! V_2 -> V_5 . V_36 . V_67 ) {
V_16 = V_26 ;
} else {
T_1 V_64 , V_65 ;
V_65 = F_12 ( V_2 , V_21 ) ;
V_64 = V_2 -> V_5 . V_36 . V_67 ( V_2 , V_65 ) ;
F_11 ( V_2 , V_18 , V_64 ) ;
}
break;
case V_68 :
break;
case V_69 :
{
T_1 V_65 = F_12 ( V_2 , V_21 ) ;
T_1 V_70 = 0 ;
T_1 V_46 , V_71 ;
T_2 V_72 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_73 ;
int V_74 ;
if ( V_20 )
V_70 = F_12 ( V_2 , V_20 ) ;
V_46 = ( V_70 + V_65 ) & ~ 31ULL ;
if ( ! ( V_2 -> V_5 . V_8 -> V_9 & V_75 ) )
V_46 &= 0xffffffff ;
V_71 = V_46 ;
V_74 = F_16 ( V_2 , & V_46 , 32 , V_72 , true ) ;
if ( ( V_74 == - V_76 ) || ( V_74 == - V_77 ) ) {
struct V_78 * V_79 ;
V_79 = F_17 ( V_2 ) ;
* V_15 = 0 ;
V_2 -> V_5 . V_8 -> V_80 = V_71 ;
V_79 -> V_81 = V_71 ;
V_73 = V_82 ;
if ( V_74 == - V_76 )
V_73 |= V_83 ;
else if ( V_74 == - V_77 )
V_73 |= V_84 ;
V_2 -> V_5 . V_8 -> V_73 = V_73 ;
V_79 -> V_85 = V_73 ;
F_18 ( V_79 ) ;
F_19 ( V_2 ,
V_86 ) ;
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
void F_21 ( struct V_1 * V_2 , struct V_87 * V_88 , bool V_89 ,
T_2 V_90 )
{
if ( V_89 ) {
T_2 V_91 = ( V_90 >> 2 ) & 0x7ff ;
V_88 -> V_92 = ( ~ V_91 << 17 ) ;
V_88 -> V_93 = V_90 & 0xfffe0000 ;
V_88 -> V_94 = ( V_90 & 2 ) ? 1 : 0 ;
V_88 -> V_95 = ( V_90 & 1 ) ? 1 : 0 ;
V_88 -> V_96 = ( V_88 -> V_96 & 0xffffffff00000000ULL ) | V_90 ;
} else {
V_88 -> V_97 = V_90 & 0xfffe0000 ;
V_88 -> V_98 = ( V_90 >> 3 ) & 0xf ;
V_88 -> V_99 = V_90 & 3 ;
V_88 -> V_96 = ( V_88 -> V_96 & 0x00000000ffffffffULL ) | ( ( V_100 ) V_90 << 32 ) ;
}
}
static struct V_87 * F_22 ( struct V_1 * V_2 , int V_101 )
{
struct V_102 * V_103 = F_23 ( V_2 ) ;
struct V_87 * V_88 ;
switch ( V_101 ) {
case V_104 ... V_105 :
V_88 = & V_103 -> V_106 [ ( V_101 - V_104 ) / 2 ] ;
break;
case V_107 ... V_108 :
V_88 = & V_103 -> V_106 [ 4 + ( ( V_101 - V_107 ) / 2 ) ] ;
break;
case V_109 ... V_110 :
V_88 = & V_103 -> V_111 [ ( V_101 - V_109 ) / 2 ] ;
break;
case V_112 ... V_113 :
V_88 = & V_103 -> V_111 [ 4 + ( ( V_101 - V_112 ) / 2 ) ] ;
break;
default:
F_24 () ;
}
return V_88 ;
}
int F_25 ( struct V_1 * V_2 , int V_101 , T_1 V_114 )
{
int V_16 = V_17 ;
switch ( V_101 ) {
case V_115 :
if ( ! F_1 ( V_2 , V_116 ) )
goto V_117;
F_23 ( V_2 ) -> V_118 = V_114 ;
break;
case V_119 :
V_2 -> V_5 . V_8 -> V_73 = V_114 ;
break;
case V_120 :
V_2 -> V_5 . V_8 -> V_80 = V_114 ;
break;
case V_121 :
F_23 ( V_2 ) -> V_122 = V_114 ;
break;
case V_104 ... V_105 :
case V_107 ... V_108 :
case V_109 ... V_110 :
case V_112 ... V_113 :
{
struct V_87 * V_88 = F_22 ( V_2 , V_101 ) ;
F_21 ( V_2 , V_88 , ! ( V_101 % 2 ) , ( T_2 ) V_114 ) ;
F_26 ( V_2 , 0 , 0 ) ;
F_27 ( V_2 ) ;
break;
}
case V_123 :
F_23 ( V_2 ) -> V_124 [ 0 ] = V_114 ;
break;
case V_125 :
F_23 ( V_2 ) -> V_124 [ 1 ] = V_114 ;
break;
case V_126 :
F_23 ( V_2 ) -> V_124 [ 2 ] = V_114 ;
break;
case V_127 :
F_23 ( V_2 ) -> V_124 [ 2 ] = V_114 ;
switch ( V_2 -> V_5 . V_128 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
if ( V_2 -> V_5 . V_129 & V_130 ) {
} else if ( V_114 & ( 1 << 29 ) ) {
V_2 -> V_5 . V_129 |= V_131 ;
F_28 ( V_2 , V_132 ) ;
} else {
V_2 -> V_5 . V_129 &= ~ V_131 ;
}
break;
}
break;
case V_133 :
case V_134 :
F_23 ( V_2 ) -> V_124 [ 4 ] = V_114 ;
break;
case V_135 :
F_23 ( V_2 ) -> V_124 [ 5 ] = V_114 ;
if ( V_2 -> V_5 . V_36 . V_136 ( V_2 ) &&
( F_29 () & V_137 ) )
V_2 -> V_5 . V_129 |= V_138 ;
break;
case V_139 :
F_23 ( V_2 ) -> V_140 = V_114 - F_30 () ;
break;
case V_141 :
F_23 ( V_2 ) -> V_142 = V_114 - F_30 () ;
break;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
F_23 ( V_2 ) -> V_151 [ V_101 - V_143 ] = V_114 ;
break;
case V_152 :
case V_153 :
case V_154 :
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
break;
V_117:
default:
F_31 ( V_168 L_1 , V_101 ) ;
#ifndef F_32
V_16 = V_26 ;
#endif
break;
}
return V_16 ;
}
int F_33 ( struct V_1 * V_2 , int V_101 , T_1 * V_114 )
{
int V_16 = V_17 ;
switch ( V_101 ) {
case V_104 ... V_105 :
case V_107 ... V_108 :
case V_109 ... V_110 :
case V_112 ... V_113 :
{
struct V_87 * V_88 = F_22 ( V_2 , V_101 ) ;
if ( V_101 % 2 )
* V_114 = V_88 -> V_96 >> 32 ;
else
* V_114 = V_88 -> V_96 ;
break;
}
case V_115 :
if ( ! F_1 ( V_2 , V_116 ) )
goto V_117;
* V_114 = F_23 ( V_2 ) -> V_118 ;
break;
case V_119 :
* V_114 = V_2 -> V_5 . V_8 -> V_73 ;
break;
case V_120 :
* V_114 = V_2 -> V_5 . V_8 -> V_80 ;
break;
case V_121 :
* V_114 = F_23 ( V_2 ) -> V_122 ;
break;
case V_123 :
* V_114 = F_23 ( V_2 ) -> V_124 [ 0 ] ;
break;
case V_125 :
* V_114 = F_23 ( V_2 ) -> V_124 [ 1 ] ;
break;
case V_126 :
case V_127 :
* V_114 = F_23 ( V_2 ) -> V_124 [ 2 ] ;
break;
case V_133 :
case V_134 :
* V_114 = F_23 ( V_2 ) -> V_124 [ 4 ] ;
break;
case V_135 :
* V_114 = F_23 ( V_2 ) -> V_124 [ 5 ] ;
break;
case V_169 :
case V_159 :
* V_114 = 0 ;
break;
case V_139 :
* V_114 = F_30 () + F_23 ( V_2 ) -> V_140 ;
break;
case V_141 :
* V_114 = F_30 () + F_23 ( V_2 ) -> V_140 ;
break;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
* V_114 = F_23 ( V_2 ) -> V_151 [ V_101 - V_143 ] ;
break;
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
* V_114 = 0 ;
break;
default:
V_117:
F_31 ( V_168 L_2 , V_101 ) ;
#ifndef F_32
V_16 = V_26 ;
#endif
break;
}
return V_16 ;
}
T_2 F_34 ( struct V_1 * V_2 , unsigned int V_14 )
{
T_2 V_73 = 0 ;
switch ( F_7 ( V_14 ) ) {
case V_170 :
case V_171 :
case V_172 :
case V_173 :
V_73 |= ( V_14 >> 12 ) & 0x4000 ;
V_73 |= ( V_14 >> 17 ) & 0x3c00 ;
break;
case 31 :
V_73 |= ( V_14 << 14 ) & 0x18000 ;
V_73 |= ( V_14 << 8 ) & 0x04000 ;
V_73 |= ( V_14 << 3 ) & 0x03c00 ;
break;
default:
F_31 ( V_168 L_3 , V_14 ) ;
break;
}
V_73 |= ( V_14 >> 16 ) & 0x03ff ;
return V_73 ;
}
T_1 F_35 ( struct V_1 * V_2 , unsigned int V_14 )
{
T_1 V_80 = 0 ;
T_1 V_20 = F_5 ( V_14 ) ;
T_1 V_21 = F_6 ( V_14 ) ;
switch ( F_7 ( V_14 ) ) {
case V_170 :
case V_171 :
case V_172 :
case V_173 :
if ( V_20 )
V_80 = F_12 ( V_2 , V_20 ) ;
V_80 += ( V_174 ) ( ( V_175 ) V_14 ) ;
break;
case 31 :
if ( V_20 )
V_80 = F_12 ( V_2 , V_20 ) ;
V_80 += F_12 ( V_2 , V_21 ) ;
break;
default:
F_31 ( V_168 L_3 , V_14 ) ;
break;
}
return V_80 ;
}
