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
if ( ( F_12 ( V_11 , V_24 ) & V_33 ) != 0 ) {
F_15 ( L_3 ) ;
F_10 ( V_11 , V_34 , V_35 ) ;
F_10 ( V_11 , V_36 , 0 ) ;
if ( F_20 ( V_11 , 0 , V_37 ) ) {
F_15 ( L_4 ) ;
return - V_28 ;
}
F_10 ( V_11 , V_34 , V_38 ) ;
for ( V_31 = 0 ; V_31 < 24413 ; ++ V_31 ) {
F_10 ( V_11 , V_36 , V_11 -> V_39 [ V_31 ] ) ;
if ( F_20 ( V_11 , 127 , V_37 ) ) {
F_15 ( L_5 ) ;
return - V_28 ;
}
}
F_21 ( 3 ) ;
if ( F_20 ( V_11 , 0 , V_37 ) ) {
F_15 ( L_6 ) ;
return - V_28 ;
}
#ifdef F_22
V_11 -> V_40 = V_41 ;
#else
V_11 -> V_40 = 0 ;
#endif
F_10 ( V_11 , V_34 , V_11 -> V_40 ) ;
F_15 ( L_7 ) ;
}
if ( V_11 -> V_26 & V_42 ) {
F_15 ( V_43 L_8 ) ;
F_23 ( & V_11 -> V_44 , V_32 ) ;
F_24 ( V_11 ) ;
F_25 ( & V_11 -> V_44 , V_32 ) ;
}
V_11 -> V_26 |= V_27 ;
return 0 ;
}
static int F_26 ( struct V_11 * V_11 )
{
if ( ( F_12 ( V_11 , V_24 ) & V_33 ) != 0 ) {
F_10 ( V_11 , V_34 , V_45 ) ;
F_10 ( V_11 , V_36 , 0 ) ;
if ( F_20 ( V_11 , 0 , V_46 ) < 0 )
return - V_28 ;
F_10 ( V_11 , V_34 , V_38 ) ;
F_10 ( V_11 , V_36 , 0 ) ;
if ( F_20 ( V_11 , 0 , V_46 ) ) {
F_10 ( V_11 , V_34 , V_47 ) ;
F_10 ( V_11 , V_34 , V_38 ) ;
if ( F_20 ( V_11 , 0 , V_46 ) )
V_11 -> V_14 = V_17 ;
else
V_11 -> V_14 = V_15 ;
} else {
V_11 -> V_14 = V_16 ;
}
} else {
if ( F_12 ( V_11 , V_48 ) & V_49 )
V_11 -> V_14 = V_17 ;
else if ( F_12 ( V_11 , V_48 ) & V_50 )
V_11 -> V_14 = V_15 ;
else
V_11 -> V_14 = V_16 ;
}
return 0 ;
}
static int F_27 ( struct V_11 * V_11 , int V_51 )
{
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 )
return 0 ;
if ( ( F_12 ( V_11 , V_24 ) & V_33 ) != 0 ) {
V_11 -> V_26 &= ~ V_27 ;
if ( ! V_51 )
return - V_28 ;
F_15 ( V_52 L_9 ) ;
if ( ! ( V_11 -> V_26 & V_53 ) ) {
#ifdef F_28
if ( ! F_29 ( V_11 ) )
return 0 ;
#endif
F_15 ( V_52
L_10
L_11 ) ;
return - V_28 ;
}
if ( F_19 ( V_11 ) != 0 ) {
F_15 ( V_52
L_12
L_13 ) ;
return - V_28 ;
}
}
return 0 ;
}
static int F_20 ( struct V_11 * V_11 , int V_54 , int V_55 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ ) {
if ( ( int ) ( F_12 ( V_11 , V_56 ) & 0xff ) <= V_54 )
return 0 ;
F_30 ( 100 ) ;
}
F_15 ( L_14 ,
V_54 , V_55 ) ;
return - 1 ;
}
static int F_31 ( struct V_11 * V_11 , unsigned int V_57 )
{
if ( V_57 >= V_58 )
return 0 ;
return V_11 -> V_59 [ V_57 ] ;
}
static int F_32 ( struct V_11 * V_11 , unsigned int V_57 , unsigned short V_60 )
{
unsigned int V_61 ;
if ( V_57 >= V_58 )
return - 1 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) {
if ( V_11 -> V_14 == V_19 && V_57 >= 512 )
return 0 ;
if ( V_11 -> V_14 == V_20 && V_57 >= 1352 )
return 0 ;
V_11 -> V_59 [ V_57 ] = V_60 ;
V_61 = V_57 / 2 ;
F_10 ( V_11 , 4096 + ( V_61 * 4 ) ,
( V_11 -> V_59 [ ( V_57 & 0x7fe ) + 1 ] << 16 ) +
V_11 -> V_59 [ V_57 & 0x7fe ] ) ;
return 0 ;
} else {
V_61 = ( V_57 << 16 ) + V_60 ;
if ( F_20 ( V_11 , 127 , V_37 ) )
return - 1 ;
F_10 ( V_11 , V_36 , V_61 ) ;
V_11 -> V_59 [ V_57 ] = V_60 ;
}
return 0 ;
}
static int F_33 ( struct V_11 * V_11 )
{
unsigned long V_32 ;
int V_62 = 1 ;
F_23 ( & V_11 -> V_44 , V_32 ) ;
if ( ( V_11 -> V_63 != V_11 -> V_64 ) &&
( V_11 -> V_63 >= 0 ) && ( V_11 -> V_64 >= 0 ) )
V_62 = 0 ;
F_25 ( & V_11 -> V_44 , V_32 ) ;
return V_62 ;
}
static int F_34 ( struct V_11 * V_11 )
{
unsigned int V_65 = F_12 ( V_11 , V_24 ) ;
unsigned int V_66 = ( V_65 & V_67 ) ;
if ( V_11 -> V_14 == V_19 )
V_66 = ( V_65 & V_68 ) ;
if ( V_65 & V_69 )
return 0 ;
switch ( V_66 ) {
case V_70 : return 32000 ;
case V_71 : return 44100 ;
case V_72 : return 48000 ;
case V_73 : return 64000 ;
case V_74 : return 88200 ;
case V_75 : return 96000 ;
case V_76 :
if ( V_11 -> V_14 == V_19 ) return 128000 ;
break;
case V_77 :
if ( V_11 -> V_14 == V_19 ) return 176400 ;
break;
case V_78 :
if ( V_11 -> V_14 == V_19 ) return 192000 ;
break;
default:
break;
}
F_15 ( L_15 , V_66 , V_65 ) ;
return 0 ;
}
static int F_35 ( struct V_11 * V_11 )
{
unsigned int V_79 = F_12 ( V_11 , V_48 ) ;
unsigned int V_66 = V_79 & V_80 ;
if ( V_11 -> V_14 == V_19 &&
F_36 ( V_11 ) == V_81 )
return F_34 ( V_11 ) ;
switch ( V_66 ) {
case V_82 : return 32000 ;
case V_83 : return 44100 ;
case V_84 : return 48000 ;
case V_85 : return 64000 ;
case V_86 : return 88200 ;
case V_87 : return 96000 ;
default:
return 0 ;
}
}
static void F_37 ( struct V_11 * V_11 )
{
V_11 -> V_88 = 1 << ( ( F_38 ( V_11 -> V_89 ) + 8 ) ) ;
}
static T_2 F_39 ( struct V_11 * V_11 )
{
int V_90 ;
V_90 = F_12 ( V_11 , V_24 ) ;
if ( ! V_11 -> V_91 )
return ( V_90 & V_92 ) ? ( V_11 -> V_88 / 4 ) : 0 ;
V_90 &= V_93 ;
V_90 /= 4 ;
V_90 &= ( V_11 -> V_88 / 2 ) - 1 ;
return V_90 ;
}
static void F_40 ( struct V_11 * V_11 )
{
F_10 ( V_11 , V_94 , 0 ) ;
if ( V_11 -> V_14 == V_19 && V_11 -> V_18 >= 152 )
F_10 ( V_11 , V_95 , V_11 -> V_96 ) ;
}
static void F_41 ( struct V_11 * V_97 )
{
V_97 -> V_89 |= ( V_98 | V_99 ) ;
F_10 ( V_97 , V_100 , V_97 -> V_89 ) ;
}
static void F_42 ( struct V_11 * V_97 )
{
V_97 -> V_89 &= ~ ( V_99 | V_98 ) ;
F_10 ( V_97 , V_100 , V_97 -> V_89 ) ;
}
static void F_43 ( struct V_11 * V_11 )
{
memset ( V_11 -> V_101 , 0 , V_102 ) ;
}
static int F_44 ( struct V_11 * V_97 , unsigned int V_103 )
{
int V_104 ;
F_45 ( & V_97 -> V_44 ) ;
V_103 >>= 7 ;
V_104 = 0 ;
while ( V_103 ) {
V_104 ++ ;
V_103 >>= 1 ;
}
V_97 -> V_89 &= ~ V_105 ;
V_97 -> V_89 |= F_46 ( V_104 ) ;
F_10 ( V_97 , V_100 , V_97 -> V_89 ) ;
F_37 ( V_97 ) ;
F_47 ( & V_97 -> V_44 ) ;
return 0 ;
}
static void F_48 ( struct V_11 * V_11 , int V_106 )
{
T_3 V_104 ;
if ( V_106 >= 112000 )
V_106 /= 4 ;
else if ( V_106 >= 56000 )
V_106 /= 2 ;
V_104 = V_107 ;
V_104 = F_49 ( V_104 , V_106 ) ;
F_50 ( V_104 >> 32 ) ;
V_11 -> V_96 = V_104 ;
F_10 ( V_11 , V_95 , V_11 -> V_96 ) ;
}
static int F_51 ( struct V_11 * V_11 , int V_106 , int V_108 )
{
int V_109 = 0 ;
int V_110 ;
int V_66 ;
if ( ! ( V_11 -> V_89 & V_111 ) ) {
if ( V_108 ) {
F_15 ( V_52 L_16 ) ;
return - 1 ;
} else {
int V_112 = F_35 ( V_11 ) ;
int V_113 = F_34 ( V_11 ) ;
if ( ( V_113 == V_112 * 2 ) && ( F_36 ( V_11 ) >= V_114 ) )
F_15 ( V_43 L_17 ) ;
else if ( V_11 -> V_14 == V_19 && ( V_113 == V_112 * 4 ) && ( F_36 ( V_11 ) >= V_114 ) )
F_15 ( V_43 L_18 ) ;
else if ( V_106 != V_112 ) {
F_15 ( V_43 L_19 ) ;
return - 1 ;
}
}
}
V_110 = V_11 -> V_115 ;
if ( V_106 > 96000 && V_11 -> V_14 != V_19 )
return - V_116 ;
switch ( V_106 ) {
case 32000 :
if ( V_110 > 48000 )
V_109 = 1 ;
V_66 = V_117 ;
break;
case 44100 :
if ( V_110 > 48000 )
V_109 = 1 ;
V_66 = V_118 ;
break;
case 48000 :
if ( V_110 > 48000 )
V_109 = 1 ;
V_66 = V_119 ;
break;
case 64000 :
if ( V_110 <= 48000 || V_110 > 96000 )
V_109 = 1 ;
V_66 = V_120 ;
break;
case 88200 :
if ( V_110 <= 48000 || V_110 > 96000 )
V_109 = 1 ;
V_66 = V_121 ;
break;
case 96000 :
if ( V_110 <= 48000 || V_110 > 96000 )
V_109 = 1 ;
V_66 = V_122 ;
break;
case 128000 :
if ( V_110 < 128000 )
V_109 = 1 ;
V_66 = V_123 ;
break;
case 176400 :
if ( V_110 < 128000 )
V_109 = 1 ;
V_66 = V_124 ;
break;
case 192000 :
if ( V_110 < 128000 )
V_109 = 1 ;
V_66 = V_125 ;
break;
default:
return - V_116 ;
}
if ( V_109 && ( V_11 -> V_64 >= 0 || V_11 -> V_63 >= 0 ) ) {
F_15 ( L_20 ,
V_11 -> V_64 ,
V_11 -> V_63 ) ;
return - V_126 ;
}
V_11 -> V_89 &= ~ V_127 ;
V_11 -> V_89 |= V_66 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
if ( V_11 -> V_14 == V_19 && V_11 -> V_18 >= 152 )
F_48 ( V_11 , V_106 ) ;
if ( V_106 >= 128000 ) {
V_11 -> V_128 = V_129 ;
} else if ( V_106 > 48000 ) {
if ( V_11 -> V_14 == V_19 )
V_11 -> V_128 = V_130 ;
else
V_11 -> V_128 = V_131 ;
} else {
switch ( V_11 -> V_14 ) {
case V_17 :
case V_15 :
V_11 -> V_128 = V_132 ;
break;
case V_16 :
case V_20 :
V_11 -> V_128 = V_133 ;
break;
case V_19 :
V_11 -> V_128 = V_134 ;
break;
default:
break;
}
}
V_11 -> V_115 = V_106 ;
return 0 ;
}
static unsigned char F_52 ( struct V_11 * V_11 , int V_135 )
{
if ( V_135 )
return F_12 ( V_11 , V_136 ) ;
else
return F_12 ( V_11 , V_137 ) ;
}
static void F_53 ( struct V_11 * V_11 , int V_135 , int V_22 )
{
if ( V_135 )
F_10 ( V_11 , V_138 , V_22 ) ;
else
F_10 ( V_11 , V_139 , V_22 ) ;
}
static int F_54 ( struct V_11 * V_11 , int V_135 )
{
if ( V_135 )
return ( F_12 ( V_11 , V_140 ) & 0xff ) ;
else
return ( F_12 ( V_11 , V_141 ) & 0xff ) ;
}
static int F_55 ( struct V_11 * V_11 , int V_135 )
{
int V_142 ;
if ( V_135 )
V_142 = F_12 ( V_11 , V_143 ) & 0xff ;
else
V_142 = F_12 ( V_11 , V_144 ) & 0xff ;
if ( V_142 < 128 )
return 128 - V_142 ;
else
return 0 ;
}
static void F_56 ( struct V_11 * V_11 , int V_135 )
{
while ( F_54 ( V_11 , V_135 ) )
F_52 ( V_11 , V_135 ) ;
}
static int F_57 ( struct V_145 * V_146 )
{
unsigned long V_32 ;
int V_147 ;
int V_148 ;
int V_31 ;
unsigned char V_149 [ 128 ] ;
F_23 ( & V_146 -> V_44 , V_32 ) ;
if ( V_146 -> V_150 ) {
if ( ! F_58 ( V_146 -> V_150 ) ) {
if ( ( V_147 = F_55 ( V_146 -> V_11 , V_146 -> V_135 ) ) > 0 ) {
if ( V_147 > ( int ) sizeof ( V_149 ) )
V_147 = sizeof ( V_149 ) ;
if ( ( V_148 = F_59 ( V_146 -> V_150 , V_149 , V_147 ) ) > 0 ) {
for ( V_31 = 0 ; V_31 < V_148 ; ++ V_31 )
F_53 ( V_146 -> V_11 , V_146 -> V_135 , V_149 [ V_31 ] ) ;
}
}
}
}
F_25 ( & V_146 -> V_44 , V_32 ) ;
return 0 ;
}
static int F_60 ( struct V_145 * V_146 )
{
unsigned char V_149 [ 128 ] ;
unsigned long V_32 ;
int V_147 ;
int V_31 ;
F_23 ( & V_146 -> V_44 , V_32 ) ;
if ( ( V_147 = F_54 ( V_146 -> V_11 , V_146 -> V_135 ) ) > 0 ) {
if ( V_146 -> V_151 ) {
if ( V_147 > ( int ) sizeof ( V_149 ) )
V_147 = sizeof ( V_149 ) ;
for ( V_31 = 0 ; V_31 < V_147 ; ++ V_31 )
V_149 [ V_31 ] = F_52 ( V_146 -> V_11 , V_146 -> V_135 ) ;
if ( V_147 )
F_61 ( V_146 -> V_151 , V_149 , V_147 ) ;
} else {
while ( -- V_147 )
F_52 ( V_146 -> V_11 , V_146 -> V_135 ) ;
}
}
V_146 -> V_152 = 0 ;
if ( V_146 -> V_135 )
V_146 -> V_11 -> V_89 |= V_153 ;
else
V_146 -> V_11 -> V_89 |= V_154 ;
F_10 ( V_146 -> V_11 , V_100 , V_146 -> V_11 -> V_89 ) ;
F_25 ( & V_146 -> V_44 , V_32 ) ;
return F_57 ( V_146 ) ;
}
static void F_62 ( struct V_155 * V_156 , int V_157 )
{
struct V_11 * V_11 ;
struct V_145 * V_146 ;
unsigned long V_32 ;
T_4 V_158 ;
V_146 = (struct V_145 * ) V_156 -> V_159 -> V_160 ;
V_11 = V_146 -> V_11 ;
V_158 = V_146 -> V_135 ? V_153 : V_154 ;
F_23 ( & V_11 -> V_44 , V_32 ) ;
if ( V_157 ) {
if ( ! ( V_11 -> V_89 & V_158 ) ) {
F_56 ( V_11 , V_146 -> V_135 ) ;
V_11 -> V_89 |= V_158 ;
}
} else {
V_11 -> V_89 &= ~ V_158 ;
F_63 ( & V_11 -> V_161 ) ;
}
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
F_25 ( & V_11 -> V_44 , V_32 ) ;
}
static void F_64 ( unsigned long V_60 )
{
struct V_145 * V_146 = (struct V_145 * ) V_60 ;
unsigned long V_32 ;
F_57 ( V_146 ) ;
F_23 ( & V_146 -> V_44 , V_32 ) ;
if ( V_146 -> V_162 ) {
V_146 -> V_163 . V_164 = 1 + V_165 ;
F_65 ( & V_146 -> V_163 ) ;
}
F_25 ( & V_146 -> V_44 , V_32 ) ;
}
static void F_66 ( struct V_155 * V_156 , int V_157 )
{
struct V_145 * V_146 ;
unsigned long V_32 ;
V_146 = (struct V_145 * ) V_156 -> V_159 -> V_160 ;
F_23 ( & V_146 -> V_44 , V_32 ) ;
if ( V_157 ) {
if ( ! V_146 -> V_162 ) {
F_67 ( & V_146 -> V_163 ) ;
V_146 -> V_163 . V_166 = F_64 ;
V_146 -> V_163 . V_60 = ( unsigned long ) V_146 ;
V_146 -> V_163 . V_164 = 1 + V_165 ;
F_65 ( & V_146 -> V_163 ) ;
V_146 -> V_162 ++ ;
}
} else {
if ( V_146 -> V_162 && -- V_146 -> V_162 <= 0 )
F_68 ( & V_146 -> V_163 ) ;
}
F_25 ( & V_146 -> V_44 , V_32 ) ;
if ( V_157 )
F_57 ( V_146 ) ;
}
static int F_69 ( struct V_155 * V_156 )
{
struct V_145 * V_146 ;
V_146 = (struct V_145 * ) V_156 -> V_159 -> V_160 ;
F_45 ( & V_146 -> V_44 ) ;
F_56 ( V_146 -> V_11 , V_146 -> V_135 ) ;
V_146 -> V_151 = V_156 ;
F_47 ( & V_146 -> V_44 ) ;
return 0 ;
}
static int F_70 ( struct V_155 * V_156 )
{
struct V_145 * V_146 ;
V_146 = (struct V_145 * ) V_156 -> V_159 -> V_160 ;
F_45 ( & V_146 -> V_44 ) ;
V_146 -> V_150 = V_156 ;
F_47 ( & V_146 -> V_44 ) ;
return 0 ;
}
static int F_71 ( struct V_155 * V_156 )
{
struct V_145 * V_146 ;
F_62 ( V_156 , 0 ) ;
V_146 = (struct V_145 * ) V_156 -> V_159 -> V_160 ;
F_45 ( & V_146 -> V_44 ) ;
V_146 -> V_151 = NULL ;
F_47 ( & V_146 -> V_44 ) ;
return 0 ;
}
static int F_72 ( struct V_155 * V_156 )
{
struct V_145 * V_146 ;
F_66 ( V_156 , 0 ) ;
V_146 = (struct V_145 * ) V_156 -> V_159 -> V_160 ;
F_45 ( & V_146 -> V_44 ) ;
V_146 -> V_150 = NULL ;
F_47 ( & V_146 -> V_44 ) ;
return 0 ;
}
static int F_73 ( struct V_167 * V_168 , struct V_11 * V_11 , int V_135 )
{
char V_149 [ 32 ] ;
V_11 -> V_169 [ V_135 ] . V_135 = V_135 ;
V_11 -> V_169 [ V_135 ] . V_159 = NULL ;
V_11 -> V_169 [ V_135 ] . V_151 = NULL ;
V_11 -> V_169 [ V_135 ] . V_150 = NULL ;
V_11 -> V_169 [ V_135 ] . V_11 = V_11 ;
V_11 -> V_169 [ V_135 ] . V_162 = 0 ;
V_11 -> V_169 [ V_135 ] . V_152 = 0 ;
F_74 ( & V_11 -> V_169 [ V_135 ] . V_44 ) ;
sprintf ( V_149 , L_21 , V_168 -> V_170 , V_135 + 1 ) ;
if ( F_75 ( V_168 , V_149 , V_135 , 1 , 1 , & V_11 -> V_169 [ V_135 ] . V_159 ) < 0 )
return - 1 ;
sprintf ( V_11 -> V_169 [ V_135 ] . V_159 -> V_171 , L_22 , V_135 + 1 ) ;
V_11 -> V_169 [ V_135 ] . V_159 -> V_160 = & V_11 -> V_169 [ V_135 ] ;
F_76 ( V_11 -> V_169 [ V_135 ] . V_159 , V_172 , & V_173 ) ;
F_76 ( V_11 -> V_169 [ V_135 ] . V_159 , V_174 , & V_175 ) ;
V_11 -> V_169 [ V_135 ] . V_159 -> V_176 |= V_177 |
V_178 |
V_179 ;
return 0 ;
}
static T_4 F_77 ( struct V_180 * V_181 )
{
T_4 V_22 = 0 ;
V_22 |= ( V_181 -> V_65 [ 0 ] & V_182 ) ? V_183 : 0 ;
V_22 |= ( V_181 -> V_65 [ 0 ] & V_184 ) ? V_185 : 0 ;
if ( V_22 & V_183 )
V_22 |= ( V_181 -> V_65 [ 0 ] & V_186 ) ? V_187 : 0 ;
else
V_22 |= ( V_181 -> V_65 [ 0 ] & V_188 ) ? V_187 : 0 ;
return V_22 ;
}
static void F_78 ( struct V_180 * V_181 , T_4 V_22 )
{
V_181 -> V_65 [ 0 ] = ( ( V_22 & V_183 ) ? V_182 : 0 ) |
( ( V_22 & V_185 ) ? V_184 : 0 ) ;
if ( V_22 & V_183 )
V_181 -> V_65 [ 0 ] |= ( V_22 & V_187 ) ? V_186 : 0 ;
else
V_181 -> V_65 [ 0 ] |= ( V_22 & V_187 ) ? V_188 : 0 ;
}
static int F_79 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
V_192 -> type = V_193 ;
V_192 -> V_54 = 1 ;
return 0 ;
}
static int F_80 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
F_78 ( & V_195 -> V_196 . V_197 , V_11 -> V_198 ) ;
return 0 ;
}
static int F_82 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
T_4 V_22 ;
V_22 = F_77 ( & V_195 -> V_196 . V_197 ) ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = V_22 != V_11 -> V_198 ;
V_11 -> V_198 = V_22 ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_83 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
V_192 -> type = V_193 ;
V_192 -> V_54 = 1 ;
return 0 ;
}
static int F_84 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
F_78 ( & V_195 -> V_196 . V_197 , V_11 -> V_200 ) ;
return 0 ;
}
static int F_85 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
T_4 V_22 ;
V_22 = F_77 ( & V_195 -> V_196 . V_197 ) ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = V_22 != V_11 -> V_200 ;
V_11 -> V_200 = V_22 ;
V_11 -> V_89 &= ~ ( V_183 | V_185 | V_187 ) ;
F_10 ( V_11 , V_100 , V_11 -> V_89 |= V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_86 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
V_192 -> type = V_193 ;
V_192 -> V_54 = 1 ;
return 0 ;
}
static int F_87 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
V_195 -> V_196 . V_197 . V_65 [ 0 ] = V_190 -> V_201 ;
return 0 ;
}
static unsigned int F_88 ( struct V_11 * V_11 )
{
return F_89 ( V_11 -> V_89 & V_202 ) ;
}
static int F_90 ( struct V_11 * V_11 , int V_12 )
{
V_11 -> V_89 &= ~ V_202 ;
V_11 -> V_89 |= F_91 ( V_12 ) ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_92 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [ 4 ] = { L_23 , L_24 , L_25 , L_26 } ;
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . V_205 . V_206 = ( ( V_11 -> V_14 == V_19 ) ? 4 : 3 ) ;
if ( V_192 -> V_196 . V_205 . V_207 > ( ( V_11 -> V_14 == V_19 ) ? 3 : 2 ) )
V_192 -> V_196 . V_205 . V_207 = ( ( V_11 -> V_14 == V_19 ) ? 3 : 2 ) ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_93 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_88 ( V_11 ) ;
return 0 ;
}
static int F_94 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
unsigned int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . V_205 . V_207 [ 0 ] % ( ( V_11 -> V_14 == V_19 ) ? 4 : 3 ) ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = V_22 != F_88 ( V_11 ) ;
if ( V_199 )
F_90 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_95 ( struct V_11 * V_11 )
{
return ( V_11 -> V_89 & V_208 ) ? 1 : 0 ;
}
static int F_96 ( struct V_11 * V_11 , int V_13 )
{
if ( V_13 )
V_11 -> V_89 |= V_208 ;
else
V_11 -> V_89 &= ~ V_208 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_97 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = F_95 ( V_11 ) ;
return 0 ;
}
static int F_98 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
unsigned int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = ( int ) V_22 != F_95 ( V_11 ) ;
F_96 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_99 ( struct V_11 * V_11 )
{
return ( V_11 -> V_89 & V_183 ) ? 1 : 0 ;
}
static int F_100 ( struct V_11 * V_11 , int V_22 )
{
if ( V_22 )
V_11 -> V_89 |= V_183 ;
else
V_11 -> V_89 &= ~ V_183 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_101 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = F_99 ( V_11 ) ;
return 0 ;
}
static int F_102 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
unsigned int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = ( int ) V_22 != F_99 ( V_11 ) ;
F_100 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_103 ( struct V_11 * V_11 )
{
return ( V_11 -> V_89 & V_187 ) ? 1 : 0 ;
}
static int F_104 ( struct V_11 * V_11 , int V_22 )
{
if ( V_22 )
V_11 -> V_89 |= V_187 ;
else
V_11 -> V_89 &= ~ V_187 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_105 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = F_103 ( V_11 ) ;
return 0 ;
}
static int F_106 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
unsigned int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = ( int ) V_22 != F_103 ( V_11 ) ;
F_104 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_107 ( struct V_11 * V_11 )
{
return ( V_11 -> V_89 & V_185 ) ? 1 : 0 ;
}
static int F_108 ( struct V_11 * V_11 , int V_22 )
{
if ( V_22 )
V_11 -> V_89 |= V_185 ;
else
V_11 -> V_89 &= ~ V_185 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_109 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = F_107 ( V_11 ) ;
return 0 ;
}
static int F_110 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
unsigned int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = ( int ) V_22 != F_107 ( V_11 ) ;
F_108 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_111 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [] = { L_27 , L_28 , L_29 , L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 } ;
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . V_205 . V_206 = ( V_11 -> V_14 == V_19 ) ? 10 : 7 ;
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_112 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
switch ( F_34 ( V_11 ) ) {
case 32000 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 0 ;
break;
case 44100 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 1 ;
break;
case 48000 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 2 ;
break;
case 64000 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 3 ;
break;
case 88200 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 4 ;
break;
case 96000 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 5 ;
break;
case 128000 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 7 ;
break;
case 176400 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 8 ;
break;
case 192000 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 9 ;
break;
default:
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_113 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
V_192 -> type = V_209 ;
V_192 -> V_54 = 1 ;
return 0 ;
}
static int F_114 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = V_11 -> V_115 ;
return 0 ;
}
static int F_115 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
static char * V_203 [] = { L_27 , L_28 , L_29 , L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 } ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . V_205 . V_206 = ( V_11 -> V_14 == V_19 ) ? 10 : 7 ;
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_116 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
switch ( F_35 ( V_11 ) ) {
case 32000 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 0 ;
break;
case 44100 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 1 ;
break;
case 48000 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 2 ;
break;
case 64000 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 3 ;
break;
case 88200 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 4 ;
break;
case 96000 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 5 ;
break;
case 128000 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 7 ;
break;
case 176400 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 8 ;
break;
case 192000 :
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 9 ;
break;
default:
V_195 -> V_196 . V_205 . V_207 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_117 ( struct V_11 * V_11 )
{
if ( V_11 -> V_89 & V_111 )
return 0 ;
else if ( F_35 ( V_11 ) != V_11 -> V_115 )
return 0 ;
return 1 ;
}
static int F_118 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [] = { L_37 , L_38 } ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . V_205 . V_206 = 2 ;
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_119 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_117 ( V_11 ) ;
return 0 ;
}
static int F_120 ( struct V_11 * V_11 )
{
if ( V_11 -> V_89 & V_111 ) {
switch ( V_11 -> V_115 ) {
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
static int F_121 ( struct V_11 * V_11 , int V_210 )
{
int V_106 ;
switch ( V_210 ) {
case V_211 :
if ( F_35 ( V_11 ) != 0 ) {
if ( ! F_51 ( V_11 , F_35 ( V_11 ) , 1 ) ) {
V_11 -> V_89 &= ~ V_111 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
}
return - 1 ;
case V_212 :
V_106 = 32000 ;
break;
case V_213 :
V_106 = 44100 ;
break;
case V_214 :
V_106 = 48000 ;
break;
case V_215 :
V_106 = 64000 ;
break;
case V_216 :
V_106 = 88200 ;
break;
case V_217 :
V_106 = 96000 ;
break;
case V_218 :
V_106 = 128000 ;
break;
case V_219 :
V_106 = 176400 ;
break;
case V_220 :
V_106 = 192000 ;
break;
default:
V_106 = 48000 ;
}
V_11 -> V_89 |= V_111 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
F_51 ( V_11 , V_106 , 1 ) ;
return 0 ;
}
static int F_122 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [] = { L_39 , L_40 , L_41 , L_42 , L_43 , L_44 , L_45 , L_46 , L_47 , L_48 } ;
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
if ( V_11 -> V_14 == V_19 )
V_192 -> V_196 . V_205 . V_206 = 10 ;
else
V_192 -> V_196 . V_205 . V_206 = 7 ;
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_123 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_120 ( V_11 ) ;
return 0 ;
}
static int F_124 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . V_205 . V_207 [ 0 ] ;
if ( V_22 < 0 ) V_22 = 0 ;
if ( V_11 -> V_14 == V_19 ) {
if ( V_22 > 9 )
V_22 = 9 ;
} else {
if ( V_22 > 6 )
V_22 = 6 ;
}
F_45 ( & V_11 -> V_44 ) ;
if ( V_22 != F_120 ( V_11 ) )
V_199 = ( F_121 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_125 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = V_11 -> V_221 ;
return 0 ;
}
static int F_126 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
V_199 = ( int ) V_195 -> V_196 . integer . V_196 [ 0 ] != V_11 -> V_221 ;
if ( V_199 )
V_11 -> V_221 = ! ! V_195 -> V_196 . integer . V_196 [ 0 ] ;
return V_199 ;
}
static int F_127 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_89 & V_222 ) {
case V_223 :
return 0 ;
case V_224 :
return 1 ;
case V_225 :
return 2 ;
default:
return 1 ;
}
}
static int F_128 ( struct V_11 * V_11 , int V_210 )
{
V_11 -> V_89 &= ~ V_222 ;
switch ( V_210 ) {
case 0 :
V_11 -> V_89 |= V_223 ;
break;
case 1 :
V_11 -> V_89 |= V_224 ;
break;
case 2 :
V_11 -> V_89 |= V_225 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_129 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [] = { L_49 , L_50 , L_51 } ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . V_205 . V_206 = 3 ;
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_130 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_127 ( V_11 ) ;
return 0 ;
}
static int F_131 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . V_205 . V_207 [ 0 ] ;
if ( V_22 < 0 ) V_22 = 0 ;
if ( V_22 > 2 ) V_22 = 2 ;
F_45 ( & V_11 -> V_44 ) ;
if ( V_22 != F_127 ( V_11 ) )
V_199 = ( F_128 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_132 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_89 & V_226 ) {
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
static int F_133 ( struct V_11 * V_11 , int V_210 )
{
V_11 -> V_89 &= ~ V_226 ;
switch ( V_210 ) {
case 0 :
V_11 -> V_89 |= V_227 ;
break;
case 1 :
V_11 -> V_89 |= V_228 ;
break;
case 2 :
V_11 -> V_89 |= V_229 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_134 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [] = { L_52 , L_50 , L_53 } ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . V_205 . V_206 = 3 ;
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_135 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_132 ( V_11 ) ;
return 0 ;
}
static int F_136 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . V_205 . V_207 [ 0 ] ;
if ( V_22 < 0 ) V_22 = 0 ;
if ( V_22 > 2 ) V_22 = 2 ;
F_45 ( & V_11 -> V_44 ) ;
if ( V_22 != F_132 ( V_11 ) )
V_199 = ( F_133 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_137 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_89 & V_230 ) {
case V_231 :
return 0 ;
case V_232 :
return 1 ;
case V_233 :
return 2 ;
default:
return 0 ;
}
}
static int F_138 ( struct V_11 * V_11 , int V_210 )
{
V_11 -> V_89 &= ~ V_230 ;
switch ( V_210 ) {
case 0 :
V_11 -> V_89 |= V_231 ;
break;
case 1 :
V_11 -> V_89 |= V_232 ;
break;
case 2 :
V_11 -> V_89 |= V_233 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_139 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [] = { L_54 , L_55 , L_56 } ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . V_205 . V_206 = 3 ;
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_140 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_137 ( V_11 ) ;
return 0 ;
}
static int F_141 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . V_205 . V_207 [ 0 ] ;
if ( V_22 < 0 ) V_22 = 0 ;
if ( V_22 > 2 ) V_22 = 2 ;
F_45 ( & V_11 -> V_44 ) ;
if ( V_22 != F_137 ( V_11 ) )
V_199 = ( F_138 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_142 ( struct V_11 * V_11 )
{
if ( V_11 -> V_89 & V_234 )
return 1 ;
return 0 ;
}
static int F_143 ( struct V_11 * V_11 , int V_210 )
{
if ( V_210 )
V_11 -> V_89 |= V_234 ;
else
V_11 -> V_89 &= ~ V_234 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_144 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_142 ( V_11 ) ;
return 0 ;
}
static int F_145 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = ( int ) V_22 != F_142 ( V_11 ) ;
F_143 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_146 ( struct V_11 * V_11 )
{
if ( V_11 -> V_89 & V_235 )
return 1 ;
return 0 ;
}
static int F_147 ( struct V_11 * V_11 , int V_210 )
{
if ( V_210 )
V_11 -> V_89 |= V_235 ;
else
V_11 -> V_89 &= ~ V_235 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_148 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_146 ( V_11 ) ;
return 0 ;
}
static int F_149 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = ( int ) V_22 != F_146 ( V_11 ) ;
F_147 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_150 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_89 & V_236 ) {
case V_237 :
return V_238 ;
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
default:
return V_246 ;
}
return 0 ;
}
static int F_151 ( struct V_11 * V_11 , int V_249 )
{
V_11 -> V_89 &= ~ V_236 ;
switch ( V_249 ) {
case V_238 :
V_11 -> V_89 &= ~ V_236 ;
break;
case V_240 :
V_11 -> V_89 |= V_239 ;
break;
case V_242 :
V_11 -> V_89 |= V_241 ;
break;
case V_244 :
V_11 -> V_89 |= V_243 ;
break;
case V_246 :
V_11 -> V_89 |= V_245 ;
break;
case V_248 :
V_11 -> V_89 |= V_247 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_152 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [] = { L_57 , L_58 , L_59 , L_60 , L_61 , L_62 } ;
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_20 :
V_192 -> V_196 . V_205 . V_206 = 6 ;
break;
case V_15 :
V_192 -> V_196 . V_205 . V_206 = 4 ;
break;
case V_19 :
V_192 -> V_196 . V_205 . V_206 = 3 ;
break;
default:
return - V_116 ;
}
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_153 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_150 ( V_11 ) ;
return 0 ;
}
static int F_154 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 , V_250 ;
unsigned int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_20 :
V_250 = 6 ;
break;
case V_15 :
V_250 = 4 ;
break;
case V_19 :
V_250 = 3 ;
break;
default:
return - V_28 ;
}
V_22 = V_195 -> V_196 . V_205 . V_207 [ 0 ] % V_250 ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = ( int ) V_22 != F_150 ( V_11 ) ;
F_151 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_36 ( struct V_11 * V_11 )
{
unsigned int V_79 = F_12 ( V_11 , V_48 ) ;
switch ( V_79 & V_251 ) {
case V_252 :
return V_253 ;
case V_254 :
return V_255 ;
case V_256 :
return V_81 ;
case V_251 :
return V_257 ;
case V_258 :
return V_114 ;
case V_259 :
return V_260 ;
case V_261 :
return V_262 ;
default:
return V_253 ;
}
return 0 ;
}
static int F_155 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [] = { L_57 , L_60 , L_58 , L_33 , L_59 , L_61 , L_62 } ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . V_205 . V_206 = 7 ;
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_156 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_36 ( V_11 ) ;
return 0 ;
}
static int F_157 ( struct V_11 * V_11 )
{
return ( V_11 -> V_89 & V_263 ) ? 1 : 0 ;
}
static int F_158 ( struct V_11 * V_11 , int V_13 )
{
if ( V_13 )
V_11 -> V_89 |= V_263 ;
else
V_11 -> V_89 &= ~ V_263 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_159 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
F_45 ( & V_11 -> V_44 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = F_157 ( V_11 ) ;
F_47 ( & V_11 -> V_44 ) ;
return 0 ;
}
static int F_160 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
unsigned int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = ( int ) V_22 != F_157 ( V_11 ) ;
F_158 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_161 ( struct V_11 * V_11 , int V_264 )
{
if ( V_264 )
V_11 -> V_91 = 1 ;
else
V_11 -> V_91 = 0 ;
return 0 ;
}
static int F_162 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
F_45 ( & V_11 -> V_44 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = V_11 -> V_91 ;
F_47 ( & V_11 -> V_44 ) ;
return 0 ;
}
static int F_163 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
unsigned int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = ( int ) V_22 != V_11 -> V_91 ;
F_161 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_164 ( struct V_11 * V_11 , int V_265 )
{
if ( V_265 )
V_11 -> V_266 = 1 ;
else
V_11 -> V_266 = 0 ;
return 0 ;
}
static int F_165 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
F_45 ( & V_11 -> V_44 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = V_11 -> V_266 ;
F_47 ( & V_11 -> V_44 ) ;
return 0 ;
}
static int F_166 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
unsigned int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = ( int ) V_22 != V_11 -> V_266 ;
F_164 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_167 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
V_192 -> type = V_209 ;
V_192 -> V_54 = 3 ;
V_192 -> V_196 . integer . V_267 = 0 ;
V_192 -> V_196 . integer . V_250 = 65536 ;
V_192 -> V_196 . integer . V_268 = 1 ;
return 0 ;
}
static int F_168 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_269 ;
int V_270 ;
int V_57 ;
V_269 = V_195 -> V_196 . integer . V_196 [ 0 ] ;
V_270 = V_195 -> V_196 . integer . V_196 [ 1 ] ;
if ( V_269 >= V_11 -> V_271 )
V_57 = F_8 ( V_11 , V_269 - V_11 -> V_271 , V_270 ) ;
else
V_57 = F_9 ( V_11 , V_269 , V_270 ) ;
F_45 ( & V_11 -> V_44 ) ;
V_195 -> V_196 . integer . V_196 [ 2 ] = F_31 ( V_11 , V_57 ) ;
F_47 ( & V_11 -> V_44 ) ;
return 0 ;
}
static int F_169 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
int V_269 ;
int V_270 ;
int V_272 ;
int V_57 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_269 = V_195 -> V_196 . integer . V_196 [ 0 ] ;
V_270 = V_195 -> V_196 . integer . V_196 [ 1 ] ;
if ( V_269 >= V_11 -> V_271 )
V_57 = F_8 ( V_11 , V_269 - V_11 -> V_271 , V_270 ) ;
else
V_57 = F_9 ( V_11 , V_269 , V_270 ) ;
V_272 = V_195 -> V_196 . integer . V_196 [ 2 ] ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = V_272 != F_31 ( V_11 , V_57 ) ;
if ( V_199 )
F_32 ( V_11 , V_57 , V_272 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_170 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [] = { L_63 , L_64 , L_65 } ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . V_205 . V_206 = 3 ;
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_171 ( struct V_11 * V_11 )
{
int V_79 = F_12 ( V_11 , V_48 ) ;
if ( V_79 & V_273 ) {
if ( V_79 & V_274 )
return 2 ;
else
return 1 ;
} else
return 0 ;
return 0 ;
}
static int F_172 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_171 ( V_11 ) ;
return 0 ;
}
static int F_173 ( struct V_11 * V_11 )
{
int V_65 = F_12 ( V_11 , V_24 ) ;
if ( V_65 & V_69 )
return 0 ;
else {
if ( V_65 & V_275 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_174 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_173 ( V_11 ) ;
return 0 ;
}
static int F_175 ( struct V_11 * V_11 )
{
int V_65 = F_12 ( V_11 , V_24 ) ;
if ( V_65 & V_276 ) {
if ( V_65 & V_277 )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_176 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_175 ( V_11 ) ;
return 0 ;
}
static int F_177 ( struct V_11 * V_11 , int V_278 )
{
int V_65 = F_12 ( V_11 , V_24 ) ;
if ( V_65 & ( V_279 >> V_278 ) ) {
if ( V_65 & ( V_280 >> V_278 ) )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_178 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
int V_281 ;
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_281 = V_195 -> V_135 . V_282 - 1 ;
F_50 ( V_281 < 0 ) ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_20 :
if ( V_281 >= 3 )
return - V_116 ;
break;
case V_15 :
case V_19 :
if ( V_281 >= 1 )
return - V_116 ;
break;
default:
return - V_28 ;
}
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_177 ( V_11 , V_281 ) ;
return 0 ;
}
static int F_179 ( struct V_11 * V_11 )
{
T_3 V_104 ;
unsigned int V_96 = V_11 -> V_96 ;
int V_115 = V_11 -> V_115 ;
if ( ! V_96 )
return 0 ;
V_104 = V_107 ;
V_104 = F_49 ( V_104 , V_96 ) ;
if ( V_115 >= 112000 )
V_104 *= 4 ;
else if ( V_115 >= 56000 )
V_104 *= 2 ;
return ( ( int ) V_104 ) - V_115 ;
}
static int F_180 ( struct V_11 * V_11 , int V_283 )
{
int V_106 = V_11 -> V_115 + V_283 ;
F_48 ( V_11 , V_106 ) ;
return 0 ;
}
static int F_181 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
V_192 -> type = V_209 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . integer . V_267 = - 5000 ;
V_192 -> V_196 . integer . V_250 = 5000 ;
return 0 ;
}
static int F_182 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_179 ( V_11 ) ;
return 0 ;
}
static int F_183 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . V_205 . V_207 [ 0 ] ;
F_45 ( & V_11 -> V_44 ) ;
if ( V_22 != F_179 ( V_11 ) )
V_199 = ( F_180 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_184 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_89 & V_284 ) {
case V_285 :
return 0 ;
case V_286 :
return 2 ;
case V_287 :
return 3 ;
case V_288 :
return 4 ;
}
return 1 ;
}
static int F_185 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_184 ( V_11 ) ;
return 0 ;
}
static int F_186 ( struct V_11 * V_11 , int V_210 )
{
V_11 -> V_89 &= ~ V_284 ;
switch ( V_210 ) {
case 0 :
V_11 -> V_89 |= V_285 ;
break;
case 1 :
break;
case 2 :
V_11 -> V_89 |= V_286 ;
break;
case 3 :
V_11 -> V_89 |= V_287 ;
break;
case 4 :
V_11 -> V_89 |= V_288 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_187 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . V_205 . V_207 [ 0 ] ;
if ( V_22 < 0 )
V_22 = 0 ;
if ( V_22 > 4 )
V_22 = 4 ;
F_45 ( & V_11 -> V_44 ) ;
if ( V_22 != F_184 ( V_11 ) )
V_199 = ( F_186 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_188 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [] = { L_66 , L_67 , L_68 , L_69 , L_70 } ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . V_205 . V_206 = 5 ;
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_189 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_89 & V_289 ) {
case V_290 :
return 0 ;
case V_291 :
return 2 ;
case V_292 :
return 3 ;
case V_293 :
return 4 ;
}
return 1 ;
}
static int F_190 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . V_205 . V_207 [ 0 ] = F_189 ( V_11 ) ;
return 0 ;
}
static int F_191 ( struct V_11 * V_11 , int V_210 )
{
V_11 -> V_89 &= ~ V_289 ;
switch ( V_210 ) {
case 0 :
V_11 -> V_89 |= V_290 ;
break;
case 1 :
break;
case 2 :
V_11 -> V_89 |= V_291 ;
break;
case 3 :
V_11 -> V_89 |= V_292 ;
break;
case 4 :
V_11 -> V_89 |= V_293 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_192 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . V_205 . V_207 [ 0 ] ;
if ( V_22 < 0 )
V_22 = 0 ;
if ( V_22 > 4 )
V_22 = 4 ;
F_45 ( & V_11 -> V_44 ) ;
if ( V_22 != F_189 ( V_11 ) )
V_199 = ( F_191 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_193 ( struct V_11 * V_11 )
{
return ( V_11 -> V_89 & V_294 ) ? 1 : 0 ;
}
static int F_194 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = F_193 ( V_11 ) ;
return 0 ;
}
static int F_195 ( struct V_11 * V_11 , int V_295 )
{
if ( V_295 )
V_11 -> V_89 |= V_294 ;
else
V_11 -> V_89 &= ~ V_294 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_196 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
unsigned int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = ( int ) V_22 != F_193 ( V_11 ) ;
F_195 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_197 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [] = { L_71 , L_72 } ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . V_205 . V_206 = 2 ;
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_198 ( struct V_11 * V_11 )
{
return ( V_11 -> V_89 & V_296 ) ? 1 : 0 ;
}
static int F_199 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = F_198 ( V_11 ) ;
return 0 ;
}
static int F_200 ( struct V_11 * V_11 , int V_295 )
{
if ( V_295 )
V_11 -> V_89 |= V_296 ;
else
V_11 -> V_89 &= ~ V_296 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_201 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_11 * V_11 = F_81 ( V_190 ) ;
int V_199 ;
unsigned int V_22 ;
if ( ! F_33 ( V_11 ) )
return - V_126 ;
V_22 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_45 ( & V_11 -> V_44 ) ;
V_199 = ( int ) V_22 != F_198 ( V_11 ) ;
F_200 ( V_11 , V_22 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_199 ;
}
static int F_202 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static char * V_203 [] = { L_71 , L_72 } ;
V_192 -> type = V_204 ;
V_192 -> V_54 = 1 ;
V_192 -> V_196 . V_205 . V_206 = 2 ;
if ( V_192 -> V_196 . V_205 . V_207 >= V_192 -> V_196 . V_205 . V_206 )
V_192 -> V_196 . V_205 . V_207 = V_192 -> V_196 . V_205 . V_206 - 1 ;
strcpy ( V_192 -> V_196 . V_205 . V_171 , V_203 [ V_192 -> V_196 . V_205 . V_207 ] ) ;
return 0 ;
}
static int F_203 ( struct V_167 * V_168 , struct V_11 * V_11 )
{
unsigned int V_278 ;
int V_297 ;
struct V_189 * V_298 ;
if ( V_11 -> V_14 == V_17 ) {
for ( V_278 = 0 ; V_278 < F_204 ( V_299 ) ; V_278 ++ ) {
V_297 = F_205 ( V_168 , V_298 = F_206 ( & V_299 [ V_278 ] , V_11 ) ) ;
if ( V_297 < 0 )
return V_297 ;
}
return 0 ;
}
for ( V_278 = 0 ; V_278 < F_204 ( V_300 ) ; V_278 ++ ) {
if ( ( V_297 = F_205 ( V_168 , V_298 = F_206 ( & V_300 [ V_278 ] , V_11 ) ) ) < 0 )
return V_297 ;
if ( V_278 == 1 )
V_11 -> V_301 = V_298 ;
}
V_302 . V_171 = L_73 ;
V_302 . V_282 = 1 ;
if ( ( V_297 = F_205 ( V_168 , V_298 = F_206 ( & V_302 , V_11 ) ) ) )
return V_297 ;
if ( V_11 -> V_14 == V_16 || V_11 -> V_14 == V_20 ) {
for ( V_278 = 1 ; V_278 < 3 ; ++ V_278 ) {
V_302 . V_282 = V_278 + 1 ;
if ( ( V_297 = F_205 ( V_168 , V_298 = F_206 ( & V_302 , V_11 ) ) ) )
return V_297 ;
}
}
if ( V_11 -> V_14 == V_19 ) {
for ( V_278 = 0 ; V_278 < F_204 ( V_303 ) ; V_278 ++ ) {
if ( ( V_297 = F_205 ( V_168 , V_298 = F_206 ( & V_303 [ V_278 ] , V_11 ) ) ) < 0 )
return V_297 ;
}
}
if ( V_11 -> V_14 == V_19 || V_11 -> V_14 == V_20 ) {
if ( ( V_297 = F_205 ( V_168 , V_298 = F_206 ( & V_304 , V_11 ) ) ) < 0 )
return V_297 ;
}
return 0 ;
}
static void
F_207 ( struct V_305 * V_306 , struct V_307 * V_308 )
{
struct V_11 * V_11 = V_306 -> V_160 ;
unsigned int V_65 ;
unsigned int V_79 ;
char * V_309 ;
char * V_310 ;
char * V_311 ;
char * V_312 ;
int V_313 ;
V_65 = F_12 ( V_11 , V_24 ) ;
V_79 = F_12 ( V_11 , V_48 ) ;
F_208 ( V_308 , L_74 , V_11 -> V_314 ,
V_11 -> V_168 -> V_315 + 1 ) ;
F_208 ( V_308 , L_75 ,
V_11 -> V_316 , V_11 -> V_101 ) ;
F_208 ( V_308 , L_76 ,
V_11 -> V_317 , V_11 -> V_318 , ( unsigned long ) V_11 -> V_23 ) ;
F_208 ( V_308 , L_77 , V_11 -> V_89 ) ;
F_208 ( V_308 , L_78 ,
V_11 -> V_40 ) ;
F_208 ( V_308 , L_79 , V_65 ) ;
F_208 ( V_308 , L_80 , V_79 ) ;
if ( F_14 ( V_11 ) ) {
F_208 ( V_308 , L_81
L_82 ) ;
return;
}
if ( F_27 ( V_11 , 0 ) ) {
if ( V_11 -> V_26 & V_53 ) {
if ( F_19 ( V_11 ) != 0 ) {
F_208 ( V_308 , L_83
L_84
L_85 ) ;
return;
}
} else {
int V_297 = - V_116 ;
#ifdef F_28
V_297 = F_29 ( V_11 ) ;
#endif
if ( V_297 < 0 ) {
F_208 ( V_308 ,
L_86
L_87 ) ;
return;
}
}
}
F_208 ( V_308 , L_88 , F_12 ( V_11 , V_56 ) & 0xff ) ;
F_208 ( V_308 , L_89 , F_12 ( V_11 , V_144 ) ) ;
F_208 ( V_308 , L_90 , F_12 ( V_11 , V_141 ) ) ;
F_208 ( V_308 , L_91 , F_12 ( V_11 , V_143 ) ) ;
F_208 ( V_308 , L_92 , F_12 ( V_11 , V_140 ) ) ;
F_208 ( V_308 , L_93 , V_11 -> V_266 ? L_94 : L_95 ) ;
F_208 ( V_308 , L_96 ) ;
V_313 = 1 << ( 6 + F_38 ( V_11 -> V_89 & V_105 ) ) ;
F_208 ( V_308 , L_97 , V_313 , ( unsigned long ) V_11 -> V_88 ) ;
F_208 ( V_308 , L_98 , F_39 ( V_11 ) ) ;
F_208 ( V_308 , L_99 , V_11 -> V_91 ? L_94 : L_95 ) ;
F_208 ( V_308 , L_100 , ( V_11 -> V_89 & V_263 ) ? L_94 : L_95 ) ;
F_208 ( V_308 , L_101 , ( V_79 & V_319 ) | ( V_79 & V_50 ) << 1 | ( V_79 & V_49 ) << 2 ) ;
F_208 ( V_308 , L_96 ) ;
switch ( F_120 ( V_11 ) ) {
case V_211 :
V_312 = L_39 ;
break;
case V_212 :
V_312 = L_102 ;
break;
case V_213 :
V_312 = L_41 ;
break;
case V_214 :
V_312 = L_103 ;
break;
case V_215 :
V_312 = L_104 ;
break;
case V_216 :
V_312 = L_44 ;
break;
case V_217 :
V_312 = L_105 ;
break;
case V_218 :
V_312 = L_46 ;
break;
case V_219 :
V_312 = L_47 ;
break;
case V_220 :
V_312 = L_106 ;
break;
default:
V_312 = L_107 ;
}
F_208 ( V_308 , L_108 , V_312 ) ;
if ( F_117 ( V_11 ) )
V_311 = L_38 ;
else
V_311 = L_37 ;
switch ( F_150 ( V_11 ) ) {
case V_246 :
V_309 = L_109 ;
break;
case V_248 :
V_309 = L_60 ;
break;
case V_244 :
V_309 = L_110 ;
break;
case V_238 :
V_309 = L_59 ;
break;
case V_240 :
V_309 = L_61 ;
break;
case V_242 :
V_309 = L_62 ;
break;
default:
V_309 = L_109 ;
break;
}
F_208 ( V_308 , L_111 , V_309 ) ;
switch ( F_36 ( V_11 ) ) {
case V_253 :
V_310 = L_109 ;
break;
case V_255 :
V_310 = L_60 ;
break;
case V_81 :
V_310 = L_110 ;
break;
case V_257 :
V_310 = L_33 ;
break;
case V_114 :
V_310 = L_59 ;
break;
case V_260 :
V_310 = L_61 ;
break;
case V_262 :
V_310 = L_62 ;
break;
default:
V_310 = L_112 ;
break;
}
F_208 ( V_308 , L_113 , V_310 ) ;
F_208 ( V_308 , L_114 , F_35 ( V_11 ) ) ;
F_208 ( V_308 , L_115 , V_311 ) ;
F_208 ( V_308 , L_116 , V_11 -> V_115 ) ;
F_208 ( V_308 , L_117 , V_11 -> V_221 ? L_118 : L_119 ) ;
F_208 ( V_308 , L_96 ) ;
if ( V_11 -> V_14 != V_17 ) {
switch ( F_88 ( V_11 ) ) {
case V_320 :
F_208 ( V_308 , L_120 ) ;
break;
case V_321 :
F_208 ( V_308 , L_121 ) ;
break;
case V_322 :
F_208 ( V_308 , L_122 ) ;
break;
case V_323 :
F_208 ( V_308 , L_123 ) ;
break;
default:
F_208 ( V_308 , L_124 ) ;
break;
}
}
if ( V_17 == V_11 -> V_14 ) {
if ( V_11 -> V_89 & V_294 )
F_208 ( V_308 , L_125 ) ;
else
F_208 ( V_308 , L_126 ) ;
if ( V_11 -> V_89 & V_296 )
F_208 ( V_308 , L_127 ) ;
else
F_208 ( V_308 , L_128 ) ;
switch ( V_11 -> V_89 & V_284 ) {
case V_285 :
F_208 ( V_308 , L_129 ) ;
break;
case V_324 :
F_208 ( V_308 , L_130 ) ;
break;
case V_286 :
F_208 ( V_308 , L_131 ) ;
break;
case V_287 :
F_208 ( V_308 , L_132 ) ;
break;
case V_288 :
F_208 ( V_308 , L_133 ) ;
break;
default:
F_208 ( V_308 , L_134 ) ;
}
switch ( V_11 -> V_89 & V_289 ) {
case V_290 :
F_208 ( V_308 , L_135 ) ;
break;
case V_325 :
F_208 ( V_308 , L_136 ) ;
break;
case V_291 :
F_208 ( V_308 , L_137 ) ;
break;
case V_292 :
F_208 ( V_308 , L_138 ) ;
break;
case V_293 :
F_208 ( V_308 , L_139 ) ;
break;
default:
F_208 ( V_308 , L_140 ) ;
}
} else {
if ( V_11 -> V_89 & V_208 )
F_208 ( V_308 , L_141 ) ;
else
F_208 ( V_308 , L_142 ) ;
if ( V_11 -> V_89 & V_183 )
F_208 ( V_308 , L_143 ) ;
else
F_208 ( V_308 , L_144 ) ;
if ( V_11 -> V_89 & V_187 )
F_208 ( V_308 , L_145 ) ;
else
F_208 ( V_308 , L_146 ) ;
if ( V_11 -> V_89 & V_185 )
F_208 ( V_308 , L_147 ) ;
else
F_208 ( V_308 , L_148 ) ;
V_313 = F_34 ( V_11 ) ;
if ( V_313 != 0 )
F_208 ( V_308 , L_149 , V_313 ) ;
else
F_208 ( V_308 , L_150 ) ;
}
F_208 ( V_308 , L_96 ) ;
V_313 = V_65 & V_280 ;
if ( V_65 & V_279 )
F_208 ( V_308 , L_151 , V_313 ? L_65 : L_64 ) ;
else
F_208 ( V_308 , L_152 ) ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_20 :
V_313 = V_65 & V_326 ;
if ( V_65 & V_327 )
F_208 ( V_308 , L_153 , V_313 ? L_65 : L_64 ) ;
else
F_208 ( V_308 , L_154 ) ;
V_313 = V_65 & V_328 ;
if ( V_65 & V_329 )
F_208 ( V_308 , L_155 , V_313 ? L_65 : L_64 ) ;
else
F_208 ( V_308 , L_156 ) ;
break;
default:
break;
}
V_313 = V_65 & V_275 ;
if ( V_65 & V_69 )
F_208 ( V_308 , L_157 ) ;
else
F_208 ( V_308 , L_158 , V_313 ? L_65 : L_64 ) ;
V_313 = V_79 & V_274 ;
if ( V_79 & V_273 )
F_208 ( V_308 , L_159 , V_313 ? L_65 : L_64 ) ;
else
F_208 ( V_308 , L_160 ) ;
V_313 = V_65 & V_277 ;
if ( V_65 & V_276 )
F_208 ( V_308 , L_161 , V_313 ? L_65 : L_64 ) ;
else
F_208 ( V_308 , L_162 ) ;
F_208 ( V_308 , L_96 ) ;
if ( V_11 -> V_14 == V_19 ) {
char * V_330 ;
switch ( F_132 ( V_11 ) ) {
case 0 :
V_330 = L_52 ;
break;
case 1 :
V_330 = L_50 ;
break;
default:
V_330 = L_53 ;
break;
}
F_208 ( V_308 , L_163 , V_330 ) ;
switch ( F_127 ( V_11 ) ) {
case 0 :
V_330 = L_49 ;
break;
case 1 :
V_330 = L_50 ;
break;
default:
V_330 = L_52 ;
break;
}
F_208 ( V_308 , L_164 , V_330 ) ;
switch ( F_137 ( V_11 ) ) {
case 0 :
V_330 = L_54 ;
break;
case 1 :
V_330 = L_55 ;
break;
default:
V_330 = L_56 ;
break;
}
F_208 ( V_308 , L_165 , V_330 ) ;
F_208 ( V_308 , L_166 , F_142 ( V_11 ) ? L_167 : L_168 ) ;
if ( V_11 -> V_89 & V_235 )
F_208 ( V_308 , L_169 ) ;
else
F_208 ( V_308 , L_170 ) ;
F_208 ( V_308 , L_96 ) ;
}
}
static void F_209 ( struct V_11 * V_11 )
{
struct V_305 * V_306 ;
if ( ! F_210 ( V_11 -> V_168 , L_171 , & V_306 ) )
F_211 ( V_306 , V_11 , F_207 ) ;
}
static void F_212 ( struct V_11 * V_11 )
{
F_6 ( & V_11 -> V_331 , V_11 -> V_2 ) ;
F_6 ( & V_11 -> V_332 , V_11 -> V_2 ) ;
}
static int T_5 F_213 ( struct V_11 * V_11 )
{
unsigned long V_333 , V_334 ;
if ( F_1 ( V_11 -> V_2 , & V_11 -> V_331 , V_102 ) < 0 ||
F_1 ( V_11 -> V_2 , & V_11 -> V_332 , V_102 ) < 0 ) {
if ( V_11 -> V_331 . V_10 )
F_214 ( & V_11 -> V_331 ) ;
F_215 ( V_52 L_172 , V_11 -> V_314 ) ;
return - V_9 ;
}
V_334 = F_216 ( V_11 -> V_331 . V_57 , 0x10000ul ) ;
V_333 = F_216 ( V_11 -> V_332 . V_57 , 0x10000ul ) ;
F_10 ( V_11 , V_335 , V_334 ) ;
F_10 ( V_11 , V_336 , V_333 ) ;
V_11 -> V_316 = V_11 -> V_331 . V_10 + ( V_334 - V_11 -> V_331 . V_57 ) ;
V_11 -> V_101 = V_11 -> V_332 . V_10 + ( V_333 - V_11 -> V_332 . V_57 ) ;
return 0 ;
}
static int F_24 ( struct V_11 * V_11 )
{
unsigned int V_31 ;
V_11 -> V_89 = V_111 |
V_337 |
F_46 ( 7 ) |
V_263 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
#ifdef F_22
V_11 -> V_40 = V_41 ;
#else
V_11 -> V_40 = 0 ;
#endif
if ( V_11 -> V_14 == V_20 )
F_217 ( V_11 ) ;
else
F_10 ( V_11 , V_34 , V_11 -> V_40 ) ;
F_40 ( V_11 ) ;
F_37 ( V_11 ) ;
for ( V_31 = 0 ; V_31 < V_58 ; ++ V_31 )
V_11 -> V_59 [ V_31 ] = V_338 ;
for ( V_31 = 0 ; V_31 < ( ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) ? 1352 : V_58 ) ; ++ V_31 ) {
if ( F_32 ( V_11 , V_31 , V_338 ) )
return - V_28 ;
}
if ( V_11 -> V_14 == V_19 ) {
V_11 -> V_89 |= ( V_224 | V_228 | V_231 ) ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
}
F_51 ( V_11 , 48000 , 1 ) ;
return 0 ;
}
static void F_218 ( unsigned long V_339 )
{
struct V_11 * V_11 = (struct V_11 * ) V_339 ;
if ( V_11 -> V_169 [ 0 ] . V_152 )
F_60 ( & V_11 -> V_169 [ 0 ] ) ;
if ( V_11 -> V_169 [ 1 ] . V_152 )
F_60 ( & V_11 -> V_169 [ 1 ] ) ;
}
static T_6 F_219 ( int V_317 , void * V_340 )
{
struct V_11 * V_11 = (struct V_11 * ) V_340 ;
unsigned int V_65 ;
int V_341 ;
int V_342 ;
int V_343 ;
unsigned int V_344 ;
unsigned int V_345 ;
int V_346 = 0 ;
V_65 = F_12 ( V_11 , V_24 ) ;
V_341 = V_65 & V_347 ;
V_342 = V_65 & V_348 ;
V_343 = V_65 & V_349 ;
if ( ! V_341 && ! V_342 && ! V_343 )
return V_350 ;
F_10 ( V_11 , V_351 , 0 ) ;
V_344 = F_12 ( V_11 , V_141 ) & 0xff ;
V_345 = F_12 ( V_11 , V_140 ) & 0xff ;
if ( ! ( V_11 -> V_26 & V_42 ) )
return V_352 ;
if ( V_341 ) {
if ( V_11 -> V_353 )
F_220 ( V_11 -> V_354 -> V_355 [ V_356 ] . V_156 ) ;
if ( V_11 -> V_357 )
F_220 ( V_11 -> V_354 -> V_355 [ V_358 ] . V_156 ) ;
}
if ( V_342 && V_344 ) {
if ( V_11 -> V_266 ) {
V_11 -> V_89 &= ~ V_154 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
V_11 -> V_169 [ 0 ] . V_152 = 1 ;
V_346 = 1 ;
} else {
F_60 ( & V_11 -> V_169 [ 0 ] ) ;
}
}
if ( V_11 -> V_14 != V_15 && V_11 -> V_14 != V_17 && V_11 -> V_14 != V_19 && V_343 && V_345 ) {
if ( V_11 -> V_266 ) {
V_11 -> V_89 &= ~ V_153 ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
V_11 -> V_169 [ 1 ] . V_152 = 1 ;
V_346 = 1 ;
} else {
F_60 ( & V_11 -> V_169 [ 1 ] ) ;
}
}
if ( V_11 -> V_266 && V_346 )
F_221 ( & V_11 -> V_161 ) ;
return V_352 ;
}
static T_2 F_222 ( struct V_359 * V_156 )
{
struct V_11 * V_11 = F_223 ( V_156 ) ;
return F_39 ( V_11 ) ;
}
static char * F_224 ( struct V_11 * V_11 ,
int V_360 ,
int V_361 )
{
int V_362 ;
if ( F_50 ( V_361 < 0 || V_361 >= V_11 -> V_271 ) )
return NULL ;
if ( ( V_362 = V_11 -> V_128 [ V_361 ] ) < 0 )
return NULL ;
if ( V_360 == V_356 )
return V_11 -> V_316 + ( V_362 * V_363 ) ;
else
return V_11 -> V_101 + ( V_362 * V_363 ) ;
}
static int F_225 ( struct V_359 * V_156 , int V_361 ,
T_2 V_364 , void T_7 * V_365 , T_2 V_54 )
{
struct V_11 * V_11 = F_223 ( V_156 ) ;
char * V_366 ;
if ( F_50 ( V_364 + V_54 > V_363 / 4 ) )
return - V_116 ;
V_366 = F_224 ( V_11 , V_156 -> V_367 -> V_360 , V_361 ) ;
if ( F_50 ( ! V_366 ) )
return - V_28 ;
if ( F_226 ( V_366 + V_364 * 4 , V_365 , V_54 * 4 ) )
return - V_368 ;
return V_54 ;
}
static int F_227 ( struct V_359 * V_156 , int V_361 ,
T_2 V_364 , void T_7 * V_369 , T_2 V_54 )
{
struct V_11 * V_11 = F_223 ( V_156 ) ;
char * V_366 ;
if ( F_50 ( V_364 + V_54 > V_363 / 4 ) )
return - V_116 ;
V_366 = F_224 ( V_11 , V_156 -> V_367 -> V_360 , V_361 ) ;
if ( F_50 ( ! V_366 ) )
return - V_28 ;
if ( F_228 ( V_369 , V_366 + V_364 * 4 , V_54 * 4 ) )
return - V_368 ;
return V_54 ;
}
static int F_229 ( struct V_359 * V_156 , int V_361 ,
T_2 V_364 , T_2 V_54 )
{
struct V_11 * V_11 = F_223 ( V_156 ) ;
char * V_366 ;
V_366 = F_224 ( V_11 , V_156 -> V_367 -> V_360 , V_361 ) ;
if ( F_50 ( ! V_366 ) )
return - V_28 ;
memset ( V_366 + V_364 * 4 , 0 , V_54 * 4 ) ;
return V_54 ;
}
static int F_230 ( struct V_359 * V_156 )
{
struct V_370 * V_371 = V_156 -> V_371 ;
struct V_11 * V_11 = F_223 ( V_156 ) ;
struct V_359 * V_372 ;
if ( V_156 -> V_360 == V_358 )
V_372 = V_11 -> V_353 ;
else
V_372 = V_11 -> V_357 ;
if ( V_11 -> V_373 )
V_371 -> V_65 -> V_374 = F_39 ( V_11 ) ;
else
V_371 -> V_65 -> V_374 = 0 ;
if ( V_372 ) {
struct V_359 * V_97 ;
struct V_370 * V_375 = V_372 -> V_371 ;
F_231 (s, substream) {
if ( V_97 == V_372 ) {
V_375 -> V_65 -> V_374 = V_371 -> V_65 -> V_374 ;
break;
}
}
}
return 0 ;
}
static int F_232 ( struct V_359 * V_156 ,
struct V_376 * V_377 )
{
struct V_11 * V_11 = F_223 ( V_156 ) ;
int V_297 ;
T_8 V_378 ;
T_8 V_379 ;
if ( F_14 ( V_11 ) )
return - V_28 ;
if ( F_27 ( V_11 , 1 ) )
return - V_28 ;
F_45 ( & V_11 -> V_44 ) ;
if ( V_156 -> V_367 -> V_360 == V_358 ) {
V_11 -> V_89 &= ~ ( V_183 | V_185 | V_187 ) ;
F_10 ( V_11 , V_100 , V_11 -> V_89 |= V_11 -> V_200 ) ;
V_378 = V_11 -> V_63 ;
V_379 = V_11 -> V_64 ;
} else {
V_378 = V_11 -> V_64 ;
V_379 = V_11 -> V_63 ;
}
if ( ( V_379 > 0 ) && ( V_378 != V_379 ) ) {
if ( F_233 ( V_377 ) != V_11 -> V_115 ) {
F_47 ( & V_11 -> V_44 ) ;
F_234 ( V_377 , V_380 ) ;
return - V_126 ;
}
if ( F_235 ( V_377 ) != V_11 -> V_88 / 4 ) {
F_47 ( & V_11 -> V_44 ) ;
F_234 ( V_377 , V_381 ) ;
return - V_126 ;
}
F_47 ( & V_11 -> V_44 ) ;
return 0 ;
} else {
F_47 ( & V_11 -> V_44 ) ;
}
F_45 ( & V_11 -> V_44 ) ;
if ( ! V_11 -> V_221 ) {
if ( ( V_297 = F_51 ( V_11 , F_233 ( V_377 ) , 0 ) ) < 0 ) {
F_47 ( & V_11 -> V_44 ) ;
F_234 ( V_377 , V_380 ) ;
return V_297 ;
}
}
F_47 ( & V_11 -> V_44 ) ;
if ( ( V_297 = F_44 ( V_11 , F_235 ( V_377 ) ) ) < 0 ) {
F_234 ( V_377 , V_381 ) ;
return V_297 ;
}
return 0 ;
}
static int F_236 ( struct V_359 * V_156 ,
struct V_382 * V_383 )
{
struct V_11 * V_11 = F_223 ( V_156 ) ;
int V_362 ;
if ( F_50 ( V_383 -> V_361 >= V_11 -> V_271 ) )
return - V_116 ;
if ( ( V_362 = V_11 -> V_128 [ V_383 -> V_361 ] ) < 0 )
return - V_116 ;
V_383 -> V_281 = V_362 * V_363 ;
V_383 -> V_384 = 0 ;
V_383 -> V_268 = 32 ;
return 0 ;
}
static int F_237 ( struct V_359 * V_156 ,
unsigned int V_385 , void * V_339 )
{
switch ( V_385 ) {
case V_386 :
return F_230 ( V_156 ) ;
case V_387 :
return F_236 ( V_156 , V_339 ) ;
default:
break;
}
return F_238 ( V_156 , V_385 , V_339 ) ;
}
static int F_239 ( struct V_359 * V_156 , int V_385 )
{
struct V_11 * V_11 = F_223 ( V_156 ) ;
struct V_359 * V_372 ;
int V_373 ;
if ( F_14 ( V_11 ) )
return - V_28 ;
if ( F_27 ( V_11 , 0 ) )
return - V_28 ;
F_240 ( & V_11 -> V_44 ) ;
V_373 = V_11 -> V_373 ;
switch ( V_385 ) {
case V_388 :
V_373 |= 1 << V_156 -> V_360 ;
break;
case V_389 :
V_373 &= ~ ( 1 << V_156 -> V_360 ) ;
break;
default:
F_241 () ;
F_242 ( & V_11 -> V_44 ) ;
return - V_116 ;
}
if ( V_156 -> V_360 == V_358 )
V_372 = V_11 -> V_353 ;
else
V_372 = V_11 -> V_357 ;
if ( V_372 ) {
struct V_359 * V_97 ;
F_231 (s, substream) {
if ( V_97 == V_372 ) {
F_243 ( V_97 , V_156 ) ;
if ( V_385 == V_388 )
V_373 |= 1 << V_97 -> V_360 ;
else
V_373 &= ~ ( 1 << V_97 -> V_360 ) ;
goto V_390;
}
}
if ( V_385 == V_388 ) {
if ( ! ( V_373 & ( 1 << V_358 ) ) &&
V_156 -> V_360 == V_356 )
F_43 ( V_11 ) ;
} else {
if ( V_373 &&
V_156 -> V_360 == V_358 )
F_43 ( V_11 ) ;
}
} else {
if ( V_156 -> V_360 == V_356 )
F_43 ( V_11 ) ;
}
V_390:
F_243 ( V_156 , V_156 ) ;
if ( ! V_11 -> V_373 && V_373 )
F_41 ( V_11 ) ;
else if ( V_11 -> V_373 && ! V_373 )
F_42 ( V_11 ) ;
V_11 -> V_373 = V_373 ;
F_242 ( & V_11 -> V_44 ) ;
return 0 ;
}
static int F_244 ( struct V_359 * V_156 )
{
struct V_11 * V_11 = F_223 ( V_156 ) ;
int V_391 = 0 ;
if ( F_14 ( V_11 ) )
return - V_28 ;
if ( F_27 ( V_11 , 1 ) )
return - V_28 ;
F_45 ( & V_11 -> V_44 ) ;
if ( ! V_11 -> V_373 )
F_40 ( V_11 ) ;
F_47 ( & V_11 -> V_44 ) ;
return V_391 ;
}
static int F_245 ( struct V_376 * V_377 ,
struct V_392 * V_393 )
{
struct V_11 * V_11 = V_393 -> V_394 ;
struct V_395 * V_396 = F_246 ( V_377 , V_397 ) ;
if ( V_11 -> V_14 == V_19 ) {
unsigned int V_398 [ 3 ] ;
V_398 [ 0 ] = V_11 -> V_399 ;
V_398 [ 1 ] = V_11 -> V_400 ;
V_398 [ 2 ] = V_11 -> V_401 ;
return F_247 ( V_396 , 3 , V_398 , 0 ) ;
} else {
unsigned int V_398 [ 2 ] ;
V_398 [ 0 ] = V_11 -> V_400 ;
V_398 [ 1 ] = V_11 -> V_401 ;
return F_247 ( V_396 , 2 , V_398 , 0 ) ;
}
}
static int F_248 ( struct V_376 * V_377 ,
struct V_392 * V_393 )
{
unsigned int V_398 [ 3 ] ;
struct V_11 * V_11 = V_393 -> V_394 ;
struct V_395 * V_396 = F_246 ( V_377 , V_397 ) ;
if ( V_11 -> V_14 == V_19 ) {
V_398 [ 0 ] = V_11 -> V_402 ;
V_398 [ 1 ] = V_11 -> V_403 ;
V_398 [ 2 ] = V_11 -> V_404 ;
return F_247 ( V_396 , 3 , V_398 , 0 ) ;
} else {
V_398 [ 0 ] = V_11 -> V_403 ;
V_398 [ 1 ] = V_11 -> V_404 ;
}
return F_247 ( V_396 , 2 , V_398 , 0 ) ;
}
static int F_249 ( struct V_376 * V_377 ,
struct V_392 * V_393 )
{
struct V_11 * V_11 = V_393 -> V_394 ;
struct V_395 * V_396 = F_246 ( V_377 , V_397 ) ;
struct V_395 * V_405 = F_246 ( V_377 , V_380 ) ;
if ( V_405 -> V_267 > 96000 && V_11 -> V_14 == V_19 ) {
struct V_395 V_406 = {
. V_267 = V_11 -> V_399 ,
. V_250 = V_11 -> V_399 ,
. integer = 1 ,
} ;
return F_250 ( V_396 , & V_406 ) ;
} else if ( V_405 -> V_267 > 48000 && V_405 -> V_250 <= 96000 ) {
struct V_395 V_406 = {
. V_267 = V_11 -> V_400 ,
. V_250 = V_11 -> V_400 ,
. integer = 1 ,
} ;
return F_250 ( V_396 , & V_406 ) ;
} else if ( V_405 -> V_250 < 64000 ) {
struct V_395 V_406 = {
. V_267 = V_11 -> V_401 ,
. V_250 = V_11 -> V_401 ,
. integer = 1 ,
} ;
return F_250 ( V_396 , & V_406 ) ;
}
return 0 ;
}
static int F_251 ( struct V_376 * V_377 ,
struct V_392 * V_393 )
{
struct V_11 * V_11 = V_393 -> V_394 ;
struct V_395 * V_396 = F_246 ( V_377 , V_397 ) ;
struct V_395 * V_405 = F_246 ( V_377 , V_380 ) ;
if ( V_405 -> V_267 > 96000 && V_11 -> V_14 == V_19 ) {
struct V_395 V_406 = {
. V_267 = V_11 -> V_402 ,
. V_250 = V_11 -> V_402 ,
. integer = 1 ,
} ;
return F_250 ( V_396 , & V_406 ) ;
} else if ( V_405 -> V_267 > 48000 && V_405 -> V_250 <= 96000 ) {
struct V_395 V_406 = {
. V_267 = V_11 -> V_403 ,
. V_250 = V_11 -> V_403 ,
. integer = 1 ,
} ;
return F_250 ( V_396 , & V_406 ) ;
} else if ( V_405 -> V_250 < 64000 ) {
struct V_395 V_406 = {
. V_267 = V_11 -> V_404 ,
. V_250 = V_11 -> V_404 ,
. integer = 1 ,
} ;
return F_250 ( V_396 , & V_406 ) ;
}
return 0 ;
}
static int F_252 ( struct V_376 * V_377 ,
struct V_392 * V_393 )
{
struct V_11 * V_11 = V_393 -> V_394 ;
struct V_395 * V_396 = F_246 ( V_377 , V_397 ) ;
struct V_395 * V_405 = F_246 ( V_377 , V_380 ) ;
if ( V_396 -> V_267 >= V_11 -> V_404 ) {
struct V_395 V_406 = {
. V_267 = 32000 ,
. V_250 = 48000 ,
. integer = 1 ,
} ;
return F_250 ( V_405 , & V_406 ) ;
} else if ( V_396 -> V_250 <= V_11 -> V_402 && V_11 -> V_14 == V_19 ) {
struct V_395 V_406 = {
. V_267 = 128000 ,
. V_250 = 192000 ,
. integer = 1 ,
} ;
return F_250 ( V_405 , & V_406 ) ;
} else if ( V_396 -> V_250 <= V_11 -> V_403 ) {
struct V_395 V_406 = {
. V_267 = 64000 ,
. V_250 = 96000 ,
. integer = 1 ,
} ;
return F_250 ( V_405 , & V_406 ) ;
}
return 0 ;
}
static int F_253 ( struct V_376 * V_377 ,
struct V_392 * V_393 )
{
struct V_11 * V_11 = V_393 -> V_394 ;
struct V_395 * V_396 = F_246 ( V_377 , V_397 ) ;
struct V_395 * V_405 = F_246 ( V_377 , V_380 ) ;
if ( V_396 -> V_267 >= V_11 -> V_401 ) {
struct V_395 V_406 = {
. V_267 = 32000 ,
. V_250 = 48000 ,
. integer = 1 ,
} ;
return F_250 ( V_405 , & V_406 ) ;
} else if ( V_396 -> V_250 <= V_11 -> V_399 && V_11 -> V_14 == V_19 ) {
struct V_395 V_406 = {
. V_267 = 128000 ,
. V_250 = 192000 ,
. integer = 1 ,
} ;
return F_250 ( V_405 , & V_406 ) ;
} else if ( V_396 -> V_250 <= V_11 -> V_400 ) {
struct V_395 V_406 = {
. V_267 = 64000 ,
. V_250 = 96000 ,
. integer = 1 ,
} ;
return F_250 ( V_405 , & V_406 ) ;
}
return 0 ;
}
static int F_254 ( struct V_359 * V_156 )
{
struct V_11 * V_11 = F_223 ( V_156 ) ;
struct V_370 * V_371 = V_156 -> V_371 ;
if ( F_14 ( V_11 ) )
return - V_28 ;
if ( F_27 ( V_11 , 1 ) )
return - V_28 ;
F_45 ( & V_11 -> V_44 ) ;
F_255 ( V_156 ) ;
V_371 -> V_407 = V_408 ;
V_371 -> V_409 = V_11 -> V_101 ;
V_371 -> V_410 = V_102 ;
V_11 -> V_63 = V_411 -> V_412 ;
V_11 -> V_357 = V_156 ;
F_47 ( & V_11 -> V_44 ) ;
F_256 ( V_371 , 0 , 32 , 24 ) ;
F_257 ( V_371 , 0 , V_381 , & V_413 ) ;
if ( V_11 -> V_221 ) {
V_371 -> V_407 . V_414 = V_371 -> V_407 . V_415 = V_11 -> V_115 ;
} else if ( V_11 -> V_14 == V_19 ) {
V_371 -> V_407 . V_415 = 192000 ;
V_371 -> V_407 . V_416 = V_417 ;
F_257 ( V_371 , 0 , V_380 , & V_418 ) ;
}
if ( V_11 -> V_14 == V_19 ) {
V_371 -> V_407 . V_419 = V_11 -> V_402 ;
V_371 -> V_407 . V_420 = V_11 -> V_404 ;
}
F_258 ( V_371 , 0 , V_397 ,
F_248 , V_11 ,
V_397 , - 1 ) ;
F_258 ( V_371 , 0 , V_397 ,
F_251 , V_11 ,
V_380 , - 1 ) ;
F_258 ( V_371 , 0 , V_380 ,
F_252 , V_11 ,
V_397 , - 1 ) ;
if ( V_17 != V_11 -> V_14 ) {
V_11 -> V_200 = V_11 -> V_198 ;
V_11 -> V_301 -> V_421 [ 0 ] . V_422 &= ~ V_423 ;
F_259 ( V_11 -> V_168 , V_424 |
V_425 , & V_11 -> V_301 -> V_135 ) ;
}
return 0 ;
}
static int F_260 ( struct V_359 * V_156 )
{
struct V_11 * V_11 = F_223 ( V_156 ) ;
F_45 ( & V_11 -> V_44 ) ;
V_11 -> V_63 = - 1 ;
V_11 -> V_357 = NULL ;
F_47 ( & V_11 -> V_44 ) ;
if ( V_17 != V_11 -> V_14 ) {
V_11 -> V_301 -> V_421 [ 0 ] . V_422 |= V_423 ;
F_259 ( V_11 -> V_168 , V_424 |
V_425 , & V_11 -> V_301 -> V_135 ) ;
}
return 0 ;
}
static int F_261 ( struct V_359 * V_156 )
{
struct V_11 * V_11 = F_223 ( V_156 ) ;
struct V_370 * V_371 = V_156 -> V_371 ;
if ( F_14 ( V_11 ) )
return - V_28 ;
if ( F_27 ( V_11 , 1 ) )
return - V_28 ;
F_45 ( & V_11 -> V_44 ) ;
F_255 ( V_156 ) ;
V_371 -> V_407 = V_426 ;
V_371 -> V_409 = V_11 -> V_316 ;
V_371 -> V_410 = V_102 ;
V_11 -> V_64 = V_411 -> V_412 ;
V_11 -> V_353 = V_156 ;
F_47 ( & V_11 -> V_44 ) ;
F_256 ( V_371 , 0 , 32 , 24 ) ;
F_257 ( V_371 , 0 , V_381 , & V_413 ) ;
if ( V_11 -> V_14 == V_19 ) {
V_371 -> V_407 . V_419 = V_11 -> V_399 ;
V_371 -> V_407 . V_420 = V_11 -> V_401 ;
V_371 -> V_407 . V_415 = 192000 ;
V_371 -> V_407 . V_416 = V_417 ;
F_257 ( V_371 , 0 , V_380 , & V_418 ) ;
}
F_258 ( V_371 , 0 , V_397 ,
F_245 , V_11 ,
V_397 , - 1 ) ;
F_258 ( V_371 , 0 , V_397 ,
F_249 , V_11 ,
V_380 , - 1 ) ;
F_258 ( V_371 , 0 , V_380 ,
F_253 , V_11 ,
V_397 , - 1 ) ;
return 0 ;
}
static int F_262 ( struct V_359 * V_156 )
{
struct V_11 * V_11 = F_223 ( V_156 ) ;
F_45 ( & V_11 -> V_44 ) ;
V_11 -> V_64 = - 1 ;
V_11 -> V_353 = NULL ;
F_47 ( & V_11 -> V_44 ) ;
return 0 ;
}
static inline int F_263 ( void T_7 * V_427 , void T_9 * V_365 )
{
T_4 V_22 = F_13 ( V_365 ) ;
return F_228 ( V_427 , & V_22 , 4 ) ;
}
static inline int F_264 ( void T_7 * V_427 , void T_9 * V_428 , void T_9 * V_429 )
{
T_4 V_430 , V_431 ;
T_3 V_432 ;
V_430 = F_13 ( V_428 ) ;
V_431 = F_13 ( V_429 ) ;
V_432 = ( ( T_3 ) V_431 << 32 ) | V_430 ;
return F_228 ( V_427 , & V_432 , 8 ) ;
}
static inline int F_265 ( void T_7 * V_427 , void T_9 * V_428 , void T_9 * V_429 )
{
T_4 V_430 , V_431 ;
T_3 V_432 ;
V_430 = F_13 ( V_428 ) & 0xffffff00 ;
V_431 = F_13 ( V_429 ) & 0xffffff00 ;
V_432 = ( ( T_3 ) V_431 << 32 ) | V_430 ;
return F_228 ( V_427 , & V_432 , 8 ) ;
}
static int F_266 ( struct V_11 * V_11 , struct V_433 T_7 * V_434 )
{
int V_435 = 0 ;
int V_31 , V_436 , V_437 , V_438 ;
if ( F_12 ( V_11 , V_24 ) & V_439 )
V_435 = 1 ;
V_437 = V_435 ? 14 : 26 ;
for ( V_31 = 0 , V_436 = 0 ; V_31 < 26 ; ++ V_31 ) {
if ( V_435 && ( V_31 & 4 ) )
continue;
V_438 = V_440 - V_436 * 4 ;
if ( F_263 ( & V_434 -> V_441 [ V_31 ] , V_11 -> V_23 + V_438 ) )
return - V_368 ;
V_438 -= V_437 * 4 ;
if ( F_263 ( & V_434 -> V_442 [ V_31 ] , V_11 -> V_23 + V_438 ) )
return - V_368 ;
V_438 -= V_437 * 4 ;
if ( F_263 ( & V_434 -> V_443 [ V_31 ] , V_11 -> V_23 + V_438 ) )
return - V_368 ;
V_438 = V_444 + V_436 * 8 ;
if ( F_265 ( & V_434 -> V_445 [ V_31 ] , V_11 -> V_23 + V_438 ,
V_11 -> V_23 + V_438 + 4 ) )
return - V_368 ;
V_438 += V_437 * 8 ;
if ( F_265 ( & V_434 -> V_446 [ V_31 ] , V_11 -> V_23 + V_438 ,
V_11 -> V_23 + V_438 + 4 ) )
return - V_368 ;
V_438 += V_437 * 8 ;
if ( F_265 ( & V_434 -> V_447 [ V_31 ] , V_11 -> V_23 + V_438 ,
V_11 -> V_23 + V_438 + 4 ) )
return - V_368 ;
V_436 ++ ;
}
return 0 ;
}
static int F_267 ( struct V_11 * V_11 , struct V_433 T_7 * V_434 )
{
int V_31 , V_436 ;
struct V_448 T_9 * V_449 ;
int V_435 = 0 ;
if ( F_12 ( V_11 , V_24 ) & V_439 )
V_435 = 1 ;
V_449 = (struct V_448 T_9 * ) ( V_11 -> V_23 + V_450 ) ;
for ( V_31 = 0 , V_436 = 0 ; V_31 < 16 ; ++ V_31 , ++ V_436 ) {
if ( F_263 ( & V_434 -> V_441 [ V_31 ] , & V_449 -> V_451 [ V_436 ] ) )
return - V_368 ;
if ( F_263 ( & V_434 -> V_442 [ V_31 ] , & V_449 -> V_452 [ V_436 ] ) )
return - V_368 ;
if ( F_263 ( & V_434 -> V_443 [ V_31 ] , & V_449 -> V_453 [ V_436 ] ) )
return - V_368 ;
if ( F_264 ( & V_434 -> V_445 [ V_31 ] , & V_449 -> V_454 [ V_436 ] ,
& V_449 -> V_455 [ V_436 ] ) )
return - V_368 ;
if ( F_264 ( & V_434 -> V_446 [ V_31 ] , & V_449 -> V_456 [ V_436 ] ,
& V_449 -> V_457 [ V_436 ] ) )
return - V_368 ;
if ( F_264 ( & V_434 -> V_447 [ V_31 ] , & V_449 -> V_458 [ V_436 ] ,
& V_449 -> V_459 [ V_436 ] ) )
return - V_368 ;
if ( V_435 && V_31 == 3 ) V_31 += 4 ;
}
return 0 ;
}
static int F_268 ( struct V_11 * V_11 , struct V_433 T_7 * V_434 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < 26 ; V_31 ++ ) {
if ( F_263 ( & V_434 -> V_442 [ V_31 ] ,
V_11 -> V_23 + V_460 + V_31 * 4 ) )
return - V_368 ;
if ( F_263 ( & V_434 -> V_441 [ V_31 ] ,
V_11 -> V_23 + V_461 + V_31 * 4 ) )
return - V_368 ;
}
for ( V_31 = 0 ; V_31 < 28 ; V_31 ++ ) {
if ( F_263 ( & V_434 -> V_443 [ V_31 ] ,
V_11 -> V_23 + V_462 + V_31 * 4 ) )
return - V_368 ;
}
for ( V_31 = 0 ; V_31 < 26 ; ++ V_31 ) {
if ( F_264 ( & V_434 -> V_446 [ V_31 ] ,
V_11 -> V_23 + V_463 + V_31 * 8 + 4 ,
V_11 -> V_23 + V_463 + V_31 * 8 ) )
return - V_368 ;
if ( F_264 ( & V_434 -> V_445 [ V_31 ] ,
V_11 -> V_23 + V_464 + V_31 * 8 + 4 ,
V_11 -> V_23 + V_464 + V_31 * 8 ) )
return - V_368 ;
}
return 0 ;
}
static int F_269 ( struct V_465 * V_407 , struct V_466 * V_466 , unsigned int V_385 , unsigned long V_339 )
{
struct V_11 * V_11 = V_407 -> V_160 ;
void T_7 * V_467 = ( void T_7 * ) V_339 ;
int V_297 ;
switch ( V_385 ) {
case V_468 : {
struct V_433 T_7 * V_434 = (struct V_433 T_7 * ) V_339 ;
V_297 = F_14 ( V_11 ) ;
if ( V_297 < 0 )
return V_297 ;
V_297 = F_27 ( V_11 , 1 ) ;
if ( V_297 < 0 )
return V_297 ;
if ( ! ( V_11 -> V_26 & V_27 ) ) {
F_15 ( V_52 L_173 ) ;
return - V_116 ;
}
switch ( V_11 -> V_14 ) {
case V_20 :
return F_266 ( V_11 , V_434 ) ;
case V_19 :
return F_267 ( V_11 , V_434 ) ;
default:
return F_268 ( V_11 , V_434 ) ;
}
}
case V_469 : {
struct V_470 V_383 ;
unsigned long V_32 ;
int V_31 ;
V_297 = F_14 ( V_11 ) ;
if ( V_297 < 0 )
return V_297 ;
V_297 = F_27 ( V_11 , 1 ) ;
if ( V_297 < 0 )
return V_297 ;
memset ( & V_383 , 0 , sizeof( V_383 ) ) ;
F_23 ( & V_11 -> V_44 , V_32 ) ;
V_383 . V_309 = ( unsigned char ) F_150 ( V_11 ) ;
V_383 . V_471 = ( unsigned char ) F_171 ( V_11 ) ;
if ( V_11 -> V_14 != V_19 )
V_383 . V_472 = ( unsigned char ) F_175 ( V_11 ) ;
V_383 . V_473 = ( unsigned char ) F_173 ( V_11 ) ;
for ( V_31 = 0 ; V_31 < ( ( V_11 -> V_14 != V_15 && V_11 -> V_14 != V_17 && V_11 -> V_14 != V_19 ) ? 3 : 1 ) ; ++ V_31 )
V_383 . V_474 [ V_31 ] = ( unsigned char ) F_177 ( V_11 , V_31 ) ;
V_383 . V_475 = ( unsigned char ) F_88 ( V_11 ) ;
V_383 . V_476 = ( unsigned char ) F_95 ( V_11 ) ;
V_383 . V_477 = ( unsigned char ) F_99 ( V_11 ) ;
V_383 . V_478 = ( unsigned char ) F_103 ( V_11 ) ;
V_383 . V_479 = ( unsigned char ) F_107 ( V_11 ) ;
V_383 . V_480 = F_34 ( V_11 ) ;
V_383 . V_115 = V_11 -> V_115 ;
V_383 . V_481 = F_35 ( V_11 ) ;
V_383 . V_311 = ( unsigned char ) F_117 ( V_11 ) ;
V_383 . V_312 = ( unsigned char ) F_120 ( V_11 ) ;
V_383 . V_310 = ( unsigned char ) F_36 ( V_11 ) ;
V_383 . V_482 = ( unsigned char ) F_157 ( V_11 ) ;
if ( V_11 -> V_14 == V_19 ) {
V_383 . V_483 = ( unsigned char ) F_127 ( V_11 ) ;
V_383 . V_484 = ( unsigned char ) F_132 ( V_11 ) ;
V_383 . V_485 = ( unsigned char ) F_137 ( V_11 ) ;
V_383 . V_486 = ( unsigned char ) F_142 ( V_11 ) ;
} else if ( V_11 -> V_14 == V_17 ) {
V_383 . V_483 = ( unsigned char ) F_184 ( V_11 ) ;
V_383 . V_484 = ( unsigned char ) F_189 ( V_11 ) ;
}
if ( V_11 -> V_14 == V_19 || V_11 -> V_14 == V_20 )
V_383 . V_487 = ( unsigned char ) F_146 ( V_11 ) ;
F_25 ( & V_11 -> V_44 , V_32 ) ;
if ( F_228 ( V_467 , & V_383 , sizeof( V_383 ) ) )
return - V_368 ;
break;
}
case V_488 : {
struct V_489 V_490 ;
if ( V_11 -> V_14 != V_19 ) return - V_116 ;
V_490 . V_491 = V_11 -> V_401 - V_492 ;
V_490 . V_493 = V_11 -> V_404 - V_492 ;
if ( F_228 ( V_467 , & V_490 , sizeof( V_490 ) ) )
return - V_368 ;
break;
}
case V_494 : {
struct V_495 V_495 ;
int V_297 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) return - V_116 ;
if ( V_11 -> V_14 == V_496 ) {
if ( ( V_297 = F_26 ( V_11 ) ) < 0 )
return V_297 ;
}
V_495 . V_14 = V_11 -> V_14 ;
V_495 . V_18 = V_11 -> V_18 ;
if ( ( V_297 = F_228 ( V_467 , & V_495 , sizeof( V_495 ) ) ) )
return - V_368 ;
break;
}
case V_497 : {
struct V_498 T_7 * V_499 ;
T_4 T_7 * V_500 ;
int V_297 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) return - V_116 ;
if ( V_11 -> V_14 == V_496 ) return - V_116 ;
if ( V_11 -> V_26 & ( V_53 | V_27 ) )
return - V_126 ;
F_15 ( V_43 L_174 ) ;
V_499 = (struct V_498 T_7 * ) V_467 ;
if ( F_270 ( V_500 , & V_499 -> V_500 ) )
return - V_368 ;
if ( F_14 ( V_11 ) )
return - V_28 ;
if ( F_226 ( V_11 -> V_39 , V_500 , sizeof( V_11 -> V_39 ) ) != 0 )
return - V_368 ;
V_11 -> V_26 |= V_53 ;
if ( ( V_297 = F_19 ( V_11 ) ) < 0 )
return V_297 ;
if ( ! ( V_11 -> V_26 & V_42 ) ) {
if ( ( V_297 = F_271 ( V_11 ) ) < 0 )
return V_297 ;
F_272 ( V_11 ) ;
F_273 ( V_11 ) ;
if ( ( V_297 = F_274 ( V_11 -> V_168 , V_11 ) ) < 0 ) {
F_15 ( V_52 L_175 ) ;
return V_297 ;
}
}
break;
}
case V_501 : {
struct V_502 T_7 * V_503 = (struct V_502 T_7 * ) V_467 ;
if ( F_228 ( V_503 -> V_504 , V_11 -> V_59 , sizeof( unsigned short ) * V_58 ) )
return - V_368 ;
break;
}
default:
return - V_116 ;
}
return 0 ;
}
static int F_275 ( struct V_167 * V_168 , struct V_11 * V_11 )
{
struct V_465 * V_407 ;
int V_297 ;
if ( ( V_297 = F_276 ( V_168 , L_176 , 0 , & V_407 ) ) < 0 )
return V_297 ;
V_11 -> V_505 = V_407 ;
V_407 -> V_160 = V_11 ;
strcpy ( V_407 -> V_171 , L_177 ) ;
V_407 -> V_506 . V_507 = F_269 ;
V_407 -> V_506 . V_508 = F_269 ;
return 0 ;
}
static int F_277 ( struct V_167 * V_168 , struct V_11 * V_11 )
{
struct V_509 * V_354 ;
int V_297 ;
if ( ( V_297 = F_278 ( V_168 , V_11 -> V_314 , 0 , 1 , 1 , & V_354 ) ) < 0 )
return V_297 ;
V_11 -> V_354 = V_354 ;
V_354 -> V_160 = V_11 ;
strcpy ( V_354 -> V_171 , V_11 -> V_314 ) ;
F_279 ( V_354 , V_358 , & V_510 ) ;
F_279 ( V_354 , V_356 , & V_511 ) ;
V_354 -> V_176 = V_512 ;
return 0 ;
}
static void F_217 ( struct V_11 * V_11 )
{
V_11 -> V_40 |= V_513 ;
F_10 ( V_11 , V_34 , V_11 -> V_40 ) ;
}
static int F_271 ( struct V_11 * V_11 )
{
int V_31 ;
if ( F_20 ( V_11 , 0 , 100 ) ) {
F_15 ( V_52 L_178 ) ;
return - V_28 ;
}
for ( V_31 = 0 ; V_31 < V_11 -> V_271 ; ++ V_31 ) {
F_10 ( V_11 , V_514 + ( 4 * V_31 ) , 1 ) ;
F_10 ( V_11 , V_515 + ( 4 * V_31 ) , 1 ) ;
}
return 0 ;
}
static void F_272 ( struct V_11 * V_11 )
{
int V_65 , V_516 , V_517 ;
switch ( V_11 -> V_14 ) {
case V_16 :
V_11 -> V_314 = L_179 ;
V_11 -> V_401 = V_11 -> V_404 = V_518 ;
V_11 -> V_400 = V_11 -> V_403 = V_519 ;
break;
case V_20 :
V_11 -> V_314 = L_180 ;
V_11 -> V_401 = V_11 -> V_404 = V_520 ;
V_11 -> V_400 = V_11 -> V_403 = V_521 ;
break;
case V_19 :
V_65 = F_12 ( V_11 , V_24 ) ;
V_516 = ( V_65 & V_522 ) ? 0 : 4 ;
V_517 = ( V_65 & V_523 ) ? 0 : 4 ;
V_11 -> V_314 = L_181 ;
V_11 -> V_401 = V_492 + V_516 ;
V_11 -> V_400 = V_524 + V_516 ;
V_11 -> V_399 = V_525 + V_516 ;
V_11 -> V_404 = V_492 + V_517 ;
V_11 -> V_403 = V_524 + V_517 ;
V_11 -> V_402 = V_525 + V_517 ;
break;
case V_15 :
V_11 -> V_314 = L_182 ;
V_11 -> V_401 = V_11 -> V_404 = V_526 ;
V_11 -> V_400 = V_11 -> V_403 = V_527 ;
break;
case V_17 :
V_11 -> V_314 = L_183 ;
V_11 -> V_401 = V_528 - 1 ;
V_11 -> V_404 = V_528 ;
V_11 -> V_400 = V_528 - 1 ;
V_11 -> V_403 = V_528 ;
break;
default:
break;
}
}
static void F_273 ( struct V_11 * V_11 )
{
F_56 ( V_11 , 0 ) ;
F_56 ( V_11 , 1 ) ;
}
static int F_274 ( struct V_167 * V_168 , struct V_11 * V_11 )
{
int V_297 ;
if ( ( V_297 = F_277 ( V_168 , V_11 ) ) < 0 ) {
F_15 ( V_52 L_184 ) ;
return V_297 ;
}
if ( ( V_297 = F_73 ( V_168 , V_11 , 0 ) ) < 0 ) {
F_15 ( V_52 L_185 ) ;
return V_297 ;
}
if ( V_11 -> V_14 == V_16 || V_11 -> V_14 == V_20 ) {
if ( ( V_297 = F_73 ( V_168 , V_11 , 1 ) ) < 0 ) {
F_15 ( V_52 L_186 ) ;
return V_297 ;
}
}
if ( ( V_297 = F_203 ( V_168 , V_11 ) ) < 0 ) {
F_15 ( V_52 L_187 ) ;
return V_297 ;
}
F_209 ( V_11 ) ;
V_11 -> V_115 = - 1 ;
V_11 -> V_63 = - 1 ;
V_11 -> V_64 = - 1 ;
V_11 -> V_353 = NULL ;
V_11 -> V_357 = NULL ;
if ( ( V_297 = F_24 ( V_11 ) ) < 0 ) {
F_15 ( V_52 L_188 ) ;
return V_297 ;
}
if ( ! ( V_11 -> V_26 & V_42 ) ) {
strcpy ( V_168 -> V_170 , L_189 ) ;
sprintf ( V_168 -> V_529 , L_190 , V_11 -> V_314 ,
V_11 -> V_318 , V_11 -> V_317 ) ;
if ( ( V_297 = F_280 ( V_168 ) ) < 0 ) {
F_15 ( V_52 L_191 ) ;
return V_297 ;
}
V_11 -> V_26 |= V_42 ;
}
return 0 ;
}
static int F_29 ( struct V_11 * V_11 )
{
const char * V_530 ;
const struct V_499 * V_531 ;
int V_297 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 )
return 0 ;
if ( V_11 -> V_14 == V_496 ) {
if ( ( V_297 = F_26 ( V_11 ) ) < 0 )
return V_297 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 )
return 0 ;
}
switch ( V_11 -> V_14 ) {
case V_17 :
V_530 = L_192 ;
break;
case V_15 :
if ( V_11 -> V_18 == 0xa )
V_530 = L_193 ;
else
V_530 = L_194 ;
break;
case V_16 :
if ( V_11 -> V_18 == 0xa )
V_530 = L_195 ;
else
V_530 = L_196 ;
break;
default:
F_15 ( V_52 L_197 , V_11 -> V_14 ) ;
return - V_116 ;
}
if ( F_281 ( & V_531 , V_530 , & V_11 -> V_2 -> V_6 ) ) {
F_15 ( V_52 L_198 , V_530 ) ;
return - V_532 ;
}
if ( V_531 -> V_5 < sizeof( V_11 -> V_39 ) ) {
F_15 ( V_52 L_199 ,
( int ) V_531 -> V_5 , ( int ) sizeof( V_11 -> V_39 ) ) ;
F_282 ( V_531 ) ;
return - V_116 ;
}
memcpy ( V_11 -> V_39 , V_531 -> V_60 , sizeof( V_11 -> V_39 ) ) ;
F_282 ( V_531 ) ;
V_11 -> V_26 |= V_53 ;
if ( ( V_297 = F_19 ( V_11 ) ) < 0 )
return V_297 ;
if ( ! ( V_11 -> V_26 & V_42 ) ) {
if ( ( V_297 = F_271 ( V_11 ) ) < 0 )
return V_297 ;
if ( ( V_297 = F_275 ( V_11 -> V_168 , V_11 ) ) < 0 ) {
F_15 ( V_52 L_200 ) ;
return V_297 ;
}
F_272 ( V_11 ) ;
F_273 ( V_11 ) ;
if ( ( V_297 = F_274 ( V_11 -> V_168 , V_11 ) ) < 0 ) {
F_15 ( V_52 L_175 ) ;
return V_297 ;
}
}
return 0 ;
}
static int T_5 F_283 ( struct V_167 * V_168 ,
struct V_11 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_297 ;
int V_533 = 0 ;
int V_534 = 0 ;
V_11 -> V_317 = - 1 ;
V_11 -> V_26 = 0 ;
V_11 -> V_169 [ 0 ] . V_159 = NULL ;
V_11 -> V_169 [ 1 ] . V_159 = NULL ;
V_11 -> V_169 [ 0 ] . V_151 = NULL ;
V_11 -> V_169 [ 1 ] . V_151 = NULL ;
V_11 -> V_169 [ 0 ] . V_150 = NULL ;
V_11 -> V_169 [ 1 ] . V_150 = NULL ;
V_11 -> V_169 [ 0 ] . V_152 = 0 ;
V_11 -> V_169 [ 1 ] . V_152 = 0 ;
F_74 ( & V_11 -> V_169 [ 0 ] . V_44 ) ;
F_74 ( & V_11 -> V_169 [ 1 ] . V_44 ) ;
V_11 -> V_23 = NULL ;
V_11 -> V_89 = 0 ;
V_11 -> V_40 = 0 ;
V_11 -> V_14 = V_496 ;
V_11 -> V_271 = 26 ;
V_11 -> V_168 = V_168 ;
F_74 ( & V_11 -> V_44 ) ;
F_284 ( & V_11 -> V_161 , F_218 , ( unsigned long ) V_11 ) ;
F_285 ( V_11 -> V_2 , V_535 , & V_11 -> V_18 ) ;
V_11 -> V_18 &= 0xff ;
F_286 ( V_11 -> V_2 , V_536 , 0xFF ) ;
strcpy ( V_168 -> V_537 , L_201 ) ;
strcpy ( V_168 -> V_538 , L_202 ) ;
if ( V_11 -> V_18 < 0xa )
return - V_539 ;
else if ( V_11 -> V_18 < 0x64 )
V_11 -> V_314 = L_203 ;
else if ( V_11 -> V_18 < 0x96 ) {
V_11 -> V_314 = L_204 ;
V_533 = 1 ;
} else {
V_11 -> V_314 = L_205 ;
V_11 -> V_271 = 16 ;
V_534 = 1 ;
}
if ( ( V_297 = F_287 ( V_2 ) ) < 0 )
return V_297 ;
F_288 ( V_11 -> V_2 ) ;
if ( ( V_297 = F_289 ( V_2 , L_171 ) ) < 0 )
return V_297 ;
V_11 -> V_318 = F_290 ( V_2 , 0 ) ;
if ( ( V_11 -> V_23 = F_291 ( V_11 -> V_318 , V_540 ) ) == NULL ) {
F_15 ( V_52 L_206 , V_11 -> V_318 , V_11 -> V_318 + V_540 - 1 ) ;
return - V_126 ;
}
if ( F_292 ( V_2 -> V_317 , F_219 , V_541 ,
V_542 , V_11 ) ) {
F_15 ( V_52 L_207 , V_2 -> V_317 ) ;
return - V_126 ;
}
V_11 -> V_317 = V_2 -> V_317 ;
V_11 -> V_91 = 0 ;
V_11 -> V_266 = 1 ;
V_11 -> V_96 = 0 ;
if ( ( V_297 = F_213 ( V_11 ) ) < 0 )
return V_297 ;
if ( ! V_533 && ! V_534 ) {
V_297 = F_16 ( V_11 , 1000 , 10 ) ;
if ( V_297 < 0 )
return V_297 ;
if ( ( F_12 ( V_11 , V_24 ) & V_33 ) != 0 ) {
#ifdef F_28
if ( ( V_297 = F_29 ( V_11 ) ) < 0 )
F_15 ( V_52 L_208 ) ;
else
return 0 ;
#endif
F_15 ( V_43 L_209 ) ;
if ( ( V_297 = F_275 ( V_168 , V_11 ) ) < 0 )
return V_297 ;
return 0 ;
} else {
F_15 ( V_43 L_210 ) ;
if ( F_12 ( V_11 , V_48 ) & V_49 )
V_11 -> V_14 = V_17 ;
else if ( F_12 ( V_11 , V_48 ) & V_50 )
V_11 -> V_14 = V_15 ;
else
V_11 -> V_14 = V_16 ;
}
}
if ( ( V_297 = F_271 ( V_11 ) ) != 0 )
return V_297 ;
if ( V_533 )
V_11 -> V_14 = V_20 ;
if ( V_534 )
V_11 -> V_14 = V_19 ;
if ( ( V_297 = F_275 ( V_168 , V_11 ) ) < 0 )
return V_297 ;
F_272 ( V_11 ) ;
F_273 ( V_11 ) ;
V_11 -> V_26 |= V_27 ;
if ( ( V_297 = F_274 ( V_168 , V_11 ) ) < 0 )
return V_297 ;
return 0 ;
}
static int F_293 ( struct V_11 * V_11 )
{
if ( V_11 -> V_318 ) {
F_63 ( & V_11 -> V_161 ) ;
V_11 -> V_89 &= ~ ( V_99 | V_98 | V_154 | V_153 ) ;
F_10 ( V_11 , V_100 , V_11 -> V_89 ) ;
}
if ( V_11 -> V_317 >= 0 )
F_294 ( V_11 -> V_317 , ( void * ) V_11 ) ;
F_212 ( V_11 ) ;
if ( V_11 -> V_23 )
F_295 ( V_11 -> V_23 ) ;
if ( V_11 -> V_318 )
F_296 ( V_11 -> V_2 ) ;
F_297 ( V_11 -> V_2 ) ;
return 0 ;
}
static void F_298 ( struct V_167 * V_168 )
{
struct V_11 * V_11 = V_168 -> V_160 ;
if ( V_11 )
F_293 ( V_11 ) ;
}
static int T_5 F_299 ( struct V_1 * V_2 ,
const struct V_543 * V_544 )
{
static int V_6 ;
struct V_11 * V_11 ;
struct V_167 * V_168 ;
int V_297 ;
if ( V_6 >= V_545 )
return - V_539 ;
if ( ! V_546 [ V_6 ] ) {
V_6 ++ ;
return - V_532 ;
}
V_297 = F_300 ( V_282 [ V_6 ] , V_135 [ V_6 ] , V_547 ,
sizeof( struct V_11 ) , & V_168 ) ;
if ( V_297 < 0 )
return V_297 ;
V_11 = V_168 -> V_160 ;
V_168 -> V_548 = F_298 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_2 = V_2 ;
F_301 ( V_168 , & V_2 -> V_6 ) ;
if ( ( V_297 = F_283 ( V_168 , V_11 ) ) < 0 ) {
F_302 ( V_168 ) ;
return V_297 ;
}
strcpy ( V_168 -> V_170 , L_189 ) ;
sprintf ( V_168 -> V_529 , L_190 , V_11 -> V_314 ,
V_11 -> V_318 , V_11 -> V_317 ) ;
if ( ( V_297 = F_280 ( V_168 ) ) < 0 ) {
F_302 ( V_168 ) ;
return V_297 ;
}
F_303 ( V_2 , V_168 ) ;
V_6 ++ ;
return 0 ;
}
static void T_10 F_304 ( struct V_1 * V_2 )
{
F_302 ( F_305 ( V_2 ) ) ;
F_303 ( V_2 , NULL ) ;
}
static int T_11 F_306 ( void )
{
return F_307 ( & V_537 ) ;
}
static void T_12 F_308 ( void )
{
F_309 ( & V_537 ) ;
}
