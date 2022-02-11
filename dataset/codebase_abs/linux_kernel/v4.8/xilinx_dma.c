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
T_5 V_55 ;
void * V_56 ;
if ( V_29 -> V_58 ) {
F_41 ( V_2 , V_29 , & V_44 ) ;
break;
}
F_31 ( & V_29 -> V_40 ) ;
V_55 = V_29 -> V_57 . V_55 ;
V_56 = V_29 -> V_57 . V_56 ;
if ( V_55 ) {
F_36 ( & V_2 -> V_45 , V_44 ) ;
V_55 ( V_56 ) ;
F_35 ( & V_2 -> V_45 , V_44 ) ;
}
F_43 ( & V_29 -> V_57 ) ;
F_29 ( V_2 , V_29 ) ;
}
F_36 ( & V_2 -> V_45 , V_44 ) ;
}
static void F_44 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
F_42 ( V_2 ) ;
}
static int F_45 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
if ( V_2 -> V_24 )
return 0 ;
if ( V_2 -> V_4 -> V_37 -> V_38 == V_52 ) {
V_2 -> V_24 = F_46 ( L_2 ,
V_2 -> V_51 ,
sizeof( struct V_27 ) ,
F_47 ( struct V_27 ) ,
0 ) ;
} else if ( V_2 -> V_4 -> V_37 -> V_38 == V_41 ) {
V_2 -> V_24 = F_46 ( L_3 ,
V_2 -> V_51 ,
sizeof( struct V_26 ) ,
F_47 ( struct V_26 ) ,
0 ) ;
} else {
V_2 -> V_24 = F_46 ( L_4 ,
V_2 -> V_51 ,
sizeof( struct V_21 ) ,
F_47 ( struct V_21 ) ,
0 ) ;
}
if ( ! V_2 -> V_24 ) {
F_48 ( V_2 -> V_51 ,
L_5 ,
V_2 -> V_60 ) ;
return - V_61 ;
}
if ( V_2 -> V_4 -> V_37 -> V_38 == V_52 ) {
V_2 -> V_54 = F_21 ( V_2 ) ;
V_2 -> V_53 = F_21 ( V_2 ) ;
}
F_49 ( V_50 ) ;
if ( V_2 -> V_4 -> V_37 -> V_38 == V_52 ) {
F_9 ( V_2 , V_62 ,
V_63 ) ;
}
if ( ( V_2 -> V_4 -> V_37 -> V_38 == V_41 ) && V_2 -> V_64 )
F_9 ( V_2 , V_62 ,
V_65 ) ;
return 0 ;
}
static enum V_66 F_50 ( struct V_49 * V_50 ,
T_6 V_67 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
struct V_28 * V_29 ;
struct V_27 * V_22 ;
struct V_15 * V_16 ;
enum V_66 V_70 ;
unsigned long V_44 ;
T_1 V_71 = 0 ;
V_70 = F_51 ( V_50 , V_67 , V_69 ) ;
if ( V_70 == V_72 || ! V_69 )
return V_70 ;
if ( V_2 -> V_4 -> V_37 -> V_38 == V_52 ) {
F_35 ( & V_2 -> V_45 , V_44 ) ;
V_29 = F_52 ( & V_2 -> V_48 ,
struct V_28 , V_40 ) ;
if ( V_2 -> V_64 ) {
F_53 (segment, &desc->segments, node) {
V_16 = & V_22 -> V_16 ;
V_71 += ( V_16 -> V_73 - V_16 -> V_74 ) &
V_75 ;
}
}
F_36 ( & V_2 -> V_45 , V_44 ) ;
V_2 -> V_71 = V_71 ;
F_54 ( V_69 , V_2 -> V_71 ) ;
}
return V_70 ;
}
static bool F_55 ( struct V_1 * V_2 )
{
return ! ( F_6 ( V_2 , V_76 ) &
V_77 ) &&
( F_6 ( V_2 , V_62 ) &
V_78 ) ;
}
static bool F_56 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_76 ) &
V_79 ;
}
static void F_57 ( struct V_1 * V_2 )
{
int V_80 ;
T_1 V_81 ;
F_8 ( V_2 , V_62 , V_78 ) ;
V_80 = F_58 ( V_2 , V_76 , V_81 ,
( V_81 & V_77 ) , 0 ,
V_82 ) ;
if ( V_80 ) {
F_48 ( V_2 -> V_51 , L_6 ,
V_2 , F_6 ( V_2 , V_76 ) ) ;
V_2 -> V_80 = true ;
}
}
static void F_59 ( struct V_1 * V_2 )
{
int V_80 ;
T_1 V_81 ;
F_9 ( V_2 , V_62 , V_78 ) ;
V_80 = F_58 ( V_2 , V_76 , V_81 ,
! ( V_81 & V_77 ) , 0 ,
V_82 ) ;
if ( V_80 ) {
F_48 ( V_2 -> V_51 , L_7 ,
V_2 , F_6 ( V_2 , V_76 ) ) ;
V_2 -> V_80 = true ;
}
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = & V_2 -> V_84 ;
struct V_28 * V_29 , * V_85 ;
T_1 V_3 ;
struct V_21 * V_86 ;
if ( V_2 -> V_80 )
return;
if ( F_61 ( & V_2 -> V_46 ) )
return;
V_29 = F_62 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
V_85 = F_52 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
V_86 = F_52 ( & V_85 -> V_31 ,
struct V_21 , V_40 ) ;
if ( V_2 -> V_64 && F_55 ( V_2 ) &&
! F_56 ( V_2 ) ) {
F_39 ( V_2 -> V_51 , L_8 ) ;
return;
}
if ( V_2 -> V_64 )
F_7 ( V_2 , V_87 ,
V_29 -> V_57 . V_23 ) ;
V_3 = F_6 ( V_2 , V_62 ) ;
if ( V_84 -> V_88 )
V_3 |= V_89 ;
else
V_3 &= ~ V_89 ;
F_7 ( V_2 , V_90 ,
V_2 -> V_91 ) ;
if ( V_2 -> V_64 || ! V_84 -> V_92 )
V_3 |= V_93 ;
if ( V_84 -> V_92 )
V_3 &= ~ V_93 ;
F_7 ( V_2 , V_62 , V_3 ) ;
if ( V_84 -> V_92 && ( V_84 -> V_94 >= 0 ) &&
( V_84 -> V_94 < V_2 -> V_95 ) ) {
if ( V_2 -> V_96 == V_97 )
F_3 ( V_2 , V_98 ,
V_84 -> V_94 <<
V_99 ) ;
else
F_3 ( V_2 , V_98 ,
V_84 -> V_94 <<
V_100 ) ;
}
F_59 ( V_2 ) ;
if ( V_2 -> V_80 )
return;
if ( V_2 -> V_64 ) {
F_7 ( V_2 , V_101 ,
V_86 -> V_23 ) ;
} else {
struct V_21 * V_22 , * V_102 = NULL ;
int V_103 = 0 ;
if ( V_2 -> V_104 < V_2 -> V_95 )
V_103 = V_2 -> V_104 ;
F_53 (segment, &desc->segments, node) {
if ( V_2 -> V_14 )
F_10 ( V_2 ,
F_63 ( V_103 ++ ) ,
V_22 -> V_16 . V_17 ,
V_22 -> V_16 . V_20 ) ;
else
F_5 ( V_2 ,
F_64 ( V_103 ++ ) ,
V_22 -> V_16 . V_17 ) ;
V_102 = V_22 ;
}
if ( ! V_102 )
return;
F_5 ( V_2 , V_105 , V_102 -> V_16 . V_106 ) ;
F_5 ( V_2 , V_107 ,
V_102 -> V_16 . V_108 ) ;
F_5 ( V_2 , V_109 , V_102 -> V_16 . V_110 ) ;
}
if ( ! V_2 -> V_64 ) {
F_31 ( & V_29 -> V_40 ) ;
F_65 ( & V_29 -> V_40 , & V_2 -> V_48 ) ;
V_2 -> V_104 ++ ;
V_2 -> V_91 -- ;
if ( V_2 -> V_104 == V_2 -> V_95 )
V_2 -> V_104 = 0 ;
} else {
F_66 ( & V_2 -> V_46 , & V_2 -> V_48 ) ;
V_2 -> V_91 = 0 ;
}
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_28 * V_111 , * V_85 ;
struct V_26 * V_86 ;
T_1 V_112 = F_1 ( V_2 , V_62 ) ;
if ( V_2 -> V_80 )
return;
if ( F_61 ( & V_2 -> V_46 ) )
return;
V_111 = F_62 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
V_85 = F_52 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
V_86 = F_52 ( & V_85 -> V_31 ,
struct V_26 , V_40 ) ;
if ( V_2 -> V_91 <= V_113 ) {
V_112 &= ~ V_114 ;
V_112 |= V_2 -> V_91 <<
V_115 ;
F_7 ( V_2 , V_62 , V_112 ) ;
}
if ( V_2 -> V_64 ) {
F_14 ( V_2 , V_87 ,
V_111 -> V_57 . V_23 ) ;
F_14 ( V_2 , V_101 ,
V_86 -> V_23 ) ;
} else {
struct V_26 * V_22 ;
struct V_116 * V_16 ;
V_22 = F_62 ( & V_111 -> V_31 ,
struct V_26 ,
V_40 ) ;
V_16 = & V_22 -> V_16 ;
F_14 ( V_2 , V_117 , V_16 -> V_118 ) ;
F_14 ( V_2 , V_119 , V_16 -> V_120 ) ;
F_7 ( V_2 , V_121 ,
V_16 -> V_73 & V_75 ) ;
}
F_66 ( & V_2 -> V_46 , & V_2 -> V_48 ) ;
V_2 -> V_91 = 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_28 * V_111 , * V_85 ;
struct V_27 * V_86 , * V_122 , * V_123 ;
T_1 V_3 ;
if ( V_2 -> V_80 )
return;
if ( F_61 ( & V_2 -> V_46 ) )
return;
if ( V_2 -> V_64 && F_55 ( V_2 ) &&
! F_56 ( V_2 ) ) {
F_39 ( V_2 -> V_51 , L_8 ) ;
return;
}
V_111 = F_62 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
V_85 = F_52 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
V_86 = F_52 ( & V_85 -> V_31 ,
struct V_27 , V_40 ) ;
if ( V_2 -> V_64 && ! V_2 -> V_4 -> V_124 ) {
V_122 = F_62 ( & V_111 -> V_31 ,
struct V_27 , V_40 ) ;
V_123 = V_2 -> V_54 ;
V_123 -> V_16 = V_122 -> V_16 ;
F_69 ( & V_122 -> V_40 , & V_123 -> V_40 ) ;
V_2 -> V_54 = V_122 ;
V_86 -> V_16 . V_125 = V_2 -> V_54 -> V_23 ;
V_111 -> V_57 . V_23 = V_123 -> V_23 ;
}
V_3 = F_6 ( V_2 , V_62 ) ;
if ( V_2 -> V_91 <= V_113 ) {
V_3 &= ~ V_114 ;
V_3 |= V_2 -> V_91 <<
V_115 ;
F_7 ( V_2 , V_62 , V_3 ) ;
}
if ( V_2 -> V_64 && ! V_2 -> V_4 -> V_124 )
F_14 ( V_2 , V_87 ,
V_111 -> V_57 . V_23 ) ;
if ( V_2 -> V_64 && V_2 -> V_4 -> V_124 ) {
if ( V_2 -> V_96 == V_97 ) {
F_7 ( V_2 , V_87 ,
V_111 -> V_57 . V_23 ) ;
} else {
if ( ! V_2 -> V_126 ) {
F_7 ( V_2 , V_87 ,
V_111 -> V_57 . V_23 ) ;
} else {
F_7 ( V_2 ,
F_70 ( V_2 -> V_126 ) ,
V_111 -> V_57 . V_23 ) ;
}
}
}
F_59 ( V_2 ) ;
if ( V_2 -> V_80 )
return;
if ( V_2 -> V_64 && ! V_2 -> V_4 -> V_124 ) {
if ( V_2 -> V_58 )
F_14 ( V_2 , V_101 ,
V_2 -> V_53 -> V_23 ) ;
else
F_14 ( V_2 , V_101 ,
V_86 -> V_23 ) ;
} else if ( V_2 -> V_64 && V_2 -> V_4 -> V_124 ) {
if ( V_2 -> V_96 == V_97 ) {
F_7 ( V_2 , V_101 ,
V_86 -> V_23 ) ;
} else {
if ( ! V_2 -> V_126 ) {
F_7 ( V_2 , V_101 ,
V_86 -> V_23 ) ;
} else {
F_7 ( V_2 ,
F_71 ( V_2 -> V_126 ) ,
V_86 -> V_23 ) ;
}
}
} else {
struct V_27 * V_22 ;
struct V_15 * V_16 ;
V_22 = F_62 ( & V_111 -> V_31 ,
struct V_27 ,
V_40 ) ;
V_16 = & V_22 -> V_16 ;
F_14 ( V_2 , V_127 , V_16 -> V_17 ) ;
F_7 ( V_2 , V_121 ,
V_16 -> V_73 & V_75 ) ;
}
F_66 ( & V_2 -> V_46 , & V_2 -> V_48 ) ;
V_2 -> V_91 = 0 ;
}
static void F_72 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
unsigned long V_44 ;
F_35 ( & V_2 -> V_45 , V_44 ) ;
V_2 -> V_128 ( V_2 ) ;
F_36 ( & V_2 -> V_45 , V_44 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_28 * V_29 , * V_32 ;
if ( F_61 ( & V_2 -> V_48 ) )
return;
F_30 (desc, next, &chan->active_list, node) {
F_31 ( & V_29 -> V_40 ) ;
if ( ! V_29 -> V_58 )
F_74 ( & V_29 -> V_57 ) ;
F_65 ( & V_29 -> V_40 , & V_2 -> V_47 ) ;
}
}
static int F_75 ( struct V_1 * V_2 )
{
int V_80 ;
T_1 V_129 ;
F_9 ( V_2 , V_62 , V_130 ) ;
V_80 = F_58 ( V_2 , V_62 , V_129 ,
! ( V_129 & V_130 ) , 0 ,
V_82 ) ;
if ( V_80 ) {
F_48 ( V_2 -> V_51 , L_9 ,
F_6 ( V_2 , V_62 ) ,
F_6 ( V_2 , V_76 ) ) ;
return - V_131 ;
}
V_2 -> V_80 = false ;
return V_80 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_80 ;
V_80 = F_75 ( V_2 ) ;
if ( V_80 )
return V_80 ;
F_9 ( V_2 , V_62 ,
V_63 ) ;
return 0 ;
}
static T_7 F_77 ( int V_132 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
T_1 V_74 ;
V_74 = F_6 ( V_2 , V_76 ) ;
if ( ! ( V_74 & V_63 ) )
return V_133 ;
F_7 ( V_2 , V_76 ,
V_74 & V_63 ) ;
if ( V_74 & V_134 ) {
T_1 V_135 = V_74 & V_136 ;
F_7 ( V_2 , V_76 ,
V_135 & V_137 ) ;
if ( ! V_2 -> V_138 ||
( V_135 & ~ V_137 ) ) {
F_48 ( V_2 -> V_51 ,
L_10 ,
V_2 , V_135 ,
F_6 ( V_2 , V_87 ) ,
F_6 ( V_2 , V_101 ) ) ;
V_2 -> V_80 = true ;
}
}
if ( V_74 & V_139 ) {
F_39 ( V_2 -> V_51 , L_11 ) ;
}
if ( V_74 & V_140 ) {
F_78 ( & V_2 -> V_45 ) ;
F_73 ( V_2 ) ;
V_2 -> V_128 ( V_2 ) ;
F_79 ( & V_2 -> V_45 ) ;
}
F_80 ( & V_2 -> V_141 ) ;
return V_142 ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_21 * V_86 ;
struct V_28 * V_85 ;
struct V_27 * V_143 ;
struct V_26 * V_144 ;
if ( F_61 ( & V_2 -> V_46 ) )
goto V_145;
V_85 = F_52 ( & V_2 -> V_46 ,
struct V_28 , V_40 ) ;
if ( V_2 -> V_4 -> V_37 -> V_38 == V_39 ) {
V_86 = F_52 ( & V_85 -> V_31 ,
struct V_21 ,
V_40 ) ;
V_86 -> V_16 . V_125 = ( T_1 ) V_29 -> V_57 . V_23 ;
} else if ( V_2 -> V_4 -> V_37 -> V_38 == V_41 ) {
V_144 = F_52 ( & V_85 -> V_31 ,
struct V_26 ,
V_40 ) ;
V_144 -> V_16 . V_125 = ( T_1 ) V_29 -> V_57 . V_23 ;
} else {
V_143 = F_52 ( & V_85 -> V_31 ,
struct V_27 ,
V_40 ) ;
V_143 -> V_16 . V_125 = ( T_1 ) V_29 -> V_57 . V_23 ;
}
V_145:
F_65 ( & V_29 -> V_40 , & V_2 -> V_46 ) ;
V_2 -> V_91 ++ ;
if ( V_2 -> V_64 && ( V_2 -> V_4 -> V_37 -> V_38 == V_39 )
&& F_82 ( V_2 -> V_91 > V_2 -> V_95 ) ) {
F_39 ( V_2 -> V_51 , L_12 ) ;
V_2 -> V_91 = V_2 -> V_95 ;
}
}
static T_6 F_83 ( struct V_146 * V_147 )
{
struct V_28 * V_29 = F_84 ( V_147 ) ;
struct V_1 * V_2 = F_38 ( V_147 -> V_2 ) ;
T_6 V_67 ;
unsigned long V_44 ;
int V_80 ;
if ( V_2 -> V_58 ) {
F_29 ( V_2 , V_29 ) ;
return - V_148 ;
}
if ( V_2 -> V_80 ) {
V_80 = F_76 ( V_2 ) ;
if ( V_80 < 0 )
return V_80 ;
}
F_35 ( & V_2 -> V_45 , V_44 ) ;
V_67 = F_85 ( V_147 ) ;
F_81 ( V_2 , V_29 ) ;
if ( V_29 -> V_58 )
V_2 -> V_58 = true ;
F_36 ( & V_2 -> V_45 , V_44 ) ;
return V_67 ;
}
static struct V_146 *
F_86 ( struct V_49 * V_50 ,
struct V_149 * V_150 ,
unsigned long V_44 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
struct V_28 * V_29 ;
struct V_21 * V_22 , * V_151 = NULL ;
struct V_152 * V_16 ;
if ( ! F_87 ( V_150 -> V_153 ) )
return NULL ;
if ( ! V_150 -> V_154 || ! V_150 -> V_155 [ 0 ] . V_156 )
return NULL ;
if ( V_150 -> V_157 != 1 )
return NULL ;
V_29 = F_26 ( V_2 ) ;
if ( ! V_29 )
return NULL ;
F_88 ( & V_29 -> V_57 , & V_2 -> V_158 ) ;
V_29 -> V_57 . V_159 = F_83 ;
F_89 ( & V_29 -> V_57 ) ;
V_22 = F_18 ( V_2 ) ;
if ( ! V_22 )
goto error;
V_16 = & V_22 -> V_16 ;
V_16 -> V_110 = V_150 -> V_154 ;
V_16 -> V_106 = V_150 -> V_155 [ 0 ] . V_156 ;
V_16 -> V_108 = ( V_150 -> V_155 [ 0 ] . V_160 + V_150 -> V_155 [ 0 ] . V_156 ) <<
V_161 ;
V_16 -> V_108 |= V_2 -> V_84 . V_162 <<
V_163 ;
if ( V_150 -> V_153 != V_97 ) {
if ( V_2 -> V_14 ) {
V_16 -> V_17 = F_16 ( V_150 -> V_164 ) ;
V_16 -> V_20 = F_17 ( V_150 -> V_164 ) ;
} else {
V_16 -> V_17 = V_150 -> V_164 ;
}
} else {
if ( V_2 -> V_14 ) {
V_16 -> V_17 = F_16 ( V_150 -> V_165 ) ;
V_16 -> V_20 = F_17 ( V_150 -> V_165 ) ;
} else {
V_16 -> V_17 = V_150 -> V_165 ;
}
}
F_65 ( & V_22 -> V_40 , & V_29 -> V_31 ) ;
V_151 = V_22 ;
V_22 = F_62 ( & V_29 -> V_31 ,
struct V_21 , V_40 ) ;
V_29 -> V_57 . V_23 = V_22 -> V_23 ;
return & V_29 -> V_57 ;
error:
F_29 ( V_2 , V_29 ) ;
return NULL ;
}
static struct V_146 *
F_90 ( struct V_49 * V_50 , T_3 V_166 ,
T_3 V_167 , T_4 V_168 , unsigned long V_44 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
struct V_28 * V_29 ;
struct V_26 * V_22 , * V_151 ;
struct V_116 * V_16 ;
if ( ! V_168 || V_168 > V_75 )
return NULL ;
V_29 = F_26 ( V_2 ) ;
if ( ! V_29 )
return NULL ;
F_88 ( & V_29 -> V_57 , & V_2 -> V_158 ) ;
V_29 -> V_57 . V_159 = F_83 ;
V_22 = F_20 ( V_2 ) ;
if ( ! V_22 )
goto error;
V_16 = & V_22 -> V_16 ;
V_16 -> V_73 = V_168 ;
V_16 -> V_118 = V_167 ;
V_16 -> V_120 = V_166 ;
if ( V_2 -> V_14 ) {
V_16 -> V_169 = F_17 ( V_167 ) ;
V_16 -> V_170 = F_17 ( V_166 ) ;
}
V_151 = F_52 ( & V_29 -> V_31 ,
struct V_26 , V_40 ) ;
V_151 -> V_16 . V_125 = V_22 -> V_23 ;
F_65 ( & V_22 -> V_40 , & V_29 -> V_31 ) ;
V_151 = V_22 ;
V_22 = F_62 ( & V_29 -> V_31 ,
struct V_26 , V_40 ) ;
V_29 -> V_57 . V_23 = V_22 -> V_23 ;
V_151 -> V_16 . V_125 = V_22 -> V_23 ;
return & V_29 -> V_57 ;
error:
F_29 ( V_2 , V_29 ) ;
return NULL ;
}
static struct V_146 * F_91 (
struct V_49 * V_50 , struct V_171 * V_155 , unsigned int V_172 ,
enum V_173 V_96 , unsigned long V_44 ,
void * V_174 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
struct V_28 * V_29 ;
struct V_27 * V_22 = NULL , * V_151 = NULL ;
T_1 * V_175 = ( T_1 * ) V_174 ;
struct V_171 * V_176 ;
T_4 V_177 ;
T_4 V_18 ;
unsigned int V_103 ;
if ( ! F_87 ( V_96 ) )
return NULL ;
V_29 = F_26 ( V_2 ) ;
if ( ! V_29 )
return NULL ;
F_88 ( & V_29 -> V_57 , & V_2 -> V_158 ) ;
V_29 -> V_57 . V_159 = F_83 ;
F_92 (sgl, sg, sg_len, i) {
V_18 = 0 ;
while ( V_18 < F_93 ( V_176 ) ) {
struct V_15 * V_16 ;
V_22 = F_21 ( V_2 ) ;
if ( ! V_22 )
goto error;
V_177 = F_94 ( T_4 , F_93 ( V_176 ) - V_18 ,
V_75 ) ;
V_16 = & V_22 -> V_16 ;
F_15 ( V_2 , V_16 , F_95 ( V_176 ) ,
V_18 , 0 ) ;
V_16 -> V_73 = V_177 ;
if ( V_2 -> V_96 == V_97 ) {
if ( V_175 )
memcpy ( V_16 -> V_178 , V_175 , sizeof( T_1 ) *
V_179 ) ;
}
if ( V_151 )
V_151 -> V_16 . V_125 = V_22 -> V_23 ;
V_151 = V_22 ;
V_18 += V_177 ;
F_65 ( & V_22 -> V_40 , & V_29 -> V_31 ) ;
}
}
V_22 = F_62 ( & V_29 -> V_31 ,
struct V_27 , V_40 ) ;
V_29 -> V_57 . V_23 = V_22 -> V_23 ;
V_151 -> V_16 . V_125 = V_22 -> V_23 ;
if ( V_2 -> V_96 == V_97 ) {
V_22 -> V_16 . V_73 |= V_180 ;
V_22 = F_52 ( & V_29 -> V_31 ,
struct V_27 ,
V_40 ) ;
V_22 -> V_16 . V_73 |= V_181 ;
}
return & V_29 -> V_57 ;
error:
F_29 ( V_2 , V_29 ) ;
return NULL ;
}
static struct V_146 * F_96 (
struct V_49 * V_50 , T_3 V_17 , T_4 V_182 ,
T_4 V_19 , enum V_173 V_96 ,
unsigned long V_44 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
struct V_28 * V_29 ;
struct V_27 * V_22 , * V_183 , * V_151 = NULL ;
T_4 V_177 , V_18 ;
unsigned int V_184 ;
int V_103 ;
T_1 V_3 ;
if ( ! V_19 )
return NULL ;
V_184 = V_182 / V_19 ;
if ( ! V_184 )
return NULL ;
if ( ! F_87 ( V_96 ) )
return NULL ;
V_29 = F_26 ( V_2 ) ;
if ( ! V_29 )
return NULL ;
V_2 -> V_96 = V_96 ;
F_88 ( & V_29 -> V_57 , & V_2 -> V_158 ) ;
V_29 -> V_57 . V_159 = F_83 ;
for ( V_103 = 0 ; V_103 < V_184 ; ++ V_103 ) {
V_18 = 0 ;
while ( V_18 < V_19 ) {
struct V_15 * V_16 ;
V_22 = F_21 ( V_2 ) ;
if ( ! V_22 )
goto error;
V_177 = F_94 ( T_4 , V_19 - V_18 ,
V_75 ) ;
V_16 = & V_22 -> V_16 ;
F_15 ( V_2 , V_16 , V_17 , V_18 ,
V_19 * V_103 ) ;
V_16 -> V_73 = V_177 ;
if ( V_151 )
V_151 -> V_16 . V_125 = V_22 -> V_23 ;
V_151 = V_22 ;
V_18 += V_177 ;
F_65 ( & V_22 -> V_40 , & V_29 -> V_31 ) ;
}
}
V_183 = F_62 ( & V_29 -> V_31 ,
struct V_27 , V_40 ) ;
V_29 -> V_57 . V_23 = V_183 -> V_23 ;
V_29 -> V_58 = true ;
V_3 = F_6 ( V_2 , V_62 ) ;
V_3 |= V_185 ;
F_7 ( V_2 , V_62 , V_3 ) ;
V_22 = F_52 ( & V_29 -> V_31 ,
struct V_27 ,
V_40 ) ;
V_22 -> V_16 . V_125 = ( T_1 ) V_183 -> V_23 ;
if ( V_96 == V_97 ) {
V_183 -> V_16 . V_73 |= V_180 ;
V_22 -> V_16 . V_73 |= V_181 ;
}
return & V_29 -> V_57 ;
error:
F_29 ( V_2 , V_29 ) ;
return NULL ;
}
static struct V_146 *
F_97 ( struct V_49 * V_50 ,
struct V_149 * V_150 ,
unsigned long V_44 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
struct V_28 * V_29 ;
struct V_27 * V_22 ;
struct V_15 * V_16 ;
if ( ! F_87 ( V_150 -> V_153 ) )
return NULL ;
if ( ! V_150 -> V_154 || ! V_150 -> V_155 [ 0 ] . V_156 )
return NULL ;
if ( V_150 -> V_157 != 1 )
return NULL ;
V_29 = F_26 ( V_2 ) ;
if ( ! V_29 )
return NULL ;
V_2 -> V_96 = V_150 -> V_153 ;
F_88 ( & V_29 -> V_57 , & V_2 -> V_158 ) ;
V_29 -> V_57 . V_159 = F_83 ;
V_22 = F_21 ( V_2 ) ;
if ( ! V_22 )
goto error;
V_16 = & V_22 -> V_16 ;
if ( V_150 -> V_153 != V_97 )
V_16 -> V_17 = V_150 -> V_164 ;
else
V_16 -> V_17 = V_150 -> V_165 ;
V_16 -> V_186 = V_2 -> V_126 & V_187 ;
V_16 -> V_188 = ( V_150 -> V_154 << V_189 ) &
V_190 ;
V_16 -> V_188 |= ( V_150 -> V_155 [ 0 ] . V_160 + V_150 -> V_155 [ 0 ] . V_156 ) &
V_191 ;
V_16 -> V_73 = V_150 -> V_155 [ 0 ] . V_156 & V_192 ;
F_65 ( & V_22 -> V_40 , & V_29 -> V_31 ) ;
V_22 = F_62 ( & V_29 -> V_31 ,
struct V_27 , V_40 ) ;
V_29 -> V_57 . V_23 = V_22 -> V_23 ;
if ( V_150 -> V_153 == V_97 ) {
V_22 -> V_16 . V_73 |= V_180 ;
V_22 = F_52 ( & V_29 -> V_31 ,
struct V_27 ,
V_40 ) ;
V_22 -> V_16 . V_73 |= V_181 ;
}
return & V_29 -> V_57 ;
error:
F_29 ( V_2 , V_29 ) ;
return NULL ;
}
static int F_98 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
T_1 V_3 ;
if ( V_2 -> V_58 )
F_76 ( V_2 ) ;
F_57 ( V_2 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_58 ) {
V_3 = F_6 ( V_2 , V_62 ) ;
V_3 &= ~ V_185 ;
F_7 ( V_2 , V_62 , V_3 ) ;
V_2 -> V_58 = false ;
}
return 0 ;
}
int F_99 ( struct V_49 * V_50 ,
struct V_83 * V_193 )
{
struct V_1 * V_2 = F_38 ( V_50 ) ;
T_1 V_194 ;
if ( V_193 -> V_195 )
return F_76 ( V_2 ) ;
V_194 = F_6 ( V_2 , V_62 ) ;
V_2 -> V_84 . V_162 = V_193 -> V_162 ;
V_2 -> V_84 . V_92 = V_193 -> V_92 ;
V_2 -> V_84 . V_196 = V_193 -> V_196 ;
V_2 -> V_84 . V_197 = V_193 -> V_197 ;
if ( V_193 -> V_196 && V_2 -> V_198 ) {
V_194 |= V_199 ;
V_194 |= V_193 -> V_197 << V_200 ;
}
V_2 -> V_84 . V_88 = V_193 -> V_88 ;
if ( V_193 -> V_92 )
V_2 -> V_84 . V_94 = V_193 -> V_94 ;
else
V_2 -> V_84 . V_94 = - 1 ;
V_2 -> V_84 . V_201 = V_193 -> V_201 ;
V_2 -> V_84 . V_202 = V_193 -> V_202 ;
if ( V_193 -> V_201 <= V_203 ) {
V_194 |= V_193 -> V_201 << V_204 ;
V_2 -> V_84 . V_201 = V_193 -> V_201 ;
}
if ( V_193 -> V_202 <= V_205 ) {
V_194 |= V_193 -> V_202 << V_206 ;
V_2 -> V_84 . V_202 = V_193 -> V_202 ;
}
V_194 &= ~ V_207 ;
V_194 |= V_193 -> V_208 << V_209 ;
F_7 ( V_2 , V_62 , V_194 ) ;
return 0 ;
}
static void F_100 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_62 ,
V_63 ) ;
if ( V_2 -> V_132 > 0 )
F_101 ( V_2 -> V_132 , V_2 ) ;
F_102 ( & V_2 -> V_141 ) ;
F_31 ( & V_2 -> V_158 . V_210 ) ;
}
static int F_103 ( struct V_211 * V_212 , struct V_213 * * V_214 ,
struct V_213 * * V_215 , struct V_213 * * V_216 ,
struct V_213 * * V_217 , struct V_213 * * V_218 )
{
int V_80 ;
* V_218 = NULL ;
* V_214 = F_104 ( & V_212 -> V_51 , L_13 ) ;
if ( F_105 ( * V_214 ) ) {
V_80 = F_106 ( * V_214 ) ;
F_48 ( & V_212 -> V_51 , L_14 , V_80 ) ;
return V_80 ;
}
* V_215 = F_104 ( & V_212 -> V_51 , L_15 ) ;
if ( F_105 ( * V_215 ) )
* V_215 = NULL ;
* V_216 = F_104 ( & V_212 -> V_51 , L_16 ) ;
if ( F_105 ( * V_216 ) )
* V_216 = NULL ;
* V_217 = F_104 ( & V_212 -> V_51 , L_17 ) ;
if ( F_105 ( * V_217 ) )
* V_217 = NULL ;
V_80 = F_107 ( * V_214 ) ;
if ( V_80 ) {
F_48 ( & V_212 -> V_51 , L_18 , V_80 ) ;
return V_80 ;
}
V_80 = F_107 ( * V_215 ) ;
if ( V_80 ) {
F_48 ( & V_212 -> V_51 , L_19 , V_80 ) ;
goto V_219;
}
V_80 = F_107 ( * V_216 ) ;
if ( V_80 ) {
F_48 ( & V_212 -> V_51 , L_20 , V_80 ) ;
goto V_220;
}
V_80 = F_107 ( * V_217 ) ;
if ( V_80 ) {
F_48 ( & V_212 -> V_51 , L_21 , V_80 ) ;
goto V_221;
}
return 0 ;
V_221:
F_108 ( * V_216 ) ;
V_220:
F_108 ( * V_215 ) ;
V_219:
F_108 ( * V_214 ) ;
return V_80 ;
}
static int F_109 ( struct V_211 * V_212 , struct V_213 * * V_214 ,
struct V_213 * * V_222 , struct V_213 * * V_218 ,
struct V_213 * * V_223 , struct V_213 * * V_224 )
{
int V_80 ;
* V_218 = NULL ;
* V_223 = NULL ;
* V_224 = NULL ;
* V_214 = F_104 ( & V_212 -> V_51 , L_13 ) ;
if ( F_105 ( * V_214 ) ) {
V_80 = F_106 ( * V_214 ) ;
F_48 ( & V_212 -> V_51 , L_22 , V_80 ) ;
return V_80 ;
}
* V_222 = F_104 ( & V_212 -> V_51 , L_23 ) ;
if ( F_105 ( * V_222 ) ) {
V_80 = F_106 ( * V_222 ) ;
F_48 ( & V_212 -> V_51 , L_24 , V_80 ) ;
return V_80 ;
}
V_80 = F_107 ( * V_214 ) ;
if ( V_80 ) {
F_48 ( & V_212 -> V_51 , L_18 , V_80 ) ;
return V_80 ;
}
V_80 = F_107 ( * V_222 ) ;
if ( V_80 ) {
F_48 ( & V_212 -> V_51 , L_25 , V_80 ) ;
goto V_219;
}
return 0 ;
V_219:
F_108 ( * V_214 ) ;
return V_80 ;
}
static int F_110 ( struct V_211 * V_212 , struct V_213 * * V_214 ,
struct V_213 * * V_215 , struct V_213 * * V_225 ,
struct V_213 * * V_216 , struct V_213 * * V_226 )
{
int V_80 ;
* V_214 = F_104 ( & V_212 -> V_51 , L_13 ) ;
if ( F_105 ( * V_214 ) ) {
V_80 = F_106 ( * V_214 ) ;
F_48 ( & V_212 -> V_51 , L_14 , V_80 ) ;
return V_80 ;
}
* V_215 = F_104 ( & V_212 -> V_51 , L_15 ) ;
if ( F_105 ( * V_215 ) )
* V_215 = NULL ;
* V_225 = F_104 ( & V_212 -> V_51 , L_26 ) ;
if ( F_105 ( * V_225 ) )
* V_225 = NULL ;
* V_216 = F_104 ( & V_212 -> V_51 , L_16 ) ;
if ( F_105 ( * V_216 ) )
* V_216 = NULL ;
* V_226 = F_104 ( & V_212 -> V_51 , L_27 ) ;
if ( F_105 ( * V_226 ) )
* V_226 = NULL ;
V_80 = F_107 ( * V_214 ) ;
if ( V_80 ) {
F_48 ( & V_212 -> V_51 , L_18 , V_80 ) ;
return V_80 ;
}
V_80 = F_107 ( * V_215 ) ;
if ( V_80 ) {
F_48 ( & V_212 -> V_51 , L_19 , V_80 ) ;
goto V_219;
}
V_80 = F_107 ( * V_225 ) ;
if ( V_80 ) {
F_48 ( & V_212 -> V_51 , L_28 , V_80 ) ;
goto V_220;
}
V_80 = F_107 ( * V_216 ) ;
if ( V_80 ) {
F_48 ( & V_212 -> V_51 , L_20 , V_80 ) ;
goto V_227;
}
V_80 = F_107 ( * V_226 ) ;
if ( V_80 ) {
F_48 ( & V_212 -> V_51 , L_29 , V_80 ) ;
goto V_221;
}
return 0 ;
V_221:
F_108 ( * V_216 ) ;
V_227:
F_108 ( * V_225 ) ;
V_220:
F_108 ( * V_215 ) ;
V_219:
F_108 ( * V_214 ) ;
return V_80 ;
}
static void F_111 ( struct V_228 * V_4 )
{
F_108 ( V_4 -> V_226 ) ;
F_108 ( V_4 -> V_216 ) ;
F_108 ( V_4 -> V_225 ) ;
F_108 ( V_4 -> V_215 ) ;
F_108 ( V_4 -> V_214 ) ;
}
static int F_112 ( struct V_228 * V_4 ,
struct V_210 * V_40 , int V_229 )
{
struct V_1 * V_2 ;
bool V_230 = false ;
T_1 V_6 , V_231 ;
int V_80 ;
V_2 = F_113 ( V_4 -> V_51 , sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 )
return - V_61 ;
V_2 -> V_51 = V_4 -> V_51 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_64 = V_4 -> V_64 ;
V_2 -> V_91 = 0x0 ;
V_2 -> V_14 = V_4 -> V_14 ;
F_114 ( & V_2 -> V_45 ) ;
F_28 ( & V_2 -> V_46 ) ;
F_28 ( & V_2 -> V_47 ) ;
F_28 ( & V_2 -> V_48 ) ;
V_230 = F_115 ( V_40 , L_30 ) ;
V_2 -> V_198 = F_115 ( V_40 , L_31 ) ;
V_80 = F_116 ( V_40 , L_32 , & V_6 ) ;
if ( V_80 ) {
F_48 ( V_4 -> V_51 , L_33 ) ;
return V_80 ;
}
V_231 = V_6 >> 3 ;
if ( V_231 > 8 )
V_230 = false ;
if ( ! V_230 )
V_4 -> V_158 . V_232 = F_117 ( V_231 - 1 ) ;
if ( F_118 ( V_40 , L_34 ) ||
F_118 ( V_40 , L_35 ) ||
F_118 ( V_40 , L_36 ) ) {
V_2 -> V_96 = V_97 ;
V_2 -> V_60 = V_229 ;
V_2 -> V_126 = V_229 ;
V_2 -> V_8 = V_233 ;
if ( V_4 -> V_37 -> V_38 == V_39 ) {
V_2 -> V_7 = V_234 ;
if ( V_4 -> V_138 == V_235 ||
V_4 -> V_138 == V_236 )
V_2 -> V_138 = true ;
}
} else if ( F_118 ( V_40 ,
L_37 ) ||
F_118 ( V_40 ,
L_38 ) ) {
V_2 -> V_96 = V_237 ;
V_2 -> V_60 = V_229 ;
V_2 -> V_126 = V_229 - V_4 -> V_238 ;
V_2 -> V_8 = V_239 ;
if ( V_4 -> V_37 -> V_38 == V_39 ) {
V_2 -> V_7 = V_240 ;
if ( V_4 -> V_138 == V_235 ||
V_4 -> V_138 == V_241 )
V_2 -> V_138 = true ;
}
} else {
F_48 ( V_4 -> V_51 , L_39 ) ;
return - V_242 ;
}
V_2 -> V_132 = F_119 ( V_40 , 0 ) ;
V_80 = F_120 ( V_2 -> V_132 , F_77 , V_243 ,
L_40 , V_2 ) ;
if ( V_80 ) {
F_48 ( V_4 -> V_51 , L_41 , V_2 -> V_132 ) ;
return V_80 ;
}
if ( V_4 -> V_37 -> V_38 == V_52 )
V_2 -> V_128 = F_68 ;
else if ( V_4 -> V_37 -> V_38 == V_41 )
V_2 -> V_128 = F_67 ;
else
V_2 -> V_128 = F_60 ;
F_121 ( & V_2 -> V_141 , F_44 ,
( unsigned long ) V_2 ) ;
V_2 -> V_158 . V_244 = & V_4 -> V_158 ;
F_65 ( & V_2 -> V_158 . V_210 , & V_4 -> V_158 . V_245 ) ;
V_4 -> V_2 [ V_2 -> V_60 ] = V_2 ;
V_80 = F_76 ( V_2 ) ;
if ( V_80 < 0 ) {
F_48 ( V_4 -> V_51 , L_42 ) ;
return V_80 ;
}
return 0 ;
}
static int F_122 ( struct V_228 * V_4 ,
struct V_210 * V_40 ) {
int V_70 , V_103 , V_238 = 1 ;
V_70 = F_116 ( V_40 , L_43 , & V_238 ) ;
if ( ( V_70 < 0 ) && V_4 -> V_124 )
F_123 ( V_4 -> V_51 , L_44 ) ;
for ( V_103 = 0 ; V_103 < V_238 ; V_103 ++ )
F_112 ( V_4 , V_40 , V_4 -> V_229 ++ ) ;
V_4 -> V_238 += V_238 ;
return 0 ;
}
static struct V_49 * F_124 ( struct V_246 * V_247 ,
struct V_248 * V_249 )
{
struct V_228 * V_4 = V_249 -> V_250 ;
int V_229 = V_247 -> args [ 0 ] ;
if ( V_229 >= V_4 -> V_238 || ! V_4 -> V_2 [ V_229 ] )
return NULL ;
return F_125 ( & V_4 -> V_2 [ V_229 ] -> V_158 ) ;
}
static int F_126 ( struct V_211 * V_212 )
{
int (* F_127)( struct V_211 * , struct V_213 * * , struct V_213 * * ,
struct V_213 * * , struct V_213 * * , struct V_213 * * )
= F_110 ;
struct V_210 * V_40 = V_212 -> V_51 . V_251 ;
struct V_228 * V_4 ;
struct V_210 * V_252 , * V_253 = V_212 -> V_51 . V_251 ;
struct V_254 * V_255 ;
T_1 V_256 , V_257 ;
int V_103 , V_80 ;
V_4 = F_113 ( & V_212 -> V_51 , sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return - V_61 ;
V_4 -> V_51 = & V_212 -> V_51 ;
if ( V_253 ) {
const struct V_258 * V_259 ;
V_259 = F_128 ( V_260 , V_253 ) ;
if ( V_259 && V_259 -> V_59 ) {
V_4 -> V_37 = V_259 -> V_59 ;
F_127 = V_4 -> V_37 -> F_127 ;
}
}
V_80 = F_127 ( V_212 , & V_4 -> V_214 , & V_4 -> V_215 , & V_4 -> V_225 ,
& V_4 -> V_216 , & V_4 -> V_226 ) ;
if ( V_80 )
return V_80 ;
V_255 = F_129 ( V_212 , V_261 , 0 ) ;
V_4 -> V_5 = F_130 ( & V_212 -> V_51 , V_255 ) ;
if ( F_105 ( V_4 -> V_5 ) )
return F_106 ( V_4 -> V_5 ) ;
V_4 -> V_64 = F_115 ( V_40 , L_45 ) ;
if ( V_4 -> V_37 -> V_38 == V_52 )
V_4 -> V_124 = F_115 ( V_40 , L_46 ) ;
if ( V_4 -> V_37 -> V_38 == V_39 ) {
V_80 = F_116 ( V_40 , L_47 ,
& V_256 ) ;
if ( V_80 < 0 ) {
F_48 ( V_4 -> V_51 ,
L_48 ) ;
return V_80 ;
}
V_80 = F_116 ( V_40 , L_49 ,
& V_4 -> V_138 ) ;
if ( V_80 < 0 )
F_123 ( V_4 -> V_51 ,
L_50 ) ;
}
V_80 = F_116 ( V_40 , L_51 , & V_257 ) ;
if ( V_80 < 0 )
F_123 ( V_4 -> V_51 , L_52 ) ;
if ( V_257 > 32 )
V_4 -> V_14 = true ;
else
V_4 -> V_14 = false ;
F_131 ( V_4 -> V_51 , F_132 ( V_257 ) ) ;
V_4 -> V_158 . V_51 = & V_212 -> V_51 ;
F_28 ( & V_4 -> V_158 . V_245 ) ;
if ( ! ( V_4 -> V_37 -> V_38 == V_41 ) ) {
F_133 ( V_262 , V_4 -> V_158 . V_263 ) ;
F_133 ( V_264 , V_4 -> V_158 . V_263 ) ;
}
V_4 -> V_158 . V_265 =
F_45 ;
V_4 -> V_158 . V_266 =
F_37 ;
V_4 -> V_158 . V_267 = F_98 ;
V_4 -> V_158 . V_268 = F_50 ;
V_4 -> V_158 . V_269 = F_72 ;
if ( V_4 -> V_37 -> V_38 == V_52 ) {
F_133 ( V_270 , V_4 -> V_158 . V_263 ) ;
V_4 -> V_158 . V_271 = F_91 ;
V_4 -> V_158 . V_272 =
F_96 ;
V_4 -> V_158 . V_273 =
F_97 ;
V_4 -> V_158 . V_274 =
V_275 ;
} else if ( V_4 -> V_37 -> V_38 == V_41 ) {
F_133 ( V_276 , V_4 -> V_158 . V_263 ) ;
V_4 -> V_158 . V_277 = F_90 ;
} else {
V_4 -> V_158 . V_273 =
F_86 ;
}
F_134 ( V_212 , V_4 ) ;
F_135 (node, child) {
V_80 = F_122 ( V_4 , V_252 ) ;
if ( V_80 < 0 )
goto V_278;
}
if ( V_4 -> V_37 -> V_38 == V_39 ) {
for ( V_103 = 0 ; V_103 < V_4 -> V_238 ; V_103 ++ )
if ( V_4 -> V_2 [ V_103 ] )
V_4 -> V_2 [ V_103 ] -> V_95 = V_256 ;
}
F_136 ( & V_4 -> V_158 ) ;
V_80 = F_137 ( V_40 , F_124 ,
V_4 ) ;
if ( V_80 < 0 ) {
F_48 ( & V_212 -> V_51 , L_53 ) ;
F_138 ( & V_4 -> V_158 ) ;
goto error;
}
F_139 ( & V_212 -> V_51 , L_54 ) ;
return 0 ;
V_278:
F_111 ( V_4 ) ;
error:
for ( V_103 = 0 ; V_103 < V_4 -> V_238 ; V_103 ++ )
if ( V_4 -> V_2 [ V_103 ] )
F_100 ( V_4 -> V_2 [ V_103 ] ) ;
return V_80 ;
}
static int F_140 ( struct V_211 * V_212 )
{
struct V_228 * V_4 = F_141 ( V_212 ) ;
int V_103 ;
F_142 ( V_212 -> V_51 . V_251 ) ;
F_138 ( & V_4 -> V_158 ) ;
for ( V_103 = 0 ; V_103 < V_4 -> V_238 ; V_103 ++ )
if ( V_4 -> V_2 [ V_103 ] )
F_100 ( V_4 -> V_2 [ V_103 ] ) ;
F_111 ( V_4 ) ;
return 0 ;
}
