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
static const char * const V_205 [ 4 ] = {
L_24 , L_25 , L_26 , L_27
} ;
struct V_10 * V_10 = F_80 ( V_192 ) ;
return F_92 ( V_194 , 1 , ( V_10 -> V_13 == V_18 ) ? 4 : 3 ,
V_205 ) ;
}
static int F_93 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_87 ( V_10 ) ;
return 0 ;
}
static int F_94 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_206 . V_207 [ 0 ] % ( ( V_10 -> V_13 == V_18 ) ? 4 : 3 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = V_21 != F_87 ( V_10 ) ;
if ( V_201 )
F_89 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_95 ( struct V_10 * V_10 , T_2 V_208 )
{
return ( V_10 -> V_92 & V_208 ) ? 1 : 0 ;
}
static int F_96 ( struct V_10 * V_10 , T_2 V_208 , int V_12 )
{
if ( V_12 )
V_10 -> V_92 |= V_208 ;
else
V_10 -> V_92 &= ~ V_208 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_97 ( struct V_191 * V_192 ,
struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
T_2 V_208 = V_192 -> V_203 ;
F_44 ( & V_10 -> V_49 ) ;
V_197 -> V_198 . integer . V_198 [ 0 ] = F_95 ( V_10 , V_208 ) ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_98 ( struct V_191 * V_192 ,
struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
T_2 V_208 = V_192 -> V_203 ;
int V_201 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . integer . V_198 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = ( int ) V_21 != F_95 ( V_10 , V_208 ) ;
if ( V_201 )
F_96 ( V_10 , V_208 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_99 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static const char * const V_205 [] = {
L_28 , L_29 , L_30 , L_31 , L_32 , L_33 ,
L_34 , L_35 , L_36 , L_37
} ;
struct V_10 * V_10 = F_80 ( V_192 ) ;
return F_92 ( V_194 , 1 , ( V_10 -> V_13 == V_18 ) ? 10 : 7 ,
V_205 ) ;
}
static int F_100 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
switch ( F_33 ( V_10 ) ) {
case 32000 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 0 ;
break;
case 44100 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 1 ;
break;
case 48000 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 2 ;
break;
case 64000 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 3 ;
break;
case 88200 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 4 ;
break;
case 96000 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 5 ;
break;
case 128000 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 7 ;
break;
case 176400 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 8 ;
break;
case 192000 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 9 ;
break;
default:
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_101 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
V_194 -> type = V_209 ;
V_194 -> V_58 = 1 ;
return 0 ;
}
static int F_102 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = V_10 -> V_118 ;
return 0 ;
}
static int F_103 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
static const char * const V_205 [] = {
L_28 , L_29 , L_30 , L_31 , L_32 , L_33 ,
L_34 , L_35 , L_36 , L_37
} ;
return F_92 ( V_194 , 1 , ( V_10 -> V_13 == V_18 ) ? 10 : 7 ,
V_205 ) ;
}
static int F_104 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
switch ( F_34 ( V_10 ) ) {
case 32000 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 0 ;
break;
case 44100 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 1 ;
break;
case 48000 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 2 ;
break;
case 64000 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 3 ;
break;
case 88200 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 4 ;
break;
case 96000 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 5 ;
break;
case 128000 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 7 ;
break;
case 176400 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 8 ;
break;
case 192000 :
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 9 ;
break;
default:
V_197 -> V_198 . V_206 . V_207 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_105 ( struct V_10 * V_10 )
{
if ( V_10 -> V_92 & V_114 )
return 0 ;
else if ( F_34 ( V_10 ) != V_10 -> V_118 )
return 0 ;
return 1 ;
}
static int F_106 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static const char * const V_205 [] = { L_38 , L_39 } ;
return F_92 ( V_194 , 1 , 2 , V_205 ) ;
}
static int F_107 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_105 ( V_10 ) ;
return 0 ;
}
static int F_108 ( struct V_10 * V_10 )
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
static int F_109 ( struct V_10 * V_10 , int V_210 )
{
int V_109 ;
switch ( V_210 ) {
case V_211 :
if ( F_34 ( V_10 ) != 0 ) {
if ( ! F_50 ( V_10 , F_34 ( V_10 ) , 1 ) ) {
V_10 -> V_92 &= ~ V_114 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
}
return - 1 ;
case V_212 :
V_109 = 32000 ;
break;
case V_213 :
V_109 = 44100 ;
break;
case V_214 :
V_109 = 48000 ;
break;
case V_215 :
V_109 = 64000 ;
break;
case V_216 :
V_109 = 88200 ;
break;
case V_217 :
V_109 = 96000 ;
break;
case V_218 :
V_109 = 128000 ;
break;
case V_219 :
V_109 = 176400 ;
break;
case V_220 :
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
static int F_110 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static const char * const V_205 [] = {
L_40 , L_41 , L_42 ,
L_43 , L_44 , L_45 ,
L_46 , L_47 , L_48 ,
L_49
} ;
struct V_10 * V_10 = F_80 ( V_192 ) ;
return F_92 ( V_194 , 1 , ( V_10 -> V_13 == V_18 ) ? 10 : 7 ,
V_205 ) ;
}
static int F_111 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_108 ( V_10 ) ;
return 0 ;
}
static int F_112 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_206 . V_207 [ 0 ] ;
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
V_201 = ( F_109 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_113 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . integer . V_198 [ 0 ] = V_10 -> V_221 ;
return 0 ;
}
static int F_114 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
V_201 = ( int ) V_197 -> V_198 . integer . V_198 [ 0 ] != V_10 -> V_221 ;
if ( V_201 )
V_10 -> V_221 = ! ! V_197 -> V_198 . integer . V_198 [ 0 ] ;
return V_201 ;
}
static int F_115 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_222 ) {
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
static int F_116 ( struct V_10 * V_10 , int V_210 )
{
V_10 -> V_92 &= ~ V_222 ;
switch ( V_210 ) {
case 0 :
V_10 -> V_92 |= V_223 ;
break;
case 1 :
V_10 -> V_92 |= V_224 ;
break;
case 2 :
V_10 -> V_92 |= V_225 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_117 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static const char * const V_205 [] = { L_50 , L_51 , L_52 } ;
return F_92 ( V_194 , 1 , 3 , V_205 ) ;
}
static int F_118 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_115 ( V_10 ) ;
return 0 ;
}
static int F_119 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_206 . V_207 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_115 ( V_10 ) )
V_201 = ( F_116 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_120 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_226 ) {
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
static int F_121 ( struct V_10 * V_10 , int V_210 )
{
V_10 -> V_92 &= ~ V_226 ;
switch ( V_210 ) {
case 0 :
V_10 -> V_92 |= V_227 ;
break;
case 1 :
V_10 -> V_92 |= V_228 ;
break;
case 2 :
V_10 -> V_92 |= V_229 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_122 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static const char * const V_205 [] = { L_53 , L_51 , L_54 } ;
return F_92 ( V_194 , 1 , 3 , V_205 ) ;
}
static int F_123 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_120 ( V_10 ) ;
return 0 ;
}
static int F_124 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_206 . V_207 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_120 ( V_10 ) )
V_201 = ( F_121 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_125 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_230 ) {
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
static int F_126 ( struct V_10 * V_10 , int V_210 )
{
V_10 -> V_92 &= ~ V_230 ;
switch ( V_210 ) {
case 0 :
V_10 -> V_92 |= V_231 ;
break;
case 1 :
V_10 -> V_92 |= V_232 ;
break;
case 2 :
V_10 -> V_92 |= V_233 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_127 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static const char * const V_205 [] = { L_55 , L_56 , L_57 } ;
return F_92 ( V_194 , 1 , 3 , V_205 ) ;
}
static int F_128 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_125 ( V_10 ) ;
return 0 ;
}
static int F_129 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_206 . V_207 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_125 ( V_10 ) )
V_201 = ( F_126 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_130 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_234 ) {
case V_235 :
return V_236 ;
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
default:
return V_244 ;
}
return 0 ;
}
static int F_131 ( struct V_10 * V_10 , int V_247 )
{
V_10 -> V_92 &= ~ V_234 ;
switch ( V_247 ) {
case V_236 :
V_10 -> V_92 &= ~ V_234 ;
break;
case V_238 :
V_10 -> V_92 |= V_237 ;
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
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_132 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static const char * const V_205 [] = {
L_58 , L_59 , L_60 , L_61 , L_62 , L_63
} ;
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_248 ;
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
return - V_119 ;
}
return F_92 ( V_194 , 1 , V_248 , V_205 ) ;
}
static int F_133 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_130 ( V_10 ) ;
return 0 ;
}
static int F_134 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 , V_249 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_249 = 6 ;
break;
case V_14 :
V_249 = 4 ;
break;
case V_18 :
V_249 = 3 ;
break;
default:
return - V_29 ;
}
V_21 = V_197 -> V_198 . V_206 . V_207 [ 0 ] % V_249 ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = ( int ) V_21 != F_130 ( V_10 ) ;
F_131 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_35 ( struct V_10 * V_10 )
{
unsigned int V_82 = F_10 ( V_10 , V_53 ) ;
switch ( V_82 & V_250 ) {
case V_251 :
return V_252 ;
case V_253 :
return V_254 ;
case V_255 :
return V_84 ;
case V_250 :
return V_256 ;
case V_257 :
return V_117 ;
case V_258 :
return V_259 ;
case V_260 :
return V_261 ;
default:
return V_252 ;
}
return 0 ;
}
static int F_135 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static const char * const V_205 [] = {
L_58 , L_61 , L_59 , L_34 , L_60 , L_62 , L_63
} ;
return F_92 ( V_194 , 1 , 7 , V_205 ) ;
}
static int F_136 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_35 ( V_10 ) ;
return 0 ;
}
static int F_137 ( struct V_10 * V_10 , int V_262 )
{
if ( V_262 )
V_10 -> V_94 = 1 ;
else
V_10 -> V_94 = 0 ;
return 0 ;
}
static int F_138 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_197 -> V_198 . integer . V_198 [ 0 ] = V_10 -> V_94 ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_139 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . integer . V_198 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = ( int ) V_21 != V_10 -> V_94 ;
F_137 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_140 ( struct V_10 * V_10 , int V_263 )
{
if ( V_263 )
V_10 -> V_264 = 1 ;
else
V_10 -> V_264 = 0 ;
return 0 ;
}
static int F_141 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_197 -> V_198 . integer . V_198 [ 0 ] = V_10 -> V_264 ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_142 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . integer . V_198 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = ( int ) V_21 != V_10 -> V_264 ;
F_140 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_143 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
V_194 -> type = V_209 ;
V_194 -> V_58 = 3 ;
V_194 -> V_198 . integer . V_265 = 0 ;
V_194 -> V_198 . integer . V_249 = 65536 ;
V_194 -> V_198 . integer . V_266 = 1 ;
return 0 ;
}
static int F_144 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_267 ;
int V_268 ;
int V_61 ;
V_267 = V_197 -> V_198 . integer . V_198 [ 0 ] ;
V_268 = V_197 -> V_198 . integer . V_198 [ 1 ] ;
if ( V_267 >= V_10 -> V_269 )
V_61 = F_6 ( V_10 , V_267 - V_10 -> V_269 , V_268 ) ;
else
V_61 = F_7 ( V_10 , V_267 , V_268 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_197 -> V_198 . integer . V_198 [ 2 ] = F_30 ( V_10 , V_61 ) ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_145 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_267 ;
int V_268 ;
int V_270 ;
int V_61 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_267 = V_197 -> V_198 . integer . V_198 [ 0 ] ;
V_268 = V_197 -> V_198 . integer . V_198 [ 1 ] ;
if ( V_267 >= V_10 -> V_269 )
V_61 = F_6 ( V_10 , V_267 - V_10 -> V_269 , V_268 ) ;
else
V_61 = F_7 ( V_10 , V_267 , V_268 ) ;
V_270 = V_197 -> V_198 . integer . V_198 [ 2 ] ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = V_270 != F_30 ( V_10 , V_61 ) ;
if ( V_201 )
F_31 ( V_10 , V_61 , V_270 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_146 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static const char * const V_205 [] = { L_64 , L_65 , L_66 } ;
return F_92 ( V_194 , 1 , 3 , V_205 ) ;
}
static int F_147 ( struct V_10 * V_10 )
{
int V_82 = F_10 ( V_10 , V_53 ) ;
if ( V_82 & V_271 ) {
if ( V_82 & V_272 )
return 2 ;
else
return 1 ;
} else
return 0 ;
return 0 ;
}
static int F_148 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_147 ( V_10 ) ;
return 0 ;
}
static int F_149 ( struct V_10 * V_10 )
{
int V_68 = F_10 ( V_10 , V_24 ) ;
if ( V_68 & V_72 )
return 0 ;
else {
if ( V_68 & V_273 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_150 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_149 ( V_10 ) ;
return 0 ;
}
static int F_151 ( struct V_10 * V_10 )
{
int V_68 = F_10 ( V_10 , V_24 ) ;
if ( V_68 & V_274 ) {
if ( V_68 & V_275 )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_152 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_151 ( V_10 ) ;
return 0 ;
}
static int F_153 ( struct V_10 * V_10 , int V_276 )
{
int V_68 = F_10 ( V_10 , V_24 ) ;
if ( V_68 & ( V_277 >> V_276 ) ) {
if ( V_68 & ( V_278 >> V_276 ) )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_154 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
int V_279 ;
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_279 = V_197 -> V_138 . V_280 - 1 ;
F_49 ( V_279 < 0 ) ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
if ( V_279 >= 3 )
return - V_119 ;
break;
case V_14 :
case V_18 :
if ( V_279 >= 1 )
return - V_119 ;
break;
default:
return - V_29 ;
}
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_153 ( V_10 , V_279 ) ;
return 0 ;
}
static int F_155 ( struct V_10 * V_10 )
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
static int F_156 ( struct V_10 * V_10 , int V_281 )
{
int V_109 = V_10 -> V_118 + V_281 ;
F_47 ( V_10 , V_109 ) ;
return 0 ;
}
static int F_157 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
V_194 -> type = V_209 ;
V_194 -> V_58 = 1 ;
V_194 -> V_198 . integer . V_265 = - 5000 ;
V_194 -> V_198 . integer . V_249 = 5000 ;
return 0 ;
}
static int F_158 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_155 ( V_10 ) ;
return 0 ;
}
static int F_159 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_206 . V_207 [ 0 ] ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_155 ( V_10 ) )
V_201 = ( F_156 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_160 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_282 ) {
case V_283 :
return 0 ;
case V_284 :
return 2 ;
case V_285 :
return 3 ;
case V_286 :
return 4 ;
}
return 1 ;
}
static int F_161 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_160 ( V_10 ) ;
return 0 ;
}
static int F_162 ( struct V_10 * V_10 , int V_210 )
{
V_10 -> V_92 &= ~ V_282 ;
switch ( V_210 ) {
case 0 :
V_10 -> V_92 |= V_283 ;
break;
case 1 :
break;
case 2 :
V_10 -> V_92 |= V_284 ;
break;
case 3 :
V_10 -> V_92 |= V_285 ;
break;
case 4 :
V_10 -> V_92 |= V_286 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_163 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_206 . V_207 [ 0 ] ;
if ( V_21 < 0 )
V_21 = 0 ;
if ( V_21 > 4 )
V_21 = 4 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_160 ( V_10 ) )
V_201 = ( F_162 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_164 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static const char * const V_205 [] = {
L_67 , L_68 , L_69 , L_70 , L_71
} ;
return F_92 ( V_194 , 1 , 5 , V_205 ) ;
}
static int F_165 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_287 ) {
case V_288 :
return 0 ;
case V_289 :
return 2 ;
case V_290 :
return 3 ;
case V_291 :
return 4 ;
}
return 1 ;
}
static int F_166 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . V_206 . V_207 [ 0 ] = F_165 ( V_10 ) ;
return 0 ;
}
static int F_167 ( struct V_10 * V_10 , int V_210 )
{
V_10 -> V_92 &= ~ V_287 ;
switch ( V_210 ) {
case 0 :
V_10 -> V_92 |= V_288 ;
break;
case 1 :
break;
case 2 :
V_10 -> V_92 |= V_289 ;
break;
case 3 :
V_10 -> V_92 |= V_290 ;
break;
case 4 :
V_10 -> V_92 |= V_291 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_168 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . V_206 . V_207 [ 0 ] ;
if ( V_21 < 0 )
V_21 = 0 ;
if ( V_21 > 4 )
V_21 = 4 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_165 ( V_10 ) )
V_201 = ( F_167 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_201 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_169 ( struct V_10 * V_10 )
{
return ( V_10 -> V_92 & V_292 ) ? 1 : 0 ;
}
static int F_170 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . integer . V_198 [ 0 ] = F_169 ( V_10 ) ;
return 0 ;
}
static int F_171 ( struct V_10 * V_10 , int V_293 )
{
if ( V_293 )
V_10 -> V_92 |= V_292 ;
else
V_10 -> V_92 &= ~ V_292 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_172 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . integer . V_198 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = ( int ) V_21 != F_169 ( V_10 ) ;
F_171 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_173 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static const char * const V_205 [] = { L_72 , L_73 } ;
return F_92 ( V_194 , 1 , 2 , V_205 ) ;
}
static int F_174 ( struct V_10 * V_10 )
{
return ( V_10 -> V_92 & V_294 ) ? 1 : 0 ;
}
static int F_175 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
V_197 -> V_198 . integer . V_198 [ 0 ] = F_174 ( V_10 ) ;
return 0 ;
}
static int F_176 ( struct V_10 * V_10 , int V_293 )
{
if ( V_293 )
V_10 -> V_92 |= V_294 ;
else
V_10 -> V_92 &= ~ V_294 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_177 ( struct V_191 * V_192 , struct V_196 * V_197 )
{
struct V_10 * V_10 = F_80 ( V_192 ) ;
int V_201 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_197 -> V_198 . integer . V_198 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_201 = ( int ) V_21 != F_174 ( V_10 ) ;
F_176 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_201 ;
}
static int F_178 ( struct V_191 * V_192 , struct V_193 * V_194 )
{
static const char * const V_205 [] = { L_72 , L_73 } ;
return F_92 ( V_194 , 1 , 2 , V_205 ) ;
}
static int F_179 ( struct V_170 * V_26 , struct V_10 * V_10 )
{
unsigned int V_276 ;
int V_295 ;
struct V_191 * V_296 ;
if ( V_10 -> V_13 == V_16 ) {
for ( V_276 = 0 ; V_276 < F_180 ( V_297 ) ; V_276 ++ ) {
V_295 = F_181 ( V_26 , V_296 = F_182 ( & V_297 [ V_276 ] , V_10 ) ) ;
if ( V_295 < 0 )
return V_295 ;
}
return 0 ;
}
for ( V_276 = 0 ; V_276 < F_180 ( V_298 ) ; V_276 ++ ) {
if ( ( V_295 = F_181 ( V_26 , V_296 = F_182 ( & V_298 [ V_276 ] , V_10 ) ) ) < 0 )
return V_295 ;
if ( V_276 == 1 )
V_10 -> V_299 = V_296 ;
}
V_300 . V_173 = L_74 ;
V_300 . V_280 = 1 ;
if ( ( V_295 = F_181 ( V_26 , V_296 = F_182 ( & V_300 , V_10 ) ) ) )
return V_295 ;
if ( V_10 -> V_13 == V_15 || V_10 -> V_13 == V_19 ) {
for ( V_276 = 1 ; V_276 < 3 ; ++ V_276 ) {
V_300 . V_280 = V_276 + 1 ;
if ( ( V_295 = F_181 ( V_26 , V_296 = F_182 ( & V_300 , V_10 ) ) ) )
return V_295 ;
}
}
if ( V_10 -> V_13 == V_18 ) {
for ( V_276 = 0 ; V_276 < F_180 ( V_301 ) ; V_276 ++ ) {
if ( ( V_295 = F_181 ( V_26 , V_296 = F_182 ( & V_301 [ V_276 ] , V_10 ) ) ) < 0 )
return V_295 ;
}
}
if ( V_10 -> V_13 == V_18 || V_10 -> V_13 == V_19 ) {
if ( ( V_295 = F_181 ( V_26 , V_296 = F_182 ( & V_302 , V_10 ) ) ) < 0 )
return V_295 ;
}
return 0 ;
}
static void
F_183 ( struct V_303 * V_304 , struct V_305 * V_306 )
{
struct V_10 * V_10 = V_304 -> V_163 ;
unsigned int V_68 ;
unsigned int V_82 ;
char * V_307 ;
char * V_308 ;
char * V_309 ;
char * V_310 ;
int V_311 ;
V_68 = F_10 ( V_10 , V_24 ) ;
V_82 = F_10 ( V_10 , V_53 ) ;
F_184 ( V_306 , L_75 , V_10 -> V_312 ,
V_10 -> V_26 -> V_313 + 1 ) ;
F_184 ( V_306 , L_76 ,
V_10 -> V_314 , V_10 -> V_104 ) ;
F_184 ( V_306 , L_77 ,
V_10 -> V_315 , V_10 -> V_316 , ( unsigned long ) V_10 -> V_22 ) ;
F_184 ( V_306 , L_78 , V_10 -> V_92 ) ;
F_184 ( V_306 , L_79 ,
V_10 -> V_46 ) ;
F_184 ( V_306 , L_80 , V_68 ) ;
F_184 ( V_306 , L_81 , V_82 ) ;
if ( F_12 ( V_10 ) ) {
F_184 ( V_306 , L_82
L_83 ) ;
return;
}
if ( F_26 ( V_10 , 0 ) ) {
if ( V_10 -> V_27 & V_57 ) {
if ( F_18 ( V_10 ) != 0 ) {
F_184 ( V_306 , L_84
L_85
L_86 ) ;
return;
}
} else {
int V_295 = - V_119 ;
V_295 = F_27 ( V_10 ) ;
if ( V_295 < 0 ) {
F_184 ( V_306 ,
L_87
L_88 ) ;
return;
}
}
}
F_184 ( V_306 , L_89 , F_10 ( V_10 , V_60 ) & 0xff ) ;
F_184 ( V_306 , L_90 , F_10 ( V_10 , V_147 ) ) ;
F_184 ( V_306 , L_91 , F_10 ( V_10 , V_144 ) ) ;
F_184 ( V_306 , L_92 , F_10 ( V_10 , V_146 ) ) ;
F_184 ( V_306 , L_93 , F_10 ( V_10 , V_143 ) ) ;
F_184 ( V_306 , L_94 , V_10 -> V_264 ? L_95 : L_96 ) ;
F_184 ( V_306 , L_97 ) ;
V_311 = 1 << ( 6 + F_37 ( V_10 -> V_92 & V_108 ) ) ;
F_184 ( V_306 , L_98 , V_311 , ( unsigned long ) V_10 -> V_91 ) ;
F_184 ( V_306 , L_99 , F_38 ( V_10 ) ) ;
F_184 ( V_306 , L_100 , V_10 -> V_94 ? L_95 : L_96 ) ;
F_184 ( V_306 , L_101 , ( V_10 -> V_92 & V_317 ) ? L_95 : L_96 ) ;
F_184 ( V_306 , L_102 , ( V_82 & V_318 ) | ( V_82 & V_55 ) << 1 | ( V_82 & V_54 ) << 2 ) ;
F_184 ( V_306 , L_97 ) ;
switch ( F_108 ( V_10 ) ) {
case V_211 :
V_310 = L_40 ;
break;
case V_212 :
V_310 = L_103 ;
break;
case V_213 :
V_310 = L_42 ;
break;
case V_214 :
V_310 = L_104 ;
break;
case V_215 :
V_310 = L_105 ;
break;
case V_216 :
V_310 = L_45 ;
break;
case V_217 :
V_310 = L_106 ;
break;
case V_218 :
V_310 = L_47 ;
break;
case V_219 :
V_310 = L_48 ;
break;
case V_220 :
V_310 = L_107 ;
break;
default:
V_310 = L_108 ;
}
F_184 ( V_306 , L_109 , V_310 ) ;
if ( F_105 ( V_10 ) )
V_309 = L_39 ;
else
V_309 = L_38 ;
switch ( F_130 ( V_10 ) ) {
case V_244 :
V_307 = L_110 ;
break;
case V_246 :
V_307 = L_61 ;
break;
case V_242 :
V_307 = L_111 ;
break;
case V_236 :
V_307 = L_60 ;
break;
case V_238 :
V_307 = L_62 ;
break;
case V_240 :
V_307 = L_63 ;
break;
default:
V_307 = L_110 ;
break;
}
F_184 ( V_306 , L_112 , V_307 ) ;
switch ( F_35 ( V_10 ) ) {
case V_252 :
V_308 = L_110 ;
break;
case V_254 :
V_308 = L_61 ;
break;
case V_84 :
V_308 = L_111 ;
break;
case V_256 :
V_308 = L_34 ;
break;
case V_117 :
V_308 = L_60 ;
break;
case V_259 :
V_308 = L_62 ;
break;
case V_261 :
V_308 = L_63 ;
break;
default:
V_308 = L_113 ;
break;
}
F_184 ( V_306 , L_114 , V_308 ) ;
F_184 ( V_306 , L_115 , F_34 ( V_10 ) ) ;
F_184 ( V_306 , L_116 , V_309 ) ;
F_184 ( V_306 , L_117 , V_10 -> V_118 ) ;
F_184 ( V_306 , L_118 , V_10 -> V_221 ? L_119 : L_120 ) ;
F_184 ( V_306 , L_97 ) ;
if ( V_10 -> V_13 != V_16 ) {
switch ( F_87 ( V_10 ) ) {
case V_319 :
F_184 ( V_306 , L_121 ) ;
break;
case V_320 :
F_184 ( V_306 , L_122 ) ;
break;
case V_321 :
F_184 ( V_306 , L_123 ) ;
break;
case V_322 :
F_184 ( V_306 , L_124 ) ;
break;
default:
F_184 ( V_306 , L_125 ) ;
break;
}
}
if ( V_16 == V_10 -> V_13 ) {
if ( V_10 -> V_92 & V_292 )
F_184 ( V_306 , L_126 ) ;
else
F_184 ( V_306 , L_127 ) ;
if ( V_10 -> V_92 & V_294 )
F_184 ( V_306 , L_128 ) ;
else
F_184 ( V_306 , L_129 ) ;
switch ( V_10 -> V_92 & V_282 ) {
case V_283 :
F_184 ( V_306 , L_130 ) ;
break;
case V_323 :
F_184 ( V_306 , L_131 ) ;
break;
case V_284 :
F_184 ( V_306 , L_132 ) ;
break;
case V_285 :
F_184 ( V_306 , L_133 ) ;
break;
case V_286 :
F_184 ( V_306 , L_134 ) ;
break;
default:
F_184 ( V_306 , L_135 ) ;
}
switch ( V_10 -> V_92 & V_287 ) {
case V_288 :
F_184 ( V_306 , L_136 ) ;
break;
case V_324 :
F_184 ( V_306 , L_137 ) ;
break;
case V_289 :
F_184 ( V_306 , L_138 ) ;
break;
case V_290 :
F_184 ( V_306 , L_139 ) ;
break;
case V_291 :
F_184 ( V_306 , L_140 ) ;
break;
default:
F_184 ( V_306 , L_141 ) ;
}
} else {
if ( V_10 -> V_92 & V_325 )
F_184 ( V_306 , L_142 ) ;
else
F_184 ( V_306 , L_143 ) ;
if ( V_10 -> V_92 & V_185 )
F_184 ( V_306 , L_144 ) ;
else
F_184 ( V_306 , L_145 ) ;
if ( V_10 -> V_92 & V_189 )
F_184 ( V_306 , L_146 ) ;
else
F_184 ( V_306 , L_147 ) ;
if ( V_10 -> V_92 & V_187 )
F_184 ( V_306 , L_148 ) ;
else
F_184 ( V_306 , L_149 ) ;
V_311 = F_33 ( V_10 ) ;
if ( V_311 != 0 )
F_184 ( V_306 , L_150 , V_311 ) ;
else
F_184 ( V_306 , L_151 ) ;
}
F_184 ( V_306 , L_97 ) ;
V_311 = V_68 & V_278 ;
if ( V_68 & V_277 )
F_184 ( V_306 , L_152 , V_311 ? L_66 : L_65 ) ;
else
F_184 ( V_306 , L_153 ) ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_311 = V_68 & V_326 ;
if ( V_68 & V_327 )
F_184 ( V_306 , L_154 , V_311 ? L_66 : L_65 ) ;
else
F_184 ( V_306 , L_155 ) ;
V_311 = V_68 & V_328 ;
if ( V_68 & V_329 )
F_184 ( V_306 , L_156 , V_311 ? L_66 : L_65 ) ;
else
F_184 ( V_306 , L_157 ) ;
break;
default:
break;
}
V_311 = V_68 & V_273 ;
if ( V_68 & V_72 )
F_184 ( V_306 , L_158 ) ;
else
F_184 ( V_306 , L_159 , V_311 ? L_66 : L_65 ) ;
V_311 = V_82 & V_272 ;
if ( V_82 & V_271 )
F_184 ( V_306 , L_160 , V_311 ? L_66 : L_65 ) ;
else
F_184 ( V_306 , L_161 ) ;
V_311 = V_68 & V_275 ;
if ( V_68 & V_274 )
F_184 ( V_306 , L_162 , V_311 ? L_66 : L_65 ) ;
else
F_184 ( V_306 , L_163 ) ;
F_184 ( V_306 , L_97 ) ;
if ( V_10 -> V_13 == V_18 ) {
char * V_330 ;
switch ( F_120 ( V_10 ) ) {
case 0 :
V_330 = L_53 ;
break;
case 1 :
V_330 = L_51 ;
break;
default:
V_330 = L_54 ;
break;
}
F_184 ( V_306 , L_164 , V_330 ) ;
switch ( F_115 ( V_10 ) ) {
case 0 :
V_330 = L_50 ;
break;
case 1 :
V_330 = L_51 ;
break;
default:
V_330 = L_53 ;
break;
}
F_184 ( V_306 , L_165 , V_330 ) ;
switch ( F_125 ( V_10 ) ) {
case 0 :
V_330 = L_55 ;
break;
case 1 :
V_330 = L_56 ;
break;
default:
V_330 = L_57 ;
break;
}
F_184 ( V_306 , L_166 , V_330 ) ;
F_184 ( V_306 , L_167 ,
F_95 ( V_10 , V_331 ) ?
L_168 : L_169 ) ;
if ( V_10 -> V_92 & V_332 )
F_184 ( V_306 , L_170 ) ;
else
F_184 ( V_306 , L_171 ) ;
F_184 ( V_306 , L_97 ) ;
}
}
static void F_185 ( struct V_10 * V_10 )
{
struct V_303 * V_304 ;
if ( ! F_186 ( V_10 -> V_26 , L_172 , & V_304 ) )
F_187 ( V_304 , V_10 , F_183 ) ;
}
static void F_188 ( struct V_10 * V_10 )
{
F_4 ( & V_10 -> V_333 , V_10 -> V_2 ) ;
F_4 ( & V_10 -> V_334 , V_10 -> V_2 ) ;
}
static int F_189 ( struct V_10 * V_10 )
{
unsigned long V_335 , V_336 ;
if ( F_1 ( V_10 -> V_2 , & V_10 -> V_333 , V_105 ) < 0 ||
F_1 ( V_10 -> V_2 , & V_10 -> V_334 , V_105 ) < 0 ) {
if ( V_10 -> V_333 . V_9 )
F_5 ( & V_10 -> V_333 ) ;
F_15 ( V_10 -> V_26 -> V_6 ,
L_173 , V_10 -> V_312 ) ;
return - V_8 ;
}
V_336 = F_190 ( V_10 -> V_333 . V_61 , 0x10000ul ) ;
V_335 = F_190 ( V_10 -> V_334 . V_61 , 0x10000ul ) ;
F_8 ( V_10 , V_337 , V_336 ) ;
F_8 ( V_10 , V_338 , V_335 ) ;
V_10 -> V_314 = V_10 -> V_333 . V_9 + ( V_336 - V_10 -> V_333 . V_61 ) ;
V_10 -> V_104 = V_10 -> V_334 . V_9 + ( V_335 - V_10 -> V_334 . V_61 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_10 )
{
unsigned int V_23 ;
V_10 -> V_92 = V_114 |
V_339 |
F_45 ( 7 ) |
V_317 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
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
for ( V_23 = 0 ; V_23 < V_62 ; ++ V_23 )
V_10 -> V_63 [ V_23 ] = V_340 ;
for ( V_23 = 0 ; V_23 < ( ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) ? 1352 : V_62 ) ; ++ V_23 ) {
if ( F_31 ( V_10 , V_23 , V_340 ) )
return - V_29 ;
}
if ( V_10 -> V_13 == V_18 ) {
V_10 -> V_92 |= ( V_224 | V_228 | V_231 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
}
F_50 ( V_10 , 48000 , 1 ) ;
return 0 ;
}
static void F_192 ( unsigned long V_341 )
{
struct V_10 * V_10 = (struct V_10 * ) V_341 ;
if ( V_10 -> V_171 [ 0 ] . V_155 )
F_59 ( & V_10 -> V_171 [ 0 ] ) ;
if ( V_10 -> V_171 [ 1 ] . V_155 )
F_59 ( & V_10 -> V_171 [ 1 ] ) ;
}
static T_5 F_193 ( int V_315 , void * V_342 )
{
struct V_10 * V_10 = (struct V_10 * ) V_342 ;
unsigned int V_68 ;
int V_343 ;
int V_344 ;
int V_345 ;
unsigned int V_346 ;
unsigned int V_347 ;
int V_348 = 0 ;
V_68 = F_10 ( V_10 , V_24 ) ;
V_343 = V_68 & V_349 ;
V_344 = V_68 & V_350 ;
V_345 = V_68 & V_351 ;
if ( ! V_343 && ! V_344 && ! V_345 )
return V_352 ;
F_8 ( V_10 , V_353 , 0 ) ;
V_346 = F_10 ( V_10 , V_144 ) & 0xff ;
V_347 = F_10 ( V_10 , V_143 ) & 0xff ;
if ( ! ( V_10 -> V_27 & V_48 ) )
return V_354 ;
if ( V_343 ) {
if ( V_10 -> V_355 )
F_194 ( V_10 -> V_356 -> V_357 [ V_358 ] . V_159 ) ;
if ( V_10 -> V_359 )
F_194 ( V_10 -> V_356 -> V_357 [ V_360 ] . V_159 ) ;
}
if ( V_344 && V_346 ) {
if ( V_10 -> V_264 ) {
V_10 -> V_92 &= ~ V_157 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
V_10 -> V_171 [ 0 ] . V_155 = 1 ;
V_348 = 1 ;
} else {
F_59 ( & V_10 -> V_171 [ 0 ] ) ;
}
}
if ( V_10 -> V_13 != V_14 && V_10 -> V_13 != V_16 && V_10 -> V_13 != V_18 && V_345 && V_347 ) {
if ( V_10 -> V_264 ) {
V_10 -> V_92 &= ~ V_156 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
V_10 -> V_171 [ 1 ] . V_155 = 1 ;
V_348 = 1 ;
} else {
F_59 ( & V_10 -> V_171 [ 1 ] ) ;
}
}
if ( V_10 -> V_264 && V_348 )
F_195 ( & V_10 -> V_164 ) ;
return V_354 ;
}
static T_3 F_196 ( struct V_361 * V_159 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
return F_38 ( V_10 ) ;
}
static char * F_198 ( struct V_10 * V_10 ,
int V_362 ,
int V_363 )
{
int V_364 ;
if ( F_49 ( V_363 < 0 || V_363 >= V_10 -> V_269 ) )
return NULL ;
if ( ( V_364 = V_10 -> V_131 [ V_363 ] ) < 0 )
return NULL ;
if ( V_362 == V_358 )
return V_10 -> V_314 + ( V_364 * V_365 ) ;
else
return V_10 -> V_104 + ( V_364 * V_365 ) ;
}
static int F_199 ( struct V_361 * V_159 , int V_363 ,
T_3 V_366 , void T_6 * V_367 , T_3 V_58 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
char * V_368 ;
if ( F_49 ( V_366 + V_58 > V_365 / 4 ) )
return - V_119 ;
V_368 = F_198 ( V_10 , V_159 -> V_369 -> V_362 , V_363 ) ;
if ( F_49 ( ! V_368 ) )
return - V_29 ;
if ( F_200 ( V_368 + V_366 * 4 , V_367 , V_58 * 4 ) )
return - V_370 ;
return V_58 ;
}
static int F_201 ( struct V_361 * V_159 , int V_363 ,
T_3 V_366 , void T_6 * V_371 , T_3 V_58 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
char * V_368 ;
if ( F_49 ( V_366 + V_58 > V_365 / 4 ) )
return - V_119 ;
V_368 = F_198 ( V_10 , V_159 -> V_369 -> V_362 , V_363 ) ;
if ( F_49 ( ! V_368 ) )
return - V_29 ;
if ( F_202 ( V_371 , V_368 + V_366 * 4 , V_58 * 4 ) )
return - V_370 ;
return V_58 ;
}
static int F_203 ( struct V_361 * V_159 , int V_363 ,
T_3 V_366 , T_3 V_58 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
char * V_368 ;
V_368 = F_198 ( V_10 , V_159 -> V_369 -> V_362 , V_363 ) ;
if ( F_49 ( ! V_368 ) )
return - V_29 ;
memset ( V_368 + V_366 * 4 , 0 , V_58 * 4 ) ;
return V_58 ;
}
static int F_204 ( struct V_361 * V_159 )
{
struct V_372 * V_373 = V_159 -> V_373 ;
struct V_10 * V_10 = F_197 ( V_159 ) ;
struct V_361 * V_374 ;
if ( V_159 -> V_362 == V_360 )
V_374 = V_10 -> V_355 ;
else
V_374 = V_10 -> V_359 ;
if ( V_10 -> V_375 )
V_373 -> V_68 -> V_376 = F_38 ( V_10 ) ;
else
V_373 -> V_68 -> V_376 = 0 ;
if ( V_374 ) {
struct V_361 * V_100 ;
struct V_372 * V_377 = V_374 -> V_373 ;
F_205 (s, substream) {
if ( V_100 == V_374 ) {
V_377 -> V_68 -> V_376 = V_373 -> V_68 -> V_376 ;
break;
}
}
}
return 0 ;
}
static int F_206 ( struct V_361 * V_159 ,
struct V_378 * V_379 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
int V_295 ;
T_7 V_380 ;
T_7 V_381 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_159 -> V_369 -> V_362 == V_360 ) {
V_10 -> V_92 &= ~ ( V_185 | V_187 | V_189 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 |= V_10 -> V_202 ) ;
V_380 = V_10 -> V_66 ;
V_381 = V_10 -> V_67 ;
} else {
V_380 = V_10 -> V_67 ;
V_381 = V_10 -> V_66 ;
}
if ( ( V_381 > 0 ) && ( V_380 != V_381 ) ) {
if ( F_207 ( V_379 ) != V_10 -> V_118 ) {
F_46 ( & V_10 -> V_49 ) ;
F_208 ( V_379 , V_382 ) ;
return - V_129 ;
}
if ( F_209 ( V_379 ) != V_10 -> V_91 / 4 ) {
F_46 ( & V_10 -> V_49 ) ;
F_208 ( V_379 , V_383 ) ;
return - V_129 ;
}
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
} else {
F_46 ( & V_10 -> V_49 ) ;
}
F_44 ( & V_10 -> V_49 ) ;
if ( ! V_10 -> V_221 ) {
if ( ( V_295 = F_50 ( V_10 , F_207 ( V_379 ) , 0 ) ) < 0 ) {
F_46 ( & V_10 -> V_49 ) ;
F_208 ( V_379 , V_382 ) ;
return V_295 ;
}
}
F_46 ( & V_10 -> V_49 ) ;
if ( ( V_295 = F_43 ( V_10 , F_209 ( V_379 ) ) ) < 0 ) {
F_208 ( V_379 , V_383 ) ;
return V_295 ;
}
return 0 ;
}
static int F_210 ( struct V_361 * V_159 ,
struct V_384 * V_385 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
int V_364 ;
if ( F_49 ( V_385 -> V_363 >= V_10 -> V_269 ) )
return - V_119 ;
if ( ( V_364 = V_10 -> V_131 [ V_385 -> V_363 ] ) < 0 )
return - V_119 ;
V_385 -> V_279 = V_364 * V_365 ;
V_385 -> V_386 = 0 ;
V_385 -> V_266 = 32 ;
return 0 ;
}
static int F_211 ( struct V_361 * V_159 ,
unsigned int V_387 , void * V_341 )
{
switch ( V_387 ) {
case V_388 :
return F_204 ( V_159 ) ;
case V_389 :
return F_210 ( V_159 , V_341 ) ;
default:
break;
}
return F_212 ( V_159 , V_387 , V_341 ) ;
}
static int F_213 ( struct V_361 * V_159 , int V_387 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
struct V_361 * V_374 ;
int V_375 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 0 ) )
return - V_29 ;
F_214 ( & V_10 -> V_49 ) ;
V_375 = V_10 -> V_375 ;
switch ( V_387 ) {
case V_390 :
V_375 |= 1 << V_159 -> V_362 ;
break;
case V_391 :
V_375 &= ~ ( 1 << V_159 -> V_362 ) ;
break;
default:
F_215 () ;
F_216 ( & V_10 -> V_49 ) ;
return - V_119 ;
}
if ( V_159 -> V_362 == V_360 )
V_374 = V_10 -> V_355 ;
else
V_374 = V_10 -> V_359 ;
if ( V_374 ) {
struct V_361 * V_100 ;
F_205 (s, substream) {
if ( V_100 == V_374 ) {
F_217 ( V_100 , V_159 ) ;
if ( V_387 == V_390 )
V_375 |= 1 << V_100 -> V_362 ;
else
V_375 &= ~ ( 1 << V_100 -> V_362 ) ;
goto V_392;
}
}
if ( V_387 == V_390 ) {
if ( ! ( V_375 & ( 1 << V_360 ) ) &&
V_159 -> V_362 == V_358 )
F_42 ( V_10 ) ;
} else {
if ( V_375 &&
V_159 -> V_362 == V_360 )
F_42 ( V_10 ) ;
}
} else {
if ( V_159 -> V_362 == V_358 )
F_42 ( V_10 ) ;
}
V_392:
F_217 ( V_159 , V_159 ) ;
if ( ! V_10 -> V_375 && V_375 )
F_40 ( V_10 ) ;
else if ( V_10 -> V_375 && ! V_375 )
F_41 ( V_10 ) ;
V_10 -> V_375 = V_375 ;
F_216 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_218 ( struct V_361 * V_159 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
int V_393 = 0 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
if ( ! V_10 -> V_375 )
F_39 ( V_10 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_393 ;
}
static int F_219 ( struct V_378 * V_379 ,
struct V_394 * V_395 )
{
struct V_10 * V_10 = V_395 -> V_396 ;
struct V_397 * V_398 = F_220 ( V_379 , V_399 ) ;
if ( V_10 -> V_13 == V_18 ) {
unsigned int V_400 [ 3 ] ;
V_400 [ 0 ] = V_10 -> V_401 ;
V_400 [ 1 ] = V_10 -> V_402 ;
V_400 [ 2 ] = V_10 -> V_403 ;
return F_221 ( V_398 , 3 , V_400 , 0 ) ;
} else {
unsigned int V_400 [ 2 ] ;
V_400 [ 0 ] = V_10 -> V_402 ;
V_400 [ 1 ] = V_10 -> V_403 ;
return F_221 ( V_398 , 2 , V_400 , 0 ) ;
}
}
static int F_222 ( struct V_378 * V_379 ,
struct V_394 * V_395 )
{
unsigned int V_400 [ 3 ] ;
struct V_10 * V_10 = V_395 -> V_396 ;
struct V_397 * V_398 = F_220 ( V_379 , V_399 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_400 [ 0 ] = V_10 -> V_404 ;
V_400 [ 1 ] = V_10 -> V_405 ;
V_400 [ 2 ] = V_10 -> V_406 ;
return F_221 ( V_398 , 3 , V_400 , 0 ) ;
} else {
V_400 [ 0 ] = V_10 -> V_405 ;
V_400 [ 1 ] = V_10 -> V_406 ;
}
return F_221 ( V_398 , 2 , V_400 , 0 ) ;
}
static int F_223 ( struct V_378 * V_379 ,
struct V_394 * V_395 )
{
struct V_10 * V_10 = V_395 -> V_396 ;
struct V_397 * V_398 = F_220 ( V_379 , V_399 ) ;
struct V_397 * V_407 = F_220 ( V_379 , V_382 ) ;
if ( V_407 -> V_265 > 96000 && V_10 -> V_13 == V_18 ) {
struct V_397 V_408 = {
. V_265 = V_10 -> V_401 ,
. V_249 = V_10 -> V_401 ,
. integer = 1 ,
} ;
return F_224 ( V_398 , & V_408 ) ;
} else if ( V_407 -> V_265 > 48000 && V_407 -> V_249 <= 96000 ) {
struct V_397 V_408 = {
. V_265 = V_10 -> V_402 ,
. V_249 = V_10 -> V_402 ,
. integer = 1 ,
} ;
return F_224 ( V_398 , & V_408 ) ;
} else if ( V_407 -> V_249 < 64000 ) {
struct V_397 V_408 = {
. V_265 = V_10 -> V_403 ,
. V_249 = V_10 -> V_403 ,
. integer = 1 ,
} ;
return F_224 ( V_398 , & V_408 ) ;
}
return 0 ;
}
static int F_225 ( struct V_378 * V_379 ,
struct V_394 * V_395 )
{
struct V_10 * V_10 = V_395 -> V_396 ;
struct V_397 * V_398 = F_220 ( V_379 , V_399 ) ;
struct V_397 * V_407 = F_220 ( V_379 , V_382 ) ;
if ( V_407 -> V_265 > 96000 && V_10 -> V_13 == V_18 ) {
struct V_397 V_408 = {
. V_265 = V_10 -> V_404 ,
. V_249 = V_10 -> V_404 ,
. integer = 1 ,
} ;
return F_224 ( V_398 , & V_408 ) ;
} else if ( V_407 -> V_265 > 48000 && V_407 -> V_249 <= 96000 ) {
struct V_397 V_408 = {
. V_265 = V_10 -> V_405 ,
. V_249 = V_10 -> V_405 ,
. integer = 1 ,
} ;
return F_224 ( V_398 , & V_408 ) ;
} else if ( V_407 -> V_249 < 64000 ) {
struct V_397 V_408 = {
. V_265 = V_10 -> V_406 ,
. V_249 = V_10 -> V_406 ,
. integer = 1 ,
} ;
return F_224 ( V_398 , & V_408 ) ;
}
return 0 ;
}
static int F_226 ( struct V_378 * V_379 ,
struct V_394 * V_395 )
{
struct V_10 * V_10 = V_395 -> V_396 ;
struct V_397 * V_398 = F_220 ( V_379 , V_399 ) ;
struct V_397 * V_407 = F_220 ( V_379 , V_382 ) ;
if ( V_398 -> V_265 >= V_10 -> V_406 ) {
struct V_397 V_408 = {
. V_265 = 32000 ,
. V_249 = 48000 ,
. integer = 1 ,
} ;
return F_224 ( V_407 , & V_408 ) ;
} else if ( V_398 -> V_249 <= V_10 -> V_404 && V_10 -> V_13 == V_18 ) {
struct V_397 V_408 = {
. V_265 = 128000 ,
. V_249 = 192000 ,
. integer = 1 ,
} ;
return F_224 ( V_407 , & V_408 ) ;
} else if ( V_398 -> V_249 <= V_10 -> V_405 ) {
struct V_397 V_408 = {
. V_265 = 64000 ,
. V_249 = 96000 ,
. integer = 1 ,
} ;
return F_224 ( V_407 , & V_408 ) ;
}
return 0 ;
}
static int F_227 ( struct V_378 * V_379 ,
struct V_394 * V_395 )
{
struct V_10 * V_10 = V_395 -> V_396 ;
struct V_397 * V_398 = F_220 ( V_379 , V_399 ) ;
struct V_397 * V_407 = F_220 ( V_379 , V_382 ) ;
if ( V_398 -> V_265 >= V_10 -> V_403 ) {
struct V_397 V_408 = {
. V_265 = 32000 ,
. V_249 = 48000 ,
. integer = 1 ,
} ;
return F_224 ( V_407 , & V_408 ) ;
} else if ( V_398 -> V_249 <= V_10 -> V_401 && V_10 -> V_13 == V_18 ) {
struct V_397 V_408 = {
. V_265 = 128000 ,
. V_249 = 192000 ,
. integer = 1 ,
} ;
return F_224 ( V_407 , & V_408 ) ;
} else if ( V_398 -> V_249 <= V_10 -> V_402 ) {
struct V_397 V_408 = {
. V_265 = 64000 ,
. V_249 = 96000 ,
. integer = 1 ,
} ;
return F_224 ( V_407 , & V_408 ) ;
}
return 0 ;
}
static int F_228 ( struct V_361 * V_159 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
struct V_372 * V_373 = V_159 -> V_373 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
F_229 ( V_159 ) ;
V_373 -> V_409 = V_410 ;
V_373 -> V_411 = V_10 -> V_104 ;
V_373 -> V_412 = V_105 ;
V_10 -> V_66 = V_413 -> V_414 ;
V_10 -> V_359 = V_159 ;
F_46 ( & V_10 -> V_49 ) ;
F_230 ( V_373 , 0 , 32 , 24 ) ;
F_231 ( V_373 , 0 , V_383 , & V_415 ) ;
if ( V_10 -> V_221 ) {
V_373 -> V_409 . V_416 = V_373 -> V_409 . V_417 = V_10 -> V_118 ;
} else if ( V_10 -> V_13 == V_18 ) {
V_373 -> V_409 . V_417 = 192000 ;
V_373 -> V_409 . V_418 = V_419 ;
F_231 ( V_373 , 0 , V_382 , & V_420 ) ;
}
if ( V_10 -> V_13 == V_18 ) {
V_373 -> V_409 . V_421 = V_10 -> V_404 ;
V_373 -> V_409 . V_422 = V_10 -> V_406 ;
}
F_232 ( V_373 , 0 , V_399 ,
F_222 , V_10 ,
V_399 , - 1 ) ;
F_232 ( V_373 , 0 , V_399 ,
F_225 , V_10 ,
V_382 , - 1 ) ;
F_232 ( V_373 , 0 , V_382 ,
F_226 , V_10 ,
V_399 , - 1 ) ;
if ( V_16 != V_10 -> V_13 ) {
V_10 -> V_202 = V_10 -> V_200 ;
V_10 -> V_299 -> V_423 [ 0 ] . V_424 &= ~ V_425 ;
F_233 ( V_10 -> V_26 , V_426 |
V_427 , & V_10 -> V_299 -> V_138 ) ;
}
return 0 ;
}
static int F_234 ( struct V_361 * V_159 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_10 -> V_66 = - 1 ;
V_10 -> V_359 = NULL ;
F_46 ( & V_10 -> V_49 ) ;
if ( V_16 != V_10 -> V_13 ) {
V_10 -> V_299 -> V_423 [ 0 ] . V_424 |= V_425 ;
F_233 ( V_10 -> V_26 , V_426 |
V_427 , & V_10 -> V_299 -> V_138 ) ;
}
return 0 ;
}
static int F_235 ( struct V_361 * V_159 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
struct V_372 * V_373 = V_159 -> V_373 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
F_229 ( V_159 ) ;
V_373 -> V_409 = V_428 ;
V_373 -> V_411 = V_10 -> V_314 ;
V_373 -> V_412 = V_105 ;
V_10 -> V_67 = V_413 -> V_414 ;
V_10 -> V_355 = V_159 ;
F_46 ( & V_10 -> V_49 ) ;
F_230 ( V_373 , 0 , 32 , 24 ) ;
F_231 ( V_373 , 0 , V_383 , & V_415 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_373 -> V_409 . V_421 = V_10 -> V_401 ;
V_373 -> V_409 . V_422 = V_10 -> V_403 ;
V_373 -> V_409 . V_417 = 192000 ;
V_373 -> V_409 . V_418 = V_419 ;
F_231 ( V_373 , 0 , V_382 , & V_420 ) ;
}
F_232 ( V_373 , 0 , V_399 ,
F_219 , V_10 ,
V_399 , - 1 ) ;
F_232 ( V_373 , 0 , V_399 ,
F_223 , V_10 ,
V_382 , - 1 ) ;
F_232 ( V_373 , 0 , V_382 ,
F_227 , V_10 ,
V_399 , - 1 ) ;
return 0 ;
}
static int F_236 ( struct V_361 * V_159 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_10 -> V_67 = - 1 ;
V_10 -> V_355 = NULL ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static inline int F_237 ( void T_6 * V_429 , void T_8 * V_367 )
{
T_2 V_21 = F_11 ( V_367 ) ;
return F_202 ( V_429 , & V_21 , 4 ) ;
}
static inline int F_238 ( void T_6 * V_429 , void T_8 * V_430 , void T_8 * V_431 )
{
T_2 V_432 , V_433 ;
T_4 V_434 ;
V_432 = F_11 ( V_430 ) ;
V_433 = F_11 ( V_431 ) ;
V_434 = ( ( T_4 ) V_433 << 32 ) | V_432 ;
return F_202 ( V_429 , & V_434 , 8 ) ;
}
static inline int F_239 ( void T_6 * V_429 , void T_8 * V_430 , void T_8 * V_431 )
{
T_2 V_432 , V_433 ;
T_4 V_434 ;
V_432 = F_11 ( V_430 ) & 0xffffff00 ;
V_433 = F_11 ( V_431 ) & 0xffffff00 ;
V_434 = ( ( T_4 ) V_433 << 32 ) | V_432 ;
return F_202 ( V_429 , & V_434 , 8 ) ;
}
static int F_240 ( struct V_10 * V_10 , struct V_435 T_6 * V_436 )
{
int V_437 = 0 ;
int V_23 , V_438 , V_439 , V_440 ;
if ( F_10 ( V_10 , V_24 ) & V_441 )
V_437 = 1 ;
V_439 = V_437 ? 14 : 26 ;
for ( V_23 = 0 , V_438 = 0 ; V_23 < 26 ; ++ V_23 ) {
if ( V_437 && ( V_23 & 4 ) )
continue;
V_440 = V_442 - V_438 * 4 ;
if ( F_237 ( & V_436 -> V_443 [ V_23 ] , V_10 -> V_22 + V_440 ) )
return - V_370 ;
V_440 -= V_439 * 4 ;
if ( F_237 ( & V_436 -> V_444 [ V_23 ] , V_10 -> V_22 + V_440 ) )
return - V_370 ;
V_440 -= V_439 * 4 ;
if ( F_237 ( & V_436 -> V_445 [ V_23 ] , V_10 -> V_22 + V_440 ) )
return - V_370 ;
V_440 = V_446 + V_438 * 8 ;
if ( F_239 ( & V_436 -> V_447 [ V_23 ] , V_10 -> V_22 + V_440 ,
V_10 -> V_22 + V_440 + 4 ) )
return - V_370 ;
V_440 += V_439 * 8 ;
if ( F_239 ( & V_436 -> V_448 [ V_23 ] , V_10 -> V_22 + V_440 ,
V_10 -> V_22 + V_440 + 4 ) )
return - V_370 ;
V_440 += V_439 * 8 ;
if ( F_239 ( & V_436 -> V_449 [ V_23 ] , V_10 -> V_22 + V_440 ,
V_10 -> V_22 + V_440 + 4 ) )
return - V_370 ;
V_438 ++ ;
}
return 0 ;
}
static int F_241 ( struct V_10 * V_10 , struct V_435 T_6 * V_436 )
{
int V_23 , V_438 ;
struct V_450 T_8 * V_451 ;
int V_437 = 0 ;
if ( F_10 ( V_10 , V_24 ) & V_441 )
V_437 = 1 ;
V_451 = (struct V_450 T_8 * ) ( V_10 -> V_22 + V_452 ) ;
for ( V_23 = 0 , V_438 = 0 ; V_23 < 16 ; ++ V_23 , ++ V_438 ) {
if ( F_237 ( & V_436 -> V_443 [ V_23 ] , & V_451 -> V_453 [ V_438 ] ) )
return - V_370 ;
if ( F_237 ( & V_436 -> V_444 [ V_23 ] , & V_451 -> V_454 [ V_438 ] ) )
return - V_370 ;
if ( F_237 ( & V_436 -> V_445 [ V_23 ] , & V_451 -> V_455 [ V_438 ] ) )
return - V_370 ;
if ( F_238 ( & V_436 -> V_447 [ V_23 ] , & V_451 -> V_456 [ V_438 ] ,
& V_451 -> V_457 [ V_438 ] ) )
return - V_370 ;
if ( F_238 ( & V_436 -> V_448 [ V_23 ] , & V_451 -> V_458 [ V_438 ] ,
& V_451 -> V_459 [ V_438 ] ) )
return - V_370 ;
if ( F_238 ( & V_436 -> V_449 [ V_23 ] , & V_451 -> V_460 [ V_438 ] ,
& V_451 -> V_461 [ V_438 ] ) )
return - V_370 ;
if ( V_437 && V_23 == 3 ) V_23 += 4 ;
}
return 0 ;
}
static int F_242 ( struct V_10 * V_10 , struct V_435 T_6 * V_436 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < 26 ; V_23 ++ ) {
if ( F_237 ( & V_436 -> V_444 [ V_23 ] ,
V_10 -> V_22 + V_462 + V_23 * 4 ) )
return - V_370 ;
if ( F_237 ( & V_436 -> V_443 [ V_23 ] ,
V_10 -> V_22 + V_463 + V_23 * 4 ) )
return - V_370 ;
}
for ( V_23 = 0 ; V_23 < 28 ; V_23 ++ ) {
if ( F_237 ( & V_436 -> V_445 [ V_23 ] ,
V_10 -> V_22 + V_464 + V_23 * 4 ) )
return - V_370 ;
}
for ( V_23 = 0 ; V_23 < 26 ; ++ V_23 ) {
if ( F_238 ( & V_436 -> V_448 [ V_23 ] ,
V_10 -> V_22 + V_465 + V_23 * 8 + 4 ,
V_10 -> V_22 + V_465 + V_23 * 8 ) )
return - V_370 ;
if ( F_238 ( & V_436 -> V_447 [ V_23 ] ,
V_10 -> V_22 + V_466 + V_23 * 8 + 4 ,
V_10 -> V_22 + V_466 + V_23 * 8 ) )
return - V_370 ;
}
return 0 ;
}
static int F_243 ( struct V_467 * V_409 , struct V_468 * V_468 , unsigned int V_387 , unsigned long V_341 )
{
struct V_10 * V_10 = V_409 -> V_163 ;
void T_6 * V_469 = ( void T_6 * ) V_341 ;
int V_295 ;
switch ( V_387 ) {
case V_470 : {
struct V_435 T_6 * V_436 = (struct V_435 T_6 * ) V_341 ;
V_295 = F_12 ( V_10 ) ;
if ( V_295 < 0 )
return V_295 ;
V_295 = F_26 ( V_10 , 1 ) ;
if ( V_295 < 0 )
return V_295 ;
if ( ! ( V_10 -> V_27 & V_28 ) ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_174 ) ;
return - V_119 ;
}
switch ( V_10 -> V_13 ) {
case V_19 :
return F_240 ( V_10 , V_436 ) ;
case V_18 :
return F_241 ( V_10 , V_436 ) ;
default:
return F_242 ( V_10 , V_436 ) ;
}
}
case V_471 : {
struct V_472 V_385 ;
unsigned long V_32 ;
int V_23 ;
V_295 = F_12 ( V_10 ) ;
if ( V_295 < 0 )
return V_295 ;
V_295 = F_26 ( V_10 , 1 ) ;
if ( V_295 < 0 )
return V_295 ;
memset ( & V_385 , 0 , sizeof( V_385 ) ) ;
F_22 ( & V_10 -> V_49 , V_32 ) ;
V_385 . V_307 = ( unsigned char ) F_130 ( V_10 ) ;
V_385 . V_473 = ( unsigned char ) F_147 ( V_10 ) ;
if ( V_10 -> V_13 != V_18 )
V_385 . V_474 = ( unsigned char ) F_151 ( V_10 ) ;
V_385 . V_475 = ( unsigned char ) F_149 ( V_10 ) ;
for ( V_23 = 0 ; V_23 < ( ( V_10 -> V_13 != V_14 && V_10 -> V_13 != V_16 && V_10 -> V_13 != V_18 ) ? 3 : 1 ) ; ++ V_23 )
V_385 . V_476 [ V_23 ] = ( unsigned char ) F_153 ( V_10 , V_23 ) ;
V_385 . V_477 = ( unsigned char ) F_87 ( V_10 ) ;
V_385 . V_478 = ( unsigned char ) F_95 ( V_10 ,
V_325 ) ;
V_385 . V_479 = ( unsigned char )
F_95 ( V_10 , V_185 ) ;
V_385 . V_480 = ( unsigned char )
F_95 ( V_10 , V_189 ) ;
V_385 . V_481 = ( unsigned char )
F_95 ( V_10 , V_187 ) ;
V_385 . V_482 = F_33 ( V_10 ) ;
V_385 . V_118 = V_10 -> V_118 ;
V_385 . V_483 = F_34 ( V_10 ) ;
V_385 . V_309 = ( unsigned char ) F_105 ( V_10 ) ;
V_385 . V_310 = ( unsigned char ) F_108 ( V_10 ) ;
V_385 . V_308 = ( unsigned char ) F_35 ( V_10 ) ;
V_385 . V_484 = ( unsigned char )
F_95 ( V_10 , V_317 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_385 . V_485 = ( unsigned char ) F_115 ( V_10 ) ;
V_385 . V_486 = ( unsigned char ) F_120 ( V_10 ) ;
V_385 . V_487 = ( unsigned char ) F_125 ( V_10 ) ;
V_385 . V_488 =
( unsigned char ) F_95 ( V_10 ,
V_331 ) ;
} else if ( V_10 -> V_13 == V_16 ) {
V_385 . V_485 = ( unsigned char ) F_160 ( V_10 ) ;
V_385 . V_486 = ( unsigned char ) F_165 ( V_10 ) ;
}
if ( V_10 -> V_13 == V_18 || V_10 -> V_13 == V_19 )
V_385 . V_489 =
( unsigned char ) F_95 ( V_10 ,
V_332 ) ;
F_24 ( & V_10 -> V_49 , V_32 ) ;
if ( F_202 ( V_469 , & V_385 , sizeof( V_385 ) ) )
return - V_370 ;
break;
}
case V_490 : {
struct V_491 V_492 ;
if ( V_10 -> V_13 != V_18 ) return - V_119 ;
V_492 . V_493 = V_10 -> V_403 - V_494 ;
V_492 . V_495 = V_10 -> V_406 - V_494 ;
if ( F_202 ( V_469 , & V_492 , sizeof( V_492 ) ) )
return - V_370 ;
break;
}
case V_496 : {
struct V_497 V_497 ;
int V_295 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) return - V_119 ;
if ( V_10 -> V_13 == V_498 ) {
if ( ( V_295 = F_25 ( V_10 ) ) < 0 )
return V_295 ;
}
memset ( & V_497 , 0 , sizeof( V_497 ) ) ;
V_497 . V_13 = V_10 -> V_13 ;
V_497 . V_17 = V_10 -> V_17 ;
if ( ( V_295 = F_202 ( V_469 , & V_497 , sizeof( V_497 ) ) ) )
return - V_370 ;
break;
}
case V_499 : {
struct V_500 T_6 * V_35 ;
T_2 T_6 * V_501 ;
int V_295 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) return - V_119 ;
if ( V_10 -> V_13 == V_498 ) return - V_119 ;
if ( V_10 -> V_27 & ( V_57 | V_28 ) )
return - V_129 ;
F_17 ( V_10 -> V_26 -> V_6 ,
L_175 ) ;
V_35 = (struct V_500 T_6 * ) V_469 ;
if ( F_244 ( V_501 , & V_35 -> V_501 ) )
return - V_370 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( ! V_10 -> V_34 ) {
V_10 -> V_34 = F_245 ( V_45 ) ;
if ( ! V_10 -> V_34 )
return - V_8 ;
}
if ( F_200 ( V_10 -> V_34 , V_501 ,
V_45 ) ) {
F_246 ( V_10 -> V_34 ) ;
V_10 -> V_34 = NULL ;
return - V_370 ;
}
V_10 -> V_27 |= V_57 ;
if ( ( V_295 = F_18 ( V_10 ) ) < 0 )
return V_295 ;
if ( ! ( V_10 -> V_27 & V_48 ) ) {
if ( ( V_295 = F_247 ( V_10 ) ) < 0 )
return V_295 ;
F_248 ( V_10 ) ;
F_249 ( V_10 ) ;
if ( ( V_295 = F_250 ( V_10 -> V_26 , V_10 ) ) < 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_176 ) ;
return V_295 ;
}
}
break;
}
case V_502 : {
struct V_503 T_6 * V_504 = (struct V_503 T_6 * ) V_469 ;
if ( F_202 ( V_504 -> V_505 , V_10 -> V_63 , sizeof( unsigned short ) * V_62 ) )
return - V_370 ;
break;
}
default:
return - V_119 ;
}
return 0 ;
}
static int F_251 ( struct V_170 * V_26 , struct V_10 * V_10 )
{
struct V_467 * V_409 ;
int V_295 ;
if ( ( V_295 = F_252 ( V_26 , L_177 , 0 , & V_409 ) ) < 0 )
return V_295 ;
V_10 -> V_506 = V_409 ;
V_409 -> V_163 = V_10 ;
strcpy ( V_409 -> V_173 , L_178 ) ;
V_409 -> V_507 . V_508 = F_243 ;
V_409 -> V_507 . V_509 = F_243 ;
return 0 ;
}
static int F_253 ( struct V_170 * V_26 , struct V_10 * V_10 )
{
struct V_510 * V_356 ;
int V_295 ;
if ( ( V_295 = F_254 ( V_26 , V_10 -> V_312 , 0 , 1 , 1 , & V_356 ) ) < 0 )
return V_295 ;
V_10 -> V_356 = V_356 ;
V_356 -> V_163 = V_10 ;
strcpy ( V_356 -> V_173 , V_10 -> V_312 ) ;
F_255 ( V_356 , V_360 , & V_511 ) ;
F_255 ( V_356 , V_358 , & V_512 ) ;
V_356 -> V_178 = V_513 ;
return 0 ;
}
static void F_191 ( struct V_10 * V_10 )
{
V_10 -> V_46 |= V_514 ;
F_8 ( V_10 , V_39 , V_10 -> V_46 ) ;
}
static int F_247 ( struct V_10 * V_10 )
{
int V_23 ;
if ( F_19 ( V_10 , 0 , 100 ) ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_179 ) ;
return - V_29 ;
}
for ( V_23 = 0 ; V_23 < V_10 -> V_269 ; ++ V_23 ) {
F_8 ( V_10 , V_515 + ( 4 * V_23 ) , 1 ) ;
F_8 ( V_10 , V_516 + ( 4 * V_23 ) , 1 ) ;
}
return 0 ;
}
static void F_248 ( struct V_10 * V_10 )
{
int V_68 , V_517 , V_518 ;
switch ( V_10 -> V_13 ) {
case V_15 :
V_10 -> V_312 = L_180 ;
V_10 -> V_403 = V_10 -> V_406 = V_519 ;
V_10 -> V_402 = V_10 -> V_405 = V_520 ;
break;
case V_19 :
V_10 -> V_312 = L_181 ;
V_10 -> V_403 = V_10 -> V_406 = V_521 ;
V_10 -> V_402 = V_10 -> V_405 = V_522 ;
break;
case V_18 :
V_68 = F_10 ( V_10 , V_24 ) ;
V_517 = ( V_68 & V_523 ) ? 0 : 4 ;
V_518 = ( V_68 & V_524 ) ? 0 : 4 ;
V_10 -> V_312 = L_182 ;
V_10 -> V_403 = V_494 + V_517 ;
V_10 -> V_402 = V_525 + V_517 ;
V_10 -> V_401 = V_526 + V_517 ;
V_10 -> V_406 = V_494 + V_518 ;
V_10 -> V_405 = V_525 + V_518 ;
V_10 -> V_404 = V_526 + V_518 ;
break;
case V_14 :
V_10 -> V_312 = L_183 ;
V_10 -> V_403 = V_10 -> V_406 = V_527 ;
V_10 -> V_402 = V_10 -> V_405 = V_528 ;
break;
case V_16 :
V_10 -> V_312 = L_184 ;
V_10 -> V_403 = V_529 - 1 ;
V_10 -> V_406 = V_529 ;
V_10 -> V_402 = V_529 - 1 ;
V_10 -> V_405 = V_529 ;
break;
default:
break;
}
}
static void F_249 ( struct V_10 * V_10 )
{
F_55 ( V_10 , 0 ) ;
F_55 ( V_10 , 1 ) ;
}
static int F_250 ( struct V_170 * V_26 , struct V_10 * V_10 )
{
int V_295 ;
if ( ( V_295 = F_253 ( V_26 , V_10 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_185 ) ;
return V_295 ;
}
if ( ( V_295 = F_72 ( V_26 , V_10 , 0 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_186 ) ;
return V_295 ;
}
if ( V_10 -> V_13 == V_15 || V_10 -> V_13 == V_19 ) {
if ( ( V_295 = F_72 ( V_26 , V_10 , 1 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_187 ) ;
return V_295 ;
}
}
if ( ( V_295 = F_179 ( V_26 , V_10 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_188 ) ;
return V_295 ;
}
F_185 ( V_10 ) ;
V_10 -> V_118 = - 1 ;
V_10 -> V_66 = - 1 ;
V_10 -> V_67 = - 1 ;
V_10 -> V_355 = NULL ;
V_10 -> V_359 = NULL ;
if ( ( V_295 = F_23 ( V_10 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_189 ) ;
return V_295 ;
}
if ( ! ( V_10 -> V_27 & V_48 ) ) {
strcpy ( V_26 -> V_172 , L_190 ) ;
sprintf ( V_26 -> V_530 , L_191 , V_10 -> V_312 ,
V_10 -> V_316 , V_10 -> V_315 ) ;
if ( ( V_295 = F_256 ( V_26 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_192 ) ;
return V_295 ;
}
V_10 -> V_27 |= V_48 ;
}
return 0 ;
}
static int F_27 ( struct V_10 * V_10 )
{
const char * V_531 ;
const struct V_35 * V_532 ;
int V_295 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
if ( V_10 -> V_13 == V_498 ) {
if ( ( V_295 = F_25 ( V_10 ) ) < 0 )
return V_295 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
}
switch ( V_10 -> V_13 ) {
case V_16 :
V_531 = L_193 ;
break;
case V_14 :
if ( V_10 -> V_17 == 0xa )
V_531 = L_194 ;
else
V_531 = L_195 ;
break;
case V_15 :
if ( V_10 -> V_17 == 0xa )
V_531 = L_196 ;
else
V_531 = L_197 ;
break;
default:
F_15 ( V_10 -> V_26 -> V_6 ,
L_198 , V_10 -> V_13 ) ;
return - V_119 ;
}
if ( F_257 ( & V_532 , V_531 , & V_10 -> V_2 -> V_6 ) ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_199 , V_531 ) ;
return - V_533 ;
}
if ( V_532 -> V_5 < V_45 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_200 ,
( int ) V_532 -> V_5 , V_45 ) ;
return - V_119 ;
}
V_10 -> V_35 = V_532 ;
V_10 -> V_27 |= V_57 ;
if ( ( V_295 = F_18 ( V_10 ) ) < 0 )
return V_295 ;
if ( ! ( V_10 -> V_27 & V_48 ) ) {
if ( ( V_295 = F_247 ( V_10 ) ) < 0 )
return V_295 ;
if ( ( V_295 = F_251 ( V_10 -> V_26 , V_10 ) ) < 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_201 ) ;
return V_295 ;
}
F_248 ( V_10 ) ;
F_249 ( V_10 ) ;
if ( ( V_295 = F_250 ( V_10 -> V_26 , V_10 ) ) < 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_176 ) ;
return V_295 ;
}
}
return 0 ;
}
static int F_258 ( struct V_170 * V_26 ,
struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_295 ;
int V_534 = 0 ;
int V_535 = 0 ;
V_10 -> V_315 = - 1 ;
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
V_10 -> V_13 = V_498 ;
V_10 -> V_269 = 26 ;
V_10 -> V_26 = V_26 ;
F_73 ( & V_10 -> V_49 ) ;
F_259 ( & V_10 -> V_164 , F_192 , ( unsigned long ) V_10 ) ;
F_260 ( V_10 -> V_2 , V_536 , & V_10 -> V_17 ) ;
V_10 -> V_17 &= 0xff ;
F_261 ( V_10 -> V_2 , V_537 , 0xFF ) ;
strcpy ( V_26 -> V_538 , L_202 ) ;
strcpy ( V_26 -> V_539 , L_203 ) ;
if ( V_10 -> V_17 < 0xa )
return - V_36 ;
else if ( V_10 -> V_17 < 0x64 )
V_10 -> V_312 = L_204 ;
else if ( V_10 -> V_17 < 0x96 ) {
V_10 -> V_312 = L_205 ;
V_534 = 1 ;
} else {
V_10 -> V_312 = L_206 ;
V_10 -> V_269 = 16 ;
V_535 = 1 ;
}
if ( ( V_295 = F_262 ( V_2 ) ) < 0 )
return V_295 ;
F_263 ( V_10 -> V_2 ) ;
if ( ( V_295 = F_264 ( V_2 , L_172 ) ) < 0 )
return V_295 ;
V_10 -> V_316 = F_265 ( V_2 , 0 ) ;
if ( ( V_10 -> V_22 = F_266 ( V_10 -> V_316 , V_540 ) ) == NULL ) {
F_15 ( V_10 -> V_26 -> V_6 , L_207 ,
V_10 -> V_316 , V_10 -> V_316 + V_540 - 1 ) ;
return - V_129 ;
}
if ( F_267 ( V_2 -> V_315 , F_193 , V_541 ,
V_542 , V_10 ) ) {
F_15 ( V_10 -> V_26 -> V_6 , L_208 , V_2 -> V_315 ) ;
return - V_129 ;
}
V_10 -> V_315 = V_2 -> V_315 ;
V_10 -> V_94 = 0 ;
V_10 -> V_264 = 1 ;
V_10 -> V_99 = 0 ;
if ( ( V_295 = F_189 ( V_10 ) ) < 0 )
return V_295 ;
if ( ! V_534 && ! V_535 ) {
V_295 = F_16 ( V_10 , 1000 , 10 ) ;
if ( V_295 < 0 )
return V_295 ;
if ( ( F_10 ( V_10 , V_24 ) & V_38 ) != 0 ) {
if ( ( V_295 = F_27 ( V_10 ) ) < 0 )
F_15 ( V_10 -> V_26 -> V_6 ,
L_209 ) ;
else
return 0 ;
F_17 ( V_10 -> V_26 -> V_6 ,
L_210 ) ;
if ( ( V_295 = F_251 ( V_26 , V_10 ) ) < 0 )
return V_295 ;
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
if ( ( V_295 = F_247 ( V_10 ) ) != 0 )
return V_295 ;
if ( V_534 )
V_10 -> V_13 = V_19 ;
if ( V_535 )
V_10 -> V_13 = V_18 ;
if ( ( V_295 = F_251 ( V_26 , V_10 ) ) < 0 )
return V_295 ;
F_248 ( V_10 ) ;
F_249 ( V_10 ) ;
V_10 -> V_27 |= V_28 ;
if ( ( V_295 = F_250 ( V_26 , V_10 ) ) < 0 )
return V_295 ;
return 0 ;
}
static int F_268 ( struct V_10 * V_10 )
{
if ( V_10 -> V_316 ) {
F_62 ( & V_10 -> V_164 ) ;
V_10 -> V_92 &= ~ ( V_102 | V_101 | V_157 | V_156 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
}
if ( V_10 -> V_315 >= 0 )
F_269 ( V_10 -> V_315 , ( void * ) V_10 ) ;
F_188 ( V_10 ) ;
F_270 ( V_10 -> V_35 ) ;
F_246 ( V_10 -> V_34 ) ;
if ( V_10 -> V_22 )
F_271 ( V_10 -> V_22 ) ;
if ( V_10 -> V_316 )
F_272 ( V_10 -> V_2 ) ;
F_273 ( V_10 -> V_2 ) ;
return 0 ;
}
static void F_274 ( struct V_170 * V_26 )
{
struct V_10 * V_10 = V_26 -> V_163 ;
if ( V_10 )
F_268 ( V_10 ) ;
}
static int F_275 ( struct V_1 * V_2 ,
const struct V_543 * V_544 )
{
static int V_6 ;
struct V_10 * V_10 ;
struct V_170 * V_26 ;
int V_295 ;
if ( V_6 >= V_545 )
return - V_36 ;
if ( ! V_546 [ V_6 ] ) {
V_6 ++ ;
return - V_533 ;
}
V_295 = F_276 ( & V_2 -> V_6 , V_280 [ V_6 ] , V_138 [ V_6 ] , V_547 ,
sizeof( struct V_10 ) , & V_26 ) ;
if ( V_295 < 0 )
return V_295 ;
V_10 = V_26 -> V_163 ;
V_26 -> V_548 = F_274 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_2 = V_2 ;
if ( ( V_295 = F_258 ( V_26 , V_10 ) ) < 0 ) {
F_277 ( V_26 ) ;
return V_295 ;
}
strcpy ( V_26 -> V_172 , L_190 ) ;
sprintf ( V_26 -> V_530 , L_191 , V_10 -> V_312 ,
V_10 -> V_316 , V_10 -> V_315 ) ;
if ( ( V_295 = F_256 ( V_26 ) ) < 0 ) {
F_277 ( V_26 ) ;
return V_295 ;
}
F_278 ( V_2 , V_26 ) ;
V_6 ++ ;
return 0 ;
}
static void F_279 ( struct V_1 * V_2 )
{
F_277 ( F_280 ( V_2 ) ) ;
}
