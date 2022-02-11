static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 )
{
V_4 -> V_6 . type = V_7 ;
V_4 -> V_6 . V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_4 , F_4 ( V_2 ) ) ) {
if ( V_4 -> V_8 >= V_5 )
return 0 ;
}
if ( F_5 ( V_7 , F_2 ( V_2 ) ,
V_5 , V_4 ) < 0 )
return - V_9 ;
return 0 ;
}
static void F_6 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
if ( V_4 -> V_10 ) {
V_4 -> V_6 . V_6 = NULL ;
F_7 ( V_4 , F_4 ( V_2 ) ) ;
}
}
static int F_8 ( struct V_11 * V_11 , int V_12 , int V_13 )
{
switch ( V_11 -> V_14 ) {
case V_15 :
case V_16 :
case V_17 :
default:
if ( V_11 -> V_18 == 0xa )
return ( 64 * V_13 ) + ( 32 + ( V_12 ) ) ;
else
return ( 52 * V_13 ) + ( 26 + ( V_12 ) ) ;
case V_19 :
return ( 32 * V_13 ) + ( 16 + ( V_12 ) ) ;
case V_20 :
return ( 52 * V_13 ) + ( 26 + ( V_12 ) ) ;
}
}
static int F_9 ( struct V_11 * V_11 , int V_12 , int V_13 )
{
switch ( V_11 -> V_14 ) {
case V_15 :
case V_16 :
case V_17 :
default:
if ( V_11 -> V_18 == 0xa )
return ( 64 * V_13 ) + V_12 ;
else
return ( 52 * V_13 ) + V_12 ;
case V_19 :
return ( 32 * V_13 ) + V_12 ;
case V_20 :
return ( 52 * V_13 ) + V_12 ;
}
}
static void F_10 ( struct V_11 * V_11 , int V_21 , int V_22 )
{
F_11 ( V_22 , V_11 -> V_23 + V_21 ) ;
}
static unsigned int F_12 ( struct V_11 * V_11 , int V_21 )
{
return F_13 ( V_11 -> V_23 + V_21 ) ;
}
static int F_14 ( struct V_11 * V_11 )
{
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) return 0 ;
if ( F_12 ( V_11 , V_24 ) & V_25 ) {
F_15 ( L_1 ) ;
V_11 -> V_26 &= ~ V_27 ;
return - V_28 ;
}
return 0 ;
}
static int F_16 ( struct V_11 * V_11 , unsigned int V_29 ,
unsigned int V_30 )
{
unsigned int V_31 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 )
return 0 ;
for ( V_31 = 0 ; V_31 != V_29 ; ++ V_31 ) {
if ( F_12 ( V_11 , V_24 ) & V_25 )
F_17 ( V_30 ) ;
else {
F_18 ( L_2 ,
V_31 * V_30 ) ;
return 0 ;
}
}
F_15 ( L_1 ) ;
V_11 -> V_26 &= ~ V_27 ;
return - V_28 ;
}
static int F_19 ( struct V_11 * V_11 ) {
int V_31 ;
unsigned long V_32 ;
const T_2 * V_33 ;
if ( V_11 -> V_34 )
V_33 = V_11 -> V_34 ;
else {
if ( ! V_11 -> V_35 )
return - V_36 ;
V_33 = ( T_2 * ) V_11 -> V_35 -> V_37 ;
if ( ! V_33 )
return - V_36 ;
}
if ( ( F_12 ( V_11 , V_24 ) & V_38 ) != 0 ) {
F_15 ( L_3 ) ;
F_10 ( V_11 , V_39 , V_40 ) ;
F_10 ( V_11 , V_41 , 0 ) ;
if ( F_20 ( V_11 , 0 , V_42 ) ) {
F_15 ( L_4 ) ;
return - V_28 ;
}
F_10 ( V_11 , V_39 , V_43 ) ;
for ( V_31 = 0 ; V_31 < V_44 / 4 ; ++ V_31 ) {
F_10 ( V_11 , V_41 , V_33 [ V_31 ] ) ;
if ( F_20 ( V_11 , 127 , V_42 ) ) {
F_15 ( L_5 ) ;
return - V_28 ;
}
}
F_21 ( 3 ) ;
if ( F_20 ( V_11 , 0 , V_42 ) ) {
F_15 ( L_6 ) ;
return - V_28 ;
}
#ifdef F_22
V_11 -> V_45 = V_46 ;
#else
V_11 -> V_45 = 0 ;
#endif
F_10 ( V_11 , V_39 , V_11 -> V_45 ) ;
F_15 ( L_7 ) ;
}
if ( V_11 -> V_26 & V_47 ) {
F_15 ( V_48 L_8 ) ;
F_23 ( & V_11 -> V_49 , V_32 ) ;
F_24 ( V_11 ) ;
F_25 ( & V_11 -> V_49 , V_32 ) ;
}
V_11 -> V_26 |= V_27 ;
return 0 ;
}
static int F_26 ( struct V_11 * V_11 )
{
if ( ( F_12 ( V_11 , V_24 ) & V_38 ) != 0 ) {
F_10 ( V_11 , V_39 , V_50 ) ;
F_10 ( V_11 , V_41 , 0 ) ;
if ( F_20 ( V_11 , 0 , V_51 ) < 0 )
return - V_28 ;
F_10 ( V_11 , V_39 , V_43 ) ;
F_10 ( V_11 , V_41 , 0 ) ;
if ( F_20 ( V_11 , 0 , V_51 ) ) {
F_10 ( V_11 , V_39 , V_52 ) ;
F_10 ( V_11 , V_39 , V_43 ) ;
if ( F_20 ( V_11 , 0 , V_51 ) )
V_11 -> V_14 = V_17 ;
else
V_11 -> V_14 = V_15 ;
} else {
V_11 -> V_14 = V_16 ;
}
} else {
if ( F_12 ( V_11 , V_53 ) & V_54 )
V_11 -> V_14 = V_17 ;
else if ( F_12 ( V_11 , V_53 ) & V_55 )
V_11 -> V_14 = V_15 ;
else
V_11 -> V_14 = V_16 ;
}
return 0 ;
}
static int F_27 ( struct V_11 * V_11 , int V_56 )
{
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 )
return 0 ;
if ( ( F_12 ( V_11 , V_24 ) & V_38 ) != 0 ) {
V_11 -> V_26 &= ~ V_27 ;
if ( ! V_56 )
return - V_28 ;
F_15 ( V_57 L_9 ) ;
if ( ! ( V_11 -> V_26 & V_58 ) ) {
if ( ! F_28 ( V_11 ) )
return 0 ;
F_15 ( V_57
L_10
L_11 ) ;
return - V_28 ;
}
if ( F_19 ( V_11 ) != 0 ) {
F_15 ( V_57
L_12
L_13 ) ;
return - V_28 ;
}
}
return 0 ;
}
static int F_20 ( struct V_11 * V_11 , int V_59 , int V_60 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_60 ; V_31 ++ ) {
if ( ( int ) ( F_12 ( V_11 , V_61 ) & 0xff ) <= V_59 )
return 0 ;
F_29 ( 100 ) ;
}
F_15 ( L_14 ,
V_59 , V_60 ) ;
return - 1 ;
}
static int F_30 ( struct V_11 * V_11 , unsigned int V_62 )
{
if ( V_62 >= V_63 )
return 0 ;
return V_11 -> V_64 [ V_62 ] ;
}
static int F_31 ( struct V_11 * V_11 , unsigned int V_62 , unsigned short V_37 )
{
unsigned int V_65 ;
if ( V_62 >= V_63 )
return - 1 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) {
if ( V_11 -> V_14 == V_19 && V_62 >= 512 )
return 0 ;
if ( V_11 -> V_14 == V_20 && V_62 >= 1352 )
return 0 ;
V_11 -> V_64 [ V_62 ] = V_37 ;
V_65 = V_62 / 2 ;
F_10 ( V_11 , 4096 + ( V_65 * 4 ) ,
( V_11 -> V_64 [ ( V_62 & 0x7fe ) + 1 ] << 16 ) +
V_11 -> V_64 [ V_62 & 0x7fe ] ) ;
return 0 ;
} else {
V_65 = ( V_62 << 16 ) + V_37 ;
if ( F_20 ( V_11 , 127 , V_42 ) )
return - 1 ;
F_10 ( V_11 , V_41 , V_65 ) ;
V_11 -> V_64 [ V_62 ] = V_37 ;
}
return 0 ;
}
static int F_32 ( struct V_11 * V_11 )
{
unsigned long V_32 ;
int V_66 = 1 ;
F_23 ( & V_11 -> V_49 , V_32 ) ;
if ( ( V_11 -> V_67 != V_11 -> V_68 ) &&
( V_11 -> V_67 >= 0 ) && ( V_11 -> V_68 >= 0 ) )
V_66 = 0 ;
F_25 ( & V_11 -> V_49 , V_32 ) ;
return V_66 ;
}
static int F_33 ( struct V_11 * V_11 )
{
unsigned int V_69 = F_12 ( V_11 , V_24 ) ;
unsigned int V_70 = ( V_69 & V_71 ) ;
if ( V_11 -> V_14 == V_19 )
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
if ( V_11 -> V_14 == V_19 ) return 128000 ;
break;
case V_81 :
if ( V_11 -> V_14 == V_19 ) return 176400 ;
break;
case V_82 :
if ( V_11 -> V_14 == V_19 ) return 192000 ;
break;
default:
break;
}
F_15 ( L_15 , V_70 , V_69 ) ;
return 0 ;
}
static int F_34 ( struct V_11 * V_11 )
{
unsigned int V_83 = F_12 ( V_11 , V_53 ) ;
unsigned int V_70 = V_83 & V_84 ;
if ( V_11 -> V_14 == V_19 &&
F_35 ( V_11 ) == V_85 )
return F_33 ( V_11 ) ;
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
static void F_36 ( struct V_11 * V_11 )
{
V_11 -> V_92 = 1 << ( ( F_37 ( V_11 -> V_93 ) + 8 ) ) ;
}
static T_3 F_38 ( struct V_11 * V_11 )
{
int V_94 ;
V_94 = F_12 ( V_11 , V_24 ) ;
if ( ! V_11 -> V_95 )
return ( V_94 & V_96 ) ? ( V_11 -> V_92 / 4 ) : 0 ;
V_94 &= V_97 ;
V_94 /= 4 ;
V_94 &= ( V_11 -> V_92 / 2 ) - 1 ;
return V_94 ;
}
static void F_39 ( struct V_11 * V_11 )
{
F_10 ( V_11 , V_98 , 0 ) ;
if ( V_11 -> V_14 == V_19 && V_11 -> V_18 >= 152 )
F_10 ( V_11 , V_99 , V_11 -> V_100 ) ;
}
static void F_40 ( struct V_11 * V_101 )
{
V_101 -> V_93 |= ( V_102 | V_103 ) ;
F_10 ( V_101 , V_104 , V_101 -> V_93 ) ;
}
static void F_41 ( struct V_11 * V_101 )
{
V_101 -> V_93 &= ~ ( V_103 | V_102 ) ;
F_10 ( V_101 , V_104 , V_101 -> V_93 ) ;
}
static void F_42 ( struct V_11 * V_11 )
{
memset ( V_11 -> V_105 , 0 , V_106 ) ;
}
static int F_43 ( struct V_11 * V_101 , unsigned int V_107 )
{
int V_108 ;
F_44 ( & V_101 -> V_49 ) ;
V_107 >>= 7 ;
V_108 = 0 ;
while ( V_107 ) {
V_108 ++ ;
V_107 >>= 1 ;
}
V_101 -> V_93 &= ~ V_109 ;
V_101 -> V_93 |= F_45 ( V_108 ) ;
F_10 ( V_101 , V_104 , V_101 -> V_93 ) ;
F_36 ( V_101 ) ;
F_46 ( & V_101 -> V_49 ) ;
return 0 ;
}
static void F_47 ( struct V_11 * V_11 , int V_110 )
{
T_4 V_108 ;
if ( V_110 >= 112000 )
V_110 /= 4 ;
else if ( V_110 >= 56000 )
V_110 /= 2 ;
V_108 = V_111 ;
V_108 = F_48 ( V_108 , V_110 ) ;
F_49 ( V_108 >> 32 ) ;
V_11 -> V_100 = V_108 ;
F_10 ( V_11 , V_99 , V_11 -> V_100 ) ;
}
static int F_50 ( struct V_11 * V_11 , int V_110 , int V_112 )
{
int V_113 = 0 ;
int V_114 ;
int V_70 ;
if ( ! ( V_11 -> V_93 & V_115 ) ) {
if ( V_112 ) {
F_15 ( V_57 L_16 ) ;
return - 1 ;
} else {
int V_116 = F_34 ( V_11 ) ;
int V_117 = F_33 ( V_11 ) ;
if ( ( V_117 == V_116 * 2 ) && ( F_35 ( V_11 ) >= V_118 ) )
F_15 ( V_48 L_17 ) ;
else if ( V_11 -> V_14 == V_19 && ( V_117 == V_116 * 4 ) && ( F_35 ( V_11 ) >= V_118 ) )
F_15 ( V_48 L_18 ) ;
else if ( V_110 != V_116 ) {
F_15 ( V_48 L_19 ) ;
return - 1 ;
}
}
}
V_114 = V_11 -> V_119 ;
if ( V_110 > 96000 && V_11 -> V_14 != V_19 )
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
if ( V_113 && ( V_11 -> V_68 >= 0 || V_11 -> V_67 >= 0 ) ) {
F_15 ( L_20 ,
V_11 -> V_68 ,
V_11 -> V_67 ) ;
return - V_130 ;
}
V_11 -> V_93 &= ~ V_131 ;
V_11 -> V_93 |= V_70 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
if ( V_11 -> V_14 == V_19 && V_11 -> V_18 >= 152 )
F_47 ( V_11 , V_110 ) ;
if ( V_110 >= 128000 ) {
V_11 -> V_132 = V_133 ;
} else if ( V_110 > 48000 ) {
if ( V_11 -> V_14 == V_19 )
V_11 -> V_132 = V_134 ;
else
V_11 -> V_132 = V_135 ;
} else {
switch ( V_11 -> V_14 ) {
case V_17 :
case V_15 :
V_11 -> V_132 = V_136 ;
break;
case V_16 :
case V_20 :
V_11 -> V_132 = V_137 ;
break;
case V_19 :
V_11 -> V_132 = V_138 ;
break;
default:
break;
}
}
V_11 -> V_119 = V_110 ;
return 0 ;
}
static unsigned char F_51 ( struct V_11 * V_11 , int V_139 )
{
if ( V_139 )
return F_12 ( V_11 , V_140 ) ;
else
return F_12 ( V_11 , V_141 ) ;
}
static void F_52 ( struct V_11 * V_11 , int V_139 , int V_22 )
{
if ( V_139 )
F_10 ( V_11 , V_142 , V_22 ) ;
else
F_10 ( V_11 , V_143 , V_22 ) ;
}
static int F_53 ( struct V_11 * V_11 , int V_139 )
{
if ( V_139 )
return ( F_12 ( V_11 , V_144 ) & 0xff ) ;
else
return ( F_12 ( V_11 , V_145 ) & 0xff ) ;
}
static int F_54 ( struct V_11 * V_11 , int V_139 )
{
int V_146 ;
if ( V_139 )
V_146 = F_12 ( V_11 , V_147 ) & 0xff ;
else
V_146 = F_12 ( V_11 , V_148 ) & 0xff ;
if ( V_146 < 128 )
return 128 - V_146 ;
else
return 0 ;
}
static void F_55 ( struct V_11 * V_11 , int V_139 )
{
while ( F_53 ( V_11 , V_139 ) )
F_51 ( V_11 , V_139 ) ;
}
static int F_56 ( struct V_149 * V_150 )
{
unsigned long V_32 ;
int V_151 ;
int V_152 ;
int V_31 ;
unsigned char V_153 [ 128 ] ;
F_23 ( & V_150 -> V_49 , V_32 ) ;
if ( V_150 -> V_154 ) {
if ( ! F_57 ( V_150 -> V_154 ) ) {
if ( ( V_151 = F_54 ( V_150 -> V_11 , V_150 -> V_139 ) ) > 0 ) {
if ( V_151 > ( int ) sizeof ( V_153 ) )
V_151 = sizeof ( V_153 ) ;
if ( ( V_152 = F_58 ( V_150 -> V_154 , V_153 , V_151 ) ) > 0 ) {
for ( V_31 = 0 ; V_31 < V_152 ; ++ V_31 )
F_52 ( V_150 -> V_11 , V_150 -> V_139 , V_153 [ V_31 ] ) ;
}
}
}
}
F_25 ( & V_150 -> V_49 , V_32 ) ;
return 0 ;
}
static int F_59 ( struct V_149 * V_150 )
{
unsigned char V_153 [ 128 ] ;
unsigned long V_32 ;
int V_151 ;
int V_31 ;
F_23 ( & V_150 -> V_49 , V_32 ) ;
if ( ( V_151 = F_53 ( V_150 -> V_11 , V_150 -> V_139 ) ) > 0 ) {
if ( V_150 -> V_155 ) {
if ( V_151 > ( int ) sizeof ( V_153 ) )
V_151 = sizeof ( V_153 ) ;
for ( V_31 = 0 ; V_31 < V_151 ; ++ V_31 )
V_153 [ V_31 ] = F_51 ( V_150 -> V_11 , V_150 -> V_139 ) ;
if ( V_151 )
F_60 ( V_150 -> V_155 , V_153 , V_151 ) ;
} else {
while ( -- V_151 )
F_51 ( V_150 -> V_11 , V_150 -> V_139 ) ;
}
}
V_150 -> V_156 = 0 ;
if ( V_150 -> V_139 )
V_150 -> V_11 -> V_93 |= V_157 ;
else
V_150 -> V_11 -> V_93 |= V_158 ;
F_10 ( V_150 -> V_11 , V_104 , V_150 -> V_11 -> V_93 ) ;
F_25 ( & V_150 -> V_49 , V_32 ) ;
return F_56 ( V_150 ) ;
}
static void F_61 ( struct V_159 * V_160 , int V_161 )
{
struct V_11 * V_11 ;
struct V_149 * V_150 ;
unsigned long V_32 ;
T_2 V_162 ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
V_11 = V_150 -> V_11 ;
V_162 = V_150 -> V_139 ? V_157 : V_158 ;
F_23 ( & V_11 -> V_49 , V_32 ) ;
if ( V_161 ) {
if ( ! ( V_11 -> V_93 & V_162 ) ) {
F_55 ( V_11 , V_150 -> V_139 ) ;
V_11 -> V_93 |= V_162 ;
}
} else {
V_11 -> V_93 &= ~ V_162 ;
F_62 ( & V_11 -> V_165 ) ;
}
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
F_25 ( & V_11 -> V_49 , V_32 ) ;
}
static void F_63 ( unsigned long V_37 )
{
struct V_149 * V_150 = (struct V_149 * ) V_37 ;
unsigned long V_32 ;
F_56 ( V_150 ) ;
F_23 ( & V_150 -> V_49 , V_32 ) ;
if ( V_150 -> V_166 ) {
V_150 -> V_167 . V_168 = 1 + V_169 ;
F_64 ( & V_150 -> V_167 ) ;
}
F_25 ( & V_150 -> V_49 , V_32 ) ;
}
static void F_65 ( struct V_159 * V_160 , int V_161 )
{
struct V_149 * V_150 ;
unsigned long V_32 ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
F_23 ( & V_150 -> V_49 , V_32 ) ;
if ( V_161 ) {
if ( ! V_150 -> V_166 ) {
F_66 ( & V_150 -> V_167 ) ;
V_150 -> V_167 . V_170 = F_63 ;
V_150 -> V_167 . V_37 = ( unsigned long ) V_150 ;
V_150 -> V_167 . V_168 = 1 + V_169 ;
F_64 ( & V_150 -> V_167 ) ;
V_150 -> V_166 ++ ;
}
} else {
if ( V_150 -> V_166 && -- V_150 -> V_166 <= 0 )
F_67 ( & V_150 -> V_167 ) ;
}
F_25 ( & V_150 -> V_49 , V_32 ) ;
if ( V_161 )
F_56 ( V_150 ) ;
}
static int F_68 ( struct V_159 * V_160 )
{
struct V_149 * V_150 ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
F_44 ( & V_150 -> V_49 ) ;
F_55 ( V_150 -> V_11 , V_150 -> V_139 ) ;
V_150 -> V_155 = V_160 ;
F_46 ( & V_150 -> V_49 ) ;
return 0 ;
}
static int F_69 ( struct V_159 * V_160 )
{
struct V_149 * V_150 ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
F_44 ( & V_150 -> V_49 ) ;
V_150 -> V_154 = V_160 ;
F_46 ( & V_150 -> V_49 ) ;
return 0 ;
}
static int F_70 ( struct V_159 * V_160 )
{
struct V_149 * V_150 ;
F_61 ( V_160 , 0 ) ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
F_44 ( & V_150 -> V_49 ) ;
V_150 -> V_155 = NULL ;
F_46 ( & V_150 -> V_49 ) ;
return 0 ;
}
static int F_71 ( struct V_159 * V_160 )
{
struct V_149 * V_150 ;
F_65 ( V_160 , 0 ) ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
F_44 ( & V_150 -> V_49 ) ;
V_150 -> V_154 = NULL ;
F_46 ( & V_150 -> V_49 ) ;
return 0 ;
}
static int F_72 ( struct V_171 * V_172 , struct V_11 * V_11 , int V_139 )
{
char V_153 [ 32 ] ;
V_11 -> V_173 [ V_139 ] . V_139 = V_139 ;
V_11 -> V_173 [ V_139 ] . V_163 = NULL ;
V_11 -> V_173 [ V_139 ] . V_155 = NULL ;
V_11 -> V_173 [ V_139 ] . V_154 = NULL ;
V_11 -> V_173 [ V_139 ] . V_11 = V_11 ;
V_11 -> V_173 [ V_139 ] . V_166 = 0 ;
V_11 -> V_173 [ V_139 ] . V_156 = 0 ;
F_73 ( & V_11 -> V_173 [ V_139 ] . V_49 ) ;
sprintf ( V_153 , L_21 , V_172 -> V_174 , V_139 + 1 ) ;
if ( F_74 ( V_172 , V_153 , V_139 , 1 , 1 , & V_11 -> V_173 [ V_139 ] . V_163 ) < 0 )
return - 1 ;
sprintf ( V_11 -> V_173 [ V_139 ] . V_163 -> V_175 , L_22 , V_139 + 1 ) ;
V_11 -> V_173 [ V_139 ] . V_163 -> V_164 = & V_11 -> V_173 [ V_139 ] ;
F_75 ( V_11 -> V_173 [ V_139 ] . V_163 , V_176 , & V_177 ) ;
F_75 ( V_11 -> V_173 [ V_139 ] . V_163 , V_178 , & V_179 ) ;
V_11 -> V_173 [ V_139 ] . V_163 -> V_180 |= V_181 |
V_182 |
V_183 ;
return 0 ;
}
static T_2 F_76 ( struct V_184 * V_185 )
{
T_2 V_22 = 0 ;
V_22 |= ( V_185 -> V_69 [ 0 ] & V_186 ) ? V_187 : 0 ;
V_22 |= ( V_185 -> V_69 [ 0 ] & V_188 ) ? V_189 : 0 ;
if ( V_22 & V_187 )
V_22 |= ( V_185 -> V_69 [ 0 ] & V_190 ) ? V_191 : 0 ;
else
V_22 |= ( V_185 -> V_69 [ 0 ] & V_192 ) ? V_191 : 0 ;
return V_22 ;
}
static void F_77 ( struct V_184 * V_185 , T_2 V_22 )
{
V_185 -> V_69 [ 0 ] = ( ( V_22 & V_187 ) ? V_186 : 0 ) |
( ( V_22 & V_189 ) ? V_188 : 0 ) ;
if ( V_22 & V_187 )
V_185 -> V_69 [ 0 ] |= ( V_22 & V_191 ) ? V_190 : 0 ;
else
V_185 -> V_69 [ 0 ] |= ( V_22 & V_191 ) ? V_192 : 0 ;
}
static int F_78 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
V_196 -> type = V_197 ;
V_196 -> V_59 = 1 ;
return 0 ;
}
static int F_79 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
F_77 ( & V_199 -> V_200 . V_201 , V_11 -> V_202 ) ;
return 0 ;
}
static int F_81 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
T_2 V_22 ;
V_22 = F_76 ( & V_199 -> V_200 . V_201 ) ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = V_22 != V_11 -> V_202 ;
V_11 -> V_202 = V_22 ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_82 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
V_196 -> type = V_197 ;
V_196 -> V_59 = 1 ;
return 0 ;
}
static int F_83 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
F_77 ( & V_199 -> V_200 . V_201 , V_11 -> V_204 ) ;
return 0 ;
}
static int F_84 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
T_2 V_22 ;
V_22 = F_76 ( & V_199 -> V_200 . V_201 ) ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = V_22 != V_11 -> V_204 ;
V_11 -> V_204 = V_22 ;
V_11 -> V_93 &= ~ ( V_187 | V_189 | V_191 ) ;
F_10 ( V_11 , V_104 , V_11 -> V_93 |= V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_85 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
V_196 -> type = V_197 ;
V_196 -> V_59 = 1 ;
return 0 ;
}
static int F_86 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
V_199 -> V_200 . V_201 . V_69 [ 0 ] = V_194 -> V_205 ;
return 0 ;
}
static unsigned int F_87 ( struct V_11 * V_11 )
{
return F_88 ( V_11 -> V_93 & V_206 ) ;
}
static int F_89 ( struct V_11 * V_11 , int V_12 )
{
V_11 -> V_93 &= ~ V_206 ;
V_11 -> V_93 |= F_90 ( V_12 ) ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_91 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [ 4 ] = { L_23 , L_24 , L_25 , L_26 } ;
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = ( ( V_11 -> V_14 == V_19 ) ? 4 : 3 ) ;
if ( V_196 -> V_200 . V_209 . V_211 > ( ( V_11 -> V_14 == V_19 ) ? 3 : 2 ) )
V_196 -> V_200 . V_209 . V_211 = ( ( V_11 -> V_14 == V_19 ) ? 3 : 2 ) ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_92 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_87 ( V_11 ) ;
return 0 ;
}
static int F_93 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . V_209 . V_211 [ 0 ] % ( ( V_11 -> V_14 == V_19 ) ? 4 : 3 ) ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = V_22 != F_87 ( V_11 ) ;
if ( V_203 )
F_89 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_94 ( struct V_11 * V_11 )
{
return ( V_11 -> V_93 & V_212 ) ? 1 : 0 ;
}
static int F_95 ( struct V_11 * V_11 , int V_13 )
{
if ( V_13 )
V_11 -> V_93 |= V_212 ;
else
V_11 -> V_93 &= ~ V_212 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_96 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = F_94 ( V_11 ) ;
return 0 ;
}
static int F_97 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = ( int ) V_22 != F_94 ( V_11 ) ;
F_95 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_98 ( struct V_11 * V_11 )
{
return ( V_11 -> V_93 & V_187 ) ? 1 : 0 ;
}
static int F_99 ( struct V_11 * V_11 , int V_22 )
{
if ( V_22 )
V_11 -> V_93 |= V_187 ;
else
V_11 -> V_93 &= ~ V_187 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_100 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = F_98 ( V_11 ) ;
return 0 ;
}
static int F_101 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = ( int ) V_22 != F_98 ( V_11 ) ;
F_99 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_102 ( struct V_11 * V_11 )
{
return ( V_11 -> V_93 & V_191 ) ? 1 : 0 ;
}
static int F_103 ( struct V_11 * V_11 , int V_22 )
{
if ( V_22 )
V_11 -> V_93 |= V_191 ;
else
V_11 -> V_93 &= ~ V_191 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_104 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = F_102 ( V_11 ) ;
return 0 ;
}
static int F_105 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = ( int ) V_22 != F_102 ( V_11 ) ;
F_103 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_106 ( struct V_11 * V_11 )
{
return ( V_11 -> V_93 & V_189 ) ? 1 : 0 ;
}
static int F_107 ( struct V_11 * V_11 , int V_22 )
{
if ( V_22 )
V_11 -> V_93 |= V_189 ;
else
V_11 -> V_93 &= ~ V_189 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_108 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = F_106 ( V_11 ) ;
return 0 ;
}
static int F_109 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = ( int ) V_22 != F_106 ( V_11 ) ;
F_107 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_110 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_27 , L_28 , L_29 , L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 } ;
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = ( V_11 -> V_14 == V_19 ) ? 10 : 7 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_111 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
switch ( F_33 ( V_11 ) ) {
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
static int F_112 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
V_196 -> type = V_213 ;
V_196 -> V_59 = 1 ;
return 0 ;
}
static int F_113 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = V_11 -> V_119 ;
return 0 ;
}
static int F_114 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
static char * V_207 [] = { L_27 , L_28 , L_29 , L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = ( V_11 -> V_14 == V_19 ) ? 10 : 7 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_115 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
switch ( F_34 ( V_11 ) ) {
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
static int F_116 ( struct V_11 * V_11 )
{
if ( V_11 -> V_93 & V_115 )
return 0 ;
else if ( F_34 ( V_11 ) != V_11 -> V_119 )
return 0 ;
return 1 ;
}
static int F_117 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_37 , L_38 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 2 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_118 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_116 ( V_11 ) ;
return 0 ;
}
static int F_119 ( struct V_11 * V_11 )
{
if ( V_11 -> V_93 & V_115 ) {
switch ( V_11 -> V_119 ) {
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
static int F_120 ( struct V_11 * V_11 , int V_214 )
{
int V_110 ;
switch ( V_214 ) {
case V_215 :
if ( F_34 ( V_11 ) != 0 ) {
if ( ! F_50 ( V_11 , F_34 ( V_11 ) , 1 ) ) {
V_11 -> V_93 &= ~ V_115 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
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
V_11 -> V_93 |= V_115 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
F_50 ( V_11 , V_110 , 1 ) ;
return 0 ;
}
static int F_121 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_39 , L_40 , L_41 , L_42 , L_43 , L_44 , L_45 , L_46 , L_47 , L_48 } ;
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
if ( V_11 -> V_14 == V_19 )
V_196 -> V_200 . V_209 . V_210 = 10 ;
else
V_196 -> V_200 . V_209 . V_210 = 7 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_122 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_119 ( V_11 ) ;
return 0 ;
}
static int F_123 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
if ( V_22 < 0 ) V_22 = 0 ;
if ( V_11 -> V_14 == V_19 ) {
if ( V_22 > 9 )
V_22 = 9 ;
} else {
if ( V_22 > 6 )
V_22 = 6 ;
}
F_44 ( & V_11 -> V_49 ) ;
if ( V_22 != F_119 ( V_11 ) )
V_203 = ( F_120 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_124 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = V_11 -> V_225 ;
return 0 ;
}
static int F_125 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
V_203 = ( int ) V_199 -> V_200 . integer . V_200 [ 0 ] != V_11 -> V_225 ;
if ( V_203 )
V_11 -> V_225 = ! ! V_199 -> V_200 . integer . V_200 [ 0 ] ;
return V_203 ;
}
static int F_126 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_93 & V_226 ) {
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
static int F_127 ( struct V_11 * V_11 , int V_214 )
{
V_11 -> V_93 &= ~ V_226 ;
switch ( V_214 ) {
case 0 :
V_11 -> V_93 |= V_227 ;
break;
case 1 :
V_11 -> V_93 |= V_228 ;
break;
case 2 :
V_11 -> V_93 |= V_229 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_128 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_49 , L_50 , L_51 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 3 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_129 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_126 ( V_11 ) ;
return 0 ;
}
static int F_130 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
if ( V_22 < 0 ) V_22 = 0 ;
if ( V_22 > 2 ) V_22 = 2 ;
F_44 ( & V_11 -> V_49 ) ;
if ( V_22 != F_126 ( V_11 ) )
V_203 = ( F_127 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_131 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_93 & V_230 ) {
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
static int F_132 ( struct V_11 * V_11 , int V_214 )
{
V_11 -> V_93 &= ~ V_230 ;
switch ( V_214 ) {
case 0 :
V_11 -> V_93 |= V_231 ;
break;
case 1 :
V_11 -> V_93 |= V_232 ;
break;
case 2 :
V_11 -> V_93 |= V_233 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_133 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_52 , L_50 , L_53 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 3 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_134 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_131 ( V_11 ) ;
return 0 ;
}
static int F_135 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
if ( V_22 < 0 ) V_22 = 0 ;
if ( V_22 > 2 ) V_22 = 2 ;
F_44 ( & V_11 -> V_49 ) ;
if ( V_22 != F_131 ( V_11 ) )
V_203 = ( F_132 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_136 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_93 & V_234 ) {
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
static int F_137 ( struct V_11 * V_11 , int V_214 )
{
V_11 -> V_93 &= ~ V_234 ;
switch ( V_214 ) {
case 0 :
V_11 -> V_93 |= V_235 ;
break;
case 1 :
V_11 -> V_93 |= V_236 ;
break;
case 2 :
V_11 -> V_93 |= V_237 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_138 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_54 , L_55 , L_56 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 3 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_139 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_136 ( V_11 ) ;
return 0 ;
}
static int F_140 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
if ( V_22 < 0 ) V_22 = 0 ;
if ( V_22 > 2 ) V_22 = 2 ;
F_44 ( & V_11 -> V_49 ) ;
if ( V_22 != F_136 ( V_11 ) )
V_203 = ( F_137 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_141 ( struct V_11 * V_11 )
{
if ( V_11 -> V_93 & V_238 )
return 1 ;
return 0 ;
}
static int F_142 ( struct V_11 * V_11 , int V_214 )
{
if ( V_214 )
V_11 -> V_93 |= V_238 ;
else
V_11 -> V_93 &= ~ V_238 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_143 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_141 ( V_11 ) ;
return 0 ;
}
static int F_144 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = ( int ) V_22 != F_141 ( V_11 ) ;
F_142 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_145 ( struct V_11 * V_11 )
{
if ( V_11 -> V_93 & V_239 )
return 1 ;
return 0 ;
}
static int F_146 ( struct V_11 * V_11 , int V_214 )
{
if ( V_214 )
V_11 -> V_93 |= V_239 ;
else
V_11 -> V_93 &= ~ V_239 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_147 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_145 ( V_11 ) ;
return 0 ;
}
static int F_148 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = ( int ) V_22 != F_145 ( V_11 ) ;
F_146 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_149 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_93 & V_240 ) {
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
case V_251 :
return V_252 ;
default:
return V_250 ;
}
return 0 ;
}
static int F_150 ( struct V_11 * V_11 , int V_253 )
{
V_11 -> V_93 &= ~ V_240 ;
switch ( V_253 ) {
case V_242 :
V_11 -> V_93 &= ~ V_240 ;
break;
case V_244 :
V_11 -> V_93 |= V_243 ;
break;
case V_246 :
V_11 -> V_93 |= V_245 ;
break;
case V_248 :
V_11 -> V_93 |= V_247 ;
break;
case V_250 :
V_11 -> V_93 |= V_249 ;
break;
case V_252 :
V_11 -> V_93 |= V_251 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_151 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_57 , L_58 , L_59 , L_60 , L_61 , L_62 } ;
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_20 :
V_196 -> V_200 . V_209 . V_210 = 6 ;
break;
case V_15 :
V_196 -> V_200 . V_209 . V_210 = 4 ;
break;
case V_19 :
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
static int F_152 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_149 ( V_11 ) ;
return 0 ;
}
static int F_153 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 , V_254 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_20 :
V_254 = 6 ;
break;
case V_15 :
V_254 = 4 ;
break;
case V_19 :
V_254 = 3 ;
break;
default:
return - V_28 ;
}
V_22 = V_199 -> V_200 . V_209 . V_211 [ 0 ] % V_254 ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = ( int ) V_22 != F_149 ( V_11 ) ;
F_150 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_35 ( struct V_11 * V_11 )
{
unsigned int V_83 = F_12 ( V_11 , V_53 ) ;
switch ( V_83 & V_255 ) {
case V_256 :
return V_257 ;
case V_258 :
return V_259 ;
case V_260 :
return V_85 ;
case V_255 :
return V_261 ;
case V_262 :
return V_118 ;
case V_263 :
return V_264 ;
case V_265 :
return V_266 ;
default:
return V_257 ;
}
return 0 ;
}
static int F_154 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_57 , L_60 , L_58 , L_33 , L_59 , L_61 , L_62 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 7 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_155 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_35 ( V_11 ) ;
return 0 ;
}
static int F_156 ( struct V_11 * V_11 )
{
return ( V_11 -> V_93 & V_267 ) ? 1 : 0 ;
}
static int F_157 ( struct V_11 * V_11 , int V_13 )
{
if ( V_13 )
V_11 -> V_93 |= V_267 ;
else
V_11 -> V_93 &= ~ V_267 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_158 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
F_44 ( & V_11 -> V_49 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = F_156 ( V_11 ) ;
F_46 ( & V_11 -> V_49 ) ;
return 0 ;
}
static int F_159 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = ( int ) V_22 != F_156 ( V_11 ) ;
F_157 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_160 ( struct V_11 * V_11 , int V_268 )
{
if ( V_268 )
V_11 -> V_95 = 1 ;
else
V_11 -> V_95 = 0 ;
return 0 ;
}
static int F_161 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
F_44 ( & V_11 -> V_49 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = V_11 -> V_95 ;
F_46 ( & V_11 -> V_49 ) ;
return 0 ;
}
static int F_162 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = ( int ) V_22 != V_11 -> V_95 ;
F_160 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_163 ( struct V_11 * V_11 , int V_269 )
{
if ( V_269 )
V_11 -> V_270 = 1 ;
else
V_11 -> V_270 = 0 ;
return 0 ;
}
static int F_164 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
F_44 ( & V_11 -> V_49 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = V_11 -> V_270 ;
F_46 ( & V_11 -> V_49 ) ;
return 0 ;
}
static int F_165 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = ( int ) V_22 != V_11 -> V_270 ;
F_163 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_166 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
V_196 -> type = V_213 ;
V_196 -> V_59 = 3 ;
V_196 -> V_200 . integer . V_271 = 0 ;
V_196 -> V_200 . integer . V_254 = 65536 ;
V_196 -> V_200 . integer . V_272 = 1 ;
return 0 ;
}
static int F_167 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_273 ;
int V_274 ;
int V_62 ;
V_273 = V_199 -> V_200 . integer . V_200 [ 0 ] ;
V_274 = V_199 -> V_200 . integer . V_200 [ 1 ] ;
if ( V_273 >= V_11 -> V_275 )
V_62 = F_8 ( V_11 , V_273 - V_11 -> V_275 , V_274 ) ;
else
V_62 = F_9 ( V_11 , V_273 , V_274 ) ;
F_44 ( & V_11 -> V_49 ) ;
V_199 -> V_200 . integer . V_200 [ 2 ] = F_30 ( V_11 , V_62 ) ;
F_46 ( & V_11 -> V_49 ) ;
return 0 ;
}
static int F_168 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
int V_273 ;
int V_274 ;
int V_276 ;
int V_62 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_273 = V_199 -> V_200 . integer . V_200 [ 0 ] ;
V_274 = V_199 -> V_200 . integer . V_200 [ 1 ] ;
if ( V_273 >= V_11 -> V_275 )
V_62 = F_8 ( V_11 , V_273 - V_11 -> V_275 , V_274 ) ;
else
V_62 = F_9 ( V_11 , V_273 , V_274 ) ;
V_276 = V_199 -> V_200 . integer . V_200 [ 2 ] ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = V_276 != F_30 ( V_11 , V_62 ) ;
if ( V_203 )
F_31 ( V_11 , V_62 , V_276 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_169 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_63 , L_64 , L_65 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 3 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_170 ( struct V_11 * V_11 )
{
int V_83 = F_12 ( V_11 , V_53 ) ;
if ( V_83 & V_277 ) {
if ( V_83 & V_278 )
return 2 ;
else
return 1 ;
} else
return 0 ;
return 0 ;
}
static int F_171 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_170 ( V_11 ) ;
return 0 ;
}
static int F_172 ( struct V_11 * V_11 )
{
int V_69 = F_12 ( V_11 , V_24 ) ;
if ( V_69 & V_73 )
return 0 ;
else {
if ( V_69 & V_279 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_173 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_172 ( V_11 ) ;
return 0 ;
}
static int F_174 ( struct V_11 * V_11 )
{
int V_69 = F_12 ( V_11 , V_24 ) ;
if ( V_69 & V_280 ) {
if ( V_69 & V_281 )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_175 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_174 ( V_11 ) ;
return 0 ;
}
static int F_176 ( struct V_11 * V_11 , int V_282 )
{
int V_69 = F_12 ( V_11 , V_24 ) ;
if ( V_69 & ( V_283 >> V_282 ) ) {
if ( V_69 & ( V_284 >> V_282 ) )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_177 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
int V_285 ;
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_285 = V_199 -> V_139 . V_286 - 1 ;
F_49 ( V_285 < 0 ) ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_20 :
if ( V_285 >= 3 )
return - V_120 ;
break;
case V_15 :
case V_19 :
if ( V_285 >= 1 )
return - V_120 ;
break;
default:
return - V_28 ;
}
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_176 ( V_11 , V_285 ) ;
return 0 ;
}
static int F_178 ( struct V_11 * V_11 )
{
T_4 V_108 ;
unsigned int V_100 = V_11 -> V_100 ;
int V_119 = V_11 -> V_119 ;
if ( ! V_100 )
return 0 ;
V_108 = V_111 ;
V_108 = F_48 ( V_108 , V_100 ) ;
if ( V_119 >= 112000 )
V_108 *= 4 ;
else if ( V_119 >= 56000 )
V_108 *= 2 ;
return ( ( int ) V_108 ) - V_119 ;
}
static int F_179 ( struct V_11 * V_11 , int V_287 )
{
int V_110 = V_11 -> V_119 + V_287 ;
F_47 ( V_11 , V_110 ) ;
return 0 ;
}
static int F_180 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
V_196 -> type = V_213 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . integer . V_271 = - 5000 ;
V_196 -> V_200 . integer . V_254 = 5000 ;
return 0 ;
}
static int F_181 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_178 ( V_11 ) ;
return 0 ;
}
static int F_182 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
F_44 ( & V_11 -> V_49 ) ;
if ( V_22 != F_178 ( V_11 ) )
V_203 = ( F_179 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_183 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_93 & V_288 ) {
case V_289 :
return 0 ;
case V_290 :
return 2 ;
case V_291 :
return 3 ;
case V_292 :
return 4 ;
}
return 1 ;
}
static int F_184 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_183 ( V_11 ) ;
return 0 ;
}
static int F_185 ( struct V_11 * V_11 , int V_214 )
{
V_11 -> V_93 &= ~ V_288 ;
switch ( V_214 ) {
case 0 :
V_11 -> V_93 |= V_289 ;
break;
case 1 :
break;
case 2 :
V_11 -> V_93 |= V_290 ;
break;
case 3 :
V_11 -> V_93 |= V_291 ;
break;
case 4 :
V_11 -> V_93 |= V_292 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_186 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
if ( V_22 < 0 )
V_22 = 0 ;
if ( V_22 > 4 )
V_22 = 4 ;
F_44 ( & V_11 -> V_49 ) ;
if ( V_22 != F_183 ( V_11 ) )
V_203 = ( F_185 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_187 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_66 , L_67 , L_68 , L_69 , L_70 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 5 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_188 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_93 & V_293 ) {
case V_294 :
return 0 ;
case V_295 :
return 2 ;
case V_296 :
return 3 ;
case V_297 :
return 4 ;
}
return 1 ;
}
static int F_189 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . V_209 . V_211 [ 0 ] = F_188 ( V_11 ) ;
return 0 ;
}
static int F_190 ( struct V_11 * V_11 , int V_214 )
{
V_11 -> V_93 &= ~ V_293 ;
switch ( V_214 ) {
case 0 :
V_11 -> V_93 |= V_294 ;
break;
case 1 :
break;
case 2 :
V_11 -> V_93 |= V_295 ;
break;
case 3 :
V_11 -> V_93 |= V_296 ;
break;
case 4 :
V_11 -> V_93 |= V_297 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_191 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . V_209 . V_211 [ 0 ] ;
if ( V_22 < 0 )
V_22 = 0 ;
if ( V_22 > 4 )
V_22 = 4 ;
F_44 ( & V_11 -> V_49 ) ;
if ( V_22 != F_188 ( V_11 ) )
V_203 = ( F_190 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_203 = 0 ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_192 ( struct V_11 * V_11 )
{
return ( V_11 -> V_93 & V_298 ) ? 1 : 0 ;
}
static int F_193 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = F_192 ( V_11 ) ;
return 0 ;
}
static int F_194 ( struct V_11 * V_11 , int V_299 )
{
if ( V_299 )
V_11 -> V_93 |= V_298 ;
else
V_11 -> V_93 &= ~ V_298 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_195 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = ( int ) V_22 != F_192 ( V_11 ) ;
F_194 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_196 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_71 , L_72 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 2 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_197 ( struct V_11 * V_11 )
{
return ( V_11 -> V_93 & V_300 ) ? 1 : 0 ;
}
static int F_198 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
V_199 -> V_200 . integer . V_200 [ 0 ] = F_197 ( V_11 ) ;
return 0 ;
}
static int F_199 ( struct V_11 * V_11 , int V_299 )
{
if ( V_299 )
V_11 -> V_93 |= V_300 ;
else
V_11 -> V_93 &= ~ V_300 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
return 0 ;
}
static int F_200 ( struct V_193 * V_194 , struct V_198 * V_199 )
{
struct V_11 * V_11 = F_80 ( V_194 ) ;
int V_203 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_130 ;
V_22 = V_199 -> V_200 . integer . V_200 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_49 ) ;
V_203 = ( int ) V_22 != F_197 ( V_11 ) ;
F_199 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_203 ;
}
static int F_201 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
static char * V_207 [] = { L_71 , L_72 } ;
V_196 -> type = V_208 ;
V_196 -> V_59 = 1 ;
V_196 -> V_200 . V_209 . V_210 = 2 ;
if ( V_196 -> V_200 . V_209 . V_211 >= V_196 -> V_200 . V_209 . V_210 )
V_196 -> V_200 . V_209 . V_211 = V_196 -> V_200 . V_209 . V_210 - 1 ;
strcpy ( V_196 -> V_200 . V_209 . V_175 , V_207 [ V_196 -> V_200 . V_209 . V_211 ] ) ;
return 0 ;
}
static int F_202 ( struct V_171 * V_172 , struct V_11 * V_11 )
{
unsigned int V_282 ;
int V_301 ;
struct V_193 * V_302 ;
if ( V_11 -> V_14 == V_17 ) {
for ( V_282 = 0 ; V_282 < F_203 ( V_303 ) ; V_282 ++ ) {
V_301 = F_204 ( V_172 , V_302 = F_205 ( & V_303 [ V_282 ] , V_11 ) ) ;
if ( V_301 < 0 )
return V_301 ;
}
return 0 ;
}
for ( V_282 = 0 ; V_282 < F_203 ( V_304 ) ; V_282 ++ ) {
if ( ( V_301 = F_204 ( V_172 , V_302 = F_205 ( & V_304 [ V_282 ] , V_11 ) ) ) < 0 )
return V_301 ;
if ( V_282 == 1 )
V_11 -> V_305 = V_302 ;
}
V_306 . V_175 = L_73 ;
V_306 . V_286 = 1 ;
if ( ( V_301 = F_204 ( V_172 , V_302 = F_205 ( & V_306 , V_11 ) ) ) )
return V_301 ;
if ( V_11 -> V_14 == V_16 || V_11 -> V_14 == V_20 ) {
for ( V_282 = 1 ; V_282 < 3 ; ++ V_282 ) {
V_306 . V_286 = V_282 + 1 ;
if ( ( V_301 = F_204 ( V_172 , V_302 = F_205 ( & V_306 , V_11 ) ) ) )
return V_301 ;
}
}
if ( V_11 -> V_14 == V_19 ) {
for ( V_282 = 0 ; V_282 < F_203 ( V_307 ) ; V_282 ++ ) {
if ( ( V_301 = F_204 ( V_172 , V_302 = F_205 ( & V_307 [ V_282 ] , V_11 ) ) ) < 0 )
return V_301 ;
}
}
if ( V_11 -> V_14 == V_19 || V_11 -> V_14 == V_20 ) {
if ( ( V_301 = F_204 ( V_172 , V_302 = F_205 ( & V_308 , V_11 ) ) ) < 0 )
return V_301 ;
}
return 0 ;
}
static void
F_206 ( struct V_309 * V_310 , struct V_311 * V_312 )
{
struct V_11 * V_11 = V_310 -> V_164 ;
unsigned int V_69 ;
unsigned int V_83 ;
char * V_313 ;
char * V_314 ;
char * V_315 ;
char * V_316 ;
int V_317 ;
V_69 = F_12 ( V_11 , V_24 ) ;
V_83 = F_12 ( V_11 , V_53 ) ;
F_207 ( V_312 , L_74 , V_11 -> V_318 ,
V_11 -> V_172 -> V_319 + 1 ) ;
F_207 ( V_312 , L_75 ,
V_11 -> V_320 , V_11 -> V_105 ) ;
F_207 ( V_312 , L_76 ,
V_11 -> V_321 , V_11 -> V_322 , ( unsigned long ) V_11 -> V_23 ) ;
F_207 ( V_312 , L_77 , V_11 -> V_93 ) ;
F_207 ( V_312 , L_78 ,
V_11 -> V_45 ) ;
F_207 ( V_312 , L_79 , V_69 ) ;
F_207 ( V_312 , L_80 , V_83 ) ;
if ( F_14 ( V_11 ) ) {
F_207 ( V_312 , L_81
L_82 ) ;
return;
}
if ( F_27 ( V_11 , 0 ) ) {
if ( V_11 -> V_26 & V_58 ) {
if ( F_19 ( V_11 ) != 0 ) {
F_207 ( V_312 , L_83
L_84
L_85 ) ;
return;
}
} else {
int V_301 = - V_120 ;
V_301 = F_28 ( V_11 ) ;
if ( V_301 < 0 ) {
F_207 ( V_312 ,
L_86
L_87 ) ;
return;
}
}
}
F_207 ( V_312 , L_88 , F_12 ( V_11 , V_61 ) & 0xff ) ;
F_207 ( V_312 , L_89 , F_12 ( V_11 , V_148 ) ) ;
F_207 ( V_312 , L_90 , F_12 ( V_11 , V_145 ) ) ;
F_207 ( V_312 , L_91 , F_12 ( V_11 , V_147 ) ) ;
F_207 ( V_312 , L_92 , F_12 ( V_11 , V_144 ) ) ;
F_207 ( V_312 , L_93 , V_11 -> V_270 ? L_94 : L_95 ) ;
F_207 ( V_312 , L_96 ) ;
V_317 = 1 << ( 6 + F_37 ( V_11 -> V_93 & V_109 ) ) ;
F_207 ( V_312 , L_97 , V_317 , ( unsigned long ) V_11 -> V_92 ) ;
F_207 ( V_312 , L_98 , F_38 ( V_11 ) ) ;
F_207 ( V_312 , L_99 , V_11 -> V_95 ? L_94 : L_95 ) ;
F_207 ( V_312 , L_100 , ( V_11 -> V_93 & V_267 ) ? L_94 : L_95 ) ;
F_207 ( V_312 , L_101 , ( V_83 & V_323 ) | ( V_83 & V_55 ) << 1 | ( V_83 & V_54 ) << 2 ) ;
F_207 ( V_312 , L_96 ) ;
switch ( F_119 ( V_11 ) ) {
case V_215 :
V_316 = L_39 ;
break;
case V_216 :
V_316 = L_102 ;
break;
case V_217 :
V_316 = L_41 ;
break;
case V_218 :
V_316 = L_103 ;
break;
case V_219 :
V_316 = L_104 ;
break;
case V_220 :
V_316 = L_44 ;
break;
case V_221 :
V_316 = L_105 ;
break;
case V_222 :
V_316 = L_46 ;
break;
case V_223 :
V_316 = L_47 ;
break;
case V_224 :
V_316 = L_106 ;
break;
default:
V_316 = L_107 ;
}
F_207 ( V_312 , L_108 , V_316 ) ;
if ( F_116 ( V_11 ) )
V_315 = L_38 ;
else
V_315 = L_37 ;
switch ( F_149 ( V_11 ) ) {
case V_250 :
V_313 = L_109 ;
break;
case V_252 :
V_313 = L_60 ;
break;
case V_248 :
V_313 = L_110 ;
break;
case V_242 :
V_313 = L_59 ;
break;
case V_244 :
V_313 = L_61 ;
break;
case V_246 :
V_313 = L_62 ;
break;
default:
V_313 = L_109 ;
break;
}
F_207 ( V_312 , L_111 , V_313 ) ;
switch ( F_35 ( V_11 ) ) {
case V_257 :
V_314 = L_109 ;
break;
case V_259 :
V_314 = L_60 ;
break;
case V_85 :
V_314 = L_110 ;
break;
case V_261 :
V_314 = L_33 ;
break;
case V_118 :
V_314 = L_59 ;
break;
case V_264 :
V_314 = L_61 ;
break;
case V_266 :
V_314 = L_62 ;
break;
default:
V_314 = L_112 ;
break;
}
F_207 ( V_312 , L_113 , V_314 ) ;
F_207 ( V_312 , L_114 , F_34 ( V_11 ) ) ;
F_207 ( V_312 , L_115 , V_315 ) ;
F_207 ( V_312 , L_116 , V_11 -> V_119 ) ;
F_207 ( V_312 , L_117 , V_11 -> V_225 ? L_118 : L_119 ) ;
F_207 ( V_312 , L_96 ) ;
if ( V_11 -> V_14 != V_17 ) {
switch ( F_87 ( V_11 ) ) {
case V_324 :
F_207 ( V_312 , L_120 ) ;
break;
case V_325 :
F_207 ( V_312 , L_121 ) ;
break;
case V_326 :
F_207 ( V_312 , L_122 ) ;
break;
case V_327 :
F_207 ( V_312 , L_123 ) ;
break;
default:
F_207 ( V_312 , L_124 ) ;
break;
}
}
if ( V_17 == V_11 -> V_14 ) {
if ( V_11 -> V_93 & V_298 )
F_207 ( V_312 , L_125 ) ;
else
F_207 ( V_312 , L_126 ) ;
if ( V_11 -> V_93 & V_300 )
F_207 ( V_312 , L_127 ) ;
else
F_207 ( V_312 , L_128 ) ;
switch ( V_11 -> V_93 & V_288 ) {
case V_289 :
F_207 ( V_312 , L_129 ) ;
break;
case V_328 :
F_207 ( V_312 , L_130 ) ;
break;
case V_290 :
F_207 ( V_312 , L_131 ) ;
break;
case V_291 :
F_207 ( V_312 , L_132 ) ;
break;
case V_292 :
F_207 ( V_312 , L_133 ) ;
break;
default:
F_207 ( V_312 , L_134 ) ;
}
switch ( V_11 -> V_93 & V_293 ) {
case V_294 :
F_207 ( V_312 , L_135 ) ;
break;
case V_329 :
F_207 ( V_312 , L_136 ) ;
break;
case V_295 :
F_207 ( V_312 , L_137 ) ;
break;
case V_296 :
F_207 ( V_312 , L_138 ) ;
break;
case V_297 :
F_207 ( V_312 , L_139 ) ;
break;
default:
F_207 ( V_312 , L_140 ) ;
}
} else {
if ( V_11 -> V_93 & V_212 )
F_207 ( V_312 , L_141 ) ;
else
F_207 ( V_312 , L_142 ) ;
if ( V_11 -> V_93 & V_187 )
F_207 ( V_312 , L_143 ) ;
else
F_207 ( V_312 , L_144 ) ;
if ( V_11 -> V_93 & V_191 )
F_207 ( V_312 , L_145 ) ;
else
F_207 ( V_312 , L_146 ) ;
if ( V_11 -> V_93 & V_189 )
F_207 ( V_312 , L_147 ) ;
else
F_207 ( V_312 , L_148 ) ;
V_317 = F_33 ( V_11 ) ;
if ( V_317 != 0 )
F_207 ( V_312 , L_149 , V_317 ) ;
else
F_207 ( V_312 , L_150 ) ;
}
F_207 ( V_312 , L_96 ) ;
V_317 = V_69 & V_284 ;
if ( V_69 & V_283 )
F_207 ( V_312 , L_151 , V_317 ? L_65 : L_64 ) ;
else
F_207 ( V_312 , L_152 ) ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_20 :
V_317 = V_69 & V_330 ;
if ( V_69 & V_331 )
F_207 ( V_312 , L_153 , V_317 ? L_65 : L_64 ) ;
else
F_207 ( V_312 , L_154 ) ;
V_317 = V_69 & V_332 ;
if ( V_69 & V_333 )
F_207 ( V_312 , L_155 , V_317 ? L_65 : L_64 ) ;
else
F_207 ( V_312 , L_156 ) ;
break;
default:
break;
}
V_317 = V_69 & V_279 ;
if ( V_69 & V_73 )
F_207 ( V_312 , L_157 ) ;
else
F_207 ( V_312 , L_158 , V_317 ? L_65 : L_64 ) ;
V_317 = V_83 & V_278 ;
if ( V_83 & V_277 )
F_207 ( V_312 , L_159 , V_317 ? L_65 : L_64 ) ;
else
F_207 ( V_312 , L_160 ) ;
V_317 = V_69 & V_281 ;
if ( V_69 & V_280 )
F_207 ( V_312 , L_161 , V_317 ? L_65 : L_64 ) ;
else
F_207 ( V_312 , L_162 ) ;
F_207 ( V_312 , L_96 ) ;
if ( V_11 -> V_14 == V_19 ) {
char * V_334 ;
switch ( F_131 ( V_11 ) ) {
case 0 :
V_334 = L_52 ;
break;
case 1 :
V_334 = L_50 ;
break;
default:
V_334 = L_53 ;
break;
}
F_207 ( V_312 , L_163 , V_334 ) ;
switch ( F_126 ( V_11 ) ) {
case 0 :
V_334 = L_49 ;
break;
case 1 :
V_334 = L_50 ;
break;
default:
V_334 = L_52 ;
break;
}
F_207 ( V_312 , L_164 , V_334 ) ;
switch ( F_136 ( V_11 ) ) {
case 0 :
V_334 = L_54 ;
break;
case 1 :
V_334 = L_55 ;
break;
default:
V_334 = L_56 ;
break;
}
F_207 ( V_312 , L_165 , V_334 ) ;
F_207 ( V_312 , L_166 , F_141 ( V_11 ) ? L_167 : L_168 ) ;
if ( V_11 -> V_93 & V_239 )
F_207 ( V_312 , L_169 ) ;
else
F_207 ( V_312 , L_170 ) ;
F_207 ( V_312 , L_96 ) ;
}
}
static void F_208 ( struct V_11 * V_11 )
{
struct V_309 * V_310 ;
if ( ! F_209 ( V_11 -> V_172 , L_171 , & V_310 ) )
F_210 ( V_310 , V_11 , F_206 ) ;
}
static void F_211 ( struct V_11 * V_11 )
{
F_6 ( & V_11 -> V_335 , V_11 -> V_2 ) ;
F_6 ( & V_11 -> V_336 , V_11 -> V_2 ) ;
}
static int F_212 ( struct V_11 * V_11 )
{
unsigned long V_337 , V_338 ;
if ( F_1 ( V_11 -> V_2 , & V_11 -> V_335 , V_106 ) < 0 ||
F_1 ( V_11 -> V_2 , & V_11 -> V_336 , V_106 ) < 0 ) {
if ( V_11 -> V_335 . V_10 )
F_213 ( & V_11 -> V_335 ) ;
F_214 ( V_57 L_172 , V_11 -> V_318 ) ;
return - V_9 ;
}
V_338 = F_215 ( V_11 -> V_335 . V_62 , 0x10000ul ) ;
V_337 = F_215 ( V_11 -> V_336 . V_62 , 0x10000ul ) ;
F_10 ( V_11 , V_339 , V_338 ) ;
F_10 ( V_11 , V_340 , V_337 ) ;
V_11 -> V_320 = V_11 -> V_335 . V_10 + ( V_338 - V_11 -> V_335 . V_62 ) ;
V_11 -> V_105 = V_11 -> V_336 . V_10 + ( V_337 - V_11 -> V_336 . V_62 ) ;
return 0 ;
}
static int F_24 ( struct V_11 * V_11 )
{
unsigned int V_31 ;
V_11 -> V_93 = V_115 |
V_341 |
F_45 ( 7 ) |
V_267 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
#ifdef F_22
V_11 -> V_45 = V_46 ;
#else
V_11 -> V_45 = 0 ;
#endif
if ( V_11 -> V_14 == V_20 )
F_216 ( V_11 ) ;
else
F_10 ( V_11 , V_39 , V_11 -> V_45 ) ;
F_39 ( V_11 ) ;
F_36 ( V_11 ) ;
for ( V_31 = 0 ; V_31 < V_63 ; ++ V_31 )
V_11 -> V_64 [ V_31 ] = V_342 ;
for ( V_31 = 0 ; V_31 < ( ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) ? 1352 : V_63 ) ; ++ V_31 ) {
if ( F_31 ( V_11 , V_31 , V_342 ) )
return - V_28 ;
}
if ( V_11 -> V_14 == V_19 ) {
V_11 -> V_93 |= ( V_228 | V_232 | V_235 ) ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
}
F_50 ( V_11 , 48000 , 1 ) ;
return 0 ;
}
static void F_217 ( unsigned long V_343 )
{
struct V_11 * V_11 = (struct V_11 * ) V_343 ;
if ( V_11 -> V_173 [ 0 ] . V_156 )
F_59 ( & V_11 -> V_173 [ 0 ] ) ;
if ( V_11 -> V_173 [ 1 ] . V_156 )
F_59 ( & V_11 -> V_173 [ 1 ] ) ;
}
static T_5 F_218 ( int V_321 , void * V_344 )
{
struct V_11 * V_11 = (struct V_11 * ) V_344 ;
unsigned int V_69 ;
int V_345 ;
int V_346 ;
int V_347 ;
unsigned int V_348 ;
unsigned int V_349 ;
int V_350 = 0 ;
V_69 = F_12 ( V_11 , V_24 ) ;
V_345 = V_69 & V_351 ;
V_346 = V_69 & V_352 ;
V_347 = V_69 & V_353 ;
if ( ! V_345 && ! V_346 && ! V_347 )
return V_354 ;
F_10 ( V_11 , V_355 , 0 ) ;
V_348 = F_12 ( V_11 , V_145 ) & 0xff ;
V_349 = F_12 ( V_11 , V_144 ) & 0xff ;
if ( ! ( V_11 -> V_26 & V_47 ) )
return V_356 ;
if ( V_345 ) {
if ( V_11 -> V_357 )
F_219 ( V_11 -> V_358 -> V_359 [ V_360 ] . V_160 ) ;
if ( V_11 -> V_361 )
F_219 ( V_11 -> V_358 -> V_359 [ V_362 ] . V_160 ) ;
}
if ( V_346 && V_348 ) {
if ( V_11 -> V_270 ) {
V_11 -> V_93 &= ~ V_158 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
V_11 -> V_173 [ 0 ] . V_156 = 1 ;
V_350 = 1 ;
} else {
F_59 ( & V_11 -> V_173 [ 0 ] ) ;
}
}
if ( V_11 -> V_14 != V_15 && V_11 -> V_14 != V_17 && V_11 -> V_14 != V_19 && V_347 && V_349 ) {
if ( V_11 -> V_270 ) {
V_11 -> V_93 &= ~ V_157 ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
V_11 -> V_173 [ 1 ] . V_156 = 1 ;
V_350 = 1 ;
} else {
F_59 ( & V_11 -> V_173 [ 1 ] ) ;
}
}
if ( V_11 -> V_270 && V_350 )
F_220 ( & V_11 -> V_165 ) ;
return V_356 ;
}
static T_3 F_221 ( struct V_363 * V_160 )
{
struct V_11 * V_11 = F_222 ( V_160 ) ;
return F_38 ( V_11 ) ;
}
static char * F_223 ( struct V_11 * V_11 ,
int V_364 ,
int V_365 )
{
int V_366 ;
if ( F_49 ( V_365 < 0 || V_365 >= V_11 -> V_275 ) )
return NULL ;
if ( ( V_366 = V_11 -> V_132 [ V_365 ] ) < 0 )
return NULL ;
if ( V_364 == V_360 )
return V_11 -> V_320 + ( V_366 * V_367 ) ;
else
return V_11 -> V_105 + ( V_366 * V_367 ) ;
}
static int F_224 ( struct V_363 * V_160 , int V_365 ,
T_3 V_368 , void T_6 * V_369 , T_3 V_59 )
{
struct V_11 * V_11 = F_222 ( V_160 ) ;
char * V_370 ;
if ( F_49 ( V_368 + V_59 > V_367 / 4 ) )
return - V_120 ;
V_370 = F_223 ( V_11 , V_160 -> V_371 -> V_364 , V_365 ) ;
if ( F_49 ( ! V_370 ) )
return - V_28 ;
if ( F_225 ( V_370 + V_368 * 4 , V_369 , V_59 * 4 ) )
return - V_372 ;
return V_59 ;
}
static int F_226 ( struct V_363 * V_160 , int V_365 ,
T_3 V_368 , void T_6 * V_373 , T_3 V_59 )
{
struct V_11 * V_11 = F_222 ( V_160 ) ;
char * V_370 ;
if ( F_49 ( V_368 + V_59 > V_367 / 4 ) )
return - V_120 ;
V_370 = F_223 ( V_11 , V_160 -> V_371 -> V_364 , V_365 ) ;
if ( F_49 ( ! V_370 ) )
return - V_28 ;
if ( F_227 ( V_373 , V_370 + V_368 * 4 , V_59 * 4 ) )
return - V_372 ;
return V_59 ;
}
static int F_228 ( struct V_363 * V_160 , int V_365 ,
T_3 V_368 , T_3 V_59 )
{
struct V_11 * V_11 = F_222 ( V_160 ) ;
char * V_370 ;
V_370 = F_223 ( V_11 , V_160 -> V_371 -> V_364 , V_365 ) ;
if ( F_49 ( ! V_370 ) )
return - V_28 ;
memset ( V_370 + V_368 * 4 , 0 , V_59 * 4 ) ;
return V_59 ;
}
static int F_229 ( struct V_363 * V_160 )
{
struct V_374 * V_375 = V_160 -> V_375 ;
struct V_11 * V_11 = F_222 ( V_160 ) ;
struct V_363 * V_376 ;
if ( V_160 -> V_364 == V_362 )
V_376 = V_11 -> V_357 ;
else
V_376 = V_11 -> V_361 ;
if ( V_11 -> V_377 )
V_375 -> V_69 -> V_378 = F_38 ( V_11 ) ;
else
V_375 -> V_69 -> V_378 = 0 ;
if ( V_376 ) {
struct V_363 * V_101 ;
struct V_374 * V_379 = V_376 -> V_375 ;
F_230 (s, substream) {
if ( V_101 == V_376 ) {
V_379 -> V_69 -> V_378 = V_375 -> V_69 -> V_378 ;
break;
}
}
}
return 0 ;
}
static int F_231 ( struct V_363 * V_160 ,
struct V_380 * V_381 )
{
struct V_11 * V_11 = F_222 ( V_160 ) ;
int V_301 ;
T_7 V_382 ;
T_7 V_383 ;
if ( F_14 ( V_11 ) )
return - V_28 ;
if ( F_27 ( V_11 , 1 ) )
return - V_28 ;
F_44 ( & V_11 -> V_49 ) ;
if ( V_160 -> V_371 -> V_364 == V_362 ) {
V_11 -> V_93 &= ~ ( V_187 | V_189 | V_191 ) ;
F_10 ( V_11 , V_104 , V_11 -> V_93 |= V_11 -> V_204 ) ;
V_382 = V_11 -> V_67 ;
V_383 = V_11 -> V_68 ;
} else {
V_382 = V_11 -> V_68 ;
V_383 = V_11 -> V_67 ;
}
if ( ( V_383 > 0 ) && ( V_382 != V_383 ) ) {
if ( F_232 ( V_381 ) != V_11 -> V_119 ) {
F_46 ( & V_11 -> V_49 ) ;
F_233 ( V_381 , V_384 ) ;
return - V_130 ;
}
if ( F_234 ( V_381 ) != V_11 -> V_92 / 4 ) {
F_46 ( & V_11 -> V_49 ) ;
F_233 ( V_381 , V_385 ) ;
return - V_130 ;
}
F_46 ( & V_11 -> V_49 ) ;
return 0 ;
} else {
F_46 ( & V_11 -> V_49 ) ;
}
F_44 ( & V_11 -> V_49 ) ;
if ( ! V_11 -> V_225 ) {
if ( ( V_301 = F_50 ( V_11 , F_232 ( V_381 ) , 0 ) ) < 0 ) {
F_46 ( & V_11 -> V_49 ) ;
F_233 ( V_381 , V_384 ) ;
return V_301 ;
}
}
F_46 ( & V_11 -> V_49 ) ;
if ( ( V_301 = F_43 ( V_11 , F_234 ( V_381 ) ) ) < 0 ) {
F_233 ( V_381 , V_385 ) ;
return V_301 ;
}
return 0 ;
}
static int F_235 ( struct V_363 * V_160 ,
struct V_386 * V_387 )
{
struct V_11 * V_11 = F_222 ( V_160 ) ;
int V_366 ;
if ( F_49 ( V_387 -> V_365 >= V_11 -> V_275 ) )
return - V_120 ;
if ( ( V_366 = V_11 -> V_132 [ V_387 -> V_365 ] ) < 0 )
return - V_120 ;
V_387 -> V_285 = V_366 * V_367 ;
V_387 -> V_388 = 0 ;
V_387 -> V_272 = 32 ;
return 0 ;
}
static int F_236 ( struct V_363 * V_160 ,
unsigned int V_389 , void * V_343 )
{
switch ( V_389 ) {
case V_390 :
return F_229 ( V_160 ) ;
case V_391 :
return F_235 ( V_160 , V_343 ) ;
default:
break;
}
return F_237 ( V_160 , V_389 , V_343 ) ;
}
static int F_238 ( struct V_363 * V_160 , int V_389 )
{
struct V_11 * V_11 = F_222 ( V_160 ) ;
struct V_363 * V_376 ;
int V_377 ;
if ( F_14 ( V_11 ) )
return - V_28 ;
if ( F_27 ( V_11 , 0 ) )
return - V_28 ;
F_239 ( & V_11 -> V_49 ) ;
V_377 = V_11 -> V_377 ;
switch ( V_389 ) {
case V_392 :
V_377 |= 1 << V_160 -> V_364 ;
break;
case V_393 :
V_377 &= ~ ( 1 << V_160 -> V_364 ) ;
break;
default:
F_240 () ;
F_241 ( & V_11 -> V_49 ) ;
return - V_120 ;
}
if ( V_160 -> V_364 == V_362 )
V_376 = V_11 -> V_357 ;
else
V_376 = V_11 -> V_361 ;
if ( V_376 ) {
struct V_363 * V_101 ;
F_230 (s, substream) {
if ( V_101 == V_376 ) {
F_242 ( V_101 , V_160 ) ;
if ( V_389 == V_392 )
V_377 |= 1 << V_101 -> V_364 ;
else
V_377 &= ~ ( 1 << V_101 -> V_364 ) ;
goto V_394;
}
}
if ( V_389 == V_392 ) {
if ( ! ( V_377 & ( 1 << V_362 ) ) &&
V_160 -> V_364 == V_360 )
F_42 ( V_11 ) ;
} else {
if ( V_377 &&
V_160 -> V_364 == V_362 )
F_42 ( V_11 ) ;
}
} else {
if ( V_160 -> V_364 == V_360 )
F_42 ( V_11 ) ;
}
V_394:
F_242 ( V_160 , V_160 ) ;
if ( ! V_11 -> V_377 && V_377 )
F_40 ( V_11 ) ;
else if ( V_11 -> V_377 && ! V_377 )
F_41 ( V_11 ) ;
V_11 -> V_377 = V_377 ;
F_241 ( & V_11 -> V_49 ) ;
return 0 ;
}
static int F_243 ( struct V_363 * V_160 )
{
struct V_11 * V_11 = F_222 ( V_160 ) ;
int V_395 = 0 ;
if ( F_14 ( V_11 ) )
return - V_28 ;
if ( F_27 ( V_11 , 1 ) )
return - V_28 ;
F_44 ( & V_11 -> V_49 ) ;
if ( ! V_11 -> V_377 )
F_39 ( V_11 ) ;
F_46 ( & V_11 -> V_49 ) ;
return V_395 ;
}
static int F_244 ( struct V_380 * V_381 ,
struct V_396 * V_397 )
{
struct V_11 * V_11 = V_397 -> V_398 ;
struct V_399 * V_400 = F_245 ( V_381 , V_401 ) ;
if ( V_11 -> V_14 == V_19 ) {
unsigned int V_402 [ 3 ] ;
V_402 [ 0 ] = V_11 -> V_403 ;
V_402 [ 1 ] = V_11 -> V_404 ;
V_402 [ 2 ] = V_11 -> V_405 ;
return F_246 ( V_400 , 3 , V_402 , 0 ) ;
} else {
unsigned int V_402 [ 2 ] ;
V_402 [ 0 ] = V_11 -> V_404 ;
V_402 [ 1 ] = V_11 -> V_405 ;
return F_246 ( V_400 , 2 , V_402 , 0 ) ;
}
}
static int F_247 ( struct V_380 * V_381 ,
struct V_396 * V_397 )
{
unsigned int V_402 [ 3 ] ;
struct V_11 * V_11 = V_397 -> V_398 ;
struct V_399 * V_400 = F_245 ( V_381 , V_401 ) ;
if ( V_11 -> V_14 == V_19 ) {
V_402 [ 0 ] = V_11 -> V_406 ;
V_402 [ 1 ] = V_11 -> V_407 ;
V_402 [ 2 ] = V_11 -> V_408 ;
return F_246 ( V_400 , 3 , V_402 , 0 ) ;
} else {
V_402 [ 0 ] = V_11 -> V_407 ;
V_402 [ 1 ] = V_11 -> V_408 ;
}
return F_246 ( V_400 , 2 , V_402 , 0 ) ;
}
static int F_248 ( struct V_380 * V_381 ,
struct V_396 * V_397 )
{
struct V_11 * V_11 = V_397 -> V_398 ;
struct V_399 * V_400 = F_245 ( V_381 , V_401 ) ;
struct V_399 * V_409 = F_245 ( V_381 , V_384 ) ;
if ( V_409 -> V_271 > 96000 && V_11 -> V_14 == V_19 ) {
struct V_399 V_410 = {
. V_271 = V_11 -> V_403 ,
. V_254 = V_11 -> V_403 ,
. integer = 1 ,
} ;
return F_249 ( V_400 , & V_410 ) ;
} else if ( V_409 -> V_271 > 48000 && V_409 -> V_254 <= 96000 ) {
struct V_399 V_410 = {
. V_271 = V_11 -> V_404 ,
. V_254 = V_11 -> V_404 ,
. integer = 1 ,
} ;
return F_249 ( V_400 , & V_410 ) ;
} else if ( V_409 -> V_254 < 64000 ) {
struct V_399 V_410 = {
. V_271 = V_11 -> V_405 ,
. V_254 = V_11 -> V_405 ,
. integer = 1 ,
} ;
return F_249 ( V_400 , & V_410 ) ;
}
return 0 ;
}
static int F_250 ( struct V_380 * V_381 ,
struct V_396 * V_397 )
{
struct V_11 * V_11 = V_397 -> V_398 ;
struct V_399 * V_400 = F_245 ( V_381 , V_401 ) ;
struct V_399 * V_409 = F_245 ( V_381 , V_384 ) ;
if ( V_409 -> V_271 > 96000 && V_11 -> V_14 == V_19 ) {
struct V_399 V_410 = {
. V_271 = V_11 -> V_406 ,
. V_254 = V_11 -> V_406 ,
. integer = 1 ,
} ;
return F_249 ( V_400 , & V_410 ) ;
} else if ( V_409 -> V_271 > 48000 && V_409 -> V_254 <= 96000 ) {
struct V_399 V_410 = {
. V_271 = V_11 -> V_407 ,
. V_254 = V_11 -> V_407 ,
. integer = 1 ,
} ;
return F_249 ( V_400 , & V_410 ) ;
} else if ( V_409 -> V_254 < 64000 ) {
struct V_399 V_410 = {
. V_271 = V_11 -> V_408 ,
. V_254 = V_11 -> V_408 ,
. integer = 1 ,
} ;
return F_249 ( V_400 , & V_410 ) ;
}
return 0 ;
}
static int F_251 ( struct V_380 * V_381 ,
struct V_396 * V_397 )
{
struct V_11 * V_11 = V_397 -> V_398 ;
struct V_399 * V_400 = F_245 ( V_381 , V_401 ) ;
struct V_399 * V_409 = F_245 ( V_381 , V_384 ) ;
if ( V_400 -> V_271 >= V_11 -> V_408 ) {
struct V_399 V_410 = {
. V_271 = 32000 ,
. V_254 = 48000 ,
. integer = 1 ,
} ;
return F_249 ( V_409 , & V_410 ) ;
} else if ( V_400 -> V_254 <= V_11 -> V_406 && V_11 -> V_14 == V_19 ) {
struct V_399 V_410 = {
. V_271 = 128000 ,
. V_254 = 192000 ,
. integer = 1 ,
} ;
return F_249 ( V_409 , & V_410 ) ;
} else if ( V_400 -> V_254 <= V_11 -> V_407 ) {
struct V_399 V_410 = {
. V_271 = 64000 ,
. V_254 = 96000 ,
. integer = 1 ,
} ;
return F_249 ( V_409 , & V_410 ) ;
}
return 0 ;
}
static int F_252 ( struct V_380 * V_381 ,
struct V_396 * V_397 )
{
struct V_11 * V_11 = V_397 -> V_398 ;
struct V_399 * V_400 = F_245 ( V_381 , V_401 ) ;
struct V_399 * V_409 = F_245 ( V_381 , V_384 ) ;
if ( V_400 -> V_271 >= V_11 -> V_405 ) {
struct V_399 V_410 = {
. V_271 = 32000 ,
. V_254 = 48000 ,
. integer = 1 ,
} ;
return F_249 ( V_409 , & V_410 ) ;
} else if ( V_400 -> V_254 <= V_11 -> V_403 && V_11 -> V_14 == V_19 ) {
struct V_399 V_410 = {
. V_271 = 128000 ,
. V_254 = 192000 ,
. integer = 1 ,
} ;
return F_249 ( V_409 , & V_410 ) ;
} else if ( V_400 -> V_254 <= V_11 -> V_404 ) {
struct V_399 V_410 = {
. V_271 = 64000 ,
. V_254 = 96000 ,
. integer = 1 ,
} ;
return F_249 ( V_409 , & V_410 ) ;
}
return 0 ;
}
static int F_253 ( struct V_363 * V_160 )
{
struct V_11 * V_11 = F_222 ( V_160 ) ;
struct V_374 * V_375 = V_160 -> V_375 ;
if ( F_14 ( V_11 ) )
return - V_28 ;
if ( F_27 ( V_11 , 1 ) )
return - V_28 ;
F_44 ( & V_11 -> V_49 ) ;
F_254 ( V_160 ) ;
V_375 -> V_411 = V_412 ;
V_375 -> V_413 = V_11 -> V_105 ;
V_375 -> V_414 = V_106 ;
V_11 -> V_67 = V_415 -> V_416 ;
V_11 -> V_361 = V_160 ;
F_46 ( & V_11 -> V_49 ) ;
F_255 ( V_375 , 0 , 32 , 24 ) ;
F_256 ( V_375 , 0 , V_385 , & V_417 ) ;
if ( V_11 -> V_225 ) {
V_375 -> V_411 . V_418 = V_375 -> V_411 . V_419 = V_11 -> V_119 ;
} else if ( V_11 -> V_14 == V_19 ) {
V_375 -> V_411 . V_419 = 192000 ;
V_375 -> V_411 . V_420 = V_421 ;
F_256 ( V_375 , 0 , V_384 , & V_422 ) ;
}
if ( V_11 -> V_14 == V_19 ) {
V_375 -> V_411 . V_423 = V_11 -> V_406 ;
V_375 -> V_411 . V_424 = V_11 -> V_408 ;
}
F_257 ( V_375 , 0 , V_401 ,
F_247 , V_11 ,
V_401 , - 1 ) ;
F_257 ( V_375 , 0 , V_401 ,
F_250 , V_11 ,
V_384 , - 1 ) ;
F_257 ( V_375 , 0 , V_384 ,
F_251 , V_11 ,
V_401 , - 1 ) ;
if ( V_17 != V_11 -> V_14 ) {
V_11 -> V_204 = V_11 -> V_202 ;
V_11 -> V_305 -> V_425 [ 0 ] . V_426 &= ~ V_427 ;
F_258 ( V_11 -> V_172 , V_428 |
V_429 , & V_11 -> V_305 -> V_139 ) ;
}
return 0 ;
}
static int F_259 ( struct V_363 * V_160 )
{
struct V_11 * V_11 = F_222 ( V_160 ) ;
F_44 ( & V_11 -> V_49 ) ;
V_11 -> V_67 = - 1 ;
V_11 -> V_361 = NULL ;
F_46 ( & V_11 -> V_49 ) ;
if ( V_17 != V_11 -> V_14 ) {
V_11 -> V_305 -> V_425 [ 0 ] . V_426 |= V_427 ;
F_258 ( V_11 -> V_172 , V_428 |
V_429 , & V_11 -> V_305 -> V_139 ) ;
}
return 0 ;
}
static int F_260 ( struct V_363 * V_160 )
{
struct V_11 * V_11 = F_222 ( V_160 ) ;
struct V_374 * V_375 = V_160 -> V_375 ;
if ( F_14 ( V_11 ) )
return - V_28 ;
if ( F_27 ( V_11 , 1 ) )
return - V_28 ;
F_44 ( & V_11 -> V_49 ) ;
F_254 ( V_160 ) ;
V_375 -> V_411 = V_430 ;
V_375 -> V_413 = V_11 -> V_320 ;
V_375 -> V_414 = V_106 ;
V_11 -> V_68 = V_415 -> V_416 ;
V_11 -> V_357 = V_160 ;
F_46 ( & V_11 -> V_49 ) ;
F_255 ( V_375 , 0 , 32 , 24 ) ;
F_256 ( V_375 , 0 , V_385 , & V_417 ) ;
if ( V_11 -> V_14 == V_19 ) {
V_375 -> V_411 . V_423 = V_11 -> V_403 ;
V_375 -> V_411 . V_424 = V_11 -> V_405 ;
V_375 -> V_411 . V_419 = 192000 ;
V_375 -> V_411 . V_420 = V_421 ;
F_256 ( V_375 , 0 , V_384 , & V_422 ) ;
}
F_257 ( V_375 , 0 , V_401 ,
F_244 , V_11 ,
V_401 , - 1 ) ;
F_257 ( V_375 , 0 , V_401 ,
F_248 , V_11 ,
V_384 , - 1 ) ;
F_257 ( V_375 , 0 , V_384 ,
F_252 , V_11 ,
V_401 , - 1 ) ;
return 0 ;
}
static int F_261 ( struct V_363 * V_160 )
{
struct V_11 * V_11 = F_222 ( V_160 ) ;
F_44 ( & V_11 -> V_49 ) ;
V_11 -> V_68 = - 1 ;
V_11 -> V_357 = NULL ;
F_46 ( & V_11 -> V_49 ) ;
return 0 ;
}
static inline int F_262 ( void T_6 * V_431 , void T_8 * V_369 )
{
T_2 V_22 = F_13 ( V_369 ) ;
return F_227 ( V_431 , & V_22 , 4 ) ;
}
static inline int F_263 ( void T_6 * V_431 , void T_8 * V_432 , void T_8 * V_433 )
{
T_2 V_434 , V_435 ;
T_4 V_436 ;
V_434 = F_13 ( V_432 ) ;
V_435 = F_13 ( V_433 ) ;
V_436 = ( ( T_4 ) V_435 << 32 ) | V_434 ;
return F_227 ( V_431 , & V_436 , 8 ) ;
}
static inline int F_264 ( void T_6 * V_431 , void T_8 * V_432 , void T_8 * V_433 )
{
T_2 V_434 , V_435 ;
T_4 V_436 ;
V_434 = F_13 ( V_432 ) & 0xffffff00 ;
V_435 = F_13 ( V_433 ) & 0xffffff00 ;
V_436 = ( ( T_4 ) V_435 << 32 ) | V_434 ;
return F_227 ( V_431 , & V_436 , 8 ) ;
}
static int F_265 ( struct V_11 * V_11 , struct V_437 T_6 * V_438 )
{
int V_439 = 0 ;
int V_31 , V_440 , V_441 , V_442 ;
if ( F_12 ( V_11 , V_24 ) & V_443 )
V_439 = 1 ;
V_441 = V_439 ? 14 : 26 ;
for ( V_31 = 0 , V_440 = 0 ; V_31 < 26 ; ++ V_31 ) {
if ( V_439 && ( V_31 & 4 ) )
continue;
V_442 = V_444 - V_440 * 4 ;
if ( F_262 ( & V_438 -> V_445 [ V_31 ] , V_11 -> V_23 + V_442 ) )
return - V_372 ;
V_442 -= V_441 * 4 ;
if ( F_262 ( & V_438 -> V_446 [ V_31 ] , V_11 -> V_23 + V_442 ) )
return - V_372 ;
V_442 -= V_441 * 4 ;
if ( F_262 ( & V_438 -> V_447 [ V_31 ] , V_11 -> V_23 + V_442 ) )
return - V_372 ;
V_442 = V_448 + V_440 * 8 ;
if ( F_264 ( & V_438 -> V_449 [ V_31 ] , V_11 -> V_23 + V_442 ,
V_11 -> V_23 + V_442 + 4 ) )
return - V_372 ;
V_442 += V_441 * 8 ;
if ( F_264 ( & V_438 -> V_450 [ V_31 ] , V_11 -> V_23 + V_442 ,
V_11 -> V_23 + V_442 + 4 ) )
return - V_372 ;
V_442 += V_441 * 8 ;
if ( F_264 ( & V_438 -> V_451 [ V_31 ] , V_11 -> V_23 + V_442 ,
V_11 -> V_23 + V_442 + 4 ) )
return - V_372 ;
V_440 ++ ;
}
return 0 ;
}
static int F_266 ( struct V_11 * V_11 , struct V_437 T_6 * V_438 )
{
int V_31 , V_440 ;
struct V_452 T_8 * V_453 ;
int V_439 = 0 ;
if ( F_12 ( V_11 , V_24 ) & V_443 )
V_439 = 1 ;
V_453 = (struct V_452 T_8 * ) ( V_11 -> V_23 + V_454 ) ;
for ( V_31 = 0 , V_440 = 0 ; V_31 < 16 ; ++ V_31 , ++ V_440 ) {
if ( F_262 ( & V_438 -> V_445 [ V_31 ] , & V_453 -> V_455 [ V_440 ] ) )
return - V_372 ;
if ( F_262 ( & V_438 -> V_446 [ V_31 ] , & V_453 -> V_456 [ V_440 ] ) )
return - V_372 ;
if ( F_262 ( & V_438 -> V_447 [ V_31 ] , & V_453 -> V_457 [ V_440 ] ) )
return - V_372 ;
if ( F_263 ( & V_438 -> V_449 [ V_31 ] , & V_453 -> V_458 [ V_440 ] ,
& V_453 -> V_459 [ V_440 ] ) )
return - V_372 ;
if ( F_263 ( & V_438 -> V_450 [ V_31 ] , & V_453 -> V_460 [ V_440 ] ,
& V_453 -> V_461 [ V_440 ] ) )
return - V_372 ;
if ( F_263 ( & V_438 -> V_451 [ V_31 ] , & V_453 -> V_462 [ V_440 ] ,
& V_453 -> V_463 [ V_440 ] ) )
return - V_372 ;
if ( V_439 && V_31 == 3 ) V_31 += 4 ;
}
return 0 ;
}
static int F_267 ( struct V_11 * V_11 , struct V_437 T_6 * V_438 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < 26 ; V_31 ++ ) {
if ( F_262 ( & V_438 -> V_446 [ V_31 ] ,
V_11 -> V_23 + V_464 + V_31 * 4 ) )
return - V_372 ;
if ( F_262 ( & V_438 -> V_445 [ V_31 ] ,
V_11 -> V_23 + V_465 + V_31 * 4 ) )
return - V_372 ;
}
for ( V_31 = 0 ; V_31 < 28 ; V_31 ++ ) {
if ( F_262 ( & V_438 -> V_447 [ V_31 ] ,
V_11 -> V_23 + V_466 + V_31 * 4 ) )
return - V_372 ;
}
for ( V_31 = 0 ; V_31 < 26 ; ++ V_31 ) {
if ( F_263 ( & V_438 -> V_450 [ V_31 ] ,
V_11 -> V_23 + V_467 + V_31 * 8 + 4 ,
V_11 -> V_23 + V_467 + V_31 * 8 ) )
return - V_372 ;
if ( F_263 ( & V_438 -> V_449 [ V_31 ] ,
V_11 -> V_23 + V_468 + V_31 * 8 + 4 ,
V_11 -> V_23 + V_468 + V_31 * 8 ) )
return - V_372 ;
}
return 0 ;
}
static int F_268 ( struct V_469 * V_411 , struct V_470 * V_470 , unsigned int V_389 , unsigned long V_343 )
{
struct V_11 * V_11 = V_411 -> V_164 ;
void T_6 * V_471 = ( void T_6 * ) V_343 ;
int V_301 ;
switch ( V_389 ) {
case V_472 : {
struct V_437 T_6 * V_438 = (struct V_437 T_6 * ) V_343 ;
V_301 = F_14 ( V_11 ) ;
if ( V_301 < 0 )
return V_301 ;
V_301 = F_27 ( V_11 , 1 ) ;
if ( V_301 < 0 )
return V_301 ;
if ( ! ( V_11 -> V_26 & V_27 ) ) {
F_15 ( V_57 L_173 ) ;
return - V_120 ;
}
switch ( V_11 -> V_14 ) {
case V_20 :
return F_265 ( V_11 , V_438 ) ;
case V_19 :
return F_266 ( V_11 , V_438 ) ;
default:
return F_267 ( V_11 , V_438 ) ;
}
}
case V_473 : {
struct V_474 V_387 ;
unsigned long V_32 ;
int V_31 ;
V_301 = F_14 ( V_11 ) ;
if ( V_301 < 0 )
return V_301 ;
V_301 = F_27 ( V_11 , 1 ) ;
if ( V_301 < 0 )
return V_301 ;
memset ( & V_387 , 0 , sizeof( V_387 ) ) ;
F_23 ( & V_11 -> V_49 , V_32 ) ;
V_387 . V_313 = ( unsigned char ) F_149 ( V_11 ) ;
V_387 . V_475 = ( unsigned char ) F_170 ( V_11 ) ;
if ( V_11 -> V_14 != V_19 )
V_387 . V_476 = ( unsigned char ) F_174 ( V_11 ) ;
V_387 . V_477 = ( unsigned char ) F_172 ( V_11 ) ;
for ( V_31 = 0 ; V_31 < ( ( V_11 -> V_14 != V_15 && V_11 -> V_14 != V_17 && V_11 -> V_14 != V_19 ) ? 3 : 1 ) ; ++ V_31 )
V_387 . V_478 [ V_31 ] = ( unsigned char ) F_176 ( V_11 , V_31 ) ;
V_387 . V_479 = ( unsigned char ) F_87 ( V_11 ) ;
V_387 . V_480 = ( unsigned char ) F_94 ( V_11 ) ;
V_387 . V_481 = ( unsigned char ) F_98 ( V_11 ) ;
V_387 . V_482 = ( unsigned char ) F_102 ( V_11 ) ;
V_387 . V_483 = ( unsigned char ) F_106 ( V_11 ) ;
V_387 . V_484 = F_33 ( V_11 ) ;
V_387 . V_119 = V_11 -> V_119 ;
V_387 . V_485 = F_34 ( V_11 ) ;
V_387 . V_315 = ( unsigned char ) F_116 ( V_11 ) ;
V_387 . V_316 = ( unsigned char ) F_119 ( V_11 ) ;
V_387 . V_314 = ( unsigned char ) F_35 ( V_11 ) ;
V_387 . V_486 = ( unsigned char ) F_156 ( V_11 ) ;
if ( V_11 -> V_14 == V_19 ) {
V_387 . V_487 = ( unsigned char ) F_126 ( V_11 ) ;
V_387 . V_488 = ( unsigned char ) F_131 ( V_11 ) ;
V_387 . V_489 = ( unsigned char ) F_136 ( V_11 ) ;
V_387 . V_490 = ( unsigned char ) F_141 ( V_11 ) ;
} else if ( V_11 -> V_14 == V_17 ) {
V_387 . V_487 = ( unsigned char ) F_183 ( V_11 ) ;
V_387 . V_488 = ( unsigned char ) F_188 ( V_11 ) ;
}
if ( V_11 -> V_14 == V_19 || V_11 -> V_14 == V_20 )
V_387 . V_491 = ( unsigned char ) F_145 ( V_11 ) ;
F_25 ( & V_11 -> V_49 , V_32 ) ;
if ( F_227 ( V_471 , & V_387 , sizeof( V_387 ) ) )
return - V_372 ;
break;
}
case V_492 : {
struct V_493 V_494 ;
if ( V_11 -> V_14 != V_19 ) return - V_120 ;
V_494 . V_495 = V_11 -> V_405 - V_496 ;
V_494 . V_497 = V_11 -> V_408 - V_496 ;
if ( F_227 ( V_471 , & V_494 , sizeof( V_494 ) ) )
return - V_372 ;
break;
}
case V_498 : {
struct V_499 V_499 ;
int V_301 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) return - V_120 ;
if ( V_11 -> V_14 == V_500 ) {
if ( ( V_301 = F_26 ( V_11 ) ) < 0 )
return V_301 ;
}
V_499 . V_14 = V_11 -> V_14 ;
V_499 . V_18 = V_11 -> V_18 ;
if ( ( V_301 = F_227 ( V_471 , & V_499 , sizeof( V_499 ) ) ) )
return - V_372 ;
break;
}
case V_501 : {
struct V_502 T_6 * V_35 ;
T_2 T_6 * V_503 ;
int V_301 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) return - V_120 ;
if ( V_11 -> V_14 == V_500 ) return - V_120 ;
if ( V_11 -> V_26 & ( V_58 | V_27 ) )
return - V_130 ;
F_15 ( V_48 L_174 ) ;
V_35 = (struct V_502 T_6 * ) V_471 ;
if ( F_269 ( V_503 , & V_35 -> V_503 ) )
return - V_372 ;
if ( F_14 ( V_11 ) )
return - V_28 ;
if ( ! V_11 -> V_34 ) {
V_11 -> V_34 = F_270 ( V_44 ) ;
if ( ! V_11 -> V_34 )
return - V_9 ;
}
if ( F_225 ( V_11 -> V_34 , V_503 ,
V_44 ) ) {
F_271 ( V_11 -> V_34 ) ;
V_11 -> V_34 = NULL ;
return - V_372 ;
}
V_11 -> V_26 |= V_58 ;
if ( ( V_301 = F_19 ( V_11 ) ) < 0 )
return V_301 ;
if ( ! ( V_11 -> V_26 & V_47 ) ) {
if ( ( V_301 = F_272 ( V_11 ) ) < 0 )
return V_301 ;
F_273 ( V_11 ) ;
F_274 ( V_11 ) ;
if ( ( V_301 = F_275 ( V_11 -> V_172 , V_11 ) ) < 0 ) {
F_15 ( V_57 L_175 ) ;
return V_301 ;
}
}
break;
}
case V_504 : {
struct V_505 T_6 * V_506 = (struct V_505 T_6 * ) V_471 ;
if ( F_227 ( V_506 -> V_507 , V_11 -> V_64 , sizeof( unsigned short ) * V_63 ) )
return - V_372 ;
break;
}
default:
return - V_120 ;
}
return 0 ;
}
static int F_276 ( struct V_171 * V_172 , struct V_11 * V_11 )
{
struct V_469 * V_411 ;
int V_301 ;
if ( ( V_301 = F_277 ( V_172 , L_176 , 0 , & V_411 ) ) < 0 )
return V_301 ;
V_11 -> V_508 = V_411 ;
V_411 -> V_164 = V_11 ;
strcpy ( V_411 -> V_175 , L_177 ) ;
V_411 -> V_509 . V_510 = F_268 ;
V_411 -> V_509 . V_511 = F_268 ;
return 0 ;
}
static int F_278 ( struct V_171 * V_172 , struct V_11 * V_11 )
{
struct V_512 * V_358 ;
int V_301 ;
if ( ( V_301 = F_279 ( V_172 , V_11 -> V_318 , 0 , 1 , 1 , & V_358 ) ) < 0 )
return V_301 ;
V_11 -> V_358 = V_358 ;
V_358 -> V_164 = V_11 ;
strcpy ( V_358 -> V_175 , V_11 -> V_318 ) ;
F_280 ( V_358 , V_362 , & V_513 ) ;
F_280 ( V_358 , V_360 , & V_514 ) ;
V_358 -> V_180 = V_515 ;
return 0 ;
}
static void F_216 ( struct V_11 * V_11 )
{
V_11 -> V_45 |= V_516 ;
F_10 ( V_11 , V_39 , V_11 -> V_45 ) ;
}
static int F_272 ( struct V_11 * V_11 )
{
int V_31 ;
if ( F_20 ( V_11 , 0 , 100 ) ) {
F_15 ( V_57 L_178 ) ;
return - V_28 ;
}
for ( V_31 = 0 ; V_31 < V_11 -> V_275 ; ++ V_31 ) {
F_10 ( V_11 , V_517 + ( 4 * V_31 ) , 1 ) ;
F_10 ( V_11 , V_518 + ( 4 * V_31 ) , 1 ) ;
}
return 0 ;
}
static void F_273 ( struct V_11 * V_11 )
{
int V_69 , V_519 , V_520 ;
switch ( V_11 -> V_14 ) {
case V_16 :
V_11 -> V_318 = L_179 ;
V_11 -> V_405 = V_11 -> V_408 = V_521 ;
V_11 -> V_404 = V_11 -> V_407 = V_522 ;
break;
case V_20 :
V_11 -> V_318 = L_180 ;
V_11 -> V_405 = V_11 -> V_408 = V_523 ;
V_11 -> V_404 = V_11 -> V_407 = V_524 ;
break;
case V_19 :
V_69 = F_12 ( V_11 , V_24 ) ;
V_519 = ( V_69 & V_525 ) ? 0 : 4 ;
V_520 = ( V_69 & V_526 ) ? 0 : 4 ;
V_11 -> V_318 = L_181 ;
V_11 -> V_405 = V_496 + V_519 ;
V_11 -> V_404 = V_527 + V_519 ;
V_11 -> V_403 = V_528 + V_519 ;
V_11 -> V_408 = V_496 + V_520 ;
V_11 -> V_407 = V_527 + V_520 ;
V_11 -> V_406 = V_528 + V_520 ;
break;
case V_15 :
V_11 -> V_318 = L_182 ;
V_11 -> V_405 = V_11 -> V_408 = V_529 ;
V_11 -> V_404 = V_11 -> V_407 = V_530 ;
break;
case V_17 :
V_11 -> V_318 = L_183 ;
V_11 -> V_405 = V_531 - 1 ;
V_11 -> V_408 = V_531 ;
V_11 -> V_404 = V_531 - 1 ;
V_11 -> V_407 = V_531 ;
break;
default:
break;
}
}
static void F_274 ( struct V_11 * V_11 )
{
F_55 ( V_11 , 0 ) ;
F_55 ( V_11 , 1 ) ;
}
static int F_275 ( struct V_171 * V_172 , struct V_11 * V_11 )
{
int V_301 ;
if ( ( V_301 = F_278 ( V_172 , V_11 ) ) < 0 ) {
F_15 ( V_57 L_184 ) ;
return V_301 ;
}
if ( ( V_301 = F_72 ( V_172 , V_11 , 0 ) ) < 0 ) {
F_15 ( V_57 L_185 ) ;
return V_301 ;
}
if ( V_11 -> V_14 == V_16 || V_11 -> V_14 == V_20 ) {
if ( ( V_301 = F_72 ( V_172 , V_11 , 1 ) ) < 0 ) {
F_15 ( V_57 L_186 ) ;
return V_301 ;
}
}
if ( ( V_301 = F_202 ( V_172 , V_11 ) ) < 0 ) {
F_15 ( V_57 L_187 ) ;
return V_301 ;
}
F_208 ( V_11 ) ;
V_11 -> V_119 = - 1 ;
V_11 -> V_67 = - 1 ;
V_11 -> V_68 = - 1 ;
V_11 -> V_357 = NULL ;
V_11 -> V_361 = NULL ;
if ( ( V_301 = F_24 ( V_11 ) ) < 0 ) {
F_15 ( V_57 L_188 ) ;
return V_301 ;
}
if ( ! ( V_11 -> V_26 & V_47 ) ) {
strcpy ( V_172 -> V_174 , L_189 ) ;
sprintf ( V_172 -> V_532 , L_190 , V_11 -> V_318 ,
V_11 -> V_322 , V_11 -> V_321 ) ;
if ( ( V_301 = F_281 ( V_172 ) ) < 0 ) {
F_15 ( V_57 L_191 ) ;
return V_301 ;
}
V_11 -> V_26 |= V_47 ;
}
return 0 ;
}
static int F_28 ( struct V_11 * V_11 )
{
const char * V_533 ;
const struct V_35 * V_534 ;
int V_301 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 )
return 0 ;
if ( V_11 -> V_14 == V_500 ) {
if ( ( V_301 = F_26 ( V_11 ) ) < 0 )
return V_301 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 )
return 0 ;
}
switch ( V_11 -> V_14 ) {
case V_17 :
V_533 = L_192 ;
break;
case V_15 :
if ( V_11 -> V_18 == 0xa )
V_533 = L_193 ;
else
V_533 = L_194 ;
break;
case V_16 :
if ( V_11 -> V_18 == 0xa )
V_533 = L_195 ;
else
V_533 = L_196 ;
break;
default:
F_15 ( V_57 L_197 , V_11 -> V_14 ) ;
return - V_120 ;
}
if ( F_282 ( & V_534 , V_533 , & V_11 -> V_2 -> V_6 ) ) {
F_15 ( V_57 L_198 , V_533 ) ;
return - V_535 ;
}
if ( V_534 -> V_5 < V_44 ) {
F_15 ( V_57 L_199 ,
( int ) V_534 -> V_5 , V_44 ) ;
return - V_120 ;
}
V_11 -> V_35 = V_534 ;
V_11 -> V_26 |= V_58 ;
if ( ( V_301 = F_19 ( V_11 ) ) < 0 )
return V_301 ;
if ( ! ( V_11 -> V_26 & V_47 ) ) {
if ( ( V_301 = F_272 ( V_11 ) ) < 0 )
return V_301 ;
if ( ( V_301 = F_276 ( V_11 -> V_172 , V_11 ) ) < 0 ) {
F_15 ( V_57 L_200 ) ;
return V_301 ;
}
F_273 ( V_11 ) ;
F_274 ( V_11 ) ;
if ( ( V_301 = F_275 ( V_11 -> V_172 , V_11 ) ) < 0 ) {
F_15 ( V_57 L_175 ) ;
return V_301 ;
}
}
return 0 ;
}
static int F_283 ( struct V_171 * V_172 ,
struct V_11 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_301 ;
int V_536 = 0 ;
int V_537 = 0 ;
V_11 -> V_321 = - 1 ;
V_11 -> V_26 = 0 ;
V_11 -> V_173 [ 0 ] . V_163 = NULL ;
V_11 -> V_173 [ 1 ] . V_163 = NULL ;
V_11 -> V_173 [ 0 ] . V_155 = NULL ;
V_11 -> V_173 [ 1 ] . V_155 = NULL ;
V_11 -> V_173 [ 0 ] . V_154 = NULL ;
V_11 -> V_173 [ 1 ] . V_154 = NULL ;
V_11 -> V_173 [ 0 ] . V_156 = 0 ;
V_11 -> V_173 [ 1 ] . V_156 = 0 ;
F_73 ( & V_11 -> V_173 [ 0 ] . V_49 ) ;
F_73 ( & V_11 -> V_173 [ 1 ] . V_49 ) ;
V_11 -> V_23 = NULL ;
V_11 -> V_93 = 0 ;
V_11 -> V_45 = 0 ;
V_11 -> V_14 = V_500 ;
V_11 -> V_275 = 26 ;
V_11 -> V_172 = V_172 ;
F_73 ( & V_11 -> V_49 ) ;
F_284 ( & V_11 -> V_165 , F_217 , ( unsigned long ) V_11 ) ;
F_285 ( V_11 -> V_2 , V_538 , & V_11 -> V_18 ) ;
V_11 -> V_18 &= 0xff ;
F_286 ( V_11 -> V_2 , V_539 , 0xFF ) ;
strcpy ( V_172 -> V_540 , L_201 ) ;
strcpy ( V_172 -> V_541 , L_202 ) ;
if ( V_11 -> V_18 < 0xa )
return - V_36 ;
else if ( V_11 -> V_18 < 0x64 )
V_11 -> V_318 = L_203 ;
else if ( V_11 -> V_18 < 0x96 ) {
V_11 -> V_318 = L_204 ;
V_536 = 1 ;
} else {
V_11 -> V_318 = L_205 ;
V_11 -> V_275 = 16 ;
V_537 = 1 ;
}
if ( ( V_301 = F_287 ( V_2 ) ) < 0 )
return V_301 ;
F_288 ( V_11 -> V_2 ) ;
if ( ( V_301 = F_289 ( V_2 , L_171 ) ) < 0 )
return V_301 ;
V_11 -> V_322 = F_290 ( V_2 , 0 ) ;
if ( ( V_11 -> V_23 = F_291 ( V_11 -> V_322 , V_542 ) ) == NULL ) {
F_15 ( V_57 L_206 , V_11 -> V_322 , V_11 -> V_322 + V_542 - 1 ) ;
return - V_130 ;
}
if ( F_292 ( V_2 -> V_321 , F_218 , V_543 ,
V_544 , V_11 ) ) {
F_15 ( V_57 L_207 , V_2 -> V_321 ) ;
return - V_130 ;
}
V_11 -> V_321 = V_2 -> V_321 ;
V_11 -> V_95 = 0 ;
V_11 -> V_270 = 1 ;
V_11 -> V_100 = 0 ;
if ( ( V_301 = F_212 ( V_11 ) ) < 0 )
return V_301 ;
if ( ! V_536 && ! V_537 ) {
V_301 = F_16 ( V_11 , 1000 , 10 ) ;
if ( V_301 < 0 )
return V_301 ;
if ( ( F_12 ( V_11 , V_24 ) & V_38 ) != 0 ) {
if ( ( V_301 = F_28 ( V_11 ) ) < 0 )
F_15 ( V_57 L_208 ) ;
else
return 0 ;
F_15 ( V_48 L_209 ) ;
if ( ( V_301 = F_276 ( V_172 , V_11 ) ) < 0 )
return V_301 ;
return 0 ;
} else {
F_15 ( V_48 L_210 ) ;
if ( F_12 ( V_11 , V_53 ) & V_54 )
V_11 -> V_14 = V_17 ;
else if ( F_12 ( V_11 , V_53 ) & V_55 )
V_11 -> V_14 = V_15 ;
else
V_11 -> V_14 = V_16 ;
}
}
if ( ( V_301 = F_272 ( V_11 ) ) != 0 )
return V_301 ;
if ( V_536 )
V_11 -> V_14 = V_20 ;
if ( V_537 )
V_11 -> V_14 = V_19 ;
if ( ( V_301 = F_276 ( V_172 , V_11 ) ) < 0 )
return V_301 ;
F_273 ( V_11 ) ;
F_274 ( V_11 ) ;
V_11 -> V_26 |= V_27 ;
if ( ( V_301 = F_275 ( V_172 , V_11 ) ) < 0 )
return V_301 ;
return 0 ;
}
static int F_293 ( struct V_11 * V_11 )
{
if ( V_11 -> V_322 ) {
F_62 ( & V_11 -> V_165 ) ;
V_11 -> V_93 &= ~ ( V_103 | V_102 | V_158 | V_157 ) ;
F_10 ( V_11 , V_104 , V_11 -> V_93 ) ;
}
if ( V_11 -> V_321 >= 0 )
F_294 ( V_11 -> V_321 , ( void * ) V_11 ) ;
F_211 ( V_11 ) ;
if ( V_11 -> V_35 )
F_295 ( V_11 -> V_35 ) ;
F_271 ( V_11 -> V_34 ) ;
if ( V_11 -> V_23 )
F_296 ( V_11 -> V_23 ) ;
if ( V_11 -> V_322 )
F_297 ( V_11 -> V_2 ) ;
F_298 ( V_11 -> V_2 ) ;
return 0 ;
}
static void F_299 ( struct V_171 * V_172 )
{
struct V_11 * V_11 = V_172 -> V_164 ;
if ( V_11 )
F_293 ( V_11 ) ;
}
static int F_300 ( struct V_1 * V_2 ,
const struct V_545 * V_546 )
{
static int V_6 ;
struct V_11 * V_11 ;
struct V_171 * V_172 ;
int V_301 ;
if ( V_6 >= V_547 )
return - V_36 ;
if ( ! V_548 [ V_6 ] ) {
V_6 ++ ;
return - V_535 ;
}
V_301 = F_301 ( V_286 [ V_6 ] , V_139 [ V_6 ] , V_549 ,
sizeof( struct V_11 ) , & V_172 ) ;
if ( V_301 < 0 )
return V_301 ;
V_11 = V_172 -> V_164 ;
V_172 -> V_550 = F_299 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_2 = V_2 ;
F_302 ( V_172 , & V_2 -> V_6 ) ;
if ( ( V_301 = F_283 ( V_172 , V_11 ) ) < 0 ) {
F_303 ( V_172 ) ;
return V_301 ;
}
strcpy ( V_172 -> V_174 , L_189 ) ;
sprintf ( V_172 -> V_532 , L_190 , V_11 -> V_318 ,
V_11 -> V_322 , V_11 -> V_321 ) ;
if ( ( V_301 = F_281 ( V_172 ) ) < 0 ) {
F_303 ( V_172 ) ;
return V_301 ;
}
F_304 ( V_2 , V_172 ) ;
V_6 ++ ;
return 0 ;
}
static void F_305 ( struct V_1 * V_2 )
{
F_303 ( F_306 ( V_2 ) ) ;
F_304 ( V_2 , NULL ) ;
}
