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
V_119 , 1 , V_113 ,
V_141 | V_142 ) ;
if ( ! V_138 )
return 0 ;
V_6 -> V_114 = V_138 ;
V_138 -> V_143 = F_43 ;
V_138 -> V_144 = V_6 ;
V_138 -> V_145 ( V_138 ) ;
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
int V_146 ;
if ( ! V_6 -> V_147 ) {
F_63 ( V_6 -> V_27 . V_28 , L_16 ,
V_35 , V_36 ) ;
F_7 ( V_6 , V_128 ) ;
V_6 -> V_146 = 1 ;
return 0 ;
}
V_46 = F_64 ( V_6 -> V_46 , 1 ) ;
V_146 = 1 ;
if ( F_25 ( V_6 , V_117 -> V_56 ) ) {
F_15 ( V_6 , V_117 -> V_56 , 1 ) ;
V_27 -> V_84 . V_123 ++ ;
V_146 = 0 ;
V_46 -- ;
}
V_75 = F_54 ( V_117 -> V_131 - V_117 -> V_122 , V_46 ) ;
if ( V_75 < 0 )
V_75 = V_46 ;
V_57 = F_50 ( V_6 , V_75 ) ;
if ( V_57 > 0 ) {
V_27 -> V_84 . V_123 += V_57 ;
V_146 = 0 ;
}
V_6 -> V_146 = V_146 ;
if ( V_146 ) {
F_7 ( V_6 , V_128 ) ;
F_65 ( V_27 ) ;
}
return V_148 ;
}
static unsigned int F_66 ( struct V_5 * V_6 )
{
struct V_76 * V_27 = & V_6 -> V_27 ;
struct V_116 * V_117 = & V_27 -> V_79 -> V_117 ;
struct V_118 * V_119 ;
int V_121 ;
int V_46 ;
int V_146 ;
struct V_137 * V_138 ;
int V_149 ;
int V_58 ;
int V_150 ;
int V_75 ;
int V_151 ;
if ( ! V_6 -> V_147 ) {
F_63 ( V_6 -> V_27 . V_28 , L_16 ,
V_35 , V_36 ) ;
F_7 ( V_6 , V_128 ) ;
V_6 -> V_146 = 1 ;
return 0 ;
}
if ( V_6 -> V_127 ) {
F_11 ( V_6 -> V_27 . V_28 , L_17 ,
V_35 , V_36 ) ;
F_7 ( V_6 , V_128 ) ;
V_6 -> V_146 = 1 ;
return 0 ;
}
V_46 = F_64 ( V_6 -> V_46 , 1 ) ;
V_146 = 1 ;
if ( F_25 ( V_6 , V_117 -> V_56 ) ) {
F_15 ( V_6 , V_117 -> V_56 , 1 ) ;
V_27 -> V_84 . V_123 ++ ;
V_146 = 0 ;
V_46 -- ;
}
V_150 = F_54 ( ( int ) F_67 ( V_117 -> V_131 , V_117 -> V_122 ,
V_124 ) , F_53 ( V_117 -> V_131 ,
V_117 -> V_122 , V_124 ) ) ;
if ( ! V_150 ) {
F_11 ( V_6 -> V_27 . V_28 , L_18 , V_35 ) ;
F_7 ( V_6 , V_128 ) ;
F_65 ( V_27 ) ;
return 0 ;
}
if ( V_150 > V_46 ) {
V_149 = V_150 / V_46 + 1 ;
V_75 = V_46 ;
V_151 = V_150 % V_46 ;
} else {
V_149 = 1 ;
V_75 = V_150 ;
V_151 = V_150 ;
}
F_11 ( V_6 -> V_27 . V_28 , L_19 ,
V_35 , V_149 , V_75 , V_151 ) ;
V_6 -> V_127 = 1 ;
V_6 -> V_120 = F_68 ( sizeof( struct V_118 ) * V_149 , V_152 ) ;
F_58 ( V_6 -> V_120 , V_149 ) ;
V_119 = V_6 -> V_120 ;
for ( V_58 = 0 ; V_58 < V_149 ; V_58 ++ , V_119 ++ ) {
if ( V_58 == ( V_149 - 1 ) )
F_59 ( V_119 , F_60 ( V_117 -> V_56 ) ,
V_151 , V_46 * V_58 ) ;
else
F_59 ( V_119 , F_60 ( V_117 -> V_56 ) ,
V_75 , V_46 * V_58 ) ;
}
V_119 = V_6 -> V_120 ;
V_121 = F_69 ( V_27 -> V_28 , V_119 , V_149 , V_126 ) ;
if ( ! V_121 ) {
F_10 ( V_6 -> V_27 . V_28 , L_20 , V_35 ) ;
return 0 ;
}
V_6 -> V_121 = V_121 ;
for ( V_58 = 0 ; V_58 < V_121 ; V_58 ++ , V_119 ++ ) {
V_119 -> V_153 = ( V_117 -> V_122 & ( V_124 - 1 ) ) +
V_46 * V_58 ;
F_33 ( V_119 ) = ( F_33 ( V_119 ) &
~ ( V_124 - 1 ) ) + V_119 -> V_153 ;
if ( V_58 == ( V_121 - 1 ) )
F_47 ( V_119 ) = V_151 ;
else
F_47 ( V_119 ) = V_75 ;
}
V_138 = V_6 -> V_86 -> V_95 -> V_140 ( V_6 -> V_86 ,
V_6 -> V_120 , V_121 , V_126 ,
V_141 | V_142 ) ;
if ( ! V_138 ) {
F_10 ( V_6 -> V_27 . V_28 , L_21 ,
V_35 ) ;
return 0 ;
}
F_70 ( V_27 -> V_28 , V_6 -> V_120 , V_121 , V_126 ) ;
V_6 -> V_125 = V_138 ;
V_138 -> V_143 = F_46 ;
V_138 -> V_144 = V_6 ;
V_138 -> V_145 ( V_138 ) ;
F_61 ( V_6 -> V_86 ) ;
return V_148 ;
}
static void F_71 ( struct V_5 * V_6 , unsigned int V_63 )
{
T_2 V_8 = F_4 ( V_6 -> V_16 + V_44 ) ;
V_8 |= V_154 ;
F_6 ( V_8 , V_6 -> V_16 + V_44 ) ;
if ( V_63 & V_155 )
F_10 ( & V_6 -> V_2 -> V_28 , L_22 ) ;
if ( V_63 & V_156 )
F_10 ( & V_6 -> V_2 -> V_28 , L_23 ) ;
if ( V_63 & V_157 )
F_10 ( & V_6 -> V_2 -> V_28 , L_24 ) ;
if ( V_63 & V_158 )
F_10 ( & V_6 -> V_2 -> V_28 , L_25 ) ;
}
static T_4 F_72 ( int V_159 , void * V_160 )
{
struct V_5 * V_6 = V_160 ;
unsigned int V_161 ;
T_2 V_63 ;
int V_68 = 0 ;
unsigned int V_162 ;
unsigned long V_163 ;
F_73 ( & V_6 -> V_27 . V_164 , V_163 ) ;
V_161 = 0 ;
while ( ( V_162 = F_17 ( V_6 ) ) > 1 ) {
switch ( V_162 ) {
case V_165 :
V_63 = F_18 ( V_6 ) ;
if ( V_63 & ( V_155 | V_156 |
V_157 | V_158 ) ) {
F_71 ( V_6 , V_63 ) ;
V_68 = V_166 ;
}
break;
case V_167 :
if ( V_6 -> V_168 ) {
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
case V_169 :
V_68 = F_55 ( V_6 ) ;
break;
case V_170 :
if ( V_6 -> V_168 )
V_68 = F_66 ( V_6 ) ;
else
V_68 = F_62 ( V_6 ) ;
break;
case V_171 :
V_68 = V_172 ;
break;
default:
F_10 ( V_6 -> V_27 . V_28 , L_26 , V_35 ,
V_162 , V_36 ) ;
V_68 = - 1 ;
break;
}
V_161 |= ( unsigned int ) V_68 ;
}
if ( V_161 == 0 && V_162 <= 1 ) {
if ( V_6 -> V_173 )
V_6 -> V_173 = 0 ;
}
F_74 ( & V_6 -> V_27 . V_164 , V_163 ) ;
return F_75 ( V_161 ) ;
}
static unsigned int F_76 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
int V_68 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_6 -> V_146 )
V_68 = V_174 ;
else
V_68 = 0 ;
return V_68 ;
}
static unsigned int F_77 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
T_2 V_175 ;
unsigned int V_68 = 0 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_175 = F_14 ( V_6 ) ;
if ( V_175 & V_176 )
V_68 |= V_177 ;
if ( V_175 & V_178 )
V_68 |= V_179 ;
if ( V_175 & V_180 )
V_68 |= V_181 ;
if ( V_175 & V_182 )
V_68 |= V_183 ;
return V_68 ;
}
static void F_78 ( struct V_76 * V_27 , unsigned int V_184 )
{
T_5 V_185 = 0 ;
struct V_5 * V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_184 & V_186 )
V_185 |= V_187 ;
if ( V_184 & V_188 )
V_185 |= V_189 ;
if ( V_184 & V_190 )
V_185 |= V_191 ;
if ( V_6 -> V_185 & V_192 )
V_185 |= V_192 ;
if ( V_184 )
F_6 ( V_185 , V_6 -> V_16 + V_193 ) ;
}
static void F_79 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_6 -> V_147 = 0 ;
V_6 -> V_127 = 0 ;
}
static void F_80 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_6 -> V_168 ) {
if ( V_6 -> V_127 ) {
F_11 ( V_6 -> V_27 . V_28 , L_27 ,
V_35 ) ;
return;
}
}
V_6 -> V_147 = 1 ;
F_5 ( V_6 , V_128 ) ;
}
static void F_81 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_6 -> V_134 = 0 ;
F_7 ( V_6 , V_115 ) ;
V_6 -> V_173 = 1 ;
}
static void F_82 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
F_5 ( V_6 , V_194 ) ;
}
static void F_83 ( struct V_76 * V_27 , int V_195 )
{
struct V_5 * V_6 ;
unsigned long V_163 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
F_73 ( & V_27 -> V_164 , V_163 ) ;
F_19 ( V_6 , V_195 ) ;
F_74 ( & V_27 -> V_164 , V_163 ) ;
}
static int F_84 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
int V_68 ;
int V_46 ;
int V_7 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
V_6 -> V_146 = 1 ;
if ( V_27 -> V_196 )
V_6 -> V_4 = V_27 -> V_196 ;
else
V_27 -> V_196 = V_6 -> V_4 ;
F_7 ( V_6 , V_197 ) ;
V_68 = F_8 ( V_6 , V_198 ,
V_199 , V_200 ,
V_201 ) ;
if ( V_68 )
return V_68 ;
switch ( V_6 -> V_46 ) {
case 256 :
V_46 = V_202 ;
break;
case 64 :
V_46 = V_203 ;
break;
case 16 :
V_46 = V_204 ;
case 1 :
default:
V_46 = V_205 ;
break;
}
switch ( V_6 -> V_47 ) {
case V_206 :
V_7 = 1 ;
break;
case V_207 :
V_7 = V_6 -> V_46 / 4 ;
break;
case V_208 :
V_7 = V_6 -> V_46 / 2 ;
break;
case V_209 :
default:
V_7 = V_6 -> V_46 - ( V_6 -> V_46 / 8 ) ;
break;
}
V_6 -> V_7 = V_7 ;
V_68 = F_13 ( V_6 , V_210 ,
V_46 , V_6 -> V_47 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_85 ( V_6 -> V_27 . V_159 , F_72 , V_211 ,
V_212 , V_6 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_6 -> V_168 )
F_36 ( V_27 ) ;
V_6 -> V_134 = 1 ;
F_5 ( V_6 , V_115 ) ;
F_86 ( V_27 , V_213 , V_198 ) ;
return 0 ;
}
static void F_87 ( struct V_76 * V_27 )
{
struct V_5 * V_6 ;
int V_68 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
F_7 ( V_6 , V_197 ) ;
F_12 ( V_6 , V_214 ) ;
V_68 = F_13 ( V_6 , V_210 ,
V_205 , V_206 ) ;
if ( V_68 )
F_10 ( V_6 -> V_27 . V_28 ,
L_28 , V_68 ) ;
F_30 ( V_27 ) ;
F_88 ( V_6 -> V_27 . V_159 , V_6 ) ;
}
static void F_89 ( struct V_76 * V_27 ,
struct V_215 * V_216 , struct V_215 * V_217 )
{
int V_19 ;
int V_218 ;
unsigned int V_20 , V_21 , V_22 ;
struct V_5 * V_6 ;
unsigned long V_163 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
switch ( V_216 -> V_219 & V_220 ) {
case V_221 :
V_21 = V_222 ;
break;
case V_223 :
V_21 = V_224 ;
break;
case V_225 :
V_21 = V_226 ;
break;
default:
V_21 = V_200 ;
break;
}
if ( V_216 -> V_219 & V_227 )
V_22 = V_228 ;
else
V_22 = V_201 ;
if ( V_216 -> V_219 & V_229 ) {
if ( ! ( V_216 -> V_219 & V_230 ) )
V_20 = V_231 ;
else
V_20 = V_232 ;
} else {
V_20 = V_199 ;
}
if ( ( V_216 -> V_219 & V_233 ) && ( V_6 -> V_46 == 256 ) )
V_6 -> V_185 |= V_192 ;
else
V_6 -> V_185 &= ~ V_192 ;
V_216 -> V_219 &= ~ V_234 ;
V_19 = F_90 ( V_27 , V_216 , V_217 , 0 , V_27 -> V_196 / 16 ) ;
F_73 ( & V_27 -> V_164 , V_163 ) ;
F_86 ( V_27 , V_216 -> V_219 , V_19 ) ;
V_218 = F_8 ( V_6 , V_19 , V_20 , V_21 , V_22 ) ;
if ( V_218 )
goto V_235;
F_78 ( & V_6 -> V_27 , V_6 -> V_27 . V_184 ) ;
if ( F_91 ( V_216 ) )
F_92 ( V_216 , V_19 , V_19 ) ;
V_235:
F_74 ( & V_27 -> V_164 , V_163 ) ;
}
static const char * F_93 ( struct V_76 * V_27 )
{
return V_212 ;
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
V_68 = F_98 ( V_6 -> V_2 , V_212 ) ;
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
if ( type & V_236 ) {
V_27 -> type = V_6 -> V_237 ;
F_97 ( V_27 ) ;
}
}
static int F_101 ( struct V_76 * V_27 ,
struct V_238 * V_239 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_27 , struct V_5 , V_27 ) ;
if ( V_239 -> V_163 & V_240 ) {
F_63 ( V_6 -> V_27 . V_28 ,
L_29 ) ;
V_6 -> V_168 = 0 ;
V_239 -> V_163 &= ~ V_240 ;
} else {
#ifndef F_102
F_10 ( V_6 -> V_27 . V_28 , L_30 ,
V_35 ) ;
return - V_241 ;
#endif
V_6 -> V_168 = 1 ;
V_6 -> V_242 = 1 ;
F_63 ( V_6 -> V_27 . V_28 , L_31 ) ;
}
return 0 ;
}
static struct V_5 * F_103 ( struct V_1 * V_2 ,
const struct V_243 * V_244 )
{
struct V_5 * V_6 ;
int V_68 ;
unsigned int V_245 ;
unsigned int V_103 ;
unsigned char * V_135 ;
int V_3 , V_4 ;
int V_237 ;
struct V_246 * V_247 ;
const char * V_248 ;
V_247 = & V_249 [ V_244 -> V_250 ] ;
V_237 = V_247 -> V_237 ;
V_6 = F_68 ( sizeof( struct V_5 ) , V_110 ) ;
if ( V_6 == NULL )
goto V_251;
V_135 = ( unsigned char * ) F_104 ( V_110 ) ;
if ( ! V_135 )
goto V_252;
V_4 = 1843200 ;
V_248 = F_105 ( V_253 ) ;
if ( V_248 && strstr ( V_248 , L_32 ) )
V_4 = 192000000 ;
switch ( V_237 ) {
case V_254 :
V_3 = 256 ;
break;
case V_255 :
V_3 = 64 ;
break;
default:
F_10 ( & V_2 -> V_28 , L_33 , V_237 ) ;
goto V_256;
}
F_106 ( V_2 ) ;
V_245 = F_107 ( V_2 , 0 ) ;
V_103 = F_107 ( V_2 , 1 ) ;
V_6 -> V_103 = V_103 ;
V_6 -> V_245 = V_245 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_146 = 1 ;
V_6 -> V_135 . V_56 = V_135 ;
V_6 -> V_135 . V_75 = V_257 ;
V_6 -> V_46 = V_3 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_237 = V_258 + V_237 + 1 ;
V_6 -> V_27 . V_28 = & V_2 -> V_28 ;
V_6 -> V_27 . V_245 = V_245 ;
V_6 -> V_27 . V_16 = NULL ;
V_6 -> V_27 . V_103 = V_103 ;
V_6 -> V_27 . V_159 = V_2 -> V_159 ;
V_6 -> V_27 . V_259 = V_260 ;
V_6 -> V_27 . V_261 = & V_262 ;
V_6 -> V_27 . V_163 = V_263 ;
V_6 -> V_27 . V_3 = V_3 ;
V_6 -> V_27 . line = V_247 -> V_264 ;
V_6 -> V_47 = V_208 ;
F_108 ( & V_6 -> V_27 . V_164 ) ;
F_109 ( V_2 , V_6 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_68 = F_110 ( & V_265 , & V_6 -> V_27 ) ;
if ( V_68 < 0 )
goto V_256;
return V_6 ;
V_256:
F_111 ( ( unsigned long ) V_135 ) ;
V_252:
F_49 ( V_6 ) ;
V_251:
return NULL ;
}
static void F_112 ( struct V_5 * V_6 )
{
F_113 ( & V_265 , & V_6 -> V_27 ) ;
F_109 ( V_6 -> V_2 , NULL ) ;
F_111 ( ( unsigned long ) V_6 -> V_135 . V_56 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) F_2 ( V_2 ) ;
F_115 ( V_2 ) ;
F_112 ( V_6 ) ;
F_116 ( V_2 ) ;
F_49 ( V_6 ) ;
return;
}
static int F_117 ( struct V_1 * V_2 , T_6 V_79 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_118 ( & V_265 , & V_6 -> V_27 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 , F_121 ( V_2 , V_79 ) ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_68 ;
F_120 ( V_2 , V_266 ) ;
F_123 ( V_2 ) ;
V_68 = F_124 ( V_2 ) ;
if ( V_68 ) {
F_10 ( & V_2 -> V_28 ,
L_34 , V_35 , V_68 ) ;
return V_68 ;
}
F_125 ( & V_265 , & V_6 -> V_27 ) ;
return 0 ;
}
static int T_7 F_126 ( struct V_1 * V_2 ,
const struct V_243 * V_244 )
{
int V_68 ;
struct V_5 * V_6 ;
V_68 = F_124 ( V_2 ) ;
if ( V_68 < 0 )
goto V_267;
V_6 = F_103 ( V_2 , V_244 ) ;
if ( ! V_6 ) {
V_68 = - V_80 ;
goto V_268;
}
F_109 ( V_2 , V_6 ) ;
return V_68 ;
V_268:
F_115 ( V_2 ) ;
F_116 ( V_2 ) ;
V_267:
return V_68 ;
}
static int T_8 F_127 ( void )
{
int V_68 ;
V_68 = F_128 ( & V_265 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_129 ( & V_269 ) ;
if ( V_68 < 0 )
F_130 ( & V_265 ) ;
return V_68 ;
}
static void T_9 F_131 ( void )
{
F_132 ( & V_269 ) ;
F_130 ( & V_265 ) ;
}
