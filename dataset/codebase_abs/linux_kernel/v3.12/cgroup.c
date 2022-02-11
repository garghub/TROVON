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
F_74 ( & V_3 -> V_89 ) ;
}
static void F_75 ( struct V_17 * V_17 , struct V_68 * V_68 )
{
if ( F_76 ( V_68 -> V_73 ) ) {
struct V_2 * V_3 = V_17 -> V_18 ;
F_35 ( ! ( F_4 ( V_3 ) ) ) ;
F_77 ( & V_3 -> V_37 , F_72 ) ;
} else {
struct V_19 * V_94 = F_10 ( V_17 ) ;
struct V_2 * V_3 = V_17 -> V_95 -> V_18 ;
F_78 ( ! F_25 ( & V_94 -> V_96 ) &&
V_3 != & V_3 -> V_50 -> V_67 ,
L_1 , V_94 -> type -> V_84 ) ;
F_70 ( & V_94 -> V_92 ) ;
F_28 ( V_94 ) ;
}
F_79 ( V_68 ) ;
}
static int F_80 ( const struct V_17 * V_97 )
{
return 1 ;
}
static void F_81 ( struct V_17 * V_97 )
{
struct V_17 * V_13 = F_82 ( V_97 -> V_95 ) ;
F_83 ( V_97 ) ;
F_84 ( V_13 -> V_98 , V_97 ) ;
F_68 ( V_13 ) ;
}
static void F_85 ( struct V_2 * V_3 , const struct V_20 * V_99 )
{
struct V_19 * V_94 ;
F_49 ( & V_3 -> V_17 -> V_98 -> V_100 ) ;
F_49 ( & V_8 ) ;
F_54 (cfe, &cgrp->files, node) {
struct V_17 * V_97 = V_94 -> V_17 ;
if ( V_99 && V_94 -> type != V_99 )
continue;
F_82 ( V_97 ) ;
F_83 ( V_97 ) ;
F_86 ( V_3 -> V_17 -> V_98 , V_97 ) ;
F_87 ( & V_94 -> V_96 ) ;
F_68 ( V_97 ) ;
break;
}
}
static void F_88 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_4 * V_5 ;
int V_23 ;
F_16 (ss, i) {
struct V_101 * V_102 ;
if ( ! F_5 ( V_23 , & V_52 ) )
continue;
F_54 (set, &ss->cftsets, node)
F_89 ( V_3 , V_102 -> V_103 , false ) ;
}
}
static void F_90 ( struct V_17 * V_17 )
{
struct V_17 * V_13 ;
V_13 = V_17 -> V_95 ;
F_91 ( & V_13 -> V_104 ) ;
F_92 ( & V_17 -> V_104 , V_105 ) ;
F_87 ( & V_17 -> V_106 . V_107 ) ;
F_93 ( & V_17 -> V_104 ) ;
F_93 ( & V_13 -> V_104 ) ;
F_81 ( V_17 ) ;
}
static int F_94 ( struct V_51 * V_50 ,
unsigned long V_108 , unsigned V_109 )
{
struct V_2 * V_3 = & V_50 -> V_67 ;
struct V_4 * V_5 ;
unsigned long V_110 = 0 ;
int V_23 , V_111 ;
F_35 ( ! F_57 ( & V_8 ) ) ;
F_35 ( ! F_57 ( & V_112 ) ) ;
F_16 (ss, i) {
if ( ! ( V_108 & ( 1 << V_23 ) ) )
continue;
if ( V_5 -> V_50 != & V_113 ) {
V_111 = - V_114 ;
goto V_115;
}
if ( ! F_95 ( V_5 -> V_116 ) ) {
V_111 = - V_117 ;
goto V_115;
}
V_110 |= 1 << V_23 ;
}
if ( V_108 != V_110 ) {
V_111 = - V_117 ;
goto V_115;
}
V_111 = F_96 ( V_3 , V_108 ) ;
if ( V_111 )
goto V_115;
F_88 ( V_3 , V_109 ) ;
F_16 (ss, i) {
unsigned long V_118 = 1UL << V_23 ;
if ( V_118 & V_108 ) {
F_35 ( F_1 ( V_3 , V_5 ) ) ;
F_35 ( ! F_1 ( V_119 , V_5 ) ) ;
F_35 ( F_1 ( V_119 , V_5 ) -> V_2 != V_119 ) ;
F_97 ( V_3 -> V_6 [ V_23 ] ,
F_1 ( V_119 , V_5 ) ) ;
F_1 ( V_3 , V_5 ) -> V_2 = V_3 ;
F_46 ( & V_5 -> V_120 , & V_50 -> V_121 ) ;
V_5 -> V_50 = V_50 ;
if ( V_5 -> V_122 )
V_5 -> V_122 ( F_1 ( V_3 , V_5 ) ) ;
V_50 -> V_52 |= V_118 ;
} else if ( V_118 & V_109 ) {
F_35 ( F_1 ( V_3 , V_5 ) != F_1 ( V_119 , V_5 ) ) ;
F_35 ( F_1 ( V_3 , V_5 ) -> V_2 != V_3 ) ;
if ( V_5 -> V_122 )
V_5 -> V_122 ( F_1 ( V_119 , V_5 ) ) ;
F_1 ( V_119 , V_5 ) -> V_2 = V_119 ;
F_98 ( V_3 -> V_6 [ V_23 ] , NULL ) ;
V_4 [ V_23 ] -> V_50 = & V_113 ;
F_46 ( & V_5 -> V_120 , & V_113 . V_121 ) ;
F_99 ( V_5 -> V_116 ) ;
V_50 -> V_52 &= ~ V_118 ;
}
}
V_50 -> V_11 |= V_123 ;
return 0 ;
V_115:
F_16 (ss, i)
if ( V_110 & ( 1 << V_23 ) )
F_99 ( V_5 -> V_116 ) ;
return V_111 ;
}
static int F_100 ( struct V_124 * V_125 , struct V_17 * V_17 )
{
struct V_51 * V_50 = V_17 -> V_126 -> V_127 ;
struct V_4 * V_5 ;
F_13 ( & V_112 ) ;
F_101 (root, ss)
F_102 ( V_125 , L_2 , V_5 -> V_84 ) ;
if ( V_50 -> V_11 & V_128 )
F_103 ( V_125 , L_3 ) ;
if ( V_50 -> V_11 & V_129 )
F_103 ( V_125 , L_4 ) ;
if ( V_50 -> V_11 & V_130 )
F_103 ( V_125 , L_5 ) ;
if ( strlen ( V_50 -> V_131 ) )
F_102 ( V_125 , L_6 , V_50 -> V_131 ) ;
if ( F_5 ( V_132 , & V_50 -> V_67 . V_11 ) )
F_103 ( V_125 , L_7 ) ;
if ( strlen ( V_50 -> V_84 ) )
F_102 ( V_125 , L_8 , V_50 -> V_84 ) ;
F_14 ( & V_112 ) ;
return 0 ;
}
static int F_104 ( char * V_133 , struct V_134 * V_135 )
{
char * V_136 , * V_137 = V_133 ;
bool V_138 = false , V_139 = false ;
unsigned long V_140 = ( unsigned long ) - 1 ;
struct V_4 * V_5 ;
int V_23 ;
F_35 ( ! F_57 ( & V_8 ) ) ;
#ifdef F_105
V_140 = ~ ( 1UL << V_141 ) ;
#endif
memset ( V_135 , 0 , sizeof( * V_135 ) ) ;
while ( ( V_136 = F_106 ( & V_137 , L_9 ) ) != NULL ) {
if ( ! * V_136 )
return - V_142 ;
if ( ! strcmp ( V_136 , L_10 ) ) {
V_135 -> V_143 = true ;
continue;
}
if ( ! strcmp ( V_136 , L_11 ) ) {
if ( V_139 )
return - V_142 ;
V_138 = true ;
continue;
}
if ( ! strcmp ( V_136 , L_12 ) ) {
V_135 -> V_11 |= V_128 ;
continue;
}
if ( ! strcmp ( V_136 , L_13 ) ) {
V_135 -> V_11 |= V_129 ;
continue;
}
if ( ! strcmp ( V_136 , L_14 ) ) {
V_135 -> V_144 = true ;
continue;
}
if ( ! strcmp ( V_136 , L_15 ) ) {
V_135 -> V_11 |= V_130 ;
continue;
}
if ( ! strncmp ( V_136 , L_16 , 14 ) ) {
if ( V_135 -> V_145 )
return - V_142 ;
V_135 -> V_145 =
F_107 ( V_136 + 14 , V_146 - 1 , V_56 ) ;
if ( ! V_135 -> V_145 )
return - V_57 ;
continue;
}
if ( ! strncmp ( V_136 , L_17 , 5 ) ) {
const char * V_84 = V_136 + 5 ;
if ( ! strlen ( V_84 ) )
return - V_142 ;
for ( V_23 = 0 ; V_23 < strlen ( V_84 ) ; V_23 ++ ) {
char V_61 = V_84 [ V_23 ] ;
if ( isalnum ( V_61 ) )
continue;
if ( ( V_61 == '.' ) || ( V_61 == '-' ) || ( V_61 == '_' ) )
continue;
return - V_142 ;
}
if ( V_135 -> V_84 )
return - V_142 ;
V_135 -> V_84 = F_107 ( V_84 ,
V_147 - 1 ,
V_56 ) ;
if ( ! V_135 -> V_84 )
return - V_57 ;
continue;
}
F_16 (ss, i) {
if ( strcmp ( V_136 , V_5 -> V_84 ) )
continue;
if ( V_5 -> V_148 )
continue;
if ( V_138 )
return - V_142 ;
F_26 ( V_23 , & V_135 -> V_52 ) ;
V_139 = true ;
break;
}
if ( V_23 == V_58 )
return - V_117 ;
}
if ( V_138 || ( ! V_139 && ! V_135 -> V_143 && ! V_135 -> V_84 ) )
F_16 (ss, i)
if ( ! V_5 -> V_148 )
F_26 ( V_23 , & V_135 -> V_52 ) ;
if ( V_135 -> V_11 & V_128 ) {
F_108 ( L_18 ) ;
if ( V_135 -> V_11 & V_129 ) {
F_109 ( L_19 ) ;
return - V_142 ;
}
if ( V_135 -> V_144 ) {
F_109 ( L_20 ) ;
return - V_142 ;
}
}
if ( ( V_135 -> V_11 & V_129 ) && ( V_135 -> V_52 & V_140 ) )
return - V_142 ;
if ( V_135 -> V_52 && V_135 -> V_143 )
return - V_142 ;
if ( ! V_135 -> V_52 && ! V_135 -> V_84 )
return - V_142 ;
return 0 ;
}
static int F_110 ( struct V_70 * V_71 , int * V_11 , char * V_133 )
{
int V_111 = 0 ;
struct V_51 * V_50 = V_71 -> V_127 ;
struct V_2 * V_3 = & V_50 -> V_67 ;
struct V_134 V_135 ;
unsigned long V_108 , V_109 ;
if ( V_50 -> V_11 & V_128 ) {
F_109 ( L_21 ) ;
return - V_142 ;
}
F_13 ( & V_3 -> V_17 -> V_98 -> V_100 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_112 ) ;
V_111 = F_104 ( V_133 , & V_135 ) ;
if ( V_111 )
goto V_149;
if ( V_135 . V_52 != V_50 -> V_52 || V_135 . V_145 )
F_108 ( L_22 ,
F_111 ( V_150 ) , V_150 -> V_151 ) ;
V_108 = V_135 . V_52 & ~ V_50 -> V_52 ;
V_109 = V_50 -> V_52 & ~ V_135 . V_52 ;
if ( ( ( V_135 . V_11 ^ V_50 -> V_11 ) & V_152 ) ||
( V_135 . V_84 && strcmp ( V_135 . V_84 , V_50 -> V_84 ) ) ) {
F_109 ( L_23 ,
V_135 . V_11 & V_152 , V_135 . V_84 ? : L_24 ,
V_50 -> V_11 & V_152 , V_50 -> V_84 ) ;
V_111 = - V_142 ;
goto V_149;
}
if ( V_50 -> V_90 > 1 ) {
V_111 = - V_114 ;
goto V_149;
}
V_111 = F_94 ( V_50 , V_108 , V_109 ) ;
if ( V_111 )
goto V_149;
if ( V_135 . V_145 )
strcpy ( V_50 -> V_131 , V_135 . V_145 ) ;
V_149:
F_28 ( V_135 . V_145 ) ;
F_28 ( V_135 . V_84 ) ;
F_14 ( & V_112 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_3 -> V_17 -> V_98 -> V_100 ) ;
return V_111 ;
}
static void F_112 ( struct V_2 * V_3 )
{
F_41 ( & V_3 -> V_120 ) ;
F_41 ( & V_3 -> V_153 ) ;
F_41 ( & V_3 -> V_154 ) ;
F_41 ( & V_3 -> V_36 ) ;
F_41 ( & V_3 -> V_155 ) ;
F_41 ( & V_3 -> V_91 ) ;
F_113 ( & V_3 -> V_156 ) ;
V_3 -> V_9 . V_2 = V_3 ;
F_41 ( & V_3 -> V_157 ) ;
F_114 ( & V_3 -> V_158 ) ;
F_115 ( & V_3 -> V_92 ) ;
}
static void F_116 ( struct V_51 * V_50 )
{
struct V_2 * V_3 = & V_50 -> V_67 ;
F_41 ( & V_50 -> V_121 ) ;
F_41 ( & V_50 -> V_159 ) ;
V_50 -> V_90 = 1 ;
V_3 -> V_50 = V_50 ;
F_98 ( V_3 -> V_84 , & V_160 ) ;
F_112 ( V_3 ) ;
F_117 ( & V_50 -> V_161 ) ;
}
static int F_118 ( struct V_51 * V_50 , int V_162 , int V_163 )
{
int V_164 ;
F_49 ( & V_8 ) ;
F_49 ( & V_112 ) ;
V_164 = F_119 ( & V_165 , V_50 , V_162 , V_163 ,
V_56 ) ;
if ( V_164 < 0 )
return V_164 ;
V_50 -> V_166 = V_164 ;
return 0 ;
}
static void F_120 ( struct V_51 * V_50 )
{
F_49 ( & V_8 ) ;
F_49 ( & V_112 ) ;
if ( V_50 -> V_166 ) {
F_121 ( & V_165 , V_50 -> V_166 ) ;
V_50 -> V_166 = 0 ;
}
}
static int F_122 ( struct V_70 * V_71 , void * V_133 )
{
struct V_134 * V_135 = V_133 ;
struct V_51 * V_50 = V_71 -> V_127 ;
if ( V_135 -> V_84 && strcmp ( V_135 -> V_84 , V_50 -> V_84 ) )
return 0 ;
if ( ( V_135 -> V_52 || V_135 -> V_143 )
&& ( V_135 -> V_52 != V_50 -> V_52 ) )
return 0 ;
return 1 ;
}
static struct V_51 * F_123 ( struct V_134 * V_135 )
{
struct V_51 * V_50 ;
if ( ! V_135 -> V_52 && ! V_135 -> V_143 )
return NULL ;
V_50 = F_42 ( sizeof( * V_50 ) , V_56 ) ;
if ( ! V_50 )
return F_124 ( - V_57 ) ;
F_116 ( V_50 ) ;
V_50 -> V_52 = V_135 -> V_52 ;
V_50 -> V_11 = V_135 -> V_11 ;
if ( V_135 -> V_145 )
strcpy ( V_50 -> V_131 , V_135 -> V_145 ) ;
if ( V_135 -> V_84 )
strcpy ( V_50 -> V_84 , V_135 -> V_84 ) ;
if ( V_135 -> V_144 )
F_26 ( V_132 , & V_50 -> V_67 . V_11 ) ;
return V_50 ;
}
static void F_125 ( struct V_51 * V_50 )
{
if ( V_50 ) {
F_126 ( V_50 -> V_166 ) ;
F_127 ( & V_50 -> V_161 ) ;
F_28 ( V_50 ) ;
}
}
static int F_128 ( struct V_70 * V_71 , void * V_133 )
{
int V_111 ;
struct V_134 * V_135 = V_133 ;
if ( ! V_135 -> V_167 )
return - V_142 ;
F_35 ( ! V_135 -> V_52 && ! V_135 -> V_143 ) ;
V_111 = F_129 ( V_71 , NULL ) ;
if ( V_111 )
return V_111 ;
V_71 -> V_127 = V_135 -> V_167 ;
V_135 -> V_167 -> V_71 = V_71 ;
V_71 -> V_168 = V_169 ;
V_71 -> V_170 = V_171 ;
V_71 -> V_172 = V_173 ;
V_71 -> V_174 = & V_175 ;
return 0 ;
}
static int F_130 ( struct V_70 * V_71 )
{
static const struct V_176 V_177 = {
. V_178 = F_75 ,
. F_83 = F_80 ,
} ;
struct V_68 * V_68 =
F_59 ( V_179 | V_180 | V_181 | V_182 , V_71 ) ;
if ( ! V_68 )
return - V_57 ;
V_68 -> V_183 = & V_184 ;
V_68 -> V_185 = & V_186 ;
F_131 ( V_68 ) ;
V_71 -> V_187 = F_132 ( V_68 ) ;
if ( ! V_71 -> V_187 )
return - V_57 ;
V_71 -> V_188 = & V_177 ;
return 0 ;
}
static struct V_17 * F_133 ( struct V_189 * V_190 ,
int V_11 , const char * V_191 ,
void * V_133 )
{
struct V_134 V_135 ;
struct V_51 * V_50 ;
int V_111 = 0 ;
struct V_70 * V_71 ;
struct V_51 * V_167 ;
struct V_41 V_55 ;
struct V_68 * V_68 ;
const struct V_192 * V_192 ;
F_13 ( & V_8 ) ;
V_111 = F_104 ( V_133 , & V_135 ) ;
F_14 ( & V_8 ) ;
if ( V_111 )
goto V_193;
V_167 = F_123 ( & V_135 ) ;
if ( F_134 ( V_167 ) ) {
V_111 = F_135 ( V_167 ) ;
goto V_193;
}
V_135 . V_167 = V_167 ;
V_71 = F_136 ( V_190 , F_122 , F_128 , 0 , & V_135 ) ;
if ( F_134 ( V_71 ) ) {
V_111 = F_135 ( V_71 ) ;
F_125 ( V_135 . V_167 ) ;
goto V_193;
}
V_50 = V_71 -> V_127 ;
F_35 ( ! V_50 ) ;
if ( V_50 == V_135 . V_167 ) {
struct V_2 * V_194 = & V_50 -> V_67 ;
struct V_51 * V_195 ;
int V_23 ;
struct V_24 * V_25 ;
F_35 ( V_71 -> V_187 != NULL ) ;
V_111 = F_130 ( V_71 ) ;
if ( V_111 )
goto V_196;
V_68 = V_71 -> V_187 -> V_98 ;
F_13 ( & V_68 -> V_100 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_112 ) ;
V_194 -> V_164 = F_137 ( & V_50 -> V_161 , V_194 ,
0 , 1 , V_56 ) ;
if ( V_194 -> V_164 < 0 )
goto V_197;
V_111 = - V_114 ;
if ( strlen ( V_50 -> V_84 ) )
F_138 (existing_root)
if ( ! strcmp ( V_195 -> V_84 , V_50 -> V_84 ) )
goto V_197;
V_111 = F_40 ( V_33 , & V_55 ) ;
if ( V_111 )
goto V_197;
V_111 = F_118 ( V_50 , 2 , 0 ) ;
if ( V_111 )
goto V_197;
V_71 -> V_187 -> V_18 = V_194 ;
V_194 -> V_17 = V_71 -> V_187 ;
V_192 = F_139 ( & V_198 ) ;
V_111 = F_89 ( V_194 , V_199 , true ) ;
if ( V_111 )
goto V_200;
V_111 = F_94 ( V_50 , V_50 -> V_52 , 0 ) ;
if ( V_111 )
goto V_200;
F_140 ( V_192 ) ;
F_43 ( & V_50 -> V_159 , & V_201 ) ;
V_59 ++ ;
F_19 ( & V_31 ) ;
F_141 (css_set_table, i, cset, hlist)
F_44 ( & V_55 , V_25 , V_194 ) ;
F_21 ( & V_31 ) ;
F_39 ( & V_55 ) ;
F_35 ( ! F_25 ( & V_194 -> V_153 ) ) ;
F_35 ( V_50 -> V_90 != 1 ) ;
F_14 ( & V_112 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_68 -> V_100 ) ;
} else {
F_125 ( V_135 . V_167 ) ;
if ( ( V_50 -> V_11 ^ V_135 . V_11 ) & V_152 ) {
if ( ( V_50 -> V_11 | V_135 . V_11 ) & V_128 ) {
F_109 ( L_25 ) ;
V_111 = - V_142 ;
goto V_196;
} else {
F_108 ( L_26 ) ;
}
}
}
F_28 ( V_135 . V_145 ) ;
F_28 ( V_135 . V_84 ) ;
return F_82 ( V_71 -> V_187 ) ;
V_200:
F_39 ( & V_55 ) ;
F_89 ( & V_50 -> V_67 , V_199 , false ) ;
F_140 ( V_192 ) ;
V_197:
F_120 ( V_50 ) ;
F_14 ( & V_112 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_68 -> V_100 ) ;
V_196:
F_142 ( V_71 ) ;
V_193:
F_28 ( V_135 . V_145 ) ;
F_28 ( V_135 . V_84 ) ;
return F_124 ( V_111 ) ;
}
static void F_143 ( struct V_70 * V_71 ) {
struct V_51 * V_50 = V_71 -> V_127 ;
struct V_2 * V_3 = & V_50 -> V_67 ;
struct V_27 * V_28 , * V_29 ;
int V_111 ;
F_35 ( ! V_50 ) ;
F_35 ( V_50 -> V_90 != 1 ) ;
F_35 ( ! F_25 ( & V_3 -> V_153 ) ) ;
F_13 ( & V_3 -> V_17 -> V_98 -> V_100 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_112 ) ;
if ( V_50 -> V_11 & V_123 ) {
V_111 = F_94 ( V_50 , 0 , V_50 -> V_52 ) ;
F_35 ( V_111 ) ;
}
F_19 ( & V_31 ) ;
F_23 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_24 ( & V_28 -> V_34 ) ;
F_24 ( & V_28 -> V_35 ) ;
F_28 ( V_28 ) ;
}
F_21 ( & V_31 ) ;
if ( ! F_25 ( & V_50 -> V_159 ) ) {
F_24 ( & V_50 -> V_159 ) ;
V_59 -- ;
}
F_120 ( V_50 ) ;
F_14 ( & V_112 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_3 -> V_17 -> V_98 -> V_100 ) ;
F_70 ( & V_3 -> V_92 ) ;
F_144 ( V_71 ) ;
F_125 ( V_50 ) ;
}
int F_145 ( const struct V_2 * V_3 , char * V_202 , int V_203 )
{
int V_111 = - V_204 ;
char * V_162 ;
if ( ! V_3 -> V_13 ) {
if ( F_146 ( V_202 , L_27 , V_203 ) >= V_203 )
return - V_204 ;
return 0 ;
}
V_162 = V_202 + V_203 - 1 ;
* V_162 = '\0' ;
F_147 () ;
do {
const char * V_84 = V_83 ( V_3 ) ;
int V_86 ;
V_86 = strlen ( V_84 ) ;
if ( ( V_162 -= V_86 ) < V_202 )
goto V_205;
memcpy ( V_162 , V_84 , V_86 ) ;
if ( -- V_162 < V_202 )
goto V_205;
* V_162 = '/' ;
V_3 = V_3 -> V_13 ;
} while ( V_3 -> V_13 );
V_111 = 0 ;
memmove ( V_202 , V_162 , V_202 + V_203 - V_162 ) ;
V_205:
F_148 () ;
return V_111 ;
}
int F_149 ( struct V_63 * V_64 , char * V_202 , T_2 V_203 )
{
struct V_51 * V_50 ;
struct V_2 * V_3 ;
int V_166 = 1 , V_111 = 0 ;
if ( V_203 < 2 )
return - V_204 ;
F_13 ( & V_8 ) ;
V_50 = F_150 ( & V_165 , & V_166 ) ;
if ( V_50 ) {
V_3 = F_56 ( V_64 , V_50 ) ;
V_111 = F_145 ( V_3 , V_202 , V_203 ) ;
} else {
memcpy ( V_202 , L_27 , 2 ) ;
}
F_14 ( & V_8 ) ;
return V_111 ;
}
struct V_63 * F_151 ( struct V_206 * V_207 )
{
if ( V_207 -> V_208 ) {
V_207 -> V_209 = 0 ;
return F_152 ( V_207 ) ;
} else {
V_207 -> V_210 = V_207 -> V_211 . V_3 ;
return V_207 -> V_211 . V_64 ;
}
}
struct V_63 * F_152 ( struct V_206 * V_207 )
{
struct V_212 * V_213 ;
if ( ! V_207 -> V_208 || V_207 -> V_209 >= V_207 -> V_214 )
return NULL ;
V_213 = F_153 ( V_207 -> V_208 , V_207 -> V_209 ++ ) ;
V_207 -> V_210 = V_213 -> V_3 ;
return V_213 -> V_64 ;
}
struct V_1 * F_154 ( struct V_206 * V_207 ,
int V_7 )
{
return F_1 ( V_207 -> V_210 , V_4 [ V_7 ] ) ;
}
int F_155 ( struct V_206 * V_207 )
{
return V_207 -> V_208 ? V_207 -> V_214 : 1 ;
}
static void F_156 ( struct V_2 * V_215 ,
struct V_63 * V_216 ,
struct V_24 * V_217 )
{
struct V_24 * V_38 ;
F_126 ( V_216 -> V_11 & V_218 ) ;
V_38 = F_58 ( V_216 ) ;
F_157 ( V_216 ) ;
F_97 ( V_216 -> V_219 , V_217 ) ;
F_158 ( V_216 ) ;
F_19 ( & V_31 ) ;
if ( ! F_25 ( & V_216 -> V_220 ) )
F_46 ( & V_216 -> V_220 , & V_217 -> V_60 ) ;
F_21 ( & V_31 ) ;
F_26 ( V_15 , & V_215 -> V_11 ) ;
F_32 ( V_38 ) ;
}
static int F_159 ( struct V_2 * V_3 , struct V_63 * V_216 ,
bool V_221 )
{
int V_222 , V_23 , V_223 ;
struct V_4 * V_5 , * V_224 = NULL ;
struct V_51 * V_50 = V_3 -> V_50 ;
struct V_63 * V_225 = V_216 ;
struct V_212 * V_213 ;
struct V_226 * V_227 ;
struct V_206 V_207 = { } ;
if ( V_221 )
V_223 = F_160 ( V_216 ) ;
else
V_223 = 1 ;
V_227 = F_161 ( sizeof( * V_213 ) , V_223 , V_56 ) ;
if ( ! V_227 )
return - V_57 ;
V_222 = F_162 ( V_227 , 0 , V_223 , V_56 ) ;
if ( V_222 )
goto V_228;
V_23 = 0 ;
F_147 () ;
do {
struct V_212 V_229 ;
if ( V_216 -> V_11 & V_218 )
goto V_49;
F_35 ( V_23 >= V_223 ) ;
V_229 . V_64 = V_216 ;
V_229 . V_3 = F_56 ( V_216 , V_50 ) ;
if ( V_229 . V_3 == V_3 )
goto V_49;
V_222 = F_163 ( V_227 , V_23 , & V_229 , V_230 ) ;
F_35 ( V_222 != 0 ) ;
V_23 ++ ;
V_49:
if ( ! V_221 )
break;
} while_each_thread(leader, tsk) ;
int F_164 ( struct V_2 * V_3 , T_3 V_231 , bool V_221 )
{
struct V_63 * V_216 ;
const struct V_192 * V_192 = F_165 () , * V_232 ;
int V_111 ;
if ( ! F_12 ( V_3 ) )
return - V_233 ;
V_234:
F_147 () ;
if ( V_231 ) {
V_216 = F_166 ( V_231 ) ;
if ( ! V_216 ) {
F_148 () ;
V_111 = - V_235 ;
goto V_236;
}
V_232 = F_167 ( V_216 ) ;
if ( ! F_168 ( V_192 -> V_237 , V_238 ) &&
! F_168 ( V_192 -> V_237 , V_232 -> V_239 ) &&
! F_168 ( V_192 -> V_237 , V_232 -> V_240 ) ) {
F_148 () ;
V_111 = - V_241 ;
goto V_236;
}
} else
V_216 = V_150 ;
if ( V_221 )
V_216 = V_216 -> V_242 ;
if ( V_216 == V_243 || ( V_216 -> V_11 & V_244 ) ) {
V_111 = - V_142 ;
F_148 () ;
goto V_236;
}
F_169 ( V_216 ) ;
F_148 () ;
F_170 ( V_216 ) ;
if ( V_221 ) {
if ( ! F_171 ( V_216 ) ) {
F_172 ( V_216 ) ;
F_173 ( V_216 ) ;
goto V_234;
}
}
V_111 = F_159 ( V_3 , V_216 , V_221 ) ;
F_172 ( V_216 ) ;
F_173 ( V_216 ) ;
V_236:
F_14 ( & V_8 ) ;
return V_111 ;
}
int F_174 ( struct V_63 * V_245 , struct V_63 * V_216 )
{
struct V_51 * V_50 ;
int V_222 = 0 ;
F_13 ( & V_8 ) ;
F_138 (root) {
struct V_2 * V_246 = F_56 ( V_245 , V_50 ) ;
V_222 = F_159 ( V_246 , V_216 , false ) ;
if ( V_222 )
break;
}
F_14 ( & V_8 ) ;
return V_222 ;
}
static int F_175 ( struct V_1 * V_21 ,
struct V_20 * V_99 , T_3 V_231 )
{
return F_164 ( V_21 -> V_2 , V_231 , false ) ;
}
static int F_176 ( struct V_1 * V_21 ,
struct V_20 * V_99 , T_3 V_247 )
{
return F_164 ( V_21 -> V_2 , V_247 , true ) ;
}
static int F_177 ( struct V_1 * V_21 ,
struct V_20 * V_99 , const char * V_248 )
{
F_178 ( sizeof( V_21 -> V_2 -> V_50 -> V_131 ) < V_146 ) ;
if ( strlen ( V_248 ) >= V_146 )
return - V_142 ;
if ( ! F_12 ( V_21 -> V_2 ) )
return - V_233 ;
F_13 ( & V_112 ) ;
strcpy ( V_21 -> V_2 -> V_50 -> V_131 , V_248 ) ;
F_14 ( & V_112 ) ;
F_14 ( & V_8 ) ;
return 0 ;
}
static int F_179 ( struct V_1 * V_21 ,
struct V_20 * V_99 , struct V_124 * V_125 )
{
struct V_2 * V_3 = V_21 -> V_2 ;
if ( ! F_12 ( V_3 ) )
return - V_233 ;
F_103 ( V_125 , V_3 -> V_50 -> V_131 ) ;
F_180 ( V_125 , '\n' ) ;
F_14 ( & V_8 ) ;
return 0 ;
}
static int F_181 ( struct V_1 * V_21 ,
struct V_20 * V_99 , struct V_124 * V_125 )
{
F_102 ( V_125 , L_28 , F_182 ( V_21 -> V_2 ) ) ;
return 0 ;
}
static T_4 F_183 ( struct V_1 * V_21 ,
struct V_20 * V_99 , struct V_249 * V_249 ,
const char T_5 * V_250 , T_2 V_251 ,
T_6 * V_252 )
{
char V_248 [ V_253 ] ;
int V_222 = 0 ;
char * V_163 ;
if ( ! V_251 )
return - V_142 ;
if ( V_251 >= sizeof( V_248 ) )
return - V_254 ;
if ( F_184 ( V_248 , V_250 , V_251 ) )
return - V_255 ;
V_248 [ V_251 ] = 0 ;
if ( V_99 -> V_256 ) {
T_3 V_257 = F_185 ( F_186 ( V_248 ) , & V_163 , 0 ) ;
if ( * V_163 )
return - V_142 ;
V_222 = V_99 -> V_256 ( V_21 , V_99 , V_257 ) ;
} else {
T_7 V_257 = F_187 ( F_186 ( V_248 ) , & V_163 , 0 ) ;
if ( * V_163 )
return - V_142 ;
V_222 = V_99 -> V_258 ( V_21 , V_99 , V_257 ) ;
}
if ( ! V_222 )
V_222 = V_251 ;
return V_222 ;
}
static T_4 F_188 ( struct V_1 * V_21 ,
struct V_20 * V_99 , struct V_249 * V_249 ,
const char T_5 * V_250 , T_2 V_251 ,
T_6 * V_252 )
{
char V_259 [ V_253 ] ;
int V_222 = 0 ;
T_2 V_260 = V_99 -> V_261 ;
char * V_248 = V_259 ;
if ( ! V_260 )
V_260 = sizeof( V_259 ) - 1 ;
if ( V_251 >= V_260 )
return - V_254 ;
if ( V_251 >= sizeof( V_259 ) ) {
V_248 = F_65 ( V_251 + 1 , V_56 ) ;
if ( V_248 == NULL )
return - V_57 ;
}
if ( V_251 && F_184 ( V_248 , V_250 , V_251 ) ) {
V_222 = - V_255 ;
goto V_205;
}
V_248 [ V_251 ] = 0 ;
V_222 = V_99 -> V_262 ( V_21 , V_99 , F_186 ( V_248 ) ) ;
if ( ! V_222 )
V_222 = V_251 ;
V_205:
if ( V_248 != V_259 )
F_28 ( V_248 ) ;
return V_222 ;
}
static T_4 F_189 ( struct V_249 * V_249 , const char T_5 * V_202 ,
T_2 V_251 , T_6 * V_263 )
{
struct V_19 * V_94 = F_10 ( V_249 -> V_264 ) ;
struct V_20 * V_99 = F_11 ( V_249 -> V_264 ) ;
struct V_1 * V_21 = V_94 -> V_21 ;
if ( V_99 -> V_265 )
return V_99 -> V_265 ( V_21 , V_99 , V_249 , V_202 , V_251 , V_263 ) ;
if ( V_99 -> V_256 || V_99 -> V_258 )
return F_183 ( V_21 , V_99 , V_249 , V_202 , V_251 , V_263 ) ;
if ( V_99 -> V_262 )
return F_188 ( V_21 , V_99 , V_249 , V_202 , V_251 , V_263 ) ;
if ( V_99 -> V_266 ) {
int V_111 = V_99 -> V_266 ( V_21 , ( unsigned int ) V_99 -> V_267 ) ;
return V_111 ? V_111 : V_251 ;
}
return - V_142 ;
}
static T_4 F_190 ( struct V_1 * V_21 ,
struct V_20 * V_99 , struct V_249 * V_249 ,
char T_5 * V_202 , T_2 V_251 , T_6 * V_263 )
{
char V_268 [ V_253 ] ;
T_3 V_257 = V_99 -> V_269 ( V_21 , V_99 ) ;
int V_86 = sprintf ( V_268 , L_29 , ( unsigned long long ) V_257 ) ;
return F_191 ( V_202 , V_251 , V_263 , V_268 , V_86 ) ;
}
static T_4 F_192 ( struct V_1 * V_21 ,
struct V_20 * V_99 , struct V_249 * V_249 ,
char T_5 * V_202 , T_2 V_251 , T_6 * V_263 )
{
char V_268 [ V_253 ] ;
T_7 V_257 = V_99 -> V_270 ( V_21 , V_99 ) ;
int V_86 = sprintf ( V_268 , L_30 , ( long long ) V_257 ) ;
return F_191 ( V_202 , V_251 , V_263 , V_268 , V_86 ) ;
}
static T_4 F_193 ( struct V_249 * V_249 , char T_5 * V_202 ,
T_2 V_251 , T_6 * V_263 )
{
struct V_19 * V_94 = F_10 ( V_249 -> V_264 ) ;
struct V_20 * V_99 = F_11 ( V_249 -> V_264 ) ;
struct V_1 * V_21 = V_94 -> V_21 ;
if ( V_99 -> V_271 )
return V_99 -> V_271 ( V_21 , V_99 , V_249 , V_202 , V_251 , V_263 ) ;
if ( V_99 -> V_269 )
return F_190 ( V_21 , V_99 , V_249 , V_202 , V_251 , V_263 ) ;
if ( V_99 -> V_270 )
return F_192 ( V_21 , V_99 , V_249 , V_202 , V_251 , V_263 ) ;
return - V_142 ;
}
static int F_194 ( struct V_272 * V_273 , const char * V_22 , T_3 V_274 )
{
struct V_124 * V_275 = V_273 -> V_276 ;
return F_102 ( V_275 , L_31 , V_22 , ( unsigned long long ) V_274 ) ;
}
static int F_195 ( struct V_124 * V_277 , void * V_278 )
{
struct V_19 * V_94 = V_277 -> V_267 ;
struct V_20 * V_99 = V_94 -> type ;
struct V_1 * V_21 = V_94 -> V_21 ;
if ( V_99 -> V_279 ) {
struct V_272 V_273 = {
. V_280 = F_194 ,
. V_276 = V_277 ,
} ;
return V_99 -> V_279 ( V_21 , V_99 , & V_273 ) ;
}
return V_99 -> V_281 ( V_21 , V_99 , V_277 ) ;
}
static int F_196 ( struct V_68 * V_68 , struct V_249 * V_249 )
{
struct V_19 * V_94 = F_10 ( V_249 -> V_264 ) ;
struct V_20 * V_99 = F_11 ( V_249 -> V_264 ) ;
struct V_2 * V_3 = F_9 ( V_94 -> V_17 -> V_95 ) ;
struct V_1 * V_21 ;
int V_282 ;
V_282 = F_197 ( V_68 , V_249 ) ;
if ( V_282 )
return V_282 ;
F_147 () ;
V_21 = F_1 ( V_3 , V_99 -> V_5 ) ;
if ( V_99 -> V_5 && ! F_198 ( V_21 ) )
V_21 = NULL ;
F_148 () ;
if ( ! V_21 )
return - V_233 ;
F_126 ( V_94 -> V_21 && V_94 -> V_21 != V_21 ) ;
V_94 -> V_21 = V_21 ;
if ( V_99 -> V_279 || V_99 -> V_281 ) {
V_249 -> V_283 = & V_284 ;
V_282 = F_199 ( V_249 , F_195 , V_94 ) ;
} else if ( V_99 -> V_285 ) {
V_282 = V_99 -> V_285 ( V_68 , V_249 ) ;
}
if ( V_21 -> V_5 && V_282 )
F_200 ( V_21 ) ;
return V_282 ;
}
static int F_201 ( struct V_68 * V_68 , struct V_249 * V_249 )
{
struct V_19 * V_94 = F_10 ( V_249 -> V_264 ) ;
struct V_20 * V_99 = F_11 ( V_249 -> V_264 ) ;
struct V_1 * V_21 = V_94 -> V_21 ;
int V_111 = 0 ;
if ( V_99 -> V_286 )
V_111 = V_99 -> V_286 ( V_68 , V_249 ) ;
if ( V_21 -> V_5 )
F_200 ( V_21 ) ;
return V_111 ;
}
static int F_202 ( struct V_68 * V_287 , struct V_17 * V_288 ,
struct V_68 * V_289 , struct V_17 * V_290 )
{
int V_111 ;
struct V_83 * V_84 , * V_291 ;
struct V_2 * V_3 ;
F_49 ( & V_287 -> V_100 ) ;
if ( ! F_76 ( V_288 -> V_98 -> V_73 ) )
return - V_292 ;
if ( V_290 -> V_98 )
return - V_293 ;
if ( V_287 != V_289 )
return - V_294 ;
V_3 = F_9 ( V_288 ) ;
if ( F_182 ( V_3 ) )
return - V_295 ;
V_84 = F_64 ( V_290 ) ;
if ( ! V_84 )
return - V_57 ;
V_111 = F_203 ( V_287 , V_288 , V_289 , V_290 ) ;
if ( V_111 ) {
F_28 ( V_84 ) ;
return V_111 ;
}
V_291 = F_204 ( V_3 -> V_84 , true ) ;
F_97 ( V_3 -> V_84 , V_84 ) ;
F_29 ( V_291 , V_37 ) ;
return 0 ;
}
static struct V_296 * F_205 ( struct V_17 * V_17 )
{
if ( F_76 ( V_17 -> V_98 -> V_73 ) )
return & F_9 ( V_17 ) -> V_92 ;
else
return & F_10 ( V_17 ) -> V_92 ;
}
static inline int F_206 ( struct V_17 * V_17 )
{
struct V_51 * V_50 = V_17 -> V_126 -> V_127 ;
return V_50 -> V_11 & V_130 ;
}
static bool F_207 ( const char * V_84 )
{
if ( ! strncmp ( V_84 , V_297 , V_298 ) ||
! strncmp ( V_84 , V_299 , V_300 ) )
return true ;
return false ;
}
static int F_208 ( struct V_17 * V_17 , const char * V_84 ,
const void * V_257 , T_2 V_301 , int V_11 )
{
if ( ! F_206 ( V_17 ) )
return - V_302 ;
if ( ! F_207 ( V_84 ) )
return - V_142 ;
return F_209 ( F_205 ( V_17 ) , V_84 , V_257 , V_301 , V_11 ) ;
}
static int F_210 ( struct V_17 * V_17 , const char * V_84 )
{
if ( ! F_206 ( V_17 ) )
return - V_302 ;
if ( ! F_207 ( V_84 ) )
return - V_142 ;
return F_211 ( F_205 ( V_17 ) , V_84 ) ;
}
static T_4 F_212 ( struct V_17 * V_17 , const char * V_84 ,
void * V_202 , T_2 V_301 )
{
if ( ! F_206 ( V_17 ) )
return - V_302 ;
if ( ! F_207 ( V_84 ) )
return - V_142 ;
return F_213 ( F_205 ( V_17 ) , V_84 , V_202 , V_301 ) ;
}
static T_4 F_214 ( struct V_17 * V_17 , char * V_202 , T_2 V_301 )
{
if ( ! F_206 ( V_17 ) )
return - V_302 ;
return F_215 ( F_205 ( V_17 ) , V_202 , V_301 ) ;
}
static inline struct V_20 * F_216 ( struct V_249 * V_249 )
{
if ( F_217 ( V_249 ) -> V_183 != & V_303 )
return F_124 ( - V_142 ) ;
return F_11 ( V_249 -> V_264 ) ;
}
static int F_218 ( struct V_17 * V_17 , T_1 V_69 ,
struct V_70 * V_71 )
{
struct V_68 * V_68 ;
if ( ! V_17 )
return - V_117 ;
if ( V_17 -> V_98 )
return - V_293 ;
V_68 = F_59 ( V_69 , V_71 ) ;
if ( ! V_68 )
return - V_57 ;
if ( F_76 ( V_69 ) ) {
V_68 -> V_185 = & V_186 ;
V_68 -> V_183 = & V_184 ;
F_131 ( V_68 ) ;
F_131 ( V_17 -> V_95 -> V_98 ) ;
F_126 ( ! F_219 ( & V_68 -> V_100 ) ) ;
} else if ( F_220 ( V_69 ) ) {
V_68 -> V_304 = 0 ;
V_68 -> V_183 = & V_303 ;
V_68 -> V_185 = & V_305 ;
}
F_221 ( V_17 , V_68 ) ;
F_82 ( V_17 ) ;
return 0 ;
}
static T_1 F_222 ( const struct V_20 * V_99 )
{
T_1 V_69 = 0 ;
if ( V_99 -> V_69 )
return V_99 -> V_69 ;
if ( V_99 -> V_271 || V_99 -> V_269 || V_99 -> V_270 ||
V_99 -> V_279 || V_99 -> V_281 )
V_69 |= V_180 ;
if ( V_99 -> V_265 || V_99 -> V_256 || V_99 -> V_258 ||
V_99 -> V_262 || V_99 -> V_266 )
V_69 |= V_182 ;
return V_69 ;
}
static int F_223 ( struct V_2 * V_3 , struct V_20 * V_99 )
{
struct V_17 * V_306 = V_3 -> V_17 ;
struct V_2 * V_13 = F_9 ( V_306 ) ;
struct V_17 * V_17 ;
struct V_19 * V_94 ;
int error ;
T_1 V_69 ;
char V_84 [ V_307 + V_308 + 2 ] = { 0 } ;
if ( V_99 -> V_5 && ! ( V_99 -> V_11 & V_309 ) &&
! ( V_3 -> V_50 -> V_11 & V_129 ) ) {
strcpy ( V_84 , V_99 -> V_5 -> V_84 ) ;
strcat ( V_84 , L_32 ) ;
}
strcat ( V_84 , V_99 -> V_84 ) ;
F_35 ( ! F_57 ( & V_306 -> V_98 -> V_100 ) ) ;
V_94 = F_42 ( sizeof( * V_94 ) , V_56 ) ;
if ( ! V_94 )
return - V_57 ;
V_17 = F_224 ( V_84 , V_306 , strlen ( V_84 ) ) ;
if ( F_134 ( V_17 ) ) {
error = F_135 ( V_17 ) ;
goto V_205;
}
V_94 -> type = ( void * ) V_99 ;
V_94 -> V_17 = V_17 ;
V_17 -> V_18 = V_94 ;
F_115 ( & V_94 -> V_92 ) ;
V_69 = F_222 ( V_99 ) ;
error = F_218 ( V_17 , V_69 | V_310 , V_3 -> V_50 -> V_71 ) ;
if ( ! error ) {
F_47 ( & V_94 -> V_96 , & V_13 -> V_154 ) ;
V_94 = NULL ;
}
F_68 ( V_17 ) ;
V_205:
F_28 ( V_94 ) ;
return error ;
}
static int F_89 ( struct V_2 * V_3 , struct V_20 V_103 [] ,
bool V_311 )
{
struct V_20 * V_99 ;
int V_111 ;
F_49 ( & V_3 -> V_17 -> V_98 -> V_100 ) ;
F_49 ( & V_8 ) ;
for ( V_99 = V_103 ; V_99 -> V_84 [ 0 ] != '\0' ; V_99 ++ ) {
if ( ( V_99 -> V_11 & V_312 ) && F_182 ( V_3 ) )
continue;
if ( ( V_99 -> V_11 & V_313 ) && ! V_3 -> V_13 )
continue;
if ( ( V_99 -> V_11 & V_314 ) && V_3 -> V_13 )
continue;
if ( V_311 ) {
V_111 = F_223 ( V_3 , V_99 ) ;
if ( V_111 ) {
F_225 ( L_33 ,
V_99 -> V_84 , V_111 ) ;
return V_111 ;
}
} else {
F_85 ( V_3 , V_99 ) ;
}
}
return 0 ;
}
static void F_226 ( void )
__acquires( &cgroup_mutex
static int F_227 ( struct V_20 * V_103 , bool V_311 )
__releases( &cgroup_mutex
int F_228 ( struct V_4 * V_5 , struct V_20 * V_103 )
{
struct V_101 * V_102 ;
struct V_20 * V_99 ;
int V_111 ;
V_102 = F_42 ( sizeof( * V_102 ) , V_56 ) ;
if ( ! V_102 )
return - V_57 ;
for ( V_99 = V_103 ; V_99 -> V_84 [ 0 ] != '\0' ; V_99 ++ )
V_99 -> V_5 = V_5 ;
F_226 () ;
V_102 -> V_103 = V_103 ;
F_47 ( & V_102 -> V_96 , & V_5 -> V_315 ) ;
V_111 = F_227 ( V_103 , true ) ;
if ( V_111 )
F_229 ( V_103 ) ;
return V_111 ;
}
int F_229 ( struct V_20 * V_103 )
{
struct V_101 * V_102 ;
if ( ! V_103 || ! V_103 [ 0 ] . V_5 )
return - V_117 ;
F_226 () ;
F_54 (set, &cfts[0].ss->cftsets, node) {
if ( V_102 -> V_103 == V_103 ) {
F_24 ( & V_102 -> V_96 ) ;
F_28 ( V_102 ) ;
F_227 ( V_103 , false ) ;
return 0 ;
}
}
F_227 ( NULL , false ) ;
return - V_117 ;
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
struct V_63 * V_316 , * V_317 ;
F_19 ( & V_31 ) ;
V_318 = 1 ;
F_50 ( & V_319 ) ;
F_233 (g, p) {
F_157 ( V_316 ) ;
if ( ! ( V_316 -> V_11 & V_218 ) && F_25 ( & V_316 -> V_220 ) )
F_43 ( & V_316 -> V_220 , & F_58 ( V_316 ) -> V_60 ) ;
F_158 ( V_316 ) ;
} F_234 ( V_317 , V_316 ) ;
F_51 ( & V_319 ) ;
F_21 ( & V_31 ) ;
}
struct V_1 *
F_235 ( struct V_1 * V_320 ,
struct V_1 * V_321 )
{
struct V_2 * V_322 = V_320 ? V_320 -> V_2 : NULL ;
struct V_2 * V_3 = V_321 -> V_2 ;
struct V_2 * V_49 ;
F_126 ( ! F_236 () ) ;
if ( ! V_322 ) {
V_49 = F_237 ( V_3 -> V_153 . V_49 , struct V_2 , V_120 ) ;
} else if ( F_238 ( ! F_4 ( V_322 ) ) ) {
V_49 = F_237 ( V_322 -> V_120 . V_49 , struct V_2 , V_120 ) ;
} else {
F_239 (next, &cgrp->children, sibling)
if ( V_49 -> V_323 > V_322 -> V_323 )
break;
}
if ( & V_49 -> V_120 == & V_3 -> V_153 )
return NULL ;
return F_1 ( V_49 , V_321 -> V_5 ) ;
}
struct V_1 *
F_240 ( struct V_1 * V_322 ,
struct V_1 * V_50 )
{
struct V_1 * V_49 ;
F_126 ( ! F_236 () ) ;
if ( ! V_322 )
return V_50 ;
V_49 = F_235 ( NULL , V_322 ) ;
if ( V_49 )
return V_49 ;
while ( V_322 != V_50 ) {
V_49 = F_235 ( V_322 , F_241 ( V_322 ) ) ;
if ( V_49 )
return V_49 ;
V_322 = F_241 ( V_322 ) ;
}
return NULL ;
}
struct V_1 *
F_242 ( struct V_1 * V_322 )
{
struct V_1 * V_324 , * V_268 ;
F_126 ( ! F_236 () ) ;
do {
V_324 = V_322 ;
V_322 = NULL ;
F_243 (tmp, last)
V_322 = V_268 ;
} while ( V_322 );
return V_324 ;
}
static struct V_1 *
F_244 ( struct V_1 * V_322 )
{
struct V_1 * V_324 ;
do {
V_324 = V_322 ;
V_322 = F_235 ( NULL , V_322 ) ;
} while ( V_322 );
return V_324 ;
}
struct V_1 *
F_245 ( struct V_1 * V_322 ,
struct V_1 * V_50 )
{
struct V_1 * V_49 ;
F_126 ( ! F_236 () ) ;
if ( ! V_322 )
return F_244 ( V_50 ) ;
if ( V_322 == V_50 )
return NULL ;
V_49 = F_235 ( V_322 , F_241 ( V_322 ) ) ;
if ( V_49 )
return F_244 ( V_49 ) ;
return F_241 ( V_322 ) ;
}
static void F_246 ( struct V_325 * V_326 )
{
struct V_41 * V_327 = V_326 -> V_34 ;
struct V_27 * V_28 ;
struct V_24 * V_25 ;
do {
V_327 = V_327 -> V_49 ;
if ( V_327 == & V_326 -> V_328 -> V_2 -> V_36 ) {
V_326 -> V_34 = NULL ;
return;
}
V_28 = F_36 ( V_327 , struct V_27 , V_34 ) ;
V_25 = V_28 -> V_25 ;
} while ( F_25 ( & V_25 -> V_60 ) );
V_326 -> V_34 = V_327 ;
V_326 -> V_64 = V_25 -> V_60 . V_49 ;
}
void F_247 ( struct V_1 * V_21 ,
struct V_325 * V_326 )
__acquires( V_31 )
{
if ( ! V_318 )
F_232 () ;
F_50 ( & V_31 ) ;
V_326 -> V_328 = V_21 ;
V_326 -> V_34 = & V_21 -> V_2 -> V_36 ;
F_246 ( V_326 ) ;
}
struct V_63 * F_248 ( struct V_325 * V_326 )
{
struct V_63 * V_65 ;
struct V_41 * V_327 = V_326 -> V_64 ;
struct V_27 * V_28 ;
if ( ! V_326 -> V_34 )
return NULL ;
V_65 = F_36 ( V_327 , struct V_63 , V_220 ) ;
V_327 = V_327 -> V_49 ;
V_28 = F_36 ( V_326 -> V_34 , struct V_27 , V_34 ) ;
if ( V_327 == & V_28 -> V_25 -> V_60 ) {
F_246 ( V_326 ) ;
} else {
V_326 -> V_64 = V_327 ;
}
return V_65 ;
}
void F_249 ( struct V_325 * V_326 )
__releases( V_31 )
{
F_51 ( & V_31 ) ;
}
static inline int F_250 ( struct V_63 * V_329 ,
struct V_330 * time ,
struct V_63 * V_331 )
{
int V_332 = F_251 ( & V_329 -> V_333 , time ) ;
if ( V_332 > 0 ) {
return 1 ;
} else if ( V_332 < 0 ) {
return 0 ;
} else {
return V_329 > V_331 ;
}
}
static inline int F_252 ( void * V_334 , void * V_335 )
{
struct V_63 * V_329 = V_334 ;
struct V_63 * V_331 = V_335 ;
return F_250 ( V_329 , & V_331 -> V_333 , V_331 ) ;
}
int F_253 ( struct V_1 * V_21 ,
bool (* F_254)( struct V_63 * , void * ) ,
void (* F_255)( struct V_63 * , void * ) ,
void * V_133 , struct V_336 * V_337 )
{
int V_222 , V_23 ;
struct V_325 V_326 ;
struct V_63 * V_316 , * V_338 ;
struct V_63 * V_339 = NULL ;
struct V_336 V_340 ;
struct V_330 V_341 = { 0 , 0 } ;
if ( V_337 ) {
V_337 -> V_342 = & F_252 ;
} else {
V_337 = & V_340 ;
V_222 = F_256 ( V_337 , V_343 , V_56 , & F_252 ) ;
if ( V_222 )
return V_222 ;
}
V_344:
V_337 -> V_301 = 0 ;
F_247 ( V_21 , & V_326 ) ;
while ( ( V_316 = F_248 ( & V_326 ) ) ) {
if ( F_254 && ! F_254 ( V_316 , V_133 ) )
continue;
if ( ! F_250 ( V_316 , & V_341 , V_339 ) )
continue;
V_338 = F_257 ( V_337 , V_316 ) ;
if ( V_338 == NULL ) {
F_169 ( V_316 ) ;
} else if ( V_338 != V_316 ) {
F_169 ( V_316 ) ;
F_173 ( V_338 ) ;
}
}
F_249 ( & V_326 ) ;
if ( V_337 -> V_301 ) {
for ( V_23 = 0 ; V_23 < V_337 -> V_301 ; V_23 ++ ) {
struct V_63 * V_345 = V_337 -> V_346 [ V_23 ] ;
if ( V_23 == 0 ) {
V_341 = V_345 -> V_333 ;
V_339 = V_345 ;
}
F_255 ( V_345 , V_133 ) ;
F_173 ( V_345 ) ;
}
goto V_344;
}
if ( V_337 == & V_340 )
F_258 ( & V_340 ) ;
return 0 ;
}
static void F_259 ( struct V_63 * V_64 , void * V_133 )
{
struct V_2 * V_347 = V_133 ;
F_13 ( & V_8 ) ;
F_159 ( V_347 , V_64 , false ) ;
F_14 ( & V_8 ) ;
}
int F_260 ( struct V_2 * V_348 , struct V_2 * V_245 )
{
return F_253 ( & V_245 -> V_9 , NULL , F_259 ,
V_348 , NULL ) ;
}
static void * F_261 ( int V_54 )
{
if ( F_262 ( V_54 ) )
return F_263 ( V_54 * sizeof( V_349 ) ) ;
else
return F_65 ( V_54 * sizeof( V_349 ) , V_56 ) ;
}
static void F_264 ( void * V_316 )
{
if ( F_265 ( V_316 ) )
F_266 ( V_316 ) ;
else
F_28 ( V_316 ) ;
}
static int F_267 ( V_349 * V_350 , int V_351 )
{
int V_352 , V_353 = 1 ;
if ( V_351 == 0 || V_351 == 1 )
return V_351 ;
for ( V_352 = 1 ; V_352 < V_351 ; V_352 ++ ) {
while ( V_350 [ V_352 ] == V_350 [ V_352 - 1 ] ) {
V_352 ++ ;
if ( V_352 == V_351 )
goto V_354;
}
V_350 [ V_353 ] = V_350 [ V_352 ] ;
V_353 ++ ;
}
V_354:
return V_353 ;
}
static int F_268 ( const void * V_355 , const void * V_356 )
{
return * ( V_349 * ) V_355 - * ( V_349 * ) V_356 ;
}
static struct V_357 * F_269 ( struct V_2 * V_3 ,
enum V_358 type )
{
struct V_357 * V_327 ;
struct V_359 * V_360 = F_270 ( V_150 ) ;
F_13 ( & V_3 -> V_156 ) ;
F_54 (l, &cgrp->pidlists, links) {
if ( V_327 -> V_22 . type == type && V_327 -> V_22 . V_360 == V_360 ) {
F_271 ( & V_327 -> V_361 ) ;
F_14 ( & V_3 -> V_156 ) ;
return V_327 ;
}
}
V_327 = F_42 ( sizeof( struct V_357 ) , V_56 ) ;
if ( ! V_327 ) {
F_14 ( & V_3 -> V_156 ) ;
return V_327 ;
}
F_272 ( & V_327 -> V_361 ) ;
F_271 ( & V_327 -> V_361 ) ;
V_327 -> V_22 . type = type ;
V_327 -> V_22 . V_360 = F_273 ( V_360 ) ;
V_327 -> V_362 = V_3 ;
F_43 ( & V_327 -> V_363 , & V_3 -> V_91 ) ;
F_14 ( & V_3 -> V_156 ) ;
return V_327 ;
}
static int F_274 ( struct V_2 * V_3 , enum V_358 type ,
struct V_357 * * V_364 )
{
V_349 * V_365 ;
int V_351 ;
int V_231 , V_366 = 0 ;
struct V_325 V_326 ;
struct V_63 * V_216 ;
struct V_357 * V_327 ;
V_351 = F_230 ( V_3 ) ;
V_365 = F_261 ( V_351 ) ;
if ( ! V_365 )
return - V_57 ;
F_247 ( & V_3 -> V_9 , & V_326 ) ;
while ( ( V_216 = F_248 ( & V_326 ) ) ) {
if ( F_275 ( V_366 == V_351 ) )
break;
if ( type == V_367 )
V_231 = F_276 ( V_216 ) ;
else
V_231 = F_277 ( V_216 ) ;
if ( V_231 > 0 )
V_365 [ V_366 ++ ] = V_231 ;
}
F_249 ( & V_326 ) ;
V_351 = V_366 ;
F_278 ( V_365 , V_351 , sizeof( V_349 ) , F_268 , NULL ) ;
if ( type == V_367 )
V_351 = F_267 ( V_365 , V_351 ) ;
V_327 = F_269 ( V_3 , type ) ;
if ( ! V_327 ) {
F_264 ( V_365 ) ;
return - V_57 ;
}
F_264 ( V_327 -> V_350 ) ;
V_327 -> V_350 = V_365 ;
V_327 -> V_351 = V_351 ;
V_327 -> V_368 ++ ;
F_279 ( & V_327 -> V_361 ) ;
* V_364 = V_327 ;
return 0 ;
}
int F_280 ( struct V_369 * V_370 , struct V_17 * V_17 )
{
int V_111 = - V_142 ;
struct V_2 * V_3 ;
struct V_325 V_326 ;
struct V_63 * V_216 ;
if ( V_17 -> V_126 -> V_174 != & V_175 ||
! F_76 ( V_17 -> V_98 -> V_73 ) )
goto V_282;
V_111 = 0 ;
V_3 = V_17 -> V_18 ;
F_247 ( & V_3 -> V_9 , & V_326 ) ;
while ( ( V_216 = F_248 ( & V_326 ) ) ) {
switch ( V_216 -> V_276 ) {
case V_371 :
V_370 -> V_372 ++ ;
break;
case V_373 :
V_370 -> V_374 ++ ;
break;
case V_375 :
V_370 -> V_376 ++ ;
break;
case V_377 :
V_370 -> V_378 ++ ;
break;
default:
if ( F_281 ( V_216 ) )
V_370 -> V_379 ++ ;
break;
}
}
F_249 ( & V_326 ) ;
V_282:
return V_111 ;
}
static void * F_282 ( struct V_124 * V_380 , T_6 * V_322 )
{
struct V_357 * V_327 = V_380 -> V_267 ;
int V_381 = 0 , V_231 = * V_322 ;
int * V_382 ;
F_283 ( & V_327 -> V_361 ) ;
if ( V_231 ) {
int V_163 = V_327 -> V_351 ;
while ( V_381 < V_163 ) {
int V_383 = ( V_381 + V_163 ) / 2 ;
if ( V_327 -> V_350 [ V_383 ] == V_231 ) {
V_381 = V_383 ;
break;
} else if ( V_327 -> V_350 [ V_383 ] <= V_231 )
V_381 = V_383 + 1 ;
else
V_163 = V_383 ;
}
}
if ( V_381 >= V_327 -> V_351 )
return NULL ;
V_382 = V_327 -> V_350 + V_381 ;
* V_322 = * V_382 ;
return V_382 ;
}
static void F_284 ( struct V_124 * V_380 , void * V_384 )
{
struct V_357 * V_327 = V_380 -> V_267 ;
F_285 ( & V_327 -> V_361 ) ;
}
static void * F_286 ( struct V_124 * V_380 , void * V_384 , T_6 * V_322 )
{
struct V_357 * V_327 = V_380 -> V_267 ;
V_349 * V_316 = V_384 ;
V_349 * V_163 = V_327 -> V_350 + V_327 -> V_351 ;
V_316 ++ ;
if ( V_316 >= V_163 ) {
return NULL ;
} else {
* V_322 = * V_316 ;
return V_316 ;
}
}
static int F_287 ( struct V_124 * V_380 , void * V_384 )
{
return F_102 ( V_380 , L_28 , * ( int * ) V_384 ) ;
}
static void F_288 ( struct V_357 * V_327 )
{
F_13 ( & V_327 -> V_362 -> V_156 ) ;
F_271 ( & V_327 -> V_361 ) ;
F_35 ( ! V_327 -> V_368 ) ;
if ( ! -- V_327 -> V_368 ) {
F_24 ( & V_327 -> V_363 ) ;
F_14 ( & V_327 -> V_362 -> V_156 ) ;
F_264 ( V_327 -> V_350 ) ;
F_289 ( V_327 -> V_22 . V_360 ) ;
F_279 ( & V_327 -> V_361 ) ;
F_28 ( V_327 ) ;
return;
}
F_14 ( & V_327 -> V_362 -> V_156 ) ;
F_279 ( & V_327 -> V_361 ) ;
}
static int F_290 ( struct V_68 * V_68 , struct V_249 * V_249 )
{
struct V_357 * V_327 ;
if ( ! ( V_249 -> V_385 & V_386 ) )
return 0 ;
V_327 = ( (struct V_124 * ) V_249 -> V_387 ) -> V_267 ;
F_288 ( V_327 ) ;
return F_291 ( V_68 , V_249 ) ;
}
static int F_292 ( struct V_249 * V_249 , enum V_358 type )
{
struct V_2 * V_3 = F_9 ( V_249 -> V_264 -> V_95 ) ;
struct V_357 * V_327 ;
int V_222 ;
if ( ! ( V_249 -> V_385 & V_386 ) )
return 0 ;
V_222 = F_274 ( V_3 , type , & V_327 ) ;
if ( V_222 )
return V_222 ;
V_249 -> V_283 = & V_388 ;
V_222 = F_293 ( V_249 , & V_389 ) ;
if ( V_222 ) {
F_288 ( V_327 ) ;
return V_222 ;
}
( (struct V_124 * ) V_249 -> V_387 ) -> V_267 = V_327 ;
return 0 ;
}
static int F_294 ( struct V_68 * V_390 , struct V_249 * V_249 )
{
return F_292 ( V_249 , V_391 ) ;
}
static int F_295 ( struct V_68 * V_390 , struct V_249 * V_249 )
{
return F_292 ( V_249 , V_367 ) ;
}
static T_3 F_296 ( struct V_1 * V_21 ,
struct V_20 * V_99 )
{
return F_8 ( V_21 -> V_2 ) ;
}
static int F_297 ( struct V_1 * V_21 ,
struct V_20 * V_99 , T_3 V_257 )
{
F_298 ( V_15 , & V_21 -> V_2 -> V_11 ) ;
if ( V_257 )
F_26 ( V_16 , & V_21 -> V_2 -> V_11 ) ;
else
F_298 ( V_16 , & V_21 -> V_2 -> V_11 ) ;
return 0 ;
}
static void F_299 ( struct V_2 * V_3 )
{
struct V_70 * V_71 = V_3 -> V_50 -> V_71 ;
F_31 ( & V_71 -> V_392 ) ;
F_68 ( V_3 -> V_17 ) ;
F_69 ( V_71 ) ;
}
static void F_300 ( struct V_87 * V_88 )
{
struct V_393 * V_394 = F_67 ( V_88 , struct V_393 ,
remove ) ;
struct V_1 * V_21 = V_394 -> V_21 ;
F_301 ( V_394 -> V_395 , & V_394 -> V_396 ) ;
V_394 -> V_99 -> V_397 ( V_21 , V_394 -> V_99 , V_394 -> V_398 ) ;
F_302 ( V_394 -> V_398 , 1 ) ;
F_303 ( V_394 -> V_398 ) ;
F_28 ( V_394 ) ;
F_200 ( V_21 ) ;
}
static int F_304 ( T_8 * V_396 , unsigned V_69 ,
int V_399 , void * V_22 )
{
struct V_393 * V_394 = F_67 ( V_396 ,
struct V_393 , V_396 ) ;
struct V_2 * V_3 = V_394 -> V_21 -> V_2 ;
unsigned long V_11 = ( unsigned long ) V_22 ;
if ( V_11 & V_400 ) {
F_91 ( & V_3 -> V_158 ) ;
if ( ! F_25 ( & V_394 -> V_350 ) ) {
F_87 ( & V_394 -> V_350 ) ;
F_74 ( & V_394 -> remove ) ;
}
F_93 ( & V_3 -> V_158 ) ;
}
return 0 ;
}
static void F_305 ( struct V_249 * V_249 ,
T_9 * V_395 , T_10 * V_401 )
{
struct V_393 * V_394 = F_67 ( V_401 ,
struct V_393 , V_401 ) ;
V_394 -> V_395 = V_395 ;
F_306 ( V_395 , & V_394 -> V_396 ) ;
}
static int F_307 ( struct V_1 * V_9 ,
struct V_20 * V_99 , const char * V_248 )
{
struct V_2 * V_3 = V_9 -> V_2 ;
struct V_393 * V_394 ;
struct V_1 * V_402 ;
unsigned int V_403 , V_404 ;
struct V_405 V_406 ;
struct V_405 V_407 ;
char * V_408 ;
int V_111 ;
V_403 = F_308 ( V_248 , & V_408 , 10 ) ;
if ( * V_408 != ' ' )
return - V_142 ;
V_248 = V_408 + 1 ;
V_404 = F_308 ( V_248 , & V_408 , 10 ) ;
if ( ( * V_408 != ' ' ) && ( * V_408 != '\0' ) )
return - V_142 ;
V_248 = V_408 + 1 ;
V_394 = F_42 ( sizeof( * V_394 ) , V_56 ) ;
if ( ! V_394 )
return - V_57 ;
F_41 ( & V_394 -> V_350 ) ;
F_309 ( & V_394 -> V_401 , F_305 ) ;
F_310 ( & V_394 -> V_396 , F_304 ) ;
F_73 ( & V_394 -> remove , F_300 ) ;
V_406 = F_311 ( V_403 ) ;
if ( ! V_406 . V_249 ) {
V_111 = - V_409 ;
goto V_410;
}
V_394 -> V_398 = F_312 ( V_406 . V_249 ) ;
if ( F_134 ( V_394 -> V_398 ) ) {
V_111 = F_135 ( V_394 -> V_398 ) ;
goto V_411;
}
V_407 = F_311 ( V_404 ) ;
if ( ! V_407 . V_249 ) {
V_111 = - V_409 ;
goto V_412;
}
V_111 = F_313 ( F_217 ( V_407 . V_249 ) , V_413 ) ;
if ( V_111 < 0 )
goto V_414;
V_394 -> V_99 = F_216 ( V_407 . V_249 ) ;
if ( F_134 ( V_394 -> V_99 ) ) {
V_111 = F_135 ( V_394 -> V_99 ) ;
goto V_414;
}
if ( ! V_394 -> V_99 -> V_5 ) {
V_111 = - V_409 ;
goto V_414;
}
F_147 () ;
V_111 = - V_142 ;
V_394 -> V_21 = F_1 ( V_3 , V_394 -> V_99 -> V_5 ) ;
V_402 = F_314 ( V_407 . V_249 -> V_264 -> V_95 , V_394 -> V_99 -> V_5 ) ;
if ( V_394 -> V_21 && V_394 -> V_21 == V_402 && F_198 ( V_394 -> V_21 ) )
V_111 = 0 ;
F_148 () ;
if ( V_111 )
goto V_414;
if ( ! V_394 -> V_99 -> V_415 || ! V_394 -> V_99 -> V_397 ) {
V_111 = - V_142 ;
goto V_416;
}
V_111 = V_394 -> V_99 -> V_415 ( V_394 -> V_21 , V_394 -> V_99 ,
V_394 -> V_398 , V_248 ) ;
if ( V_111 )
goto V_416;
V_406 . V_249 -> V_283 -> V_417 ( V_406 . V_249 , & V_394 -> V_401 ) ;
F_91 ( & V_3 -> V_158 ) ;
F_43 ( & V_394 -> V_350 , & V_3 -> V_157 ) ;
F_93 ( & V_3 -> V_158 ) ;
F_315 ( V_407 ) ;
F_315 ( V_406 ) ;
return 0 ;
V_416:
F_200 ( V_394 -> V_21 ) ;
V_414:
F_315 ( V_407 ) ;
V_412:
F_303 ( V_394 -> V_398 ) ;
V_411:
F_315 ( V_406 ) ;
V_410:
F_28 ( V_394 ) ;
return V_111 ;
}
static T_3 F_316 ( struct V_1 * V_21 ,
struct V_20 * V_99 )
{
return F_5 ( V_132 , & V_21 -> V_2 -> V_11 ) ;
}
static int F_317 ( struct V_1 * V_21 ,
struct V_20 * V_99 , T_3 V_257 )
{
if ( V_257 )
F_26 ( V_132 , & V_21 -> V_2 -> V_11 ) ;
else
F_298 ( V_132 , & V_21 -> V_2 -> V_11 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_4 * V_5 ;
int V_23 , V_111 = 0 ;
F_16 (ss, i) {
struct V_101 * V_102 ;
if ( ! F_5 ( V_23 , & V_52 ) )
continue;
F_54 (set, &ss->cftsets, node) {
V_111 = F_89 ( V_3 , V_102 -> V_103 , true ) ;
if ( V_111 < 0 )
goto V_282;
}
}
F_101 (cgrp->root, ss) {
struct V_1 * V_21 = F_1 ( V_3 , V_5 ) ;
struct V_418 * V_164 = F_204 ( V_21 -> V_164 , true ) ;
if ( V_164 )
F_97 ( V_164 -> V_21 , V_21 ) ;
}
return 0 ;
V_282:
F_88 ( V_3 , V_52 ) ;
return V_111 ;
}
static void F_318 ( struct V_87 * V_88 )
{
struct V_1 * V_21 =
F_67 ( V_88 , struct V_1 , V_89 ) ;
struct V_2 * V_3 = V_21 -> V_2 ;
if ( V_21 -> V_13 )
F_200 ( V_21 -> V_13 ) ;
V_21 -> V_5 -> V_419 ( V_21 ) ;
F_299 ( V_3 ) ;
}
static void F_319 ( struct V_37 * V_37 )
{
struct V_1 * V_21 =
F_67 ( V_37 , struct V_1 , V_37 ) ;
F_73 ( & V_21 -> V_89 , F_318 ) ;
F_74 ( & V_21 -> V_89 ) ;
}
static void F_320 ( struct V_420 * V_421 )
{
struct V_1 * V_21 =
F_67 ( V_421 , struct V_1 , V_422 ) ;
F_77 ( & V_21 -> V_37 , F_319 ) ;
}
static void F_321 ( struct V_1 * V_21 , struct V_4 * V_5 ,
struct V_2 * V_3 )
{
V_21 -> V_2 = V_3 ;
V_21 -> V_5 = V_5 ;
V_21 -> V_11 = 0 ;
V_21 -> V_164 = NULL ;
if ( V_3 -> V_13 )
V_21 -> V_13 = F_1 ( V_3 -> V_13 , V_5 ) ;
else
V_21 -> V_11 |= V_423 ;
F_35 ( F_1 ( V_3 , V_5 ) ) ;
}
static int F_322 ( struct V_1 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
int V_111 = 0 ;
F_49 ( & V_8 ) ;
if ( V_5 -> V_424 )
V_111 = V_5 -> V_424 ( V_21 ) ;
if ( ! V_111 ) {
V_21 -> V_11 |= V_425 ;
V_21 -> V_2 -> V_426 ++ ;
F_97 ( V_21 -> V_2 -> V_6 [ V_5 -> V_7 ] , V_21 ) ;
}
return V_111 ;
}
static void F_323 ( struct V_1 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
F_49 ( & V_8 ) ;
if ( ! ( V_21 -> V_11 & V_425 ) )
return;
if ( V_5 -> V_427 )
V_5 -> V_427 ( V_21 ) ;
V_21 -> V_11 &= ~ V_425 ;
V_21 -> V_2 -> V_426 -- ;
F_98 ( V_21 -> V_2 -> V_6 [ V_5 -> V_7 ] , V_21 ) ;
}
static long F_324 ( struct V_2 * V_13 , struct V_17 * V_17 ,
T_1 V_69 )
{
struct V_1 * V_428 [ V_58 ] = { } ;
struct V_2 * V_3 ;
struct V_83 * V_84 ;
struct V_51 * V_50 = V_13 -> V_50 ;
int V_282 = 0 ;
struct V_4 * V_5 ;
struct V_70 * V_71 = V_50 -> V_71 ;
V_3 = F_42 ( sizeof( * V_3 ) , V_56 ) ;
if ( ! V_3 )
return - V_57 ;
V_84 = F_64 ( V_17 ) ;
if ( ! V_84 )
goto V_429;
F_97 ( V_3 -> V_84 , V_84 ) ;
V_3 -> V_164 = F_137 ( & V_50 -> V_161 , NULL , 1 , 0 , V_56 ) ;
if ( V_3 -> V_164 < 0 )
goto V_430;
if ( ! F_12 ( V_13 ) ) {
V_282 = - V_233 ;
goto V_431;
}
F_31 ( & V_71 -> V_392 ) ;
F_112 ( V_3 ) ;
V_17 -> V_18 = V_3 ;
V_3 -> V_17 = V_17 ;
V_3 -> V_13 = V_13 ;
V_3 -> V_9 . V_13 = & V_13 -> V_9 ;
V_3 -> V_50 = V_13 -> V_50 ;
if ( F_8 ( V_13 ) )
F_26 ( V_16 , & V_3 -> V_11 ) ;
if ( F_5 ( V_132 , & V_13 -> V_11 ) )
F_26 ( V_132 , & V_3 -> V_11 ) ;
F_101 (root, ss) {
struct V_1 * V_21 ;
V_21 = V_5 -> V_432 ( F_1 ( V_13 , V_5 ) ) ;
if ( F_134 ( V_21 ) ) {
V_282 = F_135 ( V_21 ) ;
goto V_433;
}
V_428 [ V_5 -> V_7 ] = V_21 ;
V_282 = F_325 ( & V_21 -> V_422 , F_320 ) ;
if ( V_282 )
goto V_433;
F_321 ( V_21 , V_5 , V_3 ) ;
if ( V_5 -> V_434 ) {
V_282 = F_326 ( V_21 ) ;
if ( V_282 )
goto V_433;
}
}
V_282 = F_218 ( V_17 , V_179 | V_69 , V_71 ) ;
if ( V_282 < 0 )
goto V_433;
F_49 ( & V_17 -> V_98 -> V_100 ) ;
V_3 -> V_323 = V_435 ++ ;
F_327 ( & V_3 -> V_120 , & V_3 -> V_13 -> V_153 ) ;
V_50 -> V_90 ++ ;
F_101 (root, ss) {
struct V_1 * V_21 = V_428 [ V_5 -> V_7 ] ;
F_82 ( V_17 ) ;
F_328 ( V_21 -> V_13 ) ;
}
F_82 ( V_13 -> V_17 ) ;
F_101 (root, ss) {
struct V_1 * V_21 = V_428 [ V_5 -> V_7 ] ;
V_282 = F_322 ( V_21 ) ;
if ( V_282 )
goto V_436;
if ( V_5 -> V_437 && ! V_5 -> V_438 &&
V_13 -> V_13 ) {
F_108 ( L_34 ,
V_150 -> V_151 , V_150 -> V_231 , V_5 -> V_84 ) ;
if ( ! strcmp ( V_5 -> V_84 , L_35 ) )
F_108 ( L_36 ) ;
V_5 -> V_438 = true ;
}
}
F_329 ( & V_50 -> V_161 , V_3 , V_3 -> V_164 ) ;
V_282 = F_89 ( V_3 , V_199 , true ) ;
if ( V_282 )
goto V_436;
V_282 = F_96 ( V_3 , V_50 -> V_52 ) ;
if ( V_282 )
goto V_436;
F_14 ( & V_8 ) ;
F_14 ( & V_3 -> V_17 -> V_98 -> V_100 ) ;
return 0 ;
V_433:
F_101 (root, ss) {
struct V_1 * V_21 = V_428 [ V_5 -> V_7 ] ;
if ( V_21 ) {
F_330 ( & V_21 -> V_422 ) ;
V_5 -> V_419 ( V_21 ) ;
}
}
F_14 ( & V_8 ) ;
F_69 ( V_71 ) ;
V_431:
F_121 ( & V_50 -> V_161 , V_3 -> V_164 ) ;
V_430:
F_28 ( F_71 ( V_3 -> V_84 ) ) ;
V_429:
F_28 ( V_3 ) ;
return V_282 ;
V_436:
F_331 ( V_3 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_17 -> V_98 -> V_100 ) ;
return V_282 ;
}
static int F_332 ( struct V_68 * V_306 , struct V_17 * V_17 , T_1 V_69 )
{
struct V_2 * V_439 = V_17 -> V_95 -> V_18 ;
return F_324 ( V_439 , V_17 , V_69 | V_179 ) ;
}
static void F_333 ( struct V_87 * V_88 )
{
struct V_1 * V_21 =
F_67 ( V_88 , struct V_1 , V_89 ) ;
struct V_2 * V_3 = V_21 -> V_2 ;
F_13 ( & V_8 ) ;
F_323 ( V_21 ) ;
if ( ! V_3 -> V_426 && F_4 ( V_3 ) )
F_334 ( V_3 ) ;
F_14 ( & V_8 ) ;
F_200 ( V_21 ) ;
}
static void F_335 ( struct V_420 * V_421 )
{
struct V_1 * V_21 =
F_67 ( V_421 , struct V_1 , V_422 ) ;
F_73 ( & V_21 -> V_89 , F_333 ) ;
F_74 ( & V_21 -> V_89 ) ;
}
static void F_336 ( struct V_1 * V_21 )
{
F_88 ( V_21 -> V_2 , 1 << V_21 -> V_5 -> V_7 ) ;
F_328 ( V_21 ) ;
F_337 ( & V_21 -> V_422 , F_335 ) ;
}
static int F_331 ( struct V_2 * V_3 )
__releases( &cgroup_mutex
static void F_334 ( struct V_2 * V_3 )
{
struct V_2 * V_13 = V_3 -> V_13 ;
struct V_17 * V_97 = V_3 -> V_17 ;
F_49 ( & V_8 ) ;
F_338 ( & V_3 -> V_120 ) ;
F_121 ( & V_3 -> V_50 -> V_161 , V_3 -> V_164 ) ;
V_3 -> V_164 = - 1 ;
F_68 ( V_97 ) ;
F_26 ( V_15 , & V_13 -> V_11 ) ;
F_27 ( V_13 ) ;
}
static int F_339 ( struct V_68 * V_440 , struct V_17 * V_17 )
{
int V_111 ;
F_13 ( & V_8 ) ;
V_111 = F_331 ( V_17 -> V_18 ) ;
F_14 ( & V_8 ) ;
return V_111 ;
}
static void T_11 F_340 ( struct V_4 * V_5 )
{
F_41 ( & V_5 -> V_315 ) ;
if ( V_5 -> V_441 ) {
struct V_20 * V_99 ;
for ( V_99 = V_5 -> V_441 ; V_99 -> V_84 [ 0 ] != '\0' ; V_99 ++ )
V_99 -> V_5 = V_5 ;
V_5 -> V_442 . V_103 = V_5 -> V_441 ;
F_47 ( & V_5 -> V_442 . V_96 , & V_5 -> V_315 ) ;
}
}
static void T_12 F_341 ( struct V_4 * V_5 )
{
struct V_1 * V_21 ;
F_342 ( V_443 L_37 , V_5 -> V_84 ) ;
F_13 ( & V_8 ) ;
F_340 ( V_5 ) ;
F_43 ( & V_5 -> V_120 , & V_113 . V_121 ) ;
V_5 -> V_50 = & V_113 ;
V_21 = V_5 -> V_432 ( F_1 ( V_119 , V_5 ) ) ;
F_35 ( F_134 ( V_21 ) ) ;
F_321 ( V_21 , V_5 , V_119 ) ;
V_66 . V_6 [ V_5 -> V_7 ] = V_21 ;
V_444 |= V_5 -> V_445 || V_5 -> exit ;
F_35 ( ! F_25 ( & V_446 . V_60 ) ) ;
F_35 ( F_322 ( V_21 ) ) ;
F_14 ( & V_8 ) ;
F_35 ( V_5 -> V_116 ) ;
}
int T_11 F_343 ( struct V_4 * V_5 )
{
struct V_1 * V_21 ;
int V_23 , V_111 ;
struct V_447 * V_268 ;
struct V_24 * V_25 ;
unsigned long V_22 ;
if ( V_5 -> V_84 == NULL || strlen ( V_5 -> V_84 ) > V_307 ||
V_5 -> V_432 == NULL || V_5 -> V_419 == NULL )
return - V_142 ;
if ( V_5 -> V_445 || V_5 -> exit )
return - V_142 ;
if ( V_5 -> V_116 == NULL ) {
F_35 ( V_4 [ V_5 -> V_7 ] != V_5 ) ;
return 0 ;
}
F_340 ( V_5 ) ;
F_13 ( & V_8 ) ;
V_4 [ V_5 -> V_7 ] = V_5 ;
V_21 = V_5 -> V_432 ( F_1 ( V_119 , V_5 ) ) ;
if ( F_134 ( V_21 ) ) {
V_4 [ V_5 -> V_7 ] = NULL ;
F_14 ( & V_8 ) ;
return F_135 ( V_21 ) ;
}
F_43 ( & V_5 -> V_120 , & V_113 . V_121 ) ;
V_5 -> V_50 = & V_113 ;
F_321 ( V_21 , V_5 , V_119 ) ;
if ( V_5 -> V_434 ) {
V_111 = F_344 ( V_5 , V_21 ) ;
if ( V_111 )
goto V_448;
}
F_19 ( & V_31 ) ;
F_345 (css_set_table, i, tmp, cset, hlist) {
if ( V_25 -> V_6 [ V_5 -> V_7 ] )
continue;
F_22 ( & V_25 -> V_32 ) ;
V_25 -> V_6 [ V_5 -> V_7 ] = V_21 ;
V_22 = F_15 ( V_25 -> V_6 ) ;
F_55 ( V_62 , & V_25 -> V_32 , V_22 ) ;
}
F_21 ( & V_31 ) ;
V_111 = F_322 ( V_21 ) ;
if ( V_111 )
goto V_448;
F_14 ( & V_8 ) ;
return 0 ;
V_448:
F_14 ( & V_8 ) ;
F_346 ( V_5 ) ;
return V_111 ;
}
void F_346 ( struct V_4 * V_5 )
{
struct V_27 * V_28 ;
F_35 ( V_5 -> V_116 == NULL ) ;
F_35 ( V_5 -> V_50 != & V_113 ) ;
F_13 ( & V_8 ) ;
F_323 ( F_1 ( V_119 , V_5 ) ) ;
if ( V_5 -> V_434 )
F_127 ( & V_5 -> V_449 ) ;
V_4 [ V_5 -> V_7 ] = NULL ;
F_87 ( & V_5 -> V_120 ) ;
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
V_5 -> V_419 ( F_1 ( V_119 , V_5 ) ) ;
F_98 ( V_119 -> V_6 [ V_5 -> V_7 ] , NULL ) ;
F_14 ( & V_8 ) ;
}
int T_12 F_347 ( void )
{
struct V_4 * V_5 ;
int V_23 ;
F_52 ( & V_66 . V_30 , 1 ) ;
F_41 ( & V_66 . V_44 ) ;
F_41 ( & V_66 . V_60 ) ;
F_53 ( & V_66 . V_32 ) ;
V_33 = 1 ;
F_116 ( & V_113 ) ;
V_59 = 1 ;
F_98 ( V_446 . V_219 , & V_66 ) ;
V_450 . V_25 = & V_66 ;
V_450 . V_3 = V_119 ;
F_43 ( & V_450 . V_34 , & V_119 -> V_36 ) ;
F_43 ( & V_450 . V_35 , & V_66 . V_44 ) ;
F_348 (ss, i) {
F_35 ( ! V_5 -> V_84 ) ;
F_35 ( strlen ( V_5 -> V_84 ) > V_307 ) ;
F_35 ( ! V_5 -> V_432 ) ;
F_35 ( ! V_5 -> V_419 ) ;
if ( V_5 -> V_7 != V_23 ) {
F_342 ( V_451 L_38 ,
V_5 -> V_84 , V_5 -> V_7 ) ;
F_349 () ;
}
if ( V_5 -> V_452 )
F_341 ( V_5 ) ;
}
return 0 ;
}
int T_12 F_350 ( void )
{
struct V_4 * V_5 ;
unsigned long V_22 ;
int V_23 , V_282 ;
V_282 = F_351 ( & V_82 ) ;
if ( V_282 )
return V_282 ;
F_348 (ss, i) {
if ( ! V_5 -> V_452 )
F_341 ( V_5 ) ;
if ( V_5 -> V_434 )
F_344 ( V_5 , V_66 . V_6 [ V_5 -> V_7 ] ) ;
}
F_13 ( & V_8 ) ;
F_13 ( & V_112 ) ;
V_22 = F_15 ( V_66 . V_6 ) ;
F_55 ( V_62 , & V_66 . V_32 , V_22 ) ;
F_35 ( F_118 ( & V_113 , 0 , 1 ) ) ;
V_282 = F_137 ( & V_113 . V_161 , V_119 ,
0 , 1 , V_56 ) ;
F_35 ( V_282 < 0 ) ;
F_14 ( & V_112 ) ;
F_14 ( & V_8 ) ;
V_453 = F_352 ( L_39 , V_454 ) ;
if ( ! V_453 ) {
V_282 = - V_57 ;
goto V_205;
}
V_282 = F_353 ( & V_455 ) ;
if ( V_282 < 0 ) {
F_354 ( V_453 ) ;
goto V_205;
}
F_355 ( L_40 , 0 , NULL , & V_456 ) ;
V_205:
if ( V_282 )
F_356 ( & V_82 ) ;
return V_282 ;
}
int F_357 ( struct V_124 * V_277 , void * V_384 )
{
struct V_231 * V_231 ;
struct V_63 * V_216 ;
char * V_202 ;
int V_222 ;
struct V_51 * V_50 ;
V_222 = - V_57 ;
V_202 = F_65 ( V_343 , V_56 ) ;
if ( ! V_202 )
goto V_205;
V_222 = - V_235 ;
V_231 = V_277 -> V_267 ;
V_216 = F_358 ( V_231 , V_457 ) ;
if ( ! V_216 )
goto V_458;
V_222 = 0 ;
F_13 ( & V_8 ) ;
F_138 (root) {
struct V_4 * V_5 ;
struct V_2 * V_3 ;
int V_54 = 0 ;
F_102 ( V_277 , L_41 , V_50 -> V_166 ) ;
F_101 (root, ss)
F_102 ( V_277 , L_42 , V_54 ++ ? L_9 : L_24 , V_5 -> V_84 ) ;
if ( strlen ( V_50 -> V_84 ) )
F_102 ( V_277 , L_43 , V_54 ? L_9 : L_24 ,
V_50 -> V_84 ) ;
F_180 ( V_277 , ':' ) ;
V_3 = F_56 ( V_216 , V_50 ) ;
V_222 = F_145 ( V_3 , V_202 , V_343 ) ;
if ( V_222 < 0 )
goto V_149;
F_103 ( V_277 , V_202 ) ;
F_180 ( V_277 , '\n' ) ;
}
V_149:
F_14 ( & V_8 ) ;
F_173 ( V_216 ) ;
V_458:
F_28 ( V_202 ) ;
V_205:
return V_222 ;
}
static int F_359 ( struct V_124 * V_277 , void * V_384 )
{
struct V_4 * V_5 ;
int V_23 ;
F_103 ( V_277 , L_44 ) ;
F_13 ( & V_8 ) ;
F_16 (ss, i)
F_102 ( V_277 , L_45 ,
V_5 -> V_84 , V_5 -> V_50 -> V_166 ,
V_5 -> V_50 -> V_90 , ! V_5 -> V_148 ) ;
F_14 ( & V_8 ) ;
return 0 ;
}
static int F_360 ( struct V_68 * V_68 , struct V_249 * V_249 )
{
return F_199 ( V_249 , F_359 , NULL ) ;
}
void F_361 ( struct V_63 * V_459 )
{
F_157 ( V_150 ) ;
F_30 ( F_58 ( V_150 ) ) ;
V_459 -> V_219 = V_150 -> V_219 ;
F_158 ( V_150 ) ;
F_41 ( & V_459 -> V_220 ) ;
}
void F_362 ( struct V_63 * V_459 )
{
struct V_4 * V_5 ;
int V_23 ;
if ( V_318 ) {
F_19 ( & V_31 ) ;
F_157 ( V_459 ) ;
if ( F_25 ( & V_459 -> V_220 ) )
F_43 ( & V_459 -> V_220 , & F_58 ( V_459 ) -> V_60 ) ;
F_158 ( V_459 ) ;
F_21 ( & V_31 ) ;
}
if ( V_444 ) {
F_348 (ss, i)
if ( V_5 -> V_445 )
V_5 -> V_445 ( V_459 ) ;
}
}
void F_363 ( struct V_63 * V_216 , int V_460 )
{
struct V_4 * V_5 ;
struct V_24 * V_25 ;
int V_23 ;
if ( ! F_25 ( & V_216 -> V_220 ) ) {
F_19 ( & V_31 ) ;
if ( ! F_25 ( & V_216 -> V_220 ) )
F_87 ( & V_216 -> V_220 ) ;
F_21 ( & V_31 ) ;
}
F_157 ( V_216 ) ;
V_25 = F_58 ( V_216 ) ;
F_98 ( V_216 -> V_219 , & V_66 ) ;
if ( V_460 && V_444 ) {
F_348 (ss, i) {
if ( V_5 -> exit ) {
struct V_1 * V_461 = V_25 -> V_6 [ V_23 ] ;
struct V_1 * V_21 = F_364 ( V_216 , V_23 ) ;
V_5 -> exit ( V_21 , V_461 , V_216 ) ;
}
}
}
F_158 ( V_216 ) ;
F_33 ( V_25 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
if ( F_7 ( V_3 ) &&
F_25 ( & V_3 -> V_36 ) && F_25 ( & V_3 -> V_153 ) ) {
int V_462 = 0 ;
F_365 ( & V_463 ) ;
if ( ! F_4 ( V_3 ) &&
F_25 ( & V_3 -> V_155 ) ) {
F_43 ( & V_3 -> V_155 , & V_155 ) ;
V_462 = 1 ;
}
F_366 ( & V_463 ) ;
if ( V_462 )
F_74 ( & V_464 ) ;
}
}
static void F_367 ( struct V_87 * V_88 )
{
F_35 ( V_88 != & V_464 ) ;
F_13 ( & V_8 ) ;
F_365 ( & V_463 ) ;
while ( ! F_25 ( & V_155 ) ) {
char * V_465 [ 3 ] , * V_466 [ 3 ] ;
int V_23 ;
char * V_467 = NULL , * V_468 = NULL ;
struct V_2 * V_3 = F_36 ( V_155 . V_49 ,
struct V_2 ,
V_155 ) ;
F_87 ( & V_3 -> V_155 ) ;
F_366 ( & V_463 ) ;
V_467 = F_65 ( V_343 , V_56 ) ;
if ( ! V_467 )
goto V_469;
if ( F_145 ( V_3 , V_467 , V_343 ) < 0 )
goto V_469;
V_468 = F_368 ( V_3 -> V_50 -> V_131 , V_56 ) ;
if ( ! V_468 )
goto V_469;
V_23 = 0 ;
V_465 [ V_23 ++ ] = V_468 ;
V_465 [ V_23 ++ ] = V_467 ;
V_465 [ V_23 ] = NULL ;
V_23 = 0 ;
V_466 [ V_23 ++ ] = L_46 ;
V_466 [ V_23 ++ ] = L_47 ;
V_466 [ V_23 ] = NULL ;
F_14 ( & V_8 ) ;
F_369 ( V_465 [ 0 ] , V_465 , V_466 , V_470 ) ;
F_13 ( & V_8 ) ;
V_469:
F_28 ( V_467 ) ;
F_28 ( V_468 ) ;
F_365 ( & V_463 ) ;
}
F_366 ( & V_463 ) ;
F_14 ( & V_8 ) ;
}
static int T_12 F_370 ( char * V_471 )
{
struct V_4 * V_5 ;
char * V_136 ;
int V_23 ;
while ( ( V_136 = F_106 ( & V_471 , L_9 ) ) != NULL ) {
if ( ! * V_136 )
continue;
F_348 (ss, i) {
if ( ! strcmp ( V_136 , V_5 -> V_84 ) ) {
V_5 -> V_148 = 1 ;
F_342 ( V_443 L_48
L_49 , V_5 -> V_84 ) ;
break;
}
}
}
return 1 ;
}
unsigned short V_418 ( struct V_1 * V_21 )
{
struct V_418 * V_472 ;
V_472 = F_71 ( V_21 -> V_164 ) ;
if ( V_472 )
return V_472 -> V_164 ;
return 0 ;
}
bool F_371 ( struct V_1 * V_459 ,
const struct V_1 * V_50 )
{
struct V_418 * V_473 ;
struct V_418 * V_474 ;
V_473 = F_372 ( V_459 -> V_164 ) ;
if ( ! V_473 )
return false ;
V_474 = F_372 ( V_50 -> V_164 ) ;
if ( ! V_474 )
return false ;
if ( V_473 -> V_475 < V_474 -> V_475 )
return false ;
if ( V_473 -> V_476 [ V_474 -> V_475 ] != V_474 -> V_164 )
return false ;
return true ;
}
void F_373 ( struct V_4 * V_5 , struct V_1 * V_21 )
{
struct V_418 * V_164 = F_204 ( V_21 -> V_164 , true ) ;
if ( ! V_164 )
return;
F_35 ( ! V_5 -> V_434 ) ;
F_97 ( V_164 -> V_21 , NULL ) ;
F_97 ( V_21 -> V_164 , NULL ) ;
F_91 ( & V_5 -> V_477 ) ;
F_121 ( & V_5 -> V_449 , V_164 -> V_164 ) ;
F_93 ( & V_5 -> V_477 ) ;
F_29 ( V_164 , V_37 ) ;
}
static struct V_418 * F_374 ( struct V_4 * V_5 , int V_475 )
{
struct V_418 * V_478 ;
int V_111 , V_301 ;
F_35 ( ! V_5 -> V_434 ) ;
V_301 = sizeof( * V_478 ) + sizeof( unsigned short ) * ( V_475 + 1 ) ;
V_478 = F_42 ( V_301 , V_56 ) ;
if ( ! V_478 )
return F_124 ( - V_57 ) ;
F_375 ( V_56 ) ;
F_91 ( & V_5 -> V_477 ) ;
V_111 = F_137 ( & V_5 -> V_449 , V_478 , 1 , V_479 + 1 , V_480 ) ;
F_93 ( & V_5 -> V_477 ) ;
F_376 () ;
if ( V_111 < 0 )
goto V_481;
V_478 -> V_164 = V_111 ;
V_478 -> V_475 = V_475 ;
return V_478 ;
V_481:
F_28 ( V_478 ) ;
return F_124 ( V_111 ) ;
}
static int T_11 F_344 ( struct V_4 * V_5 ,
struct V_1 * V_482 )
{
struct V_418 * V_478 ;
F_114 ( & V_5 -> V_477 ) ;
F_117 ( & V_5 -> V_449 ) ;
V_478 = F_374 ( V_5 , 0 ) ;
if ( F_134 ( V_478 ) )
return F_135 ( V_478 ) ;
V_478 -> V_476 [ 0 ] = V_478 -> V_164 ;
F_98 ( V_478 -> V_21 , V_482 ) ;
F_98 ( V_482 -> V_164 , V_478 ) ;
return 0 ;
}
static int F_326 ( struct V_1 * V_483 )
{
struct V_1 * V_321 = F_241 ( V_483 ) ;
struct V_418 * V_473 , * V_484 ;
int V_23 , V_475 ;
V_484 = F_204 ( V_321 -> V_164 , true ) ;
V_475 = V_484 -> V_475 + 1 ;
V_473 = F_374 ( V_483 -> V_5 , V_475 ) ;
if ( F_134 ( V_473 ) )
return F_135 ( V_473 ) ;
for ( V_23 = 0 ; V_23 < V_475 ; V_23 ++ )
V_473 -> V_476 [ V_23 ] = V_484 -> V_476 [ V_23 ] ;
V_473 -> V_476 [ V_475 ] = V_473 -> V_164 ;
F_97 ( V_483 -> V_164 , V_473 ) ;
return 0 ;
}
struct V_1 * F_377 ( struct V_4 * V_5 , int V_164 )
{
struct V_418 * V_472 = NULL ;
F_35 ( ! V_5 -> V_434 ) ;
V_472 = F_378 ( & V_5 -> V_449 , V_164 ) ;
if ( F_275 ( ! V_472 ) )
return NULL ;
return F_372 ( V_472 -> V_21 ) ;
}
struct V_1 * F_314 ( struct V_17 * V_17 ,
struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_126 ( ! F_236 () ) ;
if ( ! V_17 -> V_98 ||
V_17 -> V_98 -> V_185 != & V_186 )
return F_124 ( - V_409 ) ;
V_3 = F_9 ( V_17 ) ;
return F_1 ( V_3 , V_5 ) ? : F_124 ( - V_117 ) ;
}
struct V_1 * F_379 ( int V_164 , struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_380 ( F_236 () ||
F_3 ( & V_8 ) ,
L_50 ) ;
V_3 = F_378 ( & V_5 -> V_50 -> V_161 , V_164 ) ;
if ( V_3 )
return F_1 ( V_3 , V_5 ) ;
return NULL ;
}
static struct V_1 *
F_381 ( struct V_1 * V_321 )
{
struct V_1 * V_21 = F_42 ( sizeof( * V_21 ) , V_56 ) ;
if ( ! V_21 )
return F_124 ( - V_57 ) ;
return V_21 ;
}
static void F_382 ( struct V_1 * V_21 )
{
F_28 ( V_21 ) ;
}
static T_3 F_383 ( struct V_1 * V_21 ,
struct V_20 * V_99 )
{
return F_230 ( V_21 -> V_2 ) ;
}
static T_3 F_384 ( struct V_1 * V_21 ,
struct V_20 * V_99 )
{
return ( T_3 ) ( unsigned long ) V_150 -> V_219 ;
}
static T_3 F_385 ( struct V_1 * V_21 ,
struct V_20 * V_99 )
{
T_3 V_54 ;
F_147 () ;
V_54 = F_231 ( & F_58 ( V_150 ) -> V_30 ) ;
F_148 () ;
return V_54 ;
}
static int F_386 ( struct V_1 * V_21 ,
struct V_20 * V_99 ,
struct V_124 * V_125 )
{
struct V_27 * V_28 ;
struct V_24 * V_25 ;
F_50 ( & V_31 ) ;
F_147 () ;
V_25 = F_372 ( V_150 -> V_219 ) ;
F_54 (link, &cset->cgrp_links, cgrp_link) {
struct V_2 * V_61 = V_28 -> V_3 ;
const char * V_84 ;
if ( V_61 -> V_17 )
V_84 = V_61 -> V_17 -> V_85 . V_84 ;
else
V_84 = L_51 ;
F_102 ( V_125 , L_52 ,
V_61 -> V_50 -> V_166 , V_84 ) ;
}
F_148 () ;
F_51 ( & V_31 ) ;
return 0 ;
}
static int F_387 ( struct V_1 * V_21 ,
struct V_20 * V_99 , struct V_124 * V_125 )
{
struct V_27 * V_28 ;
F_50 ( & V_31 ) ;
F_54 (link, &css->cgroup->cset_links, cset_link) {
struct V_24 * V_25 = V_28 -> V_25 ;
struct V_63 * V_64 ;
int V_54 = 0 ;
F_102 ( V_125 , L_53 , V_25 ) ;
F_54 (task, &cset->tasks, cg_list) {
if ( V_54 ++ > V_485 ) {
F_103 ( V_125 , L_54 ) ;
break;
} else {
F_102 ( V_125 , L_55 ,
F_277 ( V_64 ) ) ;
}
}
}
F_51 ( & V_31 ) ;
return 0 ;
}
static T_3 F_388 ( struct V_1 * V_21 , struct V_20 * V_99 )
{
return F_5 ( V_15 , & V_21 -> V_2 -> V_11 ) ;
}
