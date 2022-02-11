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
struct V_23 * V_24 = V_22 -> V_24 ;
if ( V_22 -> V_25 )
F_23 ( V_22 ) ;
if ( V_24 && F_24 ( & V_24 -> V_26 ) )
F_25 ( & V_6 -> V_10 -> V_27 ) ;
}
static void F_26 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
F_27 ( V_6 , V_22 ) ;
if ( V_22 -> V_24 )
F_28 ( & V_22 -> V_24 -> V_26 ) ;
F_18 ( & V_6 -> V_17 ) ;
if ( F_19 ( V_18 , & V_6 -> V_8 ) ) {
F_29 ( & V_22 -> V_28 , & V_6 -> V_29 ) ;
F_20 ( V_19 , & V_6 -> V_20 , 0 ) ;
} else
F_22 ( V_6 , V_22 ) ;
F_21 ( & V_6 -> V_17 ) ;
}
static void F_30 ( struct V_30 * V_10 ,
struct V_23 * V_24 )
{
F_31 ( & V_24 -> V_26 ) ;
F_32 ( V_10 -> V_27 , ! F_33 ( & V_24 -> V_26 ) ) ;
}
void F_34 ( struct V_1 * V_1 , struct V_31 * V_31 )
{
struct V_30 * V_10 = F_35 ( V_1 ) ;
struct V_5 * V_6 = NULL ;
if ( F_36 ( V_1 ) ) {
struct V_32 * V_33 ;
if ( V_31 ) {
V_33 = F_37 ( V_31 ) ;
V_6 = F_38 ( V_10 , V_33 , V_34 ) ;
} else {
V_33 = F_39 ( V_35 , V_36 ) ;
V_6 = F_38 ( V_10 , V_33 , V_34 ) ;
F_40 ( V_33 ) ;
}
}
if ( ! V_6 )
V_6 = & V_10 -> V_6 ;
if ( F_41 ( F_42 ( & V_1 -> V_37 , NULL , V_6 ) ) )
F_43 ( V_6 ) ;
}
static struct V_5 *
F_44 ( struct V_1 * V_1 )
__releases( &inode->i_lock
static struct V_5 * F_45 ( struct V_1 * V_1 )
__acquires( &wb->list_lock
static void F_46 ( struct V_38 * V_22 )
{
struct V_39 * V_40 =
F_47 ( V_22 , struct V_39 , V_22 ) ;
struct V_1 * V_1 = V_40 -> V_1 ;
struct V_41 * V_42 = V_1 -> V_43 ;
struct V_5 * V_44 = V_1 -> V_37 ;
struct V_5 * V_45 = V_40 -> V_45 ;
struct V_46 V_47 ;
bool V_48 = false ;
void * * V_49 ;
if ( V_44 < V_45 ) {
F_48 ( & V_44 -> V_15 ) ;
F_49 ( & V_45 -> V_15 , V_50 ) ;
} else {
F_48 ( & V_45 -> V_15 ) ;
F_49 ( & V_44 -> V_15 , V_50 ) ;
}
F_48 ( & V_1 -> V_51 ) ;
F_50 ( & V_42 -> V_52 ) ;
if ( F_41 ( V_1 -> V_53 & V_54 ) )
goto V_55;
F_51 (slot, &mapping->page_tree, &iter, 0 ,
PAGECACHE_TAG_DIRTY) {
struct V_31 * V_31 = F_52 ( V_49 ,
& V_42 -> V_52 ) ;
if ( F_53 ( V_31 ) && F_54 ( V_31 ) ) {
F_55 ( V_44 , V_56 ) ;
F_56 ( V_45 , V_56 ) ;
}
}
F_51 (slot, &mapping->page_tree, &iter, 0 ,
PAGECACHE_TAG_WRITEBACK) {
struct V_31 * V_31 = F_52 ( V_49 ,
& V_42 -> V_52 ) ;
if ( F_53 ( V_31 ) ) {
F_6 ( ! F_57 ( V_31 ) ) ;
F_55 ( V_44 , V_57 ) ;
F_56 ( V_45 , V_57 ) ;
}
}
F_58 ( V_45 ) ;
if ( ! F_9 ( & V_1 -> V_4 ) ) {
struct V_1 * V_58 ;
F_15 ( V_1 , V_44 ) ;
V_1 -> V_37 = V_45 ;
F_59 (pos, &new_wb->b_dirty, i_io_list)
if ( F_60 ( V_1 -> V_59 ,
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
F_61 ( & V_1 -> V_53 , V_1 -> V_53 & ~ V_64 ) ;
F_62 ( & V_42 -> V_52 ) ;
F_63 ( & V_1 -> V_51 ) ;
F_63 ( & V_45 -> V_15 ) ;
F_63 ( & V_44 -> V_15 ) ;
if ( V_48 ) {
F_17 ( V_45 ) ;
F_43 ( V_44 ) ;
}
F_43 ( V_45 ) ;
F_64 ( V_1 ) ;
F_23 ( V_40 ) ;
F_31 ( & V_65 ) ;
}
static void F_65 ( struct V_66 * V_66 )
{
struct V_39 * V_40 = F_47 ( V_66 ,
struct V_39 , V_66 ) ;
F_66 ( & V_40 -> V_22 , F_46 ) ;
F_67 ( V_67 , & V_40 -> V_22 ) ;
}
static void F_68 ( struct V_1 * V_1 , int V_68 )
{
struct V_30 * V_10 = F_35 ( V_1 ) ;
struct V_32 * V_33 ;
struct V_39 * V_40 ;
if ( V_1 -> V_53 & V_64 )
return;
V_40 = F_69 ( sizeof( * V_40 ) , V_34 ) ;
if ( ! V_40 )
return;
F_70 () ;
V_33 = F_71 ( V_68 , & V_69 ) ;
if ( V_33 )
V_40 -> V_45 = F_38 ( V_10 , V_33 , V_34 ) ;
F_72 () ;
if ( ! V_40 -> V_45 )
goto V_70;
F_48 ( & V_1 -> V_51 ) ;
if ( ! ( V_1 -> V_71 -> V_72 & V_73 ) ||
V_1 -> V_53 & ( V_64 | V_54 ) ||
F_73 ( V_1 ) == V_40 -> V_45 ) {
F_63 ( & V_1 -> V_51 ) ;
goto V_70;
}
V_1 -> V_53 |= V_64 ;
F_74 ( V_1 ) ;
F_63 ( & V_1 -> V_51 ) ;
V_40 -> V_1 = V_1 ;
F_28 ( & V_65 ) ;
F_75 ( & V_40 -> V_66 , F_65 ) ;
return;
V_70:
if ( V_40 -> V_45 )
F_43 ( V_40 -> V_45 ) ;
F_23 ( V_40 ) ;
}
void F_76 ( struct V_74 * V_75 ,
struct V_1 * V_1 )
{
if ( ! F_36 ( V_1 ) ) {
F_63 ( & V_1 -> V_51 ) ;
return;
}
V_75 -> V_6 = F_73 ( V_1 ) ;
V_75 -> V_1 = V_1 ;
V_75 -> V_76 = V_75 -> V_6 -> V_33 -> V_77 ;
V_75 -> V_78 = V_1 -> V_61 ;
V_75 -> V_79 = 0 ;
V_75 -> V_80 = 0 ;
V_75 -> V_81 = 0 ;
V_75 -> V_82 = 0 ;
F_58 ( V_75 -> V_6 ) ;
F_63 ( & V_1 -> V_51 ) ;
if ( F_41 ( F_77 ( V_75 -> V_6 ) ) )
F_68 ( V_1 , V_75 -> V_76 ) ;
}
void F_78 ( struct V_74 * V_75 )
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
V_85 = F_79 ( ( V_84 >> V_88 ) << V_89 ,
V_6 -> V_9 ) ;
if ( V_83 )
V_83 += ( V_85 >> V_90 ) -
( V_83 >> V_90 ) ;
else
V_83 = V_85 ;
if ( V_85 >= V_83 / V_91 ) {
int V_92 ;
V_92 = F_80 ( F_79 ( V_85 , V_93 ) ,
( unsigned long ) V_94 ) ;
V_86 <<= V_92 ;
if ( V_75 -> V_76 != V_87 )
V_86 |= ( 1U << V_92 ) - 1 ;
if ( F_81 ( V_86 ) > V_95 )
F_68 ( V_1 , V_87 ) ;
}
V_1 -> V_61 = V_87 ;
V_1 -> V_62 = F_80 ( V_83 , ( unsigned long ) V_96 ) ;
V_1 -> V_63 = V_86 ;
F_43 ( V_75 -> V_6 ) ;
V_75 -> V_6 = NULL ;
}
void F_82 ( struct V_74 * V_75 , struct V_31 * V_31 ,
T_2 V_97 )
{
int V_77 ;
if ( ! V_75 -> V_6 )
return;
V_77 = F_37 ( V_31 ) -> V_77 ;
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
V_75 -> V_82 -= F_80 ( V_97 , V_75 -> V_82 ) ;
}
int F_83 ( struct V_1 * V_1 , int V_98 )
{
if ( V_1 && F_84 ( V_1 ) ) {
struct V_5 * V_6 ;
bool V_99 , V_100 ;
V_6 = F_85 ( V_1 , & V_99 ) ;
V_100 = F_86 ( V_6 , V_98 ) ;
F_87 ( V_1 , V_99 ) ;
return V_100 ;
}
return F_86 ( & F_35 ( V_1 ) -> V_6 , V_98 ) ;
}
static long F_88 ( struct V_5 * V_6 , long V_101 )
{
unsigned long V_102 = V_6 -> V_9 ;
unsigned long V_103 = F_89 ( & V_6 -> V_10 -> V_11 ) ;
if ( V_101 == V_104 )
return V_104 ;
if ( ! V_103 || V_102 >= V_103 )
return V_101 ;
else
return F_90 ( ( V_105 ) V_101 * V_102 , V_103 ) ;
}
static void F_91 ( struct V_30 * V_10 ,
struct V_21 * V_106 ,
bool V_107 )
{
struct V_5 * V_108 = NULL ;
struct V_5 * V_6 = F_2 ( & V_10 -> V_109 ,
struct V_5 , V_110 ) ;
F_92 () ;
V_111:
F_70 () ;
F_93 (wb, &bdi->wb_list, bdi_node) {
F_94 ( V_112 ) ;
struct V_21 V_113 ;
struct V_21 * V_22 ;
long V_101 ;
if ( V_108 ) {
F_43 ( V_108 ) ;
V_108 = NULL ;
}
if ( ! F_4 ( V_6 ) &&
( V_106 -> V_114 == V_115 ||
F_9 ( & V_6 -> V_16 ) ) )
continue;
if ( V_107 && F_95 ( V_6 ) )
continue;
V_101 = F_88 ( V_6 , V_106 -> V_101 ) ;
V_22 = F_96 ( sizeof( * V_22 ) , V_34 ) ;
if ( V_22 ) {
* V_22 = * V_106 ;
V_22 -> V_101 = V_101 ;
V_22 -> V_25 = 1 ;
F_26 ( V_6 , V_22 ) ;
continue;
}
V_22 = & V_113 ;
* V_22 = * V_106 ;
V_22 -> V_101 = V_101 ;
V_22 -> V_25 = 0 ;
V_22 -> V_24 = & V_112 ;
F_26 ( V_6 , V_22 ) ;
F_58 ( V_6 ) ;
V_108 = V_6 ;
F_72 () ;
F_30 ( V_10 , & V_112 ) ;
goto V_111;
}
F_72 () ;
if ( V_108 )
F_43 ( V_108 ) ;
}
void F_97 ( void )
{
if ( F_33 ( & V_65 ) ) {
F_98 () ;
F_99 ( V_67 ) ;
}
}
static int T_3 F_100 ( void )
{
V_67 = F_101 ( L_1 , 0 , 0 ) ;
if ( ! V_67 )
return - V_116 ;
return 0 ;
}
static struct V_5 *
F_44 ( struct V_1 * V_1 )
__releases( &inode->i_lock
static struct V_5 * F_45 ( struct V_1 * V_1 )
__acquires( &wb->list_lock
static long F_88 ( struct V_5 * V_6 , long V_101 )
{
return V_101 ;
}
static void F_91 ( struct V_30 * V_10 ,
struct V_21 * V_106 ,
bool V_107 )
{
F_92 () ;
if ( ! V_107 || ! F_95 ( & V_10 -> V_6 ) ) {
V_106 -> V_25 = 0 ;
F_26 ( & V_10 -> V_6 , V_106 ) ;
}
}
void F_102 ( struct V_5 * V_6 , long V_101 ,
bool V_117 , enum V_118 V_119 )
{
struct V_21 * V_22 ;
if ( ! F_4 ( V_6 ) )
return;
V_22 = F_69 ( sizeof( * V_22 ) ,
V_120 | V_121 | V_122 ) ;
if ( ! V_22 ) {
F_103 ( V_6 ) ;
F_17 ( V_6 ) ;
return;
}
V_22 -> V_114 = V_115 ;
V_22 -> V_101 = V_101 ;
V_22 -> V_117 = V_117 ;
V_22 -> V_119 = V_119 ;
V_22 -> V_25 = 1 ;
F_26 ( V_6 , V_22 ) ;
}
void F_104 ( struct V_5 * V_6 )
{
F_105 ( V_6 ) ;
F_17 ( V_6 ) ;
}
void F_106 ( struct V_1 * V_1 )
{
struct V_5 * V_6 ;
V_6 = F_45 ( V_1 ) ;
F_15 ( V_1 , V_6 ) ;
F_63 ( & V_6 -> V_15 ) ;
}
void F_107 ( struct V_1 * V_1 )
{
struct V_123 * V_124 = V_1 -> V_71 ;
unsigned long V_125 ;
if ( F_9 ( & V_1 -> V_126 ) ) {
F_108 ( & V_124 -> V_127 , V_125 ) ;
if ( F_9 ( & V_1 -> V_126 ) ) {
F_29 ( & V_1 -> V_126 , & V_124 -> V_128 ) ;
F_109 ( V_1 ) ;
}
F_110 ( & V_124 -> V_127 , V_125 ) ;
}
}
void F_111 ( struct V_1 * V_1 )
{
struct V_123 * V_124 = V_1 -> V_71 ;
unsigned long V_125 ;
if ( ! F_9 ( & V_1 -> V_126 ) ) {
F_108 ( & V_124 -> V_127 , V_125 ) ;
if ( ! F_9 ( & V_1 -> V_126 ) ) {
F_16 ( & V_1 -> V_126 ) ;
F_112 ( V_1 ) ;
}
F_110 ( & V_124 -> V_127 , V_125 ) ;
}
}
static void F_113 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
if ( ! F_9 ( & V_6 -> V_12 ) ) {
struct V_1 * V_129 ;
V_129 = F_1 ( V_6 -> V_12 . V_130 ) ;
if ( F_114 ( V_1 -> V_59 , V_129 -> V_59 ) )
V_1 -> V_59 = V_131 ;
}
F_12 ( V_1 , V_6 , & V_6 -> V_12 ) ;
}
static void F_115 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
F_12 ( V_1 , V_6 , & V_6 -> V_14 ) ;
}
static void F_116 ( struct V_1 * V_1 )
{
V_1 -> V_53 &= ~ V_132 ;
F_117 ( V_1 ) ;
F_118 () ;
F_119 ( & V_1 -> V_53 , V_133 ) ;
}
static bool F_120 ( struct V_1 * V_1 , unsigned long V_134 )
{
bool V_135 = F_121 ( V_1 -> V_59 , V_134 ) ;
#ifndef F_122
V_135 = V_135 && F_123 ( V_1 -> V_59 , V_131 ) ;
#endif
return V_135 ;
}
static int F_124 ( struct V_2 * V_136 ,
struct V_2 * V_137 ,
int V_125 ,
struct V_21 * V_22 )
{
unsigned long * V_138 = NULL ;
unsigned long V_139 ;
F_125 ( V_140 ) ;
struct V_2 * V_58 , * V_141 ;
struct V_123 * V_124 = NULL ;
struct V_1 * V_1 ;
int V_142 = 0 ;
int V_143 = 0 ;
if ( ( V_125 & V_144 ) == 0 )
V_138 = V_22 -> V_138 ;
else if ( ! V_22 -> V_145 ) {
V_139 = V_131 - ( V_146 * V_147 ) ;
V_138 = & V_139 ;
}
while ( ! F_9 ( V_136 ) ) {
V_1 = F_1 ( V_136 -> V_60 ) ;
if ( V_138 &&
F_120 ( V_1 , * V_138 ) )
break;
F_14 ( & V_1 -> V_4 , & V_140 ) ;
V_143 ++ ;
if ( V_125 & V_144 )
F_5 ( V_148 , & V_1 -> V_53 ) ;
if ( F_126 ( V_1 -> V_71 ) )
continue;
if ( V_124 && V_124 != V_1 -> V_71 )
V_142 = 1 ;
V_124 = V_1 -> V_71 ;
}
if ( ! V_142 ) {
F_127 ( & V_140 , V_137 ) ;
goto V_149;
}
while ( ! F_9 ( & V_140 ) ) {
V_124 = F_1 ( V_140 . V_60 ) -> V_71 ;
F_128 (pos, node, &tmp) {
V_1 = F_1 ( V_58 ) ;
if ( V_1 -> V_71 == V_124 )
F_14 ( & V_1 -> V_4 , V_137 ) ;
}
}
V_149:
return V_143 ;
}
static void F_129 ( struct V_5 * V_6 , struct V_21 * V_22 )
{
int V_143 ;
F_13 ( & V_6 -> V_15 ) ;
F_130 ( & V_6 -> V_14 , & V_6 -> V_13 ) ;
V_143 = F_124 ( & V_6 -> V_12 , & V_6 -> V_13 , 0 , V_22 ) ;
V_143 += F_124 ( & V_6 -> V_16 , & V_6 -> V_13 ,
V_144 , V_22 ) ;
if ( V_143 )
F_3 ( V_6 ) ;
F_131 ( V_6 , V_22 , V_143 ) ;
}
static int F_132 ( struct V_1 * V_1 , struct V_74 * V_75 )
{
int V_135 ;
if ( V_1 -> V_71 -> V_150 -> F_132 && ! F_133 ( V_1 ) ) {
F_134 ( V_1 , V_75 ) ;
V_135 = V_1 -> V_71 -> V_150 -> F_132 ( V_1 , V_75 ) ;
F_135 ( V_1 , V_75 ) ;
return V_135 ;
}
return 0 ;
}
static void F_136 ( struct V_1 * V_1 )
__releases( V_1 -> V_51 )
__acquires( V_1 -> V_51 )
{
F_137 ( V_151 , & V_1 -> V_53 , V_133 ) ;
T_4 * V_152 ;
V_152 = F_138 ( & V_1 -> V_53 , V_133 ) ;
while ( V_1 -> V_53 & V_132 ) {
F_63 ( & V_1 -> V_51 ) ;
F_139 ( V_152 , & V_151 , V_153 ,
V_154 ) ;
F_48 ( & V_1 -> V_51 ) ;
}
}
void F_140 ( struct V_1 * V_1 )
{
F_48 ( & V_1 -> V_51 ) ;
F_136 ( V_1 ) ;
F_63 ( & V_1 -> V_51 ) ;
}
static void F_141 ( struct V_1 * V_1 )
__releases( V_1 -> V_51 )
{
F_142 ( V_155 ) ;
T_4 * V_152 = F_138 ( & V_1 -> V_53 , V_133 ) ;
int V_156 ;
F_143 ( V_152 , & V_155 , V_154 ) ;
V_156 = V_1 -> V_53 & V_132 ;
F_63 ( & V_1 -> V_51 ) ;
if ( V_156 )
F_144 () ;
F_145 ( V_152 , & V_155 ) ;
}
static void F_146 ( struct V_1 * V_1 , struct V_5 * V_6 ,
struct V_74 * V_75 )
{
if ( V_1 -> V_53 & V_54 )
return;
if ( ( V_1 -> V_53 & V_157 ) &&
( V_75 -> V_114 == V_158 || V_75 -> V_159 ) )
V_1 -> V_59 = V_131 ;
if ( V_75 -> V_160 ) {
F_113 ( V_1 , V_6 ) ;
return;
}
if ( F_147 ( V_1 -> V_43 , V_161 ) ) {
if ( V_75 -> V_162 <= 0 ) {
F_115 ( V_1 , V_6 ) ;
} else {
F_113 ( V_1 , V_6 ) ;
}
} else if ( V_1 -> V_53 & V_157 ) {
F_113 ( V_1 , V_6 ) ;
} else if ( V_1 -> V_53 & V_163 ) {
V_1 -> V_59 = V_131 ;
F_12 ( V_1 , V_6 , & V_6 -> V_16 ) ;
} else {
F_15 ( V_1 , V_6 ) ;
}
}
static int
F_148 ( struct V_1 * V_1 , struct V_74 * V_75 )
{
struct V_41 * V_42 = V_1 -> V_43 ;
long V_162 = V_75 -> V_162 ;
unsigned V_164 ;
int V_135 ;
F_149 ( ! ( V_1 -> V_53 & V_132 ) ) ;
F_150 ( V_1 , V_75 , V_162 ) ;
V_135 = F_151 ( V_42 , V_75 ) ;
if ( V_75 -> V_114 == V_158 && ! V_75 -> V_145 ) {
int V_165 = F_152 ( V_42 ) ;
if ( V_135 == 0 )
V_135 = V_165 ;
}
F_48 ( & V_1 -> V_51 ) ;
V_164 = V_1 -> V_53 & V_157 ;
if ( V_1 -> V_53 & V_163 ) {
if ( ( V_164 & ( V_166 | V_167 ) ) ||
V_75 -> V_114 == V_158 ||
F_41 ( V_1 -> V_53 & V_168 ) ||
F_41 ( F_121 ( V_131 ,
( V_1 -> V_169 +
V_146 * V_147 ) ) ) ) {
V_164 |= V_163 | V_168 ;
F_153 ( V_1 ) ;
}
} else
V_1 -> V_53 &= ~ V_168 ;
V_1 -> V_53 &= ~ V_164 ;
F_118 () ;
if ( F_147 ( V_42 , V_161 ) )
V_1 -> V_53 |= V_170 ;
F_63 ( & V_1 -> V_51 ) ;
if ( V_164 & V_163 )
F_154 ( V_1 ) ;
if ( V_164 & ~ V_170 ) {
int V_165 = F_132 ( V_1 , V_75 ) ;
if ( V_135 == 0 )
V_135 = V_165 ;
}
F_155 ( V_1 , V_75 , V_162 ) ;
return V_135 ;
}
static int F_156 ( struct V_1 * V_1 ,
struct V_74 * V_75 )
{
struct V_5 * V_6 ;
int V_135 = 0 ;
F_48 ( & V_1 -> V_51 ) ;
if ( ! F_33 ( & V_1 -> V_171 ) )
F_149 ( ! ( V_1 -> V_53 & ( V_172 | V_54 ) ) ) ;
else
F_149 ( V_1 -> V_53 & V_172 ) ;
if ( V_1 -> V_53 & V_132 ) {
if ( V_75 -> V_114 != V_158 )
goto V_149;
F_136 ( V_1 ) ;
}
F_149 ( V_1 -> V_53 & V_132 ) ;
if ( ! ( V_1 -> V_53 & V_173 ) &&
( V_75 -> V_114 != V_158 ||
! F_147 ( V_1 -> V_43 , V_174 ) ) )
goto V_149;
V_1 -> V_53 |= V_132 ;
F_76 ( V_75 , V_1 ) ;
V_135 = F_148 ( V_1 , V_75 ) ;
F_78 ( V_75 ) ;
V_6 = F_45 ( V_1 ) ;
F_48 ( & V_1 -> V_51 ) ;
if ( ! ( V_1 -> V_53 & V_173 ) )
F_15 ( V_1 , V_6 ) ;
F_63 ( & V_6 -> V_15 ) ;
F_116 ( V_1 ) ;
V_149:
F_63 ( & V_1 -> V_51 ) ;
return V_135 ;
}
static long F_157 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
long V_175 ;
if ( V_22 -> V_114 == V_158 || V_22 -> V_159 )
V_175 = V_104 ;
else {
V_175 = F_80 ( V_6 -> V_9 / 2 ,
V_176 . V_177 / V_178 ) ;
V_175 = F_80 ( V_175 , V_22 -> V_101 ) ;
V_175 = F_158 ( V_175 + V_179 ,
V_179 ) ;
}
return V_175 ;
}
static long F_159 ( struct V_123 * V_124 ,
struct V_5 * V_6 ,
struct V_21 * V_22 )
{
struct V_74 V_75 = {
. V_114 = V_22 -> V_114 ,
. V_159 = V_22 -> V_159 ,
. V_180 = V_22 -> V_180 ,
. V_181 = V_22 -> V_181 ,
. V_145 = V_22 -> V_145 ,
. V_117 = V_22 -> V_117 ,
. V_182 = 0 ,
. V_183 = V_184 ,
} ;
unsigned long V_185 = V_131 ;
long V_186 ;
long V_187 = 0 ;
while ( ! F_9 ( & V_6 -> V_13 ) ) {
struct V_1 * V_1 = F_1 ( V_6 -> V_13 . V_60 ) ;
struct V_5 * V_188 ;
if ( V_1 -> V_71 != V_124 ) {
if ( V_22 -> V_124 ) {
F_113 ( V_1 , V_6 ) ;
continue;
}
break;
}
F_48 ( & V_1 -> V_51 ) ;
if ( V_1 -> V_53 & ( V_189 | V_54 | V_172 ) ) {
F_63 ( & V_1 -> V_51 ) ;
F_113 ( V_1 , V_6 ) ;
continue;
}
if ( ( V_1 -> V_53 & V_132 ) && V_75 . V_114 != V_158 ) {
F_63 ( & V_1 -> V_51 ) ;
F_115 ( V_1 , V_6 ) ;
F_160 ( V_1 ) ;
continue;
}
F_63 ( & V_6 -> V_15 ) ;
if ( V_1 -> V_53 & V_132 ) {
F_141 ( V_1 ) ;
F_48 ( & V_6 -> V_15 ) ;
continue;
}
V_1 -> V_53 |= V_132 ;
F_76 ( & V_75 , V_1 ) ;
V_186 = F_157 ( V_6 , V_22 ) ;
V_75 . V_162 = V_186 ;
V_75 . V_160 = 0 ;
F_148 ( V_1 , & V_75 ) ;
F_78 ( & V_75 ) ;
V_22 -> V_101 -= V_186 - V_75 . V_162 ;
V_187 += V_186 - V_75 . V_162 ;
if ( F_161 () ) {
F_162 ( V_35 ) ;
F_163 () ;
}
V_188 = F_45 ( V_1 ) ;
F_48 ( & V_1 -> V_51 ) ;
if ( ! ( V_1 -> V_53 & V_173 ) )
V_187 ++ ;
F_146 ( V_1 , V_188 , & V_75 ) ;
F_116 ( V_1 ) ;
F_63 ( & V_1 -> V_51 ) ;
if ( F_41 ( V_188 != V_6 ) ) {
F_63 ( & V_188 -> V_15 ) ;
F_48 ( & V_6 -> V_15 ) ;
}
if ( V_187 ) {
if ( F_164 ( V_185 + V_147 / 10UL ) )
break;
if ( V_22 -> V_101 <= 0 )
break;
}
}
return V_187 ;
}
static long F_165 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
unsigned long V_185 = V_131 ;
long V_187 = 0 ;
while ( ! F_9 ( & V_6 -> V_13 ) ) {
struct V_1 * V_1 = F_1 ( V_6 -> V_13 . V_60 ) ;
struct V_123 * V_124 = V_1 -> V_71 ;
if ( ! F_166 ( V_124 ) ) {
F_113 ( V_1 , V_6 ) ;
continue;
}
V_187 += F_159 ( V_124 , V_6 , V_22 ) ;
F_167 ( & V_124 -> V_190 ) ;
if ( V_187 ) {
if ( F_164 ( V_185 + V_147 / 10UL ) )
break;
if ( V_22 -> V_101 <= 0 )
break;
}
}
return V_187 ;
}
static long F_168 ( struct V_5 * V_6 , long V_101 ,
enum V_118 V_119 )
{
struct V_21 V_22 = {
. V_101 = V_101 ,
. V_114 = V_115 ,
. V_117 = 1 ,
. V_119 = V_119 ,
} ;
struct V_191 V_192 ;
F_169 ( & V_192 ) ;
F_48 ( & V_6 -> V_15 ) ;
if ( F_9 ( & V_6 -> V_13 ) )
F_129 ( V_6 , & V_22 ) ;
F_165 ( V_6 , & V_22 ) ;
F_63 ( & V_6 -> V_15 ) ;
F_170 ( & V_192 ) ;
return V_101 - V_22 . V_101 ;
}
static long F_171 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
unsigned long V_193 = V_131 ;
long V_101 = V_22 -> V_101 ;
unsigned long V_194 ;
struct V_1 * V_1 ;
long V_195 ;
struct V_191 V_192 ;
V_194 = V_131 ;
V_22 -> V_138 = & V_194 ;
F_169 ( & V_192 ) ;
F_48 ( & V_6 -> V_15 ) ;
for (; ; ) {
if ( V_22 -> V_101 <= 0 )
break;
if ( ( V_22 -> V_181 || V_22 -> V_180 ) &&
! F_9 ( & V_6 -> V_29 ) )
break;
if ( V_22 -> V_181 && ! F_172 ( V_6 ) )
break;
if ( V_22 -> V_180 ) {
V_194 = V_131 -
F_173 ( V_196 * 10 ) ;
} else if ( V_22 -> V_181 )
V_194 = V_131 ;
F_174 ( V_6 , V_22 ) ;
if ( F_9 ( & V_6 -> V_13 ) )
F_129 ( V_6 , V_22 ) ;
if ( V_22 -> V_124 )
V_195 = F_159 ( V_22 -> V_124 , V_6 , V_22 ) ;
else
V_195 = F_165 ( V_6 , V_22 ) ;
F_175 ( V_6 , V_22 ) ;
F_176 ( V_6 , V_193 ) ;
if ( V_195 )
continue;
if ( F_9 ( & V_6 -> V_14 ) )
break;
F_177 ( V_6 , V_22 ) ;
V_1 = F_1 ( V_6 -> V_14 . V_60 ) ;
F_48 ( & V_1 -> V_51 ) ;
F_63 ( & V_6 -> V_15 ) ;
F_141 ( V_1 ) ;
F_48 ( & V_6 -> V_15 ) ;
}
F_63 ( & V_6 -> V_15 ) ;
F_170 ( & V_192 ) ;
return V_101 - V_22 -> V_101 ;
}
static struct V_21 * F_178 ( struct V_5 * V_6 )
{
struct V_21 * V_22 = NULL ;
F_18 ( & V_6 -> V_17 ) ;
if ( ! F_9 ( & V_6 -> V_29 ) ) {
V_22 = F_2 ( V_6 -> V_29 . V_130 ,
struct V_21 , V_28 ) ;
F_16 ( & V_22 -> V_28 ) ;
}
F_21 ( & V_6 -> V_17 ) ;
return V_22 ;
}
static unsigned long F_179 ( void )
{
return F_180 ( V_197 ) +
F_180 ( V_198 ) +
F_181 () ;
}
static long F_182 ( struct V_5 * V_6 )
{
if ( F_172 ( V_6 ) ) {
struct V_21 V_22 = {
. V_101 = V_104 ,
. V_114 = V_115 ,
. V_181 = 1 ,
. V_117 = 1 ,
. V_119 = V_199 ,
} ;
return F_171 ( V_6 , & V_22 ) ;
}
return 0 ;
}
static long F_183 ( struct V_5 * V_6 )
{
unsigned long V_200 ;
long V_101 ;
if ( ! V_201 )
return 0 ;
V_200 = V_6 -> V_202 +
F_173 ( V_201 * 10 ) ;
if ( F_114 ( V_131 , V_200 ) )
return 0 ;
V_6 -> V_202 = V_131 ;
V_101 = F_179 () ;
if ( V_101 ) {
struct V_21 V_22 = {
. V_101 = V_101 ,
. V_114 = V_115 ,
. V_180 = 1 ,
. V_117 = 1 ,
. V_119 = V_203 ,
} ;
return F_171 ( V_6 , & V_22 ) ;
}
return 0 ;
}
static long F_184 ( struct V_5 * V_6 )
{
struct V_21 * V_22 ;
long V_187 = 0 ;
F_5 ( V_204 , & V_6 -> V_8 ) ;
while ( ( V_22 = F_178 ( V_6 ) ) != NULL ) {
F_185 ( V_6 , V_22 ) ;
V_187 += F_171 ( V_6 , V_22 ) ;
F_22 ( V_6 , V_22 ) ;
}
V_187 += F_183 ( V_6 ) ;
V_187 += F_182 ( V_6 ) ;
F_10 ( V_204 , & V_6 -> V_8 ) ;
return V_187 ;
}
void F_186 ( struct V_38 * V_22 )
{
struct V_5 * V_6 = F_47 ( F_187 ( V_22 ) ,
struct V_5 , V_20 ) ;
long V_205 ;
F_188 ( L_2 , F_189 ( V_6 -> V_10 -> V_206 ) ) ;
V_35 -> V_125 |= V_207 ;
if ( F_53 ( ! F_190 () ||
! F_19 ( V_18 , & V_6 -> V_8 ) ) ) {
do {
V_205 = F_184 ( V_6 ) ;
F_191 ( V_205 ) ;
} while ( ! F_9 ( & V_6 -> V_29 ) );
} else {
V_205 = F_168 ( V_6 , 1024 ,
V_208 ) ;
F_191 ( V_205 ) ;
}
if ( ! F_9 ( & V_6 -> V_29 ) )
F_20 ( V_19 , & V_6 -> V_20 , 0 ) ;
else if ( F_4 ( V_6 ) && V_201 )
F_192 ( V_6 ) ;
V_35 -> V_125 &= ~ V_207 ;
}
void F_193 ( long V_101 , enum V_118 V_119 )
{
struct V_30 * V_10 ;
if ( F_194 ( V_35 ) )
F_195 ( V_35 ) ;
if ( ! V_101 )
V_101 = F_179 () ;
F_70 () ;
F_196 (bdi, &bdi_list, bdi_list) {
struct V_5 * V_6 ;
if ( ! F_197 ( V_10 ) )
continue;
F_196 (wb, &bdi->wb_list, bdi_node)
F_102 ( V_6 , F_88 ( V_6 , V_101 ) ,
false , V_119 ) ;
}
F_72 () ;
}
static void F_198 ( struct V_38 * V_209 )
{
struct V_30 * V_10 ;
F_70 () ;
F_196 (bdi, &bdi_list, bdi_list) {
struct V_5 * V_6 ;
F_196 (wb, &bdi->wb_list, bdi_node)
if ( ! F_9 ( & V_6 -> V_16 ) )
F_17 ( V_6 ) ;
}
F_72 () ;
F_199 ( & V_210 , V_146 * V_147 ) ;
}
static int T_3 F_200 ( void )
{
F_199 ( & V_210 , V_146 * V_147 ) ;
return 0 ;
}
int F_201 ( struct V_211 * V_212 , int V_213 ,
void T_5 * V_214 , T_2 * V_215 , T_6 * V_216 )
{
int V_135 ;
V_135 = F_202 ( V_212 , V_213 , V_214 , V_215 , V_216 ) ;
if ( V_135 == 0 && V_213 )
F_20 ( V_217 , & V_210 , 0 ) ;
return V_135 ;
}
static T_7 void F_203 ( struct V_1 * V_1 )
{
if ( V_1 -> V_218 || strcmp ( V_1 -> V_71 -> V_219 , L_3 ) ) {
struct V_220 * V_220 ;
const char * V_221 = L_4 ;
V_220 = F_204 ( V_1 ) ;
if ( V_220 ) {
F_48 ( & V_220 -> V_222 ) ;
V_221 = ( const char * ) V_220 -> V_223 . V_221 ;
}
F_205 ( V_224
L_5 ,
V_35 -> V_225 , F_206 ( V_35 ) , V_1 -> V_218 ,
V_221 , V_1 -> V_71 -> V_219 ) ;
if ( V_220 ) {
F_63 ( & V_220 -> V_222 ) ;
F_207 ( V_220 ) ;
}
}
}
void F_208 ( struct V_1 * V_1 , int V_125 )
{
#define F_209 (I_DIRTY_SYNC | I_DIRTY_DATASYNC)
struct V_123 * V_124 = V_1 -> V_71 ;
int V_226 ;
F_210 ( V_1 , V_125 ) ;
if ( V_125 & ( V_166 | V_167 | V_163 ) ) {
F_211 ( V_1 , V_125 ) ;
if ( V_124 -> V_150 -> V_227 )
V_124 -> V_150 -> V_227 ( V_1 , V_125 ) ;
F_212 ( V_1 , V_125 ) ;
}
if ( V_125 & F_209 )
V_125 &= ~ V_163 ;
V_226 = V_125 & V_163 ;
F_118 () ;
if ( ( ( V_1 -> V_53 & V_125 ) == V_125 ) ||
( V_226 && ( V_1 -> V_53 & F_209 ) ) )
return;
if ( F_41 ( V_228 ) )
F_203 ( V_1 ) ;
F_48 ( & V_1 -> V_51 ) ;
if ( V_226 && ( V_1 -> V_53 & F_209 ) )
goto V_229;
if ( ( V_1 -> V_53 & V_125 ) != V_125 ) {
const int V_230 = V_1 -> V_53 & V_157 ;
F_213 ( V_1 , NULL ) ;
if ( V_125 & F_209 )
V_1 -> V_53 &= ~ V_163 ;
V_1 -> V_53 |= V_125 ;
if ( V_1 -> V_53 & V_132 )
goto V_229;
if ( ! F_214 ( V_1 -> V_231 ) ) {
if ( F_215 ( V_1 ) )
goto V_229;
}
if ( V_1 -> V_53 & V_54 )
goto V_229;
if ( ! V_230 ) {
struct V_5 * V_6 ;
struct V_2 * V_232 ;
bool V_233 = false ;
V_6 = F_44 ( V_1 ) ;
F_216 ( F_217 ( V_6 -> V_10 ) &&
! F_19 ( V_18 , & V_6 -> V_8 ) ,
L_6 , V_6 -> V_10 -> V_221 ) ;
V_1 -> V_59 = V_131 ;
if ( V_226 )
V_1 -> V_169 = V_131 ;
if ( V_1 -> V_53 & ( F_209 | V_170 ) )
V_232 = & V_6 -> V_12 ;
else
V_232 = & V_6 -> V_16 ;
V_233 = F_12 ( V_1 , V_6 ,
V_232 ) ;
F_63 ( & V_6 -> V_15 ) ;
F_218 ( V_1 ) ;
if ( F_217 ( V_6 -> V_10 ) && V_233 )
F_192 ( V_6 ) ;
return;
}
}
V_229:
F_63 ( & V_1 -> V_51 ) ;
#undef F_209
}
static void F_219 ( struct V_123 * V_124 )
{
F_125 ( V_234 ) ;
F_149 ( ! F_220 ( & V_124 -> V_190 ) ) ;
F_221 ( & V_124 -> V_235 ) ;
F_70 () ;
F_50 ( & V_124 -> V_127 ) ;
F_130 ( & V_124 -> V_128 , & V_234 ) ;
while ( ! F_9 ( & V_234 ) ) {
struct V_1 * V_1 = F_222 ( & V_234 , struct V_1 ,
V_126 ) ;
struct V_41 * V_42 = V_1 -> V_43 ;
F_223 ( & V_1 -> V_126 , & V_124 -> V_128 ) ;
if ( ! F_147 ( V_42 , V_174 ) )
continue;
F_62 ( & V_124 -> V_127 ) ;
F_48 ( & V_1 -> V_51 ) ;
if ( V_1 -> V_53 & ( V_54 | V_172 | V_189 ) ) {
F_63 ( & V_1 -> V_51 ) ;
F_50 ( & V_124 -> V_127 ) ;
continue;
}
F_74 ( V_1 ) ;
F_63 ( & V_1 -> V_51 ) ;
F_72 () ;
F_224 ( V_42 ) ;
F_163 () ;
F_64 ( V_1 ) ;
F_70 () ;
F_50 ( & V_124 -> V_127 ) ;
}
F_62 ( & V_124 -> V_127 ) ;
F_72 () ;
F_225 ( & V_124 -> V_235 ) ;
}
static void F_226 ( struct V_123 * V_124 , unsigned long V_236 ,
enum V_118 V_119 , bool V_107 )
{
F_94 ( V_24 ) ;
struct V_21 V_22 = {
. V_124 = V_124 ,
. V_114 = V_115 ,
. V_159 = 1 ,
. V_24 = & V_24 ,
. V_101 = V_236 ,
. V_119 = V_119 ,
} ;
struct V_30 * V_10 = V_124 -> V_237 ;
if ( ! F_197 ( V_10 ) || V_10 == & V_238 )
return;
F_149 ( ! F_220 ( & V_124 -> V_190 ) ) ;
F_91 ( V_124 -> V_237 , & V_22 , V_107 ) ;
F_30 ( V_10 , & V_24 ) ;
}
void F_227 ( struct V_123 * V_124 ,
unsigned long V_236 ,
enum V_118 V_119 )
{
F_226 ( V_124 , V_236 , V_119 , false ) ;
}
void F_228 ( struct V_123 * V_124 , enum V_118 V_119 )
{
return F_227 ( V_124 , F_179 () , V_119 ) ;
}
bool F_229 ( struct V_123 * V_124 , unsigned long V_236 ,
enum V_118 V_119 )
{
if ( ! F_230 ( & V_124 -> V_190 ) )
return false ;
F_226 ( V_124 , V_236 , V_119 , true ) ;
F_167 ( & V_124 -> V_190 ) ;
return true ;
}
bool F_231 ( struct V_123 * V_124 , enum V_118 V_119 )
{
return F_229 ( V_124 , F_179 () , V_119 ) ;
}
void F_232 ( struct V_123 * V_124 )
{
F_94 ( V_24 ) ;
struct V_21 V_22 = {
. V_124 = V_124 ,
. V_114 = V_158 ,
. V_101 = V_104 ,
. V_117 = 0 ,
. V_24 = & V_24 ,
. V_119 = V_239 ,
. V_145 = 1 ,
} ;
struct V_30 * V_10 = V_124 -> V_237 ;
if ( V_10 == & V_238 )
return;
F_149 ( ! F_220 ( & V_124 -> V_190 ) ) ;
F_91 ( V_10 , & V_22 , false ) ;
F_30 ( V_10 , & V_24 ) ;
F_219 ( V_124 ) ;
}
int F_233 ( struct V_1 * V_1 , int V_240 )
{
struct V_74 V_75 = {
. V_162 = V_104 ,
. V_114 = V_240 ? V_158 : V_115 ,
. V_182 = 0 ,
. V_183 = V_184 ,
} ;
if ( ! F_234 ( V_1 -> V_43 ) )
V_75 . V_162 = 0 ;
F_92 () ;
return F_156 ( V_1 , & V_75 ) ;
}
int F_235 ( struct V_1 * V_1 , struct V_74 * V_75 )
{
return F_156 ( V_1 , V_75 ) ;
}
int F_236 ( struct V_1 * V_1 , int V_155 )
{
struct V_74 V_75 = {
. V_114 = V_155 ? V_158 : V_115 ,
. V_162 = 0 ,
} ;
return F_235 ( V_1 , & V_75 ) ;
}
