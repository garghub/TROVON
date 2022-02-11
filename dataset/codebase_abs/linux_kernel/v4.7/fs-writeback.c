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
static void F_104 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
if ( ! F_9 ( & V_6 -> V_12 ) ) {
struct V_1 * V_124 ;
V_124 = F_1 ( V_6 -> V_12 . V_125 ) ;
if ( F_105 ( V_1 -> V_59 , V_124 -> V_59 ) )
V_1 -> V_59 = V_126 ;
}
F_12 ( V_1 , V_6 , & V_6 -> V_12 ) ;
}
static void F_106 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
F_12 ( V_1 , V_6 , & V_6 -> V_14 ) ;
}
static void F_107 ( struct V_1 * V_1 )
{
V_1 -> V_53 &= ~ V_127 ;
F_108 ( V_1 ) ;
F_109 () ;
F_110 ( & V_1 -> V_53 , V_128 ) ;
}
static bool F_111 ( struct V_1 * V_1 , unsigned long V_129 )
{
bool V_130 = F_112 ( V_1 -> V_59 , V_129 ) ;
#ifndef F_113
V_130 = V_130 && F_114 ( V_1 -> V_59 , V_126 ) ;
#endif
return V_130 ;
}
static int F_115 ( struct V_2 * V_131 ,
struct V_2 * V_132 ,
int V_133 ,
struct V_21 * V_22 )
{
unsigned long * V_134 = NULL ;
unsigned long V_135 ;
F_116 ( V_136 ) ;
struct V_2 * V_58 , * V_137 ;
struct V_138 * V_139 = NULL ;
struct V_1 * V_1 ;
int V_140 = 0 ;
int V_141 = 0 ;
if ( ( V_133 & V_142 ) == 0 )
V_134 = V_22 -> V_134 ;
else if ( ! V_22 -> V_143 ) {
V_135 = V_126 - ( V_144 * V_145 ) ;
V_134 = & V_135 ;
}
while ( ! F_9 ( V_131 ) ) {
V_1 = F_1 ( V_131 -> V_60 ) ;
if ( V_134 &&
F_111 ( V_1 , * V_134 ) )
break;
F_14 ( & V_1 -> V_4 , & V_136 ) ;
V_141 ++ ;
if ( V_133 & V_142 )
F_5 ( V_146 , & V_1 -> V_53 ) ;
if ( F_117 ( V_1 -> V_71 ) )
continue;
if ( V_139 && V_139 != V_1 -> V_71 )
V_140 = 1 ;
V_139 = V_1 -> V_71 ;
}
if ( ! V_140 ) {
F_118 ( & V_136 , V_132 ) ;
goto V_147;
}
while ( ! F_9 ( & V_136 ) ) {
V_139 = F_1 ( V_136 . V_60 ) -> V_71 ;
F_119 (pos, node, &tmp) {
V_1 = F_1 ( V_58 ) ;
if ( V_1 -> V_71 == V_139 )
F_14 ( & V_1 -> V_4 , V_132 ) ;
}
}
V_147:
return V_141 ;
}
static void F_120 ( struct V_5 * V_6 , struct V_21 * V_22 )
{
int V_141 ;
F_13 ( & V_6 -> V_15 ) ;
F_121 ( & V_6 -> V_14 , & V_6 -> V_13 ) ;
V_141 = F_115 ( & V_6 -> V_12 , & V_6 -> V_13 , 0 , V_22 ) ;
V_141 += F_115 ( & V_6 -> V_16 , & V_6 -> V_13 ,
V_142 , V_22 ) ;
if ( V_141 )
F_3 ( V_6 ) ;
F_122 ( V_6 , V_22 , V_141 ) ;
}
static int F_123 ( struct V_1 * V_1 , struct V_74 * V_75 )
{
int V_130 ;
if ( V_1 -> V_71 -> V_148 -> F_123 && ! F_124 ( V_1 ) ) {
F_125 ( V_1 , V_75 ) ;
V_130 = V_1 -> V_71 -> V_148 -> F_123 ( V_1 , V_75 ) ;
F_126 ( V_1 , V_75 ) ;
return V_130 ;
}
return 0 ;
}
static void F_127 ( struct V_1 * V_1 )
__releases( V_1 -> V_51 )
__acquires( V_1 -> V_51 )
{
F_128 ( V_149 , & V_1 -> V_53 , V_128 ) ;
T_4 * V_150 ;
V_150 = F_129 ( & V_1 -> V_53 , V_128 ) ;
while ( V_1 -> V_53 & V_127 ) {
F_59 ( & V_1 -> V_51 ) ;
F_130 ( V_150 , & V_149 , V_151 ,
V_152 ) ;
F_44 ( & V_1 -> V_51 ) ;
}
}
void F_131 ( struct V_1 * V_1 )
{
F_44 ( & V_1 -> V_51 ) ;
F_127 ( V_1 ) ;
F_59 ( & V_1 -> V_51 ) ;
}
static void F_132 ( struct V_1 * V_1 )
__releases( V_1 -> V_51 )
{
F_133 ( V_153 ) ;
T_4 * V_150 = F_129 ( & V_1 -> V_53 , V_128 ) ;
int V_154 ;
F_134 ( V_150 , & V_153 , V_152 ) ;
V_154 = V_1 -> V_53 & V_127 ;
F_59 ( & V_1 -> V_51 ) ;
if ( V_154 )
F_135 () ;
F_136 ( V_150 , & V_153 ) ;
}
static void F_137 ( struct V_1 * V_1 , struct V_5 * V_6 ,
struct V_74 * V_75 )
{
if ( V_1 -> V_53 & V_54 )
return;
if ( ( V_1 -> V_53 & V_155 ) &&
( V_75 -> V_114 == V_156 || V_75 -> V_157 ) )
V_1 -> V_59 = V_126 ;
if ( V_75 -> V_158 ) {
F_104 ( V_1 , V_6 ) ;
return;
}
if ( F_138 ( V_1 -> V_43 , V_159 ) ) {
if ( V_75 -> V_160 <= 0 ) {
F_106 ( V_1 , V_6 ) ;
} else {
F_104 ( V_1 , V_6 ) ;
}
} else if ( V_1 -> V_53 & V_155 ) {
F_104 ( V_1 , V_6 ) ;
} else if ( V_1 -> V_53 & V_161 ) {
V_1 -> V_59 = V_126 ;
F_12 ( V_1 , V_6 , & V_6 -> V_16 ) ;
} else {
F_15 ( V_1 , V_6 ) ;
}
}
static int
F_139 ( struct V_1 * V_1 , struct V_74 * V_75 )
{
struct V_41 * V_42 = V_1 -> V_43 ;
long V_160 = V_75 -> V_160 ;
unsigned V_162 ;
int V_130 ;
F_140 ( ! ( V_1 -> V_53 & V_127 ) ) ;
F_141 ( V_1 , V_75 , V_160 ) ;
V_130 = F_142 ( V_42 , V_75 ) ;
if ( V_75 -> V_114 == V_156 && ! V_75 -> V_143 ) {
int V_163 = F_143 ( V_42 ) ;
if ( V_130 == 0 )
V_130 = V_163 ;
}
F_44 ( & V_1 -> V_51 ) ;
V_162 = V_1 -> V_53 & V_155 ;
if ( V_1 -> V_53 & V_161 ) {
if ( ( V_162 & ( V_164 | V_165 ) ) ||
F_37 ( V_1 -> V_53 & V_166 ) ||
F_37 ( F_112 ( V_126 ,
( V_1 -> V_167 +
V_144 * V_145 ) ) ) ) {
V_162 |= V_161 | V_166 ;
F_144 ( V_1 ) ;
}
} else
V_1 -> V_53 &= ~ V_166 ;
V_1 -> V_53 &= ~ V_162 ;
F_109 () ;
if ( F_138 ( V_42 , V_159 ) )
V_1 -> V_53 |= V_168 ;
F_59 ( & V_1 -> V_51 ) ;
if ( V_162 & V_161 )
F_145 ( V_1 ) ;
if ( V_162 & ~ V_168 ) {
int V_163 = F_123 ( V_1 , V_75 ) ;
if ( V_130 == 0 )
V_130 = V_163 ;
}
F_146 ( V_1 , V_75 , V_160 ) ;
return V_130 ;
}
static int F_147 ( struct V_1 * V_1 ,
struct V_74 * V_75 )
{
struct V_5 * V_6 ;
int V_130 = 0 ;
F_44 ( & V_1 -> V_51 ) ;
if ( ! F_29 ( & V_1 -> V_169 ) )
F_140 ( ! ( V_1 -> V_53 & ( V_170 | V_54 ) ) ) ;
else
F_140 ( V_1 -> V_53 & V_170 ) ;
if ( V_1 -> V_53 & V_127 ) {
if ( V_75 -> V_114 != V_156 )
goto V_147;
F_127 ( V_1 ) ;
}
F_140 ( V_1 -> V_53 & V_127 ) ;
if ( ! ( V_1 -> V_53 & V_171 ) &&
( V_75 -> V_114 != V_156 ||
! F_138 ( V_1 -> V_43 , V_172 ) ) )
goto V_147;
V_1 -> V_53 |= V_127 ;
F_73 ( V_75 , V_1 ) ;
V_130 = F_139 ( V_1 , V_75 ) ;
F_75 ( V_75 ) ;
V_6 = F_41 ( V_1 ) ;
F_44 ( & V_1 -> V_51 ) ;
if ( ! ( V_1 -> V_53 & V_171 ) )
F_15 ( V_1 , V_6 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_107 ( V_1 ) ;
V_147:
F_59 ( & V_1 -> V_51 ) ;
return V_130 ;
}
static long F_148 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
long V_173 ;
if ( V_22 -> V_114 == V_156 || V_22 -> V_157 )
V_173 = V_104 ;
else {
V_173 = F_77 ( V_6 -> V_9 / 2 ,
V_174 . V_175 / V_176 ) ;
V_173 = F_77 ( V_173 , V_22 -> V_101 ) ;
V_173 = F_149 ( V_173 + V_177 ,
V_177 ) ;
}
return V_173 ;
}
static long F_150 ( struct V_138 * V_139 ,
struct V_5 * V_6 ,
struct V_21 * V_22 )
{
struct V_74 V_75 = {
. V_114 = V_22 -> V_114 ,
. V_157 = V_22 -> V_157 ,
. V_178 = V_22 -> V_178 ,
. V_179 = V_22 -> V_179 ,
. V_143 = V_22 -> V_143 ,
. V_118 = V_22 -> V_118 ,
. V_180 = 0 ,
. V_181 = V_182 ,
} ;
unsigned long V_183 = V_126 ;
long V_184 ;
long V_185 = 0 ;
while ( ! F_9 ( & V_6 -> V_13 ) ) {
struct V_1 * V_1 = F_1 ( V_6 -> V_13 . V_60 ) ;
struct V_5 * V_186 ;
if ( V_1 -> V_71 != V_139 ) {
if ( V_22 -> V_139 ) {
F_104 ( V_1 , V_6 ) ;
continue;
}
break;
}
F_44 ( & V_1 -> V_51 ) ;
if ( V_1 -> V_53 & ( V_187 | V_54 | V_170 ) ) {
F_59 ( & V_1 -> V_51 ) ;
F_104 ( V_1 , V_6 ) ;
continue;
}
if ( ( V_1 -> V_53 & V_127 ) && V_75 . V_114 != V_156 ) {
F_59 ( & V_1 -> V_51 ) ;
F_106 ( V_1 , V_6 ) ;
F_151 ( V_1 ) ;
continue;
}
F_59 ( & V_6 -> V_15 ) ;
if ( V_1 -> V_53 & V_127 ) {
F_132 ( V_1 ) ;
F_44 ( & V_6 -> V_15 ) ;
continue;
}
V_1 -> V_53 |= V_127 ;
F_73 ( & V_75 , V_1 ) ;
V_184 = F_148 ( V_6 , V_22 ) ;
V_75 . V_160 = V_184 ;
V_75 . V_158 = 0 ;
F_139 ( V_1 , & V_75 ) ;
F_75 ( & V_75 ) ;
V_22 -> V_101 -= V_184 - V_75 . V_160 ;
V_185 += V_184 - V_75 . V_160 ;
if ( F_152 () ) {
F_153 ( V_35 ) ;
F_154 () ;
}
V_186 = F_41 ( V_1 ) ;
F_44 ( & V_1 -> V_51 ) ;
if ( ! ( V_1 -> V_53 & V_171 ) )
V_185 ++ ;
F_137 ( V_1 , V_186 , & V_75 ) ;
F_107 ( V_1 ) ;
F_59 ( & V_1 -> V_51 ) ;
if ( F_37 ( V_186 != V_6 ) ) {
F_59 ( & V_186 -> V_15 ) ;
F_44 ( & V_6 -> V_15 ) ;
}
if ( V_185 ) {
if ( F_155 ( V_183 + V_145 / 10UL ) )
break;
if ( V_22 -> V_101 <= 0 )
break;
}
}
return V_185 ;
}
static long F_156 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
unsigned long V_183 = V_126 ;
long V_185 = 0 ;
while ( ! F_9 ( & V_6 -> V_13 ) ) {
struct V_1 * V_1 = F_1 ( V_6 -> V_13 . V_60 ) ;
struct V_138 * V_139 = V_1 -> V_71 ;
if ( ! F_157 ( V_139 ) ) {
F_104 ( V_1 , V_6 ) ;
continue;
}
V_185 += F_150 ( V_139 , V_6 , V_22 ) ;
F_158 ( & V_139 -> V_188 ) ;
if ( V_185 ) {
if ( F_155 ( V_183 + V_145 / 10UL ) )
break;
if ( V_22 -> V_101 <= 0 )
break;
}
}
return V_185 ;
}
static long F_159 ( struct V_5 * V_6 , long V_101 ,
enum V_119 V_120 )
{
struct V_21 V_22 = {
. V_101 = V_101 ,
. V_114 = V_115 ,
. V_118 = 1 ,
. V_120 = V_120 ,
} ;
struct V_189 V_190 ;
F_160 ( & V_190 ) ;
F_44 ( & V_6 -> V_15 ) ;
if ( F_9 ( & V_6 -> V_13 ) )
F_120 ( V_6 , & V_22 ) ;
F_156 ( V_6 , & V_22 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_161 ( & V_190 ) ;
return V_101 - V_22 . V_101 ;
}
static long F_162 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
unsigned long V_191 = V_126 ;
long V_101 = V_22 -> V_101 ;
unsigned long V_192 ;
struct V_1 * V_1 ;
long V_193 ;
struct V_189 V_190 ;
V_192 = V_126 ;
V_22 -> V_134 = & V_192 ;
F_160 ( & V_190 ) ;
F_44 ( & V_6 -> V_15 ) ;
for (; ; ) {
if ( V_22 -> V_101 <= 0 )
break;
if ( ( V_22 -> V_179 || V_22 -> V_178 ) &&
! F_9 ( & V_6 -> V_27 ) )
break;
if ( V_22 -> V_179 && ! F_163 ( V_6 ) )
break;
if ( V_22 -> V_178 ) {
V_192 = V_126 -
F_164 ( V_194 * 10 ) ;
} else if ( V_22 -> V_179 )
V_192 = V_126 ;
F_165 ( V_6 , V_22 ) ;
if ( F_9 ( & V_6 -> V_13 ) )
F_120 ( V_6 , V_22 ) ;
if ( V_22 -> V_139 )
V_193 = F_150 ( V_22 -> V_139 , V_6 , V_22 ) ;
else
V_193 = F_156 ( V_6 , V_22 ) ;
F_166 ( V_6 , V_22 ) ;
F_167 ( V_6 , V_191 ) ;
if ( V_193 )
continue;
if ( F_9 ( & V_6 -> V_14 ) )
break;
if ( ! F_9 ( & V_6 -> V_14 ) ) {
F_168 ( V_6 , V_22 ) ;
V_1 = F_1 ( V_6 -> V_14 . V_60 ) ;
F_44 ( & V_1 -> V_51 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_132 ( V_1 ) ;
F_44 ( & V_6 -> V_15 ) ;
}
}
F_59 ( & V_6 -> V_15 ) ;
F_161 ( & V_190 ) ;
return V_101 - V_22 -> V_101 ;
}
static struct V_21 * F_169 ( struct V_5 * V_6 )
{
struct V_21 * V_22 = NULL ;
F_18 ( & V_6 -> V_17 ) ;
if ( ! F_9 ( & V_6 -> V_27 ) ) {
V_22 = F_2 ( V_6 -> V_27 . V_125 ,
struct V_21 , V_26 ) ;
F_16 ( & V_22 -> V_26 ) ;
}
F_21 ( & V_6 -> V_17 ) ;
return V_22 ;
}
static unsigned long F_170 ( void )
{
return F_171 ( V_195 ) +
F_171 ( V_196 ) +
F_172 () ;
}
static long F_173 ( struct V_5 * V_6 )
{
if ( F_163 ( V_6 ) ) {
struct V_21 V_22 = {
. V_101 = V_104 ,
. V_114 = V_115 ,
. V_179 = 1 ,
. V_118 = 1 ,
. V_120 = V_197 ,
} ;
return F_162 ( V_6 , & V_22 ) ;
}
return 0 ;
}
static long F_174 ( struct V_5 * V_6 )
{
unsigned long V_198 ;
long V_101 ;
if ( ! V_199 )
return 0 ;
V_198 = V_6 -> V_200 +
F_164 ( V_199 * 10 ) ;
if ( F_105 ( V_126 , V_198 ) )
return 0 ;
V_6 -> V_200 = V_126 ;
V_101 = F_170 () ;
if ( V_101 ) {
struct V_21 V_22 = {
. V_101 = V_101 ,
. V_114 = V_115 ,
. V_178 = 1 ,
. V_118 = 1 ,
. V_120 = V_201 ,
} ;
return F_162 ( V_6 , & V_22 ) ;
}
return 0 ;
}
static long F_175 ( struct V_5 * V_6 )
{
struct V_21 * V_22 ;
long V_185 = 0 ;
F_5 ( V_202 , & V_6 -> V_8 ) ;
while ( ( V_22 = F_169 ( V_6 ) ) != NULL ) {
struct V_29 * V_24 = V_22 -> V_24 ;
F_176 ( V_6 , V_22 ) ;
V_185 += F_162 ( V_6 , V_22 ) ;
if ( V_22 -> V_116 )
F_61 ( V_22 ) ;
if ( V_24 && F_177 ( & V_24 -> V_25 ) )
F_178 ( & V_6 -> V_10 -> V_30 ) ;
}
V_185 += F_174 ( V_6 ) ;
V_185 += F_173 ( V_6 ) ;
F_10 ( V_202 , & V_6 -> V_8 ) ;
return V_185 ;
}
void F_179 ( struct V_38 * V_22 )
{
struct V_5 * V_6 = F_43 ( F_180 ( V_22 ) ,
struct V_5 , V_20 ) ;
long V_203 ;
F_181 ( L_2 , F_182 ( V_6 -> V_10 -> V_204 ) ) ;
V_35 -> V_133 |= V_205 ;
if ( F_49 ( ! F_183 () ||
! F_19 ( V_18 , & V_6 -> V_8 ) ) ) {
do {
V_203 = F_175 ( V_6 ) ;
F_184 ( V_203 ) ;
} while ( ! F_9 ( & V_6 -> V_27 ) );
} else {
V_203 = F_159 ( V_6 , 1024 ,
V_206 ) ;
F_184 ( V_203 ) ;
}
if ( ! F_9 ( & V_6 -> V_27 ) )
F_20 ( V_19 , & V_6 -> V_20 , 0 ) ;
else if ( F_4 ( V_6 ) && V_199 )
F_185 ( V_6 ) ;
V_35 -> V_133 &= ~ V_205 ;
}
void F_186 ( long V_101 , enum V_119 V_120 )
{
struct V_28 * V_10 ;
if ( ! V_101 )
V_101 = F_170 () ;
F_67 () ;
F_187 (bdi, &bdi_list, bdi_list) {
struct V_5 * V_6 ;
if ( ! F_188 ( V_10 ) )
continue;
F_187 (wb, &bdi->wb_list, bdi_node)
F_99 ( V_6 , F_85 ( V_6 , V_101 ) ,
false , V_120 ) ;
}
F_69 () ;
}
static void F_189 ( struct V_38 * V_207 )
{
struct V_28 * V_10 ;
F_67 () ;
F_187 (bdi, &bdi_list, bdi_list) {
struct V_5 * V_6 ;
F_187 (wb, &bdi->wb_list, bdi_node)
if ( ! F_9 ( & V_6 -> V_16 ) )
F_17 ( V_6 ) ;
}
F_69 () ;
F_190 ( & V_208 , V_144 * V_145 ) ;
}
static int T_3 F_191 ( void )
{
F_190 ( & V_208 , V_144 * V_145 ) ;
return 0 ;
}
int F_192 ( struct V_209 * V_210 , int V_211 ,
void T_5 * V_212 , T_2 * V_213 , T_6 * V_214 )
{
int V_130 ;
V_130 = F_193 ( V_210 , V_211 , V_212 , V_213 , V_214 ) ;
if ( V_130 == 0 && V_211 )
F_20 ( V_215 , & V_208 , 0 ) ;
return V_130 ;
}
static T_7 void F_194 ( struct V_1 * V_1 )
{
if ( V_1 -> V_216 || strcmp ( V_1 -> V_71 -> V_217 , L_3 ) ) {
struct V_218 * V_218 ;
const char * V_219 = L_4 ;
V_218 = F_195 ( V_1 ) ;
if ( V_218 ) {
F_44 ( & V_218 -> V_220 ) ;
V_219 = ( const char * ) V_218 -> V_221 . V_219 ;
}
F_196 ( V_222
L_5 ,
V_35 -> V_223 , F_197 ( V_35 ) , V_1 -> V_216 ,
V_219 , V_1 -> V_71 -> V_217 ) ;
if ( V_218 ) {
F_59 ( & V_218 -> V_220 ) ;
F_198 ( V_218 ) ;
}
}
}
void F_199 ( struct V_1 * V_1 , int V_133 )
{
#define F_200 (I_DIRTY_SYNC | I_DIRTY_DATASYNC)
struct V_138 * V_139 = V_1 -> V_71 ;
int V_224 ;
F_201 ( V_1 , V_133 ) ;
if ( V_133 & ( V_164 | V_165 | V_161 ) ) {
F_202 ( V_1 , V_133 ) ;
if ( V_139 -> V_148 -> V_225 )
V_139 -> V_148 -> V_225 ( V_1 , V_133 ) ;
F_203 ( V_1 , V_133 ) ;
}
if ( V_133 & F_200 )
V_133 &= ~ V_161 ;
V_224 = V_133 & V_161 ;
F_109 () ;
if ( ( ( V_1 -> V_53 & V_133 ) == V_133 ) ||
( V_224 && ( V_1 -> V_53 & F_200 ) ) )
return;
if ( F_37 ( V_226 ) )
F_194 ( V_1 ) ;
F_44 ( & V_1 -> V_51 ) ;
if ( V_224 && ( V_1 -> V_53 & F_200 ) )
goto V_227;
if ( ( V_1 -> V_53 & V_133 ) != V_133 ) {
const int V_228 = V_1 -> V_53 & V_155 ;
F_204 ( V_1 , NULL ) ;
if ( V_133 & F_200 )
V_1 -> V_53 &= ~ V_161 ;
V_1 -> V_53 |= V_133 ;
if ( V_1 -> V_53 & V_127 )
goto V_227;
if ( ! F_205 ( V_1 -> V_229 ) ) {
if ( F_206 ( V_1 ) )
goto V_227;
}
if ( V_1 -> V_53 & V_54 )
goto V_227;
if ( ! V_228 ) {
struct V_5 * V_6 ;
struct V_2 * V_230 ;
bool V_231 = false ;
V_6 = F_40 ( V_1 ) ;
F_207 ( F_208 ( V_6 -> V_10 ) &&
! F_19 ( V_18 , & V_6 -> V_8 ) ,
L_6 , V_6 -> V_10 -> V_219 ) ;
V_1 -> V_59 = V_126 ;
if ( V_224 )
V_1 -> V_167 = V_126 ;
if ( V_1 -> V_53 & ( F_200 | V_168 ) )
V_230 = & V_6 -> V_12 ;
else
V_230 = & V_6 -> V_16 ;
V_231 = F_12 ( V_1 , V_6 ,
V_230 ) ;
F_59 ( & V_6 -> V_15 ) ;
F_209 ( V_1 ) ;
if ( F_208 ( V_6 -> V_10 ) && V_231 )
F_185 ( V_6 ) ;
return;
}
}
V_227:
F_59 ( & V_1 -> V_51 ) ;
#undef F_200
}
static void F_210 ( struct V_138 * V_139 )
{
struct V_1 * V_1 , * V_232 = NULL ;
F_140 ( ! F_211 ( & V_139 -> V_188 ) ) ;
F_212 ( & V_139 -> V_233 ) ;
F_44 ( & V_139 -> V_234 ) ;
F_55 (inode, &sb->s_inodes, i_sb_list) {
struct V_41 * V_42 = V_1 -> V_43 ;
F_44 ( & V_1 -> V_51 ) ;
if ( ( V_1 -> V_53 & ( V_54 | V_170 | V_187 ) ) ||
( V_42 -> V_235 == 0 ) ) {
F_59 ( & V_1 -> V_51 ) ;
continue;
}
F_71 ( V_1 ) ;
F_59 ( & V_1 -> V_51 ) ;
F_59 ( & V_139 -> V_234 ) ;
F_60 ( V_232 ) ;
V_232 = V_1 ;
F_213 ( V_42 ) ;
F_154 () ;
F_44 ( & V_139 -> V_234 ) ;
}
F_59 ( & V_139 -> V_234 ) ;
F_60 ( V_232 ) ;
F_214 ( & V_139 -> V_233 ) ;
}
static void F_215 ( struct V_138 * V_139 , unsigned long V_236 ,
enum V_119 V_120 , bool V_107 )
{
F_91 ( V_24 ) ;
struct V_21 V_22 = {
. V_139 = V_139 ,
. V_114 = V_115 ,
. V_157 = 1 ,
. V_24 = & V_24 ,
. V_101 = V_236 ,
. V_120 = V_120 ,
} ;
struct V_28 * V_10 = V_139 -> V_237 ;
if ( ! F_188 ( V_10 ) || V_10 == & V_238 )
return;
F_140 ( ! F_211 ( & V_139 -> V_188 ) ) ;
F_88 ( V_139 -> V_237 , & V_22 , V_107 ) ;
F_26 ( V_10 , & V_24 ) ;
}
void F_216 ( struct V_138 * V_139 ,
unsigned long V_236 ,
enum V_119 V_120 )
{
F_215 ( V_139 , V_236 , V_120 , false ) ;
}
void F_217 ( struct V_138 * V_139 , enum V_119 V_120 )
{
return F_216 ( V_139 , F_170 () , V_120 ) ;
}
bool F_218 ( struct V_138 * V_139 , unsigned long V_236 ,
enum V_119 V_120 )
{
if ( ! F_219 ( & V_139 -> V_188 ) )
return false ;
F_215 ( V_139 , V_236 , V_120 , true ) ;
F_158 ( & V_139 -> V_188 ) ;
return true ;
}
bool F_220 ( struct V_138 * V_139 , enum V_119 V_120 )
{
return F_218 ( V_139 , F_170 () , V_120 ) ;
}
void F_221 ( struct V_138 * V_139 )
{
F_91 ( V_24 ) ;
struct V_21 V_22 = {
. V_139 = V_139 ,
. V_114 = V_156 ,
. V_101 = V_104 ,
. V_118 = 0 ,
. V_24 = & V_24 ,
. V_120 = V_239 ,
. V_143 = 1 ,
} ;
struct V_28 * V_10 = V_139 -> V_237 ;
if ( V_10 == & V_238 )
return;
F_140 ( ! F_211 ( & V_139 -> V_188 ) ) ;
F_88 ( V_10 , & V_22 , false ) ;
F_26 ( V_10 , & V_24 ) ;
F_210 ( V_139 ) ;
}
int F_222 ( struct V_1 * V_1 , int V_240 )
{
struct V_74 V_75 = {
. V_160 = V_104 ,
. V_114 = V_240 ? V_156 : V_115 ,
. V_180 = 0 ,
. V_181 = V_182 ,
} ;
if ( ! F_223 ( V_1 -> V_43 ) )
V_75 . V_160 = 0 ;
F_89 () ;
return F_147 ( V_1 , & V_75 ) ;
}
int F_224 ( struct V_1 * V_1 , struct V_74 * V_75 )
{
return F_147 ( V_1 , V_75 ) ;
}
int F_225 ( struct V_1 * V_1 , int V_153 )
{
struct V_74 V_75 = {
. V_114 = V_153 ? V_156 : V_115 ,
. V_160 = 0 ,
} ;
return F_224 ( V_1 , & V_75 ) ;
}
