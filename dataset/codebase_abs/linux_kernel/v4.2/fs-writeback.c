static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static bool F_3 ( struct V_5 * V_6 )
{
if ( F_4 ( V_6 ) ) {
return false ;
} else {
F_5 ( V_7 , & V_6 -> V_8 ) ;
F_6 ( ! V_6 -> V_9 ) ;
F_7 ( V_6 -> V_9 ,
& V_6 -> V_10 -> V_11 ) ;
return true ;
}
}
static void F_8 ( struct V_5 * V_6 )
{
if ( F_4 ( V_6 ) && F_9 ( & V_6 -> V_12 ) &&
F_9 ( & V_6 -> V_13 ) && F_9 ( & V_6 -> V_14 ) ) {
F_10 ( V_7 , & V_6 -> V_8 ) ;
F_6 ( F_11 ( V_6 -> V_9 ,
& V_6 -> V_10 -> V_11 ) < 0 ) ;
}
}
static bool F_12 ( struct V_1 * V_1 ,
struct V_5 * V_6 ,
struct V_2 * V_3 )
{
F_13 ( & V_6 -> V_15 ) ;
F_14 ( & V_1 -> V_4 , V_3 ) ;
if ( V_3 != & V_6 -> V_16 )
return F_3 ( V_6 ) ;
F_8 ( V_6 ) ;
return false ;
}
static void F_15 ( struct V_1 * V_1 ,
struct V_5 * V_6 )
{
F_13 ( & V_6 -> V_15 ) ;
F_16 ( & V_1 -> V_4 ) ;
F_8 ( V_6 ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
F_18 ( & V_6 -> V_17 ) ;
if ( F_19 ( V_18 , & V_6 -> V_8 ) )
F_20 ( V_19 , & V_6 -> V_20 , 0 ) ;
F_21 ( & V_6 -> V_17 ) ;
}
static void F_22 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
F_23 ( V_6 -> V_10 , V_22 ) ;
F_18 ( & V_6 -> V_17 ) ;
if ( ! F_19 ( V_18 , & V_6 -> V_8 ) ) {
if ( V_22 -> V_23 )
V_22 -> V_24 = 1 ;
goto V_25;
}
if ( V_22 -> V_26 )
F_24 ( & V_22 -> V_26 -> V_27 ) ;
F_25 ( & V_22 -> V_28 , & V_6 -> V_29 ) ;
F_20 ( V_19 , & V_6 -> V_20 , 0 ) ;
V_25:
F_21 ( & V_6 -> V_17 ) ;
}
static void F_26 ( struct V_30 * V_10 ,
struct V_31 * V_26 )
{
F_27 ( & V_26 -> V_27 ) ;
F_28 ( V_10 -> V_32 , ! F_29 ( & V_26 -> V_27 ) ) ;
}
void F_30 ( struct V_1 * V_1 , struct V_33 * V_33 )
{
struct V_30 * V_10 = F_31 ( V_1 ) ;
struct V_5 * V_6 = NULL ;
if ( F_32 ( V_1 ) ) {
struct V_34 * V_35 ;
if ( V_33 ) {
V_35 = F_33 ( V_33 ) ;
V_6 = F_34 ( V_10 , V_35 , V_36 ) ;
} else {
V_35 = F_35 ( V_37 , V_38 ) ;
V_6 = F_34 ( V_10 , V_35 , V_36 ) ;
F_36 ( V_35 ) ;
}
}
if ( ! V_6 )
V_6 = & V_10 -> V_6 ;
if ( F_37 ( F_38 ( & V_1 -> V_39 , NULL , V_6 ) ) )
F_39 ( V_6 ) ;
}
static struct V_5 *
F_40 ( struct V_1 * V_1 )
__releases( &inode->i_lock
static struct V_5 * F_41 ( struct V_1 * V_1 )
__acquires( &wb->list_lock
static void F_42 ( struct V_40 * V_22 )
{
struct V_41 * V_42 =
F_43 ( V_22 , struct V_41 , V_22 ) ;
struct V_1 * V_1 = V_42 -> V_1 ;
struct V_43 * V_44 = V_1 -> V_45 ;
struct V_5 * V_46 = V_1 -> V_39 ;
struct V_5 * V_47 = V_42 -> V_47 ;
struct V_48 V_49 ;
bool V_50 = false ;
void * * V_51 ;
if ( V_46 < V_47 ) {
F_44 ( & V_46 -> V_15 ) ;
F_45 ( & V_47 -> V_15 , V_52 ) ;
} else {
F_44 ( & V_47 -> V_15 ) ;
F_45 ( & V_46 -> V_15 , V_52 ) ;
}
F_44 ( & V_1 -> V_53 ) ;
F_46 ( & V_44 -> V_54 ) ;
if ( F_37 ( V_1 -> V_55 & V_56 ) )
goto V_57;
F_47 (slot, &mapping->page_tree, &iter, 0 ,
PAGECACHE_TAG_DIRTY) {
struct V_33 * V_33 = F_48 ( V_51 ,
& V_44 -> V_54 ) ;
if ( F_49 ( V_33 ) && F_50 ( V_33 ) ) {
F_51 ( V_46 , V_58 ) ;
F_52 ( V_47 , V_58 ) ;
}
}
F_47 (slot, &mapping->page_tree, &iter, 0 ,
PAGECACHE_TAG_WRITEBACK) {
struct V_33 * V_33 = F_48 ( V_51 ,
& V_44 -> V_54 ) ;
if ( F_49 ( V_33 ) ) {
F_6 ( ! F_53 ( V_33 ) ) ;
F_51 ( V_46 , V_59 ) ;
F_52 ( V_47 , V_59 ) ;
}
}
F_54 ( V_47 ) ;
if ( ! F_9 ( & V_1 -> V_4 ) ) {
struct V_1 * V_60 ;
F_15 ( V_1 , V_46 ) ;
V_1 -> V_39 = V_47 ;
F_55 (pos, &new_wb->b_dirty, i_wb_list)
if ( F_56 ( V_1 -> V_61 ,
V_60 -> V_61 ) )
break;
F_12 ( V_1 , V_47 , V_60 -> V_4 . V_62 ) ;
} else {
V_1 -> V_39 = V_47 ;
}
V_1 -> V_63 = 0 ;
V_1 -> V_64 = 0 ;
V_1 -> V_65 = 0 ;
V_50 = true ;
V_57:
F_57 ( & V_1 -> V_55 , V_1 -> V_55 & ~ V_66 ) ;
F_58 ( & V_44 -> V_54 ) ;
F_59 ( & V_1 -> V_53 ) ;
F_59 ( & V_47 -> V_15 ) ;
F_59 ( & V_46 -> V_15 ) ;
if ( V_50 ) {
F_17 ( V_47 ) ;
F_39 ( V_46 ) ;
}
F_39 ( V_47 ) ;
F_60 ( V_1 ) ;
F_61 ( V_42 ) ;
}
static void F_62 ( struct V_67 * V_67 )
{
struct V_41 * V_42 = F_43 ( V_67 ,
struct V_41 , V_67 ) ;
F_63 ( & V_42 -> V_22 , F_42 ) ;
F_64 ( & V_42 -> V_22 ) ;
}
static void F_65 ( struct V_1 * V_1 , int V_68 )
{
struct V_30 * V_10 = F_31 ( V_1 ) ;
struct V_34 * V_35 ;
struct V_41 * V_42 ;
if ( V_1 -> V_55 & V_66 )
return;
V_42 = F_66 ( sizeof( * V_42 ) , V_36 ) ;
if ( ! V_42 )
return;
F_67 () ;
V_35 = F_68 ( V_68 , & V_69 ) ;
if ( V_35 )
V_42 -> V_47 = F_34 ( V_10 , V_35 , V_36 ) ;
F_69 () ;
if ( ! V_42 -> V_47 )
goto V_70;
F_44 ( & V_1 -> V_53 ) ;
if ( V_1 -> V_55 & ( V_66 | V_56 ) ||
F_70 ( V_1 ) == V_42 -> V_47 ) {
F_59 ( & V_1 -> V_53 ) ;
goto V_70;
}
V_1 -> V_55 |= V_66 ;
F_59 ( & V_1 -> V_53 ) ;
F_71 ( V_1 ) ;
V_42 -> V_1 = V_1 ;
F_72 ( & V_42 -> V_67 , F_62 ) ;
return;
V_70:
if ( V_42 -> V_47 )
F_39 ( V_42 -> V_47 ) ;
F_61 ( V_42 ) ;
}
void F_73 ( struct V_71 * V_72 ,
struct V_1 * V_1 )
{
if ( ! F_32 ( V_1 ) ) {
F_59 ( & V_1 -> V_53 ) ;
return;
}
V_72 -> V_6 = F_70 ( V_1 ) ;
V_72 -> V_1 = V_1 ;
V_72 -> V_73 = V_72 -> V_6 -> V_35 -> V_74 ;
V_72 -> V_75 = V_1 -> V_63 ;
V_72 -> V_76 = 0 ;
V_72 -> V_77 = 0 ;
V_72 -> V_78 = 0 ;
V_72 -> V_79 = 0 ;
F_54 ( V_72 -> V_6 ) ;
F_59 ( & V_1 -> V_53 ) ;
if ( F_37 ( F_74 ( V_72 -> V_6 ) ) )
F_65 ( V_1 , V_72 -> V_73 ) ;
}
void F_75 ( struct V_71 * V_72 )
{
struct V_5 * V_6 = V_72 -> V_6 ;
struct V_1 * V_1 = V_72 -> V_1 ;
unsigned long V_80 , V_81 , V_82 ;
T_1 V_83 ;
int V_84 ;
if ( ! V_6 )
return;
V_83 = V_1 -> V_65 ;
V_80 = V_1 -> V_64 ;
if ( V_72 -> V_77 >= V_72 -> V_78 &&
V_72 -> V_77 >= V_72 -> V_79 ) {
V_84 = V_72 -> V_73 ;
V_81 = V_72 -> V_77 ;
} else if ( V_72 -> V_78 >= V_72 -> V_79 ) {
V_84 = V_72 -> V_75 ;
V_81 = V_72 -> V_78 ;
} else {
V_84 = V_72 -> V_76 ;
V_81 = V_72 -> V_79 ;
}
V_82 = F_76 ( ( V_81 >> V_85 ) << V_86 ,
V_6 -> V_9 ) ;
if ( V_80 )
V_80 += ( V_82 >> V_87 ) -
( V_80 >> V_87 ) ;
else
V_80 = V_82 ;
if ( V_82 >= V_80 / V_88 ) {
int V_89 ;
V_89 = F_77 ( F_76 ( V_82 , V_90 ) ,
( unsigned long ) V_91 ) ;
V_83 <<= V_89 ;
if ( V_72 -> V_73 != V_84 )
V_83 |= ( 1U << V_89 ) - 1 ;
if ( F_78 ( V_83 ) > V_92 )
F_65 ( V_1 , V_84 ) ;
}
V_1 -> V_63 = V_84 ;
V_1 -> V_64 = F_77 ( V_80 , ( unsigned long ) V_93 ) ;
V_1 -> V_65 = V_83 ;
F_39 ( V_72 -> V_6 ) ;
V_72 -> V_6 = NULL ;
}
void F_79 ( struct V_71 * V_72 , struct V_33 * V_33 ,
T_2 V_94 )
{
int V_74 ;
if ( ! V_72 -> V_6 )
return;
F_67 () ;
V_74 = F_33 ( V_33 ) -> V_74 ;
F_69 () ;
if ( V_74 == V_72 -> V_73 ) {
V_72 -> V_77 += V_94 ;
return;
}
if ( V_74 == V_72 -> V_75 )
V_72 -> V_78 += V_94 ;
if ( ! V_72 -> V_79 )
V_72 -> V_76 = V_74 ;
if ( V_74 == V_72 -> V_76 )
V_72 -> V_79 += V_94 ;
else
V_72 -> V_79 -= F_77 ( V_94 , V_72 -> V_79 ) ;
}
int F_80 ( struct V_1 * V_1 , int V_95 )
{
if ( V_1 && F_81 ( V_1 ) ) {
struct V_5 * V_6 ;
bool V_96 , V_97 ;
V_6 = F_82 ( V_1 , & V_96 ) ;
V_97 = F_83 ( V_6 , V_95 ) ;
F_84 ( V_1 , V_96 ) ;
return V_97 ;
}
return F_83 ( & F_31 ( V_1 ) -> V_6 , V_95 ) ;
}
static void F_85 ( struct V_30 * V_10 ,
struct V_21 * V_22 )
{
if ( F_6 ( ! V_22 -> V_23 ) )
return;
F_28 ( V_10 -> V_32 , V_22 -> V_24 ) ;
F_86 () ;
}
static long F_87 ( struct V_5 * V_6 , long V_98 )
{
unsigned long V_99 = V_6 -> V_9 ;
unsigned long V_100 = F_88 ( & V_6 -> V_10 -> V_11 ) ;
if ( V_98 == V_101 )
return V_101 ;
if ( ! V_100 || V_99 >= V_100 )
return V_98 ;
else
return F_89 ( ( V_102 ) V_98 * V_99 , V_100 ) ;
}
static bool F_90 ( struct V_5 * V_6 ,
struct V_21 * V_103 )
{
struct V_21 * V_22 ;
V_22 = F_91 ( sizeof( * V_22 ) , V_36 ) ;
if ( V_22 ) {
* V_22 = * V_103 ;
V_22 -> V_104 = 1 ;
V_22 -> V_23 = 0 ;
} else {
V_22 = V_103 ;
V_22 -> V_104 = 0 ;
V_22 -> V_23 = 1 ;
}
V_22 -> V_24 = 0 ;
F_22 ( V_6 , V_22 ) ;
return V_22 != V_103 ;
}
static void F_92 ( struct V_30 * V_10 ,
struct V_21 * V_103 ,
bool V_105 )
{
long V_98 = V_103 -> V_98 ;
int V_106 = 0 ;
struct V_5 * V_6 ;
struct V_107 V_49 ;
F_93 () ;
V_108:
F_67 () ;
F_94 (wb, bdi, &iter, next_blkcg_id) {
if ( ! F_4 ( V_6 ) &&
( V_103 -> V_109 == V_110 ||
F_9 ( & V_6 -> V_16 ) ) )
continue;
if ( V_105 && F_95 ( V_6 ) )
continue;
V_103 -> V_98 = F_87 ( V_6 , V_98 ) ;
if ( ! F_90 ( V_6 , V_103 ) ) {
V_106 = V_6 -> V_111 -> V_74 + 1 ;
F_69 () ;
F_85 ( V_10 , V_103 ) ;
goto V_108;
}
}
F_69 () ;
}
static struct V_5 *
F_40 ( struct V_1 * V_1 )
__releases( &inode->i_lock
static struct V_5 * F_41 ( struct V_1 * V_1 )
__acquires( &wb->list_lock
static long F_87 ( struct V_5 * V_6 , long V_98 )
{
return V_98 ;
}
static void F_92 ( struct V_30 * V_10 ,
struct V_21 * V_103 ,
bool V_105 )
{
F_93 () ;
if ( ! V_105 || ! F_95 ( & V_10 -> V_6 ) ) {
V_103 -> V_104 = 0 ;
V_103 -> V_23 = 0 ;
V_103 -> V_24 = 0 ;
F_22 ( & V_10 -> V_6 , V_103 ) ;
}
}
void F_96 ( struct V_5 * V_6 , long V_98 ,
bool V_112 , enum V_113 V_114 )
{
struct V_21 * V_22 ;
if ( ! F_4 ( V_6 ) )
return;
V_22 = F_66 ( sizeof( * V_22 ) , V_36 ) ;
if ( ! V_22 ) {
F_97 ( V_6 -> V_10 ) ;
F_17 ( V_6 ) ;
return;
}
V_22 -> V_109 = V_110 ;
V_22 -> V_98 = V_98 ;
V_22 -> V_112 = V_112 ;
V_22 -> V_114 = V_114 ;
V_22 -> V_104 = 1 ;
F_22 ( V_6 , V_22 ) ;
}
void F_98 ( struct V_5 * V_6 )
{
F_99 ( V_6 -> V_10 ) ;
F_17 ( V_6 ) ;
}
void F_100 ( struct V_1 * V_1 )
{
struct V_5 * V_6 ;
V_6 = F_41 ( V_1 ) ;
F_15 ( V_1 , V_6 ) ;
F_59 ( & V_6 -> V_15 ) ;
}
static void F_101 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
if ( ! F_9 ( & V_6 -> V_12 ) ) {
struct V_1 * V_115 ;
V_115 = F_1 ( V_6 -> V_12 . V_116 ) ;
if ( F_102 ( V_1 -> V_61 , V_115 -> V_61 ) )
V_1 -> V_61 = V_117 ;
}
F_12 ( V_1 , V_6 , & V_6 -> V_12 ) ;
}
static void F_103 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
F_12 ( V_1 , V_6 , & V_6 -> V_14 ) ;
}
static void F_104 ( struct V_1 * V_1 )
{
V_1 -> V_55 &= ~ V_118 ;
F_105 ( V_1 ) ;
F_106 () ;
F_107 ( & V_1 -> V_55 , V_119 ) ;
}
static bool F_108 ( struct V_1 * V_1 , unsigned long V_120 )
{
bool V_121 = F_109 ( V_1 -> V_61 , V_120 ) ;
#ifndef F_110
V_121 = V_121 && F_111 ( V_1 -> V_61 , V_117 ) ;
#endif
return V_121 ;
}
static int F_112 ( struct V_2 * V_122 ,
struct V_2 * V_123 ,
int V_124 ,
struct V_21 * V_22 )
{
unsigned long * V_125 = NULL ;
unsigned long V_126 ;
F_113 ( V_127 ) ;
struct V_2 * V_60 , * V_128 ;
struct V_129 * V_130 = NULL ;
struct V_1 * V_1 ;
int V_131 = 0 ;
int V_132 = 0 ;
if ( ( V_124 & V_133 ) == 0 )
V_125 = V_22 -> V_125 ;
else if ( ! V_22 -> V_134 ) {
V_126 = V_117 - ( V_135 * V_136 ) ;
V_125 = & V_126 ;
}
while ( ! F_9 ( V_122 ) ) {
V_1 = F_1 ( V_122 -> V_62 ) ;
if ( V_125 &&
F_108 ( V_1 , * V_125 ) )
break;
F_14 ( & V_1 -> V_4 , & V_127 ) ;
V_132 ++ ;
if ( V_124 & V_133 )
F_5 ( V_137 , & V_1 -> V_55 ) ;
if ( F_114 ( V_1 -> V_138 ) )
continue;
if ( V_130 && V_130 != V_1 -> V_138 )
V_131 = 1 ;
V_130 = V_1 -> V_138 ;
}
if ( ! V_131 ) {
F_115 ( & V_127 , V_123 ) ;
goto V_139;
}
while ( ! F_9 ( & V_127 ) ) {
V_130 = F_1 ( V_127 . V_62 ) -> V_138 ;
F_116 (pos, node, &tmp) {
V_1 = F_1 ( V_60 ) ;
if ( V_1 -> V_138 == V_130 )
F_14 ( & V_1 -> V_4 , V_123 ) ;
}
}
V_139:
return V_132 ;
}
static void F_117 ( struct V_5 * V_6 , struct V_21 * V_22 )
{
int V_132 ;
F_13 ( & V_6 -> V_15 ) ;
F_118 ( & V_6 -> V_14 , & V_6 -> V_13 ) ;
V_132 = F_112 ( & V_6 -> V_12 , & V_6 -> V_13 , 0 , V_22 ) ;
V_132 += F_112 ( & V_6 -> V_16 , & V_6 -> V_13 ,
V_133 , V_22 ) ;
if ( V_132 )
F_3 ( V_6 ) ;
F_119 ( V_6 , V_22 , V_132 ) ;
}
static int F_120 ( struct V_1 * V_1 , struct V_71 * V_72 )
{
int V_121 ;
if ( V_1 -> V_138 -> V_140 -> F_120 && ! F_121 ( V_1 ) ) {
F_122 ( V_1 , V_72 ) ;
V_121 = V_1 -> V_138 -> V_140 -> F_120 ( V_1 , V_72 ) ;
F_123 ( V_1 , V_72 ) ;
return V_121 ;
}
return 0 ;
}
static void F_124 ( struct V_1 * V_1 )
__releases( V_1 -> V_53 )
__acquires( V_1 -> V_53 )
{
F_125 ( V_141 , & V_1 -> V_55 , V_119 ) ;
T_3 * V_142 ;
V_142 = F_126 ( & V_1 -> V_55 , V_119 ) ;
while ( V_1 -> V_55 & V_118 ) {
F_59 ( & V_1 -> V_53 ) ;
F_127 ( V_142 , & V_141 , V_143 ,
V_144 ) ;
F_44 ( & V_1 -> V_53 ) ;
}
}
void F_128 ( struct V_1 * V_1 )
{
F_44 ( & V_1 -> V_53 ) ;
F_124 ( V_1 ) ;
F_59 ( & V_1 -> V_53 ) ;
}
static void F_129 ( struct V_1 * V_1 )
__releases( V_1 -> V_53 )
{
F_130 ( V_145 ) ;
T_3 * V_142 = F_126 ( & V_1 -> V_55 , V_119 ) ;
int V_146 ;
F_131 ( V_142 , & V_145 , V_144 ) ;
V_146 = V_1 -> V_55 & V_118 ;
F_59 ( & V_1 -> V_53 ) ;
if ( V_146 )
F_132 () ;
F_133 ( V_142 , & V_145 ) ;
}
static void F_134 ( struct V_1 * V_1 , struct V_5 * V_6 ,
struct V_71 * V_72 )
{
if ( V_1 -> V_55 & V_56 )
return;
if ( ( V_1 -> V_55 & V_147 ) &&
( V_72 -> V_109 == V_148 || V_72 -> V_149 ) )
V_1 -> V_61 = V_117 ;
if ( V_72 -> V_150 ) {
F_101 ( V_1 , V_6 ) ;
return;
}
if ( F_135 ( V_1 -> V_45 , V_151 ) ) {
if ( V_72 -> V_152 <= 0 ) {
F_103 ( V_1 , V_6 ) ;
} else {
F_101 ( V_1 , V_6 ) ;
}
} else if ( V_1 -> V_55 & V_147 ) {
F_101 ( V_1 , V_6 ) ;
} else if ( V_1 -> V_55 & V_153 ) {
V_1 -> V_61 = V_117 ;
F_12 ( V_1 , V_6 , & V_6 -> V_16 ) ;
} else {
F_15 ( V_1 , V_6 ) ;
}
}
static int
F_136 ( struct V_1 * V_1 , struct V_71 * V_72 )
{
struct V_43 * V_44 = V_1 -> V_45 ;
long V_152 = V_72 -> V_152 ;
unsigned V_154 ;
int V_121 ;
F_137 ( ! ( V_1 -> V_55 & V_118 ) ) ;
F_138 ( V_1 , V_72 , V_152 ) ;
V_121 = F_139 ( V_44 , V_72 ) ;
if ( V_72 -> V_109 == V_148 && ! V_72 -> V_134 ) {
int V_155 = F_140 ( V_44 ) ;
if ( V_121 == 0 )
V_121 = V_155 ;
}
F_44 ( & V_1 -> V_53 ) ;
V_154 = V_1 -> V_55 & V_147 ;
if ( V_1 -> V_55 & V_153 ) {
if ( ( V_154 & ( V_156 | V_157 ) ) ||
F_37 ( V_1 -> V_55 & V_158 ) ||
F_37 ( F_109 ( V_117 ,
( V_1 -> V_159 +
V_135 * V_136 ) ) ) ) {
V_154 |= V_153 | V_158 ;
F_141 ( V_1 ) ;
}
} else
V_1 -> V_55 &= ~ V_158 ;
V_1 -> V_55 &= ~ V_154 ;
F_106 () ;
if ( F_135 ( V_44 , V_151 ) )
V_1 -> V_55 |= V_160 ;
F_59 ( & V_1 -> V_53 ) ;
if ( V_154 & V_153 )
F_142 ( V_1 ) ;
if ( V_154 & ~ V_160 ) {
int V_155 = F_120 ( V_1 , V_72 ) ;
if ( V_121 == 0 )
V_121 = V_155 ;
}
F_143 ( V_1 , V_72 , V_152 ) ;
return V_121 ;
}
static int
F_144 ( struct V_1 * V_1 , struct V_5 * V_6 ,
struct V_71 * V_72 )
{
int V_121 = 0 ;
F_44 ( & V_1 -> V_53 ) ;
if ( ! F_29 ( & V_1 -> V_161 ) )
F_137 ( ! ( V_1 -> V_55 & ( V_162 | V_56 ) ) ) ;
else
F_137 ( V_1 -> V_55 & V_162 ) ;
if ( V_1 -> V_55 & V_118 ) {
if ( V_72 -> V_109 != V_148 )
goto V_139;
F_124 ( V_1 ) ;
}
F_137 ( V_1 -> V_55 & V_118 ) ;
if ( ! ( V_1 -> V_55 & V_163 ) &&
( V_72 -> V_109 != V_148 ||
! F_135 ( V_1 -> V_45 , V_164 ) ) )
goto V_139;
V_1 -> V_55 |= V_118 ;
F_73 ( V_72 , V_1 ) ;
V_121 = F_136 ( V_1 , V_72 ) ;
F_75 ( V_72 ) ;
F_44 ( & V_6 -> V_15 ) ;
F_44 ( & V_1 -> V_53 ) ;
if ( ! ( V_1 -> V_55 & V_163 ) )
F_15 ( V_1 , V_6 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_104 ( V_1 ) ;
V_139:
F_59 ( & V_1 -> V_53 ) ;
return V_121 ;
}
static long F_145 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
long V_165 ;
if ( V_22 -> V_109 == V_148 || V_22 -> V_149 )
V_165 = V_101 ;
else {
V_165 = F_77 ( V_6 -> V_9 / 2 ,
V_166 . V_167 / V_168 ) ;
V_165 = F_77 ( V_165 , V_22 -> V_98 ) ;
V_165 = F_146 ( V_165 + V_169 ,
V_169 ) ;
}
return V_165 ;
}
static long F_147 ( struct V_129 * V_130 ,
struct V_5 * V_6 ,
struct V_21 * V_22 )
{
struct V_71 V_72 = {
. V_109 = V_22 -> V_109 ,
. V_149 = V_22 -> V_149 ,
. V_170 = V_22 -> V_170 ,
. V_171 = V_22 -> V_171 ,
. V_134 = V_22 -> V_134 ,
. V_112 = V_22 -> V_112 ,
. V_172 = 0 ,
. V_173 = V_174 ,
} ;
unsigned long V_175 = V_117 ;
long V_176 ;
long V_177 = 0 ;
while ( ! F_9 ( & V_6 -> V_13 ) ) {
struct V_1 * V_1 = F_1 ( V_6 -> V_13 . V_62 ) ;
if ( V_1 -> V_138 != V_130 ) {
if ( V_22 -> V_130 ) {
F_101 ( V_1 , V_6 ) ;
continue;
}
break;
}
F_44 ( & V_1 -> V_53 ) ;
if ( V_1 -> V_55 & ( V_178 | V_56 | V_162 ) ) {
F_59 ( & V_1 -> V_53 ) ;
F_101 ( V_1 , V_6 ) ;
continue;
}
if ( ( V_1 -> V_55 & V_118 ) && V_72 . V_109 != V_148 ) {
F_59 ( & V_1 -> V_53 ) ;
F_103 ( V_1 , V_6 ) ;
F_148 ( V_1 ) ;
continue;
}
F_59 ( & V_6 -> V_15 ) ;
if ( V_1 -> V_55 & V_118 ) {
F_129 ( V_1 ) ;
F_44 ( & V_6 -> V_15 ) ;
continue;
}
V_1 -> V_55 |= V_118 ;
F_73 ( & V_72 , V_1 ) ;
V_176 = F_145 ( V_6 , V_22 ) ;
V_72 . V_152 = V_176 ;
V_72 . V_150 = 0 ;
F_136 ( V_1 , & V_72 ) ;
F_75 ( & V_72 ) ;
V_22 -> V_98 -= V_176 - V_72 . V_152 ;
V_177 += V_176 - V_72 . V_152 ;
F_44 ( & V_6 -> V_15 ) ;
F_44 ( & V_1 -> V_53 ) ;
if ( ! ( V_1 -> V_55 & V_163 ) )
V_177 ++ ;
F_134 ( V_1 , V_6 , & V_72 ) ;
F_104 ( V_1 ) ;
F_59 ( & V_1 -> V_53 ) ;
F_149 ( & V_6 -> V_15 ) ;
if ( V_177 ) {
if ( F_150 ( V_175 + V_136 / 10UL ) )
break;
if ( V_22 -> V_98 <= 0 )
break;
}
}
return V_177 ;
}
static long F_151 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
unsigned long V_175 = V_117 ;
long V_177 = 0 ;
while ( ! F_9 ( & V_6 -> V_13 ) ) {
struct V_1 * V_1 = F_1 ( V_6 -> V_13 . V_62 ) ;
struct V_129 * V_130 = V_1 -> V_138 ;
if ( ! F_152 ( V_130 ) ) {
F_101 ( V_1 , V_6 ) ;
continue;
}
V_177 += F_147 ( V_130 , V_6 , V_22 ) ;
F_153 ( & V_130 -> V_179 ) ;
if ( V_177 ) {
if ( F_150 ( V_175 + V_136 / 10UL ) )
break;
if ( V_22 -> V_98 <= 0 )
break;
}
}
return V_177 ;
}
static long F_154 ( struct V_5 * V_6 , long V_98 ,
enum V_113 V_114 )
{
struct V_21 V_22 = {
. V_98 = V_98 ,
. V_109 = V_110 ,
. V_112 = 1 ,
. V_114 = V_114 ,
} ;
F_44 ( & V_6 -> V_15 ) ;
if ( F_9 ( & V_6 -> V_13 ) )
F_117 ( V_6 , & V_22 ) ;
F_151 ( V_6 , & V_22 ) ;
F_59 ( & V_6 -> V_15 ) ;
return V_98 - V_22 . V_98 ;
}
static long F_155 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
unsigned long V_180 = V_117 ;
long V_98 = V_22 -> V_98 ;
unsigned long V_181 ;
struct V_1 * V_1 ;
long V_182 ;
V_181 = V_117 ;
V_22 -> V_125 = & V_181 ;
F_44 ( & V_6 -> V_15 ) ;
for (; ; ) {
if ( V_22 -> V_98 <= 0 )
break;
if ( ( V_22 -> V_171 || V_22 -> V_170 ) &&
! F_9 ( & V_6 -> V_29 ) )
break;
if ( V_22 -> V_171 && ! F_156 ( V_6 ) )
break;
if ( V_22 -> V_170 ) {
V_181 = V_117 -
F_157 ( V_183 * 10 ) ;
} else if ( V_22 -> V_171 )
V_181 = V_117 ;
F_158 ( V_6 -> V_10 , V_22 ) ;
if ( F_9 ( & V_6 -> V_13 ) )
F_117 ( V_6 , V_22 ) ;
if ( V_22 -> V_130 )
V_182 = F_147 ( V_22 -> V_130 , V_6 , V_22 ) ;
else
V_182 = F_151 ( V_6 , V_22 ) ;
F_159 ( V_6 -> V_10 , V_22 ) ;
F_160 ( V_6 , V_180 ) ;
if ( V_182 )
continue;
if ( F_9 ( & V_6 -> V_14 ) )
break;
if ( ! F_9 ( & V_6 -> V_14 ) ) {
F_161 ( V_6 -> V_10 , V_22 ) ;
V_1 = F_1 ( V_6 -> V_14 . V_62 ) ;
F_44 ( & V_1 -> V_53 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_129 ( V_1 ) ;
F_44 ( & V_6 -> V_15 ) ;
}
}
F_59 ( & V_6 -> V_15 ) ;
return V_98 - V_22 -> V_98 ;
}
static struct V_21 * F_162 ( struct V_5 * V_6 )
{
struct V_21 * V_22 = NULL ;
F_18 ( & V_6 -> V_17 ) ;
if ( ! F_9 ( & V_6 -> V_29 ) ) {
V_22 = F_2 ( V_6 -> V_29 . V_116 ,
struct V_21 , V_28 ) ;
F_16 ( & V_22 -> V_28 ) ;
}
F_21 ( & V_6 -> V_17 ) ;
return V_22 ;
}
static unsigned long F_163 ( void )
{
return F_164 ( V_184 ) +
F_164 ( V_185 ) +
F_165 () ;
}
static long F_166 ( struct V_5 * V_6 )
{
if ( F_156 ( V_6 ) ) {
struct V_21 V_22 = {
. V_98 = V_101 ,
. V_109 = V_110 ,
. V_171 = 1 ,
. V_112 = 1 ,
. V_114 = V_186 ,
} ;
return F_155 ( V_6 , & V_22 ) ;
}
return 0 ;
}
static long F_167 ( struct V_5 * V_6 )
{
unsigned long V_187 ;
long V_98 ;
if ( ! V_188 )
return 0 ;
V_187 = V_6 -> V_189 +
F_157 ( V_188 * 10 ) ;
if ( F_102 ( V_117 , V_187 ) )
return 0 ;
V_6 -> V_189 = V_117 ;
V_98 = F_163 () ;
if ( V_98 ) {
struct V_21 V_22 = {
. V_98 = V_98 ,
. V_109 = V_110 ,
. V_170 = 1 ,
. V_112 = 1 ,
. V_114 = V_190 ,
} ;
return F_155 ( V_6 , & V_22 ) ;
}
return 0 ;
}
static long F_168 ( struct V_5 * V_6 )
{
struct V_21 * V_22 ;
long V_177 = 0 ;
F_5 ( V_191 , & V_6 -> V_8 ) ;
while ( ( V_22 = F_162 ( V_6 ) ) != NULL ) {
struct V_31 * V_26 = V_22 -> V_26 ;
bool V_192 = false ;
F_169 ( V_6 -> V_10 , V_22 ) ;
V_177 += F_155 ( V_6 , V_22 ) ;
if ( V_22 -> V_23 ) {
F_6 ( V_22 -> V_104 ) ;
F_170 () ;
V_22 -> V_24 = 1 ;
V_192 = true ;
} else if ( V_22 -> V_104 ) {
F_61 ( V_22 ) ;
}
if ( V_26 && F_171 ( & V_26 -> V_27 ) )
V_192 = true ;
if ( V_192 )
F_172 ( & V_6 -> V_10 -> V_32 ) ;
}
V_177 += F_167 ( V_6 ) ;
V_177 += F_166 ( V_6 ) ;
F_10 ( V_191 , & V_6 -> V_8 ) ;
return V_177 ;
}
void F_173 ( struct V_40 * V_22 )
{
struct V_5 * V_6 = F_43 ( F_174 ( V_22 ) ,
struct V_5 , V_20 ) ;
long V_193 ;
F_175 ( L_1 , F_176 ( V_6 -> V_10 -> V_194 ) ) ;
V_37 -> V_124 |= V_195 ;
if ( F_49 ( ! F_177 () ||
! F_19 ( V_18 , & V_6 -> V_8 ) ) ) {
do {
V_193 = F_168 ( V_6 ) ;
F_178 ( V_193 ) ;
} while ( ! F_9 ( & V_6 -> V_29 ) );
} else {
V_193 = F_154 ( V_6 , 1024 ,
V_196 ) ;
F_178 ( V_193 ) ;
}
if ( ! F_9 ( & V_6 -> V_29 ) )
F_20 ( V_19 , & V_6 -> V_20 , 0 ) ;
else if ( F_4 ( V_6 ) && V_188 )
F_179 ( V_6 ) ;
V_37 -> V_124 &= ~ V_195 ;
}
void F_180 ( long V_98 , enum V_113 V_114 )
{
struct V_30 * V_10 ;
if ( ! V_98 )
V_98 = F_163 () ;
F_67 () ;
F_181 (bdi, &bdi_list, bdi_list) {
struct V_5 * V_6 ;
struct V_107 V_49 ;
if ( ! F_182 ( V_10 ) )
continue;
F_94 (wb, bdi, &iter, 0 )
F_96 ( V_6 , F_87 ( V_6 , V_98 ) ,
false , V_114 ) ;
}
F_69 () ;
}
static void F_183 ( struct V_40 * V_197 )
{
struct V_30 * V_10 ;
F_67 () ;
F_181 (bdi, &bdi_list, bdi_list) {
struct V_5 * V_6 ;
struct V_107 V_49 ;
F_94 (wb, bdi, &iter, 0 )
if ( ! F_9 ( & V_10 -> V_6 . V_16 ) )
F_17 ( & V_10 -> V_6 ) ;
}
F_69 () ;
F_184 ( & V_198 , V_135 * V_136 ) ;
}
static int T_4 F_185 ( void )
{
F_184 ( & V_198 , V_135 * V_136 ) ;
return 0 ;
}
int F_186 ( struct V_199 * V_200 , int V_201 ,
void T_5 * V_202 , T_2 * V_203 , T_6 * V_204 )
{
int V_121 ;
V_121 = F_187 ( V_200 , V_201 , V_202 , V_203 , V_204 ) ;
if ( V_121 == 0 && V_201 )
F_20 ( V_205 , & V_198 , 0 ) ;
return V_121 ;
}
static T_7 void F_188 ( struct V_1 * V_1 )
{
if ( V_1 -> V_206 || strcmp ( V_1 -> V_138 -> V_207 , L_2 ) ) {
struct V_208 * V_208 ;
const char * V_209 = L_3 ;
V_208 = F_189 ( V_1 ) ;
if ( V_208 ) {
F_44 ( & V_208 -> V_210 ) ;
V_209 = ( const char * ) V_208 -> V_211 . V_209 ;
}
F_190 ( V_212
L_4 ,
V_37 -> V_213 , F_191 ( V_37 ) , V_1 -> V_206 ,
V_209 , V_1 -> V_138 -> V_207 ) ;
if ( V_208 ) {
F_59 ( & V_208 -> V_210 ) ;
F_192 ( V_208 ) ;
}
}
}
void F_193 ( struct V_1 * V_1 , int V_124 )
{
struct V_129 * V_130 = V_1 -> V_138 ;
int V_214 ;
F_194 ( V_1 , V_124 ) ;
if ( V_124 & ( V_156 | V_157 | V_153 ) ) {
F_195 ( V_1 , V_124 ) ;
if ( V_130 -> V_140 -> V_215 )
V_130 -> V_140 -> V_215 ( V_1 , V_124 ) ;
F_196 ( V_1 , V_124 ) ;
}
if ( V_124 & V_216 )
V_124 &= ~ V_153 ;
V_214 = V_124 & V_153 ;
F_106 () ;
if ( ( ( V_1 -> V_55 & V_124 ) == V_124 ) ||
( V_214 && ( V_1 -> V_55 & V_216 ) ) )
return;
if ( F_37 ( V_217 ) )
F_188 ( V_1 ) ;
F_44 ( & V_1 -> V_53 ) ;
if ( V_214 && ( V_1 -> V_55 & V_216 ) )
goto V_218;
if ( ( V_1 -> V_55 & V_124 ) != V_124 ) {
const int V_219 = V_1 -> V_55 & V_147 ;
F_197 ( V_1 , NULL ) ;
if ( V_124 & V_216 )
V_1 -> V_55 &= ~ V_153 ;
V_1 -> V_55 |= V_124 ;
if ( V_1 -> V_55 & V_118 )
goto V_218;
if ( ! F_198 ( V_1 -> V_220 ) ) {
if ( F_199 ( V_1 ) )
goto V_218;
}
if ( V_1 -> V_55 & V_56 )
goto V_218;
if ( ! V_219 ) {
struct V_5 * V_6 ;
struct V_2 * V_221 ;
bool V_222 = false ;
V_6 = F_40 ( V_1 ) ;
F_200 ( F_201 ( V_6 -> V_10 ) &&
! F_19 ( V_18 , & V_6 -> V_8 ) ,
L_5 , V_6 -> V_10 -> V_209 ) ;
V_1 -> V_61 = V_117 ;
if ( V_214 )
V_1 -> V_159 = V_117 ;
if ( V_1 -> V_55 & ( V_216 | V_160 ) )
V_221 = & V_6 -> V_12 ;
else
V_221 = & V_6 -> V_16 ;
V_222 = F_12 ( V_1 , V_6 ,
V_221 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_202 ( V_1 ) ;
if ( F_201 ( V_6 -> V_10 ) && V_222 )
F_179 ( V_6 ) ;
return;
}
}
V_218:
F_59 ( & V_1 -> V_53 ) ;
}
static void F_203 ( struct V_129 * V_130 )
{
struct V_1 * V_1 , * V_223 = NULL ;
F_137 ( ! F_204 ( & V_130 -> V_179 ) ) ;
F_44 ( & V_224 ) ;
F_55 (inode, &sb->s_inodes, i_sb_list) {
struct V_43 * V_44 = V_1 -> V_45 ;
F_44 ( & V_1 -> V_53 ) ;
if ( ( V_1 -> V_55 & ( V_56 | V_162 | V_178 ) ) ||
( V_44 -> V_225 == 0 ) ) {
F_59 ( & V_1 -> V_53 ) ;
continue;
}
F_205 ( V_1 ) ;
F_59 ( & V_1 -> V_53 ) ;
F_59 ( & V_224 ) ;
F_60 ( V_223 ) ;
V_223 = V_1 ;
F_140 ( V_44 ) ;
F_206 () ;
F_44 ( & V_224 ) ;
}
F_59 ( & V_224 ) ;
F_60 ( V_223 ) ;
}
static void F_207 ( struct V_129 * V_130 , unsigned long V_226 ,
enum V_113 V_114 , bool V_105 )
{
F_208 ( V_26 ) ;
struct V_21 V_22 = {
. V_130 = V_130 ,
. V_109 = V_110 ,
. V_149 = 1 ,
. V_26 = & V_26 ,
. V_98 = V_226 ,
. V_114 = V_114 ,
} ;
struct V_30 * V_10 = V_130 -> V_227 ;
if ( ! F_182 ( V_10 ) || V_10 == & V_228 )
return;
F_137 ( ! F_204 ( & V_130 -> V_179 ) ) ;
F_92 ( V_130 -> V_227 , & V_22 , V_105 ) ;
F_26 ( V_10 , & V_26 ) ;
}
void F_209 ( struct V_129 * V_130 ,
unsigned long V_226 ,
enum V_113 V_114 )
{
F_207 ( V_130 , V_226 , V_114 , false ) ;
}
void F_210 ( struct V_129 * V_130 , enum V_113 V_114 )
{
return F_209 ( V_130 , F_163 () , V_114 ) ;
}
bool F_211 ( struct V_129 * V_130 , unsigned long V_226 ,
enum V_113 V_114 )
{
if ( ! F_212 ( & V_130 -> V_179 ) )
return false ;
F_207 ( V_130 , V_226 , V_114 , true ) ;
F_153 ( & V_130 -> V_179 ) ;
return true ;
}
bool F_213 ( struct V_129 * V_130 , enum V_113 V_114 )
{
return F_211 ( V_130 , F_163 () , V_114 ) ;
}
void F_214 ( struct V_129 * V_130 )
{
F_208 ( V_26 ) ;
struct V_21 V_22 = {
. V_130 = V_130 ,
. V_109 = V_148 ,
. V_98 = V_101 ,
. V_112 = 0 ,
. V_26 = & V_26 ,
. V_114 = V_229 ,
. V_134 = 1 ,
} ;
struct V_30 * V_10 = V_130 -> V_227 ;
if ( V_10 == & V_228 )
return;
F_137 ( ! F_204 ( & V_130 -> V_179 ) ) ;
F_92 ( V_10 , & V_22 , false ) ;
F_26 ( V_10 , & V_26 ) ;
F_203 ( V_130 ) ;
}
int F_215 ( struct V_1 * V_1 , int V_230 )
{
struct V_5 * V_6 = & F_31 ( V_1 ) -> V_6 ;
struct V_71 V_72 = {
. V_152 = V_101 ,
. V_109 = V_230 ? V_148 : V_110 ,
. V_172 = 0 ,
. V_173 = V_174 ,
} ;
if ( ! F_216 ( V_1 -> V_45 ) )
V_72 . V_152 = 0 ;
F_93 () ;
return F_144 ( V_1 , V_6 , & V_72 ) ;
}
int F_217 ( struct V_1 * V_1 , struct V_71 * V_72 )
{
return F_144 ( V_1 , & F_31 ( V_1 ) -> V_6 , V_72 ) ;
}
int F_218 ( struct V_1 * V_1 , int V_145 )
{
struct V_71 V_72 = {
. V_109 = V_145 ? V_148 : V_110 ,
. V_152 = 0 ,
} ;
return F_217 ( V_1 , & V_72 ) ;
}
