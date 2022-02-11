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
return F_8 ( & V_3 -> V_9 , struct V_7 , V_10 ) ;
}
static bool F_11 ( struct V_2 * V_3 )
{
F_12 ( & V_3 -> V_9 ) ;
if ( F_13 ( V_16 , & V_3 -> V_17 ) )
return true ;
return ! F_10 ( V_3 ) -> V_13 . V_18 ;
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
struct V_7 * V_8 = F_10 ( V_3 ) ;
T_1 V_35 ;
if ( F_22 ( & V_3 -> V_4 ) == V_36 )
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
static void F_23 ( struct V_2 * V_3 )
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
static int F_24 ( struct V_2 * V_3 )
{
T_1 V_45 = F_16 ( V_3 -> V_20 + V_46 ) ;
T_1 V_19 ;
if ( V_45 & V_47 ) {
struct V_7 * V_8 = F_10 ( V_3 ) ;
F_15 ( 1 , V_3 -> V_20 + V_46 ) ;
F_25 ( F_1 ( V_3 ) ,
L_1
L_2
L_3
L_4
L_5 ,
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
static int F_26 ( struct V_2 * V_3 )
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
V_19 |= V_56 ;
V_19 |= V_65 ;
V_19 |= V_66 ;
if ( V_23 -> V_57 == V_36 ) {
V_19 = ( 3 << V_55 ) ;
V_19 |= V_58 ;
V_19 |= V_59 ;
} else {
V_19 = ( 2 << V_55 ) ;
V_19 |= V_61 ;
V_19 |= V_62 ;
}
break;
default:
return - V_67 ;
}
F_15 ( V_19 , V_3 -> V_20 + V_53 ) ;
return 0 ;
}
static void F_27 ( struct V_2 * V_3 )
{
F_15 ( 0 , V_3 -> V_20 + V_53 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_10 ( V_3 ) ;
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
static void F_29 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_4 . V_24 ;
T_1 V_19 = F_16 ( V_3 -> V_20 + V_53 ) ;
V_19 &= ~ V_74 ;
V_19 |= V_3 -> V_75 ;
F_28 ( V_3 ) ;
V_19 |= V_76 ;
V_19 |= V_77 ;
F_15 ( V_19 , V_3 -> V_20 + V_53 ) ;
if ( ! V_23 ) {
V_19 |= V_78 ;
F_15 ( V_19 , V_3 -> V_20 + V_53 ) ;
}
}
static int F_30 ( struct V_2 * V_3 )
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
F_31 ( struct V_2 * V_3 )
{
struct V_7 * V_8 , * V_83 ;
struct V_7 * V_84 = NULL ;
unsigned long V_17 ;
F_32 ( & V_3 -> V_85 , V_17 ) ;
F_33 (desc, _desc, &edmac->free_list, node) {
if ( F_34 ( & V_8 -> V_13 ) ) {
F_35 ( & V_8 -> V_10 ) ;
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
F_36 ( & V_3 -> V_85 , V_17 ) ;
return V_84 ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
if ( V_8 ) {
unsigned long V_17 ;
F_32 ( & V_3 -> V_85 , V_17 ) ;
F_38 ( & V_8 -> V_11 , & V_3 -> V_87 ) ;
F_39 ( & V_8 -> V_10 , & V_3 -> V_87 ) ;
F_36 ( & V_3 -> V_85 , V_17 ) ;
}
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_7 * V_88 ;
unsigned long V_17 ;
F_32 ( & V_3 -> V_85 , V_17 ) ;
if ( ! F_6 ( & V_3 -> V_9 ) || F_6 ( & V_3 -> V_89 ) ) {
F_36 ( & V_3 -> V_85 , V_17 ) ;
return;
}
V_88 = F_8 ( & V_3 -> V_89 , struct V_7 , V_10 ) ;
F_35 ( & V_88 -> V_10 ) ;
F_4 ( V_3 , V_88 ) ;
V_3 -> V_81 -> V_82 ( V_3 ) ;
F_36 ( & V_3 -> V_85 , V_17 ) ;
}
static void F_41 ( struct V_7 * V_8 )
{
struct V_1 * V_5 = V_8 -> V_13 . V_4 -> V_1 -> V_5 ;
if ( ! ( V_8 -> V_13 . V_17 & V_90 ) ) {
if ( V_8 -> V_13 . V_17 & V_91 )
F_42 ( V_5 , V_8 -> V_37 , V_8 -> V_40 ,
V_36 ) ;
else
F_43 ( V_5 , V_8 -> V_37 , V_8 -> V_40 ,
V_36 ) ;
}
if ( ! ( V_8 -> V_13 . V_17 & V_92 ) ) {
if ( V_8 -> V_13 . V_17 & V_93 )
F_42 ( V_5 , V_8 -> V_38 , V_8 -> V_40 ,
V_94 ) ;
else
F_43 ( V_5 , V_8 -> V_38 , V_8 -> V_40 ,
V_94 ) ;
}
}
static void F_44 ( unsigned long V_23 )
{
struct V_2 * V_3 = (struct V_2 * ) V_23 ;
struct V_7 * V_8 , * V_12 ;
T_2 V_14 ;
void * V_15 ;
F_45 ( V_95 ) ;
F_46 ( & V_3 -> V_85 ) ;
V_8 = F_10 ( V_3 ) ;
if ( V_8 -> V_86 ) {
V_3 -> V_96 = V_8 -> V_13 . V_18 ;
F_38 ( & V_3 -> V_9 , & V_95 ) ;
}
F_47 ( & V_3 -> V_85 ) ;
F_40 ( V_3 ) ;
V_14 = V_8 -> V_13 . V_14 ;
V_15 = V_8 -> V_13 . V_15 ;
F_33 (desc, d, &list, node) {
if ( ! V_3 -> V_4 . V_24 )
F_41 ( V_8 ) ;
F_37 ( V_3 , V_8 ) ;
}
if ( V_14 )
V_14 ( V_15 ) ;
}
static T_3 F_48 ( int V_97 , void * V_98 )
{
struct V_2 * V_3 = V_98 ;
T_3 V_84 = V_99 ;
F_49 ( & V_3 -> V_85 ) ;
switch ( V_3 -> V_81 -> V_100 ( V_3 ) ) {
case V_50 :
F_10 ( V_3 ) -> V_86 = true ;
F_50 ( & V_3 -> V_101 ) ;
break;
case V_51 :
if ( F_13 ( V_16 , & V_3 -> V_17 ) )
F_50 ( & V_3 -> V_101 ) ;
break;
default:
F_51 ( F_1 ( V_3 ) , L_6 ) ;
V_84 = V_102 ;
break;
}
F_52 ( & V_3 -> V_85 ) ;
return V_84 ;
}
static T_4 F_53 ( struct V_103 * V_104 )
{
struct V_2 * V_3 = F_2 ( V_104 -> V_4 ) ;
struct V_7 * V_8 ;
T_4 V_18 ;
unsigned long V_17 ;
F_32 ( & V_3 -> V_85 , V_17 ) ;
V_18 = V_3 -> V_4 . V_18 ;
if ( ++ V_18 < 0 )
V_18 = 1 ;
V_8 = F_3 ( V_104 , struct V_7 , V_13 ) ;
V_3 -> V_4 . V_18 = V_18 ;
V_8 -> V_13 . V_18 = V_18 ;
if ( F_6 ( & V_3 -> V_9 ) ) {
F_4 ( V_3 , V_8 ) ;
V_3 -> V_81 -> V_82 ( V_3 ) ;
} else {
F_7 ( & V_8 -> V_10 , & V_3 -> V_89 ) ;
}
F_36 ( & V_3 -> V_85 , V_17 ) ;
return V_18 ;
}
static int F_54 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_22 * V_23 = V_4 -> V_24 ;
const char * V_105 = F_55 ( V_4 ) ;
int V_84 , V_106 ;
if ( ! V_3 -> V_81 -> V_107 ) {
if ( ! V_23 )
return - V_67 ;
if ( V_23 -> V_25 < V_108 ||
V_23 -> V_25 > V_109 )
return - V_67 ;
if ( V_23 -> V_57 != F_22 ( V_4 ) )
return - V_67 ;
} else {
if ( V_23 ) {
switch ( V_23 -> V_25 ) {
case V_54 :
case V_64 :
if ( V_23 -> V_57 != V_36 &&
V_23 -> V_57 != V_94 )
return - V_67 ;
break;
default:
return - V_67 ;
}
}
}
if ( V_23 && V_23 -> V_105 )
V_105 = V_23 -> V_105 ;
V_84 = F_56 ( V_3 -> V_110 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_57 ( V_3 -> V_97 , F_48 , 0 , V_105 , V_3 ) ;
if ( V_84 )
goto V_111;
F_46 ( & V_3 -> V_85 ) ;
V_3 -> V_96 = 1 ;
V_3 -> V_4 . V_18 = 1 ;
V_84 = V_3 -> V_81 -> V_112 ( V_3 ) ;
F_47 ( & V_3 -> V_85 ) ;
if ( V_84 )
goto V_113;
for ( V_106 = 0 ; V_106 < V_114 ; V_106 ++ ) {
struct V_7 * V_8 ;
V_8 = F_58 ( sizeof( * V_8 ) , V_115 ) ;
if ( ! V_8 ) {
F_51 ( F_1 ( V_3 ) , L_7 ) ;
break;
}
F_59 ( & V_8 -> V_11 ) ;
F_60 ( & V_8 -> V_13 , V_4 ) ;
V_8 -> V_13 . V_17 = V_116 ;
V_8 -> V_13 . V_117 = F_53 ;
F_37 ( V_3 , V_8 ) ;
}
return V_106 ;
V_113:
F_61 ( V_3 -> V_97 , V_3 ) ;
V_111:
F_62 ( V_3 -> V_110 ) ;
return V_84 ;
}
static void F_63 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_12 ;
unsigned long V_17 ;
F_45 ( V_95 ) ;
F_5 ( ! F_6 ( & V_3 -> V_9 ) ) ;
F_5 ( ! F_6 ( & V_3 -> V_89 ) ) ;
F_32 ( & V_3 -> V_85 , V_17 ) ;
V_3 -> V_81 -> V_118 ( V_3 ) ;
V_3 -> V_119 = 0 ;
V_3 -> V_75 = 0 ;
V_3 -> V_39 = 0 ;
F_38 ( & V_3 -> V_87 , & V_95 ) ;
F_36 ( & V_3 -> V_85 , V_17 ) ;
F_33 (desc, d, &list, node)
F_64 ( V_8 ) ;
F_62 ( V_3 -> V_110 ) ;
F_61 ( V_3 -> V_97 , V_3 ) ;
}
static struct V_103 *
F_65 ( struct V_6 * V_4 , T_5 V_120 ,
T_5 V_121 , T_6 V_122 , unsigned long V_17 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_123 ;
T_6 V_124 , V_125 ;
V_123 = NULL ;
for ( V_125 = 0 ; V_125 < V_122 ; V_125 += V_124 ) {
V_8 = F_31 ( V_3 ) ;
if ( ! V_8 ) {
F_51 ( F_1 ( V_3 ) , L_8 ) ;
goto V_126;
}
V_124 = F_66 ( T_6 , V_122 - V_125 , V_127 ) ;
V_8 -> V_37 = V_121 + V_125 ;
V_8 -> V_38 = V_120 + V_125 ;
V_8 -> V_40 = V_124 ;
if ( ! V_123 )
V_123 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_123 -> V_11 ) ;
}
V_123 -> V_13 . V_18 = - V_128 ;
V_123 -> V_13 . V_17 = V_17 ;
return & V_123 -> V_13 ;
V_126:
F_37 ( V_3 , V_123 ) ;
return NULL ;
}
static struct V_103 *
F_67 ( struct V_6 * V_4 , struct V_129 * V_130 ,
unsigned int V_131 , enum V_132 V_133 ,
unsigned long V_17 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_123 ;
struct V_129 * V_134 ;
int V_106 ;
if ( ! V_3 -> V_81 -> V_107 && V_133 != F_22 ( V_4 ) ) {
F_51 ( F_1 ( V_3 ) ,
L_9 ) ;
return NULL ;
}
if ( F_13 ( V_16 , & V_3 -> V_17 ) ) {
F_51 ( F_1 ( V_3 ) ,
L_10 ) ;
return NULL ;
}
V_123 = NULL ;
F_68 (sgl, sg, sg_len, i) {
T_6 V_131 = F_69 ( V_134 ) ;
if ( V_131 > V_127 ) {
F_51 ( F_1 ( V_3 ) , L_11 ,
V_131 ) ;
goto V_126;
}
V_8 = F_31 ( V_3 ) ;
if ( ! V_8 ) {
F_51 ( F_1 ( V_3 ) , L_8 ) ;
goto V_126;
}
if ( V_133 == V_36 ) {
V_8 -> V_37 = F_70 ( V_134 ) ;
V_8 -> V_38 = V_3 -> V_119 ;
} else {
V_8 -> V_37 = V_3 -> V_119 ;
V_8 -> V_38 = F_70 ( V_134 ) ;
}
V_8 -> V_40 = V_131 ;
if ( ! V_123 )
V_123 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_123 -> V_11 ) ;
}
V_123 -> V_13 . V_18 = - V_128 ;
V_123 -> V_13 . V_17 = V_17 ;
return & V_123 -> V_13 ;
V_126:
F_37 ( V_3 , V_123 ) ;
return NULL ;
}
static struct V_103 *
F_71 ( struct V_6 * V_4 , T_5 V_135 ,
T_6 V_136 , T_6 V_137 ,
enum V_132 V_133 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_123 ;
T_6 V_125 = 0 ;
if ( ! V_3 -> V_81 -> V_107 && V_133 != F_22 ( V_4 ) ) {
F_51 ( F_1 ( V_3 ) ,
L_9 ) ;
return NULL ;
}
if ( F_72 ( V_16 , & V_3 -> V_17 ) ) {
F_51 ( F_1 ( V_3 ) ,
L_10 ) ;
return NULL ;
}
if ( V_137 > V_127 ) {
F_51 ( F_1 ( V_3 ) , L_12 ,
V_137 ) ;
return NULL ;
}
V_123 = NULL ;
for ( V_125 = 0 ; V_125 < V_136 ; V_125 += V_137 ) {
V_8 = F_31 ( V_3 ) ;
if ( ! V_8 ) {
F_51 ( F_1 ( V_3 ) , L_8 ) ;
goto V_126;
}
if ( V_133 == V_36 ) {
V_8 -> V_37 = V_135 + V_125 ;
V_8 -> V_38 = V_3 -> V_119 ;
} else {
V_8 -> V_37 = V_3 -> V_119 ;
V_8 -> V_38 = V_135 + V_125 ;
}
V_8 -> V_40 = V_137 ;
if ( ! V_123 )
V_123 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_123 -> V_11 ) ;
}
V_123 -> V_13 . V_18 = - V_128 ;
return & V_123 -> V_13 ;
V_126:
F_37 ( V_3 , V_123 ) ;
return NULL ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_7 * V_8 , * V_138 ;
unsigned long V_17 ;
F_45 ( V_95 ) ;
F_32 ( & V_3 -> V_85 , V_17 ) ;
V_3 -> V_81 -> V_118 ( V_3 ) ;
F_74 ( V_16 , & V_3 -> V_17 ) ;
F_38 ( & V_3 -> V_9 , & V_95 ) ;
F_38 ( & V_3 -> V_89 , & V_95 ) ;
V_3 -> V_81 -> V_112 ( V_3 ) ;
F_36 ( & V_3 -> V_85 , V_17 ) ;
F_33 (desc, _d, &list, node)
F_37 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_139 * V_140 )
{
enum V_141 V_142 ;
unsigned long V_17 ;
T_1 V_143 , V_144 ;
if ( ! V_3 -> V_81 -> V_107 )
return - V_67 ;
switch ( V_140 -> V_57 ) {
case V_94 :
V_142 = V_140 -> V_145 ;
V_143 = V_140 -> V_37 ;
break;
case V_36 :
V_142 = V_140 -> V_146 ;
V_143 = V_140 -> V_38 ;
break;
default:
return - V_67 ;
}
switch ( V_142 ) {
case V_147 :
V_144 = 0 ;
break;
case V_148 :
V_144 = V_66 ;
break;
case V_149 :
V_144 = V_150 ;
break;
default:
return - V_67 ;
}
F_32 ( & V_3 -> V_85 , V_17 ) ;
V_3 -> V_119 = V_143 ;
V_3 -> V_75 = V_144 ;
F_36 ( & V_3 -> V_85 , V_17 ) ;
return 0 ;
}
static int F_76 ( struct V_6 * V_4 , enum V_151 V_152 ,
unsigned long V_153 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_139 * V_140 ;
switch ( V_152 ) {
case V_154 :
return F_73 ( V_3 ) ;
case V_155 :
V_140 = (struct V_139 * ) V_153 ;
return F_75 ( V_3 , V_140 ) ;
default:
break;
}
return - V_156 ;
}
static enum V_157 F_77 ( struct V_6 * V_4 ,
T_4 V_18 ,
struct V_158 * V_159 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
T_4 V_160 , V_96 ;
enum V_157 V_84 ;
unsigned long V_17 ;
F_32 ( & V_3 -> V_85 , V_17 ) ;
V_160 = V_4 -> V_18 ;
V_96 = V_3 -> V_96 ;
F_36 ( & V_3 -> V_85 , V_17 ) ;
V_84 = F_78 ( V_18 , V_96 , V_160 ) ;
F_79 ( V_159 , V_96 , V_160 , 0 ) ;
return V_84 ;
}
static void F_80 ( struct V_6 * V_4 )
{
F_40 ( F_2 ( V_4 ) ) ;
}
static int T_7 F_81 ( struct V_161 * V_162 )
{
struct V_163 * V_164 = F_82 ( & V_162 -> V_5 ) ;
struct V_165 * V_81 ;
struct V_166 * V_167 ;
T_6 V_168 ;
int V_84 , V_106 ;
V_168 = V_164 -> V_169 * sizeof( struct V_2 ) ;
V_81 = F_58 ( sizeof( * V_81 ) + V_168 , V_115 ) ;
if ( ! V_81 )
return - V_170 ;
V_167 = & V_81 -> V_167 ;
V_81 -> V_107 = F_83 ( V_162 ) -> V_171 ;
V_81 -> V_169 = V_164 -> V_169 ;
F_59 ( & V_167 -> V_172 ) ;
for ( V_106 = 0 ; V_106 < V_164 -> V_169 ; V_106 ++ ) {
const struct V_173 * V_174 = & V_164 -> V_172 [ V_106 ] ;
struct V_2 * V_3 = & V_81 -> V_172 [ V_106 ] ;
V_3 -> V_4 . V_1 = V_167 ;
V_3 -> V_20 = V_174 -> V_175 ;
V_3 -> V_97 = V_174 -> V_97 ;
V_3 -> V_81 = V_81 ;
V_3 -> V_110 = F_84 ( NULL , V_174 -> V_105 ) ;
if ( F_85 ( V_3 -> V_110 ) ) {
F_51 ( & V_162 -> V_5 , L_13 ,
V_174 -> V_105 ) ;
continue;
}
F_86 ( & V_3 -> V_85 ) ;
F_59 ( & V_3 -> V_9 ) ;
F_59 ( & V_3 -> V_89 ) ;
F_59 ( & V_3 -> V_87 ) ;
F_87 ( & V_3 -> V_101 , F_44 ,
( unsigned long ) V_3 ) ;
F_7 ( & V_3 -> V_4 . V_176 ,
& V_167 -> V_172 ) ;
}
F_88 ( V_167 -> V_177 ) ;
F_89 ( V_178 , V_167 -> V_177 ) ;
F_89 ( V_179 , V_167 -> V_177 ) ;
V_167 -> V_5 = & V_162 -> V_5 ;
V_167 -> V_180 = F_54 ;
V_167 -> V_181 = F_63 ;
V_167 -> V_182 = F_67 ;
V_167 -> V_183 = F_71 ;
V_167 -> V_184 = F_76 ;
V_167 -> V_185 = F_80 ;
V_167 -> V_186 = F_77 ;
F_90 ( V_167 -> V_5 , V_127 ) ;
if ( V_81 -> V_107 ) {
F_89 ( V_187 , V_167 -> V_177 ) ;
V_167 -> V_188 = F_65 ;
V_81 -> V_112 = F_26 ;
V_81 -> V_118 = F_27 ;
V_81 -> V_82 = F_29 ;
V_81 -> V_100 = F_30 ;
} else {
F_89 ( V_189 , V_167 -> V_177 ) ;
V_81 -> V_112 = F_17 ;
V_81 -> V_118 = F_19 ;
V_81 -> V_82 = F_23 ;
V_81 -> V_100 = F_24 ;
}
V_84 = F_91 ( V_167 ) ;
if ( F_92 ( V_84 ) ) {
for ( V_106 = 0 ; V_106 < V_81 -> V_169 ; V_106 ++ ) {
struct V_2 * V_3 = & V_81 -> V_172 [ V_106 ] ;
if ( ! F_93 ( V_3 -> V_110 ) )
F_94 ( V_3 -> V_110 ) ;
}
F_64 ( V_81 ) ;
} else {
F_95 ( V_167 -> V_5 , L_14 ,
V_81 -> V_107 ? L_15 : L_16 ) ;
}
return V_84 ;
}
static int T_7 F_96 ( void )
{
return F_97 ( & V_190 , F_81 ) ;
}
