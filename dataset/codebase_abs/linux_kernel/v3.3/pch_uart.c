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
V_94 = F_39 ( V_6 -> V_2 -> V_99 -> V_100 ,
F_40 ( 0xa , 0 ) ) ;
V_92 = & V_6 -> V_101 ;
V_92 -> V_94 = & V_94 -> V_28 ;
V_92 -> V_93 = V_6 -> V_27 . line * 2 ;
V_92 -> V_102 = V_27 -> V_103 + V_104 ;
V_89 = F_41 ( V_97 , F_35 , V_92 ) ;
if ( ! V_89 ) {
F_10 ( V_6 -> V_27 . V_28 , L_13 ,
V_35 ) ;
return;
}
V_6 -> V_86 = V_89 ;
V_92 = & V_6 -> V_105 ;
V_92 -> V_94 = & V_94 -> V_28 ;
V_92 -> V_93 = V_6 -> V_27 . line * 2 + 1 ;
V_92 -> V_106 = V_27 -> V_103 + V_107 ;
V_89 = F_41 ( V_97 , F_35 , V_92 ) ;
if ( ! V_89 ) {
F_10 ( V_6 -> V_27 . V_28 , L_14 ,
V_35 ) ;
F_32 ( V_6 -> V_86 ) ;
V_6 -> V_86 = NULL ;
return;
}
V_6 -> V_108 = F_42 ( V_27 -> V_28 , V_27 -> V_3 ,
& V_6 -> V_109 , V_110 ) ;
V_6 -> V_87 = V_89 ;
}
static void F_43 ( void * V_111 )
{
struct V_5 * V_6 = V_111 ;
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_77 * V_78 = F_21 ( & V_27 -> V_79 -> V_27 ) ;
int V_112 ;
if ( ! V_78 ) {
F_11 ( V_6 -> V_27 . V_28 , L_10 , V_35 ) ;
return;
}
F_44 ( V_27 -> V_28 , & V_6 -> V_83 , 1 , V_113 ) ;
V_112 = F_26 ( V_6 , V_6 -> V_7 ) ;
if ( V_112 )
F_23 ( V_78 ) ;
F_24 ( V_78 ) ;
F_45 ( V_6 -> V_114 ) ;
F_5 ( V_6 , V_115 ) ;
}
static void F_46 ( void * V_111 )
{
struct V_5 * V_6 = V_111 ;
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_116 * V_117 = & V_27 -> V_79 -> V_117 ;
struct V_118 * V_119 = V_6 -> V_120 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_6 -> V_121 ; V_58 ++ , V_119 ++ ) {
V_117 -> V_122 += F_47 ( V_119 ) ;
V_27 -> V_84 . V_123 += F_47 ( V_119 ) ;
}
V_117 -> V_122 &= V_124 - 1 ;
F_45 ( V_6 -> V_125 ) ;
F_48 ( V_27 -> V_28 , V_119 , V_6 -> V_121 , V_126 ) ;
V_6 -> V_127 = 0 ;
V_6 -> V_121 = 0 ;
F_49 ( V_6 -> V_120 ) ;
F_5 ( V_6 , V_128 ) ;
}
static int F_50 ( struct V_5 * V_6 , int V_75 )
{
int V_112 = 0 ;
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_116 * V_117 = & V_27 -> V_79 -> V_117 ;
if ( F_51 ( V_27 ) || F_52 ( V_117 ) || V_112 >= V_75 )
goto V_129;
do {
int V_130 =
F_53 ( V_117 -> V_131 , V_117 -> V_122 , V_124 ) ;
int V_132 = F_54 ( V_75 - V_112 , V_130 ) ;
F_15 ( V_6 , & V_117 -> V_56 [ V_117 -> V_122 ] , V_132 ) ;
V_117 -> V_122 = ( V_117 -> V_122 + V_132 ) & ( V_124 - 1 ) ;
V_112 += V_132 ;
} while ( ! F_52 ( V_117 ) && V_112 < V_75 );
V_129:
F_11 ( V_6 -> V_27 . V_28 , L_15 ,
V_112 , V_75 - V_112 , V_36 ) ;
return V_112 ;
}
static int F_55 ( struct V_5 * V_6 )
{
struct V_133 * V_56 ;
int V_61 ;
int V_68 ;
if ( ! V_6 -> V_134 ) {
F_7 ( V_6 , V_115 ) ;
return 0 ;
}
V_56 = & V_6 -> V_135 ;
do {
V_61 = F_16 ( V_6 , V_56 -> V_56 , V_56 -> V_75 ) ;
V_68 = F_20 ( V_6 , V_56 -> V_56 , V_61 ) ;
if ( V_68 )
return 0 ;
} while ( V_61 == V_56 -> V_75 );
return V_136 ;
}
static int F_56 ( struct V_5 * V_6 )
{
return F_55 ( V_6 ) ;
}
static int F_57 ( struct V_5 * V_6 )
{
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_137 * V_138 ;
struct V_118 * V_119 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_119 = & V_6 -> V_83 ;
F_58 ( & V_6 -> V_83 , 1 ) ;
F_47 ( V_119 ) = V_6 -> V_7 ;
F_59 ( & V_6 -> V_83 , F_60 ( V_6 -> V_108 ) ,
F_47 ( V_119 ) , ( unsigned long ) V_6 -> V_108 &
~ V_139 ) ;
F_33 ( V_119 ) = V_6 -> V_109 ;
V_138 = V_6 -> V_87 -> V_95 -> V_140 ( V_6 -> V_87 ,
V_119 , 1 , V_141 ,
V_142 | V_143 ) ;
if ( ! V_138 )
return 0 ;
V_6 -> V_114 = V_138 ;
V_138 -> V_144 = F_43 ;
V_138 -> V_145 = V_6 ;
V_138 -> V_146 ( V_138 ) ;
F_61 ( V_6 -> V_87 ) ;
return V_136 ;
}
static unsigned int F_62 ( struct V_5 * V_6 )
{
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_116 * V_117 = & V_27 -> V_79 -> V_117 ;
int V_46 ;
int V_57 ;
int V_75 ;
int V_147 ;
if ( ! V_6 -> V_148 ) {
F_63 ( V_6 -> V_27 . V_28 , L_16 ,
V_35 , V_36 ) ;
F_7 ( V_6 , V_128 ) ;
V_6 -> V_147 = 1 ;
return 0 ;
}
V_46 = F_64 ( V_6 -> V_46 , 1 ) ;
V_147 = 1 ;
if ( F_25 ( V_6 , V_117 -> V_56 ) ) {
F_15 ( V_6 , V_117 -> V_56 , 1 ) ;
V_27 -> V_84 . V_123 ++ ;
V_147 = 0 ;
V_46 -- ;
}
V_75 = F_54 ( V_117 -> V_131 - V_117 -> V_122 , V_46 ) ;
if ( V_75 < 0 )
V_75 = V_46 ;
V_57 = F_50 ( V_6 , V_75 ) ;
if ( V_57 > 0 ) {
V_27 -> V_84 . V_123 += V_57 ;
V_147 = 0 ;
}
V_6 -> V_147 = V_147 ;
if ( V_147 ) {
F_7 ( V_6 , V_128 ) ;
F_65 ( V_27 ) ;
}
return V_149 ;
}
static unsigned int F_66 ( struct V_5 * V_6 )
{
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_116 * V_117 = & V_27 -> V_79 -> V_117 ;
struct V_118 * V_119 ;
int V_121 ;
int V_46 ;
int V_147 ;
struct V_137 * V_138 ;
int V_150 ;
int V_58 ;
int V_151 ;
int V_75 ;
int V_152 ;
if ( ! V_6 -> V_148 ) {
F_63 ( V_6 -> V_27 . V_28 , L_16 ,
V_35 , V_36 ) ;
F_7 ( V_6 , V_128 ) ;
V_6 -> V_147 = 1 ;
return 0 ;
}
if ( V_6 -> V_127 ) {
F_11 ( V_6 -> V_27 . V_28 , L_17 ,
V_35 , V_36 ) ;
F_7 ( V_6 , V_128 ) ;
V_6 -> V_147 = 1 ;
return 0 ;
}
V_46 = F_64 ( V_6 -> V_46 , 1 ) ;
V_147 = 1 ;
if ( F_25 ( V_6 , V_117 -> V_56 ) ) {
F_15 ( V_6 , V_117 -> V_56 , 1 ) ;
V_27 -> V_84 . V_123 ++ ;
V_147 = 0 ;
V_46 -- ;
}
V_151 = F_54 ( ( int ) F_67 ( V_117 -> V_131 , V_117 -> V_122 ,
V_124 ) , F_53 ( V_117 -> V_131 ,
V_117 -> V_122 , V_124 ) ) ;
if ( ! V_151 ) {
F_11 ( V_6 -> V_27 . V_28 , L_18 , V_35 ) ;
F_7 ( V_6 , V_128 ) ;
F_65 ( V_27 ) ;
return 0 ;
}
if ( V_151 > V_46 ) {
V_150 = V_151 / V_46 + 1 ;
V_75 = V_46 ;
V_152 = V_151 % V_46 ;
} else {
V_150 = 1 ;
V_75 = V_151 ;
V_152 = V_151 ;
}
F_11 ( V_6 -> V_27 . V_28 , L_19 ,
V_35 , V_150 , V_75 , V_152 ) ;
V_6 -> V_127 = 1 ;
V_6 -> V_120 = F_68 ( sizeof( struct V_118 ) * V_150 , V_153 ) ;
F_58 ( V_6 -> V_120 , V_150 ) ;
V_119 = V_6 -> V_120 ;
for ( V_58 = 0 ; V_58 < V_150 ; V_58 ++ , V_119 ++ ) {
if ( V_58 == ( V_150 - 1 ) )
F_59 ( V_119 , F_60 ( V_117 -> V_56 ) ,
V_152 , V_46 * V_58 ) ;
else
F_59 ( V_119 , F_60 ( V_117 -> V_56 ) ,
V_75 , V_46 * V_58 ) ;
}
V_119 = V_6 -> V_120 ;
V_121 = F_69 ( V_27 -> V_28 , V_119 , V_150 , V_126 ) ;
if ( ! V_121 ) {
F_10 ( V_6 -> V_27 . V_28 , L_20 , V_35 ) ;
return 0 ;
}
V_6 -> V_121 = V_121 ;
for ( V_58 = 0 ; V_58 < V_121 ; V_58 ++ , V_119 ++ ) {
V_119 -> V_154 = ( V_117 -> V_122 & ( V_124 - 1 ) ) +
V_46 * V_58 ;
F_33 ( V_119 ) = ( F_33 ( V_119 ) &
~ ( V_124 - 1 ) ) + V_119 -> V_154 ;
if ( V_58 == ( V_121 - 1 ) )
F_47 ( V_119 ) = V_152 ;
else
F_47 ( V_119 ) = V_75 ;
}
V_138 = V_6 -> V_86 -> V_95 -> V_140 ( V_6 -> V_86 ,
V_6 -> V_120 , V_121 , V_155 ,
V_142 | V_143 ) ;
if ( ! V_138 ) {
F_10 ( V_6 -> V_27 . V_28 , L_21 ,
V_35 ) ;
return 0 ;
}
F_70 ( V_27 -> V_28 , V_6 -> V_120 , V_121 , V_126 ) ;
V_6 -> V_125 = V_138 ;
V_138 -> V_144 = F_46 ;
V_138 -> V_145 = V_6 ;
V_138 -> V_146 ( V_138 ) ;
F_61 ( V_6 -> V_86 ) ;
return V_149 ;
}
static void F_71 ( struct V_5 * V_6 , unsigned int V_63 )
{
T_2 V_8 = F_4 ( V_6 -> V_16 + V_44 ) ;
V_8 |= V_156 ;
F_6 ( V_8 , V_6 -> V_16 + V_44 ) ;
if ( V_63 & V_157 )
F_10 ( & V_6 -> V_2 -> V_28 , L_22 ) ;
if ( V_63 & V_158 )
F_10 ( & V_6 -> V_2 -> V_28 , L_23 ) ;
if ( V_63 & V_159 )
F_10 ( & V_6 -> V_2 -> V_28 , L_24 ) ;
if ( V_63 & V_160 )
F_10 ( & V_6 -> V_2 -> V_28 , L_25 ) ;
}
static T_4 F_72 ( int V_161 , void * V_162 )
{
struct V_5 * V_6 = V_162 ;
unsigned int V_163 ;
T_2 V_63 ;
int V_68 = 0 ;
unsigned int V_164 ;
unsigned long V_165 ;
F_73 ( & V_6 -> V_27 . V_166 , V_165 ) ;
V_163 = 0 ;
while ( ( V_164 = F_17 ( V_6 ) ) > 1 ) {
switch ( V_164 ) {
case V_167 :
V_63 = F_18 ( V_6 ) ;
if ( V_63 & ( V_157 | V_158 |
V_159 | V_160 ) ) {
F_71 ( V_6 , V_63 ) ;
V_68 = V_168 ;
}
break;
case V_169 :
if ( V_6 -> V_170 ) {
F_7 ( V_6 ,
V_115 ) ;
V_68 = F_57 ( V_6 ) ;
if ( ! V_68 )
F_5 ( V_6 ,
V_115 ) ;
} else {
V_68 = F_56 ( V_6 ) ;
}
break;
case V_171 :
V_68 = F_55 ( V_6 ) ;
break;
case V_172 :
if ( V_6 -> V_170 )
V_68 = F_66 ( V_6 ) ;
else
V_68 = F_62 ( V_6 ) ;
break;
case V_173 :
V_68 = V_174 ;
break;
default:
F_10 ( V_6 -> V_27 . V_28 , L_26 , V_35 ,
V_164 , V_36 ) ;
V_68 = - 1 ;
break;
}
V_163 |= ( unsigned int ) V_68 ;
}
if ( V_163 == 0 && V_164 <= 1 ) {
if ( V_6 -> V_175 )
V_6 -> V_175 = 0 ;
}
F_74 ( & V_6 -> V_27 . V_166 , V_165 ) ;
return F_75 ( V_163 ) ;
}
static unsigned int F_76 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
int V_68 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_6 -> V_147 )
V_68 = V_176 ;
else
V_68 = 0 ;
return V_68 ;
}
static unsigned int F_77 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
T_2 V_177 ;
unsigned int V_68 = 0 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_177 = F_14 ( V_6 ) ;
if ( V_177 & V_178 )
V_68 |= V_179 ;
if ( V_177 & V_180 )
V_68 |= V_181 ;
if ( V_177 & V_182 )
V_68 |= V_183 ;
if ( V_177 & V_184 )
V_68 |= V_185 ;
return V_68 ;
}
static void F_78 ( struct V_76 * V_27 , unsigned int V_186 )
{
T_5 V_187 = 0 ;
struct V_5 * V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_186 & V_188 )
V_187 |= V_189 ;
if ( V_186 & V_190 )
V_187 |= V_191 ;
if ( V_186 & V_192 )
V_187 |= V_193 ;
if ( V_6 -> V_187 & V_194 )
V_187 |= V_194 ;
if ( V_186 )
F_6 ( V_187 , V_6 -> V_16 + V_195 ) ;
}
static void F_79 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_6 -> V_148 = 0 ;
V_6 -> V_127 = 0 ;
}
static void F_80 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_6 -> V_170 ) {
if ( V_6 -> V_127 ) {
F_11 ( V_6 -> V_27 . V_28 , L_27 ,
V_35 ) ;
return;
}
}
V_6 -> V_148 = 1 ;
F_5 ( V_6 , V_128 ) ;
}
static void F_81 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_6 -> V_134 = 0 ;
F_7 ( V_6 , V_115 ) ;
V_6 -> V_175 = 1 ;
}
static void F_82 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
F_5 ( V_6 , V_196 ) ;
}
static void F_83 ( struct V_76 * V_27 , int V_197 )
{
struct V_5 * V_6 ;
unsigned long V_165 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
F_73 ( & V_27 -> V_166 , V_165 ) ;
F_19 ( V_6 , V_197 ) ;
F_74 ( & V_27 -> V_166 , V_165 ) ;
}
static int F_84 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
int V_68 ;
int V_46 ;
int V_7 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_6 -> V_147 = 1 ;
if ( V_27 -> V_198 )
V_6 -> V_4 = V_27 -> V_198 ;
else
V_27 -> V_198 = V_6 -> V_4 ;
F_7 ( V_6 , V_199 ) ;
V_68 = F_8 ( V_6 , V_200 ,
V_201 , V_202 ,
V_203 ) ;
if ( V_68 )
return V_68 ;
switch ( V_6 -> V_46 ) {
case 256 :
V_46 = V_204 ;
break;
case 64 :
V_46 = V_205 ;
break;
case 16 :
V_46 = V_206 ;
case 1 :
default:
V_46 = V_207 ;
break;
}
switch ( V_6 -> V_47 ) {
case V_208 :
V_7 = 1 ;
break;
case V_209 :
V_7 = V_6 -> V_46 / 4 ;
break;
case V_210 :
V_7 = V_6 -> V_46 / 2 ;
break;
case V_211 :
default:
V_7 = V_6 -> V_46 - ( V_6 -> V_46 / 8 ) ;
break;
}
V_6 -> V_7 = V_7 ;
V_68 = F_13 ( V_6 , V_212 ,
V_46 , V_6 -> V_47 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_85 ( V_6 -> V_27 . V_161 , F_72 , V_213 ,
V_214 , V_6 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_6 -> V_170 )
F_36 ( V_27 ) ;
V_6 -> V_134 = 1 ;
F_5 ( V_6 , V_115 ) ;
F_86 ( V_27 , V_215 , V_200 ) ;
return 0 ;
}
static void F_87 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
int V_68 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
F_7 ( V_6 , V_199 ) ;
F_12 ( V_6 , V_216 ) ;
V_68 = F_13 ( V_6 , V_212 ,
V_207 , V_208 ) ;
if ( V_68 )
F_10 ( V_6 -> V_27 . V_28 ,
L_28 , V_68 ) ;
F_30 ( V_27 ) ;
F_88 ( V_6 -> V_27 . V_161 , V_6 ) ;
}
static void F_89 ( struct V_76 * V_27 ,
struct V_217 * V_218 , struct V_217 * V_219 )
{
int V_19 ;
int V_220 ;
unsigned int V_20 , V_21 , V_22 ;
struct V_5 * V_6 ;
unsigned long V_165 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
switch ( V_218 -> V_221 & V_222 ) {
case V_223 :
V_21 = V_224 ;
break;
case V_225 :
V_21 = V_226 ;
break;
case V_227 :
V_21 = V_228 ;
break;
default:
V_21 = V_202 ;
break;
}
if ( V_218 -> V_221 & V_229 )
V_22 = V_230 ;
else
V_22 = V_203 ;
if ( V_218 -> V_221 & V_231 ) {
if ( ! ( V_218 -> V_221 & V_232 ) )
V_20 = V_233 ;
else
V_20 = V_234 ;
} else {
V_20 = V_201 ;
}
if ( ( V_218 -> V_221 & V_235 ) && ( V_6 -> V_46 == 256 ) )
V_6 -> V_187 |= V_194 ;
else
V_6 -> V_187 &= ~ V_194 ;
V_218 -> V_221 &= ~ V_236 ;
V_19 = F_90 ( V_27 , V_218 , V_219 , 0 , V_27 -> V_198 / 16 ) ;
F_73 ( & V_27 -> V_166 , V_165 ) ;
F_86 ( V_27 , V_218 -> V_221 , V_19 ) ;
V_220 = F_8 ( V_6 , V_19 , V_20 , V_21 , V_22 ) ;
if ( V_220 )
goto V_237;
F_78 ( & V_6 -> V_27 , V_6 -> V_27 . V_186 ) ;
if ( F_91 ( V_218 ) )
F_92 ( V_218 , V_19 , V_19 ) ;
V_237:
F_74 ( & V_27 -> V_166 , V_165 ) ;
}
static const char * F_93 ( struct V_76 * V_27 )
{
return V_214 ;
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
V_68 = F_98 ( V_6 -> V_2 , V_214 ) ;
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
if ( type & V_238 ) {
V_27 -> type = V_6 -> V_239 ;
F_97 ( V_27 ) ;
}
}
static int F_101 ( struct V_76 * V_27 ,
struct V_240 * V_241 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_241 -> V_165 & V_242 ) {
F_63 ( V_6 -> V_27 . V_28 ,
L_29 ) ;
V_6 -> V_170 = 0 ;
V_241 -> V_165 &= ~ V_242 ;
} else {
#ifndef F_102
F_10 ( V_6 -> V_27 . V_28 , L_30 ,
V_35 ) ;
return - V_243 ;
#endif
V_6 -> V_170 = 1 ;
V_6 -> V_244 = 1 ;
F_63 ( V_6 -> V_27 . V_28 , L_31 ) ;
}
return 0 ;
}
static void F_103 ( struct V_5 * V_245 , int V_21 )
{
unsigned int V_246 , V_247 = 10000 ;
for (; ; ) {
V_246 = F_4 ( V_245 -> V_16 + V_64 ) ;
if ( ( V_246 & V_21 ) == V_21 )
break;
if ( -- V_247 == 0 )
break;
F_104 ( 1 ) ;
}
if ( V_245 -> V_27 . V_165 & V_248 ) {
unsigned int V_247 ;
for ( V_247 = 1000000 ; V_247 ; V_247 -- ) {
unsigned int V_10 = F_4 ( V_245 -> V_16 + V_11 ) ;
if ( V_10 & V_184 )
break;
F_104 ( 1 ) ;
F_105 () ;
}
}
}
static void F_106 ( struct V_76 * V_27 , int V_249 )
{
struct V_5 * V_6 =
F_31 ( V_27 , struct V_5 , V_27 ) ;
F_103 ( V_6 , V_250 ) ;
F_6 ( V_249 , V_6 -> V_16 + V_60 ) ;
}
static void
F_107 ( struct V_251 * V_252 , const char * V_253 , unsigned int V_112 )
{
struct V_5 * V_6 ;
unsigned long V_165 ;
T_2 V_15 ;
int V_254 = 1 ;
V_6 = V_255 [ V_252 -> V_256 ] ;
F_105 () ;
F_108 ( V_165 ) ;
if ( V_6 -> V_27 . V_257 ) {
V_254 = 0 ;
} else if ( V_258 ) {
V_254 = F_109 ( & V_6 -> V_27 . V_166 ) ;
} else
F_110 ( & V_6 -> V_27 . V_166 ) ;
V_15 = F_4 ( V_6 -> V_16 + V_17 ) ;
F_7 ( V_6 , V_199 ) ;
F_111 ( & V_6 -> V_27 , V_253 , V_112 , F_106 ) ;
F_103 ( V_6 , V_259 ) ;
F_6 ( V_15 , V_6 -> V_16 + V_17 ) ;
if ( V_254 )
F_112 ( & V_6 -> V_27 . V_166 ) ;
F_113 ( V_165 ) ;
}
static int T_6 F_114 ( struct V_251 * V_252 , char * V_260 )
{
struct V_76 * V_27 ;
int V_19 = 9600 ;
int V_21 = 8 ;
int V_20 = 'n' ;
int V_261 = 'n' ;
if ( V_252 -> V_256 >= V_262 )
V_252 -> V_256 = 0 ;
V_27 = & V_255 [ V_252 -> V_256 ] -> V_27 ;
if ( ! V_27 || ( ! V_27 -> V_263 && ! V_27 -> V_16 ) )
return - V_264 ;
V_27 -> V_198 = V_265 ;
if ( V_260 )
F_115 ( V_260 , & V_19 , & V_20 , & V_21 , & V_261 ) ;
return F_116 ( V_27 , V_252 , V_19 , V_20 , V_21 , V_261 ) ;
}
static struct V_5 * F_117 ( struct V_1 * V_2 ,
const struct V_266 * V_267 )
{
struct V_5 * V_6 ;
int V_68 ;
unsigned int V_263 ;
unsigned int V_103 ;
unsigned char * V_135 ;
int V_3 , V_4 ;
int V_239 ;
struct V_268 * V_269 ;
const char * V_270 ;
V_269 = & V_271 [ V_267 -> V_272 ] ;
V_239 = V_269 -> V_239 ;
V_6 = F_68 ( sizeof( struct V_5 ) , V_110 ) ;
if ( V_6 == NULL )
goto V_273;
V_135 = ( unsigned char * ) F_118 ( V_110 ) ;
if ( ! V_135 )
goto V_274;
V_4 = V_265 ;
V_270 = F_119 ( V_275 ) ;
if ( V_270 && strstr ( V_270 , L_32 ) )
V_4 = 192000000 ;
switch ( V_239 ) {
case V_276 :
V_3 = 256 ;
break;
case V_277 :
V_3 = 64 ;
break;
default:
F_10 ( & V_2 -> V_28 , L_33 , V_239 ) ;
goto V_278;
}
F_120 ( V_2 ) ;
V_263 = F_121 ( V_2 , 0 ) ;
V_103 = F_121 ( V_2 , 1 ) ;
V_6 -> V_103 = V_103 ;
V_6 -> V_263 = V_263 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_147 = 1 ;
V_6 -> V_135 . V_56 = V_135 ;
V_6 -> V_135 . V_75 = V_279 ;
V_6 -> V_46 = V_3 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_239 = V_280 + V_239 + 1 ;
V_6 -> V_27 . V_28 = & V_2 -> V_28 ;
V_6 -> V_27 . V_263 = V_263 ;
V_6 -> V_27 . V_16 = NULL ;
V_6 -> V_27 . V_103 = V_103 ;
V_6 -> V_27 . V_161 = V_2 -> V_161 ;
V_6 -> V_27 . V_281 = V_282 ;
V_6 -> V_27 . V_283 = & V_284 ;
V_6 -> V_27 . V_165 = V_285 ;
V_6 -> V_27 . V_3 = V_3 ;
V_6 -> V_27 . line = V_269 -> V_286 ;
V_6 -> V_47 = V_210 ;
F_122 ( & V_6 -> V_27 . V_166 ) ;
F_123 ( V_2 , V_6 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
#ifdef F_124
V_255 [ V_269 -> V_286 ] = V_6 ;
#endif
V_68 = F_125 ( & V_287 , & V_6 -> V_27 ) ;
if ( V_68 < 0 )
goto V_278;
return V_6 ;
V_278:
#ifdef F_124
V_255 [ V_269 -> V_286 ] = NULL ;
#endif
F_126 ( ( unsigned long ) V_135 ) ;
V_274:
F_49 ( V_6 ) ;
V_273:
return NULL ;
}
static void F_127 ( struct V_5 * V_6 )
{
F_128 ( & V_287 , & V_6 -> V_27 ) ;
F_123 ( V_6 -> V_2 , NULL ) ;
F_126 ( ( unsigned long ) V_6 -> V_135 . V_56 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) F_2 ( V_2 ) ;
F_130 ( V_2 ) ;
#ifdef F_124
V_255 [ V_6 -> V_27 . line ] = NULL ;
#endif
F_127 ( V_6 ) ;
F_131 ( V_2 ) ;
F_49 ( V_6 ) ;
return;
}
static int F_132 ( struct V_1 * V_2 , T_7 V_79 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_133 ( & V_287 , & V_6 -> V_27 ) ;
F_134 ( V_2 ) ;
F_135 ( V_2 , F_136 ( V_2 , V_79 ) ) ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_68 ;
F_135 ( V_2 , V_288 ) ;
F_138 ( V_2 ) ;
V_68 = F_139 ( V_2 ) ;
if ( V_68 ) {
F_10 ( & V_2 -> V_28 ,
L_34 , V_35 , V_68 ) ;
return V_68 ;
}
F_140 ( & V_287 , & V_6 -> V_27 ) ;
return 0 ;
}
static int T_8 F_141 ( struct V_1 * V_2 ,
const struct V_266 * V_267 )
{
int V_68 ;
struct V_5 * V_6 ;
V_68 = F_139 ( V_2 ) ;
if ( V_68 < 0 )
goto V_289;
V_6 = F_117 ( V_2 , V_267 ) ;
if ( ! V_6 ) {
V_68 = - V_80 ;
goto V_290;
}
F_123 ( V_2 , V_6 ) ;
return V_68 ;
V_290:
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
V_289:
return V_68 ;
}
static int T_6 F_142 ( void )
{
int V_68 ;
V_68 = F_143 ( & V_287 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_144 ( & V_291 ) ;
if ( V_68 < 0 )
F_145 ( & V_287 ) ;
return V_68 ;
}
static void T_9 F_146 ( void )
{
F_147 ( & V_291 ) ;
F_145 ( & V_287 ) ;
}
