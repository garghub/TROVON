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
static void F_42 ( unsigned long V_23 )
{
struct V_2 * V_3 = (struct V_2 * ) V_23 ;
struct V_7 * V_8 , * V_12 ;
T_2 V_14 = NULL ;
void * V_15 = NULL ;
F_43 ( V_103 ) ;
F_44 ( & V_3 -> V_96 ) ;
V_8 = F_10 ( V_3 ) ;
if ( V_8 ) {
if ( V_8 -> V_97 ) {
if ( ! F_13 ( V_16 , & V_3 -> V_17 ) )
F_45 ( & V_8 -> V_13 ) ;
F_39 ( & V_3 -> V_9 , & V_103 ) ;
}
V_14 = V_8 -> V_13 . V_14 ;
V_15 = V_8 -> V_13 . V_15 ;
}
F_46 ( & V_3 -> V_96 ) ;
F_41 ( V_3 ) ;
F_34 (desc, d, &list, node) {
F_47 ( & V_8 -> V_13 ) ;
F_38 ( V_3 , V_8 ) ;
}
if ( V_14 )
V_14 ( V_15 ) ;
}
static T_3 F_48 ( int V_104 , void * V_105 )
{
struct V_2 * V_3 = V_105 ;
struct V_7 * V_8 ;
T_3 V_95 = V_106 ;
F_49 ( & V_3 -> V_96 ) ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) ,
L_8 ) ;
F_50 ( & V_3 -> V_96 ) ;
return V_107 ;
}
switch ( V_3 -> V_101 -> V_108 ( V_3 ) ) {
case V_50 :
V_8 -> V_97 = true ;
F_51 ( & V_3 -> V_109 ) ;
break;
case V_51 :
if ( F_13 ( V_16 , & V_3 -> V_17 ) )
F_51 ( & V_3 -> V_109 ) ;
break;
default:
F_22 ( F_1 ( V_3 ) , L_9 ) ;
V_95 = V_107 ;
break;
}
F_50 ( & V_3 -> V_96 ) ;
return V_95 ;
}
static T_4 F_52 ( struct V_110 * V_111 )
{
struct V_2 * V_3 = F_2 ( V_111 -> V_4 ) ;
struct V_7 * V_8 ;
T_4 V_18 ;
unsigned long V_17 ;
F_33 ( & V_3 -> V_96 , V_17 ) ;
V_18 = F_53 ( V_111 ) ;
V_8 = F_3 ( V_111 , struct V_7 , V_13 ) ;
if ( F_6 ( & V_3 -> V_9 ) ) {
F_4 ( V_3 , V_8 ) ;
V_3 -> V_101 -> V_102 ( V_3 ) ;
} else {
F_7 ( & V_8 -> V_10 , & V_3 -> V_100 ) ;
}
F_37 ( & V_3 -> V_96 , V_17 ) ;
return V_18 ;
}
static int F_54 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_22 * V_23 = V_4 -> V_24 ;
const char * V_112 = F_55 ( V_4 ) ;
int V_95 , V_113 ;
if ( ! V_3 -> V_101 -> V_114 ) {
if ( ! V_23 )
return - V_67 ;
if ( V_23 -> V_25 < V_115 ||
V_23 -> V_25 > V_116 )
return - V_67 ;
if ( V_23 -> V_57 != F_23 ( V_4 ) )
return - V_67 ;
} else {
if ( V_23 ) {
switch ( V_23 -> V_25 ) {
case V_54 :
case V_64 :
if ( ! F_56 ( V_23 -> V_57 ) )
return - V_67 ;
break;
default:
return - V_67 ;
}
}
}
if ( V_23 && V_23 -> V_112 )
V_112 = V_23 -> V_112 ;
V_95 = F_57 ( V_3 -> V_117 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_58 ( V_3 -> V_104 , F_48 , 0 , V_112 , V_3 ) ;
if ( V_95 )
goto V_118;
F_44 ( & V_3 -> V_96 ) ;
F_59 ( & V_3 -> V_4 ) ;
V_95 = V_3 -> V_101 -> V_119 ( V_3 ) ;
F_46 ( & V_3 -> V_96 ) ;
if ( V_95 )
goto V_120;
for ( V_113 = 0 ; V_113 < V_121 ; V_113 ++ ) {
struct V_7 * V_8 ;
V_8 = F_60 ( sizeof( * V_8 ) , V_122 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_10 ) ;
break;
}
F_61 ( & V_8 -> V_11 ) ;
F_62 ( & V_8 -> V_13 , V_4 ) ;
V_8 -> V_13 . V_17 = V_123 ;
V_8 -> V_13 . V_124 = F_52 ;
F_38 ( V_3 , V_8 ) ;
}
return V_113 ;
V_120:
F_63 ( V_3 -> V_104 , V_3 ) ;
V_118:
F_64 ( V_3 -> V_117 ) ;
return V_95 ;
}
static void F_65 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_12 ;
unsigned long V_17 ;
F_43 ( V_103 ) ;
F_5 ( ! F_6 ( & V_3 -> V_9 ) ) ;
F_5 ( ! F_6 ( & V_3 -> V_100 ) ) ;
F_33 ( & V_3 -> V_96 , V_17 ) ;
V_3 -> V_101 -> V_125 ( V_3 ) ;
V_3 -> V_126 = 0 ;
V_3 -> V_75 = 0 ;
V_3 -> V_39 = 0 ;
F_39 ( & V_3 -> V_98 , & V_103 ) ;
F_37 ( & V_3 -> V_96 , V_17 ) ;
F_34 (desc, d, &list, node)
F_66 ( V_8 ) ;
F_64 ( V_3 -> V_117 ) ;
F_63 ( V_3 -> V_104 , V_3 ) ;
}
static struct V_110 *
F_67 ( struct V_6 * V_4 , T_5 V_127 ,
T_5 V_128 , T_6 V_129 , unsigned long V_17 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_130 ;
T_6 V_131 , V_132 ;
V_130 = NULL ;
for ( V_132 = 0 ; V_132 < V_129 ; V_132 += V_131 ) {
V_8 = F_32 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_11 ) ;
goto V_133;
}
V_131 = F_68 ( T_6 , V_129 - V_132 , V_134 ) ;
V_8 -> V_37 = V_128 + V_132 ;
V_8 -> V_38 = V_127 + V_132 ;
V_8 -> V_40 = V_131 ;
if ( ! V_130 )
V_130 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_130 -> V_11 ) ;
}
V_130 -> V_13 . V_18 = - V_135 ;
V_130 -> V_13 . V_17 = V_17 ;
return & V_130 -> V_13 ;
V_133:
F_38 ( V_3 , V_130 ) ;
return NULL ;
}
static struct V_110 *
F_69 ( struct V_6 * V_4 , struct V_136 * V_137 ,
unsigned int V_138 , enum V_139 V_140 ,
unsigned long V_17 , void * V_141 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_130 ;
struct V_136 * V_142 ;
int V_113 ;
if ( ! V_3 -> V_101 -> V_114 && V_140 != F_23 ( V_4 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_12 ) ;
return NULL ;
}
if ( F_13 ( V_16 , & V_3 -> V_17 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_13 ) ;
return NULL ;
}
V_130 = NULL ;
F_70 (sgl, sg, sg_len, i) {
T_6 V_138 = F_71 ( V_142 ) ;
if ( V_138 > V_134 ) {
F_22 ( F_1 ( V_3 ) , L_14 ,
V_138 ) ;
goto V_133;
}
V_8 = F_32 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_11 ) ;
goto V_133;
}
if ( V_140 == V_36 ) {
V_8 -> V_37 = F_72 ( V_142 ) ;
V_8 -> V_38 = V_3 -> V_126 ;
} else {
V_8 -> V_37 = V_3 -> V_126 ;
V_8 -> V_38 = F_72 ( V_142 ) ;
}
V_8 -> V_40 = V_138 ;
if ( ! V_130 )
V_130 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_130 -> V_11 ) ;
}
V_130 -> V_13 . V_18 = - V_135 ;
V_130 -> V_13 . V_17 = V_17 ;
return & V_130 -> V_13 ;
V_133:
F_38 ( V_3 , V_130 ) ;
return NULL ;
}
static struct V_110 *
F_73 ( struct V_6 * V_4 , T_5 V_143 ,
T_6 V_144 , T_6 V_145 ,
enum V_139 V_140 , unsigned long V_17 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_130 ;
T_6 V_132 = 0 ;
if ( ! V_3 -> V_101 -> V_114 && V_140 != F_23 ( V_4 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_12 ) ;
return NULL ;
}
if ( F_74 ( V_16 , & V_3 -> V_17 ) ) {
F_22 ( F_1 ( V_3 ) ,
L_13 ) ;
return NULL ;
}
if ( V_145 > V_134 ) {
F_22 ( F_1 ( V_3 ) , L_15 ,
V_145 ) ;
return NULL ;
}
V_130 = NULL ;
for ( V_132 = 0 ; V_132 < V_144 ; V_132 += V_145 ) {
V_8 = F_32 ( V_3 ) ;
if ( ! V_8 ) {
F_22 ( F_1 ( V_3 ) , L_11 ) ;
goto V_133;
}
if ( V_140 == V_36 ) {
V_8 -> V_37 = V_143 + V_132 ;
V_8 -> V_38 = V_3 -> V_126 ;
} else {
V_8 -> V_37 = V_3 -> V_126 ;
V_8 -> V_38 = V_143 + V_132 ;
}
V_8 -> V_40 = V_145 ;
if ( ! V_130 )
V_130 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_130 -> V_11 ) ;
}
V_130 -> V_13 . V_18 = - V_135 ;
return & V_130 -> V_13 ;
V_133:
F_38 ( V_3 , V_130 ) ;
return NULL ;
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_7 * V_8 , * V_146 ;
unsigned long V_17 ;
F_43 ( V_103 ) ;
F_33 ( & V_3 -> V_96 , V_17 ) ;
V_3 -> V_101 -> V_125 ( V_3 ) ;
F_76 ( V_16 , & V_3 -> V_17 ) ;
F_39 ( & V_3 -> V_9 , & V_103 ) ;
F_39 ( & V_3 -> V_100 , & V_103 ) ;
V_3 -> V_101 -> V_119 ( V_3 ) ;
F_37 ( & V_3 -> V_96 , V_17 ) ;
F_34 (desc, _d, &list, node)
F_38 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_77 ( struct V_2 * V_3 ,
struct V_147 * V_148 )
{
enum V_149 V_150 ;
unsigned long V_17 ;
T_1 V_151 , V_152 ;
if ( ! V_3 -> V_101 -> V_114 )
return - V_67 ;
switch ( V_148 -> V_57 ) {
case V_153 :
V_150 = V_148 -> V_154 ;
V_151 = V_148 -> V_37 ;
break;
case V_36 :
V_150 = V_148 -> V_155 ;
V_151 = V_148 -> V_38 ;
break;
default:
return - V_67 ;
}
switch ( V_150 ) {
case V_156 :
V_152 = 0 ;
break;
case V_157 :
V_152 = V_66 ;
break;
case V_158 :
V_152 = V_159 ;
break;
default:
return - V_67 ;
}
F_33 ( & V_3 -> V_96 , V_17 ) ;
V_3 -> V_126 = V_151 ;
V_3 -> V_75 = V_152 ;
F_37 ( & V_3 -> V_96 , V_17 ) ;
return 0 ;
}
static int F_78 ( struct V_6 * V_4 , enum V_160 V_161 ,
unsigned long V_162 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_147 * V_148 ;
switch ( V_161 ) {
case V_163 :
return F_75 ( V_3 ) ;
case V_164 :
V_148 = (struct V_147 * ) V_162 ;
return F_77 ( V_3 , V_148 ) ;
default:
break;
}
return - V_165 ;
}
static enum V_166 F_79 ( struct V_6 * V_4 ,
T_4 V_18 ,
struct V_167 * V_168 )
{
return F_80 ( V_4 , V_18 , V_168 ) ;
}
static void F_81 ( struct V_6 * V_4 )
{
F_41 ( F_2 ( V_4 ) ) ;
}
static int T_7 F_82 ( struct V_169 * V_170 )
{
struct V_171 * V_172 = F_83 ( & V_170 -> V_5 ) ;
struct V_173 * V_101 ;
struct V_174 * V_175 ;
T_6 V_176 ;
int V_95 , V_113 ;
V_176 = V_172 -> V_177 * sizeof( struct V_2 ) ;
V_101 = F_60 ( sizeof( * V_101 ) + V_176 , V_122 ) ;
if ( ! V_101 )
return - V_178 ;
V_175 = & V_101 -> V_175 ;
V_101 -> V_114 = F_84 ( V_170 ) -> V_179 ;
V_101 -> V_177 = V_172 -> V_177 ;
F_61 ( & V_175 -> V_180 ) ;
for ( V_113 = 0 ; V_113 < V_172 -> V_177 ; V_113 ++ ) {
const struct V_181 * V_182 = & V_172 -> V_180 [ V_113 ] ;
struct V_2 * V_3 = & V_101 -> V_180 [ V_113 ] ;
V_3 -> V_4 . V_1 = V_175 ;
V_3 -> V_20 = V_182 -> V_183 ;
V_3 -> V_104 = V_182 -> V_104 ;
V_3 -> V_101 = V_101 ;
V_3 -> V_117 = F_85 ( NULL , V_182 -> V_112 ) ;
if ( F_86 ( V_3 -> V_117 ) ) {
F_22 ( & V_170 -> V_5 , L_16 ,
V_182 -> V_112 ) ;
continue;
}
F_87 ( & V_3 -> V_96 ) ;
F_61 ( & V_3 -> V_9 ) ;
F_61 ( & V_3 -> V_100 ) ;
F_61 ( & V_3 -> V_98 ) ;
F_88 ( & V_3 -> V_109 , F_42 ,
( unsigned long ) V_3 ) ;
F_7 ( & V_3 -> V_4 . V_184 ,
& V_175 -> V_180 ) ;
}
F_89 ( V_175 -> V_185 ) ;
F_90 ( V_186 , V_175 -> V_185 ) ;
F_90 ( V_187 , V_175 -> V_185 ) ;
V_175 -> V_5 = & V_170 -> V_5 ;
V_175 -> V_188 = F_54 ;
V_175 -> V_189 = F_65 ;
V_175 -> V_190 = F_69 ;
V_175 -> V_191 = F_73 ;
V_175 -> V_192 = F_78 ;
V_175 -> V_193 = F_81 ;
V_175 -> V_194 = F_79 ;
F_91 ( V_175 -> V_5 , V_134 ) ;
if ( V_101 -> V_114 ) {
F_90 ( V_195 , V_175 -> V_185 ) ;
V_175 -> V_196 = F_67 ;
V_101 -> V_119 = F_27 ;
V_101 -> V_125 = F_28 ;
V_101 -> V_102 = F_30 ;
V_101 -> V_108 = F_31 ;
} else {
F_90 ( V_197 , V_175 -> V_185 ) ;
V_101 -> V_119 = F_17 ;
V_101 -> V_125 = F_19 ;
V_101 -> V_102 = F_24 ;
V_101 -> V_108 = F_25 ;
}
V_95 = F_92 ( V_175 ) ;
if ( F_93 ( V_95 ) ) {
for ( V_113 = 0 ; V_113 < V_101 -> V_177 ; V_113 ++ ) {
struct V_2 * V_3 = & V_101 -> V_180 [ V_113 ] ;
if ( ! F_94 ( V_3 -> V_117 ) )
F_95 ( V_3 -> V_117 ) ;
}
F_66 ( V_101 ) ;
} else {
F_96 ( V_175 -> V_5 , L_17 ,
V_101 -> V_114 ? L_18 : L_19 ) ;
}
return V_95 ;
}
static int T_7 F_97 ( void )
{
return F_98 ( & V_198 , F_82 ) ;
}
