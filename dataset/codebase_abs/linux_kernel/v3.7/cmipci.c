static inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline unsigned int F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , unsigned int V_3 , unsigned short V_4 )
{
F_6 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline unsigned short F_7 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_8 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , unsigned int V_3 , unsigned char V_4 )
{
F_10 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline unsigned char F_11 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_12 ( V_2 -> V_5 + V_3 ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_6 )
{
unsigned int V_7 , V_8 ;
V_7 = V_8 = F_4 ( V_2 -> V_5 + V_3 ) ;
V_7 |= V_6 ;
if ( V_7 == V_8 )
return 0 ;
F_2 ( V_7 , V_2 -> V_5 + V_3 ) ;
return 1 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_6 )
{
unsigned int V_7 , V_8 ;
V_7 = V_8 = F_4 ( V_2 -> V_5 + V_3 ) ;
V_7 &= ~ V_6 ;
if ( V_7 == V_8 )
return 0 ;
F_2 ( V_7 , V_2 -> V_5 + V_3 ) ;
return 1 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_3 , unsigned char V_6 )
{
unsigned char V_7 , V_8 ;
V_7 = V_8 = F_12 ( V_2 -> V_5 + V_3 ) ;
V_7 |= V_6 ;
if ( V_7 == V_8 )
return 0 ;
F_10 ( V_7 , V_2 -> V_5 + V_3 ) ;
return 1 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_3 , unsigned char V_6 )
{
unsigned char V_7 , V_8 ;
V_7 = V_8 = F_12 ( V_2 -> V_5 + V_3 ) ;
V_7 &= ~ V_6 ;
if ( V_7 == V_8 )
return 0 ;
F_10 ( V_7 , V_2 -> V_5 + V_3 ) ;
return 1 ;
}
static unsigned int F_17 ( unsigned int V_9 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < F_18 ( V_11 ) ; V_10 ++ ) {
if ( V_11 [ V_10 ] == V_9 )
return V_10 ;
}
F_19 () ;
return 0 ;
}
static int F_20 ( unsigned int V_9 , unsigned int V_12 , int * V_13 , int * V_14 , int * V_15 )
{
unsigned int V_16 , V_17 ;
int V_18 , V_19 , V_20 ;
for ( * V_13 = 0 ; V_9 < V_21 / V_12 ; * V_13 += ( 1 << 5 ) )
V_9 <<= 1 ;
* V_15 = - 1 ;
if ( * V_13 > 0xff )
goto V_22;
V_17 = V_9 * V_23 ;
for ( V_19 = ( 1 + 2 ) ; V_19 < ( 0x1f + 2 ) ; V_19 ++ ) {
for ( V_18 = ( 1 + 2 ) ; V_18 < ( 0xff + 2 ) ; V_18 ++ ) {
V_20 = ( ( V_24 / V_12 ) * V_18 ) / V_19 ;
if ( V_20 < V_9 )
V_16 = V_9 - V_20 ;
else
V_16 = V_20 - V_9 ;
if ( V_16 < V_17 ) {
V_17 = V_16 ;
* V_14 = V_18 - 2 ;
* V_15 = V_19 - 2 ;
}
}
}
V_22:
return ( * V_15 > - 1 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_9 , unsigned int V_25 )
{
unsigned int V_26 = V_27 + V_25 ;
F_9 ( V_2 , V_26 , V_9 >> 8 ) ;
F_9 ( V_2 , V_26 , V_9 & 0xff ) ;
}
static int F_22 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
return F_23 ( V_29 , F_24 ( V_31 ) ) ;
}
static int F_25 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
if ( F_27 ( V_31 ) > 2 ) {
F_28 ( & V_2 -> V_32 ) ;
if ( V_2 -> V_33 [ V_34 ] ) {
F_29 ( & V_2 -> V_32 ) ;
return - V_35 ;
}
V_2 -> V_33 [ V_34 ] = V_36 ;
F_29 ( & V_2 -> V_32 ) ;
}
return F_23 ( V_29 , F_24 ( V_31 ) ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_37 )
{
int V_38 = V_39 << ( V_2 -> V_40 [ V_37 ] . V_37 ) ;
F_1 ( V_2 , V_41 , V_2 -> V_42 | V_38 ) ;
F_1 ( V_2 , V_41 , V_2 -> V_42 & ~ V_38 ) ;
F_31 ( 10 ) ;
}
static int F_32 ( struct V_28 * V_29 )
{
return F_33 ( V_29 ) ;
}
static int F_34 ( struct V_1 * V_2 , struct V_43 * V_44 , int V_45 )
{
if ( V_45 > 2 ) {
if ( ! V_2 -> V_46 || ! V_44 -> V_37 )
return - V_47 ;
if ( V_44 -> V_48 != 0x03 )
return - V_47 ;
}
if ( V_2 -> V_46 ) {
F_35 ( & V_2 -> V_49 ) ;
if ( V_45 > 2 ) {
F_13 ( V_2 , V_50 , V_51 ) ;
F_13 ( V_2 , V_52 , V_53 ) ;
} else {
F_14 ( V_2 , V_50 , V_51 ) ;
F_14 ( V_2 , V_52 , V_53 ) ;
}
if ( V_45 == 8 )
F_13 ( V_2 , V_54 , V_55 ) ;
else
F_14 ( V_2 , V_54 , V_55 ) ;
if ( V_45 == 6 ) {
F_13 ( V_2 , V_56 , V_57 ) ;
F_13 ( V_2 , V_50 , V_58 ) ;
} else {
F_14 ( V_2 , V_56 , V_57 ) ;
F_14 ( V_2 , V_50 , V_58 ) ;
}
if ( V_45 == 4 )
F_13 ( V_2 , V_56 , V_59 ) ;
else
F_14 ( V_2 , V_56 , V_59 ) ;
F_36 ( & V_2 -> V_49 ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_28 * V_29 )
{
unsigned int V_26 , V_60 , V_61 , V_7 ;
unsigned int V_62 ;
struct V_63 * V_64 = V_29 -> V_64 ;
V_44 -> V_48 = 0 ;
V_44 -> V_65 = 0 ;
if ( F_38 ( V_64 -> V_66 ) >= 16 ) {
V_44 -> V_48 |= 0x02 ;
if ( F_38 ( V_64 -> V_66 ) > 16 )
V_44 -> V_65 ++ ;
}
if ( V_64 -> V_45 > 1 )
V_44 -> V_48 |= 0x01 ;
if ( V_44 -> V_67 && F_34 ( V_2 , V_44 , V_64 -> V_45 ) < 0 ) {
F_39 ( L_1 ) ;
return - V_47 ;
}
V_44 -> V_68 = V_64 -> V_69 ;
V_44 -> V_70 = V_64 -> V_71 << V_44 -> V_65 ;
V_62 = V_64 -> V_62 << V_44 -> V_65 ;
if ( V_64 -> V_45 > 2 ) {
V_44 -> V_70 = ( V_44 -> V_70 * V_64 -> V_45 ) / 2 ;
V_62 = ( V_62 * V_64 -> V_45 ) / 2 ;
}
F_35 ( & V_2 -> V_49 ) ;
V_26 = V_44 -> V_37 ? V_72 : V_73 ;
F_1 ( V_2 , V_26 , V_44 -> V_68 ) ;
V_26 = V_44 -> V_37 ? V_74 : V_75 ;
F_5 ( V_2 , V_26 , V_44 -> V_70 - 1 ) ;
F_5 ( V_2 , V_26 + 2 , V_62 - 1 ) ;
V_7 = V_44 -> V_37 ? V_76 : V_77 ;
if ( V_44 -> V_67 )
V_2 -> V_42 &= ~ V_7 ;
else
V_2 -> V_42 |= V_7 ;
F_1 ( V_2 , V_41 , V_2 -> V_42 ) ;
V_60 = 0 ;
V_61 = 0 ;
if ( V_64 -> V_9 > 48000 )
switch ( V_64 -> V_9 ) {
case 88200 : V_61 = V_78 ; break;
case 96000 : V_61 = V_79 ; break;
case 128000 : V_61 = V_80 ; break;
default: F_19 () ; break;
}
else
V_60 = F_17 ( V_64 -> V_9 ) ;
V_7 = F_3 ( V_2 , V_81 ) ;
if ( V_44 -> V_37 ) {
V_7 &= ~ V_82 ;
V_7 |= ( V_60 << V_83 ) & V_82 ;
} else {
V_7 &= ~ V_84 ;
V_7 |= ( V_60 << V_85 ) & V_84 ;
}
F_1 ( V_2 , V_81 , V_7 ) ;
V_7 = F_3 ( V_2 , V_56 ) ;
if ( V_44 -> V_37 ) {
V_7 &= ~ V_86 ;
V_7 |= V_44 -> V_48 << V_87 ;
} else {
V_7 &= ~ V_88 ;
V_7 |= V_44 -> V_48 << V_89 ;
}
if ( V_2 -> V_90 ) {
V_7 &= ~ ( V_91 << ( V_44 -> V_37 * 2 ) ) ;
V_7 |= V_61 << ( V_44 -> V_37 * 2 ) ;
}
F_1 ( V_2 , V_56 , V_7 ) ;
if ( ! V_44 -> V_67 && V_2 -> V_92 ) {
if ( V_64 -> V_9 > 44100 )
F_13 ( V_2 , V_54 , V_93 ) ;
else
F_14 ( V_2 , V_54 , V_93 ) ;
}
V_44 -> V_94 = 0 ;
F_36 ( & V_2 -> V_49 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_43 * V_44 ,
int V_3 )
{
unsigned int V_95 , V_96 , V_38 , V_97 ;
int V_98 = 0 ;
V_95 = V_99 << V_44 -> V_37 ;
V_96 = V_100 << V_44 -> V_37 ;
V_38 = V_39 << V_44 -> V_37 ;
V_97 = V_101 << V_44 -> V_37 ;
F_41 ( & V_2 -> V_49 ) ;
switch ( V_3 ) {
case V_102 :
V_44 -> V_94 = 1 ;
F_13 ( V_2 , V_103 , V_95 ) ;
V_2 -> V_42 |= V_96 ;
F_1 ( V_2 , V_41 , V_2 -> V_42 ) ;
break;
case V_104 :
V_44 -> V_94 = 0 ;
F_14 ( V_2 , V_103 , V_95 ) ;
V_2 -> V_42 &= ~ V_96 ;
F_1 ( V_2 , V_41 , V_2 -> V_42 | V_38 ) ;
F_1 ( V_2 , V_41 , V_2 -> V_42 & ~ V_38 ) ;
V_44 -> V_105 = V_44 -> V_67 ;
break;
case V_106 :
case V_107 :
V_2 -> V_42 |= V_97 ;
F_1 ( V_2 , V_41 , V_2 -> V_42 ) ;
break;
case V_108 :
case V_109 :
V_2 -> V_42 &= ~ V_97 ;
F_1 ( V_2 , V_41 , V_2 -> V_42 ) ;
break;
default:
V_98 = - V_47 ;
break;
}
F_42 ( & V_2 -> V_49 ) ;
return V_98 ;
}
static T_1 F_43 ( struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_28 * V_29 )
{
T_2 V_110 ;
unsigned int V_26 , V_111 , V_112 ;
if ( ! V_44 -> V_94 )
return 0 ;
#if 1
V_26 = V_44 -> V_37 ? V_74 : V_75 ;
for ( V_112 = 0 ; V_112 < 3 ; V_112 ++ ) {
V_111 = F_7 ( V_2 , V_26 ) ;
if ( V_111 < V_44 -> V_70 )
goto V_113;
}
F_44 ( V_114 L_2 , V_111 ) ;
return V_115 ;
V_113:
V_110 = ( V_44 -> V_70 - ( V_111 + 1 ) ) >> V_44 -> V_65 ;
#else
V_26 = V_44 -> V_37 ? V_72 : V_73 ;
V_110 = F_3 ( V_2 , V_26 ) - V_44 -> V_68 ;
V_110 = F_45 ( V_29 -> V_64 , V_110 ) ;
#endif
if ( V_29 -> V_64 -> V_45 > 2 )
V_110 = ( V_110 * 2 ) / V_29 -> V_64 -> V_45 ;
return V_110 ;
}
static int F_46 ( struct V_28 * V_29 ,
int V_3 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
return F_40 ( V_2 , & V_2 -> V_40 [ V_34 ] , V_3 ) ;
}
static T_1 F_47 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
return F_43 ( V_2 , & V_2 -> V_40 [ V_34 ] , V_29 ) ;
}
static int F_48 ( struct V_28 * V_29 ,
int V_3 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
return F_40 ( V_2 , & V_2 -> V_40 [ V_116 ] , V_3 ) ;
}
static T_1 F_49 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
return F_43 ( V_2 , & V_2 -> V_40 [ V_116 ] , V_29 ) ;
}
static int F_50 ( struct V_117 * V_118 ,
struct V_119 * V_120 )
{
V_120 -> type = V_121 ;
V_120 -> V_122 = 1 ;
return 0 ;
}
static int F_51 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_125 = F_52 ( V_118 ) ;
int V_10 ;
F_35 ( & V_125 -> V_49 ) ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
V_124 -> V_126 . V_127 . V_128 [ V_10 ] = ( V_125 -> V_129 >> ( V_10 * 8 ) ) & 0xff ;
F_36 ( & V_125 -> V_49 ) ;
return 0 ;
}
static int F_53 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_125 = F_52 ( V_118 ) ;
int V_10 , V_130 ;
unsigned int V_7 ;
V_7 = 0 ;
F_35 ( & V_125 -> V_49 ) ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
V_7 |= ( unsigned int ) V_124 -> V_126 . V_127 . V_128 [ V_10 ] << ( V_10 * 8 ) ;
V_130 = V_7 != V_125 -> V_129 ;
V_125 -> V_129 = V_7 ;
F_36 ( & V_125 -> V_49 ) ;
return V_130 ;
}
static int F_54 ( struct V_117 * V_118 ,
struct V_119 * V_120 )
{
V_120 -> type = V_121 ;
V_120 -> V_122 = 1 ;
return 0 ;
}
static int F_55 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
V_124 -> V_126 . V_127 . V_128 [ 0 ] = 0xff ;
V_124 -> V_126 . V_127 . V_128 [ 1 ] = 0xff ;
V_124 -> V_126 . V_127 . V_128 [ 2 ] = 0xff ;
V_124 -> V_126 . V_127 . V_128 [ 3 ] = 0xff ;
return 0 ;
}
static int F_56 ( struct V_117 * V_118 ,
struct V_119 * V_120 )
{
V_120 -> type = V_121 ;
V_120 -> V_122 = 1 ;
return 0 ;
}
static int F_57 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_125 = F_52 ( V_118 ) ;
int V_10 ;
F_35 ( & V_125 -> V_49 ) ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
V_124 -> V_126 . V_127 . V_128 [ V_10 ] = ( V_125 -> V_131 >> ( V_10 * 8 ) ) & 0xff ;
F_36 ( & V_125 -> V_49 ) ;
return 0 ;
}
static int F_58 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_125 = F_52 ( V_118 ) ;
int V_10 , V_130 ;
unsigned int V_7 ;
V_7 = 0 ;
F_35 ( & V_125 -> V_49 ) ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
V_7 |= ( unsigned int ) V_124 -> V_126 . V_127 . V_128 [ V_10 ] << ( V_10 * 8 ) ;
V_130 = V_7 != V_125 -> V_131 ;
V_125 -> V_131 = V_7 ;
F_36 ( & V_125 -> V_49 ) ;
return V_130 ;
}
static int F_59 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_132 ) {
struct V_123 * V_7 ;
unsigned int V_10 ;
V_7 = F_60 ( sizeof( * V_7 ) , V_133 ) ;
if ( ! V_7 )
return - V_134 ;
for ( V_10 = 0 ; V_10 < V_135 ; V_10 ++ ) {
struct V_117 * V_136 = V_2 -> V_137 [ V_10 ] ;
if ( V_136 ) {
int V_138 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_136 -> V_139 ( V_136 , V_7 ) ;
V_2 -> V_140 [ V_10 ] = V_7 -> V_126 . integer . V_126 [ 0 ] ;
V_7 -> V_126 . integer . V_126 [ 0 ] = V_141 [ V_10 ] . V_142 ;
V_138 = V_143 ;
if ( V_2 -> V_140 [ V_10 ] != V_7 -> V_126 . integer . V_126 [ 0 ] ) {
V_136 -> V_144 ( V_136 , V_7 ) ;
V_138 |= V_145 ;
}
V_136 -> V_146 [ 0 ] . V_147 |= V_148 ;
F_61 ( V_2 -> V_149 , V_138 , & V_136 -> V_150 ) ;
}
}
F_62 ( V_7 ) ;
V_2 -> V_132 = 1 ;
}
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_132 ) {
struct V_123 * V_7 ;
unsigned int V_10 ;
V_7 = F_60 ( sizeof( * V_7 ) , V_151 ) ;
if ( ! V_7 )
return;
V_2 -> V_132 = 0 ;
for ( V_10 = 0 ; V_10 < V_135 ; V_10 ++ ) {
struct V_117 * V_136 = V_2 -> V_137 [ V_10 ] ;
if ( V_136 ) {
int V_138 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_136 -> V_146 [ 0 ] . V_147 &= ~ V_148 ;
V_136 -> V_139 ( V_136 , V_7 ) ;
V_138 = V_143 ;
if ( V_7 -> V_126 . integer . V_126 [ 0 ] != V_2 -> V_140 [ V_10 ] ) {
V_7 -> V_126 . integer . V_126 [ 0 ] = V_2 -> V_140 [ V_10 ] ;
V_136 -> V_144 ( V_136 , V_7 ) ;
V_138 |= V_145 ;
}
F_61 ( V_2 -> V_149 , V_138 , & V_136 -> V_150 ) ;
}
}
F_62 ( V_7 ) ;
}
}
static void F_64 ( struct V_1 * V_2 , struct V_28 * V_152 , int V_153 , int V_9 )
{
if ( V_153 ) {
F_13 ( V_2 , V_56 , V_154 ) ;
F_13 ( V_2 , V_52 , V_155 ) ;
if ( V_2 -> V_156 ) {
F_13 ( V_2 , V_56 , V_157 ) ;
F_14 ( V_2 , V_52 , V_158 ) ;
} else {
F_13 ( V_2 , V_52 , V_158 ) ;
if ( V_2 -> V_92 == 33 ) {
if ( V_9 >= 48000 ) {
F_13 ( V_2 , V_56 , V_159 ) ;
} else {
F_14 ( V_2 , V_56 , V_159 ) ;
}
}
}
} else {
F_14 ( V_2 , V_56 , V_154 ) ;
F_14 ( V_2 , V_52 , V_155 ) ;
if ( V_2 -> V_156 ) {
if ( F_38 ( V_152 -> V_64 -> V_66 ) > 16 ) {
F_13 ( V_2 , V_52 , V_158 ) ;
F_13 ( V_2 , V_56 , V_157 ) ;
} else {
F_14 ( V_2 , V_52 , V_158 ) ;
F_14 ( V_2 , V_56 , V_157 ) ;
}
} else {
F_14 ( V_2 , V_52 , V_158 ) ;
F_14 ( V_2 , V_56 , V_157 ) ;
F_14 ( V_2 , V_56 , V_159 ) ;
}
}
}
static int F_65 ( struct V_1 * V_2 , struct V_28 * V_152 , int V_160 , int V_153 )
{
int V_9 , V_161 ;
V_9 = V_152 -> V_64 -> V_9 ;
if ( V_160 && V_153 )
if ( ( V_161 = F_59 ( V_2 ) ) < 0 )
return V_161 ;
F_35 ( & V_2 -> V_49 ) ;
V_2 -> V_162 = V_160 ;
if ( V_160 ) {
if ( V_2 -> V_163 )
F_13 ( V_2 , V_81 , V_164 ) ;
F_64 ( V_2 , V_152 , V_153 , V_9 ) ;
if ( V_9 == 48000 || V_9 == 96000 )
F_13 ( V_2 , V_52 , V_165 | V_166 ) ;
else
F_14 ( V_2 , V_52 , V_165 | V_166 ) ;
if ( V_9 > 48000 )
F_13 ( V_2 , V_56 , V_167 ) ;
else
F_14 ( V_2 , V_56 , V_167 ) ;
} else {
F_14 ( V_2 , V_56 , V_167 ) ;
F_14 ( V_2 , V_81 , V_164 ) ;
F_64 ( V_2 , V_152 , 0 , 0 ) ;
}
F_36 ( & V_2 -> V_49 ) ;
return 0 ;
}
static int F_66 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
int V_9 = V_29 -> V_64 -> V_9 ;
int V_161 , V_168 , V_153 = 0 ;
V_168 = ( V_9 >= 44100 && V_9 <= 96000 &&
V_29 -> V_64 -> V_66 == V_169 &&
V_29 -> V_64 -> V_45 == 2 ) ;
if ( V_168 && V_2 -> V_156 )
V_153 = V_2 -> V_131 & V_170 ;
if ( ( V_161 = F_65 ( V_2 , V_29 , V_168 , V_153 ) ) < 0 )
return V_161 ;
return F_37 ( V_2 , & V_2 -> V_40 [ V_34 ] , V_29 ) ;
}
static int F_67 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
int V_161 , V_153 ;
if ( V_2 -> V_156 )
V_153 = V_2 -> V_131 & V_170 ;
else
V_153 = 1 ;
if ( ( V_161 = F_65 ( V_2 , V_29 , 1 , V_153 ) ) < 0 )
return V_161 ;
return F_37 ( V_2 , & V_2 -> V_40 [ V_34 ] , V_29 ) ;
}
static void F_68 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_63 * V_64 = V_44 -> V_29 -> V_64 ;
unsigned int V_26 , V_7 ;
if ( V_44 -> V_105 && V_64 && V_64 -> V_171 ) {
memset ( V_64 -> V_171 , 0 , V_172 ) ;
V_26 = V_44 -> V_37 ? V_74 : V_75 ;
V_7 = ( ( V_172 / 4 ) - 1 ) | ( ( ( V_172 / 4 ) / 2 - 1 ) << 16 ) ;
F_1 ( V_2 , V_26 , V_7 ) ;
if ( V_64 -> V_45 > 2 )
F_34 ( V_2 , V_44 , 2 ) ;
F_35 ( & V_2 -> V_49 ) ;
V_7 = F_3 ( V_2 , V_81 ) ;
V_7 &= ~ ( V_84 << ( V_44 -> V_37 * 3 ) ) ;
V_7 |= ( 4 << V_85 ) << ( V_44 -> V_37 * 3 ) ;
F_1 ( V_2 , V_81 , V_7 ) ;
V_7 = F_3 ( V_2 , V_56 ) ;
V_7 &= ~ ( V_88 << ( V_44 -> V_37 * 2 ) ) ;
V_7 |= ( 3 << V_89 ) << ( V_44 -> V_37 * 2 ) ;
if ( V_2 -> V_90 )
V_7 &= ~ ( V_91 << ( V_44 -> V_37 * 2 ) ) ;
F_1 ( V_2 , V_56 , V_7 ) ;
V_2 -> V_42 |= V_100 << V_44 -> V_37 ;
F_1 ( V_2 , V_41 , V_2 -> V_42 ) ;
F_36 ( & V_2 -> V_49 ) ;
F_69 ( 1 ) ;
F_35 ( & V_2 -> V_49 ) ;
V_2 -> V_42 &= ~ ( V_100 << V_44 -> V_37 ) ;
V_7 = V_39 << V_44 -> V_37 ;
F_1 ( V_2 , V_41 , V_2 -> V_42 | V_7 ) ;
F_1 ( V_2 , V_41 , V_2 -> V_42 & ~ V_7 ) ;
F_36 ( & V_2 -> V_49 ) ;
V_44 -> V_105 = 0 ;
}
}
static int F_70 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
F_65 ( V_2 , V_29 , 0 , 0 ) ;
F_63 ( V_2 ) ;
F_68 ( V_2 , & V_2 -> V_40 [ 0 ] ) ;
return F_32 ( V_29 ) ;
}
static int F_71 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
F_68 ( V_2 , & V_2 -> V_40 [ 1 ] ) ;
return F_32 ( V_29 ) ;
}
static int F_72 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
return F_37 ( V_2 , & V_2 -> V_40 [ V_116 ] , V_29 ) ;
}
static int F_73 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
F_35 ( & V_2 -> V_49 ) ;
F_13 ( V_2 , V_81 , V_173 ) ;
if ( V_2 -> V_90 ) {
if ( V_29 -> V_64 -> V_9 > 48000 )
F_13 ( V_2 , V_56 , V_167 ) ;
else
F_14 ( V_2 , V_56 , V_167 ) ;
}
if ( F_38 ( V_29 -> V_64 -> V_66 ) > 16 )
F_13 ( V_2 , V_52 , V_158 ) ;
else
F_14 ( V_2 , V_52 , V_158 ) ;
F_36 ( & V_2 -> V_49 ) ;
return F_37 ( V_2 , & V_2 -> V_40 [ V_116 ] , V_29 ) ;
}
static int F_74 ( struct V_28 * V_152 )
{
struct V_1 * V_2 = F_26 ( V_152 ) ;
F_35 ( & V_2 -> V_49 ) ;
F_14 ( V_2 , V_81 , V_173 ) ;
F_14 ( V_2 , V_52 , V_158 ) ;
F_36 ( & V_2 -> V_49 ) ;
return F_32 ( V_152 ) ;
}
static T_3 F_75 ( int V_174 , void * V_175 )
{
struct V_1 * V_2 = V_175 ;
unsigned int V_128 , V_176 = 0 ;
V_128 = F_3 ( V_2 , V_177 ) ;
if ( ! ( V_128 & V_178 ) )
return V_179 ;
F_41 ( & V_2 -> V_49 ) ;
if ( V_128 & V_180 )
V_176 |= V_99 ;
if ( V_128 & V_181 )
V_176 |= V_182 ;
F_14 ( V_2 , V_103 , V_176 ) ;
F_13 ( V_2 , V_103 , V_176 ) ;
F_42 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_183 && ( V_128 & V_184 ) )
F_76 ( V_174 , V_2 -> V_183 -> V_185 ) ;
if ( V_2 -> V_186 ) {
if ( ( V_128 & V_180 ) && V_2 -> V_40 [ 0 ] . V_94 )
F_77 ( V_2 -> V_40 [ 0 ] . V_29 ) ;
if ( ( V_128 & V_181 ) && V_2 -> V_40 [ 1 ] . V_94 )
F_77 ( V_2 -> V_40 [ 1 ] . V_29 ) ;
}
return V_187 ;
}
static int F_78 ( struct V_1 * V_2 , int V_188 , struct V_28 * V_152 )
{
int V_37 = V_188 & V_189 ;
F_28 ( & V_2 -> V_32 ) ;
if ( V_2 -> V_33 [ V_37 ] ) {
F_29 ( & V_2 -> V_32 ) ;
return - V_35 ;
}
V_2 -> V_33 [ V_37 ] = V_188 ;
V_2 -> V_40 [ V_37 ] . V_29 = V_152 ;
if ( ! ( V_188 & V_190 ) ) {
V_2 -> V_40 [ V_37 ] . V_67 = 0 ;
F_35 ( & V_2 -> V_49 ) ;
F_14 ( V_2 , V_52 , V_191 ) ;
F_36 ( & V_2 -> V_49 ) ;
}
F_29 ( & V_2 -> V_32 ) ;
return 0 ;
}
static void F_79 ( struct V_1 * V_2 , int V_188 )
{
int V_37 = V_188 & V_189 ;
F_28 ( & V_2 -> V_32 ) ;
if ( V_2 -> V_33 [ V_37 ] == V_188 ) {
if ( V_2 -> V_40 [ V_37 ] . V_29 ) {
F_30 ( V_2 , V_37 ) ;
V_2 -> V_40 [ V_37 ] . V_94 = 0 ;
V_2 -> V_40 [ V_37 ] . V_29 = NULL ;
}
V_2 -> V_33 [ V_37 ] = 0 ;
if ( ! V_2 -> V_40 [ V_37 ] . V_67 ) {
V_2 -> V_40 [ V_37 ] . V_67 = 1 ;
F_35 ( & V_2 -> V_49 ) ;
F_13 ( V_2 , V_52 , V_191 ) ;
F_36 ( & V_2 -> V_49 ) ;
}
}
F_29 ( & V_2 -> V_32 ) ;
}
static int F_80 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
struct V_63 * V_64 = V_29 -> V_64 ;
int V_161 ;
if ( ( V_161 = F_78 ( V_2 , V_192 , V_29 ) ) < 0 )
return V_161 ;
V_64 -> V_193 = V_194 ;
if ( V_2 -> V_92 == 68 ) {
V_64 -> V_193 . V_11 |= V_195 |
V_196 ;
V_64 -> V_193 . V_197 = 96000 ;
} else if ( V_2 -> V_92 == 55 ) {
V_161 = F_81 ( V_64 , 0 ,
V_198 , & V_199 ) ;
if ( V_161 < 0 )
return V_161 ;
V_64 -> V_193 . V_11 |= V_200 ;
V_64 -> V_193 . V_197 = 128000 ;
}
F_82 ( V_64 , V_201 , 0 , 0x10000 ) ;
V_2 -> V_131 = V_2 -> V_129 ;
return 0 ;
}
static int F_83 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
struct V_63 * V_64 = V_29 -> V_64 ;
int V_161 ;
if ( ( V_161 = F_78 ( V_2 , V_202 , V_29 ) ) < 0 )
return V_161 ;
V_64 -> V_193 = V_203 ;
if ( V_2 -> V_92 == 68 ) {
V_64 -> V_193 . V_204 = 41000 ;
V_64 -> V_193 . V_11 = V_205 | V_206 ;
} else if ( V_2 -> V_92 == 55 ) {
V_161 = F_81 ( V_64 , 0 ,
V_198 , & V_199 ) ;
if ( V_161 < 0 )
return V_161 ;
V_64 -> V_193 . V_11 |= V_200 ;
V_64 -> V_193 . V_197 = 128000 ;
}
F_82 ( V_64 , V_201 , 0 , 0x10000 ) ;
return 0 ;
}
static int F_84 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
struct V_63 * V_64 = V_29 -> V_64 ;
int V_161 ;
if ( ( V_161 = F_78 ( V_2 , V_207 , V_29 ) ) < 0 )
return V_161 ;
V_64 -> V_193 = V_208 ;
F_28 ( & V_2 -> V_32 ) ;
if ( ! V_2 -> V_33 [ V_34 ] ) {
if ( V_2 -> V_46 ) {
V_64 -> V_193 . V_209 = V_2 -> V_210 ;
if ( V_2 -> V_210 == 4 )
F_81 ( V_64 , 0 , V_211 , & V_212 ) ;
else if ( V_2 -> V_210 == 6 )
F_81 ( V_64 , 0 , V_211 , & V_213 ) ;
else if ( V_2 -> V_210 == 8 )
F_81 ( V_64 , 0 , V_211 , & V_214 ) ;
}
}
F_29 ( & V_2 -> V_32 ) ;
if ( V_2 -> V_92 == 68 ) {
V_64 -> V_193 . V_11 |= V_195 |
V_196 ;
V_64 -> V_193 . V_197 = 96000 ;
} else if ( V_2 -> V_92 == 55 ) {
V_161 = F_81 ( V_64 , 0 ,
V_198 , & V_199 ) ;
if ( V_161 < 0 )
return V_161 ;
V_64 -> V_193 . V_11 |= V_200 ;
V_64 -> V_193 . V_197 = 128000 ;
}
F_82 ( V_64 , V_201 , 0 , 0x10000 ) ;
return 0 ;
}
static int F_85 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
struct V_63 * V_64 = V_29 -> V_64 ;
int V_161 ;
if ( ( V_161 = F_78 ( V_2 , V_215 , V_29 ) ) < 0 )
return V_161 ;
if ( V_2 -> V_156 ) {
V_64 -> V_193 = V_216 ;
if ( V_2 -> V_92 >= 37 ) {
V_64 -> V_193 . V_217 |= V_218 ;
F_86 ( V_64 , 0 , 32 , 24 ) ;
}
if ( V_2 -> V_90 ) {
V_64 -> V_193 . V_11 |= V_195 |
V_196 ;
V_64 -> V_193 . V_197 = 96000 ;
}
} else {
V_64 -> V_193 = V_219 ;
}
F_82 ( V_64 , V_201 , 0 , 0x40000 ) ;
V_2 -> V_131 = V_2 -> V_129 ;
return 0 ;
}
static int F_87 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
struct V_63 * V_64 = V_29 -> V_64 ;
int V_161 ;
if ( ( V_161 = F_78 ( V_2 , V_220 , V_29 ) ) < 0 )
return V_161 ;
V_64 -> V_193 = V_221 ;
if ( V_2 -> V_90 && ! ( V_2 -> V_92 == 68 ) ) {
V_64 -> V_193 . V_11 |= V_195 |
V_196 ;
V_64 -> V_193 . V_197 = 96000 ;
}
F_82 ( V_64 , V_201 , 0 , 0x40000 ) ;
return 0 ;
}
static int F_88 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
F_79 ( V_2 , V_192 ) ;
return 0 ;
}
static int F_89 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
F_79 ( V_2 , V_202 ) ;
return 0 ;
}
static int F_90 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
F_79 ( V_2 , V_207 ) ;
F_79 ( V_2 , V_36 ) ;
return 0 ;
}
static int F_91 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
F_79 ( V_2 , V_215 ) ;
return 0 ;
}
static int F_92 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
F_79 ( V_2 , V_220 ) ;
return 0 ;
}
static int T_4 F_93 ( struct V_1 * V_2 , int V_222 )
{
struct V_223 * V_186 ;
int V_161 ;
V_161 = F_94 ( V_2 -> V_149 , V_2 -> V_149 -> V_224 , V_222 , 1 , 1 , & V_186 ) ;
if ( V_161 < 0 )
return V_161 ;
F_95 ( V_186 , V_225 , & V_226 ) ;
F_95 ( V_186 , V_227 , & V_228 ) ;
V_186 -> V_185 = V_2 ;
V_186 -> V_229 = 0 ;
strcpy ( V_186 -> V_230 , L_3 ) ;
V_2 -> V_186 = V_186 ;
F_96 ( V_186 , V_231 ,
F_97 ( V_2 -> V_232 ) , 64 * 1024 , 128 * 1024 ) ;
return 0 ;
}
static int T_4 F_98 ( struct V_1 * V_2 , int V_222 )
{
struct V_223 * V_186 ;
int V_161 ;
V_161 = F_94 ( V_2 -> V_149 , V_2 -> V_149 -> V_224 , V_222 , 1 , 0 , & V_186 ) ;
if ( V_161 < 0 )
return V_161 ;
F_95 ( V_186 , V_225 , & V_233 ) ;
V_186 -> V_185 = V_2 ;
V_186 -> V_229 = 0 ;
strcpy ( V_186 -> V_230 , L_4 ) ;
V_2 -> V_234 = V_186 ;
F_96 ( V_186 , V_231 ,
F_97 ( V_2 -> V_232 ) , 64 * 1024 , 128 * 1024 ) ;
return 0 ;
}
static int T_4 F_99 ( struct V_1 * V_2 , int V_222 )
{
struct V_223 * V_186 ;
int V_161 ;
V_161 = F_94 ( V_2 -> V_149 , V_2 -> V_149 -> V_224 , V_222 , 1 , 1 , & V_186 ) ;
if ( V_161 < 0 )
return V_161 ;
F_95 ( V_186 , V_225 , & V_235 ) ;
F_95 ( V_186 , V_227 , & V_236 ) ;
V_186 -> V_185 = V_2 ;
V_186 -> V_229 = 0 ;
strcpy ( V_186 -> V_230 , L_5 ) ;
V_2 -> V_237 = V_186 ;
F_96 ( V_186 , V_231 ,
F_97 ( V_2 -> V_232 ) , 64 * 1024 , 128 * 1024 ) ;
V_161 = F_100 ( V_186 , V_225 ,
V_238 , V_2 -> V_210 , 0 ,
NULL ) ;
if ( V_161 < 0 )
return V_161 ;
return 0 ;
}
static void F_101 ( struct V_1 * V_239 , unsigned char V_240 , unsigned char V_4 )
{
F_10 ( V_240 , V_239 -> V_5 + V_241 ) ;
F_10 ( V_4 , V_239 -> V_5 + V_242 ) ;
}
static unsigned char F_102 ( struct V_1 * V_239 , unsigned char V_240 )
{
unsigned char V_243 ;
F_10 ( V_240 , V_239 -> V_5 + V_241 ) ;
V_243 = F_12 ( V_239 -> V_5 + V_242 ) ;
return V_243 ;
}
static void F_103 ( struct V_244 * V_13 , unsigned long V_7 )
{
V_13 -> V_245 = V_7 & 0xff ;
V_13 -> V_246 = ( V_7 >> 8 ) & 0xff ;
V_13 -> V_247 = ( V_7 >> 16 ) & 0x07 ;
V_13 -> V_248 = ( V_7 >> 19 ) & 0x07 ;
V_13 -> V_249 = ( V_7 >> 22 ) & 1 ;
V_13 -> V_250 = ( V_7 >> 23 ) & 1 ;
V_13 -> V_176 = ( V_7 >> 24 ) & 0xff ;
}
static int F_104 ( struct V_117 * V_118 ,
struct V_119 * V_120 )
{
struct V_244 V_26 ;
F_103 ( & V_26 , V_118 -> V_251 ) ;
V_120 -> type = V_26 . V_176 == 1 ? V_252 : V_253 ;
V_120 -> V_122 = V_26 . V_250 + 1 ;
V_120 -> V_126 . integer . V_254 = 0 ;
V_120 -> V_126 . integer . V_255 = V_26 . V_176 ;
return 0 ;
}
static int F_105 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_52 ( V_118 ) ;
struct V_244 V_26 ;
int V_7 ;
F_103 ( & V_26 , V_118 -> V_251 ) ;
F_35 ( & V_2 -> V_49 ) ;
V_7 = ( F_102 ( V_2 , V_26 . V_245 ) >> V_26 . V_247 ) & V_26 . V_176 ;
if ( V_26 . V_249 )
V_7 = V_26 . V_176 - V_7 ;
V_124 -> V_126 . integer . V_126 [ 0 ] = V_7 ;
if ( V_26 . V_250 ) {
V_7 = ( F_102 ( V_2 , V_26 . V_246 ) >> V_26 . V_248 ) & V_26 . V_176 ;
if ( V_26 . V_249 )
V_7 = V_26 . V_176 - V_7 ;
V_124 -> V_126 . integer . V_126 [ 1 ] = V_7 ;
}
F_36 ( & V_2 -> V_49 ) ;
return 0 ;
}
static int F_106 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_52 ( V_118 ) ;
struct V_244 V_26 ;
int V_130 ;
int V_256 , V_257 , V_258 , V_259 ;
F_103 ( & V_26 , V_118 -> V_251 ) ;
V_256 = V_124 -> V_126 . integer . V_126 [ 0 ] & V_26 . V_176 ;
if ( V_26 . V_249 )
V_256 = V_26 . V_176 - V_256 ;
V_256 <<= V_26 . V_247 ;
if ( V_26 . V_250 ) {
V_257 = V_124 -> V_126 . integer . V_126 [ 1 ] & V_26 . V_176 ;
if ( V_26 . V_249 )
V_257 = V_26 . V_176 - V_257 ;
V_257 <<= V_26 . V_248 ;
} else
V_257 = 0 ;
F_35 ( & V_2 -> V_49 ) ;
V_258 = F_102 ( V_2 , V_26 . V_245 ) ;
V_256 |= V_258 & ~ ( V_26 . V_176 << V_26 . V_247 ) ;
V_130 = V_256 != V_258 ;
if ( V_26 . V_250 ) {
if ( V_26 . V_245 != V_26 . V_246 ) {
F_101 ( V_2 , V_26 . V_245 , V_256 ) ;
V_259 = F_102 ( V_2 , V_26 . V_246 ) ;
} else
V_259 = V_256 ;
V_257 |= V_259 & ~ ( V_26 . V_176 << V_26 . V_248 ) ;
V_130 |= V_257 != V_259 ;
F_101 ( V_2 , V_26 . V_246 , V_257 ) ;
} else
F_101 ( V_2 , V_26 . V_245 , V_256 ) ;
F_36 ( & V_2 -> V_49 ) ;
return V_130 ;
}
static int F_107 ( struct V_117 * V_118 ,
struct V_119 * V_120 )
{
V_120 -> type = V_252 ;
V_120 -> V_122 = 4 ;
V_120 -> V_126 . integer . V_254 = 0 ;
V_120 -> V_126 . integer . V_255 = 1 ;
return 0 ;
}
static int F_108 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_52 ( V_118 ) ;
struct V_244 V_26 ;
int V_260 , V_261 ;
F_103 ( & V_26 , V_118 -> V_251 ) ;
F_35 ( & V_2 -> V_49 ) ;
V_260 = F_102 ( V_2 , V_26 . V_245 ) ;
V_261 = F_102 ( V_2 , V_26 . V_246 ) ;
F_36 ( & V_2 -> V_49 ) ;
V_124 -> V_126 . integer . V_126 [ 0 ] = ( V_260 >> V_26 . V_247 ) & 1 ;
V_124 -> V_126 . integer . V_126 [ 1 ] = ( V_261 >> V_26 . V_247 ) & 1 ;
V_124 -> V_126 . integer . V_126 [ 2 ] = ( V_260 >> V_26 . V_248 ) & 1 ;
V_124 -> V_126 . integer . V_126 [ 3 ] = ( V_261 >> V_26 . V_248 ) & 1 ;
return 0 ;
}
static int F_109 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_52 ( V_118 ) ;
struct V_244 V_26 ;
int V_130 ;
int V_260 , V_261 , V_262 , V_263 ;
F_103 ( & V_26 , V_118 -> V_251 ) ;
F_35 ( & V_2 -> V_49 ) ;
V_262 = F_102 ( V_2 , V_26 . V_245 ) ;
V_263 = F_102 ( V_2 , V_26 . V_246 ) ;
V_260 = V_262 & ~ ( ( 1 << V_26 . V_247 ) | ( 1 << V_26 . V_248 ) ) ;
V_261 = V_263 & ~ ( ( 1 << V_26 . V_247 ) | ( 1 << V_26 . V_248 ) ) ;
V_260 |= ( V_124 -> V_126 . integer . V_126 [ 0 ] & 1 ) << V_26 . V_247 ;
V_261 |= ( V_124 -> V_126 . integer . V_126 [ 1 ] & 1 ) << V_26 . V_247 ;
V_260 |= ( V_124 -> V_126 . integer . V_126 [ 2 ] & 1 ) << V_26 . V_248 ;
V_261 |= ( V_124 -> V_126 . integer . V_126 [ 3 ] & 1 ) << V_26 . V_248 ;
V_130 = V_260 != V_262 || V_261 != V_263 ;
F_101 ( V_2 , V_26 . V_245 , V_260 ) ;
F_101 ( V_2 , V_26 . V_246 , V_261 ) ;
F_36 ( & V_2 -> V_49 ) ;
return V_130 ;
}
static int F_110 ( struct V_117 * V_118 ,
struct V_119 * V_120 )
{
struct V_244 V_26 ;
F_103 ( & V_26 , V_118 -> V_251 ) ;
V_120 -> type = V_26 . V_176 == 1 ? V_252 : V_253 ;
V_120 -> V_122 = V_26 . V_250 + 1 ;
V_120 -> V_126 . integer . V_254 = 0 ;
V_120 -> V_126 . integer . V_255 = V_26 . V_176 ;
return 0 ;
}
static int F_111 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_52 ( V_118 ) ;
struct V_244 V_26 ;
unsigned char V_264 , V_7 ;
F_103 ( & V_26 , V_118 -> V_251 ) ;
F_35 ( & V_2 -> V_49 ) ;
V_264 = F_12 ( V_2 -> V_5 + V_26 . V_245 ) ;
V_7 = ( V_264 >> V_26 . V_247 ) & V_26 . V_176 ;
if ( V_26 . V_249 )
V_7 = V_26 . V_176 - V_7 ;
V_124 -> V_126 . integer . V_126 [ 0 ] = V_7 ;
if ( V_26 . V_250 ) {
V_7 = ( V_264 >> V_26 . V_248 ) & V_26 . V_176 ;
if ( V_26 . V_249 )
V_7 = V_26 . V_176 - V_7 ;
V_124 -> V_126 . integer . V_126 [ 1 ] = V_7 ;
}
F_36 ( & V_2 -> V_49 ) ;
return 0 ;
}
static int F_112 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_52 ( V_118 ) ;
struct V_244 V_26 ;
unsigned char V_264 , V_265 , V_7 ;
F_103 ( & V_26 , V_118 -> V_251 ) ;
F_35 ( & V_2 -> V_49 ) ;
V_264 = F_12 ( V_2 -> V_5 + V_26 . V_245 ) ;
V_7 = V_124 -> V_126 . integer . V_126 [ 0 ] & V_26 . V_176 ;
if ( V_26 . V_249 )
V_7 = V_26 . V_176 - V_7 ;
V_265 = V_264 & ~ ( V_26 . V_176 << V_26 . V_247 ) ;
V_265 |= ( V_7 << V_26 . V_247 ) ;
if ( V_26 . V_250 ) {
V_7 = V_124 -> V_126 . integer . V_126 [ 1 ] & V_26 . V_176 ;
if ( V_26 . V_249 )
V_7 = V_26 . V_176 - V_7 ;
V_265 &= ~ ( V_26 . V_176 << V_26 . V_248 ) ;
V_265 |= ( V_7 << V_26 . V_248 ) ;
}
F_10 ( V_265 , V_2 -> V_5 + V_26 . V_245 ) ;
F_36 ( & V_2 -> V_49 ) ;
return ( V_265 != V_264 ) ;
}
static int F_113 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
return F_111 ( V_118 , V_124 ) ;
}
static int F_114 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_52 ( V_118 ) ;
if ( V_2 -> V_132 ) {
return 0 ;
}
return F_112 ( V_118 , V_124 ) ;
}
static int F_115 ( struct V_117 * V_118 ,
struct V_123 * V_124 ,
struct V_266 * args )
{
unsigned int V_7 ;
struct V_1 * V_2 = F_52 ( V_118 ) ;
F_35 ( & V_2 -> V_49 ) ;
if ( args -> V_267 && V_2 -> V_132 ) {
V_124 -> V_126 . integer . V_126 [ 0 ] = 0 ;
F_36 ( & V_2 -> V_49 ) ;
return 0 ;
}
if ( args -> V_268 )
V_7 = F_12 ( V_2 -> V_5 + args -> V_26 ) ;
else
V_7 = F_3 ( V_2 , args -> V_26 ) ;
V_124 -> V_126 . integer . V_126 [ 0 ] = ( ( V_7 & args -> V_176 ) == args -> V_269 ) ? 1 : 0 ;
F_36 ( & V_2 -> V_49 ) ;
return 0 ;
}
static int F_116 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_266 * args ;
args = (struct V_266 * ) V_118 -> V_251 ;
if ( F_117 ( ! args ) )
return - V_47 ;
return F_115 ( V_118 , V_124 , args ) ;
}
static int F_118 ( struct V_117 * V_118 ,
struct V_123 * V_124 ,
struct V_266 * args )
{
unsigned int V_7 ;
int V_130 ;
struct V_1 * V_2 = F_52 ( V_118 ) ;
F_35 ( & V_2 -> V_49 ) ;
if ( args -> V_267 && V_2 -> V_132 ) {
F_36 ( & V_2 -> V_49 ) ;
return 0 ;
}
if ( args -> V_268 )
V_7 = F_12 ( V_2 -> V_5 + args -> V_26 ) ;
else
V_7 = F_3 ( V_2 , args -> V_26 ) ;
V_130 = ( V_7 & args -> V_176 ) != ( V_124 -> V_126 . integer . V_126 [ 0 ] ?
args -> V_269 : ( args -> V_176 & ~ args -> V_269 ) ) ;
if ( V_130 ) {
V_7 &= ~ args -> V_176 ;
if ( V_124 -> V_126 . integer . V_126 [ 0 ] )
V_7 |= args -> V_269 ;
else
V_7 |= ( args -> V_176 & ~ args -> V_269 ) ;
if ( args -> V_268 )
F_10 ( ( unsigned char ) V_7 , V_2 -> V_5 + args -> V_26 ) ;
else
F_1 ( V_2 , args -> V_26 , V_7 ) ;
}
F_36 ( & V_2 -> V_49 ) ;
return V_130 ;
}
static int F_119 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_266 * args ;
args = (struct V_266 * ) V_118 -> V_251 ;
if ( F_117 ( ! args ) )
return - V_47 ;
return F_118 ( V_118 , V_124 , args ) ;
}
static int F_120 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
int V_270 ;
V_270 = F_115 ( V_118 , V_124 , & V_271 ) ;
V_270 |= F_115 ( V_118 , V_124 , & V_272 ) ;
return V_270 ;
}
static int F_121 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_125 = F_52 ( V_118 ) ;
int V_270 ;
V_270 = F_118 ( V_118 , V_124 , & V_271 ) ;
V_270 |= F_118 ( V_118 , V_124 , & V_272 ) ;
if ( V_270 ) {
if ( V_124 -> V_126 . integer . V_126 [ 0 ] ) {
if ( V_125 -> V_162 )
F_13 ( V_125 , V_81 , V_164 ) ;
} else {
if ( V_125 -> V_162 )
F_14 ( V_125 , V_81 , V_164 ) ;
}
}
V_125 -> V_163 = V_124 -> V_126 . integer . V_126 [ 0 ] ;
return V_270 ;
}
static int F_122 ( struct V_117 * V_118 ,
struct V_119 * V_120 )
{
struct V_1 * V_2 = F_52 ( V_118 ) ;
static const char * const V_273 [ 3 ] = {
L_6 , L_7 , L_8
} ;
return F_123 ( V_120 , 1 ,
V_2 -> V_92 >= 39 ? 3 : 2 , V_273 ) ;
}
static inline unsigned int F_124 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
if ( V_2 -> V_92 >= 39 ) {
V_7 = F_3 ( V_2 , V_50 ) ;
if ( V_7 & ( V_274 | V_275 ) )
return 2 ;
}
V_7 = F_11 ( V_2 , V_276 ) ;
if ( V_7 & V_277 )
return 1 ;
return 0 ;
}
static int F_125 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_52 ( V_118 ) ;
F_35 ( & V_2 -> V_49 ) ;
V_124 -> V_126 . V_278 . V_279 [ 0 ] = F_124 ( V_2 ) ;
F_36 ( & V_2 -> V_49 ) ;
return 0 ;
}
static int F_126 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_52 ( V_118 ) ;
int V_130 ;
F_35 ( & V_2 -> V_49 ) ;
if ( V_124 -> V_126 . V_278 . V_279 [ 0 ] == 2 )
V_130 = F_13 ( V_2 , V_50 , V_274 | V_275 ) ;
else
V_130 = F_14 ( V_2 , V_50 , V_274 | V_275 ) ;
if ( V_124 -> V_126 . V_278 . V_279 [ 0 ] == 1 )
V_130 |= F_15 ( V_2 , V_276 , V_277 ) ;
else
V_130 |= F_16 ( V_2 , V_276 , V_277 ) ;
F_36 ( & V_2 -> V_49 ) ;
return V_130 ;
}
static int F_127 ( struct V_117 * V_118 ,
struct V_119 * V_120 )
{
static const char * const V_273 [ 2 ] = { L_9 , L_10 } ;
return F_123 ( V_120 , 1 , 2 , V_273 ) ;
}
static int F_128 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_52 ( V_118 ) ;
F_35 ( & V_2 -> V_49 ) ;
V_124 -> V_126 . V_278 . V_279 [ 0 ] =
( F_11 ( V_2 , V_280 ) & V_281 ) ? 1 : 0 ;
F_36 ( & V_2 -> V_49 ) ;
return 0 ;
}
static int F_129 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_52 ( V_118 ) ;
int V_130 ;
F_35 ( & V_2 -> V_49 ) ;
if ( V_124 -> V_126 . V_278 . V_279 [ 0 ] )
V_130 = F_15 ( V_2 , V_280 , V_281 ) ;
else
V_130 = F_16 ( V_2 , V_280 , V_281 ) ;
F_36 ( & V_2 -> V_49 ) ;
return V_130 ;
}
static int T_4 F_130 ( struct V_1 * V_2 , int V_282 )
{
struct V_283 * V_149 ;
struct V_284 * V_285 ;
struct V_117 * V_286 ;
unsigned int V_240 ;
int V_161 ;
if ( F_117 ( ! V_2 || ! V_2 -> V_149 ) )
return - V_47 ;
V_149 = V_2 -> V_149 ;
strcpy ( V_149 -> V_287 , L_11 ) ;
F_35 ( & V_2 -> V_49 ) ;
F_101 ( V_2 , 0x00 , 0x00 ) ;
F_36 ( & V_2 -> V_49 ) ;
for ( V_240 = 0 ; V_240 < F_18 ( V_288 ) ; V_240 ++ ) {
if ( V_2 -> V_92 == 68 ) {
if ( ! strcmp ( V_288 [ V_240 ] . V_230 ,
L_12 ) )
continue;
}
if ( ( V_161 = F_131 ( V_149 , F_132 ( & V_288 [ V_240 ] , V_2 ) ) ) < 0 )
return V_161 ;
}
V_285 = V_289 ;
for ( V_240 = 0 ; V_240 < F_18 ( V_289 ) ; V_240 ++ , V_285 ++ ) {
V_161 = F_131 ( V_2 -> V_149 , F_132 ( V_285 , V_2 ) ) ;
if ( V_161 < 0 )
return V_161 ;
}
if ( ! V_2 -> V_46 ) {
V_161 = F_131 ( V_2 -> V_149 , F_132 ( & V_290 , V_2 ) ) ;
if ( V_161 < 0 )
return V_161 ;
}
if ( V_2 -> V_222 == V_291 ||
V_2 -> V_222 == V_292 ) {
V_285 = V_293 ;
for ( V_240 = 0 ; V_240 < F_18 ( V_293 ) ; V_240 ++ , V_285 ++ ) {
V_161 = F_131 ( V_2 -> V_149 , F_132 ( V_285 , V_2 ) ) ;
if ( V_161 < 0 )
return V_161 ;
}
if ( V_2 -> V_156 ) {
if ( ( V_161 = F_131 ( V_149 , V_286 = F_132 ( & V_294 , V_2 ) ) ) < 0 )
return V_161 ;
V_286 -> V_150 . V_222 = V_282 ;
if ( ( V_161 = F_131 ( V_149 , V_286 = F_132 ( & V_295 , V_2 ) ) ) < 0 )
return V_161 ;
V_286 -> V_150 . V_222 = V_282 ;
if ( ( V_161 = F_131 ( V_149 , V_286 = F_132 ( & V_296 , V_2 ) ) ) < 0 )
return V_161 ;
V_286 -> V_150 . V_222 = V_282 ;
}
if ( V_2 -> V_92 <= 37 ) {
V_285 = V_297 ;
for ( V_240 = 0 ; V_240 < F_18 ( V_297 ) ; V_240 ++ , V_285 ++ ) {
V_161 = F_131 ( V_2 -> V_149 , F_132 ( V_285 , V_2 ) ) ;
if ( V_161 < 0 )
return V_161 ;
}
}
}
if ( V_2 -> V_92 >= 39 ) {
V_285 = V_298 ;
for ( V_240 = 0 ; V_240 < F_18 ( V_298 ) ; V_240 ++ , V_285 ++ ) {
V_161 = F_131 ( V_2 -> V_149 , F_132 ( V_285 , V_2 ) ) ;
if ( V_161 < 0 )
return V_161 ;
}
}
if ( V_2 -> V_92 < 39 ) {
V_161 = F_131 ( V_2 -> V_149 ,
F_132 ( & V_299 , V_2 ) ) ;
if ( V_161 < 0 )
return V_161 ;
}
for ( V_240 = 0 ; V_240 < V_135 ; V_240 ++ ) {
struct V_300 V_301 ;
struct V_117 * V_136 ;
memset ( & V_301 , 0 , sizeof( V_301 ) ) ;
V_301 . V_302 = V_303 ;
strcpy ( V_301 . V_230 , V_141 [ V_240 ] . V_230 ) ;
V_136 = F_133 ( V_2 -> V_149 , & V_301 ) ;
if ( V_136 )
V_2 -> V_137 [ V_240 ] = V_136 ;
}
return 0 ;
}
static void F_134 ( struct V_304 * V_305 ,
struct V_306 * V_307 )
{
struct V_1 * V_2 = V_305 -> V_185 ;
int V_10 , V_243 ;
F_135 ( V_307 , L_13 , V_2 -> V_149 -> V_308 ) ;
for ( V_10 = 0 ; V_10 < 0x94 ; V_10 ++ ) {
if ( V_10 == 0x28 )
V_10 = 0x90 ;
V_243 = F_12 ( V_2 -> V_5 + V_10 ) ;
if ( V_10 % 4 == 0 )
F_135 ( V_307 , L_14 , V_10 ) ;
F_135 ( V_307 , L_15 , V_243 ) ;
}
F_135 ( V_307 , L_16 ) ;
}
static void T_4 F_136 ( struct V_1 * V_2 )
{
struct V_304 * V_305 ;
if ( ! F_137 ( V_2 -> V_149 , L_17 , & V_305 ) )
F_138 ( V_305 , V_2 , F_134 ) ;
}
static inline void F_136 ( struct V_1 * V_2 ) {}
static void T_4 F_139 ( struct V_1 * V_2 )
{
unsigned int V_309 ;
V_309 = F_3 ( V_2 , V_103 ) & V_310 ;
if ( ! V_309 ) {
V_309 = F_3 ( V_2 , V_56 ) & V_311 ;
switch ( V_309 ) {
case 0 :
V_2 -> V_92 = 33 ;
if ( V_2 -> V_312 )
V_2 -> V_313 = 1 ;
else
V_2 -> V_156 = 1 ;
break;
case V_314 :
V_2 -> V_92 = 37 ;
V_2 -> V_156 = 1 ;
break;
default:
V_2 -> V_92 = 39 ;
V_2 -> V_156 = 1 ;
break;
}
V_2 -> V_210 = 2 ;
} else {
if ( V_309 & V_315 ) {
V_2 -> V_92 = 39 ;
if ( V_309 & V_316 )
V_2 -> V_210 = 6 ;
else
V_2 -> V_210 = 4 ;
} else if ( V_309 & V_317 ) {
V_2 -> V_92 = 68 ;
V_2 -> V_210 = 8 ;
V_2 -> V_90 = 1 ;
} else {
V_2 -> V_92 = 55 ;
V_2 -> V_210 = 6 ;
V_2 -> V_90 = 1 ;
}
V_2 -> V_156 = 1 ;
V_2 -> V_46 = 1 ;
}
}
static int T_4 F_140 ( struct V_1 * V_2 , int V_318 )
{
static int V_319 [] = { 0x201 , 0x200 , 0 } ;
struct V_320 * V_321 ;
struct V_322 * V_13 = NULL ;
int V_10 , V_323 = 0 ;
if ( V_324 [ V_318 ] == 0 )
return - V_325 ;
if ( V_324 [ V_318 ] == 1 ) {
for ( V_10 = 0 ; V_319 [ V_10 ] ; V_10 ++ ) {
V_323 = V_319 [ V_10 ] ;
V_13 = F_141 ( V_323 , 1 , L_18 ) ;
if ( V_13 )
break;
}
} else {
V_323 = V_324 [ V_318 ] ;
V_13 = F_141 ( V_323 , 1 , L_18 ) ;
}
if ( ! V_13 ) {
F_44 ( V_326 L_19 ) ;
return - V_35 ;
}
V_2 -> V_320 = V_321 = F_142 () ;
if ( ! V_321 ) {
F_44 ( V_114 L_20 ) ;
F_143 ( V_13 ) ;
return - V_134 ;
}
F_144 ( V_321 , L_21 ) ;
F_145 ( V_321 , L_22 , F_146 ( V_2 -> V_232 ) ) ;
F_147 ( V_321 , & V_2 -> V_232 -> V_318 ) ;
V_321 -> V_327 = V_323 ;
F_148 ( V_321 , V_13 ) ;
F_13 ( V_2 , V_81 , V_328 ) ;
F_149 ( V_2 -> V_320 ) ;
return 0 ;
}
static void F_150 ( struct V_1 * V_2 )
{
if ( V_2 -> V_320 ) {
struct V_322 * V_13 = F_151 ( V_2 -> V_320 ) ;
F_152 ( V_2 -> V_320 ) ;
V_2 -> V_320 = NULL ;
F_14 ( V_2 , V_81 , V_328 ) ;
F_143 ( V_13 ) ;
}
}
static inline int F_140 ( struct V_1 * V_2 , int V_318 ) { return - V_329 ; }
static inline void F_150 ( struct V_1 * V_2 ) { }
static int F_153 ( struct V_1 * V_2 )
{
if ( V_2 -> V_174 >= 0 ) {
F_14 ( V_2 , V_52 , V_330 ) ;
F_14 ( V_2 , V_50 , V_331 ) ;
F_1 ( V_2 , V_103 , 0 ) ;
F_30 ( V_2 , V_34 ) ;
F_30 ( V_2 , V_116 ) ;
F_1 ( V_2 , V_41 , 0 ) ;
F_1 ( V_2 , V_81 , 0 ) ;
F_101 ( V_2 , 0 , 0 ) ;
F_154 ( V_2 -> V_174 , V_2 ) ;
}
F_150 ( V_2 ) ;
F_155 ( V_2 -> V_232 ) ;
F_156 ( V_2 -> V_232 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
static int F_157 ( struct V_332 * V_222 )
{
struct V_1 * V_2 = V_222 -> V_333 ;
return F_153 ( V_2 ) ;
}
static int T_4 F_158 ( struct V_1 * V_2 , long V_334 )
{
long V_335 ;
unsigned int V_7 ;
struct V_336 * V_337 ;
int V_161 ;
if ( ! V_334 )
goto V_338;
if ( V_2 -> V_92 >= 39 ) {
V_335 = V_2 -> V_5 + V_339 ;
V_161 = F_159 ( V_2 -> V_149 , V_335 , V_335 + 2 ,
V_340 , 1 , & V_337 ) ;
} else {
V_161 = - V_341 ;
}
if ( V_161 < 0 ) {
V_7 = F_3 ( V_2 , V_50 ) & ~ V_342 ;
V_335 = V_334 ;
switch ( V_335 ) {
case 0x3E8 : V_7 |= V_343 ; break;
case 0x3E0 : V_7 |= V_344 ; break;
case 0x3C8 : V_7 |= V_345 ; break;
case 0x388 : V_7 |= V_346 ; break;
default:
goto V_338;
}
F_1 ( V_2 , V_50 , V_7 ) ;
F_13 ( V_2 , V_52 , V_330 ) ;
if ( F_159 ( V_2 -> V_149 , V_335 , V_335 + 2 ,
V_340 , 0 , & V_337 ) < 0 ) {
F_44 ( V_114 L_23
L_24 , V_335 ) ;
goto V_338;
}
}
if ( ( V_161 = F_160 ( V_337 , 0 , 1 , NULL ) ) < 0 ) {
F_44 ( V_114 L_25 ) ;
return V_161 ;
}
return 0 ;
V_338:
F_14 ( V_2 , V_50 , V_342 ) ;
F_14 ( V_2 , V_52 , V_330 ) ;
return 0 ;
}
static int T_4 F_161 ( struct V_283 * V_149 , struct V_347 * V_232 ,
int V_318 , struct V_1 * * V_348 )
{
struct V_1 * V_2 ;
int V_161 ;
static struct V_349 V_350 = {
. V_351 = F_157 ,
} ;
unsigned int V_7 ;
long V_352 = 0 ;
int V_353 = 0 ;
char V_354 [ 16 ] ;
int V_355 , V_356 ;
static F_162 ( V_357 ) = {
{ F_163 (PCI_VENDOR_ID_INTEL, PCI_DEVICE_ID_INTEL_82437VX) } ,
{ } ,
} ;
* V_348 = NULL ;
if ( ( V_161 = F_164 ( V_232 ) ) < 0 )
return V_161 ;
V_2 = F_165 ( sizeof( * V_2 ) , V_151 ) ;
if ( V_2 == NULL ) {
F_156 ( V_232 ) ;
return - V_134 ;
}
F_166 ( & V_2 -> V_49 ) ;
F_167 ( & V_2 -> V_32 ) ;
V_2 -> V_222 = V_232 -> V_222 ;
V_2 -> V_149 = V_149 ;
V_2 -> V_232 = V_232 ;
V_2 -> V_174 = - 1 ;
V_2 -> V_40 [ 0 ] . V_37 = 0 ;
V_2 -> V_40 [ 1 ] . V_37 = 1 ;
V_2 -> V_40 [ 0 ] . V_67 = V_2 -> V_40 [ 1 ] . V_67 = 1 ;
if ( ( V_161 = F_168 ( V_232 , V_149 -> V_224 ) ) < 0 ) {
F_62 ( V_2 ) ;
F_156 ( V_232 ) ;
return V_161 ;
}
V_2 -> V_5 = F_169 ( V_232 , 0 ) ;
if ( F_170 ( V_232 -> V_174 , F_75 ,
V_358 , V_359 , V_2 ) ) {
F_171 ( V_114 L_26 , V_232 -> V_174 ) ;
F_153 ( V_2 ) ;
return - V_35 ;
}
V_2 -> V_174 = V_232 -> V_174 ;
F_172 ( V_2 -> V_232 ) ;
V_2 -> V_92 = 0 ;
V_2 -> V_210 = 2 ;
V_2 -> V_312 = V_360 [ V_318 ] ;
if ( V_232 -> V_222 != V_361 &&
V_232 -> V_222 != V_362 )
F_139 ( V_2 ) ;
if ( V_2 -> V_46 )
sprintf ( V_2 -> V_149 -> V_224 + strlen ( V_2 -> V_149 -> V_224 ) ,
L_27 , V_2 -> V_210 ) ;
else if ( V_2 -> V_313 )
strcpy ( V_2 -> V_149 -> V_224 + strlen ( V_2 -> V_149 -> V_224 ) , L_28 ) ;
V_2 -> V_129 = V_363 ;
V_2 -> V_131 = V_363 ;
#if V_34 == 1
V_2 -> V_42 = V_77 ;
#else
V_2 -> V_42 = V_76 ;
#endif
F_13 ( V_2 , V_52 , V_364 ) ;
F_14 ( V_2 , V_52 , V_364 ) ;
F_1 ( V_2 , V_103 , 0 ) ;
F_30 ( V_2 , V_34 ) ;
F_30 ( V_2 , V_116 ) ;
F_1 ( V_2 , V_41 , 0 ) ;
F_1 ( V_2 , V_81 , 0 ) ;
F_1 ( V_2 , V_56 , 0 ) ;
F_13 ( V_2 , V_52 , V_191 | V_365 ) ;
#if V_34 == 1
F_13 ( V_2 , V_52 , V_53 ) ;
#else
F_14 ( V_2 , V_52 , V_53 ) ;
#endif
if ( V_2 -> V_92 ) {
F_9 ( V_2 , V_54 , 0x20 ) ;
F_9 ( V_2 , V_54 + 1 , 0x09 ) ;
}
F_13 ( V_2 , V_81 , V_366 ) ;
switch ( V_232 -> V_222 ) {
case V_291 :
case V_292 :
if ( ! F_173 ( V_357 ) )
F_13 ( V_2 , V_52 , V_367 ) ;
break;
default:
break;
}
if ( V_2 -> V_92 < 68 ) {
V_7 = V_232 -> V_222 < 0x110 ? 8338 : 8738 ;
} else {
switch ( F_11 ( V_2 , V_103 + 3 ) & 0x03 ) {
case 0 :
V_7 = 8769 ;
break;
case 2 :
V_7 = 8762 ;
break;
default:
switch ( ( V_232 -> V_368 << 16 ) |
V_232 -> V_369 ) {
case 0x13f69761 :
case 0x584d3741 :
case 0x584d3751 :
case 0x584d3761 :
case 0x584d3771 :
case 0x72848384 :
V_7 = 8770 ;
break;
default:
V_7 = 8768 ;
break;
}
}
}
sprintf ( V_149 -> V_370 , L_29 , V_7 ) ;
if ( V_2 -> V_92 < 68 )
sprintf ( V_354 , L_30 , V_2 -> V_92 ) ;
else
V_354 [ 0 ] = '\0' ;
sprintf ( V_149 -> V_308 , L_31 ,
V_149 -> V_370 , V_354 , V_2 -> V_5 , V_2 -> V_174 ) ;
if ( ( V_161 = F_174 ( V_149 , V_371 , V_2 , & V_350 ) ) < 0 ) {
F_153 ( V_2 ) ;
return V_161 ;
}
if ( V_2 -> V_92 >= 39 ) {
V_7 = F_11 ( V_2 , V_372 + 1 ) ;
if ( V_7 != 0x00 && V_7 != 0xff ) {
V_352 = V_2 -> V_5 + V_372 ;
V_353 = 1 ;
}
}
if ( ! V_353 ) {
V_7 = 0 ;
V_352 = V_373 [ V_318 ] ;
switch ( V_352 ) {
case 0x320 : V_7 = V_374 ; break;
case 0x310 : V_7 = V_375 ; break;
case 0x300 : V_7 = V_376 ; break;
case 0x330 : V_7 = V_377 ; break;
default:
V_352 = 0 ; break;
}
if ( V_352 > 0 ) {
F_1 ( V_2 , V_50 , V_7 ) ;
F_13 ( V_2 , V_81 , V_378 ) ;
if ( F_12 ( V_352 + 1 ) == 0xff ) {
F_171 ( V_114 L_32
L_33 , V_352 ) ;
F_14 ( V_2 , V_81 ,
V_378 ) ;
V_352 = 0 ;
}
}
}
if ( V_2 -> V_92 < 68 ) {
V_161 = F_158 ( V_2 , V_334 [ V_318 ] ) ;
if ( V_161 < 0 )
return V_161 ;
}
F_101 ( V_2 , 0 , 0 ) ;
F_136 ( V_2 ) ;
V_355 = V_356 = 0 ;
if ( ( V_161 = F_93 ( V_2 , V_355 ) ) < 0 )
return V_161 ;
V_355 ++ ;
if ( ( V_161 = F_98 ( V_2 , V_355 ) ) < 0 )
return V_161 ;
V_355 ++ ;
if ( V_2 -> V_156 || V_2 -> V_313 ) {
V_356 = V_355 ;
if ( ( V_161 = F_99 ( V_2 , V_355 ) ) < 0 )
return V_161 ;
}
if ( ( V_161 = F_130 ( V_2 , V_356 ) ) < 0 )
return V_161 ;
if ( V_352 > 0 ) {
if ( ( V_161 = F_175 ( V_149 , 0 , V_379 ,
V_352 ,
( V_353 ?
V_380 : 0 ) |
V_381 ,
- 1 , & V_2 -> V_183 ) ) < 0 ) {
F_44 ( V_114 L_34 , V_352 ) ;
}
}
#ifdef F_176
for ( V_7 = 0 ; V_7 < F_18 ( V_11 ) ; V_7 ++ )
F_21 ( V_2 , V_11 [ V_7 ] , V_7 ) ;
F_13 ( V_2 , V_52 , V_165 | V_166 ) ;
#endif
if ( F_140 ( V_2 , V_318 ) < 0 )
F_14 ( V_2 , V_81 , V_328 ) ;
F_177 ( V_149 , & V_232 -> V_318 ) ;
* V_348 = V_2 ;
return 0 ;
}
static int T_4 F_178 ( struct V_347 * V_232 ,
const struct V_382 * V_383 )
{
static int V_318 ;
struct V_283 * V_149 ;
struct V_1 * V_2 ;
int V_161 ;
if ( V_318 >= V_384 )
return - V_325 ;
if ( ! V_385 [ V_318 ] ) {
V_318 ++ ;
return - V_386 ;
}
V_161 = F_179 ( V_387 [ V_318 ] , V_150 [ V_318 ] , V_388 , 0 , & V_149 ) ;
if ( V_161 < 0 )
return V_161 ;
switch ( V_232 -> V_222 ) {
case V_291 :
case V_292 :
strcpy ( V_149 -> V_224 , L_35 ) ;
break;
case V_361 :
case V_362 :
strcpy ( V_149 -> V_224 , L_36 ) ;
break;
default:
strcpy ( V_149 -> V_224 , L_37 ) ;
break;
}
if ( ( V_161 = F_161 ( V_149 , V_232 , V_318 , & V_2 ) ) < 0 ) {
F_180 ( V_149 ) ;
return V_161 ;
}
V_149 -> V_185 = V_2 ;
if ( ( V_161 = F_181 ( V_149 ) ) < 0 ) {
F_180 ( V_149 ) ;
return V_161 ;
}
F_182 ( V_232 , V_149 ) ;
V_318 ++ ;
return 0 ;
}
static void T_5 F_183 ( struct V_347 * V_232 )
{
F_180 ( F_184 ( V_232 ) ) ;
F_182 ( V_232 , NULL ) ;
}
static int F_185 ( struct V_222 * V_318 )
{
struct V_347 * V_232 = F_186 ( V_318 ) ;
struct V_283 * V_149 = F_187 ( V_318 ) ;
struct V_1 * V_2 = V_149 -> V_185 ;
int V_10 ;
F_188 ( V_149 , V_389 ) ;
F_189 ( V_2 -> V_186 ) ;
F_189 ( V_2 -> V_234 ) ;
F_189 ( V_2 -> V_237 ) ;
for ( V_10 = 0 ; V_10 < F_18 ( V_390 ) ; V_10 ++ )
V_2 -> V_390 [ V_10 ] = F_3 ( V_2 , V_390 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < F_18 ( V_391 ) ; V_10 ++ )
V_2 -> V_391 [ V_10 ] = F_102 ( V_2 , V_391 [ V_10 ] ) ;
F_1 ( V_2 , V_103 , 0 ) ;
F_156 ( V_232 ) ;
F_190 ( V_232 ) ;
F_191 ( V_232 , V_392 ) ;
return 0 ;
}
static int F_192 ( struct V_222 * V_318 )
{
struct V_347 * V_232 = F_186 ( V_318 ) ;
struct V_283 * V_149 = F_187 ( V_318 ) ;
struct V_1 * V_2 = V_149 -> V_185 ;
int V_10 ;
F_191 ( V_232 , V_393 ) ;
F_193 ( V_232 ) ;
if ( F_164 ( V_232 ) < 0 ) {
F_44 ( V_114 L_38
L_39 ) ;
F_194 ( V_149 ) ;
return - V_341 ;
}
F_172 ( V_232 ) ;
F_1 ( V_2 , V_103 , 0 ) ;
F_30 ( V_2 , V_34 ) ;
F_30 ( V_2 , V_116 ) ;
F_101 ( V_2 , 0 , 0 ) ;
for ( V_10 = 0 ; V_10 < F_18 ( V_390 ) ; V_10 ++ )
F_1 ( V_2 , V_390 [ V_10 ] , V_2 -> V_390 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < F_18 ( V_391 ) ; V_10 ++ )
F_101 ( V_2 , V_391 [ V_10 ] , V_2 -> V_391 [ V_10 ] ) ;
F_188 ( V_149 , V_394 ) ;
return 0 ;
}
