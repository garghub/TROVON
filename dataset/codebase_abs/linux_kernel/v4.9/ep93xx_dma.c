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
return F_11 ( & V_3 -> V_9 ,
struct V_7 , V_10 ) ;
}
static bool F_12 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
F_13 ( & V_3 -> V_9 ) ;
if ( F_14 ( V_16 , & V_3 -> V_17 ) )
return true ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 )
return false ;
return ! V_8 -> V_13 . V_18 ;
}
static void F_15 ( struct V_2 * V_3 , T_1 V_19 )
{
F_16 ( V_19 , V_3 -> V_20 + V_21 ) ;
F_17 ( V_3 -> V_20 + V_21 ) ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_4 . V_24 ;
T_1 V_19 ;
F_16 ( V_23 -> V_25 & 0xf , V_3 -> V_20 + V_26 ) ;
V_19 = V_27 | V_28
| V_29 ;
F_15 ( V_3 , V_19 ) ;
return 0 ;
}
static inline T_1 F_19 ( struct V_2 * V_3 )
{
return ( F_17 ( V_3 -> V_20 + V_30 ) >> 4 ) & 0x3 ;
}
static void F_20 ( struct V_2 * V_3 )
{
T_1 V_19 ;
V_19 = F_17 ( V_3 -> V_20 + V_21 ) ;
V_19 &= ~ ( V_31 | V_32 ) ;
F_15 ( V_3 , V_19 ) ;
while ( F_19 ( V_3 ) >= V_33 )
F_21 () ;
F_15 ( V_3 , 0 ) ;
while ( F_19 ( V_3 ) == V_34 )
F_21 () ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
T_1 V_35 ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 ) {
F_23 ( F_1 ( V_3 ) , L_1 ) ;
return;
}
if ( F_24 ( & V_3 -> V_4 ) == V_36 )
V_35 = V_8 -> V_37 ;
else
V_35 = V_8 -> V_38 ;
if ( V_3 -> V_39 == 0 ) {
F_16 ( V_8 -> V_40 , V_3 -> V_20 + V_41 ) ;
F_16 ( V_35 , V_3 -> V_20 + V_42 ) ;
} else {
F_16 ( V_8 -> V_40 , V_3 -> V_20 + V_43 ) ;
F_16 ( V_35 , V_3 -> V_20 + V_44 ) ;
}
V_3 -> V_39 ^= 1 ;
}
static void F_25 ( struct V_2 * V_3 )
{
T_1 V_19 = F_17 ( V_3 -> V_20 + V_21 ) ;
F_22 ( V_3 ) ;
V_19 |= V_31 ;
if ( F_12 ( V_3 ) ) {
F_22 ( V_3 ) ;
V_19 |= V_32 ;
}
F_15 ( V_3 , V_19 ) ;
}
static int F_26 ( struct V_2 * V_3 )
{
T_1 V_45 = F_17 ( V_3 -> V_20 + V_46 ) ;
T_1 V_19 ;
if ( V_45 & V_47 ) {
struct V_7 * V_8 = F_10 ( V_3 ) ;
F_16 ( 1 , V_3 -> V_20 + V_46 ) ;
F_27 ( F_1 ( V_3 ) ,
L_2
L_3
L_4
L_5
L_6 ,
V_8 -> V_13 . V_18 , V_8 -> V_37 , V_8 -> V_38 ,
V_8 -> V_40 ) ;
}
if ( ! ( V_45 & ( V_48 | V_49 ) ) )
return V_50 ;
if ( F_12 ( V_3 ) ) {
F_22 ( V_3 ) ;
return V_51 ;
}
V_19 = F_17 ( V_3 -> V_20 + V_21 ) ;
V_19 &= ~ ( V_31 | V_32 ) ;
F_15 ( V_3 , V_19 ) ;
return V_52 ;
}
static int F_28 ( struct V_2 * V_3 )
{
const struct V_22 * V_23 = V_3 -> V_4 . V_24 ;
T_1 V_19 = 0 ;
if ( ! V_23 ) {
F_16 ( V_19 , V_3 -> V_20 + V_53 ) ;
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
F_16 ( V_19 , V_3 -> V_20 + V_53 ) ;
return 0 ;
}
static void F_29 ( struct V_2 * V_3 )
{
F_16 ( 0 , V_3 -> V_20 + V_53 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 ) {
F_23 ( F_1 ( V_3 ) , L_7 ) ;
return;
}
if ( V_3 -> V_39 == 0 ) {
F_16 ( V_8 -> V_37 , V_3 -> V_20 + V_68 ) ;
F_16 ( V_8 -> V_38 , V_3 -> V_20 + V_69 ) ;
F_16 ( V_8 -> V_40 , V_3 -> V_20 + V_70 ) ;
} else {
F_16 ( V_8 -> V_37 , V_3 -> V_20 + V_71 ) ;
F_16 ( V_8 -> V_38 , V_3 -> V_20 + V_72 ) ;
F_16 ( V_8 -> V_40 , V_3 -> V_20 + V_73 ) ;
}
V_3 -> V_39 ^= 1 ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_4 . V_24 ;
T_1 V_19 = F_17 ( V_3 -> V_20 + V_53 ) ;
V_19 &= ~ V_74 ;
V_19 |= V_3 -> V_75 ;
F_30 ( V_3 ) ;
V_19 |= V_76 ;
if ( F_12 ( V_3 ) ) {
F_30 ( V_3 ) ;
V_19 |= V_77 ;
}
V_19 |= V_78 ;
F_16 ( V_19 , V_3 -> V_20 + V_53 ) ;
if ( ! V_23 ) {
V_19 |= V_79 ;
F_16 ( V_19 , V_3 -> V_20 + V_53 ) ;
}
}
static int F_32 ( struct V_2 * V_3 )
{
T_1 V_80 = F_17 ( V_3 -> V_20 + V_81 ) ;
T_1 V_82 = V_80 & V_83 ;
T_1 V_84 = V_80 & V_85 ;
bool V_86 = V_80 & V_87 ;
bool V_88 ;
T_1 V_19 ;
struct V_7 * V_8 ;
if ( ! ( F_17 ( V_3 -> V_20 + V_89 ) & V_90 ) )
return V_50 ;
if ( V_86 ) {
F_16 ( 0 , V_3 -> V_20 + V_89 ) ;
}
V_8 = F_10 ( V_3 ) ;
V_88 = ! V_8 || V_8 -> V_13 . V_18 ;
if ( ! V_88 &&
( V_84 == V_91 ||
V_84 == V_92 ) ) {
if ( F_12 ( V_3 ) ) {
F_30 ( V_3 ) ;
if ( V_86 && ! V_3 -> V_4 . V_24 ) {
V_19 = F_17 ( V_3 -> V_20 + V_53 ) ;
V_19 |= V_79 ;
F_16 ( V_19 , V_3 -> V_20 + V_53 ) ;
}
return V_51 ;
} else {
V_88 = true ;
}
}
if ( V_88 &&
V_84 == V_91 &&
V_82 == V_93 ) {
V_19 = F_17 ( V_3 -> V_20 + V_53 ) ;
V_19 &= ~ ( V_76 | V_77
| V_78 ) ;
F_16 ( V_19 , V_3 -> V_20 + V_53 ) ;
return V_52 ;
}
return V_51 ;
}
static struct V_7 *
F_33 ( struct V_2 * V_3 )
{
struct V_7 * V_8 , * V_94 ;
struct V_7 * V_95 = NULL ;
unsigned long V_17 ;
F_34 ( & V_3 -> V_96 , V_17 ) ;
F_35 (desc, _desc, &edmac->free_list, node) {
if ( F_36 ( & V_8 -> V_13 ) ) {
F_37 ( & V_8 -> V_10 ) ;
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
F_38 ( & V_3 -> V_96 , V_17 ) ;
return V_95 ;
}
static void F_39 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
if ( V_8 ) {
unsigned long V_17 ;
F_34 ( & V_3 -> V_96 , V_17 ) ;
F_40 ( & V_8 -> V_11 , & V_3 -> V_98 ) ;
F_41 ( & V_8 -> V_10 , & V_3 -> V_98 ) ;
F_38 ( & V_3 -> V_96 , V_17 ) ;
}
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_7 * V_99 ;
unsigned long V_17 ;
F_34 ( & V_3 -> V_96 , V_17 ) ;
if ( ! F_6 ( & V_3 -> V_9 ) || F_6 ( & V_3 -> V_100 ) ) {
F_38 ( & V_3 -> V_96 , V_17 ) ;
return;
}
V_99 = F_8 ( & V_3 -> V_100 , struct V_7 , V_10 ) ;
F_37 ( & V_99 -> V_10 ) ;
F_4 ( V_3 , V_99 ) ;
V_3 -> V_101 -> V_102 ( V_3 ) ;
F_38 ( & V_3 -> V_96 , V_17 ) ;
}
static void F_43 ( unsigned long V_23 )
{
struct V_2 * V_3 = (struct V_2 * ) V_23 ;
struct V_7 * V_8 , * V_12 ;
struct V_103 V_104 ;
F_44 ( V_105 ) ;
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
F_45 ( & V_3 -> V_96 ) ;
V_8 = F_10 ( V_3 ) ;
if ( V_8 ) {
if ( V_8 -> V_97 ) {
if ( ! F_14 ( V_16 , & V_3 -> V_17 ) )
F_46 ( & V_8 -> V_13 ) ;
F_40 ( & V_3 -> V_9 , & V_105 ) ;
}
F_47 ( & V_8 -> V_13 , & V_104 ) ;
}
F_48 ( & V_3 -> V_96 ) ;
F_42 ( V_3 ) ;
F_35 (desc, d, &list, node) {
F_49 ( & V_8 -> V_13 ) ;
F_39 ( V_3 , V_8 ) ;
}
F_50 ( & V_104 , NULL ) ;
}
static T_2 F_51 ( int V_106 , void * V_107 )
{
struct V_2 * V_3 = V_107 ;
struct V_7 * V_8 ;
T_2 V_95 = V_108 ;
F_52 ( & V_3 -> V_96 ) ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 ) {
F_23 ( F_1 ( V_3 ) ,
L_8 ) ;
F_53 ( & V_3 -> V_96 ) ;
return V_109 ;
}
switch ( V_3 -> V_101 -> V_110 ( V_3 ) ) {
case V_52 :
V_8 -> V_97 = true ;
F_54 ( & V_3 -> V_111 ) ;
break;
case V_51 :
if ( F_14 ( V_16 , & V_3 -> V_17 ) )
F_54 ( & V_3 -> V_111 ) ;
break;
default:
F_23 ( F_1 ( V_3 ) , L_9 ) ;
V_95 = V_109 ;
break;
}
F_53 ( & V_3 -> V_96 ) ;
return V_95 ;
}
static T_3 F_55 ( struct V_112 * V_113 )
{
struct V_2 * V_3 = F_2 ( V_113 -> V_4 ) ;
struct V_7 * V_8 ;
T_3 V_18 ;
unsigned long V_17 ;
F_34 ( & V_3 -> V_96 , V_17 ) ;
V_18 = F_56 ( V_113 ) ;
V_8 = F_3 ( V_113 , struct V_7 , V_13 ) ;
if ( F_6 ( & V_3 -> V_9 ) ) {
F_4 ( V_3 , V_8 ) ;
V_3 -> V_101 -> V_102 ( V_3 ) ;
} else {
F_7 ( & V_8 -> V_10 , & V_3 -> V_100 ) ;
}
F_38 ( & V_3 -> V_96 , V_17 ) ;
return V_18 ;
}
static int F_57 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_22 * V_23 = V_4 -> V_24 ;
const char * V_114 = F_58 ( V_4 ) ;
int V_95 , V_115 ;
if ( ! V_3 -> V_101 -> V_116 ) {
if ( ! V_23 )
return - V_67 ;
if ( V_23 -> V_25 < V_117 ||
V_23 -> V_25 > V_118 )
return - V_67 ;
if ( V_23 -> V_57 != F_24 ( V_4 ) )
return - V_67 ;
} else {
if ( V_23 ) {
switch ( V_23 -> V_25 ) {
case V_54 :
case V_64 :
if ( ! F_59 ( V_23 -> V_57 ) )
return - V_67 ;
break;
default:
return - V_67 ;
}
}
}
if ( V_23 && V_23 -> V_114 )
V_114 = V_23 -> V_114 ;
V_95 = F_60 ( V_3 -> V_119 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_61 ( V_3 -> V_106 , F_51 , 0 , V_114 , V_3 ) ;
if ( V_95 )
goto V_120;
F_45 ( & V_3 -> V_96 ) ;
F_62 ( & V_3 -> V_4 ) ;
V_95 = V_3 -> V_101 -> V_121 ( V_3 ) ;
F_48 ( & V_3 -> V_96 ) ;
if ( V_95 )
goto V_122;
for ( V_115 = 0 ; V_115 < V_123 ; V_115 ++ ) {
struct V_7 * V_8 ;
V_8 = F_63 ( sizeof( * V_8 ) , V_124 ) ;
if ( ! V_8 ) {
F_23 ( F_1 ( V_3 ) , L_10 ) ;
break;
}
F_64 ( & V_8 -> V_11 ) ;
F_65 ( & V_8 -> V_13 , V_4 ) ;
V_8 -> V_13 . V_17 = V_125 ;
V_8 -> V_13 . V_126 = F_55 ;
F_39 ( V_3 , V_8 ) ;
}
return V_115 ;
V_122:
F_66 ( V_3 -> V_106 , V_3 ) ;
V_120:
F_67 ( V_3 -> V_119 ) ;
return V_95 ;
}
static void F_68 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_12 ;
unsigned long V_17 ;
F_44 ( V_105 ) ;
F_5 ( ! F_6 ( & V_3 -> V_9 ) ) ;
F_5 ( ! F_6 ( & V_3 -> V_100 ) ) ;
F_34 ( & V_3 -> V_96 , V_17 ) ;
V_3 -> V_101 -> V_127 ( V_3 ) ;
V_3 -> V_128 = 0 ;
V_3 -> V_75 = 0 ;
V_3 -> V_39 = 0 ;
F_40 ( & V_3 -> V_98 , & V_105 ) ;
F_38 ( & V_3 -> V_96 , V_17 ) ;
F_35 (desc, d, &list, node)
F_69 ( V_8 ) ;
F_67 ( V_3 -> V_119 ) ;
F_66 ( V_3 -> V_106 , V_3 ) ;
}
static struct V_112 *
F_70 ( struct V_6 * V_4 , T_4 V_129 ,
T_4 V_130 , T_5 V_131 , unsigned long V_17 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_132 ;
T_5 V_133 , V_134 ;
V_132 = NULL ;
for ( V_134 = 0 ; V_134 < V_131 ; V_134 += V_133 ) {
V_8 = F_33 ( V_3 ) ;
if ( ! V_8 ) {
F_23 ( F_1 ( V_3 ) , L_11 ) ;
goto V_135;
}
V_133 = F_71 ( T_5 , V_131 - V_134 , V_136 ) ;
V_8 -> V_37 = V_130 + V_134 ;
V_8 -> V_38 = V_129 + V_134 ;
V_8 -> V_40 = V_133 ;
if ( ! V_132 )
V_132 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_132 -> V_11 ) ;
}
V_132 -> V_13 . V_18 = - V_137 ;
V_132 -> V_13 . V_17 = V_17 ;
return & V_132 -> V_13 ;
V_135:
F_39 ( V_3 , V_132 ) ;
return NULL ;
}
static struct V_112 *
F_72 ( struct V_6 * V_4 , struct V_138 * V_139 ,
unsigned int V_140 , enum V_141 V_142 ,
unsigned long V_17 , void * V_143 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_132 ;
struct V_138 * V_144 ;
int V_115 ;
if ( ! V_3 -> V_101 -> V_116 && V_142 != F_24 ( V_4 ) ) {
F_23 ( F_1 ( V_3 ) ,
L_12 ) ;
return NULL ;
}
if ( F_14 ( V_16 , & V_3 -> V_17 ) ) {
F_23 ( F_1 ( V_3 ) ,
L_13 ) ;
return NULL ;
}
V_132 = NULL ;
F_73 (sgl, sg, sg_len, i) {
T_5 V_131 = F_74 ( V_144 ) ;
if ( V_131 > V_136 ) {
F_23 ( F_1 ( V_3 ) , L_14 ,
V_131 ) ;
goto V_135;
}
V_8 = F_33 ( V_3 ) ;
if ( ! V_8 ) {
F_23 ( F_1 ( V_3 ) , L_11 ) ;
goto V_135;
}
if ( V_142 == V_36 ) {
V_8 -> V_37 = F_75 ( V_144 ) ;
V_8 -> V_38 = V_3 -> V_128 ;
} else {
V_8 -> V_37 = V_3 -> V_128 ;
V_8 -> V_38 = F_75 ( V_144 ) ;
}
V_8 -> V_40 = V_131 ;
if ( ! V_132 )
V_132 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_132 -> V_11 ) ;
}
V_132 -> V_13 . V_18 = - V_137 ;
V_132 -> V_13 . V_17 = V_17 ;
return & V_132 -> V_13 ;
V_135:
F_39 ( V_3 , V_132 ) ;
return NULL ;
}
static struct V_112 *
F_76 ( struct V_6 * V_4 , T_4 V_145 ,
T_5 V_146 , T_5 V_147 ,
enum V_141 V_142 , unsigned long V_17 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_132 ;
T_5 V_134 = 0 ;
if ( ! V_3 -> V_101 -> V_116 && V_142 != F_24 ( V_4 ) ) {
F_23 ( F_1 ( V_3 ) ,
L_12 ) ;
return NULL ;
}
if ( F_77 ( V_16 , & V_3 -> V_17 ) ) {
F_23 ( F_1 ( V_3 ) ,
L_13 ) ;
return NULL ;
}
if ( V_147 > V_136 ) {
F_23 ( F_1 ( V_3 ) , L_15 ,
V_147 ) ;
return NULL ;
}
V_132 = NULL ;
for ( V_134 = 0 ; V_134 < V_146 ; V_134 += V_147 ) {
V_8 = F_33 ( V_3 ) ;
if ( ! V_8 ) {
F_23 ( F_1 ( V_3 ) , L_11 ) ;
goto V_135;
}
if ( V_142 == V_36 ) {
V_8 -> V_37 = V_145 + V_134 ;
V_8 -> V_38 = V_3 -> V_128 ;
} else {
V_8 -> V_37 = V_3 -> V_128 ;
V_8 -> V_38 = V_145 + V_134 ;
}
V_8 -> V_40 = V_147 ;
if ( ! V_132 )
V_132 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_132 -> V_11 ) ;
}
V_132 -> V_13 . V_18 = - V_137 ;
return & V_132 -> V_13 ;
V_135:
F_39 ( V_3 , V_132 ) ;
return NULL ;
}
static int F_78 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_148 ;
unsigned long V_17 ;
F_44 ( V_105 ) ;
F_34 ( & V_3 -> V_96 , V_17 ) ;
V_3 -> V_101 -> V_127 ( V_3 ) ;
F_79 ( V_16 , & V_3 -> V_17 ) ;
F_40 ( & V_3 -> V_9 , & V_105 ) ;
F_40 ( & V_3 -> V_100 , & V_105 ) ;
V_3 -> V_101 -> V_121 ( V_3 ) ;
F_38 ( & V_3 -> V_96 , V_17 ) ;
F_35 (desc, _d, &list, node)
F_39 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_80 ( struct V_6 * V_4 ,
struct V_149 * V_150 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
enum V_151 V_152 ;
unsigned long V_17 ;
T_1 V_153 , V_154 ;
if ( ! V_3 -> V_101 -> V_116 )
return - V_67 ;
switch ( V_150 -> V_57 ) {
case V_155 :
V_152 = V_150 -> V_156 ;
V_153 = V_150 -> V_37 ;
break;
case V_36 :
V_152 = V_150 -> V_157 ;
V_153 = V_150 -> V_38 ;
break;
default:
return - V_67 ;
}
switch ( V_152 ) {
case V_158 :
V_154 = 0 ;
break;
case V_159 :
V_154 = V_66 ;
break;
case V_160 :
V_154 = V_161 ;
break;
default:
return - V_67 ;
}
F_34 ( & V_3 -> V_96 , V_17 ) ;
V_3 -> V_128 = V_153 ;
V_3 -> V_75 = V_154 ;
F_38 ( & V_3 -> V_96 , V_17 ) ;
return 0 ;
}
static enum V_162 F_81 ( struct V_6 * V_4 ,
T_3 V_18 ,
struct V_163 * V_164 )
{
return F_82 ( V_4 , V_18 , V_164 ) ;
}
static void F_83 ( struct V_6 * V_4 )
{
F_42 ( F_2 ( V_4 ) ) ;
}
static int T_6 F_84 ( struct V_165 * V_166 )
{
struct V_167 * V_168 = F_85 ( & V_166 -> V_5 ) ;
struct V_169 * V_101 ;
struct V_170 * V_171 ;
T_5 V_172 ;
int V_95 , V_115 ;
V_172 = V_168 -> V_173 * sizeof( struct V_2 ) ;
V_101 = F_63 ( sizeof( * V_101 ) + V_172 , V_124 ) ;
if ( ! V_101 )
return - V_174 ;
V_171 = & V_101 -> V_171 ;
V_101 -> V_116 = F_86 ( V_166 ) -> V_175 ;
V_101 -> V_173 = V_168 -> V_173 ;
F_64 ( & V_171 -> V_176 ) ;
for ( V_115 = 0 ; V_115 < V_168 -> V_173 ; V_115 ++ ) {
const struct V_177 * V_178 = & V_168 -> V_176 [ V_115 ] ;
struct V_2 * V_3 = & V_101 -> V_176 [ V_115 ] ;
V_3 -> V_4 . V_1 = V_171 ;
V_3 -> V_20 = V_178 -> V_179 ;
V_3 -> V_106 = V_178 -> V_106 ;
V_3 -> V_101 = V_101 ;
V_3 -> V_119 = F_87 ( NULL , V_178 -> V_114 ) ;
if ( F_88 ( V_3 -> V_119 ) ) {
F_23 ( & V_166 -> V_5 , L_16 ,
V_178 -> V_114 ) ;
continue;
}
F_89 ( & V_3 -> V_96 ) ;
F_64 ( & V_3 -> V_9 ) ;
F_64 ( & V_3 -> V_100 ) ;
F_64 ( & V_3 -> V_98 ) ;
F_90 ( & V_3 -> V_111 , F_43 ,
( unsigned long ) V_3 ) ;
F_7 ( & V_3 -> V_4 . V_180 ,
& V_171 -> V_176 ) ;
}
F_91 ( V_171 -> V_181 ) ;
F_92 ( V_182 , V_171 -> V_181 ) ;
F_92 ( V_183 , V_171 -> V_181 ) ;
V_171 -> V_5 = & V_166 -> V_5 ;
V_171 -> V_184 = F_57 ;
V_171 -> V_185 = F_68 ;
V_171 -> V_186 = F_72 ;
V_171 -> V_187 = F_76 ;
V_171 -> V_188 = F_80 ;
V_171 -> V_189 = F_78 ;
V_171 -> V_190 = F_83 ;
V_171 -> V_191 = F_81 ;
F_93 ( V_171 -> V_5 , V_136 ) ;
if ( V_101 -> V_116 ) {
F_92 ( V_192 , V_171 -> V_181 ) ;
V_171 -> V_193 = F_70 ;
V_101 -> V_121 = F_28 ;
V_101 -> V_127 = F_29 ;
V_101 -> V_102 = F_31 ;
V_101 -> V_110 = F_32 ;
} else {
F_92 ( V_194 , V_171 -> V_181 ) ;
V_101 -> V_121 = F_18 ;
V_101 -> V_127 = F_20 ;
V_101 -> V_102 = F_25 ;
V_101 -> V_110 = F_26 ;
}
V_95 = F_94 ( V_171 ) ;
if ( F_95 ( V_95 ) ) {
for ( V_115 = 0 ; V_115 < V_101 -> V_173 ; V_115 ++ ) {
struct V_2 * V_3 = & V_101 -> V_176 [ V_115 ] ;
if ( ! F_96 ( V_3 -> V_119 ) )
F_97 ( V_3 -> V_119 ) ;
}
F_69 ( V_101 ) ;
} else {
F_98 ( V_171 -> V_5 , L_17 ,
V_101 -> V_116 ? L_18 : L_19 ) ;
}
return V_95 ;
}
static int T_6 F_99 ( void )
{
return F_100 ( & V_195 , F_84 ) ;
}
