static bool F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , int V_6 )
{
T_2 V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_6 / 10 ; V_8 ++ ) {
V_7 = F_2 ( V_2 , V_3 ) ;
if ( ( V_7 & V_4 ) == V_5 )
return true ;
F_3 ( 10 ) ;
}
F_4 ( L_1 , V_3 ) ;
return false ;
}
static void F_5 ( struct V_9 * V_9 , struct V_10 * V_11 )
{
T_2 V_7 ;
int V_8 ;
if ( ! V_11 -> V_12 )
return;
F_6 ( V_9 , V_11 -> V_12 + V_13 ,
V_14 ) ;
for ( V_8 = 0 ; V_8 < 10000 / 10 ; V_8 ++ ) {
V_7 = F_7 ( V_9 , V_11 -> V_12 + V_15 ) ;
V_7 &= V_16 ;
if ( V_7 == V_17 ||
V_7 == V_18 ||
V_7 == V_19 ) {
V_8 = 0 ;
break;
}
F_3 ( 10 ) ;
}
if ( V_8 )
F_8 ( V_9 , L_2 ,
V_11 -> V_12 , V_7 ) ;
F_6 ( V_9 , V_11 -> V_12 + V_13 , 0 ) ;
if ( ! F_1 ( V_9 -> V_2 ,
V_11 -> V_12 + V_15 ,
V_16 , V_17 ,
10000 ) ) {
F_9 ( V_9 , L_3 ,
V_11 -> V_12 ) ;
F_3 ( 300 ) ;
V_7 = F_7 ( V_9 , V_11 -> V_12 + V_15 ) ;
if ( ( V_7 & V_16 ) != V_17 )
F_8 ( V_9 , L_4 ,
V_11 -> V_12 ) ;
}
}
static void F_10 ( struct V_9 * V_9 ,
struct V_10 * V_11 )
{
T_2 V_20 ;
V_20 = F_7 ( V_9 , V_11 -> V_12 + V_13 ) ;
V_20 |= V_21 ;
V_20 |= V_22 ;
F_6 ( V_9 , V_11 -> V_12 + V_13 , V_20 ) ;
}
static T_3 F_11 ( struct V_9 * V_9 ,
struct V_10 * V_11 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_9 -> V_2 -> V_26 ;
struct V_27 * V_28 = V_9 -> V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
T_2 V_33 , V_34 ;
int V_35 ;
if ( V_24 -> V_36 > V_37 ) {
F_8 ( V_9 , L_5 , V_24 -> V_36 ) ;
goto V_38;
}
if ( V_11 -> V_39 <= V_11 -> V_40 )
V_35 = V_11 -> V_39 - V_11 -> V_40 + V_41 ;
else
V_35 = V_11 -> V_39 - V_11 -> V_40 ;
if ( V_35 == 1 ) {
F_8 ( V_9 , L_6 ) ;
F_12 ( V_28 ) ;
return V_42 ;
}
V_32 = & V_11 -> V_43 [ V_11 -> V_40 ] ;
V_32 -> V_24 = V_24 ;
V_32 -> V_44 = F_13 ( V_26 , V_24 -> V_45 , V_24 -> V_36 ,
V_46 ) ;
if ( F_14 ( V_26 , V_32 -> V_44 ) ) {
F_8 ( V_9 , L_7 ,
V_11 -> V_12 ) ;
goto V_38;
}
V_33 = V_47 | V_48 | V_49 ;
if ( V_11 -> V_40 == V_11 -> V_50 - 1 )
V_33 |= V_51 ;
V_34 = V_24 -> V_36 & V_37 ;
V_30 = V_11 -> V_52 ;
V_30 += V_11 -> V_40 ;
V_30 -> V_53 = F_15 ( F_16 ( V_32 -> V_44 ) ) ;
V_30 -> V_54 = F_15 ( F_17 ( V_32 -> V_44 ) ) ;
V_30 -> V_33 = F_15 ( V_33 ) ;
V_30 -> V_34 = F_15 ( V_34 ) ;
F_18 ( V_28 , V_24 -> V_36 ) ;
F_19 () ;
if ( ++ V_11 -> V_40 >= V_41 )
V_11 -> V_40 = 0 ;
F_6 ( V_9 , V_11 -> V_12 + V_55 ,
V_11 -> V_56 +
V_11 -> V_40 * sizeof( struct V_29 ) ) ;
if ( -- V_35 == 1 )
F_12 ( V_28 ) ;
return V_57 ;
V_38:
F_12 ( V_28 ) ;
F_20 ( V_24 ) ;
return V_57 ;
}
static void F_21 ( struct V_9 * V_9 , struct V_10 * V_11 )
{
struct V_25 * V_26 = V_9 -> V_2 -> V_26 ;
int V_58 ;
bool V_59 = false ;
unsigned V_60 = 0 , V_61 = 0 ;
V_58 = F_7 ( V_9 , V_11 -> V_12 + V_15 ) ;
V_58 &= V_62 ;
V_58 -= V_11 -> V_56 ;
V_58 &= V_62 ;
V_58 /= sizeof( struct V_29 ) ;
while ( V_11 -> V_39 != V_58 ) {
struct V_31 * V_32 = & V_11 -> V_43 [ V_11 -> V_39 ] ;
if ( V_32 -> V_24 ) {
F_22 ( V_26 , V_32 -> V_44 ,
V_32 -> V_24 -> V_36 , V_46 ) ;
V_32 -> V_44 = 0 ;
V_60 += V_32 -> V_24 -> V_36 ;
V_61 ++ ;
F_20 ( V_32 -> V_24 ) ;
V_32 -> V_24 = NULL ;
} else {
F_8 ( V_9 , L_8 ,
V_11 -> V_39 , V_11 -> V_40 ) ;
}
if ( ++ V_11 -> V_39 >= V_41 )
V_11 -> V_39 = 0 ;
V_59 = true ;
}
F_23 ( V_9 -> V_28 , V_61 , V_60 ) ;
if ( V_59 && F_24 ( V_9 -> V_28 ) )
F_25 ( V_9 -> V_28 ) ;
}
static void F_26 ( struct V_9 * V_9 , struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 )
return;
F_6 ( V_9 , V_11 -> V_12 + V_63 , 0 ) ;
if ( ! F_1 ( V_9 -> V_2 ,
V_11 -> V_12 + V_64 ,
V_65 , V_66 ,
10000 ) )
F_8 ( V_9 , L_9 ,
V_11 -> V_12 ) ;
}
static void F_27 ( struct V_9 * V_9 ,
struct V_10 * V_11 )
{
T_2 V_20 ;
V_20 = F_7 ( V_9 , V_11 -> V_12 + V_63 ) ;
V_20 &= V_67 ;
V_20 |= V_68 ;
V_20 |= V_69 ;
V_20 |= V_70 ;
V_20 |= V_71 << V_72 ;
F_6 ( V_9 , V_11 -> V_12 + V_63 , V_20 ) ;
}
static int F_28 ( struct V_9 * V_9 ,
struct V_31 * V_32 )
{
struct V_25 * V_26 = V_9 -> V_2 -> V_26 ;
struct V_23 * V_24 ;
T_4 V_44 ;
struct V_73 * V_74 ;
V_24 = F_29 ( V_9 -> V_28 , V_75 ) ;
if ( ! V_24 )
return - V_76 ;
V_74 = (struct V_73 * ) V_24 -> V_45 ;
V_74 -> V_36 = F_30 ( 0xdead ) ;
V_74 -> V_77 = F_30 ( 0xbeef ) ;
V_44 = F_13 ( V_26 , V_24 -> V_45 ,
V_75 , V_78 ) ;
if ( F_14 ( V_26 , V_44 ) ) {
F_8 ( V_9 , L_10 ) ;
F_20 ( V_24 ) ;
return - V_76 ;
}
V_32 -> V_24 = V_24 ;
V_32 -> V_44 = V_44 ;
if ( V_32 -> V_44 & 0xC0000000 )
F_9 ( V_9 , L_11 ) ;
return 0 ;
}
static void F_31 ( struct V_9 * V_9 ,
struct V_10 * V_11 , int V_79 )
{
struct V_29 * V_30 = V_11 -> V_52 + V_79 ;
T_2 V_33 = 0 , V_34 = 0 ;
if ( V_79 == V_11 -> V_50 - 1 )
V_33 |= V_51 ;
V_34 |= V_75 & V_37 ;
V_30 -> V_53 = F_15 ( F_16 ( V_11 -> V_43 [ V_79 ] . V_44 ) ) ;
V_30 -> V_54 = F_15 ( F_17 ( V_11 -> V_43 [ V_79 ] . V_44 ) ) ;
V_30 -> V_33 = F_15 ( V_33 ) ;
V_30 -> V_34 = F_15 ( V_34 ) ;
}
static int F_32 ( struct V_9 * V_9 , struct V_10 * V_11 ,
int V_80 )
{
T_2 V_81 ;
int V_82 = 0 ;
V_81 = F_7 ( V_9 , V_11 -> V_12 + V_64 ) ;
V_81 &= V_83 ;
V_81 -= V_11 -> V_56 ;
V_81 &= V_83 ;
V_81 /= sizeof( struct V_29 ) ;
V_11 -> V_40 = V_81 ;
while ( V_11 -> V_39 != V_11 -> V_40 ) {
struct V_25 * V_26 = V_9 -> V_2 -> V_26 ;
struct V_31 * V_32 = & V_11 -> V_43 [ V_11 -> V_39 ] ;
struct V_23 * V_24 = V_32 -> V_24 ;
struct V_73 * V_74 ;
T_1 V_36 , V_77 ;
F_33 ( V_26 , V_32 -> V_44 ,
V_75 , V_78 ) ;
V_74 = (struct V_73 * ) V_24 -> V_45 ;
V_36 = F_34 ( V_74 -> V_36 ) ;
V_77 = F_34 ( V_74 -> V_77 ) ;
do {
T_4 V_84 = V_32 -> V_44 ;
int V_85 ;
if ( V_36 == 0xdead && V_77 == 0xbeef ) {
F_8 ( V_9 , L_12 ,
V_11 -> V_39 ) ;
F_35 ( V_26 ,
V_32 -> V_44 ,
V_75 ,
V_78 ) ;
break;
}
V_36 -= V_86 ;
V_85 = F_28 ( V_9 , V_32 ) ;
if ( V_85 ) {
V_74 -> V_36 = F_30 ( 0xdead ) ;
V_74 -> V_77 = F_30 ( 0xbeef ) ;
F_35 ( V_26 ,
V_32 -> V_44 ,
V_75 ,
V_78 ) ;
break;
}
F_31 ( V_9 , V_11 , V_11 -> V_39 ) ;
F_22 ( V_26 , V_84 ,
V_75 , V_78 ) ;
F_36 ( V_24 , V_71 + V_36 ) ;
F_37 ( V_24 , V_71 ) ;
F_38 ( V_24 ) ;
V_24 -> V_87 = F_39 ( V_24 , V_9 -> V_28 ) ;
F_40 ( V_24 ) ;
V_82 ++ ;
} while ( 0 );
if ( ++ V_11 -> V_39 >= V_88 )
V_11 -> V_39 = 0 ;
if ( V_82 >= V_80 )
break;
}
return V_82 ;
}
static bool F_41 ( struct V_9 * V_9 ,
struct V_10 * V_11 ,
enum V_89 V_90 )
{
switch ( V_90 ) {
case V_91 :
F_6 ( V_9 , V_11 -> V_12 + V_92 ,
0xff0 ) ;
if ( F_7 ( V_9 , V_11 -> V_12 + V_92 ) )
return true ;
break;
case V_93 :
F_6 ( V_9 , V_11 -> V_12 + V_94 ,
0xff0 ) ;
if ( F_7 ( V_9 , V_11 -> V_12 + V_94 ) )
return true ;
break;
}
return false ;
}
static void F_42 ( struct V_9 * V_9 ,
struct V_10 * V_11 )
{
struct V_25 * V_26 = V_9 -> V_2 -> V_26 ;
struct V_31 * V_32 ;
int V_95 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_11 -> V_50 ; V_8 ++ ) {
V_32 = & V_11 -> V_43 [ V_8 ] ;
if ( V_32 -> V_24 ) {
if ( V_32 -> V_44 )
F_22 ( V_26 , V_32 -> V_44 ,
V_32 -> V_24 -> V_36 , V_46 ) ;
F_20 ( V_32 -> V_24 ) ;
}
}
if ( V_11 -> V_52 ) {
V_95 = V_11 -> V_50 * sizeof( struct V_29 ) ;
F_43 ( V_26 , V_95 , V_11 -> V_52 ,
V_11 -> V_96 ) ;
}
}
static void F_44 ( struct V_9 * V_9 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_97 ; V_8 ++ )
F_42 ( V_9 , & V_9 -> V_98 [ V_8 ] ) ;
for ( V_8 = 0 ; V_8 < V_99 ; V_8 ++ )
F_42 ( V_9 , & V_9 -> V_100 [ V_8 ] ) ;
}
static int F_45 ( struct V_9 * V_9 )
{
struct V_25 * V_26 = V_9 -> V_2 -> V_26 ;
struct V_10 * V_11 ;
static const T_1 V_101 [] = { V_102 , V_103 ,
V_104 , V_105 , } ;
int V_95 ;
int V_85 ;
int V_8 ;
F_46 ( V_97 > F_47 ( V_101 ) ) ;
F_46 ( V_99 > F_47 ( V_101 ) ) ;
if ( ! ( F_48 ( V_9 -> V_2 , V_106 ) & V_107 ) ) {
F_8 ( V_9 , L_13 ) ;
return - V_108 ;
}
for ( V_8 = 0 ; V_8 < V_97 ; V_8 ++ ) {
V_11 = & V_9 -> V_98 [ V_8 ] ;
V_11 -> V_50 = V_41 ;
V_11 -> V_12 = V_101 [ V_8 ] ;
V_95 = V_11 -> V_50 * sizeof( struct V_29 ) ;
V_11 -> V_52 = F_49 ( V_26 , V_95 ,
& V_11 -> V_96 ,
V_109 ) ;
if ( ! V_11 -> V_52 ) {
F_8 ( V_9 , L_14 ,
V_11 -> V_12 ) ;
goto V_110;
}
if ( V_11 -> V_96 & 0xC0000000 )
F_9 ( V_9 , L_11 ) ;
V_11 -> V_111 = F_41 ( V_9 , V_11 ,
V_91 ) ;
if ( V_11 -> V_111 )
V_11 -> V_56 = F_16 ( V_11 -> V_96 ) ;
else
V_11 -> V_56 = 0 ;
}
for ( V_8 = 0 ; V_8 < V_99 ; V_8 ++ ) {
int V_112 ;
V_11 = & V_9 -> V_100 [ V_8 ] ;
V_11 -> V_50 = V_88 ;
V_11 -> V_12 = V_101 [ V_8 ] ;
V_95 = V_11 -> V_50 * sizeof( struct V_29 ) ;
V_11 -> V_52 = F_49 ( V_26 , V_95 ,
& V_11 -> V_96 ,
V_109 ) ;
if ( ! V_11 -> V_52 ) {
F_8 ( V_9 , L_15 ,
V_11 -> V_12 ) ;
V_85 = - V_76 ;
goto V_110;
}
if ( V_11 -> V_96 & 0xC0000000 )
F_9 ( V_9 , L_11 ) ;
V_11 -> V_111 = F_41 ( V_9 , V_11 ,
V_93 ) ;
if ( V_11 -> V_111 )
V_11 -> V_56 = F_16 ( V_11 -> V_96 ) ;
else
V_11 -> V_56 = 0 ;
for ( V_112 = 0 ; V_112 < V_11 -> V_50 ; V_112 ++ ) {
V_85 = F_28 ( V_9 , & V_11 -> V_43 [ V_112 ] ) ;
if ( V_85 ) {
F_8 ( V_9 , L_16 ) ;
goto V_110;
}
}
}
return 0 ;
V_110:
F_44 ( V_9 ) ;
return - V_76 ;
}
static void F_50 ( struct V_9 * V_9 )
{
struct V_10 * V_11 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_97 ; V_8 ++ ) {
V_11 = & V_9 -> V_98 [ V_8 ] ;
if ( ! V_11 -> V_111 )
F_10 ( V_9 , V_11 ) ;
F_6 ( V_9 , V_11 -> V_12 + V_92 ,
F_16 ( V_11 -> V_96 ) ) ;
F_6 ( V_9 , V_11 -> V_12 + V_113 ,
F_17 ( V_11 -> V_96 ) ) ;
if ( V_11 -> V_111 )
F_10 ( V_9 , V_11 ) ;
V_11 -> V_39 = 0 ;
V_11 -> V_40 = 0 ;
}
for ( V_8 = 0 ; V_8 < V_99 ; V_8 ++ ) {
int V_112 ;
V_11 = & V_9 -> V_100 [ V_8 ] ;
if ( ! V_11 -> V_111 )
F_27 ( V_9 , V_11 ) ;
F_6 ( V_9 , V_11 -> V_12 + V_94 ,
F_16 ( V_11 -> V_96 ) ) ;
F_6 ( V_9 , V_11 -> V_12 + V_114 ,
F_17 ( V_11 -> V_96 ) ) ;
if ( V_11 -> V_111 )
F_27 ( V_9 , V_11 ) ;
for ( V_112 = 0 ; V_112 < V_11 -> V_50 ; V_112 ++ )
F_31 ( V_9 , V_11 , V_112 ) ;
F_6 ( V_9 , V_11 -> V_12 + V_115 ,
V_11 -> V_56 +
V_11 -> V_50 * sizeof( struct V_29 ) ) ;
V_11 -> V_39 = 0 ;
V_11 -> V_40 = 0 ;
}
}
static T_1 F_51 ( struct V_9 * V_9 , T_5 V_116 , T_5 V_3 )
{
struct V_1 * V_2 ;
T_1 V_117 ;
T_1 V_118 ;
T_2 V_119 ;
F_46 ( V_120 != V_121 ) ;
F_46 ( V_122 != V_123 ) ;
F_46 ( V_124 != V_125 ) ;
F_46 ( V_126 != V_127 ) ;
F_46 ( V_128 != V_129 ) ;
F_46 ( V_130 != V_131 ) ;
F_46 ( V_132 != V_133 ) ;
F_46 ( V_134 != V_135 ) ;
F_46 ( V_136 != V_137 ) ;
F_46 ( V_138 != V_139 ) ;
F_46 ( V_140 != V_141 ) ;
if ( V_9 -> V_2 -> V_142 . V_142 == V_143 ) {
V_2 = V_9 -> V_2 -> V_144 -> V_145 . V_2 ;
V_117 = V_146 ;
V_118 = V_147 ;
} else {
V_2 = V_9 -> V_2 ;
V_117 = V_148 ;
V_118 = V_149 ;
}
V_119 = F_2 ( V_2 , V_118 ) ;
V_119 &= ~ V_134 ;
V_119 |= V_116 ;
F_52 ( V_2 , V_118 , V_119 ) ;
V_119 = V_132 ;
V_119 |= V_116 << V_124 ;
V_119 |= V_3 << V_128 ;
F_52 ( V_2 , V_117 , V_119 ) ;
if ( ! F_1 ( V_2 , V_117 , V_132 , 0 , 1000 ) ) {
F_8 ( V_9 , L_17 ,
V_116 , V_3 ) ;
return 0xffff ;
}
return F_2 ( V_2 , V_117 ) & V_120 ;
}
static int F_53 ( struct V_9 * V_9 , T_5 V_116 , T_5 V_3 , T_1 V_5 )
{
struct V_1 * V_2 ;
T_1 V_117 ;
T_1 V_118 ;
T_2 V_119 ;
if ( V_9 -> V_2 -> V_142 . V_142 == V_143 ) {
V_2 = V_9 -> V_2 -> V_144 -> V_145 . V_2 ;
V_117 = V_146 ;
V_118 = V_147 ;
} else {
V_2 = V_9 -> V_2 ;
V_117 = V_148 ;
V_118 = V_149 ;
}
V_119 = F_2 ( V_2 , V_118 ) ;
V_119 &= ~ V_134 ;
V_119 |= V_116 ;
F_52 ( V_2 , V_118 , V_119 ) ;
F_6 ( V_9 , V_150 , V_151 ) ;
if ( F_7 ( V_9 , V_150 ) & V_151 )
F_9 ( V_9 , L_18 ) ;
V_119 = V_132 ;
V_119 |= V_130 ;
V_119 |= V_116 << V_124 ;
V_119 |= V_3 << V_128 ;
V_119 |= V_5 ;
F_52 ( V_2 , V_117 , V_119 ) ;
if ( ! F_1 ( V_2 , V_117 , V_132 , 0 , 1000 ) ) {
F_8 ( V_9 , L_19 ,
V_116 , V_3 ) ;
return - V_152 ;
}
return 0 ;
}
static void F_54 ( struct V_9 * V_9 )
{
T_1 V_20 ;
T_1 V_4 = ~ ( V_153 | V_154 |
V_155 | V_156 ) ;
if ( V_9 -> V_116 == V_157 )
return;
if ( V_9 -> V_158 )
return;
V_20 = F_51 ( V_9 , V_9 -> V_116 , V_159 ) ;
V_20 &= V_4 ;
if ( V_9 -> V_160 )
V_20 |= V_156 ;
if ( V_9 -> V_161 == V_162 )
V_20 |= V_163 ;
else if ( V_9 -> V_161 == V_164 )
V_20 |= V_165 ;
F_53 ( V_9 , V_9 -> V_116 , V_159 , V_20 ) ;
}
static void F_55 ( struct V_9 * V_9 )
{
T_1 V_166 ;
if ( V_9 -> V_116 == V_157 )
return;
if ( ! V_9 -> V_158 )
return;
V_166 = F_51 ( V_9 , V_9 -> V_116 , V_167 ) ;
V_166 &= ~ ( V_168 | V_169 |
V_170 | V_171 ) ;
if ( ! V_9 -> V_160 && V_9 -> V_161 & V_172 )
V_166 |= V_168 ;
if ( ! V_9 -> V_160 && V_9 -> V_161 & V_162 )
V_166 |= V_170 ;
if ( V_9 -> V_160 && V_9 -> V_161 & V_172 )
V_166 |= V_169 ;
if ( V_9 -> V_160 && V_9 -> V_161 & V_162 )
V_166 |= V_171 ;
F_53 ( V_9 , V_9 -> V_116 , V_167 , V_166 ) ;
V_166 = F_51 ( V_9 , V_9 -> V_116 , V_173 ) ;
V_166 &= ~ ( V_174 | V_175 ) ;
if ( ! V_9 -> V_160 && V_9 -> V_161 & V_164 )
V_166 |= V_174 ;
if ( V_9 -> V_160 && V_9 -> V_161 & V_164 )
V_166 |= V_175 ;
F_53 ( V_9 , V_9 -> V_116 , V_173 , V_166 ) ;
F_53 ( V_9 , V_9 -> V_116 , V_159 ,
F_51 ( V_9 , V_9 -> V_116 , V_159 ) |
V_176 ) ;
}
static void F_56 ( struct V_9 * V_9 )
{
struct V_177 * V_178 = & V_9 -> V_2 -> V_144 -> V_179 ;
struct V_180 * V_181 = & V_9 -> V_2 -> V_144 -> V_182 ;
T_5 V_8 ;
if ( V_178 -> V_142 == V_183 ) {
for ( V_8 = 0 ; V_8 < 5 ; V_8 ++ ) {
F_53 ( V_9 , V_8 , 0x1f , 0x008b ) ;
F_53 ( V_9 , V_8 , 0x15 , 0x0100 ) ;
F_53 ( V_9 , V_8 , 0x1f , 0x000f ) ;
F_53 ( V_9 , V_8 , 0x12 , 0x2aaa ) ;
F_53 ( V_9 , V_8 , 0x1f , 0x000b ) ;
}
}
if ( ( V_178 -> V_142 == V_184 && V_178 -> V_185 != 10 ) ||
( V_178 -> V_142 == V_186 && V_178 -> V_185 != 10 ) ||
( V_178 -> V_142 == V_187 && V_178 -> V_185 != 9 ) ) {
F_57 ( V_181 , 2 , ~ 0xc0000000 , 0 ) ;
F_57 ( V_181 , 4 , ~ 0x80000000 , 0 ) ;
for ( V_8 = 0 ; V_8 < 5 ; V_8 ++ ) {
F_53 ( V_9 , V_8 , 0x1f , 0x000f ) ;
F_53 ( V_9 , V_8 , 0x16 , 0x5284 ) ;
F_53 ( V_9 , V_8 , 0x1f , 0x000b ) ;
F_53 ( V_9 , V_8 , 0x17 , 0x0010 ) ;
F_53 ( V_9 , V_8 , 0x1f , 0x000f ) ;
F_53 ( V_9 , V_8 , 0x16 , 0x5296 ) ;
F_53 ( V_9 , V_8 , 0x17 , 0x1073 ) ;
F_53 ( V_9 , V_8 , 0x17 , 0x9073 ) ;
F_53 ( V_9 , V_8 , 0x16 , 0x52b6 ) ;
F_53 ( V_9 , V_8 , 0x17 , 0x9273 ) ;
F_53 ( V_9 , V_8 , 0x1f , 0x000b ) ;
}
}
}
static void F_58 ( struct V_9 * V_9 )
{
if ( V_9 -> V_116 == V_157 )
return;
F_53 ( V_9 , V_9 -> V_116 , V_159 ,
V_188 ) ;
F_3 ( 100 ) ;
if ( F_51 ( V_9 , V_9 -> V_116 , V_159 ) &
V_188 )
F_8 ( V_9 , L_20 ) ;
F_56 ( V_9 ) ;
}
static void F_59 ( struct V_9 * V_9 , T_2 V_4 , T_2 V_189 ,
bool V_190 )
{
T_2 V_191 = F_7 ( V_9 , V_192 ) ;
T_2 V_193 = ( V_191 & V_4 ) | V_189 ;
F_60 ( V_9 , V_192 , V_194 ) ;
F_3 ( 2 ) ;
if ( V_193 != V_191 || V_190 )
F_6 ( V_9 , V_192 , V_193 ) ;
F_61 ( V_9 , V_192 , ~ V_194 ) ;
F_3 ( 2 ) ;
}
static void F_62 ( struct V_9 * V_9 , T_5 * V_195 )
{
T_2 V_119 ;
V_119 = ( V_195 [ 0 ] << 24 ) | ( V_195 [ 1 ] << 16 ) | ( V_195 [ 2 ] << 8 ) | V_195 [ 3 ] ;
F_6 ( V_9 , V_196 , V_119 ) ;
V_119 = ( V_195 [ 4 ] << 8 ) | V_195 [ 5 ] ;
F_6 ( V_9 , V_197 , V_119 ) ;
}
static void F_63 ( struct V_27 * V_28 )
{
struct V_9 * V_9 = F_64 ( V_28 ) ;
if ( V_28 -> V_77 & V_198 )
F_59 ( V_9 , ~ 0 , V_199 , true ) ;
else
F_59 ( V_9 , ~ V_199 , 0 , true ) ;
}
static void F_65 ( struct V_9 * V_9 )
{
int V_8 ;
if ( V_9 -> V_2 -> V_142 . V_142 == V_143 )
return;
F_60 ( V_9 , V_200 , V_201 ) ;
for ( V_8 = 0 ; V_8 < V_202 ; V_8 ++ )
F_7 ( V_9 , V_203 + ( V_8 * 4 ) ) ;
for ( V_8 = 0 ; V_8 < V_204 ; V_8 ++ )
F_7 ( V_9 , V_205 + ( V_8 * 4 ) ) ;
}
static void F_66 ( struct V_9 * V_9 , int V_161 )
{
T_2 V_4 = ~ ( V_206 | V_207 ) ;
T_2 V_189 = 0 ;
if ( V_161 & V_172 )
V_189 |= V_208 ;
if ( V_161 & V_162 )
V_189 |= V_209 ;
if ( V_161 & V_164 )
V_189 |= V_210 ;
if ( ! V_9 -> V_160 )
V_189 |= V_207 ;
F_59 ( V_9 , V_4 , V_189 , true ) ;
}
static void F_67 ( struct V_9 * V_9 )
{
T_5 V_211 = ( F_7 ( V_9 , V_212 ) & V_213 ) >>
V_214 ;
if ( V_211 == 0 || V_211 == 1 ) {
if ( V_9 -> V_158 )
F_66 ( V_9 , V_162 ) ;
else
F_66 ( V_9 , V_9 -> V_161 ) ;
}
}
static void F_68 ( struct V_9 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_215 * V_144 = V_2 -> V_144 ;
struct V_177 * V_178 = & V_144 -> V_179 ;
T_2 V_77 = 0 ;
T_2 V_216 ;
int V_8 ;
if ( F_69 ( V_2 ) ) {
if ( ! V_9 -> V_217 ) {
V_9 -> V_217 = true ;
}
for ( V_8 = 0 ; V_8 < V_97 ; V_8 ++ )
F_5 ( V_9 , & V_9 -> V_98 [ V_8 ] ) ;
F_59 ( V_9 , ~ 0 , V_218 , false ) ;
F_3 ( 1 ) ;
for ( V_8 = 0 ; V_8 < V_99 ; V_8 ++ )
F_26 ( V_9 , & V_9 -> V_100 [ V_8 ] ) ;
}
V_216 = F_48 ( V_2 , V_106 ) ;
if ( ( V_178 -> V_142 == V_184 && V_178 -> V_185 == 10 ) ||
( V_178 -> V_142 == V_186 && V_178 -> V_185 == 10 ) ||
( V_178 -> V_142 == V_187 && V_178 -> V_185 == 9 ) )
V_216 &= ~ V_219 ;
if ( V_216 & V_219 ) {
V_77 = V_220 ;
if ( ! V_9 -> V_221 )
V_77 |= V_222 ;
}
F_70 ( V_2 , V_77 ) ;
if ( V_2 -> V_142 . V_223 > 2 ) {
F_60 ( V_9 , V_224 , 1 << 8 ) ;
F_1 ( V_9 -> V_2 , V_224 , 1 << 24 , 1 << 24 ,
1000 ) ;
}
if ( V_178 -> V_142 == V_184 || V_178 -> V_142 == V_186 ||
V_178 -> V_142 == V_187 ) {
struct V_180 * V_181 = & V_9 -> V_2 -> V_144 -> V_182 ;
T_5 V_225 = 0 ;
T_5 V_226 = V_227 |
V_228 ;
char V_229 [ 4 ] ;
if ( F_71 ( L_21 , V_229 , sizeof( V_229 ) ) > 0 ) {
if ( F_72 ( V_229 , 0 , & V_225 ) )
F_8 ( V_9 , L_22 ,
V_229 ) ;
V_225 &= 0x0f ;
V_225 <<= 4 ;
V_226 = V_225 ;
} else if ( V_178 -> V_142 == V_184 && V_178 -> V_185 == 9 ) {
V_226 = V_230 ;
} else if ( ( V_178 -> V_142 != V_187 && V_178 -> V_185 == 10 ) ||
( V_178 -> V_142 == V_187 && V_178 -> V_185 == 9 ) ) {
V_226 = V_231 |
V_232 ;
}
F_57 ( V_181 , 1 ,
~ ( V_233 |
V_234 ) ,
V_226 ) ;
}
if ( V_216 & V_219 && ! V_9 -> V_221 )
F_73 ( V_2 , V_235 ,
F_48 ( V_2 , V_235 ) &
~ V_222 ) ;
F_59 ( V_9 ,
~ ( V_236 |
V_237 |
V_238 |
V_239 |
V_207 |
V_218 |
V_240 |
V_241 |
V_242 |
V_243 |
V_244 |
V_245 |
V_246 ) ,
V_199 |
V_247 |
V_240 |
V_194 ,
false ) ;
F_65 ( V_9 ) ;
if ( V_2 -> V_142 . V_142 == V_143 )
F_74 ( V_9 -> V_248 , V_147 , ~ 0 ,
V_141 ) ;
else
F_60 ( V_9 , V_149 , V_140 ) ;
F_67 ( V_9 ) ;
F_56 ( V_9 ) ;
F_75 ( V_9 -> V_28 ) ;
V_9 -> V_249 = 0 ;
}
static void F_76 ( struct V_9 * V_9 )
{
F_6 ( V_9 , V_250 , V_9 -> V_251 ) ;
}
static void F_77 ( struct V_9 * V_9 )
{
F_6 ( V_9 , V_250 , 0 ) ;
F_7 ( V_9 , V_250 ) ;
}
static void F_78 ( struct V_9 * V_9 )
{
struct V_177 * V_178 = & V_9 -> V_2 -> V_144 -> V_179 ;
T_2 V_191 ;
T_2 V_252 ;
T_2 V_253 ;
T_2 V_254 ;
T_1 V_255 ;
T_5 V_256 ;
V_191 = F_7 ( V_9 , V_192 ) ;
F_59 ( V_9 , ~ ( V_236 | V_237 ) ,
V_194 , true ) ;
F_3 ( 2 ) ;
V_191 |= V_236 | V_237 ;
F_6 ( V_9 , V_192 , V_191 ) ;
V_252 = ( F_7 ( V_9 , V_212 ) & V_213 ) >>
V_214 ;
if ( V_178 -> V_142 != V_257 || V_252 != 0 )
F_60 ( V_9 , V_224 , V_258 ) ;
if ( V_178 -> V_142 == V_257 && V_252 == 2 )
F_57 ( & V_9 -> V_2 -> V_144 -> V_182 , 1 , ~ 0 ,
V_259 ) ;
switch ( V_178 -> V_142 ) {
case V_184 :
case V_186 :
case V_187 :
case V_260 :
case V_257 :
V_254 = 0x03cb04cb ;
if ( V_178 -> V_142 == V_184 ||
V_178 -> V_142 == V_186 ||
V_178 -> V_142 == V_187 )
V_254 = 0x2300e1 ;
F_6 ( V_9 , V_261 , V_254 ) ;
F_6 ( V_9 , V_262 , 0x27fff ) ;
break;
}
V_253 = F_7 ( V_9 , V_263 ) ;
V_253 &= ~ V_264 ;
V_255 = F_79 ( & V_9 -> V_2 -> V_144 -> V_182 ) / 1000000 ;
V_256 = ( V_255 * 128 / 1000 ) - 3 ;
V_253 |= ( V_256 << V_265 ) ;
F_6 ( V_9 , V_263 , V_253 ) ;
}
static void F_80 ( struct V_9 * V_9 , bool V_266 )
{
struct V_10 * V_11 ;
int V_8 ;
F_6 ( V_9 , V_267 , 1 << V_268 ) ;
F_59 ( V_9 , ~ V_238 , 0 , true ) ;
F_63 ( V_9 -> V_28 ) ;
F_62 ( V_9 , V_9 -> V_28 -> V_269 ) ;
if ( V_9 -> V_270 )
F_59 ( V_9 , ~ 0 , V_218 , false ) ;
else
F_59 ( V_9 , ~ V_218 , 0 , false ) ;
F_6 ( V_9 , V_271 , 32 + V_272 ) ;
if ( ! V_9 -> V_158 ) {
F_66 ( V_9 , V_9 -> V_161 ) ;
F_54 ( V_9 ) ;
} else if ( V_9 -> V_161 ) {
F_55 ( V_9 ) ;
}
if ( V_266 ) {
F_50 ( V_9 ) ;
if ( 1 )
F_76 ( V_9 ) ;
} else {
for ( V_8 = 0 ; V_8 < V_99 ; V_8 ++ ) {
V_11 = & V_9 -> V_100 [ V_8 ] ;
F_27 ( V_9 , V_11 ) ;
}
}
F_78 ( V_9 ) ;
}
static T_6 F_81 ( int V_273 , void * V_274 )
{
struct V_9 * V_9 = F_64 ( V_274 ) ;
T_2 V_249 = F_7 ( V_9 , V_150 ) ;
V_249 &= V_9 -> V_251 ;
if ( ! V_249 )
return V_275 ;
F_6 ( V_9 , V_150 , V_249 ) ;
F_77 ( V_9 ) ;
V_9 -> V_249 = V_249 ;
F_82 ( & V_9 -> V_276 ) ;
return V_277 ;
}
static int F_83 ( struct V_278 * V_276 , int V_80 )
{
struct V_9 * V_9 = F_84 ( V_276 , struct V_9 , V_276 ) ;
struct V_10 * V_11 ;
int V_82 = 0 ;
if ( V_9 -> V_249 & V_279 ) {
V_11 = & V_9 -> V_98 [ 0 ] ;
F_21 ( V_9 , V_11 ) ;
V_9 -> V_249 &= ~ V_279 ;
}
if ( V_9 -> V_249 & V_280 ) {
V_11 = & V_9 -> V_100 [ 0 ] ;
V_82 += F_32 ( V_9 , V_11 , V_80 ) ;
V_9 -> V_249 &= ~ V_280 ;
}
if ( V_9 -> V_249 ) {
F_8 ( V_9 , L_23 , V_9 -> V_249 ) ;
V_9 -> V_249 = 0 ;
}
if ( V_82 < V_80 )
F_85 ( V_276 ) ;
F_76 ( V_9 ) ;
return V_82 ;
}
static int F_86 ( struct V_27 * V_28 )
{
struct V_9 * V_9 = F_64 ( V_28 ) ;
int V_85 = 0 ;
F_68 ( V_9 ) ;
F_80 ( V_9 , true ) ;
V_85 = F_87 ( V_9 -> V_2 -> V_273 , F_81 , V_281 ,
V_282 , V_28 ) ;
if ( V_85 < 0 ) {
F_8 ( V_9 , L_24 , V_85 ) ;
goto V_283;
}
F_88 ( & V_9 -> V_276 ) ;
F_89 ( V_28 ) ;
V_283:
return V_85 ;
}
static int F_90 ( struct V_27 * V_28 )
{
struct V_9 * V_9 = F_64 ( V_28 ) ;
F_91 ( V_28 ) ;
F_92 ( & V_9 -> V_276 ) ;
F_77 ( V_9 ) ;
F_93 ( V_9 -> V_2 -> V_273 , V_28 ) ;
F_68 ( V_9 ) ;
return 0 ;
}
static T_3 F_94 ( struct V_23 * V_24 ,
struct V_27 * V_28 )
{
struct V_9 * V_9 = F_64 ( V_28 ) ;
struct V_10 * V_11 ;
V_11 = & V_9 -> V_98 [ 0 ] ;
return F_11 ( V_9 , V_11 , V_24 ) ;
}
static int F_95 ( struct V_27 * V_28 , void * V_195 )
{
struct V_9 * V_9 = F_64 ( V_28 ) ;
int V_284 ;
V_284 = F_96 ( V_28 , V_195 ) ;
if ( V_284 < 0 )
return V_284 ;
F_62 ( V_9 , ( T_5 * ) V_195 ) ;
F_97 ( V_28 , V_195 ) ;
return 0 ;
}
static int F_98 ( struct V_27 * V_28 , struct V_285 * V_286 , int V_287 )
{
struct V_9 * V_9 = F_64 ( V_28 ) ;
struct V_288 * V_45 = F_99 ( V_286 ) ;
switch ( V_287 ) {
case V_289 :
V_45 -> V_290 = V_9 -> V_116 ;
case V_291 :
if ( ! F_100 ( V_28 ) )
return - V_292 ;
V_45 -> V_293 = F_51 ( V_9 , V_45 -> V_290 ,
V_45 -> V_294 & 0x1f ) ;
return 0 ;
case V_295 :
if ( ! F_100 ( V_28 ) )
return - V_292 ;
F_53 ( V_9 , V_45 -> V_290 , V_45 -> V_294 & 0x1f ,
V_45 -> V_296 ) ;
return 0 ;
default:
return - V_297 ;
}
}
static int F_101 ( struct V_27 * V_28 ,
struct V_298 * V_287 )
{
struct V_9 * V_9 = F_64 ( V_28 ) ;
V_287 -> V_299 = V_300 |
V_301 |
V_302 |
V_303 |
V_304 |
V_305 |
V_306 ;
if ( V_9 -> V_158 ) {
F_102 ( V_287 -> V_307 ) ;
if ( V_9 -> V_160 ) {
if ( V_9 -> V_161 & V_172 )
V_287 -> V_307 |= V_308 ;
if ( V_9 -> V_161 & V_162 )
V_287 -> V_307 |= V_309 ;
if ( V_9 -> V_161 & V_164 )
V_287 -> V_307 |= V_310 ;
} else {
if ( V_9 -> V_161 & V_172 )
V_287 -> V_307 |= V_311 ;
if ( V_9 -> V_161 & V_162 )
V_287 -> V_307 |= V_312 ;
if ( V_9 -> V_161 & V_164 )
V_287 -> V_307 |= V_313 ;
}
} else {
switch ( V_9 -> V_161 ) {
case V_172 :
F_103 ( V_287 , V_314 ) ;
break;
case V_162 :
F_103 ( V_287 , V_315 ) ;
break;
case V_164 :
F_103 ( V_287 , V_316 ) ;
break;
}
}
V_287 -> V_317 = V_9 -> V_160 ? V_318 : V_319 ;
V_287 -> V_158 = V_9 -> V_158 ;
return 0 ;
}
static void F_104 ( struct V_27 * V_28 ,
struct V_320 * V_321 )
{
F_105 ( V_321 -> V_322 , V_282 , sizeof( V_321 -> V_322 ) ) ;
F_105 ( V_321 -> V_323 , L_25 , sizeof( V_321 -> V_323 ) ) ;
}
static int F_106 ( struct V_324 * V_144 , int V_325 , int V_326 )
{
return F_51 ( V_144 -> V_327 , V_325 , V_326 ) ;
}
static int F_107 ( struct V_324 * V_144 , int V_325 , int V_326 ,
T_1 V_5 )
{
return F_53 ( V_144 -> V_327 , V_325 , V_326 , V_5 ) ;
}
static int F_108 ( struct V_9 * V_9 )
{
struct V_324 * V_324 ;
int V_8 , V_85 = 0 ;
V_324 = F_109 () ;
if ( ! V_324 )
return - V_76 ;
V_324 -> V_328 = L_26 ;
sprintf ( V_324 -> V_142 , L_27 , L_28 , V_9 -> V_2 -> V_144 -> V_329 ,
V_9 -> V_2 -> V_330 ) ;
V_324 -> V_327 = V_9 ;
V_324 -> V_331 = F_106 ;
V_324 -> V_332 = F_107 ;
V_324 -> V_333 = & V_9 -> V_2 -> V_334 ;
V_324 -> V_335 = ~ ( 1 << V_9 -> V_116 ) ;
V_324 -> V_273 = F_110 ( V_336 , sizeof( int ) , V_109 ) ;
if ( ! V_324 -> V_273 ) {
V_85 = - V_76 ;
goto V_337;
}
for ( V_8 = 0 ; V_8 < V_336 ; V_8 ++ )
V_324 -> V_273 [ V_8 ] = V_338 ;
V_85 = F_111 ( V_324 ) ;
if ( V_85 ) {
F_8 ( V_9 , L_29 ) ;
goto V_339;
}
V_9 -> V_324 = V_324 ;
return V_85 ;
V_339:
F_112 ( V_324 -> V_273 ) ;
V_337:
F_113 ( V_324 ) ;
return V_85 ;
}
static void F_114 ( struct V_9 * V_9 )
{
struct V_324 * V_324 = V_9 -> V_324 ;
F_115 ( V_324 ) ;
F_112 ( V_324 -> V_273 ) ;
F_113 ( V_324 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
struct V_9 * V_9 ;
struct V_340 * V_341 = & V_2 -> V_144 -> V_341 ;
T_5 * V_342 = V_2 -> V_330 ? V_341 -> V_343 : V_341 -> V_344 ;
int V_85 ;
if ( V_2 -> V_330 > 1 ) {
F_4 ( L_30 , V_2 -> V_330 ) ;
return - V_108 ;
}
if ( ! F_117 ( V_342 ) ) {
F_118 ( & V_2 -> V_334 , L_31 , V_342 ) ;
F_119 ( V_342 ) ;
F_120 ( & V_2 -> V_334 , L_32 , V_342 ) ;
}
V_28 = F_121 ( sizeof( * V_9 ) ) ;
if ( ! V_28 )
return - V_76 ;
V_28 -> V_345 = & V_346 ;
V_28 -> V_273 = V_2 -> V_273 ;
F_122 ( V_28 , & V_347 ) ;
V_9 = F_64 ( V_28 ) ;
V_9 -> V_28 = V_28 ;
V_9 -> V_2 = V_2 ;
F_123 ( V_2 , V_9 ) ;
V_9 -> V_158 = true ;
V_9 -> V_160 = true ;
V_9 -> V_161 = V_172 | V_162 | V_164 ;
memcpy ( V_9 -> V_28 -> V_269 , V_342 , V_348 ) ;
if ( V_2 -> V_142 . V_142 == V_143 &&
! V_2 -> V_144 -> V_145 . V_2 ) {
F_8 ( V_9 , L_33 ) ;
V_85 = - V_349 ;
goto V_350;
}
V_9 -> V_248 = V_2 -> V_144 -> V_145 . V_2 ;
V_9 -> V_116 = V_2 -> V_330 ? V_341 -> V_351 :
V_341 -> V_352 ;
V_9 -> V_116 &= V_353 ;
if ( V_9 -> V_116 == V_353 ) {
F_8 ( V_9 , L_34 ) ;
V_85 = - V_349 ;
goto V_350;
}
F_124 ( V_9 , L_35 , V_9 -> V_116 ,
V_9 -> V_116 == V_157 ? L_36 : L_37 ) ;
if ( V_2 -> V_144 -> V_354 == V_355 ) {
F_8 ( V_9 , L_38 ) ;
V_85 = - V_108 ;
goto V_350;
}
F_68 ( V_9 ) ;
V_85 = F_45 ( V_9 ) ;
if ( V_85 ) {
F_8 ( V_9 , L_39 ) ;
goto V_350;
}
V_9 -> V_251 = V_356 | V_280 | V_357 ;
if ( F_71 ( L_40 , NULL , 0 ) == 0 )
V_9 -> V_251 &= ~ V_357 ;
F_58 ( V_9 ) ;
V_9 -> V_221 = ! ! ( V_2 -> V_144 -> V_341 . V_358 &
V_359 ) ;
if ( V_9 -> V_221 )
F_9 ( V_9 , L_41 ) ;
if ( V_2 -> V_144 -> V_341 . V_358 & V_360 )
F_9 ( V_9 , L_42 ) ;
V_85 = F_108 ( V_9 ) ;
if ( V_85 ) {
F_8 ( V_9 , L_43 ) ;
V_85 = - V_108 ;
goto V_110;
}
V_85 = F_125 ( V_9 -> V_28 ) ;
if ( V_85 ) {
F_8 ( V_9 , L_44 ) ;
V_85 = - V_108 ;
goto V_361;
}
F_91 ( V_28 ) ;
F_126 ( V_28 , & V_9 -> V_276 , F_83 , V_362 ) ;
return 0 ;
V_361:
F_114 ( V_9 ) ;
V_110:
F_44 ( V_9 ) ;
V_350:
F_123 ( V_2 , NULL ) ;
F_127 ( V_28 ) ;
return V_85 ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_129 ( V_2 ) ;
F_130 ( & V_9 -> V_276 ) ;
F_131 ( V_9 -> V_28 ) ;
F_114 ( V_9 ) ;
F_44 ( V_9 ) ;
F_123 ( V_2 , NULL ) ;
F_127 ( V_9 -> V_28 ) ;
}
static int T_7 F_132 ( void )
{
int V_85 ;
V_85 = F_133 ( & V_363 ) ;
if ( V_85 )
return V_85 ;
F_134 ( L_45 ) ;
return 0 ;
}
static void T_8 F_135 ( void )
{
F_136 ( & V_363 ) ;
}
