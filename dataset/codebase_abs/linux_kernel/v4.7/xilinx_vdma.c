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
static inline void F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_11 , T_1 V_12 )
{
F_11 ( V_11 , V_2 -> V_4 -> V_5 + V_2 -> V_7 + V_3 ) ;
F_11 ( V_12 , V_2 -> V_4 -> V_5 + V_2 -> V_7 + V_3 + 4 ) ;
}
static struct V_13 *
F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
T_2 V_15 ;
V_14 = F_13 ( V_2 -> V_16 , V_17 , & V_15 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_15 = V_15 ;
return V_14 ;
}
static struct V_18 *
F_14 ( struct V_1 * V_2 )
{
struct V_18 * V_14 ;
T_2 V_15 ;
V_14 = F_15 ( V_2 -> V_16 , V_17 , & V_15 ) ;
if ( ! V_14 )
return NULL ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 -> V_15 = V_15 ;
return V_14 ;
}
static struct V_19 *
F_16 ( struct V_1 * V_2 )
{
struct V_19 * V_14 ;
T_2 V_15 ;
V_14 = F_15 ( V_2 -> V_16 , V_17 , & V_15 ) ;
if ( ! V_14 )
return NULL ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 -> V_15 = V_15 ;
return V_14 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_19 * V_14 )
{
F_18 ( V_2 -> V_16 , V_14 , V_14 -> V_15 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_18 * V_14 )
{
F_18 ( V_2 -> V_16 , V_14 , V_14 -> V_15 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
F_18 ( V_2 -> V_16 , V_14 , V_14 -> V_15 ) ;
}
static struct V_20 *
F_21 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
V_21 = F_22 ( sizeof( * V_21 ) , V_22 ) ;
if ( ! V_21 )
return NULL ;
F_23 ( & V_21 -> V_23 ) ;
return V_21 ;
}
static void
F_24 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_13 * V_14 , * V_24 ;
struct V_18 * V_25 , * V_26 ;
struct V_19 * V_27 , * V_28 ;
if ( ! V_21 )
return;
if ( V_2 -> V_4 -> V_29 -> V_30 == V_31 ) {
F_25 (segment, next, &desc->segments, node) {
F_26 ( & V_14 -> V_32 ) ;
F_20 ( V_2 , V_14 ) ;
}
} else if ( V_2 -> V_4 -> V_29 -> V_30 == V_33 ) {
F_25 (cdma_segment, cdma_next,
&desc->segments, node) {
F_26 ( & V_25 -> V_32 ) ;
F_19 ( V_2 , V_25 ) ;
}
} else {
F_25 (axidma_segment, axidma_next,
&desc->segments, node) {
F_26 ( & V_27 -> V_32 ) ;
F_17 ( V_2 , V_27 ) ;
}
}
F_27 ( V_21 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_20 * V_21 , * V_24 ;
F_25 (desc, next, list, node) {
F_26 ( & V_21 -> V_32 ) ;
F_24 ( V_2 , V_21 ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
unsigned long V_36 ;
F_30 ( & V_2 -> V_37 , V_36 ) ;
F_28 ( V_2 , & V_2 -> V_38 ) ;
F_28 ( V_2 , & V_2 -> V_39 ) ;
F_28 ( V_2 , & V_2 -> V_40 ) ;
F_31 ( & V_2 -> V_37 , V_36 ) ;
}
static void F_32 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_33 ( V_42 ) ;
F_34 ( V_2 -> V_43 , L_1 ) ;
F_29 ( V_2 ) ;
if ( V_2 -> V_4 -> V_29 -> V_30 == V_44 )
F_17 ( V_2 , V_2 -> V_45 ) ;
F_35 ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_20 * V_21 , * V_24 ;
unsigned long V_36 ;
F_30 ( & V_2 -> V_37 , V_36 ) ;
F_25 (desc, next, &chan->done_list, node) {
T_3 V_46 ;
void * V_47 ;
F_26 ( & V_21 -> V_32 ) ;
V_46 = V_21 -> V_48 . V_46 ;
V_47 = V_21 -> V_48 . V_47 ;
if ( V_46 ) {
F_31 ( & V_2 -> V_37 , V_36 ) ;
V_46 ( V_47 ) ;
F_30 ( & V_2 -> V_37 , V_36 ) ;
}
F_37 ( & V_21 -> V_48 ) ;
F_24 ( V_2 , V_21 ) ;
}
F_31 ( & V_2 -> V_37 , V_36 ) ;
}
static void F_38 ( unsigned long V_49 )
{
struct V_1 * V_2 = (struct V_1 * ) V_49 ;
F_36 ( V_2 ) ;
}
static int F_39 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_33 ( V_42 ) ;
if ( V_2 -> V_16 )
return 0 ;
if ( V_2 -> V_4 -> V_29 -> V_30 == V_44 ) {
V_2 -> V_16 = F_40 ( L_2 ,
V_2 -> V_43 ,
sizeof( struct V_19 ) ,
F_41 ( struct V_19 ) ,
0 ) ;
} else if ( V_2 -> V_4 -> V_29 -> V_30 == V_33 ) {
V_2 -> V_16 = F_40 ( L_3 ,
V_2 -> V_43 ,
sizeof( struct V_18 ) ,
F_41 ( struct V_18 ) ,
0 ) ;
} else {
V_2 -> V_16 = F_40 ( L_4 ,
V_2 -> V_43 ,
sizeof( struct V_13 ) ,
F_41 ( struct V_13 ) ,
0 ) ;
}
if ( ! V_2 -> V_16 ) {
F_42 ( V_2 -> V_43 ,
L_5 ,
V_2 -> V_50 ) ;
return - V_51 ;
}
if ( V_2 -> V_4 -> V_29 -> V_30 == V_44 )
V_2 -> V_45 = F_16 ( V_2 ) ;
F_43 ( V_42 ) ;
if ( V_2 -> V_4 -> V_29 -> V_30 == V_44 ) {
F_9 ( V_2 , V_52 ,
V_53 ) ;
}
if ( ( V_2 -> V_4 -> V_29 -> V_30 == V_33 ) && V_2 -> V_54 )
F_9 ( V_2 , V_52 ,
V_55 ) ;
return 0 ;
}
static enum V_56 F_44 ( struct V_41 * V_42 ,
T_4 V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_33 ( V_42 ) ;
struct V_20 * V_21 ;
struct V_19 * V_14 ;
struct V_60 * V_61 ;
enum V_56 V_62 ;
unsigned long V_36 ;
T_1 V_63 = 0 ;
V_62 = F_45 ( V_42 , V_57 , V_59 ) ;
if ( V_62 == V_64 || ! V_59 )
return V_62 ;
if ( V_2 -> V_4 -> V_29 -> V_30 == V_44 ) {
F_30 ( & V_2 -> V_37 , V_36 ) ;
V_21 = F_46 ( & V_2 -> V_40 ,
struct V_20 , V_32 ) ;
if ( V_2 -> V_54 ) {
F_47 (segment, &desc->segments, node) {
V_61 = & V_14 -> V_61 ;
V_63 += ( V_61 -> V_65 - V_61 -> V_66 ) &
V_67 ;
}
}
F_31 ( & V_2 -> V_37 , V_36 ) ;
V_2 -> V_63 = V_63 ;
F_48 ( V_59 , V_2 -> V_63 ) ;
}
return V_62 ;
}
static bool F_49 ( struct V_1 * V_2 )
{
return ! ( F_6 ( V_2 , V_68 ) &
V_69 ) &&
( F_6 ( V_2 , V_52 ) &
V_70 ) ;
}
static bool F_50 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_68 ) &
V_71 ;
}
static void F_51 ( struct V_1 * V_2 )
{
int V_72 ;
T_1 V_73 ;
F_8 ( V_2 , V_52 , V_70 ) ;
V_72 = F_52 ( V_2 , V_68 , V_73 ,
( V_73 & V_69 ) , 0 ,
V_74 ) ;
if ( V_72 ) {
F_42 ( V_2 -> V_43 , L_6 ,
V_2 , F_6 ( V_2 , V_68 ) ) ;
V_2 -> V_72 = true ;
}
}
static void F_53 ( struct V_1 * V_2 )
{
int V_72 ;
T_1 V_73 ;
F_9 ( V_2 , V_52 , V_70 ) ;
V_72 = F_52 ( V_2 , V_68 , V_73 ,
! ( V_73 & V_69 ) , 0 ,
V_74 ) ;
if ( V_72 ) {
F_42 ( V_2 -> V_43 , L_7 ,
V_2 , F_6 ( V_2 , V_68 ) ) ;
V_2 -> V_72 = true ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = & V_2 -> V_76 ;
struct V_20 * V_21 , * V_77 ;
T_1 V_3 ;
struct V_13 * V_78 ;
if ( V_2 -> V_72 )
return;
if ( F_55 ( & V_2 -> V_38 ) )
return;
V_21 = F_56 ( & V_2 -> V_38 ,
struct V_20 , V_32 ) ;
V_77 = F_46 ( & V_2 -> V_38 ,
struct V_20 , V_32 ) ;
V_78 = F_46 ( & V_77 -> V_23 ,
struct V_13 , V_32 ) ;
if ( V_2 -> V_54 && F_49 ( V_2 ) &&
! F_50 ( V_2 ) ) {
F_34 ( V_2 -> V_43 , L_8 ) ;
return;
}
if ( V_2 -> V_54 )
F_7 ( V_2 , V_79 ,
V_21 -> V_48 . V_15 ) ;
V_3 = F_6 ( V_2 , V_52 ) ;
if ( V_76 -> V_80 )
V_3 |= V_81 ;
else
V_3 &= ~ V_81 ;
F_7 ( V_2 , V_82 ,
V_2 -> V_83 ) ;
if ( V_2 -> V_54 || ! V_76 -> V_84 )
V_3 |= V_85 ;
if ( V_76 -> V_84 )
V_3 &= ~ V_85 ;
F_7 ( V_2 , V_52 , V_3 ) ;
if ( V_76 -> V_84 && ( V_76 -> V_86 >= 0 ) &&
( V_76 -> V_86 < V_2 -> V_87 ) ) {
if ( V_2 -> V_88 == V_89 )
F_3 ( V_2 , V_90 ,
V_76 -> V_86 <<
V_91 ) ;
else
F_3 ( V_2 , V_90 ,
V_76 -> V_86 <<
V_92 ) ;
}
F_53 ( V_2 ) ;
if ( V_2 -> V_72 )
return;
if ( V_2 -> V_54 ) {
F_7 ( V_2 , V_93 ,
V_78 -> V_15 ) ;
} else {
struct V_13 * V_14 , * V_94 = NULL ;
int V_95 = 0 ;
if ( V_2 -> V_96 < V_2 -> V_87 )
V_95 = V_2 -> V_96 ;
F_47 (segment, &desc->segments, node) {
if ( V_2 -> V_97 )
F_10 ( V_2 ,
F_57 ( V_95 ++ ) ,
V_14 -> V_61 . V_98 ,
V_14 -> V_61 . V_99 ) ;
else
F_5 ( V_2 ,
F_58 ( V_95 ++ ) ,
V_14 -> V_61 . V_98 ) ;
V_94 = V_14 ;
}
if ( ! V_94 )
return;
F_5 ( V_2 , V_100 , V_94 -> V_61 . V_101 ) ;
F_5 ( V_2 , V_102 ,
V_94 -> V_61 . V_103 ) ;
F_5 ( V_2 , V_104 , V_94 -> V_61 . V_105 ) ;
}
if ( ! V_2 -> V_54 ) {
F_26 ( & V_21 -> V_32 ) ;
F_59 ( & V_21 -> V_32 , & V_2 -> V_40 ) ;
V_2 -> V_96 ++ ;
V_2 -> V_83 -- ;
if ( V_2 -> V_96 == V_2 -> V_87 )
V_2 -> V_96 = 0 ;
} else {
F_60 ( & V_2 -> V_38 , & V_2 -> V_40 ) ;
V_2 -> V_83 = 0 ;
}
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_20 * V_106 , * V_77 ;
struct V_18 * V_78 ;
T_1 V_107 = F_1 ( V_2 , V_52 ) ;
if ( V_2 -> V_72 )
return;
if ( F_55 ( & V_2 -> V_38 ) )
return;
V_106 = F_56 ( & V_2 -> V_38 ,
struct V_20 , V_32 ) ;
V_77 = F_46 ( & V_2 -> V_38 ,
struct V_20 , V_32 ) ;
V_78 = F_46 ( & V_77 -> V_23 ,
struct V_18 , V_32 ) ;
if ( V_2 -> V_83 <= V_108 ) {
V_107 &= ~ V_109 ;
V_107 |= V_2 -> V_83 <<
V_110 ;
F_7 ( V_2 , V_52 , V_107 ) ;
}
if ( V_2 -> V_54 ) {
F_7 ( V_2 , V_79 ,
V_106 -> V_48 . V_15 ) ;
F_7 ( V_2 , V_93 ,
V_78 -> V_15 ) ;
} else {
struct V_18 * V_14 ;
struct V_111 * V_61 ;
V_14 = F_56 ( & V_106 -> V_23 ,
struct V_18 ,
V_32 ) ;
V_61 = & V_14 -> V_61 ;
F_7 ( V_2 , V_112 , V_61 -> V_113 ) ;
F_7 ( V_2 , V_114 , V_61 -> V_115 ) ;
F_7 ( V_2 , V_116 ,
V_61 -> V_65 & V_67 ) ;
}
F_60 ( & V_2 -> V_38 , & V_2 -> V_40 ) ;
V_2 -> V_83 = 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_20 * V_106 , * V_77 ;
struct V_19 * V_78 , * V_117 , * V_118 ;
T_1 V_3 ;
if ( V_2 -> V_72 )
return;
if ( F_55 ( & V_2 -> V_38 ) )
return;
if ( V_2 -> V_54 && F_49 ( V_2 ) &&
! F_50 ( V_2 ) ) {
F_34 ( V_2 -> V_43 , L_8 ) ;
return;
}
V_106 = F_56 ( & V_2 -> V_38 ,
struct V_20 , V_32 ) ;
V_77 = F_46 ( & V_2 -> V_38 ,
struct V_20 , V_32 ) ;
V_78 = F_46 ( & V_77 -> V_23 ,
struct V_19 , V_32 ) ;
V_117 = F_56 ( & V_106 -> V_23 ,
struct V_19 , V_32 ) ;
V_118 = V_2 -> V_45 ;
V_118 -> V_61 = V_117 -> V_61 ;
F_63 ( & V_117 -> V_32 , & V_118 -> V_32 ) ;
V_2 -> V_45 = V_117 ;
V_78 -> V_61 . V_119 = V_2 -> V_45 -> V_15 ;
V_106 -> V_48 . V_15 = V_118 -> V_15 ;
V_3 = F_6 ( V_2 , V_52 ) ;
if ( V_2 -> V_83 <= V_108 ) {
V_3 &= ~ V_109 ;
V_3 |= V_2 -> V_83 <<
V_110 ;
F_7 ( V_2 , V_52 , V_3 ) ;
}
if ( V_2 -> V_54 )
F_7 ( V_2 , V_79 ,
V_106 -> V_48 . V_15 ) ;
F_53 ( V_2 ) ;
if ( V_2 -> V_72 )
return;
if ( V_2 -> V_54 ) {
F_7 ( V_2 , V_93 ,
V_78 -> V_15 ) ;
} else {
struct V_19 * V_14 ;
struct V_60 * V_61 ;
V_14 = F_56 ( & V_106 -> V_23 ,
struct V_19 ,
V_32 ) ;
V_61 = & V_14 -> V_61 ;
F_7 ( V_2 , V_120 , V_61 -> V_98 ) ;
F_7 ( V_2 , V_116 ,
V_61 -> V_65 & V_67 ) ;
}
F_60 ( & V_2 -> V_38 , & V_2 -> V_40 ) ;
V_2 -> V_83 = 0 ;
}
static void F_64 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_33 ( V_42 ) ;
unsigned long V_36 ;
F_30 ( & V_2 -> V_37 , V_36 ) ;
V_2 -> V_121 ( V_2 ) ;
F_31 ( & V_2 -> V_37 , V_36 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_20 * V_21 , * V_24 ;
if ( F_55 ( & V_2 -> V_40 ) )
return;
F_25 (desc, next, &chan->active_list, node) {
F_26 ( & V_21 -> V_32 ) ;
F_66 ( & V_21 -> V_48 ) ;
F_59 ( & V_21 -> V_32 , & V_2 -> V_39 ) ;
}
}
static int F_67 ( struct V_1 * V_2 )
{
int V_72 ;
T_1 V_122 ;
F_9 ( V_2 , V_52 , V_123 ) ;
V_72 = F_52 ( V_2 , V_52 , V_122 ,
! ( V_122 & V_123 ) , 0 ,
V_74 ) ;
if ( V_72 ) {
F_42 ( V_2 -> V_43 , L_9 ,
F_6 ( V_2 , V_52 ) ,
F_6 ( V_2 , V_68 ) ) ;
return - V_124 ;
}
V_2 -> V_72 = false ;
return V_72 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_72 ;
V_72 = F_67 ( V_2 ) ;
if ( V_72 )
return V_72 ;
F_9 ( V_2 , V_52 ,
V_53 ) ;
return 0 ;
}
static T_5 F_69 ( int V_125 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
T_1 V_66 ;
V_66 = F_6 ( V_2 , V_68 ) ;
if ( ! ( V_66 & V_53 ) )
return V_126 ;
F_7 ( V_2 , V_68 ,
V_66 & V_53 ) ;
if ( V_66 & V_127 ) {
T_1 V_128 = V_66 & V_129 ;
F_7 ( V_2 , V_68 ,
V_128 & V_130 ) ;
if ( ! V_2 -> V_131 ||
( V_128 & ~ V_130 ) ) {
F_42 ( V_2 -> V_43 ,
L_10 ,
V_2 , V_128 ,
F_6 ( V_2 , V_79 ) ,
F_6 ( V_2 , V_93 ) ) ;
V_2 -> V_72 = true ;
}
}
if ( V_66 & V_132 ) {
F_34 ( V_2 -> V_43 , L_11 ) ;
}
if ( V_66 & V_133 ) {
F_70 ( & V_2 -> V_37 ) ;
F_65 ( V_2 ) ;
V_2 -> V_121 ( V_2 ) ;
F_71 ( & V_2 -> V_37 ) ;
}
F_72 ( & V_2 -> V_134 ) ;
return V_135 ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_13 * V_78 ;
struct V_20 * V_77 ;
struct V_19 * V_136 ;
struct V_18 * V_137 ;
if ( F_55 ( & V_2 -> V_38 ) )
goto V_138;
V_77 = F_46 ( & V_2 -> V_38 ,
struct V_20 , V_32 ) ;
if ( V_2 -> V_4 -> V_29 -> V_30 == V_31 ) {
V_78 = F_46 ( & V_77 -> V_23 ,
struct V_13 ,
V_32 ) ;
V_78 -> V_61 . V_119 = ( T_1 ) V_21 -> V_48 . V_15 ;
} else if ( V_2 -> V_4 -> V_29 -> V_30 == V_33 ) {
V_137 = F_46 ( & V_77 -> V_23 ,
struct V_18 ,
V_32 ) ;
V_137 -> V_61 . V_119 = ( T_1 ) V_21 -> V_48 . V_15 ;
} else {
V_136 = F_46 ( & V_77 -> V_23 ,
struct V_19 ,
V_32 ) ;
V_136 -> V_61 . V_119 = ( T_1 ) V_21 -> V_48 . V_15 ;
}
V_138:
F_59 ( & V_21 -> V_32 , & V_2 -> V_38 ) ;
V_2 -> V_83 ++ ;
if ( V_2 -> V_54 && ( V_2 -> V_4 -> V_29 -> V_30 == V_31 )
&& F_74 ( V_2 -> V_83 > V_2 -> V_87 ) ) {
F_34 ( V_2 -> V_43 , L_12 ) ;
V_2 -> V_83 = V_2 -> V_87 ;
}
}
static T_4 F_75 ( struct V_139 * V_140 )
{
struct V_20 * V_21 = F_76 ( V_140 ) ;
struct V_1 * V_2 = F_33 ( V_140 -> V_2 ) ;
T_4 V_57 ;
unsigned long V_36 ;
int V_72 ;
if ( V_2 -> V_72 ) {
V_72 = F_68 ( V_2 ) ;
if ( V_72 < 0 )
return V_72 ;
}
F_30 ( & V_2 -> V_37 , V_36 ) ;
V_57 = F_77 ( V_140 ) ;
F_73 ( V_2 , V_21 ) ;
F_31 ( & V_2 -> V_37 , V_36 ) ;
return V_57 ;
}
static struct V_139 *
F_78 ( struct V_41 * V_42 ,
struct V_141 * V_142 ,
unsigned long V_36 )
{
struct V_1 * V_2 = F_33 ( V_42 ) ;
struct V_20 * V_21 ;
struct V_13 * V_14 , * V_143 = NULL ;
struct V_144 * V_61 ;
if ( ! F_79 ( V_142 -> V_145 ) )
return NULL ;
if ( ! V_142 -> V_146 || ! V_142 -> V_147 [ 0 ] . V_148 )
return NULL ;
if ( V_142 -> V_149 != 1 )
return NULL ;
V_21 = F_21 ( V_2 ) ;
if ( ! V_21 )
return NULL ;
F_80 ( & V_21 -> V_48 , & V_2 -> V_150 ) ;
V_21 -> V_48 . V_151 = F_75 ;
F_81 ( & V_21 -> V_48 ) ;
V_14 = F_12 ( V_2 ) ;
if ( ! V_14 )
goto error;
V_61 = & V_14 -> V_61 ;
V_61 -> V_105 = V_142 -> V_146 ;
V_61 -> V_101 = V_142 -> V_147 [ 0 ] . V_148 ;
V_61 -> V_103 = ( V_142 -> V_147 [ 0 ] . V_152 + V_142 -> V_147 [ 0 ] . V_148 ) <<
V_153 ;
V_61 -> V_103 |= V_2 -> V_76 . V_154 <<
V_155 ;
if ( V_142 -> V_145 != V_89 ) {
if ( V_2 -> V_97 ) {
V_61 -> V_98 = F_82 ( V_142 -> V_156 ) ;
V_61 -> V_99 = F_83 ( V_142 -> V_156 ) ;
} else {
V_61 -> V_98 = V_142 -> V_156 ;
}
} else {
if ( V_2 -> V_97 ) {
V_61 -> V_98 = F_82 ( V_142 -> V_157 ) ;
V_61 -> V_99 = F_83 ( V_142 -> V_157 ) ;
} else {
V_61 -> V_98 = V_142 -> V_157 ;
}
}
F_59 ( & V_14 -> V_32 , & V_21 -> V_23 ) ;
V_143 = V_14 ;
V_14 = F_56 ( & V_21 -> V_23 ,
struct V_13 , V_32 ) ;
V_21 -> V_48 . V_15 = V_14 -> V_15 ;
return & V_21 -> V_48 ;
error:
F_24 ( V_2 , V_21 ) ;
return NULL ;
}
static struct V_139 *
F_84 ( struct V_41 * V_42 , T_2 V_158 ,
T_2 V_159 , T_6 V_160 , unsigned long V_36 )
{
struct V_1 * V_2 = F_33 ( V_42 ) ;
struct V_20 * V_21 ;
struct V_18 * V_14 , * V_143 ;
struct V_111 * V_61 ;
if ( ! V_160 || V_160 > V_67 )
return NULL ;
V_21 = F_21 ( V_2 ) ;
if ( ! V_21 )
return NULL ;
F_80 ( & V_21 -> V_48 , & V_2 -> V_150 ) ;
V_21 -> V_48 . V_151 = F_75 ;
V_14 = F_14 ( V_2 ) ;
if ( ! V_14 )
goto error;
V_61 = & V_14 -> V_61 ;
V_61 -> V_65 = V_160 ;
V_61 -> V_113 = V_159 ;
V_61 -> V_115 = V_158 ;
V_143 = F_46 ( & V_21 -> V_23 ,
struct V_18 , V_32 ) ;
V_143 -> V_61 . V_119 = V_14 -> V_15 ;
F_59 ( & V_14 -> V_32 , & V_21 -> V_23 ) ;
V_143 = V_14 ;
V_14 = F_56 ( & V_21 -> V_23 ,
struct V_18 , V_32 ) ;
V_21 -> V_48 . V_15 = V_14 -> V_15 ;
V_143 -> V_61 . V_119 = V_14 -> V_15 ;
return & V_21 -> V_48 ;
error:
F_24 ( V_2 , V_21 ) ;
return NULL ;
}
static struct V_139 * F_85 (
struct V_41 * V_42 , struct V_161 * V_147 , unsigned int V_162 ,
enum V_163 V_88 , unsigned long V_36 ,
void * V_164 )
{
struct V_1 * V_2 = F_33 ( V_42 ) ;
struct V_20 * V_21 ;
struct V_19 * V_14 = NULL , * V_143 = NULL ;
T_1 * V_165 = ( T_1 * ) V_164 ;
struct V_161 * V_166 ;
T_6 V_167 ;
T_6 V_168 ;
unsigned int V_95 ;
if ( ! F_79 ( V_88 ) )
return NULL ;
V_21 = F_21 ( V_2 ) ;
if ( ! V_21 )
return NULL ;
F_80 ( & V_21 -> V_48 , & V_2 -> V_150 ) ;
V_21 -> V_48 . V_151 = F_75 ;
F_86 (sgl, sg, sg_len, i) {
V_168 = 0 ;
while ( V_168 < F_87 ( V_166 ) ) {
struct V_60 * V_61 ;
V_14 = F_16 ( V_2 ) ;
if ( ! V_14 )
goto error;
V_167 = F_88 ( T_6 , F_87 ( V_166 ) - V_168 ,
V_67 ) ;
V_61 = & V_14 -> V_61 ;
V_61 -> V_98 = F_89 ( V_166 ) + V_168 ;
V_61 -> V_65 = V_167 ;
if ( V_2 -> V_88 == V_89 ) {
if ( V_165 )
memcpy ( V_61 -> V_169 , V_165 , sizeof( T_1 ) *
V_170 ) ;
}
if ( V_143 )
V_143 -> V_61 . V_119 = V_14 -> V_15 ;
V_143 = V_14 ;
V_168 += V_167 ;
F_59 ( & V_14 -> V_32 , & V_21 -> V_23 ) ;
}
}
V_14 = F_56 ( & V_21 -> V_23 ,
struct V_19 , V_32 ) ;
V_21 -> V_48 . V_15 = V_14 -> V_15 ;
V_143 -> V_61 . V_119 = V_14 -> V_15 ;
if ( V_2 -> V_88 == V_89 ) {
V_14 -> V_61 . V_65 |= V_171 ;
V_14 = F_46 ( & V_21 -> V_23 ,
struct V_19 ,
V_32 ) ;
V_14 -> V_61 . V_65 |= V_172 ;
}
return & V_21 -> V_48 ;
error:
F_24 ( V_2 , V_21 ) ;
return NULL ;
}
static int F_90 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_33 ( V_42 ) ;
F_51 ( V_2 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
int F_91 ( struct V_41 * V_42 ,
struct V_75 * V_173 )
{
struct V_1 * V_2 = F_33 ( V_42 ) ;
T_1 V_174 ;
if ( V_173 -> V_175 )
return F_68 ( V_2 ) ;
V_174 = F_6 ( V_2 , V_52 ) ;
V_2 -> V_76 . V_154 = V_173 -> V_154 ;
V_2 -> V_76 . V_84 = V_173 -> V_84 ;
V_2 -> V_76 . V_176 = V_173 -> V_176 ;
V_2 -> V_76 . V_177 = V_173 -> V_177 ;
if ( V_173 -> V_176 && V_2 -> V_178 ) {
V_174 |= V_179 ;
V_174 |= V_173 -> V_177 << V_180 ;
}
V_2 -> V_76 . V_80 = V_173 -> V_80 ;
if ( V_173 -> V_84 )
V_2 -> V_76 . V_86 = V_173 -> V_86 ;
else
V_2 -> V_76 . V_86 = - 1 ;
V_2 -> V_76 . V_181 = V_173 -> V_181 ;
V_2 -> V_76 . V_182 = V_173 -> V_182 ;
if ( V_173 -> V_181 <= V_183 ) {
V_174 |= V_173 -> V_181 << V_184 ;
V_2 -> V_76 . V_181 = V_173 -> V_181 ;
}
if ( V_173 -> V_182 <= V_185 ) {
V_174 |= V_173 -> V_182 << V_186 ;
V_2 -> V_76 . V_182 = V_173 -> V_182 ;
}
V_174 &= ~ V_187 ;
V_174 |= V_173 -> V_188 << V_189 ;
F_7 ( V_2 , V_52 , V_174 ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_52 ,
V_53 ) ;
if ( V_2 -> V_125 > 0 )
F_93 ( V_2 -> V_125 , V_2 ) ;
F_94 ( & V_2 -> V_134 ) ;
F_26 ( & V_2 -> V_150 . V_190 ) ;
}
static int F_95 ( struct V_191 * V_192 , struct V_193 * * V_194 ,
struct V_193 * * V_195 , struct V_193 * * V_196 ,
struct V_193 * * V_197 , struct V_193 * * V_198 )
{
int V_72 ;
* V_198 = NULL ;
* V_194 = F_96 ( & V_192 -> V_43 , L_13 ) ;
if ( F_97 ( * V_194 ) ) {
V_72 = F_98 ( * V_194 ) ;
F_42 ( & V_192 -> V_43 , L_14 , V_72 ) ;
return V_72 ;
}
* V_195 = F_96 ( & V_192 -> V_43 , L_15 ) ;
if ( F_97 ( * V_195 ) )
* V_195 = NULL ;
* V_196 = F_96 ( & V_192 -> V_43 , L_16 ) ;
if ( F_97 ( * V_196 ) )
* V_196 = NULL ;
* V_197 = F_96 ( & V_192 -> V_43 , L_17 ) ;
if ( F_97 ( * V_197 ) )
* V_197 = NULL ;
V_72 = F_99 ( * V_194 ) ;
if ( V_72 ) {
F_42 ( & V_192 -> V_43 , L_18 , V_72 ) ;
return V_72 ;
}
V_72 = F_99 ( * V_195 ) ;
if ( V_72 ) {
F_42 ( & V_192 -> V_43 , L_19 , V_72 ) ;
goto V_199;
}
V_72 = F_99 ( * V_196 ) ;
if ( V_72 ) {
F_42 ( & V_192 -> V_43 , L_20 , V_72 ) ;
goto V_200;
}
V_72 = F_99 ( * V_197 ) ;
if ( V_72 ) {
F_42 ( & V_192 -> V_43 , L_21 , V_72 ) ;
goto V_201;
}
return 0 ;
V_201:
F_100 ( * V_196 ) ;
V_200:
F_100 ( * V_195 ) ;
V_199:
F_100 ( * V_194 ) ;
return V_72 ;
}
static int F_101 ( struct V_191 * V_192 , struct V_193 * * V_194 ,
struct V_193 * * V_202 , struct V_193 * * V_198 ,
struct V_193 * * V_203 , struct V_193 * * V_204 )
{
int V_72 ;
* V_198 = NULL ;
* V_203 = NULL ;
* V_204 = NULL ;
* V_194 = F_96 ( & V_192 -> V_43 , L_13 ) ;
if ( F_97 ( * V_194 ) ) {
V_72 = F_98 ( * V_194 ) ;
F_42 ( & V_192 -> V_43 , L_22 , V_72 ) ;
return V_72 ;
}
* V_202 = F_96 ( & V_192 -> V_43 , L_23 ) ;
if ( F_97 ( * V_202 ) ) {
V_72 = F_98 ( * V_202 ) ;
F_42 ( & V_192 -> V_43 , L_24 , V_72 ) ;
return V_72 ;
}
V_72 = F_99 ( * V_194 ) ;
if ( V_72 ) {
F_42 ( & V_192 -> V_43 , L_18 , V_72 ) ;
return V_72 ;
}
V_72 = F_99 ( * V_202 ) ;
if ( V_72 ) {
F_42 ( & V_192 -> V_43 , L_25 , V_72 ) ;
goto V_199;
}
return 0 ;
V_199:
F_100 ( * V_194 ) ;
return V_72 ;
}
static int F_102 ( struct V_191 * V_192 , struct V_193 * * V_194 ,
struct V_193 * * V_195 , struct V_193 * * V_205 ,
struct V_193 * * V_196 , struct V_193 * * V_206 )
{
int V_72 ;
* V_194 = F_96 ( & V_192 -> V_43 , L_13 ) ;
if ( F_97 ( * V_194 ) ) {
V_72 = F_98 ( * V_194 ) ;
F_42 ( & V_192 -> V_43 , L_14 , V_72 ) ;
return V_72 ;
}
* V_195 = F_96 ( & V_192 -> V_43 , L_15 ) ;
if ( F_97 ( * V_195 ) )
* V_195 = NULL ;
* V_205 = F_96 ( & V_192 -> V_43 , L_26 ) ;
if ( F_97 ( * V_205 ) )
* V_205 = NULL ;
* V_196 = F_96 ( & V_192 -> V_43 , L_16 ) ;
if ( F_97 ( * V_196 ) )
* V_196 = NULL ;
* V_206 = F_96 ( & V_192 -> V_43 , L_27 ) ;
if ( F_97 ( * V_206 ) )
* V_206 = NULL ;
V_72 = F_99 ( * V_194 ) ;
if ( V_72 ) {
F_42 ( & V_192 -> V_43 , L_18 , V_72 ) ;
return V_72 ;
}
V_72 = F_99 ( * V_195 ) ;
if ( V_72 ) {
F_42 ( & V_192 -> V_43 , L_19 , V_72 ) ;
goto V_199;
}
V_72 = F_99 ( * V_205 ) ;
if ( V_72 ) {
F_42 ( & V_192 -> V_43 , L_28 , V_72 ) ;
goto V_200;
}
V_72 = F_99 ( * V_196 ) ;
if ( V_72 ) {
F_42 ( & V_192 -> V_43 , L_20 , V_72 ) ;
goto V_207;
}
V_72 = F_99 ( * V_206 ) ;
if ( V_72 ) {
F_42 ( & V_192 -> V_43 , L_29 , V_72 ) ;
goto V_201;
}
return 0 ;
V_201:
F_100 ( * V_196 ) ;
V_207:
F_100 ( * V_205 ) ;
V_200:
F_100 ( * V_195 ) ;
V_199:
F_100 ( * V_194 ) ;
return V_72 ;
}
static void F_103 ( struct V_208 * V_4 )
{
F_100 ( V_4 -> V_206 ) ;
F_100 ( V_4 -> V_196 ) ;
F_100 ( V_4 -> V_205 ) ;
F_100 ( V_4 -> V_195 ) ;
F_100 ( V_4 -> V_194 ) ;
}
static int F_104 ( struct V_208 * V_4 ,
struct V_190 * V_32 )
{
struct V_1 * V_2 ;
bool V_209 = false ;
T_1 V_6 , V_210 ;
int V_72 ;
V_2 = F_105 ( V_4 -> V_43 , sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
return - V_51 ;
V_2 -> V_43 = V_4 -> V_43 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_54 = V_4 -> V_54 ;
V_2 -> V_83 = 0x0 ;
V_2 -> V_97 = V_4 -> V_97 ;
F_106 ( & V_2 -> V_37 ) ;
F_23 ( & V_2 -> V_38 ) ;
F_23 ( & V_2 -> V_39 ) ;
F_23 ( & V_2 -> V_40 ) ;
V_209 = F_107 ( V_32 , L_30 ) ;
V_2 -> V_178 = F_107 ( V_32 , L_31 ) ;
V_72 = F_108 ( V_32 , L_32 , & V_6 ) ;
if ( V_72 ) {
F_42 ( V_4 -> V_43 , L_33 ) ;
return V_72 ;
}
V_210 = V_6 >> 3 ;
if ( V_210 > 8 )
V_209 = false ;
if ( ! V_209 )
V_4 -> V_150 . V_211 = F_109 ( V_210 - 1 ) ;
if ( F_110 ( V_32 , L_34 ) ) {
V_2 -> V_88 = V_89 ;
V_2 -> V_50 = 0 ;
V_2 -> V_8 = V_212 ;
if ( V_4 -> V_29 -> V_30 == V_31 ) {
V_2 -> V_7 = V_213 ;
if ( V_4 -> V_131 == V_214 ||
V_4 -> V_131 == V_215 )
V_2 -> V_131 = true ;
}
} else if ( F_110 ( V_32 ,
L_35 ) ) {
V_2 -> V_88 = V_216 ;
V_2 -> V_50 = 1 ;
V_2 -> V_8 = V_217 ;
if ( V_4 -> V_29 -> V_30 == V_31 ) {
V_2 -> V_7 = V_218 ;
if ( V_4 -> V_131 == V_214 ||
V_4 -> V_131 == V_219 )
V_2 -> V_131 = true ;
}
} else {
F_42 ( V_4 -> V_43 , L_36 ) ;
return - V_220 ;
}
V_2 -> V_125 = F_111 ( V_32 , 0 ) ;
V_72 = F_112 ( V_2 -> V_125 , F_69 , V_221 ,
L_37 , V_2 ) ;
if ( V_72 ) {
F_42 ( V_4 -> V_43 , L_38 , V_2 -> V_125 ) ;
return V_72 ;
}
if ( V_4 -> V_29 -> V_30 == V_44 )
V_2 -> V_121 = F_62 ;
else if ( V_4 -> V_29 -> V_30 == V_33 )
V_2 -> V_121 = F_61 ;
else
V_2 -> V_121 = F_54 ;
F_113 ( & V_2 -> V_134 , F_38 ,
( unsigned long ) V_2 ) ;
V_2 -> V_150 . V_222 = & V_4 -> V_150 ;
F_59 ( & V_2 -> V_150 . V_190 , & V_4 -> V_150 . V_223 ) ;
V_4 -> V_2 [ V_2 -> V_50 ] = V_2 ;
V_72 = F_68 ( V_2 ) ;
if ( V_72 < 0 ) {
F_42 ( V_4 -> V_43 , L_39 ) ;
return V_72 ;
}
return 0 ;
}
static struct V_41 * F_114 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
struct V_208 * V_4 = V_227 -> V_228 ;
int V_229 = V_225 -> args [ 0 ] ;
if ( V_229 >= V_230 || ! V_4 -> V_2 [ V_229 ] )
return NULL ;
return F_115 ( & V_4 -> V_2 [ V_229 ] -> V_150 ) ;
}
static int F_116 ( struct V_191 * V_192 )
{
int (* F_117)( struct V_191 * , struct V_193 * * , struct V_193 * * ,
struct V_193 * * , struct V_193 * * , struct V_193 * * )
= F_102 ;
struct V_190 * V_32 = V_192 -> V_43 . V_231 ;
struct V_208 * V_4 ;
struct V_190 * V_232 , * V_233 = V_192 -> V_43 . V_231 ;
struct V_234 * V_235 ;
T_1 V_236 , V_237 ;
int V_95 , V_72 ;
V_4 = F_105 ( & V_192 -> V_43 , sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return - V_51 ;
V_4 -> V_43 = & V_192 -> V_43 ;
if ( V_233 ) {
const struct V_238 * V_239 ;
V_239 = F_118 ( V_240 , V_233 ) ;
if ( V_239 && V_239 -> V_49 ) {
V_4 -> V_29 = V_239 -> V_49 ;
F_117 = V_4 -> V_29 -> F_117 ;
}
}
V_72 = F_117 ( V_192 , & V_4 -> V_194 , & V_4 -> V_195 , & V_4 -> V_205 ,
& V_4 -> V_196 , & V_4 -> V_206 ) ;
if ( V_72 )
return V_72 ;
V_235 = F_119 ( V_192 , V_241 , 0 ) ;
V_4 -> V_5 = F_120 ( & V_192 -> V_43 , V_235 ) ;
if ( F_97 ( V_4 -> V_5 ) )
return F_98 ( V_4 -> V_5 ) ;
V_4 -> V_54 = F_107 ( V_32 , L_40 ) ;
if ( V_4 -> V_29 -> V_30 == V_31 ) {
V_72 = F_108 ( V_32 , L_41 ,
& V_236 ) ;
if ( V_72 < 0 ) {
F_42 ( V_4 -> V_43 ,
L_42 ) ;
return V_72 ;
}
V_72 = F_108 ( V_32 , L_43 ,
& V_4 -> V_131 ) ;
if ( V_72 < 0 )
F_121 ( V_4 -> V_43 ,
L_44 ) ;
}
V_72 = F_108 ( V_32 , L_45 , & V_237 ) ;
if ( V_72 < 0 )
F_121 ( V_4 -> V_43 , L_46 ) ;
if ( V_237 > 32 )
V_4 -> V_97 = true ;
else
V_4 -> V_97 = false ;
F_122 ( V_4 -> V_43 , F_123 ( V_237 ) ) ;
V_4 -> V_150 . V_43 = & V_192 -> V_43 ;
F_23 ( & V_4 -> V_150 . V_223 ) ;
if ( ! ( V_4 -> V_29 -> V_30 == V_33 ) ) {
F_124 ( V_242 , V_4 -> V_150 . V_243 ) ;
F_124 ( V_244 , V_4 -> V_150 . V_243 ) ;
}
V_4 -> V_150 . V_245 =
F_39 ;
V_4 -> V_150 . V_246 =
F_32 ;
V_4 -> V_150 . V_247 = F_90 ;
V_4 -> V_150 . V_248 = F_44 ;
V_4 -> V_150 . V_249 = F_64 ;
if ( V_4 -> V_29 -> V_30 == V_44 ) {
V_4 -> V_150 . V_250 = F_85 ;
V_4 -> V_150 . V_251 =
V_252 ;
} else if ( V_4 -> V_29 -> V_30 == V_33 ) {
F_124 ( V_253 , V_4 -> V_150 . V_243 ) ;
V_4 -> V_150 . V_254 = F_84 ;
} else {
V_4 -> V_150 . V_255 =
F_78 ;
}
F_125 ( V_192 , V_4 ) ;
F_126 (node, child) {
V_72 = F_104 ( V_4 , V_232 ) ;
if ( V_72 < 0 )
goto V_256;
}
if ( V_4 -> V_29 -> V_30 == V_31 ) {
for ( V_95 = 0 ; V_95 < V_230 ; V_95 ++ )
if ( V_4 -> V_2 [ V_95 ] )
V_4 -> V_2 [ V_95 ] -> V_87 = V_236 ;
}
F_127 ( & V_4 -> V_150 ) ;
V_72 = F_128 ( V_32 , F_114 ,
V_4 ) ;
if ( V_72 < 0 ) {
F_42 ( & V_192 -> V_43 , L_47 ) ;
F_129 ( & V_4 -> V_150 ) ;
goto error;
}
F_130 ( & V_192 -> V_43 , L_48 ) ;
return 0 ;
V_256:
F_103 ( V_4 ) ;
error:
for ( V_95 = 0 ; V_95 < V_230 ; V_95 ++ )
if ( V_4 -> V_2 [ V_95 ] )
F_92 ( V_4 -> V_2 [ V_95 ] ) ;
return V_72 ;
}
static int F_131 ( struct V_191 * V_192 )
{
struct V_208 * V_4 = F_132 ( V_192 ) ;
int V_95 ;
F_133 ( V_192 -> V_43 . V_231 ) ;
F_129 ( & V_4 -> V_150 ) ;
for ( V_95 = 0 ; V_95 < V_230 ; V_95 ++ )
if ( V_4 -> V_2 [ V_95 ] )
F_92 ( V_4 -> V_2 [ V_95 ] ) ;
F_103 ( V_4 ) ;
return 0 ;
}
