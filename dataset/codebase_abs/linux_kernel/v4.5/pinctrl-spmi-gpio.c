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
V_4 = V_12 -> V_13 -> V_16 [ V_15 ] . V_25 ;
V_4 -> V_21 = V_21 ;
V_6 = 0 ;
if ( V_4 -> V_26 ) {
if ( V_4 -> V_27 )
V_6 = 2 ;
else
V_6 = 1 ;
}
V_6 = V_6 << V_28 ;
V_6 |= V_4 -> V_21 << V_29 ;
V_6 |= V_4 -> V_30 & V_31 ;
V_7 = F_4 ( V_2 , V_4 , V_32 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = V_4 -> V_33 << V_34 ;
return F_4 ( V_2 , V_4 , V_35 , V_6 ) ;
}
static int F_15 ( struct V_11 * V_12 ,
unsigned int V_15 , unsigned long * V_36 )
{
unsigned V_37 = F_16 ( * V_36 ) ;
struct V_3 * V_4 ;
unsigned V_38 ;
V_4 = V_12 -> V_13 -> V_16 [ V_15 ] . V_25 ;
switch ( V_37 ) {
case V_39 :
V_38 = V_4 -> V_40 == V_41 ;
break;
case V_42 :
V_38 = V_4 -> V_40 == V_43 ;
break;
case V_44 :
V_38 = V_4 -> V_40 == V_45 ;
break;
case V_46 :
V_38 = V_4 -> V_47 == V_48 ;
break;
case V_49 :
V_38 = V_4 -> V_47 = V_50 ;
break;
case V_51 :
V_38 = V_4 -> V_47 == V_52 ;
break;
case V_53 :
V_38 = ! V_4 -> V_33 ;
break;
case V_54 :
V_38 = V_4 -> V_55 ;
break;
case V_56 :
V_38 = V_4 -> V_27 ;
break;
case V_57 :
V_38 = V_4 -> V_30 ;
break;
case V_58 :
V_38 = V_4 -> V_47 ;
break;
case V_59 :
V_38 = V_4 -> V_60 ;
break;
default:
return - V_61 ;
}
* V_36 = F_17 ( V_37 , V_38 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 , unsigned int V_15 ,
unsigned long * V_62 , unsigned V_63 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
struct V_3 * V_4 ;
unsigned V_37 , V_38 ;
unsigned int V_6 ;
int V_64 , V_7 ;
V_4 = V_12 -> V_13 -> V_16 [ V_15 ] . V_25 ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
V_37 = F_16 ( V_62 [ V_64 ] ) ;
V_38 = F_19 ( V_62 [ V_64 ] ) ;
switch ( V_37 ) {
case V_39 :
V_4 -> V_40 = V_41 ;
break;
case V_42 :
if ( ! V_4 -> V_65 )
return - V_61 ;
V_4 -> V_40 = V_43 ;
break;
case V_44 :
if ( ! V_4 -> V_65 )
return - V_61 ;
V_4 -> V_40 = V_45 ;
break;
case V_49 :
V_4 -> V_47 = V_50 ;
break;
case V_51 :
V_4 -> V_47 = V_52 ;
break;
case V_46 :
if ( V_38 )
V_4 -> V_47 = V_48 ;
else
V_4 -> V_47 = V_50 ;
break;
case V_53 :
V_4 -> V_33 = false ;
break;
case V_54 :
if ( V_38 > V_4 -> V_66 )
return - V_61 ;
V_4 -> V_55 = V_38 ;
break;
case V_56 :
V_4 -> V_27 = V_38 ? true : false ;
break;
case V_57 :
V_4 -> V_26 = true ;
V_4 -> V_30 = V_38 ;
break;
case V_58 :
if ( V_38 > V_67 )
return - V_61 ;
V_4 -> V_47 = V_38 ;
break;
case V_59 :
if ( V_38 > V_68 )
return - V_61 ;
V_4 -> V_60 = V_38 ;
break;
default:
return - V_61 ;
}
}
V_6 = V_4 -> V_55 << V_69 ;
V_7 = F_4 ( V_2 , V_4 , V_70 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = V_4 -> V_47 << V_71 ;
V_7 = F_4 ( V_2 , V_4 , V_72 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = V_4 -> V_40 << V_73 ;
V_6 |= V_4 -> V_60 << V_74 ;
V_7 = F_4 ( V_2 , V_4 , V_75 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = 0 ;
if ( V_4 -> V_26 ) {
if ( V_4 -> V_27 )
V_6 = 2 ;
else
V_6 = 1 ;
}
V_6 = V_6 << V_28 ;
V_6 |= V_4 -> V_21 << V_29 ;
V_6 |= V_4 -> V_30 & V_31 ;
return F_4 ( V_2 , V_4 , V_32 , V_6 ) ;
}
static void F_20 ( struct V_11 * V_12 ,
struct V_76 * V_77 , unsigned V_15 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
struct V_3 * V_4 ;
int V_7 , V_6 ;
static const char * const V_78 [] = {
L_3 , L_4 , L_5 ,
L_6 , L_7 , L_8
} ;
static const char * const V_79 [] = {
L_9 , L_10 , L_11
} ;
static const char * const V_80 [] = {
L_12 , L_13 , L_14 , L_15
} ;
V_4 = V_12 -> V_13 -> V_16 [ V_15 ] . V_25 ;
F_21 ( V_77 , L_16 , V_15 + V_81 ) ;
V_6 = F_1 ( V_2 , V_4 , V_35 ) ;
if ( V_6 < 0 || ! ( V_6 >> V_34 ) ) {
F_22 ( V_77 , L_17 ) ;
} else {
if ( V_4 -> V_27 ) {
V_7 = F_1 ( V_2 , V_4 , V_82 ) ;
if ( V_7 < 0 )
return;
V_7 &= V_83 ;
V_4 -> V_30 = V_7 ;
}
F_21 ( V_77 , L_18 , V_4 -> V_26 ? L_19 : L_20 ) ;
F_21 ( V_77 , L_21 , V_20 [ V_4 -> V_21 ] ) ;
F_21 ( V_77 , L_22 , V_4 -> V_55 ) ;
F_21 ( V_77 , L_23 , V_78 [ V_4 -> V_47 ] ) ;
F_21 ( V_77 , L_24 , V_79 [ V_4 -> V_40 ] ) ;
F_21 ( V_77 , L_18 , V_4 -> V_30 ? L_13 : L_15 ) ;
F_21 ( V_77 , L_21 , V_80 [ V_4 -> V_60 ] ) ;
}
}
static int F_23 ( struct V_84 * V_85 , unsigned V_15 )
{
struct V_1 * V_2 = F_24 ( V_85 ) ;
unsigned long V_36 ;
V_36 = F_17 ( V_56 , 1 ) ;
return F_18 ( V_2 -> V_86 , V_15 , & V_36 , 1 ) ;
}
static int F_25 ( struct V_84 * V_85 ,
unsigned V_15 , int V_6 )
{
struct V_1 * V_2 = F_24 ( V_85 ) ;
unsigned long V_36 ;
V_36 = F_17 ( V_57 , V_6 ) ;
return F_18 ( V_2 -> V_86 , V_15 , & V_36 , 1 ) ;
}
static int F_26 ( struct V_84 * V_85 , unsigned V_15 )
{
struct V_1 * V_2 = F_24 ( V_85 ) ;
struct V_3 * V_4 ;
int V_7 ;
V_4 = V_2 -> V_86 -> V_13 -> V_16 [ V_15 ] . V_25 ;
if ( ! V_4 -> V_33 )
return - V_61 ;
if ( V_4 -> V_27 ) {
V_7 = F_1 ( V_2 , V_4 , V_82 ) ;
if ( V_7 < 0 )
return V_7 ;
V_4 -> V_30 = V_7 & V_83 ;
}
return ! ! V_4 -> V_30 ;
}
static void F_27 ( struct V_84 * V_85 , unsigned V_15 , int V_87 )
{
struct V_1 * V_2 = F_24 ( V_85 ) ;
unsigned long V_36 ;
V_36 = F_17 ( V_57 , V_87 ) ;
F_18 ( V_2 -> V_86 , V_15 , & V_36 , 1 ) ;
}
static int F_28 ( struct V_84 * V_85 ,
const struct V_88 * V_89 ,
T_1 * V_90 )
{
if ( V_85 -> V_91 < 2 )
return - V_61 ;
if ( V_90 )
* V_90 = V_89 -> args [ 1 ] ;
return V_89 -> args [ 0 ] - V_81 ;
}
static int F_29 ( struct V_84 * V_85 , unsigned V_15 )
{
struct V_1 * V_2 = F_24 ( V_85 ) ;
struct V_3 * V_4 ;
V_4 = V_2 -> V_86 -> V_13 -> V_16 [ V_15 ] . V_25 ;
return V_4 -> V_92 ;
}
static void F_30 ( struct V_76 * V_77 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_24 ( V_85 ) ;
unsigned V_64 ;
for ( V_64 = 0 ; V_64 < V_85 -> V_93 ; V_64 ++ ) {
F_20 ( V_2 -> V_86 , V_77 , V_64 ) ;
F_22 ( V_77 , L_25 ) ;
}
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int type , V_94 , V_6 , V_95 ;
type = F_1 ( V_2 , V_4 , V_96 ) ;
if ( type < 0 )
return type ;
if ( type != V_97 ) {
F_3 ( V_2 -> V_10 , L_26 ,
type , V_4 -> V_9 ) ;
return - V_98 ;
}
V_94 = F_1 ( V_2 , V_4 , V_99 ) ;
if ( V_94 < 0 )
return V_94 ;
switch ( V_94 ) {
case V_100 :
V_4 -> V_65 = true ;
case V_101 :
V_4 -> V_66 = 4 ;
break;
case V_102 :
V_4 -> V_65 = true ;
case V_103 :
V_4 -> V_66 = 8 ;
break;
default:
F_3 ( V_2 -> V_10 , L_27 , V_94 ) ;
return - V_98 ;
}
V_6 = F_1 ( V_2 , V_4 , V_32 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_30 = V_6 & V_31 ;
V_95 = V_6 >> V_28 ;
V_95 &= V_104 ;
switch ( V_95 ) {
case 0 :
V_4 -> V_27 = true ;
V_4 -> V_26 = false ;
break;
case 1 :
V_4 -> V_27 = false ;
V_4 -> V_26 = true ;
break;
case 2 :
V_4 -> V_27 = true ;
V_4 -> V_26 = true ;
break;
default:
F_3 ( V_2 -> V_10 , L_28 ) ;
return - V_98 ;
}
V_4 -> V_21 = V_6 >> V_29 ;
V_4 -> V_21 &= V_105 ;
V_6 = F_1 ( V_2 , V_4 , V_70 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_55 = V_6 >> V_69 ;
V_4 -> V_55 &= V_106 ;
V_6 = F_1 ( V_2 , V_4 , V_72 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_47 = V_6 >> V_71 ;
V_4 -> V_47 &= V_107 ;
V_6 = F_1 ( V_2 , V_4 , V_75 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_60 = V_6 >> V_74 ;
V_4 -> V_60 &= V_108 ;
V_4 -> V_40 = V_6 >> V_73 ;
V_4 -> V_40 &= V_109 ;
V_4 -> V_33 = true ;
return 0 ;
}
static int F_32 ( struct V_110 * V_111 )
{
struct V_112 * V_10 = & V_111 -> V_10 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
struct V_3 * V_4 , * V_117 ;
struct V_1 * V_2 ;
int V_7 , V_14 , V_64 ;
T_1 V_118 ;
V_7 = F_33 ( V_10 -> V_119 , L_29 , & V_118 ) ;
if ( V_7 < 0 ) {
F_3 ( V_10 , L_30 ) ;
return V_7 ;
}
V_14 = F_34 ( V_111 ) ;
if ( ! V_14 )
return - V_61 ;
if ( V_14 < 0 )
return V_14 ;
F_35 ( V_14 > F_10 ( V_24 ) ) ;
V_2 = F_36 ( V_10 , sizeof( * V_2 ) , V_120 ) ;
if ( ! V_2 )
return - V_121 ;
F_37 ( V_111 , V_2 ) ;
V_2 -> V_10 = & V_111 -> V_10 ;
V_2 -> V_8 = F_38 ( V_10 -> V_122 , NULL ) ;
V_114 = F_39 ( V_10 , V_14 , sizeof( * V_114 ) , V_120 ) ;
if ( ! V_114 )
return - V_121 ;
V_117 = F_39 ( V_10 , V_14 , sizeof( * V_117 ) , V_120 ) ;
if ( ! V_117 )
return - V_121 ;
V_116 = F_36 ( V_10 , sizeof( * V_116 ) , V_120 ) ;
if ( ! V_116 )
return - V_121 ;
V_116 -> V_123 = & V_124 ;
V_116 -> V_125 = & V_126 ;
V_116 -> V_127 = & V_128 ;
V_116 -> V_129 = V_130 ;
V_116 -> V_17 = F_40 ( V_10 ) ;
V_116 -> V_16 = V_114 ;
V_116 -> V_14 = V_14 ;
V_116 -> V_131 = F_10 ( V_132 ) ;
V_116 -> V_133 = V_132 ;
#ifdef F_41
V_116 -> V_134 = V_135 ;
#endif
for ( V_64 = 0 ; V_64 < V_14 ; V_64 ++ , V_114 ++ ) {
V_4 = & V_117 [ V_64 ] ;
V_114 -> V_25 = V_4 ;
V_114 -> V_19 = V_64 ;
V_114 -> V_17 = V_24 [ V_64 ] ;
V_4 -> V_92 = F_42 ( V_111 , V_64 ) ;
if ( V_4 -> V_92 < 0 )
return V_4 -> V_92 ;
V_4 -> V_9 = V_118 + V_64 * V_136 ;
V_7 = F_31 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_2 -> V_85 = V_137 ;
V_2 -> V_85 . V_122 = V_10 ;
V_2 -> V_85 . V_9 = - 1 ;
V_2 -> V_85 . V_93 = V_14 ;
V_2 -> V_85 . V_138 = F_40 ( V_10 ) ;
V_2 -> V_85 . V_91 = 2 ;
V_2 -> V_85 . V_139 = false ;
V_2 -> V_86 = F_43 ( V_116 , V_10 , V_2 ) ;
if ( F_44 ( V_2 -> V_86 ) )
return F_45 ( V_2 -> V_86 ) ;
V_7 = F_46 ( & V_2 -> V_85 , V_2 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_10 , L_31 ) ;
goto V_140;
}
V_7 = F_47 ( & V_2 -> V_85 , F_40 ( V_10 ) , 0 , 0 , V_14 ) ;
if ( V_7 ) {
F_3 ( V_10 , L_32 ) ;
goto V_141;
}
return 0 ;
V_141:
F_48 ( & V_2 -> V_85 ) ;
V_140:
F_49 ( V_2 -> V_86 ) ;
return V_7 ;
}
static int F_50 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_51 ( V_111 ) ;
F_48 ( & V_2 -> V_85 ) ;
F_49 ( V_2 -> V_86 ) ;
return 0 ;
}
