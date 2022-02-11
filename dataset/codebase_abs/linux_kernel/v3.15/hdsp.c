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
if ( F_19 ( V_10 , 0 , V_50 ) < 0 ) {
V_10 -> V_13 = V_14 ;
F_17 ( V_10 -> V_26 -> V_6 , L_9 ) ;
return 0 ;
}
F_8 ( V_10 , V_39 , V_44 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_19 ( V_10 , 0 , V_50 ) == 0 ) {
V_10 -> V_13 = V_15 ;
F_17 ( V_10 -> V_26 -> V_6 , L_10 ) ;
return 0 ;
}
F_8 ( V_10 , V_39 , V_51 ) ;
F_8 ( V_10 , V_39 , V_44 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_19 ( V_10 , 0 , V_50 ) == 0 ) {
V_10 -> V_13 = V_14 ;
F_17 ( V_10 -> V_26 -> V_6 , L_9 ) ;
return 0 ;
}
F_8 ( V_10 , V_39 , V_51 ) ;
F_8 ( V_10 , V_39 , V_44 ) ;
F_8 ( V_10 , V_41 , 0 ) ;
if ( F_19 ( V_10 , 0 , V_50 ) < 0 ) {
V_10 -> V_13 = V_14 ;
F_17 ( V_10 -> V_26 -> V_6 , L_9 ) ;
return 0 ;
}
V_10 -> V_13 = V_16 ;
F_17 ( V_10 -> V_26 -> V_6 , L_11 ) ;
return 0 ;
} else {
if ( F_10 ( V_10 , V_53 ) & V_54 )
V_10 -> V_13 = V_16 ;
else if ( F_10 ( V_10 , V_53 ) & V_55 )
V_10 -> V_13 = V_14 ;
else
V_10 -> V_13 = V_15 ;
}
return 0 ;
}
static int F_26 ( struct V_10 * V_10 , int V_56 )
{
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
if ( ( F_10 ( V_10 , V_24 ) & V_38 ) != 0 ) {
V_10 -> V_27 &= ~ V_28 ;
if ( ! V_56 )
return - V_29 ;
F_15 ( V_10 -> V_26 -> V_6 , L_12 ) ;
if ( ! ( V_10 -> V_27 & V_57 ) ) {
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
static int F_19 ( struct V_10 * V_10 , int V_58 , int V_59 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_59 ; V_23 ++ ) {
if ( ( int ) ( F_10 ( V_10 , V_60 ) & 0xff ) <= V_58 )
return 0 ;
F_28 ( 100 ) ;
}
F_29 ( V_10 -> V_26 -> V_6 ,
L_15 ,
V_58 , V_59 ) ;
return - 1 ;
}
static int F_30 ( struct V_10 * V_10 , unsigned int V_61 )
{
if ( V_61 >= V_62 )
return 0 ;
return V_10 -> V_63 [ V_61 ] ;
}
static int F_31 ( struct V_10 * V_10 , unsigned int V_61 , unsigned short V_37 )
{
unsigned int V_64 ;
if ( V_61 >= V_62 )
return - 1 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) {
if ( V_10 -> V_13 == V_18 && V_61 >= 512 )
return 0 ;
if ( V_10 -> V_13 == V_19 && V_61 >= 1352 )
return 0 ;
V_10 -> V_63 [ V_61 ] = V_37 ;
V_64 = V_61 / 2 ;
F_8 ( V_10 , 4096 + ( V_64 * 4 ) ,
( V_10 -> V_63 [ ( V_61 & 0x7fe ) + 1 ] << 16 ) +
V_10 -> V_63 [ V_61 & 0x7fe ] ) ;
return 0 ;
} else {
V_64 = ( V_61 << 16 ) + V_37 ;
if ( F_19 ( V_10 , 127 , V_42 ) )
return - 1 ;
F_8 ( V_10 , V_41 , V_64 ) ;
V_10 -> V_63 [ V_61 ] = V_37 ;
}
return 0 ;
}
static int F_32 ( struct V_10 * V_10 )
{
unsigned long V_32 ;
int V_65 = 1 ;
F_22 ( & V_10 -> V_49 , V_32 ) ;
if ( ( V_10 -> V_66 != V_10 -> V_67 ) &&
( V_10 -> V_66 >= 0 ) && ( V_10 -> V_67 >= 0 ) )
V_65 = 0 ;
F_24 ( & V_10 -> V_49 , V_32 ) ;
return V_65 ;
}
static int F_33 ( struct V_10 * V_10 )
{
unsigned int V_68 = F_10 ( V_10 , V_24 ) ;
unsigned int V_69 = ( V_68 & V_70 ) ;
if ( V_10 -> V_13 == V_18 )
V_69 = ( V_68 & V_71 ) ;
if ( V_68 & V_72 )
return 0 ;
switch ( V_69 ) {
case V_73 : return 32000 ;
case V_74 : return 44100 ;
case V_75 : return 48000 ;
case V_76 : return 64000 ;
case V_77 : return 88200 ;
case V_78 : return 96000 ;
case V_79 :
if ( V_10 -> V_13 == V_18 ) return 128000 ;
break;
case V_80 :
if ( V_10 -> V_13 == V_18 ) return 176400 ;
break;
case V_81 :
if ( V_10 -> V_13 == V_18 ) return 192000 ;
break;
default:
break;
}
F_29 ( V_10 -> V_26 -> V_6 ,
L_16 ,
V_69 , V_68 ) ;
return 0 ;
}
static int F_34 ( struct V_10 * V_10 )
{
unsigned int V_82 = F_10 ( V_10 , V_53 ) ;
unsigned int V_69 = V_82 & V_83 ;
if ( V_10 -> V_13 == V_18 &&
F_35 ( V_10 ) == V_84 )
return F_33 ( V_10 ) ;
switch ( V_69 ) {
case V_85 : return 32000 ;
case V_86 : return 44100 ;
case V_87 : return 48000 ;
case V_88 : return 64000 ;
case V_89 : return 88200 ;
case V_90 : return 96000 ;
default:
return 0 ;
}
}
static void F_36 ( struct V_10 * V_10 )
{
V_10 -> V_91 = 1 << ( ( F_37 ( V_10 -> V_92 ) + 8 ) ) ;
}
static T_3 F_38 ( struct V_10 * V_10 )
{
int V_93 ;
V_93 = F_10 ( V_10 , V_24 ) ;
if ( ! V_10 -> V_94 )
return ( V_93 & V_95 ) ? ( V_10 -> V_91 / 4 ) : 0 ;
V_93 &= V_96 ;
V_93 /= 4 ;
V_93 &= ( V_10 -> V_91 / 2 ) - 1 ;
return V_93 ;
}
static void F_39 ( struct V_10 * V_10 )
{
F_8 ( V_10 , V_97 , 0 ) ;
if ( V_10 -> V_13 == V_18 && V_10 -> V_17 >= 152 )
F_8 ( V_10 , V_98 , V_10 -> V_99 ) ;
}
static void F_40 ( struct V_10 * V_100 )
{
V_100 -> V_92 |= ( V_101 | V_102 ) ;
F_8 ( V_100 , V_103 , V_100 -> V_92 ) ;
}
static void F_41 ( struct V_10 * V_100 )
{
V_100 -> V_92 &= ~ ( V_102 | V_101 ) ;
F_8 ( V_100 , V_103 , V_100 -> V_92 ) ;
}
static void F_42 ( struct V_10 * V_10 )
{
memset ( V_10 -> V_104 , 0 , V_105 ) ;
}
static int F_43 ( struct V_10 * V_100 , unsigned int V_106 )
{
int V_107 ;
F_44 ( & V_100 -> V_49 ) ;
V_106 >>= 7 ;
V_107 = 0 ;
while ( V_106 ) {
V_107 ++ ;
V_106 >>= 1 ;
}
V_100 -> V_92 &= ~ V_108 ;
V_100 -> V_92 |= F_45 ( V_107 ) ;
F_8 ( V_100 , V_103 , V_100 -> V_92 ) ;
F_36 ( V_100 ) ;
F_46 ( & V_100 -> V_49 ) ;
return 0 ;
}
static void F_47 ( struct V_10 * V_10 , int V_109 )
{
T_4 V_107 ;
if ( V_109 >= 112000 )
V_109 /= 4 ;
else if ( V_109 >= 56000 )
V_109 /= 2 ;
V_107 = V_110 ;
V_107 = F_48 ( V_107 , V_109 ) ;
F_49 ( V_107 >> 32 ) ;
V_10 -> V_99 = V_107 ;
F_8 ( V_10 , V_98 , V_10 -> V_99 ) ;
}
static int F_50 ( struct V_10 * V_10 , int V_109 , int V_111 )
{
int V_112 = 0 ;
int V_113 ;
int V_69 ;
if ( ! ( V_10 -> V_92 & V_114 ) ) {
if ( V_111 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_17 ) ;
return - 1 ;
} else {
int V_115 = F_34 ( V_10 ) ;
int V_116 = F_33 ( V_10 ) ;
if ( ( V_116 == V_115 * 2 ) && ( F_35 ( V_10 ) >= V_117 ) )
F_17 ( V_10 -> V_26 -> V_6 ,
L_18 ) ;
else if ( V_10 -> V_13 == V_18 && ( V_116 == V_115 * 4 ) && ( F_35 ( V_10 ) >= V_117 ) )
F_17 ( V_10 -> V_26 -> V_6 ,
L_19 ) ;
else if ( V_109 != V_115 ) {
F_17 ( V_10 -> V_26 -> V_6 ,
L_20 ) ;
return - 1 ;
}
}
}
V_113 = V_10 -> V_118 ;
if ( V_109 > 96000 && V_10 -> V_13 != V_18 )
return - V_119 ;
switch ( V_109 ) {
case 32000 :
if ( V_113 > 48000 )
V_112 = 1 ;
V_69 = V_120 ;
break;
case 44100 :
if ( V_113 > 48000 )
V_112 = 1 ;
V_69 = V_121 ;
break;
case 48000 :
if ( V_113 > 48000 )
V_112 = 1 ;
V_69 = V_122 ;
break;
case 64000 :
if ( V_113 <= 48000 || V_113 > 96000 )
V_112 = 1 ;
V_69 = V_123 ;
break;
case 88200 :
if ( V_113 <= 48000 || V_113 > 96000 )
V_112 = 1 ;
V_69 = V_124 ;
break;
case 96000 :
if ( V_113 <= 48000 || V_113 > 96000 )
V_112 = 1 ;
V_69 = V_125 ;
break;
case 128000 :
if ( V_113 < 128000 )
V_112 = 1 ;
V_69 = V_126 ;
break;
case 176400 :
if ( V_113 < 128000 )
V_112 = 1 ;
V_69 = V_127 ;
break;
case 192000 :
if ( V_113 < 128000 )
V_112 = 1 ;
V_69 = V_128 ;
break;
default:
return - V_119 ;
}
if ( V_112 && ( V_10 -> V_67 >= 0 || V_10 -> V_66 >= 0 ) ) {
F_29 ( V_10 -> V_26 -> V_6 ,
L_21 ,
V_10 -> V_67 ,
V_10 -> V_66 ) ;
return - V_129 ;
}
V_10 -> V_92 &= ~ V_130 ;
V_10 -> V_92 |= V_69 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
if ( V_10 -> V_13 == V_18 && V_10 -> V_17 >= 152 )
F_47 ( V_10 , V_109 ) ;
if ( V_109 >= 128000 ) {
V_10 -> V_131 = V_132 ;
} else if ( V_109 > 48000 ) {
if ( V_10 -> V_13 == V_18 )
V_10 -> V_131 = V_133 ;
else
V_10 -> V_131 = V_134 ;
} else {
switch ( V_10 -> V_13 ) {
case V_16 :
case V_14 :
V_10 -> V_131 = V_135 ;
break;
case V_15 :
case V_19 :
V_10 -> V_131 = V_136 ;
break;
case V_18 :
V_10 -> V_131 = V_137 ;
break;
default:
break;
}
}
V_10 -> V_118 = V_109 ;
return 0 ;
}
static unsigned char F_51 ( struct V_10 * V_10 , int V_138 )
{
if ( V_138 )
return F_10 ( V_10 , V_139 ) ;
else
return F_10 ( V_10 , V_140 ) ;
}
static void F_52 ( struct V_10 * V_10 , int V_138 , int V_21 )
{
if ( V_138 )
F_8 ( V_10 , V_141 , V_21 ) ;
else
F_8 ( V_10 , V_142 , V_21 ) ;
}
static int F_53 ( struct V_10 * V_10 , int V_138 )
{
if ( V_138 )
return ( F_10 ( V_10 , V_143 ) & 0xff ) ;
else
return ( F_10 ( V_10 , V_144 ) & 0xff ) ;
}
static int F_54 ( struct V_10 * V_10 , int V_138 )
{
int V_145 ;
if ( V_138 )
V_145 = F_10 ( V_10 , V_146 ) & 0xff ;
else
V_145 = F_10 ( V_10 , V_147 ) & 0xff ;
if ( V_145 < 128 )
return 128 - V_145 ;
else
return 0 ;
}
static void F_55 ( struct V_10 * V_10 , int V_138 )
{
while ( F_53 ( V_10 , V_138 ) )
F_51 ( V_10 , V_138 ) ;
}
static int F_56 ( struct V_148 * V_149 )
{
unsigned long V_32 ;
int V_150 ;
int V_151 ;
int V_23 ;
unsigned char V_152 [ 128 ] ;
F_22 ( & V_149 -> V_49 , V_32 ) ;
if ( V_149 -> V_153 ) {
if ( ! F_57 ( V_149 -> V_153 ) ) {
if ( ( V_150 = F_54 ( V_149 -> V_10 , V_149 -> V_138 ) ) > 0 ) {
if ( V_150 > ( int ) sizeof ( V_152 ) )
V_150 = sizeof ( V_152 ) ;
if ( ( V_151 = F_58 ( V_149 -> V_153 , V_152 , V_150 ) ) > 0 ) {
for ( V_23 = 0 ; V_23 < V_151 ; ++ V_23 )
F_52 ( V_149 -> V_10 , V_149 -> V_138 , V_152 [ V_23 ] ) ;
}
}
}
}
F_24 ( & V_149 -> V_49 , V_32 ) ;
return 0 ;
}
static int F_59 ( struct V_148 * V_149 )
{
unsigned char V_152 [ 128 ] ;
unsigned long V_32 ;
int V_150 ;
int V_23 ;
F_22 ( & V_149 -> V_49 , V_32 ) ;
if ( ( V_150 = F_53 ( V_149 -> V_10 , V_149 -> V_138 ) ) > 0 ) {
if ( V_149 -> V_154 ) {
if ( V_150 > ( int ) sizeof ( V_152 ) )
V_150 = sizeof ( V_152 ) ;
for ( V_23 = 0 ; V_23 < V_150 ; ++ V_23 )
V_152 [ V_23 ] = F_51 ( V_149 -> V_10 , V_149 -> V_138 ) ;
if ( V_150 )
F_60 ( V_149 -> V_154 , V_152 , V_150 ) ;
} else {
while ( -- V_150 )
F_51 ( V_149 -> V_10 , V_149 -> V_138 ) ;
}
}
V_149 -> V_155 = 0 ;
if ( V_149 -> V_138 )
V_149 -> V_10 -> V_92 |= V_156 ;
else
V_149 -> V_10 -> V_92 |= V_157 ;
F_8 ( V_149 -> V_10 , V_103 , V_149 -> V_10 -> V_92 ) ;
F_24 ( & V_149 -> V_49 , V_32 ) ;
return F_56 ( V_149 ) ;
}
static void F_61 ( struct V_158 * V_159 , int V_160 )
{
struct V_10 * V_10 ;
struct V_148 * V_149 ;
unsigned long V_32 ;
T_2 V_161 ;
V_149 = (struct V_148 * ) V_159 -> V_162 -> V_163 ;
V_10 = V_149 -> V_10 ;
V_161 = V_149 -> V_138 ? V_156 : V_157 ;
F_22 ( & V_10 -> V_49 , V_32 ) ;
if ( V_160 ) {
if ( ! ( V_10 -> V_92 & V_161 ) ) {
F_55 ( V_10 , V_149 -> V_138 ) ;
V_10 -> V_92 |= V_161 ;
}
} else {
V_10 -> V_92 &= ~ V_161 ;
F_62 ( & V_10 -> V_164 ) ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
F_24 ( & V_10 -> V_49 , V_32 ) ;
}
static void F_63 ( unsigned long V_37 )
{
struct V_148 * V_149 = (struct V_148 * ) V_37 ;
unsigned long V_32 ;
F_56 ( V_149 ) ;
F_22 ( & V_149 -> V_49 , V_32 ) ;
if ( V_149 -> V_165 ) {
V_149 -> V_166 . V_167 = 1 + V_168 ;
F_64 ( & V_149 -> V_166 ) ;
}
F_24 ( & V_149 -> V_49 , V_32 ) ;
}
static void F_65 ( struct V_158 * V_159 , int V_160 )
{
struct V_148 * V_149 ;
unsigned long V_32 ;
V_149 = (struct V_148 * ) V_159 -> V_162 -> V_163 ;
F_22 ( & V_149 -> V_49 , V_32 ) ;
if ( V_160 ) {
if ( ! V_149 -> V_165 ) {
F_66 ( & V_149 -> V_166 ) ;
V_149 -> V_166 . V_169 = F_63 ;
V_149 -> V_166 . V_37 = ( unsigned long ) V_149 ;
V_149 -> V_166 . V_167 = 1 + V_168 ;
F_64 ( & V_149 -> V_166 ) ;
V_149 -> V_165 ++ ;
}
} else {
if ( V_149 -> V_165 && -- V_149 -> V_165 <= 0 )
F_67 ( & V_149 -> V_166 ) ;
}
F_24 ( & V_149 -> V_49 , V_32 ) ;
if ( V_160 )
F_56 ( V_149 ) ;
}
static int F_68 ( struct V_158 * V_159 )
{
struct V_148 * V_149 ;
V_149 = (struct V_148 * ) V_159 -> V_162 -> V_163 ;
F_44 ( & V_149 -> V_49 ) ;
F_55 ( V_149 -> V_10 , V_149 -> V_138 ) ;
V_149 -> V_154 = V_159 ;
F_46 ( & V_149 -> V_49 ) ;
return 0 ;
}
static int F_69 ( struct V_158 * V_159 )
{
struct V_148 * V_149 ;
V_149 = (struct V_148 * ) V_159 -> V_162 -> V_163 ;
F_44 ( & V_149 -> V_49 ) ;
V_149 -> V_153 = V_159 ;
F_46 ( & V_149 -> V_49 ) ;
return 0 ;
}
static int F_70 ( struct V_158 * V_159 )
{
struct V_148 * V_149 ;
F_61 ( V_159 , 0 ) ;
V_149 = (struct V_148 * ) V_159 -> V_162 -> V_163 ;
F_44 ( & V_149 -> V_49 ) ;
V_149 -> V_154 = NULL ;
F_46 ( & V_149 -> V_49 ) ;
return 0 ;
}
static int F_71 ( struct V_158 * V_159 )
{
struct V_148 * V_149 ;
F_65 ( V_159 , 0 ) ;
V_149 = (struct V_148 * ) V_159 -> V_162 -> V_163 ;
F_44 ( & V_149 -> V_49 ) ;
V_149 -> V_153 = NULL ;
F_46 ( & V_149 -> V_49 ) ;
return 0 ;
}
static int F_72 ( struct V_170 * V_26 , struct V_10 * V_10 , int V_138 )
{
char V_152 [ 32 ] ;
V_10 -> V_171 [ V_138 ] . V_138 = V_138 ;
V_10 -> V_171 [ V_138 ] . V_162 = NULL ;
V_10 -> V_171 [ V_138 ] . V_154 = NULL ;
V_10 -> V_171 [ V_138 ] . V_153 = NULL ;
V_10 -> V_171 [ V_138 ] . V_10 = V_10 ;
V_10 -> V_171 [ V_138 ] . V_165 = 0 ;
V_10 -> V_171 [ V_138 ] . V_155 = 0 ;
F_73 ( & V_10 -> V_171 [ V_138 ] . V_49 ) ;
sprintf ( V_152 , L_22 , V_26 -> V_172 , V_138 + 1 ) ;
if ( F_74 ( V_26 , V_152 , V_138 , 1 , 1 , & V_10 -> V_171 [ V_138 ] . V_162 ) < 0 )
return - 1 ;
sprintf ( V_10 -> V_171 [ V_138 ] . V_162 -> V_173 , L_23 , V_138 + 1 ) ;
V_10 -> V_171 [ V_138 ] . V_162 -> V_163 = & V_10 -> V_171 [ V_138 ] ;
F_75 ( V_10 -> V_171 [ V_138 ] . V_162 , V_174 , & V_175 ) ;
F_75 ( V_10 -> V_171 [ V_138 ] . V_162 , V_176 , & V_177 ) ;
V_10 -> V_171 [ V_138 ] . V_162 -> V_178 |= V_179 |
V_180 |
V_181 ;
return 0 ;
}
static T_2 F_76 ( struct V_182 * V_183 )
{
T_2 V_21 = 0 ;
V_21 |= ( V_183 -> V_68 [ 0 ] & V_184 ) ? V_185 : 0 ;
V_21 |= ( V_183 -> V_68 [ 0 ] & V_186 ) ? V_187 : 0 ;
if ( V_21 & V_185 )
V_21 |= ( V_183 -> V_68 [ 0 ] & V_188 ) ? V_189 : 0 ;
else
V_21 |= ( V_183 -> V_68 [ 0 ] & V_190 ) ? V_189 : 0 ;
return V_21 ;
}
static void F_77 ( struct V_182 * V_183 , T_2 V_21 )
{
V_183 -> V_68 [ 0 ] = ( ( V_21 & V_185 ) ? V_184 : 0 ) |
( ( V_21 & V_187 ) ? V_186 : 0 ) ;
if ( V_21 & V_185 )
V_183 -> V_68 [ 0 ] |= ( V_21 & V_189 ) ? V_188 : 0 ;
else
V_183 -> V_68 [ 0 ] |= ( V_21 & V_189 ) ? V_190 : 0 ;
}
static int F_78 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
V_194 -> type = V_195 ;
V_194 -> V_58 = 1 ;
return 0 ;
}
static int F_79 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
F_77 ( & V_197 -> V_198 . V_199 , V_10 -> V_200 ) ;
return 0 ;
}
static int F_81 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
T_2 V_21 ;
V_21 = F_76 ( & V_197 -> V_198 . V_199 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = V_21 != V_10 -> V_200 ;
V_10 -> V_200 = V_21 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_82 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
V_194 -> type = V_195 ;
V_194 -> V_58 = 1 ;
return 0 ;
}
static int F_83 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
F_77 ( & V_197 -> V_198 . V_199 , V_10 -> V_202 ) ;
return 0 ;
}
static int F_84 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
T_2 V_21 ;
V_21 = F_76 ( & V_197 -> V_198 . V_199 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = V_21 != V_10 -> V_202 ;
V_10 -> V_202 = V_21 ;
V_10 -> V_92 &= ~ ( V_185 | V_187 | V_189 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 |= V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_85 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
V_194 -> type = V_195 ;
V_194 -> V_58 = 1 ;
return 0 ;
}
static int F_86 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
V_197 -> V_198 . V_199 . V_68 [ 0 ] = V_192 -> V_203 ;
return 0 ;
}
static unsigned int F_87 ( struct V_10 * V_10 )
{
return F_88 ( V_10 -> V_92 & V_204 ) ;
}
static int F_89 ( struct V_10 * V_10 , int V_11 )
{
V_10 -> V_92 &= ~ V_204 ;
V_10 -> V_92 |= F_90 ( V_11 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_91 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [ 4 ] = { L_24 , L_25 , L_26 , L_27 } ;
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . V_207 . V_208 = ( ( V_10 -> V_13 == V_18 ) ? 4 : 3 ) ;
if ( V_194 -> V_198 . V_207 . V_209 > ( ( V_10 -> V_13 == V_18 ) ? 3 : 2 ) )
V_194 -> V_198 . V_207 . V_209 = ( ( V_10 -> V_13 == V_18 ) ? 3 : 2 ) ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_92 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_87 ( V_10 ) ;
return 0 ;
}
static int F_93 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_207 . V_209 [ 0 ] % ( ( V_10 -> V_13 == V_18 ) ? 4 : 3 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = V_21 != F_87 ( V_10 ) ;
if ( V_201 )
F_89 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_94 ( struct V_10 * V_10 , T_2 V_210 )
{
return ( V_10 -> V_92 & V_210 ) ? 1 : 0 ;
}
static int F_95 ( struct V_10 * V_10 , T_2 V_210 , int V_12 )
{
if ( V_12 )
V_10 -> V_92 |= V_210 ;
else
V_10 -> V_92 &= ~ V_210 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_96 ( struct V_191 * V_192 ,
struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
T_2 V_210 = V_192 -> V_203 ;
F_44 ( & V_10 -> V_49 ) ;
V_197 -> V_198 . integer . V_198 [ 0 ] = F_94 ( V_10 , V_210 ) ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_97 ( struct V_191 * V_192 ,
struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
T_2 V_210 = V_192 -> V_203 ;
int V_201 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . integer . V_198 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = ( int ) V_21 != F_94 ( V_10 , V_210 ) ;
if ( V_201 )
F_95 ( V_10 , V_210 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_98 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [] = { L_28 , L_29 , L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 , L_37 } ;
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . V_207 . V_208 = ( V_10 -> V_13 == V_18 ) ? 10 : 7 ;
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_99 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
switch ( F_33 ( V_10 ) ) {
case 32000 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 0 ;
break;
case 44100 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 1 ;
break;
case 48000 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 2 ;
break;
case 64000 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 3 ;
break;
case 88200 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 4 ;
break;
case 96000 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 5 ;
break;
case 128000 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 7 ;
break;
case 176400 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 8 ;
break;
case 192000 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 9 ;
break;
default:
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_100 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
V_194 -> type = V_211 ;
V_194 -> V_58 = 1 ;
return 0 ;
}
static int F_101 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = V_10 -> V_118 ;
return 0 ;
}
static int F_102 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
static char * V_205 [] = { L_28 , L_29 , L_30 , L_31 , L_32 , L_33 , L_34 , L_35 , L_36 , L_37 } ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . V_207 . V_208 = ( V_10 -> V_13 == V_18 ) ? 10 : 7 ;
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_103 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
switch ( F_34 ( V_10 ) ) {
case 32000 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 0 ;
break;
case 44100 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 1 ;
break;
case 48000 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 2 ;
break;
case 64000 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 3 ;
break;
case 88200 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 4 ;
break;
case 96000 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 5 ;
break;
case 128000 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 7 ;
break;
case 176400 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 8 ;
break;
case 192000 :
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 9 ;
break;
default:
V_197 -> V_198 . V_207 . V_209 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_104 ( struct V_10 * V_10 )
{
if ( V_10 -> V_92 & V_114 )
return 0 ;
else if ( F_34 ( V_10 ) != V_10 -> V_118 )
return 0 ;
return 1 ;
}
static int F_105 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [] = { L_38 , L_39 } ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . V_207 . V_208 = 2 ;
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_106 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_104 ( V_10 ) ;
return 0 ;
}
static int F_107 ( struct V_10 * V_10 )
{
if ( V_10 -> V_92 & V_114 ) {
switch ( V_10 -> V_118 ) {
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
static int F_108 ( struct V_10 * V_10 , int V_212 )
{
int V_109 ;
switch ( V_212 ) {
case V_213 :
if ( F_34 ( V_10 ) != 0 ) {
if ( ! F_50 ( V_10 , F_34 ( V_10 ) , 1 ) ) {
V_10 -> V_92 &= ~ V_114 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
}
return - 1 ;
case V_214 :
V_109 = 32000 ;
break;
case V_215 :
V_109 = 44100 ;
break;
case V_216 :
V_109 = 48000 ;
break;
case V_217 :
V_109 = 64000 ;
break;
case V_218 :
V_109 = 88200 ;
break;
case V_219 :
V_109 = 96000 ;
break;
case V_220 :
V_109 = 128000 ;
break;
case V_221 :
V_109 = 176400 ;
break;
case V_222 :
V_109 = 192000 ;
break;
default:
V_109 = 48000 ;
}
V_10 -> V_92 |= V_114 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
F_50 ( V_10 , V_109 , 1 ) ;
return 0 ;
}
static int F_109 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [] = { L_40 , L_41 , L_42 , L_43 , L_44 , L_45 , L_46 , L_47 , L_48 , L_49 } ;
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
if ( V_10 -> V_13 == V_18 )
V_194 -> V_198 . V_207 . V_208 = 10 ;
else
V_194 -> V_198 . V_207 . V_208 = 7 ;
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_110 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_107 ( V_10 ) ;
return 0 ;
}
static int F_111 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_207 . V_209 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_10 -> V_13 == V_18 ) {
if ( V_21 > 9 )
V_21 = 9 ;
} else {
if ( V_21 > 6 )
V_21 = 6 ;
}
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_107 ( V_10 ) )
V_201 = ( F_108 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_112 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . integer . V_198 [ 0 ] = V_10 -> V_223 ;
return 0 ;
}
static int F_113 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
V_201 = ( int ) V_197 -> V_198 . integer . V_198 [ 0 ] != V_10 -> V_223 ;
if ( V_201 )
V_10 -> V_223 = ! ! V_197 -> V_198 . integer . V_198 [ 0 ] ;
return V_201 ;
}
static int F_114 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_224 ) {
case V_225 :
return 0 ;
case V_226 :
return 1 ;
case V_227 :
return 2 ;
default:
return 1 ;
}
}
static int F_115 ( struct V_10 * V_10 , int V_212 )
{
V_10 -> V_92 &= ~ V_224 ;
switch ( V_212 ) {
case 0 :
V_10 -> V_92 |= V_225 ;
break;
case 1 :
V_10 -> V_92 |= V_226 ;
break;
case 2 :
V_10 -> V_92 |= V_227 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_116 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [] = { L_50 , L_51 , L_52 } ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . V_207 . V_208 = 3 ;
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_117 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_114 ( V_10 ) ;
return 0 ;
}
static int F_118 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_207 . V_209 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_114 ( V_10 ) )
V_201 = ( F_115 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_119 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_228 ) {
case V_229 :
return 0 ;
case V_230 :
return 1 ;
case V_231 :
return 2 ;
default:
return 1 ;
}
}
static int F_120 ( struct V_10 * V_10 , int V_212 )
{
V_10 -> V_92 &= ~ V_228 ;
switch ( V_212 ) {
case 0 :
V_10 -> V_92 |= V_229 ;
break;
case 1 :
V_10 -> V_92 |= V_230 ;
break;
case 2 :
V_10 -> V_92 |= V_231 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_121 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [] = { L_53 , L_51 , L_54 } ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . V_207 . V_208 = 3 ;
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_122 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_119 ( V_10 ) ;
return 0 ;
}
static int F_123 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_207 . V_209 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_119 ( V_10 ) )
V_201 = ( F_120 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_124 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_232 ) {
case V_233 :
return 0 ;
case V_234 :
return 1 ;
case V_235 :
return 2 ;
default:
return 0 ;
}
}
static int F_125 ( struct V_10 * V_10 , int V_212 )
{
V_10 -> V_92 &= ~ V_232 ;
switch ( V_212 ) {
case 0 :
V_10 -> V_92 |= V_233 ;
break;
case 1 :
V_10 -> V_92 |= V_234 ;
break;
case 2 :
V_10 -> V_92 |= V_235 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_126 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [] = { L_55 , L_56 , L_57 } ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . V_207 . V_208 = 3 ;
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_127 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_124 ( V_10 ) ;
return 0 ;
}
static int F_128 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_207 . V_209 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_124 ( V_10 ) )
V_201 = ( F_125 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_129 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_236 ) {
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
static int F_130 ( struct V_10 * V_10 , int V_249 )
{
V_10 -> V_92 &= ~ V_236 ;
switch ( V_249 ) {
case V_238 :
V_10 -> V_92 &= ~ V_236 ;
break;
case V_240 :
V_10 -> V_92 |= V_239 ;
break;
case V_242 :
V_10 -> V_92 |= V_241 ;
break;
case V_244 :
V_10 -> V_92 |= V_243 ;
break;
case V_246 :
V_10 -> V_92 |= V_245 ;
break;
case V_248 :
V_10 -> V_92 |= V_247 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_131 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [] = { L_58 , L_59 , L_60 , L_61 , L_62 , L_63 } ;
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_194 -> V_198 . V_207 . V_208 = 6 ;
break;
case V_14 :
V_194 -> V_198 . V_207 . V_208 = 4 ;
break;
case V_18 :
V_194 -> V_198 . V_207 . V_208 = 3 ;
break;
default:
return - V_119 ;
}
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_132 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_129 ( V_10 ) ;
return 0 ;
}
static int F_133 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 , V_250 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_250 = 6 ;
break;
case V_14 :
V_250 = 4 ;
break;
case V_18 :
V_250 = 3 ;
break;
default:
return - V_29 ;
}
V_21 = V_197 -> V_198 . V_207 . V_209 [ 0 ] % V_250 ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = ( int ) V_21 != F_129 ( V_10 ) ;
F_130 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_35 ( struct V_10 * V_10 )
{
unsigned int V_82 = F_10 ( V_10 , V_53 ) ;
switch ( V_82 & V_251 ) {
case V_252 :
return V_253 ;
case V_254 :
return V_255 ;
case V_256 :
return V_84 ;
case V_251 :
return V_257 ;
case V_258 :
return V_117 ;
case V_259 :
return V_260 ;
case V_261 :
return V_262 ;
default:
return V_253 ;
}
return 0 ;
}
static int F_134 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [] = { L_58 , L_61 , L_59 , L_34 , L_60 , L_62 , L_63 } ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . V_207 . V_208 = 7 ;
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_135 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_35 ( V_10 ) ;
return 0 ;
}
static int F_136 ( struct V_10 * V_10 , int V_263 )
{
if ( V_263 )
V_10 -> V_94 = 1 ;
else
V_10 -> V_94 = 0 ;
return 0 ;
}
static int F_137 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_197 -> V_198 . integer . V_198 [ 0 ] = V_10 -> V_94 ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_138 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . integer . V_198 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = ( int ) V_21 != V_10 -> V_94 ;
F_136 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_139 ( struct V_10 * V_10 , int V_264 )
{
if ( V_264 )
V_10 -> V_265 = 1 ;
else
V_10 -> V_265 = 0 ;
return 0 ;
}
static int F_140 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_197 -> V_198 . integer . V_198 [ 0 ] = V_10 -> V_265 ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_141 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . integer . V_198 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = ( int ) V_21 != V_10 -> V_265 ;
F_139 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_142 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
V_194 -> type = V_211 ;
V_194 -> V_58 = 3 ;
V_194 -> V_198 . integer . V_266 = 0 ;
V_194 -> V_198 . integer . V_250 = 65536 ;
V_194 -> V_198 . integer . V_267 = 1 ;
return 0 ;
}
static int F_143 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_268 ;
int V_269 ;
int V_61 ;
V_268 = V_197 -> V_198 . integer . V_198 [ 0 ] ;
V_269 = V_197 -> V_198 . integer . V_198 [ 1 ] ;
if ( V_268 >= V_10 -> V_270 )
V_61 = F_6 ( V_10 , V_268 - V_10 -> V_270 , V_269 ) ;
else
V_61 = F_7 ( V_10 , V_268 , V_269 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_197 -> V_198 . integer . V_198 [ 2 ] = F_30 ( V_10 , V_61 ) ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_144 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_268 ;
int V_269 ;
int V_271 ;
int V_61 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_268 = V_197 -> V_198 . integer . V_198 [ 0 ] ;
V_269 = V_197 -> V_198 . integer . V_198 [ 1 ] ;
if ( V_268 >= V_10 -> V_270 )
V_61 = F_6 ( V_10 , V_268 - V_10 -> V_270 , V_269 ) ;
else
V_61 = F_7 ( V_10 , V_268 , V_269 ) ;
V_271 = V_197 -> V_198 . integer . V_198 [ 2 ] ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = V_271 != F_30 ( V_10 , V_61 ) ;
if ( V_201 )
F_31 ( V_10 , V_61 , V_271 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_145 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [] = { L_64 , L_65 , L_66 } ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . V_207 . V_208 = 3 ;
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_146 ( struct V_10 * V_10 )
{
int V_82 = F_10 ( V_10 , V_53 ) ;
if ( V_82 & V_272 ) {
if ( V_82 & V_273 )
return 2 ;
else
return 1 ;
} else
return 0 ;
return 0 ;
}
static int F_147 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_146 ( V_10 ) ;
return 0 ;
}
static int F_148 ( struct V_10 * V_10 )
{
int V_68 = F_10 ( V_10 , V_24 ) ;
if ( V_68 & V_72 )
return 0 ;
else {
if ( V_68 & V_274 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_149 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_148 ( V_10 ) ;
return 0 ;
}
static int F_150 ( struct V_10 * V_10 )
{
int V_68 = F_10 ( V_10 , V_24 ) ;
if ( V_68 & V_275 ) {
if ( V_68 & V_276 )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_151 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_150 ( V_10 ) ;
return 0 ;
}
static int F_152 ( struct V_10 * V_10 , int V_277 )
{
int V_68 = F_10 ( V_10 , V_24 ) ;
if ( V_68 & ( V_278 >> V_277 ) ) {
if ( V_68 & ( V_279 >> V_277 ) )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_153 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
int V_280 ;
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_280 = V_197 -> V_138 . V_281 - 1 ;
F_49 ( V_280 < 0 ) ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
if ( V_280 >= 3 )
return - V_119 ;
break;
case V_14 :
case V_18 :
if ( V_280 >= 1 )
return - V_119 ;
break;
default:
return - V_29 ;
}
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_152 ( V_10 , V_280 ) ;
return 0 ;
}
static int F_154 ( struct V_10 * V_10 )
{
T_4 V_107 ;
unsigned int V_99 = V_10 -> V_99 ;
int V_118 = V_10 -> V_118 ;
if ( ! V_99 )
return 0 ;
V_107 = V_110 ;
V_107 = F_48 ( V_107 , V_99 ) ;
if ( V_118 >= 112000 )
V_107 *= 4 ;
else if ( V_118 >= 56000 )
V_107 *= 2 ;
return ( ( int ) V_107 ) - V_118 ;
}
static int F_155 ( struct V_10 * V_10 , int V_282 )
{
int V_109 = V_10 -> V_118 + V_282 ;
F_47 ( V_10 , V_109 ) ;
return 0 ;
}
static int F_156 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
V_194 -> type = V_211 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . integer . V_266 = - 5000 ;
V_194 -> V_198 . integer . V_250 = 5000 ;
return 0 ;
}
static int F_157 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_154 ( V_10 ) ;
return 0 ;
}
static int F_158 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_207 . V_209 [ 0 ] ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_154 ( V_10 ) )
V_201 = ( F_155 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_159 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_283 ) {
case V_284 :
return 0 ;
case V_285 :
return 2 ;
case V_286 :
return 3 ;
case V_287 :
return 4 ;
}
return 1 ;
}
static int F_160 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_159 ( V_10 ) ;
return 0 ;
}
static int F_161 ( struct V_10 * V_10 , int V_212 )
{
V_10 -> V_92 &= ~ V_283 ;
switch ( V_212 ) {
case 0 :
V_10 -> V_92 |= V_284 ;
break;
case 1 :
break;
case 2 :
V_10 -> V_92 |= V_285 ;
break;
case 3 :
V_10 -> V_92 |= V_286 ;
break;
case 4 :
V_10 -> V_92 |= V_287 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_162 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_207 . V_209 [ 0 ] ;
if ( V_21 < 0 )
V_21 = 0 ;
if ( V_21 > 4 )
V_21 = 4 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_159 ( V_10 ) )
V_201 = ( F_161 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_163 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [] = { L_67 , L_68 , L_69 , L_70 , L_71 } ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . V_207 . V_208 = 5 ;
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_164 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_288 ) {
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
static int F_165 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_207 . V_209 [ 0 ] = F_164 ( V_10 ) ;
return 0 ;
}
static int F_166 ( struct V_10 * V_10 , int V_212 )
{
V_10 -> V_92 &= ~ V_288 ;
switch ( V_212 ) {
case 0 :
V_10 -> V_92 |= V_289 ;
break;
case 1 :
break;
case 2 :
V_10 -> V_92 |= V_290 ;
break;
case 3 :
V_10 -> V_92 |= V_291 ;
break;
case 4 :
V_10 -> V_92 |= V_292 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_167 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_207 . V_209 [ 0 ] ;
if ( V_21 < 0 )
V_21 = 0 ;
if ( V_21 > 4 )
V_21 = 4 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_164 ( V_10 ) )
V_201 = ( F_166 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_168 ( struct V_10 * V_10 )
{
return ( V_10 -> V_92 & V_293 ) ? 1 : 0 ;
}
static int F_169 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . integer . V_198 [ 0 ] = F_168 ( V_10 ) ;
return 0 ;
}
static int F_170 ( struct V_10 * V_10 , int V_294 )
{
if ( V_294 )
V_10 -> V_92 |= V_293 ;
else
V_10 -> V_92 &= ~ V_293 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_171 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . integer . V_198 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = ( int ) V_21 != F_168 ( V_10 ) ;
F_170 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_172 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [] = { L_72 , L_73 } ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . V_207 . V_208 = 2 ;
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_173 ( struct V_10 * V_10 )
{
return ( V_10 -> V_92 & V_295 ) ? 1 : 0 ;
}
static int F_174 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . integer . V_198 [ 0 ] = F_173 ( V_10 ) ;
return 0 ;
}
static int F_175 ( struct V_10 * V_10 , int V_294 )
{
if ( V_294 )
V_10 -> V_92 |= V_295 ;
else
V_10 -> V_92 &= ~ V_295 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_176 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . integer . V_198 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = ( int ) V_21 != F_173 ( V_10 ) ;
F_175 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_177 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static char * V_205 [] = { L_72 , L_73 } ;
V_194 -> type = V_206 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . V_207 . V_208 = 2 ;
if ( V_194 -> V_198 . V_207 . V_209 >= V_194 -> V_198 . V_207 . V_208 )
V_194 -> V_198 . V_207 . V_209 = V_194 -> V_198 . V_207 . V_208 - 1 ;
strcpy ( V_194 -> V_198 . V_207 . V_173 , V_205 [ V_194 -> V_198 . V_207 . V_209 ] ) ;
return 0 ;
}
static int F_178 ( struct V_170 * V_26 , struct V_10 * V_10 )
{
unsigned int V_277 ;
int V_296 ;
struct V_191 * V_297 ;
if ( V_10 -> V_13 == V_16 ) {
for ( V_277 = 0 ; V_277 < F_179 ( V_298 ) ; V_277 ++ ) {
V_296 = F_180 ( V_26 , V_297 = F_181 ( & V_298 [ V_277 ] , V_10 ) ) ;
if ( V_296 < 0 )
return V_296 ;
}
return 0 ;
}
for ( V_277 = 0 ; V_277 < F_179 ( V_299 ) ; V_277 ++ ) {
if ( ( V_296 = F_180 ( V_26 , V_297 = F_181 ( & V_299 [ V_277 ] , V_10 ) ) ) < 0 )
return V_296 ;
if ( V_277 == 1 )
V_10 -> V_300 = V_297 ;
}
V_301 . V_173 = L_74 ;
V_301 . V_281 = 1 ;
if ( ( V_296 = F_180 ( V_26 , V_297 = F_181 ( & V_301 , V_10 ) ) ) )
return V_296 ;
if ( V_10 -> V_13 == V_15 || V_10 -> V_13 == V_19 ) {
for ( V_277 = 1 ; V_277 < 3 ; ++ V_277 ) {
V_301 . V_281 = V_277 + 1 ;
if ( ( V_296 = F_180 ( V_26 , V_297 = F_181 ( & V_301 , V_10 ) ) ) )
return V_296 ;
}
}
if ( V_10 -> V_13 == V_18 ) {
for ( V_277 = 0 ; V_277 < F_179 ( V_302 ) ; V_277 ++ ) {
if ( ( V_296 = F_180 ( V_26 , V_297 = F_181 ( & V_302 [ V_277 ] , V_10 ) ) ) < 0 )
return V_296 ;
}
}
if ( V_10 -> V_13 == V_18 || V_10 -> V_13 == V_19 ) {
if ( ( V_296 = F_180 ( V_26 , V_297 = F_181 ( & V_303 , V_10 ) ) ) < 0 )
return V_296 ;
}
return 0 ;
}
static void
F_182 ( struct V_304 * V_305 , struct V_306 * V_307 )
{
struct V_10 * V_10 = V_305 -> V_163 ;
unsigned int V_68 ;
unsigned int V_82 ;
char * V_308 ;
char * V_309 ;
char * V_310 ;
char * V_311 ;
int V_312 ;
V_68 = F_10 ( V_10 , V_24 ) ;
V_82 = F_10 ( V_10 , V_53 ) ;
F_183 ( V_307 , L_75 , V_10 -> V_313 ,
V_10 -> V_26 -> V_314 + 1 ) ;
F_183 ( V_307 , L_76 ,
V_10 -> V_315 , V_10 -> V_104 ) ;
F_183 ( V_307 , L_77 ,
V_10 -> V_316 , V_10 -> V_317 , ( unsigned long ) V_10 -> V_22 ) ;
F_183 ( V_307 , L_78 , V_10 -> V_92 ) ;
F_183 ( V_307 , L_79 ,
V_10 -> V_46 ) ;
F_183 ( V_307 , L_80 , V_68 ) ;
F_183 ( V_307 , L_81 , V_82 ) ;
if ( F_12 ( V_10 ) ) {
F_183 ( V_307 , L_82
L_83 ) ;
return;
}
if ( F_26 ( V_10 , 0 ) ) {
if ( V_10 -> V_27 & V_57 ) {
if ( F_18 ( V_10 ) != 0 ) {
F_183 ( V_307 , L_84
L_85
L_86 ) ;
return;
}
} else {
int V_296 = - V_119 ;
V_296 = F_27 ( V_10 ) ;
if ( V_296 < 0 ) {
F_183 ( V_307 ,
L_87
L_88 ) ;
return;
}
}
}
F_183 ( V_307 , L_89 , F_10 ( V_10 , V_60 ) & 0xff ) ;
F_183 ( V_307 , L_90 , F_10 ( V_10 , V_147 ) ) ;
F_183 ( V_307 , L_91 , F_10 ( V_10 , V_144 ) ) ;
F_183 ( V_307 , L_92 , F_10 ( V_10 , V_146 ) ) ;
F_183 ( V_307 , L_93 , F_10 ( V_10 , V_143 ) ) ;
F_183 ( V_307 , L_94 , V_10 -> V_265 ? L_95 : L_96 ) ;
F_183 ( V_307 , L_97 ) ;
V_312 = 1 << ( 6 + F_37 ( V_10 -> V_92 & V_108 ) ) ;
F_183 ( V_307 , L_98 , V_312 , ( unsigned long ) V_10 -> V_91 ) ;
F_183 ( V_307 , L_99 , F_38 ( V_10 ) ) ;
F_183 ( V_307 , L_100 , V_10 -> V_94 ? L_95 : L_96 ) ;
F_183 ( V_307 , L_101 , ( V_10 -> V_92 & V_318 ) ? L_95 : L_96 ) ;
F_183 ( V_307 , L_102 , ( V_82 & V_319 ) | ( V_82 & V_55 ) << 1 | ( V_82 & V_54 ) << 2 ) ;
F_183 ( V_307 , L_97 ) ;
switch ( F_107 ( V_10 ) ) {
case V_213 :
V_311 = L_40 ;
break;
case V_214 :
V_311 = L_103 ;
break;
case V_215 :
V_311 = L_42 ;
break;
case V_216 :
V_311 = L_104 ;
break;
case V_217 :
V_311 = L_105 ;
break;
case V_218 :
V_311 = L_45 ;
break;
case V_219 :
V_311 = L_106 ;
break;
case V_220 :
V_311 = L_47 ;
break;
case V_221 :
V_311 = L_48 ;
break;
case V_222 :
V_311 = L_107 ;
break;
default:
V_311 = L_108 ;
}
F_183 ( V_307 , L_109 , V_311 ) ;
if ( F_104 ( V_10 ) )
V_310 = L_39 ;
else
V_310 = L_38 ;
switch ( F_129 ( V_10 ) ) {
case V_246 :
V_308 = L_110 ;
break;
case V_248 :
V_308 = L_61 ;
break;
case V_244 :
V_308 = L_111 ;
break;
case V_238 :
V_308 = L_60 ;
break;
case V_240 :
V_308 = L_62 ;
break;
case V_242 :
V_308 = L_63 ;
break;
default:
V_308 = L_110 ;
break;
}
F_183 ( V_307 , L_112 , V_308 ) ;
switch ( F_35 ( V_10 ) ) {
case V_253 :
V_309 = L_110 ;
break;
case V_255 :
V_309 = L_61 ;
break;
case V_84 :
V_309 = L_111 ;
break;
case V_257 :
V_309 = L_34 ;
break;
case V_117 :
V_309 = L_60 ;
break;
case V_260 :
V_309 = L_62 ;
break;
case V_262 :
V_309 = L_63 ;
break;
default:
V_309 = L_113 ;
break;
}
F_183 ( V_307 , L_114 , V_309 ) ;
F_183 ( V_307 , L_115 , F_34 ( V_10 ) ) ;
F_183 ( V_307 , L_116 , V_310 ) ;
F_183 ( V_307 , L_117 , V_10 -> V_118 ) ;
F_183 ( V_307 , L_118 , V_10 -> V_223 ? L_119 : L_120 ) ;
F_183 ( V_307 , L_97 ) ;
if ( V_10 -> V_13 != V_16 ) {
switch ( F_87 ( V_10 ) ) {
case V_320 :
F_183 ( V_307 , L_121 ) ;
break;
case V_321 :
F_183 ( V_307 , L_122 ) ;
break;
case V_322 :
F_183 ( V_307 , L_123 ) ;
break;
case V_323 :
F_183 ( V_307 , L_124 ) ;
break;
default:
F_183 ( V_307 , L_125 ) ;
break;
}
}
if ( V_16 == V_10 -> V_13 ) {
if ( V_10 -> V_92 & V_293 )
F_183 ( V_307 , L_126 ) ;
else
F_183 ( V_307 , L_127 ) ;
if ( V_10 -> V_92 & V_295 )
F_183 ( V_307 , L_128 ) ;
else
F_183 ( V_307 , L_129 ) ;
switch ( V_10 -> V_92 & V_283 ) {
case V_284 :
F_183 ( V_307 , L_130 ) ;
break;
case V_324 :
F_183 ( V_307 , L_131 ) ;
break;
case V_285 :
F_183 ( V_307 , L_132 ) ;
break;
case V_286 :
F_183 ( V_307 , L_133 ) ;
break;
case V_287 :
F_183 ( V_307 , L_134 ) ;
break;
default:
F_183 ( V_307 , L_135 ) ;
}
switch ( V_10 -> V_92 & V_288 ) {
case V_289 :
F_183 ( V_307 , L_136 ) ;
break;
case V_325 :
F_183 ( V_307 , L_137 ) ;
break;
case V_290 :
F_183 ( V_307 , L_138 ) ;
break;
case V_291 :
F_183 ( V_307 , L_139 ) ;
break;
case V_292 :
F_183 ( V_307 , L_140 ) ;
break;
default:
F_183 ( V_307 , L_141 ) ;
}
} else {
if ( V_10 -> V_92 & V_326 )
F_183 ( V_307 , L_142 ) ;
else
F_183 ( V_307 , L_143 ) ;
if ( V_10 -> V_92 & V_185 )
F_183 ( V_307 , L_144 ) ;
else
F_183 ( V_307 , L_145 ) ;
if ( V_10 -> V_92 & V_189 )
F_183 ( V_307 , L_146 ) ;
else
F_183 ( V_307 , L_147 ) ;
if ( V_10 -> V_92 & V_187 )
F_183 ( V_307 , L_148 ) ;
else
F_183 ( V_307 , L_149 ) ;
V_312 = F_33 ( V_10 ) ;
if ( V_312 != 0 )
F_183 ( V_307 , L_150 , V_312 ) ;
else
F_183 ( V_307 , L_151 ) ;
}
F_183 ( V_307 , L_97 ) ;
V_312 = V_68 & V_279 ;
if ( V_68 & V_278 )
F_183 ( V_307 , L_152 , V_312 ? L_66 : L_65 ) ;
else
F_183 ( V_307 , L_153 ) ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_312 = V_68 & V_327 ;
if ( V_68 & V_328 )
F_183 ( V_307 , L_154 , V_312 ? L_66 : L_65 ) ;
else
F_183 ( V_307 , L_155 ) ;
V_312 = V_68 & V_329 ;
if ( V_68 & V_330 )
F_183 ( V_307 , L_156 , V_312 ? L_66 : L_65 ) ;
else
F_183 ( V_307 , L_157 ) ;
break;
default:
break;
}
V_312 = V_68 & V_274 ;
if ( V_68 & V_72 )
F_183 ( V_307 , L_158 ) ;
else
F_183 ( V_307 , L_159 , V_312 ? L_66 : L_65 ) ;
V_312 = V_82 & V_273 ;
if ( V_82 & V_272 )
F_183 ( V_307 , L_160 , V_312 ? L_66 : L_65 ) ;
else
F_183 ( V_307 , L_161 ) ;
V_312 = V_68 & V_276 ;
if ( V_68 & V_275 )
F_183 ( V_307 , L_162 , V_312 ? L_66 : L_65 ) ;
else
F_183 ( V_307 , L_163 ) ;
F_183 ( V_307 , L_97 ) ;
if ( V_10 -> V_13 == V_18 ) {
char * V_331 ;
switch ( F_119 ( V_10 ) ) {
case 0 :
V_331 = L_53 ;
break;
case 1 :
V_331 = L_51 ;
break;
default:
V_331 = L_54 ;
break;
}
F_183 ( V_307 , L_164 , V_331 ) ;
switch ( F_114 ( V_10 ) ) {
case 0 :
V_331 = L_50 ;
break;
case 1 :
V_331 = L_51 ;
break;
default:
V_331 = L_53 ;
break;
}
F_183 ( V_307 , L_165 , V_331 ) ;
switch ( F_124 ( V_10 ) ) {
case 0 :
V_331 = L_55 ;
break;
case 1 :
V_331 = L_56 ;
break;
default:
V_331 = L_57 ;
break;
}
F_183 ( V_307 , L_166 , V_331 ) ;
F_183 ( V_307 , L_167 ,
F_94 ( V_10 , V_332 ) ?
L_168 : L_169 ) ;
if ( V_10 -> V_92 & V_333 )
F_183 ( V_307 , L_170 ) ;
else
F_183 ( V_307 , L_171 ) ;
F_183 ( V_307 , L_97 ) ;
}
}
static void F_184 ( struct V_10 * V_10 )
{
struct V_304 * V_305 ;
if ( ! F_185 ( V_10 -> V_26 , L_172 , & V_305 ) )
F_186 ( V_305 , V_10 , F_182 ) ;
}
static void F_187 ( struct V_10 * V_10 )
{
F_4 ( & V_10 -> V_334 , V_10 -> V_2 ) ;
F_4 ( & V_10 -> V_335 , V_10 -> V_2 ) ;
}
static int F_188 ( struct V_10 * V_10 )
{
unsigned long V_336 , V_337 ;
if ( F_1 ( V_10 -> V_2 , & V_10 -> V_334 , V_105 ) < 0 ||
F_1 ( V_10 -> V_2 , & V_10 -> V_335 , V_105 ) < 0 ) {
if ( V_10 -> V_334 . V_9 )
F_5 ( & V_10 -> V_334 ) ;
F_15 ( V_10 -> V_26 -> V_6 ,
L_173 , V_10 -> V_313 ) ;
return - V_8 ;
}
V_337 = F_189 ( V_10 -> V_334 . V_61 , 0x10000ul ) ;
V_336 = F_189 ( V_10 -> V_335 . V_61 , 0x10000ul ) ;
F_8 ( V_10 , V_338 , V_337 ) ;
F_8 ( V_10 , V_339 , V_336 ) ;
V_10 -> V_315 = V_10 -> V_334 . V_9 + ( V_337 - V_10 -> V_334 . V_61 ) ;
V_10 -> V_104 = V_10 -> V_335 . V_9 + ( V_336 - V_10 -> V_335 . V_61 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_10 )
{
unsigned int V_23 ;
V_10 -> V_92 = V_114 |
V_340 |
F_45 ( 7 ) |
V_318 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
#ifdef F_21
V_10 -> V_46 = V_47 ;
#else
V_10 -> V_46 = 0 ;
#endif
if ( V_10 -> V_13 == V_19 )
F_190 ( V_10 ) ;
else
F_8 ( V_10 , V_39 , V_10 -> V_46 ) ;
F_39 ( V_10 ) ;
F_36 ( V_10 ) ;
for ( V_23 = 0 ; V_23 < V_62 ; ++ V_23 )
V_10 -> V_63 [ V_23 ] = V_341 ;
for ( V_23 = 0 ; V_23 < ( ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) ? 1352 : V_62 ) ; ++ V_23 ) {
if ( F_31 ( V_10 , V_23 , V_341 ) )
return - V_29 ;
}
if ( V_10 -> V_13 == V_18 ) {
V_10 -> V_92 |= ( V_226 | V_230 | V_233 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
}
F_50 ( V_10 , 48000 , 1 ) ;
return 0 ;
}
static void F_191 ( unsigned long V_342 )
{
struct V_10 * V_10 = (struct V_10 * ) V_342 ;
if ( V_10 -> V_171 [ 0 ] . V_155 )
F_59 ( & V_10 -> V_171 [ 0 ] ) ;
if ( V_10 -> V_171 [ 1 ] . V_155 )
F_59 ( & V_10 -> V_171 [ 1 ] ) ;
}
static T_5 F_192 ( int V_316 , void * V_343 )
{
struct V_10 * V_10 = (struct V_10 * ) V_343 ;
unsigned int V_68 ;
int V_344 ;
int V_345 ;
int V_346 ;
unsigned int V_347 ;
unsigned int V_348 ;
int V_349 = 0 ;
V_68 = F_10 ( V_10 , V_24 ) ;
V_344 = V_68 & V_350 ;
V_345 = V_68 & V_351 ;
V_346 = V_68 & V_352 ;
if ( ! V_344 && ! V_345 && ! V_346 )
return V_353 ;
F_8 ( V_10 , V_354 , 0 ) ;
V_347 = F_10 ( V_10 , V_144 ) & 0xff ;
V_348 = F_10 ( V_10 , V_143 ) & 0xff ;
if ( ! ( V_10 -> V_27 & V_48 ) )
return V_355 ;
if ( V_344 ) {
if ( V_10 -> V_356 )
F_193 ( V_10 -> V_357 -> V_358 [ V_359 ] . V_159 ) ;
if ( V_10 -> V_360 )
F_193 ( V_10 -> V_357 -> V_358 [ V_361 ] . V_159 ) ;
}
if ( V_345 && V_347 ) {
if ( V_10 -> V_265 ) {
V_10 -> V_92 &= ~ V_157 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
V_10 -> V_171 [ 0 ] . V_155 = 1 ;
V_349 = 1 ;
} else {
F_59 ( & V_10 -> V_171 [ 0 ] ) ;
}
}
if ( V_10 -> V_13 != V_14 && V_10 -> V_13 != V_16 && V_10 -> V_13 != V_18 && V_346 && V_348 ) {
if ( V_10 -> V_265 ) {
V_10 -> V_92 &= ~ V_156 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
V_10 -> V_171 [ 1 ] . V_155 = 1 ;
V_349 = 1 ;
} else {
F_59 ( & V_10 -> V_171 [ 1 ] ) ;
}
}
if ( V_10 -> V_265 && V_349 )
F_194 ( & V_10 -> V_164 ) ;
return V_355 ;
}
static T_3 F_195 ( struct V_362 * V_159 )
{
struct V_10 * V_10 = F_196 ( V_159 ) ;
return F_38 ( V_10 ) ;
}
static char * F_197 ( struct V_10 * V_10 ,
int V_363 ,
int V_364 )
{
int V_365 ;
if ( F_49 ( V_364 < 0 || V_364 >= V_10 -> V_270 ) )
return NULL ;
if ( ( V_365 = V_10 -> V_131 [ V_364 ] ) < 0 )
return NULL ;
if ( V_363 == V_359 )
return V_10 -> V_315 + ( V_365 * V_366 ) ;
else
return V_10 -> V_104 + ( V_365 * V_366 ) ;
}
static int F_198 ( struct V_362 * V_159 , int V_364 ,
T_3 V_367 , void T_6 * V_368 , T_3 V_58 )
{
struct V_10 * V_10 = F_196 ( V_159 ) ;
char * V_369 ;
if ( F_49 ( V_367 + V_58 > V_366 / 4 ) )
return - V_119 ;
V_369 = F_197 ( V_10 , V_159 -> V_370 -> V_363 , V_364 ) ;
if ( F_49 ( ! V_369 ) )
return - V_29 ;
if ( F_199 ( V_369 + V_367 * 4 , V_368 , V_58 * 4 ) )
return - V_371 ;
return V_58 ;
}
static int F_200 ( struct V_362 * V_159 , int V_364 ,
T_3 V_367 , void T_6 * V_372 , T_3 V_58 )
{
struct V_10 * V_10 = F_196 ( V_159 ) ;
char * V_369 ;
if ( F_49 ( V_367 + V_58 > V_366 / 4 ) )
return - V_119 ;
V_369 = F_197 ( V_10 , V_159 -> V_370 -> V_363 , V_364 ) ;
if ( F_49 ( ! V_369 ) )
return - V_29 ;
if ( F_201 ( V_372 , V_369 + V_367 * 4 , V_58 * 4 ) )
return - V_371 ;
return V_58 ;
}
static int F_202 ( struct V_362 * V_159 , int V_364 ,
T_3 V_367 , T_3 V_58 )
{
struct V_10 * V_10 = F_196 ( V_159 ) ;
char * V_369 ;
V_369 = F_197 ( V_10 , V_159 -> V_370 -> V_363 , V_364 ) ;
if ( F_49 ( ! V_369 ) )
return - V_29 ;
memset ( V_369 + V_367 * 4 , 0 , V_58 * 4 ) ;
return V_58 ;
}
static int F_203 ( struct V_362 * V_159 )
{
struct V_373 * V_374 = V_159 -> V_374 ;
struct V_10 * V_10 = F_196 ( V_159 ) ;
struct V_362 * V_375 ;
if ( V_159 -> V_363 == V_361 )
V_375 = V_10 -> V_356 ;
else
V_375 = V_10 -> V_360 ;
if ( V_10 -> V_376 )
V_374 -> V_68 -> V_377 = F_38 ( V_10 ) ;
else
V_374 -> V_68 -> V_377 = 0 ;
if ( V_375 ) {
struct V_362 * V_100 ;
struct V_373 * V_378 = V_375 -> V_374 ;
F_204 (s, substream) {
if ( V_100 == V_375 ) {
V_378 -> V_68 -> V_377 = V_374 -> V_68 -> V_377 ;
break;
}
}
}
return 0 ;
}
static int F_205 ( struct V_362 * V_159 ,
struct V_379 * V_380 )
{
struct V_10 * V_10 = F_196 ( V_159 ) ;
int V_296 ;
T_7 V_381 ;
T_7 V_382 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_159 -> V_370 -> V_363 == V_361 ) {
V_10 -> V_92 &= ~ ( V_185 | V_187 | V_189 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 |= V_10 -> V_202 ) ;
V_381 = V_10 -> V_66 ;
V_382 = V_10 -> V_67 ;
} else {
V_381 = V_10 -> V_67 ;
V_382 = V_10 -> V_66 ;
}
if ( ( V_382 > 0 ) && ( V_381 != V_382 ) ) {
if ( F_206 ( V_380 ) != V_10 -> V_118 ) {
F_46 ( & V_10 -> V_49 ) ;
F_207 ( V_380 , V_383 ) ;
return - V_129 ;
}
if ( F_208 ( V_380 ) != V_10 -> V_91 / 4 ) {
F_46 ( & V_10 -> V_49 ) ;
F_207 ( V_380 , V_384 ) ;
return - V_129 ;
}
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
} else {
F_46 ( & V_10 -> V_49 ) ;
}
F_44 ( & V_10 -> V_49 ) ;
if ( ! V_10 -> V_223 ) {
if ( ( V_296 = F_50 ( V_10 , F_206 ( V_380 ) , 0 ) ) < 0 ) {
F_46 ( & V_10 -> V_49 ) ;
F_207 ( V_380 , V_383 ) ;
return V_296 ;
}
}
F_46 ( & V_10 -> V_49 ) ;
if ( ( V_296 = F_43 ( V_10 , F_208 ( V_380 ) ) ) < 0 ) {
F_207 ( V_380 , V_384 ) ;
return V_296 ;
}
return 0 ;
}
static int F_209 ( struct V_362 * V_159 ,
struct V_385 * V_386 )
{
struct V_10 * V_10 = F_196 ( V_159 ) ;
int V_365 ;
if ( F_49 ( V_386 -> V_364 >= V_10 -> V_270 ) )
return - V_119 ;
if ( ( V_365 = V_10 -> V_131 [ V_386 -> V_364 ] ) < 0 )
return - V_119 ;
V_386 -> V_280 = V_365 * V_366 ;
V_386 -> V_387 = 0 ;
V_386 -> V_267 = 32 ;
return 0 ;
}
static int F_210 ( struct V_362 * V_159 ,
unsigned int V_388 , void * V_342 )
{
switch ( V_388 ) {
case V_389 :
return F_203 ( V_159 ) ;
case V_390 :
return F_209 ( V_159 , V_342 ) ;
default:
break;
}
return F_211 ( V_159 , V_388 , V_342 ) ;
}
static int F_212 ( struct V_362 * V_159 , int V_388 )
{
struct V_10 * V_10 = F_196 ( V_159 ) ;
struct V_362 * V_375 ;
int V_376 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 0 ) )
return - V_29 ;
F_213 ( & V_10 -> V_49 ) ;
V_376 = V_10 -> V_376 ;
switch ( V_388 ) {
case V_391 :
V_376 |= 1 << V_159 -> V_363 ;
break;
case V_392 :
V_376 &= ~ ( 1 << V_159 -> V_363 ) ;
break;
default:
F_214 () ;
F_215 ( & V_10 -> V_49 ) ;
return - V_119 ;
}
if ( V_159 -> V_363 == V_361 )
V_375 = V_10 -> V_356 ;
else
V_375 = V_10 -> V_360 ;
if ( V_375 ) {
struct V_362 * V_100 ;
F_204 (s, substream) {
if ( V_100 == V_375 ) {
F_216 ( V_100 , V_159 ) ;
if ( V_388 == V_391 )
V_376 |= 1 << V_100 -> V_363 ;
else
V_376 &= ~ ( 1 << V_100 -> V_363 ) ;
goto V_393;
}
}
if ( V_388 == V_391 ) {
if ( ! ( V_376 & ( 1 << V_361 ) ) &&
V_159 -> V_363 == V_359 )
F_42 ( V_10 ) ;
} else {
if ( V_376 &&
V_159 -> V_363 == V_361 )
F_42 ( V_10 ) ;
}
} else {
if ( V_159 -> V_363 == V_359 )
F_42 ( V_10 ) ;
}
V_393:
F_216 ( V_159 , V_159 ) ;
if ( ! V_10 -> V_376 && V_376 )
F_40 ( V_10 ) ;
else if ( V_10 -> V_376 && ! V_376 )
F_41 ( V_10 ) ;
V_10 -> V_376 = V_376 ;
F_215 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_217 ( struct V_362 * V_159 )
{
struct V_10 * V_10 = F_196 ( V_159 ) ;
int V_394 = 0 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
if ( ! V_10 -> V_376 )
F_39 ( V_10 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_394 ;
}
static int F_218 ( struct V_379 * V_380 ,
struct V_395 * V_396 )
{
struct V_10 * V_10 = V_396 -> V_397 ;
struct V_398 * V_399 = F_219 ( V_380 , V_400 ) ;
if ( V_10 -> V_13 == V_18 ) {
unsigned int V_401 [ 3 ] ;
V_401 [ 0 ] = V_10 -> V_402 ;
V_401 [ 1 ] = V_10 -> V_403 ;
V_401 [ 2 ] = V_10 -> V_404 ;
return F_220 ( V_399 , 3 , V_401 , 0 ) ;
} else {
unsigned int V_401 [ 2 ] ;
V_401 [ 0 ] = V_10 -> V_403 ;
V_401 [ 1 ] = V_10 -> V_404 ;
return F_220 ( V_399 , 2 , V_401 , 0 ) ;
}
}
static int F_221 ( struct V_379 * V_380 ,
struct V_395 * V_396 )
{
unsigned int V_401 [ 3 ] ;
struct V_10 * V_10 = V_396 -> V_397 ;
struct V_398 * V_399 = F_219 ( V_380 , V_400 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_401 [ 0 ] = V_10 -> V_405 ;
V_401 [ 1 ] = V_10 -> V_406 ;
V_401 [ 2 ] = V_10 -> V_407 ;
return F_220 ( V_399 , 3 , V_401 , 0 ) ;
} else {
V_401 [ 0 ] = V_10 -> V_406 ;
V_401 [ 1 ] = V_10 -> V_407 ;
}
return F_220 ( V_399 , 2 , V_401 , 0 ) ;
}
static int F_222 ( struct V_379 * V_380 ,
struct V_395 * V_396 )
{
struct V_10 * V_10 = V_396 -> V_397 ;
struct V_398 * V_399 = F_219 ( V_380 , V_400 ) ;
struct V_398 * V_408 = F_219 ( V_380 , V_383 ) ;
if ( V_408 -> V_266 > 96000 && V_10 -> V_13 == V_18 ) {
struct V_398 V_409 = {
. V_266 = V_10 -> V_402 ,
. V_250 = V_10 -> V_402 ,
. integer = 1 ,
} ;
return F_223 ( V_399 , & V_409 ) ;
} else if ( V_408 -> V_266 > 48000 && V_408 -> V_250 <= 96000 ) {
struct V_398 V_409 = {
. V_266 = V_10 -> V_403 ,
. V_250 = V_10 -> V_403 ,
. integer = 1 ,
} ;
return F_223 ( V_399 , & V_409 ) ;
} else if ( V_408 -> V_250 < 64000 ) {
struct V_398 V_409 = {
. V_266 = V_10 -> V_404 ,
. V_250 = V_10 -> V_404 ,
. integer = 1 ,
} ;
return F_223 ( V_399 , & V_409 ) ;
}
return 0 ;
}
static int F_224 ( struct V_379 * V_380 ,
struct V_395 * V_396 )
{
struct V_10 * V_10 = V_396 -> V_397 ;
struct V_398 * V_399 = F_219 ( V_380 , V_400 ) ;
struct V_398 * V_408 = F_219 ( V_380 , V_383 ) ;
if ( V_408 -> V_266 > 96000 && V_10 -> V_13 == V_18 ) {
struct V_398 V_409 = {
. V_266 = V_10 -> V_405 ,
. V_250 = V_10 -> V_405 ,
. integer = 1 ,
} ;
return F_223 ( V_399 , & V_409 ) ;
} else if ( V_408 -> V_266 > 48000 && V_408 -> V_250 <= 96000 ) {
struct V_398 V_409 = {
. V_266 = V_10 -> V_406 ,
. V_250 = V_10 -> V_406 ,
. integer = 1 ,
} ;
return F_223 ( V_399 , & V_409 ) ;
} else if ( V_408 -> V_250 < 64000 ) {
struct V_398 V_409 = {
. V_266 = V_10 -> V_407 ,
. V_250 = V_10 -> V_407 ,
. integer = 1 ,
} ;
return F_223 ( V_399 , & V_409 ) ;
}
return 0 ;
}
static int F_225 ( struct V_379 * V_380 ,
struct V_395 * V_396 )
{
struct V_10 * V_10 = V_396 -> V_397 ;
struct V_398 * V_399 = F_219 ( V_380 , V_400 ) ;
struct V_398 * V_408 = F_219 ( V_380 , V_383 ) ;
if ( V_399 -> V_266 >= V_10 -> V_407 ) {
struct V_398 V_409 = {
. V_266 = 32000 ,
. V_250 = 48000 ,
. integer = 1 ,
} ;
return F_223 ( V_408 , & V_409 ) ;
} else if ( V_399 -> V_250 <= V_10 -> V_405 && V_10 -> V_13 == V_18 ) {
struct V_398 V_409 = {
. V_266 = 128000 ,
. V_250 = 192000 ,
. integer = 1 ,
} ;
return F_223 ( V_408 , & V_409 ) ;
} else if ( V_399 -> V_250 <= V_10 -> V_406 ) {
struct V_398 V_409 = {
. V_266 = 64000 ,
. V_250 = 96000 ,
. integer = 1 ,
} ;
return F_223 ( V_408 , & V_409 ) ;
}
return 0 ;
}
static int F_226 ( struct V_379 * V_380 ,
struct V_395 * V_396 )
{
struct V_10 * V_10 = V_396 -> V_397 ;
struct V_398 * V_399 = F_219 ( V_380 , V_400 ) ;
struct V_398 * V_408 = F_219 ( V_380 , V_383 ) ;
if ( V_399 -> V_266 >= V_10 -> V_404 ) {
struct V_398 V_409 = {
. V_266 = 32000 ,
. V_250 = 48000 ,
. integer = 1 ,
} ;
return F_223 ( V_408 , & V_409 ) ;
} else if ( V_399 -> V_250 <= V_10 -> V_402 && V_10 -> V_13 == V_18 ) {
struct V_398 V_409 = {
. V_266 = 128000 ,
. V_250 = 192000 ,
. integer = 1 ,
} ;
return F_223 ( V_408 , & V_409 ) ;
} else if ( V_399 -> V_250 <= V_10 -> V_403 ) {
struct V_398 V_409 = {
. V_266 = 64000 ,
. V_250 = 96000 ,
. integer = 1 ,
} ;
return F_223 ( V_408 , & V_409 ) ;
}
return 0 ;
}
static int F_227 ( struct V_362 * V_159 )
{
struct V_10 * V_10 = F_196 ( V_159 ) ;
struct V_373 * V_374 = V_159 -> V_374 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
F_228 ( V_159 ) ;
V_374 -> V_410 = V_411 ;
V_374 -> V_412 = V_10 -> V_104 ;
V_374 -> V_413 = V_105 ;
V_10 -> V_66 = V_414 -> V_415 ;
V_10 -> V_360 = V_159 ;
F_46 ( & V_10 -> V_49 ) ;
F_229 ( V_374 , 0 , 32 , 24 ) ;
F_230 ( V_374 , 0 , V_384 , & V_416 ) ;
if ( V_10 -> V_223 ) {
V_374 -> V_410 . V_417 = V_374 -> V_410 . V_418 = V_10 -> V_118 ;
} else if ( V_10 -> V_13 == V_18 ) {
V_374 -> V_410 . V_418 = 192000 ;
V_374 -> V_410 . V_419 = V_420 ;
F_230 ( V_374 , 0 , V_383 , & V_421 ) ;
}
if ( V_10 -> V_13 == V_18 ) {
V_374 -> V_410 . V_422 = V_10 -> V_405 ;
V_374 -> V_410 . V_423 = V_10 -> V_407 ;
}
F_231 ( V_374 , 0 , V_400 ,
F_221 , V_10 ,
V_400 , - 1 ) ;
F_231 ( V_374 , 0 , V_400 ,
F_224 , V_10 ,
V_383 , - 1 ) ;
F_231 ( V_374 , 0 , V_383 ,
F_225 , V_10 ,
V_400 , - 1 ) ;
if ( V_16 != V_10 -> V_13 ) {
V_10 -> V_202 = V_10 -> V_200 ;
V_10 -> V_300 -> V_424 [ 0 ] . V_425 &= ~ V_426 ;
F_232 ( V_10 -> V_26 , V_427 |
V_428 , & V_10 -> V_300 -> V_138 ) ;
}
return 0 ;
}
static int F_233 ( struct V_362 * V_159 )
{
struct V_10 * V_10 = F_196 ( V_159 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_10 -> V_66 = - 1 ;
V_10 -> V_360 = NULL ;
F_46 ( & V_10 -> V_49 ) ;
if ( V_16 != V_10 -> V_13 ) {
V_10 -> V_300 -> V_424 [ 0 ] . V_425 |= V_426 ;
F_232 ( V_10 -> V_26 , V_427 |
V_428 , & V_10 -> V_300 -> V_138 ) ;
}
return 0 ;
}
static int F_234 ( struct V_362 * V_159 )
{
struct V_10 * V_10 = F_196 ( V_159 ) ;
struct V_373 * V_374 = V_159 -> V_374 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
F_228 ( V_159 ) ;
V_374 -> V_410 = V_429 ;
V_374 -> V_412 = V_10 -> V_315 ;
V_374 -> V_413 = V_105 ;
V_10 -> V_67 = V_414 -> V_415 ;
V_10 -> V_356 = V_159 ;
F_46 ( & V_10 -> V_49 ) ;
F_229 ( V_374 , 0 , 32 , 24 ) ;
F_230 ( V_374 , 0 , V_384 , & V_416 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_374 -> V_410 . V_422 = V_10 -> V_402 ;
V_374 -> V_410 . V_423 = V_10 -> V_404 ;
V_374 -> V_410 . V_418 = 192000 ;
V_374 -> V_410 . V_419 = V_420 ;
F_230 ( V_374 , 0 , V_383 , & V_421 ) ;
}
F_231 ( V_374 , 0 , V_400 ,
F_218 , V_10 ,
V_400 , - 1 ) ;
F_231 ( V_374 , 0 , V_400 ,
F_222 , V_10 ,
V_383 , - 1 ) ;
F_231 ( V_374 , 0 , V_383 ,
F_226 , V_10 ,
V_400 , - 1 ) ;
return 0 ;
}
static int F_235 ( struct V_362 * V_159 )
{
struct V_10 * V_10 = F_196 ( V_159 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_10 -> V_67 = - 1 ;
V_10 -> V_356 = NULL ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static inline int F_236 ( void T_6 * V_430 , void T_8 * V_368 )
{
T_2 V_21 = F_11 ( V_368 ) ;
return F_201 ( V_430 , & V_21 , 4 ) ;
}
static inline int F_237 ( void T_6 * V_430 , void T_8 * V_431 , void T_8 * V_432 )
{
T_2 V_433 , V_434 ;
T_4 V_435 ;
V_433 = F_11 ( V_431 ) ;
V_434 = F_11 ( V_432 ) ;
V_435 = ( ( T_4 ) V_434 << 32 ) | V_433 ;
return F_201 ( V_430 , & V_435 , 8 ) ;
}
static inline int F_238 ( void T_6 * V_430 , void T_8 * V_431 , void T_8 * V_432 )
{
T_2 V_433 , V_434 ;
T_4 V_435 ;
V_433 = F_11 ( V_431 ) & 0xffffff00 ;
V_434 = F_11 ( V_432 ) & 0xffffff00 ;
V_435 = ( ( T_4 ) V_434 << 32 ) | V_433 ;
return F_201 ( V_430 , & V_435 , 8 ) ;
}
static int F_239 ( struct V_10 * V_10 , struct V_436 T_6 * V_437 )
{
int V_438 = 0 ;
int V_23 , V_439 , V_440 , V_441 ;
if ( F_10 ( V_10 , V_24 ) & V_442 )
V_438 = 1 ;
V_440 = V_438 ? 14 : 26 ;
for ( V_23 = 0 , V_439 = 0 ; V_23 < 26 ; ++ V_23 ) {
if ( V_438 && ( V_23 & 4 ) )
continue;
V_441 = V_443 - V_439 * 4 ;
if ( F_236 ( & V_437 -> V_444 [ V_23 ] , V_10 -> V_22 + V_441 ) )
return - V_371 ;
V_441 -= V_440 * 4 ;
if ( F_236 ( & V_437 -> V_445 [ V_23 ] , V_10 -> V_22 + V_441 ) )
return - V_371 ;
V_441 -= V_440 * 4 ;
if ( F_236 ( & V_437 -> V_446 [ V_23 ] , V_10 -> V_22 + V_441 ) )
return - V_371 ;
V_441 = V_447 + V_439 * 8 ;
if ( F_238 ( & V_437 -> V_448 [ V_23 ] , V_10 -> V_22 + V_441 ,
V_10 -> V_22 + V_441 + 4 ) )
return - V_371 ;
V_441 += V_440 * 8 ;
if ( F_238 ( & V_437 -> V_449 [ V_23 ] , V_10 -> V_22 + V_441 ,
V_10 -> V_22 + V_441 + 4 ) )
return - V_371 ;
V_441 += V_440 * 8 ;
if ( F_238 ( & V_437 -> V_450 [ V_23 ] , V_10 -> V_22 + V_441 ,
V_10 -> V_22 + V_441 + 4 ) )
return - V_371 ;
V_439 ++ ;
}
return 0 ;
}
static int F_240 ( struct V_10 * V_10 , struct V_436 T_6 * V_437 )
{
int V_23 , V_439 ;
struct V_451 T_8 * V_452 ;
int V_438 = 0 ;
if ( F_10 ( V_10 , V_24 ) & V_442 )
V_438 = 1 ;
V_452 = (struct V_451 T_8 * ) ( V_10 -> V_22 + V_453 ) ;
for ( V_23 = 0 , V_439 = 0 ; V_23 < 16 ; ++ V_23 , ++ V_439 ) {
if ( F_236 ( & V_437 -> V_444 [ V_23 ] , & V_452 -> V_454 [ V_439 ] ) )
return - V_371 ;
if ( F_236 ( & V_437 -> V_445 [ V_23 ] , & V_452 -> V_455 [ V_439 ] ) )
return - V_371 ;
if ( F_236 ( & V_437 -> V_446 [ V_23 ] , & V_452 -> V_456 [ V_439 ] ) )
return - V_371 ;
if ( F_237 ( & V_437 -> V_448 [ V_23 ] , & V_452 -> V_457 [ V_439 ] ,
& V_452 -> V_458 [ V_439 ] ) )
return - V_371 ;
if ( F_237 ( & V_437 -> V_449 [ V_23 ] , & V_452 -> V_459 [ V_439 ] ,
& V_452 -> V_460 [ V_439 ] ) )
return - V_371 ;
if ( F_237 ( & V_437 -> V_450 [ V_23 ] , & V_452 -> V_461 [ V_439 ] ,
& V_452 -> V_462 [ V_439 ] ) )
return - V_371 ;
if ( V_438 && V_23 == 3 ) V_23 += 4 ;
}
return 0 ;
}
static int F_241 ( struct V_10 * V_10 , struct V_436 T_6 * V_437 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < 26 ; V_23 ++ ) {
if ( F_236 ( & V_437 -> V_445 [ V_23 ] ,
V_10 -> V_22 + V_463 + V_23 * 4 ) )
return - V_371 ;
if ( F_236 ( & V_437 -> V_444 [ V_23 ] ,
V_10 -> V_22 + V_464 + V_23 * 4 ) )
return - V_371 ;
}
for ( V_23 = 0 ; V_23 < 28 ; V_23 ++ ) {
if ( F_236 ( & V_437 -> V_446 [ V_23 ] ,
V_10 -> V_22 + V_465 + V_23 * 4 ) )
return - V_371 ;
}
for ( V_23 = 0 ; V_23 < 26 ; ++ V_23 ) {
if ( F_237 ( & V_437 -> V_449 [ V_23 ] ,
V_10 -> V_22 + V_466 + V_23 * 8 + 4 ,
V_10 -> V_22 + V_466 + V_23 * 8 ) )
return - V_371 ;
if ( F_237 ( & V_437 -> V_448 [ V_23 ] ,
V_10 -> V_22 + V_467 + V_23 * 8 + 4 ,
V_10 -> V_22 + V_467 + V_23 * 8 ) )
return - V_371 ;
}
return 0 ;
}
static int F_242 ( struct V_468 * V_410 , struct V_469 * V_469 , unsigned int V_388 , unsigned long V_342 )
{
struct V_10 * V_10 = V_410 -> V_163 ;
void T_6 * V_470 = ( void T_6 * ) V_342 ;
int V_296 ;
switch ( V_388 ) {
case V_471 : {
struct V_436 T_6 * V_437 = (struct V_436 T_6 * ) V_342 ;
V_296 = F_12 ( V_10 ) ;
if ( V_296 < 0 )
return V_296 ;
V_296 = F_26 ( V_10 , 1 ) ;
if ( V_296 < 0 )
return V_296 ;
if ( ! ( V_10 -> V_27 & V_28 ) ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_174 ) ;
return - V_119 ;
}
switch ( V_10 -> V_13 ) {
case V_19 :
return F_239 ( V_10 , V_437 ) ;
case V_18 :
return F_240 ( V_10 , V_437 ) ;
default:
return F_241 ( V_10 , V_437 ) ;
}
}
case V_472 : {
struct V_473 V_386 ;
unsigned long V_32 ;
int V_23 ;
V_296 = F_12 ( V_10 ) ;
if ( V_296 < 0 )
return V_296 ;
V_296 = F_26 ( V_10 , 1 ) ;
if ( V_296 < 0 )
return V_296 ;
memset ( & V_386 , 0 , sizeof( V_386 ) ) ;
F_22 ( & V_10 -> V_49 , V_32 ) ;
V_386 . V_308 = ( unsigned char ) F_129 ( V_10 ) ;
V_386 . V_474 = ( unsigned char ) F_146 ( V_10 ) ;
if ( V_10 -> V_13 != V_18 )
V_386 . V_475 = ( unsigned char ) F_150 ( V_10 ) ;
V_386 . V_476 = ( unsigned char ) F_148 ( V_10 ) ;
for ( V_23 = 0 ; V_23 < ( ( V_10 -> V_13 != V_14 && V_10 -> V_13 != V_16 && V_10 -> V_13 != V_18 ) ? 3 : 1 ) ; ++ V_23 )
V_386 . V_477 [ V_23 ] = ( unsigned char ) F_152 ( V_10 , V_23 ) ;
V_386 . V_478 = ( unsigned char ) F_87 ( V_10 ) ;
V_386 . V_479 = ( unsigned char ) F_94 ( V_10 ,
V_326 ) ;
V_386 . V_480 = ( unsigned char )
F_94 ( V_10 , V_185 ) ;
V_386 . V_481 = ( unsigned char )
F_94 ( V_10 , V_189 ) ;
V_386 . V_482 = ( unsigned char )
F_94 ( V_10 , V_187 ) ;
V_386 . V_483 = F_33 ( V_10 ) ;
V_386 . V_118 = V_10 -> V_118 ;
V_386 . V_484 = F_34 ( V_10 ) ;
V_386 . V_310 = ( unsigned char ) F_104 ( V_10 ) ;
V_386 . V_311 = ( unsigned char ) F_107 ( V_10 ) ;
V_386 . V_309 = ( unsigned char ) F_35 ( V_10 ) ;
V_386 . V_485 = ( unsigned char )
F_94 ( V_10 , V_318 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_386 . V_486 = ( unsigned char ) F_114 ( V_10 ) ;
V_386 . V_487 = ( unsigned char ) F_119 ( V_10 ) ;
V_386 . V_488 = ( unsigned char ) F_124 ( V_10 ) ;
V_386 . V_489 =
( unsigned char ) F_94 ( V_10 ,
V_332 ) ;
} else if ( V_10 -> V_13 == V_16 ) {
V_386 . V_486 = ( unsigned char ) F_159 ( V_10 ) ;
V_386 . V_487 = ( unsigned char ) F_164 ( V_10 ) ;
}
if ( V_10 -> V_13 == V_18 || V_10 -> V_13 == V_19 )
V_386 . V_490 =
( unsigned char ) F_94 ( V_10 ,
V_333 ) ;
F_24 ( & V_10 -> V_49 , V_32 ) ;
if ( F_201 ( V_470 , & V_386 , sizeof( V_386 ) ) )
return - V_371 ;
break;
}
case V_491 : {
struct V_492 V_493 ;
if ( V_10 -> V_13 != V_18 ) return - V_119 ;
V_493 . V_494 = V_10 -> V_404 - V_495 ;
V_493 . V_496 = V_10 -> V_407 - V_495 ;
if ( F_201 ( V_470 , & V_493 , sizeof( V_493 ) ) )
return - V_371 ;
break;
}
case V_497 : {
struct V_498 V_498 ;
int V_296 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) return - V_119 ;
if ( V_10 -> V_13 == V_499 ) {
if ( ( V_296 = F_25 ( V_10 ) ) < 0 )
return V_296 ;
}
memset ( & V_498 , 0 , sizeof( V_498 ) ) ;
V_498 . V_13 = V_10 -> V_13 ;
V_498 . V_17 = V_10 -> V_17 ;
if ( ( V_296 = F_201 ( V_470 , & V_498 , sizeof( V_498 ) ) ) )
return - V_371 ;
break;
}
case V_500 : {
struct V_501 T_6 * V_35 ;
T_2 T_6 * V_502 ;
int V_296 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) return - V_119 ;
if ( V_10 -> V_13 == V_499 ) return - V_119 ;
if ( V_10 -> V_27 & ( V_57 | V_28 ) )
return - V_129 ;
F_17 ( V_10 -> V_26 -> V_6 ,
L_175 ) ;
V_35 = (struct V_501 T_6 * ) V_470 ;
if ( F_243 ( V_502 , & V_35 -> V_502 ) )
return - V_371 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( ! V_10 -> V_34 ) {
V_10 -> V_34 = F_244 ( V_45 ) ;
if ( ! V_10 -> V_34 )
return - V_8 ;
}
if ( F_199 ( V_10 -> V_34 , V_502 ,
V_45 ) ) {
F_245 ( V_10 -> V_34 ) ;
V_10 -> V_34 = NULL ;
return - V_371 ;
}
V_10 -> V_27 |= V_57 ;
if ( ( V_296 = F_18 ( V_10 ) ) < 0 )
return V_296 ;
if ( ! ( V_10 -> V_27 & V_48 ) ) {
if ( ( V_296 = F_246 ( V_10 ) ) < 0 )
return V_296 ;
F_247 ( V_10 ) ;
F_248 ( V_10 ) ;
if ( ( V_296 = F_249 ( V_10 -> V_26 , V_10 ) ) < 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_176 ) ;
return V_296 ;
}
}
break;
}
case V_503 : {
struct V_504 T_6 * V_505 = (struct V_504 T_6 * ) V_470 ;
if ( F_201 ( V_505 -> V_506 , V_10 -> V_63 , sizeof( unsigned short ) * V_62 ) )
return - V_371 ;
break;
}
default:
return - V_119 ;
}
return 0 ;
}
static int F_250 ( struct V_170 * V_26 , struct V_10 * V_10 )
{
struct V_468 * V_410 ;
int V_296 ;
if ( ( V_296 = F_251 ( V_26 , L_177 , 0 , & V_410 ) ) < 0 )
return V_296 ;
V_10 -> V_507 = V_410 ;
V_410 -> V_163 = V_10 ;
strcpy ( V_410 -> V_173 , L_178 ) ;
V_410 -> V_508 . V_509 = F_242 ;
V_410 -> V_508 . V_510 = F_242 ;
return 0 ;
}
static int F_252 ( struct V_170 * V_26 , struct V_10 * V_10 )
{
struct V_511 * V_357 ;
int V_296 ;
if ( ( V_296 = F_253 ( V_26 , V_10 -> V_313 , 0 , 1 , 1 , & V_357 ) ) < 0 )
return V_296 ;
V_10 -> V_357 = V_357 ;
V_357 -> V_163 = V_10 ;
strcpy ( V_357 -> V_173 , V_10 -> V_313 ) ;
F_254 ( V_357 , V_361 , & V_512 ) ;
F_254 ( V_357 , V_359 , & V_513 ) ;
V_357 -> V_178 = V_514 ;
return 0 ;
}
static void F_190 ( struct V_10 * V_10 )
{
V_10 -> V_46 |= V_515 ;
F_8 ( V_10 , V_39 , V_10 -> V_46 ) ;
}
static int F_246 ( struct V_10 * V_10 )
{
int V_23 ;
if ( F_19 ( V_10 , 0 , 100 ) ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_179 ) ;
return - V_29 ;
}
for ( V_23 = 0 ; V_23 < V_10 -> V_270 ; ++ V_23 ) {
F_8 ( V_10 , V_516 + ( 4 * V_23 ) , 1 ) ;
F_8 ( V_10 , V_517 + ( 4 * V_23 ) , 1 ) ;
}
return 0 ;
}
static void F_247 ( struct V_10 * V_10 )
{
int V_68 , V_518 , V_519 ;
switch ( V_10 -> V_13 ) {
case V_15 :
V_10 -> V_313 = L_180 ;
V_10 -> V_404 = V_10 -> V_407 = V_520 ;
V_10 -> V_403 = V_10 -> V_406 = V_521 ;
break;
case V_19 :
V_10 -> V_313 = L_181 ;
V_10 -> V_404 = V_10 -> V_407 = V_522 ;
V_10 -> V_403 = V_10 -> V_406 = V_523 ;
break;
case V_18 :
V_68 = F_10 ( V_10 , V_24 ) ;
V_518 = ( V_68 & V_524 ) ? 0 : 4 ;
V_519 = ( V_68 & V_525 ) ? 0 : 4 ;
V_10 -> V_313 = L_182 ;
V_10 -> V_404 = V_495 + V_518 ;
V_10 -> V_403 = V_526 + V_518 ;
V_10 -> V_402 = V_527 + V_518 ;
V_10 -> V_407 = V_495 + V_519 ;
V_10 -> V_406 = V_526 + V_519 ;
V_10 -> V_405 = V_527 + V_519 ;
break;
case V_14 :
V_10 -> V_313 = L_183 ;
V_10 -> V_404 = V_10 -> V_407 = V_528 ;
V_10 -> V_403 = V_10 -> V_406 = V_529 ;
break;
case V_16 :
V_10 -> V_313 = L_184 ;
V_10 -> V_404 = V_530 - 1 ;
V_10 -> V_407 = V_530 ;
V_10 -> V_403 = V_530 - 1 ;
V_10 -> V_406 = V_530 ;
break;
default:
break;
}
}
static void F_248 ( struct V_10 * V_10 )
{
F_55 ( V_10 , 0 ) ;
F_55 ( V_10 , 1 ) ;
}
static int F_249 ( struct V_170 * V_26 , struct V_10 * V_10 )
{
int V_296 ;
if ( ( V_296 = F_252 ( V_26 , V_10 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_185 ) ;
return V_296 ;
}
if ( ( V_296 = F_72 ( V_26 , V_10 , 0 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_186 ) ;
return V_296 ;
}
if ( V_10 -> V_13 == V_15 || V_10 -> V_13 == V_19 ) {
if ( ( V_296 = F_72 ( V_26 , V_10 , 1 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_187 ) ;
return V_296 ;
}
}
if ( ( V_296 = F_178 ( V_26 , V_10 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_188 ) ;
return V_296 ;
}
F_184 ( V_10 ) ;
V_10 -> V_118 = - 1 ;
V_10 -> V_66 = - 1 ;
V_10 -> V_67 = - 1 ;
V_10 -> V_356 = NULL ;
V_10 -> V_360 = NULL ;
if ( ( V_296 = F_23 ( V_10 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_189 ) ;
return V_296 ;
}
if ( ! ( V_10 -> V_27 & V_48 ) ) {
strcpy ( V_26 -> V_172 , L_190 ) ;
sprintf ( V_26 -> V_531 , L_191 , V_10 -> V_313 ,
V_10 -> V_317 , V_10 -> V_316 ) ;
if ( ( V_296 = F_255 ( V_26 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_192 ) ;
return V_296 ;
}
V_10 -> V_27 |= V_48 ;
}
return 0 ;
}
static int F_27 ( struct V_10 * V_10 )
{
const char * V_532 ;
const struct V_35 * V_533 ;
int V_296 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
if ( V_10 -> V_13 == V_499 ) {
if ( ( V_296 = F_25 ( V_10 ) ) < 0 )
return V_296 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
}
switch ( V_10 -> V_13 ) {
case V_16 :
V_532 = L_193 ;
break;
case V_14 :
if ( V_10 -> V_17 == 0xa )
V_532 = L_194 ;
else
V_532 = L_195 ;
break;
case V_15 :
if ( V_10 -> V_17 == 0xa )
V_532 = L_196 ;
else
V_532 = L_197 ;
break;
default:
F_15 ( V_10 -> V_26 -> V_6 ,
L_198 , V_10 -> V_13 ) ;
return - V_119 ;
}
if ( F_256 ( & V_533 , V_532 , & V_10 -> V_2 -> V_6 ) ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_199 , V_532 ) ;
return - V_534 ;
}
if ( V_533 -> V_5 < V_45 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_200 ,
( int ) V_533 -> V_5 , V_45 ) ;
return - V_119 ;
}
V_10 -> V_35 = V_533 ;
V_10 -> V_27 |= V_57 ;
if ( ( V_296 = F_18 ( V_10 ) ) < 0 )
return V_296 ;
if ( ! ( V_10 -> V_27 & V_48 ) ) {
if ( ( V_296 = F_246 ( V_10 ) ) < 0 )
return V_296 ;
if ( ( V_296 = F_250 ( V_10 -> V_26 , V_10 ) ) < 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_201 ) ;
return V_296 ;
}
F_247 ( V_10 ) ;
F_248 ( V_10 ) ;
if ( ( V_296 = F_249 ( V_10 -> V_26 , V_10 ) ) < 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_176 ) ;
return V_296 ;
}
}
return 0 ;
}
static int F_257 ( struct V_170 * V_26 ,
struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_296 ;
int V_535 = 0 ;
int V_536 = 0 ;
V_10 -> V_316 = - 1 ;
V_10 -> V_27 = 0 ;
V_10 -> V_171 [ 0 ] . V_162 = NULL ;
V_10 -> V_171 [ 1 ] . V_162 = NULL ;
V_10 -> V_171 [ 0 ] . V_154 = NULL ;
V_10 -> V_171 [ 1 ] . V_154 = NULL ;
V_10 -> V_171 [ 0 ] . V_153 = NULL ;
V_10 -> V_171 [ 1 ] . V_153 = NULL ;
V_10 -> V_171 [ 0 ] . V_155 = 0 ;
V_10 -> V_171 [ 1 ] . V_155 = 0 ;
F_73 ( & V_10 -> V_171 [ 0 ] . V_49 ) ;
F_73 ( & V_10 -> V_171 [ 1 ] . V_49 ) ;
V_10 -> V_22 = NULL ;
V_10 -> V_92 = 0 ;
V_10 -> V_46 = 0 ;
V_10 -> V_13 = V_499 ;
V_10 -> V_270 = 26 ;
V_10 -> V_26 = V_26 ;
F_73 ( & V_10 -> V_49 ) ;
F_258 ( & V_10 -> V_164 , F_191 , ( unsigned long ) V_10 ) ;
F_259 ( V_10 -> V_2 , V_537 , & V_10 -> V_17 ) ;
V_10 -> V_17 &= 0xff ;
F_260 ( V_10 -> V_2 , V_538 , 0xFF ) ;
strcpy ( V_26 -> V_539 , L_202 ) ;
strcpy ( V_26 -> V_540 , L_203 ) ;
if ( V_10 -> V_17 < 0xa )
return - V_36 ;
else if ( V_10 -> V_17 < 0x64 )
V_10 -> V_313 = L_204 ;
else if ( V_10 -> V_17 < 0x96 ) {
V_10 -> V_313 = L_205 ;
V_535 = 1 ;
} else {
V_10 -> V_313 = L_206 ;
V_10 -> V_270 = 16 ;
V_536 = 1 ;
}
if ( ( V_296 = F_261 ( V_2 ) ) < 0 )
return V_296 ;
F_262 ( V_10 -> V_2 ) ;
if ( ( V_296 = F_263 ( V_2 , L_172 ) ) < 0 )
return V_296 ;
V_10 -> V_317 = F_264 ( V_2 , 0 ) ;
if ( ( V_10 -> V_22 = F_265 ( V_10 -> V_317 , V_541 ) ) == NULL ) {
F_15 ( V_10 -> V_26 -> V_6 , L_207 ,
V_10 -> V_317 , V_10 -> V_317 + V_541 - 1 ) ;
return - V_129 ;
}
if ( F_266 ( V_2 -> V_316 , F_192 , V_542 ,
V_543 , V_10 ) ) {
F_15 ( V_10 -> V_26 -> V_6 , L_208 , V_2 -> V_316 ) ;
return - V_129 ;
}
V_10 -> V_316 = V_2 -> V_316 ;
V_10 -> V_94 = 0 ;
V_10 -> V_265 = 1 ;
V_10 -> V_99 = 0 ;
if ( ( V_296 = F_188 ( V_10 ) ) < 0 )
return V_296 ;
if ( ! V_535 && ! V_536 ) {
V_296 = F_16 ( V_10 , 1000 , 10 ) ;
if ( V_296 < 0 )
return V_296 ;
if ( ( F_10 ( V_10 , V_24 ) & V_38 ) != 0 ) {
if ( ( V_296 = F_27 ( V_10 ) ) < 0 )
F_15 ( V_10 -> V_26 -> V_6 ,
L_209 ) ;
else
return 0 ;
F_17 ( V_10 -> V_26 -> V_6 ,
L_210 ) ;
if ( ( V_296 = F_250 ( V_26 , V_10 ) ) < 0 )
return V_296 ;
return 0 ;
} else {
F_17 ( V_10 -> V_26 -> V_6 ,
L_211 ) ;
if ( F_10 ( V_10 , V_53 ) & V_54 )
V_10 -> V_13 = V_16 ;
else if ( F_10 ( V_10 , V_53 ) & V_55 )
V_10 -> V_13 = V_14 ;
else
V_10 -> V_13 = V_15 ;
}
}
if ( ( V_296 = F_246 ( V_10 ) ) != 0 )
return V_296 ;
if ( V_535 )
V_10 -> V_13 = V_19 ;
if ( V_536 )
V_10 -> V_13 = V_18 ;
if ( ( V_296 = F_250 ( V_26 , V_10 ) ) < 0 )
return V_296 ;
F_247 ( V_10 ) ;
F_248 ( V_10 ) ;
V_10 -> V_27 |= V_28 ;
if ( ( V_296 = F_249 ( V_26 , V_10 ) ) < 0 )
return V_296 ;
return 0 ;
}
static int F_267 ( struct V_10 * V_10 )
{
if ( V_10 -> V_317 ) {
F_62 ( & V_10 -> V_164 ) ;
V_10 -> V_92 &= ~ ( V_102 | V_101 | V_157 | V_156 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
}
if ( V_10 -> V_316 >= 0 )
F_268 ( V_10 -> V_316 , ( void * ) V_10 ) ;
F_187 ( V_10 ) ;
if ( V_10 -> V_35 )
F_269 ( V_10 -> V_35 ) ;
F_245 ( V_10 -> V_34 ) ;
if ( V_10 -> V_22 )
F_270 ( V_10 -> V_22 ) ;
if ( V_10 -> V_317 )
F_271 ( V_10 -> V_2 ) ;
F_272 ( V_10 -> V_2 ) ;
return 0 ;
}
static void F_273 ( struct V_170 * V_26 )
{
struct V_10 * V_10 = V_26 -> V_163 ;
if ( V_10 )
F_267 ( V_10 ) ;
}
static int F_274 ( struct V_1 * V_2 ,
const struct V_544 * V_545 )
{
static int V_6 ;
struct V_10 * V_10 ;
struct V_170 * V_26 ;
int V_296 ;
if ( V_6 >= V_546 )
return - V_36 ;
if ( ! V_547 [ V_6 ] ) {
V_6 ++ ;
return - V_534 ;
}
V_296 = F_275 ( & V_2 -> V_6 , V_281 [ V_6 ] , V_138 [ V_6 ] , V_548 ,
sizeof( struct V_10 ) , & V_26 ) ;
if ( V_296 < 0 )
return V_296 ;
V_10 = V_26 -> V_163 ;
V_26 -> V_549 = F_273 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_2 = V_2 ;
if ( ( V_296 = F_257 ( V_26 , V_10 ) ) < 0 ) {
F_276 ( V_26 ) ;
return V_296 ;
}
strcpy ( V_26 -> V_172 , L_190 ) ;
sprintf ( V_26 -> V_531 , L_191 , V_10 -> V_313 ,
V_10 -> V_317 , V_10 -> V_316 ) ;
if ( ( V_296 = F_255 ( V_26 ) ) < 0 ) {
F_276 ( V_26 ) ;
return V_296 ;
}
F_277 ( V_2 , V_26 ) ;
V_6 ++ ;
return 0 ;
}
static void F_278 ( struct V_1 * V_2 )
{
F_276 ( F_279 ( V_2 ) ) ;
}
