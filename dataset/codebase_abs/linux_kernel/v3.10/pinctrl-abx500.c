static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_4 ,
unsigned V_5 , bool * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_8 = V_5 % 8 ;
T_1 V_9 ;
int V_10 ;
V_4 += V_5 / 8 ;
V_10 = F_4 ( V_7 -> V_11 ,
V_12 , V_4 , & V_9 ) ;
* V_6 = ! ! ( V_9 & F_5 ( V_8 ) ) ;
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 ,
L_1 ,
V_13 , V_4 , V_5 ) ;
return V_10 ;
}
static int F_7 ( struct V_2 * V_3 , T_1 V_4 ,
unsigned V_5 , int V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_8 = V_5 % 8 ;
int V_10 ;
V_4 += V_5 / 8 ;
V_10 = F_8 ( V_7 -> V_11 ,
V_12 , V_4 , F_5 ( V_8 ) , V_9 << V_8 ) ;
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_2 , V_13 ) ;
return V_10 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_5 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
bool V_6 ;
int V_10 ;
V_10 = F_3 ( V_3 , V_14 ,
V_5 , & V_6 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 -> V_11 , L_3 , V_13 ) ;
return V_10 ;
}
return V_6 ;
}
static void F_10 ( struct V_2 * V_3 , unsigned V_5 , int V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_10 ;
V_10 = F_7 ( V_3 , V_15 , V_5 , V_9 ) ;
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_2 , V_13 ) ;
}
static int F_11 ( struct V_1 * V_7 ,
int V_5 , enum V_16 V_9 )
{
T_1 V_8 ;
int V_10 ;
struct V_17 * V_17 ;
if ( ! V_7 -> V_18 -> V_17 ) {
F_6 ( V_7 -> V_11 , L_4 ,
V_13 ) ;
V_10 = - V_19 ;
goto V_20;
}
V_17 = V_7 -> V_18 -> V_17 ;
if ( ( V_5 < V_17 -> V_21 )
|| ( V_5 > V_17 -> V_22 ) ) {
V_10 = - V_23 ;
goto V_20;
}
V_8 = V_5 << 1 ;
V_10 = F_8 ( V_7 -> V_11 ,
V_12 , V_24 ,
V_25 << V_8 , V_9 << V_8 ) ;
V_20:
if ( V_10 < 0 )
F_6 ( V_7 -> V_11 , L_5 , V_13 , V_10 ) ;
return V_10 ;
}
static int F_12 ( struct V_2 * V_3 ,
unsigned V_5 ,
int V_9 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_17 * V_17 = V_7 -> V_18 -> V_17 ;
unsigned V_26 ;
int V_10 ;
V_10 = F_7 ( V_3 , V_27 , V_5 , 1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_7 ( V_3 , V_28 , V_5 , 1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_26 = V_5 + 1 ;
if ( V_17 && V_26 >= V_17 -> V_21 && V_26 <= V_17 -> V_22 ) {
V_10 = F_11 ( V_7 ,
V_26 ,
V_29 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return F_7 ( V_3 , V_15 , V_5 , V_9 ) ;
}
static int F_13 ( struct V_2 * V_3 , unsigned V_5 )
{
return F_7 ( V_3 , V_27 , V_5 , 0 ) ;
}
static int F_14 ( struct V_2 * V_3 , unsigned V_5 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_26 = V_5 + 1 ;
int V_30 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_7 -> V_32 ; V_31 ++ ) {
struct V_33 * V_34 =
& V_7 -> V_35 [ V_31 ] ;
if ( V_26 >= V_34 -> V_36 && V_26 <= V_34 -> V_37 ) {
V_30 = V_26 - V_34 -> V_36 + V_34 -> V_38 ;
return F_15 ( V_7 -> V_39 -> V_40 , V_30 ) ;
}
}
return - V_23 ;
}
static int F_16 ( struct V_41 * V_42 , struct V_2 * V_3 ,
unsigned V_26 , int V_43 )
{
struct V_1 * V_7 = F_17 ( V_42 ) ;
struct V_44 V_45 = V_7 -> V_18 -> V_44 [ V_26 ] ;
int V_10 ;
int V_9 ;
unsigned V_5 ;
const char * V_46 [] = {
[ V_47 ] = L_6 ,
[ V_48 ] = L_7 ,
[ V_49 ] = L_8 ,
[ V_50 ] = L_9 ,
} ;
if ( ( ( V_43 == V_48 ) && ( V_45 . V_51 == V_52 ) ) ||
( ( V_43 == V_49 ) && ( V_45 . V_53 == V_52 ) ) ||
( ( V_43 == V_50 ) && ( V_45 . V_54 == V_52 ) ) ) {
F_18 ( V_7 -> V_11 , L_10 , V_26 ,
V_46 [ V_43 ] ) ;
return - V_23 ;
}
V_5 = V_26 - 1 ;
switch ( V_43 ) {
case V_47 :
V_9 = 0 ;
if ( V_45 . V_53 != V_52 )
V_9 ++ ;
V_10 = F_7 ( V_3 , V_55 ,
V_5 , V_9 ) ;
break;
case V_48 :
if ( V_45 . V_53 != V_52 ) {
V_10 = F_7 ( V_3 , V_55 ,
V_5 , 0 ) ;
V_10 = F_7 ( V_3 ,
V_56 ,
V_45 . V_53 ,
! ! ( V_45 . V_57 && F_5 ( 0 ) ) ) ;
if ( V_45 . V_54 != V_52 )
V_10 = F_7 ( V_3 ,
V_56 ,
V_45 . V_54 ,
! ! ( V_45 . V_57 && F_5 ( 1 ) ) ) ;
} else
V_10 = F_7 ( V_3 , V_55 ,
V_5 , 1 ) ;
break;
case V_49 :
V_10 = F_7 ( V_3 , V_55 ,
V_5 , 0 ) ;
V_10 = F_7 ( V_3 , V_56 ,
V_45 . V_53 , ! ! ( V_45 . V_58 && F_5 ( 0 ) ) ) ;
if ( V_45 . V_54 != V_52 )
V_10 = F_7 ( V_3 ,
V_56 ,
V_45 . V_54 ,
! ! ( V_45 . V_58 && F_5 ( 1 ) ) ) ;
break;
case V_50 :
V_10 = F_7 ( V_3 , V_55 ,
V_5 , 0 ) ;
V_10 = F_7 ( V_3 , V_56 ,
V_45 . V_54 , ! ! ( V_45 . V_59 && F_5 ( 0 ) ) ) ;
V_10 = F_7 ( V_3 , V_56 ,
V_45 . V_54 , ! ! ( V_45 . V_59 && F_5 ( 1 ) ) ) ;
break;
default:
F_18 ( V_7 -> V_11 , L_11 , V_43 ) ;
return - V_23 ;
}
return V_10 ;
}
static T_1 F_19 ( struct V_41 * V_42 , struct V_2 * V_3 ,
unsigned V_26 )
{
T_1 V_60 ;
bool V_61 ;
bool V_53 ;
bool V_54 ;
struct V_1 * V_7 = F_17 ( V_42 ) ;
struct V_44 V_45 = V_7 -> V_18 -> V_44 [ V_26 ] ;
unsigned V_5 = V_26 - 1 ;
if ( V_45 . V_51 == V_52 )
return V_47 ;
F_3 ( V_3 , V_55 + ( V_5 / 8 ) ,
V_45 . V_51 , & V_61 ) ;
V_60 = V_61 ;
if ( ( V_45 . V_53 < V_52 ) || ( V_45 . V_53 > 7 ) ||
( V_45 . V_54 < V_52 ) || ( V_45 . V_54 > 7 ) ) {
F_6 ( V_7 -> V_11 ,
L_12 ) ;
return - V_23 ;
}
if ( ( V_45 . V_54 != V_52 ) && ( V_45 . V_53 == V_52 ) ) {
F_6 ( V_7 -> V_11 ,
L_13 ) ;
return - V_23 ;
}
if ( ( V_45 . V_53 == V_52 ) && ( V_45 . V_54 == V_52 ) )
return V_60 ;
if ( V_60 )
return V_47 ;
F_3 ( V_3 , V_56 ,
V_45 . V_53 , & V_53 ) ;
if ( V_45 . V_54 != V_52 )
F_3 ( V_3 , V_56 , V_45 . V_54 ,
& V_54 ) ;
else
V_54 = 0 ;
V_60 = ( V_54 << 1 ) + V_53 ;
if ( V_60 == V_45 . V_57 )
return V_48 ;
else if ( V_60 == V_45 . V_58 )
return V_49 ;
else
return V_50 ;
}
static void F_20 ( struct V_62 * V_63 ,
struct V_41 * V_42 ,
struct V_2 * V_3 ,
unsigned V_5 , unsigned V_26 )
{
const char * V_64 = F_21 ( V_3 , V_5 - 1 ) ;
T_1 V_65 = V_5 - 1 ;
int V_60 = - 1 ;
bool V_66 ;
bool V_67 ;
const char * V_46 [] = {
[ V_47 ] = L_6 ,
[ V_48 ] = L_7 ,
[ V_49 ] = L_8 ,
[ V_50 ] = L_9 ,
} ;
F_3 ( V_3 , V_27 , V_65 , & V_66 ) ;
F_3 ( V_3 , V_28 , V_65 , & V_67 ) ;
if ( V_42 )
V_60 = F_19 ( V_42 , V_3 , V_5 ) ;
F_22 ( V_63 , L_14 ,
V_26 , V_64 ? : L_15 ,
V_66 ? L_16 : L_17 ,
V_66 ?
( V_3 -> V_68
? ( V_3 -> V_68 ( V_3 , V_5 ) ? L_18 : L_19 )
: L_20 )
: ( V_67 ? L_21 : L_22 ) ,
( V_60 < 0 ) ? L_23 : V_46 [ V_60 ] ) ;
}
static void F_23 ( struct V_62 * V_63 , struct V_2 * V_3 )
{
unsigned V_31 ;
unsigned V_26 = V_3 -> V_69 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_41 * V_42 = V_7 -> V_42 ;
for ( V_31 = 0 ; V_31 < V_3 -> V_70 ; V_31 ++ , V_26 ++ ) {
F_20 ( V_63 , V_42 , V_3 , V_31 + 1 , V_26 ) ;
F_22 ( V_63 , L_24 ) ;
}
}
static inline void F_20 ( struct V_62 * V_63 ,
struct V_41 * V_42 ,
struct V_2 * V_3 ,
unsigned V_5 , unsigned V_26 )
{
}
static int F_24 ( struct V_2 * V_3 , unsigned V_5 )
{
int V_26 = V_3 -> V_69 + V_5 ;
return F_25 ( V_26 ) ;
}
static void F_26 ( struct V_2 * V_3 , unsigned V_5 )
{
int V_26 = V_3 -> V_69 + V_5 ;
F_27 ( V_26 ) ;
}
static int F_28 ( struct V_41 * V_42 )
{
struct V_1 * V_7 = F_17 ( V_42 ) ;
return V_7 -> V_18 -> V_71 ;
}
static const char * F_29 ( struct V_41 * V_42 ,
unsigned V_72 )
{
struct V_1 * V_7 = F_17 ( V_42 ) ;
return V_7 -> V_18 -> V_73 [ V_72 ] . V_74 ;
}
static int F_30 ( struct V_41 * V_42 ,
unsigned V_72 ,
const char * const * * V_75 ,
unsigned * const V_76 )
{
struct V_1 * V_7 = F_17 ( V_42 ) ;
* V_75 = V_7 -> V_18 -> V_73 [ V_72 ] . V_75 ;
* V_76 = V_7 -> V_18 -> V_73 [ V_72 ] . V_77 ;
return 0 ;
}
static int F_31 ( struct V_41 * V_42 , unsigned V_72 ,
unsigned V_78 )
{
struct V_1 * V_7 = F_17 ( V_42 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
const struct V_79 * V_80 ;
int V_31 ;
int V_10 = 0 ;
V_80 = & V_7 -> V_18 -> V_75 [ V_78 ] ;
if ( V_80 -> V_81 < 0 )
return - V_23 ;
F_18 ( V_7 -> V_11 , L_25 , V_80 -> V_74 , V_80 -> V_82 ) ;
for ( V_31 = 0 ; V_31 < V_80 -> V_82 ; V_31 ++ ) {
F_18 ( V_7 -> V_11 , L_26 ,
V_80 -> V_83 [ V_31 ] , V_80 -> V_81 ) ;
V_10 = F_16 ( V_42 , V_3 , V_80 -> V_83 [ V_31 ] , V_80 -> V_81 ) ;
}
return V_10 ;
}
static void F_32 ( struct V_41 * V_42 ,
unsigned V_72 , unsigned V_78 )
{
struct V_1 * V_7 = F_17 ( V_42 ) ;
const struct V_79 * V_80 ;
V_80 = & V_7 -> V_18 -> V_75 [ V_78 ] ;
if ( V_80 -> V_81 < 0 )
return;
F_18 ( V_7 -> V_11 , L_27 , V_80 -> V_74 , V_80 -> V_82 ) ;
}
static int F_33 ( struct V_41 * V_42 ,
struct V_84 * V_85 ,
unsigned V_5 )
{
struct V_1 * V_7 = F_17 ( V_42 ) ;
const struct V_86 * V_87 ;
int V_10 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_7 -> V_18 -> V_88 ; V_31 ++ ) {
V_87 = & V_7 -> V_18 -> V_89 [ V_31 ] ;
if ( ( V_5 >= V_87 -> V_5 ) &&
( V_5 < ( V_87 -> V_5 + V_87 -> V_82 ) ) )
break;
}
if ( V_31 == V_7 -> V_18 -> V_88 ) {
F_6 ( V_7 -> V_11 , L_28 , V_13 ) ;
return - V_90 ;
}
F_18 ( V_7 -> V_11 , L_29 ,
V_87 -> V_91 , V_5 ) ;
V_10 = F_16 ( V_7 -> V_42 , & V_7 -> V_3 ,
V_5 , V_87 -> V_91 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 -> V_11 , L_30 , V_13 ) ;
return V_10 ;
}
return V_10 ;
}
static void F_34 ( struct V_41 * V_42 ,
struct V_84 * V_85 ,
unsigned V_5 )
{
}
static int F_35 ( struct V_41 * V_42 )
{
struct V_1 * V_7 = F_17 ( V_42 ) ;
return V_7 -> V_18 -> V_77 ;
}
static const char * F_36 ( struct V_41 * V_42 ,
unsigned V_92 )
{
struct V_1 * V_7 = F_17 ( V_42 ) ;
return V_7 -> V_18 -> V_75 [ V_92 ] . V_74 ;
}
static int F_37 ( struct V_41 * V_42 ,
unsigned V_92 ,
const unsigned * * V_83 ,
unsigned * V_93 )
{
struct V_1 * V_7 = F_17 ( V_42 ) ;
* V_83 = V_7 -> V_18 -> V_75 [ V_92 ] . V_83 ;
* V_93 = V_7 -> V_18 -> V_75 [ V_92 ] . V_82 ;
return 0 ;
}
static void F_38 ( struct V_41 * V_42 ,
struct V_62 * V_63 , unsigned V_5 )
{
struct V_1 * V_7 = F_17 ( V_42 ) ;
struct V_2 * V_3 = & V_7 -> V_3 ;
F_20 ( V_63 , V_42 , V_3 , V_5 ,
V_3 -> V_69 + V_5 - 1 ) ;
}
static int F_39 ( struct V_41 * V_42 ,
unsigned V_94 ,
unsigned long * V_95 )
{
return - V_96 ;
}
static int F_40 ( struct V_41 * V_42 ,
unsigned V_94 ,
unsigned long V_95 )
{
struct V_1 * V_7 = F_17 ( V_42 ) ;
struct V_17 * V_17 = V_7 -> V_18 -> V_17 ;
struct V_2 * V_3 = & V_7 -> V_3 ;
unsigned V_5 ;
int V_10 ;
enum V_97 V_98 = F_41 ( V_95 ) ;
enum V_97 V_99 = F_42 ( V_95 ) ;
F_18 ( V_3 -> V_11 , L_31 ,
V_94 , V_95 , ( V_98 == V_100 ) ? L_32 : L_33 ,
( V_98 == V_100 ) ? ( V_99 ? L_34 : L_35 ) :
( V_99 ? L_21 : L_22 ) ) ;
V_5 = V_94 - 1 ;
switch ( V_98 ) {
case V_101 :
V_10 = F_13 ( V_3 , V_5 ) ;
if ( V_17 &&
V_94 >= V_17 -> V_21 &&
V_94 <= V_17 -> V_22 )
V_10 = F_11 ( V_7 ,
V_94 ,
V_99 ? V_102 : V_29 ) ;
else
V_10 = F_7 ( V_3 , V_28 ,
V_5 , V_99 ? 0 : 1 ) ;
break;
case V_100 :
V_10 = F_12 ( V_3 , V_5 , V_99 ) ;
break;
default:
F_6 ( V_3 -> V_11 , L_36 ) ;
return - V_23 ;
}
return V_10 ;
}
static int F_43 ( struct V_103 * V_18 )
{
unsigned int V_104 = 0 ;
unsigned int V_105 = 0 ;
unsigned int V_82 = 0 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_18 -> V_88 ; V_31 ++ ) {
unsigned V_106 ;
unsigned V_107 ;
const struct V_86 * V_87 ;
V_87 = & V_18 -> V_89 [ V_31 ] ;
V_106 = V_87 -> V_5 ;
V_107 = V_87 -> V_5 + V_87 -> V_82 - 1 ;
if ( V_31 == 0 ) {
V_104 = V_106 ;
V_105 = V_107 ;
} else {
if ( V_106 < V_104 )
V_104 = V_106 ;
if ( V_107 > V_105 )
V_105 = V_107 ;
}
}
V_82 = V_105 - V_104 + 1 ;
return V_82 ;
}
static int F_44 ( struct V_108 * V_109 )
{
struct V_110 * V_111 =
F_45 ( V_109 -> V_11 . V_39 ) ;
struct V_112 * V_113 = NULL ;
struct V_114 * V_115 = V_109 -> V_11 . V_116 ;
struct V_1 * V_7 ;
const struct V_117 * V_118 = F_46 ( V_109 ) ;
unsigned int V_119 = - 1 ;
int V_10 , V_120 ;
int V_31 ;
if ( V_111 )
V_113 = V_111 -> V_26 ;
if ( ! ( V_113 || V_115 ) ) {
F_6 ( & V_109 -> V_11 , L_37 ) ;
return - V_90 ;
}
V_7 = F_47 ( & V_109 -> V_11 , sizeof( struct V_1 ) ,
V_121 ) ;
if ( V_7 == NULL ) {
F_6 ( & V_109 -> V_11 ,
L_38 ) ;
return - V_122 ;
}
V_7 -> V_11 = & V_109 -> V_11 ;
V_7 -> V_39 = F_48 ( V_109 -> V_11 . V_39 ) ;
V_7 -> V_3 = V_123 ;
V_7 -> V_3 . V_11 = & V_109 -> V_11 ;
V_7 -> V_3 . V_69 = ( V_115 ) ? - 1 : V_113 -> V_124 ;
if ( V_118 )
V_119 = V_118 -> V_125 ;
else if ( V_115 ) {
const struct V_126 * V_127 ;
V_127 = F_49 ( V_128 , & V_109 -> V_11 ) ;
if ( V_127 )
V_119 = ( unsigned long ) V_127 -> V_129 ;
}
F_50 ( & V_7 -> V_130 ) ;
switch ( V_119 ) {
case V_131 :
F_51 ( & V_7 -> V_18 ) ;
break;
case V_132 :
F_52 ( & V_7 -> V_18 ) ;
break;
case V_133 :
F_53 ( & V_7 -> V_18 ) ;
break;
case V_134 :
F_54 ( & V_7 -> V_18 ) ;
break;
default:
F_6 ( & V_109 -> V_11 , L_39 , V_119 ) ;
F_55 ( & V_7 -> V_130 ) ;
return - V_23 ;
}
if ( ! V_7 -> V_18 ) {
F_6 ( & V_109 -> V_11 , L_40 ) ;
F_55 ( & V_7 -> V_130 ) ;
return - V_23 ;
}
V_7 -> V_3 . V_70 = F_43 ( V_7 -> V_18 ) ;
V_7 -> V_35 = V_7 -> V_18 -> V_135 ;
V_7 -> V_32 = V_7 -> V_18 -> V_136 ;
V_10 = F_56 ( & V_7 -> V_3 ) ;
if ( V_10 ) {
F_6 ( & V_109 -> V_11 , L_41 , V_10 ) ;
F_55 ( & V_7 -> V_130 ) ;
return V_10 ;
}
F_57 ( & V_109 -> V_11 , L_42 ) ;
V_137 . V_83 = V_7 -> V_18 -> V_83 ;
V_137 . V_82 = V_7 -> V_18 -> V_82 ;
V_7 -> V_42 = F_58 ( & V_137 , & V_109 -> V_11 , V_7 ) ;
if ( ! V_7 -> V_42 ) {
F_6 ( & V_109 -> V_11 ,
L_43 ) ;
V_10 = - V_23 ;
goto V_138;
}
F_57 ( & V_109 -> V_11 , L_44 ) ;
for ( V_31 = 0 ; V_31 < V_7 -> V_18 -> V_88 ; V_31 ++ ) {
const struct V_86 * V_87 = & V_7 -> V_18 -> V_89 [ V_31 ] ;
V_10 = F_59 ( & V_7 -> V_3 ,
F_60 ( & V_109 -> V_11 ) ,
V_87 -> V_5 - 1 , V_87 -> V_5 , V_87 -> V_82 ) ;
if ( V_10 < 0 )
goto V_138;
}
F_61 ( V_109 , V_7 ) ;
F_57 ( & V_109 -> V_11 , L_45 ) ;
return 0 ;
V_138:
V_120 = F_62 ( & V_7 -> V_3 ) ;
if ( V_120 )
F_57 ( & V_109 -> V_11 , L_46 ) ;
F_55 ( & V_7 -> V_130 ) ;
return V_10 ;
}
static int F_63 ( struct V_108 * V_109 )
{
struct V_1 * V_7 = F_64 ( V_109 ) ;
int V_10 ;
V_10 = F_62 ( & V_7 -> V_3 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 -> V_11 , L_47 ,
V_10 ) ;
return V_10 ;
}
F_55 ( & V_7 -> V_130 ) ;
return 0 ;
}
static int T_2 F_65 ( void )
{
return F_66 ( & V_139 ) ;
}
