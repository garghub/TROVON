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
if ( V_149 -> V_165 )
F_64 ( & V_149 -> V_166 , 1 + V_167 ) ;
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
F_66 ( & V_149 -> V_166 , F_63 ,
( unsigned long ) V_149 ) ;
F_64 ( & V_149 -> V_166 , 1 + V_167 ) ;
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
static int F_72 ( struct V_168 * V_26 , struct V_10 * V_10 , int V_138 )
{
char V_152 [ 32 ] ;
V_10 -> V_169 [ V_138 ] . V_138 = V_138 ;
V_10 -> V_169 [ V_138 ] . V_162 = NULL ;
V_10 -> V_169 [ V_138 ] . V_154 = NULL ;
V_10 -> V_169 [ V_138 ] . V_153 = NULL ;
V_10 -> V_169 [ V_138 ] . V_10 = V_10 ;
V_10 -> V_169 [ V_138 ] . V_165 = 0 ;
V_10 -> V_169 [ V_138 ] . V_155 = 0 ;
F_73 ( & V_10 -> V_169 [ V_138 ] . V_49 ) ;
sprintf ( V_152 , L_22 , V_26 -> V_170 , V_138 + 1 ) ;
if ( F_74 ( V_26 , V_152 , V_138 , 1 , 1 , & V_10 -> V_169 [ V_138 ] . V_162 ) < 0 )
return - 1 ;
sprintf ( V_10 -> V_169 [ V_138 ] . V_162 -> V_171 , L_23 , V_138 + 1 ) ;
V_10 -> V_169 [ V_138 ] . V_162 -> V_163 = & V_10 -> V_169 [ V_138 ] ;
F_75 ( V_10 -> V_169 [ V_138 ] . V_162 , V_172 , & V_173 ) ;
F_75 ( V_10 -> V_169 [ V_138 ] . V_162 , V_174 , & V_175 ) ;
V_10 -> V_169 [ V_138 ] . V_162 -> V_176 |= V_177 |
V_178 |
V_179 ;
return 0 ;
}
static T_2 F_76 ( struct V_180 * V_181 )
{
T_2 V_21 = 0 ;
V_21 |= ( V_181 -> V_68 [ 0 ] & V_182 ) ? V_183 : 0 ;
V_21 |= ( V_181 -> V_68 [ 0 ] & V_184 ) ? V_185 : 0 ;
if ( V_21 & V_183 )
V_21 |= ( V_181 -> V_68 [ 0 ] & V_186 ) ? V_187 : 0 ;
else
V_21 |= ( V_181 -> V_68 [ 0 ] & V_188 ) ? V_187 : 0 ;
return V_21 ;
}
static void F_77 ( struct V_180 * V_181 , T_2 V_21 )
{
V_181 -> V_68 [ 0 ] = ( ( V_21 & V_183 ) ? V_182 : 0 ) |
( ( V_21 & V_185 ) ? V_184 : 0 ) ;
if ( V_21 & V_183 )
V_181 -> V_68 [ 0 ] |= ( V_21 & V_187 ) ? V_186 : 0 ;
else
V_181 -> V_68 [ 0 ] |= ( V_21 & V_187 ) ? V_188 : 0 ;
}
static int F_78 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
V_192 -> type = V_193 ;
V_192 -> V_58 = 1 ;
return 0 ;
}
static int F_79 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
F_77 ( & V_195 -> V_196 . V_197 , V_10 -> V_198 ) ;
return 0 ;
}
static int F_81 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
T_2 V_21 ;
V_21 = F_76 ( & V_195 -> V_196 . V_197 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_199 = V_21 != V_10 -> V_198 ;
V_10 -> V_198 = V_21 ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_82 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
V_192 -> type = V_193 ;
V_192 -> V_58 = 1 ;
return 0 ;
}
static int F_83 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
F_77 ( & V_195 -> V_196 . V_197 , V_10 -> V_200 ) ;
return 0 ;
}
static int F_84 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
T_2 V_21 ;
V_21 = F_76 ( & V_195 -> V_196 . V_197 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_199 = V_21 != V_10 -> V_200 ;
V_10 -> V_200 = V_21 ;
V_10 -> V_92 &= ~ ( V_183 | V_185 | V_187 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 |= V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_85 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
V_192 -> type = V_193 ;
V_192 -> V_58 = 1 ;
return 0 ;
}
static int F_86 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
V_195 -> V_196 . V_197 . V_68 [ 0 ] = V_190 -> V_201 ;
return 0 ;
}
static unsigned int F_87 ( struct V_10 * V_10 )
{
return F_88 ( V_10 -> V_92 & V_202 ) ;
}
static int F_89 ( struct V_10 * V_10 , int V_11 )
{
V_10 -> V_92 &= ~ V_202 ;
V_10 -> V_92 |= F_90 ( V_11 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_91 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [ 4 ] = {
L_24 , L_25 , L_26 , L_27
} ;
struct V_10 * V_10 = F_80 ( V_190 ) ;
return F_92 ( V_192 , 1 , ( V_10 -> V_13 == V_18 ) ? 4 : 3 ,
V_203 ) ;
}
static int F_93 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_87 ( V_10 ) ;
return 0 ;
}
static int F_94 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . V_204 . V_205 [ 0 ] % ( ( V_10 -> V_13 == V_18 ) ? 4 : 3 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_199 = V_21 != F_87 ( V_10 ) ;
if ( V_199 )
F_89 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_95 ( struct V_10 * V_10 , T_2 V_206 )
{
return ( V_10 -> V_92 & V_206 ) ? 1 : 0 ;
}
static int F_96 ( struct V_10 * V_10 , T_2 V_206 , int V_12 )
{
if ( V_12 )
V_10 -> V_92 |= V_206 ;
else
V_10 -> V_92 &= ~ V_206 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_97 ( struct V_189 * V_190 ,
struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
T_2 V_206 = V_190 -> V_201 ;
F_44 ( & V_10 -> V_49 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = F_95 ( V_10 , V_206 ) ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_98 ( struct V_189 * V_190 ,
struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
T_2 V_206 = V_190 -> V_201 ;
int V_199 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_199 = ( int ) V_21 != F_95 ( V_10 , V_206 ) ;
if ( V_199 )
F_96 ( V_10 , V_206 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_99 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [] = {
L_28 , L_29 , L_30 , L_31 , L_32 , L_33 ,
L_34 , L_35 , L_36 , L_37
} ;
struct V_10 * V_10 = F_80 ( V_190 ) ;
return F_92 ( V_192 , 1 , ( V_10 -> V_13 == V_18 ) ? 10 : 7 ,
V_203 ) ;
}
static int F_100 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
switch ( F_33 ( V_10 ) ) {
case 32000 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 0 ;
break;
case 44100 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 1 ;
break;
case 48000 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 2 ;
break;
case 64000 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 3 ;
break;
case 88200 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 4 ;
break;
case 96000 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 5 ;
break;
case 128000 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 7 ;
break;
case 176400 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 8 ;
break;
case 192000 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 9 ;
break;
default:
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 6 ;
}
return 0 ;
}
static int F_101 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
V_192 -> type = V_207 ;
V_192 -> V_58 = 1 ;
return 0 ;
}
static int F_102 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = V_10 -> V_118 ;
return 0 ;
}
static int F_103 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
static const char * const V_203 [] = {
L_28 , L_29 , L_30 , L_31 , L_32 , L_33 ,
L_34 , L_35 , L_36 , L_37
} ;
return F_92 ( V_192 , 1 , ( V_10 -> V_13 == V_18 ) ? 10 : 7 ,
V_203 ) ;
}
static int F_104 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
switch ( F_34 ( V_10 ) ) {
case 32000 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 0 ;
break;
case 44100 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 1 ;
break;
case 48000 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 2 ;
break;
case 64000 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 3 ;
break;
case 88200 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 4 ;
break;
case 96000 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 5 ;
break;
case 128000 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 7 ;
break;
case 176400 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 8 ;
break;
case 192000 :
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 9 ;
break;
default:
V_195 -> V_196 . V_204 . V_205 [ 0 ] = 6 ;
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
static int F_106 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [] = { L_38 , L_39 } ;
return F_92 ( V_192 , 1 , 2 , V_203 ) ;
}
static int F_107 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_105 ( V_10 ) ;
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
static int F_109 ( struct V_10 * V_10 , int V_208 )
{
int V_109 ;
switch ( V_208 ) {
case V_209 :
if ( F_34 ( V_10 ) != 0 ) {
if ( ! F_50 ( V_10 , F_34 ( V_10 ) , 1 ) ) {
V_10 -> V_92 &= ~ V_114 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
}
return - 1 ;
case V_210 :
V_109 = 32000 ;
break;
case V_211 :
V_109 = 44100 ;
break;
case V_212 :
V_109 = 48000 ;
break;
case V_213 :
V_109 = 64000 ;
break;
case V_214 :
V_109 = 88200 ;
break;
case V_215 :
V_109 = 96000 ;
break;
case V_216 :
V_109 = 128000 ;
break;
case V_217 :
V_109 = 176400 ;
break;
case V_218 :
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
static int F_110 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [] = {
L_40 , L_41 , L_42 ,
L_43 , L_44 , L_45 ,
L_46 , L_47 , L_48 ,
L_49
} ;
struct V_10 * V_10 = F_80 ( V_190 ) ;
return F_92 ( V_192 , 1 , ( V_10 -> V_13 == V_18 ) ? 10 : 7 ,
V_203 ) ;
}
static int F_111 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_108 ( V_10 ) ;
return 0 ;
}
static int F_112 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . V_204 . V_205 [ 0 ] ;
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
V_199 = ( F_109 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_113 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = V_10 -> V_219 ;
return 0 ;
}
static int F_114 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
V_199 = ( int ) V_195 -> V_196 . integer . V_196 [ 0 ] != V_10 -> V_219 ;
if ( V_199 )
V_10 -> V_219 = ! ! V_195 -> V_196 . integer . V_196 [ 0 ] ;
return V_199 ;
}
static int F_115 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_220 ) {
case V_221 :
return 0 ;
case V_222 :
return 1 ;
case V_223 :
return 2 ;
default:
return 1 ;
}
}
static int F_116 ( struct V_10 * V_10 , int V_208 )
{
V_10 -> V_92 &= ~ V_220 ;
switch ( V_208 ) {
case 0 :
V_10 -> V_92 |= V_221 ;
break;
case 1 :
V_10 -> V_92 |= V_222 ;
break;
case 2 :
V_10 -> V_92 |= V_223 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_117 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [] = { L_50 , L_51 , L_52 } ;
return F_92 ( V_192 , 1 , 3 , V_203 ) ;
}
static int F_118 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_115 ( V_10 ) ;
return 0 ;
}
static int F_119 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . V_204 . V_205 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_115 ( V_10 ) )
V_199 = ( F_116 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_120 ( struct V_10 * V_10 )
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
static int F_121 ( struct V_10 * V_10 , int V_208 )
{
V_10 -> V_92 &= ~ V_224 ;
switch ( V_208 ) {
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
static int F_122 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [] = { L_53 , L_51 , L_54 } ;
return F_92 ( V_192 , 1 , 3 , V_203 ) ;
}
static int F_123 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_120 ( V_10 ) ;
return 0 ;
}
static int F_124 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . V_204 . V_205 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_120 ( V_10 ) )
V_199 = ( F_121 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_125 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_228 ) {
case V_229 :
return 0 ;
case V_230 :
return 1 ;
case V_231 :
return 2 ;
default:
return 0 ;
}
}
static int F_126 ( struct V_10 * V_10 , int V_208 )
{
V_10 -> V_92 &= ~ V_228 ;
switch ( V_208 ) {
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
static int F_127 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [] = { L_55 , L_56 , L_57 } ;
return F_92 ( V_192 , 1 , 3 , V_203 ) ;
}
static int F_128 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_125 ( V_10 ) ;
return 0 ;
}
static int F_129 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . V_204 . V_205 [ 0 ] ;
if ( V_21 < 0 ) V_21 = 0 ;
if ( V_21 > 2 ) V_21 = 2 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_125 ( V_10 ) )
V_199 = ( F_126 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_130 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_232 ) {
case V_233 :
return V_234 ;
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
default:
return V_242 ;
}
return 0 ;
}
static int F_131 ( struct V_10 * V_10 , int V_245 )
{
V_10 -> V_92 &= ~ V_232 ;
switch ( V_245 ) {
case V_234 :
V_10 -> V_92 &= ~ V_232 ;
break;
case V_236 :
V_10 -> V_92 |= V_235 ;
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
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_132 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [] = {
L_58 , L_59 , L_60 , L_61 , L_62 , L_63
} ;
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_246 ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_246 = 6 ;
break;
case V_14 :
V_246 = 4 ;
break;
case V_18 :
V_246 = 3 ;
break;
default:
return - V_119 ;
}
return F_92 ( V_192 , 1 , V_246 , V_203 ) ;
}
static int F_133 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_130 ( V_10 ) ;
return 0 ;
}
static int F_134 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 , V_247 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
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
return - V_29 ;
}
V_21 = V_195 -> V_196 . V_204 . V_205 [ 0 ] % V_247 ;
F_44 ( & V_10 -> V_49 ) ;
V_199 = ( int ) V_21 != F_130 ( V_10 ) ;
F_131 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_35 ( struct V_10 * V_10 )
{
unsigned int V_82 = F_10 ( V_10 , V_53 ) ;
switch ( V_82 & V_248 ) {
case V_249 :
return V_250 ;
case V_251 :
return V_252 ;
case V_253 :
return V_84 ;
case V_248 :
return V_254 ;
case V_255 :
return V_117 ;
case V_256 :
return V_257 ;
case V_258 :
return V_259 ;
default:
return V_250 ;
}
return 0 ;
}
static int F_135 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [] = {
L_58 , L_61 , L_59 , L_34 , L_60 , L_62 , L_63
} ;
return F_92 ( V_192 , 1 , 7 , V_203 ) ;
}
static int F_136 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_35 ( V_10 ) ;
return 0 ;
}
static int F_137 ( struct V_10 * V_10 , int V_260 )
{
if ( V_260 )
V_10 -> V_94 = 1 ;
else
V_10 -> V_94 = 0 ;
return 0 ;
}
static int F_138 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = V_10 -> V_94 ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_139 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_199 = ( int ) V_21 != V_10 -> V_94 ;
F_137 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_140 ( struct V_10 * V_10 , int V_261 )
{
if ( V_261 )
V_10 -> V_262 = 1 ;
else
V_10 -> V_262 = 0 ;
return 0 ;
}
static int F_141 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = V_10 -> V_262 ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_142 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_199 = ( int ) V_21 != V_10 -> V_262 ;
F_140 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_143 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
V_192 -> type = V_207 ;
V_192 -> V_58 = 3 ;
V_192 -> V_196 . integer . V_263 = 0 ;
V_192 -> V_196 . integer . V_247 = 65536 ;
V_192 -> V_196 . integer . V_264 = 1 ;
return 0 ;
}
static int F_144 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_265 ;
int V_266 ;
int V_61 ;
V_265 = V_195 -> V_196 . integer . V_196 [ 0 ] ;
V_266 = V_195 -> V_196 . integer . V_196 [ 1 ] ;
if ( V_265 >= V_10 -> V_267 )
V_61 = F_6 ( V_10 , V_265 - V_10 -> V_267 , V_266 ) ;
else
V_61 = F_7 ( V_10 , V_265 , V_266 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_195 -> V_196 . integer . V_196 [ 2 ] = F_30 ( V_10 , V_61 ) ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_145 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
int V_265 ;
int V_266 ;
int V_268 ;
int V_61 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_265 = V_195 -> V_196 . integer . V_196 [ 0 ] ;
V_266 = V_195 -> V_196 . integer . V_196 [ 1 ] ;
if ( V_265 >= V_10 -> V_267 )
V_61 = F_6 ( V_10 , V_265 - V_10 -> V_267 , V_266 ) ;
else
V_61 = F_7 ( V_10 , V_265 , V_266 ) ;
V_268 = V_195 -> V_196 . integer . V_196 [ 2 ] ;
F_44 ( & V_10 -> V_49 ) ;
V_199 = V_268 != F_30 ( V_10 , V_61 ) ;
if ( V_199 )
F_31 ( V_10 , V_61 , V_268 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_146 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [] = { L_64 , L_65 , L_66 } ;
return F_92 ( V_192 , 1 , 3 , V_203 ) ;
}
static int F_147 ( struct V_10 * V_10 )
{
int V_82 = F_10 ( V_10 , V_53 ) ;
if ( V_82 & V_269 ) {
if ( V_82 & V_270 )
return 2 ;
else
return 1 ;
} else
return 0 ;
return 0 ;
}
static int F_148 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_147 ( V_10 ) ;
return 0 ;
}
static int F_149 ( struct V_10 * V_10 )
{
int V_68 = F_10 ( V_10 , V_24 ) ;
if ( V_68 & V_72 )
return 0 ;
else {
if ( V_68 & V_271 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_150 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_149 ( V_10 ) ;
return 0 ;
}
static int F_151 ( struct V_10 * V_10 )
{
int V_68 = F_10 ( V_10 , V_24 ) ;
if ( V_68 & V_272 ) {
if ( V_68 & V_273 )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_152 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_151 ( V_10 ) ;
return 0 ;
}
static int F_153 ( struct V_10 * V_10 , int V_274 )
{
int V_68 = F_10 ( V_10 , V_24 ) ;
if ( V_68 & ( V_275 >> V_274 ) ) {
if ( V_68 & ( V_276 >> V_274 ) )
return 2 ;
else
return 1 ;
} else
return 0 ;
}
static int F_154 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
int V_277 ;
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_277 = V_195 -> V_138 . V_278 - 1 ;
F_49 ( V_277 < 0 ) ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
if ( V_277 >= 3 )
return - V_119 ;
break;
case V_14 :
case V_18 :
if ( V_277 >= 1 )
return - V_119 ;
break;
default:
return - V_29 ;
}
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_153 ( V_10 , V_277 ) ;
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
static int F_156 ( struct V_10 * V_10 , int V_279 )
{
int V_109 = V_10 -> V_118 + V_279 ;
F_47 ( V_10 , V_109 ) ;
return 0 ;
}
static int F_157 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
V_192 -> type = V_207 ;
V_192 -> V_58 = 1 ;
V_192 -> V_196 . integer . V_263 = - 5000 ;
V_192 -> V_196 . integer . V_247 = 5000 ;
return 0 ;
}
static int F_158 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_155 ( V_10 ) ;
return 0 ;
}
static int F_159 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . V_204 . V_205 [ 0 ] ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_155 ( V_10 ) )
V_199 = ( F_156 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_160 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_280 ) {
case V_281 :
return 0 ;
case V_282 :
return 2 ;
case V_283 :
return 3 ;
case V_284 :
return 4 ;
}
return 1 ;
}
static int F_161 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_160 ( V_10 ) ;
return 0 ;
}
static int F_162 ( struct V_10 * V_10 , int V_208 )
{
V_10 -> V_92 &= ~ V_280 ;
switch ( V_208 ) {
case 0 :
V_10 -> V_92 |= V_281 ;
break;
case 1 :
break;
case 2 :
V_10 -> V_92 |= V_282 ;
break;
case 3 :
V_10 -> V_92 |= V_283 ;
break;
case 4 :
V_10 -> V_92 |= V_284 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_163 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . V_204 . V_205 [ 0 ] ;
if ( V_21 < 0 )
V_21 = 0 ;
if ( V_21 > 4 )
V_21 = 4 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_160 ( V_10 ) )
V_199 = ( F_162 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_164 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [] = {
L_67 , L_68 , L_69 , L_70 , L_71
} ;
return F_92 ( V_192 , 1 , 5 , V_203 ) ;
}
static int F_165 ( struct V_10 * V_10 )
{
switch ( V_10 -> V_92 & V_285 ) {
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
static int F_166 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . V_204 . V_205 [ 0 ] = F_165 ( V_10 ) ;
return 0 ;
}
static int F_167 ( struct V_10 * V_10 , int V_208 )
{
V_10 -> V_92 &= ~ V_285 ;
switch ( V_208 ) {
case 0 :
V_10 -> V_92 |= V_286 ;
break;
case 1 :
break;
case 2 :
V_10 -> V_92 |= V_287 ;
break;
case 3 :
V_10 -> V_92 |= V_288 ;
break;
case 4 :
V_10 -> V_92 |= V_289 ;
break;
default:
return - 1 ;
}
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_168 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . V_204 . V_205 [ 0 ] ;
if ( V_21 < 0 )
V_21 = 0 ;
if ( V_21 > 4 )
V_21 = 4 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_21 != F_165 ( V_10 ) )
V_199 = ( F_167 ( V_10 , V_21 ) == 0 ) ? 1 : 0 ;
else
V_199 = 0 ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_169 ( struct V_10 * V_10 )
{
return ( V_10 -> V_92 & V_290 ) ? 1 : 0 ;
}
static int F_170 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = F_169 ( V_10 ) ;
return 0 ;
}
static int F_171 ( struct V_10 * V_10 , int V_291 )
{
if ( V_291 )
V_10 -> V_92 |= V_290 ;
else
V_10 -> V_92 &= ~ V_290 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_172 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_199 = ( int ) V_21 != F_169 ( V_10 ) ;
F_171 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_173 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [] = { L_72 , L_73 } ;
return F_92 ( V_192 , 1 , 2 , V_203 ) ;
}
static int F_174 ( struct V_10 * V_10 )
{
return ( V_10 -> V_92 & V_292 ) ? 1 : 0 ;
}
static int F_175 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
V_195 -> V_196 . integer . V_196 [ 0 ] = F_174 ( V_10 ) ;
return 0 ;
}
static int F_176 ( struct V_10 * V_10 , int V_291 )
{
if ( V_291 )
V_10 -> V_92 |= V_292 ;
else
V_10 -> V_92 &= ~ V_292 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
return 0 ;
}
static int F_177 ( struct V_189 * V_190 , struct V_194 * V_195 )
{
struct V_10 * V_10 = F_80 ( V_190 ) ;
int V_199 ;
unsigned int V_21 ;
if ( ! F_32 ( V_10 ) )
return - V_129 ;
V_21 = V_195 -> V_196 . integer . V_196 [ 0 ] & 1 ;
F_44 ( & V_10 -> V_49 ) ;
V_199 = ( int ) V_21 != F_174 ( V_10 ) ;
F_176 ( V_10 , V_21 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_199 ;
}
static int F_178 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
static const char * const V_203 [] = { L_72 , L_73 } ;
return F_92 ( V_192 , 1 , 2 , V_203 ) ;
}
static int F_179 ( struct V_168 * V_26 , struct V_10 * V_10 )
{
unsigned int V_274 ;
int V_293 ;
struct V_189 * V_294 ;
if ( V_10 -> V_13 == V_16 ) {
for ( V_274 = 0 ; V_274 < F_180 ( V_295 ) ; V_274 ++ ) {
V_293 = F_181 ( V_26 , V_294 = F_182 ( & V_295 [ V_274 ] , V_10 ) ) ;
if ( V_293 < 0 )
return V_293 ;
}
return 0 ;
}
for ( V_274 = 0 ; V_274 < F_180 ( V_296 ) ; V_274 ++ ) {
if ( ( V_293 = F_181 ( V_26 , V_294 = F_182 ( & V_296 [ V_274 ] , V_10 ) ) ) < 0 )
return V_293 ;
if ( V_274 == 1 )
V_10 -> V_297 = V_294 ;
}
V_298 . V_171 = L_74 ;
V_298 . V_278 = 1 ;
if ( ( V_293 = F_181 ( V_26 , V_294 = F_182 ( & V_298 , V_10 ) ) ) )
return V_293 ;
if ( V_10 -> V_13 == V_15 || V_10 -> V_13 == V_19 ) {
for ( V_274 = 1 ; V_274 < 3 ; ++ V_274 ) {
V_298 . V_278 = V_274 + 1 ;
if ( ( V_293 = F_181 ( V_26 , V_294 = F_182 ( & V_298 , V_10 ) ) ) )
return V_293 ;
}
}
if ( V_10 -> V_13 == V_18 ) {
for ( V_274 = 0 ; V_274 < F_180 ( V_299 ) ; V_274 ++ ) {
if ( ( V_293 = F_181 ( V_26 , V_294 = F_182 ( & V_299 [ V_274 ] , V_10 ) ) ) < 0 )
return V_293 ;
}
}
if ( V_10 -> V_13 == V_18 || V_10 -> V_13 == V_19 ) {
if ( ( V_293 = F_181 ( V_26 , V_294 = F_182 ( & V_300 , V_10 ) ) ) < 0 )
return V_293 ;
}
return 0 ;
}
static void
F_183 ( struct V_301 * V_302 , struct V_303 * V_304 )
{
struct V_10 * V_10 = V_302 -> V_163 ;
unsigned int V_68 ;
unsigned int V_82 ;
char * V_305 ;
char * V_306 ;
char * V_307 ;
char * V_308 ;
int V_309 ;
V_68 = F_10 ( V_10 , V_24 ) ;
V_82 = F_10 ( V_10 , V_53 ) ;
F_184 ( V_304 , L_75 , V_10 -> V_310 ,
V_10 -> V_26 -> V_311 + 1 ) ;
F_184 ( V_304 , L_76 ,
V_10 -> V_312 , V_10 -> V_104 ) ;
F_184 ( V_304 , L_77 ,
V_10 -> V_313 , V_10 -> V_314 , ( unsigned long ) V_10 -> V_22 ) ;
F_184 ( V_304 , L_78 , V_10 -> V_92 ) ;
F_184 ( V_304 , L_79 ,
V_10 -> V_46 ) ;
F_184 ( V_304 , L_80 , V_68 ) ;
F_184 ( V_304 , L_81 , V_82 ) ;
if ( F_12 ( V_10 ) ) {
F_184 ( V_304 , L_82
L_83 ) ;
return;
}
if ( F_26 ( V_10 , 0 ) ) {
if ( V_10 -> V_27 & V_57 ) {
if ( F_18 ( V_10 ) != 0 ) {
F_184 ( V_304 , L_84
L_85
L_86 ) ;
return;
}
} else {
int V_293 = - V_119 ;
V_293 = F_27 ( V_10 ) ;
if ( V_293 < 0 ) {
F_184 ( V_304 ,
L_87
L_88 ) ;
return;
}
}
}
F_184 ( V_304 , L_89 , F_10 ( V_10 , V_60 ) & 0xff ) ;
F_184 ( V_304 , L_90 , F_10 ( V_10 , V_147 ) ) ;
F_184 ( V_304 , L_91 , F_10 ( V_10 , V_144 ) ) ;
F_184 ( V_304 , L_92 , F_10 ( V_10 , V_146 ) ) ;
F_184 ( V_304 , L_93 , F_10 ( V_10 , V_143 ) ) ;
F_184 ( V_304 , L_94 , V_10 -> V_262 ? L_95 : L_96 ) ;
F_184 ( V_304 , L_97 ) ;
V_309 = 1 << ( 6 + F_37 ( V_10 -> V_92 & V_108 ) ) ;
F_184 ( V_304 , L_98 , V_309 , ( unsigned long ) V_10 -> V_91 ) ;
F_184 ( V_304 , L_99 , F_38 ( V_10 ) ) ;
F_184 ( V_304 , L_100 , V_10 -> V_94 ? L_95 : L_96 ) ;
F_184 ( V_304 , L_101 , ( V_10 -> V_92 & V_315 ) ? L_95 : L_96 ) ;
F_184 ( V_304 , L_102 , ( V_82 & V_316 ) | ( V_82 & V_55 ) << 1 | ( V_82 & V_54 ) << 2 ) ;
F_184 ( V_304 , L_97 ) ;
switch ( F_108 ( V_10 ) ) {
case V_209 :
V_308 = L_40 ;
break;
case V_210 :
V_308 = L_103 ;
break;
case V_211 :
V_308 = L_42 ;
break;
case V_212 :
V_308 = L_104 ;
break;
case V_213 :
V_308 = L_105 ;
break;
case V_214 :
V_308 = L_45 ;
break;
case V_215 :
V_308 = L_106 ;
break;
case V_216 :
V_308 = L_47 ;
break;
case V_217 :
V_308 = L_48 ;
break;
case V_218 :
V_308 = L_107 ;
break;
default:
V_308 = L_108 ;
}
F_184 ( V_304 , L_109 , V_308 ) ;
if ( F_105 ( V_10 ) )
V_307 = L_39 ;
else
V_307 = L_38 ;
switch ( F_130 ( V_10 ) ) {
case V_242 :
V_305 = L_110 ;
break;
case V_244 :
V_305 = L_61 ;
break;
case V_240 :
V_305 = L_111 ;
break;
case V_234 :
V_305 = L_60 ;
break;
case V_236 :
V_305 = L_62 ;
break;
case V_238 :
V_305 = L_63 ;
break;
default:
V_305 = L_110 ;
break;
}
F_184 ( V_304 , L_112 , V_305 ) ;
switch ( F_35 ( V_10 ) ) {
case V_250 :
V_306 = L_110 ;
break;
case V_252 :
V_306 = L_61 ;
break;
case V_84 :
V_306 = L_111 ;
break;
case V_254 :
V_306 = L_34 ;
break;
case V_117 :
V_306 = L_60 ;
break;
case V_257 :
V_306 = L_62 ;
break;
case V_259 :
V_306 = L_63 ;
break;
default:
V_306 = L_113 ;
break;
}
F_184 ( V_304 , L_114 , V_306 ) ;
F_184 ( V_304 , L_115 , F_34 ( V_10 ) ) ;
F_184 ( V_304 , L_116 , V_307 ) ;
F_184 ( V_304 , L_117 , V_10 -> V_118 ) ;
F_184 ( V_304 , L_118 , V_10 -> V_219 ? L_119 : L_120 ) ;
F_184 ( V_304 , L_97 ) ;
if ( V_10 -> V_13 != V_16 ) {
switch ( F_87 ( V_10 ) ) {
case V_317 :
F_184 ( V_304 , L_121 ) ;
break;
case V_318 :
F_184 ( V_304 , L_122 ) ;
break;
case V_319 :
F_184 ( V_304 , L_123 ) ;
break;
case V_320 :
F_184 ( V_304 , L_124 ) ;
break;
default:
F_184 ( V_304 , L_125 ) ;
break;
}
}
if ( V_16 == V_10 -> V_13 ) {
if ( V_10 -> V_92 & V_290 )
F_184 ( V_304 , L_126 ) ;
else
F_184 ( V_304 , L_127 ) ;
if ( V_10 -> V_92 & V_292 )
F_184 ( V_304 , L_128 ) ;
else
F_184 ( V_304 , L_129 ) ;
switch ( V_10 -> V_92 & V_280 ) {
case V_281 :
F_184 ( V_304 , L_130 ) ;
break;
case V_321 :
F_184 ( V_304 , L_131 ) ;
break;
case V_282 :
F_184 ( V_304 , L_132 ) ;
break;
case V_283 :
F_184 ( V_304 , L_133 ) ;
break;
case V_284 :
F_184 ( V_304 , L_134 ) ;
break;
default:
F_184 ( V_304 , L_135 ) ;
}
switch ( V_10 -> V_92 & V_285 ) {
case V_286 :
F_184 ( V_304 , L_136 ) ;
break;
case V_322 :
F_184 ( V_304 , L_137 ) ;
break;
case V_287 :
F_184 ( V_304 , L_138 ) ;
break;
case V_288 :
F_184 ( V_304 , L_139 ) ;
break;
case V_289 :
F_184 ( V_304 , L_140 ) ;
break;
default:
F_184 ( V_304 , L_141 ) ;
}
} else {
if ( V_10 -> V_92 & V_323 )
F_184 ( V_304 , L_142 ) ;
else
F_184 ( V_304 , L_143 ) ;
if ( V_10 -> V_92 & V_183 )
F_184 ( V_304 , L_144 ) ;
else
F_184 ( V_304 , L_145 ) ;
if ( V_10 -> V_92 & V_187 )
F_184 ( V_304 , L_146 ) ;
else
F_184 ( V_304 , L_147 ) ;
if ( V_10 -> V_92 & V_185 )
F_184 ( V_304 , L_148 ) ;
else
F_184 ( V_304 , L_149 ) ;
V_309 = F_33 ( V_10 ) ;
if ( V_309 != 0 )
F_184 ( V_304 , L_150 , V_309 ) ;
else
F_184 ( V_304 , L_151 ) ;
}
F_184 ( V_304 , L_97 ) ;
V_309 = V_68 & V_276 ;
if ( V_68 & V_275 )
F_184 ( V_304 , L_152 , V_309 ? L_66 : L_65 ) ;
else
F_184 ( V_304 , L_153 ) ;
switch ( V_10 -> V_13 ) {
case V_15 :
case V_19 :
V_309 = V_68 & V_324 ;
if ( V_68 & V_325 )
F_184 ( V_304 , L_154 , V_309 ? L_66 : L_65 ) ;
else
F_184 ( V_304 , L_155 ) ;
V_309 = V_68 & V_326 ;
if ( V_68 & V_327 )
F_184 ( V_304 , L_156 , V_309 ? L_66 : L_65 ) ;
else
F_184 ( V_304 , L_157 ) ;
break;
default:
break;
}
V_309 = V_68 & V_271 ;
if ( V_68 & V_72 )
F_184 ( V_304 , L_158 ) ;
else
F_184 ( V_304 , L_159 , V_309 ? L_66 : L_65 ) ;
V_309 = V_82 & V_270 ;
if ( V_82 & V_269 )
F_184 ( V_304 , L_160 , V_309 ? L_66 : L_65 ) ;
else
F_184 ( V_304 , L_161 ) ;
V_309 = V_68 & V_273 ;
if ( V_68 & V_272 )
F_184 ( V_304 , L_162 , V_309 ? L_66 : L_65 ) ;
else
F_184 ( V_304 , L_163 ) ;
F_184 ( V_304 , L_97 ) ;
if ( V_10 -> V_13 == V_18 ) {
char * V_328 ;
switch ( F_120 ( V_10 ) ) {
case 0 :
V_328 = L_53 ;
break;
case 1 :
V_328 = L_51 ;
break;
default:
V_328 = L_54 ;
break;
}
F_184 ( V_304 , L_164 , V_328 ) ;
switch ( F_115 ( V_10 ) ) {
case 0 :
V_328 = L_50 ;
break;
case 1 :
V_328 = L_51 ;
break;
default:
V_328 = L_53 ;
break;
}
F_184 ( V_304 , L_165 , V_328 ) ;
switch ( F_125 ( V_10 ) ) {
case 0 :
V_328 = L_55 ;
break;
case 1 :
V_328 = L_56 ;
break;
default:
V_328 = L_57 ;
break;
}
F_184 ( V_304 , L_166 , V_328 ) ;
F_184 ( V_304 , L_167 ,
F_95 ( V_10 , V_329 ) ?
L_168 : L_169 ) ;
if ( V_10 -> V_92 & V_330 )
F_184 ( V_304 , L_170 ) ;
else
F_184 ( V_304 , L_171 ) ;
F_184 ( V_304 , L_97 ) ;
}
}
static void F_185 ( struct V_10 * V_10 )
{
struct V_301 * V_302 ;
if ( ! F_186 ( V_10 -> V_26 , L_172 , & V_302 ) )
F_187 ( V_302 , V_10 , F_183 ) ;
}
static void F_188 ( struct V_10 * V_10 )
{
F_4 ( & V_10 -> V_331 , V_10 -> V_2 ) ;
F_4 ( & V_10 -> V_332 , V_10 -> V_2 ) ;
}
static int F_189 ( struct V_10 * V_10 )
{
unsigned long V_333 , V_334 ;
if ( F_1 ( V_10 -> V_2 , & V_10 -> V_331 , V_105 ) < 0 ||
F_1 ( V_10 -> V_2 , & V_10 -> V_332 , V_105 ) < 0 ) {
if ( V_10 -> V_331 . V_9 )
F_5 ( & V_10 -> V_331 ) ;
F_15 ( V_10 -> V_26 -> V_6 ,
L_173 , V_10 -> V_310 ) ;
return - V_8 ;
}
V_334 = F_190 ( V_10 -> V_331 . V_61 , 0x10000ul ) ;
V_333 = F_190 ( V_10 -> V_332 . V_61 , 0x10000ul ) ;
F_8 ( V_10 , V_335 , V_334 ) ;
F_8 ( V_10 , V_336 , V_333 ) ;
V_10 -> V_312 = V_10 -> V_331 . V_9 + ( V_334 - V_10 -> V_331 . V_61 ) ;
V_10 -> V_104 = V_10 -> V_332 . V_9 + ( V_333 - V_10 -> V_332 . V_61 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_10 )
{
unsigned int V_23 ;
V_10 -> V_92 = V_114 |
V_337 |
F_45 ( 7 ) |
V_315 ;
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
V_10 -> V_63 [ V_23 ] = V_338 ;
for ( V_23 = 0 ; V_23 < ( ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) ? 1352 : V_62 ) ; ++ V_23 ) {
if ( F_31 ( V_10 , V_23 , V_338 ) )
return - V_29 ;
}
if ( V_10 -> V_13 == V_18 ) {
V_10 -> V_92 |= ( V_222 | V_226 | V_229 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
}
F_50 ( V_10 , 48000 , 1 ) ;
return 0 ;
}
static void F_192 ( unsigned long V_339 )
{
struct V_10 * V_10 = (struct V_10 * ) V_339 ;
if ( V_10 -> V_169 [ 0 ] . V_155 )
F_59 ( & V_10 -> V_169 [ 0 ] ) ;
if ( V_10 -> V_169 [ 1 ] . V_155 )
F_59 ( & V_10 -> V_169 [ 1 ] ) ;
}
static T_5 F_193 ( int V_313 , void * V_340 )
{
struct V_10 * V_10 = (struct V_10 * ) V_340 ;
unsigned int V_68 ;
int V_341 ;
int V_342 ;
int V_343 ;
unsigned int V_344 ;
unsigned int V_345 ;
int V_346 = 0 ;
V_68 = F_10 ( V_10 , V_24 ) ;
V_341 = V_68 & V_347 ;
V_342 = V_68 & V_348 ;
V_343 = V_68 & V_349 ;
if ( ! V_341 && ! V_342 && ! V_343 )
return V_350 ;
F_8 ( V_10 , V_351 , 0 ) ;
V_344 = F_10 ( V_10 , V_144 ) & 0xff ;
V_345 = F_10 ( V_10 , V_143 ) & 0xff ;
if ( ! ( V_10 -> V_27 & V_48 ) )
return V_352 ;
if ( V_341 ) {
if ( V_10 -> V_353 )
F_194 ( V_10 -> V_354 -> V_355 [ V_356 ] . V_159 ) ;
if ( V_10 -> V_357 )
F_194 ( V_10 -> V_354 -> V_355 [ V_358 ] . V_159 ) ;
}
if ( V_342 && V_344 ) {
if ( V_10 -> V_262 ) {
V_10 -> V_92 &= ~ V_157 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
V_10 -> V_169 [ 0 ] . V_155 = 1 ;
V_346 = 1 ;
} else {
F_59 ( & V_10 -> V_169 [ 0 ] ) ;
}
}
if ( V_10 -> V_13 != V_14 && V_10 -> V_13 != V_16 && V_10 -> V_13 != V_18 && V_343 && V_345 ) {
if ( V_10 -> V_262 ) {
V_10 -> V_92 &= ~ V_156 ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
V_10 -> V_169 [ 1 ] . V_155 = 1 ;
V_346 = 1 ;
} else {
F_59 ( & V_10 -> V_169 [ 1 ] ) ;
}
}
if ( V_10 -> V_262 && V_346 )
F_195 ( & V_10 -> V_164 ) ;
return V_352 ;
}
static T_3 F_196 ( struct V_359 * V_159 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
return F_38 ( V_10 ) ;
}
static char * F_198 ( struct V_10 * V_10 ,
int V_360 ,
int V_361 )
{
int V_362 ;
if ( F_49 ( V_361 < 0 || V_361 >= V_10 -> V_267 ) )
return NULL ;
if ( ( V_362 = V_10 -> V_131 [ V_361 ] ) < 0 )
return NULL ;
if ( V_360 == V_356 )
return V_10 -> V_312 + ( V_362 * V_363 ) ;
else
return V_10 -> V_104 + ( V_362 * V_363 ) ;
}
static int F_199 ( struct V_359 * V_159 , int V_361 ,
T_3 V_364 , void T_6 * V_365 , T_3 V_58 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
char * V_366 ;
if ( F_49 ( V_364 + V_58 > V_363 / 4 ) )
return - V_119 ;
V_366 = F_198 ( V_10 , V_159 -> V_367 -> V_360 , V_361 ) ;
if ( F_49 ( ! V_366 ) )
return - V_29 ;
if ( F_200 ( V_366 + V_364 * 4 , V_365 , V_58 * 4 ) )
return - V_368 ;
return V_58 ;
}
static int F_201 ( struct V_359 * V_159 , int V_361 ,
T_3 V_364 , void T_6 * V_369 , T_3 V_58 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
char * V_366 ;
if ( F_49 ( V_364 + V_58 > V_363 / 4 ) )
return - V_119 ;
V_366 = F_198 ( V_10 , V_159 -> V_367 -> V_360 , V_361 ) ;
if ( F_49 ( ! V_366 ) )
return - V_29 ;
if ( F_202 ( V_369 , V_366 + V_364 * 4 , V_58 * 4 ) )
return - V_368 ;
return V_58 ;
}
static int F_203 ( struct V_359 * V_159 , int V_361 ,
T_3 V_364 , T_3 V_58 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
char * V_366 ;
V_366 = F_198 ( V_10 , V_159 -> V_367 -> V_360 , V_361 ) ;
if ( F_49 ( ! V_366 ) )
return - V_29 ;
memset ( V_366 + V_364 * 4 , 0 , V_58 * 4 ) ;
return V_58 ;
}
static int F_204 ( struct V_359 * V_159 )
{
struct V_370 * V_371 = V_159 -> V_371 ;
struct V_10 * V_10 = F_197 ( V_159 ) ;
struct V_359 * V_372 ;
if ( V_159 -> V_360 == V_358 )
V_372 = V_10 -> V_353 ;
else
V_372 = V_10 -> V_357 ;
if ( V_10 -> V_373 )
V_371 -> V_68 -> V_374 = F_38 ( V_10 ) ;
else
V_371 -> V_68 -> V_374 = 0 ;
if ( V_372 ) {
struct V_359 * V_100 ;
struct V_370 * V_375 = V_372 -> V_371 ;
F_205 (s, substream) {
if ( V_100 == V_372 ) {
V_375 -> V_68 -> V_374 = V_371 -> V_68 -> V_374 ;
break;
}
}
}
return 0 ;
}
static int F_206 ( struct V_359 * V_159 ,
struct V_376 * V_377 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
int V_293 ;
T_7 V_378 ;
T_7 V_379 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
if ( V_159 -> V_367 -> V_360 == V_358 ) {
V_10 -> V_92 &= ~ ( V_183 | V_185 | V_187 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 |= V_10 -> V_200 ) ;
V_378 = V_10 -> V_66 ;
V_379 = V_10 -> V_67 ;
} else {
V_378 = V_10 -> V_67 ;
V_379 = V_10 -> V_66 ;
}
if ( ( V_379 > 0 ) && ( V_378 != V_379 ) ) {
if ( F_207 ( V_377 ) != V_10 -> V_118 ) {
F_46 ( & V_10 -> V_49 ) ;
F_208 ( V_377 , V_380 ) ;
return - V_129 ;
}
if ( F_209 ( V_377 ) != V_10 -> V_91 / 4 ) {
F_46 ( & V_10 -> V_49 ) ;
F_208 ( V_377 , V_381 ) ;
return - V_129 ;
}
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
} else {
F_46 ( & V_10 -> V_49 ) ;
}
F_44 ( & V_10 -> V_49 ) ;
if ( ! V_10 -> V_219 ) {
if ( ( V_293 = F_50 ( V_10 , F_207 ( V_377 ) , 0 ) ) < 0 ) {
F_46 ( & V_10 -> V_49 ) ;
F_208 ( V_377 , V_380 ) ;
return V_293 ;
}
}
F_46 ( & V_10 -> V_49 ) ;
if ( ( V_293 = F_43 ( V_10 , F_209 ( V_377 ) ) ) < 0 ) {
F_208 ( V_377 , V_381 ) ;
return V_293 ;
}
return 0 ;
}
static int F_210 ( struct V_359 * V_159 ,
struct V_382 * V_383 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
int V_362 ;
if ( F_49 ( V_383 -> V_361 >= V_10 -> V_267 ) )
return - V_119 ;
if ( ( V_362 = V_10 -> V_131 [ V_383 -> V_361 ] ) < 0 )
return - V_119 ;
V_383 -> V_277 = V_362 * V_363 ;
V_383 -> V_384 = 0 ;
V_383 -> V_264 = 32 ;
return 0 ;
}
static int F_211 ( struct V_359 * V_159 ,
unsigned int V_385 , void * V_339 )
{
switch ( V_385 ) {
case V_386 :
return F_204 ( V_159 ) ;
case V_387 :
return F_210 ( V_159 , V_339 ) ;
default:
break;
}
return F_212 ( V_159 , V_385 , V_339 ) ;
}
static int F_213 ( struct V_359 * V_159 , int V_385 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
struct V_359 * V_372 ;
int V_373 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 0 ) )
return - V_29 ;
F_214 ( & V_10 -> V_49 ) ;
V_373 = V_10 -> V_373 ;
switch ( V_385 ) {
case V_388 :
V_373 |= 1 << V_159 -> V_360 ;
break;
case V_389 :
V_373 &= ~ ( 1 << V_159 -> V_360 ) ;
break;
default:
F_215 () ;
F_216 ( & V_10 -> V_49 ) ;
return - V_119 ;
}
if ( V_159 -> V_360 == V_358 )
V_372 = V_10 -> V_353 ;
else
V_372 = V_10 -> V_357 ;
if ( V_372 ) {
struct V_359 * V_100 ;
F_205 (s, substream) {
if ( V_100 == V_372 ) {
F_217 ( V_100 , V_159 ) ;
if ( V_385 == V_388 )
V_373 |= 1 << V_100 -> V_360 ;
else
V_373 &= ~ ( 1 << V_100 -> V_360 ) ;
goto V_390;
}
}
if ( V_385 == V_388 ) {
if ( ! ( V_373 & ( 1 << V_358 ) ) &&
V_159 -> V_360 == V_356 )
F_42 ( V_10 ) ;
} else {
if ( V_373 &&
V_159 -> V_360 == V_358 )
F_42 ( V_10 ) ;
}
} else {
if ( V_159 -> V_360 == V_356 )
F_42 ( V_10 ) ;
}
V_390:
F_217 ( V_159 , V_159 ) ;
if ( ! V_10 -> V_373 && V_373 )
F_40 ( V_10 ) ;
else if ( V_10 -> V_373 && ! V_373 )
F_41 ( V_10 ) ;
V_10 -> V_373 = V_373 ;
F_216 ( & V_10 -> V_49 ) ;
return 0 ;
}
static int F_218 ( struct V_359 * V_159 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
int V_391 = 0 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
if ( ! V_10 -> V_373 )
F_39 ( V_10 ) ;
F_46 ( & V_10 -> V_49 ) ;
return V_391 ;
}
static int F_219 ( struct V_376 * V_377 ,
struct V_392 * V_393 )
{
struct V_10 * V_10 = V_393 -> V_394 ;
struct V_395 * V_396 = F_220 ( V_377 , V_397 ) ;
if ( V_10 -> V_13 == V_18 ) {
unsigned int V_398 [ 3 ] ;
V_398 [ 0 ] = V_10 -> V_399 ;
V_398 [ 1 ] = V_10 -> V_400 ;
V_398 [ 2 ] = V_10 -> V_401 ;
return F_221 ( V_396 , 3 , V_398 , 0 ) ;
} else {
unsigned int V_398 [ 2 ] ;
V_398 [ 0 ] = V_10 -> V_400 ;
V_398 [ 1 ] = V_10 -> V_401 ;
return F_221 ( V_396 , 2 , V_398 , 0 ) ;
}
}
static int F_222 ( struct V_376 * V_377 ,
struct V_392 * V_393 )
{
unsigned int V_398 [ 3 ] ;
struct V_10 * V_10 = V_393 -> V_394 ;
struct V_395 * V_396 = F_220 ( V_377 , V_397 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_398 [ 0 ] = V_10 -> V_402 ;
V_398 [ 1 ] = V_10 -> V_403 ;
V_398 [ 2 ] = V_10 -> V_404 ;
return F_221 ( V_396 , 3 , V_398 , 0 ) ;
} else {
V_398 [ 0 ] = V_10 -> V_403 ;
V_398 [ 1 ] = V_10 -> V_404 ;
}
return F_221 ( V_396 , 2 , V_398 , 0 ) ;
}
static int F_223 ( struct V_376 * V_377 ,
struct V_392 * V_393 )
{
struct V_10 * V_10 = V_393 -> V_394 ;
struct V_395 * V_396 = F_220 ( V_377 , V_397 ) ;
struct V_395 * V_405 = F_220 ( V_377 , V_380 ) ;
if ( V_405 -> V_263 > 96000 && V_10 -> V_13 == V_18 ) {
struct V_395 V_406 = {
. V_263 = V_10 -> V_399 ,
. V_247 = V_10 -> V_399 ,
. integer = 1 ,
} ;
return F_224 ( V_396 , & V_406 ) ;
} else if ( V_405 -> V_263 > 48000 && V_405 -> V_247 <= 96000 ) {
struct V_395 V_406 = {
. V_263 = V_10 -> V_400 ,
. V_247 = V_10 -> V_400 ,
. integer = 1 ,
} ;
return F_224 ( V_396 , & V_406 ) ;
} else if ( V_405 -> V_247 < 64000 ) {
struct V_395 V_406 = {
. V_263 = V_10 -> V_401 ,
. V_247 = V_10 -> V_401 ,
. integer = 1 ,
} ;
return F_224 ( V_396 , & V_406 ) ;
}
return 0 ;
}
static int F_225 ( struct V_376 * V_377 ,
struct V_392 * V_393 )
{
struct V_10 * V_10 = V_393 -> V_394 ;
struct V_395 * V_396 = F_220 ( V_377 , V_397 ) ;
struct V_395 * V_405 = F_220 ( V_377 , V_380 ) ;
if ( V_405 -> V_263 > 96000 && V_10 -> V_13 == V_18 ) {
struct V_395 V_406 = {
. V_263 = V_10 -> V_402 ,
. V_247 = V_10 -> V_402 ,
. integer = 1 ,
} ;
return F_224 ( V_396 , & V_406 ) ;
} else if ( V_405 -> V_263 > 48000 && V_405 -> V_247 <= 96000 ) {
struct V_395 V_406 = {
. V_263 = V_10 -> V_403 ,
. V_247 = V_10 -> V_403 ,
. integer = 1 ,
} ;
return F_224 ( V_396 , & V_406 ) ;
} else if ( V_405 -> V_247 < 64000 ) {
struct V_395 V_406 = {
. V_263 = V_10 -> V_404 ,
. V_247 = V_10 -> V_404 ,
. integer = 1 ,
} ;
return F_224 ( V_396 , & V_406 ) ;
}
return 0 ;
}
static int F_226 ( struct V_376 * V_377 ,
struct V_392 * V_393 )
{
struct V_10 * V_10 = V_393 -> V_394 ;
struct V_395 * V_396 = F_220 ( V_377 , V_397 ) ;
struct V_395 * V_405 = F_220 ( V_377 , V_380 ) ;
if ( V_396 -> V_263 >= V_10 -> V_404 ) {
struct V_395 V_406 = {
. V_263 = 32000 ,
. V_247 = 48000 ,
. integer = 1 ,
} ;
return F_224 ( V_405 , & V_406 ) ;
} else if ( V_396 -> V_247 <= V_10 -> V_402 && V_10 -> V_13 == V_18 ) {
struct V_395 V_406 = {
. V_263 = 128000 ,
. V_247 = 192000 ,
. integer = 1 ,
} ;
return F_224 ( V_405 , & V_406 ) ;
} else if ( V_396 -> V_247 <= V_10 -> V_403 ) {
struct V_395 V_406 = {
. V_263 = 64000 ,
. V_247 = 96000 ,
. integer = 1 ,
} ;
return F_224 ( V_405 , & V_406 ) ;
}
return 0 ;
}
static int F_227 ( struct V_376 * V_377 ,
struct V_392 * V_393 )
{
struct V_10 * V_10 = V_393 -> V_394 ;
struct V_395 * V_396 = F_220 ( V_377 , V_397 ) ;
struct V_395 * V_405 = F_220 ( V_377 , V_380 ) ;
if ( V_396 -> V_263 >= V_10 -> V_401 ) {
struct V_395 V_406 = {
. V_263 = 32000 ,
. V_247 = 48000 ,
. integer = 1 ,
} ;
return F_224 ( V_405 , & V_406 ) ;
} else if ( V_396 -> V_247 <= V_10 -> V_399 && V_10 -> V_13 == V_18 ) {
struct V_395 V_406 = {
. V_263 = 128000 ,
. V_247 = 192000 ,
. integer = 1 ,
} ;
return F_224 ( V_405 , & V_406 ) ;
} else if ( V_396 -> V_247 <= V_10 -> V_400 ) {
struct V_395 V_406 = {
. V_263 = 64000 ,
. V_247 = 96000 ,
. integer = 1 ,
} ;
return F_224 ( V_405 , & V_406 ) ;
}
return 0 ;
}
static int F_228 ( struct V_359 * V_159 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
struct V_370 * V_371 = V_159 -> V_371 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
F_229 ( V_159 ) ;
V_371 -> V_407 = V_408 ;
V_371 -> V_409 = V_10 -> V_104 ;
V_371 -> V_410 = V_105 ;
V_10 -> V_66 = V_411 -> V_412 ;
V_10 -> V_357 = V_159 ;
F_46 ( & V_10 -> V_49 ) ;
F_230 ( V_371 , 0 , 32 , 24 ) ;
F_231 ( V_371 , 0 , V_381 , & V_413 ) ;
if ( V_10 -> V_219 ) {
V_371 -> V_407 . V_414 = V_371 -> V_407 . V_415 = V_10 -> V_118 ;
} else if ( V_10 -> V_13 == V_18 ) {
V_371 -> V_407 . V_415 = 192000 ;
V_371 -> V_407 . V_416 = V_417 ;
F_231 ( V_371 , 0 , V_380 , & V_418 ) ;
}
if ( V_10 -> V_13 == V_18 ) {
V_371 -> V_407 . V_419 = V_10 -> V_402 ;
V_371 -> V_407 . V_420 = V_10 -> V_404 ;
}
F_232 ( V_371 , 0 , V_397 ,
F_222 , V_10 ,
V_397 , - 1 ) ;
F_232 ( V_371 , 0 , V_397 ,
F_225 , V_10 ,
V_380 , - 1 ) ;
F_232 ( V_371 , 0 , V_380 ,
F_226 , V_10 ,
V_397 , - 1 ) ;
if ( V_16 != V_10 -> V_13 ) {
V_10 -> V_200 = V_10 -> V_198 ;
V_10 -> V_297 -> V_421 [ 0 ] . V_422 &= ~ V_423 ;
F_233 ( V_10 -> V_26 , V_424 |
V_425 , & V_10 -> V_297 -> V_138 ) ;
}
return 0 ;
}
static int F_234 ( struct V_359 * V_159 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_10 -> V_66 = - 1 ;
V_10 -> V_357 = NULL ;
F_46 ( & V_10 -> V_49 ) ;
if ( V_16 != V_10 -> V_13 ) {
V_10 -> V_297 -> V_421 [ 0 ] . V_422 |= V_423 ;
F_233 ( V_10 -> V_26 , V_424 |
V_425 , & V_10 -> V_297 -> V_138 ) ;
}
return 0 ;
}
static int F_235 ( struct V_359 * V_159 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
struct V_370 * V_371 = V_159 -> V_371 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( F_26 ( V_10 , 1 ) )
return - V_29 ;
F_44 ( & V_10 -> V_49 ) ;
F_229 ( V_159 ) ;
V_371 -> V_407 = V_426 ;
V_371 -> V_409 = V_10 -> V_312 ;
V_371 -> V_410 = V_105 ;
V_10 -> V_67 = V_411 -> V_412 ;
V_10 -> V_353 = V_159 ;
F_46 ( & V_10 -> V_49 ) ;
F_230 ( V_371 , 0 , 32 , 24 ) ;
F_231 ( V_371 , 0 , V_381 , & V_413 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_371 -> V_407 . V_419 = V_10 -> V_399 ;
V_371 -> V_407 . V_420 = V_10 -> V_401 ;
V_371 -> V_407 . V_415 = 192000 ;
V_371 -> V_407 . V_416 = V_417 ;
F_231 ( V_371 , 0 , V_380 , & V_418 ) ;
}
F_232 ( V_371 , 0 , V_397 ,
F_219 , V_10 ,
V_397 , - 1 ) ;
F_232 ( V_371 , 0 , V_397 ,
F_223 , V_10 ,
V_380 , - 1 ) ;
F_232 ( V_371 , 0 , V_380 ,
F_227 , V_10 ,
V_397 , - 1 ) ;
return 0 ;
}
static int F_236 ( struct V_359 * V_159 )
{
struct V_10 * V_10 = F_197 ( V_159 ) ;
F_44 ( & V_10 -> V_49 ) ;
V_10 -> V_67 = - 1 ;
V_10 -> V_353 = NULL ;
F_46 ( & V_10 -> V_49 ) ;
return 0 ;
}
static inline int F_237 ( void T_6 * V_427 , void T_8 * V_365 )
{
T_2 V_21 = F_11 ( V_365 ) ;
return F_202 ( V_427 , & V_21 , 4 ) ;
}
static inline int F_238 ( void T_6 * V_427 , void T_8 * V_428 , void T_8 * V_429 )
{
T_2 V_430 , V_431 ;
T_4 V_432 ;
V_430 = F_11 ( V_428 ) ;
V_431 = F_11 ( V_429 ) ;
V_432 = ( ( T_4 ) V_431 << 32 ) | V_430 ;
return F_202 ( V_427 , & V_432 , 8 ) ;
}
static inline int F_239 ( void T_6 * V_427 , void T_8 * V_428 , void T_8 * V_429 )
{
T_2 V_430 , V_431 ;
T_4 V_432 ;
V_430 = F_11 ( V_428 ) & 0xffffff00 ;
V_431 = F_11 ( V_429 ) & 0xffffff00 ;
V_432 = ( ( T_4 ) V_431 << 32 ) | V_430 ;
return F_202 ( V_427 , & V_432 , 8 ) ;
}
static int F_240 ( struct V_10 * V_10 , struct V_433 T_6 * V_434 )
{
int V_435 = 0 ;
int V_23 , V_436 , V_437 , V_438 ;
if ( F_10 ( V_10 , V_24 ) & V_439 )
V_435 = 1 ;
V_437 = V_435 ? 14 : 26 ;
for ( V_23 = 0 , V_436 = 0 ; V_23 < 26 ; ++ V_23 ) {
if ( V_435 && ( V_23 & 4 ) )
continue;
V_438 = V_440 - V_436 * 4 ;
if ( F_237 ( & V_434 -> V_441 [ V_23 ] , V_10 -> V_22 + V_438 ) )
return - V_368 ;
V_438 -= V_437 * 4 ;
if ( F_237 ( & V_434 -> V_442 [ V_23 ] , V_10 -> V_22 + V_438 ) )
return - V_368 ;
V_438 -= V_437 * 4 ;
if ( F_237 ( & V_434 -> V_443 [ V_23 ] , V_10 -> V_22 + V_438 ) )
return - V_368 ;
V_438 = V_444 + V_436 * 8 ;
if ( F_239 ( & V_434 -> V_445 [ V_23 ] , V_10 -> V_22 + V_438 ,
V_10 -> V_22 + V_438 + 4 ) )
return - V_368 ;
V_438 += V_437 * 8 ;
if ( F_239 ( & V_434 -> V_446 [ V_23 ] , V_10 -> V_22 + V_438 ,
V_10 -> V_22 + V_438 + 4 ) )
return - V_368 ;
V_438 += V_437 * 8 ;
if ( F_239 ( & V_434 -> V_447 [ V_23 ] , V_10 -> V_22 + V_438 ,
V_10 -> V_22 + V_438 + 4 ) )
return - V_368 ;
V_436 ++ ;
}
return 0 ;
}
static int F_241 ( struct V_10 * V_10 , struct V_433 T_6 * V_434 )
{
int V_23 , V_436 ;
struct V_448 T_8 * V_449 ;
int V_435 = 0 ;
if ( F_10 ( V_10 , V_24 ) & V_439 )
V_435 = 1 ;
V_449 = (struct V_448 T_8 * ) ( V_10 -> V_22 + V_450 ) ;
for ( V_23 = 0 , V_436 = 0 ; V_23 < 16 ; ++ V_23 , ++ V_436 ) {
if ( F_237 ( & V_434 -> V_441 [ V_23 ] , & V_449 -> V_451 [ V_436 ] ) )
return - V_368 ;
if ( F_237 ( & V_434 -> V_442 [ V_23 ] , & V_449 -> V_452 [ V_436 ] ) )
return - V_368 ;
if ( F_237 ( & V_434 -> V_443 [ V_23 ] , & V_449 -> V_453 [ V_436 ] ) )
return - V_368 ;
if ( F_238 ( & V_434 -> V_445 [ V_23 ] , & V_449 -> V_454 [ V_436 ] ,
& V_449 -> V_455 [ V_436 ] ) )
return - V_368 ;
if ( F_238 ( & V_434 -> V_446 [ V_23 ] , & V_449 -> V_456 [ V_436 ] ,
& V_449 -> V_457 [ V_436 ] ) )
return - V_368 ;
if ( F_238 ( & V_434 -> V_447 [ V_23 ] , & V_449 -> V_458 [ V_436 ] ,
& V_449 -> V_459 [ V_436 ] ) )
return - V_368 ;
if ( V_435 && V_23 == 3 ) V_23 += 4 ;
}
return 0 ;
}
static int F_242 ( struct V_10 * V_10 , struct V_433 T_6 * V_434 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < 26 ; V_23 ++ ) {
if ( F_237 ( & V_434 -> V_442 [ V_23 ] ,
V_10 -> V_22 + V_460 + V_23 * 4 ) )
return - V_368 ;
if ( F_237 ( & V_434 -> V_441 [ V_23 ] ,
V_10 -> V_22 + V_461 + V_23 * 4 ) )
return - V_368 ;
}
for ( V_23 = 0 ; V_23 < 28 ; V_23 ++ ) {
if ( F_237 ( & V_434 -> V_443 [ V_23 ] ,
V_10 -> V_22 + V_462 + V_23 * 4 ) )
return - V_368 ;
}
for ( V_23 = 0 ; V_23 < 26 ; ++ V_23 ) {
if ( F_238 ( & V_434 -> V_446 [ V_23 ] ,
V_10 -> V_22 + V_463 + V_23 * 8 + 4 ,
V_10 -> V_22 + V_463 + V_23 * 8 ) )
return - V_368 ;
if ( F_238 ( & V_434 -> V_445 [ V_23 ] ,
V_10 -> V_22 + V_464 + V_23 * 8 + 4 ,
V_10 -> V_22 + V_464 + V_23 * 8 ) )
return - V_368 ;
}
return 0 ;
}
static int F_243 ( struct V_465 * V_407 , struct V_466 * V_466 , unsigned int V_385 , unsigned long V_339 )
{
struct V_10 * V_10 = V_407 -> V_163 ;
void T_6 * V_467 = ( void T_6 * ) V_339 ;
int V_293 ;
switch ( V_385 ) {
case V_468 : {
struct V_433 T_6 * V_434 = (struct V_433 T_6 * ) V_339 ;
V_293 = F_12 ( V_10 ) ;
if ( V_293 < 0 )
return V_293 ;
V_293 = F_26 ( V_10 , 1 ) ;
if ( V_293 < 0 )
return V_293 ;
if ( ! ( V_10 -> V_27 & V_28 ) ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_174 ) ;
return - V_119 ;
}
switch ( V_10 -> V_13 ) {
case V_19 :
return F_240 ( V_10 , V_434 ) ;
case V_18 :
return F_241 ( V_10 , V_434 ) ;
default:
return F_242 ( V_10 , V_434 ) ;
}
}
case V_469 : {
struct V_470 V_383 ;
unsigned long V_32 ;
int V_23 ;
V_293 = F_12 ( V_10 ) ;
if ( V_293 < 0 )
return V_293 ;
V_293 = F_26 ( V_10 , 1 ) ;
if ( V_293 < 0 )
return V_293 ;
memset ( & V_383 , 0 , sizeof( V_383 ) ) ;
F_22 ( & V_10 -> V_49 , V_32 ) ;
V_383 . V_305 = ( unsigned char ) F_130 ( V_10 ) ;
V_383 . V_471 = ( unsigned char ) F_147 ( V_10 ) ;
if ( V_10 -> V_13 != V_18 )
V_383 . V_472 = ( unsigned char ) F_151 ( V_10 ) ;
V_383 . V_473 = ( unsigned char ) F_149 ( V_10 ) ;
for ( V_23 = 0 ; V_23 < ( ( V_10 -> V_13 != V_14 && V_10 -> V_13 != V_16 && V_10 -> V_13 != V_18 ) ? 3 : 1 ) ; ++ V_23 )
V_383 . V_474 [ V_23 ] = ( unsigned char ) F_153 ( V_10 , V_23 ) ;
V_383 . V_475 = ( unsigned char ) F_87 ( V_10 ) ;
V_383 . V_476 = ( unsigned char ) F_95 ( V_10 ,
V_323 ) ;
V_383 . V_477 = ( unsigned char )
F_95 ( V_10 , V_183 ) ;
V_383 . V_478 = ( unsigned char )
F_95 ( V_10 , V_187 ) ;
V_383 . V_479 = ( unsigned char )
F_95 ( V_10 , V_185 ) ;
V_383 . V_480 = F_33 ( V_10 ) ;
V_383 . V_118 = V_10 -> V_118 ;
V_383 . V_481 = F_34 ( V_10 ) ;
V_383 . V_307 = ( unsigned char ) F_105 ( V_10 ) ;
V_383 . V_308 = ( unsigned char ) F_108 ( V_10 ) ;
V_383 . V_306 = ( unsigned char ) F_35 ( V_10 ) ;
V_383 . V_482 = ( unsigned char )
F_95 ( V_10 , V_315 ) ;
if ( V_10 -> V_13 == V_18 ) {
V_383 . V_483 = ( unsigned char ) F_115 ( V_10 ) ;
V_383 . V_484 = ( unsigned char ) F_120 ( V_10 ) ;
V_383 . V_485 = ( unsigned char ) F_125 ( V_10 ) ;
V_383 . V_486 =
( unsigned char ) F_95 ( V_10 ,
V_329 ) ;
} else if ( V_10 -> V_13 == V_16 ) {
V_383 . V_483 = ( unsigned char ) F_160 ( V_10 ) ;
V_383 . V_484 = ( unsigned char ) F_165 ( V_10 ) ;
}
if ( V_10 -> V_13 == V_18 || V_10 -> V_13 == V_19 )
V_383 . V_487 =
( unsigned char ) F_95 ( V_10 ,
V_330 ) ;
F_24 ( & V_10 -> V_49 , V_32 ) ;
if ( F_202 ( V_467 , & V_383 , sizeof( V_383 ) ) )
return - V_368 ;
break;
}
case V_488 : {
struct V_489 V_490 ;
if ( V_10 -> V_13 != V_18 ) return - V_119 ;
V_490 . V_491 = V_10 -> V_401 - V_492 ;
V_490 . V_493 = V_10 -> V_404 - V_492 ;
if ( F_202 ( V_467 , & V_490 , sizeof( V_490 ) ) )
return - V_368 ;
break;
}
case V_494 : {
struct V_495 V_495 ;
int V_293 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) return - V_119 ;
if ( V_10 -> V_13 == V_496 ) {
if ( ( V_293 = F_25 ( V_10 ) ) < 0 )
return V_293 ;
}
memset ( & V_495 , 0 , sizeof( V_495 ) ) ;
V_495 . V_13 = V_10 -> V_13 ;
V_495 . V_17 = V_10 -> V_17 ;
if ( ( V_293 = F_202 ( V_467 , & V_495 , sizeof( V_495 ) ) ) )
return - V_368 ;
break;
}
case V_497 : {
struct V_498 T_6 * V_35 ;
T_2 T_6 * V_499 ;
int V_293 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 ) return - V_119 ;
if ( V_10 -> V_13 == V_496 ) return - V_119 ;
if ( V_10 -> V_27 & ( V_57 | V_28 ) )
return - V_129 ;
F_17 ( V_10 -> V_26 -> V_6 ,
L_175 ) ;
V_35 = (struct V_498 T_6 * ) V_467 ;
if ( F_244 ( V_499 , & V_35 -> V_499 ) )
return - V_368 ;
if ( F_12 ( V_10 ) )
return - V_29 ;
if ( ! V_10 -> V_34 ) {
V_10 -> V_34 = F_245 ( V_45 ) ;
if ( ! V_10 -> V_34 )
return - V_8 ;
}
if ( F_200 ( V_10 -> V_34 , V_499 ,
V_45 ) ) {
F_246 ( V_10 -> V_34 ) ;
V_10 -> V_34 = NULL ;
return - V_368 ;
}
V_10 -> V_27 |= V_57 ;
if ( ( V_293 = F_18 ( V_10 ) ) < 0 )
return V_293 ;
if ( ! ( V_10 -> V_27 & V_48 ) ) {
if ( ( V_293 = F_247 ( V_10 ) ) < 0 )
return V_293 ;
F_248 ( V_10 ) ;
F_249 ( V_10 ) ;
if ( ( V_293 = F_250 ( V_10 -> V_26 , V_10 ) ) < 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_176 ) ;
return V_293 ;
}
}
break;
}
case V_500 : {
struct V_501 T_6 * V_502 = (struct V_501 T_6 * ) V_467 ;
if ( F_202 ( V_502 -> V_503 , V_10 -> V_63 , sizeof( unsigned short ) * V_62 ) )
return - V_368 ;
break;
}
default:
return - V_119 ;
}
return 0 ;
}
static int F_251 ( struct V_168 * V_26 , struct V_10 * V_10 )
{
struct V_465 * V_407 ;
int V_293 ;
if ( ( V_293 = F_252 ( V_26 , L_177 , 0 , & V_407 ) ) < 0 )
return V_293 ;
V_10 -> V_504 = V_407 ;
V_407 -> V_163 = V_10 ;
strcpy ( V_407 -> V_171 , L_178 ) ;
V_407 -> V_505 . V_506 = F_243 ;
V_407 -> V_505 . V_507 = F_243 ;
return 0 ;
}
static int F_253 ( struct V_168 * V_26 , struct V_10 * V_10 )
{
struct V_508 * V_354 ;
int V_293 ;
if ( ( V_293 = F_254 ( V_26 , V_10 -> V_310 , 0 , 1 , 1 , & V_354 ) ) < 0 )
return V_293 ;
V_10 -> V_354 = V_354 ;
V_354 -> V_163 = V_10 ;
strcpy ( V_354 -> V_171 , V_10 -> V_310 ) ;
F_255 ( V_354 , V_358 , & V_509 ) ;
F_255 ( V_354 , V_356 , & V_510 ) ;
V_354 -> V_176 = V_511 ;
return 0 ;
}
static void F_191 ( struct V_10 * V_10 )
{
V_10 -> V_46 |= V_512 ;
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
for ( V_23 = 0 ; V_23 < V_10 -> V_267 ; ++ V_23 ) {
F_8 ( V_10 , V_513 + ( 4 * V_23 ) , 1 ) ;
F_8 ( V_10 , V_514 + ( 4 * V_23 ) , 1 ) ;
}
return 0 ;
}
static void F_248 ( struct V_10 * V_10 )
{
int V_68 , V_515 , V_516 ;
switch ( V_10 -> V_13 ) {
case V_15 :
V_10 -> V_310 = L_180 ;
V_10 -> V_401 = V_10 -> V_404 = V_517 ;
V_10 -> V_400 = V_10 -> V_403 = V_518 ;
break;
case V_19 :
V_10 -> V_310 = L_181 ;
V_10 -> V_401 = V_10 -> V_404 = V_519 ;
V_10 -> V_400 = V_10 -> V_403 = V_520 ;
break;
case V_18 :
V_68 = F_10 ( V_10 , V_24 ) ;
V_515 = ( V_68 & V_521 ) ? 0 : 4 ;
V_516 = ( V_68 & V_522 ) ? 0 : 4 ;
V_10 -> V_310 = L_182 ;
V_10 -> V_401 = V_492 + V_515 ;
V_10 -> V_400 = V_523 + V_515 ;
V_10 -> V_399 = V_524 + V_515 ;
V_10 -> V_404 = V_492 + V_516 ;
V_10 -> V_403 = V_523 + V_516 ;
V_10 -> V_402 = V_524 + V_516 ;
break;
case V_14 :
V_10 -> V_310 = L_183 ;
V_10 -> V_401 = V_10 -> V_404 = V_525 ;
V_10 -> V_400 = V_10 -> V_403 = V_526 ;
break;
case V_16 :
V_10 -> V_310 = L_184 ;
V_10 -> V_401 = V_527 - 1 ;
V_10 -> V_404 = V_527 ;
V_10 -> V_400 = V_527 - 1 ;
V_10 -> V_403 = V_527 ;
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
static int F_250 ( struct V_168 * V_26 , struct V_10 * V_10 )
{
int V_293 ;
if ( ( V_293 = F_253 ( V_26 , V_10 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_185 ) ;
return V_293 ;
}
if ( ( V_293 = F_72 ( V_26 , V_10 , 0 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_186 ) ;
return V_293 ;
}
if ( V_10 -> V_13 == V_15 || V_10 -> V_13 == V_19 ) {
if ( ( V_293 = F_72 ( V_26 , V_10 , 1 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_187 ) ;
return V_293 ;
}
}
if ( ( V_293 = F_179 ( V_26 , V_10 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_188 ) ;
return V_293 ;
}
F_185 ( V_10 ) ;
V_10 -> V_118 = - 1 ;
V_10 -> V_66 = - 1 ;
V_10 -> V_67 = - 1 ;
V_10 -> V_353 = NULL ;
V_10 -> V_357 = NULL ;
if ( ( V_293 = F_23 ( V_10 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_189 ) ;
return V_293 ;
}
if ( ! ( V_10 -> V_27 & V_48 ) ) {
strcpy ( V_26 -> V_170 , L_190 ) ;
sprintf ( V_26 -> V_528 , L_191 , V_10 -> V_310 ,
V_10 -> V_314 , V_10 -> V_313 ) ;
if ( ( V_293 = F_256 ( V_26 ) ) < 0 ) {
F_15 ( V_26 -> V_6 ,
L_192 ) ;
return V_293 ;
}
V_10 -> V_27 |= V_48 ;
}
return 0 ;
}
static int F_27 ( struct V_10 * V_10 )
{
const char * V_529 ;
const struct V_35 * V_530 ;
int V_293 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
if ( V_10 -> V_13 == V_496 ) {
if ( ( V_293 = F_25 ( V_10 ) ) < 0 )
return V_293 ;
if ( V_10 -> V_13 == V_19 || V_10 -> V_13 == V_18 )
return 0 ;
}
switch ( V_10 -> V_13 ) {
case V_16 :
V_529 = L_193 ;
break;
case V_14 :
if ( V_10 -> V_17 == 0xa )
V_529 = L_194 ;
else
V_529 = L_195 ;
break;
case V_15 :
if ( V_10 -> V_17 == 0xa )
V_529 = L_196 ;
else
V_529 = L_197 ;
break;
default:
F_15 ( V_10 -> V_26 -> V_6 ,
L_198 , V_10 -> V_13 ) ;
return - V_119 ;
}
if ( F_257 ( & V_530 , V_529 , & V_10 -> V_2 -> V_6 ) ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_199 , V_529 ) ;
return - V_531 ;
}
if ( V_530 -> V_5 < V_45 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_200 ,
( int ) V_530 -> V_5 , V_45 ) ;
return - V_119 ;
}
V_10 -> V_35 = V_530 ;
V_10 -> V_27 |= V_57 ;
if ( ( V_293 = F_18 ( V_10 ) ) < 0 )
return V_293 ;
if ( ! ( V_10 -> V_27 & V_48 ) ) {
if ( ( V_293 = F_247 ( V_10 ) ) < 0 )
return V_293 ;
if ( ( V_293 = F_251 ( V_10 -> V_26 , V_10 ) ) < 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_201 ) ;
return V_293 ;
}
F_248 ( V_10 ) ;
F_249 ( V_10 ) ;
if ( ( V_293 = F_250 ( V_10 -> V_26 , V_10 ) ) < 0 ) {
F_15 ( V_10 -> V_26 -> V_6 ,
L_176 ) ;
return V_293 ;
}
}
return 0 ;
}
static int F_258 ( struct V_168 * V_26 ,
struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_293 ;
int V_532 = 0 ;
int V_533 = 0 ;
V_10 -> V_313 = - 1 ;
V_10 -> V_27 = 0 ;
V_10 -> V_169 [ 0 ] . V_162 = NULL ;
V_10 -> V_169 [ 1 ] . V_162 = NULL ;
V_10 -> V_169 [ 0 ] . V_154 = NULL ;
V_10 -> V_169 [ 1 ] . V_154 = NULL ;
V_10 -> V_169 [ 0 ] . V_153 = NULL ;
V_10 -> V_169 [ 1 ] . V_153 = NULL ;
V_10 -> V_169 [ 0 ] . V_155 = 0 ;
V_10 -> V_169 [ 1 ] . V_155 = 0 ;
F_73 ( & V_10 -> V_169 [ 0 ] . V_49 ) ;
F_73 ( & V_10 -> V_169 [ 1 ] . V_49 ) ;
V_10 -> V_22 = NULL ;
V_10 -> V_92 = 0 ;
V_10 -> V_46 = 0 ;
V_10 -> V_13 = V_496 ;
V_10 -> V_267 = 26 ;
V_10 -> V_26 = V_26 ;
F_73 ( & V_10 -> V_49 ) ;
F_259 ( & V_10 -> V_164 , F_192 , ( unsigned long ) V_10 ) ;
F_260 ( V_10 -> V_2 , V_534 , & V_10 -> V_17 ) ;
V_10 -> V_17 &= 0xff ;
F_261 ( V_10 -> V_2 , V_535 , 0xFF ) ;
strcpy ( V_26 -> V_536 , L_202 ) ;
strcpy ( V_26 -> V_537 , L_203 ) ;
if ( V_10 -> V_17 < 0xa )
return - V_36 ;
else if ( V_10 -> V_17 < 0x64 )
V_10 -> V_310 = L_204 ;
else if ( V_10 -> V_17 < 0x96 ) {
V_10 -> V_310 = L_205 ;
V_532 = 1 ;
} else {
V_10 -> V_310 = L_206 ;
V_10 -> V_267 = 16 ;
V_533 = 1 ;
}
if ( ( V_293 = F_262 ( V_2 ) ) < 0 )
return V_293 ;
F_263 ( V_10 -> V_2 ) ;
if ( ( V_293 = F_264 ( V_2 , L_172 ) ) < 0 )
return V_293 ;
V_10 -> V_314 = F_265 ( V_2 , 0 ) ;
if ( ( V_10 -> V_22 = F_266 ( V_10 -> V_314 , V_538 ) ) == NULL ) {
F_15 ( V_10 -> V_26 -> V_6 , L_207 ,
V_10 -> V_314 , V_10 -> V_314 + V_538 - 1 ) ;
return - V_129 ;
}
if ( F_267 ( V_2 -> V_313 , F_193 , V_539 ,
V_540 , V_10 ) ) {
F_15 ( V_10 -> V_26 -> V_6 , L_208 , V_2 -> V_313 ) ;
return - V_129 ;
}
V_10 -> V_313 = V_2 -> V_313 ;
V_10 -> V_94 = 0 ;
V_10 -> V_262 = 1 ;
V_10 -> V_99 = 0 ;
if ( ( V_293 = F_189 ( V_10 ) ) < 0 )
return V_293 ;
if ( ! V_532 && ! V_533 ) {
V_293 = F_16 ( V_10 , 1000 , 10 ) ;
if ( V_293 < 0 )
return V_293 ;
if ( ( F_10 ( V_10 , V_24 ) & V_38 ) != 0 ) {
if ( ( V_293 = F_27 ( V_10 ) ) < 0 )
F_15 ( V_10 -> V_26 -> V_6 ,
L_209 ) ;
else
return 0 ;
F_17 ( V_10 -> V_26 -> V_6 ,
L_210 ) ;
if ( ( V_293 = F_251 ( V_26 , V_10 ) ) < 0 )
return V_293 ;
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
if ( ( V_293 = F_247 ( V_10 ) ) != 0 )
return V_293 ;
if ( V_532 )
V_10 -> V_13 = V_19 ;
if ( V_533 )
V_10 -> V_13 = V_18 ;
if ( ( V_293 = F_251 ( V_26 , V_10 ) ) < 0 )
return V_293 ;
F_248 ( V_10 ) ;
F_249 ( V_10 ) ;
V_10 -> V_27 |= V_28 ;
if ( ( V_293 = F_250 ( V_26 , V_10 ) ) < 0 )
return V_293 ;
return 0 ;
}
static int F_268 ( struct V_10 * V_10 )
{
if ( V_10 -> V_314 ) {
F_62 ( & V_10 -> V_164 ) ;
V_10 -> V_92 &= ~ ( V_102 | V_101 | V_157 | V_156 ) ;
F_8 ( V_10 , V_103 , V_10 -> V_92 ) ;
}
if ( V_10 -> V_313 >= 0 )
F_269 ( V_10 -> V_313 , ( void * ) V_10 ) ;
F_188 ( V_10 ) ;
F_270 ( V_10 -> V_35 ) ;
F_246 ( V_10 -> V_34 ) ;
F_271 ( V_10 -> V_22 ) ;
if ( V_10 -> V_314 )
F_272 ( V_10 -> V_2 ) ;
F_273 ( V_10 -> V_2 ) ;
return 0 ;
}
static void F_274 ( struct V_168 * V_26 )
{
struct V_10 * V_10 = V_26 -> V_163 ;
if ( V_10 )
F_268 ( V_10 ) ;
}
static int F_275 ( struct V_1 * V_2 ,
const struct V_541 * V_542 )
{
static int V_6 ;
struct V_10 * V_10 ;
struct V_168 * V_26 ;
int V_293 ;
if ( V_6 >= V_543 )
return - V_36 ;
if ( ! V_544 [ V_6 ] ) {
V_6 ++ ;
return - V_531 ;
}
V_293 = F_276 ( & V_2 -> V_6 , V_278 [ V_6 ] , V_138 [ V_6 ] , V_545 ,
sizeof( struct V_10 ) , & V_26 ) ;
if ( V_293 < 0 )
return V_293 ;
V_10 = V_26 -> V_163 ;
V_26 -> V_546 = F_274 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_2 = V_2 ;
if ( ( V_293 = F_258 ( V_26 , V_10 ) ) < 0 ) {
F_277 ( V_26 ) ;
return V_293 ;
}
strcpy ( V_26 -> V_170 , L_190 ) ;
sprintf ( V_26 -> V_528 , L_191 , V_10 -> V_310 ,
V_10 -> V_314 , V_10 -> V_313 ) ;
if ( ( V_293 = F_256 ( V_26 ) ) < 0 ) {
F_277 ( V_26 ) ;
return V_293 ;
}
F_278 ( V_2 , V_26 ) ;
V_6 ++ ;
return 0 ;
}
static void F_279 ( struct V_1 * V_2 )
{
F_277 ( F_280 ( V_2 ) ) ;
}
