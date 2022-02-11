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
return F_24 ( V_31 , & V_10 -> V_22 ) ;
}
static void F_25 ( struct V_9 * V_10 , bool V_32 )
{
F_17 ( & V_33 ) ;
do {
bool V_34 ;
if ( V_32 )
V_34 = ! V_10 -> V_35 ++ ;
else
V_34 = ! -- V_10 -> V_35 ;
if ( ! V_34 )
break;
if ( V_10 -> V_36 )
F_26 ( V_10 -> V_36 ) ;
V_10 = F_11 ( V_10 ) ;
} while ( V_10 );
}
static unsigned long F_27 ( struct V_11 * V_37 [] )
{
unsigned long V_38 = 0UL ;
struct V_15 * V_16 ;
int V_39 ;
F_28 (ss, i)
V_38 += ( unsigned long ) V_37 [ V_39 ] ;
V_38 = ( V_38 >> 16 ) ^ V_38 ;
return V_38 ;
}
static void F_29 ( struct V_40 * V_41 )
{
struct V_42 * V_43 , * V_44 ;
struct V_15 * V_16 ;
int V_45 ;
F_17 ( & V_33 ) ;
if ( ! F_30 ( & V_41 -> V_46 ) )
return;
F_28 (ss, ssid)
F_31 ( & V_41 -> V_47 [ V_45 ] ) ;
F_32 ( & V_41 -> V_48 ) ;
V_49 -- ;
F_33 (link, tmp_link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_10 = V_43 -> V_10 ;
F_31 ( & V_43 -> V_50 ) ;
F_31 ( & V_43 -> V_51 ) ;
if ( F_34 ( & V_10 -> V_52 ) ) {
F_25 ( V_10 , false ) ;
F_35 ( V_10 ) ;
}
F_36 ( V_43 ) ;
}
F_37 ( V_41 , V_53 ) ;
}
static void F_38 ( struct V_40 * V_41 )
{
if ( F_39 ( & V_41 -> V_46 , - 1 , 1 ) )
return;
F_40 ( & V_33 ) ;
F_29 ( V_41 ) ;
F_41 ( & V_33 ) ;
}
static inline void F_42 ( struct V_40 * V_41 )
{
F_43 ( & V_41 -> V_46 ) ;
}
static bool F_44 ( struct V_40 * V_41 ,
struct V_40 * V_54 ,
struct V_9 * V_55 ,
struct V_11 * V_56 [] )
{
struct V_57 * V_58 , * V_59 ;
if ( memcmp ( V_56 , V_41 -> V_17 , sizeof( V_41 -> V_17 ) ) )
return false ;
V_58 = & V_41 -> V_60 ;
V_59 = & V_54 -> V_60 ;
while ( 1 ) {
struct V_42 * V_61 , * V_62 ;
struct V_9 * V_63 , * V_64 ;
V_58 = V_58 -> V_65 ;
V_59 = V_59 -> V_65 ;
if ( V_58 == & V_41 -> V_60 ) {
F_45 ( V_59 != & V_54 -> V_60 ) ;
break;
} else {
F_45 ( V_59 == & V_54 -> V_60 ) ;
}
V_61 = F_46 ( V_58 , struct V_42 , V_51 ) ;
V_62 = F_46 ( V_59 , struct V_42 , V_51 ) ;
V_63 = V_61 -> V_10 ;
V_64 = V_62 -> V_10 ;
F_45 ( V_63 -> V_19 != V_64 -> V_19 ) ;
if ( V_63 -> V_19 == V_55 -> V_19 ) {
if ( V_63 != V_55 )
return false ;
} else {
if ( V_63 != V_64 )
return false ;
}
}
return true ;
}
static struct V_40 * F_47 ( struct V_40 * V_54 ,
struct V_9 * V_10 ,
struct V_11 * V_56 [] )
{
struct V_66 * V_19 = V_10 -> V_19 ;
struct V_15 * V_16 ;
struct V_40 * V_41 ;
unsigned long V_38 ;
int V_39 ;
F_28 (ss, i) {
if ( V_19 -> V_20 & ( 1UL << V_39 ) ) {
V_56 [ V_39 ] = F_16 ( V_10 , V_16 ) ;
} else {
V_56 [ V_39 ] = V_54 -> V_17 [ V_39 ] ;
}
}
V_38 = F_27 ( V_56 ) ;
F_48 (css_set_table, cset, hlist, key) {
if ( ! F_44 ( V_41 , V_54 , V_10 , V_56 ) )
continue;
return V_41 ;
}
return NULL ;
}
static void F_49 ( struct V_57 * V_67 )
{
struct V_42 * V_43 , * V_44 ;
F_33 (link, tmp_link, links_to_free, cset_link) {
F_31 ( & V_43 -> V_50 ) ;
F_36 ( V_43 ) ;
}
}
static int F_50 ( int V_68 , struct V_57 * V_69 )
{
struct V_42 * V_43 ;
int V_39 ;
F_51 ( V_69 ) ;
for ( V_39 = 0 ; V_39 < V_68 ; V_39 ++ ) {
V_43 = F_52 ( sizeof( * V_43 ) , V_70 ) ;
if ( ! V_43 ) {
F_49 ( V_69 ) ;
return - V_71 ;
}
F_53 ( & V_43 -> V_50 , V_69 ) ;
}
return 0 ;
}
static void F_54 ( struct V_57 * V_69 , struct V_40 * V_41 ,
struct V_9 * V_10 )
{
struct V_42 * V_43 ;
F_45 ( F_34 ( V_69 ) ) ;
if ( F_55 ( V_10 ) )
V_41 -> V_72 = V_10 ;
V_43 = F_56 ( V_69 , struct V_42 , V_50 ) ;
V_43 -> V_41 = V_41 ;
V_43 -> V_10 = V_10 ;
if ( F_34 ( & V_10 -> V_52 ) )
F_25 ( V_10 , true ) ;
F_57 ( & V_43 -> V_50 , & V_10 -> V_52 ) ;
F_58 ( & V_43 -> V_51 , & V_41 -> V_60 ) ;
}
static struct V_40 * F_59 ( struct V_40 * V_54 ,
struct V_9 * V_10 )
{
struct V_11 * V_56 [ V_73 ] = { } ;
struct V_40 * V_41 ;
struct V_57 V_69 ;
struct V_42 * V_43 ;
struct V_15 * V_16 ;
unsigned long V_38 ;
int V_45 ;
F_17 ( & V_18 ) ;
F_60 ( & V_33 ) ;
V_41 = F_47 ( V_54 , V_10 , V_56 ) ;
if ( V_41 )
F_42 ( V_41 ) ;
F_61 ( & V_33 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_52 ( sizeof( * V_41 ) , V_70 ) ;
if ( ! V_41 )
return NULL ;
if ( F_50 ( V_74 , & V_69 ) < 0 ) {
F_36 ( V_41 ) ;
return NULL ;
}
F_62 ( & V_41 -> V_46 , 1 ) ;
F_51 ( & V_41 -> V_60 ) ;
F_51 ( & V_41 -> V_75 ) ;
F_51 ( & V_41 -> V_76 ) ;
F_51 ( & V_41 -> V_77 ) ;
F_51 ( & V_41 -> V_78 ) ;
F_63 ( & V_41 -> V_48 ) ;
memcpy ( V_41 -> V_17 , V_56 , sizeof( V_41 -> V_17 ) ) ;
F_40 ( & V_33 ) ;
F_64 (link, &old_cset->cgrp_links, cgrp_link) {
struct V_9 * V_79 = V_43 -> V_10 ;
if ( V_79 -> V_19 == V_10 -> V_19 )
V_79 = V_10 ;
F_54 ( & V_69 , V_41 , V_79 ) ;
}
F_45 ( ! F_34 ( & V_69 ) ) ;
V_49 ++ ;
V_38 = F_27 ( V_41 -> V_17 ) ;
F_65 ( V_80 , & V_41 -> V_48 , V_38 ) ;
F_28 (ss, ssid)
F_58 ( & V_41 -> V_47 [ V_45 ] ,
& V_41 -> V_17 [ V_45 ] -> V_9 -> V_81 [ V_45 ] ) ;
F_41 ( & V_33 ) ;
return V_41 ;
}
static struct V_66 * F_66 ( struct V_82 * V_83 )
{
struct V_9 * V_84 = V_83 -> V_26 -> V_27 ;
return V_84 -> V_19 ;
}
static int F_67 ( struct V_66 * V_19 )
{
int V_8 ;
F_17 ( & V_18 ) ;
V_8 = F_68 ( & V_85 , V_19 , 0 , 0 , V_70 ) ;
if ( V_8 < 0 )
return V_8 ;
V_19 -> V_86 = V_8 ;
return 0 ;
}
static void F_69 ( struct V_66 * V_19 )
{
F_17 ( & V_18 ) ;
if ( V_19 -> V_86 ) {
F_10 ( & V_85 , V_19 -> V_86 ) ;
V_19 -> V_86 = 0 ;
}
}
static void F_70 ( struct V_66 * V_19 )
{
if ( V_19 ) {
F_71 ( V_19 -> V_86 ) ;
F_72 ( & V_19 -> V_87 ) ;
F_36 ( V_19 ) ;
}
}
static void F_73 ( struct V_66 * V_19 )
{
struct V_9 * V_10 = & V_19 -> V_10 ;
struct V_42 * V_43 , * V_44 ;
F_74 ( & V_18 ) ;
F_45 ( F_75 ( & V_19 -> V_88 ) ) ;
F_45 ( ! F_34 ( & V_10 -> V_13 . V_89 ) ) ;
F_76 ( & V_90 , V_19 -> V_20 ) ;
F_40 ( & V_33 ) ;
F_33 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_31 ( & V_43 -> V_50 ) ;
F_31 ( & V_43 -> V_51 ) ;
F_36 ( V_43 ) ;
}
F_41 ( & V_33 ) ;
if ( ! F_34 ( & V_19 -> V_91 ) ) {
F_31 ( & V_19 -> V_91 ) ;
V_74 -- ;
}
F_69 ( V_19 ) ;
F_77 ( & V_18 ) ;
F_78 ( V_19 -> V_83 ) ;
F_70 ( V_19 ) ;
}
static struct V_9 * F_79 ( struct V_40 * V_41 ,
struct V_66 * V_19 )
{
struct V_9 * V_92 = NULL ;
F_17 ( & V_18 ) ;
F_17 ( & V_33 ) ;
if ( V_41 == & V_93 ) {
V_92 = & V_19 -> V_10 ;
} else {
struct V_42 * V_43 ;
F_64 (link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_79 = V_43 -> V_10 ;
if ( V_79 -> V_19 == V_19 ) {
V_92 = V_79 ;
break;
}
}
}
F_45 ( ! V_92 ) ;
return V_92 ;
}
static struct V_9 * F_80 ( struct V_94 * V_95 ,
struct V_66 * V_19 )
{
return F_79 ( F_81 ( V_95 ) , V_19 ) ;
}
static char * F_82 ( struct V_9 * V_10 , const struct V_28 * V_29 ,
char * V_96 )
{
if ( V_29 -> V_16 && ! ( V_29 -> V_22 & V_97 ) &&
! ( V_10 -> V_19 -> V_22 & V_98 ) )
snprintf ( V_96 , V_99 , L_1 ,
V_29 -> V_16 -> V_100 , V_29 -> V_100 ) ;
else
strncpy ( V_96 , V_29 -> V_100 , V_99 ) ;
return V_96 ;
}
static T_2 F_83 ( const struct V_28 * V_29 )
{
T_2 V_101 = 0 ;
if ( V_29 -> V_101 )
return V_29 -> V_101 ;
if ( V_29 -> V_102 || V_29 -> V_103 || V_29 -> V_104 )
V_101 |= V_105 ;
if ( V_29 -> V_106 || V_29 -> V_107 || V_29 -> V_108 )
V_101 |= V_109 ;
return V_101 ;
}
static void F_84 ( struct V_9 * V_10 )
{
F_71 ( F_18 ( V_10 ) ) ;
F_85 ( & V_10 -> V_13 ) ;
}
static bool F_86 ( struct V_9 * V_10 )
{
return F_87 ( & V_10 -> V_13 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
F_89 ( & V_10 -> V_13 ) ;
}
static void F_90 ( struct V_9 * V_10 )
{
struct V_9 * V_14 = F_11 ( V_10 ) ;
unsigned int V_110 = V_10 -> V_111 ;
struct V_15 * V_16 ;
int V_45 ;
F_17 ( & V_18 ) ;
if ( ! F_55 ( V_10 ) ) {
V_10 -> V_21 = V_110 ;
return;
}
while ( true ) {
unsigned int V_112 = V_110 ;
F_28 (ss, ssid)
if ( V_110 & ( 1 << V_45 ) )
V_112 |= V_16 -> V_113 ;
if ( V_14 )
V_112 &= V_14 -> V_21 ;
else
V_112 &= V_10 -> V_19 -> V_20 ;
if ( V_112 == V_110 )
break;
V_110 = V_112 ;
}
V_10 -> V_21 = V_110 ;
}
static void F_91 ( struct V_114 * V_26 )
{
struct V_9 * V_10 ;
if ( F_92 ( V_26 ) == V_115 )
V_10 = V_26 -> V_27 ;
else
V_10 = V_26 -> V_14 -> V_27 ;
F_77 ( & V_18 ) ;
F_93 ( V_26 ) ;
F_88 ( V_10 ) ;
}
static struct V_9 * F_94 ( struct V_114 * V_26 )
{
struct V_9 * V_10 ;
if ( F_92 ( V_26 ) == V_115 )
V_10 = V_26 -> V_27 ;
else
V_10 = V_26 -> V_14 -> V_27 ;
if ( ! F_86 ( V_10 ) )
return NULL ;
F_95 ( V_26 ) ;
F_74 ( & V_18 ) ;
if ( ! F_18 ( V_10 ) )
return V_10 ;
F_91 ( V_26 ) ;
return NULL ;
}
static void F_96 ( struct V_9 * V_10 , const struct V_28 * V_29 )
{
char V_100 [ V_99 ] ;
F_17 ( & V_18 ) ;
F_97 ( V_10 -> V_26 , F_82 ( V_10 , V_29 , V_100 ) ) ;
}
static void F_98 ( struct V_9 * V_10 , unsigned int V_20 )
{
struct V_15 * V_16 ;
int V_39 ;
F_28 (ss, i) {
struct V_28 * V_116 ;
if ( ! ( V_20 & ( 1 << V_39 ) ) )
continue;
F_64 (cfts, &ss->cfts, node)
F_99 ( V_10 , V_116 , false ) ;
}
}
static int F_76 ( struct V_66 * V_117 , unsigned int V_118 )
{
struct V_15 * V_16 ;
unsigned int V_119 ;
int V_45 , V_39 , V_6 ;
F_17 ( & V_18 ) ;
F_28 (ss, ssid) {
if ( ! ( V_118 & ( 1 << V_45 ) ) )
continue;
if ( F_100 ( NULL , F_13 ( & V_16 -> V_19 -> V_10 , V_16 ) ) )
return - V_120 ;
if ( V_16 -> V_19 != & V_90 && V_117 != & V_90 )
return - V_120 ;
}
V_119 = V_118 ;
if ( V_117 == & V_90 )
V_119 &= ~ V_121 ;
V_6 = F_101 ( & V_117 -> V_10 , V_119 ) ;
if ( V_6 ) {
if ( V_117 != & V_90 )
return V_6 ;
if ( V_122 ) {
F_102 ( L_2 ,
V_6 , V_118 ) ;
F_102 ( L_3 ) ;
}
}
F_28 (ss, ssid)
if ( V_118 & ( 1 << V_45 ) )
F_98 ( & V_16 -> V_19 -> V_10 , 1 << V_45 ) ;
F_28 (ss, ssid) {
struct V_66 * V_123 ;
struct V_11 * V_37 ;
struct V_40 * V_41 ;
if ( ! ( V_118 & ( 1 << V_45 ) ) )
continue;
V_123 = V_16 -> V_19 ;
V_37 = F_13 ( & V_123 -> V_10 , V_16 ) ;
F_103 ( ! V_37 || F_13 ( & V_117 -> V_10 , V_16 ) ) ;
F_104 ( V_123 -> V_10 . V_17 [ V_45 ] , NULL ) ;
F_105 ( V_117 -> V_10 . V_17 [ V_45 ] , V_37 ) ;
V_16 -> V_19 = V_117 ;
V_37 -> V_9 = & V_117 -> V_10 ;
F_40 ( & V_33 ) ;
F_106 (css_set_table, i, cset, hlist)
F_107 ( & V_41 -> V_47 [ V_16 -> V_8 ] ,
& V_117 -> V_10 . V_81 [ V_16 -> V_8 ] ) ;
F_41 ( & V_33 ) ;
V_123 -> V_20 &= ~ ( 1 << V_45 ) ;
V_123 -> V_10 . V_111 &= ~ ( 1 << V_45 ) ;
F_90 ( & V_123 -> V_10 ) ;
V_117 -> V_20 |= 1 << V_45 ;
if ( V_117 != & V_90 ) {
V_117 -> V_10 . V_111 |= 1 << V_45 ;
F_90 ( & V_117 -> V_10 ) ;
}
if ( V_16 -> V_124 )
V_16 -> V_124 ( V_37 ) ;
}
F_108 ( V_117 -> V_10 . V_26 ) ;
return 0 ;
}
static int F_109 ( struct V_125 * V_126 ,
struct V_82 * V_83 )
{
struct V_66 * V_19 = F_66 ( V_83 ) ;
struct V_15 * V_16 ;
int V_45 ;
F_28 (ss, ssid)
if ( V_19 -> V_20 & ( 1 << V_45 ) )
F_110 ( V_126 , L_4 , V_16 -> V_100 ) ;
if ( V_19 -> V_22 & V_98 )
F_111 ( V_126 , L_5 ) ;
if ( V_19 -> V_22 & V_127 )
F_111 ( V_126 , L_6 ) ;
F_112 ( & V_128 ) ;
if ( strlen ( V_19 -> V_129 ) )
F_110 ( V_126 , L_7 , V_19 -> V_129 ) ;
F_113 ( & V_128 ) ;
if ( F_24 ( V_130 , & V_19 -> V_10 . V_22 ) )
F_111 ( V_126 , L_8 ) ;
if ( strlen ( V_19 -> V_100 ) )
F_110 ( V_126 , L_9 , V_19 -> V_100 ) ;
return 0 ;
}
static int F_114 ( char * V_131 , struct V_132 * V_133 )
{
char * V_134 , * V_135 = V_131 ;
bool V_136 = false , V_137 = false ;
unsigned int V_138 = - 1U ;
struct V_15 * V_16 ;
int V_139 = 0 ;
int V_39 ;
#ifdef F_115
V_138 = ~ ( 1U << V_140 ) ;
#endif
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
while ( ( V_134 = F_116 ( & V_135 , L_10 ) ) != NULL ) {
V_139 ++ ;
if ( ! * V_134 )
return - V_141 ;
if ( ! strcmp ( V_134 , L_11 ) ) {
V_133 -> V_142 = true ;
continue;
}
if ( ! strcmp ( V_134 , L_12 ) ) {
if ( V_137 )
return - V_141 ;
V_136 = true ;
continue;
}
if ( ! strcmp ( V_134 , L_13 ) ) {
V_133 -> V_22 |= V_143 ;
continue;
}
if ( ! strcmp ( V_134 , L_14 ) ) {
V_133 -> V_22 |= V_98 ;
continue;
}
if ( ! strcmp ( V_134 , L_15 ) ) {
V_133 -> V_144 = true ;
continue;
}
if ( ! strcmp ( V_134 , L_16 ) ) {
V_133 -> V_22 |= V_127 ;
continue;
}
if ( ! strncmp ( V_134 , L_17 , 14 ) ) {
if ( V_133 -> V_145 )
return - V_141 ;
V_133 -> V_145 =
F_117 ( V_134 + 14 , V_146 - 1 , V_70 ) ;
if ( ! V_133 -> V_145 )
return - V_71 ;
continue;
}
if ( ! strncmp ( V_134 , L_18 , 5 ) ) {
const char * V_100 = V_134 + 5 ;
if ( ! strlen ( V_100 ) )
return - V_141 ;
for ( V_39 = 0 ; V_39 < strlen ( V_100 ) ; V_39 ++ ) {
char V_79 = V_100 [ V_39 ] ;
if ( isalnum ( V_79 ) )
continue;
if ( ( V_79 == '.' ) || ( V_79 == '-' ) || ( V_79 == '_' ) )
continue;
return - V_141 ;
}
if ( V_133 -> V_100 )
return - V_141 ;
V_133 -> V_100 = F_117 ( V_100 ,
V_147 - 1 ,
V_70 ) ;
if ( ! V_133 -> V_100 )
return - V_71 ;
continue;
}
F_28 (ss, i) {
if ( strcmp ( V_134 , V_16 -> V_100 ) )
continue;
if ( V_16 -> V_148 )
continue;
if ( V_136 )
return - V_141 ;
V_133 -> V_20 |= ( 1 << V_39 ) ;
V_137 = true ;
break;
}
if ( V_39 == V_73 )
return - V_149 ;
}
if ( V_133 -> V_22 & V_143 ) {
F_102 ( L_19 ) ;
if ( V_139 != 1 ) {
F_118 ( L_20 ) ;
return - V_141 ;
}
return 0 ;
}
if ( V_136 || ( ! V_137 && ! V_133 -> V_142 && ! V_133 -> V_100 ) )
F_28 (ss, i)
if ( ! V_16 -> V_148 )
V_133 -> V_20 |= ( 1 << V_39 ) ;
if ( ! V_133 -> V_20 && ! V_133 -> V_100 )
return - V_141 ;
if ( ( V_133 -> V_22 & V_98 ) && ( V_133 -> V_20 & V_138 ) )
return - V_141 ;
if ( V_133 -> V_20 && V_133 -> V_142 )
return - V_141 ;
return 0 ;
}
static int F_119 ( struct V_82 * V_83 , int * V_22 , char * V_131 )
{
int V_6 = 0 ;
struct V_66 * V_19 = F_66 ( V_83 ) ;
struct V_132 V_133 ;
unsigned int V_150 , V_151 ;
if ( V_19 == & V_90 ) {
F_118 ( L_21 ) ;
return - V_141 ;
}
F_74 ( & V_18 ) ;
V_6 = F_114 ( V_131 , & V_133 ) ;
if ( V_6 )
goto V_152;
if ( V_133 . V_20 != V_19 -> V_20 || V_133 . V_145 )
F_102 ( L_22 ,
F_120 ( V_153 ) , V_153 -> V_154 ) ;
V_150 = V_133 . V_20 & ~ V_19 -> V_20 ;
V_151 = V_19 -> V_20 & ~ V_133 . V_20 ;
if ( ( V_133 . V_22 ^ V_19 -> V_22 ) ||
( V_133 . V_100 && strcmp ( V_133 . V_100 , V_19 -> V_100 ) ) ) {
F_118 ( L_23 ,
V_133 . V_22 , V_133 . V_100 ? : L_24 , V_19 -> V_22 , V_19 -> V_100 ) ;
V_6 = - V_141 ;
goto V_152;
}
if ( ! F_34 ( & V_19 -> V_10 . V_13 . V_89 ) ) {
V_6 = - V_120 ;
goto V_152;
}
V_6 = F_76 ( V_19 , V_150 ) ;
if ( V_6 )
goto V_152;
F_76 ( & V_90 , V_151 ) ;
if ( V_133 . V_145 ) {
F_112 ( & V_128 ) ;
strcpy ( V_19 -> V_129 , V_133 . V_145 ) ;
F_113 ( & V_128 ) ;
}
V_152:
F_36 ( V_133 . V_145 ) ;
F_36 ( V_133 . V_100 ) ;
F_77 ( & V_18 ) ;
return V_6 ;
}
static void F_121 ( void )
{
struct V_94 * V_155 , * V_156 ;
F_40 ( & V_33 ) ;
if ( V_157 )
goto V_152;
V_157 = true ;
F_122 ( & V_158 ) ;
F_123 (g, p) {
F_71 ( ! F_34 ( & V_155 -> V_159 ) ||
F_81 ( V_155 ) != & V_93 ) ;
F_124 ( & V_155 -> V_160 -> V_161 ) ;
if ( ! ( V_155 -> V_22 & V_162 ) ) {
struct V_40 * V_41 = F_81 ( V_155 ) ;
F_53 ( & V_155 -> V_159 , & V_41 -> V_75 ) ;
F_42 ( V_41 ) ;
}
F_125 ( & V_155 -> V_160 -> V_161 ) ;
} F_126 ( V_156 , V_155 ) ;
F_127 ( & V_158 ) ;
V_152:
F_41 ( & V_33 ) ;
}
static void F_128 ( struct V_9 * V_10 )
{
struct V_15 * V_16 ;
int V_45 ;
F_51 ( & V_10 -> V_13 . V_163 ) ;
F_51 ( & V_10 -> V_13 . V_89 ) ;
F_51 ( & V_10 -> V_52 ) ;
F_51 ( & V_10 -> V_164 ) ;
F_129 ( & V_10 -> V_165 ) ;
V_10 -> V_13 . V_9 = V_10 ;
V_10 -> V_13 . V_22 |= V_23 ;
F_28 (ss, ssid)
F_51 ( & V_10 -> V_81 [ V_45 ] ) ;
F_130 ( & V_10 -> V_166 ) ;
F_131 ( & V_10 -> V_167 , V_168 ) ;
}
static void F_132 ( struct V_66 * V_19 ,
struct V_132 * V_133 )
{
struct V_9 * V_10 = & V_19 -> V_10 ;
F_51 ( & V_19 -> V_91 ) ;
F_62 ( & V_19 -> V_88 , 1 ) ;
V_10 -> V_19 = V_19 ;
F_128 ( V_10 ) ;
F_133 ( & V_19 -> V_87 ) ;
V_19 -> V_22 = V_133 -> V_22 ;
if ( V_133 -> V_145 )
strcpy ( V_19 -> V_129 , V_133 -> V_145 ) ;
if ( V_133 -> V_100 )
strcpy ( V_19 -> V_100 , V_133 -> V_100 ) ;
if ( V_133 -> V_144 )
F_134 ( V_130 , & V_19 -> V_10 . V_22 ) ;
}
static int F_135 ( struct V_66 * V_19 , unsigned int V_118 )
{
F_136 ( V_69 ) ;
struct V_9 * V_84 = & V_19 -> V_10 ;
struct V_28 * V_169 ;
struct V_40 * V_41 ;
int V_39 , V_6 ;
F_17 ( & V_18 ) ;
V_6 = F_1 ( & V_19 -> V_87 , V_84 , 1 , 2 , V_170 ) ;
if ( V_6 < 0 )
goto V_171;
V_84 -> V_8 = V_6 ;
V_6 = F_137 ( & V_84 -> V_13 . V_172 , V_173 , 0 ,
V_70 ) ;
if ( V_6 )
goto V_171;
V_6 = F_50 ( V_49 , & V_69 ) ;
if ( V_6 )
goto V_174;
V_6 = F_67 ( V_19 ) ;
if ( V_6 )
goto V_174;
V_19 -> V_83 = F_138 ( & V_175 ,
V_176 ,
V_84 ) ;
if ( F_139 ( V_19 -> V_83 ) ) {
V_6 = F_140 ( V_19 -> V_83 ) ;
goto V_177;
}
V_84 -> V_26 = V_19 -> V_83 -> V_26 ;
if ( V_19 == & V_90 )
V_169 = V_178 ;
else
V_169 = V_179 ;
V_6 = F_99 ( V_84 , V_169 , true ) ;
if ( V_6 )
goto V_180;
V_6 = F_76 ( V_19 , V_118 ) ;
if ( V_6 )
goto V_180;
F_53 ( & V_19 -> V_91 , & V_181 ) ;
V_74 ++ ;
F_40 ( & V_33 ) ;
F_106 (css_set_table, i, cset, hlist)
F_54 ( & V_69 , V_41 , V_84 ) ;
F_41 ( & V_33 ) ;
F_45 ( ! F_34 ( & V_84 -> V_13 . V_89 ) ) ;
F_45 ( F_75 ( & V_19 -> V_88 ) != 1 ) ;
F_108 ( V_84 -> V_26 ) ;
V_6 = 0 ;
goto V_171;
V_180:
F_78 ( V_19 -> V_83 ) ;
V_19 -> V_83 = NULL ;
V_177:
F_69 ( V_19 ) ;
V_174:
F_141 ( & V_84 -> V_13 . V_172 ) ;
V_171:
F_49 ( & V_69 ) ;
return V_6 ;
}
static struct V_182 * F_142 ( struct V_183 * V_184 ,
int V_22 , const char * V_185 ,
void * V_131 )
{
struct V_186 * V_187 = NULL ;
struct V_15 * V_16 ;
struct V_66 * V_19 ;
struct V_132 V_133 ;
struct V_182 * V_182 ;
int V_6 ;
int V_39 ;
bool V_188 ;
if ( ! V_157 )
F_121 () ;
F_74 ( & V_18 ) ;
V_6 = F_114 ( V_131 , & V_133 ) ;
if ( V_6 )
goto V_152;
if ( V_133 . V_22 & V_143 ) {
V_122 = true ;
V_19 = & V_90 ;
F_84 ( & V_19 -> V_10 ) ;
V_6 = 0 ;
goto V_152;
}
F_28 (ss, i) {
if ( ! ( V_133 . V_20 & ( 1 << V_39 ) ) ||
V_16 -> V_19 == & V_90 )
continue;
if ( ! F_143 ( & V_16 -> V_19 -> V_10 . V_13 . V_172 ) ) {
F_77 ( & V_18 ) ;
F_144 ( 10 ) ;
V_6 = F_145 () ;
goto V_189;
}
F_88 ( & V_16 -> V_19 -> V_10 ) ;
}
F_146 (root) {
bool V_190 = false ;
if ( V_19 == & V_90 )
continue;
if ( V_133 . V_100 ) {
if ( strcmp ( V_133 . V_100 , V_19 -> V_100 ) )
continue;
V_190 = true ;
}
if ( ( V_133 . V_20 || V_133 . V_142 ) &&
( V_133 . V_20 != V_19 -> V_20 ) ) {
if ( ! V_190 )
continue;
V_6 = - V_120 ;
goto V_152;
}
if ( V_19 -> V_22 ^ V_133 . V_22 )
F_102 ( L_25 ) ;
V_187 = F_147 ( V_19 -> V_83 , NULL ) ;
if ( F_139 ( V_187 ) ||
! F_143 ( & V_19 -> V_10 . V_13 . V_172 ) ) {
F_77 ( & V_18 ) ;
if ( ! F_148 ( V_187 ) )
F_149 ( V_187 ) ;
F_144 ( 10 ) ;
V_6 = F_145 () ;
goto V_189;
}
V_6 = 0 ;
goto V_152;
}
if ( ! V_133 . V_20 && ! V_133 . V_142 ) {
V_6 = - V_141 ;
goto V_152;
}
V_19 = F_52 ( sizeof( * V_19 ) , V_70 ) ;
if ( ! V_19 ) {
V_6 = - V_71 ;
goto V_152;
}
F_132 ( V_19 , & V_133 ) ;
V_6 = F_135 ( V_19 , V_133 . V_20 ) ;
if ( V_6 )
F_70 ( V_19 ) ;
V_152:
F_77 ( & V_18 ) ;
V_189:
F_36 ( V_133 . V_145 ) ;
F_36 ( V_133 . V_100 ) ;
if ( V_6 )
return F_150 ( V_6 ) ;
V_182 = F_151 ( V_184 , V_22 , V_19 -> V_83 ,
V_191 , & V_188 ) ;
if ( F_139 ( V_182 ) || ! V_188 )
F_88 ( & V_19 -> V_10 ) ;
if ( V_187 ) {
F_103 ( V_188 ) ;
F_149 ( V_187 ) ;
}
return V_182 ;
}
static void F_152 ( struct V_186 * V_192 )
{
struct V_82 * V_83 = F_153 ( V_192 ) ;
struct V_66 * V_19 = F_66 ( V_83 ) ;
if ( F_154 ( & V_19 -> V_10 . V_13 ) ||
V_19 == & V_90 )
F_88 ( & V_19 -> V_10 ) ;
else
F_155 ( & V_19 -> V_10 . V_13 . V_172 ) ;
F_156 ( V_192 ) ;
}
char * F_157 ( struct V_94 * V_95 , char * V_96 , T_3 V_193 )
{
struct V_66 * V_19 ;
struct V_9 * V_10 ;
int V_86 = 1 ;
char * V_194 = NULL ;
F_74 ( & V_18 ) ;
F_60 ( & V_33 ) ;
V_19 = F_158 ( & V_85 , & V_86 ) ;
if ( V_19 ) {
V_10 = F_80 ( V_95 , V_19 ) ;
V_194 = F_159 ( V_10 , V_96 , V_193 ) ;
} else {
if ( F_160 ( V_96 , L_26 , V_193 ) < V_193 )
V_194 = V_96 ;
}
F_61 ( & V_33 ) ;
F_77 ( & V_18 ) ;
return V_194 ;
}
struct V_94 * F_161 ( struct V_195 * V_196 )
{
V_196 -> V_197 = F_56 ( V_196 -> V_198 , struct V_40 , V_78 ) ;
V_196 -> V_199 = NULL ;
return F_162 ( V_196 ) ;
}
struct V_94 * F_162 ( struct V_195 * V_196 )
{
struct V_40 * V_41 = V_196 -> V_197 ;
struct V_94 * V_95 = V_196 -> V_199 ;
while ( & V_41 -> V_78 != V_196 -> V_198 ) {
if ( ! V_95 )
V_95 = F_56 ( & V_41 -> V_76 ,
struct V_94 , V_159 ) ;
else
V_95 = F_163 ( V_95 , V_159 ) ;
if ( & V_95 -> V_159 != & V_41 -> V_76 ) {
V_196 -> V_197 = V_41 ;
V_196 -> V_199 = V_95 ;
return V_95 ;
}
V_41 = F_163 ( V_41 , V_78 ) ;
V_95 = NULL ;
}
return NULL ;
}
static void F_164 ( struct V_9 * V_200 ,
struct V_94 * V_201 ,
struct V_40 * V_202 )
{
struct V_40 * V_54 ;
F_17 ( & V_18 ) ;
F_17 ( & V_33 ) ;
F_71 ( V_201 -> V_22 & V_162 ) ;
V_54 = F_81 ( V_201 ) ;
F_42 ( V_202 ) ;
F_105 ( V_201 -> V_203 , V_202 ) ;
F_107 ( & V_201 -> V_159 , & V_202 -> V_76 ) ;
F_29 ( V_54 ) ;
}
static void F_165 ( struct V_57 * V_204 )
{
struct V_40 * V_41 , * V_205 ;
F_17 ( & V_18 ) ;
F_40 ( & V_33 ) ;
F_33 (cset, tmp_cset, preloaded_csets, mg_preload_node) {
V_41 -> V_206 = NULL ;
V_41 -> V_207 = NULL ;
F_166 ( & V_41 -> V_77 ) ;
F_29 ( V_41 ) ;
}
F_41 ( & V_33 ) ;
}
static void F_167 ( struct V_40 * V_208 ,
struct V_9 * V_209 ,
struct V_57 * V_204 )
{
struct V_9 * V_210 ;
F_17 ( & V_18 ) ;
F_17 ( & V_33 ) ;
V_210 = F_79 ( V_208 , V_209 -> V_19 ) ;
if ( ! F_34 ( & V_208 -> V_77 ) )
return;
F_103 ( V_208 -> V_206 ) ;
F_103 ( ! F_34 ( & V_208 -> V_76 ) ) ;
F_103 ( ! F_34 ( & V_208 -> V_78 ) ) ;
V_208 -> V_206 = V_210 ;
F_42 ( V_208 ) ;
F_53 ( & V_208 -> V_77 , V_204 ) ;
}
static int F_168 ( struct V_9 * V_209 ,
struct V_57 * V_204 )
{
F_136 ( V_198 ) ;
struct V_40 * V_208 , * V_205 ;
F_17 ( & V_18 ) ;
if ( V_209 && F_55 ( V_209 ) && F_11 ( V_209 ) &&
V_209 -> V_21 )
return - V_120 ;
F_33 (src_cset, tmp_cset, preloaded_csets, mg_preload_node) {
struct V_40 * V_211 ;
V_211 = F_59 ( V_208 ,
V_209 ? : V_208 -> V_72 ) ;
if ( ! V_211 )
goto V_212;
F_71 ( V_208 -> V_207 || V_211 -> V_207 ) ;
if ( V_208 == V_211 ) {
V_208 -> V_206 = NULL ;
F_166 ( & V_208 -> V_77 ) ;
F_38 ( V_208 ) ;
F_38 ( V_211 ) ;
continue;
}
V_208 -> V_207 = V_211 ;
if ( F_34 ( & V_211 -> V_77 ) )
F_53 ( & V_211 -> V_77 , & V_198 ) ;
else
F_38 ( V_211 ) ;
}
F_169 ( & V_198 , V_204 ) ;
return 0 ;
V_212:
F_165 ( & V_198 ) ;
return - V_71 ;
}
static int F_170 ( struct V_9 * V_10 , struct V_94 * V_213 ,
bool V_214 )
{
struct V_195 V_196 = {
. V_215 = F_171 ( V_196 . V_215 ) ,
. V_216 = F_171 ( V_196 . V_216 ) ,
. V_198 = & V_196 . V_215 ,
} ;
struct V_11 * V_37 , * V_217 = NULL ;
struct V_40 * V_41 , * V_205 ;
struct V_94 * V_95 , * V_218 ;
int V_39 , V_6 ;
F_40 ( & V_33 ) ;
F_172 () ;
V_95 = V_213 ;
do {
if ( V_95 -> V_22 & V_162 )
goto V_65;
if ( F_34 ( & V_95 -> V_159 ) )
goto V_65;
V_41 = F_81 ( V_95 ) ;
if ( ! V_41 -> V_206 )
goto V_65;
F_107 ( & V_95 -> V_159 , & V_41 -> V_76 ) ;
if ( F_34 ( & V_41 -> V_78 ) )
F_58 ( & V_41 -> V_78 , & V_196 . V_215 ) ;
if ( F_34 ( & V_41 -> V_207 -> V_78 ) )
F_107 ( & V_41 -> V_207 -> V_78 ,
& V_196 . V_216 ) ;
V_65:
if ( ! V_214 )
break;
} while_each_thread(leader, task) ;
int F_173 ( struct V_9 * V_209 ,
struct V_94 * V_213 , bool V_214 )
{
F_136 ( V_204 ) ;
struct V_94 * V_95 ;
int V_6 ;
F_60 ( & V_33 ) ;
F_172 () ;
V_95 = V_213 ;
do {
F_167 ( F_81 ( V_95 ) , V_209 ,
& V_204 ) ;
if ( ! V_214 )
break;
} while_each_thread(leader, task) ;
T_4 F_174 ( struct V_24 * V_25 , char * V_96 ,
T_3 V_219 , T_5 V_220 , bool V_214 )
{
struct V_94 * V_201 ;
const struct V_221 * V_221 = F_175 () , * V_222 ;
struct V_9 * V_10 ;
T_6 V_223 ;
int V_6 ;
if ( F_176 ( F_177 ( V_96 ) , 0 , & V_223 ) || V_223 < 0 )
return - V_141 ;
V_10 = F_94 ( V_25 -> V_26 ) ;
if ( ! V_10 )
return - V_224 ;
V_225:
F_172 () ;
if ( V_223 ) {
V_201 = F_178 ( V_223 ) ;
if ( ! V_201 ) {
F_179 () ;
V_6 = - V_226 ;
goto V_227;
}
V_222 = F_180 ( V_201 ) ;
if ( ! F_181 ( V_221 -> V_228 , V_229 ) &&
! F_181 ( V_221 -> V_228 , V_222 -> V_230 ) &&
! F_181 ( V_221 -> V_228 , V_222 -> V_231 ) ) {
F_179 () ;
V_6 = - V_232 ;
goto V_227;
}
} else
V_201 = V_153 ;
if ( V_214 )
V_201 = V_201 -> V_233 ;
if ( V_201 == V_234 || ( V_201 -> V_22 & V_235 ) ) {
V_6 = - V_141 ;
F_179 () ;
goto V_227;
}
F_182 ( V_201 ) ;
F_179 () ;
F_183 ( V_201 ) ;
if ( V_214 ) {
if ( ! F_184 ( V_201 ) ) {
F_185 ( V_201 ) ;
F_186 ( V_201 ) ;
goto V_225;
}
}
V_6 = F_173 ( V_10 , V_201 , V_214 ) ;
F_185 ( V_201 ) ;
F_186 ( V_201 ) ;
V_227:
F_91 ( V_25 -> V_26 ) ;
return V_6 ? : V_219 ;
}
int F_187 ( struct V_94 * V_236 , struct V_94 * V_201 )
{
struct V_66 * V_19 ;
int V_237 = 0 ;
F_74 ( & V_18 ) ;
F_146 (root) {
struct V_9 * V_238 ;
if ( V_19 == & V_90 )
continue;
F_60 ( & V_33 ) ;
V_238 = F_80 ( V_236 , V_19 ) ;
F_61 ( & V_33 ) ;
V_237 = F_173 ( V_238 , V_201 , false ) ;
if ( V_237 )
break;
}
F_77 ( & V_18 ) ;
return V_237 ;
}
static T_4 F_188 ( struct V_24 * V_25 ,
char * V_96 , T_3 V_219 , T_5 V_220 )
{
return F_174 ( V_25 , V_96 , V_219 , V_220 , false ) ;
}
static T_4 F_189 ( struct V_24 * V_25 ,
char * V_96 , T_3 V_219 , T_5 V_220 )
{
return F_174 ( V_25 , V_96 , V_219 , V_220 , true ) ;
}
static T_4 F_190 ( struct V_24 * V_25 ,
char * V_96 , T_3 V_219 , T_5 V_220 )
{
struct V_9 * V_10 ;
F_191 ( sizeof( V_10 -> V_19 -> V_129 ) < V_146 ) ;
V_10 = F_94 ( V_25 -> V_26 ) ;
if ( ! V_10 )
return - V_224 ;
F_112 ( & V_128 ) ;
F_160 ( V_10 -> V_19 -> V_129 , F_177 ( V_96 ) ,
sizeof( V_10 -> V_19 -> V_129 ) ) ;
F_113 ( & V_128 ) ;
F_91 ( V_25 -> V_26 ) ;
return V_219 ;
}
static int F_192 ( struct V_125 * V_126 , void * V_239 )
{
struct V_9 * V_10 = F_193 ( V_126 ) -> V_9 ;
F_112 ( & V_128 ) ;
F_111 ( V_126 , V_10 -> V_19 -> V_129 ) ;
F_113 ( & V_128 ) ;
F_194 ( V_126 , '\n' ) ;
return 0 ;
}
static int F_195 ( struct V_125 * V_126 , void * V_239 )
{
F_111 ( V_126 , L_27 ) ;
return 0 ;
}
static void F_196 ( struct V_125 * V_126 , unsigned int V_118 )
{
struct V_15 * V_16 ;
bool V_240 = false ;
int V_45 ;
F_28 (ss, ssid) {
if ( V_118 & ( 1 << V_45 ) ) {
if ( V_240 )
F_194 ( V_126 , ' ' ) ;
F_110 ( V_126 , L_28 , V_16 -> V_100 ) ;
V_240 = true ;
}
}
if ( V_240 )
F_194 ( V_126 , '\n' ) ;
}
static int F_197 ( struct V_125 * V_126 , void * V_239 )
{
struct V_9 * V_10 = F_193 ( V_126 ) -> V_9 ;
F_196 ( V_126 , V_10 -> V_19 -> V_20 &
~ V_121 ) ;
return 0 ;
}
static int F_198 ( struct V_125 * V_126 , void * V_239 )
{
struct V_9 * V_10 = F_193 ( V_126 ) -> V_9 ;
F_196 ( V_126 , F_11 ( V_10 ) -> V_111 ) ;
return 0 ;
}
static int F_199 ( struct V_125 * V_126 , void * V_239 )
{
struct V_9 * V_10 = F_193 ( V_126 ) -> V_9 ;
F_196 ( V_126 , V_10 -> V_111 ) ;
return 0 ;
}
static int F_200 ( struct V_9 * V_10 )
{
F_136 ( V_204 ) ;
struct V_11 * V_37 ;
struct V_40 * V_208 ;
int V_6 ;
F_17 ( & V_18 ) ;
F_60 ( & V_33 ) ;
F_201 (css, cgroup_css(cgrp, NULL)) {
struct V_42 * V_43 ;
if ( V_37 -> V_9 == V_10 )
continue;
F_64 (link, &css->cgroup->cset_links, cset_link)
F_167 ( V_43 -> V_41 , V_10 ,
& V_204 ) ;
}
F_61 ( & V_33 ) ;
V_6 = F_168 ( NULL , & V_204 ) ;
if ( V_6 )
goto V_241;
F_64 (src_cset, &preloaded_csets, mg_preload_node) {
struct V_94 * V_242 = NULL , * V_95 ;
if ( ! V_208 -> V_206 )
break;
while ( true ) {
F_60 ( & V_33 ) ;
V_95 = F_202 ( & V_208 -> V_75 ,
struct V_94 , V_159 ) ;
if ( V_95 ) {
V_95 = V_95 -> V_233 ;
F_71 ( ! F_81 ( V_95 ) -> V_206 ) ;
F_182 ( V_95 ) ;
}
F_61 ( & V_33 ) ;
if ( ! V_95 )
break;
if ( F_203 ( V_242 == V_95 ,
L_29 ) )
goto V_241;
V_242 = V_95 ;
F_183 ( V_95 ) ;
if ( ! F_184 ( V_95 ) ) {
F_185 ( V_95 ) ;
F_186 ( V_95 ) ;
continue;
}
V_6 = F_170 ( V_208 -> V_72 , V_95 , true ) ;
F_185 ( V_95 ) ;
F_186 ( V_95 ) ;
if ( F_203 ( V_6 , L_30 , V_6 ) )
goto V_241;
}
}
V_241:
F_165 ( & V_204 ) ;
return V_6 ;
}
static T_4 F_204 ( struct V_24 * V_25 ,
char * V_96 , T_3 V_219 ,
T_5 V_220 )
{
unsigned int V_243 = 0 , V_244 = 0 ;
unsigned int V_245 , V_246 , V_247 , V_248 ;
struct V_9 * V_10 , * V_249 ;
struct V_15 * V_16 ;
char * V_250 ;
int V_45 , V_6 ;
V_96 = F_177 ( V_96 ) ;
while ( ( V_250 = F_116 ( & V_96 , L_31 ) ) ) {
if ( V_250 [ 0 ] == '\0' )
continue;
F_28 (ss, ssid) {
if ( V_16 -> V_148 || strcmp ( V_250 + 1 , V_16 -> V_100 ) ||
( ( 1 << V_16 -> V_8 ) & V_121 ) )
continue;
if ( * V_250 == '+' ) {
V_243 |= 1 << V_45 ;
V_244 &= ~ ( 1 << V_45 ) ;
} else if ( * V_250 == '-' ) {
V_244 |= 1 << V_45 ;
V_243 &= ~ ( 1 << V_45 ) ;
} else {
return - V_141 ;
}
break;
}
if ( V_45 == V_73 )
return - V_141 ;
}
V_10 = F_94 ( V_25 -> V_26 ) ;
if ( ! V_10 )
return - V_224 ;
F_28 (ss, ssid) {
if ( V_243 & ( 1 << V_45 ) ) {
if ( V_10 -> V_111 & ( 1 << V_45 ) ) {
V_243 &= ~ ( 1 << V_45 ) ;
continue;
}
if ( ! ( V_90 . V_20 & ( 1 << V_45 ) ) ||
( F_11 ( V_10 ) &&
! ( F_11 ( V_10 ) -> V_111 & ( 1 << V_45 ) ) ) ) {
V_6 = - V_149 ;
goto V_152;
}
if ( V_10 -> V_21 & ( 1 << V_45 ) )
continue;
F_205 (child, cgrp) {
F_206 ( V_251 ) ;
if ( ! F_13 ( V_249 , V_16 ) )
continue;
F_84 ( V_249 ) ;
F_207 ( & V_249 -> V_166 , & V_251 ,
V_252 ) ;
F_91 ( V_25 -> V_26 ) ;
F_208 () ;
F_209 ( & V_249 -> V_166 , & V_251 ) ;
F_88 ( V_249 ) ;
return F_145 () ;
}
} else if ( V_244 & ( 1 << V_45 ) ) {
if ( ! ( V_10 -> V_111 & ( 1 << V_45 ) ) ) {
V_244 &= ~ ( 1 << V_45 ) ;
continue;
}
F_205 (child, cgrp) {
if ( V_249 -> V_111 & ( 1 << V_45 ) ) {
V_6 = - V_120 ;
goto V_152;
}
}
}
}
if ( ! V_243 && ! V_244 ) {
V_6 = 0 ;
goto V_152;
}
if ( V_243 && F_11 ( V_10 ) && ! F_34 ( & V_10 -> V_52 ) ) {
V_6 = - V_120 ;
goto V_152;
}
V_10 -> V_111 |= V_243 ;
V_10 -> V_111 &= ~ V_244 ;
V_247 = V_10 -> V_21 ;
F_90 ( V_10 ) ;
V_248 = V_10 -> V_21 ;
V_245 = ~ V_247 & V_248 ;
V_246 = V_247 & ~ V_248 ;
V_243 |= V_245 ;
V_244 |= V_246 ;
F_28 (ss, ssid) {
if ( ! ( V_243 & ( 1 << V_45 ) ) )
continue;
F_205 (child, cgrp) {
if ( V_245 & ( 1 << V_45 ) )
V_6 = F_210 ( V_249 , V_16 ,
V_10 -> V_111 & ( 1 << V_45 ) ) ;
else
V_6 = F_101 ( V_249 , 1 << V_45 ) ;
if ( V_6 )
goto V_253;
}
}
V_6 = F_200 ( V_10 ) ;
if ( V_6 )
goto V_253;
F_28 (ss, ssid) {
if ( ! ( V_244 & ( 1 << V_45 ) ) )
continue;
F_205 (child, cgrp) {
struct V_11 * V_37 = F_13 ( V_249 , V_16 ) ;
if ( V_246 & ( 1 << V_45 ) ) {
F_211 ( V_37 ) ;
} else {
F_98 ( V_249 , 1 << V_45 ) ;
if ( V_16 -> V_254 )
V_16 -> V_254 ( V_37 ) ;
}
}
}
F_108 ( V_10 -> V_26 ) ;
V_6 = 0 ;
V_152:
F_91 ( V_25 -> V_26 ) ;
return V_6 ? : V_219 ;
V_253:
V_10 -> V_111 &= ~ V_243 ;
V_10 -> V_111 |= V_244 ;
F_90 ( V_10 ) ;
F_28 (ss, ssid) {
if ( ! ( V_243 & ( 1 << V_45 ) ) )
continue;
F_205 (child, cgrp) {
struct V_11 * V_37 = F_13 ( V_249 , V_16 ) ;
if ( ! V_37 )
continue;
if ( V_245 & ( 1 << V_45 ) )
F_211 ( V_37 ) ;
else
F_98 ( V_249 , 1 << V_45 ) ;
}
}
goto V_152;
}
static int F_212 ( struct V_125 * V_126 , void * V_239 )
{
F_110 ( V_126 , L_32 , ( bool ) F_193 ( V_126 ) -> V_9 -> V_35 ) ;
return 0 ;
}
static T_4 F_213 ( struct V_24 * V_25 , char * V_96 ,
T_3 V_219 , T_5 V_220 )
{
struct V_9 * V_10 = V_25 -> V_26 -> V_14 -> V_27 ;
struct V_28 * V_29 = V_25 -> V_26 -> V_27 ;
struct V_11 * V_37 ;
int V_6 ;
if ( V_29 -> V_108 )
return V_29 -> V_108 ( V_25 , V_96 , V_219 , V_220 ) ;
F_172 () ;
V_37 = F_13 ( V_10 , V_29 -> V_16 ) ;
F_179 () ;
if ( V_29 -> V_106 ) {
unsigned long long V_239 ;
V_6 = F_214 ( V_96 , 0 , & V_239 ) ;
if ( ! V_6 )
V_6 = V_29 -> V_106 ( V_37 , V_29 , V_239 ) ;
} else if ( V_29 -> V_107 ) {
long long V_239 ;
V_6 = F_215 ( V_96 , 0 , & V_239 ) ;
if ( ! V_6 )
V_6 = V_29 -> V_107 ( V_37 , V_29 , V_239 ) ;
} else {
V_6 = - V_141 ;
}
return V_6 ? : V_219 ;
}
static void * F_216 ( struct V_125 * V_126 , T_5 * V_255 )
{
return F_217 ( V_126 ) -> F_218 ( V_126 , V_255 ) ;
}
static void * F_219 ( struct V_125 * V_126 , void * V_239 , T_5 * V_255 )
{
return F_217 ( V_126 ) -> F_220 ( V_126 , V_239 , V_255 ) ;
}
static void F_221 ( struct V_125 * V_126 , void * V_239 )
{
F_217 ( V_126 ) -> F_222 ( V_126 , V_239 ) ;
}
static int F_223 ( struct V_125 * V_256 , void * V_257 )
{
struct V_28 * V_29 = F_217 ( V_256 ) ;
struct V_11 * V_37 = F_193 ( V_256 ) ;
if ( V_29 -> V_104 )
return V_29 -> V_104 ( V_256 , V_257 ) ;
if ( V_29 -> V_102 )
F_110 ( V_256 , L_33 , V_29 -> V_102 ( V_37 , V_29 ) ) ;
else if ( V_29 -> V_103 )
F_110 ( V_256 , L_34 , V_29 -> V_103 ( V_37 , V_29 ) ) ;
else
return - V_141 ;
return 0 ;
}
static int F_224 ( struct V_114 * V_26 , struct V_114 * V_258 ,
const char * V_259 )
{
struct V_9 * V_10 = V_26 -> V_27 ;
int V_6 ;
if ( F_92 ( V_26 ) != V_115 )
return - V_260 ;
if ( V_26 -> V_14 != V_258 )
return - V_261 ;
if ( F_55 ( V_10 ) )
return - V_262 ;
F_95 ( V_258 ) ;
F_95 ( V_26 ) ;
F_74 ( & V_18 ) ;
V_6 = F_225 ( V_26 , V_258 , V_259 ) ;
F_77 ( & V_18 ) ;
F_93 ( V_26 ) ;
F_93 ( V_258 ) ;
return V_6 ;
}
static int F_226 ( struct V_114 * V_26 )
{
struct V_263 V_263 = { . V_264 = V_265 | V_266 ,
. V_267 = F_227 () ,
. V_268 = F_228 () , } ;
if ( F_181 ( V_263 . V_267 , V_229 ) &&
F_229 ( V_263 . V_268 , V_269 ) )
return 0 ;
return F_230 ( V_26 , & V_263 ) ;
}
static int F_231 ( struct V_9 * V_10 , struct V_28 * V_29 )
{
char V_100 [ V_99 ] ;
struct V_114 * V_26 ;
struct V_270 * V_38 = NULL ;
int V_6 ;
#ifdef F_232
V_38 = & V_29 -> V_271 ;
#endif
V_26 = F_233 ( V_10 -> V_26 , F_82 ( V_10 , V_29 , V_100 ) ,
F_83 ( V_29 ) , 0 , V_29 -> V_272 , V_29 ,
NULL , false , V_38 ) ;
if ( F_139 ( V_26 ) )
return F_140 ( V_26 ) ;
V_6 = F_226 ( V_26 ) ;
if ( V_6 ) {
F_234 ( V_26 ) ;
return V_6 ;
}
if ( V_29 -> V_104 == F_212 )
V_10 -> V_36 = V_26 ;
return 0 ;
}
static int F_99 ( struct V_9 * V_10 , struct V_28 V_116 [] ,
bool V_273 )
{
struct V_28 * V_29 ;
int V_6 ;
F_17 ( & V_18 ) ;
for ( V_29 = V_116 ; V_29 -> V_100 [ 0 ] != '\0' ; V_29 ++ ) {
if ( ( V_29 -> V_22 & V_274 ) && ! F_55 ( V_10 ) )
continue;
if ( ( V_29 -> V_22 & V_275 ) && F_55 ( V_10 ) )
continue;
if ( ( V_29 -> V_22 & V_276 ) && ! F_11 ( V_10 ) )
continue;
if ( ( V_29 -> V_22 & V_277 ) && F_11 ( V_10 ) )
continue;
if ( V_273 ) {
V_6 = F_231 ( V_10 , V_29 ) ;
if ( V_6 ) {
F_102 ( L_35 ,
V_278 , V_29 -> V_100 , V_6 ) ;
return V_6 ;
}
} else {
F_96 ( V_10 , V_29 ) ;
}
}
return 0 ;
}
static int F_235 ( struct V_28 * V_116 , bool V_273 )
{
F_136 ( V_279 ) ;
struct V_15 * V_16 = V_116 [ 0 ] . V_16 ;
struct V_9 * V_19 = & V_16 -> V_19 -> V_10 ;
struct V_11 * V_37 ;
int V_6 = 0 ;
F_17 ( & V_18 ) ;
F_201 (css, cgroup_css(root, ss)) {
struct V_9 * V_10 = V_37 -> V_9 ;
if ( F_18 ( V_10 ) )
continue;
V_6 = F_99 ( V_10 , V_116 , V_273 ) ;
if ( V_6 )
break;
}
if ( V_273 && ! V_6 )
F_108 ( V_19 -> V_26 ) ;
return V_6 ;
}
static void F_236 ( struct V_28 * V_116 )
{
struct V_28 * V_29 ;
for ( V_29 = V_116 ; V_29 -> V_100 [ 0 ] != '\0' ; V_29 ++ ) {
if ( V_29 -> V_280 && V_29 -> V_280 != V_281 )
F_36 ( V_29 -> V_272 ) ;
V_29 -> V_272 = NULL ;
V_29 -> V_16 = NULL ;
V_29 -> V_22 &= ~ ( V_274 | V_275 ) ;
}
}
static int F_237 ( struct V_15 * V_16 , struct V_28 * V_116 )
{
struct V_28 * V_29 ;
for ( V_29 = V_116 ; V_29 -> V_100 [ 0 ] != '\0' ; V_29 ++ ) {
struct V_282 * V_272 ;
F_103 ( V_29 -> V_16 || V_29 -> V_272 ) ;
if ( V_29 -> F_218 )
V_272 = & V_283 ;
else
V_272 = & V_284 ;
if ( V_29 -> V_280 && V_29 -> V_280 != V_281 ) {
V_272 = F_238 ( V_272 , sizeof( * V_272 ) , V_70 ) ;
if ( ! V_272 ) {
F_236 ( V_116 ) ;
return - V_71 ;
}
V_272 -> V_285 = V_29 -> V_280 ;
}
V_29 -> V_272 = V_272 ;
V_29 -> V_16 = V_16 ;
}
return 0 ;
}
static int F_239 ( struct V_28 * V_116 )
{
F_17 ( & V_18 ) ;
if ( ! V_116 || ! V_116 [ 0 ] . V_16 )
return - V_149 ;
F_31 ( & V_116 -> V_286 ) ;
F_235 ( V_116 , false ) ;
F_236 ( V_116 ) ;
return 0 ;
}
int F_240 ( struct V_28 * V_116 )
{
int V_6 ;
F_74 ( & V_18 ) ;
V_6 = F_239 ( V_116 ) ;
F_77 ( & V_18 ) ;
return V_6 ;
}
static int F_241 ( struct V_15 * V_16 , struct V_28 * V_116 )
{
int V_6 ;
if ( V_16 -> V_148 )
return 0 ;
if ( ! V_116 || V_116 [ 0 ] . V_100 [ 0 ] == '\0' )
return 0 ;
V_6 = F_237 ( V_16 , V_116 ) ;
if ( V_6 )
return V_6 ;
F_74 ( & V_18 ) ;
F_58 ( & V_116 -> V_286 , & V_16 -> V_116 ) ;
V_6 = F_235 ( V_116 , true ) ;
if ( V_6 )
F_239 ( V_116 ) ;
F_77 ( & V_18 ) ;
return V_6 ;
}
int F_242 ( struct V_15 * V_16 , struct V_28 * V_116 )
{
struct V_28 * V_29 ;
for ( V_29 = V_116 ; V_29 && V_29 -> V_100 [ 0 ] != '\0' ; V_29 ++ )
V_29 -> V_22 |= V_274 ;
return F_241 ( V_16 , V_116 ) ;
}
int F_243 ( struct V_15 * V_16 , struct V_28 * V_116 )
{
struct V_28 * V_29 ;
if ( ! V_287 ||
V_16 -> V_288 != V_16 -> V_289 ) {
for ( V_29 = V_116 ; V_29 && V_29 -> V_100 [ 0 ] != '\0' ; V_29 ++ )
V_29 -> V_22 |= V_275 ;
}
return F_241 ( V_16 , V_116 ) ;
}
static int F_244 ( const struct V_9 * V_10 )
{
int V_68 = 0 ;
struct V_42 * V_43 ;
F_60 ( & V_33 ) ;
F_64 (link, &cgrp->cset_links, cset_link)
V_68 += F_75 ( & V_43 -> V_41 -> V_46 ) ;
F_61 ( & V_33 ) ;
return V_68 ;
}
struct V_11 * F_100 ( struct V_11 * V_290 ,
struct V_11 * V_14 )
{
struct V_11 * V_65 ;
F_245 () ;
if ( ! V_290 ) {
V_65 = F_246 ( V_14 -> V_89 . V_65 , struct V_11 , V_163 ) ;
} else if ( F_247 ( ! ( V_290 -> V_22 & V_291 ) ) ) {
V_65 = F_246 ( V_290 -> V_163 . V_65 , struct V_11 , V_163 ) ;
} else {
F_248 (next, &parent->children, sibling)
if ( V_65 -> V_292 > V_290 -> V_292 )
break;
}
if ( & V_65 -> V_163 != & V_14 -> V_89 )
return V_65 ;
return NULL ;
}
struct V_11 *
F_249 ( struct V_11 * V_290 ,
struct V_11 * V_19 )
{
struct V_11 * V_65 ;
F_245 () ;
if ( ! V_290 )
return V_19 ;
V_65 = F_100 ( NULL , V_290 ) ;
if ( V_65 )
return V_65 ;
while ( V_290 != V_19 ) {
V_65 = F_100 ( V_290 , V_290 -> V_14 ) ;
if ( V_65 )
return V_65 ;
V_290 = V_290 -> V_14 ;
}
return NULL ;
}
struct V_11 *
F_250 ( struct V_11 * V_290 )
{
struct V_11 * V_293 , * V_294 ;
F_245 () ;
do {
V_293 = V_290 ;
V_290 = NULL ;
F_251 (tmp, last)
V_290 = V_294 ;
} while ( V_290 );
return V_293 ;
}
static struct V_11 *
F_252 ( struct V_11 * V_290 )
{
struct V_11 * V_293 ;
do {
V_293 = V_290 ;
V_290 = F_100 ( NULL , V_290 ) ;
} while ( V_290 );
return V_293 ;
}
struct V_11 *
F_253 ( struct V_11 * V_290 ,
struct V_11 * V_19 )
{
struct V_11 * V_65 ;
F_245 () ;
if ( ! V_290 )
return F_252 ( V_19 ) ;
if ( V_290 == V_19 )
return NULL ;
V_65 = F_100 ( V_290 , V_290 -> V_14 ) ;
if ( V_65 )
return F_252 ( V_65 ) ;
return V_290 -> V_14 ;
}
bool F_154 ( struct V_11 * V_37 )
{
struct V_11 * V_249 ;
bool V_6 = false ;
F_172 () ;
F_251 (child, css) {
if ( V_249 -> V_22 & V_23 ) {
V_6 = true ;
break;
}
}
F_179 () ;
return V_6 ;
}
static void F_254 ( struct V_295 * V_296 )
{
struct V_57 * V_297 = V_296 -> V_298 ;
struct V_42 * V_43 ;
struct V_40 * V_41 ;
do {
V_297 = V_297 -> V_65 ;
if ( V_297 == V_296 -> V_299 ) {
V_296 -> V_298 = NULL ;
return;
}
if ( V_296 -> V_16 ) {
V_41 = F_12 ( V_297 , struct V_40 ,
V_47 [ V_296 -> V_16 -> V_8 ] ) ;
} else {
V_43 = F_46 ( V_297 , struct V_42 , V_50 ) ;
V_41 = V_43 -> V_41 ;
}
} while ( F_34 ( & V_41 -> V_75 ) && F_34 ( & V_41 -> V_76 ) );
V_296 -> V_298 = V_297 ;
if ( ! F_34 ( & V_41 -> V_75 ) )
V_296 -> V_300 = V_41 -> V_75 . V_65 ;
else
V_296 -> V_300 = V_41 -> V_76 . V_65 ;
V_296 -> V_301 = & V_41 -> V_75 ;
V_296 -> V_302 = & V_41 -> V_76 ;
}
void F_255 ( struct V_11 * V_37 ,
struct V_295 * V_296 )
__acquires( V_33 )
{
F_71 ( ! V_157 ) ;
F_60 ( & V_33 ) ;
V_296 -> V_16 = V_37 -> V_16 ;
if ( V_296 -> V_16 )
V_296 -> V_298 = & V_37 -> V_9 -> V_81 [ V_37 -> V_16 -> V_8 ] ;
else
V_296 -> V_298 = & V_37 -> V_9 -> V_52 ;
V_296 -> V_299 = V_296 -> V_298 ;
F_254 ( V_296 ) ;
}
struct V_94 * F_256 ( struct V_295 * V_296 )
{
struct V_94 * V_92 ;
struct V_57 * V_297 = V_296 -> V_300 ;
if ( ! V_296 -> V_298 )
return NULL ;
V_92 = F_46 ( V_297 , struct V_94 , V_159 ) ;
V_297 = V_297 -> V_65 ;
if ( V_297 == V_296 -> V_301 )
V_297 = V_296 -> V_302 -> V_65 ;
if ( V_297 == V_296 -> V_302 )
F_254 ( V_296 ) ;
else
V_296 -> V_300 = V_297 ;
return V_92 ;
}
void F_257 ( struct V_295 * V_296 )
__releases( V_33 )
{
F_61 ( & V_33 ) ;
}
int F_258 ( struct V_9 * V_303 , struct V_9 * V_236 )
{
F_136 ( V_204 ) ;
struct V_42 * V_43 ;
struct V_295 V_296 ;
struct V_94 * V_95 ;
int V_6 ;
F_74 ( & V_18 ) ;
F_60 ( & V_33 ) ;
F_64 (link, &from->cset_links, cset_link)
F_167 ( V_43 -> V_41 , V_303 , & V_204 ) ;
F_61 ( & V_33 ) ;
V_6 = F_168 ( V_303 , & V_204 ) ;
if ( V_6 )
goto V_304;
do {
F_255 ( & V_236 -> V_13 , & V_296 ) ;
V_95 = F_256 ( & V_296 ) ;
if ( V_95 )
F_182 ( V_95 ) ;
F_257 ( & V_296 ) ;
if ( V_95 ) {
V_6 = F_170 ( V_303 , V_95 , false ) ;
F_186 ( V_95 ) ;
}
} while ( V_95 && ! V_6 );
V_304:
F_165 ( & V_204 ) ;
F_77 ( & V_18 ) ;
return V_6 ;
}
static void * F_259 ( int V_68 )
{
if ( F_260 ( V_68 ) )
return F_261 ( V_68 * sizeof( T_6 ) ) ;
else
return F_262 ( V_68 * sizeof( T_6 ) , V_70 ) ;
}
static void F_263 ( void * V_155 )
{
if ( F_264 ( V_155 ) )
F_265 ( V_155 ) ;
else
F_36 ( V_155 ) ;
}
static void F_266 ( struct V_9 * V_10 )
{
struct V_305 * V_297 , * V_306 ;
F_74 ( & V_10 -> V_165 ) ;
F_33 (l, tmp_l, &cgrp->pidlists, links)
F_267 ( V_307 , & V_297 -> V_308 , 0 ) ;
F_77 ( & V_10 -> V_165 ) ;
F_268 ( V_307 ) ;
F_45 ( ! F_34 ( & V_10 -> V_164 ) ) ;
}
static void F_269 ( struct V_309 * V_310 )
{
struct V_311 * V_312 = F_270 ( V_310 ) ;
struct V_305 * V_297 = F_12 ( V_312 , struct V_305 ,
V_308 ) ;
struct V_305 * V_313 = NULL ;
F_74 ( & V_297 -> V_314 -> V_165 ) ;
if ( ! F_271 ( V_312 ) ) {
F_31 ( & V_297 -> V_315 ) ;
F_263 ( V_297 -> V_316 ) ;
F_272 ( V_297 -> V_38 . V_317 ) ;
V_313 = V_297 ;
}
F_77 ( & V_297 -> V_314 -> V_165 ) ;
F_36 ( V_313 ) ;
}
static int F_273 ( T_6 * V_316 , int V_318 )
{
int V_319 , V_320 = 1 ;
if ( V_318 == 0 || V_318 == 1 )
return V_318 ;
for ( V_319 = 1 ; V_319 < V_318 ; V_319 ++ ) {
while ( V_316 [ V_319 ] == V_316 [ V_319 - 1 ] ) {
V_319 ++ ;
if ( V_319 == V_318 )
goto V_321;
}
V_316 [ V_320 ] = V_316 [ V_319 ] ;
V_320 ++ ;
}
V_321:
return V_320 ;
}
static T_6 F_274 ( T_6 V_223 )
{
unsigned V_322 = V_223 & 0x55555555 ;
unsigned V_323 = V_223 & 0xAAAAAAAA ;
return ( V_322 << 1 ) | ( V_323 >> 1 ) ;
}
static T_6 F_275 ( struct V_9 * V_10 , T_6 V_223 )
{
if ( F_55 ( V_10 ) )
return F_274 ( V_223 ) ;
else
return V_223 ;
}
static int F_276 ( const void * V_322 , const void * V_323 )
{
return * ( T_6 * ) V_322 - * ( T_6 * ) V_323 ;
}
static int F_277 ( const void * V_322 , const void * V_323 )
{
return F_274 ( * ( T_6 * ) V_322 ) - F_274 ( * ( T_6 * ) V_323 ) ;
}
static struct V_305 * F_278 ( struct V_9 * V_10 ,
enum V_324 type )
{
struct V_305 * V_297 ;
struct V_325 * V_317 = F_279 ( V_153 ) ;
F_17 ( & V_10 -> V_165 ) ;
F_64 (l, &cgrp->pidlists, links)
if ( V_297 -> V_38 . type == type && V_297 -> V_38 . V_317 == V_317 )
return V_297 ;
return NULL ;
}
static struct V_305 * F_280 ( struct V_9 * V_10 ,
enum V_324 type )
{
struct V_305 * V_297 ;
F_17 ( & V_10 -> V_165 ) ;
V_297 = F_278 ( V_10 , type ) ;
if ( V_297 )
return V_297 ;
V_297 = F_52 ( sizeof( struct V_305 ) , V_70 ) ;
if ( ! V_297 )
return V_297 ;
F_281 ( & V_297 -> V_308 , F_269 ) ;
V_297 -> V_38 . type = type ;
V_297 -> V_38 . V_317 = F_282 ( F_279 ( V_153 ) ) ;
V_297 -> V_314 = V_10 ;
F_53 ( & V_297 -> V_315 , & V_10 -> V_164 ) ;
return V_297 ;
}
static int F_283 ( struct V_9 * V_10 , enum V_324 type ,
struct V_305 * * V_326 )
{
T_6 * V_327 ;
int V_318 ;
int V_223 , V_328 = 0 ;
struct V_295 V_296 ;
struct V_94 * V_201 ;
struct V_305 * V_297 ;
F_17 ( & V_10 -> V_165 ) ;
V_318 = F_244 ( V_10 ) ;
V_327 = F_259 ( V_318 ) ;
if ( ! V_327 )
return - V_71 ;
F_255 ( & V_10 -> V_13 , & V_296 ) ;
while ( ( V_201 = F_256 ( & V_296 ) ) ) {
if ( F_284 ( V_328 == V_318 ) )
break;
if ( type == V_329 )
V_223 = F_285 ( V_201 ) ;
else
V_223 = F_286 ( V_201 ) ;
if ( V_223 > 0 )
V_327 [ V_328 ++ ] = V_223 ;
}
F_257 ( & V_296 ) ;
V_318 = V_328 ;
if ( F_55 ( V_10 ) )
F_287 ( V_327 , V_318 , sizeof( T_6 ) , F_277 , NULL ) ;
else
F_287 ( V_327 , V_318 , sizeof( T_6 ) , F_276 , NULL ) ;
if ( type == V_329 )
V_318 = F_273 ( V_327 , V_318 ) ;
V_297 = F_280 ( V_10 , type ) ;
if ( ! V_297 ) {
F_263 ( V_327 ) ;
return - V_71 ;
}
F_263 ( V_297 -> V_316 ) ;
V_297 -> V_316 = V_327 ;
V_297 -> V_318 = V_318 ;
* V_326 = V_297 ;
return 0 ;
}
int F_288 ( struct V_330 * V_331 , struct V_182 * V_182 )
{
struct V_114 * V_26 = F_289 ( V_182 ) ;
struct V_9 * V_10 ;
struct V_295 V_296 ;
struct V_94 * V_201 ;
if ( V_182 -> V_332 -> V_333 != & V_334 || ! V_26 ||
F_92 ( V_26 ) != V_115 )
return - V_141 ;
F_74 ( & V_18 ) ;
F_172 () ;
V_10 = F_290 ( V_26 -> V_27 ) ;
if ( ! V_10 || F_18 ( V_10 ) ) {
F_179 () ;
F_77 ( & V_18 ) ;
return - V_149 ;
}
F_179 () ;
F_255 ( & V_10 -> V_13 , & V_296 ) ;
while ( ( V_201 = F_256 ( & V_296 ) ) ) {
switch ( V_201 -> V_335 ) {
case V_336 :
V_331 -> V_337 ++ ;
break;
case V_338 :
V_331 -> V_339 ++ ;
break;
case V_252 :
V_331 -> V_340 ++ ;
break;
case V_341 :
V_331 -> V_342 ++ ;
break;
default:
if ( F_291 ( V_201 ) )
V_331 -> V_343 ++ ;
break;
}
}
F_257 ( & V_296 ) ;
F_77 ( & V_18 ) ;
return 0 ;
}
static void * F_292 ( struct V_125 * V_344 , T_5 * V_290 )
{
struct V_24 * V_25 = V_344 -> V_345 ;
struct V_9 * V_10 = F_193 ( V_344 ) -> V_9 ;
struct V_305 * V_297 ;
enum V_324 type = F_217 ( V_344 ) -> V_345 ;
int V_346 = 0 , V_223 = * V_290 ;
int * V_347 , V_6 ;
F_74 ( & V_10 -> V_165 ) ;
if ( V_25 -> V_27 )
V_25 -> V_27 = F_278 ( V_10 , type ) ;
if ( ! V_25 -> V_27 ) {
V_6 = F_283 ( V_10 , type ,
(struct V_305 * * ) & V_25 -> V_27 ) ;
if ( V_6 )
return F_150 ( V_6 ) ;
}
V_297 = V_25 -> V_27 ;
if ( V_223 ) {
int V_4 = V_297 -> V_318 ;
while ( V_346 < V_4 ) {
int V_348 = ( V_346 + V_4 ) / 2 ;
if ( F_275 ( V_10 , V_297 -> V_316 [ V_348 ] ) == V_223 ) {
V_346 = V_348 ;
break;
} else if ( F_275 ( V_10 , V_297 -> V_316 [ V_348 ] ) <= V_223 )
V_346 = V_348 + 1 ;
else
V_4 = V_348 ;
}
}
if ( V_346 >= V_297 -> V_318 )
return NULL ;
V_347 = V_297 -> V_316 + V_346 ;
* V_290 = F_275 ( V_10 , * V_347 ) ;
return V_347 ;
}
static void F_293 ( struct V_125 * V_344 , void * V_239 )
{
struct V_24 * V_25 = V_344 -> V_345 ;
struct V_305 * V_297 = V_25 -> V_27 ;
if ( V_297 )
F_267 ( V_307 , & V_297 -> V_308 ,
V_349 ) ;
F_77 ( & F_193 ( V_344 ) -> V_9 -> V_165 ) ;
}
static void * F_294 ( struct V_125 * V_344 , void * V_239 , T_5 * V_290 )
{
struct V_24 * V_25 = V_344 -> V_345 ;
struct V_305 * V_297 = V_25 -> V_27 ;
T_6 * V_155 = V_239 ;
T_6 * V_4 = V_297 -> V_316 + V_297 -> V_318 ;
V_155 ++ ;
if ( V_155 >= V_4 ) {
return NULL ;
} else {
* V_290 = F_275 ( F_193 ( V_344 ) -> V_9 , * V_155 ) ;
return V_155 ;
}
}
static int F_295 ( struct V_125 * V_344 , void * V_239 )
{
return F_110 ( V_344 , L_32 , * ( int * ) V_239 ) ;
}
static T_7 F_296 ( struct V_11 * V_37 ,
struct V_28 * V_29 )
{
return F_23 ( V_37 -> V_9 ) ;
}
static int F_297 ( struct V_11 * V_37 ,
struct V_28 * V_29 , T_7 V_350 )
{
if ( V_350 )
F_134 ( V_31 , & V_37 -> V_9 -> V_22 ) ;
else
F_298 ( V_31 , & V_37 -> V_9 -> V_22 ) ;
return 0 ;
}
static T_7 F_299 ( struct V_11 * V_37 ,
struct V_28 * V_29 )
{
return F_24 ( V_130 , & V_37 -> V_9 -> V_22 ) ;
}
static int F_300 ( struct V_11 * V_37 ,
struct V_28 * V_29 , T_7 V_350 )
{
if ( V_350 )
F_134 ( V_130 , & V_37 -> V_9 -> V_22 ) ;
else
F_298 ( V_130 , & V_37 -> V_9 -> V_22 ) ;
return 0 ;
}
static int F_101 ( struct V_9 * V_10 , unsigned int V_20 )
{
struct V_15 * V_16 ;
int V_39 , V_6 = 0 ;
F_28 (ss, i) {
struct V_28 * V_116 ;
if ( ! ( V_20 & ( 1 << V_39 ) ) )
continue;
F_64 (cfts, &ss->cfts, node) {
V_6 = F_99 ( V_10 , V_116 , true ) ;
if ( V_6 < 0 )
goto V_212;
}
}
return 0 ;
V_212:
F_98 ( V_10 , V_20 ) ;
return V_6 ;
}
static void F_301 ( struct V_309 * V_310 )
{
struct V_11 * V_37 =
F_12 ( V_310 , struct V_11 , V_351 ) ;
struct V_9 * V_10 = V_37 -> V_9 ;
F_141 ( & V_37 -> V_172 ) ;
if ( V_37 -> V_16 ) {
if ( V_37 -> V_14 )
F_89 ( V_37 -> V_14 ) ;
V_37 -> V_16 -> V_352 ( V_37 ) ;
F_88 ( V_10 ) ;
} else {
F_302 ( & V_10 -> V_19 -> V_88 ) ;
F_266 ( V_10 ) ;
F_303 ( & V_10 -> V_167 ) ;
if ( F_11 ( V_10 ) ) {
F_88 ( F_11 ( V_10 ) ) ;
F_304 ( V_10 -> V_26 ) ;
F_36 ( V_10 ) ;
} else {
F_73 ( V_10 -> V_19 ) ;
}
}
}
static void F_305 ( struct V_53 * V_53 )
{
struct V_11 * V_37 =
F_12 ( V_53 , struct V_11 , V_53 ) ;
F_131 ( & V_37 -> V_351 , F_301 ) ;
F_306 ( V_353 , & V_37 -> V_351 ) ;
}
static void F_307 ( struct V_309 * V_310 )
{
struct V_11 * V_37 =
F_12 ( V_310 , struct V_11 , V_351 ) ;
struct V_15 * V_16 = V_37 -> V_16 ;
struct V_9 * V_10 = V_37 -> V_9 ;
F_74 ( & V_18 ) ;
V_37 -> V_22 |= V_291 ;
F_308 ( & V_37 -> V_163 ) ;
if ( V_16 ) {
F_9 ( & V_16 -> V_354 , V_37 -> V_8 ) ;
} else {
F_9 ( & V_10 -> V_19 -> V_87 , V_10 -> V_8 ) ;
V_10 -> V_8 = - 1 ;
F_104 ( * ( void V_355 V_356 * * ) & V_10 -> V_26 -> V_27 , NULL ) ;
}
F_77 ( & V_18 ) ;
F_309 ( & V_37 -> V_53 , F_305 ) ;
}
static void V_173 ( struct V_357 * V_358 )
{
struct V_11 * V_37 =
F_12 ( V_358 , struct V_11 , V_172 ) ;
F_131 ( & V_37 -> V_351 , F_307 ) ;
F_306 ( V_353 , & V_37 -> V_351 ) ;
}
static void F_310 ( struct V_11 * V_37 ,
struct V_15 * V_16 , struct V_9 * V_10 )
{
F_17 ( & V_18 ) ;
F_84 ( V_10 ) ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_9 = V_10 ;
V_37 -> V_16 = V_16 ;
F_51 ( & V_37 -> V_163 ) ;
F_51 ( & V_37 -> V_89 ) ;
V_37 -> V_292 = V_359 ++ ;
if ( F_11 ( V_10 ) ) {
V_37 -> V_14 = F_13 ( F_11 ( V_10 ) , V_16 ) ;
F_85 ( V_37 -> V_14 ) ;
}
F_45 ( F_13 ( V_10 , V_16 ) ) ;
}
static int F_311 ( struct V_11 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_16 ;
int V_6 = 0 ;
F_17 ( & V_18 ) ;
if ( V_16 -> V_360 )
V_6 = V_16 -> V_360 ( V_37 ) ;
if ( ! V_6 ) {
V_37 -> V_22 |= V_23 ;
F_105 ( V_37 -> V_9 -> V_17 [ V_16 -> V_8 ] , V_37 ) ;
}
return V_6 ;
}
static void F_312 ( struct V_11 * V_37 )
{
struct V_15 * V_16 = V_37 -> V_16 ;
F_17 ( & V_18 ) ;
if ( ! ( V_37 -> V_22 & V_23 ) )
return;
if ( V_16 -> V_361 )
V_16 -> V_361 ( V_37 ) ;
V_37 -> V_22 &= ~ V_23 ;
F_104 ( V_37 -> V_9 -> V_17 [ V_16 -> V_8 ] , NULL ) ;
F_313 ( & V_37 -> V_9 -> V_166 ) ;
}
static int F_210 ( struct V_9 * V_10 , struct V_15 * V_16 ,
bool V_362 )
{
struct V_9 * V_14 = F_11 ( V_10 ) ;
struct V_11 * V_12 = F_13 ( V_14 , V_16 ) ;
struct V_11 * V_37 ;
int V_212 ;
F_17 ( & V_18 ) ;
V_37 = V_16 -> V_363 ( V_12 ) ;
if ( F_139 ( V_37 ) )
return F_140 ( V_37 ) ;
F_310 ( V_37 , V_16 , V_10 ) ;
V_212 = F_137 ( & V_37 -> V_172 , V_173 , 0 , V_70 ) ;
if ( V_212 )
goto V_364;
V_212 = F_1 ( & V_16 -> V_354 , NULL , 2 , 0 , V_170 ) ;
if ( V_212 < 0 )
goto V_365;
V_37 -> V_8 = V_212 ;
if ( V_362 ) {
V_212 = F_101 ( V_10 , 1 << V_16 -> V_8 ) ;
if ( V_212 )
goto V_366;
}
F_314 ( & V_37 -> V_163 , & V_12 -> V_89 ) ;
F_7 ( & V_16 -> V_354 , V_37 , V_37 -> V_8 ) ;
V_212 = F_311 ( V_37 ) ;
if ( V_212 )
goto V_367;
if ( V_16 -> V_368 && ! V_16 -> V_369 &&
F_11 ( V_14 ) ) {
F_102 ( L_36 ,
V_153 -> V_154 , V_153 -> V_223 , V_16 -> V_100 ) ;
if ( ! strcmp ( V_16 -> V_100 , L_37 ) )
F_102 ( L_38 ) ;
V_16 -> V_369 = true ;
}
return 0 ;
V_367:
F_308 ( & V_37 -> V_163 ) ;
F_98 ( V_37 -> V_9 , 1 << V_37 -> V_16 -> V_8 ) ;
V_366:
F_9 ( & V_16 -> V_354 , V_37 -> V_8 ) ;
V_365:
F_141 ( & V_37 -> V_172 ) ;
V_364:
F_309 ( & V_37 -> V_53 , F_305 ) ;
return V_212 ;
}
static int F_315 ( struct V_114 * V_370 , const char * V_100 ,
T_2 V_101 )
{
struct V_9 * V_14 , * V_10 ;
struct V_66 * V_19 ;
struct V_15 * V_16 ;
struct V_114 * V_26 ;
struct V_28 * V_169 ;
int V_45 , V_6 ;
if ( strchr ( V_100 , '\n' ) )
return - V_141 ;
V_14 = F_94 ( V_370 ) ;
if ( ! V_14 )
return - V_224 ;
V_19 = V_14 -> V_19 ;
V_10 = F_52 ( sizeof( * V_10 ) , V_70 ) ;
if ( ! V_10 ) {
V_6 = - V_71 ;
goto V_152;
}
V_6 = F_137 ( & V_10 -> V_13 . V_172 , V_173 , 0 , V_70 ) ;
if ( V_6 )
goto V_371;
V_10 -> V_8 = F_1 ( & V_19 -> V_87 , NULL , 2 , 0 , V_170 ) ;
if ( V_10 -> V_8 < 0 ) {
V_6 = - V_71 ;
goto V_372;
}
F_128 ( V_10 ) ;
V_10 -> V_13 . V_14 = & V_14 -> V_13 ;
V_10 -> V_19 = V_19 ;
if ( F_23 ( V_14 ) )
F_134 ( V_31 , & V_10 -> V_22 ) ;
if ( F_24 ( V_130 , & V_14 -> V_22 ) )
F_134 ( V_130 , & V_10 -> V_22 ) ;
V_26 = F_316 ( V_14 -> V_26 , V_100 , V_101 , V_10 ) ;
if ( F_139 ( V_26 ) ) {
V_6 = F_140 ( V_26 ) ;
goto V_373;
}
V_10 -> V_26 = V_26 ;
F_317 ( V_26 ) ;
V_10 -> V_13 . V_292 = V_359 ++ ;
F_314 ( & V_10 -> V_13 . V_163 , & F_11 ( V_10 ) -> V_13 . V_89 ) ;
F_43 ( & V_19 -> V_88 ) ;
F_84 ( V_14 ) ;
F_7 ( & V_19 -> V_87 , V_10 , V_10 -> V_8 ) ;
V_6 = F_226 ( V_26 ) ;
if ( V_6 )
goto V_374;
if ( F_55 ( V_10 ) )
V_169 = V_178 ;
else
V_169 = V_179 ;
V_6 = F_99 ( V_10 , V_169 , true ) ;
if ( V_6 )
goto V_374;
F_28 (ss, ssid) {
if ( V_14 -> V_21 & ( 1 << V_45 ) ) {
V_6 = F_210 ( V_10 , V_16 ,
V_14 -> V_111 & ( 1 << V_45 ) ) ;
if ( V_6 )
goto V_374;
}
}
if ( ! F_55 ( V_10 ) ) {
V_10 -> V_111 = V_14 -> V_111 ;
F_90 ( V_10 ) ;
}
F_108 ( V_26 ) ;
V_6 = 0 ;
goto V_152;
V_373:
F_9 ( & V_19 -> V_87 , V_10 -> V_8 ) ;
V_372:
F_141 ( & V_10 -> V_13 . V_172 ) ;
V_371:
F_36 ( V_10 ) ;
V_152:
F_91 ( V_370 ) ;
return V_6 ;
V_374:
F_318 ( V_10 ) ;
goto V_152;
}
static void F_319 ( struct V_309 * V_310 )
{
struct V_11 * V_37 =
F_12 ( V_310 , struct V_11 , V_351 ) ;
F_74 ( & V_18 ) ;
F_312 ( V_37 ) ;
F_77 ( & V_18 ) ;
F_89 ( V_37 ) ;
}
static void F_320 ( struct V_357 * V_358 )
{
struct V_11 * V_37 =
F_12 ( V_358 , struct V_11 , V_172 ) ;
F_131 ( & V_37 -> V_351 , F_319 ) ;
F_306 ( V_353 , & V_37 -> V_351 ) ;
}
static void F_211 ( struct V_11 * V_37 )
{
F_17 ( & V_18 ) ;
F_98 ( V_37 -> V_9 , 1 << V_37 -> V_16 -> V_8 ) ;
F_85 ( V_37 ) ;
F_321 ( & V_37 -> V_172 , F_320 ) ;
}
static int F_318 ( struct V_9 * V_10 )
__releases( &cgroup_mutex
static int F_322 ( struct V_114 * V_26 )
{
struct V_9 * V_10 ;
int V_6 = 0 ;
V_10 = F_94 ( V_26 ) ;
if ( ! V_10 )
return 0 ;
V_6 = F_318 ( V_10 ) ;
F_91 ( V_26 ) ;
return V_6 ;
}
static void T_8 F_323 ( struct V_15 * V_16 , bool V_375 )
{
struct V_11 * V_37 ;
F_324 ( V_376 L_39 , V_16 -> V_100 ) ;
F_74 ( & V_18 ) ;
F_133 ( & V_16 -> V_354 ) ;
F_51 ( & V_16 -> V_116 ) ;
V_16 -> V_19 = & V_90 ;
V_37 = V_16 -> V_363 ( F_13 ( & V_90 . V_10 , V_16 ) ) ;
F_45 ( F_139 ( V_37 ) ) ;
F_310 ( V_37 , V_16 , & V_90 . V_10 ) ;
V_37 -> V_22 |= V_377 ;
if ( V_375 ) {
V_37 -> V_8 = 1 ;
} else {
V_37 -> V_8 = F_1 ( & V_16 -> V_354 , V_37 , 1 , 2 , V_70 ) ;
F_45 ( V_37 -> V_8 < 0 ) ;
}
V_93 . V_17 [ V_16 -> V_8 ] = V_37 ;
V_378 |= V_16 -> V_379 || V_16 -> exit ;
F_45 ( ! F_34 ( & V_380 . V_75 ) ) ;
F_45 ( F_311 ( V_37 ) ) ;
F_77 ( & V_18 ) ;
}
int T_8 F_325 ( void )
{
static struct V_132 T_9 V_133 ;
struct V_15 * V_16 ;
int V_39 ;
F_132 ( & V_90 , & V_133 ) ;
V_90 . V_10 . V_13 . V_22 |= V_377 ;
F_104 ( V_380 . V_203 , & V_93 ) ;
F_28 (ss, i) {
F_203 ( ! V_16 -> V_363 || ! V_16 -> V_352 || V_16 -> V_100 || V_16 -> V_8 ,
L_40 ,
V_39 , V_381 [ V_39 ] , V_16 -> V_363 , V_16 -> V_352 ,
V_16 -> V_8 , V_16 -> V_100 ) ;
F_203 ( strlen ( V_381 [ V_39 ] ) > V_382 ,
L_41 , V_381 [ V_39 ] ) ;
V_16 -> V_8 = V_39 ;
V_16 -> V_100 = V_381 [ V_39 ] ;
if ( V_16 -> V_383 )
F_323 ( V_16 , true ) ;
}
return 0 ;
}
int T_8 F_326 ( void )
{
struct V_15 * V_16 ;
unsigned long V_38 ;
int V_45 , V_212 ;
F_45 ( F_237 ( NULL , V_178 ) ) ;
F_45 ( F_237 ( NULL , V_179 ) ) ;
F_74 ( & V_18 ) ;
V_38 = F_27 ( V_93 . V_17 ) ;
F_65 ( V_80 , & V_93 . V_48 , V_38 ) ;
F_45 ( F_135 ( & V_90 , 0 ) ) ;
F_77 ( & V_18 ) ;
F_28 (ss, ssid) {
if ( V_16 -> V_383 ) {
struct V_11 * V_37 =
V_93 . V_17 [ V_16 -> V_8 ] ;
V_37 -> V_8 = F_1 ( & V_16 -> V_354 , V_37 , 1 , 2 ,
V_70 ) ;
F_45 ( V_37 -> V_8 < 0 ) ;
} else {
F_323 ( V_16 , false ) ;
}
F_58 ( & V_93 . V_47 [ V_45 ] ,
& V_90 . V_10 . V_81 [ V_45 ] ) ;
if ( V_16 -> V_148 )
continue;
V_90 . V_20 |= 1 << V_16 -> V_8 ;
if ( V_287 && ! V_16 -> V_288 )
V_16 -> V_288 = V_16 -> V_289 ;
if ( ! V_16 -> V_288 )
V_121 |= 1 << V_16 -> V_8 ;
if ( V_16 -> V_288 == V_16 -> V_289 ) {
F_103 ( F_241 ( V_16 , V_16 -> V_288 ) ) ;
} else {
F_103 ( F_242 ( V_16 , V_16 -> V_288 ) ) ;
F_103 ( F_243 ( V_16 , V_16 -> V_289 ) ) ;
}
}
V_384 = F_327 ( L_42 , V_385 ) ;
if ( ! V_384 )
return - V_71 ;
V_212 = F_328 ( & V_334 ) ;
if ( V_212 < 0 ) {
F_329 ( V_384 ) ;
return V_212 ;
}
F_330 ( L_43 , 0 , NULL , & V_386 ) ;
return 0 ;
}
static int T_8 F_331 ( void )
{
V_353 = F_332 ( L_44 , 0 , 1 ) ;
F_45 ( ! V_353 ) ;
V_307 = F_332 ( L_45 ,
0 , 1 ) ;
F_45 ( ! V_307 ) ;
return 0 ;
}
int F_333 ( struct V_125 * V_256 , struct V_325 * V_317 ,
struct V_223 * V_223 , struct V_94 * V_201 )
{
char * V_96 , * V_194 ;
int V_237 ;
struct V_66 * V_19 ;
V_237 = - V_71 ;
V_96 = F_262 ( V_146 , V_70 ) ;
if ( ! V_96 )
goto V_171;
F_74 ( & V_18 ) ;
F_60 ( & V_33 ) ;
F_146 (root) {
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_45 , V_68 = 0 ;
if ( V_19 == & V_90 && ! V_122 )
continue;
F_110 ( V_256 , L_46 , V_19 -> V_86 ) ;
F_28 (ss, ssid)
if ( V_19 -> V_20 & ( 1 << V_45 ) )
F_110 ( V_256 , L_47 , V_68 ++ ? L_10 : L_24 , V_16 -> V_100 ) ;
if ( strlen ( V_19 -> V_100 ) )
F_110 ( V_256 , L_48 , V_68 ? L_10 : L_24 ,
V_19 -> V_100 ) ;
F_194 ( V_256 , ':' ) ;
V_10 = F_80 ( V_201 , V_19 ) ;
V_194 = F_159 ( V_10 , V_96 , V_146 ) ;
if ( ! V_194 ) {
V_237 = - V_387 ;
goto V_152;
}
F_111 ( V_256 , V_194 ) ;
F_194 ( V_256 , '\n' ) ;
}
V_237 = 0 ;
V_152:
F_61 ( & V_33 ) ;
F_77 ( & V_18 ) ;
F_36 ( V_96 ) ;
V_171:
return V_237 ;
}
static int F_334 ( struct V_125 * V_256 , void * V_239 )
{
struct V_15 * V_16 ;
int V_39 ;
F_111 ( V_256 , L_49 ) ;
F_74 ( & V_18 ) ;
F_28 (ss, i)
F_110 ( V_256 , L_50 ,
V_16 -> V_100 , V_16 -> V_19 -> V_86 ,
F_75 ( & V_16 -> V_19 -> V_88 ) , ! V_16 -> V_148 ) ;
F_77 ( & V_18 ) ;
return 0 ;
}
static int F_335 ( struct V_388 * V_388 , struct V_389 * V_389 )
{
return F_336 ( V_389 , F_334 , NULL ) ;
}
void F_337 ( struct V_94 * V_249 )
{
F_104 ( V_249 -> V_203 , & V_93 ) ;
F_51 ( & V_249 -> V_159 ) ;
}
void F_338 ( struct V_94 * V_249 )
{
struct V_15 * V_16 ;
int V_39 ;
if ( V_157 ) {
struct V_40 * V_41 ;
F_40 ( & V_33 ) ;
V_41 = F_81 ( V_153 ) ;
if ( F_34 ( & V_249 -> V_159 ) ) {
F_105 ( V_249 -> V_203 , V_41 ) ;
F_53 ( & V_249 -> V_159 , & V_41 -> V_75 ) ;
F_42 ( V_41 ) ;
}
F_41 ( & V_33 ) ;
}
if ( V_378 ) {
F_28 (ss, i)
if ( V_16 -> V_379 )
V_16 -> V_379 ( V_249 ) ;
}
}
void F_339 ( struct V_94 * V_201 )
{
struct V_15 * V_16 ;
struct V_40 * V_41 ;
bool V_390 = false ;
int V_39 ;
if ( ! F_34 ( & V_201 -> V_159 ) ) {
F_40 ( & V_33 ) ;
F_166 ( & V_201 -> V_159 ) ;
F_41 ( & V_33 ) ;
V_390 = true ;
}
V_41 = F_81 ( V_201 ) ;
F_104 ( V_201 -> V_203 , & V_93 ) ;
if ( V_378 ) {
F_28 (ss, i) {
if ( V_16 -> exit ) {
struct V_11 * V_391 = V_41 -> V_17 [ V_39 ] ;
struct V_11 * V_37 = F_340 ( V_201 , V_39 ) ;
V_16 -> exit ( V_37 , V_391 , V_201 ) ;
}
}
}
if ( V_390 )
F_38 ( V_41 ) ;
}
static void F_35 ( struct V_9 * V_10 )
{
if ( F_23 ( V_10 ) && ! F_341 ( V_10 ) &&
! F_154 ( & V_10 -> V_13 ) && ! F_18 ( V_10 ) )
F_342 ( & V_10 -> V_167 ) ;
}
static void V_168 ( struct V_309 * V_310 )
{
struct V_9 * V_10 =
F_12 ( V_310 , struct V_9 , V_167 ) ;
char * V_392 = NULL , * V_393 = NULL , * V_194 ;
char * V_394 [ 3 ] , * V_395 [ 3 ] ;
F_74 ( & V_18 ) ;
V_392 = F_262 ( V_146 , V_70 ) ;
V_393 = F_343 ( V_10 -> V_19 -> V_129 , V_70 ) ;
if ( ! V_392 || ! V_393 )
goto V_171;
V_194 = F_159 ( V_10 , V_392 , V_146 ) ;
if ( ! V_194 )
goto V_171;
V_394 [ 0 ] = V_393 ;
V_394 [ 1 ] = V_194 ;
V_394 [ 2 ] = NULL ;
V_395 [ 0 ] = L_51 ;
V_395 [ 1 ] = L_52 ;
V_395 [ 2 ] = NULL ;
F_77 ( & V_18 ) ;
F_344 ( V_394 [ 0 ] , V_394 , V_395 , V_396 ) ;
goto V_189;
V_171:
F_77 ( & V_18 ) ;
V_189:
F_36 ( V_393 ) ;
F_36 ( V_392 ) ;
}
static int T_8 F_345 ( char * V_397 )
{
struct V_15 * V_16 ;
char * V_134 ;
int V_39 ;
while ( ( V_134 = F_116 ( & V_397 , L_10 ) ) != NULL ) {
if ( ! * V_134 )
continue;
F_28 (ss, i) {
if ( ! strcmp ( V_134 , V_16 -> V_100 ) ) {
V_16 -> V_148 = 1 ;
F_324 ( V_376 L_53
L_54 , V_16 -> V_100 ) ;
break;
}
}
}
return 1 ;
}
static int T_8 F_346 ( char * V_397 )
{
F_324 ( L_55 ) ;
V_287 = true ;
return 0 ;
}
struct V_11 * F_347 ( struct V_182 * V_182 ,
struct V_15 * V_16 )
{
struct V_114 * V_26 = F_289 ( V_182 ) ;
struct V_11 * V_37 = NULL ;
struct V_9 * V_10 ;
if ( V_182 -> V_332 -> V_333 != & V_334 || ! V_26 ||
F_92 ( V_26 ) != V_115 )
return F_150 ( - V_398 ) ;
F_172 () ;
V_10 = F_290 ( V_26 -> V_27 ) ;
if ( V_10 )
V_37 = F_13 ( V_10 , V_16 ) ;
if ( ! V_37 || ! F_348 ( V_37 ) )
V_37 = F_150 ( - V_149 ) ;
F_179 () ;
return V_37 ;
}
struct V_11 * F_349 ( int V_8 , struct V_15 * V_16 )
{
F_71 ( ! F_350 () ) ;
return F_351 ( & V_16 -> V_354 , V_8 ) ;
}
static struct V_11 *
F_352 ( struct V_11 * V_12 )
{
struct V_11 * V_37 = F_52 ( sizeof( * V_37 ) , V_70 ) ;
if ( ! V_37 )
return F_150 ( - V_71 ) ;
return V_37 ;
}
static void F_353 ( struct V_11 * V_37 )
{
F_36 ( V_37 ) ;
}
static T_7 F_354 ( struct V_11 * V_37 ,
struct V_28 * V_29 )
{
return F_244 ( V_37 -> V_9 ) ;
}
static T_7 F_355 ( struct V_11 * V_37 ,
struct V_28 * V_29 )
{
return ( T_7 ) ( unsigned long ) V_153 -> V_203 ;
}
static T_7 F_356 ( struct V_11 * V_37 ,
struct V_28 * V_29 )
{
T_7 V_68 ;
F_172 () ;
V_68 = F_75 ( & F_81 ( V_153 ) -> V_46 ) ;
F_179 () ;
return V_68 ;
}
static int F_357 ( struct V_125 * V_126 , void * V_239 )
{
struct V_42 * V_43 ;
struct V_40 * V_41 ;
char * V_399 ;
V_399 = F_262 ( V_400 + 1 , V_70 ) ;
if ( ! V_399 )
return - V_71 ;
F_60 ( & V_33 ) ;
F_172 () ;
V_41 = F_290 ( V_153 -> V_203 ) ;
F_64 (link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_79 = V_43 -> V_10 ;
F_358 ( V_79 , V_399 , V_400 + 1 ) ;
F_110 ( V_126 , L_56 ,
V_79 -> V_19 -> V_86 , V_399 ) ;
}
F_179 () ;
F_61 ( & V_33 ) ;
F_36 ( V_399 ) ;
return 0 ;
}
static int F_359 ( struct V_125 * V_126 , void * V_239 )
{
struct V_11 * V_37 = F_193 ( V_126 ) ;
struct V_42 * V_43 ;
F_60 ( & V_33 ) ;
F_64 (link, &css->cgroup->cset_links, cset_link) {
struct V_40 * V_41 = V_43 -> V_41 ;
struct V_94 * V_95 ;
int V_68 = 0 ;
F_110 ( V_126 , L_57 , V_41 ) ;
F_64 (task, &cset->tasks, cg_list) {
if ( V_68 ++ > V_401 )
goto V_402;
F_110 ( V_126 , L_58 , F_286 ( V_95 ) ) ;
}
F_64 (task, &cset->mg_tasks, cg_list) {
if ( V_68 ++ > V_401 )
goto V_402;
F_110 ( V_126 , L_58 , F_286 ( V_95 ) ) ;
}
continue;
V_402:
F_111 ( V_126 , L_59 ) ;
}
F_61 ( & V_33 ) ;
return 0 ;
}
static T_7 F_360 ( struct V_11 * V_37 , struct V_28 * V_29 )
{
return ( ! F_341 ( V_37 -> V_9 ) &&
! F_154 ( & V_37 -> V_9 -> V_13 ) ) ;
}
