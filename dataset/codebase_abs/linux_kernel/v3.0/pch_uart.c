static void F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_7 = 1 ;
V_6 -> V_8 = 0 ;
}
static unsigned int F_3 ( struct V_5 * V_6 , void T_1 * V_9 )
{
unsigned int V_10 = F_4 ( V_9 + V_11 ) ;
V_6 -> V_12 |= V_10 & V_13 ;
return V_10 ;
}
static void F_5 ( struct V_5 * V_6 ,
unsigned int V_14 )
{
T_2 V_15 = F_4 ( V_6 -> V_16 + V_17 ) ;
V_15 |= V_14 & V_18 ;
F_6 ( V_15 , V_6 -> V_16 + V_17 ) ;
}
static void F_7 ( struct V_5 * V_6 ,
unsigned int V_14 )
{
T_2 V_15 = F_4 ( V_6 -> V_16 + V_17 ) ;
V_15 &= ~ ( V_14 & V_18 ) ;
F_6 ( V_15 , V_6 -> V_16 + V_17 ) ;
}
static int F_8 ( struct V_5 * V_6 , int V_19 ,
unsigned int V_20 , unsigned int V_21 ,
unsigned int V_22 )
{
unsigned int V_23 , V_24 , V_25 ;
int div ;
div = F_9 ( V_6 -> V_4 / 16 , V_19 ) ;
if ( div < 0 || V_26 <= div ) {
F_10 ( V_6 -> V_27 . V_28 , L_1 , div ) ;
return - V_29 ;
}
V_23 = ( unsigned int ) div & 0x00FFU ;
V_24 = ( ( unsigned int ) div >> 8 ) & 0x00FFU ;
if ( V_20 & ~ ( V_30 | V_31 | V_32 ) ) {
F_10 ( V_6 -> V_27 . V_28 , L_2 , V_20 ) ;
return - V_29 ;
}
if ( V_21 & ~ V_33 ) {
F_10 ( V_6 -> V_27 . V_28 , L_3 , V_21 ) ;
return - V_29 ;
}
if ( V_22 & ~ V_34 ) {
F_10 ( V_6 -> V_27 . V_28 , L_4 , V_22 ) ;
return - V_29 ;
}
V_25 = V_20 ;
V_25 |= V_21 ;
V_25 |= V_22 ;
F_11 ( V_6 -> V_27 . V_28 , L_5 ,
V_35 , V_19 , div , V_25 , V_36 ) ;
F_6 ( V_37 , V_6 -> V_16 + V_38 ) ;
F_6 ( V_23 , V_6 -> V_16 + V_39 ) ;
F_6 ( V_24 , V_6 -> V_16 + V_40 ) ;
F_6 ( V_25 , V_6 -> V_16 + V_38 ) ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 ,
unsigned int V_14 )
{
if ( V_14 & ~ ( V_41 | V_42 ) ) {
F_10 ( V_6 -> V_27 . V_28 , L_6 ,
V_35 , V_14 ) ;
return - V_29 ;
}
F_6 ( V_43 | V_6 -> V_8 , V_6 -> V_16 + V_44 ) ;
F_6 ( V_43 | V_6 -> V_8 | V_14 ,
V_6 -> V_16 + V_44 ) ;
F_6 ( V_6 -> V_8 , V_6 -> V_16 + V_44 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 ,
unsigned int V_45 ,
unsigned int V_46 , unsigned int V_47 )
{
T_2 V_8 ;
if ( V_45 & ~ V_48 ) {
F_10 ( V_6 -> V_27 . V_28 , L_7 ,
V_35 , V_45 ) ;
return - V_29 ;
}
if ( V_46 & ~ ( V_43 | V_49 ) ) {
F_10 ( V_6 -> V_27 . V_28 , L_8 ,
V_35 , V_46 ) ;
return - V_29 ;
}
if ( V_47 & ~ V_50 ) {
F_10 ( V_6 -> V_27 . V_28 , L_9 ,
V_35 , V_47 ) ;
return - V_29 ;
}
switch ( V_6 -> V_46 ) {
case 256 :
V_6 -> V_7 =
V_51 [ V_47 >> V_52 ] ;
break;
case 64 :
V_6 -> V_7 =
V_53 [ V_47 >> V_52 ] ;
break;
case 16 :
V_6 -> V_7 =
V_54 [ V_47 >> V_52 ] ;
break;
default:
V_6 -> V_7 =
V_55 [ V_47 >> V_52 ] ;
break;
}
V_8 =
V_45 | V_46 | V_47 | V_42 | V_41 ;
F_6 ( V_43 , V_6 -> V_16 + V_44 ) ;
F_6 ( V_43 | V_42 | V_41 ,
V_6 -> V_16 + V_44 ) ;
F_6 ( V_8 , V_6 -> V_16 + V_44 ) ;
V_6 -> V_8 = V_8 ;
return 0 ;
}
static T_2 F_14 ( struct V_5 * V_6 )
{
V_6 -> V_12 = 0 ;
return F_3 ( V_6 , V_6 -> V_16 ) ;
}
static void F_15 ( struct V_5 * V_6 ,
const unsigned char * V_56 , int V_57 )
{
int V_58 ;
unsigned int V_59 ;
for ( V_58 = 0 ; V_58 < V_57 ; ) {
V_59 = V_56 [ V_58 ++ ] ;
F_6 ( V_59 , V_6 -> V_16 + V_60 ) ;
}
}
static int F_16 ( struct V_5 * V_6 , unsigned char * V_56 ,
int V_61 )
{
int V_58 ;
T_2 V_62 , V_63 ;
V_63 = F_4 ( V_6 -> V_16 + V_64 ) ;
for ( V_58 = 0 , V_63 = F_4 ( V_6 -> V_16 + V_64 ) ;
V_58 < V_61 && V_63 & V_65 ;
V_63 = F_4 ( V_6 -> V_16 + V_64 ) ) {
V_62 = F_4 ( V_6 -> V_16 + V_66 ) ;
V_56 [ V_58 ++ ] = V_62 ;
}
return V_58 ;
}
static unsigned int F_17 ( struct V_5 * V_6 )
{
unsigned int V_67 ;
int V_68 ;
V_67 = F_4 ( V_6 -> V_16 + V_69 ) ;
V_68 = ( V_67 & ( V_70 | V_71 | V_72 ) ) ;
return V_68 ;
}
static T_2 F_18 ( struct V_5 * V_6 )
{
return F_4 ( V_6 -> V_16 + V_64 ) ;
}
static void F_19 ( struct V_5 * V_6 , int V_73 )
{
unsigned int V_25 ;
V_25 = F_4 ( V_6 -> V_16 + V_38 ) ;
if ( V_73 )
V_25 |= V_74 ;
else
V_25 &= ~ V_74 ;
F_6 ( V_25 , V_6 -> V_16 + V_38 ) ;
}
static int F_20 ( struct V_5 * V_6 , const unsigned char * V_56 ,
int V_75 )
{
struct V_76 * V_27 ;
struct V_77 * V_78 ;
V_27 = & V_6 -> V_27 ;
V_78 = F_21 ( & V_27 -> V_79 -> V_27 ) ;
if ( ! V_78 ) {
F_11 ( V_6 -> V_27 . V_28 , L_10 , V_35 ) ;
return - V_80 ;
}
F_22 ( V_78 , V_56 , V_75 ) ;
F_23 ( V_78 ) ;
F_24 ( V_78 ) ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 , unsigned char * V_56 )
{
int V_68 ;
struct V_76 * V_27 = & V_6 -> V_27 ;
if ( V_27 -> V_81 ) {
F_11 ( V_6 -> V_27 . V_28 , L_11 ,
V_35 , V_27 -> V_81 , V_36 ) ;
V_56 [ 0 ] = V_27 -> V_81 ;
V_27 -> V_81 = 0 ;
V_68 = 1 ;
} else {
V_68 = 0 ;
}
return V_68 ;
}
static int F_26 ( struct V_5 * V_6 , int V_75 )
{
struct V_77 * V_78 ;
int V_82 ;
struct V_76 * V_27 = & V_6 -> V_27 ;
V_27 = & V_6 -> V_27 ;
V_78 = F_21 ( & V_27 -> V_79 -> V_27 ) ;
if ( ! V_78 ) {
F_11 ( V_6 -> V_27 . V_28 , L_10 , V_35 ) ;
return 0 ;
}
V_82 = F_27 ( V_78 , V_75 ) ;
if ( V_82 < V_75 )
F_28 ( V_27 -> V_28 , L_12 ,
V_75 - V_82 ) ;
if ( ! V_82 )
return V_82 ;
F_22 ( V_78 , F_29 ( & V_6 -> V_83 ) , V_75 ) ;
V_27 -> V_84 . V_85 += V_82 ;
F_24 ( V_78 ) ;
return V_82 ;
}
static void F_30 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_6 -> V_86 ) {
F_32 ( V_6 -> V_86 ) ;
V_6 -> V_86 = NULL ;
}
if ( V_6 -> V_87 ) {
F_32 ( V_6 -> V_87 ) ;
V_6 -> V_87 = NULL ;
}
if ( F_33 ( & V_6 -> V_83 ) )
F_34 ( V_27 -> V_28 , V_27 -> V_3 ,
F_29 ( & V_6 -> V_83 ) ,
F_33 ( & V_6 -> V_83 ) ) ;
return;
}
static bool F_35 ( struct V_88 * V_89 , void * V_90 )
{
struct V_91 * V_92 = V_90 ;
if ( ( V_89 -> V_93 == V_92 -> V_93 ) && ( V_92 -> V_94 ==
V_89 -> V_95 -> V_28 ) ) {
V_89 -> V_96 = V_92 ;
return true ;
} else {
return false ;
}
}
static void F_36 ( struct V_76 * V_27 )
{
T_3 V_97 ;
struct V_88 * V_89 ;
struct V_1 * V_94 ;
struct V_91 * V_92 ;
struct V_5 * V_6 =
F_31 ( V_27 , struct V_5 , V_27 ) ;
F_37 ( V_97 ) ;
F_38 ( V_98 , V_97 ) ;
V_94 = F_39 ( 2 , F_40 ( 0xa , 0 ) ) ;
V_92 = & V_6 -> V_99 ;
V_92 -> V_94 = & V_94 -> V_28 ;
V_92 -> V_93 = V_6 -> V_27 . line * 2 ;
V_92 -> V_100 = V_27 -> V_101 + V_102 ;
V_89 = F_41 ( V_97 , F_35 , V_92 ) ;
if ( ! V_89 ) {
F_10 ( V_6 -> V_27 . V_28 , L_13 ,
V_35 ) ;
return;
}
V_6 -> V_86 = V_89 ;
V_92 = & V_6 -> V_103 ;
V_92 -> V_94 = & V_94 -> V_28 ;
V_92 -> V_93 = V_6 -> V_27 . line * 2 + 1 ;
V_92 -> V_104 = V_27 -> V_101 + V_105 ;
V_89 = F_41 ( V_97 , F_35 , V_92 ) ;
if ( ! V_89 ) {
F_10 ( V_6 -> V_27 . V_28 , L_14 ,
V_35 ) ;
F_32 ( V_6 -> V_86 ) ;
return;
}
V_6 -> V_106 = F_42 ( V_27 -> V_28 , V_27 -> V_3 ,
& V_6 -> V_107 , V_108 ) ;
V_6 -> V_87 = V_89 ;
}
static void F_43 ( void * V_109 )
{
struct V_5 * V_6 = V_109 ;
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_77 * V_78 = F_21 ( & V_27 -> V_79 -> V_27 ) ;
int V_110 ;
if ( ! V_78 ) {
F_11 ( V_6 -> V_27 . V_28 , L_10 , V_35 ) ;
return;
}
F_44 ( V_27 -> V_28 , & V_6 -> V_83 , 1 , V_111 ) ;
V_110 = F_26 ( V_6 , V_6 -> V_7 ) ;
if ( V_110 )
F_23 ( V_78 ) ;
F_24 ( V_78 ) ;
F_45 ( V_6 -> V_112 ) ;
F_5 ( V_6 , V_113 ) ;
}
static void F_46 ( void * V_109 )
{
struct V_5 * V_6 = V_109 ;
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_114 * V_115 = & V_27 -> V_79 -> V_115 ;
struct V_116 * V_117 = V_6 -> V_118 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_6 -> V_119 ; V_58 ++ , V_117 ++ ) {
V_115 -> V_120 += F_47 ( V_117 ) ;
V_27 -> V_84 . V_121 += F_47 ( V_117 ) ;
}
V_115 -> V_120 &= V_122 - 1 ;
F_45 ( V_6 -> V_123 ) ;
F_48 ( V_27 -> V_28 , V_117 , V_6 -> V_119 , V_124 ) ;
V_6 -> V_125 = 0 ;
V_6 -> V_119 = 0 ;
F_49 ( V_6 -> V_118 ) ;
F_5 ( V_6 , V_126 ) ;
}
static int F_50 ( struct V_5 * V_6 , int V_75 )
{
int V_110 = 0 ;
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_114 * V_115 = & V_27 -> V_79 -> V_115 ;
if ( F_51 ( V_27 ) || F_52 ( V_115 ) || V_110 >= V_75 )
goto V_127;
do {
int V_128 =
F_53 ( V_115 -> V_129 , V_115 -> V_120 , V_122 ) ;
int V_130 = F_54 ( V_75 - V_110 , V_128 ) ;
F_15 ( V_6 , & V_115 -> V_56 [ V_115 -> V_120 ] , V_130 ) ;
V_115 -> V_120 = ( V_115 -> V_120 + V_130 ) & ( V_122 - 1 ) ;
V_110 += V_130 ;
} while ( ! F_52 ( V_115 ) && V_110 < V_75 );
V_127:
F_11 ( V_6 -> V_27 . V_28 , L_15 ,
V_110 , V_75 - V_110 , V_36 ) ;
return V_110 ;
}
static int F_55 ( struct V_5 * V_6 )
{
struct V_131 * V_56 ;
int V_61 ;
int V_68 ;
if ( ! V_6 -> V_132 ) {
F_7 ( V_6 , V_113 ) ;
return 0 ;
}
V_56 = & V_6 -> V_133 ;
do {
V_61 = F_16 ( V_6 , V_56 -> V_56 , V_56 -> V_75 ) ;
V_68 = F_20 ( V_6 , V_56 -> V_56 , V_61 ) ;
if ( V_68 )
return 0 ;
} while ( V_61 == V_56 -> V_75 );
return V_134 ;
}
static int F_56 ( struct V_5 * V_6 )
{
return F_55 ( V_6 ) ;
}
static int F_57 ( struct V_5 * V_6 )
{
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_135 * V_136 ;
struct V_116 * V_117 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_117 = & V_6 -> V_83 ;
F_58 ( & V_6 -> V_83 , 1 ) ;
F_47 ( V_117 ) = V_6 -> V_7 ;
F_59 ( & V_6 -> V_83 , F_60 ( V_6 -> V_106 ) ,
F_47 ( V_117 ) , ( unsigned long ) V_6 -> V_106 &
~ V_137 ) ;
F_33 ( V_117 ) = V_6 -> V_107 ;
V_136 = V_6 -> V_87 -> V_95 -> V_138 ( V_6 -> V_87 ,
V_117 , 1 , V_111 ,
V_139 | V_140 ) ;
if ( ! V_136 )
return 0 ;
V_6 -> V_112 = V_136 ;
V_136 -> V_141 = F_43 ;
V_136 -> V_142 = V_6 ;
V_136 -> V_143 ( V_136 ) ;
F_61 ( V_6 -> V_87 ) ;
return V_134 ;
}
static unsigned int F_62 ( struct V_5 * V_6 )
{
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_114 * V_115 = & V_27 -> V_79 -> V_115 ;
int V_46 ;
int V_57 ;
int V_75 ;
int V_144 ;
if ( ! V_6 -> V_145 ) {
F_63 ( V_6 -> V_27 . V_28 , L_16 ,
V_35 , V_36 ) ;
F_7 ( V_6 , V_126 ) ;
V_6 -> V_144 = 1 ;
return 0 ;
}
V_46 = F_64 ( V_6 -> V_46 , 1 ) ;
V_144 = 1 ;
if ( F_25 ( V_6 , V_115 -> V_56 ) ) {
F_15 ( V_6 , V_115 -> V_56 , 1 ) ;
V_27 -> V_84 . V_121 ++ ;
V_144 = 0 ;
V_46 -- ;
}
V_75 = F_54 ( V_115 -> V_129 - V_115 -> V_120 , V_46 ) ;
if ( V_75 < 0 )
V_75 = V_46 ;
V_57 = F_50 ( V_6 , V_75 ) ;
if ( V_57 > 0 ) {
V_27 -> V_84 . V_121 += V_57 ;
V_144 = 0 ;
}
V_6 -> V_144 = V_144 ;
if ( V_144 ) {
F_7 ( V_6 , V_126 ) ;
F_65 ( V_27 ) ;
}
return V_146 ;
}
static unsigned int F_66 ( struct V_5 * V_6 )
{
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_114 * V_115 = & V_27 -> V_79 -> V_115 ;
struct V_116 * V_117 ;
int V_119 ;
int V_46 ;
int V_144 ;
struct V_135 * V_136 ;
int V_147 ;
int V_58 ;
int V_148 ;
int V_75 ;
int V_149 ;
if ( ! V_6 -> V_145 ) {
F_63 ( V_6 -> V_27 . V_28 , L_16 ,
V_35 , V_36 ) ;
F_7 ( V_6 , V_126 ) ;
V_6 -> V_144 = 1 ;
return 0 ;
}
if ( V_6 -> V_125 ) {
F_11 ( V_6 -> V_27 . V_28 , L_17 ,
V_35 , V_36 ) ;
F_7 ( V_6 , V_126 ) ;
V_6 -> V_144 = 1 ;
return 0 ;
}
V_46 = F_64 ( V_6 -> V_46 , 1 ) ;
V_144 = 1 ;
if ( F_25 ( V_6 , V_115 -> V_56 ) ) {
F_15 ( V_6 , V_115 -> V_56 , 1 ) ;
V_27 -> V_84 . V_121 ++ ;
V_144 = 0 ;
V_46 -- ;
}
V_148 = F_54 ( ( int ) F_67 ( V_115 -> V_129 , V_115 -> V_120 ,
V_122 ) , F_53 ( V_115 -> V_129 ,
V_115 -> V_120 , V_122 ) ) ;
if ( ! V_148 ) {
F_11 ( V_6 -> V_27 . V_28 , L_18 , V_35 ) ;
F_7 ( V_6 , V_126 ) ;
F_65 ( V_27 ) ;
return 0 ;
}
if ( V_148 > V_46 ) {
V_147 = V_148 / V_46 + 1 ;
V_75 = V_46 ;
V_149 = V_148 % V_46 ;
} else {
V_147 = 1 ;
V_75 = V_148 ;
V_149 = V_148 ;
}
F_11 ( V_6 -> V_27 . V_28 , L_19 ,
V_35 , V_147 , V_75 , V_149 ) ;
V_6 -> V_125 = 1 ;
V_6 -> V_118 = F_68 ( sizeof( struct V_116 ) * V_147 , V_150 ) ;
F_58 ( V_6 -> V_118 , V_147 ) ;
V_117 = V_6 -> V_118 ;
for ( V_58 = 0 ; V_58 < V_147 ; V_58 ++ , V_117 ++ ) {
if ( V_58 == ( V_147 - 1 ) )
F_59 ( V_117 , F_60 ( V_115 -> V_56 ) ,
V_149 , V_46 * V_58 ) ;
else
F_59 ( V_117 , F_60 ( V_115 -> V_56 ) ,
V_75 , V_46 * V_58 ) ;
}
V_117 = V_6 -> V_118 ;
V_119 = F_69 ( V_27 -> V_28 , V_117 , V_147 , V_124 ) ;
if ( ! V_119 ) {
F_10 ( V_6 -> V_27 . V_28 , L_20 , V_35 ) ;
return 0 ;
}
V_6 -> V_119 = V_119 ;
for ( V_58 = 0 ; V_58 < V_119 ; V_58 ++ , V_117 ++ ) {
V_117 -> V_151 = ( V_115 -> V_120 & ( V_122 - 1 ) ) +
V_46 * V_58 ;
F_33 ( V_117 ) = ( F_33 ( V_117 ) &
~ ( V_122 - 1 ) ) + V_117 -> V_151 ;
if ( V_58 == ( V_119 - 1 ) )
F_47 ( V_117 ) = V_149 ;
else
F_47 ( V_117 ) = V_75 ;
}
V_136 = V_6 -> V_86 -> V_95 -> V_138 ( V_6 -> V_86 ,
V_6 -> V_118 , V_119 , V_124 ,
V_139 | V_140 ) ;
if ( ! V_136 ) {
F_10 ( V_6 -> V_27 . V_28 , L_21 ,
V_35 ) ;
return 0 ;
}
F_70 ( V_27 -> V_28 , V_6 -> V_118 , V_119 , V_124 ) ;
V_6 -> V_123 = V_136 ;
V_136 -> V_141 = F_46 ;
V_136 -> V_142 = V_6 ;
V_136 -> V_143 ( V_136 ) ;
F_61 ( V_6 -> V_86 ) ;
return V_146 ;
}
static void F_71 ( struct V_5 * V_6 , unsigned int V_63 )
{
T_2 V_8 = F_4 ( V_6 -> V_16 + V_44 ) ;
V_8 |= V_152 ;
F_6 ( V_8 , V_6 -> V_16 + V_44 ) ;
if ( V_63 & V_153 )
F_10 ( & V_6 -> V_2 -> V_28 , L_22 ) ;
if ( V_63 & V_154 )
F_10 ( & V_6 -> V_2 -> V_28 , L_23 ) ;
if ( V_63 & V_155 )
F_10 ( & V_6 -> V_2 -> V_28 , L_24 ) ;
if ( V_63 & V_156 )
F_10 ( & V_6 -> V_2 -> V_28 , L_25 ) ;
}
static T_4 F_72 ( int V_157 , void * V_158 )
{
struct V_5 * V_6 = V_158 ;
unsigned int V_159 ;
T_2 V_63 ;
int V_68 = 0 ;
unsigned int V_160 ;
unsigned long V_161 ;
F_73 ( & V_6 -> V_27 . V_162 , V_161 ) ;
V_159 = 0 ;
while ( ( V_160 = F_17 ( V_6 ) ) > 1 ) {
switch ( V_160 ) {
case V_163 :
V_63 = F_18 ( V_6 ) ;
if ( V_63 & ( V_153 | V_154 |
V_155 | V_156 ) ) {
F_71 ( V_6 , V_63 ) ;
V_68 = V_164 ;
}
break;
case V_165 :
if ( V_6 -> V_166 ) {
F_7 ( V_6 ,
V_113 ) ;
V_68 = F_57 ( V_6 ) ;
if ( ! V_68 )
F_5 ( V_6 ,
V_113 ) ;
} else {
V_68 = F_56 ( V_6 ) ;
}
break;
case V_167 :
V_68 = F_55 ( V_6 ) ;
break;
case V_168 :
if ( V_6 -> V_166 )
V_68 = F_66 ( V_6 ) ;
else
V_68 = F_62 ( V_6 ) ;
break;
case V_169 :
V_68 = V_170 ;
break;
default:
F_10 ( V_6 -> V_27 . V_28 , L_26 , V_35 ,
V_160 , V_36 ) ;
V_68 = - 1 ;
break;
}
V_159 |= ( unsigned int ) V_68 ;
}
if ( V_159 == 0 && V_160 <= 1 ) {
if ( V_6 -> V_171 )
V_6 -> V_171 = 0 ;
}
F_74 ( & V_6 -> V_27 . V_162 , V_161 ) ;
return F_75 ( V_159 ) ;
}
static unsigned int F_76 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
int V_68 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_6 -> V_144 )
V_68 = V_172 ;
else
V_68 = 0 ;
return V_68 ;
}
static unsigned int F_77 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
T_2 V_173 ;
unsigned int V_68 = 0 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_173 = F_14 ( V_6 ) ;
if ( V_173 & V_174 )
V_68 |= V_175 ;
if ( V_173 & V_176 )
V_68 |= V_177 ;
if ( V_173 & V_178 )
V_68 |= V_179 ;
if ( V_173 & V_180 )
V_68 |= V_181 ;
return V_68 ;
}
static void F_78 ( struct V_76 * V_27 , unsigned int V_182 )
{
T_5 V_183 = 0 ;
struct V_5 * V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_182 & V_184 )
V_183 |= V_185 ;
if ( V_182 & V_186 )
V_183 |= V_187 ;
if ( V_182 & V_188 )
V_183 |= V_189 ;
if ( V_6 -> V_183 & V_190 )
V_183 |= V_190 ;
if ( V_182 )
F_6 ( V_183 , V_6 -> V_16 + V_191 ) ;
}
static void F_79 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_6 -> V_145 = 0 ;
V_6 -> V_125 = 0 ;
}
static void F_80 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_6 -> V_166 ) {
if ( V_6 -> V_125 ) {
F_11 ( V_6 -> V_27 . V_28 , L_27 ,
V_35 ) ;
return;
}
}
V_6 -> V_145 = 1 ;
F_5 ( V_6 , V_126 ) ;
}
static void F_81 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_6 -> V_132 = 0 ;
F_7 ( V_6 , V_113 ) ;
V_6 -> V_171 = 1 ;
}
static void F_82 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
F_5 ( V_6 , V_192 ) ;
}
static void F_83 ( struct V_76 * V_27 , int V_193 )
{
struct V_5 * V_6 ;
unsigned long V_161 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
F_73 ( & V_27 -> V_162 , V_161 ) ;
F_19 ( V_6 , V_193 ) ;
F_74 ( & V_27 -> V_162 , V_161 ) ;
}
static int F_84 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
int V_68 ;
int V_46 ;
int V_7 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_6 -> V_144 = 1 ;
if ( V_27 -> V_194 )
V_6 -> V_4 = V_27 -> V_194 ;
else
V_27 -> V_194 = V_6 -> V_4 ;
F_7 ( V_6 , V_195 ) ;
V_68 = F_8 ( V_6 , V_196 ,
V_197 , V_198 ,
V_199 ) ;
if ( V_68 )
return V_68 ;
switch ( V_6 -> V_46 ) {
case 256 :
V_46 = V_200 ;
break;
case 64 :
V_46 = V_201 ;
break;
case 16 :
V_46 = V_202 ;
case 1 :
default:
V_46 = V_203 ;
break;
}
switch ( V_6 -> V_47 ) {
case V_204 :
V_7 = 1 ;
break;
case V_205 :
V_7 = V_6 -> V_46 / 4 ;
break;
case V_206 :
V_7 = V_6 -> V_46 / 2 ;
break;
case V_207 :
default:
V_7 = V_6 -> V_46 - ( V_6 -> V_46 / 8 ) ;
break;
}
V_6 -> V_7 = V_7 ;
V_68 = F_13 ( V_6 , V_208 ,
V_46 , V_6 -> V_47 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_85 ( V_6 -> V_27 . V_157 , F_72 , V_209 ,
V_210 , V_6 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_6 -> V_166 )
F_36 ( V_27 ) ;
V_6 -> V_132 = 1 ;
F_5 ( V_6 , V_113 ) ;
F_86 ( V_27 , V_211 , V_196 ) ;
return 0 ;
}
static void F_87 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
int V_68 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
F_7 ( V_6 , V_195 ) ;
F_12 ( V_6 , V_212 ) ;
V_68 = F_13 ( V_6 , V_208 ,
V_203 , V_204 ) ;
if ( V_68 )
F_10 ( V_6 -> V_27 . V_28 ,
L_28 , V_68 ) ;
if ( V_6 -> V_213 )
F_30 ( V_27 ) ;
F_88 ( V_6 -> V_27 . V_157 , V_6 ) ;
}
static void F_89 ( struct V_76 * V_27 ,
struct V_214 * V_215 , struct V_214 * V_216 )
{
int V_19 ;
int V_217 ;
unsigned int V_20 , V_21 , V_22 ;
struct V_5 * V_6 ;
unsigned long V_161 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
switch ( V_215 -> V_218 & V_219 ) {
case V_220 :
V_21 = V_221 ;
break;
case V_222 :
V_21 = V_223 ;
break;
case V_224 :
V_21 = V_225 ;
break;
default:
V_21 = V_198 ;
break;
}
if ( V_215 -> V_218 & V_226 )
V_22 = V_227 ;
else
V_22 = V_199 ;
if ( V_215 -> V_218 & V_228 ) {
if ( ! ( V_215 -> V_218 & V_229 ) )
V_20 = V_230 ;
else
V_20 = V_231 ;
} else {
V_20 = V_197 ;
}
if ( ( V_215 -> V_218 & V_232 ) && ( V_6 -> V_46 == 256 ) )
V_6 -> V_183 |= V_190 ;
else
V_6 -> V_183 &= ~ V_190 ;
V_215 -> V_218 &= ~ V_233 ;
V_19 = F_90 ( V_27 , V_215 , V_216 , 0 , V_27 -> V_194 / 16 ) ;
F_73 ( & V_27 -> V_162 , V_161 ) ;
F_86 ( V_27 , V_215 -> V_218 , V_19 ) ;
V_217 = F_8 ( V_6 , V_19 , V_20 , V_21 , V_22 ) ;
if ( V_217 )
goto V_234;
if ( F_91 ( V_215 ) )
F_92 ( V_215 , V_19 , V_19 ) ;
V_234:
F_74 ( & V_27 -> V_162 , V_161 ) ;
}
static const char * F_93 ( struct V_76 * V_27 )
{
return V_210 ;
}
static void F_94 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
F_95 ( V_6 -> V_2 , V_6 -> V_16 ) ;
F_96 ( V_6 -> V_2 ) ;
}
static int F_97 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
int V_68 ;
void T_1 * V_16 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_68 = F_98 ( V_6 -> V_2 , V_210 ) ;
if ( V_68 < 0 )
return - V_80 ;
V_16 = F_99 ( V_6 -> V_2 , 1 , 0 ) ;
if ( ! V_16 ) {
F_96 ( V_6 -> V_2 ) ;
return - V_80 ;
}
V_6 -> V_16 = V_27 -> V_16 = V_16 ;
return 0 ;
}
static void F_100 ( struct V_76 * V_27 , int type )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( type & V_235 ) {
V_27 -> type = V_6 -> V_236 ;
F_97 ( V_27 ) ;
}
}
static int F_101 ( struct V_76 * V_27 ,
struct V_237 * V_238 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_238 -> V_161 & V_239 ) {
F_63 ( V_6 -> V_27 . V_28 ,
L_29 ) ;
V_6 -> V_166 = 0 ;
V_238 -> V_161 &= ~ V_239 ;
} else {
#ifndef F_102
F_10 ( V_6 -> V_27 . V_28 , L_30 ,
V_35 ) ;
return - V_240 ;
#endif
V_6 -> V_166 = 1 ;
V_6 -> V_213 = 1 ;
F_63 ( V_6 -> V_27 . V_28 , L_31 ) ;
}
return 0 ;
}
static struct V_5 * F_103 ( struct V_1 * V_2 ,
const struct V_241 * V_242 )
{
struct V_5 * V_6 ;
int V_68 ;
unsigned int V_243 ;
unsigned int V_101 ;
unsigned char * V_133 ;
int V_3 , V_4 ;
int V_236 ;
struct V_244 * V_245 ;
const char * V_246 ;
V_245 = & V_247 [ V_242 -> V_248 ] ;
V_236 = V_245 -> V_236 ;
V_6 = F_68 ( sizeof( struct V_5 ) , V_108 ) ;
if ( V_6 == NULL )
goto V_249;
V_133 = ( unsigned char * ) F_104 ( V_108 ) ;
if ( ! V_133 )
goto V_250;
V_4 = 1843200 ;
V_246 = F_105 ( V_251 ) ;
if ( V_246 && strstr ( V_246 , L_32 ) )
V_4 = 192000000 ;
switch ( V_236 ) {
case V_252 :
V_3 = 256 ;
break;
case V_253 :
V_3 = 64 ;
break;
default:
F_10 ( & V_2 -> V_28 , L_33 , V_236 ) ;
goto V_254;
}
V_243 = F_106 ( V_2 , 0 ) ;
V_101 = F_106 ( V_2 , 1 ) ;
V_6 -> V_101 = V_101 ;
V_6 -> V_243 = V_243 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_144 = 1 ;
V_6 -> V_133 . V_56 = V_133 ;
V_6 -> V_133 . V_75 = V_255 ;
V_6 -> V_46 = V_3 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_236 = V_256 + V_236 + 1 ;
V_6 -> V_27 . V_28 = & V_2 -> V_28 ;
V_6 -> V_27 . V_243 = V_243 ;
V_6 -> V_27 . V_16 = NULL ;
V_6 -> V_27 . V_101 = V_101 ;
V_6 -> V_27 . V_157 = V_2 -> V_157 ;
V_6 -> V_27 . V_257 = V_258 ;
V_6 -> V_27 . V_259 = & V_260 ;
V_6 -> V_27 . V_161 = V_261 ;
V_6 -> V_27 . V_3 = V_3 ;
V_6 -> V_27 . line = V_245 -> V_262 ;
V_6 -> V_47 = V_206 ;
F_107 ( & V_6 -> V_27 . V_162 ) ;
F_108 ( V_2 , V_6 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_68 = F_109 ( & V_263 , & V_6 -> V_27 ) ;
if ( V_68 < 0 )
goto V_254;
return V_6 ;
V_254:
F_110 ( ( unsigned long ) V_133 ) ;
V_250:
F_49 ( V_6 ) ;
V_249:
return NULL ;
}
static void F_111 ( struct V_5 * V_6 )
{
F_112 ( & V_263 , & V_6 -> V_27 ) ;
F_108 ( V_6 -> V_2 , NULL ) ;
F_110 ( ( unsigned long ) V_6 -> V_133 . V_56 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) F_2 ( V_2 ) ;
F_111 ( V_6 ) ;
F_114 ( V_2 ) ;
F_49 ( V_6 ) ;
return;
}
static int F_115 ( struct V_1 * V_2 , T_6 V_79 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_116 ( & V_263 , & V_6 -> V_27 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 , F_119 ( V_2 , V_79 ) ) ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_68 ;
F_118 ( V_2 , V_264 ) ;
F_121 ( V_2 ) ;
V_68 = F_122 ( V_2 ) ;
if ( V_68 ) {
F_10 ( & V_2 -> V_28 ,
L_34 , V_35 , V_68 ) ;
return V_68 ;
}
F_123 ( & V_263 , & V_6 -> V_27 ) ;
return 0 ;
}
static int T_7 F_124 ( struct V_1 * V_2 ,
const struct V_241 * V_242 )
{
int V_68 ;
struct V_5 * V_6 ;
V_68 = F_122 ( V_2 ) ;
if ( V_68 < 0 )
goto V_265;
V_6 = F_103 ( V_2 , V_242 ) ;
if ( ! V_6 ) {
V_68 = - V_80 ;
goto V_266;
}
F_108 ( V_2 , V_6 ) ;
return V_68 ;
V_266:
F_114 ( V_2 ) ;
V_265:
return V_68 ;
}
static int T_8 F_125 ( void )
{
int V_68 ;
V_68 = F_126 ( & V_263 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_127 ( & V_267 ) ;
if ( V_68 < 0 )
F_128 ( & V_263 ) ;
return V_68 ;
}
static void T_9 F_129 ( void )
{
F_130 ( & V_267 ) ;
F_128 ( & V_263 ) ;
}
