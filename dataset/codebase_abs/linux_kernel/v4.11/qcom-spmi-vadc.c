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
static int F_23 ( const struct V_82 * V_83 ,
T_3 V_84 , T_4 V_85 , T_5 * V_86 )
{
bool V_87 = 1 ;
T_3 V_55 = 0 ;
if ( ! V_83 )
return - V_77 ;
if ( V_84 > 1 ) {
if ( V_83 [ 0 ] . V_88 < V_83 [ 1 ] . V_88 )
V_87 = 0 ;
}
while ( V_55 < V_84 ) {
if ( ( V_87 ) && ( V_83 [ V_55 ] . V_88 < V_85 ) ) {
break;
} else if ( ( ! V_87 ) &&
( V_83 [ V_55 ] . V_88 > V_85 ) ) {
break;
}
V_55 ++ ;
}
if ( V_55 == 0 ) {
* V_86 = V_83 [ 0 ] . V_89 ;
} else if ( V_55 == V_84 ) {
* V_86 = V_83 [ V_84 - 1 ] . V_89 ;
} else {
* V_86 = ( ( ( T_4 ) ( ( V_83 [ V_55 ] . V_89 - V_83 [ V_55 - 1 ] . V_89 ) *
( V_85 - V_83 [ V_55 - 1 ] . V_88 ) ) /
( V_83 [ V_55 ] . V_88 - V_83 [ V_55 - 1 ] . V_88 ) ) +
V_83 [ V_55 - 1 ] . V_89 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_90 ,
const struct V_27 * V_28 ,
T_5 * V_91 )
{
* V_91 = ( V_90 -
V_2 -> V_67 [ V_28 -> V_92 ] . V_79 ) ;
* V_91 *= V_2 -> V_67 [ V_28 -> V_92 ] . V_69 ;
* V_91 = F_25 ( * V_91 ,
V_2 -> V_67 [ V_28 -> V_92 ] . V_78 ) ;
if ( V_28 -> V_92 == V_71 )
* V_91 +=
V_2 -> V_67 [ V_28 -> V_92 ] . V_69 ;
if ( * V_91 < 0 )
* V_91 = 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_27 * V_28 , T_1 V_90 ,
int * V_93 )
{
const struct V_94 * V_95 ;
T_5 V_96 = 0 , V_97 = 0 ;
F_24 ( V_2 , V_90 , V_28 , & V_96 ) ;
V_95 = & V_98 [ V_28 -> V_95 ] ;
V_96 = V_96 * V_95 -> V_99 ;
V_97 = F_25 ( V_96 , V_95 -> V_54 ) ;
* V_93 = V_97 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
const struct V_27 * V_28 , T_1 V_90 ,
int * V_100 )
{
T_5 V_96 = 0 , V_97 = 0 ;
F_24 ( V_2 , V_90 , V_28 , & V_96 ) ;
if ( V_28 -> V_92 == V_71 )
V_96 = F_25 ( V_96 , 1000 ) ;
F_23 ( V_101 ,
F_28 ( V_101 ) ,
V_96 , & V_97 ) ;
V_97 *= 1000 ;
* V_100 = V_97 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_27 * V_28 ,
T_1 V_90 , int * V_100 )
{
const struct V_94 * V_95 ;
T_5 V_96 = 0 ;
T_6 V_102 ;
F_24 ( V_2 , V_90 , V_28 , & V_96 ) ;
if ( V_96 > 0 ) {
V_95 = & V_98 [ V_28 -> V_95 ] ;
V_102 = V_96 * V_95 -> V_99 ;
F_30 ( V_102 , V_95 -> V_54 * 2 ) ;
V_96 = V_102 ;
} else {
V_96 = 0 ;
}
V_96 -= V_103 ;
* V_100 = V_96 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_27 * V_28 ,
T_1 V_90 , int * V_100 )
{
const struct V_94 * V_95 ;
T_5 V_96 = 0 , V_97 = 0 ;
F_24 ( V_2 , V_90 , V_28 , & V_96 ) ;
V_95 = & V_98 [ V_28 -> V_95 ] ;
V_96 = V_96 * V_95 -> V_99 ;
V_96 = F_25 ( V_96 , V_95 -> V_54 ) ;
V_96 = ( ( V_104 ) * ( V_96 * 2 ) ) ;
V_96 = ( V_96 + V_105 ) ;
V_97 = F_25 ( V_96 , 1000000 ) ;
* V_100 = V_97 ;
return 0 ;
}
static int F_32 ( T_3 V_106 )
{
if ( ! F_33 ( V_106 ) || V_106 < V_107 ||
V_106 > V_108 )
return - V_77 ;
return F_34 ( V_106 / V_107 ) ;
}
static int F_35 ( T_3 V_54 , T_3 V_99 )
{
unsigned int V_109 ;
for ( V_109 = 0 ; V_109 < F_28 ( V_98 ) ; V_109 ++ )
if ( V_98 [ V_109 ] . V_54 == V_54 &&
V_98 [ V_109 ] . V_99 == V_99 )
break;
if ( V_109 == F_28 ( V_98 ) )
return - V_77 ;
return V_109 ;
}
static int F_36 ( T_3 V_106 )
{
if ( ( V_106 <= 1000 && V_106 % 100 ) || ( V_106 > 1000 && V_106 % 2000 ) )
return - V_77 ;
if ( V_106 <= 1000 )
V_106 /= 100 ;
else
V_106 = V_106 / 2000 + 10 ;
return V_106 ;
}
static int F_37 ( T_3 V_106 )
{
if ( ! F_33 ( V_106 ) || V_106 > V_110 )
return - V_77 ;
return F_34 ( V_106 ) ;
}
static int F_38 ( struct V_111 * V_112 ,
struct V_113 const * V_17 , int * V_114 , int * V_115 ,
long V_116 )
{
struct V_1 * V_2 = F_39 ( V_112 ) ;
struct V_27 * V_28 ;
T_1 V_90 ;
int V_7 ;
switch ( V_116 ) {
case V_117 :
V_28 = & V_2 -> V_57 [ V_17 -> V_118 ] ;
V_7 = F_16 ( V_2 , V_28 , & V_90 ) ;
if ( V_7 )
break;
V_119 [ V_28 -> V_119 ] . F_40 ( V_2 , V_28 , V_90 , V_114 ) ;
return V_120 ;
case V_121 :
V_28 = & V_2 -> V_57 [ V_17 -> V_118 ] ;
V_7 = F_16 ( V_2 , V_28 , & V_90 ) ;
if ( V_7 )
break;
* V_114 = ( int ) V_90 ;
return V_120 ;
default:
V_7 = - V_77 ;
break;
}
return V_7 ;
}
static int F_41 ( struct V_111 * V_112 ,
const struct V_122 * V_123 )
{
struct V_1 * V_2 = F_39 ( V_112 ) ;
unsigned int V_55 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_56 ; V_55 ++ )
if ( V_2 -> V_124 [ V_55 ] . V_35 == V_123 -> args [ 0 ] )
return V_55 ;
return - V_77 ;
}
static int F_42 ( struct V_125 * V_26 ,
struct V_27 * V_28 ,
struct V_126 * V_127 )
{
const char * V_128 = V_127 -> V_128 ;
T_3 V_17 , V_106 , V_129 [ 2 ] ;
int V_7 ;
V_7 = F_43 ( V_127 , L_5 , & V_17 ) ;
if ( V_7 ) {
F_8 ( V_26 , L_6 , V_128 ) ;
return V_7 ;
}
if ( V_17 > V_130 || V_17 < V_131 ) {
F_8 ( V_26 , L_7 , V_128 , V_17 ) ;
return - V_77 ;
}
V_28 -> V_35 = V_17 ;
V_7 = F_43 ( V_127 , L_8 , & V_106 ) ;
if ( ! V_7 ) {
V_7 = F_32 ( V_106 ) ;
if ( V_7 < 0 ) {
F_8 ( V_26 , L_9 ,
V_17 , V_106 ) ;
return V_7 ;
}
V_28 -> V_29 = V_7 ;
} else {
V_28 -> V_29 = V_132 ;
}
V_7 = F_44 ( V_127 , L_10 , V_129 , 2 ) ;
if ( ! V_7 ) {
V_7 = F_35 ( V_129 [ 0 ] , V_129 [ 1 ] ) ;
if ( V_7 < 0 ) {
F_8 ( V_26 , L_11 ,
V_17 , V_129 [ 0 ] , V_129 [ 1 ] ) ;
return V_7 ;
}
V_28 -> V_95 = V_7 ;
} else {
V_28 -> V_95 = V_133 [ V_28 -> V_35 ] . V_134 ;
}
V_7 = F_43 ( V_127 , L_12 , & V_106 ) ;
if ( ! V_7 ) {
V_7 = F_36 ( V_106 ) ;
if ( V_7 < 0 ) {
F_8 ( V_26 , L_13 ,
V_17 , V_106 ) ;
return V_7 ;
}
V_28 -> V_38 = V_7 ;
} else {
V_28 -> V_38 = V_135 ;
}
V_7 = F_43 ( V_127 , L_14 , & V_106 ) ;
if ( ! V_7 ) {
V_7 = F_37 ( V_106 ) ;
if ( V_7 < 0 ) {
F_8 ( V_26 , L_15 ,
V_17 , V_106 ) ;
return V_7 ;
}
V_28 -> V_40 = V_7 ;
} else {
V_28 -> V_40 = V_136 ;
}
if ( F_45 ( V_127 , L_16 ) )
V_28 -> V_92 = V_68 ;
else
V_28 -> V_92 = V_71 ;
F_15 ( V_26 , L_17 , V_17 , V_128 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
const struct V_137 * V_138 ;
struct V_113 * V_139 ;
struct V_27 V_28 ;
struct V_126 * V_140 ;
unsigned int V_141 = 0 ;
int V_7 ;
V_2 -> V_56 = F_47 ( V_127 ) ;
if ( ! V_2 -> V_56 )
return - V_77 ;
V_2 -> V_124 = F_48 ( V_2 -> V_26 , V_2 -> V_56 ,
sizeof( * V_2 -> V_124 ) , V_142 ) ;
if ( ! V_2 -> V_124 )
return - V_143 ;
V_2 -> V_57 = F_48 ( V_2 -> V_26 , V_2 -> V_56 ,
sizeof( * V_2 -> V_57 ) , V_142 ) ;
if ( ! V_2 -> V_57 )
return - V_143 ;
V_139 = V_2 -> V_124 ;
F_49 (node, child) {
V_7 = F_42 ( V_2 -> V_26 , & V_28 , V_140 ) ;
if ( V_7 ) {
F_50 ( V_140 ) ;
return V_7 ;
}
V_28 . V_119 = V_133 [ V_28 . V_35 ] . V_119 ;
V_2 -> V_57 [ V_141 ] = V_28 ;
V_138 = & V_133 [ V_28 . V_35 ] ;
V_139 -> V_35 = V_28 . V_35 ;
V_139 -> V_144 = V_138 -> V_144 ;
V_139 -> V_145 = V_138 -> V_146 ;
V_139 -> type = V_138 -> type ;
V_139 -> V_147 = 1 ;
V_139 -> V_118 = V_141 ++ ;
V_139 ++ ;
}
if ( ! F_14 ( V_2 , V_73 ) ) {
F_8 ( V_2 -> V_26 , L_18 ) ;
return - V_148 ;
}
if ( ! F_14 ( V_2 , V_76 ) ) {
F_8 ( V_2 -> V_26 , L_19 ) ;
return - V_148 ;
}
if ( ! F_14 ( V_2 , V_80 ) ) {
F_8 ( V_2 -> V_26 , L_20 ) ;
return - V_148 ;
}
if ( ! F_14 ( V_2 , V_81 ) ) {
F_8 ( V_2 -> V_26 , L_21 ) ;
return - V_148 ;
}
return 0 ;
}
static T_7 F_51 ( int V_149 , void * V_150 )
{
struct V_1 * V_2 = V_150 ;
V_62 ( & V_2 -> V_62 ) ;
return V_151 ;
}
static int F_52 ( struct V_1 * V_2 )
{
T_2 V_114 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_152 , & V_114 ) ;
if ( V_7 )
return V_7 ;
if ( V_114 < V_153 ) {
F_8 ( V_2 -> V_26 , L_22 , V_114 ) ;
return - V_148 ;
}
V_7 = F_1 ( V_2 , V_154 , & V_114 ) ;
if ( V_7 )
return V_7 ;
if ( V_114 < V_155 ) {
F_8 ( V_2 -> V_26 , L_23 , V_114 ) ;
return - V_148 ;
}
V_7 = F_1 ( V_2 , V_156 , & V_114 ) ;
if ( V_7 )
return V_7 ;
if ( V_114 < V_157 ) {
F_8 ( V_2 -> V_26 , L_24 , V_114 ) ;
return - V_148 ;
}
return 0 ;
}
static int F_53 ( struct V_158 * V_159 )
{
struct V_126 * V_127 = V_159 -> V_26 . V_160 ;
struct V_125 * V_26 = & V_159 -> V_26 ;
struct V_111 * V_112 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
int V_7 , V_161 ;
T_3 V_162 ;
V_5 = F_54 ( V_26 -> V_163 , NULL ) ;
if ( ! V_5 )
return - V_148 ;
V_7 = F_43 ( V_127 , L_5 , & V_162 ) ;
if ( V_7 < 0 )
return V_7 ;
V_112 = F_55 ( V_26 , sizeof( * V_2 ) ) ;
if ( ! V_112 )
return - V_143 ;
V_2 = F_39 ( V_112 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_6 = V_162 ;
V_2 -> V_164 = false ;
F_56 ( & V_2 -> V_62 ) ;
F_57 ( & V_2 -> V_59 ) ;
V_7 = F_52 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_46 ( V_2 , V_127 ) ;
if ( V_7 )
return V_7 ;
V_161 = F_58 ( V_159 , 0 ) ;
if ( V_161 < 0 ) {
if ( V_161 == - V_165 || V_161 == - V_77 )
return V_161 ;
V_2 -> V_61 = true ;
} else {
V_7 = F_59 ( V_26 , V_161 , F_51 , 0 ,
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
V_112 -> V_26 . V_163 = V_26 ;
V_112 -> V_26 . V_160 = V_127 ;
V_112 -> V_128 = V_159 -> V_128 ;
V_112 -> V_166 = V_167 ;
V_112 -> V_168 = & V_169 ;
V_112 -> V_170 = V_2 -> V_124 ;
V_112 -> V_171 = V_2 -> V_56 ;
return F_60 ( V_26 , V_112 ) ;
}
