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
static int F_10 ( struct V_13 * V_14 , unsigned V_17 ,
const unsigned * * V_18 , unsigned * V_20 )
{
* V_18 = & V_14 -> V_15 -> V_18 [ V_17 ] . V_21 ;
* V_20 = 1 ;
return 0 ;
}
static int F_11 ( struct V_22 * V_23 ,
struct V_13 * V_14 ,
unsigned long * * V_24 ,
unsigned int * V_25 )
{
struct V_26 * V_27 ;
unsigned long V_28 ;
int V_9 , V_29 ;
T_1 V_8 ;
for ( V_29 = 0 ; V_29 < F_12 ( V_26 ) ; V_29 ++ ) {
V_27 = & V_26 [ V_29 ] ;
V_9 = F_13 ( V_23 , V_27 -> V_30 , & V_8 ) ;
if ( V_9 == - V_31 )
continue;
if ( V_9 )
V_8 = 0 ;
F_14 ( V_14 -> V_12 , L_3 ,
V_27 -> V_30 , V_8 ) ;
V_28 = F_15 ( V_27 -> V_32 , V_8 ) ;
V_9 = F_16 ( V_14 , V_24 , V_25 , V_28 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_17 ( struct V_13 * V_14 ,
struct V_22 * V_23 ,
struct V_33 * * V_10 ,
unsigned * V_34 , unsigned * V_35 ,
enum V_36 type )
{
unsigned long * V_24 = NULL ;
unsigned V_25 = 0 ;
struct V_30 * V_37 ;
const char * V_38 ;
int V_9 ;
V_9 = F_11 ( V_23 , V_14 , & V_24 , & V_25 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_25 )
return 0 ;
V_9 = F_18 ( V_23 , L_4 ) ;
if ( V_9 < 0 )
goto exit;
V_9 = F_19 ( V_14 , V_10 , V_34 , V_35 , V_9 ) ;
if ( V_9 < 0 )
goto exit;
F_20 (np, L_4 , prop, group) {
V_9 = F_21 ( V_14 , V_10 ,
V_34 , V_35 , V_38 ,
V_24 , V_25 , type ) ;
if ( V_9 < 0 )
break;
}
exit:
F_22 ( V_24 ) ;
return V_9 ;
}
static int F_23 ( struct V_13 * V_14 ,
struct V_22 * V_39 ,
struct V_33 * * V_10 , unsigned * V_35 )
{
enum V_36 type ;
struct V_22 * V_23 ;
unsigned V_34 ;
int V_9 ;
V_9 = 0 ;
* V_10 = NULL ;
* V_35 = 0 ;
V_34 = 0 ;
type = V_40 ;
F_24 (np_config, np) {
V_9 = F_25 ( V_14 , V_23 , V_10 ,
& V_34 , V_35 , type ) ;
if ( V_9 )
break;
V_9 = F_17 ( V_14 , V_23 , V_10 , & V_34 ,
V_35 , type ) ;
if ( V_9 )
break;
}
if ( V_9 < 0 )
F_26 ( V_14 , * V_10 , * V_35 ) ;
return V_9 ;
}
static int F_27 ( struct V_13 * V_14 )
{
return F_12 ( V_41 ) ;
}
static const char * F_28 ( struct V_13 * V_14 ,
unsigned V_42 )
{
return V_41 [ V_42 ] ;
}
static int F_29 ( struct V_13 * V_14 ,
unsigned V_42 ,
const char * const * * V_43 ,
unsigned * const V_44 )
{
* V_43 = V_45 ;
* V_44 = V_14 -> V_15 -> V_16 ;
return 0 ;
}
static int F_30 ( struct V_13 * V_14 , unsigned V_42 ,
unsigned V_17 )
{
struct V_1 * V_4 = F_31 ( V_14 ) ;
struct V_5 * V_6 ;
unsigned int V_8 ;
int V_9 ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_46 ;
V_6 -> V_42 = V_42 ;
V_8 = 0 ;
if ( V_6 -> V_47 ) {
if ( V_6 -> V_48 )
V_8 = 2 ;
else
V_8 = 1 ;
}
V_8 |= V_6 -> V_42 << V_49 ;
V_8 |= V_6 -> V_50 & V_51 ;
V_9 = F_6 ( V_4 , V_6 , V_52 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_6 -> V_53 << V_54 ;
return F_6 ( V_4 , V_6 , V_55 , V_8 ) ;
}
static int F_32 ( struct V_13 * V_14 ,
unsigned int V_17 , unsigned long * V_56 )
{
unsigned V_32 = F_33 ( * V_56 ) ;
struct V_5 * V_6 ;
unsigned V_57 ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_46 ;
switch ( V_32 ) {
case V_58 :
V_57 = V_6 -> V_59 == V_60 ;
break;
case V_61 :
V_57 = V_6 -> V_59 == V_62 ;
break;
case V_63 :
V_57 = V_6 -> V_59 == V_64 ;
break;
case V_65 :
V_57 = V_6 -> V_66 == V_67 ;
break;
case V_68 :
V_57 = V_6 -> V_66 = V_69 ;
break;
case V_70 :
V_57 = V_6 -> V_66 == V_71 ;
break;
case V_72 :
V_57 = ! V_6 -> V_53 ;
break;
case V_73 :
V_57 = V_6 -> V_74 ;
break;
case V_75 :
V_57 = V_6 -> V_48 ;
break;
case V_76 :
V_57 = V_6 -> V_50 ;
break;
case V_77 :
V_57 = V_6 -> V_66 ;
break;
case V_78 :
V_57 = V_6 -> V_79 ;
break;
default:
return - V_31 ;
}
* V_56 = F_15 ( V_32 , V_57 ) ;
return 0 ;
}
static int F_34 ( struct V_13 * V_14 , unsigned int V_17 ,
unsigned long * V_24 , unsigned V_25 )
{
struct V_1 * V_4 = F_31 ( V_14 ) ;
struct V_5 * V_6 ;
unsigned V_32 , V_57 ;
unsigned int V_8 ;
int V_29 , V_9 ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_46 ;
for ( V_29 = 0 ; V_29 < V_25 ; V_29 ++ ) {
V_32 = F_33 ( V_24 [ V_29 ] ) ;
V_57 = F_35 ( V_24 [ V_29 ] ) ;
switch ( V_32 ) {
case V_58 :
V_6 -> V_59 = V_60 ;
break;
case V_61 :
if ( ! V_6 -> V_80 )
return - V_31 ;
V_6 -> V_59 = V_62 ;
break;
case V_63 :
if ( ! V_6 -> V_80 )
return - V_31 ;
V_6 -> V_59 = V_64 ;
break;
case V_68 :
V_6 -> V_66 = V_69 ;
break;
case V_70 :
V_6 -> V_66 = V_71 ;
break;
case V_65 :
if ( V_57 )
V_6 -> V_66 = V_67 ;
else
V_6 -> V_66 = V_69 ;
break;
case V_72 :
V_6 -> V_53 = false ;
break;
case V_73 :
if ( V_57 > V_6 -> V_81 )
return - V_31 ;
V_6 -> V_74 = V_57 ;
break;
case V_75 :
V_6 -> V_48 = V_57 ? true : false ;
break;
case V_76 :
V_6 -> V_47 = true ;
V_6 -> V_50 = V_57 ;
break;
case V_77 :
if ( V_57 > V_82 )
return - V_31 ;
V_6 -> V_66 = V_57 ;
break;
case V_78 :
if ( V_57 > V_83 )
return - V_31 ;
V_6 -> V_79 = V_57 ;
break;
default:
return - V_31 ;
}
}
V_8 = V_6 -> V_74 << V_84 ;
V_9 = F_6 ( V_4 , V_6 , V_85 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_6 -> V_66 << V_86 ;
V_9 = F_6 ( V_4 , V_6 , V_87 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_6 -> V_59 << V_88 ;
V_8 = V_6 -> V_79 << V_89 ;
V_9 = F_6 ( V_4 , V_6 , V_90 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = 0 ;
if ( V_6 -> V_47 ) {
if ( V_6 -> V_48 )
V_8 = 2 ;
else
V_8 = 1 ;
}
V_8 = V_8 << V_91 ;
V_8 |= V_6 -> V_42 << V_49 ;
V_8 |= V_6 -> V_50 & V_51 ;
return F_6 ( V_4 , V_6 , V_52 , V_8 ) ;
}
static void F_36 ( struct V_13 * V_14 ,
struct V_92 * V_93 , unsigned V_17 )
{
struct V_1 * V_4 = F_31 ( V_14 ) ;
struct V_5 * V_6 ;
int V_9 , V_8 ;
static const char * const V_94 [] = {
L_5 , L_6 , L_7 ,
L_8 , L_9 , L_10
} ;
static const char * const V_95 [] = {
L_11 , L_12 , L_13
} ;
static const char * const V_96 [] = {
L_14 , L_15 , L_16 , L_17
} ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_46 ;
F_37 ( V_93 , L_18 , V_17 + V_97 ) ;
V_8 = F_3 ( V_4 , V_6 , V_55 ) ;
if ( V_8 < 0 || ! ( V_8 >> V_54 ) ) {
F_38 ( V_93 , L_19 ) ;
} else {
if ( ! V_6 -> V_48 ) {
V_9 = F_3 ( V_4 , V_6 , V_98 ) ;
if ( ! V_9 ) {
V_9 &= V_99 ;
V_6 -> V_50 = V_9 ;
}
}
F_37 ( V_93 , L_20 , V_6 -> V_47 ? L_21 : L_22 ) ;
F_37 ( V_93 , L_23 , V_41 [ V_6 -> V_42 ] ) ;
F_37 ( V_93 , L_24 , V_6 -> V_74 ) ;
F_37 ( V_93 , L_25 , V_94 [ V_6 -> V_66 ] ) ;
F_37 ( V_93 , L_26 , V_95 [ V_6 -> V_59 ] ) ;
F_37 ( V_93 , L_20 , V_6 -> V_50 ? L_15 : L_17 ) ;
F_37 ( V_93 , L_23 , V_96 [ V_6 -> V_79 ] ) ;
}
}
static int F_39 ( struct V_2 * V_3 , unsigned V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_56 ;
V_56 = F_15 ( V_75 , 1 ) ;
return F_34 ( V_4 -> V_100 , V_17 , & V_56 , 1 ) ;
}
static int F_40 ( struct V_2 * V_3 ,
unsigned V_17 , int V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_56 ;
V_56 = F_15 ( V_76 , V_8 ) ;
return F_34 ( V_4 -> V_100 , V_17 , & V_56 , 1 ) ;
}
static int F_41 ( struct V_2 * V_3 , unsigned V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 ;
int V_9 ;
V_6 = V_4 -> V_100 -> V_15 -> V_18 [ V_17 ] . V_46 ;
if ( ! V_6 -> V_53 )
return - V_31 ;
if ( V_6 -> V_48 ) {
V_9 = F_3 ( V_4 , V_6 , V_98 ) ;
if ( V_9 < 0 )
return V_9 ;
V_6 -> V_50 = V_9 & V_99 ;
}
return V_6 -> V_50 ;
}
static void F_42 ( struct V_2 * V_3 , unsigned V_17 , int V_101 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_56 ;
V_56 = F_15 ( V_76 , V_101 ) ;
F_34 ( V_4 -> V_100 , V_17 , & V_56 , 1 ) ;
}
static int F_43 ( struct V_2 * V_3 , unsigned V_11 )
{
return F_44 ( V_3 -> V_11 + V_11 ) ;
}
static void F_45 ( struct V_2 * V_3 , unsigned V_11 )
{
F_46 ( V_3 -> V_11 + V_11 ) ;
}
static int F_47 ( struct V_2 * V_3 ,
const struct V_102 * V_103 ,
T_1 * V_104 )
{
if ( V_3 -> V_105 < 2 )
return - V_31 ;
if ( V_104 )
* V_104 = V_103 -> args [ 1 ] ;
return V_103 -> args [ 0 ] - V_97 ;
}
static int F_48 ( struct V_2 * V_3 , unsigned V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 ;
V_6 = V_4 -> V_100 -> V_15 -> V_18 [ V_17 ] . V_46 ;
return V_6 -> V_106 ;
}
static void F_49 ( struct V_92 * V_93 , struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned V_29 ;
for ( V_29 = 0 ; V_29 < V_3 -> V_107 ; V_29 ++ ) {
F_36 ( V_4 -> V_100 , V_93 , V_29 ) ;
F_38 ( V_93 , L_27 ) ;
}
}
static int F_50 ( struct V_1 * V_4 ,
struct V_5 * V_6 )
{
int type , V_108 , V_8 , V_109 ;
type = F_3 ( V_4 , V_6 , V_110 ) ;
if ( type < 0 )
return type ;
if ( type != V_111 ) {
F_5 ( V_4 -> V_12 , L_28 ,
type , V_6 -> V_11 ) ;
return - V_112 ;
}
V_108 = F_3 ( V_4 , V_6 , V_113 ) ;
if ( V_108 < 0 )
return V_108 ;
switch ( V_108 ) {
case V_114 :
V_6 -> V_80 = true ;
case V_115 :
V_6 -> V_81 = 4 ;
break;
case V_116 :
V_6 -> V_80 = true ;
case V_117 :
V_6 -> V_81 = 8 ;
break;
default:
F_5 ( V_4 -> V_12 , L_29 , V_108 ) ;
return - V_112 ;
}
V_8 = F_3 ( V_4 , V_6 , V_52 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_50 = V_8 & V_51 ;
V_109 = V_8 >> V_91 ;
V_109 &= V_118 ;
switch ( V_109 ) {
case 0 :
V_6 -> V_48 = true ;
V_6 -> V_47 = false ;
break;
case 1 :
V_6 -> V_48 = false ;
V_6 -> V_47 = true ;
break;
case 2 :
V_6 -> V_48 = true ;
V_6 -> V_47 = true ;
break;
default:
F_5 ( V_4 -> V_12 , L_30 ) ;
return - V_112 ;
}
V_6 -> V_42 = V_8 >> V_49 ;
V_6 -> V_42 &= V_119 ;
V_8 = F_3 ( V_4 , V_6 , V_85 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_74 = V_8 >> V_84 ;
V_6 -> V_74 &= V_120 ;
V_8 = F_3 ( V_4 , V_6 , V_87 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_66 = V_8 >> V_86 ;
V_6 -> V_66 &= V_121 ;
V_8 = F_3 ( V_4 , V_6 , V_90 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_79 = V_8 >> V_89 ;
V_6 -> V_79 &= V_122 ;
V_6 -> V_59 = V_8 >> V_88 ;
V_6 -> V_59 &= V_123 ;
V_6 -> V_53 = true ;
return 0 ;
}
static int F_51 ( struct V_124 * V_125 )
{
struct V_126 * V_12 = & V_125 -> V_12 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_5 * V_6 , * V_131 ;
struct V_1 * V_4 ;
int V_9 , V_16 , V_29 ;
T_1 V_132 [ 2 ] ;
V_9 = F_52 ( V_12 -> V_133 , L_31 , V_132 , 2 ) ;
if ( V_9 < 0 ) {
F_5 ( V_12 , L_32 ) ;
return V_9 ;
}
V_16 = V_132 [ 1 ] / V_134 ;
if ( ! V_16 )
return - V_31 ;
F_53 ( V_16 > F_12 ( V_45 ) ) ;
V_4 = F_54 ( V_12 , sizeof( * V_4 ) , V_135 ) ;
if ( ! V_4 )
return - V_136 ;
F_55 ( V_125 , V_4 ) ;
V_4 -> V_12 = & V_125 -> V_12 ;
V_4 -> V_10 = F_56 ( V_12 -> V_137 , NULL ) ;
V_128 = F_57 ( V_12 , V_16 , sizeof( * V_128 ) , V_135 ) ;
if ( ! V_128 )
return - V_136 ;
V_131 = F_57 ( V_12 , V_16 , sizeof( * V_131 ) , V_135 ) ;
if ( ! V_131 )
return - V_136 ;
V_130 = F_54 ( V_12 , sizeof( * V_130 ) , V_135 ) ;
if ( ! V_130 )
return - V_136 ;
V_130 -> V_138 = & V_139 ;
V_130 -> V_140 = & V_141 ;
V_130 -> V_142 = & V_143 ;
V_130 -> V_144 = V_145 ;
V_130 -> V_19 = F_58 ( V_12 ) ;
V_130 -> V_18 = V_128 ;
V_130 -> V_16 = V_16 ;
for ( V_29 = 0 ; V_29 < V_16 ; V_29 ++ , V_128 ++ ) {
V_6 = & V_131 [ V_29 ] ;
V_128 -> V_46 = V_6 ;
V_128 -> V_21 = V_29 ;
V_128 -> V_19 = V_45 [ V_29 ] ;
V_6 -> V_106 = F_59 ( V_125 , V_29 ) ;
if ( V_6 -> V_106 < 0 )
return V_6 -> V_106 ;
V_6 -> V_11 = V_132 [ 0 ] + V_29 * V_134 ;
V_9 = F_50 ( V_4 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
}
V_4 -> V_3 = V_146 ;
V_4 -> V_3 . V_12 = V_12 ;
V_4 -> V_3 . V_11 = - 1 ;
V_4 -> V_3 . V_107 = V_16 ;
V_4 -> V_3 . V_147 = F_58 ( V_12 ) ;
V_4 -> V_3 . V_105 = 2 ;
V_4 -> V_3 . V_148 = false ;
V_4 -> V_100 = F_60 ( V_130 , V_12 , V_4 ) ;
if ( ! V_4 -> V_100 )
return - V_112 ;
V_9 = F_61 ( & V_4 -> V_3 ) ;
if ( V_9 ) {
F_5 ( V_4 -> V_12 , L_33 ) ;
goto V_149;
}
V_9 = F_62 ( & V_4 -> V_3 , F_58 ( V_12 ) , 0 , 0 , V_16 ) ;
if ( V_9 ) {
F_5 ( V_12 , L_34 ) ;
goto V_150;
}
return 0 ;
V_150:
F_63 ( & V_4 -> V_3 ) ;
V_149:
F_64 ( V_4 -> V_100 ) ;
return V_9 ;
}
static int F_65 ( struct V_124 * V_125 )
{
struct V_1 * V_4 = F_66 ( V_125 ) ;
F_63 ( & V_4 -> V_3 ) ;
F_64 ( V_4 -> V_100 ) ;
return 0 ;
}
