static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_4 ( V_6 , V_2 -> V_4 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_6 )
{
F_3 ( V_2 , V_2 -> V_7 + V_3 , V_6 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_1 ( V_2 , V_2 -> V_8 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_6 )
{
F_3 ( V_2 , V_2 -> V_8 + V_3 , V_6 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_9 )
{
F_7 ( V_2 , V_3 , F_6 ( V_2 , V_3 ) & ~ V_9 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_10 )
{
F_7 ( V_2 , V_3 , F_6 ( V_2 , V_3 ) | V_10 ) ;
}
static struct V_11 *
F_10 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
T_2 V_13 ;
V_12 = F_11 ( V_2 -> V_14 , V_15 , & V_13 ) ;
if ( ! V_12 )
return NULL ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_13 = V_13 ;
return V_12 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
F_13 ( V_2 -> V_14 , V_12 , V_12 -> V_13 ) ;
}
static struct V_16 *
F_14 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_15 ( sizeof( * V_17 ) , V_18 ) ;
if ( ! V_17 )
return NULL ;
F_16 ( & V_17 -> V_19 ) ;
return V_17 ;
}
static void
F_17 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_11 * V_12 , * V_20 ;
if ( ! V_17 )
return;
F_18 (segment, next, &desc->segments, node) {
F_19 ( & V_12 -> V_21 ) ;
F_12 ( V_2 , V_12 ) ;
}
F_20 ( V_17 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_16 * V_17 , * V_20 ;
F_18 (desc, next, list, node) {
F_19 ( & V_17 -> V_21 ) ;
F_17 ( V_2 , V_17 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned long V_24 ;
F_23 ( & V_2 -> V_25 , V_24 ) ;
F_21 ( V_2 , & V_2 -> V_26 ) ;
F_21 ( V_2 , & V_2 -> V_27 ) ;
F_21 ( V_2 , & V_2 -> V_28 ) ;
F_24 ( & V_2 -> V_25 , V_24 ) ;
}
static void F_25 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
F_27 ( V_2 -> V_31 , L_1 ) ;
F_22 ( V_2 ) ;
F_28 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_16 * V_17 , * V_20 ;
unsigned long V_24 ;
F_23 ( & V_2 -> V_25 , V_24 ) ;
F_18 (desc, next, &chan->done_list, node) {
T_3 V_32 ;
void * V_33 ;
F_19 ( & V_17 -> V_21 ) ;
V_32 = V_17 -> V_34 . V_32 ;
V_33 = V_17 -> V_34 . V_33 ;
if ( V_32 ) {
F_24 ( & V_2 -> V_25 , V_24 ) ;
V_32 ( V_33 ) ;
F_23 ( & V_2 -> V_25 , V_24 ) ;
}
F_30 ( & V_17 -> V_34 ) ;
F_17 ( V_2 , V_17 ) ;
}
F_24 ( & V_2 -> V_25 , V_24 ) ;
}
static void F_31 ( unsigned long V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_35 ;
F_29 ( V_2 ) ;
}
static int F_32 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
if ( V_2 -> V_14 )
return 0 ;
V_2 -> V_14 = F_33 ( L_2 ,
V_2 -> V_31 ,
sizeof( struct V_11 ) ,
F_34 ( struct V_11 ) , 0 ) ;
if ( ! V_2 -> V_14 ) {
F_35 ( V_2 -> V_31 ,
L_3 ,
V_2 -> V_36 ) ;
return - V_37 ;
}
F_36 ( V_30 ) ;
return 0 ;
}
static enum V_38 F_37 ( struct V_29 * V_30 ,
T_4 V_39 ,
struct V_40 * V_41 )
{
return F_38 ( V_30 , V_39 , V_41 ) ;
}
static bool F_39 ( struct V_1 * V_2 )
{
return ! ( F_6 ( V_2 , V_42 ) &
V_43 ) &&
( F_6 ( V_2 , V_44 ) &
V_45 ) ;
}
static bool F_40 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_42 ) &
V_46 ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_47 ;
T_1 V_48 ;
F_8 ( V_2 , V_44 , V_45 ) ;
V_47 = F_42 ( V_2 , V_42 , V_48 ,
( V_48 & V_43 ) , 0 ,
V_49 ) ;
if ( V_47 ) {
F_35 ( V_2 -> V_31 , L_4 ,
V_2 , F_6 ( V_2 , V_42 ) ) ;
V_2 -> V_47 = true ;
}
return;
}
static void F_43 ( struct V_1 * V_2 )
{
int V_47 ;
T_1 V_48 ;
F_9 ( V_2 , V_44 , V_45 ) ;
V_47 = F_42 ( V_2 , V_42 , V_48 ,
! ( V_48 & V_43 ) , 0 ,
V_49 ) ;
if ( V_47 ) {
F_35 ( V_2 -> V_31 , L_5 ,
V_2 , F_6 ( V_2 , V_42 ) ) ;
V_2 -> V_47 = true ;
}
return;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = & V_2 -> V_51 ;
struct V_16 * V_17 , * V_52 ;
T_1 V_3 ;
struct V_11 * V_53 ;
if ( V_2 -> V_47 )
return;
if ( F_45 ( & V_2 -> V_26 ) )
return;
V_17 = F_46 ( & V_2 -> V_26 ,
struct V_16 , V_21 ) ;
V_52 = F_47 ( & V_2 -> V_26 ,
struct V_16 , V_21 ) ;
V_53 = F_47 ( & V_52 -> V_19 ,
struct V_11 , V_21 ) ;
if ( V_2 -> V_54 && F_39 ( V_2 ) &&
! F_40 ( V_2 ) ) {
F_27 ( V_2 -> V_31 , L_6 ) ;
return;
}
if ( V_2 -> V_54 )
F_7 ( V_2 , V_55 ,
V_17 -> V_34 . V_13 ) ;
V_3 = F_6 ( V_2 , V_44 ) ;
if ( V_51 -> V_56 )
V_3 |= V_57 ;
else
V_3 &= ~ V_57 ;
F_7 ( V_2 , V_58 ,
V_2 -> V_59 ) ;
if ( V_2 -> V_54 || ! V_51 -> V_60 )
V_3 |= V_61 ;
if ( V_51 -> V_60 )
V_3 &= ~ V_61 ;
F_7 ( V_2 , V_44 , V_3 ) ;
if ( V_51 -> V_60 && ( V_51 -> V_62 >= 0 ) &&
( V_51 -> V_62 < V_2 -> V_63 ) ) {
if ( V_2 -> V_64 == V_65 )
F_3 ( V_2 , V_66 ,
V_51 -> V_62 <<
V_67 ) ;
else
F_3 ( V_2 , V_66 ,
V_51 -> V_62 <<
V_68 ) ;
}
F_43 ( V_2 ) ;
if ( V_2 -> V_47 )
return;
if ( V_2 -> V_54 ) {
F_7 ( V_2 , V_69 ,
V_53 -> V_13 ) ;
} else {
struct V_11 * V_12 , * V_70 = NULL ;
int V_71 = 0 ;
F_48 (desc, &chan->pending_list, node) {
V_12 = F_46 ( & V_17 -> V_19 ,
struct V_11 , V_21 ) ;
F_5 ( V_2 ,
F_49 ( V_71 ++ ) ,
V_12 -> V_72 . V_73 ) ;
V_70 = V_12 ;
}
if ( ! V_70 )
return;
F_5 ( V_2 , V_74 , V_70 -> V_72 . V_75 ) ;
F_5 ( V_2 , V_76 ,
V_70 -> V_72 . V_77 ) ;
F_5 ( V_2 , V_78 , V_70 -> V_72 . V_79 ) ;
}
F_50 ( & V_2 -> V_26 , & V_2 -> V_28 ) ;
V_2 -> V_59 = 0 ;
}
static void F_51 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
unsigned long V_24 ;
F_23 ( & V_2 -> V_25 , V_24 ) ;
F_44 ( V_2 ) ;
F_24 ( & V_2 -> V_25 , V_24 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_16 * V_17 , * V_20 ;
if ( F_45 ( & V_2 -> V_28 ) )
return;
F_18 (desc, next, &chan->active_list, node) {
F_19 ( & V_17 -> V_21 ) ;
F_53 ( & V_17 -> V_34 ) ;
F_54 ( & V_17 -> V_21 , & V_2 -> V_27 ) ;
}
}
static int F_55 ( struct V_1 * V_2 )
{
int V_47 ;
T_1 V_80 ;
F_9 ( V_2 , V_44 , V_81 ) ;
V_47 = F_42 ( V_2 , V_44 , V_80 ,
! ( V_80 & V_81 ) , 0 ,
V_49 ) ;
if ( V_47 ) {
F_35 ( V_2 -> V_31 , L_7 ,
F_6 ( V_2 , V_44 ) ,
F_6 ( V_2 , V_42 ) ) ;
return - V_82 ;
}
V_2 -> V_47 = false ;
return V_47 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_47 ;
V_47 = F_55 ( V_2 ) ;
if ( V_47 )
return V_47 ;
F_9 ( V_2 , V_44 ,
V_83 ) ;
return 0 ;
}
static T_5 F_57 ( int V_84 , void * V_35 )
{
struct V_1 * V_2 = V_35 ;
T_1 V_85 ;
V_85 = F_6 ( V_2 , V_42 ) ;
if ( ! ( V_85 & V_83 ) )
return V_86 ;
F_7 ( V_2 , V_42 ,
V_85 & V_83 ) ;
if ( V_85 & V_87 ) {
T_1 V_88 = V_85 & V_89 ;
F_7 ( V_2 , V_42 ,
V_88 & V_90 ) ;
if ( ! V_2 -> V_91 ||
( V_88 & ~ V_90 ) ) {
F_35 ( V_2 -> V_31 ,
L_8 ,
V_2 , V_88 ,
F_6 ( V_2 , V_55 ) ,
F_6 ( V_2 , V_69 ) ) ;
V_2 -> V_47 = true ;
}
}
if ( V_85 & V_92 ) {
F_27 ( V_2 -> V_31 , L_9 ) ;
}
if ( V_85 & V_93 ) {
F_58 ( & V_2 -> V_25 ) ;
F_52 ( V_2 ) ;
F_44 ( V_2 ) ;
F_59 ( & V_2 -> V_25 ) ;
}
F_60 ( & V_2 -> V_94 ) ;
return V_95 ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_11 * V_53 ;
struct V_16 * V_52 ;
if ( F_45 ( & V_2 -> V_26 ) )
goto V_96;
V_52 = F_47 ( & V_2 -> V_26 ,
struct V_16 , V_21 ) ;
V_53 = F_47 ( & V_52 -> V_19 ,
struct V_11 , V_21 ) ;
V_53 -> V_72 . V_97 = ( T_1 ) V_17 -> V_34 . V_13 ;
V_96:
F_54 ( & V_17 -> V_21 , & V_2 -> V_26 ) ;
V_2 -> V_59 ++ ;
if ( F_62 ( V_2 -> V_59 > V_2 -> V_63 ) ) {
F_27 ( V_2 -> V_31 , L_10 ) ;
V_2 -> V_59 = V_2 -> V_63 ;
}
}
static T_4 F_63 ( struct V_98 * V_99 )
{
struct V_16 * V_17 = F_64 ( V_99 ) ;
struct V_1 * V_2 = F_26 ( V_99 -> V_2 ) ;
T_4 V_39 ;
unsigned long V_24 ;
int V_47 ;
if ( V_2 -> V_47 ) {
V_47 = F_56 ( V_2 ) ;
if ( V_47 < 0 )
return V_47 ;
}
F_23 ( & V_2 -> V_25 , V_24 ) ;
V_39 = F_65 ( V_99 ) ;
F_61 ( V_2 , V_17 ) ;
F_24 ( & V_2 -> V_25 , V_24 ) ;
return V_39 ;
}
static struct V_98 *
F_66 ( struct V_29 * V_30 ,
struct V_100 * V_101 ,
unsigned long V_24 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
struct V_16 * V_17 ;
struct V_11 * V_12 , * V_102 = NULL ;
struct V_103 * V_72 ;
if ( ! F_67 ( V_101 -> V_104 ) )
return NULL ;
if ( ! V_101 -> V_105 || ! V_101 -> V_106 [ 0 ] . V_107 )
return NULL ;
if ( V_101 -> V_108 != 1 )
return NULL ;
V_17 = F_14 ( V_2 ) ;
if ( ! V_17 )
return NULL ;
F_68 ( & V_17 -> V_34 , & V_2 -> V_109 ) ;
V_17 -> V_34 . V_110 = F_63 ;
F_69 ( & V_17 -> V_34 ) ;
V_12 = F_10 ( V_2 ) ;
if ( ! V_12 )
goto error;
V_72 = & V_12 -> V_72 ;
V_72 -> V_79 = V_101 -> V_105 ;
V_72 -> V_75 = V_101 -> V_106 [ 0 ] . V_107 ;
V_72 -> V_77 = ( V_101 -> V_106 [ 0 ] . V_111 + V_101 -> V_106 [ 0 ] . V_107 ) <<
V_112 ;
V_72 -> V_77 |= V_2 -> V_51 . V_113 <<
V_114 ;
if ( V_101 -> V_104 != V_65 )
V_72 -> V_73 = V_101 -> V_115 ;
else
V_72 -> V_73 = V_101 -> V_116 ;
F_54 ( & V_12 -> V_21 , & V_17 -> V_19 ) ;
V_102 = V_12 ;
V_12 = F_46 ( & V_17 -> V_19 ,
struct V_11 , V_21 ) ;
V_17 -> V_34 . V_13 = V_12 -> V_13 ;
return & V_17 -> V_34 ;
error:
F_17 ( V_2 , V_17 ) ;
return NULL ;
}
static int F_70 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
F_41 ( V_2 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
int F_71 ( struct V_29 * V_30 ,
struct V_50 * V_117 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
T_1 V_118 ;
if ( V_117 -> V_119 )
return F_56 ( V_2 ) ;
V_118 = F_6 ( V_2 , V_44 ) ;
V_2 -> V_51 . V_113 = V_117 -> V_113 ;
V_2 -> V_51 . V_60 = V_117 -> V_60 ;
V_2 -> V_51 . V_120 = V_117 -> V_120 ;
V_2 -> V_51 . V_121 = V_117 -> V_121 ;
if ( V_117 -> V_120 && V_2 -> V_122 ) {
V_118 |= V_123 ;
V_118 |= V_117 -> V_121 << V_124 ;
}
V_2 -> V_51 . V_56 = V_117 -> V_56 ;
if ( V_117 -> V_60 )
V_2 -> V_51 . V_62 = V_117 -> V_62 ;
else
V_2 -> V_51 . V_62 = - 1 ;
V_2 -> V_51 . V_125 = V_117 -> V_125 ;
V_2 -> V_51 . V_126 = V_117 -> V_126 ;
if ( V_117 -> V_125 <= V_127 ) {
V_118 |= V_117 -> V_125 << V_128 ;
V_2 -> V_51 . V_125 = V_117 -> V_125 ;
}
if ( V_117 -> V_126 <= V_129 ) {
V_118 |= V_117 -> V_126 << V_130 ;
V_2 -> V_51 . V_126 = V_117 -> V_126 ;
}
V_118 &= ~ V_131 ;
V_118 |= V_117 -> V_132 << V_133 ;
F_7 ( V_2 , V_44 , V_118 ) ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_44 ,
V_83 ) ;
if ( V_2 -> V_84 > 0 )
F_73 ( V_2 -> V_84 , V_2 ) ;
F_74 ( & V_2 -> V_94 ) ;
F_19 ( & V_2 -> V_109 . V_134 ) ;
}
static int F_75 ( struct V_135 * V_4 ,
struct V_134 * V_21 )
{
struct V_1 * V_2 ;
bool V_136 = false ;
T_1 V_6 , V_137 ;
int V_47 ;
V_2 = F_76 ( V_4 -> V_31 , sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_31 = V_4 -> V_31 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_54 = V_4 -> V_54 ;
V_2 -> V_59 = 0x0 ;
F_77 ( & V_2 -> V_25 ) ;
F_16 ( & V_2 -> V_26 ) ;
F_16 ( & V_2 -> V_27 ) ;
F_16 ( & V_2 -> V_28 ) ;
V_136 = F_78 ( V_21 , L_11 ) ;
V_2 -> V_122 = F_78 ( V_21 , L_12 ) ;
V_47 = F_79 ( V_21 , L_13 , & V_6 ) ;
if ( V_47 ) {
F_35 ( V_4 -> V_31 , L_14 ) ;
return V_47 ;
}
V_137 = V_6 >> 3 ;
if ( V_137 > 8 )
V_136 = false ;
if ( ! V_136 )
V_4 -> V_109 . V_138 = F_80 ( V_137 - 1 ) ;
if ( F_81 ( V_21 , L_15 ) ) {
V_2 -> V_64 = V_65 ;
V_2 -> V_36 = 0 ;
V_2 -> V_8 = V_139 ;
V_2 -> V_7 = V_140 ;
if ( V_4 -> V_91 == V_141 ||
V_4 -> V_91 == V_142 )
V_2 -> V_91 = true ;
} else if ( F_81 ( V_21 ,
L_16 ) ) {
V_2 -> V_64 = V_143 ;
V_2 -> V_36 = 1 ;
V_2 -> V_8 = V_144 ;
V_2 -> V_7 = V_145 ;
if ( V_4 -> V_91 == V_141 ||
V_4 -> V_91 == V_146 )
V_2 -> V_91 = true ;
} else {
F_35 ( V_4 -> V_31 , L_17 ) ;
return - V_147 ;
}
V_2 -> V_84 = F_82 ( V_21 , 0 ) ;
V_47 = F_83 ( V_2 -> V_84 , F_57 , V_148 ,
L_18 , V_2 ) ;
if ( V_47 ) {
F_35 ( V_4 -> V_31 , L_19 , V_2 -> V_84 ) ;
return V_47 ;
}
F_84 ( & V_2 -> V_94 , F_31 ,
( unsigned long ) V_2 ) ;
V_2 -> V_109 . V_149 = & V_4 -> V_109 ;
F_54 ( & V_2 -> V_109 . V_134 , & V_4 -> V_109 . V_150 ) ;
V_4 -> V_2 [ V_2 -> V_36 ] = V_2 ;
V_47 = F_56 ( V_2 ) ;
if ( V_47 < 0 ) {
F_35 ( V_4 -> V_31 , L_20 ) ;
return V_47 ;
}
return 0 ;
}
static struct V_29 * F_85 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_135 * V_4 = V_154 -> V_155 ;
int V_156 = V_152 -> args [ 0 ] ;
if ( V_156 >= V_157 || ! V_4 -> V_2 [ V_156 ] )
return NULL ;
return F_86 ( & V_4 -> V_2 [ V_156 ] -> V_109 ) ;
}
static int F_87 ( struct V_158 * V_159 )
{
struct V_134 * V_21 = V_159 -> V_31 . V_160 ;
struct V_135 * V_4 ;
struct V_134 * V_161 ;
struct V_162 * V_163 ;
T_1 V_164 ;
int V_71 , V_47 ;
V_4 = F_76 ( & V_159 -> V_31 , sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return - V_37 ;
V_4 -> V_31 = & V_159 -> V_31 ;
V_163 = F_88 ( V_159 , V_165 , 0 ) ;
V_4 -> V_5 = F_89 ( & V_159 -> V_31 , V_163 ) ;
if ( F_90 ( V_4 -> V_5 ) )
return F_91 ( V_4 -> V_5 ) ;
V_4 -> V_54 = F_78 ( V_21 , L_21 ) ;
V_47 = F_79 ( V_21 , L_22 , & V_164 ) ;
if ( V_47 < 0 ) {
F_35 ( V_4 -> V_31 , L_23 ) ;
return V_47 ;
}
V_47 = F_79 ( V_21 , L_24 ,
& V_4 -> V_91 ) ;
if ( V_47 < 0 )
F_92 ( V_4 -> V_31 , L_25 ) ;
V_4 -> V_109 . V_31 = & V_159 -> V_31 ;
F_16 ( & V_4 -> V_109 . V_150 ) ;
F_93 ( V_166 , V_4 -> V_109 . V_167 ) ;
F_93 ( V_168 , V_4 -> V_109 . V_167 ) ;
V_4 -> V_109 . V_169 =
F_32 ;
V_4 -> V_109 . V_170 =
F_25 ;
V_4 -> V_109 . V_171 =
F_66 ;
V_4 -> V_109 . V_172 = F_70 ;
V_4 -> V_109 . V_173 = F_37 ;
V_4 -> V_109 . V_174 = F_51 ;
F_94 ( V_159 , V_4 ) ;
F_95 (node, child) {
V_47 = F_75 ( V_4 , V_161 ) ;
if ( V_47 < 0 )
goto error;
}
for ( V_71 = 0 ; V_71 < V_157 ; V_71 ++ )
if ( V_4 -> V_2 [ V_71 ] )
V_4 -> V_2 [ V_71 ] -> V_63 = V_164 ;
F_96 ( & V_4 -> V_109 ) ;
V_47 = F_97 ( V_21 , F_85 ,
V_4 ) ;
if ( V_47 < 0 ) {
F_35 ( & V_159 -> V_31 , L_26 ) ;
F_98 ( & V_4 -> V_109 ) ;
goto error;
}
F_99 ( & V_159 -> V_31 , L_27 ) ;
return 0 ;
error:
for ( V_71 = 0 ; V_71 < V_157 ; V_71 ++ )
if ( V_4 -> V_2 [ V_71 ] )
F_72 ( V_4 -> V_2 [ V_71 ] ) ;
return V_47 ;
}
static int F_100 ( struct V_158 * V_159 )
{
struct V_135 * V_4 = F_101 ( V_159 ) ;
int V_71 ;
F_102 ( V_159 -> V_31 . V_160 ) ;
F_98 ( & V_4 -> V_109 ) ;
for ( V_71 = 0 ; V_71 < V_157 ; V_71 ++ )
if ( V_4 -> V_2 [ V_71 ] )
F_72 ( V_4 -> V_2 [ V_71 ] ) ;
return 0 ;
}
