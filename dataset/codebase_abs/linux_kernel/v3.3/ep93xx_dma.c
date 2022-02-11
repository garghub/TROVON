static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 . V_5 -> V_1 ;
}
static struct V_2 * F_2 ( struct V_6 * V_4 )
{
return F_3 ( V_4 , struct V_2 , V_4 ) ;
}
static void F_4 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
F_5 ( ! F_6 ( & V_3 -> V_9 ) ) ;
F_7 ( & V_8 -> V_10 , & V_3 -> V_9 ) ;
while ( ! F_6 ( & V_8 -> V_11 ) ) {
struct V_7 * V_12 = F_8 ( & V_8 -> V_11 ,
struct V_7 , V_10 ) ;
V_12 -> V_13 . V_14 = V_8 -> V_13 . V_14 ;
V_12 -> V_13 . V_15 = V_8 -> V_13 . V_15 ;
F_9 ( & V_12 -> V_10 , & V_3 -> V_9 ) ;
}
}
static struct V_7 *
F_10 ( struct V_2 * V_3 )
{
if ( F_6 ( & V_3 -> V_9 ) )
return NULL ;
return F_8 ( & V_3 -> V_9 , struct V_7 , V_10 ) ;
}
static bool F_11 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
F_12 ( & V_3 -> V_9 ) ;
if ( F_13 ( V_16 , & V_3 -> V_17 ) )
return true ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 )
return false ;
return ! V_8 -> V_13 . V_18 ;
}
static void F_14 ( struct V_2 * V_3 , T_1 V_19 )
{
F_15 ( V_19 , V_3 -> V_20 + V_21 ) ;
F_16 ( V_3 -> V_20 + V_21 ) ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_4 . V_24 ;
T_1 V_19 ;
F_15 ( V_23 -> V_25 & 0xf , V_3 -> V_20 + V_26 ) ;
V_19 = V_27 | V_28
| V_29 ;
F_14 ( V_3 , V_19 ) ;
return 0 ;
}
static inline T_1 F_18 ( struct V_2 * V_3 )
{
return ( F_16 ( V_3 -> V_20 + V_30 ) >> 4 ) & 0x3 ;
}
static void F_19 ( struct V_2 * V_3 )
{
T_1 V_19 ;
V_19 = F_16 ( V_3 -> V_20 + V_21 ) ;
V_19 &= ~ ( V_31 | V_32 ) ;
F_14 ( V_3 , V_19 ) ;
while ( F_18 ( V_3 ) >= V_33 )
F_20 () ;
F_14 ( V_3 , 0 ) ;
while ( F_18 ( V_3 ) == V_34 )
F_20 () ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
T_1 V_35 ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_1 ) ;
return;
}
if ( F_23 ( & V_3 -> V_4 ) == V_36 )
V_35 = V_8 -> V_37 ;
else
V_35 = V_8 -> V_38 ;
if ( V_3 -> V_39 == 0 ) {
F_15 ( V_8 -> V_40 , V_3 -> V_20 + V_41 ) ;
F_15 ( V_35 , V_3 -> V_20 + V_42 ) ;
} else {
F_15 ( V_8 -> V_40 , V_3 -> V_20 + V_43 ) ;
F_15 ( V_35 , V_3 -> V_20 + V_44 ) ;
}
V_3 -> V_39 ^= 1 ;
}
static void F_24 ( struct V_2 * V_3 )
{
T_1 V_19 = F_16 ( V_3 -> V_20 + V_21 ) ;
F_21 ( V_3 ) ;
V_19 |= V_31 ;
if ( F_11 ( V_3 ) ) {
F_21 ( V_3 ) ;
V_19 |= V_32 ;
}
F_14 ( V_3 , V_19 ) ;
}
static int F_25 ( struct V_2 * V_3 )
{
T_1 V_45 = F_16 ( V_3 -> V_20 + V_46 ) ;
T_1 V_19 ;
if ( V_45 & V_47 ) {
struct V_7 * V_8 = F_10 ( V_3 ) ;
F_15 ( 1 , V_3 -> V_20 + V_46 ) ;
F_26 ( F_1 ( V_3 ) ,
L_2
L_3
L_4
L_5
L_6 ,
V_8 -> V_13 . V_18 , V_8 -> V_37 , V_8 -> V_38 ,
V_8 -> V_40 ) ;
}
switch ( V_45 & ( V_48 | V_49 ) ) {
case V_48 :
V_19 = F_16 ( V_3 -> V_20 + V_21 ) ;
V_19 &= ~ ( V_31 | V_32 ) ;
F_14 ( V_3 , V_19 ) ;
return V_50 ;
case V_49 :
if ( F_11 ( V_3 ) )
F_21 ( V_3 ) ;
return V_51 ;
}
return V_52 ;
}
static int F_27 ( struct V_2 * V_3 )
{
const struct V_22 * V_23 = V_3 -> V_4 . V_24 ;
T_1 V_19 = 0 ;
if ( ! V_23 ) {
F_15 ( V_19 , V_3 -> V_20 + V_53 ) ;
return 0 ;
}
switch ( V_23 -> V_25 ) {
case V_54 :
V_19 = ( 5 << V_55 ) ;
V_19 |= V_56 ;
if ( V_23 -> V_57 == V_36 ) {
V_19 |= V_58 ;
V_19 |= V_59 ;
V_19 |= V_60 ;
} else {
V_19 |= V_61 ;
V_19 |= V_62 ;
V_19 |= V_63 ;
}
break;
case V_64 :
if ( V_23 -> V_57 == V_36 ) {
V_19 = ( 3 << V_55 ) ;
V_19 |= V_58 ;
V_19 |= V_59 ;
} else {
V_19 = ( 2 << V_55 ) ;
V_19 |= V_61 ;
V_19 |= V_62 ;
}
V_19 |= V_56 ;
V_19 |= V_65 ;
V_19 |= V_66 ;
break;
default:
return - V_67 ;
}
F_15 ( V_19 , V_3 -> V_20 + V_53 ) ;
return 0 ;
}
static void F_28 ( struct V_2 * V_3 )
{
F_15 ( 0 , V_3 -> V_20 + V_53 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_7 ) ;
return;
}
if ( V_3 -> V_39 == 0 ) {
F_15 ( V_8 -> V_37 , V_3 -> V_20 + V_68 ) ;
F_15 ( V_8 -> V_38 , V_3 -> V_20 + V_69 ) ;
F_15 ( V_8 -> V_40 , V_3 -> V_20 + V_70 ) ;
} else {
F_15 ( V_8 -> V_37 , V_3 -> V_20 + V_71 ) ;
F_15 ( V_8 -> V_38 , V_3 -> V_20 + V_72 ) ;
F_15 ( V_8 -> V_40 , V_3 -> V_20 + V_73 ) ;
}
V_3 -> V_39 ^= 1 ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_4 . V_24 ;
T_1 V_19 = F_16 ( V_3 -> V_20 + V_53 ) ;
V_19 &= ~ V_74 ;
V_19 |= V_3 -> V_75 ;
F_29 ( V_3 ) ;
V_19 |= V_76 ;
V_19 |= V_77 ;
F_15 ( V_19 , V_3 -> V_20 + V_53 ) ;
if ( ! V_23 ) {
V_19 |= V_78 ;
F_15 ( V_19 , V_3 -> V_20 + V_53 ) ;
}
}
static int F_31 ( struct V_2 * V_3 )
{
T_1 V_19 ;
if ( ! ( F_16 ( V_3 -> V_20 + V_79 ) & V_80 ) )
return V_52 ;
F_15 ( 0 , V_3 -> V_20 + V_79 ) ;
V_19 = F_16 ( V_3 -> V_20 + V_53 ) ;
V_19 &= ~ ( V_76 | V_77 ) ;
F_15 ( V_19 , V_3 -> V_20 + V_53 ) ;
if ( F_11 ( V_3 ) ) {
V_3 -> V_81 -> V_82 ( V_3 ) ;
return V_51 ;
}
return V_50 ;
}
static struct V_7 *
F_32 ( struct V_2 * V_3 )
{
struct V_7 * V_8 , * V_83 ;
struct V_7 * V_84 = NULL ;
unsigned long V_17 ;
F_33 ( & V_3 -> V_85 , V_17 ) ;
F_34 (desc, _desc, &edmac->free_list, node) {
if ( F_35 ( & V_8 -> V_13 ) ) {
F_36 ( & V_8 -> V_10 ) ;
V_8 -> V_37 = 0 ;
V_8 -> V_38 = 0 ;
V_8 -> V_40 = 0 ;
V_8 -> V_86 = false ;
V_8 -> V_13 . V_18 = 0 ;
V_8 -> V_13 . V_14 = NULL ;
V_8 -> V_13 . V_15 = NULL ;
V_84 = V_8 ;
break;
}
}
F_37 ( & V_3 -> V_85 , V_17 ) ;
return V_84 ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
if ( V_8 ) {
unsigned long V_17 ;
F_33 ( & V_3 -> V_85 , V_17 ) ;
F_39 ( & V_8 -> V_11 , & V_3 -> V_87 ) ;
F_40 ( & V_8 -> V_10 , & V_3 -> V_87 ) ;
F_37 ( & V_3 -> V_85 , V_17 ) ;
}
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_7 * V_88 ;
unsigned long V_17 ;
F_33 ( & V_3 -> V_85 , V_17 ) ;
if ( ! F_6 ( & V_3 -> V_9 ) || F_6 ( & V_3 -> V_89 ) ) {
F_37 ( & V_3 -> V_85 , V_17 ) ;
return;
}
V_88 = F_8 ( & V_3 -> V_89 , struct V_7 , V_10 ) ;
F_36 ( & V_88 -> V_10 ) ;
F_4 ( V_3 , V_88 ) ;
V_3 -> V_81 -> V_82 ( V_3 ) ;
F_37 ( & V_3 -> V_85 , V_17 ) ;
}
static void F_42 ( struct V_7 * V_8 )
{
struct V_1 * V_5 = V_8 -> V_13 . V_4 -> V_1 -> V_5 ;
if ( ! ( V_8 -> V_13 . V_17 & V_90 ) ) {
if ( V_8 -> V_13 . V_17 & V_91 )
F_43 ( V_5 , V_8 -> V_37 , V_8 -> V_40 ,
V_92 ) ;
else
F_44 ( V_5 , V_8 -> V_37 , V_8 -> V_40 ,
V_92 ) ;
}
if ( ! ( V_8 -> V_13 . V_17 & V_93 ) ) {
if ( V_8 -> V_13 . V_17 & V_94 )
F_43 ( V_5 , V_8 -> V_38 , V_8 -> V_40 ,
V_95 ) ;
else
F_44 ( V_5 , V_8 -> V_38 , V_8 -> V_40 ,
V_95 ) ;
}
}
static void F_45 ( unsigned long V_23 )
{
struct V_2 * V_3 = (struct V_2 * ) V_23 ;
struct V_7 * V_8 , * V_12 ;
T_2 V_14 = NULL ;
void * V_15 = NULL ;
F_46 ( V_96 ) ;
F_47 ( & V_3 -> V_85 ) ;
V_8 = F_10 ( V_3 ) ;
if ( V_8 ) {
if ( V_8 -> V_86 ) {
V_3 -> V_97 = V_8 -> V_13 . V_18 ;
F_39 ( & V_3 -> V_9 , & V_96 ) ;
}
V_14 = V_8 -> V_13 . V_14 ;
V_15 = V_8 -> V_13 . V_15 ;
}
F_48 ( & V_3 -> V_85 ) ;
F_41 ( V_3 ) ;
F_34 (desc, d, &list, node) {
if ( ! V_3 -> V_4 . V_24 )
F_42 ( V_8 ) ;
F_38 ( V_3 , V_8 ) ;
}
if ( V_14 )
V_14 ( V_15 ) ;
}
static T_3 F_49 ( int V_98 , void * V_99 )
{
struct V_2 * V_3 = V_99 ;
struct V_7 * V_8 ;
T_3 V_84 = V_100 ;
F_50 ( & V_3 -> V_85 ) ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) ,
L_8 ) ;
F_51 ( & V_3 -> V_85 ) ;
return V_101 ;
}
switch ( V_3 -> V_81 -> V_102 ( V_3 ) ) {
case V_50 :
V_8 -> V_86 = true ;
F_52 ( & V_3 -> V_103 ) ;
break;
case V_51 :
if ( F_13 ( V_16 , & V_3 -> V_17 ) )
F_52 ( & V_3 -> V_103 ) ;
break;
default:
F_22 ( F_1 ( V_3 ) , L_9 ) ;
V_84 = V_101 ;
break;
}
F_51 ( & V_3 -> V_85 ) ;
return V_84 ;
}
static T_4 F_53 ( struct V_104 * V_105 )
{
struct V_2 * V_3 = F_2 ( V_105 -> V_4 ) ;
struct V_7 * V_8 ;
T_4 V_18 ;
unsigned long V_17 ;
F_33 ( & V_3 -> V_85 , V_17 ) ;
V_18 = V_3 -> V_4 . V_18 ;
if ( ++ V_18 < 0 )
V_18 = 1 ;
V_8 = F_3 ( V_105 , struct V_7 , V_13 ) ;
V_3 -> V_4 . V_18 = V_18 ;
V_8 -> V_13 . V_18 = V_18 ;
if ( F_6 ( & V_3 -> V_9 ) ) {
F_4 ( V_3 , V_8 ) ;
V_3 -> V_81 -> V_82 ( V_3 ) ;
} else {
F_7 ( & V_8 -> V_10 , & V_3 -> V_89 ) ;
}
F_37 ( & V_3 -> V_85 , V_17 ) ;
return V_18 ;
}
static int F_54 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_22 * V_23 = V_4 -> V_24 ;
const char * V_106 = F_55 ( V_4 ) ;
int V_84 , V_107 ;
if ( ! V_3 -> V_81 -> V_108 ) {
if ( ! V_23 )
return - V_67 ;
if ( V_23 -> V_25 < V_109 ||
V_23 -> V_25 > V_110 )
return - V_67 ;
if ( V_23 -> V_57 != F_23 ( V_4 ) )
return - V_67 ;
} else {
if ( V_23 ) {
switch ( V_23 -> V_25 ) {
case V_54 :
case V_64 :
if ( V_23 -> V_57 != V_36 &&
V_23 -> V_57 != V_111 )
return - V_67 ;
break;
default:
return - V_67 ;
}
}
}
if ( V_23 && V_23 -> V_106 )
V_106 = V_23 -> V_106 ;
V_84 = F_56 ( V_3 -> V_112 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_57 ( V_3 -> V_98 , F_49 , 0 , V_106 , V_3 ) ;
if ( V_84 )
goto V_113;
F_47 ( & V_3 -> V_85 ) ;
V_3 -> V_97 = 1 ;
V_3 -> V_4 . V_18 = 1 ;
V_84 = V_3 -> V_81 -> V_114 ( V_3 ) ;
F_48 ( & V_3 -> V_85 ) ;
if ( V_84 )
goto V_115;
for ( V_107 = 0 ; V_107 < V_116 ; V_107 ++ ) {
struct V_7 * V_8 ;
V_8 = F_58 ( sizeof( * V_8 ) , V_117 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_10 ) ;
break;
}
F_59 ( & V_8 -> V_11 ) ;
F_60 ( & V_8 -> V_13 , V_4 ) ;
V_8 -> V_13 . V_17 = V_118 ;
V_8 -> V_13 . V_119 = F_53 ;
F_38 ( V_3 , V_8 ) ;
}
return V_107 ;
V_115:
F_61 ( V_3 -> V_98 , V_3 ) ;
V_113:
F_62 ( V_3 -> V_112 ) ;
return V_84 ;
}
static void F_63 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_12 ;
unsigned long V_17 ;
F_46 ( V_96 ) ;
F_5 ( ! F_6 ( & V_3 -> V_9 ) ) ;
F_5 ( ! F_6 ( & V_3 -> V_89 ) ) ;
F_33 ( & V_3 -> V_85 , V_17 ) ;
V_3 -> V_81 -> V_120 ( V_3 ) ;
V_3 -> V_121 = 0 ;
V_3 -> V_75 = 0 ;
V_3 -> V_39 = 0 ;
F_39 ( & V_3 -> V_87 , & V_96 ) ;
F_37 ( & V_3 -> V_85 , V_17 ) ;
F_34 (desc, d, &list, node)
F_64 ( V_8 ) ;
F_62 ( V_3 -> V_112 ) ;
F_61 ( V_3 -> V_98 , V_3 ) ;
}
static struct V_104 *
F_65 ( struct V_6 * V_4 , T_5 V_122 ,
T_5 V_123 , T_6 V_124 , unsigned long V_17 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_125 ;
T_6 V_126 , V_127 ;
V_125 = NULL ;
for ( V_127 = 0 ; V_127 < V_124 ; V_127 += V_126 ) {
V_8 = F_32 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_11 ) ;
goto V_128;
}
V_126 = F_66 ( T_6 , V_124 - V_127 , V_129 ) ;
V_8 -> V_37 = V_123 + V_127 ;
V_8 -> V_38 = V_122 + V_127 ;
V_8 -> V_40 = V_126 ;
if ( ! V_125 )
V_125 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_125 -> V_11 ) ;
}
V_125 -> V_13 . V_18 = - V_130 ;
V_125 -> V_13 . V_17 = V_17 ;
return & V_125 -> V_13 ;
V_128:
F_38 ( V_3 , V_125 ) ;
return NULL ;
}
static struct V_104 *
F_67 ( struct V_6 * V_4 , struct V_131 * V_132 ,
unsigned int V_133 , enum V_134 V_135 ,
unsigned long V_17 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_125 ;
struct V_131 * V_136 ;
int V_107 ;
if ( ! V_3 -> V_81 -> V_108 && V_135 != F_23 ( V_4 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_12 ) ;
return NULL ;
}
if ( F_13 ( V_16 , & V_3 -> V_17 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_13 ) ;
return NULL ;
}
V_125 = NULL ;
F_68 (sgl, sg, sg_len, i) {
T_6 V_133 = F_69 ( V_136 ) ;
if ( V_133 > V_129 ) {
F_22 ( F_1 ( V_3 ) , L_14 ,
V_133 ) ;
goto V_128;
}
V_8 = F_32 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_11 ) ;
goto V_128;
}
if ( V_135 == V_36 ) {
V_8 -> V_37 = F_70 ( V_136 ) ;
V_8 -> V_38 = V_3 -> V_121 ;
} else {
V_8 -> V_37 = V_3 -> V_121 ;
V_8 -> V_38 = F_70 ( V_136 ) ;
}
V_8 -> V_40 = V_133 ;
if ( ! V_125 )
V_125 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_125 -> V_11 ) ;
}
V_125 -> V_13 . V_18 = - V_130 ;
V_125 -> V_13 . V_17 = V_17 ;
return & V_125 -> V_13 ;
V_128:
F_38 ( V_3 , V_125 ) ;
return NULL ;
}
static struct V_104 *
F_71 ( struct V_6 * V_4 , T_5 V_137 ,
T_6 V_138 , T_6 V_139 ,
enum V_134 V_135 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_125 ;
T_6 V_127 = 0 ;
if ( ! V_3 -> V_81 -> V_108 && V_135 != F_23 ( V_4 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_12 ) ;
return NULL ;
}
if ( F_72 ( V_16 , & V_3 -> V_17 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_13 ) ;
return NULL ;
}
if ( V_139 > V_129 ) {
F_22 ( F_1 ( V_3 ) , L_15 ,
V_139 ) ;
return NULL ;
}
V_125 = NULL ;
for ( V_127 = 0 ; V_127 < V_138 ; V_127 += V_139 ) {
V_8 = F_32 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_11 ) ;
goto V_128;
}
if ( V_135 == V_36 ) {
V_8 -> V_37 = V_137 + V_127 ;
V_8 -> V_38 = V_3 -> V_121 ;
} else {
V_8 -> V_37 = V_3 -> V_121 ;
V_8 -> V_38 = V_137 + V_127 ;
}
V_8 -> V_40 = V_139 ;
if ( ! V_125 )
V_125 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_125 -> V_11 ) ;
}
V_125 -> V_13 . V_18 = - V_130 ;
return & V_125 -> V_13 ;
V_128:
F_38 ( V_3 , V_125 ) ;
return NULL ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_7 * V_8 , * V_140 ;
unsigned long V_17 ;
F_46 ( V_96 ) ;
F_33 ( & V_3 -> V_85 , V_17 ) ;
V_3 -> V_81 -> V_120 ( V_3 ) ;
F_74 ( V_16 , & V_3 -> V_17 ) ;
F_39 ( & V_3 -> V_9 , & V_96 ) ;
F_39 ( & V_3 -> V_89 , & V_96 ) ;
V_3 -> V_81 -> V_114 ( V_3 ) ;
F_37 ( & V_3 -> V_85 , V_17 ) ;
F_34 (desc, _d, &list, node)
F_38 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_141 * V_142 )
{
enum V_143 V_144 ;
unsigned long V_17 ;
T_1 V_145 , V_146 ;
if ( ! V_3 -> V_81 -> V_108 )
return - V_67 ;
switch ( V_142 -> V_57 ) {
case V_111 :
V_144 = V_142 -> V_147 ;
V_145 = V_142 -> V_37 ;
break;
case V_36 :
V_144 = V_142 -> V_148 ;
V_145 = V_142 -> V_38 ;
break;
default:
return - V_67 ;
}
switch ( V_144 ) {
case V_149 :
V_146 = 0 ;
break;
case V_150 :
V_146 = V_66 ;
break;
case V_151 :
V_146 = V_152 ;
break;
default:
return - V_67 ;
}
F_33 ( & V_3 -> V_85 , V_17 ) ;
V_3 -> V_121 = V_145 ;
V_3 -> V_75 = V_146 ;
F_37 ( & V_3 -> V_85 , V_17 ) ;
return 0 ;
}
static int F_76 ( struct V_6 * V_4 , enum V_153 V_154 ,
unsigned long V_155 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_141 * V_142 ;
switch ( V_154 ) {
case V_156 :
return F_73 ( V_3 ) ;
case V_157 :
V_142 = (struct V_141 * ) V_155 ;
return F_75 ( V_3 , V_142 ) ;
default:
break;
}
return - V_158 ;
}
static enum V_159 F_77 ( struct V_6 * V_4 ,
T_4 V_18 ,
struct V_160 * V_161 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
T_4 V_162 , V_97 ;
enum V_159 V_84 ;
unsigned long V_17 ;
F_33 ( & V_3 -> V_85 , V_17 ) ;
V_162 = V_4 -> V_18 ;
V_97 = V_3 -> V_97 ;
F_37 ( & V_3 -> V_85 , V_17 ) ;
V_84 = F_78 ( V_18 , V_97 , V_162 ) ;
F_79 ( V_161 , V_97 , V_162 , 0 ) ;
return V_84 ;
}
static void F_80 ( struct V_6 * V_4 )
{
F_41 ( F_2 ( V_4 ) ) ;
}
static int T_7 F_81 ( struct V_163 * V_164 )
{
struct V_165 * V_166 = F_82 ( & V_164 -> V_5 ) ;
struct V_167 * V_81 ;
struct V_168 * V_169 ;
T_6 V_170 ;
int V_84 , V_107 ;
V_170 = V_166 -> V_171 * sizeof( struct V_2 ) ;
V_81 = F_58 ( sizeof( * V_81 ) + V_170 , V_117 ) ;
if ( ! V_81 )
return - V_172 ;
V_169 = & V_81 -> V_169 ;
V_81 -> V_108 = F_83 ( V_164 ) -> V_173 ;
V_81 -> V_171 = V_166 -> V_171 ;
F_59 ( & V_169 -> V_174 ) ;
for ( V_107 = 0 ; V_107 < V_166 -> V_171 ; V_107 ++ ) {
const struct V_175 * V_176 = & V_166 -> V_174 [ V_107 ] ;
struct V_2 * V_3 = & V_81 -> V_174 [ V_107 ] ;
V_3 -> V_4 . V_1 = V_169 ;
V_3 -> V_20 = V_176 -> V_177 ;
V_3 -> V_98 = V_176 -> V_98 ;
V_3 -> V_81 = V_81 ;
V_3 -> V_112 = F_84 ( NULL , V_176 -> V_106 ) ;
if ( F_85 ( V_3 -> V_112 ) ) {
F_22 ( & V_164 -> V_5 , L_16 ,
V_176 -> V_106 ) ;
continue;
}
F_86 ( & V_3 -> V_85 ) ;
F_59 ( & V_3 -> V_9 ) ;
F_59 ( & V_3 -> V_89 ) ;
F_59 ( & V_3 -> V_87 ) ;
F_87 ( & V_3 -> V_103 , F_45 ,
( unsigned long ) V_3 ) ;
F_7 ( & V_3 -> V_4 . V_178 ,
& V_169 -> V_174 ) ;
}
F_88 ( V_169 -> V_179 ) ;
F_89 ( V_180 , V_169 -> V_179 ) ;
F_89 ( V_181 , V_169 -> V_179 ) ;
V_169 -> V_5 = & V_164 -> V_5 ;
V_169 -> V_182 = F_54 ;
V_169 -> V_183 = F_63 ;
V_169 -> V_184 = F_67 ;
V_169 -> V_185 = F_71 ;
V_169 -> V_186 = F_76 ;
V_169 -> V_187 = F_80 ;
V_169 -> V_188 = F_77 ;
F_90 ( V_169 -> V_5 , V_129 ) ;
if ( V_81 -> V_108 ) {
F_89 ( V_189 , V_169 -> V_179 ) ;
V_169 -> V_190 = F_65 ;
V_81 -> V_114 = F_27 ;
V_81 -> V_120 = F_28 ;
V_81 -> V_82 = F_30 ;
V_81 -> V_102 = F_31 ;
} else {
F_89 ( V_191 , V_169 -> V_179 ) ;
V_81 -> V_114 = F_17 ;
V_81 -> V_120 = F_19 ;
V_81 -> V_82 = F_24 ;
V_81 -> V_102 = F_25 ;
}
V_84 = F_91 ( V_169 ) ;
if ( F_92 ( V_84 ) ) {
for ( V_107 = 0 ; V_107 < V_81 -> V_171 ; V_107 ++ ) {
struct V_2 * V_3 = & V_81 -> V_174 [ V_107 ] ;
if ( ! F_93 ( V_3 -> V_112 ) )
F_94 ( V_3 -> V_112 ) ;
}
F_64 ( V_81 ) ;
} else {
F_95 ( V_169 -> V_5 , L_17 ,
V_81 -> V_108 ? L_18 : L_19 ) ;
}
return V_84 ;
}
static int T_7 F_96 ( void )
{
return F_97 ( & V_192 , F_81 ) ;
}
