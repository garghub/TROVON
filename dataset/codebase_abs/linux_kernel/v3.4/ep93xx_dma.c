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
if ( ! F_13 ( V_16 , & V_3 -> V_17 ) )
F_48 ( & V_8 -> V_13 ) ;
F_39 ( & V_3 -> V_9 , & V_96 ) ;
}
V_14 = V_8 -> V_13 . V_14 ;
V_15 = V_8 -> V_13 . V_15 ;
}
F_49 ( & V_3 -> V_85 ) ;
F_41 ( V_3 ) ;
F_34 (desc, d, &list, node) {
if ( ! V_3 -> V_4 . V_24 )
F_42 ( V_8 ) ;
F_38 ( V_3 , V_8 ) ;
}
if ( V_14 )
V_14 ( V_15 ) ;
}
static T_3 F_50 ( int V_97 , void * V_98 )
{
struct V_2 * V_3 = V_98 ;
struct V_7 * V_8 ;
T_3 V_84 = V_99 ;
F_51 ( & V_3 -> V_85 ) ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) ,
L_8 ) ;
F_52 ( & V_3 -> V_85 ) ;
return V_100 ;
}
switch ( V_3 -> V_81 -> V_101 ( V_3 ) ) {
case V_50 :
V_8 -> V_86 = true ;
F_53 ( & V_3 -> V_102 ) ;
break;
case V_51 :
if ( F_13 ( V_16 , & V_3 -> V_17 ) )
F_53 ( & V_3 -> V_102 ) ;
break;
default:
F_22 ( F_1 ( V_3 ) , L_9 ) ;
V_84 = V_100 ;
break;
}
F_52 ( & V_3 -> V_85 ) ;
return V_84 ;
}
static T_4 F_54 ( struct V_103 * V_104 )
{
struct V_2 * V_3 = F_2 ( V_104 -> V_4 ) ;
struct V_7 * V_8 ;
T_4 V_18 ;
unsigned long V_17 ;
F_33 ( & V_3 -> V_85 , V_17 ) ;
V_18 = F_55 ( V_104 ) ;
V_8 = F_3 ( V_104 , struct V_7 , V_13 ) ;
if ( F_6 ( & V_3 -> V_9 ) ) {
F_4 ( V_3 , V_8 ) ;
V_3 -> V_81 -> V_82 ( V_3 ) ;
} else {
F_7 ( & V_8 -> V_10 , & V_3 -> V_89 ) ;
}
F_37 ( & V_3 -> V_85 , V_17 ) ;
return V_18 ;
}
static int F_56 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_22 * V_23 = V_4 -> V_24 ;
const char * V_105 = F_57 ( V_4 ) ;
int V_84 , V_106 ;
if ( ! V_3 -> V_81 -> V_107 ) {
if ( ! V_23 )
return - V_67 ;
if ( V_23 -> V_25 < V_108 ||
V_23 -> V_25 > V_109 )
return - V_67 ;
if ( V_23 -> V_57 != F_23 ( V_4 ) )
return - V_67 ;
} else {
if ( V_23 ) {
switch ( V_23 -> V_25 ) {
case V_54 :
case V_64 :
if ( V_23 -> V_57 != V_36 &&
V_23 -> V_57 != V_110 )
return - V_67 ;
break;
default:
return - V_67 ;
}
}
}
if ( V_23 && V_23 -> V_105 )
V_105 = V_23 -> V_105 ;
V_84 = F_58 ( V_3 -> V_111 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_59 ( V_3 -> V_97 , F_50 , 0 , V_105 , V_3 ) ;
if ( V_84 )
goto V_112;
F_47 ( & V_3 -> V_85 ) ;
F_60 ( & V_3 -> V_4 ) ;
V_84 = V_3 -> V_81 -> V_113 ( V_3 ) ;
F_49 ( & V_3 -> V_85 ) ;
if ( V_84 )
goto V_114;
for ( V_106 = 0 ; V_106 < V_115 ; V_106 ++ ) {
struct V_7 * V_8 ;
V_8 = F_61 ( sizeof( * V_8 ) , V_116 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_10 ) ;
break;
}
F_62 ( & V_8 -> V_11 ) ;
F_63 ( & V_8 -> V_13 , V_4 ) ;
V_8 -> V_13 . V_17 = V_117 ;
V_8 -> V_13 . V_118 = F_54 ;
F_38 ( V_3 , V_8 ) ;
}
return V_106 ;
V_114:
F_64 ( V_3 -> V_97 , V_3 ) ;
V_112:
F_65 ( V_3 -> V_111 ) ;
return V_84 ;
}
static void F_66 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_12 ;
unsigned long V_17 ;
F_46 ( V_96 ) ;
F_5 ( ! F_6 ( & V_3 -> V_9 ) ) ;
F_5 ( ! F_6 ( & V_3 -> V_89 ) ) ;
F_33 ( & V_3 -> V_85 , V_17 ) ;
V_3 -> V_81 -> V_119 ( V_3 ) ;
V_3 -> V_120 = 0 ;
V_3 -> V_75 = 0 ;
V_3 -> V_39 = 0 ;
F_39 ( & V_3 -> V_87 , & V_96 ) ;
F_37 ( & V_3 -> V_85 , V_17 ) ;
F_34 (desc, d, &list, node)
F_67 ( V_8 ) ;
F_65 ( V_3 -> V_111 ) ;
F_64 ( V_3 -> V_97 , V_3 ) ;
}
static struct V_103 *
F_68 ( struct V_6 * V_4 , T_5 V_121 ,
T_5 V_122 , T_6 V_123 , unsigned long V_17 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_124 ;
T_6 V_125 , V_126 ;
V_124 = NULL ;
for ( V_126 = 0 ; V_126 < V_123 ; V_126 += V_125 ) {
V_8 = F_32 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_11 ) ;
goto V_127;
}
V_125 = F_69 ( T_6 , V_123 - V_126 , V_128 ) ;
V_8 -> V_37 = V_122 + V_126 ;
V_8 -> V_38 = V_121 + V_126 ;
V_8 -> V_40 = V_125 ;
if ( ! V_124 )
V_124 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_124 -> V_11 ) ;
}
V_124 -> V_13 . V_18 = - V_129 ;
V_124 -> V_13 . V_17 = V_17 ;
return & V_124 -> V_13 ;
V_127:
F_38 ( V_3 , V_124 ) ;
return NULL ;
}
static struct V_103 *
F_70 ( struct V_6 * V_4 , struct V_130 * V_131 ,
unsigned int V_132 , enum V_133 V_134 ,
unsigned long V_17 , void * V_135 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_124 ;
struct V_130 * V_136 ;
int V_106 ;
if ( ! V_3 -> V_81 -> V_107 && V_134 != F_23 ( V_4 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_12 ) ;
return NULL ;
}
if ( F_13 ( V_16 , & V_3 -> V_17 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_13 ) ;
return NULL ;
}
V_124 = NULL ;
F_71 (sgl, sg, sg_len, i) {
T_6 V_132 = F_72 ( V_136 ) ;
if ( V_132 > V_128 ) {
F_22 ( F_1 ( V_3 ) , L_14 ,
V_132 ) ;
goto V_127;
}
V_8 = F_32 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_11 ) ;
goto V_127;
}
if ( V_134 == V_36 ) {
V_8 -> V_37 = F_73 ( V_136 ) ;
V_8 -> V_38 = V_3 -> V_120 ;
} else {
V_8 -> V_37 = V_3 -> V_120 ;
V_8 -> V_38 = F_73 ( V_136 ) ;
}
V_8 -> V_40 = V_132 ;
if ( ! V_124 )
V_124 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_124 -> V_11 ) ;
}
V_124 -> V_13 . V_18 = - V_129 ;
V_124 -> V_13 . V_17 = V_17 ;
return & V_124 -> V_13 ;
V_127:
F_38 ( V_3 , V_124 ) ;
return NULL ;
}
static struct V_103 *
F_74 ( struct V_6 * V_4 , T_5 V_137 ,
T_6 V_138 , T_6 V_139 ,
enum V_133 V_134 , void * V_135 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_124 ;
T_6 V_126 = 0 ;
if ( ! V_3 -> V_81 -> V_107 && V_134 != F_23 ( V_4 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_12 ) ;
return NULL ;
}
if ( F_75 ( V_16 , & V_3 -> V_17 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_13 ) ;
return NULL ;
}
if ( V_139 > V_128 ) {
F_22 ( F_1 ( V_3 ) , L_15 ,
V_139 ) ;
return NULL ;
}
V_124 = NULL ;
for ( V_126 = 0 ; V_126 < V_138 ; V_126 += V_139 ) {
V_8 = F_32 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_11 ) ;
goto V_127;
}
if ( V_134 == V_36 ) {
V_8 -> V_37 = V_137 + V_126 ;
V_8 -> V_38 = V_3 -> V_120 ;
} else {
V_8 -> V_37 = V_3 -> V_120 ;
V_8 -> V_38 = V_137 + V_126 ;
}
V_8 -> V_40 = V_139 ;
if ( ! V_124 )
V_124 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_124 -> V_11 ) ;
}
V_124 -> V_13 . V_18 = - V_129 ;
return & V_124 -> V_13 ;
V_127:
F_38 ( V_3 , V_124 ) ;
return NULL ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_7 * V_8 , * V_140 ;
unsigned long V_17 ;
F_46 ( V_96 ) ;
F_33 ( & V_3 -> V_85 , V_17 ) ;
V_3 -> V_81 -> V_119 ( V_3 ) ;
F_77 ( V_16 , & V_3 -> V_17 ) ;
F_39 ( & V_3 -> V_9 , & V_96 ) ;
F_39 ( & V_3 -> V_89 , & V_96 ) ;
V_3 -> V_81 -> V_113 ( V_3 ) ;
F_37 ( & V_3 -> V_85 , V_17 ) ;
F_34 (desc, _d, &list, node)
F_38 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_78 ( struct V_2 * V_3 ,
struct V_141 * V_142 )
{
enum V_143 V_144 ;
unsigned long V_17 ;
T_1 V_145 , V_146 ;
if ( ! V_3 -> V_81 -> V_107 )
return - V_67 ;
switch ( V_142 -> V_57 ) {
case V_110 :
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
V_3 -> V_120 = V_145 ;
V_3 -> V_75 = V_146 ;
F_37 ( & V_3 -> V_85 , V_17 ) ;
return 0 ;
}
static int F_79 ( struct V_6 * V_4 , enum V_153 V_154 ,
unsigned long V_155 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_141 * V_142 ;
switch ( V_154 ) {
case V_156 :
return F_76 ( V_3 ) ;
case V_157 :
V_142 = (struct V_141 * ) V_155 ;
return F_78 ( V_3 , V_142 ) ;
default:
break;
}
return - V_158 ;
}
static enum V_159 F_80 ( struct V_6 * V_4 ,
T_4 V_18 ,
struct V_160 * V_161 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
enum V_159 V_84 ;
unsigned long V_17 ;
F_33 ( & V_3 -> V_85 , V_17 ) ;
V_84 = F_81 ( V_4 , V_18 , V_161 ) ;
F_37 ( & V_3 -> V_85 , V_17 ) ;
return V_84 ;
}
static void F_82 ( struct V_6 * V_4 )
{
F_41 ( F_2 ( V_4 ) ) ;
}
static int T_7 F_83 ( struct V_162 * V_163 )
{
struct V_164 * V_165 = F_84 ( & V_163 -> V_5 ) ;
struct V_166 * V_81 ;
struct V_167 * V_168 ;
T_6 V_169 ;
int V_84 , V_106 ;
V_169 = V_165 -> V_170 * sizeof( struct V_2 ) ;
V_81 = F_61 ( sizeof( * V_81 ) + V_169 , V_116 ) ;
if ( ! V_81 )
return - V_171 ;
V_168 = & V_81 -> V_168 ;
V_81 -> V_107 = F_85 ( V_163 ) -> V_172 ;
V_81 -> V_170 = V_165 -> V_170 ;
F_62 ( & V_168 -> V_173 ) ;
for ( V_106 = 0 ; V_106 < V_165 -> V_170 ; V_106 ++ ) {
const struct V_174 * V_175 = & V_165 -> V_173 [ V_106 ] ;
struct V_2 * V_3 = & V_81 -> V_173 [ V_106 ] ;
V_3 -> V_4 . V_1 = V_168 ;
V_3 -> V_20 = V_175 -> V_176 ;
V_3 -> V_97 = V_175 -> V_97 ;
V_3 -> V_81 = V_81 ;
V_3 -> V_111 = F_86 ( NULL , V_175 -> V_105 ) ;
if ( F_87 ( V_3 -> V_111 ) ) {
F_22 ( & V_163 -> V_5 , L_16 ,
V_175 -> V_105 ) ;
continue;
}
F_88 ( & V_3 -> V_85 ) ;
F_62 ( & V_3 -> V_9 ) ;
F_62 ( & V_3 -> V_89 ) ;
F_62 ( & V_3 -> V_87 ) ;
F_89 ( & V_3 -> V_102 , F_45 ,
( unsigned long ) V_3 ) ;
F_7 ( & V_3 -> V_4 . V_177 ,
& V_168 -> V_173 ) ;
}
F_90 ( V_168 -> V_178 ) ;
F_91 ( V_179 , V_168 -> V_178 ) ;
F_91 ( V_180 , V_168 -> V_178 ) ;
V_168 -> V_5 = & V_163 -> V_5 ;
V_168 -> V_181 = F_56 ;
V_168 -> V_182 = F_66 ;
V_168 -> V_183 = F_70 ;
V_168 -> V_184 = F_74 ;
V_168 -> V_185 = F_79 ;
V_168 -> V_186 = F_82 ;
V_168 -> V_187 = F_80 ;
F_92 ( V_168 -> V_5 , V_128 ) ;
if ( V_81 -> V_107 ) {
F_91 ( V_188 , V_168 -> V_178 ) ;
V_168 -> V_189 = F_68 ;
V_81 -> V_113 = F_27 ;
V_81 -> V_119 = F_28 ;
V_81 -> V_82 = F_30 ;
V_81 -> V_101 = F_31 ;
} else {
F_91 ( V_190 , V_168 -> V_178 ) ;
V_81 -> V_113 = F_17 ;
V_81 -> V_119 = F_19 ;
V_81 -> V_82 = F_24 ;
V_81 -> V_101 = F_25 ;
}
V_84 = F_93 ( V_168 ) ;
if ( F_94 ( V_84 ) ) {
for ( V_106 = 0 ; V_106 < V_81 -> V_170 ; V_106 ++ ) {
struct V_2 * V_3 = & V_81 -> V_173 [ V_106 ] ;
if ( ! F_95 ( V_3 -> V_111 ) )
F_96 ( V_3 -> V_111 ) ;
}
F_67 ( V_81 ) ;
} else {
F_97 ( V_168 -> V_5 , L_17 ,
V_81 -> V_107 ? L_18 : L_19 ) ;
}
return V_84 ;
}
static int T_7 F_98 ( void )
{
return F_99 ( & V_191 , F_83 ) ;
}
