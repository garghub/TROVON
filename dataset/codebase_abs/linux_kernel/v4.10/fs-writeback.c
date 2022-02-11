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
F_27 ( & V_65 ) ;
}
static void F_62 ( struct V_66 * V_66 )
{
struct V_39 * V_40 = F_43 ( V_66 ,
struct V_39 , V_66 ) ;
F_63 ( & V_40 -> V_22 , F_42 ) ;
F_64 ( V_67 , & V_40 -> V_22 ) ;
}
static void F_65 ( struct V_1 * V_1 , int V_68 )
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
V_33 = F_68 ( V_68 , & V_69 ) ;
if ( V_33 )
V_40 -> V_45 = F_34 ( V_10 , V_33 , V_34 ) ;
F_69 () ;
if ( ! V_40 -> V_45 )
goto V_70;
F_44 ( & V_1 -> V_51 ) ;
if ( ! ( V_1 -> V_71 -> V_72 & V_73 ) ||
V_1 -> V_53 & ( V_64 | V_54 ) ||
F_70 ( V_1 ) == V_40 -> V_45 ) {
F_59 ( & V_1 -> V_51 ) ;
goto V_70;
}
V_1 -> V_53 |= V_64 ;
F_71 ( V_1 ) ;
F_59 ( & V_1 -> V_51 ) ;
V_40 -> V_1 = V_1 ;
F_24 ( & V_65 ) ;
F_72 ( & V_40 -> V_66 , F_62 ) ;
return;
V_70:
if ( V_40 -> V_45 )
F_39 ( V_40 -> V_45 ) ;
F_61 ( V_40 ) ;
}
void F_73 ( struct V_74 * V_75 ,
struct V_1 * V_1 )
{
if ( ! F_32 ( V_1 ) ) {
F_59 ( & V_1 -> V_51 ) ;
return;
}
V_75 -> V_6 = F_70 ( V_1 ) ;
V_75 -> V_1 = V_1 ;
V_75 -> V_76 = V_75 -> V_6 -> V_33 -> V_77 ;
V_75 -> V_78 = V_1 -> V_61 ;
V_75 -> V_79 = 0 ;
V_75 -> V_80 = 0 ;
V_75 -> V_81 = 0 ;
V_75 -> V_82 = 0 ;
F_54 ( V_75 -> V_6 ) ;
F_59 ( & V_1 -> V_51 ) ;
if ( F_37 ( F_74 ( V_75 -> V_6 ) ) )
F_65 ( V_1 , V_75 -> V_76 ) ;
}
void F_75 ( struct V_74 * V_75 )
{
struct V_5 * V_6 = V_75 -> V_6 ;
struct V_1 * V_1 = V_75 -> V_1 ;
unsigned long V_83 , V_84 , V_85 ;
T_1 V_86 ;
int V_87 ;
if ( ! V_6 )
return;
V_86 = V_1 -> V_63 ;
V_83 = V_1 -> V_62 ;
if ( V_75 -> V_80 >= V_75 -> V_81 &&
V_75 -> V_80 >= V_75 -> V_82 ) {
V_87 = V_75 -> V_76 ;
V_84 = V_75 -> V_80 ;
} else if ( V_75 -> V_81 >= V_75 -> V_82 ) {
V_87 = V_75 -> V_78 ;
V_84 = V_75 -> V_81 ;
} else {
V_87 = V_75 -> V_79 ;
V_84 = V_75 -> V_82 ;
}
V_85 = F_76 ( ( V_84 >> V_88 ) << V_89 ,
V_6 -> V_9 ) ;
if ( V_83 )
V_83 += ( V_85 >> V_90 ) -
( V_83 >> V_90 ) ;
else
V_83 = V_85 ;
if ( V_85 >= V_83 / V_91 ) {
int V_92 ;
V_92 = F_77 ( F_76 ( V_85 , V_93 ) ,
( unsigned long ) V_94 ) ;
V_86 <<= V_92 ;
if ( V_75 -> V_76 != V_87 )
V_86 |= ( 1U << V_92 ) - 1 ;
if ( F_78 ( V_86 ) > V_95 )
F_65 ( V_1 , V_87 ) ;
}
V_1 -> V_61 = V_87 ;
V_1 -> V_62 = F_77 ( V_83 , ( unsigned long ) V_96 ) ;
V_1 -> V_63 = V_86 ;
F_39 ( V_75 -> V_6 ) ;
V_75 -> V_6 = NULL ;
}
void F_79 ( struct V_74 * V_75 , struct V_31 * V_31 ,
T_2 V_97 )
{
int V_77 ;
if ( ! V_75 -> V_6 )
return;
V_77 = F_33 ( V_31 ) -> V_77 ;
if ( V_77 == V_75 -> V_76 ) {
V_75 -> V_80 += V_97 ;
return;
}
if ( V_77 == V_75 -> V_78 )
V_75 -> V_81 += V_97 ;
if ( ! V_75 -> V_82 )
V_75 -> V_79 = V_77 ;
if ( V_77 == V_75 -> V_79 )
V_75 -> V_82 += V_97 ;
else
V_75 -> V_82 -= F_77 ( V_97 , V_75 -> V_82 ) ;
}
int F_80 ( struct V_1 * V_1 , int V_98 )
{
if ( V_1 && F_81 ( V_1 ) ) {
struct V_5 * V_6 ;
bool V_99 , V_100 ;
V_6 = F_82 ( V_1 , & V_99 ) ;
V_100 = F_83 ( V_6 , V_98 ) ;
F_84 ( V_1 , V_99 ) ;
return V_100 ;
}
return F_83 ( & F_31 ( V_1 ) -> V_6 , V_98 ) ;
}
static long F_85 ( struct V_5 * V_6 , long V_101 )
{
unsigned long V_102 = V_6 -> V_9 ;
unsigned long V_103 = F_86 ( & V_6 -> V_10 -> V_11 ) ;
if ( V_101 == V_104 )
return V_104 ;
if ( ! V_103 || V_102 >= V_103 )
return V_101 ;
else
return F_87 ( ( V_105 ) V_101 * V_102 , V_103 ) ;
}
static void F_88 ( struct V_28 * V_10 ,
struct V_21 * V_106 ,
bool V_107 )
{
struct V_5 * V_108 = NULL ;
struct V_5 * V_6 = F_2 ( & V_10 -> V_109 ,
struct V_5 , V_110 ) ;
F_89 () ;
V_111:
F_67 () ;
F_90 (wb, &bdi->wb_list, bdi_node) {
F_91 ( V_112 ) ;
struct V_21 V_113 ;
struct V_21 * V_22 ;
long V_101 ;
if ( V_108 ) {
F_39 ( V_108 ) ;
V_108 = NULL ;
}
if ( ! F_4 ( V_6 ) &&
( V_106 -> V_114 == V_115 ||
F_9 ( & V_6 -> V_16 ) ) )
continue;
if ( V_107 && F_92 ( V_6 ) )
continue;
V_101 = F_85 ( V_6 , V_106 -> V_101 ) ;
V_22 = F_93 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 ) {
* V_22 = * V_106 ;
V_22 -> V_101 = V_101 ;
V_22 -> V_116 = 1 ;
F_22 ( V_6 , V_22 ) ;
continue;
}
V_22 = & V_113 ;
* V_22 = * V_106 ;
V_22 -> V_101 = V_101 ;
V_22 -> V_116 = 0 ;
V_22 -> V_24 = & V_112 ;
F_22 ( V_6 , V_22 ) ;
F_54 ( V_6 ) ;
V_108 = V_6 ;
F_69 () ;
F_26 ( V_10 , & V_112 ) ;
goto V_111;
}
F_69 () ;
if ( V_108 )
F_39 ( V_108 ) ;
}
void F_94 ( void )
{
if ( F_29 ( & V_65 ) ) {
F_95 () ;
F_96 ( V_67 ) ;
}
}
static int T_3 F_97 ( void )
{
V_67 = F_98 ( L_1 , 0 , 0 ) ;
if ( ! V_67 )
return - V_117 ;
return 0 ;
}
static struct V_5 *
F_40 ( struct V_1 * V_1 )
__releases( &inode->i_lock
static struct V_5 * F_41 ( struct V_1 * V_1 )
__acquires( &wb->list_lock
static long F_85 ( struct V_5 * V_6 , long V_101 )
{
return V_101 ;
}
static void F_88 ( struct V_28 * V_10 ,
struct V_21 * V_106 ,
bool V_107 )
{
F_89 () ;
if ( ! V_107 || ! F_92 ( & V_10 -> V_6 ) ) {
V_106 -> V_116 = 0 ;
F_22 ( & V_10 -> V_6 , V_106 ) ;
}
}
void F_99 ( struct V_5 * V_6 , long V_101 ,
bool V_118 , enum V_119 V_120 )
{
struct V_21 * V_22 ;
if ( ! F_4 ( V_6 ) )
return;
V_22 = F_66 ( sizeof( * V_22 ) ,
V_121 | V_122 | V_123 ) ;
if ( ! V_22 ) {
F_100 ( V_6 ) ;
F_17 ( V_6 ) ;
return;
}
V_22 -> V_114 = V_115 ;
V_22 -> V_101 = V_101 ;
V_22 -> V_118 = V_118 ;
V_22 -> V_120 = V_120 ;
V_22 -> V_116 = 1 ;
F_22 ( V_6 , V_22 ) ;
}
void F_101 ( struct V_5 * V_6 )
{
F_102 ( V_6 ) ;
F_17 ( V_6 ) ;
}
void F_103 ( struct V_1 * V_1 )
{
struct V_5 * V_6 ;
V_6 = F_41 ( V_1 ) ;
F_15 ( V_1 , V_6 ) ;
F_59 ( & V_6 -> V_15 ) ;
}
void F_104 ( struct V_1 * V_1 )
{
struct V_124 * V_125 = V_1 -> V_71 ;
unsigned long V_126 ;
if ( F_9 ( & V_1 -> V_127 ) ) {
F_105 ( & V_125 -> V_128 , V_126 ) ;
if ( F_9 ( & V_1 -> V_127 ) ) {
F_25 ( & V_1 -> V_127 , & V_125 -> V_129 ) ;
F_106 ( V_1 ) ;
}
F_107 ( & V_125 -> V_128 , V_126 ) ;
}
}
void F_108 ( struct V_1 * V_1 )
{
struct V_124 * V_125 = V_1 -> V_71 ;
unsigned long V_126 ;
if ( ! F_9 ( & V_1 -> V_127 ) ) {
F_105 ( & V_125 -> V_128 , V_126 ) ;
if ( ! F_9 ( & V_1 -> V_127 ) ) {
F_16 ( & V_1 -> V_127 ) ;
F_109 ( V_1 ) ;
}
F_107 ( & V_125 -> V_128 , V_126 ) ;
}
}
static void F_110 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
if ( ! F_9 ( & V_6 -> V_12 ) ) {
struct V_1 * V_130 ;
V_130 = F_1 ( V_6 -> V_12 . V_131 ) ;
if ( F_111 ( V_1 -> V_59 , V_130 -> V_59 ) )
V_1 -> V_59 = V_132 ;
}
F_12 ( V_1 , V_6 , & V_6 -> V_12 ) ;
}
static void F_112 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
F_12 ( V_1 , V_6 , & V_6 -> V_14 ) ;
}
static void F_113 ( struct V_1 * V_1 )
{
V_1 -> V_53 &= ~ V_133 ;
F_114 ( V_1 ) ;
F_115 () ;
F_116 ( & V_1 -> V_53 , V_134 ) ;
}
static bool F_117 ( struct V_1 * V_1 , unsigned long V_135 )
{
bool V_136 = F_118 ( V_1 -> V_59 , V_135 ) ;
#ifndef F_119
V_136 = V_136 && F_120 ( V_1 -> V_59 , V_132 ) ;
#endif
return V_136 ;
}
static int F_121 ( struct V_2 * V_137 ,
struct V_2 * V_138 ,
int V_126 ,
struct V_21 * V_22 )
{
unsigned long * V_139 = NULL ;
unsigned long V_140 ;
F_122 ( V_141 ) ;
struct V_2 * V_58 , * V_142 ;
struct V_124 * V_125 = NULL ;
struct V_1 * V_1 ;
int V_143 = 0 ;
int V_144 = 0 ;
if ( ( V_126 & V_145 ) == 0 )
V_139 = V_22 -> V_139 ;
else if ( ! V_22 -> V_146 ) {
V_140 = V_132 - ( V_147 * V_148 ) ;
V_139 = & V_140 ;
}
while ( ! F_9 ( V_137 ) ) {
V_1 = F_1 ( V_137 -> V_60 ) ;
if ( V_139 &&
F_117 ( V_1 , * V_139 ) )
break;
F_14 ( & V_1 -> V_4 , & V_141 ) ;
V_144 ++ ;
if ( V_126 & V_145 )
F_5 ( V_149 , & V_1 -> V_53 ) ;
if ( F_123 ( V_1 -> V_71 ) )
continue;
if ( V_125 && V_125 != V_1 -> V_71 )
V_143 = 1 ;
V_125 = V_1 -> V_71 ;
}
if ( ! V_143 ) {
F_124 ( & V_141 , V_138 ) ;
goto V_150;
}
while ( ! F_9 ( & V_141 ) ) {
V_125 = F_1 ( V_141 . V_60 ) -> V_71 ;
F_125 (pos, node, &tmp) {
V_1 = F_1 ( V_58 ) ;
if ( V_1 -> V_71 == V_125 )
F_14 ( & V_1 -> V_4 , V_138 ) ;
}
}
V_150:
return V_144 ;
}
static void F_126 ( struct V_5 * V_6 , struct V_21 * V_22 )
{
int V_144 ;
F_13 ( & V_6 -> V_15 ) ;
F_127 ( & V_6 -> V_14 , & V_6 -> V_13 ) ;
V_144 = F_121 ( & V_6 -> V_12 , & V_6 -> V_13 , 0 , V_22 ) ;
V_144 += F_121 ( & V_6 -> V_16 , & V_6 -> V_13 ,
V_145 , V_22 ) ;
if ( V_144 )
F_3 ( V_6 ) ;
F_128 ( V_6 , V_22 , V_144 ) ;
}
static int F_129 ( struct V_1 * V_1 , struct V_74 * V_75 )
{
int V_136 ;
if ( V_1 -> V_71 -> V_151 -> F_129 && ! F_130 ( V_1 ) ) {
F_131 ( V_1 , V_75 ) ;
V_136 = V_1 -> V_71 -> V_151 -> F_129 ( V_1 , V_75 ) ;
F_132 ( V_1 , V_75 ) ;
return V_136 ;
}
return 0 ;
}
static void F_133 ( struct V_1 * V_1 )
__releases( V_1 -> V_51 )
__acquires( V_1 -> V_51 )
{
F_134 ( V_152 , & V_1 -> V_53 , V_134 ) ;
T_4 * V_153 ;
V_153 = F_135 ( & V_1 -> V_53 , V_134 ) ;
while ( V_1 -> V_53 & V_133 ) {
F_59 ( & V_1 -> V_51 ) ;
F_136 ( V_153 , & V_152 , V_154 ,
V_155 ) ;
F_44 ( & V_1 -> V_51 ) ;
}
}
void F_137 ( struct V_1 * V_1 )
{
F_44 ( & V_1 -> V_51 ) ;
F_133 ( V_1 ) ;
F_59 ( & V_1 -> V_51 ) ;
}
static void F_138 ( struct V_1 * V_1 )
__releases( V_1 -> V_51 )
{
F_139 ( V_156 ) ;
T_4 * V_153 = F_135 ( & V_1 -> V_53 , V_134 ) ;
int V_157 ;
F_140 ( V_153 , & V_156 , V_155 ) ;
V_157 = V_1 -> V_53 & V_133 ;
F_59 ( & V_1 -> V_51 ) ;
if ( V_157 )
F_141 () ;
F_142 ( V_153 , & V_156 ) ;
}
static void F_143 ( struct V_1 * V_1 , struct V_5 * V_6 ,
struct V_74 * V_75 )
{
if ( V_1 -> V_53 & V_54 )
return;
if ( ( V_1 -> V_53 & V_158 ) &&
( V_75 -> V_114 == V_159 || V_75 -> V_160 ) )
V_1 -> V_59 = V_132 ;
if ( V_75 -> V_161 ) {
F_110 ( V_1 , V_6 ) ;
return;
}
if ( F_144 ( V_1 -> V_43 , V_162 ) ) {
if ( V_75 -> V_163 <= 0 ) {
F_112 ( V_1 , V_6 ) ;
} else {
F_110 ( V_1 , V_6 ) ;
}
} else if ( V_1 -> V_53 & V_158 ) {
F_110 ( V_1 , V_6 ) ;
} else if ( V_1 -> V_53 & V_164 ) {
V_1 -> V_59 = V_132 ;
F_12 ( V_1 , V_6 , & V_6 -> V_16 ) ;
} else {
F_15 ( V_1 , V_6 ) ;
}
}
static int
F_145 ( struct V_1 * V_1 , struct V_74 * V_75 )
{
struct V_41 * V_42 = V_1 -> V_43 ;
long V_163 = V_75 -> V_163 ;
unsigned V_165 ;
int V_136 ;
F_146 ( ! ( V_1 -> V_53 & V_133 ) ) ;
F_147 ( V_1 , V_75 , V_163 ) ;
V_136 = F_148 ( V_42 , V_75 ) ;
if ( V_75 -> V_114 == V_159 && ! V_75 -> V_146 ) {
int V_166 = F_149 ( V_42 ) ;
if ( V_136 == 0 )
V_136 = V_166 ;
}
F_44 ( & V_1 -> V_51 ) ;
V_165 = V_1 -> V_53 & V_158 ;
if ( V_1 -> V_53 & V_164 ) {
if ( ( V_165 & ( V_167 | V_168 ) ) ||
V_75 -> V_114 == V_159 ||
F_37 ( V_1 -> V_53 & V_169 ) ||
F_37 ( F_118 ( V_132 ,
( V_1 -> V_170 +
V_147 * V_148 ) ) ) ) {
V_165 |= V_164 | V_169 ;
F_150 ( V_1 ) ;
}
} else
V_1 -> V_53 &= ~ V_169 ;
V_1 -> V_53 &= ~ V_165 ;
F_115 () ;
if ( F_144 ( V_42 , V_162 ) )
V_1 -> V_53 |= V_171 ;
F_59 ( & V_1 -> V_51 ) ;
if ( V_165 & V_164 )
F_151 ( V_1 ) ;
if ( V_165 & ~ V_171 ) {
int V_166 = F_129 ( V_1 , V_75 ) ;
if ( V_136 == 0 )
V_136 = V_166 ;
}
F_152 ( V_1 , V_75 , V_163 ) ;
return V_136 ;
}
static int F_153 ( struct V_1 * V_1 ,
struct V_74 * V_75 )
{
struct V_5 * V_6 ;
int V_136 = 0 ;
F_44 ( & V_1 -> V_51 ) ;
if ( ! F_29 ( & V_1 -> V_172 ) )
F_146 ( ! ( V_1 -> V_53 & ( V_173 | V_54 ) ) ) ;
else
F_146 ( V_1 -> V_53 & V_173 ) ;
if ( V_1 -> V_53 & V_133 ) {
if ( V_75 -> V_114 != V_159 )
goto V_150;
F_133 ( V_1 ) ;
}
F_146 ( V_1 -> V_53 & V_133 ) ;
if ( ! ( V_1 -> V_53 & V_174 ) &&
( V_75 -> V_114 != V_159 ||
! F_144 ( V_1 -> V_43 , V_175 ) ) )
goto V_150;
V_1 -> V_53 |= V_133 ;
F_73 ( V_75 , V_1 ) ;
V_136 = F_145 ( V_1 , V_75 ) ;
F_75 ( V_75 ) ;
V_6 = F_41 ( V_1 ) ;
F_44 ( & V_1 -> V_51 ) ;
if ( ! ( V_1 -> V_53 & V_174 ) )
F_15 ( V_1 , V_6 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_113 ( V_1 ) ;
V_150:
F_59 ( & V_1 -> V_51 ) ;
return V_136 ;
}
static long F_154 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
long V_176 ;
if ( V_22 -> V_114 == V_159 || V_22 -> V_160 )
V_176 = V_104 ;
else {
V_176 = F_77 ( V_6 -> V_9 / 2 ,
V_177 . V_178 / V_179 ) ;
V_176 = F_77 ( V_176 , V_22 -> V_101 ) ;
V_176 = F_155 ( V_176 + V_180 ,
V_180 ) ;
}
return V_176 ;
}
static long F_156 ( struct V_124 * V_125 ,
struct V_5 * V_6 ,
struct V_21 * V_22 )
{
struct V_74 V_75 = {
. V_114 = V_22 -> V_114 ,
. V_160 = V_22 -> V_160 ,
. V_181 = V_22 -> V_181 ,
. V_182 = V_22 -> V_182 ,
. V_146 = V_22 -> V_146 ,
. V_118 = V_22 -> V_118 ,
. V_183 = 0 ,
. V_184 = V_185 ,
} ;
unsigned long V_186 = V_132 ;
long V_187 ;
long V_188 = 0 ;
while ( ! F_9 ( & V_6 -> V_13 ) ) {
struct V_1 * V_1 = F_1 ( V_6 -> V_13 . V_60 ) ;
struct V_5 * V_189 ;
if ( V_1 -> V_71 != V_125 ) {
if ( V_22 -> V_125 ) {
F_110 ( V_1 , V_6 ) ;
continue;
}
break;
}
F_44 ( & V_1 -> V_51 ) ;
if ( V_1 -> V_53 & ( V_190 | V_54 | V_173 ) ) {
F_59 ( & V_1 -> V_51 ) ;
F_110 ( V_1 , V_6 ) ;
continue;
}
if ( ( V_1 -> V_53 & V_133 ) && V_75 . V_114 != V_159 ) {
F_59 ( & V_1 -> V_51 ) ;
F_112 ( V_1 , V_6 ) ;
F_157 ( V_1 ) ;
continue;
}
F_59 ( & V_6 -> V_15 ) ;
if ( V_1 -> V_53 & V_133 ) {
F_138 ( V_1 ) ;
F_44 ( & V_6 -> V_15 ) ;
continue;
}
V_1 -> V_53 |= V_133 ;
F_73 ( & V_75 , V_1 ) ;
V_187 = F_154 ( V_6 , V_22 ) ;
V_75 . V_163 = V_187 ;
V_75 . V_161 = 0 ;
F_145 ( V_1 , & V_75 ) ;
F_75 ( & V_75 ) ;
V_22 -> V_101 -= V_187 - V_75 . V_163 ;
V_188 += V_187 - V_75 . V_163 ;
if ( F_158 () ) {
F_159 ( V_35 ) ;
F_160 () ;
}
V_189 = F_41 ( V_1 ) ;
F_44 ( & V_1 -> V_51 ) ;
if ( ! ( V_1 -> V_53 & V_174 ) )
V_188 ++ ;
F_143 ( V_1 , V_189 , & V_75 ) ;
F_113 ( V_1 ) ;
F_59 ( & V_1 -> V_51 ) ;
if ( F_37 ( V_189 != V_6 ) ) {
F_59 ( & V_189 -> V_15 ) ;
F_44 ( & V_6 -> V_15 ) ;
}
if ( V_188 ) {
if ( F_161 ( V_186 + V_148 / 10UL ) )
break;
if ( V_22 -> V_101 <= 0 )
break;
}
}
return V_188 ;
}
static long F_162 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
unsigned long V_186 = V_132 ;
long V_188 = 0 ;
while ( ! F_9 ( & V_6 -> V_13 ) ) {
struct V_1 * V_1 = F_1 ( V_6 -> V_13 . V_60 ) ;
struct V_124 * V_125 = V_1 -> V_71 ;
if ( ! F_163 ( V_125 ) ) {
F_110 ( V_1 , V_6 ) ;
continue;
}
V_188 += F_156 ( V_125 , V_6 , V_22 ) ;
F_164 ( & V_125 -> V_191 ) ;
if ( V_188 ) {
if ( F_161 ( V_186 + V_148 / 10UL ) )
break;
if ( V_22 -> V_101 <= 0 )
break;
}
}
return V_188 ;
}
static long F_165 ( struct V_5 * V_6 , long V_101 ,
enum V_119 V_120 )
{
struct V_21 V_22 = {
. V_101 = V_101 ,
. V_114 = V_115 ,
. V_118 = 1 ,
. V_120 = V_120 ,
} ;
struct V_192 V_193 ;
F_166 ( & V_193 ) ;
F_44 ( & V_6 -> V_15 ) ;
if ( F_9 ( & V_6 -> V_13 ) )
F_126 ( V_6 , & V_22 ) ;
F_162 ( V_6 , & V_22 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_167 ( & V_193 ) ;
return V_101 - V_22 . V_101 ;
}
static long F_168 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
unsigned long V_194 = V_132 ;
long V_101 = V_22 -> V_101 ;
unsigned long V_195 ;
struct V_1 * V_1 ;
long V_196 ;
struct V_192 V_193 ;
V_195 = V_132 ;
V_22 -> V_139 = & V_195 ;
F_166 ( & V_193 ) ;
F_44 ( & V_6 -> V_15 ) ;
for (; ; ) {
if ( V_22 -> V_101 <= 0 )
break;
if ( ( V_22 -> V_182 || V_22 -> V_181 ) &&
! F_9 ( & V_6 -> V_27 ) )
break;
if ( V_22 -> V_182 && ! F_169 ( V_6 ) )
break;
if ( V_22 -> V_181 ) {
V_195 = V_132 -
F_170 ( V_197 * 10 ) ;
} else if ( V_22 -> V_182 )
V_195 = V_132 ;
F_171 ( V_6 , V_22 ) ;
if ( F_9 ( & V_6 -> V_13 ) )
F_126 ( V_6 , V_22 ) ;
if ( V_22 -> V_125 )
V_196 = F_156 ( V_22 -> V_125 , V_6 , V_22 ) ;
else
V_196 = F_162 ( V_6 , V_22 ) ;
F_172 ( V_6 , V_22 ) ;
F_173 ( V_6 , V_194 ) ;
if ( V_196 )
continue;
if ( F_9 ( & V_6 -> V_14 ) )
break;
F_174 ( V_6 , V_22 ) ;
V_1 = F_1 ( V_6 -> V_14 . V_60 ) ;
F_44 ( & V_1 -> V_51 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_138 ( V_1 ) ;
F_44 ( & V_6 -> V_15 ) ;
}
F_59 ( & V_6 -> V_15 ) ;
F_167 ( & V_193 ) ;
return V_101 - V_22 -> V_101 ;
}
static struct V_21 * F_175 ( struct V_5 * V_6 )
{
struct V_21 * V_22 = NULL ;
F_18 ( & V_6 -> V_17 ) ;
if ( ! F_9 ( & V_6 -> V_27 ) ) {
V_22 = F_2 ( V_6 -> V_27 . V_131 ,
struct V_21 , V_26 ) ;
F_16 ( & V_22 -> V_26 ) ;
}
F_21 ( & V_6 -> V_17 ) ;
return V_22 ;
}
static unsigned long F_176 ( void )
{
return F_177 ( V_198 ) +
F_177 ( V_199 ) +
F_178 () ;
}
static long F_179 ( struct V_5 * V_6 )
{
if ( F_169 ( V_6 ) ) {
struct V_21 V_22 = {
. V_101 = V_104 ,
. V_114 = V_115 ,
. V_182 = 1 ,
. V_118 = 1 ,
. V_120 = V_200 ,
} ;
return F_168 ( V_6 , & V_22 ) ;
}
return 0 ;
}
static long F_180 ( struct V_5 * V_6 )
{
unsigned long V_201 ;
long V_101 ;
if ( ! V_202 )
return 0 ;
V_201 = V_6 -> V_203 +
F_170 ( V_202 * 10 ) ;
if ( F_111 ( V_132 , V_201 ) )
return 0 ;
V_6 -> V_203 = V_132 ;
V_101 = F_176 () ;
if ( V_101 ) {
struct V_21 V_22 = {
. V_101 = V_101 ,
. V_114 = V_115 ,
. V_181 = 1 ,
. V_118 = 1 ,
. V_120 = V_204 ,
} ;
return F_168 ( V_6 , & V_22 ) ;
}
return 0 ;
}
static long F_181 ( struct V_5 * V_6 )
{
struct V_21 * V_22 ;
long V_188 = 0 ;
F_5 ( V_205 , & V_6 -> V_8 ) ;
while ( ( V_22 = F_175 ( V_6 ) ) != NULL ) {
struct V_29 * V_24 = V_22 -> V_24 ;
F_182 ( V_6 , V_22 ) ;
V_188 += F_168 ( V_6 , V_22 ) ;
if ( V_22 -> V_116 )
F_61 ( V_22 ) ;
if ( V_24 && F_183 ( & V_24 -> V_25 ) )
F_184 ( & V_6 -> V_10 -> V_30 ) ;
}
V_188 += F_180 ( V_6 ) ;
V_188 += F_179 ( V_6 ) ;
F_10 ( V_205 , & V_6 -> V_8 ) ;
return V_188 ;
}
void F_185 ( struct V_38 * V_22 )
{
struct V_5 * V_6 = F_43 ( F_186 ( V_22 ) ,
struct V_5 , V_20 ) ;
long V_206 ;
F_187 ( L_2 , F_188 ( V_6 -> V_10 -> V_207 ) ) ;
V_35 -> V_126 |= V_208 ;
if ( F_49 ( ! F_189 () ||
! F_19 ( V_18 , & V_6 -> V_8 ) ) ) {
do {
V_206 = F_181 ( V_6 ) ;
F_190 ( V_206 ) ;
} while ( ! F_9 ( & V_6 -> V_27 ) );
} else {
V_206 = F_165 ( V_6 , 1024 ,
V_209 ) ;
F_190 ( V_206 ) ;
}
if ( ! F_9 ( & V_6 -> V_27 ) )
F_20 ( V_19 , & V_6 -> V_20 , 0 ) ;
else if ( F_4 ( V_6 ) && V_202 )
F_191 ( V_6 ) ;
V_35 -> V_126 &= ~ V_208 ;
}
void F_192 ( long V_101 , enum V_119 V_120 )
{
struct V_28 * V_10 ;
if ( F_193 ( V_35 ) )
F_194 ( V_35 ) ;
if ( ! V_101 )
V_101 = F_176 () ;
F_67 () ;
F_195 (bdi, &bdi_list, bdi_list) {
struct V_5 * V_6 ;
if ( ! F_196 ( V_10 ) )
continue;
F_195 (wb, &bdi->wb_list, bdi_node)
F_99 ( V_6 , F_85 ( V_6 , V_101 ) ,
false , V_120 ) ;
}
F_69 () ;
}
static void F_197 ( struct V_38 * V_210 )
{
struct V_28 * V_10 ;
F_67 () ;
F_195 (bdi, &bdi_list, bdi_list) {
struct V_5 * V_6 ;
F_195 (wb, &bdi->wb_list, bdi_node)
if ( ! F_9 ( & V_6 -> V_16 ) )
F_17 ( V_6 ) ;
}
F_69 () ;
F_198 ( & V_211 , V_147 * V_148 ) ;
}
static int T_3 F_199 ( void )
{
F_198 ( & V_211 , V_147 * V_148 ) ;
return 0 ;
}
int F_200 ( struct V_212 * V_213 , int V_214 ,
void T_5 * V_215 , T_2 * V_216 , T_6 * V_217 )
{
int V_136 ;
V_136 = F_201 ( V_213 , V_214 , V_215 , V_216 , V_217 ) ;
if ( V_136 == 0 && V_214 )
F_20 ( V_218 , & V_211 , 0 ) ;
return V_136 ;
}
static T_7 void F_202 ( struct V_1 * V_1 )
{
if ( V_1 -> V_219 || strcmp ( V_1 -> V_71 -> V_220 , L_3 ) ) {
struct V_221 * V_221 ;
const char * V_222 = L_4 ;
V_221 = F_203 ( V_1 ) ;
if ( V_221 ) {
F_44 ( & V_221 -> V_223 ) ;
V_222 = ( const char * ) V_221 -> V_224 . V_222 ;
}
F_204 ( V_225
L_5 ,
V_35 -> V_226 , F_205 ( V_35 ) , V_1 -> V_219 ,
V_222 , V_1 -> V_71 -> V_220 ) ;
if ( V_221 ) {
F_59 ( & V_221 -> V_223 ) ;
F_206 ( V_221 ) ;
}
}
}
void F_207 ( struct V_1 * V_1 , int V_126 )
{
#define F_208 (I_DIRTY_SYNC | I_DIRTY_DATASYNC)
struct V_124 * V_125 = V_1 -> V_71 ;
int V_227 ;
F_209 ( V_1 , V_126 ) ;
if ( V_126 & ( V_167 | V_168 | V_164 ) ) {
F_210 ( V_1 , V_126 ) ;
if ( V_125 -> V_151 -> V_228 )
V_125 -> V_151 -> V_228 ( V_1 , V_126 ) ;
F_211 ( V_1 , V_126 ) ;
}
if ( V_126 & F_208 )
V_126 &= ~ V_164 ;
V_227 = V_126 & V_164 ;
F_115 () ;
if ( ( ( V_1 -> V_53 & V_126 ) == V_126 ) ||
( V_227 && ( V_1 -> V_53 & F_208 ) ) )
return;
if ( F_37 ( V_229 ) )
F_202 ( V_1 ) ;
F_44 ( & V_1 -> V_51 ) ;
if ( V_227 && ( V_1 -> V_53 & F_208 ) )
goto V_230;
if ( ( V_1 -> V_53 & V_126 ) != V_126 ) {
const int V_231 = V_1 -> V_53 & V_158 ;
F_212 ( V_1 , NULL ) ;
if ( V_126 & F_208 )
V_1 -> V_53 &= ~ V_164 ;
V_1 -> V_53 |= V_126 ;
if ( V_1 -> V_53 & V_133 )
goto V_230;
if ( ! F_213 ( V_1 -> V_232 ) ) {
if ( F_214 ( V_1 ) )
goto V_230;
}
if ( V_1 -> V_53 & V_54 )
goto V_230;
if ( ! V_231 ) {
struct V_5 * V_6 ;
struct V_2 * V_233 ;
bool V_234 = false ;
V_6 = F_40 ( V_1 ) ;
F_215 ( F_216 ( V_6 -> V_10 ) &&
! F_19 ( V_18 , & V_6 -> V_8 ) ,
L_6 , V_6 -> V_10 -> V_222 ) ;
V_1 -> V_59 = V_132 ;
if ( V_227 )
V_1 -> V_170 = V_132 ;
if ( V_1 -> V_53 & ( F_208 | V_171 ) )
V_233 = & V_6 -> V_12 ;
else
V_233 = & V_6 -> V_16 ;
V_234 = F_12 ( V_1 , V_6 ,
V_233 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_217 ( V_1 ) ;
if ( F_216 ( V_6 -> V_10 ) && V_234 )
F_191 ( V_6 ) ;
return;
}
}
V_230:
F_59 ( & V_1 -> V_51 ) ;
#undef F_208
}
static void F_218 ( struct V_124 * V_125 )
{
F_122 ( V_235 ) ;
F_146 ( ! F_219 ( & V_125 -> V_191 ) ) ;
F_220 ( & V_125 -> V_236 ) ;
F_67 () ;
F_46 ( & V_125 -> V_128 ) ;
F_127 ( & V_125 -> V_129 , & V_235 ) ;
while ( ! F_9 ( & V_235 ) ) {
struct V_1 * V_1 = F_221 ( & V_235 , struct V_1 ,
V_127 ) ;
struct V_41 * V_42 = V_1 -> V_43 ;
F_222 ( & V_1 -> V_127 , & V_125 -> V_129 ) ;
if ( ! F_144 ( V_42 , V_175 ) )
continue;
F_58 ( & V_125 -> V_128 ) ;
F_44 ( & V_1 -> V_51 ) ;
if ( V_1 -> V_53 & ( V_54 | V_173 | V_190 ) ) {
F_59 ( & V_1 -> V_51 ) ;
F_46 ( & V_125 -> V_128 ) ;
continue;
}
F_71 ( V_1 ) ;
F_59 ( & V_1 -> V_51 ) ;
F_69 () ;
F_223 ( V_42 ) ;
F_160 () ;
F_60 ( V_1 ) ;
F_67 () ;
F_46 ( & V_125 -> V_128 ) ;
}
F_58 ( & V_125 -> V_128 ) ;
F_69 () ;
F_224 ( & V_125 -> V_236 ) ;
}
static void F_225 ( struct V_124 * V_125 , unsigned long V_237 ,
enum V_119 V_120 , bool V_107 )
{
F_91 ( V_24 ) ;
struct V_21 V_22 = {
. V_125 = V_125 ,
. V_114 = V_115 ,
. V_160 = 1 ,
. V_24 = & V_24 ,
. V_101 = V_237 ,
. V_120 = V_120 ,
} ;
struct V_28 * V_10 = V_125 -> V_238 ;
if ( ! F_196 ( V_10 ) || V_10 == & V_239 )
return;
F_146 ( ! F_219 ( & V_125 -> V_191 ) ) ;
F_88 ( V_125 -> V_238 , & V_22 , V_107 ) ;
F_26 ( V_10 , & V_24 ) ;
}
void F_226 ( struct V_124 * V_125 ,
unsigned long V_237 ,
enum V_119 V_120 )
{
F_225 ( V_125 , V_237 , V_120 , false ) ;
}
void F_227 ( struct V_124 * V_125 , enum V_119 V_120 )
{
return F_226 ( V_125 , F_176 () , V_120 ) ;
}
bool F_228 ( struct V_124 * V_125 , unsigned long V_237 ,
enum V_119 V_120 )
{
if ( ! F_229 ( & V_125 -> V_191 ) )
return false ;
F_225 ( V_125 , V_237 , V_120 , true ) ;
F_164 ( & V_125 -> V_191 ) ;
return true ;
}
bool F_230 ( struct V_124 * V_125 , enum V_119 V_120 )
{
return F_228 ( V_125 , F_176 () , V_120 ) ;
}
void F_231 ( struct V_124 * V_125 )
{
F_91 ( V_24 ) ;
struct V_21 V_22 = {
. V_125 = V_125 ,
. V_114 = V_159 ,
. V_101 = V_104 ,
. V_118 = 0 ,
. V_24 = & V_24 ,
. V_120 = V_240 ,
. V_146 = 1 ,
} ;
struct V_28 * V_10 = V_125 -> V_238 ;
if ( V_10 == & V_239 )
return;
F_146 ( ! F_219 ( & V_125 -> V_191 ) ) ;
F_88 ( V_10 , & V_22 , false ) ;
F_26 ( V_10 , & V_24 ) ;
F_218 ( V_125 ) ;
}
int F_232 ( struct V_1 * V_1 , int V_241 )
{
struct V_74 V_75 = {
. V_163 = V_104 ,
. V_114 = V_241 ? V_159 : V_115 ,
. V_183 = 0 ,
. V_184 = V_185 ,
} ;
if ( ! F_233 ( V_1 -> V_43 ) )
V_75 . V_163 = 0 ;
F_89 () ;
return F_153 ( V_1 , & V_75 ) ;
}
int F_234 ( struct V_1 * V_1 , struct V_74 * V_75 )
{
return F_153 ( V_1 , V_75 ) ;
}
int F_235 ( struct V_1 * V_1 , int V_156 )
{
struct V_74 V_75 = {
. V_114 = V_156 ? V_159 : V_115 ,
. V_163 = 0 ,
} ;
return F_234 ( V_1 , & V_75 ) ;
}
