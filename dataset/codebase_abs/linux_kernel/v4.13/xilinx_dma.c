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
static inline void F_12 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_6 )
{
F_13 ( V_6 , V_2 -> V_4 -> V_5 + V_2 -> V_8 + V_3 ) ;
}
static inline void F_14 ( struct V_1 * V_2 , T_1 V_3 ,
T_3 V_13 )
{
if ( V_2 -> V_14 )
F_12 ( V_2 , V_3 , V_13 ) ;
else
F_7 ( V_2 , V_3 , V_13 ) ;
}
static inline void F_15 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
T_3 V_17 , T_4 V_18 ,
T_4 V_19 )
{
if ( V_2 -> V_14 ) {
V_16 -> V_17 = F_16 ( V_17 + V_18 + V_19 ) ;
V_16 -> V_20 = F_17 ( V_17 + V_18 +
V_19 ) ;
} else {
V_16 -> V_17 = V_17 + V_18 + V_19 ;
}
}
static struct V_21 *
F_18 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
T_3 V_23 ;
V_22 = F_19 ( V_2 -> V_24 , V_25 , & V_23 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_23 = V_23 ;
return V_22 ;
}
static struct V_26 *
F_20 ( struct V_1 * V_2 )
{
struct V_26 * V_22 ;
T_3 V_23 ;
V_22 = F_19 ( V_2 -> V_24 , V_25 , & V_23 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_23 = V_23 ;
return V_22 ;
}
static struct V_27 *
F_21 ( struct V_1 * V_2 )
{
struct V_27 * V_22 ;
T_3 V_23 ;
V_22 = F_19 ( V_2 -> V_24 , V_25 , & V_23 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_23 = V_23 ;
return V_22 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_27 * V_22 )
{
F_23 ( V_2 -> V_24 , V_22 , V_22 -> V_23 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_26 * V_22 )
{
F_23 ( V_2 -> V_24 , V_22 , V_22 -> V_23 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
F_23 ( V_2 -> V_24 , V_22 , V_22 -> V_23 ) ;
}
static struct V_28 *
F_26 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
V_29 = F_27 ( sizeof( * V_29 ) , V_30 ) ;
if ( ! V_29 )
return NULL ;
F_28 ( & V_29 -> V_31 ) ;
return V_29 ;
}
static void
F_29 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_21 * V_22 , * V_32 ;
struct V_26 * V_33 , * V_34 ;
struct V_27 * V_35 , * V_36 ;
if ( ! V_29 )
return;
if ( V_2 -> V_4 -> V_37 -> V_38 == V_39 ) {
F_30 (segment, next, &desc->segments, node) {
F_31 ( & V_22 -> V_40 ) ;
F_25 ( V_2 , V_22 ) ;
}
} else if ( V_2 -> V_4 -> V_37 -> V_38 == V_41 ) {
F_30 (cdma_segment, cdma_next,
&desc->segments, node) {
F_31 ( & V_33 -> V_40 ) ;
F_24 ( V_2 , V_33 ) ;
}
} else {
F_30 (axidma_segment, axidma_next,
&desc->segments, node) {
F_31 ( & V_35 -> V_40 ) ;
F_22 ( V_2 , V_35 ) ;
}
}
F_32 ( V_29 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_28 * V_29 , * V_32 ;
F_30 (desc, next, list, node) {
F_31 ( & V_29 -> V_40 ) ;
F_29 ( V_2 , V_29 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_35 ( & V_2 -> V_45 , V_44 ) ;
F_33 ( V_2 , & V_2 -> V_46 ) ;
F_33 ( V_2 , & V_2 -> V_47 ) ;
F_33 ( V_2 , & V_2 -> V_48 ) ;
F_36 ( & V_2 -> V_45 , V_44 ) ;
}
static void F_37 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
F_39 ( V_2 -> V_51 , L_1 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_4 -> V_37 -> V_38 == V_52 ) {
F_22 ( V_2 , V_2 -> V_53 ) ;
F_22 ( V_2 , V_2 -> V_54 ) ;
}
F_40 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
unsigned long * V_44 )
{
T_5 V_55 ;
void * V_56 ;
V_55 = V_29 -> V_57 . V_55 ;
V_56 = V_29 -> V_57 . V_56 ;
if ( V_55 ) {
F_36 ( & V_2 -> V_45 , * V_44 ) ;
V_55 ( V_56 ) ;
F_35 ( & V_2 -> V_45 , * V_44 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_28 * V_29 , * V_32 ;
unsigned long V_44 ;
F_35 ( & V_2 -> V_45 , V_44 ) ;
F_30 (desc, next, &chan->done_list, node) {
struct V_58 V_59 ;
if ( V_29 -> V_60 ) {
F_41 ( V_2 , V_29 , & V_44 ) ;
break;
}
F_31 ( & V_29 -> V_40 ) ;
F_43 ( & V_29 -> V_57 , & V_59 ) ;
if ( F_44 ( & V_59 ) ) {
F_36 ( & V_2 -> V_45 , V_44 ) ;
F_45 ( & V_59 , NULL ) ;
F_35 ( & V_2 -> V_45 , V_44 ) ;
}
F_46 ( & V_29 -> V_57 ) ;
F_29 ( V_2 , V_29 ) ;
}
F_36 ( & V_2 -> V_45 , V_44 ) ;
}
static void F_47 ( unsigned long V_61 )
{
struct V_1 * V_2 = (struct V_1 * ) V_61 ;
F_42 ( V_2 ) ;
}
static int F_48 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
if ( V_2 -> V_24 )
return 0 ;
if ( V_2 -> V_4 -> V_37 -> V_38 == V_52 ) {
V_2 -> V_24 = F_49 ( L_2 ,
V_2 -> V_51 ,
sizeof( struct V_27 ) ,
F_50 ( struct V_27 ) ,
0 ) ;
} else if ( V_2 -> V_4 -> V_37 -> V_38 == V_41 ) {
V_2 -> V_24 = F_49 ( L_3 ,
V_2 -> V_51 ,
sizeof( struct V_26 ) ,
F_50 ( struct V_26 ) ,
0 ) ;
} else {
V_2 -> V_24 = F_49 ( L_4 ,
V_2 -> V_51 ,
sizeof( struct V_21 ) ,
F_50 ( struct V_21 ) ,
0 ) ;
}
if ( ! V_2 -> V_24 ) {
F_51 ( V_2 -> V_51 ,
L_5 ,
V_2 -> V_62 ) ;
return - V_63 ;
}
if ( V_2 -> V_4 -> V_37 -> V_38 == V_52 ) {
V_2 -> V_54 = F_21 ( V_2 ) ;
V_2 -> V_53 = F_21 ( V_2 ) ;
}
F_52 ( V_50 ) ;
if ( V_2 -> V_4 -> V_37 -> V_38 == V_52 ) {
F_9 ( V_2 , V_64 ,
V_65 ) ;
}
if ( ( V_2 -> V_4 -> V_37 -> V_38 == V_41 ) && V_2 -> V_66 )
F_9 ( V_2 , V_64 ,
V_67 ) ;
return 0 ;
}
static enum V_68 F_53 ( struct V_49 * V_50 ,
T_6 V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
struct V_28 * V_29 ;
struct V_27 * V_22 ;
struct V_15 * V_16 ;
enum V_68 V_72 ;
unsigned long V_44 ;
T_1 V_73 = 0 ;
V_72 = F_54 ( V_50 , V_69 , V_71 ) ;
if ( V_72 == V_74 || ! V_71 )
return V_72 ;
if ( V_2 -> V_4 -> V_37 -> V_38 == V_52 ) {
F_35 ( & V_2 -> V_45 , V_44 ) ;
V_29 = F_55 ( & V_2 -> V_48 ,
struct V_28 , V_40 ) ;
if ( V_2 -> V_66 ) {
F_56 (segment, &desc->segments, node) {
V_16 = & V_22 -> V_16 ;
V_73 += ( V_16 -> V_75 - V_16 -> V_76 ) &
V_77 ;
}
}
F_36 ( & V_2 -> V_45 , V_44 ) ;
V_2 -> V_73 = V_73 ;
F_57 ( V_71 , V_2 -> V_73 ) ;
}
return V_72 ;
}
static bool F_58 ( struct V_1 * V_2 )
{
return ! ( F_6 ( V_2 , V_78 ) &
V_79 ) &&
( F_6 ( V_2 , V_64 ) &
V_80 ) ;
}
static bool F_59 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_78 ) &
V_81 ;
}
static int F_60 ( struct V_1 * V_2 )
{
T_1 V_82 ;
F_8 ( V_2 , V_64 , V_80 ) ;
return F_61 ( V_2 , V_78 , V_82 ,
V_82 & V_79 , 0 ,
V_83 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
T_1 V_82 ;
return F_61 ( V_2 , V_78 , V_82 ,
V_82 & V_81 , 0 ,
V_83 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
int V_84 ;
T_1 V_82 ;
F_9 ( V_2 , V_64 , V_80 ) ;
V_84 = F_61 ( V_2 , V_78 , V_82 ,
! ( V_82 & V_79 ) , 0 ,
V_83 ) ;
if ( V_84 ) {
F_51 ( V_2 -> V_51 , L_6 ,
V_2 , F_6 ( V_2 , V_78 ) ) ;
V_2 -> V_84 = true ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_85 * V_86 = & V_2 -> V_86 ;
struct V_28 * V_29 , * V_87 ;
T_1 V_3 ;
struct V_21 * V_88 ;
if ( V_2 -> V_84 )
return;
if ( F_65 ( & V_2 -> V_46 ) )
return;
V_29 = F_66 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
V_87 = F_55 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
V_88 = F_55 ( & V_87 -> V_31 ,
struct V_21 , V_40 ) ;
if ( V_2 -> V_66 && F_58 ( V_2 ) &&
! F_59 ( V_2 ) ) {
F_39 ( V_2 -> V_51 , L_7 ) ;
return;
}
if ( V_2 -> V_66 )
F_7 ( V_2 , V_89 ,
V_29 -> V_57 . V_23 ) ;
V_3 = F_6 ( V_2 , V_64 ) ;
if ( V_86 -> V_90 )
V_3 |= V_91 ;
else
V_3 &= ~ V_91 ;
F_7 ( V_2 , V_92 ,
V_2 -> V_93 ) ;
if ( V_2 -> V_66 || ! V_86 -> V_94 )
V_3 |= V_95 ;
if ( V_86 -> V_94 )
V_3 &= ~ V_95 ;
F_7 ( V_2 , V_64 , V_3 ) ;
if ( V_86 -> V_94 && ( V_86 -> V_96 >= 0 ) &&
( V_86 -> V_96 < V_2 -> V_97 ) ) {
if ( V_2 -> V_98 == V_99 )
F_3 ( V_2 , V_100 ,
V_86 -> V_96 <<
V_101 ) ;
else
F_3 ( V_2 , V_100 ,
V_86 -> V_96 <<
V_102 ) ;
}
F_63 ( V_2 ) ;
if ( V_2 -> V_84 )
return;
if ( V_2 -> V_66 ) {
F_7 ( V_2 , V_103 ,
V_88 -> V_23 ) ;
} else {
struct V_21 * V_22 , * V_104 = NULL ;
int V_105 = 0 ;
if ( V_2 -> V_106 < V_2 -> V_97 )
V_105 = V_2 -> V_106 ;
F_56 (segment, &desc->segments, node) {
if ( V_2 -> V_14 )
F_10 ( V_2 ,
F_67 ( V_105 ++ ) ,
V_22 -> V_16 . V_17 ,
V_22 -> V_16 . V_20 ) ;
else
F_5 ( V_2 ,
F_68 ( V_105 ++ ) ,
V_22 -> V_16 . V_17 ) ;
V_104 = V_22 ;
}
if ( ! V_104 )
return;
F_5 ( V_2 , V_107 , V_104 -> V_16 . V_108 ) ;
F_5 ( V_2 , V_109 ,
V_104 -> V_16 . V_110 ) ;
F_5 ( V_2 , V_111 , V_104 -> V_16 . V_112 ) ;
}
if ( ! V_2 -> V_66 ) {
F_31 ( & V_29 -> V_40 ) ;
F_69 ( & V_29 -> V_40 , & V_2 -> V_48 ) ;
V_2 -> V_106 ++ ;
V_2 -> V_93 -- ;
if ( V_2 -> V_106 == V_2 -> V_97 )
V_2 -> V_106 = 0 ;
} else {
F_70 ( & V_2 -> V_46 , & V_2 -> V_48 ) ;
V_2 -> V_93 = 0 ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_28 * V_113 , * V_87 ;
struct V_26 * V_88 ;
T_1 V_114 = F_1 ( V_2 , V_64 ) ;
if ( V_2 -> V_84 )
return;
if ( F_65 ( & V_2 -> V_46 ) )
return;
V_113 = F_66 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
V_87 = F_55 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
V_88 = F_55 ( & V_87 -> V_31 ,
struct V_26 , V_40 ) ;
if ( V_2 -> V_93 <= V_115 ) {
V_114 &= ~ V_116 ;
V_114 |= V_2 -> V_93 <<
V_117 ;
F_7 ( V_2 , V_64 , V_114 ) ;
}
if ( V_2 -> V_66 ) {
F_14 ( V_2 , V_89 ,
V_113 -> V_57 . V_23 ) ;
F_14 ( V_2 , V_103 ,
V_88 -> V_23 ) ;
} else {
struct V_26 * V_22 ;
struct V_118 * V_16 ;
V_22 = F_66 ( & V_113 -> V_31 ,
struct V_26 ,
V_40 ) ;
V_16 = & V_22 -> V_16 ;
F_14 ( V_2 , V_119 , V_16 -> V_120 ) ;
F_14 ( V_2 , V_121 , V_16 -> V_122 ) ;
F_7 ( V_2 , V_123 ,
V_16 -> V_75 & V_77 ) ;
}
F_70 ( & V_2 -> V_46 , & V_2 -> V_48 ) ;
V_2 -> V_93 = 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_28 * V_113 , * V_87 ;
struct V_27 * V_88 , * V_124 , * V_125 ;
T_1 V_3 ;
if ( V_2 -> V_84 )
return;
if ( F_65 ( & V_2 -> V_46 ) )
return;
if ( V_2 -> V_66 && F_58 ( V_2 ) &&
! F_59 ( V_2 ) ) {
F_39 ( V_2 -> V_51 , L_7 ) ;
return;
}
V_113 = F_66 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
V_87 = F_55 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
V_88 = F_55 ( & V_87 -> V_31 ,
struct V_27 , V_40 ) ;
if ( V_2 -> V_66 && ! V_2 -> V_4 -> V_126 ) {
V_124 = F_66 ( & V_113 -> V_31 ,
struct V_27 , V_40 ) ;
V_125 = V_2 -> V_54 ;
V_125 -> V_16 = V_124 -> V_16 ;
F_73 ( & V_124 -> V_40 , & V_125 -> V_40 ) ;
V_2 -> V_54 = V_124 ;
V_88 -> V_16 . V_127 = V_2 -> V_54 -> V_23 ;
V_113 -> V_57 . V_23 = V_125 -> V_23 ;
}
V_3 = F_6 ( V_2 , V_64 ) ;
if ( V_2 -> V_93 <= V_115 ) {
V_3 &= ~ V_116 ;
V_3 |= V_2 -> V_93 <<
V_117 ;
F_7 ( V_2 , V_64 , V_3 ) ;
}
if ( V_2 -> V_66 && ! V_2 -> V_4 -> V_126 )
F_14 ( V_2 , V_89 ,
V_113 -> V_57 . V_23 ) ;
if ( V_2 -> V_66 && V_2 -> V_4 -> V_126 ) {
if ( V_2 -> V_98 == V_99 ) {
F_7 ( V_2 , V_89 ,
V_113 -> V_57 . V_23 ) ;
} else {
if ( ! V_2 -> V_128 ) {
F_7 ( V_2 , V_89 ,
V_113 -> V_57 . V_23 ) ;
} else {
F_7 ( V_2 ,
F_74 ( V_2 -> V_128 ) ,
V_113 -> V_57 . V_23 ) ;
}
}
}
F_63 ( V_2 ) ;
if ( V_2 -> V_84 )
return;
if ( V_2 -> V_66 && ! V_2 -> V_4 -> V_126 ) {
if ( V_2 -> V_60 )
F_14 ( V_2 , V_103 ,
V_2 -> V_53 -> V_23 ) ;
else
F_14 ( V_2 , V_103 ,
V_88 -> V_23 ) ;
} else if ( V_2 -> V_66 && V_2 -> V_4 -> V_126 ) {
if ( V_2 -> V_98 == V_99 ) {
F_7 ( V_2 , V_103 ,
V_88 -> V_23 ) ;
} else {
if ( ! V_2 -> V_128 ) {
F_7 ( V_2 , V_103 ,
V_88 -> V_23 ) ;
} else {
F_7 ( V_2 ,
F_75 ( V_2 -> V_128 ) ,
V_88 -> V_23 ) ;
}
}
} else {
struct V_27 * V_22 ;
struct V_15 * V_16 ;
V_22 = F_66 ( & V_113 -> V_31 ,
struct V_27 ,
V_40 ) ;
V_16 = & V_22 -> V_16 ;
F_14 ( V_2 , V_129 , V_16 -> V_17 ) ;
F_7 ( V_2 , V_123 ,
V_16 -> V_75 & V_77 ) ;
}
F_70 ( & V_2 -> V_46 , & V_2 -> V_48 ) ;
V_2 -> V_93 = 0 ;
}
static void F_76 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
unsigned long V_44 ;
F_35 ( & V_2 -> V_45 , V_44 ) ;
V_2 -> V_130 ( V_2 ) ;
F_36 ( & V_2 -> V_45 , V_44 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_28 * V_29 , * V_32 ;
if ( F_65 ( & V_2 -> V_48 ) )
return;
F_30 (desc, next, &chan->active_list, node) {
F_31 ( & V_29 -> V_40 ) ;
if ( ! V_29 -> V_60 )
F_78 ( & V_29 -> V_57 ) ;
F_69 ( & V_29 -> V_40 , & V_2 -> V_47 ) ;
}
}
static int F_79 ( struct V_1 * V_2 )
{
int V_84 ;
T_1 V_131 ;
F_9 ( V_2 , V_64 , V_132 ) ;
V_84 = F_61 ( V_2 , V_64 , V_131 ,
! ( V_131 & V_132 ) , 0 ,
V_83 ) ;
if ( V_84 ) {
F_51 ( V_2 -> V_51 , L_8 ,
F_6 ( V_2 , V_64 ) ,
F_6 ( V_2 , V_78 ) ) ;
return - V_133 ;
}
V_2 -> V_84 = false ;
return V_84 ;
}
static int F_80 ( struct V_1 * V_2 )
{
int V_84 ;
V_84 = F_79 ( V_2 ) ;
if ( V_84 )
return V_84 ;
F_9 ( V_2 , V_64 ,
V_65 ) ;
return 0 ;
}
static T_7 F_81 ( int V_134 , void * V_61 )
{
struct V_1 * V_2 = V_61 ;
T_1 V_76 ;
V_76 = F_6 ( V_2 , V_78 ) ;
if ( ! ( V_76 & V_65 ) )
return V_135 ;
F_7 ( V_2 , V_78 ,
V_76 & V_65 ) ;
if ( V_76 & V_136 ) {
T_1 V_137 = V_76 & V_138 ;
F_7 ( V_2 , V_78 ,
V_137 & V_139 ) ;
if ( ! V_2 -> V_140 ||
( V_137 & ~ V_139 ) ) {
F_51 ( V_2 -> V_51 ,
L_9 ,
V_2 , V_137 ,
F_6 ( V_2 , V_89 ) ,
F_6 ( V_2 , V_103 ) ) ;
V_2 -> V_84 = true ;
}
}
if ( V_76 & V_141 ) {
F_39 ( V_2 -> V_51 , L_10 ) ;
}
if ( V_76 & V_142 ) {
F_82 ( & V_2 -> V_45 ) ;
F_77 ( V_2 ) ;
V_2 -> V_130 ( V_2 ) ;
F_83 ( & V_2 -> V_45 ) ;
}
F_84 ( & V_2 -> V_143 ) ;
return V_144 ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_21 * V_88 ;
struct V_28 * V_87 ;
struct V_27 * V_145 ;
struct V_26 * V_146 ;
if ( F_65 ( & V_2 -> V_46 ) )
goto V_147;
V_87 = F_55 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
if ( V_2 -> V_4 -> V_37 -> V_38 == V_39 ) {
V_88 = F_55 ( & V_87 -> V_31 ,
struct V_21 ,
V_40 ) ;
V_88 -> V_16 . V_127 = ( T_1 ) V_29 -> V_57 . V_23 ;
} else if ( V_2 -> V_4 -> V_37 -> V_38 == V_41 ) {
V_146 = F_55 ( & V_87 -> V_31 ,
struct V_26 ,
V_40 ) ;
V_146 -> V_16 . V_127 = ( T_1 ) V_29 -> V_57 . V_23 ;
} else {
V_145 = F_55 ( & V_87 -> V_31 ,
struct V_27 ,
V_40 ) ;
V_145 -> V_16 . V_127 = ( T_1 ) V_29 -> V_57 . V_23 ;
}
V_147:
F_69 ( & V_29 -> V_40 , & V_2 -> V_46 ) ;
V_2 -> V_93 ++ ;
if ( V_2 -> V_66 && ( V_2 -> V_4 -> V_37 -> V_38 == V_39 )
&& F_86 ( V_2 -> V_93 > V_2 -> V_97 ) ) {
F_39 ( V_2 -> V_51 , L_11 ) ;
V_2 -> V_93 = V_2 -> V_97 ;
}
}
static T_6 F_87 ( struct V_148 * V_149 )
{
struct V_28 * V_29 = F_88 ( V_149 ) ;
struct V_1 * V_2 = F_38 ( V_149 -> V_2 ) ;
T_6 V_69 ;
unsigned long V_44 ;
int V_84 ;
if ( V_2 -> V_60 ) {
F_29 ( V_2 , V_29 ) ;
return - V_150 ;
}
if ( V_2 -> V_84 ) {
V_84 = F_80 ( V_2 ) ;
if ( V_84 < 0 )
return V_84 ;
}
F_35 ( & V_2 -> V_45 , V_44 ) ;
V_69 = F_89 ( V_149 ) ;
F_85 ( V_2 , V_29 ) ;
if ( V_29 -> V_60 )
V_2 -> V_60 = true ;
F_36 ( & V_2 -> V_45 , V_44 ) ;
return V_69 ;
}
static struct V_148 *
F_90 ( struct V_49 * V_50 ,
struct V_151 * V_152 ,
unsigned long V_44 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
struct V_28 * V_29 ;
struct V_21 * V_22 , * V_153 = NULL ;
struct V_154 * V_16 ;
if ( ! F_91 ( V_152 -> V_155 ) )
return NULL ;
if ( ! V_152 -> V_156 || ! V_152 -> V_157 [ 0 ] . V_158 )
return NULL ;
if ( V_152 -> V_159 != 1 )
return NULL ;
V_29 = F_26 ( V_2 ) ;
if ( ! V_29 )
return NULL ;
F_92 ( & V_29 -> V_57 , & V_2 -> V_160 ) ;
V_29 -> V_57 . V_161 = F_87 ;
F_93 ( & V_29 -> V_57 ) ;
V_22 = F_18 ( V_2 ) ;
if ( ! V_22 )
goto error;
V_16 = & V_22 -> V_16 ;
V_16 -> V_112 = V_152 -> V_156 ;
V_16 -> V_108 = V_152 -> V_157 [ 0 ] . V_158 ;
V_16 -> V_110 = ( V_152 -> V_157 [ 0 ] . V_162 + V_152 -> V_157 [ 0 ] . V_158 ) <<
V_163 ;
V_16 -> V_110 |= V_2 -> V_86 . V_164 <<
V_165 ;
if ( V_152 -> V_155 != V_99 ) {
if ( V_2 -> V_14 ) {
V_16 -> V_17 = F_16 ( V_152 -> V_166 ) ;
V_16 -> V_20 = F_17 ( V_152 -> V_166 ) ;
} else {
V_16 -> V_17 = V_152 -> V_166 ;
}
} else {
if ( V_2 -> V_14 ) {
V_16 -> V_17 = F_16 ( V_152 -> V_167 ) ;
V_16 -> V_20 = F_17 ( V_152 -> V_167 ) ;
} else {
V_16 -> V_17 = V_152 -> V_167 ;
}
}
F_69 ( & V_22 -> V_40 , & V_29 -> V_31 ) ;
V_153 = V_22 ;
V_22 = F_66 ( & V_29 -> V_31 ,
struct V_21 , V_40 ) ;
V_29 -> V_57 . V_23 = V_22 -> V_23 ;
return & V_29 -> V_57 ;
error:
F_29 ( V_2 , V_29 ) ;
return NULL ;
}
static struct V_148 *
F_94 ( struct V_49 * V_50 , T_3 V_168 ,
T_3 V_169 , T_4 V_170 , unsigned long V_44 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
struct V_28 * V_29 ;
struct V_26 * V_22 ;
struct V_118 * V_16 ;
if ( ! V_170 || V_170 > V_77 )
return NULL ;
V_29 = F_26 ( V_2 ) ;
if ( ! V_29 )
return NULL ;
F_92 ( & V_29 -> V_57 , & V_2 -> V_160 ) ;
V_29 -> V_57 . V_161 = F_87 ;
V_22 = F_20 ( V_2 ) ;
if ( ! V_22 )
goto error;
V_16 = & V_22 -> V_16 ;
V_16 -> V_75 = V_170 ;
V_16 -> V_120 = V_169 ;
V_16 -> V_122 = V_168 ;
if ( V_2 -> V_14 ) {
V_16 -> V_171 = F_17 ( V_169 ) ;
V_16 -> V_172 = F_17 ( V_168 ) ;
}
F_69 ( & V_22 -> V_40 , & V_29 -> V_31 ) ;
V_29 -> V_57 . V_23 = V_22 -> V_23 ;
V_16 -> V_127 = V_22 -> V_23 ;
return & V_29 -> V_57 ;
error:
F_29 ( V_2 , V_29 ) ;
return NULL ;
}
static struct V_148 * F_95 (
struct V_49 * V_50 , struct V_173 * V_157 , unsigned int V_174 ,
enum V_175 V_98 , unsigned long V_44 ,
void * V_176 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
struct V_28 * V_29 ;
struct V_27 * V_22 = NULL , * V_153 = NULL ;
T_1 * V_177 = ( T_1 * ) V_176 ;
struct V_173 * V_178 ;
T_4 V_179 ;
T_4 V_18 ;
unsigned int V_105 ;
if ( ! F_91 ( V_98 ) )
return NULL ;
V_29 = F_26 ( V_2 ) ;
if ( ! V_29 )
return NULL ;
F_92 ( & V_29 -> V_57 , & V_2 -> V_160 ) ;
V_29 -> V_57 . V_161 = F_87 ;
F_96 (sgl, sg, sg_len, i) {
V_18 = 0 ;
while ( V_18 < F_97 ( V_178 ) ) {
struct V_15 * V_16 ;
V_22 = F_21 ( V_2 ) ;
if ( ! V_22 )
goto error;
V_179 = F_98 ( T_4 , F_97 ( V_178 ) - V_18 ,
V_77 ) ;
V_16 = & V_22 -> V_16 ;
F_15 ( V_2 , V_16 , F_99 ( V_178 ) ,
V_18 , 0 ) ;
V_16 -> V_75 = V_179 ;
if ( V_2 -> V_98 == V_99 ) {
if ( V_177 )
memcpy ( V_16 -> V_180 , V_177 , sizeof( T_1 ) *
V_181 ) ;
}
if ( V_153 )
V_153 -> V_16 . V_127 = V_22 -> V_23 ;
V_153 = V_22 ;
V_18 += V_179 ;
F_69 ( & V_22 -> V_40 , & V_29 -> V_31 ) ;
}
}
V_22 = F_66 ( & V_29 -> V_31 ,
struct V_27 , V_40 ) ;
V_29 -> V_57 . V_23 = V_22 -> V_23 ;
V_153 -> V_16 . V_127 = V_22 -> V_23 ;
if ( V_2 -> V_98 == V_99 ) {
V_22 -> V_16 . V_75 |= V_182 ;
V_22 = F_55 ( & V_29 -> V_31 ,
struct V_27 ,
V_40 ) ;
V_22 -> V_16 . V_75 |= V_183 ;
}
return & V_29 -> V_57 ;
error:
F_29 ( V_2 , V_29 ) ;
return NULL ;
}
static struct V_148 * F_100 (
struct V_49 * V_50 , T_3 V_17 , T_4 V_184 ,
T_4 V_19 , enum V_175 V_98 ,
unsigned long V_44 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
struct V_28 * V_29 ;
struct V_27 * V_22 , * V_185 , * V_153 = NULL ;
T_4 V_179 , V_18 ;
unsigned int V_186 ;
int V_105 ;
T_1 V_3 ;
if ( ! V_19 )
return NULL ;
V_186 = V_184 / V_19 ;
if ( ! V_186 )
return NULL ;
if ( ! F_91 ( V_98 ) )
return NULL ;
V_29 = F_26 ( V_2 ) ;
if ( ! V_29 )
return NULL ;
V_2 -> V_98 = V_98 ;
F_92 ( & V_29 -> V_57 , & V_2 -> V_160 ) ;
V_29 -> V_57 . V_161 = F_87 ;
for ( V_105 = 0 ; V_105 < V_186 ; ++ V_105 ) {
V_18 = 0 ;
while ( V_18 < V_19 ) {
struct V_15 * V_16 ;
V_22 = F_21 ( V_2 ) ;
if ( ! V_22 )
goto error;
V_179 = F_98 ( T_4 , V_19 - V_18 ,
V_77 ) ;
V_16 = & V_22 -> V_16 ;
F_15 ( V_2 , V_16 , V_17 , V_18 ,
V_19 * V_105 ) ;
V_16 -> V_75 = V_179 ;
if ( V_153 )
V_153 -> V_16 . V_127 = V_22 -> V_23 ;
V_153 = V_22 ;
V_18 += V_179 ;
F_69 ( & V_22 -> V_40 , & V_29 -> V_31 ) ;
}
}
V_185 = F_66 ( & V_29 -> V_31 ,
struct V_27 , V_40 ) ;
V_29 -> V_57 . V_23 = V_185 -> V_23 ;
V_29 -> V_60 = true ;
V_3 = F_6 ( V_2 , V_64 ) ;
V_3 |= V_187 ;
F_7 ( V_2 , V_64 , V_3 ) ;
V_22 = F_55 ( & V_29 -> V_31 ,
struct V_27 ,
V_40 ) ;
V_22 -> V_16 . V_127 = ( T_1 ) V_185 -> V_23 ;
if ( V_98 == V_99 ) {
V_185 -> V_16 . V_75 |= V_182 ;
V_22 -> V_16 . V_75 |= V_183 ;
}
return & V_29 -> V_57 ;
error:
F_29 ( V_2 , V_29 ) ;
return NULL ;
}
static struct V_148 *
F_101 ( struct V_49 * V_50 ,
struct V_151 * V_152 ,
unsigned long V_44 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
struct V_28 * V_29 ;
struct V_27 * V_22 ;
struct V_15 * V_16 ;
if ( ! F_91 ( V_152 -> V_155 ) )
return NULL ;
if ( ! V_152 -> V_156 || ! V_152 -> V_157 [ 0 ] . V_158 )
return NULL ;
if ( V_152 -> V_159 != 1 )
return NULL ;
V_29 = F_26 ( V_2 ) ;
if ( ! V_29 )
return NULL ;
V_2 -> V_98 = V_152 -> V_155 ;
F_92 ( & V_29 -> V_57 , & V_2 -> V_160 ) ;
V_29 -> V_57 . V_161 = F_87 ;
V_22 = F_21 ( V_2 ) ;
if ( ! V_22 )
goto error;
V_16 = & V_22 -> V_16 ;
if ( V_152 -> V_155 != V_99 )
V_16 -> V_17 = V_152 -> V_166 ;
else
V_16 -> V_17 = V_152 -> V_167 ;
V_16 -> V_188 = V_2 -> V_128 & V_189 ;
V_16 -> V_190 = ( V_152 -> V_156 << V_191 ) &
V_192 ;
V_16 -> V_190 |= ( V_152 -> V_157 [ 0 ] . V_162 + V_152 -> V_157 [ 0 ] . V_158 ) &
V_193 ;
V_16 -> V_75 = V_152 -> V_157 [ 0 ] . V_158 & V_194 ;
F_69 ( & V_22 -> V_40 , & V_29 -> V_31 ) ;
V_22 = F_66 ( & V_29 -> V_31 ,
struct V_27 , V_40 ) ;
V_29 -> V_57 . V_23 = V_22 -> V_23 ;
if ( V_152 -> V_155 == V_99 ) {
V_22 -> V_16 . V_75 |= V_182 ;
V_22 = F_55 ( & V_29 -> V_31 ,
struct V_27 ,
V_40 ) ;
V_22 -> V_16 . V_75 |= V_183 ;
}
return & V_29 -> V_57 ;
error:
F_29 ( V_2 , V_29 ) ;
return NULL ;
}
static int F_102 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
T_1 V_3 ;
int V_84 ;
if ( V_2 -> V_60 )
F_80 ( V_2 ) ;
V_84 = V_2 -> V_195 ( V_2 ) ;
if ( V_84 ) {
F_51 ( V_2 -> V_51 , L_12 ,
V_2 , F_6 ( V_2 , V_78 ) ) ;
V_2 -> V_84 = true ;
}
F_34 ( V_2 ) ;
if ( V_2 -> V_60 ) {
V_3 = F_6 ( V_2 , V_64 ) ;
V_3 &= ~ V_187 ;
F_7 ( V_2 , V_64 , V_3 ) ;
V_2 -> V_60 = false ;
}
return 0 ;
}
int F_103 ( struct V_49 * V_50 ,
struct V_85 * V_196 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
T_1 V_197 ;
if ( V_196 -> V_198 )
return F_80 ( V_2 ) ;
V_197 = F_6 ( V_2 , V_64 ) ;
V_2 -> V_86 . V_164 = V_196 -> V_164 ;
V_2 -> V_86 . V_94 = V_196 -> V_94 ;
V_2 -> V_86 . V_199 = V_196 -> V_199 ;
V_2 -> V_86 . V_200 = V_196 -> V_200 ;
if ( V_196 -> V_199 && V_2 -> V_201 ) {
V_197 |= V_202 ;
V_197 |= V_196 -> V_200 << V_203 ;
}
V_2 -> V_86 . V_90 = V_196 -> V_90 ;
if ( V_196 -> V_94 )
V_2 -> V_86 . V_96 = V_196 -> V_96 ;
else
V_2 -> V_86 . V_96 = - 1 ;
V_2 -> V_86 . V_204 = V_196 -> V_204 ;
V_2 -> V_86 . V_205 = V_196 -> V_205 ;
if ( V_196 -> V_204 <= V_206 ) {
V_197 |= V_196 -> V_204 << V_207 ;
V_2 -> V_86 . V_204 = V_196 -> V_204 ;
}
if ( V_196 -> V_205 <= V_208 ) {
V_197 |= V_196 -> V_205 << V_209 ;
V_2 -> V_86 . V_205 = V_196 -> V_205 ;
}
V_197 &= ~ V_210 ;
V_197 |= V_196 -> V_211 << V_212 ;
F_7 ( V_2 , V_64 , V_197 ) ;
return 0 ;
}
static void F_104 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_64 ,
V_65 ) ;
if ( V_2 -> V_134 > 0 )
F_105 ( V_2 -> V_134 , V_2 ) ;
F_106 ( & V_2 -> V_143 ) ;
F_31 ( & V_2 -> V_160 . V_213 ) ;
}
static int F_107 ( struct V_214 * V_215 , struct V_216 * * V_217 ,
struct V_216 * * V_218 , struct V_216 * * V_219 ,
struct V_216 * * V_220 , struct V_216 * * V_221 )
{
int V_84 ;
* V_221 = NULL ;
* V_217 = F_108 ( & V_215 -> V_51 , L_13 ) ;
if ( F_109 ( * V_217 ) ) {
V_84 = F_110 ( * V_217 ) ;
F_51 ( & V_215 -> V_51 , L_14 , V_84 ) ;
return V_84 ;
}
* V_218 = F_108 ( & V_215 -> V_51 , L_15 ) ;
if ( F_109 ( * V_218 ) )
* V_218 = NULL ;
* V_219 = F_108 ( & V_215 -> V_51 , L_16 ) ;
if ( F_109 ( * V_219 ) )
* V_219 = NULL ;
* V_220 = F_108 ( & V_215 -> V_51 , L_17 ) ;
if ( F_109 ( * V_220 ) )
* V_220 = NULL ;
V_84 = F_111 ( * V_217 ) ;
if ( V_84 ) {
F_51 ( & V_215 -> V_51 , L_18 , V_84 ) ;
return V_84 ;
}
V_84 = F_111 ( * V_218 ) ;
if ( V_84 ) {
F_51 ( & V_215 -> V_51 , L_19 , V_84 ) ;
goto V_222;
}
V_84 = F_111 ( * V_219 ) ;
if ( V_84 ) {
F_51 ( & V_215 -> V_51 , L_20 , V_84 ) ;
goto V_223;
}
V_84 = F_111 ( * V_220 ) ;
if ( V_84 ) {
F_51 ( & V_215 -> V_51 , L_21 , V_84 ) ;
goto V_224;
}
return 0 ;
V_224:
F_112 ( * V_219 ) ;
V_223:
F_112 ( * V_218 ) ;
V_222:
F_112 ( * V_217 ) ;
return V_84 ;
}
static int F_113 ( struct V_214 * V_215 , struct V_216 * * V_217 ,
struct V_216 * * V_225 , struct V_216 * * V_221 ,
struct V_216 * * V_226 , struct V_216 * * V_227 )
{
int V_84 ;
* V_221 = NULL ;
* V_226 = NULL ;
* V_227 = NULL ;
* V_217 = F_108 ( & V_215 -> V_51 , L_13 ) ;
if ( F_109 ( * V_217 ) ) {
V_84 = F_110 ( * V_217 ) ;
F_51 ( & V_215 -> V_51 , L_22 , V_84 ) ;
return V_84 ;
}
* V_225 = F_108 ( & V_215 -> V_51 , L_23 ) ;
if ( F_109 ( * V_225 ) ) {
V_84 = F_110 ( * V_225 ) ;
F_51 ( & V_215 -> V_51 , L_24 , V_84 ) ;
return V_84 ;
}
V_84 = F_111 ( * V_217 ) ;
if ( V_84 ) {
F_51 ( & V_215 -> V_51 , L_18 , V_84 ) ;
return V_84 ;
}
V_84 = F_111 ( * V_225 ) ;
if ( V_84 ) {
F_51 ( & V_215 -> V_51 , L_25 , V_84 ) ;
goto V_222;
}
return 0 ;
V_222:
F_112 ( * V_217 ) ;
return V_84 ;
}
static int F_114 ( struct V_214 * V_215 , struct V_216 * * V_217 ,
struct V_216 * * V_218 , struct V_216 * * V_228 ,
struct V_216 * * V_219 , struct V_216 * * V_229 )
{
int V_84 ;
* V_217 = F_108 ( & V_215 -> V_51 , L_13 ) ;
if ( F_109 ( * V_217 ) ) {
V_84 = F_110 ( * V_217 ) ;
F_51 ( & V_215 -> V_51 , L_14 , V_84 ) ;
return V_84 ;
}
* V_218 = F_108 ( & V_215 -> V_51 , L_15 ) ;
if ( F_109 ( * V_218 ) )
* V_218 = NULL ;
* V_228 = F_108 ( & V_215 -> V_51 , L_26 ) ;
if ( F_109 ( * V_228 ) )
* V_228 = NULL ;
* V_219 = F_108 ( & V_215 -> V_51 , L_16 ) ;
if ( F_109 ( * V_219 ) )
* V_219 = NULL ;
* V_229 = F_108 ( & V_215 -> V_51 , L_27 ) ;
if ( F_109 ( * V_229 ) )
* V_229 = NULL ;
V_84 = F_111 ( * V_217 ) ;
if ( V_84 ) {
F_51 ( & V_215 -> V_51 , L_18 , V_84 ) ;
return V_84 ;
}
V_84 = F_111 ( * V_218 ) ;
if ( V_84 ) {
F_51 ( & V_215 -> V_51 , L_19 , V_84 ) ;
goto V_222;
}
V_84 = F_111 ( * V_228 ) ;
if ( V_84 ) {
F_51 ( & V_215 -> V_51 , L_28 , V_84 ) ;
goto V_223;
}
V_84 = F_111 ( * V_219 ) ;
if ( V_84 ) {
F_51 ( & V_215 -> V_51 , L_20 , V_84 ) ;
goto V_230;
}
V_84 = F_111 ( * V_229 ) ;
if ( V_84 ) {
F_51 ( & V_215 -> V_51 , L_29 , V_84 ) ;
goto V_224;
}
return 0 ;
V_224:
F_112 ( * V_219 ) ;
V_230:
F_112 ( * V_228 ) ;
V_223:
F_112 ( * V_218 ) ;
V_222:
F_112 ( * V_217 ) ;
return V_84 ;
}
static void F_115 ( struct V_231 * V_4 )
{
F_112 ( V_4 -> V_229 ) ;
F_112 ( V_4 -> V_219 ) ;
F_112 ( V_4 -> V_228 ) ;
F_112 ( V_4 -> V_218 ) ;
F_112 ( V_4 -> V_217 ) ;
}
static int F_116 ( struct V_231 * V_4 ,
struct V_213 * V_40 , int V_232 )
{
struct V_1 * V_2 ;
bool V_233 = false ;
T_1 V_6 , V_234 ;
int V_84 ;
V_2 = F_117 ( V_4 -> V_51 , sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 )
return - V_63 ;
V_2 -> V_51 = V_4 -> V_51 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_66 = V_4 -> V_66 ;
V_2 -> V_93 = 0x0 ;
V_2 -> V_14 = V_4 -> V_14 ;
F_118 ( & V_2 -> V_45 ) ;
F_28 ( & V_2 -> V_46 ) ;
F_28 ( & V_2 -> V_47 ) ;
F_28 ( & V_2 -> V_48 ) ;
V_233 = F_119 ( V_40 , L_30 ) ;
V_2 -> V_201 = F_119 ( V_40 , L_31 ) ;
V_84 = F_120 ( V_40 , L_32 , & V_6 ) ;
if ( V_84 ) {
F_51 ( V_4 -> V_51 , L_33 ) ;
return V_84 ;
}
V_234 = V_6 >> 3 ;
if ( V_234 > 8 )
V_233 = false ;
if ( ! V_233 )
V_4 -> V_160 . V_235 = F_121 ( V_234 - 1 ) ;
if ( F_122 ( V_40 , L_34 ) ||
F_122 ( V_40 , L_35 ) ||
F_122 ( V_40 , L_36 ) ) {
V_2 -> V_98 = V_99 ;
V_2 -> V_62 = V_232 ;
V_2 -> V_128 = V_232 ;
V_2 -> V_8 = V_236 ;
if ( V_4 -> V_37 -> V_38 == V_39 ) {
V_2 -> V_7 = V_237 ;
if ( V_4 -> V_140 == V_238 ||
V_4 -> V_140 == V_239 )
V_2 -> V_140 = true ;
}
} else if ( F_122 ( V_40 ,
L_37 ) ||
F_122 ( V_40 ,
L_38 ) ) {
V_2 -> V_98 = V_240 ;
V_2 -> V_62 = V_232 ;
V_2 -> V_128 = V_232 - V_4 -> V_241 ;
V_2 -> V_8 = V_242 ;
if ( V_4 -> V_37 -> V_38 == V_39 ) {
V_2 -> V_7 = V_243 ;
if ( V_4 -> V_140 == V_238 ||
V_4 -> V_140 == V_244 )
V_2 -> V_140 = true ;
}
} else {
F_51 ( V_4 -> V_51 , L_39 ) ;
return - V_245 ;
}
V_2 -> V_134 = F_123 ( V_40 , 0 ) ;
V_84 = F_124 ( V_2 -> V_134 , F_81 , V_246 ,
L_40 , V_2 ) ;
if ( V_84 ) {
F_51 ( V_4 -> V_51 , L_41 , V_2 -> V_134 ) ;
return V_84 ;
}
if ( V_4 -> V_37 -> V_38 == V_52 ) {
V_2 -> V_130 = F_72 ;
V_2 -> V_195 = F_60 ;
} else if ( V_4 -> V_37 -> V_38 == V_41 ) {
V_2 -> V_130 = F_71 ;
V_2 -> V_195 = F_62 ;
} else {
V_2 -> V_130 = F_64 ;
V_2 -> V_195 = F_60 ;
}
F_125 ( & V_2 -> V_143 , F_47 ,
( unsigned long ) V_2 ) ;
V_2 -> V_160 . V_247 = & V_4 -> V_160 ;
F_69 ( & V_2 -> V_160 . V_213 , & V_4 -> V_160 . V_248 ) ;
V_4 -> V_2 [ V_2 -> V_62 ] = V_2 ;
V_84 = F_80 ( V_2 ) ;
if ( V_84 < 0 ) {
F_51 ( V_4 -> V_51 , L_42 ) ;
return V_84 ;
}
return 0 ;
}
static int F_126 ( struct V_231 * V_4 ,
struct V_213 * V_40 ) {
int V_72 , V_105 , V_241 = 1 ;
V_72 = F_120 ( V_40 , L_43 , & V_241 ) ;
if ( ( V_72 < 0 ) && V_4 -> V_126 )
F_127 ( V_4 -> V_51 , L_44 ) ;
for ( V_105 = 0 ; V_105 < V_241 ; V_105 ++ )
F_116 ( V_4 , V_40 , V_4 -> V_232 ++ ) ;
V_4 -> V_241 += V_241 ;
return 0 ;
}
static struct V_49 * F_128 ( struct V_249 * V_250 ,
struct V_251 * V_252 )
{
struct V_231 * V_4 = V_252 -> V_253 ;
int V_232 = V_250 -> args [ 0 ] ;
if ( V_232 >= V_4 -> V_241 || ! V_4 -> V_2 [ V_232 ] )
return NULL ;
return F_129 ( & V_4 -> V_2 [ V_232 ] -> V_160 ) ;
}
static int F_130 ( struct V_214 * V_215 )
{
int (* F_131)( struct V_214 * , struct V_216 * * , struct V_216 * * ,
struct V_216 * * , struct V_216 * * , struct V_216 * * )
= F_114 ;
struct V_213 * V_40 = V_215 -> V_51 . V_254 ;
struct V_231 * V_4 ;
struct V_213 * V_255 , * V_256 = V_215 -> V_51 . V_254 ;
struct V_257 * V_258 ;
T_1 V_259 , V_260 ;
int V_105 , V_84 ;
V_4 = F_117 ( & V_215 -> V_51 , sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return - V_63 ;
V_4 -> V_51 = & V_215 -> V_51 ;
if ( V_256 ) {
const struct V_261 * V_262 ;
V_262 = F_132 ( V_263 , V_256 ) ;
if ( V_262 && V_262 -> V_61 ) {
V_4 -> V_37 = V_262 -> V_61 ;
F_131 = V_4 -> V_37 -> F_131 ;
}
}
V_84 = F_131 ( V_215 , & V_4 -> V_217 , & V_4 -> V_218 , & V_4 -> V_228 ,
& V_4 -> V_219 , & V_4 -> V_229 ) ;
if ( V_84 )
return V_84 ;
V_258 = F_133 ( V_215 , V_264 , 0 ) ;
V_4 -> V_5 = F_134 ( & V_215 -> V_51 , V_258 ) ;
if ( F_109 ( V_4 -> V_5 ) )
return F_110 ( V_4 -> V_5 ) ;
V_4 -> V_66 = F_119 ( V_40 , L_45 ) ;
if ( V_4 -> V_37 -> V_38 == V_52 )
V_4 -> V_126 = F_119 ( V_40 , L_46 ) ;
if ( V_4 -> V_37 -> V_38 == V_39 ) {
V_84 = F_120 ( V_40 , L_47 ,
& V_259 ) ;
if ( V_84 < 0 ) {
F_51 ( V_4 -> V_51 ,
L_48 ) ;
return V_84 ;
}
V_84 = F_120 ( V_40 , L_49 ,
& V_4 -> V_140 ) ;
if ( V_84 < 0 )
F_127 ( V_4 -> V_51 ,
L_50 ) ;
}
V_84 = F_120 ( V_40 , L_51 , & V_260 ) ;
if ( V_84 < 0 )
F_127 ( V_4 -> V_51 , L_52 ) ;
if ( V_260 > 32 )
V_4 -> V_14 = true ;
else
V_4 -> V_14 = false ;
F_135 ( V_4 -> V_51 , F_136 ( V_260 ) ) ;
V_4 -> V_160 . V_51 = & V_215 -> V_51 ;
F_28 ( & V_4 -> V_160 . V_248 ) ;
if ( ! ( V_4 -> V_37 -> V_38 == V_41 ) ) {
F_137 ( V_265 , V_4 -> V_160 . V_266 ) ;
F_137 ( V_267 , V_4 -> V_160 . V_266 ) ;
}
V_4 -> V_160 . V_268 =
F_48 ;
V_4 -> V_160 . V_269 =
F_37 ;
V_4 -> V_160 . V_270 = F_102 ;
V_4 -> V_160 . V_271 = F_53 ;
V_4 -> V_160 . V_272 = F_76 ;
if ( V_4 -> V_37 -> V_38 == V_52 ) {
F_137 ( V_273 , V_4 -> V_160 . V_266 ) ;
V_4 -> V_160 . V_274 = F_95 ;
V_4 -> V_160 . V_275 =
F_100 ;
V_4 -> V_160 . V_276 =
F_101 ;
V_4 -> V_160 . V_277 =
V_278 ;
} else if ( V_4 -> V_37 -> V_38 == V_41 ) {
F_137 ( V_279 , V_4 -> V_160 . V_266 ) ;
V_4 -> V_160 . V_280 = F_94 ;
} else {
V_4 -> V_160 . V_276 =
F_90 ;
}
F_138 ( V_215 , V_4 ) ;
F_139 (node, child) {
V_84 = F_126 ( V_4 , V_255 ) ;
if ( V_84 < 0 )
goto V_281;
}
if ( V_4 -> V_37 -> V_38 == V_39 ) {
for ( V_105 = 0 ; V_105 < V_4 -> V_241 ; V_105 ++ )
if ( V_4 -> V_2 [ V_105 ] )
V_4 -> V_2 [ V_105 ] -> V_97 = V_259 ;
}
F_140 ( & V_4 -> V_160 ) ;
V_84 = F_141 ( V_40 , F_128 ,
V_4 ) ;
if ( V_84 < 0 ) {
F_51 ( & V_215 -> V_51 , L_53 ) ;
F_142 ( & V_4 -> V_160 ) ;
goto error;
}
F_143 ( & V_215 -> V_51 , L_54 ) ;
return 0 ;
V_281:
F_115 ( V_4 ) ;
error:
for ( V_105 = 0 ; V_105 < V_4 -> V_241 ; V_105 ++ )
if ( V_4 -> V_2 [ V_105 ] )
F_104 ( V_4 -> V_2 [ V_105 ] ) ;
return V_84 ;
}
static int F_144 ( struct V_214 * V_215 )
{
struct V_231 * V_4 = F_145 ( V_215 ) ;
int V_105 ;
F_146 ( V_215 -> V_51 . V_254 ) ;
F_142 ( & V_4 -> V_160 ) ;
for ( V_105 = 0 ; V_105 < V_4 -> V_241 ; V_105 ++ )
if ( V_4 -> V_2 [ V_105 ] )
F_104 ( V_4 -> V_2 [ V_105 ] ) ;
F_115 ( V_4 ) ;
return 0 ;
}
