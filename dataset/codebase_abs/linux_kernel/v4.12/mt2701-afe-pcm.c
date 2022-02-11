static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_3 - V_5 ;
if ( V_4 < 0 || V_4 >= V_6 ) {
F_2 ( V_2 -> V_7 , L_1 ,
V_8 , V_3 , V_4 ) ;
return - V_9 ;
}
return V_4 ;
}
static int F_3 ( unsigned int V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_4 ( V_12 ) ; V_11 ++ )
if ( V_12 [ V_11 ] . V_13 == V_10 )
return V_12 [ V_11 ] . V_14 ;
return - V_9 ;
}
static int F_5 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
int V_26 = F_1 ( V_2 , V_18 -> V_27 ) ;
int V_28 = V_29 + V_26 ;
int V_30 = 0 ;
if ( V_26 < 0 )
return V_26 ;
V_30 = F_7 ( V_24 -> V_31 [ V_28 ] ) ;
if ( V_30 )
F_2 ( V_2 -> V_7 , L_2 ,
V_26 ) ;
return V_30 ;
}
static int F_8 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
int V_32 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
int V_26 = F_1 ( V_2 , V_18 -> V_27 ) ;
struct V_33 * V_34 ;
const struct V_35 * V_36 ;
int V_37 = V_16 -> V_38 ;
if ( V_26 < 0 )
return V_26 ;
V_34 = & V_24 -> V_34 [ V_26 ] ;
if ( V_32 ) {
if ( V_37 == V_39 )
V_37 = V_40 ;
else
V_37 = V_39 ;
}
V_36 = V_34 -> V_36 [ V_37 ] ;
V_34 -> V_41 [ V_37 ] -- ;
if ( V_34 -> V_41 [ V_37 ] < 0 ) {
F_9 ( V_2 -> V_7 , L_3 ,
V_34 -> V_41 [ V_37 ] , V_37 ) ;
V_34 -> V_41 [ V_37 ] = 0 ;
}
if ( V_34 -> V_41 [ V_37 ] )
return 0 ;
F_10 ( V_2 -> V_42 , V_36 -> V_43 ,
V_44 , 0 ) ;
F_10 ( V_2 -> V_42 , V_45 ,
1 << V_36 -> V_46 ,
1 << V_36 -> V_46 ) ;
return 0 ;
}
static void F_11 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
int V_26 = F_1 ( V_2 , V_18 -> V_27 ) ;
struct V_33 * V_34 ;
int V_28 = V_29 + V_26 ;
if ( V_26 < 0 )
return;
V_34 = & V_24 -> V_34 [ V_26 ] ;
if ( V_34 -> V_47 [ V_16 -> V_38 ] )
V_34 -> V_47 [ V_16 -> V_38 ] = 0 ;
else
goto V_48;
F_8 ( V_16 , V_18 , 0 ) ;
if ( V_16 -> V_38 == V_40 )
F_8 ( V_16 , V_18 , 1 ) ;
V_48:
F_12 ( V_24 -> V_31 [ V_28 ] ) ;
}
static int F_13 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
int V_32 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
int V_26 = F_1 ( V_2 , V_18 -> V_27 ) ;
struct V_33 * V_34 ;
const struct V_35 * V_36 ;
struct V_49 * const V_50 = V_16 -> V_50 ;
int V_51 , V_52 , V_53 = 1 ;
int V_37 = V_16 -> V_38 ;
unsigned int V_54 = 0 , V_4 = 0 ;
if ( V_26 < 0 )
return V_26 ;
V_34 = & V_24 -> V_34 [ V_26 ] ;
if ( V_32 ) {
if ( V_37 == V_39 )
V_37 = V_40 ;
else
V_37 = V_39 ;
}
V_36 = V_34 -> V_36 [ V_37 ] ;
V_34 -> V_41 [ V_37 ] ++ ;
if ( V_34 -> V_41 [ V_37 ] != 1 )
return 0 ;
V_52 = F_3 ( V_50 -> V_13 ) ;
V_54 = V_55 |
V_56 |
V_57 |
V_58 ;
V_4 = F_14 ( V_52 ) |
V_57 |
F_15 ( V_53 ) ;
if ( V_37 == V_40 ) {
V_54 |= V_59 ;
V_4 |= V_59 ;
}
F_10 ( V_2 -> V_42 , V_36 -> V_43 , V_54 , V_4 ) ;
if ( V_37 == V_39 )
V_51 = V_60 ;
else
V_51 = V_61 ;
F_10 ( V_2 -> V_42 , V_51 ,
V_36 -> V_62
<< V_36 -> V_63 ,
V_52 << V_36 -> V_63 ) ;
F_10 ( V_2 -> V_42 , V_45 ,
1 << V_36 -> V_46 ,
0 << V_36 -> V_46 ) ;
F_10 ( V_2 -> V_42 , V_36 -> V_43 ,
V_64 , V_64 ) ;
F_16 ( 1 ) ;
F_10 ( V_2 -> V_42 , V_36 -> V_43 ,
V_64 , 0 ) ;
F_16 ( 1 ) ;
F_10 ( V_2 -> V_42 , V_36 -> V_43 ,
V_44 , V_44 ) ;
return 0 ;
}
static int F_17 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_65 ;
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
int V_26 = F_1 ( V_2 , V_18 -> V_27 ) ;
struct V_33 * V_34 ;
int V_66 ;
if ( V_26 < 0 )
return V_26 ;
V_34 = & V_24 -> V_34 [ V_26 ] ;
V_66 = V_34 -> V_66 ;
if ( V_34 -> V_47 [ V_16 -> V_38 ] )
return - V_67 ;
V_34 -> V_47 [ V_16 -> V_38 ] = 1 ;
if ( V_68 % V_66 == 0 ) {
V_65 = 0 ;
} else if ( V_69 % V_66 == 0 ) {
V_65 = 1 ;
} else {
F_2 ( V_18 -> V_7 , L_4 ,
V_8 , V_66 ) ;
return - V_9 ;
}
F_18 ( V_2 , V_26 , V_65 , V_66 ) ;
if ( V_16 -> V_38 == V_39 ) {
F_13 ( V_16 , V_18 , 0 ) ;
} else {
F_13 ( V_16 , V_18 , 1 ) ;
F_13 ( V_16 , V_18 , 0 ) ;
}
return 0 ;
}
static int F_19 ( struct V_17 * V_18 , int V_70 ,
unsigned int V_71 , int V_72 )
{
struct V_1 * V_2 = F_20 ( V_18 -> V_7 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
int V_26 = F_1 ( V_2 , V_18 -> V_27 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_72 == V_73 ) {
F_9 ( V_18 -> V_7 ,
L_5 ,
V_8 ) ;
return - V_9 ;
}
V_24 -> V_34 [ V_26 ] . V_66 = V_71 ;
return 0 ;
}
static int F_21 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
F_10 ( V_2 -> V_42 , V_45 ,
V_74 , 0 ) ;
V_24 -> V_75 [ V_16 -> V_38 ] = 1 ;
return 0 ;
}
static int F_22 ( struct V_15 * V_16 ,
struct V_76 * V_77 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
int V_78 ;
T_1 V_4 , V_79 ;
V_78 = F_23 ( V_77 ) ;
if ( ( V_78 != 8000 ) && ( V_78 != 16000 ) ) {
F_2 ( V_2 -> V_7 , L_6 ,
V_8 , V_78 ) ;
return - V_9 ;
}
F_10 ( V_2 -> V_42 , V_80 ,
V_81 ,
V_82 ) ;
V_4 = V_83 | V_84
| V_85 ;
V_79 = V_4 ;
if ( V_78 == 16000 )
V_4 |= V_86 ;
V_79 |= V_86 ;
F_10 ( V_2 -> V_42 , V_87 , V_79 , V_4 ) ;
F_10 ( V_2 -> V_42 , V_87 ,
V_88 ,
V_88 ) ;
F_10 ( V_2 -> V_42 , V_80 ,
V_89 ,
V_89 ) ;
F_10 ( V_2 -> V_42 , V_80 ,
V_90 ,
V_90 ) ;
return 0 ;
}
static void F_24 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
if ( ! V_24 -> V_75 [ ! V_16 -> V_38 ] ) {
F_10 ( V_2 -> V_42 , V_87 ,
V_88 , 0 ) ;
F_10 ( V_2 -> V_42 , V_80 ,
V_90 , 0 ) ;
F_10 ( V_2 -> V_42 , V_80 ,
V_89 , 0 ) ;
F_10 ( V_2 -> V_42 , V_45 ,
V_74 ,
V_74 ) ;
}
V_24 -> V_75 [ V_16 -> V_38 ] = 0 ;
}
static int F_25 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
int V_37 = V_16 -> V_38 ;
int V_91 = V_20 -> V_92 -> V_27 ;
struct V_93 * V_94 ;
if ( V_37 == V_39 ) {
V_94 = & V_2 -> V_95 [ V_96 ] ;
if ( V_94 -> V_16 ) {
F_9 ( V_2 -> V_7 , L_7 ,
V_8 , V_37 , V_91 ) ;
return - V_67 ;
}
}
return F_26 ( V_16 , V_18 ) ;
}
static int F_27 ( struct V_15 * V_16 ,
struct V_76 * V_77 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
int V_37 = V_16 -> V_38 ;
if ( V_37 == V_39 ) {
F_10 ( V_2 -> V_42 ,
V_97 ,
V_98 ,
V_99 ) ;
}
return F_28 ( V_16 , V_77 , V_18 ) ;
}
static int F_29 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
struct V_93 * V_94 ;
const struct V_100 * V_101 ;
int V_11 ;
for ( V_11 = V_102 ; V_11 < V_103 ; ++ V_11 ) {
V_94 = & V_2 -> V_95 [ V_11 ] ;
if ( V_94 -> V_16 )
return - V_67 ;
}
for ( V_11 = V_102 ; V_11 < V_103 ; ++ V_11 ) {
V_101 = V_2 -> V_95 [ V_11 ] . V_104 ;
F_10 ( V_2 -> V_42 ,
V_101 -> V_105 ,
1 << V_101 -> V_106 ,
0 << V_101 -> V_106 ) ;
}
return F_26 ( V_16 , V_18 ) ;
}
static void F_30 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
const struct V_100 * V_101 ;
int V_11 ;
for ( V_11 = V_102 ; V_11 < V_103 ; ++ V_11 ) {
V_101 = V_2 -> V_95 [ V_11 ] . V_104 ;
F_10 ( V_2 -> V_42 ,
V_101 -> V_105 ,
1 << V_101 -> V_106 ,
1 << V_101 -> V_106 ) ;
}
return F_31 ( V_16 , V_18 ) ;
}
static int F_32 ( struct V_15 * V_16 ,
struct V_76 * V_77 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
int V_107 = F_33 ( V_77 ) ;
F_10 ( V_2 -> V_42 ,
V_97 ,
V_98 ,
V_108 ) ;
F_10 ( V_2 -> V_42 ,
V_97 ,
V_109 ,
V_110 ) ;
F_10 ( V_2 -> V_42 ,
V_97 ,
V_111 ,
F_34 ( V_107 ) ) ;
return F_28 ( V_16 , V_77 , V_18 ) ;
}
static int F_35 ( struct V_15 * V_16 ,
int V_112 , struct V_17 * V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_20 -> V_22 ) ;
struct V_93 * V_94 = & V_2 -> V_95 [ V_102 ] ;
switch ( V_112 ) {
case V_113 :
case V_114 :
F_10 ( V_2 -> V_42 , V_94 -> V_104 -> V_115 ,
1 << V_94 -> V_104 -> V_116 ,
1 << V_94 -> V_104 -> V_116 ) ;
F_36 ( V_16 , V_112 , V_18 ) ;
return 0 ;
case V_117 :
case V_118 :
F_36 ( V_16 , V_112 , V_18 ) ;
F_10 ( V_2 -> V_42 , V_94 -> V_104 -> V_115 ,
1 << V_94 -> V_104 -> V_116 , 0 ) ;
return 0 ;
default:
return - V_9 ;
}
}
static int F_37 ( struct V_15 * V_16 ,
unsigned int V_13 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
int V_52 ;
if ( V_20 -> V_92 -> V_27 != V_119 )
V_52 = F_3 ( V_13 ) ;
else
V_52 = ( V_13 == 16000 ? 1 : 0 ) ;
return V_52 ;
}
static int F_38 ( struct V_15 * V_16 , unsigned int V_13 )
{
return F_3 ( V_13 ) ;
}
static T_2 F_39 ( int V_120 , void * V_7 )
{
int V_27 ;
struct V_1 * V_2 = V_7 ;
struct V_93 * V_95 ;
struct V_121 * V_122 ;
T_1 V_123 ;
F_40 ( V_2 -> V_42 , V_124 , & V_123 ) ;
F_41 ( V_2 -> V_42 , V_125 , V_123 ) ;
for ( V_27 = 0 ; V_27 < V_126 ; ++ V_27 ) {
V_95 = & V_2 -> V_95 [ V_27 ] ;
if ( V_95 -> V_127 < 0 )
continue;
V_122 = & V_2 -> V_128 [ V_95 -> V_127 ] ;
if ( V_123 & 1 << ( V_122 -> V_129 -> V_130 ) )
F_42 ( V_95 -> V_16 ) ;
}
return V_131 ;
}
static int F_43 ( struct V_132 * V_7 )
{
struct V_1 * V_2 = F_20 ( V_7 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_132 * V_7 )
{
struct V_1 * V_2 = F_20 ( V_7 ) ;
return F_46 ( V_2 ) ;
}
static int F_47 ( struct V_133 * V_134 )
{
int V_30 , V_11 ;
unsigned int V_120 ;
struct V_1 * V_2 ;
struct V_23 * V_24 ;
struct V_135 * V_136 ;
struct V_132 * V_7 ;
V_30 = 0 ;
V_2 = F_48 ( & V_134 -> V_7 , sizeof( * V_2 ) , V_137 ) ;
if ( ! V_2 )
return - V_138 ;
V_2 -> V_25 = F_48 ( & V_134 -> V_7 , sizeof( * V_24 ) ,
V_137 ) ;
if ( ! V_2 -> V_25 )
return - V_138 ;
V_24 = V_2 -> V_25 ;
V_2 -> V_7 = & V_134 -> V_7 ;
V_7 = V_2 -> V_7 ;
V_120 = F_49 ( V_134 , 0 ) ;
if ( ! V_120 ) {
F_2 ( V_7 , L_8 , V_7 -> V_139 -> V_140 ) ;
return - V_141 ;
}
V_30 = F_50 ( V_7 , V_120 , F_39 ,
V_142 , L_9 , ( void * ) V_2 ) ;
if ( V_30 ) {
F_2 ( V_7 , L_10 ) ;
return V_30 ;
}
V_136 = F_51 ( V_134 , V_143 , 0 ) ;
V_2 -> V_144 = F_52 ( & V_134 -> V_7 , V_136 ) ;
if ( F_53 ( V_2 -> V_144 ) )
return F_54 ( V_2 -> V_144 ) ;
V_2 -> V_42 = F_55 ( & V_134 -> V_7 , V_2 -> V_144 ,
& V_145 ) ;
if ( F_53 ( V_2 -> V_42 ) )
return F_54 ( V_2 -> V_42 ) ;
F_56 ( & V_2 -> V_146 ) ;
V_2 -> V_147 = V_126 ;
V_2 -> V_95 = F_57 ( V_7 , V_2 -> V_147 , sizeof( * V_2 -> V_95 ) ,
V_137 ) ;
if ( ! V_2 -> V_95 )
return - V_138 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_147 ; V_11 ++ ) {
V_2 -> V_95 [ V_11 ] . V_104 = & V_101 [ V_11 ] ;
V_2 -> V_95 [ V_11 ] . V_127 = - 1 ;
}
V_2 -> V_148 = V_149 ;
V_2 -> V_128 = F_57 ( V_7 , V_2 -> V_148 , sizeof( * V_2 -> V_128 ) ,
V_137 ) ;
if ( ! V_2 -> V_128 )
return - V_138 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_148 ; V_11 ++ )
V_2 -> V_128 [ V_11 ] . V_129 = & V_129 [ V_11 ] ;
for ( V_11 = 0 ; V_11 < V_6 ; V_11 ++ ) {
V_24 -> V_34 [ V_11 ] . V_36 [ V_150 ]
= & V_35 [ V_11 ] [ V_150 ] ;
V_24 -> V_34 [ V_11 ] . V_36 [ V_151 ]
= & V_35 [ V_11 ] [ V_151 ] ;
}
V_2 -> V_152 = & V_153 ;
V_2 -> V_154 = F_37 ;
V_2 -> V_155 = F_38 ;
V_2 -> V_156 = V_157 ;
V_2 -> V_158 = F_4 ( V_157 ) ;
V_2 -> V_159 = F_45 ;
V_2 -> V_160 = F_43 ;
V_30 = F_58 ( V_2 ) ;
if ( V_30 ) {
F_2 ( V_7 , L_11 ) ;
return V_30 ;
}
F_59 ( V_134 , V_2 ) ;
F_60 ( & V_134 -> V_7 ) ;
if ( ! F_61 ( & V_134 -> V_7 ) )
goto V_161;
F_62 ( & V_134 -> V_7 ) ;
V_30 = F_63 ( & V_134 -> V_7 , & V_162 ) ;
if ( V_30 ) {
F_9 ( V_7 , L_12 ) ;
goto V_163;
}
V_30 = F_64 ( & V_134 -> V_7 ,
& V_164 ,
V_165 ,
F_4 ( V_165 ) ) ;
if ( V_30 ) {
F_9 ( V_7 , L_13 ) ;
goto V_166;
}
F_45 ( & V_134 -> V_7 ) ;
return 0 ;
V_166:
F_65 ( & V_134 -> V_7 ) ;
V_163:
F_66 ( & V_134 -> V_7 ) ;
V_161:
F_67 ( & V_134 -> V_7 ) ;
return V_30 ;
}
static int F_68 ( struct V_133 * V_134 )
{
struct V_1 * V_2 = F_69 ( V_134 ) ;
F_67 ( & V_134 -> V_7 ) ;
if ( ! F_70 ( & V_134 -> V_7 ) )
F_43 ( & V_134 -> V_7 ) ;
F_71 ( & V_134 -> V_7 ) ;
F_65 ( & V_134 -> V_7 ) ;
F_66 ( & V_134 -> V_7 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
