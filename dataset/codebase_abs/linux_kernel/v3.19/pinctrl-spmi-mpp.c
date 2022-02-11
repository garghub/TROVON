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
struct V_22 * V_23 ;
enum V_36 type ;
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
if ( ! V_6 -> V_47 ) {
V_8 = 0 ;
if ( V_6 -> V_48 ) {
if ( V_6 -> V_49 )
V_8 = 2 ;
else
V_8 = 1 ;
}
} else {
V_8 = 4 ;
if ( V_6 -> V_48 ) {
if ( V_6 -> V_49 )
V_8 = 3 ;
else
V_8 = 5 ;
}
}
V_8 |= V_6 -> V_42 << V_50 ;
V_8 |= V_6 -> V_51 & V_52 ;
V_9 = F_6 ( V_4 , V_6 , V_53 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_6 -> V_54 << V_55 ;
return F_6 ( V_4 , V_6 , V_56 , V_8 ) ;
}
static int F_32 ( struct V_13 * V_14 ,
unsigned int V_17 , unsigned long * V_57 )
{
unsigned V_32 = F_33 ( * V_57 ) ;
struct V_5 * V_6 ;
unsigned V_58 = 0 ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_46 ;
switch ( V_32 ) {
case V_59 :
V_58 = V_6 -> V_60 == V_61 ;
break;
case V_62 :
switch ( V_6 -> V_60 ) {
case V_61 :
V_58 = 0 ;
break;
case V_63 :
V_58 = 600 ;
break;
case V_64 :
V_58 = 10000 ;
break;
case V_65 :
V_58 = 30000 ;
break;
default:
return - V_31 ;
}
break;
case V_66 :
V_58 = ! V_6 -> V_54 ;
break;
case V_67 :
V_58 = V_6 -> V_68 ;
break;
case V_69 :
V_58 = V_6 -> V_49 ;
break;
case V_70 :
V_58 = V_6 -> V_51 ;
break;
case V_71 :
V_58 = V_6 -> V_72 ;
break;
case V_73 :
V_58 = V_6 -> V_47 ;
break;
default:
return - V_31 ;
}
* V_57 = F_15 ( V_32 , V_58 ) ;
return 0 ;
}
static int F_34 ( struct V_13 * V_14 , unsigned int V_17 ,
unsigned long * V_24 , unsigned V_25 )
{
struct V_1 * V_4 = F_31 ( V_14 ) ;
struct V_5 * V_6 ;
unsigned V_32 , V_58 ;
unsigned int V_8 ;
int V_29 , V_9 ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_46 ;
for ( V_29 = 0 ; V_29 < V_25 ; V_29 ++ ) {
V_32 = F_33 ( V_24 [ V_29 ] ) ;
V_58 = F_35 ( V_24 [ V_29 ] ) ;
switch ( V_32 ) {
case V_59 :
V_6 -> V_60 = V_61 ;
break;
case V_62 :
switch ( V_58 ) {
case 600 :
V_6 -> V_60 = V_63 ;
break;
case 10000 :
V_6 -> V_60 = V_64 ;
break;
case 30000 :
V_6 -> V_60 = V_65 ;
break;
default:
return - V_31 ;
}
break;
case V_66 :
V_6 -> V_54 = false ;
break;
case V_67 :
if ( V_58 >= V_6 -> V_74 )
return - V_31 ;
V_6 -> V_68 = V_58 ;
break;
case V_69 :
V_6 -> V_49 = V_58 ? true : false ;
break;
case V_70 :
V_6 -> V_48 = true ;
V_6 -> V_51 = V_58 ;
break;
case V_71 :
if ( V_58 >= V_75 )
return - V_31 ;
V_6 -> V_72 = V_58 ;
break;
case V_73 :
V_6 -> V_47 = true ;
break;
default:
return - V_31 ;
}
}
V_8 = V_6 -> V_68 << V_76 ;
V_9 = F_6 ( V_4 , V_6 , V_77 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_6 -> V_60 << V_78 ;
V_9 = F_6 ( V_4 , V_6 , V_79 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_6 -> V_72 & V_80 ;
V_9 = F_6 ( V_4 , V_6 , V_81 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_6 -> V_47 ) {
V_8 = 0 ;
if ( V_6 -> V_48 ) {
if ( V_6 -> V_49 )
V_8 = 2 ;
else
V_8 = 1 ;
}
} else {
V_8 = 4 ;
if ( V_6 -> V_48 ) {
if ( V_6 -> V_49 )
V_8 = 3 ;
else
V_8 = 5 ;
}
}
V_8 = V_8 << V_82 ;
V_8 |= V_6 -> V_42 << V_50 ;
V_8 |= V_6 -> V_51 & V_52 ;
return F_6 ( V_4 , V_6 , V_53 , V_8 ) ;
}
static void F_36 ( struct V_13 * V_14 ,
struct V_83 * V_84 , unsigned V_17 )
{
struct V_1 * V_4 = F_31 ( V_14 ) ;
struct V_5 * V_6 ;
int V_9 , V_8 ;
static const char * const V_85 [] = {
L_5 , L_6 , L_7 , L_8
} ;
V_6 = V_14 -> V_15 -> V_18 [ V_17 ] . V_46 ;
F_37 ( V_84 , L_9 , V_17 + V_86 ) ;
V_8 = F_3 ( V_4 , V_6 , V_56 ) ;
if ( V_8 < 0 || ! ( V_8 >> V_55 ) ) {
F_38 ( V_84 , L_10 ) ;
} else {
if ( V_6 -> V_49 ) {
V_9 = F_3 ( V_4 , V_6 , V_87 ) ;
if ( ! V_9 ) {
V_9 &= V_88 ;
V_6 -> V_51 = V_9 ;
}
}
F_37 ( V_84 , L_11 , V_6 -> V_48 ? L_12 : L_13 ) ;
F_37 ( V_84 , L_11 , V_6 -> V_47 ? L_14 : L_15 ) ;
F_37 ( V_84 , L_16 , V_41 [ V_6 -> V_42 ] ) ;
F_37 ( V_84 , L_17 , V_6 -> V_68 ) ;
F_37 ( V_84 , L_18 , V_85 [ V_6 -> V_60 ] ) ;
F_37 ( V_84 , L_11 , V_6 -> V_51 ? L_19 : L_20 ) ;
}
}
static int F_39 ( struct V_2 * V_3 , unsigned V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_57 ;
V_57 = F_15 ( V_69 , 1 ) ;
return F_34 ( V_4 -> V_89 , V_17 , & V_57 , 1 ) ;
}
static int F_40 ( struct V_2 * V_3 ,
unsigned V_17 , int V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_57 ;
V_57 = F_15 ( V_70 , V_8 ) ;
return F_34 ( V_4 -> V_89 , V_17 , & V_57 , 1 ) ;
}
static int F_41 ( struct V_2 * V_3 , unsigned V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 ;
int V_9 ;
V_6 = V_4 -> V_89 -> V_15 -> V_18 [ V_17 ] . V_46 ;
if ( V_6 -> V_49 ) {
V_9 = F_3 ( V_4 , V_6 , V_87 ) ;
if ( V_9 < 0 )
return V_9 ;
V_6 -> V_51 = V_9 & V_88 ;
}
return V_6 -> V_51 ;
}
static void F_42 ( struct V_2 * V_3 , unsigned V_17 , int V_90 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_57 ;
V_57 = F_15 ( V_70 , V_90 ) ;
F_34 ( V_4 -> V_89 , V_17 , & V_57 , 1 ) ;
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
const struct V_91 * V_92 ,
T_1 * V_93 )
{
if ( V_3 -> V_94 < 2 )
return - V_31 ;
if ( V_93 )
* V_93 = V_92 -> args [ 1 ] ;
return V_92 -> args [ 0 ] - V_86 ;
}
static int F_48 ( struct V_2 * V_3 , unsigned V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 ;
V_6 = V_4 -> V_89 -> V_15 -> V_18 [ V_17 ] . V_46 ;
return V_6 -> V_95 ;
}
static void F_49 ( struct V_83 * V_84 , struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned V_29 ;
for ( V_29 = 0 ; V_29 < V_3 -> V_96 ; V_29 ++ ) {
F_36 ( V_4 -> V_89 , V_84 , V_29 ) ;
F_38 ( V_84 , L_21 ) ;
}
}
static int F_50 ( struct V_1 * V_4 ,
struct V_5 * V_6 )
{
int type , V_97 , V_8 , V_98 ;
type = F_3 ( V_4 , V_6 , V_99 ) ;
if ( type < 0 )
return type ;
if ( type != V_100 ) {
F_5 ( V_4 -> V_12 , L_22 ,
type , V_6 -> V_11 ) ;
return - V_101 ;
}
V_97 = F_3 ( V_4 , V_6 , V_102 ) ;
if ( V_97 < 0 )
return V_97 ;
switch ( V_97 ) {
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
V_6 -> V_74 = 4 ;
break;
case V_108 :
V_6 -> V_74 = 8 ;
break;
default:
F_5 ( V_4 -> V_12 , L_23 ,
V_97 , V_6 -> V_11 ) ;
return - V_101 ;
}
V_8 = F_3 ( V_4 , V_6 , V_53 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_51 = V_8 & V_52 ;
V_98 = V_8 >> V_82 ;
V_98 &= V_109 ;
switch ( V_98 ) {
case 0 :
V_6 -> V_49 = true ;
V_6 -> V_48 = false ;
V_6 -> V_47 = false ;
break;
case 1 :
V_6 -> V_49 = false ;
V_6 -> V_48 = true ;
V_6 -> V_47 = false ;
break;
case 2 :
V_6 -> V_49 = true ;
V_6 -> V_48 = true ;
V_6 -> V_47 = false ;
break;
case 3 :
V_6 -> V_49 = true ;
V_6 -> V_48 = true ;
V_6 -> V_47 = true ;
break;
case 4 :
V_6 -> V_49 = true ;
V_6 -> V_48 = false ;
V_6 -> V_47 = true ;
break;
case 5 :
V_6 -> V_49 = false ;
V_6 -> V_48 = true ;
V_6 -> V_47 = true ;
break;
default:
F_5 ( V_4 -> V_12 , L_24 ) ;
return - V_101 ;
}
V_6 -> V_42 = V_8 >> V_50 ;
V_6 -> V_42 &= V_110 ;
V_8 = F_3 ( V_4 , V_6 , V_77 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_68 = V_8 >> V_76 ;
V_6 -> V_68 &= V_111 ;
V_8 = F_3 ( V_4 , V_6 , V_79 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_60 = V_8 >> V_78 ;
V_6 -> V_60 &= V_112 ;
V_8 = F_3 ( V_4 , V_6 , V_81 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_72 = V_8 >> V_113 ;
V_6 -> V_72 &= V_80 ;
V_6 -> V_54 = true ;
return 0 ;
}
static int F_51 ( struct V_114 * V_115 )
{
struct V_116 * V_12 = & V_115 -> V_12 ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
struct V_5 * V_6 , * V_121 ;
struct V_1 * V_4 ;
int V_9 , V_16 , V_29 ;
T_1 V_122 [ 2 ] ;
V_9 = F_52 ( V_12 -> V_123 , L_25 , V_122 , 2 ) ;
if ( V_9 < 0 ) {
F_5 ( V_12 , L_26 ) ;
return V_9 ;
}
V_16 = V_122 [ 1 ] / V_124 ;
if ( ! V_16 )
return - V_31 ;
F_53 ( V_16 > F_12 ( V_45 ) ) ;
V_4 = F_54 ( V_12 , sizeof( * V_4 ) , V_125 ) ;
if ( ! V_4 )
return - V_126 ;
F_55 ( V_115 , V_4 ) ;
V_4 -> V_12 = & V_115 -> V_12 ;
V_4 -> V_10 = F_56 ( V_12 -> V_127 , NULL ) ;
V_118 = F_57 ( V_12 , V_16 , sizeof( * V_118 ) , V_125 ) ;
if ( ! V_118 )
return - V_126 ;
V_121 = F_57 ( V_12 , V_16 , sizeof( * V_121 ) , V_125 ) ;
if ( ! V_121 )
return - V_126 ;
V_120 = F_54 ( V_12 , sizeof( * V_120 ) , V_125 ) ;
if ( ! V_120 )
return - V_126 ;
V_120 -> V_128 = & V_129 ;
V_120 -> V_130 = & V_131 ;
V_120 -> V_132 = & V_133 ;
V_120 -> V_134 = V_135 ;
V_120 -> V_19 = F_58 ( V_12 ) ;
V_120 -> V_18 = V_118 ;
V_120 -> V_16 = V_16 ;
for ( V_29 = 0 ; V_29 < V_16 ; V_29 ++ , V_118 ++ ) {
V_6 = & V_121 [ V_29 ] ;
V_118 -> V_46 = V_6 ;
V_118 -> V_21 = V_29 ;
V_118 -> V_19 = V_45 [ V_29 ] ;
V_6 -> V_95 = F_59 ( V_115 , V_29 ) ;
if ( V_6 -> V_95 < 0 )
return V_6 -> V_95 ;
V_6 -> V_11 = V_122 [ 0 ] + V_29 * V_124 ;
V_9 = F_50 ( V_4 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
}
V_4 -> V_3 = V_136 ;
V_4 -> V_3 . V_12 = V_12 ;
V_4 -> V_3 . V_11 = - 1 ;
V_4 -> V_3 . V_96 = V_16 ;
V_4 -> V_3 . V_137 = F_58 ( V_12 ) ;
V_4 -> V_3 . V_94 = 2 ;
V_4 -> V_3 . V_138 = false ;
V_4 -> V_89 = F_60 ( V_120 , V_12 , V_4 ) ;
if ( ! V_4 -> V_89 )
return - V_101 ;
V_9 = F_61 ( & V_4 -> V_3 ) ;
if ( V_9 ) {
F_5 ( V_4 -> V_12 , L_27 ) ;
goto V_139;
}
V_9 = F_62 ( & V_4 -> V_3 , F_58 ( V_12 ) , 0 , 0 , V_16 ) ;
if ( V_9 ) {
F_5 ( V_12 , L_28 ) ;
goto V_140;
}
return 0 ;
V_140:
F_63 ( & V_4 -> V_3 ) ;
V_139:
F_64 ( V_4 -> V_89 ) ;
return V_9 ;
}
static int F_65 ( struct V_114 * V_115 )
{
struct V_1 * V_4 = F_66 ( V_115 ) ;
F_63 ( & V_4 -> V_3 ) ;
F_64 ( V_4 -> V_89 ) ;
return 0 ;
}
