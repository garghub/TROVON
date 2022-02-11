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
struct V_24 * V_25 , int V_26 ,
unsigned int * V_27 , int V_28 , int V_29 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_30 , V_31 = 0 , V_32 = 0 ;
if ( V_26 < 1 ) {
F_8 ( V_2 -> V_33 , L_1 ) ;
return 0 ;
}
if ( ( V_28 + V_26 + V_29 ) > V_25 -> V_34 ) {
F_8 ( V_2 -> V_33 ,
L_2 ) ;
return 0 ;
}
if ( F_9 ( V_27 [ 0 ] ) == V_35 )
V_31 = 1 ;
if ( F_10 ( V_27 [ 0 ] ) < V_36 )
V_32 = 1 ;
if ( V_26 > 1 )
for ( V_30 = 1 ; V_30 < V_26 ; V_30 ++ ) {
if ( ( F_9 ( V_27 [ V_30 ] ) == V_35 ) !=
( V_31 ) ) {
F_8 ( V_2 -> V_33 ,
L_3 ) ;
return 0 ;
}
if ( ( F_10 ( V_27 [ V_30 ] ) < V_36 ) !=
( V_32 ) ) {
F_8 ( V_2 -> V_33 ,
L_4 ) ;
return 0 ;
}
if ( ! V_5 -> V_37 && V_31 &&
( F_11 ( V_27 [ V_30 ] ) >= ( V_25 -> V_26 / 2 ) ) ) {
F_8 ( V_2 -> V_33 ,
L_5 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
int V_26 , unsigned int * V_27 ,
int V_28 , int V_29 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_38 = F_11 ( V_27 [ 0 ] ) ;
unsigned int V_39 = F_10 ( V_27 [ 0 ] ) ;
unsigned int V_40 = F_9 ( V_27 [ 0 ] ) ;
unsigned int V_41 = 0x00 ;
unsigned int V_42 ;
int V_30 ;
V_5 -> V_43 = 0 ;
if ( F_13 ( V_25 , V_39 ) )
V_5 -> V_43 |= V_44 ;
if ( V_40 == V_35 )
V_5 -> V_43 |= V_45 ;
F_2 ( V_5 -> V_43 , V_2 -> V_22 + V_46 ) ;
F_2 ( 2 , V_2 -> V_22 + V_47 ) ;
F_2 ( 0 , V_2 -> V_22 + V_47 ) ;
F_2 ( 1 , V_2 -> V_22 + V_47 ) ;
if ( V_28 ) {
V_42 = F_14 ( V_38 ) |
F_15 ( V_39 ) ;
V_41 = V_5 -> V_48 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
F_2 ( V_42 | V_41 , V_2 -> V_22 + V_49 ) ;
V_41 = V_5 -> V_50 ;
}
}
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ ) {
unsigned int V_51 = F_11 ( V_27 [ V_30 ] ) ;
unsigned int V_52 = F_10 ( V_27 [ V_30 ] ) ;
V_42 = F_14 ( V_51 ) |
F_15 ( V_52 ) ;
F_2 ( V_42 | V_41 , V_2 -> V_22 + V_49 ) ;
}
if ( V_29 ) {
V_42 = F_14 ( V_38 ) |
F_15 ( V_39 ) ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ )
F_2 ( V_42 | V_41 , V_2 -> V_22 + V_49 ) ;
}
F_2 ( 0 , V_2 -> V_22 + V_47 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned int V_53 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_53 ] ;
V_5 -> V_54 = V_55 | V_56 |
V_57 ;
F_2 ( V_5 -> V_54 , V_2 -> V_22 + V_58 ) ;
F_17 ( V_2 -> V_59 , 0 , V_8 -> V_9 >> 1 ,
V_60 | V_61 ) ;
V_5 -> V_54 |= V_62 ;
F_2 ( V_5 -> V_54 , V_2 -> V_22 + V_58 ) ;
}
static unsigned int F_18 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
unsigned int V_63 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_64 * V_65 = & V_25 -> V_66 -> V_65 ;
unsigned int V_67 = V_5 -> V_68 ;
unsigned int V_69 = V_67 + V_65 -> V_70 ;
unsigned int V_71 = V_69 + V_5 -> V_72 ;
unsigned int V_73 = V_5 -> V_74 ;
unsigned int V_75 , V_76 , V_77 ;
if ( V_71 == V_65 -> V_70 )
return V_63 ;
V_75 = V_63 / V_71 ;
V_76 = V_75 * V_65 -> V_70 ;
V_63 -= V_75 * V_71 ;
while ( V_63 ) {
if ( V_73 < V_67 ) {
V_77 = V_67 - V_73 ;
if ( V_77 > V_63 )
V_77 = V_63 ;
V_73 += V_77 ;
V_63 -= V_77 ;
if ( ! V_63 )
break;
}
if ( V_73 < V_69 ) {
V_77 = V_69 - V_73 ;
if ( V_77 > V_63 )
V_77 = V_63 ;
V_76 += V_77 ;
V_73 += V_77 ;
V_63 -= V_77 ;
}
V_67 += V_71 ;
V_69 += V_71 ;
}
return V_76 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
unsigned short * V_78 ,
unsigned int V_63 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_64 * V_65 = & V_25 -> V_66 -> V_65 ;
unsigned int V_67 = V_5 -> V_68 ;
unsigned int V_69 = V_67 + V_65 -> V_70 ;
unsigned int V_71 = V_69 + V_5 -> V_72 ;
unsigned int V_73 = V_5 -> V_74 ;
unsigned int V_77 ;
if ( V_71 == V_65 -> V_70 ) {
F_20 ( V_25 , V_78 , V_63 ) ;
V_73 += V_63 ;
} else {
while ( V_63 ) {
if ( V_73 < V_67 ) {
V_77 = V_67 - V_73 ;
if ( V_77 > V_63 )
V_77 = V_63 ;
V_73 += V_77 ;
V_63 -= V_77 ;
if ( ! V_63 )
break;
}
if ( V_73 < V_69 ) {
V_77 = V_69 - V_73 ;
if ( V_77 > V_63 )
V_77 = V_63 ;
F_20 ( V_25 , V_78 , V_77 ) ;
V_73 += V_77 ;
V_63 -= V_77 ;
}
V_67 += V_71 ;
V_69 += V_71 ;
}
}
V_5 -> V_74 = V_73 % V_71 ;
}
static void F_21 ( struct V_1 * V_2 , bool V_14 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_14 )
V_5 -> V_79 |= V_80 ;
else
V_5 -> V_79 &= ~ V_80 ;
F_2 ( V_5 -> V_79 , V_2 -> V_22 + V_81 ) ;
if ( V_5 -> V_79 )
F_5 ( V_2 , true ) ;
else
F_5 ( V_2 , false ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
unsigned int * V_82 , unsigned int * V_83 ,
unsigned int V_84 , int V_85 ,
unsigned int * V_86 , unsigned int * V_87 ,
unsigned int V_88 )
{
struct V_89 * V_59 = V_2 -> V_59 ;
struct V_64 * V_65 = & V_25 -> V_66 -> V_65 ;
* V_86 = * V_83 / V_59 -> V_90 ;
* V_87 = * V_82 / V_59 -> V_90 ;
* V_87 = * V_87 / * V_86 ;
if ( * V_87 < V_85 )
* V_87 = V_85 ;
* V_83 = * V_86 * V_59 -> V_90 ;
if ( V_65 -> V_91 == V_92 && ! V_88 ) {
if ( * V_87 < ( V_85 + 2 ) )
* V_87 = V_85 + 2 ;
}
* V_82 = * V_86 * * V_87 * V_59 -> V_90 ;
}
static void F_23 ( struct V_1 * V_2 , int V_93 )
{
if ( V_93 == 1 || V_93 == 2 || V_93 == 4 )
F_24 ( V_2 -> V_59 , 1 , 2 , true ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_94 )
F_3 ( V_2 , false ) ;
F_21 ( V_2 , false ) ;
F_24 ( V_2 -> V_59 , 1 , 2 , false ) ;
V_5 -> V_54 = V_55 | V_56 ;
F_2 ( V_5 -> V_54 , V_2 -> V_22 + V_58 ) ;
V_5 -> V_43 = 0 ;
F_2 ( V_5 -> V_43 , V_2 -> V_22 + V_46 ) ;
F_2 ( 0 , V_2 -> V_22 + V_95 ) ;
F_2 ( 1 , V_2 -> V_22 + V_47 ) ;
F_2 ( 2 , V_2 -> V_22 + V_47 ) ;
F_6 ( V_2 ) ;
V_5 -> V_79 = 0 ;
F_2 ( V_5 -> V_79 , V_2 -> V_22 + V_81 ) ;
F_5 ( V_2 , false ) ;
V_5 -> V_96 = 0 ;
V_5 -> V_94 = 0 ;
V_5 -> V_74 = 0 ;
V_25 -> V_66 -> V_97 = NULL ;
V_5 -> V_98 = 0 ;
V_5 -> V_99 = 0 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_24 * V_25 , void * V_100 ,
unsigned int V_101 ,
unsigned int V_102 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned short * V_103 = V_100 ;
unsigned int V_104 = F_27 ( V_25 , V_101 ) ;
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < V_104 ; V_30 ++ ) {
if ( V_5 -> V_94 )
V_103 [ V_30 ] = F_28 ( V_103 [ V_30 ] ) ;
if ( V_25 -> V_105 == 0xffff )
V_103 [ V_30 ] ^= 0x8000 ;
else
V_103 [ V_30 ] = ( V_103 [ V_30 ] >> 4 ) & 0x0fff ;
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_64 * V_65 = & V_25 -> V_66 -> V_65 ;
unsigned short V_106 ;
V_106 = F_4 ( V_2 -> V_22 + V_107 ) ;
F_20 ( V_25 , & V_106 , 1 ) ;
if ( ! V_5 -> V_98 ) {
if ( V_25 -> V_66 -> V_108 >= V_65 -> V_109 )
V_25 -> V_66 -> V_110 |= V_111 ;
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_64 * V_65 = & V_25 -> V_66 -> V_65 ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_5 -> V_99 ] ;
unsigned int V_112 = F_27 ( V_25 , V_8 -> V_12 ) ;
unsigned int V_113 ;
bool V_114 ;
V_113 = F_18 ( V_2 , V_25 , V_112 ) ;
V_114 = V_113 < F_31 ( V_25 , V_113 + 1 ) ;
if ( V_114 && V_5 -> V_115 ) {
V_5 -> V_99 = 1 - V_5 -> V_99 ;
F_1 ( V_2 , V_5 -> V_99 ) ;
if ( V_5 -> V_96 == 4 ) {
F_16 ( V_2 ,
V_5 -> V_99 ) ;
}
}
if ( V_112 )
F_19 ( V_2 , V_25 , V_8 -> V_116 , V_112 ) ;
if ( ! V_5 -> V_98 ) {
if ( V_25 -> V_66 -> V_108 >= V_65 -> V_109 )
V_25 -> V_66 -> V_110 |= V_111 ;
}
if ( V_25 -> V_66 -> V_110 & V_117 )
V_114 = false ;
if ( V_114 && ! V_5 -> V_115 ) {
F_1 ( V_2 , 0 ) ;
if ( V_5 -> V_96 == 4 )
F_16 ( V_2 , 0 ) ;
}
}
static T_1 F_32 ( int V_118 , void * V_119 )
{
struct V_1 * V_2 = V_119 ;
struct V_24 * V_25 = V_2 -> V_120 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_121 ;
unsigned int V_20 ;
unsigned int V_122 ;
if ( ! V_2 -> V_123 )
return V_124 ;
V_121 = F_4 ( V_2 -> V_22 + V_81 ) & 0xf ;
V_20 = F_4 ( V_5 -> V_10 + V_21 ) ;
if ( ! V_121 && ! ( V_20 & V_125 ) )
return V_124 ;
F_2 ( V_20 | 0x00ff0000 , V_5 -> V_10 + V_21 ) ;
if ( V_20 & V_126 ) {
F_8 ( V_2 -> V_33 , L_6 ) ;
V_25 -> V_66 -> V_110 |= V_127 ;
goto V_128;
}
if ( V_20 & V_129 ) {
F_8 ( V_2 -> V_33 , L_7 ) ;
V_25 -> V_66 -> V_110 |= V_127 ;
goto V_128;
}
V_122 = F_4 ( V_2 -> V_22 + V_130 ) ;
if ( ( V_122 & V_131 ) == 0 ) {
F_8 ( V_2 -> V_33 ,
L_8 ) ;
V_25 -> V_66 -> V_110 |= V_127 | V_132 ;
goto V_128;
}
if ( V_122 & V_133 ) {
F_8 ( V_2 -> V_33 ,
L_9 ) ;
V_25 -> V_66 -> V_110 |= V_127 | V_132 ;
goto V_128;
}
if ( V_122 & V_134 ) {
F_8 ( V_2 -> V_33 , L_10 ) ;
V_25 -> V_66 -> V_110 |= V_127 ;
goto V_128;
}
if ( V_122 & V_135 ) {
F_8 ( V_2 -> V_33 , L_11 ) ;
V_25 -> V_66 -> V_110 |= V_127 | V_132 ;
goto V_128;
}
if ( ! V_5 -> V_96 )
return V_136 ;
if ( V_5 -> V_137 ) {
if ( ( V_122 & V_138 ) &&
( V_121 & V_80 ) ) {
if ( V_5 -> V_137 & V_139 ) {
V_5 -> V_137 &= ~ V_139 ;
if ( ! ( V_5 -> V_137 & V_140 ) )
F_21 ( V_2 , false ) ;
F_23 ( V_2 , V_5 -> V_96 ) ;
F_2 ( V_5 -> V_43 ,
V_2 -> V_22 + V_46 ) ;
} else if ( V_5 -> V_137 & V_140 ) {
V_5 -> V_137 &= ~ V_140 ;
F_21 ( V_2 , false ) ;
V_5 -> V_98 = 0 ;
}
}
}
if ( V_5 -> V_94 )
F_30 ( V_2 , V_25 ) ;
else
F_29 ( V_2 , V_25 ) ;
V_128:
F_33 ( V_2 , V_25 ) ;
return V_136 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 -> V_79 , V_2 -> V_22 + V_81 ) ;
F_2 ( V_5 -> V_54 , V_2 -> V_22 + V_58 ) ;
if ( V_5 -> V_96 != 3 ) {
F_23 ( V_2 , V_5 -> V_96 ) ;
V_5 -> V_43 |= V_141 ;
}
F_2 ( V_5 -> V_43 , V_2 -> V_22 + V_46 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
unsigned int V_142 )
{
struct V_64 * V_65 = & V_25 -> V_66 -> V_65 ;
if ( V_142 != V_65 -> V_143 )
return - V_144 ;
V_25 -> V_66 -> V_97 = NULL ;
F_34 ( V_2 ) ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_64 * V_65 = & V_25 -> V_66 -> V_65 ;
struct V_7 * V_145 = & V_5 -> V_8 [ 0 ] ;
struct V_7 * V_146 = & V_5 -> V_8 [ 1 ] ;
unsigned int V_147 , V_148 , V_30 ;
V_147 = V_145 -> V_149 ;
V_148 = V_146 -> V_149 ;
if ( V_147 > V_25 -> V_66 -> V_150 ) {
V_147 = V_25 -> V_66 -> V_150 & ~ 3L ;
}
if ( V_148 > V_25 -> V_66 -> V_150 ) {
V_148 = V_25 -> V_66 -> V_150 & ~ 3L ;
}
if ( V_5 -> V_151 & V_152 ) {
if ( V_147 < ( V_5 -> V_153 << 1 ) ) {
V_5 -> V_151 &= ( ~ V_152 ) ;
F_37 ( V_2 -> V_33 ,
L_12 ,
V_147 , V_5 -> V_153 << 1 ) ;
} else {
V_147 = V_5 -> V_153 << 1 ;
if ( V_147 < 4 ) {
F_37 ( V_2 -> V_33 ,
L_13 ,
V_147 ) ;
V_147 = 4 ;
}
}
}
if ( V_5 -> V_151 & V_152 ) {
if ( V_148 < ( V_5 -> V_153 << 1 ) ) {
V_5 -> V_151 &= ( ~ V_152 ) ;
F_37 ( V_2 -> V_33 ,
L_14 ,
V_148 , V_5 -> V_153 << 1 ) ;
} else {
V_148 = V_5 -> V_153 << 1 ;
if ( V_148 < 4 ) {
F_37 ( V_2 -> V_33 ,
L_15 ,
V_148 ) ;
V_148 = 4 ;
}
}
}
if ( ! ( V_5 -> V_151 & V_152 ) ) {
V_30 = V_147 ;
V_147 =
( V_147 / ( V_5 -> V_153 << 1 ) ) *
( V_5 -> V_153 << 1 ) ;
V_147 &= ~ 3L ;
if ( ! V_147 )
V_147 = V_30 ;
V_30 = V_148 ;
V_148 =
( V_148 / ( V_5 -> V_153 << 1 ) ) *
( V_5 -> V_153 << 1 ) ;
V_148 &= ~ 3L ;
if ( ! V_148 )
V_148 = V_30 ;
if ( ! V_5 -> V_98 ) {
if ( V_147 >
( ( V_5 -> V_153 << 1 ) *
V_65 -> V_109 ) ) {
V_147 =
( V_5 -> V_153 << 1 ) *
V_65 -> V_109 ;
V_147 &= ~ 3L ;
} else {
if ( V_148 >
( ( V_5 -> V_153 << 1 ) *
V_65 -> V_109 - V_147 ) )
V_148 =
( V_5 -> V_153 << 1 ) *
V_65 -> V_109 - V_147 ;
V_148 &= ~ 3L ;
}
}
}
V_5 -> V_99 = 0 ;
V_145 -> V_12 = V_147 ;
V_146 -> V_12 = V_148 ;
F_3 ( V_2 , false ) ;
F_1 ( V_2 , 0 ) ;
F_2 ( 0x00000000 | V_154 ,
V_5 -> V_10 + V_21 ) ;
F_3 ( V_2 , true ) ;
F_2 ( F_4 ( V_5 -> V_10 + V_21 ) | V_19 ,
V_5 -> V_10 + V_21 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_89 * V_59 = V_2 -> V_59 ;
struct V_64 * V_65 = & V_25 -> V_66 -> V_65 ;
unsigned int V_155 = 0 ;
V_5 -> V_137 = 0 ;
V_5 -> V_151 = V_65 -> V_84 ;
V_5 -> V_68 = 0 ;
V_5 -> V_72 = 0 ;
if ( V_65 -> V_156 == V_157 )
V_5 -> V_137 |= V_139 ;
if ( V_65 -> V_158 == V_157 ) {
V_5 -> V_98 = 1 ;
V_5 -> V_137 |= V_140 ;
}
if ( V_65 -> V_158 == V_159 )
V_5 -> V_98 = 1 ;
if ( V_65 -> V_158 == V_160 )
V_5 -> V_98 = 0 ;
V_5 -> V_68 = 0 ;
V_5 -> V_72 = 0 ;
if ( V_5 -> V_161 ) {
V_5 -> V_94 = 1 ;
if ( ( V_65 -> V_84 & V_152 ) &&
( V_65 -> V_162 == 1 ) ) {
if ( V_65 -> V_91 == V_92 )
V_5 -> V_72 = 1 ;
if ( V_65 -> V_91 == V_163 ) {
V_5 -> V_94 = 0 ;
}
}
if ( ( V_65 -> V_84 & V_152 ) &&
( V_65 -> V_162 & 1 ) &&
( V_65 -> V_162 > 1 ) ) {
if ( V_65 -> V_164 == V_165 ) {
V_5 -> V_94 = 0 ;
} else {
V_5 -> V_72 = 1 ;
}
}
} else {
V_5 -> V_94 = 0 ;
}
if ( V_65 -> V_91 == V_92 && V_5 -> V_166 ) {
V_5 -> V_68 = 2 ;
if ( ( V_5 -> V_94 == 1 ) && ( V_5 -> V_72 == 1 ) ) {
V_5 -> V_68 ++ ;
V_5 -> V_72 = 0 ;
}
if ( V_65 -> V_167 < V_5 -> V_168 )
V_65 -> V_167 = V_5 -> V_168 ;
V_155 = V_5 -> V_166 / V_65 -> V_167 ;
if ( V_5 -> V_166 % V_65 -> V_167 )
V_155 ++ ;
if ( V_155 > ( V_5 -> V_68 - 1 ) ) {
V_5 -> V_68 = V_155 + 1 ;
if ( V_5 -> V_94 == 1 )
if ( ( V_5 -> V_68 +
V_65 -> V_70 +
V_5 -> V_72 ) & 1 )
V_5 -> V_68 ++ ;
}
}
V_5 -> V_153 =
( V_5 -> V_68 + V_65 -> V_70 +
V_5 -> V_72 ) * ( V_65 -> V_162 /
V_65 -> V_70 ) ;
if ( ! F_7 ( V_2 , V_25 , V_65 -> V_70 ,
V_65 -> V_27 , V_5 -> V_68 ,
V_5 -> V_72 ) )
return - V_144 ;
F_12 ( V_2 , V_25 , V_65 -> V_70 , V_65 -> V_27 ,
V_5 -> V_68 , V_5 -> V_72 ) ;
V_5 -> V_96 = 0 ;
if ( V_65 -> V_164 != V_163 &&
V_65 -> V_91 == V_163 ) {
if ( V_65 -> V_164 == V_157 )
V_5 -> V_96 = 4 ;
else
V_5 -> V_96 = 1 ;
F_39 ( V_59 , & V_65 -> V_167 ,
V_5 -> V_151 &
V_169 ) ;
F_40 ( V_59 ) ;
V_5 -> V_43 |= V_170 ;
if ( ! V_5 -> V_94 ) {
V_5 -> V_43 |= V_171 ;
V_5 -> V_79 |= V_172 ;
}
if ( V_65 -> V_164 == V_157 ) {
struct V_7 * V_8 = & V_5 -> V_8 [ 0 ] ;
V_5 -> V_54 |= V_57 ;
F_2 ( V_5 -> V_54 , V_2 -> V_22 + V_58 ) ;
F_17 ( V_59 , 0 , V_8 -> V_9 >> 1 ,
V_60 | V_61 ) ;
V_5 -> V_54 |= V_62 ;
}
}
if ( V_65 -> V_164 == V_163 &&
V_65 -> V_91 != V_157 ) {
if ( ! V_5 -> V_94 ) {
F_8 ( V_2 -> V_33 ,
L_16 ) ;
return - V_173 ;
}
V_5 -> V_96 = 2 ;
F_22 ( V_2 , V_25 ,
& V_65 -> V_174 , & V_65 -> V_167 ,
V_5 -> V_151 ,
V_5 -> V_153 ,
& V_59 -> V_175 ,
& V_59 -> V_176 ,
V_5 -> V_68 ) ;
V_5 -> V_43 |= V_170 ;
V_5 -> V_54 |= V_177 | V_178 ;
if ( V_65 -> V_91 == V_92 && ! V_5 -> V_166 )
V_5 -> V_54 |= V_179 ;
F_2 ( V_5 -> V_153 ,
V_2 -> V_22 + V_95 ) ;
}
if ( V_65 -> V_164 == V_165 &&
V_65 -> V_91 == V_157 ) {
V_5 -> V_96 = 3 ;
V_5 -> V_43 |= V_180 ;
}
if ( V_5 -> V_96 == 0 ) {
F_8 ( V_2 -> V_33 ,
L_17 ) ;
return - V_144 ;
}
if ( V_5 -> V_94 )
V_5 -> V_43 |= V_181 ;
V_5 -> V_54 = V_55 | V_56 ;
F_2 ( V_5 -> V_54 , V_2 -> V_22 + V_58 ) ;
F_41 ( 1 ) ;
F_6 ( V_2 ) ;
F_4 ( V_2 -> V_22 + V_130 ) ;
F_4 ( V_2 -> V_22 + V_81 ) ;
V_5 -> V_74 = 0 ;
if ( V_5 -> V_94 ) {
F_36 ( V_2 , V_25 ) ;
F_2 ( 0x02000000 | V_154 ,
V_5 -> V_10 + V_21 ) ;
} else {
F_5 ( V_2 , true ) ;
}
if ( V_65 -> V_156 == V_92 )
F_34 ( V_2 ) ;
else if ( V_65 -> V_156 == V_182 )
V_25 -> V_66 -> V_97 = F_35 ;
if ( V_65 -> V_156 == V_157 || V_65 -> V_158 == V_157 )
F_21 ( V_2 , true ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_64 * V_65 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_183 = 0 ;
unsigned int V_84 ;
unsigned int V_184 ;
V_183 |= F_43 ( & V_65 -> V_156 ,
V_92 | V_157 | V_182 ) ;
V_84 = V_165 ;
if ( V_5 -> V_161 )
V_84 |= V_163 | V_157 ;
V_183 |= F_43 ( & V_65 -> V_164 , V_84 ) ;
V_84 = V_163 | V_157 ;
if ( V_5 -> V_161 )
V_84 |= V_92 ;
V_183 |= F_43 ( & V_65 -> V_91 , V_84 ) ;
V_183 |= F_43 ( & V_65 -> V_185 , V_160 ) ;
V_183 |= F_43 ( & V_65 -> V_158 ,
V_160 | V_159 | V_157 ) ;
if ( V_183 )
return 1 ;
V_183 |= F_44 ( V_65 -> V_156 ) ;
V_183 |= F_44 ( V_65 -> V_164 ) ;
V_183 |= F_44 ( V_65 -> V_91 ) ;
V_183 |= F_44 ( V_65 -> V_158 ) ;
if ( V_65 -> V_156 == V_157 && V_65 -> V_164 == V_157 )
V_183 |= - V_144 ;
if ( V_65 -> V_156 == V_182 && V_65 -> V_164 == V_182 )
V_183 |= - V_144 ;
if ( ( V_65 -> V_164 & ( V_163 | V_157 ) ) &&
( ! ( V_65 -> V_91 & ( V_163 | V_92 ) ) ) )
V_183 |= - V_144 ;
if ( ( V_65 -> V_164 == V_165 ) &&
( ! ( V_65 -> V_91 & ( V_163 | V_157 ) ) ) )
V_183 |= - V_144 ;
if ( V_65 -> V_158 == V_157 && V_65 -> V_164 == V_157 )
V_183 |= - V_144 ;
if ( V_183 )
return 2 ;
switch ( V_65 -> V_156 ) {
case V_92 :
case V_157 :
V_183 |= F_45 ( & V_65 -> V_143 , 0 ) ;
break;
case V_182 :
break;
}
if ( V_65 -> V_164 & ( V_165 | V_157 ) )
V_183 |= F_45 ( & V_65 -> V_174 , 0 ) ;
if ( ( V_65 -> V_164 == V_163 ) &&
( V_65 -> V_91 == V_163 ) && ( V_65 -> V_162 == 1 ) ) {
V_65 -> V_164 = V_165 ;
V_65 -> V_167 = V_65 -> V_174 ;
V_65 -> V_174 = 0 ;
}
if ( V_65 -> V_164 == V_163 ) {
V_183 |= F_46 ( & V_65 -> V_174 ,
V_5 -> V_168 ) ;
}
if ( V_65 -> V_164 == V_157 ) {
if ( V_65 -> V_174 ) {
V_65 -> V_174 = 0 ;
V_183 |= - V_144 ;
V_183 |= F_47 ( & V_65 -> V_162 ,
65535 ) ;
}
}
if ( V_65 -> V_91 & ( V_163 | V_92 ) ) {
V_183 |= F_46 ( & V_65 -> V_167 ,
V_5 -> V_168 ) ;
}
if ( V_65 -> V_91 == V_157 )
V_183 |= F_45 ( & V_65 -> V_167 , 0 ) ;
if ( V_65 -> V_158 == V_160 )
V_183 |= F_46 ( & V_65 -> V_109 , 1 ) ;
else
V_183 |= F_45 ( & V_65 -> V_109 , 0 ) ;
V_183 |= F_46 ( & V_65 -> V_70 , 1 ) ;
V_183 |= F_46 ( & V_65 -> V_162 ,
V_65 -> V_70 ) ;
if ( ( V_65 -> V_162 % V_65 -> V_70 ) ) {
V_65 -> V_162 =
V_65 -> V_70 * ( V_65 -> V_162 / V_65 -> V_70 ) ;
V_183 |= - V_144 ;
}
if ( V_183 )
return 3 ;
if ( V_65 -> V_164 == V_163 ) {
V_184 = V_65 -> V_174 ;
F_39 ( V_2 -> V_59 , & V_184 , V_65 -> V_84 ) ;
V_183 |= F_45 ( & V_65 -> V_174 , V_184 ) ;
}
if ( V_65 -> V_91 & ( V_163 | V_92 ) ) {
V_184 = V_65 -> V_167 ;
F_39 ( V_2 -> V_59 , & V_184 , V_65 -> V_84 ) ;
V_183 |= F_45 ( & V_65 -> V_167 , V_184 ) ;
if ( V_65 -> V_164 == V_163 &&
V_65 -> V_91 == V_92 ) {
if ( V_65 -> V_167 == 0 ) {
V_184 = V_5 -> V_168 *
( V_65 -> V_162 + 2 ) ;
} else {
V_184 = V_65 -> V_167 * V_65 -> V_70 ;
}
V_183 |= F_46 ( & V_65 ->
V_174 ,
V_184 ) ;
}
}
if ( V_183 )
return 4 ;
if ( V_65 -> V_27 )
if ( ! F_7 ( V_2 , V_25 , V_65 -> V_70 ,
V_65 -> V_27 , 0 , 0 ) )
return 5 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_186 * V_187 ,
unsigned long V_188 )
{
unsigned int V_189 ;
V_189 = F_4 ( V_2 -> V_22 + V_130 ) ;
if ( V_189 & V_190 )
return 0 ;
return - V_191 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_22 + V_192 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_186 * V_187 ,
unsigned int * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_42 ;
int V_193 ;
int V_30 ;
F_12 ( V_2 , V_25 , 1 , & V_187 -> V_194 , 0 , 0 ) ;
V_5 -> V_54 = V_55 | V_56 ;
F_2 ( V_5 -> V_54 , V_2 -> V_22 + V_58 ) ;
F_6 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < V_187 -> V_195 ; V_30 ++ ) {
F_49 ( V_2 ) ;
V_193 = F_51 ( V_2 , V_25 , V_187 , F_48 , 0 ) ;
if ( V_193 )
return V_193 ;
V_42 = F_4 ( V_2 -> V_22 + V_107 ) ;
if ( V_25 -> V_105 == 0xffff )
V_100 [ V_30 ] = ( V_42 & 0xffff ) ^ 0x8000 ;
else
V_100 [ V_30 ] = ( V_42 >> 4 ) & 0xfff ;
}
return V_187 -> V_195 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_186 * V_187 ,
unsigned int * V_100 )
{
unsigned int V_51 = F_11 ( V_187 -> V_194 ) ;
unsigned int V_42 = V_25 -> V_196 [ V_51 ] ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_187 -> V_195 ; V_30 ++ ) {
V_42 = V_100 [ V_30 ] ;
F_2 ( V_42 , V_2 -> V_22 + F_53 ( V_51 ) ) ;
}
V_25 -> V_196 [ V_51 ] = V_42 ;
return V_187 -> V_195 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_186 * V_187 ,
unsigned int * V_100 )
{
V_100 [ 1 ] = F_4 ( V_2 -> V_22 + V_197 ) & 0xf ;
return V_187 -> V_195 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_186 * V_187 ,
unsigned int * V_100 )
{
if ( F_56 ( V_25 , V_100 ) )
F_2 ( V_25 -> V_198 , V_2 -> V_22 + V_197 ) ;
V_100 [ 1 ] = V_25 -> V_198 ;
return V_187 -> V_195 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_22 + V_81 ) ;
F_2 ( 0 , V_2 -> V_22 + V_46 ) ;
F_2 ( 0 , V_2 -> V_22 + V_58 ) ;
F_6 ( V_2 ) ;
F_4 ( V_2 -> V_22 + V_81 ) ;
F_4 ( V_2 -> V_22 + V_130 ) ;
F_2 ( 0 , V_2 -> V_22 + V_95 ) ;
F_2 ( 1 , V_2 -> V_22 + V_47 ) ;
F_2 ( 2 , V_2 -> V_22 + V_47 ) ;
F_2 ( 2047 , V_2 -> V_22 + F_53 ( 0 ) ) ;
F_2 ( 2047 , V_2 -> V_22 + F_53 ( 1 ) ) ;
}
static struct V_199 * F_58 ( struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_199 * V_202 = NULL ;
int V_203 = V_201 -> V_204 [ 0 ] ;
int V_205 = V_201 -> V_204 [ 1 ] ;
F_59 (pcidev) {
if ( V_202 -> V_206 != V_207 )
continue;
if ( V_202 -> V_208 != 0x80d9 )
continue;
if ( V_203 || V_205 ) {
if ( V_202 -> V_203 -> V_209 != V_203 ||
F_60 ( V_202 -> V_210 ) != V_205 )
continue;
}
return V_202 ;
}
F_8 ( V_2 -> V_33 ,
L_18 ,
V_203 , V_205 ) ;
return NULL ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_211 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < 2 ; V_30 ++ ) {
V_8 = & V_5 -> V_8 [ V_30 ] ;
for ( V_211 = 2 ; V_211 >= 0 ; V_211 -- ) {
V_8 -> V_116 =
F_62 ( V_2 -> V_212 , V_213 << V_211 ,
& V_8 -> V_9 , V_214 ) ;
if ( V_8 -> V_116 )
break;
}
if ( ! V_8 -> V_116 )
break;
V_8 -> V_149 = V_213 << V_211 ;
if ( V_30 == 0 )
V_5 -> V_161 = 1 ;
if ( V_30 == 1 )
V_5 -> V_115 = 1 ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_30 ;
if ( ! V_5 )
return;
for ( V_30 = 0 ; V_30 < 2 ; V_30 ++ ) {
V_8 = & V_5 -> V_8 [ V_30 ] ;
if ( V_8 -> V_116 ) {
F_64 ( V_2 -> V_212 , V_8 -> V_149 ,
V_8 -> V_116 , V_8 -> V_9 ) ;
}
}
}
static int F_65 ( struct V_1 * V_2 ,
int V_215 , int V_166 )
{
const struct V_216 * V_217 = V_2 -> V_218 ;
struct V_199 * V_202 = F_66 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_24 * V_25 ;
int V_193 ;
int V_30 ;
T_2 V_219 ;
V_5 = F_67 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_220 ;
V_193 = F_68 ( V_2 ) ;
if ( V_193 )
return V_193 ;
F_69 ( V_202 ) ;
V_5 -> V_10 = F_70 ( V_202 , 0 ) ;
V_2 -> V_22 = F_70 ( V_202 , 2 ) ;
V_2 -> V_59 = F_71 ( V_2 -> V_22 + V_221 ,
V_222 , V_223 , 0 ) ;
if ( ! V_2 -> V_59 )
return - V_220 ;
F_57 ( V_2 ) ;
if ( V_202 -> V_118 ) {
V_193 = F_72 ( V_202 -> V_118 , F_32 , V_224 ,
V_2 -> V_225 , V_2 ) ;
if ( V_193 == 0 ) {
V_2 -> V_118 = V_202 -> V_118 ;
F_61 ( V_2 ) ;
}
}
if ( V_215 > 0 ) {
if ( V_215 > 256 )
V_215 = 256 ;
if ( V_166 > 0 )
if ( V_215 > 128 )
V_215 = 128 ;
V_5 -> V_37 = 1 ;
} else {
V_5 -> V_37 = 0 ;
}
if ( V_166 < 0 ) {
V_5 -> V_166 = - V_166 ;
V_5 -> V_48 = 0x80 ;
V_5 -> V_50 = 0x00 ;
} else {
V_5 -> V_166 = V_166 ;
V_5 -> V_48 = 0x00 ;
V_5 -> V_50 = 0x80 ;
}
F_73 ( V_202 , V_226 , & V_219 ) ;
F_74 ( V_202 , V_226 , V_219 | 64 ) ;
V_193 = F_75 ( V_2 , 4 ) ;
if ( V_193 )
return V_193 ;
V_25 = & V_2 -> V_227 [ 0 ] ;
V_25 -> type = V_228 ;
V_25 -> V_229 = V_230 | V_231 | V_232 | V_233 ;
V_25 -> V_26 = ( V_5 -> V_37 ) ? V_215 : 16 ;
V_25 -> V_105 = V_217 -> V_234 ? 0xffff : 0x0fff ;
V_25 -> V_235 = V_217 -> V_236 ? & V_237
: & V_238 ;
V_25 -> V_239 = F_50 ;
if ( V_2 -> V_118 ) {
V_2 -> V_120 = V_25 ;
V_25 -> V_229 |= V_240 ;
V_25 -> V_34 = V_241 ;
V_25 -> V_242 = F_42 ;
V_25 -> V_243 = F_38 ;
V_25 -> V_244 = F_25 ;
V_25 -> V_245 = F_26 ;
}
if ( V_25 -> V_105 == 0xffff ) {
V_5 -> V_168 = 10000 ;
} else {
V_5 -> V_168 = 3000 ;
}
V_25 = & V_2 -> V_227 [ 1 ] ;
V_25 -> type = V_246 ;
V_25 -> V_229 = V_247 | V_232 | V_231 ;
V_25 -> V_26 = 2 ;
V_25 -> V_105 = 0x0fff ;
V_25 -> V_235 = & V_248 ;
V_25 -> V_249 = F_52 ;
V_193 = F_76 ( V_25 ) ;
if ( V_193 )
return V_193 ;
for ( V_30 = 0 ; V_30 < V_25 -> V_26 ; V_30 ++ )
V_25 -> V_196 [ V_30 ] = 2047 ;
V_25 = & V_2 -> V_227 [ 2 ] ;
V_25 -> type = V_250 ;
V_25 -> V_229 = V_230 ;
V_25 -> V_26 = 4 ;
V_25 -> V_105 = 1 ;
V_25 -> V_235 = & V_251 ;
V_25 -> V_252 = F_54 ;
V_25 = & V_2 -> V_227 [ 3 ] ;
V_25 -> type = V_253 ;
V_25 -> V_229 = V_247 ;
V_25 -> V_26 = 4 ;
V_25 -> V_105 = 1 ;
V_25 -> V_235 = & V_251 ;
V_25 -> V_252 = F_55 ;
V_25 -> V_198 = F_4 ( V_2 -> V_22 + V_197 ) >> 4 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_199 * V_202 ;
int V_215 , V_166 ;
V_215 = V_201 -> V_204 [ 2 ] ;
V_166 = V_201 -> V_204 [ 4 ] ;
V_202 = F_58 ( V_2 , V_201 ) ;
if ( ! V_202 )
return - V_173 ;
F_78 ( V_2 , & V_202 -> V_2 ) ;
return F_65 ( V_2 , V_215 , V_166 ) ;
}
static int F_79 ( struct V_1 * V_2 ,
unsigned long V_188 )
{
struct V_199 * V_202 = F_66 ( V_2 ) ;
const struct V_216 * V_217 = NULL ;
if ( V_188 < F_80 ( V_254 ) )
V_217 = & V_254 [ V_188 ] ;
if ( ! V_217 )
return - V_255 ;
V_2 -> V_218 = V_217 ;
V_2 -> V_225 = V_217 -> V_256 ;
F_81 ( V_202 ) ;
return F_65 ( V_2 , 0 , 0 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_199 * V_202 = F_66 ( V_2 ) ;
if ( V_2 -> V_22 )
F_57 ( V_2 ) ;
F_83 ( V_2 ) ;
F_63 ( V_2 ) ;
if ( V_202 )
F_84 ( V_202 ) ;
}
static int F_85 ( struct V_199 * V_2 ,
const struct V_257 * V_258 )
{
return F_86 ( V_2 , & V_259 ,
V_258 -> V_260 ) ;
}
