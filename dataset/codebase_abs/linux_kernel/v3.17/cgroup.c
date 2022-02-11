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
static inline bool F_18 ( const struct V_9 * V_10 )
{
return ! ( V_10 -> V_13 . V_22 & V_23 ) ;
}
struct V_11 * F_19 ( struct V_24 * V_25 )
{
struct V_9 * V_10 = V_25 -> V_26 -> V_14 -> V_27 ;
struct V_28 * V_29 = F_20 ( V_25 ) ;
if ( V_29 -> V_16 )
return F_21 ( V_10 -> V_17 [ V_29 -> V_16 -> V_8 ] ) ;
else
return & V_10 -> V_13 ;
}
bool F_22 ( struct V_9 * V_10 , struct V_9 * V_30 )
{
while ( V_10 ) {
if ( V_10 == V_30 )
return true ;
V_10 = F_11 ( V_10 ) ;
}
return false ;
}
static int F_23 ( const struct V_9 * V_10 )
{
const int V_31 =
( 1 << V_32 ) |
( 1 << V_33 ) ;
return ( V_10 -> V_22 & V_31 ) == V_31 ;
}
static int F_24 ( const struct V_9 * V_10 )
{
return F_25 ( V_33 , & V_10 -> V_22 ) ;
}
static void F_26 ( struct V_9 * V_10 , bool V_34 )
{
F_17 ( & V_35 ) ;
do {
bool V_36 ;
if ( V_34 )
V_36 = ! V_10 -> V_37 ++ ;
else
V_36 = ! -- V_10 -> V_37 ;
if ( ! V_36 )
break;
if ( V_10 -> V_38 )
F_27 ( V_10 -> V_38 ) ;
V_10 = F_11 ( V_10 ) ;
} while ( V_10 );
}
static unsigned long F_28 ( struct V_11 * V_39 [] )
{
unsigned long V_40 = 0UL ;
struct V_15 * V_16 ;
int V_41 ;
F_29 (ss, i)
V_40 += ( unsigned long ) V_39 [ V_41 ] ;
V_40 = ( V_40 >> 16 ) ^ V_40 ;
return V_40 ;
}
static void F_30 ( struct V_42 * V_43 , bool V_44 )
{
struct V_45 * V_46 , * V_47 ;
struct V_15 * V_16 ;
int V_48 ;
F_17 ( & V_35 ) ;
if ( ! F_31 ( & V_43 -> V_49 ) )
return;
F_29 (ss, ssid)
F_32 ( & V_43 -> V_50 [ V_48 ] ) ;
F_33 ( & V_43 -> V_51 ) ;
V_52 -- ;
F_34 (link, tmp_link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_10 = V_46 -> V_10 ;
F_32 ( & V_46 -> V_53 ) ;
F_32 ( & V_46 -> V_54 ) ;
if ( F_35 ( & V_10 -> V_55 ) ) {
F_26 ( V_10 , false ) ;
if ( F_24 ( V_10 ) ) {
if ( V_44 )
F_36 ( V_32 , & V_10 -> V_22 ) ;
F_37 ( V_10 ) ;
}
}
F_38 ( V_46 ) ;
}
F_39 ( V_43 , V_56 ) ;
}
static void F_40 ( struct V_42 * V_43 , bool V_44 )
{
if ( F_41 ( & V_43 -> V_49 , - 1 , 1 ) )
return;
F_42 ( & V_35 ) ;
F_30 ( V_43 , V_44 ) ;
F_43 ( & V_35 ) ;
}
static inline void F_44 ( struct V_42 * V_43 )
{
F_45 ( & V_43 -> V_49 ) ;
}
static bool F_46 ( struct V_42 * V_43 ,
struct V_42 * V_57 ,
struct V_9 * V_58 ,
struct V_11 * V_59 [] )
{
struct V_60 * V_61 , * V_62 ;
if ( memcmp ( V_59 , V_43 -> V_17 , sizeof( V_43 -> V_17 ) ) )
return false ;
V_61 = & V_43 -> V_63 ;
V_62 = & V_57 -> V_63 ;
while ( 1 ) {
struct V_45 * V_64 , * V_65 ;
struct V_9 * V_66 , * V_67 ;
V_61 = V_61 -> V_68 ;
V_62 = V_62 -> V_68 ;
if ( V_61 == & V_43 -> V_63 ) {
F_47 ( V_62 != & V_57 -> V_63 ) ;
break;
} else {
F_47 ( V_62 == & V_57 -> V_63 ) ;
}
V_64 = F_48 ( V_61 , struct V_45 , V_54 ) ;
V_65 = F_48 ( V_62 , struct V_45 , V_54 ) ;
V_66 = V_64 -> V_10 ;
V_67 = V_65 -> V_10 ;
F_47 ( V_66 -> V_19 != V_67 -> V_19 ) ;
if ( V_66 -> V_19 == V_58 -> V_19 ) {
if ( V_66 != V_58 )
return false ;
} else {
if ( V_66 != V_67 )
return false ;
}
}
return true ;
}
static struct V_42 * F_49 ( struct V_42 * V_57 ,
struct V_9 * V_10 ,
struct V_11 * V_59 [] )
{
struct V_69 * V_19 = V_10 -> V_19 ;
struct V_15 * V_16 ;
struct V_42 * V_43 ;
unsigned long V_40 ;
int V_41 ;
F_29 (ss, i) {
if ( V_19 -> V_20 & ( 1UL << V_41 ) ) {
V_59 [ V_41 ] = F_16 ( V_10 , V_16 ) ;
} else {
V_59 [ V_41 ] = V_57 -> V_17 [ V_41 ] ;
}
}
V_40 = F_28 ( V_59 ) ;
F_50 (css_set_table, cset, hlist, key) {
if ( ! F_46 ( V_43 , V_57 , V_10 , V_59 ) )
continue;
return V_43 ;
}
return NULL ;
}
static void F_51 ( struct V_60 * V_70 )
{
struct V_45 * V_46 , * V_47 ;
F_34 (link, tmp_link, links_to_free, cset_link) {
F_32 ( & V_46 -> V_53 ) ;
F_38 ( V_46 ) ;
}
}
static int F_52 ( int V_71 , struct V_60 * V_72 )
{
struct V_45 * V_46 ;
int V_41 ;
F_53 ( V_72 ) ;
for ( V_41 = 0 ; V_41 < V_71 ; V_41 ++ ) {
V_46 = F_54 ( sizeof( * V_46 ) , V_73 ) ;
if ( ! V_46 ) {
F_51 ( V_72 ) ;
return - V_74 ;
}
F_55 ( & V_46 -> V_53 , V_72 ) ;
}
return 0 ;
}
static void F_56 ( struct V_60 * V_72 , struct V_42 * V_43 ,
struct V_9 * V_10 )
{
struct V_45 * V_46 ;
F_47 ( F_35 ( V_72 ) ) ;
if ( F_57 ( V_10 ) )
V_43 -> V_75 = V_10 ;
V_46 = F_58 ( V_72 , struct V_45 , V_53 ) ;
V_46 -> V_43 = V_43 ;
V_46 -> V_10 = V_10 ;
if ( F_35 ( & V_10 -> V_55 ) )
F_26 ( V_10 , true ) ;
F_59 ( & V_46 -> V_53 , & V_10 -> V_55 ) ;
F_60 ( & V_46 -> V_54 , & V_43 -> V_63 ) ;
}
static struct V_42 * F_61 ( struct V_42 * V_57 ,
struct V_9 * V_10 )
{
struct V_11 * V_59 [ V_76 ] = { } ;
struct V_42 * V_43 ;
struct V_60 V_72 ;
struct V_45 * V_46 ;
struct V_15 * V_16 ;
unsigned long V_40 ;
int V_48 ;
F_17 ( & V_18 ) ;
F_62 ( & V_35 ) ;
V_43 = F_49 ( V_57 , V_10 , V_59 ) ;
if ( V_43 )
F_44 ( V_43 ) ;
F_63 ( & V_35 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_54 ( sizeof( * V_43 ) , V_73 ) ;
if ( ! V_43 )
return NULL ;
if ( F_52 ( V_77 , & V_72 ) < 0 ) {
F_38 ( V_43 ) ;
return NULL ;
}
F_64 ( & V_43 -> V_49 , 1 ) ;
F_53 ( & V_43 -> V_63 ) ;
F_53 ( & V_43 -> V_78 ) ;
F_53 ( & V_43 -> V_79 ) ;
F_53 ( & V_43 -> V_80 ) ;
F_53 ( & V_43 -> V_81 ) ;
F_65 ( & V_43 -> V_51 ) ;
memcpy ( V_43 -> V_17 , V_59 , sizeof( V_43 -> V_17 ) ) ;
F_42 ( & V_35 ) ;
F_66 (link, &old_cset->cgrp_links, cgrp_link) {
struct V_9 * V_82 = V_46 -> V_10 ;
if ( V_82 -> V_19 == V_10 -> V_19 )
V_82 = V_10 ;
F_56 ( & V_72 , V_43 , V_82 ) ;
}
F_47 ( ! F_35 ( & V_72 ) ) ;
V_52 ++ ;
V_40 = F_28 ( V_43 -> V_17 ) ;
F_67 ( V_83 , & V_43 -> V_51 , V_40 ) ;
F_29 (ss, ssid)
F_60 ( & V_43 -> V_50 [ V_48 ] ,
& V_43 -> V_17 [ V_48 ] -> V_9 -> V_84 [ V_48 ] ) ;
F_43 ( & V_35 ) ;
return V_43 ;
}
static struct V_69 * F_68 ( struct V_85 * V_86 )
{
struct V_9 * V_87 = V_86 -> V_26 -> V_27 ;
return V_87 -> V_19 ;
}
static int F_69 ( struct V_69 * V_19 )
{
int V_8 ;
F_17 ( & V_18 ) ;
V_8 = F_70 ( & V_88 , V_19 , 0 , 0 , V_73 ) ;
if ( V_8 < 0 )
return V_8 ;
V_19 -> V_89 = V_8 ;
return 0 ;
}
static void F_71 ( struct V_69 * V_19 )
{
F_17 ( & V_18 ) ;
if ( V_19 -> V_89 ) {
F_10 ( & V_88 , V_19 -> V_89 ) ;
V_19 -> V_89 = 0 ;
}
}
static void F_72 ( struct V_69 * V_19 )
{
if ( V_19 ) {
F_73 ( V_19 -> V_89 ) ;
F_74 ( & V_19 -> V_90 ) ;
F_38 ( V_19 ) ;
}
}
static void F_75 ( struct V_69 * V_19 )
{
struct V_9 * V_10 = & V_19 -> V_10 ;
struct V_45 * V_46 , * V_47 ;
F_76 ( & V_18 ) ;
F_47 ( F_77 ( & V_19 -> V_91 ) ) ;
F_47 ( ! F_35 ( & V_10 -> V_13 . V_92 ) ) ;
F_78 ( & V_93 , V_19 -> V_20 ) ;
F_42 ( & V_35 ) ;
F_34 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_32 ( & V_46 -> V_53 ) ;
F_32 ( & V_46 -> V_54 ) ;
F_38 ( V_46 ) ;
}
F_43 ( & V_35 ) ;
if ( ! F_35 ( & V_19 -> V_94 ) ) {
F_32 ( & V_19 -> V_94 ) ;
V_77 -- ;
}
F_71 ( V_19 ) ;
F_79 ( & V_18 ) ;
F_80 ( V_19 -> V_86 ) ;
F_72 ( V_19 ) ;
}
static struct V_9 * F_81 ( struct V_42 * V_43 ,
struct V_69 * V_19 )
{
struct V_9 * V_95 = NULL ;
F_17 ( & V_18 ) ;
F_17 ( & V_35 ) ;
if ( V_43 == & V_96 ) {
V_95 = & V_19 -> V_10 ;
} else {
struct V_45 * V_46 ;
F_66 (link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_82 = V_46 -> V_10 ;
if ( V_82 -> V_19 == V_19 ) {
V_95 = V_82 ;
break;
}
}
}
F_47 ( ! V_95 ) ;
return V_95 ;
}
static struct V_9 * F_82 ( struct V_97 * V_98 ,
struct V_69 * V_19 )
{
return F_81 ( F_83 ( V_98 ) , V_19 ) ;
}
static char * F_84 ( struct V_9 * V_10 , const struct V_28 * V_29 ,
char * V_99 )
{
if ( V_29 -> V_16 && ! ( V_29 -> V_22 & V_100 ) &&
! ( V_10 -> V_19 -> V_22 & V_101 ) )
snprintf ( V_99 , V_102 , L_1 ,
V_29 -> V_16 -> V_103 , V_29 -> V_103 ) ;
else
strncpy ( V_99 , V_29 -> V_103 , V_102 ) ;
return V_99 ;
}
static T_2 F_85 ( const struct V_28 * V_29 )
{
T_2 V_104 = 0 ;
if ( V_29 -> V_104 )
return V_29 -> V_104 ;
if ( V_29 -> V_105 || V_29 -> V_106 || V_29 -> V_107 )
V_104 |= V_108 ;
if ( V_29 -> V_109 || V_29 -> V_110 || V_29 -> V_111 )
V_104 |= V_112 ;
return V_104 ;
}
static void F_86 ( struct V_9 * V_10 )
{
F_73 ( F_18 ( V_10 ) ) ;
F_87 ( & V_10 -> V_13 ) ;
}
static bool F_88 ( struct V_9 * V_10 )
{
return F_89 ( & V_10 -> V_13 ) ;
}
static void F_90 ( struct V_9 * V_10 )
{
F_91 ( & V_10 -> V_13 ) ;
}
static void F_92 ( struct V_9 * V_10 )
{
struct V_9 * V_14 = F_11 ( V_10 ) ;
unsigned int V_113 = V_10 -> V_114 ;
struct V_15 * V_16 ;
int V_48 ;
F_17 ( & V_18 ) ;
if ( ! F_57 ( V_10 ) ) {
V_10 -> V_21 = V_113 ;
return;
}
while ( true ) {
unsigned int V_115 = V_113 ;
F_29 (ss, ssid)
if ( V_113 & ( 1 << V_48 ) )
V_115 |= V_16 -> V_116 ;
if ( V_14 )
V_115 &= V_14 -> V_21 ;
else
V_115 &= V_10 -> V_19 -> V_20 ;
if ( V_115 == V_113 )
break;
V_113 = V_115 ;
}
V_10 -> V_21 = V_113 ;
}
static void F_93 ( struct V_117 * V_26 )
{
struct V_9 * V_10 ;
if ( F_94 ( V_26 ) == V_118 )
V_10 = V_26 -> V_27 ;
else
V_10 = V_26 -> V_14 -> V_27 ;
F_79 ( & V_18 ) ;
F_95 ( V_26 ) ;
F_90 ( V_10 ) ;
}
static struct V_9 * F_96 ( struct V_117 * V_26 )
{
struct V_9 * V_10 ;
if ( F_94 ( V_26 ) == V_118 )
V_10 = V_26 -> V_27 ;
else
V_10 = V_26 -> V_14 -> V_27 ;
if ( ! F_88 ( V_10 ) )
return NULL ;
F_97 ( V_26 ) ;
F_76 ( & V_18 ) ;
if ( ! F_18 ( V_10 ) )
return V_10 ;
F_93 ( V_26 ) ;
return NULL ;
}
static void F_98 ( struct V_9 * V_10 , const struct V_28 * V_29 )
{
char V_103 [ V_102 ] ;
F_17 ( & V_18 ) ;
F_99 ( V_10 -> V_26 , F_84 ( V_10 , V_29 , V_103 ) ) ;
}
static void F_100 ( struct V_9 * V_10 , unsigned int V_20 )
{
struct V_15 * V_16 ;
int V_41 ;
F_29 (ss, i) {
struct V_28 * V_119 ;
if ( ! ( V_20 & ( 1 << V_41 ) ) )
continue;
F_66 (cfts, &ss->cfts, node)
F_101 ( V_10 , V_119 , false ) ;
}
}
static int F_78 ( struct V_69 * V_120 , unsigned int V_121 )
{
struct V_15 * V_16 ;
unsigned int V_122 ;
int V_48 , V_41 , V_6 ;
F_17 ( & V_18 ) ;
F_29 (ss, ssid) {
if ( ! ( V_121 & ( 1 << V_48 ) ) )
continue;
if ( F_102 ( NULL , F_13 ( & V_16 -> V_19 -> V_10 , V_16 ) ) )
return - V_123 ;
if ( V_16 -> V_19 != & V_93 && V_120 != & V_93 )
return - V_123 ;
}
V_122 = V_121 ;
if ( V_120 == & V_93 )
V_122 &= ~ V_124 ;
V_6 = F_103 ( & V_120 -> V_10 , V_122 ) ;
if ( V_6 ) {
if ( V_120 != & V_93 )
return V_6 ;
if ( V_125 ) {
F_104 ( L_2 ,
V_6 , V_121 ) ;
F_104 ( L_3 ) ;
}
}
F_29 (ss, ssid)
if ( V_121 & ( 1 << V_48 ) )
F_100 ( & V_16 -> V_19 -> V_10 , 1 << V_48 ) ;
F_29 (ss, ssid) {
struct V_69 * V_126 ;
struct V_11 * V_39 ;
struct V_42 * V_43 ;
if ( ! ( V_121 & ( 1 << V_48 ) ) )
continue;
V_126 = V_16 -> V_19 ;
V_39 = F_13 ( & V_126 -> V_10 , V_16 ) ;
F_105 ( ! V_39 || F_13 ( & V_120 -> V_10 , V_16 ) ) ;
F_106 ( V_126 -> V_10 . V_17 [ V_48 ] , NULL ) ;
F_107 ( V_120 -> V_10 . V_17 [ V_48 ] , V_39 ) ;
V_16 -> V_19 = V_120 ;
V_39 -> V_9 = & V_120 -> V_10 ;
F_42 ( & V_35 ) ;
F_108 (css_set_table, i, cset, hlist)
F_109 ( & V_43 -> V_50 [ V_16 -> V_8 ] ,
& V_120 -> V_10 . V_84 [ V_16 -> V_8 ] ) ;
F_43 ( & V_35 ) ;
V_126 -> V_20 &= ~ ( 1 << V_48 ) ;
V_126 -> V_10 . V_114 &= ~ ( 1 << V_48 ) ;
F_92 ( & V_126 -> V_10 ) ;
V_120 -> V_20 |= 1 << V_48 ;
if ( V_120 != & V_93 ) {
V_120 -> V_10 . V_114 |= 1 << V_48 ;
F_92 ( & V_120 -> V_10 ) ;
}
if ( V_16 -> V_127 )
V_16 -> V_127 ( V_39 ) ;
}
F_110 ( V_120 -> V_10 . V_26 ) ;
return 0 ;
}
static int F_111 ( struct V_128 * V_129 ,
struct V_85 * V_86 )
{
struct V_69 * V_19 = F_68 ( V_86 ) ;
struct V_15 * V_16 ;
int V_48 ;
F_29 (ss, ssid)
if ( V_19 -> V_20 & ( 1 << V_48 ) )
F_112 ( V_129 , L_4 , V_16 -> V_103 ) ;
if ( V_19 -> V_22 & V_101 )
F_113 ( V_129 , L_5 ) ;
if ( V_19 -> V_22 & V_130 )
F_113 ( V_129 , L_6 ) ;
F_114 ( & V_131 ) ;
if ( strlen ( V_19 -> V_132 ) )
F_112 ( V_129 , L_7 , V_19 -> V_132 ) ;
F_115 ( & V_131 ) ;
if ( F_25 ( V_133 , & V_19 -> V_10 . V_22 ) )
F_113 ( V_129 , L_8 ) ;
if ( strlen ( V_19 -> V_103 ) )
F_112 ( V_129 , L_9 , V_19 -> V_103 ) ;
return 0 ;
}
static int F_116 ( char * V_134 , struct V_135 * V_136 )
{
char * V_137 , * V_138 = V_134 ;
bool V_139 = false , V_140 = false ;
unsigned int V_141 = - 1U ;
struct V_15 * V_16 ;
int V_142 = 0 ;
int V_41 ;
#ifdef F_117
V_141 = ~ ( 1U << V_143 ) ;
#endif
memset ( V_136 , 0 , sizeof( * V_136 ) ) ;
while ( ( V_137 = F_118 ( & V_138 , L_10 ) ) != NULL ) {
V_142 ++ ;
if ( ! * V_137 )
return - V_144 ;
if ( ! strcmp ( V_137 , L_11 ) ) {
V_136 -> V_145 = true ;
continue;
}
if ( ! strcmp ( V_137 , L_12 ) ) {
if ( V_140 )
return - V_144 ;
V_139 = true ;
continue;
}
if ( ! strcmp ( V_137 , L_13 ) ) {
V_136 -> V_22 |= V_146 ;
continue;
}
if ( ! strcmp ( V_137 , L_14 ) ) {
V_136 -> V_22 |= V_101 ;
continue;
}
if ( ! strcmp ( V_137 , L_15 ) ) {
V_136 -> V_147 = true ;
continue;
}
if ( ! strcmp ( V_137 , L_16 ) ) {
V_136 -> V_22 |= V_130 ;
continue;
}
if ( ! strncmp ( V_137 , L_17 , 14 ) ) {
if ( V_136 -> V_148 )
return - V_144 ;
V_136 -> V_148 =
F_119 ( V_137 + 14 , V_149 - 1 , V_73 ) ;
if ( ! V_136 -> V_148 )
return - V_74 ;
continue;
}
if ( ! strncmp ( V_137 , L_18 , 5 ) ) {
const char * V_103 = V_137 + 5 ;
if ( ! strlen ( V_103 ) )
return - V_144 ;
for ( V_41 = 0 ; V_41 < strlen ( V_103 ) ; V_41 ++ ) {
char V_82 = V_103 [ V_41 ] ;
if ( isalnum ( V_82 ) )
continue;
if ( ( V_82 == '.' ) || ( V_82 == '-' ) || ( V_82 == '_' ) )
continue;
return - V_144 ;
}
if ( V_136 -> V_103 )
return - V_144 ;
V_136 -> V_103 = F_119 ( V_103 ,
V_150 - 1 ,
V_73 ) ;
if ( ! V_136 -> V_103 )
return - V_74 ;
continue;
}
F_29 (ss, i) {
if ( strcmp ( V_137 , V_16 -> V_103 ) )
continue;
if ( V_16 -> V_151 )
continue;
if ( V_139 )
return - V_144 ;
V_136 -> V_20 |= ( 1 << V_41 ) ;
V_140 = true ;
break;
}
if ( V_41 == V_76 )
return - V_152 ;
}
if ( V_136 -> V_22 & V_146 ) {
F_104 ( L_19 ) ;
if ( V_142 != 1 ) {
F_120 ( L_20 ) ;
return - V_144 ;
}
return 0 ;
}
if ( V_139 || ( ! V_140 && ! V_136 -> V_145 && ! V_136 -> V_103 ) )
F_29 (ss, i)
if ( ! V_16 -> V_151 )
V_136 -> V_20 |= ( 1 << V_41 ) ;
if ( ! V_136 -> V_20 && ! V_136 -> V_103 )
return - V_144 ;
if ( ( V_136 -> V_22 & V_101 ) && ( V_136 -> V_20 & V_141 ) )
return - V_144 ;
if ( V_136 -> V_20 && V_136 -> V_145 )
return - V_144 ;
return 0 ;
}
static int F_121 ( struct V_85 * V_86 , int * V_22 , char * V_134 )
{
int V_6 = 0 ;
struct V_69 * V_19 = F_68 ( V_86 ) ;
struct V_135 V_136 ;
unsigned int V_153 , V_154 ;
if ( V_19 == & V_93 ) {
F_120 ( L_21 ) ;
return - V_144 ;
}
F_76 ( & V_18 ) ;
V_6 = F_116 ( V_134 , & V_136 ) ;
if ( V_6 )
goto V_155;
if ( V_136 . V_20 != V_19 -> V_20 || V_136 . V_148 )
F_104 ( L_22 ,
F_122 ( V_156 ) , V_156 -> V_157 ) ;
V_153 = V_136 . V_20 & ~ V_19 -> V_20 ;
V_154 = V_19 -> V_20 & ~ V_136 . V_20 ;
if ( ( V_136 . V_22 ^ V_19 -> V_22 ) ||
( V_136 . V_103 && strcmp ( V_136 . V_103 , V_19 -> V_103 ) ) ) {
F_120 ( L_23 ,
V_136 . V_22 , V_136 . V_103 ? : L_24 , V_19 -> V_22 , V_19 -> V_103 ) ;
V_6 = - V_144 ;
goto V_155;
}
if ( ! F_35 ( & V_19 -> V_10 . V_13 . V_92 ) ) {
V_6 = - V_123 ;
goto V_155;
}
V_6 = F_78 ( V_19 , V_153 ) ;
if ( V_6 )
goto V_155;
F_78 ( & V_93 , V_154 ) ;
if ( V_136 . V_148 ) {
F_114 ( & V_131 ) ;
strcpy ( V_19 -> V_132 , V_136 . V_148 ) ;
F_115 ( & V_131 ) ;
}
V_155:
F_38 ( V_136 . V_148 ) ;
F_38 ( V_136 . V_103 ) ;
F_79 ( & V_18 ) ;
return V_6 ;
}
static void F_123 ( void )
{
struct V_97 * V_158 , * V_159 ;
F_42 ( & V_35 ) ;
if ( V_160 )
goto V_155;
V_160 = true ;
F_124 ( & V_161 ) ;
F_125 (g, p) {
F_73 ( ! F_35 ( & V_158 -> V_162 ) ||
F_83 ( V_158 ) != & V_96 ) ;
F_126 ( & V_158 -> V_163 -> V_164 ) ;
if ( ! ( V_158 -> V_22 & V_165 ) ) {
struct V_42 * V_43 = F_83 ( V_158 ) ;
F_55 ( & V_158 -> V_162 , & V_43 -> V_78 ) ;
F_44 ( V_43 ) ;
}
F_127 ( & V_158 -> V_163 -> V_164 ) ;
} F_128 ( V_159 , V_158 ) ;
F_129 ( & V_161 ) ;
V_155:
F_43 ( & V_35 ) ;
}
static void F_130 ( struct V_9 * V_10 )
{
struct V_15 * V_16 ;
int V_48 ;
F_53 ( & V_10 -> V_13 . V_166 ) ;
F_53 ( & V_10 -> V_13 . V_92 ) ;
F_53 ( & V_10 -> V_55 ) ;
F_53 ( & V_10 -> V_167 ) ;
F_53 ( & V_10 -> V_168 ) ;
F_131 ( & V_10 -> V_169 ) ;
V_10 -> V_13 . V_9 = V_10 ;
V_10 -> V_13 . V_22 |= V_23 ;
F_29 (ss, ssid)
F_53 ( & V_10 -> V_84 [ V_48 ] ) ;
F_132 ( & V_10 -> V_170 ) ;
}
static void F_133 ( struct V_69 * V_19 ,
struct V_135 * V_136 )
{
struct V_9 * V_10 = & V_19 -> V_10 ;
F_53 ( & V_19 -> V_94 ) ;
F_64 ( & V_19 -> V_91 , 1 ) ;
V_10 -> V_19 = V_19 ;
F_130 ( V_10 ) ;
F_134 ( & V_19 -> V_90 ) ;
V_19 -> V_22 = V_136 -> V_22 ;
if ( V_136 -> V_148 )
strcpy ( V_19 -> V_132 , V_136 -> V_148 ) ;
if ( V_136 -> V_103 )
strcpy ( V_19 -> V_103 , V_136 -> V_103 ) ;
if ( V_136 -> V_147 )
F_36 ( V_133 , & V_19 -> V_10 . V_22 ) ;
}
static int F_135 ( struct V_69 * V_19 , unsigned int V_121 )
{
F_136 ( V_72 ) ;
struct V_9 * V_87 = & V_19 -> V_10 ;
struct V_28 * V_171 ;
struct V_42 * V_43 ;
int V_41 , V_6 ;
F_17 ( & V_18 ) ;
V_6 = F_1 ( & V_19 -> V_90 , V_87 , 1 , 2 , V_172 ) ;
if ( V_6 < 0 )
goto V_173;
V_87 -> V_8 = V_6 ;
V_6 = F_137 ( & V_87 -> V_13 . V_174 , V_175 ) ;
if ( V_6 )
goto V_173;
V_6 = F_52 ( V_52 , & V_72 ) ;
if ( V_6 )
goto V_176;
V_6 = F_69 ( V_19 ) ;
if ( V_6 )
goto V_176;
V_19 -> V_86 = F_138 ( & V_177 ,
V_178 ,
V_87 ) ;
if ( F_139 ( V_19 -> V_86 ) ) {
V_6 = F_140 ( V_19 -> V_86 ) ;
goto V_179;
}
V_87 -> V_26 = V_19 -> V_86 -> V_26 ;
if ( V_19 == & V_93 )
V_171 = V_180 ;
else
V_171 = V_181 ;
V_6 = F_101 ( V_87 , V_171 , true ) ;
if ( V_6 )
goto V_182;
V_6 = F_78 ( V_19 , V_121 ) ;
if ( V_6 )
goto V_182;
F_55 ( & V_19 -> V_94 , & V_183 ) ;
V_77 ++ ;
F_42 ( & V_35 ) ;
F_108 (css_set_table, i, cset, hlist)
F_56 ( & V_72 , V_43 , V_87 ) ;
F_43 ( & V_35 ) ;
F_47 ( ! F_35 ( & V_87 -> V_13 . V_92 ) ) ;
F_47 ( F_77 ( & V_19 -> V_91 ) != 1 ) ;
F_110 ( V_87 -> V_26 ) ;
V_6 = 0 ;
goto V_173;
V_182:
F_80 ( V_19 -> V_86 ) ;
V_19 -> V_86 = NULL ;
V_179:
F_71 ( V_19 ) ;
V_176:
F_141 ( & V_87 -> V_13 . V_174 ) ;
V_173:
F_51 ( & V_72 ) ;
return V_6 ;
}
static struct V_184 * F_142 ( struct V_185 * V_186 ,
int V_22 , const char * V_187 ,
void * V_134 )
{
struct V_188 * V_189 = NULL ;
struct V_15 * V_16 ;
struct V_69 * V_19 ;
struct V_135 V_136 ;
struct V_184 * V_184 ;
int V_6 ;
int V_41 ;
bool V_190 ;
if ( ! V_160 )
F_123 () ;
F_76 ( & V_18 ) ;
V_6 = F_116 ( V_134 , & V_136 ) ;
if ( V_6 )
goto V_155;
if ( V_136 . V_22 & V_146 ) {
V_125 = true ;
V_19 = & V_93 ;
F_86 ( & V_19 -> V_10 ) ;
V_6 = 0 ;
goto V_155;
}
F_29 (ss, i) {
if ( ! ( V_136 . V_20 & ( 1 << V_41 ) ) ||
V_16 -> V_19 == & V_93 )
continue;
if ( ! F_143 ( & V_16 -> V_19 -> V_10 . V_13 . V_174 ) ) {
F_79 ( & V_18 ) ;
F_144 ( 10 ) ;
V_6 = F_145 () ;
goto V_191;
}
F_90 ( & V_16 -> V_19 -> V_10 ) ;
}
F_146 (root) {
bool V_192 = false ;
if ( V_19 == & V_93 )
continue;
if ( V_136 . V_103 ) {
if ( strcmp ( V_136 . V_103 , V_19 -> V_103 ) )
continue;
V_192 = true ;
}
if ( ( V_136 . V_20 || V_136 . V_145 ) &&
( V_136 . V_20 != V_19 -> V_20 ) ) {
if ( ! V_192 )
continue;
V_6 = - V_123 ;
goto V_155;
}
if ( V_19 -> V_22 ^ V_136 . V_22 )
F_104 ( L_25 ) ;
V_189 = F_147 ( V_19 -> V_86 , NULL ) ;
if ( F_139 ( V_189 ) ||
! F_143 ( & V_19 -> V_10 . V_13 . V_174 ) ) {
F_79 ( & V_18 ) ;
if ( ! F_148 ( V_189 ) )
F_149 ( V_189 ) ;
F_144 ( 10 ) ;
V_6 = F_145 () ;
goto V_191;
}
V_6 = 0 ;
goto V_155;
}
if ( ! V_136 . V_20 && ! V_136 . V_145 ) {
V_6 = - V_144 ;
goto V_155;
}
V_19 = F_54 ( sizeof( * V_19 ) , V_73 ) ;
if ( ! V_19 ) {
V_6 = - V_74 ;
goto V_155;
}
F_133 ( V_19 , & V_136 ) ;
V_6 = F_135 ( V_19 , V_136 . V_20 ) ;
if ( V_6 )
F_72 ( V_19 ) ;
V_155:
F_79 ( & V_18 ) ;
V_191:
F_38 ( V_136 . V_148 ) ;
F_38 ( V_136 . V_103 ) ;
if ( V_6 )
return F_150 ( V_6 ) ;
V_184 = F_151 ( V_186 , V_22 , V_19 -> V_86 ,
V_193 , & V_190 ) ;
if ( F_139 ( V_184 ) || ! V_190 )
F_90 ( & V_19 -> V_10 ) ;
if ( V_189 ) {
F_105 ( V_190 ) ;
F_149 ( V_189 ) ;
}
return V_184 ;
}
static void F_152 ( struct V_188 * V_194 )
{
struct V_85 * V_86 = F_153 ( V_194 ) ;
struct V_69 * V_19 = F_68 ( V_86 ) ;
if ( F_154 ( & V_19 -> V_10 . V_13 ) ||
V_19 == & V_93 )
F_90 ( & V_19 -> V_10 ) ;
else
F_155 ( & V_19 -> V_10 . V_13 . V_174 ) ;
F_156 ( V_194 ) ;
}
char * F_157 ( struct V_97 * V_98 , char * V_99 , T_3 V_195 )
{
struct V_69 * V_19 ;
struct V_9 * V_10 ;
int V_89 = 1 ;
char * V_196 = NULL ;
F_76 ( & V_18 ) ;
F_62 ( & V_35 ) ;
V_19 = F_158 ( & V_88 , & V_89 ) ;
if ( V_19 ) {
V_10 = F_82 ( V_98 , V_19 ) ;
V_196 = F_159 ( V_10 , V_99 , V_195 ) ;
} else {
if ( F_160 ( V_99 , L_26 , V_195 ) < V_195 )
V_196 = V_99 ;
}
F_63 ( & V_35 ) ;
F_79 ( & V_18 ) ;
return V_196 ;
}
struct V_97 * F_161 ( struct V_197 * V_198 )
{
V_198 -> V_199 = F_58 ( V_198 -> V_200 , struct V_42 , V_81 ) ;
V_198 -> V_201 = NULL ;
return F_162 ( V_198 ) ;
}
struct V_97 * F_162 ( struct V_197 * V_198 )
{
struct V_42 * V_43 = V_198 -> V_199 ;
struct V_97 * V_98 = V_198 -> V_201 ;
while ( & V_43 -> V_81 != V_198 -> V_200 ) {
if ( ! V_98 )
V_98 = F_58 ( & V_43 -> V_79 ,
struct V_97 , V_162 ) ;
else
V_98 = F_163 ( V_98 , V_162 ) ;
if ( & V_98 -> V_162 != & V_43 -> V_79 ) {
V_198 -> V_199 = V_43 ;
V_198 -> V_201 = V_98 ;
return V_98 ;
}
V_43 = F_163 ( V_43 , V_81 ) ;
V_98 = NULL ;
}
return NULL ;
}
static void F_164 ( struct V_9 * V_202 ,
struct V_97 * V_203 ,
struct V_42 * V_204 )
{
struct V_42 * V_57 ;
F_17 ( & V_18 ) ;
F_17 ( & V_35 ) ;
F_73 ( V_203 -> V_22 & V_165 ) ;
V_57 = F_83 ( V_203 ) ;
F_44 ( V_204 ) ;
F_107 ( V_203 -> V_205 , V_204 ) ;
F_109 ( & V_203 -> V_162 , & V_204 -> V_79 ) ;
F_36 ( V_32 , & V_202 -> V_22 ) ;
F_30 ( V_57 , false ) ;
}
static void F_165 ( struct V_60 * V_206 )
{
struct V_42 * V_43 , * V_207 ;
F_17 ( & V_18 ) ;
F_42 ( & V_35 ) ;
F_34 (cset, tmp_cset, preloaded_csets, mg_preload_node) {
V_43 -> V_208 = NULL ;
V_43 -> V_209 = NULL ;
F_166 ( & V_43 -> V_80 ) ;
F_30 ( V_43 , false ) ;
}
F_43 ( & V_35 ) ;
}
static void F_167 ( struct V_42 * V_210 ,
struct V_9 * V_211 ,
struct V_60 * V_206 )
{
struct V_9 * V_212 ;
F_17 ( & V_18 ) ;
F_17 ( & V_35 ) ;
V_212 = F_81 ( V_210 , V_211 -> V_19 ) ;
if ( ! F_35 ( & V_210 -> V_80 ) )
return;
F_105 ( V_210 -> V_208 ) ;
F_105 ( ! F_35 ( & V_210 -> V_79 ) ) ;
F_105 ( ! F_35 ( & V_210 -> V_81 ) ) ;
V_210 -> V_208 = V_212 ;
F_44 ( V_210 ) ;
F_55 ( & V_210 -> V_80 , V_206 ) ;
}
static int F_168 ( struct V_9 * V_211 ,
struct V_60 * V_206 )
{
F_136 ( V_200 ) ;
struct V_42 * V_210 , * V_207 ;
F_17 ( & V_18 ) ;
if ( V_211 && F_57 ( V_211 ) && F_11 ( V_211 ) &&
V_211 -> V_21 )
return - V_123 ;
F_34 (src_cset, tmp_cset, preloaded_csets, mg_preload_node) {
struct V_42 * V_213 ;
V_213 = F_61 ( V_210 ,
V_211 ? : V_210 -> V_75 ) ;
if ( ! V_213 )
goto V_214;
F_73 ( V_210 -> V_209 || V_213 -> V_209 ) ;
if ( V_210 == V_213 ) {
V_210 -> V_208 = NULL ;
F_166 ( & V_210 -> V_80 ) ;
F_40 ( V_210 , false ) ;
F_40 ( V_213 , false ) ;
continue;
}
V_210 -> V_209 = V_213 ;
if ( F_35 ( & V_213 -> V_80 ) )
F_55 ( & V_213 -> V_80 , & V_200 ) ;
else
F_40 ( V_213 , false ) ;
}
F_169 ( & V_200 , V_206 ) ;
return 0 ;
V_214:
F_165 ( & V_200 ) ;
return - V_74 ;
}
static int F_170 ( struct V_9 * V_10 , struct V_97 * V_215 ,
bool V_216 )
{
struct V_197 V_198 = {
. V_217 = F_171 ( V_198 . V_217 ) ,
. V_218 = F_171 ( V_198 . V_218 ) ,
. V_200 = & V_198 . V_217 ,
} ;
struct V_11 * V_39 , * V_219 = NULL ;
struct V_42 * V_43 , * V_207 ;
struct V_97 * V_98 , * V_220 ;
int V_41 , V_6 ;
F_42 ( & V_35 ) ;
F_172 () ;
V_98 = V_215 ;
do {
if ( V_98 -> V_22 & V_165 )
goto V_68;
if ( F_35 ( & V_98 -> V_162 ) )
goto V_68;
V_43 = F_83 ( V_98 ) ;
if ( ! V_43 -> V_208 )
goto V_68;
F_109 ( & V_98 -> V_162 , & V_43 -> V_79 ) ;
if ( F_35 ( & V_43 -> V_81 ) )
F_60 ( & V_43 -> V_81 , & V_198 . V_217 ) ;
if ( F_35 ( & V_43 -> V_209 -> V_81 ) )
F_109 ( & V_43 -> V_209 -> V_81 ,
& V_198 . V_218 ) ;
V_68:
if ( ! V_216 )
break;
} while_each_thread(leader, task) ;
int F_173 ( struct V_9 * V_211 ,
struct V_97 * V_215 , bool V_216 )
{
F_136 ( V_206 ) ;
struct V_97 * V_98 ;
int V_6 ;
F_62 ( & V_35 ) ;
F_172 () ;
V_98 = V_215 ;
do {
F_167 ( F_83 ( V_98 ) , V_211 ,
& V_206 ) ;
if ( ! V_216 )
break;
} while_each_thread(leader, task) ;
T_4 F_174 ( struct V_24 * V_25 , char * V_99 ,
T_3 V_221 , T_5 V_222 , bool V_216 )
{
struct V_97 * V_203 ;
const struct V_223 * V_223 = F_175 () , * V_224 ;
struct V_9 * V_10 ;
T_6 V_225 ;
int V_6 ;
if ( F_176 ( F_177 ( V_99 ) , 0 , & V_225 ) || V_225 < 0 )
return - V_144 ;
V_10 = F_96 ( V_25 -> V_26 ) ;
if ( ! V_10 )
return - V_226 ;
V_227:
F_172 () ;
if ( V_225 ) {
V_203 = F_178 ( V_225 ) ;
if ( ! V_203 ) {
F_179 () ;
V_6 = - V_228 ;
goto V_229;
}
V_224 = F_180 ( V_203 ) ;
if ( ! F_181 ( V_223 -> V_230 , V_231 ) &&
! F_181 ( V_223 -> V_230 , V_224 -> V_232 ) &&
! F_181 ( V_223 -> V_230 , V_224 -> V_233 ) ) {
F_179 () ;
V_6 = - V_234 ;
goto V_229;
}
} else
V_203 = V_156 ;
if ( V_216 )
V_203 = V_203 -> V_235 ;
if ( V_203 == V_236 || ( V_203 -> V_22 & V_237 ) ) {
V_6 = - V_144 ;
F_179 () ;
goto V_229;
}
F_182 ( V_203 ) ;
F_179 () ;
F_183 ( V_203 ) ;
if ( V_216 ) {
if ( ! F_184 ( V_203 ) ) {
F_185 ( V_203 ) ;
F_186 ( V_203 ) ;
goto V_227;
}
}
V_6 = F_173 ( V_10 , V_203 , V_216 ) ;
F_185 ( V_203 ) ;
F_186 ( V_203 ) ;
V_229:
F_93 ( V_25 -> V_26 ) ;
return V_6 ? : V_221 ;
}
int F_187 ( struct V_97 * V_238 , struct V_97 * V_203 )
{
struct V_69 * V_19 ;
int V_239 = 0 ;
F_76 ( & V_18 ) ;
F_146 (root) {
struct V_9 * V_240 ;
if ( V_19 == & V_93 )
continue;
F_62 ( & V_35 ) ;
V_240 = F_82 ( V_238 , V_19 ) ;
F_63 ( & V_35 ) ;
V_239 = F_173 ( V_240 , V_203 , false ) ;
if ( V_239 )
break;
}
F_79 ( & V_18 ) ;
return V_239 ;
}
static T_4 F_188 ( struct V_24 * V_25 ,
char * V_99 , T_3 V_221 , T_5 V_222 )
{
return F_174 ( V_25 , V_99 , V_221 , V_222 , false ) ;
}
static T_4 F_189 ( struct V_24 * V_25 ,
char * V_99 , T_3 V_221 , T_5 V_222 )
{
return F_174 ( V_25 , V_99 , V_221 , V_222 , true ) ;
}
static T_4 F_190 ( struct V_24 * V_25 ,
char * V_99 , T_3 V_221 , T_5 V_222 )
{
struct V_9 * V_10 ;
F_191 ( sizeof( V_10 -> V_19 -> V_132 ) < V_149 ) ;
V_10 = F_96 ( V_25 -> V_26 ) ;
if ( ! V_10 )
return - V_226 ;
F_114 ( & V_131 ) ;
F_160 ( V_10 -> V_19 -> V_132 , F_177 ( V_99 ) ,
sizeof( V_10 -> V_19 -> V_132 ) ) ;
F_115 ( & V_131 ) ;
F_93 ( V_25 -> V_26 ) ;
return V_221 ;
}
static int F_192 ( struct V_128 * V_129 , void * V_241 )
{
struct V_9 * V_10 = F_193 ( V_129 ) -> V_9 ;
F_114 ( & V_131 ) ;
F_113 ( V_129 , V_10 -> V_19 -> V_132 ) ;
F_115 ( & V_131 ) ;
F_194 ( V_129 , '\n' ) ;
return 0 ;
}
static int F_195 ( struct V_128 * V_129 , void * V_241 )
{
F_113 ( V_129 , L_27 ) ;
return 0 ;
}
static void F_196 ( struct V_128 * V_129 , unsigned int V_121 )
{
struct V_15 * V_16 ;
bool V_242 = false ;
int V_48 ;
F_29 (ss, ssid) {
if ( V_121 & ( 1 << V_48 ) ) {
if ( V_242 )
F_194 ( V_129 , ' ' ) ;
F_112 ( V_129 , L_28 , V_16 -> V_103 ) ;
V_242 = true ;
}
}
if ( V_242 )
F_194 ( V_129 , '\n' ) ;
}
static int F_197 ( struct V_128 * V_129 , void * V_241 )
{
struct V_9 * V_10 = F_193 ( V_129 ) -> V_9 ;
F_196 ( V_129 , V_10 -> V_19 -> V_20 &
~ V_124 ) ;
return 0 ;
}
static int F_198 ( struct V_128 * V_129 , void * V_241 )
{
struct V_9 * V_10 = F_193 ( V_129 ) -> V_9 ;
F_196 ( V_129 , F_11 ( V_10 ) -> V_114 ) ;
return 0 ;
}
static int F_199 ( struct V_128 * V_129 , void * V_241 )
{
struct V_9 * V_10 = F_193 ( V_129 ) -> V_9 ;
F_196 ( V_129 , V_10 -> V_114 ) ;
return 0 ;
}
static int F_200 ( struct V_9 * V_10 )
{
F_136 ( V_206 ) ;
struct V_11 * V_39 ;
struct V_42 * V_210 ;
int V_6 ;
F_17 ( & V_18 ) ;
F_62 ( & V_35 ) ;
F_201 (css, cgroup_css(cgrp, NULL)) {
struct V_45 * V_46 ;
if ( V_39 -> V_9 == V_10 )
continue;
F_66 (link, &css->cgroup->cset_links, cset_link)
F_167 ( V_46 -> V_43 , V_10 ,
& V_206 ) ;
}
F_63 ( & V_35 ) ;
V_6 = F_168 ( NULL , & V_206 ) ;
if ( V_6 )
goto V_243;
F_66 (src_cset, &preloaded_csets, mg_preload_node) {
struct V_97 * V_244 = NULL , * V_98 ;
if ( ! V_210 -> V_208 )
break;
while ( true ) {
F_62 ( & V_35 ) ;
V_98 = F_202 ( & V_210 -> V_78 ,
struct V_97 , V_162 ) ;
if ( V_98 ) {
V_98 = V_98 -> V_235 ;
F_73 ( ! F_83 ( V_98 ) -> V_208 ) ;
F_182 ( V_98 ) ;
}
F_63 ( & V_35 ) ;
if ( ! V_98 )
break;
if ( F_203 ( V_244 == V_98 ,
L_29 ) )
goto V_243;
V_244 = V_98 ;
F_183 ( V_98 ) ;
if ( ! F_184 ( V_98 ) ) {
F_185 ( V_98 ) ;
F_186 ( V_98 ) ;
continue;
}
V_6 = F_170 ( V_210 -> V_75 , V_98 , true ) ;
F_185 ( V_98 ) ;
F_186 ( V_98 ) ;
if ( F_203 ( V_6 , L_30 , V_6 ) )
goto V_243;
}
}
V_243:
F_165 ( & V_206 ) ;
return V_6 ;
}
static T_4 F_204 ( struct V_24 * V_25 ,
char * V_99 , T_3 V_221 ,
T_5 V_222 )
{
unsigned int V_245 = 0 , V_246 = 0 ;
unsigned int V_247 , V_248 , V_249 , V_250 ;
struct V_9 * V_10 , * V_251 ;
struct V_15 * V_16 ;
char * V_252 ;
int V_48 , V_6 ;
V_99 = F_177 ( V_99 ) ;
while ( ( V_252 = F_118 ( & V_99 , L_31 ) ) ) {
if ( V_252 [ 0 ] == '\0' )
continue;
F_29 (ss, ssid) {
if ( V_16 -> V_151 || strcmp ( V_252 + 1 , V_16 -> V_103 ) ||
( ( 1 << V_16 -> V_8 ) & V_124 ) )
continue;
if ( * V_252 == '+' ) {
V_245 |= 1 << V_48 ;
V_246 &= ~ ( 1 << V_48 ) ;
} else if ( * V_252 == '-' ) {
V_246 |= 1 << V_48 ;
V_245 &= ~ ( 1 << V_48 ) ;
} else {
return - V_144 ;
}
break;
}
if ( V_48 == V_76 )
return - V_144 ;
}
V_10 = F_96 ( V_25 -> V_26 ) ;
if ( ! V_10 )
return - V_226 ;
F_29 (ss, ssid) {
if ( V_245 & ( 1 << V_48 ) ) {
if ( V_10 -> V_114 & ( 1 << V_48 ) ) {
V_245 &= ~ ( 1 << V_48 ) ;
continue;
}
if ( ! ( V_93 . V_20 & ( 1 << V_48 ) ) ||
( F_11 ( V_10 ) &&
! ( F_11 ( V_10 ) -> V_114 & ( 1 << V_48 ) ) ) ) {
V_6 = - V_152 ;
goto V_155;
}
if ( V_10 -> V_21 & ( 1 << V_48 ) )
continue;
F_205 (child, cgrp) {
F_206 ( V_253 ) ;
if ( ! F_13 ( V_251 , V_16 ) )
continue;
F_86 ( V_251 ) ;
F_207 ( & V_251 -> V_170 , & V_253 ,
V_254 ) ;
F_93 ( V_25 -> V_26 ) ;
F_208 () ;
F_209 ( & V_251 -> V_170 , & V_253 ) ;
F_90 ( V_251 ) ;
return F_145 () ;
}
} else if ( V_246 & ( 1 << V_48 ) ) {
if ( ! ( V_10 -> V_114 & ( 1 << V_48 ) ) ) {
V_246 &= ~ ( 1 << V_48 ) ;
continue;
}
F_205 (child, cgrp) {
if ( V_251 -> V_114 & ( 1 << V_48 ) ) {
V_6 = - V_123 ;
goto V_155;
}
}
}
}
if ( ! V_245 && ! V_246 ) {
V_6 = 0 ;
goto V_155;
}
if ( V_245 && F_11 ( V_10 ) && ! F_35 ( & V_10 -> V_55 ) ) {
V_6 = - V_123 ;
goto V_155;
}
V_10 -> V_114 |= V_245 ;
V_10 -> V_114 &= ~ V_246 ;
V_249 = V_10 -> V_21 ;
F_92 ( V_10 ) ;
V_250 = V_10 -> V_21 ;
V_247 = ~ V_249 & V_250 ;
V_248 = V_249 & ~ V_250 ;
V_245 |= V_247 ;
V_246 |= V_248 ;
F_29 (ss, ssid) {
if ( ! ( V_245 & ( 1 << V_48 ) ) )
continue;
F_205 (child, cgrp) {
if ( V_247 & ( 1 << V_48 ) )
V_6 = F_210 ( V_251 , V_16 ,
V_10 -> V_114 & ( 1 << V_48 ) ) ;
else
V_6 = F_103 ( V_251 , 1 << V_48 ) ;
if ( V_6 )
goto V_255;
}
}
V_6 = F_200 ( V_10 ) ;
if ( V_6 )
goto V_255;
F_29 (ss, ssid) {
if ( ! ( V_246 & ( 1 << V_48 ) ) )
continue;
F_205 (child, cgrp) {
struct V_11 * V_39 = F_13 ( V_251 , V_16 ) ;
if ( V_248 & ( 1 << V_48 ) ) {
F_211 ( V_39 ) ;
} else {
F_100 ( V_251 , 1 << V_48 ) ;
if ( V_16 -> V_256 )
V_16 -> V_256 ( V_39 ) ;
}
}
}
F_110 ( V_10 -> V_26 ) ;
V_6 = 0 ;
V_155:
F_93 ( V_25 -> V_26 ) ;
return V_6 ? : V_221 ;
V_255:
V_10 -> V_114 &= ~ V_245 ;
V_10 -> V_114 |= V_246 ;
F_92 ( V_10 ) ;
F_29 (ss, ssid) {
if ( ! ( V_245 & ( 1 << V_48 ) ) )
continue;
F_205 (child, cgrp) {
struct V_11 * V_39 = F_13 ( V_251 , V_16 ) ;
if ( ! V_39 )
continue;
if ( V_247 & ( 1 << V_48 ) )
F_211 ( V_39 ) ;
else
F_100 ( V_251 , 1 << V_48 ) ;
}
}
goto V_155;
}
static int F_212 ( struct V_128 * V_129 , void * V_241 )
{
F_112 ( V_129 , L_32 , ( bool ) F_193 ( V_129 ) -> V_9 -> V_37 ) ;
return 0 ;
}
static T_4 F_213 ( struct V_24 * V_25 , char * V_99 ,
T_3 V_221 , T_5 V_222 )
{
struct V_9 * V_10 = V_25 -> V_26 -> V_14 -> V_27 ;
struct V_28 * V_29 = V_25 -> V_26 -> V_27 ;
struct V_11 * V_39 ;
int V_6 ;
if ( V_29 -> V_111 )
return V_29 -> V_111 ( V_25 , V_99 , V_221 , V_222 ) ;
F_172 () ;
V_39 = F_13 ( V_10 , V_29 -> V_16 ) ;
F_179 () ;
if ( V_29 -> V_109 ) {
unsigned long long V_241 ;
V_6 = F_214 ( V_99 , 0 , & V_241 ) ;
if ( ! V_6 )
V_6 = V_29 -> V_109 ( V_39 , V_29 , V_241 ) ;
} else if ( V_29 -> V_110 ) {
long long V_241 ;
V_6 = F_215 ( V_99 , 0 , & V_241 ) ;
if ( ! V_6 )
V_6 = V_29 -> V_110 ( V_39 , V_29 , V_241 ) ;
} else {
V_6 = - V_144 ;
}
return V_6 ? : V_221 ;
}
static void * F_216 ( struct V_128 * V_129 , T_5 * V_257 )
{
return F_217 ( V_129 ) -> F_218 ( V_129 , V_257 ) ;
}
static void * F_219 ( struct V_128 * V_129 , void * V_241 , T_5 * V_257 )
{
return F_217 ( V_129 ) -> F_220 ( V_129 , V_241 , V_257 ) ;
}
static void F_221 ( struct V_128 * V_129 , void * V_241 )
{
F_217 ( V_129 ) -> F_222 ( V_129 , V_241 ) ;
}
static int F_223 ( struct V_128 * V_258 , void * V_259 )
{
struct V_28 * V_29 = F_217 ( V_258 ) ;
struct V_11 * V_39 = F_193 ( V_258 ) ;
if ( V_29 -> V_107 )
return V_29 -> V_107 ( V_258 , V_259 ) ;
if ( V_29 -> V_105 )
F_112 ( V_258 , L_33 , V_29 -> V_105 ( V_39 , V_29 ) ) ;
else if ( V_29 -> V_106 )
F_112 ( V_258 , L_34 , V_29 -> V_106 ( V_39 , V_29 ) ) ;
else
return - V_144 ;
return 0 ;
}
static int F_224 ( struct V_117 * V_26 , struct V_117 * V_260 ,
const char * V_261 )
{
struct V_9 * V_10 = V_26 -> V_27 ;
int V_6 ;
if ( F_94 ( V_26 ) != V_118 )
return - V_262 ;
if ( V_26 -> V_14 != V_260 )
return - V_263 ;
if ( F_57 ( V_10 ) )
return - V_264 ;
F_97 ( V_260 ) ;
F_97 ( V_26 ) ;
F_76 ( & V_18 ) ;
V_6 = F_225 ( V_26 , V_260 , V_261 ) ;
F_79 ( & V_18 ) ;
F_95 ( V_26 ) ;
F_95 ( V_260 ) ;
return V_6 ;
}
static int F_226 ( struct V_117 * V_26 )
{
struct V_265 V_265 = { . V_266 = V_267 | V_268 ,
. V_269 = F_227 () ,
. V_270 = F_228 () , } ;
if ( F_181 ( V_265 . V_269 , V_231 ) &&
F_229 ( V_265 . V_270 , V_271 ) )
return 0 ;
return F_230 ( V_26 , & V_265 ) ;
}
static int F_231 ( struct V_9 * V_10 , struct V_28 * V_29 )
{
char V_103 [ V_102 ] ;
struct V_117 * V_26 ;
struct V_272 * V_40 = NULL ;
int V_6 ;
#ifdef F_232
V_40 = & V_29 -> V_273 ;
#endif
V_26 = F_233 ( V_10 -> V_26 , F_84 ( V_10 , V_29 , V_103 ) ,
F_85 ( V_29 ) , 0 , V_29 -> V_274 , V_29 ,
NULL , false , V_40 ) ;
if ( F_139 ( V_26 ) )
return F_140 ( V_26 ) ;
V_6 = F_226 ( V_26 ) ;
if ( V_6 ) {
F_234 ( V_26 ) ;
return V_6 ;
}
if ( V_29 -> V_107 == F_212 )
V_10 -> V_38 = V_26 ;
return 0 ;
}
static int F_101 ( struct V_9 * V_10 , struct V_28 V_119 [] ,
bool V_275 )
{
struct V_28 * V_29 ;
int V_6 ;
F_17 ( & V_18 ) ;
for ( V_29 = V_119 ; V_29 -> V_103 [ 0 ] != '\0' ; V_29 ++ ) {
if ( ( V_29 -> V_22 & V_276 ) && ! F_57 ( V_10 ) )
continue;
if ( ( V_29 -> V_22 & V_277 ) && F_57 ( V_10 ) )
continue;
if ( ( V_29 -> V_22 & V_278 ) && ! F_11 ( V_10 ) )
continue;
if ( ( V_29 -> V_22 & V_279 ) && F_11 ( V_10 ) )
continue;
if ( V_275 ) {
V_6 = F_231 ( V_10 , V_29 ) ;
if ( V_6 ) {
F_104 ( L_35 ,
V_280 , V_29 -> V_103 , V_6 ) ;
return V_6 ;
}
} else {
F_98 ( V_10 , V_29 ) ;
}
}
return 0 ;
}
static int F_235 ( struct V_28 * V_119 , bool V_275 )
{
F_136 ( V_281 ) ;
struct V_15 * V_16 = V_119 [ 0 ] . V_16 ;
struct V_9 * V_19 = & V_16 -> V_19 -> V_10 ;
struct V_11 * V_39 ;
int V_6 = 0 ;
F_17 ( & V_18 ) ;
F_201 (css, cgroup_css(root, ss)) {
struct V_9 * V_10 = V_39 -> V_9 ;
if ( F_18 ( V_10 ) )
continue;
V_6 = F_101 ( V_10 , V_119 , V_275 ) ;
if ( V_6 )
break;
}
if ( V_275 && ! V_6 )
F_110 ( V_19 -> V_26 ) ;
return V_6 ;
}
static void F_236 ( struct V_28 * V_119 )
{
struct V_28 * V_29 ;
for ( V_29 = V_119 ; V_29 -> V_103 [ 0 ] != '\0' ; V_29 ++ ) {
if ( V_29 -> V_282 && V_29 -> V_282 != V_283 )
F_38 ( V_29 -> V_274 ) ;
V_29 -> V_274 = NULL ;
V_29 -> V_16 = NULL ;
V_29 -> V_22 &= ~ ( V_276 | V_277 ) ;
}
}
static int F_237 ( struct V_15 * V_16 , struct V_28 * V_119 )
{
struct V_28 * V_29 ;
for ( V_29 = V_119 ; V_29 -> V_103 [ 0 ] != '\0' ; V_29 ++ ) {
struct V_284 * V_274 ;
F_105 ( V_29 -> V_16 || V_29 -> V_274 ) ;
if ( V_29 -> F_218 )
V_274 = & V_285 ;
else
V_274 = & V_286 ;
if ( V_29 -> V_282 && V_29 -> V_282 != V_283 ) {
V_274 = F_238 ( V_274 , sizeof( * V_274 ) , V_73 ) ;
if ( ! V_274 ) {
F_236 ( V_119 ) ;
return - V_74 ;
}
V_274 -> V_287 = V_29 -> V_282 ;
}
V_29 -> V_274 = V_274 ;
V_29 -> V_16 = V_16 ;
}
return 0 ;
}
static int F_239 ( struct V_28 * V_119 )
{
F_17 ( & V_18 ) ;
if ( ! V_119 || ! V_119 [ 0 ] . V_16 )
return - V_152 ;
F_32 ( & V_119 -> V_288 ) ;
F_235 ( V_119 , false ) ;
F_236 ( V_119 ) ;
return 0 ;
}
int F_240 ( struct V_28 * V_119 )
{
int V_6 ;
F_76 ( & V_18 ) ;
V_6 = F_239 ( V_119 ) ;
F_79 ( & V_18 ) ;
return V_6 ;
}
static int F_241 ( struct V_15 * V_16 , struct V_28 * V_119 )
{
int V_6 ;
if ( V_16 -> V_151 )
return 0 ;
if ( ! V_119 || V_119 [ 0 ] . V_103 [ 0 ] == '\0' )
return 0 ;
V_6 = F_237 ( V_16 , V_119 ) ;
if ( V_6 )
return V_6 ;
F_76 ( & V_18 ) ;
F_60 ( & V_119 -> V_288 , & V_16 -> V_119 ) ;
V_6 = F_235 ( V_119 , true ) ;
if ( V_6 )
F_239 ( V_119 ) ;
F_79 ( & V_18 ) ;
return V_6 ;
}
int F_242 ( struct V_15 * V_16 , struct V_28 * V_119 )
{
struct V_28 * V_29 ;
for ( V_29 = V_119 ; V_29 && V_29 -> V_103 [ 0 ] != '\0' ; V_29 ++ )
V_29 -> V_22 |= V_276 ;
return F_241 ( V_16 , V_119 ) ;
}
int F_243 ( struct V_15 * V_16 , struct V_28 * V_119 )
{
struct V_28 * V_29 ;
if ( ! V_289 ||
V_16 -> V_290 != V_16 -> V_291 ) {
for ( V_29 = V_119 ; V_29 && V_29 -> V_103 [ 0 ] != '\0' ; V_29 ++ )
V_29 -> V_22 |= V_277 ;
}
return F_241 ( V_16 , V_119 ) ;
}
static int F_244 ( const struct V_9 * V_10 )
{
int V_71 = 0 ;
struct V_45 * V_46 ;
F_62 ( & V_35 ) ;
F_66 (link, &cgrp->cset_links, cset_link)
V_71 += F_77 ( & V_46 -> V_43 -> V_49 ) ;
F_63 ( & V_35 ) ;
return V_71 ;
}
struct V_11 * F_102 ( struct V_11 * V_292 ,
struct V_11 * V_14 )
{
struct V_11 * V_68 ;
F_245 () ;
if ( ! V_292 ) {
V_68 = F_246 ( V_14 -> V_92 . V_68 , struct V_11 , V_166 ) ;
} else if ( F_247 ( ! ( V_292 -> V_22 & V_293 ) ) ) {
V_68 = F_246 ( V_292 -> V_166 . V_68 , struct V_11 , V_166 ) ;
} else {
F_248 (next, &parent->children, sibling)
if ( V_68 -> V_294 > V_292 -> V_294 )
break;
}
if ( & V_68 -> V_166 != & V_14 -> V_92 )
return V_68 ;
return NULL ;
}
struct V_11 *
F_249 ( struct V_11 * V_292 ,
struct V_11 * V_19 )
{
struct V_11 * V_68 ;
F_245 () ;
if ( ! V_292 )
return V_19 ;
V_68 = F_102 ( NULL , V_292 ) ;
if ( V_68 )
return V_68 ;
while ( V_292 != V_19 ) {
V_68 = F_102 ( V_292 , V_292 -> V_14 ) ;
if ( V_68 )
return V_68 ;
V_292 = V_292 -> V_14 ;
}
return NULL ;
}
struct V_11 *
F_250 ( struct V_11 * V_292 )
{
struct V_11 * V_295 , * V_296 ;
F_245 () ;
do {
V_295 = V_292 ;
V_292 = NULL ;
F_251 (tmp, last)
V_292 = V_296 ;
} while ( V_292 );
return V_295 ;
}
static struct V_11 *
F_252 ( struct V_11 * V_292 )
{
struct V_11 * V_295 ;
do {
V_295 = V_292 ;
V_292 = F_102 ( NULL , V_292 ) ;
} while ( V_292 );
return V_295 ;
}
struct V_11 *
F_253 ( struct V_11 * V_292 ,
struct V_11 * V_19 )
{
struct V_11 * V_68 ;
F_245 () ;
if ( ! V_292 )
return F_252 ( V_19 ) ;
if ( V_292 == V_19 )
return NULL ;
V_68 = F_102 ( V_292 , V_292 -> V_14 ) ;
if ( V_68 )
return F_252 ( V_68 ) ;
return V_292 -> V_14 ;
}
bool F_154 ( struct V_11 * V_39 )
{
struct V_11 * V_251 ;
bool V_6 = false ;
F_172 () ;
F_251 (child, css) {
if ( V_251 -> V_22 & V_23 ) {
V_6 = true ;
break;
}
}
F_179 () ;
return V_6 ;
}
static void F_254 ( struct V_297 * V_298 )
{
struct V_60 * V_299 = V_298 -> V_300 ;
struct V_45 * V_46 ;
struct V_42 * V_43 ;
do {
V_299 = V_299 -> V_68 ;
if ( V_299 == V_298 -> V_301 ) {
V_298 -> V_300 = NULL ;
return;
}
if ( V_298 -> V_16 ) {
V_43 = F_12 ( V_299 , struct V_42 ,
V_50 [ V_298 -> V_16 -> V_8 ] ) ;
} else {
V_46 = F_48 ( V_299 , struct V_45 , V_53 ) ;
V_43 = V_46 -> V_43 ;
}
} while ( F_35 ( & V_43 -> V_78 ) && F_35 ( & V_43 -> V_79 ) );
V_298 -> V_300 = V_299 ;
if ( ! F_35 ( & V_43 -> V_78 ) )
V_298 -> V_302 = V_43 -> V_78 . V_68 ;
else
V_298 -> V_302 = V_43 -> V_79 . V_68 ;
V_298 -> V_303 = & V_43 -> V_78 ;
V_298 -> V_304 = & V_43 -> V_79 ;
}
void F_255 ( struct V_11 * V_39 ,
struct V_297 * V_298 )
__acquires( V_35 )
{
F_73 ( ! V_160 ) ;
F_62 ( & V_35 ) ;
V_298 -> V_16 = V_39 -> V_16 ;
if ( V_298 -> V_16 )
V_298 -> V_300 = & V_39 -> V_9 -> V_84 [ V_39 -> V_16 -> V_8 ] ;
else
V_298 -> V_300 = & V_39 -> V_9 -> V_55 ;
V_298 -> V_301 = V_298 -> V_300 ;
F_254 ( V_298 ) ;
}
struct V_97 * F_256 ( struct V_297 * V_298 )
{
struct V_97 * V_95 ;
struct V_60 * V_299 = V_298 -> V_302 ;
if ( ! V_298 -> V_300 )
return NULL ;
V_95 = F_48 ( V_299 , struct V_97 , V_162 ) ;
V_299 = V_299 -> V_68 ;
if ( V_299 == V_298 -> V_303 )
V_299 = V_298 -> V_304 -> V_68 ;
if ( V_299 == V_298 -> V_304 )
F_254 ( V_298 ) ;
else
V_298 -> V_302 = V_299 ;
return V_95 ;
}
void F_257 ( struct V_297 * V_298 )
__releases( V_35 )
{
F_63 ( & V_35 ) ;
}
int F_258 ( struct V_9 * V_305 , struct V_9 * V_238 )
{
F_136 ( V_206 ) ;
struct V_45 * V_46 ;
struct V_297 V_298 ;
struct V_97 * V_98 ;
int V_6 ;
F_76 ( & V_18 ) ;
F_62 ( & V_35 ) ;
F_66 (link, &from->cset_links, cset_link)
F_167 ( V_46 -> V_43 , V_305 , & V_206 ) ;
F_63 ( & V_35 ) ;
V_6 = F_168 ( V_305 , & V_206 ) ;
if ( V_6 )
goto V_306;
do {
F_255 ( & V_238 -> V_13 , & V_298 ) ;
V_98 = F_256 ( & V_298 ) ;
if ( V_98 )
F_182 ( V_98 ) ;
F_257 ( & V_298 ) ;
if ( V_98 ) {
V_6 = F_170 ( V_305 , V_98 , false ) ;
F_186 ( V_98 ) ;
}
} while ( V_98 && ! V_6 );
V_306:
F_165 ( & V_206 ) ;
F_79 ( & V_18 ) ;
return V_6 ;
}
static void * F_259 ( int V_71 )
{
if ( F_260 ( V_71 ) )
return F_261 ( V_71 * sizeof( T_6 ) ) ;
else
return F_262 ( V_71 * sizeof( T_6 ) , V_73 ) ;
}
static void F_263 ( void * V_158 )
{
if ( F_264 ( V_158 ) )
F_265 ( V_158 ) ;
else
F_38 ( V_158 ) ;
}
static void F_266 ( struct V_9 * V_10 )
{
struct V_307 * V_299 , * V_308 ;
F_76 ( & V_10 -> V_169 ) ;
F_34 (l, tmp_l, &cgrp->pidlists, links)
F_267 ( V_309 , & V_299 -> V_310 , 0 ) ;
F_79 ( & V_10 -> V_169 ) ;
F_268 ( V_309 ) ;
F_47 ( ! F_35 ( & V_10 -> V_168 ) ) ;
}
static void F_269 ( struct V_311 * V_312 )
{
struct V_313 * V_314 = F_270 ( V_312 ) ;
struct V_307 * V_299 = F_12 ( V_314 , struct V_307 ,
V_310 ) ;
struct V_307 * V_315 = NULL ;
F_76 ( & V_299 -> V_316 -> V_169 ) ;
if ( ! F_271 ( V_314 ) ) {
F_32 ( & V_299 -> V_317 ) ;
F_263 ( V_299 -> V_318 ) ;
F_272 ( V_299 -> V_40 . V_319 ) ;
V_315 = V_299 ;
}
F_79 ( & V_299 -> V_316 -> V_169 ) ;
F_38 ( V_315 ) ;
}
static int F_273 ( T_6 * V_318 , int V_320 )
{
int V_321 , V_322 = 1 ;
if ( V_320 == 0 || V_320 == 1 )
return V_320 ;
for ( V_321 = 1 ; V_321 < V_320 ; V_321 ++ ) {
while ( V_318 [ V_321 ] == V_318 [ V_321 - 1 ] ) {
V_321 ++ ;
if ( V_321 == V_320 )
goto V_323;
}
V_318 [ V_322 ] = V_318 [ V_321 ] ;
V_322 ++ ;
}
V_323:
return V_322 ;
}
static T_6 F_274 ( T_6 V_225 )
{
unsigned V_324 = V_225 & 0x55555555 ;
unsigned V_325 = V_225 & 0xAAAAAAAA ;
return ( V_324 << 1 ) | ( V_325 >> 1 ) ;
}
static T_6 F_275 ( struct V_9 * V_10 , T_6 V_225 )
{
if ( F_57 ( V_10 ) )
return F_274 ( V_225 ) ;
else
return V_225 ;
}
static int F_276 ( const void * V_324 , const void * V_325 )
{
return * ( T_6 * ) V_324 - * ( T_6 * ) V_325 ;
}
static int F_277 ( const void * V_324 , const void * V_325 )
{
return F_274 ( * ( T_6 * ) V_324 ) - F_274 ( * ( T_6 * ) V_325 ) ;
}
static struct V_307 * F_278 ( struct V_9 * V_10 ,
enum V_326 type )
{
struct V_307 * V_299 ;
struct V_327 * V_319 = F_279 ( V_156 ) ;
F_17 ( & V_10 -> V_169 ) ;
F_66 (l, &cgrp->pidlists, links)
if ( V_299 -> V_40 . type == type && V_299 -> V_40 . V_319 == V_319 )
return V_299 ;
return NULL ;
}
static struct V_307 * F_280 ( struct V_9 * V_10 ,
enum V_326 type )
{
struct V_307 * V_299 ;
F_17 ( & V_10 -> V_169 ) ;
V_299 = F_278 ( V_10 , type ) ;
if ( V_299 )
return V_299 ;
V_299 = F_54 ( sizeof( struct V_307 ) , V_73 ) ;
if ( ! V_299 )
return V_299 ;
F_281 ( & V_299 -> V_310 , F_269 ) ;
V_299 -> V_40 . type = type ;
V_299 -> V_40 . V_319 = F_282 ( F_279 ( V_156 ) ) ;
V_299 -> V_316 = V_10 ;
F_55 ( & V_299 -> V_317 , & V_10 -> V_168 ) ;
return V_299 ;
}
static int F_283 ( struct V_9 * V_10 , enum V_326 type ,
struct V_307 * * V_328 )
{
T_6 * V_329 ;
int V_320 ;
int V_225 , V_330 = 0 ;
struct V_297 V_298 ;
struct V_97 * V_203 ;
struct V_307 * V_299 ;
F_17 ( & V_10 -> V_169 ) ;
V_320 = F_244 ( V_10 ) ;
V_329 = F_259 ( V_320 ) ;
if ( ! V_329 )
return - V_74 ;
F_255 ( & V_10 -> V_13 , & V_298 ) ;
while ( ( V_203 = F_256 ( & V_298 ) ) ) {
if ( F_284 ( V_330 == V_320 ) )
break;
if ( type == V_331 )
V_225 = F_285 ( V_203 ) ;
else
V_225 = F_286 ( V_203 ) ;
if ( V_225 > 0 )
V_329 [ V_330 ++ ] = V_225 ;
}
F_257 ( & V_298 ) ;
V_320 = V_330 ;
if ( F_57 ( V_10 ) )
F_287 ( V_329 , V_320 , sizeof( T_6 ) , F_277 , NULL ) ;
else
F_287 ( V_329 , V_320 , sizeof( T_6 ) , F_276 , NULL ) ;
if ( type == V_331 )
V_320 = F_273 ( V_329 , V_320 ) ;
V_299 = F_280 ( V_10 , type ) ;
if ( ! V_299 ) {
F_263 ( V_329 ) ;
return - V_74 ;
}
F_263 ( V_299 -> V_318 ) ;
V_299 -> V_318 = V_329 ;
V_299 -> V_320 = V_320 ;
* V_328 = V_299 ;
return 0 ;
}
int F_288 ( struct V_332 * V_333 , struct V_184 * V_184 )
{
struct V_117 * V_26 = F_289 ( V_184 ) ;
struct V_9 * V_10 ;
struct V_297 V_298 ;
struct V_97 * V_203 ;
if ( V_184 -> V_334 -> V_335 != & V_336 || ! V_26 ||
F_94 ( V_26 ) != V_118 )
return - V_144 ;
F_76 ( & V_18 ) ;
F_172 () ;
V_10 = F_290 ( V_26 -> V_27 ) ;
if ( ! V_10 || F_18 ( V_10 ) ) {
F_179 () ;
F_79 ( & V_18 ) ;
return - V_152 ;
}
F_179 () ;
F_255 ( & V_10 -> V_13 , & V_298 ) ;
while ( ( V_203 = F_256 ( & V_298 ) ) ) {
switch ( V_203 -> V_337 ) {
case V_338 :
V_333 -> V_339 ++ ;
break;
case V_340 :
V_333 -> V_341 ++ ;
break;
case V_254 :
V_333 -> V_342 ++ ;
break;
case V_343 :
V_333 -> V_344 ++ ;
break;
default:
if ( F_291 ( V_203 ) )
V_333 -> V_345 ++ ;
break;
}
}
F_257 ( & V_298 ) ;
F_79 ( & V_18 ) ;
return 0 ;
}
static void * F_292 ( struct V_128 * V_346 , T_5 * V_292 )
{
struct V_24 * V_25 = V_346 -> V_347 ;
struct V_9 * V_10 = F_193 ( V_346 ) -> V_9 ;
struct V_307 * V_299 ;
enum V_326 type = F_217 ( V_346 ) -> V_347 ;
int V_348 = 0 , V_225 = * V_292 ;
int * V_349 , V_6 ;
F_76 ( & V_10 -> V_169 ) ;
if ( V_25 -> V_27 )
V_25 -> V_27 = F_278 ( V_10 , type ) ;
if ( ! V_25 -> V_27 ) {
V_6 = F_283 ( V_10 , type ,
(struct V_307 * * ) & V_25 -> V_27 ) ;
if ( V_6 )
return F_150 ( V_6 ) ;
}
V_299 = V_25 -> V_27 ;
if ( V_225 ) {
int V_4 = V_299 -> V_320 ;
while ( V_348 < V_4 ) {
int V_350 = ( V_348 + V_4 ) / 2 ;
if ( F_275 ( V_10 , V_299 -> V_318 [ V_350 ] ) == V_225 ) {
V_348 = V_350 ;
break;
} else if ( F_275 ( V_10 , V_299 -> V_318 [ V_350 ] ) <= V_225 )
V_348 = V_350 + 1 ;
else
V_4 = V_350 ;
}
}
if ( V_348 >= V_299 -> V_320 )
return NULL ;
V_349 = V_299 -> V_318 + V_348 ;
* V_292 = F_275 ( V_10 , * V_349 ) ;
return V_349 ;
}
static void F_293 ( struct V_128 * V_346 , void * V_241 )
{
struct V_24 * V_25 = V_346 -> V_347 ;
struct V_307 * V_299 = V_25 -> V_27 ;
if ( V_299 )
F_267 ( V_309 , & V_299 -> V_310 ,
V_351 ) ;
F_79 ( & F_193 ( V_346 ) -> V_9 -> V_169 ) ;
}
static void * F_294 ( struct V_128 * V_346 , void * V_241 , T_5 * V_292 )
{
struct V_24 * V_25 = V_346 -> V_347 ;
struct V_307 * V_299 = V_25 -> V_27 ;
T_6 * V_158 = V_241 ;
T_6 * V_4 = V_299 -> V_318 + V_299 -> V_320 ;
V_158 ++ ;
if ( V_158 >= V_4 ) {
return NULL ;
} else {
* V_292 = F_275 ( F_193 ( V_346 ) -> V_9 , * V_158 ) ;
return V_158 ;
}
}
static int F_295 ( struct V_128 * V_346 , void * V_241 )
{
return F_112 ( V_346 , L_32 , * ( int * ) V_241 ) ;
}
static T_7 F_296 ( struct V_11 * V_39 ,
struct V_28 * V_29 )
{
return F_24 ( V_39 -> V_9 ) ;
}
static int F_297 ( struct V_11 * V_39 ,
struct V_28 * V_29 , T_7 V_352 )
{
F_298 ( V_32 , & V_39 -> V_9 -> V_22 ) ;
if ( V_352 )
F_36 ( V_33 , & V_39 -> V_9 -> V_22 ) ;
else
F_298 ( V_33 , & V_39 -> V_9 -> V_22 ) ;
return 0 ;
}
static T_7 F_299 ( struct V_11 * V_39 ,
struct V_28 * V_29 )
{
return F_25 ( V_133 , & V_39 -> V_9 -> V_22 ) ;
}
static int F_300 ( struct V_11 * V_39 ,
struct V_28 * V_29 , T_7 V_352 )
{
if ( V_352 )
F_36 ( V_133 , & V_39 -> V_9 -> V_22 ) ;
else
F_298 ( V_133 , & V_39 -> V_9 -> V_22 ) ;
return 0 ;
}
static int F_103 ( struct V_9 * V_10 , unsigned int V_20 )
{
struct V_15 * V_16 ;
int V_41 , V_6 = 0 ;
F_29 (ss, i) {
struct V_28 * V_119 ;
if ( ! ( V_20 & ( 1 << V_41 ) ) )
continue;
F_66 (cfts, &ss->cfts, node) {
V_6 = F_101 ( V_10 , V_119 , true ) ;
if ( V_6 < 0 )
goto V_214;
}
}
return 0 ;
V_214:
F_100 ( V_10 , V_20 ) ;
return V_6 ;
}
static void F_301 ( struct V_311 * V_312 )
{
struct V_11 * V_39 =
F_12 ( V_312 , struct V_11 , V_353 ) ;
struct V_9 * V_10 = V_39 -> V_9 ;
F_141 ( & V_39 -> V_174 ) ;
if ( V_39 -> V_16 ) {
if ( V_39 -> V_14 )
F_91 ( V_39 -> V_14 ) ;
V_39 -> V_16 -> V_354 ( V_39 ) ;
F_90 ( V_10 ) ;
} else {
F_302 ( & V_10 -> V_19 -> V_91 ) ;
F_266 ( V_10 ) ;
if ( F_11 ( V_10 ) ) {
F_90 ( F_11 ( V_10 ) ) ;
F_303 ( V_10 -> V_26 ) ;
F_38 ( V_10 ) ;
} else {
F_75 ( V_10 -> V_19 ) ;
}
}
}
static void F_304 ( struct V_56 * V_56 )
{
struct V_11 * V_39 =
F_12 ( V_56 , struct V_11 , V_56 ) ;
F_305 ( & V_39 -> V_353 , F_301 ) ;
F_306 ( V_355 , & V_39 -> V_353 ) ;
}
static void F_307 ( struct V_311 * V_312 )
{
struct V_11 * V_39 =
F_12 ( V_312 , struct V_11 , V_353 ) ;
struct V_15 * V_16 = V_39 -> V_16 ;
struct V_9 * V_10 = V_39 -> V_9 ;
F_76 ( & V_18 ) ;
V_39 -> V_22 |= V_293 ;
F_308 ( & V_39 -> V_166 ) ;
if ( V_16 ) {
F_9 ( & V_16 -> V_356 , V_39 -> V_8 ) ;
} else {
F_9 ( & V_10 -> V_19 -> V_90 , V_10 -> V_8 ) ;
V_10 -> V_8 = - 1 ;
F_106 ( * ( void V_357 V_358 * * ) & V_10 -> V_26 -> V_27 , NULL ) ;
}
F_79 ( & V_18 ) ;
F_309 ( & V_39 -> V_56 , F_304 ) ;
}
static void V_175 ( struct V_359 * V_360 )
{
struct V_11 * V_39 =
F_12 ( V_360 , struct V_11 , V_174 ) ;
F_305 ( & V_39 -> V_353 , F_307 ) ;
F_306 ( V_355 , & V_39 -> V_353 ) ;
}
static void F_310 ( struct V_11 * V_39 ,
struct V_15 * V_16 , struct V_9 * V_10 )
{
F_17 ( & V_18 ) ;
F_86 ( V_10 ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_9 = V_10 ;
V_39 -> V_16 = V_16 ;
F_53 ( & V_39 -> V_166 ) ;
F_53 ( & V_39 -> V_92 ) ;
V_39 -> V_294 = V_361 ++ ;
if ( F_11 ( V_10 ) ) {
V_39 -> V_14 = F_13 ( F_11 ( V_10 ) , V_16 ) ;
F_87 ( V_39 -> V_14 ) ;
}
F_47 ( F_13 ( V_10 , V_16 ) ) ;
}
static int F_311 ( struct V_11 * V_39 )
{
struct V_15 * V_16 = V_39 -> V_16 ;
int V_6 = 0 ;
F_17 ( & V_18 ) ;
if ( V_16 -> V_362 )
V_6 = V_16 -> V_362 ( V_39 ) ;
if ( ! V_6 ) {
V_39 -> V_22 |= V_23 ;
F_107 ( V_39 -> V_9 -> V_17 [ V_16 -> V_8 ] , V_39 ) ;
}
return V_6 ;
}
static void F_312 ( struct V_11 * V_39 )
{
struct V_15 * V_16 = V_39 -> V_16 ;
F_17 ( & V_18 ) ;
if ( ! ( V_39 -> V_22 & V_23 ) )
return;
if ( V_16 -> V_363 )
V_16 -> V_363 ( V_39 ) ;
V_39 -> V_22 &= ~ V_23 ;
F_106 ( V_39 -> V_9 -> V_17 [ V_16 -> V_8 ] , NULL ) ;
F_313 ( & V_39 -> V_9 -> V_170 ) ;
}
static int F_210 ( struct V_9 * V_10 , struct V_15 * V_16 ,
bool V_364 )
{
struct V_9 * V_14 = F_11 ( V_10 ) ;
struct V_11 * V_12 = F_13 ( V_14 , V_16 ) ;
struct V_11 * V_39 ;
int V_214 ;
F_17 ( & V_18 ) ;
V_39 = V_16 -> V_365 ( V_12 ) ;
if ( F_139 ( V_39 ) )
return F_140 ( V_39 ) ;
F_310 ( V_39 , V_16 , V_10 ) ;
V_214 = F_137 ( & V_39 -> V_174 , V_175 ) ;
if ( V_214 )
goto V_366;
V_214 = F_1 ( & V_16 -> V_356 , NULL , 2 , 0 , V_172 ) ;
if ( V_214 < 0 )
goto V_367;
V_39 -> V_8 = V_214 ;
if ( V_364 ) {
V_214 = F_103 ( V_10 , 1 << V_16 -> V_8 ) ;
if ( V_214 )
goto V_368;
}
F_314 ( & V_39 -> V_166 , & V_12 -> V_92 ) ;
F_7 ( & V_16 -> V_356 , V_39 , V_39 -> V_8 ) ;
V_214 = F_311 ( V_39 ) ;
if ( V_214 )
goto V_369;
if ( V_16 -> V_370 && ! V_16 -> V_371 &&
F_11 ( V_14 ) ) {
F_104 ( L_36 ,
V_156 -> V_157 , V_156 -> V_225 , V_16 -> V_103 ) ;
if ( ! strcmp ( V_16 -> V_103 , L_37 ) )
F_104 ( L_38 ) ;
V_16 -> V_371 = true ;
}
return 0 ;
V_369:
F_308 ( & V_39 -> V_166 ) ;
F_100 ( V_39 -> V_9 , 1 << V_39 -> V_16 -> V_8 ) ;
V_368:
F_9 ( & V_16 -> V_356 , V_39 -> V_8 ) ;
V_367:
F_141 ( & V_39 -> V_174 ) ;
V_366:
F_309 ( & V_39 -> V_56 , F_304 ) ;
return V_214 ;
}
static int F_315 ( struct V_117 * V_372 , const char * V_103 ,
T_2 V_104 )
{
struct V_9 * V_14 , * V_10 ;
struct V_69 * V_19 ;
struct V_15 * V_16 ;
struct V_117 * V_26 ;
struct V_28 * V_171 ;
int V_48 , V_6 ;
if ( strchr ( V_103 , '\n' ) )
return - V_144 ;
V_14 = F_96 ( V_372 ) ;
if ( ! V_14 )
return - V_226 ;
V_19 = V_14 -> V_19 ;
V_10 = F_54 ( sizeof( * V_10 ) , V_73 ) ;
if ( ! V_10 ) {
V_6 = - V_74 ;
goto V_155;
}
V_6 = F_137 ( & V_10 -> V_13 . V_174 , V_175 ) ;
if ( V_6 )
goto V_373;
V_10 -> V_8 = F_1 ( & V_19 -> V_90 , NULL , 2 , 0 , V_172 ) ;
if ( V_10 -> V_8 < 0 ) {
V_6 = - V_74 ;
goto V_374;
}
F_130 ( V_10 ) ;
V_10 -> V_13 . V_14 = & V_14 -> V_13 ;
V_10 -> V_19 = V_19 ;
if ( F_24 ( V_14 ) )
F_36 ( V_33 , & V_10 -> V_22 ) ;
if ( F_25 ( V_133 , & V_14 -> V_22 ) )
F_36 ( V_133 , & V_10 -> V_22 ) ;
V_26 = F_316 ( V_14 -> V_26 , V_103 , V_104 , V_10 ) ;
if ( F_139 ( V_26 ) ) {
V_6 = F_140 ( V_26 ) ;
goto V_375;
}
V_10 -> V_26 = V_26 ;
F_317 ( V_26 ) ;
V_10 -> V_13 . V_294 = V_361 ++ ;
F_314 ( & V_10 -> V_13 . V_166 , & F_11 ( V_10 ) -> V_13 . V_92 ) ;
F_45 ( & V_19 -> V_91 ) ;
F_86 ( V_14 ) ;
F_7 ( & V_19 -> V_90 , V_10 , V_10 -> V_8 ) ;
V_6 = F_226 ( V_26 ) ;
if ( V_6 )
goto V_376;
if ( F_57 ( V_10 ) )
V_171 = V_180 ;
else
V_171 = V_181 ;
V_6 = F_101 ( V_10 , V_171 , true ) ;
if ( V_6 )
goto V_376;
F_29 (ss, ssid) {
if ( V_14 -> V_21 & ( 1 << V_48 ) ) {
V_6 = F_210 ( V_10 , V_16 ,
V_14 -> V_114 & ( 1 << V_48 ) ) ;
if ( V_6 )
goto V_376;
}
}
if ( ! F_57 ( V_10 ) ) {
V_10 -> V_114 = V_14 -> V_114 ;
F_92 ( V_10 ) ;
}
F_110 ( V_26 ) ;
V_6 = 0 ;
goto V_155;
V_375:
F_9 ( & V_19 -> V_90 , V_10 -> V_8 ) ;
V_374:
F_141 ( & V_10 -> V_13 . V_174 ) ;
V_373:
F_38 ( V_10 ) ;
V_155:
F_93 ( V_372 ) ;
return V_6 ;
V_376:
F_318 ( V_10 ) ;
goto V_155;
}
static void F_319 ( struct V_311 * V_312 )
{
struct V_11 * V_39 =
F_12 ( V_312 , struct V_11 , V_353 ) ;
F_76 ( & V_18 ) ;
F_312 ( V_39 ) ;
F_79 ( & V_18 ) ;
F_91 ( V_39 ) ;
}
static void F_320 ( struct V_359 * V_360 )
{
struct V_11 * V_39 =
F_12 ( V_360 , struct V_11 , V_174 ) ;
F_305 ( & V_39 -> V_353 , F_319 ) ;
F_306 ( V_355 , & V_39 -> V_353 ) ;
}
static void F_211 ( struct V_11 * V_39 )
{
F_17 ( & V_18 ) ;
F_100 ( V_39 -> V_9 , 1 << V_39 -> V_16 -> V_8 ) ;
F_87 ( V_39 ) ;
F_321 ( & V_39 -> V_174 , F_320 ) ;
}
static int F_318 ( struct V_9 * V_10 )
__releases( &cgroup_mutex
static int F_322 ( struct V_117 * V_26 )
{
struct V_9 * V_10 ;
int V_6 = 0 ;
V_10 = F_96 ( V_26 ) ;
if ( ! V_10 )
return 0 ;
F_86 ( V_10 ) ;
V_6 = F_318 ( V_10 ) ;
F_93 ( V_26 ) ;
F_90 ( V_10 ) ;
return V_6 ;
}
static void T_8 F_323 ( struct V_15 * V_16 , bool V_377 )
{
struct V_11 * V_39 ;
F_324 ( V_378 L_39 , V_16 -> V_103 ) ;
F_76 ( & V_18 ) ;
F_134 ( & V_16 -> V_356 ) ;
F_53 ( & V_16 -> V_119 ) ;
V_16 -> V_19 = & V_93 ;
V_39 = V_16 -> V_365 ( F_13 ( & V_93 . V_10 , V_16 ) ) ;
F_47 ( F_139 ( V_39 ) ) ;
F_310 ( V_39 , V_16 , & V_93 . V_10 ) ;
V_39 -> V_22 |= V_379 ;
if ( V_377 ) {
V_39 -> V_8 = 1 ;
} else {
V_39 -> V_8 = F_1 ( & V_16 -> V_356 , V_39 , 1 , 2 , V_73 ) ;
F_47 ( V_39 -> V_8 < 0 ) ;
}
V_96 . V_17 [ V_16 -> V_8 ] = V_39 ;
V_380 |= V_16 -> V_381 || V_16 -> exit ;
F_47 ( ! F_35 ( & V_382 . V_78 ) ) ;
F_47 ( F_311 ( V_39 ) ) ;
F_79 ( & V_18 ) ;
}
int T_8 F_325 ( void )
{
static struct V_135 T_9 V_136 ;
struct V_15 * V_16 ;
int V_41 ;
F_133 ( & V_93 , & V_136 ) ;
V_93 . V_10 . V_13 . V_22 |= V_379 ;
F_106 ( V_382 . V_205 , & V_96 ) ;
F_29 (ss, i) {
F_203 ( ! V_16 -> V_365 || ! V_16 -> V_354 || V_16 -> V_103 || V_16 -> V_8 ,
L_40 ,
V_41 , V_383 [ V_41 ] , V_16 -> V_365 , V_16 -> V_354 ,
V_16 -> V_8 , V_16 -> V_103 ) ;
F_203 ( strlen ( V_383 [ V_41 ] ) > V_384 ,
L_41 , V_383 [ V_41 ] ) ;
V_16 -> V_8 = V_41 ;
V_16 -> V_103 = V_383 [ V_41 ] ;
if ( V_16 -> V_385 )
F_323 ( V_16 , true ) ;
}
return 0 ;
}
int T_8 F_326 ( void )
{
struct V_15 * V_16 ;
unsigned long V_40 ;
int V_48 , V_214 ;
F_47 ( F_237 ( NULL , V_180 ) ) ;
F_47 ( F_237 ( NULL , V_181 ) ) ;
F_76 ( & V_18 ) ;
V_40 = F_28 ( V_96 . V_17 ) ;
F_67 ( V_83 , & V_96 . V_51 , V_40 ) ;
F_47 ( F_135 ( & V_93 , 0 ) ) ;
F_79 ( & V_18 ) ;
F_29 (ss, ssid) {
if ( V_16 -> V_385 ) {
struct V_11 * V_39 =
V_96 . V_17 [ V_16 -> V_8 ] ;
V_39 -> V_8 = F_1 ( & V_16 -> V_356 , V_39 , 1 , 2 ,
V_73 ) ;
F_47 ( V_39 -> V_8 < 0 ) ;
} else {
F_323 ( V_16 , false ) ;
}
F_60 ( & V_96 . V_50 [ V_48 ] ,
& V_93 . V_10 . V_84 [ V_48 ] ) ;
if ( V_16 -> V_151 )
continue;
V_93 . V_20 |= 1 << V_16 -> V_8 ;
if ( V_289 && ! V_16 -> V_290 )
V_16 -> V_290 = V_16 -> V_291 ;
if ( ! V_16 -> V_290 )
V_124 |= 1 << V_16 -> V_8 ;
if ( V_16 -> V_290 == V_16 -> V_291 ) {
F_105 ( F_241 ( V_16 , V_16 -> V_290 ) ) ;
} else {
F_105 ( F_242 ( V_16 , V_16 -> V_290 ) ) ;
F_105 ( F_243 ( V_16 , V_16 -> V_291 ) ) ;
}
}
V_386 = F_327 ( L_42 , V_387 ) ;
if ( ! V_386 )
return - V_74 ;
V_214 = F_328 ( & V_336 ) ;
if ( V_214 < 0 ) {
F_329 ( V_386 ) ;
return V_214 ;
}
F_330 ( L_43 , 0 , NULL , & V_388 ) ;
return 0 ;
}
static int T_8 F_331 ( void )
{
V_355 = F_332 ( L_44 , 0 , 1 ) ;
F_47 ( ! V_355 ) ;
V_309 = F_332 ( L_45 ,
0 , 1 ) ;
F_47 ( ! V_309 ) ;
return 0 ;
}
int F_333 ( struct V_128 * V_258 , void * V_241 )
{
struct V_225 * V_225 ;
struct V_97 * V_203 ;
char * V_99 , * V_196 ;
int V_239 ;
struct V_69 * V_19 ;
V_239 = - V_74 ;
V_99 = F_262 ( V_149 , V_73 ) ;
if ( ! V_99 )
goto V_173;
V_239 = - V_228 ;
V_225 = V_258 -> V_347 ;
V_203 = F_334 ( V_225 , V_389 ) ;
if ( ! V_203 )
goto V_191;
V_239 = 0 ;
F_76 ( & V_18 ) ;
F_62 ( & V_35 ) ;
F_146 (root) {
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_48 , V_71 = 0 ;
if ( V_19 == & V_93 && ! V_125 )
continue;
F_112 ( V_258 , L_46 , V_19 -> V_89 ) ;
F_29 (ss, ssid)
if ( V_19 -> V_20 & ( 1 << V_48 ) )
F_112 ( V_258 , L_47 , V_71 ++ ? L_10 : L_24 , V_16 -> V_103 ) ;
if ( strlen ( V_19 -> V_103 ) )
F_112 ( V_258 , L_48 , V_71 ? L_10 : L_24 ,
V_19 -> V_103 ) ;
F_194 ( V_258 , ':' ) ;
V_10 = F_82 ( V_203 , V_19 ) ;
V_196 = F_159 ( V_10 , V_99 , V_149 ) ;
if ( ! V_196 ) {
V_239 = - V_390 ;
goto V_155;
}
F_113 ( V_258 , V_196 ) ;
F_194 ( V_258 , '\n' ) ;
}
V_155:
F_63 ( & V_35 ) ;
F_79 ( & V_18 ) ;
F_186 ( V_203 ) ;
V_191:
F_38 ( V_99 ) ;
V_173:
return V_239 ;
}
static int F_335 ( struct V_128 * V_258 , void * V_241 )
{
struct V_15 * V_16 ;
int V_41 ;
F_113 ( V_258 , L_49 ) ;
F_76 ( & V_18 ) ;
F_29 (ss, i)
F_112 ( V_258 , L_50 ,
V_16 -> V_103 , V_16 -> V_19 -> V_89 ,
F_77 ( & V_16 -> V_19 -> V_91 ) , ! V_16 -> V_151 ) ;
F_79 ( & V_18 ) ;
return 0 ;
}
static int F_336 ( struct V_391 * V_391 , struct V_392 * V_392 )
{
return F_337 ( V_392 , F_335 , NULL ) ;
}
void F_338 ( struct V_97 * V_251 )
{
F_106 ( V_251 -> V_205 , & V_96 ) ;
F_53 ( & V_251 -> V_162 ) ;
}
void F_339 ( struct V_97 * V_251 )
{
struct V_15 * V_16 ;
int V_41 ;
if ( V_160 ) {
struct V_42 * V_43 ;
F_42 ( & V_35 ) ;
V_43 = F_83 ( V_156 ) ;
if ( F_35 ( & V_251 -> V_162 ) ) {
F_107 ( V_251 -> V_205 , V_43 ) ;
F_55 ( & V_251 -> V_162 , & V_43 -> V_78 ) ;
F_44 ( V_43 ) ;
}
F_43 ( & V_35 ) ;
}
if ( V_380 ) {
F_29 (ss, i)
if ( V_16 -> V_381 )
V_16 -> V_381 ( V_251 ) ;
}
}
void F_340 ( struct V_97 * V_203 )
{
struct V_15 * V_16 ;
struct V_42 * V_43 ;
bool V_393 = false ;
int V_41 ;
if ( ! F_35 ( & V_203 -> V_162 ) ) {
F_42 ( & V_35 ) ;
F_166 ( & V_203 -> V_162 ) ;
F_43 ( & V_35 ) ;
V_393 = true ;
}
V_43 = F_83 ( V_203 ) ;
F_106 ( V_203 -> V_205 , & V_96 ) ;
if ( V_380 ) {
F_29 (ss, i) {
if ( V_16 -> exit ) {
struct V_11 * V_394 = V_43 -> V_17 [ V_41 ] ;
struct V_11 * V_39 = F_341 ( V_203 , V_41 ) ;
V_16 -> exit ( V_39 , V_394 , V_203 ) ;
}
}
}
if ( V_393 )
F_40 ( V_43 , true ) ;
}
static void F_37 ( struct V_9 * V_10 )
{
if ( F_23 ( V_10 ) && F_35 ( & V_10 -> V_55 ) &&
! F_154 ( & V_10 -> V_13 ) ) {
int V_395 = 0 ;
F_342 ( & V_396 ) ;
if ( ! F_18 ( V_10 ) &&
F_35 ( & V_10 -> V_167 ) ) {
F_55 ( & V_10 -> V_167 , & V_167 ) ;
V_395 = 1 ;
}
F_343 ( & V_396 ) ;
if ( V_395 )
F_344 ( & V_397 ) ;
}
}
static void F_345 ( struct V_311 * V_312 )
{
F_47 ( V_312 != & V_397 ) ;
F_76 ( & V_18 ) ;
F_342 ( & V_396 ) ;
while ( ! F_35 ( & V_167 ) ) {
char * V_398 [ 3 ] , * V_399 [ 3 ] ;
int V_41 ;
char * V_400 = NULL , * V_401 = NULL , * V_196 ;
struct V_9 * V_10 = F_48 ( V_167 . V_68 ,
struct V_9 ,
V_167 ) ;
F_166 ( & V_10 -> V_167 ) ;
F_343 ( & V_396 ) ;
V_400 = F_262 ( V_149 , V_73 ) ;
if ( ! V_400 )
goto V_402;
V_196 = F_159 ( V_10 , V_400 , V_149 ) ;
if ( ! V_196 )
goto V_402;
V_401 = F_346 ( V_10 -> V_19 -> V_132 , V_73 ) ;
if ( ! V_401 )
goto V_402;
V_41 = 0 ;
V_398 [ V_41 ++ ] = V_401 ;
V_398 [ V_41 ++ ] = V_196 ;
V_398 [ V_41 ] = NULL ;
V_41 = 0 ;
V_399 [ V_41 ++ ] = L_51 ;
V_399 [ V_41 ++ ] = L_52 ;
V_399 [ V_41 ] = NULL ;
F_79 ( & V_18 ) ;
F_347 ( V_398 [ 0 ] , V_398 , V_399 , V_403 ) ;
F_76 ( & V_18 ) ;
V_402:
F_38 ( V_400 ) ;
F_38 ( V_401 ) ;
F_342 ( & V_396 ) ;
}
F_343 ( & V_396 ) ;
F_79 ( & V_18 ) ;
}
static int T_8 F_348 ( char * V_404 )
{
struct V_15 * V_16 ;
char * V_137 ;
int V_41 ;
while ( ( V_137 = F_118 ( & V_404 , L_10 ) ) != NULL ) {
if ( ! * V_137 )
continue;
F_29 (ss, i) {
if ( ! strcmp ( V_137 , V_16 -> V_103 ) ) {
V_16 -> V_151 = 1 ;
F_324 ( V_378 L_53
L_54 , V_16 -> V_103 ) ;
break;
}
}
}
return 1 ;
}
static int T_8 F_349 ( char * V_404 )
{
F_324 ( L_55 ) ;
V_289 = true ;
return 0 ;
}
struct V_11 * F_350 ( struct V_184 * V_184 ,
struct V_15 * V_16 )
{
struct V_117 * V_26 = F_289 ( V_184 ) ;
struct V_11 * V_39 = NULL ;
struct V_9 * V_10 ;
if ( V_184 -> V_334 -> V_335 != & V_336 || ! V_26 ||
F_94 ( V_26 ) != V_118 )
return F_150 ( - V_405 ) ;
F_172 () ;
V_10 = F_290 ( V_26 -> V_27 ) ;
if ( V_10 )
V_39 = F_13 ( V_10 , V_16 ) ;
if ( ! V_39 || ! F_351 ( V_39 ) )
V_39 = F_150 ( - V_152 ) ;
F_179 () ;
return V_39 ;
}
struct V_11 * F_352 ( int V_8 , struct V_15 * V_16 )
{
F_73 ( ! F_353 () ) ;
return F_354 ( & V_16 -> V_356 , V_8 ) ;
}
static struct V_11 *
F_355 ( struct V_11 * V_12 )
{
struct V_11 * V_39 = F_54 ( sizeof( * V_39 ) , V_73 ) ;
if ( ! V_39 )
return F_150 ( - V_74 ) ;
return V_39 ;
}
static void F_356 ( struct V_11 * V_39 )
{
F_38 ( V_39 ) ;
}
static T_7 F_357 ( struct V_11 * V_39 ,
struct V_28 * V_29 )
{
return F_244 ( V_39 -> V_9 ) ;
}
static T_7 F_358 ( struct V_11 * V_39 ,
struct V_28 * V_29 )
{
return ( T_7 ) ( unsigned long ) V_156 -> V_205 ;
}
static T_7 F_359 ( struct V_11 * V_39 ,
struct V_28 * V_29 )
{
T_7 V_71 ;
F_172 () ;
V_71 = F_77 ( & F_83 ( V_156 ) -> V_49 ) ;
F_179 () ;
return V_71 ;
}
static int F_360 ( struct V_128 * V_129 , void * V_241 )
{
struct V_45 * V_46 ;
struct V_42 * V_43 ;
char * V_406 ;
V_406 = F_262 ( V_407 + 1 , V_73 ) ;
if ( ! V_406 )
return - V_74 ;
F_62 ( & V_35 ) ;
F_172 () ;
V_43 = F_290 ( V_156 -> V_205 ) ;
F_66 (link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_82 = V_46 -> V_10 ;
F_361 ( V_82 , V_406 , V_407 + 1 ) ;
F_112 ( V_129 , L_56 ,
V_82 -> V_19 -> V_89 , V_406 ) ;
}
F_179 () ;
F_63 ( & V_35 ) ;
F_38 ( V_406 ) ;
return 0 ;
}
static int F_362 ( struct V_128 * V_129 , void * V_241 )
{
struct V_11 * V_39 = F_193 ( V_129 ) ;
struct V_45 * V_46 ;
F_62 ( & V_35 ) ;
F_66 (link, &css->cgroup->cset_links, cset_link) {
struct V_42 * V_43 = V_46 -> V_43 ;
struct V_97 * V_98 ;
int V_71 = 0 ;
F_112 ( V_129 , L_57 , V_43 ) ;
F_66 (task, &cset->tasks, cg_list) {
if ( V_71 ++ > V_408 )
goto V_409;
F_112 ( V_129 , L_58 , F_286 ( V_98 ) ) ;
}
F_66 (task, &cset->mg_tasks, cg_list) {
if ( V_71 ++ > V_408 )
goto V_409;
F_112 ( V_129 , L_58 , F_286 ( V_98 ) ) ;
}
continue;
V_409:
F_113 ( V_129 , L_59 ) ;
}
F_63 ( & V_35 ) ;
return 0 ;
}
static T_7 F_363 ( struct V_11 * V_39 , struct V_28 * V_29 )
{
return F_25 ( V_32 , & V_39 -> V_9 -> V_22 ) ;
}
