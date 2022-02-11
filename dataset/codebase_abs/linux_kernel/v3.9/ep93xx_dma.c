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
if ( F_11 ( V_3 ) ) {
F_29 ( V_3 ) ;
V_19 |= V_77 ;
}
V_19 |= V_78 ;
F_15 ( V_19 , V_3 -> V_20 + V_53 ) ;
if ( ! V_23 ) {
V_19 |= V_79 ;
F_15 ( V_19 , V_3 -> V_20 + V_53 ) ;
}
}
static int F_31 ( struct V_2 * V_3 )
{
T_1 V_80 = F_16 ( V_3 -> V_20 + V_81 ) ;
T_1 V_82 = V_80 & V_83 ;
T_1 V_84 = V_80 & V_85 ;
bool V_86 = V_80 & V_87 ;
bool V_88 ;
T_1 V_19 ;
struct V_7 * V_8 ;
if ( ! ( F_16 ( V_3 -> V_20 + V_89 ) & V_90 ) )
return V_52 ;
if ( V_86 ) {
F_15 ( 0 , V_3 -> V_20 + V_89 ) ;
}
V_8 = F_10 ( V_3 ) ;
V_88 = ! V_8 || V_8 -> V_13 . V_18 ;
if ( ! V_88 &&
( V_84 == V_91 ||
V_84 == V_92 ) ) {
if ( F_11 ( V_3 ) ) {
F_29 ( V_3 ) ;
if ( V_86 && ! V_3 -> V_4 . V_24 ) {
V_19 = F_16 ( V_3 -> V_20 + V_53 ) ;
V_19 |= V_79 ;
F_15 ( V_19 , V_3 -> V_20 + V_53 ) ;
}
return V_51 ;
} else {
V_88 = true ;
}
}
if ( V_88 &&
V_84 == V_91 &&
V_82 == V_93 ) {
V_19 = F_16 ( V_3 -> V_20 + V_53 ) ;
V_19 &= ~ ( V_76 | V_77
| V_78 ) ;
F_15 ( V_19 , V_3 -> V_20 + V_53 ) ;
return V_50 ;
}
return V_51 ;
}
static struct V_7 *
F_32 ( struct V_2 * V_3 )
{
struct V_7 * V_8 , * V_94 ;
struct V_7 * V_95 = NULL ;
unsigned long V_17 ;
F_33 ( & V_3 -> V_96 , V_17 ) ;
F_34 (desc, _desc, &edmac->free_list, node) {
if ( F_35 ( & V_8 -> V_13 ) ) {
F_36 ( & V_8 -> V_10 ) ;
V_8 -> V_37 = 0 ;
V_8 -> V_38 = 0 ;
V_8 -> V_40 = 0 ;
V_8 -> V_97 = false ;
V_8 -> V_13 . V_18 = 0 ;
V_8 -> V_13 . V_14 = NULL ;
V_8 -> V_13 . V_15 = NULL ;
V_95 = V_8 ;
break;
}
}
F_37 ( & V_3 -> V_96 , V_17 ) ;
return V_95 ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
if ( V_8 ) {
unsigned long V_17 ;
F_33 ( & V_3 -> V_96 , V_17 ) ;
F_39 ( & V_8 -> V_11 , & V_3 -> V_98 ) ;
F_40 ( & V_8 -> V_10 , & V_3 -> V_98 ) ;
F_37 ( & V_3 -> V_96 , V_17 ) ;
}
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_7 * V_99 ;
unsigned long V_17 ;
F_33 ( & V_3 -> V_96 , V_17 ) ;
if ( ! F_6 ( & V_3 -> V_9 ) || F_6 ( & V_3 -> V_100 ) ) {
F_37 ( & V_3 -> V_96 , V_17 ) ;
return;
}
V_99 = F_8 ( & V_3 -> V_100 , struct V_7 , V_10 ) ;
F_36 ( & V_99 -> V_10 ) ;
F_4 ( V_3 , V_99 ) ;
V_3 -> V_101 -> V_102 ( V_3 ) ;
F_37 ( & V_3 -> V_96 , V_17 ) ;
}
static void F_42 ( struct V_7 * V_8 )
{
struct V_1 * V_5 = V_8 -> V_13 . V_4 -> V_1 -> V_5 ;
if ( ! ( V_8 -> V_13 . V_17 & V_103 ) ) {
if ( V_8 -> V_13 . V_17 & V_104 )
F_43 ( V_5 , V_8 -> V_37 , V_8 -> V_40 ,
V_105 ) ;
else
F_44 ( V_5 , V_8 -> V_37 , V_8 -> V_40 ,
V_105 ) ;
}
if ( ! ( V_8 -> V_13 . V_17 & V_106 ) ) {
if ( V_8 -> V_13 . V_17 & V_107 )
F_43 ( V_5 , V_8 -> V_38 , V_8 -> V_40 ,
V_108 ) ;
else
F_44 ( V_5 , V_8 -> V_38 , V_8 -> V_40 ,
V_108 ) ;
}
}
static void F_45 ( unsigned long V_23 )
{
struct V_2 * V_3 = (struct V_2 * ) V_23 ;
struct V_7 * V_8 , * V_12 ;
T_2 V_14 = NULL ;
void * V_15 = NULL ;
F_46 ( V_109 ) ;
F_47 ( & V_3 -> V_96 ) ;
V_8 = F_10 ( V_3 ) ;
if ( V_8 ) {
if ( V_8 -> V_97 ) {
if ( ! F_13 ( V_16 , & V_3 -> V_17 ) )
F_48 ( & V_8 -> V_13 ) ;
F_39 ( & V_3 -> V_9 , & V_109 ) ;
}
V_14 = V_8 -> V_13 . V_14 ;
V_15 = V_8 -> V_13 . V_15 ;
}
F_49 ( & V_3 -> V_96 ) ;
F_41 ( V_3 ) ;
F_34 (desc, d, &list, node) {
if ( ! V_3 -> V_4 . V_24 )
F_42 ( V_8 ) ;
F_38 ( V_3 , V_8 ) ;
}
if ( V_14 )
V_14 ( V_15 ) ;
}
static T_3 F_50 ( int V_110 , void * V_111 )
{
struct V_2 * V_3 = V_111 ;
struct V_7 * V_8 ;
T_3 V_95 = V_112 ;
F_51 ( & V_3 -> V_96 ) ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) ,
L_8 ) ;
F_52 ( & V_3 -> V_96 ) ;
return V_113 ;
}
switch ( V_3 -> V_101 -> V_114 ( V_3 ) ) {
case V_50 :
V_8 -> V_97 = true ;
F_53 ( & V_3 -> V_115 ) ;
break;
case V_51 :
if ( F_13 ( V_16 , & V_3 -> V_17 ) )
F_53 ( & V_3 -> V_115 ) ;
break;
default:
F_22 ( F_1 ( V_3 ) , L_9 ) ;
V_95 = V_113 ;
break;
}
F_52 ( & V_3 -> V_96 ) ;
return V_95 ;
}
static T_4 F_54 ( struct V_116 * V_117 )
{
struct V_2 * V_3 = F_2 ( V_117 -> V_4 ) ;
struct V_7 * V_8 ;
T_4 V_18 ;
unsigned long V_17 ;
F_33 ( & V_3 -> V_96 , V_17 ) ;
V_18 = F_55 ( V_117 ) ;
V_8 = F_3 ( V_117 , struct V_7 , V_13 ) ;
if ( F_6 ( & V_3 -> V_9 ) ) {
F_4 ( V_3 , V_8 ) ;
V_3 -> V_101 -> V_102 ( V_3 ) ;
} else {
F_7 ( & V_8 -> V_10 , & V_3 -> V_100 ) ;
}
F_37 ( & V_3 -> V_96 , V_17 ) ;
return V_18 ;
}
static int F_56 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_22 * V_23 = V_4 -> V_24 ;
const char * V_118 = F_57 ( V_4 ) ;
int V_95 , V_119 ;
if ( ! V_3 -> V_101 -> V_120 ) {
if ( ! V_23 )
return - V_67 ;
if ( V_23 -> V_25 < V_121 ||
V_23 -> V_25 > V_122 )
return - V_67 ;
if ( V_23 -> V_57 != F_23 ( V_4 ) )
return - V_67 ;
} else {
if ( V_23 ) {
switch ( V_23 -> V_25 ) {
case V_54 :
case V_64 :
if ( ! F_58 ( V_23 -> V_57 ) )
return - V_67 ;
break;
default:
return - V_67 ;
}
}
}
if ( V_23 && V_23 -> V_118 )
V_118 = V_23 -> V_118 ;
V_95 = F_59 ( V_3 -> V_123 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_60 ( V_3 -> V_110 , F_50 , 0 , V_118 , V_3 ) ;
if ( V_95 )
goto V_124;
F_47 ( & V_3 -> V_96 ) ;
F_61 ( & V_3 -> V_4 ) ;
V_95 = V_3 -> V_101 -> V_125 ( V_3 ) ;
F_49 ( & V_3 -> V_96 ) ;
if ( V_95 )
goto V_126;
for ( V_119 = 0 ; V_119 < V_127 ; V_119 ++ ) {
struct V_7 * V_8 ;
V_8 = F_62 ( sizeof( * V_8 ) , V_128 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_10 ) ;
break;
}
F_63 ( & V_8 -> V_11 ) ;
F_64 ( & V_8 -> V_13 , V_4 ) ;
V_8 -> V_13 . V_17 = V_129 ;
V_8 -> V_13 . V_130 = F_54 ;
F_38 ( V_3 , V_8 ) ;
}
return V_119 ;
V_126:
F_65 ( V_3 -> V_110 , V_3 ) ;
V_124:
F_66 ( V_3 -> V_123 ) ;
return V_95 ;
}
static void F_67 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_12 ;
unsigned long V_17 ;
F_46 ( V_109 ) ;
F_5 ( ! F_6 ( & V_3 -> V_9 ) ) ;
F_5 ( ! F_6 ( & V_3 -> V_100 ) ) ;
F_33 ( & V_3 -> V_96 , V_17 ) ;
V_3 -> V_101 -> V_131 ( V_3 ) ;
V_3 -> V_132 = 0 ;
V_3 -> V_75 = 0 ;
V_3 -> V_39 = 0 ;
F_39 ( & V_3 -> V_98 , & V_109 ) ;
F_37 ( & V_3 -> V_96 , V_17 ) ;
F_34 (desc, d, &list, node)
F_68 ( V_8 ) ;
F_66 ( V_3 -> V_123 ) ;
F_65 ( V_3 -> V_110 , V_3 ) ;
}
static struct V_116 *
F_69 ( struct V_6 * V_4 , T_5 V_133 ,
T_5 V_134 , T_6 V_135 , unsigned long V_17 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_136 ;
T_6 V_137 , V_138 ;
V_136 = NULL ;
for ( V_138 = 0 ; V_138 < V_135 ; V_138 += V_137 ) {
V_8 = F_32 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_11 ) ;
goto V_139;
}
V_137 = F_70 ( T_6 , V_135 - V_138 , V_140 ) ;
V_8 -> V_37 = V_134 + V_138 ;
V_8 -> V_38 = V_133 + V_138 ;
V_8 -> V_40 = V_137 ;
if ( ! V_136 )
V_136 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_136 -> V_11 ) ;
}
V_136 -> V_13 . V_18 = - V_141 ;
V_136 -> V_13 . V_17 = V_17 ;
return & V_136 -> V_13 ;
V_139:
F_38 ( V_3 , V_136 ) ;
return NULL ;
}
static struct V_116 *
F_71 ( struct V_6 * V_4 , struct V_142 * V_143 ,
unsigned int V_144 , enum V_145 V_146 ,
unsigned long V_17 , void * V_147 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_136 ;
struct V_142 * V_148 ;
int V_119 ;
if ( ! V_3 -> V_101 -> V_120 && V_146 != F_23 ( V_4 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_12 ) ;
return NULL ;
}
if ( F_13 ( V_16 , & V_3 -> V_17 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_13 ) ;
return NULL ;
}
V_136 = NULL ;
F_72 (sgl, sg, sg_len, i) {
T_6 V_144 = F_73 ( V_148 ) ;
if ( V_144 > V_140 ) {
F_22 ( F_1 ( V_3 ) , L_14 ,
V_144 ) ;
goto V_139;
}
V_8 = F_32 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_11 ) ;
goto V_139;
}
if ( V_146 == V_36 ) {
V_8 -> V_37 = F_74 ( V_148 ) ;
V_8 -> V_38 = V_3 -> V_132 ;
} else {
V_8 -> V_37 = V_3 -> V_132 ;
V_8 -> V_38 = F_74 ( V_148 ) ;
}
V_8 -> V_40 = V_144 ;
if ( ! V_136 )
V_136 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_136 -> V_11 ) ;
}
V_136 -> V_13 . V_18 = - V_141 ;
V_136 -> V_13 . V_17 = V_17 ;
return & V_136 -> V_13 ;
V_139:
F_38 ( V_3 , V_136 ) ;
return NULL ;
}
static struct V_116 *
F_75 ( struct V_6 * V_4 , T_5 V_149 ,
T_6 V_150 , T_6 V_151 ,
enum V_145 V_146 , unsigned long V_17 ,
void * V_147 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_136 ;
T_6 V_138 = 0 ;
if ( ! V_3 -> V_101 -> V_120 && V_146 != F_23 ( V_4 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_12 ) ;
return NULL ;
}
if ( F_76 ( V_16 , & V_3 -> V_17 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_13 ) ;
return NULL ;
}
if ( V_151 > V_140 ) {
F_22 ( F_1 ( V_3 ) , L_15 ,
V_151 ) ;
return NULL ;
}
V_136 = NULL ;
for ( V_138 = 0 ; V_138 < V_150 ; V_138 += V_151 ) {
V_8 = F_32 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_11 ) ;
goto V_139;
}
if ( V_146 == V_36 ) {
V_8 -> V_37 = V_149 + V_138 ;
V_8 -> V_38 = V_3 -> V_132 ;
} else {
V_8 -> V_37 = V_3 -> V_132 ;
V_8 -> V_38 = V_149 + V_138 ;
}
V_8 -> V_40 = V_151 ;
if ( ! V_136 )
V_136 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_136 -> V_11 ) ;
}
V_136 -> V_13 . V_18 = - V_141 ;
return & V_136 -> V_13 ;
V_139:
F_38 ( V_3 , V_136 ) ;
return NULL ;
}
static int F_77 ( struct V_2 * V_3 )
{
struct V_7 * V_8 , * V_152 ;
unsigned long V_17 ;
F_46 ( V_109 ) ;
F_33 ( & V_3 -> V_96 , V_17 ) ;
V_3 -> V_101 -> V_131 ( V_3 ) ;
F_78 ( V_16 , & V_3 -> V_17 ) ;
F_39 ( & V_3 -> V_9 , & V_109 ) ;
F_39 ( & V_3 -> V_100 , & V_109 ) ;
V_3 -> V_101 -> V_125 ( V_3 ) ;
F_37 ( & V_3 -> V_96 , V_17 ) ;
F_34 (desc, _d, &list, node)
F_38 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_79 ( struct V_2 * V_3 ,
struct V_153 * V_154 )
{
enum V_155 V_156 ;
unsigned long V_17 ;
T_1 V_157 , V_158 ;
if ( ! V_3 -> V_101 -> V_120 )
return - V_67 ;
switch ( V_154 -> V_57 ) {
case V_159 :
V_156 = V_154 -> V_160 ;
V_157 = V_154 -> V_37 ;
break;
case V_36 :
V_156 = V_154 -> V_161 ;
V_157 = V_154 -> V_38 ;
break;
default:
return - V_67 ;
}
switch ( V_156 ) {
case V_162 :
V_158 = 0 ;
break;
case V_163 :
V_158 = V_66 ;
break;
case V_164 :
V_158 = V_165 ;
break;
default:
return - V_67 ;
}
F_33 ( & V_3 -> V_96 , V_17 ) ;
V_3 -> V_132 = V_157 ;
V_3 -> V_75 = V_158 ;
F_37 ( & V_3 -> V_96 , V_17 ) ;
return 0 ;
}
static int F_80 ( struct V_6 * V_4 , enum V_166 V_167 ,
unsigned long V_168 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_153 * V_154 ;
switch ( V_167 ) {
case V_169 :
return F_77 ( V_3 ) ;
case V_170 :
V_154 = (struct V_153 * ) V_168 ;
return F_79 ( V_3 , V_154 ) ;
default:
break;
}
return - V_171 ;
}
static enum V_172 F_81 ( struct V_6 * V_4 ,
T_4 V_18 ,
struct V_173 * V_174 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
enum V_172 V_95 ;
unsigned long V_17 ;
F_33 ( & V_3 -> V_96 , V_17 ) ;
V_95 = F_82 ( V_4 , V_18 , V_174 ) ;
F_37 ( & V_3 -> V_96 , V_17 ) ;
return V_95 ;
}
static void F_83 ( struct V_6 * V_4 )
{
F_41 ( F_2 ( V_4 ) ) ;
}
static int T_7 F_84 ( struct V_175 * V_176 )
{
struct V_177 * V_178 = F_85 ( & V_176 -> V_5 ) ;
struct V_179 * V_101 ;
struct V_180 * V_181 ;
T_6 V_182 ;
int V_95 , V_119 ;
V_182 = V_178 -> V_183 * sizeof( struct V_2 ) ;
V_101 = F_62 ( sizeof( * V_101 ) + V_182 , V_128 ) ;
if ( ! V_101 )
return - V_184 ;
V_181 = & V_101 -> V_181 ;
V_101 -> V_120 = F_86 ( V_176 ) -> V_185 ;
V_101 -> V_183 = V_178 -> V_183 ;
F_63 ( & V_181 -> V_186 ) ;
for ( V_119 = 0 ; V_119 < V_178 -> V_183 ; V_119 ++ ) {
const struct V_187 * V_188 = & V_178 -> V_186 [ V_119 ] ;
struct V_2 * V_3 = & V_101 -> V_186 [ V_119 ] ;
V_3 -> V_4 . V_1 = V_181 ;
V_3 -> V_20 = V_188 -> V_189 ;
V_3 -> V_110 = V_188 -> V_110 ;
V_3 -> V_101 = V_101 ;
V_3 -> V_123 = F_87 ( NULL , V_188 -> V_118 ) ;
if ( F_88 ( V_3 -> V_123 ) ) {
F_22 ( & V_176 -> V_5 , L_16 ,
V_188 -> V_118 ) ;
continue;
}
F_89 ( & V_3 -> V_96 ) ;
F_63 ( & V_3 -> V_9 ) ;
F_63 ( & V_3 -> V_100 ) ;
F_63 ( & V_3 -> V_98 ) ;
F_90 ( & V_3 -> V_115 , F_45 ,
( unsigned long ) V_3 ) ;
F_7 ( & V_3 -> V_4 . V_190 ,
& V_181 -> V_186 ) ;
}
F_91 ( V_181 -> V_191 ) ;
F_92 ( V_192 , V_181 -> V_191 ) ;
F_92 ( V_193 , V_181 -> V_191 ) ;
V_181 -> V_5 = & V_176 -> V_5 ;
V_181 -> V_194 = F_56 ;
V_181 -> V_195 = F_67 ;
V_181 -> V_196 = F_71 ;
V_181 -> V_197 = F_75 ;
V_181 -> V_198 = F_80 ;
V_181 -> V_199 = F_83 ;
V_181 -> V_200 = F_81 ;
F_93 ( V_181 -> V_5 , V_140 ) ;
if ( V_101 -> V_120 ) {
F_92 ( V_201 , V_181 -> V_191 ) ;
V_181 -> V_202 = F_69 ;
V_101 -> V_125 = F_27 ;
V_101 -> V_131 = F_28 ;
V_101 -> V_102 = F_30 ;
V_101 -> V_114 = F_31 ;
} else {
F_92 ( V_203 , V_181 -> V_191 ) ;
V_101 -> V_125 = F_17 ;
V_101 -> V_131 = F_19 ;
V_101 -> V_102 = F_24 ;
V_101 -> V_114 = F_25 ;
}
V_95 = F_94 ( V_181 ) ;
if ( F_95 ( V_95 ) ) {
for ( V_119 = 0 ; V_119 < V_101 -> V_183 ; V_119 ++ ) {
struct V_2 * V_3 = & V_101 -> V_186 [ V_119 ] ;
if ( ! F_96 ( V_3 -> V_123 ) )
F_97 ( V_3 -> V_123 ) ;
}
F_68 ( V_101 ) ;
} else {
F_98 ( V_181 -> V_5 , L_17 ,
V_101 -> V_120 ? L_18 : L_19 ) ;
}
return V_95 ;
}
static int T_7 F_99 ( void )
{
return F_100 ( & V_204 , F_84 ) ;
}
