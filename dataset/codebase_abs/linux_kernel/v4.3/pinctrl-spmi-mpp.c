static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 ,
struct V_5 * V_6 , unsigned int V_7 )
{
unsigned int V_8 ;
int V_9 ;
V_9 = F_4 ( V_4 -> V_10 , V_6 -> V_11 + V_7 , & V_8 ) ;
if ( V_9 < 0 )
F_5 ( V_4 -> V_12 , L_1 , V_7 ) ;
else
V_9 = V_8 ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_4 ,
struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_8 )
{
int V_9 ;
V_9 = F_7 ( V_4 -> V_10 , V_6 -> V_11 + V_7 , V_8 ) ;
if ( V_9 < 0 )
F_5 ( V_4 -> V_12 , L_2 , V_7 ) ;
return V_9 ;
}
static int F_8 ( struct V_13 * V_14 )
{
return V_14 -> V_15 -> V_16 ;
}
static const char * F_9 ( struct V_13 * V_14 ,
unsigned V_17 )
{
return V_14 -> V_15 -> V_18 [ V_17 ] . V_19 ;
}
static int F_10 ( struct V_13 * V_14 ,
unsigned V_17 ,
const unsigned * * V_18 , unsigned * V_20 )
{
* V_18 = & V_14 -> V_15 -> V_18 [ V_17 ] . V_21 ;
* V_20 = 1 ;
return 0 ;
}
static int F_11 ( struct V_13 * V_14 )
{
return F_12 ( V_22 ) ;
}
static const char * F_13 ( struct V_13 * V_14 ,
unsigned V_23 )
{
return V_22 [ V_23 ] ;
}
static int F_14 ( struct V_13 * V_14 ,
unsigned V_23 ,
const char * const * * V_24 ,
unsigned * const V_25 )
{
* V_24 = V_26 ;
* V_25 = V_14 -> V_15 -> V_16 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_4 ,
struct V_5 * V_6 )
{
unsigned int V_27 ;
unsigned int V_28 ;
unsigned int V_8 ;
unsigned int V_29 ;
switch ( V_6 -> V_23 ) {
case V_30 :
if ( V_6 -> V_31 && V_6 -> V_32 )
V_27 = V_33 ;
else if ( V_6 -> V_31 )
V_27 = V_34 ;
else
V_27 = V_35 ;
break;
case V_36 :
if ( V_6 -> V_31 && V_6 -> V_32 )
V_27 = V_37 ;
else if ( V_6 -> V_31 )
V_27 = V_38 ;
else
V_27 = V_39 ;
break;
case V_40 :
default:
V_27 = V_41 ;
break;
}
if ( V_6 -> V_42 )
V_28 = V_43 + V_6 -> V_42 - 1 ;
else if ( V_6 -> V_44 )
V_28 = V_45 ;
else
V_28 = V_46 ;
V_29 = ! ! V_6 -> V_47 ;
V_8 = V_27 << V_48 |
V_28 << V_49 |
V_29 ;
return F_6 ( V_4 , V_6 , V_50 , V_8 ) ;
}
static int F_16 ( struct V_13 * V_14 , unsigned V_23 ,
unsigned V_17 )
{
struct V_1 * V_4 = F_17 ( V_14 ) ;
struct V_5 * V_6 ;
unsigned int V_8 ;
int V_9 ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_51 ;
V_6 -> V_23 = V_23 ;
V_9 = F_15 ( V_4 , V_6 ) ;
V_8 = V_6 -> V_52 << V_53 ;
return F_6 ( V_4 , V_6 , V_54 , V_8 ) ;
}
static int F_18 ( struct V_13 * V_14 ,
unsigned int V_17 , unsigned long * V_55 )
{
unsigned V_56 = F_19 ( * V_55 ) ;
struct V_5 * V_6 ;
unsigned V_57 = 0 ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_51 ;
switch ( V_56 ) {
case V_58 :
V_57 = V_6 -> V_59 == V_60 ;
break;
case V_61 :
switch ( V_6 -> V_59 ) {
case V_60 :
V_57 = 0 ;
break;
case V_62 :
V_57 = 600 ;
break;
case V_63 :
V_57 = 10000 ;
break;
case V_64 :
V_57 = 30000 ;
break;
default:
return - V_65 ;
}
break;
case V_66 :
V_57 = ! V_6 -> V_52 ;
break;
case V_67 :
V_57 = V_6 -> V_68 ;
break;
case V_69 :
V_57 = V_6 -> V_31 ;
break;
case V_70 :
V_57 = V_6 -> V_47 ;
break;
case V_71 :
V_57 = V_6 -> V_42 ;
break;
case V_72 :
V_57 = V_6 -> V_73 ;
break;
case V_74 :
V_57 = V_6 -> V_44 ;
break;
case V_75 :
V_57 = V_6 -> V_76 ;
break;
case V_77 :
V_57 = V_6 -> V_78 ;
break;
default:
return - V_65 ;
}
* V_55 = F_20 ( V_56 , V_57 ) ;
return 0 ;
}
static int F_21 ( struct V_13 * V_14 , unsigned int V_17 ,
unsigned long * V_79 , unsigned V_80 )
{
struct V_1 * V_4 = F_17 ( V_14 ) ;
struct V_5 * V_6 ;
unsigned V_56 , V_57 ;
unsigned int V_8 ;
int V_81 , V_9 ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_51 ;
V_6 -> V_52 = true ;
for ( V_81 = 0 ; V_81 < V_80 ; V_81 ++ ) {
V_56 = F_19 ( V_79 [ V_81 ] ) ;
V_57 = F_22 ( V_79 [ V_81 ] ) ;
switch ( V_56 ) {
case V_58 :
V_6 -> V_59 = V_60 ;
break;
case V_61 :
switch ( V_57 ) {
case 600 :
V_6 -> V_59 = V_62 ;
break;
case 10000 :
V_6 -> V_59 = V_63 ;
break;
case 30000 :
V_6 -> V_59 = V_64 ;
break;
default:
return - V_65 ;
}
break;
case V_66 :
V_6 -> V_52 = false ;
break;
case V_67 :
if ( V_57 >= V_6 -> V_82 )
return - V_65 ;
V_6 -> V_68 = V_57 ;
break;
case V_69 :
V_6 -> V_31 = V_57 ? true : false ;
break;
case V_70 :
V_6 -> V_32 = true ;
V_6 -> V_47 = V_57 ;
break;
case V_71 :
V_6 -> V_42 = V_57 ;
break;
case V_75 :
V_57 = V_6 -> V_76 ;
break;
case V_72 :
if ( V_57 >= V_83 )
return - V_65 ;
V_6 -> V_73 = V_57 ;
break;
case V_77 :
V_6 -> V_78 = V_57 ;
break;
case V_74 :
V_6 -> V_44 = ! ! V_57 ;
break;
default:
return - V_65 ;
}
}
V_8 = V_6 -> V_68 << V_84 ;
V_9 = F_6 ( V_4 , V_6 , V_85 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_6 -> V_59 << V_86 ;
V_9 = F_6 ( V_4 , V_6 , V_87 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_6 -> V_73 & V_88 ;
V_9 = F_6 ( V_4 , V_6 , V_89 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_6 ( V_4 , V_6 , V_90 , V_6 -> V_78 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_15 ( V_4 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_6 -> V_52 << V_53 ;
return F_6 ( V_4 , V_6 , V_54 , V_8 ) ;
}
static void F_23 ( struct V_13 * V_14 ,
struct V_91 * V_92 , unsigned V_17 )
{
struct V_1 * V_4 = F_17 ( V_14 ) ;
struct V_5 * V_6 ;
int V_9 ;
static const char * const V_93 [] = {
L_3 , L_4 , L_5 , L_6
} ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_51 ;
F_24 ( V_92 , L_7 , V_17 + V_94 ) ;
if ( ! V_6 -> V_52 ) {
F_25 ( V_92 , L_8 ) ;
} else {
if ( V_6 -> V_31 ) {
V_9 = F_3 ( V_4 , V_6 , V_95 ) ;
if ( V_9 < 0 )
return;
V_9 &= V_96 ;
V_6 -> V_47 = V_9 ;
}
F_24 ( V_92 , L_9 , V_6 -> V_32 ? L_10 : L_11 ) ;
F_24 ( V_92 , L_12 , V_22 [ V_6 -> V_23 ] ) ;
F_24 ( V_92 , L_13 , V_6 -> V_68 ) ;
F_24 ( V_92 , L_14 , V_6 -> V_78 ) ;
F_24 ( V_92 , L_15 , V_93 [ V_6 -> V_59 ] ) ;
F_24 ( V_92 , L_9 , V_6 -> V_47 ? L_16 : L_17 ) ;
if ( V_6 -> V_42 )
F_24 ( V_92 , L_18 , V_6 -> V_42 ) ;
if ( V_6 -> V_44 )
F_25 ( V_92 , L_19 ) ;
}
}
static int F_26 ( struct V_2 * V_3 , unsigned V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_55 ;
V_55 = F_20 ( V_69 , 1 ) ;
return F_21 ( V_4 -> V_97 , V_17 , & V_55 , 1 ) ;
}
static int F_27 ( struct V_2 * V_3 ,
unsigned V_17 , int V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_55 ;
V_55 = F_20 ( V_70 , V_8 ) ;
return F_21 ( V_4 -> V_97 , V_17 , & V_55 , 1 ) ;
}
static int F_28 ( struct V_2 * V_3 , unsigned V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 ;
int V_9 ;
V_6 = V_4 -> V_97 -> V_15 -> V_18 [ V_17 ] . V_51 ;
if ( V_6 -> V_31 ) {
V_9 = F_3 ( V_4 , V_6 , V_95 ) ;
if ( V_9 < 0 )
return V_9 ;
V_6 -> V_47 = V_9 & V_96 ;
}
return V_6 -> V_47 ;
}
static void F_29 ( struct V_2 * V_3 , unsigned V_17 , int V_98 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_55 ;
V_55 = F_20 ( V_70 , V_98 ) ;
F_21 ( V_4 -> V_97 , V_17 , & V_55 , 1 ) ;
}
static int F_30 ( struct V_2 * V_3 , unsigned V_11 )
{
return F_31 ( V_3 -> V_11 + V_11 ) ;
}
static void F_32 ( struct V_2 * V_3 , unsigned V_11 )
{
F_33 ( V_3 -> V_11 + V_11 ) ;
}
static int F_34 ( struct V_2 * V_3 ,
const struct V_99 * V_100 ,
T_1 * V_101 )
{
if ( V_3 -> V_102 < 2 )
return - V_65 ;
if ( V_101 )
* V_101 = V_100 -> args [ 1 ] ;
return V_100 -> args [ 0 ] - V_94 ;
}
static int F_35 ( struct V_2 * V_3 , unsigned V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 ;
V_6 = V_4 -> V_97 -> V_15 -> V_18 [ V_17 ] . V_51 ;
return V_6 -> V_103 ;
}
static void F_36 ( struct V_91 * V_92 , struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned V_81 ;
for ( V_81 = 0 ; V_81 < V_3 -> V_104 ; V_81 ++ ) {
F_23 ( V_4 -> V_97 , V_92 , V_81 ) ;
F_25 ( V_92 , L_20 ) ;
}
}
static int F_37 ( struct V_1 * V_4 ,
struct V_5 * V_6 )
{
int type , V_105 , V_8 , V_106 ;
unsigned int V_28 ;
type = F_3 ( V_4 , V_6 , V_107 ) ;
if ( type < 0 )
return type ;
if ( type != V_108 ) {
F_5 ( V_4 -> V_12 , L_21 ,
type , V_6 -> V_11 ) ;
return - V_109 ;
}
V_105 = F_3 ( V_4 , V_6 , V_110 ) ;
if ( V_105 < 0 )
return V_105 ;
switch ( V_105 ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_6 -> V_82 = 4 ;
break;
case V_116 :
V_6 -> V_82 = 8 ;
break;
default:
F_5 ( V_4 -> V_12 , L_22 ,
V_105 , V_6 -> V_11 ) ;
return - V_109 ;
}
V_8 = F_3 ( V_4 , V_6 , V_50 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_47 = V_8 & V_117 ;
V_106 = V_8 >> V_48 ;
V_106 &= V_118 ;
switch ( V_106 ) {
case V_38 :
V_6 -> V_31 = true ;
V_6 -> V_32 = false ;
V_6 -> V_23 = V_36 ;
break;
case V_39 :
V_6 -> V_31 = false ;
V_6 -> V_32 = true ;
V_6 -> V_23 = V_36 ;
break;
case V_37 :
V_6 -> V_31 = true ;
V_6 -> V_32 = true ;
V_6 -> V_23 = V_36 ;
break;
case V_33 :
V_6 -> V_31 = true ;
V_6 -> V_32 = true ;
V_6 -> V_23 = V_30 ;
break;
case V_34 :
V_6 -> V_31 = true ;
V_6 -> V_32 = false ;
V_6 -> V_23 = V_30 ;
break;
case V_35 :
V_6 -> V_31 = false ;
V_6 -> V_32 = true ;
V_6 -> V_23 = V_30 ;
break;
case V_41 :
V_6 -> V_31 = false ;
V_6 -> V_32 = true ;
V_6 -> V_23 = V_40 ;
break;
default:
F_5 ( V_4 -> V_12 , L_23 ) ;
return - V_109 ;
}
V_28 = V_8 >> V_49 ;
V_28 &= V_119 ;
if ( V_28 >= V_43 )
V_6 -> V_42 = V_28 + 1 ;
else if ( V_28 == V_45 )
V_6 -> V_44 = true ;
V_8 = F_3 ( V_4 , V_6 , V_85 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_68 = V_8 >> V_84 ;
V_6 -> V_68 &= V_120 ;
V_8 = F_3 ( V_4 , V_6 , V_87 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_59 = V_8 >> V_86 ;
V_6 -> V_59 &= V_121 ;
V_8 = F_3 ( V_4 , V_6 , V_89 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_73 = V_8 >> V_122 ;
V_6 -> V_73 &= V_88 ;
V_8 = F_3 ( V_4 , V_6 , V_123 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_76 = V_8 ;
V_8 = F_3 ( V_4 , V_6 , V_90 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_78 = V_8 ;
V_8 = F_3 ( V_4 , V_6 , V_54 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_52 = ! ! V_8 ;
return 0 ;
}
static int F_38 ( struct V_124 * V_125 )
{
struct V_126 * V_12 = & V_125 -> V_12 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_5 * V_6 , * V_131 ;
struct V_1 * V_4 ;
int V_9 , V_16 , V_81 ;
T_1 V_132 [ 2 ] ;
V_9 = F_39 ( V_12 -> V_133 , L_24 , V_132 , 2 ) ;
if ( V_9 < 0 ) {
F_5 ( V_12 , L_25 ) ;
return V_9 ;
}
V_16 = V_132 [ 1 ] / V_134 ;
if ( ! V_16 )
return - V_65 ;
F_40 ( V_16 > F_12 ( V_26 ) ) ;
V_4 = F_41 ( V_12 , sizeof( * V_4 ) , V_135 ) ;
if ( ! V_4 )
return - V_136 ;
F_42 ( V_125 , V_4 ) ;
V_4 -> V_12 = & V_125 -> V_12 ;
V_4 -> V_10 = F_43 ( V_12 -> V_137 , NULL ) ;
V_128 = F_44 ( V_12 , V_16 , sizeof( * V_128 ) , V_135 ) ;
if ( ! V_128 )
return - V_136 ;
V_131 = F_44 ( V_12 , V_16 , sizeof( * V_131 ) , V_135 ) ;
if ( ! V_131 )
return - V_136 ;
V_130 = F_41 ( V_12 , sizeof( * V_130 ) , V_135 ) ;
if ( ! V_130 )
return - V_136 ;
V_130 -> V_138 = & V_139 ;
V_130 -> V_140 = & V_141 ;
V_130 -> V_142 = & V_143 ;
V_130 -> V_144 = V_145 ;
V_130 -> V_19 = F_45 ( V_12 ) ;
V_130 -> V_18 = V_128 ;
V_130 -> V_16 = V_16 ;
V_130 -> V_146 = F_12 ( V_147 ) ;
V_130 -> V_148 = V_147 ;
#ifdef F_46
V_130 -> V_149 = V_150 ;
#endif
for ( V_81 = 0 ; V_81 < V_16 ; V_81 ++ , V_128 ++ ) {
V_6 = & V_131 [ V_81 ] ;
V_128 -> V_51 = V_6 ;
V_128 -> V_21 = V_81 ;
V_128 -> V_19 = V_26 [ V_81 ] ;
V_6 -> V_103 = F_47 ( V_125 , V_81 ) ;
if ( V_6 -> V_103 < 0 )
return V_6 -> V_103 ;
V_6 -> V_11 = V_132 [ 0 ] + V_81 * V_134 ;
V_9 = F_37 ( V_4 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
}
V_4 -> V_3 = V_151 ;
V_4 -> V_3 . V_12 = V_12 ;
V_4 -> V_3 . V_11 = - 1 ;
V_4 -> V_3 . V_104 = V_16 ;
V_4 -> V_3 . V_152 = F_45 ( V_12 ) ;
V_4 -> V_3 . V_102 = 2 ;
V_4 -> V_3 . V_153 = false ;
V_4 -> V_97 = F_48 ( V_130 , V_12 , V_4 ) ;
if ( F_49 ( V_4 -> V_97 ) )
return F_50 ( V_4 -> V_97 ) ;
V_9 = F_51 ( & V_4 -> V_3 ) ;
if ( V_9 ) {
F_5 ( V_4 -> V_12 , L_26 ) ;
goto V_154;
}
V_9 = F_52 ( & V_4 -> V_3 , F_45 ( V_12 ) , 0 , 0 , V_16 ) ;
if ( V_9 ) {
F_5 ( V_12 , L_27 ) ;
goto V_155;
}
return 0 ;
V_155:
F_53 ( & V_4 -> V_3 ) ;
V_154:
F_54 ( V_4 -> V_97 ) ;
return V_9 ;
}
static int F_55 ( struct V_124 * V_125 )
{
struct V_1 * V_4 = F_56 ( V_125 ) ;
F_53 ( & V_4 -> V_3 ) ;
F_54 ( V_4 -> V_97 ) ;
return 0 ;
}
