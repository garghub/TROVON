static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( V_5 )
return F_2 ( V_3 -> V_6 [ V_5 -> V_7 ] ,
F_3 ( & V_8 ) ) ;
else
return & V_3 -> V_9 ;
}
static inline bool F_4 ( const struct V_2 * V_3 )
{
return F_5 ( V_10 , & V_3 -> V_11 ) ;
}
bool F_6 ( struct V_2 * V_3 , struct V_2 * V_12 )
{
while ( V_3 ) {
if ( V_3 == V_12 )
return true ;
V_3 = V_3 -> V_13 ;
}
return false ;
}
static int F_7 ( const struct V_2 * V_3 )
{
const int V_14 =
( 1 << V_15 ) |
( 1 << V_16 ) ;
return ( V_3 -> V_11 & V_14 ) == V_14 ;
}
static int F_8 ( const struct V_2 * V_3 )
{
return F_5 ( V_16 , & V_3 -> V_11 ) ;
}
static inline struct V_2 * F_9 ( struct V_17 * V_17 )
{
return V_17 -> V_18 ;
}
static inline struct V_19 * F_10 ( struct V_17 * V_17 )
{
return V_17 -> V_18 ;
}
static inline struct V_20 * F_11 ( struct V_17 * V_17 )
{
return F_10 ( V_17 ) -> type ;
}
static bool F_12 ( struct V_2 * V_3 )
{
F_13 ( & V_8 ) ;
if ( F_4 ( V_3 ) ) {
F_14 ( & V_8 ) ;
return false ;
}
return true ;
}
static unsigned long F_15 ( struct V_1 * V_21 [] )
{
unsigned long V_22 = 0UL ;
struct V_4 * V_5 ;
int V_23 ;
F_16 (ss, i)
V_22 += ( unsigned long ) V_21 [ V_23 ] ;
V_22 = ( V_22 >> 16 ) ^ V_22 ;
return V_22 ;
}
static void F_17 ( struct V_24 * V_25 , int V_26 )
{
struct V_27 * V_28 , * V_29 ;
if ( F_18 ( & V_25 -> V_30 , - 1 , 1 ) )
return;
F_19 ( & V_31 ) ;
if ( ! F_20 ( & V_25 -> V_30 ) ) {
F_21 ( & V_31 ) ;
return;
}
F_22 ( & V_25 -> V_32 ) ;
V_33 -- ;
F_23 (link, tmp_link, &cset->cgrp_links, cgrp_link) {
struct V_2 * V_3 = V_28 -> V_3 ;
F_24 ( & V_28 -> V_34 ) ;
F_24 ( & V_28 -> V_35 ) ;
if ( F_25 ( & V_3 -> V_36 ) && F_8 ( V_3 ) ) {
if ( V_26 )
F_26 ( V_15 , & V_3 -> V_11 ) ;
F_27 ( V_3 ) ;
}
F_28 ( V_28 ) ;
}
F_21 ( & V_31 ) ;
F_29 ( V_25 , V_37 ) ;
}
static inline void F_30 ( struct V_24 * V_25 )
{
F_31 ( & V_25 -> V_30 ) ;
}
static inline void F_32 ( struct V_24 * V_25 )
{
F_17 ( V_25 , 0 ) ;
}
static inline void F_33 ( struct V_24 * V_25 )
{
F_17 ( V_25 , 1 ) ;
}
static bool F_34 ( struct V_24 * V_25 ,
struct V_24 * V_38 ,
struct V_2 * V_39 ,
struct V_1 * V_40 [] )
{
struct V_41 * V_42 , * V_43 ;
if ( memcmp ( V_40 , V_25 -> V_6 , sizeof( V_25 -> V_6 ) ) ) {
return false ;
}
V_42 = & V_25 -> V_44 ;
V_43 = & V_38 -> V_44 ;
while ( 1 ) {
struct V_27 * V_45 , * V_46 ;
struct V_2 * V_47 , * V_48 ;
V_42 = V_42 -> V_49 ;
V_43 = V_43 -> V_49 ;
if ( V_42 == & V_25 -> V_44 ) {
F_35 ( V_43 != & V_38 -> V_44 ) ;
break;
} else {
F_35 ( V_43 == & V_38 -> V_44 ) ;
}
V_45 = F_36 ( V_42 , struct V_27 , V_35 ) ;
V_46 = F_36 ( V_43 , struct V_27 , V_35 ) ;
V_47 = V_45 -> V_3 ;
V_48 = V_46 -> V_3 ;
F_35 ( V_47 -> V_50 != V_48 -> V_50 ) ;
if ( V_47 -> V_50 == V_39 -> V_50 ) {
if ( V_47 != V_39 )
return false ;
} else {
if ( V_47 != V_48 )
return false ;
}
}
return true ;
}
static struct V_24 * F_37 ( struct V_24 * V_38 ,
struct V_2 * V_3 ,
struct V_1 * V_40 [] )
{
struct V_51 * V_50 = V_3 -> V_50 ;
struct V_4 * V_5 ;
struct V_24 * V_25 ;
unsigned long V_22 ;
int V_23 ;
F_16 (ss, i) {
if ( V_50 -> V_52 & ( 1UL << V_23 ) ) {
V_40 [ V_23 ] = F_1 ( V_3 , V_5 ) ;
} else {
V_40 [ V_23 ] = V_38 -> V_6 [ V_23 ] ;
}
}
V_22 = F_15 ( V_40 ) ;
F_38 (css_set_table, cset, hlist, key) {
if ( ! F_34 ( V_25 , V_38 , V_3 , V_40 ) )
continue;
return V_25 ;
}
return NULL ;
}
static void F_39 ( struct V_41 * V_53 )
{
struct V_27 * V_28 , * V_29 ;
F_23 (link, tmp_link, links_to_free, cset_link) {
F_24 ( & V_28 -> V_34 ) ;
F_28 ( V_28 ) ;
}
}
static int F_40 ( int V_54 , struct V_41 * V_55 )
{
struct V_27 * V_28 ;
int V_23 ;
F_41 ( V_55 ) ;
for ( V_23 = 0 ; V_23 < V_54 ; V_23 ++ ) {
V_28 = F_42 ( sizeof( * V_28 ) , V_56 ) ;
if ( ! V_28 ) {
F_39 ( V_55 ) ;
return - V_57 ;
}
F_43 ( & V_28 -> V_34 , V_55 ) ;
}
return 0 ;
}
static void F_44 ( struct V_41 * V_55 , struct V_24 * V_25 ,
struct V_2 * V_3 )
{
struct V_27 * V_28 ;
F_35 ( F_25 ( V_55 ) ) ;
V_28 = F_45 ( V_55 , struct V_27 , V_34 ) ;
V_28 -> V_25 = V_25 ;
V_28 -> V_3 = V_3 ;
F_46 ( & V_28 -> V_34 , & V_3 -> V_36 ) ;
F_47 ( & V_28 -> V_35 , & V_25 -> V_44 ) ;
}
static struct V_24 * F_48 ( struct V_24 * V_38 ,
struct V_2 * V_3 )
{
struct V_1 * V_40 [ V_58 ] = { } ;
struct V_24 * V_25 ;
struct V_41 V_55 ;
struct V_27 * V_28 ;
unsigned long V_22 ;
F_49 ( & V_8 ) ;
F_50 ( & V_31 ) ;
V_25 = F_37 ( V_38 , V_3 , V_40 ) ;
if ( V_25 )
F_30 ( V_25 ) ;
F_51 ( & V_31 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_42 ( sizeof( * V_25 ) , V_56 ) ;
if ( ! V_25 )
return NULL ;
if ( F_40 ( V_59 , & V_55 ) < 0 ) {
F_28 ( V_25 ) ;
return NULL ;
}
F_52 ( & V_25 -> V_30 , 1 ) ;
F_41 ( & V_25 -> V_44 ) ;
F_41 ( & V_25 -> V_60 ) ;
F_53 ( & V_25 -> V_32 ) ;
memcpy ( V_25 -> V_6 , V_40 , sizeof( V_25 -> V_6 ) ) ;
F_19 ( & V_31 ) ;
F_54 (link, &old_cset->cgrp_links, cgrp_link) {
struct V_2 * V_61 = V_28 -> V_3 ;
if ( V_61 -> V_50 == V_3 -> V_50 )
V_61 = V_3 ;
F_44 ( & V_55 , V_25 , V_61 ) ;
}
F_35 ( ! F_25 ( & V_55 ) ) ;
V_33 ++ ;
V_22 = F_15 ( V_25 -> V_6 ) ;
F_55 ( V_62 , & V_25 -> V_32 , V_22 ) ;
F_21 ( & V_31 ) ;
return V_25 ;
}
static struct V_2 * F_56 ( struct V_63 * V_64 ,
struct V_51 * V_50 )
{
struct V_24 * V_25 ;
struct V_2 * V_65 = NULL ;
F_35 ( ! F_57 ( & V_8 ) ) ;
F_50 ( & V_31 ) ;
V_25 = F_58 ( V_64 ) ;
if ( V_25 == & V_66 ) {
V_65 = & V_50 -> V_67 ;
} else {
struct V_27 * V_28 ;
F_54 (link, &cset->cgrp_links, cgrp_link) {
struct V_2 * V_61 = V_28 -> V_3 ;
if ( V_61 -> V_50 == V_50 ) {
V_65 = V_61 ;
break;
}
}
}
F_51 ( & V_31 ) ;
F_35 ( ! V_65 ) ;
return V_65 ;
}
static struct V_68 * F_59 ( T_1 V_69 , struct V_70 * V_71 )
{
struct V_68 * V_68 = F_60 ( V_71 ) ;
if ( V_68 ) {
V_68 -> V_72 = F_61 () ;
V_68 -> V_73 = V_69 ;
V_68 -> V_74 = F_62 () ;
V_68 -> V_75 = F_63 () ;
V_68 -> V_76 = V_68 -> V_77 = V_68 -> V_78 = V_79 ;
V_68 -> V_80 -> V_81 = & V_82 ;
}
return V_68 ;
}
static struct V_83 * F_64 ( struct V_17 * V_17 )
{
struct V_83 * V_84 ;
V_84 = F_65 ( sizeof( * V_84 ) + V_17 -> V_85 . V_86 + 1 , V_56 ) ;
if ( ! V_84 )
return NULL ;
strcpy ( V_84 -> V_84 , V_17 -> V_85 . V_84 ) ;
return V_84 ;
}
static void F_66 ( struct V_87 * V_88 )
{
struct V_2 * V_3 = F_67 ( V_88 , struct V_2 , V_89 ) ;
F_13 ( & V_8 ) ;
V_3 -> V_50 -> V_90 -- ;
F_14 ( & V_8 ) ;
F_68 ( V_3 -> V_13 -> V_17 ) ;
F_69 ( V_3 -> V_50 -> V_71 ) ;
F_35 ( ! F_25 ( & V_3 -> V_91 ) ) ;
F_70 ( & V_3 -> V_92 ) ;
F_28 ( F_71 ( V_3 -> V_84 ) ) ;
F_28 ( V_3 ) ;
}
static void F_72 ( struct V_37 * V_93 )
{
struct V_2 * V_3 = F_67 ( V_93 , struct V_2 , V_37 ) ;
F_73 ( & V_3 -> V_89 , F_66 ) ;
F_74 ( V_94 , & V_3 -> V_89 ) ;
}
static void F_75 ( struct V_17 * V_17 , struct V_68 * V_68 )
{
if ( F_76 ( V_68 -> V_73 ) ) {
struct V_2 * V_3 = V_17 -> V_18 ;
F_35 ( ! ( F_4 ( V_3 ) ) ) ;
F_77 ( & V_3 -> V_50 -> V_95 , V_3 -> V_96 ) ;
V_3 -> V_96 = - 1 ;
F_78 ( & V_3 -> V_37 , F_72 ) ;
} else {
struct V_19 * V_97 = F_10 ( V_17 ) ;
struct V_2 * V_3 = V_17 -> V_98 -> V_18 ;
F_79 ( ! F_25 ( & V_97 -> V_99 ) &&
V_3 != & V_3 -> V_50 -> V_67 ,
L_1 , V_97 -> type -> V_84 ) ;
F_70 ( & V_97 -> V_92 ) ;
F_28 ( V_97 ) ;
}
F_80 ( V_68 ) ;
}
static void F_81 ( struct V_17 * V_100 )
{
struct V_17 * V_13 = F_82 ( V_100 -> V_98 ) ;
F_83 ( V_100 ) ;
F_84 ( V_13 -> V_101 , V_100 ) ;
F_68 ( V_13 ) ;
}
static void F_85 ( struct V_2 * V_3 , const struct V_20 * V_102 )
{
struct V_19 * V_97 ;
F_49 ( & V_3 -> V_17 -> V_101 -> V_103 ) ;
F_49 ( & V_8 ) ;
F_54 (cfe, &cgrp->files, node) {
struct V_17 * V_100 = V_97 -> V_17 ;
if ( V_102 && V_97 -> type != V_102 )
continue;
F_82 ( V_100 ) ;
F_83 ( V_100 ) ;
F_86 ( V_3 -> V_17 -> V_101 , V_100 ) ;
F_87 ( & V_97 -> V_99 ) ;
F_68 ( V_100 ) ;
break;
}
}
static void F_88 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_4 * V_5 ;
int V_23 ;
F_16 (ss, i) {
struct V_104 * V_105 ;
if ( ! F_5 ( V_23 , & V_52 ) )
continue;
F_54 (set, &ss->cftsets, node)
F_89 ( V_3 , V_105 -> V_106 , false ) ;
}
}
static void F_90 ( struct V_17 * V_17 )
{
struct V_17 * V_13 ;
V_13 = V_17 -> V_98 ;
F_91 ( & V_13 -> V_107 ) ;
F_92 ( & V_17 -> V_107 , V_108 ) ;
F_87 ( & V_17 -> V_109 . V_110 ) ;
F_93 ( & V_17 -> V_107 ) ;
F_93 ( & V_13 -> V_107 ) ;
F_81 ( V_17 ) ;
}
static int F_94 ( struct V_51 * V_50 ,
unsigned long V_111 , unsigned V_112 )
{
struct V_2 * V_3 = & V_50 -> V_67 ;
struct V_4 * V_5 ;
unsigned long V_113 = 0 ;
int V_23 , V_114 ;
F_35 ( ! F_57 ( & V_8 ) ) ;
F_35 ( ! F_57 ( & V_115 ) ) ;
F_16 (ss, i) {
if ( ! ( V_111 & ( 1 << V_23 ) ) )
continue;
if ( V_5 -> V_50 != & V_116 ) {
V_114 = - V_117 ;
goto V_118;
}
if ( ! F_95 ( V_5 -> V_119 ) ) {
V_114 = - V_120 ;
goto V_118;
}
V_113 |= 1 << V_23 ;
}
if ( V_111 != V_113 ) {
V_114 = - V_120 ;
goto V_118;
}
V_114 = F_96 ( V_3 , V_111 ) ;
if ( V_114 )
goto V_118;
F_88 ( V_3 , V_112 ) ;
F_16 (ss, i) {
unsigned long V_121 = 1UL << V_23 ;
if ( V_121 & V_111 ) {
F_35 ( F_1 ( V_3 , V_5 ) ) ;
F_35 ( ! F_1 ( V_122 , V_5 ) ) ;
F_35 ( F_1 ( V_122 , V_5 ) -> V_2 != V_122 ) ;
F_97 ( V_3 -> V_6 [ V_23 ] ,
F_1 ( V_122 , V_5 ) ) ;
F_1 ( V_3 , V_5 ) -> V_2 = V_3 ;
F_46 ( & V_5 -> V_123 , & V_50 -> V_124 ) ;
V_5 -> V_50 = V_50 ;
if ( V_5 -> V_125 )
V_5 -> V_125 ( F_1 ( V_3 , V_5 ) ) ;
V_50 -> V_52 |= V_121 ;
} else if ( V_121 & V_112 ) {
F_35 ( F_1 ( V_3 , V_5 ) != F_1 ( V_122 , V_5 ) ) ;
F_35 ( F_1 ( V_3 , V_5 ) -> V_2 != V_3 ) ;
if ( V_5 -> V_125 )
V_5 -> V_125 ( F_1 ( V_122 , V_5 ) ) ;
F_1 ( V_122 , V_5 ) -> V_2 = V_122 ;
F_98 ( V_3 -> V_6 [ V_23 ] , NULL ) ;
V_4 [ V_23 ] -> V_50 = & V_116 ;
F_46 ( & V_5 -> V_123 , & V_116 . V_124 ) ;
F_99 ( V_5 -> V_119 ) ;
V_50 -> V_52 &= ~ V_121 ;
}
}
V_50 -> V_11 |= V_126 ;
return 0 ;
V_118:
F_16 (ss, i)
if ( V_113 & ( 1 << V_23 ) )
F_99 ( V_5 -> V_119 ) ;
return V_114 ;
}
static int F_100 ( struct V_127 * V_128 , struct V_17 * V_17 )
{
struct V_51 * V_50 = V_17 -> V_129 -> V_130 ;
struct V_4 * V_5 ;
F_13 ( & V_115 ) ;
F_101 (root, ss)
F_102 ( V_128 , L_2 , V_5 -> V_84 ) ;
if ( V_50 -> V_11 & V_131 )
F_103 ( V_128 , L_3 ) ;
if ( V_50 -> V_11 & V_132 )
F_103 ( V_128 , L_4 ) ;
if ( V_50 -> V_11 & V_133 )
F_103 ( V_128 , L_5 ) ;
if ( strlen ( V_50 -> V_134 ) )
F_102 ( V_128 , L_6 , V_50 -> V_134 ) ;
if ( F_5 ( V_135 , & V_50 -> V_67 . V_11 ) )
F_103 ( V_128 , L_7 ) ;
if ( strlen ( V_50 -> V_84 ) )
F_102 ( V_128 , L_8 , V_50 -> V_84 ) ;
F_14 ( & V_115 ) ;
return 0 ;
}
static int F_104 ( char * V_136 , struct V_137 * V_138 )
{
char * V_139 , * V_140 = V_136 ;
bool V_141 = false , V_142 = false ;
unsigned long V_143 = ( unsigned long ) - 1 ;
struct V_4 * V_5 ;
int V_23 ;
F_35 ( ! F_57 ( & V_8 ) ) ;
#ifdef F_105
V_143 = ~ ( 1UL << V_144 ) ;
#endif
memset ( V_138 , 0 , sizeof( * V_138 ) ) ;
while ( ( V_139 = F_106 ( & V_140 , L_9 ) ) != NULL ) {
if ( ! * V_139 )
return - V_145 ;
if ( ! strcmp ( V_139 , L_10 ) ) {
V_138 -> V_146 = true ;
continue;
}
if ( ! strcmp ( V_139 , L_11 ) ) {
if ( V_142 )
return - V_145 ;
V_141 = true ;
continue;
}
if ( ! strcmp ( V_139 , L_12 ) ) {
V_138 -> V_11 |= V_131 ;
continue;
}
if ( ! strcmp ( V_139 , L_13 ) ) {
V_138 -> V_11 |= V_132 ;
continue;
}
if ( ! strcmp ( V_139 , L_14 ) ) {
V_138 -> V_147 = true ;
continue;
}
if ( ! strcmp ( V_139 , L_15 ) ) {
V_138 -> V_11 |= V_133 ;
continue;
}
if ( ! strncmp ( V_139 , L_16 , 14 ) ) {
if ( V_138 -> V_148 )
return - V_145 ;
V_138 -> V_148 =
F_107 ( V_139 + 14 , V_149 - 1 , V_56 ) ;
if ( ! V_138 -> V_148 )
return - V_57 ;
continue;
}
if ( ! strncmp ( V_139 , L_17 , 5 ) ) {
const char * V_84 = V_139 + 5 ;
if ( ! strlen ( V_84 ) )
return - V_145 ;
for ( V_23 = 0 ; V_23 < strlen ( V_84 ) ; V_23 ++ ) {
char V_61 = V_84 [ V_23 ] ;
if ( isalnum ( V_61 ) )
continue;
if ( ( V_61 == '.' ) || ( V_61 == '-' ) || ( V_61 == '_' ) )
continue;
return - V_145 ;
}
if ( V_138 -> V_84 )
return - V_145 ;
V_138 -> V_84 = F_107 ( V_84 ,
V_150 - 1 ,
V_56 ) ;
if ( ! V_138 -> V_84 )
return - V_57 ;
continue;
}
F_16 (ss, i) {
if ( strcmp ( V_139 , V_5 -> V_84 ) )
continue;
if ( V_5 -> V_151 )
continue;
if ( V_141 )
return - V_145 ;
F_26 ( V_23 , & V_138 -> V_52 ) ;
V_142 = true ;
break;
}
if ( V_23 == V_58 )
return - V_120 ;
}
if ( V_141 || ( ! V_142 && ! V_138 -> V_146 && ! V_138 -> V_84 ) )
F_16 (ss, i)
if ( ! V_5 -> V_151 )
F_26 ( V_23 , & V_138 -> V_52 ) ;
if ( V_138 -> V_11 & V_131 ) {
F_108 ( L_18 ) ;
if ( V_138 -> V_11 & V_132 ) {
F_109 ( L_19 ) ;
return - V_145 ;
}
if ( V_138 -> V_147 ) {
F_109 ( L_20 ) ;
return - V_145 ;
}
}
if ( ( V_138 -> V_11 & V_132 ) && ( V_138 -> V_52 & V_143 ) )
return - V_145 ;
if ( V_138 -> V_52 && V_138 -> V_146 )
return - V_145 ;
if ( ! V_138 -> V_52 && ! V_138 -> V_84 )
return - V_145 ;
return 0 ;
}
static int F_110 ( struct V_70 * V_71 , int * V_11 , char * V_136 )
{
int V_114 = 0 ;
struct V_51 * V_50 = V_71 -> V_130 ;
struct V_2 * V_3 = & V_50 -> V_67 ;
struct V_137 V_138 ;
unsigned long V_111 , V_112 ;
if ( V_50 -> V_11 & V_131 ) {
F_109 ( L_21 ) ;
return - V_145 ;
}
F_13 ( & V_3 -> V_17 -> V_101 -> V_103 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_115 ) ;
V_114 = F_104 ( V_136 , & V_138 ) ;
if ( V_114 )
goto V_152;
if ( V_138 . V_52 != V_50 -> V_52 || V_138 . V_148 )
F_108 ( L_22 ,
F_111 ( V_153 ) , V_153 -> V_154 ) ;
V_111 = V_138 . V_52 & ~ V_50 -> V_52 ;
V_112 = V_50 -> V_52 & ~ V_138 . V_52 ;
if ( ( ( V_138 . V_11 ^ V_50 -> V_11 ) & V_155 ) ||
( V_138 . V_84 && strcmp ( V_138 . V_84 , V_50 -> V_84 ) ) ) {
F_109 ( L_23 ,
V_138 . V_11 & V_155 , V_138 . V_84 ? : L_24 ,
V_50 -> V_11 & V_155 , V_50 -> V_84 ) ;
V_114 = - V_145 ;
goto V_152;
}
if ( V_50 -> V_90 > 1 ) {
V_114 = - V_117 ;
goto V_152;
}
V_114 = F_94 ( V_50 , V_111 , V_112 ) ;
if ( V_114 )
goto V_152;
if ( V_138 . V_148 )
strcpy ( V_50 -> V_134 , V_138 . V_148 ) ;
V_152:
F_28 ( V_138 . V_148 ) ;
F_28 ( V_138 . V_84 ) ;
F_14 ( & V_115 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_3 -> V_17 -> V_101 -> V_103 ) ;
return V_114 ;
}
static void F_112 ( struct V_2 * V_3 )
{
F_41 ( & V_3 -> V_123 ) ;
F_41 ( & V_3 -> V_156 ) ;
F_41 ( & V_3 -> V_157 ) ;
F_41 ( & V_3 -> V_36 ) ;
F_41 ( & V_3 -> V_158 ) ;
F_41 ( & V_3 -> V_91 ) ;
F_113 ( & V_3 -> V_159 ) ;
V_3 -> V_9 . V_2 = V_3 ;
F_41 ( & V_3 -> V_160 ) ;
F_114 ( & V_3 -> V_161 ) ;
F_115 ( & V_3 -> V_92 ) ;
}
static void F_116 ( struct V_51 * V_50 )
{
struct V_2 * V_3 = & V_50 -> V_67 ;
F_41 ( & V_50 -> V_124 ) ;
F_41 ( & V_50 -> V_162 ) ;
V_50 -> V_90 = 1 ;
V_3 -> V_50 = V_50 ;
F_98 ( V_3 -> V_84 , & V_163 ) ;
F_112 ( V_3 ) ;
F_117 ( & V_50 -> V_95 ) ;
}
static int F_118 ( struct V_51 * V_50 , int V_164 , int V_165 )
{
int V_96 ;
F_49 ( & V_8 ) ;
F_49 ( & V_115 ) ;
V_96 = F_119 ( & V_166 , V_50 , V_164 , V_165 ,
V_56 ) ;
if ( V_96 < 0 )
return V_96 ;
V_50 -> V_167 = V_96 ;
return 0 ;
}
static void F_120 ( struct V_51 * V_50 )
{
F_49 ( & V_8 ) ;
F_49 ( & V_115 ) ;
if ( V_50 -> V_167 ) {
F_77 ( & V_166 , V_50 -> V_167 ) ;
V_50 -> V_167 = 0 ;
}
}
static int F_121 ( struct V_70 * V_71 , void * V_136 )
{
struct V_137 * V_138 = V_136 ;
struct V_51 * V_50 = V_71 -> V_130 ;
if ( V_138 -> V_84 && strcmp ( V_138 -> V_84 , V_50 -> V_84 ) )
return 0 ;
if ( ( V_138 -> V_52 || V_138 -> V_146 )
&& ( V_138 -> V_52 != V_50 -> V_52 ) )
return 0 ;
return 1 ;
}
static struct V_51 * F_122 ( struct V_137 * V_138 )
{
struct V_51 * V_50 ;
if ( ! V_138 -> V_52 && ! V_138 -> V_146 )
return NULL ;
V_50 = F_42 ( sizeof( * V_50 ) , V_56 ) ;
if ( ! V_50 )
return F_123 ( - V_57 ) ;
F_116 ( V_50 ) ;
V_50 -> V_52 = V_138 -> V_52 ;
V_50 -> V_11 = V_138 -> V_11 ;
if ( V_138 -> V_148 )
strcpy ( V_50 -> V_134 , V_138 -> V_148 ) ;
if ( V_138 -> V_84 )
strcpy ( V_50 -> V_84 , V_138 -> V_84 ) ;
if ( V_138 -> V_147 )
F_26 ( V_135 , & V_50 -> V_67 . V_11 ) ;
return V_50 ;
}
static void F_124 ( struct V_51 * V_50 )
{
if ( V_50 ) {
F_125 ( V_50 -> V_167 ) ;
F_126 ( & V_50 -> V_95 ) ;
F_28 ( V_50 ) ;
}
}
static int F_127 ( struct V_70 * V_71 , void * V_136 )
{
int V_114 ;
struct V_137 * V_138 = V_136 ;
if ( ! V_138 -> V_168 )
return - V_145 ;
F_35 ( ! V_138 -> V_52 && ! V_138 -> V_146 ) ;
V_114 = F_128 ( V_71 , NULL ) ;
if ( V_114 )
return V_114 ;
V_71 -> V_130 = V_138 -> V_168 ;
V_138 -> V_168 -> V_71 = V_71 ;
V_71 -> V_169 = V_170 ;
V_71 -> V_171 = V_172 ;
V_71 -> V_173 = V_174 ;
V_71 -> V_175 = & V_176 ;
return 0 ;
}
static int F_129 ( struct V_70 * V_71 )
{
static const struct V_177 V_178 = {
. V_179 = F_75 ,
. F_83 = V_180 ,
} ;
struct V_68 * V_68 =
F_59 ( V_181 | V_182 | V_183 | V_184 , V_71 ) ;
if ( ! V_68 )
return - V_57 ;
V_68 -> V_185 = & V_186 ;
V_68 -> V_187 = & V_188 ;
F_130 ( V_68 ) ;
V_71 -> V_189 = F_131 ( V_68 ) ;
if ( ! V_71 -> V_189 )
return - V_57 ;
V_71 -> V_190 = & V_178 ;
return 0 ;
}
static struct V_17 * F_132 ( struct V_191 * V_192 ,
int V_11 , const char * V_193 ,
void * V_136 )
{
struct V_137 V_138 ;
struct V_51 * V_50 ;
int V_114 = 0 ;
struct V_70 * V_71 ;
struct V_51 * V_168 ;
struct V_41 V_55 ;
struct V_68 * V_68 ;
const struct V_194 * V_194 ;
F_13 ( & V_8 ) ;
V_114 = F_104 ( V_136 , & V_138 ) ;
F_14 ( & V_8 ) ;
if ( V_114 )
goto V_195;
V_168 = F_122 ( & V_138 ) ;
if ( F_133 ( V_168 ) ) {
V_114 = F_134 ( V_168 ) ;
goto V_195;
}
V_138 . V_168 = V_168 ;
V_71 = F_135 ( V_192 , F_121 , F_127 , 0 , & V_138 ) ;
if ( F_133 ( V_71 ) ) {
V_114 = F_134 ( V_71 ) ;
F_124 ( V_138 . V_168 ) ;
goto V_195;
}
V_50 = V_71 -> V_130 ;
F_35 ( ! V_50 ) ;
if ( V_50 == V_138 . V_168 ) {
struct V_2 * V_196 = & V_50 -> V_67 ;
struct V_51 * V_197 ;
int V_23 ;
struct V_24 * V_25 ;
F_35 ( V_71 -> V_189 != NULL ) ;
V_114 = F_129 ( V_71 ) ;
if ( V_114 )
goto V_198;
V_68 = V_71 -> V_189 -> V_101 ;
F_13 ( & V_68 -> V_103 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_115 ) ;
V_196 -> V_96 = F_136 ( & V_50 -> V_95 , V_196 ,
0 , 1 , V_56 ) ;
if ( V_196 -> V_96 < 0 )
goto V_199;
V_114 = - V_117 ;
if ( strlen ( V_50 -> V_84 ) )
F_137 (existing_root)
if ( ! strcmp ( V_197 -> V_84 , V_50 -> V_84 ) )
goto V_199;
V_114 = F_40 ( V_33 , & V_55 ) ;
if ( V_114 )
goto V_199;
V_114 = F_118 ( V_50 , 2 , 0 ) ;
if ( V_114 )
goto V_199;
V_71 -> V_189 -> V_18 = V_196 ;
V_196 -> V_17 = V_71 -> V_189 ;
V_194 = F_138 ( & V_200 ) ;
V_114 = F_89 ( V_196 , V_201 , true ) ;
if ( V_114 )
goto V_202;
V_114 = F_94 ( V_50 , V_50 -> V_52 , 0 ) ;
if ( V_114 )
goto V_202;
F_139 ( V_194 ) ;
F_43 ( & V_50 -> V_162 , & V_203 ) ;
V_59 ++ ;
F_19 ( & V_31 ) ;
F_140 (css_set_table, i, cset, hlist)
F_44 ( & V_55 , V_25 , V_196 ) ;
F_21 ( & V_31 ) ;
F_39 ( & V_55 ) ;
F_35 ( ! F_25 ( & V_196 -> V_156 ) ) ;
F_35 ( V_50 -> V_90 != 1 ) ;
F_14 ( & V_115 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_68 -> V_103 ) ;
} else {
F_124 ( V_138 . V_168 ) ;
if ( ( V_50 -> V_11 ^ V_138 . V_11 ) & V_155 ) {
if ( ( V_50 -> V_11 | V_138 . V_11 ) & V_131 ) {
F_109 ( L_25 ) ;
V_114 = - V_145 ;
goto V_198;
} else {
F_108 ( L_26 ) ;
}
}
}
F_28 ( V_138 . V_148 ) ;
F_28 ( V_138 . V_84 ) ;
return F_82 ( V_71 -> V_189 ) ;
V_202:
F_39 ( & V_55 ) ;
F_89 ( & V_50 -> V_67 , V_201 , false ) ;
F_139 ( V_194 ) ;
V_199:
F_120 ( V_50 ) ;
F_14 ( & V_115 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_68 -> V_103 ) ;
V_198:
F_141 ( V_71 ) ;
V_195:
F_28 ( V_138 . V_148 ) ;
F_28 ( V_138 . V_84 ) ;
return F_123 ( V_114 ) ;
}
static void F_142 ( struct V_70 * V_71 ) {
struct V_51 * V_50 = V_71 -> V_130 ;
struct V_2 * V_3 = & V_50 -> V_67 ;
struct V_27 * V_28 , * V_29 ;
int V_114 ;
F_35 ( ! V_50 ) ;
F_35 ( V_50 -> V_90 != 1 ) ;
F_35 ( ! F_25 ( & V_3 -> V_156 ) ) ;
F_13 ( & V_3 -> V_17 -> V_101 -> V_103 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_115 ) ;
if ( V_50 -> V_11 & V_126 ) {
V_114 = F_94 ( V_50 , 0 , V_50 -> V_52 ) ;
F_35 ( V_114 ) ;
}
F_19 ( & V_31 ) ;
F_23 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_24 ( & V_28 -> V_34 ) ;
F_24 ( & V_28 -> V_35 ) ;
F_28 ( V_28 ) ;
}
F_21 ( & V_31 ) ;
if ( ! F_25 ( & V_50 -> V_162 ) ) {
F_24 ( & V_50 -> V_162 ) ;
V_59 -- ;
}
F_120 ( V_50 ) ;
F_14 ( & V_115 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_3 -> V_17 -> V_101 -> V_103 ) ;
F_70 ( & V_3 -> V_92 ) ;
F_143 ( V_71 ) ;
F_124 ( V_50 ) ;
}
int F_144 ( const struct V_2 * V_3 , char * V_204 , int V_205 )
{
int V_114 = - V_206 ;
char * V_164 ;
if ( ! V_3 -> V_13 ) {
if ( F_145 ( V_204 , L_27 , V_205 ) >= V_205 )
return - V_206 ;
return 0 ;
}
V_164 = V_204 + V_205 - 1 ;
* V_164 = '\0' ;
F_146 () ;
do {
const char * V_84 = V_83 ( V_3 ) ;
int V_86 ;
V_86 = strlen ( V_84 ) ;
if ( ( V_164 -= V_86 ) < V_204 )
goto V_207;
memcpy ( V_164 , V_84 , V_86 ) ;
if ( -- V_164 < V_204 )
goto V_207;
* V_164 = '/' ;
V_3 = V_3 -> V_13 ;
} while ( V_3 -> V_13 );
V_114 = 0 ;
memmove ( V_204 , V_164 , V_204 + V_205 - V_164 ) ;
V_207:
F_147 () ;
return V_114 ;
}
int F_148 ( struct V_63 * V_64 , char * V_204 , T_2 V_205 )
{
struct V_51 * V_50 ;
struct V_2 * V_3 ;
int V_167 = 1 , V_114 = 0 ;
if ( V_205 < 2 )
return - V_206 ;
F_13 ( & V_8 ) ;
V_50 = F_149 ( & V_166 , & V_167 ) ;
if ( V_50 ) {
V_3 = F_56 ( V_64 , V_50 ) ;
V_114 = F_144 ( V_3 , V_204 , V_205 ) ;
} else {
memcpy ( V_204 , L_27 , 2 ) ;
}
F_14 ( & V_8 ) ;
return V_114 ;
}
struct V_63 * F_150 ( struct V_208 * V_209 )
{
if ( V_209 -> V_210 ) {
V_209 -> V_211 = 0 ;
return F_151 ( V_209 ) ;
} else {
V_209 -> V_212 = V_209 -> V_213 . V_3 ;
return V_209 -> V_213 . V_64 ;
}
}
struct V_63 * F_151 ( struct V_208 * V_209 )
{
struct V_214 * V_215 ;
if ( ! V_209 -> V_210 || V_209 -> V_211 >= V_209 -> V_216 )
return NULL ;
V_215 = F_152 ( V_209 -> V_210 , V_209 -> V_211 ++ ) ;
V_209 -> V_212 = V_215 -> V_3 ;
return V_215 -> V_64 ;
}
struct V_1 * F_153 ( struct V_208 * V_209 ,
int V_7 )
{
return F_1 ( V_209 -> V_212 , V_4 [ V_7 ] ) ;
}
int F_154 ( struct V_208 * V_209 )
{
return V_209 -> V_210 ? V_209 -> V_216 : 1 ;
}
static void F_155 ( struct V_2 * V_217 ,
struct V_63 * V_218 ,
struct V_24 * V_219 )
{
struct V_24 * V_38 ;
F_125 ( V_218 -> V_11 & V_220 ) ;
V_38 = F_58 ( V_218 ) ;
F_156 ( V_218 ) ;
F_97 ( V_218 -> V_221 , V_219 ) ;
F_157 ( V_218 ) ;
F_19 ( & V_31 ) ;
if ( ! F_25 ( & V_218 -> V_222 ) )
F_46 ( & V_218 -> V_222 , & V_219 -> V_60 ) ;
F_21 ( & V_31 ) ;
F_26 ( V_15 , & V_217 -> V_11 ) ;
F_32 ( V_38 ) ;
}
static int F_158 ( struct V_2 * V_3 , struct V_63 * V_218 ,
bool V_223 )
{
int V_224 , V_23 , V_225 ;
struct V_4 * V_5 , * V_226 = NULL ;
struct V_51 * V_50 = V_3 -> V_50 ;
struct V_63 * V_227 = V_218 ;
struct V_214 * V_215 ;
struct V_228 * V_229 ;
struct V_208 V_209 = { } ;
if ( V_223 )
V_225 = F_159 ( V_218 ) ;
else
V_225 = 1 ;
V_229 = F_160 ( sizeof( * V_215 ) , V_225 , V_56 ) ;
if ( ! V_229 )
return - V_57 ;
V_224 = F_161 ( V_229 , 0 , V_225 , V_56 ) ;
if ( V_224 )
goto V_230;
V_23 = 0 ;
F_146 () ;
do {
struct V_214 V_231 ;
if ( V_218 -> V_11 & V_220 )
goto V_49;
F_35 ( V_23 >= V_225 ) ;
V_231 . V_64 = V_218 ;
V_231 . V_3 = F_56 ( V_218 , V_50 ) ;
if ( V_231 . V_3 == V_3 )
goto V_49;
V_224 = F_162 ( V_229 , V_23 , & V_231 , V_232 ) ;
F_35 ( V_224 != 0 ) ;
V_23 ++ ;
V_49:
if ( ! V_223 )
break;
} while_each_thread(leader, tsk) ;
int F_163 ( struct V_2 * V_3 , T_3 V_233 , bool V_223 )
{
struct V_63 * V_218 ;
const struct V_194 * V_194 = F_164 () , * V_234 ;
int V_114 ;
if ( ! F_12 ( V_3 ) )
return - V_235 ;
V_236:
F_146 () ;
if ( V_233 ) {
V_218 = F_165 ( V_233 ) ;
if ( ! V_218 ) {
F_147 () ;
V_114 = - V_237 ;
goto V_238;
}
V_234 = F_166 ( V_218 ) ;
if ( ! F_167 ( V_194 -> V_239 , V_240 ) &&
! F_167 ( V_194 -> V_239 , V_234 -> V_241 ) &&
! F_167 ( V_194 -> V_239 , V_234 -> V_242 ) ) {
F_147 () ;
V_114 = - V_243 ;
goto V_238;
}
} else
V_218 = V_153 ;
if ( V_223 )
V_218 = V_218 -> V_244 ;
if ( V_218 == V_245 || ( V_218 -> V_11 & V_246 ) ) {
V_114 = - V_145 ;
F_147 () ;
goto V_238;
}
F_168 ( V_218 ) ;
F_147 () ;
F_169 ( V_218 ) ;
if ( V_223 ) {
if ( ! F_170 ( V_218 ) ) {
F_171 ( V_218 ) ;
F_172 ( V_218 ) ;
goto V_236;
}
}
V_114 = F_158 ( V_3 , V_218 , V_223 ) ;
F_171 ( V_218 ) ;
F_172 ( V_218 ) ;
V_238:
F_14 ( & V_8 ) ;
return V_114 ;
}
int F_173 ( struct V_63 * V_247 , struct V_63 * V_218 )
{
struct V_51 * V_50 ;
int V_224 = 0 ;
F_13 ( & V_8 ) ;
F_137 (root) {
struct V_2 * V_248 = F_56 ( V_247 , V_50 ) ;
V_224 = F_158 ( V_248 , V_218 , false ) ;
if ( V_224 )
break;
}
F_14 ( & V_8 ) ;
return V_224 ;
}
static int F_174 ( struct V_1 * V_21 ,
struct V_20 * V_102 , T_3 V_233 )
{
return F_163 ( V_21 -> V_2 , V_233 , false ) ;
}
static int F_175 ( struct V_1 * V_21 ,
struct V_20 * V_102 , T_3 V_249 )
{
return F_163 ( V_21 -> V_2 , V_249 , true ) ;
}
static int F_176 ( struct V_1 * V_21 ,
struct V_20 * V_102 , const char * V_250 )
{
F_177 ( sizeof( V_21 -> V_2 -> V_50 -> V_134 ) < V_149 ) ;
if ( strlen ( V_250 ) >= V_149 )
return - V_145 ;
if ( ! F_12 ( V_21 -> V_2 ) )
return - V_235 ;
F_13 ( & V_115 ) ;
strcpy ( V_21 -> V_2 -> V_50 -> V_134 , V_250 ) ;
F_14 ( & V_115 ) ;
F_14 ( & V_8 ) ;
return 0 ;
}
static int F_178 ( struct V_1 * V_21 ,
struct V_20 * V_102 , struct V_127 * V_128 )
{
struct V_2 * V_3 = V_21 -> V_2 ;
if ( ! F_12 ( V_3 ) )
return - V_235 ;
F_103 ( V_128 , V_3 -> V_50 -> V_134 ) ;
F_179 ( V_128 , '\n' ) ;
F_14 ( & V_8 ) ;
return 0 ;
}
static int F_180 ( struct V_1 * V_21 ,
struct V_20 * V_102 , struct V_127 * V_128 )
{
F_102 ( V_128 , L_28 , F_181 ( V_21 -> V_2 ) ) ;
return 0 ;
}
static T_4 F_182 ( struct V_1 * V_21 ,
struct V_20 * V_102 , struct V_251 * V_251 ,
const char T_5 * V_252 , T_2 V_253 ,
T_6 * V_254 )
{
char V_250 [ V_255 ] ;
int V_224 = 0 ;
char * V_165 ;
if ( ! V_253 )
return - V_145 ;
if ( V_253 >= sizeof( V_250 ) )
return - V_256 ;
if ( F_183 ( V_250 , V_252 , V_253 ) )
return - V_257 ;
V_250 [ V_253 ] = 0 ;
if ( V_102 -> V_258 ) {
T_3 V_259 = F_184 ( F_185 ( V_250 ) , & V_165 , 0 ) ;
if ( * V_165 )
return - V_145 ;
V_224 = V_102 -> V_258 ( V_21 , V_102 , V_259 ) ;
} else {
T_7 V_259 = F_186 ( F_185 ( V_250 ) , & V_165 , 0 ) ;
if ( * V_165 )
return - V_145 ;
V_224 = V_102 -> V_260 ( V_21 , V_102 , V_259 ) ;
}
if ( ! V_224 )
V_224 = V_253 ;
return V_224 ;
}
static T_4 F_187 ( struct V_1 * V_21 ,
struct V_20 * V_102 , struct V_251 * V_251 ,
const char T_5 * V_252 , T_2 V_253 ,
T_6 * V_254 )
{
char V_261 [ V_255 ] ;
int V_224 = 0 ;
T_2 V_262 = V_102 -> V_263 ;
char * V_250 = V_261 ;
if ( ! V_262 )
V_262 = sizeof( V_261 ) - 1 ;
if ( V_253 >= V_262 )
return - V_256 ;
if ( V_253 >= sizeof( V_261 ) ) {
V_250 = F_65 ( V_253 + 1 , V_56 ) ;
if ( V_250 == NULL )
return - V_57 ;
}
if ( V_253 && F_183 ( V_250 , V_252 , V_253 ) ) {
V_224 = - V_257 ;
goto V_207;
}
V_250 [ V_253 ] = 0 ;
V_224 = V_102 -> V_264 ( V_21 , V_102 , F_185 ( V_250 ) ) ;
if ( ! V_224 )
V_224 = V_253 ;
V_207:
if ( V_250 != V_261 )
F_28 ( V_250 ) ;
return V_224 ;
}
static T_4 F_188 ( struct V_251 * V_251 , const char T_5 * V_204 ,
T_2 V_253 , T_6 * V_265 )
{
struct V_19 * V_97 = F_10 ( V_251 -> V_266 ) ;
struct V_20 * V_102 = F_11 ( V_251 -> V_266 ) ;
struct V_1 * V_21 = V_97 -> V_21 ;
if ( V_102 -> V_267 )
return V_102 -> V_267 ( V_21 , V_102 , V_251 , V_204 , V_253 , V_265 ) ;
if ( V_102 -> V_258 || V_102 -> V_260 )
return F_182 ( V_21 , V_102 , V_251 , V_204 , V_253 , V_265 ) ;
if ( V_102 -> V_264 )
return F_187 ( V_21 , V_102 , V_251 , V_204 , V_253 , V_265 ) ;
if ( V_102 -> V_268 ) {
int V_114 = V_102 -> V_268 ( V_21 , ( unsigned int ) V_102 -> V_269 ) ;
return V_114 ? V_114 : V_253 ;
}
return - V_145 ;
}
static T_4 F_189 ( struct V_1 * V_21 ,
struct V_20 * V_102 , struct V_251 * V_251 ,
char T_5 * V_204 , T_2 V_253 , T_6 * V_265 )
{
char V_270 [ V_255 ] ;
T_3 V_259 = V_102 -> V_271 ( V_21 , V_102 ) ;
int V_86 = sprintf ( V_270 , L_29 , ( unsigned long long ) V_259 ) ;
return F_190 ( V_204 , V_253 , V_265 , V_270 , V_86 ) ;
}
static T_4 F_191 ( struct V_1 * V_21 ,
struct V_20 * V_102 , struct V_251 * V_251 ,
char T_5 * V_204 , T_2 V_253 , T_6 * V_265 )
{
char V_270 [ V_255 ] ;
T_7 V_259 = V_102 -> V_272 ( V_21 , V_102 ) ;
int V_86 = sprintf ( V_270 , L_30 , ( long long ) V_259 ) ;
return F_190 ( V_204 , V_253 , V_265 , V_270 , V_86 ) ;
}
static T_4 F_192 ( struct V_251 * V_251 , char T_5 * V_204 ,
T_2 V_253 , T_6 * V_265 )
{
struct V_19 * V_97 = F_10 ( V_251 -> V_266 ) ;
struct V_20 * V_102 = F_11 ( V_251 -> V_266 ) ;
struct V_1 * V_21 = V_97 -> V_21 ;
if ( V_102 -> V_273 )
return V_102 -> V_273 ( V_21 , V_102 , V_251 , V_204 , V_253 , V_265 ) ;
if ( V_102 -> V_271 )
return F_189 ( V_21 , V_102 , V_251 , V_204 , V_253 , V_265 ) ;
if ( V_102 -> V_272 )
return F_191 ( V_21 , V_102 , V_251 , V_204 , V_253 , V_265 ) ;
return - V_145 ;
}
static int F_193 ( struct V_274 * V_275 , const char * V_22 , T_3 V_276 )
{
struct V_127 * V_277 = V_275 -> V_278 ;
return F_102 ( V_277 , L_31 , V_22 , ( unsigned long long ) V_276 ) ;
}
static int F_194 ( struct V_127 * V_279 , void * V_280 )
{
struct V_19 * V_97 = V_279 -> V_269 ;
struct V_20 * V_102 = V_97 -> type ;
struct V_1 * V_21 = V_97 -> V_21 ;
if ( V_102 -> V_281 ) {
struct V_274 V_275 = {
. V_282 = F_193 ,
. V_278 = V_279 ,
} ;
return V_102 -> V_281 ( V_21 , V_102 , & V_275 ) ;
}
return V_102 -> V_283 ( V_21 , V_102 , V_279 ) ;
}
static int F_195 ( struct V_68 * V_68 , struct V_251 * V_251 )
{
struct V_19 * V_97 = F_10 ( V_251 -> V_266 ) ;
struct V_20 * V_102 = F_11 ( V_251 -> V_266 ) ;
struct V_2 * V_3 = F_9 ( V_97 -> V_17 -> V_98 ) ;
struct V_1 * V_21 ;
int V_284 ;
V_284 = F_196 ( V_68 , V_251 ) ;
if ( V_284 )
return V_284 ;
F_146 () ;
V_21 = F_1 ( V_3 , V_102 -> V_5 ) ;
if ( V_102 -> V_5 && ! F_197 ( V_21 ) )
V_21 = NULL ;
F_147 () ;
if ( ! V_21 )
return - V_235 ;
F_125 ( V_97 -> V_21 && V_97 -> V_21 != V_21 ) ;
V_97 -> V_21 = V_21 ;
if ( V_102 -> V_281 || V_102 -> V_283 ) {
V_251 -> V_285 = & V_286 ;
V_284 = F_198 ( V_251 , F_194 , V_97 ) ;
} else if ( V_102 -> V_287 ) {
V_284 = V_102 -> V_287 ( V_68 , V_251 ) ;
}
if ( V_21 -> V_5 && V_284 )
F_199 ( V_21 ) ;
return V_284 ;
}
static int F_200 ( struct V_68 * V_68 , struct V_251 * V_251 )
{
struct V_19 * V_97 = F_10 ( V_251 -> V_266 ) ;
struct V_20 * V_102 = F_11 ( V_251 -> V_266 ) ;
struct V_1 * V_21 = V_97 -> V_21 ;
int V_114 = 0 ;
if ( V_102 -> V_288 )
V_114 = V_102 -> V_288 ( V_68 , V_251 ) ;
if ( V_21 -> V_5 )
F_199 ( V_21 ) ;
if ( V_251 -> V_285 == & V_286 )
F_201 ( V_68 , V_251 ) ;
return V_114 ;
}
static int F_202 ( struct V_68 * V_289 , struct V_17 * V_290 ,
struct V_68 * V_291 , struct V_17 * V_292 )
{
int V_114 ;
struct V_83 * V_84 , * V_293 ;
struct V_2 * V_3 ;
F_49 ( & V_289 -> V_103 ) ;
if ( ! F_76 ( V_290 -> V_101 -> V_73 ) )
return - V_294 ;
if ( V_292 -> V_101 )
return - V_295 ;
if ( V_289 != V_291 )
return - V_296 ;
V_3 = F_9 ( V_290 ) ;
if ( F_181 ( V_3 ) )
return - V_297 ;
V_84 = F_64 ( V_292 ) ;
if ( ! V_84 )
return - V_57 ;
V_114 = F_203 ( V_289 , V_290 , V_291 , V_292 ) ;
if ( V_114 ) {
F_28 ( V_84 ) ;
return V_114 ;
}
V_293 = F_204 ( V_3 -> V_84 , true ) ;
F_97 ( V_3 -> V_84 , V_84 ) ;
F_29 ( V_293 , V_37 ) ;
return 0 ;
}
static struct V_298 * F_205 ( struct V_17 * V_17 )
{
if ( F_76 ( V_17 -> V_101 -> V_73 ) )
return & F_9 ( V_17 ) -> V_92 ;
else
return & F_10 ( V_17 ) -> V_92 ;
}
static inline int F_206 ( struct V_17 * V_17 )
{
struct V_51 * V_50 = V_17 -> V_129 -> V_130 ;
return V_50 -> V_11 & V_133 ;
}
static bool F_207 ( const char * V_84 )
{
if ( ! strncmp ( V_84 , V_299 , V_300 ) ||
! strncmp ( V_84 , V_301 , V_302 ) )
return true ;
return false ;
}
static int F_208 ( struct V_17 * V_17 , const char * V_84 ,
const void * V_259 , T_2 V_303 , int V_11 )
{
if ( ! F_206 ( V_17 ) )
return - V_304 ;
if ( ! F_207 ( V_84 ) )
return - V_145 ;
return F_209 ( F_205 ( V_17 ) , V_84 , V_259 , V_303 , V_11 ) ;
}
static int F_210 ( struct V_17 * V_17 , const char * V_84 )
{
if ( ! F_206 ( V_17 ) )
return - V_304 ;
if ( ! F_207 ( V_84 ) )
return - V_145 ;
return F_211 ( F_205 ( V_17 ) , V_84 ) ;
}
static T_4 F_212 ( struct V_17 * V_17 , const char * V_84 ,
void * V_204 , T_2 V_303 )
{
if ( ! F_206 ( V_17 ) )
return - V_304 ;
if ( ! F_207 ( V_84 ) )
return - V_145 ;
return F_213 ( F_205 ( V_17 ) , V_84 , V_204 , V_303 ) ;
}
static T_4 F_214 ( struct V_17 * V_17 , char * V_204 , T_2 V_303 )
{
if ( ! F_206 ( V_17 ) )
return - V_304 ;
return F_215 ( F_205 ( V_17 ) , V_204 , V_303 ) ;
}
static inline struct V_20 * F_216 ( struct V_251 * V_251 )
{
if ( F_217 ( V_251 ) -> V_185 != & V_305 )
return F_123 ( - V_145 ) ;
return F_11 ( V_251 -> V_266 ) ;
}
static int F_218 ( struct V_17 * V_17 , T_1 V_69 ,
struct V_70 * V_71 )
{
struct V_68 * V_68 ;
if ( ! V_17 )
return - V_120 ;
if ( V_17 -> V_101 )
return - V_295 ;
V_68 = F_59 ( V_69 , V_71 ) ;
if ( ! V_68 )
return - V_57 ;
if ( F_76 ( V_69 ) ) {
V_68 -> V_187 = & V_188 ;
V_68 -> V_185 = & V_186 ;
F_130 ( V_68 ) ;
F_130 ( V_17 -> V_98 -> V_101 ) ;
F_125 ( ! F_219 ( & V_68 -> V_103 ) ) ;
} else if ( F_220 ( V_69 ) ) {
V_68 -> V_306 = 0 ;
V_68 -> V_185 = & V_305 ;
V_68 -> V_187 = & V_307 ;
}
F_221 ( V_17 , V_68 ) ;
F_82 ( V_17 ) ;
return 0 ;
}
static T_1 F_222 ( const struct V_20 * V_102 )
{
T_1 V_69 = 0 ;
if ( V_102 -> V_69 )
return V_102 -> V_69 ;
if ( V_102 -> V_273 || V_102 -> V_271 || V_102 -> V_272 ||
V_102 -> V_281 || V_102 -> V_283 )
V_69 |= V_182 ;
if ( V_102 -> V_267 || V_102 -> V_258 || V_102 -> V_260 ||
V_102 -> V_264 || V_102 -> V_268 )
V_69 |= V_184 ;
return V_69 ;
}
static int F_223 ( struct V_2 * V_3 , struct V_20 * V_102 )
{
struct V_17 * V_308 = V_3 -> V_17 ;
struct V_2 * V_13 = F_9 ( V_308 ) ;
struct V_17 * V_17 ;
struct V_19 * V_97 ;
int error ;
T_1 V_69 ;
char V_84 [ V_309 + V_310 + 2 ] = { 0 } ;
if ( V_102 -> V_5 && ! ( V_102 -> V_11 & V_311 ) &&
! ( V_3 -> V_50 -> V_11 & V_132 ) ) {
strcpy ( V_84 , V_102 -> V_5 -> V_84 ) ;
strcat ( V_84 , L_32 ) ;
}
strcat ( V_84 , V_102 -> V_84 ) ;
F_35 ( ! F_57 ( & V_308 -> V_101 -> V_103 ) ) ;
V_97 = F_42 ( sizeof( * V_97 ) , V_56 ) ;
if ( ! V_97 )
return - V_57 ;
V_17 = F_224 ( V_84 , V_308 , strlen ( V_84 ) ) ;
if ( F_133 ( V_17 ) ) {
error = F_134 ( V_17 ) ;
goto V_207;
}
V_97 -> type = ( void * ) V_102 ;
V_97 -> V_17 = V_17 ;
V_17 -> V_18 = V_97 ;
F_115 ( & V_97 -> V_92 ) ;
V_69 = F_222 ( V_102 ) ;
error = F_218 ( V_17 , V_69 | V_312 , V_3 -> V_50 -> V_71 ) ;
if ( ! error ) {
F_47 ( & V_97 -> V_99 , & V_13 -> V_157 ) ;
V_97 = NULL ;
}
F_68 ( V_17 ) ;
V_207:
F_28 ( V_97 ) ;
return error ;
}
static int F_89 ( struct V_2 * V_3 , struct V_20 V_106 [] ,
bool V_313 )
{
struct V_20 * V_102 ;
int V_114 ;
F_49 ( & V_3 -> V_17 -> V_101 -> V_103 ) ;
F_49 ( & V_8 ) ;
for ( V_102 = V_106 ; V_102 -> V_84 [ 0 ] != '\0' ; V_102 ++ ) {
if ( ( V_102 -> V_11 & V_314 ) && F_181 ( V_3 ) )
continue;
if ( ( V_102 -> V_11 & V_315 ) && ! V_3 -> V_13 )
continue;
if ( ( V_102 -> V_11 & V_316 ) && V_3 -> V_13 )
continue;
if ( V_313 ) {
V_114 = F_223 ( V_3 , V_102 ) ;
if ( V_114 ) {
F_225 ( L_33 ,
V_102 -> V_84 , V_114 ) ;
return V_114 ;
}
} else {
F_85 ( V_3 , V_102 ) ;
}
}
return 0 ;
}
static void F_226 ( void )
__acquires( &cgroup_mutex
static int F_227 ( struct V_20 * V_106 , bool V_313 )
__releases( &cgroup_mutex
int F_228 ( struct V_4 * V_5 , struct V_20 * V_106 )
{
struct V_104 * V_105 ;
struct V_20 * V_102 ;
int V_114 ;
V_105 = F_42 ( sizeof( * V_105 ) , V_56 ) ;
if ( ! V_105 )
return - V_57 ;
for ( V_102 = V_106 ; V_102 -> V_84 [ 0 ] != '\0' ; V_102 ++ )
V_102 -> V_5 = V_5 ;
F_226 () ;
V_105 -> V_106 = V_106 ;
F_47 ( & V_105 -> V_99 , & V_5 -> V_317 ) ;
V_114 = F_227 ( V_106 , true ) ;
if ( V_114 )
F_229 ( V_106 ) ;
return V_114 ;
}
int F_229 ( struct V_20 * V_106 )
{
struct V_104 * V_105 ;
if ( ! V_106 || ! V_106 [ 0 ] . V_5 )
return - V_120 ;
F_226 () ;
F_54 (set, &cfts[0].ss->cftsets, node) {
if ( V_105 -> V_106 == V_106 ) {
F_24 ( & V_105 -> V_99 ) ;
F_28 ( V_105 ) ;
F_227 ( V_106 , false ) ;
return 0 ;
}
}
F_227 ( NULL , false ) ;
return - V_120 ;
}
int F_230 ( const struct V_2 * V_3 )
{
int V_54 = 0 ;
struct V_27 * V_28 ;
F_50 ( & V_31 ) ;
F_54 (link, &cgrp->cset_links, cset_link)
V_54 += F_231 ( & V_28 -> V_25 -> V_30 ) ;
F_51 ( & V_31 ) ;
return V_54 ;
}
static void F_232 ( void )
{
struct V_63 * V_318 , * V_319 ;
F_19 ( & V_31 ) ;
V_320 = 1 ;
F_50 ( & V_321 ) ;
F_233 (g, p) {
F_156 ( V_318 ) ;
if ( ! ( V_318 -> V_11 & V_220 ) && F_25 ( & V_318 -> V_222 ) )
F_43 ( & V_318 -> V_222 , & F_58 ( V_318 ) -> V_60 ) ;
F_157 ( V_318 ) ;
} F_234 ( V_319 , V_318 ) ;
F_51 ( & V_321 ) ;
F_21 ( & V_31 ) ;
}
struct V_1 *
F_235 ( struct V_1 * V_322 ,
struct V_1 * V_323 )
{
struct V_2 * V_324 = V_322 ? V_322 -> V_2 : NULL ;
struct V_2 * V_3 = V_323 -> V_2 ;
struct V_2 * V_49 ;
F_125 ( ! F_236 () ) ;
if ( ! V_324 ) {
V_49 = F_237 ( V_3 -> V_156 . V_49 , struct V_2 , V_123 ) ;
} else if ( F_238 ( ! F_4 ( V_324 ) ) ) {
V_49 = F_237 ( V_324 -> V_123 . V_49 , struct V_2 , V_123 ) ;
} else {
F_239 (next, &cgrp->children, sibling)
if ( V_49 -> V_325 > V_324 -> V_325 )
break;
}
if ( & V_49 -> V_123 == & V_3 -> V_156 )
return NULL ;
return F_1 ( V_49 , V_323 -> V_5 ) ;
}
struct V_1 *
F_240 ( struct V_1 * V_324 ,
struct V_1 * V_50 )
{
struct V_1 * V_49 ;
F_125 ( ! F_236 () ) ;
if ( ! V_324 )
return V_50 ;
V_49 = F_235 ( NULL , V_324 ) ;
if ( V_49 )
return V_49 ;
while ( V_324 != V_50 ) {
V_49 = F_235 ( V_324 , F_241 ( V_324 ) ) ;
if ( V_49 )
return V_49 ;
V_324 = F_241 ( V_324 ) ;
}
return NULL ;
}
struct V_1 *
F_242 ( struct V_1 * V_324 )
{
struct V_1 * V_326 , * V_270 ;
F_125 ( ! F_236 () ) ;
do {
V_326 = V_324 ;
V_324 = NULL ;
F_243 (tmp, last)
V_324 = V_270 ;
} while ( V_324 );
return V_326 ;
}
static struct V_1 *
F_244 ( struct V_1 * V_324 )
{
struct V_1 * V_326 ;
do {
V_326 = V_324 ;
V_324 = F_235 ( NULL , V_324 ) ;
} while ( V_324 );
return V_326 ;
}
struct V_1 *
F_245 ( struct V_1 * V_324 ,
struct V_1 * V_50 )
{
struct V_1 * V_49 ;
F_125 ( ! F_236 () ) ;
if ( ! V_324 )
return F_244 ( V_50 ) ;
if ( V_324 == V_50 )
return NULL ;
V_49 = F_235 ( V_324 , F_241 ( V_324 ) ) ;
if ( V_49 )
return F_244 ( V_49 ) ;
return F_241 ( V_324 ) ;
}
static void F_246 ( struct V_327 * V_328 )
{
struct V_41 * V_329 = V_328 -> V_34 ;
struct V_27 * V_28 ;
struct V_24 * V_25 ;
do {
V_329 = V_329 -> V_49 ;
if ( V_329 == & V_328 -> V_330 -> V_2 -> V_36 ) {
V_328 -> V_34 = NULL ;
return;
}
V_28 = F_36 ( V_329 , struct V_27 , V_34 ) ;
V_25 = V_28 -> V_25 ;
} while ( F_25 ( & V_25 -> V_60 ) );
V_328 -> V_34 = V_329 ;
V_328 -> V_64 = V_25 -> V_60 . V_49 ;
}
void F_247 ( struct V_1 * V_21 ,
struct V_327 * V_328 )
__acquires( V_31 )
{
if ( ! V_320 )
F_232 () ;
F_50 ( & V_31 ) ;
V_328 -> V_330 = V_21 ;
V_328 -> V_34 = & V_21 -> V_2 -> V_36 ;
F_246 ( V_328 ) ;
}
struct V_63 * F_248 ( struct V_327 * V_328 )
{
struct V_63 * V_65 ;
struct V_41 * V_329 = V_328 -> V_64 ;
struct V_27 * V_28 ;
if ( ! V_328 -> V_34 )
return NULL ;
V_65 = F_36 ( V_329 , struct V_63 , V_222 ) ;
V_329 = V_329 -> V_49 ;
V_28 = F_36 ( V_328 -> V_34 , struct V_27 , V_34 ) ;
if ( V_329 == & V_28 -> V_25 -> V_60 ) {
F_246 ( V_328 ) ;
} else {
V_328 -> V_64 = V_329 ;
}
return V_65 ;
}
void F_249 ( struct V_327 * V_328 )
__releases( V_31 )
{
F_51 ( & V_31 ) ;
}
static inline int F_250 ( struct V_63 * V_331 ,
struct V_332 * time ,
struct V_63 * V_333 )
{
int V_334 = F_251 ( & V_331 -> V_335 , time ) ;
if ( V_334 > 0 ) {
return 1 ;
} else if ( V_334 < 0 ) {
return 0 ;
} else {
return V_331 > V_333 ;
}
}
static inline int F_252 ( void * V_336 , void * V_337 )
{
struct V_63 * V_331 = V_336 ;
struct V_63 * V_333 = V_337 ;
return F_250 ( V_331 , & V_333 -> V_335 , V_333 ) ;
}
int F_253 ( struct V_1 * V_21 ,
bool (* F_254)( struct V_63 * , void * ) ,
void (* F_255)( struct V_63 * , void * ) ,
void * V_136 , struct V_338 * V_339 )
{
int V_224 , V_23 ;
struct V_327 V_328 ;
struct V_63 * V_318 , * V_340 ;
struct V_63 * V_341 = NULL ;
struct V_338 V_342 ;
struct V_332 V_343 = { 0 , 0 } ;
if ( V_339 ) {
V_339 -> V_344 = & F_252 ;
} else {
V_339 = & V_342 ;
V_224 = F_256 ( V_339 , V_345 , V_56 , & F_252 ) ;
if ( V_224 )
return V_224 ;
}
V_346:
V_339 -> V_303 = 0 ;
F_247 ( V_21 , & V_328 ) ;
while ( ( V_318 = F_248 ( & V_328 ) ) ) {
if ( F_254 && ! F_254 ( V_318 , V_136 ) )
continue;
if ( ! F_250 ( V_318 , & V_343 , V_341 ) )
continue;
V_340 = F_257 ( V_339 , V_318 ) ;
if ( V_340 == NULL ) {
F_168 ( V_318 ) ;
} else if ( V_340 != V_318 ) {
F_168 ( V_318 ) ;
F_172 ( V_340 ) ;
}
}
F_249 ( & V_328 ) ;
if ( V_339 -> V_303 ) {
for ( V_23 = 0 ; V_23 < V_339 -> V_303 ; V_23 ++ ) {
struct V_63 * V_347 = V_339 -> V_348 [ V_23 ] ;
if ( V_23 == 0 ) {
V_343 = V_347 -> V_335 ;
V_341 = V_347 ;
}
F_255 ( V_347 , V_136 ) ;
F_172 ( V_347 ) ;
}
goto V_346;
}
if ( V_339 == & V_342 )
F_258 ( & V_342 ) ;
return 0 ;
}
static void F_259 ( struct V_63 * V_64 , void * V_136 )
{
struct V_2 * V_349 = V_136 ;
F_13 ( & V_8 ) ;
F_158 ( V_349 , V_64 , false ) ;
F_14 ( & V_8 ) ;
}
int F_260 ( struct V_2 * V_350 , struct V_2 * V_247 )
{
return F_253 ( & V_247 -> V_9 , NULL , F_259 ,
V_350 , NULL ) ;
}
static void * F_261 ( int V_54 )
{
if ( F_262 ( V_54 ) )
return F_263 ( V_54 * sizeof( V_351 ) ) ;
else
return F_65 ( V_54 * sizeof( V_351 ) , V_56 ) ;
}
static void F_264 ( void * V_318 )
{
if ( F_265 ( V_318 ) )
F_266 ( V_318 ) ;
else
F_28 ( V_318 ) ;
}
static int F_267 ( V_351 * V_352 , int V_353 )
{
int V_354 , V_355 = 1 ;
if ( V_353 == 0 || V_353 == 1 )
return V_353 ;
for ( V_354 = 1 ; V_354 < V_353 ; V_354 ++ ) {
while ( V_352 [ V_354 ] == V_352 [ V_354 - 1 ] ) {
V_354 ++ ;
if ( V_354 == V_353 )
goto V_356;
}
V_352 [ V_355 ] = V_352 [ V_354 ] ;
V_355 ++ ;
}
V_356:
return V_355 ;
}
static int F_268 ( const void * V_357 , const void * V_358 )
{
return * ( V_351 * ) V_357 - * ( V_351 * ) V_358 ;
}
static struct V_359 * F_269 ( struct V_2 * V_3 ,
enum V_360 type )
{
struct V_359 * V_329 ;
struct V_361 * V_362 = F_270 ( V_153 ) ;
F_13 ( & V_3 -> V_159 ) ;
F_54 (l, &cgrp->pidlists, links) {
if ( V_329 -> V_22 . type == type && V_329 -> V_22 . V_362 == V_362 ) {
F_271 ( & V_329 -> V_363 ) ;
F_14 ( & V_3 -> V_159 ) ;
return V_329 ;
}
}
V_329 = F_42 ( sizeof( struct V_359 ) , V_56 ) ;
if ( ! V_329 ) {
F_14 ( & V_3 -> V_159 ) ;
return V_329 ;
}
F_272 ( & V_329 -> V_363 ) ;
F_271 ( & V_329 -> V_363 ) ;
V_329 -> V_22 . type = type ;
V_329 -> V_22 . V_362 = F_273 ( V_362 ) ;
V_329 -> V_364 = V_3 ;
F_43 ( & V_329 -> V_365 , & V_3 -> V_91 ) ;
F_14 ( & V_3 -> V_159 ) ;
return V_329 ;
}
static int F_274 ( struct V_2 * V_3 , enum V_360 type ,
struct V_359 * * V_366 )
{
V_351 * V_367 ;
int V_353 ;
int V_233 , V_368 = 0 ;
struct V_327 V_328 ;
struct V_63 * V_218 ;
struct V_359 * V_329 ;
V_353 = F_230 ( V_3 ) ;
V_367 = F_261 ( V_353 ) ;
if ( ! V_367 )
return - V_57 ;
F_247 ( & V_3 -> V_9 , & V_328 ) ;
while ( ( V_218 = F_248 ( & V_328 ) ) ) {
if ( F_275 ( V_368 == V_353 ) )
break;
if ( type == V_369 )
V_233 = F_276 ( V_218 ) ;
else
V_233 = F_277 ( V_218 ) ;
if ( V_233 > 0 )
V_367 [ V_368 ++ ] = V_233 ;
}
F_249 ( & V_328 ) ;
V_353 = V_368 ;
F_278 ( V_367 , V_353 , sizeof( V_351 ) , F_268 , NULL ) ;
if ( type == V_369 )
V_353 = F_267 ( V_367 , V_353 ) ;
V_329 = F_269 ( V_3 , type ) ;
if ( ! V_329 ) {
F_264 ( V_367 ) ;
return - V_57 ;
}
F_264 ( V_329 -> V_352 ) ;
V_329 -> V_352 = V_367 ;
V_329 -> V_353 = V_353 ;
V_329 -> V_370 ++ ;
F_279 ( & V_329 -> V_363 ) ;
* V_366 = V_329 ;
return 0 ;
}
int F_280 ( struct V_371 * V_372 , struct V_17 * V_17 )
{
int V_114 = - V_145 ;
struct V_2 * V_3 ;
struct V_327 V_328 ;
struct V_63 * V_218 ;
if ( V_17 -> V_129 -> V_175 != & V_176 ||
! F_76 ( V_17 -> V_101 -> V_73 ) )
goto V_284;
V_114 = 0 ;
V_3 = V_17 -> V_18 ;
F_247 ( & V_3 -> V_9 , & V_328 ) ;
while ( ( V_218 = F_248 ( & V_328 ) ) ) {
switch ( V_218 -> V_278 ) {
case V_373 :
V_372 -> V_374 ++ ;
break;
case V_375 :
V_372 -> V_376 ++ ;
break;
case V_377 :
V_372 -> V_378 ++ ;
break;
case V_379 :
V_372 -> V_380 ++ ;
break;
default:
if ( F_281 ( V_218 ) )
V_372 -> V_381 ++ ;
break;
}
}
F_249 ( & V_328 ) ;
V_284:
return V_114 ;
}
static void * F_282 ( struct V_127 * V_382 , T_6 * V_324 )
{
struct V_359 * V_329 = V_382 -> V_269 ;
int V_383 = 0 , V_233 = * V_324 ;
int * V_384 ;
F_283 ( & V_329 -> V_363 ) ;
if ( V_233 ) {
int V_165 = V_329 -> V_353 ;
while ( V_383 < V_165 ) {
int V_385 = ( V_383 + V_165 ) / 2 ;
if ( V_329 -> V_352 [ V_385 ] == V_233 ) {
V_383 = V_385 ;
break;
} else if ( V_329 -> V_352 [ V_385 ] <= V_233 )
V_383 = V_385 + 1 ;
else
V_165 = V_385 ;
}
}
if ( V_383 >= V_329 -> V_353 )
return NULL ;
V_384 = V_329 -> V_352 + V_383 ;
* V_324 = * V_384 ;
return V_384 ;
}
static void F_284 ( struct V_127 * V_382 , void * V_386 )
{
struct V_359 * V_329 = V_382 -> V_269 ;
F_285 ( & V_329 -> V_363 ) ;
}
static void * F_286 ( struct V_127 * V_382 , void * V_386 , T_6 * V_324 )
{
struct V_359 * V_329 = V_382 -> V_269 ;
V_351 * V_318 = V_386 ;
V_351 * V_165 = V_329 -> V_352 + V_329 -> V_353 ;
V_318 ++ ;
if ( V_318 >= V_165 ) {
return NULL ;
} else {
* V_324 = * V_318 ;
return V_318 ;
}
}
static int F_287 ( struct V_127 * V_382 , void * V_386 )
{
return F_102 ( V_382 , L_28 , * ( int * ) V_386 ) ;
}
static void F_288 ( struct V_359 * V_329 )
{
F_13 ( & V_329 -> V_364 -> V_159 ) ;
F_271 ( & V_329 -> V_363 ) ;
F_35 ( ! V_329 -> V_370 ) ;
if ( ! -- V_329 -> V_370 ) {
F_24 ( & V_329 -> V_365 ) ;
F_14 ( & V_329 -> V_364 -> V_159 ) ;
F_264 ( V_329 -> V_352 ) ;
F_289 ( V_329 -> V_22 . V_362 ) ;
F_279 ( & V_329 -> V_363 ) ;
F_28 ( V_329 ) ;
return;
}
F_14 ( & V_329 -> V_364 -> V_159 ) ;
F_279 ( & V_329 -> V_363 ) ;
}
static int F_290 ( struct V_68 * V_68 , struct V_251 * V_251 )
{
struct V_359 * V_329 ;
if ( ! ( V_251 -> V_387 & V_388 ) )
return 0 ;
V_329 = ( (struct V_127 * ) V_251 -> V_389 ) -> V_269 ;
F_288 ( V_329 ) ;
return F_291 ( V_68 , V_251 ) ;
}
static int F_292 ( struct V_251 * V_251 , enum V_360 type )
{
struct V_2 * V_3 = F_9 ( V_251 -> V_266 -> V_98 ) ;
struct V_359 * V_329 ;
int V_224 ;
if ( ! ( V_251 -> V_387 & V_388 ) )
return 0 ;
V_224 = F_274 ( V_3 , type , & V_329 ) ;
if ( V_224 )
return V_224 ;
V_251 -> V_285 = & V_390 ;
V_224 = F_293 ( V_251 , & V_391 ) ;
if ( V_224 ) {
F_288 ( V_329 ) ;
return V_224 ;
}
( (struct V_127 * ) V_251 -> V_389 ) -> V_269 = V_329 ;
return 0 ;
}
static int F_294 ( struct V_68 * V_392 , struct V_251 * V_251 )
{
return F_292 ( V_251 , V_393 ) ;
}
static int F_295 ( struct V_68 * V_392 , struct V_251 * V_251 )
{
return F_292 ( V_251 , V_369 ) ;
}
static T_3 F_296 ( struct V_1 * V_21 ,
struct V_20 * V_102 )
{
return F_8 ( V_21 -> V_2 ) ;
}
static int F_297 ( struct V_1 * V_21 ,
struct V_20 * V_102 , T_3 V_259 )
{
F_298 ( V_15 , & V_21 -> V_2 -> V_11 ) ;
if ( V_259 )
F_26 ( V_16 , & V_21 -> V_2 -> V_11 ) ;
else
F_298 ( V_16 , & V_21 -> V_2 -> V_11 ) ;
return 0 ;
}
static void F_299 ( struct V_2 * V_3 )
{
struct V_70 * V_71 = V_3 -> V_50 -> V_71 ;
F_31 ( & V_71 -> V_394 ) ;
F_68 ( V_3 -> V_17 ) ;
F_69 ( V_71 ) ;
}
static void F_300 ( struct V_87 * V_88 )
{
struct V_395 * V_396 = F_67 ( V_88 , struct V_395 ,
remove ) ;
struct V_1 * V_21 = V_396 -> V_21 ;
F_301 ( V_396 -> V_397 , & V_396 -> V_398 ) ;
V_396 -> V_102 -> V_399 ( V_21 , V_396 -> V_102 , V_396 -> V_400 ) ;
F_302 ( V_396 -> V_400 , 1 ) ;
F_303 ( V_396 -> V_400 ) ;
F_28 ( V_396 ) ;
F_199 ( V_21 ) ;
}
static int F_304 ( T_8 * V_398 , unsigned V_69 ,
int V_401 , void * V_22 )
{
struct V_395 * V_396 = F_67 ( V_398 ,
struct V_395 , V_398 ) ;
struct V_2 * V_3 = V_396 -> V_21 -> V_2 ;
unsigned long V_11 = ( unsigned long ) V_22 ;
if ( V_11 & V_402 ) {
F_91 ( & V_3 -> V_161 ) ;
if ( ! F_25 ( & V_396 -> V_352 ) ) {
F_87 ( & V_396 -> V_352 ) ;
F_305 ( & V_396 -> remove ) ;
}
F_93 ( & V_3 -> V_161 ) ;
}
return 0 ;
}
static void F_306 ( struct V_251 * V_251 ,
T_9 * V_397 , T_10 * V_403 )
{
struct V_395 * V_396 = F_67 ( V_403 ,
struct V_395 , V_403 ) ;
V_396 -> V_397 = V_397 ;
F_307 ( V_397 , & V_396 -> V_398 ) ;
}
static int F_308 ( struct V_1 * V_9 ,
struct V_20 * V_102 , const char * V_250 )
{
struct V_2 * V_3 = V_9 -> V_2 ;
struct V_395 * V_396 ;
struct V_1 * V_404 ;
unsigned int V_405 , V_406 ;
struct V_407 V_408 ;
struct V_407 V_409 ;
char * V_410 ;
int V_114 ;
V_405 = F_309 ( V_250 , & V_410 , 10 ) ;
if ( * V_410 != ' ' )
return - V_145 ;
V_250 = V_410 + 1 ;
V_406 = F_309 ( V_250 , & V_410 , 10 ) ;
if ( ( * V_410 != ' ' ) && ( * V_410 != '\0' ) )
return - V_145 ;
V_250 = V_410 + 1 ;
V_396 = F_42 ( sizeof( * V_396 ) , V_56 ) ;
if ( ! V_396 )
return - V_57 ;
F_41 ( & V_396 -> V_352 ) ;
F_310 ( & V_396 -> V_403 , F_306 ) ;
F_311 ( & V_396 -> V_398 , F_304 ) ;
F_73 ( & V_396 -> remove , F_300 ) ;
V_408 = F_312 ( V_405 ) ;
if ( ! V_408 . V_251 ) {
V_114 = - V_411 ;
goto V_412;
}
V_396 -> V_400 = F_313 ( V_408 . V_251 ) ;
if ( F_133 ( V_396 -> V_400 ) ) {
V_114 = F_134 ( V_396 -> V_400 ) ;
goto V_413;
}
V_409 = F_312 ( V_406 ) ;
if ( ! V_409 . V_251 ) {
V_114 = - V_411 ;
goto V_414;
}
V_114 = F_314 ( F_217 ( V_409 . V_251 ) , V_415 ) ;
if ( V_114 < 0 )
goto V_416;
V_396 -> V_102 = F_216 ( V_409 . V_251 ) ;
if ( F_133 ( V_396 -> V_102 ) ) {
V_114 = F_134 ( V_396 -> V_102 ) ;
goto V_416;
}
if ( ! V_396 -> V_102 -> V_5 ) {
V_114 = - V_411 ;
goto V_416;
}
F_146 () ;
V_114 = - V_145 ;
V_396 -> V_21 = F_1 ( V_3 , V_396 -> V_102 -> V_5 ) ;
V_404 = F_315 ( V_409 . V_251 -> V_266 -> V_98 , V_396 -> V_102 -> V_5 ) ;
if ( V_396 -> V_21 && V_396 -> V_21 == V_404 && F_197 ( V_396 -> V_21 ) )
V_114 = 0 ;
F_147 () ;
if ( V_114 )
goto V_416;
if ( ! V_396 -> V_102 -> V_417 || ! V_396 -> V_102 -> V_399 ) {
V_114 = - V_145 ;
goto V_418;
}
V_114 = V_396 -> V_102 -> V_417 ( V_396 -> V_21 , V_396 -> V_102 ,
V_396 -> V_400 , V_250 ) ;
if ( V_114 )
goto V_418;
V_408 . V_251 -> V_285 -> V_419 ( V_408 . V_251 , & V_396 -> V_403 ) ;
F_91 ( & V_3 -> V_161 ) ;
F_43 ( & V_396 -> V_352 , & V_3 -> V_160 ) ;
F_93 ( & V_3 -> V_161 ) ;
F_316 ( V_409 ) ;
F_316 ( V_408 ) ;
return 0 ;
V_418:
F_199 ( V_396 -> V_21 ) ;
V_416:
F_316 ( V_409 ) ;
V_414:
F_303 ( V_396 -> V_400 ) ;
V_413:
F_316 ( V_408 ) ;
V_412:
F_28 ( V_396 ) ;
return V_114 ;
}
static T_3 F_317 ( struct V_1 * V_21 ,
struct V_20 * V_102 )
{
return F_5 ( V_135 , & V_21 -> V_2 -> V_11 ) ;
}
static int F_318 ( struct V_1 * V_21 ,
struct V_20 * V_102 , T_3 V_259 )
{
if ( V_259 )
F_26 ( V_135 , & V_21 -> V_2 -> V_11 ) ;
else
F_298 ( V_135 , & V_21 -> V_2 -> V_11 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_4 * V_5 ;
int V_23 , V_114 = 0 ;
F_16 (ss, i) {
struct V_104 * V_105 ;
if ( ! F_5 ( V_23 , & V_52 ) )
continue;
F_54 (set, &ss->cftsets, node) {
V_114 = F_89 ( V_3 , V_105 -> V_106 , true ) ;
if ( V_114 < 0 )
goto V_284;
}
}
return 0 ;
V_284:
F_88 ( V_3 , V_52 ) ;
return V_114 ;
}
static void F_319 ( struct V_87 * V_88 )
{
struct V_1 * V_21 =
F_67 ( V_88 , struct V_1 , V_89 ) ;
struct V_2 * V_3 = V_21 -> V_2 ;
if ( V_21 -> V_13 )
F_199 ( V_21 -> V_13 ) ;
V_21 -> V_5 -> V_420 ( V_21 ) ;
F_299 ( V_3 ) ;
}
static void F_320 ( struct V_37 * V_37 )
{
struct V_1 * V_21 =
F_67 ( V_37 , struct V_1 , V_37 ) ;
F_73 ( & V_21 -> V_89 , F_319 ) ;
F_74 ( V_94 , & V_21 -> V_89 ) ;
}
static void F_321 ( struct V_421 * V_422 )
{
struct V_1 * V_21 =
F_67 ( V_422 , struct V_1 , V_423 ) ;
F_97 ( V_21 -> V_2 -> V_6 [ V_21 -> V_5 -> V_7 ] , NULL ) ;
F_78 ( & V_21 -> V_37 , F_320 ) ;
}
static void F_322 ( struct V_1 * V_21 , struct V_4 * V_5 ,
struct V_2 * V_3 )
{
V_21 -> V_2 = V_3 ;
V_21 -> V_5 = V_5 ;
V_21 -> V_11 = 0 ;
if ( V_3 -> V_13 )
V_21 -> V_13 = F_1 ( V_3 -> V_13 , V_5 ) ;
else
V_21 -> V_11 |= V_424 ;
F_35 ( F_1 ( V_3 , V_5 ) ) ;
}
static int F_323 ( struct V_1 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
int V_114 = 0 ;
F_49 ( & V_8 ) ;
if ( V_5 -> V_425 )
V_114 = V_5 -> V_425 ( V_21 ) ;
if ( ! V_114 ) {
V_21 -> V_11 |= V_426 ;
V_21 -> V_2 -> V_427 ++ ;
F_97 ( V_21 -> V_2 -> V_6 [ V_5 -> V_7 ] , V_21 ) ;
}
return V_114 ;
}
static void F_324 ( struct V_1 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
F_49 ( & V_8 ) ;
if ( ! ( V_21 -> V_11 & V_426 ) )
return;
if ( V_5 -> V_428 )
V_5 -> V_428 ( V_21 ) ;
V_21 -> V_11 &= ~ V_426 ;
V_21 -> V_2 -> V_427 -- ;
F_98 ( V_21 -> V_2 -> V_6 [ V_5 -> V_7 ] , V_21 ) ;
}
static long F_325 ( struct V_2 * V_13 , struct V_17 * V_17 ,
T_1 V_69 )
{
struct V_1 * V_429 [ V_58 ] = { } ;
struct V_2 * V_3 ;
struct V_83 * V_84 ;
struct V_51 * V_50 = V_13 -> V_50 ;
int V_284 = 0 ;
struct V_4 * V_5 ;
struct V_70 * V_71 = V_50 -> V_71 ;
V_3 = F_42 ( sizeof( * V_3 ) , V_56 ) ;
if ( ! V_3 )
return - V_57 ;
V_84 = F_64 ( V_17 ) ;
if ( ! V_84 )
goto V_430;
F_97 ( V_3 -> V_84 , V_84 ) ;
V_3 -> V_96 = F_136 ( & V_50 -> V_95 , NULL , 1 , 0 , V_56 ) ;
if ( V_3 -> V_96 < 0 )
goto V_431;
if ( ! F_12 ( V_13 ) ) {
V_284 = - V_235 ;
goto V_432;
}
F_31 ( & V_71 -> V_394 ) ;
F_112 ( V_3 ) ;
V_17 -> V_18 = V_3 ;
V_3 -> V_17 = V_17 ;
V_3 -> V_13 = V_13 ;
V_3 -> V_9 . V_13 = & V_13 -> V_9 ;
V_3 -> V_50 = V_13 -> V_50 ;
if ( F_8 ( V_13 ) )
F_26 ( V_16 , & V_3 -> V_11 ) ;
if ( F_5 ( V_135 , & V_13 -> V_11 ) )
F_26 ( V_135 , & V_3 -> V_11 ) ;
F_101 (root, ss) {
struct V_1 * V_21 ;
V_21 = V_5 -> V_433 ( F_1 ( V_13 , V_5 ) ) ;
if ( F_133 ( V_21 ) ) {
V_284 = F_134 ( V_21 ) ;
goto V_434;
}
V_429 [ V_5 -> V_7 ] = V_21 ;
V_284 = F_326 ( & V_21 -> V_423 , F_321 ) ;
if ( V_284 )
goto V_434;
F_322 ( V_21 , V_5 , V_3 ) ;
}
V_284 = F_218 ( V_17 , V_181 | V_69 , V_71 ) ;
if ( V_284 < 0 )
goto V_434;
F_49 ( & V_17 -> V_101 -> V_103 ) ;
V_3 -> V_325 = V_435 ++ ;
F_327 ( & V_3 -> V_123 , & V_3 -> V_13 -> V_156 ) ;
V_50 -> V_90 ++ ;
F_82 ( V_13 -> V_17 ) ;
F_101 (root, ss) {
struct V_1 * V_21 = V_429 [ V_5 -> V_7 ] ;
V_284 = F_323 ( V_21 ) ;
if ( V_284 )
goto V_436;
F_82 ( V_17 ) ;
F_328 ( V_21 -> V_13 ) ;
V_429 [ V_5 -> V_7 ] = NULL ;
if ( V_5 -> V_437 && ! V_5 -> V_438 &&
V_13 -> V_13 ) {
F_108 ( L_34 ,
V_153 -> V_154 , V_153 -> V_233 , V_5 -> V_84 ) ;
if ( ! strcmp ( V_5 -> V_84 , L_35 ) )
F_108 ( L_36 ) ;
V_5 -> V_438 = true ;
}
}
F_329 ( & V_50 -> V_95 , V_3 , V_3 -> V_96 ) ;
V_284 = F_89 ( V_3 , V_201 , true ) ;
if ( V_284 )
goto V_436;
V_284 = F_96 ( V_3 , V_50 -> V_52 ) ;
if ( V_284 )
goto V_436;
F_14 ( & V_8 ) ;
F_14 ( & V_3 -> V_17 -> V_101 -> V_103 ) ;
return 0 ;
V_434:
F_101 (root, ss) {
struct V_1 * V_21 = V_429 [ V_5 -> V_7 ] ;
if ( V_21 ) {
F_330 ( & V_21 -> V_423 ) ;
V_5 -> V_420 ( V_21 ) ;
}
}
F_14 ( & V_8 ) ;
F_69 ( V_71 ) ;
V_432:
F_77 ( & V_50 -> V_95 , V_3 -> V_96 ) ;
V_431:
F_28 ( F_71 ( V_3 -> V_84 ) ) ;
V_430:
F_28 ( V_3 ) ;
return V_284 ;
V_436:
F_101 (root, ss) {
struct V_1 * V_21 = V_429 [ V_5 -> V_7 ] ;
if ( V_21 ) {
F_330 ( & V_21 -> V_423 ) ;
V_5 -> V_420 ( V_21 ) ;
}
}
F_331 ( V_3 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_17 -> V_101 -> V_103 ) ;
return V_284 ;
}
static int F_332 ( struct V_68 * V_308 , struct V_17 * V_17 , T_1 V_69 )
{
struct V_2 * V_439 = V_17 -> V_98 -> V_18 ;
return F_325 ( V_439 , V_17 , V_69 | V_181 ) ;
}
static void F_333 ( struct V_87 * V_88 )
{
struct V_1 * V_21 =
F_67 ( V_88 , struct V_1 , V_89 ) ;
struct V_2 * V_3 = V_21 -> V_2 ;
F_13 ( & V_8 ) ;
F_324 ( V_21 ) ;
if ( ! V_3 -> V_427 && F_4 ( V_3 ) )
F_334 ( V_3 ) ;
F_14 ( & V_8 ) ;
F_199 ( V_21 ) ;
}
static void F_335 ( struct V_421 * V_422 )
{
struct V_1 * V_21 =
F_67 ( V_422 , struct V_1 , V_423 ) ;
F_73 ( & V_21 -> V_89 , F_333 ) ;
F_74 ( V_94 , & V_21 -> V_89 ) ;
}
static void F_336 ( struct V_1 * V_21 )
{
F_88 ( V_21 -> V_2 , 1 << V_21 -> V_5 -> V_7 ) ;
F_328 ( V_21 ) ;
F_337 ( & V_21 -> V_423 , F_335 ) ;
}
static int F_331 ( struct V_2 * V_3 )
__releases( &cgroup_mutex
static void F_334 ( struct V_2 * V_3 )
{
struct V_2 * V_13 = V_3 -> V_13 ;
struct V_17 * V_100 = V_3 -> V_17 ;
F_49 ( & V_8 ) ;
F_338 ( & V_3 -> V_123 ) ;
F_68 ( V_100 ) ;
F_26 ( V_15 , & V_13 -> V_11 ) ;
F_27 ( V_13 ) ;
}
static int F_339 ( struct V_68 * V_440 , struct V_17 * V_17 )
{
int V_114 ;
F_13 ( & V_8 ) ;
V_114 = F_331 ( V_17 -> V_18 ) ;
F_14 ( & V_8 ) ;
return V_114 ;
}
static void T_11 F_340 ( struct V_4 * V_5 )
{
F_41 ( & V_5 -> V_317 ) ;
if ( V_5 -> V_441 ) {
struct V_20 * V_102 ;
for ( V_102 = V_5 -> V_441 ; V_102 -> V_84 [ 0 ] != '\0' ; V_102 ++ )
V_102 -> V_5 = V_5 ;
V_5 -> V_442 . V_106 = V_5 -> V_441 ;
F_47 ( & V_5 -> V_442 . V_99 , & V_5 -> V_317 ) ;
}
}
static void T_12 F_341 ( struct V_4 * V_5 )
{
struct V_1 * V_21 ;
F_342 ( V_443 L_37 , V_5 -> V_84 ) ;
F_13 ( & V_8 ) ;
F_340 ( V_5 ) ;
F_43 ( & V_5 -> V_123 , & V_116 . V_124 ) ;
V_5 -> V_50 = & V_116 ;
V_21 = V_5 -> V_433 ( F_1 ( V_122 , V_5 ) ) ;
F_35 ( F_133 ( V_21 ) ) ;
F_322 ( V_21 , V_5 , V_122 ) ;
V_66 . V_6 [ V_5 -> V_7 ] = V_21 ;
V_444 |= V_5 -> V_445 || V_5 -> exit ;
F_35 ( ! F_25 ( & V_446 . V_60 ) ) ;
F_35 ( F_323 ( V_21 ) ) ;
F_14 ( & V_8 ) ;
F_35 ( V_5 -> V_119 ) ;
}
int T_11 F_343 ( struct V_4 * V_5 )
{
struct V_1 * V_21 ;
int V_23 , V_114 ;
struct V_447 * V_270 ;
struct V_24 * V_25 ;
unsigned long V_22 ;
if ( V_5 -> V_84 == NULL || strlen ( V_5 -> V_84 ) > V_309 ||
V_5 -> V_433 == NULL || V_5 -> V_420 == NULL )
return - V_145 ;
if ( V_5 -> V_445 || V_5 -> exit )
return - V_145 ;
if ( V_5 -> V_119 == NULL ) {
F_35 ( V_4 [ V_5 -> V_7 ] != V_5 ) ;
return 0 ;
}
F_340 ( V_5 ) ;
F_13 ( & V_8 ) ;
V_4 [ V_5 -> V_7 ] = V_5 ;
V_21 = V_5 -> V_433 ( F_1 ( V_122 , V_5 ) ) ;
if ( F_133 ( V_21 ) ) {
V_4 [ V_5 -> V_7 ] = NULL ;
F_14 ( & V_8 ) ;
return F_134 ( V_21 ) ;
}
F_43 ( & V_5 -> V_123 , & V_116 . V_124 ) ;
V_5 -> V_50 = & V_116 ;
F_322 ( V_21 , V_5 , V_122 ) ;
F_19 ( & V_31 ) ;
F_344 (css_set_table, i, tmp, cset, hlist) {
if ( V_25 -> V_6 [ V_5 -> V_7 ] )
continue;
F_22 ( & V_25 -> V_32 ) ;
V_25 -> V_6 [ V_5 -> V_7 ] = V_21 ;
V_22 = F_15 ( V_25 -> V_6 ) ;
F_55 ( V_62 , & V_25 -> V_32 , V_22 ) ;
}
F_21 ( & V_31 ) ;
V_114 = F_323 ( V_21 ) ;
if ( V_114 )
goto V_448;
F_14 ( & V_8 ) ;
return 0 ;
V_448:
F_14 ( & V_8 ) ;
F_345 ( V_5 ) ;
return V_114 ;
}
void F_345 ( struct V_4 * V_5 )
{
struct V_27 * V_28 ;
F_35 ( V_5 -> V_119 == NULL ) ;
F_35 ( V_5 -> V_50 != & V_116 ) ;
F_13 ( & V_8 ) ;
F_324 ( F_1 ( V_122 , V_5 ) ) ;
V_4 [ V_5 -> V_7 ] = NULL ;
F_87 ( & V_5 -> V_123 ) ;
F_19 ( & V_31 ) ;
F_54 (link, &cgroup_dummy_top->cset_links, cset_link) {
struct V_24 * V_25 = V_28 -> V_25 ;
unsigned long V_22 ;
F_22 ( & V_25 -> V_32 ) ;
V_25 -> V_6 [ V_5 -> V_7 ] = NULL ;
V_22 = F_15 ( V_25 -> V_6 ) ;
F_55 ( V_62 , & V_25 -> V_32 , V_22 ) ;
}
F_21 ( & V_31 ) ;
V_5 -> V_420 ( F_1 ( V_122 , V_5 ) ) ;
F_98 ( V_122 -> V_6 [ V_5 -> V_7 ] , NULL ) ;
F_14 ( & V_8 ) ;
}
int T_12 F_346 ( void )
{
struct V_4 * V_5 ;
int V_23 ;
F_52 ( & V_66 . V_30 , 1 ) ;
F_41 ( & V_66 . V_44 ) ;
F_41 ( & V_66 . V_60 ) ;
F_53 ( & V_66 . V_32 ) ;
V_33 = 1 ;
F_116 ( & V_116 ) ;
V_59 = 1 ;
F_98 ( V_446 . V_221 , & V_66 ) ;
V_449 . V_25 = & V_66 ;
V_449 . V_3 = V_122 ;
F_43 ( & V_449 . V_34 , & V_122 -> V_36 ) ;
F_43 ( & V_449 . V_35 , & V_66 . V_44 ) ;
F_347 (ss, i) {
F_35 ( ! V_5 -> V_84 ) ;
F_35 ( strlen ( V_5 -> V_84 ) > V_309 ) ;
F_35 ( ! V_5 -> V_433 ) ;
F_35 ( ! V_5 -> V_420 ) ;
if ( V_5 -> V_7 != V_23 ) {
F_342 ( V_450 L_38 ,
V_5 -> V_84 , V_5 -> V_7 ) ;
F_348 () ;
}
if ( V_5 -> V_451 )
F_341 ( V_5 ) ;
}
return 0 ;
}
int T_12 F_349 ( void )
{
struct V_4 * V_5 ;
unsigned long V_22 ;
int V_23 , V_284 ;
V_284 = F_350 ( & V_82 ) ;
if ( V_284 )
return V_284 ;
F_347 (ss, i) {
if ( ! V_5 -> V_451 )
F_341 ( V_5 ) ;
}
F_13 ( & V_8 ) ;
F_13 ( & V_115 ) ;
V_22 = F_15 ( V_66 . V_6 ) ;
F_55 ( V_62 , & V_66 . V_32 , V_22 ) ;
F_35 ( F_118 ( & V_116 , 0 , 1 ) ) ;
V_284 = F_136 ( & V_116 . V_95 , V_122 ,
0 , 1 , V_56 ) ;
F_35 ( V_284 < 0 ) ;
F_14 ( & V_115 ) ;
F_14 ( & V_8 ) ;
V_452 = F_351 ( L_39 , V_453 ) ;
if ( ! V_452 ) {
V_284 = - V_57 ;
goto V_207;
}
V_284 = F_352 ( & V_454 ) ;
if ( V_284 < 0 ) {
F_353 ( V_452 ) ;
goto V_207;
}
F_354 ( L_40 , 0 , NULL , & V_455 ) ;
V_207:
if ( V_284 )
F_355 ( & V_82 ) ;
return V_284 ;
}
static int T_12 F_356 ( void )
{
V_94 = F_357 ( L_41 , 0 , 1 ) ;
F_35 ( ! V_94 ) ;
return 0 ;
}
int F_358 ( struct V_127 * V_279 , void * V_386 )
{
struct V_233 * V_233 ;
struct V_63 * V_218 ;
char * V_204 ;
int V_224 ;
struct V_51 * V_50 ;
V_224 = - V_57 ;
V_204 = F_65 ( V_345 , V_56 ) ;
if ( ! V_204 )
goto V_207;
V_224 = - V_237 ;
V_233 = V_279 -> V_269 ;
V_218 = F_359 ( V_233 , V_456 ) ;
if ( ! V_218 )
goto V_457;
V_224 = 0 ;
F_13 ( & V_8 ) ;
F_137 (root) {
struct V_4 * V_5 ;
struct V_2 * V_3 ;
int V_54 = 0 ;
F_102 ( V_279 , L_42 , V_50 -> V_167 ) ;
F_101 (root, ss)
F_102 ( V_279 , L_43 , V_54 ++ ? L_9 : L_24 , V_5 -> V_84 ) ;
if ( strlen ( V_50 -> V_84 ) )
F_102 ( V_279 , L_44 , V_54 ? L_9 : L_24 ,
V_50 -> V_84 ) ;
F_179 ( V_279 , ':' ) ;
V_3 = F_56 ( V_218 , V_50 ) ;
V_224 = F_144 ( V_3 , V_204 , V_345 ) ;
if ( V_224 < 0 )
goto V_152;
F_103 ( V_279 , V_204 ) ;
F_179 ( V_279 , '\n' ) ;
}
V_152:
F_14 ( & V_8 ) ;
F_172 ( V_218 ) ;
V_457:
F_28 ( V_204 ) ;
V_207:
return V_224 ;
}
static int F_360 ( struct V_127 * V_279 , void * V_386 )
{
struct V_4 * V_5 ;
int V_23 ;
F_103 ( V_279 , L_45 ) ;
F_13 ( & V_8 ) ;
F_16 (ss, i)
F_102 ( V_279 , L_46 ,
V_5 -> V_84 , V_5 -> V_50 -> V_167 ,
V_5 -> V_50 -> V_90 , ! V_5 -> V_151 ) ;
F_14 ( & V_8 ) ;
return 0 ;
}
static int F_361 ( struct V_68 * V_68 , struct V_251 * V_251 )
{
return F_198 ( V_251 , F_360 , NULL ) ;
}
void F_362 ( struct V_63 * V_458 )
{
F_156 ( V_153 ) ;
F_30 ( F_58 ( V_153 ) ) ;
V_458 -> V_221 = V_153 -> V_221 ;
F_157 ( V_153 ) ;
F_41 ( & V_458 -> V_222 ) ;
}
void F_363 ( struct V_63 * V_458 )
{
struct V_4 * V_5 ;
int V_23 ;
if ( V_320 ) {
F_19 ( & V_31 ) ;
F_156 ( V_458 ) ;
if ( F_25 ( & V_458 -> V_222 ) )
F_43 ( & V_458 -> V_222 , & F_58 ( V_458 ) -> V_60 ) ;
F_157 ( V_458 ) ;
F_21 ( & V_31 ) ;
}
if ( V_444 ) {
F_347 (ss, i)
if ( V_5 -> V_445 )
V_5 -> V_445 ( V_458 ) ;
}
}
void F_364 ( struct V_63 * V_218 , int V_459 )
{
struct V_4 * V_5 ;
struct V_24 * V_25 ;
int V_23 ;
if ( ! F_25 ( & V_218 -> V_222 ) ) {
F_19 ( & V_31 ) ;
if ( ! F_25 ( & V_218 -> V_222 ) )
F_87 ( & V_218 -> V_222 ) ;
F_21 ( & V_31 ) ;
}
F_156 ( V_218 ) ;
V_25 = F_58 ( V_218 ) ;
F_98 ( V_218 -> V_221 , & V_66 ) ;
if ( V_459 && V_444 ) {
F_347 (ss, i) {
if ( V_5 -> exit ) {
struct V_1 * V_460 = V_25 -> V_6 [ V_23 ] ;
struct V_1 * V_21 = F_365 ( V_218 , V_23 ) ;
V_5 -> exit ( V_21 , V_460 , V_218 ) ;
}
}
}
F_157 ( V_218 ) ;
F_33 ( V_25 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
if ( F_7 ( V_3 ) &&
F_25 ( & V_3 -> V_36 ) && F_25 ( & V_3 -> V_156 ) ) {
int V_461 = 0 ;
F_366 ( & V_462 ) ;
if ( ! F_4 ( V_3 ) &&
F_25 ( & V_3 -> V_158 ) ) {
F_43 ( & V_3 -> V_158 , & V_158 ) ;
V_461 = 1 ;
}
F_367 ( & V_462 ) ;
if ( V_461 )
F_305 ( & V_463 ) ;
}
}
static void F_368 ( struct V_87 * V_88 )
{
F_35 ( V_88 != & V_463 ) ;
F_13 ( & V_8 ) ;
F_366 ( & V_462 ) ;
while ( ! F_25 ( & V_158 ) ) {
char * V_464 [ 3 ] , * V_465 [ 3 ] ;
int V_23 ;
char * V_466 = NULL , * V_467 = NULL ;
struct V_2 * V_3 = F_36 ( V_158 . V_49 ,
struct V_2 ,
V_158 ) ;
F_87 ( & V_3 -> V_158 ) ;
F_367 ( & V_462 ) ;
V_466 = F_65 ( V_345 , V_56 ) ;
if ( ! V_466 )
goto V_468;
if ( F_144 ( V_3 , V_466 , V_345 ) < 0 )
goto V_468;
V_467 = F_369 ( V_3 -> V_50 -> V_134 , V_56 ) ;
if ( ! V_467 )
goto V_468;
V_23 = 0 ;
V_464 [ V_23 ++ ] = V_467 ;
V_464 [ V_23 ++ ] = V_466 ;
V_464 [ V_23 ] = NULL ;
V_23 = 0 ;
V_465 [ V_23 ++ ] = L_47 ;
V_465 [ V_23 ++ ] = L_48 ;
V_465 [ V_23 ] = NULL ;
F_14 ( & V_8 ) ;
F_370 ( V_464 [ 0 ] , V_464 , V_465 , V_469 ) ;
F_13 ( & V_8 ) ;
V_468:
F_28 ( V_466 ) ;
F_28 ( V_467 ) ;
F_366 ( & V_462 ) ;
}
F_367 ( & V_462 ) ;
F_14 ( & V_8 ) ;
}
static int T_12 F_371 ( char * V_470 )
{
struct V_4 * V_5 ;
char * V_139 ;
int V_23 ;
while ( ( V_139 = F_106 ( & V_470 , L_9 ) ) != NULL ) {
if ( ! * V_139 )
continue;
F_347 (ss, i) {
if ( ! strcmp ( V_139 , V_5 -> V_84 ) ) {
V_5 -> V_151 = 1 ;
F_342 ( V_443 L_49
L_50 , V_5 -> V_84 ) ;
break;
}
}
}
return 1 ;
}
struct V_1 * F_315 ( struct V_17 * V_17 ,
struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_125 ( ! F_236 () ) ;
if ( ! V_17 -> V_101 ||
V_17 -> V_101 -> V_187 != & V_188 )
return F_123 ( - V_411 ) ;
V_3 = F_9 ( V_17 ) ;
return F_1 ( V_3 , V_5 ) ? : F_123 ( - V_120 ) ;
}
struct V_1 * F_372 ( int V_96 , struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_373 ( F_236 () ||
F_3 ( & V_8 ) ,
L_51 ) ;
V_3 = F_374 ( & V_5 -> V_50 -> V_95 , V_96 ) ;
if ( V_3 )
return F_1 ( V_3 , V_5 ) ;
return NULL ;
}
static struct V_1 *
F_375 ( struct V_1 * V_323 )
{
struct V_1 * V_21 = F_42 ( sizeof( * V_21 ) , V_56 ) ;
if ( ! V_21 )
return F_123 ( - V_57 ) ;
return V_21 ;
}
static void F_376 ( struct V_1 * V_21 )
{
F_28 ( V_21 ) ;
}
static T_3 F_377 ( struct V_1 * V_21 ,
struct V_20 * V_102 )
{
return F_230 ( V_21 -> V_2 ) ;
}
static T_3 F_378 ( struct V_1 * V_21 ,
struct V_20 * V_102 )
{
return ( T_3 ) ( unsigned long ) V_153 -> V_221 ;
}
static T_3 F_379 ( struct V_1 * V_21 ,
struct V_20 * V_102 )
{
T_3 V_54 ;
F_146 () ;
V_54 = F_231 ( & F_58 ( V_153 ) -> V_30 ) ;
F_147 () ;
return V_54 ;
}
static int F_380 ( struct V_1 * V_21 ,
struct V_20 * V_102 ,
struct V_127 * V_128 )
{
struct V_27 * V_28 ;
struct V_24 * V_25 ;
F_50 ( & V_31 ) ;
F_146 () ;
V_25 = F_381 ( V_153 -> V_221 ) ;
F_54 (link, &cset->cgrp_links, cgrp_link) {
struct V_2 * V_61 = V_28 -> V_3 ;
const char * V_84 ;
if ( V_61 -> V_17 )
V_84 = V_61 -> V_17 -> V_85 . V_84 ;
else
V_84 = L_52 ;
F_102 ( V_128 , L_53 ,
V_61 -> V_50 -> V_167 , V_84 ) ;
}
F_147 () ;
F_51 ( & V_31 ) ;
return 0 ;
}
static int F_382 ( struct V_1 * V_21 ,
struct V_20 * V_102 , struct V_127 * V_128 )
{
struct V_27 * V_28 ;
F_50 ( & V_31 ) ;
F_54 (link, &css->cgroup->cset_links, cset_link) {
struct V_24 * V_25 = V_28 -> V_25 ;
struct V_63 * V_64 ;
int V_54 = 0 ;
F_102 ( V_128 , L_54 , V_25 ) ;
F_54 (task, &cset->tasks, cg_list) {
if ( V_54 ++ > V_471 ) {
F_103 ( V_128 , L_55 ) ;
break;
} else {
F_102 ( V_128 , L_56 ,
F_277 ( V_64 ) ) ;
}
}
}
F_51 ( & V_31 ) ;
return 0 ;
}
static T_3 F_383 ( struct V_1 * V_21 , struct V_20 * V_102 )
{
return F_5 ( V_15 , & V_21 -> V_2 -> V_11 ) ;
}
