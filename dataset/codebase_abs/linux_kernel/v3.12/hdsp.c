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
int V_24 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) return 0 ;
for ( V_24 = 0 ; V_24 < 500 ; V_24 ++ ) {
if ( 0 == ( F_12 ( V_11 , V_25 ) &
V_26 ) ) {
if ( V_24 ) {
F_15 ( L_1 ,
( 20 * V_24 ) ) ;
}
return 0 ;
}
F_16 ( 20 ) ;
}
F_17 ( V_27 L_2 ) ;
V_11 -> V_28 &= ~ V_29 ;
return - V_30 ;
}
static int F_18 ( struct V_11 * V_11 , unsigned int V_31 ,
unsigned int V_32 )
{
unsigned int V_24 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 )
return 0 ;
for ( V_24 = 0 ; V_24 != V_31 ; ++ V_24 ) {
if ( F_12 ( V_11 , V_25 ) & V_26 )
F_16 ( V_32 ) ;
else {
F_15 ( L_3 ,
V_24 * V_32 ) ;
return 0 ;
}
}
F_17 ( L_2 ) ;
V_11 -> V_28 &= ~ V_29 ;
return - V_30 ;
}
static int F_19 ( struct V_11 * V_11 ) {
int V_24 ;
unsigned long V_33 ;
const T_2 * V_34 ;
if ( V_11 -> V_35 )
V_34 = V_11 -> V_35 ;
else {
if ( ! V_11 -> V_36 )
return - V_37 ;
V_34 = ( T_2 * ) V_11 -> V_36 -> V_38 ;
if ( ! V_34 )
return - V_37 ;
}
if ( ( F_12 ( V_11 , V_25 ) & V_39 ) != 0 ) {
F_17 ( L_4 ) ;
F_10 ( V_11 , V_40 , V_41 ) ;
F_10 ( V_11 , V_42 , 0 ) ;
if ( F_20 ( V_11 , 0 , V_43 ) ) {
F_17 ( L_5 ) ;
F_10 ( V_11 , V_40 , V_44 ) ;
return - V_30 ;
}
F_10 ( V_11 , V_40 , V_45 ) ;
for ( V_24 = 0 ; V_24 < V_46 / 4 ; ++ V_24 ) {
F_10 ( V_11 , V_42 , V_34 [ V_24 ] ) ;
if ( F_20 ( V_11 , 127 , V_43 ) ) {
F_17 ( L_6 ) ;
F_10 ( V_11 , V_40 , V_44 ) ;
return - V_30 ;
}
}
F_20 ( V_11 , 3 , V_43 ) ;
F_10 ( V_11 , V_40 , V_44 ) ;
F_21 ( 3 ) ;
#ifdef F_22
V_11 -> V_47 = V_48 ;
#else
V_11 -> V_47 = 0 ;
#endif
F_10 ( V_11 , V_40 , V_11 -> V_47 ) ;
F_17 ( L_7 ) ;
}
if ( V_11 -> V_28 & V_49 ) {
F_17 ( V_50 L_8 ) ;
F_23 ( & V_11 -> V_51 , V_33 ) ;
F_24 ( V_11 ) ;
F_25 ( & V_11 -> V_51 , V_33 ) ;
}
V_11 -> V_28 |= V_29 ;
return 0 ;
}
static int F_26 ( struct V_11 * V_11 )
{
if ( ( F_12 ( V_11 , V_25 ) & V_39 ) != 0 ) {
F_10 ( V_11 , V_40 , V_45 ) ;
F_10 ( V_11 , V_42 , 0 ) ;
if ( F_20 ( V_11 , 0 , V_52 ) < 0 ) {
F_10 ( V_11 , V_40 , V_53 ) ;
F_10 ( V_11 , V_40 , V_45 ) ;
}
F_10 ( V_11 , V_40 , V_44 | V_54 ) ;
F_10 ( V_11 , V_42 , 0 ) ;
if ( F_20 ( V_11 , 0 , V_52 ) < 0 ) {
V_11 -> V_14 = V_15 ;
F_17 ( L_9 ) ;
return 0 ;
}
F_10 ( V_11 , V_40 , V_45 ) ;
F_10 ( V_11 , V_42 , 0 ) ;
if ( F_20 ( V_11 , 0 , V_52 ) == 0 ) {
V_11 -> V_14 = V_16 ;
F_17 ( L_10 ) ;
return 0 ;
}
F_10 ( V_11 , V_40 , V_53 ) ;
F_10 ( V_11 , V_40 , V_45 ) ;
F_10 ( V_11 , V_42 , 0 ) ;
if ( F_20 ( V_11 , 0 , V_52 ) == 0 ) {
V_11 -> V_14 = V_15 ;
F_17 ( L_9 ) ;
return 0 ;
}
F_10 ( V_11 , V_40 , V_53 ) ;
F_10 ( V_11 , V_40 , V_45 ) ;
F_10 ( V_11 , V_42 , 0 ) ;
if ( F_20 ( V_11 , 0 , V_52 ) < 0 ) {
V_11 -> V_14 = V_15 ;
F_17 ( L_9 ) ;
return 0 ;
}
V_11 -> V_14 = V_17 ;
F_17 ( L_11 ) ;
return 0 ;
} else {
if ( F_12 ( V_11 , V_55 ) & V_56 )
V_11 -> V_14 = V_17 ;
else if ( F_12 ( V_11 , V_55 ) & V_57 )
V_11 -> V_14 = V_15 ;
else
V_11 -> V_14 = V_16 ;
}
return 0 ;
}
static int F_27 ( struct V_11 * V_11 , int V_58 )
{
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 )
return 0 ;
if ( ( F_12 ( V_11 , V_25 ) & V_39 ) != 0 ) {
V_11 -> V_28 &= ~ V_29 ;
if ( ! V_58 )
return - V_30 ;
F_17 ( V_27 L_12 ) ;
if ( ! ( V_11 -> V_28 & V_59 ) ) {
if ( ! F_28 ( V_11 ) )
return 0 ;
F_17 ( V_27
L_13
L_14 ) ;
return - V_30 ;
}
if ( F_19 ( V_11 ) != 0 ) {
F_17 ( V_27
L_15
L_16 ) ;
return - V_30 ;
}
}
return 0 ;
}
static int F_20 ( struct V_11 * V_11 , int V_60 , int V_61 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_61 ; V_24 ++ ) {
if ( ( int ) ( F_12 ( V_11 , V_62 ) & 0xff ) <= V_60 )
return 0 ;
F_29 ( 100 ) ;
}
F_17 ( L_17 ,
V_60 , V_61 ) ;
return - 1 ;
}
static int F_30 ( struct V_11 * V_11 , unsigned int V_63 )
{
if ( V_63 >= V_64 )
return 0 ;
return V_11 -> V_65 [ V_63 ] ;
}
static int F_31 ( struct V_11 * V_11 , unsigned int V_63 , unsigned short V_38 )
{
unsigned int V_66 ;
if ( V_63 >= V_64 )
return - 1 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) {
if ( V_11 -> V_14 == V_19 && V_63 >= 512 )
return 0 ;
if ( V_11 -> V_14 == V_20 && V_63 >= 1352 )
return 0 ;
V_11 -> V_65 [ V_63 ] = V_38 ;
V_66 = V_63 / 2 ;
F_10 ( V_11 , 4096 + ( V_66 * 4 ) ,
( V_11 -> V_65 [ ( V_63 & 0x7fe ) + 1 ] << 16 ) +
V_11 -> V_65 [ V_63 & 0x7fe ] ) ;
return 0 ;
} else {
V_66 = ( V_63 << 16 ) + V_38 ;
if ( F_20 ( V_11 , 127 , V_43 ) )
return - 1 ;
F_10 ( V_11 , V_42 , V_66 ) ;
V_11 -> V_65 [ V_63 ] = V_38 ;
}
return 0 ;
}
static int F_32 ( struct V_11 * V_11 )
{
unsigned long V_33 ;
int V_67 = 1 ;
F_23 ( & V_11 -> V_51 , V_33 ) ;
if ( ( V_11 -> V_68 != V_11 -> V_69 ) &&
( V_11 -> V_68 >= 0 ) && ( V_11 -> V_69 >= 0 ) )
V_67 = 0 ;
F_25 ( & V_11 -> V_51 , V_33 ) ;
return V_67 ;
}
static int F_33 ( struct V_11 * V_11 )
{
unsigned int V_70 = F_12 ( V_11 , V_25 ) ;
unsigned int V_71 = ( V_70 & V_72 ) ;
if ( V_11 -> V_14 == V_19 )
V_71 = ( V_70 & V_73 ) ;
if ( V_70 & V_74 )
return 0 ;
switch ( V_71 ) {
case V_75 : return 32000 ;
case V_76 : return 44100 ;
case V_77 : return 48000 ;
case V_78 : return 64000 ;
case V_79 : return 88200 ;
case V_80 : return 96000 ;
case V_81 :
if ( V_11 -> V_14 == V_19 ) return 128000 ;
break;
case V_82 :
if ( V_11 -> V_14 == V_19 ) return 176400 ;
break;
case V_83 :
if ( V_11 -> V_14 == V_19 ) return 192000 ;
break;
default:
break;
}
F_17 ( L_18 , V_71 , V_70 ) ;
return 0 ;
}
static int F_34 ( struct V_11 * V_11 )
{
unsigned int V_84 = F_12 ( V_11 , V_55 ) ;
unsigned int V_71 = V_84 & V_85 ;
if ( V_11 -> V_14 == V_19 &&
F_35 ( V_11 ) == V_86 )
return F_33 ( V_11 ) ;
switch ( V_71 ) {
case V_87 : return 32000 ;
case V_88 : return 44100 ;
case V_89 : return 48000 ;
case V_90 : return 64000 ;
case V_91 : return 88200 ;
case V_92 : return 96000 ;
default:
return 0 ;
}
}
static void F_36 ( struct V_11 * V_11 )
{
V_11 -> V_93 = 1 << ( ( F_37 ( V_11 -> V_94 ) + 8 ) ) ;
}
static T_3 F_38 ( struct V_11 * V_11 )
{
int V_95 ;
V_95 = F_12 ( V_11 , V_25 ) ;
if ( ! V_11 -> V_96 )
return ( V_95 & V_97 ) ? ( V_11 -> V_93 / 4 ) : 0 ;
V_95 &= V_98 ;
V_95 /= 4 ;
V_95 &= ( V_11 -> V_93 / 2 ) - 1 ;
return V_95 ;
}
static void F_39 ( struct V_11 * V_11 )
{
F_10 ( V_11 , V_99 , 0 ) ;
if ( V_11 -> V_14 == V_19 && V_11 -> V_18 >= 152 )
F_10 ( V_11 , V_100 , V_11 -> V_101 ) ;
}
static void F_40 ( struct V_11 * V_102 )
{
V_102 -> V_94 |= ( V_103 | V_104 ) ;
F_10 ( V_102 , V_105 , V_102 -> V_94 ) ;
}
static void F_41 ( struct V_11 * V_102 )
{
V_102 -> V_94 &= ~ ( V_104 | V_103 ) ;
F_10 ( V_102 , V_105 , V_102 -> V_94 ) ;
}
static void F_42 ( struct V_11 * V_11 )
{
memset ( V_11 -> V_106 , 0 , V_107 ) ;
}
static int F_43 ( struct V_11 * V_102 , unsigned int V_108 )
{
int V_109 ;
F_44 ( & V_102 -> V_51 ) ;
V_108 >>= 7 ;
V_109 = 0 ;
while ( V_108 ) {
V_109 ++ ;
V_108 >>= 1 ;
}
V_102 -> V_94 &= ~ V_110 ;
V_102 -> V_94 |= F_45 ( V_109 ) ;
F_10 ( V_102 , V_105 , V_102 -> V_94 ) ;
F_36 ( V_102 ) ;
F_46 ( & V_102 -> V_51 ) ;
return 0 ;
}
static void F_47 ( struct V_11 * V_11 , int V_111 )
{
T_4 V_109 ;
if ( V_111 >= 112000 )
V_111 /= 4 ;
else if ( V_111 >= 56000 )
V_111 /= 2 ;
V_109 = V_112 ;
V_109 = F_48 ( V_109 , V_111 ) ;
F_49 ( V_109 >> 32 ) ;
V_11 -> V_101 = V_109 ;
F_10 ( V_11 , V_100 , V_11 -> V_101 ) ;
}
static int F_50 ( struct V_11 * V_11 , int V_111 , int V_113 )
{
int V_114 = 0 ;
int V_115 ;
int V_71 ;
if ( ! ( V_11 -> V_94 & V_116 ) ) {
if ( V_113 ) {
F_17 ( V_27 L_19 ) ;
return - 1 ;
} else {
int V_117 = F_34 ( V_11 ) ;
int V_118 = F_33 ( V_11 ) ;
if ( ( V_118 == V_117 * 2 ) && ( F_35 ( V_11 ) >= V_119 ) )
F_17 ( V_50 L_20 ) ;
else if ( V_11 -> V_14 == V_19 && ( V_118 == V_117 * 4 ) && ( F_35 ( V_11 ) >= V_119 ) )
F_17 ( V_50 L_21 ) ;
else if ( V_111 != V_117 ) {
F_17 ( V_50 L_22 ) ;
return - 1 ;
}
}
}
V_115 = V_11 -> V_120 ;
if ( V_111 > 96000 && V_11 -> V_14 != V_19 )
return - V_121 ;
switch ( V_111 ) {
case 32000 :
if ( V_115 > 48000 )
V_114 = 1 ;
V_71 = V_122 ;
break;
case 44100 :
if ( V_115 > 48000 )
V_114 = 1 ;
V_71 = V_123 ;
break;
case 48000 :
if ( V_115 > 48000 )
V_114 = 1 ;
V_71 = V_124 ;
break;
case 64000 :
if ( V_115 <= 48000 || V_115 > 96000 )
V_114 = 1 ;
V_71 = V_125 ;
break;
case 88200 :
if ( V_115 <= 48000 || V_115 > 96000 )
V_114 = 1 ;
V_71 = V_126 ;
break;
case 96000 :
if ( V_115 <= 48000 || V_115 > 96000 )
V_114 = 1 ;
V_71 = V_127 ;
break;
case 128000 :
if ( V_115 < 128000 )
V_114 = 1 ;
V_71 = V_128 ;
break;
case 176400 :
if ( V_115 < 128000 )
V_114 = 1 ;
V_71 = V_129 ;
break;
case 192000 :
if ( V_115 < 128000 )
V_114 = 1 ;
V_71 = V_130 ;
break;
default:
return - V_121 ;
}
if ( V_114 && ( V_11 -> V_69 >= 0 || V_11 -> V_68 >= 0 ) ) {
F_17 ( L_23 ,
V_11 -> V_69 ,
V_11 -> V_68 ) ;
return - V_131 ;
}
V_11 -> V_94 &= ~ V_132 ;
V_11 -> V_94 |= V_71 ;
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
if ( V_11 -> V_14 == V_19 && V_11 -> V_18 >= 152 )
F_47 ( V_11 , V_111 ) ;
if ( V_111 >= 128000 ) {
V_11 -> V_133 = V_134 ;
} else if ( V_111 > 48000 ) {
if ( V_11 -> V_14 == V_19 )
V_11 -> V_133 = V_135 ;
else
V_11 -> V_133 = V_136 ;
} else {
switch ( V_11 -> V_14 ) {
case V_17 :
case V_15 :
V_11 -> V_133 = V_137 ;
break;
case V_16 :
case V_20 :
V_11 -> V_133 = V_138 ;
break;
case V_19 :
V_11 -> V_133 = V_139 ;
break;
default:
break;
}
}
V_11 -> V_120 = V_111 ;
return 0 ;
}
static unsigned char F_51 ( struct V_11 * V_11 , int V_140 )
{
if ( V_140 )
return F_12 ( V_11 , V_141 ) ;
else
return F_12 ( V_11 , V_142 ) ;
}
static void F_52 ( struct V_11 * V_11 , int V_140 , int V_22 )
{
if ( V_140 )
F_10 ( V_11 , V_143 , V_22 ) ;
else
F_10 ( V_11 , V_144 , V_22 ) ;
}
static int F_53 ( struct V_11 * V_11 , int V_140 )
{
if ( V_140 )
return ( F_12 ( V_11 , V_145 ) & 0xff ) ;
else
return ( F_12 ( V_11 , V_146 ) & 0xff ) ;
}
static int F_54 ( struct V_11 * V_11 , int V_140 )
{
int V_147 ;
if ( V_140 )
V_147 = F_12 ( V_11 , V_148 ) & 0xff ;
else
V_147 = F_12 ( V_11 , V_149 ) & 0xff ;
if ( V_147 < 128 )
return 128 - V_147 ;
else
return 0 ;
}
static void F_55 ( struct V_11 * V_11 , int V_140 )
{
while ( F_53 ( V_11 , V_140 ) )
F_51 ( V_11 , V_140 ) ;
}
static int F_56 ( struct V_150 * V_151 )
{
unsigned long V_33 ;
int V_152 ;
int V_153 ;
int V_24 ;
unsigned char V_154 [ 128 ] ;
F_23 ( & V_151 -> V_51 , V_33 ) ;
if ( V_151 -> V_155 ) {
if ( ! F_57 ( V_151 -> V_155 ) ) {
if ( ( V_152 = F_54 ( V_151 -> V_11 , V_151 -> V_140 ) ) > 0 ) {
if ( V_152 > ( int ) sizeof ( V_154 ) )
V_152 = sizeof ( V_154 ) ;
if ( ( V_153 = F_58 ( V_151 -> V_155 , V_154 , V_152 ) ) > 0 ) {
for ( V_24 = 0 ; V_24 < V_153 ; ++ V_24 )
F_52 ( V_151 -> V_11 , V_151 -> V_140 , V_154 [ V_24 ] ) ;
}
}
}
}
F_25 ( & V_151 -> V_51 , V_33 ) ;
return 0 ;
}
static int F_59 ( struct V_150 * V_151 )
{
unsigned char V_154 [ 128 ] ;
unsigned long V_33 ;
int V_152 ;
int V_24 ;
F_23 ( & V_151 -> V_51 , V_33 ) ;
if ( ( V_152 = F_53 ( V_151 -> V_11 , V_151 -> V_140 ) ) > 0 ) {
if ( V_151 -> V_156 ) {
if ( V_152 > ( int ) sizeof ( V_154 ) )
V_152 = sizeof ( V_154 ) ;
for ( V_24 = 0 ; V_24 < V_152 ; ++ V_24 )
V_154 [ V_24 ] = F_51 ( V_151 -> V_11 , V_151 -> V_140 ) ;
if ( V_152 )
F_60 ( V_151 -> V_156 , V_154 , V_152 ) ;
} else {
while ( -- V_152 )
F_51 ( V_151 -> V_11 , V_151 -> V_140 ) ;
}
}
V_151 -> V_157 = 0 ;
if ( V_151 -> V_140 )
V_151 -> V_11 -> V_94 |= V_158 ;
else
V_151 -> V_11 -> V_94 |= V_159 ;
F_10 ( V_151 -> V_11 , V_105 , V_151 -> V_11 -> V_94 ) ;
F_25 ( & V_151 -> V_51 , V_33 ) ;
return F_56 ( V_151 ) ;
}
static void F_61 ( struct V_160 * V_161 , int V_162 )
{
struct V_11 * V_11 ;
struct V_150 * V_151 ;
unsigned long V_33 ;
T_2 V_163 ;
V_151 = (struct V_150 * ) V_161 -> V_164 -> V_165 ;
V_11 = V_151 -> V_11 ;
V_163 = V_151 -> V_140 ? V_158 : V_159 ;
F_23 ( & V_11 -> V_51 , V_33 ) ;
if ( V_162 ) {
if ( ! ( V_11 -> V_94 & V_163 ) ) {
F_55 ( V_11 , V_151 -> V_140 ) ;
V_11 -> V_94 |= V_163 ;
}
} else {
V_11 -> V_94 &= ~ V_163 ;
F_62 ( & V_11 -> V_166 ) ;
}
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
F_25 ( & V_11 -> V_51 , V_33 ) ;
}
static void F_63 ( unsigned long V_38 )
{
struct V_150 * V_151 = (struct V_150 * ) V_38 ;
unsigned long V_33 ;
F_56 ( V_151 ) ;
F_23 ( & V_151 -> V_51 , V_33 ) ;
if ( V_151 -> V_167 ) {
V_151 -> V_168 . V_169 = 1 + V_170 ;
F_64 ( & V_151 -> V_168 ) ;
}
F_25 ( & V_151 -> V_51 , V_33 ) ;
}
static void F_65 ( struct V_160 * V_161 , int V_162 )
{
struct V_150 * V_151 ;
unsigned long V_33 ;
V_151 = (struct V_150 * ) V_161 -> V_164 -> V_165 ;
F_23 ( & V_151 -> V_51 , V_33 ) ;
if ( V_162 ) {
if ( ! V_151 -> V_167 ) {
F_66 ( & V_151 -> V_168 ) ;
V_151 -> V_168 . V_171 = F_63 ;
V_151 -> V_168 . V_38 = ( unsigned long ) V_151 ;
V_151 -> V_168 . V_169 = 1 + V_170 ;
F_64 ( & V_151 -> V_168 ) ;
V_151 -> V_167 ++ ;
}
} else {
if ( V_151 -> V_167 && -- V_151 -> V_167 <= 0 )
F_67 ( & V_151 -> V_168 ) ;
}
F_25 ( & V_151 -> V_51 , V_33 ) ;
if ( V_162 )
F_56 ( V_151 ) ;
}
static int F_68 ( struct V_160 * V_161 )
{
struct V_150 * V_151 ;
V_151 = (struct V_150 * ) V_161 -> V_164 -> V_165 ;
F_44 ( & V_151 -> V_51 ) ;
F_55 ( V_151 -> V_11 , V_151 -> V_140 ) ;
V_151 -> V_156 = V_161 ;
F_46 ( & V_151 -> V_51 ) ;
return 0 ;
}
static int F_69 ( struct V_160 * V_161 )
{
struct V_150 * V_151 ;
V_151 = (struct V_150 * ) V_161 -> V_164 -> V_165 ;
F_44 ( & V_151 -> V_51 ) ;
V_151 -> V_155 = V_161 ;
F_46 ( & V_151 -> V_51 ) ;
return 0 ;
}
static int F_70 ( struct V_160 * V_161 )
{
struct V_150 * V_151 ;
F_61 ( V_161 , 0 ) ;
V_151 = (struct V_150 * ) V_161 -> V_164 -> V_165 ;
F_44 ( & V_151 -> V_51 ) ;
V_151 -> V_156 = NULL ;
F_46 ( & V_151 -> V_51 ) ;
return 0 ;
}
static int F_71 ( struct V_160 * V_161 )
{
struct V_150 * V_151 ;
F_65 ( V_161 , 0 ) ;
V_151 = (struct V_150 * ) V_161 -> V_164 -> V_165 ;
F_44 ( & V_151 -> V_51 ) ;
V_151 -> V_155 = NULL ;
F_46 ( & V_151 -> V_51 ) ;
return 0 ;
}
static int F_72 ( struct V_172 * V_173 , struct V_11 * V_11 , int V_140 )
{
char V_154 [ 32 ] ;
V_11 -> V_174 [ V_140 ] . V_140 = V_140 ;
V_11 -> V_174 [ V_140 ] . V_164 = NULL ;
V_11 -> V_174 [ V_140 ] . V_156 = NULL ;
V_11 -> V_174 [ V_140 ] . V_155 = NULL ;
V_11 -> V_174 [ V_140 ] . V_11 = V_11 ;
V_11 -> V_174 [ V_140 ] . V_167 = 0 ;
V_11 -> V_174 [ V_140 ] . V_157 = 0 ;
F_73 ( & V_11 -> V_174 [ V_140 ] . V_51 ) ;
sprintf ( V_154 , L_24 , V_173 -> V_175 , V_140 + 1 ) ;
if ( F_74 ( V_173 , V_154 , V_140 , 1 , 1 , & V_11 -> V_174 [ V_140 ] . V_164 ) < 0 )
return - 1 ;
sprintf ( V_11 -> V_174 [ V_140 ] . V_164 -> V_176 , L_25 , V_140 + 1 ) ;
V_11 -> V_174 [ V_140 ] . V_164 -> V_165 = & V_11 -> V_174 [ V_140 ] ;
F_75 ( V_11 -> V_174 [ V_140 ] . V_164 , V_177 , & V_178 ) ;
F_75 ( V_11 -> V_174 [ V_140 ] . V_164 , V_179 , & V_180 ) ;
V_11 -> V_174 [ V_140 ] . V_164 -> V_181 |= V_182 |
V_183 |
V_184 ;
return 0 ;
}
static T_2 F_76 ( struct V_185 * V_186 )
{
T_2 V_22 = 0 ;
V_22 |= ( V_186 -> V_70 [ 0 ] & V_187 ) ? V_188 : 0 ;
V_22 |= ( V_186 -> V_70 [ 0 ] & V_189 ) ? V_190 : 0 ;
if ( V_22 & V_188 )
V_22 |= ( V_186 -> V_70 [ 0 ] & V_191 ) ? V_192 : 0 ;
else
V_22 |= ( V_186 -> V_70 [ 0 ] & V_193 ) ? V_192 : 0 ;
return V_22 ;
}
static void F_77 ( struct V_185 * V_186 , T_2 V_22 )
{
V_186 -> V_70 [ 0 ] = ( ( V_22 & V_188 ) ? V_187 : 0 ) |
( ( V_22 & V_190 ) ? V_189 : 0 ) ;
if ( V_22 & V_188 )
V_186 -> V_70 [ 0 ] |= ( V_22 & V_192 ) ? V_191 : 0 ;
else
V_186 -> V_70 [ 0 ] |= ( V_22 & V_192 ) ? V_193 : 0 ;
}
static int F_78 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
V_197 -> type = V_198 ;
V_197 -> V_60 = 1 ;
return 0 ;
}
static int F_79 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
F_77 ( & V_200 -> V_201 . V_202 , V_11 -> V_203 ) ;
return 0 ;
}
static int F_81 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
T_2 V_22 ;
V_22 = F_76 ( & V_200 -> V_201 . V_202 ) ;
F_44 ( & V_11 -> V_51 ) ;
V_204 = V_22 != V_11 -> V_203 ;
V_11 -> V_203 = V_22 ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_82 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
V_197 -> type = V_198 ;
V_197 -> V_60 = 1 ;
return 0 ;
}
static int F_83 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
F_77 ( & V_200 -> V_201 . V_202 , V_11 -> V_205 ) ;
return 0 ;
}
static int F_84 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
T_2 V_22 ;
V_22 = F_76 ( & V_200 -> V_201 . V_202 ) ;
F_44 ( & V_11 -> V_51 ) ;
V_204 = V_22 != V_11 -> V_205 ;
V_11 -> V_205 = V_22 ;
V_11 -> V_94 &= ~ ( V_188 | V_190 | V_192 ) ;
F_10 ( V_11 , V_105 , V_11 -> V_94 |= V_22 ) ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_85 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
V_197 -> type = V_198 ;
V_197 -> V_60 = 1 ;
return 0 ;
}
static int F_86 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
V_200 -> V_201 . V_202 . V_70 [ 0 ] = V_195 -> V_206 ;
return 0 ;
}
static unsigned int F_87 ( struct V_11 * V_11 )
{
return F_88 ( V_11 -> V_94 & V_207 ) ;
}
static int F_89 ( struct V_11 * V_11 , int V_12 )
{
V_11 -> V_94 &= ~ V_207 ;
V_11 -> V_94 |= F_90 ( V_12 ) ;
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
return 0 ;
}
static int F_91 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [ 4 ] = { L_26 , L_27 , L_28 , L_29 } ;
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . V_210 . V_211 = ( ( V_11 -> V_14 == V_19 ) ? 4 : 3 ) ;
if ( V_197 -> V_201 . V_210 . V_212 > ( ( V_11 -> V_14 == V_19 ) ? 3 : 2 ) )
V_197 -> V_201 . V_210 . V_212 = ( ( V_11 -> V_14 == V_19 ) ? 3 : 2 ) ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_92 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_87 ( V_11 ) ;
return 0 ;
}
static int F_93 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . V_210 . V_212 [ 0 ] % ( ( V_11 -> V_14 == V_19 ) ? 4 : 3 ) ;
F_44 ( & V_11 -> V_51 ) ;
V_204 = V_22 != F_87 ( V_11 ) ;
if ( V_204 )
F_89 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_94 ( struct V_11 * V_11 , T_2 V_213 )
{
return ( V_11 -> V_94 & V_213 ) ? 1 : 0 ;
}
static int F_95 ( struct V_11 * V_11 , T_2 V_213 , int V_13 )
{
if ( V_13 )
V_11 -> V_94 |= V_213 ;
else
V_11 -> V_94 &= ~ V_213 ;
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
return 0 ;
}
static int F_96 ( struct V_194 * V_195 ,
struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
T_2 V_213 = V_195 -> V_206 ;
F_44 ( & V_11 -> V_51 ) ;
V_200 -> V_201 . integer . V_201 [ 0 ] = F_94 ( V_11 , V_213 ) ;
F_46 ( & V_11 -> V_51 ) ;
return 0 ;
}
static int F_97 ( struct V_194 * V_195 ,
struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
T_2 V_213 = V_195 -> V_206 ;
int V_204 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . integer . V_201 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_51 ) ;
V_204 = ( int ) V_22 != F_94 ( V_11 , V_213 ) ;
if ( V_204 )
F_95 ( V_11 , V_213 , V_22 ) ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_98 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [] = { L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 , L_37 , L_38 , L_39 } ;
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . V_210 . V_211 = ( V_11 -> V_14 == V_19 ) ? 10 : 7 ;
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_99 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
switch ( F_33 ( V_11 ) ) {
case 32000 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 0 ;
break;
case 44100 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 1 ;
break;
case 48000 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 2 ;
break;
case 64000 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 3 ;
break;
case 88200 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 4 ;
break;
case 96000 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 5 ;
break;
case 128000 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 7 ;
break;
case 176400 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 8 ;
break;
case 192000 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 9 ;
break;
default:
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_100 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
V_197 -> type = V_214 ;
V_197 -> V_60 = 1 ;
return 0 ;
}
static int F_101 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = V_11 -> V_120 ;
return 0 ;
}
static int F_102 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
static char * V_208 [] = { L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 , L_37 , L_38 , L_39 } ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . V_210 . V_211 = ( V_11 -> V_14 == V_19 ) ? 10 : 7 ;
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_103 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
switch ( F_34 ( V_11 ) ) {
case 32000 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 0 ;
break;
case 44100 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 1 ;
break;
case 48000 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 2 ;
break;
case 64000 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 3 ;
break;
case 88200 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 4 ;
break;
case 96000 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 5 ;
break;
case 128000 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 7 ;
break;
case 176400 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 8 ;
break;
case 192000 :
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 9 ;
break;
default:
V_200 -> V_201 . V_210 . V_212 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_104 ( struct V_11 * V_11 )
{
if ( V_11 -> V_94 & V_116 )
return 0 ;
else if ( F_34 ( V_11 ) != V_11 -> V_120 )
return 0 ;
return 1 ;
}
static int F_105 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [] = { L_40 , L_41 } ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . V_210 . V_211 = 2 ;
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_106 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_104 ( V_11 ) ;
return 0 ;
}
static int F_107 ( struct V_11 * V_11 )
{
if ( V_11 -> V_94 & V_116 ) {
switch ( V_11 -> V_120 ) {
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
static int F_108 ( struct V_11 * V_11 , int V_215 )
{
int V_111 ;
switch ( V_215 ) {
case V_216 :
if ( F_34 ( V_11 ) != 0 ) {
if ( ! F_50 ( V_11 , F_34 ( V_11 ) , 1 ) ) {
V_11 -> V_94 &= ~ V_116 ;
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
return 0 ;
}
}
return - 1 ;
case V_217 :
V_111 = 32000 ;
break;
case V_218 :
V_111 = 44100 ;
break;
case V_219 :
V_111 = 48000 ;
break;
case V_220 :
V_111 = 64000 ;
break;
case V_221 :
V_111 = 88200 ;
break;
case V_222 :
V_111 = 96000 ;
break;
case V_223 :
V_111 = 128000 ;
break;
case V_224 :
V_111 = 176400 ;
break;
case V_225 :
V_111 = 192000 ;
break;
default:
V_111 = 48000 ;
}
V_11 -> V_94 |= V_116 ;
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
F_50 ( V_11 , V_111 , 1 ) ;
return 0 ;
}
static int F_109 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [] = { L_42 , L_43 , L_44 , L_45 , L_46 , L_47 , L_48 , L_49 , L_50 , L_51 } ;
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
if ( V_11 -> V_14 == V_19 )
V_197 -> V_201 . V_210 . V_211 = 10 ;
else
V_197 -> V_201 . V_210 . V_211 = 7 ;
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_110 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_107 ( V_11 ) ;
return 0 ;
}
static int F_111 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . V_210 . V_212 [ 0 ] ;
if ( V_22 < 0 ) V_22 = 0 ;
if ( V_11 -> V_14 == V_19 ) {
if ( V_22 > 9 )
V_22 = 9 ;
} else {
if ( V_22 > 6 )
V_22 = 6 ;
}
F_44 ( & V_11 -> V_51 ) ;
if ( V_22 != F_107 ( V_11 ) )
V_204 = ( F_108 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_204 = 0 ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_112 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . integer . V_201 [ 0 ] = V_11 -> V_226 ;
return 0 ;
}
static int F_113 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
V_204 = ( int ) V_200 -> V_201 . integer . V_201 [ 0 ] != V_11 -> V_226 ;
if ( V_204 )
V_11 -> V_226 = ! ! V_200 -> V_201 . integer . V_201 [ 0 ] ;
return V_204 ;
}
static int F_114 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_94 & V_227 ) {
case V_228 :
return 0 ;
case V_229 :
return 1 ;
case V_230 :
return 2 ;
default:
return 1 ;
}
}
static int F_115 ( struct V_11 * V_11 , int V_215 )
{
V_11 -> V_94 &= ~ V_227 ;
switch ( V_215 ) {
case 0 :
V_11 -> V_94 |= V_228 ;
break;
case 1 :
V_11 -> V_94 |= V_229 ;
break;
case 2 :
V_11 -> V_94 |= V_230 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
return 0 ;
}
static int F_116 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [] = { L_52 , L_53 , L_54 } ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . V_210 . V_211 = 3 ;
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_117 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_114 ( V_11 ) ;
return 0 ;
}
static int F_118 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . V_210 . V_212 [ 0 ] ;
if ( V_22 < 0 ) V_22 = 0 ;
if ( V_22 > 2 ) V_22 = 2 ;
F_44 ( & V_11 -> V_51 ) ;
if ( V_22 != F_114 ( V_11 ) )
V_204 = ( F_115 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_204 = 0 ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_119 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_94 & V_231 ) {
case V_232 :
return 0 ;
case V_233 :
return 1 ;
case V_234 :
return 2 ;
default:
return 1 ;
}
}
static int F_120 ( struct V_11 * V_11 , int V_215 )
{
V_11 -> V_94 &= ~ V_231 ;
switch ( V_215 ) {
case 0 :
V_11 -> V_94 |= V_232 ;
break;
case 1 :
V_11 -> V_94 |= V_233 ;
break;
case 2 :
V_11 -> V_94 |= V_234 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
return 0 ;
}
static int F_121 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [] = { L_55 , L_53 , L_56 } ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . V_210 . V_211 = 3 ;
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_122 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_119 ( V_11 ) ;
return 0 ;
}
static int F_123 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . V_210 . V_212 [ 0 ] ;
if ( V_22 < 0 ) V_22 = 0 ;
if ( V_22 > 2 ) V_22 = 2 ;
F_44 ( & V_11 -> V_51 ) ;
if ( V_22 != F_119 ( V_11 ) )
V_204 = ( F_120 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_204 = 0 ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_124 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_94 & V_235 ) {
case V_236 :
return 0 ;
case V_237 :
return 1 ;
case V_238 :
return 2 ;
default:
return 0 ;
}
}
static int F_125 ( struct V_11 * V_11 , int V_215 )
{
V_11 -> V_94 &= ~ V_235 ;
switch ( V_215 ) {
case 0 :
V_11 -> V_94 |= V_236 ;
break;
case 1 :
V_11 -> V_94 |= V_237 ;
break;
case 2 :
V_11 -> V_94 |= V_238 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
return 0 ;
}
static int F_126 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [] = { L_57 , L_58 , L_59 } ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . V_210 . V_211 = 3 ;
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_127 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_124 ( V_11 ) ;
return 0 ;
}
static int F_128 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . V_210 . V_212 [ 0 ] ;
if ( V_22 < 0 ) V_22 = 0 ;
if ( V_22 > 2 ) V_22 = 2 ;
F_44 ( & V_11 -> V_51 ) ;
if ( V_22 != F_124 ( V_11 ) )
V_204 = ( F_125 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_204 = 0 ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_129 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_94 & V_239 ) {
case V_240 :
return V_241 ;
case V_242 :
return V_243 ;
case V_244 :
return V_245 ;
case V_246 :
return V_247 ;
case V_248 :
return V_249 ;
case V_250 :
return V_251 ;
default:
return V_249 ;
}
return 0 ;
}
static int F_130 ( struct V_11 * V_11 , int V_252 )
{
V_11 -> V_94 &= ~ V_239 ;
switch ( V_252 ) {
case V_241 :
V_11 -> V_94 &= ~ V_239 ;
break;
case V_243 :
V_11 -> V_94 |= V_242 ;
break;
case V_245 :
V_11 -> V_94 |= V_244 ;
break;
case V_247 :
V_11 -> V_94 |= V_246 ;
break;
case V_249 :
V_11 -> V_94 |= V_248 ;
break;
case V_251 :
V_11 -> V_94 |= V_250 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
return 0 ;
}
static int F_131 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [] = { L_60 , L_61 , L_62 , L_63 , L_64 , L_65 } ;
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_20 :
V_197 -> V_201 . V_210 . V_211 = 6 ;
break;
case V_15 :
V_197 -> V_201 . V_210 . V_211 = 4 ;
break;
case V_19 :
V_197 -> V_201 . V_210 . V_211 = 3 ;
break;
default:
return - V_121 ;
}
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_132 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_129 ( V_11 ) ;
return 0 ;
}
static int F_133 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 , V_253 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_20 :
V_253 = 6 ;
break;
case V_15 :
V_253 = 4 ;
break;
case V_19 :
V_253 = 3 ;
break;
default:
return - V_30 ;
}
V_22 = V_200 -> V_201 . V_210 . V_212 [ 0 ] % V_253 ;
F_44 ( & V_11 -> V_51 ) ;
V_204 = ( int ) V_22 != F_129 ( V_11 ) ;
F_130 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_35 ( struct V_11 * V_11 )
{
unsigned int V_84 = F_12 ( V_11 , V_55 ) ;
switch ( V_84 & V_254 ) {
case V_255 :
return V_256 ;
case V_257 :
return V_258 ;
case V_259 :
return V_86 ;
case V_254 :
return V_260 ;
case V_261 :
return V_119 ;
case V_262 :
return V_263 ;
case V_264 :
return V_265 ;
default:
return V_256 ;
}
return 0 ;
}
static int F_134 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [] = { L_60 , L_63 , L_61 , L_36 , L_62 , L_64 , L_65 } ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . V_210 . V_211 = 7 ;
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_135 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_35 ( V_11 ) ;
return 0 ;
}
static int F_136 ( struct V_11 * V_11 , int V_266 )
{
if ( V_266 )
V_11 -> V_96 = 1 ;
else
V_11 -> V_96 = 0 ;
return 0 ;
}
static int F_137 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
F_44 ( & V_11 -> V_51 ) ;
V_200 -> V_201 . integer . V_201 [ 0 ] = V_11 -> V_96 ;
F_46 ( & V_11 -> V_51 ) ;
return 0 ;
}
static int F_138 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . integer . V_201 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_51 ) ;
V_204 = ( int ) V_22 != V_11 -> V_96 ;
F_136 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_139 ( struct V_11 * V_11 , int V_267 )
{
if ( V_267 )
V_11 -> V_268 = 1 ;
else
V_11 -> V_268 = 0 ;
return 0 ;
}
static int F_140 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
F_44 ( & V_11 -> V_51 ) ;
V_200 -> V_201 . integer . V_201 [ 0 ] = V_11 -> V_268 ;
F_46 ( & V_11 -> V_51 ) ;
return 0 ;
}
static int F_141 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . integer . V_201 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_51 ) ;
V_204 = ( int ) V_22 != V_11 -> V_268 ;
F_139 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_142 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
V_197 -> type = V_214 ;
V_197 -> V_60 = 3 ;
V_197 -> V_201 . integer . V_269 = 0 ;
V_197 -> V_201 . integer . V_253 = 65536 ;
V_197 -> V_201 . integer . V_270 = 1 ;
return 0 ;
}
static int F_143 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_271 ;
int V_272 ;
int V_63 ;
V_271 = V_200 -> V_201 . integer . V_201 [ 0 ] ;
V_272 = V_200 -> V_201 . integer . V_201 [ 1 ] ;
if ( V_271 >= V_11 -> V_273 )
V_63 = F_8 ( V_11 , V_271 - V_11 -> V_273 , V_272 ) ;
else
V_63 = F_9 ( V_11 , V_271 , V_272 ) ;
F_44 ( & V_11 -> V_51 ) ;
V_200 -> V_201 . integer . V_201 [ 2 ] = F_30 ( V_11 , V_63 ) ;
F_46 ( & V_11 -> V_51 ) ;
return 0 ;
}
static int F_144 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
int V_271 ;
int V_272 ;
int V_274 ;
int V_63 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_271 = V_200 -> V_201 . integer . V_201 [ 0 ] ;
V_272 = V_200 -> V_201 . integer . V_201 [ 1 ] ;
if ( V_271 >= V_11 -> V_273 )
V_63 = F_8 ( V_11 , V_271 - V_11 -> V_273 , V_272 ) ;
else
V_63 = F_9 ( V_11 , V_271 , V_272 ) ;
V_274 = V_200 -> V_201 . integer . V_201 [ 2 ] ;
F_44 ( & V_11 -> V_51 ) ;
V_204 = V_274 != F_30 ( V_11 , V_63 ) ;
if ( V_204 )
F_31 ( V_11 , V_63 , V_274 ) ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_145 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [] = { L_66 , L_67 , L_68 } ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . V_210 . V_211 = 3 ;
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_146 ( struct V_11 * V_11 )
{
int V_84 = F_12 ( V_11 , V_55 ) ;
if ( V_84 & V_275 ) {
if ( V_84 & V_276 )
return 2 ;
else
return 1 ;
} else
return 0 ;
return 0 ;
}
static int F_147 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_146 ( V_11 ) ;
return 0 ;
}
static int F_148 ( struct V_11 * V_11 )
{
int V_70 = F_12 ( V_11 , V_25 ) ;
if ( V_70 & V_74 )
return 0 ;
else {
if ( V_70 & V_277 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_149 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_148 ( V_11 ) ;
return 0 ;
}
static int F_150 ( struct V_11 * V_11 )
{
int V_70 = F_12 ( V_11 , V_25 ) ;
if ( V_70 & V_278 ) {
if ( V_70 & V_279 )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_151 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_150 ( V_11 ) ;
return 0 ;
}
static int F_152 ( struct V_11 * V_11 , int V_280 )
{
int V_70 = F_12 ( V_11 , V_25 ) ;
if ( V_70 & ( V_281 >> V_280 ) ) {
if ( V_70 & ( V_282 >> V_280 ) )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_153 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
int V_283 ;
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_283 = V_200 -> V_140 . V_284 - 1 ;
F_49 ( V_283 < 0 ) ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_20 :
if ( V_283 >= 3 )
return - V_121 ;
break;
case V_15 :
case V_19 :
if ( V_283 >= 1 )
return - V_121 ;
break;
default:
return - V_30 ;
}
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_152 ( V_11 , V_283 ) ;
return 0 ;
}
static int F_154 ( struct V_11 * V_11 )
{
T_4 V_109 ;
unsigned int V_101 = V_11 -> V_101 ;
int V_120 = V_11 -> V_120 ;
if ( ! V_101 )
return 0 ;
V_109 = V_112 ;
V_109 = F_48 ( V_109 , V_101 ) ;
if ( V_120 >= 112000 )
V_109 *= 4 ;
else if ( V_120 >= 56000 )
V_109 *= 2 ;
return ( ( int ) V_109 ) - V_120 ;
}
static int F_155 ( struct V_11 * V_11 , int V_285 )
{
int V_111 = V_11 -> V_120 + V_285 ;
F_47 ( V_11 , V_111 ) ;
return 0 ;
}
static int F_156 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
V_197 -> type = V_214 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . integer . V_269 = - 5000 ;
V_197 -> V_201 . integer . V_253 = 5000 ;
return 0 ;
}
static int F_157 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_154 ( V_11 ) ;
return 0 ;
}
static int F_158 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . V_210 . V_212 [ 0 ] ;
F_44 ( & V_11 -> V_51 ) ;
if ( V_22 != F_154 ( V_11 ) )
V_204 = ( F_155 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_204 = 0 ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_159 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_94 & V_286 ) {
case V_287 :
return 0 ;
case V_288 :
return 2 ;
case V_289 :
return 3 ;
case V_290 :
return 4 ;
}
return 1 ;
}
static int F_160 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_159 ( V_11 ) ;
return 0 ;
}
static int F_161 ( struct V_11 * V_11 , int V_215 )
{
V_11 -> V_94 &= ~ V_286 ;
switch ( V_215 ) {
case 0 :
V_11 -> V_94 |= V_287 ;
break;
case 1 :
break;
case 2 :
V_11 -> V_94 |= V_288 ;
break;
case 3 :
V_11 -> V_94 |= V_289 ;
break;
case 4 :
V_11 -> V_94 |= V_290 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
return 0 ;
}
static int F_162 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . V_210 . V_212 [ 0 ] ;
if ( V_22 < 0 )
V_22 = 0 ;
if ( V_22 > 4 )
V_22 = 4 ;
F_44 ( & V_11 -> V_51 ) ;
if ( V_22 != F_159 ( V_11 ) )
V_204 = ( F_161 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_204 = 0 ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_163 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [] = { L_69 , L_70 , L_71 , L_72 , L_73 } ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . V_210 . V_211 = 5 ;
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_164 ( struct V_11 * V_11 )
{
switch ( V_11 -> V_94 & V_291 ) {
case V_292 :
return 0 ;
case V_293 :
return 2 ;
case V_294 :
return 3 ;
case V_295 :
return 4 ;
}
return 1 ;
}
static int F_165 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . V_210 . V_212 [ 0 ] = F_164 ( V_11 ) ;
return 0 ;
}
static int F_166 ( struct V_11 * V_11 , int V_215 )
{
V_11 -> V_94 &= ~ V_291 ;
switch ( V_215 ) {
case 0 :
V_11 -> V_94 |= V_292 ;
break;
case 1 :
break;
case 2 :
V_11 -> V_94 |= V_293 ;
break;
case 3 :
V_11 -> V_94 |= V_294 ;
break;
case 4 :
V_11 -> V_94 |= V_295 ;
break;
default:
return - 1 ;
}
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
return 0 ;
}
static int F_167 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . V_210 . V_212 [ 0 ] ;
if ( V_22 < 0 )
V_22 = 0 ;
if ( V_22 > 4 )
V_22 = 4 ;
F_44 ( & V_11 -> V_51 ) ;
if ( V_22 != F_164 ( V_11 ) )
V_204 = ( F_166 ( V_11 , V_22 ) == 0 ) ? 1 : 0 ;
else
V_204 = 0 ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_168 ( struct V_11 * V_11 )
{
return ( V_11 -> V_94 & V_296 ) ? 1 : 0 ;
}
static int F_169 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . integer . V_201 [ 0 ] = F_168 ( V_11 ) ;
return 0 ;
}
static int F_170 ( struct V_11 * V_11 , int V_297 )
{
if ( V_297 )
V_11 -> V_94 |= V_296 ;
else
V_11 -> V_94 &= ~ V_296 ;
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
return 0 ;
}
static int F_171 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . integer . V_201 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_51 ) ;
V_204 = ( int ) V_22 != F_168 ( V_11 ) ;
F_170 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_172 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [] = { L_74 , L_75 } ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . V_210 . V_211 = 2 ;
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_173 ( struct V_11 * V_11 )
{
return ( V_11 -> V_94 & V_298 ) ? 1 : 0 ;
}
static int F_174 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
V_200 -> V_201 . integer . V_201 [ 0 ] = F_173 ( V_11 ) ;
return 0 ;
}
static int F_175 ( struct V_11 * V_11 , int V_297 )
{
if ( V_297 )
V_11 -> V_94 |= V_298 ;
else
V_11 -> V_94 &= ~ V_298 ;
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
return 0 ;
}
static int F_176 ( struct V_194 * V_195 , struct V_199 * V_200 )
{
struct V_11 * V_11 = F_80 ( V_195 ) ;
int V_204 ;
unsigned int V_22 ;
if ( ! F_32 ( V_11 ) )
return - V_131 ;
V_22 = V_200 -> V_201 . integer . V_201 [ 0 ] & 1 ;
F_44 ( & V_11 -> V_51 ) ;
V_204 = ( int ) V_22 != F_173 ( V_11 ) ;
F_175 ( V_11 , V_22 ) ;
F_46 ( & V_11 -> V_51 ) ;
return V_204 ;
}
static int F_177 ( struct V_194 * V_195 , struct V_196 * V_197 )
{
static char * V_208 [] = { L_74 , L_75 } ;
V_197 -> type = V_209 ;
V_197 -> V_60 = 1 ;
V_197 -> V_201 . V_210 . V_211 = 2 ;
if ( V_197 -> V_201 . V_210 . V_212 >= V_197 -> V_201 . V_210 . V_211 )
V_197 -> V_201 . V_210 . V_212 = V_197 -> V_201 . V_210 . V_211 - 1 ;
strcpy ( V_197 -> V_201 . V_210 . V_176 , V_208 [ V_197 -> V_201 . V_210 . V_212 ] ) ;
return 0 ;
}
static int F_178 ( struct V_172 * V_173 , struct V_11 * V_11 )
{
unsigned int V_280 ;
int V_299 ;
struct V_194 * V_300 ;
if ( V_11 -> V_14 == V_17 ) {
for ( V_280 = 0 ; V_280 < F_179 ( V_301 ) ; V_280 ++ ) {
V_299 = F_180 ( V_173 , V_300 = F_181 ( & V_301 [ V_280 ] , V_11 ) ) ;
if ( V_299 < 0 )
return V_299 ;
}
return 0 ;
}
for ( V_280 = 0 ; V_280 < F_179 ( V_302 ) ; V_280 ++ ) {
if ( ( V_299 = F_180 ( V_173 , V_300 = F_181 ( & V_302 [ V_280 ] , V_11 ) ) ) < 0 )
return V_299 ;
if ( V_280 == 1 )
V_11 -> V_303 = V_300 ;
}
V_304 . V_176 = L_76 ;
V_304 . V_284 = 1 ;
if ( ( V_299 = F_180 ( V_173 , V_300 = F_181 ( & V_304 , V_11 ) ) ) )
return V_299 ;
if ( V_11 -> V_14 == V_16 || V_11 -> V_14 == V_20 ) {
for ( V_280 = 1 ; V_280 < 3 ; ++ V_280 ) {
V_304 . V_284 = V_280 + 1 ;
if ( ( V_299 = F_180 ( V_173 , V_300 = F_181 ( & V_304 , V_11 ) ) ) )
return V_299 ;
}
}
if ( V_11 -> V_14 == V_19 ) {
for ( V_280 = 0 ; V_280 < F_179 ( V_305 ) ; V_280 ++ ) {
if ( ( V_299 = F_180 ( V_173 , V_300 = F_181 ( & V_305 [ V_280 ] , V_11 ) ) ) < 0 )
return V_299 ;
}
}
if ( V_11 -> V_14 == V_19 || V_11 -> V_14 == V_20 ) {
if ( ( V_299 = F_180 ( V_173 , V_300 = F_181 ( & V_306 , V_11 ) ) ) < 0 )
return V_299 ;
}
return 0 ;
}
static void
F_182 ( struct V_307 * V_308 , struct V_309 * V_310 )
{
struct V_11 * V_11 = V_308 -> V_165 ;
unsigned int V_70 ;
unsigned int V_84 ;
char * V_311 ;
char * V_312 ;
char * V_313 ;
char * V_314 ;
int V_315 ;
V_70 = F_12 ( V_11 , V_25 ) ;
V_84 = F_12 ( V_11 , V_55 ) ;
F_183 ( V_310 , L_77 , V_11 -> V_316 ,
V_11 -> V_173 -> V_317 + 1 ) ;
F_183 ( V_310 , L_78 ,
V_11 -> V_318 , V_11 -> V_106 ) ;
F_183 ( V_310 , L_79 ,
V_11 -> V_319 , V_11 -> V_320 , ( unsigned long ) V_11 -> V_23 ) ;
F_183 ( V_310 , L_80 , V_11 -> V_94 ) ;
F_183 ( V_310 , L_81 ,
V_11 -> V_47 ) ;
F_183 ( V_310 , L_82 , V_70 ) ;
F_183 ( V_310 , L_83 , V_84 ) ;
if ( F_14 ( V_11 ) ) {
F_183 ( V_310 , L_84
L_85 ) ;
return;
}
if ( F_27 ( V_11 , 0 ) ) {
if ( V_11 -> V_28 & V_59 ) {
if ( F_19 ( V_11 ) != 0 ) {
F_183 ( V_310 , L_86
L_87
L_88 ) ;
return;
}
} else {
int V_299 = - V_121 ;
V_299 = F_28 ( V_11 ) ;
if ( V_299 < 0 ) {
F_183 ( V_310 ,
L_89
L_90 ) ;
return;
}
}
}
F_183 ( V_310 , L_91 , F_12 ( V_11 , V_62 ) & 0xff ) ;
F_183 ( V_310 , L_92 , F_12 ( V_11 , V_149 ) ) ;
F_183 ( V_310 , L_93 , F_12 ( V_11 , V_146 ) ) ;
F_183 ( V_310 , L_94 , F_12 ( V_11 , V_148 ) ) ;
F_183 ( V_310 , L_95 , F_12 ( V_11 , V_145 ) ) ;
F_183 ( V_310 , L_96 , V_11 -> V_268 ? L_97 : L_98 ) ;
F_183 ( V_310 , L_99 ) ;
V_315 = 1 << ( 6 + F_37 ( V_11 -> V_94 & V_110 ) ) ;
F_183 ( V_310 , L_100 , V_315 , ( unsigned long ) V_11 -> V_93 ) ;
F_183 ( V_310 , L_101 , F_38 ( V_11 ) ) ;
F_183 ( V_310 , L_102 , V_11 -> V_96 ? L_97 : L_98 ) ;
F_183 ( V_310 , L_103 , ( V_11 -> V_94 & V_321 ) ? L_97 : L_98 ) ;
F_183 ( V_310 , L_104 , ( V_84 & V_322 ) | ( V_84 & V_57 ) << 1 | ( V_84 & V_56 ) << 2 ) ;
F_183 ( V_310 , L_99 ) ;
switch ( F_107 ( V_11 ) ) {
case V_216 :
V_314 = L_42 ;
break;
case V_217 :
V_314 = L_105 ;
break;
case V_218 :
V_314 = L_44 ;
break;
case V_219 :
V_314 = L_106 ;
break;
case V_220 :
V_314 = L_107 ;
break;
case V_221 :
V_314 = L_47 ;
break;
case V_222 :
V_314 = L_108 ;
break;
case V_223 :
V_314 = L_49 ;
break;
case V_224 :
V_314 = L_50 ;
break;
case V_225 :
V_314 = L_109 ;
break;
default:
V_314 = L_110 ;
}
F_183 ( V_310 , L_111 , V_314 ) ;
if ( F_104 ( V_11 ) )
V_313 = L_41 ;
else
V_313 = L_40 ;
switch ( F_129 ( V_11 ) ) {
case V_249 :
V_311 = L_112 ;
break;
case V_251 :
V_311 = L_63 ;
break;
case V_247 :
V_311 = L_113 ;
break;
case V_241 :
V_311 = L_62 ;
break;
case V_243 :
V_311 = L_64 ;
break;
case V_245 :
V_311 = L_65 ;
break;
default:
V_311 = L_112 ;
break;
}
F_183 ( V_310 , L_114 , V_311 ) ;
switch ( F_35 ( V_11 ) ) {
case V_256 :
V_312 = L_112 ;
break;
case V_258 :
V_312 = L_63 ;
break;
case V_86 :
V_312 = L_113 ;
break;
case V_260 :
V_312 = L_36 ;
break;
case V_119 :
V_312 = L_62 ;
break;
case V_263 :
V_312 = L_64 ;
break;
case V_265 :
V_312 = L_65 ;
break;
default:
V_312 = L_115 ;
break;
}
F_183 ( V_310 , L_116 , V_312 ) ;
F_183 ( V_310 , L_117 , F_34 ( V_11 ) ) ;
F_183 ( V_310 , L_118 , V_313 ) ;
F_183 ( V_310 , L_119 , V_11 -> V_120 ) ;
F_183 ( V_310 , L_120 , V_11 -> V_226 ? L_121 : L_122 ) ;
F_183 ( V_310 , L_99 ) ;
if ( V_11 -> V_14 != V_17 ) {
switch ( F_87 ( V_11 ) ) {
case V_323 :
F_183 ( V_310 , L_123 ) ;
break;
case V_324 :
F_183 ( V_310 , L_124 ) ;
break;
case V_325 :
F_183 ( V_310 , L_125 ) ;
break;
case V_326 :
F_183 ( V_310 , L_126 ) ;
break;
default:
F_183 ( V_310 , L_127 ) ;
break;
}
}
if ( V_17 == V_11 -> V_14 ) {
if ( V_11 -> V_94 & V_296 )
F_183 ( V_310 , L_128 ) ;
else
F_183 ( V_310 , L_129 ) ;
if ( V_11 -> V_94 & V_298 )
F_183 ( V_310 , L_130 ) ;
else
F_183 ( V_310 , L_131 ) ;
switch ( V_11 -> V_94 & V_286 ) {
case V_287 :
F_183 ( V_310 , L_132 ) ;
break;
case V_327 :
F_183 ( V_310 , L_133 ) ;
break;
case V_288 :
F_183 ( V_310 , L_134 ) ;
break;
case V_289 :
F_183 ( V_310 , L_135 ) ;
break;
case V_290 :
F_183 ( V_310 , L_136 ) ;
break;
default:
F_183 ( V_310 , L_137 ) ;
}
switch ( V_11 -> V_94 & V_291 ) {
case V_292 :
F_183 ( V_310 , L_138 ) ;
break;
case V_328 :
F_183 ( V_310 , L_139 ) ;
break;
case V_293 :
F_183 ( V_310 , L_140 ) ;
break;
case V_294 :
F_183 ( V_310 , L_141 ) ;
break;
case V_295 :
F_183 ( V_310 , L_142 ) ;
break;
default:
F_183 ( V_310 , L_143 ) ;
}
} else {
if ( V_11 -> V_94 & V_329 )
F_183 ( V_310 , L_144 ) ;
else
F_183 ( V_310 , L_145 ) ;
if ( V_11 -> V_94 & V_188 )
F_183 ( V_310 , L_146 ) ;
else
F_183 ( V_310 , L_147 ) ;
if ( V_11 -> V_94 & V_192 )
F_183 ( V_310 , L_148 ) ;
else
F_183 ( V_310 , L_149 ) ;
if ( V_11 -> V_94 & V_190 )
F_183 ( V_310 , L_150 ) ;
else
F_183 ( V_310 , L_151 ) ;
V_315 = F_33 ( V_11 ) ;
if ( V_315 != 0 )
F_183 ( V_310 , L_152 , V_315 ) ;
else
F_183 ( V_310 , L_153 ) ;
}
F_183 ( V_310 , L_99 ) ;
V_315 = V_70 & V_282 ;
if ( V_70 & V_281 )
F_183 ( V_310 , L_154 , V_315 ? L_68 : L_67 ) ;
else
F_183 ( V_310 , L_155 ) ;
switch ( V_11 -> V_14 ) {
case V_16 :
case V_20 :
V_315 = V_70 & V_330 ;
if ( V_70 & V_331 )
F_183 ( V_310 , L_156 , V_315 ? L_68 : L_67 ) ;
else
F_183 ( V_310 , L_157 ) ;
V_315 = V_70 & V_332 ;
if ( V_70 & V_333 )
F_183 ( V_310 , L_158 , V_315 ? L_68 : L_67 ) ;
else
F_183 ( V_310 , L_159 ) ;
break;
default:
break;
}
V_315 = V_70 & V_277 ;
if ( V_70 & V_74 )
F_183 ( V_310 , L_160 ) ;
else
F_183 ( V_310 , L_161 , V_315 ? L_68 : L_67 ) ;
V_315 = V_84 & V_276 ;
if ( V_84 & V_275 )
F_183 ( V_310 , L_162 , V_315 ? L_68 : L_67 ) ;
else
F_183 ( V_310 , L_163 ) ;
V_315 = V_70 & V_279 ;
if ( V_70 & V_278 )
F_183 ( V_310 , L_164 , V_315 ? L_68 : L_67 ) ;
else
F_183 ( V_310 , L_165 ) ;
F_183 ( V_310 , L_99 ) ;
if ( V_11 -> V_14 == V_19 ) {
char * V_334 ;
switch ( F_119 ( V_11 ) ) {
case 0 :
V_334 = L_55 ;
break;
case 1 :
V_334 = L_53 ;
break;
default:
V_334 = L_56 ;
break;
}
F_183 ( V_310 , L_166 , V_334 ) ;
switch ( F_114 ( V_11 ) ) {
case 0 :
V_334 = L_52 ;
break;
case 1 :
V_334 = L_53 ;
break;
default:
V_334 = L_55 ;
break;
}
F_183 ( V_310 , L_167 , V_334 ) ;
switch ( F_124 ( V_11 ) ) {
case 0 :
V_334 = L_57 ;
break;
case 1 :
V_334 = L_58 ;
break;
default:
V_334 = L_59 ;
break;
}
F_183 ( V_310 , L_168 , V_334 ) ;
F_183 ( V_310 , L_169 ,
F_94 ( V_11 , V_335 ) ?
L_170 : L_171 ) ;
if ( V_11 -> V_94 & V_336 )
F_183 ( V_310 , L_172 ) ;
else
F_183 ( V_310 , L_173 ) ;
F_183 ( V_310 , L_99 ) ;
}
}
static void F_184 ( struct V_11 * V_11 )
{
struct V_307 * V_308 ;
if ( ! F_185 ( V_11 -> V_173 , L_174 , & V_308 ) )
F_186 ( V_308 , V_11 , F_182 ) ;
}
static void F_187 ( struct V_11 * V_11 )
{
F_6 ( & V_11 -> V_337 , V_11 -> V_2 ) ;
F_6 ( & V_11 -> V_338 , V_11 -> V_2 ) ;
}
static int F_188 ( struct V_11 * V_11 )
{
unsigned long V_339 , V_340 ;
if ( F_1 ( V_11 -> V_2 , & V_11 -> V_337 , V_107 ) < 0 ||
F_1 ( V_11 -> V_2 , & V_11 -> V_338 , V_107 ) < 0 ) {
if ( V_11 -> V_337 . V_10 )
F_189 ( & V_11 -> V_337 ) ;
F_190 ( V_27 L_175 , V_11 -> V_316 ) ;
return - V_9 ;
}
V_340 = F_191 ( V_11 -> V_337 . V_63 , 0x10000ul ) ;
V_339 = F_191 ( V_11 -> V_338 . V_63 , 0x10000ul ) ;
F_10 ( V_11 , V_341 , V_340 ) ;
F_10 ( V_11 , V_342 , V_339 ) ;
V_11 -> V_318 = V_11 -> V_337 . V_10 + ( V_340 - V_11 -> V_337 . V_63 ) ;
V_11 -> V_106 = V_11 -> V_338 . V_10 + ( V_339 - V_11 -> V_338 . V_63 ) ;
return 0 ;
}
static int F_24 ( struct V_11 * V_11 )
{
unsigned int V_24 ;
V_11 -> V_94 = V_116 |
V_343 |
F_45 ( 7 ) |
V_321 ;
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
#ifdef F_22
V_11 -> V_47 = V_48 ;
#else
V_11 -> V_47 = 0 ;
#endif
if ( V_11 -> V_14 == V_20 )
F_192 ( V_11 ) ;
else
F_10 ( V_11 , V_40 , V_11 -> V_47 ) ;
F_39 ( V_11 ) ;
F_36 ( V_11 ) ;
for ( V_24 = 0 ; V_24 < V_64 ; ++ V_24 )
V_11 -> V_65 [ V_24 ] = V_344 ;
for ( V_24 = 0 ; V_24 < ( ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) ? 1352 : V_64 ) ; ++ V_24 ) {
if ( F_31 ( V_11 , V_24 , V_344 ) )
return - V_30 ;
}
if ( V_11 -> V_14 == V_19 ) {
V_11 -> V_94 |= ( V_229 | V_233 | V_236 ) ;
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
}
F_50 ( V_11 , 48000 , 1 ) ;
return 0 ;
}
static void F_193 ( unsigned long V_345 )
{
struct V_11 * V_11 = (struct V_11 * ) V_345 ;
if ( V_11 -> V_174 [ 0 ] . V_157 )
F_59 ( & V_11 -> V_174 [ 0 ] ) ;
if ( V_11 -> V_174 [ 1 ] . V_157 )
F_59 ( & V_11 -> V_174 [ 1 ] ) ;
}
static T_5 F_194 ( int V_319 , void * V_346 )
{
struct V_11 * V_11 = (struct V_11 * ) V_346 ;
unsigned int V_70 ;
int V_347 ;
int V_348 ;
int V_349 ;
unsigned int V_350 ;
unsigned int V_351 ;
int V_352 = 0 ;
V_70 = F_12 ( V_11 , V_25 ) ;
V_347 = V_70 & V_353 ;
V_348 = V_70 & V_354 ;
V_349 = V_70 & V_355 ;
if ( ! V_347 && ! V_348 && ! V_349 )
return V_356 ;
F_10 ( V_11 , V_357 , 0 ) ;
V_350 = F_12 ( V_11 , V_146 ) & 0xff ;
V_351 = F_12 ( V_11 , V_145 ) & 0xff ;
if ( ! ( V_11 -> V_28 & V_49 ) )
return V_358 ;
if ( V_347 ) {
if ( V_11 -> V_359 )
F_195 ( V_11 -> V_360 -> V_361 [ V_362 ] . V_161 ) ;
if ( V_11 -> V_363 )
F_195 ( V_11 -> V_360 -> V_361 [ V_364 ] . V_161 ) ;
}
if ( V_348 && V_350 ) {
if ( V_11 -> V_268 ) {
V_11 -> V_94 &= ~ V_159 ;
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
V_11 -> V_174 [ 0 ] . V_157 = 1 ;
V_352 = 1 ;
} else {
F_59 ( & V_11 -> V_174 [ 0 ] ) ;
}
}
if ( V_11 -> V_14 != V_15 && V_11 -> V_14 != V_17 && V_11 -> V_14 != V_19 && V_349 && V_351 ) {
if ( V_11 -> V_268 ) {
V_11 -> V_94 &= ~ V_158 ;
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
V_11 -> V_174 [ 1 ] . V_157 = 1 ;
V_352 = 1 ;
} else {
F_59 ( & V_11 -> V_174 [ 1 ] ) ;
}
}
if ( V_11 -> V_268 && V_352 )
F_196 ( & V_11 -> V_166 ) ;
return V_358 ;
}
static T_3 F_197 ( struct V_365 * V_161 )
{
struct V_11 * V_11 = F_198 ( V_161 ) ;
return F_38 ( V_11 ) ;
}
static char * F_199 ( struct V_11 * V_11 ,
int V_366 ,
int V_367 )
{
int V_368 ;
if ( F_49 ( V_367 < 0 || V_367 >= V_11 -> V_273 ) )
return NULL ;
if ( ( V_368 = V_11 -> V_133 [ V_367 ] ) < 0 )
return NULL ;
if ( V_366 == V_362 )
return V_11 -> V_318 + ( V_368 * V_369 ) ;
else
return V_11 -> V_106 + ( V_368 * V_369 ) ;
}
static int F_200 ( struct V_365 * V_161 , int V_367 ,
T_3 V_370 , void T_6 * V_371 , T_3 V_60 )
{
struct V_11 * V_11 = F_198 ( V_161 ) ;
char * V_372 ;
if ( F_49 ( V_370 + V_60 > V_369 / 4 ) )
return - V_121 ;
V_372 = F_199 ( V_11 , V_161 -> V_373 -> V_366 , V_367 ) ;
if ( F_49 ( ! V_372 ) )
return - V_30 ;
if ( F_201 ( V_372 + V_370 * 4 , V_371 , V_60 * 4 ) )
return - V_374 ;
return V_60 ;
}
static int F_202 ( struct V_365 * V_161 , int V_367 ,
T_3 V_370 , void T_6 * V_375 , T_3 V_60 )
{
struct V_11 * V_11 = F_198 ( V_161 ) ;
char * V_372 ;
if ( F_49 ( V_370 + V_60 > V_369 / 4 ) )
return - V_121 ;
V_372 = F_199 ( V_11 , V_161 -> V_373 -> V_366 , V_367 ) ;
if ( F_49 ( ! V_372 ) )
return - V_30 ;
if ( F_203 ( V_375 , V_372 + V_370 * 4 , V_60 * 4 ) )
return - V_374 ;
return V_60 ;
}
static int F_204 ( struct V_365 * V_161 , int V_367 ,
T_3 V_370 , T_3 V_60 )
{
struct V_11 * V_11 = F_198 ( V_161 ) ;
char * V_372 ;
V_372 = F_199 ( V_11 , V_161 -> V_373 -> V_366 , V_367 ) ;
if ( F_49 ( ! V_372 ) )
return - V_30 ;
memset ( V_372 + V_370 * 4 , 0 , V_60 * 4 ) ;
return V_60 ;
}
static int F_205 ( struct V_365 * V_161 )
{
struct V_376 * V_377 = V_161 -> V_377 ;
struct V_11 * V_11 = F_198 ( V_161 ) ;
struct V_365 * V_378 ;
if ( V_161 -> V_366 == V_364 )
V_378 = V_11 -> V_359 ;
else
V_378 = V_11 -> V_363 ;
if ( V_11 -> V_379 )
V_377 -> V_70 -> V_380 = F_38 ( V_11 ) ;
else
V_377 -> V_70 -> V_380 = 0 ;
if ( V_378 ) {
struct V_365 * V_102 ;
struct V_376 * V_381 = V_378 -> V_377 ;
F_206 (s, substream) {
if ( V_102 == V_378 ) {
V_381 -> V_70 -> V_380 = V_377 -> V_70 -> V_380 ;
break;
}
}
}
return 0 ;
}
static int F_207 ( struct V_365 * V_161 ,
struct V_382 * V_383 )
{
struct V_11 * V_11 = F_198 ( V_161 ) ;
int V_299 ;
T_7 V_384 ;
T_7 V_385 ;
if ( F_14 ( V_11 ) )
return - V_30 ;
if ( F_27 ( V_11 , 1 ) )
return - V_30 ;
F_44 ( & V_11 -> V_51 ) ;
if ( V_161 -> V_373 -> V_366 == V_364 ) {
V_11 -> V_94 &= ~ ( V_188 | V_190 | V_192 ) ;
F_10 ( V_11 , V_105 , V_11 -> V_94 |= V_11 -> V_205 ) ;
V_384 = V_11 -> V_68 ;
V_385 = V_11 -> V_69 ;
} else {
V_384 = V_11 -> V_69 ;
V_385 = V_11 -> V_68 ;
}
if ( ( V_385 > 0 ) && ( V_384 != V_385 ) ) {
if ( F_208 ( V_383 ) != V_11 -> V_120 ) {
F_46 ( & V_11 -> V_51 ) ;
F_209 ( V_383 , V_386 ) ;
return - V_131 ;
}
if ( F_210 ( V_383 ) != V_11 -> V_93 / 4 ) {
F_46 ( & V_11 -> V_51 ) ;
F_209 ( V_383 , V_387 ) ;
return - V_131 ;
}
F_46 ( & V_11 -> V_51 ) ;
return 0 ;
} else {
F_46 ( & V_11 -> V_51 ) ;
}
F_44 ( & V_11 -> V_51 ) ;
if ( ! V_11 -> V_226 ) {
if ( ( V_299 = F_50 ( V_11 , F_208 ( V_383 ) , 0 ) ) < 0 ) {
F_46 ( & V_11 -> V_51 ) ;
F_209 ( V_383 , V_386 ) ;
return V_299 ;
}
}
F_46 ( & V_11 -> V_51 ) ;
if ( ( V_299 = F_43 ( V_11 , F_210 ( V_383 ) ) ) < 0 ) {
F_209 ( V_383 , V_387 ) ;
return V_299 ;
}
return 0 ;
}
static int F_211 ( struct V_365 * V_161 ,
struct V_388 * V_389 )
{
struct V_11 * V_11 = F_198 ( V_161 ) ;
int V_368 ;
if ( F_49 ( V_389 -> V_367 >= V_11 -> V_273 ) )
return - V_121 ;
if ( ( V_368 = V_11 -> V_133 [ V_389 -> V_367 ] ) < 0 )
return - V_121 ;
V_389 -> V_283 = V_368 * V_369 ;
V_389 -> V_390 = 0 ;
V_389 -> V_270 = 32 ;
return 0 ;
}
static int F_212 ( struct V_365 * V_161 ,
unsigned int V_391 , void * V_345 )
{
switch ( V_391 ) {
case V_392 :
return F_205 ( V_161 ) ;
case V_393 :
return F_211 ( V_161 , V_345 ) ;
default:
break;
}
return F_213 ( V_161 , V_391 , V_345 ) ;
}
static int F_214 ( struct V_365 * V_161 , int V_391 )
{
struct V_11 * V_11 = F_198 ( V_161 ) ;
struct V_365 * V_378 ;
int V_379 ;
if ( F_14 ( V_11 ) )
return - V_30 ;
if ( F_27 ( V_11 , 0 ) )
return - V_30 ;
F_215 ( & V_11 -> V_51 ) ;
V_379 = V_11 -> V_379 ;
switch ( V_391 ) {
case V_394 :
V_379 |= 1 << V_161 -> V_366 ;
break;
case V_395 :
V_379 &= ~ ( 1 << V_161 -> V_366 ) ;
break;
default:
F_216 () ;
F_217 ( & V_11 -> V_51 ) ;
return - V_121 ;
}
if ( V_161 -> V_366 == V_364 )
V_378 = V_11 -> V_359 ;
else
V_378 = V_11 -> V_363 ;
if ( V_378 ) {
struct V_365 * V_102 ;
F_206 (s, substream) {
if ( V_102 == V_378 ) {
F_218 ( V_102 , V_161 ) ;
if ( V_391 == V_394 )
V_379 |= 1 << V_102 -> V_366 ;
else
V_379 &= ~ ( 1 << V_102 -> V_366 ) ;
goto V_396;
}
}
if ( V_391 == V_394 ) {
if ( ! ( V_379 & ( 1 << V_364 ) ) &&
V_161 -> V_366 == V_362 )
F_42 ( V_11 ) ;
} else {
if ( V_379 &&
V_161 -> V_366 == V_364 )
F_42 ( V_11 ) ;
}
} else {
if ( V_161 -> V_366 == V_362 )
F_42 ( V_11 ) ;
}
V_396:
F_218 ( V_161 , V_161 ) ;
if ( ! V_11 -> V_379 && V_379 )
F_40 ( V_11 ) ;
else if ( V_11 -> V_379 && ! V_379 )
F_41 ( V_11 ) ;
V_11 -> V_379 = V_379 ;
F_217 ( & V_11 -> V_51 ) ;
return 0 ;
}
static int F_219 ( struct V_365 * V_161 )
{
struct V_11 * V_11 = F_198 ( V_161 ) ;
int V_397 = 0 ;
if ( F_14 ( V_11 ) )
return - V_30 ;
if ( F_27 ( V_11 , 1 ) )
return - V_30 ;
F_44 ( & V_11 -> V_51 ) ;
if ( ! V_11 -> V_379 )
F_39 ( V_11 ) ;
F_46 ( & V_11 -> V_51 ) ;
return V_397 ;
}
static int F_220 ( struct V_382 * V_383 ,
struct V_398 * V_399 )
{
struct V_11 * V_11 = V_399 -> V_400 ;
struct V_401 * V_402 = F_221 ( V_383 , V_403 ) ;
if ( V_11 -> V_14 == V_19 ) {
unsigned int V_404 [ 3 ] ;
V_404 [ 0 ] = V_11 -> V_405 ;
V_404 [ 1 ] = V_11 -> V_406 ;
V_404 [ 2 ] = V_11 -> V_407 ;
return F_222 ( V_402 , 3 , V_404 , 0 ) ;
} else {
unsigned int V_404 [ 2 ] ;
V_404 [ 0 ] = V_11 -> V_406 ;
V_404 [ 1 ] = V_11 -> V_407 ;
return F_222 ( V_402 , 2 , V_404 , 0 ) ;
}
}
static int F_223 ( struct V_382 * V_383 ,
struct V_398 * V_399 )
{
unsigned int V_404 [ 3 ] ;
struct V_11 * V_11 = V_399 -> V_400 ;
struct V_401 * V_402 = F_221 ( V_383 , V_403 ) ;
if ( V_11 -> V_14 == V_19 ) {
V_404 [ 0 ] = V_11 -> V_408 ;
V_404 [ 1 ] = V_11 -> V_409 ;
V_404 [ 2 ] = V_11 -> V_410 ;
return F_222 ( V_402 , 3 , V_404 , 0 ) ;
} else {
V_404 [ 0 ] = V_11 -> V_409 ;
V_404 [ 1 ] = V_11 -> V_410 ;
}
return F_222 ( V_402 , 2 , V_404 , 0 ) ;
}
static int F_224 ( struct V_382 * V_383 ,
struct V_398 * V_399 )
{
struct V_11 * V_11 = V_399 -> V_400 ;
struct V_401 * V_402 = F_221 ( V_383 , V_403 ) ;
struct V_401 * V_411 = F_221 ( V_383 , V_386 ) ;
if ( V_411 -> V_269 > 96000 && V_11 -> V_14 == V_19 ) {
struct V_401 V_412 = {
. V_269 = V_11 -> V_405 ,
. V_253 = V_11 -> V_405 ,
. integer = 1 ,
} ;
return F_225 ( V_402 , & V_412 ) ;
} else if ( V_411 -> V_269 > 48000 && V_411 -> V_253 <= 96000 ) {
struct V_401 V_412 = {
. V_269 = V_11 -> V_406 ,
. V_253 = V_11 -> V_406 ,
. integer = 1 ,
} ;
return F_225 ( V_402 , & V_412 ) ;
} else if ( V_411 -> V_253 < 64000 ) {
struct V_401 V_412 = {
. V_269 = V_11 -> V_407 ,
. V_253 = V_11 -> V_407 ,
. integer = 1 ,
} ;
return F_225 ( V_402 , & V_412 ) ;
}
return 0 ;
}
static int F_226 ( struct V_382 * V_383 ,
struct V_398 * V_399 )
{
struct V_11 * V_11 = V_399 -> V_400 ;
struct V_401 * V_402 = F_221 ( V_383 , V_403 ) ;
struct V_401 * V_411 = F_221 ( V_383 , V_386 ) ;
if ( V_411 -> V_269 > 96000 && V_11 -> V_14 == V_19 ) {
struct V_401 V_412 = {
. V_269 = V_11 -> V_408 ,
. V_253 = V_11 -> V_408 ,
. integer = 1 ,
} ;
return F_225 ( V_402 , & V_412 ) ;
} else if ( V_411 -> V_269 > 48000 && V_411 -> V_253 <= 96000 ) {
struct V_401 V_412 = {
. V_269 = V_11 -> V_409 ,
. V_253 = V_11 -> V_409 ,
. integer = 1 ,
} ;
return F_225 ( V_402 , & V_412 ) ;
} else if ( V_411 -> V_253 < 64000 ) {
struct V_401 V_412 = {
. V_269 = V_11 -> V_410 ,
. V_253 = V_11 -> V_410 ,
. integer = 1 ,
} ;
return F_225 ( V_402 , & V_412 ) ;
}
return 0 ;
}
static int F_227 ( struct V_382 * V_383 ,
struct V_398 * V_399 )
{
struct V_11 * V_11 = V_399 -> V_400 ;
struct V_401 * V_402 = F_221 ( V_383 , V_403 ) ;
struct V_401 * V_411 = F_221 ( V_383 , V_386 ) ;
if ( V_402 -> V_269 >= V_11 -> V_410 ) {
struct V_401 V_412 = {
. V_269 = 32000 ,
. V_253 = 48000 ,
. integer = 1 ,
} ;
return F_225 ( V_411 , & V_412 ) ;
} else if ( V_402 -> V_253 <= V_11 -> V_408 && V_11 -> V_14 == V_19 ) {
struct V_401 V_412 = {
. V_269 = 128000 ,
. V_253 = 192000 ,
. integer = 1 ,
} ;
return F_225 ( V_411 , & V_412 ) ;
} else if ( V_402 -> V_253 <= V_11 -> V_409 ) {
struct V_401 V_412 = {
. V_269 = 64000 ,
. V_253 = 96000 ,
. integer = 1 ,
} ;
return F_225 ( V_411 , & V_412 ) ;
}
return 0 ;
}
static int F_228 ( struct V_382 * V_383 ,
struct V_398 * V_399 )
{
struct V_11 * V_11 = V_399 -> V_400 ;
struct V_401 * V_402 = F_221 ( V_383 , V_403 ) ;
struct V_401 * V_411 = F_221 ( V_383 , V_386 ) ;
if ( V_402 -> V_269 >= V_11 -> V_407 ) {
struct V_401 V_412 = {
. V_269 = 32000 ,
. V_253 = 48000 ,
. integer = 1 ,
} ;
return F_225 ( V_411 , & V_412 ) ;
} else if ( V_402 -> V_253 <= V_11 -> V_405 && V_11 -> V_14 == V_19 ) {
struct V_401 V_412 = {
. V_269 = 128000 ,
. V_253 = 192000 ,
. integer = 1 ,
} ;
return F_225 ( V_411 , & V_412 ) ;
} else if ( V_402 -> V_253 <= V_11 -> V_406 ) {
struct V_401 V_412 = {
. V_269 = 64000 ,
. V_253 = 96000 ,
. integer = 1 ,
} ;
return F_225 ( V_411 , & V_412 ) ;
}
return 0 ;
}
static int F_229 ( struct V_365 * V_161 )
{
struct V_11 * V_11 = F_198 ( V_161 ) ;
struct V_376 * V_377 = V_161 -> V_377 ;
if ( F_14 ( V_11 ) )
return - V_30 ;
if ( F_27 ( V_11 , 1 ) )
return - V_30 ;
F_44 ( & V_11 -> V_51 ) ;
F_230 ( V_161 ) ;
V_377 -> V_413 = V_414 ;
V_377 -> V_415 = V_11 -> V_106 ;
V_377 -> V_416 = V_107 ;
V_11 -> V_68 = V_417 -> V_418 ;
V_11 -> V_363 = V_161 ;
F_46 ( & V_11 -> V_51 ) ;
F_231 ( V_377 , 0 , 32 , 24 ) ;
F_232 ( V_377 , 0 , V_387 , & V_419 ) ;
if ( V_11 -> V_226 ) {
V_377 -> V_413 . V_420 = V_377 -> V_413 . V_421 = V_11 -> V_120 ;
} else if ( V_11 -> V_14 == V_19 ) {
V_377 -> V_413 . V_421 = 192000 ;
V_377 -> V_413 . V_422 = V_423 ;
F_232 ( V_377 , 0 , V_386 , & V_424 ) ;
}
if ( V_11 -> V_14 == V_19 ) {
V_377 -> V_413 . V_425 = V_11 -> V_408 ;
V_377 -> V_413 . V_426 = V_11 -> V_410 ;
}
F_233 ( V_377 , 0 , V_403 ,
F_223 , V_11 ,
V_403 , - 1 ) ;
F_233 ( V_377 , 0 , V_403 ,
F_226 , V_11 ,
V_386 , - 1 ) ;
F_233 ( V_377 , 0 , V_386 ,
F_227 , V_11 ,
V_403 , - 1 ) ;
if ( V_17 != V_11 -> V_14 ) {
V_11 -> V_205 = V_11 -> V_203 ;
V_11 -> V_303 -> V_427 [ 0 ] . V_428 &= ~ V_429 ;
F_234 ( V_11 -> V_173 , V_430 |
V_431 , & V_11 -> V_303 -> V_140 ) ;
}
return 0 ;
}
static int F_235 ( struct V_365 * V_161 )
{
struct V_11 * V_11 = F_198 ( V_161 ) ;
F_44 ( & V_11 -> V_51 ) ;
V_11 -> V_68 = - 1 ;
V_11 -> V_363 = NULL ;
F_46 ( & V_11 -> V_51 ) ;
if ( V_17 != V_11 -> V_14 ) {
V_11 -> V_303 -> V_427 [ 0 ] . V_428 |= V_429 ;
F_234 ( V_11 -> V_173 , V_430 |
V_431 , & V_11 -> V_303 -> V_140 ) ;
}
return 0 ;
}
static int F_236 ( struct V_365 * V_161 )
{
struct V_11 * V_11 = F_198 ( V_161 ) ;
struct V_376 * V_377 = V_161 -> V_377 ;
if ( F_14 ( V_11 ) )
return - V_30 ;
if ( F_27 ( V_11 , 1 ) )
return - V_30 ;
F_44 ( & V_11 -> V_51 ) ;
F_230 ( V_161 ) ;
V_377 -> V_413 = V_432 ;
V_377 -> V_415 = V_11 -> V_318 ;
V_377 -> V_416 = V_107 ;
V_11 -> V_69 = V_417 -> V_418 ;
V_11 -> V_359 = V_161 ;
F_46 ( & V_11 -> V_51 ) ;
F_231 ( V_377 , 0 , 32 , 24 ) ;
F_232 ( V_377 , 0 , V_387 , & V_419 ) ;
if ( V_11 -> V_14 == V_19 ) {
V_377 -> V_413 . V_425 = V_11 -> V_405 ;
V_377 -> V_413 . V_426 = V_11 -> V_407 ;
V_377 -> V_413 . V_421 = 192000 ;
V_377 -> V_413 . V_422 = V_423 ;
F_232 ( V_377 , 0 , V_386 , & V_424 ) ;
}
F_233 ( V_377 , 0 , V_403 ,
F_220 , V_11 ,
V_403 , - 1 ) ;
F_233 ( V_377 , 0 , V_403 ,
F_224 , V_11 ,
V_386 , - 1 ) ;
F_233 ( V_377 , 0 , V_386 ,
F_228 , V_11 ,
V_403 , - 1 ) ;
return 0 ;
}
static int F_237 ( struct V_365 * V_161 )
{
struct V_11 * V_11 = F_198 ( V_161 ) ;
F_44 ( & V_11 -> V_51 ) ;
V_11 -> V_69 = - 1 ;
V_11 -> V_359 = NULL ;
F_46 ( & V_11 -> V_51 ) ;
return 0 ;
}
static inline int F_238 ( void T_6 * V_433 , void T_8 * V_371 )
{
T_2 V_22 = F_13 ( V_371 ) ;
return F_203 ( V_433 , & V_22 , 4 ) ;
}
static inline int F_239 ( void T_6 * V_433 , void T_8 * V_434 , void T_8 * V_435 )
{
T_2 V_436 , V_437 ;
T_4 V_438 ;
V_436 = F_13 ( V_434 ) ;
V_437 = F_13 ( V_435 ) ;
V_438 = ( ( T_4 ) V_437 << 32 ) | V_436 ;
return F_203 ( V_433 , & V_438 , 8 ) ;
}
static inline int F_240 ( void T_6 * V_433 , void T_8 * V_434 , void T_8 * V_435 )
{
T_2 V_436 , V_437 ;
T_4 V_438 ;
V_436 = F_13 ( V_434 ) & 0xffffff00 ;
V_437 = F_13 ( V_435 ) & 0xffffff00 ;
V_438 = ( ( T_4 ) V_437 << 32 ) | V_436 ;
return F_203 ( V_433 , & V_438 , 8 ) ;
}
static int F_241 ( struct V_11 * V_11 , struct V_439 T_6 * V_440 )
{
int V_441 = 0 ;
int V_24 , V_442 , V_443 , V_444 ;
if ( F_12 ( V_11 , V_25 ) & V_445 )
V_441 = 1 ;
V_443 = V_441 ? 14 : 26 ;
for ( V_24 = 0 , V_442 = 0 ; V_24 < 26 ; ++ V_24 ) {
if ( V_441 && ( V_24 & 4 ) )
continue;
V_444 = V_446 - V_442 * 4 ;
if ( F_238 ( & V_440 -> V_447 [ V_24 ] , V_11 -> V_23 + V_444 ) )
return - V_374 ;
V_444 -= V_443 * 4 ;
if ( F_238 ( & V_440 -> V_448 [ V_24 ] , V_11 -> V_23 + V_444 ) )
return - V_374 ;
V_444 -= V_443 * 4 ;
if ( F_238 ( & V_440 -> V_449 [ V_24 ] , V_11 -> V_23 + V_444 ) )
return - V_374 ;
V_444 = V_450 + V_442 * 8 ;
if ( F_240 ( & V_440 -> V_451 [ V_24 ] , V_11 -> V_23 + V_444 ,
V_11 -> V_23 + V_444 + 4 ) )
return - V_374 ;
V_444 += V_443 * 8 ;
if ( F_240 ( & V_440 -> V_452 [ V_24 ] , V_11 -> V_23 + V_444 ,
V_11 -> V_23 + V_444 + 4 ) )
return - V_374 ;
V_444 += V_443 * 8 ;
if ( F_240 ( & V_440 -> V_453 [ V_24 ] , V_11 -> V_23 + V_444 ,
V_11 -> V_23 + V_444 + 4 ) )
return - V_374 ;
V_442 ++ ;
}
return 0 ;
}
static int F_242 ( struct V_11 * V_11 , struct V_439 T_6 * V_440 )
{
int V_24 , V_442 ;
struct V_454 T_8 * V_455 ;
int V_441 = 0 ;
if ( F_12 ( V_11 , V_25 ) & V_445 )
V_441 = 1 ;
V_455 = (struct V_454 T_8 * ) ( V_11 -> V_23 + V_456 ) ;
for ( V_24 = 0 , V_442 = 0 ; V_24 < 16 ; ++ V_24 , ++ V_442 ) {
if ( F_238 ( & V_440 -> V_447 [ V_24 ] , & V_455 -> V_457 [ V_442 ] ) )
return - V_374 ;
if ( F_238 ( & V_440 -> V_448 [ V_24 ] , & V_455 -> V_458 [ V_442 ] ) )
return - V_374 ;
if ( F_238 ( & V_440 -> V_449 [ V_24 ] , & V_455 -> V_459 [ V_442 ] ) )
return - V_374 ;
if ( F_239 ( & V_440 -> V_451 [ V_24 ] , & V_455 -> V_460 [ V_442 ] ,
& V_455 -> V_461 [ V_442 ] ) )
return - V_374 ;
if ( F_239 ( & V_440 -> V_452 [ V_24 ] , & V_455 -> V_462 [ V_442 ] ,
& V_455 -> V_463 [ V_442 ] ) )
return - V_374 ;
if ( F_239 ( & V_440 -> V_453 [ V_24 ] , & V_455 -> V_464 [ V_442 ] ,
& V_455 -> V_465 [ V_442 ] ) )
return - V_374 ;
if ( V_441 && V_24 == 3 ) V_24 += 4 ;
}
return 0 ;
}
static int F_243 ( struct V_11 * V_11 , struct V_439 T_6 * V_440 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < 26 ; V_24 ++ ) {
if ( F_238 ( & V_440 -> V_448 [ V_24 ] ,
V_11 -> V_23 + V_466 + V_24 * 4 ) )
return - V_374 ;
if ( F_238 ( & V_440 -> V_447 [ V_24 ] ,
V_11 -> V_23 + V_467 + V_24 * 4 ) )
return - V_374 ;
}
for ( V_24 = 0 ; V_24 < 28 ; V_24 ++ ) {
if ( F_238 ( & V_440 -> V_449 [ V_24 ] ,
V_11 -> V_23 + V_468 + V_24 * 4 ) )
return - V_374 ;
}
for ( V_24 = 0 ; V_24 < 26 ; ++ V_24 ) {
if ( F_239 ( & V_440 -> V_452 [ V_24 ] ,
V_11 -> V_23 + V_469 + V_24 * 8 + 4 ,
V_11 -> V_23 + V_469 + V_24 * 8 ) )
return - V_374 ;
if ( F_239 ( & V_440 -> V_451 [ V_24 ] ,
V_11 -> V_23 + V_470 + V_24 * 8 + 4 ,
V_11 -> V_23 + V_470 + V_24 * 8 ) )
return - V_374 ;
}
return 0 ;
}
static int F_244 ( struct V_471 * V_413 , struct V_472 * V_472 , unsigned int V_391 , unsigned long V_345 )
{
struct V_11 * V_11 = V_413 -> V_165 ;
void T_6 * V_473 = ( void T_6 * ) V_345 ;
int V_299 ;
switch ( V_391 ) {
case V_474 : {
struct V_439 T_6 * V_440 = (struct V_439 T_6 * ) V_345 ;
V_299 = F_14 ( V_11 ) ;
if ( V_299 < 0 )
return V_299 ;
V_299 = F_27 ( V_11 , 1 ) ;
if ( V_299 < 0 )
return V_299 ;
if ( ! ( V_11 -> V_28 & V_29 ) ) {
F_17 ( V_27 L_176 ) ;
return - V_121 ;
}
switch ( V_11 -> V_14 ) {
case V_20 :
return F_241 ( V_11 , V_440 ) ;
case V_19 :
return F_242 ( V_11 , V_440 ) ;
default:
return F_243 ( V_11 , V_440 ) ;
}
}
case V_475 : {
struct V_476 V_389 ;
unsigned long V_33 ;
int V_24 ;
V_299 = F_14 ( V_11 ) ;
if ( V_299 < 0 )
return V_299 ;
V_299 = F_27 ( V_11 , 1 ) ;
if ( V_299 < 0 )
return V_299 ;
memset ( & V_389 , 0 , sizeof( V_389 ) ) ;
F_23 ( & V_11 -> V_51 , V_33 ) ;
V_389 . V_311 = ( unsigned char ) F_129 ( V_11 ) ;
V_389 . V_477 = ( unsigned char ) F_146 ( V_11 ) ;
if ( V_11 -> V_14 != V_19 )
V_389 . V_478 = ( unsigned char ) F_150 ( V_11 ) ;
V_389 . V_479 = ( unsigned char ) F_148 ( V_11 ) ;
for ( V_24 = 0 ; V_24 < ( ( V_11 -> V_14 != V_15 && V_11 -> V_14 != V_17 && V_11 -> V_14 != V_19 ) ? 3 : 1 ) ; ++ V_24 )
V_389 . V_480 [ V_24 ] = ( unsigned char ) F_152 ( V_11 , V_24 ) ;
V_389 . V_481 = ( unsigned char ) F_87 ( V_11 ) ;
V_389 . V_482 = ( unsigned char ) F_94 ( V_11 ,
V_329 ) ;
V_389 . V_483 = ( unsigned char )
F_94 ( V_11 , V_188 ) ;
V_389 . V_484 = ( unsigned char )
F_94 ( V_11 , V_192 ) ;
V_389 . V_485 = ( unsigned char )
F_94 ( V_11 , V_190 ) ;
V_389 . V_486 = F_33 ( V_11 ) ;
V_389 . V_120 = V_11 -> V_120 ;
V_389 . V_487 = F_34 ( V_11 ) ;
V_389 . V_313 = ( unsigned char ) F_104 ( V_11 ) ;
V_389 . V_314 = ( unsigned char ) F_107 ( V_11 ) ;
V_389 . V_312 = ( unsigned char ) F_35 ( V_11 ) ;
V_389 . V_488 = ( unsigned char )
F_94 ( V_11 , V_321 ) ;
if ( V_11 -> V_14 == V_19 ) {
V_389 . V_489 = ( unsigned char ) F_114 ( V_11 ) ;
V_389 . V_490 = ( unsigned char ) F_119 ( V_11 ) ;
V_389 . V_491 = ( unsigned char ) F_124 ( V_11 ) ;
V_389 . V_492 =
( unsigned char ) F_94 ( V_11 ,
V_335 ) ;
} else if ( V_11 -> V_14 == V_17 ) {
V_389 . V_489 = ( unsigned char ) F_159 ( V_11 ) ;
V_389 . V_490 = ( unsigned char ) F_164 ( V_11 ) ;
}
if ( V_11 -> V_14 == V_19 || V_11 -> V_14 == V_20 )
V_389 . V_493 =
( unsigned char ) F_94 ( V_11 ,
V_336 ) ;
F_25 ( & V_11 -> V_51 , V_33 ) ;
if ( F_203 ( V_473 , & V_389 , sizeof( V_389 ) ) )
return - V_374 ;
break;
}
case V_494 : {
struct V_495 V_496 ;
if ( V_11 -> V_14 != V_19 ) return - V_121 ;
V_496 . V_497 = V_11 -> V_407 - V_498 ;
V_496 . V_499 = V_11 -> V_410 - V_498 ;
if ( F_203 ( V_473 , & V_496 , sizeof( V_496 ) ) )
return - V_374 ;
break;
}
case V_500 : {
struct V_501 V_501 ;
int V_299 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) return - V_121 ;
if ( V_11 -> V_14 == V_502 ) {
if ( ( V_299 = F_26 ( V_11 ) ) < 0 )
return V_299 ;
}
memset ( & V_501 , 0 , sizeof( V_501 ) ) ;
V_501 . V_14 = V_11 -> V_14 ;
V_501 . V_18 = V_11 -> V_18 ;
if ( ( V_299 = F_203 ( V_473 , & V_501 , sizeof( V_501 ) ) ) )
return - V_374 ;
break;
}
case V_503 : {
struct V_504 T_6 * V_36 ;
T_2 T_6 * V_505 ;
int V_299 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 ) return - V_121 ;
if ( V_11 -> V_14 == V_502 ) return - V_121 ;
if ( V_11 -> V_28 & ( V_59 | V_29 ) )
return - V_131 ;
F_17 ( V_50 L_177 ) ;
V_36 = (struct V_504 T_6 * ) V_473 ;
if ( F_245 ( V_505 , & V_36 -> V_505 ) )
return - V_374 ;
if ( F_14 ( V_11 ) )
return - V_30 ;
if ( ! V_11 -> V_35 ) {
V_11 -> V_35 = F_246 ( V_46 ) ;
if ( ! V_11 -> V_35 )
return - V_9 ;
}
if ( F_201 ( V_11 -> V_35 , V_505 ,
V_46 ) ) {
F_247 ( V_11 -> V_35 ) ;
V_11 -> V_35 = NULL ;
return - V_374 ;
}
V_11 -> V_28 |= V_59 ;
if ( ( V_299 = F_19 ( V_11 ) ) < 0 )
return V_299 ;
if ( ! ( V_11 -> V_28 & V_49 ) ) {
if ( ( V_299 = F_248 ( V_11 ) ) < 0 )
return V_299 ;
F_249 ( V_11 ) ;
F_250 ( V_11 ) ;
if ( ( V_299 = F_251 ( V_11 -> V_173 , V_11 ) ) < 0 ) {
F_17 ( V_27 L_178 ) ;
return V_299 ;
}
}
break;
}
case V_506 : {
struct V_507 T_6 * V_508 = (struct V_507 T_6 * ) V_473 ;
if ( F_203 ( V_508 -> V_509 , V_11 -> V_65 , sizeof( unsigned short ) * V_64 ) )
return - V_374 ;
break;
}
default:
return - V_121 ;
}
return 0 ;
}
static int F_252 ( struct V_172 * V_173 , struct V_11 * V_11 )
{
struct V_471 * V_413 ;
int V_299 ;
if ( ( V_299 = F_253 ( V_173 , L_179 , 0 , & V_413 ) ) < 0 )
return V_299 ;
V_11 -> V_510 = V_413 ;
V_413 -> V_165 = V_11 ;
strcpy ( V_413 -> V_176 , L_180 ) ;
V_413 -> V_511 . V_512 = F_244 ;
V_413 -> V_511 . V_513 = F_244 ;
return 0 ;
}
static int F_254 ( struct V_172 * V_173 , struct V_11 * V_11 )
{
struct V_514 * V_360 ;
int V_299 ;
if ( ( V_299 = F_255 ( V_173 , V_11 -> V_316 , 0 , 1 , 1 , & V_360 ) ) < 0 )
return V_299 ;
V_11 -> V_360 = V_360 ;
V_360 -> V_165 = V_11 ;
strcpy ( V_360 -> V_176 , V_11 -> V_316 ) ;
F_256 ( V_360 , V_364 , & V_515 ) ;
F_256 ( V_360 , V_362 , & V_516 ) ;
V_360 -> V_181 = V_517 ;
return 0 ;
}
static void F_192 ( struct V_11 * V_11 )
{
V_11 -> V_47 |= V_518 ;
F_10 ( V_11 , V_40 , V_11 -> V_47 ) ;
}
static int F_248 ( struct V_11 * V_11 )
{
int V_24 ;
if ( F_20 ( V_11 , 0 , 100 ) ) {
F_17 ( V_27 L_181 ) ;
return - V_30 ;
}
for ( V_24 = 0 ; V_24 < V_11 -> V_273 ; ++ V_24 ) {
F_10 ( V_11 , V_519 + ( 4 * V_24 ) , 1 ) ;
F_10 ( V_11 , V_520 + ( 4 * V_24 ) , 1 ) ;
}
return 0 ;
}
static void F_249 ( struct V_11 * V_11 )
{
int V_70 , V_521 , V_522 ;
switch ( V_11 -> V_14 ) {
case V_16 :
V_11 -> V_316 = L_182 ;
V_11 -> V_407 = V_11 -> V_410 = V_523 ;
V_11 -> V_406 = V_11 -> V_409 = V_524 ;
break;
case V_20 :
V_11 -> V_316 = L_183 ;
V_11 -> V_407 = V_11 -> V_410 = V_525 ;
V_11 -> V_406 = V_11 -> V_409 = V_526 ;
break;
case V_19 :
V_70 = F_12 ( V_11 , V_25 ) ;
V_521 = ( V_70 & V_527 ) ? 0 : 4 ;
V_522 = ( V_70 & V_528 ) ? 0 : 4 ;
V_11 -> V_316 = L_184 ;
V_11 -> V_407 = V_498 + V_521 ;
V_11 -> V_406 = V_529 + V_521 ;
V_11 -> V_405 = V_530 + V_521 ;
V_11 -> V_410 = V_498 + V_522 ;
V_11 -> V_409 = V_529 + V_522 ;
V_11 -> V_408 = V_530 + V_522 ;
break;
case V_15 :
V_11 -> V_316 = L_185 ;
V_11 -> V_407 = V_11 -> V_410 = V_531 ;
V_11 -> V_406 = V_11 -> V_409 = V_532 ;
break;
case V_17 :
V_11 -> V_316 = L_186 ;
V_11 -> V_407 = V_533 - 1 ;
V_11 -> V_410 = V_533 ;
V_11 -> V_406 = V_533 - 1 ;
V_11 -> V_409 = V_533 ;
break;
default:
break;
}
}
static void F_250 ( struct V_11 * V_11 )
{
F_55 ( V_11 , 0 ) ;
F_55 ( V_11 , 1 ) ;
}
static int F_251 ( struct V_172 * V_173 , struct V_11 * V_11 )
{
int V_299 ;
if ( ( V_299 = F_254 ( V_173 , V_11 ) ) < 0 ) {
F_17 ( V_27 L_187 ) ;
return V_299 ;
}
if ( ( V_299 = F_72 ( V_173 , V_11 , 0 ) ) < 0 ) {
F_17 ( V_27 L_188 ) ;
return V_299 ;
}
if ( V_11 -> V_14 == V_16 || V_11 -> V_14 == V_20 ) {
if ( ( V_299 = F_72 ( V_173 , V_11 , 1 ) ) < 0 ) {
F_17 ( V_27 L_189 ) ;
return V_299 ;
}
}
if ( ( V_299 = F_178 ( V_173 , V_11 ) ) < 0 ) {
F_17 ( V_27 L_190 ) ;
return V_299 ;
}
F_184 ( V_11 ) ;
V_11 -> V_120 = - 1 ;
V_11 -> V_68 = - 1 ;
V_11 -> V_69 = - 1 ;
V_11 -> V_359 = NULL ;
V_11 -> V_363 = NULL ;
if ( ( V_299 = F_24 ( V_11 ) ) < 0 ) {
F_17 ( V_27 L_191 ) ;
return V_299 ;
}
if ( ! ( V_11 -> V_28 & V_49 ) ) {
strcpy ( V_173 -> V_175 , L_192 ) ;
sprintf ( V_173 -> V_534 , L_193 , V_11 -> V_316 ,
V_11 -> V_320 , V_11 -> V_319 ) ;
if ( ( V_299 = F_257 ( V_173 ) ) < 0 ) {
F_17 ( V_27 L_194 ) ;
return V_299 ;
}
V_11 -> V_28 |= V_49 ;
}
return 0 ;
}
static int F_28 ( struct V_11 * V_11 )
{
const char * V_535 ;
const struct V_36 * V_536 ;
int V_299 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 )
return 0 ;
if ( V_11 -> V_14 == V_502 ) {
if ( ( V_299 = F_26 ( V_11 ) ) < 0 )
return V_299 ;
if ( V_11 -> V_14 == V_20 || V_11 -> V_14 == V_19 )
return 0 ;
}
switch ( V_11 -> V_14 ) {
case V_17 :
V_535 = L_195 ;
break;
case V_15 :
if ( V_11 -> V_18 == 0xa )
V_535 = L_196 ;
else
V_535 = L_197 ;
break;
case V_16 :
if ( V_11 -> V_18 == 0xa )
V_535 = L_198 ;
else
V_535 = L_199 ;
break;
default:
F_17 ( V_27 L_200 , V_11 -> V_14 ) ;
return - V_121 ;
}
if ( F_258 ( & V_536 , V_535 , & V_11 -> V_2 -> V_6 ) ) {
F_17 ( V_27 L_201 , V_535 ) ;
return - V_537 ;
}
if ( V_536 -> V_5 < V_46 ) {
F_17 ( V_27 L_202 ,
( int ) V_536 -> V_5 , V_46 ) ;
return - V_121 ;
}
V_11 -> V_36 = V_536 ;
V_11 -> V_28 |= V_59 ;
if ( ( V_299 = F_19 ( V_11 ) ) < 0 )
return V_299 ;
if ( ! ( V_11 -> V_28 & V_49 ) ) {
if ( ( V_299 = F_248 ( V_11 ) ) < 0 )
return V_299 ;
if ( ( V_299 = F_252 ( V_11 -> V_173 , V_11 ) ) < 0 ) {
F_17 ( V_27 L_203 ) ;
return V_299 ;
}
F_249 ( V_11 ) ;
F_250 ( V_11 ) ;
if ( ( V_299 = F_251 ( V_11 -> V_173 , V_11 ) ) < 0 ) {
F_17 ( V_27 L_178 ) ;
return V_299 ;
}
}
return 0 ;
}
static int F_259 ( struct V_172 * V_173 ,
struct V_11 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_299 ;
int V_538 = 0 ;
int V_539 = 0 ;
V_11 -> V_319 = - 1 ;
V_11 -> V_28 = 0 ;
V_11 -> V_174 [ 0 ] . V_164 = NULL ;
V_11 -> V_174 [ 1 ] . V_164 = NULL ;
V_11 -> V_174 [ 0 ] . V_156 = NULL ;
V_11 -> V_174 [ 1 ] . V_156 = NULL ;
V_11 -> V_174 [ 0 ] . V_155 = NULL ;
V_11 -> V_174 [ 1 ] . V_155 = NULL ;
V_11 -> V_174 [ 0 ] . V_157 = 0 ;
V_11 -> V_174 [ 1 ] . V_157 = 0 ;
F_73 ( & V_11 -> V_174 [ 0 ] . V_51 ) ;
F_73 ( & V_11 -> V_174 [ 1 ] . V_51 ) ;
V_11 -> V_23 = NULL ;
V_11 -> V_94 = 0 ;
V_11 -> V_47 = 0 ;
V_11 -> V_14 = V_502 ;
V_11 -> V_273 = 26 ;
V_11 -> V_173 = V_173 ;
F_73 ( & V_11 -> V_51 ) ;
F_260 ( & V_11 -> V_166 , F_193 , ( unsigned long ) V_11 ) ;
F_261 ( V_11 -> V_2 , V_540 , & V_11 -> V_18 ) ;
V_11 -> V_18 &= 0xff ;
F_262 ( V_11 -> V_2 , V_541 , 0xFF ) ;
strcpy ( V_173 -> V_542 , L_204 ) ;
strcpy ( V_173 -> V_543 , L_205 ) ;
if ( V_11 -> V_18 < 0xa )
return - V_37 ;
else if ( V_11 -> V_18 < 0x64 )
V_11 -> V_316 = L_206 ;
else if ( V_11 -> V_18 < 0x96 ) {
V_11 -> V_316 = L_207 ;
V_538 = 1 ;
} else {
V_11 -> V_316 = L_208 ;
V_11 -> V_273 = 16 ;
V_539 = 1 ;
}
if ( ( V_299 = F_263 ( V_2 ) ) < 0 )
return V_299 ;
F_264 ( V_11 -> V_2 ) ;
if ( ( V_299 = F_265 ( V_2 , L_174 ) ) < 0 )
return V_299 ;
V_11 -> V_320 = F_266 ( V_2 , 0 ) ;
if ( ( V_11 -> V_23 = F_267 ( V_11 -> V_320 , V_544 ) ) == NULL ) {
F_17 ( V_27 L_209 , V_11 -> V_320 , V_11 -> V_320 + V_544 - 1 ) ;
return - V_131 ;
}
if ( F_268 ( V_2 -> V_319 , F_194 , V_545 ,
V_546 , V_11 ) ) {
F_17 ( V_27 L_210 , V_2 -> V_319 ) ;
return - V_131 ;
}
V_11 -> V_319 = V_2 -> V_319 ;
V_11 -> V_96 = 0 ;
V_11 -> V_268 = 1 ;
V_11 -> V_101 = 0 ;
if ( ( V_299 = F_188 ( V_11 ) ) < 0 )
return V_299 ;
if ( ! V_538 && ! V_539 ) {
V_299 = F_18 ( V_11 , 1000 , 10 ) ;
if ( V_299 < 0 )
return V_299 ;
if ( ( F_12 ( V_11 , V_25 ) & V_39 ) != 0 ) {
if ( ( V_299 = F_28 ( V_11 ) ) < 0 )
F_17 ( V_27 L_211 ) ;
else
return 0 ;
F_17 ( V_50 L_212 ) ;
if ( ( V_299 = F_252 ( V_173 , V_11 ) ) < 0 )
return V_299 ;
return 0 ;
} else {
F_17 ( V_50 L_213 ) ;
if ( F_12 ( V_11 , V_55 ) & V_56 )
V_11 -> V_14 = V_17 ;
else if ( F_12 ( V_11 , V_55 ) & V_57 )
V_11 -> V_14 = V_15 ;
else
V_11 -> V_14 = V_16 ;
}
}
if ( ( V_299 = F_248 ( V_11 ) ) != 0 )
return V_299 ;
if ( V_538 )
V_11 -> V_14 = V_20 ;
if ( V_539 )
V_11 -> V_14 = V_19 ;
if ( ( V_299 = F_252 ( V_173 , V_11 ) ) < 0 )
return V_299 ;
F_249 ( V_11 ) ;
F_250 ( V_11 ) ;
V_11 -> V_28 |= V_29 ;
if ( ( V_299 = F_251 ( V_173 , V_11 ) ) < 0 )
return V_299 ;
return 0 ;
}
static int F_269 ( struct V_11 * V_11 )
{
if ( V_11 -> V_320 ) {
F_62 ( & V_11 -> V_166 ) ;
V_11 -> V_94 &= ~ ( V_104 | V_103 | V_159 | V_158 ) ;
F_10 ( V_11 , V_105 , V_11 -> V_94 ) ;
}
if ( V_11 -> V_319 >= 0 )
F_270 ( V_11 -> V_319 , ( void * ) V_11 ) ;
F_187 ( V_11 ) ;
if ( V_11 -> V_36 )
F_271 ( V_11 -> V_36 ) ;
F_247 ( V_11 -> V_35 ) ;
if ( V_11 -> V_23 )
F_272 ( V_11 -> V_23 ) ;
if ( V_11 -> V_320 )
F_273 ( V_11 -> V_2 ) ;
F_274 ( V_11 -> V_2 ) ;
return 0 ;
}
static void F_275 ( struct V_172 * V_173 )
{
struct V_11 * V_11 = V_173 -> V_165 ;
if ( V_11 )
F_269 ( V_11 ) ;
}
static int F_276 ( struct V_1 * V_2 ,
const struct V_547 * V_548 )
{
static int V_6 ;
struct V_11 * V_11 ;
struct V_172 * V_173 ;
int V_299 ;
if ( V_6 >= V_549 )
return - V_37 ;
if ( ! V_550 [ V_6 ] ) {
V_6 ++ ;
return - V_537 ;
}
V_299 = F_277 ( V_284 [ V_6 ] , V_140 [ V_6 ] , V_551 ,
sizeof( struct V_11 ) , & V_173 ) ;
if ( V_299 < 0 )
return V_299 ;
V_11 = V_173 -> V_165 ;
V_173 -> V_552 = F_275 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_2 = V_2 ;
F_278 ( V_173 , & V_2 -> V_6 ) ;
if ( ( V_299 = F_259 ( V_173 , V_11 ) ) < 0 ) {
F_279 ( V_173 ) ;
return V_299 ;
}
strcpy ( V_173 -> V_175 , L_192 ) ;
sprintf ( V_173 -> V_534 , L_193 , V_11 -> V_316 ,
V_11 -> V_320 , V_11 -> V_319 ) ;
if ( ( V_299 = F_257 ( V_173 ) ) < 0 ) {
F_279 ( V_173 ) ;
return V_299 ;
}
F_280 ( V_2 , V_173 ) ;
V_6 ++ ;
return 0 ;
}
static void F_281 ( struct V_1 * V_2 )
{
F_279 ( F_282 ( V_2 ) ) ;
}
