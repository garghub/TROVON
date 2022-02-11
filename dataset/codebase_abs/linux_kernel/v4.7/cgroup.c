static bool F_1 ( int V_1 )
{
if ( V_2 == 0 )
return false ;
return F_2 ( V_3 [ V_1 ] ) ;
}
static bool F_3 ( int V_1 )
{
return V_4 & ( 1 << V_1 ) ;
}
static bool F_4 ( const struct V_5 * V_6 )
{
return V_6 -> V_7 == & V_8 ;
}
static int F_5 ( struct V_9 * V_9 , void * V_10 , int V_11 , int V_12 ,
T_1 V_13 )
{
int V_14 ;
F_6 ( V_13 ) ;
F_7 ( & V_15 ) ;
V_14 = F_8 ( V_9 , V_10 , V_11 , V_12 , V_13 & ~ V_16 ) ;
F_9 ( & V_15 ) ;
F_10 () ;
return V_14 ;
}
static void * F_11 ( struct V_9 * V_9 , void * V_10 , int V_17 )
{
void * V_14 ;
F_7 ( & V_15 ) ;
V_14 = F_12 ( V_9 , V_10 , V_17 ) ;
F_9 ( & V_15 ) ;
return V_14 ;
}
static void F_13 ( struct V_9 * V_9 , int V_17 )
{
F_7 ( & V_15 ) ;
F_14 ( V_9 , V_17 ) ;
F_9 ( & V_15 ) ;
}
static struct V_5 * F_15 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 . V_21 ;
if ( V_19 )
return F_16 ( V_19 , struct V_5 , V_20 ) ;
return NULL ;
}
static T_2 F_17 ( struct V_5 * V_6 )
{
struct V_5 * V_21 = F_15 ( V_6 ) ;
T_2 V_22 = V_6 -> V_7 -> V_23 ;
if ( V_21 )
return V_21 -> V_24 ;
if ( F_4 ( V_6 ) )
V_22 &= ~ ( V_25 |
V_26 ) ;
return V_22 ;
}
static T_2 F_18 ( struct V_5 * V_6 )
{
struct V_5 * V_21 = F_15 ( V_6 ) ;
if ( V_21 )
return V_21 -> V_27 ;
return V_6 -> V_7 -> V_23 ;
}
static struct V_18 * F_19 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
if ( V_29 )
return F_20 ( V_6 -> V_30 [ V_29 -> V_17 ] ,
F_21 ( & V_31 ) ) ;
else
return & V_6 -> V_20 ;
}
static struct V_18 * F_22 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
F_23 ( & V_31 ) ;
if ( ! V_29 )
return & V_6 -> V_20 ;
while ( ! ( F_18 ( V_6 ) & ( 1 << V_29 -> V_17 ) ) ) {
V_6 = F_15 ( V_6 ) ;
if ( ! V_6 )
return NULL ;
}
return F_19 ( V_6 , V_29 ) ;
}
struct V_18 * F_24 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
struct V_18 * V_32 ;
F_25 () ;
do {
V_32 = F_19 ( V_6 , V_29 ) ;
if ( V_32 && F_26 ( V_32 ) )
goto V_33;
V_6 = F_15 ( V_6 ) ;
} while ( V_6 );
V_32 = V_34 . V_30 [ V_29 -> V_17 ] ;
F_27 ( V_32 ) ;
V_33:
F_28 () ;
return V_32 ;
}
static inline bool F_29 ( const struct V_5 * V_6 )
{
return ! ( V_6 -> V_20 . V_35 & V_36 ) ;
}
static void F_30 ( struct V_5 * V_6 )
{
F_31 ( F_29 ( V_6 ) ) ;
F_27 ( & V_6 -> V_20 ) ;
}
static bool F_32 ( struct V_5 * V_6 )
{
return F_33 ( & V_6 -> V_20 ) ;
}
struct V_18 * F_34 ( struct V_37 * V_38 )
{
struct V_5 * V_6 = V_38 -> V_39 -> V_21 -> V_40 ;
struct V_41 * V_42 = F_35 ( V_38 ) ;
if ( V_42 -> V_29 )
return F_36 ( V_6 -> V_30 [ V_42 -> V_29 -> V_17 ] ) ;
else
return & V_6 -> V_20 ;
}
static int F_37 ( const struct V_5 * V_6 )
{
return F_38 ( V_43 , & V_6 -> V_35 ) ;
}
static bool F_39 ( struct V_44 * V_45 )
{
F_23 ( & V_46 ) ;
return ! F_40 ( & V_45 -> V_47 ) || ! F_40 ( & V_45 -> V_48 ) ;
}
static void F_41 ( struct V_5 * V_6 , bool V_49 )
{
F_23 ( & V_46 ) ;
do {
bool V_50 ;
if ( V_49 )
V_50 = ! V_6 -> V_51 ++ ;
else
V_50 = ! -- V_6 -> V_51 ;
if ( ! V_50 )
break;
F_42 ( V_6 ) ;
F_43 ( & V_6 -> V_52 ) ;
V_6 = F_15 ( V_6 ) ;
} while ( V_6 );
}
static void F_44 ( struct V_44 * V_45 , bool V_49 )
{
struct V_53 * V_54 ;
F_23 ( & V_46 ) ;
F_45 (link, &cset->cgrp_links, cgrp_link)
F_41 ( V_54 -> V_6 , V_49 ) ;
}
static void F_46 ( struct V_55 * V_56 ,
struct V_44 * V_57 , struct V_44 * V_58 ,
bool V_59 )
{
F_23 ( & V_46 ) ;
if ( V_58 && ! F_39 ( V_58 ) )
F_44 ( V_58 , true ) ;
if ( V_57 ) {
struct V_60 * V_61 , * V_62 ;
F_31 ( F_40 ( & V_56 -> V_63 ) ) ;
F_47 (it, pos, &from_cset->task_iters,
iters_node)
if ( V_61 -> V_64 == & V_56 -> V_63 )
F_48 ( V_61 ) ;
F_49 ( & V_56 -> V_63 ) ;
if ( ! F_39 ( V_57 ) )
F_44 ( V_57 , false ) ;
} else {
F_31 ( ! F_40 ( & V_56 -> V_63 ) ) ;
}
if ( V_58 ) {
F_31 ( V_56 -> V_35 & V_65 ) ;
F_50 ( V_56 -> V_66 , V_58 ) ;
F_51 ( & V_56 -> V_63 , V_59 ? & V_58 -> V_48 :
& V_58 -> V_47 ) ;
}
}
static unsigned long F_52 ( struct V_18 * V_32 [] )
{
unsigned long V_67 = 0UL ;
struct V_28 * V_29 ;
int V_68 ;
F_53 (ss, i)
V_67 += ( unsigned long ) V_32 [ V_68 ] ;
V_67 = ( V_67 >> 16 ) ^ V_67 ;
return V_67 ;
}
static void F_54 ( struct V_44 * V_45 )
{
struct V_53 * V_54 , * V_69 ;
struct V_28 * V_29 ;
int V_1 ;
F_23 ( & V_46 ) ;
if ( ! F_55 ( & V_45 -> V_70 ) )
return;
F_53 (ss, ssid) {
F_56 ( & V_45 -> V_71 [ V_1 ] ) ;
F_57 ( V_45 -> V_30 [ V_1 ] ) ;
}
F_58 ( & V_45 -> V_72 ) ;
V_73 -- ;
F_47 (link, tmp_link, &cset->cgrp_links, cgrp_link) {
F_56 ( & V_54 -> V_74 ) ;
F_56 ( & V_54 -> V_75 ) ;
if ( F_15 ( V_54 -> V_6 ) )
F_59 ( V_54 -> V_6 ) ;
F_60 ( V_54 ) ;
}
F_61 ( V_45 , V_76 ) ;
}
static void F_62 ( struct V_44 * V_45 )
{
unsigned long V_35 ;
if ( F_63 ( & V_45 -> V_70 , - 1 , 1 ) )
return;
F_64 ( & V_46 , V_35 ) ;
F_54 ( V_45 ) ;
F_65 ( & V_46 , V_35 ) ;
}
static inline void F_66 ( struct V_44 * V_45 )
{
F_67 ( & V_45 -> V_70 ) ;
}
static bool F_68 ( struct V_44 * V_45 ,
struct V_44 * V_77 ,
struct V_5 * V_78 ,
struct V_18 * V_79 [] )
{
struct V_80 * V_81 , * V_82 ;
if ( memcmp ( V_79 , V_45 -> V_30 , sizeof( V_45 -> V_30 ) ) )
return false ;
V_81 = & V_45 -> V_83 ;
V_82 = & V_77 -> V_83 ;
while ( 1 ) {
struct V_53 * V_84 , * V_85 ;
struct V_5 * V_86 , * V_87 ;
V_81 = V_81 -> V_88 ;
V_82 = V_82 -> V_88 ;
if ( V_81 == & V_45 -> V_83 ) {
F_69 ( V_82 != & V_77 -> V_83 ) ;
break;
} else {
F_69 ( V_82 == & V_77 -> V_83 ) ;
}
V_84 = F_70 ( V_81 , struct V_53 , V_75 ) ;
V_85 = F_70 ( V_82 , struct V_53 , V_75 ) ;
V_86 = V_84 -> V_6 ;
V_87 = V_85 -> V_6 ;
F_69 ( V_86 -> V_7 != V_87 -> V_7 ) ;
if ( V_86 -> V_7 == V_78 -> V_7 ) {
if ( V_86 != V_78 )
return false ;
} else {
if ( V_86 != V_87 )
return false ;
}
}
return true ;
}
static struct V_44 * F_71 ( struct V_44 * V_77 ,
struct V_5 * V_6 ,
struct V_18 * V_79 [] )
{
struct V_89 * V_7 = V_6 -> V_7 ;
struct V_28 * V_29 ;
struct V_44 * V_45 ;
unsigned long V_67 ;
int V_68 ;
F_53 (ss, i) {
if ( V_7 -> V_23 & ( 1UL << V_68 ) ) {
V_79 [ V_68 ] = F_22 ( V_6 , V_29 ) ;
} else {
V_79 [ V_68 ] = V_77 -> V_30 [ V_68 ] ;
}
}
V_67 = F_52 ( V_79 ) ;
F_72 (css_set_table, cset, hlist, key) {
if ( ! F_68 ( V_45 , V_77 , V_6 , V_79 ) )
continue;
return V_45 ;
}
return NULL ;
}
static void F_73 ( struct V_80 * V_90 )
{
struct V_53 * V_54 , * V_69 ;
F_47 (link, tmp_link, links_to_free, cset_link) {
F_56 ( & V_54 -> V_74 ) ;
F_60 ( V_54 ) ;
}
}
static int F_74 ( int V_91 , struct V_80 * V_92 )
{
struct V_53 * V_54 ;
int V_68 ;
F_75 ( V_92 ) ;
for ( V_68 = 0 ; V_68 < V_91 ; V_68 ++ ) {
V_54 = F_76 ( sizeof( * V_54 ) , V_93 ) ;
if ( ! V_54 ) {
F_73 ( V_92 ) ;
return - V_94 ;
}
F_77 ( & V_54 -> V_74 , V_92 ) ;
}
return 0 ;
}
static void F_78 ( struct V_80 * V_92 , struct V_44 * V_45 ,
struct V_5 * V_6 )
{
struct V_53 * V_54 ;
F_69 ( F_40 ( V_92 ) ) ;
if ( F_4 ( V_6 ) )
V_45 -> V_95 = V_6 ;
V_54 = F_79 ( V_92 , struct V_53 , V_74 ) ;
V_54 -> V_45 = V_45 ;
V_54 -> V_6 = V_6 ;
F_80 ( & V_54 -> V_74 , & V_6 -> V_96 ) ;
F_51 ( & V_54 -> V_75 , & V_45 -> V_83 ) ;
if ( F_15 ( V_6 ) )
F_30 ( V_6 ) ;
}
static struct V_44 * F_81 ( struct V_44 * V_77 ,
struct V_5 * V_6 )
{
struct V_18 * V_79 [ V_2 ] = { } ;
struct V_44 * V_45 ;
struct V_80 V_92 ;
struct V_53 * V_54 ;
struct V_28 * V_29 ;
unsigned long V_67 ;
int V_1 ;
F_23 ( & V_31 ) ;
F_82 ( & V_46 ) ;
V_45 = F_71 ( V_77 , V_6 , V_79 ) ;
if ( V_45 )
F_66 ( V_45 ) ;
F_83 ( & V_46 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_76 ( sizeof( * V_45 ) , V_93 ) ;
if ( ! V_45 )
return NULL ;
if ( F_74 ( V_97 , & V_92 ) < 0 ) {
F_60 ( V_45 ) ;
return NULL ;
}
F_84 ( & V_45 -> V_70 , 1 ) ;
F_75 ( & V_45 -> V_83 ) ;
F_75 ( & V_45 -> V_47 ) ;
F_75 ( & V_45 -> V_48 ) ;
F_75 ( & V_45 -> V_98 ) ;
F_75 ( & V_45 -> V_99 ) ;
F_75 ( & V_45 -> V_100 ) ;
F_85 ( & V_45 -> V_72 ) ;
memcpy ( V_45 -> V_30 , V_79 , sizeof( V_45 -> V_30 ) ) ;
F_82 ( & V_46 ) ;
F_45 (link, &old_cset->cgrp_links, cgrp_link) {
struct V_5 * V_101 = V_54 -> V_6 ;
if ( V_101 -> V_7 == V_6 -> V_7 )
V_101 = V_6 ;
F_78 ( & V_92 , V_45 , V_101 ) ;
}
F_69 ( ! F_40 ( & V_92 ) ) ;
V_73 ++ ;
V_67 = F_52 ( V_45 -> V_30 ) ;
F_86 ( V_102 , & V_45 -> V_72 , V_67 ) ;
F_53 (ss, ssid) {
struct V_18 * V_32 = V_45 -> V_30 [ V_1 ] ;
F_51 ( & V_45 -> V_71 [ V_1 ] ,
& V_32 -> V_5 -> V_103 [ V_1 ] ) ;
F_27 ( V_32 ) ;
}
F_83 ( & V_46 ) ;
return V_45 ;
}
static struct V_89 * F_87 ( struct V_104 * V_105 )
{
struct V_5 * V_106 = V_105 -> V_39 -> V_40 ;
return V_106 -> V_7 ;
}
static int F_88 ( struct V_89 * V_7 )
{
int V_17 ;
F_23 ( & V_31 ) ;
V_17 = F_89 ( & V_107 , V_7 , 0 , 0 , V_93 ) ;
if ( V_17 < 0 )
return V_17 ;
V_7 -> V_108 = V_17 ;
return 0 ;
}
static void F_90 ( struct V_89 * V_7 )
{
F_23 ( & V_31 ) ;
if ( V_7 -> V_108 ) {
F_14 ( & V_107 , V_7 -> V_108 ) ;
V_7 -> V_108 = 0 ;
}
}
static void F_91 ( struct V_89 * V_7 )
{
if ( V_7 ) {
F_31 ( V_7 -> V_108 ) ;
F_92 ( & V_7 -> V_109 ) ;
F_60 ( V_7 ) ;
}
}
static void F_93 ( struct V_89 * V_7 )
{
struct V_5 * V_6 = & V_7 -> V_6 ;
struct V_53 * V_54 , * V_69 ;
F_94 ( & V_8 . V_6 ) ;
F_69 ( F_95 ( & V_7 -> V_110 ) ) ;
F_69 ( ! F_40 ( & V_6 -> V_20 . V_111 ) ) ;
F_96 ( F_97 ( & V_8 , V_7 -> V_23 ) ) ;
F_82 ( & V_46 ) ;
F_47 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_56 ( & V_54 -> V_74 ) ;
F_56 ( & V_54 -> V_75 ) ;
F_60 ( V_54 ) ;
}
F_83 ( & V_46 ) ;
if ( ! F_40 ( & V_7 -> V_112 ) ) {
F_56 ( & V_7 -> V_112 ) ;
V_97 -- ;
}
F_90 ( V_7 ) ;
F_98 ( & V_31 ) ;
F_99 ( V_7 -> V_105 ) ;
F_91 ( V_7 ) ;
}
static struct V_5 *
F_100 ( struct V_89 * V_7 )
{
struct V_5 * V_113 = NULL ;
struct V_44 * V_45 ;
F_23 ( & V_46 ) ;
F_25 () ;
V_45 = V_114 -> V_115 -> V_116 -> V_117 ;
if ( V_45 == & V_34 ) {
V_113 = & V_7 -> V_6 ;
} else {
struct V_53 * V_54 ;
F_45 (link, &cset->cgrp_links, cgrp_link) {
struct V_5 * V_101 = V_54 -> V_6 ;
if ( V_101 -> V_7 == V_7 ) {
V_113 = V_101 ;
break;
}
}
}
F_28 () ;
F_69 ( ! V_113 ) ;
return V_113 ;
}
static struct V_5 * F_101 ( struct V_44 * V_45 ,
struct V_89 * V_7 )
{
struct V_5 * V_113 = NULL ;
F_23 ( & V_31 ) ;
F_23 ( & V_46 ) ;
if ( V_45 == & V_34 ) {
V_113 = & V_7 -> V_6 ;
} else {
struct V_53 * V_54 ;
F_45 (link, &cset->cgrp_links, cgrp_link) {
struct V_5 * V_101 = V_54 -> V_6 ;
if ( V_101 -> V_7 == V_7 ) {
V_113 = V_101 ;
break;
}
}
}
F_69 ( ! V_113 ) ;
return V_113 ;
}
static struct V_5 * F_102 ( struct V_55 * V_56 ,
struct V_89 * V_7 )
{
return F_101 ( F_103 ( V_56 ) , V_7 ) ;
}
static char * F_104 ( struct V_5 * V_6 , const struct V_41 * V_42 ,
char * V_118 )
{
struct V_28 * V_29 = V_42 -> V_29 ;
if ( V_42 -> V_29 && ! ( V_42 -> V_35 & V_119 ) &&
! ( V_6 -> V_7 -> V_35 & V_120 ) )
snprintf ( V_118 , V_121 , L_1 ,
F_4 ( V_6 ) ? V_29 -> V_122 : V_29 -> V_123 ,
V_42 -> V_122 ) ;
else
strncpy ( V_118 , V_42 -> V_122 , V_121 ) ;
return V_118 ;
}
static T_3 F_105 ( const struct V_41 * V_42 )
{
T_3 V_124 = 0 ;
if ( V_42 -> V_125 || V_42 -> V_126 || V_42 -> V_127 )
V_124 |= V_128 ;
if ( V_42 -> V_129 || V_42 -> V_130 || V_42 -> V_131 ) {
if ( V_42 -> V_35 & V_132 )
V_124 |= V_133 ;
else
V_124 |= V_134 ;
}
return V_124 ;
}
static T_2 F_106 ( T_2 V_24 , T_2 V_135 )
{
T_2 V_136 = V_24 ;
struct V_28 * V_29 ;
int V_1 ;
F_23 ( & V_31 ) ;
V_136 |= V_26 ;
while ( true ) {
T_2 V_137 = V_136 ;
F_107 (ss, ssid, cur_ss_mask) {
V_137 |= V_29 -> V_138 ;
} F_108 () ;
V_137 &= V_135 ;
if ( V_137 == V_136 )
break;
V_136 = V_137 ;
}
return V_136 ;
}
static void F_109 ( struct V_139 * V_39 )
{
struct V_5 * V_6 ;
if ( F_110 ( V_39 ) == V_140 )
V_6 = V_39 -> V_40 ;
else
V_6 = V_39 -> V_21 -> V_40 ;
F_98 ( & V_31 ) ;
F_111 ( V_39 ) ;
F_59 ( V_6 ) ;
}
static struct V_5 * F_112 ( struct V_139 * V_39 ,
bool V_141 )
{
struct V_5 * V_6 ;
if ( F_110 ( V_39 ) == V_140 )
V_6 = V_39 -> V_40 ;
else
V_6 = V_39 -> V_21 -> V_40 ;
if ( ! F_32 ( V_6 ) )
return NULL ;
F_113 ( V_39 ) ;
if ( V_141 )
F_94 ( V_6 ) ;
else
F_114 ( & V_31 ) ;
if ( ! F_29 ( V_6 ) )
return V_6 ;
F_109 ( V_39 ) ;
return NULL ;
}
static void F_115 ( struct V_5 * V_6 , const struct V_41 * V_42 )
{
char V_122 [ V_121 ] ;
F_23 ( & V_31 ) ;
if ( V_42 -> V_142 ) {
struct V_18 * V_32 = F_19 ( V_6 , V_42 -> V_29 ) ;
struct V_143 * V_144 = ( void * ) V_32 + V_42 -> V_142 ;
F_82 ( & V_145 ) ;
V_144 -> V_39 = NULL ;
F_83 ( & V_145 ) ;
}
F_116 ( V_6 -> V_39 , F_104 ( V_6 , V_42 , V_122 ) ) ;
}
static void F_117 ( struct V_18 * V_32 )
{
struct V_5 * V_6 = V_32 -> V_5 ;
struct V_41 * V_146 ;
if ( ! ( V_32 -> V_35 & V_147 ) )
return;
V_32 -> V_35 &= ~ V_147 ;
F_45 (cfts, &css->ss->cfts, node)
F_118 ( V_32 , V_6 , V_146 , false ) ;
}
static int F_119 ( struct V_18 * V_32 )
{
struct V_5 * V_6 = V_32 -> V_5 ;
struct V_41 * V_146 , * V_148 ;
int V_14 ;
if ( ( V_32 -> V_35 & V_147 ) || ! V_6 -> V_39 )
return 0 ;
if ( ! V_32 -> V_29 ) {
if ( F_4 ( V_6 ) )
V_146 = V_149 ;
else
V_146 = V_150 ;
return F_118 ( & V_6 -> V_20 , V_6 , V_146 , true ) ;
}
F_45 (cfts, &css->ss->cfts, node) {
V_14 = F_118 ( V_32 , V_6 , V_146 , true ) ;
if ( V_14 < 0 ) {
V_148 = V_146 ;
goto V_151;
}
}
V_32 -> V_35 |= V_147 ;
return 0 ;
V_151:
F_45 (cfts, &css->ss->cfts, node) {
if ( V_146 == V_148 )
break;
F_118 ( V_32 , V_6 , V_146 , false ) ;
}
return V_14 ;
}
static int F_97 ( struct V_89 * V_152 , T_2 V_153 )
{
struct V_5 * V_154 = & V_152 -> V_6 ;
struct V_28 * V_29 ;
int V_1 , V_68 , V_14 ;
F_23 ( & V_31 ) ;
F_107 (ss, ssid, ss_mask) {
if ( F_120 ( NULL , F_19 ( & V_29 -> V_7 -> V_6 , V_29 ) ) &&
! V_29 -> V_155 )
return - V_156 ;
if ( V_29 -> V_7 != & V_8 && V_152 != & V_8 )
return - V_156 ;
} F_108 () ;
F_107 (ss, ssid, ss_mask) {
struct V_89 * V_157 = V_29 -> V_7 ;
struct V_5 * V_158 = & V_157 -> V_6 ;
struct V_18 * V_32 = F_19 ( V_158 , V_29 ) ;
struct V_44 * V_45 ;
F_96 ( ! V_32 || F_19 ( V_154 , V_29 ) ) ;
V_157 -> V_23 &= ~ ( 1 << V_1 ) ;
F_96 ( F_121 ( V_158 ) ) ;
F_122 ( V_158 , 0 ) ;
F_123 ( V_158 -> V_30 [ V_1 ] , NULL ) ;
F_50 ( V_154 -> V_30 [ V_1 ] , V_32 ) ;
V_29 -> V_7 = V_152 ;
V_32 -> V_5 = V_154 ;
F_82 ( & V_46 ) ;
F_124 (css_set_table, i, cset, hlist)
F_80 ( & V_45 -> V_71 [ V_29 -> V_17 ] ,
& V_154 -> V_103 [ V_29 -> V_17 ] ) ;
F_83 ( & V_46 ) ;
V_152 -> V_23 |= 1 << V_1 ;
if ( V_152 == & V_8 ) {
F_125 ( V_159 [ V_1 ] ) ;
} else {
V_154 -> V_24 |= 1 << V_1 ;
F_126 ( V_159 [ V_1 ] ) ;
}
V_14 = F_121 ( V_154 ) ;
if ( V_14 )
F_127 ( L_2 ,
V_29 -> V_122 , V_14 ) ;
if ( V_29 -> V_160 )
V_29 -> V_160 ( V_32 ) ;
} F_108 () ;
F_128 ( V_154 -> V_39 ) ;
return 0 ;
}
static int F_129 ( struct V_161 * V_162 , struct V_139 * V_163 ,
struct V_104 * V_105 )
{
int V_164 = 0 ;
char * V_118 = NULL ;
struct V_89 * V_165 = F_87 ( V_105 ) ;
struct V_5 * V_166 ;
V_118 = F_130 ( V_167 , V_93 ) ;
if ( ! V_118 )
return - V_94 ;
F_82 ( & V_46 ) ;
V_166 = F_100 ( V_165 ) ;
V_164 = F_131 ( V_163 , V_166 -> V_39 , V_118 , V_167 ) ;
F_83 ( & V_46 ) ;
if ( V_164 >= V_167 )
V_164 = - V_168 ;
else if ( V_164 > 0 ) {
F_132 ( V_162 , V_118 , L_3 ) ;
V_164 = 0 ;
}
F_60 ( V_118 ) ;
return V_164 ;
}
static int F_133 ( struct V_161 * V_169 ,
struct V_104 * V_105 )
{
struct V_89 * V_7 = F_87 ( V_105 ) ;
struct V_28 * V_29 ;
int V_1 ;
if ( V_7 != & V_8 )
F_53 (ss, ssid)
if ( V_7 -> V_23 & ( 1 << V_1 ) )
F_134 ( V_169 , V_29 -> V_123 , NULL ) ;
if ( V_7 -> V_35 & V_120 )
F_135 ( V_169 , L_4 ) ;
if ( V_7 -> V_35 & V_170 )
F_135 ( V_169 , L_5 ) ;
F_136 ( & V_171 ) ;
if ( strlen ( V_7 -> V_172 ) )
F_134 ( V_169 , L_6 ,
V_7 -> V_172 ) ;
F_137 ( & V_171 ) ;
if ( F_38 ( V_173 , & V_7 -> V_6 . V_35 ) )
F_135 ( V_169 , L_7 ) ;
if ( strlen ( V_7 -> V_122 ) )
F_134 ( V_169 , L_8 , V_7 -> V_122 ) ;
return 0 ;
}
static int F_138 ( char * V_174 , struct V_175 * V_176 )
{
char * V_177 , * V_178 = V_174 ;
bool V_179 = false , V_180 = false ;
T_2 V_181 = V_182 ;
struct V_28 * V_29 ;
int V_183 = 0 ;
int V_68 ;
#ifdef F_139
V_181 = ~ ( ( T_2 ) 1 << V_184 ) ;
#endif
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
while ( ( V_177 = F_140 ( & V_178 , L_9 ) ) != NULL ) {
V_183 ++ ;
if ( ! * V_177 )
return - V_185 ;
if ( ! strcmp ( V_177 , L_10 ) ) {
V_176 -> V_186 = true ;
continue;
}
if ( ! strcmp ( V_177 , L_11 ) ) {
if ( V_180 )
return - V_185 ;
V_179 = true ;
continue;
}
if ( ! strcmp ( V_177 , L_12 ) ) {
V_176 -> V_35 |= V_120 ;
continue;
}
if ( ! strcmp ( V_177 , L_13 ) ) {
V_176 -> V_187 = true ;
continue;
}
if ( ! strcmp ( V_177 , L_14 ) ) {
V_176 -> V_35 |= V_170 ;
continue;
}
if ( ! strncmp ( V_177 , L_15 , 14 ) ) {
if ( V_176 -> V_188 )
return - V_185 ;
V_176 -> V_188 =
F_141 ( V_177 + 14 , V_167 - 1 , V_93 ) ;
if ( ! V_176 -> V_188 )
return - V_94 ;
continue;
}
if ( ! strncmp ( V_177 , L_16 , 5 ) ) {
const char * V_122 = V_177 + 5 ;
if ( ! strlen ( V_122 ) )
return - V_185 ;
for ( V_68 = 0 ; V_68 < strlen ( V_122 ) ; V_68 ++ ) {
char V_101 = V_122 [ V_68 ] ;
if ( isalnum ( V_101 ) )
continue;
if ( ( V_101 == '.' ) || ( V_101 == '-' ) || ( V_101 == '_' ) )
continue;
return - V_185 ;
}
if ( V_176 -> V_122 )
return - V_185 ;
V_176 -> V_122 = F_141 ( V_122 ,
V_189 - 1 ,
V_93 ) ;
if ( ! V_176 -> V_122 )
return - V_94 ;
continue;
}
F_53 (ss, i) {
if ( strcmp ( V_177 , V_29 -> V_123 ) )
continue;
if ( ! F_1 ( V_68 ) )
continue;
if ( F_3 ( V_68 ) )
continue;
if ( V_179 )
return - V_185 ;
V_176 -> V_23 |= ( 1 << V_68 ) ;
V_180 = true ;
break;
}
if ( V_68 == V_2 )
return - V_190 ;
}
if ( V_179 || ( ! V_180 && ! V_176 -> V_186 && ! V_176 -> V_122 ) )
F_53 (ss, i)
if ( F_1 ( V_68 ) && ! F_3 ( V_68 ) )
V_176 -> V_23 |= ( 1 << V_68 ) ;
if ( ! V_176 -> V_23 && ! V_176 -> V_122 )
return - V_185 ;
if ( ( V_176 -> V_35 & V_120 ) && ( V_176 -> V_23 & V_181 ) )
return - V_185 ;
if ( V_176 -> V_23 && V_176 -> V_186 )
return - V_185 ;
return 0 ;
}
static int F_142 ( struct V_104 * V_105 , int * V_35 , char * V_174 )
{
int V_14 = 0 ;
struct V_89 * V_7 = F_87 ( V_105 ) ;
struct V_175 V_176 ;
T_2 V_191 , V_192 ;
if ( V_7 == & V_8 ) {
F_143 ( L_17 ) ;
return - V_185 ;
}
F_94 ( & V_8 . V_6 ) ;
V_14 = F_138 ( V_174 , & V_176 ) ;
if ( V_14 )
goto V_33;
if ( V_176 . V_23 != V_7 -> V_23 || V_176 . V_188 )
F_127 ( L_18 ,
F_144 ( V_114 ) , V_114 -> V_193 ) ;
V_191 = V_176 . V_23 & ~ V_7 -> V_23 ;
V_192 = V_7 -> V_23 & ~ V_176 . V_23 ;
if ( ( V_176 . V_35 ^ V_7 -> V_35 ) ||
( V_176 . V_122 && strcmp ( V_176 . V_122 , V_7 -> V_122 ) ) ) {
F_143 ( L_19 ,
V_176 . V_35 , V_176 . V_122 ? : L_20 , V_7 -> V_35 , V_7 -> V_122 ) ;
V_14 = - V_185 ;
goto V_33;
}
if ( ! F_40 ( & V_7 -> V_6 . V_20 . V_111 ) ) {
V_14 = - V_156 ;
goto V_33;
}
V_14 = F_97 ( V_7 , V_191 ) ;
if ( V_14 )
goto V_33;
F_96 ( F_97 ( & V_8 , V_192 ) ) ;
if ( V_176 . V_188 ) {
F_136 ( & V_171 ) ;
strcpy ( V_7 -> V_172 , V_176 . V_188 ) ;
F_137 ( & V_171 ) ;
}
V_33:
F_60 ( V_176 . V_188 ) ;
F_60 ( V_176 . V_122 ) ;
F_98 ( & V_31 ) ;
return V_14 ;
}
static void F_145 ( void )
{
struct V_55 * V_194 , * V_195 ;
F_82 ( & V_46 ) ;
if ( V_196 )
goto V_33;
V_196 = true ;
F_146 ( & V_197 ) ;
F_147 (g, p) {
F_31 ( ! F_40 ( & V_194 -> V_63 ) ||
F_103 ( V_194 ) != & V_34 ) ;
F_136 ( & V_194 -> V_198 -> V_199 ) ;
if ( ! ( V_194 -> V_35 & V_65 ) ) {
struct V_44 * V_45 = F_103 ( V_194 ) ;
if ( ! F_39 ( V_45 ) )
F_44 ( V_45 , true ) ;
F_51 ( & V_194 -> V_63 , & V_45 -> V_47 ) ;
F_66 ( V_45 ) ;
}
F_137 ( & V_194 -> V_198 -> V_199 ) ;
} F_148 ( V_195 , V_194 ) ;
F_149 ( & V_197 ) ;
V_33:
F_83 ( & V_46 ) ;
}
static void F_150 ( struct V_5 * V_6 )
{
struct V_28 * V_29 ;
int V_1 ;
F_75 ( & V_6 -> V_20 . V_200 ) ;
F_75 ( & V_6 -> V_20 . V_111 ) ;
F_75 ( & V_6 -> V_96 ) ;
F_75 ( & V_6 -> V_201 ) ;
F_151 ( & V_6 -> V_202 ) ;
V_6 -> V_20 . V_5 = V_6 ;
V_6 -> V_20 . V_35 |= V_36 ;
F_53 (ss, ssid)
F_75 ( & V_6 -> V_103 [ V_1 ] ) ;
F_152 ( & V_6 -> V_203 ) ;
F_153 ( & V_6 -> V_204 , V_205 ) ;
}
static void F_154 ( struct V_89 * V_7 ,
struct V_175 * V_176 )
{
struct V_5 * V_6 = & V_7 -> V_6 ;
F_75 ( & V_7 -> V_112 ) ;
F_84 ( & V_7 -> V_110 , 1 ) ;
V_6 -> V_7 = V_7 ;
F_150 ( V_6 ) ;
F_155 ( & V_7 -> V_109 ) ;
V_7 -> V_35 = V_176 -> V_35 ;
if ( V_176 -> V_188 )
strcpy ( V_7 -> V_172 , V_176 -> V_188 ) ;
if ( V_176 -> V_122 )
strcpy ( V_7 -> V_122 , V_176 -> V_122 ) ;
if ( V_176 -> V_187 )
F_156 ( V_173 , & V_7 -> V_6 . V_35 ) ;
}
static int F_157 ( struct V_89 * V_7 , T_2 V_153 )
{
F_158 ( V_92 ) ;
struct V_5 * V_106 = & V_7 -> V_6 ;
struct V_44 * V_45 ;
int V_68 , V_14 ;
F_23 ( & V_31 ) ;
V_14 = F_5 ( & V_7 -> V_109 , V_106 , 1 , 2 , V_93 ) ;
if ( V_14 < 0 )
goto V_206;
V_106 -> V_17 = V_14 ;
V_106 -> V_207 [ 0 ] = V_14 ;
V_14 = F_159 ( & V_106 -> V_20 . V_208 , V_209 , 0 ,
V_93 ) ;
if ( V_14 )
goto V_206;
V_14 = F_74 ( 2 * V_73 , & V_92 ) ;
if ( V_14 )
goto V_210;
V_14 = F_88 ( V_7 ) ;
if ( V_14 )
goto V_210;
V_7 -> V_105 = F_160 ( & V_211 ,
V_212 ,
V_106 ) ;
if ( F_161 ( V_7 -> V_105 ) ) {
V_14 = F_162 ( V_7 -> V_105 ) ;
goto V_213;
}
V_106 -> V_39 = V_7 -> V_105 -> V_39 ;
V_14 = F_119 ( & V_106 -> V_20 ) ;
if ( V_14 )
goto V_214;
V_14 = F_97 ( V_7 , V_153 ) ;
if ( V_14 )
goto V_214;
F_77 ( & V_7 -> V_112 , & V_215 ) ;
V_97 ++ ;
F_82 ( & V_46 ) ;
F_124 (css_set_table, i, cset, hlist) {
F_78 ( & V_92 , V_45 , V_106 ) ;
if ( F_39 ( V_45 ) )
F_41 ( V_106 , true ) ;
}
F_83 ( & V_46 ) ;
F_69 ( ! F_40 ( & V_106 -> V_20 . V_111 ) ) ;
F_69 ( F_95 ( & V_7 -> V_110 ) != 1 ) ;
F_128 ( V_106 -> V_39 ) ;
V_14 = 0 ;
goto V_206;
V_214:
F_99 ( V_7 -> V_105 ) ;
V_7 -> V_105 = NULL ;
V_213:
F_90 ( V_7 ) ;
V_210:
F_163 ( & V_106 -> V_20 . V_208 ) ;
V_206:
F_73 ( & V_92 ) ;
return V_14 ;
}
static struct V_216 * F_164 ( struct V_217 * V_218 ,
int V_35 , const char * V_219 ,
void * V_174 )
{
bool V_220 = V_218 == & V_221 ;
struct V_222 * V_223 = NULL ;
struct V_224 * V_225 = V_114 -> V_115 -> V_116 ;
struct V_28 * V_29 ;
struct V_89 * V_7 ;
struct V_175 V_176 ;
struct V_216 * V_216 ;
int V_14 ;
int V_68 ;
bool V_226 ;
F_165 ( V_225 ) ;
if ( ! F_166 ( V_225 -> V_227 , V_228 ) ) {
F_167 ( V_225 ) ;
return F_168 ( - V_229 ) ;
}
if ( ! V_196 )
F_145 () ;
if ( V_220 ) {
if ( V_174 ) {
F_143 ( L_21 , ( char * ) V_174 ) ;
F_167 ( V_225 ) ;
return F_168 ( - V_185 ) ;
}
V_230 = true ;
V_7 = & V_8 ;
F_30 ( & V_7 -> V_6 ) ;
goto V_231;
}
F_94 ( & V_8 . V_6 ) ;
V_14 = F_138 ( V_174 , & V_176 ) ;
if ( V_14 )
goto V_33;
F_53 (ss, i) {
if ( ! ( V_176 . V_23 & ( 1 << V_68 ) ) ||
V_29 -> V_7 == & V_8 )
continue;
if ( ! F_169 ( & V_29 -> V_7 -> V_6 . V_20 . V_208 ) ) {
F_98 ( & V_31 ) ;
F_170 ( 10 ) ;
V_14 = F_171 () ;
goto V_232;
}
F_59 ( & V_29 -> V_7 -> V_6 ) ;
}
F_172 (root) {
bool V_233 = false ;
if ( V_7 == & V_8 )
continue;
if ( V_176 . V_122 ) {
if ( strcmp ( V_176 . V_122 , V_7 -> V_122 ) )
continue;
V_233 = true ;
}
if ( ( V_176 . V_23 || V_176 . V_186 ) &&
( V_176 . V_23 != V_7 -> V_23 ) ) {
if ( ! V_233 )
continue;
V_14 = - V_156 ;
goto V_33;
}
if ( V_7 -> V_35 ^ V_176 . V_35 )
F_127 ( L_22 ) ;
V_223 = F_173 ( V_7 -> V_105 , NULL ) ;
if ( F_161 ( V_223 ) ||
! F_169 ( & V_7 -> V_6 . V_20 . V_208 ) ) {
F_98 ( & V_31 ) ;
if ( ! F_174 ( V_223 ) )
F_175 ( V_223 ) ;
F_170 ( 10 ) ;
V_14 = F_171 () ;
goto V_232;
}
V_14 = 0 ;
goto V_33;
}
if ( ! V_176 . V_23 && ! V_176 . V_186 ) {
V_14 = - V_185 ;
goto V_33;
}
if ( ! V_176 . V_186 && ! F_176 ( V_228 ) ) {
V_14 = - V_229 ;
goto V_33;
}
V_7 = F_76 ( sizeof( * V_7 ) , V_93 ) ;
if ( ! V_7 ) {
V_14 = - V_94 ;
goto V_33;
}
F_154 ( V_7 , & V_176 ) ;
V_14 = F_157 ( V_7 , V_176 . V_23 ) ;
if ( V_14 )
F_91 ( V_7 ) ;
V_33:
F_98 ( & V_31 ) ;
V_232:
F_60 ( V_176 . V_188 ) ;
F_60 ( V_176 . V_122 ) ;
if ( V_14 ) {
F_167 ( V_225 ) ;
return F_168 ( V_14 ) ;
}
V_231:
V_216 = F_177 ( V_218 , V_35 , V_7 -> V_105 ,
V_220 ? V_234 : V_235 ,
& V_226 ) ;
if ( ! F_161 ( V_216 ) && V_225 != & V_236 ) {
struct V_216 * V_237 ;
struct V_5 * V_6 ;
F_114 ( & V_31 ) ;
F_82 ( & V_46 ) ;
V_6 = F_101 ( V_225 -> V_117 , V_7 ) ;
F_83 ( & V_46 ) ;
F_98 ( & V_31 ) ;
V_237 = F_178 ( V_6 -> V_39 , V_216 -> V_238 ) ;
F_179 ( V_216 ) ;
V_216 = V_237 ;
}
if ( F_161 ( V_216 ) || ! V_226 )
F_59 ( & V_7 -> V_6 ) ;
if ( V_223 ) {
F_96 ( V_226 ) ;
F_175 ( V_223 ) ;
}
F_167 ( V_225 ) ;
return V_216 ;
}
static void F_180 ( struct V_222 * V_239 )
{
struct V_104 * V_105 = F_181 ( V_239 ) ;
struct V_89 * V_7 = F_87 ( V_105 ) ;
if ( ! F_40 ( & V_7 -> V_6 . V_20 . V_111 ) ||
V_7 == & V_8 )
F_59 ( & V_7 -> V_6 ) ;
else
F_182 ( & V_7 -> V_6 . V_20 . V_208 ) ;
F_183 ( V_239 ) ;
}
static char * F_184 ( struct V_5 * V_6 , char * V_118 , T_4 V_240 ,
struct V_224 * V_225 )
{
struct V_5 * V_7 = F_101 ( V_225 -> V_117 , V_6 -> V_7 ) ;
int V_14 ;
V_14 = F_131 ( V_6 -> V_39 , V_7 -> V_39 , V_118 , V_240 ) ;
if ( V_14 < 0 || V_14 >= V_240 )
return NULL ;
return V_118 ;
}
char * F_185 ( struct V_5 * V_6 , char * V_118 , T_4 V_240 ,
struct V_224 * V_225 )
{
char * V_14 ;
F_114 ( & V_31 ) ;
F_82 ( & V_46 ) ;
V_14 = F_184 ( V_6 , V_118 , V_240 , V_225 ) ;
F_83 ( & V_46 ) ;
F_98 ( & V_31 ) ;
return V_14 ;
}
char * F_186 ( struct V_55 * V_56 , char * V_118 , T_4 V_240 )
{
struct V_89 * V_7 ;
struct V_5 * V_6 ;
int V_108 = 1 ;
char * V_241 = NULL ;
F_114 ( & V_31 ) ;
F_82 ( & V_46 ) ;
V_7 = F_187 ( & V_107 , & V_108 ) ;
if ( V_7 ) {
V_6 = F_102 ( V_56 , V_7 ) ;
V_241 = F_184 ( V_6 , V_118 , V_240 , & V_236 ) ;
} else {
if ( F_188 ( V_118 , L_23 , V_240 ) < V_240 )
V_241 = V_118 ;
}
F_83 ( & V_46 ) ;
F_98 ( & V_31 ) ;
return V_241 ;
}
static void F_189 ( struct V_55 * V_56 ,
struct V_242 * V_243 )
{
struct V_44 * V_45 ;
F_23 ( & V_46 ) ;
if ( V_56 -> V_35 & V_65 )
return;
if ( F_40 ( & V_56 -> V_63 ) )
return;
V_45 = F_103 ( V_56 ) ;
if ( ! V_45 -> V_244 )
return;
F_80 ( & V_56 -> V_63 , & V_45 -> V_48 ) ;
if ( F_40 ( & V_45 -> V_99 ) )
F_51 ( & V_45 -> V_99 , & V_243 -> V_245 ) ;
if ( F_40 ( & V_45 -> V_246 -> V_99 ) )
F_80 ( & V_45 -> V_246 -> V_99 ,
& V_243 -> V_247 ) ;
}
struct V_55 * F_190 ( struct V_242 * V_243 ,
struct V_18 * * V_248 )
{
V_243 -> V_249 = F_79 ( V_243 -> V_250 , struct V_44 , V_99 ) ;
V_243 -> V_251 = NULL ;
return F_191 ( V_243 , V_248 ) ;
}
struct V_55 * F_191 ( struct V_242 * V_243 ,
struct V_18 * * V_248 )
{
struct V_44 * V_45 = V_243 -> V_249 ;
struct V_55 * V_56 = V_243 -> V_251 ;
while ( & V_45 -> V_99 != V_243 -> V_250 ) {
if ( ! V_56 )
V_56 = F_79 ( & V_45 -> V_48 ,
struct V_55 , V_63 ) ;
else
V_56 = F_192 ( V_56 , V_63 ) ;
if ( & V_56 -> V_63 != & V_45 -> V_48 ) {
V_243 -> V_249 = V_45 ;
V_243 -> V_251 = V_56 ;
if ( V_45 -> V_246 )
* V_248 = V_45 -> V_246 -> V_30 [ V_243 -> V_1 ] ;
else
* V_248 = V_45 -> V_30 [ V_243 -> V_1 ] ;
return V_56 ;
}
V_45 = F_192 ( V_45 , V_99 ) ;
V_56 = NULL ;
}
return NULL ;
}
static int F_193 ( struct V_242 * V_243 ,
struct V_89 * V_7 )
{
struct V_28 * V_29 ;
struct V_55 * V_56 , * V_252 ;
struct V_44 * V_45 , * V_253 ;
int V_1 , V_254 , V_14 ;
if ( F_40 ( & V_243 -> V_245 ) )
return 0 ;
F_107 (ss, ssid, root->subsys_mask) {
if ( V_29 -> V_255 ) {
V_243 -> V_1 = V_1 ;
V_14 = V_29 -> V_255 ( V_243 ) ;
if ( V_14 ) {
V_254 = V_1 ;
goto V_256;
}
}
} F_108 () ;
F_82 ( & V_46 ) ;
F_45 (cset, &tset->src_csets, mg_node) {
F_47 (task, tmp_task, &cset->mg_tasks, cg_list) {
struct V_44 * V_57 = F_103 ( V_56 ) ;
struct V_44 * V_58 = V_45 -> V_246 ;
F_66 ( V_58 ) ;
F_46 ( V_56 , V_57 , V_58 , true ) ;
F_54 ( V_57 ) ;
}
}
F_83 ( & V_46 ) ;
V_243 -> V_250 = & V_243 -> V_247 ;
F_107 (ss, ssid, root->subsys_mask) {
if ( V_29 -> V_257 ) {
V_243 -> V_1 = V_1 ;
V_29 -> V_257 ( V_243 ) ;
}
} F_108 () ;
V_14 = 0 ;
goto V_258;
V_256:
F_107 (ss, ssid, root->subsys_mask) {
if ( V_1 == V_254 )
break;
if ( V_29 -> V_259 ) {
V_243 -> V_1 = V_1 ;
V_29 -> V_259 ( V_243 ) ;
}
} F_108 () ;
V_258:
F_82 ( & V_46 ) ;
F_194 ( & V_243 -> V_247 , & V_243 -> V_245 ) ;
F_47 (cset, tmp_cset, &tset->src_csets, mg_node) {
F_195 ( & V_45 -> V_48 , & V_45 -> V_47 ) ;
F_49 ( & V_45 -> V_99 ) ;
}
F_83 ( & V_46 ) ;
return V_14 ;
}
static bool F_196 ( struct V_5 * V_260 )
{
return ! F_4 ( V_260 ) || ! F_15 ( V_260 ) ||
! V_260 -> V_24 ;
}
static void F_197 ( struct V_80 * V_261 )
{
struct V_44 * V_45 , * V_253 ;
F_23 ( & V_31 ) ;
F_82 ( & V_46 ) ;
F_47 (cset, tmp_cset, preloaded_csets, mg_preload_node) {
V_45 -> V_244 = NULL ;
V_45 -> V_262 = NULL ;
V_45 -> V_246 = NULL ;
F_49 ( & V_45 -> V_98 ) ;
F_54 ( V_45 ) ;
}
F_83 ( & V_46 ) ;
}
static void F_198 ( struct V_44 * V_263 ,
struct V_5 * V_260 ,
struct V_80 * V_261 )
{
struct V_5 * V_264 ;
F_23 ( & V_31 ) ;
F_23 ( & V_46 ) ;
if ( V_263 -> V_265 )
return;
V_264 = F_101 ( V_263 , V_260 -> V_7 ) ;
if ( ! F_40 ( & V_263 -> V_98 ) )
return;
F_96 ( V_263 -> V_244 ) ;
F_96 ( V_263 -> V_262 ) ;
F_96 ( ! F_40 ( & V_263 -> V_48 ) ) ;
F_96 ( ! F_40 ( & V_263 -> V_99 ) ) ;
V_263 -> V_244 = V_264 ;
V_263 -> V_262 = V_260 ;
F_66 ( V_263 ) ;
F_77 ( & V_263 -> V_98 , V_261 ) ;
}
static int F_199 ( struct V_80 * V_261 )
{
F_158 ( V_250 ) ;
struct V_44 * V_263 , * V_253 ;
F_23 ( & V_31 ) ;
F_47 (src_cset, tmp_cset, preloaded_csets, mg_preload_node) {
struct V_44 * V_266 ;
V_266 = F_81 ( V_263 , V_263 -> V_262 ) ;
if ( ! V_266 )
goto V_151;
F_31 ( V_263 -> V_246 || V_266 -> V_246 ) ;
if ( V_263 == V_266 ) {
V_263 -> V_244 = NULL ;
V_263 -> V_262 = NULL ;
F_49 ( & V_263 -> V_98 ) ;
F_62 ( V_263 ) ;
F_62 ( V_266 ) ;
continue;
}
V_263 -> V_246 = V_266 ;
if ( F_40 ( & V_266 -> V_98 ) )
F_77 ( & V_266 -> V_98 , & V_250 ) ;
else
F_62 ( V_266 ) ;
}
F_200 ( & V_250 , V_261 ) ;
return 0 ;
V_151:
F_197 ( & V_250 ) ;
return - V_94 ;
}
static int F_201 ( struct V_55 * V_267 , bool V_268 ,
struct V_89 * V_7 )
{
struct V_242 V_243 = F_202 ( V_243 ) ;
struct V_55 * V_56 ;
F_82 ( & V_46 ) ;
F_25 () ;
V_56 = V_267 ;
do {
F_189 ( V_56 , & V_243 ) ;
if ( ! V_268 )
break;
} while_each_thread(leader, task) ;
int F_203 ( struct V_5 * V_260 ,
struct V_55 * V_267 , bool V_268 )
{
F_158 ( V_261 ) ;
struct V_55 * V_56 ;
int V_14 ;
if ( ! F_196 ( V_260 ) )
return - V_156 ;
F_82 ( & V_46 ) ;
F_25 () ;
V_56 = V_267 ;
do {
F_198 ( F_103 ( V_56 ) , V_260 ,
& V_261 ) ;
if ( ! V_268 )
break;
} while_each_thread(leader, task) ;
int F_204 ( struct V_55 * V_56 ,
struct V_5 * V_260 ,
struct V_37 * V_38 )
{
const struct V_269 * V_269 = F_205 () ;
const struct V_269 * V_270 = F_206 ( V_56 ) ;
int V_14 = 0 ;
if ( ! F_207 ( V_269 -> V_271 , V_272 ) &&
! F_207 ( V_269 -> V_271 , V_270 -> V_273 ) &&
! F_207 ( V_269 -> V_271 , V_270 -> V_274 ) )
V_14 = - V_275 ;
if ( ! V_14 && F_4 ( V_260 ) ) {
struct V_222 * V_239 = V_38 -> V_276 -> V_277 . V_216 -> V_238 ;
struct V_5 * V_6 ;
struct V_278 * V_278 ;
F_82 ( & V_46 ) ;
V_6 = F_102 ( V_56 , & V_8 ) ;
F_83 ( & V_46 ) ;
while ( ! F_208 ( V_260 , V_6 ) )
V_6 = F_15 ( V_6 ) ;
V_14 = - V_94 ;
V_278 = F_209 ( V_239 , V_6 -> V_279 . V_39 ) ;
if ( V_278 ) {
V_14 = F_210 ( V_278 , V_280 ) ;
F_211 ( V_278 ) ;
}
}
F_212 ( V_270 ) ;
return V_14 ;
}
static T_5 F_213 ( struct V_37 * V_38 , char * V_118 ,
T_4 V_281 , T_6 V_282 , bool V_268 )
{
struct V_55 * V_283 ;
struct V_28 * V_29 ;
struct V_5 * V_6 ;
T_7 V_284 ;
int V_1 , V_14 ;
if ( F_214 ( F_215 ( V_118 ) , 0 , & V_284 ) || V_284 < 0 )
return - V_185 ;
V_6 = F_112 ( V_38 -> V_39 , false ) ;
if ( ! V_6 )
return - V_285 ;
F_216 ( & V_286 ) ;
F_25 () ;
if ( V_284 ) {
V_283 = F_217 ( V_284 ) ;
if ( ! V_283 ) {
V_14 = - V_287 ;
goto V_288;
}
} else {
V_283 = V_114 ;
}
if ( V_268 )
V_283 = V_283 -> V_289 ;
if ( V_283 == V_290 || ( V_283 -> V_35 & V_291 ) ) {
V_14 = - V_185 ;
goto V_288;
}
F_218 ( V_283 ) ;
F_28 () ;
V_14 = F_204 ( V_283 , V_6 , V_38 ) ;
if ( ! V_14 )
V_14 = F_203 ( V_6 , V_283 , V_268 ) ;
F_219 ( V_283 ) ;
goto V_292;
V_288:
F_28 () ;
V_292:
F_220 ( & V_286 ) ;
F_53 (ss, ssid)
if ( V_29 -> V_293 )
V_29 -> V_293 () ;
F_109 ( V_38 -> V_39 ) ;
return V_14 ? : V_281 ;
}
int F_221 ( struct V_55 * V_294 , struct V_55 * V_283 )
{
struct V_89 * V_7 ;
int V_295 = 0 ;
F_114 ( & V_31 ) ;
F_172 (root) {
struct V_5 * V_296 ;
if ( V_7 == & V_8 )
continue;
F_82 ( & V_46 ) ;
V_296 = F_102 ( V_294 , V_7 ) ;
F_83 ( & V_46 ) ;
V_295 = F_203 ( V_296 , V_283 , false ) ;
if ( V_295 )
break;
}
F_98 ( & V_31 ) ;
return V_295 ;
}
static T_5 F_222 ( struct V_37 * V_38 ,
char * V_118 , T_4 V_281 , T_6 V_282 )
{
return F_213 ( V_38 , V_118 , V_281 , V_282 , false ) ;
}
static T_5 F_223 ( struct V_37 * V_38 ,
char * V_118 , T_4 V_281 , T_6 V_282 )
{
return F_213 ( V_38 , V_118 , V_281 , V_282 , true ) ;
}
static T_5 F_224 ( struct V_37 * V_38 ,
char * V_118 , T_4 V_281 , T_6 V_282 )
{
struct V_5 * V_6 ;
F_225 ( sizeof( V_6 -> V_7 -> V_172 ) < V_167 ) ;
V_6 = F_112 ( V_38 -> V_39 , false ) ;
if ( ! V_6 )
return - V_285 ;
F_136 ( & V_171 ) ;
F_188 ( V_6 -> V_7 -> V_172 , F_215 ( V_118 ) ,
sizeof( V_6 -> V_7 -> V_172 ) ) ;
F_137 ( & V_171 ) ;
F_109 ( V_38 -> V_39 ) ;
return V_281 ;
}
static int F_226 ( struct V_161 * V_169 , void * V_297 )
{
struct V_5 * V_6 = F_227 ( V_169 ) -> V_5 ;
F_136 ( & V_171 ) ;
F_135 ( V_169 , V_6 -> V_7 -> V_172 ) ;
F_137 ( & V_171 ) ;
F_228 ( V_169 , '\n' ) ;
return 0 ;
}
static int F_229 ( struct V_161 * V_169 , void * V_297 )
{
F_135 ( V_169 , L_24 ) ;
return 0 ;
}
static void F_230 ( struct V_161 * V_169 , T_2 V_153 )
{
struct V_28 * V_29 ;
bool V_298 = false ;
int V_1 ;
F_107 (ss, ssid, ss_mask) {
if ( V_298 )
F_228 ( V_169 , ' ' ) ;
F_231 ( V_169 , L_25 , V_29 -> V_122 ) ;
V_298 = true ;
} F_108 () ;
if ( V_298 )
F_228 ( V_169 , '\n' ) ;
}
static int F_232 ( struct V_161 * V_169 , void * V_297 )
{
struct V_5 * V_6 = F_227 ( V_169 ) -> V_5 ;
F_230 ( V_169 , F_17 ( V_6 ) ) ;
return 0 ;
}
static int F_233 ( struct V_161 * V_169 , void * V_297 )
{
struct V_5 * V_6 = F_227 ( V_169 ) -> V_5 ;
F_230 ( V_169 , V_6 -> V_24 ) ;
return 0 ;
}
static int F_234 ( struct V_5 * V_6 )
{
F_158 ( V_261 ) ;
struct V_242 V_243 = F_202 ( V_243 ) ;
struct V_18 * V_299 ;
struct V_5 * V_300 ;
struct V_44 * V_263 ;
int V_14 ;
F_23 ( & V_31 ) ;
F_216 ( & V_286 ) ;
F_82 ( & V_46 ) ;
F_235 (dsct, d_css, cgrp) {
struct V_53 * V_54 ;
F_45 (link, &dsct->cset_links, cset_link)
F_198 ( V_54 -> V_45 , V_300 ,
& V_261 ) ;
}
F_83 ( & V_46 ) ;
V_14 = F_199 ( & V_261 ) ;
if ( V_14 )
goto V_301;
F_82 ( & V_46 ) ;
F_45 (src_cset, &preloaded_csets, mg_preload_node) {
struct V_55 * V_56 , * V_302 ;
if ( ! V_263 -> V_244 )
break;
F_47 (task, ntask, &src_cset->tasks, cg_list)
F_189 ( V_56 , & V_243 ) ;
}
F_83 ( & V_46 ) ;
V_14 = F_193 ( & V_243 , V_6 -> V_7 ) ;
V_301:
F_197 ( & V_261 ) ;
F_220 ( & V_286 ) ;
return V_14 ;
}
static void F_94 ( struct V_5 * V_6 )
__acquires( &cgroup_mutex
static void F_236 ( struct V_5 * V_6 )
{
struct V_5 * V_300 ;
struct V_18 * V_299 ;
F_235 (dsct, d_css, cgrp) {
V_300 -> V_303 = V_300 -> V_24 ;
V_300 -> V_304 = V_300 -> V_27 ;
}
}
static void F_237 ( struct V_5 * V_6 )
{
struct V_5 * V_300 ;
struct V_18 * V_299 ;
F_235 (dsct, d_css, cgrp) {
V_300 -> V_24 &= F_17 ( V_300 ) ;
V_300 -> V_27 =
F_106 ( V_300 -> V_24 ,
F_18 ( V_300 ) ) ;
}
}
static void F_238 ( struct V_5 * V_6 )
{
struct V_5 * V_300 ;
struct V_18 * V_299 ;
F_239 (dsct, d_css, cgrp) {
V_300 -> V_24 = V_300 -> V_303 ;
V_300 -> V_27 = V_300 -> V_304 ;
}
}
static bool F_240 ( struct V_18 * V_32 )
{
struct V_28 * V_29 = V_32 -> V_29 ;
struct V_5 * V_6 = V_32 -> V_5 ;
if ( F_17 ( V_6 ) & ( 1 << V_29 -> V_17 ) )
return true ;
if ( ! ( F_18 ( V_6 ) & ( 1 << V_29 -> V_17 ) ) )
return false ;
return F_4 ( V_6 ) && V_29 -> V_155 ;
}
static int F_241 ( struct V_5 * V_6 )
{
struct V_5 * V_300 ;
struct V_18 * V_299 ;
struct V_28 * V_29 ;
int V_1 , V_14 ;
F_235 (dsct, d_css, cgrp) {
F_53 (ss, ssid) {
struct V_18 * V_32 = F_19 ( V_300 , V_29 ) ;
F_31 ( V_32 && F_242 ( & V_32 -> V_208 ) ) ;
if ( ! ( F_18 ( V_300 ) & ( 1 << V_29 -> V_17 ) ) )
continue;
if ( ! V_32 ) {
V_32 = F_243 ( V_300 , V_29 ) ;
if ( F_161 ( V_32 ) )
return F_162 ( V_32 ) ;
}
if ( F_240 ( V_32 ) ) {
V_14 = F_119 ( V_32 ) ;
if ( V_14 )
return V_14 ;
}
}
}
return 0 ;
}
static void F_244 ( struct V_5 * V_6 )
{
struct V_5 * V_300 ;
struct V_18 * V_299 ;
struct V_28 * V_29 ;
int V_1 ;
F_239 (dsct, d_css, cgrp) {
F_53 (ss, ssid) {
struct V_18 * V_32 = F_19 ( V_300 , V_29 ) ;
F_31 ( V_32 && F_242 ( & V_32 -> V_208 ) ) ;
if ( ! V_32 )
continue;
if ( V_32 -> V_21 &&
! ( F_18 ( V_300 ) & ( 1 << V_29 -> V_17 ) ) ) {
F_245 ( V_32 ) ;
} else if ( ! F_240 ( V_32 ) ) {
F_117 ( V_32 ) ;
if ( V_29 -> V_305 )
V_29 -> V_305 ( V_32 ) ;
}
}
}
}
static int F_121 ( struct V_5 * V_6 )
{
int V_14 ;
F_237 ( V_6 ) ;
V_14 = F_241 ( V_6 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_234 ( V_6 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static void F_122 ( struct V_5 * V_6 , int V_14 )
{
if ( V_14 ) {
F_238 ( V_6 ) ;
F_237 ( V_6 ) ;
}
F_244 ( V_6 ) ;
}
static T_5 F_246 ( struct V_37 * V_38 ,
char * V_118 , T_4 V_281 ,
T_6 V_282 )
{
T_2 V_306 = 0 , V_307 = 0 ;
struct V_5 * V_6 , * V_308 ;
struct V_28 * V_29 ;
char * V_309 ;
int V_1 , V_14 ;
V_118 = F_215 ( V_118 ) ;
while ( ( V_309 = F_140 ( & V_118 , L_26 ) ) ) {
if ( V_309 [ 0 ] == '\0' )
continue;
F_107 (ss, ssid, ~cgrp_dfl_inhibit_ss_mask) {
if ( ! F_1 ( V_1 ) ||
strcmp ( V_309 + 1 , V_29 -> V_122 ) )
continue;
if ( * V_309 == '+' ) {
V_306 |= 1 << V_1 ;
V_307 &= ~ ( 1 << V_1 ) ;
} else if ( * V_309 == '-' ) {
V_307 |= 1 << V_1 ;
V_306 &= ~ ( 1 << V_1 ) ;
} else {
return - V_185 ;
}
break;
} F_108 () ;
if ( V_1 == V_2 )
return - V_185 ;
}
V_6 = F_112 ( V_38 -> V_39 , true ) ;
if ( ! V_6 )
return - V_285 ;
F_53 (ss, ssid) {
if ( V_306 & ( 1 << V_1 ) ) {
if ( V_6 -> V_24 & ( 1 << V_1 ) ) {
V_306 &= ~ ( 1 << V_1 ) ;
continue;
}
if ( ! ( F_17 ( V_6 ) & ( 1 << V_1 ) ) ) {
V_14 = - V_190 ;
goto V_33;
}
} else if ( V_307 & ( 1 << V_1 ) ) {
if ( ! ( V_6 -> V_24 & ( 1 << V_1 ) ) ) {
V_307 &= ~ ( 1 << V_1 ) ;
continue;
}
F_247 (child, cgrp) {
if ( V_308 -> V_24 & ( 1 << V_1 ) ) {
V_14 = - V_156 ;
goto V_33;
}
}
}
}
if ( ! V_306 && ! V_307 ) {
V_14 = 0 ;
goto V_33;
}
if ( V_306 && F_15 ( V_6 ) && ! F_40 ( & V_6 -> V_96 ) ) {
V_14 = - V_156 ;
goto V_33;
}
F_236 ( V_6 ) ;
V_6 -> V_24 |= V_306 ;
V_6 -> V_24 &= ~ V_307 ;
V_14 = F_121 ( V_6 ) ;
F_122 ( V_6 , V_14 ) ;
F_128 ( V_6 -> V_39 ) ;
V_14 = 0 ;
V_33:
F_109 ( V_38 -> V_39 ) ;
return V_14 ? : V_281 ;
}
static int F_248 ( struct V_161 * V_169 , void * V_297 )
{
F_231 ( V_169 , L_27 ,
F_249 ( F_227 ( V_169 ) -> V_5 ) ) ;
return 0 ;
}
static T_5 F_250 ( struct V_37 * V_38 , char * V_118 ,
T_4 V_281 , T_6 V_282 )
{
struct V_5 * V_6 = V_38 -> V_39 -> V_21 -> V_40 ;
struct V_41 * V_42 = V_38 -> V_39 -> V_40 ;
struct V_18 * V_32 ;
int V_14 ;
if ( V_42 -> V_131 )
return V_42 -> V_131 ( V_38 , V_118 , V_281 , V_282 ) ;
F_25 () ;
V_32 = F_19 ( V_6 , V_42 -> V_29 ) ;
F_28 () ;
if ( V_42 -> V_129 ) {
unsigned long long V_297 ;
V_14 = F_251 ( V_118 , 0 , & V_297 ) ;
if ( ! V_14 )
V_14 = V_42 -> V_129 ( V_32 , V_42 , V_297 ) ;
} else if ( V_42 -> V_130 ) {
long long V_297 ;
V_14 = F_252 ( V_118 , 0 , & V_297 ) ;
if ( ! V_14 )
V_14 = V_42 -> V_130 ( V_32 , V_42 , V_297 ) ;
} else {
V_14 = - V_185 ;
}
return V_14 ? : V_281 ;
}
static void * F_253 ( struct V_161 * V_169 , T_6 * V_310 )
{
return F_254 ( V_169 ) -> F_255 ( V_169 , V_310 ) ;
}
static void * F_256 ( struct V_161 * V_169 , void * V_297 , T_6 * V_310 )
{
return F_254 ( V_169 ) -> F_257 ( V_169 , V_297 , V_310 ) ;
}
static void F_258 ( struct V_161 * V_169 , void * V_297 )
{
F_254 ( V_169 ) -> F_259 ( V_169 , V_297 ) ;
}
static int F_260 ( struct V_161 * V_311 , void * V_312 )
{
struct V_41 * V_42 = F_254 ( V_311 ) ;
struct V_18 * V_32 = F_227 ( V_311 ) ;
if ( V_42 -> V_127 )
return V_42 -> V_127 ( V_311 , V_312 ) ;
if ( V_42 -> V_125 )
F_231 ( V_311 , L_28 , V_42 -> V_125 ( V_32 , V_42 ) ) ;
else if ( V_42 -> V_126 )
F_231 ( V_311 , L_29 , V_42 -> V_126 ( V_32 , V_42 ) ) ;
else
return - V_185 ;
return 0 ;
}
static int F_261 ( struct V_139 * V_39 , struct V_139 * V_313 ,
const char * V_314 )
{
struct V_5 * V_6 = V_39 -> V_40 ;
int V_14 ;
if ( F_110 ( V_39 ) != V_140 )
return - V_315 ;
if ( V_39 -> V_21 != V_313 )
return - V_316 ;
if ( F_4 ( V_6 ) )
return - V_229 ;
F_113 ( V_313 ) ;
F_113 ( V_39 ) ;
F_114 ( & V_31 ) ;
V_14 = F_262 ( V_39 , V_313 , V_314 ) ;
F_98 ( & V_31 ) ;
F_111 ( V_39 ) ;
F_111 ( V_313 ) ;
return V_14 ;
}
static int F_263 ( struct V_139 * V_39 )
{
struct V_317 V_317 = { . V_318 = V_319 | V_320 ,
. V_321 = F_264 () ,
. V_322 = F_265 () , } ;
if ( F_207 ( V_317 . V_321 , V_272 ) &&
F_266 ( V_317 . V_322 , V_323 ) )
return 0 ;
return F_267 ( V_39 , & V_317 ) ;
}
static int F_268 ( struct V_18 * V_32 , struct V_5 * V_6 ,
struct V_41 * V_42 )
{
char V_122 [ V_121 ] ;
struct V_139 * V_39 ;
struct V_324 * V_67 = NULL ;
int V_14 ;
#ifdef F_269
V_67 = & V_42 -> V_325 ;
#endif
V_39 = F_270 ( V_6 -> V_39 , F_104 ( V_6 , V_42 , V_122 ) ,
F_105 ( V_42 ) , 0 , V_42 -> V_326 , V_42 ,
NULL , V_67 ) ;
if ( F_161 ( V_39 ) )
return F_162 ( V_39 ) ;
V_14 = F_263 ( V_39 ) ;
if ( V_14 ) {
F_271 ( V_39 ) ;
return V_14 ;
}
if ( V_42 -> V_142 ) {
struct V_143 * V_144 = ( void * ) V_32 + V_42 -> V_142 ;
F_82 ( & V_145 ) ;
V_144 -> V_39 = V_39 ;
F_83 ( & V_145 ) ;
}
return 0 ;
}
static int F_118 ( struct V_18 * V_32 ,
struct V_5 * V_6 , struct V_41 V_146 [] ,
bool V_327 )
{
struct V_41 * V_42 , * V_328 = NULL ;
int V_14 = 0 ;
F_23 ( & V_31 ) ;
V_329:
for ( V_42 = V_146 ; V_42 != V_328 && V_42 -> V_122 [ 0 ] != '\0' ; V_42 ++ ) {
if ( ( V_42 -> V_35 & V_330 ) && ! F_4 ( V_6 ) )
continue;
if ( ( V_42 -> V_35 & V_331 ) && F_4 ( V_6 ) )
continue;
if ( ( V_42 -> V_35 & V_332 ) && ! F_15 ( V_6 ) )
continue;
if ( ( V_42 -> V_35 & V_333 ) && F_15 ( V_6 ) )
continue;
if ( V_327 ) {
V_14 = F_268 ( V_32 , V_6 , V_42 ) ;
if ( V_14 ) {
F_127 ( L_30 ,
V_334 , V_42 -> V_122 , V_14 ) ;
V_328 = V_42 ;
V_327 = false ;
goto V_329;
}
} else {
F_115 ( V_6 , V_42 ) ;
}
}
return V_14 ;
}
static int F_272 ( struct V_41 * V_146 , bool V_327 )
{
F_158 ( V_335 ) ;
struct V_28 * V_29 = V_146 [ 0 ] . V_29 ;
struct V_5 * V_7 = & V_29 -> V_7 -> V_6 ;
struct V_18 * V_32 ;
int V_14 = 0 ;
F_23 ( & V_31 ) ;
F_273 (css, cgroup_css(root, ss)) {
struct V_5 * V_6 = V_32 -> V_5 ;
if ( ! ( V_32 -> V_35 & V_147 ) )
continue;
V_14 = F_118 ( V_32 , V_6 , V_146 , V_327 ) ;
if ( V_14 )
break;
}
if ( V_327 && ! V_14 )
F_128 ( V_7 -> V_39 ) ;
return V_14 ;
}
static void F_274 ( struct V_41 * V_146 )
{
struct V_41 * V_42 ;
for ( V_42 = V_146 ; V_42 -> V_122 [ 0 ] != '\0' ; V_42 ++ ) {
if ( V_42 -> V_336 && V_42 -> V_336 != V_337 )
F_60 ( V_42 -> V_326 ) ;
V_42 -> V_326 = NULL ;
V_42 -> V_29 = NULL ;
V_42 -> V_35 &= ~ ( V_330 | V_331 ) ;
}
}
static int F_275 ( struct V_28 * V_29 , struct V_41 * V_146 )
{
struct V_41 * V_42 ;
for ( V_42 = V_146 ; V_42 -> V_122 [ 0 ] != '\0' ; V_42 ++ ) {
struct V_338 * V_326 ;
F_96 ( V_42 -> V_29 || V_42 -> V_326 ) ;
if ( V_42 -> F_255 )
V_326 = & V_339 ;
else
V_326 = & V_340 ;
if ( V_42 -> V_336 && V_42 -> V_336 != V_337 ) {
V_326 = F_276 ( V_326 , sizeof( * V_326 ) , V_93 ) ;
if ( ! V_326 ) {
F_274 ( V_146 ) ;
return - V_94 ;
}
V_326 -> V_341 = V_42 -> V_336 ;
}
V_42 -> V_326 = V_326 ;
V_42 -> V_29 = V_29 ;
}
return 0 ;
}
static int F_277 ( struct V_41 * V_146 )
{
F_23 ( & V_31 ) ;
if ( ! V_146 || ! V_146 [ 0 ] . V_29 )
return - V_190 ;
F_56 ( & V_146 -> V_342 ) ;
F_272 ( V_146 , false ) ;
F_274 ( V_146 ) ;
return 0 ;
}
int F_278 ( struct V_41 * V_146 )
{
int V_14 ;
F_114 ( & V_31 ) ;
V_14 = F_277 ( V_146 ) ;
F_98 ( & V_31 ) ;
return V_14 ;
}
static int F_279 ( struct V_28 * V_29 , struct V_41 * V_146 )
{
int V_14 ;
if ( ! F_1 ( V_29 -> V_17 ) )
return 0 ;
if ( ! V_146 || V_146 [ 0 ] . V_122 [ 0 ] == '\0' )
return 0 ;
V_14 = F_275 ( V_29 , V_146 ) ;
if ( V_14 )
return V_14 ;
F_114 ( & V_31 ) ;
F_51 ( & V_146 -> V_342 , & V_29 -> V_146 ) ;
V_14 = F_272 ( V_146 , true ) ;
if ( V_14 )
F_277 ( V_146 ) ;
F_98 ( & V_31 ) ;
return V_14 ;
}
int F_280 ( struct V_28 * V_29 , struct V_41 * V_146 )
{
struct V_41 * V_42 ;
for ( V_42 = V_146 ; V_42 && V_42 -> V_122 [ 0 ] != '\0' ; V_42 ++ )
V_42 -> V_35 |= V_330 ;
return F_279 ( V_29 , V_146 ) ;
}
int F_281 ( struct V_28 * V_29 , struct V_41 * V_146 )
{
struct V_41 * V_42 ;
for ( V_42 = V_146 ; V_42 && V_42 -> V_122 [ 0 ] != '\0' ; V_42 ++ )
V_42 -> V_35 |= V_331 ;
return F_279 ( V_29 , V_146 ) ;
}
void F_43 ( struct V_143 * V_144 )
{
unsigned long V_35 ;
F_64 ( & V_145 , V_35 ) ;
if ( V_144 -> V_39 )
F_282 ( V_144 -> V_39 ) ;
F_65 ( & V_145 , V_35 ) ;
}
static int F_283 ( const struct V_5 * V_6 )
{
int V_91 = 0 ;
struct V_53 * V_54 ;
F_82 ( & V_46 ) ;
F_45 (link, &cgrp->cset_links, cset_link)
V_91 += F_95 ( & V_54 -> V_45 -> V_70 ) ;
F_83 ( & V_46 ) ;
return V_91 ;
}
struct V_18 * F_120 ( struct V_18 * V_62 ,
struct V_18 * V_21 )
{
struct V_18 * V_88 ;
F_284 () ;
if ( ! V_62 ) {
V_88 = F_285 ( V_21 -> V_111 . V_88 , struct V_18 , V_200 ) ;
} else if ( F_286 ( ! ( V_62 -> V_35 & V_343 ) ) ) {
V_88 = F_285 ( V_62 -> V_200 . V_88 , struct V_18 , V_200 ) ;
} else {
F_287 (next, &parent->children, sibling)
if ( V_88 -> V_344 > V_62 -> V_344 )
break;
}
if ( & V_88 -> V_200 != & V_21 -> V_111 )
return V_88 ;
return NULL ;
}
struct V_18 *
F_288 ( struct V_18 * V_62 ,
struct V_18 * V_7 )
{
struct V_18 * V_88 ;
F_284 () ;
if ( ! V_62 )
return V_7 ;
V_88 = F_120 ( NULL , V_62 ) ;
if ( V_88 )
return V_88 ;
while ( V_62 != V_7 ) {
V_88 = F_120 ( V_62 , V_62 -> V_21 ) ;
if ( V_88 )
return V_88 ;
V_62 = V_62 -> V_21 ;
}
return NULL ;
}
struct V_18 *
F_289 ( struct V_18 * V_62 )
{
struct V_18 * V_345 , * V_346 ;
F_284 () ;
do {
V_345 = V_62 ;
V_62 = NULL ;
F_290 (tmp, last)
V_62 = V_346 ;
} while ( V_62 );
return V_345 ;
}
static struct V_18 *
F_291 ( struct V_18 * V_62 )
{
struct V_18 * V_345 ;
do {
V_345 = V_62 ;
V_62 = F_120 ( NULL , V_62 ) ;
} while ( V_62 );
return V_345 ;
}
struct V_18 *
F_292 ( struct V_18 * V_62 ,
struct V_18 * V_7 )
{
struct V_18 * V_88 ;
F_284 () ;
if ( ! V_62 )
return F_291 ( V_7 ) ;
if ( V_62 == V_7 )
return NULL ;
V_88 = F_120 ( V_62 , V_62 -> V_21 ) ;
if ( V_88 )
return F_291 ( V_88 ) ;
return V_62 -> V_21 ;
}
bool F_293 ( struct V_18 * V_32 )
{
struct V_18 * V_308 ;
bool V_14 = false ;
F_25 () ;
F_290 (child, css) {
if ( V_308 -> V_35 & V_36 ) {
V_14 = true ;
break;
}
}
F_28 () ;
return V_14 ;
}
static void F_294 ( struct V_60 * V_61 )
{
struct V_80 * V_347 = V_61 -> V_348 ;
struct V_53 * V_54 ;
struct V_44 * V_45 ;
F_23 ( & V_46 ) ;
do {
V_347 = V_347 -> V_88 ;
if ( V_347 == V_61 -> V_349 ) {
V_61 -> V_348 = NULL ;
V_61 -> V_64 = NULL ;
return;
}
if ( V_61 -> V_29 ) {
V_45 = F_16 ( V_347 , struct V_44 ,
V_71 [ V_61 -> V_29 -> V_17 ] ) ;
} else {
V_54 = F_70 ( V_347 , struct V_53 , V_74 ) ;
V_45 = V_54 -> V_45 ;
}
} while ( ! F_39 ( V_45 ) );
V_61 -> V_348 = V_347 ;
if ( ! F_40 ( & V_45 -> V_47 ) )
V_61 -> V_64 = V_45 -> V_47 . V_88 ;
else
V_61 -> V_64 = V_45 -> V_48 . V_88 ;
V_61 -> V_350 = & V_45 -> V_47 ;
V_61 -> V_351 = & V_45 -> V_48 ;
if ( V_61 -> V_249 ) {
F_56 ( & V_61 -> V_352 ) ;
F_54 ( V_61 -> V_249 ) ;
}
F_66 ( V_45 ) ;
V_61 -> V_249 = V_45 ;
F_77 ( & V_61 -> V_352 , & V_45 -> V_100 ) ;
}
static void F_48 ( struct V_60 * V_61 )
{
struct V_80 * V_347 = V_61 -> V_64 ;
F_23 ( & V_46 ) ;
F_31 ( ! V_347 ) ;
V_347 = V_347 -> V_88 ;
if ( V_347 == V_61 -> V_350 )
V_347 = V_61 -> V_351 -> V_88 ;
if ( V_347 == V_61 -> V_351 )
F_294 ( V_61 ) ;
else
V_61 -> V_64 = V_347 ;
}
void F_295 ( struct V_18 * V_32 ,
struct V_60 * V_61 )
{
F_31 ( ! V_196 ) ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_82 ( & V_46 ) ;
V_61 -> V_29 = V_32 -> V_29 ;
if ( V_61 -> V_29 )
V_61 -> V_348 = & V_32 -> V_5 -> V_103 [ V_32 -> V_29 -> V_17 ] ;
else
V_61 -> V_348 = & V_32 -> V_5 -> V_96 ;
V_61 -> V_349 = V_61 -> V_348 ;
F_294 ( V_61 ) ;
F_83 ( & V_46 ) ;
}
struct V_55 * F_296 ( struct V_60 * V_61 )
{
if ( V_61 -> V_251 ) {
F_219 ( V_61 -> V_251 ) ;
V_61 -> V_251 = NULL ;
}
F_82 ( & V_46 ) ;
if ( V_61 -> V_64 ) {
V_61 -> V_251 = F_70 ( V_61 -> V_64 , struct V_55 ,
V_63 ) ;
F_218 ( V_61 -> V_251 ) ;
F_48 ( V_61 ) ;
}
F_83 ( & V_46 ) ;
return V_61 -> V_251 ;
}
void F_297 ( struct V_60 * V_61 )
{
if ( V_61 -> V_249 ) {
F_82 ( & V_46 ) ;
F_56 ( & V_61 -> V_352 ) ;
F_54 ( V_61 -> V_249 ) ;
F_83 ( & V_46 ) ;
}
if ( V_61 -> V_251 )
F_219 ( V_61 -> V_251 ) ;
}
int F_298 ( struct V_5 * V_353 , struct V_5 * V_294 )
{
F_158 ( V_261 ) ;
struct V_53 * V_54 ;
struct V_60 V_61 ;
struct V_55 * V_56 ;
int V_14 ;
if ( ! F_196 ( V_353 ) )
return - V_156 ;
F_114 ( & V_31 ) ;
F_82 ( & V_46 ) ;
F_45 (link, &from->cset_links, cset_link)
F_198 ( V_54 -> V_45 , V_353 , & V_261 ) ;
F_83 ( & V_46 ) ;
V_14 = F_199 ( & V_261 ) ;
if ( V_14 )
goto V_354;
do {
F_295 ( & V_294 -> V_20 , & V_61 ) ;
V_56 = F_296 ( & V_61 ) ;
if ( V_56 )
F_218 ( V_56 ) ;
F_297 ( & V_61 ) ;
if ( V_56 ) {
V_14 = F_201 ( V_56 , false , V_353 -> V_7 ) ;
F_219 ( V_56 ) ;
}
} while ( V_56 && ! V_14 );
V_354:
F_197 ( & V_261 ) ;
F_98 ( & V_31 ) ;
return V_14 ;
}
static void * F_299 ( int V_91 )
{
if ( F_300 ( V_91 ) )
return F_301 ( V_91 * sizeof( T_7 ) ) ;
else
return F_130 ( V_91 * sizeof( T_7 ) , V_93 ) ;
}
static void F_302 ( void * V_194 )
{
F_303 ( V_194 ) ;
}
static void F_304 ( struct V_5 * V_6 )
{
struct V_355 * V_347 , * V_356 ;
F_114 ( & V_6 -> V_202 ) ;
F_47 (l, tmp_l, &cgrp->pidlists, links)
F_305 ( V_357 , & V_347 -> V_358 , 0 ) ;
F_98 ( & V_6 -> V_202 ) ;
F_306 ( V_357 ) ;
F_69 ( ! F_40 ( & V_6 -> V_201 ) ) ;
}
static void F_307 ( struct V_359 * V_360 )
{
struct V_361 * V_362 = F_308 ( V_360 ) ;
struct V_355 * V_347 = F_16 ( V_362 , struct V_355 ,
V_358 ) ;
struct V_355 * V_363 = NULL ;
F_114 ( & V_347 -> V_364 -> V_202 ) ;
if ( ! F_309 ( V_362 ) ) {
F_56 ( & V_347 -> V_365 ) ;
F_302 ( V_347 -> V_366 ) ;
F_310 ( V_347 -> V_67 . V_225 ) ;
V_363 = V_347 ;
}
F_98 ( & V_347 -> V_364 -> V_202 ) ;
F_60 ( V_363 ) ;
}
static int F_311 ( T_7 * V_366 , int V_367 )
{
int V_368 , V_369 = 1 ;
if ( V_367 == 0 || V_367 == 1 )
return V_367 ;
for ( V_368 = 1 ; V_368 < V_367 ; V_368 ++ ) {
while ( V_366 [ V_368 ] == V_366 [ V_368 - 1 ] ) {
V_368 ++ ;
if ( V_368 == V_367 )
goto V_370;
}
V_366 [ V_369 ] = V_366 [ V_368 ] ;
V_369 ++ ;
}
V_370:
return V_369 ;
}
static T_7 F_312 ( T_7 V_284 )
{
unsigned V_371 = V_284 & 0x55555555 ;
unsigned V_372 = V_284 & 0xAAAAAAAA ;
return ( V_371 << 1 ) | ( V_372 >> 1 ) ;
}
static T_7 F_313 ( struct V_5 * V_6 , T_7 V_284 )
{
if ( F_4 ( V_6 ) )
return F_312 ( V_284 ) ;
else
return V_284 ;
}
static int F_314 ( const void * V_371 , const void * V_372 )
{
return * ( T_7 * ) V_371 - * ( T_7 * ) V_372 ;
}
static int F_315 ( const void * V_371 , const void * V_372 )
{
return F_312 ( * ( T_7 * ) V_371 ) - F_312 ( * ( T_7 * ) V_372 ) ;
}
static struct V_355 * F_316 ( struct V_5 * V_6 ,
enum V_373 type )
{
struct V_355 * V_347 ;
struct V_374 * V_225 = F_317 ( V_114 ) ;
F_23 ( & V_6 -> V_202 ) ;
F_45 (l, &cgrp->pidlists, links)
if ( V_347 -> V_67 . type == type && V_347 -> V_67 . V_225 == V_225 )
return V_347 ;
return NULL ;
}
static struct V_355 * F_318 ( struct V_5 * V_6 ,
enum V_373 type )
{
struct V_355 * V_347 ;
F_23 ( & V_6 -> V_202 ) ;
V_347 = F_316 ( V_6 , type ) ;
if ( V_347 )
return V_347 ;
V_347 = F_76 ( sizeof( struct V_355 ) , V_93 ) ;
if ( ! V_347 )
return V_347 ;
F_319 ( & V_347 -> V_358 , F_307 ) ;
V_347 -> V_67 . type = type ;
V_347 -> V_67 . V_225 = F_320 ( F_317 ( V_114 ) ) ;
V_347 -> V_364 = V_6 ;
F_77 ( & V_347 -> V_365 , & V_6 -> V_201 ) ;
return V_347 ;
}
static int F_321 ( struct V_5 * V_6 , enum V_373 type ,
struct V_355 * * V_375 )
{
T_7 * V_376 ;
int V_367 ;
int V_284 , V_377 = 0 ;
struct V_60 V_61 ;
struct V_55 * V_283 ;
struct V_355 * V_347 ;
F_23 ( & V_6 -> V_202 ) ;
V_367 = F_283 ( V_6 ) ;
V_376 = F_299 ( V_367 ) ;
if ( ! V_376 )
return - V_94 ;
F_295 ( & V_6 -> V_20 , & V_61 ) ;
while ( ( V_283 = F_296 ( & V_61 ) ) ) {
if ( F_322 ( V_377 == V_367 ) )
break;
if ( type == V_378 )
V_284 = F_323 ( V_283 ) ;
else
V_284 = F_324 ( V_283 ) ;
if ( V_284 > 0 )
V_376 [ V_377 ++ ] = V_284 ;
}
F_297 ( & V_61 ) ;
V_367 = V_377 ;
if ( F_4 ( V_6 ) )
F_325 ( V_376 , V_367 , sizeof( T_7 ) , F_315 , NULL ) ;
else
F_325 ( V_376 , V_367 , sizeof( T_7 ) , F_314 , NULL ) ;
if ( type == V_378 )
V_367 = F_311 ( V_376 , V_367 ) ;
V_347 = F_318 ( V_6 , type ) ;
if ( ! V_347 ) {
F_302 ( V_376 ) ;
return - V_94 ;
}
F_302 ( V_347 -> V_366 ) ;
V_347 -> V_366 = V_376 ;
V_347 -> V_367 = V_367 ;
* V_375 = V_347 ;
return 0 ;
}
int F_326 ( struct V_379 * V_380 , struct V_216 * V_216 )
{
struct V_139 * V_39 = F_327 ( V_216 ) ;
struct V_5 * V_6 ;
struct V_60 V_61 ;
struct V_55 * V_283 ;
if ( V_216 -> V_238 -> V_381 != & V_382 || ! V_39 ||
F_110 ( V_39 ) != V_140 )
return - V_185 ;
F_114 ( & V_31 ) ;
F_25 () ;
V_6 = F_328 ( V_39 -> V_40 ) ;
if ( ! V_6 || F_29 ( V_6 ) ) {
F_28 () ;
F_98 ( & V_31 ) ;
return - V_190 ;
}
F_28 () ;
F_295 ( & V_6 -> V_20 , & V_61 ) ;
while ( ( V_283 = F_296 ( & V_61 ) ) ) {
switch ( V_283 -> V_383 ) {
case V_384 :
V_380 -> V_385 ++ ;
break;
case V_386 :
V_380 -> V_387 ++ ;
break;
case V_388 :
V_380 -> V_389 ++ ;
break;
case V_390 :
V_380 -> V_391 ++ ;
break;
default:
if ( F_329 ( V_283 ) )
V_380 -> V_392 ++ ;
break;
}
}
F_297 ( & V_61 ) ;
F_98 ( & V_31 ) ;
return 0 ;
}
static void * F_330 ( struct V_161 * V_393 , T_6 * V_62 )
{
struct V_37 * V_38 = V_393 -> V_394 ;
struct V_5 * V_6 = F_227 ( V_393 ) -> V_5 ;
struct V_355 * V_347 ;
enum V_373 type = F_254 ( V_393 ) -> V_394 ;
int V_395 = 0 , V_284 = * V_62 ;
int * V_396 , V_14 ;
F_114 ( & V_6 -> V_202 ) ;
if ( V_38 -> V_40 )
V_38 -> V_40 = F_316 ( V_6 , type ) ;
if ( ! V_38 -> V_40 ) {
V_14 = F_321 ( V_6 , type ,
(struct V_355 * * ) & V_38 -> V_40 ) ;
if ( V_14 )
return F_168 ( V_14 ) ;
}
V_347 = V_38 -> V_40 ;
if ( V_284 ) {
int V_12 = V_347 -> V_367 ;
while ( V_395 < V_12 ) {
int V_397 = ( V_395 + V_12 ) / 2 ;
if ( F_313 ( V_6 , V_347 -> V_366 [ V_397 ] ) == V_284 ) {
V_395 = V_397 ;
break;
} else if ( F_313 ( V_6 , V_347 -> V_366 [ V_397 ] ) <= V_284 )
V_395 = V_397 + 1 ;
else
V_12 = V_397 ;
}
}
if ( V_395 >= V_347 -> V_367 )
return NULL ;
V_396 = V_347 -> V_366 + V_395 ;
* V_62 = F_313 ( V_6 , * V_396 ) ;
return V_396 ;
}
static void F_331 ( struct V_161 * V_393 , void * V_297 )
{
struct V_37 * V_38 = V_393 -> V_394 ;
struct V_355 * V_347 = V_38 -> V_40 ;
if ( V_347 )
F_305 ( V_357 , & V_347 -> V_358 ,
V_398 ) ;
F_98 ( & F_227 ( V_393 ) -> V_5 -> V_202 ) ;
}
static void * F_332 ( struct V_161 * V_393 , void * V_297 , T_6 * V_62 )
{
struct V_37 * V_38 = V_393 -> V_394 ;
struct V_355 * V_347 = V_38 -> V_40 ;
T_7 * V_194 = V_297 ;
T_7 * V_12 = V_347 -> V_366 + V_347 -> V_367 ;
V_194 ++ ;
if ( V_194 >= V_12 ) {
return NULL ;
} else {
* V_62 = F_313 ( F_227 ( V_393 ) -> V_5 , * V_194 ) ;
return V_194 ;
}
}
static int F_333 ( struct V_161 * V_393 , void * V_297 )
{
F_231 ( V_393 , L_31 , * ( int * ) V_297 ) ;
return 0 ;
}
static T_8 F_334 ( struct V_18 * V_32 ,
struct V_41 * V_42 )
{
return F_37 ( V_32 -> V_5 ) ;
}
static int F_335 ( struct V_18 * V_32 ,
struct V_41 * V_42 , T_8 V_399 )
{
if ( V_399 )
F_156 ( V_43 , & V_32 -> V_5 -> V_35 ) ;
else
F_336 ( V_43 , & V_32 -> V_5 -> V_35 ) ;
return 0 ;
}
static T_8 F_337 ( struct V_18 * V_32 ,
struct V_41 * V_42 )
{
return F_38 ( V_173 , & V_32 -> V_5 -> V_35 ) ;
}
static int F_338 ( struct V_18 * V_32 ,
struct V_41 * V_42 , T_8 V_399 )
{
if ( V_399 )
F_156 ( V_173 , & V_32 -> V_5 -> V_35 ) ;
else
F_336 ( V_173 , & V_32 -> V_5 -> V_35 ) ;
return 0 ;
}
static void F_339 ( struct V_359 * V_360 )
{
struct V_18 * V_32 =
F_16 ( V_360 , struct V_18 , V_400 ) ;
struct V_28 * V_29 = V_32 -> V_29 ;
struct V_5 * V_6 = V_32 -> V_5 ;
F_163 ( & V_32 -> V_208 ) ;
if ( V_29 ) {
struct V_18 * V_21 = V_32 -> V_21 ;
int V_17 = V_32 -> V_17 ;
V_29 -> V_401 ( V_32 ) ;
F_13 ( & V_29 -> V_402 , V_17 ) ;
F_59 ( V_6 ) ;
if ( V_21 )
F_57 ( V_21 ) ;
} else {
F_340 ( & V_6 -> V_7 -> V_110 ) ;
F_304 ( V_6 ) ;
F_341 ( & V_6 -> V_204 ) ;
if ( F_15 ( V_6 ) ) {
F_59 ( F_15 ( V_6 ) ) ;
F_342 ( V_6 -> V_39 ) ;
F_60 ( V_6 ) ;
} else {
F_93 ( V_6 -> V_7 ) ;
}
}
}
static void F_343 ( struct V_76 * V_76 )
{
struct V_18 * V_32 =
F_16 ( V_76 , struct V_18 , V_76 ) ;
F_153 ( & V_32 -> V_400 , F_339 ) ;
F_344 ( V_403 , & V_32 -> V_400 ) ;
}
static void F_345 ( struct V_359 * V_360 )
{
struct V_18 * V_32 =
F_16 ( V_360 , struct V_18 , V_400 ) ;
struct V_28 * V_29 = V_32 -> V_29 ;
struct V_5 * V_6 = V_32 -> V_5 ;
F_114 ( & V_31 ) ;
V_32 -> V_35 |= V_343 ;
F_346 ( & V_32 -> V_200 ) ;
if ( V_29 ) {
F_11 ( & V_29 -> V_402 , NULL , V_32 -> V_17 ) ;
if ( V_29 -> V_404 )
V_29 -> V_404 ( V_32 ) ;
} else {
F_13 ( & V_6 -> V_7 -> V_109 , V_6 -> V_17 ) ;
V_6 -> V_17 = - 1 ;
if ( V_6 -> V_39 )
F_123 ( * ( void V_405 V_406 * * ) & V_6 -> V_39 -> V_40 ,
NULL ) ;
}
F_98 ( & V_31 ) ;
F_347 ( & V_32 -> V_76 , F_343 ) ;
}
static void V_209 ( struct V_407 * V_408 )
{
struct V_18 * V_32 =
F_16 ( V_408 , struct V_18 , V_208 ) ;
F_153 ( & V_32 -> V_400 , F_345 ) ;
F_344 ( V_403 , & V_32 -> V_400 ) ;
}
static void F_348 ( struct V_18 * V_32 ,
struct V_28 * V_29 , struct V_5 * V_6 )
{
F_23 ( & V_31 ) ;
F_30 ( V_6 ) ;
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_32 -> V_5 = V_6 ;
V_32 -> V_29 = V_29 ;
V_32 -> V_17 = - 1 ;
F_75 ( & V_32 -> V_200 ) ;
F_75 ( & V_32 -> V_111 ) ;
V_32 -> V_344 = V_409 ++ ;
F_84 ( & V_32 -> V_410 , 0 ) ;
if ( F_15 ( V_6 ) ) {
V_32 -> V_21 = F_19 ( F_15 ( V_6 ) , V_29 ) ;
F_27 ( V_32 -> V_21 ) ;
}
F_69 ( F_19 ( V_6 , V_29 ) ) ;
}
static int F_349 ( struct V_18 * V_32 )
{
struct V_28 * V_29 = V_32 -> V_29 ;
int V_14 = 0 ;
F_23 ( & V_31 ) ;
if ( V_29 -> V_411 )
V_14 = V_29 -> V_411 ( V_32 ) ;
if ( ! V_14 ) {
V_32 -> V_35 |= V_36 ;
F_50 ( V_32 -> V_5 -> V_30 [ V_29 -> V_17 ] , V_32 ) ;
F_67 ( & V_32 -> V_410 ) ;
if ( V_32 -> V_21 )
F_67 ( & V_32 -> V_21 -> V_410 ) ;
}
return V_14 ;
}
static void F_350 ( struct V_18 * V_32 )
{
struct V_28 * V_29 = V_32 -> V_29 ;
F_23 ( & V_31 ) ;
if ( ! ( V_32 -> V_35 & V_36 ) )
return;
if ( V_29 -> V_305 )
V_29 -> V_305 ( V_32 ) ;
if ( V_29 -> V_412 )
V_29 -> V_412 ( V_32 ) ;
V_32 -> V_35 &= ~ V_36 ;
F_123 ( V_32 -> V_5 -> V_30 [ V_29 -> V_17 ] , NULL ) ;
F_351 ( & V_32 -> V_5 -> V_203 ) ;
}
static struct V_18 * F_243 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
struct V_5 * V_21 = F_15 ( V_6 ) ;
struct V_18 * V_19 = F_19 ( V_21 , V_29 ) ;
struct V_18 * V_32 ;
int V_151 ;
F_23 ( & V_31 ) ;
V_32 = V_29 -> V_413 ( V_19 ) ;
if ( F_161 ( V_32 ) )
return V_32 ;
F_348 ( V_32 , V_29 , V_6 ) ;
V_151 = F_159 ( & V_32 -> V_208 , V_209 , 0 , V_93 ) ;
if ( V_151 )
goto V_414;
V_151 = F_5 ( & V_29 -> V_402 , NULL , 2 , 0 , V_93 ) ;
if ( V_151 < 0 )
goto V_414;
V_32 -> V_17 = V_151 ;
F_352 ( & V_32 -> V_200 , & V_19 -> V_111 ) ;
F_11 ( & V_29 -> V_402 , V_32 , V_32 -> V_17 ) ;
V_151 = F_349 ( V_32 ) ;
if ( V_151 )
goto V_415;
if ( V_29 -> V_416 && ! V_29 -> V_417 &&
F_15 ( V_21 ) ) {
F_127 ( L_32 ,
V_114 -> V_193 , V_114 -> V_284 , V_29 -> V_122 ) ;
if ( ! strcmp ( V_29 -> V_122 , L_33 ) )
F_127 ( L_34 ) ;
V_29 -> V_417 = true ;
}
return V_32 ;
V_415:
F_346 ( & V_32 -> V_200 ) ;
V_414:
F_347 ( & V_32 -> V_76 , F_343 ) ;
return F_168 ( V_151 ) ;
}
static struct V_5 * F_353 ( struct V_5 * V_21 )
{
struct V_89 * V_7 = V_21 -> V_7 ;
struct V_5 * V_6 , * V_418 ;
int V_419 = V_21 -> V_419 + 1 ;
int V_14 ;
V_6 = F_76 ( sizeof( * V_6 ) +
sizeof( V_6 -> V_207 [ 0 ] ) * ( V_419 + 1 ) , V_93 ) ;
if ( ! V_6 )
return F_168 ( - V_94 ) ;
V_14 = F_159 ( & V_6 -> V_20 . V_208 , V_209 , 0 , V_93 ) ;
if ( V_14 )
goto V_420;
V_6 -> V_17 = F_5 ( & V_7 -> V_109 , NULL , 2 , 0 , V_93 ) ;
if ( V_6 -> V_17 < 0 ) {
V_14 = - V_94 ;
goto V_421;
}
F_150 ( V_6 ) ;
V_6 -> V_20 . V_21 = & V_21 -> V_20 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_419 = V_419 ;
for ( V_418 = V_6 ; V_418 ; V_418 = F_15 ( V_418 ) )
V_6 -> V_207 [ V_418 -> V_419 ] = V_418 -> V_17 ;
if ( F_37 ( V_21 ) )
F_156 ( V_43 , & V_6 -> V_35 ) ;
if ( F_38 ( V_173 , & V_21 -> V_35 ) )
F_156 ( V_173 , & V_6 -> V_35 ) ;
V_6 -> V_20 . V_344 = V_409 ++ ;
F_352 ( & V_6 -> V_20 . V_200 , & F_15 ( V_6 ) -> V_20 . V_111 ) ;
F_67 ( & V_7 -> V_110 ) ;
F_30 ( V_21 ) ;
F_11 ( & V_7 -> V_109 , V_6 , V_6 -> V_17 ) ;
if ( ! F_4 ( V_6 ) )
V_6 -> V_24 = F_17 ( V_6 ) ;
F_237 ( V_6 ) ;
V_14 = F_241 ( V_6 ) ;
if ( V_14 )
goto V_422;
return V_6 ;
V_421:
F_163 ( & V_6 -> V_20 . V_208 ) ;
V_420:
F_60 ( V_6 ) ;
return F_168 ( V_14 ) ;
V_422:
F_354 ( V_6 ) ;
return F_168 ( V_14 ) ;
}
static int F_355 ( struct V_139 * V_423 , const char * V_122 ,
T_3 V_124 )
{
struct V_5 * V_21 , * V_6 ;
struct V_139 * V_39 ;
int V_14 ;
if ( strchr ( V_122 , '\n' ) )
return - V_185 ;
V_21 = F_112 ( V_423 , false ) ;
if ( ! V_21 )
return - V_285 ;
V_6 = F_353 ( V_21 ) ;
if ( F_161 ( V_6 ) ) {
V_14 = F_162 ( V_6 ) ;
goto V_33;
}
V_39 = F_356 ( V_21 -> V_39 , V_122 , V_124 , V_6 ) ;
if ( F_161 ( V_39 ) ) {
V_14 = F_162 ( V_39 ) ;
goto V_422;
}
V_6 -> V_39 = V_39 ;
F_357 ( V_39 ) ;
V_14 = F_263 ( V_39 ) ;
if ( V_14 )
goto V_422;
V_14 = F_119 ( & V_6 -> V_20 ) ;
if ( V_14 )
goto V_422;
V_14 = F_241 ( V_6 ) ;
if ( V_14 )
goto V_422;
F_128 ( V_39 ) ;
V_14 = 0 ;
goto V_33;
V_422:
F_354 ( V_6 ) ;
V_33:
F_109 ( V_423 ) ;
return V_14 ;
}
static void F_358 ( struct V_359 * V_360 )
{
struct V_18 * V_32 =
F_16 ( V_360 , struct V_18 , V_400 ) ;
F_114 ( & V_31 ) ;
do {
F_350 ( V_32 ) ;
F_57 ( V_32 ) ;
V_32 = V_32 -> V_21 ;
} while ( V_32 && F_55 ( & V_32 -> V_410 ) );
F_98 ( & V_31 ) ;
}
static void F_359 ( struct V_407 * V_408 )
{
struct V_18 * V_32 =
F_16 ( V_408 , struct V_18 , V_208 ) ;
if ( F_55 ( & V_32 -> V_410 ) ) {
F_153 ( & V_32 -> V_400 , F_358 ) ;
F_344 ( V_403 , & V_32 -> V_400 ) ;
}
}
static void F_245 ( struct V_18 * V_32 )
{
F_23 ( & V_31 ) ;
F_117 ( V_32 ) ;
F_27 ( V_32 ) ;
F_360 ( & V_32 -> V_208 , F_359 ) ;
}
static int F_354 ( struct V_5 * V_6 )
__releases( &cgroup_mutex
static int F_361 ( struct V_139 * V_39 )
{
struct V_5 * V_6 ;
int V_14 = 0 ;
V_6 = F_112 ( V_39 , false ) ;
if ( ! V_6 )
return 0 ;
V_14 = F_354 ( V_6 ) ;
F_109 ( V_39 ) ;
return V_14 ;
}
static void T_9 F_362 ( struct V_28 * V_29 , bool V_424 )
{
struct V_18 * V_32 ;
F_363 ( L_35 , V_29 -> V_122 ) ;
F_114 ( & V_31 ) ;
F_155 ( & V_29 -> V_402 ) ;
F_75 ( & V_29 -> V_146 ) ;
V_29 -> V_7 = & V_8 ;
V_32 = V_29 -> V_413 ( F_19 ( & V_8 . V_6 , V_29 ) ) ;
F_69 ( F_161 ( V_32 ) ) ;
F_348 ( V_32 , V_29 , & V_8 . V_6 ) ;
V_32 -> V_35 |= V_425 ;
if ( V_424 ) {
V_32 -> V_17 = 1 ;
} else {
V_32 -> V_17 = F_5 ( & V_29 -> V_402 , V_32 , 1 , 2 , V_93 ) ;
F_69 ( V_32 -> V_17 < 0 ) ;
}
V_34 . V_30 [ V_29 -> V_17 ] = V_32 ;
V_426 |= ( bool ) V_29 -> V_427 << V_29 -> V_17 ;
V_428 |= ( bool ) V_29 -> exit << V_29 -> V_17 ;
V_429 |= ( bool ) V_29 -> free << V_29 -> V_17 ;
V_430 |= ( bool ) V_29 -> V_431 << V_29 -> V_17 ;
F_69 ( ! F_40 ( & V_432 . V_47 ) ) ;
F_69 ( F_349 ( V_32 ) ) ;
F_98 ( & V_31 ) ;
}
int T_9 F_364 ( void )
{
static struct V_175 T_10 V_176 ;
struct V_28 * V_29 ;
int V_68 ;
F_154 ( & V_8 , & V_176 ) ;
V_8 . V_6 . V_20 . V_35 |= V_425 ;
F_123 ( V_432 . V_66 , & V_34 ) ;
F_53 (ss, i) {
F_365 ( ! V_29 -> V_413 || ! V_29 -> V_401 || V_29 -> V_122 || V_29 -> V_17 ,
L_36 ,
V_68 , V_433 [ V_68 ] , V_29 -> V_413 , V_29 -> V_401 ,
V_29 -> V_17 , V_29 -> V_122 ) ;
F_365 ( strlen ( V_433 [ V_68 ] ) > V_434 ,
L_37 , V_433 [ V_68 ] ) ;
V_29 -> V_17 = V_68 ;
V_29 -> V_122 = V_433 [ V_68 ] ;
if ( ! V_29 -> V_123 )
V_29 -> V_123 = V_433 [ V_68 ] ;
if ( V_29 -> V_435 )
F_362 ( V_29 , true ) ;
}
return 0 ;
}
int T_9 F_366 ( void )
{
struct V_28 * V_29 ;
int V_1 ;
F_225 ( V_2 > 16 ) ;
F_69 ( F_367 ( & V_286 ) ) ;
F_69 ( F_275 ( NULL , V_149 ) ) ;
F_69 ( F_275 ( NULL , V_150 ) ) ;
F_368 ( V_236 . V_227 ) ;
F_114 ( & V_31 ) ;
F_86 ( V_102 , & V_34 . V_72 ,
F_52 ( V_34 . V_30 ) ) ;
F_69 ( F_157 ( & V_8 , 0 ) ) ;
F_98 ( & V_31 ) ;
F_53 (ss, ssid) {
if ( V_29 -> V_435 ) {
struct V_18 * V_32 =
V_34 . V_30 [ V_29 -> V_17 ] ;
V_32 -> V_17 = F_5 ( & V_29 -> V_402 , V_32 , 1 , 2 ,
V_93 ) ;
F_69 ( V_32 -> V_17 < 0 ) ;
} else {
F_362 ( V_29 , false ) ;
}
F_51 ( & V_34 . V_71 [ V_1 ] ,
& V_8 . V_6 . V_103 [ V_1 ] ) ;
if ( V_436 & ( 1 << V_1 ) ) {
F_126 ( V_3 [ V_1 ] ) ;
F_369 ( V_437 L_38 ,
V_29 -> V_122 ) ;
continue;
}
if ( F_3 ( V_1 ) )
F_369 ( V_437 L_39 ,
V_29 -> V_122 ) ;
V_8 . V_23 |= 1 << V_29 -> V_17 ;
if ( V_29 -> V_155 )
V_26 |= 1 << V_29 -> V_17 ;
else if ( ! V_29 -> V_438 )
V_25 |= 1 << V_29 -> V_17 ;
if ( V_29 -> V_438 == V_29 -> V_439 ) {
F_96 ( F_279 ( V_29 , V_29 -> V_438 ) ) ;
} else {
F_96 ( F_280 ( V_29 , V_29 -> V_438 ) ) ;
F_96 ( F_281 ( V_29 , V_29 -> V_439 ) ) ;
}
if ( V_29 -> V_160 )
V_29 -> V_160 ( V_34 . V_30 [ V_1 ] ) ;
}
F_58 ( & V_34 . V_72 ) ;
F_86 ( V_102 , & V_34 . V_72 ,
F_52 ( V_34 . V_30 ) ) ;
F_96 ( F_370 ( V_440 , L_40 ) ) ;
F_96 ( F_371 ( & V_382 ) ) ;
F_96 ( F_371 ( & V_221 ) ) ;
F_96 ( ! F_372 ( L_41 , 0 , NULL , & V_441 ) ) ;
return 0 ;
}
static int T_9 F_373 ( void )
{
V_403 = F_374 ( L_42 , 0 , 1 ) ;
F_69 ( ! V_403 ) ;
V_357 = F_374 ( L_43 ,
0 , 1 ) ;
F_69 ( ! V_357 ) ;
return 0 ;
}
int F_375 ( struct V_161 * V_311 , struct V_374 * V_225 ,
struct V_284 * V_284 , struct V_55 * V_283 )
{
char * V_118 , * V_241 ;
int V_295 ;
struct V_89 * V_7 ;
V_295 = - V_94 ;
V_118 = F_130 ( V_167 , V_93 ) ;
if ( ! V_118 )
goto V_206;
F_114 ( & V_31 ) ;
F_82 ( & V_46 ) ;
F_172 (root) {
struct V_28 * V_29 ;
struct V_5 * V_6 ;
int V_1 , V_91 = 0 ;
if ( V_7 == & V_8 && ! V_230 )
continue;
F_231 ( V_311 , L_44 , V_7 -> V_108 ) ;
if ( V_7 != & V_8 )
F_53 (ss, ssid)
if ( V_7 -> V_23 & ( 1 << V_1 ) )
F_231 ( V_311 , L_45 , V_91 ++ ? L_9 : L_20 ,
V_29 -> V_123 ) ;
if ( strlen ( V_7 -> V_122 ) )
F_231 ( V_311 , L_46 , V_91 ? L_9 : L_20 ,
V_7 -> V_122 ) ;
F_228 ( V_311 , ':' ) ;
V_6 = F_102 ( V_283 , V_7 ) ;
if ( F_4 ( V_6 ) || ! ( V_283 -> V_35 & V_65 ) ) {
V_241 = F_184 ( V_6 , V_118 , V_167 ,
V_114 -> V_115 -> V_116 ) ;
if ( ! V_241 ) {
V_295 = - V_442 ;
goto V_33;
}
} else {
V_241 = L_23 ;
}
F_135 ( V_311 , V_241 ) ;
if ( F_4 ( V_6 ) && F_29 ( V_6 ) )
F_135 ( V_311 , L_47 ) ;
else
F_228 ( V_311 , '\n' ) ;
}
V_295 = 0 ;
V_33:
F_83 ( & V_46 ) ;
F_98 ( & V_31 ) ;
F_60 ( V_118 ) ;
V_206:
return V_295 ;
}
static int F_376 ( struct V_161 * V_311 , void * V_297 )
{
struct V_28 * V_29 ;
int V_68 ;
F_135 ( V_311 , L_48 ) ;
F_114 ( & V_31 ) ;
F_53 (ss, i)
F_231 ( V_311 , L_49 ,
V_29 -> V_123 , V_29 -> V_7 -> V_108 ,
F_95 ( & V_29 -> V_7 -> V_110 ) ,
F_1 ( V_68 ) ) ;
F_98 ( & V_31 ) ;
return 0 ;
}
static int F_377 ( struct V_278 * V_278 , struct V_276 * V_276 )
{
return F_378 ( V_276 , F_376 , NULL ) ;
}
void F_379 ( struct V_55 * V_308 )
{
F_123 ( V_308 -> V_66 , & V_34 ) ;
F_75 ( & V_308 -> V_63 ) ;
}
int F_380 ( struct V_55 * V_308 )
{
struct V_28 * V_29 ;
int V_68 , V_443 , V_14 ;
F_107 (ss, i, have_canfork_callback) {
V_14 = V_29 -> V_431 ( V_308 ) ;
if ( V_14 )
goto V_444;
} F_108 () ;
return 0 ;
V_444:
F_53 (ss, j) {
if ( V_443 >= V_68 )
break;
if ( V_29 -> V_445 )
V_29 -> V_445 ( V_308 ) ;
}
return V_14 ;
}
void F_381 ( struct V_55 * V_308 )
{
struct V_28 * V_29 ;
int V_68 ;
F_53 (ss, i)
if ( V_29 -> V_445 )
V_29 -> V_445 ( V_308 ) ;
}
void F_382 ( struct V_55 * V_308 )
{
struct V_28 * V_29 ;
int V_68 ;
if ( V_196 ) {
struct V_44 * V_45 ;
F_82 ( & V_46 ) ;
V_45 = F_103 ( V_114 ) ;
if ( F_40 ( & V_308 -> V_63 ) ) {
F_66 ( V_45 ) ;
F_46 ( V_308 , NULL , V_45 , false ) ;
}
F_83 ( & V_46 ) ;
}
F_107 (ss, i, have_fork_callback) {
V_29 -> V_427 ( V_308 ) ;
} F_108 () ;
}
void F_383 ( struct V_55 * V_283 )
{
struct V_28 * V_29 ;
struct V_44 * V_45 ;
int V_68 ;
V_45 = F_103 ( V_283 ) ;
if ( ! F_40 ( & V_283 -> V_63 ) ) {
F_82 ( & V_46 ) ;
F_46 ( V_283 , V_45 , NULL , false ) ;
F_83 ( & V_46 ) ;
} else {
F_66 ( V_45 ) ;
}
F_107 (ss, i, have_exit_callback) {
V_29 -> exit ( V_283 ) ;
} F_108 () ;
}
void F_384 ( struct V_55 * V_56 )
{
struct V_44 * V_45 = F_103 ( V_56 ) ;
struct V_28 * V_29 ;
int V_1 ;
F_107 (ss, ssid, have_free_callback) {
V_29 -> free ( V_56 ) ;
} F_108 () ;
F_62 ( V_45 ) ;
}
static void F_42 ( struct V_5 * V_6 )
{
if ( F_37 ( V_6 ) && ! F_249 ( V_6 ) &&
! F_293 ( & V_6 -> V_20 ) && ! F_29 ( V_6 ) )
F_385 ( & V_6 -> V_204 ) ;
}
static void V_205 ( struct V_359 * V_360 )
{
struct V_5 * V_6 =
F_16 ( V_360 , struct V_5 , V_204 ) ;
char * V_446 = NULL , * V_447 = NULL , * V_241 ;
char * V_448 [ 3 ] , * V_449 [ 3 ] ;
F_114 ( & V_31 ) ;
V_446 = F_130 ( V_167 , V_93 ) ;
V_447 = F_386 ( V_6 -> V_7 -> V_172 , V_93 ) ;
if ( ! V_446 || ! V_447 )
goto V_206;
F_82 ( & V_46 ) ;
V_241 = F_184 ( V_6 , V_446 , V_167 , & V_236 ) ;
F_83 ( & V_46 ) ;
if ( ! V_241 )
goto V_206;
V_448 [ 0 ] = V_447 ;
V_448 [ 1 ] = V_241 ;
V_448 [ 2 ] = NULL ;
V_449 [ 0 ] = L_50 ;
V_449 [ 1 ] = L_51 ;
V_449 [ 2 ] = NULL ;
F_98 ( & V_31 ) ;
F_387 ( V_448 [ 0 ] , V_448 , V_449 , V_450 ) ;
goto V_232;
V_206:
F_98 ( & V_31 ) ;
V_232:
F_60 ( V_447 ) ;
F_60 ( V_446 ) ;
}
static int T_9 F_388 ( char * V_451 )
{
struct V_28 * V_29 ;
char * V_177 ;
int V_68 ;
while ( ( V_177 = F_140 ( & V_451 , L_9 ) ) != NULL ) {
if ( ! * V_177 )
continue;
F_53 (ss, i) {
if ( strcmp ( V_177 , V_29 -> V_122 ) &&
strcmp ( V_177 , V_29 -> V_123 ) )
continue;
V_436 |= 1 << V_68 ;
}
}
return 1 ;
}
static int T_9 F_389 ( char * V_451 )
{
struct V_28 * V_29 ;
char * V_177 ;
int V_68 ;
while ( ( V_177 = F_140 ( & V_451 , L_9 ) ) != NULL ) {
if ( ! * V_177 )
continue;
if ( ! strcmp ( V_177 , L_11 ) ) {
V_4 = V_182 ;
break;
}
F_53 (ss, i) {
if ( strcmp ( V_177 , V_29 -> V_122 ) &&
strcmp ( V_177 , V_29 -> V_123 ) )
continue;
V_4 |= 1 << V_68 ;
}
}
return 1 ;
}
struct V_18 * F_390 ( struct V_216 * V_216 ,
struct V_28 * V_29 )
{
struct V_139 * V_39 = F_327 ( V_216 ) ;
struct V_217 * V_381 = V_216 -> V_238 -> V_381 ;
struct V_18 * V_32 = NULL ;
struct V_5 * V_6 ;
if ( ( V_381 != & V_382 && V_381 != & V_221 ) ||
! V_39 || F_110 ( V_39 ) != V_140 )
return F_168 ( - V_452 ) ;
F_25 () ;
V_6 = F_328 ( V_39 -> V_40 ) ;
if ( V_6 )
V_32 = F_19 ( V_6 , V_29 ) ;
if ( ! V_32 || ! F_26 ( V_32 ) )
V_32 = F_168 ( - V_190 ) ;
F_28 () ;
return V_32 ;
}
struct V_18 * F_391 ( int V_17 , struct V_28 * V_29 )
{
F_31 ( ! F_392 () ) ;
return V_17 > 0 ? F_393 ( & V_29 -> V_402 , V_17 ) : NULL ;
}
struct V_5 * F_394 ( const char * V_241 )
{
struct V_139 * V_39 ;
struct V_5 * V_6 ;
F_114 ( & V_31 ) ;
V_39 = F_395 ( V_8 . V_6 . V_39 , V_241 ) ;
if ( V_39 ) {
if ( F_110 ( V_39 ) == V_140 ) {
V_6 = V_39 -> V_40 ;
F_30 ( V_6 ) ;
} else {
V_6 = F_168 ( - V_315 ) ;
}
F_342 ( V_39 ) ;
} else {
V_6 = F_168 ( - V_190 ) ;
}
F_98 ( & V_31 ) ;
return V_6 ;
}
void F_396 ( void )
{
if ( V_453 )
return;
F_397 ( L_52 ) ;
V_453 = true ;
}
void F_398 ( struct V_454 * V_455 )
{
if ( V_453 )
return;
F_25 () ;
while ( true ) {
struct V_44 * V_45 ;
V_45 = F_103 ( V_114 ) ;
if ( F_286 ( F_32 ( V_45 -> V_95 ) ) ) {
V_455 -> V_399 = ( unsigned long ) V_45 -> V_95 ;
break;
}
F_399 () ;
}
F_28 () ;
}
void F_400 ( struct V_454 * V_455 )
{
F_59 ( F_401 ( V_455 ) ) ;
}
static struct V_224 * F_402 ( void )
{
struct V_224 * V_456 ;
int V_14 ;
V_456 = F_76 ( sizeof( struct V_224 ) , V_93 ) ;
if ( ! V_456 )
return F_168 ( - V_94 ) ;
V_14 = F_403 ( & V_456 -> V_225 ) ;
if ( V_14 ) {
F_60 ( V_456 ) ;
return F_168 ( V_14 ) ;
}
F_84 ( & V_456 -> V_91 , 1 ) ;
V_456 -> V_225 . V_457 = & V_458 ;
return V_456 ;
}
void F_404 ( struct V_224 * V_225 )
{
F_62 ( V_225 -> V_117 ) ;
F_405 ( V_225 -> V_227 ) ;
F_406 ( & V_225 -> V_225 ) ;
F_60 ( V_225 ) ;
}
struct V_224 * F_407 ( unsigned long V_35 ,
struct V_459 * V_227 ,
struct V_224 * V_460 )
{
struct V_224 * V_456 ;
struct V_44 * V_45 ;
F_69 ( ! V_460 ) ;
if ( ! ( V_35 & V_461 ) ) {
F_165 ( V_460 ) ;
return V_460 ;
}
if ( ! F_166 ( V_227 , V_228 ) )
return F_168 ( - V_229 ) ;
F_114 ( & V_31 ) ;
F_82 ( & V_46 ) ;
V_45 = F_103 ( V_114 ) ;
F_66 ( V_45 ) ;
F_83 ( & V_46 ) ;
F_98 ( & V_31 ) ;
V_456 = F_402 () ;
if ( F_161 ( V_456 ) ) {
F_62 ( V_45 ) ;
return V_456 ;
}
V_456 -> V_227 = F_368 ( V_227 ) ;
V_456 -> V_117 = V_45 ;
return V_456 ;
}
static inline struct V_224 * F_408 ( struct V_462 * V_225 )
{
return F_16 ( V_225 , struct V_224 , V_225 ) ;
}
static int F_409 ( struct V_115 * V_115 , struct V_462 * V_225 )
{
struct V_224 * V_116 = F_408 ( V_225 ) ;
if ( ! F_166 ( F_410 () , V_228 ) ||
! F_166 ( V_116 -> V_227 , V_228 ) )
return - V_229 ;
if ( V_116 == V_115 -> V_116 )
return 0 ;
F_165 ( V_116 ) ;
F_167 ( V_115 -> V_116 ) ;
V_115 -> V_116 = V_116 ;
return 0 ;
}
static struct V_462 * F_411 ( struct V_55 * V_56 )
{
struct V_224 * V_225 = NULL ;
struct V_115 * V_115 ;
F_412 ( V_56 ) ;
V_115 = V_56 -> V_115 ;
if ( V_115 ) {
V_225 = V_115 -> V_116 ;
F_165 ( V_225 ) ;
}
F_413 ( V_56 ) ;
return V_225 ? & V_225 -> V_225 : NULL ;
}
static void F_414 ( struct V_462 * V_225 )
{
F_167 ( F_408 ( V_225 ) ) ;
}
static T_9 int F_415 ( void )
{
return 0 ;
}
static struct V_18 *
F_416 ( struct V_18 * V_19 )
{
struct V_18 * V_32 = F_76 ( sizeof( * V_32 ) , V_93 ) ;
if ( ! V_32 )
return F_168 ( - V_94 ) ;
return V_32 ;
}
static void F_417 ( struct V_18 * V_32 )
{
F_60 ( V_32 ) ;
}
static T_8 F_418 ( struct V_18 * V_32 ,
struct V_41 * V_42 )
{
return F_283 ( V_32 -> V_5 ) ;
}
static T_8 F_419 ( struct V_18 * V_32 ,
struct V_41 * V_42 )
{
return ( T_8 ) ( unsigned long ) V_114 -> V_66 ;
}
static T_8 F_420 ( struct V_18 * V_32 ,
struct V_41 * V_42 )
{
T_8 V_91 ;
F_25 () ;
V_91 = F_95 ( & F_103 ( V_114 ) -> V_70 ) ;
F_28 () ;
return V_91 ;
}
static int F_421 ( struct V_161 * V_169 , void * V_297 )
{
struct V_53 * V_54 ;
struct V_44 * V_45 ;
char * V_463 ;
V_463 = F_130 ( V_464 + 1 , V_93 ) ;
if ( ! V_463 )
return - V_94 ;
F_82 ( & V_46 ) ;
F_25 () ;
V_45 = F_328 ( V_114 -> V_66 ) ;
F_45 (link, &cset->cgrp_links, cgrp_link) {
struct V_5 * V_101 = V_54 -> V_6 ;
F_422 ( V_101 , V_463 , V_464 + 1 ) ;
F_231 ( V_169 , L_53 ,
V_101 -> V_7 -> V_108 , V_463 ) ;
}
F_28 () ;
F_83 ( & V_46 ) ;
F_60 ( V_463 ) ;
return 0 ;
}
static int F_423 ( struct V_161 * V_169 , void * V_297 )
{
struct V_18 * V_32 = F_227 ( V_169 ) ;
struct V_53 * V_54 ;
F_82 ( & V_46 ) ;
F_45 (link, &css->cgroup->cset_links, cset_link) {
struct V_44 * V_45 = V_54 -> V_45 ;
struct V_55 * V_56 ;
int V_91 = 0 ;
F_231 ( V_169 , L_54 , V_45 ) ;
F_45 (task, &cset->tasks, cg_list) {
if ( V_91 ++ > V_465 )
goto V_466;
F_231 ( V_169 , L_55 , F_324 ( V_56 ) ) ;
}
F_45 (task, &cset->mg_tasks, cg_list) {
if ( V_91 ++ > V_465 )
goto V_466;
F_231 ( V_169 , L_55 , F_324 ( V_56 ) ) ;
}
continue;
V_466:
F_135 ( V_169 , L_56 ) ;
}
F_83 ( & V_46 ) ;
return 0 ;
}
static T_8 F_424 ( struct V_18 * V_32 , struct V_41 * V_42 )
{
return ( ! F_249 ( V_32 -> V_5 ) &&
! F_293 ( & V_32 -> V_5 -> V_20 ) ) ;
}
