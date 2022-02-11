static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 )
{
V_4 -> V_6 . type = V_7 ;
V_4 -> V_6 . V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_7 , F_2 ( V_2 ) ,
V_5 , V_4 ) < 0 )
return - V_8 ;
return 0 ;
}
static void F_4 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
if ( V_4 -> V_9 )
F_5 ( V_4 ) ;
}
static int F_6 ( struct V_10 * V_10 , int V_11 , int V_12 )
{
switch ( V_10 -> V_13 ) {
case V_14 :
case V_15 :
case V_16 :
default:
if ( V_10 -> V_17 == 0xa )
return ( 64 * V_12 ) + ( 32 + ( V_11 ) ) ;
else
return ( 52 * V_12 ) + ( 26 + ( V_11 ) ) ;
case V_18 :
return ( 32 * V_12 ) + ( 16 + ( V_11 ) ) ;
case V_19 :
return ( 52 * V_12 ) + ( 26 + ( V_11 ) ) ;
}
}
static int F_7 ( struct V_10 * V_10 , int V_11 , int V_12 )
{
switch ( V_10 -> V_13 ) {
case V_14 :
case V_15 :
case V_16 :
default:
if ( V_10 -> V_17 == 0xa )
return ( 64 * V_12 ) + V_11 ;
else
return ( 52 * V_12 ) + V_11 ;
case V_18 :
return ( 32 * V_12 ) + V_11 ;
case V_19 :
return ( 52 * V_12 ) + V_11 ;
}
}
static void F_8 ( struct V_10 * V_10 , int V_20 , int V_21 )
{
F_9 ( V_21 , V_10 -> V_22 + V_20 ) ;
}
static unsigned int F_10 ( struct V_10 * V_10 , int V_20 )
{
return F_11 ( V_10 -> V_22 + V_20 ) ;
}
static int F_12 ( struct V_10 * V_10 )
{
int V_23 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) return 0 ;
for ( V_23 = 0 ; V_23 < 500 ; V_23 ++ ) {
if ( 0 == ( F_10 ( V_10 , V_24 ) &
V_25 ) ) {
if ( V_23 ) {
F_13 ( L_1 ,
( 20 * V_23 ) ) ;
}
return 0 ;
}
F_14 ( 20 ) ;
}
F_15 ( V_26 L_2 ) ;
V_10 -> V_27 &= ~ V_28 ;
return - V_29 ;
}
static int F_16 ( struct V_10 * V_10 , unsigned int V_30 ,
unsigned int V_31 )
{
unsigned int V_23 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
for ( V_23 = 0 ; V_23 != V_30 ; ++ V_23 ) {
if ( F_10 ( V_10 , V_24 ) & V_25 )
F_14 ( V_31 ) ;
else {
F_13 ( L_3 ,
V_23 * V_31 ) ;
return 0 ;
}
}
F_15 ( L_2 ) ;
V_10 -> V_27 &= ~ V_28 ;
return - V_29 ;
}
static int F_17 ( struct V_10 * V_10 ) {
int V_23 ;
unsigned long V_32 ;
const T_2 * V_33 ;
if ( V_10 -> V_34 )
V_33 = V_10 -> V_34 ;
else {
if ( ! V_10 -> V_35 )
return - V_36 ;
V_33 = ( T_2 * ) V_10 -> V_35 -> V_37 ;
if ( ! V_33 )
return - V_36 ;
}
if ( ( F_10 ( V_10 , V_24 ) & V_38 ) != 0 ) {
F_15 ( L_4 ) ;
F_8 ( V_10 , V_39 , V_40 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_18 ( V_10 , 0 , V_42 ) ) {
F_15 ( L_5 ) ;
F_8 ( V_10 , V_39 , V_43 ) ;
return - V_29 ;
}
F_8 ( V_10 , V_39 , V_44 ) ;
for ( V_23 = 0 ; V_23 < V_45 / 4 ; ++ V_23 ) {
F_8 ( V_10 , V_41 , V_33 [ V_23 ] ) ;
if ( F_18 ( V_10 , 127 , V_42 ) ) {
F_15 ( L_6 ) ;
F_8 ( V_10 , V_39 , V_43 ) ;
return - V_29 ;
}
}
F_18 ( V_10 , 3 , V_42 ) ;
F_8 ( V_10 , V_39 , V_43 ) ;
F_19 ( 3 ) ;
#ifdef F_20
V_10 -> V_46 = V_47 ;
#else
V_10 -> V_46 = 0 ;
#endif
F_8 ( V_10 , V_39 , V_10 -> V_46 ) ;
F_15 ( L_7 ) ;
}
if ( V_10 -> V_27 & V_48 ) {
F_15 ( V_49 L_8 ) ;
F_21 ( & V_10 -> V_50 , V_32 ) ;
F_22 ( V_10 ) ;
F_23 ( & V_10 -> V_50 , V_32 ) ;
}
V_10 -> V_27 |= V_28 ;
return 0 ;
}
static int F_24 ( struct V_10 * V_10 )
{
if ( ( F_10 ( V_10 , V_24 ) & V_38 ) != 0 ) {
F_8 ( V_10 , V_39 , V_44 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_18 ( V_10 , 0 , V_51 ) < 0 ) {
F_8 ( V_10 , V_39 , V_52 ) ;
F_8 ( V_10 , V_39 , V_44 ) ;
}
F_8 ( V_10 , V_39 , V_43 | V_53 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_18 ( V_10 , 0 , V_51 ) < 0 ) {
V_10 -> V_13 = V_14 ;
F_15 ( L_9 ) ;
return 0 ;
}
F_8 ( V_10 , V_39 , V_44 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_18 ( V_10 , 0 , V_51 ) == 0 ) {
V_10 -> V_13 = V_15 ;
F_15 ( L_10 ) ;
return 0 ;
}
F_8 ( V_10 , V_39 , V_52 ) ;
F_8 ( V_10 , V_39 , V_44 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_18 ( V_10 , 0 , V_51 ) == 0 ) {
V_10 -> V_13 = V_14 ;
F_15 ( L_9 ) ;
return 0 ;
}
F_8 ( V_10 , V_39 , V_52 ) ;
F_8 ( V_10 , V_39 , V_44 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_18 ( V_10 , 0 , V_51 ) < 0 ) {
V_10 -> V_13 = V_14 ;
F_15 ( L_9 ) ;
return 0 ;
}
V_10 -> V_13 = V_16 ;
F_15 ( L_11 ) ;
return 0 ;
} else {
if ( F_10 ( V_10 , V_54 ) & V_55 )
V_10 -> V_13 = V_16 ;
else if ( F_10 ( V_10 , V_54 ) & V_56 )
V_10 -> V_13 = V_14 ;
else
V_10 -> V_13 = V_15 ;
}
return 0 ;
}
static int F_25 ( struct V_10 * V_10 , int V_57 )
{
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
if ( ( F_10 ( V_10 , V_24 ) & V_38 ) != 0 ) {
V_10 -> V_27 &= ~ V_28 ;
if ( ! V_57 )
return - V_29 ;
F_15 ( V_26 L_12 ) ;
if ( ! ( V_10 -> V_27 & V_58 ) ) {
if ( ! F_26 ( V_10 ) )
return 0 ;
F_15 ( V_26
L_13
L_14 ) ;
return - V_29 ;
}
if ( F_17 ( V_10 ) != 0 ) {
F_15 ( V_26
L_15
L_16 ) ;
return - V_29 ;
}
}
return 0 ;
}
static int F_18 ( struct V_10 * V_10 , int V_59 , int V_60 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_60 ; V_23 ++ ) {
if ( ( int ) ( F_10 ( V_10 , V_61 ) & 0xff ) <= V_59 )
return 0 ;
F_27 ( 100 ) ;
}
F_15 ( L_17 ,
V_59 , V_60 ) ;
return - 1 ;
}
static int F_28 ( struct V_10 * V_10 , unsigned int V_62 )
{
if ( V_62 >= V_63 )
return 0 ;
return V_10 -> V_64 [ V_62 ] ;
}
static int F_29 ( struct V_10 * V_10 , unsigned int V_62 , unsigned short V_37 )
{
unsigned int V_65 ;
if ( V_62 >= V_63 )
return - 1 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) {
if ( V_10 -> V_13 == V_18 && V_62 >= 512 )
return 0 ;
if ( V_10 -> V_13 == V_19 && V_62 >= 1352 )
return 0 ;
V_10 -> V_64 [ V_62 ] = V_37 ;
V_65 = V_62 / 2 ;
F_8 ( V_10 , 4096 + ( V_65 * 4 ) ,
( V_10 -> V_64 [ ( V_62 & 0x7fe ) + 1 ] << 16 ) +
V_10 -> V_64 [ V_62 & 0x7fe ] ) ;
return 0 ;
} else {
V_65 = ( V_62 << 16 ) + V_37 ;
if ( F_18 ( V_10 , 127 , V_42 ) )
return - 1 ;
F_8 ( V_10 , V_41 , V_65 ) ;
V_10 -> V_64 [ V_62 ] = V_37 ;
}
return 0 ;
}
static int F_30 ( struct V_10 * V_10 )
{
unsigned long V_32 ;
int V_66 = 1 ;
F_21 ( & V_10 -> V_50 , V_32 ) ;
if ( ( V_10 -> V_67 != V_10 -> V_68 ) &&
( V_10 -> V_67 >= 0 ) && ( V_10 -> V_68 >= 0 ) )
V_66 = 0 ;
F_23 ( & V_10 -> V_50 , V_32 ) ;
return V_66 ;
}
static int F_31 ( struct V_10 * V_10 )
{
unsigned int V_69 = F_10 ( V_10 , V_24 ) ;
unsigned int V_70 = ( V_69 & V_71 ) ;
if ( V_10 -> V_13 == V_18 )
V_70 = ( V_69 & V_72 ) ;
if ( V_69 & V_73 )
return 0 ;
switch ( V_70 ) {
case V_74 : return 32000 ;
case V_75 : return 44100 ;
case V_76 : return 48000 ;
case V_77 : return 64000 ;
case V_78 : return 88200 ;
case V_79 : return 96000 ;
case V_80 :
if ( V_10 -> V_13 == V_18 ) return 128000 ;
break;
case V_81 :
if ( V_10 -> V_13 == V_18 ) return 176400 ;
break;
case V_82 :
if ( V_10 -> V_13 == V_18 ) return 192000 ;
break;
default:
break;
}
F_15 ( L_18 , V_70 , V_69 ) ;
return 0 ;
}
static int F_32 ( struct V_10 * V_10 )
{
unsigned int V_83 = F_10 ( V_10 , V_54 ) ;
unsigned int V_70 = V_83 & V_84 ;
if ( V_10 -> V_13 == V_18 &&
F_33 ( V_10 ) == V_85 )
return F_31 ( V_10 ) ;
switch ( V_70 ) {
case V_86 : return 32000 ;
case V_87 : return 44100 ;
case V_88 : return 48000 ;
case V_89 : return 64000 ;
case V_90 : return 88200 ;
case V_91 : return 96000 ;
default:
return 0 ;
}
}
static void F_34 ( struct V_10 * V_10 )
{
V_10 -> V_92 = 1 << ( ( F_35 ( V_10 -> V_93 ) + 8 ) ) ;
}
static T_3 F_36 ( struct V_10 * V_10 )
{
int V_94 ;
V_94 = F_10 ( V_10 , V_24 ) ;
if ( ! V_10 -> V_95 )
return ( V_94 & V_96 ) ? ( V_10 -> V_92 / 4 ) : 0 ;
V_94 &= V_97 ;
V_94 /= 4 ;
V_94 &= ( V_10 -> V_92 / 2 ) - 1 ;
return V_94 ;
}
static void F_37 ( struct V_10 * V_10 )
{
F_8 ( V_10 , V_98 , 0 ) ;
if ( V_10 -> V_13 == V_18 && V_10 -> V_17 >= 152 )
F_8 ( V_10 , V_99 , V_10 -> V_100 ) ;
}
static void F_38 ( struct V_10 * V_101 )
{
V_101 -> V_93 |= ( V_102 | V_103 ) ;
F_8 ( V_101 , V_104 , V_101 -> V_93 ) ;
}
static void F_39 ( struct V_10 * V_101 )
{
V_101 -> V_93 &= ~ ( V_103 | V_102 ) ;
F_8 ( V_101 , V_104 , V_101 -> V_93 ) ;
}
static void F_40 ( struct V_10 * V_10 )
{
memset ( V_10 -> V_105 , 0 , V_106 ) ;
}
static int F_41 ( struct V_10 * V_101 , unsigned int V_107 )
{
int V_108 ;
F_42 ( & V_101 -> V_50 ) ;
V_107 >>= 7 ;
V_108 = 0 ;
while ( V_107 ) {
V_108 ++ ;
V_107 >>= 1 ;
}
V_101 -> V_93 &= ~ V_109 ;
V_101 -> V_93 |= F_43 ( V_108 ) ;
F_8 ( V_101 , V_104 , V_101 -> V_93 ) ;
F_34 ( V_101 ) ;
F_44 ( & V_101 -> V_50 ) ;
return 0 ;
}
static void F_45 ( struct V_10 * V_10 , int V_110 )
{
T_4 V_108 ;
if ( V_110 >= 112000 )
V_110 /= 4 ;
else if ( V_110 >= 56000 )
V_110 /= 2 ;
V_108 = V_111 ;
V_108 = F_46 ( V_108 , V_110 ) ;
F_47 ( V_108 >> 32 ) ;
V_10 -> V_100 = V_108 ;
F_8 ( V_10 , V_99 , V_10 -> V_100 ) ;
}
static int F_48 ( struct V_10 * V_10 , int V_110 , int V_112 )
{
int V_113 = 0 ;
int V_114 ;
int V_70 ;
if ( ! ( V_10 -> V_93 & V_115 ) ) {
if ( V_112 ) {
F_15 ( V_26 L_19 ) ;
return - 1 ;
} else {
int V_116 = F_32 ( V_10 ) ;
int V_117 = F_31 ( V_10 ) ;
if ( ( V_117 == V_116 * 2 ) && ( F_33 ( V_10 ) >= V_118 ) )
F_15 ( V_49 L_20 ) ;
else if ( V_10 -> V_13 == V_18 && ( V_117 == V_116 * 4 ) && ( F_33 ( V_10 ) >= V_118 ) )
F_15 ( V_49 L_21 ) ;
else if ( V_110 != V_116 ) {
F_15 ( V_49 L_22 ) ;
return - 1 ;
}
}
}
V_114 = V_10 -> V_119 ;
if ( V_110 > 96000 && V_10 -> V_13 != V_18 )
return - V_120 ;
switch ( V_110 ) {
case 32000 :
if ( V_114 > 48000 )
V_113 = 1 ;
V_70 = V_121 ;
break;
case 44100 :
if ( V_114 > 48000 )
V_113 = 1 ;
V_70 = V_122 ;
break;
case 48000 :
if ( V_114 > 48000 )
V_113 = 1 ;
V_70 = V_123 ;
break;
case 64000 :
if ( V_114 <= 48000 || V_114 > 96000 )
V_113 = 1 ;
V_70 = V_124 ;
break;
case 88200 :
if ( V_114 <= 48000 || V_114 > 96000 )
V_113 = 1 ;
V_70 = V_125 ;
break;
case 96000 :
if ( V_114 <= 48000 || V_114 > 96000 )
V_113 = 1 ;
V_70 = V_126 ;
break;
case 128000 :
if ( V_114 < 128000 )
V_113 = 1 ;
V_70 = V_127 ;
break;
case 176400 :
if ( V_114 < 128000 )
V_113 = 1 ;
V_70 = V_128 ;
break;
case 192000 :
if ( V_114 < 128000 )
V_113 = 1 ;
V_70 = V_129 ;
break;
default:
return - V_120 ;
}
if ( V_113 && ( V_10 -> V_68 >= 0 || V_10 -> V_67 >= 0 ) ) {
F_15 ( L_23 ,
V_10 -> V_68 ,
V_10 -> V_67 ) ;
return - V_130 ;
}
V_10 -> V_93 &= ~ V_131 ;
V_10 -> V_93 |= V_70 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
if ( V_10 -> V_13 == V_18 && V_10 -> V_17 >= 152 )
F_45 ( V_10 , V_110 ) ;
if ( V_110 >= 128000 ) {
V_10 -> V_132 = V_133 ;
} else if ( V_110 > 48000 ) {
if ( V_10 -> V_13 == V_18 )
V_10 -> V_132 = V_134 ;
else
V_10 -> V_132 = V_135 ;
} else {
switch ( V_10 -> V_13 ) {
case V_16 :
case V_14 :
V_10 -> V_132 = V_136 ;
break;
case V_15 :
case V_19 :
V_10 -> V_132 = V_137 ;
break;
case V_18 :
V_10 -> V_132 = V_138 ;
break;
default:
break;
}
}
V_10 -> V_119 = V_110 ;
return 0 ;
}
static unsigned char F_49 ( struct V_10 * V_10 , int V_139 )
{
if ( V_139 )
return F_10 ( V_10 , V_140 ) ;
else
return F_10 ( V_10 , V_141 ) ;
}
static void F_50 ( struct V_10 * V_10 , int V_139 , int V_21 )
{
if ( V_139 )
F_8 ( V_10 , V_142 , V_21 ) ;
else
F_8 ( V_10 , V_143 , V_21 ) ;
}
static int F_51 ( struct V_10 * V_10 , int V_139 )
{
if ( V_139 )
return ( F_10 ( V_10 , V_144 ) & 0xff ) ;
else
return ( F_10 ( V_10 , V_145 ) & 0xff ) ;
}
static int F_52 ( struct V_10 * V_10 , int V_139 )
{
int V_146 ;
if ( V_139 )
V_146 = F_10 ( V_10 , V_147 ) & 0xff ;
else
V_146 = F_10 ( V_10 , V_148 ) & 0xff ;
if ( V_146 < 128 )
return 128 - V_146 ;
else
return 0 ;
}
static void F_53 ( struct V_10 * V_10 , int V_139 )
{
while ( F_51 ( V_10 , V_139 ) )
F_49 ( V_10 , V_139 ) ;
}
static int F_54 ( struct V_149 * V_150 )
{
unsigned long V_32 ;
int V_151 ;
int V_152 ;
int V_23 ;
unsigned char V_153 [ 128 ] ;
F_21 ( & V_150 -> V_50 , V_32 ) ;
if ( V_150 -> V_154 ) {
if ( ! F_55 ( V_150 -> V_154 ) ) {
if ( ( V_151 = F_52 ( V_150 -> V_10 , V_150 -> V_139 ) ) > 0 ) {
if ( V_151 > ( int ) sizeof ( V_153 ) )
V_151 = sizeof ( V_153 ) ;
if ( ( V_152 = F_56 ( V_150 -> V_154 , V_153 , V_151 ) ) > 0 ) {
for ( V_23 = 0 ; V_23 < V_152 ; ++ V_23 )
F_50 ( V_150 -> V_10 , V_150 -> V_139 , V_153 [ V_23 ] ) ;
}
}
}
}
F_23 ( & V_150 -> V_50 , V_32 ) ;
return 0 ;
}
static int F_57 ( struct V_149 * V_150 )
{
unsigned char V_153 [ 128 ] ;
unsigned long V_32 ;
int V_151 ;
int V_23 ;
F_21 ( & V_150 -> V_50 , V_32 ) ;
if ( ( V_151 = F_51 ( V_150 -> V_10 , V_150 -> V_139 ) ) > 0 ) {
if ( V_150 -> V_155 ) {
if ( V_151 > ( int ) sizeof ( V_153 ) )
V_151 = sizeof ( V_153 ) ;
for ( V_23 = 0 ; V_23 < V_151 ; ++ V_23 )
V_153 [ V_23 ] = F_49 ( V_150 -> V_10 , V_150 -> V_139 ) ;
if ( V_151 )
F_58 ( V_150 -> V_155 , V_153 , V_151 ) ;
} else {
while ( -- V_151 )
F_49 ( V_150 -> V_10 , V_150 -> V_139 ) ;
}
}
V_150 -> V_156 = 0 ;
if ( V_150 -> V_139 )
V_150 -> V_10 -> V_93 |= V_157 ;
else
V_150 -> V_10 -> V_93 |= V_158 ;
F_8 ( V_150 -> V_10 , V_104 , V_150 -> V_10 -> V_93 ) ;
F_23 ( & V_150 -> V_50 , V_32 ) ;
return F_54 ( V_150 ) ;
}
static void F_59 ( struct V_159 * V_160 , int V_161 )
{
struct V_10 * V_10 ;
struct V_149 * V_150 ;
unsigned long V_32 ;
T_2 V_162 ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
V_10 = V_150 -> V_10 ;
V_162 = V_150 -> V_139 ? V_157 : V_158 ;
F_21 ( & V_10 -> V_50 , V_32 ) ;
if ( V_161 ) {
if ( ! ( V_10 -> V_93 & V_162 ) ) {
F_53 ( V_10 , V_150 -> V_139 ) ;
V_10 -> V_93 |= V_162 ;
}
} else {
V_10 -> V_93 &= ~ V_162 ;
F_60 ( & V_10 -> V_165 ) ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
F_23 ( & V_10 -> V_50 , V_32 ) ;
}
static void F_61 ( unsigned long V_37 )
{
struct V_149 * V_150 = (struct V_149 * ) V_37 ;
unsigned long V_32 ;
F_54 ( V_150 ) ;
F_21 ( & V_150 -> V_50 , V_32 ) ;
if ( V_150 -> V_166 ) {
V_150 -> V_167 . V_168 = 1 + V_169 ;
F_62 ( & V_150 -> V_167 ) ;
}
F_23 ( & V_150 -> V_50 , V_32 ) ;
}
static void F_63 ( struct V_159 * V_160 , int V_161 )
{
struct V_149 * V_150 ;
unsigned long V_32 ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
F_21 ( & V_150 -> V_50 , V_32 ) ;
if ( V_161 ) {
if ( ! V_150 -> V_166 ) {
F_64 ( & V_150 -> V_167 ) ;
V_150 -> V_167 . V_170 = F_61 ;
V_150 -> V_167 . V_37 = ( unsigned long ) V_150 ;
V_150 -> V_167 . V_168 = 1 + V_169 ;
F_62 ( & V_150 -> V_167 ) ;
V_150 -> V_166 ++ ;
}
} else {
if ( V_150 -> V_166 && -- V_150 -> V_166 <= 0 )
F_65 ( & V_150 -> V_167 ) ;
}
F_23 ( & V_150 -> V_50 , V_32 ) ;
if ( V_161 )
F_54 ( V_150 ) ;
}
static int F_66 ( struct V_159 * V_160 )
{
struct V_149 * V_150 ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
F_42 ( & V_150 -> V_50 ) ;
F_53 ( V_150 -> V_10 , V_150 -> V_139 ) ;
V_150 -> V_155 = V_160 ;
F_44 ( & V_150 -> V_50 ) ;
return 0 ;
}
static int F_67 ( struct V_159 * V_160 )
{
struct V_149 * V_150 ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
F_42 ( & V_150 -> V_50 ) ;
V_150 -> V_154 = V_160 ;
F_44 ( & V_150 -> V_50 ) ;
return 0 ;
}
static int F_68 ( struct V_159 * V_160 )
{
struct V_149 * V_150 ;
F_59 ( V_160 , 0 ) ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
F_42 ( & V_150 -> V_50 ) ;
V_150 -> V_155 = NULL ;
F_44 ( & V_150 -> V_50 ) ;
return 0 ;
}
static int F_69 ( struct V_159 * V_160 )
{
struct V_149 * V_150 ;
F_63 ( V_160 , 0 ) ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
F_42 ( & V_150 -> V_50 ) ;
V_150 -> V_154 = NULL ;
F_44 ( & V_150 -> V_50 ) ;
return 0 ;
}
static int F_70 ( struct V_171 * V_172 , struct V_10 * V_10 , int V_139 )
{
char V_153 [ 32 ] ;
V_10 -> V_173 [ V_139 ] . V_139 = V_139 ;
V_10 -> V_173 [ V_139 ] . V_163 = NULL ;
V_10 -> V_173 [ V_139 ] . V_155 = NULL ;
V_10 -> V_173 [ V_139 ] . V_154 = NULL ;
V_10 -> V_173 [ V_139 ] . V_10 = V_10 ;
V_10 -> V_173 [ V_139 ] . V_166 = 0 ;
V_10 -> V_173 [ V_139 ] . V_156 = 0 ;
F_71 ( & V_10 -> V_173 [ V_139 ] . V_50 ) ;
sprintf ( V_153 , L_24 , V_172 -> V_174 , V_139 + 1 ) ;
if ( F_72 ( V_172 , V_153 , V_139 , 1 , 1 , & V_10 -> V_173 [ V_139 ] . V_163 ) < 0 )
return - 1 ;
sprintf ( V_10 -> V_173 [ V_139 ] . V_163 -> V_175 , L_25 , V_139 + 1 ) ;
V_10 -> V_173 [ V_139 ] . V_163 -> V_164 = & V_10 -> V_173 [ V_139 ] ;
F_73 ( V_10 -> V_173 [ V_139 ] . V_163 , V_176 , & V_177 ) ;
F_73 ( V_10 -> V_173 [ V_139 ] . V_163 , V_178 , & V_179 ) ;
V_10 -> V_173 [ V_139 ] . V_163 -> V_180 |= V_181 |
V_182 |
V_183 ;
return 0 ;
}
static T_2 F_74 ( struct V_184 * V_185 )
{
T_2 V_21 = 0 ;
V_21 |= ( V_185 -> V_69 [ 0 ] & V_186 ) ? V_187 : 0 ;
V_21 |= ( V_185 -> V_69 [ 0 ] & V_188 ) ? V_189 : 0 ;
if ( V_21 & V_187 )
V_21 |= ( V_185 -> V_69 [ 0 ] & V_190 ) ? V_191 : 0 ;
else
V_21 |= ( V_185 -> V_69 [ 0 ] & V_192 ) ? V_191 : 0 ;
return V_21 ;
}
static void F_75 ( struct V_184 * V_185 , T_2 V_21 )
{
V_185 -> V_69 [ 0 ] = ( ( V_21 & V_187 ) ? V_186 : 0 ) |
( ( V_21 & V_189 ) ? V_188 : 0 ) ;
if ( V_21 & V_187 )
V_185 -> V_69 [ 0 ] |= ( V_21 & V_191 ) ? V_190 : 0 ;
else
V_185 -> V_69 [ 0 ] |= ( V_21 & V_191 ) ? V_192 : 0 ;
}
static int F_76 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
V_196 -> type = V_197 ;
V_196 -> V_59 = 1 ;
return 0 ;
}
static int F_77 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
F_75 ( & V_199 -> V_200 . V_201 , V_10 -> V_202 ) ;
return 0 ;
}
static int F_79 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
T_2 V_21 ;
V_21 = F_74 ( & V_199 -> V_200 . V_201 ) ;
F_42 ( & V_10 -> V_50 ) ;
V_203 = V_21 != V_10 -> V_202 ;
V_10 -> V_202 = V_21 ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_80 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
V_196 -> type = V_197 ;
V_196 -> V_59 = 1 ;
return 0 ;
}
static int F_81 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
F_75 ( & V_199 -> V_200 . V_201 , V_10 -> V_204 ) ;
return 0 ;
}
static int F_82 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
T_2 V_21 ;
V_21 = F_74 ( & V_199 -> V_200 . V_201 ) ;
F_42 ( & V_10 -> V_50 ) ;
V_203 = V_21 != V_10 -> V_204 ;
V_10 -> V_204 = V_21 ;
V_10 -> V_93 &= ~ ( V_187 | V_189 | V_191 ) ;
F_8 ( V_10 , V_104 , V_10 -> V_93 |= V_21 ) ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_83 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
V_196 -> type = V_197 ;
V_196 -> V_59 = 1 ;
return 0 ;
}
static int F_84 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
V_199 -> V_200 . V_201 . V_69 [ 0 ] = V_194 -> V_205 ;
return 0 ;
}
static unsigned int F_85 ( struct V_10 * V_10 )
{
return F_86 ( V_10 -> V_93 & V_206 ) ;
}
static int F_87 ( struct V_10 * V_10 , int V_11 )
{
V_10 -> V_93 &= ~ V_206 ;
V_10 -> V_93 |= F_88 ( V_11 ) ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_89 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [ 4 ] = { L_26 , L_27 , L_28 , L_29 } ;
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = ( ( V_10 -> V_13 == V_18 ) ? 4 : 3 ) ;
if ( V_196 -> V_200 . V_209 . V_211 > ( ( V_10 -> V_13 == V_18 ) ? 3 : 2 ) )
V_196 -> V_200 . V_209 . V_211 = ( ( V_10 -> V_13 == V_18 ) ? 3 : 2 ) ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_90 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_85 ( V_10 ) ;
return 0 ;
}
static int F_91 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
unsigned int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . V_209 . V_211 [ 0 ] % ( ( V_10 -> V_13 == V_18 ) ? 4 : 3 ) ;
F_42 ( & V_10 -> V_50 ) ;
V_203 = V_21 != F_85 ( V_10 ) ;
if ( V_203 )
F_87 ( V_10 , V_21 ) ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_92 ( struct V_10 * V_10 , T_2 V_212 )
{
return ( V_10 -> V_93 & V_212 ) ? 1 : 0 ;
}
static int F_93 ( struct V_10 * V_10 , T_2 V_212 , int V_12 )
{
if ( V_12 )
V_10 -> V_93 |= V_212 ;
else
V_10 -> V_93 &= ~ V_212 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_94 ( struct V_193 * V_194 ,
struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
T_2 V_212 = V_194 -> V_205 ;
F_42 ( & V_10 -> V_50 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = F_92 ( V_10 , V_212 ) ;
F_44 ( & V_10 -> V_50 ) ;
return 0 ;
}
static int F_95 ( struct V_193 * V_194 ,
struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
T_2 V_212 = V_194 -> V_205 ;
int V_203 ;
unsigned int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_42 ( & V_10 -> V_50 ) ;
V_203 = ( int ) V_21 != F_92 ( V_10 , V_212 ) ;
if ( V_203 )
F_93 ( V_10 , V_212 , V_21 ) ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_96 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 , L_37 , L_38 , L_39 } ;
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = ( V_10 -> V_13 == V_18 ) ? 10 : 7 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_97 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
switch ( F_31 ( V_10 ) ) {
case 32000 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 0 ;
break;
case 44100 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 1 ;
break;
case 48000 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 2 ;
break;
case 64000 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 3 ;
break;
case 88200 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 4 ;
break;
case 96000 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 5 ;
break;
case 128000 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 7 ;
break;
case 176400 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 8 ;
break;
case 192000 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 9 ;
break;
default:
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_98 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
V_196 -> type = V_213 ;
V_196 -> V_59 = 1 ;
return 0 ;
}
static int F_99 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = V_10 -> V_119 ;
return 0 ;
}
static int F_100 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
static char * V_207 [] = { L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 , L_37 , L_38 , L_39 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = ( V_10 -> V_13 == V_18 ) ? 10 : 7 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_101 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
switch ( F_32 ( V_10 ) ) {
case 32000 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 0 ;
break;
case 44100 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 1 ;
break;
case 48000 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 2 ;
break;
case 64000 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 3 ;
break;
case 88200 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 4 ;
break;
case 96000 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 5 ;
break;
case 128000 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 7 ;
break;
case 176400 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 8 ;
break;
case 192000 :
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 9 ;
break;
default:
V_199 -> V_200 . V_209 . V_211 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_102 ( struct V_10 * V_10 )
{
if ( V_10 -> V_93 & V_115 )
return 0 ;
else if ( F_32 ( V_10 ) != V_10 -> V_119 )
return 0 ;
return 1 ;
}
static int F_103 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_40 , L_41 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 2 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_104 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_102 ( V_10 ) ;
return 0 ;
}
static int F_105 ( struct V_10 * V_10 )
{
if ( V_10 -> V_93 & V_115 ) {
switch ( V_10 -> V_119 ) {
case 32000 :
return 1 ;
case 44100 :
return 2 ;
case 48000 :
return 3 ;
case 64000 :
return 4 ;
case 88200 :
return 5 ;
case 96000 :
return 6 ;
case 128000 :
return 7 ;
case 176400 :
return 8 ;
case 192000 :
return 9 ;
default:
return 3 ;
}
} else {
return 0 ;
}
}
static int F_106 ( struct V_10 * V_10 , int V_214 )
{
int V_110 ;
switch ( V_214 ) {
case V_215 :
if ( F_32 ( V_10 ) != 0 ) {
if ( ! F_48 ( V_10 , F_32 ( V_10 ) , 1 ) ) {
V_10 -> V_93 &= ~ V_115 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
}
return - 1 ;
case V_216 :
V_110 = 32000 ;
break;
case V_217 :
V_110 = 44100 ;
break;
case V_218 :
V_110 = 48000 ;
break;
case V_219 :
V_110 = 64000 ;
break;
case V_220 :
V_110 = 88200 ;
break;
case V_221 :
V_110 = 96000 ;
break;
case V_222 :
V_110 = 128000 ;
break;
case V_223 :
V_110 = 176400 ;
break;
case V_224 :
V_110 = 192000 ;
break;
default:
V_110 = 48000 ;
}
V_10 -> V_93 |= V_115 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
F_48 ( V_10 , V_110 , 1 ) ;
return 0 ;
}
static int F_107 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_42 , L_43 , L_44 , L_45 , L_46 , L_47 , L_48 , L_49 , L_50 , L_51 } ;
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
if ( V_10 -> V_13 == V_18 )
V_196 -> V_200 . V_209 . V_210 = 10 ;
else
V_196 -> V_200 . V_209 . V_210 = 7 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_108 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_105 ( V_10 ) ;
return 0 ;
}
static int F_109 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_10 -> V_13 == V_18 ) {
if ( V_21 > 9 )
V_21 = 9 ;
} else {
if ( V_21 > 6 )
V_21 = 6 ;
}
F_42 ( & V_10 -> V_50 ) ;
if ( V_21 != F_105 ( V_10 ) )
V_203 = ( F_106 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_110 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = V_10 -> V_225 ;
return 0 ;
}
static int F_111 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
V_203 = ( int ) V_199 -> V_200 . integer . V_200 [ 0 ] != V_10 -> V_225 ;
if ( V_203 )
V_10 -> V_225 = ! ! V_199 -> V_200 . integer . V_200 [ 0 ] ;
return V_203 ;
}
static int F_112 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_93 & V_226 ) {
case V_227 :
return 0 ;
case V_228 :
return 1 ;
case V_229 :
return 2 ;
default:
return 1 ;
}
}
static int F_113 ( struct V_10 * V_10 , int V_214 )
{
V_10 -> V_93 &= ~ V_226 ;
switch ( V_214 ) {
case 0 :
V_10 -> V_93 |= V_227 ;
break;
case 1 :
V_10 -> V_93 |= V_228 ;
break;
case 2 :
V_10 -> V_93 |= V_229 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_114 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_52 , L_53 , L_54 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 3 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_115 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_112 ( V_10 ) ;
return 0 ;
}
static int F_116 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_42 ( & V_10 -> V_50 ) ;
if ( V_21 != F_112 ( V_10 ) )
V_203 = ( F_113 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_117 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_93 & V_230 ) {
case V_231 :
return 0 ;
case V_232 :
return 1 ;
case V_233 :
return 2 ;
default:
return 1 ;
}
}
static int F_118 ( struct V_10 * V_10 , int V_214 )
{
V_10 -> V_93 &= ~ V_230 ;
switch ( V_214 ) {
case 0 :
V_10 -> V_93 |= V_231 ;
break;
case 1 :
V_10 -> V_93 |= V_232 ;
break;
case 2 :
V_10 -> V_93 |= V_233 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_119 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_55 , L_53 , L_56 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 3 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_120 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_117 ( V_10 ) ;
return 0 ;
}
static int F_121 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_42 ( & V_10 -> V_50 ) ;
if ( V_21 != F_117 ( V_10 ) )
V_203 = ( F_118 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_122 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_93 & V_234 ) {
case V_235 :
return 0 ;
case V_236 :
return 1 ;
case V_237 :
return 2 ;
default:
return 0 ;
}
}
static int F_123 ( struct V_10 * V_10 , int V_214 )
{
V_10 -> V_93 &= ~ V_234 ;
switch ( V_214 ) {
case 0 :
V_10 -> V_93 |= V_235 ;
break;
case 1 :
V_10 -> V_93 |= V_236 ;
break;
case 2 :
V_10 -> V_93 |= V_237 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_124 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_57 , L_58 , L_59 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 3 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_125 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_122 ( V_10 ) ;
return 0 ;
}
static int F_126 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_42 ( & V_10 -> V_50 ) ;
if ( V_21 != F_122 ( V_10 ) )
V_203 = ( F_123 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_127 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_93 & V_238 ) {
case V_239 :
return V_240 ;
case V_241 :
return V_242 ;
case V_243 :
return V_244 ;
case V_245 :
return V_246 ;
case V_247 :
return V_248 ;
case V_249 :
return V_250 ;
default:
return V_248 ;
}
return 0 ;
}
static int F_128 ( struct V_10 * V_10 , int V_251 )
{
V_10 -> V_93 &= ~ V_238 ;
switch ( V_251 ) {
case V_240 :
V_10 -> V_93 &= ~ V_238 ;
break;
case V_242 :
V_10 -> V_93 |= V_241 ;
break;
case V_244 :
V_10 -> V_93 |= V_243 ;
break;
case V_246 :
V_10 -> V_93 |= V_245 ;
break;
case V_248 :
V_10 -> V_93 |= V_247 ;
break;
case V_250 :
V_10 -> V_93 |= V_249 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_129 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_60 , L_61 , L_62 , L_63 , L_64 , L_65 } ;
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_196 -> V_200 . V_209 . V_210 = 6 ;
break;
case V_14 :
V_196 -> V_200 . V_209 . V_210 = 4 ;
break;
case V_18 :
V_196 -> V_200 . V_209 . V_210 = 3 ;
break;
default:
return - V_120 ;
}
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_130 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_127 ( V_10 ) ;
return 0 ;
}
static int F_131 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 , V_252 ;
unsigned int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_252 = 6 ;
break;
case V_14 :
V_252 = 4 ;
break;
case V_18 :
V_252 = 3 ;
break;
default:
return - V_29 ;
}
V_21 = V_199 -> V_200 . V_209 . V_211 [ 0 ] % V_252 ;
F_42 ( & V_10 -> V_50 ) ;
V_203 = ( int ) V_21 != F_127 ( V_10 ) ;
F_128 ( V_10 , V_21 ) ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_33 ( struct V_10 * V_10 )
{
unsigned int V_83 = F_10 ( V_10 , V_54 ) ;
switch ( V_83 & V_253 ) {
case V_254 :
return V_255 ;
case V_256 :
return V_257 ;
case V_258 :
return V_85 ;
case V_253 :
return V_259 ;
case V_260 :
return V_118 ;
case V_261 :
return V_262 ;
case V_263 :
return V_264 ;
default:
return V_255 ;
}
return 0 ;
}
static int F_132 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_60 , L_63 , L_61 , L_36 , L_62 , L_64 , L_65 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 7 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_133 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_33 ( V_10 ) ;
return 0 ;
}
static int F_134 ( struct V_10 * V_10 , int V_265 )
{
if ( V_265 )
V_10 -> V_95 = 1 ;
else
V_10 -> V_95 = 0 ;
return 0 ;
}
static int F_135 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
F_42 ( & V_10 -> V_50 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = V_10 -> V_95 ;
F_44 ( & V_10 -> V_50 ) ;
return 0 ;
}
static int F_136 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
unsigned int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_42 ( & V_10 -> V_50 ) ;
V_203 = ( int ) V_21 != V_10 -> V_95 ;
F_134 ( V_10 , V_21 ) ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_137 ( struct V_10 * V_10 , int V_266 )
{
if ( V_266 )
V_10 -> V_267 = 1 ;
else
V_10 -> V_267 = 0 ;
return 0 ;
}
static int F_138 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
F_42 ( & V_10 -> V_50 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = V_10 -> V_267 ;
F_44 ( & V_10 -> V_50 ) ;
return 0 ;
}
static int F_139 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
unsigned int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_42 ( & V_10 -> V_50 ) ;
V_203 = ( int ) V_21 != V_10 -> V_267 ;
F_137 ( V_10 , V_21 ) ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_140 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
V_196 -> type = V_213 ;
V_196 -> V_59 = 3 ;
V_196 -> V_200 . integer . V_268 = 0 ;
V_196 -> V_200 . integer . V_252 = 65536 ;
V_196 -> V_200 . integer . V_269 = 1 ;
return 0 ;
}
static int F_141 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_270 ;
int V_271 ;
int V_62 ;
V_270 = V_199 -> V_200 . integer . V_200 [ 0 ] ;
V_271 = V_199 -> V_200 . integer . V_200 [ 1 ] ;
if ( V_270 >= V_10 -> V_272 )
V_62 = F_6 ( V_10 , V_270 - V_10 -> V_272 , V_271 ) ;
else
V_62 = F_7 ( V_10 , V_270 , V_271 ) ;
F_42 ( & V_10 -> V_50 ) ;
V_199 -> V_200 . integer . V_200 [ 2 ] = F_28 ( V_10 , V_62 ) ;
F_44 ( & V_10 -> V_50 ) ;
return 0 ;
}
static int F_142 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
int V_270 ;
int V_271 ;
int V_273 ;
int V_62 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_270 = V_199 -> V_200 . integer . V_200 [ 0 ] ;
V_271 = V_199 -> V_200 . integer . V_200 [ 1 ] ;
if ( V_270 >= V_10 -> V_272 )
V_62 = F_6 ( V_10 , V_270 - V_10 -> V_272 , V_271 ) ;
else
V_62 = F_7 ( V_10 , V_270 , V_271 ) ;
V_273 = V_199 -> V_200 . integer . V_200 [ 2 ] ;
F_42 ( & V_10 -> V_50 ) ;
V_203 = V_273 != F_28 ( V_10 , V_62 ) ;
if ( V_203 )
F_29 ( V_10 , V_62 , V_273 ) ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_143 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_66 , L_67 , L_68 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 3 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_144 ( struct V_10 * V_10 )
{
int V_83 = F_10 ( V_10 , V_54 ) ;
if ( V_83 & V_274 ) {
if ( V_83 & V_275 )
return 2 ;
else
return 1 ;
} else
return 0 ;
return 0 ;
}
static int F_145 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_144 ( V_10 ) ;
return 0 ;
}
static int F_146 ( struct V_10 * V_10 )
{
int V_69 = F_10 ( V_10 , V_24 ) ;
if ( V_69 & V_73 )
return 0 ;
else {
if ( V_69 & V_276 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_147 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_146 ( V_10 ) ;
return 0 ;
}
static int F_148 ( struct V_10 * V_10 )
{
int V_69 = F_10 ( V_10 , V_24 ) ;
if ( V_69 & V_277 ) {
if ( V_69 & V_278 )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_149 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_148 ( V_10 ) ;
return 0 ;
}
static int F_150 ( struct V_10 * V_10 , int V_279 )
{
int V_69 = F_10 ( V_10 , V_24 ) ;
if ( V_69 & ( V_280 >> V_279 ) ) {
if ( V_69 & ( V_281 >> V_279 ) )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_151 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
int V_282 ;
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_282 = V_199 -> V_139 . V_283 - 1 ;
F_47 ( V_282 < 0 ) ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
if ( V_282 >= 3 )
return - V_120 ;
break;
case V_14 :
case V_18 :
if ( V_282 >= 1 )
return - V_120 ;
break;
default:
return - V_29 ;
}
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_150 ( V_10 , V_282 ) ;
return 0 ;
}
static int F_152 ( struct V_10 * V_10 )
{
T_4 V_108 ;
unsigned int V_100 = V_10 -> V_100 ;
int V_119 = V_10 -> V_119 ;
if ( ! V_100 )
return 0 ;
V_108 = V_111 ;
V_108 = F_46 ( V_108 , V_100 ) ;
if ( V_119 >= 112000 )
V_108 *= 4 ;
else if ( V_119 >= 56000 )
V_108 *= 2 ;
return ( ( int ) V_108 ) - V_119 ;
}
static int F_153 ( struct V_10 * V_10 , int V_284 )
{
int V_110 = V_10 -> V_119 + V_284 ;
F_45 ( V_10 , V_110 ) ;
return 0 ;
}
static int F_154 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
V_196 -> type = V_213 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . integer . V_268 = - 5000 ;
V_196 -> V_200 . integer . V_252 = 5000 ;
return 0 ;
}
static int F_155 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_152 ( V_10 ) ;
return 0 ;
}
static int F_156 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
F_42 ( & V_10 -> V_50 ) ;
if ( V_21 != F_152 ( V_10 ) )
V_203 = ( F_153 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_157 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_93 & V_285 ) {
case V_286 :
return 0 ;
case V_287 :
return 2 ;
case V_288 :
return 3 ;
case V_289 :
return 4 ;
}
return 1 ;
}
static int F_158 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_157 ( V_10 ) ;
return 0 ;
}
static int F_159 ( struct V_10 * V_10 , int V_214 )
{
V_10 -> V_93 &= ~ V_285 ;
switch ( V_214 ) {
case 0 :
V_10 -> V_93 |= V_286 ;
break;
case 1 :
break;
case 2 :
V_10 -> V_93 |= V_287 ;
break;
case 3 :
V_10 -> V_93 |= V_288 ;
break;
case 4 :
V_10 -> V_93 |= V_289 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_160 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
if ( V_21 < 0 )
V_21 = 0 ;
if ( V_21 > 4 )
V_21 = 4 ;
F_42 ( & V_10 -> V_50 ) ;
if ( V_21 != F_157 ( V_10 ) )
V_203 = ( F_159 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_161 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_69 , L_70 , L_71 , L_72 , L_73 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 5 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_162 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_93 & V_290 ) {
case V_291 :
return 0 ;
case V_292 :
return 2 ;
case V_293 :
return 3 ;
case V_294 :
return 4 ;
}
return 1 ;
}
static int F_163 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_162 ( V_10 ) ;
return 0 ;
}
static int F_164 ( struct V_10 * V_10 , int V_214 )
{
V_10 -> V_93 &= ~ V_290 ;
switch ( V_214 ) {
case 0 :
V_10 -> V_93 |= V_291 ;
break;
case 1 :
break;
case 2 :
V_10 -> V_93 |= V_292 ;
break;
case 3 :
V_10 -> V_93 |= V_293 ;
break;
case 4 :
V_10 -> V_93 |= V_294 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_165 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
if ( V_21 < 0 )
V_21 = 0 ;
if ( V_21 > 4 )
V_21 = 4 ;
F_42 ( & V_10 -> V_50 ) ;
if ( V_21 != F_162 ( V_10 ) )
V_203 = ( F_164 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_166 ( struct V_10 * V_10 )
{
return ( V_10 -> V_93 & V_295 ) ? 1 : 0 ;
}
static int F_167 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = F_166 ( V_10 ) ;
return 0 ;
}
static int F_168 ( struct V_10 * V_10 , int V_296 )
{
if ( V_296 )
V_10 -> V_93 |= V_295 ;
else
V_10 -> V_93 &= ~ V_295 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_169 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
unsigned int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_42 ( & V_10 -> V_50 ) ;
V_203 = ( int ) V_21 != F_166 ( V_10 ) ;
F_168 ( V_10 , V_21 ) ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_170 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_74 , L_75 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 2 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_171 ( struct V_10 * V_10 )
{
return ( V_10 -> V_93 & V_297 ) ? 1 : 0 ;
}
static int F_172 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = F_171 ( V_10 ) ;
return 0 ;
}
static int F_173 ( struct V_10 * V_10 , int V_296 )
{
if ( V_296 )
V_10 -> V_93 |= V_297 ;
else
V_10 -> V_93 &= ~ V_297 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_174 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_10 * V_10 = F_78 ( V_194 ) ;
int V_203 ;
unsigned int V_21 ;
if ( ! F_30 ( V_10 ) )
return - V_130 ;
V_21 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_42 ( & V_10 -> V_50 ) ;
V_203 = ( int ) V_21 != F_171 ( V_10 ) ;
F_173 ( V_10 , V_21 ) ;
F_44 ( & V_10 -> V_50 ) ;
return V_203 ;
}
static int F_175 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_74 , L_75 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 2 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_176 ( struct V_171 * V_172 , struct V_10 * V_10 )
{
unsigned int V_279 ;
int V_298 ;
struct V_193 * V_299 ;
if ( V_10 -> V_13 == V_16 ) {
for ( V_279 = 0 ; V_279 < F_177 ( V_300 ) ; V_279 ++ ) {
V_298 = F_178 ( V_172 , V_299 = F_179 ( & V_300 [ V_279 ] , V_10 ) ) ;
if ( V_298 < 0 )
return V_298 ;
}
return 0 ;
}
for ( V_279 = 0 ; V_279 < F_177 ( V_301 ) ; V_279 ++ ) {
if ( ( V_298 = F_178 ( V_172 , V_299 = F_179 ( & V_301 [ V_279 ] , V_10 ) ) ) < 0 )
return V_298 ;
if ( V_279 == 1 )
V_10 -> V_302 = V_299 ;
}
V_303 . V_175 = L_76 ;
V_303 . V_283 = 1 ;
if ( ( V_298 = F_178 ( V_172 , V_299 = F_179 ( & V_303 , V_10 ) ) ) )
return V_298 ;
if ( V_10 -> V_13 == V_15 || V_10 -> V_13 == V_19 ) {
for ( V_279 = 1 ; V_279 < 3 ; ++ V_279 ) {
V_303 . V_283 = V_279 + 1 ;
if ( ( V_298 = F_178 ( V_172 , V_299 = F_179 ( & V_303 , V_10 ) ) ) )
return V_298 ;
}
}
if ( V_10 -> V_13 == V_18 ) {
for ( V_279 = 0 ; V_279 < F_177 ( V_304 ) ; V_279 ++ ) {
if ( ( V_298 = F_178 ( V_172 , V_299 = F_179 ( & V_304 [ V_279 ] , V_10 ) ) ) < 0 )
return V_298 ;
}
}
if ( V_10 -> V_13 == V_18 || V_10 -> V_13 == V_19 ) {
if ( ( V_298 = F_178 ( V_172 , V_299 = F_179 ( & V_305 , V_10 ) ) ) < 0 )
return V_298 ;
}
return 0 ;
}
static void
F_180 ( struct V_306 * V_307 , struct V_308 * V_309 )
{
struct V_10 * V_10 = V_307 -> V_164 ;
unsigned int V_69 ;
unsigned int V_83 ;
char * V_310 ;
char * V_311 ;
char * V_312 ;
char * V_313 ;
int V_314 ;
V_69 = F_10 ( V_10 , V_24 ) ;
V_83 = F_10 ( V_10 , V_54 ) ;
F_181 ( V_309 , L_77 , V_10 -> V_315 ,
V_10 -> V_172 -> V_316 + 1 ) ;
F_181 ( V_309 , L_78 ,
V_10 -> V_317 , V_10 -> V_105 ) ;
F_181 ( V_309 , L_79 ,
V_10 -> V_318 , V_10 -> V_319 , ( unsigned long ) V_10 -> V_22 ) ;
F_181 ( V_309 , L_80 , V_10 -> V_93 ) ;
F_181 ( V_309 , L_81 ,
V_10 -> V_46 ) ;
F_181 ( V_309 , L_82 , V_69 ) ;
F_181 ( V_309 , L_83 , V_83 ) ;
if ( F_12 ( V_10 ) ) {
F_181 ( V_309 , L_84
L_85 ) ;
return;
}
if ( F_25 ( V_10 , 0 ) ) {
if ( V_10 -> V_27 & V_58 ) {
if ( F_17 ( V_10 ) != 0 ) {
F_181 ( V_309 , L_86
L_87
L_88 ) ;
return;
}
} else {
int V_298 = - V_120 ;
V_298 = F_26 ( V_10 ) ;
if ( V_298 < 0 ) {
F_181 ( V_309 ,
L_89
L_90 ) ;
return;
}
}
}
F_181 ( V_309 , L_91 , F_10 ( V_10 , V_61 ) & 0xff ) ;
F_181 ( V_309 , L_92 , F_10 ( V_10 , V_148 ) ) ;
F_181 ( V_309 , L_93 , F_10 ( V_10 , V_145 ) ) ;
F_181 ( V_309 , L_94 , F_10 ( V_10 , V_147 ) ) ;
F_181 ( V_309 , L_95 , F_10 ( V_10 , V_144 ) ) ;
F_181 ( V_309 , L_96 , V_10 -> V_267 ? L_97 : L_98 ) ;
F_181 ( V_309 , L_99 ) ;
V_314 = 1 << ( 6 + F_35 ( V_10 -> V_93 & V_109 ) ) ;
F_181 ( V_309 , L_100 , V_314 , ( unsigned long ) V_10 -> V_92 ) ;
F_181 ( V_309 , L_101 , F_36 ( V_10 ) ) ;
F_181 ( V_309 , L_102 , V_10 -> V_95 ? L_97 : L_98 ) ;
F_181 ( V_309 , L_103 , ( V_10 -> V_93 & V_320 ) ? L_97 : L_98 ) ;
F_181 ( V_309 , L_104 , ( V_83 & V_321 ) | ( V_83 & V_56 ) << 1 | ( V_83 & V_55 ) << 2 ) ;
F_181 ( V_309 , L_99 ) ;
switch ( F_105 ( V_10 ) ) {
case V_215 :
V_313 = L_42 ;
break;
case V_216 :
V_313 = L_105 ;
break;
case V_217 :
V_313 = L_44 ;
break;
case V_218 :
V_313 = L_106 ;
break;
case V_219 :
V_313 = L_107 ;
break;
case V_220 :
V_313 = L_47 ;
break;
case V_221 :
V_313 = L_108 ;
break;
case V_222 :
V_313 = L_49 ;
break;
case V_223 :
V_313 = L_50 ;
break;
case V_224 :
V_313 = L_109 ;
break;
default:
V_313 = L_110 ;
}
F_181 ( V_309 , L_111 , V_313 ) ;
if ( F_102 ( V_10 ) )
V_312 = L_41 ;
else
V_312 = L_40 ;
switch ( F_127 ( V_10 ) ) {
case V_248 :
V_310 = L_112 ;
break;
case V_250 :
V_310 = L_63 ;
break;
case V_246 :
V_310 = L_113 ;
break;
case V_240 :
V_310 = L_62 ;
break;
case V_242 :
V_310 = L_64 ;
break;
case V_244 :
V_310 = L_65 ;
break;
default:
V_310 = L_112 ;
break;
}
F_181 ( V_309 , L_114 , V_310 ) ;
switch ( F_33 ( V_10 ) ) {
case V_255 :
V_311 = L_112 ;
break;
case V_257 :
V_311 = L_63 ;
break;
case V_85 :
V_311 = L_113 ;
break;
case V_259 :
V_311 = L_36 ;
break;
case V_118 :
V_311 = L_62 ;
break;
case V_262 :
V_311 = L_64 ;
break;
case V_264 :
V_311 = L_65 ;
break;
default:
V_311 = L_115 ;
break;
}
F_181 ( V_309 , L_116 , V_311 ) ;
F_181 ( V_309 , L_117 , F_32 ( V_10 ) ) ;
F_181 ( V_309 , L_118 , V_312 ) ;
F_181 ( V_309 , L_119 , V_10 -> V_119 ) ;
F_181 ( V_309 , L_120 , V_10 -> V_225 ? L_121 : L_122 ) ;
F_181 ( V_309 , L_99 ) ;
if ( V_10 -> V_13 != V_16 ) {
switch ( F_85 ( V_10 ) ) {
case V_322 :
F_181 ( V_309 , L_123 ) ;
break;
case V_323 :
F_181 ( V_309 , L_124 ) ;
break;
case V_324 :
F_181 ( V_309 , L_125 ) ;
break;
case V_325 :
F_181 ( V_309 , L_126 ) ;
break;
default:
F_181 ( V_309 , L_127 ) ;
break;
}
}
if ( V_16 == V_10 -> V_13 ) {
if ( V_10 -> V_93 & V_295 )
F_181 ( V_309 , L_128 ) ;
else
F_181 ( V_309 , L_129 ) ;
if ( V_10 -> V_93 & V_297 )
F_181 ( V_309 , L_130 ) ;
else
F_181 ( V_309 , L_131 ) ;
switch ( V_10 -> V_93 & V_285 ) {
case V_286 :
F_181 ( V_309 , L_132 ) ;
break;
case V_326 :
F_181 ( V_309 , L_133 ) ;
break;
case V_287 :
F_181 ( V_309 , L_134 ) ;
break;
case V_288 :
F_181 ( V_309 , L_135 ) ;
break;
case V_289 :
F_181 ( V_309 , L_136 ) ;
break;
default:
F_181 ( V_309 , L_137 ) ;
}
switch ( V_10 -> V_93 & V_290 ) {
case V_291 :
F_181 ( V_309 , L_138 ) ;
break;
case V_327 :
F_181 ( V_309 , L_139 ) ;
break;
case V_292 :
F_181 ( V_309 , L_140 ) ;
break;
case V_293 :
F_181 ( V_309 , L_141 ) ;
break;
case V_294 :
F_181 ( V_309 , L_142 ) ;
break;
default:
F_181 ( V_309 , L_143 ) ;
}
} else {
if ( V_10 -> V_93 & V_328 )
F_181 ( V_309 , L_144 ) ;
else
F_181 ( V_309 , L_145 ) ;
if ( V_10 -> V_93 & V_187 )
F_181 ( V_309 , L_146 ) ;
else
F_181 ( V_309 , L_147 ) ;
if ( V_10 -> V_93 & V_191 )
F_181 ( V_309 , L_148 ) ;
else
F_181 ( V_309 , L_149 ) ;
if ( V_10 -> V_93 & V_189 )
F_181 ( V_309 , L_150 ) ;
else
F_181 ( V_309 , L_151 ) ;
V_314 = F_31 ( V_10 ) ;
if ( V_314 != 0 )
F_181 ( V_309 , L_152 , V_314 ) ;
else
F_181 ( V_309 , L_153 ) ;
}
F_181 ( V_309 , L_99 ) ;
V_314 = V_69 & V_281 ;
if ( V_69 & V_280 )
F_181 ( V_309 , L_154 , V_314 ? L_68 : L_67 ) ;
else
F_181 ( V_309 , L_155 ) ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_314 = V_69 & V_329 ;
if ( V_69 & V_330 )
F_181 ( V_309 , L_156 , V_314 ? L_68 : L_67 ) ;
else
F_181 ( V_309 , L_157 ) ;
V_314 = V_69 & V_331 ;
if ( V_69 & V_332 )
F_181 ( V_309 , L_158 , V_314 ? L_68 : L_67 ) ;
else
F_181 ( V_309 , L_159 ) ;
break;
default:
break;
}
V_314 = V_69 & V_276 ;
if ( V_69 & V_73 )
F_181 ( V_309 , L_160 ) ;
else
F_181 ( V_309 , L_161 , V_314 ? L_68 : L_67 ) ;
V_314 = V_83 & V_275 ;
if ( V_83 & V_274 )
F_181 ( V_309 , L_162 , V_314 ? L_68 : L_67 ) ;
else
F_181 ( V_309 , L_163 ) ;
V_314 = V_69 & V_278 ;
if ( V_69 & V_277 )
F_181 ( V_309 , L_164 , V_314 ? L_68 : L_67 ) ;
else
F_181 ( V_309 , L_165 ) ;
F_181 ( V_309 , L_99 ) ;
if ( V_10 -> V_13 == V_18 ) {
char * V_333 ;
switch ( F_117 ( V_10 ) ) {
case 0 :
V_333 = L_55 ;
break;
case 1 :
V_333 = L_53 ;
break;
default:
V_333 = L_56 ;
break;
}
F_181 ( V_309 , L_166 , V_333 ) ;
switch ( F_112 ( V_10 ) ) {
case 0 :
V_333 = L_52 ;
break;
case 1 :
V_333 = L_53 ;
break;
default:
V_333 = L_55 ;
break;
}
F_181 ( V_309 , L_167 , V_333 ) ;
switch ( F_122 ( V_10 ) ) {
case 0 :
V_333 = L_57 ;
break;
case 1 :
V_333 = L_58 ;
break;
default:
V_333 = L_59 ;
break;
}
F_181 ( V_309 , L_168 , V_333 ) ;
F_181 ( V_309 , L_169 ,
F_92 ( V_10 , V_334 ) ?
L_170 : L_171 ) ;
if ( V_10 -> V_93 & V_335 )
F_181 ( V_309 , L_172 ) ;
else
F_181 ( V_309 , L_173 ) ;
F_181 ( V_309 , L_99 ) ;
}
}
static void F_182 ( struct V_10 * V_10 )
{
struct V_306 * V_307 ;
if ( ! F_183 ( V_10 -> V_172 , L_174 , & V_307 ) )
F_184 ( V_307 , V_10 , F_180 ) ;
}
static void F_185 ( struct V_10 * V_10 )
{
F_4 ( & V_10 -> V_336 , V_10 -> V_2 ) ;
F_4 ( & V_10 -> V_337 , V_10 -> V_2 ) ;
}
static int F_186 ( struct V_10 * V_10 )
{
unsigned long V_338 , V_339 ;
if ( F_1 ( V_10 -> V_2 , & V_10 -> V_336 , V_106 ) < 0 ||
F_1 ( V_10 -> V_2 , & V_10 -> V_337 , V_106 ) < 0 ) {
if ( V_10 -> V_336 . V_9 )
F_5 ( & V_10 -> V_336 ) ;
F_187 ( V_26 L_175 , V_10 -> V_315 ) ;
return - V_8 ;
}
V_339 = F_188 ( V_10 -> V_336 . V_62 , 0x10000ul ) ;
V_338 = F_188 ( V_10 -> V_337 . V_62 , 0x10000ul ) ;
F_8 ( V_10 , V_340 , V_339 ) ;
F_8 ( V_10 , V_341 , V_338 ) ;
V_10 -> V_317 = V_10 -> V_336 . V_9 + ( V_339 - V_10 -> V_336 . V_62 ) ;
V_10 -> V_105 = V_10 -> V_337 . V_9 + ( V_338 - V_10 -> V_337 . V_62 ) ;
return 0 ;
}
static int F_22 ( struct V_10 * V_10 )
{
unsigned int V_23 ;
V_10 -> V_93 = V_115 |
V_342 |
F_43 ( 7 ) |
V_320 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
#ifdef F_20
V_10 -> V_46 = V_47 ;
#else
V_10 -> V_46 = 0 ;
#endif
if ( V_10 -> V_13 == V_19 )
F_189 ( V_10 ) ;
else
F_8 ( V_10 , V_39 , V_10 -> V_46 ) ;
F_37 ( V_10 ) ;
F_34 ( V_10 ) ;
for ( V_23 = 0 ; V_23 < V_63 ; ++ V_23 )
V_10 -> V_64 [ V_23 ] = V_343 ;
for ( V_23 = 0 ; V_23 < ( ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) ? 1352 : V_63 ) ; ++ V_23 ) {
if ( F_29 ( V_10 , V_23 , V_343 ) )
return - V_29 ;
}
if ( V_10 -> V_13 == V_18 ) {
V_10 -> V_93 |= ( V_228 | V_232 | V_235 ) ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
}
F_48 ( V_10 , 48000 , 1 ) ;
return 0 ;
}
static void F_190 ( unsigned long V_344 )
{
struct V_10 * V_10 = (struct V_10 * ) V_344 ;
if ( V_10 -> V_173 [ 0 ] . V_156 )
F_57 ( & V_10 -> V_173 [ 0 ] ) ;
if ( V_10 -> V_173 [ 1 ] . V_156 )
F_57 ( & V_10 -> V_173 [ 1 ] ) ;
}
static T_5 F_191 ( int V_318 , void * V_345 )
{
struct V_10 * V_10 = (struct V_10 * ) V_345 ;
unsigned int V_69 ;
int V_346 ;
int V_347 ;
int V_348 ;
unsigned int V_349 ;
unsigned int V_350 ;
int V_351 = 0 ;
V_69 = F_10 ( V_10 , V_24 ) ;
V_346 = V_69 & V_352 ;
V_347 = V_69 & V_353 ;
V_348 = V_69 & V_354 ;
if ( ! V_346 && ! V_347 && ! V_348 )
return V_355 ;
F_8 ( V_10 , V_356 , 0 ) ;
V_349 = F_10 ( V_10 , V_145 ) & 0xff ;
V_350 = F_10 ( V_10 , V_144 ) & 0xff ;
if ( ! ( V_10 -> V_27 & V_48 ) )
return V_357 ;
if ( V_346 ) {
if ( V_10 -> V_358 )
F_192 ( V_10 -> V_359 -> V_360 [ V_361 ] . V_160 ) ;
if ( V_10 -> V_362 )
F_192 ( V_10 -> V_359 -> V_360 [ V_363 ] . V_160 ) ;
}
if ( V_347 && V_349 ) {
if ( V_10 -> V_267 ) {
V_10 -> V_93 &= ~ V_158 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
V_10 -> V_173 [ 0 ] . V_156 = 1 ;
V_351 = 1 ;
} else {
F_57 ( & V_10 -> V_173 [ 0 ] ) ;
}
}
if ( V_10 -> V_13 != V_14 && V_10 -> V_13 != V_16 && V_10 -> V_13 != V_18 && V_348 && V_350 ) {
if ( V_10 -> V_267 ) {
V_10 -> V_93 &= ~ V_157 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
V_10 -> V_173 [ 1 ] . V_156 = 1 ;
V_351 = 1 ;
} else {
F_57 ( & V_10 -> V_173 [ 1 ] ) ;
}
}
if ( V_10 -> V_267 && V_351 )
F_193 ( & V_10 -> V_165 ) ;
return V_357 ;
}
static T_3 F_194 ( struct V_364 * V_160 )
{
struct V_10 * V_10 = F_195 ( V_160 ) ;
return F_36 ( V_10 ) ;
}
static char * F_196 ( struct V_10 * V_10 ,
int V_365 ,
int V_366 )
{
int V_367 ;
if ( F_47 ( V_366 < 0 || V_366 >= V_10 -> V_272 ) )
return NULL ;
if ( ( V_367 = V_10 -> V_132 [ V_366 ] ) < 0 )
return NULL ;
if ( V_365 == V_361 )
return V_10 -> V_317 + ( V_367 * V_368 ) ;
else
return V_10 -> V_105 + ( V_367 * V_368 ) ;
}
static int F_197 ( struct V_364 * V_160 , int V_366 ,
T_3 V_369 , void T_6 * V_370 , T_3 V_59 )
{
struct V_10 * V_10 = F_195 ( V_160 ) ;
char * V_371 ;
if ( F_47 ( V_369 + V_59 > V_368 / 4 ) )
return - V_120 ;
V_371 = F_196 ( V_10 , V_160 -> V_372 -> V_365 , V_366 ) ;
if ( F_47 ( ! V_371 ) )
return - V_29 ;
if ( F_198 ( V_371 + V_369 * 4 , V_370 , V_59 * 4 ) )
return - V_373 ;
return V_59 ;
}
static int F_199 ( struct V_364 * V_160 , int V_366 ,
T_3 V_369 , void T_6 * V_374 , T_3 V_59 )
{
struct V_10 * V_10 = F_195 ( V_160 ) ;
char * V_371 ;
if ( F_47 ( V_369 + V_59 > V_368 / 4 ) )
return - V_120 ;
V_371 = F_196 ( V_10 , V_160 -> V_372 -> V_365 , V_366 ) ;
if ( F_47 ( ! V_371 ) )
return - V_29 ;
if ( F_200 ( V_374 , V_371 + V_369 * 4 , V_59 * 4 ) )
return - V_373 ;
return V_59 ;
}
static int F_201 ( struct V_364 * V_160 , int V_366 ,
T_3 V_369 , T_3 V_59 )
{
struct V_10 * V_10 = F_195 ( V_160 ) ;
char * V_371 ;
V_371 = F_196 ( V_10 , V_160 -> V_372 -> V_365 , V_366 ) ;
if ( F_47 ( ! V_371 ) )
return - V_29 ;
memset ( V_371 + V_369 * 4 , 0 , V_59 * 4 ) ;
return V_59 ;
}
static int F_202 ( struct V_364 * V_160 )
{
struct V_375 * V_376 = V_160 -> V_376 ;
struct V_10 * V_10 = F_195 ( V_160 ) ;
struct V_364 * V_377 ;
if ( V_160 -> V_365 == V_363 )
V_377 = V_10 -> V_358 ;
else
V_377 = V_10 -> V_362 ;
if ( V_10 -> V_378 )
V_376 -> V_69 -> V_379 = F_36 ( V_10 ) ;
else
V_376 -> V_69 -> V_379 = 0 ;
if ( V_377 ) {
struct V_364 * V_101 ;
struct V_375 * V_380 = V_377 -> V_376 ;
F_203 (s, substream) {
if ( V_101 == V_377 ) {
V_380 -> V_69 -> V_379 = V_376 -> V_69 -> V_379 ;
break;
}
}
}
return 0 ;
}
static int F_204 ( struct V_364 * V_160 ,
struct V_381 * V_382 )
{
struct V_10 * V_10 = F_195 ( V_160 ) ;
int V_298 ;
T_7 V_383 ;
T_7 V_384 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_25 ( V_10 , 1 ) )
return - V_29 ;
F_42 ( & V_10 -> V_50 ) ;
if ( V_160 -> V_372 -> V_365 == V_363 ) {
V_10 -> V_93 &= ~ ( V_187 | V_189 | V_191 ) ;
F_8 ( V_10 , V_104 , V_10 -> V_93 |= V_10 -> V_204 ) ;
V_383 = V_10 -> V_67 ;
V_384 = V_10 -> V_68 ;
} else {
V_383 = V_10 -> V_68 ;
V_384 = V_10 -> V_67 ;
}
if ( ( V_384 > 0 ) && ( V_383 != V_384 ) ) {
if ( F_205 ( V_382 ) != V_10 -> V_119 ) {
F_44 ( & V_10 -> V_50 ) ;
F_206 ( V_382 , V_385 ) ;
return - V_130 ;
}
if ( F_207 ( V_382 ) != V_10 -> V_92 / 4 ) {
F_44 ( & V_10 -> V_50 ) ;
F_206 ( V_382 , V_386 ) ;
return - V_130 ;
}
F_44 ( & V_10 -> V_50 ) ;
return 0 ;
} else {
F_44 ( & V_10 -> V_50 ) ;
}
F_42 ( & V_10 -> V_50 ) ;
if ( ! V_10 -> V_225 ) {
if ( ( V_298 = F_48 ( V_10 , F_205 ( V_382 ) , 0 ) ) < 0 ) {
F_44 ( & V_10 -> V_50 ) ;
F_206 ( V_382 , V_385 ) ;
return V_298 ;
}
}
F_44 ( & V_10 -> V_50 ) ;
if ( ( V_298 = F_41 ( V_10 , F_207 ( V_382 ) ) ) < 0 ) {
F_206 ( V_382 , V_386 ) ;
return V_298 ;
}
return 0 ;
}
static int F_208 ( struct V_364 * V_160 ,
struct V_387 * V_388 )
{
struct V_10 * V_10 = F_195 ( V_160 ) ;
int V_367 ;
if ( F_47 ( V_388 -> V_366 >= V_10 -> V_272 ) )
return - V_120 ;
if ( ( V_367 = V_10 -> V_132 [ V_388 -> V_366 ] ) < 0 )
return - V_120 ;
V_388 -> V_282 = V_367 * V_368 ;
V_388 -> V_389 = 0 ;
V_388 -> V_269 = 32 ;
return 0 ;
}
static int F_209 ( struct V_364 * V_160 ,
unsigned int V_390 , void * V_344 )
{
switch ( V_390 ) {
case V_391 :
return F_202 ( V_160 ) ;
case V_392 :
return F_208 ( V_160 , V_344 ) ;
default:
break;
}
return F_210 ( V_160 , V_390 , V_344 ) ;
}
static int F_211 ( struct V_364 * V_160 , int V_390 )
{
struct V_10 * V_10 = F_195 ( V_160 ) ;
struct V_364 * V_377 ;
int V_378 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_25 ( V_10 , 0 ) )
return - V_29 ;
F_212 ( & V_10 -> V_50 ) ;
V_378 = V_10 -> V_378 ;
switch ( V_390 ) {
case V_393 :
V_378 |= 1 << V_160 -> V_365 ;
break;
case V_394 :
V_378 &= ~ ( 1 << V_160 -> V_365 ) ;
break;
default:
F_213 () ;
F_214 ( & V_10 -> V_50 ) ;
return - V_120 ;
}
if ( V_160 -> V_365 == V_363 )
V_377 = V_10 -> V_358 ;
else
V_377 = V_10 -> V_362 ;
if ( V_377 ) {
struct V_364 * V_101 ;
F_203 (s, substream) {
if ( V_101 == V_377 ) {
F_215 ( V_101 , V_160 ) ;
if ( V_390 == V_393 )
V_378 |= 1 << V_101 -> V_365 ;
else
V_378 &= ~ ( 1 << V_101 -> V_365 ) ;
goto V_395;
}
}
if ( V_390 == V_393 ) {
if ( ! ( V_378 & ( 1 << V_363 ) ) &&
V_160 -> V_365 == V_361 )
F_40 ( V_10 ) ;
} else {
if ( V_378 &&
V_160 -> V_365 == V_363 )
F_40 ( V_10 ) ;
}
} else {
if ( V_160 -> V_365 == V_361 )
F_40 ( V_10 ) ;
}
V_395:
F_215 ( V_160 , V_160 ) ;
if ( ! V_10 -> V_378 && V_378 )
F_38 ( V_10 ) ;
else if ( V_10 -> V_378 && ! V_378 )
F_39 ( V_10 ) ;
V_10 -> V_378 = V_378 ;
F_214 ( & V_10 -> V_50 ) ;
return 0 ;
}
static int F_216 ( struct V_364 * V_160 )
{
struct V_10 * V_10 = F_195 ( V_160 ) ;
int V_396 = 0 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_25 ( V_10 , 1 ) )
return - V_29 ;
F_42 ( & V_10 -> V_50 ) ;
if ( ! V_10 -> V_378 )
F_37 ( V_10 ) ;
F_44 ( & V_10 -> V_50 ) ;
return V_396 ;
}
static int F_217 ( struct V_381 * V_382 ,
struct V_397 * V_398 )
{
struct V_10 * V_10 = V_398 -> V_399 ;
struct V_400 * V_401 = F_218 ( V_382 , V_402 ) ;
if ( V_10 -> V_13 == V_18 ) {
unsigned int V_403 [ 3 ] ;
V_403 [ 0 ] = V_10 -> V_404 ;
V_403 [ 1 ] = V_10 -> V_405 ;
V_403 [ 2 ] = V_10 -> V_406 ;
return F_219 ( V_401 , 3 , V_403 , 0 ) ;
} else {
unsigned int V_403 [ 2 ] ;
V_403 [ 0 ] = V_10 -> V_405 ;
V_403 [ 1 ] = V_10 -> V_406 ;
return F_219 ( V_401 , 2 , V_403 , 0 ) ;
}
}
static int F_220 ( struct V_381 * V_382 ,
struct V_397 * V_398 )
{
unsigned int V_403 [ 3 ] ;
struct V_10 * V_10 = V_398 -> V_399 ;
struct V_400 * V_401 = F_218 ( V_382 , V_402 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_403 [ 0 ] = V_10 -> V_407 ;
V_403 [ 1 ] = V_10 -> V_408 ;
V_403 [ 2 ] = V_10 -> V_409 ;
return F_219 ( V_401 , 3 , V_403 , 0 ) ;
} else {
V_403 [ 0 ] = V_10 -> V_408 ;
V_403 [ 1 ] = V_10 -> V_409 ;
}
return F_219 ( V_401 , 2 , V_403 , 0 ) ;
}
static int F_221 ( struct V_381 * V_382 ,
struct V_397 * V_398 )
{
struct V_10 * V_10 = V_398 -> V_399 ;
struct V_400 * V_401 = F_218 ( V_382 , V_402 ) ;
struct V_400 * V_410 = F_218 ( V_382 , V_385 ) ;
if ( V_410 -> V_268 > 96000 && V_10 -> V_13 == V_18 ) {
struct V_400 V_411 = {
. V_268 = V_10 -> V_404 ,
. V_252 = V_10 -> V_404 ,
. integer = 1 ,
} ;
return F_222 ( V_401 , & V_411 ) ;
} else if ( V_410 -> V_268 > 48000 && V_410 -> V_252 <= 96000 ) {
struct V_400 V_411 = {
. V_268 = V_10 -> V_405 ,
. V_252 = V_10 -> V_405 ,
. integer = 1 ,
} ;
return F_222 ( V_401 , & V_411 ) ;
} else if ( V_410 -> V_252 < 64000 ) {
struct V_400 V_411 = {
. V_268 = V_10 -> V_406 ,
. V_252 = V_10 -> V_406 ,
. integer = 1 ,
} ;
return F_222 ( V_401 , & V_411 ) ;
}
return 0 ;
}
static int F_223 ( struct V_381 * V_382 ,
struct V_397 * V_398 )
{
struct V_10 * V_10 = V_398 -> V_399 ;
struct V_400 * V_401 = F_218 ( V_382 , V_402 ) ;
struct V_400 * V_410 = F_218 ( V_382 , V_385 ) ;
if ( V_410 -> V_268 > 96000 && V_10 -> V_13 == V_18 ) {
struct V_400 V_411 = {
. V_268 = V_10 -> V_407 ,
. V_252 = V_10 -> V_407 ,
. integer = 1 ,
} ;
return F_222 ( V_401 , & V_411 ) ;
} else if ( V_410 -> V_268 > 48000 && V_410 -> V_252 <= 96000 ) {
struct V_400 V_411 = {
. V_268 = V_10 -> V_408 ,
. V_252 = V_10 -> V_408 ,
. integer = 1 ,
} ;
return F_222 ( V_401 , & V_411 ) ;
} else if ( V_410 -> V_252 < 64000 ) {
struct V_400 V_411 = {
. V_268 = V_10 -> V_409 ,
. V_252 = V_10 -> V_409 ,
. integer = 1 ,
} ;
return F_222 ( V_401 , & V_411 ) ;
}
return 0 ;
}
static int F_224 ( struct V_381 * V_382 ,
struct V_397 * V_398 )
{
struct V_10 * V_10 = V_398 -> V_399 ;
struct V_400 * V_401 = F_218 ( V_382 , V_402 ) ;
struct V_400 * V_410 = F_218 ( V_382 , V_385 ) ;
if ( V_401 -> V_268 >= V_10 -> V_409 ) {
struct V_400 V_411 = {
. V_268 = 32000 ,
. V_252 = 48000 ,
. integer = 1 ,
} ;
return F_222 ( V_410 , & V_411 ) ;
} else if ( V_401 -> V_252 <= V_10 -> V_407 && V_10 -> V_13 == V_18 ) {
struct V_400 V_411 = {
. V_268 = 128000 ,
. V_252 = 192000 ,
. integer = 1 ,
} ;
return F_222 ( V_410 , & V_411 ) ;
} else if ( V_401 -> V_252 <= V_10 -> V_408 ) {
struct V_400 V_411 = {
. V_268 = 64000 ,
. V_252 = 96000 ,
. integer = 1 ,
} ;
return F_222 ( V_410 , & V_411 ) ;
}
return 0 ;
}
static int F_225 ( struct V_381 * V_382 ,
struct V_397 * V_398 )
{
struct V_10 * V_10 = V_398 -> V_399 ;
struct V_400 * V_401 = F_218 ( V_382 , V_402 ) ;
struct V_400 * V_410 = F_218 ( V_382 , V_385 ) ;
if ( V_401 -> V_268 >= V_10 -> V_406 ) {
struct V_400 V_411 = {
. V_268 = 32000 ,
. V_252 = 48000 ,
. integer = 1 ,
} ;
return F_222 ( V_410 , & V_411 ) ;
} else if ( V_401 -> V_252 <= V_10 -> V_404 && V_10 -> V_13 == V_18 ) {
struct V_400 V_411 = {
. V_268 = 128000 ,
. V_252 = 192000 ,
. integer = 1 ,
} ;
return F_222 ( V_410 , & V_411 ) ;
} else if ( V_401 -> V_252 <= V_10 -> V_405 ) {
struct V_400 V_411 = {
. V_268 = 64000 ,
. V_252 = 96000 ,
. integer = 1 ,
} ;
return F_222 ( V_410 , & V_411 ) ;
}
return 0 ;
}
static int F_226 ( struct V_364 * V_160 )
{
struct V_10 * V_10 = F_195 ( V_160 ) ;
struct V_375 * V_376 = V_160 -> V_376 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_25 ( V_10 , 1 ) )
return - V_29 ;
F_42 ( & V_10 -> V_50 ) ;
F_227 ( V_160 ) ;
V_376 -> V_412 = V_413 ;
V_376 -> V_414 = V_10 -> V_105 ;
V_376 -> V_415 = V_106 ;
V_10 -> V_67 = V_416 -> V_417 ;
V_10 -> V_362 = V_160 ;
F_44 ( & V_10 -> V_50 ) ;
F_228 ( V_376 , 0 , 32 , 24 ) ;
F_229 ( V_376 , 0 , V_386 , & V_418 ) ;
if ( V_10 -> V_225 ) {
V_376 -> V_412 . V_419 = V_376 -> V_412 . V_420 = V_10 -> V_119 ;
} else if ( V_10 -> V_13 == V_18 ) {
V_376 -> V_412 . V_420 = 192000 ;
V_376 -> V_412 . V_421 = V_422 ;
F_229 ( V_376 , 0 , V_385 , & V_423 ) ;
}
if ( V_10 -> V_13 == V_18 ) {
V_376 -> V_412 . V_424 = V_10 -> V_407 ;
V_376 -> V_412 . V_425 = V_10 -> V_409 ;
}
F_230 ( V_376 , 0 , V_402 ,
F_220 , V_10 ,
V_402 , - 1 ) ;
F_230 ( V_376 , 0 , V_402 ,
F_223 , V_10 ,
V_385 , - 1 ) ;
F_230 ( V_376 , 0 , V_385 ,
F_224 , V_10 ,
V_402 , - 1 ) ;
if ( V_16 != V_10 -> V_13 ) {
V_10 -> V_204 = V_10 -> V_202 ;
V_10 -> V_302 -> V_426 [ 0 ] . V_427 &= ~ V_428 ;
F_231 ( V_10 -> V_172 , V_429 |
V_430 , & V_10 -> V_302 -> V_139 ) ;
}
return 0 ;
}
static int F_232 ( struct V_364 * V_160 )
{
struct V_10 * V_10 = F_195 ( V_160 ) ;
F_42 ( & V_10 -> V_50 ) ;
V_10 -> V_67 = - 1 ;
V_10 -> V_362 = NULL ;
F_44 ( & V_10 -> V_50 ) ;
if ( V_16 != V_10 -> V_13 ) {
V_10 -> V_302 -> V_426 [ 0 ] . V_427 |= V_428 ;
F_231 ( V_10 -> V_172 , V_429 |
V_430 , & V_10 -> V_302 -> V_139 ) ;
}
return 0 ;
}
static int F_233 ( struct V_364 * V_160 )
{
struct V_10 * V_10 = F_195 ( V_160 ) ;
struct V_375 * V_376 = V_160 -> V_376 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_25 ( V_10 , 1 ) )
return - V_29 ;
F_42 ( & V_10 -> V_50 ) ;
F_227 ( V_160 ) ;
V_376 -> V_412 = V_431 ;
V_376 -> V_414 = V_10 -> V_317 ;
V_376 -> V_415 = V_106 ;
V_10 -> V_68 = V_416 -> V_417 ;
V_10 -> V_358 = V_160 ;
F_44 ( & V_10 -> V_50 ) ;
F_228 ( V_376 , 0 , 32 , 24 ) ;
F_229 ( V_376 , 0 , V_386 , & V_418 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_376 -> V_412 . V_424 = V_10 -> V_404 ;
V_376 -> V_412 . V_425 = V_10 -> V_406 ;
V_376 -> V_412 . V_420 = 192000 ;
V_376 -> V_412 . V_421 = V_422 ;
F_229 ( V_376 , 0 , V_385 , & V_423 ) ;
}
F_230 ( V_376 , 0 , V_402 ,
F_217 , V_10 ,
V_402 , - 1 ) ;
F_230 ( V_376 , 0 , V_402 ,
F_221 , V_10 ,
V_385 , - 1 ) ;
F_230 ( V_376 , 0 , V_385 ,
F_225 , V_10 ,
V_402 , - 1 ) ;
return 0 ;
}
static int F_234 ( struct V_364 * V_160 )
{
struct V_10 * V_10 = F_195 ( V_160 ) ;
F_42 ( & V_10 -> V_50 ) ;
V_10 -> V_68 = - 1 ;
V_10 -> V_358 = NULL ;
F_44 ( & V_10 -> V_50 ) ;
return 0 ;
}
static inline int F_235 ( void T_6 * V_432 , void T_8 * V_370 )
{
T_2 V_21 = F_11 ( V_370 ) ;
return F_200 ( V_432 , & V_21 , 4 ) ;
}
static inline int F_236 ( void T_6 * V_432 , void T_8 * V_433 , void T_8 * V_434 )
{
T_2 V_435 , V_436 ;
T_4 V_437 ;
V_435 = F_11 ( V_433 ) ;
V_436 = F_11 ( V_434 ) ;
V_437 = ( ( T_4 ) V_436 << 32 ) | V_435 ;
return F_200 ( V_432 , & V_437 , 8 ) ;
}
static inline int F_237 ( void T_6 * V_432 , void T_8 * V_433 , void T_8 * V_434 )
{
T_2 V_435 , V_436 ;
T_4 V_437 ;
V_435 = F_11 ( V_433 ) & 0xffffff00 ;
V_436 = F_11 ( V_434 ) & 0xffffff00 ;
V_437 = ( ( T_4 ) V_436 << 32 ) | V_435 ;
return F_200 ( V_432 , & V_437 , 8 ) ;
}
static int F_238 ( struct V_10 * V_10 , struct V_438 T_6 * V_439 )
{
int V_440 = 0 ;
int V_23 , V_441 , V_442 , V_443 ;
if ( F_10 ( V_10 , V_24 ) & V_444 )
V_440 = 1 ;
V_442 = V_440 ? 14 : 26 ;
for ( V_23 = 0 , V_441 = 0 ; V_23 < 26 ; ++ V_23 ) {
if ( V_440 && ( V_23 & 4 ) )
continue;
V_443 = V_445 - V_441 * 4 ;
if ( F_235 ( & V_439 -> V_446 [ V_23 ] , V_10 -> V_22 + V_443 ) )
return - V_373 ;
V_443 -= V_442 * 4 ;
if ( F_235 ( & V_439 -> V_447 [ V_23 ] , V_10 -> V_22 + V_443 ) )
return - V_373 ;
V_443 -= V_442 * 4 ;
if ( F_235 ( & V_439 -> V_448 [ V_23 ] , V_10 -> V_22 + V_443 ) )
return - V_373 ;
V_443 = V_449 + V_441 * 8 ;
if ( F_237 ( & V_439 -> V_450 [ V_23 ] , V_10 -> V_22 + V_443 ,
V_10 -> V_22 + V_443 + 4 ) )
return - V_373 ;
V_443 += V_442 * 8 ;
if ( F_237 ( & V_439 -> V_451 [ V_23 ] , V_10 -> V_22 + V_443 ,
V_10 -> V_22 + V_443 + 4 ) )
return - V_373 ;
V_443 += V_442 * 8 ;
if ( F_237 ( & V_439 -> V_452 [ V_23 ] , V_10 -> V_22 + V_443 ,
V_10 -> V_22 + V_443 + 4 ) )
return - V_373 ;
V_441 ++ ;
}
return 0 ;
}
static int F_239 ( struct V_10 * V_10 , struct V_438 T_6 * V_439 )
{
int V_23 , V_441 ;
struct V_453 T_8 * V_454 ;
int V_440 = 0 ;
if ( F_10 ( V_10 , V_24 ) & V_444 )
V_440 = 1 ;
V_454 = (struct V_453 T_8 * ) ( V_10 -> V_22 + V_455 ) ;
for ( V_23 = 0 , V_441 = 0 ; V_23 < 16 ; ++ V_23 , ++ V_441 ) {
if ( F_235 ( & V_439 -> V_446 [ V_23 ] , & V_454 -> V_456 [ V_441 ] ) )
return - V_373 ;
if ( F_235 ( & V_439 -> V_447 [ V_23 ] , & V_454 -> V_457 [ V_441 ] ) )
return - V_373 ;
if ( F_235 ( & V_439 -> V_448 [ V_23 ] , & V_454 -> V_458 [ V_441 ] ) )
return - V_373 ;
if ( F_236 ( & V_439 -> V_450 [ V_23 ] , & V_454 -> V_459 [ V_441 ] ,
& V_454 -> V_460 [ V_441 ] ) )
return - V_373 ;
if ( F_236 ( & V_439 -> V_451 [ V_23 ] , & V_454 -> V_461 [ V_441 ] ,
& V_454 -> V_462 [ V_441 ] ) )
return - V_373 ;
if ( F_236 ( & V_439 -> V_452 [ V_23 ] , & V_454 -> V_463 [ V_441 ] ,
& V_454 -> V_464 [ V_441 ] ) )
return - V_373 ;
if ( V_440 && V_23 == 3 ) V_23 += 4 ;
}
return 0 ;
}
static int F_240 ( struct V_10 * V_10 , struct V_438 T_6 * V_439 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < 26 ; V_23 ++ ) {
if ( F_235 ( & V_439 -> V_447 [ V_23 ] ,
V_10 -> V_22 + V_465 + V_23 * 4 ) )
return - V_373 ;
if ( F_235 ( & V_439 -> V_446 [ V_23 ] ,
V_10 -> V_22 + V_466 + V_23 * 4 ) )
return - V_373 ;
}
for ( V_23 = 0 ; V_23 < 28 ; V_23 ++ ) {
if ( F_235 ( & V_439 -> V_448 [ V_23 ] ,
V_10 -> V_22 + V_467 + V_23 * 4 ) )
return - V_373 ;
}
for ( V_23 = 0 ; V_23 < 26 ; ++ V_23 ) {
if ( F_236 ( & V_439 -> V_451 [ V_23 ] ,
V_10 -> V_22 + V_468 + V_23 * 8 + 4 ,
V_10 -> V_22 + V_468 + V_23 * 8 ) )
return - V_373 ;
if ( F_236 ( & V_439 -> V_450 [ V_23 ] ,
V_10 -> V_22 + V_469 + V_23 * 8 + 4 ,
V_10 -> V_22 + V_469 + V_23 * 8 ) )
return - V_373 ;
}
return 0 ;
}
static int F_241 ( struct V_470 * V_412 , struct V_471 * V_471 , unsigned int V_390 , unsigned long V_344 )
{
struct V_10 * V_10 = V_412 -> V_164 ;
void T_6 * V_472 = ( void T_6 * ) V_344 ;
int V_298 ;
switch ( V_390 ) {
case V_473 : {
struct V_438 T_6 * V_439 = (struct V_438 T_6 * ) V_344 ;
V_298 = F_12 ( V_10 ) ;
if ( V_298 < 0 )
return V_298 ;
V_298 = F_25 ( V_10 , 1 ) ;
if ( V_298 < 0 )
return V_298 ;
if ( ! ( V_10 -> V_27 & V_28 ) ) {
F_15 ( V_26 L_176 ) ;
return - V_120 ;
}
switch ( V_10 -> V_13 ) {
case V_19 :
return F_238 ( V_10 , V_439 ) ;
case V_18 :
return F_239 ( V_10 , V_439 ) ;
default:
return F_240 ( V_10 , V_439 ) ;
}
}
case V_474 : {
struct V_475 V_388 ;
unsigned long V_32 ;
int V_23 ;
V_298 = F_12 ( V_10 ) ;
if ( V_298 < 0 )
return V_298 ;
V_298 = F_25 ( V_10 , 1 ) ;
if ( V_298 < 0 )
return V_298 ;
memset ( & V_388 , 0 , sizeof( V_388 ) ) ;
F_21 ( & V_10 -> V_50 , V_32 ) ;
V_388 . V_310 = ( unsigned char ) F_127 ( V_10 ) ;
V_388 . V_476 = ( unsigned char ) F_144 ( V_10 ) ;
if ( V_10 -> V_13 != V_18 )
V_388 . V_477 = ( unsigned char ) F_148 ( V_10 ) ;
V_388 . V_478 = ( unsigned char ) F_146 ( V_10 ) ;
for ( V_23 = 0 ; V_23 < ( ( V_10 -> V_13 != V_14 && V_10 -> V_13 != V_16 && V_10 -> V_13 != V_18 ) ? 3 : 1 ) ; ++ V_23 )
V_388 . V_479 [ V_23 ] = ( unsigned char ) F_150 ( V_10 , V_23 ) ;
V_388 . V_480 = ( unsigned char ) F_85 ( V_10 ) ;
V_388 . V_481 = ( unsigned char ) F_92 ( V_10 ,
V_328 ) ;
V_388 . V_482 = ( unsigned char )
F_92 ( V_10 , V_187 ) ;
V_388 . V_483 = ( unsigned char )
F_92 ( V_10 , V_191 ) ;
V_388 . V_484 = ( unsigned char )
F_92 ( V_10 , V_189 ) ;
V_388 . V_485 = F_31 ( V_10 ) ;
V_388 . V_119 = V_10 -> V_119 ;
V_388 . V_486 = F_32 ( V_10 ) ;
V_388 . V_312 = ( unsigned char ) F_102 ( V_10 ) ;
V_388 . V_313 = ( unsigned char ) F_105 ( V_10 ) ;
V_388 . V_311 = ( unsigned char ) F_33 ( V_10 ) ;
V_388 . V_487 = ( unsigned char )
F_92 ( V_10 , V_320 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_388 . V_488 = ( unsigned char ) F_112 ( V_10 ) ;
V_388 . V_489 = ( unsigned char ) F_117 ( V_10 ) ;
V_388 . V_490 = ( unsigned char ) F_122 ( V_10 ) ;
V_388 . V_491 =
( unsigned char ) F_92 ( V_10 ,
V_334 ) ;
} else if ( V_10 -> V_13 == V_16 ) {
V_388 . V_488 = ( unsigned char ) F_157 ( V_10 ) ;
V_388 . V_489 = ( unsigned char ) F_162 ( V_10 ) ;
}
if ( V_10 -> V_13 == V_18 || V_10 -> V_13 == V_19 )
V_388 . V_492 =
( unsigned char ) F_92 ( V_10 ,
V_335 ) ;
F_23 ( & V_10 -> V_50 , V_32 ) ;
if ( F_200 ( V_472 , & V_388 , sizeof( V_388 ) ) )
return - V_373 ;
break;
}
case V_493 : {
struct V_494 V_495 ;
if ( V_10 -> V_13 != V_18 ) return - V_120 ;
V_495 . V_496 = V_10 -> V_406 - V_497 ;
V_495 . V_498 = V_10 -> V_409 - V_497 ;
if ( F_200 ( V_472 , & V_495 , sizeof( V_495 ) ) )
return - V_373 ;
break;
}
case V_499 : {
struct V_500 V_500 ;
int V_298 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) return - V_120 ;
if ( V_10 -> V_13 == V_501 ) {
if ( ( V_298 = F_24 ( V_10 ) ) < 0 )
return V_298 ;
}
memset ( & V_500 , 0 , sizeof( V_500 ) ) ;
V_500 . V_13 = V_10 -> V_13 ;
V_500 . V_17 = V_10 -> V_17 ;
if ( ( V_298 = F_200 ( V_472 , & V_500 , sizeof( V_500 ) ) ) )
return - V_373 ;
break;
}
case V_502 : {
struct V_503 T_6 * V_35 ;
T_2 T_6 * V_504 ;
int V_298 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) return - V_120 ;
if ( V_10 -> V_13 == V_501 ) return - V_120 ;
if ( V_10 -> V_27 & ( V_58 | V_28 ) )
return - V_130 ;
F_15 ( V_49 L_177 ) ;
V_35 = (struct V_503 T_6 * ) V_472 ;
if ( F_242 ( V_504 , & V_35 -> V_504 ) )
return - V_373 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( ! V_10 -> V_34 ) {
V_10 -> V_34 = F_243 ( V_45 ) ;
if ( ! V_10 -> V_34 )
return - V_8 ;
}
if ( F_198 ( V_10 -> V_34 , V_504 ,
V_45 ) ) {
F_244 ( V_10 -> V_34 ) ;
V_10 -> V_34 = NULL ;
return - V_373 ;
}
V_10 -> V_27 |= V_58 ;
if ( ( V_298 = F_17 ( V_10 ) ) < 0 )
return V_298 ;
if ( ! ( V_10 -> V_27 & V_48 ) ) {
if ( ( V_298 = F_245 ( V_10 ) ) < 0 )
return V_298 ;
F_246 ( V_10 ) ;
F_247 ( V_10 ) ;
if ( ( V_298 = F_248 ( V_10 -> V_172 , V_10 ) ) < 0 ) {
F_15 ( V_26 L_178 ) ;
return V_298 ;
}
}
break;
}
case V_505 : {
struct V_506 T_6 * V_507 = (struct V_506 T_6 * ) V_472 ;
if ( F_200 ( V_507 -> V_508 , V_10 -> V_64 , sizeof( unsigned short ) * V_63 ) )
return - V_373 ;
break;
}
default:
return - V_120 ;
}
return 0 ;
}
static int F_249 ( struct V_171 * V_172 , struct V_10 * V_10 )
{
struct V_470 * V_412 ;
int V_298 ;
if ( ( V_298 = F_250 ( V_172 , L_179 , 0 , & V_412 ) ) < 0 )
return V_298 ;
V_10 -> V_509 = V_412 ;
V_412 -> V_164 = V_10 ;
strcpy ( V_412 -> V_175 , L_180 ) ;
V_412 -> V_510 . V_511 = F_241 ;
V_412 -> V_510 . V_512 = F_241 ;
return 0 ;
}
static int F_251 ( struct V_171 * V_172 , struct V_10 * V_10 )
{
struct V_513 * V_359 ;
int V_298 ;
if ( ( V_298 = F_252 ( V_172 , V_10 -> V_315 , 0 , 1 , 1 , & V_359 ) ) < 0 )
return V_298 ;
V_10 -> V_359 = V_359 ;
V_359 -> V_164 = V_10 ;
strcpy ( V_359 -> V_175 , V_10 -> V_315 ) ;
F_253 ( V_359 , V_363 , & V_514 ) ;
F_253 ( V_359 , V_361 , & V_515 ) ;
V_359 -> V_180 = V_516 ;
return 0 ;
}
static void F_189 ( struct V_10 * V_10 )
{
V_10 -> V_46 |= V_517 ;
F_8 ( V_10 , V_39 , V_10 -> V_46 ) ;
}
static int F_245 ( struct V_10 * V_10 )
{
int V_23 ;
if ( F_18 ( V_10 , 0 , 100 ) ) {
F_15 ( V_26 L_181 ) ;
return - V_29 ;
}
for ( V_23 = 0 ; V_23 < V_10 -> V_272 ; ++ V_23 ) {
F_8 ( V_10 , V_518 + ( 4 * V_23 ) , 1 ) ;
F_8 ( V_10 , V_519 + ( 4 * V_23 ) , 1 ) ;
}
return 0 ;
}
static void F_246 ( struct V_10 * V_10 )
{
int V_69 , V_520 , V_521 ;
switch ( V_10 -> V_13 ) {
case V_15 :
V_10 -> V_315 = L_182 ;
V_10 -> V_406 = V_10 -> V_409 = V_522 ;
V_10 -> V_405 = V_10 -> V_408 = V_523 ;
break;
case V_19 :
V_10 -> V_315 = L_183 ;
V_10 -> V_406 = V_10 -> V_409 = V_524 ;
V_10 -> V_405 = V_10 -> V_408 = V_525 ;
break;
case V_18 :
V_69 = F_10 ( V_10 , V_24 ) ;
V_520 = ( V_69 & V_526 ) ? 0 : 4 ;
V_521 = ( V_69 & V_527 ) ? 0 : 4 ;
V_10 -> V_315 = L_184 ;
V_10 -> V_406 = V_497 + V_520 ;
V_10 -> V_405 = V_528 + V_520 ;
V_10 -> V_404 = V_529 + V_520 ;
V_10 -> V_409 = V_497 + V_521 ;
V_10 -> V_408 = V_528 + V_521 ;
V_10 -> V_407 = V_529 + V_521 ;
break;
case V_14 :
V_10 -> V_315 = L_185 ;
V_10 -> V_406 = V_10 -> V_409 = V_530 ;
V_10 -> V_405 = V_10 -> V_408 = V_531 ;
break;
case V_16 :
V_10 -> V_315 = L_186 ;
V_10 -> V_406 = V_532 - 1 ;
V_10 -> V_409 = V_532 ;
V_10 -> V_405 = V_532 - 1 ;
V_10 -> V_408 = V_532 ;
break;
default:
break;
}
}
static void F_247 ( struct V_10 * V_10 )
{
F_53 ( V_10 , 0 ) ;
F_53 ( V_10 , 1 ) ;
}
static int F_248 ( struct V_171 * V_172 , struct V_10 * V_10 )
{
int V_298 ;
if ( ( V_298 = F_251 ( V_172 , V_10 ) ) < 0 ) {
F_15 ( V_26 L_187 ) ;
return V_298 ;
}
if ( ( V_298 = F_70 ( V_172 , V_10 , 0 ) ) < 0 ) {
F_15 ( V_26 L_188 ) ;
return V_298 ;
}
if ( V_10 -> V_13 == V_15 || V_10 -> V_13 == V_19 ) {
if ( ( V_298 = F_70 ( V_172 , V_10 , 1 ) ) < 0 ) {
F_15 ( V_26 L_189 ) ;
return V_298 ;
}
}
if ( ( V_298 = F_176 ( V_172 , V_10 ) ) < 0 ) {
F_15 ( V_26 L_190 ) ;
return V_298 ;
}
F_182 ( V_10 ) ;
V_10 -> V_119 = - 1 ;
V_10 -> V_67 = - 1 ;
V_10 -> V_68 = - 1 ;
V_10 -> V_358 = NULL ;
V_10 -> V_362 = NULL ;
if ( ( V_298 = F_22 ( V_10 ) ) < 0 ) {
F_15 ( V_26 L_191 ) ;
return V_298 ;
}
if ( ! ( V_10 -> V_27 & V_48 ) ) {
strcpy ( V_172 -> V_174 , L_192 ) ;
sprintf ( V_172 -> V_533 , L_193 , V_10 -> V_315 ,
V_10 -> V_319 , V_10 -> V_318 ) ;
if ( ( V_298 = F_254 ( V_172 ) ) < 0 ) {
F_15 ( V_26 L_194 ) ;
return V_298 ;
}
V_10 -> V_27 |= V_48 ;
}
return 0 ;
}
static int F_26 ( struct V_10 * V_10 )
{
const char * V_534 ;
const struct V_35 * V_535 ;
int V_298 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
if ( V_10 -> V_13 == V_501 ) {
if ( ( V_298 = F_24 ( V_10 ) ) < 0 )
return V_298 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
}
switch ( V_10 -> V_13 ) {
case V_16 :
V_534 = L_195 ;
break;
case V_14 :
if ( V_10 -> V_17 == 0xa )
V_534 = L_196 ;
else
V_534 = L_197 ;
break;
case V_15 :
if ( V_10 -> V_17 == 0xa )
V_534 = L_198 ;
else
V_534 = L_199 ;
break;
default:
F_15 ( V_26 L_200 , V_10 -> V_13 ) ;
return - V_120 ;
}
if ( F_255 ( & V_535 , V_534 , & V_10 -> V_2 -> V_6 ) ) {
F_15 ( V_26 L_201 , V_534 ) ;
return - V_536 ;
}
if ( V_535 -> V_5 < V_45 ) {
F_15 ( V_26 L_202 ,
( int ) V_535 -> V_5 , V_45 ) ;
return - V_120 ;
}
V_10 -> V_35 = V_535 ;
V_10 -> V_27 |= V_58 ;
if ( ( V_298 = F_17 ( V_10 ) ) < 0 )
return V_298 ;
if ( ! ( V_10 -> V_27 & V_48 ) ) {
if ( ( V_298 = F_245 ( V_10 ) ) < 0 )
return V_298 ;
if ( ( V_298 = F_249 ( V_10 -> V_172 , V_10 ) ) < 0 ) {
F_15 ( V_26 L_203 ) ;
return V_298 ;
}
F_246 ( V_10 ) ;
F_247 ( V_10 ) ;
if ( ( V_298 = F_248 ( V_10 -> V_172 , V_10 ) ) < 0 ) {
F_15 ( V_26 L_178 ) ;
return V_298 ;
}
}
return 0 ;
}
static int F_256 ( struct V_171 * V_172 ,
struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_298 ;
int V_537 = 0 ;
int V_538 = 0 ;
V_10 -> V_318 = - 1 ;
V_10 -> V_27 = 0 ;
V_10 -> V_173 [ 0 ] . V_163 = NULL ;
V_10 -> V_173 [ 1 ] . V_163 = NULL ;
V_10 -> V_173 [ 0 ] . V_155 = NULL ;
V_10 -> V_173 [ 1 ] . V_155 = NULL ;
V_10 -> V_173 [ 0 ] . V_154 = NULL ;
V_10 -> V_173 [ 1 ] . V_154 = NULL ;
V_10 -> V_173 [ 0 ] . V_156 = 0 ;
V_10 -> V_173 [ 1 ] . V_156 = 0 ;
F_71 ( & V_10 -> V_173 [ 0 ] . V_50 ) ;
F_71 ( & V_10 -> V_173 [ 1 ] . V_50 ) ;
V_10 -> V_22 = NULL ;
V_10 -> V_93 = 0 ;
V_10 -> V_46 = 0 ;
V_10 -> V_13 = V_501 ;
V_10 -> V_272 = 26 ;
V_10 -> V_172 = V_172 ;
F_71 ( & V_10 -> V_50 ) ;
F_257 ( & V_10 -> V_165 , F_190 , ( unsigned long ) V_10 ) ;
F_258 ( V_10 -> V_2 , V_539 , & V_10 -> V_17 ) ;
V_10 -> V_17 &= 0xff ;
F_259 ( V_10 -> V_2 , V_540 , 0xFF ) ;
strcpy ( V_172 -> V_541 , L_204 ) ;
strcpy ( V_172 -> V_542 , L_205 ) ;
if ( V_10 -> V_17 < 0xa )
return - V_36 ;
else if ( V_10 -> V_17 < 0x64 )
V_10 -> V_315 = L_206 ;
else if ( V_10 -> V_17 < 0x96 ) {
V_10 -> V_315 = L_207 ;
V_537 = 1 ;
} else {
V_10 -> V_315 = L_208 ;
V_10 -> V_272 = 16 ;
V_538 = 1 ;
}
if ( ( V_298 = F_260 ( V_2 ) ) < 0 )
return V_298 ;
F_261 ( V_10 -> V_2 ) ;
if ( ( V_298 = F_262 ( V_2 , L_174 ) ) < 0 )
return V_298 ;
V_10 -> V_319 = F_263 ( V_2 , 0 ) ;
if ( ( V_10 -> V_22 = F_264 ( V_10 -> V_319 , V_543 ) ) == NULL ) {
F_15 ( V_26 L_209 , V_10 -> V_319 , V_10 -> V_319 + V_543 - 1 ) ;
return - V_130 ;
}
if ( F_265 ( V_2 -> V_318 , F_191 , V_544 ,
V_545 , V_10 ) ) {
F_15 ( V_26 L_210 , V_2 -> V_318 ) ;
return - V_130 ;
}
V_10 -> V_318 = V_2 -> V_318 ;
V_10 -> V_95 = 0 ;
V_10 -> V_267 = 1 ;
V_10 -> V_100 = 0 ;
if ( ( V_298 = F_186 ( V_10 ) ) < 0 )
return V_298 ;
if ( ! V_537 && ! V_538 ) {
V_298 = F_16 ( V_10 , 1000 , 10 ) ;
if ( V_298 < 0 )
return V_298 ;
if ( ( F_10 ( V_10 , V_24 ) & V_38 ) != 0 ) {
if ( ( V_298 = F_26 ( V_10 ) ) < 0 )
F_15 ( V_26 L_211 ) ;
else
return 0 ;
F_15 ( V_49 L_212 ) ;
if ( ( V_298 = F_249 ( V_172 , V_10 ) ) < 0 )
return V_298 ;
return 0 ;
} else {
F_15 ( V_49 L_213 ) ;
if ( F_10 ( V_10 , V_54 ) & V_55 )
V_10 -> V_13 = V_16 ;
else if ( F_10 ( V_10 , V_54 ) & V_56 )
V_10 -> V_13 = V_14 ;
else
V_10 -> V_13 = V_15 ;
}
}
if ( ( V_298 = F_245 ( V_10 ) ) != 0 )
return V_298 ;
if ( V_537 )
V_10 -> V_13 = V_19 ;
if ( V_538 )
V_10 -> V_13 = V_18 ;
if ( ( V_298 = F_249 ( V_172 , V_10 ) ) < 0 )
return V_298 ;
F_246 ( V_10 ) ;
F_247 ( V_10 ) ;
V_10 -> V_27 |= V_28 ;
if ( ( V_298 = F_248 ( V_172 , V_10 ) ) < 0 )
return V_298 ;
return 0 ;
}
static int F_266 ( struct V_10 * V_10 )
{
if ( V_10 -> V_319 ) {
F_60 ( & V_10 -> V_165 ) ;
V_10 -> V_93 &= ~ ( V_103 | V_102 | V_158 | V_157 ) ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
}
if ( V_10 -> V_318 >= 0 )
F_267 ( V_10 -> V_318 , ( void * ) V_10 ) ;
F_185 ( V_10 ) ;
if ( V_10 -> V_35 )
F_268 ( V_10 -> V_35 ) ;
F_244 ( V_10 -> V_34 ) ;
if ( V_10 -> V_22 )
F_269 ( V_10 -> V_22 ) ;
if ( V_10 -> V_319 )
F_270 ( V_10 -> V_2 ) ;
F_271 ( V_10 -> V_2 ) ;
return 0 ;
}
static void F_272 ( struct V_171 * V_172 )
{
struct V_10 * V_10 = V_172 -> V_164 ;
if ( V_10 )
F_266 ( V_10 ) ;
}
static int F_273 ( struct V_1 * V_2 ,
const struct V_546 * V_547 )
{
static int V_6 ;
struct V_10 * V_10 ;
struct V_171 * V_172 ;
int V_298 ;
if ( V_6 >= V_548 )
return - V_36 ;
if ( ! V_549 [ V_6 ] ) {
V_6 ++ ;
return - V_536 ;
}
V_298 = F_274 ( V_283 [ V_6 ] , V_139 [ V_6 ] , V_550 ,
sizeof( struct V_10 ) , & V_172 ) ;
if ( V_298 < 0 )
return V_298 ;
V_10 = V_172 -> V_164 ;
V_172 -> V_551 = F_272 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_2 = V_2 ;
F_275 ( V_172 , & V_2 -> V_6 ) ;
if ( ( V_298 = F_256 ( V_172 , V_10 ) ) < 0 ) {
F_276 ( V_172 ) ;
return V_298 ;
}
strcpy ( V_172 -> V_174 , L_192 ) ;
sprintf ( V_172 -> V_533 , L_193 , V_10 -> V_315 ,
V_10 -> V_319 , V_10 -> V_318 ) ;
if ( ( V_298 = F_254 ( V_172 ) ) < 0 ) {
F_276 ( V_172 ) ;
return V_298 ;
}
F_277 ( V_2 , V_172 ) ;
V_6 ++ ;
return 0 ;
}
static void F_278 ( struct V_1 * V_2 )
{
F_276 ( F_279 ( V_2 ) ) ;
}
