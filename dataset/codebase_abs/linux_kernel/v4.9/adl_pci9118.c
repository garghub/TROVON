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
T_1 * V_103 = V_98 ;
for ( V_31 = 0 ; V_31 < V_102 ; V_31 ++ ) {
if ( V_5 -> V_92 )
V_101 [ V_31 ] = F_29 ( V_103 [ V_31 ] ) ;
if ( V_25 -> V_104 == 0xffff )
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
unsigned short V_105 ;
V_105 = F_4 ( V_2 -> V_22 + V_106 ) ;
F_21 ( V_25 , & V_105 , 1 ) ;
if ( ! V_5 -> V_96 ) {
if ( V_25 -> V_65 -> V_107 >= V_27 -> V_108 )
V_25 -> V_65 -> V_109 |= V_110 ;
}
}
static void F_31 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_26 * V_27 = & V_25 -> V_65 -> V_27 ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_5 -> V_97 ] ;
unsigned int V_111 = F_28 ( V_25 , V_8 -> V_12 ) ;
unsigned int V_112 ;
bool V_113 ;
V_112 = F_19 ( V_2 , V_25 , V_111 ) ;
V_113 = V_112 < F_32 ( V_25 , V_112 + 1 ) ;
if ( V_113 && V_5 -> V_114 ) {
V_5 -> V_97 = 1 - V_5 -> V_97 ;
F_1 ( V_2 , V_5 -> V_97 ) ;
if ( V_5 -> V_94 == 4 )
F_17 ( V_2 , V_5 -> V_97 ) ;
}
if ( V_111 )
F_20 ( V_2 , V_25 , V_8 -> V_115 , V_111 ) ;
if ( ! V_5 -> V_96 ) {
if ( V_25 -> V_65 -> V_107 >= V_27 -> V_108 )
V_25 -> V_65 -> V_109 |= V_110 ;
}
if ( V_25 -> V_65 -> V_109 & V_116 )
V_113 = false ;
if ( V_113 && ! V_5 -> V_114 ) {
F_1 ( V_2 , 0 ) ;
if ( V_5 -> V_94 == 4 )
F_17 ( V_2 , 0 ) ;
}
}
static T_2 F_33 ( int V_117 , void * V_118 )
{
struct V_1 * V_2 = V_118 ;
struct V_24 * V_25 = V_2 -> V_119 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_120 ;
unsigned int V_20 ;
unsigned int V_121 ;
if ( ! V_2 -> V_122 )
return V_123 ;
V_120 = F_4 ( V_2 -> V_22 + V_79 ) & 0xf ;
V_20 = F_4 ( V_5 -> V_10 + V_21 ) ;
if ( ! V_120 && ! ( V_20 & V_124 ) )
return V_123 ;
F_2 ( V_20 | 0x00ff0000 , V_5 -> V_10 + V_21 ) ;
if ( V_20 & V_125 ) {
F_11 ( V_2 -> V_36 , L_4 ) ;
V_25 -> V_65 -> V_109 |= V_126 ;
goto V_127;
}
if ( V_20 & V_128 ) {
F_11 ( V_2 -> V_36 , L_5 ) ;
V_25 -> V_65 -> V_109 |= V_126 ;
goto V_127;
}
V_121 = F_4 ( V_2 -> V_22 + V_129 ) ;
if ( ( V_121 & V_130 ) == 0 ) {
F_11 ( V_2 -> V_36 ,
L_6 ) ;
V_25 -> V_65 -> V_109 |= V_126 | V_131 ;
goto V_127;
}
if ( V_121 & V_132 ) {
F_11 ( V_2 -> V_36 ,
L_7 ) ;
V_25 -> V_65 -> V_109 |= V_126 | V_131 ;
goto V_127;
}
if ( V_121 & V_133 ) {
F_11 ( V_2 -> V_36 , L_8 ) ;
V_25 -> V_65 -> V_109 |= V_126 ;
goto V_127;
}
if ( V_121 & V_134 ) {
F_11 ( V_2 -> V_36 , L_9 ) ;
V_25 -> V_65 -> V_109 |= V_126 | V_131 ;
goto V_127;
}
if ( ! V_5 -> V_94 )
return V_135 ;
if ( V_5 -> V_136 ) {
if ( ( V_121 & V_137 ) &&
( V_120 & V_78 ) ) {
if ( V_5 -> V_136 & V_138 ) {
V_5 -> V_136 &= ~ V_138 ;
if ( ! ( V_5 -> V_136 & V_139 ) )
F_22 ( V_2 , false ) ;
F_24 ( V_2 , V_5 -> V_94 ) ;
F_2 ( V_5 -> V_46 ,
V_2 -> V_22 + V_49 ) ;
} else if ( V_5 -> V_136 & V_139 ) {
V_5 -> V_136 &= ~ V_139 ;
F_22 ( V_2 , false ) ;
V_5 -> V_96 = 0 ;
}
}
}
if ( V_5 -> V_92 )
F_31 ( V_2 , V_25 ) ;
else
F_30 ( V_2 , V_25 ) ;
V_127:
F_34 ( V_2 , V_25 ) ;
return V_135 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 -> V_77 , V_2 -> V_22 + V_79 ) ;
F_2 ( V_5 -> V_55 , V_2 -> V_22 + V_59 ) ;
if ( V_5 -> V_94 != 3 ) {
F_24 ( V_2 , V_5 -> V_94 ) ;
V_5 -> V_46 |= V_140 ;
}
F_2 ( V_5 -> V_46 , V_2 -> V_22 + V_49 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
unsigned int V_141 )
{
struct V_26 * V_27 = & V_25 -> V_65 -> V_27 ;
if ( V_141 != V_27 -> V_142 )
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
struct V_7 * V_143 = & V_5 -> V_8 [ 0 ] ;
struct V_7 * V_144 = & V_5 -> V_8 [ 1 ] ;
unsigned int V_145 = V_143 -> V_146 ;
unsigned int V_147 = V_144 -> V_146 ;
unsigned int V_148 = V_5 -> V_149 *
F_38 ( V_25 ) ;
if ( V_145 > V_25 -> V_65 -> V_150 ) {
V_145 = V_25 -> V_65 -> V_150 & ~ 3L ;
}
if ( V_147 > V_25 -> V_65 -> V_150 ) {
V_147 = V_25 -> V_65 -> V_150 & ~ 3L ;
}
if ( V_5 -> V_151 & V_152 ) {
if ( V_145 < V_148 ) {
V_5 -> V_151 &= ( ~ V_152 ) ;
F_39 ( V_2 -> V_36 ,
L_10 ,
V_145 , V_148 ) ;
} else {
V_145 = V_148 ;
if ( V_145 < 4 ) {
F_39 ( V_2 -> V_36 ,
L_11 ,
V_145 ) ;
V_145 = 4 ;
}
}
}
if ( V_5 -> V_151 & V_152 ) {
if ( V_147 < V_148 ) {
V_5 -> V_151 &= ( ~ V_152 ) ;
F_39 ( V_2 -> V_36 ,
L_12 ,
V_147 , V_148 ) ;
} else {
V_147 = V_148 ;
if ( V_147 < 4 ) {
F_39 ( V_2 -> V_36 ,
L_13 ,
V_147 ) ;
V_147 = 4 ;
}
}
}
if ( ! ( V_5 -> V_151 & V_152 ) ) {
unsigned int V_153 ;
V_153 = V_145 ;
V_145 = ( V_145 / V_148 ) * V_148 ;
V_145 &= ~ 3L ;
if ( ! V_145 )
V_145 = V_153 ;
V_153 = V_147 ;
V_147 = ( V_147 / V_148 ) * V_148 ;
V_147 &= ~ 3L ;
if ( ! V_147 )
V_147 = V_153 ;
if ( ! V_5 -> V_96 ) {
unsigned long long V_154 ;
V_154 = ( unsigned long long ) V_148 *
V_27 -> V_108 ;
if ( V_145 > V_154 ) {
V_145 = V_154 ;
V_145 &= ~ 3L ;
} else {
if ( V_147 > ( V_154 - V_145 ) ) {
V_147 = V_154 - V_145 ;
V_147 &= ~ 3L ;
}
}
}
}
V_5 -> V_97 = 0 ;
V_143 -> V_12 = V_145 ;
V_144 -> V_12 = V_147 ;
F_3 ( V_2 , false ) ;
F_1 ( V_2 , 0 ) ;
F_2 ( 0x00000000 | V_155 ,
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
unsigned int V_156 = 0 ;
unsigned int V_154 ;
V_5 -> V_136 = 0 ;
V_5 -> V_151 = V_27 -> V_82 ;
V_5 -> V_67 = 0 ;
V_5 -> V_70 = 0 ;
if ( V_27 -> V_157 == V_158 )
V_5 -> V_136 |= V_138 ;
if ( V_27 -> V_159 == V_158 ) {
V_5 -> V_96 = 1 ;
V_5 -> V_136 |= V_139 ;
}
if ( V_27 -> V_159 == V_160 )
V_5 -> V_96 = 1 ;
if ( V_27 -> V_159 == V_161 )
V_5 -> V_96 = 0 ;
V_5 -> V_67 = 0 ;
V_5 -> V_70 = 0 ;
if ( V_5 -> V_162 ) {
V_5 -> V_92 = 1 ;
if ( ( V_27 -> V_82 & V_152 ) &&
( V_27 -> V_163 == 1 ) ) {
if ( V_27 -> V_89 == V_90 )
V_5 -> V_70 = 1 ;
if ( V_27 -> V_89 == V_164 ) {
V_5 -> V_92 = 0 ;
}
}
if ( ( V_27 -> V_82 & V_152 ) &&
( V_27 -> V_163 & 1 ) &&
( V_27 -> V_163 > 1 ) ) {
if ( V_27 -> V_165 == V_166 ) {
V_5 -> V_92 = 0 ;
} else {
V_5 -> V_70 = 1 ;
}
}
} else {
V_5 -> V_92 = 0 ;
}
if ( V_27 -> V_89 == V_90 && V_5 -> V_167 ) {
V_5 -> V_67 = 2 ;
if ( ( V_5 -> V_92 == 1 ) && ( V_5 -> V_70 == 1 ) ) {
V_5 -> V_67 ++ ;
V_5 -> V_70 = 0 ;
}
if ( V_27 -> V_168 < V_5 -> V_169 )
V_27 -> V_168 = V_5 -> V_169 ;
V_156 = V_5 -> V_167 / V_27 -> V_168 ;
if ( V_5 -> V_167 % V_27 -> V_168 )
V_156 ++ ;
if ( V_156 > ( V_5 -> V_67 - 1 ) ) {
V_5 -> V_67 = V_156 + 1 ;
if ( V_5 -> V_92 == 1 )
if ( ( V_5 -> V_67 +
V_27 -> V_32 +
V_5 -> V_70 ) & 1 )
V_5 -> V_67 ++ ;
}
}
V_154 = V_5 -> V_67 + V_27 -> V_32 +
V_5 -> V_70 ;
V_5 -> V_149 = V_154 *
( V_27 -> V_163 / V_27 -> V_32 ) ;
if ( V_154 > V_25 -> V_170 ) {
F_11 ( V_2 -> V_36 ,
L_14 ) ;
return - V_37 ;
}
F_13 ( V_2 , V_25 , V_27 -> V_32 , V_27 -> V_29 ,
V_5 -> V_67 , V_5 -> V_70 ) ;
V_5 -> V_94 = 0 ;
if ( V_27 -> V_165 != V_164 &&
V_27 -> V_89 == V_164 ) {
if ( V_27 -> V_165 == V_158 )
V_5 -> V_94 = 4 ;
else
V_5 -> V_94 = 1 ;
F_41 ( V_60 , & V_27 -> V_168 ,
V_5 -> V_151 &
V_171 ) ;
F_42 ( V_60 ) ;
V_5 -> V_46 |= V_172 ;
if ( ! V_5 -> V_92 ) {
V_5 -> V_46 |= V_173 ;
V_5 -> V_77 |= V_174 ;
}
if ( V_27 -> V_165 == V_158 ) {
struct V_7 * V_8 = & V_5 -> V_8 [ 0 ] ;
V_5 -> V_55 |= V_58 ;
F_2 ( V_5 -> V_55 , V_2 -> V_22 + V_59 ) ;
F_18 ( V_60 , 0 , V_8 -> V_9 >> 1 ,
V_61 | V_62 ) ;
V_5 -> V_55 |= V_63 ;
}
}
if ( V_27 -> V_165 == V_164 &&
V_27 -> V_89 != V_158 ) {
if ( ! V_5 -> V_92 ) {
F_11 ( V_2 -> V_36 ,
L_15 ) ;
return - V_175 ;
}
V_5 -> V_94 = 2 ;
F_23 ( V_2 , V_25 ,
& V_27 -> V_176 , & V_27 -> V_168 ,
V_5 -> V_151 ,
V_5 -> V_149 ,
& V_60 -> V_177 ,
& V_60 -> V_178 ,
V_5 -> V_67 ) ;
V_5 -> V_46 |= V_172 ;
V_5 -> V_55 |= V_179 | V_180 ;
if ( V_27 -> V_89 == V_90 && ! V_5 -> V_167 )
V_5 -> V_55 |= V_181 ;
F_2 ( V_5 -> V_149 ,
V_2 -> V_22 + V_93 ) ;
}
if ( V_27 -> V_165 == V_166 &&
V_27 -> V_89 == V_158 ) {
V_5 -> V_94 = 3 ;
V_5 -> V_46 |= V_182 ;
}
if ( V_5 -> V_94 == 0 ) {
F_11 ( V_2 -> V_36 ,
L_16 ) ;
return - V_37 ;
}
if ( V_5 -> V_92 )
V_5 -> V_46 |= V_183 ;
V_5 -> V_55 = V_56 | V_57 ;
F_2 ( V_5 -> V_55 , V_2 -> V_22 + V_59 ) ;
F_43 ( 1 ) ;
F_6 ( V_2 ) ;
F_4 ( V_2 -> V_22 + V_129 ) ;
F_4 ( V_2 -> V_22 + V_79 ) ;
V_5 -> V_72 = 0 ;
if ( V_5 -> V_92 ) {
F_37 ( V_2 , V_25 ) ;
F_2 ( 0x02000000 | V_155 ,
V_5 -> V_10 + V_21 ) ;
} else {
F_5 ( V_2 , true ) ;
}
if ( V_27 -> V_157 == V_90 )
F_35 ( V_2 ) ;
else if ( V_27 -> V_157 == V_184 )
V_25 -> V_65 -> V_95 = F_36 ;
if ( V_27 -> V_157 == V_158 || V_27 -> V_159 == V_158 )
F_22 ( V_2 , true ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_185 = 0 ;
unsigned int V_82 ;
unsigned int V_186 ;
V_185 |= F_45 ( & V_27 -> V_157 ,
V_90 | V_158 | V_184 ) ;
V_82 = V_166 ;
if ( V_5 -> V_162 )
V_82 |= V_164 | V_158 ;
V_185 |= F_45 ( & V_27 -> V_165 , V_82 ) ;
V_82 = V_164 | V_158 ;
if ( V_5 -> V_162 )
V_82 |= V_90 ;
V_185 |= F_45 ( & V_27 -> V_89 , V_82 ) ;
V_185 |= F_45 ( & V_27 -> V_187 , V_161 ) ;
V_185 |= F_45 ( & V_27 -> V_159 ,
V_161 | V_160 | V_158 ) ;
if ( V_185 )
return 1 ;
V_185 |= F_46 ( V_27 -> V_157 ) ;
V_185 |= F_46 ( V_27 -> V_165 ) ;
V_185 |= F_46 ( V_27 -> V_89 ) ;
V_185 |= F_46 ( V_27 -> V_159 ) ;
if ( V_27 -> V_157 == V_158 && V_27 -> V_165 == V_158 )
V_185 |= - V_37 ;
if ( ( V_27 -> V_165 & ( V_164 | V_158 ) ) &&
( ! ( V_27 -> V_89 & ( V_164 | V_90 ) ) ) )
V_185 |= - V_37 ;
if ( ( V_27 -> V_165 == V_166 ) &&
( ! ( V_27 -> V_89 & ( V_164 | V_158 ) ) ) )
V_185 |= - V_37 ;
if ( V_27 -> V_159 == V_158 && V_27 -> V_165 == V_158 )
V_185 |= - V_37 ;
if ( V_185 )
return 2 ;
switch ( V_27 -> V_157 ) {
case V_90 :
case V_158 :
V_185 |= F_47 ( & V_27 -> V_142 , 0 ) ;
break;
case V_184 :
break;
}
if ( V_27 -> V_165 & ( V_166 | V_158 ) )
V_185 |= F_47 ( & V_27 -> V_176 , 0 ) ;
if ( ( V_27 -> V_165 == V_164 ) &&
( V_27 -> V_89 == V_164 ) && ( V_27 -> V_163 == 1 ) ) {
V_27 -> V_165 = V_166 ;
V_27 -> V_168 = V_27 -> V_176 ;
V_27 -> V_176 = 0 ;
}
if ( V_27 -> V_165 == V_164 ) {
V_185 |= F_48 ( & V_27 -> V_176 ,
V_5 -> V_169 ) ;
}
if ( V_27 -> V_165 == V_158 ) {
if ( V_27 -> V_176 ) {
V_27 -> V_176 = 0 ;
V_185 |= - V_37 ;
V_185 |= F_49 ( & V_27 -> V_163 ,
65535 ) ;
}
}
if ( V_27 -> V_89 & ( V_164 | V_90 ) ) {
V_185 |= F_48 ( & V_27 -> V_168 ,
V_5 -> V_169 ) ;
}
if ( V_27 -> V_89 == V_158 )
V_185 |= F_47 ( & V_27 -> V_168 , 0 ) ;
if ( V_27 -> V_159 == V_161 )
V_185 |= F_48 ( & V_27 -> V_108 , 1 ) ;
else
V_185 |= F_47 ( & V_27 -> V_108 , 0 ) ;
V_185 |= F_48 ( & V_27 -> V_32 , 1 ) ;
V_185 |= F_48 ( & V_27 -> V_163 ,
V_27 -> V_32 ) ;
if ( ( V_27 -> V_163 % V_27 -> V_32 ) ) {
V_27 -> V_163 =
V_27 -> V_32 * ( V_27 -> V_163 / V_27 -> V_32 ) ;
V_185 |= - V_37 ;
}
if ( V_185 )
return 3 ;
if ( V_27 -> V_165 == V_164 ) {
V_186 = V_27 -> V_176 ;
F_41 ( V_2 -> V_60 , & V_186 , V_27 -> V_82 ) ;
V_185 |= F_47 ( & V_27 -> V_176 , V_186 ) ;
}
if ( V_27 -> V_89 & ( V_164 | V_90 ) ) {
V_186 = V_27 -> V_168 ;
F_41 ( V_2 -> V_60 , & V_186 , V_27 -> V_82 ) ;
V_185 |= F_47 ( & V_27 -> V_168 , V_186 ) ;
if ( V_27 -> V_165 == V_164 &&
V_27 -> V_89 == V_90 ) {
if ( V_27 -> V_168 == 0 ) {
V_186 = V_5 -> V_169 *
( V_27 -> V_163 + 2 ) ;
} else {
V_186 = V_27 -> V_168 * V_27 -> V_32 ;
}
V_185 |= F_48 ( & V_27 ->
V_176 ,
V_186 ) ;
}
}
if ( V_185 )
return 4 ;
if ( V_27 -> V_29 )
V_185 |= F_7 ( V_2 , V_25 , V_27 ) ;
if ( V_185 )
return 5 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_188 * V_189 ,
unsigned long V_190 )
{
unsigned int V_191 ;
V_191 = F_4 ( V_2 -> V_22 + V_129 ) ;
if ( V_191 & V_192 )
return 0 ;
return - V_193 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_22 + V_194 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_188 * V_189 ,
unsigned int * V_98 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_45 ;
int V_195 ;
int V_31 ;
F_13 ( V_2 , V_25 , 1 , & V_189 -> V_196 , 0 , 0 ) ;
V_5 -> V_55 = V_56 | V_57 ;
F_2 ( V_5 -> V_55 , V_2 -> V_22 + V_59 ) ;
F_6 ( V_2 ) ;
for ( V_31 = 0 ; V_31 < V_189 -> V_197 ; V_31 ++ ) {
F_51 ( V_2 ) ;
V_195 = F_53 ( V_2 , V_25 , V_189 , F_50 , 0 ) ;
if ( V_195 )
return V_195 ;
V_45 = F_4 ( V_2 -> V_22 + V_106 ) ;
if ( V_25 -> V_104 == 0xffff )
V_98 [ V_31 ] = ( V_45 & 0xffff ) ^ 0x8000 ;
else
V_98 [ V_31 ] = ( V_45 >> 4 ) & 0xfff ;
}
return V_189 -> V_197 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_188 * V_189 ,
unsigned int * V_98 )
{
unsigned int V_33 = F_10 ( V_189 -> V_196 ) ;
unsigned int V_45 = V_25 -> V_198 [ V_33 ] ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_189 -> V_197 ; V_31 ++ ) {
V_45 = V_98 [ V_31 ] ;
F_2 ( V_45 , V_2 -> V_22 + F_55 ( V_33 ) ) ;
}
V_25 -> V_198 [ V_33 ] = V_45 ;
return V_189 -> V_197 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_188 * V_189 ,
unsigned int * V_98 )
{
V_98 [ 1 ] = F_4 ( V_2 -> V_22 + V_199 ) & 0xf ;
return V_189 -> V_197 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_188 * V_189 ,
unsigned int * V_98 )
{
if ( F_58 ( V_25 , V_98 ) )
F_2 ( V_25 -> V_200 , V_2 -> V_22 + V_199 ) ;
V_98 [ 1 ] = V_25 -> V_200 ;
return V_189 -> V_197 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_22 + V_79 ) ;
F_2 ( 0 , V_2 -> V_22 + V_49 ) ;
F_2 ( 0 , V_2 -> V_22 + V_59 ) ;
F_6 ( V_2 ) ;
F_4 ( V_2 -> V_22 + V_79 ) ;
F_4 ( V_2 -> V_22 + V_129 ) ;
F_2 ( 0 , V_2 -> V_22 + V_93 ) ;
F_2 ( 1 , V_2 -> V_22 + V_50 ) ;
F_2 ( 2 , V_2 -> V_22 + V_50 ) ;
F_2 ( 2047 , V_2 -> V_22 + F_55 ( 0 ) ) ;
F_2 ( 2047 , V_2 -> V_22 + F_55 ( 1 ) ) ;
}
static struct V_201 * F_60 ( struct V_1 * V_2 ,
struct V_202 * V_203 )
{
struct V_201 * V_204 = NULL ;
int V_205 = V_203 -> V_206 [ 0 ] ;
int V_207 = V_203 -> V_206 [ 1 ] ;
F_61 (pcidev) {
if ( V_204 -> V_208 != V_209 )
continue;
if ( V_204 -> V_210 != 0x80d9 )
continue;
if ( V_205 || V_207 ) {
if ( V_204 -> V_205 -> V_211 != V_205 ||
F_62 ( V_204 -> V_212 ) != V_207 )
continue;
}
return V_204 ;
}
F_11 ( V_2 -> V_36 ,
L_17 ,
V_205 , V_207 ) ;
return NULL ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_213 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < 2 ; V_31 ++ ) {
V_8 = & V_5 -> V_8 [ V_31 ] ;
for ( V_213 = 2 ; V_213 >= 0 ; V_213 -- ) {
V_8 -> V_115 =
F_64 ( V_2 -> V_214 , V_215 << V_213 ,
& V_8 -> V_9 , V_216 ) ;
if ( V_8 -> V_115 )
break;
}
if ( ! V_8 -> V_115 )
break;
V_8 -> V_146 = V_215 << V_213 ;
if ( V_31 == 0 )
V_5 -> V_162 = 1 ;
if ( V_31 == 1 )
V_5 -> V_114 = 1 ;
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
if ( V_8 -> V_115 ) {
F_66 ( V_2 -> V_214 , V_8 -> V_146 ,
V_8 -> V_115 , V_8 -> V_9 ) ;
}
}
}
static int F_67 ( struct V_1 * V_2 ,
int V_217 , int V_167 )
{
const struct V_218 * V_219 = V_2 -> V_220 ;
struct V_201 * V_204 = F_68 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_24 * V_25 ;
int V_195 ;
int V_31 ;
T_3 V_221 ;
V_5 = F_69 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_222 ;
V_195 = F_70 ( V_2 ) ;
if ( V_195 )
return V_195 ;
F_71 ( V_204 ) ;
V_5 -> V_10 = F_72 ( V_204 , 0 ) ;
V_2 -> V_22 = F_72 ( V_204 , 2 ) ;
V_2 -> V_60 = F_73 ( V_2 -> V_22 + V_223 ,
V_224 , V_225 , 0 ) ;
if ( ! V_2 -> V_60 )
return - V_222 ;
F_59 ( V_2 ) ;
if ( V_204 -> V_117 ) {
V_195 = F_74 ( V_204 -> V_117 , F_33 , V_226 ,
V_2 -> V_227 , V_2 ) ;
if ( V_195 == 0 ) {
V_2 -> V_117 = V_204 -> V_117 ;
F_63 ( V_2 ) ;
}
}
if ( V_217 > 0 ) {
if ( V_217 > 256 )
V_217 = 256 ;
if ( V_167 > 0 )
if ( V_217 > 128 )
V_217 = 128 ;
V_5 -> V_38 = 1 ;
} else {
V_5 -> V_38 = 0 ;
}
if ( V_167 < 0 ) {
V_5 -> V_167 = - V_167 ;
V_5 -> V_51 = 0x80 ;
V_5 -> V_53 = 0x00 ;
} else {
V_5 -> V_167 = V_167 ;
V_5 -> V_51 = 0x00 ;
V_5 -> V_53 = 0x80 ;
}
F_75 ( V_204 , V_228 , & V_221 ) ;
F_76 ( V_204 , V_228 , V_221 | 64 ) ;
V_195 = F_77 ( V_2 , 4 ) ;
if ( V_195 )
return V_195 ;
V_25 = & V_2 -> V_229 [ 0 ] ;
V_25 -> type = V_230 ;
V_25 -> V_231 = V_232 | V_233 | V_234 | V_235 ;
V_25 -> V_40 = ( V_5 -> V_38 ) ? V_217 : 16 ;
V_25 -> V_104 = V_219 -> V_236 ? 0xffff : 0x0fff ;
V_25 -> V_237 = V_219 -> V_238 ? & V_239
: & V_240 ;
V_25 -> V_241 = F_52 ;
if ( V_2 -> V_117 ) {
V_2 -> V_119 = V_25 ;
V_25 -> V_231 |= V_242 ;
V_25 -> V_170 = 255 ;
V_25 -> V_243 = F_44 ;
V_25 -> V_244 = F_40 ;
V_25 -> V_245 = F_26 ;
V_25 -> V_246 = F_27 ;
}
if ( V_25 -> V_104 == 0xffff ) {
V_5 -> V_169 = 10000 ;
} else {
V_5 -> V_169 = 3000 ;
}
V_25 = & V_2 -> V_229 [ 1 ] ;
V_25 -> type = V_247 ;
V_25 -> V_231 = V_248 | V_234 | V_233 ;
V_25 -> V_40 = 2 ;
V_25 -> V_104 = 0x0fff ;
V_25 -> V_237 = & V_249 ;
V_25 -> V_250 = F_54 ;
V_195 = F_78 ( V_25 ) ;
if ( V_195 )
return V_195 ;
for ( V_31 = 0 ; V_31 < V_25 -> V_40 ; V_31 ++ )
V_25 -> V_198 [ V_31 ] = 2047 ;
V_25 = & V_2 -> V_229 [ 2 ] ;
V_25 -> type = V_251 ;
V_25 -> V_231 = V_232 ;
V_25 -> V_40 = 4 ;
V_25 -> V_104 = 1 ;
V_25 -> V_237 = & V_252 ;
V_25 -> V_253 = F_56 ;
V_25 = & V_2 -> V_229 [ 3 ] ;
V_25 -> type = V_254 ;
V_25 -> V_231 = V_248 ;
V_25 -> V_40 = 4 ;
V_25 -> V_104 = 1 ;
V_25 -> V_237 = & V_252 ;
V_25 -> V_253 = F_57 ;
V_25 -> V_200 = F_4 ( V_2 -> V_22 + V_199 ) >> 4 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_202 * V_203 )
{
struct V_201 * V_204 ;
int V_217 , V_167 ;
V_217 = V_203 -> V_206 [ 2 ] ;
V_167 = V_203 -> V_206 [ 4 ] ;
V_204 = F_60 ( V_2 , V_203 ) ;
if ( ! V_204 )
return - V_175 ;
F_80 ( V_2 , & V_204 -> V_2 ) ;
return F_67 ( V_2 , V_217 , V_167 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
unsigned long V_190 )
{
struct V_201 * V_204 = F_68 ( V_2 ) ;
const struct V_218 * V_219 = NULL ;
if ( V_190 < F_82 ( V_255 ) )
V_219 = & V_255 [ V_190 ] ;
if ( ! V_219 )
return - V_256 ;
V_2 -> V_220 = V_219 ;
V_2 -> V_227 = V_219 -> V_257 ;
F_83 ( V_204 ) ;
return F_67 ( V_2 , 0 , 0 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_201 * V_204 = F_68 ( V_2 ) ;
if ( V_2 -> V_22 )
F_59 ( V_2 ) ;
F_85 ( V_2 ) ;
F_65 ( V_2 ) ;
F_86 ( V_204 ) ;
}
static int F_87 ( struct V_201 * V_2 ,
const struct V_258 * V_259 )
{
return F_88 ( V_2 , & V_260 ,
V_259 -> V_261 ) ;
}
