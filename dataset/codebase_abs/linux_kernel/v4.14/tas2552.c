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
unsigned int V_34 , V_35 , V_36 ;
T_1 V_37 ;
T_1 V_38 = ( V_17 -> V_27 << 3 ) & V_39 ;
T_1 V_40 = F_10 ( V_7 , V_41 ) ;
V_40 = ( V_40 >> 7 ) ;
V_42:
V_36 = ( V_24 * 2 ) << V_40 ;
V_37 = V_36 / V_25 ;
V_34 = V_36 % V_25 ;
V_36 = V_25 / 10000 ;
V_35 = V_34 / ( V_36 + 1 ) ;
V_34 = V_35 + ( ( 9999 - V_25 % 10000 ) * ( V_34 / V_36 - V_35 ) ) / 10000 ;
if ( V_34 && ( V_25 < 512000 || V_25 > 9200000 ) ) {
if ( V_17 -> V_27 == V_28 ) {
V_25 = 1800000 ;
V_38 = ( V_43 << 3 ) &
V_39 ;
} else {
V_25 = F_9 ( V_21 ) ;
V_25 += V_17 -> V_30 ;
V_38 = ( V_28 << 3 ) &
V_39 ;
}
goto V_42;
}
F_4 ( V_7 , V_13 , V_39 ,
V_38 ) ;
F_4 ( V_7 , V_41 ,
V_44 , V_37 ) ;
F_3 ( V_7 , V_32 ,
F_11 ( V_34 ) ) ;
F_3 ( V_7 , V_45 ,
F_12 ( V_34 ) ) ;
}
F_4 ( V_7 , V_12 , V_31 ,
V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_46 * V_47 ,
struct V_20 * V_21 ,
struct V_48 * V_49 )
{
struct V_6 * V_7 = V_49 -> V_7 ;
struct V_16 * V_17 = F_7 ( V_7 -> V_22 ) ;
int V_50 ;
T_1 V_51 , V_52 ;
switch ( F_14 ( V_21 ) ) {
case 16 :
V_51 = V_53 ;
V_50 = 32 + V_17 -> V_30 ;
break;
case 20 :
V_51 = V_54 ;
V_50 = 64 + V_17 -> V_30 ;
break;
case 24 :
V_51 = V_55 ;
V_50 = 64 + V_17 -> V_30 ;
break;
case 32 :
V_51 = V_56 ;
V_50 = 64 + V_17 -> V_30 ;
break;
default:
F_15 ( V_7 -> V_22 , L_1 ,
F_14 ( V_21 ) ) ;
return - V_29 ;
}
if ( V_50 <= 32 )
V_51 |= V_57 ;
else if ( V_50 <= 64 )
V_51 |= V_58 ;
else if ( V_50 <= 128 )
V_51 |= V_59 ;
else
V_51 |= V_60 ;
F_4 ( V_7 , V_61 ,
V_62 | V_63 ,
V_51 ) ;
switch ( F_8 ( V_21 ) ) {
case 8000 :
V_52 = V_64 ;
break;
case 11025 :
case 12000 :
V_52 = V_65 ;
break;
case 16000 :
V_52 = V_66 ;
break;
case 22050 :
case 24000 :
V_52 = V_67 ;
break;
case 32000 :
V_52 = V_68 ;
break;
case 44100 :
case 48000 :
V_52 = V_69 ;
break;
case 88200 :
case 96000 :
V_52 = V_70 ;
break;
case 176400 :
case 192000 :
V_52 = V_71 ;
break;
default:
F_15 ( V_7 -> V_22 , L_2 ,
F_8 ( V_21 ) ) ;
return - V_29 ;
}
F_4 ( V_7 , V_72 , V_73 ,
V_52 ) ;
return F_6 ( V_7 , V_21 ) ;
}
static int F_16 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_6 * V_7 = V_49 -> V_7 ;
struct V_16 * V_17 = F_17 ( V_7 ) ;
int V_74 = 0 ;
if ( V_17 -> V_75 == V_76 )
V_74 += ( V_17 -> V_30 + 1 ) ;
else if ( V_17 -> V_75 == V_77 )
V_74 += V_17 -> V_30 ;
F_3 ( V_7 , V_78 , V_74 ) ;
return 0 ;
}
static int F_18 ( struct V_48 * V_49 , unsigned int V_79 )
{
struct V_6 * V_7 = V_49 -> V_7 ;
struct V_16 * V_17 = F_7 ( V_7 -> V_22 ) ;
T_1 V_80 ;
switch ( V_79 & V_81 ) {
case V_82 :
V_80 = 0x00 ;
break;
case V_83 :
V_80 = V_84 ;
break;
case V_85 :
V_80 = V_86 ;
break;
case V_87 :
V_80 = ( V_86 | V_84 ) ;
break;
default:
F_19 ( V_7 -> V_22 , L_3 ) ;
return - V_29 ;
}
switch ( V_79 & ( V_88 |
V_89 ) ) {
case ( V_90 | V_91 ) :
break;
case ( V_76 | V_92 ) :
case ( V_77 | V_92 ) :
V_80 |= V_93 ;
break;
case ( V_94 | V_91 ) :
V_80 |= V_95 ;
break;
case ( V_96 | V_91 ) :
V_80 |= V_97 ;
break;
default:
F_19 ( V_7 -> V_22 , L_4 ) ;
return - V_29 ;
}
V_17 -> V_75 = V_79 & V_88 ;
F_4 ( V_7 , V_61 , V_98 ,
V_80 ) ;
return 0 ;
}
static int F_20 ( struct V_48 * V_49 , int V_99 ,
unsigned int V_100 , int V_101 )
{
struct V_6 * V_7 = V_49 -> V_7 ;
struct V_16 * V_17 = F_7 ( V_7 -> V_22 ) ;
T_1 V_102 , V_103 , V_104 ;
switch ( V_99 ) {
case V_105 :
case V_106 :
if ( V_100 < 512000 || V_100 > 24576000 ) {
F_21 ( V_7 -> V_22 , L_5 ,
V_100 ) ;
V_99 = V_28 ;
V_100 = 0 ;
}
case V_28 :
case V_43 :
V_103 = V_39 ;
V_104 = ( V_99 << 3 ) & V_103 ;
V_102 = V_13 ;
V_17 -> V_27 = V_99 ;
V_17 -> V_25 = V_100 ;
break;
case V_107 :
case V_108 :
case V_109 :
case V_110 :
V_103 = V_111 ;
V_104 = ( V_99 >> 1 ) & V_103 ;
V_102 = V_112 ;
V_17 -> V_113 = V_99 ;
V_17 -> V_114 = V_100 ;
break;
default:
F_15 ( V_7 -> V_22 , L_6 , V_99 ) ;
return - V_29 ;
}
F_4 ( V_7 , V_102 , V_103 , V_104 ) ;
return 0 ;
}
static int F_22 ( struct V_48 * V_49 ,
unsigned int V_115 , unsigned int V_116 ,
int V_117 , int V_118 )
{
struct V_6 * V_7 = V_49 -> V_7 ;
struct V_16 * V_17 = F_17 ( V_7 ) ;
unsigned int V_119 ;
if ( F_23 ( ! V_115 ) ) {
F_15 ( V_7 -> V_22 , L_7 ) ;
return - V_29 ;
}
V_119 = F_24 ( V_115 ) ;
if ( ( V_119 + 1 ) != F_25 ( V_115 ) ) {
F_15 ( V_7 -> V_22 , L_8 ) ;
return - V_29 ;
}
V_17 -> V_30 = V_119 * V_118 ;
F_4 ( V_7 , V_120 ,
V_121 , V_121 ) ;
return 0 ;
}
static int F_26 ( struct V_48 * V_49 , int V_122 )
{
T_1 V_19 = 0 ;
struct V_6 * V_7 = V_49 -> V_7 ;
if ( V_122 )
V_19 |= V_123 ;
F_4 ( V_7 , V_13 , V_123 , V_19 ) ;
return 0 ;
}
static int F_27 ( struct V_124 * V_22 )
{
struct V_16 * V_17 = F_7 ( V_22 ) ;
F_5 ( V_17 , 1 ) ;
F_28 ( V_17 -> V_125 , true ) ;
F_29 ( V_17 -> V_125 ) ;
F_30 ( V_17 -> V_126 , 0 ) ;
return 0 ;
}
static int F_31 ( struct V_124 * V_22 )
{
struct V_16 * V_17 = F_7 ( V_22 ) ;
F_30 ( V_17 -> V_126 , 1 ) ;
F_5 ( V_17 , 0 ) ;
F_28 ( V_17 -> V_125 , false ) ;
F_32 ( V_17 -> V_125 ) ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_16 * V_17 = F_17 ( V_7 ) ;
int V_127 ;
V_17 -> V_7 = V_7 ;
V_127 = F_34 ( F_35 ( V_17 -> V_128 ) ,
V_17 -> V_128 ) ;
if ( V_127 != 0 ) {
F_15 ( V_7 -> V_22 , L_9 ,
V_127 ) ;
return V_127 ;
}
F_30 ( V_17 -> V_126 , 1 ) ;
V_127 = F_36 ( V_7 -> V_22 ) ;
if ( V_127 < 0 ) {
F_15 ( V_7 -> V_22 , L_10 ,
V_127 ) ;
goto V_129;
}
F_4 ( V_7 , V_13 , V_123 , V_123 ) ;
F_3 ( V_7 , V_72 , V_130 |
V_131 ) ;
F_3 ( V_7 , V_132 ,
V_133 |
F_37 ( V_134 ) ) ;
F_3 ( V_7 , V_135 , V_136 |
V_137 ) ;
F_3 ( V_7 , V_12 , V_138 | V_139 |
V_140 ) ;
return 0 ;
V_129:
F_30 ( V_17 -> V_126 , 0 ) ;
F_38 ( F_35 ( V_17 -> V_128 ) ,
V_17 -> V_128 ) ;
return V_127 ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_16 * V_17 = F_17 ( V_7 ) ;
F_40 ( V_7 -> V_22 ) ;
F_30 ( V_17 -> V_126 , 0 ) ;
return 0 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_16 * V_17 = F_17 ( V_7 ) ;
int V_127 ;
V_127 = F_38 ( F_35 ( V_17 -> V_128 ) ,
V_17 -> V_128 ) ;
if ( V_127 != 0 )
F_15 ( V_7 -> V_22 , L_11 ,
V_127 ) ;
return V_127 ;
}
static int F_42 ( struct V_6 * V_7 )
{
struct V_16 * V_17 = F_17 ( V_7 ) ;
int V_127 ;
V_127 = F_34 ( F_35 ( V_17 -> V_128 ) ,
V_17 -> V_128 ) ;
if ( V_127 != 0 ) {
F_15 ( V_7 -> V_22 , L_9 ,
V_127 ) ;
}
return V_127 ;
}
static int F_43 ( struct V_141 * V_142 ,
const struct V_143 * V_144 )
{
struct V_124 * V_22 ;
struct V_16 * V_145 ;
int V_127 ;
int V_146 ;
V_22 = & V_142 -> V_22 ;
V_145 = F_44 ( & V_142 -> V_22 , sizeof( * V_145 ) , V_147 ) ;
if ( V_145 == NULL )
return - V_148 ;
V_145 -> V_126 = F_45 ( V_22 , L_12 ,
V_149 ) ;
if ( F_46 ( V_145 -> V_126 ) )
return F_47 ( V_145 -> V_126 ) ;
V_145 -> V_150 = V_142 ;
V_145 -> V_125 = F_48 ( V_142 , & V_151 ) ;
if ( F_46 ( V_145 -> V_125 ) ) {
V_127 = F_47 ( V_145 -> V_125 ) ;
F_15 ( & V_142 -> V_22 , L_13 ,
V_127 ) ;
return V_127 ;
}
for ( V_146 = 0 ; V_146 < F_35 ( V_145 -> V_128 ) ; V_146 ++ )
V_145 -> V_128 [ V_146 ] . V_152 = V_153 [ V_146 ] ;
V_127 = F_49 ( V_22 , F_35 ( V_145 -> V_128 ) ,
V_145 -> V_128 ) ;
if ( V_127 != 0 ) {
F_15 ( V_22 , L_14 , V_127 ) ;
return V_127 ;
}
F_50 ( & V_142 -> V_22 ) ;
F_51 ( & V_142 -> V_22 , 1000 ) ;
F_52 ( & V_142 -> V_22 ) ;
F_53 ( & V_142 -> V_22 ) ;
F_54 ( & V_142 -> V_22 ) ;
F_55 ( & V_142 -> V_22 ) ;
F_56 ( & V_142 -> V_22 , V_145 ) ;
V_127 = F_57 ( & V_142 -> V_22 ,
& V_154 ,
V_155 , F_35 ( V_155 ) ) ;
if ( V_127 < 0 )
F_15 ( & V_142 -> V_22 , L_15 , V_127 ) ;
return V_127 ;
}
static int F_58 ( struct V_141 * V_142 )
{
F_59 ( & V_142 -> V_22 ) ;
F_60 ( & V_142 -> V_22 ) ;
return 0 ;
}
