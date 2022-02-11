static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
return F_2 ( V_2 -> V_5 , V_2 -> V_6 + V_3 , V_4 , 1 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_4 ( V_2 -> V_5 , V_2 -> V_6 + V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_7 ;
V_7 = F_3 ( V_2 , V_8 , V_9 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , V_10 , & V_4 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_8 , V_9 ) ;
if ( V_7 )
return V_7 ;
V_4 |= V_11 ;
return F_3 ( V_2 , V_10 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , bool V_12 )
{
return F_3 ( V_2 , V_13 , V_12 ? V_14 : 0 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_2 V_15 , V_16 , V_17 , V_18 , V_19 , V_20 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_21 , & V_15 ) ;
if ( V_7 )
return;
V_7 = F_1 ( V_2 , V_22 , & V_18 ) ;
if ( V_7 )
return;
V_7 = F_1 ( V_2 , V_23 , & V_17 ) ;
if ( V_7 )
return;
V_7 = F_1 ( V_2 , V_24 , & V_20 ) ;
if ( V_7 )
return;
V_7 = F_1 ( V_2 , V_25 , & V_16 ) ;
if ( V_7 )
return;
V_7 = F_1 ( V_2 , V_13 , & V_19 ) ;
if ( V_7 )
return;
F_8 ( V_2 -> V_26 ,
L_1 ,
V_15 , V_19 , V_17 , V_18 , V_20 , V_16 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
T_2 V_29 , V_30 ;
int V_7 ;
V_30 = ( V_31 << V_32 ) |
V_33 | V_34 ;
V_7 = F_3 ( V_2 , V_21 , V_30 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_23 , V_28 -> V_35 ) ;
if ( V_7 )
return V_7 ;
V_29 = V_28 -> V_29 << V_36 ;
V_7 = F_3 ( V_2 , V_22 , V_29 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_37 , V_28 -> V_38 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_39 , V_28 -> V_40 ) ;
if ( V_7 )
return V_7 ;
if ( V_28 -> V_40 )
V_7 = F_3 ( V_2 , V_41 , V_42 ) ;
else
V_7 = F_3 ( V_2 , V_41 , 0 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_43 )
{
unsigned int V_44 , V_45 ;
T_2 V_16 ;
int V_7 ;
V_45 = V_43 / V_46 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
V_7 = F_1 ( V_2 , V_25 , & V_16 ) ;
if ( V_7 )
return V_7 ;
V_16 &= V_47 ;
if ( V_16 == V_48 )
return 0 ;
F_11 ( V_46 , V_49 ) ;
}
F_7 ( V_2 ) ;
return - V_50 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_4 )
{
int V_7 ;
V_7 = F_2 ( V_2 -> V_5 , V_2 -> V_6 + V_51 , V_4 , 2 ) ;
if ( V_7 )
return V_7 ;
* V_4 = F_13 ( T_1 , * V_4 , V_52 , V_53 ) ;
return 0 ;
}
static struct V_27 * F_14 ( struct V_1 * V_2 ,
unsigned int V_54 )
{
unsigned int V_55 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_56 ; V_55 ++ )
if ( V_2 -> V_57 [ V_55 ] . V_35 == V_54 )
return & V_2 -> V_57 [ V_55 ] ;
F_15 ( V_2 -> V_26 , L_2 , V_54 ) ;
return NULL ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_27 * V_28 , T_1 * V_4 )
{
unsigned int V_58 ;
int V_7 ;
F_17 ( & V_2 -> V_59 ) ;
V_7 = F_9 ( V_2 , V_28 ) ;
if ( V_7 )
goto V_60;
if ( ! V_2 -> V_61 )
F_18 ( & V_2 -> V_62 ) ;
V_7 = F_6 ( V_2 , true ) ;
if ( V_7 )
goto V_60;
V_7 = F_3 ( V_2 , V_24 , V_63 ) ;
if ( V_7 )
goto V_64;
V_58 = F_19 ( V_28 -> V_40 ) * V_46 * 2 ;
if ( V_2 -> V_61 ) {
V_7 = F_10 ( V_2 , V_58 ) ;
} else {
V_7 = F_20 ( & V_2 -> V_62 , V_58 ) ;
if ( ! V_7 ) {
V_7 = - V_50 ;
goto V_64;
}
V_7 = F_10 ( V_2 , V_46 ) ;
if ( V_7 )
goto V_64;
}
V_7 = F_12 ( V_2 , V_4 ) ;
V_64:
F_6 ( V_2 , false ) ;
if ( V_7 )
F_8 ( V_2 -> V_26 , L_3 ) ;
V_60:
F_21 ( & V_2 -> V_59 ) ;
return V_7 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
T_1 V_65 , V_66 ;
int V_7 ;
V_2 -> V_67 [ V_68 ] . V_69 = V_70 ;
V_2 -> V_67 [ V_71 ] . V_69 = V_72 ;
V_28 = F_14 ( V_2 , V_73 ) ;
V_7 = F_16 ( V_2 , V_28 , & V_65 ) ;
if ( V_7 )
goto V_74;
V_28 = F_14 ( V_2 , V_75 ) ;
if ( ! V_28 )
V_28 = F_14 ( V_2 , V_76 ) ;
V_7 = F_16 ( V_2 , V_28 , & V_66 ) ;
if ( V_7 )
goto V_74;
if ( V_65 == V_66 ) {
V_7 = - V_77 ;
goto V_74;
}
V_2 -> V_67 [ V_71 ] . V_78 = V_65 - V_66 ;
V_2 -> V_67 [ V_71 ] . V_79 = V_66 ;
V_28 = F_14 ( V_2 , V_80 ) ;
V_7 = F_16 ( V_2 , V_28 , & V_65 ) ;
if ( V_7 )
goto V_74;
V_28 = F_14 ( V_2 , V_81 ) ;
V_7 = F_16 ( V_2 , V_28 , & V_66 ) ;
if ( V_7 )
goto V_74;
if ( V_65 == V_66 ) {
V_7 = - V_77 ;
goto V_74;
}
V_2 -> V_67 [ V_68 ] . V_78 = V_65 - V_66 ;
V_2 -> V_67 [ V_68 ] . V_79 = V_66 ;
V_74:
if ( V_7 )
F_8 ( V_2 -> V_26 , L_4 ) ;
return V_7 ;
}
static T_3 F_23 ( struct V_1 * V_2 ,
const struct V_27 * V_28 , T_1 V_82 )
{
const struct V_83 * V_84 ;
T_3 V_85 ;
V_85 = V_82 - V_2 -> V_67 [ V_28 -> V_86 ] . V_79 ;
V_85 *= V_2 -> V_67 [ V_28 -> V_86 ] . V_69 ;
V_85 = V_85 / V_2 -> V_67 [ V_28 -> V_86 ] . V_78 ;
if ( V_28 -> V_86 == V_71 )
V_85 += V_2 -> V_67 [ V_28 -> V_86 ] . V_69 ;
if ( V_85 < 0 )
V_85 = 0 ;
V_84 = & V_87 [ V_28 -> V_84 ] ;
V_85 = V_85 * V_84 -> V_88 ;
return V_85 / V_84 -> V_54 ;
}
static int F_24 ( T_4 V_89 )
{
if ( ! F_25 ( V_89 ) || V_89 < V_90 ||
V_89 > V_91 )
return - V_77 ;
return F_26 ( V_89 / V_90 ) ;
}
static int F_27 ( T_4 V_54 , T_4 V_88 )
{
unsigned int V_92 ;
for ( V_92 = 0 ; V_92 < F_28 ( V_87 ) ; V_92 ++ )
if ( V_87 [ V_92 ] . V_54 == V_54 &&
V_87 [ V_92 ] . V_88 == V_88 )
break;
if ( V_92 == F_28 ( V_87 ) )
return - V_77 ;
return V_92 ;
}
static int F_29 ( T_4 V_89 )
{
if ( ( V_89 <= 1000 && V_89 % 100 ) || ( V_89 > 1000 && V_89 % 2000 ) )
return - V_77 ;
if ( V_89 <= 1000 )
V_89 /= 100 ;
else
V_89 = V_89 / 2000 + 10 ;
return V_89 ;
}
static int F_30 ( T_4 V_89 )
{
if ( ! F_25 ( V_89 ) || V_89 > V_93 )
return - V_77 ;
return F_26 ( V_89 ) ;
}
static int F_31 ( struct V_94 * V_95 ,
struct V_96 const * V_17 , int * V_97 , int * V_98 ,
long V_99 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
struct V_27 * V_28 ;
T_1 V_82 ;
int V_7 ;
switch ( V_99 ) {
case V_100 :
V_28 = & V_2 -> V_57 [ V_17 -> V_101 ] ;
V_7 = F_16 ( V_2 , V_28 , & V_82 ) ;
if ( V_7 )
break;
* V_97 = F_23 ( V_2 , V_28 , V_82 ) ;
* V_97 /= 2 ;
* V_97 -= V_102 ;
return V_103 ;
case V_104 :
V_28 = & V_2 -> V_57 [ V_17 -> V_101 ] ;
V_7 = F_16 ( V_2 , V_28 , & V_82 ) ;
if ( V_7 )
break;
* V_97 = F_23 ( V_2 , V_28 , V_82 ) ;
return V_103 ;
case V_105 :
* V_97 = 0 ;
* V_98 = 1000 ;
return V_106 ;
default:
V_7 = - V_77 ;
break;
}
return V_7 ;
}
static int F_33 ( struct V_94 * V_95 ,
const struct V_107 * V_108 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
unsigned int V_55 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_56 ; V_55 ++ )
if ( V_2 -> V_109 [ V_55 ] . V_35 == V_108 -> args [ 0 ] )
return V_55 ;
return - V_77 ;
}
static int F_34 ( struct V_110 * V_26 ,
struct V_27 * V_28 ,
struct V_111 * V_112 )
{
const char * V_113 = V_112 -> V_113 ;
T_4 V_17 , V_89 , V_114 [ 2 ] ;
int V_7 ;
V_7 = F_35 ( V_112 , L_5 , & V_17 ) ;
if ( V_7 ) {
F_8 ( V_26 , L_6 , V_113 ) ;
return V_7 ;
}
if ( V_17 > V_115 || V_17 < V_116 ) {
F_8 ( V_26 , L_7 , V_113 , V_17 ) ;
return - V_77 ;
}
V_28 -> V_35 = V_17 ;
V_7 = F_35 ( V_112 , L_8 , & V_89 ) ;
if ( ! V_7 ) {
V_7 = F_24 ( V_89 ) ;
if ( V_7 < 0 ) {
F_8 ( V_26 , L_9 ,
V_17 , V_89 ) ;
return V_7 ;
}
V_28 -> V_29 = V_7 ;
} else {
V_28 -> V_29 = V_117 ;
}
V_7 = F_36 ( V_112 , L_10 , V_114 , 2 ) ;
if ( ! V_7 ) {
V_7 = F_27 ( V_114 [ 0 ] , V_114 [ 1 ] ) ;
if ( V_7 < 0 ) {
F_8 ( V_26 , L_11 ,
V_17 , V_114 [ 0 ] , V_114 [ 1 ] ) ;
return V_7 ;
}
V_28 -> V_84 = V_7 ;
} else {
V_28 -> V_84 = V_118 [ V_28 -> V_35 ] . V_119 ;
}
V_7 = F_35 ( V_112 , L_12 , & V_89 ) ;
if ( ! V_7 ) {
V_7 = F_29 ( V_89 ) ;
if ( V_7 < 0 ) {
F_8 ( V_26 , L_13 ,
V_17 , V_89 ) ;
return V_7 ;
}
V_28 -> V_38 = V_7 ;
} else {
V_28 -> V_38 = V_120 ;
}
V_7 = F_35 ( V_112 , L_14 , & V_89 ) ;
if ( ! V_7 ) {
V_7 = F_30 ( V_89 ) ;
if ( V_7 < 0 ) {
F_8 ( V_26 , L_15 ,
V_17 , V_89 ) ;
return V_7 ;
}
V_28 -> V_40 = V_7 ;
} else {
V_28 -> V_40 = V_121 ;
}
if ( F_37 ( V_112 , L_16 ) )
V_28 -> V_86 = V_68 ;
else
V_28 -> V_86 = V_71 ;
F_15 ( V_26 , L_17 , V_17 , V_113 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_111 * V_112 )
{
const struct V_122 * V_123 ;
struct V_96 * V_124 ;
struct V_27 V_28 ;
struct V_111 * V_125 ;
unsigned int V_126 = 0 ;
int V_7 ;
V_2 -> V_56 = F_39 ( V_112 ) ;
if ( ! V_2 -> V_56 )
return - V_77 ;
V_2 -> V_109 = F_40 ( V_2 -> V_26 , V_2 -> V_56 ,
sizeof( * V_2 -> V_109 ) , V_127 ) ;
if ( ! V_2 -> V_109 )
return - V_128 ;
V_2 -> V_57 = F_40 ( V_2 -> V_26 , V_2 -> V_56 ,
sizeof( * V_2 -> V_57 ) , V_127 ) ;
if ( ! V_2 -> V_57 )
return - V_128 ;
V_124 = V_2 -> V_109 ;
F_41 (node, child) {
V_7 = F_34 ( V_2 -> V_26 , & V_28 , V_125 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_57 [ V_126 ] = V_28 ;
V_123 = & V_118 [ V_28 . V_35 ] ;
V_124 -> V_35 = V_28 . V_35 ;
V_124 -> V_129 = V_123 -> V_129 ;
V_124 -> V_130 = V_123 -> V_131 ;
V_124 -> type = V_123 -> type ;
V_124 -> V_132 = 1 ;
V_124 -> V_101 = V_126 ++ ;
V_124 ++ ;
}
if ( ! F_14 ( V_2 , V_73 ) ) {
F_8 ( V_2 -> V_26 , L_18 ) ;
return - V_133 ;
}
if ( ! F_14 ( V_2 , V_76 ) ) {
F_8 ( V_2 -> V_26 , L_19 ) ;
return - V_133 ;
}
if ( ! F_14 ( V_2 , V_80 ) ) {
F_8 ( V_2 -> V_26 , L_20 ) ;
return - V_133 ;
}
if ( ! F_14 ( V_2 , V_81 ) ) {
F_8 ( V_2 -> V_26 , L_21 ) ;
return - V_133 ;
}
return 0 ;
}
static T_5 F_42 ( int V_134 , void * V_135 )
{
struct V_1 * V_2 = V_135 ;
V_62 ( & V_2 -> V_62 ) ;
return V_136 ;
}
static int F_43 ( struct V_1 * V_2 )
{
T_2 V_97 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_137 , & V_97 ) ;
if ( V_7 )
return V_7 ;
if ( V_97 < V_138 ) {
F_8 ( V_2 -> V_26 , L_22 , V_97 ) ;
return - V_133 ;
}
V_7 = F_1 ( V_2 , V_139 , & V_97 ) ;
if ( V_7 )
return V_7 ;
if ( V_97 < V_140 ) {
F_8 ( V_2 -> V_26 , L_23 , V_97 ) ;
return - V_133 ;
}
V_7 = F_1 ( V_2 , V_141 , & V_97 ) ;
if ( V_7 )
return V_7 ;
if ( V_97 < V_142 ) {
F_8 ( V_2 -> V_26 , L_24 , V_97 ) ;
return - V_133 ;
}
return 0 ;
}
static int F_44 ( struct V_143 * V_144 )
{
struct V_111 * V_112 = V_144 -> V_26 . V_145 ;
struct V_110 * V_26 = & V_144 -> V_26 ;
struct V_94 * V_95 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
int V_7 , V_146 ;
T_4 V_147 ;
V_5 = F_45 ( V_26 -> V_148 , NULL ) ;
if ( ! V_5 )
return - V_133 ;
V_7 = F_35 ( V_112 , L_5 , & V_147 ) ;
if ( V_7 < 0 )
return V_7 ;
V_95 = F_46 ( V_26 , sizeof( * V_2 ) ) ;
if ( ! V_95 )
return - V_128 ;
V_2 = F_32 ( V_95 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_6 = V_147 ;
V_2 -> V_149 = false ;
F_47 ( & V_2 -> V_62 ) ;
F_48 ( & V_2 -> V_59 ) ;
V_7 = F_43 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_38 ( V_2 , V_112 ) ;
if ( V_7 )
return V_7 ;
V_146 = F_49 ( V_144 , 0 ) ;
if ( V_146 < 0 ) {
if ( V_146 == - V_150 || V_146 == - V_77 )
return V_146 ;
V_2 -> V_61 = true ;
} else {
V_7 = F_50 ( V_26 , V_146 , F_42 , 0 ,
L_25 , V_2 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_5 ( V_2 ) ;
if ( V_7 ) {
F_8 ( V_26 , L_26 ) ;
return V_7 ;
}
V_7 = F_22 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_95 -> V_26 . V_148 = V_26 ;
V_95 -> V_26 . V_145 = V_112 ;
V_95 -> V_113 = V_144 -> V_113 ;
V_95 -> V_151 = V_152 ;
V_95 -> V_153 = & V_154 ;
V_95 -> V_155 = V_2 -> V_109 ;
V_95 -> V_156 = V_2 -> V_56 ;
return F_51 ( V_26 , V_95 ) ;
}
