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
F_14 ( & V_107 , V_7 -> V_108 ) ;
}
static void F_91 ( struct V_89 * V_7 )
{
if ( V_7 ) {
F_92 ( & V_7 -> V_109 ) ;
F_60 ( V_7 ) ;
}
}
static void F_93 ( struct V_89 * V_7 )
{
struct V_5 * V_6 = & V_7 -> V_6 ;
struct V_53 * V_54 , * V_69 ;
F_94 ( V_7 ) ;
F_95 ( & V_8 . V_6 ) ;
F_69 ( F_96 ( & V_7 -> V_110 ) ) ;
F_69 ( ! F_40 ( & V_6 -> V_20 . V_111 ) ) ;
F_97 ( F_98 ( & V_8 , V_7 -> V_23 ) ) ;
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
F_99 ( & V_31 ) ;
F_100 ( V_7 -> V_105 ) ;
F_91 ( V_7 ) ;
}
static struct V_5 *
F_101 ( struct V_89 * V_7 )
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
static struct V_5 * F_102 ( struct V_44 * V_45 ,
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
static struct V_5 * F_103 ( struct V_55 * V_56 ,
struct V_89 * V_7 )
{
return F_102 ( F_104 ( V_56 ) , V_7 ) ;
}
static char * F_105 ( struct V_5 * V_6 , const struct V_41 * V_42 ,
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
static T_3 F_106 ( const struct V_41 * V_42 )
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
static T_2 F_107 ( T_2 V_24 , T_2 V_135 )
{
T_2 V_136 = V_24 ;
struct V_28 * V_29 ;
int V_1 ;
F_23 ( & V_31 ) ;
V_136 |= V_26 ;
while ( true ) {
T_2 V_137 = V_136 ;
F_108 (ss, ssid, cur_ss_mask) {
V_137 |= V_29 -> V_138 ;
} F_109 () ;
V_137 &= V_135 ;
if ( V_137 == V_136 )
break;
V_136 = V_137 ;
}
return V_136 ;
}
static void F_110 ( struct V_139 * V_39 )
{
struct V_5 * V_6 ;
if ( F_111 ( V_39 ) == V_140 )
V_6 = V_39 -> V_40 ;
else
V_6 = V_39 -> V_21 -> V_40 ;
F_99 ( & V_31 ) ;
F_112 ( V_39 ) ;
F_59 ( V_6 ) ;
}
static struct V_5 * F_113 ( struct V_139 * V_39 ,
bool V_141 )
{
struct V_5 * V_6 ;
if ( F_111 ( V_39 ) == V_140 )
V_6 = V_39 -> V_40 ;
else
V_6 = V_39 -> V_21 -> V_40 ;
if ( ! F_32 ( V_6 ) )
return NULL ;
F_114 ( V_39 ) ;
if ( V_141 )
F_95 ( V_6 ) ;
else
F_115 ( & V_31 ) ;
if ( ! F_29 ( V_6 ) )
return V_6 ;
F_110 ( V_39 ) ;
return NULL ;
}
static void F_116 ( struct V_5 * V_6 , const struct V_41 * V_42 )
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
F_117 ( V_6 -> V_39 , F_105 ( V_6 , V_42 , V_122 ) ) ;
}
static void F_118 ( struct V_18 * V_32 )
{
struct V_5 * V_6 = V_32 -> V_5 ;
struct V_41 * V_146 ;
if ( ! ( V_32 -> V_35 & V_147 ) )
return;
V_32 -> V_35 &= ~ V_147 ;
F_45 (cfts, &css->ss->cfts, node)
F_119 ( V_32 , V_6 , V_146 , false ) ;
}
static int F_120 ( struct V_18 * V_32 )
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
return F_119 ( & V_6 -> V_20 , V_6 , V_146 , true ) ;
}
F_45 (cfts, &css->ss->cfts, node) {
V_14 = F_119 ( V_32 , V_6 , V_146 , true ) ;
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
F_119 ( V_32 , V_6 , V_146 , false ) ;
}
return V_14 ;
}
static int F_98 ( struct V_89 * V_152 , T_2 V_153 )
{
struct V_5 * V_154 = & V_152 -> V_6 ;
struct V_28 * V_29 ;
int V_1 , V_68 , V_14 ;
F_23 ( & V_31 ) ;
F_108 (ss, ssid, ss_mask) {
if ( F_121 ( NULL , F_19 ( & V_29 -> V_7 -> V_6 , V_29 ) ) &&
! V_29 -> V_155 )
return - V_156 ;
if ( V_29 -> V_7 != & V_8 && V_152 != & V_8 )
return - V_156 ;
} F_109 () ;
F_108 (ss, ssid, ss_mask) {
struct V_89 * V_157 = V_29 -> V_7 ;
struct V_5 * V_158 = & V_157 -> V_6 ;
struct V_18 * V_32 = F_19 ( V_158 , V_29 ) ;
struct V_44 * V_45 ;
F_97 ( ! V_32 || F_19 ( V_154 , V_29 ) ) ;
V_157 -> V_23 &= ~ ( 1 << V_1 ) ;
F_97 ( F_122 ( V_158 ) ) ;
F_123 ( V_158 , 0 ) ;
F_124 ( V_158 -> V_30 [ V_1 ] , NULL ) ;
F_50 ( V_154 -> V_30 [ V_1 ] , V_32 ) ;
V_29 -> V_7 = V_152 ;
V_32 -> V_5 = V_154 ;
F_82 ( & V_46 ) ;
F_125 (css_set_table, i, cset, hlist)
F_80 ( & V_45 -> V_71 [ V_29 -> V_17 ] ,
& V_154 -> V_103 [ V_29 -> V_17 ] ) ;
F_83 ( & V_46 ) ;
V_152 -> V_23 |= 1 << V_1 ;
if ( V_152 == & V_8 ) {
F_126 ( V_159 [ V_1 ] ) ;
} else {
V_154 -> V_24 |= 1 << V_1 ;
F_127 ( V_159 [ V_1 ] ) ;
}
V_14 = F_122 ( V_154 ) ;
if ( V_14 )
F_128 ( L_2 ,
V_29 -> V_122 , V_14 ) ;
if ( V_29 -> V_160 )
V_29 -> V_160 ( V_32 ) ;
} F_109 () ;
F_129 ( V_154 -> V_39 ) ;
return 0 ;
}
static int F_130 ( struct V_161 * V_162 , struct V_139 * V_163 ,
struct V_104 * V_105 )
{
int V_164 = 0 ;
char * V_118 = NULL ;
struct V_89 * V_165 = F_87 ( V_105 ) ;
struct V_5 * V_166 ;
V_118 = F_131 ( V_167 , V_93 ) ;
if ( ! V_118 )
return - V_94 ;
F_82 ( & V_46 ) ;
V_166 = F_101 ( V_165 ) ;
V_164 = F_132 ( V_163 , V_166 -> V_39 , V_118 , V_167 ) ;
F_83 ( & V_46 ) ;
if ( V_164 >= V_167 )
V_164 = - V_168 ;
else if ( V_164 > 0 ) {
F_133 ( V_162 , V_118 , L_3 ) ;
V_164 = 0 ;
}
F_60 ( V_118 ) ;
return V_164 ;
}
static int F_134 ( struct V_161 * V_169 ,
struct V_104 * V_105 )
{
struct V_89 * V_7 = F_87 ( V_105 ) ;
struct V_28 * V_29 ;
int V_1 ;
if ( V_7 != & V_8 )
F_53 (ss, ssid)
if ( V_7 -> V_23 & ( 1 << V_1 ) )
F_135 ( V_169 , V_29 -> V_123 , NULL ) ;
if ( V_7 -> V_35 & V_120 )
F_136 ( V_169 , L_4 ) ;
if ( V_7 -> V_35 & V_170 )
F_136 ( V_169 , L_5 ) ;
F_137 ( & V_171 ) ;
if ( strlen ( V_7 -> V_172 ) )
F_135 ( V_169 , L_6 ,
V_7 -> V_172 ) ;
F_138 ( & V_171 ) ;
if ( F_38 ( V_173 , & V_7 -> V_6 . V_35 ) )
F_136 ( V_169 , L_7 ) ;
if ( strlen ( V_7 -> V_122 ) )
F_135 ( V_169 , L_8 , V_7 -> V_122 ) ;
return 0 ;
}
static int F_139 ( char * V_174 , struct V_175 * V_176 )
{
char * V_177 , * V_178 = V_174 ;
bool V_179 = false , V_180 = false ;
T_2 V_181 = V_182 ;
struct V_28 * V_29 ;
int V_183 = 0 ;
int V_68 ;
#ifdef F_140
V_181 = ~ ( ( T_2 ) 1 << V_184 ) ;
#endif
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
while ( ( V_177 = F_141 ( & V_178 , L_9 ) ) != NULL ) {
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
F_142 ( V_177 + 14 , V_167 - 1 , V_93 ) ;
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
V_176 -> V_122 = F_142 ( V_122 ,
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
static int F_143 ( struct V_104 * V_105 , int * V_35 , char * V_174 )
{
int V_14 = 0 ;
struct V_89 * V_7 = F_87 ( V_105 ) ;
struct V_175 V_176 ;
T_2 V_191 , V_192 ;
if ( V_7 == & V_8 ) {
F_144 ( L_17 ) ;
return - V_185 ;
}
F_95 ( & V_8 . V_6 ) ;
V_14 = F_139 ( V_174 , & V_176 ) ;
if ( V_14 )
goto V_33;
if ( V_176 . V_23 != V_7 -> V_23 || V_176 . V_188 )
F_128 ( L_18 ,
F_145 ( V_114 ) , V_114 -> V_193 ) ;
V_191 = V_176 . V_23 & ~ V_7 -> V_23 ;
V_192 = V_7 -> V_23 & ~ V_176 . V_23 ;
if ( ( V_176 . V_35 ^ V_7 -> V_35 ) ||
( V_176 . V_122 && strcmp ( V_176 . V_122 , V_7 -> V_122 ) ) ) {
F_144 ( L_19 ,
V_176 . V_35 , V_176 . V_122 ? : L_20 , V_7 -> V_35 , V_7 -> V_122 ) ;
V_14 = - V_185 ;
goto V_33;
}
if ( ! F_40 ( & V_7 -> V_6 . V_20 . V_111 ) ) {
V_14 = - V_156 ;
goto V_33;
}
V_14 = F_98 ( V_7 , V_191 ) ;
if ( V_14 )
goto V_33;
F_97 ( F_98 ( & V_8 , V_192 ) ) ;
if ( V_176 . V_188 ) {
F_137 ( & V_171 ) ;
strcpy ( V_7 -> V_172 , V_176 . V_188 ) ;
F_138 ( & V_171 ) ;
}
F_146 ( V_7 ) ;
V_33:
F_60 ( V_176 . V_188 ) ;
F_60 ( V_176 . V_122 ) ;
F_99 ( & V_31 ) ;
return V_14 ;
}
static void F_147 ( void )
{
struct V_55 * V_194 , * V_195 ;
F_82 ( & V_46 ) ;
if ( V_196 )
goto V_33;
V_196 = true ;
F_148 ( & V_197 ) ;
F_149 (g, p) {
F_31 ( ! F_40 ( & V_194 -> V_63 ) ||
F_104 ( V_194 ) != & V_34 ) ;
F_137 ( & V_194 -> V_198 -> V_199 ) ;
if ( ! ( V_194 -> V_35 & V_65 ) ) {
struct V_44 * V_45 = F_104 ( V_194 ) ;
if ( ! F_39 ( V_45 ) )
F_44 ( V_45 , true ) ;
F_51 ( & V_194 -> V_63 , & V_45 -> V_47 ) ;
F_66 ( V_45 ) ;
}
F_138 ( & V_194 -> V_198 -> V_199 ) ;
} F_150 ( V_195 , V_194 ) ;
F_151 ( & V_197 ) ;
V_33:
F_83 ( & V_46 ) ;
}
static void F_152 ( struct V_5 * V_6 )
{
struct V_28 * V_29 ;
int V_1 ;
F_75 ( & V_6 -> V_20 . V_200 ) ;
F_75 ( & V_6 -> V_20 . V_111 ) ;
F_75 ( & V_6 -> V_96 ) ;
F_75 ( & V_6 -> V_201 ) ;
F_153 ( & V_6 -> V_202 ) ;
V_6 -> V_20 . V_5 = V_6 ;
V_6 -> V_20 . V_35 |= V_36 ;
F_53 (ss, ssid)
F_75 ( & V_6 -> V_103 [ V_1 ] ) ;
F_154 ( & V_6 -> V_203 ) ;
F_155 ( & V_6 -> V_204 , V_205 ) ;
}
static void F_156 ( struct V_89 * V_7 ,
struct V_175 * V_176 )
{
struct V_5 * V_6 = & V_7 -> V_6 ;
F_75 ( & V_7 -> V_112 ) ;
F_84 ( & V_7 -> V_110 , 1 ) ;
V_6 -> V_7 = V_7 ;
F_152 ( V_6 ) ;
F_157 ( & V_7 -> V_109 ) ;
V_7 -> V_35 = V_176 -> V_35 ;
if ( V_176 -> V_188 )
strcpy ( V_7 -> V_172 , V_176 -> V_188 ) ;
if ( V_176 -> V_122 )
strcpy ( V_7 -> V_122 , V_176 -> V_122 ) ;
if ( V_176 -> V_187 )
F_158 ( V_173 , & V_7 -> V_6 . V_35 ) ;
}
static int F_159 ( struct V_89 * V_7 , T_2 V_153 )
{
F_160 ( V_92 ) ;
struct V_5 * V_106 = & V_7 -> V_6 ;
struct V_44 * V_45 ;
int V_68 , V_14 ;
F_23 ( & V_31 ) ;
V_14 = F_5 ( & V_7 -> V_109 , V_106 , 1 , 2 , V_93 ) ;
if ( V_14 < 0 )
goto V_206;
V_106 -> V_17 = V_14 ;
V_106 -> V_207 [ 0 ] = V_14 ;
V_14 = F_161 ( & V_106 -> V_20 . V_208 , V_209 , 0 ,
V_93 ) ;
if ( V_14 )
goto V_206;
V_14 = F_74 ( 2 * V_73 , & V_92 ) ;
if ( V_14 )
goto V_210;
V_14 = F_88 ( V_7 ) ;
if ( V_14 )
goto V_210;
V_7 -> V_105 = F_162 ( & V_211 ,
V_212 ,
V_106 ) ;
if ( F_163 ( V_7 -> V_105 ) ) {
V_14 = F_164 ( V_7 -> V_105 ) ;
goto V_213;
}
V_106 -> V_39 = V_7 -> V_105 -> V_39 ;
V_14 = F_120 ( & V_106 -> V_20 ) ;
if ( V_14 )
goto V_214;
V_14 = F_98 ( V_7 , V_153 ) ;
if ( V_14 )
goto V_214;
F_165 ( V_7 ) ;
F_77 ( & V_7 -> V_112 , & V_215 ) ;
V_97 ++ ;
F_82 ( & V_46 ) ;
F_125 (css_set_table, i, cset, hlist) {
F_78 ( & V_92 , V_45 , V_106 ) ;
if ( F_39 ( V_45 ) )
F_41 ( V_106 , true ) ;
}
F_83 ( & V_46 ) ;
F_69 ( ! F_40 ( & V_106 -> V_20 . V_111 ) ) ;
F_69 ( F_96 ( & V_7 -> V_110 ) != 1 ) ;
F_129 ( V_106 -> V_39 ) ;
V_14 = 0 ;
goto V_206;
V_214:
F_100 ( V_7 -> V_105 ) ;
V_7 -> V_105 = NULL ;
V_213:
F_90 ( V_7 ) ;
V_210:
F_166 ( & V_106 -> V_20 . V_208 ) ;
V_206:
F_73 ( & V_92 ) ;
return V_14 ;
}
static struct V_216 * F_167 ( struct V_217 * V_218 ,
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
F_168 ( V_225 ) ;
if ( ! F_169 ( V_225 -> V_227 , V_228 ) ) {
F_170 ( V_225 ) ;
return F_171 ( - V_229 ) ;
}
if ( ! V_196 )
F_147 () ;
if ( V_220 ) {
if ( V_174 ) {
F_144 ( L_21 , ( char * ) V_174 ) ;
F_170 ( V_225 ) ;
return F_171 ( - V_185 ) ;
}
V_230 = true ;
V_7 = & V_8 ;
F_30 ( & V_7 -> V_6 ) ;
goto V_231;
}
F_95 ( & V_8 . V_6 ) ;
V_14 = F_139 ( V_174 , & V_176 ) ;
if ( V_14 )
goto V_33;
F_53 (ss, i) {
if ( ! ( V_176 . V_23 & ( 1 << V_68 ) ) ||
V_29 -> V_7 == & V_8 )
continue;
if ( ! F_172 ( & V_29 -> V_7 -> V_6 . V_20 . V_208 ) ) {
F_99 ( & V_31 ) ;
F_173 ( 10 ) ;
V_14 = F_174 () ;
goto V_232;
}
F_59 ( & V_29 -> V_7 -> V_6 ) ;
}
F_175 (root) {
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
F_128 ( L_22 ) ;
V_223 = F_176 ( V_7 -> V_105 , NULL ) ;
if ( F_163 ( V_223 ) ||
! F_172 ( & V_7 -> V_6 . V_20 . V_208 ) ) {
F_99 ( & V_31 ) ;
if ( ! F_177 ( V_223 ) )
F_178 ( V_223 ) ;
F_173 ( 10 ) ;
V_14 = F_174 () ;
goto V_232;
}
V_14 = 0 ;
goto V_33;
}
if ( ! V_176 . V_23 && ! V_176 . V_186 ) {
V_14 = - V_185 ;
goto V_33;
}
if ( V_225 != & V_234 ) {
V_14 = - V_229 ;
goto V_33;
}
V_7 = F_76 ( sizeof( * V_7 ) , V_93 ) ;
if ( ! V_7 ) {
V_14 = - V_94 ;
goto V_33;
}
F_156 ( V_7 , & V_176 ) ;
V_14 = F_159 ( V_7 , V_176 . V_23 ) ;
if ( V_14 )
F_91 ( V_7 ) ;
V_33:
F_99 ( & V_31 ) ;
V_232:
F_60 ( V_176 . V_188 ) ;
F_60 ( V_176 . V_122 ) ;
if ( V_14 ) {
F_170 ( V_225 ) ;
return F_171 ( V_14 ) ;
}
V_231:
V_216 = F_179 ( V_218 , V_35 , V_7 -> V_105 ,
V_220 ? V_235 : V_236 ,
& V_226 ) ;
if ( ! F_163 ( V_216 ) && V_225 != & V_234 ) {
struct V_216 * V_237 ;
struct V_5 * V_6 ;
F_115 ( & V_31 ) ;
F_82 ( & V_46 ) ;
V_6 = F_102 ( V_225 -> V_117 , V_7 ) ;
F_83 ( & V_46 ) ;
F_99 ( & V_31 ) ;
V_237 = F_180 ( V_6 -> V_39 , V_216 -> V_238 ) ;
F_181 ( V_216 ) ;
V_216 = V_237 ;
}
if ( F_163 ( V_216 ) || ! V_226 )
F_59 ( & V_7 -> V_6 ) ;
if ( V_223 ) {
F_97 ( V_226 ) ;
F_178 ( V_223 ) ;
}
F_170 ( V_225 ) ;
return V_216 ;
}
static void F_182 ( struct V_222 * V_239 )
{
struct V_104 * V_105 = F_183 ( V_239 ) ;
struct V_89 * V_7 = F_87 ( V_105 ) ;
if ( ! F_40 ( & V_7 -> V_6 . V_20 . V_111 ) ||
V_7 == & V_8 )
F_59 ( & V_7 -> V_6 ) ;
else
F_184 ( & V_7 -> V_6 . V_20 . V_208 ) ;
F_185 ( V_239 ) ;
}
static int F_186 ( struct V_5 * V_6 , char * V_118 , T_4 V_240 ,
struct V_224 * V_225 )
{
struct V_5 * V_7 = F_102 ( V_225 -> V_117 , V_6 -> V_7 ) ;
return F_132 ( V_6 -> V_39 , V_7 -> V_39 , V_118 , V_240 ) ;
}
int F_187 ( struct V_5 * V_6 , char * V_118 , T_4 V_240 ,
struct V_224 * V_225 )
{
int V_14 ;
F_115 ( & V_31 ) ;
F_82 ( & V_46 ) ;
V_14 = F_186 ( V_6 , V_118 , V_240 , V_225 ) ;
F_83 ( & V_46 ) ;
F_99 ( & V_31 ) ;
return V_14 ;
}
int F_188 ( struct V_55 * V_56 , char * V_118 , T_4 V_240 )
{
struct V_89 * V_7 ;
struct V_5 * V_6 ;
int V_108 = 1 ;
int V_14 ;
F_115 ( & V_31 ) ;
F_82 ( & V_46 ) ;
V_7 = F_189 ( & V_107 , & V_108 ) ;
if ( V_7 ) {
V_6 = F_103 ( V_56 , V_7 ) ;
V_14 = F_186 ( V_6 , V_118 , V_240 , & V_234 ) ;
} else {
V_14 = F_190 ( V_118 , L_23 , V_240 ) ;
}
F_83 ( & V_46 ) ;
F_99 ( & V_31 ) ;
return V_14 ;
}
static void F_191 ( struct V_55 * V_56 ,
struct V_241 * V_242 )
{
struct V_44 * V_45 ;
F_23 ( & V_46 ) ;
if ( V_56 -> V_35 & V_65 )
return;
if ( F_40 ( & V_56 -> V_63 ) )
return;
V_45 = F_104 ( V_56 ) ;
if ( ! V_45 -> V_243 )
return;
F_80 ( & V_56 -> V_63 , & V_45 -> V_48 ) ;
if ( F_40 ( & V_45 -> V_99 ) )
F_51 ( & V_45 -> V_99 , & V_242 -> V_244 ) ;
if ( F_40 ( & V_45 -> V_245 -> V_99 ) )
F_80 ( & V_45 -> V_245 -> V_99 ,
& V_242 -> V_246 ) ;
}
struct V_55 * F_192 ( struct V_241 * V_242 ,
struct V_18 * * V_247 )
{
V_242 -> V_248 = F_79 ( V_242 -> V_249 , struct V_44 , V_99 ) ;
V_242 -> V_250 = NULL ;
return F_193 ( V_242 , V_247 ) ;
}
struct V_55 * F_193 ( struct V_241 * V_242 ,
struct V_18 * * V_247 )
{
struct V_44 * V_45 = V_242 -> V_248 ;
struct V_55 * V_56 = V_242 -> V_250 ;
while ( & V_45 -> V_99 != V_242 -> V_249 ) {
if ( ! V_56 )
V_56 = F_79 ( & V_45 -> V_48 ,
struct V_55 , V_63 ) ;
else
V_56 = F_194 ( V_56 , V_63 ) ;
if ( & V_56 -> V_63 != & V_45 -> V_48 ) {
V_242 -> V_248 = V_45 ;
V_242 -> V_250 = V_56 ;
if ( V_45 -> V_245 )
* V_247 = V_45 -> V_245 -> V_30 [ V_242 -> V_1 ] ;
else
* V_247 = V_45 -> V_30 [ V_242 -> V_1 ] ;
return V_56 ;
}
V_45 = F_194 ( V_45 , V_99 ) ;
V_56 = NULL ;
}
return NULL ;
}
static int F_195 ( struct V_241 * V_242 ,
struct V_89 * V_7 )
{
struct V_28 * V_29 ;
struct V_55 * V_56 , * V_251 ;
struct V_44 * V_45 , * V_252 ;
int V_1 , V_253 , V_14 ;
if ( F_40 ( & V_242 -> V_244 ) )
return 0 ;
F_108 (ss, ssid, root->subsys_mask) {
if ( V_29 -> V_254 ) {
V_242 -> V_1 = V_1 ;
V_14 = V_29 -> V_254 ( V_242 ) ;
if ( V_14 ) {
V_253 = V_1 ;
goto V_255;
}
}
} F_109 () ;
F_82 ( & V_46 ) ;
F_45 (cset, &tset->src_csets, mg_node) {
F_47 (task, tmp_task, &cset->mg_tasks, cg_list) {
struct V_44 * V_57 = F_104 ( V_56 ) ;
struct V_44 * V_58 = V_45 -> V_245 ;
F_66 ( V_58 ) ;
F_46 ( V_56 , V_57 , V_58 , true ) ;
F_54 ( V_57 ) ;
}
}
F_83 ( & V_46 ) ;
V_242 -> V_249 = & V_242 -> V_246 ;
F_108 (ss, ssid, root->subsys_mask) {
if ( V_29 -> V_256 ) {
V_242 -> V_1 = V_1 ;
V_29 -> V_256 ( V_242 ) ;
}
} F_109 () ;
V_14 = 0 ;
goto V_257;
V_255:
F_108 (ss, ssid, root->subsys_mask) {
if ( V_1 == V_253 )
break;
if ( V_29 -> V_258 ) {
V_242 -> V_1 = V_1 ;
V_29 -> V_258 ( V_242 ) ;
}
} F_109 () ;
V_257:
F_82 ( & V_46 ) ;
F_196 ( & V_242 -> V_246 , & V_242 -> V_244 ) ;
F_47 (cset, tmp_cset, &tset->src_csets, mg_node) {
F_197 ( & V_45 -> V_48 , & V_45 -> V_47 ) ;
F_49 ( & V_45 -> V_99 ) ;
}
F_83 ( & V_46 ) ;
return V_14 ;
}
static bool F_198 ( struct V_5 * V_259 )
{
return ! F_4 ( V_259 ) || ! F_15 ( V_259 ) ||
! V_259 -> V_24 ;
}
static void F_199 ( struct V_80 * V_260 )
{
struct V_44 * V_45 , * V_252 ;
F_23 ( & V_31 ) ;
F_82 ( & V_46 ) ;
F_47 (cset, tmp_cset, preloaded_csets, mg_preload_node) {
V_45 -> V_243 = NULL ;
V_45 -> V_261 = NULL ;
V_45 -> V_245 = NULL ;
F_49 ( & V_45 -> V_98 ) ;
F_54 ( V_45 ) ;
}
F_83 ( & V_46 ) ;
}
static void F_200 ( struct V_44 * V_262 ,
struct V_5 * V_259 ,
struct V_80 * V_260 )
{
struct V_5 * V_263 ;
F_23 ( & V_31 ) ;
F_23 ( & V_46 ) ;
if ( V_262 -> V_264 )
return;
V_263 = F_102 ( V_262 , V_259 -> V_7 ) ;
if ( ! F_40 ( & V_262 -> V_98 ) )
return;
F_97 ( V_262 -> V_243 ) ;
F_97 ( V_262 -> V_261 ) ;
F_97 ( ! F_40 ( & V_262 -> V_48 ) ) ;
F_97 ( ! F_40 ( & V_262 -> V_99 ) ) ;
V_262 -> V_243 = V_263 ;
V_262 -> V_261 = V_259 ;
F_66 ( V_262 ) ;
F_77 ( & V_262 -> V_98 , V_260 ) ;
}
static int F_201 ( struct V_80 * V_260 )
{
F_160 ( V_249 ) ;
struct V_44 * V_262 , * V_252 ;
F_23 ( & V_31 ) ;
F_47 (src_cset, tmp_cset, preloaded_csets, mg_preload_node) {
struct V_44 * V_265 ;
V_265 = F_81 ( V_262 , V_262 -> V_261 ) ;
if ( ! V_265 )
goto V_151;
F_31 ( V_262 -> V_245 || V_265 -> V_245 ) ;
if ( V_262 == V_265 ) {
V_262 -> V_243 = NULL ;
V_262 -> V_261 = NULL ;
F_49 ( & V_262 -> V_98 ) ;
F_62 ( V_262 ) ;
F_62 ( V_265 ) ;
continue;
}
V_262 -> V_245 = V_265 ;
if ( F_40 ( & V_265 -> V_98 ) )
F_77 ( & V_265 -> V_98 , & V_249 ) ;
else
F_62 ( V_265 ) ;
}
F_202 ( & V_249 , V_260 ) ;
return 0 ;
V_151:
F_199 ( & V_249 ) ;
return - V_94 ;
}
static int F_203 ( struct V_55 * V_266 , bool V_267 ,
struct V_89 * V_7 )
{
struct V_241 V_242 = F_204 ( V_242 ) ;
struct V_55 * V_56 ;
F_82 ( & V_46 ) ;
F_25 () ;
V_56 = V_266 ;
do {
F_191 ( V_56 , & V_242 ) ;
if ( ! V_267 )
break;
} while_each_thread(leader, task) ;
int F_205 ( struct V_5 * V_259 ,
struct V_55 * V_266 , bool V_267 )
{
F_160 ( V_260 ) ;
struct V_55 * V_56 ;
int V_14 ;
if ( ! F_198 ( V_259 ) )
return - V_156 ;
F_82 ( & V_46 ) ;
F_25 () ;
V_56 = V_266 ;
do {
F_200 ( F_104 ( V_56 ) , V_259 ,
& V_260 ) ;
if ( ! V_267 )
break;
} while_each_thread(leader, task) ;
int F_206 ( struct V_55 * V_56 ,
struct V_5 * V_259 ,
struct V_37 * V_38 )
{
const struct V_268 * V_268 = F_207 () ;
const struct V_268 * V_269 = F_208 ( V_56 ) ;
int V_14 = 0 ;
if ( ! F_209 ( V_268 -> V_270 , V_271 ) &&
! F_209 ( V_268 -> V_270 , V_269 -> V_272 ) &&
! F_209 ( V_268 -> V_270 , V_269 -> V_273 ) )
V_14 = - V_274 ;
if ( ! V_14 && F_4 ( V_259 ) ) {
struct V_222 * V_239 = V_38 -> V_275 -> V_276 . V_216 -> V_238 ;
struct V_5 * V_6 ;
struct V_277 * V_277 ;
F_82 ( & V_46 ) ;
V_6 = F_103 ( V_56 , & V_8 ) ;
F_83 ( & V_46 ) ;
while ( ! F_210 ( V_259 , V_6 ) )
V_6 = F_15 ( V_6 ) ;
V_14 = - V_94 ;
V_277 = F_211 ( V_239 , V_6 -> V_278 . V_39 ) ;
if ( V_277 ) {
V_14 = F_212 ( V_277 , V_279 ) ;
F_213 ( V_277 ) ;
}
}
F_214 ( V_269 ) ;
return V_14 ;
}
static T_5 F_215 ( struct V_37 * V_38 , char * V_118 ,
T_4 V_280 , T_6 V_281 , bool V_267 )
{
struct V_55 * V_282 ;
struct V_28 * V_29 ;
struct V_5 * V_6 ;
T_7 V_283 ;
int V_1 , V_14 ;
if ( F_216 ( F_217 ( V_118 ) , 0 , & V_283 ) || V_283 < 0 )
return - V_185 ;
V_6 = F_113 ( V_38 -> V_39 , false ) ;
if ( ! V_6 )
return - V_284 ;
F_218 ( & V_285 ) ;
F_25 () ;
if ( V_283 ) {
V_282 = F_219 ( V_283 ) ;
if ( ! V_282 ) {
V_14 = - V_286 ;
goto V_287;
}
} else {
V_282 = V_114 ;
}
if ( V_267 )
V_282 = V_282 -> V_288 ;
if ( V_282 == V_289 || ( V_282 -> V_35 & V_290 ) ) {
V_14 = - V_185 ;
goto V_287;
}
F_220 ( V_282 ) ;
F_28 () ;
V_14 = F_206 ( V_282 , V_6 , V_38 ) ;
if ( ! V_14 )
V_14 = F_205 ( V_6 , V_282 , V_267 ) ;
F_221 ( V_282 ) ;
goto V_291;
V_287:
F_28 () ;
V_291:
F_222 ( & V_285 ) ;
F_53 (ss, ssid)
if ( V_29 -> V_292 )
V_29 -> V_292 () ;
F_110 ( V_38 -> V_39 ) ;
return V_14 ? : V_280 ;
}
int F_223 ( struct V_55 * V_293 , struct V_55 * V_282 )
{
struct V_89 * V_7 ;
int V_294 = 0 ;
F_115 ( & V_31 ) ;
F_218 ( & V_285 ) ;
F_175 (root) {
struct V_5 * V_295 ;
if ( V_7 == & V_8 )
continue;
F_82 ( & V_46 ) ;
V_295 = F_103 ( V_293 , V_7 ) ;
F_83 ( & V_46 ) ;
V_294 = F_205 ( V_295 , V_282 , false ) ;
if ( V_294 )
break;
}
F_222 ( & V_285 ) ;
F_99 ( & V_31 ) ;
return V_294 ;
}
static T_5 F_224 ( struct V_37 * V_38 ,
char * V_118 , T_4 V_280 , T_6 V_281 )
{
return F_215 ( V_38 , V_118 , V_280 , V_281 , false ) ;
}
static T_5 F_225 ( struct V_37 * V_38 ,
char * V_118 , T_4 V_280 , T_6 V_281 )
{
return F_215 ( V_38 , V_118 , V_280 , V_281 , true ) ;
}
static T_5 F_226 ( struct V_37 * V_38 ,
char * V_118 , T_4 V_280 , T_6 V_281 )
{
struct V_5 * V_6 ;
F_227 ( sizeof( V_6 -> V_7 -> V_172 ) < V_167 ) ;
V_6 = F_113 ( V_38 -> V_39 , false ) ;
if ( ! V_6 )
return - V_284 ;
F_137 ( & V_171 ) ;
F_190 ( V_6 -> V_7 -> V_172 , F_217 ( V_118 ) ,
sizeof( V_6 -> V_7 -> V_172 ) ) ;
F_138 ( & V_171 ) ;
F_110 ( V_38 -> V_39 ) ;
return V_280 ;
}
static int F_228 ( struct V_161 * V_169 , void * V_296 )
{
struct V_5 * V_6 = F_229 ( V_169 ) -> V_5 ;
F_137 ( & V_171 ) ;
F_136 ( V_169 , V_6 -> V_7 -> V_172 ) ;
F_138 ( & V_171 ) ;
F_230 ( V_169 , '\n' ) ;
return 0 ;
}
static int F_231 ( struct V_161 * V_169 , void * V_296 )
{
F_136 ( V_169 , L_24 ) ;
return 0 ;
}
static void F_232 ( struct V_161 * V_169 , T_2 V_153 )
{
struct V_28 * V_29 ;
bool V_297 = false ;
int V_1 ;
F_108 (ss, ssid, ss_mask) {
if ( V_297 )
F_230 ( V_169 , ' ' ) ;
F_233 ( V_169 , L_25 , V_29 -> V_122 ) ;
V_297 = true ;
} F_109 () ;
if ( V_297 )
F_230 ( V_169 , '\n' ) ;
}
static int F_234 ( struct V_161 * V_169 , void * V_296 )
{
struct V_5 * V_6 = F_229 ( V_169 ) -> V_5 ;
F_232 ( V_169 , F_17 ( V_6 ) ) ;
return 0 ;
}
static int F_235 ( struct V_161 * V_169 , void * V_296 )
{
struct V_5 * V_6 = F_229 ( V_169 ) -> V_5 ;
F_232 ( V_169 , V_6 -> V_24 ) ;
return 0 ;
}
static int F_236 ( struct V_5 * V_6 )
{
F_160 ( V_260 ) ;
struct V_241 V_242 = F_204 ( V_242 ) ;
struct V_18 * V_298 ;
struct V_5 * V_299 ;
struct V_44 * V_262 ;
int V_14 ;
F_23 ( & V_31 ) ;
F_218 ( & V_285 ) ;
F_82 ( & V_46 ) ;
F_237 (dsct, d_css, cgrp) {
struct V_53 * V_54 ;
F_45 (link, &dsct->cset_links, cset_link)
F_200 ( V_54 -> V_45 , V_299 ,
& V_260 ) ;
}
F_83 ( & V_46 ) ;
V_14 = F_201 ( & V_260 ) ;
if ( V_14 )
goto V_300;
F_82 ( & V_46 ) ;
F_45 (src_cset, &preloaded_csets, mg_preload_node) {
struct V_55 * V_56 , * V_301 ;
if ( ! V_262 -> V_243 )
break;
F_47 (task, ntask, &src_cset->tasks, cg_list)
F_191 ( V_56 , & V_242 ) ;
}
F_83 ( & V_46 ) ;
V_14 = F_195 ( & V_242 , V_6 -> V_7 ) ;
V_300:
F_199 ( & V_260 ) ;
F_222 ( & V_285 ) ;
return V_14 ;
}
static void F_95 ( struct V_5 * V_6 )
__acquires( &cgroup_mutex
static void F_238 ( struct V_5 * V_6 )
{
struct V_5 * V_299 ;
struct V_18 * V_298 ;
F_237 (dsct, d_css, cgrp) {
V_299 -> V_302 = V_299 -> V_24 ;
V_299 -> V_303 = V_299 -> V_27 ;
}
}
static void F_239 ( struct V_5 * V_6 )
{
struct V_5 * V_299 ;
struct V_18 * V_298 ;
F_237 (dsct, d_css, cgrp) {
V_299 -> V_24 &= F_17 ( V_299 ) ;
V_299 -> V_27 =
F_107 ( V_299 -> V_24 ,
F_18 ( V_299 ) ) ;
}
}
static void F_240 ( struct V_5 * V_6 )
{
struct V_5 * V_299 ;
struct V_18 * V_298 ;
F_241 (dsct, d_css, cgrp) {
V_299 -> V_24 = V_299 -> V_302 ;
V_299 -> V_27 = V_299 -> V_303 ;
}
}
static bool F_242 ( struct V_18 * V_32 )
{
struct V_28 * V_29 = V_32 -> V_29 ;
struct V_5 * V_6 = V_32 -> V_5 ;
if ( F_17 ( V_6 ) & ( 1 << V_29 -> V_17 ) )
return true ;
if ( ! ( F_18 ( V_6 ) & ( 1 << V_29 -> V_17 ) ) )
return false ;
return F_4 ( V_6 ) && V_29 -> V_155 ;
}
static int F_243 ( struct V_5 * V_6 )
{
struct V_5 * V_299 ;
struct V_18 * V_298 ;
struct V_28 * V_29 ;
int V_1 , V_14 ;
F_237 (dsct, d_css, cgrp) {
F_53 (ss, ssid) {
struct V_18 * V_32 = F_19 ( V_299 , V_29 ) ;
F_31 ( V_32 && F_244 ( & V_32 -> V_208 ) ) ;
if ( ! ( F_18 ( V_299 ) & ( 1 << V_29 -> V_17 ) ) )
continue;
if ( ! V_32 ) {
V_32 = F_245 ( V_299 , V_29 ) ;
if ( F_163 ( V_32 ) )
return F_164 ( V_32 ) ;
}
if ( F_242 ( V_32 ) ) {
V_14 = F_120 ( V_32 ) ;
if ( V_14 )
return V_14 ;
}
}
}
return 0 ;
}
static void F_246 ( struct V_5 * V_6 )
{
struct V_5 * V_299 ;
struct V_18 * V_298 ;
struct V_28 * V_29 ;
int V_1 ;
F_241 (dsct, d_css, cgrp) {
F_53 (ss, ssid) {
struct V_18 * V_32 = F_19 ( V_299 , V_29 ) ;
F_31 ( V_32 && F_244 ( & V_32 -> V_208 ) ) ;
if ( ! V_32 )
continue;
if ( V_32 -> V_21 &&
! ( F_18 ( V_299 ) & ( 1 << V_29 -> V_17 ) ) ) {
F_247 ( V_32 ) ;
} else if ( ! F_242 ( V_32 ) ) {
F_118 ( V_32 ) ;
if ( V_29 -> V_304 )
V_29 -> V_304 ( V_32 ) ;
}
}
}
}
static int F_122 ( struct V_5 * V_6 )
{
int V_14 ;
F_239 ( V_6 ) ;
V_14 = F_243 ( V_6 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_236 ( V_6 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static void F_123 ( struct V_5 * V_6 , int V_14 )
{
if ( V_14 ) {
F_240 ( V_6 ) ;
F_239 ( V_6 ) ;
}
F_246 ( V_6 ) ;
}
static T_5 F_248 ( struct V_37 * V_38 ,
char * V_118 , T_4 V_280 ,
T_6 V_281 )
{
T_2 V_305 = 0 , V_306 = 0 ;
struct V_5 * V_6 , * V_307 ;
struct V_28 * V_29 ;
char * V_308 ;
int V_1 , V_14 ;
V_118 = F_217 ( V_118 ) ;
while ( ( V_308 = F_141 ( & V_118 , L_26 ) ) ) {
if ( V_308 [ 0 ] == '\0' )
continue;
F_108 (ss, ssid, ~cgrp_dfl_inhibit_ss_mask) {
if ( ! F_1 ( V_1 ) ||
strcmp ( V_308 + 1 , V_29 -> V_122 ) )
continue;
if ( * V_308 == '+' ) {
V_305 |= 1 << V_1 ;
V_306 &= ~ ( 1 << V_1 ) ;
} else if ( * V_308 == '-' ) {
V_306 |= 1 << V_1 ;
V_305 &= ~ ( 1 << V_1 ) ;
} else {
return - V_185 ;
}
break;
} F_109 () ;
if ( V_1 == V_2 )
return - V_185 ;
}
V_6 = F_113 ( V_38 -> V_39 , true ) ;
if ( ! V_6 )
return - V_284 ;
F_53 (ss, ssid) {
if ( V_305 & ( 1 << V_1 ) ) {
if ( V_6 -> V_24 & ( 1 << V_1 ) ) {
V_305 &= ~ ( 1 << V_1 ) ;
continue;
}
if ( ! ( F_17 ( V_6 ) & ( 1 << V_1 ) ) ) {
V_14 = - V_190 ;
goto V_33;
}
} else if ( V_306 & ( 1 << V_1 ) ) {
if ( ! ( V_6 -> V_24 & ( 1 << V_1 ) ) ) {
V_306 &= ~ ( 1 << V_1 ) ;
continue;
}
F_249 (child, cgrp) {
if ( V_307 -> V_24 & ( 1 << V_1 ) ) {
V_14 = - V_156 ;
goto V_33;
}
}
}
}
if ( ! V_305 && ! V_306 ) {
V_14 = 0 ;
goto V_33;
}
if ( V_305 && F_15 ( V_6 ) ) {
struct V_53 * V_54 ;
F_82 ( & V_46 ) ;
V_14 = 0 ;
F_45 (link, &cgrp->cset_links, cset_link) {
if ( F_39 ( V_54 -> V_45 ) ) {
V_14 = - V_156 ;
break;
}
}
F_83 ( & V_46 ) ;
if ( V_14 )
goto V_33;
}
F_238 ( V_6 ) ;
V_6 -> V_24 |= V_305 ;
V_6 -> V_24 &= ~ V_306 ;
V_14 = F_122 ( V_6 ) ;
F_123 ( V_6 , V_14 ) ;
F_129 ( V_6 -> V_39 ) ;
V_14 = 0 ;
V_33:
F_110 ( V_38 -> V_39 ) ;
return V_14 ? : V_280 ;
}
static int F_250 ( struct V_161 * V_169 , void * V_296 )
{
F_233 ( V_169 , L_27 ,
F_251 ( F_229 ( V_169 ) -> V_5 ) ) ;
return 0 ;
}
static T_5 F_252 ( struct V_37 * V_38 , char * V_118 ,
T_4 V_280 , T_6 V_281 )
{
struct V_5 * V_6 = V_38 -> V_39 -> V_21 -> V_40 ;
struct V_41 * V_42 = V_38 -> V_39 -> V_40 ;
struct V_18 * V_32 ;
int V_14 ;
if ( V_42 -> V_131 )
return V_42 -> V_131 ( V_38 , V_118 , V_280 , V_281 ) ;
F_25 () ;
V_32 = F_19 ( V_6 , V_42 -> V_29 ) ;
F_28 () ;
if ( V_42 -> V_129 ) {
unsigned long long V_296 ;
V_14 = F_253 ( V_118 , 0 , & V_296 ) ;
if ( ! V_14 )
V_14 = V_42 -> V_129 ( V_32 , V_42 , V_296 ) ;
} else if ( V_42 -> V_130 ) {
long long V_296 ;
V_14 = F_254 ( V_118 , 0 , & V_296 ) ;
if ( ! V_14 )
V_14 = V_42 -> V_130 ( V_32 , V_42 , V_296 ) ;
} else {
V_14 = - V_185 ;
}
return V_14 ? : V_280 ;
}
static void * F_255 ( struct V_161 * V_169 , T_6 * V_309 )
{
return F_256 ( V_169 ) -> F_257 ( V_169 , V_309 ) ;
}
static void * F_258 ( struct V_161 * V_169 , void * V_296 , T_6 * V_309 )
{
return F_256 ( V_169 ) -> F_259 ( V_169 , V_296 , V_309 ) ;
}
static void F_260 ( struct V_161 * V_169 , void * V_296 )
{
F_256 ( V_169 ) -> F_261 ( V_169 , V_296 ) ;
}
static int F_262 ( struct V_161 * V_310 , void * V_311 )
{
struct V_41 * V_42 = F_256 ( V_310 ) ;
struct V_18 * V_32 = F_229 ( V_310 ) ;
if ( V_42 -> V_127 )
return V_42 -> V_127 ( V_310 , V_311 ) ;
if ( V_42 -> V_125 )
F_233 ( V_310 , L_28 , V_42 -> V_125 ( V_32 , V_42 ) ) ;
else if ( V_42 -> V_126 )
F_233 ( V_310 , L_29 , V_42 -> V_126 ( V_32 , V_42 ) ) ;
else
return - V_185 ;
return 0 ;
}
static int F_263 ( struct V_139 * V_39 , struct V_139 * V_312 ,
const char * V_313 )
{
struct V_5 * V_6 = V_39 -> V_40 ;
int V_14 ;
if ( F_111 ( V_39 ) != V_140 )
return - V_314 ;
if ( V_39 -> V_21 != V_312 )
return - V_315 ;
if ( F_4 ( V_6 ) )
return - V_229 ;
F_114 ( V_312 ) ;
F_114 ( V_39 ) ;
F_115 ( & V_31 ) ;
V_14 = F_264 ( V_39 , V_312 , V_313 ) ;
if ( ! V_14 )
F_265 ( V_6 ) ;
F_99 ( & V_31 ) ;
F_112 ( V_39 ) ;
F_112 ( V_312 ) ;
return V_14 ;
}
static int F_266 ( struct V_139 * V_39 )
{
struct V_316 V_316 = { . V_317 = V_318 | V_319 ,
. V_320 = F_267 () ,
. V_321 = F_268 () , } ;
if ( F_209 ( V_316 . V_320 , V_271 ) &&
F_269 ( V_316 . V_321 , V_322 ) )
return 0 ;
return F_270 ( V_39 , & V_316 ) ;
}
static int F_271 ( struct V_18 * V_32 , struct V_5 * V_6 ,
struct V_41 * V_42 )
{
char V_122 [ V_121 ] ;
struct V_139 * V_39 ;
struct V_323 * V_67 = NULL ;
int V_14 ;
#ifdef F_272
V_67 = & V_42 -> V_324 ;
#endif
V_39 = F_273 ( V_6 -> V_39 , F_105 ( V_6 , V_42 , V_122 ) ,
F_106 ( V_42 ) , 0 , V_42 -> V_325 , V_42 ,
NULL , V_67 ) ;
if ( F_163 ( V_39 ) )
return F_164 ( V_39 ) ;
V_14 = F_266 ( V_39 ) ;
if ( V_14 ) {
F_274 ( V_39 ) ;
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
static int F_119 ( struct V_18 * V_32 ,
struct V_5 * V_6 , struct V_41 V_146 [] ,
bool V_326 )
{
struct V_41 * V_42 , * V_327 = NULL ;
int V_14 = 0 ;
F_23 ( & V_31 ) ;
V_328:
for ( V_42 = V_146 ; V_42 != V_327 && V_42 -> V_122 [ 0 ] != '\0' ; V_42 ++ ) {
if ( ( V_42 -> V_35 & V_329 ) && ! F_4 ( V_6 ) )
continue;
if ( ( V_42 -> V_35 & V_330 ) && F_4 ( V_6 ) )
continue;
if ( ( V_42 -> V_35 & V_331 ) && ! F_15 ( V_6 ) )
continue;
if ( ( V_42 -> V_35 & V_332 ) && F_15 ( V_6 ) )
continue;
if ( V_326 ) {
V_14 = F_271 ( V_32 , V_6 , V_42 ) ;
if ( V_14 ) {
F_128 ( L_30 ,
V_333 , V_42 -> V_122 , V_14 ) ;
V_327 = V_42 ;
V_326 = false ;
goto V_328;
}
} else {
F_116 ( V_6 , V_42 ) ;
}
}
return V_14 ;
}
static int F_275 ( struct V_41 * V_146 , bool V_326 )
{
F_160 ( V_334 ) ;
struct V_28 * V_29 = V_146 [ 0 ] . V_29 ;
struct V_5 * V_7 = & V_29 -> V_7 -> V_6 ;
struct V_18 * V_32 ;
int V_14 = 0 ;
F_23 ( & V_31 ) ;
F_276 (css, cgroup_css(root, ss)) {
struct V_5 * V_6 = V_32 -> V_5 ;
if ( ! ( V_32 -> V_35 & V_147 ) )
continue;
V_14 = F_119 ( V_32 , V_6 , V_146 , V_326 ) ;
if ( V_14 )
break;
}
if ( V_326 && ! V_14 )
F_129 ( V_7 -> V_39 ) ;
return V_14 ;
}
static void F_277 ( struct V_41 * V_146 )
{
struct V_41 * V_42 ;
for ( V_42 = V_146 ; V_42 -> V_122 [ 0 ] != '\0' ; V_42 ++ ) {
if ( V_42 -> V_335 && V_42 -> V_335 != V_336 )
F_60 ( V_42 -> V_325 ) ;
V_42 -> V_325 = NULL ;
V_42 -> V_29 = NULL ;
V_42 -> V_35 &= ~ ( V_329 | V_330 ) ;
}
}
static int F_278 ( struct V_28 * V_29 , struct V_41 * V_146 )
{
struct V_41 * V_42 ;
for ( V_42 = V_146 ; V_42 -> V_122 [ 0 ] != '\0' ; V_42 ++ ) {
struct V_337 * V_325 ;
F_97 ( V_42 -> V_29 || V_42 -> V_325 ) ;
if ( V_42 -> F_257 )
V_325 = & V_338 ;
else
V_325 = & V_339 ;
if ( V_42 -> V_335 && V_42 -> V_335 != V_336 ) {
V_325 = F_279 ( V_325 , sizeof( * V_325 ) , V_93 ) ;
if ( ! V_325 ) {
F_277 ( V_146 ) ;
return - V_94 ;
}
V_325 -> V_340 = V_42 -> V_335 ;
}
V_42 -> V_325 = V_325 ;
V_42 -> V_29 = V_29 ;
}
return 0 ;
}
static int F_280 ( struct V_41 * V_146 )
{
F_23 ( & V_31 ) ;
if ( ! V_146 || ! V_146 [ 0 ] . V_29 )
return - V_190 ;
F_56 ( & V_146 -> V_341 ) ;
F_275 ( V_146 , false ) ;
F_277 ( V_146 ) ;
return 0 ;
}
int F_281 ( struct V_41 * V_146 )
{
int V_14 ;
F_115 ( & V_31 ) ;
V_14 = F_280 ( V_146 ) ;
F_99 ( & V_31 ) ;
return V_14 ;
}
static int F_282 ( struct V_28 * V_29 , struct V_41 * V_146 )
{
int V_14 ;
if ( ! F_1 ( V_29 -> V_17 ) )
return 0 ;
if ( ! V_146 || V_146 [ 0 ] . V_122 [ 0 ] == '\0' )
return 0 ;
V_14 = F_278 ( V_29 , V_146 ) ;
if ( V_14 )
return V_14 ;
F_115 ( & V_31 ) ;
F_51 ( & V_146 -> V_341 , & V_29 -> V_146 ) ;
V_14 = F_275 ( V_146 , true ) ;
if ( V_14 )
F_280 ( V_146 ) ;
F_99 ( & V_31 ) ;
return V_14 ;
}
int F_283 ( struct V_28 * V_29 , struct V_41 * V_146 )
{
struct V_41 * V_42 ;
for ( V_42 = V_146 ; V_42 && V_42 -> V_122 [ 0 ] != '\0' ; V_42 ++ )
V_42 -> V_35 |= V_329 ;
return F_282 ( V_29 , V_146 ) ;
}
int F_284 ( struct V_28 * V_29 , struct V_41 * V_146 )
{
struct V_41 * V_42 ;
for ( V_42 = V_146 ; V_42 && V_42 -> V_122 [ 0 ] != '\0' ; V_42 ++ )
V_42 -> V_35 |= V_330 ;
return F_282 ( V_29 , V_146 ) ;
}
void F_43 ( struct V_143 * V_144 )
{
unsigned long V_35 ;
F_64 ( & V_145 , V_35 ) ;
if ( V_144 -> V_39 )
F_285 ( V_144 -> V_39 ) ;
F_65 ( & V_145 , V_35 ) ;
}
static int F_286 ( const struct V_5 * V_6 )
{
int V_91 = 0 ;
struct V_53 * V_54 ;
F_82 ( & V_46 ) ;
F_45 (link, &cgrp->cset_links, cset_link)
V_91 += F_96 ( & V_54 -> V_45 -> V_70 ) ;
F_83 ( & V_46 ) ;
return V_91 ;
}
struct V_18 * F_121 ( struct V_18 * V_62 ,
struct V_18 * V_21 )
{
struct V_18 * V_88 ;
F_287 () ;
if ( ! V_62 ) {
V_88 = F_288 ( V_21 -> V_111 . V_88 , struct V_18 , V_200 ) ;
} else if ( F_289 ( ! ( V_62 -> V_35 & V_342 ) ) ) {
V_88 = F_288 ( V_62 -> V_200 . V_88 , struct V_18 , V_200 ) ;
} else {
F_290 (next, &parent->children, sibling)
if ( V_88 -> V_343 > V_62 -> V_343 )
break;
}
if ( & V_88 -> V_200 != & V_21 -> V_111 )
return V_88 ;
return NULL ;
}
struct V_18 *
F_291 ( struct V_18 * V_62 ,
struct V_18 * V_7 )
{
struct V_18 * V_88 ;
F_287 () ;
if ( ! V_62 )
return V_7 ;
V_88 = F_121 ( NULL , V_62 ) ;
if ( V_88 )
return V_88 ;
while ( V_62 != V_7 ) {
V_88 = F_121 ( V_62 , V_62 -> V_21 ) ;
if ( V_88 )
return V_88 ;
V_62 = V_62 -> V_21 ;
}
return NULL ;
}
struct V_18 *
F_292 ( struct V_18 * V_62 )
{
struct V_18 * V_344 , * V_345 ;
F_287 () ;
do {
V_344 = V_62 ;
V_62 = NULL ;
F_293 (tmp, last)
V_62 = V_345 ;
} while ( V_62 );
return V_344 ;
}
static struct V_18 *
F_294 ( struct V_18 * V_62 )
{
struct V_18 * V_344 ;
do {
V_344 = V_62 ;
V_62 = F_121 ( NULL , V_62 ) ;
} while ( V_62 );
return V_344 ;
}
struct V_18 *
F_295 ( struct V_18 * V_62 ,
struct V_18 * V_7 )
{
struct V_18 * V_88 ;
F_287 () ;
if ( ! V_62 )
return F_294 ( V_7 ) ;
if ( V_62 == V_7 )
return NULL ;
V_88 = F_121 ( V_62 , V_62 -> V_21 ) ;
if ( V_88 )
return F_294 ( V_88 ) ;
return V_62 -> V_21 ;
}
bool F_296 ( struct V_18 * V_32 )
{
struct V_18 * V_307 ;
bool V_14 = false ;
F_25 () ;
F_293 (child, css) {
if ( V_307 -> V_35 & V_36 ) {
V_14 = true ;
break;
}
}
F_28 () ;
return V_14 ;
}
static void F_297 ( struct V_60 * V_61 )
{
struct V_80 * V_346 = V_61 -> V_347 ;
struct V_53 * V_54 ;
struct V_44 * V_45 ;
F_23 ( & V_46 ) ;
do {
V_346 = V_346 -> V_88 ;
if ( V_346 == V_61 -> V_348 ) {
V_61 -> V_347 = NULL ;
V_61 -> V_64 = NULL ;
return;
}
if ( V_61 -> V_29 ) {
V_45 = F_16 ( V_346 , struct V_44 ,
V_71 [ V_61 -> V_29 -> V_17 ] ) ;
} else {
V_54 = F_70 ( V_346 , struct V_53 , V_74 ) ;
V_45 = V_54 -> V_45 ;
}
} while ( ! F_39 ( V_45 ) );
V_61 -> V_347 = V_346 ;
if ( ! F_40 ( & V_45 -> V_47 ) )
V_61 -> V_64 = V_45 -> V_47 . V_88 ;
else
V_61 -> V_64 = V_45 -> V_48 . V_88 ;
V_61 -> V_349 = & V_45 -> V_47 ;
V_61 -> V_350 = & V_45 -> V_48 ;
if ( V_61 -> V_248 ) {
F_56 ( & V_61 -> V_351 ) ;
F_54 ( V_61 -> V_248 ) ;
}
F_66 ( V_45 ) ;
V_61 -> V_248 = V_45 ;
F_77 ( & V_61 -> V_351 , & V_45 -> V_100 ) ;
}
static void F_48 ( struct V_60 * V_61 )
{
struct V_80 * V_346 = V_61 -> V_64 ;
F_23 ( & V_46 ) ;
F_31 ( ! V_346 ) ;
V_346 = V_346 -> V_88 ;
if ( V_346 == V_61 -> V_349 )
V_346 = V_61 -> V_350 -> V_88 ;
if ( V_346 == V_61 -> V_350 )
F_297 ( V_61 ) ;
else
V_61 -> V_64 = V_346 ;
}
void F_298 ( struct V_18 * V_32 ,
struct V_60 * V_61 )
{
F_31 ( ! V_196 ) ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_82 ( & V_46 ) ;
V_61 -> V_29 = V_32 -> V_29 ;
if ( V_61 -> V_29 )
V_61 -> V_347 = & V_32 -> V_5 -> V_103 [ V_32 -> V_29 -> V_17 ] ;
else
V_61 -> V_347 = & V_32 -> V_5 -> V_96 ;
V_61 -> V_348 = V_61 -> V_347 ;
F_297 ( V_61 ) ;
F_83 ( & V_46 ) ;
}
struct V_55 * F_299 ( struct V_60 * V_61 )
{
if ( V_61 -> V_250 ) {
F_221 ( V_61 -> V_250 ) ;
V_61 -> V_250 = NULL ;
}
F_82 ( & V_46 ) ;
if ( V_61 -> V_64 ) {
V_61 -> V_250 = F_70 ( V_61 -> V_64 , struct V_55 ,
V_63 ) ;
F_220 ( V_61 -> V_250 ) ;
F_48 ( V_61 ) ;
}
F_83 ( & V_46 ) ;
return V_61 -> V_250 ;
}
void F_300 ( struct V_60 * V_61 )
{
if ( V_61 -> V_248 ) {
F_82 ( & V_46 ) ;
F_56 ( & V_61 -> V_351 ) ;
F_54 ( V_61 -> V_248 ) ;
F_83 ( & V_46 ) ;
}
if ( V_61 -> V_250 )
F_221 ( V_61 -> V_250 ) ;
}
int F_301 ( struct V_5 * V_352 , struct V_5 * V_293 )
{
F_160 ( V_260 ) ;
struct V_53 * V_54 ;
struct V_60 V_61 ;
struct V_55 * V_56 ;
int V_14 ;
if ( ! F_198 ( V_352 ) )
return - V_156 ;
F_115 ( & V_31 ) ;
F_218 ( & V_285 ) ;
F_82 ( & V_46 ) ;
F_45 (link, &from->cset_links, cset_link)
F_200 ( V_54 -> V_45 , V_352 , & V_260 ) ;
F_83 ( & V_46 ) ;
V_14 = F_201 ( & V_260 ) ;
if ( V_14 )
goto V_353;
do {
F_298 ( & V_293 -> V_20 , & V_61 ) ;
V_56 = F_299 ( & V_61 ) ;
if ( V_56 )
F_220 ( V_56 ) ;
F_300 ( & V_61 ) ;
if ( V_56 ) {
V_14 = F_203 ( V_56 , false , V_352 -> V_7 ) ;
if ( ! V_14 )
F_302 ( V_352 , V_56 , false ) ;
F_221 ( V_56 ) ;
}
} while ( V_56 && ! V_14 );
V_353:
F_199 ( & V_260 ) ;
F_222 ( & V_285 ) ;
F_99 ( & V_31 ) ;
return V_14 ;
}
static void * F_303 ( int V_91 )
{
if ( F_304 ( V_91 ) )
return F_305 ( V_91 * sizeof( T_7 ) ) ;
else
return F_131 ( V_91 * sizeof( T_7 ) , V_93 ) ;
}
static void F_306 ( void * V_194 )
{
F_307 ( V_194 ) ;
}
static void F_308 ( struct V_5 * V_6 )
{
struct V_354 * V_346 , * V_355 ;
F_115 ( & V_6 -> V_202 ) ;
F_47 (l, tmp_l, &cgrp->pidlists, links)
F_309 ( V_356 , & V_346 -> V_357 , 0 ) ;
F_99 ( & V_6 -> V_202 ) ;
F_310 ( V_356 ) ;
F_69 ( ! F_40 ( & V_6 -> V_201 ) ) ;
}
static void F_311 ( struct V_358 * V_359 )
{
struct V_360 * V_361 = F_312 ( V_359 ) ;
struct V_354 * V_346 = F_16 ( V_361 , struct V_354 ,
V_357 ) ;
struct V_354 * V_362 = NULL ;
F_115 ( & V_346 -> V_363 -> V_202 ) ;
if ( ! F_313 ( V_361 ) ) {
F_56 ( & V_346 -> V_364 ) ;
F_306 ( V_346 -> V_365 ) ;
F_314 ( V_346 -> V_67 . V_225 ) ;
V_362 = V_346 ;
}
F_99 ( & V_346 -> V_363 -> V_202 ) ;
F_60 ( V_362 ) ;
}
static int F_315 ( T_7 * V_365 , int V_366 )
{
int V_367 , V_368 = 1 ;
if ( V_366 == 0 || V_366 == 1 )
return V_366 ;
for ( V_367 = 1 ; V_367 < V_366 ; V_367 ++ ) {
while ( V_365 [ V_367 ] == V_365 [ V_367 - 1 ] ) {
V_367 ++ ;
if ( V_367 == V_366 )
goto V_369;
}
V_365 [ V_368 ] = V_365 [ V_367 ] ;
V_368 ++ ;
}
V_369:
return V_368 ;
}
static T_7 F_316 ( T_7 V_283 )
{
unsigned V_370 = V_283 & 0x55555555 ;
unsigned V_371 = V_283 & 0xAAAAAAAA ;
return ( V_370 << 1 ) | ( V_371 >> 1 ) ;
}
static T_7 F_317 ( struct V_5 * V_6 , T_7 V_283 )
{
if ( F_4 ( V_6 ) )
return F_316 ( V_283 ) ;
else
return V_283 ;
}
static int F_318 ( const void * V_370 , const void * V_371 )
{
return * ( T_7 * ) V_370 - * ( T_7 * ) V_371 ;
}
static int F_319 ( const void * V_370 , const void * V_371 )
{
return F_316 ( * ( T_7 * ) V_370 ) - F_316 ( * ( T_7 * ) V_371 ) ;
}
static struct V_354 * F_320 ( struct V_5 * V_6 ,
enum V_372 type )
{
struct V_354 * V_346 ;
struct V_373 * V_225 = F_321 ( V_114 ) ;
F_23 ( & V_6 -> V_202 ) ;
F_45 (l, &cgrp->pidlists, links)
if ( V_346 -> V_67 . type == type && V_346 -> V_67 . V_225 == V_225 )
return V_346 ;
return NULL ;
}
static struct V_354 * F_322 ( struct V_5 * V_6 ,
enum V_372 type )
{
struct V_354 * V_346 ;
F_23 ( & V_6 -> V_202 ) ;
V_346 = F_320 ( V_6 , type ) ;
if ( V_346 )
return V_346 ;
V_346 = F_76 ( sizeof( struct V_354 ) , V_93 ) ;
if ( ! V_346 )
return V_346 ;
F_323 ( & V_346 -> V_357 , F_311 ) ;
V_346 -> V_67 . type = type ;
V_346 -> V_67 . V_225 = F_324 ( F_321 ( V_114 ) ) ;
V_346 -> V_363 = V_6 ;
F_77 ( & V_346 -> V_364 , & V_6 -> V_201 ) ;
return V_346 ;
}
static int F_325 ( struct V_5 * V_6 , enum V_372 type ,
struct V_354 * * V_374 )
{
T_7 * V_375 ;
int V_366 ;
int V_283 , V_376 = 0 ;
struct V_60 V_61 ;
struct V_55 * V_282 ;
struct V_354 * V_346 ;
F_23 ( & V_6 -> V_202 ) ;
V_366 = F_286 ( V_6 ) ;
V_375 = F_303 ( V_366 ) ;
if ( ! V_375 )
return - V_94 ;
F_298 ( & V_6 -> V_20 , & V_61 ) ;
while ( ( V_282 = F_299 ( & V_61 ) ) ) {
if ( F_326 ( V_376 == V_366 ) )
break;
if ( type == V_377 )
V_283 = F_327 ( V_282 ) ;
else
V_283 = F_328 ( V_282 ) ;
if ( V_283 > 0 )
V_375 [ V_376 ++ ] = V_283 ;
}
F_300 ( & V_61 ) ;
V_366 = V_376 ;
if ( F_4 ( V_6 ) )
F_329 ( V_375 , V_366 , sizeof( T_7 ) , F_319 , NULL ) ;
else
F_329 ( V_375 , V_366 , sizeof( T_7 ) , F_318 , NULL ) ;
if ( type == V_377 )
V_366 = F_315 ( V_375 , V_366 ) ;
V_346 = F_322 ( V_6 , type ) ;
if ( ! V_346 ) {
F_306 ( V_375 ) ;
return - V_94 ;
}
F_306 ( V_346 -> V_365 ) ;
V_346 -> V_365 = V_375 ;
V_346 -> V_366 = V_366 ;
* V_374 = V_346 ;
return 0 ;
}
int F_330 ( struct V_378 * V_379 , struct V_216 * V_216 )
{
struct V_139 * V_39 = F_331 ( V_216 ) ;
struct V_5 * V_6 ;
struct V_60 V_61 ;
struct V_55 * V_282 ;
if ( V_216 -> V_238 -> V_380 != & V_381 || ! V_39 ||
F_111 ( V_39 ) != V_140 )
return - V_185 ;
F_115 ( & V_31 ) ;
F_25 () ;
V_6 = F_332 ( V_39 -> V_40 ) ;
if ( ! V_6 || F_29 ( V_6 ) ) {
F_28 () ;
F_99 ( & V_31 ) ;
return - V_190 ;
}
F_28 () ;
F_298 ( & V_6 -> V_20 , & V_61 ) ;
while ( ( V_282 = F_299 ( & V_61 ) ) ) {
switch ( V_282 -> V_382 ) {
case V_383 :
V_379 -> V_384 ++ ;
break;
case V_385 :
V_379 -> V_386 ++ ;
break;
case V_387 :
V_379 -> V_388 ++ ;
break;
case V_389 :
V_379 -> V_390 ++ ;
break;
default:
if ( F_333 ( V_282 ) )
V_379 -> V_391 ++ ;
break;
}
}
F_300 ( & V_61 ) ;
F_99 ( & V_31 ) ;
return 0 ;
}
static void * F_334 ( struct V_161 * V_392 , T_6 * V_62 )
{
struct V_37 * V_38 = V_392 -> V_393 ;
struct V_5 * V_6 = F_229 ( V_392 ) -> V_5 ;
struct V_354 * V_346 ;
enum V_372 type = F_256 ( V_392 ) -> V_393 ;
int V_394 = 0 , V_283 = * V_62 ;
int * V_395 , V_14 ;
F_115 ( & V_6 -> V_202 ) ;
if ( V_38 -> V_40 )
V_38 -> V_40 = F_320 ( V_6 , type ) ;
if ( ! V_38 -> V_40 ) {
V_14 = F_325 ( V_6 , type ,
(struct V_354 * * ) & V_38 -> V_40 ) ;
if ( V_14 )
return F_171 ( V_14 ) ;
}
V_346 = V_38 -> V_40 ;
if ( V_283 ) {
int V_12 = V_346 -> V_366 ;
while ( V_394 < V_12 ) {
int V_396 = ( V_394 + V_12 ) / 2 ;
if ( F_317 ( V_6 , V_346 -> V_365 [ V_396 ] ) == V_283 ) {
V_394 = V_396 ;
break;
} else if ( F_317 ( V_6 , V_346 -> V_365 [ V_396 ] ) <= V_283 )
V_394 = V_396 + 1 ;
else
V_12 = V_396 ;
}
}
if ( V_394 >= V_346 -> V_366 )
return NULL ;
V_395 = V_346 -> V_365 + V_394 ;
* V_62 = F_317 ( V_6 , * V_395 ) ;
return V_395 ;
}
static void F_335 ( struct V_161 * V_392 , void * V_296 )
{
struct V_37 * V_38 = V_392 -> V_393 ;
struct V_354 * V_346 = V_38 -> V_40 ;
if ( V_346 )
F_309 ( V_356 , & V_346 -> V_357 ,
V_397 ) ;
F_99 ( & F_229 ( V_392 ) -> V_5 -> V_202 ) ;
}
static void * F_336 ( struct V_161 * V_392 , void * V_296 , T_6 * V_62 )
{
struct V_37 * V_38 = V_392 -> V_393 ;
struct V_354 * V_346 = V_38 -> V_40 ;
T_7 * V_194 = V_296 ;
T_7 * V_12 = V_346 -> V_365 + V_346 -> V_366 ;
V_194 ++ ;
if ( V_194 >= V_12 ) {
return NULL ;
} else {
* V_62 = F_317 ( F_229 ( V_392 ) -> V_5 , * V_194 ) ;
return V_194 ;
}
}
static int F_337 ( struct V_161 * V_392 , void * V_296 )
{
F_233 ( V_392 , L_31 , * ( int * ) V_296 ) ;
return 0 ;
}
static T_8 F_338 ( struct V_18 * V_32 ,
struct V_41 * V_42 )
{
return F_37 ( V_32 -> V_5 ) ;
}
static int F_339 ( struct V_18 * V_32 ,
struct V_41 * V_42 , T_8 V_398 )
{
if ( V_398 )
F_158 ( V_43 , & V_32 -> V_5 -> V_35 ) ;
else
F_340 ( V_43 , & V_32 -> V_5 -> V_35 ) ;
return 0 ;
}
static T_8 F_341 ( struct V_18 * V_32 ,
struct V_41 * V_42 )
{
return F_38 ( V_173 , & V_32 -> V_5 -> V_35 ) ;
}
static int F_342 ( struct V_18 * V_32 ,
struct V_41 * V_42 , T_8 V_398 )
{
if ( V_398 )
F_158 ( V_173 , & V_32 -> V_5 -> V_35 ) ;
else
F_340 ( V_173 , & V_32 -> V_5 -> V_35 ) ;
return 0 ;
}
static void F_343 ( struct V_358 * V_359 )
{
struct V_18 * V_32 =
F_16 ( V_359 , struct V_18 , V_399 ) ;
struct V_28 * V_29 = V_32 -> V_29 ;
struct V_5 * V_6 = V_32 -> V_5 ;
F_166 ( & V_32 -> V_208 ) ;
if ( V_29 ) {
struct V_18 * V_21 = V_32 -> V_21 ;
int V_17 = V_32 -> V_17 ;
V_29 -> V_400 ( V_32 ) ;
F_13 ( & V_29 -> V_401 , V_17 ) ;
F_59 ( V_6 ) ;
if ( V_21 )
F_57 ( V_21 ) ;
} else {
F_344 ( & V_6 -> V_7 -> V_110 ) ;
F_308 ( V_6 ) ;
F_345 ( & V_6 -> V_204 ) ;
if ( F_15 ( V_6 ) ) {
F_59 ( F_15 ( V_6 ) ) ;
F_346 ( V_6 -> V_39 ) ;
F_60 ( V_6 ) ;
} else {
F_93 ( V_6 -> V_7 ) ;
}
}
}
static void F_347 ( struct V_76 * V_76 )
{
struct V_18 * V_32 =
F_16 ( V_76 , struct V_18 , V_76 ) ;
F_155 ( & V_32 -> V_399 , F_343 ) ;
F_348 ( V_402 , & V_32 -> V_399 ) ;
}
static void F_349 ( struct V_358 * V_359 )
{
struct V_18 * V_32 =
F_16 ( V_359 , struct V_18 , V_399 ) ;
struct V_28 * V_29 = V_32 -> V_29 ;
struct V_5 * V_6 = V_32 -> V_5 ;
F_115 ( & V_31 ) ;
V_32 -> V_35 |= V_342 ;
F_350 ( & V_32 -> V_200 ) ;
if ( V_29 ) {
F_11 ( & V_29 -> V_401 , NULL , V_32 -> V_17 ) ;
if ( V_29 -> V_403 )
V_29 -> V_403 ( V_32 ) ;
} else {
F_351 ( V_6 ) ;
F_13 ( & V_6 -> V_7 -> V_109 , V_6 -> V_17 ) ;
V_6 -> V_17 = - 1 ;
if ( V_6 -> V_39 )
F_124 ( * ( void V_404 V_405 * * ) & V_6 -> V_39 -> V_40 ,
NULL ) ;
F_352 ( V_6 ) ;
}
F_99 ( & V_31 ) ;
F_353 ( & V_32 -> V_76 , F_347 ) ;
}
static void V_209 ( struct V_406 * V_407 )
{
struct V_18 * V_32 =
F_16 ( V_407 , struct V_18 , V_208 ) ;
F_155 ( & V_32 -> V_399 , F_349 ) ;
F_348 ( V_402 , & V_32 -> V_399 ) ;
}
static void F_354 ( struct V_18 * V_32 ,
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
V_32 -> V_343 = V_408 ++ ;
F_84 ( & V_32 -> V_409 , 0 ) ;
if ( F_15 ( V_6 ) ) {
V_32 -> V_21 = F_19 ( F_15 ( V_6 ) , V_29 ) ;
F_27 ( V_32 -> V_21 ) ;
}
F_69 ( F_19 ( V_6 , V_29 ) ) ;
}
static int F_355 ( struct V_18 * V_32 )
{
struct V_28 * V_29 = V_32 -> V_29 ;
int V_14 = 0 ;
F_23 ( & V_31 ) ;
if ( V_29 -> V_410 )
V_14 = V_29 -> V_410 ( V_32 ) ;
if ( ! V_14 ) {
V_32 -> V_35 |= V_36 ;
F_50 ( V_32 -> V_5 -> V_30 [ V_29 -> V_17 ] , V_32 ) ;
F_67 ( & V_32 -> V_409 ) ;
if ( V_32 -> V_21 )
F_67 ( & V_32 -> V_21 -> V_409 ) ;
}
return V_14 ;
}
static void F_356 ( struct V_18 * V_32 )
{
struct V_28 * V_29 = V_32 -> V_29 ;
F_23 ( & V_31 ) ;
if ( ! ( V_32 -> V_35 & V_36 ) )
return;
if ( V_29 -> V_304 )
V_29 -> V_304 ( V_32 ) ;
if ( V_29 -> V_411 )
V_29 -> V_411 ( V_32 ) ;
V_32 -> V_35 &= ~ V_36 ;
F_124 ( V_32 -> V_5 -> V_30 [ V_29 -> V_17 ] , NULL ) ;
F_357 ( & V_32 -> V_5 -> V_203 ) ;
}
static struct V_18 * F_245 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
struct V_5 * V_21 = F_15 ( V_6 ) ;
struct V_18 * V_19 = F_19 ( V_21 , V_29 ) ;
struct V_18 * V_32 ;
int V_151 ;
F_23 ( & V_31 ) ;
V_32 = V_29 -> V_412 ( V_19 ) ;
if ( ! V_32 )
V_32 = F_171 ( - V_94 ) ;
if ( F_163 ( V_32 ) )
return V_32 ;
F_354 ( V_32 , V_29 , V_6 ) ;
V_151 = F_161 ( & V_32 -> V_208 , V_209 , 0 , V_93 ) ;
if ( V_151 )
goto V_413;
V_151 = F_5 ( & V_29 -> V_401 , NULL , 2 , 0 , V_93 ) ;
if ( V_151 < 0 )
goto V_413;
V_32 -> V_17 = V_151 ;
F_358 ( & V_32 -> V_200 , & V_19 -> V_111 ) ;
F_11 ( & V_29 -> V_401 , V_32 , V_32 -> V_17 ) ;
V_151 = F_355 ( V_32 ) ;
if ( V_151 )
goto V_414;
if ( V_29 -> V_415 && ! V_29 -> V_416 &&
F_15 ( V_21 ) ) {
F_128 ( L_32 ,
V_114 -> V_193 , V_114 -> V_283 , V_29 -> V_122 ) ;
if ( ! strcmp ( V_29 -> V_122 , L_33 ) )
F_128 ( L_34 ) ;
V_29 -> V_416 = true ;
}
return V_32 ;
V_414:
F_350 ( & V_32 -> V_200 ) ;
V_413:
F_353 ( & V_32 -> V_76 , F_347 ) ;
return F_171 ( V_151 ) ;
}
static struct V_5 * F_359 ( struct V_5 * V_21 )
{
struct V_89 * V_7 = V_21 -> V_7 ;
struct V_5 * V_6 , * V_417 ;
int V_418 = V_21 -> V_418 + 1 ;
int V_14 ;
V_6 = F_76 ( sizeof( * V_6 ) +
sizeof( V_6 -> V_207 [ 0 ] ) * ( V_418 + 1 ) , V_93 ) ;
if ( ! V_6 )
return F_171 ( - V_94 ) ;
V_14 = F_161 ( & V_6 -> V_20 . V_208 , V_209 , 0 , V_93 ) ;
if ( V_14 )
goto V_419;
V_6 -> V_17 = F_5 ( & V_7 -> V_109 , NULL , 2 , 0 , V_93 ) ;
if ( V_6 -> V_17 < 0 ) {
V_14 = - V_94 ;
goto V_420;
}
F_152 ( V_6 ) ;
V_6 -> V_20 . V_21 = & V_21 -> V_20 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_418 = V_418 ;
for ( V_417 = V_6 ; V_417 ; V_417 = F_15 ( V_417 ) )
V_6 -> V_207 [ V_417 -> V_418 ] = V_417 -> V_17 ;
if ( F_37 ( V_21 ) )
F_158 ( V_43 , & V_6 -> V_35 ) ;
if ( F_38 ( V_173 , & V_21 -> V_35 ) )
F_158 ( V_173 , & V_6 -> V_35 ) ;
V_6 -> V_20 . V_343 = V_408 ++ ;
F_358 ( & V_6 -> V_20 . V_200 , & F_15 ( V_6 ) -> V_20 . V_111 ) ;
F_67 ( & V_7 -> V_110 ) ;
F_30 ( V_21 ) ;
F_11 ( & V_7 -> V_109 , V_6 , V_6 -> V_17 ) ;
if ( ! F_4 ( V_6 ) )
V_6 -> V_24 = F_17 ( V_6 ) ;
if ( V_21 )
F_360 ( V_6 , V_21 ) ;
F_239 ( V_6 ) ;
return V_6 ;
V_420:
F_166 ( & V_6 -> V_20 . V_208 ) ;
V_419:
F_60 ( V_6 ) ;
return F_171 ( V_14 ) ;
}
static int F_361 ( struct V_139 * V_421 , const char * V_122 ,
T_3 V_124 )
{
struct V_5 * V_21 , * V_6 ;
struct V_139 * V_39 ;
int V_14 ;
if ( strchr ( V_122 , '\n' ) )
return - V_185 ;
V_21 = F_113 ( V_421 , false ) ;
if ( ! V_21 )
return - V_284 ;
V_6 = F_359 ( V_21 ) ;
if ( F_163 ( V_6 ) ) {
V_14 = F_164 ( V_6 ) ;
goto V_33;
}
V_39 = F_362 ( V_21 -> V_39 , V_122 , V_124 , V_6 ) ;
if ( F_163 ( V_39 ) ) {
V_14 = F_164 ( V_39 ) ;
goto V_422;
}
V_6 -> V_39 = V_39 ;
F_363 ( V_39 ) ;
V_14 = F_266 ( V_39 ) ;
if ( V_14 )
goto V_422;
V_14 = F_120 ( & V_6 -> V_20 ) ;
if ( V_14 )
goto V_422;
V_14 = F_243 ( V_6 ) ;
if ( V_14 )
goto V_422;
F_364 ( V_6 ) ;
F_129 ( V_39 ) ;
V_14 = 0 ;
goto V_33;
V_422:
F_365 ( V_6 ) ;
V_33:
F_110 ( V_421 ) ;
return V_14 ;
}
static void F_366 ( struct V_358 * V_359 )
{
struct V_18 * V_32 =
F_16 ( V_359 , struct V_18 , V_399 ) ;
F_115 ( & V_31 ) ;
do {
F_356 ( V_32 ) ;
F_57 ( V_32 ) ;
V_32 = V_32 -> V_21 ;
} while ( V_32 && F_55 ( & V_32 -> V_409 ) );
F_99 ( & V_31 ) ;
}
static void F_367 ( struct V_406 * V_407 )
{
struct V_18 * V_32 =
F_16 ( V_407 , struct V_18 , V_208 ) ;
if ( F_55 ( & V_32 -> V_409 ) ) {
F_155 ( & V_32 -> V_399 , F_366 ) ;
F_348 ( V_402 , & V_32 -> V_399 ) ;
}
}
static void F_247 ( struct V_18 * V_32 )
{
F_23 ( & V_31 ) ;
F_118 ( V_32 ) ;
F_27 ( V_32 ) ;
F_368 ( & V_32 -> V_208 , F_367 ) ;
}
static int F_365 ( struct V_5 * V_6 )
__releases( &cgroup_mutex
static int F_369 ( struct V_139 * V_39 )
{
struct V_5 * V_6 ;
int V_14 = 0 ;
V_6 = F_113 ( V_39 , false ) ;
if ( ! V_6 )
return 0 ;
V_14 = F_365 ( V_6 ) ;
if ( ! V_14 )
F_370 ( V_6 ) ;
F_110 ( V_39 ) ;
return V_14 ;
}
static void T_9 F_371 ( struct V_28 * V_29 , bool V_423 )
{
struct V_18 * V_32 ;
F_372 ( L_35 , V_29 -> V_122 ) ;
F_115 ( & V_31 ) ;
F_157 ( & V_29 -> V_401 ) ;
F_75 ( & V_29 -> V_146 ) ;
V_29 -> V_7 = & V_8 ;
V_32 = V_29 -> V_412 ( F_19 ( & V_8 . V_6 , V_29 ) ) ;
F_69 ( F_163 ( V_32 ) ) ;
F_354 ( V_32 , V_29 , & V_8 . V_6 ) ;
V_32 -> V_35 |= V_424 ;
if ( V_423 ) {
V_32 -> V_17 = 1 ;
} else {
V_32 -> V_17 = F_5 ( & V_29 -> V_401 , V_32 , 1 , 2 , V_93 ) ;
F_69 ( V_32 -> V_17 < 0 ) ;
}
V_34 . V_30 [ V_29 -> V_17 ] = V_32 ;
V_425 |= ( bool ) V_29 -> V_426 << V_29 -> V_17 ;
V_427 |= ( bool ) V_29 -> exit << V_29 -> V_17 ;
V_428 |= ( bool ) V_29 -> free << V_29 -> V_17 ;
V_429 |= ( bool ) V_29 -> V_430 << V_29 -> V_17 ;
F_69 ( ! F_40 ( & V_431 . V_47 ) ) ;
F_69 ( F_355 ( V_32 ) ) ;
F_99 ( & V_31 ) ;
}
int T_9 F_373 ( void )
{
static struct V_175 T_10 V_176 ;
struct V_28 * V_29 ;
int V_68 ;
F_156 ( & V_8 , & V_176 ) ;
V_8 . V_6 . V_20 . V_35 |= V_424 ;
F_124 ( V_431 . V_66 , & V_34 ) ;
F_53 (ss, i) {
F_374 ( ! V_29 -> V_412 || ! V_29 -> V_400 || V_29 -> V_122 || V_29 -> V_17 ,
L_36 ,
V_68 , V_432 [ V_68 ] , V_29 -> V_412 , V_29 -> V_400 ,
V_29 -> V_17 , V_29 -> V_122 ) ;
F_374 ( strlen ( V_432 [ V_68 ] ) > V_433 ,
L_37 , V_432 [ V_68 ] ) ;
V_29 -> V_17 = V_68 ;
V_29 -> V_122 = V_432 [ V_68 ] ;
if ( ! V_29 -> V_123 )
V_29 -> V_123 = V_432 [ V_68 ] ;
if ( V_29 -> V_434 )
F_371 ( V_29 , true ) ;
}
return 0 ;
}
int T_9 F_375 ( void )
{
struct V_28 * V_29 ;
int V_1 ;
F_227 ( V_2 > 16 ) ;
F_69 ( F_376 ( & V_285 ) ) ;
F_69 ( F_278 ( NULL , V_149 ) ) ;
F_69 ( F_278 ( NULL , V_150 ) ) ;
F_377 ( & V_285 . V_435 ) ;
F_378 ( V_234 . V_227 ) ;
F_115 ( & V_31 ) ;
F_86 ( V_102 , & V_34 . V_72 ,
F_52 ( V_34 . V_30 ) ) ;
F_69 ( F_159 ( & V_8 , 0 ) ) ;
F_99 ( & V_31 ) ;
F_53 (ss, ssid) {
if ( V_29 -> V_434 ) {
struct V_18 * V_32 =
V_34 . V_30 [ V_29 -> V_17 ] ;
V_32 -> V_17 = F_5 ( & V_29 -> V_401 , V_32 , 1 , 2 ,
V_93 ) ;
F_69 ( V_32 -> V_17 < 0 ) ;
} else {
F_371 ( V_29 , false ) ;
}
F_51 ( & V_34 . V_71 [ V_1 ] ,
& V_8 . V_6 . V_103 [ V_1 ] ) ;
if ( V_436 & ( 1 << V_1 ) ) {
F_127 ( V_3 [ V_1 ] ) ;
F_379 ( V_437 L_38 ,
V_29 -> V_122 ) ;
continue;
}
if ( F_3 ( V_1 ) )
F_379 ( V_437 L_39 ,
V_29 -> V_122 ) ;
V_8 . V_23 |= 1 << V_29 -> V_17 ;
if ( V_29 -> V_155 )
V_26 |= 1 << V_29 -> V_17 ;
else if ( ! V_29 -> V_438 )
V_25 |= 1 << V_29 -> V_17 ;
if ( V_29 -> V_438 == V_29 -> V_439 ) {
F_97 ( F_282 ( V_29 , V_29 -> V_438 ) ) ;
} else {
F_97 ( F_283 ( V_29 , V_29 -> V_438 ) ) ;
F_97 ( F_284 ( V_29 , V_29 -> V_439 ) ) ;
}
if ( V_29 -> V_160 )
V_29 -> V_160 ( V_34 . V_30 [ V_1 ] ) ;
}
F_58 ( & V_34 . V_72 ) ;
F_86 ( V_102 , & V_34 . V_72 ,
F_52 ( V_34 . V_30 ) ) ;
F_97 ( F_380 ( V_440 , L_40 ) ) ;
F_97 ( F_381 ( & V_381 ) ) ;
F_97 ( F_381 ( & V_221 ) ) ;
F_97 ( ! F_382 ( L_41 , 0 , NULL , & V_441 ) ) ;
return 0 ;
}
static int T_9 F_383 ( void )
{
V_402 = F_384 ( L_42 , 0 , 1 ) ;
F_69 ( ! V_402 ) ;
V_356 = F_384 ( L_43 ,
0 , 1 ) ;
F_69 ( ! V_356 ) ;
return 0 ;
}
int F_385 ( struct V_161 * V_310 , struct V_373 * V_225 ,
struct V_283 * V_283 , struct V_55 * V_282 )
{
char * V_118 ;
int V_294 ;
struct V_89 * V_7 ;
V_294 = - V_94 ;
V_118 = F_131 ( V_167 , V_93 ) ;
if ( ! V_118 )
goto V_206;
F_115 ( & V_31 ) ;
F_82 ( & V_46 ) ;
F_175 (root) {
struct V_28 * V_29 ;
struct V_5 * V_6 ;
int V_1 , V_91 = 0 ;
if ( V_7 == & V_8 && ! V_230 )
continue;
F_233 ( V_310 , L_44 , V_7 -> V_108 ) ;
if ( V_7 != & V_8 )
F_53 (ss, ssid)
if ( V_7 -> V_23 & ( 1 << V_1 ) )
F_233 ( V_310 , L_45 , V_91 ++ ? L_9 : L_20 ,
V_29 -> V_123 ) ;
if ( strlen ( V_7 -> V_122 ) )
F_233 ( V_310 , L_46 , V_91 ? L_9 : L_20 ,
V_7 -> V_122 ) ;
F_230 ( V_310 , ':' ) ;
V_6 = F_103 ( V_282 , V_7 ) ;
if ( F_4 ( V_6 ) || ! ( V_282 -> V_35 & V_65 ) ) {
V_294 = F_186 ( V_6 , V_118 , V_167 ,
V_114 -> V_115 -> V_116 ) ;
if ( V_294 >= V_167 )
V_294 = - V_442 ;
if ( V_294 < 0 )
goto V_33;
F_136 ( V_310 , V_118 ) ;
} else {
F_136 ( V_310 , L_23 ) ;
}
if ( F_4 ( V_6 ) && F_29 ( V_6 ) )
F_136 ( V_310 , L_47 ) ;
else
F_230 ( V_310 , '\n' ) ;
}
V_294 = 0 ;
V_33:
F_83 ( & V_46 ) ;
F_99 ( & V_31 ) ;
F_60 ( V_118 ) ;
V_206:
return V_294 ;
}
static int F_386 ( struct V_161 * V_310 , void * V_296 )
{
struct V_28 * V_29 ;
int V_68 ;
F_136 ( V_310 , L_48 ) ;
F_115 ( & V_31 ) ;
F_53 (ss, i)
F_233 ( V_310 , L_49 ,
V_29 -> V_123 , V_29 -> V_7 -> V_108 ,
F_96 ( & V_29 -> V_7 -> V_110 ) ,
F_1 ( V_68 ) ) ;
F_99 ( & V_31 ) ;
return 0 ;
}
static int F_387 ( struct V_277 * V_277 , struct V_275 * V_275 )
{
return F_388 ( V_275 , F_386 , NULL ) ;
}
void F_389 ( struct V_55 * V_307 )
{
F_124 ( V_307 -> V_66 , & V_34 ) ;
F_75 ( & V_307 -> V_63 ) ;
}
int F_390 ( struct V_55 * V_307 )
{
struct V_28 * V_29 ;
int V_68 , V_443 , V_14 ;
F_108 (ss, i, have_canfork_callback) {
V_14 = V_29 -> V_430 ( V_307 ) ;
if ( V_14 )
goto V_444;
} F_109 () ;
return 0 ;
V_444:
F_53 (ss, j) {
if ( V_443 >= V_68 )
break;
if ( V_29 -> V_445 )
V_29 -> V_445 ( V_307 ) ;
}
return V_14 ;
}
void F_391 ( struct V_55 * V_307 )
{
struct V_28 * V_29 ;
int V_68 ;
F_53 (ss, i)
if ( V_29 -> V_445 )
V_29 -> V_445 ( V_307 ) ;
}
void F_392 ( struct V_55 * V_307 )
{
struct V_28 * V_29 ;
int V_68 ;
if ( V_196 ) {
struct V_44 * V_45 ;
F_82 ( & V_46 ) ;
V_45 = F_104 ( V_114 ) ;
if ( F_40 ( & V_307 -> V_63 ) ) {
F_66 ( V_45 ) ;
F_46 ( V_307 , NULL , V_45 , false ) ;
}
F_83 ( & V_46 ) ;
}
F_108 (ss, i, have_fork_callback) {
V_29 -> V_426 ( V_307 ) ;
} F_109 () ;
}
void F_393 ( struct V_55 * V_282 )
{
struct V_28 * V_29 ;
struct V_44 * V_45 ;
int V_68 ;
V_45 = F_104 ( V_282 ) ;
if ( ! F_40 ( & V_282 -> V_63 ) ) {
F_82 ( & V_46 ) ;
F_46 ( V_282 , V_45 , NULL , false ) ;
F_83 ( & V_46 ) ;
} else {
F_66 ( V_45 ) ;
}
F_108 (ss, i, have_exit_callback) {
V_29 -> exit ( V_282 ) ;
} F_109 () ;
}
void F_394 ( struct V_55 * V_56 )
{
struct V_44 * V_45 = F_104 ( V_56 ) ;
struct V_28 * V_29 ;
int V_1 ;
F_108 (ss, ssid, have_free_callback) {
V_29 -> free ( V_56 ) ;
} F_109 () ;
F_62 ( V_45 ) ;
}
static void F_42 ( struct V_5 * V_6 )
{
if ( F_37 ( V_6 ) && ! F_251 ( V_6 ) &&
! F_296 ( & V_6 -> V_20 ) && ! F_29 ( V_6 ) )
F_395 ( & V_6 -> V_204 ) ;
}
static void V_205 ( struct V_358 * V_359 )
{
struct V_5 * V_6 =
F_16 ( V_359 , struct V_5 , V_204 ) ;
char * V_446 = NULL , * V_447 = NULL ;
char * V_448 [ 3 ] , * V_449 [ 3 ] ;
int V_14 ;
F_115 ( & V_31 ) ;
V_446 = F_131 ( V_167 , V_93 ) ;
V_447 = F_396 ( V_6 -> V_7 -> V_172 , V_93 ) ;
if ( ! V_446 || ! V_447 )
goto V_206;
F_82 ( & V_46 ) ;
V_14 = F_186 ( V_6 , V_446 , V_167 , & V_234 ) ;
F_83 ( & V_46 ) ;
if ( V_14 < 0 || V_14 >= V_167 )
goto V_206;
V_448 [ 0 ] = V_447 ;
V_448 [ 1 ] = V_446 ;
V_448 [ 2 ] = NULL ;
V_449 [ 0 ] = L_50 ;
V_449 [ 1 ] = L_51 ;
V_449 [ 2 ] = NULL ;
F_99 ( & V_31 ) ;
F_397 ( V_448 [ 0 ] , V_448 , V_449 , V_450 ) ;
goto V_232;
V_206:
F_99 ( & V_31 ) ;
V_232:
F_60 ( V_447 ) ;
F_60 ( V_446 ) ;
}
static int T_9 F_398 ( char * V_451 )
{
struct V_28 * V_29 ;
char * V_177 ;
int V_68 ;
while ( ( V_177 = F_141 ( & V_451 , L_9 ) ) != NULL ) {
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
static int T_9 F_399 ( char * V_451 )
{
struct V_28 * V_29 ;
char * V_177 ;
int V_68 ;
while ( ( V_177 = F_141 ( & V_451 , L_9 ) ) != NULL ) {
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
struct V_18 * F_400 ( struct V_216 * V_216 ,
struct V_28 * V_29 )
{
struct V_139 * V_39 = F_331 ( V_216 ) ;
struct V_217 * V_380 = V_216 -> V_238 -> V_380 ;
struct V_18 * V_32 = NULL ;
struct V_5 * V_6 ;
if ( ( V_380 != & V_381 && V_380 != & V_221 ) ||
! V_39 || F_111 ( V_39 ) != V_140 )
return F_171 ( - V_452 ) ;
F_25 () ;
V_6 = F_332 ( V_39 -> V_40 ) ;
if ( V_6 )
V_32 = F_19 ( V_6 , V_29 ) ;
if ( ! V_32 || ! F_26 ( V_32 ) )
V_32 = F_171 ( - V_190 ) ;
F_28 () ;
return V_32 ;
}
struct V_18 * F_401 ( int V_17 , struct V_28 * V_29 )
{
F_31 ( ! F_402 () ) ;
return F_403 ( & V_29 -> V_401 , V_17 ) ;
}
struct V_5 * F_404 ( const char * V_453 )
{
struct V_139 * V_39 ;
struct V_5 * V_6 ;
F_115 ( & V_31 ) ;
V_39 = F_405 ( V_8 . V_6 . V_39 , V_453 ) ;
if ( V_39 ) {
if ( F_111 ( V_39 ) == V_140 ) {
V_6 = V_39 -> V_40 ;
F_30 ( V_6 ) ;
} else {
V_6 = F_171 ( - V_314 ) ;
}
F_346 ( V_39 ) ;
} else {
V_6 = F_171 ( - V_190 ) ;
}
F_99 ( & V_31 ) ;
return V_6 ;
}
struct V_5 * F_406 ( int V_454 )
{
struct V_18 * V_32 ;
struct V_5 * V_6 ;
struct V_275 * V_455 ;
V_455 = F_407 ( V_454 ) ;
if ( ! V_455 )
return F_171 ( - V_452 ) ;
V_32 = F_400 ( V_455 -> V_276 . V_216 , NULL ) ;
F_408 ( V_455 ) ;
if ( F_163 ( V_32 ) )
return F_409 ( V_32 ) ;
V_6 = V_32 -> V_5 ;
if ( ! F_4 ( V_6 ) ) {
F_59 ( V_6 ) ;
return F_171 ( - V_452 ) ;
}
return V_6 ;
}
void F_410 ( void )
{
if ( V_456 )
return;
F_411 ( L_52 ) ;
V_456 = true ;
}
void F_412 ( struct V_457 * V_458 )
{
if ( V_456 )
return;
if ( V_458 -> V_398 ) {
F_30 ( F_413 ( V_458 ) ) ;
return;
}
F_25 () ;
while ( true ) {
struct V_44 * V_45 ;
V_45 = F_104 ( V_114 ) ;
if ( F_289 ( F_32 ( V_45 -> V_95 ) ) ) {
V_458 -> V_398 = ( unsigned long ) V_45 -> V_95 ;
break;
}
F_414 () ;
}
F_28 () ;
}
void F_415 ( struct V_457 * V_458 )
{
F_59 ( F_413 ( V_458 ) ) ;
}
static struct V_459 * F_416 ( struct V_460 * V_225 )
{
return F_417 ( V_225 , F_418 () , V_461 ) ;
}
static void F_419 ( struct V_459 * V_459 )
{
F_420 ( V_459 , V_461 ) ;
}
static struct V_224 * F_421 ( void )
{
struct V_224 * V_462 ;
int V_14 ;
V_462 = F_76 ( sizeof( struct V_224 ) , V_93 ) ;
if ( ! V_462 )
return F_171 ( - V_94 ) ;
V_14 = F_422 ( & V_462 -> V_225 ) ;
if ( V_14 ) {
F_60 ( V_462 ) ;
return F_171 ( V_14 ) ;
}
F_84 ( & V_462 -> V_91 , 1 ) ;
V_462 -> V_225 . V_463 = & V_464 ;
return V_462 ;
}
void F_423 ( struct V_224 * V_225 )
{
F_62 ( V_225 -> V_117 ) ;
F_419 ( V_225 -> V_459 ) ;
F_424 ( V_225 -> V_227 ) ;
F_425 ( & V_225 -> V_225 ) ;
F_60 ( V_225 ) ;
}
struct V_224 * F_426 ( unsigned long V_35 ,
struct V_460 * V_227 ,
struct V_224 * V_465 )
{
struct V_224 * V_462 ;
struct V_459 * V_459 ;
struct V_44 * V_45 ;
F_69 ( ! V_465 ) ;
if ( ! ( V_35 & V_466 ) ) {
F_168 ( V_465 ) ;
return V_465 ;
}
if ( ! F_169 ( V_227 , V_228 ) )
return F_171 ( - V_229 ) ;
V_459 = F_416 ( V_227 ) ;
if ( ! V_459 )
return F_171 ( - V_467 ) ;
F_82 ( & V_46 ) ;
V_45 = F_104 ( V_114 ) ;
F_66 ( V_45 ) ;
F_83 ( & V_46 ) ;
V_462 = F_421 () ;
if ( F_163 ( V_462 ) ) {
F_62 ( V_45 ) ;
F_419 ( V_459 ) ;
return V_462 ;
}
V_462 -> V_227 = F_378 ( V_227 ) ;
V_462 -> V_459 = V_459 ;
V_462 -> V_117 = V_45 ;
return V_462 ;
}
static inline struct V_224 * F_427 ( struct V_468 * V_225 )
{
return F_16 ( V_225 , struct V_224 , V_225 ) ;
}
static int F_428 ( struct V_115 * V_115 , struct V_468 * V_225 )
{
struct V_224 * V_116 = F_427 ( V_225 ) ;
if ( ! F_169 ( F_429 () , V_228 ) ||
! F_169 ( V_116 -> V_227 , V_228 ) )
return - V_229 ;
if ( V_116 == V_115 -> V_116 )
return 0 ;
F_168 ( V_116 ) ;
F_170 ( V_115 -> V_116 ) ;
V_115 -> V_116 = V_116 ;
return 0 ;
}
static struct V_468 * F_430 ( struct V_55 * V_56 )
{
struct V_224 * V_225 = NULL ;
struct V_115 * V_115 ;
F_431 ( V_56 ) ;
V_115 = V_56 -> V_115 ;
if ( V_115 ) {
V_225 = V_115 -> V_116 ;
F_168 ( V_225 ) ;
}
F_432 ( V_56 ) ;
return V_225 ? & V_225 -> V_225 : NULL ;
}
static void F_433 ( struct V_468 * V_225 )
{
F_170 ( F_427 ( V_225 ) ) ;
}
static struct V_460 * F_434 ( struct V_468 * V_225 )
{
return F_427 ( V_225 ) -> V_227 ;
}
static T_9 int F_435 ( void )
{
return 0 ;
}
int F_436 ( struct V_5 * V_6 , struct V_469 * V_470 ,
enum V_471 type , bool V_472 )
{
struct V_5 * V_21 = F_15 ( V_6 ) ;
int V_14 ;
F_115 ( & V_31 ) ;
V_14 = F_437 ( V_6 , V_21 , V_470 , type , V_472 ) ;
F_99 ( & V_31 ) ;
return V_14 ;
}
static struct V_18 *
F_438 ( struct V_18 * V_19 )
{
struct V_18 * V_32 = F_76 ( sizeof( * V_32 ) , V_93 ) ;
if ( ! V_32 )
return F_171 ( - V_94 ) ;
return V_32 ;
}
static void F_439 ( struct V_18 * V_32 )
{
F_60 ( V_32 ) ;
}
static T_8 F_440 ( struct V_18 * V_32 ,
struct V_41 * V_42 )
{
return F_286 ( V_32 -> V_5 ) ;
}
static T_8 F_441 ( struct V_18 * V_32 ,
struct V_41 * V_42 )
{
return ( T_8 ) ( unsigned long ) V_114 -> V_66 ;
}
static T_8 F_442 ( struct V_18 * V_32 ,
struct V_41 * V_42 )
{
T_8 V_91 ;
F_25 () ;
V_91 = F_96 ( & F_104 ( V_114 ) -> V_70 ) ;
F_28 () ;
return V_91 ;
}
static int F_443 ( struct V_161 * V_169 , void * V_296 )
{
struct V_53 * V_54 ;
struct V_44 * V_45 ;
char * V_473 ;
V_473 = F_131 ( V_474 + 1 , V_93 ) ;
if ( ! V_473 )
return - V_94 ;
F_82 ( & V_46 ) ;
F_25 () ;
V_45 = F_332 ( V_114 -> V_66 ) ;
F_45 (link, &cset->cgrp_links, cgrp_link) {
struct V_5 * V_101 = V_54 -> V_6 ;
F_444 ( V_101 , V_473 , V_474 + 1 ) ;
F_233 ( V_169 , L_53 ,
V_101 -> V_7 -> V_108 , V_473 ) ;
}
F_28 () ;
F_83 ( & V_46 ) ;
F_60 ( V_473 ) ;
return 0 ;
}
static int F_445 ( struct V_161 * V_169 , void * V_296 )
{
struct V_18 * V_32 = F_229 ( V_169 ) ;
struct V_53 * V_54 ;
F_82 ( & V_46 ) ;
F_45 (link, &css->cgroup->cset_links, cset_link) {
struct V_44 * V_45 = V_54 -> V_45 ;
struct V_55 * V_56 ;
int V_91 = 0 ;
F_233 ( V_169 , L_54 , V_45 ) ;
F_45 (task, &cset->tasks, cg_list) {
if ( V_91 ++ > V_475 )
goto V_476;
F_233 ( V_169 , L_55 , F_328 ( V_56 ) ) ;
}
F_45 (task, &cset->mg_tasks, cg_list) {
if ( V_91 ++ > V_475 )
goto V_476;
F_233 ( V_169 , L_55 , F_328 ( V_56 ) ) ;
}
continue;
V_476:
F_136 ( V_169 , L_56 ) ;
}
F_83 ( & V_46 ) ;
return 0 ;
}
static T_8 F_446 ( struct V_18 * V_32 , struct V_41 * V_42 )
{
return ( ! F_251 ( V_32 -> V_5 ) &&
! F_296 ( & V_32 -> V_5 -> V_20 ) ) ;
}
