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
static void F_31 ( struct V_3 * V_4 )
{
F_32 ( & V_4 -> V_18 ) ;
}
struct V_16 * F_33 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = V_32 -> V_33 -> V_19 -> V_34 ;
struct V_35 * V_36 = F_34 ( V_32 ) ;
if ( V_36 -> V_21 )
return F_35 ( V_4 -> V_22 [ V_36 -> V_21 -> V_15 ] ) ;
else
return & V_4 -> V_18 ;
}
bool F_36 ( struct V_3 * V_4 , struct V_3 * V_37 )
{
while ( V_4 ) {
if ( V_4 == V_37 )
return true ;
V_4 = F_14 ( V_4 ) ;
}
return false ;
}
static int F_37 ( const struct V_3 * V_4 )
{
return F_38 ( V_38 , & V_4 -> V_29 ) ;
}
static bool F_39 ( struct V_39 * V_40 )
{
F_20 ( & V_41 ) ;
return ! F_40 ( & V_40 -> V_42 ) || ! F_40 ( & V_40 -> V_43 ) ;
}
static void F_41 ( struct V_3 * V_4 , bool V_44 )
{
F_20 ( & V_41 ) ;
do {
bool V_45 ;
if ( V_44 )
V_45 = ! V_4 -> V_46 ++ ;
else
V_45 = ! -- V_4 -> V_46 ;
if ( ! V_45 )
break;
F_42 ( V_4 ) ;
F_43 ( & V_4 -> V_47 ) ;
V_4 = F_14 ( V_4 ) ;
} while ( V_4 );
}
static void F_44 ( struct V_39 * V_40 , bool V_44 )
{
struct V_48 * V_49 ;
F_20 ( & V_41 ) ;
F_45 (link, &cset->cgrp_links, cgrp_link)
F_41 ( V_49 -> V_4 , V_44 ) ;
}
static void F_46 ( struct V_50 * V_51 ,
struct V_39 * V_52 , struct V_39 * V_53 ,
bool V_54 )
{
F_20 ( & V_41 ) ;
if ( V_52 ) {
struct V_55 * V_56 , * V_57 ;
F_28 ( F_40 ( & V_51 -> V_58 ) ) ;
F_47 (it, pos, &from_cset->task_iters,
iters_node)
if ( V_56 -> V_59 == & V_51 -> V_58 )
F_48 ( V_56 ) ;
F_49 ( & V_51 -> V_58 ) ;
if ( ! F_39 ( V_52 ) )
F_44 ( V_52 , false ) ;
} else {
F_28 ( ! F_40 ( & V_51 -> V_58 ) ) ;
}
if ( V_53 ) {
F_28 ( V_51 -> V_29 & V_60 ) ;
if ( ! F_39 ( V_53 ) )
F_44 ( V_53 , true ) ;
F_50 ( V_51 -> V_61 , V_53 ) ;
F_51 ( & V_51 -> V_58 , V_54 ? & V_53 -> V_43 :
& V_53 -> V_42 ) ;
}
}
static unsigned long F_52 ( struct V_16 * V_26 [] )
{
unsigned long V_62 = 0UL ;
struct V_20 * V_21 ;
int V_63 ;
F_53 (ss, i)
V_62 += ( unsigned long ) V_26 [ V_63 ] ;
V_62 = ( V_62 >> 16 ) ^ V_62 ;
return V_62 ;
}
static void F_54 ( struct V_39 * V_40 )
{
struct V_48 * V_49 , * V_64 ;
struct V_20 * V_21 ;
int V_1 ;
F_20 ( & V_41 ) ;
if ( ! F_55 ( & V_40 -> V_65 ) )
return;
F_53 (ss, ssid) {
F_56 ( & V_40 -> V_66 [ V_1 ] ) ;
F_32 ( V_40 -> V_22 [ V_1 ] ) ;
}
F_57 ( & V_40 -> V_67 ) ;
V_68 -- ;
F_47 (link, tmp_link, &cset->cgrp_links, cgrp_link) {
F_56 ( & V_49 -> V_69 ) ;
F_56 ( & V_49 -> V_70 ) ;
if ( F_14 ( V_49 -> V_4 ) )
F_31 ( V_49 -> V_4 ) ;
F_58 ( V_49 ) ;
}
F_59 ( V_40 , V_71 ) ;
}
static void F_60 ( struct V_39 * V_40 )
{
if ( F_61 ( & V_40 -> V_65 , - 1 , 1 ) )
return;
F_6 ( & V_41 ) ;
F_54 ( V_40 ) ;
F_8 ( & V_41 ) ;
}
static inline void F_62 ( struct V_39 * V_40 )
{
F_63 ( & V_40 -> V_65 ) ;
}
static bool F_64 ( struct V_39 * V_40 ,
struct V_39 * V_72 ,
struct V_3 * V_73 ,
struct V_16 * V_74 [] )
{
struct V_75 * V_76 , * V_77 ;
if ( memcmp ( V_74 , V_40 -> V_22 , sizeof( V_40 -> V_22 ) ) )
return false ;
V_76 = & V_40 -> V_78 ;
V_77 = & V_72 -> V_78 ;
while ( 1 ) {
struct V_48 * V_79 , * V_80 ;
struct V_3 * V_81 , * V_82 ;
V_76 = V_76 -> V_83 ;
V_77 = V_77 -> V_83 ;
if ( V_76 == & V_40 -> V_78 ) {
F_65 ( V_77 != & V_72 -> V_78 ) ;
break;
} else {
F_65 ( V_77 == & V_72 -> V_78 ) ;
}
V_79 = F_66 ( V_76 , struct V_48 , V_70 ) ;
V_80 = F_66 ( V_77 , struct V_48 , V_70 ) ;
V_81 = V_79 -> V_4 ;
V_82 = V_80 -> V_4 ;
F_65 ( V_81 -> V_5 != V_82 -> V_5 ) ;
if ( V_81 -> V_5 == V_73 -> V_5 ) {
if ( V_81 != V_73 )
return false ;
} else {
if ( V_81 != V_82 )
return false ;
}
}
return true ;
}
static struct V_39 * F_67 ( struct V_39 * V_72 ,
struct V_3 * V_4 ,
struct V_16 * V_74 [] )
{
struct V_84 * V_5 = V_4 -> V_5 ;
struct V_20 * V_21 ;
struct V_39 * V_40 ;
unsigned long V_62 ;
int V_63 ;
F_53 (ss, i) {
if ( V_5 -> V_24 & ( 1UL << V_63 ) ) {
V_74 [ V_63 ] = F_19 ( V_4 , V_21 ) ;
} else {
V_74 [ V_63 ] = V_72 -> V_22 [ V_63 ] ;
}
}
V_62 = F_52 ( V_74 ) ;
F_68 (css_set_table, cset, hlist, key) {
if ( ! F_64 ( V_40 , V_72 , V_4 , V_74 ) )
continue;
return V_40 ;
}
return NULL ;
}
static void F_69 ( struct V_75 * V_85 )
{
struct V_48 * V_49 , * V_64 ;
F_47 (link, tmp_link, links_to_free, cset_link) {
F_56 ( & V_49 -> V_69 ) ;
F_58 ( V_49 ) ;
}
}
static int F_70 ( int V_86 , struct V_75 * V_87 )
{
struct V_48 * V_49 ;
int V_63 ;
F_71 ( V_87 ) ;
for ( V_63 = 0 ; V_63 < V_86 ; V_63 ++ ) {
V_49 = F_72 ( sizeof( * V_49 ) , V_88 ) ;
if ( ! V_49 ) {
F_69 ( V_87 ) ;
return - V_89 ;
}
F_73 ( & V_49 -> V_69 , V_87 ) ;
}
return 0 ;
}
static void F_74 ( struct V_75 * V_87 , struct V_39 * V_40 ,
struct V_3 * V_4 )
{
struct V_48 * V_49 ;
F_65 ( F_40 ( V_87 ) ) ;
if ( F_3 ( V_4 ) )
V_40 -> V_90 = V_4 ;
V_49 = F_75 ( V_87 , struct V_48 , V_69 ) ;
V_49 -> V_40 = V_40 ;
V_49 -> V_4 = V_4 ;
F_76 ( & V_49 -> V_69 , & V_4 -> V_91 ) ;
F_51 ( & V_49 -> V_70 , & V_40 -> V_78 ) ;
if ( F_14 ( V_4 ) )
F_27 ( V_4 ) ;
}
static struct V_39 * F_77 ( struct V_39 * V_72 ,
struct V_3 * V_4 )
{
struct V_16 * V_74 [ V_92 ] = { } ;
struct V_39 * V_40 ;
struct V_75 V_87 ;
struct V_48 * V_49 ;
struct V_20 * V_21 ;
unsigned long V_62 ;
int V_1 ;
F_20 ( & V_23 ) ;
F_6 ( & V_41 ) ;
V_40 = F_67 ( V_72 , V_4 , V_74 ) ;
if ( V_40 )
F_62 ( V_40 ) ;
F_8 ( & V_41 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_72 ( sizeof( * V_40 ) , V_88 ) ;
if ( ! V_40 )
return NULL ;
if ( F_70 ( V_93 , & V_87 ) < 0 ) {
F_58 ( V_40 ) ;
return NULL ;
}
F_78 ( & V_40 -> V_65 , 1 ) ;
F_71 ( & V_40 -> V_78 ) ;
F_71 ( & V_40 -> V_42 ) ;
F_71 ( & V_40 -> V_43 ) ;
F_71 ( & V_40 -> V_94 ) ;
F_71 ( & V_40 -> V_95 ) ;
F_71 ( & V_40 -> V_96 ) ;
F_79 ( & V_40 -> V_67 ) ;
memcpy ( V_40 -> V_22 , V_74 , sizeof( V_40 -> V_22 ) ) ;
F_6 ( & V_41 ) ;
F_45 (link, &old_cset->cgrp_links, cgrp_link) {
struct V_3 * V_97 = V_49 -> V_4 ;
if ( V_97 -> V_5 == V_4 -> V_5 )
V_97 = V_4 ;
F_74 ( & V_87 , V_40 , V_97 ) ;
}
F_65 ( ! F_40 ( & V_87 ) ) ;
V_68 ++ ;
V_62 = F_52 ( V_40 -> V_22 ) ;
F_80 ( V_98 , & V_40 -> V_67 , V_62 ) ;
F_53 (ss, ssid) {
struct V_16 * V_26 = V_40 -> V_22 [ V_1 ] ;
F_51 ( & V_40 -> V_66 [ V_1 ] ,
& V_26 -> V_3 -> V_99 [ V_1 ] ) ;
F_24 ( V_26 ) ;
}
F_8 ( & V_41 ) ;
return V_40 ;
}
static struct V_84 * F_81 ( struct V_100 * V_101 )
{
struct V_3 * V_102 = V_101 -> V_33 -> V_34 ;
return V_102 -> V_5 ;
}
static int F_82 ( struct V_84 * V_5 )
{
int V_15 ;
F_20 ( & V_23 ) ;
V_15 = F_83 ( & V_103 , V_5 , 0 , 0 , V_88 ) ;
if ( V_15 < 0 )
return V_15 ;
V_5 -> V_104 = V_15 ;
return 0 ;
}
static void F_84 ( struct V_84 * V_5 )
{
F_20 ( & V_23 ) ;
if ( V_5 -> V_104 ) {
F_13 ( & V_103 , V_5 -> V_104 ) ;
V_5 -> V_104 = 0 ;
}
}
static void F_85 ( struct V_84 * V_5 )
{
if ( V_5 ) {
F_28 ( V_5 -> V_104 ) ;
F_86 ( & V_5 -> V_105 ) ;
F_58 ( V_5 ) ;
}
}
static void F_87 ( struct V_84 * V_5 )
{
struct V_3 * V_4 = & V_5 -> V_4 ;
struct V_48 * V_49 , * V_64 ;
F_88 ( & V_23 ) ;
F_65 ( F_89 ( & V_5 -> V_106 ) ) ;
F_65 ( ! F_40 ( & V_4 -> V_18 . V_107 ) ) ;
F_90 ( & V_6 , V_5 -> V_24 ) ;
F_6 ( & V_41 ) ;
F_47 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_56 ( & V_49 -> V_69 ) ;
F_56 ( & V_49 -> V_70 ) ;
F_58 ( V_49 ) ;
}
F_8 ( & V_41 ) ;
if ( ! F_40 ( & V_5 -> V_108 ) ) {
F_56 ( & V_5 -> V_108 ) ;
V_93 -- ;
}
F_84 ( V_5 ) ;
F_91 ( & V_23 ) ;
F_92 ( V_5 -> V_101 ) ;
F_85 ( V_5 ) ;
}
static struct V_3 * F_93 ( struct V_39 * V_40 ,
struct V_84 * V_5 )
{
struct V_3 * V_109 = NULL ;
F_20 ( & V_23 ) ;
F_20 ( & V_41 ) ;
if ( V_40 == & V_28 ) {
V_109 = & V_5 -> V_4 ;
} else {
struct V_48 * V_49 ;
F_45 (link, &cset->cgrp_links, cgrp_link) {
struct V_3 * V_97 = V_49 -> V_4 ;
if ( V_97 -> V_5 == V_5 ) {
V_109 = V_97 ;
break;
}
}
}
F_65 ( ! V_109 ) ;
return V_109 ;
}
static struct V_3 * F_94 ( struct V_50 * V_51 ,
struct V_84 * V_5 )
{
return F_93 ( F_95 ( V_51 ) , V_5 ) ;
}
static char * F_96 ( struct V_3 * V_4 , const struct V_35 * V_36 ,
char * V_110 )
{
struct V_20 * V_21 = V_36 -> V_21 ;
if ( V_36 -> V_21 && ! ( V_36 -> V_29 & V_111 ) &&
! ( V_4 -> V_5 -> V_29 & V_112 ) )
snprintf ( V_110 , V_113 , L_1 ,
F_3 ( V_4 ) ? V_21 -> V_114 : V_21 -> V_115 ,
V_36 -> V_114 ) ;
else
strncpy ( V_110 , V_36 -> V_114 , V_113 ) ;
return V_110 ;
}
static T_2 F_97 ( const struct V_35 * V_36 )
{
T_2 V_116 = 0 ;
if ( V_36 -> V_117 || V_36 -> V_118 || V_36 -> V_119 )
V_116 |= V_120 ;
if ( V_36 -> V_121 || V_36 -> V_122 || V_36 -> V_123 ) {
if ( V_36 -> V_29 & V_124 )
V_116 |= V_125 ;
else
V_116 |= V_126 ;
}
return V_116 ;
}
static unsigned long F_98 ( struct V_3 * V_4 ,
unsigned long V_127 )
{
struct V_3 * V_19 = F_14 ( V_4 ) ;
unsigned long V_128 = V_127 ;
struct V_20 * V_21 ;
int V_1 ;
F_20 ( & V_23 ) ;
if ( ! F_3 ( V_4 ) )
return V_128 ;
while ( true ) {
unsigned long V_129 = V_128 ;
F_99 (ss, ssid, &cur_ss_mask)
V_129 |= V_21 -> V_130 ;
if ( V_19 )
V_129 &= V_19 -> V_25 ;
else
V_129 &= V_4 -> V_5 -> V_24 ;
if ( V_129 == V_128 )
break;
V_128 = V_129 ;
}
return V_128 ;
}
static void F_100 ( struct V_3 * V_4 )
{
V_4 -> V_25 =
F_98 ( V_4 , V_4 -> V_127 ) ;
}
static void F_101 ( struct V_131 * V_33 )
{
struct V_3 * V_4 ;
if ( F_102 ( V_33 ) == V_132 )
V_4 = V_33 -> V_34 ;
else
V_4 = V_33 -> V_19 -> V_34 ;
F_91 ( & V_23 ) ;
F_103 ( V_33 ) ;
F_31 ( V_4 ) ;
}
static struct V_3 * F_104 ( struct V_131 * V_33 )
{
struct V_3 * V_4 ;
if ( F_102 ( V_33 ) == V_132 )
V_4 = V_33 -> V_34 ;
else
V_4 = V_33 -> V_19 -> V_34 ;
if ( ! F_29 ( V_4 ) )
return NULL ;
F_105 ( V_33 ) ;
F_88 ( & V_23 ) ;
if ( ! F_26 ( V_4 ) )
return V_4 ;
F_101 ( V_33 ) ;
return NULL ;
}
static void F_106 ( struct V_3 * V_4 , const struct V_35 * V_36 )
{
char V_114 [ V_113 ] ;
F_20 ( & V_23 ) ;
if ( V_36 -> V_133 ) {
struct V_16 * V_26 = F_16 ( V_4 , V_36 -> V_21 ) ;
struct V_134 * V_135 = ( void * ) V_26 + V_36 -> V_133 ;
F_107 ( & V_136 ) ;
V_135 -> V_33 = NULL ;
F_108 ( & V_136 ) ;
}
F_109 ( V_4 -> V_33 , F_96 ( V_4 , V_36 , V_114 ) ) ;
}
static void F_110 ( struct V_16 * V_26 ,
struct V_3 * V_137 )
{
struct V_3 * V_4 = V_137 ? : V_26 -> V_3 ;
struct V_35 * V_138 ;
F_45 (cfts, &css->ss->cfts, node)
F_111 ( V_26 , V_4 , V_138 , false ) ;
}
static int F_112 ( struct V_16 * V_26 ,
struct V_3 * V_137 )
{
struct V_3 * V_4 = V_137 ? : V_26 -> V_3 ;
struct V_35 * V_138 , * V_139 ;
int V_12 ;
if ( ! V_26 -> V_21 ) {
if ( F_3 ( V_4 ) )
V_138 = V_140 ;
else
V_138 = V_141 ;
return F_111 ( & V_4 -> V_18 , V_4 , V_138 , true ) ;
}
F_45 (cfts, &css->ss->cfts, node) {
V_12 = F_111 ( V_26 , V_4 , V_138 , true ) ;
if ( V_12 < 0 ) {
V_139 = V_138 ;
goto V_142;
}
}
return 0 ;
V_142:
F_45 (cfts, &css->ss->cfts, node) {
if ( V_138 == V_139 )
break;
F_111 ( V_26 , V_4 , V_138 , false ) ;
}
return V_12 ;
}
static int F_90 ( struct V_84 * V_143 ,
unsigned long V_144 )
{
struct V_3 * V_145 = & V_143 -> V_4 ;
struct V_20 * V_21 ;
unsigned long V_146 ;
int V_1 , V_63 , V_12 ;
F_20 ( & V_23 ) ;
F_99 (ss, ssid, &ss_mask) {
if ( F_113 ( NULL , F_16 ( & V_21 -> V_5 -> V_4 , V_21 ) ) )
return - V_147 ;
if ( V_21 -> V_5 != & V_6 && V_143 != & V_6 )
return - V_147 ;
}
V_146 = V_144 ;
if ( V_143 == & V_6 )
V_146 &= ~ V_148 ;
F_99 (ss, ssid, &tmp_ss_mask) {
struct V_3 * V_149 = & V_21 -> V_5 -> V_4 ;
int V_150 ;
V_12 = F_112 ( F_16 ( V_149 , V_21 ) , V_145 ) ;
if ( ! V_12 )
continue;
if ( V_143 == & V_6 ) {
if ( V_151 ) {
F_114 ( L_2 ,
V_12 , V_144 ) ;
F_114 ( L_3 ) ;
}
continue;
}
F_99 (ss, tssid, &tmp_ss_mask) {
if ( V_150 == V_1 )
break;
F_110 ( F_16 ( V_149 , V_21 ) , V_145 ) ;
}
return V_12 ;
}
F_99 (ss, ssid, &ss_mask) {
struct V_84 * V_152 = V_21 -> V_5 ;
struct V_3 * V_149 = & V_152 -> V_4 ;
struct V_16 * V_26 = F_16 ( V_149 , V_21 ) ;
struct V_39 * V_40 ;
F_115 ( ! V_26 || F_16 ( V_145 , V_21 ) ) ;
F_110 ( V_26 , NULL ) ;
F_116 ( V_149 -> V_22 [ V_1 ] , NULL ) ;
F_50 ( V_145 -> V_22 [ V_1 ] , V_26 ) ;
V_21 -> V_5 = V_143 ;
V_26 -> V_3 = V_145 ;
F_6 ( & V_41 ) ;
F_117 (css_set_table, i, cset, hlist)
F_76 ( & V_40 -> V_66 [ V_21 -> V_15 ] ,
& V_145 -> V_99 [ V_21 -> V_15 ] ) ;
F_8 ( & V_41 ) ;
V_152 -> V_24 &= ~ ( 1 << V_1 ) ;
V_149 -> V_127 &= ~ ( 1 << V_1 ) ;
F_100 ( V_149 ) ;
V_143 -> V_24 |= 1 << V_1 ;
if ( V_143 == & V_6 ) {
F_118 ( V_153 [ V_1 ] ) ;
} else {
V_145 -> V_127 |= 1 << V_1 ;
F_100 ( V_145 ) ;
F_119 ( V_153 [ V_1 ] ) ;
}
if ( V_21 -> V_154 )
V_21 -> V_154 ( V_26 ) ;
}
F_120 ( V_145 -> V_33 ) ;
return 0 ;
}
static int F_121 ( struct V_155 * V_156 ,
struct V_100 * V_101 )
{
struct V_84 * V_5 = F_81 ( V_101 ) ;
struct V_20 * V_21 ;
int V_1 ;
if ( V_5 != & V_6 )
F_53 (ss, ssid)
if ( V_5 -> V_24 & ( 1 << V_1 ) )
F_122 ( V_156 , V_21 -> V_115 , NULL ) ;
if ( V_5 -> V_29 & V_112 )
F_123 ( V_156 , L_4 ) ;
if ( V_5 -> V_29 & V_157 )
F_123 ( V_156 , L_5 ) ;
F_124 ( & V_158 ) ;
if ( strlen ( V_5 -> V_159 ) )
F_122 ( V_156 , L_6 ,
V_5 -> V_159 ) ;
F_125 ( & V_158 ) ;
if ( F_38 ( V_160 , & V_5 -> V_4 . V_29 ) )
F_123 ( V_156 , L_7 ) ;
if ( strlen ( V_5 -> V_114 ) )
F_122 ( V_156 , L_8 , V_5 -> V_114 ) ;
return 0 ;
}
static int F_126 ( char * V_161 , struct V_162 * V_163 )
{
char * V_164 , * V_165 = V_161 ;
bool V_166 = false , V_167 = false ;
unsigned long V_168 = - 1UL ;
struct V_20 * V_21 ;
int V_169 = 0 ;
int V_63 ;
#ifdef F_127
V_168 = ~ ( 1U << V_170 ) ;
#endif
memset ( V_163 , 0 , sizeof( * V_163 ) ) ;
while ( ( V_164 = F_128 ( & V_165 , L_9 ) ) != NULL ) {
V_169 ++ ;
if ( ! * V_164 )
return - V_171 ;
if ( ! strcmp ( V_164 , L_10 ) ) {
V_163 -> V_172 = true ;
continue;
}
if ( ! strcmp ( V_164 , L_11 ) ) {
if ( V_167 )
return - V_171 ;
V_166 = true ;
continue;
}
if ( ! strcmp ( V_164 , L_12 ) ) {
V_163 -> V_29 |= V_173 ;
continue;
}
if ( ! strcmp ( V_164 , L_13 ) ) {
V_163 -> V_29 |= V_112 ;
continue;
}
if ( ! strcmp ( V_164 , L_14 ) ) {
V_163 -> V_174 = true ;
continue;
}
if ( ! strcmp ( V_164 , L_15 ) ) {
V_163 -> V_29 |= V_157 ;
continue;
}
if ( ! strncmp ( V_164 , L_16 , 14 ) ) {
if ( V_163 -> V_175 )
return - V_171 ;
V_163 -> V_175 =
F_129 ( V_164 + 14 , V_176 - 1 , V_88 ) ;
if ( ! V_163 -> V_175 )
return - V_89 ;
continue;
}
if ( ! strncmp ( V_164 , L_17 , 5 ) ) {
const char * V_114 = V_164 + 5 ;
if ( ! strlen ( V_114 ) )
return - V_171 ;
for ( V_63 = 0 ; V_63 < strlen ( V_114 ) ; V_63 ++ ) {
char V_97 = V_114 [ V_63 ] ;
if ( isalnum ( V_97 ) )
continue;
if ( ( V_97 == '.' ) || ( V_97 == '-' ) || ( V_97 == '_' ) )
continue;
return - V_171 ;
}
if ( V_163 -> V_114 )
return - V_171 ;
V_163 -> V_114 = F_129 ( V_114 ,
V_177 - 1 ,
V_88 ) ;
if ( ! V_163 -> V_114 )
return - V_89 ;
continue;
}
F_53 (ss, i) {
if ( strcmp ( V_164 , V_21 -> V_115 ) )
continue;
if ( ! F_1 ( V_63 ) )
continue;
if ( V_166 )
return - V_171 ;
V_163 -> V_24 |= ( 1 << V_63 ) ;
V_167 = true ;
break;
}
if ( V_63 == V_92 )
return - V_178 ;
}
if ( V_163 -> V_29 & V_173 ) {
F_114 ( L_18 ) ;
if ( V_169 != 1 ) {
F_130 ( L_19 ) ;
return - V_171 ;
}
return 0 ;
}
if ( V_166 || ( ! V_167 && ! V_163 -> V_172 && ! V_163 -> V_114 ) )
F_53 (ss, i)
if ( F_1 ( V_63 ) )
V_163 -> V_24 |= ( 1 << V_63 ) ;
if ( ! V_163 -> V_24 && ! V_163 -> V_114 )
return - V_171 ;
if ( ( V_163 -> V_29 & V_112 ) && ( V_163 -> V_24 & V_168 ) )
return - V_171 ;
if ( V_163 -> V_24 && V_163 -> V_172 )
return - V_171 ;
return 0 ;
}
static int F_131 ( struct V_100 * V_101 , int * V_29 , char * V_161 )
{
int V_12 = 0 ;
struct V_84 * V_5 = F_81 ( V_101 ) ;
struct V_162 V_163 ;
unsigned long V_179 , V_180 ;
if ( V_5 == & V_6 ) {
F_130 ( L_20 ) ;
return - V_171 ;
}
F_88 ( & V_23 ) ;
V_12 = F_126 ( V_161 , & V_163 ) ;
if ( V_12 )
goto V_27;
if ( V_163 . V_24 != V_5 -> V_24 || V_163 . V_175 )
F_114 ( L_21 ,
F_132 ( V_181 ) , V_181 -> V_182 ) ;
V_179 = V_163 . V_24 & ~ V_5 -> V_24 ;
V_180 = V_5 -> V_24 & ~ V_163 . V_24 ;
if ( ( V_163 . V_29 ^ V_5 -> V_29 ) ||
( V_163 . V_114 && strcmp ( V_163 . V_114 , V_5 -> V_114 ) ) ) {
F_130 ( L_22 ,
V_163 . V_29 , V_163 . V_114 ? : L_23 , V_5 -> V_29 , V_5 -> V_114 ) ;
V_12 = - V_171 ;
goto V_27;
}
if ( ! F_40 ( & V_5 -> V_4 . V_18 . V_107 ) ) {
V_12 = - V_147 ;
goto V_27;
}
V_12 = F_90 ( V_5 , V_179 ) ;
if ( V_12 )
goto V_27;
F_90 ( & V_6 , V_180 ) ;
if ( V_163 . V_175 ) {
F_124 ( & V_158 ) ;
strcpy ( V_5 -> V_159 , V_163 . V_175 ) ;
F_125 ( & V_158 ) ;
}
V_27:
F_58 ( V_163 . V_175 ) ;
F_58 ( V_163 . V_114 ) ;
F_91 ( & V_23 ) ;
return V_12 ;
}
static void F_133 ( void )
{
struct V_50 * V_183 , * V_184 ;
F_6 ( & V_41 ) ;
if ( V_185 )
goto V_27;
V_185 = true ;
F_134 ( & V_186 ) ;
F_135 (g, p) {
F_28 ( ! F_40 ( & V_183 -> V_58 ) ||
F_95 ( V_183 ) != & V_28 ) ;
F_107 ( & V_183 -> V_187 -> V_188 ) ;
if ( ! ( V_183 -> V_29 & V_60 ) ) {
struct V_39 * V_40 = F_95 ( V_183 ) ;
if ( ! F_39 ( V_40 ) )
F_44 ( V_40 , true ) ;
F_51 ( & V_183 -> V_58 , & V_40 -> V_42 ) ;
F_62 ( V_40 ) ;
}
F_108 ( & V_183 -> V_187 -> V_188 ) ;
} F_136 ( V_184 , V_183 ) ;
F_137 ( & V_186 ) ;
V_27:
F_8 ( & V_41 ) ;
}
static void F_138 ( struct V_3 * V_4 )
{
struct V_20 * V_21 ;
int V_1 ;
F_71 ( & V_4 -> V_18 . V_189 ) ;
F_71 ( & V_4 -> V_18 . V_107 ) ;
F_71 ( & V_4 -> V_91 ) ;
F_71 ( & V_4 -> V_190 ) ;
F_139 ( & V_4 -> V_191 ) ;
V_4 -> V_18 . V_3 = V_4 ;
V_4 -> V_18 . V_29 |= V_30 ;
F_53 (ss, ssid)
F_71 ( & V_4 -> V_99 [ V_1 ] ) ;
F_140 ( & V_4 -> V_192 ) ;
F_141 ( & V_4 -> V_193 , V_194 ) ;
}
static void F_142 ( struct V_84 * V_5 ,
struct V_162 * V_163 )
{
struct V_3 * V_4 = & V_5 -> V_4 ;
F_71 ( & V_5 -> V_108 ) ;
F_78 ( & V_5 -> V_106 , 1 ) ;
V_4 -> V_5 = V_5 ;
F_138 ( V_4 ) ;
F_143 ( & V_5 -> V_105 ) ;
V_5 -> V_29 = V_163 -> V_29 ;
if ( V_163 -> V_175 )
strcpy ( V_5 -> V_159 , V_163 -> V_175 ) ;
if ( V_163 -> V_114 )
strcpy ( V_5 -> V_114 , V_163 -> V_114 ) ;
if ( V_163 -> V_174 )
F_144 ( V_160 , & V_5 -> V_4 . V_29 ) ;
}
static int F_145 ( struct V_84 * V_5 , unsigned long V_144 )
{
F_146 ( V_87 ) ;
struct V_3 * V_102 = & V_5 -> V_4 ;
struct V_39 * V_40 ;
int V_63 , V_12 ;
F_20 ( & V_23 ) ;
V_12 = F_4 ( & V_5 -> V_105 , V_102 , 1 , 2 , V_88 ) ;
if ( V_12 < 0 )
goto V_195;
V_102 -> V_15 = V_12 ;
V_12 = F_147 ( & V_102 -> V_18 . V_196 , V_197 , 0 ,
V_88 ) ;
if ( V_12 )
goto V_195;
V_12 = F_70 ( V_68 , & V_87 ) ;
if ( V_12 )
goto V_198;
V_12 = F_82 ( V_5 ) ;
if ( V_12 )
goto V_198;
V_5 -> V_101 = F_148 ( & V_199 ,
V_200 ,
V_102 ) ;
if ( F_149 ( V_5 -> V_101 ) ) {
V_12 = F_150 ( V_5 -> V_101 ) ;
goto V_201;
}
V_102 -> V_33 = V_5 -> V_101 -> V_33 ;
V_12 = F_112 ( & V_102 -> V_18 , NULL ) ;
if ( V_12 )
goto V_202;
V_12 = F_90 ( V_5 , V_144 ) ;
if ( V_12 )
goto V_202;
F_73 ( & V_5 -> V_108 , & V_203 ) ;
V_93 ++ ;
F_6 ( & V_41 ) ;
F_117 (css_set_table, i, cset, hlist) {
F_74 ( & V_87 , V_40 , V_102 ) ;
if ( F_39 ( V_40 ) )
F_41 ( V_102 , true ) ;
}
F_8 ( & V_41 ) ;
F_65 ( ! F_40 ( & V_102 -> V_18 . V_107 ) ) ;
F_65 ( F_89 ( & V_5 -> V_106 ) != 1 ) ;
F_120 ( V_102 -> V_33 ) ;
V_12 = 0 ;
goto V_195;
V_202:
F_92 ( V_5 -> V_101 ) ;
V_5 -> V_101 = NULL ;
V_201:
F_84 ( V_5 ) ;
V_198:
F_151 ( & V_102 -> V_18 . V_196 ) ;
V_195:
F_69 ( & V_87 ) ;
return V_12 ;
}
static struct V_204 * F_152 ( struct V_205 * V_206 ,
int V_29 , const char * V_207 ,
void * V_161 )
{
struct V_208 * V_209 = NULL ;
struct V_20 * V_21 ;
struct V_84 * V_5 ;
struct V_162 V_163 ;
struct V_204 * V_204 ;
int V_12 ;
int V_63 ;
bool V_210 ;
if ( ! V_185 )
F_133 () ;
F_88 ( & V_23 ) ;
V_12 = F_126 ( V_161 , & V_163 ) ;
if ( V_12 )
goto V_27;
if ( V_163 . V_29 & V_173 ) {
V_151 = true ;
V_5 = & V_6 ;
F_27 ( & V_5 -> V_4 ) ;
V_12 = 0 ;
goto V_27;
}
F_53 (ss, i) {
if ( ! ( V_163 . V_24 & ( 1 << V_63 ) ) ||
V_21 -> V_5 == & V_6 )
continue;
if ( ! F_153 ( & V_21 -> V_5 -> V_4 . V_18 . V_196 ) ) {
F_91 ( & V_23 ) ;
F_154 ( 10 ) ;
V_12 = F_155 () ;
goto V_211;
}
F_31 ( & V_21 -> V_5 -> V_4 ) ;
}
F_156 (root) {
bool V_212 = false ;
if ( V_5 == & V_6 )
continue;
if ( V_163 . V_114 ) {
if ( strcmp ( V_163 . V_114 , V_5 -> V_114 ) )
continue;
V_212 = true ;
}
if ( ( V_163 . V_24 || V_163 . V_172 ) &&
( V_163 . V_24 != V_5 -> V_24 ) ) {
if ( ! V_212 )
continue;
V_12 = - V_147 ;
goto V_27;
}
if ( V_5 -> V_29 ^ V_163 . V_29 )
F_114 ( L_24 ) ;
V_209 = F_157 ( V_5 -> V_101 , NULL ) ;
if ( F_149 ( V_209 ) ||
! F_153 ( & V_5 -> V_4 . V_18 . V_196 ) ) {
F_91 ( & V_23 ) ;
if ( ! F_158 ( V_209 ) )
F_159 ( V_209 ) ;
F_154 ( 10 ) ;
V_12 = F_155 () ;
goto V_211;
}
V_12 = 0 ;
goto V_27;
}
if ( ! V_163 . V_24 && ! V_163 . V_172 ) {
V_12 = - V_171 ;
goto V_27;
}
V_5 = F_72 ( sizeof( * V_5 ) , V_88 ) ;
if ( ! V_5 ) {
V_12 = - V_89 ;
goto V_27;
}
F_142 ( V_5 , & V_163 ) ;
V_12 = F_145 ( V_5 , V_163 . V_24 ) ;
if ( V_12 )
F_85 ( V_5 ) ;
V_27:
F_91 ( & V_23 ) ;
V_211:
F_58 ( V_163 . V_175 ) ;
F_58 ( V_163 . V_114 ) ;
if ( V_12 )
return F_160 ( V_12 ) ;
V_204 = F_161 ( V_206 , V_29 , V_5 -> V_101 ,
V_213 , & V_210 ) ;
if ( F_149 ( V_204 ) || ! V_210 )
F_31 ( & V_5 -> V_4 ) ;
if ( V_209 ) {
F_115 ( V_210 ) ;
F_159 ( V_209 ) ;
}
return V_204 ;
}
static void F_162 ( struct V_208 * V_214 )
{
struct V_100 * V_101 = F_163 ( V_214 ) ;
struct V_84 * V_5 = F_81 ( V_101 ) ;
if ( ! F_40 ( & V_5 -> V_4 . V_18 . V_107 ) ||
V_5 == & V_6 )
F_31 ( & V_5 -> V_4 ) ;
else
F_164 ( & V_5 -> V_4 . V_18 . V_196 ) ;
F_165 ( V_214 ) ;
}
char * F_166 ( struct V_50 * V_51 , char * V_110 , T_3 V_215 )
{
struct V_84 * V_5 ;
struct V_3 * V_4 ;
int V_104 = 1 ;
char * V_216 = NULL ;
F_88 ( & V_23 ) ;
F_6 ( & V_41 ) ;
V_5 = F_167 ( & V_103 , & V_104 ) ;
if ( V_5 ) {
V_4 = F_94 ( V_51 , V_5 ) ;
V_216 = F_168 ( V_4 , V_110 , V_215 ) ;
} else {
if ( F_169 ( V_110 , L_25 , V_215 ) < V_215 )
V_216 = V_110 ;
}
F_8 ( & V_41 ) ;
F_91 ( & V_23 ) ;
return V_216 ;
}
static void F_170 ( struct V_50 * V_51 ,
struct V_217 * V_218 )
{
struct V_39 * V_40 ;
F_20 ( & V_41 ) ;
if ( V_51 -> V_29 & V_60 )
return;
if ( F_40 ( & V_51 -> V_58 ) )
return;
V_40 = F_95 ( V_51 ) ;
if ( ! V_40 -> V_219 )
return;
F_76 ( & V_51 -> V_58 , & V_40 -> V_43 ) ;
if ( F_40 ( & V_40 -> V_95 ) )
F_51 ( & V_40 -> V_95 , & V_218 -> V_220 ) ;
if ( F_40 ( & V_40 -> V_221 -> V_95 ) )
F_76 ( & V_40 -> V_221 -> V_95 ,
& V_218 -> V_222 ) ;
}
struct V_50 * F_171 ( struct V_217 * V_218 ,
struct V_16 * * V_223 )
{
V_218 -> V_224 = F_75 ( V_218 -> V_225 , struct V_39 , V_95 ) ;
V_218 -> V_226 = NULL ;
return F_172 ( V_218 , V_223 ) ;
}
struct V_50 * F_172 ( struct V_217 * V_218 ,
struct V_16 * * V_223 )
{
struct V_39 * V_40 = V_218 -> V_224 ;
struct V_50 * V_51 = V_218 -> V_226 ;
while ( & V_40 -> V_95 != V_218 -> V_225 ) {
if ( ! V_51 )
V_51 = F_75 ( & V_40 -> V_43 ,
struct V_50 , V_58 ) ;
else
V_51 = F_173 ( V_51 , V_58 ) ;
if ( & V_51 -> V_58 != & V_40 -> V_43 ) {
V_218 -> V_224 = V_40 ;
V_218 -> V_226 = V_51 ;
if ( V_40 -> V_221 )
* V_223 = V_40 -> V_221 -> V_22 [ V_218 -> V_1 ] ;
else
* V_223 = V_40 -> V_22 [ V_218 -> V_1 ] ;
return V_51 ;
}
V_40 = F_173 ( V_40 , V_95 ) ;
V_51 = NULL ;
}
return NULL ;
}
static int F_174 ( struct V_217 * V_218 ,
struct V_3 * V_227 )
{
struct V_16 * V_26 , * V_228 = NULL ;
struct V_50 * V_51 , * V_229 ;
struct V_39 * V_40 , * V_230 ;
int V_63 , V_12 ;
if ( F_40 ( & V_218 -> V_220 ) )
return 0 ;
F_175 (css, i, dst_cgrp) {
if ( V_26 -> V_21 -> V_231 ) {
V_218 -> V_1 = V_63 ;
V_12 = V_26 -> V_21 -> V_231 ( V_218 ) ;
if ( V_12 ) {
V_228 = V_26 ;
goto V_232;
}
}
}
F_6 ( & V_41 ) ;
F_45 (cset, &tset->src_csets, mg_node) {
F_47 (task, tmp_task, &cset->mg_tasks, cg_list) {
struct V_39 * V_52 = F_95 ( V_51 ) ;
struct V_39 * V_53 = V_40 -> V_221 ;
F_62 ( V_53 ) ;
F_46 ( V_51 , V_52 , V_53 , true ) ;
F_54 ( V_52 ) ;
}
}
F_8 ( & V_41 ) ;
V_218 -> V_225 = & V_218 -> V_222 ;
F_175 (css, i, dst_cgrp) {
if ( V_26 -> V_21 -> V_233 ) {
V_218 -> V_1 = V_63 ;
V_26 -> V_21 -> V_233 ( V_218 ) ;
}
}
V_12 = 0 ;
goto V_234;
V_232:
F_175 (css, i, dst_cgrp) {
if ( V_26 == V_228 )
break;
if ( V_26 -> V_21 -> V_235 ) {
V_218 -> V_1 = V_63 ;
V_26 -> V_21 -> V_235 ( V_218 ) ;
}
}
V_234:
F_6 ( & V_41 ) ;
F_176 ( & V_218 -> V_222 , & V_218 -> V_220 ) ;
F_47 (cset, tmp_cset, &tset->src_csets, mg_node) {
F_177 ( & V_40 -> V_43 , & V_40 -> V_42 ) ;
F_49 ( & V_40 -> V_95 ) ;
}
F_8 ( & V_41 ) ;
return V_12 ;
}
static void F_178 ( struct V_75 * V_236 )
{
struct V_39 * V_40 , * V_230 ;
F_20 ( & V_23 ) ;
F_6 ( & V_41 ) ;
F_47 (cset, tmp_cset, preloaded_csets, mg_preload_node) {
V_40 -> V_219 = NULL ;
V_40 -> V_221 = NULL ;
F_49 ( & V_40 -> V_94 ) ;
F_54 ( V_40 ) ;
}
F_8 ( & V_41 ) ;
}
static void F_179 ( struct V_39 * V_237 ,
struct V_3 * V_227 ,
struct V_75 * V_236 )
{
struct V_3 * V_238 ;
F_20 ( & V_23 ) ;
F_20 ( & V_41 ) ;
V_238 = F_93 ( V_237 , V_227 -> V_5 ) ;
if ( ! F_40 ( & V_237 -> V_94 ) )
return;
F_115 ( V_237 -> V_219 ) ;
F_115 ( ! F_40 ( & V_237 -> V_43 ) ) ;
F_115 ( ! F_40 ( & V_237 -> V_95 ) ) ;
V_237 -> V_219 = V_238 ;
F_62 ( V_237 ) ;
F_73 ( & V_237 -> V_94 , V_236 ) ;
}
static int F_180 ( struct V_3 * V_227 ,
struct V_75 * V_236 )
{
F_146 ( V_225 ) ;
struct V_39 * V_237 , * V_230 ;
F_20 ( & V_23 ) ;
if ( V_227 && F_3 ( V_227 ) && F_14 ( V_227 ) &&
V_227 -> V_25 )
return - V_147 ;
F_47 (src_cset, tmp_cset, preloaded_csets, mg_preload_node) {
struct V_39 * V_239 ;
V_239 = F_77 ( V_237 ,
V_227 ? : V_237 -> V_90 ) ;
if ( ! V_239 )
goto V_142;
F_28 ( V_237 -> V_221 || V_239 -> V_221 ) ;
if ( V_237 == V_239 ) {
V_237 -> V_219 = NULL ;
F_49 ( & V_237 -> V_94 ) ;
F_60 ( V_237 ) ;
F_60 ( V_239 ) ;
continue;
}
V_237 -> V_221 = V_239 ;
if ( F_40 ( & V_239 -> V_94 ) )
F_73 ( & V_239 -> V_94 , & V_225 ) ;
else
F_60 ( V_239 ) ;
}
F_181 ( & V_225 , V_236 ) ;
return 0 ;
V_142:
F_178 ( & V_225 ) ;
return - V_89 ;
}
static int F_182 ( struct V_50 * V_240 , bool V_241 ,
struct V_3 * V_4 )
{
struct V_217 V_218 = F_183 ( V_218 ) ;
struct V_50 * V_51 ;
F_6 ( & V_41 ) ;
F_22 () ;
V_51 = V_240 ;
do {
F_170 ( V_51 , & V_218 ) ;
if ( ! V_241 )
break;
} while_each_thread(leader, task) ;
int F_184 ( struct V_3 * V_227 ,
struct V_50 * V_240 , bool V_241 )
{
F_146 ( V_236 ) ;
struct V_50 * V_51 ;
int V_12 ;
F_6 ( & V_41 ) ;
F_22 () ;
V_51 = V_240 ;
do {
F_179 ( F_95 ( V_51 ) , V_227 ,
& V_236 ) ;
if ( ! V_241 )
break;
} while_each_thread(leader, task) ;
int F_185 ( struct V_50 * V_51 ,
struct V_3 * V_227 ,
struct V_31 * V_32 )
{
const struct V_242 * V_242 = F_186 () ;
const struct V_242 * V_243 = F_187 ( V_51 ) ;
int V_12 = 0 ;
if ( ! F_188 ( V_242 -> V_244 , V_245 ) &&
! F_188 ( V_242 -> V_244 , V_243 -> V_246 ) &&
! F_188 ( V_242 -> V_244 , V_243 -> V_247 ) )
V_12 = - V_248 ;
if ( ! V_12 && F_3 ( V_227 ) ) {
struct V_208 * V_214 = V_32 -> V_249 -> V_250 . V_204 -> V_251 ;
struct V_3 * V_4 ;
struct V_252 * V_252 ;
F_6 ( & V_41 ) ;
V_4 = F_94 ( V_51 , & V_6 ) ;
F_8 ( & V_41 ) ;
while ( ! F_36 ( V_227 , V_4 ) )
V_4 = F_14 ( V_4 ) ;
V_12 = - V_89 ;
V_252 = F_189 ( V_214 , V_4 -> V_253 . V_33 ) ;
if ( V_252 ) {
V_12 = F_190 ( V_252 , V_254 ) ;
F_191 ( V_252 ) ;
}
}
F_192 ( V_243 ) ;
return V_12 ;
}
static T_4 F_193 ( struct V_31 * V_32 , char * V_110 ,
T_3 V_255 , T_5 V_256 , bool V_241 )
{
struct V_50 * V_257 ;
struct V_3 * V_4 ;
T_6 V_258 ;
int V_12 ;
if ( F_194 ( F_195 ( V_110 ) , 0 , & V_258 ) || V_258 < 0 )
return - V_171 ;
V_4 = F_104 ( V_32 -> V_33 ) ;
if ( ! V_4 )
return - V_259 ;
F_196 ( & V_260 ) ;
F_22 () ;
if ( V_258 ) {
V_257 = F_197 ( V_258 ) ;
if ( ! V_257 ) {
V_12 = - V_261 ;
goto V_262;
}
} else {
V_257 = V_181 ;
}
if ( V_241 )
V_257 = V_257 -> V_263 ;
if ( V_257 == V_264 || ( V_257 -> V_29 & V_265 ) ) {
V_12 = - V_171 ;
goto V_262;
}
F_198 ( V_257 ) ;
F_25 () ;
V_12 = F_185 ( V_257 , V_4 , V_32 ) ;
if ( ! V_12 )
V_12 = F_184 ( V_4 , V_257 , V_241 ) ;
F_199 ( V_257 ) ;
goto V_266;
V_262:
F_25 () ;
V_266:
F_200 ( & V_260 ) ;
F_101 ( V_32 -> V_33 ) ;
return V_12 ? : V_255 ;
}
int F_201 ( struct V_50 * V_267 , struct V_50 * V_257 )
{
struct V_84 * V_5 ;
int V_268 = 0 ;
F_88 ( & V_23 ) ;
F_156 (root) {
struct V_3 * V_269 ;
if ( V_5 == & V_6 )
continue;
F_6 ( & V_41 ) ;
V_269 = F_94 ( V_267 , V_5 ) ;
F_8 ( & V_41 ) ;
V_268 = F_184 ( V_269 , V_257 , false ) ;
if ( V_268 )
break;
}
F_91 ( & V_23 ) ;
return V_268 ;
}
static T_4 F_202 ( struct V_31 * V_32 ,
char * V_110 , T_3 V_255 , T_5 V_256 )
{
return F_193 ( V_32 , V_110 , V_255 , V_256 , false ) ;
}
static T_4 F_203 ( struct V_31 * V_32 ,
char * V_110 , T_3 V_255 , T_5 V_256 )
{
return F_193 ( V_32 , V_110 , V_255 , V_256 , true ) ;
}
static T_4 F_204 ( struct V_31 * V_32 ,
char * V_110 , T_3 V_255 , T_5 V_256 )
{
struct V_3 * V_4 ;
F_205 ( sizeof( V_4 -> V_5 -> V_159 ) < V_176 ) ;
V_4 = F_104 ( V_32 -> V_33 ) ;
if ( ! V_4 )
return - V_259 ;
F_124 ( & V_158 ) ;
F_169 ( V_4 -> V_5 -> V_159 , F_195 ( V_110 ) ,
sizeof( V_4 -> V_5 -> V_159 ) ) ;
F_125 ( & V_158 ) ;
F_101 ( V_32 -> V_33 ) ;
return V_255 ;
}
static int F_206 ( struct V_155 * V_156 , void * V_270 )
{
struct V_3 * V_4 = F_207 ( V_156 ) -> V_3 ;
F_124 ( & V_158 ) ;
F_123 ( V_156 , V_4 -> V_5 -> V_159 ) ;
F_125 ( & V_158 ) ;
F_208 ( V_156 , '\n' ) ;
return 0 ;
}
static int F_209 ( struct V_155 * V_156 , void * V_270 )
{
F_123 ( V_156 , L_26 ) ;
return 0 ;
}
static void F_210 ( struct V_155 * V_156 , unsigned long V_144 )
{
struct V_20 * V_21 ;
bool V_271 = false ;
int V_1 ;
F_99 (ss, ssid, &ss_mask) {
if ( V_271 )
F_208 ( V_156 , ' ' ) ;
F_211 ( V_156 , L_27 , V_21 -> V_114 ) ;
V_271 = true ;
}
if ( V_271 )
F_208 ( V_156 , '\n' ) ;
}
static int F_212 ( struct V_155 * V_156 , void * V_270 )
{
struct V_3 * V_4 = F_207 ( V_156 ) -> V_3 ;
F_210 ( V_156 , V_4 -> V_5 -> V_24 &
~ V_148 ) ;
return 0 ;
}
static int F_213 ( struct V_155 * V_156 , void * V_270 )
{
struct V_3 * V_4 = F_207 ( V_156 ) -> V_3 ;
F_210 ( V_156 , F_14 ( V_4 ) -> V_127 ) ;
return 0 ;
}
static int F_214 ( struct V_155 * V_156 , void * V_270 )
{
struct V_3 * V_4 = F_207 ( V_156 ) -> V_3 ;
F_210 ( V_156 , V_4 -> V_127 ) ;
return 0 ;
}
static int F_215 ( struct V_3 * V_4 )
{
F_146 ( V_236 ) ;
struct V_217 V_218 = F_183 ( V_218 ) ;
struct V_16 * V_26 ;
struct V_39 * V_237 ;
int V_12 ;
F_20 ( & V_23 ) ;
F_196 ( & V_260 ) ;
F_6 ( & V_41 ) ;
F_216 (css, cgroup_css(cgrp, NULL)) {
struct V_48 * V_49 ;
if ( V_26 -> V_3 == V_4 )
continue;
F_45 (link, &css->cgroup->cset_links, cset_link)
F_179 ( V_49 -> V_40 , V_4 ,
& V_236 ) ;
}
F_8 ( & V_41 ) ;
V_12 = F_180 ( NULL , & V_236 ) ;
if ( V_12 )
goto V_272;
F_6 ( & V_41 ) ;
F_45 (src_cset, &preloaded_csets, mg_preload_node) {
struct V_50 * V_51 , * V_273 ;
if ( ! V_237 -> V_219 )
break;
F_47 (task, ntask, &src_cset->tasks, cg_list)
F_170 ( V_51 , & V_218 ) ;
}
F_8 ( & V_41 ) ;
V_12 = F_174 ( & V_218 , V_4 ) ;
V_272:
F_178 ( & V_236 ) ;
F_200 ( & V_260 ) ;
return V_12 ;
}
static T_4 F_217 ( struct V_31 * V_32 ,
char * V_110 , T_3 V_255 ,
T_5 V_256 )
{
unsigned long V_274 = 0 , V_275 = 0 ;
unsigned long V_276 , V_277 , V_278 , V_279 , V_280 , V_281 ;
struct V_3 * V_4 , * V_282 ;
struct V_20 * V_21 ;
char * V_283 ;
int V_1 , V_12 ;
V_110 = F_195 ( V_110 ) ;
while ( ( V_283 = F_128 ( & V_110 , L_28 ) ) ) {
unsigned long V_146 = ~ V_148 ;
if ( V_283 [ 0 ] == '\0' )
continue;
F_99 (ss, ssid, &tmp_ss_mask) {
if ( ! F_1 ( V_1 ) ||
strcmp ( V_283 + 1 , V_21 -> V_114 ) )
continue;
if ( * V_283 == '+' ) {
V_274 |= 1 << V_1 ;
V_275 &= ~ ( 1 << V_1 ) ;
} else if ( * V_283 == '-' ) {
V_275 |= 1 << V_1 ;
V_274 &= ~ ( 1 << V_1 ) ;
} else {
return - V_171 ;
}
break;
}
if ( V_1 == V_92 )
return - V_171 ;
}
V_4 = F_104 ( V_32 -> V_33 ) ;
if ( ! V_4 )
return - V_259 ;
F_53 (ss, ssid) {
if ( V_274 & ( 1 << V_1 ) ) {
if ( V_4 -> V_127 & ( 1 << V_1 ) ) {
V_274 &= ~ ( 1 << V_1 ) ;
continue;
}
if ( ! ( V_6 . V_24 & ( 1 << V_1 ) ) ||
( F_14 ( V_4 ) &&
! ( F_14 ( V_4 ) -> V_127 & ( 1 << V_1 ) ) ) ) {
V_12 = - V_178 ;
goto V_27;
}
} else if ( V_275 & ( 1 << V_1 ) ) {
if ( ! ( V_4 -> V_127 & ( 1 << V_1 ) ) ) {
V_275 &= ~ ( 1 << V_1 ) ;
continue;
}
F_218 (child, cgrp) {
if ( V_282 -> V_127 & ( 1 << V_1 ) ) {
V_12 = - V_147 ;
goto V_27;
}
}
}
}
if ( ! V_274 && ! V_275 ) {
V_12 = 0 ;
goto V_27;
}
if ( V_274 && F_14 ( V_4 ) && ! F_40 ( & V_4 -> V_91 ) ) {
V_12 = - V_147 ;
goto V_27;
}
V_278 = V_4 -> V_127 ;
V_280 = V_4 -> V_25 ;
V_279 = ( V_278 | V_274 ) & ~ V_275 ;
V_281 = F_98 ( V_4 , V_279 ) ;
V_276 = ~ V_280 & V_281 ;
V_277 = V_280 & ~ V_281 ;
V_274 |= V_276 ;
V_275 |= V_277 ;
F_99 (ss, ssid, &css_enable) {
F_218 (child, cgrp) {
F_219 ( V_284 ) ;
if ( ! F_16 ( V_282 , V_21 ) )
continue;
F_27 ( V_282 ) ;
F_220 ( & V_282 -> V_192 , & V_284 ,
V_285 ) ;
F_101 ( V_32 -> V_33 ) ;
F_221 () ;
F_222 ( & V_282 -> V_192 , & V_284 ) ;
F_31 ( V_282 ) ;
return F_155 () ;
}
}
V_4 -> V_127 = V_279 ;
V_4 -> V_25 = V_281 ;
F_53 (ss, ssid) {
if ( ! ( V_274 & ( 1 << V_1 ) ) )
continue;
F_218 (child, cgrp) {
if ( V_276 & ( 1 << V_1 ) )
V_12 = F_223 ( V_282 , V_21 ,
V_4 -> V_127 & ( 1 << V_1 ) ) ;
else
V_12 = F_112 ( F_16 ( V_282 , V_21 ) ,
NULL ) ;
if ( V_12 )
goto V_286;
}
}
V_12 = F_215 ( V_4 ) ;
if ( V_12 )
goto V_286;
F_53 (ss, ssid) {
if ( ! ( V_275 & ( 1 << V_1 ) ) )
continue;
F_218 (child, cgrp) {
struct V_16 * V_26 = F_16 ( V_282 , V_21 ) ;
if ( V_277 & ( 1 << V_1 ) ) {
F_224 ( V_26 ) ;
} else {
F_110 ( V_26 , NULL ) ;
if ( V_21 -> V_287 )
V_21 -> V_287 ( V_26 ) ;
}
}
}
F_53 (ss, ssid) {
struct V_16 * V_288 = F_16 ( V_4 , V_21 ) ;
struct V_16 * V_26 ;
if ( ! V_21 -> V_289 || ! V_288 )
continue;
F_216 (css, this_css)
if ( V_26 != V_288 )
V_21 -> V_289 ( V_26 ) ;
}
F_120 ( V_4 -> V_33 ) ;
V_12 = 0 ;
V_27:
F_101 ( V_32 -> V_33 ) ;
return V_12 ? : V_255 ;
V_286:
V_4 -> V_127 = V_278 ;
V_4 -> V_25 = V_280 ;
F_53 (ss, ssid) {
if ( ! ( V_274 & ( 1 << V_1 ) ) )
continue;
F_218 (child, cgrp) {
struct V_16 * V_26 = F_16 ( V_282 , V_21 ) ;
if ( ! V_26 )
continue;
if ( V_276 & ( 1 << V_1 ) )
F_224 ( V_26 ) ;
else
F_110 ( V_26 , NULL ) ;
}
}
goto V_27;
}
static int F_225 ( struct V_155 * V_156 , void * V_270 )
{
F_211 ( V_156 , L_29 ,
F_226 ( F_207 ( V_156 ) -> V_3 ) ) ;
return 0 ;
}
static T_4 F_227 ( struct V_31 * V_32 , char * V_110 ,
T_3 V_255 , T_5 V_256 )
{
struct V_3 * V_4 = V_32 -> V_33 -> V_19 -> V_34 ;
struct V_35 * V_36 = V_32 -> V_33 -> V_34 ;
struct V_16 * V_26 ;
int V_12 ;
if ( V_36 -> V_123 )
return V_36 -> V_123 ( V_32 , V_110 , V_255 , V_256 ) ;
F_22 () ;
V_26 = F_16 ( V_4 , V_36 -> V_21 ) ;
F_25 () ;
if ( V_36 -> V_121 ) {
unsigned long long V_270 ;
V_12 = F_228 ( V_110 , 0 , & V_270 ) ;
if ( ! V_12 )
V_12 = V_36 -> V_121 ( V_26 , V_36 , V_270 ) ;
} else if ( V_36 -> V_122 ) {
long long V_270 ;
V_12 = F_229 ( V_110 , 0 , & V_270 ) ;
if ( ! V_12 )
V_12 = V_36 -> V_122 ( V_26 , V_36 , V_270 ) ;
} else {
V_12 = - V_171 ;
}
return V_12 ? : V_255 ;
}
static void * F_230 ( struct V_155 * V_156 , T_5 * V_290 )
{
return F_231 ( V_156 ) -> F_232 ( V_156 , V_290 ) ;
}
static void * F_233 ( struct V_155 * V_156 , void * V_270 , T_5 * V_290 )
{
return F_231 ( V_156 ) -> F_234 ( V_156 , V_270 , V_290 ) ;
}
static void F_235 ( struct V_155 * V_156 , void * V_270 )
{
F_231 ( V_156 ) -> F_236 ( V_156 , V_270 ) ;
}
static int F_237 ( struct V_155 * V_291 , void * V_292 )
{
struct V_35 * V_36 = F_231 ( V_291 ) ;
struct V_16 * V_26 = F_207 ( V_291 ) ;
if ( V_36 -> V_119 )
return V_36 -> V_119 ( V_291 , V_292 ) ;
if ( V_36 -> V_117 )
F_211 ( V_291 , L_30 , V_36 -> V_117 ( V_26 , V_36 ) ) ;
else if ( V_36 -> V_118 )
F_211 ( V_291 , L_31 , V_36 -> V_118 ( V_26 , V_36 ) ) ;
else
return - V_171 ;
return 0 ;
}
static int F_238 ( struct V_131 * V_33 , struct V_131 * V_293 ,
const char * V_294 )
{
struct V_3 * V_4 = V_33 -> V_34 ;
int V_12 ;
if ( F_102 ( V_33 ) != V_132 )
return - V_295 ;
if ( V_33 -> V_19 != V_293 )
return - V_296 ;
if ( F_3 ( V_4 ) )
return - V_297 ;
F_105 ( V_293 ) ;
F_105 ( V_33 ) ;
F_88 ( & V_23 ) ;
V_12 = F_239 ( V_33 , V_293 , V_294 ) ;
F_91 ( & V_23 ) ;
F_103 ( V_33 ) ;
F_103 ( V_293 ) ;
return V_12 ;
}
static int F_240 ( struct V_131 * V_33 )
{
struct V_298 V_298 = { . V_299 = V_300 | V_301 ,
. V_302 = F_241 () ,
. V_303 = F_242 () , } ;
if ( F_188 ( V_298 . V_302 , V_245 ) &&
F_243 ( V_298 . V_303 , V_304 ) )
return 0 ;
return F_244 ( V_33 , & V_298 ) ;
}
static int F_245 ( struct V_16 * V_26 , struct V_3 * V_4 ,
struct V_35 * V_36 )
{
char V_114 [ V_113 ] ;
struct V_131 * V_33 ;
struct V_305 * V_62 = NULL ;
int V_12 ;
#ifdef F_246
V_62 = & V_36 -> V_306 ;
#endif
V_33 = F_247 ( V_4 -> V_33 , F_96 ( V_4 , V_36 , V_114 ) ,
F_97 ( V_36 ) , 0 , V_36 -> V_307 , V_36 ,
NULL , V_62 ) ;
if ( F_149 ( V_33 ) )
return F_150 ( V_33 ) ;
V_12 = F_240 ( V_33 ) ;
if ( V_12 ) {
F_248 ( V_33 ) ;
return V_12 ;
}
if ( V_36 -> V_133 ) {
struct V_134 * V_135 = ( void * ) V_26 + V_36 -> V_133 ;
F_107 ( & V_136 ) ;
V_135 -> V_33 = V_33 ;
F_108 ( & V_136 ) ;
}
return 0 ;
}
static int F_111 ( struct V_16 * V_26 ,
struct V_3 * V_4 , struct V_35 V_138 [] ,
bool V_308 )
{
struct V_35 * V_36 , * V_309 = NULL ;
int V_12 ;
F_20 ( & V_23 ) ;
V_310:
for ( V_36 = V_138 ; V_36 != V_309 && V_36 -> V_114 [ 0 ] != '\0' ; V_36 ++ ) {
if ( ( V_36 -> V_29 & V_311 ) && ! F_3 ( V_4 ) )
continue;
if ( ( V_36 -> V_29 & V_312 ) && F_3 ( V_4 ) )
continue;
if ( ( V_36 -> V_29 & V_313 ) && ! F_14 ( V_4 ) )
continue;
if ( ( V_36 -> V_29 & V_314 ) && F_14 ( V_4 ) )
continue;
if ( V_308 ) {
V_12 = F_245 ( V_26 , V_4 , V_36 ) ;
if ( V_12 ) {
F_114 ( L_32 ,
V_315 , V_36 -> V_114 , V_12 ) ;
V_309 = V_36 ;
V_308 = false ;
goto V_310;
}
} else {
F_106 ( V_4 , V_36 ) ;
}
}
return 0 ;
}
static int F_249 ( struct V_35 * V_138 , bool V_308 )
{
F_146 ( V_316 ) ;
struct V_20 * V_21 = V_138 [ 0 ] . V_21 ;
struct V_3 * V_5 = & V_21 -> V_5 -> V_4 ;
struct V_16 * V_26 ;
int V_12 = 0 ;
F_20 ( & V_23 ) ;
F_216 (css, cgroup_css(root, ss)) {
struct V_3 * V_4 = V_26 -> V_3 ;
if ( F_26 ( V_4 ) )
continue;
V_12 = F_111 ( V_26 , V_4 , V_138 , V_308 ) ;
if ( V_12 )
break;
}
if ( V_308 && ! V_12 )
F_120 ( V_5 -> V_33 ) ;
return V_12 ;
}
static void F_250 ( struct V_35 * V_138 )
{
struct V_35 * V_36 ;
for ( V_36 = V_138 ; V_36 -> V_114 [ 0 ] != '\0' ; V_36 ++ ) {
if ( V_36 -> V_317 && V_36 -> V_317 != V_318 )
F_58 ( V_36 -> V_307 ) ;
V_36 -> V_307 = NULL ;
V_36 -> V_21 = NULL ;
V_36 -> V_29 &= ~ ( V_311 | V_312 ) ;
}
}
static int F_251 ( struct V_20 * V_21 , struct V_35 * V_138 )
{
struct V_35 * V_36 ;
for ( V_36 = V_138 ; V_36 -> V_114 [ 0 ] != '\0' ; V_36 ++ ) {
struct V_319 * V_307 ;
F_115 ( V_36 -> V_21 || V_36 -> V_307 ) ;
if ( V_36 -> F_232 )
V_307 = & V_320 ;
else
V_307 = & V_321 ;
if ( V_36 -> V_317 && V_36 -> V_317 != V_318 ) {
V_307 = F_252 ( V_307 , sizeof( * V_307 ) , V_88 ) ;
if ( ! V_307 ) {
F_250 ( V_138 ) ;
return - V_89 ;
}
V_307 -> V_322 = V_36 -> V_317 ;
}
V_36 -> V_307 = V_307 ;
V_36 -> V_21 = V_21 ;
}
return 0 ;
}
static int F_253 ( struct V_35 * V_138 )
{
F_20 ( & V_23 ) ;
if ( ! V_138 || ! V_138 [ 0 ] . V_21 )
return - V_178 ;
F_56 ( & V_138 -> V_323 ) ;
F_249 ( V_138 , false ) ;
F_250 ( V_138 ) ;
return 0 ;
}
int F_254 ( struct V_35 * V_138 )
{
int V_12 ;
F_88 ( & V_23 ) ;
V_12 = F_253 ( V_138 ) ;
F_91 ( & V_23 ) ;
return V_12 ;
}
static int F_255 ( struct V_20 * V_21 , struct V_35 * V_138 )
{
int V_12 ;
if ( ! F_1 ( V_21 -> V_15 ) )
return 0 ;
if ( ! V_138 || V_138 [ 0 ] . V_114 [ 0 ] == '\0' )
return 0 ;
V_12 = F_251 ( V_21 , V_138 ) ;
if ( V_12 )
return V_12 ;
F_88 ( & V_23 ) ;
F_51 ( & V_138 -> V_323 , & V_21 -> V_138 ) ;
V_12 = F_249 ( V_138 , true ) ;
if ( V_12 )
F_253 ( V_138 ) ;
F_91 ( & V_23 ) ;
return V_12 ;
}
int F_256 ( struct V_20 * V_21 , struct V_35 * V_138 )
{
struct V_35 * V_36 ;
for ( V_36 = V_138 ; V_36 && V_36 -> V_114 [ 0 ] != '\0' ; V_36 ++ )
V_36 -> V_29 |= V_311 ;
return F_255 ( V_21 , V_138 ) ;
}
int F_257 ( struct V_20 * V_21 , struct V_35 * V_138 )
{
struct V_35 * V_36 ;
for ( V_36 = V_138 ; V_36 && V_36 -> V_114 [ 0 ] != '\0' ; V_36 ++ )
V_36 -> V_29 |= V_312 ;
return F_255 ( V_21 , V_138 ) ;
}
void F_43 ( struct V_134 * V_135 )
{
unsigned long V_29 ;
F_258 ( & V_136 , V_29 ) ;
if ( V_135 -> V_33 )
F_259 ( V_135 -> V_33 ) ;
F_260 ( & V_136 , V_29 ) ;
}
static int F_261 ( const struct V_3 * V_4 )
{
int V_86 = 0 ;
struct V_48 * V_49 ;
F_6 ( & V_41 ) ;
F_45 (link, &cgrp->cset_links, cset_link)
V_86 += F_89 ( & V_49 -> V_40 -> V_65 ) ;
F_8 ( & V_41 ) ;
return V_86 ;
}
struct V_16 * F_113 ( struct V_16 * V_57 ,
struct V_16 * V_19 )
{
struct V_16 * V_83 ;
F_262 () ;
if ( ! V_57 ) {
V_83 = F_263 ( V_19 -> V_107 . V_83 , struct V_16 , V_189 ) ;
} else if ( F_264 ( ! ( V_57 -> V_29 & V_324 ) ) ) {
V_83 = F_263 ( V_57 -> V_189 . V_83 , struct V_16 , V_189 ) ;
} else {
F_265 (next, &parent->children, sibling)
if ( V_83 -> V_325 > V_57 -> V_325 )
break;
}
if ( & V_83 -> V_189 != & V_19 -> V_107 )
return V_83 ;
return NULL ;
}
struct V_16 *
F_266 ( struct V_16 * V_57 ,
struct V_16 * V_5 )
{
struct V_16 * V_83 ;
F_262 () ;
if ( ! V_57 )
return V_5 ;
V_83 = F_113 ( NULL , V_57 ) ;
if ( V_83 )
return V_83 ;
while ( V_57 != V_5 ) {
V_83 = F_113 ( V_57 , V_57 -> V_19 ) ;
if ( V_83 )
return V_83 ;
V_57 = V_57 -> V_19 ;
}
return NULL ;
}
struct V_16 *
F_267 ( struct V_16 * V_57 )
{
struct V_16 * V_326 , * V_327 ;
F_262 () ;
do {
V_326 = V_57 ;
V_57 = NULL ;
F_268 (tmp, last)
V_57 = V_327 ;
} while ( V_57 );
return V_326 ;
}
static struct V_16 *
F_269 ( struct V_16 * V_57 )
{
struct V_16 * V_326 ;
do {
V_326 = V_57 ;
V_57 = F_113 ( NULL , V_57 ) ;
} while ( V_57 );
return V_326 ;
}
struct V_16 *
F_270 ( struct V_16 * V_57 ,
struct V_16 * V_5 )
{
struct V_16 * V_83 ;
F_262 () ;
if ( ! V_57 )
return F_269 ( V_5 ) ;
if ( V_57 == V_5 )
return NULL ;
V_83 = F_113 ( V_57 , V_57 -> V_19 ) ;
if ( V_83 )
return F_269 ( V_83 ) ;
return V_57 -> V_19 ;
}
bool F_271 ( struct V_16 * V_26 )
{
struct V_16 * V_282 ;
bool V_12 = false ;
F_22 () ;
F_268 (child, css) {
if ( V_282 -> V_29 & V_30 ) {
V_12 = true ;
break;
}
}
F_25 () ;
return V_12 ;
}
static void F_272 ( struct V_55 * V_56 )
{
struct V_75 * V_328 = V_56 -> V_329 ;
struct V_48 * V_49 ;
struct V_39 * V_40 ;
F_20 ( & V_41 ) ;
do {
V_328 = V_328 -> V_83 ;
if ( V_328 == V_56 -> V_330 ) {
V_56 -> V_329 = NULL ;
V_56 -> V_59 = NULL ;
return;
}
if ( V_56 -> V_21 ) {
V_40 = F_15 ( V_328 , struct V_39 ,
V_66 [ V_56 -> V_21 -> V_15 ] ) ;
} else {
V_49 = F_66 ( V_328 , struct V_48 , V_69 ) ;
V_40 = V_49 -> V_40 ;
}
} while ( ! F_39 ( V_40 ) );
V_56 -> V_329 = V_328 ;
if ( ! F_40 ( & V_40 -> V_42 ) )
V_56 -> V_59 = V_40 -> V_42 . V_83 ;
else
V_56 -> V_59 = V_40 -> V_43 . V_83 ;
V_56 -> V_331 = & V_40 -> V_42 ;
V_56 -> V_332 = & V_40 -> V_43 ;
if ( V_56 -> V_224 ) {
F_56 ( & V_56 -> V_333 ) ;
F_54 ( V_56 -> V_224 ) ;
}
F_62 ( V_40 ) ;
V_56 -> V_224 = V_40 ;
F_73 ( & V_56 -> V_333 , & V_40 -> V_96 ) ;
}
static void F_48 ( struct V_55 * V_56 )
{
struct V_75 * V_328 = V_56 -> V_59 ;
F_20 ( & V_41 ) ;
F_28 ( ! V_328 ) ;
V_328 = V_328 -> V_83 ;
if ( V_328 == V_56 -> V_331 )
V_328 = V_56 -> V_332 -> V_83 ;
if ( V_328 == V_56 -> V_332 )
F_272 ( V_56 ) ;
else
V_56 -> V_59 = V_328 ;
}
void F_273 ( struct V_16 * V_26 ,
struct V_55 * V_56 )
{
F_28 ( ! V_185 ) ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
F_6 ( & V_41 ) ;
V_56 -> V_21 = V_26 -> V_21 ;
if ( V_56 -> V_21 )
V_56 -> V_329 = & V_26 -> V_3 -> V_99 [ V_26 -> V_21 -> V_15 ] ;
else
V_56 -> V_329 = & V_26 -> V_3 -> V_91 ;
V_56 -> V_330 = V_56 -> V_329 ;
F_272 ( V_56 ) ;
F_8 ( & V_41 ) ;
}
struct V_50 * F_274 ( struct V_55 * V_56 )
{
if ( V_56 -> V_226 ) {
F_199 ( V_56 -> V_226 ) ;
V_56 -> V_226 = NULL ;
}
F_6 ( & V_41 ) ;
if ( V_56 -> V_59 ) {
V_56 -> V_226 = F_66 ( V_56 -> V_59 , struct V_50 ,
V_58 ) ;
F_198 ( V_56 -> V_226 ) ;
F_48 ( V_56 ) ;
}
F_8 ( & V_41 ) ;
return V_56 -> V_226 ;
}
void F_275 ( struct V_55 * V_56 )
{
if ( V_56 -> V_224 ) {
F_6 ( & V_41 ) ;
F_56 ( & V_56 -> V_333 ) ;
F_54 ( V_56 -> V_224 ) ;
F_8 ( & V_41 ) ;
}
if ( V_56 -> V_226 )
F_199 ( V_56 -> V_226 ) ;
}
int F_276 ( struct V_3 * V_334 , struct V_3 * V_267 )
{
F_146 ( V_236 ) ;
struct V_48 * V_49 ;
struct V_55 V_56 ;
struct V_50 * V_51 ;
int V_12 ;
F_88 ( & V_23 ) ;
F_6 ( & V_41 ) ;
F_45 (link, &from->cset_links, cset_link)
F_179 ( V_49 -> V_40 , V_334 , & V_236 ) ;
F_8 ( & V_41 ) ;
V_12 = F_180 ( V_334 , & V_236 ) ;
if ( V_12 )
goto V_335;
do {
F_273 ( & V_267 -> V_18 , & V_56 ) ;
V_51 = F_274 ( & V_56 ) ;
if ( V_51 )
F_198 ( V_51 ) ;
F_275 ( & V_56 ) ;
if ( V_51 ) {
V_12 = F_182 ( V_51 , false , V_334 ) ;
F_199 ( V_51 ) ;
}
} while ( V_51 && ! V_12 );
V_335:
F_178 ( & V_236 ) ;
F_91 ( & V_23 ) ;
return V_12 ;
}
static void * F_277 ( int V_86 )
{
if ( F_278 ( V_86 ) )
return F_279 ( V_86 * sizeof( T_6 ) ) ;
else
return F_280 ( V_86 * sizeof( T_6 ) , V_88 ) ;
}
static void F_281 ( void * V_183 )
{
F_282 ( V_183 ) ;
}
static void F_283 ( struct V_3 * V_4 )
{
struct V_336 * V_328 , * V_337 ;
F_88 ( & V_4 -> V_191 ) ;
F_47 (l, tmp_l, &cgrp->pidlists, links)
F_284 ( V_338 , & V_328 -> V_339 , 0 ) ;
F_91 ( & V_4 -> V_191 ) ;
F_285 ( V_338 ) ;
F_65 ( ! F_40 ( & V_4 -> V_190 ) ) ;
}
static void F_286 ( struct V_340 * V_341 )
{
struct V_342 * V_343 = F_287 ( V_341 ) ;
struct V_336 * V_328 = F_15 ( V_343 , struct V_336 ,
V_339 ) ;
struct V_336 * V_344 = NULL ;
F_88 ( & V_328 -> V_345 -> V_191 ) ;
if ( ! F_288 ( V_343 ) ) {
F_56 ( & V_328 -> V_346 ) ;
F_281 ( V_328 -> V_347 ) ;
F_289 ( V_328 -> V_62 . V_348 ) ;
V_344 = V_328 ;
}
F_91 ( & V_328 -> V_345 -> V_191 ) ;
F_58 ( V_344 ) ;
}
static int F_290 ( T_6 * V_347 , int V_349 )
{
int V_350 , V_351 = 1 ;
if ( V_349 == 0 || V_349 == 1 )
return V_349 ;
for ( V_350 = 1 ; V_350 < V_349 ; V_350 ++ ) {
while ( V_347 [ V_350 ] == V_347 [ V_350 - 1 ] ) {
V_350 ++ ;
if ( V_350 == V_349 )
goto V_352;
}
V_347 [ V_351 ] = V_347 [ V_350 ] ;
V_351 ++ ;
}
V_352:
return V_351 ;
}
static T_6 F_291 ( T_6 V_258 )
{
unsigned V_353 = V_258 & 0x55555555 ;
unsigned V_354 = V_258 & 0xAAAAAAAA ;
return ( V_353 << 1 ) | ( V_354 >> 1 ) ;
}
static T_6 F_292 ( struct V_3 * V_4 , T_6 V_258 )
{
if ( F_3 ( V_4 ) )
return F_291 ( V_258 ) ;
else
return V_258 ;
}
static int F_293 ( const void * V_353 , const void * V_354 )
{
return * ( T_6 * ) V_353 - * ( T_6 * ) V_354 ;
}
static int F_294 ( const void * V_353 , const void * V_354 )
{
return F_291 ( * ( T_6 * ) V_353 ) - F_291 ( * ( T_6 * ) V_354 ) ;
}
static struct V_336 * F_295 ( struct V_3 * V_4 ,
enum V_355 type )
{
struct V_336 * V_328 ;
struct V_356 * V_348 = F_296 ( V_181 ) ;
F_20 ( & V_4 -> V_191 ) ;
F_45 (l, &cgrp->pidlists, links)
if ( V_328 -> V_62 . type == type && V_328 -> V_62 . V_348 == V_348 )
return V_328 ;
return NULL ;
}
static struct V_336 * F_297 ( struct V_3 * V_4 ,
enum V_355 type )
{
struct V_336 * V_328 ;
F_20 ( & V_4 -> V_191 ) ;
V_328 = F_295 ( V_4 , type ) ;
if ( V_328 )
return V_328 ;
V_328 = F_72 ( sizeof( struct V_336 ) , V_88 ) ;
if ( ! V_328 )
return V_328 ;
F_298 ( & V_328 -> V_339 , F_286 ) ;
V_328 -> V_62 . type = type ;
V_328 -> V_62 . V_348 = F_299 ( F_296 ( V_181 ) ) ;
V_328 -> V_345 = V_4 ;
F_73 ( & V_328 -> V_346 , & V_4 -> V_190 ) ;
return V_328 ;
}
static int F_300 ( struct V_3 * V_4 , enum V_355 type ,
struct V_336 * * V_357 )
{
T_6 * V_358 ;
int V_349 ;
int V_258 , V_359 = 0 ;
struct V_55 V_56 ;
struct V_50 * V_257 ;
struct V_336 * V_328 ;
F_20 ( & V_4 -> V_191 ) ;
V_349 = F_261 ( V_4 ) ;
V_358 = F_277 ( V_349 ) ;
if ( ! V_358 )
return - V_89 ;
F_273 ( & V_4 -> V_18 , & V_56 ) ;
while ( ( V_257 = F_274 ( & V_56 ) ) ) {
if ( F_301 ( V_359 == V_349 ) )
break;
if ( type == V_360 )
V_258 = F_302 ( V_257 ) ;
else
V_258 = F_303 ( V_257 ) ;
if ( V_258 > 0 )
V_358 [ V_359 ++ ] = V_258 ;
}
F_275 ( & V_56 ) ;
V_349 = V_359 ;
if ( F_3 ( V_4 ) )
F_304 ( V_358 , V_349 , sizeof( T_6 ) , F_294 , NULL ) ;
else
F_304 ( V_358 , V_349 , sizeof( T_6 ) , F_293 , NULL ) ;
if ( type == V_360 )
V_349 = F_290 ( V_358 , V_349 ) ;
V_328 = F_297 ( V_4 , type ) ;
if ( ! V_328 ) {
F_281 ( V_358 ) ;
return - V_89 ;
}
F_281 ( V_328 -> V_347 ) ;
V_328 -> V_347 = V_358 ;
V_328 -> V_349 = V_349 ;
* V_357 = V_328 ;
return 0 ;
}
int F_305 ( struct V_361 * V_362 , struct V_204 * V_204 )
{
struct V_131 * V_33 = F_306 ( V_204 ) ;
struct V_3 * V_4 ;
struct V_55 V_56 ;
struct V_50 * V_257 ;
if ( V_204 -> V_251 -> V_363 != & V_364 || ! V_33 ||
F_102 ( V_33 ) != V_132 )
return - V_171 ;
F_88 ( & V_23 ) ;
F_22 () ;
V_4 = F_307 ( V_33 -> V_34 ) ;
if ( ! V_4 || F_26 ( V_4 ) ) {
F_25 () ;
F_91 ( & V_23 ) ;
return - V_178 ;
}
F_25 () ;
F_273 ( & V_4 -> V_18 , & V_56 ) ;
while ( ( V_257 = F_274 ( & V_56 ) ) ) {
switch ( V_257 -> V_365 ) {
case V_366 :
V_362 -> V_367 ++ ;
break;
case V_368 :
V_362 -> V_369 ++ ;
break;
case V_285 :
V_362 -> V_370 ++ ;
break;
case V_371 :
V_362 -> V_372 ++ ;
break;
default:
if ( F_308 ( V_257 ) )
V_362 -> V_373 ++ ;
break;
}
}
F_275 ( & V_56 ) ;
F_91 ( & V_23 ) ;
return 0 ;
}
static void * F_309 ( struct V_155 * V_374 , T_5 * V_57 )
{
struct V_31 * V_32 = V_374 -> V_375 ;
struct V_3 * V_4 = F_207 ( V_374 ) -> V_3 ;
struct V_336 * V_328 ;
enum V_355 type = F_231 ( V_374 ) -> V_375 ;
int V_376 = 0 , V_258 = * V_57 ;
int * V_377 , V_12 ;
F_88 ( & V_4 -> V_191 ) ;
if ( V_32 -> V_34 )
V_32 -> V_34 = F_295 ( V_4 , type ) ;
if ( ! V_32 -> V_34 ) {
V_12 = F_300 ( V_4 , type ,
(struct V_336 * * ) & V_32 -> V_34 ) ;
if ( V_12 )
return F_160 ( V_12 ) ;
}
V_328 = V_32 -> V_34 ;
if ( V_258 ) {
int V_10 = V_328 -> V_349 ;
while ( V_376 < V_10 ) {
int V_378 = ( V_376 + V_10 ) / 2 ;
if ( F_292 ( V_4 , V_328 -> V_347 [ V_378 ] ) == V_258 ) {
V_376 = V_378 ;
break;
} else if ( F_292 ( V_4 , V_328 -> V_347 [ V_378 ] ) <= V_258 )
V_376 = V_378 + 1 ;
else
V_10 = V_378 ;
}
}
if ( V_376 >= V_328 -> V_349 )
return NULL ;
V_377 = V_328 -> V_347 + V_376 ;
* V_57 = F_292 ( V_4 , * V_377 ) ;
return V_377 ;
}
static void F_310 ( struct V_155 * V_374 , void * V_270 )
{
struct V_31 * V_32 = V_374 -> V_375 ;
struct V_336 * V_328 = V_32 -> V_34 ;
if ( V_328 )
F_284 ( V_338 , & V_328 -> V_339 ,
V_379 ) ;
F_91 ( & F_207 ( V_374 ) -> V_3 -> V_191 ) ;
}
static void * F_311 ( struct V_155 * V_374 , void * V_270 , T_5 * V_57 )
{
struct V_31 * V_32 = V_374 -> V_375 ;
struct V_336 * V_328 = V_32 -> V_34 ;
T_6 * V_183 = V_270 ;
T_6 * V_10 = V_328 -> V_347 + V_328 -> V_349 ;
V_183 ++ ;
if ( V_183 >= V_10 ) {
return NULL ;
} else {
* V_57 = F_292 ( F_207 ( V_374 ) -> V_3 , * V_183 ) ;
return V_183 ;
}
}
static int F_312 ( struct V_155 * V_374 , void * V_270 )
{
F_211 ( V_374 , L_33 , * ( int * ) V_270 ) ;
return 0 ;
}
static T_7 F_313 ( struct V_16 * V_26 ,
struct V_35 * V_36 )
{
return F_37 ( V_26 -> V_3 ) ;
}
static int F_314 ( struct V_16 * V_26 ,
struct V_35 * V_36 , T_7 V_380 )
{
if ( V_380 )
F_144 ( V_38 , & V_26 -> V_3 -> V_29 ) ;
else
F_315 ( V_38 , & V_26 -> V_3 -> V_29 ) ;
return 0 ;
}
static T_7 F_316 ( struct V_16 * V_26 ,
struct V_35 * V_36 )
{
return F_38 ( V_160 , & V_26 -> V_3 -> V_29 ) ;
}
static int F_317 ( struct V_16 * V_26 ,
struct V_35 * V_36 , T_7 V_380 )
{
if ( V_380 )
F_144 ( V_160 , & V_26 -> V_3 -> V_29 ) ;
else
F_315 ( V_160 , & V_26 -> V_3 -> V_29 ) ;
return 0 ;
}
static void F_318 ( struct V_340 * V_341 )
{
struct V_16 * V_26 =
F_15 ( V_341 , struct V_16 , V_381 ) ;
struct V_20 * V_21 = V_26 -> V_21 ;
struct V_3 * V_4 = V_26 -> V_3 ;
F_151 ( & V_26 -> V_196 ) ;
if ( V_21 ) {
int V_15 = V_26 -> V_15 ;
if ( V_26 -> V_19 )
F_32 ( V_26 -> V_19 ) ;
V_21 -> V_382 ( V_26 ) ;
F_12 ( & V_21 -> V_383 , V_15 ) ;
F_31 ( V_4 ) ;
} else {
F_319 ( & V_4 -> V_5 -> V_106 ) ;
F_283 ( V_4 ) ;
F_320 ( & V_4 -> V_193 ) ;
if ( F_14 ( V_4 ) ) {
F_31 ( F_14 ( V_4 ) ) ;
F_321 ( V_4 -> V_33 ) ;
F_58 ( V_4 ) ;
} else {
F_87 ( V_4 -> V_5 ) ;
}
}
}
static void F_322 ( struct V_71 * V_71 )
{
struct V_16 * V_26 =
F_15 ( V_71 , struct V_16 , V_71 ) ;
F_141 ( & V_26 -> V_381 , F_318 ) ;
F_323 ( V_384 , & V_26 -> V_381 ) ;
}
static void F_324 ( struct V_340 * V_341 )
{
struct V_16 * V_26 =
F_15 ( V_341 , struct V_16 , V_381 ) ;
struct V_20 * V_21 = V_26 -> V_21 ;
struct V_3 * V_4 = V_26 -> V_3 ;
F_88 ( & V_23 ) ;
V_26 -> V_29 |= V_324 ;
F_325 ( & V_26 -> V_189 ) ;
if ( V_21 ) {
F_10 ( & V_21 -> V_383 , NULL , V_26 -> V_15 ) ;
if ( V_21 -> V_385 )
V_21 -> V_385 ( V_26 ) ;
} else {
F_12 ( & V_4 -> V_5 -> V_105 , V_4 -> V_15 ) ;
V_4 -> V_15 = - 1 ;
F_116 ( * ( void V_386 V_387 * * ) & V_4 -> V_33 -> V_34 , NULL ) ;
}
F_91 ( & V_23 ) ;
F_326 ( & V_26 -> V_71 , F_322 ) ;
}
static void V_197 ( struct V_388 * V_389 )
{
struct V_16 * V_26 =
F_15 ( V_389 , struct V_16 , V_196 ) ;
F_141 ( & V_26 -> V_381 , F_324 ) ;
F_323 ( V_384 , & V_26 -> V_381 ) ;
}
static void F_327 ( struct V_16 * V_26 ,
struct V_20 * V_21 , struct V_3 * V_4 )
{
F_20 ( & V_23 ) ;
F_27 ( V_4 ) ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_26 -> V_3 = V_4 ;
V_26 -> V_21 = V_21 ;
F_71 ( & V_26 -> V_189 ) ;
F_71 ( & V_26 -> V_107 ) ;
V_26 -> V_325 = V_390 ++ ;
if ( F_14 ( V_4 ) ) {
V_26 -> V_19 = F_16 ( F_14 ( V_4 ) , V_21 ) ;
F_24 ( V_26 -> V_19 ) ;
}
F_65 ( F_16 ( V_4 , V_21 ) ) ;
}
static int F_328 ( struct V_16 * V_26 )
{
struct V_20 * V_21 = V_26 -> V_21 ;
int V_12 = 0 ;
F_20 ( & V_23 ) ;
if ( V_21 -> V_391 )
V_12 = V_21 -> V_391 ( V_26 ) ;
if ( ! V_12 ) {
V_26 -> V_29 |= V_30 ;
F_50 ( V_26 -> V_3 -> V_22 [ V_21 -> V_15 ] , V_26 ) ;
}
return V_12 ;
}
static void F_329 ( struct V_16 * V_26 )
{
struct V_20 * V_21 = V_26 -> V_21 ;
F_20 ( & V_23 ) ;
if ( ! ( V_26 -> V_29 & V_30 ) )
return;
if ( V_21 -> V_392 )
V_21 -> V_392 ( V_26 ) ;
V_26 -> V_29 &= ~ V_30 ;
F_116 ( V_26 -> V_3 -> V_22 [ V_21 -> V_15 ] , NULL ) ;
F_330 ( & V_26 -> V_3 -> V_192 ) ;
}
static int F_223 ( struct V_3 * V_4 , struct V_20 * V_21 ,
bool V_393 )
{
struct V_3 * V_19 = F_14 ( V_4 ) ;
struct V_16 * V_17 = F_16 ( V_19 , V_21 ) ;
struct V_16 * V_26 ;
int V_142 ;
F_20 ( & V_23 ) ;
V_26 = V_21 -> V_394 ( V_17 ) ;
if ( F_149 ( V_26 ) )
return F_150 ( V_26 ) ;
F_327 ( V_26 , V_21 , V_4 ) ;
V_142 = F_147 ( & V_26 -> V_196 , V_197 , 0 , V_88 ) ;
if ( V_142 )
goto V_395;
V_142 = F_4 ( & V_21 -> V_383 , NULL , 2 , 0 , V_88 ) ;
if ( V_142 < 0 )
goto V_396;
V_26 -> V_15 = V_142 ;
if ( V_393 ) {
V_142 = F_112 ( V_26 , NULL ) ;
if ( V_142 )
goto V_397;
}
F_331 ( & V_26 -> V_189 , & V_17 -> V_107 ) ;
F_10 ( & V_21 -> V_383 , V_26 , V_26 -> V_15 ) ;
V_142 = F_328 ( V_26 ) ;
if ( V_142 )
goto V_398;
if ( V_21 -> V_399 && ! V_21 -> V_400 &&
F_14 ( V_19 ) ) {
F_114 ( L_34 ,
V_181 -> V_182 , V_181 -> V_258 , V_21 -> V_114 ) ;
if ( ! strcmp ( V_21 -> V_114 , L_35 ) )
F_114 ( L_36 ) ;
V_21 -> V_400 = true ;
}
return 0 ;
V_398:
F_325 ( & V_26 -> V_189 ) ;
F_110 ( V_26 , NULL ) ;
V_397:
F_12 ( & V_21 -> V_383 , V_26 -> V_15 ) ;
V_396:
F_151 ( & V_26 -> V_196 ) ;
V_395:
F_326 ( & V_26 -> V_71 , F_322 ) ;
return V_142 ;
}
static int F_332 ( struct V_131 * V_401 , const char * V_114 ,
T_2 V_116 )
{
struct V_3 * V_19 , * V_4 ;
struct V_84 * V_5 ;
struct V_20 * V_21 ;
struct V_131 * V_33 ;
int V_1 , V_12 ;
if ( strchr ( V_114 , '\n' ) )
return - V_171 ;
V_19 = F_104 ( V_401 ) ;
if ( ! V_19 )
return - V_259 ;
V_5 = V_19 -> V_5 ;
V_4 = F_72 ( sizeof( * V_4 ) , V_88 ) ;
if ( ! V_4 ) {
V_12 = - V_89 ;
goto V_27;
}
V_12 = F_147 ( & V_4 -> V_18 . V_196 , V_197 , 0 , V_88 ) ;
if ( V_12 )
goto V_402;
V_4 -> V_15 = F_4 ( & V_5 -> V_105 , NULL , 2 , 0 , V_88 ) ;
if ( V_4 -> V_15 < 0 ) {
V_12 = - V_89 ;
goto V_403;
}
F_138 ( V_4 ) ;
V_4 -> V_18 . V_19 = & V_19 -> V_18 ;
V_4 -> V_5 = V_5 ;
if ( F_37 ( V_19 ) )
F_144 ( V_38 , & V_4 -> V_29 ) ;
if ( F_38 ( V_160 , & V_19 -> V_29 ) )
F_144 ( V_160 , & V_4 -> V_29 ) ;
V_33 = F_333 ( V_19 -> V_33 , V_114 , V_116 , V_4 ) ;
if ( F_149 ( V_33 ) ) {
V_12 = F_150 ( V_33 ) ;
goto V_404;
}
V_4 -> V_33 = V_33 ;
F_334 ( V_33 ) ;
V_4 -> V_18 . V_325 = V_390 ++ ;
F_331 ( & V_4 -> V_18 . V_189 , & F_14 ( V_4 ) -> V_18 . V_107 ) ;
F_63 ( & V_5 -> V_106 ) ;
F_27 ( V_19 ) ;
F_10 ( & V_5 -> V_105 , V_4 , V_4 -> V_15 ) ;
V_12 = F_240 ( V_33 ) ;
if ( V_12 )
goto V_405;
V_12 = F_112 ( & V_4 -> V_18 , NULL ) ;
if ( V_12 )
goto V_405;
F_53 (ss, ssid) {
if ( V_19 -> V_25 & ( 1 << V_1 ) ) {
V_12 = F_223 ( V_4 , V_21 ,
V_19 -> V_127 & ( 1 << V_1 ) ) ;
if ( V_12 )
goto V_405;
}
}
if ( ! F_3 ( V_4 ) ) {
V_4 -> V_127 = V_19 -> V_127 ;
F_100 ( V_4 ) ;
}
F_120 ( V_33 ) ;
V_12 = 0 ;
goto V_27;
V_404:
F_12 ( & V_5 -> V_105 , V_4 -> V_15 ) ;
V_403:
F_151 ( & V_4 -> V_18 . V_196 ) ;
V_402:
F_58 ( V_4 ) ;
V_27:
F_101 ( V_401 ) ;
return V_12 ;
V_405:
F_335 ( V_4 ) ;
goto V_27;
}
static void F_336 ( struct V_340 * V_341 )
{
struct V_16 * V_26 =
F_15 ( V_341 , struct V_16 , V_381 ) ;
F_88 ( & V_23 ) ;
F_329 ( V_26 ) ;
F_91 ( & V_23 ) ;
F_32 ( V_26 ) ;
}
static void F_337 ( struct V_388 * V_389 )
{
struct V_16 * V_26 =
F_15 ( V_389 , struct V_16 , V_196 ) ;
F_141 ( & V_26 -> V_381 , F_336 ) ;
F_323 ( V_384 , & V_26 -> V_381 ) ;
}
static void F_224 ( struct V_16 * V_26 )
{
F_20 ( & V_23 ) ;
F_110 ( V_26 , NULL ) ;
F_24 ( V_26 ) ;
F_338 ( & V_26 -> V_196 , F_337 ) ;
}
static int F_335 ( struct V_3 * V_4 )
__releases( &cgroup_mutex
static int F_339 ( struct V_131 * V_33 )
{
struct V_3 * V_4 ;
int V_12 = 0 ;
V_4 = F_104 ( V_33 ) ;
if ( ! V_4 )
return 0 ;
V_12 = F_335 ( V_4 ) ;
F_101 ( V_33 ) ;
return V_12 ;
}
static void T_8 F_340 ( struct V_20 * V_21 , bool V_406 )
{
struct V_16 * V_26 ;
F_341 ( V_407 L_37 , V_21 -> V_114 ) ;
F_88 ( & V_23 ) ;
F_143 ( & V_21 -> V_383 ) ;
F_71 ( & V_21 -> V_138 ) ;
V_21 -> V_5 = & V_6 ;
V_26 = V_21 -> V_394 ( F_16 ( & V_6 . V_4 , V_21 ) ) ;
F_65 ( F_149 ( V_26 ) ) ;
F_327 ( V_26 , V_21 , & V_6 . V_4 ) ;
V_26 -> V_29 |= V_408 ;
if ( V_406 ) {
V_26 -> V_15 = 1 ;
} else {
V_26 -> V_15 = F_4 ( & V_21 -> V_383 , V_26 , 1 , 2 , V_88 ) ;
F_65 ( V_26 -> V_15 < 0 ) ;
}
V_28 . V_22 [ V_21 -> V_15 ] = V_26 ;
V_409 |= ( bool ) V_21 -> V_410 << V_21 -> V_15 ;
V_411 |= ( bool ) V_21 -> exit << V_21 -> V_15 ;
V_412 |= ( bool ) V_21 -> free << V_21 -> V_15 ;
V_413 |= ( bool ) V_21 -> V_414 << V_21 -> V_15 ;
F_65 ( ! F_40 ( & V_415 . V_42 ) ) ;
F_65 ( F_328 ( V_26 ) ) ;
F_91 ( & V_23 ) ;
}
int T_8 F_342 ( void )
{
static struct V_162 T_9 V_163 ;
struct V_20 * V_21 ;
int V_63 ;
F_142 ( & V_6 , & V_163 ) ;
V_6 . V_4 . V_18 . V_29 |= V_408 ;
F_116 ( V_415 . V_61 , & V_28 ) ;
F_53 (ss, i) {
F_343 ( ! V_21 -> V_394 || ! V_21 -> V_382 || V_21 -> V_114 || V_21 -> V_15 ,
L_38 ,
V_63 , V_416 [ V_63 ] , V_21 -> V_394 , V_21 -> V_382 ,
V_21 -> V_15 , V_21 -> V_114 ) ;
F_343 ( strlen ( V_416 [ V_63 ] ) > V_417 ,
L_39 , V_416 [ V_63 ] ) ;
V_21 -> V_15 = V_63 ;
V_21 -> V_114 = V_416 [ V_63 ] ;
if ( ! V_21 -> V_115 )
V_21 -> V_115 = V_416 [ V_63 ] ;
if ( V_21 -> V_418 )
F_340 ( V_21 , true ) ;
}
return 0 ;
}
int T_8 F_344 ( void )
{
struct V_20 * V_21 ;
unsigned long V_62 ;
int V_1 ;
F_65 ( F_345 ( & V_260 ) ) ;
F_65 ( F_251 ( NULL , V_140 ) ) ;
F_65 ( F_251 ( NULL , V_141 ) ) ;
F_88 ( & V_23 ) ;
V_62 = F_52 ( V_28 . V_22 ) ;
F_80 ( V_98 , & V_28 . V_67 , V_62 ) ;
F_65 ( F_145 ( & V_6 , 0 ) ) ;
F_91 ( & V_23 ) ;
F_53 (ss, ssid) {
if ( V_21 -> V_418 ) {
struct V_16 * V_26 =
V_28 . V_22 [ V_21 -> V_15 ] ;
V_26 -> V_15 = F_4 ( & V_21 -> V_383 , V_26 , 1 , 2 ,
V_88 ) ;
F_65 ( V_26 -> V_15 < 0 ) ;
} else {
F_340 ( V_21 , false ) ;
}
F_51 ( & V_28 . V_66 [ V_1 ] ,
& V_6 . V_4 . V_99 [ V_1 ] ) ;
if ( V_419 & ( 1 << V_1 ) ) {
F_119 ( V_2 [ V_1 ] ) ;
F_341 ( V_407 L_40 ,
V_21 -> V_114 ) ;
continue;
}
V_6 . V_24 |= 1 << V_21 -> V_15 ;
if ( ! V_21 -> V_420 )
V_148 |= 1 << V_21 -> V_15 ;
if ( V_21 -> V_420 == V_21 -> V_421 ) {
F_115 ( F_255 ( V_21 , V_21 -> V_420 ) ) ;
} else {
F_115 ( F_256 ( V_21 , V_21 -> V_420 ) ) ;
F_115 ( F_257 ( V_21 , V_21 -> V_421 ) ) ;
}
if ( V_21 -> V_154 )
V_21 -> V_154 ( V_28 . V_22 [ V_1 ] ) ;
}
F_115 ( F_346 ( V_422 , L_41 ) ) ;
F_115 ( F_347 ( & V_364 ) ) ;
F_115 ( ! F_348 ( L_42 , 0 , NULL , & V_423 ) ) ;
return 0 ;
}
static int T_8 F_349 ( void )
{
V_384 = F_350 ( L_43 , 0 , 1 ) ;
F_65 ( ! V_384 ) ;
V_338 = F_350 ( L_44 ,
0 , 1 ) ;
F_65 ( ! V_338 ) ;
return 0 ;
}
int F_351 ( struct V_155 * V_291 , struct V_356 * V_348 ,
struct V_258 * V_258 , struct V_50 * V_257 )
{
char * V_110 , * V_216 ;
int V_268 ;
struct V_84 * V_5 ;
V_268 = - V_89 ;
V_110 = F_280 ( V_176 , V_88 ) ;
if ( ! V_110 )
goto V_195;
F_88 ( & V_23 ) ;
F_6 ( & V_41 ) ;
F_156 (root) {
struct V_20 * V_21 ;
struct V_3 * V_4 ;
int V_1 , V_86 = 0 ;
if ( V_5 == & V_6 && ! V_151 )
continue;
F_211 ( V_291 , L_45 , V_5 -> V_104 ) ;
if ( V_5 != & V_6 )
F_53 (ss, ssid)
if ( V_5 -> V_24 & ( 1 << V_1 ) )
F_211 ( V_291 , L_46 , V_86 ++ ? L_9 : L_23 ,
V_21 -> V_115 ) ;
if ( strlen ( V_5 -> V_114 ) )
F_211 ( V_291 , L_47 , V_86 ? L_9 : L_23 ,
V_5 -> V_114 ) ;
F_208 ( V_291 , ':' ) ;
V_4 = F_94 ( V_257 , V_5 ) ;
if ( F_3 ( V_4 ) || ! ( V_257 -> V_29 & V_60 ) ) {
V_216 = F_168 ( V_4 , V_110 , V_176 ) ;
if ( ! V_216 ) {
V_268 = - V_424 ;
goto V_27;
}
} else {
V_216 = L_25 ;
}
F_123 ( V_291 , V_216 ) ;
if ( F_3 ( V_4 ) && F_26 ( V_4 ) )
F_123 ( V_291 , L_48 ) ;
else
F_208 ( V_291 , '\n' ) ;
}
V_268 = 0 ;
V_27:
F_8 ( & V_41 ) ;
F_91 ( & V_23 ) ;
F_58 ( V_110 ) ;
V_195:
return V_268 ;
}
static int F_352 ( struct V_155 * V_291 , void * V_270 )
{
struct V_20 * V_21 ;
int V_63 ;
F_123 ( V_291 , L_49 ) ;
F_88 ( & V_23 ) ;
F_53 (ss, i)
F_211 ( V_291 , L_50 ,
V_21 -> V_115 , V_21 -> V_5 -> V_104 ,
F_89 ( & V_21 -> V_5 -> V_106 ) ,
F_1 ( V_63 ) ) ;
F_91 ( & V_23 ) ;
return 0 ;
}
static int F_353 ( struct V_252 * V_252 , struct V_249 * V_249 )
{
return F_354 ( V_249 , F_352 , NULL ) ;
}
static void * * F_355 ( void * V_425 [ V_426 ] , int V_63 )
{
if ( V_427 <= V_63 && V_63 < V_428 )
return & V_425 [ V_63 - V_427 ] ;
return NULL ;
}
static void * F_356 ( void * V_425 [ V_426 ] , int V_63 )
{
void * * V_375 = F_355 ( V_425 , V_63 ) ;
return V_375 ? * V_375 : NULL ;
}
void F_357 ( struct V_50 * V_282 )
{
F_116 ( V_282 -> V_61 , & V_28 ) ;
F_71 ( & V_282 -> V_58 ) ;
}
int F_358 ( struct V_50 * V_282 ,
void * V_425 [ V_426 ] )
{
struct V_20 * V_21 ;
int V_63 , V_429 , V_12 ;
F_99 (ss, i, &have_canfork_callback) {
V_12 = V_21 -> V_414 ( V_282 , F_355 ( V_425 , V_63 ) ) ;
if ( V_12 )
goto V_430;
}
return 0 ;
V_430:
F_53 (ss, j) {
if ( V_429 >= V_63 )
break;
if ( V_21 -> V_431 )
V_21 -> V_431 ( V_282 , F_356 ( V_425 , V_429 ) ) ;
}
return V_12 ;
}
void F_359 ( struct V_50 * V_282 ,
void * V_425 [ V_426 ] )
{
struct V_20 * V_21 ;
int V_63 ;
F_53 (ss, i)
if ( V_21 -> V_431 )
V_21 -> V_431 ( V_282 , F_356 ( V_425 , V_63 ) ) ;
}
void F_360 ( struct V_50 * V_282 ,
void * V_432 [ V_426 ] )
{
struct V_20 * V_21 ;
int V_63 ;
if ( V_185 ) {
struct V_39 * V_40 ;
F_6 ( & V_41 ) ;
V_40 = F_95 ( V_181 ) ;
if ( F_40 ( & V_282 -> V_58 ) ) {
F_62 ( V_40 ) ;
F_46 ( V_282 , NULL , V_40 , false ) ;
}
F_8 ( & V_41 ) ;
}
F_99 (ss, i, &have_fork_callback)
V_21 -> V_410 ( V_282 , F_356 ( V_432 , V_63 ) ) ;
}
void F_361 ( struct V_50 * V_257 )
{
struct V_20 * V_21 ;
struct V_39 * V_40 ;
int V_63 ;
V_40 = F_95 ( V_257 ) ;
if ( ! F_40 ( & V_257 -> V_58 ) ) {
F_6 ( & V_41 ) ;
F_46 ( V_257 , V_40 , NULL , false ) ;
F_8 ( & V_41 ) ;
} else {
F_62 ( V_40 ) ;
}
F_99 (ss, i, &have_exit_callback)
V_21 -> exit ( V_257 ) ;
}
void F_362 ( struct V_50 * V_51 )
{
struct V_39 * V_40 = F_95 ( V_51 ) ;
struct V_20 * V_21 ;
int V_1 ;
F_99 (ss, ssid, &have_free_callback)
V_21 -> free ( V_51 ) ;
F_60 ( V_40 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
if ( F_37 ( V_4 ) && ! F_226 ( V_4 ) &&
! F_271 ( & V_4 -> V_18 ) && ! F_26 ( V_4 ) )
F_363 ( & V_4 -> V_193 ) ;
}
static void V_194 ( struct V_340 * V_341 )
{
struct V_3 * V_4 =
F_15 ( V_341 , struct V_3 , V_193 ) ;
char * V_433 = NULL , * V_434 = NULL , * V_216 ;
char * V_435 [ 3 ] , * V_436 [ 3 ] ;
F_88 ( & V_23 ) ;
V_433 = F_280 ( V_176 , V_88 ) ;
V_434 = F_364 ( V_4 -> V_5 -> V_159 , V_88 ) ;
if ( ! V_433 || ! V_434 )
goto V_195;
V_216 = F_168 ( V_4 , V_433 , V_176 ) ;
if ( ! V_216 )
goto V_195;
V_435 [ 0 ] = V_434 ;
V_435 [ 1 ] = V_216 ;
V_435 [ 2 ] = NULL ;
V_436 [ 0 ] = L_51 ;
V_436 [ 1 ] = L_52 ;
V_436 [ 2 ] = NULL ;
F_91 ( & V_23 ) ;
F_365 ( V_435 [ 0 ] , V_435 , V_436 , V_437 ) ;
goto V_211;
V_195:
F_91 ( & V_23 ) ;
V_211:
F_58 ( V_434 ) ;
F_58 ( V_433 ) ;
}
static int T_8 F_366 ( char * V_438 )
{
struct V_20 * V_21 ;
char * V_164 ;
int V_63 ;
while ( ( V_164 = F_128 ( & V_438 , L_9 ) ) != NULL ) {
if ( ! * V_164 )
continue;
F_53 (ss, i) {
if ( strcmp ( V_164 , V_21 -> V_114 ) &&
strcmp ( V_164 , V_21 -> V_115 ) )
continue;
V_419 |= 1 << V_63 ;
}
}
return 1 ;
}
struct V_16 * F_367 ( struct V_204 * V_204 ,
struct V_20 * V_21 )
{
struct V_131 * V_33 = F_306 ( V_204 ) ;
struct V_16 * V_26 = NULL ;
struct V_3 * V_4 ;
if ( V_204 -> V_251 -> V_363 != & V_364 || ! V_33 ||
F_102 ( V_33 ) != V_132 )
return F_160 ( - V_439 ) ;
F_22 () ;
V_4 = F_307 ( V_33 -> V_34 ) ;
if ( V_4 )
V_26 = F_16 ( V_4 , V_21 ) ;
if ( ! V_26 || ! F_23 ( V_26 ) )
V_26 = F_160 ( - V_178 ) ;
F_25 () ;
return V_26 ;
}
struct V_16 * F_368 ( int V_15 , struct V_20 * V_21 )
{
F_28 ( ! F_369 () ) ;
return V_15 > 0 ? F_370 ( & V_21 -> V_383 , V_15 ) : NULL ;
}
static struct V_16 *
F_371 ( struct V_16 * V_17 )
{
struct V_16 * V_26 = F_72 ( sizeof( * V_26 ) , V_88 ) ;
if ( ! V_26 )
return F_160 ( - V_89 ) ;
return V_26 ;
}
static void F_372 ( struct V_16 * V_26 )
{
F_58 ( V_26 ) ;
}
static T_7 F_373 ( struct V_16 * V_26 ,
struct V_35 * V_36 )
{
return F_261 ( V_26 -> V_3 ) ;
}
static T_7 F_374 ( struct V_16 * V_26 ,
struct V_35 * V_36 )
{
return ( T_7 ) ( unsigned long ) V_181 -> V_61 ;
}
static T_7 F_375 ( struct V_16 * V_26 ,
struct V_35 * V_36 )
{
T_7 V_86 ;
F_22 () ;
V_86 = F_89 ( & F_95 ( V_181 ) -> V_65 ) ;
F_25 () ;
return V_86 ;
}
static int F_376 ( struct V_155 * V_156 , void * V_270 )
{
struct V_48 * V_49 ;
struct V_39 * V_40 ;
char * V_440 ;
V_440 = F_280 ( V_441 + 1 , V_88 ) ;
if ( ! V_440 )
return - V_89 ;
F_6 ( & V_41 ) ;
F_22 () ;
V_40 = F_307 ( V_181 -> V_61 ) ;
F_45 (link, &cset->cgrp_links, cgrp_link) {
struct V_3 * V_97 = V_49 -> V_4 ;
F_377 ( V_97 , V_440 , V_441 + 1 ) ;
F_211 ( V_156 , L_53 ,
V_97 -> V_5 -> V_104 , V_440 ) ;
}
F_25 () ;
F_8 ( & V_41 ) ;
F_58 ( V_440 ) ;
return 0 ;
}
static int F_378 ( struct V_155 * V_156 , void * V_270 )
{
struct V_16 * V_26 = F_207 ( V_156 ) ;
struct V_48 * V_49 ;
F_6 ( & V_41 ) ;
F_45 (link, &css->cgroup->cset_links, cset_link) {
struct V_39 * V_40 = V_49 -> V_40 ;
struct V_50 * V_51 ;
int V_86 = 0 ;
F_211 ( V_156 , L_54 , V_40 ) ;
F_45 (task, &cset->tasks, cg_list) {
if ( V_86 ++ > V_442 )
goto V_443;
F_211 ( V_156 , L_55 , F_303 ( V_51 ) ) ;
}
F_45 (task, &cset->mg_tasks, cg_list) {
if ( V_86 ++ > V_442 )
goto V_443;
F_211 ( V_156 , L_55 , F_303 ( V_51 ) ) ;
}
continue;
V_443:
F_123 ( V_156 , L_56 ) ;
}
F_8 ( & V_41 ) ;
return 0 ;
}
static T_7 F_379 ( struct V_16 * V_26 , struct V_35 * V_36 )
{
return ( ! F_226 ( V_26 -> V_3 ) &&
! F_271 ( & V_26 -> V_3 -> V_18 ) ) ;
}
