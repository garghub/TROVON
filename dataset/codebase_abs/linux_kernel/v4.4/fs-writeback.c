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
F_23 ( V_6 , V_22 ) ;
F_18 ( & V_6 -> V_17 ) ;
if ( ! F_19 ( V_18 , & V_6 -> V_8 ) )
goto V_23;
if ( V_22 -> V_24 )
F_24 ( & V_22 -> V_24 -> V_25 ) ;
F_25 ( & V_22 -> V_26 , & V_6 -> V_27 ) ;
F_20 ( V_19 , & V_6 -> V_20 , 0 ) ;
V_23:
F_21 ( & V_6 -> V_17 ) ;
}
static void F_26 ( struct V_28 * V_10 ,
struct V_29 * V_24 )
{
F_27 ( & V_24 -> V_25 ) ;
F_28 ( V_10 -> V_30 , ! F_29 ( & V_24 -> V_25 ) ) ;
}
void F_30 ( struct V_1 * V_1 , struct V_31 * V_31 )
{
struct V_28 * V_10 = F_31 ( V_1 ) ;
struct V_5 * V_6 = NULL ;
if ( F_32 ( V_1 ) ) {
struct V_32 * V_33 ;
if ( V_31 ) {
V_33 = F_33 ( V_31 ) ;
V_6 = F_34 ( V_10 , V_33 , V_34 ) ;
} else {
V_33 = F_35 ( V_35 , V_36 ) ;
V_6 = F_34 ( V_10 , V_33 , V_34 ) ;
F_36 ( V_33 ) ;
}
}
if ( ! V_6 )
V_6 = & V_10 -> V_6 ;
if ( F_37 ( F_38 ( & V_1 -> V_37 , NULL , V_6 ) ) )
F_39 ( V_6 ) ;
}
static struct V_5 *
F_40 ( struct V_1 * V_1 )
__releases( &inode->i_lock
static struct V_5 * F_41 ( struct V_1 * V_1 )
__acquires( &wb->list_lock
static void F_42 ( struct V_38 * V_22 )
{
struct V_39 * V_40 =
F_43 ( V_22 , struct V_39 , V_22 ) ;
struct V_1 * V_1 = V_40 -> V_1 ;
struct V_41 * V_42 = V_1 -> V_43 ;
struct V_5 * V_44 = V_1 -> V_37 ;
struct V_5 * V_45 = V_40 -> V_45 ;
struct V_46 V_47 ;
bool V_48 = false ;
void * * V_49 ;
if ( V_44 < V_45 ) {
F_44 ( & V_44 -> V_15 ) ;
F_45 ( & V_45 -> V_15 , V_50 ) ;
} else {
F_44 ( & V_45 -> V_15 ) ;
F_45 ( & V_44 -> V_15 , V_50 ) ;
}
F_44 ( & V_1 -> V_51 ) ;
F_46 ( & V_42 -> V_52 ) ;
if ( F_37 ( V_1 -> V_53 & V_54 ) )
goto V_55;
F_47 (slot, &mapping->page_tree, &iter, 0 ,
PAGECACHE_TAG_DIRTY) {
struct V_31 * V_31 = F_48 ( V_49 ,
& V_42 -> V_52 ) ;
if ( F_49 ( V_31 ) && F_50 ( V_31 ) ) {
F_51 ( V_44 , V_56 ) ;
F_52 ( V_45 , V_56 ) ;
}
}
F_47 (slot, &mapping->page_tree, &iter, 0 ,
PAGECACHE_TAG_WRITEBACK) {
struct V_31 * V_31 = F_48 ( V_49 ,
& V_42 -> V_52 ) ;
if ( F_49 ( V_31 ) ) {
F_6 ( ! F_53 ( V_31 ) ) ;
F_51 ( V_44 , V_57 ) ;
F_52 ( V_45 , V_57 ) ;
}
}
F_54 ( V_45 ) ;
if ( ! F_9 ( & V_1 -> V_4 ) ) {
struct V_1 * V_58 ;
F_15 ( V_1 , V_44 ) ;
V_1 -> V_37 = V_45 ;
F_55 (pos, &new_wb->b_dirty, i_io_list)
if ( F_56 ( V_1 -> V_59 ,
V_58 -> V_59 ) )
break;
F_12 ( V_1 , V_45 , V_58 -> V_4 . V_60 ) ;
} else {
V_1 -> V_37 = V_45 ;
}
V_1 -> V_61 = 0 ;
V_1 -> V_62 = 0 ;
V_1 -> V_63 = 0 ;
V_48 = true ;
V_55:
F_57 ( & V_1 -> V_53 , V_1 -> V_53 & ~ V_64 ) ;
F_58 ( & V_42 -> V_52 ) ;
F_59 ( & V_1 -> V_51 ) ;
F_59 ( & V_45 -> V_15 ) ;
F_59 ( & V_44 -> V_15 ) ;
if ( V_48 ) {
F_17 ( V_45 ) ;
F_39 ( V_44 ) ;
}
F_39 ( V_45 ) ;
F_60 ( V_1 ) ;
F_61 ( V_40 ) ;
}
static void F_62 ( struct V_65 * V_65 )
{
struct V_39 * V_40 = F_43 ( V_65 ,
struct V_39 , V_65 ) ;
F_63 ( & V_40 -> V_22 , F_42 ) ;
F_64 ( & V_40 -> V_22 ) ;
}
static void F_65 ( struct V_1 * V_1 , int V_66 )
{
struct V_28 * V_10 = F_31 ( V_1 ) ;
struct V_32 * V_33 ;
struct V_39 * V_40 ;
if ( V_1 -> V_53 & V_64 )
return;
V_40 = F_66 ( sizeof( * V_40 ) , V_34 ) ;
if ( ! V_40 )
return;
F_67 () ;
V_33 = F_68 ( V_66 , & V_67 ) ;
if ( V_33 )
V_40 -> V_45 = F_34 ( V_10 , V_33 , V_34 ) ;
F_69 () ;
if ( ! V_40 -> V_45 )
goto V_68;
F_44 ( & V_1 -> V_51 ) ;
if ( V_1 -> V_53 & ( V_64 | V_54 ) ||
F_70 ( V_1 ) == V_40 -> V_45 ) {
F_59 ( & V_1 -> V_51 ) ;
goto V_68;
}
V_1 -> V_53 |= V_64 ;
F_59 ( & V_1 -> V_51 ) ;
F_71 ( V_1 ) ;
V_40 -> V_1 = V_1 ;
F_72 ( & V_40 -> V_65 , F_62 ) ;
return;
V_68:
if ( V_40 -> V_45 )
F_39 ( V_40 -> V_45 ) ;
F_61 ( V_40 ) ;
}
void F_73 ( struct V_69 * V_70 ,
struct V_1 * V_1 )
{
if ( ! F_32 ( V_1 ) ) {
F_59 ( & V_1 -> V_51 ) ;
return;
}
V_70 -> V_6 = F_70 ( V_1 ) ;
V_70 -> V_1 = V_1 ;
V_70 -> V_71 = V_70 -> V_6 -> V_33 -> V_72 ;
V_70 -> V_73 = V_1 -> V_61 ;
V_70 -> V_74 = 0 ;
V_70 -> V_75 = 0 ;
V_70 -> V_76 = 0 ;
V_70 -> V_77 = 0 ;
F_54 ( V_70 -> V_6 ) ;
F_59 ( & V_1 -> V_51 ) ;
if ( F_37 ( F_74 ( V_70 -> V_6 ) ) )
F_65 ( V_1 , V_70 -> V_71 ) ;
}
void F_75 ( struct V_69 * V_70 )
{
struct V_5 * V_6 = V_70 -> V_6 ;
struct V_1 * V_1 = V_70 -> V_1 ;
unsigned long V_78 , V_79 , V_80 ;
T_1 V_81 ;
int V_82 ;
if ( ! V_6 )
return;
V_81 = V_1 -> V_63 ;
V_78 = V_1 -> V_62 ;
if ( V_70 -> V_75 >= V_70 -> V_76 &&
V_70 -> V_75 >= V_70 -> V_77 ) {
V_82 = V_70 -> V_71 ;
V_79 = V_70 -> V_75 ;
} else if ( V_70 -> V_76 >= V_70 -> V_77 ) {
V_82 = V_70 -> V_73 ;
V_79 = V_70 -> V_76 ;
} else {
V_82 = V_70 -> V_74 ;
V_79 = V_70 -> V_77 ;
}
V_80 = F_76 ( ( V_79 >> V_83 ) << V_84 ,
V_6 -> V_9 ) ;
if ( V_78 )
V_78 += ( V_80 >> V_85 ) -
( V_78 >> V_85 ) ;
else
V_78 = V_80 ;
if ( V_80 >= V_78 / V_86 ) {
int V_87 ;
V_87 = F_77 ( F_76 ( V_80 , V_88 ) ,
( unsigned long ) V_89 ) ;
V_81 <<= V_87 ;
if ( V_70 -> V_71 != V_82 )
V_81 |= ( 1U << V_87 ) - 1 ;
if ( F_78 ( V_81 ) > V_90 )
F_65 ( V_1 , V_82 ) ;
}
V_1 -> V_61 = V_82 ;
V_1 -> V_62 = F_77 ( V_78 , ( unsigned long ) V_91 ) ;
V_1 -> V_63 = V_81 ;
F_39 ( V_70 -> V_6 ) ;
V_70 -> V_6 = NULL ;
}
void F_79 ( struct V_69 * V_70 , struct V_31 * V_31 ,
T_2 V_92 )
{
int V_72 ;
if ( ! V_70 -> V_6 )
return;
F_67 () ;
V_72 = F_33 ( V_31 ) -> V_72 ;
F_69 () ;
if ( V_72 == V_70 -> V_71 ) {
V_70 -> V_75 += V_92 ;
return;
}
if ( V_72 == V_70 -> V_73 )
V_70 -> V_76 += V_92 ;
if ( ! V_70 -> V_77 )
V_70 -> V_74 = V_72 ;
if ( V_72 == V_70 -> V_74 )
V_70 -> V_77 += V_92 ;
else
V_70 -> V_77 -= F_77 ( V_92 , V_70 -> V_77 ) ;
}
int F_80 ( struct V_1 * V_1 , int V_93 )
{
if ( V_1 && F_81 ( V_1 ) ) {
struct V_5 * V_6 ;
bool V_94 , V_95 ;
V_6 = F_82 ( V_1 , & V_94 ) ;
V_95 = F_83 ( V_6 , V_93 ) ;
F_84 ( V_1 , V_94 ) ;
return V_95 ;
}
return F_83 ( & F_31 ( V_1 ) -> V_6 , V_93 ) ;
}
static long F_85 ( struct V_5 * V_6 , long V_96 )
{
unsigned long V_97 = V_6 -> V_9 ;
unsigned long V_98 = F_86 ( & V_6 -> V_10 -> V_11 ) ;
if ( V_96 == V_99 )
return V_99 ;
if ( ! V_98 || V_97 >= V_98 )
return V_96 ;
else
return F_87 ( ( V_100 ) V_96 * V_97 , V_98 ) ;
}
static void F_88 ( struct V_28 * V_10 ,
struct V_21 * V_101 ,
bool V_102 )
{
struct V_5 * V_103 = NULL ;
struct V_5 * V_6 = F_2 ( & V_10 -> V_104 ,
struct V_5 , V_105 ) ;
F_89 () ;
V_106:
F_67 () ;
F_90 (wb, &bdi->wb_list, bdi_node) {
F_91 ( V_107 ) ;
struct V_21 V_108 ;
struct V_21 * V_22 ;
long V_96 ;
if ( V_103 ) {
F_39 ( V_103 ) ;
V_103 = NULL ;
}
if ( ! F_4 ( V_6 ) &&
( V_101 -> V_109 == V_110 ||
F_9 ( & V_6 -> V_16 ) ) )
continue;
if ( V_102 && F_92 ( V_6 ) )
continue;
V_96 = F_85 ( V_6 , V_101 -> V_96 ) ;
V_22 = F_93 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 ) {
* V_22 = * V_101 ;
V_22 -> V_96 = V_96 ;
V_22 -> V_111 = 1 ;
F_22 ( V_6 , V_22 ) ;
continue;
}
V_22 = & V_108 ;
* V_22 = * V_101 ;
V_22 -> V_96 = V_96 ;
V_22 -> V_111 = 0 ;
V_22 -> V_24 = & V_107 ;
F_22 ( V_6 , V_22 ) ;
F_54 ( V_6 ) ;
V_103 = V_6 ;
F_69 () ;
F_26 ( V_10 , & V_107 ) ;
goto V_106;
}
F_69 () ;
if ( V_103 )
F_39 ( V_103 ) ;
}
static struct V_5 *
F_40 ( struct V_1 * V_1 )
__releases( &inode->i_lock
static struct V_5 * F_41 ( struct V_1 * V_1 )
__acquires( &wb->list_lock
static long F_85 ( struct V_5 * V_6 , long V_96 )
{
return V_96 ;
}
static void F_88 ( struct V_28 * V_10 ,
struct V_21 * V_101 ,
bool V_102 )
{
F_89 () ;
if ( ! V_102 || ! F_92 ( & V_10 -> V_6 ) ) {
V_101 -> V_111 = 0 ;
F_22 ( & V_10 -> V_6 , V_101 ) ;
}
}
void F_94 ( struct V_5 * V_6 , long V_96 ,
bool V_112 , enum V_113 V_114 )
{
struct V_21 * V_22 ;
if ( ! F_4 ( V_6 ) )
return;
V_22 = F_66 ( sizeof( * V_22 ) , V_34 ) ;
if ( ! V_22 ) {
F_95 ( V_6 ) ;
F_17 ( V_6 ) ;
return;
}
V_22 -> V_109 = V_110 ;
V_22 -> V_96 = V_96 ;
V_22 -> V_112 = V_112 ;
V_22 -> V_114 = V_114 ;
V_22 -> V_111 = 1 ;
F_22 ( V_6 , V_22 ) ;
}
void F_96 ( struct V_5 * V_6 )
{
F_97 ( V_6 ) ;
F_17 ( V_6 ) ;
}
void F_98 ( struct V_1 * V_1 )
{
struct V_5 * V_6 ;
V_6 = F_41 ( V_1 ) ;
F_15 ( V_1 , V_6 ) ;
F_59 ( & V_6 -> V_15 ) ;
}
static void F_99 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
if ( ! F_9 ( & V_6 -> V_12 ) ) {
struct V_1 * V_115 ;
V_115 = F_1 ( V_6 -> V_12 . V_116 ) ;
if ( F_100 ( V_1 -> V_59 , V_115 -> V_59 ) )
V_1 -> V_59 = V_117 ;
}
F_12 ( V_1 , V_6 , & V_6 -> V_12 ) ;
}
static void F_101 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
F_12 ( V_1 , V_6 , & V_6 -> V_14 ) ;
}
static void F_102 ( struct V_1 * V_1 )
{
V_1 -> V_53 &= ~ V_118 ;
F_103 ( V_1 ) ;
F_104 () ;
F_105 ( & V_1 -> V_53 , V_119 ) ;
}
static bool F_106 ( struct V_1 * V_1 , unsigned long V_120 )
{
bool V_121 = F_107 ( V_1 -> V_59 , V_120 ) ;
#ifndef F_108
V_121 = V_121 && F_109 ( V_1 -> V_59 , V_117 ) ;
#endif
return V_121 ;
}
static int F_110 ( struct V_2 * V_122 ,
struct V_2 * V_123 ,
int V_124 ,
struct V_21 * V_22 )
{
unsigned long * V_125 = NULL ;
unsigned long V_126 ;
F_111 ( V_127 ) ;
struct V_2 * V_58 , * V_128 ;
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
V_1 = F_1 ( V_122 -> V_60 ) ;
if ( V_125 &&
F_106 ( V_1 , * V_125 ) )
break;
F_14 ( & V_1 -> V_4 , & V_127 ) ;
V_132 ++ ;
if ( V_124 & V_133 )
F_5 ( V_137 , & V_1 -> V_53 ) ;
if ( F_112 ( V_1 -> V_138 ) )
continue;
if ( V_130 && V_130 != V_1 -> V_138 )
V_131 = 1 ;
V_130 = V_1 -> V_138 ;
}
if ( ! V_131 ) {
F_113 ( & V_127 , V_123 ) ;
goto V_139;
}
while ( ! F_9 ( & V_127 ) ) {
V_130 = F_1 ( V_127 . V_60 ) -> V_138 ;
F_114 (pos, node, &tmp) {
V_1 = F_1 ( V_58 ) ;
if ( V_1 -> V_138 == V_130 )
F_14 ( & V_1 -> V_4 , V_123 ) ;
}
}
V_139:
return V_132 ;
}
static void F_115 ( struct V_5 * V_6 , struct V_21 * V_22 )
{
int V_132 ;
F_13 ( & V_6 -> V_15 ) ;
F_116 ( & V_6 -> V_14 , & V_6 -> V_13 ) ;
V_132 = F_110 ( & V_6 -> V_12 , & V_6 -> V_13 , 0 , V_22 ) ;
V_132 += F_110 ( & V_6 -> V_16 , & V_6 -> V_13 ,
V_133 , V_22 ) ;
if ( V_132 )
F_3 ( V_6 ) ;
F_117 ( V_6 , V_22 , V_132 ) ;
}
static int F_118 ( struct V_1 * V_1 , struct V_69 * V_70 )
{
int V_121 ;
if ( V_1 -> V_138 -> V_140 -> F_118 && ! F_119 ( V_1 ) ) {
F_120 ( V_1 , V_70 ) ;
V_121 = V_1 -> V_138 -> V_140 -> F_118 ( V_1 , V_70 ) ;
F_121 ( V_1 , V_70 ) ;
return V_121 ;
}
return 0 ;
}
static void F_122 ( struct V_1 * V_1 )
__releases( V_1 -> V_51 )
__acquires( V_1 -> V_51 )
{
F_123 ( V_141 , & V_1 -> V_53 , V_119 ) ;
T_3 * V_142 ;
V_142 = F_124 ( & V_1 -> V_53 , V_119 ) ;
while ( V_1 -> V_53 & V_118 ) {
F_59 ( & V_1 -> V_51 ) ;
F_125 ( V_142 , & V_141 , V_143 ,
V_144 ) ;
F_44 ( & V_1 -> V_51 ) ;
}
}
void F_126 ( struct V_1 * V_1 )
{
F_44 ( & V_1 -> V_51 ) ;
F_122 ( V_1 ) ;
F_59 ( & V_1 -> V_51 ) ;
}
static void F_127 ( struct V_1 * V_1 )
__releases( V_1 -> V_51 )
{
F_128 ( V_145 ) ;
T_3 * V_142 = F_124 ( & V_1 -> V_53 , V_119 ) ;
int V_146 ;
F_129 ( V_142 , & V_145 , V_144 ) ;
V_146 = V_1 -> V_53 & V_118 ;
F_59 ( & V_1 -> V_51 ) ;
if ( V_146 )
F_130 () ;
F_131 ( V_142 , & V_145 ) ;
}
static void F_132 ( struct V_1 * V_1 , struct V_5 * V_6 ,
struct V_69 * V_70 )
{
if ( V_1 -> V_53 & V_54 )
return;
if ( ( V_1 -> V_53 & V_147 ) &&
( V_70 -> V_109 == V_148 || V_70 -> V_149 ) )
V_1 -> V_59 = V_117 ;
if ( V_70 -> V_150 ) {
F_99 ( V_1 , V_6 ) ;
return;
}
if ( F_133 ( V_1 -> V_43 , V_151 ) ) {
if ( V_70 -> V_152 <= 0 ) {
F_101 ( V_1 , V_6 ) ;
} else {
F_99 ( V_1 , V_6 ) ;
}
} else if ( V_1 -> V_53 & V_147 ) {
F_99 ( V_1 , V_6 ) ;
} else if ( V_1 -> V_53 & V_153 ) {
V_1 -> V_59 = V_117 ;
F_12 ( V_1 , V_6 , & V_6 -> V_16 ) ;
} else {
F_15 ( V_1 , V_6 ) ;
}
}
static int
F_134 ( struct V_1 * V_1 , struct V_69 * V_70 )
{
struct V_41 * V_42 = V_1 -> V_43 ;
long V_152 = V_70 -> V_152 ;
unsigned V_154 ;
int V_121 ;
F_135 ( ! ( V_1 -> V_53 & V_118 ) ) ;
F_136 ( V_1 , V_70 , V_152 ) ;
V_121 = F_137 ( V_42 , V_70 ) ;
if ( V_70 -> V_109 == V_148 && ! V_70 -> V_134 ) {
int V_155 = F_138 ( V_42 ) ;
if ( V_121 == 0 )
V_121 = V_155 ;
}
F_44 ( & V_1 -> V_51 ) ;
V_154 = V_1 -> V_53 & V_147 ;
if ( V_1 -> V_53 & V_153 ) {
if ( ( V_154 & ( V_156 | V_157 ) ) ||
F_37 ( V_1 -> V_53 & V_158 ) ||
F_37 ( F_107 ( V_117 ,
( V_1 -> V_159 +
V_135 * V_136 ) ) ) ) {
V_154 |= V_153 | V_158 ;
F_139 ( V_1 ) ;
}
} else
V_1 -> V_53 &= ~ V_158 ;
V_1 -> V_53 &= ~ V_154 ;
F_104 () ;
if ( F_133 ( V_42 , V_151 ) )
V_1 -> V_53 |= V_160 ;
F_59 ( & V_1 -> V_51 ) ;
if ( V_154 & V_153 )
F_140 ( V_1 ) ;
if ( V_154 & ~ V_160 ) {
int V_155 = F_118 ( V_1 , V_70 ) ;
if ( V_121 == 0 )
V_121 = V_155 ;
}
F_141 ( V_1 , V_70 , V_152 ) ;
return V_121 ;
}
static int
F_142 ( struct V_1 * V_1 , struct V_5 * V_6 ,
struct V_69 * V_70 )
{
int V_121 = 0 ;
F_44 ( & V_1 -> V_51 ) ;
if ( ! F_29 ( & V_1 -> V_161 ) )
F_135 ( ! ( V_1 -> V_53 & ( V_162 | V_54 ) ) ) ;
else
F_135 ( V_1 -> V_53 & V_162 ) ;
if ( V_1 -> V_53 & V_118 ) {
if ( V_70 -> V_109 != V_148 )
goto V_139;
F_122 ( V_1 ) ;
}
F_135 ( V_1 -> V_53 & V_118 ) ;
if ( ! ( V_1 -> V_53 & V_163 ) &&
( V_70 -> V_109 != V_148 ||
! F_133 ( V_1 -> V_43 , V_164 ) ) )
goto V_139;
V_1 -> V_53 |= V_118 ;
F_73 ( V_70 , V_1 ) ;
V_121 = F_134 ( V_1 , V_70 ) ;
F_75 ( V_70 ) ;
F_44 ( & V_6 -> V_15 ) ;
F_44 ( & V_1 -> V_51 ) ;
if ( ! ( V_1 -> V_53 & V_163 ) )
F_15 ( V_1 , V_6 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_102 ( V_1 ) ;
V_139:
F_59 ( & V_1 -> V_51 ) ;
return V_121 ;
}
static long F_143 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
long V_165 ;
if ( V_22 -> V_109 == V_148 || V_22 -> V_149 )
V_165 = V_99 ;
else {
V_165 = F_77 ( V_6 -> V_9 / 2 ,
V_166 . V_167 / V_168 ) ;
V_165 = F_77 ( V_165 , V_22 -> V_96 ) ;
V_165 = F_144 ( V_165 + V_169 ,
V_169 ) ;
}
return V_165 ;
}
static long F_145 ( struct V_129 * V_130 ,
struct V_5 * V_6 ,
struct V_21 * V_22 )
{
struct V_69 V_70 = {
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
struct V_1 * V_1 = F_1 ( V_6 -> V_13 . V_60 ) ;
if ( V_1 -> V_138 != V_130 ) {
if ( V_22 -> V_130 ) {
F_99 ( V_1 , V_6 ) ;
continue;
}
break;
}
F_44 ( & V_1 -> V_51 ) ;
if ( V_1 -> V_53 & ( V_178 | V_54 | V_162 ) ) {
F_59 ( & V_1 -> V_51 ) ;
F_99 ( V_1 , V_6 ) ;
continue;
}
if ( ( V_1 -> V_53 & V_118 ) && V_70 . V_109 != V_148 ) {
F_59 ( & V_1 -> V_51 ) ;
F_101 ( V_1 , V_6 ) ;
F_146 ( V_1 ) ;
continue;
}
F_59 ( & V_6 -> V_15 ) ;
if ( V_1 -> V_53 & V_118 ) {
F_127 ( V_1 ) ;
F_44 ( & V_6 -> V_15 ) ;
continue;
}
V_1 -> V_53 |= V_118 ;
F_73 ( & V_70 , V_1 ) ;
V_176 = F_143 ( V_6 , V_22 ) ;
V_70 . V_152 = V_176 ;
V_70 . V_150 = 0 ;
F_134 ( V_1 , & V_70 ) ;
F_75 ( & V_70 ) ;
V_22 -> V_96 -= V_176 - V_70 . V_152 ;
V_177 += V_176 - V_70 . V_152 ;
if ( F_147 () ) {
F_148 ( V_35 ) ;
F_149 () ;
}
F_44 ( & V_6 -> V_15 ) ;
F_44 ( & V_1 -> V_51 ) ;
if ( ! ( V_1 -> V_53 & V_163 ) )
V_177 ++ ;
F_132 ( V_1 , V_6 , & V_70 ) ;
F_102 ( V_1 ) ;
F_59 ( & V_1 -> V_51 ) ;
if ( V_177 ) {
if ( F_150 ( V_175 + V_136 / 10UL ) )
break;
if ( V_22 -> V_96 <= 0 )
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
struct V_1 * V_1 = F_1 ( V_6 -> V_13 . V_60 ) ;
struct V_129 * V_130 = V_1 -> V_138 ;
if ( ! F_152 ( V_130 ) ) {
F_99 ( V_1 , V_6 ) ;
continue;
}
V_177 += F_145 ( V_130 , V_6 , V_22 ) ;
F_153 ( & V_130 -> V_179 ) ;
if ( V_177 ) {
if ( F_150 ( V_175 + V_136 / 10UL ) )
break;
if ( V_22 -> V_96 <= 0 )
break;
}
}
return V_177 ;
}
static long F_154 ( struct V_5 * V_6 , long V_96 ,
enum V_113 V_114 )
{
struct V_21 V_22 = {
. V_96 = V_96 ,
. V_109 = V_110 ,
. V_112 = 1 ,
. V_114 = V_114 ,
} ;
struct V_180 V_181 ;
F_155 ( & V_181 ) ;
F_44 ( & V_6 -> V_15 ) ;
if ( F_9 ( & V_6 -> V_13 ) )
F_115 ( V_6 , & V_22 ) ;
F_151 ( V_6 , & V_22 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_156 ( & V_181 ) ;
return V_96 - V_22 . V_96 ;
}
static long F_157 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
unsigned long V_182 = V_117 ;
long V_96 = V_22 -> V_96 ;
unsigned long V_183 ;
struct V_1 * V_1 ;
long V_184 ;
struct V_180 V_181 ;
V_183 = V_117 ;
V_22 -> V_125 = & V_183 ;
F_155 ( & V_181 ) ;
F_44 ( & V_6 -> V_15 ) ;
for (; ; ) {
if ( V_22 -> V_96 <= 0 )
break;
if ( ( V_22 -> V_171 || V_22 -> V_170 ) &&
! F_9 ( & V_6 -> V_27 ) )
break;
if ( V_22 -> V_171 && ! F_158 ( V_6 ) )
break;
if ( V_22 -> V_170 ) {
V_183 = V_117 -
F_159 ( V_185 * 10 ) ;
} else if ( V_22 -> V_171 )
V_183 = V_117 ;
F_160 ( V_6 , V_22 ) ;
if ( F_9 ( & V_6 -> V_13 ) )
F_115 ( V_6 , V_22 ) ;
if ( V_22 -> V_130 )
V_184 = F_145 ( V_22 -> V_130 , V_6 , V_22 ) ;
else
V_184 = F_151 ( V_6 , V_22 ) ;
F_161 ( V_6 , V_22 ) ;
F_162 ( V_6 , V_182 ) ;
if ( V_184 )
continue;
if ( F_9 ( & V_6 -> V_14 ) )
break;
if ( ! F_9 ( & V_6 -> V_14 ) ) {
F_163 ( V_6 , V_22 ) ;
V_1 = F_1 ( V_6 -> V_14 . V_60 ) ;
F_44 ( & V_1 -> V_51 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_127 ( V_1 ) ;
F_44 ( & V_6 -> V_15 ) ;
}
}
F_59 ( & V_6 -> V_15 ) ;
F_156 ( & V_181 ) ;
return V_96 - V_22 -> V_96 ;
}
static struct V_21 * F_164 ( struct V_5 * V_6 )
{
struct V_21 * V_22 = NULL ;
F_18 ( & V_6 -> V_17 ) ;
if ( ! F_9 ( & V_6 -> V_27 ) ) {
V_22 = F_2 ( V_6 -> V_27 . V_116 ,
struct V_21 , V_26 ) ;
F_16 ( & V_22 -> V_26 ) ;
}
F_21 ( & V_6 -> V_17 ) ;
return V_22 ;
}
static unsigned long F_165 ( void )
{
return F_166 ( V_186 ) +
F_166 ( V_187 ) +
F_167 () ;
}
static long F_168 ( struct V_5 * V_6 )
{
if ( F_158 ( V_6 ) ) {
struct V_21 V_22 = {
. V_96 = V_99 ,
. V_109 = V_110 ,
. V_171 = 1 ,
. V_112 = 1 ,
. V_114 = V_188 ,
} ;
return F_157 ( V_6 , & V_22 ) ;
}
return 0 ;
}
static long F_169 ( struct V_5 * V_6 )
{
unsigned long V_189 ;
long V_96 ;
if ( ! V_190 )
return 0 ;
V_189 = V_6 -> V_191 +
F_159 ( V_190 * 10 ) ;
if ( F_100 ( V_117 , V_189 ) )
return 0 ;
V_6 -> V_191 = V_117 ;
V_96 = F_165 () ;
if ( V_96 ) {
struct V_21 V_22 = {
. V_96 = V_96 ,
. V_109 = V_110 ,
. V_170 = 1 ,
. V_112 = 1 ,
. V_114 = V_192 ,
} ;
return F_157 ( V_6 , & V_22 ) ;
}
return 0 ;
}
static long F_170 ( struct V_5 * V_6 )
{
struct V_21 * V_22 ;
long V_177 = 0 ;
F_5 ( V_193 , & V_6 -> V_8 ) ;
while ( ( V_22 = F_164 ( V_6 ) ) != NULL ) {
struct V_29 * V_24 = V_22 -> V_24 ;
F_171 ( V_6 , V_22 ) ;
V_177 += F_157 ( V_6 , V_22 ) ;
if ( V_22 -> V_111 )
F_61 ( V_22 ) ;
if ( V_24 && F_172 ( & V_24 -> V_25 ) )
F_173 ( & V_6 -> V_10 -> V_30 ) ;
}
V_177 += F_169 ( V_6 ) ;
V_177 += F_168 ( V_6 ) ;
F_10 ( V_193 , & V_6 -> V_8 ) ;
return V_177 ;
}
void F_174 ( struct V_38 * V_22 )
{
struct V_5 * V_6 = F_43 ( F_175 ( V_22 ) ,
struct V_5 , V_20 ) ;
long V_194 ;
F_176 ( L_1 , F_177 ( V_6 -> V_10 -> V_195 ) ) ;
V_35 -> V_124 |= V_196 ;
if ( F_49 ( ! F_178 () ||
! F_19 ( V_18 , & V_6 -> V_8 ) ) ) {
do {
V_194 = F_170 ( V_6 ) ;
F_179 ( V_194 ) ;
} while ( ! F_9 ( & V_6 -> V_27 ) );
} else {
V_194 = F_154 ( V_6 , 1024 ,
V_197 ) ;
F_179 ( V_194 ) ;
}
if ( ! F_9 ( & V_6 -> V_27 ) )
F_20 ( V_19 , & V_6 -> V_20 , 0 ) ;
else if ( F_4 ( V_6 ) && V_190 )
F_180 ( V_6 ) ;
V_35 -> V_124 &= ~ V_196 ;
}
void F_181 ( long V_96 , enum V_113 V_114 )
{
struct V_28 * V_10 ;
if ( ! V_96 )
V_96 = F_165 () ;
F_67 () ;
F_182 (bdi, &bdi_list, bdi_list) {
struct V_5 * V_6 ;
if ( ! F_183 ( V_10 ) )
continue;
F_182 (wb, &bdi->wb_list, bdi_node)
F_94 ( V_6 , F_85 ( V_6 , V_96 ) ,
false , V_114 ) ;
}
F_69 () ;
}
static void F_184 ( struct V_38 * V_198 )
{
struct V_28 * V_10 ;
F_67 () ;
F_182 (bdi, &bdi_list, bdi_list) {
struct V_5 * V_6 ;
F_182 (wb, &bdi->wb_list, bdi_node)
if ( ! F_9 ( & V_6 -> V_16 ) )
F_17 ( V_6 ) ;
}
F_69 () ;
F_185 ( & V_199 , V_135 * V_136 ) ;
}
static int T_4 F_186 ( void )
{
F_185 ( & V_199 , V_135 * V_136 ) ;
return 0 ;
}
int F_187 ( struct V_200 * V_201 , int V_202 ,
void T_5 * V_203 , T_2 * V_204 , T_6 * V_205 )
{
int V_121 ;
V_121 = F_188 ( V_201 , V_202 , V_203 , V_204 , V_205 ) ;
if ( V_121 == 0 && V_202 )
F_20 ( V_206 , & V_199 , 0 ) ;
return V_121 ;
}
static T_7 void F_189 ( struct V_1 * V_1 )
{
if ( V_1 -> V_207 || strcmp ( V_1 -> V_138 -> V_208 , L_2 ) ) {
struct V_209 * V_209 ;
const char * V_210 = L_3 ;
V_209 = F_190 ( V_1 ) ;
if ( V_209 ) {
F_44 ( & V_209 -> V_211 ) ;
V_210 = ( const char * ) V_209 -> V_212 . V_210 ;
}
F_191 ( V_213
L_4 ,
V_35 -> V_214 , F_192 ( V_35 ) , V_1 -> V_207 ,
V_210 , V_1 -> V_138 -> V_208 ) ;
if ( V_209 ) {
F_59 ( & V_209 -> V_211 ) ;
F_193 ( V_209 ) ;
}
}
}
void F_194 ( struct V_1 * V_1 , int V_124 )
{
#define F_195 (I_DIRTY_SYNC | I_DIRTY_DATASYNC)
struct V_129 * V_130 = V_1 -> V_138 ;
int V_215 ;
F_196 ( V_1 , V_124 ) ;
if ( V_124 & ( V_156 | V_157 | V_153 ) ) {
F_197 ( V_1 , V_124 ) ;
if ( V_130 -> V_140 -> V_216 )
V_130 -> V_140 -> V_216 ( V_1 , V_124 ) ;
F_198 ( V_1 , V_124 ) ;
}
if ( V_124 & F_195 )
V_124 &= ~ V_153 ;
V_215 = V_124 & V_153 ;
F_104 () ;
if ( ( ( V_1 -> V_53 & V_124 ) == V_124 ) ||
( V_215 && ( V_1 -> V_53 & F_195 ) ) )
return;
if ( F_37 ( V_217 ) )
F_189 ( V_1 ) ;
F_44 ( & V_1 -> V_51 ) ;
if ( V_215 && ( V_1 -> V_53 & F_195 ) )
goto V_218;
if ( ( V_1 -> V_53 & V_124 ) != V_124 ) {
const int V_219 = V_1 -> V_53 & V_147 ;
F_199 ( V_1 , NULL ) ;
if ( V_124 & F_195 )
V_1 -> V_53 &= ~ V_153 ;
V_1 -> V_53 |= V_124 ;
if ( V_1 -> V_53 & V_118 )
goto V_218;
if ( ! F_200 ( V_1 -> V_220 ) ) {
if ( F_201 ( V_1 ) )
goto V_218;
}
if ( V_1 -> V_53 & V_54 )
goto V_218;
if ( ! V_219 ) {
struct V_5 * V_6 ;
struct V_2 * V_221 ;
bool V_222 = false ;
V_6 = F_40 ( V_1 ) ;
F_202 ( F_203 ( V_6 -> V_10 ) &&
! F_19 ( V_18 , & V_6 -> V_8 ) ,
L_5 , V_6 -> V_10 -> V_210 ) ;
V_1 -> V_59 = V_117 ;
if ( V_215 )
V_1 -> V_159 = V_117 ;
if ( V_1 -> V_53 & ( F_195 | V_160 ) )
V_221 = & V_6 -> V_12 ;
else
V_221 = & V_6 -> V_16 ;
V_222 = F_12 ( V_1 , V_6 ,
V_221 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_204 ( V_1 ) ;
if ( F_203 ( V_6 -> V_10 ) && V_222 )
F_180 ( V_6 ) ;
return;
}
}
V_218:
F_59 ( & V_1 -> V_51 ) ;
#undef F_195
}
static void F_205 ( struct V_129 * V_130 )
{
struct V_1 * V_1 , * V_223 = NULL ;
F_135 ( ! F_206 ( & V_130 -> V_179 ) ) ;
F_207 ( & V_130 -> V_224 ) ;
F_44 ( & V_130 -> V_225 ) ;
F_55 (inode, &sb->s_inodes, i_sb_list) {
struct V_41 * V_42 = V_1 -> V_43 ;
F_44 ( & V_1 -> V_51 ) ;
if ( ( V_1 -> V_53 & ( V_54 | V_162 | V_178 ) ) ||
( V_42 -> V_226 == 0 ) ) {
F_59 ( & V_1 -> V_51 ) ;
continue;
}
F_208 ( V_1 ) ;
F_59 ( & V_1 -> V_51 ) ;
F_59 ( & V_130 -> V_225 ) ;
F_60 ( V_223 ) ;
V_223 = V_1 ;
F_209 ( V_42 ) ;
F_149 () ;
F_44 ( & V_130 -> V_225 ) ;
}
F_59 ( & V_130 -> V_225 ) ;
F_60 ( V_223 ) ;
F_210 ( & V_130 -> V_224 ) ;
}
static void F_211 ( struct V_129 * V_130 , unsigned long V_227 ,
enum V_113 V_114 , bool V_102 )
{
F_91 ( V_24 ) ;
struct V_21 V_22 = {
. V_130 = V_130 ,
. V_109 = V_110 ,
. V_149 = 1 ,
. V_24 = & V_24 ,
. V_96 = V_227 ,
. V_114 = V_114 ,
} ;
struct V_28 * V_10 = V_130 -> V_228 ;
if ( ! F_183 ( V_10 ) || V_10 == & V_229 )
return;
F_135 ( ! F_206 ( & V_130 -> V_179 ) ) ;
F_88 ( V_130 -> V_228 , & V_22 , V_102 ) ;
F_26 ( V_10 , & V_24 ) ;
}
void F_212 ( struct V_129 * V_130 ,
unsigned long V_227 ,
enum V_113 V_114 )
{
F_211 ( V_130 , V_227 , V_114 , false ) ;
}
void F_213 ( struct V_129 * V_130 , enum V_113 V_114 )
{
return F_212 ( V_130 , F_165 () , V_114 ) ;
}
bool F_214 ( struct V_129 * V_130 , unsigned long V_227 ,
enum V_113 V_114 )
{
if ( ! F_215 ( & V_130 -> V_179 ) )
return false ;
F_211 ( V_130 , V_227 , V_114 , true ) ;
F_153 ( & V_130 -> V_179 ) ;
return true ;
}
bool F_216 ( struct V_129 * V_130 , enum V_113 V_114 )
{
return F_214 ( V_130 , F_165 () , V_114 ) ;
}
void F_217 ( struct V_129 * V_130 )
{
F_91 ( V_24 ) ;
struct V_21 V_22 = {
. V_130 = V_130 ,
. V_109 = V_148 ,
. V_96 = V_99 ,
. V_112 = 0 ,
. V_24 = & V_24 ,
. V_114 = V_230 ,
. V_134 = 1 ,
} ;
struct V_28 * V_10 = V_130 -> V_228 ;
if ( V_10 == & V_229 )
return;
F_135 ( ! F_206 ( & V_130 -> V_179 ) ) ;
F_88 ( V_10 , & V_22 , false ) ;
F_26 ( V_10 , & V_24 ) ;
F_205 ( V_130 ) ;
}
int F_218 ( struct V_1 * V_1 , int V_231 )
{
struct V_5 * V_6 = & F_31 ( V_1 ) -> V_6 ;
struct V_69 V_70 = {
. V_152 = V_99 ,
. V_109 = V_231 ? V_148 : V_110 ,
. V_172 = 0 ,
. V_173 = V_174 ,
} ;
if ( ! F_219 ( V_1 -> V_43 ) )
V_70 . V_152 = 0 ;
F_89 () ;
return F_142 ( V_1 , V_6 , & V_70 ) ;
}
int F_220 ( struct V_1 * V_1 , struct V_69 * V_70 )
{
return F_142 ( V_1 , & F_31 ( V_1 ) -> V_6 , V_70 ) ;
}
int F_221 ( struct V_1 * V_1 , int V_145 )
{
struct V_69 V_70 = {
. V_109 = V_145 ? V_148 : V_110 ,
. V_152 = 0 ,
} ;
return F_220 ( V_1 , & V_70 ) ;
}
