static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
int V_7 = 0 ;
int V_8 ;
unsigned int V_9 ;
V_9 = V_3 | V_10 | V_11 ;
F_3 ( V_2 , V_12 , V_9 ) ;
F_4 ( V_2 -> V_13 , L_1 ) ;
if ( V_5 -> V_14 )
V_8 = 4 ;
else
V_8 = 400 ;
do {
V_7 ++ ;
if ( V_5 -> V_14 )
F_5 ( & V_5 -> V_15 ,
F_6 ( 250 ) ) ;
else
F_7 ( 1 ) ;
V_6 = F_8 ( V_2 , V_12 ) ;
F_4 ( V_2 -> V_13 , L_2 , V_6 ) ;
} while ( V_6 & V_3 && V_7 < V_8 );
if ( V_6 & V_3 )
F_9 ( V_2 -> V_13 , L_3 ,
V_3 ) ;
}
T_1 F_10 ( int V_16 , void * V_17 )
{
struct V_4 * V_5 = V_17 ;
F_11 ( & V_5 -> V_15 ) ;
return V_18 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_19 ;
T_3 V_6 , V_20 , V_21 , V_22 , V_23 ;
switch ( V_5 -> V_24 ) {
case 2 :
V_23 = V_25 ;
break;
default:
V_23 = V_26 ;
break;
}
if ( V_5 -> V_27 && V_5 -> V_28 ) {
F_4 ( V_2 -> V_13 , L_4 ,
V_5 -> V_28 ) ;
F_3 ( V_2 , V_23 , V_5 -> V_28 ) ;
F_1 ( V_2 ,
V_29 |
V_30 ) ;
return;
}
if ( V_5 -> V_31 ) {
F_13 ( V_2 , V_32 ,
V_33 ,
32 << V_34 ) ;
F_1 ( V_2 ,
V_35 |
V_36 ) ;
} else {
F_1 ( V_2 ,
V_37 |
V_38 ) ;
}
switch ( V_5 -> V_24 ) {
case 0 :
V_20 = F_8 ( V_2 , V_39 )
& V_40 ;
V_21 = F_8 ( V_2 , V_41 )
& V_42 ;
break;
case 2 :
case 1 :
V_6 = F_8 ( V_2 , V_23 ) ;
V_21 = ( V_6 & V_43 )
>> V_44 ;
V_20 = V_6 & V_45 ;
break;
default:
F_14 ( 1 , L_5 ) ;
return;
}
F_4 ( V_2 -> V_13 , L_6 , V_20 , V_21 ) ;
if ( V_5 -> V_46 || V_5 -> V_47 ) {
F_4 ( V_2 -> V_13 ,
L_7 ,
V_5 -> V_46 , V_5 -> V_47 ) ;
V_19 = V_21 ;
V_19 += V_5 -> V_47 ;
V_22 = ( V_48 ) V_19 << V_44 ;
V_19 = V_20 ;
V_19 += V_5 -> V_46 ;
V_22 |= ( V_48 ) V_19 ;
F_4 ( V_2 -> V_13 , L_8 , V_22 ) ;
F_3 ( V_2 , V_23 , V_22 ) ;
F_1 ( V_2 ,
V_29 |
V_30 ) ;
} else {
V_22 = V_21 << V_44 ;
V_22 |= V_20 ;
}
if ( V_5 -> V_27 && ! V_5 -> V_49 )
V_5 -> V_28 = V_22 ;
}
static int F_15 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_54 ;
V_54 = F_17 ( V_51 , V_53 ) ;
V_5 -> V_28 = 0 ;
if ( V_5 -> V_46 || V_5 -> V_47 || V_5 -> V_55 )
return V_54 ;
if ( F_8 ( V_2 , V_56 )
& ( V_57 | V_58 ) )
F_13 ( V_2 ,
V_12 ,
V_59 |
V_60 ,
V_59 |
V_60 ) ;
return V_54 ;
}
static int F_18 ( struct V_61 * V_62 ,
struct V_50 * V_51 , int V_63 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_63 ) {
case V_64 :
switch ( V_5 -> V_65 ) {
case 0 :
break;
case 1 :
F_13 ( V_2 , V_56 ,
V_57 |
V_58 ,
V_57 |
V_58 ) ;
F_13 ( V_2 , V_66 ,
V_67 |
V_68 ,
V_67 |
V_68 ) ;
break;
default:
F_9 ( V_2 -> V_13 , L_9 ,
V_5 -> V_65 ) ;
break;
}
case V_69 :
F_13 ( V_2 , V_70 ,
V_71 , 0 ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_61 * V_62 ,
struct V_50 * V_51 , int V_63 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
unsigned int V_6 = F_8 ( V_2 , V_66 ) ;
switch ( V_63 ) {
case V_72 :
F_13 ( V_2 , V_70 ,
V_71 , V_71 ) ;
F_7 ( 5 ) ;
F_13 ( V_2 , V_56 ,
V_57 | V_58 ,
V_57 | V_58 ) ;
V_6 |= V_67 | V_68 ;
F_3 ( V_2 , V_66 , V_6 ) ;
F_13 ( V_2 , V_32 ,
V_73 , 0 ) ;
F_12 ( V_2 ) ;
V_6 |= V_74 | V_75 |
V_76 | V_77 ;
F_3 ( V_2 , V_66 , V_6 ) ;
break;
case V_69 :
F_13 ( V_2 , V_66 ,
V_76 |
V_74 |
V_77 |
V_75 , 0 ) ;
F_13 ( V_2 , V_66 ,
V_67 |
V_68 , 0 ) ;
F_3 ( V_2 , V_12 , 0 ) ;
F_13 ( V_2 , V_56 ,
V_57 | V_58 ,
0 ) ;
break;
}
return 0 ;
}
static int F_20 ( struct V_61 * V_62 ,
struct V_50 * V_78 , int V_63 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
T_3 V_6 = F_8 ( V_2 , V_79 ) & ~ V_80 ;
switch ( V_63 ) {
case V_64 :
V_6 |= V_80 ;
F_3 ( V_2 , V_79 , V_6 ) ;
F_21 ( 50 ) ;
break;
case V_81 :
F_3 ( V_2 , V_79 , V_6 ) ;
break;
default:
F_22 () ;
break;
}
return 0 ;
}
static int F_23 ( struct V_61 * V_62 ,
struct V_50 * V_78 , int V_63 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
bool * V_82 ;
switch ( V_62 -> V_83 ) {
case V_84 :
V_82 = & V_5 -> V_85 ;
break;
case V_86 :
V_82 = & V_5 -> V_87 ;
break;
case V_88 :
V_82 = & V_5 -> V_89 ;
break;
case V_90 :
V_82 = & V_5 -> V_91 ;
break;
default:
F_14 ( 1 , L_10 ) ;
return - V_92 ;
}
* V_82 = F_24 ( V_63 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = & V_2 -> V_94 ;
F_13 ( V_2 , V_95 ,
V_96 , V_96 ) ;
F_13 ( V_2 , V_97 ,
V_96 , V_96 ) ;
F_13 ( V_2 , V_98 ,
V_99 , V_99 ) ;
F_13 ( V_2 , V_100 ,
V_99 , V_99 ) ;
F_13 ( V_2 , V_101 ,
V_102 , V_102 ) ;
F_13 ( V_2 , V_103 ,
V_102 , V_102 ) ;
F_13 ( V_2 , V_104 ,
V_105 | V_106 ,
V_105 | V_106 ) ;
F_13 ( V_2 , V_107 ,
V_105 | V_108 ,
V_105 | V_108 ) ;
F_13 ( V_2 , V_109 ,
V_110 | V_111 ,
V_110 | V_111 ) ;
F_13 ( V_2 , V_112 ,
V_113 | V_111 ,
V_113 | V_111 ) ;
F_26 ( V_2 , V_114 ,
F_27 ( V_114 ) ) ;
F_28 ( V_94 , V_115 ,
F_27 ( V_115 ) ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 ,
int V_116 , int V_117 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_93 * V_94 = & V_2 -> V_94 ;
F_30 ( & V_5 -> V_15 ) ;
F_31 ( V_94 , V_118 ,
F_27 ( V_118 ) ) ;
if ( V_116 )
F_31 ( V_94 ,
V_119 ,
F_27 ( V_119 ) ) ;
else
F_31 ( V_94 ,
V_120 ,
F_27 ( V_120 ) ) ;
if ( V_117 )
F_31 ( V_94 ,
V_121 ,
F_27 ( V_121 ) ) ;
else
F_31 ( V_94 ,
V_122 ,
F_27 ( V_122 ) ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 ,
int V_116 , int V_117 ,
int V_123 , int V_124 ,
int V_125 , int V_126 , int V_127 ,
int V_128 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_129 = ! V_116 ;
V_5 -> V_130 = ! V_117 ;
if ( ! V_116 )
F_13 ( V_2 , V_131 ,
V_132 ,
V_132 ) ;
if ( ! V_117 )
F_13 ( V_2 , V_133 ,
V_134 ,
V_134 ) ;
if ( ! V_116 && ! V_117 )
F_13 ( V_2 , V_79 ,
V_135 ,
V_135 ) ;
if ( V_123 )
F_13 ( V_2 , V_136 ,
V_137 , V_137 ) ;
if ( V_124 )
F_13 ( V_2 , V_136 ,
V_138 , V_138 ) ;
F_13 ( V_2 , V_139 ,
V_140 | V_141 |
V_142 | V_143 ,
V_125 << V_144 |
V_126 << V_145 |
V_127 |
V_128 << V_146 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_9 = 0 ;
if ( V_5 -> V_129 )
V_9 |= V_147 | V_148 ;
if ( V_5 -> V_130 )
V_9 |= V_149 | V_150 ;
F_13 ( V_2 , V_151 , V_9 , V_9 ) ;
}
void F_34 ( struct V_1 * V_2 ,
enum V_152 V_153 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_154 , V_9 ;
switch ( V_153 ) {
case V_155 :
F_13 ( V_2 , V_156 ,
V_157 , V_157 ) ;
break;
case V_158 :
V_9 = 0 ;
V_154 = 0 ;
if ( V_5 -> V_129 )
V_154 |= V_147 | V_148 ;
if ( V_5 -> V_130 )
V_154 |= V_149 | V_150 ;
if ( V_5 -> V_129 && V_5 -> V_85 )
V_9 |= V_147 ;
if ( V_5 -> V_129 && V_5 -> V_87 )
V_9 |= V_148 ;
if ( V_5 -> V_130 && V_5 -> V_89 )
V_9 |= V_149 ;
if ( V_5 -> V_130 && V_5 -> V_91 )
V_9 |= V_150 ;
F_13 ( V_2 , V_151 ,
V_154 , V_9 ) ;
F_13 ( V_2 , V_156 ,
V_157 , 0 ) ;
break;
default:
break;
}
}
