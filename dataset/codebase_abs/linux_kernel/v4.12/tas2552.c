static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
switch ( V_5 ) {
case V_9 :
F_3 ( V_7 , V_10 , 0xc0 ) ;
F_4 ( V_7 , V_11 , ( 1 << 5 ) ,
( 1 << 5 ) ) ;
F_4 ( V_7 , V_12 , 1 , 0 ) ;
F_4 ( V_7 , V_13 , V_14 , 0 ) ;
break;
case V_15 :
F_4 ( V_7 , V_13 , V_14 ,
V_14 ) ;
F_4 ( V_7 , V_12 , 1 , 1 ) ;
F_4 ( V_7 , V_11 , ( 1 << 5 ) , 0 ) ;
F_3 ( V_7 , V_10 , 0xbe ) ;
break;
}
return 0 ;
}
static void F_5 ( struct V_16 * V_17 , int V_18 )
{
T_1 V_19 = 0 ;
if ( ! V_17 -> V_7 )
return;
if ( V_18 )
V_19 = V_14 ;
F_4 ( V_17 -> V_7 , V_13 , V_14 ,
V_19 ) ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_20 * V_21 )
{
struct V_16 * V_17 = F_7 ( V_7 -> V_22 ) ;
bool V_23 = false ;
unsigned int V_24 = F_8 ( V_21 ) * 512 ;
unsigned int V_25 = V_17 -> V_25 ;
T_1 V_26 ;
if ( ! V_25 ) {
if ( V_17 -> V_27 != V_28 )
return - V_29 ;
V_25 = F_9 ( V_21 ) ;
V_25 += V_17 -> V_30 ;
}
V_26 = F_10 ( V_7 , V_12 ) & V_31 ;
F_4 ( V_7 , V_12 , V_31 , 0 ) ;
if ( V_25 == V_24 )
V_23 = true ;
if ( V_23 ) {
F_4 ( V_7 , V_32 ,
V_33 , V_33 ) ;
} else {
unsigned int V_34 ;
T_1 V_35 ;
T_1 V_36 = ( V_17 -> V_27 << 3 ) & V_37 ;
T_1 V_38 = F_10 ( V_7 , V_39 ) ;
V_38 = ( V_38 >> 7 ) ;
V_40:
V_35 = ( V_24 * 2 * ( 1 << V_38 ) ) / V_25 ;
V_34 = ( V_24 * 2 * ( 1 << V_38 ) ) % V_25 ;
V_34 /= ( V_25 / 10000 ) ;
if ( V_34 && ( V_25 < 512000 || V_25 > 9200000 ) ) {
if ( V_17 -> V_27 == V_28 ) {
V_25 = 1800000 ;
V_36 = ( V_41 << 3 ) &
V_37 ;
} else {
V_25 = F_9 ( V_21 ) ;
V_25 += V_17 -> V_30 ;
V_36 = ( V_28 << 3 ) &
V_37 ;
}
goto V_40;
}
F_4 ( V_7 , V_13 , V_37 ,
V_36 ) ;
F_4 ( V_7 , V_39 ,
V_42 , V_35 ) ;
F_3 ( V_7 , V_32 ,
F_11 ( V_34 ) ) ;
F_3 ( V_7 , V_43 ,
F_12 ( V_34 ) ) ;
}
F_4 ( V_7 , V_12 , V_31 ,
V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_44 * V_45 ,
struct V_20 * V_21 ,
struct V_46 * V_47 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_16 * V_17 = F_7 ( V_7 -> V_22 ) ;
int V_48 ;
T_1 V_49 , V_50 ;
switch ( F_14 ( V_21 ) ) {
case 16 :
V_49 = V_51 ;
V_48 = 32 + V_17 -> V_30 ;
break;
case 20 :
V_49 = V_52 ;
V_48 = 64 + V_17 -> V_30 ;
break;
case 24 :
V_49 = V_53 ;
V_48 = 64 + V_17 -> V_30 ;
break;
case 32 :
V_49 = V_54 ;
V_48 = 64 + V_17 -> V_30 ;
break;
default:
F_15 ( V_7 -> V_22 , L_1 ,
F_14 ( V_21 ) ) ;
return - V_29 ;
}
if ( V_48 <= 32 )
V_49 |= V_55 ;
else if ( V_48 <= 64 )
V_49 |= V_56 ;
else if ( V_48 <= 128 )
V_49 |= V_57 ;
else
V_49 |= V_58 ;
F_4 ( V_7 , V_59 ,
V_60 | V_61 ,
V_49 ) ;
switch ( F_8 ( V_21 ) ) {
case 8000 :
V_50 = V_62 ;
break;
case 11025 :
case 12000 :
V_50 = V_63 ;
break;
case 16000 :
V_50 = V_64 ;
break;
case 22050 :
case 24000 :
V_50 = V_65 ;
break;
case 32000 :
V_50 = V_66 ;
break;
case 44100 :
case 48000 :
V_50 = V_67 ;
break;
case 88200 :
case 96000 :
V_50 = V_68 ;
break;
case 176400 :
case 192000 :
V_50 = V_69 ;
break;
default:
F_15 ( V_7 -> V_22 , L_2 ,
F_8 ( V_21 ) ) ;
return - V_29 ;
}
F_4 ( V_7 , V_70 , V_71 ,
V_50 ) ;
return F_6 ( V_7 , V_21 ) ;
}
static int F_16 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_16 * V_17 = F_17 ( V_7 ) ;
int V_72 = 0 ;
if ( V_17 -> V_73 == V_74 )
V_72 += ( V_17 -> V_30 + 1 ) ;
else if ( V_17 -> V_73 == V_75 )
V_72 += V_17 -> V_30 ;
F_3 ( V_7 , V_76 , V_72 ) ;
return 0 ;
}
static int F_18 ( struct V_46 * V_47 , unsigned int V_77 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_16 * V_17 = F_7 ( V_7 -> V_22 ) ;
T_1 V_78 ;
switch ( V_77 & V_79 ) {
case V_80 :
V_78 = 0x00 ;
break;
case V_81 :
V_78 = V_82 ;
break;
case V_83 :
V_78 = V_84 ;
break;
case V_85 :
V_78 = ( V_84 | V_82 ) ;
break;
default:
F_19 ( V_7 -> V_22 , L_3 ) ;
return - V_29 ;
}
switch ( V_77 & ( V_86 |
V_87 ) ) {
case ( V_88 | V_89 ) :
break;
case ( V_74 | V_90 ) :
case ( V_75 | V_90 ) :
V_78 |= V_91 ;
break;
case ( V_92 | V_89 ) :
V_78 |= V_93 ;
break;
case ( V_94 | V_89 ) :
V_78 |= V_95 ;
break;
default:
F_19 ( V_7 -> V_22 , L_4 ) ;
return - V_29 ;
}
V_17 -> V_73 = V_77 & V_86 ;
F_4 ( V_7 , V_59 , V_96 ,
V_78 ) ;
return 0 ;
}
static int F_20 ( struct V_46 * V_47 , int V_97 ,
unsigned int V_98 , int V_99 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_16 * V_17 = F_7 ( V_7 -> V_22 ) ;
T_1 V_100 , V_101 , V_102 ;
switch ( V_97 ) {
case V_103 :
case V_104 :
if ( V_98 < 512000 || V_98 > 24576000 ) {
F_21 ( V_7 -> V_22 , L_5 ,
V_98 ) ;
V_97 = V_28 ;
V_98 = 0 ;
}
case V_28 :
case V_41 :
V_101 = V_37 ;
V_102 = ( V_97 << 3 ) & V_101 ;
V_100 = V_13 ;
V_17 -> V_27 = V_97 ;
V_17 -> V_25 = V_98 ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_101 = V_109 ;
V_102 = ( V_97 >> 1 ) & V_101 ;
V_100 = V_110 ;
V_17 -> V_111 = V_97 ;
V_17 -> V_112 = V_98 ;
break;
default:
F_15 ( V_7 -> V_22 , L_6 , V_97 ) ;
return - V_29 ;
}
F_4 ( V_7 , V_100 , V_101 , V_102 ) ;
return 0 ;
}
static int F_22 ( struct V_46 * V_47 ,
unsigned int V_113 , unsigned int V_114 ,
int V_115 , int V_116 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_16 * V_17 = F_17 ( V_7 ) ;
unsigned int V_117 ;
if ( F_23 ( ! V_113 ) ) {
F_15 ( V_7 -> V_22 , L_7 ) ;
return - V_29 ;
}
V_117 = F_24 ( V_113 ) ;
if ( ( V_117 + 1 ) != F_25 ( V_113 ) ) {
F_15 ( V_7 -> V_22 , L_8 ) ;
return - V_29 ;
}
V_17 -> V_30 = V_117 * V_116 ;
F_4 ( V_7 , V_118 ,
V_119 , V_119 ) ;
return 0 ;
}
static int F_26 ( struct V_46 * V_47 , int V_120 )
{
T_1 V_19 = 0 ;
struct V_6 * V_7 = V_47 -> V_7 ;
if ( V_120 )
V_19 |= V_121 ;
F_4 ( V_7 , V_13 , V_121 , V_19 ) ;
return 0 ;
}
static int F_27 ( struct V_122 * V_22 )
{
struct V_16 * V_17 = F_7 ( V_22 ) ;
F_5 ( V_17 , 1 ) ;
F_28 ( V_17 -> V_123 , true ) ;
F_29 ( V_17 -> V_123 ) ;
F_30 ( V_17 -> V_124 , 0 ) ;
return 0 ;
}
static int F_31 ( struct V_122 * V_22 )
{
struct V_16 * V_17 = F_7 ( V_22 ) ;
F_30 ( V_17 -> V_124 , 1 ) ;
F_5 ( V_17 , 0 ) ;
F_28 ( V_17 -> V_123 , false ) ;
F_32 ( V_17 -> V_123 ) ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_16 * V_17 = F_17 ( V_7 ) ;
int V_125 ;
V_17 -> V_7 = V_7 ;
V_125 = F_34 ( F_35 ( V_17 -> V_126 ) ,
V_17 -> V_126 ) ;
if ( V_125 != 0 ) {
F_15 ( V_7 -> V_22 , L_9 ,
V_125 ) ;
return V_125 ;
}
F_30 ( V_17 -> V_124 , 1 ) ;
V_125 = F_36 ( V_7 -> V_22 ) ;
if ( V_125 < 0 ) {
F_15 ( V_7 -> V_22 , L_10 ,
V_125 ) ;
goto V_127;
}
F_4 ( V_7 , V_13 , V_121 , V_121 ) ;
F_3 ( V_7 , V_70 , V_128 |
V_129 ) ;
F_3 ( V_7 , V_130 ,
V_131 |
F_37 ( V_132 ) ) ;
F_3 ( V_7 , V_133 , V_134 |
V_135 ) ;
F_3 ( V_7 , V_12 , V_136 | V_137 |
V_138 ) ;
return 0 ;
V_127:
F_30 ( V_17 -> V_124 , 0 ) ;
F_38 ( F_35 ( V_17 -> V_126 ) ,
V_17 -> V_126 ) ;
return V_125 ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_16 * V_17 = F_17 ( V_7 ) ;
F_40 ( V_7 -> V_22 ) ;
F_30 ( V_17 -> V_124 , 0 ) ;
return 0 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_16 * V_17 = F_17 ( V_7 ) ;
int V_125 ;
V_125 = F_38 ( F_35 ( V_17 -> V_126 ) ,
V_17 -> V_126 ) ;
if ( V_125 != 0 )
F_15 ( V_7 -> V_22 , L_11 ,
V_125 ) ;
return V_125 ;
}
static int F_42 ( struct V_6 * V_7 )
{
struct V_16 * V_17 = F_17 ( V_7 ) ;
int V_125 ;
V_125 = F_34 ( F_35 ( V_17 -> V_126 ) ,
V_17 -> V_126 ) ;
if ( V_125 != 0 ) {
F_15 ( V_7 -> V_22 , L_9 ,
V_125 ) ;
}
return V_125 ;
}
static int F_43 ( struct V_139 * V_140 ,
const struct V_141 * V_142 )
{
struct V_122 * V_22 ;
struct V_16 * V_143 ;
int V_125 ;
int V_144 ;
V_22 = & V_140 -> V_22 ;
V_143 = F_44 ( & V_140 -> V_22 , sizeof( * V_143 ) , V_145 ) ;
if ( V_143 == NULL )
return - V_146 ;
V_143 -> V_124 = F_45 ( V_22 , L_12 ,
V_147 ) ;
if ( F_46 ( V_143 -> V_124 ) )
return F_47 ( V_143 -> V_124 ) ;
V_143 -> V_148 = V_140 ;
V_143 -> V_123 = F_48 ( V_140 , & V_149 ) ;
if ( F_46 ( V_143 -> V_123 ) ) {
V_125 = F_47 ( V_143 -> V_123 ) ;
F_15 ( & V_140 -> V_22 , L_13 ,
V_125 ) ;
return V_125 ;
}
for ( V_144 = 0 ; V_144 < F_35 ( V_143 -> V_126 ) ; V_144 ++ )
V_143 -> V_126 [ V_144 ] . V_150 = V_151 [ V_144 ] ;
V_125 = F_49 ( V_22 , F_35 ( V_143 -> V_126 ) ,
V_143 -> V_126 ) ;
if ( V_125 != 0 ) {
F_15 ( V_22 , L_14 , V_125 ) ;
return V_125 ;
}
F_50 ( & V_140 -> V_22 ) ;
F_51 ( & V_140 -> V_22 , 1000 ) ;
F_52 ( & V_140 -> V_22 ) ;
F_53 ( & V_140 -> V_22 ) ;
F_54 ( & V_140 -> V_22 ) ;
F_55 ( & V_140 -> V_22 ) ;
F_56 ( & V_140 -> V_22 , V_143 ) ;
V_125 = F_57 ( & V_140 -> V_22 ,
& V_152 ,
V_153 , F_35 ( V_153 ) ) ;
if ( V_125 < 0 )
F_15 ( & V_140 -> V_22 , L_15 , V_125 ) ;
return V_125 ;
}
static int F_58 ( struct V_139 * V_140 )
{
F_59 ( & V_140 -> V_22 ) ;
F_60 ( & V_140 -> V_22 ) ;
return 0 ;
}
