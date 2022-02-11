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
F_13 ( V_10 -> V_26 -> V_6 ,
L_1 ,
( 20 * V_23 ) ) ;
}
return 0 ;
}
F_14 ( 20 ) ;
}
F_15 ( V_10 -> V_26 -> V_6 , L_2 ) ;
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
F_13 ( V_10 -> V_26 -> V_6 , L_3 ,
V_23 * V_31 ) ;
return 0 ;
}
}
F_17 ( V_10 -> V_26 -> V_6 , L_2 ) ;
V_10 -> V_27 &= ~ V_28 ;
return - V_29 ;
}
static int F_18 ( struct V_10 * V_10 ) {
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
F_17 ( V_10 -> V_26 -> V_6 , L_4 ) ;
F_8 ( V_10 , V_39 , V_40 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_19 ( V_10 , 0 , V_42 ) ) {
F_17 ( V_10 -> V_26 -> V_6 ,
L_5 ) ;
F_8 ( V_10 , V_39 , V_43 ) ;
return - V_29 ;
}
F_8 ( V_10 , V_39 , V_44 ) ;
for ( V_23 = 0 ; V_23 < V_45 / 4 ; ++ V_23 ) {
F_8 ( V_10 , V_41 , V_33 [ V_23 ] ) ;
if ( F_19 ( V_10 , 127 , V_42 ) ) {
F_17 ( V_10 -> V_26 -> V_6 ,
L_6 ) ;
F_8 ( V_10 , V_39 , V_43 ) ;
return - V_29 ;
}
}
F_19 ( V_10 , 3 , V_42 ) ;
F_8 ( V_10 , V_39 , V_43 ) ;
F_20 ( 3 ) ;
#ifdef F_21
V_10 -> V_46 = V_47 ;
#else
V_10 -> V_46 = 0 ;
#endif
F_8 ( V_10 , V_39 , V_10 -> V_46 ) ;
F_17 ( V_10 -> V_26 -> V_6 , L_7 ) ;
}
if ( V_10 -> V_27 & V_48 ) {
F_17 ( V_10 -> V_26 -> V_6 ,
L_8 ) ;
F_22 ( & V_10 -> V_49 , V_32 ) ;
F_23 ( V_10 ) ;
F_24 ( & V_10 -> V_49 , V_32 ) ;
}
V_10 -> V_27 |= V_28 ;
return 0 ;
}
static int F_25 ( struct V_10 * V_10 )
{
if ( ( F_10 ( V_10 , V_24 ) & V_38 ) != 0 ) {
F_8 ( V_10 , V_39 , V_44 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_19 ( V_10 , 0 , V_50 ) < 0 ) {
F_8 ( V_10 , V_39 , V_51 ) ;
F_8 ( V_10 , V_39 , V_44 ) ;
}
F_8 ( V_10 , V_39 , V_43 | V_52 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_19 ( V_10 , 0 , V_50 ) < 0 )
goto V_53;
F_8 ( V_10 , V_39 , V_44 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_19 ( V_10 , 0 , V_50 ) == 0 ) {
V_10 -> V_13 = V_15 ;
F_17 ( V_10 -> V_26 -> V_6 , L_9 ) ;
return 0 ;
}
F_8 ( V_10 , V_39 , V_51 ) ;
F_8 ( V_10 , V_39 , V_44 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_19 ( V_10 , 0 , V_50 ) == 0 )
goto V_53;
F_8 ( V_10 , V_39 , V_51 ) ;
F_8 ( V_10 , V_39 , V_44 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_19 ( V_10 , 0 , V_50 ) < 0 )
goto V_53;
V_10 -> V_13 = V_16 ;
F_17 ( V_10 -> V_26 -> V_6 , L_10 ) ;
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
V_53:
V_10 -> V_13 = V_14 ;
F_17 ( V_10 -> V_26 -> V_6 , L_11 ) ;
return 0 ;
}
static int F_26 ( struct V_10 * V_10 , int V_57 )
{
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
if ( ( F_10 ( V_10 , V_24 ) & V_38 ) != 0 ) {
V_10 -> V_27 &= ~ V_28 ;
if ( ! V_57 )
return - V_29 ;
F_15 ( V_10 -> V_26 -> V_6 , L_12 ) ;
if ( ! ( V_10 -> V_27 & V_58 ) ) {
if ( ! F_27 ( V_10 ) )
return 0 ;
F_15 ( V_10 -> V_26 -> V_6 ,
L_13 ) ;
return - V_29 ;
}
if ( F_18 ( V_10 ) != 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_14 ) ;
return - V_29 ;
}
}
return 0 ;
}
static int F_19 ( struct V_10 * V_10 , int V_59 , int V_60 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_60 ; V_23 ++ ) {
if ( ( int ) ( F_10 ( V_10 , V_61 ) & 0xff ) <= V_59 )
return 0 ;
F_28 ( 100 ) ;
}
F_29 ( V_10 -> V_26 -> V_6 ,
L_15 ,
V_59 , V_60 ) ;
return - 1 ;
}
static int F_30 ( struct V_10 * V_10 , unsigned int V_62 )
{
if ( V_62 >= V_63 )
return 0 ;
return V_10 -> V_64 [ V_62 ] ;
}
static int F_31 ( struct V_10 * V_10 , unsigned int V_62 , unsigned short V_37 )
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
if ( F_19 ( V_10 , 127 , V_42 ) )
return - 1 ;
F_8 ( V_10 , V_41 , V_65 ) ;
V_10 -> V_64 [ V_62 ] = V_37 ;
}
return 0 ;
}
static int F_32 ( struct V_10 * V_10 )
{
unsigned long V_32 ;
int V_66 = 1 ;
F_22 ( & V_10 -> V_49 , V_32 ) ;
if ( ( V_10 -> V_67 != V_10 -> V_68 ) &&
( V_10 -> V_67 >= 0 ) && ( V_10 -> V_68 >= 0 ) )
V_66 = 0 ;
F_24 ( & V_10 -> V_49 , V_32 ) ;
return V_66 ;
}
static int F_33 ( struct V_10 * V_10 )
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
F_29 ( V_10 -> V_26 -> V_6 ,
L_16 ,
V_70 , V_69 ) ;
return 0 ;
}
static int F_34 ( struct V_10 * V_10 )
{
unsigned int V_83 = F_10 ( V_10 , V_54 ) ;
unsigned int V_70 = V_83 & V_84 ;
if ( V_10 -> V_13 == V_18 &&
F_35 ( V_10 ) == V_85 )
return F_33 ( V_10 ) ;
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
static void F_36 ( struct V_10 * V_10 )
{
V_10 -> V_92 = 1 << ( ( F_37 ( V_10 -> V_93 ) + 8 ) ) ;
}
static T_3 F_38 ( struct V_10 * V_10 )
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
static void F_39 ( struct V_10 * V_10 )
{
F_8 ( V_10 , V_98 , 0 ) ;
if ( V_10 -> V_13 == V_18 && V_10 -> V_17 >= 152 )
F_8 ( V_10 , V_99 , V_10 -> V_100 ) ;
}
static void F_40 ( struct V_10 * V_101 )
{
V_101 -> V_93 |= ( V_102 | V_103 ) ;
F_8 ( V_101 , V_104 , V_101 -> V_93 ) ;
}
static void F_41 ( struct V_10 * V_101 )
{
V_101 -> V_93 &= ~ ( V_103 | V_102 ) ;
F_8 ( V_101 , V_104 , V_101 -> V_93 ) ;
}
static void F_42 ( struct V_10 * V_10 )
{
memset ( V_10 -> V_105 , 0 , V_106 ) ;
}
static int F_43 ( struct V_10 * V_101 , unsigned int V_107 )
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
F_8 ( V_101 , V_104 , V_101 -> V_93 ) ;
F_36 ( V_101 ) ;
F_46 ( & V_101 -> V_49 ) ;
return 0 ;
}
static void F_47 ( struct V_10 * V_10 , int V_110 )
{
T_4 V_108 ;
if ( V_110 >= 112000 )
V_110 /= 4 ;
else if ( V_110 >= 56000 )
V_110 /= 2 ;
V_108 = V_111 ;
V_108 = F_48 ( V_108 , V_110 ) ;
F_49 ( V_108 >> 32 ) ;
V_10 -> V_100 = V_108 ;
F_8 ( V_10 , V_99 , V_10 -> V_100 ) ;
}
static int F_50 ( struct V_10 * V_10 , int V_110 , int V_112 )
{
int V_113 = 0 ;
int V_114 ;
int V_70 ;
if ( ! ( V_10 -> V_93 & V_115 ) ) {
if ( V_112 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_17 ) ;
return - 1 ;
} else {
int V_116 = F_34 ( V_10 ) ;
int V_117 = F_33 ( V_10 ) ;
if ( ( V_117 == V_116 * 2 ) && ( F_35 ( V_10 ) >= V_118 ) )
F_17 ( V_10 -> V_26 -> V_6 ,
L_18 ) ;
else if ( V_10 -> V_13 == V_18 && ( V_117 == V_116 * 4 ) && ( F_35 ( V_10 ) >= V_118 ) )
F_17 ( V_10 -> V_26 -> V_6 ,
L_19 ) ;
else if ( V_110 != V_116 ) {
F_17 ( V_10 -> V_26 -> V_6 ,
L_20 ) ;
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
F_29 ( V_10 -> V_26 -> V_6 ,
L_21 ,
V_10 -> V_68 ,
V_10 -> V_67 ) ;
return - V_130 ;
}
V_10 -> V_93 &= ~ V_131 ;
V_10 -> V_93 |= V_70 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
if ( V_10 -> V_13 == V_18 && V_10 -> V_17 >= 152 )
F_47 ( V_10 , V_110 ) ;
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
static unsigned char F_51 ( struct V_10 * V_10 , int V_139 )
{
if ( V_139 )
return F_10 ( V_10 , V_140 ) ;
else
return F_10 ( V_10 , V_141 ) ;
}
static void F_52 ( struct V_10 * V_10 , int V_139 , int V_21 )
{
if ( V_139 )
F_8 ( V_10 , V_142 , V_21 ) ;
else
F_8 ( V_10 , V_143 , V_21 ) ;
}
static int F_53 ( struct V_10 * V_10 , int V_139 )
{
if ( V_139 )
return ( F_10 ( V_10 , V_144 ) & 0xff ) ;
else
return ( F_10 ( V_10 , V_145 ) & 0xff ) ;
}
static int F_54 ( struct V_10 * V_10 , int V_139 )
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
static void F_55 ( struct V_10 * V_10 , int V_139 )
{
while ( F_53 ( V_10 , V_139 ) )
F_51 ( V_10 , V_139 ) ;
}
static int F_56 ( struct V_149 * V_150 )
{
unsigned long V_32 ;
int V_151 ;
int V_152 ;
int V_23 ;
unsigned char V_153 [ 128 ] ;
F_22 ( & V_150 -> V_49 , V_32 ) ;
if ( V_150 -> V_154 ) {
if ( ! F_57 ( V_150 -> V_154 ) ) {
if ( ( V_151 = F_54 ( V_150 -> V_10 , V_150 -> V_139 ) ) > 0 ) {
if ( V_151 > ( int ) sizeof ( V_153 ) )
V_151 = sizeof ( V_153 ) ;
if ( ( V_152 = F_58 ( V_150 -> V_154 , V_153 , V_151 ) ) > 0 ) {
for ( V_23 = 0 ; V_23 < V_152 ; ++ V_23 )
F_52 ( V_150 -> V_10 , V_150 -> V_139 , V_153 [ V_23 ] ) ;
}
}
}
}
F_24 ( & V_150 -> V_49 , V_32 ) ;
return 0 ;
}
static int F_59 ( struct V_149 * V_150 )
{
unsigned char V_153 [ 128 ] ;
unsigned long V_32 ;
int V_151 ;
int V_23 ;
F_22 ( & V_150 -> V_49 , V_32 ) ;
if ( ( V_151 = F_53 ( V_150 -> V_10 , V_150 -> V_139 ) ) > 0 ) {
if ( V_150 -> V_155 ) {
if ( V_151 > ( int ) sizeof ( V_153 ) )
V_151 = sizeof ( V_153 ) ;
for ( V_23 = 0 ; V_23 < V_151 ; ++ V_23 )
V_153 [ V_23 ] = F_51 ( V_150 -> V_10 , V_150 -> V_139 ) ;
if ( V_151 )
F_60 ( V_150 -> V_155 , V_153 , V_151 ) ;
} else {
while ( -- V_151 )
F_51 ( V_150 -> V_10 , V_150 -> V_139 ) ;
}
}
V_150 -> V_156 = 0 ;
if ( V_150 -> V_139 )
V_150 -> V_10 -> V_93 |= V_157 ;
else
V_150 -> V_10 -> V_93 |= V_158 ;
F_8 ( V_150 -> V_10 , V_104 , V_150 -> V_10 -> V_93 ) ;
F_24 ( & V_150 -> V_49 , V_32 ) ;
return F_56 ( V_150 ) ;
}
static void F_61 ( struct V_159 * V_160 , int V_161 )
{
struct V_10 * V_10 ;
struct V_149 * V_150 ;
unsigned long V_32 ;
T_2 V_162 ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
V_10 = V_150 -> V_10 ;
V_162 = V_150 -> V_139 ? V_157 : V_158 ;
F_22 ( & V_10 -> V_49 , V_32 ) ;
if ( V_161 ) {
if ( ! ( V_10 -> V_93 & V_162 ) ) {
F_55 ( V_10 , V_150 -> V_139 ) ;
V_10 -> V_93 |= V_162 ;
}
} else {
V_10 -> V_93 &= ~ V_162 ;
F_62 ( & V_10 -> V_165 ) ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
F_24 ( & V_10 -> V_49 , V_32 ) ;
}
static void F_63 ( unsigned long V_37 )
{
struct V_149 * V_150 = (struct V_149 * ) V_37 ;
unsigned long V_32 ;
F_56 ( V_150 ) ;
F_22 ( & V_150 -> V_49 , V_32 ) ;
if ( V_150 -> V_166 )
F_64 ( & V_150 -> V_167 , 1 + V_168 ) ;
F_24 ( & V_150 -> V_49 , V_32 ) ;
}
static void F_65 ( struct V_159 * V_160 , int V_161 )
{
struct V_149 * V_150 ;
unsigned long V_32 ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
F_22 ( & V_150 -> V_49 , V_32 ) ;
if ( V_161 ) {
if ( ! V_150 -> V_166 ) {
F_66 ( & V_150 -> V_167 , F_63 ,
( unsigned long ) V_150 ) ;
F_64 ( & V_150 -> V_167 , 1 + V_168 ) ;
V_150 -> V_166 ++ ;
}
} else {
if ( V_150 -> V_166 && -- V_150 -> V_166 <= 0 )
F_67 ( & V_150 -> V_167 ) ;
}
F_24 ( & V_150 -> V_49 , V_32 ) ;
if ( V_161 )
F_56 ( V_150 ) ;
}
static int F_68 ( struct V_159 * V_160 )
{
struct V_149 * V_150 ;
V_150 = (struct V_149 * ) V_160 -> V_163 -> V_164 ;
F_44 ( & V_150 -> V_49 ) ;
F_55 ( V_150 -> V_10 , V_150 -> V_139 ) ;
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
static int F_72 ( struct V_169 * V_26 , struct V_10 * V_10 , int V_139 )
{
char V_153 [ 40 ] ;
V_10 -> V_170 [ V_139 ] . V_139 = V_139 ;
V_10 -> V_170 [ V_139 ] . V_163 = NULL ;
V_10 -> V_170 [ V_139 ] . V_155 = NULL ;
V_10 -> V_170 [ V_139 ] . V_154 = NULL ;
V_10 -> V_170 [ V_139 ] . V_10 = V_10 ;
V_10 -> V_170 [ V_139 ] . V_166 = 0 ;
V_10 -> V_170 [ V_139 ] . V_156 = 0 ;
F_73 ( & V_10 -> V_170 [ V_139 ] . V_49 ) ;
snprintf ( V_153 , sizeof( V_153 ) , L_22 , V_26 -> V_171 , V_139 + 1 ) ;
if ( F_74 ( V_26 , V_153 , V_139 , 1 , 1 , & V_10 -> V_170 [ V_139 ] . V_163 ) < 0 )
return - 1 ;
sprintf ( V_10 -> V_170 [ V_139 ] . V_163 -> V_172 , L_23 , V_139 + 1 ) ;
V_10 -> V_170 [ V_139 ] . V_163 -> V_164 = & V_10 -> V_170 [ V_139 ] ;
F_75 ( V_10 -> V_170 [ V_139 ] . V_163 , V_173 , & V_174 ) ;
F_75 ( V_10 -> V_170 [ V_139 ] . V_163 , V_175 , & V_176 ) ;
V_10 -> V_170 [ V_139 ] . V_163 -> V_177 |= V_178 |
V_179 |
V_180 ;
return 0 ;
}
static T_2 F_76 ( struct V_181 * V_182 )
{
T_2 V_21 = 0 ;
V_21 |= ( V_182 -> V_69 [ 0 ] & V_183 ) ? V_184 : 0 ;
V_21 |= ( V_182 -> V_69 [ 0 ] & V_185 ) ? V_186 : 0 ;
if ( V_21 & V_184 )
V_21 |= ( V_182 -> V_69 [ 0 ] & V_187 ) ? V_188 : 0 ;
else
V_21 |= ( V_182 -> V_69 [ 0 ] & V_189 ) ? V_188 : 0 ;
return V_21 ;
}
static void F_77 ( struct V_181 * V_182 , T_2 V_21 )
{
V_182 -> V_69 [ 0 ] = ( ( V_21 & V_184 ) ? V_183 : 0 ) |
( ( V_21 & V_186 ) ? V_185 : 0 ) ;
if ( V_21 & V_184 )
V_182 -> V_69 [ 0 ] |= ( V_21 & V_188 ) ? V_187 : 0 ;
else
V_182 -> V_69 [ 0 ] |= ( V_21 & V_188 ) ? V_189 : 0 ;
}
static int F_78 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
V_193 -> type = V_194 ;
V_193 -> V_59 = 1 ;
return 0 ;
}
static int F_79 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
F_77 ( & V_196 -> V_197 . V_198 , V_10 -> V_199 ) ;
return 0 ;
}
static int F_81 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
T_2 V_21 ;
V_21 = F_76 ( & V_196 -> V_197 . V_198 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_200 = V_21 != V_10 -> V_199 ;
V_10 -> V_199 = V_21 ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_82 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
V_193 -> type = V_194 ;
V_193 -> V_59 = 1 ;
return 0 ;
}
static int F_83 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
F_77 ( & V_196 -> V_197 . V_198 , V_10 -> V_201 ) ;
return 0 ;
}
static int F_84 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
T_2 V_21 ;
V_21 = F_76 ( & V_196 -> V_197 . V_198 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_200 = V_21 != V_10 -> V_201 ;
V_10 -> V_201 = V_21 ;
V_10 -> V_93 &= ~ ( V_184 | V_186 | V_188 ) ;
F_8 ( V_10 , V_104 , V_10 -> V_93 |= V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_85 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
V_193 -> type = V_194 ;
V_193 -> V_59 = 1 ;
return 0 ;
}
static int F_86 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
V_196 -> V_197 . V_198 . V_69 [ 0 ] = V_191 -> V_202 ;
return 0 ;
}
static unsigned int F_87 ( struct V_10 * V_10 )
{
return F_88 ( V_10 -> V_93 & V_203 ) ;
}
static int F_89 ( struct V_10 * V_10 , int V_11 )
{
V_10 -> V_93 &= ~ V_203 ;
V_10 -> V_93 |= F_90 ( V_11 ) ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_91 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [ 4 ] = {
L_24 , L_25 , L_26 , L_27
} ;
struct V_10 * V_10 = F_80 ( V_191 ) ;
return F_92 ( V_193 , 1 , ( V_10 -> V_13 == V_18 ) ? 4 : 3 ,
V_204 ) ;
}
static int F_93 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_87 ( V_10 ) ;
return 0 ;
}
static int F_94 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . V_205 . V_206 [ 0 ] % ( ( V_10 -> V_13 == V_18 ) ? 4 : 3 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_200 = V_21 != F_87 ( V_10 ) ;
if ( V_200 )
F_89 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_95 ( struct V_10 * V_10 , T_2 V_207 )
{
return ( V_10 -> V_93 & V_207 ) ? 1 : 0 ;
}
static int F_96 ( struct V_10 * V_10 , T_2 V_207 , int V_12 )
{
if ( V_12 )
V_10 -> V_93 |= V_207 ;
else
V_10 -> V_93 &= ~ V_207 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_97 ( struct V_190 * V_191 ,
struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
T_2 V_207 = V_191 -> V_202 ;
F_44 ( & V_10 -> V_49 ) ;
V_196 -> V_197 . integer . V_197 [ 0 ] = F_95 ( V_10 , V_207 ) ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_98 ( struct V_190 * V_191 ,
struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
T_2 V_207 = V_191 -> V_202 ;
int V_200 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . integer . V_197 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_200 = ( int ) V_21 != F_95 ( V_10 , V_207 ) ;
if ( V_200 )
F_96 ( V_10 , V_207 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_99 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [] = {
L_28 , L_29 , L_30 , L_31 , L_32 , L_33 ,
L_34 , L_35 , L_36 , L_37
} ;
struct V_10 * V_10 = F_80 ( V_191 ) ;
return F_92 ( V_193 , 1 , ( V_10 -> V_13 == V_18 ) ? 10 : 7 ,
V_204 ) ;
}
static int F_100 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
switch ( F_33 ( V_10 ) ) {
case 32000 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 0 ;
break;
case 44100 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 1 ;
break;
case 48000 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 2 ;
break;
case 64000 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 3 ;
break;
case 88200 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 4 ;
break;
case 96000 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 5 ;
break;
case 128000 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 7 ;
break;
case 176400 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 8 ;
break;
case 192000 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 9 ;
break;
default:
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_101 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
V_193 -> type = V_208 ;
V_193 -> V_59 = 1 ;
return 0 ;
}
static int F_102 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = V_10 -> V_119 ;
return 0 ;
}
static int F_103 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
static const char * const V_204 [] = {
L_28 , L_29 , L_30 , L_31 , L_32 , L_33 ,
L_34 , L_35 , L_36 , L_37
} ;
return F_92 ( V_193 , 1 , ( V_10 -> V_13 == V_18 ) ? 10 : 7 ,
V_204 ) ;
}
static int F_104 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
switch ( F_34 ( V_10 ) ) {
case 32000 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 0 ;
break;
case 44100 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 1 ;
break;
case 48000 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 2 ;
break;
case 64000 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 3 ;
break;
case 88200 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 4 ;
break;
case 96000 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 5 ;
break;
case 128000 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 7 ;
break;
case 176400 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 8 ;
break;
case 192000 :
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 9 ;
break;
default:
V_196 -> V_197 . V_205 . V_206 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_105 ( struct V_10 * V_10 )
{
if ( V_10 -> V_93 & V_115 )
return 0 ;
else if ( F_34 ( V_10 ) != V_10 -> V_119 )
return 0 ;
return 1 ;
}
static int F_106 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [] = { L_38 , L_39 } ;
return F_92 ( V_193 , 1 , 2 , V_204 ) ;
}
static int F_107 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_105 ( V_10 ) ;
return 0 ;
}
static int F_108 ( struct V_10 * V_10 )
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
static int F_109 ( struct V_10 * V_10 , int V_209 )
{
int V_110 ;
switch ( V_209 ) {
case V_210 :
if ( F_34 ( V_10 ) != 0 ) {
if ( ! F_50 ( V_10 , F_34 ( V_10 ) , 1 ) ) {
V_10 -> V_93 &= ~ V_115 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
}
return - 1 ;
case V_211 :
V_110 = 32000 ;
break;
case V_212 :
V_110 = 44100 ;
break;
case V_213 :
V_110 = 48000 ;
break;
case V_214 :
V_110 = 64000 ;
break;
case V_215 :
V_110 = 88200 ;
break;
case V_216 :
V_110 = 96000 ;
break;
case V_217 :
V_110 = 128000 ;
break;
case V_218 :
V_110 = 176400 ;
break;
case V_219 :
V_110 = 192000 ;
break;
default:
V_110 = 48000 ;
}
V_10 -> V_93 |= V_115 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
F_50 ( V_10 , V_110 , 1 ) ;
return 0 ;
}
static int F_110 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [] = {
L_40 , L_41 , L_42 ,
L_43 , L_44 , L_45 ,
L_46 , L_47 , L_48 ,
L_49
} ;
struct V_10 * V_10 = F_80 ( V_191 ) ;
return F_92 ( V_193 , 1 , ( V_10 -> V_13 == V_18 ) ? 10 : 7 ,
V_204 ) ;
}
static int F_111 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_108 ( V_10 ) ;
return 0 ;
}
static int F_112 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . V_205 . V_206 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_10 -> V_13 == V_18 ) {
if ( V_21 > 9 )
V_21 = 9 ;
} else {
if ( V_21 > 6 )
V_21 = 6 ;
}
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_108 ( V_10 ) )
V_200 = ( F_109 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_200 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_113 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . integer . V_197 [ 0 ] = V_10 -> V_220 ;
return 0 ;
}
static int F_114 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
V_200 = ( int ) V_196 -> V_197 . integer . V_197 [ 0 ] != V_10 -> V_220 ;
if ( V_200 )
V_10 -> V_220 = ! ! V_196 -> V_197 . integer . V_197 [ 0 ] ;
return V_200 ;
}
static int F_115 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_93 & V_221 ) {
case V_222 :
return 0 ;
case V_223 :
return 1 ;
case V_224 :
return 2 ;
default:
return 1 ;
}
}
static int F_116 ( struct V_10 * V_10 , int V_209 )
{
V_10 -> V_93 &= ~ V_221 ;
switch ( V_209 ) {
case 0 :
V_10 -> V_93 |= V_222 ;
break;
case 1 :
V_10 -> V_93 |= V_223 ;
break;
case 2 :
V_10 -> V_93 |= V_224 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_117 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [] = { L_50 , L_51 , L_52 } ;
return F_92 ( V_193 , 1 , 3 , V_204 ) ;
}
static int F_118 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_115 ( V_10 ) ;
return 0 ;
}
static int F_119 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . V_205 . V_206 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_115 ( V_10 ) )
V_200 = ( F_116 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_200 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_120 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_93 & V_225 ) {
case V_226 :
return 0 ;
case V_227 :
return 1 ;
case V_228 :
return 2 ;
default:
return 1 ;
}
}
static int F_121 ( struct V_10 * V_10 , int V_209 )
{
V_10 -> V_93 &= ~ V_225 ;
switch ( V_209 ) {
case 0 :
V_10 -> V_93 |= V_226 ;
break;
case 1 :
V_10 -> V_93 |= V_227 ;
break;
case 2 :
V_10 -> V_93 |= V_228 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_122 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [] = { L_53 , L_51 , L_54 } ;
return F_92 ( V_193 , 1 , 3 , V_204 ) ;
}
static int F_123 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_120 ( V_10 ) ;
return 0 ;
}
static int F_124 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . V_205 . V_206 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_120 ( V_10 ) )
V_200 = ( F_121 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_200 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_125 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_93 & V_229 ) {
case V_230 :
return 0 ;
case V_231 :
return 1 ;
case V_232 :
return 2 ;
default:
return 0 ;
}
}
static int F_126 ( struct V_10 * V_10 , int V_209 )
{
V_10 -> V_93 &= ~ V_229 ;
switch ( V_209 ) {
case 0 :
V_10 -> V_93 |= V_230 ;
break;
case 1 :
V_10 -> V_93 |= V_231 ;
break;
case 2 :
V_10 -> V_93 |= V_232 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_127 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [] = { L_55 , L_56 , L_57 } ;
return F_92 ( V_193 , 1 , 3 , V_204 ) ;
}
static int F_128 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_125 ( V_10 ) ;
return 0 ;
}
static int F_129 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . V_205 . V_206 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_125 ( V_10 ) )
V_200 = ( F_126 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_200 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_130 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_93 & V_233 ) {
case V_234 :
return V_235 ;
case V_236 :
return V_237 ;
case V_238 :
return V_239 ;
case V_240 :
return V_241 ;
case V_242 :
return V_243 ;
case V_244 :
return V_245 ;
default:
return V_243 ;
}
return 0 ;
}
static int F_131 ( struct V_10 * V_10 , int V_246 )
{
V_10 -> V_93 &= ~ V_233 ;
switch ( V_246 ) {
case V_235 :
V_10 -> V_93 &= ~ V_233 ;
break;
case V_237 :
V_10 -> V_93 |= V_236 ;
break;
case V_239 :
V_10 -> V_93 |= V_238 ;
break;
case V_241 :
V_10 -> V_93 |= V_240 ;
break;
case V_243 :
V_10 -> V_93 |= V_242 ;
break;
case V_245 :
V_10 -> V_93 |= V_244 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_132 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [] = {
L_58 , L_59 , L_60 , L_61 , L_62 , L_63
} ;
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_247 ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_247 = 6 ;
break;
case V_14 :
V_247 = 4 ;
break;
case V_18 :
V_247 = 3 ;
break;
default:
return - V_120 ;
}
return F_92 ( V_193 , 1 , V_247 , V_204 ) ;
}
static int F_133 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_130 ( V_10 ) ;
return 0 ;
}
static int F_134 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 , V_248 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_248 = 6 ;
break;
case V_14 :
V_248 = 4 ;
break;
case V_18 :
V_248 = 3 ;
break;
default:
return - V_29 ;
}
V_21 = V_196 -> V_197 . V_205 . V_206 [ 0 ] % V_248 ;
F_44 ( & V_10 -> V_49 ) ;
V_200 = ( int ) V_21 != F_130 ( V_10 ) ;
F_131 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_35 ( struct V_10 * V_10 )
{
unsigned int V_83 = F_10 ( V_10 , V_54 ) ;
switch ( V_83 & V_249 ) {
case V_250 :
return V_251 ;
case V_252 :
return V_253 ;
case V_254 :
return V_85 ;
case V_249 :
return V_255 ;
case V_256 :
return V_118 ;
case V_257 :
return V_258 ;
case V_259 :
return V_260 ;
default:
return V_251 ;
}
return 0 ;
}
static int F_135 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [] = {
L_58 , L_61 , L_59 , L_34 , L_60 , L_62 , L_63
} ;
return F_92 ( V_193 , 1 , 7 , V_204 ) ;
}
static int F_136 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_35 ( V_10 ) ;
return 0 ;
}
static int F_137 ( struct V_10 * V_10 , int V_261 )
{
if ( V_261 )
V_10 -> V_95 = 1 ;
else
V_10 -> V_95 = 0 ;
return 0 ;
}
static int F_138 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_196 -> V_197 . integer . V_197 [ 0 ] = V_10 -> V_95 ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_139 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . integer . V_197 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_200 = ( int ) V_21 != V_10 -> V_95 ;
F_137 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_140 ( struct V_10 * V_10 , int V_262 )
{
if ( V_262 )
V_10 -> V_263 = 1 ;
else
V_10 -> V_263 = 0 ;
return 0 ;
}
static int F_141 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_196 -> V_197 . integer . V_197 [ 0 ] = V_10 -> V_263 ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_142 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . integer . V_197 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_200 = ( int ) V_21 != V_10 -> V_263 ;
F_140 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_143 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
V_193 -> type = V_208 ;
V_193 -> V_59 = 3 ;
V_193 -> V_197 . integer . V_264 = 0 ;
V_193 -> V_197 . integer . V_248 = 65536 ;
V_193 -> V_197 . integer . V_265 = 1 ;
return 0 ;
}
static int F_144 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_266 ;
int V_267 ;
int V_62 ;
V_266 = V_196 -> V_197 . integer . V_197 [ 0 ] ;
V_267 = V_196 -> V_197 . integer . V_197 [ 1 ] ;
if ( V_266 >= V_10 -> V_268 )
V_62 = F_6 ( V_10 , V_266 - V_10 -> V_268 , V_267 ) ;
else
V_62 = F_7 ( V_10 , V_266 , V_267 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_196 -> V_197 . integer . V_197 [ 2 ] = F_30 ( V_10 , V_62 ) ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_145 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
int V_266 ;
int V_267 ;
int V_269 ;
int V_62 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_266 = V_196 -> V_197 . integer . V_197 [ 0 ] ;
V_267 = V_196 -> V_197 . integer . V_197 [ 1 ] ;
if ( V_266 >= V_10 -> V_268 )
V_62 = F_6 ( V_10 , V_266 - V_10 -> V_268 , V_267 ) ;
else
V_62 = F_7 ( V_10 , V_266 , V_267 ) ;
V_269 = V_196 -> V_197 . integer . V_197 [ 2 ] ;
F_44 ( & V_10 -> V_49 ) ;
V_200 = V_269 != F_30 ( V_10 , V_62 ) ;
if ( V_200 )
F_31 ( V_10 , V_62 , V_269 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_146 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [] = { L_64 , L_65 , L_66 } ;
return F_92 ( V_193 , 1 , 3 , V_204 ) ;
}
static int F_147 ( struct V_10 * V_10 )
{
int V_83 = F_10 ( V_10 , V_54 ) ;
if ( V_83 & V_270 ) {
if ( V_83 & V_271 )
return 2 ;
else
return 1 ;
} else
return 0 ;
return 0 ;
}
static int F_148 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_147 ( V_10 ) ;
return 0 ;
}
static int F_149 ( struct V_10 * V_10 )
{
int V_69 = F_10 ( V_10 , V_24 ) ;
if ( V_69 & V_73 )
return 0 ;
else {
if ( V_69 & V_272 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_150 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_149 ( V_10 ) ;
return 0 ;
}
static int F_151 ( struct V_10 * V_10 )
{
int V_69 = F_10 ( V_10 , V_24 ) ;
if ( V_69 & V_273 ) {
if ( V_69 & V_274 )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_152 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_151 ( V_10 ) ;
return 0 ;
}
static int F_153 ( struct V_10 * V_10 , int V_275 )
{
int V_69 = F_10 ( V_10 , V_24 ) ;
if ( V_69 & ( V_276 >> V_275 ) ) {
if ( V_69 & ( V_277 >> V_275 ) )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_154 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
int V_278 ;
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_278 = V_196 -> V_139 . V_279 - 1 ;
if ( F_49 ( V_278 < 0 ) )
return - V_120 ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
if ( V_278 >= 3 )
return - V_120 ;
break;
case V_14 :
case V_18 :
if ( V_278 >= 1 )
return - V_120 ;
break;
default:
return - V_29 ;
}
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_153 ( V_10 , V_278 ) ;
return 0 ;
}
static int F_155 ( struct V_10 * V_10 )
{
T_4 V_108 ;
unsigned int V_100 = V_10 -> V_100 ;
int V_119 = V_10 -> V_119 ;
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
static int F_156 ( struct V_10 * V_10 , int V_280 )
{
int V_110 = V_10 -> V_119 + V_280 ;
F_47 ( V_10 , V_110 ) ;
return 0 ;
}
static int F_157 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
V_193 -> type = V_208 ;
V_193 -> V_59 = 1 ;
V_193 -> V_197 . integer . V_264 = - 5000 ;
V_193 -> V_197 . integer . V_248 = 5000 ;
return 0 ;
}
static int F_158 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . integer . V_197 [ 0 ] = F_155 ( V_10 ) ;
return 0 ;
}
static int F_159 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . integer . V_197 [ 0 ] ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_155 ( V_10 ) )
V_200 = ( F_156 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_200 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_160 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_93 & V_281 ) {
case V_282 :
return 0 ;
case V_283 :
return 2 ;
case V_284 :
return 3 ;
case V_285 :
return 4 ;
}
return 1 ;
}
static int F_161 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_160 ( V_10 ) ;
return 0 ;
}
static int F_162 ( struct V_10 * V_10 , int V_209 )
{
V_10 -> V_93 &= ~ V_281 ;
switch ( V_209 ) {
case 0 :
V_10 -> V_93 |= V_282 ;
break;
case 1 :
break;
case 2 :
V_10 -> V_93 |= V_283 ;
break;
case 3 :
V_10 -> V_93 |= V_284 ;
break;
case 4 :
V_10 -> V_93 |= V_285 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_163 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . V_205 . V_206 [ 0 ] ;
if ( V_21 < 0 )
V_21 = 0 ;
if ( V_21 > 4 )
V_21 = 4 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_160 ( V_10 ) )
V_200 = ( F_162 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_200 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_164 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [] = {
L_67 , L_68 , L_69 , L_70 , L_71
} ;
return F_92 ( V_193 , 1 , 5 , V_204 ) ;
}
static int F_165 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_93 & V_286 ) {
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
static int F_166 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . V_205 . V_206 [ 0 ] = F_165 ( V_10 ) ;
return 0 ;
}
static int F_167 ( struct V_10 * V_10 , int V_209 )
{
V_10 -> V_93 &= ~ V_286 ;
switch ( V_209 ) {
case 0 :
V_10 -> V_93 |= V_287 ;
break;
case 1 :
break;
case 2 :
V_10 -> V_93 |= V_288 ;
break;
case 3 :
V_10 -> V_93 |= V_289 ;
break;
case 4 :
V_10 -> V_93 |= V_290 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_168 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . V_205 . V_206 [ 0 ] ;
if ( V_21 < 0 )
V_21 = 0 ;
if ( V_21 > 4 )
V_21 = 4 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_165 ( V_10 ) )
V_200 = ( F_167 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_200 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_169 ( struct V_10 * V_10 )
{
return ( V_10 -> V_93 & V_291 ) ? 1 : 0 ;
}
static int F_170 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . integer . V_197 [ 0 ] = F_169 ( V_10 ) ;
return 0 ;
}
static int F_171 ( struct V_10 * V_10 , int V_292 )
{
if ( V_292 )
V_10 -> V_93 |= V_291 ;
else
V_10 -> V_93 &= ~ V_291 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_172 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . integer . V_197 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_200 = ( int ) V_21 != F_169 ( V_10 ) ;
F_171 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_173 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [] = { L_72 , L_73 } ;
return F_92 ( V_193 , 1 , 2 , V_204 ) ;
}
static int F_174 ( struct V_10 * V_10 )
{
return ( V_10 -> V_93 & V_293 ) ? 1 : 0 ;
}
static int F_175 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
V_196 -> V_197 . integer . V_197 [ 0 ] = F_174 ( V_10 ) ;
return 0 ;
}
static int F_176 ( struct V_10 * V_10 , int V_292 )
{
if ( V_292 )
V_10 -> V_93 |= V_293 ;
else
V_10 -> V_93 &= ~ V_293 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
return 0 ;
}
static int F_177 ( struct V_190 * V_191 , struct V_195 * V_196 )
{
struct V_10 * V_10 = F_80 ( V_191 ) ;
int V_200 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_130 ;
V_21 = V_196 -> V_197 . integer . V_197 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_200 = ( int ) V_21 != F_174 ( V_10 ) ;
F_176 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_200 ;
}
static int F_178 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
static const char * const V_204 [] = { L_72 , L_73 } ;
return F_92 ( V_193 , 1 , 2 , V_204 ) ;
}
static int F_179 ( struct V_169 * V_26 , struct V_10 * V_10 )
{
unsigned int V_275 ;
int V_294 ;
struct V_190 * V_295 ;
if ( V_10 -> V_13 == V_16 ) {
for ( V_275 = 0 ; V_275 < F_180 ( V_296 ) ; V_275 ++ ) {
V_294 = F_181 ( V_26 , V_295 = F_182 ( & V_296 [ V_275 ] , V_10 ) ) ;
if ( V_294 < 0 )
return V_294 ;
}
return 0 ;
}
for ( V_275 = 0 ; V_275 < F_180 ( V_297 ) ; V_275 ++ ) {
if ( ( V_294 = F_181 ( V_26 , V_295 = F_182 ( & V_297 [ V_275 ] , V_10 ) ) ) < 0 )
return V_294 ;
if ( V_275 == 1 )
V_10 -> V_298 = V_295 ;
}
V_299 . V_172 = L_74 ;
V_299 . V_279 = 1 ;
if ( ( V_294 = F_181 ( V_26 , V_295 = F_182 ( & V_299 , V_10 ) ) ) )
return V_294 ;
if ( V_10 -> V_13 == V_15 || V_10 -> V_13 == V_19 ) {
for ( V_275 = 1 ; V_275 < 3 ; ++ V_275 ) {
V_299 . V_279 = V_275 + 1 ;
if ( ( V_294 = F_181 ( V_26 , V_295 = F_182 ( & V_299 , V_10 ) ) ) )
return V_294 ;
}
}
if ( V_10 -> V_13 == V_18 ) {
for ( V_275 = 0 ; V_275 < F_180 ( V_300 ) ; V_275 ++ ) {
if ( ( V_294 = F_181 ( V_26 , V_295 = F_182 ( & V_300 [ V_275 ] , V_10 ) ) ) < 0 )
return V_294 ;
}
}
if ( V_10 -> V_13 == V_18 || V_10 -> V_13 == V_19 ) {
if ( ( V_294 = F_181 ( V_26 , V_295 = F_182 ( & V_301 , V_10 ) ) ) < 0 )
return V_294 ;
}
return 0 ;
}
static void
F_183 ( struct V_302 * V_303 , struct V_304 * V_305 )
{
struct V_10 * V_10 = V_303 -> V_164 ;
unsigned int V_69 ;
unsigned int V_83 ;
char * V_306 ;
char * V_307 ;
char * V_308 ;
char * V_309 ;
int V_310 ;
V_69 = F_10 ( V_10 , V_24 ) ;
V_83 = F_10 ( V_10 , V_54 ) ;
F_184 ( V_305 , L_75 , V_10 -> V_311 ,
V_10 -> V_26 -> V_312 + 1 ) ;
F_184 ( V_305 , L_76 ,
V_10 -> V_313 , V_10 -> V_105 ) ;
F_184 ( V_305 , L_77 ,
V_10 -> V_314 , V_10 -> V_315 , ( unsigned long ) V_10 -> V_22 ) ;
F_184 ( V_305 , L_78 , V_10 -> V_93 ) ;
F_184 ( V_305 , L_79 ,
V_10 -> V_46 ) ;
F_184 ( V_305 , L_80 , V_69 ) ;
F_184 ( V_305 , L_81 , V_83 ) ;
if ( F_12 ( V_10 ) ) {
F_184 ( V_305 , L_82
L_83 ) ;
return;
}
if ( F_26 ( V_10 , 0 ) ) {
if ( V_10 -> V_27 & V_58 ) {
if ( F_18 ( V_10 ) != 0 ) {
F_184 ( V_305 , L_84
L_85
L_86 ) ;
return;
}
} else {
int V_294 = - V_120 ;
V_294 = F_27 ( V_10 ) ;
if ( V_294 < 0 ) {
F_184 ( V_305 ,
L_87
L_88 ) ;
return;
}
}
}
F_184 ( V_305 , L_89 , F_10 ( V_10 , V_61 ) & 0xff ) ;
F_184 ( V_305 , L_90 , F_10 ( V_10 , V_148 ) ) ;
F_184 ( V_305 , L_91 , F_10 ( V_10 , V_145 ) ) ;
F_184 ( V_305 , L_92 , F_10 ( V_10 , V_147 ) ) ;
F_184 ( V_305 , L_93 , F_10 ( V_10 , V_144 ) ) ;
F_184 ( V_305 , L_94 , V_10 -> V_263 ? L_95 : L_96 ) ;
F_184 ( V_305 , L_97 ) ;
V_310 = 1 << ( 6 + F_37 ( V_10 -> V_93 & V_109 ) ) ;
F_184 ( V_305 , L_98 , V_310 , ( unsigned long ) V_10 -> V_92 ) ;
F_184 ( V_305 , L_99 , F_38 ( V_10 ) ) ;
F_184 ( V_305 , L_100 , V_10 -> V_95 ? L_95 : L_96 ) ;
F_184 ( V_305 , L_101 , ( V_10 -> V_93 & V_316 ) ? L_95 : L_96 ) ;
F_184 ( V_305 , L_102 , ( V_83 & V_317 ) | ( V_83 & V_56 ) << 1 | ( V_83 & V_55 ) << 2 ) ;
F_184 ( V_305 , L_97 ) ;
switch ( F_108 ( V_10 ) ) {
case V_210 :
V_309 = L_40 ;
break;
case V_211 :
V_309 = L_103 ;
break;
case V_212 :
V_309 = L_42 ;
break;
case V_213 :
V_309 = L_104 ;
break;
case V_214 :
V_309 = L_105 ;
break;
case V_215 :
V_309 = L_45 ;
break;
case V_216 :
V_309 = L_106 ;
break;
case V_217 :
V_309 = L_47 ;
break;
case V_218 :
V_309 = L_48 ;
break;
case V_219 :
V_309 = L_107 ;
break;
default:
V_309 = L_108 ;
}
F_184 ( V_305 , L_109 , V_309 ) ;
if ( F_105 ( V_10 ) )
V_308 = L_39 ;
else
V_308 = L_38 ;
switch ( F_130 ( V_10 ) ) {
case V_243 :
V_306 = L_110 ;
break;
case V_245 :
V_306 = L_61 ;
break;
case V_241 :
V_306 = L_111 ;
break;
case V_235 :
V_306 = L_60 ;
break;
case V_237 :
V_306 = L_62 ;
break;
case V_239 :
V_306 = L_63 ;
break;
default:
V_306 = L_110 ;
break;
}
F_184 ( V_305 , L_112 , V_306 ) ;
switch ( F_35 ( V_10 ) ) {
case V_251 :
V_307 = L_110 ;
break;
case V_253 :
V_307 = L_61 ;
break;
case V_85 :
V_307 = L_111 ;
break;
case V_255 :
V_307 = L_34 ;
break;
case V_118 :
V_307 = L_60 ;
break;
case V_258 :
V_307 = L_62 ;
break;
case V_260 :
V_307 = L_63 ;
break;
default:
V_307 = L_113 ;
break;
}
F_184 ( V_305 , L_114 , V_307 ) ;
F_184 ( V_305 , L_115 , F_34 ( V_10 ) ) ;
F_184 ( V_305 , L_116 , V_308 ) ;
F_184 ( V_305 , L_117 , V_10 -> V_119 ) ;
F_184 ( V_305 , L_118 , V_10 -> V_220 ? L_119 : L_120 ) ;
F_184 ( V_305 , L_97 ) ;
if ( V_10 -> V_13 != V_16 ) {
switch ( F_87 ( V_10 ) ) {
case V_318 :
F_184 ( V_305 , L_121 ) ;
break;
case V_319 :
F_184 ( V_305 , L_122 ) ;
break;
case V_320 :
F_184 ( V_305 , L_123 ) ;
break;
case V_321 :
F_184 ( V_305 , L_124 ) ;
break;
default:
F_184 ( V_305 , L_125 ) ;
break;
}
}
if ( V_16 == V_10 -> V_13 ) {
if ( V_10 -> V_93 & V_291 )
F_184 ( V_305 , L_126 ) ;
else
F_184 ( V_305 , L_127 ) ;
if ( V_10 -> V_93 & V_293 )
F_184 ( V_305 , L_128 ) ;
else
F_184 ( V_305 , L_129 ) ;
switch ( V_10 -> V_93 & V_281 ) {
case V_282 :
F_184 ( V_305 , L_130 ) ;
break;
case V_322 :
F_184 ( V_305 , L_131 ) ;
break;
case V_283 :
F_184 ( V_305 , L_132 ) ;
break;
case V_284 :
F_184 ( V_305 , L_133 ) ;
break;
case V_285 :
F_184 ( V_305 , L_134 ) ;
break;
default:
F_184 ( V_305 , L_135 ) ;
}
switch ( V_10 -> V_93 & V_286 ) {
case V_287 :
F_184 ( V_305 , L_136 ) ;
break;
case V_323 :
F_184 ( V_305 , L_137 ) ;
break;
case V_288 :
F_184 ( V_305 , L_138 ) ;
break;
case V_289 :
F_184 ( V_305 , L_139 ) ;
break;
case V_290 :
F_184 ( V_305 , L_140 ) ;
break;
default:
F_184 ( V_305 , L_141 ) ;
}
} else {
if ( V_10 -> V_93 & V_324 )
F_184 ( V_305 , L_142 ) ;
else
F_184 ( V_305 , L_143 ) ;
if ( V_10 -> V_93 & V_184 )
F_184 ( V_305 , L_144 ) ;
else
F_184 ( V_305 , L_145 ) ;
if ( V_10 -> V_93 & V_188 )
F_184 ( V_305 , L_146 ) ;
else
F_184 ( V_305 , L_147 ) ;
if ( V_10 -> V_93 & V_186 )
F_184 ( V_305 , L_148 ) ;
else
F_184 ( V_305 , L_149 ) ;
V_310 = F_33 ( V_10 ) ;
if ( V_310 != 0 )
F_184 ( V_305 , L_150 , V_310 ) ;
else
F_184 ( V_305 , L_151 ) ;
}
F_184 ( V_305 , L_97 ) ;
V_310 = V_69 & V_277 ;
if ( V_69 & V_276 )
F_184 ( V_305 , L_152 , V_310 ? L_66 : L_65 ) ;
else
F_184 ( V_305 , L_153 ) ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_310 = V_69 & V_325 ;
if ( V_69 & V_326 )
F_184 ( V_305 , L_154 , V_310 ? L_66 : L_65 ) ;
else
F_184 ( V_305 , L_155 ) ;
V_310 = V_69 & V_327 ;
if ( V_69 & V_328 )
F_184 ( V_305 , L_156 , V_310 ? L_66 : L_65 ) ;
else
F_184 ( V_305 , L_157 ) ;
break;
default:
break;
}
V_310 = V_69 & V_272 ;
if ( V_69 & V_73 )
F_184 ( V_305 , L_158 ) ;
else
F_184 ( V_305 , L_159 , V_310 ? L_66 : L_65 ) ;
V_310 = V_83 & V_271 ;
if ( V_83 & V_270 )
F_184 ( V_305 , L_160 , V_310 ? L_66 : L_65 ) ;
else
F_184 ( V_305 , L_161 ) ;
V_310 = V_69 & V_274 ;
if ( V_69 & V_273 )
F_184 ( V_305 , L_162 , V_310 ? L_66 : L_65 ) ;
else
F_184 ( V_305 , L_163 ) ;
F_184 ( V_305 , L_97 ) ;
if ( V_10 -> V_13 == V_18 ) {
char * V_329 ;
switch ( F_120 ( V_10 ) ) {
case 0 :
V_329 = L_53 ;
break;
case 1 :
V_329 = L_51 ;
break;
default:
V_329 = L_54 ;
break;
}
F_184 ( V_305 , L_164 , V_329 ) ;
switch ( F_115 ( V_10 ) ) {
case 0 :
V_329 = L_50 ;
break;
case 1 :
V_329 = L_51 ;
break;
default:
V_329 = L_53 ;
break;
}
F_184 ( V_305 , L_165 , V_329 ) ;
switch ( F_125 ( V_10 ) ) {
case 0 :
V_329 = L_55 ;
break;
case 1 :
V_329 = L_56 ;
break;
default:
V_329 = L_57 ;
break;
}
F_184 ( V_305 , L_166 , V_329 ) ;
F_184 ( V_305 , L_167 ,
F_95 ( V_10 , V_330 ) ?
L_168 : L_169 ) ;
if ( V_10 -> V_93 & V_331 )
F_184 ( V_305 , L_170 ) ;
else
F_184 ( V_305 , L_171 ) ;
F_184 ( V_305 , L_97 ) ;
}
}
static void F_185 ( struct V_10 * V_10 )
{
struct V_302 * V_303 ;
if ( ! F_186 ( V_10 -> V_26 , L_172 , & V_303 ) )
F_187 ( V_303 , V_10 , F_183 ) ;
}
static void F_188 ( struct V_10 * V_10 )
{
F_4 ( & V_10 -> V_332 , V_10 -> V_2 ) ;
F_4 ( & V_10 -> V_333 , V_10 -> V_2 ) ;
}
static int F_189 ( struct V_10 * V_10 )
{
unsigned long V_334 , V_335 ;
if ( F_1 ( V_10 -> V_2 , & V_10 -> V_332 , V_106 ) < 0 ||
F_1 ( V_10 -> V_2 , & V_10 -> V_333 , V_106 ) < 0 ) {
if ( V_10 -> V_332 . V_9 )
F_5 ( & V_10 -> V_332 ) ;
F_15 ( V_10 -> V_26 -> V_6 ,
L_173 , V_10 -> V_311 ) ;
return - V_8 ;
}
V_335 = F_190 ( V_10 -> V_332 . V_62 , 0x10000ul ) ;
V_334 = F_190 ( V_10 -> V_333 . V_62 , 0x10000ul ) ;
F_8 ( V_10 , V_336 , V_335 ) ;
F_8 ( V_10 , V_337 , V_334 ) ;
V_10 -> V_313 = V_10 -> V_332 . V_9 + ( V_335 - V_10 -> V_332 . V_62 ) ;
V_10 -> V_105 = V_10 -> V_333 . V_9 + ( V_334 - V_10 -> V_333 . V_62 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_10 )
{
unsigned int V_23 ;
V_10 -> V_93 = V_115 |
V_338 |
F_45 ( 7 ) |
V_316 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
#ifdef F_21
V_10 -> V_46 = V_47 ;
#else
V_10 -> V_46 = 0 ;
#endif
if ( V_10 -> V_13 == V_19 )
F_191 ( V_10 ) ;
else
F_8 ( V_10 , V_39 , V_10 -> V_46 ) ;
F_39 ( V_10 ) ;
F_36 ( V_10 ) ;
for ( V_23 = 0 ; V_23 < V_63 ; ++ V_23 )
V_10 -> V_64 [ V_23 ] = V_339 ;
for ( V_23 = 0 ; V_23 < ( ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) ? 1352 : V_63 ) ; ++ V_23 ) {
if ( F_31 ( V_10 , V_23 , V_339 ) )
return - V_29 ;
}
if ( V_10 -> V_13 == V_18 ) {
V_10 -> V_93 |= ( V_223 | V_227 | V_230 ) ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
}
F_50 ( V_10 , 48000 , 1 ) ;
return 0 ;
}
static void F_192 ( unsigned long V_340 )
{
struct V_10 * V_10 = (struct V_10 * ) V_340 ;
if ( V_10 -> V_170 [ 0 ] . V_156 )
F_59 ( & V_10 -> V_170 [ 0 ] ) ;
if ( V_10 -> V_170 [ 1 ] . V_156 )
F_59 ( & V_10 -> V_170 [ 1 ] ) ;
}
static T_5 F_193 ( int V_314 , void * V_341 )
{
struct V_10 * V_10 = (struct V_10 * ) V_341 ;
unsigned int V_69 ;
int V_342 ;
int V_343 ;
int V_344 ;
unsigned int V_345 ;
unsigned int V_346 ;
int V_347 = 0 ;
V_69 = F_10 ( V_10 , V_24 ) ;
V_342 = V_69 & V_348 ;
V_343 = V_69 & V_349 ;
V_344 = V_69 & V_350 ;
if ( ! V_342 && ! V_343 && ! V_344 )
return V_351 ;
F_8 ( V_10 , V_352 , 0 ) ;
V_345 = F_10 ( V_10 , V_145 ) & 0xff ;
V_346 = F_10 ( V_10 , V_144 ) & 0xff ;
if ( ! ( V_10 -> V_27 & V_48 ) )
return V_353 ;
if ( V_342 ) {
if ( V_10 -> V_354 )
F_194 ( V_10 -> V_355 -> V_356 [ V_357 ] . V_160 ) ;
if ( V_10 -> V_358 )
F_194 ( V_10 -> V_355 -> V_356 [ V_359 ] . V_160 ) ;
}
if ( V_343 && V_345 ) {
if ( V_10 -> V_263 ) {
V_10 -> V_93 &= ~ V_158 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
V_10 -> V_170 [ 0 ] . V_156 = 1 ;
V_347 = 1 ;
} else {
F_59 ( & V_10 -> V_170 [ 0 ] ) ;
}
}
if ( V_10 -> V_13 != V_14 && V_10 -> V_13 != V_16 && V_10 -> V_13 != V_18 && V_344 && V_346 ) {
if ( V_10 -> V_263 ) {
V_10 -> V_93 &= ~ V_157 ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
V_10 -> V_170 [ 1 ] . V_156 = 1 ;
V_347 = 1 ;
} else {
F_59 ( & V_10 -> V_170 [ 1 ] ) ;
}
}
if ( V_10 -> V_263 && V_347 )
F_195 ( & V_10 -> V_165 ) ;
return V_353 ;
}
static T_3 F_196 ( struct V_360 * V_160 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
return F_38 ( V_10 ) ;
}
static char * F_198 ( struct V_10 * V_10 ,
int V_361 ,
int V_362 )
{
int V_363 ;
if ( F_49 ( V_362 < 0 || V_362 >= V_10 -> V_268 ) )
return NULL ;
if ( ( V_363 = V_10 -> V_132 [ V_362 ] ) < 0 )
return NULL ;
if ( V_361 == V_357 )
return V_10 -> V_313 + ( V_363 * V_364 ) ;
else
return V_10 -> V_105 + ( V_363 * V_364 ) ;
}
static int F_199 ( struct V_360 * V_160 ,
int V_362 , unsigned long V_365 ,
void T_6 * V_366 , unsigned long V_59 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
char * V_367 ;
if ( F_49 ( V_365 + V_59 > V_364 ) )
return - V_120 ;
V_367 = F_198 ( V_10 , V_160 -> V_368 -> V_361 , V_362 ) ;
if ( F_49 ( ! V_367 ) )
return - V_29 ;
if ( F_200 ( V_367 + V_365 , V_366 , V_59 ) )
return - V_369 ;
return 0 ;
}
static int F_201 ( struct V_360 * V_160 ,
int V_362 , unsigned long V_365 ,
void * V_366 , unsigned long V_59 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
char * V_367 ;
V_367 = F_198 ( V_10 , V_160 -> V_368 -> V_361 , V_362 ) ;
if ( F_49 ( ! V_367 ) )
return - V_29 ;
memcpy ( V_367 + V_365 , V_366 , V_59 ) ;
return 0 ;
}
static int F_202 ( struct V_360 * V_160 ,
int V_362 , unsigned long V_365 ,
void T_6 * V_370 , unsigned long V_59 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
char * V_367 ;
if ( F_49 ( V_365 + V_59 > V_364 ) )
return - V_120 ;
V_367 = F_198 ( V_10 , V_160 -> V_368 -> V_361 , V_362 ) ;
if ( F_49 ( ! V_367 ) )
return - V_29 ;
if ( F_203 ( V_370 , V_367 + V_365 , V_59 ) )
return - V_369 ;
return 0 ;
}
static int F_204 ( struct V_360 * V_160 ,
int V_362 , unsigned long V_365 ,
void * V_370 , unsigned long V_59 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
char * V_367 ;
V_367 = F_198 ( V_10 , V_160 -> V_368 -> V_361 , V_362 ) ;
if ( F_49 ( ! V_367 ) )
return - V_29 ;
memcpy ( V_370 , V_367 + V_365 , V_59 ) ;
return 0 ;
}
static int F_205 ( struct V_360 * V_160 ,
int V_362 , unsigned long V_365 ,
unsigned long V_59 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
char * V_367 ;
V_367 = F_198 ( V_10 , V_160 -> V_368 -> V_361 , V_362 ) ;
if ( F_49 ( ! V_367 ) )
return - V_29 ;
memset ( V_367 + V_365 , 0 , V_59 ) ;
return 0 ;
}
static int F_206 ( struct V_360 * V_160 )
{
struct V_371 * V_372 = V_160 -> V_372 ;
struct V_10 * V_10 = F_197 ( V_160 ) ;
struct V_360 * V_373 ;
if ( V_160 -> V_361 == V_359 )
V_373 = V_10 -> V_354 ;
else
V_373 = V_10 -> V_358 ;
if ( V_10 -> V_374 )
V_372 -> V_69 -> V_375 = F_38 ( V_10 ) ;
else
V_372 -> V_69 -> V_375 = 0 ;
if ( V_373 ) {
struct V_360 * V_101 ;
struct V_371 * V_376 = V_373 -> V_372 ;
F_207 (s, substream) {
if ( V_101 == V_373 ) {
V_376 -> V_69 -> V_375 = V_372 -> V_69 -> V_375 ;
break;
}
}
}
return 0 ;
}
static int F_208 ( struct V_360 * V_160 ,
struct V_377 * V_378 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
int V_294 ;
T_7 V_379 ;
T_7 V_380 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_160 -> V_368 -> V_361 == V_359 ) {
V_10 -> V_93 &= ~ ( V_184 | V_186 | V_188 ) ;
F_8 ( V_10 , V_104 , V_10 -> V_93 |= V_10 -> V_201 ) ;
V_379 = V_10 -> V_67 ;
V_380 = V_10 -> V_68 ;
} else {
V_379 = V_10 -> V_68 ;
V_380 = V_10 -> V_67 ;
}
if ( ( V_380 > 0 ) && ( V_379 != V_380 ) ) {
if ( F_209 ( V_378 ) != V_10 -> V_119 ) {
F_46 ( & V_10 -> V_49 ) ;
F_210 ( V_378 , V_381 ) ;
return - V_130 ;
}
if ( F_211 ( V_378 ) != V_10 -> V_92 / 4 ) {
F_46 ( & V_10 -> V_49 ) ;
F_210 ( V_378 , V_382 ) ;
return - V_130 ;
}
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
} else {
F_46 ( & V_10 -> V_49 ) ;
}
F_44 ( & V_10 -> V_49 ) ;
if ( ! V_10 -> V_220 ) {
if ( ( V_294 = F_50 ( V_10 , F_209 ( V_378 ) , 0 ) ) < 0 ) {
F_46 ( & V_10 -> V_49 ) ;
F_210 ( V_378 , V_381 ) ;
return V_294 ;
}
}
F_46 ( & V_10 -> V_49 ) ;
if ( ( V_294 = F_43 ( V_10 , F_211 ( V_378 ) ) ) < 0 ) {
F_210 ( V_378 , V_382 ) ;
return V_294 ;
}
return 0 ;
}
static int F_212 ( struct V_360 * V_160 ,
struct V_383 * V_384 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
int V_363 ;
if ( F_49 ( V_384 -> V_362 >= V_10 -> V_268 ) )
return - V_120 ;
if ( ( V_363 = V_10 -> V_132 [ V_384 -> V_362 ] ) < 0 )
return - V_120 ;
V_384 -> V_278 = V_363 * V_364 ;
V_384 -> V_385 = 0 ;
V_384 -> V_265 = 32 ;
return 0 ;
}
static int F_213 ( struct V_360 * V_160 ,
unsigned int V_386 , void * V_340 )
{
switch ( V_386 ) {
case V_387 :
return F_206 ( V_160 ) ;
case V_388 :
return F_212 ( V_160 , V_340 ) ;
default:
break;
}
return F_214 ( V_160 , V_386 , V_340 ) ;
}
static int F_215 ( struct V_360 * V_160 , int V_386 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
struct V_360 * V_373 ;
int V_374 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 0 ) )
return - V_29 ;
F_216 ( & V_10 -> V_49 ) ;
V_374 = V_10 -> V_374 ;
switch ( V_386 ) {
case V_389 :
V_374 |= 1 << V_160 -> V_361 ;
break;
case V_390 :
V_374 &= ~ ( 1 << V_160 -> V_361 ) ;
break;
default:
F_217 () ;
F_218 ( & V_10 -> V_49 ) ;
return - V_120 ;
}
if ( V_160 -> V_361 == V_359 )
V_373 = V_10 -> V_354 ;
else
V_373 = V_10 -> V_358 ;
if ( V_373 ) {
struct V_360 * V_101 ;
F_207 (s, substream) {
if ( V_101 == V_373 ) {
F_219 ( V_101 , V_160 ) ;
if ( V_386 == V_389 )
V_374 |= 1 << V_101 -> V_361 ;
else
V_374 &= ~ ( 1 << V_101 -> V_361 ) ;
goto V_391;
}
}
if ( V_386 == V_389 ) {
if ( ! ( V_374 & ( 1 << V_359 ) ) &&
V_160 -> V_361 == V_357 )
F_42 ( V_10 ) ;
} else {
if ( V_374 &&
V_160 -> V_361 == V_359 )
F_42 ( V_10 ) ;
}
} else {
if ( V_160 -> V_361 == V_357 )
F_42 ( V_10 ) ;
}
V_391:
F_219 ( V_160 , V_160 ) ;
if ( ! V_10 -> V_374 && V_374 )
F_40 ( V_10 ) ;
else if ( V_10 -> V_374 && ! V_374 )
F_41 ( V_10 ) ;
V_10 -> V_374 = V_374 ;
F_218 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_220 ( struct V_360 * V_160 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
int V_392 = 0 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
if ( ! V_10 -> V_374 )
F_39 ( V_10 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_392 ;
}
static int F_221 ( struct V_377 * V_378 ,
struct V_393 * V_394 )
{
struct V_10 * V_10 = V_394 -> V_395 ;
struct V_396 * V_397 = F_222 ( V_378 , V_398 ) ;
if ( V_10 -> V_13 == V_18 ) {
unsigned int V_399 [ 3 ] ;
V_399 [ 0 ] = V_10 -> V_400 ;
V_399 [ 1 ] = V_10 -> V_401 ;
V_399 [ 2 ] = V_10 -> V_402 ;
return F_223 ( V_397 , 3 , V_399 , 0 ) ;
} else {
unsigned int V_399 [ 2 ] ;
V_399 [ 0 ] = V_10 -> V_401 ;
V_399 [ 1 ] = V_10 -> V_402 ;
return F_223 ( V_397 , 2 , V_399 , 0 ) ;
}
}
static int F_224 ( struct V_377 * V_378 ,
struct V_393 * V_394 )
{
unsigned int V_399 [ 3 ] ;
struct V_10 * V_10 = V_394 -> V_395 ;
struct V_396 * V_397 = F_222 ( V_378 , V_398 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_399 [ 0 ] = V_10 -> V_403 ;
V_399 [ 1 ] = V_10 -> V_404 ;
V_399 [ 2 ] = V_10 -> V_405 ;
return F_223 ( V_397 , 3 , V_399 , 0 ) ;
} else {
V_399 [ 0 ] = V_10 -> V_404 ;
V_399 [ 1 ] = V_10 -> V_405 ;
}
return F_223 ( V_397 , 2 , V_399 , 0 ) ;
}
static int F_225 ( struct V_377 * V_378 ,
struct V_393 * V_394 )
{
struct V_10 * V_10 = V_394 -> V_395 ;
struct V_396 * V_397 = F_222 ( V_378 , V_398 ) ;
struct V_396 * V_406 = F_222 ( V_378 , V_381 ) ;
if ( V_406 -> V_264 > 96000 && V_10 -> V_13 == V_18 ) {
struct V_396 V_407 = {
. V_264 = V_10 -> V_400 ,
. V_248 = V_10 -> V_400 ,
. integer = 1 ,
} ;
return F_226 ( V_397 , & V_407 ) ;
} else if ( V_406 -> V_264 > 48000 && V_406 -> V_248 <= 96000 ) {
struct V_396 V_407 = {
. V_264 = V_10 -> V_401 ,
. V_248 = V_10 -> V_401 ,
. integer = 1 ,
} ;
return F_226 ( V_397 , & V_407 ) ;
} else if ( V_406 -> V_248 < 64000 ) {
struct V_396 V_407 = {
. V_264 = V_10 -> V_402 ,
. V_248 = V_10 -> V_402 ,
. integer = 1 ,
} ;
return F_226 ( V_397 , & V_407 ) ;
}
return 0 ;
}
static int F_227 ( struct V_377 * V_378 ,
struct V_393 * V_394 )
{
struct V_10 * V_10 = V_394 -> V_395 ;
struct V_396 * V_397 = F_222 ( V_378 , V_398 ) ;
struct V_396 * V_406 = F_222 ( V_378 , V_381 ) ;
if ( V_406 -> V_264 > 96000 && V_10 -> V_13 == V_18 ) {
struct V_396 V_407 = {
. V_264 = V_10 -> V_403 ,
. V_248 = V_10 -> V_403 ,
. integer = 1 ,
} ;
return F_226 ( V_397 , & V_407 ) ;
} else if ( V_406 -> V_264 > 48000 && V_406 -> V_248 <= 96000 ) {
struct V_396 V_407 = {
. V_264 = V_10 -> V_404 ,
. V_248 = V_10 -> V_404 ,
. integer = 1 ,
} ;
return F_226 ( V_397 , & V_407 ) ;
} else if ( V_406 -> V_248 < 64000 ) {
struct V_396 V_407 = {
. V_264 = V_10 -> V_405 ,
. V_248 = V_10 -> V_405 ,
. integer = 1 ,
} ;
return F_226 ( V_397 , & V_407 ) ;
}
return 0 ;
}
static int F_228 ( struct V_377 * V_378 ,
struct V_393 * V_394 )
{
struct V_10 * V_10 = V_394 -> V_395 ;
struct V_396 * V_397 = F_222 ( V_378 , V_398 ) ;
struct V_396 * V_406 = F_222 ( V_378 , V_381 ) ;
if ( V_397 -> V_264 >= V_10 -> V_405 ) {
struct V_396 V_407 = {
. V_264 = 32000 ,
. V_248 = 48000 ,
. integer = 1 ,
} ;
return F_226 ( V_406 , & V_407 ) ;
} else if ( V_397 -> V_248 <= V_10 -> V_403 && V_10 -> V_13 == V_18 ) {
struct V_396 V_407 = {
. V_264 = 128000 ,
. V_248 = 192000 ,
. integer = 1 ,
} ;
return F_226 ( V_406 , & V_407 ) ;
} else if ( V_397 -> V_248 <= V_10 -> V_404 ) {
struct V_396 V_407 = {
. V_264 = 64000 ,
. V_248 = 96000 ,
. integer = 1 ,
} ;
return F_226 ( V_406 , & V_407 ) ;
}
return 0 ;
}
static int F_229 ( struct V_377 * V_378 ,
struct V_393 * V_394 )
{
struct V_10 * V_10 = V_394 -> V_395 ;
struct V_396 * V_397 = F_222 ( V_378 , V_398 ) ;
struct V_396 * V_406 = F_222 ( V_378 , V_381 ) ;
if ( V_397 -> V_264 >= V_10 -> V_402 ) {
struct V_396 V_407 = {
. V_264 = 32000 ,
. V_248 = 48000 ,
. integer = 1 ,
} ;
return F_226 ( V_406 , & V_407 ) ;
} else if ( V_397 -> V_248 <= V_10 -> V_400 && V_10 -> V_13 == V_18 ) {
struct V_396 V_407 = {
. V_264 = 128000 ,
. V_248 = 192000 ,
. integer = 1 ,
} ;
return F_226 ( V_406 , & V_407 ) ;
} else if ( V_397 -> V_248 <= V_10 -> V_401 ) {
struct V_396 V_407 = {
. V_264 = 64000 ,
. V_248 = 96000 ,
. integer = 1 ,
} ;
return F_226 ( V_406 , & V_407 ) ;
}
return 0 ;
}
static int F_230 ( struct V_360 * V_160 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
struct V_371 * V_372 = V_160 -> V_372 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
F_231 ( V_160 ) ;
V_372 -> V_408 = V_409 ;
V_372 -> V_410 = V_10 -> V_105 ;
V_372 -> V_411 = V_106 ;
V_10 -> V_67 = V_412 -> V_413 ;
V_10 -> V_358 = V_160 ;
F_46 ( & V_10 -> V_49 ) ;
F_232 ( V_372 , 0 , 32 , 24 ) ;
F_233 ( V_372 , 0 , V_382 , & V_414 ) ;
if ( V_10 -> V_220 ) {
V_372 -> V_408 . V_415 = V_372 -> V_408 . V_416 = V_10 -> V_119 ;
} else if ( V_10 -> V_13 == V_18 ) {
V_372 -> V_408 . V_416 = 192000 ;
V_372 -> V_408 . V_417 = V_418 ;
F_233 ( V_372 , 0 , V_381 , & V_419 ) ;
}
if ( V_10 -> V_13 == V_18 ) {
V_372 -> V_408 . V_420 = V_10 -> V_403 ;
V_372 -> V_408 . V_421 = V_10 -> V_405 ;
}
F_234 ( V_372 , 0 , V_398 ,
F_224 , V_10 ,
V_398 , - 1 ) ;
F_234 ( V_372 , 0 , V_398 ,
F_227 , V_10 ,
V_381 , - 1 ) ;
F_234 ( V_372 , 0 , V_381 ,
F_228 , V_10 ,
V_398 , - 1 ) ;
if ( V_16 != V_10 -> V_13 ) {
V_10 -> V_201 = V_10 -> V_199 ;
V_10 -> V_298 -> V_422 [ 0 ] . V_423 &= ~ V_424 ;
F_235 ( V_10 -> V_26 , V_425 |
V_426 , & V_10 -> V_298 -> V_139 ) ;
}
return 0 ;
}
static int F_236 ( struct V_360 * V_160 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_10 -> V_67 = - 1 ;
V_10 -> V_358 = NULL ;
F_46 ( & V_10 -> V_49 ) ;
if ( V_16 != V_10 -> V_13 ) {
V_10 -> V_298 -> V_422 [ 0 ] . V_423 |= V_424 ;
F_235 ( V_10 -> V_26 , V_425 |
V_426 , & V_10 -> V_298 -> V_139 ) ;
}
return 0 ;
}
static int F_237 ( struct V_360 * V_160 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
struct V_371 * V_372 = V_160 -> V_372 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
F_231 ( V_160 ) ;
V_372 -> V_408 = V_427 ;
V_372 -> V_410 = V_10 -> V_313 ;
V_372 -> V_411 = V_106 ;
V_10 -> V_68 = V_412 -> V_413 ;
V_10 -> V_354 = V_160 ;
F_46 ( & V_10 -> V_49 ) ;
F_232 ( V_372 , 0 , 32 , 24 ) ;
F_233 ( V_372 , 0 , V_382 , & V_414 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_372 -> V_408 . V_420 = V_10 -> V_400 ;
V_372 -> V_408 . V_421 = V_10 -> V_402 ;
V_372 -> V_408 . V_416 = 192000 ;
V_372 -> V_408 . V_417 = V_418 ;
F_233 ( V_372 , 0 , V_381 , & V_419 ) ;
}
F_234 ( V_372 , 0 , V_398 ,
F_221 , V_10 ,
V_398 , - 1 ) ;
F_234 ( V_372 , 0 , V_398 ,
F_225 , V_10 ,
V_381 , - 1 ) ;
F_234 ( V_372 , 0 , V_381 ,
F_229 , V_10 ,
V_398 , - 1 ) ;
return 0 ;
}
static int F_238 ( struct V_360 * V_160 )
{
struct V_10 * V_10 = F_197 ( V_160 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_10 -> V_68 = - 1 ;
V_10 -> V_354 = NULL ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static inline int F_239 ( void T_6 * V_428 , void T_8 * V_366 )
{
T_2 V_21 = F_11 ( V_366 ) ;
return F_203 ( V_428 , & V_21 , 4 ) ;
}
static inline int F_240 ( void T_6 * V_428 , void T_8 * V_429 , void T_8 * V_430 )
{
T_2 V_431 , V_432 ;
T_4 V_433 ;
V_431 = F_11 ( V_429 ) ;
V_432 = F_11 ( V_430 ) ;
V_433 = ( ( T_4 ) V_432 << 32 ) | V_431 ;
return F_203 ( V_428 , & V_433 , 8 ) ;
}
static inline int F_241 ( void T_6 * V_428 , void T_8 * V_429 , void T_8 * V_430 )
{
T_2 V_431 , V_432 ;
T_4 V_433 ;
V_431 = F_11 ( V_429 ) & 0xffffff00 ;
V_432 = F_11 ( V_430 ) & 0xffffff00 ;
V_433 = ( ( T_4 ) V_432 << 32 ) | V_431 ;
return F_203 ( V_428 , & V_433 , 8 ) ;
}
static int F_242 ( struct V_10 * V_10 , struct V_434 T_6 * V_435 )
{
int V_436 = 0 ;
int V_23 , V_437 , V_438 , V_439 ;
if ( F_10 ( V_10 , V_24 ) & V_440 )
V_436 = 1 ;
V_438 = V_436 ? 14 : 26 ;
for ( V_23 = 0 , V_437 = 0 ; V_23 < 26 ; ++ V_23 ) {
if ( V_436 && ( V_23 & 4 ) )
continue;
V_439 = V_441 - V_437 * 4 ;
if ( F_239 ( & V_435 -> V_442 [ V_23 ] , V_10 -> V_22 + V_439 ) )
return - V_369 ;
V_439 -= V_438 * 4 ;
if ( F_239 ( & V_435 -> V_443 [ V_23 ] , V_10 -> V_22 + V_439 ) )
return - V_369 ;
V_439 -= V_438 * 4 ;
if ( F_239 ( & V_435 -> V_444 [ V_23 ] , V_10 -> V_22 + V_439 ) )
return - V_369 ;
V_439 = V_445 + V_437 * 8 ;
if ( F_241 ( & V_435 -> V_446 [ V_23 ] , V_10 -> V_22 + V_439 ,
V_10 -> V_22 + V_439 + 4 ) )
return - V_369 ;
V_439 += V_438 * 8 ;
if ( F_241 ( & V_435 -> V_447 [ V_23 ] , V_10 -> V_22 + V_439 ,
V_10 -> V_22 + V_439 + 4 ) )
return - V_369 ;
V_439 += V_438 * 8 ;
if ( F_241 ( & V_435 -> V_448 [ V_23 ] , V_10 -> V_22 + V_439 ,
V_10 -> V_22 + V_439 + 4 ) )
return - V_369 ;
V_437 ++ ;
}
return 0 ;
}
static int F_243 ( struct V_10 * V_10 , struct V_434 T_6 * V_435 )
{
int V_23 , V_437 ;
struct V_449 T_8 * V_450 ;
int V_436 = 0 ;
if ( F_10 ( V_10 , V_24 ) & V_440 )
V_436 = 1 ;
V_450 = (struct V_449 T_8 * ) ( V_10 -> V_22 + V_451 ) ;
for ( V_23 = 0 , V_437 = 0 ; V_23 < 16 ; ++ V_23 , ++ V_437 ) {
if ( F_239 ( & V_435 -> V_442 [ V_23 ] , & V_450 -> V_452 [ V_437 ] ) )
return - V_369 ;
if ( F_239 ( & V_435 -> V_443 [ V_23 ] , & V_450 -> V_453 [ V_437 ] ) )
return - V_369 ;
if ( F_239 ( & V_435 -> V_444 [ V_23 ] , & V_450 -> V_454 [ V_437 ] ) )
return - V_369 ;
if ( F_240 ( & V_435 -> V_446 [ V_23 ] , & V_450 -> V_455 [ V_437 ] ,
& V_450 -> V_456 [ V_437 ] ) )
return - V_369 ;
if ( F_240 ( & V_435 -> V_447 [ V_23 ] , & V_450 -> V_457 [ V_437 ] ,
& V_450 -> V_458 [ V_437 ] ) )
return - V_369 ;
if ( F_240 ( & V_435 -> V_448 [ V_23 ] , & V_450 -> V_459 [ V_437 ] ,
& V_450 -> V_460 [ V_437 ] ) )
return - V_369 ;
if ( V_436 && V_23 == 3 ) V_23 += 4 ;
}
return 0 ;
}
static int F_244 ( struct V_10 * V_10 , struct V_434 T_6 * V_435 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < 26 ; V_23 ++ ) {
if ( F_239 ( & V_435 -> V_443 [ V_23 ] ,
V_10 -> V_22 + V_461 + V_23 * 4 ) )
return - V_369 ;
if ( F_239 ( & V_435 -> V_442 [ V_23 ] ,
V_10 -> V_22 + V_462 + V_23 * 4 ) )
return - V_369 ;
}
for ( V_23 = 0 ; V_23 < 28 ; V_23 ++ ) {
if ( F_239 ( & V_435 -> V_444 [ V_23 ] ,
V_10 -> V_22 + V_463 + V_23 * 4 ) )
return - V_369 ;
}
for ( V_23 = 0 ; V_23 < 26 ; ++ V_23 ) {
if ( F_240 ( & V_435 -> V_447 [ V_23 ] ,
V_10 -> V_22 + V_464 + V_23 * 8 + 4 ,
V_10 -> V_22 + V_464 + V_23 * 8 ) )
return - V_369 ;
if ( F_240 ( & V_435 -> V_446 [ V_23 ] ,
V_10 -> V_22 + V_465 + V_23 * 8 + 4 ,
V_10 -> V_22 + V_465 + V_23 * 8 ) )
return - V_369 ;
}
return 0 ;
}
static int F_245 ( struct V_466 * V_408 , struct V_467 * V_467 , unsigned int V_386 , unsigned long V_340 )
{
struct V_10 * V_10 = V_408 -> V_164 ;
void T_6 * V_468 = ( void T_6 * ) V_340 ;
int V_294 ;
switch ( V_386 ) {
case V_469 : {
struct V_434 T_6 * V_435 = (struct V_434 T_6 * ) V_340 ;
V_294 = F_12 ( V_10 ) ;
if ( V_294 < 0 )
return V_294 ;
V_294 = F_26 ( V_10 , 1 ) ;
if ( V_294 < 0 )
return V_294 ;
if ( ! ( V_10 -> V_27 & V_28 ) ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_174 ) ;
return - V_120 ;
}
switch ( V_10 -> V_13 ) {
case V_19 :
return F_242 ( V_10 , V_435 ) ;
case V_18 :
return F_243 ( V_10 , V_435 ) ;
default:
return F_244 ( V_10 , V_435 ) ;
}
}
case V_470 : {
struct V_471 V_384 ;
unsigned long V_32 ;
int V_23 ;
V_294 = F_12 ( V_10 ) ;
if ( V_294 < 0 )
return V_294 ;
V_294 = F_26 ( V_10 , 1 ) ;
if ( V_294 < 0 )
return V_294 ;
memset ( & V_384 , 0 , sizeof( V_384 ) ) ;
F_22 ( & V_10 -> V_49 , V_32 ) ;
V_384 . V_306 = ( unsigned char ) F_130 ( V_10 ) ;
V_384 . V_472 = ( unsigned char ) F_147 ( V_10 ) ;
if ( V_10 -> V_13 != V_18 )
V_384 . V_473 = ( unsigned char ) F_151 ( V_10 ) ;
V_384 . V_474 = ( unsigned char ) F_149 ( V_10 ) ;
for ( V_23 = 0 ; V_23 < ( ( V_10 -> V_13 != V_14 && V_10 -> V_13 != V_16 && V_10 -> V_13 != V_18 ) ? 3 : 1 ) ; ++ V_23 )
V_384 . V_475 [ V_23 ] = ( unsigned char ) F_153 ( V_10 , V_23 ) ;
V_384 . V_476 = ( unsigned char ) F_87 ( V_10 ) ;
V_384 . V_477 = ( unsigned char ) F_95 ( V_10 ,
V_324 ) ;
V_384 . V_478 = ( unsigned char )
F_95 ( V_10 , V_184 ) ;
V_384 . V_479 = ( unsigned char )
F_95 ( V_10 , V_188 ) ;
V_384 . V_480 = ( unsigned char )
F_95 ( V_10 , V_186 ) ;
V_384 . V_481 = F_33 ( V_10 ) ;
V_384 . V_119 = V_10 -> V_119 ;
V_384 . V_482 = F_34 ( V_10 ) ;
V_384 . V_308 = ( unsigned char ) F_105 ( V_10 ) ;
V_384 . V_309 = ( unsigned char ) F_108 ( V_10 ) ;
V_384 . V_307 = ( unsigned char ) F_35 ( V_10 ) ;
V_384 . V_483 = ( unsigned char )
F_95 ( V_10 , V_316 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_384 . V_484 = ( unsigned char ) F_115 ( V_10 ) ;
V_384 . V_485 = ( unsigned char ) F_120 ( V_10 ) ;
V_384 . V_486 = ( unsigned char ) F_125 ( V_10 ) ;
V_384 . V_487 =
( unsigned char ) F_95 ( V_10 ,
V_330 ) ;
} else if ( V_10 -> V_13 == V_16 ) {
V_384 . V_484 = ( unsigned char ) F_160 ( V_10 ) ;
V_384 . V_485 = ( unsigned char ) F_165 ( V_10 ) ;
}
if ( V_10 -> V_13 == V_18 || V_10 -> V_13 == V_19 )
V_384 . V_488 =
( unsigned char ) F_95 ( V_10 ,
V_331 ) ;
F_24 ( & V_10 -> V_49 , V_32 ) ;
if ( F_203 ( V_468 , & V_384 , sizeof( V_384 ) ) )
return - V_369 ;
break;
}
case V_489 : {
struct V_490 V_491 ;
if ( V_10 -> V_13 != V_18 ) return - V_120 ;
V_491 . V_492 = V_10 -> V_402 - V_493 ;
V_491 . V_494 = V_10 -> V_405 - V_493 ;
if ( F_203 ( V_468 , & V_491 , sizeof( V_491 ) ) )
return - V_369 ;
break;
}
case V_495 : {
struct V_496 V_496 ;
int V_294 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) return - V_120 ;
if ( V_10 -> V_13 == V_497 ) {
if ( ( V_294 = F_25 ( V_10 ) ) < 0 )
return V_294 ;
}
memset ( & V_496 , 0 , sizeof( V_496 ) ) ;
V_496 . V_13 = V_10 -> V_13 ;
V_496 . V_17 = V_10 -> V_17 ;
if ( ( V_294 = F_203 ( V_468 , & V_496 , sizeof( V_496 ) ) ) )
return - V_369 ;
break;
}
case V_498 : {
struct V_499 T_6 * V_35 ;
T_2 T_6 * V_500 ;
int V_294 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) return - V_120 ;
if ( V_10 -> V_13 == V_497 ) return - V_120 ;
if ( V_10 -> V_27 & ( V_58 | V_28 ) )
return - V_130 ;
F_17 ( V_10 -> V_26 -> V_6 ,
L_175 ) ;
V_35 = (struct V_499 T_6 * ) V_468 ;
if ( F_246 ( V_500 , & V_35 -> V_500 ) )
return - V_369 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( ! V_10 -> V_34 ) {
V_10 -> V_34 = F_247 ( V_45 ) ;
if ( ! V_10 -> V_34 )
return - V_8 ;
}
if ( F_200 ( V_10 -> V_34 , V_500 ,
V_45 ) ) {
F_248 ( V_10 -> V_34 ) ;
V_10 -> V_34 = NULL ;
return - V_369 ;
}
V_10 -> V_27 |= V_58 ;
if ( ( V_294 = F_18 ( V_10 ) ) < 0 )
return V_294 ;
if ( ! ( V_10 -> V_27 & V_48 ) ) {
if ( ( V_294 = F_249 ( V_10 ) ) < 0 )
return V_294 ;
F_250 ( V_10 ) ;
F_251 ( V_10 ) ;
if ( ( V_294 = F_252 ( V_10 -> V_26 , V_10 ) ) < 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_176 ) ;
return V_294 ;
}
}
break;
}
case V_501 : {
struct V_502 T_6 * V_503 = (struct V_502 T_6 * ) V_468 ;
if ( F_203 ( V_503 -> V_504 , V_10 -> V_64 , sizeof( unsigned short ) * V_63 ) )
return - V_369 ;
break;
}
default:
return - V_120 ;
}
return 0 ;
}
static int F_253 ( struct V_169 * V_26 , struct V_10 * V_10 )
{
struct V_466 * V_408 ;
int V_294 ;
if ( ( V_294 = F_254 ( V_26 , L_177 , 0 , & V_408 ) ) < 0 )
return V_294 ;
V_10 -> V_505 = V_408 ;
V_408 -> V_164 = V_10 ;
strcpy ( V_408 -> V_172 , L_178 ) ;
V_408 -> V_506 . V_507 = F_245 ;
V_408 -> V_506 . V_508 = F_245 ;
return 0 ;
}
static int F_255 ( struct V_169 * V_26 , struct V_10 * V_10 )
{
struct V_509 * V_355 ;
int V_294 ;
if ( ( V_294 = F_256 ( V_26 , V_10 -> V_311 , 0 , 1 , 1 , & V_355 ) ) < 0 )
return V_294 ;
V_10 -> V_355 = V_355 ;
V_355 -> V_164 = V_10 ;
strcpy ( V_355 -> V_172 , V_10 -> V_311 ) ;
F_257 ( V_355 , V_359 , & V_510 ) ;
F_257 ( V_355 , V_357 , & V_511 ) ;
V_355 -> V_177 = V_512 ;
return 0 ;
}
static void F_191 ( struct V_10 * V_10 )
{
V_10 -> V_46 |= V_513 ;
F_8 ( V_10 , V_39 , V_10 -> V_46 ) ;
}
static int F_249 ( struct V_10 * V_10 )
{
int V_23 ;
if ( F_19 ( V_10 , 0 , 100 ) ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_179 ) ;
return - V_29 ;
}
for ( V_23 = 0 ; V_23 < V_10 -> V_268 ; ++ V_23 ) {
F_8 ( V_10 , V_514 + ( 4 * V_23 ) , 1 ) ;
F_8 ( V_10 , V_515 + ( 4 * V_23 ) , 1 ) ;
}
return 0 ;
}
static void F_250 ( struct V_10 * V_10 )
{
int V_69 , V_516 , V_517 ;
switch ( V_10 -> V_13 ) {
case V_15 :
V_10 -> V_311 = L_180 ;
V_10 -> V_402 = V_10 -> V_405 = V_518 ;
V_10 -> V_401 = V_10 -> V_404 = V_519 ;
break;
case V_19 :
V_10 -> V_311 = L_181 ;
V_10 -> V_402 = V_10 -> V_405 = V_520 ;
V_10 -> V_401 = V_10 -> V_404 = V_521 ;
break;
case V_18 :
V_69 = F_10 ( V_10 , V_24 ) ;
V_516 = ( V_69 & V_522 ) ? 0 : 4 ;
V_517 = ( V_69 & V_523 ) ? 0 : 4 ;
V_10 -> V_311 = L_182 ;
V_10 -> V_402 = V_493 + V_516 ;
V_10 -> V_401 = V_524 + V_516 ;
V_10 -> V_400 = V_525 + V_516 ;
V_10 -> V_405 = V_493 + V_517 ;
V_10 -> V_404 = V_524 + V_517 ;
V_10 -> V_403 = V_525 + V_517 ;
break;
case V_14 :
V_10 -> V_311 = L_183 ;
V_10 -> V_402 = V_10 -> V_405 = V_526 ;
V_10 -> V_401 = V_10 -> V_404 = V_527 ;
break;
case V_16 :
V_10 -> V_311 = L_184 ;
V_10 -> V_402 = V_528 - 1 ;
V_10 -> V_405 = V_528 ;
V_10 -> V_401 = V_528 - 1 ;
V_10 -> V_404 = V_528 ;
break;
default:
break;
}
}
static void F_251 ( struct V_10 * V_10 )
{
F_55 ( V_10 , 0 ) ;
F_55 ( V_10 , 1 ) ;
}
static int F_252 ( struct V_169 * V_26 , struct V_10 * V_10 )
{
int V_294 ;
if ( ( V_294 = F_255 ( V_26 , V_10 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_185 ) ;
return V_294 ;
}
if ( ( V_294 = F_72 ( V_26 , V_10 , 0 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_186 ) ;
return V_294 ;
}
if ( V_10 -> V_13 == V_15 || V_10 -> V_13 == V_19 ) {
if ( ( V_294 = F_72 ( V_26 , V_10 , 1 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_187 ) ;
return V_294 ;
}
}
if ( ( V_294 = F_179 ( V_26 , V_10 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_188 ) ;
return V_294 ;
}
F_185 ( V_10 ) ;
V_10 -> V_119 = - 1 ;
V_10 -> V_67 = - 1 ;
V_10 -> V_68 = - 1 ;
V_10 -> V_354 = NULL ;
V_10 -> V_358 = NULL ;
if ( ( V_294 = F_23 ( V_10 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_189 ) ;
return V_294 ;
}
if ( ! ( V_10 -> V_27 & V_48 ) ) {
strcpy ( V_26 -> V_171 , L_190 ) ;
sprintf ( V_26 -> V_529 , L_191 , V_10 -> V_311 ,
V_10 -> V_315 , V_10 -> V_314 ) ;
if ( ( V_294 = F_258 ( V_26 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_192 ) ;
return V_294 ;
}
V_10 -> V_27 |= V_48 ;
}
return 0 ;
}
static int F_27 ( struct V_10 * V_10 )
{
const char * V_530 ;
const struct V_35 * V_531 ;
int V_294 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
if ( V_10 -> V_13 == V_497 ) {
if ( ( V_294 = F_25 ( V_10 ) ) < 0 )
return V_294 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
}
switch ( V_10 -> V_13 ) {
case V_16 :
V_530 = L_193 ;
break;
case V_14 :
if ( V_10 -> V_17 == 0xa )
V_530 = L_194 ;
else
V_530 = L_195 ;
break;
case V_15 :
if ( V_10 -> V_17 == 0xa )
V_530 = L_196 ;
else
V_530 = L_197 ;
break;
default:
F_15 ( V_10 -> V_26 -> V_6 ,
L_198 , V_10 -> V_13 ) ;
return - V_120 ;
}
if ( F_259 ( & V_531 , V_530 , & V_10 -> V_2 -> V_6 ) ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_199 , V_530 ) ;
return - V_532 ;
}
if ( V_531 -> V_5 < V_45 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_200 ,
( int ) V_531 -> V_5 , V_45 ) ;
F_260 ( V_531 ) ;
return - V_120 ;
}
V_10 -> V_35 = V_531 ;
V_10 -> V_27 |= V_58 ;
if ( ( V_294 = F_18 ( V_10 ) ) < 0 )
return V_294 ;
if ( ! ( V_10 -> V_27 & V_48 ) ) {
if ( ( V_294 = F_249 ( V_10 ) ) < 0 )
return V_294 ;
if ( ( V_294 = F_253 ( V_10 -> V_26 , V_10 ) ) < 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_201 ) ;
return V_294 ;
}
F_250 ( V_10 ) ;
F_251 ( V_10 ) ;
if ( ( V_294 = F_252 ( V_10 -> V_26 , V_10 ) ) < 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_176 ) ;
return V_294 ;
}
}
return 0 ;
}
static int F_261 ( struct V_169 * V_26 ,
struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_294 ;
int V_533 = 0 ;
int V_534 = 0 ;
V_10 -> V_314 = - 1 ;
V_10 -> V_27 = 0 ;
V_10 -> V_170 [ 0 ] . V_163 = NULL ;
V_10 -> V_170 [ 1 ] . V_163 = NULL ;
V_10 -> V_170 [ 0 ] . V_155 = NULL ;
V_10 -> V_170 [ 1 ] . V_155 = NULL ;
V_10 -> V_170 [ 0 ] . V_154 = NULL ;
V_10 -> V_170 [ 1 ] . V_154 = NULL ;
V_10 -> V_170 [ 0 ] . V_156 = 0 ;
V_10 -> V_170 [ 1 ] . V_156 = 0 ;
F_73 ( & V_10 -> V_170 [ 0 ] . V_49 ) ;
F_73 ( & V_10 -> V_170 [ 1 ] . V_49 ) ;
V_10 -> V_22 = NULL ;
V_10 -> V_93 = 0 ;
V_10 -> V_46 = 0 ;
V_10 -> V_13 = V_497 ;
V_10 -> V_268 = 26 ;
V_10 -> V_26 = V_26 ;
F_73 ( & V_10 -> V_49 ) ;
F_262 ( & V_10 -> V_165 , F_192 , ( unsigned long ) V_10 ) ;
F_263 ( V_10 -> V_2 , V_535 , & V_10 -> V_17 ) ;
V_10 -> V_17 &= 0xff ;
F_264 ( V_10 -> V_2 , V_536 , 0xFF ) ;
strcpy ( V_26 -> V_537 , L_202 ) ;
strcpy ( V_26 -> V_538 , L_203 ) ;
if ( V_10 -> V_17 < 0xa )
return - V_36 ;
else if ( V_10 -> V_17 < 0x64 )
V_10 -> V_311 = L_204 ;
else if ( V_10 -> V_17 < 0x96 ) {
V_10 -> V_311 = L_205 ;
V_533 = 1 ;
} else {
V_10 -> V_311 = L_206 ;
V_10 -> V_268 = 16 ;
V_534 = 1 ;
}
if ( ( V_294 = F_265 ( V_2 ) ) < 0 )
return V_294 ;
F_266 ( V_10 -> V_2 ) ;
if ( ( V_294 = F_267 ( V_2 , L_172 ) ) < 0 )
return V_294 ;
V_10 -> V_315 = F_268 ( V_2 , 0 ) ;
if ( ( V_10 -> V_22 = F_269 ( V_10 -> V_315 , V_539 ) ) == NULL ) {
F_15 ( V_10 -> V_26 -> V_6 , L_207 ,
V_10 -> V_315 , V_10 -> V_315 + V_539 - 1 ) ;
return - V_130 ;
}
if ( F_270 ( V_2 -> V_314 , F_193 , V_540 ,
V_541 , V_10 ) ) {
F_15 ( V_10 -> V_26 -> V_6 , L_208 , V_2 -> V_314 ) ;
return - V_130 ;
}
V_10 -> V_314 = V_2 -> V_314 ;
V_10 -> V_95 = 0 ;
V_10 -> V_263 = 1 ;
V_10 -> V_100 = 0 ;
if ( ( V_294 = F_189 ( V_10 ) ) < 0 )
return V_294 ;
if ( ! V_533 && ! V_534 ) {
V_294 = F_16 ( V_10 , 1000 , 10 ) ;
if ( V_294 < 0 )
return V_294 ;
if ( ( F_10 ( V_10 , V_24 ) & V_38 ) != 0 ) {
if ( ( V_294 = F_27 ( V_10 ) ) < 0 )
F_15 ( V_10 -> V_26 -> V_6 ,
L_209 ) ;
else
return 0 ;
F_17 ( V_10 -> V_26 -> V_6 ,
L_210 ) ;
if ( ( V_294 = F_253 ( V_26 , V_10 ) ) < 0 )
return V_294 ;
return 0 ;
} else {
F_17 ( V_10 -> V_26 -> V_6 ,
L_211 ) ;
if ( F_10 ( V_10 , V_54 ) & V_55 )
V_10 -> V_13 = V_16 ;
else if ( F_10 ( V_10 , V_54 ) & V_56 )
V_10 -> V_13 = V_14 ;
else
V_10 -> V_13 = V_15 ;
}
}
if ( ( V_294 = F_249 ( V_10 ) ) != 0 )
return V_294 ;
if ( V_533 )
V_10 -> V_13 = V_19 ;
if ( V_534 )
V_10 -> V_13 = V_18 ;
if ( ( V_294 = F_253 ( V_26 , V_10 ) ) < 0 )
return V_294 ;
F_250 ( V_10 ) ;
F_251 ( V_10 ) ;
V_10 -> V_27 |= V_28 ;
if ( ( V_294 = F_252 ( V_26 , V_10 ) ) < 0 )
return V_294 ;
return 0 ;
}
static int F_271 ( struct V_10 * V_10 )
{
if ( V_10 -> V_315 ) {
F_62 ( & V_10 -> V_165 ) ;
V_10 -> V_93 &= ~ ( V_103 | V_102 | V_158 | V_157 ) ;
F_8 ( V_10 , V_104 , V_10 -> V_93 ) ;
}
if ( V_10 -> V_314 >= 0 )
F_272 ( V_10 -> V_314 , ( void * ) V_10 ) ;
F_188 ( V_10 ) ;
F_260 ( V_10 -> V_35 ) ;
F_248 ( V_10 -> V_34 ) ;
F_273 ( V_10 -> V_22 ) ;
if ( V_10 -> V_315 )
F_274 ( V_10 -> V_2 ) ;
F_275 ( V_10 -> V_2 ) ;
return 0 ;
}
static void F_276 ( struct V_169 * V_26 )
{
struct V_10 * V_10 = V_26 -> V_164 ;
if ( V_10 )
F_271 ( V_10 ) ;
}
static int F_277 ( struct V_1 * V_2 ,
const struct V_542 * V_543 )
{
static int V_6 ;
struct V_10 * V_10 ;
struct V_169 * V_26 ;
int V_294 ;
if ( V_6 >= V_544 )
return - V_36 ;
if ( ! V_545 [ V_6 ] ) {
V_6 ++ ;
return - V_532 ;
}
V_294 = F_278 ( & V_2 -> V_6 , V_279 [ V_6 ] , V_139 [ V_6 ] , V_546 ,
sizeof( struct V_10 ) , & V_26 ) ;
if ( V_294 < 0 )
return V_294 ;
V_10 = V_26 -> V_164 ;
V_26 -> V_547 = F_276 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_2 = V_2 ;
V_294 = F_261 ( V_26 , V_10 ) ;
if ( V_294 )
goto V_548;
strcpy ( V_26 -> V_171 , L_190 ) ;
sprintf ( V_26 -> V_529 , L_191 , V_10 -> V_311 ,
V_10 -> V_315 , V_10 -> V_314 ) ;
V_294 = F_258 ( V_26 ) ;
if ( V_294 ) {
V_548:
F_279 ( V_26 ) ;
return V_294 ;
}
F_280 ( V_2 , V_26 ) ;
V_6 ++ ;
return 0 ;
}
static void F_281 ( struct V_1 * V_2 )
{
F_279 ( F_282 ( V_2 ) ) ;
}
