static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_3 ] ;
F_2 ( V_8 -> V_9 , V_5 -> V_10 + V_11 ) ;
F_2 ( V_8 -> V_12 , V_5 -> V_10 + V_13 ) ;
}
static void F_3 ( struct V_1 * V_2 , bool V_14 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_15 ;
V_15 = F_4 ( V_5 -> V_10 + V_16 ) ;
if ( V_14 )
V_15 |= V_17 | V_18 | V_19 ;
else
V_15 &= ~ V_19 ;
F_2 ( V_15 , V_5 -> V_10 + V_16 ) ;
}
static void F_5 ( struct V_1 * V_2 , bool V_14 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_20 ;
V_20 = F_4 ( V_5 -> V_10 + V_21 ) ;
if ( V_14 )
V_20 |= 0x1f00 ;
else
V_20 &= ~ 0x1f00 ;
F_2 ( V_20 , V_5 -> V_10 + V_21 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_22 + V_23 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_28 = F_8 ( V_27 -> V_29 [ 0 ] ) ;
unsigned int V_30 = F_9 ( V_27 -> V_29 [ 0 ] ) ;
int V_31 ;
if ( V_27 -> V_32 == 1 )
return 0 ;
for ( V_31 = 1 ; V_31 < V_27 -> V_32 ; V_31 ++ ) {
unsigned int V_33 = F_10 ( V_27 -> V_29 [ V_31 ] ) ;
unsigned int V_34 = F_8 ( V_27 -> V_29 [ V_31 ] ) ;
unsigned int V_35 = F_9 ( V_27 -> V_29 [ V_31 ] ) ;
if ( V_35 != V_30 ) {
F_11 ( V_2 -> V_36 ,
L_1 ) ;
return - V_37 ;
}
if ( F_12 ( V_25 , V_34 ) !=
F_12 ( V_25 , V_28 ) ) {
F_11 ( V_2 -> V_36 ,
L_2 ) ;
return - V_37 ;
}
if ( ! V_5 -> V_38 && V_35 == V_39 &&
( V_33 >= ( V_25 -> V_40 / 2 ) ) ) {
F_11 ( V_2 -> V_36 ,
L_3 ) ;
return - V_37 ;
}
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
int V_40 , unsigned int * V_29 ,
int V_41 , int V_42 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_43 = F_10 ( V_29 [ 0 ] ) ;
unsigned int V_28 = F_8 ( V_29 [ 0 ] ) ;
unsigned int V_30 = F_9 ( V_29 [ 0 ] ) ;
unsigned int V_44 = 0x00 ;
unsigned int V_45 ;
int V_31 ;
V_5 -> V_46 = 0 ;
if ( F_14 ( V_25 , V_28 ) )
V_5 -> V_46 |= V_47 ;
if ( V_30 == V_39 )
V_5 -> V_46 |= V_48 ;
F_2 ( V_5 -> V_46 , V_2 -> V_22 + V_49 ) ;
F_2 ( 2 , V_2 -> V_22 + V_50 ) ;
F_2 ( 0 , V_2 -> V_22 + V_50 ) ;
F_2 ( 1 , V_2 -> V_22 + V_50 ) ;
if ( V_41 ) {
V_45 = F_15 ( V_43 ) |
F_16 ( V_28 ) ;
V_44 = V_5 -> V_51 ;
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ ) {
F_2 ( V_45 | V_44 , V_2 -> V_22 + V_52 ) ;
V_44 = V_5 -> V_53 ;
}
}
for ( V_31 = 0 ; V_31 < V_40 ; V_31 ++ ) {
unsigned int V_33 = F_10 ( V_29 [ V_31 ] ) ;
unsigned int V_34 = F_8 ( V_29 [ V_31 ] ) ;
V_45 = F_15 ( V_33 ) |
F_16 ( V_34 ) ;
F_2 ( V_45 | V_44 , V_2 -> V_22 + V_52 ) ;
}
if ( V_42 ) {
V_45 = F_15 ( V_43 ) |
F_16 ( V_28 ) ;
for ( V_31 = 0 ; V_31 < V_42 ; V_31 ++ )
F_2 ( V_45 | V_44 , V_2 -> V_22 + V_52 ) ;
}
F_2 ( 0 , V_2 -> V_22 + V_50 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned int V_54 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_54 ] ;
V_5 -> V_55 = V_56 | V_57 |
V_58 ;
F_2 ( V_5 -> V_55 , V_2 -> V_22 + V_59 ) ;
F_18 ( V_2 -> V_60 , 0 , V_8 -> V_9 >> 1 ,
V_61 | V_62 ) ;
V_5 -> V_55 |= V_63 ;
F_2 ( V_5 -> V_55 , V_2 -> V_22 + V_59 ) ;
}
static unsigned int F_19 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
unsigned int V_64 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_26 * V_27 = & V_25 -> V_65 -> V_27 ;
unsigned int V_66 = V_5 -> V_67 ;
unsigned int V_68 = V_66 + V_27 -> V_32 ;
unsigned int V_69 = V_68 + V_5 -> V_70 ;
unsigned int V_71 = V_5 -> V_72 ;
unsigned int V_73 , V_74 , V_75 ;
if ( V_69 == V_27 -> V_32 )
return V_64 ;
V_73 = V_64 / V_69 ;
V_74 = V_73 * V_27 -> V_32 ;
V_64 -= V_73 * V_69 ;
while ( V_64 ) {
if ( V_71 < V_66 ) {
V_75 = V_66 - V_71 ;
if ( V_75 > V_64 )
V_75 = V_64 ;
V_71 += V_75 ;
V_64 -= V_75 ;
if ( ! V_64 )
break;
}
if ( V_71 < V_68 ) {
V_75 = V_68 - V_71 ;
if ( V_75 > V_64 )
V_75 = V_64 ;
V_74 += V_75 ;
V_71 += V_75 ;
V_64 -= V_75 ;
}
V_66 += V_69 ;
V_68 += V_69 ;
}
return V_74 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
unsigned short * V_76 ,
unsigned int V_64 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_26 * V_27 = & V_25 -> V_65 -> V_27 ;
unsigned int V_66 = V_5 -> V_67 ;
unsigned int V_68 = V_66 + V_27 -> V_32 ;
unsigned int V_69 = V_68 + V_5 -> V_70 ;
unsigned int V_71 = V_5 -> V_72 ;
unsigned int V_75 ;
if ( V_69 == V_27 -> V_32 ) {
F_21 ( V_25 , V_76 , V_64 ) ;
V_71 += V_64 ;
} else {
while ( V_64 ) {
if ( V_71 < V_66 ) {
V_75 = V_66 - V_71 ;
if ( V_75 > V_64 )
V_75 = V_64 ;
V_71 += V_75 ;
V_64 -= V_75 ;
if ( ! V_64 )
break;
}
if ( V_71 < V_68 ) {
V_75 = V_68 - V_71 ;
if ( V_75 > V_64 )
V_75 = V_64 ;
F_21 ( V_25 , V_76 , V_75 ) ;
V_71 += V_75 ;
V_64 -= V_75 ;
}
V_66 += V_69 ;
V_68 += V_69 ;
}
}
V_5 -> V_72 = V_71 % V_69 ;
}
static void F_22 ( struct V_1 * V_2 , bool V_14 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_14 )
V_5 -> V_77 |= V_78 ;
else
V_5 -> V_77 &= ~ V_78 ;
F_2 ( V_5 -> V_77 , V_2 -> V_22 + V_79 ) ;
if ( V_5 -> V_77 )
F_5 ( V_2 , true ) ;
else
F_5 ( V_2 , false ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
unsigned int * V_80 , unsigned int * V_81 ,
unsigned int V_82 , int V_83 ,
unsigned int * V_84 , unsigned int * V_85 ,
unsigned int V_86 )
{
struct V_87 * V_60 = V_2 -> V_60 ;
struct V_26 * V_27 = & V_25 -> V_65 -> V_27 ;
* V_84 = * V_81 / V_60 -> V_88 ;
* V_85 = * V_80 / V_60 -> V_88 ;
* V_85 = * V_85 / * V_84 ;
if ( * V_85 < V_83 )
* V_85 = V_83 ;
* V_81 = * V_84 * V_60 -> V_88 ;
if ( V_27 -> V_89 == V_90 && ! V_86 ) {
if ( * V_85 < ( V_83 + 2 ) )
* V_85 = V_83 + 2 ;
}
* V_80 = * V_84 * * V_85 * V_60 -> V_88 ;
}
static void F_24 ( struct V_1 * V_2 , int V_91 )
{
if ( V_91 == 1 || V_91 == 2 || V_91 == 4 )
F_25 ( V_2 -> V_60 , 1 , 2 , true ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_92 )
F_3 ( V_2 , false ) ;
F_22 ( V_2 , false ) ;
F_25 ( V_2 -> V_60 , 1 , 2 , false ) ;
V_5 -> V_55 = V_56 | V_57 ;
F_2 ( V_5 -> V_55 , V_2 -> V_22 + V_59 ) ;
V_5 -> V_46 = 0 ;
F_2 ( V_5 -> V_46 , V_2 -> V_22 + V_49 ) ;
F_2 ( 0 , V_2 -> V_22 + V_93 ) ;
F_2 ( 1 , V_2 -> V_22 + V_50 ) ;
F_2 ( 2 , V_2 -> V_22 + V_50 ) ;
F_6 ( V_2 ) ;
V_5 -> V_77 = 0 ;
F_2 ( V_5 -> V_77 , V_2 -> V_22 + V_79 ) ;
F_5 ( V_2 , false ) ;
V_5 -> V_94 = 0 ;
V_5 -> V_92 = 0 ;
V_5 -> V_72 = 0 ;
V_25 -> V_65 -> V_95 = NULL ;
V_5 -> V_96 = 0 ;
V_5 -> V_97 = 0 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_24 * V_25 , void * V_98 ,
unsigned int V_99 ,
unsigned int V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned short * V_101 = V_98 ;
unsigned int V_102 = F_28 ( V_25 , V_99 ) ;
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_102 ; V_31 ++ ) {
if ( V_5 -> V_92 )
V_101 [ V_31 ] = F_29 ( V_101 [ V_31 ] ) ;
if ( V_25 -> V_103 == 0xffff )
V_101 [ V_31 ] ^= 0x8000 ;
else
V_101 [ V_31 ] = ( V_101 [ V_31 ] >> 4 ) & 0x0fff ;
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_26 * V_27 = & V_25 -> V_65 -> V_27 ;
unsigned short V_104 ;
V_104 = F_4 ( V_2 -> V_22 + V_105 ) ;
F_21 ( V_25 , & V_104 , 1 ) ;
if ( ! V_5 -> V_96 ) {
if ( V_25 -> V_65 -> V_106 >= V_27 -> V_107 )
V_25 -> V_65 -> V_108 |= V_109 ;
}
}
static void F_31 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_26 * V_27 = & V_25 -> V_65 -> V_27 ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_5 -> V_97 ] ;
unsigned int V_110 = F_28 ( V_25 , V_8 -> V_12 ) ;
unsigned int V_111 ;
bool V_112 ;
V_111 = F_19 ( V_2 , V_25 , V_110 ) ;
V_112 = V_111 < F_32 ( V_25 , V_111 + 1 ) ;
if ( V_112 && V_5 -> V_113 ) {
V_5 -> V_97 = 1 - V_5 -> V_97 ;
F_1 ( V_2 , V_5 -> V_97 ) ;
if ( V_5 -> V_94 == 4 )
F_17 ( V_2 , V_5 -> V_97 ) ;
}
if ( V_110 )
F_20 ( V_2 , V_25 , V_8 -> V_114 , V_110 ) ;
if ( ! V_5 -> V_96 ) {
if ( V_25 -> V_65 -> V_106 >= V_27 -> V_107 )
V_25 -> V_65 -> V_108 |= V_109 ;
}
if ( V_25 -> V_65 -> V_108 & V_115 )
V_112 = false ;
if ( V_112 && ! V_5 -> V_113 ) {
F_1 ( V_2 , 0 ) ;
if ( V_5 -> V_94 == 4 )
F_17 ( V_2 , 0 ) ;
}
}
static T_1 F_33 ( int V_116 , void * V_117 )
{
struct V_1 * V_2 = V_117 ;
struct V_24 * V_25 = V_2 -> V_118 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_119 ;
unsigned int V_20 ;
unsigned int V_120 ;
if ( ! V_2 -> V_121 )
return V_122 ;
V_119 = F_4 ( V_2 -> V_22 + V_79 ) & 0xf ;
V_20 = F_4 ( V_5 -> V_10 + V_21 ) ;
if ( ! V_119 && ! ( V_20 & V_123 ) )
return V_122 ;
F_2 ( V_20 | 0x00ff0000 , V_5 -> V_10 + V_21 ) ;
if ( V_20 & V_124 ) {
F_11 ( V_2 -> V_36 , L_4 ) ;
V_25 -> V_65 -> V_108 |= V_125 ;
goto V_126;
}
if ( V_20 & V_127 ) {
F_11 ( V_2 -> V_36 , L_5 ) ;
V_25 -> V_65 -> V_108 |= V_125 ;
goto V_126;
}
V_120 = F_4 ( V_2 -> V_22 + V_128 ) ;
if ( ( V_120 & V_129 ) == 0 ) {
F_11 ( V_2 -> V_36 ,
L_6 ) ;
V_25 -> V_65 -> V_108 |= V_125 | V_130 ;
goto V_126;
}
if ( V_120 & V_131 ) {
F_11 ( V_2 -> V_36 ,
L_7 ) ;
V_25 -> V_65 -> V_108 |= V_125 | V_130 ;
goto V_126;
}
if ( V_120 & V_132 ) {
F_11 ( V_2 -> V_36 , L_8 ) ;
V_25 -> V_65 -> V_108 |= V_125 ;
goto V_126;
}
if ( V_120 & V_133 ) {
F_11 ( V_2 -> V_36 , L_9 ) ;
V_25 -> V_65 -> V_108 |= V_125 | V_130 ;
goto V_126;
}
if ( ! V_5 -> V_94 )
return V_134 ;
if ( V_5 -> V_135 ) {
if ( ( V_120 & V_136 ) &&
( V_119 & V_78 ) ) {
if ( V_5 -> V_135 & V_137 ) {
V_5 -> V_135 &= ~ V_137 ;
if ( ! ( V_5 -> V_135 & V_138 ) )
F_22 ( V_2 , false ) ;
F_24 ( V_2 , V_5 -> V_94 ) ;
F_2 ( V_5 -> V_46 ,
V_2 -> V_22 + V_49 ) ;
} else if ( V_5 -> V_135 & V_138 ) {
V_5 -> V_135 &= ~ V_138 ;
F_22 ( V_2 , false ) ;
V_5 -> V_96 = 0 ;
}
}
}
if ( V_5 -> V_92 )
F_31 ( V_2 , V_25 ) ;
else
F_30 ( V_2 , V_25 ) ;
V_126:
F_34 ( V_2 , V_25 ) ;
return V_134 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 -> V_77 , V_2 -> V_22 + V_79 ) ;
F_2 ( V_5 -> V_55 , V_2 -> V_22 + V_59 ) ;
if ( V_5 -> V_94 != 3 ) {
F_24 ( V_2 , V_5 -> V_94 ) ;
V_5 -> V_46 |= V_139 ;
}
F_2 ( V_5 -> V_46 , V_2 -> V_22 + V_49 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
unsigned int V_140 )
{
struct V_26 * V_27 = & V_25 -> V_65 -> V_27 ;
if ( V_140 != V_27 -> V_141 )
return - V_37 ;
V_25 -> V_65 -> V_95 = NULL ;
F_35 ( V_2 ) ;
return 1 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_26 * V_27 = & V_25 -> V_65 -> V_27 ;
struct V_7 * V_142 = & V_5 -> V_8 [ 0 ] ;
struct V_7 * V_143 = & V_5 -> V_8 [ 1 ] ;
unsigned int V_144 = V_142 -> V_145 ;
unsigned int V_146 = V_143 -> V_145 ;
unsigned int V_147 = V_5 -> V_148 *
F_38 ( V_25 ) ;
if ( V_144 > V_25 -> V_65 -> V_149 ) {
V_144 = V_25 -> V_65 -> V_149 & ~ 3L ;
}
if ( V_146 > V_25 -> V_65 -> V_149 ) {
V_146 = V_25 -> V_65 -> V_149 & ~ 3L ;
}
if ( V_5 -> V_150 & V_151 ) {
if ( V_144 < V_147 ) {
V_5 -> V_150 &= ( ~ V_151 ) ;
F_39 ( V_2 -> V_36 ,
L_10 ,
V_144 , V_147 ) ;
} else {
V_144 = V_147 ;
if ( V_144 < 4 ) {
F_39 ( V_2 -> V_36 ,
L_11 ,
V_144 ) ;
V_144 = 4 ;
}
}
}
if ( V_5 -> V_150 & V_151 ) {
if ( V_146 < V_147 ) {
V_5 -> V_150 &= ( ~ V_151 ) ;
F_39 ( V_2 -> V_36 ,
L_12 ,
V_146 , V_147 ) ;
} else {
V_146 = V_147 ;
if ( V_146 < 4 ) {
F_39 ( V_2 -> V_36 ,
L_13 ,
V_146 ) ;
V_146 = 4 ;
}
}
}
if ( ! ( V_5 -> V_150 & V_151 ) ) {
unsigned int V_152 ;
V_152 = V_144 ;
V_144 = ( V_144 / V_147 ) * V_147 ;
V_144 &= ~ 3L ;
if ( ! V_144 )
V_144 = V_152 ;
V_152 = V_146 ;
V_146 = ( V_146 / V_147 ) * V_147 ;
V_146 &= ~ 3L ;
if ( ! V_146 )
V_146 = V_152 ;
if ( ! V_5 -> V_96 ) {
unsigned long long V_153 ;
V_153 = ( unsigned long long ) V_147 *
V_27 -> V_107 ;
if ( V_144 > V_153 ) {
V_144 = V_153 ;
V_144 &= ~ 3L ;
} else {
if ( V_146 > ( V_153 - V_144 ) ) {
V_146 = V_153 - V_144 ;
V_146 &= ~ 3L ;
}
}
}
}
V_5 -> V_97 = 0 ;
V_142 -> V_12 = V_144 ;
V_143 -> V_12 = V_146 ;
F_3 ( V_2 , false ) ;
F_1 ( V_2 , 0 ) ;
F_2 ( 0x00000000 | V_154 ,
V_5 -> V_10 + V_21 ) ;
F_3 ( V_2 , true ) ;
F_2 ( F_4 ( V_5 -> V_10 + V_21 ) | V_19 ,
V_5 -> V_10 + V_21 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_87 * V_60 = V_2 -> V_60 ;
struct V_26 * V_27 = & V_25 -> V_65 -> V_27 ;
unsigned int V_155 = 0 ;
unsigned int V_153 ;
V_5 -> V_135 = 0 ;
V_5 -> V_150 = V_27 -> V_82 ;
V_5 -> V_67 = 0 ;
V_5 -> V_70 = 0 ;
if ( V_27 -> V_156 == V_157 )
V_5 -> V_135 |= V_137 ;
if ( V_27 -> V_158 == V_157 ) {
V_5 -> V_96 = 1 ;
V_5 -> V_135 |= V_138 ;
}
if ( V_27 -> V_158 == V_159 )
V_5 -> V_96 = 1 ;
if ( V_27 -> V_158 == V_160 )
V_5 -> V_96 = 0 ;
V_5 -> V_67 = 0 ;
V_5 -> V_70 = 0 ;
if ( V_5 -> V_161 ) {
V_5 -> V_92 = 1 ;
if ( ( V_27 -> V_82 & V_151 ) &&
( V_27 -> V_162 == 1 ) ) {
if ( V_27 -> V_89 == V_90 )
V_5 -> V_70 = 1 ;
if ( V_27 -> V_89 == V_163 ) {
V_5 -> V_92 = 0 ;
}
}
if ( ( V_27 -> V_82 & V_151 ) &&
( V_27 -> V_162 & 1 ) &&
( V_27 -> V_162 > 1 ) ) {
if ( V_27 -> V_164 == V_165 ) {
V_5 -> V_92 = 0 ;
} else {
V_5 -> V_70 = 1 ;
}
}
} else {
V_5 -> V_92 = 0 ;
}
if ( V_27 -> V_89 == V_90 && V_5 -> V_166 ) {
V_5 -> V_67 = 2 ;
if ( ( V_5 -> V_92 == 1 ) && ( V_5 -> V_70 == 1 ) ) {
V_5 -> V_67 ++ ;
V_5 -> V_70 = 0 ;
}
if ( V_27 -> V_167 < V_5 -> V_168 )
V_27 -> V_167 = V_5 -> V_168 ;
V_155 = V_5 -> V_166 / V_27 -> V_167 ;
if ( V_5 -> V_166 % V_27 -> V_167 )
V_155 ++ ;
if ( V_155 > ( V_5 -> V_67 - 1 ) ) {
V_5 -> V_67 = V_155 + 1 ;
if ( V_5 -> V_92 == 1 )
if ( ( V_5 -> V_67 +
V_27 -> V_32 +
V_5 -> V_70 ) & 1 )
V_5 -> V_67 ++ ;
}
}
V_153 = V_5 -> V_67 + V_27 -> V_32 +
V_5 -> V_70 ;
V_5 -> V_148 = V_153 *
( V_27 -> V_162 / V_27 -> V_32 ) ;
if ( V_153 > V_25 -> V_169 ) {
F_11 ( V_2 -> V_36 ,
L_14 ) ;
return - V_37 ;
}
F_13 ( V_2 , V_25 , V_27 -> V_32 , V_27 -> V_29 ,
V_5 -> V_67 , V_5 -> V_70 ) ;
V_5 -> V_94 = 0 ;
if ( V_27 -> V_164 != V_163 &&
V_27 -> V_89 == V_163 ) {
if ( V_27 -> V_164 == V_157 )
V_5 -> V_94 = 4 ;
else
V_5 -> V_94 = 1 ;
F_41 ( V_60 , & V_27 -> V_167 ,
V_5 -> V_150 &
V_170 ) ;
F_42 ( V_60 ) ;
V_5 -> V_46 |= V_171 ;
if ( ! V_5 -> V_92 ) {
V_5 -> V_46 |= V_172 ;
V_5 -> V_77 |= V_173 ;
}
if ( V_27 -> V_164 == V_157 ) {
struct V_7 * V_8 = & V_5 -> V_8 [ 0 ] ;
V_5 -> V_55 |= V_58 ;
F_2 ( V_5 -> V_55 , V_2 -> V_22 + V_59 ) ;
F_18 ( V_60 , 0 , V_8 -> V_9 >> 1 ,
V_61 | V_62 ) ;
V_5 -> V_55 |= V_63 ;
}
}
if ( V_27 -> V_164 == V_163 &&
V_27 -> V_89 != V_157 ) {
if ( ! V_5 -> V_92 ) {
F_11 ( V_2 -> V_36 ,
L_15 ) ;
return - V_174 ;
}
V_5 -> V_94 = 2 ;
F_23 ( V_2 , V_25 ,
& V_27 -> V_175 , & V_27 -> V_167 ,
V_5 -> V_150 ,
V_5 -> V_148 ,
& V_60 -> V_176 ,
& V_60 -> V_177 ,
V_5 -> V_67 ) ;
V_5 -> V_46 |= V_171 ;
V_5 -> V_55 |= V_178 | V_179 ;
if ( V_27 -> V_89 == V_90 && ! V_5 -> V_166 )
V_5 -> V_55 |= V_180 ;
F_2 ( V_5 -> V_148 ,
V_2 -> V_22 + V_93 ) ;
}
if ( V_27 -> V_164 == V_165 &&
V_27 -> V_89 == V_157 ) {
V_5 -> V_94 = 3 ;
V_5 -> V_46 |= V_181 ;
}
if ( V_5 -> V_94 == 0 ) {
F_11 ( V_2 -> V_36 ,
L_16 ) ;
return - V_37 ;
}
if ( V_5 -> V_92 )
V_5 -> V_46 |= V_182 ;
V_5 -> V_55 = V_56 | V_57 ;
F_2 ( V_5 -> V_55 , V_2 -> V_22 + V_59 ) ;
F_43 ( 1 ) ;
F_6 ( V_2 ) ;
F_4 ( V_2 -> V_22 + V_128 ) ;
F_4 ( V_2 -> V_22 + V_79 ) ;
V_5 -> V_72 = 0 ;
if ( V_5 -> V_92 ) {
F_37 ( V_2 , V_25 ) ;
F_2 ( 0x02000000 | V_154 ,
V_5 -> V_10 + V_21 ) ;
} else {
F_5 ( V_2 , true ) ;
}
if ( V_27 -> V_156 == V_90 )
F_35 ( V_2 ) ;
else if ( V_27 -> V_156 == V_183 )
V_25 -> V_65 -> V_95 = F_36 ;
if ( V_27 -> V_156 == V_157 || V_27 -> V_158 == V_157 )
F_22 ( V_2 , true ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_184 = 0 ;
unsigned int V_82 ;
unsigned int V_185 ;
V_184 |= F_45 ( & V_27 -> V_156 ,
V_90 | V_157 | V_183 ) ;
V_82 = V_165 ;
if ( V_5 -> V_161 )
V_82 |= V_163 | V_157 ;
V_184 |= F_45 ( & V_27 -> V_164 , V_82 ) ;
V_82 = V_163 | V_157 ;
if ( V_5 -> V_161 )
V_82 |= V_90 ;
V_184 |= F_45 ( & V_27 -> V_89 , V_82 ) ;
V_184 |= F_45 ( & V_27 -> V_186 , V_160 ) ;
V_184 |= F_45 ( & V_27 -> V_158 ,
V_160 | V_159 | V_157 ) ;
if ( V_184 )
return 1 ;
V_184 |= F_46 ( V_27 -> V_156 ) ;
V_184 |= F_46 ( V_27 -> V_164 ) ;
V_184 |= F_46 ( V_27 -> V_89 ) ;
V_184 |= F_46 ( V_27 -> V_158 ) ;
if ( V_27 -> V_156 == V_157 && V_27 -> V_164 == V_157 )
V_184 |= - V_37 ;
if ( ( V_27 -> V_164 & ( V_163 | V_157 ) ) &&
( ! ( V_27 -> V_89 & ( V_163 | V_90 ) ) ) )
V_184 |= - V_37 ;
if ( ( V_27 -> V_164 == V_165 ) &&
( ! ( V_27 -> V_89 & ( V_163 | V_157 ) ) ) )
V_184 |= - V_37 ;
if ( V_27 -> V_158 == V_157 && V_27 -> V_164 == V_157 )
V_184 |= - V_37 ;
if ( V_184 )
return 2 ;
switch ( V_27 -> V_156 ) {
case V_90 :
case V_157 :
V_184 |= F_47 ( & V_27 -> V_141 , 0 ) ;
break;
case V_183 :
break;
}
if ( V_27 -> V_164 & ( V_165 | V_157 ) )
V_184 |= F_47 ( & V_27 -> V_175 , 0 ) ;
if ( ( V_27 -> V_164 == V_163 ) &&
( V_27 -> V_89 == V_163 ) && ( V_27 -> V_162 == 1 ) ) {
V_27 -> V_164 = V_165 ;
V_27 -> V_167 = V_27 -> V_175 ;
V_27 -> V_175 = 0 ;
}
if ( V_27 -> V_164 == V_163 ) {
V_184 |= F_48 ( & V_27 -> V_175 ,
V_5 -> V_168 ) ;
}
if ( V_27 -> V_164 == V_157 ) {
if ( V_27 -> V_175 ) {
V_27 -> V_175 = 0 ;
V_184 |= - V_37 ;
V_184 |= F_49 ( & V_27 -> V_162 ,
65535 ) ;
}
}
if ( V_27 -> V_89 & ( V_163 | V_90 ) ) {
V_184 |= F_48 ( & V_27 -> V_167 ,
V_5 -> V_168 ) ;
}
if ( V_27 -> V_89 == V_157 )
V_184 |= F_47 ( & V_27 -> V_167 , 0 ) ;
if ( V_27 -> V_158 == V_160 )
V_184 |= F_48 ( & V_27 -> V_107 , 1 ) ;
else
V_184 |= F_47 ( & V_27 -> V_107 , 0 ) ;
V_184 |= F_48 ( & V_27 -> V_32 , 1 ) ;
V_184 |= F_48 ( & V_27 -> V_162 ,
V_27 -> V_32 ) ;
if ( ( V_27 -> V_162 % V_27 -> V_32 ) ) {
V_27 -> V_162 =
V_27 -> V_32 * ( V_27 -> V_162 / V_27 -> V_32 ) ;
V_184 |= - V_37 ;
}
if ( V_184 )
return 3 ;
if ( V_27 -> V_164 == V_163 ) {
V_185 = V_27 -> V_175 ;
F_41 ( V_2 -> V_60 , & V_185 , V_27 -> V_82 ) ;
V_184 |= F_47 ( & V_27 -> V_175 , V_185 ) ;
}
if ( V_27 -> V_89 & ( V_163 | V_90 ) ) {
V_185 = V_27 -> V_167 ;
F_41 ( V_2 -> V_60 , & V_185 , V_27 -> V_82 ) ;
V_184 |= F_47 ( & V_27 -> V_167 , V_185 ) ;
if ( V_27 -> V_164 == V_163 &&
V_27 -> V_89 == V_90 ) {
if ( V_27 -> V_167 == 0 ) {
V_185 = V_5 -> V_168 *
( V_27 -> V_162 + 2 ) ;
} else {
V_185 = V_27 -> V_167 * V_27 -> V_32 ;
}
V_184 |= F_48 ( & V_27 ->
V_175 ,
V_185 ) ;
}
}
if ( V_184 )
return 4 ;
if ( V_27 -> V_29 )
V_184 |= F_7 ( V_2 , V_25 , V_27 ) ;
if ( V_184 )
return 5 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_187 * V_188 ,
unsigned long V_189 )
{
unsigned int V_190 ;
V_190 = F_4 ( V_2 -> V_22 + V_128 ) ;
if ( V_190 & V_191 )
return 0 ;
return - V_192 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_22 + V_193 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_187 * V_188 ,
unsigned int * V_98 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_45 ;
int V_194 ;
int V_31 ;
F_13 ( V_2 , V_25 , 1 , & V_188 -> V_195 , 0 , 0 ) ;
V_5 -> V_55 = V_56 | V_57 ;
F_2 ( V_5 -> V_55 , V_2 -> V_22 + V_59 ) ;
F_6 ( V_2 ) ;
for ( V_31 = 0 ; V_31 < V_188 -> V_196 ; V_31 ++ ) {
F_51 ( V_2 ) ;
V_194 = F_53 ( V_2 , V_25 , V_188 , F_50 , 0 ) ;
if ( V_194 )
return V_194 ;
V_45 = F_4 ( V_2 -> V_22 + V_105 ) ;
if ( V_25 -> V_103 == 0xffff )
V_98 [ V_31 ] = ( V_45 & 0xffff ) ^ 0x8000 ;
else
V_98 [ V_31 ] = ( V_45 >> 4 ) & 0xfff ;
}
return V_188 -> V_196 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_187 * V_188 ,
unsigned int * V_98 )
{
unsigned int V_33 = F_10 ( V_188 -> V_195 ) ;
unsigned int V_45 = V_25 -> V_197 [ V_33 ] ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_188 -> V_196 ; V_31 ++ ) {
V_45 = V_98 [ V_31 ] ;
F_2 ( V_45 , V_2 -> V_22 + F_55 ( V_33 ) ) ;
}
V_25 -> V_197 [ V_33 ] = V_45 ;
return V_188 -> V_196 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_187 * V_188 ,
unsigned int * V_98 )
{
V_98 [ 1 ] = F_4 ( V_2 -> V_22 + V_198 ) & 0xf ;
return V_188 -> V_196 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_187 * V_188 ,
unsigned int * V_98 )
{
if ( F_58 ( V_25 , V_98 ) )
F_2 ( V_25 -> V_199 , V_2 -> V_22 + V_198 ) ;
V_98 [ 1 ] = V_25 -> V_199 ;
return V_188 -> V_196 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_22 + V_79 ) ;
F_2 ( 0 , V_2 -> V_22 + V_49 ) ;
F_2 ( 0 , V_2 -> V_22 + V_59 ) ;
F_6 ( V_2 ) ;
F_4 ( V_2 -> V_22 + V_79 ) ;
F_4 ( V_2 -> V_22 + V_128 ) ;
F_2 ( 0 , V_2 -> V_22 + V_93 ) ;
F_2 ( 1 , V_2 -> V_22 + V_50 ) ;
F_2 ( 2 , V_2 -> V_22 + V_50 ) ;
F_2 ( 2047 , V_2 -> V_22 + F_55 ( 0 ) ) ;
F_2 ( 2047 , V_2 -> V_22 + F_55 ( 1 ) ) ;
}
static struct V_200 * F_60 ( struct V_1 * V_2 ,
struct V_201 * V_202 )
{
struct V_200 * V_203 = NULL ;
int V_204 = V_202 -> V_205 [ 0 ] ;
int V_206 = V_202 -> V_205 [ 1 ] ;
F_61 (pcidev) {
if ( V_203 -> V_207 != V_208 )
continue;
if ( V_203 -> V_209 != 0x80d9 )
continue;
if ( V_204 || V_206 ) {
if ( V_203 -> V_204 -> V_210 != V_204 ||
F_62 ( V_203 -> V_211 ) != V_206 )
continue;
}
return V_203 ;
}
F_11 ( V_2 -> V_36 ,
L_17 ,
V_204 , V_206 ) ;
return NULL ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_212 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < 2 ; V_31 ++ ) {
V_8 = & V_5 -> V_8 [ V_31 ] ;
for ( V_212 = 2 ; V_212 >= 0 ; V_212 -- ) {
V_8 -> V_114 =
F_64 ( V_2 -> V_213 , V_214 << V_212 ,
& V_8 -> V_9 , V_215 ) ;
if ( V_8 -> V_114 )
break;
}
if ( ! V_8 -> V_114 )
break;
V_8 -> V_145 = V_214 << V_212 ;
if ( V_31 == 0 )
V_5 -> V_161 = 1 ;
if ( V_31 == 1 )
V_5 -> V_113 = 1 ;
}
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_31 ;
if ( ! V_5 )
return;
for ( V_31 = 0 ; V_31 < 2 ; V_31 ++ ) {
V_8 = & V_5 -> V_8 [ V_31 ] ;
if ( V_8 -> V_114 ) {
F_66 ( V_2 -> V_213 , V_8 -> V_145 ,
V_8 -> V_114 , V_8 -> V_9 ) ;
}
}
}
static int F_67 ( struct V_1 * V_2 ,
int V_216 , int V_166 )
{
const struct V_217 * V_218 = V_2 -> V_219 ;
struct V_200 * V_203 = F_68 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_24 * V_25 ;
int V_194 ;
int V_31 ;
T_2 V_220 ;
V_5 = F_69 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_221 ;
V_194 = F_70 ( V_2 ) ;
if ( V_194 )
return V_194 ;
F_71 ( V_203 ) ;
V_5 -> V_10 = F_72 ( V_203 , 0 ) ;
V_2 -> V_22 = F_72 ( V_203 , 2 ) ;
V_2 -> V_60 = F_73 ( V_2 -> V_22 + V_222 ,
V_223 , V_224 , 0 ) ;
if ( ! V_2 -> V_60 )
return - V_221 ;
F_59 ( V_2 ) ;
if ( V_203 -> V_116 ) {
V_194 = F_74 ( V_203 -> V_116 , F_33 , V_225 ,
V_2 -> V_226 , V_2 ) ;
if ( V_194 == 0 ) {
V_2 -> V_116 = V_203 -> V_116 ;
F_63 ( V_2 ) ;
}
}
if ( V_216 > 0 ) {
if ( V_216 > 256 )
V_216 = 256 ;
if ( V_166 > 0 )
if ( V_216 > 128 )
V_216 = 128 ;
V_5 -> V_38 = 1 ;
} else {
V_5 -> V_38 = 0 ;
}
if ( V_166 < 0 ) {
V_5 -> V_166 = - V_166 ;
V_5 -> V_51 = 0x80 ;
V_5 -> V_53 = 0x00 ;
} else {
V_5 -> V_166 = V_166 ;
V_5 -> V_51 = 0x00 ;
V_5 -> V_53 = 0x80 ;
}
F_75 ( V_203 , V_227 , & V_220 ) ;
F_76 ( V_203 , V_227 , V_220 | 64 ) ;
V_194 = F_77 ( V_2 , 4 ) ;
if ( V_194 )
return V_194 ;
V_25 = & V_2 -> V_228 [ 0 ] ;
V_25 -> type = V_229 ;
V_25 -> V_230 = V_231 | V_232 | V_233 | V_234 ;
V_25 -> V_40 = ( V_5 -> V_38 ) ? V_216 : 16 ;
V_25 -> V_103 = V_218 -> V_235 ? 0xffff : 0x0fff ;
V_25 -> V_236 = V_218 -> V_237 ? & V_238
: & V_239 ;
V_25 -> V_240 = F_52 ;
if ( V_2 -> V_116 ) {
V_2 -> V_118 = V_25 ;
V_25 -> V_230 |= V_241 ;
V_25 -> V_169 = 255 ;
V_25 -> V_242 = F_44 ;
V_25 -> V_243 = F_40 ;
V_25 -> V_244 = F_26 ;
V_25 -> V_245 = F_27 ;
}
if ( V_25 -> V_103 == 0xffff ) {
V_5 -> V_168 = 10000 ;
} else {
V_5 -> V_168 = 3000 ;
}
V_25 = & V_2 -> V_228 [ 1 ] ;
V_25 -> type = V_246 ;
V_25 -> V_230 = V_247 | V_233 | V_232 ;
V_25 -> V_40 = 2 ;
V_25 -> V_103 = 0x0fff ;
V_25 -> V_236 = & V_248 ;
V_25 -> V_249 = F_54 ;
V_194 = F_78 ( V_25 ) ;
if ( V_194 )
return V_194 ;
for ( V_31 = 0 ; V_31 < V_25 -> V_40 ; V_31 ++ )
V_25 -> V_197 [ V_31 ] = 2047 ;
V_25 = & V_2 -> V_228 [ 2 ] ;
V_25 -> type = V_250 ;
V_25 -> V_230 = V_231 ;
V_25 -> V_40 = 4 ;
V_25 -> V_103 = 1 ;
V_25 -> V_236 = & V_251 ;
V_25 -> V_252 = F_56 ;
V_25 = & V_2 -> V_228 [ 3 ] ;
V_25 -> type = V_253 ;
V_25 -> V_230 = V_247 ;
V_25 -> V_40 = 4 ;
V_25 -> V_103 = 1 ;
V_25 -> V_236 = & V_251 ;
V_25 -> V_252 = F_57 ;
V_25 -> V_199 = F_4 ( V_2 -> V_22 + V_198 ) >> 4 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_201 * V_202 )
{
struct V_200 * V_203 ;
int V_216 , V_166 ;
V_216 = V_202 -> V_205 [ 2 ] ;
V_166 = V_202 -> V_205 [ 4 ] ;
V_203 = F_60 ( V_2 , V_202 ) ;
if ( ! V_203 )
return - V_174 ;
F_80 ( V_2 , & V_203 -> V_2 ) ;
return F_67 ( V_2 , V_216 , V_166 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
unsigned long V_189 )
{
struct V_200 * V_203 = F_68 ( V_2 ) ;
const struct V_217 * V_218 = NULL ;
if ( V_189 < F_82 ( V_254 ) )
V_218 = & V_254 [ V_189 ] ;
if ( ! V_218 )
return - V_255 ;
V_2 -> V_219 = V_218 ;
V_2 -> V_226 = V_218 -> V_256 ;
F_83 ( V_203 ) ;
return F_67 ( V_2 , 0 , 0 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_200 * V_203 = F_68 ( V_2 ) ;
if ( V_2 -> V_22 )
F_59 ( V_2 ) ;
F_85 ( V_2 ) ;
F_65 ( V_2 ) ;
if ( V_203 )
F_86 ( V_203 ) ;
}
static int F_87 ( struct V_200 * V_2 ,
const struct V_257 * V_258 )
{
return F_88 ( V_2 , & V_259 ,
V_258 -> V_260 ) ;
}
