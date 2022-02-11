static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( V_5 )
return F_2 ( V_3 -> V_6 [ V_5 -> V_7 ] ,
F_3 ( & V_8 ) ||
F_3 ( & V_9 ) ) ;
else
return & V_3 -> V_10 ;
}
static inline bool F_4 ( const struct V_2 * V_3 )
{
return F_5 ( V_11 , & V_3 -> V_12 ) ;
}
struct V_1 * F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_2 * V_3 = V_16 -> V_18 -> V_19 -> V_20 ;
struct V_21 * V_22 = F_7 ( V_14 ) ;
if ( V_22 -> V_5 )
return F_8 ( V_3 -> V_6 [ V_22 -> V_5 -> V_7 ] ) ;
else
return & V_3 -> V_10 ;
}
bool F_9 ( struct V_2 * V_3 , struct V_2 * V_23 )
{
while ( V_3 ) {
if ( V_3 == V_23 )
return true ;
V_3 = V_3 -> V_19 ;
}
return false ;
}
static int F_10 ( const struct V_2 * V_3 )
{
const int V_24 =
( 1 << V_25 ) |
( 1 << V_26 ) ;
return ( V_3 -> V_12 & V_24 ) == V_24 ;
}
static int F_11 ( const struct V_2 * V_3 )
{
return F_5 ( V_26 , & V_3 -> V_12 ) ;
}
static bool F_12 ( struct V_2 * V_3 )
{
F_13 ( & V_9 ) ;
if ( F_4 ( V_3 ) ) {
F_14 ( & V_9 ) ;
return false ;
}
return true ;
}
static unsigned long F_15 ( struct V_1 * V_27 [] )
{
unsigned long V_28 = 0UL ;
struct V_4 * V_5 ;
int V_29 ;
F_16 (ss, i)
V_28 += ( unsigned long ) V_27 [ V_29 ] ;
V_28 = ( V_28 >> 16 ) ^ V_28 ;
return V_28 ;
}
static void F_17 ( struct V_30 * V_31 , bool V_32 )
{
struct V_33 * V_34 , * V_35 ;
F_18 ( & V_36 ) ;
if ( ! F_19 ( & V_31 -> V_37 ) )
return;
F_20 ( & V_31 -> V_38 ) ;
V_39 -- ;
F_21 (link, tmp_link, &cset->cgrp_links, cgrp_link) {
struct V_2 * V_3 = V_34 -> V_3 ;
F_22 ( & V_34 -> V_40 ) ;
F_22 ( & V_34 -> V_41 ) ;
if ( F_23 ( & V_3 -> V_42 ) && F_11 ( V_3 ) ) {
if ( V_32 )
F_24 ( V_25 , & V_3 -> V_12 ) ;
F_25 ( V_3 ) ;
}
F_26 ( V_34 ) ;
}
F_27 ( V_31 , V_43 ) ;
}
static void F_28 ( struct V_30 * V_31 , bool V_32 )
{
if ( F_29 ( & V_31 -> V_37 , - 1 , 1 ) )
return;
F_30 ( & V_36 ) ;
F_17 ( V_31 , V_32 ) ;
F_31 ( & V_36 ) ;
}
static inline void F_32 ( struct V_30 * V_31 )
{
F_33 ( & V_31 -> V_37 ) ;
}
static bool F_34 ( struct V_30 * V_31 ,
struct V_30 * V_44 ,
struct V_2 * V_45 ,
struct V_1 * V_46 [] )
{
struct V_47 * V_48 , * V_49 ;
if ( memcmp ( V_46 , V_31 -> V_6 , sizeof( V_31 -> V_6 ) ) ) {
return false ;
}
V_48 = & V_31 -> V_50 ;
V_49 = & V_44 -> V_50 ;
while ( 1 ) {
struct V_33 * V_51 , * V_52 ;
struct V_2 * V_53 , * V_54 ;
V_48 = V_48 -> V_55 ;
V_49 = V_49 -> V_55 ;
if ( V_48 == & V_31 -> V_50 ) {
F_35 ( V_49 != & V_44 -> V_50 ) ;
break;
} else {
F_35 ( V_49 == & V_44 -> V_50 ) ;
}
V_51 = F_36 ( V_48 , struct V_33 , V_41 ) ;
V_52 = F_36 ( V_49 , struct V_33 , V_41 ) ;
V_53 = V_51 -> V_3 ;
V_54 = V_52 -> V_3 ;
F_35 ( V_53 -> V_56 != V_54 -> V_56 ) ;
if ( V_53 -> V_56 == V_45 -> V_56 ) {
if ( V_53 != V_45 )
return false ;
} else {
if ( V_53 != V_54 )
return false ;
}
}
return true ;
}
static struct V_30 * F_37 ( struct V_30 * V_44 ,
struct V_2 * V_3 ,
struct V_1 * V_46 [] )
{
struct V_57 * V_56 = V_3 -> V_56 ;
struct V_4 * V_5 ;
struct V_30 * V_31 ;
unsigned long V_28 ;
int V_29 ;
F_16 (ss, i) {
if ( V_56 -> V_3 . V_58 & ( 1UL << V_29 ) ) {
V_46 [ V_29 ] = F_1 ( V_3 , V_5 ) ;
} else {
V_46 [ V_29 ] = V_44 -> V_6 [ V_29 ] ;
}
}
V_28 = F_15 ( V_46 ) ;
F_38 (css_set_table, cset, hlist, key) {
if ( ! F_34 ( V_31 , V_44 , V_3 , V_46 ) )
continue;
return V_31 ;
}
return NULL ;
}
static void F_39 ( struct V_47 * V_59 )
{
struct V_33 * V_34 , * V_35 ;
F_21 (link, tmp_link, links_to_free, cset_link) {
F_22 ( & V_34 -> V_40 ) ;
F_26 ( V_34 ) ;
}
}
static int F_40 ( int V_60 , struct V_47 * V_61 )
{
struct V_33 * V_34 ;
int V_29 ;
F_41 ( V_61 ) ;
for ( V_29 = 0 ; V_29 < V_60 ; V_29 ++ ) {
V_34 = F_42 ( sizeof( * V_34 ) , V_62 ) ;
if ( ! V_34 ) {
F_39 ( V_61 ) ;
return - V_63 ;
}
F_43 ( & V_34 -> V_40 , V_61 ) ;
}
return 0 ;
}
static void F_44 ( struct V_47 * V_61 , struct V_30 * V_31 ,
struct V_2 * V_3 )
{
struct V_33 * V_34 ;
F_35 ( F_23 ( V_61 ) ) ;
V_34 = F_45 ( V_61 , struct V_33 , V_40 ) ;
V_34 -> V_31 = V_31 ;
V_34 -> V_3 = V_3 ;
F_46 ( & V_34 -> V_40 , & V_3 -> V_42 ) ;
F_47 ( & V_34 -> V_41 , & V_31 -> V_50 ) ;
}
static struct V_30 * F_48 ( struct V_30 * V_44 ,
struct V_2 * V_3 )
{
struct V_1 * V_46 [ V_64 ] = { } ;
struct V_30 * V_31 ;
struct V_47 V_61 ;
struct V_33 * V_34 ;
unsigned long V_28 ;
F_18 ( & V_9 ) ;
F_49 ( & V_36 ) ;
V_31 = F_37 ( V_44 , V_3 , V_46 ) ;
if ( V_31 )
F_32 ( V_31 ) ;
F_50 ( & V_36 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_42 ( sizeof( * V_31 ) , V_62 ) ;
if ( ! V_31 )
return NULL ;
if ( F_40 ( V_65 , & V_61 ) < 0 ) {
F_26 ( V_31 ) ;
return NULL ;
}
F_51 ( & V_31 -> V_37 , 1 ) ;
F_41 ( & V_31 -> V_50 ) ;
F_41 ( & V_31 -> V_66 ) ;
F_41 ( & V_31 -> V_67 ) ;
F_41 ( & V_31 -> V_68 ) ;
F_41 ( & V_31 -> V_69 ) ;
F_52 ( & V_31 -> V_38 ) ;
memcpy ( V_31 -> V_6 , V_46 , sizeof( V_31 -> V_6 ) ) ;
F_30 ( & V_36 ) ;
F_53 (link, &old_cset->cgrp_links, cgrp_link) {
struct V_2 * V_70 = V_34 -> V_3 ;
if ( V_70 -> V_56 == V_3 -> V_56 )
V_70 = V_3 ;
F_44 ( & V_61 , V_31 , V_70 ) ;
}
F_35 ( ! F_23 ( & V_61 ) ) ;
V_39 ++ ;
V_28 = F_15 ( V_31 -> V_6 ) ;
F_54 ( V_71 , & V_31 -> V_38 , V_28 ) ;
F_31 ( & V_36 ) ;
return V_31 ;
}
static struct V_57 * F_55 ( struct V_72 * V_73 )
{
struct V_2 * V_74 = V_73 -> V_18 -> V_20 ;
return V_74 -> V_56 ;
}
static int F_56 ( struct V_57 * V_56 )
{
int V_7 ;
F_18 ( & V_9 ) ;
V_7 = F_57 ( & V_75 , V_56 , 0 , 0 , V_62 ) ;
if ( V_7 < 0 )
return V_7 ;
V_56 -> V_76 = V_7 ;
return 0 ;
}
static void F_58 ( struct V_57 * V_56 )
{
F_18 ( & V_9 ) ;
if ( V_56 -> V_76 ) {
F_59 ( & V_75 , V_56 -> V_76 ) ;
V_56 -> V_76 = 0 ;
}
}
static void F_60 ( struct V_57 * V_56 )
{
if ( V_56 ) {
F_61 ( V_56 -> V_76 ) ;
F_62 ( & V_56 -> V_77 ) ;
F_26 ( V_56 ) ;
}
}
static void F_63 ( struct V_57 * V_56 )
{
struct V_2 * V_3 = & V_56 -> V_3 ;
struct V_33 * V_34 , * V_35 ;
F_13 ( & V_8 ) ;
F_13 ( & V_9 ) ;
F_35 ( F_64 ( & V_56 -> V_78 ) ) ;
F_35 ( ! F_23 ( & V_3 -> V_79 ) ) ;
F_65 ( & V_80 , V_3 -> V_58 ) ;
F_30 ( & V_36 ) ;
F_21 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_22 ( & V_34 -> V_40 ) ;
F_22 ( & V_34 -> V_41 ) ;
F_26 ( V_34 ) ;
}
F_31 ( & V_36 ) ;
if ( ! F_23 ( & V_56 -> V_81 ) ) {
F_22 ( & V_56 -> V_81 ) ;
V_65 -- ;
}
F_58 ( V_56 ) ;
F_14 ( & V_9 ) ;
F_14 ( & V_8 ) ;
F_66 ( V_56 -> V_73 ) ;
F_60 ( V_56 ) ;
}
static struct V_2 * F_67 ( struct V_30 * V_31 ,
struct V_57 * V_56 )
{
struct V_2 * V_82 = NULL ;
F_18 ( & V_9 ) ;
F_18 ( & V_36 ) ;
if ( V_31 == & V_83 ) {
V_82 = & V_56 -> V_3 ;
} else {
struct V_33 * V_34 ;
F_53 (link, &cset->cgrp_links, cgrp_link) {
struct V_2 * V_70 = V_34 -> V_3 ;
if ( V_70 -> V_56 == V_56 ) {
V_82 = V_70 ;
break;
}
}
}
F_35 ( ! V_82 ) ;
return V_82 ;
}
static struct V_2 * F_68 ( struct V_84 * V_85 ,
struct V_57 * V_56 )
{
return F_67 ( F_69 ( V_85 ) , V_56 ) ;
}
static char * F_70 ( struct V_2 * V_3 , const struct V_21 * V_22 ,
char * V_86 )
{
if ( V_22 -> V_5 && ! ( V_22 -> V_12 & V_87 ) &&
! ( V_3 -> V_56 -> V_12 & V_88 ) )
snprintf ( V_86 , V_89 , L_1 ,
V_22 -> V_5 -> V_90 , V_22 -> V_90 ) ;
else
strncpy ( V_86 , V_22 -> V_90 , V_89 ) ;
return V_86 ;
}
static T_1 F_71 ( const struct V_21 * V_22 )
{
T_1 V_91 = 0 ;
if ( V_22 -> V_91 )
return V_22 -> V_91 ;
if ( V_22 -> V_92 || V_22 -> V_93 || V_22 -> V_94 )
V_91 |= V_95 ;
if ( V_22 -> V_96 || V_22 -> V_97 || V_22 -> V_98 ||
V_22 -> V_99 )
V_91 |= V_100 ;
return V_91 ;
}
static void F_72 ( struct V_101 * V_102 )
{
struct V_2 * V_3 = F_73 ( V_102 , struct V_2 , V_103 ) ;
F_74 ( & V_3 -> V_56 -> V_78 ) ;
F_75 ( V_3 ) ;
if ( V_3 -> V_19 ) {
F_76 ( V_3 -> V_19 ) ;
F_77 ( V_3 -> V_18 ) ;
F_26 ( V_3 ) ;
} else {
F_63 ( V_3 -> V_56 ) ;
}
}
static void F_78 ( struct V_43 * V_104 )
{
struct V_2 * V_3 = F_73 ( V_104 , struct V_2 , V_43 ) ;
F_79 ( & V_3 -> V_103 , F_72 ) ;
F_80 ( V_105 , & V_3 -> V_103 ) ;
}
static void F_81 ( struct V_2 * V_3 )
{
F_61 ( F_4 ( V_3 ) ) ;
F_61 ( F_64 ( & V_3 -> V_106 ) <= 0 ) ;
F_33 ( & V_3 -> V_106 ) ;
}
static void F_76 ( struct V_2 * V_3 )
{
if ( ! F_19 ( & V_3 -> V_106 ) )
return;
if ( F_61 ( V_3 -> V_19 && ! F_4 ( V_3 ) ) )
return;
F_13 ( & V_9 ) ;
F_59 ( & V_3 -> V_56 -> V_77 , V_3 -> V_7 ) ;
F_14 ( & V_9 ) ;
V_3 -> V_7 = - 1 ;
F_82 ( & V_3 -> V_43 , F_78 ) ;
}
static void F_83 ( struct V_2 * V_3 , const struct V_21 * V_22 )
{
char V_90 [ V_89 ] ;
F_18 ( & V_8 ) ;
F_84 ( V_3 -> V_18 , F_70 ( V_3 , V_22 , V_90 ) ) ;
}
static void F_85 ( struct V_2 * V_3 , unsigned long V_58 )
{
struct V_4 * V_5 ;
int V_29 ;
F_16 (ss, i) {
struct V_21 * V_107 ;
if ( ! F_5 ( V_29 , & V_58 ) )
continue;
F_53 (cfts, &ss->cfts, node)
F_86 ( V_3 , V_107 , false ) ;
}
}
static int F_65 ( struct V_57 * V_108 ,
unsigned long V_109 )
{
struct V_4 * V_5 ;
int V_110 , V_111 ;
F_18 ( & V_8 ) ;
F_18 ( & V_9 ) ;
F_16 (ss, ssid) {
if ( ! ( V_109 & ( 1 << V_110 ) ) )
continue;
if ( V_5 -> V_56 == & V_80 )
continue;
if ( ! F_23 ( & V_5 -> V_56 -> V_3 . V_79 ) )
return - V_112 ;
if ( V_108 != & V_80 )
return - V_112 ;
}
V_111 = F_87 ( & V_108 -> V_3 , V_109 ) ;
if ( V_111 ) {
if ( V_108 != & V_80 )
return V_111 ;
if ( V_113 ) {
F_88 ( L_2 ,
V_111 , V_109 ) ;
F_88 ( L_3 ) ;
}
}
F_14 ( & V_9 ) ;
F_16 (ss, ssid)
if ( V_109 & ( 1 << V_110 ) )
F_85 ( & V_5 -> V_56 -> V_3 , 1 << V_110 ) ;
F_13 ( & V_9 ) ;
F_16 (ss, ssid) {
struct V_57 * V_114 ;
struct V_1 * V_27 ;
if ( ! ( V_109 & ( 1 << V_110 ) ) )
continue;
V_114 = V_5 -> V_56 ;
V_27 = F_1 ( & V_114 -> V_3 , V_5 ) ;
F_89 ( ! V_27 || F_1 ( & V_108 -> V_3 , V_5 ) ) ;
F_90 ( V_114 -> V_3 . V_6 [ V_110 ] , NULL ) ;
F_91 ( V_108 -> V_3 . V_6 [ V_110 ] , V_27 ) ;
V_5 -> V_56 = V_108 ;
V_27 -> V_2 = & V_108 -> V_3 ;
V_114 -> V_3 . V_58 &= ~ ( 1 << V_110 ) ;
V_108 -> V_3 . V_58 |= 1 << V_110 ;
if ( V_5 -> V_115 )
V_5 -> V_115 ( V_27 ) ;
}
F_92 ( V_108 -> V_3 . V_18 ) ;
return 0 ;
}
static int F_93 ( struct V_13 * V_14 ,
struct V_72 * V_73 )
{
struct V_57 * V_56 = F_55 ( V_73 ) ;
struct V_4 * V_5 ;
int V_110 ;
F_16 (ss, ssid)
if ( V_56 -> V_3 . V_58 & ( 1 << V_110 ) )
F_94 ( V_14 , L_4 , V_5 -> V_90 ) ;
if ( V_56 -> V_12 & V_116 )
F_95 ( V_14 , L_5 ) ;
if ( V_56 -> V_12 & V_88 )
F_95 ( V_14 , L_6 ) ;
if ( V_56 -> V_12 & V_117 )
F_95 ( V_14 , L_7 ) ;
F_96 ( & V_118 ) ;
if ( strlen ( V_56 -> V_119 ) )
F_94 ( V_14 , L_8 , V_56 -> V_119 ) ;
F_97 ( & V_118 ) ;
if ( F_5 ( V_120 , & V_56 -> V_3 . V_12 ) )
F_95 ( V_14 , L_9 ) ;
if ( strlen ( V_56 -> V_90 ) )
F_94 ( V_14 , L_10 , V_56 -> V_90 ) ;
return 0 ;
}
static int F_98 ( char * V_121 , struct V_122 * V_123 )
{
char * V_124 , * V_125 = V_121 ;
bool V_126 = false , V_127 = false ;
unsigned long V_128 = ( unsigned long ) - 1 ;
struct V_4 * V_5 ;
int V_29 ;
F_35 ( ! F_99 ( & V_9 ) ) ;
#ifdef F_100
V_128 = ~ ( 1UL << V_129 ) ;
#endif
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
while ( ( V_124 = F_101 ( & V_125 , L_11 ) ) != NULL ) {
if ( ! * V_124 )
return - V_130 ;
if ( ! strcmp ( V_124 , L_12 ) ) {
V_123 -> V_131 = true ;
continue;
}
if ( ! strcmp ( V_124 , L_13 ) ) {
if ( V_127 )
return - V_130 ;
V_126 = true ;
continue;
}
if ( ! strcmp ( V_124 , L_14 ) ) {
V_123 -> V_12 |= V_116 ;
continue;
}
if ( ! strcmp ( V_124 , L_15 ) ) {
V_123 -> V_12 |= V_88 ;
continue;
}
if ( ! strcmp ( V_124 , L_16 ) ) {
V_123 -> V_132 = true ;
continue;
}
if ( ! strcmp ( V_124 , L_17 ) ) {
V_123 -> V_12 |= V_117 ;
continue;
}
if ( ! strncmp ( V_124 , L_18 , 14 ) ) {
if ( V_123 -> V_133 )
return - V_130 ;
V_123 -> V_133 =
F_102 ( V_124 + 14 , V_134 - 1 , V_62 ) ;
if ( ! V_123 -> V_133 )
return - V_63 ;
continue;
}
if ( ! strncmp ( V_124 , L_19 , 5 ) ) {
const char * V_90 = V_124 + 5 ;
if ( ! strlen ( V_90 ) )
return - V_130 ;
for ( V_29 = 0 ; V_29 < strlen ( V_90 ) ; V_29 ++ ) {
char V_70 = V_90 [ V_29 ] ;
if ( isalnum ( V_70 ) )
continue;
if ( ( V_70 == '.' ) || ( V_70 == '-' ) || ( V_70 == '_' ) )
continue;
return - V_130 ;
}
if ( V_123 -> V_90 )
return - V_130 ;
V_123 -> V_90 = F_102 ( V_90 ,
V_135 - 1 ,
V_62 ) ;
if ( ! V_123 -> V_90 )
return - V_63 ;
continue;
}
F_16 (ss, i) {
if ( strcmp ( V_124 , V_5 -> V_90 ) )
continue;
if ( V_5 -> V_136 )
continue;
if ( V_126 )
return - V_130 ;
F_24 ( V_29 , & V_123 -> V_58 ) ;
V_127 = true ;
break;
}
if ( V_29 == V_64 )
return - V_137 ;
}
if ( V_123 -> V_12 & V_116 ) {
F_88 ( L_20 ) ;
if ( ( V_123 -> V_12 & ( V_88 | V_117 ) ) ||
V_123 -> V_132 || V_123 -> V_133 ||
V_123 -> V_90 ) {
F_103 ( L_21 ) ;
return - V_130 ;
}
} else {
if ( V_126 || ( ! V_127 && ! V_123 -> V_131 && ! V_123 -> V_90 ) )
F_16 (ss, i)
if ( ! V_5 -> V_136 )
F_24 ( V_29 , & V_123 -> V_58 ) ;
if ( ! V_123 -> V_58 && ! V_123 -> V_90 )
return - V_130 ;
}
if ( ( V_123 -> V_12 & V_88 ) && ( V_123 -> V_58 & V_128 ) )
return - V_130 ;
if ( V_123 -> V_58 && V_123 -> V_131 )
return - V_130 ;
return 0 ;
}
static int F_104 ( struct V_72 * V_73 , int * V_12 , char * V_121 )
{
int V_111 = 0 ;
struct V_57 * V_56 = F_55 ( V_73 ) ;
struct V_122 V_123 ;
unsigned long V_138 , V_139 ;
if ( V_56 -> V_12 & V_116 ) {
F_103 ( L_22 ) ;
return - V_130 ;
}
F_13 ( & V_8 ) ;
F_13 ( & V_9 ) ;
V_111 = F_98 ( V_121 , & V_123 ) ;
if ( V_111 )
goto V_140;
if ( V_123 . V_58 != V_56 -> V_3 . V_58 || V_123 . V_133 )
F_88 ( L_23 ,
F_105 ( V_141 ) , V_141 -> V_142 ) ;
V_138 = V_123 . V_58 & ~ V_56 -> V_3 . V_58 ;
V_139 = V_56 -> V_3 . V_58 & ~ V_123 . V_58 ;
if ( ( ( V_123 . V_12 ^ V_56 -> V_12 ) & V_143 ) ||
( V_123 . V_90 && strcmp ( V_123 . V_90 , V_56 -> V_90 ) ) ) {
F_103 ( L_24 ,
V_123 . V_12 & V_143 , V_123 . V_90 ? : L_25 ,
V_56 -> V_12 & V_143 , V_56 -> V_90 ) ;
V_111 = - V_130 ;
goto V_140;
}
if ( ! F_23 ( & V_56 -> V_3 . V_79 ) ) {
V_111 = - V_112 ;
goto V_140;
}
V_111 = F_65 ( V_56 , V_138 ) ;
if ( V_111 )
goto V_140;
F_65 ( & V_80 , V_139 ) ;
if ( V_123 . V_133 ) {
F_96 ( & V_118 ) ;
strcpy ( V_56 -> V_119 , V_123 . V_133 ) ;
F_97 ( & V_118 ) ;
}
V_140:
F_26 ( V_123 . V_133 ) ;
F_26 ( V_123 . V_90 ) ;
F_14 ( & V_9 ) ;
F_14 ( & V_8 ) ;
return V_111 ;
}
static void F_106 ( void )
{
struct V_84 * V_144 , * V_145 ;
F_30 ( & V_36 ) ;
if ( V_146 )
goto V_140;
V_146 = true ;
F_107 ( & V_147 ) ;
F_108 (g, p) {
F_61 ( ! F_23 ( & V_144 -> V_148 ) ||
F_69 ( V_144 ) != & V_83 ) ;
F_109 ( & V_144 -> V_149 -> V_150 ) ;
if ( ! ( V_144 -> V_12 & V_151 ) ) {
struct V_30 * V_31 = F_69 ( V_144 ) ;
F_43 ( & V_144 -> V_148 , & V_31 -> V_66 ) ;
F_32 ( V_31 ) ;
}
F_110 ( & V_144 -> V_149 -> V_150 ) ;
} F_111 ( V_145 , V_144 ) ;
F_112 ( & V_147 ) ;
V_140:
F_31 ( & V_36 ) ;
}
static void F_113 ( struct V_2 * V_3 )
{
F_51 ( & V_3 -> V_106 , 1 ) ;
F_41 ( & V_3 -> V_152 ) ;
F_41 ( & V_3 -> V_79 ) ;
F_41 ( & V_3 -> V_42 ) ;
F_41 ( & V_3 -> V_153 ) ;
F_41 ( & V_3 -> V_154 ) ;
F_114 ( & V_3 -> V_155 ) ;
V_3 -> V_10 . V_2 = V_3 ;
}
static void F_115 ( struct V_57 * V_56 ,
struct V_122 * V_123 )
{
struct V_2 * V_3 = & V_56 -> V_3 ;
F_41 ( & V_56 -> V_81 ) ;
F_51 ( & V_56 -> V_78 , 1 ) ;
V_3 -> V_56 = V_56 ;
F_113 ( V_3 ) ;
F_116 ( & V_56 -> V_77 ) ;
V_56 -> V_12 = V_123 -> V_12 ;
if ( V_123 -> V_133 )
strcpy ( V_56 -> V_119 , V_123 -> V_133 ) ;
if ( V_123 -> V_90 )
strcpy ( V_56 -> V_90 , V_123 -> V_90 ) ;
if ( V_123 -> V_132 )
F_24 ( V_120 , & V_56 -> V_3 . V_12 ) ;
}
static int F_117 ( struct V_57 * V_56 , unsigned long V_109 )
{
F_118 ( V_61 ) ;
struct V_2 * V_74 = & V_56 -> V_3 ;
struct V_30 * V_31 ;
int V_29 , V_111 ;
F_18 ( & V_8 ) ;
F_18 ( & V_9 ) ;
V_111 = F_119 ( & V_56 -> V_77 , V_74 , 0 , 1 , V_62 ) ;
if ( V_111 < 0 )
goto V_156;
V_74 -> V_7 = V_111 ;
V_111 = F_40 ( V_39 , & V_61 ) ;
if ( V_111 )
goto V_156;
V_111 = F_56 ( V_56 ) ;
if ( V_111 )
goto V_156;
V_56 -> V_73 = F_120 ( & V_157 ,
V_158 ,
V_74 ) ;
if ( F_121 ( V_56 -> V_73 ) ) {
V_111 = F_122 ( V_56 -> V_73 ) ;
goto V_159;
}
V_74 -> V_18 = V_56 -> V_73 -> V_18 ;
V_111 = F_86 ( V_74 , V_160 , true ) ;
if ( V_111 )
goto V_161;
V_111 = F_65 ( V_56 , V_109 ) ;
if ( V_111 )
goto V_161;
F_43 ( & V_56 -> V_81 , & V_162 ) ;
V_65 ++ ;
F_30 ( & V_36 ) ;
F_123 (css_set_table, i, cset, hlist)
F_44 ( & V_61 , V_31 , V_74 ) ;
F_31 ( & V_36 ) ;
F_35 ( ! F_23 ( & V_74 -> V_79 ) ) ;
F_35 ( F_64 ( & V_56 -> V_78 ) != 1 ) ;
F_92 ( V_74 -> V_18 ) ;
V_111 = 0 ;
goto V_156;
V_161:
F_66 ( V_56 -> V_73 ) ;
V_56 -> V_73 = NULL ;
V_159:
F_58 ( V_56 ) ;
V_156:
F_39 ( & V_61 ) ;
return V_111 ;
}
static struct V_163 * F_124 ( struct V_164 * V_165 ,
int V_12 , const char * V_166 ,
void * V_121 )
{
struct V_57 * V_56 ;
struct V_122 V_123 ;
struct V_163 * V_163 ;
int V_111 ;
bool V_167 ;
if ( ! V_146 )
F_106 () ;
F_13 ( & V_8 ) ;
F_13 ( & V_9 ) ;
V_111 = F_98 ( V_121 , & V_123 ) ;
if ( V_111 )
goto V_140;
V_168:
if ( ! V_123 . V_58 && ! V_123 . V_131 && ! V_123 . V_90 ) {
V_113 = true ;
V_56 = & V_80 ;
F_81 ( & V_56 -> V_3 ) ;
V_111 = 0 ;
goto V_140;
}
F_125 (root) {
bool V_169 = false ;
if ( V_56 == & V_80 )
continue;
if ( V_123 . V_90 ) {
if ( strcmp ( V_123 . V_90 , V_56 -> V_90 ) )
continue;
V_169 = true ;
}
if ( ( V_123 . V_58 || V_123 . V_131 ) &&
( V_123 . V_58 != V_56 -> V_3 . V_58 ) ) {
if ( ! V_169 )
continue;
V_111 = - V_112 ;
goto V_140;
}
if ( ( V_56 -> V_12 ^ V_123 . V_12 ) & V_143 ) {
if ( ( V_56 -> V_12 | V_123 . V_12 ) & V_116 ) {
F_103 ( L_26 ) ;
V_111 = - V_130 ;
goto V_140;
} else {
F_88 ( L_27 ) ;
}
}
if ( ! F_126 ( & V_56 -> V_3 . V_106 ) ) {
F_14 ( & V_9 ) ;
F_14 ( & V_8 ) ;
F_127 ( 10 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_9 ) ;
goto V_168;
}
V_111 = 0 ;
goto V_140;
}
if ( ! V_123 . V_58 && ! V_123 . V_131 ) {
V_111 = - V_130 ;
goto V_140;
}
V_56 = F_42 ( sizeof( * V_56 ) , V_62 ) ;
if ( ! V_56 ) {
V_111 = - V_63 ;
goto V_140;
}
F_115 ( V_56 , & V_123 ) ;
V_111 = F_117 ( V_56 , V_123 . V_58 ) ;
if ( V_111 )
F_60 ( V_56 ) ;
V_140:
F_14 ( & V_9 ) ;
F_14 ( & V_8 ) ;
F_26 ( V_123 . V_133 ) ;
F_26 ( V_123 . V_90 ) ;
if ( V_111 )
return F_128 ( V_111 ) ;
V_163 = F_129 ( V_165 , V_12 , V_56 -> V_73 ,
V_170 , & V_167 ) ;
if ( F_121 ( V_163 ) || ! V_167 )
F_76 ( & V_56 -> V_3 ) ;
return V_163 ;
}
static void F_130 ( struct V_171 * V_172 )
{
struct V_72 * V_73 = F_131 ( V_172 ) ;
struct V_57 * V_56 = F_55 ( V_73 ) ;
F_76 ( & V_56 -> V_3 ) ;
F_132 ( V_172 ) ;
}
char * F_133 ( struct V_84 * V_85 , char * V_86 , T_2 V_173 )
{
struct V_57 * V_56 ;
struct V_2 * V_3 ;
int V_76 = 1 ;
char * V_174 = NULL ;
F_13 ( & V_9 ) ;
F_49 ( & V_36 ) ;
V_56 = F_134 ( & V_75 , & V_76 ) ;
if ( V_56 ) {
V_3 = F_68 ( V_85 , V_56 ) ;
V_174 = F_135 ( V_3 , V_86 , V_173 ) ;
} else {
if ( F_136 ( V_86 , L_28 , V_173 ) < V_173 )
V_174 = V_86 ;
}
F_50 ( & V_36 ) ;
F_14 ( & V_9 ) ;
return V_174 ;
}
struct V_84 * F_137 ( struct V_175 * V_176 )
{
V_176 -> V_177 = F_45 ( V_176 -> V_178 , struct V_30 , V_69 ) ;
V_176 -> V_179 = NULL ;
return F_138 ( V_176 ) ;
}
struct V_84 * F_138 ( struct V_175 * V_176 )
{
struct V_30 * V_31 = V_176 -> V_177 ;
struct V_84 * V_85 = V_176 -> V_179 ;
while ( & V_31 -> V_69 != V_176 -> V_178 ) {
if ( ! V_85 )
V_85 = F_45 ( & V_31 -> V_67 ,
struct V_84 , V_148 ) ;
else
V_85 = F_139 ( V_85 , V_148 ) ;
if ( & V_85 -> V_148 != & V_31 -> V_67 ) {
V_176 -> V_177 = V_31 ;
V_176 -> V_179 = V_85 ;
return V_85 ;
}
V_31 = F_139 ( V_31 , V_69 ) ;
V_85 = NULL ;
}
return NULL ;
}
static void F_140 ( struct V_2 * V_180 ,
struct V_84 * V_181 ,
struct V_30 * V_182 )
{
struct V_30 * V_44 ;
F_18 ( & V_9 ) ;
F_18 ( & V_36 ) ;
F_61 ( V_181 -> V_12 & V_151 ) ;
V_44 = F_69 ( V_181 ) ;
F_32 ( V_182 ) ;
F_91 ( V_181 -> V_183 , V_182 ) ;
F_141 ( & V_181 -> V_148 , & V_182 -> V_67 ) ;
F_24 ( V_25 , & V_180 -> V_12 ) ;
F_17 ( V_44 , false ) ;
}
static void F_142 ( struct V_47 * V_184 )
{
struct V_30 * V_31 , * V_185 ;
F_18 ( & V_9 ) ;
F_30 ( & V_36 ) ;
F_21 (cset, tmp_cset, preloaded_csets, mg_preload_node) {
V_31 -> V_186 = NULL ;
V_31 -> V_187 = NULL ;
F_143 ( & V_31 -> V_68 ) ;
F_17 ( V_31 , false ) ;
}
F_31 ( & V_36 ) ;
}
static void F_144 ( struct V_30 * V_188 ,
struct V_2 * V_189 ,
struct V_47 * V_184 )
{
struct V_2 * V_190 ;
F_18 ( & V_9 ) ;
F_18 ( & V_36 ) ;
V_190 = F_67 ( V_188 , V_189 -> V_56 ) ;
if ( V_190 == V_189 )
return;
if ( ! F_23 ( & V_188 -> V_68 ) )
return;
F_89 ( V_188 -> V_186 ) ;
F_89 ( ! F_23 ( & V_188 -> V_67 ) ) ;
F_89 ( ! F_23 ( & V_188 -> V_69 ) ) ;
V_188 -> V_186 = V_190 ;
F_32 ( V_188 ) ;
F_43 ( & V_188 -> V_68 , V_184 ) ;
}
static int F_145 ( struct V_2 * V_189 ,
struct V_47 * V_184 )
{
F_118 ( V_178 ) ;
struct V_30 * V_188 ;
F_18 ( & V_9 ) ;
F_53 (src_cset, preloaded_csets, mg_preload_node) {
struct V_30 * V_191 ;
V_191 = F_48 ( V_188 , V_189 ) ;
if ( ! V_191 )
goto V_192;
F_61 ( V_188 -> V_187 || V_191 -> V_187 ) ;
V_188 -> V_187 = V_191 ;
if ( F_23 ( & V_191 -> V_68 ) )
F_43 ( & V_191 -> V_68 , & V_178 ) ;
else
F_28 ( V_191 , false ) ;
}
F_146 ( & V_178 , V_184 ) ;
return 0 ;
V_192:
F_142 ( & V_178 ) ;
return - V_63 ;
}
static int F_147 ( struct V_2 * V_3 , struct V_84 * V_193 ,
bool V_194 )
{
struct V_175 V_176 = {
. V_195 = F_148 ( V_176 . V_195 ) ,
. V_196 = F_148 ( V_176 . V_196 ) ,
. V_178 = & V_176 . V_195 ,
} ;
struct V_1 * V_27 , * V_197 = NULL ;
struct V_30 * V_31 , * V_185 ;
struct V_84 * V_85 , * V_198 ;
int V_29 , V_111 ;
F_30 ( & V_36 ) ;
F_149 () ;
V_85 = V_193 ;
do {
if ( V_85 -> V_12 & V_151 )
goto V_55;
if ( F_23 ( & V_85 -> V_148 ) )
goto V_55;
V_31 = F_69 ( V_85 ) ;
if ( ! V_31 -> V_186 )
goto V_55;
F_141 ( & V_85 -> V_148 , & V_31 -> V_67 ) ;
if ( F_23 ( & V_31 -> V_69 ) )
F_47 ( & V_31 -> V_69 , & V_176 . V_195 ) ;
if ( F_23 ( & V_31 -> V_187 -> V_69 ) )
F_141 ( & V_31 -> V_187 -> V_69 ,
& V_176 . V_196 ) ;
V_55:
if ( ! V_194 )
break;
} while_each_thread(leader, task) ;
int F_150 ( struct V_2 * V_189 ,
struct V_84 * V_193 , bool V_194 )
{
F_118 ( V_184 ) ;
struct V_84 * V_85 ;
int V_111 ;
F_49 ( & V_36 ) ;
F_149 () ;
V_85 = V_193 ;
do {
F_144 ( F_69 ( V_85 ) , V_189 ,
& V_184 ) ;
if ( ! V_194 )
break;
} while_each_thread(leader, task) ;
int F_151 ( struct V_2 * V_3 , T_3 V_199 , bool V_194 )
{
struct V_84 * V_181 ;
const struct V_200 * V_200 = F_152 () , * V_201 ;
int V_111 ;
if ( ! F_12 ( V_3 ) )
return - V_202 ;
V_203:
F_149 () ;
if ( V_199 ) {
V_181 = F_153 ( V_199 ) ;
if ( ! V_181 ) {
F_154 () ;
V_111 = - V_204 ;
goto V_205;
}
V_201 = F_155 ( V_181 ) ;
if ( ! F_156 ( V_200 -> V_206 , V_207 ) &&
! F_156 ( V_200 -> V_206 , V_201 -> V_208 ) &&
! F_156 ( V_200 -> V_206 , V_201 -> V_209 ) ) {
F_154 () ;
V_111 = - V_210 ;
goto V_205;
}
} else
V_181 = V_141 ;
if ( V_194 )
V_181 = V_181 -> V_211 ;
if ( V_181 == V_212 || ( V_181 -> V_12 & V_213 ) ) {
V_111 = - V_130 ;
F_154 () ;
goto V_205;
}
F_157 ( V_181 ) ;
F_154 () ;
F_158 ( V_181 ) ;
if ( V_194 ) {
if ( ! F_159 ( V_181 ) ) {
F_160 ( V_181 ) ;
F_161 ( V_181 ) ;
goto V_203;
}
}
V_111 = F_150 ( V_3 , V_181 , V_194 ) ;
F_160 ( V_181 ) ;
F_161 ( V_181 ) ;
V_205:
F_14 ( & V_9 ) ;
return V_111 ;
}
int F_162 ( struct V_84 * V_214 , struct V_84 * V_181 )
{
struct V_57 * V_56 ;
int V_215 = 0 ;
F_13 ( & V_9 ) ;
F_125 (root) {
struct V_2 * V_216 ;
if ( V_56 == & V_80 )
continue;
F_49 ( & V_36 ) ;
V_216 = F_68 ( V_214 , V_56 ) ;
F_50 ( & V_36 ) ;
V_215 = F_150 ( V_216 , V_181 , false ) ;
if ( V_215 )
break;
}
F_14 ( & V_9 ) ;
return V_215 ;
}
static int F_163 ( struct V_1 * V_27 ,
struct V_21 * V_22 , T_3 V_199 )
{
return F_151 ( V_27 -> V_2 , V_199 , false ) ;
}
static int F_164 ( struct V_1 * V_27 ,
struct V_21 * V_22 , T_3 V_217 )
{
return F_151 ( V_27 -> V_2 , V_217 , true ) ;
}
static int F_165 ( struct V_1 * V_27 ,
struct V_21 * V_22 , char * V_218 )
{
struct V_57 * V_56 = V_27 -> V_2 -> V_56 ;
F_166 ( sizeof( V_56 -> V_119 ) < V_134 ) ;
if ( ! F_12 ( V_27 -> V_2 ) )
return - V_202 ;
F_96 ( & V_118 ) ;
F_136 ( V_56 -> V_119 , V_218 ,
sizeof( V_56 -> V_119 ) ) ;
F_97 ( & V_118 ) ;
F_14 ( & V_9 ) ;
return 0 ;
}
static int F_167 ( struct V_13 * V_14 , void * V_219 )
{
struct V_2 * V_3 = F_6 ( V_14 ) -> V_2 ;
if ( ! F_12 ( V_3 ) )
return - V_202 ;
F_95 ( V_14 , V_3 -> V_56 -> V_119 ) ;
F_168 ( V_14 , '\n' ) ;
F_14 ( & V_9 ) ;
return 0 ;
}
static int F_169 ( struct V_13 * V_14 , void * V_219 )
{
struct V_2 * V_3 = F_6 ( V_14 ) -> V_2 ;
F_94 ( V_14 , L_29 , F_170 ( V_3 ) ) ;
return 0 ;
}
static T_4 F_171 ( struct V_15 * V_16 , char * V_86 ,
T_2 V_220 , T_5 V_221 )
{
struct V_2 * V_3 = V_16 -> V_18 -> V_19 -> V_20 ;
struct V_21 * V_22 = V_16 -> V_18 -> V_20 ;
struct V_1 * V_27 ;
int V_111 ;
F_149 () ;
V_27 = F_1 ( V_3 , V_22 -> V_5 ) ;
F_154 () ;
if ( V_22 -> V_98 ) {
V_111 = V_22 -> V_98 ( V_27 , V_22 , F_172 ( V_86 ) ) ;
} else if ( V_22 -> V_96 ) {
unsigned long long V_219 ;
V_111 = F_173 ( V_86 , 0 , & V_219 ) ;
if ( ! V_111 )
V_111 = V_22 -> V_96 ( V_27 , V_22 , V_219 ) ;
} else if ( V_22 -> V_97 ) {
long long V_219 ;
V_111 = F_174 ( V_86 , 0 , & V_219 ) ;
if ( ! V_111 )
V_111 = V_22 -> V_97 ( V_27 , V_22 , V_219 ) ;
} else if ( V_22 -> V_99 ) {
V_111 = V_22 -> V_99 ( V_27 , ( unsigned int ) V_22 -> V_17 ) ;
} else {
V_111 = - V_130 ;
}
return V_111 ? : V_220 ;
}
static void * F_175 ( struct V_13 * V_14 , T_5 * V_222 )
{
return F_7 ( V_14 ) -> F_176 ( V_14 , V_222 ) ;
}
static void * F_177 ( struct V_13 * V_14 , void * V_219 , T_5 * V_222 )
{
return F_7 ( V_14 ) -> F_178 ( V_14 , V_219 , V_222 ) ;
}
static void F_179 ( struct V_13 * V_14 , void * V_219 )
{
F_7 ( V_14 ) -> F_180 ( V_14 , V_219 ) ;
}
static int F_181 ( struct V_13 * V_223 , void * V_224 )
{
struct V_21 * V_22 = F_7 ( V_223 ) ;
struct V_1 * V_27 = F_6 ( V_223 ) ;
if ( V_22 -> V_94 )
return V_22 -> V_94 ( V_223 , V_224 ) ;
if ( V_22 -> V_92 )
F_94 ( V_223 , L_30 , V_22 -> V_92 ( V_27 , V_22 ) ) ;
else if ( V_22 -> V_93 )
F_94 ( V_223 , L_31 , V_22 -> V_93 ( V_27 , V_22 ) ) ;
else
return - V_130 ;
return 0 ;
}
static int F_182 ( struct V_225 * V_18 , struct V_225 * V_226 ,
const char * V_227 )
{
struct V_2 * V_3 = V_18 -> V_20 ;
int V_111 ;
if ( F_183 ( V_18 ) != V_228 )
return - V_229 ;
if ( V_18 -> V_19 != V_226 )
return - V_230 ;
if ( F_170 ( V_3 ) )
return - V_231 ;
F_184 ( V_226 ) ;
F_184 ( V_18 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_9 ) ;
V_111 = F_185 ( V_18 , V_226 , V_227 ) ;
F_14 ( & V_9 ) ;
F_14 ( & V_8 ) ;
F_186 ( V_18 ) ;
F_186 ( V_226 ) ;
return V_111 ;
}
static int F_187 ( struct V_225 * V_18 )
{
struct V_232 V_232 = { . V_233 = V_234 | V_235 ,
. V_236 = F_188 () ,
. V_237 = F_189 () , } ;
if ( F_156 ( V_232 . V_236 , V_207 ) &&
F_190 ( V_232 . V_237 , V_238 ) )
return 0 ;
return F_191 ( V_18 , & V_232 ) ;
}
static int F_192 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
char V_90 [ V_89 ] ;
struct V_225 * V_18 ;
struct V_239 * V_28 = NULL ;
int V_111 ;
#ifdef F_193
V_28 = & V_22 -> V_240 ;
#endif
V_18 = F_194 ( V_3 -> V_18 , F_70 ( V_3 , V_22 , V_90 ) ,
F_71 ( V_22 ) , 0 , V_22 -> V_241 , V_22 ,
NULL , false , V_28 ) ;
if ( F_121 ( V_18 ) )
return F_122 ( V_18 ) ;
V_111 = F_187 ( V_18 ) ;
if ( V_111 )
F_195 ( V_18 ) ;
return V_111 ;
}
static int F_86 ( struct V_2 * V_3 , struct V_21 V_107 [] ,
bool V_242 )
{
struct V_21 * V_22 ;
int V_111 ;
F_18 ( & V_8 ) ;
for ( V_22 = V_107 ; V_22 -> V_90 [ 0 ] != '\0' ; V_22 ++ ) {
if ( ( V_22 -> V_12 & V_243 ) && ! F_196 ( V_3 ) )
continue;
if ( ( V_22 -> V_12 & V_244 ) && F_170 ( V_3 ) )
continue;
if ( ( V_22 -> V_12 & V_245 ) && ! V_3 -> V_19 )
continue;
if ( ( V_22 -> V_12 & V_246 ) && V_3 -> V_19 )
continue;
if ( V_242 ) {
V_111 = F_192 ( V_3 , V_22 ) ;
if ( V_111 ) {
F_197 ( L_32 ,
V_22 -> V_90 , V_111 ) ;
return V_111 ;
}
} else {
F_83 ( V_3 , V_22 ) ;
}
}
return 0 ;
}
static int F_198 ( struct V_21 * V_107 , bool V_242 )
{
F_118 ( V_247 ) ;
struct V_4 * V_5 = V_107 [ 0 ] . V_5 ;
struct V_2 * V_56 = & V_5 -> V_56 -> V_3 ;
struct V_1 * V_27 ;
int V_111 = 0 ;
F_18 ( & V_8 ) ;
if ( V_5 -> V_56 == & V_80 )
return 0 ;
F_199 (css, cgroup_css(root, ss)) {
struct V_2 * V_3 = V_27 -> V_2 ;
if ( F_4 ( V_3 ) )
continue;
V_111 = F_86 ( V_3 , V_107 , V_242 ) ;
if ( V_111 )
break;
}
if ( V_242 && ! V_111 )
F_92 ( V_56 -> V_18 ) ;
return V_111 ;
}
static void F_200 ( struct V_21 * V_107 )
{
struct V_21 * V_22 ;
for ( V_22 = V_107 ; V_22 -> V_90 [ 0 ] != '\0' ; V_22 ++ ) {
if ( V_22 -> V_248 && V_22 -> V_248 != V_249 )
F_26 ( V_22 -> V_241 ) ;
V_22 -> V_241 = NULL ;
V_22 -> V_5 = NULL ;
}
}
static int F_201 ( struct V_4 * V_5 , struct V_21 * V_107 )
{
struct V_21 * V_22 ;
for ( V_22 = V_107 ; V_22 -> V_90 [ 0 ] != '\0' ; V_22 ++ ) {
struct V_250 * V_241 ;
F_89 ( V_22 -> V_5 || V_22 -> V_241 ) ;
if ( V_22 -> F_176 )
V_241 = & V_251 ;
else
V_241 = & V_252 ;
if ( V_22 -> V_248 && V_22 -> V_248 != V_249 ) {
V_241 = F_202 ( V_241 , sizeof( * V_241 ) , V_62 ) ;
if ( ! V_241 ) {
F_200 ( V_107 ) ;
return - V_63 ;
}
V_241 -> V_253 = V_22 -> V_248 ;
}
V_22 -> V_241 = V_241 ;
V_22 -> V_5 = V_5 ;
}
return 0 ;
}
static int F_203 ( struct V_21 * V_107 )
{
F_18 ( & V_8 ) ;
if ( ! V_107 || ! V_107 [ 0 ] . V_5 )
return - V_137 ;
F_22 ( & V_107 -> V_254 ) ;
F_198 ( V_107 , false ) ;
F_200 ( V_107 ) ;
return 0 ;
}
int F_204 ( struct V_21 * V_107 )
{
int V_111 ;
F_13 ( & V_8 ) ;
V_111 = F_203 ( V_107 ) ;
F_14 ( & V_8 ) ;
return V_111 ;
}
int F_205 ( struct V_4 * V_5 , struct V_21 * V_107 )
{
int V_111 ;
if ( ! V_107 || V_107 [ 0 ] . V_90 [ 0 ] == '\0' )
return 0 ;
V_111 = F_201 ( V_5 , V_107 ) ;
if ( V_111 )
return V_111 ;
F_13 ( & V_8 ) ;
F_47 ( & V_107 -> V_254 , & V_5 -> V_107 ) ;
V_111 = F_198 ( V_107 , true ) ;
if ( V_111 )
F_203 ( V_107 ) ;
F_14 ( & V_8 ) ;
return V_111 ;
}
static int F_206 ( const struct V_2 * V_3 )
{
int V_60 = 0 ;
struct V_33 * V_34 ;
F_49 ( & V_36 ) ;
F_53 (link, &cgrp->cset_links, cset_link)
V_60 += F_64 ( & V_34 -> V_31 -> V_37 ) ;
F_50 ( & V_36 ) ;
return V_60 ;
}
struct V_1 *
F_207 ( struct V_1 * V_255 ,
struct V_1 * V_256 )
{
struct V_2 * V_257 = V_255 ? V_255 -> V_2 : NULL ;
struct V_2 * V_3 = V_256 -> V_2 ;
struct V_2 * V_55 ;
F_208 () ;
if ( ! V_257 ) {
V_55 = F_209 ( V_3 -> V_79 . V_55 , struct V_2 , V_152 ) ;
} else if ( F_210 ( ! F_4 ( V_257 ) ) ) {
V_55 = F_209 ( V_257 -> V_152 . V_55 , struct V_2 , V_152 ) ;
} else {
F_211 (next, &cgrp->children, sibling)
if ( V_55 -> V_258 > V_257 -> V_258 )
break;
}
if ( & V_55 -> V_152 == & V_3 -> V_79 )
return NULL ;
return F_1 ( V_55 , V_256 -> V_5 ) ;
}
struct V_1 *
F_212 ( struct V_1 * V_257 ,
struct V_1 * V_56 )
{
struct V_1 * V_55 ;
F_208 () ;
if ( ! V_257 )
return V_56 ;
V_55 = F_207 ( NULL , V_257 ) ;
if ( V_55 )
return V_55 ;
while ( V_257 != V_56 ) {
V_55 = F_207 ( V_257 , F_213 ( V_257 ) ) ;
if ( V_55 )
return V_55 ;
V_257 = F_213 ( V_257 ) ;
}
return NULL ;
}
struct V_1 *
F_214 ( struct V_1 * V_257 )
{
struct V_1 * V_259 , * V_260 ;
F_208 () ;
do {
V_259 = V_257 ;
V_257 = NULL ;
F_215 (tmp, last)
V_257 = V_260 ;
} while ( V_257 );
return V_259 ;
}
static struct V_1 *
F_216 ( struct V_1 * V_257 )
{
struct V_1 * V_259 ;
do {
V_259 = V_257 ;
V_257 = F_207 ( NULL , V_257 ) ;
} while ( V_257 );
return V_259 ;
}
struct V_1 *
F_217 ( struct V_1 * V_257 ,
struct V_1 * V_56 )
{
struct V_1 * V_55 ;
F_208 () ;
if ( ! V_257 )
return F_216 ( V_56 ) ;
if ( V_257 == V_56 )
return NULL ;
V_55 = F_207 ( V_257 , F_213 ( V_257 ) ) ;
if ( V_55 )
return F_216 ( V_55 ) ;
return F_213 ( V_257 ) ;
}
static void F_218 ( struct V_261 * V_262 )
{
struct V_47 * V_263 = V_262 -> V_40 ;
struct V_33 * V_34 ;
struct V_30 * V_31 ;
do {
V_263 = V_263 -> V_55 ;
if ( V_263 == & V_262 -> V_264 -> V_2 -> V_42 ) {
V_262 -> V_40 = NULL ;
return;
}
V_34 = F_36 ( V_263 , struct V_33 , V_40 ) ;
V_31 = V_34 -> V_31 ;
} while ( F_23 ( & V_31 -> V_66 ) && F_23 ( & V_31 -> V_67 ) );
V_262 -> V_40 = V_263 ;
if ( ! F_23 ( & V_31 -> V_66 ) )
V_262 -> V_85 = V_31 -> V_66 . V_55 ;
else
V_262 -> V_85 = V_31 -> V_67 . V_55 ;
}
void F_219 ( struct V_1 * V_27 ,
struct V_261 * V_262 )
__acquires( V_36 )
{
F_61 ( ! V_146 ) ;
F_49 ( & V_36 ) ;
V_262 -> V_264 = V_27 ;
V_262 -> V_40 = & V_27 -> V_2 -> V_42 ;
F_218 ( V_262 ) ;
}
struct V_84 * F_220 ( struct V_261 * V_262 )
{
struct V_84 * V_82 ;
struct V_47 * V_263 = V_262 -> V_85 ;
struct V_33 * V_34 = F_36 ( V_262 -> V_40 ,
struct V_33 , V_40 ) ;
if ( ! V_262 -> V_40 )
return NULL ;
V_82 = F_36 ( V_263 , struct V_84 , V_148 ) ;
V_263 = V_263 -> V_55 ;
if ( V_263 == & V_34 -> V_31 -> V_66 )
V_263 = V_34 -> V_31 -> V_67 . V_55 ;
if ( V_263 == & V_34 -> V_31 -> V_67 )
F_218 ( V_262 ) ;
else
V_262 -> V_85 = V_263 ;
return V_82 ;
}
void F_221 ( struct V_261 * V_262 )
__releases( V_36 )
{
F_50 ( & V_36 ) ;
}
int F_222 ( struct V_2 * V_265 , struct V_2 * V_214 )
{
F_118 ( V_184 ) ;
struct V_33 * V_34 ;
struct V_261 V_262 ;
struct V_84 * V_85 ;
int V_111 ;
F_13 ( & V_9 ) ;
F_49 ( & V_36 ) ;
F_53 (link, &from->cset_links, cset_link)
F_144 ( V_34 -> V_31 , V_265 , & V_184 ) ;
F_50 ( & V_36 ) ;
V_111 = F_145 ( V_265 , & V_184 ) ;
if ( V_111 )
goto V_266;
do {
F_219 ( & V_214 -> V_10 , & V_262 ) ;
V_85 = F_220 ( & V_262 ) ;
if ( V_85 )
F_157 ( V_85 ) ;
F_221 ( & V_262 ) ;
if ( V_85 ) {
V_111 = F_147 ( V_265 , V_85 , false ) ;
F_161 ( V_85 ) ;
}
} while ( V_85 && ! V_111 );
V_266:
F_142 ( & V_184 ) ;
F_14 ( & V_9 ) ;
return V_111 ;
}
static void * F_223 ( int V_60 )
{
if ( F_224 ( V_60 ) )
return F_225 ( V_60 * sizeof( V_267 ) ) ;
else
return F_226 ( V_60 * sizeof( V_267 ) , V_62 ) ;
}
static void F_227 ( void * V_144 )
{
if ( F_228 ( V_144 ) )
F_229 ( V_144 ) ;
else
F_26 ( V_144 ) ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_268 * V_263 , * V_269 ;
F_13 ( & V_3 -> V_155 ) ;
F_21 (l, tmp_l, &cgrp->pidlists, links)
F_230 ( V_270 , & V_263 -> V_271 , 0 ) ;
F_14 ( & V_3 -> V_155 ) ;
F_231 ( V_270 ) ;
F_35 ( ! F_23 ( & V_3 -> V_154 ) ) ;
}
static void F_232 ( struct V_101 * V_102 )
{
struct V_272 * V_273 = F_233 ( V_102 ) ;
struct V_268 * V_263 = F_73 ( V_273 , struct V_268 ,
V_271 ) ;
struct V_268 * V_274 = NULL ;
F_13 ( & V_263 -> V_275 -> V_155 ) ;
if ( ! F_234 ( V_273 ) ) {
F_22 ( & V_263 -> V_276 ) ;
F_227 ( V_263 -> V_277 ) ;
F_235 ( V_263 -> V_28 . V_278 ) ;
V_274 = V_263 ;
}
F_14 ( & V_263 -> V_275 -> V_155 ) ;
F_26 ( V_274 ) ;
}
static int F_236 ( V_267 * V_277 , int V_279 )
{
int V_280 , V_281 = 1 ;
if ( V_279 == 0 || V_279 == 1 )
return V_279 ;
for ( V_280 = 1 ; V_280 < V_279 ; V_280 ++ ) {
while ( V_277 [ V_280 ] == V_277 [ V_280 - 1 ] ) {
V_280 ++ ;
if ( V_280 == V_279 )
goto V_282;
}
V_277 [ V_281 ] = V_277 [ V_280 ] ;
V_281 ++ ;
}
V_282:
return V_281 ;
}
static V_267 F_237 ( V_267 V_199 )
{
unsigned V_283 = V_199 & 0x55555555 ;
unsigned V_284 = V_199 & 0xAAAAAAAA ;
return ( V_283 << 1 ) | ( V_284 >> 1 ) ;
}
static V_267 F_238 ( struct V_2 * V_3 , V_267 V_199 )
{
if ( F_170 ( V_3 ) )
return F_237 ( V_199 ) ;
else
return V_199 ;
}
static int F_239 ( const void * V_283 , const void * V_284 )
{
return * ( V_267 * ) V_283 - * ( V_267 * ) V_284 ;
}
static int F_240 ( const void * V_283 , const void * V_284 )
{
return F_237 ( * ( V_267 * ) V_283 ) - F_237 ( * ( V_267 * ) V_284 ) ;
}
static struct V_268 * F_241 ( struct V_2 * V_3 ,
enum V_285 type )
{
struct V_268 * V_263 ;
struct V_286 * V_278 = F_242 ( V_141 ) ;
F_18 ( & V_3 -> V_155 ) ;
F_53 (l, &cgrp->pidlists, links)
if ( V_263 -> V_28 . type == type && V_263 -> V_28 . V_278 == V_278 )
return V_263 ;
return NULL ;
}
static struct V_268 * F_243 ( struct V_2 * V_3 ,
enum V_285 type )
{
struct V_268 * V_263 ;
F_18 ( & V_3 -> V_155 ) ;
V_263 = F_241 ( V_3 , type ) ;
if ( V_263 )
return V_263 ;
V_263 = F_42 ( sizeof( struct V_268 ) , V_62 ) ;
if ( ! V_263 )
return V_263 ;
F_244 ( & V_263 -> V_271 , F_232 ) ;
V_263 -> V_28 . type = type ;
V_263 -> V_28 . V_278 = F_245 ( F_242 ( V_141 ) ) ;
V_263 -> V_275 = V_3 ;
F_43 ( & V_263 -> V_276 , & V_3 -> V_154 ) ;
return V_263 ;
}
static int F_246 ( struct V_2 * V_3 , enum V_285 type ,
struct V_268 * * V_287 )
{
V_267 * V_288 ;
int V_279 ;
int V_199 , V_289 = 0 ;
struct V_261 V_262 ;
struct V_84 * V_181 ;
struct V_268 * V_263 ;
F_18 ( & V_3 -> V_155 ) ;
V_279 = F_206 ( V_3 ) ;
V_288 = F_223 ( V_279 ) ;
if ( ! V_288 )
return - V_63 ;
F_219 ( & V_3 -> V_10 , & V_262 ) ;
while ( ( V_181 = F_220 ( & V_262 ) ) ) {
if ( F_247 ( V_289 == V_279 ) )
break;
if ( type == V_290 )
V_199 = F_248 ( V_181 ) ;
else
V_199 = F_249 ( V_181 ) ;
if ( V_199 > 0 )
V_288 [ V_289 ++ ] = V_199 ;
}
F_221 ( & V_262 ) ;
V_279 = V_289 ;
if ( F_170 ( V_3 ) )
F_250 ( V_288 , V_279 , sizeof( V_267 ) , F_240 , NULL ) ;
else
F_250 ( V_288 , V_279 , sizeof( V_267 ) , F_239 , NULL ) ;
if ( type == V_290 )
V_279 = F_236 ( V_288 , V_279 ) ;
V_263 = F_243 ( V_3 , type ) ;
if ( ! V_263 ) {
F_14 ( & V_3 -> V_155 ) ;
F_227 ( V_288 ) ;
return - V_63 ;
}
F_227 ( V_263 -> V_277 ) ;
V_263 -> V_277 = V_288 ;
V_263 -> V_279 = V_279 ;
* V_287 = V_263 ;
return 0 ;
}
int F_251 ( struct V_291 * V_292 , struct V_163 * V_163 )
{
struct V_225 * V_18 = F_252 ( V_163 ) ;
struct V_2 * V_3 ;
struct V_261 V_262 ;
struct V_84 * V_181 ;
if ( V_163 -> V_293 -> V_294 != & V_295 || ! V_18 ||
F_183 ( V_18 ) != V_228 )
return - V_130 ;
F_13 ( & V_9 ) ;
F_149 () ;
V_3 = F_253 ( V_18 -> V_20 ) ;
if ( ! V_3 || F_4 ( V_3 ) ) {
F_154 () ;
F_14 ( & V_9 ) ;
return - V_137 ;
}
F_154 () ;
F_219 ( & V_3 -> V_10 , & V_262 ) ;
while ( ( V_181 = F_220 ( & V_262 ) ) ) {
switch ( V_181 -> V_296 ) {
case V_297 :
V_292 -> V_298 ++ ;
break;
case V_299 :
V_292 -> V_300 ++ ;
break;
case V_301 :
V_292 -> V_302 ++ ;
break;
case V_303 :
V_292 -> V_304 ++ ;
break;
default:
if ( F_254 ( V_181 ) )
V_292 -> V_305 ++ ;
break;
}
}
F_221 ( & V_262 ) ;
F_14 ( & V_9 ) ;
return 0 ;
}
static void * F_255 ( struct V_13 * V_306 , T_5 * V_257 )
{
struct V_15 * V_16 = V_306 -> V_17 ;
struct V_2 * V_3 = F_6 ( V_306 ) -> V_2 ;
struct V_268 * V_263 ;
enum V_285 type = F_7 ( V_306 ) -> V_17 ;
int V_307 = 0 , V_199 = * V_257 ;
int * V_308 , V_111 ;
F_13 ( & V_3 -> V_155 ) ;
if ( V_16 -> V_20 )
V_16 -> V_20 = F_241 ( V_3 , type ) ;
if ( ! V_16 -> V_20 ) {
V_111 = F_246 ( V_3 , type ,
(struct V_268 * * ) & V_16 -> V_20 ) ;
if ( V_111 )
return F_128 ( V_111 ) ;
}
V_263 = V_16 -> V_20 ;
if ( V_199 ) {
int V_309 = V_263 -> V_279 ;
while ( V_307 < V_309 ) {
int V_310 = ( V_307 + V_309 ) / 2 ;
if ( F_238 ( V_3 , V_263 -> V_277 [ V_310 ] ) == V_199 ) {
V_307 = V_310 ;
break;
} else if ( F_238 ( V_3 , V_263 -> V_277 [ V_310 ] ) <= V_199 )
V_307 = V_310 + 1 ;
else
V_309 = V_310 ;
}
}
if ( V_307 >= V_263 -> V_279 )
return NULL ;
V_308 = V_263 -> V_277 + V_307 ;
* V_257 = F_238 ( V_3 , * V_308 ) ;
return V_308 ;
}
static void F_256 ( struct V_13 * V_306 , void * V_219 )
{
struct V_15 * V_16 = V_306 -> V_17 ;
struct V_268 * V_263 = V_16 -> V_20 ;
if ( V_263 )
F_230 ( V_270 , & V_263 -> V_271 ,
V_311 ) ;
F_14 ( & F_6 ( V_306 ) -> V_2 -> V_155 ) ;
}
static void * F_257 ( struct V_13 * V_306 , void * V_219 , T_5 * V_257 )
{
struct V_15 * V_16 = V_306 -> V_17 ;
struct V_268 * V_263 = V_16 -> V_20 ;
V_267 * V_144 = V_219 ;
V_267 * V_309 = V_263 -> V_277 + V_263 -> V_279 ;
V_144 ++ ;
if ( V_144 >= V_309 ) {
return NULL ;
} else {
* V_257 = F_238 ( F_6 ( V_306 ) -> V_2 , * V_144 ) ;
return V_144 ;
}
}
static int F_258 ( struct V_13 * V_306 , void * V_219 )
{
return F_94 ( V_306 , L_29 , * ( int * ) V_219 ) ;
}
static T_3 F_259 ( struct V_1 * V_27 ,
struct V_21 * V_22 )
{
return F_11 ( V_27 -> V_2 ) ;
}
static int F_260 ( struct V_1 * V_27 ,
struct V_21 * V_22 , T_3 V_312 )
{
F_261 ( V_25 , & V_27 -> V_2 -> V_12 ) ;
if ( V_312 )
F_24 ( V_26 , & V_27 -> V_2 -> V_12 ) ;
else
F_261 ( V_26 , & V_27 -> V_2 -> V_12 ) ;
return 0 ;
}
static T_3 F_262 ( struct V_1 * V_27 ,
struct V_21 * V_22 )
{
return F_5 ( V_120 , & V_27 -> V_2 -> V_12 ) ;
}
static int F_263 ( struct V_1 * V_27 ,
struct V_21 * V_22 , T_3 V_312 )
{
if ( V_312 )
F_24 ( V_120 , & V_27 -> V_2 -> V_12 ) ;
else
F_261 ( V_120 , & V_27 -> V_2 -> V_12 ) ;
return 0 ;
}
static int F_87 ( struct V_2 * V_3 , unsigned long V_58 )
{
struct V_4 * V_5 ;
int V_29 , V_111 = 0 ;
F_16 (ss, i) {
struct V_21 * V_107 ;
if ( ! F_5 ( V_29 , & V_58 ) )
continue;
F_53 (cfts, &ss->cfts, node) {
V_111 = F_86 ( V_3 , V_107 , true ) ;
if ( V_111 < 0 )
goto V_192;
}
}
return 0 ;
V_192:
F_85 ( V_3 , V_58 ) ;
return V_111 ;
}
static void F_264 ( struct V_101 * V_102 )
{
struct V_1 * V_27 =
F_73 ( V_102 , struct V_1 , V_103 ) ;
struct V_2 * V_3 = V_27 -> V_2 ;
if ( V_27 -> V_19 )
F_265 ( V_27 -> V_19 ) ;
V_27 -> V_5 -> V_313 ( V_27 ) ;
F_76 ( V_3 ) ;
}
static void F_266 ( struct V_43 * V_43 )
{
struct V_1 * V_27 =
F_73 ( V_43 , struct V_1 , V_43 ) ;
F_79 ( & V_27 -> V_103 , F_264 ) ;
F_80 ( V_105 , & V_27 -> V_103 ) ;
}
static void F_267 ( struct V_314 * V_315 )
{
struct V_1 * V_27 =
F_73 ( V_315 , struct V_1 , V_106 ) ;
F_90 ( V_27 -> V_2 -> V_6 [ V_27 -> V_5 -> V_7 ] , NULL ) ;
F_82 ( & V_27 -> V_43 , F_266 ) ;
}
static void F_268 ( struct V_1 * V_27 , struct V_4 * V_5 ,
struct V_2 * V_3 )
{
V_27 -> V_2 = V_3 ;
V_27 -> V_5 = V_5 ;
V_27 -> V_12 = 0 ;
if ( V_3 -> V_19 )
V_27 -> V_19 = F_1 ( V_3 -> V_19 , V_5 ) ;
else
V_27 -> V_12 |= V_316 ;
F_35 ( F_1 ( V_3 , V_5 ) ) ;
}
static int F_269 ( struct V_1 * V_27 )
{
struct V_4 * V_5 = V_27 -> V_5 ;
int V_111 = 0 ;
F_18 ( & V_8 ) ;
F_18 ( & V_9 ) ;
if ( V_5 -> V_317 )
V_111 = V_5 -> V_317 ( V_27 ) ;
if ( ! V_111 ) {
V_27 -> V_12 |= V_318 ;
V_27 -> V_2 -> V_319 ++ ;
F_91 ( V_27 -> V_2 -> V_6 [ V_5 -> V_7 ] , V_27 ) ;
}
return V_111 ;
}
static void F_270 ( struct V_1 * V_27 )
{
struct V_4 * V_5 = V_27 -> V_5 ;
F_18 ( & V_8 ) ;
F_18 ( & V_9 ) ;
if ( ! ( V_27 -> V_12 & V_318 ) )
return;
if ( V_5 -> V_320 )
V_5 -> V_320 ( V_27 ) ;
V_27 -> V_12 &= ~ V_318 ;
V_27 -> V_2 -> V_319 -- ;
F_90 ( V_27 -> V_2 -> V_6 [ V_5 -> V_7 ] , V_27 ) ;
}
static int F_271 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_2 * V_19 = V_3 -> V_19 ;
struct V_1 * V_27 ;
int V_192 ;
F_18 ( & V_9 ) ;
V_27 = V_5 -> V_321 ( F_1 ( V_19 , V_5 ) ) ;
if ( F_121 ( V_27 ) )
return F_122 ( V_27 ) ;
V_192 = F_272 ( & V_27 -> V_106 , F_267 ) ;
if ( V_192 )
goto V_322;
F_268 ( V_27 , V_5 , V_3 ) ;
V_192 = F_87 ( V_3 , 1 << V_5 -> V_7 ) ;
if ( V_192 )
goto V_323;
V_192 = F_269 ( V_27 ) ;
if ( V_192 )
goto V_324;
F_81 ( V_3 ) ;
F_273 ( V_27 -> V_19 ) ;
V_3 -> V_58 |= 1 << V_5 -> V_7 ;
if ( V_5 -> V_325 && ! V_5 -> V_326 &&
V_19 -> V_19 ) {
F_88 ( L_33 ,
V_141 -> V_142 , V_141 -> V_199 , V_5 -> V_90 ) ;
if ( ! strcmp ( V_5 -> V_90 , L_34 ) )
F_88 ( L_35 ) ;
V_5 -> V_326 = true ;
}
return 0 ;
V_324:
F_85 ( V_27 -> V_2 , 1 << V_27 -> V_5 -> V_7 ) ;
V_323:
F_274 ( & V_27 -> V_106 ) ;
V_322:
V_5 -> V_313 ( V_27 ) ;
return V_192 ;
}
static long F_275 ( struct V_2 * V_19 , const char * V_90 ,
T_1 V_91 )
{
struct V_2 * V_3 ;
struct V_57 * V_56 = V_19 -> V_56 ;
int V_110 , V_192 ;
struct V_4 * V_5 ;
struct V_225 * V_18 ;
if ( V_56 == & V_80 )
return - V_130 ;
V_3 = F_42 ( sizeof( * V_3 ) , V_62 ) ;
if ( ! V_3 )
return - V_63 ;
F_13 ( & V_8 ) ;
if ( ! F_12 ( V_19 ) ) {
V_192 = - V_202 ;
goto V_327;
}
V_3 -> V_7 = F_119 ( & V_56 -> V_77 , NULL , 1 , 0 , V_62 ) ;
if ( V_3 -> V_7 < 0 ) {
V_192 = - V_63 ;
goto V_328;
}
F_113 ( V_3 ) ;
V_3 -> V_19 = V_19 ;
V_3 -> V_10 . V_19 = & V_19 -> V_10 ;
V_3 -> V_56 = V_19 -> V_56 ;
if ( F_11 ( V_19 ) )
F_24 ( V_26 , & V_3 -> V_12 ) ;
if ( F_5 ( V_120 , & V_19 -> V_12 ) )
F_24 ( V_120 , & V_3 -> V_12 ) ;
V_18 = F_276 ( V_19 -> V_18 , V_90 , V_91 , V_3 ) ;
if ( F_121 ( V_18 ) ) {
V_192 = F_122 ( V_18 ) ;
goto V_329;
}
V_3 -> V_18 = V_18 ;
F_277 ( V_18 ) ;
V_3 -> V_258 = V_330 ++ ;
F_278 ( & V_3 -> V_152 , & V_3 -> V_19 -> V_79 ) ;
F_33 ( & V_56 -> V_78 ) ;
F_81 ( V_19 ) ;
F_279 ( & V_56 -> V_77 , V_3 , V_3 -> V_7 ) ;
V_192 = F_187 ( V_18 ) ;
if ( V_192 )
goto V_331;
V_192 = F_86 ( V_3 , V_160 , true ) ;
if ( V_192 )
goto V_331;
F_16 (ss, ssid) {
if ( V_56 -> V_3 . V_58 & ( 1 << V_110 ) ) {
V_192 = F_271 ( V_3 , V_5 ) ;
if ( V_192 )
goto V_331;
}
}
F_92 ( V_18 ) ;
F_14 ( & V_9 ) ;
F_14 ( & V_8 ) ;
return 0 ;
V_329:
F_59 ( & V_56 -> V_77 , V_3 -> V_7 ) ;
V_328:
F_14 ( & V_9 ) ;
V_327:
F_14 ( & V_8 ) ;
F_26 ( V_3 ) ;
return V_192 ;
V_331:
F_280 ( V_3 ) ;
F_14 ( & V_9 ) ;
F_14 ( & V_8 ) ;
return V_192 ;
}
static int F_281 ( struct V_225 * V_332 , const char * V_90 ,
T_1 V_91 )
{
struct V_2 * V_19 = V_332 -> V_20 ;
int V_111 ;
F_81 ( V_19 ) ;
F_184 ( V_332 ) ;
V_111 = F_275 ( V_19 , V_90 , V_91 ) ;
F_186 ( V_332 ) ;
F_76 ( V_19 ) ;
return V_111 ;
}
static void F_282 ( struct V_101 * V_102 )
{
struct V_1 * V_27 =
F_73 ( V_102 , struct V_1 , V_103 ) ;
struct V_2 * V_3 = V_27 -> V_2 ;
F_13 ( & V_8 ) ;
F_13 ( & V_9 ) ;
F_270 ( V_27 ) ;
if ( ! V_3 -> V_319 && F_4 ( V_3 ) )
F_283 ( V_3 ) ;
F_14 ( & V_9 ) ;
F_14 ( & V_8 ) ;
F_265 ( V_27 ) ;
}
static void F_284 ( struct V_314 * V_315 )
{
struct V_1 * V_27 =
F_73 ( V_315 , struct V_1 , V_106 ) ;
F_79 ( & V_27 -> V_103 , F_282 ) ;
F_80 ( V_105 , & V_27 -> V_103 ) ;
}
static void F_285 ( struct V_1 * V_27 )
{
F_18 ( & V_8 ) ;
F_85 ( V_27 -> V_2 , 1 << V_27 -> V_5 -> V_7 ) ;
F_273 ( V_27 ) ;
F_286 ( & V_27 -> V_106 , F_284 ) ;
}
static void F_287 ( struct V_1 * V_27 )
{
struct V_2 * V_3 = V_27 -> V_2 ;
F_18 ( & V_8 ) ;
if ( V_3 -> V_58 & ( 1 << V_27 -> V_5 -> V_7 ) ) {
V_3 -> V_58 &= ~ ( 1 << V_27 -> V_5 -> V_7 ) ;
F_285 ( V_27 ) ;
}
}
static int F_280 ( struct V_2 * V_3 )
__releases( &cgroup_mutex
static void F_283 ( struct V_2 * V_3 )
{
struct V_2 * V_19 = V_3 -> V_19 ;
F_18 ( & V_8 ) ;
F_18 ( & V_9 ) ;
F_288 ( & V_3 -> V_152 ) ;
F_76 ( V_3 ) ;
F_24 ( V_25 , & V_19 -> V_12 ) ;
F_25 ( V_19 ) ;
}
static int F_289 ( struct V_225 * V_18 )
{
struct V_2 * V_3 = V_18 -> V_20 ;
int V_111 = 0 ;
F_81 ( V_3 ) ;
F_184 ( V_18 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_9 ) ;
if ( ! F_4 ( V_3 ) )
V_111 = F_280 ( V_3 ) ;
F_14 ( & V_9 ) ;
F_14 ( & V_8 ) ;
F_186 ( V_18 ) ;
F_76 ( V_3 ) ;
return V_111 ;
}
static void T_6 F_290 ( struct V_4 * V_5 )
{
struct V_1 * V_27 ;
F_291 ( V_333 L_36 , V_5 -> V_90 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_9 ) ;
F_41 ( & V_5 -> V_107 ) ;
V_5 -> V_56 = & V_80 ;
V_27 = V_5 -> V_321 ( F_1 ( & V_80 . V_3 , V_5 ) ) ;
F_35 ( F_121 ( V_27 ) ) ;
F_268 ( V_27 , V_5 , & V_80 . V_3 ) ;
V_83 . V_6 [ V_5 -> V_7 ] = V_27 ;
V_334 |= V_5 -> V_335 || V_5 -> exit ;
F_35 ( ! F_23 ( & V_336 . V_66 ) ) ;
F_35 ( F_269 ( V_27 ) ) ;
V_80 . V_3 . V_58 |= 1 << V_5 -> V_7 ;
F_14 ( & V_9 ) ;
F_14 ( & V_8 ) ;
}
int T_6 F_292 ( void )
{
static struct V_122 T_7 V_123 =
{ . V_12 = V_116 } ;
struct V_4 * V_5 ;
int V_29 ;
F_115 ( & V_80 , & V_123 ) ;
F_90 ( V_336 . V_183 , & V_83 ) ;
F_16 (ss, i) {
F_293 ( ! V_5 -> V_321 || ! V_5 -> V_313 || V_5 -> V_90 || V_5 -> V_7 ,
L_37 ,
V_29 , V_337 [ V_29 ] , V_5 -> V_321 , V_5 -> V_313 ,
V_5 -> V_7 , V_5 -> V_90 ) ;
F_293 ( strlen ( V_337 [ V_29 ] ) > V_338 ,
L_38 , V_337 [ V_29 ] ) ;
V_5 -> V_7 = V_29 ;
V_5 -> V_90 = V_337 [ V_29 ] ;
if ( V_5 -> V_339 )
F_290 ( V_5 ) ;
}
return 0 ;
}
int T_6 F_294 ( void )
{
struct V_4 * V_5 ;
unsigned long V_28 ;
int V_110 , V_192 ;
F_35 ( F_201 ( NULL , V_160 ) ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_9 ) ;
V_28 = F_15 ( V_83 . V_6 ) ;
F_54 ( V_71 , & V_83 . V_38 , V_28 ) ;
F_35 ( F_117 ( & V_80 , 0 ) ) ;
F_14 ( & V_9 ) ;
F_14 ( & V_8 ) ;
F_16 (ss, ssid) {
if ( ! V_5 -> V_339 )
F_290 ( V_5 ) ;
if ( V_5 -> V_340 )
F_89 ( F_205 ( V_5 , V_5 -> V_340 ) ) ;
}
V_341 = F_295 ( L_39 , V_342 ) ;
if ( ! V_341 )
return - V_63 ;
V_192 = F_296 ( & V_295 ) ;
if ( V_192 < 0 ) {
F_297 ( V_341 ) ;
return V_192 ;
}
F_298 ( L_40 , 0 , NULL , & V_343 ) ;
return 0 ;
}
static int T_6 F_299 ( void )
{
V_105 = F_300 ( L_41 , 0 , 1 ) ;
F_35 ( ! V_105 ) ;
V_270 = F_300 ( L_42 ,
0 , 1 ) ;
F_35 ( ! V_270 ) ;
return 0 ;
}
int F_301 ( struct V_13 * V_223 , void * V_219 )
{
struct V_199 * V_199 ;
struct V_84 * V_181 ;
char * V_86 , * V_174 ;
int V_215 ;
struct V_57 * V_56 ;
V_215 = - V_63 ;
V_86 = F_226 ( V_134 , V_62 ) ;
if ( ! V_86 )
goto V_156;
V_215 = - V_204 ;
V_199 = V_223 -> V_17 ;
V_181 = F_302 ( V_199 , V_344 ) ;
if ( ! V_181 )
goto V_345;
V_215 = 0 ;
F_13 ( & V_9 ) ;
F_49 ( & V_36 ) ;
F_125 (root) {
struct V_4 * V_5 ;
struct V_2 * V_3 ;
int V_110 , V_60 = 0 ;
if ( V_56 == & V_80 && ! V_113 )
continue;
F_94 ( V_223 , L_43 , V_56 -> V_76 ) ;
F_16 (ss, ssid)
if ( V_56 -> V_3 . V_58 & ( 1 << V_110 ) )
F_94 ( V_223 , L_44 , V_60 ++ ? L_11 : L_25 , V_5 -> V_90 ) ;
if ( strlen ( V_56 -> V_90 ) )
F_94 ( V_223 , L_45 , V_60 ? L_11 : L_25 ,
V_56 -> V_90 ) ;
F_168 ( V_223 , ':' ) ;
V_3 = F_68 ( V_181 , V_56 ) ;
V_174 = F_135 ( V_3 , V_86 , V_134 ) ;
if ( ! V_174 ) {
V_215 = - V_346 ;
goto V_140;
}
F_95 ( V_223 , V_174 ) ;
F_168 ( V_223 , '\n' ) ;
}
V_140:
F_50 ( & V_36 ) ;
F_14 ( & V_9 ) ;
F_161 ( V_181 ) ;
V_345:
F_26 ( V_86 ) ;
V_156:
return V_215 ;
}
static int F_303 ( struct V_13 * V_223 , void * V_219 )
{
struct V_4 * V_5 ;
int V_29 ;
F_95 ( V_223 , L_46 ) ;
F_13 ( & V_9 ) ;
F_16 (ss, i)
F_94 ( V_223 , L_47 ,
V_5 -> V_90 , V_5 -> V_56 -> V_76 ,
F_64 ( & V_5 -> V_56 -> V_78 ) , ! V_5 -> V_136 ) ;
F_14 ( & V_9 ) ;
return 0 ;
}
static int F_304 ( struct V_347 * V_347 , struct V_348 * V_348 )
{
return F_305 ( V_348 , F_303 , NULL ) ;
}
void F_306 ( struct V_84 * V_349 )
{
F_90 ( V_349 -> V_183 , & V_83 ) ;
F_41 ( & V_349 -> V_148 ) ;
}
void F_307 ( struct V_84 * V_349 )
{
struct V_4 * V_5 ;
int V_29 ;
if ( V_146 ) {
struct V_30 * V_31 ;
F_30 ( & V_36 ) ;
V_31 = F_69 ( V_141 ) ;
if ( F_23 ( & V_349 -> V_148 ) ) {
F_91 ( V_349 -> V_183 , V_31 ) ;
F_43 ( & V_349 -> V_148 , & V_31 -> V_66 ) ;
F_32 ( V_31 ) ;
}
F_31 ( & V_36 ) ;
}
if ( V_334 ) {
F_16 (ss, i)
if ( V_5 -> V_335 )
V_5 -> V_335 ( V_349 ) ;
}
}
void F_308 ( struct V_84 * V_181 )
{
struct V_4 * V_5 ;
struct V_30 * V_31 ;
bool V_350 = false ;
int V_29 ;
if ( ! F_23 ( & V_181 -> V_148 ) ) {
F_30 ( & V_36 ) ;
F_143 ( & V_181 -> V_148 ) ;
F_31 ( & V_36 ) ;
V_350 = true ;
}
V_31 = F_69 ( V_181 ) ;
F_90 ( V_181 -> V_183 , & V_83 ) ;
if ( V_334 ) {
F_16 (ss, i) {
if ( V_5 -> exit ) {
struct V_1 * V_351 = V_31 -> V_6 [ V_29 ] ;
struct V_1 * V_27 = F_309 ( V_181 , V_29 ) ;
V_5 -> exit ( V_27 , V_351 , V_181 ) ;
}
}
}
if ( V_350 )
F_28 ( V_31 , true ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
if ( F_10 ( V_3 ) &&
F_23 ( & V_3 -> V_42 ) && F_23 ( & V_3 -> V_79 ) ) {
int V_352 = 0 ;
F_310 ( & V_353 ) ;
if ( ! F_4 ( V_3 ) &&
F_23 ( & V_3 -> V_153 ) ) {
F_43 ( & V_3 -> V_153 , & V_153 ) ;
V_352 = 1 ;
}
F_311 ( & V_353 ) ;
if ( V_352 )
F_312 ( & V_354 ) ;
}
}
static void F_313 ( struct V_101 * V_102 )
{
F_35 ( V_102 != & V_354 ) ;
F_13 ( & V_9 ) ;
F_310 ( & V_353 ) ;
while ( ! F_23 ( & V_153 ) ) {
char * V_355 [ 3 ] , * V_356 [ 3 ] ;
int V_29 ;
char * V_357 = NULL , * V_358 = NULL , * V_174 ;
struct V_2 * V_3 = F_36 ( V_153 . V_55 ,
struct V_2 ,
V_153 ) ;
F_143 ( & V_3 -> V_153 ) ;
F_311 ( & V_353 ) ;
V_357 = F_226 ( V_134 , V_62 ) ;
if ( ! V_357 )
goto V_359;
V_174 = F_135 ( V_3 , V_357 , V_134 ) ;
if ( ! V_174 )
goto V_359;
V_358 = F_314 ( V_3 -> V_56 -> V_119 , V_62 ) ;
if ( ! V_358 )
goto V_359;
V_29 = 0 ;
V_355 [ V_29 ++ ] = V_358 ;
V_355 [ V_29 ++ ] = V_174 ;
V_355 [ V_29 ] = NULL ;
V_29 = 0 ;
V_356 [ V_29 ++ ] = L_48 ;
V_356 [ V_29 ++ ] = L_49 ;
V_356 [ V_29 ] = NULL ;
F_14 ( & V_9 ) ;
F_315 ( V_355 [ 0 ] , V_355 , V_356 , V_360 ) ;
F_13 ( & V_9 ) ;
V_359:
F_26 ( V_357 ) ;
F_26 ( V_358 ) ;
F_310 ( & V_353 ) ;
}
F_311 ( & V_353 ) ;
F_14 ( & V_9 ) ;
}
static int T_6 F_316 ( char * V_361 )
{
struct V_4 * V_5 ;
char * V_124 ;
int V_29 ;
while ( ( V_124 = F_101 ( & V_361 , L_11 ) ) != NULL ) {
if ( ! * V_124 )
continue;
F_16 (ss, i) {
if ( ! strcmp ( V_124 , V_5 -> V_90 ) ) {
V_5 -> V_136 = 1 ;
F_291 ( V_333 L_50
L_51 , V_5 -> V_90 ) ;
break;
}
}
}
return 1 ;
}
struct V_1 * F_317 ( struct V_163 * V_163 ,
struct V_4 * V_5 )
{
struct V_225 * V_18 = F_252 ( V_163 ) ;
struct V_1 * V_27 = NULL ;
struct V_2 * V_3 ;
if ( V_163 -> V_293 -> V_294 != & V_295 || ! V_18 ||
F_183 ( V_18 ) != V_228 )
return F_128 ( - V_362 ) ;
F_149 () ;
V_3 = F_253 ( V_18 -> V_20 ) ;
if ( V_3 )
V_27 = F_1 ( V_3 , V_5 ) ;
if ( ! V_27 || ! F_318 ( V_27 ) )
V_27 = F_128 ( - V_137 ) ;
F_154 () ;
return V_27 ;
}
struct V_1 * F_319 ( int V_7 , struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_208 () ;
V_3 = F_320 ( & V_5 -> V_56 -> V_77 , V_7 ) ;
if ( V_3 )
return F_1 ( V_3 , V_5 ) ;
return NULL ;
}
static struct V_1 *
F_321 ( struct V_1 * V_256 )
{
struct V_1 * V_27 = F_42 ( sizeof( * V_27 ) , V_62 ) ;
if ( ! V_27 )
return F_128 ( - V_63 ) ;
return V_27 ;
}
static void F_322 ( struct V_1 * V_27 )
{
F_26 ( V_27 ) ;
}
static T_3 F_323 ( struct V_1 * V_27 ,
struct V_21 * V_22 )
{
return F_206 ( V_27 -> V_2 ) ;
}
static T_3 F_324 ( struct V_1 * V_27 ,
struct V_21 * V_22 )
{
return ( T_3 ) ( unsigned long ) V_141 -> V_183 ;
}
static T_3 F_325 ( struct V_1 * V_27 ,
struct V_21 * V_22 )
{
T_3 V_60 ;
F_149 () ;
V_60 = F_64 ( & F_69 ( V_141 ) -> V_37 ) ;
F_154 () ;
return V_60 ;
}
static int F_326 ( struct V_13 * V_14 , void * V_219 )
{
struct V_33 * V_34 ;
struct V_30 * V_31 ;
char * V_363 ;
V_363 = F_226 ( V_364 + 1 , V_62 ) ;
if ( ! V_363 )
return - V_63 ;
F_49 ( & V_36 ) ;
F_149 () ;
V_31 = F_253 ( V_141 -> V_183 ) ;
F_53 (link, &cset->cgrp_links, cgrp_link) {
struct V_2 * V_70 = V_34 -> V_3 ;
F_327 ( V_70 , V_363 , V_364 + 1 ) ;
F_94 ( V_14 , L_52 ,
V_70 -> V_56 -> V_76 , V_363 ) ;
}
F_154 () ;
F_50 ( & V_36 ) ;
F_26 ( V_363 ) ;
return 0 ;
}
static int F_328 ( struct V_13 * V_14 , void * V_219 )
{
struct V_1 * V_27 = F_6 ( V_14 ) ;
struct V_33 * V_34 ;
F_49 ( & V_36 ) ;
F_53 (link, &css->cgroup->cset_links, cset_link) {
struct V_30 * V_31 = V_34 -> V_31 ;
struct V_84 * V_85 ;
int V_60 = 0 ;
F_94 ( V_14 , L_53 , V_31 ) ;
F_53 (task, &cset->tasks, cg_list) {
if ( V_60 ++ > V_365 )
goto V_366;
F_94 ( V_14 , L_54 , F_249 ( V_85 ) ) ;
}
F_53 (task, &cset->mg_tasks, cg_list) {
if ( V_60 ++ > V_365 )
goto V_366;
F_94 ( V_14 , L_54 , F_249 ( V_85 ) ) ;
}
continue;
V_366:
F_95 ( V_14 , L_55 ) ;
}
F_50 ( & V_36 ) ;
return 0 ;
}
static T_3 F_329 ( struct V_1 * V_27 , struct V_21 * V_22 )
{
return F_5 ( V_25 , & V_27 -> V_2 -> V_12 ) ;
}
