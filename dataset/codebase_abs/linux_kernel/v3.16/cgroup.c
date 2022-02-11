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
static void F_88 ( struct V_9 * V_10 )
{
F_89 ( & V_10 -> V_13 ) ;
}
static void F_90 ( struct V_113 * V_26 )
{
struct V_9 * V_10 ;
if ( F_91 ( V_26 ) == V_114 )
V_10 = V_26 -> V_27 ;
else
V_10 = V_26 -> V_14 -> V_27 ;
F_79 ( & V_18 ) ;
F_92 ( V_26 ) ;
F_88 ( V_10 ) ;
}
static struct V_9 * F_93 ( struct V_113 * V_26 )
{
struct V_9 * V_10 ;
if ( F_91 ( V_26 ) == V_114 )
V_10 = V_26 -> V_27 ;
else
V_10 = V_26 -> V_14 -> V_27 ;
F_86 ( V_10 ) ;
F_94 ( V_26 ) ;
F_76 ( & V_18 ) ;
if ( ! F_18 ( V_10 ) )
return V_10 ;
F_90 ( V_26 ) ;
return NULL ;
}
static void F_95 ( struct V_9 * V_10 , const struct V_28 * V_29 )
{
char V_103 [ V_102 ] ;
F_17 ( & V_18 ) ;
F_96 ( V_10 -> V_26 , F_84 ( V_10 , V_29 , V_103 ) ) ;
}
static void F_97 ( struct V_9 * V_10 , unsigned int V_20 )
{
struct V_15 * V_16 ;
int V_41 ;
F_29 (ss, i) {
struct V_28 * V_115 ;
if ( ! ( V_20 & ( 1 << V_41 ) ) )
continue;
F_66 (cfts, &ss->cfts, node)
F_98 ( V_10 , V_115 , false ) ;
}
}
static int F_78 ( struct V_69 * V_116 , unsigned int V_117 )
{
struct V_15 * V_16 ;
unsigned int V_118 ;
int V_48 , V_41 , V_6 ;
F_17 ( & V_18 ) ;
F_29 (ss, ssid) {
if ( ! ( V_117 & ( 1 << V_48 ) ) )
continue;
if ( F_99 ( NULL , F_13 ( & V_16 -> V_19 -> V_10 , V_16 ) ) )
return - V_119 ;
if ( V_16 -> V_19 != & V_93 && V_116 != & V_93 )
return - V_119 ;
}
V_118 = V_117 ;
if ( V_116 == & V_93 )
V_118 &= ~ V_120 ;
V_6 = F_100 ( & V_116 -> V_10 , V_118 ) ;
if ( V_6 ) {
if ( V_116 != & V_93 )
return V_6 ;
if ( V_121 ) {
F_101 ( L_2 ,
V_6 , V_117 ) ;
F_101 ( L_3 ) ;
}
}
F_29 (ss, ssid)
if ( V_117 & ( 1 << V_48 ) )
F_97 ( & V_16 -> V_19 -> V_10 , 1 << V_48 ) ;
F_29 (ss, ssid) {
struct V_69 * V_122 ;
struct V_11 * V_39 ;
struct V_42 * V_43 ;
if ( ! ( V_117 & ( 1 << V_48 ) ) )
continue;
V_122 = V_16 -> V_19 ;
V_39 = F_13 ( & V_122 -> V_10 , V_16 ) ;
F_102 ( ! V_39 || F_13 ( & V_116 -> V_10 , V_16 ) ) ;
F_103 ( V_122 -> V_10 . V_17 [ V_48 ] , NULL ) ;
F_104 ( V_116 -> V_10 . V_17 [ V_48 ] , V_39 ) ;
V_16 -> V_19 = V_116 ;
V_39 -> V_9 = & V_116 -> V_10 ;
F_42 ( & V_35 ) ;
F_105 (css_set_table, i, cset, hlist)
F_106 ( & V_43 -> V_50 [ V_16 -> V_8 ] ,
& V_116 -> V_10 . V_84 [ V_16 -> V_8 ] ) ;
F_43 ( & V_35 ) ;
V_122 -> V_20 &= ~ ( 1 << V_48 ) ;
V_122 -> V_10 . V_21 &= ~ ( 1 << V_48 ) ;
V_116 -> V_20 |= 1 << V_48 ;
if ( V_116 != & V_93 )
V_116 -> V_10 . V_21 |= 1 << V_48 ;
if ( V_16 -> V_123 )
V_16 -> V_123 ( V_39 ) ;
}
F_107 ( V_116 -> V_10 . V_26 ) ;
return 0 ;
}
static int F_108 ( struct V_124 * V_125 ,
struct V_85 * V_86 )
{
struct V_69 * V_19 = F_68 ( V_86 ) ;
struct V_15 * V_16 ;
int V_48 ;
F_29 (ss, ssid)
if ( V_19 -> V_20 & ( 1 << V_48 ) )
F_109 ( V_125 , L_4 , V_16 -> V_103 ) ;
if ( V_19 -> V_22 & V_126 )
F_110 ( V_125 , L_5 ) ;
if ( V_19 -> V_22 & V_101 )
F_110 ( V_125 , L_6 ) ;
if ( V_19 -> V_22 & V_127 )
F_110 ( V_125 , L_7 ) ;
F_111 ( & V_128 ) ;
if ( strlen ( V_19 -> V_129 ) )
F_109 ( V_125 , L_8 , V_19 -> V_129 ) ;
F_112 ( & V_128 ) ;
if ( F_25 ( V_130 , & V_19 -> V_10 . V_22 ) )
F_110 ( V_125 , L_9 ) ;
if ( strlen ( V_19 -> V_103 ) )
F_109 ( V_125 , L_10 , V_19 -> V_103 ) ;
return 0 ;
}
static int F_113 ( char * V_131 , struct V_132 * V_133 )
{
char * V_134 , * V_135 = V_131 ;
bool V_136 = false , V_137 = false ;
unsigned int V_138 = - 1U ;
struct V_15 * V_16 ;
int V_41 ;
#ifdef F_114
V_138 = ~ ( 1U << V_139 ) ;
#endif
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
while ( ( V_134 = F_115 ( & V_135 , L_11 ) ) != NULL ) {
if ( ! * V_134 )
return - V_140 ;
if ( ! strcmp ( V_134 , L_12 ) ) {
V_133 -> V_141 = true ;
continue;
}
if ( ! strcmp ( V_134 , L_13 ) ) {
if ( V_137 )
return - V_140 ;
V_136 = true ;
continue;
}
if ( ! strcmp ( V_134 , L_14 ) ) {
V_133 -> V_22 |= V_126 ;
continue;
}
if ( ! strcmp ( V_134 , L_15 ) ) {
V_133 -> V_22 |= V_101 ;
continue;
}
if ( ! strcmp ( V_134 , L_16 ) ) {
V_133 -> V_142 = true ;
continue;
}
if ( ! strcmp ( V_134 , L_17 ) ) {
V_133 -> V_22 |= V_127 ;
continue;
}
if ( ! strncmp ( V_134 , L_18 , 14 ) ) {
if ( V_133 -> V_143 )
return - V_140 ;
V_133 -> V_143 =
F_116 ( V_134 + 14 , V_144 - 1 , V_73 ) ;
if ( ! V_133 -> V_143 )
return - V_74 ;
continue;
}
if ( ! strncmp ( V_134 , L_19 , 5 ) ) {
const char * V_103 = V_134 + 5 ;
if ( ! strlen ( V_103 ) )
return - V_140 ;
for ( V_41 = 0 ; V_41 < strlen ( V_103 ) ; V_41 ++ ) {
char V_82 = V_103 [ V_41 ] ;
if ( isalnum ( V_82 ) )
continue;
if ( ( V_82 == '.' ) || ( V_82 == '-' ) || ( V_82 == '_' ) )
continue;
return - V_140 ;
}
if ( V_133 -> V_103 )
return - V_140 ;
V_133 -> V_103 = F_116 ( V_103 ,
V_145 - 1 ,
V_73 ) ;
if ( ! V_133 -> V_103 )
return - V_74 ;
continue;
}
F_29 (ss, i) {
if ( strcmp ( V_134 , V_16 -> V_103 ) )
continue;
if ( V_16 -> V_146 )
continue;
if ( V_136 )
return - V_140 ;
V_133 -> V_20 |= ( 1 << V_41 ) ;
V_137 = true ;
break;
}
if ( V_41 == V_76 )
return - V_147 ;
}
if ( V_133 -> V_22 & V_126 ) {
F_101 ( L_20 ) ;
if ( ( V_133 -> V_22 & ( V_101 | V_127 ) ) ||
V_133 -> V_142 || V_133 -> V_143 ||
V_133 -> V_103 ) {
F_117 ( L_21 ) ;
return - V_140 ;
}
} else {
if ( V_136 || ( ! V_137 && ! V_133 -> V_141 && ! V_133 -> V_103 ) )
F_29 (ss, i)
if ( ! V_16 -> V_146 )
V_133 -> V_20 |= ( 1 << V_41 ) ;
if ( ! V_133 -> V_20 && ! V_133 -> V_103 )
return - V_140 ;
}
if ( ( V_133 -> V_22 & V_101 ) && ( V_133 -> V_20 & V_138 ) )
return - V_140 ;
if ( V_133 -> V_20 && V_133 -> V_141 )
return - V_140 ;
return 0 ;
}
static int F_118 ( struct V_85 * V_86 , int * V_22 , char * V_131 )
{
int V_6 = 0 ;
struct V_69 * V_19 = F_68 ( V_86 ) ;
struct V_132 V_133 ;
unsigned int V_148 , V_149 ;
if ( V_19 -> V_22 & V_126 ) {
F_117 ( L_22 ) ;
return - V_140 ;
}
F_76 ( & V_18 ) ;
V_6 = F_113 ( V_131 , & V_133 ) ;
if ( V_6 )
goto V_150;
if ( V_133 . V_20 != V_19 -> V_20 || V_133 . V_143 )
F_101 ( L_23 ,
F_119 ( V_151 ) , V_151 -> V_152 ) ;
V_148 = V_133 . V_20 & ~ V_19 -> V_20 ;
V_149 = V_19 -> V_20 & ~ V_133 . V_20 ;
if ( ( ( V_133 . V_22 ^ V_19 -> V_22 ) & V_153 ) ||
( V_133 . V_103 && strcmp ( V_133 . V_103 , V_19 -> V_103 ) ) ) {
F_117 ( L_24 ,
V_133 . V_22 & V_153 , V_133 . V_103 ? : L_25 ,
V_19 -> V_22 & V_153 , V_19 -> V_103 ) ;
V_6 = - V_140 ;
goto V_150;
}
if ( ! F_35 ( & V_19 -> V_10 . V_13 . V_92 ) ) {
V_6 = - V_119 ;
goto V_150;
}
V_6 = F_78 ( V_19 , V_148 ) ;
if ( V_6 )
goto V_150;
F_78 ( & V_93 , V_149 ) ;
if ( V_133 . V_143 ) {
F_111 ( & V_128 ) ;
strcpy ( V_19 -> V_129 , V_133 . V_143 ) ;
F_112 ( & V_128 ) ;
}
V_150:
F_38 ( V_133 . V_143 ) ;
F_38 ( V_133 . V_103 ) ;
F_79 ( & V_18 ) ;
return V_6 ;
}
static void F_120 ( void )
{
struct V_97 * V_154 , * V_155 ;
F_42 ( & V_35 ) ;
if ( V_156 )
goto V_150;
V_156 = true ;
F_121 ( & V_157 ) ;
F_122 (g, p) {
F_73 ( ! F_35 ( & V_154 -> V_158 ) ||
F_83 ( V_154 ) != & V_96 ) ;
F_123 ( & V_154 -> V_159 -> V_160 ) ;
if ( ! ( V_154 -> V_22 & V_161 ) ) {
struct V_42 * V_43 = F_83 ( V_154 ) ;
F_55 ( & V_154 -> V_158 , & V_43 -> V_78 ) ;
F_44 ( V_43 ) ;
}
F_124 ( & V_154 -> V_159 -> V_160 ) ;
} F_125 ( V_155 , V_154 ) ;
F_126 ( & V_157 ) ;
V_150:
F_43 ( & V_35 ) ;
}
static void F_127 ( struct V_9 * V_10 )
{
struct V_15 * V_16 ;
int V_48 ;
F_53 ( & V_10 -> V_13 . V_162 ) ;
F_53 ( & V_10 -> V_13 . V_92 ) ;
F_53 ( & V_10 -> V_55 ) ;
F_53 ( & V_10 -> V_163 ) ;
F_53 ( & V_10 -> V_164 ) ;
F_128 ( & V_10 -> V_165 ) ;
V_10 -> V_13 . V_9 = V_10 ;
V_10 -> V_13 . V_22 |= V_23 ;
F_29 (ss, ssid)
F_53 ( & V_10 -> V_84 [ V_48 ] ) ;
F_129 ( & V_10 -> V_166 ) ;
}
static void F_130 ( struct V_69 * V_19 ,
struct V_132 * V_133 )
{
struct V_9 * V_10 = & V_19 -> V_10 ;
F_53 ( & V_19 -> V_94 ) ;
F_64 ( & V_19 -> V_91 , 1 ) ;
V_10 -> V_19 = V_19 ;
F_127 ( V_10 ) ;
F_131 ( & V_19 -> V_90 ) ;
V_19 -> V_22 = V_133 -> V_22 ;
if ( V_133 -> V_143 )
strcpy ( V_19 -> V_129 , V_133 -> V_143 ) ;
if ( V_133 -> V_103 )
strcpy ( V_19 -> V_103 , V_133 -> V_103 ) ;
if ( V_133 -> V_142 )
F_36 ( V_130 , & V_19 -> V_10 . V_22 ) ;
}
static int F_132 ( struct V_69 * V_19 , unsigned int V_117 )
{
F_133 ( V_72 ) ;
struct V_9 * V_87 = & V_19 -> V_10 ;
struct V_42 * V_43 ;
int V_41 , V_6 ;
F_17 ( & V_18 ) ;
V_6 = F_1 ( & V_19 -> V_90 , V_87 , 1 , 2 , V_167 ) ;
if ( V_6 < 0 )
goto V_168;
V_87 -> V_8 = V_6 ;
V_6 = F_134 ( & V_87 -> V_13 . V_169 , V_170 ) ;
if ( V_6 )
goto V_168;
V_6 = F_52 ( V_52 , & V_72 ) ;
if ( V_6 )
goto V_171;
V_6 = F_69 ( V_19 ) ;
if ( V_6 )
goto V_171;
V_19 -> V_86 = F_135 ( & V_172 ,
V_173 ,
V_87 ) ;
if ( F_136 ( V_19 -> V_86 ) ) {
V_6 = F_137 ( V_19 -> V_86 ) ;
goto V_174;
}
V_87 -> V_26 = V_19 -> V_86 -> V_26 ;
V_6 = F_98 ( V_87 , V_175 , true ) ;
if ( V_6 )
goto V_176;
V_6 = F_78 ( V_19 , V_117 ) ;
if ( V_6 )
goto V_176;
F_55 ( & V_19 -> V_94 , & V_177 ) ;
V_77 ++ ;
F_42 ( & V_35 ) ;
F_105 (css_set_table, i, cset, hlist)
F_56 ( & V_72 , V_43 , V_87 ) ;
F_43 ( & V_35 ) ;
F_47 ( ! F_35 ( & V_87 -> V_13 . V_92 ) ) ;
F_47 ( F_77 ( & V_19 -> V_91 ) != 1 ) ;
F_107 ( V_87 -> V_26 ) ;
V_6 = 0 ;
goto V_168;
V_176:
F_80 ( V_19 -> V_86 ) ;
V_19 -> V_86 = NULL ;
V_174:
F_71 ( V_19 ) ;
V_171:
F_138 ( & V_87 -> V_13 . V_169 ) ;
V_168:
F_51 ( & V_72 ) ;
return V_6 ;
}
static struct V_178 * F_139 ( struct V_179 * V_180 ,
int V_22 , const char * V_181 ,
void * V_131 )
{
struct V_182 * V_183 = NULL ;
struct V_15 * V_16 ;
struct V_69 * V_19 ;
struct V_132 V_133 ;
struct V_178 * V_178 ;
int V_6 ;
int V_41 ;
bool V_184 ;
if ( ! V_156 )
F_120 () ;
F_76 ( & V_18 ) ;
V_6 = F_113 ( V_131 , & V_133 ) ;
if ( V_6 )
goto V_150;
if ( ! V_133 . V_20 && ! V_133 . V_141 && ! V_133 . V_103 ) {
V_121 = true ;
V_19 = & V_93 ;
F_86 ( & V_19 -> V_10 ) ;
V_6 = 0 ;
goto V_150;
}
F_29 (ss, i) {
if ( ! ( V_133 . V_20 & ( 1 << V_41 ) ) ||
V_16 -> V_19 == & V_93 )
continue;
if ( ! F_140 ( & V_16 -> V_19 -> V_10 . V_13 . V_169 ) ) {
F_79 ( & V_18 ) ;
F_141 ( 10 ) ;
V_6 = F_142 () ;
goto V_185;
}
F_88 ( & V_16 -> V_19 -> V_10 ) ;
}
F_143 (root) {
bool V_186 = false ;
if ( V_19 == & V_93 )
continue;
if ( V_133 . V_103 ) {
if ( strcmp ( V_133 . V_103 , V_19 -> V_103 ) )
continue;
V_186 = true ;
}
if ( ( V_133 . V_20 || V_133 . V_141 ) &&
( V_133 . V_20 != V_19 -> V_20 ) ) {
if ( ! V_186 )
continue;
V_6 = - V_119 ;
goto V_150;
}
if ( ( V_19 -> V_22 ^ V_133 . V_22 ) & V_153 ) {
if ( ( V_19 -> V_22 | V_133 . V_22 ) & V_126 ) {
F_117 ( L_26 ) ;
V_6 = - V_140 ;
goto V_150;
} else {
F_101 ( L_27 ) ;
}
}
V_183 = F_144 ( V_19 -> V_86 , NULL ) ;
if ( F_136 ( V_183 ) ||
! F_140 ( & V_19 -> V_10 . V_13 . V_169 ) ) {
F_79 ( & V_18 ) ;
if ( ! F_145 ( V_183 ) )
F_146 ( V_183 ) ;
F_141 ( 10 ) ;
V_6 = F_142 () ;
goto V_185;
}
V_6 = 0 ;
goto V_150;
}
if ( ! V_133 . V_20 && ! V_133 . V_141 ) {
V_6 = - V_140 ;
goto V_150;
}
V_19 = F_54 ( sizeof( * V_19 ) , V_73 ) ;
if ( ! V_19 ) {
V_6 = - V_74 ;
goto V_150;
}
F_130 ( V_19 , & V_133 ) ;
V_6 = F_132 ( V_19 , V_133 . V_20 ) ;
if ( V_6 )
F_72 ( V_19 ) ;
V_150:
F_79 ( & V_18 ) ;
V_185:
F_38 ( V_133 . V_143 ) ;
F_38 ( V_133 . V_103 ) ;
if ( V_6 )
return F_147 ( V_6 ) ;
V_178 = F_148 ( V_180 , V_22 , V_19 -> V_86 ,
V_187 , & V_184 ) ;
if ( F_136 ( V_178 ) || ! V_184 )
F_88 ( & V_19 -> V_10 ) ;
if ( V_183 ) {
F_102 ( V_184 ) ;
F_146 ( V_183 ) ;
}
return V_178 ;
}
static void F_149 ( struct V_182 * V_188 )
{
struct V_85 * V_86 = F_150 ( V_188 ) ;
struct V_69 * V_19 = F_68 ( V_86 ) ;
if ( F_151 ( & V_19 -> V_10 . V_13 ) ||
V_19 == & V_93 )
F_88 ( & V_19 -> V_10 ) ;
else
F_152 ( & V_19 -> V_10 . V_13 . V_169 ) ;
F_153 ( V_188 ) ;
}
char * F_154 ( struct V_97 * V_98 , char * V_99 , T_3 V_189 )
{
struct V_69 * V_19 ;
struct V_9 * V_10 ;
int V_89 = 1 ;
char * V_190 = NULL ;
F_76 ( & V_18 ) ;
F_62 ( & V_35 ) ;
V_19 = F_155 ( & V_88 , & V_89 ) ;
if ( V_19 ) {
V_10 = F_82 ( V_98 , V_19 ) ;
V_190 = F_156 ( V_10 , V_99 , V_189 ) ;
} else {
if ( F_157 ( V_99 , L_28 , V_189 ) < V_189 )
V_190 = V_99 ;
}
F_63 ( & V_35 ) ;
F_79 ( & V_18 ) ;
return V_190 ;
}
struct V_97 * F_158 ( struct V_191 * V_192 )
{
V_192 -> V_193 = F_58 ( V_192 -> V_194 , struct V_42 , V_81 ) ;
V_192 -> V_195 = NULL ;
return F_159 ( V_192 ) ;
}
struct V_97 * F_159 ( struct V_191 * V_192 )
{
struct V_42 * V_43 = V_192 -> V_193 ;
struct V_97 * V_98 = V_192 -> V_195 ;
while ( & V_43 -> V_81 != V_192 -> V_194 ) {
if ( ! V_98 )
V_98 = F_58 ( & V_43 -> V_79 ,
struct V_97 , V_158 ) ;
else
V_98 = F_160 ( V_98 , V_158 ) ;
if ( & V_98 -> V_158 != & V_43 -> V_79 ) {
V_192 -> V_193 = V_43 ;
V_192 -> V_195 = V_98 ;
return V_98 ;
}
V_43 = F_160 ( V_43 , V_81 ) ;
V_98 = NULL ;
}
return NULL ;
}
static void F_161 ( struct V_9 * V_196 ,
struct V_97 * V_197 ,
struct V_42 * V_198 )
{
struct V_42 * V_57 ;
F_17 ( & V_18 ) ;
F_17 ( & V_35 ) ;
F_73 ( V_197 -> V_22 & V_161 ) ;
V_57 = F_83 ( V_197 ) ;
F_44 ( V_198 ) ;
F_104 ( V_197 -> V_199 , V_198 ) ;
F_106 ( & V_197 -> V_158 , & V_198 -> V_79 ) ;
F_36 ( V_32 , & V_196 -> V_22 ) ;
F_30 ( V_57 , false ) ;
}
static void F_162 ( struct V_60 * V_200 )
{
struct V_42 * V_43 , * V_201 ;
F_17 ( & V_18 ) ;
F_42 ( & V_35 ) ;
F_34 (cset, tmp_cset, preloaded_csets, mg_preload_node) {
V_43 -> V_202 = NULL ;
V_43 -> V_203 = NULL ;
F_163 ( & V_43 -> V_80 ) ;
F_30 ( V_43 , false ) ;
}
F_43 ( & V_35 ) ;
}
static void F_164 ( struct V_42 * V_204 ,
struct V_9 * V_205 ,
struct V_60 * V_200 )
{
struct V_9 * V_206 ;
F_17 ( & V_18 ) ;
F_17 ( & V_35 ) ;
V_206 = F_81 ( V_204 , V_205 -> V_19 ) ;
if ( ! F_35 ( & V_204 -> V_80 ) )
return;
F_102 ( V_204 -> V_202 ) ;
F_102 ( ! F_35 ( & V_204 -> V_79 ) ) ;
F_102 ( ! F_35 ( & V_204 -> V_81 ) ) ;
V_204 -> V_202 = V_206 ;
F_44 ( V_204 ) ;
F_55 ( & V_204 -> V_80 , V_200 ) ;
}
static int F_165 ( struct V_9 * V_205 ,
struct V_60 * V_200 )
{
F_133 ( V_194 ) ;
struct V_42 * V_204 , * V_201 ;
F_17 ( & V_18 ) ;
if ( V_205 && F_57 ( V_205 ) && F_11 ( V_205 ) &&
V_205 -> V_21 )
return - V_119 ;
F_34 (src_cset, tmp_cset, preloaded_csets, mg_preload_node) {
struct V_42 * V_207 ;
V_207 = F_61 ( V_204 ,
V_205 ? : V_204 -> V_75 ) ;
if ( ! V_207 )
goto V_208;
F_73 ( V_204 -> V_203 || V_207 -> V_203 ) ;
if ( V_204 == V_207 ) {
V_204 -> V_202 = NULL ;
F_163 ( & V_204 -> V_80 ) ;
F_40 ( V_204 , false ) ;
F_40 ( V_207 , false ) ;
continue;
}
V_204 -> V_203 = V_207 ;
if ( F_35 ( & V_207 -> V_80 ) )
F_55 ( & V_207 -> V_80 , & V_194 ) ;
else
F_40 ( V_207 , false ) ;
}
F_166 ( & V_194 , V_200 ) ;
return 0 ;
V_208:
F_162 ( & V_194 ) ;
return - V_74 ;
}
static int F_167 ( struct V_9 * V_10 , struct V_97 * V_209 ,
bool V_210 )
{
struct V_191 V_192 = {
. V_211 = F_168 ( V_192 . V_211 ) ,
. V_212 = F_168 ( V_192 . V_212 ) ,
. V_194 = & V_192 . V_211 ,
} ;
struct V_11 * V_39 , * V_213 = NULL ;
struct V_42 * V_43 , * V_201 ;
struct V_97 * V_98 , * V_214 ;
int V_41 , V_6 ;
F_42 ( & V_35 ) ;
F_169 () ;
V_98 = V_209 ;
do {
if ( V_98 -> V_22 & V_161 )
goto V_68;
if ( F_35 ( & V_98 -> V_158 ) )
goto V_68;
V_43 = F_83 ( V_98 ) ;
if ( ! V_43 -> V_202 )
goto V_68;
F_106 ( & V_98 -> V_158 , & V_43 -> V_79 ) ;
if ( F_35 ( & V_43 -> V_81 ) )
F_60 ( & V_43 -> V_81 , & V_192 . V_211 ) ;
if ( F_35 ( & V_43 -> V_203 -> V_81 ) )
F_106 ( & V_43 -> V_203 -> V_81 ,
& V_192 . V_212 ) ;
V_68:
if ( ! V_210 )
break;
} while_each_thread(leader, task) ;
int F_170 ( struct V_9 * V_205 ,
struct V_97 * V_209 , bool V_210 )
{
F_133 ( V_200 ) ;
struct V_97 * V_98 ;
int V_6 ;
F_62 ( & V_35 ) ;
F_169 () ;
V_98 = V_209 ;
do {
F_164 ( F_83 ( V_98 ) , V_205 ,
& V_200 ) ;
if ( ! V_210 )
break;
} while_each_thread(leader, task) ;
T_4 F_171 ( struct V_24 * V_25 , char * V_99 ,
T_3 V_215 , T_5 V_216 , bool V_210 )
{
struct V_97 * V_197 ;
const struct V_217 * V_217 = F_172 () , * V_218 ;
struct V_9 * V_10 ;
T_6 V_219 ;
int V_6 ;
if ( F_173 ( F_174 ( V_99 ) , 0 , & V_219 ) || V_219 < 0 )
return - V_140 ;
V_10 = F_93 ( V_25 -> V_26 ) ;
if ( ! V_10 )
return - V_220 ;
V_221:
F_169 () ;
if ( V_219 ) {
V_197 = F_175 ( V_219 ) ;
if ( ! V_197 ) {
F_176 () ;
V_6 = - V_222 ;
goto V_223;
}
V_218 = F_177 ( V_197 ) ;
if ( ! F_178 ( V_217 -> V_224 , V_225 ) &&
! F_178 ( V_217 -> V_224 , V_218 -> V_226 ) &&
! F_178 ( V_217 -> V_224 , V_218 -> V_227 ) ) {
F_176 () ;
V_6 = - V_228 ;
goto V_223;
}
} else
V_197 = V_151 ;
if ( V_210 )
V_197 = V_197 -> V_229 ;
if ( V_197 == V_230 || ( V_197 -> V_22 & V_231 ) ) {
V_6 = - V_140 ;
F_176 () ;
goto V_223;
}
F_179 ( V_197 ) ;
F_176 () ;
F_180 ( V_197 ) ;
if ( V_210 ) {
if ( ! F_181 ( V_197 ) ) {
F_182 ( V_197 ) ;
F_183 ( V_197 ) ;
goto V_221;
}
}
V_6 = F_170 ( V_10 , V_197 , V_210 ) ;
F_182 ( V_197 ) ;
F_183 ( V_197 ) ;
V_223:
F_90 ( V_25 -> V_26 ) ;
return V_6 ? : V_215 ;
}
int F_184 ( struct V_97 * V_232 , struct V_97 * V_197 )
{
struct V_69 * V_19 ;
int V_233 = 0 ;
F_76 ( & V_18 ) ;
F_143 (root) {
struct V_9 * V_234 ;
if ( V_19 == & V_93 )
continue;
F_62 ( & V_35 ) ;
V_234 = F_82 ( V_232 , V_19 ) ;
F_63 ( & V_35 ) ;
V_233 = F_170 ( V_234 , V_197 , false ) ;
if ( V_233 )
break;
}
F_79 ( & V_18 ) ;
return V_233 ;
}
static T_4 F_185 ( struct V_24 * V_25 ,
char * V_99 , T_3 V_215 , T_5 V_216 )
{
return F_171 ( V_25 , V_99 , V_215 , V_216 , false ) ;
}
static T_4 F_186 ( struct V_24 * V_25 ,
char * V_99 , T_3 V_215 , T_5 V_216 )
{
return F_171 ( V_25 , V_99 , V_215 , V_216 , true ) ;
}
static T_4 F_187 ( struct V_24 * V_25 ,
char * V_99 , T_3 V_215 , T_5 V_216 )
{
struct V_9 * V_10 ;
F_188 ( sizeof( V_10 -> V_19 -> V_129 ) < V_144 ) ;
V_10 = F_93 ( V_25 -> V_26 ) ;
if ( ! V_10 )
return - V_220 ;
F_111 ( & V_128 ) ;
F_157 ( V_10 -> V_19 -> V_129 , F_174 ( V_99 ) ,
sizeof( V_10 -> V_19 -> V_129 ) ) ;
F_112 ( & V_128 ) ;
F_90 ( V_25 -> V_26 ) ;
return V_215 ;
}
static int F_189 ( struct V_124 * V_125 , void * V_235 )
{
struct V_9 * V_10 = F_190 ( V_125 ) -> V_9 ;
F_111 ( & V_128 ) ;
F_110 ( V_125 , V_10 -> V_19 -> V_129 ) ;
F_112 ( & V_128 ) ;
F_191 ( V_125 , '\n' ) ;
return 0 ;
}
static int F_192 ( struct V_124 * V_125 , void * V_235 )
{
struct V_9 * V_10 = F_190 ( V_125 ) -> V_9 ;
F_109 ( V_125 , L_29 , F_193 ( V_10 ) ) ;
return 0 ;
}
static void F_194 ( struct V_124 * V_125 , unsigned int V_117 )
{
struct V_15 * V_16 ;
bool V_236 = false ;
int V_48 ;
F_29 (ss, ssid) {
if ( V_117 & ( 1 << V_48 ) ) {
if ( V_236 )
F_191 ( V_125 , ' ' ) ;
F_109 ( V_125 , L_30 , V_16 -> V_103 ) ;
V_236 = true ;
}
}
if ( V_236 )
F_191 ( V_125 , '\n' ) ;
}
static int F_195 ( struct V_124 * V_125 , void * V_235 )
{
struct V_9 * V_10 = F_190 ( V_125 ) -> V_9 ;
F_194 ( V_125 , V_10 -> V_19 -> V_20 &
~ V_120 ) ;
return 0 ;
}
static int F_196 ( struct V_124 * V_125 , void * V_235 )
{
struct V_9 * V_10 = F_190 ( V_125 ) -> V_9 ;
F_194 ( V_125 , F_11 ( V_10 ) -> V_21 ) ;
return 0 ;
}
static int F_197 ( struct V_124 * V_125 , void * V_235 )
{
struct V_9 * V_10 = F_190 ( V_125 ) -> V_9 ;
F_194 ( V_125 , V_10 -> V_21 ) ;
return 0 ;
}
static int F_198 ( struct V_9 * V_10 )
{
F_133 ( V_200 ) ;
struct V_11 * V_39 ;
struct V_42 * V_204 ;
int V_6 ;
F_17 ( & V_18 ) ;
F_62 ( & V_35 ) ;
F_199 (css, cgroup_css(cgrp, NULL)) {
struct V_45 * V_46 ;
if ( V_39 -> V_9 == V_10 )
continue;
F_66 (link, &css->cgroup->cset_links, cset_link)
F_164 ( V_46 -> V_43 , V_10 ,
& V_200 ) ;
}
F_63 ( & V_35 ) ;
V_6 = F_165 ( NULL , & V_200 ) ;
if ( V_6 )
goto V_237;
F_66 (src_cset, &preloaded_csets, mg_preload_node) {
struct V_97 * V_238 = NULL , * V_98 ;
if ( ! V_204 -> V_202 )
break;
while ( true ) {
F_62 ( & V_35 ) ;
V_98 = F_200 ( & V_204 -> V_78 ,
struct V_97 , V_158 ) ;
if ( V_98 ) {
V_98 = V_98 -> V_229 ;
F_73 ( ! F_83 ( V_98 ) -> V_202 ) ;
F_179 ( V_98 ) ;
}
F_63 ( & V_35 ) ;
if ( ! V_98 )
break;
if ( F_201 ( V_238 == V_98 ,
L_31 ) )
goto V_237;
V_238 = V_98 ;
F_180 ( V_98 ) ;
if ( ! F_181 ( V_98 ) ) {
F_182 ( V_98 ) ;
F_183 ( V_98 ) ;
continue;
}
V_6 = F_167 ( V_204 -> V_75 , V_98 , true ) ;
F_182 ( V_98 ) ;
F_183 ( V_98 ) ;
if ( F_201 ( V_6 , L_32 , V_6 ) )
goto V_237;
}
}
V_237:
F_162 ( & V_200 ) ;
return V_6 ;
}
static T_4 F_202 ( struct V_24 * V_25 ,
char * V_99 , T_3 V_215 ,
T_5 V_216 )
{
unsigned int V_239 = 0 , V_240 = 0 ;
struct V_9 * V_10 , * V_241 ;
struct V_15 * V_16 ;
char * V_242 ;
int V_48 , V_6 ;
V_99 = F_174 ( V_99 ) ;
while ( ( V_242 = F_115 ( & V_99 , L_33 ) ) ) {
if ( V_242 [ 0 ] == '\0' )
continue;
F_29 (ss, ssid) {
if ( V_16 -> V_146 || strcmp ( V_242 + 1 , V_16 -> V_103 ) ||
( ( 1 << V_16 -> V_8 ) & V_120 ) )
continue;
if ( * V_242 == '+' ) {
V_239 |= 1 << V_48 ;
V_240 &= ~ ( 1 << V_48 ) ;
} else if ( * V_242 == '-' ) {
V_240 |= 1 << V_48 ;
V_239 &= ~ ( 1 << V_48 ) ;
} else {
return - V_140 ;
}
break;
}
if ( V_48 == V_76 )
return - V_140 ;
}
V_10 = F_93 ( V_25 -> V_26 ) ;
if ( ! V_10 )
return - V_220 ;
F_29 (ss, ssid) {
if ( V_239 & ( 1 << V_48 ) ) {
if ( V_10 -> V_21 & ( 1 << V_48 ) ) {
V_239 &= ~ ( 1 << V_48 ) ;
continue;
}
F_203 (child, cgrp) {
F_204 ( V_243 ) ;
if ( ! F_13 ( V_241 , V_16 ) )
continue;
F_86 ( V_241 ) ;
F_205 ( & V_241 -> V_166 , & V_243 ,
V_244 ) ;
F_90 ( V_25 -> V_26 ) ;
F_206 () ;
F_207 ( & V_241 -> V_166 , & V_243 ) ;
F_88 ( V_241 ) ;
return F_142 () ;
}
if ( ! ( V_93 . V_20 & ( 1 << V_48 ) ) ||
( F_11 ( V_10 ) &&
! ( F_11 ( V_10 ) -> V_21 & ( 1 << V_48 ) ) ) ) {
V_6 = - V_147 ;
goto V_150;
}
} else if ( V_240 & ( 1 << V_48 ) ) {
if ( ! ( V_10 -> V_21 & ( 1 << V_48 ) ) ) {
V_240 &= ~ ( 1 << V_48 ) ;
continue;
}
F_203 (child, cgrp) {
if ( V_241 -> V_21 & ( 1 << V_48 ) ) {
V_6 = - V_119 ;
goto V_150;
}
}
}
}
if ( ! V_239 && ! V_240 ) {
V_6 = 0 ;
goto V_150;
}
if ( V_239 && F_11 ( V_10 ) && ! F_35 ( & V_10 -> V_55 ) ) {
V_6 = - V_119 ;
goto V_150;
}
F_29 (ss, ssid) {
if ( ! ( V_239 & ( 1 << V_48 ) ) )
continue;
F_203 (child, cgrp) {
V_6 = F_208 ( V_241 , V_16 ) ;
if ( V_6 )
goto V_245;
}
}
V_10 -> V_21 |= V_239 ;
V_10 -> V_21 &= ~ V_240 ;
V_6 = F_198 ( V_10 ) ;
if ( V_6 )
goto V_245;
F_29 (ss, ssid) {
if ( ! ( V_240 & ( 1 << V_48 ) ) )
continue;
F_203 (child, cgrp)
F_209 ( F_13 ( V_241 , V_16 ) ) ;
}
F_107 ( V_10 -> V_26 ) ;
V_6 = 0 ;
V_150:
F_90 ( V_25 -> V_26 ) ;
return V_6 ? : V_215 ;
V_245:
V_10 -> V_21 &= ~ V_239 ;
V_10 -> V_21 |= V_240 ;
F_29 (ss, ssid) {
if ( ! ( V_239 & ( 1 << V_48 ) ) )
continue;
F_203 (child, cgrp) {
struct V_11 * V_39 = F_13 ( V_241 , V_16 ) ;
if ( V_39 )
F_209 ( V_39 ) ;
}
}
goto V_150;
}
static int F_210 ( struct V_124 * V_125 , void * V_235 )
{
F_109 ( V_125 , L_29 , ( bool ) F_190 ( V_125 ) -> V_9 -> V_37 ) ;
return 0 ;
}
static T_4 F_211 ( struct V_24 * V_25 , char * V_99 ,
T_3 V_215 , T_5 V_216 )
{
struct V_9 * V_10 = V_25 -> V_26 -> V_14 -> V_27 ;
struct V_28 * V_29 = V_25 -> V_26 -> V_27 ;
struct V_11 * V_39 ;
int V_6 ;
if ( V_29 -> V_111 )
return V_29 -> V_111 ( V_25 , V_99 , V_215 , V_216 ) ;
F_169 () ;
V_39 = F_13 ( V_10 , V_29 -> V_16 ) ;
F_176 () ;
if ( V_29 -> V_109 ) {
unsigned long long V_235 ;
V_6 = F_212 ( V_99 , 0 , & V_235 ) ;
if ( ! V_6 )
V_6 = V_29 -> V_109 ( V_39 , V_29 , V_235 ) ;
} else if ( V_29 -> V_110 ) {
long long V_235 ;
V_6 = F_213 ( V_99 , 0 , & V_235 ) ;
if ( ! V_6 )
V_6 = V_29 -> V_110 ( V_39 , V_29 , V_235 ) ;
} else {
V_6 = - V_140 ;
}
return V_6 ? : V_215 ;
}
static void * F_214 ( struct V_124 * V_125 , T_5 * V_246 )
{
return F_215 ( V_125 ) -> F_216 ( V_125 , V_246 ) ;
}
static void * F_217 ( struct V_124 * V_125 , void * V_235 , T_5 * V_246 )
{
return F_215 ( V_125 ) -> F_218 ( V_125 , V_235 , V_246 ) ;
}
static void F_219 ( struct V_124 * V_125 , void * V_235 )
{
F_215 ( V_125 ) -> F_220 ( V_125 , V_235 ) ;
}
static int F_221 ( struct V_124 * V_247 , void * V_248 )
{
struct V_28 * V_29 = F_215 ( V_247 ) ;
struct V_11 * V_39 = F_190 ( V_247 ) ;
if ( V_29 -> V_107 )
return V_29 -> V_107 ( V_247 , V_248 ) ;
if ( V_29 -> V_105 )
F_109 ( V_247 , L_34 , V_29 -> V_105 ( V_39 , V_29 ) ) ;
else if ( V_29 -> V_106 )
F_109 ( V_247 , L_35 , V_29 -> V_106 ( V_39 , V_29 ) ) ;
else
return - V_140 ;
return 0 ;
}
static int F_222 ( struct V_113 * V_26 , struct V_113 * V_249 ,
const char * V_250 )
{
struct V_9 * V_10 = V_26 -> V_27 ;
int V_6 ;
if ( F_91 ( V_26 ) != V_114 )
return - V_251 ;
if ( V_26 -> V_14 != V_249 )
return - V_252 ;
if ( F_193 ( V_10 ) )
return - V_253 ;
F_94 ( V_249 ) ;
F_94 ( V_26 ) ;
F_76 ( & V_18 ) ;
V_6 = F_223 ( V_26 , V_249 , V_250 ) ;
F_79 ( & V_18 ) ;
F_92 ( V_26 ) ;
F_92 ( V_249 ) ;
return V_6 ;
}
static int F_224 ( struct V_113 * V_26 )
{
struct V_254 V_254 = { . V_255 = V_256 | V_257 ,
. V_258 = F_225 () ,
. V_259 = F_226 () , } ;
if ( F_178 ( V_254 . V_258 , V_225 ) &&
F_227 ( V_254 . V_259 , V_260 ) )
return 0 ;
return F_228 ( V_26 , & V_254 ) ;
}
static int F_229 ( struct V_9 * V_10 , struct V_28 * V_29 )
{
char V_103 [ V_102 ] ;
struct V_113 * V_26 ;
struct V_261 * V_40 = NULL ;
int V_6 ;
#ifdef F_230
V_40 = & V_29 -> V_262 ;
#endif
V_26 = F_231 ( V_10 -> V_26 , F_84 ( V_10 , V_29 , V_103 ) ,
F_85 ( V_29 ) , 0 , V_29 -> V_263 , V_29 ,
NULL , false , V_40 ) ;
if ( F_136 ( V_26 ) )
return F_137 ( V_26 ) ;
V_6 = F_224 ( V_26 ) ;
if ( V_6 ) {
F_232 ( V_26 ) ;
return V_6 ;
}
if ( V_29 -> V_107 == F_210 )
V_10 -> V_38 = V_26 ;
return 0 ;
}
static int F_98 ( struct V_9 * V_10 , struct V_28 V_115 [] ,
bool V_264 )
{
struct V_28 * V_29 ;
int V_6 ;
F_17 ( & V_18 ) ;
for ( V_29 = V_115 ; V_29 -> V_103 [ 0 ] != '\0' ; V_29 ++ ) {
if ( ( V_29 -> V_22 & V_265 ) && ! F_57 ( V_10 ) )
continue;
if ( ( V_29 -> V_22 & V_266 ) && F_193 ( V_10 ) )
continue;
if ( ( V_29 -> V_22 & V_267 ) && ! F_11 ( V_10 ) )
continue;
if ( ( V_29 -> V_22 & V_268 ) && F_11 ( V_10 ) )
continue;
if ( V_264 ) {
V_6 = F_229 ( V_10 , V_29 ) ;
if ( V_6 ) {
F_101 ( L_36 ,
V_269 , V_29 -> V_103 , V_6 ) ;
return V_6 ;
}
} else {
F_95 ( V_10 , V_29 ) ;
}
}
return 0 ;
}
static int F_233 ( struct V_28 * V_115 , bool V_264 )
{
F_133 ( V_270 ) ;
struct V_15 * V_16 = V_115 [ 0 ] . V_16 ;
struct V_9 * V_19 = & V_16 -> V_19 -> V_10 ;
struct V_11 * V_39 ;
int V_6 = 0 ;
F_17 ( & V_18 ) ;
F_199 (css, cgroup_css(root, ss)) {
struct V_9 * V_10 = V_39 -> V_9 ;
if ( F_18 ( V_10 ) )
continue;
V_6 = F_98 ( V_10 , V_115 , V_264 ) ;
if ( V_6 )
break;
}
if ( V_264 && ! V_6 )
F_107 ( V_19 -> V_26 ) ;
return V_6 ;
}
static void F_234 ( struct V_28 * V_115 )
{
struct V_28 * V_29 ;
for ( V_29 = V_115 ; V_29 -> V_103 [ 0 ] != '\0' ; V_29 ++ ) {
if ( V_29 -> V_271 && V_29 -> V_271 != V_272 )
F_38 ( V_29 -> V_263 ) ;
V_29 -> V_263 = NULL ;
V_29 -> V_16 = NULL ;
}
}
static int F_235 ( struct V_15 * V_16 , struct V_28 * V_115 )
{
struct V_28 * V_29 ;
for ( V_29 = V_115 ; V_29 -> V_103 [ 0 ] != '\0' ; V_29 ++ ) {
struct V_273 * V_263 ;
F_102 ( V_29 -> V_16 || V_29 -> V_263 ) ;
if ( V_29 -> F_216 )
V_263 = & V_274 ;
else
V_263 = & V_275 ;
if ( V_29 -> V_271 && V_29 -> V_271 != V_272 ) {
V_263 = F_236 ( V_263 , sizeof( * V_263 ) , V_73 ) ;
if ( ! V_263 ) {
F_234 ( V_115 ) ;
return - V_74 ;
}
V_263 -> V_276 = V_29 -> V_271 ;
}
V_29 -> V_263 = V_263 ;
V_29 -> V_16 = V_16 ;
}
return 0 ;
}
static int F_237 ( struct V_28 * V_115 )
{
F_17 ( & V_18 ) ;
if ( ! V_115 || ! V_115 [ 0 ] . V_16 )
return - V_147 ;
F_32 ( & V_115 -> V_277 ) ;
F_233 ( V_115 , false ) ;
F_234 ( V_115 ) ;
return 0 ;
}
int F_238 ( struct V_28 * V_115 )
{
int V_6 ;
F_76 ( & V_18 ) ;
V_6 = F_237 ( V_115 ) ;
F_79 ( & V_18 ) ;
return V_6 ;
}
int F_239 ( struct V_15 * V_16 , struct V_28 * V_115 )
{
int V_6 ;
if ( V_16 -> V_146 )
return 0 ;
if ( ! V_115 || V_115 [ 0 ] . V_103 [ 0 ] == '\0' )
return 0 ;
V_6 = F_235 ( V_16 , V_115 ) ;
if ( V_6 )
return V_6 ;
F_76 ( & V_18 ) ;
F_60 ( & V_115 -> V_277 , & V_16 -> V_115 ) ;
V_6 = F_233 ( V_115 , true ) ;
if ( V_6 )
F_237 ( V_115 ) ;
F_79 ( & V_18 ) ;
return V_6 ;
}
static int F_240 ( const struct V_9 * V_10 )
{
int V_71 = 0 ;
struct V_45 * V_46 ;
F_62 ( & V_35 ) ;
F_66 (link, &cgrp->cset_links, cset_link)
V_71 += F_77 ( & V_46 -> V_43 -> V_49 ) ;
F_63 ( & V_35 ) ;
return V_71 ;
}
struct V_11 * F_99 ( struct V_11 * V_278 ,
struct V_11 * V_14 )
{
struct V_11 * V_68 ;
F_241 () ;
if ( ! V_278 ) {
V_68 = F_242 ( V_14 -> V_92 . V_68 , struct V_11 , V_162 ) ;
} else if ( F_243 ( ! ( V_278 -> V_22 & V_279 ) ) ) {
V_68 = F_242 ( V_278 -> V_162 . V_68 , struct V_11 , V_162 ) ;
} else {
F_244 (next, &parent->children, sibling)
if ( V_68 -> V_280 > V_278 -> V_280 )
break;
}
if ( & V_68 -> V_162 != & V_14 -> V_92 )
return V_68 ;
return NULL ;
}
struct V_11 *
F_245 ( struct V_11 * V_278 ,
struct V_11 * V_19 )
{
struct V_11 * V_68 ;
F_241 () ;
if ( ! V_278 )
return V_19 ;
V_68 = F_99 ( NULL , V_278 ) ;
if ( V_68 )
return V_68 ;
while ( V_278 != V_19 ) {
V_68 = F_99 ( V_278 , V_278 -> V_14 ) ;
if ( V_68 )
return V_68 ;
V_278 = V_278 -> V_14 ;
}
return NULL ;
}
struct V_11 *
F_246 ( struct V_11 * V_278 )
{
struct V_11 * V_281 , * V_282 ;
F_241 () ;
do {
V_281 = V_278 ;
V_278 = NULL ;
F_247 (tmp, last)
V_278 = V_282 ;
} while ( V_278 );
return V_281 ;
}
static struct V_11 *
F_248 ( struct V_11 * V_278 )
{
struct V_11 * V_281 ;
do {
V_281 = V_278 ;
V_278 = F_99 ( NULL , V_278 ) ;
} while ( V_278 );
return V_281 ;
}
struct V_11 *
F_249 ( struct V_11 * V_278 ,
struct V_11 * V_19 )
{
struct V_11 * V_68 ;
F_241 () ;
if ( ! V_278 )
return F_248 ( V_19 ) ;
if ( V_278 == V_19 )
return NULL ;
V_68 = F_99 ( V_278 , V_278 -> V_14 ) ;
if ( V_68 )
return F_248 ( V_68 ) ;
return V_278 -> V_14 ;
}
bool F_151 ( struct V_11 * V_39 )
{
struct V_11 * V_241 ;
bool V_6 = false ;
F_169 () ;
F_247 (child, css) {
if ( V_241 -> V_22 & V_23 ) {
V_6 = true ;
break;
}
}
F_176 () ;
return V_6 ;
}
static void F_250 ( struct V_283 * V_284 )
{
struct V_60 * V_285 = V_284 -> V_286 ;
struct V_45 * V_46 ;
struct V_42 * V_43 ;
do {
V_285 = V_285 -> V_68 ;
if ( V_285 == V_284 -> V_287 ) {
V_284 -> V_286 = NULL ;
return;
}
if ( V_284 -> V_16 ) {
V_43 = F_12 ( V_285 , struct V_42 ,
V_50 [ V_284 -> V_16 -> V_8 ] ) ;
} else {
V_46 = F_48 ( V_285 , struct V_45 , V_53 ) ;
V_43 = V_46 -> V_43 ;
}
} while ( F_35 ( & V_43 -> V_78 ) && F_35 ( & V_43 -> V_79 ) );
V_284 -> V_286 = V_285 ;
if ( ! F_35 ( & V_43 -> V_78 ) )
V_284 -> V_288 = V_43 -> V_78 . V_68 ;
else
V_284 -> V_288 = V_43 -> V_79 . V_68 ;
V_284 -> V_289 = & V_43 -> V_78 ;
V_284 -> V_290 = & V_43 -> V_79 ;
}
void F_251 ( struct V_11 * V_39 ,
struct V_283 * V_284 )
__acquires( V_35 )
{
F_73 ( ! V_156 ) ;
F_62 ( & V_35 ) ;
V_284 -> V_16 = V_39 -> V_16 ;
if ( V_284 -> V_16 )
V_284 -> V_286 = & V_39 -> V_9 -> V_84 [ V_39 -> V_16 -> V_8 ] ;
else
V_284 -> V_286 = & V_39 -> V_9 -> V_55 ;
V_284 -> V_287 = V_284 -> V_286 ;
F_250 ( V_284 ) ;
}
struct V_97 * F_252 ( struct V_283 * V_284 )
{
struct V_97 * V_95 ;
struct V_60 * V_285 = V_284 -> V_288 ;
if ( ! V_284 -> V_286 )
return NULL ;
V_95 = F_48 ( V_285 , struct V_97 , V_158 ) ;
V_285 = V_285 -> V_68 ;
if ( V_285 == V_284 -> V_289 )
V_285 = V_284 -> V_290 -> V_68 ;
if ( V_285 == V_284 -> V_290 )
F_250 ( V_284 ) ;
else
V_284 -> V_288 = V_285 ;
return V_95 ;
}
void F_253 ( struct V_283 * V_284 )
__releases( V_35 )
{
F_63 ( & V_35 ) ;
}
int F_254 ( struct V_9 * V_291 , struct V_9 * V_232 )
{
F_133 ( V_200 ) ;
struct V_45 * V_46 ;
struct V_283 V_284 ;
struct V_97 * V_98 ;
int V_6 ;
F_76 ( & V_18 ) ;
F_62 ( & V_35 ) ;
F_66 (link, &from->cset_links, cset_link)
F_164 ( V_46 -> V_43 , V_291 , & V_200 ) ;
F_63 ( & V_35 ) ;
V_6 = F_165 ( V_291 , & V_200 ) ;
if ( V_6 )
goto V_292;
do {
F_251 ( & V_232 -> V_13 , & V_284 ) ;
V_98 = F_252 ( & V_284 ) ;
if ( V_98 )
F_179 ( V_98 ) ;
F_253 ( & V_284 ) ;
if ( V_98 ) {
V_6 = F_167 ( V_291 , V_98 , false ) ;
F_183 ( V_98 ) ;
}
} while ( V_98 && ! V_6 );
V_292:
F_162 ( & V_200 ) ;
F_79 ( & V_18 ) ;
return V_6 ;
}
static void * F_255 ( int V_71 )
{
if ( F_256 ( V_71 ) )
return F_257 ( V_71 * sizeof( T_6 ) ) ;
else
return F_258 ( V_71 * sizeof( T_6 ) , V_73 ) ;
}
static void F_259 ( void * V_154 )
{
if ( F_260 ( V_154 ) )
F_261 ( V_154 ) ;
else
F_38 ( V_154 ) ;
}
static void F_262 ( struct V_9 * V_10 )
{
struct V_293 * V_285 , * V_294 ;
F_76 ( & V_10 -> V_165 ) ;
F_34 (l, tmp_l, &cgrp->pidlists, links)
F_263 ( V_295 , & V_285 -> V_296 , 0 ) ;
F_79 ( & V_10 -> V_165 ) ;
F_264 ( V_295 ) ;
F_47 ( ! F_35 ( & V_10 -> V_164 ) ) ;
}
static void F_265 ( struct V_297 * V_298 )
{
struct V_299 * V_300 = F_266 ( V_298 ) ;
struct V_293 * V_285 = F_12 ( V_300 , struct V_293 ,
V_296 ) ;
struct V_293 * V_301 = NULL ;
F_76 ( & V_285 -> V_302 -> V_165 ) ;
if ( ! F_267 ( V_300 ) ) {
F_32 ( & V_285 -> V_303 ) ;
F_259 ( V_285 -> V_304 ) ;
F_268 ( V_285 -> V_40 . V_305 ) ;
V_301 = V_285 ;
}
F_79 ( & V_285 -> V_302 -> V_165 ) ;
F_38 ( V_301 ) ;
}
static int F_269 ( T_6 * V_304 , int V_306 )
{
int V_307 , V_308 = 1 ;
if ( V_306 == 0 || V_306 == 1 )
return V_306 ;
for ( V_307 = 1 ; V_307 < V_306 ; V_307 ++ ) {
while ( V_304 [ V_307 ] == V_304 [ V_307 - 1 ] ) {
V_307 ++ ;
if ( V_307 == V_306 )
goto V_309;
}
V_304 [ V_308 ] = V_304 [ V_307 ] ;
V_308 ++ ;
}
V_309:
return V_308 ;
}
static T_6 F_270 ( T_6 V_219 )
{
unsigned V_310 = V_219 & 0x55555555 ;
unsigned V_311 = V_219 & 0xAAAAAAAA ;
return ( V_310 << 1 ) | ( V_311 >> 1 ) ;
}
static T_6 F_271 ( struct V_9 * V_10 , T_6 V_219 )
{
if ( F_193 ( V_10 ) )
return F_270 ( V_219 ) ;
else
return V_219 ;
}
static int F_272 ( const void * V_310 , const void * V_311 )
{
return * ( T_6 * ) V_310 - * ( T_6 * ) V_311 ;
}
static int F_273 ( const void * V_310 , const void * V_311 )
{
return F_270 ( * ( T_6 * ) V_310 ) - F_270 ( * ( T_6 * ) V_311 ) ;
}
static struct V_293 * F_274 ( struct V_9 * V_10 ,
enum V_312 type )
{
struct V_293 * V_285 ;
struct V_313 * V_305 = F_275 ( V_151 ) ;
F_17 ( & V_10 -> V_165 ) ;
F_66 (l, &cgrp->pidlists, links)
if ( V_285 -> V_40 . type == type && V_285 -> V_40 . V_305 == V_305 )
return V_285 ;
return NULL ;
}
static struct V_293 * F_276 ( struct V_9 * V_10 ,
enum V_312 type )
{
struct V_293 * V_285 ;
F_17 ( & V_10 -> V_165 ) ;
V_285 = F_274 ( V_10 , type ) ;
if ( V_285 )
return V_285 ;
V_285 = F_54 ( sizeof( struct V_293 ) , V_73 ) ;
if ( ! V_285 )
return V_285 ;
F_277 ( & V_285 -> V_296 , F_265 ) ;
V_285 -> V_40 . type = type ;
V_285 -> V_40 . V_305 = F_278 ( F_275 ( V_151 ) ) ;
V_285 -> V_302 = V_10 ;
F_55 ( & V_285 -> V_303 , & V_10 -> V_164 ) ;
return V_285 ;
}
static int F_279 ( struct V_9 * V_10 , enum V_312 type ,
struct V_293 * * V_314 )
{
T_6 * V_315 ;
int V_306 ;
int V_219 , V_316 = 0 ;
struct V_283 V_284 ;
struct V_97 * V_197 ;
struct V_293 * V_285 ;
F_17 ( & V_10 -> V_165 ) ;
V_306 = F_240 ( V_10 ) ;
V_315 = F_255 ( V_306 ) ;
if ( ! V_315 )
return - V_74 ;
F_251 ( & V_10 -> V_13 , & V_284 ) ;
while ( ( V_197 = F_252 ( & V_284 ) ) ) {
if ( F_280 ( V_316 == V_306 ) )
break;
if ( type == V_317 )
V_219 = F_281 ( V_197 ) ;
else
V_219 = F_282 ( V_197 ) ;
if ( V_219 > 0 )
V_315 [ V_316 ++ ] = V_219 ;
}
F_253 ( & V_284 ) ;
V_306 = V_316 ;
if ( F_193 ( V_10 ) )
F_283 ( V_315 , V_306 , sizeof( T_6 ) , F_273 , NULL ) ;
else
F_283 ( V_315 , V_306 , sizeof( T_6 ) , F_272 , NULL ) ;
if ( type == V_317 )
V_306 = F_269 ( V_315 , V_306 ) ;
V_285 = F_276 ( V_10 , type ) ;
if ( ! V_285 ) {
F_79 ( & V_10 -> V_165 ) ;
F_259 ( V_315 ) ;
return - V_74 ;
}
F_259 ( V_285 -> V_304 ) ;
V_285 -> V_304 = V_315 ;
V_285 -> V_306 = V_306 ;
* V_314 = V_285 ;
return 0 ;
}
int F_284 ( struct V_318 * V_319 , struct V_178 * V_178 )
{
struct V_113 * V_26 = F_285 ( V_178 ) ;
struct V_9 * V_10 ;
struct V_283 V_284 ;
struct V_97 * V_197 ;
if ( V_178 -> V_320 -> V_321 != & V_322 || ! V_26 ||
F_91 ( V_26 ) != V_114 )
return - V_140 ;
F_76 ( & V_18 ) ;
F_169 () ;
V_10 = F_286 ( V_26 -> V_27 ) ;
if ( ! V_10 || F_18 ( V_10 ) ) {
F_176 () ;
F_79 ( & V_18 ) ;
return - V_147 ;
}
F_176 () ;
F_251 ( & V_10 -> V_13 , & V_284 ) ;
while ( ( V_197 = F_252 ( & V_284 ) ) ) {
switch ( V_197 -> V_323 ) {
case V_324 :
V_319 -> V_325 ++ ;
break;
case V_326 :
V_319 -> V_327 ++ ;
break;
case V_244 :
V_319 -> V_328 ++ ;
break;
case V_329 :
V_319 -> V_330 ++ ;
break;
default:
if ( F_287 ( V_197 ) )
V_319 -> V_331 ++ ;
break;
}
}
F_253 ( & V_284 ) ;
F_79 ( & V_18 ) ;
return 0 ;
}
static void * F_288 ( struct V_124 * V_332 , T_5 * V_278 )
{
struct V_24 * V_25 = V_332 -> V_333 ;
struct V_9 * V_10 = F_190 ( V_332 ) -> V_9 ;
struct V_293 * V_285 ;
enum V_312 type = F_215 ( V_332 ) -> V_333 ;
int V_334 = 0 , V_219 = * V_278 ;
int * V_335 , V_6 ;
F_76 ( & V_10 -> V_165 ) ;
if ( V_25 -> V_27 )
V_25 -> V_27 = F_274 ( V_10 , type ) ;
if ( ! V_25 -> V_27 ) {
V_6 = F_279 ( V_10 , type ,
(struct V_293 * * ) & V_25 -> V_27 ) ;
if ( V_6 )
return F_147 ( V_6 ) ;
}
V_285 = V_25 -> V_27 ;
if ( V_219 ) {
int V_4 = V_285 -> V_306 ;
while ( V_334 < V_4 ) {
int V_336 = ( V_334 + V_4 ) / 2 ;
if ( F_271 ( V_10 , V_285 -> V_304 [ V_336 ] ) == V_219 ) {
V_334 = V_336 ;
break;
} else if ( F_271 ( V_10 , V_285 -> V_304 [ V_336 ] ) <= V_219 )
V_334 = V_336 + 1 ;
else
V_4 = V_336 ;
}
}
if ( V_334 >= V_285 -> V_306 )
return NULL ;
V_335 = V_285 -> V_304 + V_334 ;
* V_278 = F_271 ( V_10 , * V_335 ) ;
return V_335 ;
}
static void F_289 ( struct V_124 * V_332 , void * V_235 )
{
struct V_24 * V_25 = V_332 -> V_333 ;
struct V_293 * V_285 = V_25 -> V_27 ;
if ( V_285 )
F_263 ( V_295 , & V_285 -> V_296 ,
V_337 ) ;
F_79 ( & F_190 ( V_332 ) -> V_9 -> V_165 ) ;
}
static void * F_290 ( struct V_124 * V_332 , void * V_235 , T_5 * V_278 )
{
struct V_24 * V_25 = V_332 -> V_333 ;
struct V_293 * V_285 = V_25 -> V_27 ;
T_6 * V_154 = V_235 ;
T_6 * V_4 = V_285 -> V_304 + V_285 -> V_306 ;
V_154 ++ ;
if ( V_154 >= V_4 ) {
return NULL ;
} else {
* V_278 = F_271 ( F_190 ( V_332 ) -> V_9 , * V_154 ) ;
return V_154 ;
}
}
static int F_291 ( struct V_124 * V_332 , void * V_235 )
{
return F_109 ( V_332 , L_29 , * ( int * ) V_235 ) ;
}
static T_7 F_292 ( struct V_11 * V_39 ,
struct V_28 * V_29 )
{
return F_24 ( V_39 -> V_9 ) ;
}
static int F_293 ( struct V_11 * V_39 ,
struct V_28 * V_29 , T_7 V_338 )
{
F_294 ( V_32 , & V_39 -> V_9 -> V_22 ) ;
if ( V_338 )
F_36 ( V_33 , & V_39 -> V_9 -> V_22 ) ;
else
F_294 ( V_33 , & V_39 -> V_9 -> V_22 ) ;
return 0 ;
}
static T_7 F_295 ( struct V_11 * V_39 ,
struct V_28 * V_29 )
{
return F_25 ( V_130 , & V_39 -> V_9 -> V_22 ) ;
}
static int F_296 ( struct V_11 * V_39 ,
struct V_28 * V_29 , T_7 V_338 )
{
if ( V_338 )
F_36 ( V_130 , & V_39 -> V_9 -> V_22 ) ;
else
F_294 ( V_130 , & V_39 -> V_9 -> V_22 ) ;
return 0 ;
}
static int F_100 ( struct V_9 * V_10 , unsigned int V_20 )
{
struct V_15 * V_16 ;
int V_41 , V_6 = 0 ;
F_29 (ss, i) {
struct V_28 * V_115 ;
if ( ! ( V_20 & ( 1 << V_41 ) ) )
continue;
F_66 (cfts, &ss->cfts, node) {
V_6 = F_98 ( V_10 , V_115 , true ) ;
if ( V_6 < 0 )
goto V_208;
}
}
return 0 ;
V_208:
F_97 ( V_10 , V_20 ) ;
return V_6 ;
}
static void F_297 ( struct V_297 * V_298 )
{
struct V_11 * V_39 =
F_12 ( V_298 , struct V_11 , V_339 ) ;
struct V_9 * V_10 = V_39 -> V_9 ;
if ( V_39 -> V_16 ) {
if ( V_39 -> V_14 )
F_89 ( V_39 -> V_14 ) ;
V_39 -> V_16 -> V_340 ( V_39 ) ;
F_88 ( V_10 ) ;
} else {
F_298 ( & V_10 -> V_19 -> V_91 ) ;
F_262 ( V_10 ) ;
if ( F_11 ( V_10 ) ) {
F_88 ( F_11 ( V_10 ) ) ;
F_299 ( V_10 -> V_26 ) ;
F_38 ( V_10 ) ;
} else {
F_75 ( V_10 -> V_19 ) ;
}
}
}
static void F_300 ( struct V_56 * V_56 )
{
struct V_11 * V_39 =
F_12 ( V_56 , struct V_11 , V_56 ) ;
F_301 ( & V_39 -> V_339 , F_297 ) ;
F_302 ( V_341 , & V_39 -> V_339 ) ;
}
static void F_303 ( struct V_297 * V_298 )
{
struct V_11 * V_39 =
F_12 ( V_298 , struct V_11 , V_339 ) ;
struct V_15 * V_16 = V_39 -> V_16 ;
struct V_9 * V_10 = V_39 -> V_9 ;
F_76 ( & V_18 ) ;
V_39 -> V_22 |= V_279 ;
F_304 ( & V_39 -> V_162 ) ;
if ( V_16 ) {
F_9 ( & V_16 -> V_342 , V_39 -> V_8 ) ;
} else {
F_9 ( & V_10 -> V_19 -> V_90 , V_10 -> V_8 ) ;
V_10 -> V_8 = - 1 ;
}
F_79 ( & V_18 ) ;
F_305 ( & V_39 -> V_56 , F_300 ) ;
}
static void V_170 ( struct V_343 * V_344 )
{
struct V_11 * V_39 =
F_12 ( V_344 , struct V_11 , V_169 ) ;
F_301 ( & V_39 -> V_339 , F_303 ) ;
F_302 ( V_341 , & V_39 -> V_339 ) ;
}
static void F_306 ( struct V_11 * V_39 ,
struct V_15 * V_16 , struct V_9 * V_10 )
{
F_17 ( & V_18 ) ;
F_86 ( V_10 ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_9 = V_10 ;
V_39 -> V_16 = V_16 ;
F_53 ( & V_39 -> V_162 ) ;
F_53 ( & V_39 -> V_92 ) ;
V_39 -> V_280 = V_345 ++ ;
if ( F_11 ( V_10 ) ) {
V_39 -> V_14 = F_13 ( F_11 ( V_10 ) , V_16 ) ;
F_87 ( V_39 -> V_14 ) ;
}
F_47 ( F_13 ( V_10 , V_16 ) ) ;
}
static int F_307 ( struct V_11 * V_39 )
{
struct V_15 * V_16 = V_39 -> V_16 ;
int V_6 = 0 ;
F_17 ( & V_18 ) ;
if ( V_16 -> V_346 )
V_6 = V_16 -> V_346 ( V_39 ) ;
if ( ! V_6 ) {
V_39 -> V_22 |= V_23 ;
F_104 ( V_39 -> V_9 -> V_17 [ V_16 -> V_8 ] , V_39 ) ;
}
return V_6 ;
}
static void F_308 ( struct V_11 * V_39 )
{
struct V_15 * V_16 = V_39 -> V_16 ;
F_17 ( & V_18 ) ;
if ( ! ( V_39 -> V_22 & V_23 ) )
return;
if ( V_16 -> V_347 )
V_16 -> V_347 ( V_39 ) ;
V_39 -> V_22 &= ~ V_23 ;
F_103 ( V_39 -> V_9 -> V_17 [ V_16 -> V_8 ] , NULL ) ;
F_309 ( & V_39 -> V_9 -> V_166 ) ;
}
static int F_208 ( struct V_9 * V_10 , struct V_15 * V_16 )
{
struct V_9 * V_14 = F_11 ( V_10 ) ;
struct V_11 * V_12 = F_13 ( V_14 , V_16 ) ;
struct V_11 * V_39 ;
int V_208 ;
F_17 ( & V_18 ) ;
V_39 = V_16 -> V_348 ( V_12 ) ;
if ( F_136 ( V_39 ) )
return F_137 ( V_39 ) ;
F_306 ( V_39 , V_16 , V_10 ) ;
V_208 = F_134 ( & V_39 -> V_169 , V_170 ) ;
if ( V_208 )
goto V_349;
V_208 = F_1 ( & V_16 -> V_342 , NULL , 2 , 0 , V_167 ) ;
if ( V_208 < 0 )
goto V_350;
V_39 -> V_8 = V_208 ;
V_208 = F_100 ( V_10 , 1 << V_16 -> V_8 ) ;
if ( V_208 )
goto V_351;
F_310 ( & V_39 -> V_162 , & V_12 -> V_92 ) ;
F_7 ( & V_16 -> V_342 , V_39 , V_39 -> V_8 ) ;
V_208 = F_307 ( V_39 ) ;
if ( V_208 )
goto V_352;
if ( V_16 -> V_353 && ! V_16 -> V_354 &&
F_11 ( V_14 ) ) {
F_101 ( L_37 ,
V_151 -> V_152 , V_151 -> V_219 , V_16 -> V_103 ) ;
if ( ! strcmp ( V_16 -> V_103 , L_38 ) )
F_101 ( L_39 ) ;
V_16 -> V_354 = true ;
}
return 0 ;
V_352:
F_304 ( & V_39 -> V_162 ) ;
F_97 ( V_39 -> V_9 , 1 << V_39 -> V_16 -> V_8 ) ;
V_351:
F_9 ( & V_16 -> V_342 , V_39 -> V_8 ) ;
V_350:
F_138 ( & V_39 -> V_169 ) ;
V_349:
F_305 ( & V_39 -> V_56 , F_300 ) ;
return V_208 ;
}
static int F_311 ( struct V_113 * V_355 , const char * V_103 ,
T_2 V_104 )
{
struct V_9 * V_14 , * V_10 ;
struct V_69 * V_19 ;
struct V_15 * V_16 ;
struct V_113 * V_26 ;
int V_48 , V_6 ;
V_14 = F_93 ( V_355 ) ;
if ( ! V_14 )
return - V_220 ;
V_19 = V_14 -> V_19 ;
V_10 = F_54 ( sizeof( * V_10 ) , V_73 ) ;
if ( ! V_10 ) {
V_6 = - V_74 ;
goto V_150;
}
V_6 = F_134 ( & V_10 -> V_13 . V_169 , V_170 ) ;
if ( V_6 )
goto V_356;
V_10 -> V_8 = F_1 ( & V_19 -> V_90 , NULL , 2 , 0 , V_167 ) ;
if ( V_10 -> V_8 < 0 ) {
V_6 = - V_74 ;
goto V_357;
}
F_127 ( V_10 ) ;
V_10 -> V_13 . V_14 = & V_14 -> V_13 ;
V_10 -> V_19 = V_19 ;
if ( F_24 ( V_14 ) )
F_36 ( V_33 , & V_10 -> V_22 ) ;
if ( F_25 ( V_130 , & V_14 -> V_22 ) )
F_36 ( V_130 , & V_10 -> V_22 ) ;
V_26 = F_312 ( V_14 -> V_26 , V_103 , V_104 , V_10 ) ;
if ( F_136 ( V_26 ) ) {
V_6 = F_137 ( V_26 ) ;
goto V_358;
}
V_10 -> V_26 = V_26 ;
F_313 ( V_26 ) ;
V_10 -> V_13 . V_280 = V_345 ++ ;
F_310 ( & V_10 -> V_13 . V_162 , & F_11 ( V_10 ) -> V_13 . V_92 ) ;
F_45 ( & V_19 -> V_91 ) ;
F_86 ( V_14 ) ;
F_7 ( & V_19 -> V_90 , V_10 , V_10 -> V_8 ) ;
V_6 = F_224 ( V_26 ) ;
if ( V_6 )
goto V_359;
V_6 = F_98 ( V_10 , V_175 , true ) ;
if ( V_6 )
goto V_359;
F_29 (ss, ssid) {
if ( V_14 -> V_21 & ( 1 << V_48 ) ) {
V_6 = F_208 ( V_10 , V_16 ) ;
if ( V_6 )
goto V_359;
}
}
if ( ! F_57 ( V_10 ) )
V_10 -> V_21 = V_14 -> V_21 ;
F_107 ( V_26 ) ;
V_6 = 0 ;
goto V_150;
V_358:
F_9 ( & V_19 -> V_90 , V_10 -> V_8 ) ;
V_357:
F_138 ( & V_10 -> V_13 . V_169 ) ;
V_356:
F_38 ( V_10 ) ;
V_150:
F_90 ( V_355 ) ;
return V_6 ;
V_359:
F_314 ( V_10 ) ;
goto V_150;
}
static void F_315 ( struct V_297 * V_298 )
{
struct V_11 * V_39 =
F_12 ( V_298 , struct V_11 , V_339 ) ;
F_76 ( & V_18 ) ;
F_308 ( V_39 ) ;
F_79 ( & V_18 ) ;
F_89 ( V_39 ) ;
}
static void F_316 ( struct V_343 * V_344 )
{
struct V_11 * V_39 =
F_12 ( V_344 , struct V_11 , V_169 ) ;
F_301 ( & V_39 -> V_339 , F_315 ) ;
F_302 ( V_341 , & V_39 -> V_339 ) ;
}
static void F_209 ( struct V_11 * V_39 )
{
F_17 ( & V_18 ) ;
F_97 ( V_39 -> V_9 , 1 << V_39 -> V_16 -> V_8 ) ;
F_87 ( V_39 ) ;
F_317 ( & V_39 -> V_169 , F_316 ) ;
}
static int F_314 ( struct V_9 * V_10 )
__releases( &cgroup_mutex
static int F_318 ( struct V_113 * V_26 )
{
struct V_9 * V_10 ;
int V_6 = 0 ;
V_10 = F_93 ( V_26 ) ;
if ( ! V_10 )
return 0 ;
F_86 ( V_10 ) ;
V_6 = F_314 ( V_10 ) ;
F_90 ( V_26 ) ;
if ( ! V_6 )
F_103 ( * ( void V_360 V_361 * * ) & V_26 -> V_27 , NULL ) ;
F_88 ( V_10 ) ;
return V_6 ;
}
static void T_8 F_319 ( struct V_15 * V_16 , bool V_362 )
{
struct V_11 * V_39 ;
F_320 ( V_363 L_40 , V_16 -> V_103 ) ;
F_76 ( & V_18 ) ;
F_131 ( & V_16 -> V_342 ) ;
F_53 ( & V_16 -> V_115 ) ;
V_16 -> V_19 = & V_93 ;
V_39 = V_16 -> V_348 ( F_13 ( & V_93 . V_10 , V_16 ) ) ;
F_47 ( F_136 ( V_39 ) ) ;
F_306 ( V_39 , V_16 , & V_93 . V_10 ) ;
V_39 -> V_22 |= V_364 ;
if ( V_362 ) {
V_39 -> V_8 = 1 ;
} else {
V_39 -> V_8 = F_1 ( & V_16 -> V_342 , V_39 , 1 , 2 , V_73 ) ;
F_47 ( V_39 -> V_8 < 0 ) ;
}
V_96 . V_17 [ V_16 -> V_8 ] = V_39 ;
V_365 |= V_16 -> V_366 || V_16 -> exit ;
F_47 ( ! F_35 ( & V_367 . V_78 ) ) ;
F_47 ( F_307 ( V_39 ) ) ;
F_79 ( & V_18 ) ;
}
int T_8 F_321 ( void )
{
static struct V_132 T_9 V_133 =
{ . V_22 = V_126 } ;
struct V_15 * V_16 ;
int V_41 ;
F_130 ( & V_93 , & V_133 ) ;
V_93 . V_10 . V_13 . V_22 |= V_364 ;
F_103 ( V_367 . V_199 , & V_96 ) ;
F_29 (ss, i) {
F_201 ( ! V_16 -> V_348 || ! V_16 -> V_340 || V_16 -> V_103 || V_16 -> V_8 ,
L_41 ,
V_41 , V_368 [ V_41 ] , V_16 -> V_348 , V_16 -> V_340 ,
V_16 -> V_8 , V_16 -> V_103 ) ;
F_201 ( strlen ( V_368 [ V_41 ] ) > V_369 ,
L_42 , V_368 [ V_41 ] ) ;
V_16 -> V_8 = V_41 ;
V_16 -> V_103 = V_368 [ V_41 ] ;
if ( V_16 -> V_370 )
F_319 ( V_16 , true ) ;
}
return 0 ;
}
int T_8 F_322 ( void )
{
struct V_15 * V_16 ;
unsigned long V_40 ;
int V_48 , V_208 ;
F_47 ( F_235 ( NULL , V_175 ) ) ;
F_76 ( & V_18 ) ;
V_40 = F_28 ( V_96 . V_17 ) ;
F_67 ( V_83 , & V_96 . V_51 , V_40 ) ;
F_47 ( F_132 ( & V_93 , 0 ) ) ;
F_79 ( & V_18 ) ;
F_29 (ss, ssid) {
if ( V_16 -> V_370 ) {
struct V_11 * V_39 =
V_96 . V_17 [ V_16 -> V_8 ] ;
V_39 -> V_8 = F_1 ( & V_16 -> V_342 , V_39 , 1 , 2 ,
V_73 ) ;
F_47 ( V_39 -> V_8 < 0 ) ;
} else {
F_319 ( V_16 , false ) ;
}
F_60 ( & V_96 . V_50 [ V_48 ] ,
& V_93 . V_10 . V_84 [ V_48 ] ) ;
if ( ! V_16 -> V_146 ) {
V_93 . V_20 |= 1 << V_16 -> V_8 ;
F_102 ( F_239 ( V_16 , V_16 -> V_371 ) ) ;
}
}
V_372 = F_323 ( L_43 , V_373 ) ;
if ( ! V_372 )
return - V_74 ;
V_208 = F_324 ( & V_322 ) ;
if ( V_208 < 0 ) {
F_325 ( V_372 ) ;
return V_208 ;
}
F_326 ( L_44 , 0 , NULL , & V_374 ) ;
return 0 ;
}
static int T_8 F_327 ( void )
{
V_341 = F_328 ( L_45 , 0 , 1 ) ;
F_47 ( ! V_341 ) ;
V_295 = F_328 ( L_46 ,
0 , 1 ) ;
F_47 ( ! V_295 ) ;
return 0 ;
}
int F_329 ( struct V_124 * V_247 , void * V_235 )
{
struct V_219 * V_219 ;
struct V_97 * V_197 ;
char * V_99 , * V_190 ;
int V_233 ;
struct V_69 * V_19 ;
V_233 = - V_74 ;
V_99 = F_258 ( V_144 , V_73 ) ;
if ( ! V_99 )
goto V_168;
V_233 = - V_222 ;
V_219 = V_247 -> V_333 ;
V_197 = F_330 ( V_219 , V_375 ) ;
if ( ! V_197 )
goto V_185;
V_233 = 0 ;
F_76 ( & V_18 ) ;
F_62 ( & V_35 ) ;
F_143 (root) {
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_48 , V_71 = 0 ;
if ( V_19 == & V_93 && ! V_121 )
continue;
F_109 ( V_247 , L_47 , V_19 -> V_89 ) ;
F_29 (ss, ssid)
if ( V_19 -> V_20 & ( 1 << V_48 ) )
F_109 ( V_247 , L_48 , V_71 ++ ? L_11 : L_25 , V_16 -> V_103 ) ;
if ( strlen ( V_19 -> V_103 ) )
F_109 ( V_247 , L_49 , V_71 ? L_11 : L_25 ,
V_19 -> V_103 ) ;
F_191 ( V_247 , ':' ) ;
V_10 = F_82 ( V_197 , V_19 ) ;
V_190 = F_156 ( V_10 , V_99 , V_144 ) ;
if ( ! V_190 ) {
V_233 = - V_376 ;
goto V_150;
}
F_110 ( V_247 , V_190 ) ;
F_191 ( V_247 , '\n' ) ;
}
V_150:
F_63 ( & V_35 ) ;
F_79 ( & V_18 ) ;
F_183 ( V_197 ) ;
V_185:
F_38 ( V_99 ) ;
V_168:
return V_233 ;
}
static int F_331 ( struct V_124 * V_247 , void * V_235 )
{
struct V_15 * V_16 ;
int V_41 ;
F_110 ( V_247 , L_50 ) ;
F_76 ( & V_18 ) ;
F_29 (ss, i)
F_109 ( V_247 , L_51 ,
V_16 -> V_103 , V_16 -> V_19 -> V_89 ,
F_77 ( & V_16 -> V_19 -> V_91 ) , ! V_16 -> V_146 ) ;
F_79 ( & V_18 ) ;
return 0 ;
}
static int F_332 ( struct V_377 * V_377 , struct V_378 * V_378 )
{
return F_333 ( V_378 , F_331 , NULL ) ;
}
void F_334 ( struct V_97 * V_241 )
{
F_103 ( V_241 -> V_199 , & V_96 ) ;
F_53 ( & V_241 -> V_158 ) ;
}
void F_335 ( struct V_97 * V_241 )
{
struct V_15 * V_16 ;
int V_41 ;
if ( V_156 ) {
struct V_42 * V_43 ;
F_42 ( & V_35 ) ;
V_43 = F_83 ( V_151 ) ;
if ( F_35 ( & V_241 -> V_158 ) ) {
F_104 ( V_241 -> V_199 , V_43 ) ;
F_55 ( & V_241 -> V_158 , & V_43 -> V_78 ) ;
F_44 ( V_43 ) ;
}
F_43 ( & V_35 ) ;
}
if ( V_365 ) {
F_29 (ss, i)
if ( V_16 -> V_366 )
V_16 -> V_366 ( V_241 ) ;
}
}
void F_336 ( struct V_97 * V_197 )
{
struct V_15 * V_16 ;
struct V_42 * V_43 ;
bool V_379 = false ;
int V_41 ;
if ( ! F_35 ( & V_197 -> V_158 ) ) {
F_42 ( & V_35 ) ;
F_163 ( & V_197 -> V_158 ) ;
F_43 ( & V_35 ) ;
V_379 = true ;
}
V_43 = F_83 ( V_197 ) ;
F_103 ( V_197 -> V_199 , & V_96 ) ;
if ( V_365 ) {
F_29 (ss, i) {
if ( V_16 -> exit ) {
struct V_11 * V_380 = V_43 -> V_17 [ V_41 ] ;
struct V_11 * V_39 = F_337 ( V_197 , V_41 ) ;
V_16 -> exit ( V_39 , V_380 , V_197 ) ;
}
}
}
if ( V_379 )
F_40 ( V_43 , true ) ;
}
static void F_37 ( struct V_9 * V_10 )
{
if ( F_23 ( V_10 ) && F_35 ( & V_10 -> V_55 ) &&
! F_151 ( & V_10 -> V_13 ) ) {
int V_381 = 0 ;
F_338 ( & V_382 ) ;
if ( ! F_18 ( V_10 ) &&
F_35 ( & V_10 -> V_163 ) ) {
F_55 ( & V_10 -> V_163 , & V_163 ) ;
V_381 = 1 ;
}
F_339 ( & V_382 ) ;
if ( V_381 )
F_340 ( & V_383 ) ;
}
}
static void F_341 ( struct V_297 * V_298 )
{
F_47 ( V_298 != & V_383 ) ;
F_76 ( & V_18 ) ;
F_338 ( & V_382 ) ;
while ( ! F_35 ( & V_163 ) ) {
char * V_384 [ 3 ] , * V_385 [ 3 ] ;
int V_41 ;
char * V_386 = NULL , * V_387 = NULL , * V_190 ;
struct V_9 * V_10 = F_48 ( V_163 . V_68 ,
struct V_9 ,
V_163 ) ;
F_163 ( & V_10 -> V_163 ) ;
F_339 ( & V_382 ) ;
V_386 = F_258 ( V_144 , V_73 ) ;
if ( ! V_386 )
goto V_388;
V_190 = F_156 ( V_10 , V_386 , V_144 ) ;
if ( ! V_190 )
goto V_388;
V_387 = F_342 ( V_10 -> V_19 -> V_129 , V_73 ) ;
if ( ! V_387 )
goto V_388;
V_41 = 0 ;
V_384 [ V_41 ++ ] = V_387 ;
V_384 [ V_41 ++ ] = V_190 ;
V_384 [ V_41 ] = NULL ;
V_41 = 0 ;
V_385 [ V_41 ++ ] = L_52 ;
V_385 [ V_41 ++ ] = L_53 ;
V_385 [ V_41 ] = NULL ;
F_79 ( & V_18 ) ;
F_343 ( V_384 [ 0 ] , V_384 , V_385 , V_389 ) ;
F_76 ( & V_18 ) ;
V_388:
F_38 ( V_386 ) ;
F_38 ( V_387 ) ;
F_338 ( & V_382 ) ;
}
F_339 ( & V_382 ) ;
F_79 ( & V_18 ) ;
}
static int T_8 F_344 ( char * V_390 )
{
struct V_15 * V_16 ;
char * V_134 ;
int V_41 ;
while ( ( V_134 = F_115 ( & V_390 , L_11 ) ) != NULL ) {
if ( ! * V_134 )
continue;
F_29 (ss, i) {
if ( ! strcmp ( V_134 , V_16 -> V_103 ) ) {
V_16 -> V_146 = 1 ;
F_320 ( V_363 L_54
L_55 , V_16 -> V_103 ) ;
break;
}
}
}
return 1 ;
}
struct V_11 * F_345 ( struct V_178 * V_178 ,
struct V_15 * V_16 )
{
struct V_113 * V_26 = F_285 ( V_178 ) ;
struct V_11 * V_39 = NULL ;
struct V_9 * V_10 ;
if ( V_178 -> V_320 -> V_321 != & V_322 || ! V_26 ||
F_91 ( V_26 ) != V_114 )
return F_147 ( - V_391 ) ;
F_169 () ;
V_10 = F_286 ( V_26 -> V_27 ) ;
if ( V_10 )
V_39 = F_13 ( V_10 , V_16 ) ;
if ( ! V_39 || ! F_346 ( V_39 ) )
V_39 = F_147 ( - V_147 ) ;
F_176 () ;
return V_39 ;
}
struct V_11 * F_347 ( int V_8 , struct V_15 * V_16 )
{
F_73 ( ! F_348 () ) ;
return F_349 ( & V_16 -> V_342 , V_8 ) ;
}
static struct V_11 *
F_350 ( struct V_11 * V_12 )
{
struct V_11 * V_39 = F_54 ( sizeof( * V_39 ) , V_73 ) ;
if ( ! V_39 )
return F_147 ( - V_74 ) ;
return V_39 ;
}
static void F_351 ( struct V_11 * V_39 )
{
F_38 ( V_39 ) ;
}
static T_7 F_352 ( struct V_11 * V_39 ,
struct V_28 * V_29 )
{
return F_240 ( V_39 -> V_9 ) ;
}
static T_7 F_353 ( struct V_11 * V_39 ,
struct V_28 * V_29 )
{
return ( T_7 ) ( unsigned long ) V_151 -> V_199 ;
}
static T_7 F_354 ( struct V_11 * V_39 ,
struct V_28 * V_29 )
{
T_7 V_71 ;
F_169 () ;
V_71 = F_77 ( & F_83 ( V_151 ) -> V_49 ) ;
F_176 () ;
return V_71 ;
}
static int F_355 ( struct V_124 * V_125 , void * V_235 )
{
struct V_45 * V_46 ;
struct V_42 * V_43 ;
char * V_392 ;
V_392 = F_258 ( V_393 + 1 , V_73 ) ;
if ( ! V_392 )
return - V_74 ;
F_62 ( & V_35 ) ;
F_169 () ;
V_43 = F_286 ( V_151 -> V_199 ) ;
F_66 (link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_82 = V_46 -> V_10 ;
F_356 ( V_82 , V_392 , V_393 + 1 ) ;
F_109 ( V_125 , L_56 ,
V_82 -> V_19 -> V_89 , V_392 ) ;
}
F_176 () ;
F_63 ( & V_35 ) ;
F_38 ( V_392 ) ;
return 0 ;
}
static int F_357 ( struct V_124 * V_125 , void * V_235 )
{
struct V_11 * V_39 = F_190 ( V_125 ) ;
struct V_45 * V_46 ;
F_62 ( & V_35 ) ;
F_66 (link, &css->cgroup->cset_links, cset_link) {
struct V_42 * V_43 = V_46 -> V_43 ;
struct V_97 * V_98 ;
int V_71 = 0 ;
F_109 ( V_125 , L_57 , V_43 ) ;
F_66 (task, &cset->tasks, cg_list) {
if ( V_71 ++ > V_394 )
goto V_395;
F_109 ( V_125 , L_58 , F_282 ( V_98 ) ) ;
}
F_66 (task, &cset->mg_tasks, cg_list) {
if ( V_71 ++ > V_394 )
goto V_395;
F_109 ( V_125 , L_58 , F_282 ( V_98 ) ) ;
}
continue;
V_395:
F_110 ( V_125 , L_59 ) ;
}
F_63 ( & V_35 ) ;
return 0 ;
}
static T_7 F_358 ( struct V_11 * V_39 , struct V_28 * V_29 )
{
return F_25 ( V_32 , & V_39 -> V_9 -> V_22 ) ;
}
