static int F_1 ( struct V_1 * V_1 , void * V_2 , int V_3 , int V_4 ,
T_1 V_5 )
{
int V_6 ;
F_2 ( V_5 ) ;
F_3 ( & V_7 ) ;
V_6 = F_4 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_5 ( & V_7 ) ;
F_6 () ;
return V_6 ;
}
static void * F_7 ( struct V_1 * V_1 , void * V_2 , int V_8 )
{
void * V_6 ;
F_3 ( & V_7 ) ;
V_6 = F_8 ( V_1 , V_2 , V_8 ) ;
F_5 ( & V_7 ) ;
return V_6 ;
}
static void F_9 ( struct V_1 * V_1 , int V_8 )
{
F_3 ( & V_7 ) ;
F_10 ( V_1 , V_8 ) ;
F_5 ( & V_7 ) ;
}
static struct V_9 * F_11 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
if ( V_12 )
return F_12 ( V_12 , struct V_9 , V_13 ) ;
return NULL ;
}
static struct V_11 * F_13 ( struct V_9 * V_10 ,
struct V_15 * V_16 )
{
if ( V_16 )
return F_14 ( V_10 -> V_17 [ V_16 -> V_8 ] ,
F_15 ( & V_18 ) ) ;
else
return & V_10 -> V_13 ;
}
static struct V_11 * F_16 ( struct V_9 * V_10 ,
struct V_15 * V_16 )
{
F_17 ( & V_18 ) ;
if ( ! V_16 )
return & V_10 -> V_13 ;
if ( ! ( V_10 -> V_19 -> V_20 & ( 1 << V_16 -> V_8 ) ) )
return NULL ;
while ( F_11 ( V_10 ) &&
! ( F_11 ( V_10 ) -> V_21 & ( 1 << V_16 -> V_8 ) ) )
V_10 = F_11 ( V_10 ) ;
return F_13 ( V_10 , V_16 ) ;
}
struct V_11 * F_18 ( struct V_9 * V_10 ,
struct V_15 * V_16 )
{
struct V_11 * V_22 ;
F_19 () ;
do {
V_22 = F_13 ( V_10 , V_16 ) ;
if ( V_22 && F_20 ( V_22 ) )
goto V_23;
V_10 = F_11 ( V_10 ) ;
} while ( V_10 );
V_22 = V_24 . V_17 [ V_16 -> V_8 ] ;
F_21 ( V_22 ) ;
V_23:
F_22 () ;
return V_22 ;
}
static inline bool F_23 ( const struct V_9 * V_10 )
{
return ! ( V_10 -> V_13 . V_25 & V_26 ) ;
}
struct V_11 * F_24 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_29 -> V_14 -> V_30 ;
struct V_31 * V_32 = F_25 ( V_28 ) ;
if ( V_32 -> V_16 )
return F_26 ( V_10 -> V_17 [ V_32 -> V_16 -> V_8 ] ) ;
else
return & V_10 -> V_13 ;
}
bool F_27 ( struct V_9 * V_10 , struct V_9 * V_33 )
{
while ( V_10 ) {
if ( V_10 == V_33 )
return true ;
V_10 = F_11 ( V_10 ) ;
}
return false ;
}
static int F_28 ( const struct V_9 * V_10 )
{
return F_29 ( V_34 , & V_10 -> V_25 ) ;
}
static void F_30 ( struct V_9 * V_10 , bool V_35 )
{
F_17 ( & V_36 ) ;
do {
bool V_37 ;
if ( V_35 )
V_37 = ! V_10 -> V_38 ++ ;
else
V_37 = ! -- V_10 -> V_38 ;
if ( ! V_37 )
break;
if ( V_10 -> V_39 )
F_31 ( V_10 -> V_39 ) ;
V_10 = F_11 ( V_10 ) ;
} while ( V_10 );
}
static unsigned long F_32 ( struct V_11 * V_22 [] )
{
unsigned long V_40 = 0UL ;
struct V_15 * V_16 ;
int V_41 ;
F_33 (ss, i)
V_40 += ( unsigned long ) V_22 [ V_41 ] ;
V_40 = ( V_40 >> 16 ) ^ V_40 ;
return V_40 ;
}
static void F_34 ( struct V_42 * V_43 )
{
struct V_44 * V_45 , * V_46 ;
struct V_15 * V_16 ;
int V_47 ;
F_17 ( & V_36 ) ;
if ( ! F_35 ( & V_43 -> V_48 ) )
return;
F_33 (ss, ssid)
F_36 ( & V_43 -> V_49 [ V_47 ] ) ;
F_37 ( & V_43 -> V_50 ) ;
V_51 -- ;
F_38 (link, tmp_link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_10 = V_45 -> V_10 ;
F_36 ( & V_45 -> V_52 ) ;
F_36 ( & V_45 -> V_53 ) ;
if ( F_39 ( & V_10 -> V_54 ) ) {
F_30 ( V_10 , false ) ;
F_40 ( V_10 ) ;
}
F_41 ( V_45 ) ;
}
F_42 ( V_43 , V_55 ) ;
}
static void F_43 ( struct V_42 * V_43 )
{
if ( F_44 ( & V_43 -> V_48 , - 1 , 1 ) )
return;
F_45 ( & V_36 ) ;
F_34 ( V_43 ) ;
F_46 ( & V_36 ) ;
}
static inline void F_47 ( struct V_42 * V_43 )
{
F_48 ( & V_43 -> V_48 ) ;
}
static bool F_49 ( struct V_42 * V_43 ,
struct V_42 * V_56 ,
struct V_9 * V_57 ,
struct V_11 * V_58 [] )
{
struct V_59 * V_60 , * V_61 ;
if ( memcmp ( V_58 , V_43 -> V_17 , sizeof( V_43 -> V_17 ) ) )
return false ;
V_60 = & V_43 -> V_62 ;
V_61 = & V_56 -> V_62 ;
while ( 1 ) {
struct V_44 * V_63 , * V_64 ;
struct V_9 * V_65 , * V_66 ;
V_60 = V_60 -> V_67 ;
V_61 = V_61 -> V_67 ;
if ( V_60 == & V_43 -> V_62 ) {
F_50 ( V_61 != & V_56 -> V_62 ) ;
break;
} else {
F_50 ( V_61 == & V_56 -> V_62 ) ;
}
V_63 = F_51 ( V_60 , struct V_44 , V_53 ) ;
V_64 = F_51 ( V_61 , struct V_44 , V_53 ) ;
V_65 = V_63 -> V_10 ;
V_66 = V_64 -> V_10 ;
F_50 ( V_65 -> V_19 != V_66 -> V_19 ) ;
if ( V_65 -> V_19 == V_57 -> V_19 ) {
if ( V_65 != V_57 )
return false ;
} else {
if ( V_65 != V_66 )
return false ;
}
}
return true ;
}
static struct V_42 * F_52 ( struct V_42 * V_56 ,
struct V_9 * V_10 ,
struct V_11 * V_58 [] )
{
struct V_68 * V_19 = V_10 -> V_19 ;
struct V_15 * V_16 ;
struct V_42 * V_43 ;
unsigned long V_40 ;
int V_41 ;
F_33 (ss, i) {
if ( V_19 -> V_20 & ( 1UL << V_41 ) ) {
V_58 [ V_41 ] = F_16 ( V_10 , V_16 ) ;
} else {
V_58 [ V_41 ] = V_56 -> V_17 [ V_41 ] ;
}
}
V_40 = F_32 ( V_58 ) ;
F_53 (css_set_table, cset, hlist, key) {
if ( ! F_49 ( V_43 , V_56 , V_10 , V_58 ) )
continue;
return V_43 ;
}
return NULL ;
}
static void F_54 ( struct V_59 * V_69 )
{
struct V_44 * V_45 , * V_46 ;
F_38 (link, tmp_link, links_to_free, cset_link) {
F_36 ( & V_45 -> V_52 ) ;
F_41 ( V_45 ) ;
}
}
static int F_55 ( int V_70 , struct V_59 * V_71 )
{
struct V_44 * V_45 ;
int V_41 ;
F_56 ( V_71 ) ;
for ( V_41 = 0 ; V_41 < V_70 ; V_41 ++ ) {
V_45 = F_57 ( sizeof( * V_45 ) , V_72 ) ;
if ( ! V_45 ) {
F_54 ( V_71 ) ;
return - V_73 ;
}
F_58 ( & V_45 -> V_52 , V_71 ) ;
}
return 0 ;
}
static void F_59 ( struct V_59 * V_71 , struct V_42 * V_43 ,
struct V_9 * V_10 )
{
struct V_44 * V_45 ;
F_50 ( F_39 ( V_71 ) ) ;
if ( F_60 ( V_10 ) )
V_43 -> V_74 = V_10 ;
V_45 = F_61 ( V_71 , struct V_44 , V_52 ) ;
V_45 -> V_43 = V_43 ;
V_45 -> V_10 = V_10 ;
if ( F_39 ( & V_10 -> V_54 ) )
F_30 ( V_10 , true ) ;
F_62 ( & V_45 -> V_52 , & V_10 -> V_54 ) ;
F_63 ( & V_45 -> V_53 , & V_43 -> V_62 ) ;
}
static struct V_42 * F_64 ( struct V_42 * V_56 ,
struct V_9 * V_10 )
{
struct V_11 * V_58 [ V_75 ] = { } ;
struct V_42 * V_43 ;
struct V_59 V_71 ;
struct V_44 * V_45 ;
struct V_15 * V_16 ;
unsigned long V_40 ;
int V_47 ;
F_17 ( & V_18 ) ;
F_65 ( & V_36 ) ;
V_43 = F_52 ( V_56 , V_10 , V_58 ) ;
if ( V_43 )
F_47 ( V_43 ) ;
F_66 ( & V_36 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_57 ( sizeof( * V_43 ) , V_72 ) ;
if ( ! V_43 )
return NULL ;
if ( F_55 ( V_76 , & V_71 ) < 0 ) {
F_41 ( V_43 ) ;
return NULL ;
}
F_67 ( & V_43 -> V_48 , 1 ) ;
F_56 ( & V_43 -> V_62 ) ;
F_56 ( & V_43 -> V_77 ) ;
F_56 ( & V_43 -> V_78 ) ;
F_56 ( & V_43 -> V_79 ) ;
F_56 ( & V_43 -> V_80 ) ;
F_68 ( & V_43 -> V_50 ) ;
memcpy ( V_43 -> V_17 , V_58 , sizeof( V_43 -> V_17 ) ) ;
F_45 ( & V_36 ) ;
F_69 (link, &old_cset->cgrp_links, cgrp_link) {
struct V_9 * V_81 = V_45 -> V_10 ;
if ( V_81 -> V_19 == V_10 -> V_19 )
V_81 = V_10 ;
F_59 ( & V_71 , V_43 , V_81 ) ;
}
F_50 ( ! F_39 ( & V_71 ) ) ;
V_51 ++ ;
V_40 = F_32 ( V_43 -> V_17 ) ;
F_70 ( V_82 , & V_43 -> V_50 , V_40 ) ;
F_33 (ss, ssid)
F_63 ( & V_43 -> V_49 [ V_47 ] ,
& V_43 -> V_17 [ V_47 ] -> V_9 -> V_83 [ V_47 ] ) ;
F_46 ( & V_36 ) ;
return V_43 ;
}
static struct V_68 * F_71 ( struct V_84 * V_85 )
{
struct V_9 * V_86 = V_85 -> V_29 -> V_30 ;
return V_86 -> V_19 ;
}
static int F_72 ( struct V_68 * V_19 )
{
int V_8 ;
F_17 ( & V_18 ) ;
V_8 = F_73 ( & V_87 , V_19 , 0 , 0 , V_72 ) ;
if ( V_8 < 0 )
return V_8 ;
V_19 -> V_88 = V_8 ;
return 0 ;
}
static void F_74 ( struct V_68 * V_19 )
{
F_17 ( & V_18 ) ;
if ( V_19 -> V_88 ) {
F_10 ( & V_87 , V_19 -> V_88 ) ;
V_19 -> V_88 = 0 ;
}
}
static void F_75 ( struct V_68 * V_19 )
{
if ( V_19 ) {
F_76 ( V_19 -> V_88 ) ;
F_77 ( & V_19 -> V_89 ) ;
F_41 ( V_19 ) ;
}
}
static void F_78 ( struct V_68 * V_19 )
{
struct V_9 * V_10 = & V_19 -> V_10 ;
struct V_44 * V_45 , * V_46 ;
F_79 ( & V_18 ) ;
F_50 ( F_80 ( & V_19 -> V_90 ) ) ;
F_50 ( ! F_39 ( & V_10 -> V_13 . V_91 ) ) ;
F_81 ( & V_92 , V_19 -> V_20 ) ;
F_45 ( & V_36 ) ;
F_38 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_36 ( & V_45 -> V_52 ) ;
F_36 ( & V_45 -> V_53 ) ;
F_41 ( V_45 ) ;
}
F_46 ( & V_36 ) ;
if ( ! F_39 ( & V_19 -> V_93 ) ) {
F_36 ( & V_19 -> V_93 ) ;
V_76 -- ;
}
F_74 ( V_19 ) ;
F_82 ( & V_18 ) ;
F_83 ( V_19 -> V_85 ) ;
F_75 ( V_19 ) ;
}
static struct V_9 * F_84 ( struct V_42 * V_43 ,
struct V_68 * V_19 )
{
struct V_9 * V_94 = NULL ;
F_17 ( & V_18 ) ;
F_17 ( & V_36 ) ;
if ( V_43 == & V_24 ) {
V_94 = & V_19 -> V_10 ;
} else {
struct V_44 * V_45 ;
F_69 (link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_81 = V_45 -> V_10 ;
if ( V_81 -> V_19 == V_19 ) {
V_94 = V_81 ;
break;
}
}
}
F_50 ( ! V_94 ) ;
return V_94 ;
}
static struct V_9 * F_85 ( struct V_95 * V_96 ,
struct V_68 * V_19 )
{
return F_84 ( F_86 ( V_96 ) , V_19 ) ;
}
static char * F_87 ( struct V_9 * V_10 , const struct V_31 * V_32 ,
char * V_97 )
{
if ( V_32 -> V_16 && ! ( V_32 -> V_25 & V_98 ) &&
! ( V_10 -> V_19 -> V_25 & V_99 ) )
snprintf ( V_97 , V_100 , L_1 ,
V_32 -> V_16 -> V_101 , V_32 -> V_101 ) ;
else
strncpy ( V_97 , V_32 -> V_101 , V_100 ) ;
return V_97 ;
}
static T_2 F_88 ( const struct V_31 * V_32 )
{
T_2 V_102 = 0 ;
if ( V_32 -> V_102 )
return V_32 -> V_102 ;
if ( V_32 -> V_103 || V_32 -> V_104 || V_32 -> V_105 )
V_102 |= V_106 ;
if ( V_32 -> V_107 || V_32 -> V_108 || V_32 -> V_109 )
V_102 |= V_110 ;
return V_102 ;
}
static void F_89 ( struct V_9 * V_10 )
{
F_76 ( F_23 ( V_10 ) ) ;
F_21 ( & V_10 -> V_13 ) ;
}
static bool F_90 ( struct V_9 * V_10 )
{
return F_91 ( & V_10 -> V_13 ) ;
}
static void F_92 ( struct V_9 * V_10 )
{
F_93 ( & V_10 -> V_13 ) ;
}
static unsigned long F_94 ( struct V_9 * V_10 ,
unsigned long V_111 )
{
struct V_9 * V_14 = F_11 ( V_10 ) ;
unsigned long V_112 = V_111 ;
struct V_15 * V_16 ;
int V_47 ;
F_17 ( & V_18 ) ;
if ( ! F_60 ( V_10 ) )
return V_112 ;
while ( true ) {
unsigned long V_113 = V_112 ;
F_95 (ss, ssid, &cur_ss_mask)
V_113 |= V_16 -> V_114 ;
if ( V_14 )
V_113 &= V_14 -> V_21 ;
else
V_113 &= V_10 -> V_19 -> V_20 ;
if ( V_113 == V_112 )
break;
V_112 = V_113 ;
}
return V_112 ;
}
static void F_96 ( struct V_9 * V_10 )
{
V_10 -> V_21 =
F_94 ( V_10 , V_10 -> V_111 ) ;
}
static void F_97 ( struct V_115 * V_29 )
{
struct V_9 * V_10 ;
if ( F_98 ( V_29 ) == V_116 )
V_10 = V_29 -> V_30 ;
else
V_10 = V_29 -> V_14 -> V_30 ;
F_82 ( & V_18 ) ;
F_99 ( V_29 ) ;
F_92 ( V_10 ) ;
}
static struct V_9 * F_100 ( struct V_115 * V_29 )
{
struct V_9 * V_10 ;
if ( F_98 ( V_29 ) == V_116 )
V_10 = V_29 -> V_30 ;
else
V_10 = V_29 -> V_14 -> V_30 ;
if ( ! F_90 ( V_10 ) )
return NULL ;
F_101 ( V_29 ) ;
F_79 ( & V_18 ) ;
if ( ! F_23 ( V_10 ) )
return V_10 ;
F_97 ( V_29 ) ;
return NULL ;
}
static void F_102 ( struct V_9 * V_10 , const struct V_31 * V_32 )
{
char V_101 [ V_100 ] ;
F_17 ( & V_18 ) ;
F_103 ( V_10 -> V_29 , F_87 ( V_10 , V_32 , V_101 ) ) ;
}
static void F_104 ( struct V_9 * V_10 , unsigned long V_20 )
{
struct V_15 * V_16 ;
int V_41 ;
F_33 (ss, i) {
struct V_31 * V_117 ;
if ( ! ( V_20 & ( 1 << V_41 ) ) )
continue;
F_69 (cfts, &ss->cfts, node)
F_105 ( V_10 , V_117 , false ) ;
}
}
static int F_81 ( struct V_68 * V_118 ,
unsigned long V_119 )
{
struct V_15 * V_16 ;
unsigned long V_120 ;
int V_47 , V_41 , V_6 ;
F_17 ( & V_18 ) ;
F_95 (ss, ssid, &ss_mask) {
if ( F_106 ( NULL , F_13 ( & V_16 -> V_19 -> V_10 , V_16 ) ) )
return - V_121 ;
if ( V_16 -> V_19 != & V_92 && V_118 != & V_92 )
return - V_121 ;
}
V_120 = V_119 ;
if ( V_118 == & V_92 )
V_120 &= ~ V_122 ;
V_6 = F_107 ( & V_118 -> V_10 , V_120 ) ;
if ( V_6 ) {
if ( V_118 != & V_92 )
return V_6 ;
if ( V_123 ) {
F_108 ( L_2 ,
V_6 , V_119 ) ;
F_108 ( L_3 ) ;
}
}
F_95 (ss, ssid, &ss_mask)
F_104 ( & V_16 -> V_19 -> V_10 , 1 << V_47 ) ;
F_95 (ss, ssid, &ss_mask) {
struct V_68 * V_124 ;
struct V_11 * V_22 ;
struct V_42 * V_43 ;
V_124 = V_16 -> V_19 ;
V_22 = F_13 ( & V_124 -> V_10 , V_16 ) ;
F_109 ( ! V_22 || F_13 ( & V_118 -> V_10 , V_16 ) ) ;
F_110 ( V_124 -> V_10 . V_17 [ V_47 ] , NULL ) ;
F_111 ( V_118 -> V_10 . V_17 [ V_47 ] , V_22 ) ;
V_16 -> V_19 = V_118 ;
V_22 -> V_9 = & V_118 -> V_10 ;
F_45 ( & V_36 ) ;
F_112 (css_set_table, i, cset, hlist)
F_113 ( & V_43 -> V_49 [ V_16 -> V_8 ] ,
& V_118 -> V_10 . V_83 [ V_16 -> V_8 ] ) ;
F_46 ( & V_36 ) ;
V_124 -> V_20 &= ~ ( 1 << V_47 ) ;
V_124 -> V_10 . V_111 &= ~ ( 1 << V_47 ) ;
F_96 ( & V_124 -> V_10 ) ;
V_118 -> V_20 |= 1 << V_47 ;
if ( V_118 != & V_92 ) {
V_118 -> V_10 . V_111 |= 1 << V_47 ;
F_96 ( & V_118 -> V_10 ) ;
}
if ( V_16 -> V_125 )
V_16 -> V_125 ( V_22 ) ;
}
F_114 ( V_118 -> V_10 . V_29 ) ;
return 0 ;
}
static int F_115 ( struct V_126 * V_127 ,
struct V_84 * V_85 )
{
struct V_68 * V_19 = F_71 ( V_85 ) ;
struct V_15 * V_16 ;
int V_47 ;
F_33 (ss, ssid)
if ( V_19 -> V_20 & ( 1 << V_47 ) )
F_116 ( V_127 , L_4 , V_16 -> V_101 ) ;
if ( V_19 -> V_25 & V_99 )
F_117 ( V_127 , L_5 ) ;
if ( V_19 -> V_25 & V_128 )
F_117 ( V_127 , L_6 ) ;
F_118 ( & V_129 ) ;
if ( strlen ( V_19 -> V_130 ) )
F_116 ( V_127 , L_7 , V_19 -> V_130 ) ;
F_119 ( & V_129 ) ;
if ( F_29 ( V_131 , & V_19 -> V_10 . V_25 ) )
F_117 ( V_127 , L_8 ) ;
if ( strlen ( V_19 -> V_101 ) )
F_116 ( V_127 , L_9 , V_19 -> V_101 ) ;
return 0 ;
}
static int F_120 ( char * V_132 , struct V_133 * V_134 )
{
char * V_135 , * V_136 = V_132 ;
bool V_137 = false , V_138 = false ;
unsigned long V_139 = - 1UL ;
struct V_15 * V_16 ;
int V_140 = 0 ;
int V_41 ;
#ifdef F_121
V_139 = ~ ( 1U << V_141 ) ;
#endif
memset ( V_134 , 0 , sizeof( * V_134 ) ) ;
while ( ( V_135 = F_122 ( & V_136 , L_10 ) ) != NULL ) {
V_140 ++ ;
if ( ! * V_135 )
return - V_142 ;
if ( ! strcmp ( V_135 , L_11 ) ) {
V_134 -> V_143 = true ;
continue;
}
if ( ! strcmp ( V_135 , L_12 ) ) {
if ( V_138 )
return - V_142 ;
V_137 = true ;
continue;
}
if ( ! strcmp ( V_135 , L_13 ) ) {
V_134 -> V_25 |= V_144 ;
continue;
}
if ( ! strcmp ( V_135 , L_14 ) ) {
V_134 -> V_25 |= V_99 ;
continue;
}
if ( ! strcmp ( V_135 , L_15 ) ) {
V_134 -> V_145 = true ;
continue;
}
if ( ! strcmp ( V_135 , L_16 ) ) {
V_134 -> V_25 |= V_128 ;
continue;
}
if ( ! strncmp ( V_135 , L_17 , 14 ) ) {
if ( V_134 -> V_146 )
return - V_142 ;
V_134 -> V_146 =
F_123 ( V_135 + 14 , V_147 - 1 , V_72 ) ;
if ( ! V_134 -> V_146 )
return - V_73 ;
continue;
}
if ( ! strncmp ( V_135 , L_18 , 5 ) ) {
const char * V_101 = V_135 + 5 ;
if ( ! strlen ( V_101 ) )
return - V_142 ;
for ( V_41 = 0 ; V_41 < strlen ( V_101 ) ; V_41 ++ ) {
char V_81 = V_101 [ V_41 ] ;
if ( isalnum ( V_81 ) )
continue;
if ( ( V_81 == '.' ) || ( V_81 == '-' ) || ( V_81 == '_' ) )
continue;
return - V_142 ;
}
if ( V_134 -> V_101 )
return - V_142 ;
V_134 -> V_101 = F_123 ( V_101 ,
V_148 - 1 ,
V_72 ) ;
if ( ! V_134 -> V_101 )
return - V_73 ;
continue;
}
F_33 (ss, i) {
if ( strcmp ( V_135 , V_16 -> V_101 ) )
continue;
if ( V_16 -> V_149 )
continue;
if ( V_137 )
return - V_142 ;
V_134 -> V_20 |= ( 1 << V_41 ) ;
V_138 = true ;
break;
}
if ( V_41 == V_75 )
return - V_150 ;
}
if ( V_134 -> V_25 & V_144 ) {
F_108 ( L_19 ) ;
if ( V_140 != 1 ) {
F_124 ( L_20 ) ;
return - V_142 ;
}
return 0 ;
}
if ( V_137 || ( ! V_138 && ! V_134 -> V_143 && ! V_134 -> V_101 ) )
F_33 (ss, i)
if ( ! V_16 -> V_149 )
V_134 -> V_20 |= ( 1 << V_41 ) ;
if ( ! V_134 -> V_20 && ! V_134 -> V_101 )
return - V_142 ;
if ( ( V_134 -> V_25 & V_99 ) && ( V_134 -> V_20 & V_139 ) )
return - V_142 ;
if ( V_134 -> V_20 && V_134 -> V_143 )
return - V_142 ;
return 0 ;
}
static int F_125 ( struct V_84 * V_85 , int * V_25 , char * V_132 )
{
int V_6 = 0 ;
struct V_68 * V_19 = F_71 ( V_85 ) ;
struct V_133 V_134 ;
unsigned long V_151 , V_152 ;
if ( V_19 == & V_92 ) {
F_124 ( L_21 ) ;
return - V_142 ;
}
F_79 ( & V_18 ) ;
V_6 = F_120 ( V_132 , & V_134 ) ;
if ( V_6 )
goto V_23;
if ( V_134 . V_20 != V_19 -> V_20 || V_134 . V_146 )
F_108 ( L_22 ,
F_126 ( V_153 ) , V_153 -> V_154 ) ;
V_151 = V_134 . V_20 & ~ V_19 -> V_20 ;
V_152 = V_19 -> V_20 & ~ V_134 . V_20 ;
if ( ( V_134 . V_25 ^ V_19 -> V_25 ) ||
( V_134 . V_101 && strcmp ( V_134 . V_101 , V_19 -> V_101 ) ) ) {
F_124 ( L_23 ,
V_134 . V_25 , V_134 . V_101 ? : L_24 , V_19 -> V_25 , V_19 -> V_101 ) ;
V_6 = - V_142 ;
goto V_23;
}
if ( ! F_39 ( & V_19 -> V_10 . V_13 . V_91 ) ) {
V_6 = - V_121 ;
goto V_23;
}
V_6 = F_81 ( V_19 , V_151 ) ;
if ( V_6 )
goto V_23;
F_81 ( & V_92 , V_152 ) ;
if ( V_134 . V_146 ) {
F_118 ( & V_129 ) ;
strcpy ( V_19 -> V_130 , V_134 . V_146 ) ;
F_119 ( & V_129 ) ;
}
V_23:
F_41 ( V_134 . V_146 ) ;
F_41 ( V_134 . V_101 ) ;
F_82 ( & V_18 ) ;
return V_6 ;
}
static void F_127 ( void )
{
struct V_95 * V_155 , * V_156 ;
F_45 ( & V_36 ) ;
if ( V_157 )
goto V_23;
V_157 = true ;
F_128 ( & V_158 ) ;
F_129 (g, p) {
F_76 ( ! F_39 ( & V_155 -> V_159 ) ||
F_86 ( V_155 ) != & V_24 ) ;
F_130 ( & V_155 -> V_160 -> V_161 ) ;
if ( ! ( V_155 -> V_25 & V_162 ) ) {
struct V_42 * V_43 = F_86 ( V_155 ) ;
F_58 ( & V_155 -> V_159 , & V_43 -> V_77 ) ;
F_47 ( V_43 ) ;
}
F_131 ( & V_155 -> V_160 -> V_161 ) ;
} F_132 ( V_156 , V_155 ) ;
F_133 ( & V_158 ) ;
V_23:
F_46 ( & V_36 ) ;
}
static void F_134 ( struct V_9 * V_10 )
{
struct V_15 * V_16 ;
int V_47 ;
F_56 ( & V_10 -> V_13 . V_163 ) ;
F_56 ( & V_10 -> V_13 . V_91 ) ;
F_56 ( & V_10 -> V_54 ) ;
F_56 ( & V_10 -> V_164 ) ;
F_135 ( & V_10 -> V_165 ) ;
V_10 -> V_13 . V_9 = V_10 ;
V_10 -> V_13 . V_25 |= V_26 ;
F_33 (ss, ssid)
F_56 ( & V_10 -> V_83 [ V_47 ] ) ;
F_136 ( & V_10 -> V_166 ) ;
F_137 ( & V_10 -> V_167 , V_168 ) ;
}
static void F_138 ( struct V_68 * V_19 ,
struct V_133 * V_134 )
{
struct V_9 * V_10 = & V_19 -> V_10 ;
F_56 ( & V_19 -> V_93 ) ;
F_67 ( & V_19 -> V_90 , 1 ) ;
V_10 -> V_19 = V_19 ;
F_134 ( V_10 ) ;
F_139 ( & V_19 -> V_89 ) ;
V_19 -> V_25 = V_134 -> V_25 ;
if ( V_134 -> V_146 )
strcpy ( V_19 -> V_130 , V_134 -> V_146 ) ;
if ( V_134 -> V_101 )
strcpy ( V_19 -> V_101 , V_134 -> V_101 ) ;
if ( V_134 -> V_145 )
F_140 ( V_131 , & V_19 -> V_10 . V_25 ) ;
}
static int F_141 ( struct V_68 * V_19 , unsigned long V_119 )
{
F_142 ( V_71 ) ;
struct V_9 * V_86 = & V_19 -> V_10 ;
struct V_31 * V_169 ;
struct V_42 * V_43 ;
int V_41 , V_6 ;
F_17 ( & V_18 ) ;
V_6 = F_1 ( & V_19 -> V_89 , V_86 , 1 , 2 , V_170 ) ;
if ( V_6 < 0 )
goto V_171;
V_86 -> V_8 = V_6 ;
V_6 = F_143 ( & V_86 -> V_13 . V_172 , V_173 , 0 ,
V_72 ) ;
if ( V_6 )
goto V_171;
V_6 = F_55 ( V_51 , & V_71 ) ;
if ( V_6 )
goto V_174;
V_6 = F_72 ( V_19 ) ;
if ( V_6 )
goto V_174;
V_19 -> V_85 = F_144 ( & V_175 ,
V_176 ,
V_86 ) ;
if ( F_145 ( V_19 -> V_85 ) ) {
V_6 = F_146 ( V_19 -> V_85 ) ;
goto V_177;
}
V_86 -> V_29 = V_19 -> V_85 -> V_29 ;
if ( V_19 == & V_92 )
V_169 = V_178 ;
else
V_169 = V_179 ;
V_6 = F_105 ( V_86 , V_169 , true ) ;
if ( V_6 )
goto V_180;
V_6 = F_81 ( V_19 , V_119 ) ;
if ( V_6 )
goto V_180;
F_58 ( & V_19 -> V_93 , & V_181 ) ;
V_76 ++ ;
F_45 ( & V_36 ) ;
F_112 (css_set_table, i, cset, hlist)
F_59 ( & V_71 , V_43 , V_86 ) ;
F_46 ( & V_36 ) ;
F_50 ( ! F_39 ( & V_86 -> V_13 . V_91 ) ) ;
F_50 ( F_80 ( & V_19 -> V_90 ) != 1 ) ;
F_114 ( V_86 -> V_29 ) ;
V_6 = 0 ;
goto V_171;
V_180:
F_83 ( V_19 -> V_85 ) ;
V_19 -> V_85 = NULL ;
V_177:
F_74 ( V_19 ) ;
V_174:
F_147 ( & V_86 -> V_13 . V_172 ) ;
V_171:
F_54 ( & V_71 ) ;
return V_6 ;
}
static struct V_182 * F_148 ( struct V_183 * V_184 ,
int V_25 , const char * V_185 ,
void * V_132 )
{
struct V_186 * V_187 = NULL ;
struct V_15 * V_16 ;
struct V_68 * V_19 ;
struct V_133 V_134 ;
struct V_182 * V_182 ;
int V_6 ;
int V_41 ;
bool V_188 ;
if ( ! V_157 )
F_127 () ;
F_79 ( & V_18 ) ;
V_6 = F_120 ( V_132 , & V_134 ) ;
if ( V_6 )
goto V_23;
if ( V_134 . V_25 & V_144 ) {
V_123 = true ;
V_19 = & V_92 ;
F_89 ( & V_19 -> V_10 ) ;
V_6 = 0 ;
goto V_23;
}
F_33 (ss, i) {
if ( ! ( V_134 . V_20 & ( 1 << V_41 ) ) ||
V_16 -> V_19 == & V_92 )
continue;
if ( ! F_149 ( & V_16 -> V_19 -> V_10 . V_13 . V_172 ) ) {
F_82 ( & V_18 ) ;
F_150 ( 10 ) ;
V_6 = F_151 () ;
goto V_189;
}
F_92 ( & V_16 -> V_19 -> V_10 ) ;
}
F_152 (root) {
bool V_190 = false ;
if ( V_19 == & V_92 )
continue;
if ( V_134 . V_101 ) {
if ( strcmp ( V_134 . V_101 , V_19 -> V_101 ) )
continue;
V_190 = true ;
}
if ( ( V_134 . V_20 || V_134 . V_143 ) &&
( V_134 . V_20 != V_19 -> V_20 ) ) {
if ( ! V_190 )
continue;
V_6 = - V_121 ;
goto V_23;
}
if ( V_19 -> V_25 ^ V_134 . V_25 )
F_108 ( L_25 ) ;
V_187 = F_153 ( V_19 -> V_85 , NULL ) ;
if ( F_145 ( V_187 ) ||
! F_149 ( & V_19 -> V_10 . V_13 . V_172 ) ) {
F_82 ( & V_18 ) ;
if ( ! F_154 ( V_187 ) )
F_155 ( V_187 ) ;
F_150 ( 10 ) ;
V_6 = F_151 () ;
goto V_189;
}
V_6 = 0 ;
goto V_23;
}
if ( ! V_134 . V_20 && ! V_134 . V_143 ) {
V_6 = - V_142 ;
goto V_23;
}
V_19 = F_57 ( sizeof( * V_19 ) , V_72 ) ;
if ( ! V_19 ) {
V_6 = - V_73 ;
goto V_23;
}
F_138 ( V_19 , & V_134 ) ;
V_6 = F_141 ( V_19 , V_134 . V_20 ) ;
if ( V_6 )
F_75 ( V_19 ) ;
V_23:
F_82 ( & V_18 ) ;
V_189:
F_41 ( V_134 . V_146 ) ;
F_41 ( V_134 . V_101 ) ;
if ( V_6 )
return F_156 ( V_6 ) ;
V_182 = F_157 ( V_184 , V_25 , V_19 -> V_85 ,
V_191 , & V_188 ) ;
if ( F_145 ( V_182 ) || ! V_188 )
F_92 ( & V_19 -> V_10 ) ;
if ( V_187 ) {
F_109 ( V_188 ) ;
F_155 ( V_187 ) ;
}
return V_182 ;
}
static void F_158 ( struct V_186 * V_192 )
{
struct V_84 * V_85 = F_159 ( V_192 ) ;
struct V_68 * V_19 = F_71 ( V_85 ) ;
if ( ! F_39 ( & V_19 -> V_10 . V_13 . V_91 ) ||
V_19 == & V_92 )
F_92 ( & V_19 -> V_10 ) ;
else
F_160 ( & V_19 -> V_10 . V_13 . V_172 ) ;
F_161 ( V_192 ) ;
}
char * F_162 ( struct V_95 * V_96 , char * V_97 , T_3 V_193 )
{
struct V_68 * V_19 ;
struct V_9 * V_10 ;
int V_88 = 1 ;
char * V_194 = NULL ;
F_79 ( & V_18 ) ;
F_65 ( & V_36 ) ;
V_19 = F_163 ( & V_87 , & V_88 ) ;
if ( V_19 ) {
V_10 = F_85 ( V_96 , V_19 ) ;
V_194 = F_164 ( V_10 , V_97 , V_193 ) ;
} else {
if ( F_165 ( V_97 , L_26 , V_193 ) < V_193 )
V_194 = V_97 ;
}
F_66 ( & V_36 ) ;
F_82 ( & V_18 ) ;
return V_194 ;
}
struct V_95 * F_166 ( struct V_195 * V_196 )
{
V_196 -> V_197 = F_61 ( V_196 -> V_198 , struct V_42 , V_80 ) ;
V_196 -> V_199 = NULL ;
return F_167 ( V_196 ) ;
}
struct V_95 * F_167 ( struct V_195 * V_196 )
{
struct V_42 * V_43 = V_196 -> V_197 ;
struct V_95 * V_96 = V_196 -> V_199 ;
while ( & V_43 -> V_80 != V_196 -> V_198 ) {
if ( ! V_96 )
V_96 = F_61 ( & V_43 -> V_78 ,
struct V_95 , V_159 ) ;
else
V_96 = F_168 ( V_96 , V_159 ) ;
if ( & V_96 -> V_159 != & V_43 -> V_78 ) {
V_196 -> V_197 = V_43 ;
V_196 -> V_199 = V_96 ;
return V_96 ;
}
V_43 = F_168 ( V_43 , V_80 ) ;
V_96 = NULL ;
}
return NULL ;
}
static void F_169 ( struct V_9 * V_200 ,
struct V_95 * V_201 ,
struct V_42 * V_202 )
{
struct V_42 * V_56 ;
F_17 ( & V_18 ) ;
F_17 ( & V_36 ) ;
F_76 ( V_201 -> V_25 & V_162 ) ;
V_56 = F_86 ( V_201 ) ;
F_47 ( V_202 ) ;
F_111 ( V_201 -> V_203 , V_202 ) ;
F_113 ( & V_201 -> V_159 , & V_202 -> V_78 ) ;
F_34 ( V_56 ) ;
}
static void F_170 ( struct V_59 * V_204 )
{
struct V_42 * V_43 , * V_205 ;
F_17 ( & V_18 ) ;
F_45 ( & V_36 ) ;
F_38 (cset, tmp_cset, preloaded_csets, mg_preload_node) {
V_43 -> V_206 = NULL ;
V_43 -> V_207 = NULL ;
F_171 ( & V_43 -> V_79 ) ;
F_34 ( V_43 ) ;
}
F_46 ( & V_36 ) ;
}
static void F_172 ( struct V_42 * V_208 ,
struct V_9 * V_209 ,
struct V_59 * V_204 )
{
struct V_9 * V_210 ;
F_17 ( & V_18 ) ;
F_17 ( & V_36 ) ;
V_210 = F_84 ( V_208 , V_209 -> V_19 ) ;
if ( ! F_39 ( & V_208 -> V_79 ) )
return;
F_109 ( V_208 -> V_206 ) ;
F_109 ( ! F_39 ( & V_208 -> V_78 ) ) ;
F_109 ( ! F_39 ( & V_208 -> V_80 ) ) ;
V_208 -> V_206 = V_210 ;
F_47 ( V_208 ) ;
F_58 ( & V_208 -> V_79 , V_204 ) ;
}
static int F_173 ( struct V_9 * V_209 ,
struct V_59 * V_204 )
{
F_142 ( V_198 ) ;
struct V_42 * V_208 , * V_205 ;
F_17 ( & V_18 ) ;
if ( V_209 && F_60 ( V_209 ) && F_11 ( V_209 ) &&
V_209 -> V_21 )
return - V_121 ;
F_38 (src_cset, tmp_cset, preloaded_csets, mg_preload_node) {
struct V_42 * V_211 ;
V_211 = F_64 ( V_208 ,
V_209 ? : V_208 -> V_74 ) ;
if ( ! V_211 )
goto V_212;
F_76 ( V_208 -> V_207 || V_211 -> V_207 ) ;
if ( V_208 == V_211 ) {
V_208 -> V_206 = NULL ;
F_171 ( & V_208 -> V_79 ) ;
F_43 ( V_208 ) ;
F_43 ( V_211 ) ;
continue;
}
V_208 -> V_207 = V_211 ;
if ( F_39 ( & V_211 -> V_79 ) )
F_58 ( & V_211 -> V_79 , & V_198 ) ;
else
F_43 ( V_211 ) ;
}
F_174 ( & V_198 , V_204 ) ;
return 0 ;
V_212:
F_170 ( & V_198 ) ;
return - V_73 ;
}
static int F_175 ( struct V_9 * V_10 , struct V_95 * V_213 ,
bool V_214 )
{
struct V_195 V_196 = {
. V_215 = F_176 ( V_196 . V_215 ) ,
. V_216 = F_176 ( V_196 . V_216 ) ,
. V_198 = & V_196 . V_215 ,
} ;
struct V_11 * V_22 , * V_217 = NULL ;
struct V_42 * V_43 , * V_205 ;
struct V_95 * V_96 , * V_218 ;
int V_41 , V_6 ;
F_45 ( & V_36 ) ;
F_19 () ;
V_96 = V_213 ;
do {
if ( V_96 -> V_25 & V_162 )
goto V_67;
if ( F_39 ( & V_96 -> V_159 ) )
goto V_67;
V_43 = F_86 ( V_96 ) ;
if ( ! V_43 -> V_206 )
goto V_67;
F_113 ( & V_96 -> V_159 , & V_43 -> V_78 ) ;
if ( F_39 ( & V_43 -> V_80 ) )
F_63 ( & V_43 -> V_80 , & V_196 . V_215 ) ;
if ( F_39 ( & V_43 -> V_207 -> V_80 ) )
F_113 ( & V_43 -> V_207 -> V_80 ,
& V_196 . V_216 ) ;
V_67:
if ( ! V_214 )
break;
} while_each_thread(leader, task) ;
int F_177 ( struct V_9 * V_209 ,
struct V_95 * V_213 , bool V_214 )
{
F_142 ( V_204 ) ;
struct V_95 * V_96 ;
int V_6 ;
F_65 ( & V_36 ) ;
F_19 () ;
V_96 = V_213 ;
do {
F_172 ( F_86 ( V_96 ) , V_209 ,
& V_204 ) ;
if ( ! V_214 )
break;
} while_each_thread(leader, task) ;
int F_178 ( struct V_95 * V_96 ,
struct V_9 * V_209 ,
struct V_27 * V_28 )
{
const struct V_219 * V_219 = F_179 () ;
const struct V_219 * V_220 = F_180 ( V_96 ) ;
int V_6 = 0 ;
if ( ! F_181 ( V_219 -> V_221 , V_222 ) &&
! F_181 ( V_219 -> V_221 , V_220 -> V_223 ) &&
! F_181 ( V_219 -> V_221 , V_220 -> V_224 ) )
V_6 = - V_225 ;
if ( ! V_6 && F_60 ( V_209 ) ) {
struct V_186 * V_192 = V_28 -> V_226 -> V_227 . V_182 -> V_228 ;
struct V_9 * V_10 ;
struct V_229 * V_229 ;
F_65 ( & V_36 ) ;
V_10 = F_85 ( V_96 , & V_92 ) ;
F_66 ( & V_36 ) ;
while ( ! F_27 ( V_209 , V_10 ) )
V_10 = F_11 ( V_10 ) ;
V_6 = - V_73 ;
V_229 = F_182 ( V_192 , V_10 -> V_230 ) ;
if ( V_229 ) {
V_6 = F_183 ( V_229 , V_231 ) ;
F_184 ( V_229 ) ;
}
}
F_185 ( V_220 ) ;
return V_6 ;
}
static T_4 F_186 ( struct V_27 * V_28 , char * V_97 ,
T_3 V_232 , T_5 V_233 , bool V_214 )
{
struct V_95 * V_201 ;
struct V_9 * V_10 ;
T_6 V_234 ;
int V_6 ;
if ( F_187 ( F_188 ( V_97 ) , 0 , & V_234 ) || V_234 < 0 )
return - V_142 ;
V_10 = F_100 ( V_28 -> V_29 ) ;
if ( ! V_10 )
return - V_235 ;
F_189 ( & V_236 ) ;
F_19 () ;
if ( V_234 ) {
V_201 = F_190 ( V_234 ) ;
if ( ! V_201 ) {
V_6 = - V_237 ;
goto V_238;
}
} else {
V_201 = V_153 ;
}
if ( V_214 )
V_201 = V_201 -> V_239 ;
if ( V_201 == V_240 || ( V_201 -> V_25 & V_241 ) ) {
V_6 = - V_142 ;
goto V_238;
}
F_191 ( V_201 ) ;
F_22 () ;
V_6 = F_178 ( V_201 , V_10 , V_28 ) ;
if ( ! V_6 )
V_6 = F_177 ( V_10 , V_201 , V_214 ) ;
F_192 ( V_201 ) ;
goto V_242;
V_238:
F_22 () ;
V_242:
F_193 ( & V_236 ) ;
F_97 ( V_28 -> V_29 ) ;
return V_6 ? : V_232 ;
}
int F_194 ( struct V_95 * V_243 , struct V_95 * V_201 )
{
struct V_68 * V_19 ;
int V_244 = 0 ;
F_79 ( & V_18 ) ;
F_152 (root) {
struct V_9 * V_245 ;
if ( V_19 == & V_92 )
continue;
F_65 ( & V_36 ) ;
V_245 = F_85 ( V_243 , V_19 ) ;
F_66 ( & V_36 ) ;
V_244 = F_177 ( V_245 , V_201 , false ) ;
if ( V_244 )
break;
}
F_82 ( & V_18 ) ;
return V_244 ;
}
static T_4 F_195 ( struct V_27 * V_28 ,
char * V_97 , T_3 V_232 , T_5 V_233 )
{
return F_186 ( V_28 , V_97 , V_232 , V_233 , false ) ;
}
static T_4 F_196 ( struct V_27 * V_28 ,
char * V_97 , T_3 V_232 , T_5 V_233 )
{
return F_186 ( V_28 , V_97 , V_232 , V_233 , true ) ;
}
static T_4 F_197 ( struct V_27 * V_28 ,
char * V_97 , T_3 V_232 , T_5 V_233 )
{
struct V_9 * V_10 ;
F_198 ( sizeof( V_10 -> V_19 -> V_130 ) < V_147 ) ;
V_10 = F_100 ( V_28 -> V_29 ) ;
if ( ! V_10 )
return - V_235 ;
F_118 ( & V_129 ) ;
F_165 ( V_10 -> V_19 -> V_130 , F_188 ( V_97 ) ,
sizeof( V_10 -> V_19 -> V_130 ) ) ;
F_119 ( & V_129 ) ;
F_97 ( V_28 -> V_29 ) ;
return V_232 ;
}
static int F_199 ( struct V_126 * V_127 , void * V_246 )
{
struct V_9 * V_10 = F_200 ( V_127 ) -> V_9 ;
F_118 ( & V_129 ) ;
F_117 ( V_127 , V_10 -> V_19 -> V_130 ) ;
F_119 ( & V_129 ) ;
F_201 ( V_127 , '\n' ) ;
return 0 ;
}
static int F_202 ( struct V_126 * V_127 , void * V_246 )
{
F_117 ( V_127 , L_27 ) ;
return 0 ;
}
static void F_203 ( struct V_126 * V_127 , unsigned long V_119 )
{
struct V_15 * V_16 ;
bool V_247 = false ;
int V_47 ;
F_95 (ss, ssid, &ss_mask) {
if ( V_247 )
F_201 ( V_127 , ' ' ) ;
F_116 ( V_127 , L_28 , V_16 -> V_101 ) ;
V_247 = true ;
}
if ( V_247 )
F_201 ( V_127 , '\n' ) ;
}
static int F_204 ( struct V_126 * V_127 , void * V_246 )
{
struct V_9 * V_10 = F_200 ( V_127 ) -> V_9 ;
F_203 ( V_127 , V_10 -> V_19 -> V_20 &
~ V_122 ) ;
return 0 ;
}
static int F_205 ( struct V_126 * V_127 , void * V_246 )
{
struct V_9 * V_10 = F_200 ( V_127 ) -> V_9 ;
F_203 ( V_127 , F_11 ( V_10 ) -> V_111 ) ;
return 0 ;
}
static int F_206 ( struct V_126 * V_127 , void * V_246 )
{
struct V_9 * V_10 = F_200 ( V_127 ) -> V_9 ;
F_203 ( V_127 , V_10 -> V_111 ) ;
return 0 ;
}
static int F_207 ( struct V_9 * V_10 )
{
F_142 ( V_204 ) ;
struct V_11 * V_22 ;
struct V_42 * V_208 ;
int V_6 ;
F_17 ( & V_18 ) ;
F_189 ( & V_236 ) ;
F_65 ( & V_36 ) ;
F_208 (css, cgroup_css(cgrp, NULL)) {
struct V_44 * V_45 ;
if ( V_22 -> V_9 == V_10 )
continue;
F_69 (link, &css->cgroup->cset_links, cset_link)
F_172 ( V_45 -> V_43 , V_10 ,
& V_204 ) ;
}
F_66 ( & V_36 ) ;
V_6 = F_173 ( NULL , & V_204 ) ;
if ( V_6 )
goto V_248;
F_69 (src_cset, &preloaded_csets, mg_preload_node) {
struct V_95 * V_249 = NULL , * V_96 ;
if ( ! V_208 -> V_206 )
break;
while ( true ) {
F_65 ( & V_36 ) ;
V_96 = F_209 ( & V_208 -> V_77 ,
struct V_95 , V_159 ) ;
if ( V_96 ) {
V_96 = V_96 -> V_239 ;
F_76 ( ! F_86 ( V_96 ) -> V_206 ) ;
F_191 ( V_96 ) ;
}
F_66 ( & V_36 ) ;
if ( ! V_96 )
break;
if ( F_210 ( V_249 == V_96 ,
L_29 ) )
goto V_248;
V_249 = V_96 ;
V_6 = F_175 ( V_208 -> V_74 , V_96 , true ) ;
F_192 ( V_96 ) ;
if ( F_210 ( V_6 , L_30 , V_6 ) )
goto V_248;
}
}
V_248:
F_170 ( & V_204 ) ;
F_193 ( & V_236 ) ;
return V_6 ;
}
static T_4 F_211 ( struct V_27 * V_28 ,
char * V_97 , T_3 V_232 ,
T_5 V_233 )
{
unsigned long V_250 = 0 , V_251 = 0 ;
unsigned long V_252 , V_253 , V_254 , V_255 , V_256 , V_257 ;
struct V_9 * V_10 , * V_258 ;
struct V_15 * V_16 ;
char * V_259 ;
int V_47 , V_6 ;
V_97 = F_188 ( V_97 ) ;
while ( ( V_259 = F_122 ( & V_97 , L_31 ) ) ) {
unsigned long V_120 = ~ V_122 ;
if ( V_259 [ 0 ] == '\0' )
continue;
F_95 (ss, ssid, &tmp_ss_mask) {
if ( V_16 -> V_149 || strcmp ( V_259 + 1 , V_16 -> V_101 ) )
continue;
if ( * V_259 == '+' ) {
V_250 |= 1 << V_47 ;
V_251 &= ~ ( 1 << V_47 ) ;
} else if ( * V_259 == '-' ) {
V_251 |= 1 << V_47 ;
V_250 &= ~ ( 1 << V_47 ) ;
} else {
return - V_142 ;
}
break;
}
if ( V_47 == V_75 )
return - V_142 ;
}
V_10 = F_100 ( V_28 -> V_29 ) ;
if ( ! V_10 )
return - V_235 ;
F_33 (ss, ssid) {
if ( V_250 & ( 1 << V_47 ) ) {
if ( V_10 -> V_111 & ( 1 << V_47 ) ) {
V_250 &= ~ ( 1 << V_47 ) ;
continue;
}
if ( ! ( V_92 . V_20 & ( 1 << V_47 ) ) ||
( F_11 ( V_10 ) &&
! ( F_11 ( V_10 ) -> V_111 & ( 1 << V_47 ) ) ) ) {
V_6 = - V_150 ;
goto V_23;
}
} else if ( V_251 & ( 1 << V_47 ) ) {
if ( ! ( V_10 -> V_111 & ( 1 << V_47 ) ) ) {
V_251 &= ~ ( 1 << V_47 ) ;
continue;
}
F_212 (child, cgrp) {
if ( V_258 -> V_111 & ( 1 << V_47 ) ) {
V_6 = - V_121 ;
goto V_23;
}
}
}
}
if ( ! V_250 && ! V_251 ) {
V_6 = 0 ;
goto V_23;
}
if ( V_250 && F_11 ( V_10 ) && ! F_39 ( & V_10 -> V_54 ) ) {
V_6 = - V_121 ;
goto V_23;
}
V_254 = V_10 -> V_111 ;
V_256 = V_10 -> V_21 ;
V_255 = ( V_254 | V_250 ) & ~ V_251 ;
V_257 = F_94 ( V_10 , V_255 ) ;
V_252 = ~ V_256 & V_257 ;
V_253 = V_256 & ~ V_257 ;
V_250 |= V_252 ;
V_251 |= V_253 ;
F_95 (ss, ssid, &css_enable) {
F_212 (child, cgrp) {
F_213 ( V_260 ) ;
if ( ! F_13 ( V_258 , V_16 ) )
continue;
F_89 ( V_258 ) ;
F_214 ( & V_258 -> V_166 , & V_260 ,
V_261 ) ;
F_97 ( V_28 -> V_29 ) ;
F_215 () ;
F_216 ( & V_258 -> V_166 , & V_260 ) ;
F_92 ( V_258 ) ;
return F_151 () ;
}
}
V_10 -> V_111 = V_255 ;
V_10 -> V_21 = V_257 ;
F_33 (ss, ssid) {
if ( ! ( V_250 & ( 1 << V_47 ) ) )
continue;
F_212 (child, cgrp) {
if ( V_252 & ( 1 << V_47 ) )
V_6 = F_217 ( V_258 , V_16 ,
V_10 -> V_111 & ( 1 << V_47 ) ) ;
else
V_6 = F_107 ( V_258 , 1 << V_47 ) ;
if ( V_6 )
goto V_262;
}
}
V_6 = F_207 ( V_10 ) ;
if ( V_6 )
goto V_262;
F_33 (ss, ssid) {
if ( ! ( V_251 & ( 1 << V_47 ) ) )
continue;
F_212 (child, cgrp) {
struct V_11 * V_22 = F_13 ( V_258 , V_16 ) ;
if ( V_253 & ( 1 << V_47 ) ) {
F_218 ( V_22 ) ;
} else {
F_104 ( V_258 , 1 << V_47 ) ;
if ( V_16 -> V_263 )
V_16 -> V_263 ( V_22 ) ;
}
}
}
F_33 (ss, ssid) {
struct V_11 * V_264 = F_13 ( V_10 , V_16 ) ;
struct V_11 * V_22 ;
if ( ! V_16 -> V_265 || ! V_264 )
continue;
F_208 (css, this_css)
if ( V_22 != V_264 )
V_16 -> V_265 ( V_22 ) ;
}
F_114 ( V_10 -> V_29 ) ;
V_6 = 0 ;
V_23:
F_97 ( V_28 -> V_29 ) ;
return V_6 ? : V_232 ;
V_262:
V_10 -> V_111 = V_254 ;
V_10 -> V_21 = V_256 ;
F_33 (ss, ssid) {
if ( ! ( V_250 & ( 1 << V_47 ) ) )
continue;
F_212 (child, cgrp) {
struct V_11 * V_22 = F_13 ( V_258 , V_16 ) ;
if ( ! V_22 )
continue;
if ( V_252 & ( 1 << V_47 ) )
F_218 ( V_22 ) ;
else
F_104 ( V_258 , 1 << V_47 ) ;
}
}
goto V_23;
}
static int F_219 ( struct V_126 * V_127 , void * V_246 )
{
F_116 ( V_127 , L_32 , ( bool ) F_200 ( V_127 ) -> V_9 -> V_38 ) ;
return 0 ;
}
static T_4 F_220 ( struct V_27 * V_28 , char * V_97 ,
T_3 V_232 , T_5 V_233 )
{
struct V_9 * V_10 = V_28 -> V_29 -> V_14 -> V_30 ;
struct V_31 * V_32 = V_28 -> V_29 -> V_30 ;
struct V_11 * V_22 ;
int V_6 ;
if ( V_32 -> V_109 )
return V_32 -> V_109 ( V_28 , V_97 , V_232 , V_233 ) ;
F_19 () ;
V_22 = F_13 ( V_10 , V_32 -> V_16 ) ;
F_22 () ;
if ( V_32 -> V_107 ) {
unsigned long long V_246 ;
V_6 = F_221 ( V_97 , 0 , & V_246 ) ;
if ( ! V_6 )
V_6 = V_32 -> V_107 ( V_22 , V_32 , V_246 ) ;
} else if ( V_32 -> V_108 ) {
long long V_246 ;
V_6 = F_222 ( V_97 , 0 , & V_246 ) ;
if ( ! V_6 )
V_6 = V_32 -> V_108 ( V_22 , V_32 , V_246 ) ;
} else {
V_6 = - V_142 ;
}
return V_6 ? : V_232 ;
}
static void * F_223 ( struct V_126 * V_127 , T_5 * V_266 )
{
return F_224 ( V_127 ) -> F_225 ( V_127 , V_266 ) ;
}
static void * F_226 ( struct V_126 * V_127 , void * V_246 , T_5 * V_266 )
{
return F_224 ( V_127 ) -> F_227 ( V_127 , V_246 , V_266 ) ;
}
static void F_228 ( struct V_126 * V_127 , void * V_246 )
{
F_224 ( V_127 ) -> F_229 ( V_127 , V_246 ) ;
}
static int F_230 ( struct V_126 * V_267 , void * V_268 )
{
struct V_31 * V_32 = F_224 ( V_267 ) ;
struct V_11 * V_22 = F_200 ( V_267 ) ;
if ( V_32 -> V_105 )
return V_32 -> V_105 ( V_267 , V_268 ) ;
if ( V_32 -> V_103 )
F_116 ( V_267 , L_33 , V_32 -> V_103 ( V_22 , V_32 ) ) ;
else if ( V_32 -> V_104 )
F_116 ( V_267 , L_34 , V_32 -> V_104 ( V_22 , V_32 ) ) ;
else
return - V_142 ;
return 0 ;
}
static int F_231 ( struct V_115 * V_29 , struct V_115 * V_269 ,
const char * V_270 )
{
struct V_9 * V_10 = V_29 -> V_30 ;
int V_6 ;
if ( F_98 ( V_29 ) != V_116 )
return - V_271 ;
if ( V_29 -> V_14 != V_269 )
return - V_272 ;
if ( F_60 ( V_10 ) )
return - V_273 ;
F_101 ( V_269 ) ;
F_101 ( V_29 ) ;
F_79 ( & V_18 ) ;
V_6 = F_232 ( V_29 , V_269 , V_270 ) ;
F_82 ( & V_18 ) ;
F_99 ( V_29 ) ;
F_99 ( V_269 ) ;
return V_6 ;
}
static int F_233 ( struct V_115 * V_29 )
{
struct V_274 V_274 = { . V_275 = V_276 | V_277 ,
. V_278 = F_234 () ,
. V_279 = F_235 () , } ;
if ( F_181 ( V_274 . V_278 , V_222 ) &&
F_236 ( V_274 . V_279 , V_280 ) )
return 0 ;
return F_237 ( V_29 , & V_274 ) ;
}
static int F_238 ( struct V_9 * V_10 , struct V_31 * V_32 )
{
char V_101 [ V_100 ] ;
struct V_115 * V_29 ;
struct V_281 * V_40 = NULL ;
int V_6 ;
#ifdef F_239
V_40 = & V_32 -> V_282 ;
#endif
V_29 = F_240 ( V_10 -> V_29 , F_87 ( V_10 , V_32 , V_101 ) ,
F_88 ( V_32 ) , 0 , V_32 -> V_283 , V_32 ,
NULL , V_40 ) ;
if ( F_145 ( V_29 ) )
return F_146 ( V_29 ) ;
V_6 = F_233 ( V_29 ) ;
if ( V_6 ) {
F_241 ( V_29 ) ;
return V_6 ;
}
if ( V_32 -> V_109 == F_196 )
V_10 -> V_230 = V_29 ;
else if ( V_32 -> V_105 == F_219 )
V_10 -> V_39 = V_29 ;
return 0 ;
}
static int F_105 ( struct V_9 * V_10 , struct V_31 V_117 [] ,
bool V_284 )
{
struct V_31 * V_32 ;
int V_6 ;
F_17 ( & V_18 ) ;
for ( V_32 = V_117 ; V_32 -> V_101 [ 0 ] != '\0' ; V_32 ++ ) {
if ( ( V_32 -> V_25 & V_285 ) && ! F_60 ( V_10 ) )
continue;
if ( ( V_32 -> V_25 & V_286 ) && F_60 ( V_10 ) )
continue;
if ( ( V_32 -> V_25 & V_287 ) && ! F_11 ( V_10 ) )
continue;
if ( ( V_32 -> V_25 & V_288 ) && F_11 ( V_10 ) )
continue;
if ( V_284 ) {
V_6 = F_238 ( V_10 , V_32 ) ;
if ( V_6 ) {
F_108 ( L_35 ,
V_289 , V_32 -> V_101 , V_6 ) ;
return V_6 ;
}
} else {
F_102 ( V_10 , V_32 ) ;
}
}
return 0 ;
}
static int F_242 ( struct V_31 * V_117 , bool V_284 )
{
F_142 ( V_290 ) ;
struct V_15 * V_16 = V_117 [ 0 ] . V_16 ;
struct V_9 * V_19 = & V_16 -> V_19 -> V_10 ;
struct V_11 * V_22 ;
int V_6 = 0 ;
F_17 ( & V_18 ) ;
F_208 (css, cgroup_css(root, ss)) {
struct V_9 * V_10 = V_22 -> V_9 ;
if ( F_23 ( V_10 ) )
continue;
V_6 = F_105 ( V_10 , V_117 , V_284 ) ;
if ( V_6 )
break;
}
if ( V_284 && ! V_6 )
F_114 ( V_19 -> V_29 ) ;
return V_6 ;
}
static void F_243 ( struct V_31 * V_117 )
{
struct V_31 * V_32 ;
for ( V_32 = V_117 ; V_32 -> V_101 [ 0 ] != '\0' ; V_32 ++ ) {
if ( V_32 -> V_291 && V_32 -> V_291 != V_292 )
F_41 ( V_32 -> V_283 ) ;
V_32 -> V_283 = NULL ;
V_32 -> V_16 = NULL ;
V_32 -> V_25 &= ~ ( V_285 | V_286 ) ;
}
}
static int F_244 ( struct V_15 * V_16 , struct V_31 * V_117 )
{
struct V_31 * V_32 ;
for ( V_32 = V_117 ; V_32 -> V_101 [ 0 ] != '\0' ; V_32 ++ ) {
struct V_293 * V_283 ;
F_109 ( V_32 -> V_16 || V_32 -> V_283 ) ;
if ( V_32 -> F_225 )
V_283 = & V_294 ;
else
V_283 = & V_295 ;
if ( V_32 -> V_291 && V_32 -> V_291 != V_292 ) {
V_283 = F_245 ( V_283 , sizeof( * V_283 ) , V_72 ) ;
if ( ! V_283 ) {
F_243 ( V_117 ) ;
return - V_73 ;
}
V_283 -> V_296 = V_32 -> V_291 ;
}
V_32 -> V_283 = V_283 ;
V_32 -> V_16 = V_16 ;
}
return 0 ;
}
static int F_246 ( struct V_31 * V_117 )
{
F_17 ( & V_18 ) ;
if ( ! V_117 || ! V_117 [ 0 ] . V_16 )
return - V_150 ;
F_36 ( & V_117 -> V_297 ) ;
F_242 ( V_117 , false ) ;
F_243 ( V_117 ) ;
return 0 ;
}
int F_247 ( struct V_31 * V_117 )
{
int V_6 ;
F_79 ( & V_18 ) ;
V_6 = F_246 ( V_117 ) ;
F_82 ( & V_18 ) ;
return V_6 ;
}
static int F_248 ( struct V_15 * V_16 , struct V_31 * V_117 )
{
int V_6 ;
if ( V_16 -> V_149 )
return 0 ;
if ( ! V_117 || V_117 [ 0 ] . V_101 [ 0 ] == '\0' )
return 0 ;
V_6 = F_244 ( V_16 , V_117 ) ;
if ( V_6 )
return V_6 ;
F_79 ( & V_18 ) ;
F_63 ( & V_117 -> V_297 , & V_16 -> V_117 ) ;
V_6 = F_242 ( V_117 , true ) ;
if ( V_6 )
F_246 ( V_117 ) ;
F_82 ( & V_18 ) ;
return V_6 ;
}
int F_249 ( struct V_15 * V_16 , struct V_31 * V_117 )
{
struct V_31 * V_32 ;
for ( V_32 = V_117 ; V_32 && V_32 -> V_101 [ 0 ] != '\0' ; V_32 ++ )
V_32 -> V_25 |= V_285 ;
return F_248 ( V_16 , V_117 ) ;
}
int F_250 ( struct V_15 * V_16 , struct V_31 * V_117 )
{
struct V_31 * V_32 ;
if ( ! V_298 ||
V_16 -> V_299 != V_16 -> V_300 ) {
for ( V_32 = V_117 ; V_32 && V_32 -> V_101 [ 0 ] != '\0' ; V_32 ++ )
V_32 -> V_25 |= V_286 ;
}
return F_248 ( V_16 , V_117 ) ;
}
static int F_251 ( const struct V_9 * V_10 )
{
int V_70 = 0 ;
struct V_44 * V_45 ;
F_65 ( & V_36 ) ;
F_69 (link, &cgrp->cset_links, cset_link)
V_70 += F_80 ( & V_45 -> V_43 -> V_48 ) ;
F_66 ( & V_36 ) ;
return V_70 ;
}
struct V_11 * F_106 ( struct V_11 * V_301 ,
struct V_11 * V_14 )
{
struct V_11 * V_67 ;
F_252 () ;
if ( ! V_301 ) {
V_67 = F_253 ( V_14 -> V_91 . V_67 , struct V_11 , V_163 ) ;
} else if ( F_254 ( ! ( V_301 -> V_25 & V_302 ) ) ) {
V_67 = F_253 ( V_301 -> V_163 . V_67 , struct V_11 , V_163 ) ;
} else {
F_255 (next, &parent->children, sibling)
if ( V_67 -> V_303 > V_301 -> V_303 )
break;
}
if ( & V_67 -> V_163 != & V_14 -> V_91 )
return V_67 ;
return NULL ;
}
struct V_11 *
F_256 ( struct V_11 * V_301 ,
struct V_11 * V_19 )
{
struct V_11 * V_67 ;
F_252 () ;
if ( ! V_301 )
return V_19 ;
V_67 = F_106 ( NULL , V_301 ) ;
if ( V_67 )
return V_67 ;
while ( V_301 != V_19 ) {
V_67 = F_106 ( V_301 , V_301 -> V_14 ) ;
if ( V_67 )
return V_67 ;
V_301 = V_301 -> V_14 ;
}
return NULL ;
}
struct V_11 *
F_257 ( struct V_11 * V_301 )
{
struct V_11 * V_304 , * V_305 ;
F_252 () ;
do {
V_304 = V_301 ;
V_301 = NULL ;
F_258 (tmp, last)
V_301 = V_305 ;
} while ( V_301 );
return V_304 ;
}
static struct V_11 *
F_259 ( struct V_11 * V_301 )
{
struct V_11 * V_304 ;
do {
V_304 = V_301 ;
V_301 = F_106 ( NULL , V_301 ) ;
} while ( V_301 );
return V_304 ;
}
struct V_11 *
F_260 ( struct V_11 * V_301 ,
struct V_11 * V_19 )
{
struct V_11 * V_67 ;
F_252 () ;
if ( ! V_301 )
return F_259 ( V_19 ) ;
if ( V_301 == V_19 )
return NULL ;
V_67 = F_106 ( V_301 , V_301 -> V_14 ) ;
if ( V_67 )
return F_259 ( V_67 ) ;
return V_301 -> V_14 ;
}
bool F_261 ( struct V_11 * V_22 )
{
struct V_11 * V_258 ;
bool V_6 = false ;
F_19 () ;
F_258 (child, css) {
if ( V_258 -> V_25 & V_26 ) {
V_6 = true ;
break;
}
}
F_22 () ;
return V_6 ;
}
static void F_262 ( struct V_306 * V_307 )
{
struct V_59 * V_308 = V_307 -> V_309 ;
struct V_44 * V_45 ;
struct V_42 * V_43 ;
do {
V_308 = V_308 -> V_67 ;
if ( V_308 == V_307 -> V_310 ) {
V_307 -> V_309 = NULL ;
return;
}
if ( V_307 -> V_16 ) {
V_43 = F_12 ( V_308 , struct V_42 ,
V_49 [ V_307 -> V_16 -> V_8 ] ) ;
} else {
V_45 = F_51 ( V_308 , struct V_44 , V_52 ) ;
V_43 = V_45 -> V_43 ;
}
} while ( F_39 ( & V_43 -> V_77 ) && F_39 ( & V_43 -> V_78 ) );
V_307 -> V_309 = V_308 ;
if ( ! F_39 ( & V_43 -> V_77 ) )
V_307 -> V_311 = V_43 -> V_77 . V_67 ;
else
V_307 -> V_311 = V_43 -> V_78 . V_67 ;
V_307 -> V_312 = & V_43 -> V_77 ;
V_307 -> V_313 = & V_43 -> V_78 ;
}
void F_263 ( struct V_11 * V_22 ,
struct V_306 * V_307 )
__acquires( V_36 )
{
F_76 ( ! V_157 ) ;
F_65 ( & V_36 ) ;
V_307 -> V_16 = V_22 -> V_16 ;
if ( V_307 -> V_16 )
V_307 -> V_309 = & V_22 -> V_9 -> V_83 [ V_22 -> V_16 -> V_8 ] ;
else
V_307 -> V_309 = & V_22 -> V_9 -> V_54 ;
V_307 -> V_310 = V_307 -> V_309 ;
F_262 ( V_307 ) ;
}
struct V_95 * F_264 ( struct V_306 * V_307 )
{
struct V_95 * V_94 ;
struct V_59 * V_308 = V_307 -> V_311 ;
if ( ! V_307 -> V_309 )
return NULL ;
V_94 = F_51 ( V_308 , struct V_95 , V_159 ) ;
V_308 = V_308 -> V_67 ;
if ( V_308 == V_307 -> V_312 )
V_308 = V_307 -> V_313 -> V_67 ;
if ( V_308 == V_307 -> V_313 )
F_262 ( V_307 ) ;
else
V_307 -> V_311 = V_308 ;
return V_94 ;
}
void F_265 ( struct V_306 * V_307 )
__releases( V_36 )
{
F_66 ( & V_36 ) ;
}
int F_266 ( struct V_9 * V_314 , struct V_9 * V_243 )
{
F_142 ( V_204 ) ;
struct V_44 * V_45 ;
struct V_306 V_307 ;
struct V_95 * V_96 ;
int V_6 ;
F_79 ( & V_18 ) ;
F_65 ( & V_36 ) ;
F_69 (link, &from->cset_links, cset_link)
F_172 ( V_45 -> V_43 , V_314 , & V_204 ) ;
F_66 ( & V_36 ) ;
V_6 = F_173 ( V_314 , & V_204 ) ;
if ( V_6 )
goto V_315;
do {
F_263 ( & V_243 -> V_13 , & V_307 ) ;
V_96 = F_264 ( & V_307 ) ;
if ( V_96 )
F_191 ( V_96 ) ;
F_265 ( & V_307 ) ;
if ( V_96 ) {
V_6 = F_175 ( V_314 , V_96 , false ) ;
F_192 ( V_96 ) ;
}
} while ( V_96 && ! V_6 );
V_315:
F_170 ( & V_204 ) ;
F_82 ( & V_18 ) ;
return V_6 ;
}
static void * F_267 ( int V_70 )
{
if ( F_268 ( V_70 ) )
return F_269 ( V_70 * sizeof( T_6 ) ) ;
else
return F_270 ( V_70 * sizeof( T_6 ) , V_72 ) ;
}
static void F_271 ( void * V_155 )
{
F_272 ( V_155 ) ;
}
static void F_273 ( struct V_9 * V_10 )
{
struct V_316 * V_308 , * V_317 ;
F_79 ( & V_10 -> V_165 ) ;
F_38 (l, tmp_l, &cgrp->pidlists, links)
F_274 ( V_318 , & V_308 -> V_319 , 0 ) ;
F_82 ( & V_10 -> V_165 ) ;
F_275 ( V_318 ) ;
F_50 ( ! F_39 ( & V_10 -> V_164 ) ) ;
}
static void F_276 ( struct V_320 * V_321 )
{
struct V_322 * V_323 = F_277 ( V_321 ) ;
struct V_316 * V_308 = F_12 ( V_323 , struct V_316 ,
V_319 ) ;
struct V_316 * V_324 = NULL ;
F_79 ( & V_308 -> V_325 -> V_165 ) ;
if ( ! F_278 ( V_323 ) ) {
F_36 ( & V_308 -> V_326 ) ;
F_271 ( V_308 -> V_327 ) ;
F_279 ( V_308 -> V_40 . V_328 ) ;
V_324 = V_308 ;
}
F_82 ( & V_308 -> V_325 -> V_165 ) ;
F_41 ( V_324 ) ;
}
static int F_280 ( T_6 * V_327 , int V_329 )
{
int V_330 , V_331 = 1 ;
if ( V_329 == 0 || V_329 == 1 )
return V_329 ;
for ( V_330 = 1 ; V_330 < V_329 ; V_330 ++ ) {
while ( V_327 [ V_330 ] == V_327 [ V_330 - 1 ] ) {
V_330 ++ ;
if ( V_330 == V_329 )
goto V_332;
}
V_327 [ V_331 ] = V_327 [ V_330 ] ;
V_331 ++ ;
}
V_332:
return V_331 ;
}
static T_6 F_281 ( T_6 V_234 )
{
unsigned V_333 = V_234 & 0x55555555 ;
unsigned V_334 = V_234 & 0xAAAAAAAA ;
return ( V_333 << 1 ) | ( V_334 >> 1 ) ;
}
static T_6 F_282 ( struct V_9 * V_10 , T_6 V_234 )
{
if ( F_60 ( V_10 ) )
return F_281 ( V_234 ) ;
else
return V_234 ;
}
static int F_283 ( const void * V_333 , const void * V_334 )
{
return * ( T_6 * ) V_333 - * ( T_6 * ) V_334 ;
}
static int F_284 ( const void * V_333 , const void * V_334 )
{
return F_281 ( * ( T_6 * ) V_333 ) - F_281 ( * ( T_6 * ) V_334 ) ;
}
static struct V_316 * F_285 ( struct V_9 * V_10 ,
enum V_335 type )
{
struct V_316 * V_308 ;
struct V_336 * V_328 = F_286 ( V_153 ) ;
F_17 ( & V_10 -> V_165 ) ;
F_69 (l, &cgrp->pidlists, links)
if ( V_308 -> V_40 . type == type && V_308 -> V_40 . V_328 == V_328 )
return V_308 ;
return NULL ;
}
static struct V_316 * F_287 ( struct V_9 * V_10 ,
enum V_335 type )
{
struct V_316 * V_308 ;
F_17 ( & V_10 -> V_165 ) ;
V_308 = F_285 ( V_10 , type ) ;
if ( V_308 )
return V_308 ;
V_308 = F_57 ( sizeof( struct V_316 ) , V_72 ) ;
if ( ! V_308 )
return V_308 ;
F_288 ( & V_308 -> V_319 , F_276 ) ;
V_308 -> V_40 . type = type ;
V_308 -> V_40 . V_328 = F_289 ( F_286 ( V_153 ) ) ;
V_308 -> V_325 = V_10 ;
F_58 ( & V_308 -> V_326 , & V_10 -> V_164 ) ;
return V_308 ;
}
static int F_290 ( struct V_9 * V_10 , enum V_335 type ,
struct V_316 * * V_337 )
{
T_6 * V_338 ;
int V_329 ;
int V_234 , V_339 = 0 ;
struct V_306 V_307 ;
struct V_95 * V_201 ;
struct V_316 * V_308 ;
F_17 ( & V_10 -> V_165 ) ;
V_329 = F_251 ( V_10 ) ;
V_338 = F_267 ( V_329 ) ;
if ( ! V_338 )
return - V_73 ;
F_263 ( & V_10 -> V_13 , & V_307 ) ;
while ( ( V_201 = F_264 ( & V_307 ) ) ) {
if ( F_291 ( V_339 == V_329 ) )
break;
if ( type == V_340 )
V_234 = F_292 ( V_201 ) ;
else
V_234 = F_293 ( V_201 ) ;
if ( V_234 > 0 )
V_338 [ V_339 ++ ] = V_234 ;
}
F_265 ( & V_307 ) ;
V_329 = V_339 ;
if ( F_60 ( V_10 ) )
F_294 ( V_338 , V_329 , sizeof( T_6 ) , F_284 , NULL ) ;
else
F_294 ( V_338 , V_329 , sizeof( T_6 ) , F_283 , NULL ) ;
if ( type == V_340 )
V_329 = F_280 ( V_338 , V_329 ) ;
V_308 = F_287 ( V_10 , type ) ;
if ( ! V_308 ) {
F_271 ( V_338 ) ;
return - V_73 ;
}
F_271 ( V_308 -> V_327 ) ;
V_308 -> V_327 = V_338 ;
V_308 -> V_329 = V_329 ;
* V_337 = V_308 ;
return 0 ;
}
int F_295 ( struct V_341 * V_342 , struct V_182 * V_182 )
{
struct V_115 * V_29 = F_296 ( V_182 ) ;
struct V_9 * V_10 ;
struct V_306 V_307 ;
struct V_95 * V_201 ;
if ( V_182 -> V_228 -> V_343 != & V_344 || ! V_29 ||
F_98 ( V_29 ) != V_116 )
return - V_142 ;
F_79 ( & V_18 ) ;
F_19 () ;
V_10 = F_297 ( V_29 -> V_30 ) ;
if ( ! V_10 || F_23 ( V_10 ) ) {
F_22 () ;
F_82 ( & V_18 ) ;
return - V_150 ;
}
F_22 () ;
F_263 ( & V_10 -> V_13 , & V_307 ) ;
while ( ( V_201 = F_264 ( & V_307 ) ) ) {
switch ( V_201 -> V_345 ) {
case V_346 :
V_342 -> V_347 ++ ;
break;
case V_348 :
V_342 -> V_349 ++ ;
break;
case V_261 :
V_342 -> V_350 ++ ;
break;
case V_351 :
V_342 -> V_352 ++ ;
break;
default:
if ( F_298 ( V_201 ) )
V_342 -> V_353 ++ ;
break;
}
}
F_265 ( & V_307 ) ;
F_82 ( & V_18 ) ;
return 0 ;
}
static void * F_299 ( struct V_126 * V_354 , T_5 * V_301 )
{
struct V_27 * V_28 = V_354 -> V_355 ;
struct V_9 * V_10 = F_200 ( V_354 ) -> V_9 ;
struct V_316 * V_308 ;
enum V_335 type = F_224 ( V_354 ) -> V_355 ;
int V_356 = 0 , V_234 = * V_301 ;
int * V_357 , V_6 ;
F_79 ( & V_10 -> V_165 ) ;
if ( V_28 -> V_30 )
V_28 -> V_30 = F_285 ( V_10 , type ) ;
if ( ! V_28 -> V_30 ) {
V_6 = F_290 ( V_10 , type ,
(struct V_316 * * ) & V_28 -> V_30 ) ;
if ( V_6 )
return F_156 ( V_6 ) ;
}
V_308 = V_28 -> V_30 ;
if ( V_234 ) {
int V_4 = V_308 -> V_329 ;
while ( V_356 < V_4 ) {
int V_358 = ( V_356 + V_4 ) / 2 ;
if ( F_282 ( V_10 , V_308 -> V_327 [ V_358 ] ) == V_234 ) {
V_356 = V_358 ;
break;
} else if ( F_282 ( V_10 , V_308 -> V_327 [ V_358 ] ) <= V_234 )
V_356 = V_358 + 1 ;
else
V_4 = V_358 ;
}
}
if ( V_356 >= V_308 -> V_329 )
return NULL ;
V_357 = V_308 -> V_327 + V_356 ;
* V_301 = F_282 ( V_10 , * V_357 ) ;
return V_357 ;
}
static void F_300 ( struct V_126 * V_354 , void * V_246 )
{
struct V_27 * V_28 = V_354 -> V_355 ;
struct V_316 * V_308 = V_28 -> V_30 ;
if ( V_308 )
F_274 ( V_318 , & V_308 -> V_319 ,
V_359 ) ;
F_82 ( & F_200 ( V_354 ) -> V_9 -> V_165 ) ;
}
static void * F_301 ( struct V_126 * V_354 , void * V_246 , T_5 * V_301 )
{
struct V_27 * V_28 = V_354 -> V_355 ;
struct V_316 * V_308 = V_28 -> V_30 ;
T_6 * V_155 = V_246 ;
T_6 * V_4 = V_308 -> V_327 + V_308 -> V_329 ;
V_155 ++ ;
if ( V_155 >= V_4 ) {
return NULL ;
} else {
* V_301 = F_282 ( F_200 ( V_354 ) -> V_9 , * V_155 ) ;
return V_155 ;
}
}
static int F_302 ( struct V_126 * V_354 , void * V_246 )
{
F_116 ( V_354 , L_32 , * ( int * ) V_246 ) ;
return 0 ;
}
static T_7 F_303 ( struct V_11 * V_22 ,
struct V_31 * V_32 )
{
return F_28 ( V_22 -> V_9 ) ;
}
static int F_304 ( struct V_11 * V_22 ,
struct V_31 * V_32 , T_7 V_360 )
{
if ( V_360 )
F_140 ( V_34 , & V_22 -> V_9 -> V_25 ) ;
else
F_305 ( V_34 , & V_22 -> V_9 -> V_25 ) ;
return 0 ;
}
static T_7 F_306 ( struct V_11 * V_22 ,
struct V_31 * V_32 )
{
return F_29 ( V_131 , & V_22 -> V_9 -> V_25 ) ;
}
static int F_307 ( struct V_11 * V_22 ,
struct V_31 * V_32 , T_7 V_360 )
{
if ( V_360 )
F_140 ( V_131 , & V_22 -> V_9 -> V_25 ) ;
else
F_305 ( V_131 , & V_22 -> V_9 -> V_25 ) ;
return 0 ;
}
static int F_107 ( struct V_9 * V_10 , unsigned long V_20 )
{
struct V_15 * V_16 ;
int V_41 , V_6 = 0 ;
F_33 (ss, i) {
struct V_31 * V_117 ;
if ( ! ( V_20 & ( 1 << V_41 ) ) )
continue;
F_69 (cfts, &ss->cfts, node) {
V_6 = F_105 ( V_10 , V_117 , true ) ;
if ( V_6 < 0 )
goto V_212;
}
}
return 0 ;
V_212:
F_104 ( V_10 , V_20 ) ;
return V_6 ;
}
static void F_308 ( struct V_320 * V_321 )
{
struct V_11 * V_22 =
F_12 ( V_321 , struct V_11 , V_361 ) ;
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_9 * V_10 = V_22 -> V_9 ;
F_147 ( & V_22 -> V_172 ) ;
if ( V_16 ) {
int V_8 = V_22 -> V_8 ;
if ( V_22 -> V_14 )
F_93 ( V_22 -> V_14 ) ;
V_16 -> V_362 ( V_22 ) ;
F_9 ( & V_16 -> V_363 , V_8 ) ;
F_92 ( V_10 ) ;
} else {
F_309 ( & V_10 -> V_19 -> V_90 ) ;
F_273 ( V_10 ) ;
F_310 ( & V_10 -> V_167 ) ;
if ( F_11 ( V_10 ) ) {
F_92 ( F_11 ( V_10 ) ) ;
F_311 ( V_10 -> V_29 ) ;
F_41 ( V_10 ) ;
} else {
F_78 ( V_10 -> V_19 ) ;
}
}
}
static void F_312 ( struct V_55 * V_55 )
{
struct V_11 * V_22 =
F_12 ( V_55 , struct V_11 , V_55 ) ;
F_137 ( & V_22 -> V_361 , F_308 ) ;
F_313 ( V_364 , & V_22 -> V_361 ) ;
}
static void F_314 ( struct V_320 * V_321 )
{
struct V_11 * V_22 =
F_12 ( V_321 , struct V_11 , V_361 ) ;
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_9 * V_10 = V_22 -> V_9 ;
F_79 ( & V_18 ) ;
V_22 -> V_25 |= V_302 ;
F_315 ( & V_22 -> V_163 ) ;
if ( V_16 ) {
F_7 ( & V_16 -> V_363 , NULL , V_22 -> V_8 ) ;
if ( V_16 -> V_365 )
V_16 -> V_365 ( V_22 ) ;
} else {
F_9 ( & V_10 -> V_19 -> V_89 , V_10 -> V_8 ) ;
V_10 -> V_8 = - 1 ;
F_110 ( * ( void V_366 V_367 * * ) & V_10 -> V_29 -> V_30 , NULL ) ;
}
F_82 ( & V_18 ) ;
F_316 ( & V_22 -> V_55 , F_312 ) ;
}
static void V_173 ( struct V_368 * V_369 )
{
struct V_11 * V_22 =
F_12 ( V_369 , struct V_11 , V_172 ) ;
F_137 ( & V_22 -> V_361 , F_314 ) ;
F_313 ( V_364 , & V_22 -> V_361 ) ;
}
static void F_317 ( struct V_11 * V_22 ,
struct V_15 * V_16 , struct V_9 * V_10 )
{
F_17 ( & V_18 ) ;
F_89 ( V_10 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_9 = V_10 ;
V_22 -> V_16 = V_16 ;
F_56 ( & V_22 -> V_163 ) ;
F_56 ( & V_22 -> V_91 ) ;
V_22 -> V_303 = V_370 ++ ;
if ( F_11 ( V_10 ) ) {
V_22 -> V_14 = F_13 ( F_11 ( V_10 ) , V_16 ) ;
F_21 ( V_22 -> V_14 ) ;
}
F_50 ( F_13 ( V_10 , V_16 ) ) ;
}
static int F_318 ( struct V_11 * V_22 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
int V_6 = 0 ;
F_17 ( & V_18 ) ;
if ( V_16 -> V_371 )
V_6 = V_16 -> V_371 ( V_22 ) ;
if ( ! V_6 ) {
V_22 -> V_25 |= V_26 ;
F_111 ( V_22 -> V_9 -> V_17 [ V_16 -> V_8 ] , V_22 ) ;
}
return V_6 ;
}
static void F_319 ( struct V_11 * V_22 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
F_17 ( & V_18 ) ;
if ( ! ( V_22 -> V_25 & V_26 ) )
return;
if ( V_16 -> V_372 )
V_16 -> V_372 ( V_22 ) ;
V_22 -> V_25 &= ~ V_26 ;
F_110 ( V_22 -> V_9 -> V_17 [ V_16 -> V_8 ] , NULL ) ;
F_320 ( & V_22 -> V_9 -> V_166 ) ;
}
static int F_217 ( struct V_9 * V_10 , struct V_15 * V_16 ,
bool V_373 )
{
struct V_9 * V_14 = F_11 ( V_10 ) ;
struct V_11 * V_12 = F_13 ( V_14 , V_16 ) ;
struct V_11 * V_22 ;
int V_212 ;
F_17 ( & V_18 ) ;
V_22 = V_16 -> V_374 ( V_12 ) ;
if ( F_145 ( V_22 ) )
return F_146 ( V_22 ) ;
F_317 ( V_22 , V_16 , V_10 ) ;
V_212 = F_143 ( & V_22 -> V_172 , V_173 , 0 , V_72 ) ;
if ( V_212 )
goto V_375;
V_212 = F_1 ( & V_16 -> V_363 , NULL , 2 , 0 , V_170 ) ;
if ( V_212 < 0 )
goto V_376;
V_22 -> V_8 = V_212 ;
if ( V_373 ) {
V_212 = F_107 ( V_10 , 1 << V_16 -> V_8 ) ;
if ( V_212 )
goto V_377;
}
F_321 ( & V_22 -> V_163 , & V_12 -> V_91 ) ;
F_7 ( & V_16 -> V_363 , V_22 , V_22 -> V_8 ) ;
V_212 = F_318 ( V_22 ) ;
if ( V_212 )
goto V_378;
if ( V_16 -> V_379 && ! V_16 -> V_380 &&
F_11 ( V_14 ) ) {
F_108 ( L_36 ,
V_153 -> V_154 , V_153 -> V_234 , V_16 -> V_101 ) ;
if ( ! strcmp ( V_16 -> V_101 , L_37 ) )
F_108 ( L_38 ) ;
V_16 -> V_380 = true ;
}
return 0 ;
V_378:
F_315 ( & V_22 -> V_163 ) ;
F_104 ( V_22 -> V_9 , 1 << V_22 -> V_16 -> V_8 ) ;
V_377:
F_9 ( & V_16 -> V_363 , V_22 -> V_8 ) ;
V_376:
F_147 ( & V_22 -> V_172 ) ;
V_375:
F_316 ( & V_22 -> V_55 , F_312 ) ;
return V_212 ;
}
static int F_322 ( struct V_115 * V_381 , const char * V_101 ,
T_2 V_102 )
{
struct V_9 * V_14 , * V_10 ;
struct V_68 * V_19 ;
struct V_15 * V_16 ;
struct V_115 * V_29 ;
struct V_31 * V_169 ;
int V_47 , V_6 ;
if ( strchr ( V_101 , '\n' ) )
return - V_142 ;
V_14 = F_100 ( V_381 ) ;
if ( ! V_14 )
return - V_235 ;
V_19 = V_14 -> V_19 ;
V_10 = F_57 ( sizeof( * V_10 ) , V_72 ) ;
if ( ! V_10 ) {
V_6 = - V_73 ;
goto V_23;
}
V_6 = F_143 ( & V_10 -> V_13 . V_172 , V_173 , 0 , V_72 ) ;
if ( V_6 )
goto V_382;
V_10 -> V_8 = F_1 ( & V_19 -> V_89 , NULL , 2 , 0 , V_170 ) ;
if ( V_10 -> V_8 < 0 ) {
V_6 = - V_73 ;
goto V_383;
}
F_134 ( V_10 ) ;
V_10 -> V_13 . V_14 = & V_14 -> V_13 ;
V_10 -> V_19 = V_19 ;
if ( F_28 ( V_14 ) )
F_140 ( V_34 , & V_10 -> V_25 ) ;
if ( F_29 ( V_131 , & V_14 -> V_25 ) )
F_140 ( V_131 , & V_10 -> V_25 ) ;
V_29 = F_323 ( V_14 -> V_29 , V_101 , V_102 , V_10 ) ;
if ( F_145 ( V_29 ) ) {
V_6 = F_146 ( V_29 ) ;
goto V_384;
}
V_10 -> V_29 = V_29 ;
F_324 ( V_29 ) ;
V_10 -> V_13 . V_303 = V_370 ++ ;
F_321 ( & V_10 -> V_13 . V_163 , & F_11 ( V_10 ) -> V_13 . V_91 ) ;
F_48 ( & V_19 -> V_90 ) ;
F_89 ( V_14 ) ;
F_7 ( & V_19 -> V_89 , V_10 , V_10 -> V_8 ) ;
V_6 = F_233 ( V_29 ) ;
if ( V_6 )
goto V_385;
if ( F_60 ( V_10 ) )
V_169 = V_178 ;
else
V_169 = V_179 ;
V_6 = F_105 ( V_10 , V_169 , true ) ;
if ( V_6 )
goto V_385;
F_33 (ss, ssid) {
if ( V_14 -> V_21 & ( 1 << V_47 ) ) {
V_6 = F_217 ( V_10 , V_16 ,
V_14 -> V_111 & ( 1 << V_47 ) ) ;
if ( V_6 )
goto V_385;
}
}
if ( ! F_60 ( V_10 ) ) {
V_10 -> V_111 = V_14 -> V_111 ;
F_96 ( V_10 ) ;
}
F_114 ( V_29 ) ;
V_6 = 0 ;
goto V_23;
V_384:
F_9 ( & V_19 -> V_89 , V_10 -> V_8 ) ;
V_383:
F_147 ( & V_10 -> V_13 . V_172 ) ;
V_382:
F_41 ( V_10 ) ;
V_23:
F_97 ( V_381 ) ;
return V_6 ;
V_385:
F_325 ( V_10 ) ;
goto V_23;
}
static void F_326 ( struct V_320 * V_321 )
{
struct V_11 * V_22 =
F_12 ( V_321 , struct V_11 , V_361 ) ;
F_79 ( & V_18 ) ;
F_319 ( V_22 ) ;
F_82 ( & V_18 ) ;
F_93 ( V_22 ) ;
}
static void F_327 ( struct V_368 * V_369 )
{
struct V_11 * V_22 =
F_12 ( V_369 , struct V_11 , V_172 ) ;
F_137 ( & V_22 -> V_361 , F_326 ) ;
F_313 ( V_364 , & V_22 -> V_361 ) ;
}
static void F_218 ( struct V_11 * V_22 )
{
F_17 ( & V_18 ) ;
F_104 ( V_22 -> V_9 , 1 << V_22 -> V_16 -> V_8 ) ;
F_21 ( V_22 ) ;
F_328 ( & V_22 -> V_172 , F_327 ) ;
}
static int F_325 ( struct V_9 * V_10 )
__releases( &cgroup_mutex
static int F_329 ( struct V_115 * V_29 )
{
struct V_9 * V_10 ;
int V_6 = 0 ;
V_10 = F_100 ( V_29 ) ;
if ( ! V_10 )
return 0 ;
V_6 = F_325 ( V_10 ) ;
F_97 ( V_29 ) ;
return V_6 ;
}
static void T_8 F_330 ( struct V_15 * V_16 , bool V_386 )
{
struct V_11 * V_22 ;
F_331 ( V_387 L_39 , V_16 -> V_101 ) ;
F_79 ( & V_18 ) ;
F_139 ( & V_16 -> V_363 ) ;
F_56 ( & V_16 -> V_117 ) ;
V_16 -> V_19 = & V_92 ;
V_22 = V_16 -> V_374 ( F_13 ( & V_92 . V_10 , V_16 ) ) ;
F_50 ( F_145 ( V_22 ) ) ;
F_317 ( V_22 , V_16 , & V_92 . V_10 ) ;
V_22 -> V_25 |= V_388 ;
if ( V_386 ) {
V_22 -> V_8 = 1 ;
} else {
V_22 -> V_8 = F_1 ( & V_16 -> V_363 , V_22 , 1 , 2 , V_72 ) ;
F_50 ( V_22 -> V_8 < 0 ) ;
}
V_24 . V_17 [ V_16 -> V_8 ] = V_22 ;
V_389 |= ( bool ) V_16 -> V_390 << V_16 -> V_8 ;
V_391 |= ( bool ) V_16 -> exit << V_16 -> V_8 ;
F_50 ( ! F_39 ( & V_392 . V_77 ) ) ;
F_50 ( F_318 ( V_22 ) ) ;
F_82 ( & V_18 ) ;
}
int T_8 F_332 ( void )
{
static struct V_133 T_9 V_134 ;
struct V_15 * V_16 ;
int V_41 ;
F_138 ( & V_92 , & V_134 ) ;
V_92 . V_10 . V_13 . V_25 |= V_388 ;
F_110 ( V_392 . V_203 , & V_24 ) ;
F_33 (ss, i) {
F_210 ( ! V_16 -> V_374 || ! V_16 -> V_362 || V_16 -> V_101 || V_16 -> V_8 ,
L_40 ,
V_41 , V_393 [ V_41 ] , V_16 -> V_374 , V_16 -> V_362 ,
V_16 -> V_8 , V_16 -> V_101 ) ;
F_210 ( strlen ( V_393 [ V_41 ] ) > V_394 ,
L_41 , V_393 [ V_41 ] ) ;
V_16 -> V_8 = V_41 ;
V_16 -> V_101 = V_393 [ V_41 ] ;
if ( V_16 -> V_395 )
F_330 ( V_16 , true ) ;
}
return 0 ;
}
int T_8 F_333 ( void )
{
struct V_15 * V_16 ;
unsigned long V_40 ;
int V_47 , V_212 ;
F_50 ( F_334 ( & V_236 ) ) ;
F_50 ( F_244 ( NULL , V_178 ) ) ;
F_50 ( F_244 ( NULL , V_179 ) ) ;
F_79 ( & V_18 ) ;
V_40 = F_32 ( V_24 . V_17 ) ;
F_70 ( V_82 , & V_24 . V_50 , V_40 ) ;
F_50 ( F_141 ( & V_92 , 0 ) ) ;
F_82 ( & V_18 ) ;
F_33 (ss, ssid) {
if ( V_16 -> V_395 ) {
struct V_11 * V_22 =
V_24 . V_17 [ V_16 -> V_8 ] ;
V_22 -> V_8 = F_1 ( & V_16 -> V_363 , V_22 , 1 , 2 ,
V_72 ) ;
F_50 ( V_22 -> V_8 < 0 ) ;
} else {
F_330 ( V_16 , false ) ;
}
F_63 ( & V_24 . V_49 [ V_47 ] ,
& V_92 . V_10 . V_83 [ V_47 ] ) ;
if ( V_16 -> V_149 )
continue;
V_92 . V_20 |= 1 << V_16 -> V_8 ;
if ( V_298 && ! V_16 -> V_299 )
V_16 -> V_299 = V_16 -> V_300 ;
if ( ! V_16 -> V_299 )
V_122 |= 1 << V_16 -> V_8 ;
if ( V_16 -> V_299 == V_16 -> V_300 ) {
F_109 ( F_248 ( V_16 , V_16 -> V_299 ) ) ;
} else {
F_109 ( F_249 ( V_16 , V_16 -> V_299 ) ) ;
F_109 ( F_250 ( V_16 , V_16 -> V_300 ) ) ;
}
if ( V_16 -> V_125 )
V_16 -> V_125 ( V_24 . V_17 [ V_47 ] ) ;
}
V_212 = F_335 ( V_396 , L_42 ) ;
if ( V_212 )
return V_212 ;
V_212 = F_336 ( & V_344 ) ;
if ( V_212 < 0 ) {
F_337 ( V_396 , L_42 ) ;
return V_212 ;
}
F_338 ( L_43 , 0 , NULL , & V_397 ) ;
return 0 ;
}
static int T_8 F_339 ( void )
{
V_364 = F_340 ( L_44 , 0 , 1 ) ;
F_50 ( ! V_364 ) ;
V_318 = F_340 ( L_45 ,
0 , 1 ) ;
F_50 ( ! V_318 ) ;
return 0 ;
}
int F_341 ( struct V_126 * V_267 , struct V_336 * V_328 ,
struct V_234 * V_234 , struct V_95 * V_201 )
{
char * V_97 , * V_194 ;
int V_244 ;
struct V_68 * V_19 ;
V_244 = - V_73 ;
V_97 = F_270 ( V_147 , V_72 ) ;
if ( ! V_97 )
goto V_171;
F_79 ( & V_18 ) ;
F_65 ( & V_36 ) ;
F_152 (root) {
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_47 , V_70 = 0 ;
if ( V_19 == & V_92 && ! V_123 )
continue;
F_116 ( V_267 , L_46 , V_19 -> V_88 ) ;
F_33 (ss, ssid)
if ( V_19 -> V_20 & ( 1 << V_47 ) )
F_116 ( V_267 , L_47 , V_70 ++ ? L_10 : L_24 , V_16 -> V_101 ) ;
if ( strlen ( V_19 -> V_101 ) )
F_116 ( V_267 , L_48 , V_70 ? L_10 : L_24 ,
V_19 -> V_101 ) ;
F_201 ( V_267 , ':' ) ;
V_10 = F_85 ( V_201 , V_19 ) ;
V_194 = F_164 ( V_10 , V_97 , V_147 ) ;
if ( ! V_194 ) {
V_244 = - V_398 ;
goto V_23;
}
F_117 ( V_267 , V_194 ) ;
F_201 ( V_267 , '\n' ) ;
}
V_244 = 0 ;
V_23:
F_66 ( & V_36 ) ;
F_82 ( & V_18 ) ;
F_41 ( V_97 ) ;
V_171:
return V_244 ;
}
static int F_342 ( struct V_126 * V_267 , void * V_246 )
{
struct V_15 * V_16 ;
int V_41 ;
F_117 ( V_267 , L_49 ) ;
F_79 ( & V_18 ) ;
F_33 (ss, i)
F_116 ( V_267 , L_50 ,
V_16 -> V_101 , V_16 -> V_19 -> V_88 ,
F_80 ( & V_16 -> V_19 -> V_90 ) , ! V_16 -> V_149 ) ;
F_82 ( & V_18 ) ;
return 0 ;
}
static int F_343 ( struct V_229 * V_229 , struct V_226 * V_226 )
{
return F_344 ( V_226 , F_342 , NULL ) ;
}
void F_345 ( struct V_95 * V_258 )
{
F_110 ( V_258 -> V_203 , & V_24 ) ;
F_56 ( & V_258 -> V_159 ) ;
}
void F_346 ( struct V_95 * V_258 )
{
struct V_15 * V_16 ;
int V_41 ;
if ( V_157 ) {
struct V_42 * V_43 ;
F_45 ( & V_36 ) ;
V_43 = F_86 ( V_153 ) ;
if ( F_39 ( & V_258 -> V_159 ) ) {
F_111 ( V_258 -> V_203 , V_43 ) ;
F_58 ( & V_258 -> V_159 , & V_43 -> V_77 ) ;
F_47 ( V_43 ) ;
}
F_46 ( & V_36 ) ;
}
F_95 (ss, i, &have_fork_callback)
V_16 -> V_390 ( V_258 ) ;
}
void F_347 ( struct V_95 * V_201 )
{
struct V_15 * V_16 ;
struct V_42 * V_43 ;
bool V_399 = false ;
int V_41 ;
if ( ! F_39 ( & V_201 -> V_159 ) ) {
F_45 ( & V_36 ) ;
F_171 ( & V_201 -> V_159 ) ;
F_46 ( & V_36 ) ;
V_399 = true ;
}
V_43 = F_86 ( V_201 ) ;
F_110 ( V_201 -> V_203 , & V_24 ) ;
F_95 (ss, i, &have_exit_callback) {
struct V_11 * V_400 = V_43 -> V_17 [ V_41 ] ;
struct V_11 * V_22 = F_348 ( V_201 , V_41 ) ;
V_16 -> exit ( V_22 , V_400 , V_201 ) ;
}
if ( V_399 )
F_43 ( V_43 ) ;
}
static void F_40 ( struct V_9 * V_10 )
{
if ( F_28 ( V_10 ) && ! F_349 ( V_10 ) &&
! F_261 ( & V_10 -> V_13 ) && ! F_23 ( V_10 ) )
F_350 ( & V_10 -> V_167 ) ;
}
static void V_168 ( struct V_320 * V_321 )
{
struct V_9 * V_10 =
F_12 ( V_321 , struct V_9 , V_167 ) ;
char * V_401 = NULL , * V_402 = NULL , * V_194 ;
char * V_403 [ 3 ] , * V_404 [ 3 ] ;
F_79 ( & V_18 ) ;
V_401 = F_270 ( V_147 , V_72 ) ;
V_402 = F_351 ( V_10 -> V_19 -> V_130 , V_72 ) ;
if ( ! V_401 || ! V_402 )
goto V_171;
V_194 = F_164 ( V_10 , V_401 , V_147 ) ;
if ( ! V_194 )
goto V_171;
V_403 [ 0 ] = V_402 ;
V_403 [ 1 ] = V_194 ;
V_403 [ 2 ] = NULL ;
V_404 [ 0 ] = L_51 ;
V_404 [ 1 ] = L_52 ;
V_404 [ 2 ] = NULL ;
F_82 ( & V_18 ) ;
F_352 ( V_403 [ 0 ] , V_403 , V_404 , V_405 ) ;
goto V_189;
V_171:
F_82 ( & V_18 ) ;
V_189:
F_41 ( V_402 ) ;
F_41 ( V_401 ) ;
}
static int T_8 F_353 ( char * V_406 )
{
struct V_15 * V_16 ;
char * V_135 ;
int V_41 ;
while ( ( V_135 = F_122 ( & V_406 , L_10 ) ) != NULL ) {
if ( ! * V_135 )
continue;
F_33 (ss, i) {
if ( ! strcmp ( V_135 , V_16 -> V_101 ) ) {
V_16 -> V_149 = 1 ;
F_331 ( V_387 L_53
L_54 , V_16 -> V_101 ) ;
break;
}
}
}
return 1 ;
}
static int T_8 F_354 ( char * V_406 )
{
F_331 ( L_55 ) ;
V_298 = true ;
return 0 ;
}
struct V_11 * F_355 ( struct V_182 * V_182 ,
struct V_15 * V_16 )
{
struct V_115 * V_29 = F_296 ( V_182 ) ;
struct V_11 * V_22 = NULL ;
struct V_9 * V_10 ;
if ( V_182 -> V_228 -> V_343 != & V_344 || ! V_29 ||
F_98 ( V_29 ) != V_116 )
return F_156 ( - V_407 ) ;
F_19 () ;
V_10 = F_297 ( V_29 -> V_30 ) ;
if ( V_10 )
V_22 = F_13 ( V_10 , V_16 ) ;
if ( ! V_22 || ! F_20 ( V_22 ) )
V_22 = F_156 ( - V_150 ) ;
F_22 () ;
return V_22 ;
}
struct V_11 * F_356 ( int V_8 , struct V_15 * V_16 )
{
F_76 ( ! F_357 () ) ;
return V_8 > 0 ? F_358 ( & V_16 -> V_363 , V_8 ) : NULL ;
}
static struct V_11 *
F_359 ( struct V_11 * V_12 )
{
struct V_11 * V_22 = F_57 ( sizeof( * V_22 ) , V_72 ) ;
if ( ! V_22 )
return F_156 ( - V_73 ) ;
return V_22 ;
}
static void F_360 ( struct V_11 * V_22 )
{
F_41 ( V_22 ) ;
}
static T_7 F_361 ( struct V_11 * V_22 ,
struct V_31 * V_32 )
{
return F_251 ( V_22 -> V_9 ) ;
}
static T_7 F_362 ( struct V_11 * V_22 ,
struct V_31 * V_32 )
{
return ( T_7 ) ( unsigned long ) V_153 -> V_203 ;
}
static T_7 F_363 ( struct V_11 * V_22 ,
struct V_31 * V_32 )
{
T_7 V_70 ;
F_19 () ;
V_70 = F_80 ( & F_86 ( V_153 ) -> V_48 ) ;
F_22 () ;
return V_70 ;
}
static int F_364 ( struct V_126 * V_127 , void * V_246 )
{
struct V_44 * V_45 ;
struct V_42 * V_43 ;
char * V_408 ;
V_408 = F_270 ( V_409 + 1 , V_72 ) ;
if ( ! V_408 )
return - V_73 ;
F_65 ( & V_36 ) ;
F_19 () ;
V_43 = F_297 ( V_153 -> V_203 ) ;
F_69 (link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_81 = V_45 -> V_10 ;
F_365 ( V_81 , V_408 , V_409 + 1 ) ;
F_116 ( V_127 , L_56 ,
V_81 -> V_19 -> V_88 , V_408 ) ;
}
F_22 () ;
F_66 ( & V_36 ) ;
F_41 ( V_408 ) ;
return 0 ;
}
static int F_366 ( struct V_126 * V_127 , void * V_246 )
{
struct V_11 * V_22 = F_200 ( V_127 ) ;
struct V_44 * V_45 ;
F_65 ( & V_36 ) ;
F_69 (link, &css->cgroup->cset_links, cset_link) {
struct V_42 * V_43 = V_45 -> V_43 ;
struct V_95 * V_96 ;
int V_70 = 0 ;
F_116 ( V_127 , L_57 , V_43 ) ;
F_69 (task, &cset->tasks, cg_list) {
if ( V_70 ++ > V_410 )
goto V_411;
F_116 ( V_127 , L_58 , F_293 ( V_96 ) ) ;
}
F_69 (task, &cset->mg_tasks, cg_list) {
if ( V_70 ++ > V_410 )
goto V_411;
F_116 ( V_127 , L_58 , F_293 ( V_96 ) ) ;
}
continue;
V_411:
F_117 ( V_127 , L_59 ) ;
}
F_66 ( & V_36 ) ;
return 0 ;
}
static T_7 F_367 ( struct V_11 * V_22 , struct V_31 * V_32 )
{
return ( ! F_349 ( V_22 -> V_9 ) &&
! F_261 ( & V_22 -> V_9 -> V_13 ) ) ;
}
