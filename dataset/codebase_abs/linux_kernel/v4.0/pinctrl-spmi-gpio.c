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
static int F_15 ( struct V_13 * V_14 , unsigned V_23 ,
unsigned V_17 )
{
struct V_1 * V_4 = F_16 ( V_14 ) ;
struct V_5 * V_6 ;
unsigned int V_8 ;
int V_9 ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_27 ;
V_6 -> V_23 = V_23 ;
V_8 = 0 ;
if ( V_6 -> V_28 ) {
if ( V_6 -> V_29 )
V_8 = 2 ;
else
V_8 = 1 ;
}
V_8 |= V_6 -> V_23 << V_30 ;
V_8 |= V_6 -> V_31 & V_32 ;
V_9 = F_6 ( V_4 , V_6 , V_33 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_6 -> V_34 << V_35 ;
return F_6 ( V_4 , V_6 , V_36 , V_8 ) ;
}
static int F_17 ( struct V_13 * V_14 ,
unsigned int V_17 , unsigned long * V_37 )
{
unsigned V_38 = F_18 ( * V_37 ) ;
struct V_5 * V_6 ;
unsigned V_39 ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_27 ;
switch ( V_38 ) {
case V_40 :
V_39 = V_6 -> V_41 == V_42 ;
break;
case V_43 :
V_39 = V_6 -> V_41 == V_44 ;
break;
case V_45 :
V_39 = V_6 -> V_41 == V_46 ;
break;
case V_47 :
V_39 = V_6 -> V_48 == V_49 ;
break;
case V_50 :
V_39 = V_6 -> V_48 = V_51 ;
break;
case V_52 :
V_39 = V_6 -> V_48 == V_53 ;
break;
case V_54 :
V_39 = ! V_6 -> V_34 ;
break;
case V_55 :
V_39 = V_6 -> V_56 ;
break;
case V_57 :
V_39 = V_6 -> V_29 ;
break;
case V_58 :
V_39 = V_6 -> V_31 ;
break;
case V_59 :
V_39 = V_6 -> V_48 ;
break;
case V_60 :
V_39 = V_6 -> V_61 ;
break;
default:
return - V_62 ;
}
* V_37 = F_19 ( V_38 , V_39 ) ;
return 0 ;
}
static int F_20 ( struct V_13 * V_14 , unsigned int V_17 ,
unsigned long * V_63 , unsigned V_64 )
{
struct V_1 * V_4 = F_16 ( V_14 ) ;
struct V_5 * V_6 ;
unsigned V_38 , V_39 ;
unsigned int V_8 ;
int V_65 , V_9 ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_27 ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
V_38 = F_18 ( V_63 [ V_65 ] ) ;
V_39 = F_21 ( V_63 [ V_65 ] ) ;
switch ( V_38 ) {
case V_40 :
V_6 -> V_41 = V_42 ;
break;
case V_43 :
if ( ! V_6 -> V_66 )
return - V_62 ;
V_6 -> V_41 = V_44 ;
break;
case V_45 :
if ( ! V_6 -> V_66 )
return - V_62 ;
V_6 -> V_41 = V_46 ;
break;
case V_50 :
V_6 -> V_48 = V_51 ;
break;
case V_52 :
V_6 -> V_48 = V_53 ;
break;
case V_47 :
if ( V_39 )
V_6 -> V_48 = V_49 ;
else
V_6 -> V_48 = V_51 ;
break;
case V_54 :
V_6 -> V_34 = false ;
break;
case V_55 :
if ( V_39 > V_6 -> V_67 )
return - V_62 ;
V_6 -> V_56 = V_39 ;
break;
case V_57 :
V_6 -> V_29 = V_39 ? true : false ;
break;
case V_58 :
V_6 -> V_28 = true ;
V_6 -> V_31 = V_39 ;
break;
case V_59 :
if ( V_39 > V_68 )
return - V_62 ;
V_6 -> V_48 = V_39 ;
break;
case V_60 :
if ( V_39 > V_69 )
return - V_62 ;
V_6 -> V_61 = V_39 ;
break;
default:
return - V_62 ;
}
}
V_8 = V_6 -> V_56 << V_70 ;
V_9 = F_6 ( V_4 , V_6 , V_71 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_6 -> V_48 << V_72 ;
V_9 = F_6 ( V_4 , V_6 , V_73 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_6 -> V_41 << V_74 ;
V_8 = V_6 -> V_61 << V_75 ;
V_9 = F_6 ( V_4 , V_6 , V_76 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = 0 ;
if ( V_6 -> V_28 ) {
if ( V_6 -> V_29 )
V_8 = 2 ;
else
V_8 = 1 ;
}
V_8 = V_8 << V_77 ;
V_8 |= V_6 -> V_23 << V_30 ;
V_8 |= V_6 -> V_31 & V_32 ;
return F_6 ( V_4 , V_6 , V_33 , V_8 ) ;
}
static void F_22 ( struct V_13 * V_14 ,
struct V_78 * V_79 , unsigned V_17 )
{
struct V_1 * V_4 = F_16 ( V_14 ) ;
struct V_5 * V_6 ;
int V_9 , V_8 ;
static const char * const V_80 [] = {
L_3 , L_4 , L_5 ,
L_6 , L_7 , L_8
} ;
static const char * const V_81 [] = {
L_9 , L_10 , L_11
} ;
static const char * const V_82 [] = {
L_12 , L_13 , L_14 , L_15
} ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_27 ;
F_23 ( V_79 , L_16 , V_17 + V_83 ) ;
V_8 = F_3 ( V_4 , V_6 , V_36 ) ;
if ( V_8 < 0 || ! ( V_8 >> V_35 ) ) {
F_24 ( V_79 , L_17 ) ;
} else {
if ( ! V_6 -> V_29 ) {
V_9 = F_3 ( V_4 , V_6 , V_84 ) ;
if ( ! V_9 ) {
V_9 &= V_85 ;
V_6 -> V_31 = V_9 ;
}
}
F_23 ( V_79 , L_18 , V_6 -> V_28 ? L_19 : L_20 ) ;
F_23 ( V_79 , L_21 , V_22 [ V_6 -> V_23 ] ) ;
F_23 ( V_79 , L_22 , V_6 -> V_56 ) ;
F_23 ( V_79 , L_23 , V_80 [ V_6 -> V_48 ] ) ;
F_23 ( V_79 , L_24 , V_81 [ V_6 -> V_41 ] ) ;
F_23 ( V_79 , L_18 , V_6 -> V_31 ? L_13 : L_15 ) ;
F_23 ( V_79 , L_21 , V_82 [ V_6 -> V_61 ] ) ;
}
}
static int F_25 ( struct V_2 * V_3 , unsigned V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_37 ;
V_37 = F_19 ( V_57 , 1 ) ;
return F_20 ( V_4 -> V_86 , V_17 , & V_37 , 1 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
unsigned V_17 , int V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_37 ;
V_37 = F_19 ( V_58 , V_8 ) ;
return F_20 ( V_4 -> V_86 , V_17 , & V_37 , 1 ) ;
}
static int F_27 ( struct V_2 * V_3 , unsigned V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 ;
int V_9 ;
V_6 = V_4 -> V_86 -> V_15 -> V_18 [ V_17 ] . V_27 ;
if ( ! V_6 -> V_34 )
return - V_62 ;
if ( V_6 -> V_29 ) {
V_9 = F_3 ( V_4 , V_6 , V_84 ) ;
if ( V_9 < 0 )
return V_9 ;
V_6 -> V_31 = V_9 & V_85 ;
}
return V_6 -> V_31 ;
}
static void F_28 ( struct V_2 * V_3 , unsigned V_17 , int V_87 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_37 ;
V_37 = F_19 ( V_58 , V_87 ) ;
F_20 ( V_4 -> V_86 , V_17 , & V_37 , 1 ) ;
}
static int F_29 ( struct V_2 * V_3 , unsigned V_11 )
{
return F_30 ( V_3 -> V_11 + V_11 ) ;
}
static void F_31 ( struct V_2 * V_3 , unsigned V_11 )
{
F_32 ( V_3 -> V_11 + V_11 ) ;
}
static int F_33 ( struct V_2 * V_3 ,
const struct V_88 * V_89 ,
T_1 * V_90 )
{
if ( V_3 -> V_91 < 2 )
return - V_62 ;
if ( V_90 )
* V_90 = V_89 -> args [ 1 ] ;
return V_89 -> args [ 0 ] - V_83 ;
}
static int F_34 ( struct V_2 * V_3 , unsigned V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 ;
V_6 = V_4 -> V_86 -> V_15 -> V_18 [ V_17 ] . V_27 ;
return V_6 -> V_92 ;
}
static void F_35 ( struct V_78 * V_79 , struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned V_65 ;
for ( V_65 = 0 ; V_65 < V_3 -> V_93 ; V_65 ++ ) {
F_22 ( V_4 -> V_86 , V_79 , V_65 ) ;
F_24 ( V_79 , L_25 ) ;
}
}
static int F_36 ( struct V_1 * V_4 ,
struct V_5 * V_6 )
{
int type , V_94 , V_8 , V_95 ;
type = F_3 ( V_4 , V_6 , V_96 ) ;
if ( type < 0 )
return type ;
if ( type != V_97 ) {
F_5 ( V_4 -> V_12 , L_26 ,
type , V_6 -> V_11 ) ;
return - V_98 ;
}
V_94 = F_3 ( V_4 , V_6 , V_99 ) ;
if ( V_94 < 0 )
return V_94 ;
switch ( V_94 ) {
case V_100 :
V_6 -> V_66 = true ;
case V_101 :
V_6 -> V_67 = 4 ;
break;
case V_102 :
V_6 -> V_66 = true ;
case V_103 :
V_6 -> V_67 = 8 ;
break;
default:
F_5 ( V_4 -> V_12 , L_27 , V_94 ) ;
return - V_98 ;
}
V_8 = F_3 ( V_4 , V_6 , V_33 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_31 = V_8 & V_32 ;
V_95 = V_8 >> V_77 ;
V_95 &= V_104 ;
switch ( V_95 ) {
case 0 :
V_6 -> V_29 = true ;
V_6 -> V_28 = false ;
break;
case 1 :
V_6 -> V_29 = false ;
V_6 -> V_28 = true ;
break;
case 2 :
V_6 -> V_29 = true ;
V_6 -> V_28 = true ;
break;
default:
F_5 ( V_4 -> V_12 , L_28 ) ;
return - V_98 ;
}
V_6 -> V_23 = V_8 >> V_30 ;
V_6 -> V_23 &= V_105 ;
V_8 = F_3 ( V_4 , V_6 , V_71 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_56 = V_8 >> V_70 ;
V_6 -> V_56 &= V_106 ;
V_8 = F_3 ( V_4 , V_6 , V_73 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_48 = V_8 >> V_72 ;
V_6 -> V_48 &= V_107 ;
V_8 = F_3 ( V_4 , V_6 , V_76 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_61 = V_8 >> V_75 ;
V_6 -> V_61 &= V_108 ;
V_6 -> V_41 = V_8 >> V_74 ;
V_6 -> V_41 &= V_109 ;
V_6 -> V_34 = true ;
return 0 ;
}
static int F_37 ( struct V_110 * V_111 )
{
struct V_112 * V_12 = & V_111 -> V_12 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
struct V_5 * V_6 , * V_117 ;
struct V_1 * V_4 ;
int V_9 , V_16 , V_65 ;
T_1 V_118 [ 2 ] ;
V_9 = F_38 ( V_12 -> V_119 , L_29 , V_118 , 2 ) ;
if ( V_9 < 0 ) {
F_5 ( V_12 , L_30 ) ;
return V_9 ;
}
V_16 = V_118 [ 1 ] / V_120 ;
if ( ! V_16 )
return - V_62 ;
F_39 ( V_16 > F_12 ( V_26 ) ) ;
V_4 = F_40 ( V_12 , sizeof( * V_4 ) , V_121 ) ;
if ( ! V_4 )
return - V_122 ;
F_41 ( V_111 , V_4 ) ;
V_4 -> V_12 = & V_111 -> V_12 ;
V_4 -> V_10 = F_42 ( V_12 -> V_123 , NULL ) ;
V_114 = F_43 ( V_12 , V_16 , sizeof( * V_114 ) , V_121 ) ;
if ( ! V_114 )
return - V_122 ;
V_117 = F_43 ( V_12 , V_16 , sizeof( * V_117 ) , V_121 ) ;
if ( ! V_117 )
return - V_122 ;
V_116 = F_40 ( V_12 , sizeof( * V_116 ) , V_121 ) ;
if ( ! V_116 )
return - V_122 ;
V_116 -> V_124 = & V_125 ;
V_116 -> V_126 = & V_127 ;
V_116 -> V_128 = & V_129 ;
V_116 -> V_130 = V_131 ;
V_116 -> V_19 = F_44 ( V_12 ) ;
V_116 -> V_18 = V_114 ;
V_116 -> V_16 = V_16 ;
V_116 -> V_132 = F_12 ( V_133 ) ;
V_116 -> V_134 = V_133 ;
#ifdef F_45
V_116 -> V_135 = V_136 ;
#endif
for ( V_65 = 0 ; V_65 < V_16 ; V_65 ++ , V_114 ++ ) {
V_6 = & V_117 [ V_65 ] ;
V_114 -> V_27 = V_6 ;
V_114 -> V_21 = V_65 ;
V_114 -> V_19 = V_26 [ V_65 ] ;
V_6 -> V_92 = F_46 ( V_111 , V_65 ) ;
if ( V_6 -> V_92 < 0 )
return V_6 -> V_92 ;
V_6 -> V_11 = V_118 [ 0 ] + V_65 * V_120 ;
V_9 = F_36 ( V_4 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
}
V_4 -> V_3 = V_137 ;
V_4 -> V_3 . V_12 = V_12 ;
V_4 -> V_3 . V_11 = - 1 ;
V_4 -> V_3 . V_93 = V_16 ;
V_4 -> V_3 . V_138 = F_44 ( V_12 ) ;
V_4 -> V_3 . V_91 = 2 ;
V_4 -> V_3 . V_139 = false ;
V_4 -> V_86 = F_47 ( V_116 , V_12 , V_4 ) ;
if ( ! V_4 -> V_86 )
return - V_98 ;
V_9 = F_48 ( & V_4 -> V_3 ) ;
if ( V_9 ) {
F_5 ( V_4 -> V_12 , L_31 ) ;
goto V_140;
}
V_9 = F_49 ( & V_4 -> V_3 , F_44 ( V_12 ) , 0 , 0 , V_16 ) ;
if ( V_9 ) {
F_5 ( V_12 , L_32 ) ;
goto V_141;
}
return 0 ;
V_141:
F_50 ( & V_4 -> V_3 ) ;
V_140:
F_51 ( V_4 -> V_86 ) ;
return V_9 ;
}
static int F_52 ( struct V_110 * V_111 )
{
struct V_1 * V_4 = F_53 ( V_111 ) ;
F_50 ( & V_4 -> V_3 ) ;
F_51 ( V_4 -> V_86 ) ;
return 0 ;
}
