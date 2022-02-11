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
V_3 -> V_30 = 0 ;
return 0 ;
}
static inline T_1 F_19 ( struct V_2 * V_3 )
{
return ( F_17 ( V_3 -> V_20 + V_31 ) >> 4 ) & 0x3 ;
}
static void F_20 ( struct V_2 * V_3 )
{
unsigned long V_17 ;
T_1 V_19 ;
F_21 ( & V_3 -> V_32 , V_17 ) ;
V_19 = F_17 ( V_3 -> V_20 + V_21 ) ;
V_19 &= ~ ( V_33 | V_34 ) ;
F_15 ( V_3 , V_19 ) ;
F_22 ( & V_3 -> V_32 , V_17 ) ;
while ( F_19 ( V_3 ) >= V_35 )
F_23 () ;
}
static void F_24 ( struct V_2 * V_3 )
{
F_15 ( V_3 , 0 ) ;
while ( F_19 ( V_3 ) != V_36 )
F_25 ( F_1 ( V_3 ) , L_1 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
T_1 V_37 ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 ) {
F_25 ( F_1 ( V_3 ) , L_2 ) ;
return;
}
if ( F_27 ( & V_3 -> V_4 ) == V_38 )
V_37 = V_8 -> V_39 ;
else
V_37 = V_8 -> V_40 ;
if ( V_3 -> V_30 == 0 ) {
F_16 ( V_8 -> V_41 , V_3 -> V_20 + V_42 ) ;
F_16 ( V_37 , V_3 -> V_20 + V_43 ) ;
} else {
F_16 ( V_8 -> V_41 , V_3 -> V_20 + V_44 ) ;
F_16 ( V_37 , V_3 -> V_20 + V_45 ) ;
}
V_3 -> V_30 ^= 1 ;
}
static void F_28 ( struct V_2 * V_3 )
{
T_1 V_19 = F_17 ( V_3 -> V_20 + V_21 ) ;
F_26 ( V_3 ) ;
V_19 |= V_33 ;
if ( F_12 ( V_3 ) ) {
F_26 ( V_3 ) ;
V_19 |= V_34 ;
}
F_15 ( V_3 , V_19 ) ;
}
static int F_29 ( struct V_2 * V_3 )
{
T_1 V_46 = F_17 ( V_3 -> V_20 + V_47 ) ;
T_1 V_19 ;
if ( V_46 & V_48 ) {
struct V_7 * V_8 = F_10 ( V_3 ) ;
F_16 ( 1 , V_3 -> V_20 + V_47 ) ;
F_30 ( F_1 ( V_3 ) ,
L_3
L_4
L_5
L_6
L_7 ,
V_8 -> V_13 . V_18 , V_8 -> V_39 , V_8 -> V_40 ,
V_8 -> V_41 ) ;
}
if ( ! ( V_46 & ( V_49 | V_50 ) ) )
return V_51 ;
if ( F_12 ( V_3 ) ) {
F_26 ( V_3 ) ;
return V_52 ;
}
V_19 = F_17 ( V_3 -> V_20 + V_21 ) ;
V_19 &= ~ ( V_33 | V_34 ) ;
F_15 ( V_3 , V_19 ) ;
return V_53 ;
}
static int F_31 ( struct V_2 * V_3 )
{
const struct V_22 * V_23 = V_3 -> V_4 . V_24 ;
T_1 V_19 = 0 ;
if ( ! V_23 ) {
F_16 ( V_19 , V_3 -> V_20 + V_54 ) ;
return 0 ;
}
switch ( V_23 -> V_25 ) {
case V_55 :
V_19 = ( 5 << V_56 ) ;
V_19 |= V_57 ;
if ( V_23 -> V_58 == V_38 ) {
V_19 |= V_59 ;
V_19 |= V_60 ;
V_19 |= V_61 ;
} else {
V_19 |= V_62 ;
V_19 |= V_63 ;
V_19 |= V_64 ;
}
break;
case V_65 :
if ( V_23 -> V_58 == V_38 ) {
V_19 = ( 3 << V_56 ) ;
V_19 |= V_59 ;
V_19 |= V_60 ;
} else {
V_19 = ( 2 << V_56 ) ;
V_19 |= V_62 ;
V_19 |= V_63 ;
}
V_19 |= V_57 ;
V_19 |= V_66 ;
V_19 |= V_67 ;
break;
default:
return - V_68 ;
}
F_16 ( V_19 , V_3 -> V_20 + V_54 ) ;
return 0 ;
}
static void F_32 ( struct V_2 * V_3 )
{
F_16 ( 0 , V_3 -> V_20 + V_54 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 ) {
F_25 ( F_1 ( V_3 ) , L_8 ) ;
return;
}
if ( V_3 -> V_30 == 0 ) {
F_16 ( V_8 -> V_39 , V_3 -> V_20 + V_69 ) ;
F_16 ( V_8 -> V_40 , V_3 -> V_20 + V_70 ) ;
F_16 ( V_8 -> V_41 , V_3 -> V_20 + V_71 ) ;
} else {
F_16 ( V_8 -> V_39 , V_3 -> V_20 + V_72 ) ;
F_16 ( V_8 -> V_40 , V_3 -> V_20 + V_73 ) ;
F_16 ( V_8 -> V_41 , V_3 -> V_20 + V_74 ) ;
}
V_3 -> V_30 ^= 1 ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_4 . V_24 ;
T_1 V_19 = F_17 ( V_3 -> V_20 + V_54 ) ;
V_19 &= ~ V_75 ;
V_19 |= V_3 -> V_76 ;
F_33 ( V_3 ) ;
V_19 |= V_77 ;
if ( F_12 ( V_3 ) ) {
F_33 ( V_3 ) ;
V_19 |= V_78 ;
}
V_19 |= V_79 ;
F_16 ( V_19 , V_3 -> V_20 + V_54 ) ;
if ( ! V_23 ) {
V_19 |= V_80 ;
F_16 ( V_19 , V_3 -> V_20 + V_54 ) ;
}
}
static int F_35 ( struct V_2 * V_3 )
{
T_1 V_81 = F_17 ( V_3 -> V_20 + V_82 ) ;
T_1 V_83 = V_81 & V_84 ;
T_1 V_85 = V_81 & V_86 ;
bool V_87 = V_81 & V_88 ;
bool V_89 ;
T_1 V_19 ;
struct V_7 * V_8 ;
if ( ! ( F_17 ( V_3 -> V_20 + V_90 ) & V_91 ) )
return V_51 ;
if ( V_87 ) {
F_16 ( 0 , V_3 -> V_20 + V_90 ) ;
}
V_8 = F_10 ( V_3 ) ;
V_89 = ! V_8 || V_8 -> V_13 . V_18 ;
if ( ! V_89 &&
( V_85 == V_92 ||
V_85 == V_93 ) ) {
if ( F_12 ( V_3 ) ) {
F_33 ( V_3 ) ;
if ( V_87 && ! V_3 -> V_4 . V_24 ) {
V_19 = F_17 ( V_3 -> V_20 + V_54 ) ;
V_19 |= V_80 ;
F_16 ( V_19 , V_3 -> V_20 + V_54 ) ;
}
return V_52 ;
} else {
V_89 = true ;
}
}
if ( V_89 &&
V_85 == V_92 &&
V_83 == V_94 ) {
V_19 = F_17 ( V_3 -> V_20 + V_54 ) ;
V_19 &= ~ ( V_77 | V_78
| V_79 ) ;
F_16 ( V_19 , V_3 -> V_20 + V_54 ) ;
return V_53 ;
}
return V_52 ;
}
static struct V_7 *
F_36 ( struct V_2 * V_3 )
{
struct V_7 * V_8 , * V_95 ;
struct V_7 * V_96 = NULL ;
unsigned long V_17 ;
F_21 ( & V_3 -> V_32 , V_17 ) ;
F_37 (desc, _desc, &edmac->free_list, node) {
if ( F_38 ( & V_8 -> V_13 ) ) {
F_39 ( & V_8 -> V_10 ) ;
V_8 -> V_39 = 0 ;
V_8 -> V_40 = 0 ;
V_8 -> V_41 = 0 ;
V_8 -> V_97 = false ;
V_8 -> V_13 . V_18 = 0 ;
V_8 -> V_13 . V_14 = NULL ;
V_8 -> V_13 . V_15 = NULL ;
V_96 = V_8 ;
break;
}
}
F_22 ( & V_3 -> V_32 , V_17 ) ;
return V_96 ;
}
static void F_40 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
if ( V_8 ) {
unsigned long V_17 ;
F_21 ( & V_3 -> V_32 , V_17 ) ;
F_41 ( & V_8 -> V_11 , & V_3 -> V_98 ) ;
F_42 ( & V_8 -> V_10 , & V_3 -> V_98 ) ;
F_22 ( & V_3 -> V_32 , V_17 ) ;
}
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_7 * V_99 ;
unsigned long V_17 ;
F_21 ( & V_3 -> V_32 , V_17 ) ;
if ( ! F_6 ( & V_3 -> V_9 ) || F_6 ( & V_3 -> V_100 ) ) {
F_22 ( & V_3 -> V_32 , V_17 ) ;
return;
}
V_99 = F_8 ( & V_3 -> V_100 , struct V_7 , V_10 ) ;
F_39 ( & V_99 -> V_10 ) ;
F_4 ( V_3 , V_99 ) ;
V_3 -> V_101 -> V_102 ( V_3 ) ;
F_22 ( & V_3 -> V_32 , V_17 ) ;
}
static void F_44 ( unsigned long V_23 )
{
struct V_2 * V_3 = (struct V_2 * ) V_23 ;
struct V_7 * V_8 , * V_12 ;
struct V_103 V_104 ;
F_45 ( V_105 ) ;
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
F_46 ( & V_3 -> V_32 ) ;
V_8 = F_10 ( V_3 ) ;
if ( V_8 ) {
if ( V_8 -> V_97 ) {
if ( ! F_14 ( V_16 , & V_3 -> V_17 ) )
F_47 ( & V_8 -> V_13 ) ;
F_41 ( & V_3 -> V_9 , & V_105 ) ;
}
F_48 ( & V_8 -> V_13 , & V_104 ) ;
}
F_49 ( & V_3 -> V_32 ) ;
F_43 ( V_3 ) ;
F_37 (desc, d, &list, node) {
F_50 ( & V_8 -> V_13 ) ;
F_40 ( V_3 , V_8 ) ;
}
F_51 ( & V_104 , NULL ) ;
}
static T_2 F_52 ( int V_106 , void * V_107 )
{
struct V_2 * V_3 = V_107 ;
struct V_7 * V_8 ;
T_2 V_96 = V_108 ;
F_53 ( & V_3 -> V_32 ) ;
V_8 = F_10 ( V_3 ) ;
if ( ! V_8 ) {
F_25 ( F_1 ( V_3 ) ,
L_9 ) ;
F_54 ( & V_3 -> V_32 ) ;
return V_109 ;
}
switch ( V_3 -> V_101 -> V_110 ( V_3 ) ) {
case V_53 :
V_8 -> V_97 = true ;
F_55 ( & V_3 -> V_111 ) ;
break;
case V_52 :
if ( F_14 ( V_16 , & V_3 -> V_17 ) )
F_55 ( & V_3 -> V_111 ) ;
break;
default:
F_25 ( F_1 ( V_3 ) , L_10 ) ;
V_96 = V_109 ;
break;
}
F_54 ( & V_3 -> V_32 ) ;
return V_96 ;
}
static T_3 F_56 ( struct V_112 * V_113 )
{
struct V_2 * V_3 = F_2 ( V_113 -> V_4 ) ;
struct V_7 * V_8 ;
T_3 V_18 ;
unsigned long V_17 ;
F_21 ( & V_3 -> V_32 , V_17 ) ;
V_18 = F_57 ( V_113 ) ;
V_8 = F_3 ( V_113 , struct V_7 , V_13 ) ;
if ( F_6 ( & V_3 -> V_9 ) ) {
F_4 ( V_3 , V_8 ) ;
V_3 -> V_101 -> V_102 ( V_3 ) ;
} else {
F_7 ( & V_8 -> V_10 , & V_3 -> V_100 ) ;
}
F_22 ( & V_3 -> V_32 , V_17 ) ;
return V_18 ;
}
static int F_58 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_22 * V_23 = V_4 -> V_24 ;
const char * V_114 = F_59 ( V_4 ) ;
int V_96 , V_115 ;
if ( ! V_3 -> V_101 -> V_116 ) {
if ( ! V_23 )
return - V_68 ;
if ( V_23 -> V_25 < V_117 ||
V_23 -> V_25 > V_118 )
return - V_68 ;
if ( V_23 -> V_58 != F_27 ( V_4 ) )
return - V_68 ;
} else {
if ( V_23 ) {
switch ( V_23 -> V_25 ) {
case V_55 :
case V_65 :
if ( ! F_60 ( V_23 -> V_58 ) )
return - V_68 ;
break;
default:
return - V_68 ;
}
}
}
if ( V_23 && V_23 -> V_114 )
V_114 = V_23 -> V_114 ;
V_96 = F_61 ( V_3 -> V_119 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_62 ( V_3 -> V_106 , F_52 , 0 , V_114 , V_3 ) ;
if ( V_96 )
goto V_120;
F_46 ( & V_3 -> V_32 ) ;
F_63 ( & V_3 -> V_4 ) ;
V_96 = V_3 -> V_101 -> V_121 ( V_3 ) ;
F_49 ( & V_3 -> V_32 ) ;
if ( V_96 )
goto V_122;
for ( V_115 = 0 ; V_115 < V_123 ; V_115 ++ ) {
struct V_7 * V_8 ;
V_8 = F_64 ( sizeof( * V_8 ) , V_124 ) ;
if ( ! V_8 ) {
F_25 ( F_1 ( V_3 ) , L_11 ) ;
break;
}
F_65 ( & V_8 -> V_11 ) ;
F_66 ( & V_8 -> V_13 , V_4 ) ;
V_8 -> V_13 . V_17 = V_125 ;
V_8 -> V_13 . V_126 = F_56 ;
F_40 ( V_3 , V_8 ) ;
}
return V_115 ;
V_122:
F_67 ( V_3 -> V_106 , V_3 ) ;
V_120:
F_68 ( V_3 -> V_119 ) ;
return V_96 ;
}
static void F_69 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_12 ;
unsigned long V_17 ;
F_45 ( V_105 ) ;
F_5 ( ! F_6 ( & V_3 -> V_9 ) ) ;
F_5 ( ! F_6 ( & V_3 -> V_100 ) ) ;
F_21 ( & V_3 -> V_32 , V_17 ) ;
V_3 -> V_101 -> V_127 ( V_3 ) ;
V_3 -> V_128 = 0 ;
V_3 -> V_76 = 0 ;
V_3 -> V_30 = 0 ;
F_41 ( & V_3 -> V_98 , & V_105 ) ;
F_22 ( & V_3 -> V_32 , V_17 ) ;
F_37 (desc, d, &list, node)
F_70 ( V_8 ) ;
F_68 ( V_3 -> V_119 ) ;
F_67 ( V_3 -> V_106 , V_3 ) ;
}
static struct V_112 *
F_71 ( struct V_6 * V_4 , T_4 V_129 ,
T_4 V_130 , T_5 V_131 , unsigned long V_17 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_132 ;
T_5 V_133 , V_134 ;
V_132 = NULL ;
for ( V_134 = 0 ; V_134 < V_131 ; V_134 += V_133 ) {
V_8 = F_36 ( V_3 ) ;
if ( ! V_8 ) {
F_25 ( F_1 ( V_3 ) , L_12 ) ;
goto V_135;
}
V_133 = F_72 ( T_5 , V_131 - V_134 , V_136 ) ;
V_8 -> V_39 = V_130 + V_134 ;
V_8 -> V_40 = V_129 + V_134 ;
V_8 -> V_41 = V_133 ;
if ( ! V_132 )
V_132 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_132 -> V_11 ) ;
}
V_132 -> V_13 . V_18 = - V_137 ;
V_132 -> V_13 . V_17 = V_17 ;
return & V_132 -> V_13 ;
V_135:
F_40 ( V_3 , V_132 ) ;
return NULL ;
}
static struct V_112 *
F_73 ( struct V_6 * V_4 , struct V_138 * V_139 ,
unsigned int V_140 , enum V_141 V_142 ,
unsigned long V_17 , void * V_143 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_132 ;
struct V_138 * V_144 ;
int V_115 ;
if ( ! V_3 -> V_101 -> V_116 && V_142 != F_27 ( V_4 ) ) {
F_25 ( F_1 ( V_3 ) ,
L_13 ) ;
return NULL ;
}
if ( F_14 ( V_16 , & V_3 -> V_17 ) ) {
F_25 ( F_1 ( V_3 ) ,
L_14 ) ;
return NULL ;
}
V_132 = NULL ;
F_74 (sgl, sg, sg_len, i) {
T_5 V_131 = F_75 ( V_144 ) ;
if ( V_131 > V_136 ) {
F_25 ( F_1 ( V_3 ) , L_15 ,
V_131 ) ;
goto V_135;
}
V_8 = F_36 ( V_3 ) ;
if ( ! V_8 ) {
F_25 ( F_1 ( V_3 ) , L_12 ) ;
goto V_135;
}
if ( V_142 == V_38 ) {
V_8 -> V_39 = F_76 ( V_144 ) ;
V_8 -> V_40 = V_3 -> V_128 ;
} else {
V_8 -> V_39 = V_3 -> V_128 ;
V_8 -> V_40 = F_76 ( V_144 ) ;
}
V_8 -> V_41 = V_131 ;
if ( ! V_132 )
V_132 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_132 -> V_11 ) ;
}
V_132 -> V_13 . V_18 = - V_137 ;
V_132 -> V_13 . V_17 = V_17 ;
return & V_132 -> V_13 ;
V_135:
F_40 ( V_3 , V_132 ) ;
return NULL ;
}
static struct V_112 *
F_77 ( struct V_6 * V_4 , T_4 V_145 ,
T_5 V_146 , T_5 V_147 ,
enum V_141 V_142 , unsigned long V_17 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_132 ;
T_5 V_134 = 0 ;
if ( ! V_3 -> V_101 -> V_116 && V_142 != F_27 ( V_4 ) ) {
F_25 ( F_1 ( V_3 ) ,
L_13 ) ;
return NULL ;
}
if ( F_78 ( V_16 , & V_3 -> V_17 ) ) {
F_25 ( F_1 ( V_3 ) ,
L_14 ) ;
return NULL ;
}
if ( V_147 > V_136 ) {
F_25 ( F_1 ( V_3 ) , L_16 ,
V_147 ) ;
return NULL ;
}
V_132 = NULL ;
for ( V_134 = 0 ; V_134 < V_146 ; V_134 += V_147 ) {
V_8 = F_36 ( V_3 ) ;
if ( ! V_8 ) {
F_25 ( F_1 ( V_3 ) , L_12 ) ;
goto V_135;
}
if ( V_142 == V_38 ) {
V_8 -> V_39 = V_145 + V_134 ;
V_8 -> V_40 = V_3 -> V_128 ;
} else {
V_8 -> V_39 = V_3 -> V_128 ;
V_8 -> V_40 = V_145 + V_134 ;
}
V_8 -> V_41 = V_147 ;
if ( ! V_132 )
V_132 = V_8 ;
else
F_7 ( & V_8 -> V_10 , & V_132 -> V_11 ) ;
}
V_132 -> V_13 . V_18 = - V_137 ;
return & V_132 -> V_13 ;
V_135:
F_40 ( V_3 , V_132 ) ;
return NULL ;
}
static void F_79 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
if ( V_3 -> V_101 -> V_148 )
V_3 -> V_101 -> V_148 ( V_3 ) ;
}
static int F_80 ( struct V_6 * V_4 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_7 * V_8 , * V_149 ;
unsigned long V_17 ;
F_45 ( V_105 ) ;
F_21 ( & V_3 -> V_32 , V_17 ) ;
V_3 -> V_101 -> V_127 ( V_3 ) ;
F_81 ( V_16 , & V_3 -> V_17 ) ;
F_41 ( & V_3 -> V_9 , & V_105 ) ;
F_41 ( & V_3 -> V_100 , & V_105 ) ;
V_3 -> V_101 -> V_121 ( V_3 ) ;
F_22 ( & V_3 -> V_32 , V_17 ) ;
F_37 (desc, _d, &list, node)
F_40 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_82 ( struct V_6 * V_4 ,
struct V_150 * V_151 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
enum V_152 V_153 ;
unsigned long V_17 ;
T_1 V_154 , V_155 ;
if ( ! V_3 -> V_101 -> V_116 )
return - V_68 ;
switch ( V_151 -> V_58 ) {
case V_156 :
V_153 = V_151 -> V_157 ;
V_154 = V_151 -> V_39 ;
break;
case V_38 :
V_153 = V_151 -> V_158 ;
V_154 = V_151 -> V_40 ;
break;
default:
return - V_68 ;
}
switch ( V_153 ) {
case V_159 :
V_155 = 0 ;
break;
case V_160 :
V_155 = V_67 ;
break;
case V_161 :
V_155 = V_162 ;
break;
default:
return - V_68 ;
}
F_21 ( & V_3 -> V_32 , V_17 ) ;
V_3 -> V_128 = V_154 ;
V_3 -> V_76 = V_155 ;
F_22 ( & V_3 -> V_32 , V_17 ) ;
return 0 ;
}
static enum V_163 F_83 ( struct V_6 * V_4 ,
T_3 V_18 ,
struct V_164 * V_165 )
{
return F_84 ( V_4 , V_18 , V_165 ) ;
}
static void F_85 ( struct V_6 * V_4 )
{
F_43 ( F_2 ( V_4 ) ) ;
}
static int T_6 F_86 ( struct V_166 * V_167 )
{
struct V_168 * V_169 = F_87 ( & V_167 -> V_5 ) ;
struct V_170 * V_101 ;
struct V_171 * V_172 ;
T_5 V_173 ;
int V_96 , V_115 ;
V_173 = V_169 -> V_174 * sizeof( struct V_2 ) ;
V_101 = F_64 ( sizeof( * V_101 ) + V_173 , V_124 ) ;
if ( ! V_101 )
return - V_175 ;
V_172 = & V_101 -> V_172 ;
V_101 -> V_116 = F_88 ( V_167 ) -> V_176 ;
V_101 -> V_174 = V_169 -> V_174 ;
F_65 ( & V_172 -> V_177 ) ;
for ( V_115 = 0 ; V_115 < V_169 -> V_174 ; V_115 ++ ) {
const struct V_178 * V_179 = & V_169 -> V_177 [ V_115 ] ;
struct V_2 * V_3 = & V_101 -> V_177 [ V_115 ] ;
V_3 -> V_4 . V_1 = V_172 ;
V_3 -> V_20 = V_179 -> V_180 ;
V_3 -> V_106 = V_179 -> V_106 ;
V_3 -> V_101 = V_101 ;
V_3 -> V_119 = F_89 ( NULL , V_179 -> V_114 ) ;
if ( F_90 ( V_3 -> V_119 ) ) {
F_25 ( & V_167 -> V_5 , L_17 ,
V_179 -> V_114 ) ;
continue;
}
F_91 ( & V_3 -> V_32 ) ;
F_65 ( & V_3 -> V_9 ) ;
F_65 ( & V_3 -> V_100 ) ;
F_65 ( & V_3 -> V_98 ) ;
F_92 ( & V_3 -> V_111 , F_44 ,
( unsigned long ) V_3 ) ;
F_7 ( & V_3 -> V_4 . V_181 ,
& V_172 -> V_177 ) ;
}
F_93 ( V_172 -> V_182 ) ;
F_94 ( V_183 , V_172 -> V_182 ) ;
F_94 ( V_184 , V_172 -> V_182 ) ;
V_172 -> V_5 = & V_167 -> V_5 ;
V_172 -> V_185 = F_58 ;
V_172 -> V_186 = F_69 ;
V_172 -> V_187 = F_73 ;
V_172 -> V_188 = F_77 ;
V_172 -> V_189 = F_82 ;
V_172 -> V_190 = F_79 ;
V_172 -> V_191 = F_80 ;
V_172 -> V_192 = F_85 ;
V_172 -> V_193 = F_83 ;
F_95 ( V_172 -> V_5 , V_136 ) ;
if ( V_101 -> V_116 ) {
F_94 ( V_194 , V_172 -> V_182 ) ;
V_172 -> V_195 = F_71 ;
V_101 -> V_121 = F_31 ;
V_101 -> V_127 = F_32 ;
V_101 -> V_102 = F_34 ;
V_101 -> V_110 = F_35 ;
} else {
F_94 ( V_196 , V_172 -> V_182 ) ;
V_101 -> V_148 = F_20 ;
V_101 -> V_121 = F_18 ;
V_101 -> V_127 = F_24 ;
V_101 -> V_102 = F_28 ;
V_101 -> V_110 = F_29 ;
}
V_96 = F_96 ( V_172 ) ;
if ( F_97 ( V_96 ) ) {
for ( V_115 = 0 ; V_115 < V_101 -> V_174 ; V_115 ++ ) {
struct V_2 * V_3 = & V_101 -> V_177 [ V_115 ] ;
if ( ! F_98 ( V_3 -> V_119 ) )
F_99 ( V_3 -> V_119 ) ;
}
F_70 ( V_101 ) ;
} else {
F_100 ( V_172 -> V_5 , L_18 ,
V_101 -> V_116 ? L_19 : L_20 ) ;
}
return V_96 ;
}
static int T_6 F_101 ( void )
{
return F_102 ( & V_197 , F_86 ) ;
}
