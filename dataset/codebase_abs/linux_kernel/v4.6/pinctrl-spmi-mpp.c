static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_5 )
{
unsigned int V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_8 , V_4 -> V_9 + V_5 , & V_6 ) ;
if ( V_7 < 0 )
F_3 ( V_2 -> V_10 , L_1 , V_5 ) ;
else
V_7 = V_6 ;
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_5 ,
unsigned int V_6 )
{
int V_7 ;
V_7 = F_5 ( V_2 -> V_8 , V_4 -> V_9 + V_5 , V_6 ) ;
if ( V_7 < 0 )
F_3 ( V_2 -> V_10 , L_2 , V_5 ) ;
return V_7 ;
}
static int F_6 ( struct V_11 * V_12 )
{
return V_12 -> V_13 -> V_14 ;
}
static const char * F_7 ( struct V_11 * V_12 ,
unsigned V_15 )
{
return V_12 -> V_13 -> V_16 [ V_15 ] . V_17 ;
}
static int F_8 ( struct V_11 * V_12 ,
unsigned V_15 ,
const unsigned * * V_16 , unsigned * V_18 )
{
* V_16 = & V_12 -> V_13 -> V_16 [ V_15 ] . V_19 ;
* V_18 = 1 ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 )
{
return F_10 ( V_20 ) ;
}
static const char * F_11 ( struct V_11 * V_12 ,
unsigned V_21 )
{
return V_20 [ V_21 ] ;
}
static int F_12 ( struct V_11 * V_12 ,
unsigned V_21 ,
const char * const * * V_22 ,
unsigned * const V_23 )
{
* V_22 = V_24 ;
* V_23 = V_12 -> V_13 -> V_14 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_25 ;
unsigned int V_26 ;
unsigned int V_6 ;
unsigned int V_27 ;
switch ( V_4 -> V_21 ) {
case V_28 :
if ( V_4 -> V_29 && V_4 -> V_30 )
V_25 = V_31 ;
else if ( V_4 -> V_29 )
V_25 = V_32 ;
else
V_25 = V_33 ;
break;
case V_34 :
if ( V_4 -> V_29 && V_4 -> V_30 )
V_25 = V_35 ;
else if ( V_4 -> V_29 )
V_25 = V_36 ;
else
V_25 = V_37 ;
break;
case V_38 :
default:
V_25 = V_39 ;
break;
}
if ( V_4 -> V_40 )
V_26 = V_41 + V_4 -> V_40 - 1 ;
else if ( V_4 -> V_42 )
V_26 = V_43 ;
else
V_26 = V_44 ;
V_27 = ! ! V_4 -> V_45 ;
V_6 = V_25 << V_46 |
V_26 << V_47 |
V_27 ;
return F_4 ( V_2 , V_4 , V_48 , V_6 ) ;
}
static int F_14 ( struct V_11 * V_12 , unsigned V_21 ,
unsigned V_15 )
{
struct V_1 * V_2 = F_15 ( V_12 ) ;
struct V_3 * V_4 ;
unsigned int V_6 ;
int V_7 ;
V_4 = V_12 -> V_13 -> V_16 [ V_15 ] . V_49 ;
V_4 -> V_21 = V_21 ;
V_7 = F_13 ( V_2 , V_4 ) ;
V_6 = V_4 -> V_50 << V_51 ;
return F_4 ( V_2 , V_4 , V_52 , V_6 ) ;
}
static int F_16 ( struct V_11 * V_12 ,
unsigned int V_15 , unsigned long * V_53 )
{
unsigned V_54 = F_17 ( * V_53 ) ;
struct V_3 * V_4 ;
unsigned V_55 = 0 ;
V_4 = V_12 -> V_13 -> V_16 [ V_15 ] . V_49 ;
switch ( V_54 ) {
case V_56 :
V_55 = V_4 -> V_57 == V_58 ;
break;
case V_59 :
switch ( V_4 -> V_57 ) {
case V_58 :
V_55 = 0 ;
break;
case V_60 :
V_55 = 600 ;
break;
case V_61 :
V_55 = 10000 ;
break;
case V_62 :
V_55 = 30000 ;
break;
default:
return - V_63 ;
}
break;
case V_64 :
V_55 = ! V_4 -> V_50 ;
break;
case V_65 :
V_55 = V_4 -> V_66 ;
break;
case V_67 :
V_55 = V_4 -> V_29 ;
break;
case V_68 :
V_55 = V_4 -> V_45 ;
break;
case V_69 :
V_55 = V_4 -> V_40 ;
break;
case V_70 :
V_55 = V_4 -> V_71 ;
break;
case V_72 :
V_55 = V_4 -> V_42 ;
break;
case V_73 :
V_55 = V_4 -> V_74 ;
break;
case V_75 :
V_55 = V_4 -> V_76 ;
break;
default:
return - V_63 ;
}
* V_53 = F_18 ( V_54 , V_55 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_12 , unsigned int V_15 ,
unsigned long * V_77 , unsigned V_78 )
{
struct V_1 * V_2 = F_15 ( V_12 ) ;
struct V_3 * V_4 ;
unsigned V_54 , V_55 ;
unsigned int V_6 ;
int V_79 , V_7 ;
V_4 = V_12 -> V_13 -> V_16 [ V_15 ] . V_49 ;
V_4 -> V_50 = true ;
for ( V_79 = 0 ; V_79 < V_78 ; V_79 ++ ) {
V_54 = F_17 ( V_77 [ V_79 ] ) ;
V_55 = F_20 ( V_77 [ V_79 ] ) ;
switch ( V_54 ) {
case V_56 :
V_4 -> V_57 = V_58 ;
break;
case V_59 :
switch ( V_55 ) {
case 600 :
V_4 -> V_57 = V_60 ;
break;
case 10000 :
V_4 -> V_57 = V_61 ;
break;
case 30000 :
V_4 -> V_57 = V_62 ;
break;
default:
return - V_63 ;
}
break;
case V_64 :
V_4 -> V_50 = false ;
break;
case V_65 :
if ( V_55 >= V_4 -> V_80 )
return - V_63 ;
V_4 -> V_66 = V_55 ;
break;
case V_67 :
V_4 -> V_29 = V_55 ? true : false ;
break;
case V_68 :
V_4 -> V_30 = true ;
V_4 -> V_45 = V_55 ;
break;
case V_69 :
V_4 -> V_40 = V_55 ;
break;
case V_73 :
V_55 = V_4 -> V_74 ;
break;
case V_70 :
if ( V_55 >= V_81 )
return - V_63 ;
V_4 -> V_71 = V_55 ;
break;
case V_75 :
V_4 -> V_76 = V_55 ;
break;
case V_72 :
V_4 -> V_42 = ! ! V_55 ;
break;
default:
return - V_63 ;
}
}
V_6 = V_4 -> V_66 << V_82 ;
V_7 = F_4 ( V_2 , V_4 , V_83 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_4 -> V_84 ) {
V_6 = V_4 -> V_57 << V_85 ;
V_7 = F_4 ( V_2 , V_4 , V_86 ,
V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_6 = V_4 -> V_71 & V_87 ;
V_7 = F_4 ( V_2 , V_4 , V_88 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_2 , V_4 , V_89 , V_4 -> V_76 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = V_4 -> V_50 << V_51 ;
return F_4 ( V_2 , V_4 , V_52 , V_6 ) ;
}
static void F_21 ( struct V_11 * V_12 ,
struct V_90 * V_91 , unsigned V_15 )
{
struct V_1 * V_2 = F_15 ( V_12 ) ;
struct V_3 * V_4 ;
int V_7 ;
static const char * const V_92 [] = {
L_3 , L_4 , L_5 , L_6
} ;
V_4 = V_12 -> V_13 -> V_16 [ V_15 ] . V_49 ;
F_22 ( V_91 , L_7 , V_15 + V_93 ) ;
if ( ! V_4 -> V_50 ) {
F_23 ( V_91 , L_8 ) ;
} else {
if ( V_4 -> V_29 ) {
V_7 = F_1 ( V_2 , V_4 , V_94 ) ;
if ( V_7 < 0 )
return;
V_7 &= V_95 ;
V_4 -> V_45 = V_7 ;
}
F_22 ( V_91 , L_9 , V_4 -> V_30 ? L_10 : L_11 ) ;
F_22 ( V_91 , L_12 , V_20 [ V_4 -> V_21 ] ) ;
F_22 ( V_91 , L_13 , V_4 -> V_66 ) ;
F_22 ( V_91 , L_14 , V_4 -> V_76 ) ;
if ( V_4 -> V_84 )
F_22 ( V_91 , L_15 , V_92 [ V_4 -> V_57 ] ) ;
F_22 ( V_91 , L_9 , V_4 -> V_45 ? L_16 : L_17 ) ;
if ( V_4 -> V_40 )
F_22 ( V_91 , L_18 , V_4 -> V_40 ) ;
if ( V_4 -> V_42 )
F_23 ( V_91 , L_19 ) ;
}
}
static int F_24 ( struct V_96 * V_97 , unsigned V_15 )
{
struct V_1 * V_2 = F_25 ( V_97 ) ;
unsigned long V_53 ;
V_53 = F_18 ( V_67 , 1 ) ;
return F_19 ( V_2 -> V_98 , V_15 , & V_53 , 1 ) ;
}
static int F_26 ( struct V_96 * V_97 ,
unsigned V_15 , int V_6 )
{
struct V_1 * V_2 = F_25 ( V_97 ) ;
unsigned long V_53 ;
V_53 = F_18 ( V_68 , V_6 ) ;
return F_19 ( V_2 -> V_98 , V_15 , & V_53 , 1 ) ;
}
static int F_27 ( struct V_96 * V_97 , unsigned V_15 )
{
struct V_1 * V_2 = F_25 ( V_97 ) ;
struct V_3 * V_4 ;
int V_7 ;
V_4 = V_2 -> V_98 -> V_13 -> V_16 [ V_15 ] . V_49 ;
if ( V_4 -> V_29 ) {
V_7 = F_1 ( V_2 , V_4 , V_94 ) ;
if ( V_7 < 0 )
return V_7 ;
V_4 -> V_45 = V_7 & V_95 ;
}
return ! ! V_4 -> V_45 ;
}
static void F_28 ( struct V_96 * V_97 , unsigned V_15 , int V_99 )
{
struct V_1 * V_2 = F_25 ( V_97 ) ;
unsigned long V_53 ;
V_53 = F_18 ( V_68 , V_99 ) ;
F_19 ( V_2 -> V_98 , V_15 , & V_53 , 1 ) ;
}
static int F_29 ( struct V_96 * V_97 ,
const struct V_100 * V_101 ,
T_1 * V_102 )
{
if ( V_97 -> V_103 < 2 )
return - V_63 ;
if ( V_102 )
* V_102 = V_101 -> args [ 1 ] ;
return V_101 -> args [ 0 ] - V_93 ;
}
static int F_30 ( struct V_96 * V_97 , unsigned V_15 )
{
struct V_1 * V_2 = F_25 ( V_97 ) ;
struct V_3 * V_4 ;
V_4 = V_2 -> V_98 -> V_13 -> V_16 [ V_15 ] . V_49 ;
return V_4 -> V_104 ;
}
static void F_31 ( struct V_90 * V_91 , struct V_96 * V_97 )
{
struct V_1 * V_2 = F_25 ( V_97 ) ;
unsigned V_79 ;
for ( V_79 = 0 ; V_79 < V_97 -> V_105 ; V_79 ++ ) {
F_21 ( V_2 -> V_98 , V_91 , V_79 ) ;
F_23 ( V_91 , L_20 ) ;
}
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int type , V_106 , V_6 , V_107 ;
unsigned int V_26 ;
type = F_1 ( V_2 , V_4 , V_108 ) ;
if ( type < 0 )
return type ;
if ( type != V_109 ) {
F_3 ( V_2 -> V_10 , L_21 ,
type , V_4 -> V_9 ) ;
return - V_110 ;
}
V_106 = F_1 ( V_2 , V_4 , V_111 ) ;
if ( V_106 < 0 )
return V_106 ;
switch ( V_106 ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_4 -> V_80 = 4 ;
break;
case V_117 :
V_4 -> V_80 = 8 ;
break;
default:
F_3 ( V_2 -> V_10 , L_22 ,
V_106 , V_4 -> V_9 ) ;
return - V_110 ;
}
V_6 = F_1 ( V_2 , V_4 , V_48 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_45 = V_6 & V_118 ;
V_107 = V_6 >> V_46 ;
V_107 &= V_119 ;
switch ( V_107 ) {
case V_36 :
V_4 -> V_29 = true ;
V_4 -> V_30 = false ;
V_4 -> V_21 = V_34 ;
break;
case V_37 :
V_4 -> V_29 = false ;
V_4 -> V_30 = true ;
V_4 -> V_21 = V_34 ;
break;
case V_35 :
V_4 -> V_29 = true ;
V_4 -> V_30 = true ;
V_4 -> V_21 = V_34 ;
break;
case V_31 :
V_4 -> V_29 = true ;
V_4 -> V_30 = true ;
V_4 -> V_21 = V_28 ;
break;
case V_32 :
V_4 -> V_29 = true ;
V_4 -> V_30 = false ;
V_4 -> V_21 = V_28 ;
break;
case V_33 :
V_4 -> V_29 = false ;
V_4 -> V_30 = true ;
V_4 -> V_21 = V_28 ;
break;
case V_39 :
V_4 -> V_29 = false ;
V_4 -> V_30 = true ;
V_4 -> V_21 = V_38 ;
break;
default:
F_3 ( V_2 -> V_10 , L_23 ) ;
return - V_110 ;
}
V_26 = V_6 >> V_47 ;
V_26 &= V_120 ;
if ( V_26 >= V_41 )
V_4 -> V_40 = V_26 + 1 ;
else if ( V_26 == V_43 )
V_4 -> V_42 = true ;
V_6 = F_1 ( V_2 , V_4 , V_83 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_66 = V_6 >> V_82 ;
V_4 -> V_66 &= V_121 ;
if ( V_106 != V_113 &&
V_106 != V_115 ) {
V_6 = F_1 ( V_2 , V_4 , V_86 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_57 = V_6 >> V_85 ;
V_4 -> V_57 &= V_122 ;
V_4 -> V_84 = true ;
}
V_6 = F_1 ( V_2 , V_4 , V_88 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_71 = V_6 >> V_123 ;
V_4 -> V_71 &= V_87 ;
V_6 = F_1 ( V_2 , V_4 , V_124 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_74 = V_6 ;
V_6 = F_1 ( V_2 , V_4 , V_89 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_76 = V_6 ;
V_6 = F_1 ( V_2 , V_4 , V_52 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_50 = ! ! V_6 ;
return 0 ;
}
static int F_33 ( struct V_125 * V_126 )
{
struct V_127 * V_10 = & V_126 -> V_10 ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
struct V_3 * V_4 , * V_132 ;
struct V_1 * V_2 ;
int V_7 , V_14 , V_79 ;
T_1 V_133 ;
V_7 = F_34 ( V_10 -> V_134 , L_24 , & V_133 ) ;
if ( V_7 < 0 ) {
F_3 ( V_10 , L_25 ) ;
return V_7 ;
}
V_14 = F_35 ( V_126 ) ;
if ( ! V_14 )
return - V_63 ;
if ( V_14 < 0 )
return V_14 ;
F_36 ( V_14 > F_10 ( V_24 ) ) ;
V_2 = F_37 ( V_10 , sizeof( * V_2 ) , V_135 ) ;
if ( ! V_2 )
return - V_136 ;
F_38 ( V_126 , V_2 ) ;
V_2 -> V_10 = & V_126 -> V_10 ;
V_2 -> V_8 = F_39 ( V_10 -> V_137 , NULL ) ;
V_129 = F_40 ( V_10 , V_14 , sizeof( * V_129 ) , V_135 ) ;
if ( ! V_129 )
return - V_136 ;
V_132 = F_40 ( V_10 , V_14 , sizeof( * V_132 ) , V_135 ) ;
if ( ! V_132 )
return - V_136 ;
V_131 = F_37 ( V_10 , sizeof( * V_131 ) , V_135 ) ;
if ( ! V_131 )
return - V_136 ;
V_131 -> V_138 = & V_139 ;
V_131 -> V_140 = & V_141 ;
V_131 -> V_142 = & V_143 ;
V_131 -> V_144 = V_145 ;
V_131 -> V_17 = F_41 ( V_10 ) ;
V_131 -> V_16 = V_129 ;
V_131 -> V_14 = V_14 ;
V_131 -> V_146 = F_10 ( V_147 ) ;
V_131 -> V_148 = V_147 ;
#ifdef F_42
V_131 -> V_149 = V_150 ;
#endif
for ( V_79 = 0 ; V_79 < V_14 ; V_79 ++ , V_129 ++ ) {
V_4 = & V_132 [ V_79 ] ;
V_129 -> V_49 = V_4 ;
V_129 -> V_19 = V_79 ;
V_129 -> V_17 = V_24 [ V_79 ] ;
V_4 -> V_104 = F_43 ( V_126 , V_79 ) ;
if ( V_4 -> V_104 < 0 )
return V_4 -> V_104 ;
V_4 -> V_9 = V_133 + V_79 * V_151 ;
V_7 = F_32 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_2 -> V_97 = V_152 ;
V_2 -> V_97 . V_137 = V_10 ;
V_2 -> V_97 . V_9 = - 1 ;
V_2 -> V_97 . V_105 = V_14 ;
V_2 -> V_97 . V_153 = F_41 ( V_10 ) ;
V_2 -> V_97 . V_103 = 2 ;
V_2 -> V_97 . V_154 = false ;
V_2 -> V_98 = F_44 ( V_131 , V_10 , V_2 ) ;
if ( F_45 ( V_2 -> V_98 ) )
return F_46 ( V_2 -> V_98 ) ;
V_7 = F_47 ( & V_2 -> V_97 , V_2 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_10 , L_26 ) ;
goto V_155;
}
V_7 = F_48 ( & V_2 -> V_97 , F_41 ( V_10 ) , 0 , 0 , V_14 ) ;
if ( V_7 ) {
F_3 ( V_10 , L_27 ) ;
goto V_156;
}
return 0 ;
V_156:
F_49 ( & V_2 -> V_97 ) ;
V_155:
F_50 ( V_2 -> V_98 ) ;
return V_7 ;
}
static int F_51 ( struct V_125 * V_126 )
{
struct V_1 * V_2 = F_52 ( V_126 ) ;
F_49 ( & V_2 -> V_97 ) ;
F_50 ( V_2 -> V_98 ) ;
return 0 ;
}
