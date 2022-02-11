static bool F_1 ( int V_1 )
{
return F_2 ( V_2 [ V_1 ] ) ;
}
static bool F_3 ( const struct V_3 * V_4 )
{
return V_4 -> V_5 == & V_6 ;
}
static int F_4 ( struct V_7 * V_7 , void * V_8 , int V_9 , int V_10 ,
T_1 V_11 )
{
int V_12 ;
F_5 ( V_11 ) ;
F_6 ( & V_13 ) ;
V_12 = F_7 ( V_7 , V_8 , V_9 , V_10 , V_11 & ~ V_14 ) ;
F_8 ( & V_13 ) ;
F_9 () ;
return V_12 ;
}
static void * F_10 ( struct V_7 * V_7 , void * V_8 , int V_15 )
{
void * V_12 ;
F_6 ( & V_13 ) ;
V_12 = F_11 ( V_7 , V_8 , V_15 ) ;
F_8 ( & V_13 ) ;
return V_12 ;
}
static void F_12 ( struct V_7 * V_7 , int V_15 )
{
F_6 ( & V_13 ) ;
F_13 ( V_7 , V_15 ) ;
F_8 ( & V_13 ) ;
}
static struct V_3 * F_14 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = V_4 -> V_18 . V_19 ;
if ( V_17 )
return F_15 ( V_17 , struct V_3 , V_18 ) ;
return NULL ;
}
static struct V_16 * F_16 ( struct V_3 * V_4 ,
struct V_20 * V_21 )
{
if ( V_21 )
return F_17 ( V_4 -> V_22 [ V_21 -> V_15 ] ,
F_18 ( & V_23 ) ) ;
else
return & V_4 -> V_18 ;
}
static struct V_16 * F_19 ( struct V_3 * V_4 ,
struct V_20 * V_21 )
{
F_20 ( & V_23 ) ;
if ( ! V_21 )
return & V_4 -> V_18 ;
if ( ! ( V_4 -> V_5 -> V_24 & ( 1 << V_21 -> V_15 ) ) )
return NULL ;
while ( F_14 ( V_4 ) &&
! ( F_14 ( V_4 ) -> V_25 & ( 1 << V_21 -> V_15 ) ) )
V_4 = F_14 ( V_4 ) ;
return F_16 ( V_4 , V_21 ) ;
}
struct V_16 * F_21 ( struct V_3 * V_4 ,
struct V_20 * V_21 )
{
struct V_16 * V_26 ;
F_22 () ;
do {
V_26 = F_16 ( V_4 , V_21 ) ;
if ( V_26 && F_23 ( V_26 ) )
goto V_27;
V_4 = F_14 ( V_4 ) ;
} while ( V_4 );
V_26 = V_28 . V_22 [ V_21 -> V_15 ] ;
F_24 ( V_26 ) ;
V_27:
F_25 () ;
return V_26 ;
}
static inline bool F_26 ( const struct V_3 * V_4 )
{
return ! ( V_4 -> V_18 . V_29 & V_30 ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
F_28 ( F_26 ( V_4 ) ) ;
F_24 ( & V_4 -> V_18 ) ;
}
static bool F_29 ( struct V_3 * V_4 )
{
return F_30 ( & V_4 -> V_18 ) ;
}
struct V_16 * F_31 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = V_32 -> V_33 -> V_19 -> V_34 ;
struct V_35 * V_36 = F_32 ( V_32 ) ;
if ( V_36 -> V_21 )
return F_33 ( V_4 -> V_22 [ V_36 -> V_21 -> V_15 ] ) ;
else
return & V_4 -> V_18 ;
}
static int F_34 ( const struct V_3 * V_4 )
{
return F_35 ( V_37 , & V_4 -> V_29 ) ;
}
static bool F_36 ( struct V_38 * V_39 )
{
F_20 ( & V_40 ) ;
return ! F_37 ( & V_39 -> V_41 ) || ! F_37 ( & V_39 -> V_42 ) ;
}
static void F_38 ( struct V_3 * V_4 , bool V_43 )
{
F_20 ( & V_40 ) ;
do {
bool V_44 ;
if ( V_43 )
V_44 = ! V_4 -> V_45 ++ ;
else
V_44 = ! -- V_4 -> V_45 ;
if ( ! V_44 )
break;
F_39 ( V_4 ) ;
F_40 ( & V_4 -> V_46 ) ;
V_4 = F_14 ( V_4 ) ;
} while ( V_4 );
}
static void F_41 ( struct V_38 * V_39 , bool V_43 )
{
struct V_47 * V_48 ;
F_20 ( & V_40 ) ;
F_42 (link, &cset->cgrp_links, cgrp_link)
F_38 ( V_48 -> V_4 , V_43 ) ;
}
static void F_43 ( struct V_49 * V_50 ,
struct V_38 * V_51 , struct V_38 * V_52 ,
bool V_53 )
{
F_20 ( & V_40 ) ;
if ( V_51 ) {
struct V_54 * V_55 , * V_56 ;
F_28 ( F_37 ( & V_50 -> V_57 ) ) ;
F_44 (it, pos, &from_cset->task_iters,
iters_node)
if ( V_55 -> V_58 == & V_50 -> V_57 )
F_45 ( V_55 ) ;
F_46 ( & V_50 -> V_57 ) ;
if ( ! F_36 ( V_51 ) )
F_41 ( V_51 , false ) ;
} else {
F_28 ( ! F_37 ( & V_50 -> V_57 ) ) ;
}
if ( V_52 ) {
F_28 ( V_50 -> V_29 & V_59 ) ;
if ( ! F_36 ( V_52 ) )
F_41 ( V_52 , true ) ;
F_47 ( V_50 -> V_60 , V_52 ) ;
F_48 ( & V_50 -> V_57 , V_53 ? & V_52 -> V_42 :
& V_52 -> V_41 ) ;
}
}
static unsigned long F_49 ( struct V_16 * V_26 [] )
{
unsigned long V_61 = 0UL ;
struct V_20 * V_21 ;
int V_62 ;
F_50 (ss, i)
V_61 += ( unsigned long ) V_26 [ V_62 ] ;
V_61 = ( V_61 >> 16 ) ^ V_61 ;
return V_61 ;
}
static void F_51 ( struct V_38 * V_39 )
{
struct V_47 * V_48 , * V_63 ;
struct V_20 * V_21 ;
int V_1 ;
F_20 ( & V_40 ) ;
if ( ! F_52 ( & V_39 -> V_64 ) )
return;
F_50 (ss, ssid) {
F_53 ( & V_39 -> V_65 [ V_1 ] ) ;
F_54 ( V_39 -> V_22 [ V_1 ] ) ;
}
F_55 ( & V_39 -> V_66 ) ;
V_67 -- ;
F_44 (link, tmp_link, &cset->cgrp_links, cgrp_link) {
F_53 ( & V_48 -> V_68 ) ;
F_53 ( & V_48 -> V_69 ) ;
if ( F_14 ( V_48 -> V_4 ) )
F_56 ( V_48 -> V_4 ) ;
F_57 ( V_48 ) ;
}
F_58 ( V_39 , V_70 ) ;
}
static void F_59 ( struct V_38 * V_39 )
{
if ( F_60 ( & V_39 -> V_64 , - 1 , 1 ) )
return;
F_6 ( & V_40 ) ;
F_51 ( V_39 ) ;
F_8 ( & V_40 ) ;
}
static inline void F_61 ( struct V_38 * V_39 )
{
F_62 ( & V_39 -> V_64 ) ;
}
static bool F_63 ( struct V_38 * V_39 ,
struct V_38 * V_71 ,
struct V_3 * V_72 ,
struct V_16 * V_73 [] )
{
struct V_74 * V_75 , * V_76 ;
if ( memcmp ( V_73 , V_39 -> V_22 , sizeof( V_39 -> V_22 ) ) )
return false ;
V_75 = & V_39 -> V_77 ;
V_76 = & V_71 -> V_77 ;
while ( 1 ) {
struct V_47 * V_78 , * V_79 ;
struct V_3 * V_80 , * V_81 ;
V_75 = V_75 -> V_82 ;
V_76 = V_76 -> V_82 ;
if ( V_75 == & V_39 -> V_77 ) {
F_64 ( V_76 != & V_71 -> V_77 ) ;
break;
} else {
F_64 ( V_76 == & V_71 -> V_77 ) ;
}
V_78 = F_65 ( V_75 , struct V_47 , V_69 ) ;
V_79 = F_65 ( V_76 , struct V_47 , V_69 ) ;
V_80 = V_78 -> V_4 ;
V_81 = V_79 -> V_4 ;
F_64 ( V_80 -> V_5 != V_81 -> V_5 ) ;
if ( V_80 -> V_5 == V_72 -> V_5 ) {
if ( V_80 != V_72 )
return false ;
} else {
if ( V_80 != V_81 )
return false ;
}
}
return true ;
}
static struct V_38 * F_66 ( struct V_38 * V_71 ,
struct V_3 * V_4 ,
struct V_16 * V_73 [] )
{
struct V_83 * V_5 = V_4 -> V_5 ;
struct V_20 * V_21 ;
struct V_38 * V_39 ;
unsigned long V_61 ;
int V_62 ;
F_50 (ss, i) {
if ( V_5 -> V_24 & ( 1UL << V_62 ) ) {
V_73 [ V_62 ] = F_19 ( V_4 , V_21 ) ;
} else {
V_73 [ V_62 ] = V_71 -> V_22 [ V_62 ] ;
}
}
V_61 = F_49 ( V_73 ) ;
F_67 (css_set_table, cset, hlist, key) {
if ( ! F_63 ( V_39 , V_71 , V_4 , V_73 ) )
continue;
return V_39 ;
}
return NULL ;
}
static void F_68 ( struct V_74 * V_84 )
{
struct V_47 * V_48 , * V_63 ;
F_44 (link, tmp_link, links_to_free, cset_link) {
F_53 ( & V_48 -> V_68 ) ;
F_57 ( V_48 ) ;
}
}
static int F_69 ( int V_85 , struct V_74 * V_86 )
{
struct V_47 * V_48 ;
int V_62 ;
F_70 ( V_86 ) ;
for ( V_62 = 0 ; V_62 < V_85 ; V_62 ++ ) {
V_48 = F_71 ( sizeof( * V_48 ) , V_87 ) ;
if ( ! V_48 ) {
F_68 ( V_86 ) ;
return - V_88 ;
}
F_72 ( & V_48 -> V_68 , V_86 ) ;
}
return 0 ;
}
static void F_73 ( struct V_74 * V_86 , struct V_38 * V_39 ,
struct V_3 * V_4 )
{
struct V_47 * V_48 ;
F_64 ( F_37 ( V_86 ) ) ;
if ( F_3 ( V_4 ) )
V_39 -> V_89 = V_4 ;
V_48 = F_74 ( V_86 , struct V_47 , V_68 ) ;
V_48 -> V_39 = V_39 ;
V_48 -> V_4 = V_4 ;
F_75 ( & V_48 -> V_68 , & V_4 -> V_90 ) ;
F_48 ( & V_48 -> V_69 , & V_39 -> V_77 ) ;
if ( F_14 ( V_4 ) )
F_27 ( V_4 ) ;
}
static struct V_38 * F_76 ( struct V_38 * V_71 ,
struct V_3 * V_4 )
{
struct V_16 * V_73 [ V_91 ] = { } ;
struct V_38 * V_39 ;
struct V_74 V_86 ;
struct V_47 * V_48 ;
struct V_20 * V_21 ;
unsigned long V_61 ;
int V_1 ;
F_20 ( & V_23 ) ;
F_6 ( & V_40 ) ;
V_39 = F_66 ( V_71 , V_4 , V_73 ) ;
if ( V_39 )
F_61 ( V_39 ) ;
F_8 ( & V_40 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_71 ( sizeof( * V_39 ) , V_87 ) ;
if ( ! V_39 )
return NULL ;
if ( F_69 ( V_92 , & V_86 ) < 0 ) {
F_57 ( V_39 ) ;
return NULL ;
}
F_77 ( & V_39 -> V_64 , 1 ) ;
F_70 ( & V_39 -> V_77 ) ;
F_70 ( & V_39 -> V_41 ) ;
F_70 ( & V_39 -> V_42 ) ;
F_70 ( & V_39 -> V_93 ) ;
F_70 ( & V_39 -> V_94 ) ;
F_70 ( & V_39 -> V_95 ) ;
F_78 ( & V_39 -> V_66 ) ;
memcpy ( V_39 -> V_22 , V_73 , sizeof( V_39 -> V_22 ) ) ;
F_6 ( & V_40 ) ;
F_42 (link, &old_cset->cgrp_links, cgrp_link) {
struct V_3 * V_96 = V_48 -> V_4 ;
if ( V_96 -> V_5 == V_4 -> V_5 )
V_96 = V_4 ;
F_73 ( & V_86 , V_39 , V_96 ) ;
}
F_64 ( ! F_37 ( & V_86 ) ) ;
V_67 ++ ;
V_61 = F_49 ( V_39 -> V_22 ) ;
F_79 ( V_97 , & V_39 -> V_66 , V_61 ) ;
F_50 (ss, ssid) {
struct V_16 * V_26 = V_39 -> V_22 [ V_1 ] ;
F_48 ( & V_39 -> V_65 [ V_1 ] ,
& V_26 -> V_3 -> V_98 [ V_1 ] ) ;
F_24 ( V_26 ) ;
}
F_8 ( & V_40 ) ;
return V_39 ;
}
static struct V_83 * F_80 ( struct V_99 * V_100 )
{
struct V_3 * V_101 = V_100 -> V_33 -> V_34 ;
return V_101 -> V_5 ;
}
static int F_81 ( struct V_83 * V_5 )
{
int V_15 ;
F_20 ( & V_23 ) ;
V_15 = F_82 ( & V_102 , V_5 , 0 , 0 , V_87 ) ;
if ( V_15 < 0 )
return V_15 ;
V_5 -> V_103 = V_15 ;
return 0 ;
}
static void F_83 ( struct V_83 * V_5 )
{
F_20 ( & V_23 ) ;
if ( V_5 -> V_103 ) {
F_13 ( & V_102 , V_5 -> V_103 ) ;
V_5 -> V_103 = 0 ;
}
}
static void F_84 ( struct V_83 * V_5 )
{
if ( V_5 ) {
F_28 ( V_5 -> V_103 ) ;
F_85 ( & V_5 -> V_104 ) ;
F_57 ( V_5 ) ;
}
}
static void F_86 ( struct V_83 * V_5 )
{
struct V_3 * V_4 = & V_5 -> V_4 ;
struct V_47 * V_48 , * V_63 ;
F_87 ( & V_23 ) ;
F_64 ( F_88 ( & V_5 -> V_105 ) ) ;
F_64 ( ! F_37 ( & V_4 -> V_18 . V_106 ) ) ;
F_89 ( & V_6 , V_5 -> V_24 ) ;
F_6 ( & V_40 ) ;
F_44 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_53 ( & V_48 -> V_68 ) ;
F_53 ( & V_48 -> V_69 ) ;
F_57 ( V_48 ) ;
}
F_8 ( & V_40 ) ;
if ( ! F_37 ( & V_5 -> V_107 ) ) {
F_53 ( & V_5 -> V_107 ) ;
V_92 -- ;
}
F_83 ( V_5 ) ;
F_90 ( & V_23 ) ;
F_91 ( V_5 -> V_100 ) ;
F_84 ( V_5 ) ;
}
static struct V_3 * F_92 ( struct V_38 * V_39 ,
struct V_83 * V_5 )
{
struct V_3 * V_108 = NULL ;
F_20 ( & V_23 ) ;
F_20 ( & V_40 ) ;
if ( V_39 == & V_28 ) {
V_108 = & V_5 -> V_4 ;
} else {
struct V_47 * V_48 ;
F_42 (link, &cset->cgrp_links, cgrp_link) {
struct V_3 * V_96 = V_48 -> V_4 ;
if ( V_96 -> V_5 == V_5 ) {
V_108 = V_96 ;
break;
}
}
}
F_64 ( ! V_108 ) ;
return V_108 ;
}
static struct V_3 * F_93 ( struct V_49 * V_50 ,
struct V_83 * V_5 )
{
return F_92 ( F_94 ( V_50 ) , V_5 ) ;
}
static char * F_95 ( struct V_3 * V_4 , const struct V_35 * V_36 ,
char * V_109 )
{
struct V_20 * V_21 = V_36 -> V_21 ;
if ( V_36 -> V_21 && ! ( V_36 -> V_29 & V_110 ) &&
! ( V_4 -> V_5 -> V_29 & V_111 ) )
snprintf ( V_109 , V_112 , L_1 ,
F_3 ( V_4 ) ? V_21 -> V_113 : V_21 -> V_114 ,
V_36 -> V_113 ) ;
else
strncpy ( V_109 , V_36 -> V_113 , V_112 ) ;
return V_109 ;
}
static T_2 F_96 ( const struct V_35 * V_36 )
{
T_2 V_115 = 0 ;
if ( V_36 -> V_116 || V_36 -> V_117 || V_36 -> V_118 )
V_115 |= V_119 ;
if ( V_36 -> V_120 || V_36 -> V_121 || V_36 -> V_122 ) {
if ( V_36 -> V_29 & V_123 )
V_115 |= V_124 ;
else
V_115 |= V_125 ;
}
return V_115 ;
}
static unsigned long F_97 ( struct V_3 * V_4 ,
unsigned long V_126 )
{
struct V_3 * V_19 = F_14 ( V_4 ) ;
unsigned long V_127 = V_126 ;
struct V_20 * V_21 ;
int V_1 ;
F_20 ( & V_23 ) ;
if ( ! F_3 ( V_4 ) )
return V_127 ;
while ( true ) {
unsigned long V_128 = V_127 ;
F_98 (ss, ssid, &cur_ss_mask)
V_128 |= V_21 -> V_129 ;
if ( V_19 )
V_128 &= V_19 -> V_25 ;
else
V_128 &= V_4 -> V_5 -> V_24 ;
if ( V_128 == V_127 )
break;
V_127 = V_128 ;
}
return V_127 ;
}
static void F_99 ( struct V_3 * V_4 )
{
V_4 -> V_25 =
F_97 ( V_4 , V_4 -> V_126 ) ;
}
static void F_100 ( struct V_130 * V_33 )
{
struct V_3 * V_4 ;
if ( F_101 ( V_33 ) == V_131 )
V_4 = V_33 -> V_34 ;
else
V_4 = V_33 -> V_19 -> V_34 ;
F_90 ( & V_23 ) ;
F_102 ( V_33 ) ;
F_56 ( V_4 ) ;
}
static struct V_3 * F_103 ( struct V_130 * V_33 )
{
struct V_3 * V_4 ;
if ( F_101 ( V_33 ) == V_131 )
V_4 = V_33 -> V_34 ;
else
V_4 = V_33 -> V_19 -> V_34 ;
if ( ! F_29 ( V_4 ) )
return NULL ;
F_104 ( V_33 ) ;
F_87 ( & V_23 ) ;
if ( ! F_26 ( V_4 ) )
return V_4 ;
F_100 ( V_33 ) ;
return NULL ;
}
static void F_105 ( struct V_3 * V_4 , const struct V_35 * V_36 )
{
char V_113 [ V_112 ] ;
F_20 ( & V_23 ) ;
if ( V_36 -> V_132 ) {
struct V_16 * V_26 = F_16 ( V_4 , V_36 -> V_21 ) ;
struct V_133 * V_134 = ( void * ) V_26 + V_36 -> V_132 ;
F_106 ( & V_135 ) ;
V_134 -> V_33 = NULL ;
F_107 ( & V_135 ) ;
}
F_108 ( V_4 -> V_33 , F_95 ( V_4 , V_36 , V_113 ) ) ;
}
static void F_109 ( struct V_16 * V_26 ,
struct V_3 * V_136 )
{
struct V_3 * V_4 = V_136 ? : V_26 -> V_3 ;
struct V_35 * V_137 ;
F_42 (cfts, &css->ss->cfts, node)
F_110 ( V_26 , V_4 , V_137 , false ) ;
}
static int F_111 ( struct V_16 * V_26 ,
struct V_3 * V_136 )
{
struct V_3 * V_4 = V_136 ? : V_26 -> V_3 ;
struct V_35 * V_137 , * V_138 ;
int V_12 ;
if ( ! V_26 -> V_21 ) {
if ( F_3 ( V_4 ) )
V_137 = V_139 ;
else
V_137 = V_140 ;
return F_110 ( & V_4 -> V_18 , V_4 , V_137 , true ) ;
}
F_42 (cfts, &css->ss->cfts, node) {
V_12 = F_110 ( V_26 , V_4 , V_137 , true ) ;
if ( V_12 < 0 ) {
V_138 = V_137 ;
goto V_141;
}
}
return 0 ;
V_141:
F_42 (cfts, &css->ss->cfts, node) {
if ( V_137 == V_138 )
break;
F_110 ( V_26 , V_4 , V_137 , false ) ;
}
return V_12 ;
}
static int F_89 ( struct V_83 * V_142 ,
unsigned long V_143 )
{
struct V_3 * V_144 = & V_142 -> V_4 ;
struct V_20 * V_21 ;
unsigned long V_145 ;
int V_1 , V_62 , V_12 ;
F_20 ( & V_23 ) ;
F_98 (ss, ssid, &ss_mask) {
if ( F_112 ( NULL , F_16 ( & V_21 -> V_5 -> V_4 , V_21 ) ) )
return - V_146 ;
if ( V_21 -> V_5 != & V_6 && V_142 != & V_6 )
return - V_146 ;
}
V_145 = V_143 ;
if ( V_142 == & V_6 )
V_145 &= ~ V_147 ;
F_98 (ss, ssid, &tmp_ss_mask) {
struct V_3 * V_148 = & V_21 -> V_5 -> V_4 ;
int V_149 ;
V_12 = F_111 ( F_16 ( V_148 , V_21 ) , V_144 ) ;
if ( ! V_12 )
continue;
if ( V_142 == & V_6 ) {
if ( V_150 ) {
F_113 ( L_2 ,
V_12 , V_143 ) ;
F_113 ( L_3 ) ;
}
continue;
}
F_98 (ss, tssid, &tmp_ss_mask) {
if ( V_149 == V_1 )
break;
F_109 ( F_16 ( V_148 , V_21 ) , V_144 ) ;
}
return V_12 ;
}
F_98 (ss, ssid, &ss_mask) {
struct V_83 * V_151 = V_21 -> V_5 ;
struct V_3 * V_148 = & V_151 -> V_4 ;
struct V_16 * V_26 = F_16 ( V_148 , V_21 ) ;
struct V_38 * V_39 ;
F_114 ( ! V_26 || F_16 ( V_144 , V_21 ) ) ;
F_109 ( V_26 , NULL ) ;
F_115 ( V_148 -> V_22 [ V_1 ] , NULL ) ;
F_47 ( V_144 -> V_22 [ V_1 ] , V_26 ) ;
V_21 -> V_5 = V_142 ;
V_26 -> V_3 = V_144 ;
F_6 ( & V_40 ) ;
F_116 (css_set_table, i, cset, hlist)
F_75 ( & V_39 -> V_65 [ V_21 -> V_15 ] ,
& V_144 -> V_98 [ V_21 -> V_15 ] ) ;
F_8 ( & V_40 ) ;
V_151 -> V_24 &= ~ ( 1 << V_1 ) ;
V_148 -> V_126 &= ~ ( 1 << V_1 ) ;
F_99 ( V_148 ) ;
V_142 -> V_24 |= 1 << V_1 ;
if ( V_142 == & V_6 ) {
F_117 ( V_152 [ V_1 ] ) ;
} else {
V_144 -> V_126 |= 1 << V_1 ;
F_99 ( V_144 ) ;
F_118 ( V_152 [ V_1 ] ) ;
}
if ( V_21 -> V_153 )
V_21 -> V_153 ( V_26 ) ;
}
F_119 ( V_144 -> V_33 ) ;
return 0 ;
}
static int F_120 ( struct V_154 * V_155 ,
struct V_99 * V_100 )
{
struct V_83 * V_5 = F_80 ( V_100 ) ;
struct V_20 * V_21 ;
int V_1 ;
if ( V_5 != & V_6 )
F_50 (ss, ssid)
if ( V_5 -> V_24 & ( 1 << V_1 ) )
F_121 ( V_155 , V_21 -> V_114 , NULL ) ;
if ( V_5 -> V_29 & V_111 )
F_122 ( V_155 , L_4 ) ;
if ( V_5 -> V_29 & V_156 )
F_122 ( V_155 , L_5 ) ;
F_123 ( & V_157 ) ;
if ( strlen ( V_5 -> V_158 ) )
F_121 ( V_155 , L_6 ,
V_5 -> V_158 ) ;
F_124 ( & V_157 ) ;
if ( F_35 ( V_159 , & V_5 -> V_4 . V_29 ) )
F_122 ( V_155 , L_7 ) ;
if ( strlen ( V_5 -> V_113 ) )
F_121 ( V_155 , L_8 , V_5 -> V_113 ) ;
return 0 ;
}
static int F_125 ( char * V_160 , struct V_161 * V_162 )
{
char * V_163 , * V_164 = V_160 ;
bool V_165 = false , V_166 = false ;
unsigned long V_167 = - 1UL ;
struct V_20 * V_21 ;
int V_168 = 0 ;
int V_62 ;
#ifdef F_126
V_167 = ~ ( 1U << V_169 ) ;
#endif
memset ( V_162 , 0 , sizeof( * V_162 ) ) ;
while ( ( V_163 = F_127 ( & V_164 , L_9 ) ) != NULL ) {
V_168 ++ ;
if ( ! * V_163 )
return - V_170 ;
if ( ! strcmp ( V_163 , L_10 ) ) {
V_162 -> V_171 = true ;
continue;
}
if ( ! strcmp ( V_163 , L_11 ) ) {
if ( V_166 )
return - V_170 ;
V_165 = true ;
continue;
}
if ( ! strcmp ( V_163 , L_12 ) ) {
V_162 -> V_29 |= V_111 ;
continue;
}
if ( ! strcmp ( V_163 , L_13 ) ) {
V_162 -> V_172 = true ;
continue;
}
if ( ! strcmp ( V_163 , L_14 ) ) {
V_162 -> V_29 |= V_156 ;
continue;
}
if ( ! strncmp ( V_163 , L_15 , 14 ) ) {
if ( V_162 -> V_173 )
return - V_170 ;
V_162 -> V_173 =
F_128 ( V_163 + 14 , V_174 - 1 , V_87 ) ;
if ( ! V_162 -> V_173 )
return - V_88 ;
continue;
}
if ( ! strncmp ( V_163 , L_16 , 5 ) ) {
const char * V_113 = V_163 + 5 ;
if ( ! strlen ( V_113 ) )
return - V_170 ;
for ( V_62 = 0 ; V_62 < strlen ( V_113 ) ; V_62 ++ ) {
char V_96 = V_113 [ V_62 ] ;
if ( isalnum ( V_96 ) )
continue;
if ( ( V_96 == '.' ) || ( V_96 == '-' ) || ( V_96 == '_' ) )
continue;
return - V_170 ;
}
if ( V_162 -> V_113 )
return - V_170 ;
V_162 -> V_113 = F_128 ( V_113 ,
V_175 - 1 ,
V_87 ) ;
if ( ! V_162 -> V_113 )
return - V_88 ;
continue;
}
F_50 (ss, i) {
if ( strcmp ( V_163 , V_21 -> V_114 ) )
continue;
if ( ! F_1 ( V_62 ) )
continue;
if ( V_165 )
return - V_170 ;
V_162 -> V_24 |= ( 1 << V_62 ) ;
V_166 = true ;
break;
}
if ( V_62 == V_91 )
return - V_176 ;
}
if ( V_165 || ( ! V_166 && ! V_162 -> V_171 && ! V_162 -> V_113 ) )
F_50 (ss, i)
if ( F_1 ( V_62 ) )
V_162 -> V_24 |= ( 1 << V_62 ) ;
if ( ! V_162 -> V_24 && ! V_162 -> V_113 )
return - V_170 ;
if ( ( V_162 -> V_29 & V_111 ) && ( V_162 -> V_24 & V_167 ) )
return - V_170 ;
if ( V_162 -> V_24 && V_162 -> V_171 )
return - V_170 ;
return 0 ;
}
static int F_129 ( struct V_99 * V_100 , int * V_29 , char * V_160 )
{
int V_12 = 0 ;
struct V_83 * V_5 = F_80 ( V_100 ) ;
struct V_161 V_162 ;
unsigned long V_177 , V_178 ;
if ( V_5 == & V_6 ) {
F_130 ( L_17 ) ;
return - V_170 ;
}
F_87 ( & V_23 ) ;
V_12 = F_125 ( V_160 , & V_162 ) ;
if ( V_12 )
goto V_27;
if ( V_162 . V_24 != V_5 -> V_24 || V_162 . V_173 )
F_113 ( L_18 ,
F_131 ( V_179 ) , V_179 -> V_180 ) ;
V_177 = V_162 . V_24 & ~ V_5 -> V_24 ;
V_178 = V_5 -> V_24 & ~ V_162 . V_24 ;
if ( ( V_162 . V_29 ^ V_5 -> V_29 ) ||
( V_162 . V_113 && strcmp ( V_162 . V_113 , V_5 -> V_113 ) ) ) {
F_130 ( L_19 ,
V_162 . V_29 , V_162 . V_113 ? : L_20 , V_5 -> V_29 , V_5 -> V_113 ) ;
V_12 = - V_170 ;
goto V_27;
}
if ( ! F_37 ( & V_5 -> V_4 . V_18 . V_106 ) ) {
V_12 = - V_146 ;
goto V_27;
}
V_12 = F_89 ( V_5 , V_177 ) ;
if ( V_12 )
goto V_27;
F_89 ( & V_6 , V_178 ) ;
if ( V_162 . V_173 ) {
F_123 ( & V_157 ) ;
strcpy ( V_5 -> V_158 , V_162 . V_173 ) ;
F_124 ( & V_157 ) ;
}
V_27:
F_57 ( V_162 . V_173 ) ;
F_57 ( V_162 . V_113 ) ;
F_90 ( & V_23 ) ;
return V_12 ;
}
static void F_132 ( void )
{
struct V_49 * V_181 , * V_182 ;
F_6 ( & V_40 ) ;
if ( V_183 )
goto V_27;
V_183 = true ;
F_133 ( & V_184 ) ;
F_134 (g, p) {
F_28 ( ! F_37 ( & V_181 -> V_57 ) ||
F_94 ( V_181 ) != & V_28 ) ;
F_106 ( & V_181 -> V_185 -> V_186 ) ;
if ( ! ( V_181 -> V_29 & V_59 ) ) {
struct V_38 * V_39 = F_94 ( V_181 ) ;
if ( ! F_36 ( V_39 ) )
F_41 ( V_39 , true ) ;
F_48 ( & V_181 -> V_57 , & V_39 -> V_41 ) ;
F_61 ( V_39 ) ;
}
F_107 ( & V_181 -> V_185 -> V_186 ) ;
} F_135 ( V_182 , V_181 ) ;
F_136 ( & V_184 ) ;
V_27:
F_8 ( & V_40 ) ;
}
static void F_137 ( struct V_3 * V_4 )
{
struct V_20 * V_21 ;
int V_1 ;
F_70 ( & V_4 -> V_18 . V_187 ) ;
F_70 ( & V_4 -> V_18 . V_106 ) ;
F_70 ( & V_4 -> V_90 ) ;
F_70 ( & V_4 -> V_188 ) ;
F_138 ( & V_4 -> V_189 ) ;
V_4 -> V_18 . V_3 = V_4 ;
V_4 -> V_18 . V_29 |= V_30 ;
F_50 (ss, ssid)
F_70 ( & V_4 -> V_98 [ V_1 ] ) ;
F_139 ( & V_4 -> V_190 ) ;
F_140 ( & V_4 -> V_191 , V_192 ) ;
}
static void F_141 ( struct V_83 * V_5 ,
struct V_161 * V_162 )
{
struct V_3 * V_4 = & V_5 -> V_4 ;
F_70 ( & V_5 -> V_107 ) ;
F_77 ( & V_5 -> V_105 , 1 ) ;
V_4 -> V_5 = V_5 ;
F_137 ( V_4 ) ;
F_142 ( & V_5 -> V_104 ) ;
V_5 -> V_29 = V_162 -> V_29 ;
if ( V_162 -> V_173 )
strcpy ( V_5 -> V_158 , V_162 -> V_173 ) ;
if ( V_162 -> V_113 )
strcpy ( V_5 -> V_113 , V_162 -> V_113 ) ;
if ( V_162 -> V_172 )
F_143 ( V_159 , & V_5 -> V_4 . V_29 ) ;
}
static int F_144 ( struct V_83 * V_5 , unsigned long V_143 )
{
F_145 ( V_86 ) ;
struct V_3 * V_101 = & V_5 -> V_4 ;
struct V_38 * V_39 ;
int V_62 , V_12 ;
F_20 ( & V_23 ) ;
V_12 = F_4 ( & V_5 -> V_104 , V_101 , 1 , 2 , V_87 ) ;
if ( V_12 < 0 )
goto V_193;
V_101 -> V_15 = V_12 ;
V_101 -> V_194 [ 0 ] = V_12 ;
V_12 = F_146 ( & V_101 -> V_18 . V_195 , V_196 , 0 ,
V_87 ) ;
if ( V_12 )
goto V_193;
V_12 = F_69 ( V_67 , & V_86 ) ;
if ( V_12 )
goto V_197;
V_12 = F_81 ( V_5 ) ;
if ( V_12 )
goto V_197;
V_5 -> V_100 = F_147 ( & V_198 ,
V_199 ,
V_101 ) ;
if ( F_148 ( V_5 -> V_100 ) ) {
V_12 = F_149 ( V_5 -> V_100 ) ;
goto V_200;
}
V_101 -> V_33 = V_5 -> V_100 -> V_33 ;
V_12 = F_111 ( & V_101 -> V_18 , NULL ) ;
if ( V_12 )
goto V_201;
V_12 = F_89 ( V_5 , V_143 ) ;
if ( V_12 )
goto V_201;
F_72 ( & V_5 -> V_107 , & V_202 ) ;
V_92 ++ ;
F_6 ( & V_40 ) ;
F_116 (css_set_table, i, cset, hlist) {
F_73 ( & V_86 , V_39 , V_101 ) ;
if ( F_36 ( V_39 ) )
F_38 ( V_101 , true ) ;
}
F_8 ( & V_40 ) ;
F_64 ( ! F_37 ( & V_101 -> V_18 . V_106 ) ) ;
F_64 ( F_88 ( & V_5 -> V_105 ) != 1 ) ;
F_119 ( V_101 -> V_33 ) ;
V_12 = 0 ;
goto V_193;
V_201:
F_91 ( V_5 -> V_100 ) ;
V_5 -> V_100 = NULL ;
V_200:
F_83 ( V_5 ) ;
V_197:
F_150 ( & V_101 -> V_18 . V_195 ) ;
V_193:
F_68 ( & V_86 ) ;
return V_12 ;
}
static struct V_203 * F_151 ( struct V_204 * V_205 ,
int V_29 , const char * V_206 ,
void * V_160 )
{
bool V_207 = V_205 == & V_208 ;
struct V_209 * V_210 = NULL ;
struct V_20 * V_21 ;
struct V_83 * V_5 ;
struct V_161 V_162 ;
struct V_203 * V_203 ;
int V_12 ;
int V_62 ;
bool V_211 ;
if ( ! V_183 )
F_132 () ;
if ( V_207 ) {
if ( V_160 ) {
F_130 ( L_21 , ( char * ) V_160 ) ;
return F_152 ( - V_170 ) ;
}
V_150 = true ;
V_5 = & V_6 ;
F_27 ( & V_5 -> V_4 ) ;
goto V_212;
}
F_87 ( & V_23 ) ;
V_12 = F_125 ( V_160 , & V_162 ) ;
if ( V_12 )
goto V_27;
F_50 (ss, i) {
if ( ! ( V_162 . V_24 & ( 1 << V_62 ) ) ||
V_21 -> V_5 == & V_6 )
continue;
if ( ! F_153 ( & V_21 -> V_5 -> V_4 . V_18 . V_195 ) ) {
F_90 ( & V_23 ) ;
F_154 ( 10 ) ;
V_12 = F_155 () ;
goto V_213;
}
F_56 ( & V_21 -> V_5 -> V_4 ) ;
}
F_156 (root) {
bool V_214 = false ;
if ( V_5 == & V_6 )
continue;
if ( V_162 . V_113 ) {
if ( strcmp ( V_162 . V_113 , V_5 -> V_113 ) )
continue;
V_214 = true ;
}
if ( ( V_162 . V_24 || V_162 . V_171 ) &&
( V_162 . V_24 != V_5 -> V_24 ) ) {
if ( ! V_214 )
continue;
V_12 = - V_146 ;
goto V_27;
}
if ( V_5 -> V_29 ^ V_162 . V_29 )
F_113 ( L_22 ) ;
V_210 = F_157 ( V_5 -> V_100 , NULL ) ;
if ( F_148 ( V_210 ) ||
! F_153 ( & V_5 -> V_4 . V_18 . V_195 ) ) {
F_90 ( & V_23 ) ;
if ( ! F_158 ( V_210 ) )
F_159 ( V_210 ) ;
F_154 ( 10 ) ;
V_12 = F_155 () ;
goto V_213;
}
V_12 = 0 ;
goto V_27;
}
if ( ! V_162 . V_24 && ! V_162 . V_171 ) {
V_12 = - V_170 ;
goto V_27;
}
V_5 = F_71 ( sizeof( * V_5 ) , V_87 ) ;
if ( ! V_5 ) {
V_12 = - V_88 ;
goto V_27;
}
F_141 ( V_5 , & V_162 ) ;
V_12 = F_144 ( V_5 , V_162 . V_24 ) ;
if ( V_12 )
F_84 ( V_5 ) ;
V_27:
F_90 ( & V_23 ) ;
V_213:
F_57 ( V_162 . V_173 ) ;
F_57 ( V_162 . V_113 ) ;
if ( V_12 )
return F_152 ( V_12 ) ;
V_212:
V_203 = F_160 ( V_205 , V_29 , V_5 -> V_100 ,
V_207 ? V_215 : V_216 ,
& V_211 ) ;
if ( F_148 ( V_203 ) || ! V_211 )
F_56 ( & V_5 -> V_4 ) ;
if ( V_210 ) {
F_114 ( V_211 ) ;
F_159 ( V_210 ) ;
}
return V_203 ;
}
static void F_161 ( struct V_209 * V_217 )
{
struct V_99 * V_100 = F_162 ( V_217 ) ;
struct V_83 * V_5 = F_80 ( V_100 ) ;
if ( ! F_37 ( & V_5 -> V_4 . V_18 . V_106 ) ||
V_5 == & V_6 )
F_56 ( & V_5 -> V_4 ) ;
else
F_163 ( & V_5 -> V_4 . V_18 . V_195 ) ;
F_164 ( V_217 ) ;
}
char * F_165 ( struct V_49 * V_50 , char * V_109 , T_3 V_218 )
{
struct V_83 * V_5 ;
struct V_3 * V_4 ;
int V_103 = 1 ;
char * V_219 = NULL ;
F_87 ( & V_23 ) ;
F_6 ( & V_40 ) ;
V_5 = F_166 ( & V_102 , & V_103 ) ;
if ( V_5 ) {
V_4 = F_93 ( V_50 , V_5 ) ;
V_219 = F_167 ( V_4 , V_109 , V_218 ) ;
} else {
if ( F_168 ( V_109 , L_23 , V_218 ) < V_218 )
V_219 = V_109 ;
}
F_8 ( & V_40 ) ;
F_90 ( & V_23 ) ;
return V_219 ;
}
static void F_169 ( struct V_49 * V_50 ,
struct V_220 * V_221 )
{
struct V_38 * V_39 ;
F_20 ( & V_40 ) ;
if ( V_50 -> V_29 & V_59 )
return;
if ( F_37 ( & V_50 -> V_57 ) )
return;
V_39 = F_94 ( V_50 ) ;
if ( ! V_39 -> V_222 )
return;
F_75 ( & V_50 -> V_57 , & V_39 -> V_42 ) ;
if ( F_37 ( & V_39 -> V_94 ) )
F_48 ( & V_39 -> V_94 , & V_221 -> V_223 ) ;
if ( F_37 ( & V_39 -> V_224 -> V_94 ) )
F_75 ( & V_39 -> V_224 -> V_94 ,
& V_221 -> V_225 ) ;
}
struct V_49 * F_170 ( struct V_220 * V_221 ,
struct V_16 * * V_226 )
{
V_221 -> V_227 = F_74 ( V_221 -> V_228 , struct V_38 , V_94 ) ;
V_221 -> V_229 = NULL ;
return F_171 ( V_221 , V_226 ) ;
}
struct V_49 * F_171 ( struct V_220 * V_221 ,
struct V_16 * * V_226 )
{
struct V_38 * V_39 = V_221 -> V_227 ;
struct V_49 * V_50 = V_221 -> V_229 ;
while ( & V_39 -> V_94 != V_221 -> V_228 ) {
if ( ! V_50 )
V_50 = F_74 ( & V_39 -> V_42 ,
struct V_49 , V_57 ) ;
else
V_50 = F_172 ( V_50 , V_57 ) ;
if ( & V_50 -> V_57 != & V_39 -> V_42 ) {
V_221 -> V_227 = V_39 ;
V_221 -> V_229 = V_50 ;
if ( V_39 -> V_224 )
* V_226 = V_39 -> V_224 -> V_22 [ V_221 -> V_1 ] ;
else
* V_226 = V_39 -> V_22 [ V_221 -> V_1 ] ;
return V_50 ;
}
V_39 = F_172 ( V_39 , V_94 ) ;
V_50 = NULL ;
}
return NULL ;
}
static int F_173 ( struct V_220 * V_221 ,
struct V_3 * V_230 )
{
struct V_16 * V_26 , * V_231 = NULL ;
struct V_49 * V_50 , * V_232 ;
struct V_38 * V_39 , * V_233 ;
int V_62 , V_12 ;
if ( F_37 ( & V_221 -> V_223 ) )
return 0 ;
F_174 (css, i, dst_cgrp) {
if ( V_26 -> V_21 -> V_234 ) {
V_221 -> V_1 = V_62 ;
V_12 = V_26 -> V_21 -> V_234 ( V_221 ) ;
if ( V_12 ) {
V_231 = V_26 ;
goto V_235;
}
}
}
F_6 ( & V_40 ) ;
F_42 (cset, &tset->src_csets, mg_node) {
F_44 (task, tmp_task, &cset->mg_tasks, cg_list) {
struct V_38 * V_51 = F_94 ( V_50 ) ;
struct V_38 * V_52 = V_39 -> V_224 ;
F_61 ( V_52 ) ;
F_43 ( V_50 , V_51 , V_52 , true ) ;
F_51 ( V_51 ) ;
}
}
F_8 ( & V_40 ) ;
V_221 -> V_228 = & V_221 -> V_225 ;
F_174 (css, i, dst_cgrp) {
if ( V_26 -> V_21 -> V_236 ) {
V_221 -> V_1 = V_62 ;
V_26 -> V_21 -> V_236 ( V_221 ) ;
}
}
V_12 = 0 ;
goto V_237;
V_235:
F_174 (css, i, dst_cgrp) {
if ( V_26 == V_231 )
break;
if ( V_26 -> V_21 -> V_238 ) {
V_221 -> V_1 = V_62 ;
V_26 -> V_21 -> V_238 ( V_221 ) ;
}
}
V_237:
F_6 ( & V_40 ) ;
F_175 ( & V_221 -> V_225 , & V_221 -> V_223 ) ;
F_44 (cset, tmp_cset, &tset->src_csets, mg_node) {
F_176 ( & V_39 -> V_42 , & V_39 -> V_41 ) ;
F_46 ( & V_39 -> V_94 ) ;
}
F_8 ( & V_40 ) ;
return V_12 ;
}
static void F_177 ( struct V_74 * V_239 )
{
struct V_38 * V_39 , * V_233 ;
F_20 ( & V_23 ) ;
F_6 ( & V_40 ) ;
F_44 (cset, tmp_cset, preloaded_csets, mg_preload_node) {
V_39 -> V_222 = NULL ;
V_39 -> V_224 = NULL ;
F_46 ( & V_39 -> V_93 ) ;
F_51 ( V_39 ) ;
}
F_8 ( & V_40 ) ;
}
static void F_178 ( struct V_38 * V_240 ,
struct V_3 * V_230 ,
struct V_74 * V_239 )
{
struct V_3 * V_241 ;
F_20 ( & V_23 ) ;
F_20 ( & V_40 ) ;
V_241 = F_92 ( V_240 , V_230 -> V_5 ) ;
if ( ! F_37 ( & V_240 -> V_93 ) )
return;
F_114 ( V_240 -> V_222 ) ;
F_114 ( ! F_37 ( & V_240 -> V_42 ) ) ;
F_114 ( ! F_37 ( & V_240 -> V_94 ) ) ;
V_240 -> V_222 = V_241 ;
F_61 ( V_240 ) ;
F_72 ( & V_240 -> V_93 , V_239 ) ;
}
static int F_179 ( struct V_3 * V_230 ,
struct V_74 * V_239 )
{
F_145 ( V_228 ) ;
struct V_38 * V_240 , * V_233 ;
F_20 ( & V_23 ) ;
if ( V_230 && F_3 ( V_230 ) && F_14 ( V_230 ) &&
V_230 -> V_25 )
return - V_146 ;
F_44 (src_cset, tmp_cset, preloaded_csets, mg_preload_node) {
struct V_38 * V_242 ;
V_242 = F_76 ( V_240 ,
V_230 ? : V_240 -> V_89 ) ;
if ( ! V_242 )
goto V_141;
F_28 ( V_240 -> V_224 || V_242 -> V_224 ) ;
if ( V_240 == V_242 ) {
V_240 -> V_222 = NULL ;
F_46 ( & V_240 -> V_93 ) ;
F_59 ( V_240 ) ;
F_59 ( V_242 ) ;
continue;
}
V_240 -> V_224 = V_242 ;
if ( F_37 ( & V_242 -> V_93 ) )
F_72 ( & V_242 -> V_93 , & V_228 ) ;
else
F_59 ( V_242 ) ;
}
F_180 ( & V_228 , V_239 ) ;
return 0 ;
V_141:
F_177 ( & V_228 ) ;
return - V_88 ;
}
static int F_181 ( struct V_49 * V_243 , bool V_244 ,
struct V_3 * V_4 )
{
struct V_220 V_221 = F_182 ( V_221 ) ;
struct V_49 * V_50 ;
F_6 ( & V_40 ) ;
F_22 () ;
V_50 = V_243 ;
do {
F_169 ( V_50 , & V_221 ) ;
if ( ! V_244 )
break;
} while_each_thread(leader, task) ;
int F_183 ( struct V_3 * V_230 ,
struct V_49 * V_243 , bool V_244 )
{
F_145 ( V_239 ) ;
struct V_49 * V_50 ;
int V_12 ;
F_6 ( & V_40 ) ;
F_22 () ;
V_50 = V_243 ;
do {
F_178 ( F_94 ( V_50 ) , V_230 ,
& V_239 ) ;
if ( ! V_244 )
break;
} while_each_thread(leader, task) ;
int F_184 ( struct V_49 * V_50 ,
struct V_3 * V_230 ,
struct V_31 * V_32 )
{
const struct V_245 * V_245 = F_185 () ;
const struct V_245 * V_246 = F_186 ( V_50 ) ;
int V_12 = 0 ;
if ( ! F_187 ( V_245 -> V_247 , V_248 ) &&
! F_187 ( V_245 -> V_247 , V_246 -> V_249 ) &&
! F_187 ( V_245 -> V_247 , V_246 -> V_250 ) )
V_12 = - V_251 ;
if ( ! V_12 && F_3 ( V_230 ) ) {
struct V_209 * V_217 = V_32 -> V_252 -> V_253 . V_203 -> V_254 ;
struct V_3 * V_4 ;
struct V_255 * V_255 ;
F_6 ( & V_40 ) ;
V_4 = F_93 ( V_50 , & V_6 ) ;
F_8 ( & V_40 ) ;
while ( ! F_188 ( V_230 , V_4 ) )
V_4 = F_14 ( V_4 ) ;
V_12 = - V_88 ;
V_255 = F_189 ( V_217 , V_4 -> V_256 . V_33 ) ;
if ( V_255 ) {
V_12 = F_190 ( V_255 , V_257 ) ;
F_191 ( V_255 ) ;
}
}
F_192 ( V_246 ) ;
return V_12 ;
}
static T_4 F_193 ( struct V_31 * V_32 , char * V_109 ,
T_3 V_258 , T_5 V_259 , bool V_244 )
{
struct V_49 * V_260 ;
struct V_3 * V_4 ;
T_6 V_261 ;
int V_12 ;
if ( F_194 ( F_195 ( V_109 ) , 0 , & V_261 ) || V_261 < 0 )
return - V_170 ;
V_4 = F_103 ( V_32 -> V_33 ) ;
if ( ! V_4 )
return - V_262 ;
F_196 ( & V_263 ) ;
F_22 () ;
if ( V_261 ) {
V_260 = F_197 ( V_261 ) ;
if ( ! V_260 ) {
V_12 = - V_264 ;
goto V_265;
}
} else {
V_260 = V_179 ;
}
if ( V_244 )
V_260 = V_260 -> V_266 ;
if ( V_260 == V_267 || ( V_260 -> V_29 & V_268 ) ) {
V_12 = - V_170 ;
goto V_265;
}
F_198 ( V_260 ) ;
F_25 () ;
V_12 = F_184 ( V_260 , V_4 , V_32 ) ;
if ( ! V_12 )
V_12 = F_183 ( V_4 , V_260 , V_244 ) ;
F_199 ( V_260 ) ;
goto V_269;
V_265:
F_25 () ;
V_269:
F_200 ( & V_263 ) ;
F_100 ( V_32 -> V_33 ) ;
F_201 () ;
return V_12 ? : V_258 ;
}
int F_202 ( struct V_49 * V_270 , struct V_49 * V_260 )
{
struct V_83 * V_5 ;
int V_271 = 0 ;
F_87 ( & V_23 ) ;
F_156 (root) {
struct V_3 * V_272 ;
if ( V_5 == & V_6 )
continue;
F_6 ( & V_40 ) ;
V_272 = F_93 ( V_270 , V_5 ) ;
F_8 ( & V_40 ) ;
V_271 = F_183 ( V_272 , V_260 , false ) ;
if ( V_271 )
break;
}
F_90 ( & V_23 ) ;
return V_271 ;
}
static T_4 F_203 ( struct V_31 * V_32 ,
char * V_109 , T_3 V_258 , T_5 V_259 )
{
return F_193 ( V_32 , V_109 , V_258 , V_259 , false ) ;
}
static T_4 F_204 ( struct V_31 * V_32 ,
char * V_109 , T_3 V_258 , T_5 V_259 )
{
return F_193 ( V_32 , V_109 , V_258 , V_259 , true ) ;
}
static T_4 F_205 ( struct V_31 * V_32 ,
char * V_109 , T_3 V_258 , T_5 V_259 )
{
struct V_3 * V_4 ;
F_206 ( sizeof( V_4 -> V_5 -> V_158 ) < V_174 ) ;
V_4 = F_103 ( V_32 -> V_33 ) ;
if ( ! V_4 )
return - V_262 ;
F_123 ( & V_157 ) ;
F_168 ( V_4 -> V_5 -> V_158 , F_195 ( V_109 ) ,
sizeof( V_4 -> V_5 -> V_158 ) ) ;
F_124 ( & V_157 ) ;
F_100 ( V_32 -> V_33 ) ;
return V_258 ;
}
static int F_207 ( struct V_154 * V_155 , void * V_273 )
{
struct V_3 * V_4 = F_208 ( V_155 ) -> V_3 ;
F_123 ( & V_157 ) ;
F_122 ( V_155 , V_4 -> V_5 -> V_158 ) ;
F_124 ( & V_157 ) ;
F_209 ( V_155 , '\n' ) ;
return 0 ;
}
static int F_210 ( struct V_154 * V_155 , void * V_273 )
{
F_122 ( V_155 , L_24 ) ;
return 0 ;
}
static void F_211 ( struct V_154 * V_155 , unsigned long V_143 )
{
struct V_20 * V_21 ;
bool V_274 = false ;
int V_1 ;
F_98 (ss, ssid, &ss_mask) {
if ( V_274 )
F_209 ( V_155 , ' ' ) ;
F_212 ( V_155 , L_25 , V_21 -> V_113 ) ;
V_274 = true ;
}
if ( V_274 )
F_209 ( V_155 , '\n' ) ;
}
static int F_213 ( struct V_154 * V_155 , void * V_273 )
{
struct V_3 * V_4 = F_208 ( V_155 ) -> V_3 ;
F_211 ( V_155 , V_4 -> V_5 -> V_24 &
~ V_147 ) ;
return 0 ;
}
static int F_214 ( struct V_154 * V_155 , void * V_273 )
{
struct V_3 * V_4 = F_208 ( V_155 ) -> V_3 ;
F_211 ( V_155 , F_14 ( V_4 ) -> V_126 ) ;
return 0 ;
}
static int F_215 ( struct V_154 * V_155 , void * V_273 )
{
struct V_3 * V_4 = F_208 ( V_155 ) -> V_3 ;
F_211 ( V_155 , V_4 -> V_126 ) ;
return 0 ;
}
static int F_216 ( struct V_3 * V_4 )
{
F_145 ( V_239 ) ;
struct V_220 V_221 = F_182 ( V_221 ) ;
struct V_16 * V_26 ;
struct V_38 * V_240 ;
int V_12 ;
F_20 ( & V_23 ) ;
F_196 ( & V_263 ) ;
F_6 ( & V_40 ) ;
F_217 (css, cgroup_css(cgrp, NULL)) {
struct V_47 * V_48 ;
if ( V_26 -> V_3 == V_4 )
continue;
F_42 (link, &css->cgroup->cset_links, cset_link)
F_178 ( V_48 -> V_39 , V_4 ,
& V_239 ) ;
}
F_8 ( & V_40 ) ;
V_12 = F_179 ( NULL , & V_239 ) ;
if ( V_12 )
goto V_275;
F_6 ( & V_40 ) ;
F_42 (src_cset, &preloaded_csets, mg_preload_node) {
struct V_49 * V_50 , * V_276 ;
if ( ! V_240 -> V_222 )
break;
F_44 (task, ntask, &src_cset->tasks, cg_list)
F_169 ( V_50 , & V_221 ) ;
}
F_8 ( & V_40 ) ;
V_12 = F_173 ( & V_221 , V_4 ) ;
V_275:
F_177 ( & V_239 ) ;
F_200 ( & V_263 ) ;
return V_12 ;
}
static T_4 F_218 ( struct V_31 * V_32 ,
char * V_109 , T_3 V_258 ,
T_5 V_259 )
{
unsigned long V_277 = 0 , V_278 = 0 ;
unsigned long V_279 , V_280 , V_281 , V_282 , V_283 , V_284 ;
struct V_3 * V_4 , * V_285 ;
struct V_20 * V_21 ;
char * V_286 ;
int V_1 , V_12 ;
V_109 = F_195 ( V_109 ) ;
while ( ( V_286 = F_127 ( & V_109 , L_26 ) ) ) {
unsigned long V_145 = ~ V_147 ;
if ( V_286 [ 0 ] == '\0' )
continue;
F_98 (ss, ssid, &tmp_ss_mask) {
if ( ! F_1 ( V_1 ) ||
strcmp ( V_286 + 1 , V_21 -> V_113 ) )
continue;
if ( * V_286 == '+' ) {
V_277 |= 1 << V_1 ;
V_278 &= ~ ( 1 << V_1 ) ;
} else if ( * V_286 == '-' ) {
V_278 |= 1 << V_1 ;
V_277 &= ~ ( 1 << V_1 ) ;
} else {
return - V_170 ;
}
break;
}
if ( V_1 == V_91 )
return - V_170 ;
}
V_4 = F_103 ( V_32 -> V_33 ) ;
if ( ! V_4 )
return - V_262 ;
F_50 (ss, ssid) {
if ( V_277 & ( 1 << V_1 ) ) {
if ( V_4 -> V_126 & ( 1 << V_1 ) ) {
V_277 &= ~ ( 1 << V_1 ) ;
continue;
}
if ( ! ( V_6 . V_24 & ( 1 << V_1 ) ) ||
( F_14 ( V_4 ) &&
! ( F_14 ( V_4 ) -> V_126 & ( 1 << V_1 ) ) ) ) {
V_12 = - V_176 ;
goto V_27;
}
} else if ( V_278 & ( 1 << V_1 ) ) {
if ( ! ( V_4 -> V_126 & ( 1 << V_1 ) ) ) {
V_278 &= ~ ( 1 << V_1 ) ;
continue;
}
F_219 (child, cgrp) {
if ( V_285 -> V_126 & ( 1 << V_1 ) ) {
V_12 = - V_146 ;
goto V_27;
}
}
}
}
if ( ! V_277 && ! V_278 ) {
V_12 = 0 ;
goto V_27;
}
if ( V_277 && F_14 ( V_4 ) && ! F_37 ( & V_4 -> V_90 ) ) {
V_12 = - V_146 ;
goto V_27;
}
V_281 = V_4 -> V_126 ;
V_283 = V_4 -> V_25 ;
V_282 = ( V_281 | V_277 ) & ~ V_278 ;
V_284 = F_97 ( V_4 , V_282 ) ;
V_279 = ~ V_283 & V_284 ;
V_280 = V_283 & ~ V_284 ;
V_277 |= V_279 ;
V_278 |= V_280 ;
F_98 (ss, ssid, &css_enable) {
F_219 (child, cgrp) {
F_220 ( V_287 ) ;
if ( ! F_16 ( V_285 , V_21 ) )
continue;
F_27 ( V_285 ) ;
F_221 ( & V_285 -> V_190 , & V_287 ,
V_288 ) ;
F_100 ( V_32 -> V_33 ) ;
F_222 () ;
F_223 ( & V_285 -> V_190 , & V_287 ) ;
F_56 ( V_285 ) ;
return F_155 () ;
}
}
V_4 -> V_126 = V_282 ;
V_4 -> V_25 = V_284 ;
F_50 (ss, ssid) {
if ( ! ( V_277 & ( 1 << V_1 ) ) )
continue;
F_219 (child, cgrp) {
if ( V_279 & ( 1 << V_1 ) )
V_12 = F_224 ( V_285 , V_21 ,
V_4 -> V_126 & ( 1 << V_1 ) ) ;
else
V_12 = F_111 ( F_16 ( V_285 , V_21 ) ,
NULL ) ;
if ( V_12 )
goto V_289;
}
}
V_12 = F_216 ( V_4 ) ;
if ( V_12 )
goto V_289;
F_50 (ss, ssid) {
if ( ! ( V_278 & ( 1 << V_1 ) ) )
continue;
F_219 (child, cgrp) {
struct V_16 * V_26 = F_16 ( V_285 , V_21 ) ;
if ( V_280 & ( 1 << V_1 ) ) {
F_225 ( V_26 ) ;
} else {
F_109 ( V_26 , NULL ) ;
if ( V_21 -> V_290 )
V_21 -> V_290 ( V_26 ) ;
}
}
}
F_50 (ss, ssid) {
struct V_16 * V_291 = F_16 ( V_4 , V_21 ) ;
struct V_16 * V_26 ;
if ( ! V_21 -> V_292 || ! V_291 )
continue;
F_217 (css, this_css)
if ( V_26 != V_291 )
V_21 -> V_292 ( V_26 ) ;
}
F_119 ( V_4 -> V_33 ) ;
V_12 = 0 ;
V_27:
F_100 ( V_32 -> V_33 ) ;
return V_12 ? : V_258 ;
V_289:
V_4 -> V_126 = V_281 ;
V_4 -> V_25 = V_283 ;
F_50 (ss, ssid) {
if ( ! ( V_277 & ( 1 << V_1 ) ) )
continue;
F_219 (child, cgrp) {
struct V_16 * V_26 = F_16 ( V_285 , V_21 ) ;
if ( ! V_26 )
continue;
if ( V_279 & ( 1 << V_1 ) )
F_225 ( V_26 ) ;
else
F_109 ( V_26 , NULL ) ;
}
}
goto V_27;
}
static int F_226 ( struct V_154 * V_155 , void * V_273 )
{
F_212 ( V_155 , L_27 ,
F_227 ( F_208 ( V_155 ) -> V_3 ) ) ;
return 0 ;
}
static T_4 F_228 ( struct V_31 * V_32 , char * V_109 ,
T_3 V_258 , T_5 V_259 )
{
struct V_3 * V_4 = V_32 -> V_33 -> V_19 -> V_34 ;
struct V_35 * V_36 = V_32 -> V_33 -> V_34 ;
struct V_16 * V_26 ;
int V_12 ;
if ( V_36 -> V_122 )
return V_36 -> V_122 ( V_32 , V_109 , V_258 , V_259 ) ;
F_22 () ;
V_26 = F_16 ( V_4 , V_36 -> V_21 ) ;
F_25 () ;
if ( V_36 -> V_120 ) {
unsigned long long V_273 ;
V_12 = F_229 ( V_109 , 0 , & V_273 ) ;
if ( ! V_12 )
V_12 = V_36 -> V_120 ( V_26 , V_36 , V_273 ) ;
} else if ( V_36 -> V_121 ) {
long long V_273 ;
V_12 = F_230 ( V_109 , 0 , & V_273 ) ;
if ( ! V_12 )
V_12 = V_36 -> V_121 ( V_26 , V_36 , V_273 ) ;
} else {
V_12 = - V_170 ;
}
return V_12 ? : V_258 ;
}
static void * F_231 ( struct V_154 * V_155 , T_5 * V_293 )
{
return F_232 ( V_155 ) -> F_233 ( V_155 , V_293 ) ;
}
static void * F_234 ( struct V_154 * V_155 , void * V_273 , T_5 * V_293 )
{
return F_232 ( V_155 ) -> F_235 ( V_155 , V_273 , V_293 ) ;
}
static void F_236 ( struct V_154 * V_155 , void * V_273 )
{
F_232 ( V_155 ) -> F_237 ( V_155 , V_273 ) ;
}
static int F_238 ( struct V_154 * V_294 , void * V_295 )
{
struct V_35 * V_36 = F_232 ( V_294 ) ;
struct V_16 * V_26 = F_208 ( V_294 ) ;
if ( V_36 -> V_118 )
return V_36 -> V_118 ( V_294 , V_295 ) ;
if ( V_36 -> V_116 )
F_212 ( V_294 , L_28 , V_36 -> V_116 ( V_26 , V_36 ) ) ;
else if ( V_36 -> V_117 )
F_212 ( V_294 , L_29 , V_36 -> V_117 ( V_26 , V_36 ) ) ;
else
return - V_170 ;
return 0 ;
}
static int F_239 ( struct V_130 * V_33 , struct V_130 * V_296 ,
const char * V_297 )
{
struct V_3 * V_4 = V_33 -> V_34 ;
int V_12 ;
if ( F_101 ( V_33 ) != V_131 )
return - V_298 ;
if ( V_33 -> V_19 != V_296 )
return - V_299 ;
if ( F_3 ( V_4 ) )
return - V_300 ;
F_104 ( V_296 ) ;
F_104 ( V_33 ) ;
F_87 ( & V_23 ) ;
V_12 = F_240 ( V_33 , V_296 , V_297 ) ;
F_90 ( & V_23 ) ;
F_102 ( V_33 ) ;
F_102 ( V_296 ) ;
return V_12 ;
}
static int F_241 ( struct V_130 * V_33 )
{
struct V_301 V_301 = { . V_302 = V_303 | V_304 ,
. V_305 = F_242 () ,
. V_306 = F_243 () , } ;
if ( F_187 ( V_301 . V_305 , V_248 ) &&
F_244 ( V_301 . V_306 , V_307 ) )
return 0 ;
return F_245 ( V_33 , & V_301 ) ;
}
static int F_246 ( struct V_16 * V_26 , struct V_3 * V_4 ,
struct V_35 * V_36 )
{
char V_113 [ V_112 ] ;
struct V_130 * V_33 ;
struct V_308 * V_61 = NULL ;
int V_12 ;
#ifdef F_247
V_61 = & V_36 -> V_309 ;
#endif
V_33 = F_248 ( V_4 -> V_33 , F_95 ( V_4 , V_36 , V_113 ) ,
F_96 ( V_36 ) , 0 , V_36 -> V_310 , V_36 ,
NULL , V_61 ) ;
if ( F_148 ( V_33 ) )
return F_149 ( V_33 ) ;
V_12 = F_241 ( V_33 ) ;
if ( V_12 ) {
F_249 ( V_33 ) ;
return V_12 ;
}
if ( V_36 -> V_132 ) {
struct V_133 * V_134 = ( void * ) V_26 + V_36 -> V_132 ;
F_106 ( & V_135 ) ;
V_134 -> V_33 = V_33 ;
F_107 ( & V_135 ) ;
}
return 0 ;
}
static int F_110 ( struct V_16 * V_26 ,
struct V_3 * V_4 , struct V_35 V_137 [] ,
bool V_311 )
{
struct V_35 * V_36 , * V_312 = NULL ;
int V_12 ;
F_20 ( & V_23 ) ;
V_313:
for ( V_36 = V_137 ; V_36 != V_312 && V_36 -> V_113 [ 0 ] != '\0' ; V_36 ++ ) {
if ( ( V_36 -> V_29 & V_314 ) && ! F_3 ( V_4 ) )
continue;
if ( ( V_36 -> V_29 & V_315 ) && F_3 ( V_4 ) )
continue;
if ( ( V_36 -> V_29 & V_316 ) && ! F_14 ( V_4 ) )
continue;
if ( ( V_36 -> V_29 & V_317 ) && F_14 ( V_4 ) )
continue;
if ( V_311 ) {
V_12 = F_246 ( V_26 , V_4 , V_36 ) ;
if ( V_12 ) {
F_113 ( L_30 ,
V_318 , V_36 -> V_113 , V_12 ) ;
V_312 = V_36 ;
V_311 = false ;
goto V_313;
}
} else {
F_105 ( V_4 , V_36 ) ;
}
}
return 0 ;
}
static int F_250 ( struct V_35 * V_137 , bool V_311 )
{
F_145 ( V_319 ) ;
struct V_20 * V_21 = V_137 [ 0 ] . V_21 ;
struct V_3 * V_5 = & V_21 -> V_5 -> V_4 ;
struct V_16 * V_26 ;
int V_12 = 0 ;
F_20 ( & V_23 ) ;
F_217 (css, cgroup_css(root, ss)) {
struct V_3 * V_4 = V_26 -> V_3 ;
if ( F_26 ( V_4 ) )
continue;
V_12 = F_110 ( V_26 , V_4 , V_137 , V_311 ) ;
if ( V_12 )
break;
}
if ( V_311 && ! V_12 )
F_119 ( V_5 -> V_33 ) ;
return V_12 ;
}
static void F_251 ( struct V_35 * V_137 )
{
struct V_35 * V_36 ;
for ( V_36 = V_137 ; V_36 -> V_113 [ 0 ] != '\0' ; V_36 ++ ) {
if ( V_36 -> V_320 && V_36 -> V_320 != V_321 )
F_57 ( V_36 -> V_310 ) ;
V_36 -> V_310 = NULL ;
V_36 -> V_21 = NULL ;
V_36 -> V_29 &= ~ ( V_314 | V_315 ) ;
}
}
static int F_252 ( struct V_20 * V_21 , struct V_35 * V_137 )
{
struct V_35 * V_36 ;
for ( V_36 = V_137 ; V_36 -> V_113 [ 0 ] != '\0' ; V_36 ++ ) {
struct V_322 * V_310 ;
F_114 ( V_36 -> V_21 || V_36 -> V_310 ) ;
if ( V_36 -> F_233 )
V_310 = & V_323 ;
else
V_310 = & V_324 ;
if ( V_36 -> V_320 && V_36 -> V_320 != V_321 ) {
V_310 = F_253 ( V_310 , sizeof( * V_310 ) , V_87 ) ;
if ( ! V_310 ) {
F_251 ( V_137 ) ;
return - V_88 ;
}
V_310 -> V_325 = V_36 -> V_320 ;
}
V_36 -> V_310 = V_310 ;
V_36 -> V_21 = V_21 ;
}
return 0 ;
}
static int F_254 ( struct V_35 * V_137 )
{
F_20 ( & V_23 ) ;
if ( ! V_137 || ! V_137 [ 0 ] . V_21 )
return - V_176 ;
F_53 ( & V_137 -> V_326 ) ;
F_250 ( V_137 , false ) ;
F_251 ( V_137 ) ;
return 0 ;
}
int F_255 ( struct V_35 * V_137 )
{
int V_12 ;
F_87 ( & V_23 ) ;
V_12 = F_254 ( V_137 ) ;
F_90 ( & V_23 ) ;
return V_12 ;
}
static int F_256 ( struct V_20 * V_21 , struct V_35 * V_137 )
{
int V_12 ;
if ( ! F_1 ( V_21 -> V_15 ) )
return 0 ;
if ( ! V_137 || V_137 [ 0 ] . V_113 [ 0 ] == '\0' )
return 0 ;
V_12 = F_252 ( V_21 , V_137 ) ;
if ( V_12 )
return V_12 ;
F_87 ( & V_23 ) ;
F_48 ( & V_137 -> V_326 , & V_21 -> V_137 ) ;
V_12 = F_250 ( V_137 , true ) ;
if ( V_12 )
F_254 ( V_137 ) ;
F_90 ( & V_23 ) ;
return V_12 ;
}
int F_257 ( struct V_20 * V_21 , struct V_35 * V_137 )
{
struct V_35 * V_36 ;
for ( V_36 = V_137 ; V_36 && V_36 -> V_113 [ 0 ] != '\0' ; V_36 ++ )
V_36 -> V_29 |= V_314 ;
return F_256 ( V_21 , V_137 ) ;
}
int F_258 ( struct V_20 * V_21 , struct V_35 * V_137 )
{
struct V_35 * V_36 ;
for ( V_36 = V_137 ; V_36 && V_36 -> V_113 [ 0 ] != '\0' ; V_36 ++ )
V_36 -> V_29 |= V_315 ;
return F_256 ( V_21 , V_137 ) ;
}
void F_40 ( struct V_133 * V_134 )
{
unsigned long V_29 ;
F_259 ( & V_135 , V_29 ) ;
if ( V_134 -> V_33 )
F_260 ( V_134 -> V_33 ) ;
F_261 ( & V_135 , V_29 ) ;
}
static int F_262 ( const struct V_3 * V_4 )
{
int V_85 = 0 ;
struct V_47 * V_48 ;
F_6 ( & V_40 ) ;
F_42 (link, &cgrp->cset_links, cset_link)
V_85 += F_88 ( & V_48 -> V_39 -> V_64 ) ;
F_8 ( & V_40 ) ;
return V_85 ;
}
struct V_16 * F_112 ( struct V_16 * V_56 ,
struct V_16 * V_19 )
{
struct V_16 * V_82 ;
F_263 () ;
if ( ! V_56 ) {
V_82 = F_264 ( V_19 -> V_106 . V_82 , struct V_16 , V_187 ) ;
} else if ( F_265 ( ! ( V_56 -> V_29 & V_327 ) ) ) {
V_82 = F_264 ( V_56 -> V_187 . V_82 , struct V_16 , V_187 ) ;
} else {
F_266 (next, &parent->children, sibling)
if ( V_82 -> V_328 > V_56 -> V_328 )
break;
}
if ( & V_82 -> V_187 != & V_19 -> V_106 )
return V_82 ;
return NULL ;
}
struct V_16 *
F_267 ( struct V_16 * V_56 ,
struct V_16 * V_5 )
{
struct V_16 * V_82 ;
F_263 () ;
if ( ! V_56 )
return V_5 ;
V_82 = F_112 ( NULL , V_56 ) ;
if ( V_82 )
return V_82 ;
while ( V_56 != V_5 ) {
V_82 = F_112 ( V_56 , V_56 -> V_19 ) ;
if ( V_82 )
return V_82 ;
V_56 = V_56 -> V_19 ;
}
return NULL ;
}
struct V_16 *
F_268 ( struct V_16 * V_56 )
{
struct V_16 * V_329 , * V_330 ;
F_263 () ;
do {
V_329 = V_56 ;
V_56 = NULL ;
F_269 (tmp, last)
V_56 = V_330 ;
} while ( V_56 );
return V_329 ;
}
static struct V_16 *
F_270 ( struct V_16 * V_56 )
{
struct V_16 * V_329 ;
do {
V_329 = V_56 ;
V_56 = F_112 ( NULL , V_56 ) ;
} while ( V_56 );
return V_329 ;
}
struct V_16 *
F_271 ( struct V_16 * V_56 ,
struct V_16 * V_5 )
{
struct V_16 * V_82 ;
F_263 () ;
if ( ! V_56 )
return F_270 ( V_5 ) ;
if ( V_56 == V_5 )
return NULL ;
V_82 = F_112 ( V_56 , V_56 -> V_19 ) ;
if ( V_82 )
return F_270 ( V_82 ) ;
return V_56 -> V_19 ;
}
bool F_272 ( struct V_16 * V_26 )
{
struct V_16 * V_285 ;
bool V_12 = false ;
F_22 () ;
F_269 (child, css) {
if ( V_285 -> V_29 & V_30 ) {
V_12 = true ;
break;
}
}
F_25 () ;
return V_12 ;
}
static void F_273 ( struct V_54 * V_55 )
{
struct V_74 * V_331 = V_55 -> V_332 ;
struct V_47 * V_48 ;
struct V_38 * V_39 ;
F_20 ( & V_40 ) ;
do {
V_331 = V_331 -> V_82 ;
if ( V_331 == V_55 -> V_333 ) {
V_55 -> V_332 = NULL ;
V_55 -> V_58 = NULL ;
return;
}
if ( V_55 -> V_21 ) {
V_39 = F_15 ( V_331 , struct V_38 ,
V_65 [ V_55 -> V_21 -> V_15 ] ) ;
} else {
V_48 = F_65 ( V_331 , struct V_47 , V_68 ) ;
V_39 = V_48 -> V_39 ;
}
} while ( ! F_36 ( V_39 ) );
V_55 -> V_332 = V_331 ;
if ( ! F_37 ( & V_39 -> V_41 ) )
V_55 -> V_58 = V_39 -> V_41 . V_82 ;
else
V_55 -> V_58 = V_39 -> V_42 . V_82 ;
V_55 -> V_334 = & V_39 -> V_41 ;
V_55 -> V_335 = & V_39 -> V_42 ;
if ( V_55 -> V_227 ) {
F_53 ( & V_55 -> V_336 ) ;
F_51 ( V_55 -> V_227 ) ;
}
F_61 ( V_39 ) ;
V_55 -> V_227 = V_39 ;
F_72 ( & V_55 -> V_336 , & V_39 -> V_95 ) ;
}
static void F_45 ( struct V_54 * V_55 )
{
struct V_74 * V_331 = V_55 -> V_58 ;
F_20 ( & V_40 ) ;
F_28 ( ! V_331 ) ;
V_331 = V_331 -> V_82 ;
if ( V_331 == V_55 -> V_334 )
V_331 = V_55 -> V_335 -> V_82 ;
if ( V_331 == V_55 -> V_335 )
F_273 ( V_55 ) ;
else
V_55 -> V_58 = V_331 ;
}
void F_274 ( struct V_16 * V_26 ,
struct V_54 * V_55 )
{
F_28 ( ! V_183 ) ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
F_6 ( & V_40 ) ;
V_55 -> V_21 = V_26 -> V_21 ;
if ( V_55 -> V_21 )
V_55 -> V_332 = & V_26 -> V_3 -> V_98 [ V_26 -> V_21 -> V_15 ] ;
else
V_55 -> V_332 = & V_26 -> V_3 -> V_90 ;
V_55 -> V_333 = V_55 -> V_332 ;
F_273 ( V_55 ) ;
F_8 ( & V_40 ) ;
}
struct V_49 * F_275 ( struct V_54 * V_55 )
{
if ( V_55 -> V_229 ) {
F_199 ( V_55 -> V_229 ) ;
V_55 -> V_229 = NULL ;
}
F_6 ( & V_40 ) ;
if ( V_55 -> V_58 ) {
V_55 -> V_229 = F_65 ( V_55 -> V_58 , struct V_49 ,
V_57 ) ;
F_198 ( V_55 -> V_229 ) ;
F_45 ( V_55 ) ;
}
F_8 ( & V_40 ) ;
return V_55 -> V_229 ;
}
void F_276 ( struct V_54 * V_55 )
{
if ( V_55 -> V_227 ) {
F_6 ( & V_40 ) ;
F_53 ( & V_55 -> V_336 ) ;
F_51 ( V_55 -> V_227 ) ;
F_8 ( & V_40 ) ;
}
if ( V_55 -> V_229 )
F_199 ( V_55 -> V_229 ) ;
}
int F_277 ( struct V_3 * V_337 , struct V_3 * V_270 )
{
F_145 ( V_239 ) ;
struct V_47 * V_48 ;
struct V_54 V_55 ;
struct V_49 * V_50 ;
int V_12 ;
F_87 ( & V_23 ) ;
F_6 ( & V_40 ) ;
F_42 (link, &from->cset_links, cset_link)
F_178 ( V_48 -> V_39 , V_337 , & V_239 ) ;
F_8 ( & V_40 ) ;
V_12 = F_179 ( V_337 , & V_239 ) ;
if ( V_12 )
goto V_338;
do {
F_274 ( & V_270 -> V_18 , & V_55 ) ;
V_50 = F_275 ( & V_55 ) ;
if ( V_50 )
F_198 ( V_50 ) ;
F_276 ( & V_55 ) ;
if ( V_50 ) {
V_12 = F_181 ( V_50 , false , V_337 ) ;
F_199 ( V_50 ) ;
}
} while ( V_50 && ! V_12 );
V_338:
F_177 ( & V_239 ) ;
F_90 ( & V_23 ) ;
return V_12 ;
}
static void * F_278 ( int V_85 )
{
if ( F_279 ( V_85 ) )
return F_280 ( V_85 * sizeof( T_6 ) ) ;
else
return F_281 ( V_85 * sizeof( T_6 ) , V_87 ) ;
}
static void F_282 ( void * V_181 )
{
F_283 ( V_181 ) ;
}
static void F_284 ( struct V_3 * V_4 )
{
struct V_339 * V_331 , * V_340 ;
F_87 ( & V_4 -> V_189 ) ;
F_44 (l, tmp_l, &cgrp->pidlists, links)
F_285 ( V_341 , & V_331 -> V_342 , 0 ) ;
F_90 ( & V_4 -> V_189 ) ;
F_286 ( V_341 ) ;
F_64 ( ! F_37 ( & V_4 -> V_188 ) ) ;
}
static void F_287 ( struct V_343 * V_344 )
{
struct V_345 * V_346 = F_288 ( V_344 ) ;
struct V_339 * V_331 = F_15 ( V_346 , struct V_339 ,
V_342 ) ;
struct V_339 * V_347 = NULL ;
F_87 ( & V_331 -> V_348 -> V_189 ) ;
if ( ! F_289 ( V_346 ) ) {
F_53 ( & V_331 -> V_349 ) ;
F_282 ( V_331 -> V_350 ) ;
F_290 ( V_331 -> V_61 . V_351 ) ;
V_347 = V_331 ;
}
F_90 ( & V_331 -> V_348 -> V_189 ) ;
F_57 ( V_347 ) ;
}
static int F_291 ( T_6 * V_350 , int V_352 )
{
int V_353 , V_354 = 1 ;
if ( V_352 == 0 || V_352 == 1 )
return V_352 ;
for ( V_353 = 1 ; V_353 < V_352 ; V_353 ++ ) {
while ( V_350 [ V_353 ] == V_350 [ V_353 - 1 ] ) {
V_353 ++ ;
if ( V_353 == V_352 )
goto V_355;
}
V_350 [ V_354 ] = V_350 [ V_353 ] ;
V_354 ++ ;
}
V_355:
return V_354 ;
}
static T_6 F_292 ( T_6 V_261 )
{
unsigned V_356 = V_261 & 0x55555555 ;
unsigned V_357 = V_261 & 0xAAAAAAAA ;
return ( V_356 << 1 ) | ( V_357 >> 1 ) ;
}
static T_6 F_293 ( struct V_3 * V_4 , T_6 V_261 )
{
if ( F_3 ( V_4 ) )
return F_292 ( V_261 ) ;
else
return V_261 ;
}
static int F_294 ( const void * V_356 , const void * V_357 )
{
return * ( T_6 * ) V_356 - * ( T_6 * ) V_357 ;
}
static int F_295 ( const void * V_356 , const void * V_357 )
{
return F_292 ( * ( T_6 * ) V_356 ) - F_292 ( * ( T_6 * ) V_357 ) ;
}
static struct V_339 * F_296 ( struct V_3 * V_4 ,
enum V_358 type )
{
struct V_339 * V_331 ;
struct V_359 * V_351 = F_297 ( V_179 ) ;
F_20 ( & V_4 -> V_189 ) ;
F_42 (l, &cgrp->pidlists, links)
if ( V_331 -> V_61 . type == type && V_331 -> V_61 . V_351 == V_351 )
return V_331 ;
return NULL ;
}
static struct V_339 * F_298 ( struct V_3 * V_4 ,
enum V_358 type )
{
struct V_339 * V_331 ;
F_20 ( & V_4 -> V_189 ) ;
V_331 = F_296 ( V_4 , type ) ;
if ( V_331 )
return V_331 ;
V_331 = F_71 ( sizeof( struct V_339 ) , V_87 ) ;
if ( ! V_331 )
return V_331 ;
F_299 ( & V_331 -> V_342 , F_287 ) ;
V_331 -> V_61 . type = type ;
V_331 -> V_61 . V_351 = F_300 ( F_297 ( V_179 ) ) ;
V_331 -> V_348 = V_4 ;
F_72 ( & V_331 -> V_349 , & V_4 -> V_188 ) ;
return V_331 ;
}
static int F_301 ( struct V_3 * V_4 , enum V_358 type ,
struct V_339 * * V_360 )
{
T_6 * V_361 ;
int V_352 ;
int V_261 , V_362 = 0 ;
struct V_54 V_55 ;
struct V_49 * V_260 ;
struct V_339 * V_331 ;
F_20 ( & V_4 -> V_189 ) ;
V_352 = F_262 ( V_4 ) ;
V_361 = F_278 ( V_352 ) ;
if ( ! V_361 )
return - V_88 ;
F_274 ( & V_4 -> V_18 , & V_55 ) ;
while ( ( V_260 = F_275 ( & V_55 ) ) ) {
if ( F_302 ( V_362 == V_352 ) )
break;
if ( type == V_363 )
V_261 = F_303 ( V_260 ) ;
else
V_261 = F_304 ( V_260 ) ;
if ( V_261 > 0 )
V_361 [ V_362 ++ ] = V_261 ;
}
F_276 ( & V_55 ) ;
V_352 = V_362 ;
if ( F_3 ( V_4 ) )
F_305 ( V_361 , V_352 , sizeof( T_6 ) , F_295 , NULL ) ;
else
F_305 ( V_361 , V_352 , sizeof( T_6 ) , F_294 , NULL ) ;
if ( type == V_363 )
V_352 = F_291 ( V_361 , V_352 ) ;
V_331 = F_298 ( V_4 , type ) ;
if ( ! V_331 ) {
F_282 ( V_361 ) ;
return - V_88 ;
}
F_282 ( V_331 -> V_350 ) ;
V_331 -> V_350 = V_361 ;
V_331 -> V_352 = V_352 ;
* V_360 = V_331 ;
return 0 ;
}
int F_306 ( struct V_364 * V_365 , struct V_203 * V_203 )
{
struct V_130 * V_33 = F_307 ( V_203 ) ;
struct V_3 * V_4 ;
struct V_54 V_55 ;
struct V_49 * V_260 ;
if ( V_203 -> V_254 -> V_366 != & V_367 || ! V_33 ||
F_101 ( V_33 ) != V_131 )
return - V_170 ;
F_87 ( & V_23 ) ;
F_22 () ;
V_4 = F_308 ( V_33 -> V_34 ) ;
if ( ! V_4 || F_26 ( V_4 ) ) {
F_25 () ;
F_90 ( & V_23 ) ;
return - V_176 ;
}
F_25 () ;
F_274 ( & V_4 -> V_18 , & V_55 ) ;
while ( ( V_260 = F_275 ( & V_55 ) ) ) {
switch ( V_260 -> V_368 ) {
case V_369 :
V_365 -> V_370 ++ ;
break;
case V_371 :
V_365 -> V_372 ++ ;
break;
case V_288 :
V_365 -> V_373 ++ ;
break;
case V_374 :
V_365 -> V_375 ++ ;
break;
default:
if ( F_309 ( V_260 ) )
V_365 -> V_376 ++ ;
break;
}
}
F_276 ( & V_55 ) ;
F_90 ( & V_23 ) ;
return 0 ;
}
static void * F_310 ( struct V_154 * V_377 , T_5 * V_56 )
{
struct V_31 * V_32 = V_377 -> V_378 ;
struct V_3 * V_4 = F_208 ( V_377 ) -> V_3 ;
struct V_339 * V_331 ;
enum V_358 type = F_232 ( V_377 ) -> V_378 ;
int V_379 = 0 , V_261 = * V_56 ;
int * V_380 , V_12 ;
F_87 ( & V_4 -> V_189 ) ;
if ( V_32 -> V_34 )
V_32 -> V_34 = F_296 ( V_4 , type ) ;
if ( ! V_32 -> V_34 ) {
V_12 = F_301 ( V_4 , type ,
(struct V_339 * * ) & V_32 -> V_34 ) ;
if ( V_12 )
return F_152 ( V_12 ) ;
}
V_331 = V_32 -> V_34 ;
if ( V_261 ) {
int V_10 = V_331 -> V_352 ;
while ( V_379 < V_10 ) {
int V_381 = ( V_379 + V_10 ) / 2 ;
if ( F_293 ( V_4 , V_331 -> V_350 [ V_381 ] ) == V_261 ) {
V_379 = V_381 ;
break;
} else if ( F_293 ( V_4 , V_331 -> V_350 [ V_381 ] ) <= V_261 )
V_379 = V_381 + 1 ;
else
V_10 = V_381 ;
}
}
if ( V_379 >= V_331 -> V_352 )
return NULL ;
V_380 = V_331 -> V_350 + V_379 ;
* V_56 = F_293 ( V_4 , * V_380 ) ;
return V_380 ;
}
static void F_311 ( struct V_154 * V_377 , void * V_273 )
{
struct V_31 * V_32 = V_377 -> V_378 ;
struct V_339 * V_331 = V_32 -> V_34 ;
if ( V_331 )
F_285 ( V_341 , & V_331 -> V_342 ,
V_382 ) ;
F_90 ( & F_208 ( V_377 ) -> V_3 -> V_189 ) ;
}
static void * F_312 ( struct V_154 * V_377 , void * V_273 , T_5 * V_56 )
{
struct V_31 * V_32 = V_377 -> V_378 ;
struct V_339 * V_331 = V_32 -> V_34 ;
T_6 * V_181 = V_273 ;
T_6 * V_10 = V_331 -> V_350 + V_331 -> V_352 ;
V_181 ++ ;
if ( V_181 >= V_10 ) {
return NULL ;
} else {
* V_56 = F_293 ( F_208 ( V_377 ) -> V_3 , * V_181 ) ;
return V_181 ;
}
}
static int F_313 ( struct V_154 * V_377 , void * V_273 )
{
F_212 ( V_377 , L_31 , * ( int * ) V_273 ) ;
return 0 ;
}
static T_7 F_314 ( struct V_16 * V_26 ,
struct V_35 * V_36 )
{
return F_34 ( V_26 -> V_3 ) ;
}
static int F_315 ( struct V_16 * V_26 ,
struct V_35 * V_36 , T_7 V_383 )
{
if ( V_383 )
F_143 ( V_37 , & V_26 -> V_3 -> V_29 ) ;
else
F_316 ( V_37 , & V_26 -> V_3 -> V_29 ) ;
return 0 ;
}
static T_7 F_317 ( struct V_16 * V_26 ,
struct V_35 * V_36 )
{
return F_35 ( V_159 , & V_26 -> V_3 -> V_29 ) ;
}
static int F_318 ( struct V_16 * V_26 ,
struct V_35 * V_36 , T_7 V_383 )
{
if ( V_383 )
F_143 ( V_159 , & V_26 -> V_3 -> V_29 ) ;
else
F_316 ( V_159 , & V_26 -> V_3 -> V_29 ) ;
return 0 ;
}
static void F_319 ( struct V_343 * V_344 )
{
struct V_16 * V_26 =
F_15 ( V_344 , struct V_16 , V_384 ) ;
struct V_20 * V_21 = V_26 -> V_21 ;
struct V_3 * V_4 = V_26 -> V_3 ;
F_150 ( & V_26 -> V_195 ) ;
if ( V_21 ) {
struct V_16 * V_19 = V_26 -> V_19 ;
int V_15 = V_26 -> V_15 ;
V_21 -> V_385 ( V_26 ) ;
F_12 ( & V_21 -> V_386 , V_15 ) ;
F_56 ( V_4 ) ;
if ( V_19 )
F_54 ( V_19 ) ;
} else {
F_320 ( & V_4 -> V_5 -> V_105 ) ;
F_284 ( V_4 ) ;
F_321 ( & V_4 -> V_191 ) ;
if ( F_14 ( V_4 ) ) {
F_56 ( F_14 ( V_4 ) ) ;
F_322 ( V_4 -> V_33 ) ;
F_57 ( V_4 ) ;
} else {
F_86 ( V_4 -> V_5 ) ;
}
}
}
static void F_323 ( struct V_70 * V_70 )
{
struct V_16 * V_26 =
F_15 ( V_70 , struct V_16 , V_70 ) ;
F_140 ( & V_26 -> V_384 , F_319 ) ;
F_324 ( V_387 , & V_26 -> V_384 ) ;
}
static void F_325 ( struct V_343 * V_344 )
{
struct V_16 * V_26 =
F_15 ( V_344 , struct V_16 , V_384 ) ;
struct V_20 * V_21 = V_26 -> V_21 ;
struct V_3 * V_4 = V_26 -> V_3 ;
F_87 ( & V_23 ) ;
V_26 -> V_29 |= V_327 ;
F_326 ( & V_26 -> V_187 ) ;
if ( V_21 ) {
F_10 ( & V_21 -> V_386 , NULL , V_26 -> V_15 ) ;
if ( V_21 -> V_388 )
V_21 -> V_388 ( V_26 ) ;
} else {
F_12 ( & V_4 -> V_5 -> V_104 , V_4 -> V_15 ) ;
V_4 -> V_15 = - 1 ;
F_115 ( * ( void V_389 V_390 * * ) & V_4 -> V_33 -> V_34 , NULL ) ;
}
F_90 ( & V_23 ) ;
F_327 ( & V_26 -> V_70 , F_323 ) ;
}
static void V_196 ( struct V_391 * V_392 )
{
struct V_16 * V_26 =
F_15 ( V_392 , struct V_16 , V_195 ) ;
F_140 ( & V_26 -> V_384 , F_325 ) ;
F_324 ( V_387 , & V_26 -> V_384 ) ;
}
static void F_328 ( struct V_16 * V_26 ,
struct V_20 * V_21 , struct V_3 * V_4 )
{
F_20 ( & V_23 ) ;
F_27 ( V_4 ) ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_26 -> V_3 = V_4 ;
V_26 -> V_21 = V_21 ;
F_70 ( & V_26 -> V_187 ) ;
F_70 ( & V_26 -> V_106 ) ;
V_26 -> V_328 = V_393 ++ ;
F_77 ( & V_26 -> V_394 , 0 ) ;
if ( F_14 ( V_4 ) ) {
V_26 -> V_19 = F_16 ( F_14 ( V_4 ) , V_21 ) ;
F_24 ( V_26 -> V_19 ) ;
}
F_64 ( F_16 ( V_4 , V_21 ) ) ;
}
static int F_329 ( struct V_16 * V_26 )
{
struct V_20 * V_21 = V_26 -> V_21 ;
int V_12 = 0 ;
F_20 ( & V_23 ) ;
if ( V_21 -> V_395 )
V_12 = V_21 -> V_395 ( V_26 ) ;
if ( ! V_12 ) {
V_26 -> V_29 |= V_30 ;
F_47 ( V_26 -> V_3 -> V_22 [ V_21 -> V_15 ] , V_26 ) ;
F_62 ( & V_26 -> V_394 ) ;
if ( V_26 -> V_19 )
F_62 ( & V_26 -> V_19 -> V_394 ) ;
}
return V_12 ;
}
static void F_330 ( struct V_16 * V_26 )
{
struct V_20 * V_21 = V_26 -> V_21 ;
F_20 ( & V_23 ) ;
if ( ! ( V_26 -> V_29 & V_30 ) )
return;
if ( V_21 -> V_396 )
V_21 -> V_396 ( V_26 ) ;
V_26 -> V_29 &= ~ V_30 ;
F_115 ( V_26 -> V_3 -> V_22 [ V_21 -> V_15 ] , NULL ) ;
F_331 ( & V_26 -> V_3 -> V_190 ) ;
}
static int F_224 ( struct V_3 * V_4 , struct V_20 * V_21 ,
bool V_397 )
{
struct V_3 * V_19 = F_14 ( V_4 ) ;
struct V_16 * V_17 = F_16 ( V_19 , V_21 ) ;
struct V_16 * V_26 ;
int V_141 ;
F_20 ( & V_23 ) ;
V_26 = V_21 -> V_398 ( V_17 ) ;
if ( F_148 ( V_26 ) )
return F_149 ( V_26 ) ;
F_328 ( V_26 , V_21 , V_4 ) ;
V_141 = F_146 ( & V_26 -> V_195 , V_196 , 0 , V_87 ) ;
if ( V_141 )
goto V_399;
V_141 = F_4 ( & V_21 -> V_386 , NULL , 2 , 0 , V_87 ) ;
if ( V_141 < 0 )
goto V_400;
V_26 -> V_15 = V_141 ;
if ( V_397 ) {
V_141 = F_111 ( V_26 , NULL ) ;
if ( V_141 )
goto V_401;
}
F_332 ( & V_26 -> V_187 , & V_17 -> V_106 ) ;
F_10 ( & V_21 -> V_386 , V_26 , V_26 -> V_15 ) ;
V_141 = F_329 ( V_26 ) ;
if ( V_141 )
goto V_402;
if ( V_21 -> V_403 && ! V_21 -> V_404 &&
F_14 ( V_19 ) ) {
F_113 ( L_32 ,
V_179 -> V_180 , V_179 -> V_261 , V_21 -> V_113 ) ;
if ( ! strcmp ( V_21 -> V_113 , L_33 ) )
F_113 ( L_34 ) ;
V_21 -> V_404 = true ;
}
return 0 ;
V_402:
F_326 ( & V_26 -> V_187 ) ;
F_109 ( V_26 , NULL ) ;
V_401:
F_12 ( & V_21 -> V_386 , V_26 -> V_15 ) ;
V_400:
F_150 ( & V_26 -> V_195 ) ;
V_399:
F_327 ( & V_26 -> V_70 , F_323 ) ;
return V_141 ;
}
static int F_333 ( struct V_130 * V_405 , const char * V_113 ,
T_2 V_115 )
{
struct V_3 * V_19 , * V_4 , * V_406 ;
struct V_83 * V_5 ;
struct V_20 * V_21 ;
struct V_130 * V_33 ;
int V_407 , V_1 , V_12 ;
if ( strchr ( V_113 , '\n' ) )
return - V_170 ;
V_19 = F_103 ( V_405 ) ;
if ( ! V_19 )
return - V_262 ;
V_5 = V_19 -> V_5 ;
V_407 = V_19 -> V_407 + 1 ;
V_4 = F_71 ( sizeof( * V_4 ) +
sizeof( V_4 -> V_194 [ 0 ] ) * ( V_407 + 1 ) , V_87 ) ;
if ( ! V_4 ) {
V_12 = - V_88 ;
goto V_27;
}
V_12 = F_146 ( & V_4 -> V_18 . V_195 , V_196 , 0 , V_87 ) ;
if ( V_12 )
goto V_408;
V_4 -> V_15 = F_4 ( & V_5 -> V_104 , NULL , 2 , 0 , V_87 ) ;
if ( V_4 -> V_15 < 0 ) {
V_12 = - V_88 ;
goto V_409;
}
F_137 ( V_4 ) ;
V_4 -> V_18 . V_19 = & V_19 -> V_18 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_407 = V_407 ;
for ( V_406 = V_4 ; V_406 ; V_406 = F_14 ( V_406 ) )
V_4 -> V_194 [ V_406 -> V_407 ] = V_406 -> V_15 ;
if ( F_34 ( V_19 ) )
F_143 ( V_37 , & V_4 -> V_29 ) ;
if ( F_35 ( V_159 , & V_19 -> V_29 ) )
F_143 ( V_159 , & V_4 -> V_29 ) ;
V_33 = F_334 ( V_19 -> V_33 , V_113 , V_115 , V_4 ) ;
if ( F_148 ( V_33 ) ) {
V_12 = F_149 ( V_33 ) ;
goto V_410;
}
V_4 -> V_33 = V_33 ;
F_335 ( V_33 ) ;
V_4 -> V_18 . V_328 = V_393 ++ ;
F_332 ( & V_4 -> V_18 . V_187 , & F_14 ( V_4 ) -> V_18 . V_106 ) ;
F_62 ( & V_5 -> V_105 ) ;
F_27 ( V_19 ) ;
F_10 ( & V_5 -> V_104 , V_4 , V_4 -> V_15 ) ;
V_12 = F_241 ( V_33 ) ;
if ( V_12 )
goto V_411;
V_12 = F_111 ( & V_4 -> V_18 , NULL ) ;
if ( V_12 )
goto V_411;
F_50 (ss, ssid) {
if ( V_19 -> V_25 & ( 1 << V_1 ) ) {
V_12 = F_224 ( V_4 , V_21 ,
V_19 -> V_126 & ( 1 << V_1 ) ) ;
if ( V_12 )
goto V_411;
}
}
if ( ! F_3 ( V_4 ) ) {
V_4 -> V_126 = V_19 -> V_126 ;
F_99 ( V_4 ) ;
}
F_119 ( V_33 ) ;
V_12 = 0 ;
goto V_27;
V_410:
F_12 ( & V_5 -> V_104 , V_4 -> V_15 ) ;
V_409:
F_150 ( & V_4 -> V_18 . V_195 ) ;
V_408:
F_57 ( V_4 ) ;
V_27:
F_100 ( V_405 ) ;
return V_12 ;
V_411:
F_336 ( V_4 ) ;
goto V_27;
}
static void F_337 ( struct V_343 * V_344 )
{
struct V_16 * V_26 =
F_15 ( V_344 , struct V_16 , V_384 ) ;
F_87 ( & V_23 ) ;
do {
F_330 ( V_26 ) ;
F_54 ( V_26 ) ;
V_26 = V_26 -> V_19 ;
} while ( V_26 && F_52 ( & V_26 -> V_394 ) );
F_90 ( & V_23 ) ;
}
static void F_338 ( struct V_391 * V_392 )
{
struct V_16 * V_26 =
F_15 ( V_392 , struct V_16 , V_195 ) ;
if ( F_52 ( & V_26 -> V_394 ) ) {
F_140 ( & V_26 -> V_384 , F_337 ) ;
F_324 ( V_387 , & V_26 -> V_384 ) ;
}
}
static void F_225 ( struct V_16 * V_26 )
{
F_20 ( & V_23 ) ;
F_109 ( V_26 , NULL ) ;
F_24 ( V_26 ) ;
F_339 ( & V_26 -> V_195 , F_338 ) ;
}
static int F_336 ( struct V_3 * V_4 )
__releases( &cgroup_mutex
static int F_340 ( struct V_130 * V_33 )
{
struct V_3 * V_4 ;
int V_12 = 0 ;
V_4 = F_103 ( V_33 ) ;
if ( ! V_4 )
return 0 ;
V_12 = F_336 ( V_4 ) ;
F_100 ( V_33 ) ;
return V_12 ;
}
static void T_8 F_341 ( struct V_20 * V_21 , bool V_412 )
{
struct V_16 * V_26 ;
F_342 ( L_35 , V_21 -> V_113 ) ;
F_87 ( & V_23 ) ;
F_142 ( & V_21 -> V_386 ) ;
F_70 ( & V_21 -> V_137 ) ;
V_21 -> V_5 = & V_6 ;
V_26 = V_21 -> V_398 ( F_16 ( & V_6 . V_4 , V_21 ) ) ;
F_64 ( F_148 ( V_26 ) ) ;
F_328 ( V_26 , V_21 , & V_6 . V_4 ) ;
V_26 -> V_29 |= V_413 ;
if ( V_412 ) {
V_26 -> V_15 = 1 ;
} else {
V_26 -> V_15 = F_4 ( & V_21 -> V_386 , V_26 , 1 , 2 , V_87 ) ;
F_64 ( V_26 -> V_15 < 0 ) ;
}
V_28 . V_22 [ V_21 -> V_15 ] = V_26 ;
V_414 |= ( bool ) V_21 -> V_415 << V_21 -> V_15 ;
V_416 |= ( bool ) V_21 -> exit << V_21 -> V_15 ;
V_417 |= ( bool ) V_21 -> free << V_21 -> V_15 ;
V_418 |= ( bool ) V_21 -> V_419 << V_21 -> V_15 ;
F_64 ( ! F_37 ( & V_420 . V_41 ) ) ;
F_64 ( F_329 ( V_26 ) ) ;
F_90 ( & V_23 ) ;
}
int T_8 F_343 ( void )
{
static struct V_161 T_9 V_162 ;
struct V_20 * V_21 ;
int V_62 ;
F_141 ( & V_6 , & V_162 ) ;
V_6 . V_4 . V_18 . V_29 |= V_413 ;
F_115 ( V_420 . V_60 , & V_28 ) ;
F_50 (ss, i) {
F_344 ( ! V_21 -> V_398 || ! V_21 -> V_385 || V_21 -> V_113 || V_21 -> V_15 ,
L_36 ,
V_62 , V_421 [ V_62 ] , V_21 -> V_398 , V_21 -> V_385 ,
V_21 -> V_15 , V_21 -> V_113 ) ;
F_344 ( strlen ( V_421 [ V_62 ] ) > V_422 ,
L_37 , V_421 [ V_62 ] ) ;
V_21 -> V_15 = V_62 ;
V_21 -> V_113 = V_421 [ V_62 ] ;
if ( ! V_21 -> V_114 )
V_21 -> V_114 = V_421 [ V_62 ] ;
if ( V_21 -> V_423 )
F_341 ( V_21 , true ) ;
}
return 0 ;
}
int T_8 F_345 ( void )
{
struct V_20 * V_21 ;
unsigned long V_61 ;
int V_1 ;
F_64 ( F_346 ( & V_263 ) ) ;
F_64 ( F_252 ( NULL , V_139 ) ) ;
F_64 ( F_252 ( NULL , V_140 ) ) ;
F_87 ( & V_23 ) ;
V_61 = F_49 ( V_28 . V_22 ) ;
F_79 ( V_97 , & V_28 . V_66 , V_61 ) ;
F_64 ( F_144 ( & V_6 , 0 ) ) ;
F_90 ( & V_23 ) ;
F_50 (ss, ssid) {
if ( V_21 -> V_423 ) {
struct V_16 * V_26 =
V_28 . V_22 [ V_21 -> V_15 ] ;
V_26 -> V_15 = F_4 ( & V_21 -> V_386 , V_26 , 1 , 2 ,
V_87 ) ;
F_64 ( V_26 -> V_15 < 0 ) ;
} else {
F_341 ( V_21 , false ) ;
}
F_48 ( & V_28 . V_65 [ V_1 ] ,
& V_6 . V_4 . V_98 [ V_1 ] ) ;
if ( V_424 & ( 1 << V_1 ) ) {
F_118 ( V_2 [ V_1 ] ) ;
F_347 ( V_425 L_38 ,
V_21 -> V_113 ) ;
continue;
}
V_6 . V_24 |= 1 << V_21 -> V_15 ;
if ( ! V_21 -> V_426 )
V_147 |= 1 << V_21 -> V_15 ;
if ( V_21 -> V_426 == V_21 -> V_427 ) {
F_114 ( F_256 ( V_21 , V_21 -> V_426 ) ) ;
} else {
F_114 ( F_257 ( V_21 , V_21 -> V_426 ) ) ;
F_114 ( F_258 ( V_21 , V_21 -> V_427 ) ) ;
}
if ( V_21 -> V_153 )
V_21 -> V_153 ( V_28 . V_22 [ V_1 ] ) ;
}
F_114 ( F_348 ( V_428 , L_39 ) ) ;
F_114 ( F_349 ( & V_367 ) ) ;
F_114 ( F_349 ( & V_208 ) ) ;
F_114 ( ! F_350 ( L_40 , 0 , NULL , & V_429 ) ) ;
return 0 ;
}
static int T_8 F_351 ( void )
{
V_387 = F_352 ( L_41 , 0 , 1 ) ;
F_64 ( ! V_387 ) ;
V_341 = F_352 ( L_42 ,
0 , 1 ) ;
F_64 ( ! V_341 ) ;
return 0 ;
}
int F_353 ( struct V_154 * V_294 , struct V_359 * V_351 ,
struct V_261 * V_261 , struct V_49 * V_260 )
{
char * V_109 , * V_219 ;
int V_271 ;
struct V_83 * V_5 ;
V_271 = - V_88 ;
V_109 = F_281 ( V_174 , V_87 ) ;
if ( ! V_109 )
goto V_193;
F_87 ( & V_23 ) ;
F_6 ( & V_40 ) ;
F_156 (root) {
struct V_20 * V_21 ;
struct V_3 * V_4 ;
int V_1 , V_85 = 0 ;
if ( V_5 == & V_6 && ! V_150 )
continue;
F_212 ( V_294 , L_43 , V_5 -> V_103 ) ;
if ( V_5 != & V_6 )
F_50 (ss, ssid)
if ( V_5 -> V_24 & ( 1 << V_1 ) )
F_212 ( V_294 , L_44 , V_85 ++ ? L_9 : L_20 ,
V_21 -> V_114 ) ;
if ( strlen ( V_5 -> V_113 ) )
F_212 ( V_294 , L_45 , V_85 ? L_9 : L_20 ,
V_5 -> V_113 ) ;
F_209 ( V_294 , ':' ) ;
V_4 = F_93 ( V_260 , V_5 ) ;
if ( F_3 ( V_4 ) || ! ( V_260 -> V_29 & V_59 ) ) {
V_219 = F_167 ( V_4 , V_109 , V_174 ) ;
if ( ! V_219 ) {
V_271 = - V_430 ;
goto V_27;
}
} else {
V_219 = L_23 ;
}
F_122 ( V_294 , V_219 ) ;
if ( F_3 ( V_4 ) && F_26 ( V_4 ) )
F_122 ( V_294 , L_46 ) ;
else
F_209 ( V_294 , '\n' ) ;
}
V_271 = 0 ;
V_27:
F_8 ( & V_40 ) ;
F_90 ( & V_23 ) ;
F_57 ( V_109 ) ;
V_193:
return V_271 ;
}
static int F_354 ( struct V_154 * V_294 , void * V_273 )
{
struct V_20 * V_21 ;
int V_62 ;
F_122 ( V_294 , L_47 ) ;
F_87 ( & V_23 ) ;
F_50 (ss, i)
F_212 ( V_294 , L_48 ,
V_21 -> V_114 , V_21 -> V_5 -> V_103 ,
F_88 ( & V_21 -> V_5 -> V_105 ) ,
F_1 ( V_62 ) ) ;
F_90 ( & V_23 ) ;
return 0 ;
}
static int F_355 ( struct V_255 * V_255 , struct V_252 * V_252 )
{
return F_356 ( V_252 , F_354 , NULL ) ;
}
void F_357 ( struct V_49 * V_285 )
{
F_115 ( V_285 -> V_60 , & V_28 ) ;
F_70 ( & V_285 -> V_57 ) ;
}
int F_358 ( struct V_49 * V_285 )
{
struct V_20 * V_21 ;
int V_62 , V_431 , V_12 ;
F_98 (ss, i, &have_canfork_callback) {
V_12 = V_21 -> V_419 ( V_285 ) ;
if ( V_12 )
goto V_432;
}
return 0 ;
V_432:
F_50 (ss, j) {
if ( V_431 >= V_62 )
break;
if ( V_21 -> V_433 )
V_21 -> V_433 ( V_285 ) ;
}
return V_12 ;
}
void F_359 ( struct V_49 * V_285 )
{
struct V_20 * V_21 ;
int V_62 ;
F_50 (ss, i)
if ( V_21 -> V_433 )
V_21 -> V_433 ( V_285 ) ;
}
void F_360 ( struct V_49 * V_285 )
{
struct V_20 * V_21 ;
int V_62 ;
if ( V_183 ) {
struct V_38 * V_39 ;
F_6 ( & V_40 ) ;
V_39 = F_94 ( V_179 ) ;
if ( F_37 ( & V_285 -> V_57 ) ) {
F_61 ( V_39 ) ;
F_43 ( V_285 , NULL , V_39 , false ) ;
}
F_8 ( & V_40 ) ;
}
F_98 (ss, i, &have_fork_callback)
V_21 -> V_415 ( V_285 ) ;
}
void F_361 ( struct V_49 * V_260 )
{
struct V_20 * V_21 ;
struct V_38 * V_39 ;
int V_62 ;
V_39 = F_94 ( V_260 ) ;
if ( ! F_37 ( & V_260 -> V_57 ) ) {
F_6 ( & V_40 ) ;
F_43 ( V_260 , V_39 , NULL , false ) ;
F_8 ( & V_40 ) ;
} else {
F_61 ( V_39 ) ;
}
F_98 (ss, i, &have_exit_callback)
V_21 -> exit ( V_260 ) ;
}
void F_362 ( struct V_49 * V_50 )
{
struct V_38 * V_39 = F_94 ( V_50 ) ;
struct V_20 * V_21 ;
int V_1 ;
F_98 (ss, ssid, &have_free_callback)
V_21 -> free ( V_50 ) ;
F_59 ( V_39 ) ;
}
static void F_39 ( struct V_3 * V_4 )
{
if ( F_34 ( V_4 ) && ! F_227 ( V_4 ) &&
! F_272 ( & V_4 -> V_18 ) && ! F_26 ( V_4 ) )
F_363 ( & V_4 -> V_191 ) ;
}
static void V_192 ( struct V_343 * V_344 )
{
struct V_3 * V_4 =
F_15 ( V_344 , struct V_3 , V_191 ) ;
char * V_434 = NULL , * V_435 = NULL , * V_219 ;
char * V_436 [ 3 ] , * V_437 [ 3 ] ;
F_87 ( & V_23 ) ;
V_434 = F_281 ( V_174 , V_87 ) ;
V_435 = F_364 ( V_4 -> V_5 -> V_158 , V_87 ) ;
if ( ! V_434 || ! V_435 )
goto V_193;
V_219 = F_167 ( V_4 , V_434 , V_174 ) ;
if ( ! V_219 )
goto V_193;
V_436 [ 0 ] = V_435 ;
V_436 [ 1 ] = V_219 ;
V_436 [ 2 ] = NULL ;
V_437 [ 0 ] = L_49 ;
V_437 [ 1 ] = L_50 ;
V_437 [ 2 ] = NULL ;
F_90 ( & V_23 ) ;
F_365 ( V_436 [ 0 ] , V_436 , V_437 , V_438 ) ;
goto V_213;
V_193:
F_90 ( & V_23 ) ;
V_213:
F_57 ( V_435 ) ;
F_57 ( V_434 ) ;
}
static int T_8 F_366 ( char * V_439 )
{
struct V_20 * V_21 ;
char * V_163 ;
int V_62 ;
while ( ( V_163 = F_127 ( & V_439 , L_9 ) ) != NULL ) {
if ( ! * V_163 )
continue;
F_50 (ss, i) {
if ( strcmp ( V_163 , V_21 -> V_113 ) &&
strcmp ( V_163 , V_21 -> V_114 ) )
continue;
V_424 |= 1 << V_62 ;
}
}
return 1 ;
}
struct V_16 * F_367 ( struct V_203 * V_203 ,
struct V_20 * V_21 )
{
struct V_130 * V_33 = F_307 ( V_203 ) ;
struct V_16 * V_26 = NULL ;
struct V_3 * V_4 ;
if ( V_203 -> V_254 -> V_366 != & V_367 || ! V_33 ||
F_101 ( V_33 ) != V_131 )
return F_152 ( - V_440 ) ;
F_22 () ;
V_4 = F_308 ( V_33 -> V_34 ) ;
if ( V_4 )
V_26 = F_16 ( V_4 , V_21 ) ;
if ( ! V_26 || ! F_23 ( V_26 ) )
V_26 = F_152 ( - V_176 ) ;
F_25 () ;
return V_26 ;
}
struct V_16 * F_368 ( int V_15 , struct V_20 * V_21 )
{
F_28 ( ! F_369 () ) ;
return V_15 > 0 ? F_370 ( & V_21 -> V_386 , V_15 ) : NULL ;
}
struct V_3 * F_371 ( const char * V_219 )
{
struct V_130 * V_33 ;
struct V_3 * V_4 ;
F_87 ( & V_23 ) ;
V_33 = F_372 ( V_6 . V_4 . V_33 , V_219 ) ;
if ( V_33 ) {
if ( F_101 ( V_33 ) == V_131 ) {
V_4 = V_33 -> V_34 ;
F_27 ( V_4 ) ;
} else {
V_4 = F_152 ( - V_298 ) ;
}
F_322 ( V_33 ) ;
} else {
V_4 = F_152 ( - V_176 ) ;
}
F_90 ( & V_23 ) ;
return V_4 ;
}
void F_373 ( void )
{
if ( V_441 )
return;
F_374 ( L_51 ) ;
V_441 = true ;
}
void F_375 ( struct V_442 * V_443 )
{
if ( V_441 )
return;
F_22 () ;
while ( true ) {
struct V_38 * V_39 ;
V_39 = F_94 ( V_179 ) ;
if ( F_265 ( F_29 ( V_39 -> V_89 ) ) ) {
V_443 -> V_383 = ( unsigned long ) V_39 -> V_89 ;
break;
}
F_376 () ;
}
F_25 () ;
}
void F_377 ( struct V_442 * V_443 )
{
F_56 ( F_378 ( V_443 ) ) ;
}
static struct V_16 *
F_379 ( struct V_16 * V_17 )
{
struct V_16 * V_26 = F_71 ( sizeof( * V_26 ) , V_87 ) ;
if ( ! V_26 )
return F_152 ( - V_88 ) ;
return V_26 ;
}
static void F_380 ( struct V_16 * V_26 )
{
F_57 ( V_26 ) ;
}
static T_7 F_381 ( struct V_16 * V_26 ,
struct V_35 * V_36 )
{
return F_262 ( V_26 -> V_3 ) ;
}
static T_7 F_382 ( struct V_16 * V_26 ,
struct V_35 * V_36 )
{
return ( T_7 ) ( unsigned long ) V_179 -> V_60 ;
}
static T_7 F_383 ( struct V_16 * V_26 ,
struct V_35 * V_36 )
{
T_7 V_85 ;
F_22 () ;
V_85 = F_88 ( & F_94 ( V_179 ) -> V_64 ) ;
F_25 () ;
return V_85 ;
}
static int F_384 ( struct V_154 * V_155 , void * V_273 )
{
struct V_47 * V_48 ;
struct V_38 * V_39 ;
char * V_444 ;
V_444 = F_281 ( V_445 + 1 , V_87 ) ;
if ( ! V_444 )
return - V_88 ;
F_6 ( & V_40 ) ;
F_22 () ;
V_39 = F_308 ( V_179 -> V_60 ) ;
F_42 (link, &cset->cgrp_links, cgrp_link) {
struct V_3 * V_96 = V_48 -> V_4 ;
F_385 ( V_96 , V_444 , V_445 + 1 ) ;
F_212 ( V_155 , L_52 ,
V_96 -> V_5 -> V_103 , V_444 ) ;
}
F_25 () ;
F_8 ( & V_40 ) ;
F_57 ( V_444 ) ;
return 0 ;
}
static int F_386 ( struct V_154 * V_155 , void * V_273 )
{
struct V_16 * V_26 = F_208 ( V_155 ) ;
struct V_47 * V_48 ;
F_6 ( & V_40 ) ;
F_42 (link, &css->cgroup->cset_links, cset_link) {
struct V_38 * V_39 = V_48 -> V_39 ;
struct V_49 * V_50 ;
int V_85 = 0 ;
F_212 ( V_155 , L_53 , V_39 ) ;
F_42 (task, &cset->tasks, cg_list) {
if ( V_85 ++ > V_446 )
goto V_447;
F_212 ( V_155 , L_54 , F_304 ( V_50 ) ) ;
}
F_42 (task, &cset->mg_tasks, cg_list) {
if ( V_85 ++ > V_446 )
goto V_447;
F_212 ( V_155 , L_54 , F_304 ( V_50 ) ) ;
}
continue;
V_447:
F_122 ( V_155 , L_55 ) ;
}
F_8 ( & V_40 ) ;
return 0 ;
}
static T_7 F_387 ( struct V_16 * V_26 , struct V_35 * V_36 )
{
return ( ! F_227 ( V_26 -> V_3 ) &&
! F_272 ( & V_26 -> V_3 -> V_18 ) ) ;
}
