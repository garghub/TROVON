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
static int F_8 ( struct V_11 * V_12 , unsigned V_15 ,
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
static int F_13 ( struct V_11 * V_12 , unsigned V_21 ,
unsigned V_15 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
struct V_3 * V_4 ;
unsigned int V_6 ;
int V_7 ;
if ( V_21 > V_25 ) {
F_15 ( L_3 , V_21 ) ;
return - V_26 ;
}
V_4 = V_12 -> V_13 -> V_16 [ V_15 ] . V_27 ;
if ( ! V_4 -> V_28 ) {
if ( V_21 == V_29 ||
V_21 == V_30 ) {
F_15 ( L_4 ) ;
return - V_26 ;
}
if ( V_21 >= V_31 )
V_21 -= ( V_31 -
V_29 ) ;
}
V_4 -> V_21 = V_21 ;
if ( V_4 -> V_32 )
V_6 = V_33 ;
else if ( V_4 -> V_34 && V_4 -> V_35 )
V_6 = V_36 ;
else if ( V_4 -> V_34 )
V_6 = V_37 ;
else
V_6 = V_38 ;
if ( V_4 -> V_28 ) {
V_7 = F_4 ( V_2 , V_4 ,
V_39 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = V_4 -> V_40 - 1 ;
V_7 = F_4 ( V_2 , V_4 ,
V_41 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = V_4 -> V_42
<< V_43 ;
V_6 |= V_4 -> V_21
& V_44 ;
V_7 = F_4 ( V_2 , V_4 ,
V_45 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
} else {
V_6 = V_6 << V_46 ;
V_6 |= V_4 -> V_21 << V_47 ;
V_6 |= V_4 -> V_42 & V_48 ;
V_7 = F_4 ( V_2 , V_4 , V_39 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_6 = V_4 -> V_49 << V_50 ;
return F_4 ( V_2 , V_4 , V_51 , V_6 ) ;
}
static int F_16 ( struct V_11 * V_12 ,
unsigned int V_15 , unsigned long * V_52 )
{
unsigned V_53 = F_17 ( * V_52 ) ;
struct V_3 * V_4 ;
unsigned V_54 ;
V_4 = V_12 -> V_13 -> V_16 [ V_15 ] . V_27 ;
switch ( V_53 ) {
case V_55 :
V_54 = V_4 -> V_56 == V_57 ;
break;
case V_58 :
V_54 = V_4 -> V_56 == V_59 ;
break;
case V_60 :
V_54 = V_4 -> V_56 == V_61 ;
break;
case V_62 :
V_54 = V_4 -> V_63 == V_64 ;
break;
case V_65 :
V_54 = V_4 -> V_63 = V_66 ;
break;
case V_67 :
V_54 = V_4 -> V_63 == V_68 ;
break;
case V_69 :
V_54 = ! V_4 -> V_49 ;
break;
case V_70 :
V_54 = V_4 -> V_71 ;
break;
case V_72 :
V_54 = V_4 -> V_35 ;
break;
case V_73 :
V_54 = V_4 -> V_42 ;
break;
case V_74 :
V_54 = V_4 -> V_63 ;
break;
case V_75 :
V_54 = V_4 -> V_76 ;
break;
case V_77 :
V_54 = V_4 -> V_40 ;
break;
case V_78 :
V_54 = V_4 -> V_32 ;
break;
case V_79 :
V_54 = V_4 -> V_80 ;
break;
default:
return - V_26 ;
}
* V_52 = F_18 ( V_53 , V_54 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_12 , unsigned int V_15 ,
unsigned long * V_81 , unsigned V_82 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
struct V_3 * V_4 ;
unsigned V_53 , V_54 ;
unsigned int V_6 ;
int V_83 , V_7 ;
V_4 = V_12 -> V_13 -> V_16 [ V_15 ] . V_27 ;
for ( V_83 = 0 ; V_83 < V_82 ; V_83 ++ ) {
V_53 = F_17 ( V_81 [ V_83 ] ) ;
V_54 = F_20 ( V_81 [ V_83 ] ) ;
switch ( V_53 ) {
case V_55 :
V_4 -> V_56 = V_57 ;
break;
case V_58 :
if ( ! V_4 -> V_84 )
return - V_26 ;
V_4 -> V_56 = V_59 ;
break;
case V_60 :
if ( ! V_4 -> V_84 )
return - V_26 ;
V_4 -> V_56 = V_61 ;
break;
case V_65 :
V_4 -> V_63 = V_66 ;
break;
case V_67 :
V_4 -> V_63 = V_68 ;
break;
case V_62 :
if ( V_54 )
V_4 -> V_63 = V_64 ;
else
V_4 -> V_63 = V_66 ;
break;
case V_69 :
V_4 -> V_49 = false ;
break;
case V_70 :
if ( V_54 >= V_4 -> V_85 )
return - V_26 ;
V_4 -> V_71 = V_54 ;
break;
case V_72 :
V_4 -> V_35 = V_54 ? true : false ;
break;
case V_73 :
V_4 -> V_34 = true ;
V_4 -> V_42 = V_54 ;
break;
case V_74 :
if ( V_54 > V_86 )
return - V_26 ;
V_4 -> V_63 = V_54 ;
break;
case V_75 :
if ( V_54 > V_87 )
return - V_26 ;
V_4 -> V_76 = V_54 ;
break;
case V_77 :
if ( ! V_4 -> V_28 || V_54 > 4 )
return - V_26 ;
V_4 -> V_40 = V_54 ;
break;
case V_78 :
if ( ! V_4 -> V_28 )
return - V_26 ;
V_4 -> V_32 = true ;
break;
case V_79 :
if ( V_54 > 4 )
return - V_26 ;
V_4 -> V_80 = V_54 ;
break;
default:
return - V_26 ;
}
}
V_6 = V_4 -> V_71 << V_88 ;
V_7 = F_4 ( V_2 , V_4 , V_89 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = V_4 -> V_63 << V_90 ;
V_7 = F_4 ( V_2 , V_4 , V_91 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = V_4 -> V_56 << V_92 ;
V_6 |= V_4 -> V_76 << V_93 ;
V_7 = F_4 ( V_2 , V_4 , V_94 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_4 -> V_80 == 0 ) {
V_6 = 0 ;
} else {
if ( V_4 -> V_28 ) {
V_6 = V_4 -> V_80 - 1 ;
V_6 |= V_95 ;
} else {
V_6 = F_21 ( V_4 -> V_80 - 1 ) ;
}
}
V_7 = F_4 ( V_2 , V_4 , V_96 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_4 -> V_32 )
V_6 = V_33 ;
else if ( V_4 -> V_34 && V_4 -> V_35 )
V_6 = V_36 ;
else if ( V_4 -> V_34 )
V_6 = V_37 ;
else
V_6 = V_38 ;
if ( V_4 -> V_28 ) {
V_7 = F_4 ( V_2 , V_4 ,
V_39 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = V_4 -> V_40 - 1 ;
V_7 = F_4 ( V_2 , V_4 ,
V_41 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = V_4 -> V_42
<< V_43 ;
V_6 |= V_4 -> V_21
& V_44 ;
V_7 = F_4 ( V_2 , V_4 ,
V_45 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
} else {
V_6 = V_6 << V_46 ;
V_6 |= V_4 -> V_21 << V_47 ;
V_6 |= V_4 -> V_42 & V_48 ;
V_7 = F_4 ( V_2 , V_4 , V_39 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return V_7 ;
}
static void F_22 ( struct V_11 * V_12 ,
struct V_97 * V_98 , unsigned V_15 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
struct V_3 * V_4 ;
int V_7 , V_6 , V_21 ;
static const char * const V_99 [] = {
L_5 , L_6 , L_7 ,
L_8 , L_9 , L_10
} ;
static const char * const V_100 [] = {
L_11 , L_12 , L_13
} ;
static const char * const V_101 [] = {
L_14 , L_15 , L_16 , L_17
} ;
V_4 = V_12 -> V_13 -> V_16 [ V_15 ] . V_27 ;
F_23 ( V_98 , L_18 , V_15 + V_102 ) ;
V_6 = F_1 ( V_2 , V_4 , V_51 ) ;
if ( V_6 < 0 || ! ( V_6 >> V_50 ) ) {
F_24 ( V_98 , L_19 ) ;
} else {
if ( V_4 -> V_35 ) {
V_7 = F_1 ( V_2 , V_4 , V_103 ) ;
if ( V_7 < 0 )
return;
V_7 &= V_104 ;
V_4 -> V_42 = V_7 ;
}
V_21 = V_4 -> V_21 ;
if ( ! V_4 -> V_28 &&
V_4 -> V_21 >= V_29 )
V_21 += V_31 -
V_29 ;
if ( V_4 -> V_32 )
F_24 ( V_98 , L_20 ) ;
else
F_23 ( V_98 , L_21 ,
V_4 -> V_34 ? L_22 : L_23 ) ;
F_23 ( V_98 , L_24 , V_20 [ V_21 ] ) ;
F_23 ( V_98 , L_25 , V_4 -> V_71 ) ;
F_23 ( V_98 , L_26 , V_99 [ V_4 -> V_63 ] ) ;
F_23 ( V_98 , L_27 , V_100 [ V_4 -> V_56 ] ) ;
F_23 ( V_98 , L_21 , V_4 -> V_42 ? L_15 : L_17 ) ;
F_23 ( V_98 , L_24 , V_101 [ V_4 -> V_76 ] ) ;
F_23 ( V_98 , L_28 , V_4 -> V_40 ) ;
F_23 ( V_98 , L_29 , V_4 -> V_80 ) ;
}
}
static int F_25 ( struct V_105 * V_106 , unsigned V_15 )
{
struct V_1 * V_2 = F_26 ( V_106 ) ;
unsigned long V_52 ;
V_52 = F_18 ( V_72 , 1 ) ;
return F_19 ( V_2 -> V_107 , V_15 , & V_52 , 1 ) ;
}
static int F_27 ( struct V_105 * V_106 ,
unsigned V_15 , int V_6 )
{
struct V_1 * V_2 = F_26 ( V_106 ) ;
unsigned long V_52 ;
V_52 = F_18 ( V_73 , V_6 ) ;
return F_19 ( V_2 -> V_107 , V_15 , & V_52 , 1 ) ;
}
static int F_28 ( struct V_105 * V_106 , unsigned V_15 )
{
struct V_1 * V_2 = F_26 ( V_106 ) ;
struct V_3 * V_4 ;
int V_7 ;
V_4 = V_2 -> V_107 -> V_13 -> V_16 [ V_15 ] . V_27 ;
if ( ! V_4 -> V_49 )
return - V_26 ;
if ( V_4 -> V_35 ) {
V_7 = F_1 ( V_2 , V_4 , V_103 ) ;
if ( V_7 < 0 )
return V_7 ;
V_4 -> V_42 = V_7 & V_104 ;
}
return ! ! V_4 -> V_42 ;
}
static void F_29 ( struct V_105 * V_106 , unsigned V_15 , int V_108 )
{
struct V_1 * V_2 = F_26 ( V_106 ) ;
unsigned long V_52 ;
V_52 = F_18 ( V_73 , V_108 ) ;
F_19 ( V_2 -> V_107 , V_15 , & V_52 , 1 ) ;
}
static int F_30 ( struct V_105 * V_106 ,
const struct V_109 * V_110 ,
T_1 * V_111 )
{
if ( V_106 -> V_112 < 2 )
return - V_26 ;
if ( V_111 )
* V_111 = V_110 -> args [ 1 ] ;
return V_110 -> args [ 0 ] - V_102 ;
}
static int F_31 ( struct V_105 * V_106 , unsigned V_15 )
{
struct V_1 * V_2 = F_26 ( V_106 ) ;
struct V_3 * V_4 ;
V_4 = V_2 -> V_107 -> V_13 -> V_16 [ V_15 ] . V_27 ;
return V_4 -> V_113 ;
}
static void F_32 ( struct V_97 * V_98 , struct V_105 * V_106 )
{
struct V_1 * V_2 = F_26 ( V_106 ) ;
unsigned V_83 ;
for ( V_83 = 0 ; V_83 < V_106 -> V_114 ; V_83 ++ ) {
F_22 ( V_2 -> V_107 , V_98 , V_83 ) ;
F_24 ( V_98 , L_30 ) ;
}
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int type , V_115 , V_6 , V_116 ;
type = F_1 ( V_2 , V_4 , V_117 ) ;
if ( type < 0 )
return type ;
if ( type != V_118 ) {
F_3 ( V_2 -> V_10 , L_31 ,
type , V_4 -> V_9 ) ;
return - V_119 ;
}
V_115 = F_1 ( V_2 , V_4 , V_120 ) ;
if ( V_115 < 0 )
return V_115 ;
switch ( V_115 ) {
case V_121 :
V_4 -> V_84 = true ;
case V_122 :
V_4 -> V_85 = 4 ;
break;
case V_123 :
V_4 -> V_84 = true ;
case V_124 :
V_4 -> V_85 = 8 ;
break;
case V_125 :
V_4 -> V_85 = 1 ;
V_4 -> V_84 = true ;
V_4 -> V_28 = true ;
break;
case V_126 :
V_4 -> V_85 = 2 ;
V_4 -> V_84 = true ;
V_4 -> V_28 = true ;
break;
default:
F_3 ( V_2 -> V_10 , L_32 , V_115 ) ;
return - V_119 ;
}
if ( V_4 -> V_28 ) {
V_6 = F_1 ( V_2 , V_4 ,
V_45 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_42 = ! ! ( V_6 & V_127 ) ;
V_4 -> V_21 = V_6 & V_44 ;
V_6 = F_1 ( V_2 , V_4 , V_39 ) ;
if ( V_6 < 0 )
return V_6 ;
V_116 = V_6 & V_128 ;
} else {
V_6 = F_1 ( V_2 , V_4 , V_39 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_42 = V_6 & V_48 ;
V_116 = V_6 >> V_46 ;
V_116 &= V_129 ;
V_4 -> V_21 = V_6 >> V_47 ;
V_4 -> V_21 &= V_130 ;
}
switch ( V_116 ) {
case V_38 :
V_4 -> V_35 = true ;
V_4 -> V_34 = false ;
break;
case V_37 :
V_4 -> V_35 = false ;
V_4 -> V_34 = true ;
break;
case V_36 :
V_4 -> V_35 = true ;
V_4 -> V_34 = true ;
break;
case V_33 :
if ( ! V_4 -> V_28 )
return - V_119 ;
V_4 -> V_32 = true ;
break;
default:
F_3 ( V_2 -> V_10 , L_33 ) ;
return - V_119 ;
}
V_6 = F_1 ( V_2 , V_4 , V_89 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_71 = V_6 >> V_88 ;
V_4 -> V_71 &= V_131 ;
V_6 = F_1 ( V_2 , V_4 , V_91 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_63 = V_6 >> V_90 ;
V_4 -> V_63 &= V_132 ;
V_6 = F_1 ( V_2 , V_4 , V_96 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_4 -> V_28 && ( V_6 & V_95 ) )
V_4 -> V_80 =
( V_6 & V_133 ) + 1 ;
else if ( ! V_4 -> V_28 )
V_4 -> V_80 = F_34 ( V_6 ) ;
else
V_4 -> V_80 = 0 ;
V_6 = F_1 ( V_2 , V_4 , V_94 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_76 = V_6 >> V_93 ;
V_4 -> V_76 &= V_134 ;
V_4 -> V_56 = V_6 >> V_92 ;
V_4 -> V_56 &= V_135 ;
if ( V_4 -> V_28 ) {
V_6 = F_1 ( V_2 , V_4 ,
V_41 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_40 = ( V_6 & V_136 ) + 1 ;
}
V_4 -> V_49 = true ;
return 0 ;
}
static int F_35 ( struct V_137 * V_138 )
{
struct V_139 * V_10 = & V_138 -> V_10 ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
struct V_3 * V_4 , * V_144 ;
struct V_1 * V_2 ;
int V_7 , V_14 , V_83 ;
T_1 V_145 ;
V_7 = F_36 ( V_10 -> V_146 , L_34 , & V_145 ) ;
if ( V_7 < 0 ) {
F_3 ( V_10 , L_35 ) ;
return V_7 ;
}
V_14 = F_37 ( V_138 ) ;
if ( ! V_14 )
return - V_26 ;
if ( V_14 < 0 )
return V_14 ;
F_38 ( V_14 > F_10 ( V_24 ) ) ;
V_2 = F_39 ( V_10 , sizeof( * V_2 ) , V_147 ) ;
if ( ! V_2 )
return - V_148 ;
F_40 ( V_138 , V_2 ) ;
V_2 -> V_10 = & V_138 -> V_10 ;
V_2 -> V_8 = F_41 ( V_10 -> V_149 , NULL ) ;
V_141 = F_42 ( V_10 , V_14 , sizeof( * V_141 ) , V_147 ) ;
if ( ! V_141 )
return - V_148 ;
V_144 = F_42 ( V_10 , V_14 , sizeof( * V_144 ) , V_147 ) ;
if ( ! V_144 )
return - V_148 ;
V_143 = F_39 ( V_10 , sizeof( * V_143 ) , V_147 ) ;
if ( ! V_143 )
return - V_148 ;
V_143 -> V_150 = & V_151 ;
V_143 -> V_152 = & V_153 ;
V_143 -> V_154 = & V_155 ;
V_143 -> V_156 = V_157 ;
V_143 -> V_17 = F_43 ( V_10 ) ;
V_143 -> V_16 = V_141 ;
V_143 -> V_14 = V_14 ;
V_143 -> V_158 = F_10 ( V_159 ) ;
V_143 -> V_160 = V_159 ;
#ifdef F_44
V_143 -> V_161 = V_162 ;
#endif
for ( V_83 = 0 ; V_83 < V_14 ; V_83 ++ , V_141 ++ ) {
V_4 = & V_144 [ V_83 ] ;
V_141 -> V_27 = V_4 ;
V_141 -> V_19 = V_83 ;
V_141 -> V_17 = V_24 [ V_83 ] ;
V_4 -> V_113 = F_45 ( V_138 , V_83 ) ;
if ( V_4 -> V_113 < 0 )
return V_4 -> V_113 ;
V_4 -> V_9 = V_145 + V_83 * V_163 ;
V_7 = F_33 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_2 -> V_106 = V_164 ;
V_2 -> V_106 . V_149 = V_10 ;
V_2 -> V_106 . V_9 = - 1 ;
V_2 -> V_106 . V_114 = V_14 ;
V_2 -> V_106 . V_165 = F_43 ( V_10 ) ;
V_2 -> V_106 . V_112 = 2 ;
V_2 -> V_106 . V_166 = false ;
V_2 -> V_107 = F_46 ( V_10 , V_143 , V_2 ) ;
if ( F_47 ( V_2 -> V_107 ) )
return F_48 ( V_2 -> V_107 ) ;
V_7 = F_49 ( & V_2 -> V_106 , V_2 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_10 , L_36 ) ;
return V_7 ;
}
V_7 = F_50 ( & V_2 -> V_106 , F_43 ( V_10 ) , 0 , 0 , V_14 ) ;
if ( V_7 ) {
F_3 ( V_10 , L_37 ) ;
goto V_167;
}
return 0 ;
V_167:
F_51 ( & V_2 -> V_106 ) ;
return V_7 ;
}
static int F_52 ( struct V_137 * V_138 )
{
struct V_1 * V_2 = F_53 ( V_138 ) ;
F_51 ( & V_2 -> V_106 ) ;
return 0 ;
}
