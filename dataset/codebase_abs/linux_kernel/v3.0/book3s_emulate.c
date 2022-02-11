int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , int * V_6 )
{
int V_7 = V_8 ;
switch ( F_2 ( V_5 ) ) {
case 19 :
switch ( F_3 ( V_5 ) ) {
case V_9 :
case V_10 :
F_4 ( V_4 , V_4 -> V_11 . V_12 -> V_13 ) ;
F_5 ( V_4 , V_4 -> V_11 . V_12 -> V_14 ) ;
* V_6 = 0 ;
break;
default:
V_7 = V_15 ;
break;
}
break;
case 31 :
switch ( F_3 ( V_5 ) ) {
case V_16 :
F_6 ( V_4 , F_7 ( V_5 ) ,
V_4 -> V_11 . V_12 -> V_17 ) ;
break;
case V_18 :
{
T_1 V_19 = F_8 ( V_4 , F_9 ( V_5 ) ) ;
if ( V_5 & 0x10000 ) {
V_4 -> V_11 . V_12 -> V_17 &= ~ ( V_20 | V_21 ) ;
V_4 -> V_11 . V_12 -> V_17 |= V_19 & ( V_20 | V_21 ) ;
} else
F_5 ( V_4 , V_19 ) ;
break;
}
case V_22 :
F_5 ( V_4 , F_8 ( V_4 , F_9 ( V_5 ) ) ) ;
break;
case V_23 :
{
int V_24 ;
V_24 = F_10 ( V_5 , 12 + 32 , 15 + 32 ) ;
if ( V_4 -> V_11 . V_25 . V_26 ) {
T_2 V_27 ;
V_27 = V_4 -> V_11 . V_25 . V_26 ( V_4 , V_24 ) ;
F_6 ( V_4 , F_7 ( V_5 ) , V_27 ) ;
}
break;
}
case V_28 :
{
int V_24 ;
V_24 = ( F_8 ( V_4 , F_11 ( V_5 ) ) >> 28 ) & 0xf ;
if ( V_4 -> V_11 . V_25 . V_26 ) {
T_2 V_27 ;
V_27 = V_4 -> V_11 . V_25 . V_26 ( V_4 , V_24 ) ;
F_6 ( V_4 , F_7 ( V_5 ) , V_27 ) ;
}
break;
}
case V_29 :
V_4 -> V_11 . V_25 . V_30 ( V_4 ,
( V_5 >> 16 ) & 0xf ,
F_8 ( V_4 , F_9 ( V_5 ) ) ) ;
break;
case V_31 :
V_4 -> V_11 . V_25 . V_30 ( V_4 ,
( F_8 ( V_4 , F_11 ( V_5 ) ) >> 28 ) & 0xf ,
F_8 ( V_4 , F_9 ( V_5 ) ) ) ;
break;
case V_32 :
case V_33 :
{
bool V_34 = ( V_5 & 0x00200000 ) ? true : false ;
T_1 V_35 = F_8 ( V_4 , F_11 ( V_5 ) ) ;
V_4 -> V_11 . V_25 . V_36 ( V_4 , V_35 , V_34 ) ;
break;
}
case V_37 :
break;
case V_38 :
if ( ! V_4 -> V_11 . V_25 . V_39 )
return V_15 ;
V_4 -> V_11 . V_25 . V_39 ( V_4 ,
F_8 ( V_4 , F_9 ( V_5 ) ) ,
F_8 ( V_4 , F_11 ( V_5 ) ) ) ;
break;
case V_40 :
if ( ! V_4 -> V_11 . V_25 . V_41 )
return V_15 ;
V_4 -> V_11 . V_25 . V_41 ( V_4 ,
F_8 ( V_4 , F_11 ( V_5 ) ) ) ;
break;
case V_42 :
if ( ! V_4 -> V_11 . V_25 . V_43 )
return V_15 ;
V_4 -> V_11 . V_25 . V_43 ( V_4 ) ;
break;
case V_44 :
if ( ! V_4 -> V_11 . V_25 . V_45 ) {
V_7 = V_15 ;
} else {
T_1 V_46 , V_47 ;
V_47 = F_8 ( V_4 , F_11 ( V_5 ) ) ;
V_46 = V_4 -> V_11 . V_25 . V_45 ( V_4 , V_47 ) ;
F_6 ( V_4 , F_7 ( V_5 ) , V_46 ) ;
}
break;
case V_48 :
if ( ! V_4 -> V_11 . V_25 . V_49 ) {
V_7 = V_15 ;
} else {
T_1 V_46 , V_47 ;
V_47 = F_8 ( V_4 , F_11 ( V_5 ) ) ;
V_46 = V_4 -> V_11 . V_25 . V_49 ( V_4 , V_47 ) ;
F_6 ( V_4 , F_7 ( V_5 ) , V_46 ) ;
}
break;
case V_50 :
break;
case V_51 :
{
T_1 V_47 = F_8 ( V_4 , F_11 ( V_5 ) ) ;
T_1 V_52 = 0 ;
T_1 V_35 , V_53 ;
T_2 V_54 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_55 ;
int V_56 ;
if ( F_12 ( V_5 ) )
V_52 = F_8 ( V_4 , F_12 ( V_5 ) ) ;
V_35 = ( V_52 + V_47 ) & ~ 31ULL ;
if ( ! ( V_4 -> V_11 . V_12 -> V_17 & V_57 ) )
V_35 &= 0xffffffff ;
V_53 = V_35 ;
V_56 = F_13 ( V_4 , & V_35 , 32 , V_54 , true ) ;
if ( ( V_56 == - V_58 ) || ( V_56 == - V_59 ) ) {
* V_6 = 0 ;
V_4 -> V_11 . V_12 -> V_60 = V_53 ;
F_14 ( V_4 ) -> V_61 = V_53 ;
V_55 = V_62 ;
if ( V_56 == - V_58 )
V_55 |= V_63 ;
else if ( V_56 == - V_59 )
V_55 |= V_64 ;
V_4 -> V_11 . V_12 -> V_55 = V_55 ;
F_14 ( V_4 ) -> V_65 = V_55 ;
F_15 ( V_4 ,
V_66 ) ;
}
break;
}
default:
V_7 = V_15 ;
}
break;
default:
V_7 = V_15 ;
}
if ( V_7 == V_15 )
V_7 = F_16 ( V_2 , V_4 ) ;
return V_7 ;
}
void F_17 ( struct V_3 * V_4 , struct V_67 * V_68 , bool V_69 ,
T_2 V_70 )
{
if ( V_69 ) {
T_2 V_71 = ( V_70 >> 2 ) & 0x7ff ;
V_68 -> V_72 = ( ~ V_71 << 17 ) ;
V_68 -> V_73 = V_70 & 0xfffe0000 ;
V_68 -> V_74 = ( V_70 & 2 ) ? 1 : 0 ;
V_68 -> V_75 = ( V_70 & 1 ) ? 1 : 0 ;
V_68 -> V_76 = ( V_68 -> V_76 & 0xffffffff00000000ULL ) | V_70 ;
} else {
V_68 -> V_77 = V_70 & 0xfffe0000 ;
V_68 -> V_78 = ( V_70 >> 3 ) & 0xf ;
V_68 -> V_79 = V_70 & 3 ;
V_68 -> V_76 = ( V_68 -> V_76 & 0x00000000ffffffffULL ) | ( ( V_80 ) V_70 << 32 ) ;
}
}
static struct V_67 * F_18 ( struct V_3 * V_4 , int V_81 )
{
struct V_82 * V_83 = F_19 ( V_4 ) ;
struct V_67 * V_68 ;
switch ( V_81 ) {
case V_84 ... V_85 :
V_68 = & V_83 -> V_86 [ ( V_81 - V_84 ) / 2 ] ;
break;
case V_87 ... V_88 :
V_68 = & V_83 -> V_86 [ 4 + ( ( V_81 - V_87 ) / 2 ) ] ;
break;
case V_89 ... V_90 :
V_68 = & V_83 -> V_91 [ ( V_81 - V_89 ) / 2 ] ;
break;
case V_92 ... V_93 :
V_68 = & V_83 -> V_91 [ 4 + ( ( V_81 - V_92 ) / 2 ) ] ;
break;
default:
F_20 () ;
}
return V_68 ;
}
int F_21 ( struct V_3 * V_4 , int V_81 , int V_19 )
{
int V_7 = V_8 ;
T_1 V_94 = F_8 ( V_4 , V_19 ) ;
switch ( V_81 ) {
case V_95 :
F_19 ( V_4 ) -> V_96 = V_94 ;
break;
case V_97 :
V_4 -> V_11 . V_12 -> V_55 = V_94 ;
break;
case V_98 :
V_4 -> V_11 . V_12 -> V_60 = V_94 ;
break;
case V_99 :
F_19 ( V_4 ) -> V_100 = V_94 ;
break;
case V_84 ... V_85 :
case V_87 ... V_88 :
case V_89 ... V_90 :
case V_92 ... V_93 :
{
struct V_67 * V_68 = F_18 ( V_4 , V_81 ) ;
F_17 ( V_4 , V_68 , ! ( V_81 % 2 ) , ( T_2 ) V_94 ) ;
F_22 ( V_4 , 0 , 0 ) ;
F_23 ( V_4 ) ;
break;
}
case V_101 :
F_19 ( V_4 ) -> V_102 [ 0 ] = V_94 ;
break;
case V_103 :
F_19 ( V_4 ) -> V_102 [ 1 ] = V_94 ;
break;
case V_104 :
F_19 ( V_4 ) -> V_102 [ 2 ] = V_94 ;
break;
case V_105 :
F_19 ( V_4 ) -> V_102 [ 2 ] = V_94 ;
switch ( V_4 -> V_11 . V_106 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
if ( V_4 -> V_11 . V_107 & V_108 ) {
} else if ( V_94 & ( 1 << 29 ) ) {
V_4 -> V_11 . V_107 |= V_109 ;
F_24 ( V_4 , V_110 ) ;
} else {
V_4 -> V_11 . V_107 &= ~ V_109 ;
}
break;
}
break;
case V_111 :
case V_112 :
F_19 ( V_4 ) -> V_102 [ 4 ] = V_94 ;
break;
case V_113 :
F_19 ( V_4 ) -> V_102 [ 5 ] = V_94 ;
if ( V_4 -> V_11 . V_25 . V_114 ( V_4 ) &&
( F_25 () & V_115 ) )
V_4 -> V_11 . V_107 |= V_116 ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
F_19 ( V_4 ) -> V_125 [ V_81 - V_117 ] = V_94 ;
break;
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
break;
default:
F_26 ( V_140 L_1 , V_81 ) ;
#ifndef F_27
V_7 = V_15 ;
#endif
break;
}
return V_7 ;
}
int F_28 ( struct V_3 * V_4 , int V_81 , int V_141 )
{
int V_7 = V_8 ;
switch ( V_81 ) {
case V_84 ... V_85 :
case V_87 ... V_88 :
case V_89 ... V_90 :
case V_92 ... V_93 :
{
struct V_67 * V_68 = F_18 ( V_4 , V_81 ) ;
if ( V_81 % 2 )
F_6 ( V_4 , V_141 , V_68 -> V_76 >> 32 ) ;
else
F_6 ( V_4 , V_141 , V_68 -> V_76 ) ;
break;
}
case V_95 :
F_6 ( V_4 , V_141 , F_19 ( V_4 ) -> V_96 ) ;
break;
case V_97 :
F_6 ( V_4 , V_141 , V_4 -> V_11 . V_12 -> V_55 ) ;
break;
case V_98 :
F_6 ( V_4 , V_141 , V_4 -> V_11 . V_12 -> V_60 ) ;
break;
case V_99 :
F_6 ( V_4 , V_141 , F_19 ( V_4 ) -> V_100 ) ;
break;
case V_101 :
F_6 ( V_4 , V_141 , F_19 ( V_4 ) -> V_102 [ 0 ] ) ;
break;
case V_103 :
F_6 ( V_4 , V_141 , F_19 ( V_4 ) -> V_102 [ 1 ] ) ;
break;
case V_104 :
case V_105 :
F_6 ( V_4 , V_141 , F_19 ( V_4 ) -> V_102 [ 2 ] ) ;
break;
case V_111 :
case V_112 :
F_6 ( V_4 , V_141 , F_19 ( V_4 ) -> V_102 [ 4 ] ) ;
break;
case V_113 :
F_6 ( V_4 , V_141 , F_19 ( V_4 ) -> V_102 [ 5 ] ) ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
F_6 ( V_4 , V_141 ,
F_19 ( V_4 ) -> V_125 [ V_81 - V_117 ] ) ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
F_6 ( V_4 , V_141 , 0 ) ;
break;
default:
F_26 ( V_140 L_2 , V_81 ) ;
#ifndef F_27
V_7 = V_15 ;
#endif
break;
}
return V_7 ;
}
T_2 F_29 ( struct V_3 * V_4 , unsigned int V_5 )
{
T_2 V_55 = 0 ;
switch ( F_2 ( V_5 ) ) {
case V_142 :
case V_143 :
case V_144 :
case V_145 :
V_55 |= ( V_5 >> 12 ) & 0x4000 ;
V_55 |= ( V_5 >> 17 ) & 0x3c00 ;
break;
case 31 :
V_55 |= ( V_5 << 14 ) & 0x18000 ;
V_55 |= ( V_5 << 8 ) & 0x04000 ;
V_55 |= ( V_5 << 3 ) & 0x03c00 ;
break;
default:
F_26 ( V_140 L_3 , V_5 ) ;
break;
}
V_55 |= ( V_5 >> 16 ) & 0x03ff ;
return V_55 ;
}
T_1 F_30 ( struct V_3 * V_4 , unsigned int V_5 )
{
T_1 V_60 = 0 ;
T_1 V_52 ;
switch ( F_2 ( V_5 ) ) {
case V_142 :
case V_143 :
case V_144 :
case V_145 :
V_52 = F_12 ( V_5 ) ;
if ( V_52 )
V_60 = F_8 ( V_4 , V_52 ) ;
V_60 += ( V_146 ) ( ( V_147 ) V_5 ) ;
break;
case 31 :
V_52 = F_12 ( V_5 ) ;
if ( V_52 )
V_60 = F_8 ( V_4 , V_52 ) ;
V_60 += F_8 ( V_4 , F_11 ( V_5 ) ) ;
break;
default:
F_26 ( V_140 L_3 , V_5 ) ;
break;
}
return V_60 ;
}
