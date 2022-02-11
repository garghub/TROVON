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
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_22 , unsigned int V_23 )
{
F_2 ( V_23 & 0xff , V_2 -> V_24 + F_7 ( V_22 ) ) ;
F_2 ( ( V_23 >> 8 ) & 0xff , V_2 -> V_24 + F_7 ( V_22 ) ) ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned int V_22 , unsigned int V_25 )
{
unsigned int V_23 ;
V_23 = V_22 << 6 ;
V_23 |= 0x30 ;
V_23 |= V_25 ;
F_2 ( V_23 , V_2 -> V_24 + V_26 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_24 + V_27 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_28 * V_29 , int V_30 ,
unsigned int * V_31 , int V_32 , int V_33 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_34 , V_35 = 0 , V_36 = 0 ;
if ( V_30 < 1 ) {
F_11 ( V_2 -> V_37 , L_1 ) ;
return 0 ;
}
if ( ( V_32 + V_30 + V_33 ) > V_29 -> V_38 ) {
F_11 ( V_2 -> V_37 ,
L_2 ) ;
return 0 ;
}
if ( F_12 ( V_31 [ 0 ] ) == V_39 )
V_35 = 1 ;
if ( F_13 ( V_31 [ 0 ] ) < V_40 )
V_36 = 1 ;
if ( V_30 > 1 )
for ( V_34 = 1 ; V_34 < V_30 ; V_34 ++ ) {
if ( ( F_12 ( V_31 [ V_34 ] ) == V_39 ) !=
( V_35 ) ) {
F_11 ( V_2 -> V_37 ,
L_3 ) ;
return 0 ;
}
if ( ( F_13 ( V_31 [ V_34 ] ) < V_40 ) !=
( V_36 ) ) {
F_11 ( V_2 -> V_37 ,
L_4 ) ;
return 0 ;
}
if ( ! V_5 -> V_41 && V_35 &&
( F_14 ( V_31 [ V_34 ] ) >= ( V_29 -> V_30 / 2 ) ) ) {
F_11 ( V_2 -> V_37 ,
L_5 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
int V_30 , unsigned int * V_31 ,
int V_32 , int V_33 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_42 = F_14 ( V_31 [ 0 ] ) ;
unsigned int V_43 = F_13 ( V_31 [ 0 ] ) ;
unsigned int V_44 = F_12 ( V_31 [ 0 ] ) ;
unsigned int V_45 = 0x00 ;
unsigned int V_23 ;
int V_34 ;
V_5 -> V_46 = 0 ;
if ( F_16 ( V_29 , V_43 ) )
V_5 -> V_46 |= V_47 ;
if ( V_44 == V_39 )
V_5 -> V_46 |= V_48 ;
F_2 ( V_5 -> V_46 , V_2 -> V_24 + V_49 ) ;
F_2 ( 2 , V_2 -> V_24 + V_50 ) ;
F_2 ( 0 , V_2 -> V_24 + V_50 ) ;
F_2 ( 1 , V_2 -> V_24 + V_50 ) ;
if ( V_32 ) {
V_23 = F_17 ( V_42 ) |
F_18 ( V_43 ) ;
V_45 = V_5 -> V_51 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
F_2 ( V_23 | V_45 , V_2 -> V_24 + V_52 ) ;
V_45 = V_5 -> V_53 ;
}
}
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ ) {
unsigned int V_54 = F_14 ( V_31 [ V_34 ] ) ;
unsigned int V_55 = F_13 ( V_31 [ V_34 ] ) ;
V_23 = F_17 ( V_54 ) |
F_18 ( V_55 ) ;
F_2 ( V_23 | V_45 , V_2 -> V_24 + V_52 ) ;
}
if ( V_33 ) {
V_23 = F_17 ( V_42 ) |
F_18 ( V_43 ) ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ )
F_2 ( V_23 | V_45 , V_2 -> V_24 + V_52 ) ;
}
F_2 ( 0 , V_2 -> V_24 + V_50 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
unsigned int V_56 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_56 ] ;
V_5 -> V_57 = V_58 | V_59 |
V_60 ;
F_2 ( V_5 -> V_57 , V_2 -> V_24 + V_61 ) ;
F_8 ( V_2 , 0 , V_62 ) ;
F_6 ( V_2 , 0 , V_8 -> V_9 >> 1 ) ;
V_5 -> V_57 |= V_63 ;
F_2 ( V_5 -> V_57 , V_2 -> V_24 + V_61 ) ;
}
static unsigned int F_20 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
unsigned int V_64 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_65 * V_66 = & V_29 -> V_67 -> V_66 ;
unsigned int V_68 = V_5 -> V_69 ;
unsigned int V_70 = V_68 + V_66 -> V_71 ;
unsigned int V_72 = V_70 + V_5 -> V_73 ;
unsigned int V_74 = V_5 -> V_75 ;
unsigned int V_76 , V_77 , V_78 ;
if ( V_72 == V_66 -> V_71 )
return V_64 ;
V_76 = V_64 / V_72 ;
V_77 = V_76 * V_66 -> V_71 ;
V_64 -= V_76 * V_72 ;
while ( V_64 ) {
if ( V_74 < V_68 ) {
V_78 = V_68 - V_74 ;
if ( V_78 > V_64 )
V_78 = V_64 ;
V_74 += V_78 ;
V_64 -= V_78 ;
if ( ! V_64 )
break;
}
if ( V_74 < V_70 ) {
V_78 = V_70 - V_74 ;
if ( V_78 > V_64 )
V_78 = V_64 ;
V_77 += V_78 ;
V_74 += V_78 ;
V_64 -= V_78 ;
}
V_68 += V_72 ;
V_70 += V_72 ;
}
return V_77 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
unsigned short * V_79 ,
unsigned int V_64 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_65 * V_66 = & V_29 -> V_67 -> V_66 ;
unsigned int V_68 = V_5 -> V_69 ;
unsigned int V_70 = V_68 + V_66 -> V_71 ;
unsigned int V_72 = V_70 + V_5 -> V_73 ;
unsigned int V_74 = V_5 -> V_75 ;
unsigned int V_78 ;
if ( V_72 == V_66 -> V_71 ) {
F_22 ( V_29 , V_79 , V_64 ) ;
V_74 += V_64 ;
} else {
while ( V_64 ) {
if ( V_74 < V_68 ) {
V_78 = V_68 - V_74 ;
if ( V_78 > V_64 )
V_78 = V_64 ;
V_74 += V_78 ;
V_64 -= V_78 ;
if ( ! V_64 )
break;
}
if ( V_74 < V_70 ) {
V_78 = V_70 - V_74 ;
if ( V_78 > V_64 )
V_78 = V_64 ;
F_22 ( V_29 , V_79 , V_78 ) ;
V_74 += V_78 ;
V_64 -= V_78 ;
}
V_68 += V_72 ;
V_70 += V_72 ;
}
}
V_5 -> V_75 = V_74 % V_72 ;
}
static void F_23 ( struct V_1 * V_2 , bool V_14 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_14 )
V_5 -> V_80 |= V_81 ;
else
V_5 -> V_80 &= ~ V_81 ;
F_2 ( V_5 -> V_80 , V_2 -> V_24 + V_82 ) ;
if ( V_5 -> V_80 )
F_5 ( V_2 , true ) ;
else
F_5 ( V_2 , false ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
unsigned int * V_83 , unsigned int * V_84 ,
unsigned int V_85 , int V_86 ,
unsigned int * V_87 , unsigned int * V_88 ,
unsigned int V_89 )
{
struct V_65 * V_66 = & V_29 -> V_67 -> V_66 ;
* V_87 = * V_84 / V_90 ;
* V_88 = * V_83 / V_90 ;
* V_88 = * V_88 / * V_87 ;
if ( * V_88 < V_86 )
* V_88 = V_86 ;
* V_84 = * V_87 * V_90 ;
if ( V_66 -> V_91 == V_92 && ! V_89 ) {
if ( * V_88 < ( V_86 + 2 ) )
* V_88 = V_86 + 2 ;
}
* V_83 = * V_87 * * V_88 * V_90 ;
}
static void F_25 ( struct V_1 * V_2 , int V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_8 ( V_2 , 1 , V_93 ) ;
F_8 ( V_2 , 2 , V_93 ) ;
F_26 ( 1 ) ;
if ( ( V_25 == 1 ) || ( V_25 == 2 ) || ( V_25 == 4 ) ) {
F_6 ( V_2 , 2 , V_5 -> V_94 ) ;
F_6 ( V_2 , 1 , V_5 -> V_95 ) ;
}
}
static int F_27 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_96 )
F_3 ( V_2 , false ) ;
F_23 ( V_2 , false ) ;
F_25 ( V_2 , 0 ) ;
V_5 -> V_57 = V_58 | V_59 ;
F_2 ( V_5 -> V_57 , V_2 -> V_24 + V_61 ) ;
V_5 -> V_46 = 0 ;
F_2 ( V_5 -> V_46 , V_2 -> V_24 + V_49 ) ;
F_2 ( 0 , V_2 -> V_24 + V_97 ) ;
F_2 ( 1 , V_2 -> V_24 + V_50 ) ;
F_2 ( 2 , V_2 -> V_24 + V_50 ) ;
F_9 ( V_2 ) ;
V_5 -> V_80 = 0 ;
F_2 ( V_5 -> V_80 , V_2 -> V_24 + V_82 ) ;
F_5 ( V_2 , false ) ;
V_5 -> V_98 = 0 ;
V_5 -> V_96 = 0 ;
V_5 -> V_75 = 0 ;
V_29 -> V_67 -> V_99 = NULL ;
V_5 -> V_100 = 0 ;
V_5 -> V_101 = 0 ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_28 * V_29 , void * V_102 ,
unsigned int V_103 ,
unsigned int V_104 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned short * V_105 = V_102 ;
unsigned int V_106 = F_29 ( V_29 , V_103 ) ;
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < V_106 ; V_34 ++ ) {
if ( V_5 -> V_96 )
V_105 [ V_34 ] = F_30 ( V_105 [ V_34 ] ) ;
if ( V_29 -> V_107 == 0xffff )
V_105 [ V_34 ] ^= 0x8000 ;
else
V_105 [ V_34 ] = ( V_105 [ V_34 ] >> 4 ) & 0x0fff ;
}
}
static void F_31 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_65 * V_66 = & V_29 -> V_67 -> V_66 ;
unsigned short V_108 ;
V_108 = F_4 ( V_2 -> V_24 + V_109 ) ;
F_22 ( V_29 , & V_108 , 1 ) ;
if ( ! V_5 -> V_100 ) {
if ( V_29 -> V_67 -> V_110 >= V_66 -> V_111 )
V_29 -> V_67 -> V_112 |= V_113 ;
}
}
static void F_32 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_65 * V_66 = & V_29 -> V_67 -> V_66 ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_5 -> V_101 ] ;
unsigned int V_114 = F_29 ( V_29 , V_8 -> V_12 ) ;
unsigned int V_115 ;
bool V_116 ;
V_115 = F_20 ( V_2 , V_29 , V_114 ) ;
V_116 = V_115 < F_33 ( V_29 , V_115 + 1 ) ;
if ( V_116 && V_5 -> V_117 ) {
V_5 -> V_101 = 1 - V_5 -> V_101 ;
F_1 ( V_2 , V_5 -> V_101 ) ;
if ( V_5 -> V_98 == 4 ) {
F_19 ( V_2 ,
V_5 -> V_101 ) ;
}
}
if ( V_114 )
F_21 ( V_2 , V_29 , V_8 -> V_118 , V_114 ) ;
if ( ! V_5 -> V_100 ) {
if ( V_29 -> V_67 -> V_110 >= V_66 -> V_111 )
V_29 -> V_67 -> V_112 |= V_113 ;
}
if ( V_29 -> V_67 -> V_112 & V_119 )
V_116 = false ;
if ( V_116 && ! V_5 -> V_117 ) {
F_1 ( V_2 , 0 ) ;
if ( V_5 -> V_98 == 4 )
F_19 ( V_2 , 0 ) ;
}
}
static T_1 F_34 ( int V_120 , void * V_121 )
{
struct V_1 * V_2 = V_121 ;
struct V_28 * V_29 = V_2 -> V_122 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_123 ;
unsigned int V_20 ;
unsigned int V_124 ;
if ( ! V_2 -> V_125 )
return V_126 ;
V_123 = F_4 ( V_2 -> V_24 + V_82 ) & 0xf ;
V_20 = F_4 ( V_5 -> V_10 + V_21 ) ;
if ( ! V_123 && ! ( V_20 & V_127 ) )
return V_126 ;
F_2 ( V_20 | 0x00ff0000 , V_5 -> V_10 + V_21 ) ;
if ( V_20 & V_128 ) {
F_11 ( V_2 -> V_37 , L_6 ) ;
V_29 -> V_67 -> V_112 |= V_129 ;
goto V_130;
}
if ( V_20 & V_131 ) {
F_11 ( V_2 -> V_37 , L_7 ) ;
V_29 -> V_67 -> V_112 |= V_129 ;
goto V_130;
}
V_124 = F_4 ( V_2 -> V_24 + V_132 ) ;
if ( ( V_124 & V_133 ) == 0 ) {
F_11 ( V_2 -> V_37 ,
L_8 ) ;
V_29 -> V_67 -> V_112 |= V_129 | V_134 ;
goto V_130;
}
if ( V_124 & V_135 ) {
F_11 ( V_2 -> V_37 ,
L_9 ) ;
V_29 -> V_67 -> V_112 |= V_129 | V_134 ;
goto V_130;
}
if ( V_124 & V_136 ) {
F_11 ( V_2 -> V_37 , L_10 ) ;
V_29 -> V_67 -> V_112 |= V_129 ;
goto V_130;
}
if ( V_124 & V_137 ) {
F_11 ( V_2 -> V_37 , L_11 ) ;
V_29 -> V_67 -> V_112 |= V_129 | V_134 ;
goto V_130;
}
if ( ! V_5 -> V_98 )
return V_138 ;
if ( V_5 -> V_139 ) {
if ( ( V_124 & V_140 ) &&
( V_123 & V_81 ) ) {
if ( V_5 -> V_139 & V_141 ) {
V_5 -> V_139 &= ~ V_141 ;
if ( ! ( V_5 -> V_139 & V_142 ) )
F_23 ( V_2 , false ) ;
F_25 ( V_2 , V_5 -> V_98 ) ;
F_2 ( V_5 -> V_46 ,
V_2 -> V_24 + V_49 ) ;
} else if ( V_5 -> V_139 & V_142 ) {
V_5 -> V_139 &= ~ V_142 ;
F_23 ( V_2 , false ) ;
V_5 -> V_100 = 0 ;
}
}
}
if ( V_5 -> V_96 )
F_32 ( V_2 , V_29 ) ;
else
F_31 ( V_2 , V_29 ) ;
V_130:
F_35 ( V_2 , V_29 ) ;
return V_138 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 -> V_80 , V_2 -> V_24 + V_82 ) ;
F_2 ( V_5 -> V_57 , V_2 -> V_24 + V_61 ) ;
if ( V_5 -> V_98 != 3 ) {
F_25 ( V_2 , V_5 -> V_98 ) ;
V_5 -> V_46 |= V_143 ;
}
F_2 ( V_5 -> V_46 , V_2 -> V_24 + V_49 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
unsigned int V_144 )
{
struct V_65 * V_66 = & V_29 -> V_67 -> V_66 ;
if ( V_144 != V_66 -> V_145 )
return - V_146 ;
V_29 -> V_67 -> V_99 = NULL ;
F_36 ( V_2 ) ;
return 1 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_65 * V_66 = & V_29 -> V_67 -> V_66 ;
struct V_7 * V_147 = & V_5 -> V_8 [ 0 ] ;
struct V_7 * V_148 = & V_5 -> V_8 [ 1 ] ;
unsigned int V_149 , V_150 , V_34 ;
V_149 = V_147 -> V_151 ;
V_150 = V_148 -> V_151 ;
if ( V_149 > V_29 -> V_67 -> V_152 ) {
V_149 = V_29 -> V_67 -> V_152 & ~ 3L ;
}
if ( V_150 > V_29 -> V_67 -> V_152 ) {
V_150 = V_29 -> V_67 -> V_152 & ~ 3L ;
}
if ( V_5 -> V_153 & V_154 ) {
if ( V_149 < ( V_5 -> V_155 << 1 ) ) {
V_5 -> V_153 &= ( ~ V_154 ) ;
F_39 ( V_2 -> V_37 ,
L_12 ,
V_149 , V_5 -> V_155 << 1 ) ;
} else {
V_149 = V_5 -> V_155 << 1 ;
if ( V_149 < 4 ) {
F_39 ( V_2 -> V_37 ,
L_13 ,
V_149 ) ;
V_149 = 4 ;
}
}
}
if ( V_5 -> V_153 & V_154 ) {
if ( V_150 < ( V_5 -> V_155 << 1 ) ) {
V_5 -> V_153 &= ( ~ V_154 ) ;
F_39 ( V_2 -> V_37 ,
L_14 ,
V_150 , V_5 -> V_155 << 1 ) ;
} else {
V_150 = V_5 -> V_155 << 1 ;
if ( V_150 < 4 ) {
F_39 ( V_2 -> V_37 ,
L_15 ,
V_150 ) ;
V_150 = 4 ;
}
}
}
if ( ! ( V_5 -> V_153 & V_154 ) ) {
V_34 = V_149 ;
V_149 =
( V_149 / ( V_5 -> V_155 << 1 ) ) *
( V_5 -> V_155 << 1 ) ;
V_149 &= ~ 3L ;
if ( ! V_149 )
V_149 = V_34 ;
V_34 = V_150 ;
V_150 =
( V_150 / ( V_5 -> V_155 << 1 ) ) *
( V_5 -> V_155 << 1 ) ;
V_150 &= ~ 3L ;
if ( ! V_150 )
V_150 = V_34 ;
if ( ! V_5 -> V_100 ) {
if ( V_149 >
( ( V_5 -> V_155 << 1 ) *
V_66 -> V_111 ) ) {
V_149 =
( V_5 -> V_155 << 1 ) *
V_66 -> V_111 ;
V_149 &= ~ 3L ;
} else {
if ( V_150 >
( ( V_5 -> V_155 << 1 ) *
V_66 -> V_111 - V_149 ) )
V_150 =
( V_5 -> V_155 << 1 ) *
V_66 -> V_111 - V_149 ;
V_150 &= ~ 3L ;
}
}
}
V_5 -> V_101 = 0 ;
V_147 -> V_12 = V_149 ;
V_148 -> V_12 = V_150 ;
F_3 ( V_2 , false ) ;
F_1 ( V_2 , 0 ) ;
F_2 ( 0x00000000 | V_156 ,
V_5 -> V_10 + V_21 ) ;
F_3 ( V_2 , true ) ;
F_2 ( F_4 ( V_5 -> V_10 + V_21 ) | V_19 ,
V_5 -> V_10 + V_21 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_65 * V_66 = & V_29 -> V_67 -> V_66 ;
unsigned int V_157 = 0 ;
V_5 -> V_139 = 0 ;
V_5 -> V_153 = V_66 -> V_85 ;
V_5 -> V_69 = 0 ;
V_5 -> V_73 = 0 ;
if ( V_66 -> V_158 == V_159 )
V_5 -> V_139 |= V_141 ;
if ( V_66 -> V_160 == V_159 ) {
V_5 -> V_100 = 1 ;
V_5 -> V_139 |= V_142 ;
}
if ( V_66 -> V_160 == V_161 )
V_5 -> V_100 = 1 ;
if ( V_66 -> V_160 == V_162 )
V_5 -> V_100 = 0 ;
V_5 -> V_69 = 0 ;
V_5 -> V_73 = 0 ;
if ( V_5 -> V_163 ) {
V_5 -> V_96 = 1 ;
if ( ( V_66 -> V_85 & V_154 ) &&
( V_66 -> V_164 == 1 ) ) {
if ( V_66 -> V_91 == V_92 )
V_5 -> V_73 = 1 ;
if ( V_66 -> V_91 == V_165 ) {
V_5 -> V_96 = 0 ;
}
}
if ( ( V_66 -> V_85 & V_154 ) &&
( V_66 -> V_164 & 1 ) &&
( V_66 -> V_164 > 1 ) ) {
if ( V_66 -> V_166 == V_167 ) {
V_5 -> V_96 = 0 ;
} else {
V_5 -> V_73 = 1 ;
}
}
} else {
V_5 -> V_96 = 0 ;
}
if ( V_66 -> V_91 == V_92 && V_5 -> V_168 ) {
V_5 -> V_69 = 2 ;
if ( ( V_5 -> V_96 == 1 ) && ( V_5 -> V_73 == 1 ) ) {
V_5 -> V_69 ++ ;
V_5 -> V_73 = 0 ;
}
if ( V_66 -> V_169 < V_5 -> V_170 )
V_66 -> V_169 = V_5 -> V_170 ;
V_157 = V_5 -> V_168 / V_66 -> V_169 ;
if ( V_5 -> V_168 % V_66 -> V_169 )
V_157 ++ ;
if ( V_157 > ( V_5 -> V_69 - 1 ) ) {
V_5 -> V_69 = V_157 + 1 ;
if ( V_5 -> V_96 == 1 )
if ( ( V_5 -> V_69 +
V_66 -> V_71 +
V_5 -> V_73 ) & 1 )
V_5 -> V_69 ++ ;
}
}
V_5 -> V_155 =
( V_5 -> V_69 + V_66 -> V_71 +
V_5 -> V_73 ) * ( V_66 -> V_164 /
V_66 -> V_71 ) ;
if ( ! F_10 ( V_2 , V_29 , V_66 -> V_71 ,
V_66 -> V_31 , V_5 -> V_69 ,
V_5 -> V_73 ) )
return - V_146 ;
F_15 ( V_2 , V_29 , V_66 -> V_71 , V_66 -> V_31 ,
V_5 -> V_69 , V_5 -> V_73 ) ;
V_5 -> V_98 = 0 ;
if ( V_66 -> V_166 != V_165 &&
V_66 -> V_91 == V_165 ) {
if ( V_66 -> V_166 == V_159 )
V_5 -> V_98 = 4 ;
else
V_5 -> V_98 = 1 ;
F_41 ( V_90 ,
& V_5 -> V_95 ,
& V_5 -> V_94 ,
& V_66 -> V_169 ,
V_5 -> V_153 &
V_171 ) ;
V_5 -> V_46 |= V_172 ;
if ( ! V_5 -> V_96 ) {
V_5 -> V_46 |= V_173 ;
V_5 -> V_80 |= V_174 ;
}
if ( V_66 -> V_166 == V_159 ) {
struct V_7 * V_8 = & V_5 -> V_8 [ 0 ] ;
V_5 -> V_57 |= V_60 ;
F_2 ( V_5 -> V_57 , V_2 -> V_24 + V_61 ) ;
F_8 ( V_2 , 0 , V_62 ) ;
F_6 ( V_2 , 0 , V_8 -> V_9 >> 1 ) ;
V_5 -> V_57 |= V_63 ;
}
}
if ( V_66 -> V_166 == V_165 &&
V_66 -> V_91 != V_159 ) {
if ( ! V_5 -> V_96 ) {
F_11 ( V_2 -> V_37 ,
L_16 ) ;
return - V_175 ;
}
V_5 -> V_98 = 2 ;
F_24 ( V_2 , V_29 ,
& V_66 -> V_176 , & V_66 -> V_169 ,
V_5 -> V_153 ,
V_5 -> V_155 ,
& V_5 -> V_95 ,
& V_5 -> V_94 ,
V_5 -> V_69 ) ;
V_5 -> V_46 |= V_172 ;
V_5 -> V_57 |= V_177 | V_178 ;
if ( V_66 -> V_91 == V_92 && ! V_5 -> V_168 )
V_5 -> V_57 |= V_179 ;
F_2 ( V_5 -> V_155 ,
V_2 -> V_24 + V_97 ) ;
}
if ( V_66 -> V_166 == V_167 &&
V_66 -> V_91 == V_159 ) {
V_5 -> V_98 = 3 ;
V_5 -> V_46 |= V_180 ;
}
if ( V_5 -> V_98 == 0 ) {
F_11 ( V_2 -> V_37 ,
L_17 ) ;
return - V_146 ;
}
if ( V_5 -> V_96 )
V_5 -> V_46 |= V_181 ;
F_25 ( V_2 , - 1 ) ;
V_5 -> V_57 = V_58 | V_59 ;
F_2 ( V_5 -> V_57 , V_2 -> V_24 + V_61 ) ;
F_26 ( 1 ) ;
F_9 ( V_2 ) ;
F_4 ( V_2 -> V_24 + V_132 ) ;
F_4 ( V_2 -> V_24 + V_82 ) ;
V_5 -> V_75 = 0 ;
if ( V_5 -> V_96 ) {
F_38 ( V_2 , V_29 ) ;
F_2 ( 0x02000000 | V_156 ,
V_5 -> V_10 + V_21 ) ;
} else {
F_5 ( V_2 , true ) ;
}
if ( V_66 -> V_158 == V_92 )
F_36 ( V_2 ) ;
else if ( V_66 -> V_158 == V_182 )
V_29 -> V_67 -> V_99 = F_37 ;
if ( V_66 -> V_158 == V_159 || V_66 -> V_160 == V_159 )
F_23 ( V_2 , true ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_65 * V_66 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_183 = 0 ;
unsigned int V_85 ;
unsigned int V_184 ;
unsigned int V_185 = 0 , V_186 = 0 ;
V_183 |= F_43 ( & V_66 -> V_158 ,
V_92 | V_159 | V_182 ) ;
V_85 = V_167 ;
if ( V_5 -> V_163 )
V_85 |= V_165 | V_159 ;
V_183 |= F_43 ( & V_66 -> V_166 , V_85 ) ;
V_85 = V_165 | V_159 ;
if ( V_5 -> V_163 )
V_85 |= V_92 ;
V_183 |= F_43 ( & V_66 -> V_91 , V_85 ) ;
V_183 |= F_43 ( & V_66 -> V_187 , V_162 ) ;
V_183 |= F_43 ( & V_66 -> V_160 ,
V_162 | V_161 | V_159 ) ;
if ( V_183 )
return 1 ;
V_183 |= F_44 ( V_66 -> V_158 ) ;
V_183 |= F_44 ( V_66 -> V_166 ) ;
V_183 |= F_44 ( V_66 -> V_91 ) ;
V_183 |= F_44 ( V_66 -> V_160 ) ;
if ( V_66 -> V_158 == V_159 && V_66 -> V_166 == V_159 )
V_183 |= - V_146 ;
if ( V_66 -> V_158 == V_182 && V_66 -> V_166 == V_182 )
V_183 |= - V_146 ;
if ( ( V_66 -> V_166 & ( V_165 | V_159 ) ) &&
( ! ( V_66 -> V_91 & ( V_165 | V_92 ) ) ) )
V_183 |= - V_146 ;
if ( ( V_66 -> V_166 == V_167 ) &&
( ! ( V_66 -> V_91 & ( V_165 | V_159 ) ) ) )
V_183 |= - V_146 ;
if ( V_66 -> V_160 == V_159 && V_66 -> V_166 == V_159 )
V_183 |= - V_146 ;
if ( V_183 )
return 2 ;
switch ( V_66 -> V_158 ) {
case V_92 :
case V_159 :
V_183 |= F_45 ( & V_66 -> V_145 , 0 ) ;
break;
case V_182 :
break;
}
if ( V_66 -> V_166 & ( V_167 | V_159 ) )
V_183 |= F_45 ( & V_66 -> V_176 , 0 ) ;
if ( ( V_66 -> V_166 == V_165 ) &&
( V_66 -> V_91 == V_165 ) && ( V_66 -> V_164 == 1 ) ) {
V_66 -> V_166 = V_167 ;
V_66 -> V_169 = V_66 -> V_176 ;
V_66 -> V_176 = 0 ;
}
if ( V_66 -> V_166 == V_165 )
V_183 |= F_46 ( & V_66 -> V_176 ,
V_5 -> V_170 ) ;
if ( V_66 -> V_166 == V_159 )
if ( V_66 -> V_176 ) {
V_66 -> V_176 = 0 ;
V_183 |= - V_146 ;
V_183 |= F_47 ( & V_66 -> V_164 ,
65535 ) ;
}
if ( V_66 -> V_91 & ( V_165 | V_92 ) )
V_183 |= F_46 ( & V_66 -> V_169 ,
V_5 -> V_170 ) ;
if ( V_66 -> V_91 == V_159 )
V_183 |= F_45 ( & V_66 -> V_169 , 0 ) ;
if ( V_66 -> V_160 == V_162 )
V_183 |= F_46 ( & V_66 -> V_111 , 1 ) ;
else
V_183 |= F_45 ( & V_66 -> V_111 , 0 ) ;
V_183 |= F_46 ( & V_66 -> V_71 , 1 ) ;
V_183 |= F_46 ( & V_66 -> V_164 ,
V_66 -> V_71 ) ;
if ( ( V_66 -> V_164 % V_66 -> V_71 ) ) {
V_66 -> V_164 =
V_66 -> V_71 * ( V_66 -> V_164 / V_66 -> V_71 ) ;
V_183 |= - V_146 ;
}
if ( V_183 )
return 3 ;
if ( V_66 -> V_166 == V_165 ) {
V_184 = V_66 -> V_176 ;
F_41 ( V_90 ,
& V_185 , & V_186 ,
& V_184 , V_66 -> V_85 ) ;
V_183 |= F_45 ( & V_66 -> V_176 , V_184 ) ;
}
if ( V_66 -> V_91 & ( V_165 | V_92 ) ) {
V_184 = V_66 -> V_169 ;
F_41 ( V_90 ,
& V_185 , & V_186 ,
& V_184 , V_66 -> V_85 ) ;
V_183 |= F_45 ( & V_66 -> V_169 , V_184 ) ;
if ( V_66 -> V_166 == V_165 &&
V_66 -> V_91 == V_92 ) {
if ( V_66 -> V_169 == 0 ) {
V_184 = V_5 -> V_170 *
( V_66 -> V_164 + 2 ) ;
} else {
V_184 = V_66 -> V_169 * V_66 -> V_71 ;
}
V_183 |= F_46 ( & V_66 -> V_176 ,
V_184 ) ;
}
}
if ( V_183 )
return 4 ;
if ( V_66 -> V_31 )
if ( ! F_10 ( V_2 , V_29 , V_66 -> V_71 ,
V_66 -> V_31 , 0 , 0 ) )
return 5 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_188 * V_189 ,
unsigned long V_190 )
{
unsigned int V_191 ;
V_191 = F_4 ( V_2 -> V_24 + V_132 ) ;
if ( V_191 & V_192 )
return 0 ;
return - V_193 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_24 + V_194 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_188 * V_189 ,
unsigned int * V_102 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_23 ;
int V_195 ;
int V_34 ;
F_15 ( V_2 , V_29 , 1 , & V_189 -> V_196 , 0 , 0 ) ;
V_5 -> V_57 = V_58 | V_59 ;
F_2 ( V_5 -> V_57 , V_2 -> V_24 + V_61 ) ;
F_9 ( V_2 ) ;
for ( V_34 = 0 ; V_34 < V_189 -> V_197 ; V_34 ++ ) {
F_49 ( V_2 ) ;
V_195 = F_51 ( V_2 , V_29 , V_189 , F_48 , 0 ) ;
if ( V_195 )
return V_195 ;
V_23 = F_4 ( V_2 -> V_24 + V_109 ) ;
if ( V_29 -> V_107 == 0xffff )
V_102 [ V_34 ] = ( V_23 & 0xffff ) ^ 0x8000 ;
else
V_102 [ V_34 ] = ( V_23 >> 4 ) & 0xfff ;
}
return V_189 -> V_197 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_188 * V_189 ,
unsigned int * V_102 )
{
unsigned int V_54 = F_14 ( V_189 -> V_196 ) ;
unsigned int V_23 = V_29 -> V_198 [ V_54 ] ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_189 -> V_197 ; V_34 ++ ) {
V_23 = V_102 [ V_34 ] ;
F_2 ( V_23 , V_2 -> V_24 + F_53 ( V_54 ) ) ;
}
V_29 -> V_198 [ V_54 ] = V_23 ;
return V_189 -> V_197 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_188 * V_189 ,
unsigned int * V_102 )
{
V_102 [ 1 ] = F_4 ( V_2 -> V_24 + V_199 ) & 0xf ;
return V_189 -> V_197 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_188 * V_189 ,
unsigned int * V_102 )
{
if ( F_56 ( V_29 , V_102 ) )
F_2 ( V_29 -> V_200 , V_2 -> V_24 + V_199 ) ;
V_102 [ 1 ] = V_29 -> V_200 ;
return V_189 -> V_197 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_24 + V_82 ) ;
F_2 ( 0 , V_2 -> V_24 + V_49 ) ;
F_2 ( 0 , V_2 -> V_24 + V_61 ) ;
F_9 ( V_2 ) ;
F_4 ( V_2 -> V_24 + V_82 ) ;
F_4 ( V_2 -> V_24 + V_132 ) ;
F_8 ( V_2 , 0 , V_62 ) ;
F_25 ( V_2 , 0 ) ;
F_2 ( 0 , V_2 -> V_24 + V_97 ) ;
F_2 ( 1 , V_2 -> V_24 + V_50 ) ;
F_2 ( 2 , V_2 -> V_24 + V_50 ) ;
F_2 ( 2047 , V_2 -> V_24 + F_53 ( 0 ) ) ;
F_2 ( 2047 , V_2 -> V_24 + F_53 ( 1 ) ) ;
}
static struct V_201 * F_58 ( struct V_1 * V_2 ,
struct V_202 * V_203 )
{
struct V_201 * V_204 = NULL ;
int V_205 = V_203 -> V_206 [ 0 ] ;
int V_207 = V_203 -> V_206 [ 1 ] ;
F_59 (pcidev) {
if ( V_204 -> V_208 != V_209 )
continue;
if ( V_204 -> V_210 != 0x80d9 )
continue;
if ( V_205 || V_207 ) {
if ( V_204 -> V_205 -> V_211 != V_205 ||
F_60 ( V_204 -> V_212 ) != V_207 )
continue;
}
return V_204 ;
}
F_11 ( V_2 -> V_37 ,
L_18 ,
V_205 , V_207 ) ;
return NULL ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_213 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < 2 ; V_34 ++ ) {
V_8 = & V_5 -> V_8 [ V_34 ] ;
for ( V_213 = 2 ; V_213 >= 0 ; V_213 -- ) {
V_8 -> V_118 =
F_62 ( V_2 -> V_214 , V_215 << V_213 ,
& V_8 -> V_9 , V_216 ) ;
if ( V_8 -> V_118 )
break;
}
if ( ! V_8 -> V_118 )
break;
V_8 -> V_151 = V_215 << V_213 ;
if ( V_34 == 0 )
V_5 -> V_163 = 1 ;
if ( V_34 == 1 )
V_5 -> V_117 = 1 ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_34 ;
if ( ! V_5 )
return;
for ( V_34 = 0 ; V_34 < 2 ; V_34 ++ ) {
V_8 = & V_5 -> V_8 [ V_34 ] ;
if ( V_8 -> V_118 ) {
F_64 ( V_2 -> V_214 , V_8 -> V_151 ,
V_8 -> V_118 , V_8 -> V_9 ) ;
}
}
}
static int F_65 ( struct V_1 * V_2 ,
int V_217 , int V_168 )
{
const struct V_218 * V_219 = V_2 -> V_220 ;
struct V_201 * V_204 = F_66 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_28 * V_29 ;
int V_195 ;
int V_34 ;
T_2 V_221 ;
V_5 = F_67 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_222 ;
V_195 = F_68 ( V_2 ) ;
if ( V_195 )
return V_195 ;
F_69 ( V_204 ) ;
V_5 -> V_10 = F_70 ( V_204 , 0 ) ;
V_2 -> V_24 = F_70 ( V_204 , 2 ) ;
F_57 ( V_2 ) ;
if ( V_204 -> V_120 ) {
V_195 = F_71 ( V_204 -> V_120 , F_34 , V_223 ,
V_2 -> V_224 , V_2 ) ;
if ( V_195 == 0 ) {
V_2 -> V_120 = V_204 -> V_120 ;
F_61 ( V_2 ) ;
}
}
if ( V_217 > 0 ) {
if ( V_217 > 256 )
V_217 = 256 ;
if ( V_168 > 0 )
if ( V_217 > 128 )
V_217 = 128 ;
V_5 -> V_41 = 1 ;
} else {
V_5 -> V_41 = 0 ;
}
if ( V_168 < 0 ) {
V_5 -> V_168 = - V_168 ;
V_5 -> V_51 = 0x80 ;
V_5 -> V_53 = 0x00 ;
} else {
V_5 -> V_168 = V_168 ;
V_5 -> V_51 = 0x00 ;
V_5 -> V_53 = 0x80 ;
}
F_72 ( V_204 , V_225 , & V_221 ) ;
F_73 ( V_204 , V_225 , V_221 | 64 ) ;
V_195 = F_74 ( V_2 , 4 ) ;
if ( V_195 )
return V_195 ;
V_29 = & V_2 -> V_226 [ 0 ] ;
V_29 -> type = V_227 ;
V_29 -> V_228 = V_229 | V_230 | V_231 | V_232 ;
V_29 -> V_30 = ( V_5 -> V_41 ) ? V_217 : 16 ;
V_29 -> V_107 = V_219 -> V_233 ? 0xffff : 0x0fff ;
V_29 -> V_234 = V_219 -> V_235 ? & V_236
: & V_237 ;
V_29 -> V_238 = F_50 ;
if ( V_2 -> V_120 ) {
V_2 -> V_122 = V_29 ;
V_29 -> V_228 |= V_239 ;
V_29 -> V_38 = V_240 ;
V_29 -> V_241 = F_42 ;
V_29 -> V_242 = F_40 ;
V_29 -> V_243 = F_27 ;
V_29 -> V_244 = F_28 ;
}
if ( V_29 -> V_107 == 0xffff ) {
V_5 -> V_170 = 10000 ;
} else {
V_5 -> V_170 = 3000 ;
}
V_29 = & V_2 -> V_226 [ 1 ] ;
V_29 -> type = V_245 ;
V_29 -> V_228 = V_246 | V_231 | V_230 ;
V_29 -> V_30 = 2 ;
V_29 -> V_107 = 0x0fff ;
V_29 -> V_234 = & V_247 ;
V_29 -> V_248 = F_52 ;
V_195 = F_75 ( V_29 ) ;
if ( V_195 )
return V_195 ;
for ( V_34 = 0 ; V_34 < V_29 -> V_30 ; V_34 ++ )
V_29 -> V_198 [ V_34 ] = 2047 ;
V_29 = & V_2 -> V_226 [ 2 ] ;
V_29 -> type = V_249 ;
V_29 -> V_228 = V_229 ;
V_29 -> V_30 = 4 ;
V_29 -> V_107 = 1 ;
V_29 -> V_234 = & V_250 ;
V_29 -> V_251 = F_54 ;
V_29 = & V_2 -> V_226 [ 3 ] ;
V_29 -> type = V_252 ;
V_29 -> V_228 = V_246 ;
V_29 -> V_30 = 4 ;
V_29 -> V_107 = 1 ;
V_29 -> V_234 = & V_250 ;
V_29 -> V_251 = F_55 ;
V_29 -> V_200 = F_4 ( V_2 -> V_24 + V_199 ) >> 4 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_202 * V_203 )
{
struct V_201 * V_204 ;
int V_217 , V_168 ;
V_217 = V_203 -> V_206 [ 2 ] ;
V_168 = V_203 -> V_206 [ 4 ] ;
V_204 = F_58 ( V_2 , V_203 ) ;
if ( ! V_204 )
return - V_175 ;
F_77 ( V_2 , & V_204 -> V_2 ) ;
return F_65 ( V_2 , V_217 , V_168 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
unsigned long V_190 )
{
struct V_201 * V_204 = F_66 ( V_2 ) ;
const struct V_218 * V_219 = NULL ;
if ( V_190 < F_79 ( V_253 ) )
V_219 = & V_253 [ V_190 ] ;
if ( ! V_219 )
return - V_254 ;
V_2 -> V_220 = V_219 ;
V_2 -> V_224 = V_219 -> V_255 ;
F_80 ( V_204 ) ;
return F_65 ( V_2 , 0 , 0 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_201 * V_204 = F_66 ( V_2 ) ;
if ( V_2 -> V_24 )
F_57 ( V_2 ) ;
F_82 ( V_2 ) ;
F_63 ( V_2 ) ;
if ( V_204 )
F_83 ( V_204 ) ;
}
static int F_84 ( struct V_201 * V_2 ,
const struct V_256 * V_257 )
{
return F_85 ( V_2 , & V_258 ,
V_257 -> V_259 ) ;
}
