static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 -> V_11 ;
unsigned int V_13 ;
unsigned int V_14 ;
unsigned int V_15 ;
unsigned int V_16 ;
unsigned int V_17 ;
V_17 = F_2 ( V_5 -> V_18 + F_3 ( V_3 ) ) ;
V_13 = V_5 -> V_19 ;
V_14 = F_4 ( V_5 -> V_20 [ V_13 ] . V_21 ) ;
for ( V_15 = 0 ; ( V_17 < V_14 || V_17 >= V_14 + V_5 -> V_22 ) &&
V_15 < V_5 -> V_23 ; V_15 ++ ) {
V_16 = V_5 -> V_22 / sizeof( V_24 ) ;
if ( V_11 -> V_25 == V_26 ) {
if ( V_16 > V_5 -> V_27 )
V_16 = V_5 -> V_27 ;
V_5 -> V_27 -= V_16 ;
}
F_5 ( V_8 , V_5 -> V_28 [ V_13 ] ,
V_16 ) ;
V_13 ++ ;
V_13 %= V_5 -> V_23 ;
V_14 = F_4 ( V_5 -> V_20 [ V_13 ] . V_21 ) ;
V_5 -> V_19 = V_13 ;
}
}
static T_1 F_6 ( int V_29 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_31 * V_12 = V_8 -> V_12 ;
V_24 V_32 , V_33 ;
V_24 V_34 ;
V_24 V_35 ;
T_2 V_36 , V_37 ;
unsigned long V_38 ;
if ( ! V_2 -> V_39 )
return V_40 ;
V_34 = F_2 ( V_5 -> V_18 + V_41 ) ;
if ( ( V_34 &
( V_42 | V_43 | V_44 ) ) == 0 )
return V_40 ;
V_32 = F_2 ( V_2 -> V_45 + V_46 ) ;
V_33 = F_2 ( V_2 -> V_45 + V_47 ) ;
if ( V_32 )
F_7 ( V_32 , V_2 -> V_45 + V_46 ) ;
F_8 ( & V_2 -> V_48 , V_38 ) ;
V_36 = F_9 ( V_5 -> V_18 + V_49 ) ;
if ( V_34 & V_42 ) {
F_10 ( ( V_36 & V_50 ) | V_51 ,
V_5 -> V_18 + V_49 ) ;
if ( V_36 & V_50 )
F_1 ( V_2 , 0 ) ;
}
F_11 ( & V_2 -> V_48 , V_38 ) ;
F_8 ( & V_2 -> V_48 , V_38 ) ;
V_37 = F_9 ( V_5 -> V_18 + V_52 ) ;
if ( V_34 & V_43 ) {
F_10 ( ( V_37 & V_50 ) | V_51 ,
V_5 -> V_18 + V_52 ) ;
}
F_11 ( & V_2 -> V_48 , V_38 ) ;
if ( V_34 & V_53 ) {
V_35 = F_2 ( V_5 -> V_18 + V_54 ) ;
F_7 ( V_35 , V_5 -> V_18 + V_54 ) ;
}
if ( V_33 & V_55 ) {
F_12 ( V_2 -> V_56 , L_1 ) ;
V_12 -> V_57 |= V_58 ;
}
if ( V_33 & V_59 ) {
F_12 ( V_2 -> V_56 , L_2 ) ;
V_12 -> V_57 |= V_58 ;
}
if ( V_5 -> V_27 == 0 )
V_12 -> V_57 |= V_60 ;
F_13 ( V_2 , V_8 ) ;
return V_61 ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_38 ;
F_8 ( & V_2 -> V_48 , V_38 ) ;
F_15 ( V_5 -> V_18 , V_3 ) ;
F_11 ( & V_2 -> V_48 , V_38 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
F_7 ( 0 , V_2 -> V_45 + V_62 ) ;
F_7 ( 0 , V_2 -> V_45 + V_63 ) ;
F_14 ( V_2 , 0 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_31 * V_12 = V_8 -> V_12 ;
struct V_10 * V_11 = & V_12 -> V_11 ;
unsigned long V_38 ;
V_24 V_64 ;
if ( V_8 -> V_65 )
return - V_66 ;
F_7 ( V_67 , V_2 -> V_45 + V_62 ) ;
F_14 ( V_2 , 0 ) ;
V_5 -> V_19 = 0 ;
F_7 ( 0 , V_5 -> V_18 + V_68 ) ;
F_7 ( 0 , V_5 -> V_18 + V_69 ) ;
F_7 ( 0 , V_5 -> V_18 + V_70 ) ;
V_64 = V_5 -> V_71 | V_72 |
V_73 | V_74 ;
F_7 ( V_64 , V_5 -> V_18 + V_75 ) ;
F_8 ( & V_2 -> V_48 , V_38 ) ;
F_10 ( V_50 | V_76 | V_51 ,
V_5 -> V_18 + V_49 ) ;
F_11 ( & V_2 -> V_48 , V_38 ) ;
if ( V_11 -> V_25 == V_26 )
V_5 -> V_27 = V_11 -> V_77 ;
else
V_5 -> V_27 = 1 ;
F_7 ( V_59 | V_55 , V_2 -> V_45 + V_47 ) ;
F_7 ( V_78 , V_2 -> V_45 + V_63 ) ;
F_7 ( V_79 , V_2 -> V_45 + V_62 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_10 * V_11 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_11 -> V_81 ; V_80 ++ ) {
unsigned int V_82 = F_19 ( V_11 -> V_83 [ V_80 ] ) ;
if ( V_82 != V_80 ) {
F_20 ( V_2 -> V_56 ,
L_3 ) ;
return - V_66 ;
}
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_10 * V_11 )
{
int V_84 = 0 ;
if ( V_8 -> V_65 )
return - V_66 ;
V_84 |= F_22 ( & V_11 -> V_85 , V_86 ) ;
V_84 |= F_22 ( & V_11 -> V_87 , V_88 ) ;
V_84 |= F_22 ( & V_11 -> V_89 , V_86 ) ;
V_84 |= F_22 ( & V_11 -> V_90 , V_26 ) ;
V_84 |= F_22 ( & V_11 -> V_25 , V_26 | V_91 ) ;
if ( V_84 )
return 1 ;
V_84 |= F_23 ( V_11 -> V_25 ) ;
if ( V_84 )
return 2 ;
V_84 |= F_24 ( & V_11 -> V_92 , 0 ) ;
if ( ! V_11 -> V_81 || ! V_11 -> V_83 ) {
V_11 -> V_81 = 32 ;
V_84 |= - V_66 ;
}
V_84 |= F_24 ( & V_11 -> V_93 ,
V_11 -> V_81 ) ;
if ( V_11 -> V_25 == V_26 )
V_84 |= F_25 ( & V_11 -> V_77 , 1 ) ;
else
V_84 |= F_24 ( & V_11 -> V_77 , 0 ) ;
if ( V_84 )
return 3 ;
if ( V_11 -> V_83 && V_11 -> V_81 > 0 )
V_84 |= F_18 ( V_2 , V_8 , V_11 ) ;
if ( V_84 )
return 5 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned int V_94 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_3 V_95 = V_5 -> V_71 ;
V_24 V_96 = V_72 | V_73 |
V_74 ;
unsigned int V_97 = 0 ;
unsigned int V_13 = 0 ;
unsigned int V_80 ;
if ( V_94 > V_98 )
V_94 = V_98 ;
V_94 -= V_94 % sizeof( V_24 ) ;
if ( V_94 == 0 )
return - V_66 ;
for ( V_80 = 0 ; V_80 < V_99 && V_13 < V_100 ; V_80 ++ ) {
V_5 -> V_20 [ V_80 ] . V_21 =
F_27 ( V_5 -> V_101 [ V_13 ] + V_97 ) ;
V_5 -> V_20 [ V_80 ] . V_102 = F_27 ( V_103 ) ;
V_5 -> V_20 [ V_80 ] . V_104 = F_27 ( V_94 ) ;
V_5 -> V_20 [ V_80 ] . V_17 = F_27 ( ( V_95 +
( V_80 + 1 ) * sizeof( V_5 -> V_20 [ 0 ] ) ) | V_96 ) ;
V_5 -> V_28 [ V_80 ] = V_5 -> V_105 [ V_13 ] +
( V_97 / sizeof( V_24 ) ) ;
V_97 += V_94 ;
if ( V_94 + V_97 > V_98 ) {
V_97 = 0 ;
V_13 ++ ;
}
}
V_5 -> V_23 = V_80 ;
V_5 -> V_20 [ V_80 - 1 ] . V_17 = F_27 ( V_95 | V_96 ) ;
V_5 -> V_22 = V_94 ;
return V_94 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_106 * V_107 ,
unsigned int * V_108 )
{
int V_109 ;
switch ( V_108 [ 0 ] ) {
case V_110 :
V_109 = F_26 ( V_2 , V_108 [ 1 ] ) ;
if ( V_109 )
return V_109 ;
V_108 [ 1 ] = V_109 ;
break;
default:
V_109 = F_29 ( V_2 , V_8 , V_107 , V_108 , 0xffffffff ) ;
if ( V_109 )
return V_109 ;
break;
}
return V_107 -> V_111 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_112 * V_113 = F_31 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_80 ;
if ( ! V_5 )
return;
for ( V_80 = 0 ; V_80 < V_100 ; V_80 ++ ) {
if ( V_5 -> V_105 [ V_80 ] )
F_32 ( & V_113 -> V_2 ,
V_98 ,
V_5 -> V_105 [ V_80 ] ,
V_5 -> V_101 [ V_80 ] ) ;
}
if ( V_5 -> V_20 )
F_32 ( & V_113 -> V_2 ,
sizeof( struct V_114 ) *
V_99 ,
V_5 -> V_20 ,
V_5 -> V_71 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_24 V_115 ;
F_7 ( V_116 , V_2 -> V_45 + V_62 ) ;
F_34 ( 10 , 1000 ) ;
F_7 ( F_35 ( 32 ) | F_36 ( 32 ) ,
V_2 -> V_45 + V_117 ) ;
F_7 ( F_35 ( 32 ) | F_36 ( 32 ) ,
V_2 -> V_45 + V_118 ) ;
V_5 -> V_119 = F_2 ( V_2 -> V_45 + V_120 ) &
V_121 ;
V_5 -> V_122 = F_2 ( V_2 -> V_45 + V_123 ) &
V_121 ;
F_7 ( 0 , V_2 -> V_45 + V_63 ) ;
V_115 =
V_124 | V_125 | V_126 |
V_127 | V_128 | V_129 |
V_130 ;
F_7 ( V_115 , V_5 -> V_18 + V_41 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_24 V_64 ;
void T_4 * V_131 = V_5 -> V_18 ;
#ifdef F_38
V_64 = V_132 | V_133 ;
#else
V_64 = 0 ;
#endif
F_7 ( V_64 , V_5 -> V_18 + V_134 ) ;
F_7 ( 0 , V_5 -> V_18 + V_41 ) ;
F_14 ( V_2 , 0 ) ;
F_14 ( V_2 , 1 ) ;
V_64 = 0 ;
V_64 |= V_135 ;
V_64 |= V_136 ;
V_64 |= V_137 ;
V_64 |= V_138 ;
V_64 |= V_139 ;
V_64 |= V_140 ;
V_64 |= V_141 ;
V_64 |= V_142 ;
F_7 ( V_64 , V_131 + V_143 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned long V_144 )
{
struct V_112 * V_113 = F_31 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_80 ;
int V_145 ;
V_2 -> V_146 = L_4 ;
V_5 = F_40 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_147 ;
V_145 = F_41 ( V_2 ) ;
if ( V_145 )
return V_145 ;
F_42 ( V_113 ) ;
V_5 -> V_18 = F_43 ( V_113 , 0 ) ;
V_2 -> V_45 = F_43 ( V_113 , 2 ) ;
if ( ! V_5 -> V_18 || ! V_2 -> V_45 ) {
F_44 ( V_2 -> V_56 , L_5 ) ;
return - V_147 ;
}
F_37 ( V_2 ) ;
if ( F_45 ( V_113 -> V_29 , F_6 , V_148 ,
V_2 -> V_146 , V_2 ) ) {
F_44 ( V_2 -> V_56 ,
L_6 , V_113 -> V_29 ) ;
return - V_66 ;
}
V_2 -> V_29 = V_113 -> V_29 ;
F_20 ( V_2 -> V_56 , L_7 , V_2 -> V_29 ) ;
for ( V_80 = 0 ; V_80 < V_100 ; V_80 ++ ) {
V_5 -> V_105 [ V_80 ] =
F_46 ( & V_113 -> V_2 , V_98 ,
& V_5 -> V_101 [ V_80 ] ,
V_149 ) ;
}
V_5 -> V_20 = F_46 ( & V_113 -> V_2 ,
sizeof( struct V_114 ) *
V_99 ,
& V_5 -> V_71 ,
V_149 ) ;
if ( V_5 -> V_71 & 0xf ) {
F_44 ( V_2 -> V_56 ,
L_8 ) ;
return - V_150 ;
}
V_145 = F_26 ( V_2 , 0x1000 ) ;
if ( V_145 < 0 )
return V_145 ;
V_145 = F_47 ( V_2 , 1 ) ;
if ( V_145 )
return V_145 ;
V_8 = & V_2 -> V_151 [ 0 ] ;
V_2 -> V_9 = V_8 ;
V_8 -> type = V_152 ;
V_8 -> V_153 = V_154 | V_155 | V_156 |
V_157 ;
V_8 -> V_158 = 32 ;
V_8 -> V_159 = 32 ;
V_8 -> V_160 = 1 ;
V_8 -> V_161 = & V_162 ;
V_8 -> V_163 = F_28 ;
V_8 -> V_164 = F_17 ;
V_8 -> V_165 = F_21 ;
V_8 -> V_166 = F_16 ;
return F_33 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_2 -> V_29 )
F_49 ( V_2 -> V_29 , V_2 ) ;
if ( V_5 ) {
if ( V_5 -> V_18 ) {
F_7 ( 0 , V_5 -> V_18 + V_41 ) ;
F_50 ( V_5 -> V_18 ) ;
}
if ( V_2 -> V_45 )
F_50 ( V_2 -> V_45 ) ;
}
F_51 ( V_2 ) ;
F_30 ( V_2 ) ;
}
static int F_52 ( struct V_112 * V_2 ,
const struct V_167 * V_168 )
{
return F_53 ( V_2 , & V_169 , V_168 -> V_170 ) ;
}
