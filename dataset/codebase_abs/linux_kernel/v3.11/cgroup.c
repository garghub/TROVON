static inline bool F_1 ( const struct V_1 * V_2 )
{
return F_2 ( V_3 , & V_2 -> V_4 ) ;
}
bool F_3 ( struct V_1 * V_2 , struct V_1 * V_5 )
{
while ( V_2 ) {
if ( V_2 == V_5 )
return true ;
V_2 = V_2 -> V_6 ;
}
return false ;
}
static int F_4 ( const struct V_1 * V_2 )
{
const int V_7 =
( 1 << V_8 ) |
( 1 << V_9 ) ;
return ( V_2 -> V_4 & V_7 ) == V_7 ;
}
static int F_5 ( const struct V_1 * V_2 )
{
return F_2 ( V_9 , & V_2 -> V_4 ) ;
}
static inline struct V_1 * F_6 ( struct V_10 * V_10 )
{
return V_10 -> V_11 ;
}
static inline struct V_12 * F_7 ( struct V_10 * V_10 )
{
return V_10 -> V_11 ;
}
static inline struct V_13 * F_8 ( struct V_10 * V_10 )
{
return F_7 ( V_10 ) -> type ;
}
static bool F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_14 ) ;
if ( F_1 ( V_2 ) ) {
F_11 ( & V_14 ) ;
return false ;
}
return true ;
}
static unsigned long F_12 ( struct V_15 * V_16 [] )
{
unsigned long V_17 = 0UL ;
struct V_18 * V_19 ;
int V_20 ;
F_13 (ss, i)
V_17 += ( unsigned long ) V_16 [ V_20 ] ;
V_17 = ( V_17 >> 16 ) ^ V_17 ;
return V_17 ;
}
static void F_14 ( struct V_21 * V_22 , int V_23 )
{
struct V_24 * V_25 , * V_26 ;
if ( F_15 ( & V_22 -> V_27 , - 1 , 1 ) )
return;
F_16 ( & V_28 ) ;
if ( ! F_17 ( & V_22 -> V_27 ) ) {
F_18 ( & V_28 ) ;
return;
}
F_19 ( & V_22 -> V_29 ) ;
V_30 -- ;
F_20 (link, tmp_link, &cset->cgrp_links, cgrp_link) {
struct V_1 * V_2 = V_25 -> V_2 ;
F_21 ( & V_25 -> V_31 ) ;
F_21 ( & V_25 -> V_32 ) ;
if ( F_22 ( & V_2 -> V_33 ) && F_5 ( V_2 ) ) {
if ( V_23 )
F_23 ( V_8 , & V_2 -> V_4 ) ;
F_24 ( V_2 ) ;
}
F_25 ( V_25 ) ;
}
F_18 ( & V_28 ) ;
F_26 ( V_22 , V_34 ) ;
}
static inline void F_27 ( struct V_21 * V_22 )
{
F_28 ( & V_22 -> V_27 ) ;
}
static inline void F_29 ( struct V_21 * V_22 )
{
F_14 ( V_22 , 0 ) ;
}
static inline void F_30 ( struct V_21 * V_22 )
{
F_14 ( V_22 , 1 ) ;
}
static bool F_31 ( struct V_21 * V_22 ,
struct V_21 * V_35 ,
struct V_1 * V_36 ,
struct V_15 * V_37 [] )
{
struct V_38 * V_39 , * V_40 ;
if ( memcmp ( V_37 , V_22 -> V_41 , sizeof( V_22 -> V_41 ) ) ) {
return false ;
}
V_39 = & V_22 -> V_42 ;
V_40 = & V_35 -> V_42 ;
while ( 1 ) {
struct V_24 * V_43 , * V_44 ;
struct V_1 * V_45 , * V_46 ;
V_39 = V_39 -> V_47 ;
V_40 = V_40 -> V_47 ;
if ( V_39 == & V_22 -> V_42 ) {
F_32 ( V_40 != & V_35 -> V_42 ) ;
break;
} else {
F_32 ( V_40 == & V_35 -> V_42 ) ;
}
V_43 = F_33 ( V_39 , struct V_24 , V_32 ) ;
V_44 = F_33 ( V_40 , struct V_24 , V_32 ) ;
V_45 = V_43 -> V_2 ;
V_46 = V_44 -> V_2 ;
F_32 ( V_45 -> V_48 != V_46 -> V_48 ) ;
if ( V_45 -> V_48 == V_36 -> V_48 ) {
if ( V_45 != V_36 )
return false ;
} else {
if ( V_45 != V_46 )
return false ;
}
}
return true ;
}
static struct V_21 * F_34 ( struct V_21 * V_35 ,
struct V_1 * V_2 ,
struct V_15 * V_37 [] )
{
struct V_49 * V_48 = V_2 -> V_48 ;
struct V_18 * V_19 ;
struct V_21 * V_22 ;
unsigned long V_17 ;
int V_20 ;
F_13 (ss, i) {
if ( V_48 -> V_50 & ( 1UL << V_20 ) ) {
V_37 [ V_20 ] = V_2 -> V_41 [ V_20 ] ;
} else {
V_37 [ V_20 ] = V_35 -> V_41 [ V_20 ] ;
}
}
V_17 = F_12 ( V_37 ) ;
F_35 (css_set_table, cset, hlist, key) {
if ( ! F_31 ( V_22 , V_35 , V_2 , V_37 ) )
continue;
return V_22 ;
}
return NULL ;
}
static void F_36 ( struct V_38 * V_51 )
{
struct V_24 * V_25 , * V_26 ;
F_20 (link, tmp_link, links_to_free, cset_link) {
F_21 ( & V_25 -> V_31 ) ;
F_25 ( V_25 ) ;
}
}
static int F_37 ( int V_52 , struct V_38 * V_53 )
{
struct V_24 * V_25 ;
int V_20 ;
F_38 ( V_53 ) ;
for ( V_20 = 0 ; V_20 < V_52 ; V_20 ++ ) {
V_25 = F_39 ( sizeof( * V_25 ) , V_54 ) ;
if ( ! V_25 ) {
F_36 ( V_53 ) ;
return - V_55 ;
}
F_40 ( & V_25 -> V_31 , V_53 ) ;
}
return 0 ;
}
static void F_41 ( struct V_38 * V_53 , struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
F_32 ( F_22 ( V_53 ) ) ;
V_25 = F_42 ( V_53 , struct V_24 , V_31 ) ;
V_25 -> V_22 = V_22 ;
V_25 -> V_2 = V_2 ;
F_43 ( & V_25 -> V_31 , & V_2 -> V_33 ) ;
F_44 ( & V_25 -> V_32 , & V_22 -> V_42 ) ;
}
static struct V_21 * F_45 ( struct V_21 * V_35 ,
struct V_1 * V_2 )
{
struct V_15 * V_37 [ V_56 ] = { } ;
struct V_21 * V_22 ;
struct V_38 V_53 ;
struct V_24 * V_25 ;
unsigned long V_17 ;
F_46 ( & V_14 ) ;
F_47 ( & V_28 ) ;
V_22 = F_34 ( V_35 , V_2 , V_37 ) ;
if ( V_22 )
F_27 ( V_22 ) ;
F_48 ( & V_28 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_39 ( sizeof( * V_22 ) , V_54 ) ;
if ( ! V_22 )
return NULL ;
if ( F_37 ( V_57 , & V_53 ) < 0 ) {
F_25 ( V_22 ) ;
return NULL ;
}
F_49 ( & V_22 -> V_27 , 1 ) ;
F_38 ( & V_22 -> V_42 ) ;
F_38 ( & V_22 -> V_58 ) ;
F_50 ( & V_22 -> V_29 ) ;
memcpy ( V_22 -> V_41 , V_37 , sizeof( V_22 -> V_41 ) ) ;
F_16 ( & V_28 ) ;
F_51 (link, &old_cset->cgrp_links, cgrp_link) {
struct V_1 * V_59 = V_25 -> V_2 ;
if ( V_59 -> V_48 == V_2 -> V_48 )
V_59 = V_2 ;
F_41 ( & V_53 , V_22 , V_59 ) ;
}
F_32 ( ! F_22 ( & V_53 ) ) ;
V_30 ++ ;
V_17 = F_12 ( V_22 -> V_41 ) ;
F_52 ( V_60 , & V_22 -> V_29 , V_17 ) ;
F_18 ( & V_28 ) ;
return V_22 ;
}
static struct V_1 * F_53 ( struct V_61 * V_62 ,
struct V_49 * V_48 )
{
struct V_21 * V_22 ;
struct V_1 * V_63 = NULL ;
F_32 ( ! F_54 ( & V_14 ) ) ;
F_47 ( & V_28 ) ;
V_22 = F_55 ( V_62 ) ;
if ( V_22 == & V_64 ) {
V_63 = & V_48 -> V_65 ;
} else {
struct V_24 * V_25 ;
F_51 (link, &cset->cgrp_links, cgrp_link) {
struct V_1 * V_59 = V_25 -> V_2 ;
if ( V_59 -> V_48 == V_48 ) {
V_63 = V_59 ;
break;
}
}
}
F_48 ( & V_28 ) ;
F_32 ( ! V_63 ) ;
return V_63 ;
}
static struct V_66 * F_56 ( T_1 V_67 , struct V_68 * V_69 )
{
struct V_66 * V_66 = F_57 ( V_69 ) ;
if ( V_66 ) {
V_66 -> V_70 = F_58 () ;
V_66 -> V_71 = V_67 ;
V_66 -> V_72 = F_59 () ;
V_66 -> V_73 = F_60 () ;
V_66 -> V_74 = V_66 -> V_75 = V_66 -> V_76 = V_77 ;
V_66 -> V_78 -> V_79 = & V_80 ;
}
return V_66 ;
}
static struct V_81 * F_61 ( struct V_10 * V_10 )
{
struct V_81 * V_82 ;
V_82 = F_62 ( sizeof( * V_82 ) + V_10 -> V_83 . V_84 + 1 , V_54 ) ;
if ( ! V_82 )
return NULL ;
strcpy ( V_82 -> V_82 , V_10 -> V_83 . V_82 ) ;
return V_82 ;
}
static void F_63 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = F_64 ( V_86 , struct V_1 , V_87 ) ;
struct V_18 * V_19 ;
F_10 ( & V_14 ) ;
F_65 (cgrp->root, ss)
V_19 -> V_88 ( V_2 ) ;
V_2 -> V_48 -> V_89 -- ;
F_11 ( & V_14 ) ;
F_66 ( V_2 -> V_6 -> V_10 ) ;
F_67 ( & V_2 -> V_48 -> V_90 , V_2 -> V_91 ) ;
F_68 ( V_2 -> V_48 -> V_69 ) ;
F_32 ( ! F_22 ( & V_2 -> V_92 ) ) ;
F_69 ( & V_2 -> V_93 ) ;
F_25 ( F_70 ( V_2 -> V_82 ) ) ;
F_25 ( V_2 ) ;
}
static void F_71 ( struct V_34 * V_94 )
{
struct V_1 * V_2 = F_64 ( V_94 , struct V_1 , V_34 ) ;
F_72 ( & V_2 -> V_87 , F_63 ) ;
F_73 ( & V_2 -> V_87 ) ;
}
static void F_74 ( struct V_10 * V_10 , struct V_66 * V_66 )
{
if ( F_75 ( V_66 -> V_71 ) ) {
struct V_1 * V_2 = V_10 -> V_11 ;
F_32 ( ! ( F_1 ( V_2 ) ) ) ;
F_76 ( & V_2 -> V_34 , F_71 ) ;
} else {
struct V_12 * V_95 = F_7 ( V_10 ) ;
struct V_1 * V_2 = V_10 -> V_96 -> V_11 ;
F_77 ( ! F_22 ( & V_95 -> V_97 ) &&
V_2 != & V_2 -> V_48 -> V_65 ,
L_1 , V_95 -> type -> V_82 ) ;
F_69 ( & V_95 -> V_93 ) ;
F_25 ( V_95 ) ;
}
F_78 ( V_66 ) ;
}
static int F_79 ( const struct V_10 * V_98 )
{
return 1 ;
}
static void F_80 ( struct V_10 * V_98 )
{
struct V_10 * V_6 = F_81 ( V_98 -> V_96 ) ;
F_82 ( V_98 ) ;
F_83 ( V_6 -> V_99 , V_98 ) ;
F_66 ( V_6 ) ;
}
static void F_84 ( struct V_1 * V_2 , const struct V_13 * V_100 )
{
struct V_12 * V_95 ;
F_46 ( & V_2 -> V_10 -> V_99 -> V_101 ) ;
F_46 ( & V_14 ) ;
F_51 (cfe, &cgrp->files, node) {
struct V_10 * V_98 = V_95 -> V_10 ;
if ( V_100 && V_95 -> type != V_100 )
continue;
F_81 ( V_98 ) ;
F_82 ( V_98 ) ;
F_85 ( V_2 -> V_10 -> V_99 , V_98 ) ;
F_86 ( & V_95 -> V_97 ) ;
F_66 ( V_98 ) ;
break;
}
}
static void F_87 ( struct V_10 * V_102 , bool V_103 ,
unsigned long V_50 )
{
struct V_1 * V_2 = F_6 ( V_102 ) ;
struct V_18 * V_19 ;
F_65 (cgrp->root, ss) {
struct V_104 * V_105 ;
if ( ! F_2 ( V_19 -> V_106 , & V_50 ) )
continue;
F_51 (set, &ss->cftsets, node)
F_88 ( V_2 , NULL , V_105 -> V_107 , false ) ;
}
if ( V_103 ) {
while ( ! F_22 ( & V_2 -> V_108 ) )
F_84 ( V_2 , NULL ) ;
}
}
static void F_89 ( struct V_10 * V_10 )
{
struct V_10 * V_6 ;
struct V_49 * V_48 = V_10 -> V_109 -> V_110 ;
F_87 ( V_10 , true , V_48 -> V_50 ) ;
V_6 = V_10 -> V_96 ;
F_90 ( & V_6 -> V_111 ) ;
F_91 ( & V_10 -> V_111 , V_112 ) ;
F_86 ( & V_10 -> V_113 . V_114 ) ;
F_92 ( & V_10 -> V_111 ) ;
F_92 ( & V_6 -> V_111 ) ;
F_80 ( V_10 ) ;
}
static int F_93 ( struct V_49 * V_48 ,
unsigned long V_115 , unsigned V_116 )
{
struct V_1 * V_2 = & V_48 -> V_65 ;
struct V_18 * V_19 ;
int V_20 ;
F_32 ( ! F_54 ( & V_14 ) ) ;
F_32 ( ! F_54 ( & V_117 ) ) ;
F_13 (ss, i) {
unsigned long V_118 = 1UL << V_20 ;
if ( ! ( V_118 & V_115 ) )
continue;
if ( V_19 -> V_48 != & V_119 ) {
return - V_120 ;
}
}
if ( V_48 -> V_89 > 1 )
return - V_120 ;
F_13 (ss, i) {
unsigned long V_118 = 1UL << V_20 ;
if ( V_118 & V_115 ) {
F_32 ( V_2 -> V_41 [ V_20 ] ) ;
F_32 ( ! V_121 -> V_41 [ V_20 ] ) ;
F_32 ( V_121 -> V_41 [ V_20 ] -> V_1 != V_121 ) ;
V_2 -> V_41 [ V_20 ] = V_121 -> V_41 [ V_20 ] ;
V_2 -> V_41 [ V_20 ] -> V_1 = V_2 ;
F_43 ( & V_19 -> V_122 , & V_48 -> V_123 ) ;
V_19 -> V_48 = V_48 ;
if ( V_19 -> V_124 )
V_19 -> V_124 ( V_2 ) ;
V_48 -> V_50 |= V_118 ;
} else if ( V_118 & V_116 ) {
F_32 ( V_2 -> V_41 [ V_20 ] != V_121 -> V_41 [ V_20 ] ) ;
F_32 ( V_2 -> V_41 [ V_20 ] -> V_1 != V_2 ) ;
if ( V_19 -> V_124 )
V_19 -> V_124 ( V_121 ) ;
V_121 -> V_41 [ V_20 ] -> V_1 = V_121 ;
V_2 -> V_41 [ V_20 ] = NULL ;
V_18 [ V_20 ] -> V_48 = & V_119 ;
F_43 ( & V_19 -> V_122 , & V_119 . V_123 ) ;
F_94 ( V_19 -> V_125 ) ;
V_48 -> V_50 &= ~ V_118 ;
} else if ( V_118 & V_48 -> V_50 ) {
F_32 ( ! V_2 -> V_41 [ V_20 ] ) ;
F_94 ( V_19 -> V_125 ) ;
#ifdef F_95
F_32 ( V_19 -> V_125 && ! F_96 ( V_19 -> V_125 ) ) ;
#endif
} else {
F_32 ( V_2 -> V_41 [ V_20 ] ) ;
}
}
V_48 -> V_4 |= V_126 ;
return 0 ;
}
static int F_97 ( struct V_127 * V_128 , struct V_10 * V_10 )
{
struct V_49 * V_48 = V_10 -> V_109 -> V_110 ;
struct V_18 * V_19 ;
F_10 ( & V_117 ) ;
F_65 (root, ss)
F_98 ( V_128 , L_2 , V_19 -> V_82 ) ;
if ( V_48 -> V_4 & V_129 )
F_99 ( V_128 , L_3 ) ;
if ( V_48 -> V_4 & V_130 )
F_99 ( V_128 , L_4 ) ;
if ( V_48 -> V_4 & V_131 )
F_99 ( V_128 , L_5 ) ;
if ( strlen ( V_48 -> V_132 ) )
F_98 ( V_128 , L_6 , V_48 -> V_132 ) ;
if ( F_2 ( V_133 , & V_48 -> V_65 . V_4 ) )
F_99 ( V_128 , L_7 ) ;
if ( strlen ( V_48 -> V_82 ) )
F_98 ( V_128 , L_8 , V_48 -> V_82 ) ;
F_11 ( & V_117 ) ;
return 0 ;
}
static int F_100 ( char * V_134 , struct V_135 * V_136 )
{
char * V_137 , * V_138 = V_134 ;
bool V_139 = false , V_140 = false ;
unsigned long V_141 = ( unsigned long ) - 1 ;
bool V_142 = false ;
struct V_18 * V_19 ;
int V_20 ;
F_32 ( ! F_54 ( & V_14 ) ) ;
#ifdef F_101
V_141 = ~ ( 1UL << V_143 ) ;
#endif
memset ( V_136 , 0 , sizeof( * V_136 ) ) ;
while ( ( V_137 = F_102 ( & V_138 , L_9 ) ) != NULL ) {
if ( ! * V_137 )
return - V_144 ;
if ( ! strcmp ( V_137 , L_10 ) ) {
V_136 -> V_145 = true ;
continue;
}
if ( ! strcmp ( V_137 , L_11 ) ) {
if ( V_140 )
return - V_144 ;
V_139 = true ;
continue;
}
if ( ! strcmp ( V_137 , L_12 ) ) {
V_136 -> V_4 |= V_129 ;
continue;
}
if ( ! strcmp ( V_137 , L_13 ) ) {
V_136 -> V_4 |= V_130 ;
continue;
}
if ( ! strcmp ( V_137 , L_14 ) ) {
V_136 -> V_146 = true ;
continue;
}
if ( ! strcmp ( V_137 , L_15 ) ) {
V_136 -> V_4 |= V_131 ;
continue;
}
if ( ! strncmp ( V_137 , L_16 , 14 ) ) {
if ( V_136 -> V_147 )
return - V_144 ;
V_136 -> V_147 =
F_103 ( V_137 + 14 , V_148 - 1 , V_54 ) ;
if ( ! V_136 -> V_147 )
return - V_55 ;
continue;
}
if ( ! strncmp ( V_137 , L_17 , 5 ) ) {
const char * V_82 = V_137 + 5 ;
if ( ! strlen ( V_82 ) )
return - V_144 ;
for ( V_20 = 0 ; V_20 < strlen ( V_82 ) ; V_20 ++ ) {
char V_59 = V_82 [ V_20 ] ;
if ( isalnum ( V_59 ) )
continue;
if ( ( V_59 == '.' ) || ( V_59 == '-' ) || ( V_59 == '_' ) )
continue;
return - V_144 ;
}
if ( V_136 -> V_82 )
return - V_144 ;
V_136 -> V_82 = F_103 ( V_82 ,
V_149 - 1 ,
V_54 ) ;
if ( ! V_136 -> V_82 )
return - V_55 ;
continue;
}
F_13 (ss, i) {
if ( strcmp ( V_137 , V_19 -> V_82 ) )
continue;
if ( V_19 -> V_150 )
continue;
if ( V_139 )
return - V_144 ;
F_23 ( V_20 , & V_136 -> V_50 ) ;
V_140 = true ;
break;
}
if ( V_20 == V_56 )
return - V_151 ;
}
if ( V_139 || ( ! V_140 && ! V_136 -> V_145 && ! V_136 -> V_82 ) )
F_13 (ss, i)
if ( ! V_19 -> V_150 )
F_23 ( V_20 , & V_136 -> V_50 ) ;
if ( V_136 -> V_4 & V_129 ) {
F_104 ( L_18 ) ;
if ( V_136 -> V_4 & V_130 ) {
F_105 ( L_19 ) ;
return - V_144 ;
}
if ( V_136 -> V_146 ) {
F_105 ( L_20 ) ;
return - V_144 ;
}
}
if ( ( V_136 -> V_4 & V_130 ) && ( V_136 -> V_50 & V_141 ) )
return - V_144 ;
if ( V_136 -> V_50 && V_136 -> V_145 )
return - V_144 ;
if ( ! V_136 -> V_50 && ! V_136 -> V_82 )
return - V_144 ;
F_13 (ss, i) {
if ( ! ( V_136 -> V_50 & ( 1UL << V_20 ) ) )
continue;
if ( ! F_106 ( V_18 [ V_20 ] -> V_125 ) ) {
V_142 = true ;
break;
}
}
if ( V_142 ) {
for ( V_20 -- ; V_20 >= 0 ; V_20 -- ) {
unsigned long V_118 = 1UL << V_20 ;
if ( ! ( V_118 & V_136 -> V_50 ) )
continue;
F_94 ( V_18 [ V_20 ] -> V_125 ) ;
}
return - V_151 ;
}
return 0 ;
}
static void F_107 ( unsigned long V_50 )
{
struct V_18 * V_19 ;
int V_20 ;
F_10 ( & V_14 ) ;
F_13 (ss, i)
if ( V_50 & ( 1UL << V_20 ) )
F_94 ( V_18 [ V_20 ] -> V_125 ) ;
F_11 ( & V_14 ) ;
}
static int F_108 ( struct V_68 * V_69 , int * V_4 , char * V_134 )
{
int V_152 = 0 ;
struct V_49 * V_48 = V_69 -> V_110 ;
struct V_1 * V_2 = & V_48 -> V_65 ;
struct V_135 V_136 ;
unsigned long V_115 , V_116 ;
if ( V_48 -> V_4 & V_129 ) {
F_105 ( L_21 ) ;
return - V_144 ;
}
F_10 ( & V_2 -> V_10 -> V_99 -> V_101 ) ;
F_10 ( & V_14 ) ;
F_10 ( & V_117 ) ;
V_152 = F_100 ( V_134 , & V_136 ) ;
if ( V_152 )
goto V_153;
if ( V_136 . V_50 != V_48 -> V_50 || V_136 . V_147 )
F_104 ( L_22 ,
F_109 ( V_154 ) , V_154 -> V_155 ) ;
V_115 = V_136 . V_50 & ~ V_48 -> V_50 ;
V_116 = V_48 -> V_50 & ~ V_136 . V_50 ;
if ( ( ( V_136 . V_4 ^ V_48 -> V_4 ) & V_156 ) ||
( V_136 . V_82 && strcmp ( V_136 . V_82 , V_48 -> V_82 ) ) ) {
F_105 ( L_23 ,
V_136 . V_4 & V_156 , V_136 . V_82 ? : L_24 ,
V_48 -> V_4 & V_156 , V_48 -> V_82 ) ;
V_152 = - V_144 ;
goto V_153;
}
F_87 ( V_2 -> V_10 , false , V_116 ) ;
V_152 = F_93 ( V_48 , V_115 , V_116 ) ;
if ( V_152 ) {
F_110 ( V_2 , false , V_116 ) ;
goto V_153;
}
F_110 ( V_2 , false , V_115 ) ;
if ( V_136 . V_147 )
strcpy ( V_48 -> V_132 , V_136 . V_147 ) ;
V_153:
F_25 ( V_136 . V_147 ) ;
F_25 ( V_136 . V_82 ) ;
F_11 ( & V_117 ) ;
F_11 ( & V_14 ) ;
F_11 ( & V_2 -> V_10 -> V_99 -> V_101 ) ;
if ( V_152 )
F_107 ( V_136 . V_50 ) ;
return V_152 ;
}
static void F_111 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_122 ) ;
F_38 ( & V_2 -> V_157 ) ;
F_38 ( & V_2 -> V_108 ) ;
F_38 ( & V_2 -> V_33 ) ;
F_38 ( & V_2 -> V_158 ) ;
F_38 ( & V_2 -> V_92 ) ;
F_112 ( & V_2 -> V_159 ) ;
F_38 ( & V_2 -> V_160 ) ;
F_113 ( & V_2 -> V_161 ) ;
F_114 ( & V_2 -> V_93 ) ;
}
static void F_115 ( struct V_49 * V_48 )
{
struct V_1 * V_2 = & V_48 -> V_65 ;
F_38 ( & V_48 -> V_123 ) ;
F_38 ( & V_48 -> V_162 ) ;
V_48 -> V_89 = 1 ;
V_2 -> V_48 = V_48 ;
F_116 ( V_2 -> V_82 , & V_163 ) ;
F_111 ( V_2 ) ;
}
static int F_117 ( struct V_49 * V_48 , int V_164 , int V_165 )
{
int V_91 ;
F_46 ( & V_14 ) ;
F_46 ( & V_117 ) ;
V_91 = F_118 ( & V_166 , V_48 , V_164 , V_165 ,
V_54 ) ;
if ( V_91 < 0 )
return V_91 ;
V_48 -> V_167 = V_91 ;
return 0 ;
}
static void F_119 ( struct V_49 * V_48 )
{
F_46 ( & V_14 ) ;
F_46 ( & V_117 ) ;
if ( V_48 -> V_167 ) {
F_120 ( & V_166 , V_48 -> V_167 ) ;
V_48 -> V_167 = 0 ;
}
}
static int F_121 ( struct V_68 * V_69 , void * V_134 )
{
struct V_135 * V_136 = V_134 ;
struct V_49 * V_48 = V_69 -> V_110 ;
if ( V_136 -> V_82 && strcmp ( V_136 -> V_82 , V_48 -> V_82 ) )
return 0 ;
if ( ( V_136 -> V_50 || V_136 -> V_145 )
&& ( V_136 -> V_50 != V_48 -> V_50 ) )
return 0 ;
return 1 ;
}
static struct V_49 * F_122 ( struct V_135 * V_136 )
{
struct V_49 * V_48 ;
if ( ! V_136 -> V_50 && ! V_136 -> V_145 )
return NULL ;
V_48 = F_39 ( sizeof( * V_48 ) , V_54 ) ;
if ( ! V_48 )
return F_123 ( - V_55 ) ;
F_115 ( V_48 ) ;
V_48 -> V_50 = V_136 -> V_50 ;
V_48 -> V_4 = V_136 -> V_4 ;
F_124 ( & V_48 -> V_90 ) ;
if ( V_136 -> V_147 )
strcpy ( V_48 -> V_132 , V_136 -> V_147 ) ;
if ( V_136 -> V_82 )
strcpy ( V_48 -> V_82 , V_136 -> V_82 ) ;
if ( V_136 -> V_146 )
F_23 ( V_133 , & V_48 -> V_65 . V_4 ) ;
return V_48 ;
}
static void F_125 ( struct V_49 * V_48 )
{
if ( V_48 ) {
F_126 ( V_48 -> V_167 ) ;
F_127 ( & V_48 -> V_90 ) ;
F_25 ( V_48 ) ;
}
}
static int F_128 ( struct V_68 * V_69 , void * V_134 )
{
int V_152 ;
struct V_135 * V_136 = V_134 ;
if ( ! V_136 -> V_168 )
return - V_144 ;
F_32 ( ! V_136 -> V_50 && ! V_136 -> V_145 ) ;
V_152 = F_129 ( V_69 , NULL ) ;
if ( V_152 )
return V_152 ;
V_69 -> V_110 = V_136 -> V_168 ;
V_136 -> V_168 -> V_69 = V_69 ;
V_69 -> V_169 = V_170 ;
V_69 -> V_171 = V_172 ;
V_69 -> V_173 = V_174 ;
V_69 -> V_175 = & V_176 ;
return 0 ;
}
static int F_130 ( struct V_68 * V_69 )
{
static const struct V_177 V_178 = {
. V_179 = F_74 ,
. F_82 = F_79 ,
} ;
struct V_66 * V_66 =
F_56 ( V_180 | V_181 | V_182 | V_183 , V_69 ) ;
if ( ! V_66 )
return - V_55 ;
V_66 -> V_184 = & V_185 ;
V_66 -> V_186 = & V_187 ;
F_131 ( V_66 ) ;
V_69 -> V_188 = F_132 ( V_66 ) ;
if ( ! V_69 -> V_188 )
return - V_55 ;
V_69 -> V_189 = & V_178 ;
return 0 ;
}
static struct V_10 * F_133 ( struct V_190 * V_191 ,
int V_4 , const char * V_192 ,
void * V_134 )
{
struct V_135 V_136 ;
struct V_49 * V_48 ;
int V_152 = 0 ;
struct V_68 * V_69 ;
struct V_49 * V_168 ;
struct V_66 * V_66 ;
F_10 ( & V_14 ) ;
V_152 = F_100 ( V_134 , & V_136 ) ;
F_11 ( & V_14 ) ;
if ( V_152 )
goto V_193;
V_168 = F_122 ( & V_136 ) ;
if ( F_134 ( V_168 ) ) {
V_152 = F_135 ( V_168 ) ;
goto V_194;
}
V_136 . V_168 = V_168 ;
V_69 = F_136 ( V_191 , F_121 , F_128 , 0 , & V_136 ) ;
if ( F_134 ( V_69 ) ) {
V_152 = F_135 ( V_69 ) ;
F_125 ( V_136 . V_168 ) ;
goto V_194;
}
V_48 = V_69 -> V_110 ;
F_32 ( ! V_48 ) ;
if ( V_48 == V_136 . V_168 ) {
struct V_38 V_53 ;
struct V_1 * V_195 = & V_48 -> V_65 ;
struct V_49 * V_196 ;
const struct V_197 * V_197 ;
int V_20 ;
struct V_21 * V_22 ;
F_32 ( V_69 -> V_188 != NULL ) ;
V_152 = F_130 ( V_69 ) ;
if ( V_152 )
goto V_198;
V_66 = V_69 -> V_188 -> V_99 ;
F_10 ( & V_66 -> V_101 ) ;
F_10 ( & V_14 ) ;
F_10 ( & V_117 ) ;
V_152 = - V_120 ;
if ( strlen ( V_48 -> V_82 ) )
F_137 (existing_root)
if ( ! strcmp ( V_196 -> V_82 , V_48 -> V_82 ) )
goto V_199;
V_152 = F_37 ( V_30 , & V_53 ) ;
if ( V_152 )
goto V_199;
V_152 = F_117 ( V_48 , 2 , 0 ) ;
if ( V_152 )
goto V_199;
V_152 = F_93 ( V_48 , V_48 -> V_50 , 0 ) ;
if ( V_152 == - V_120 ) {
F_36 ( & V_53 ) ;
goto V_199;
}
F_32 ( V_152 ) ;
F_40 ( & V_48 -> V_162 , & V_200 ) ;
V_57 ++ ;
V_69 -> V_188 -> V_11 = V_195 ;
V_48 -> V_65 . V_10 = V_69 -> V_188 ;
F_16 ( & V_28 ) ;
F_138 (css_set_table, i, cset, hlist)
F_41 ( & V_53 , V_22 , V_195 ) ;
F_18 ( & V_28 ) ;
F_36 ( & V_53 ) ;
F_32 ( ! F_22 ( & V_195 -> V_157 ) ) ;
F_32 ( V_48 -> V_89 != 1 ) ;
V_197 = F_139 ( & V_201 ) ;
F_110 ( V_195 , true , V_48 -> V_50 ) ;
F_140 ( V_197 ) ;
F_11 ( & V_117 ) ;
F_11 ( & V_14 ) ;
F_11 ( & V_66 -> V_101 ) ;
} else {
F_125 ( V_136 . V_168 ) ;
if ( ( V_48 -> V_4 ^ V_136 . V_4 ) & V_156 ) {
if ( ( V_48 -> V_4 | V_136 . V_4 ) & V_129 ) {
F_105 ( L_25 ) ;
V_152 = - V_144 ;
goto V_198;
} else {
F_104 ( L_26 ) ;
}
}
F_107 ( V_136 . V_50 ) ;
}
F_25 ( V_136 . V_147 ) ;
F_25 ( V_136 . V_82 ) ;
return F_81 ( V_69 -> V_188 ) ;
V_199:
F_119 ( V_48 ) ;
F_11 ( & V_117 ) ;
F_11 ( & V_14 ) ;
F_11 ( & V_66 -> V_101 ) ;
V_198:
F_141 ( V_69 ) ;
V_194:
F_107 ( V_136 . V_50 ) ;
V_193:
F_25 ( V_136 . V_147 ) ;
F_25 ( V_136 . V_82 ) ;
return F_123 ( V_152 ) ;
}
static void F_142 ( struct V_68 * V_69 ) {
struct V_49 * V_48 = V_69 -> V_110 ;
struct V_1 * V_2 = & V_48 -> V_65 ;
struct V_24 * V_25 , * V_26 ;
int V_152 ;
F_32 ( ! V_48 ) ;
F_32 ( V_48 -> V_89 != 1 ) ;
F_32 ( ! F_22 ( & V_2 -> V_157 ) ) ;
F_10 ( & V_14 ) ;
F_10 ( & V_117 ) ;
if ( V_48 -> V_4 & V_126 ) {
V_152 = F_93 ( V_48 , 0 , V_48 -> V_50 ) ;
F_32 ( V_152 ) ;
}
F_16 ( & V_28 ) ;
F_20 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_21 ( & V_25 -> V_31 ) ;
F_21 ( & V_25 -> V_32 ) ;
F_25 ( V_25 ) ;
}
F_18 ( & V_28 ) ;
if ( ! F_22 ( & V_48 -> V_162 ) ) {
F_21 ( & V_48 -> V_162 ) ;
V_57 -- ;
}
F_119 ( V_48 ) ;
F_11 ( & V_117 ) ;
F_11 ( & V_14 ) ;
F_69 ( & V_2 -> V_93 ) ;
F_143 ( V_69 ) ;
F_125 ( V_48 ) ;
}
int F_144 ( const struct V_1 * V_2 , char * V_202 , int V_203 )
{
int V_152 = - V_204 ;
char * V_164 ;
if ( ! V_2 -> V_6 ) {
if ( F_145 ( V_202 , L_27 , V_203 ) >= V_203 )
return - V_204 ;
return 0 ;
}
V_164 = V_202 + V_203 - 1 ;
* V_164 = '\0' ;
F_146 () ;
do {
const char * V_82 = V_81 ( V_2 ) ;
int V_84 ;
V_84 = strlen ( V_82 ) ;
if ( ( V_164 -= V_84 ) < V_202 )
goto V_205;
memcpy ( V_164 , V_82 , V_84 ) ;
if ( -- V_164 < V_202 )
goto V_205;
* V_164 = '/' ;
V_2 = V_2 -> V_6 ;
} while ( V_2 -> V_6 );
V_152 = 0 ;
memmove ( V_202 , V_164 , V_202 + V_203 - V_164 ) ;
V_205:
F_147 () ;
return V_152 ;
}
int F_148 ( struct V_61 * V_62 , char * V_202 , T_2 V_203 )
{
struct V_49 * V_48 ;
struct V_1 * V_2 ;
int V_167 = 1 , V_152 = 0 ;
if ( V_203 < 2 )
return - V_204 ;
F_10 ( & V_14 ) ;
V_48 = F_149 ( & V_166 , & V_167 ) ;
if ( V_48 ) {
V_2 = F_53 ( V_62 , V_48 ) ;
V_152 = F_144 ( V_2 , V_202 , V_203 ) ;
} else {
memcpy ( V_202 , L_27 , 2 ) ;
}
F_11 ( & V_14 ) ;
return V_152 ;
}
struct V_61 * F_150 ( struct V_206 * V_207 )
{
if ( V_207 -> V_208 ) {
V_207 -> V_209 = 0 ;
return F_151 ( V_207 ) ;
} else {
V_207 -> V_210 = V_207 -> V_211 . V_2 ;
return V_207 -> V_211 . V_62 ;
}
}
struct V_61 * F_151 ( struct V_206 * V_207 )
{
struct V_212 * V_213 ;
if ( ! V_207 -> V_208 || V_207 -> V_209 >= V_207 -> V_214 )
return NULL ;
V_213 = F_152 ( V_207 -> V_208 , V_207 -> V_209 ++ ) ;
V_207 -> V_210 = V_213 -> V_2 ;
return V_213 -> V_62 ;
}
struct V_1 * F_153 ( struct V_206 * V_207 )
{
return V_207 -> V_210 ;
}
int F_154 ( struct V_206 * V_207 )
{
return V_207 -> V_208 ? V_207 -> V_214 : 1 ;
}
static void F_155 ( struct V_1 * V_215 ,
struct V_61 * V_216 ,
struct V_21 * V_217 )
{
struct V_21 * V_35 ;
F_126 ( V_216 -> V_4 & V_218 ) ;
V_35 = F_55 ( V_216 ) ;
F_156 ( V_216 ) ;
F_157 ( V_216 -> V_219 , V_217 ) ;
F_158 ( V_216 ) ;
F_16 ( & V_28 ) ;
if ( ! F_22 ( & V_216 -> V_220 ) )
F_43 ( & V_216 -> V_220 , & V_217 -> V_58 ) ;
F_18 ( & V_28 ) ;
F_23 ( V_8 , & V_215 -> V_4 ) ;
F_29 ( V_35 ) ;
}
static int F_159 ( struct V_1 * V_2 , struct V_61 * V_216 ,
bool V_221 )
{
int V_222 , V_20 , V_223 ;
struct V_18 * V_19 , * V_224 = NULL ;
struct V_49 * V_48 = V_2 -> V_48 ;
struct V_61 * V_225 = V_216 ;
struct V_212 * V_213 ;
struct V_226 * V_227 ;
struct V_206 V_207 = { } ;
if ( V_221 )
V_223 = F_160 ( V_216 ) ;
else
V_223 = 1 ;
V_227 = F_161 ( sizeof( * V_213 ) , V_223 , V_54 ) ;
if ( ! V_227 )
return - V_55 ;
V_222 = F_162 ( V_227 , 0 , V_223 , V_54 ) ;
if ( V_222 )
goto V_228;
V_20 = 0 ;
F_146 () ;
do {
struct V_212 V_229 ;
if ( V_216 -> V_4 & V_218 )
continue;
F_32 ( V_20 >= V_223 ) ;
V_229 . V_62 = V_216 ;
V_229 . V_2 = F_53 ( V_216 , V_48 ) ;
if ( V_229 . V_2 == V_2 )
continue;
V_222 = F_163 ( V_227 , V_20 , & V_229 , V_230 ) ;
F_32 ( V_222 != 0 ) ;
V_20 ++ ;
if ( ! V_221 )
break;
} while_each_thread(leader, tsk) ;
int F_164 ( struct V_1 * V_2 , T_3 V_231 , bool V_221 )
{
struct V_61 * V_216 ;
const struct V_197 * V_197 = F_165 () , * V_232 ;
int V_152 ;
if ( ! F_9 ( V_2 ) )
return - V_233 ;
V_234:
F_146 () ;
if ( V_231 ) {
V_216 = F_166 ( V_231 ) ;
if ( ! V_216 ) {
F_147 () ;
V_152 = - V_235 ;
goto V_236;
}
V_232 = F_167 ( V_216 ) ;
if ( ! F_168 ( V_197 -> V_237 , V_238 ) &&
! F_168 ( V_197 -> V_237 , V_232 -> V_239 ) &&
! F_168 ( V_197 -> V_237 , V_232 -> V_240 ) ) {
F_147 () ;
V_152 = - V_241 ;
goto V_236;
}
} else
V_216 = V_154 ;
if ( V_221 )
V_216 = V_216 -> V_242 ;
if ( V_216 == V_243 || ( V_216 -> V_4 & V_244 ) ) {
V_152 = - V_144 ;
F_147 () ;
goto V_236;
}
F_169 ( V_216 ) ;
F_147 () ;
F_170 ( V_216 ) ;
if ( V_221 ) {
if ( ! F_171 ( V_216 ) ) {
F_172 ( V_216 ) ;
F_173 ( V_216 ) ;
goto V_234;
}
}
V_152 = F_159 ( V_2 , V_216 , V_221 ) ;
F_172 ( V_216 ) ;
F_173 ( V_216 ) ;
V_236:
F_11 ( & V_14 ) ;
return V_152 ;
}
int F_174 ( struct V_61 * V_245 , struct V_61 * V_216 )
{
struct V_49 * V_48 ;
int V_222 = 0 ;
F_10 ( & V_14 ) ;
F_137 (root) {
struct V_1 * V_246 = F_53 ( V_245 , V_48 ) ;
V_222 = F_159 ( V_246 , V_216 , false ) ;
if ( V_222 )
break;
}
F_11 ( & V_14 ) ;
return V_222 ;
}
static int F_175 ( struct V_1 * V_2 , struct V_13 * V_100 , T_3 V_231 )
{
return F_164 ( V_2 , V_231 , false ) ;
}
static int F_176 ( struct V_1 * V_2 , struct V_13 * V_100 , T_3 V_247 )
{
return F_164 ( V_2 , V_247 , true ) ;
}
static int F_177 ( struct V_1 * V_2 , struct V_13 * V_100 ,
const char * V_248 )
{
F_178 ( sizeof( V_2 -> V_48 -> V_132 ) < V_148 ) ;
if ( strlen ( V_248 ) >= V_148 )
return - V_144 ;
if ( ! F_9 ( V_2 ) )
return - V_233 ;
F_10 ( & V_117 ) ;
strcpy ( V_2 -> V_48 -> V_132 , V_248 ) ;
F_11 ( & V_117 ) ;
F_11 ( & V_14 ) ;
return 0 ;
}
static int F_179 ( struct V_1 * V_2 , struct V_13 * V_100 ,
struct V_127 * V_128 )
{
if ( ! F_9 ( V_2 ) )
return - V_233 ;
F_99 ( V_128 , V_2 -> V_48 -> V_132 ) ;
F_180 ( V_128 , '\n' ) ;
F_11 ( & V_14 ) ;
return 0 ;
}
static int F_181 ( struct V_1 * V_2 , struct V_13 * V_100 ,
struct V_127 * V_128 )
{
F_98 ( V_128 , L_28 , F_182 ( V_2 ) ) ;
return 0 ;
}
static T_4 F_183 ( struct V_1 * V_2 , struct V_13 * V_100 ,
struct V_249 * V_249 ,
const char T_5 * V_250 ,
T_2 V_251 , T_6 * V_252 )
{
char V_248 [ V_253 ] ;
int V_222 = 0 ;
char * V_165 ;
if ( ! V_251 )
return - V_144 ;
if ( V_251 >= sizeof( V_248 ) )
return - V_254 ;
if ( F_184 ( V_248 , V_250 , V_251 ) )
return - V_255 ;
V_248 [ V_251 ] = 0 ;
if ( V_100 -> V_256 ) {
T_3 V_257 = F_185 ( F_186 ( V_248 ) , & V_165 , 0 ) ;
if ( * V_165 )
return - V_144 ;
V_222 = V_100 -> V_256 ( V_2 , V_100 , V_257 ) ;
} else {
T_7 V_257 = F_187 ( F_186 ( V_248 ) , & V_165 , 0 ) ;
if ( * V_165 )
return - V_144 ;
V_222 = V_100 -> V_258 ( V_2 , V_100 , V_257 ) ;
}
if ( ! V_222 )
V_222 = V_251 ;
return V_222 ;
}
static T_4 F_188 ( struct V_1 * V_2 , struct V_13 * V_100 ,
struct V_249 * V_249 ,
const char T_5 * V_250 ,
T_2 V_251 , T_6 * V_252 )
{
char V_259 [ V_253 ] ;
int V_222 = 0 ;
T_2 V_260 = V_100 -> V_261 ;
char * V_248 = V_259 ;
if ( ! V_260 )
V_260 = sizeof( V_259 ) - 1 ;
if ( V_251 >= V_260 )
return - V_254 ;
if ( V_251 >= sizeof( V_259 ) ) {
V_248 = F_62 ( V_251 + 1 , V_54 ) ;
if ( V_248 == NULL )
return - V_55 ;
}
if ( V_251 && F_184 ( V_248 , V_250 , V_251 ) ) {
V_222 = - V_255 ;
goto V_205;
}
V_248 [ V_251 ] = 0 ;
V_222 = V_100 -> V_262 ( V_2 , V_100 , F_186 ( V_248 ) ) ;
if ( ! V_222 )
V_222 = V_251 ;
V_205:
if ( V_248 != V_259 )
F_25 ( V_248 ) ;
return V_222 ;
}
static T_4 F_189 ( struct V_249 * V_249 , const char T_5 * V_202 ,
T_2 V_251 , T_6 * V_263 )
{
struct V_13 * V_100 = F_8 ( V_249 -> V_264 ) ;
struct V_1 * V_2 = F_6 ( V_249 -> V_264 -> V_96 ) ;
if ( F_1 ( V_2 ) )
return - V_233 ;
if ( V_100 -> V_265 )
return V_100 -> V_265 ( V_2 , V_100 , V_249 , V_202 , V_251 , V_263 ) ;
if ( V_100 -> V_256 || V_100 -> V_258 )
return F_183 ( V_2 , V_100 , V_249 , V_202 , V_251 , V_263 ) ;
if ( V_100 -> V_262 )
return F_188 ( V_2 , V_100 , V_249 , V_202 , V_251 , V_263 ) ;
if ( V_100 -> V_266 ) {
int V_152 = V_100 -> V_266 ( V_2 , ( unsigned int ) V_100 -> V_267 ) ;
return V_152 ? V_152 : V_251 ;
}
return - V_144 ;
}
static T_4 F_190 ( struct V_1 * V_2 , struct V_13 * V_100 ,
struct V_249 * V_249 ,
char T_5 * V_202 , T_2 V_251 ,
T_6 * V_263 )
{
char V_268 [ V_253 ] ;
T_3 V_257 = V_100 -> V_269 ( V_2 , V_100 ) ;
int V_84 = sprintf ( V_268 , L_29 , ( unsigned long long ) V_257 ) ;
return F_191 ( V_202 , V_251 , V_263 , V_268 , V_84 ) ;
}
static T_4 F_192 ( struct V_1 * V_2 , struct V_13 * V_100 ,
struct V_249 * V_249 ,
char T_5 * V_202 , T_2 V_251 ,
T_6 * V_263 )
{
char V_268 [ V_253 ] ;
T_7 V_257 = V_100 -> V_270 ( V_2 , V_100 ) ;
int V_84 = sprintf ( V_268 , L_30 , ( long long ) V_257 ) ;
return F_191 ( V_202 , V_251 , V_263 , V_268 , V_84 ) ;
}
static T_4 F_193 ( struct V_249 * V_249 , char T_5 * V_202 ,
T_2 V_251 , T_6 * V_263 )
{
struct V_13 * V_100 = F_8 ( V_249 -> V_264 ) ;
struct V_1 * V_2 = F_6 ( V_249 -> V_264 -> V_96 ) ;
if ( F_1 ( V_2 ) )
return - V_233 ;
if ( V_100 -> V_271 )
return V_100 -> V_271 ( V_2 , V_100 , V_249 , V_202 , V_251 , V_263 ) ;
if ( V_100 -> V_269 )
return F_190 ( V_2 , V_100 , V_249 , V_202 , V_251 , V_263 ) ;
if ( V_100 -> V_270 )
return F_192 ( V_2 , V_100 , V_249 , V_202 , V_251 , V_263 ) ;
return - V_144 ;
}
static int F_194 ( struct V_272 * V_273 , const char * V_17 , T_3 V_274 )
{
struct V_127 * V_275 = V_273 -> V_276 ;
return F_98 ( V_275 , L_31 , V_17 , ( unsigned long long ) V_274 ) ;
}
static int F_195 ( struct V_127 * V_277 , void * V_278 )
{
struct V_279 * V_276 = V_277 -> V_267 ;
struct V_13 * V_100 = V_276 -> V_100 ;
if ( V_100 -> V_280 ) {
struct V_272 V_273 = {
. V_281 = F_194 ,
. V_276 = V_277 ,
} ;
return V_100 -> V_280 ( V_276 -> V_1 , V_100 , & V_273 ) ;
}
return V_100 -> V_282 ( V_276 -> V_1 , V_100 , V_277 ) ;
}
static int F_196 ( struct V_66 * V_66 , struct V_249 * V_249 )
{
struct V_127 * V_128 = V_249 -> V_283 ;
F_25 ( V_128 -> V_267 ) ;
return F_197 ( V_66 , V_249 ) ;
}
static int F_198 ( struct V_66 * V_66 , struct V_249 * V_249 )
{
int V_284 ;
struct V_13 * V_100 ;
V_284 = F_199 ( V_66 , V_249 ) ;
if ( V_284 )
return V_284 ;
V_100 = F_8 ( V_249 -> V_264 ) ;
if ( V_100 -> V_280 || V_100 -> V_282 ) {
struct V_279 * V_276 ;
V_276 = F_39 ( sizeof( * V_276 ) , V_285 ) ;
if ( ! V_276 )
return - V_55 ;
V_276 -> V_100 = V_100 ;
V_276 -> V_1 = F_6 ( V_249 -> V_264 -> V_96 ) ;
V_249 -> V_286 = & V_287 ;
V_284 = F_200 ( V_249 , F_195 , V_276 ) ;
if ( V_284 < 0 )
F_25 ( V_276 ) ;
} else if ( V_100 -> V_288 )
V_284 = V_100 -> V_288 ( V_66 , V_249 ) ;
else
V_284 = 0 ;
return V_284 ;
}
static int F_201 ( struct V_66 * V_66 , struct V_249 * V_249 )
{
struct V_13 * V_100 = F_8 ( V_249 -> V_264 ) ;
if ( V_100 -> V_289 )
return V_100 -> V_289 ( V_66 , V_249 ) ;
return 0 ;
}
static int F_202 ( struct V_66 * V_290 , struct V_10 * V_291 ,
struct V_66 * V_292 , struct V_10 * V_293 )
{
int V_152 ;
struct V_81 * V_82 , * V_294 ;
struct V_1 * V_2 ;
F_46 ( & V_290 -> V_101 ) ;
if ( ! F_75 ( V_291 -> V_99 -> V_71 ) )
return - V_295 ;
if ( V_293 -> V_99 )
return - V_296 ;
if ( V_290 != V_292 )
return - V_297 ;
V_2 = F_6 ( V_291 ) ;
if ( F_182 ( V_2 ) )
return - V_298 ;
V_82 = F_61 ( V_293 ) ;
if ( ! V_82 )
return - V_55 ;
V_152 = F_203 ( V_290 , V_291 , V_292 , V_293 ) ;
if ( V_152 ) {
F_25 ( V_82 ) ;
return V_152 ;
}
V_294 = F_204 ( V_2 -> V_82 , true ) ;
F_157 ( V_2 -> V_82 , V_82 ) ;
F_26 ( V_294 , V_34 ) ;
return 0 ;
}
static struct V_299 * F_205 ( struct V_10 * V_10 )
{
if ( F_75 ( V_10 -> V_99 -> V_71 ) )
return & F_6 ( V_10 ) -> V_93 ;
else
return & F_7 ( V_10 ) -> V_93 ;
}
static inline int F_206 ( struct V_10 * V_10 )
{
struct V_49 * V_48 = V_10 -> V_109 -> V_110 ;
return V_48 -> V_4 & V_131 ;
}
static bool F_207 ( const char * V_82 )
{
if ( ! strncmp ( V_82 , V_300 , V_301 ) ||
! strncmp ( V_82 , V_302 , V_303 ) )
return true ;
return false ;
}
static int F_208 ( struct V_10 * V_10 , const char * V_82 ,
const void * V_257 , T_2 V_304 , int V_4 )
{
if ( ! F_206 ( V_10 ) )
return - V_305 ;
if ( ! F_207 ( V_82 ) )
return - V_144 ;
return F_209 ( F_205 ( V_10 ) , V_82 , V_257 , V_304 , V_4 ) ;
}
static int F_210 ( struct V_10 * V_10 , const char * V_82 )
{
if ( ! F_206 ( V_10 ) )
return - V_305 ;
if ( ! F_207 ( V_82 ) )
return - V_144 ;
return F_211 ( F_205 ( V_10 ) , V_82 ) ;
}
static T_4 F_212 ( struct V_10 * V_10 , const char * V_82 ,
void * V_202 , T_2 V_304 )
{
if ( ! F_206 ( V_10 ) )
return - V_305 ;
if ( ! F_207 ( V_82 ) )
return - V_144 ;
return F_213 ( F_205 ( V_10 ) , V_82 , V_202 , V_304 ) ;
}
static T_4 F_214 ( struct V_10 * V_10 , char * V_202 , T_2 V_304 )
{
if ( ! F_206 ( V_10 ) )
return - V_305 ;
return F_215 ( F_205 ( V_10 ) , V_202 , V_304 ) ;
}
static inline struct V_13 * F_216 ( struct V_249 * V_249 )
{
if ( F_217 ( V_249 ) -> V_184 != & V_306 )
return F_123 ( - V_144 ) ;
return F_8 ( V_249 -> V_264 ) ;
}
static int F_218 ( struct V_10 * V_10 , T_1 V_67 ,
struct V_68 * V_69 )
{
struct V_66 * V_66 ;
if ( ! V_10 )
return - V_151 ;
if ( V_10 -> V_99 )
return - V_296 ;
V_66 = F_56 ( V_67 , V_69 ) ;
if ( ! V_66 )
return - V_55 ;
if ( F_75 ( V_67 ) ) {
V_66 -> V_186 = & V_187 ;
V_66 -> V_184 = & V_185 ;
F_131 ( V_66 ) ;
F_131 ( V_10 -> V_96 -> V_99 ) ;
F_126 ( ! F_219 ( & V_66 -> V_101 ) ) ;
} else if ( F_220 ( V_67 ) ) {
V_66 -> V_307 = 0 ;
V_66 -> V_184 = & V_306 ;
V_66 -> V_186 = & V_308 ;
}
F_221 ( V_10 , V_66 ) ;
F_81 ( V_10 ) ;
return 0 ;
}
static T_1 F_222 ( const struct V_13 * V_100 )
{
T_1 V_67 = 0 ;
if ( V_100 -> V_67 )
return V_100 -> V_67 ;
if ( V_100 -> V_271 || V_100 -> V_269 || V_100 -> V_270 ||
V_100 -> V_280 || V_100 -> V_282 )
V_67 |= V_181 ;
if ( V_100 -> V_265 || V_100 -> V_256 || V_100 -> V_258 ||
V_100 -> V_262 || V_100 -> V_266 )
V_67 |= V_183 ;
return V_67 ;
}
static int F_223 ( struct V_1 * V_2 , struct V_18 * V_41 ,
struct V_13 * V_100 )
{
struct V_10 * V_102 = V_2 -> V_10 ;
struct V_1 * V_6 = F_6 ( V_102 ) ;
struct V_10 * V_10 ;
struct V_12 * V_95 ;
int error ;
T_1 V_67 ;
char V_82 [ V_309 + V_310 + 2 ] = { 0 } ;
if ( V_41 && ! ( V_2 -> V_48 -> V_4 & V_130 ) ) {
strcpy ( V_82 , V_41 -> V_82 ) ;
strcat ( V_82 , L_32 ) ;
}
strcat ( V_82 , V_100 -> V_82 ) ;
F_32 ( ! F_54 ( & V_102 -> V_99 -> V_101 ) ) ;
V_95 = F_39 ( sizeof( * V_95 ) , V_54 ) ;
if ( ! V_95 )
return - V_55 ;
V_10 = F_224 ( V_82 , V_102 , strlen ( V_82 ) ) ;
if ( F_134 ( V_10 ) ) {
error = F_135 ( V_10 ) ;
goto V_205;
}
V_95 -> type = ( void * ) V_100 ;
V_95 -> V_10 = V_10 ;
V_10 -> V_11 = V_95 ;
F_114 ( & V_95 -> V_93 ) ;
V_67 = F_222 ( V_100 ) ;
error = F_218 ( V_10 , V_67 | V_311 , V_2 -> V_48 -> V_69 ) ;
if ( ! error ) {
F_44 ( & V_95 -> V_97 , & V_6 -> V_108 ) ;
V_95 = NULL ;
}
F_66 ( V_10 ) ;
V_205:
F_25 ( V_95 ) ;
return error ;
}
static int F_88 ( struct V_1 * V_2 , struct V_18 * V_41 ,
struct V_13 V_107 [] , bool V_312 )
{
struct V_13 * V_100 ;
int V_284 , V_152 = 0 ;
for ( V_100 = V_107 ; V_100 -> V_82 [ 0 ] != '\0' ; V_100 ++ ) {
if ( ( V_100 -> V_4 & V_313 ) && F_182 ( V_2 ) )
continue;
if ( ( V_100 -> V_4 & V_314 ) && ! V_2 -> V_6 )
continue;
if ( ( V_100 -> V_4 & V_315 ) && V_2 -> V_6 )
continue;
if ( V_312 ) {
V_284 = F_223 ( V_2 , V_41 , V_100 ) ;
if ( V_284 )
F_225 ( L_33 ,
V_100 -> V_82 , V_284 ) ;
V_152 = V_284 ;
} else {
F_84 ( V_2 , V_100 ) ;
}
}
return V_152 ;
}
static void F_226 ( void )
__acquires( &cgroup_mutex
static void F_227 ( struct V_18 * V_19 ,
struct V_13 * V_107 , bool V_312 )
__releases( &cgroup_mutex
int F_228 ( struct V_18 * V_19 , struct V_13 * V_107 )
{
struct V_104 * V_105 ;
V_105 = F_39 ( sizeof( * V_105 ) , V_54 ) ;
if ( ! V_105 )
return - V_55 ;
F_226 () ;
V_105 -> V_107 = V_107 ;
F_44 ( & V_105 -> V_97 , & V_19 -> V_316 ) ;
F_227 ( V_19 , V_107 , true ) ;
return 0 ;
}
int F_229 ( struct V_18 * V_19 , struct V_13 * V_107 )
{
struct V_104 * V_105 ;
F_226 () ;
F_51 (set, &ss->cftsets, node) {
if ( V_105 -> V_107 == V_107 ) {
F_21 ( & V_105 -> V_97 ) ;
F_25 ( V_105 ) ;
F_227 ( V_19 , V_107 , false ) ;
return 0 ;
}
}
F_227 ( V_19 , NULL , false ) ;
return - V_151 ;
}
int F_230 ( const struct V_1 * V_2 )
{
int V_52 = 0 ;
struct V_24 * V_25 ;
F_47 ( & V_28 ) ;
F_51 (link, &cgrp->cset_links, cset_link)
V_52 += F_231 ( & V_25 -> V_22 -> V_27 ) ;
F_48 ( & V_28 ) ;
return V_52 ;
}
static void F_232 ( struct V_1 * V_2 , struct V_317 * V_318 )
{
struct V_38 * V_319 = V_318 -> V_31 ;
struct V_24 * V_25 ;
struct V_21 * V_22 ;
do {
V_319 = V_319 -> V_47 ;
if ( V_319 == & V_2 -> V_33 ) {
V_318 -> V_31 = NULL ;
return;
}
V_25 = F_33 ( V_319 , struct V_24 , V_31 ) ;
V_22 = V_25 -> V_22 ;
} while ( F_22 ( & V_22 -> V_58 ) );
V_318 -> V_31 = V_319 ;
V_318 -> V_62 = V_22 -> V_58 . V_47 ;
}
static void F_233 ( void )
{
struct V_61 * V_320 , * V_321 ;
F_16 ( & V_28 ) ;
V_322 = 1 ;
F_47 ( & V_323 ) ;
F_234 (g, p) {
F_156 ( V_320 ) ;
if ( ! ( V_320 -> V_4 & V_218 ) && F_22 ( & V_320 -> V_220 ) )
F_40 ( & V_320 -> V_220 , & F_55 ( V_320 ) -> V_58 ) ;
F_158 ( V_320 ) ;
} F_235 ( V_321 , V_320 ) ;
F_48 ( & V_323 ) ;
F_18 ( & V_28 ) ;
}
struct V_1 * F_236 ( struct V_1 * V_324 )
{
struct V_1 * V_47 ;
F_126 ( ! F_237 () ) ;
if ( F_238 ( ! F_1 ( V_324 ) ) ) {
V_47 = F_239 ( V_324 -> V_122 . V_47 , struct V_1 , V_122 ) ;
if ( & V_47 -> V_122 != & V_324 -> V_6 -> V_157 )
return V_47 ;
return NULL ;
}
F_240 (next, &pos->parent->children, sibling)
if ( V_47 -> V_325 > V_324 -> V_325 )
return V_47 ;
return NULL ;
}
struct V_1 * F_241 ( struct V_1 * V_324 ,
struct V_1 * V_1 )
{
struct V_1 * V_47 ;
F_126 ( ! F_237 () ) ;
if ( ! V_324 )
V_324 = V_1 ;
V_47 = F_242 ( & V_324 -> V_157 , struct V_1 , V_122 ) ;
if ( V_47 )
return V_47 ;
while ( V_324 != V_1 ) {
V_47 = F_236 ( V_324 ) ;
if ( V_47 )
return V_47 ;
V_324 = V_324 -> V_6 ;
}
return NULL ;
}
struct V_1 * F_243 ( struct V_1 * V_324 )
{
struct V_1 * V_326 , * V_268 ;
F_126 ( ! F_237 () ) ;
do {
V_326 = V_324 ;
V_324 = NULL ;
F_240 (tmp, &last->children, sibling)
V_324 = V_268 ;
} while ( V_324 );
return V_326 ;
}
static struct V_1 * F_244 ( struct V_1 * V_324 )
{
struct V_1 * V_326 ;
do {
V_326 = V_324 ;
V_324 = F_242 ( & V_324 -> V_157 , struct V_1 ,
V_122 ) ;
} while ( V_324 );
return V_326 ;
}
struct V_1 * F_245 ( struct V_1 * V_324 ,
struct V_1 * V_1 )
{
struct V_1 * V_47 ;
F_126 ( ! F_237 () ) ;
if ( ! V_324 ) {
V_47 = F_244 ( V_1 ) ;
return V_47 != V_1 ? V_47 : NULL ;
}
V_47 = F_236 ( V_324 ) ;
if ( V_47 )
return F_244 ( V_47 ) ;
V_47 = V_324 -> V_6 ;
return V_47 != V_1 ? V_47 : NULL ;
}
void F_246 ( struct V_1 * V_2 , struct V_317 * V_318 )
__acquires( V_28 )
{
if ( ! V_322 )
F_233 () ;
F_47 ( & V_28 ) ;
V_318 -> V_31 = & V_2 -> V_33 ;
F_232 ( V_2 , V_318 ) ;
}
struct V_61 * F_247 ( struct V_1 * V_2 ,
struct V_317 * V_318 )
{
struct V_61 * V_63 ;
struct V_38 * V_319 = V_318 -> V_62 ;
struct V_24 * V_25 ;
if ( ! V_318 -> V_31 )
return NULL ;
V_63 = F_33 ( V_319 , struct V_61 , V_220 ) ;
V_319 = V_319 -> V_47 ;
V_25 = F_33 ( V_318 -> V_31 , struct V_24 , V_31 ) ;
if ( V_319 == & V_25 -> V_22 -> V_58 ) {
F_232 ( V_2 , V_318 ) ;
} else {
V_318 -> V_62 = V_319 ;
}
return V_63 ;
}
void F_248 ( struct V_1 * V_2 , struct V_317 * V_318 )
__releases( V_28 )
{
F_48 ( & V_28 ) ;
}
static inline int F_249 ( struct V_61 * V_327 ,
struct V_328 * time ,
struct V_61 * V_329 )
{
int V_330 = F_250 ( & V_327 -> V_331 , time ) ;
if ( V_330 > 0 ) {
return 1 ;
} else if ( V_330 < 0 ) {
return 0 ;
} else {
return V_327 > V_329 ;
}
}
static inline int F_251 ( void * V_332 , void * V_333 )
{
struct V_61 * V_327 = V_332 ;
struct V_61 * V_329 = V_333 ;
return F_249 ( V_327 , & V_329 -> V_331 , V_329 ) ;
}
int F_252 ( struct V_334 * V_335 )
{
int V_222 , V_20 ;
struct V_317 V_318 ;
struct V_61 * V_320 , * V_336 ;
struct V_61 * V_337 = NULL ;
struct V_338 V_339 ;
struct V_338 * V_340 ;
struct V_328 V_341 = { 0 , 0 } ;
if ( V_335 -> V_340 ) {
V_340 = V_335 -> V_340 ;
V_340 -> V_342 = & F_251 ;
} else {
V_340 = & V_339 ;
V_222 = F_253 ( V_340 , V_343 , V_54 , & F_251 ) ;
if ( V_222 )
return V_222 ;
}
V_344:
V_340 -> V_304 = 0 ;
F_246 ( V_335 -> V_345 , & V_318 ) ;
while ( ( V_320 = F_247 ( V_335 -> V_345 , & V_318 ) ) ) {
if ( V_335 -> V_346 && ! V_335 -> V_346 ( V_320 , V_335 ) )
continue;
if ( ! F_249 ( V_320 , & V_341 , V_337 ) )
continue;
V_336 = F_254 ( V_340 , V_320 ) ;
if ( V_336 == NULL ) {
F_169 ( V_320 ) ;
} else if ( V_336 != V_320 ) {
F_169 ( V_320 ) ;
F_173 ( V_336 ) ;
}
}
F_248 ( V_335 -> V_345 , & V_318 ) ;
if ( V_340 -> V_304 ) {
for ( V_20 = 0 ; V_20 < V_340 -> V_304 ; V_20 ++ ) {
struct V_61 * V_347 = V_340 -> V_348 [ V_20 ] ;
if ( V_20 == 0 ) {
V_341 = V_347 -> V_331 ;
V_337 = V_347 ;
}
V_335 -> V_349 ( V_347 , V_335 ) ;
F_173 ( V_347 ) ;
}
goto V_344;
}
if ( V_340 == & V_339 )
F_255 ( & V_339 ) ;
return 0 ;
}
static void F_256 ( struct V_61 * V_62 ,
struct V_334 * V_335 )
{
struct V_1 * V_350 = V_335 -> V_134 ;
F_10 ( & V_14 ) ;
F_159 ( V_350 , V_62 , false ) ;
F_11 ( & V_14 ) ;
}
int F_257 ( struct V_1 * V_351 , struct V_1 * V_245 )
{
struct V_334 V_335 ;
V_335 . V_345 = V_245 ;
V_335 . V_346 = NULL ;
V_335 . V_349 = F_256 ;
V_335 . V_340 = NULL ;
V_335 . V_134 = V_351 ;
return F_252 ( & V_335 ) ;
}
static void * F_258 ( int V_52 )
{
if ( F_259 ( V_52 ) )
return F_260 ( V_52 * sizeof( V_352 ) ) ;
else
return F_62 ( V_52 * sizeof( V_352 ) , V_54 ) ;
}
static void F_261 ( void * V_320 )
{
if ( F_262 ( V_320 ) )
F_263 ( V_320 ) ;
else
F_25 ( V_320 ) ;
}
static int F_264 ( V_352 * V_353 , int V_354 )
{
int V_355 , V_356 = 1 ;
if ( V_354 == 0 || V_354 == 1 )
return V_354 ;
for ( V_355 = 1 ; V_355 < V_354 ; V_355 ++ ) {
while ( V_353 [ V_355 ] == V_353 [ V_355 - 1 ] ) {
V_355 ++ ;
if ( V_355 == V_354 )
goto V_357;
}
V_353 [ V_356 ] = V_353 [ V_355 ] ;
V_356 ++ ;
}
V_357:
return V_356 ;
}
static int F_265 ( const void * V_358 , const void * V_359 )
{
return * ( V_352 * ) V_358 - * ( V_352 * ) V_359 ;
}
static struct V_360 * F_266 ( struct V_1 * V_2 ,
enum V_361 type )
{
struct V_360 * V_319 ;
struct V_362 * V_363 = F_267 ( V_154 ) ;
F_10 ( & V_2 -> V_159 ) ;
F_51 (l, &cgrp->pidlists, links) {
if ( V_319 -> V_17 . type == type && V_319 -> V_17 . V_363 == V_363 ) {
F_268 ( & V_319 -> V_364 ) ;
F_11 ( & V_2 -> V_159 ) ;
return V_319 ;
}
}
V_319 = F_39 ( sizeof( struct V_360 ) , V_54 ) ;
if ( ! V_319 ) {
F_11 ( & V_2 -> V_159 ) ;
return V_319 ;
}
F_269 ( & V_319 -> V_364 ) ;
F_268 ( & V_319 -> V_364 ) ;
V_319 -> V_17 . type = type ;
V_319 -> V_17 . V_363 = F_270 ( V_363 ) ;
V_319 -> V_365 = V_2 ;
F_40 ( & V_319 -> V_366 , & V_2 -> V_92 ) ;
F_11 ( & V_2 -> V_159 ) ;
return V_319 ;
}
static int F_271 ( struct V_1 * V_2 , enum V_361 type ,
struct V_360 * * V_367 )
{
V_352 * V_368 ;
int V_354 ;
int V_231 , V_369 = 0 ;
struct V_317 V_318 ;
struct V_61 * V_216 ;
struct V_360 * V_319 ;
V_354 = F_230 ( V_2 ) ;
V_368 = F_258 ( V_354 ) ;
if ( ! V_368 )
return - V_55 ;
F_246 ( V_2 , & V_318 ) ;
while ( ( V_216 = F_247 ( V_2 , & V_318 ) ) ) {
if ( F_272 ( V_369 == V_354 ) )
break;
if ( type == V_370 )
V_231 = F_273 ( V_216 ) ;
else
V_231 = F_274 ( V_216 ) ;
if ( V_231 > 0 )
V_368 [ V_369 ++ ] = V_231 ;
}
F_248 ( V_2 , & V_318 ) ;
V_354 = V_369 ;
F_275 ( V_368 , V_354 , sizeof( V_352 ) , F_265 , NULL ) ;
if ( type == V_370 )
V_354 = F_264 ( V_368 , V_354 ) ;
V_319 = F_266 ( V_2 , type ) ;
if ( ! V_319 ) {
F_261 ( V_368 ) ;
return - V_55 ;
}
F_261 ( V_319 -> V_353 ) ;
V_319 -> V_353 = V_368 ;
V_319 -> V_354 = V_354 ;
V_319 -> V_371 ++ ;
F_276 ( & V_319 -> V_364 ) ;
* V_367 = V_319 ;
return 0 ;
}
int F_277 ( struct V_372 * V_373 , struct V_10 * V_10 )
{
int V_152 = - V_144 ;
struct V_1 * V_2 ;
struct V_317 V_318 ;
struct V_61 * V_216 ;
if ( V_10 -> V_109 -> V_175 != & V_176 ||
! F_75 ( V_10 -> V_99 -> V_71 ) )
goto V_284;
V_152 = 0 ;
V_2 = V_10 -> V_11 ;
F_246 ( V_2 , & V_318 ) ;
while ( ( V_216 = F_247 ( V_2 , & V_318 ) ) ) {
switch ( V_216 -> V_276 ) {
case V_374 :
V_373 -> V_375 ++ ;
break;
case V_376 :
V_373 -> V_377 ++ ;
break;
case V_378 :
V_373 -> V_379 ++ ;
break;
case V_380 :
V_373 -> V_381 ++ ;
break;
default:
if ( F_278 ( V_216 ) )
V_373 -> V_382 ++ ;
break;
}
}
F_248 ( V_2 , & V_318 ) ;
V_284:
return V_152 ;
}
static void * F_279 ( struct V_127 * V_383 , T_6 * V_324 )
{
struct V_360 * V_319 = V_383 -> V_267 ;
int V_384 = 0 , V_231 = * V_324 ;
int * V_385 ;
F_280 ( & V_319 -> V_364 ) ;
if ( V_231 ) {
int V_165 = V_319 -> V_354 ;
while ( V_384 < V_165 ) {
int V_386 = ( V_384 + V_165 ) / 2 ;
if ( V_319 -> V_353 [ V_386 ] == V_231 ) {
V_384 = V_386 ;
break;
} else if ( V_319 -> V_353 [ V_386 ] <= V_231 )
V_384 = V_386 + 1 ;
else
V_165 = V_386 ;
}
}
if ( V_384 >= V_319 -> V_354 )
return NULL ;
V_385 = V_319 -> V_353 + V_384 ;
* V_324 = * V_385 ;
return V_385 ;
}
static void F_281 ( struct V_127 * V_383 , void * V_387 )
{
struct V_360 * V_319 = V_383 -> V_267 ;
F_282 ( & V_319 -> V_364 ) ;
}
static void * F_283 ( struct V_127 * V_383 , void * V_387 , T_6 * V_324 )
{
struct V_360 * V_319 = V_383 -> V_267 ;
V_352 * V_320 = V_387 ;
V_352 * V_165 = V_319 -> V_353 + V_319 -> V_354 ;
V_320 ++ ;
if ( V_320 >= V_165 ) {
return NULL ;
} else {
* V_324 = * V_320 ;
return V_320 ;
}
}
static int F_284 ( struct V_127 * V_383 , void * V_387 )
{
return F_98 ( V_383 , L_28 , * ( int * ) V_387 ) ;
}
static void F_285 ( struct V_360 * V_319 )
{
F_10 ( & V_319 -> V_365 -> V_159 ) ;
F_268 ( & V_319 -> V_364 ) ;
F_32 ( ! V_319 -> V_371 ) ;
if ( ! -- V_319 -> V_371 ) {
F_21 ( & V_319 -> V_366 ) ;
F_11 ( & V_319 -> V_365 -> V_159 ) ;
F_261 ( V_319 -> V_353 ) ;
F_286 ( V_319 -> V_17 . V_363 ) ;
F_276 ( & V_319 -> V_364 ) ;
F_25 ( V_319 ) ;
return;
}
F_11 ( & V_319 -> V_365 -> V_159 ) ;
F_276 ( & V_319 -> V_364 ) ;
}
static int F_287 ( struct V_66 * V_66 , struct V_249 * V_249 )
{
struct V_360 * V_319 ;
if ( ! ( V_249 -> V_388 & V_389 ) )
return 0 ;
V_319 = ( (struct V_127 * ) V_249 -> V_283 ) -> V_267 ;
F_285 ( V_319 ) ;
return F_288 ( V_66 , V_249 ) ;
}
static int F_289 ( struct V_249 * V_249 , enum V_361 type )
{
struct V_1 * V_2 = F_6 ( V_249 -> V_264 -> V_96 ) ;
struct V_360 * V_319 ;
int V_222 ;
if ( ! ( V_249 -> V_388 & V_389 ) )
return 0 ;
V_222 = F_271 ( V_2 , type , & V_319 ) ;
if ( V_222 )
return V_222 ;
V_249 -> V_286 = & V_390 ;
V_222 = F_290 ( V_249 , & V_391 ) ;
if ( V_222 ) {
F_285 ( V_319 ) ;
return V_222 ;
}
( (struct V_127 * ) V_249 -> V_283 ) -> V_267 = V_319 ;
return 0 ;
}
static int F_291 ( struct V_66 * V_392 , struct V_249 * V_249 )
{
return F_289 ( V_249 , V_393 ) ;
}
static int F_292 ( struct V_66 * V_392 , struct V_249 * V_249 )
{
return F_289 ( V_249 , V_370 ) ;
}
static T_3 F_293 ( struct V_1 * V_2 ,
struct V_13 * V_100 )
{
return F_5 ( V_2 ) ;
}
static int F_294 ( struct V_1 * V_2 ,
struct V_13 * V_100 ,
T_3 V_257 )
{
F_295 ( V_8 , & V_2 -> V_4 ) ;
if ( V_257 )
F_23 ( V_9 , & V_2 -> V_4 ) ;
else
F_295 ( V_9 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_296 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_48 -> V_69 ;
F_28 ( & V_69 -> V_394 ) ;
F_66 ( V_2 -> V_10 ) ;
F_68 ( V_69 ) ;
}
static void F_297 ( struct V_85 * V_86 )
{
struct V_395 * V_396 = F_64 ( V_86 , struct V_395 ,
remove ) ;
struct V_1 * V_2 = V_396 -> V_2 ;
F_298 ( V_396 -> V_397 , & V_396 -> V_398 ) ;
V_396 -> V_100 -> V_399 ( V_2 , V_396 -> V_100 , V_396 -> V_400 ) ;
F_299 ( V_396 -> V_400 , 1 ) ;
F_300 ( V_396 -> V_400 ) ;
F_25 ( V_396 ) ;
F_296 ( V_2 ) ;
}
static int F_301 ( T_8 * V_398 , unsigned V_67 ,
int V_401 , void * V_17 )
{
struct V_395 * V_396 = F_64 ( V_398 ,
struct V_395 , V_398 ) ;
struct V_1 * V_2 = V_396 -> V_2 ;
unsigned long V_4 = ( unsigned long ) V_17 ;
if ( V_4 & V_402 ) {
F_90 ( & V_2 -> V_161 ) ;
if ( ! F_22 ( & V_396 -> V_353 ) ) {
F_86 ( & V_396 -> V_353 ) ;
F_73 ( & V_396 -> remove ) ;
}
F_92 ( & V_2 -> V_161 ) ;
}
return 0 ;
}
static void F_302 ( struct V_249 * V_249 ,
T_9 * V_397 , T_10 * V_403 )
{
struct V_395 * V_396 = F_64 ( V_403 ,
struct V_395 , V_403 ) ;
V_396 -> V_397 = V_397 ;
F_303 ( V_397 , & V_396 -> V_398 ) ;
}
static int F_304 ( struct V_1 * V_2 , struct V_13 * V_100 ,
const char * V_248 )
{
struct V_395 * V_396 = NULL ;
struct V_1 * V_404 ;
unsigned int V_405 , V_406 ;
struct V_249 * V_407 = NULL ;
struct V_249 * V_408 = NULL ;
char * V_409 ;
int V_152 ;
V_405 = F_305 ( V_248 , & V_409 , 10 ) ;
if ( * V_409 != ' ' )
return - V_144 ;
V_248 = V_409 + 1 ;
V_406 = F_305 ( V_248 , & V_409 , 10 ) ;
if ( ( * V_409 != ' ' ) && ( * V_409 != '\0' ) )
return - V_144 ;
V_248 = V_409 + 1 ;
V_396 = F_39 ( sizeof( * V_396 ) , V_54 ) ;
if ( ! V_396 )
return - V_55 ;
V_396 -> V_2 = V_2 ;
F_38 ( & V_396 -> V_353 ) ;
F_306 ( & V_396 -> V_403 , F_302 ) ;
F_307 ( & V_396 -> V_398 , F_301 ) ;
F_72 ( & V_396 -> remove , F_297 ) ;
V_407 = F_308 ( V_405 ) ;
if ( F_134 ( V_407 ) ) {
V_152 = F_135 ( V_407 ) ;
goto V_410;
}
V_396 -> V_400 = F_309 ( V_407 ) ;
if ( F_134 ( V_396 -> V_400 ) ) {
V_152 = F_135 ( V_396 -> V_400 ) ;
goto V_410;
}
V_408 = F_310 ( V_406 ) ;
if ( ! V_408 ) {
V_152 = - V_411 ;
goto V_410;
}
V_152 = F_311 ( F_217 ( V_408 ) , V_412 ) ;
if ( V_152 < 0 )
goto V_410;
V_396 -> V_100 = F_216 ( V_408 ) ;
if ( F_134 ( V_396 -> V_100 ) ) {
V_152 = F_135 ( V_396 -> V_100 ) ;
goto V_410;
}
V_404 = F_6 ( V_408 -> V_264 -> V_96 ) ;
if ( V_404 != V_2 ) {
V_152 = - V_144 ;
goto V_410;
}
if ( ! V_396 -> V_100 -> V_413 || ! V_396 -> V_100 -> V_399 ) {
V_152 = - V_144 ;
goto V_410;
}
V_152 = V_396 -> V_100 -> V_413 ( V_2 , V_396 -> V_100 ,
V_396 -> V_400 , V_248 ) ;
if ( V_152 )
goto V_410;
V_407 -> V_286 -> V_414 ( V_407 , & V_396 -> V_403 ) ;
F_81 ( V_2 -> V_10 ) ;
F_90 ( & V_2 -> V_161 ) ;
F_40 ( & V_396 -> V_353 , & V_2 -> V_160 ) ;
F_92 ( & V_2 -> V_161 ) ;
F_312 ( V_408 ) ;
F_312 ( V_407 ) ;
return 0 ;
V_410:
if ( V_408 )
F_312 ( V_408 ) ;
if ( V_396 && V_396 -> V_400 && ! F_134 ( V_396 -> V_400 ) )
F_300 ( V_396 -> V_400 ) ;
if ( ! F_313 ( V_407 ) )
F_312 ( V_407 ) ;
F_25 ( V_396 ) ;
return V_152 ;
}
static T_3 F_314 ( struct V_1 * V_2 ,
struct V_13 * V_100 )
{
return F_2 ( V_133 , & V_2 -> V_4 ) ;
}
static int F_315 ( struct V_1 * V_2 ,
struct V_13 * V_100 ,
T_3 V_257 )
{
if ( V_257 )
F_23 ( V_133 , & V_2 -> V_4 ) ;
else
F_295 ( V_133 , & V_2 -> V_4 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , bool V_103 ,
unsigned long V_50 )
{
int V_284 ;
struct V_18 * V_19 ;
if ( V_103 ) {
V_284 = F_88 ( V_2 , NULL , V_415 , true ) ;
if ( V_284 < 0 )
return V_284 ;
}
F_65 (cgrp->root, ss) {
struct V_104 * V_105 ;
if ( ! F_2 ( V_19 -> V_106 , & V_50 ) )
continue;
F_51 (set, &ss->cftsets, node)
F_88 ( V_2 , V_19 , V_105 -> V_107 , true ) ;
}
F_65 (cgrp->root, ss) {
struct V_15 * V_16 = V_2 -> V_41 [ V_19 -> V_106 ] ;
struct V_416 * V_91 = F_204 ( V_16 -> V_91 , true ) ;
if ( V_91 )
F_157 ( V_91 -> V_16 , V_16 ) ;
}
return 0 ;
}
static void F_316 ( struct V_85 * V_86 )
{
struct V_15 * V_16 =
F_64 ( V_86 , struct V_15 , V_417 ) ;
F_296 ( V_16 -> V_1 ) ;
}
static void F_317 ( struct V_418 * V_419 )
{
struct V_15 * V_16 =
F_64 ( V_419 , struct V_15 , V_420 ) ;
F_73 ( & V_16 -> V_417 ) ;
}
static void F_318 ( struct V_15 * V_16 ,
struct V_18 * V_19 ,
struct V_1 * V_2 )
{
V_16 -> V_1 = V_2 ;
V_16 -> V_4 = 0 ;
V_16 -> V_91 = NULL ;
if ( V_2 == V_121 )
V_16 -> V_4 |= V_421 ;
F_32 ( V_2 -> V_41 [ V_19 -> V_106 ] ) ;
V_2 -> V_41 [ V_19 -> V_106 ] = V_16 ;
F_72 ( & V_16 -> V_417 , F_316 ) ;
}
static int F_319 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
int V_152 = 0 ;
F_46 ( & V_14 ) ;
if ( V_19 -> V_422 )
V_152 = V_19 -> V_422 ( V_2 ) ;
if ( ! V_152 )
V_2 -> V_41 [ V_19 -> V_106 ] -> V_4 |= V_423 ;
return V_152 ;
}
static void F_320 ( struct V_18 * V_19 , struct V_1 * V_2 )
__releases( &cgroup_mutex
static long F_321 ( struct V_1 * V_6 , struct V_10 * V_10 ,
T_1 V_67 )
{
struct V_1 * V_2 ;
struct V_81 * V_82 ;
struct V_49 * V_48 = V_6 -> V_48 ;
int V_284 = 0 ;
struct V_18 * V_19 ;
struct V_68 * V_69 = V_48 -> V_69 ;
V_2 = F_39 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
V_82 = F_61 ( V_10 ) ;
if ( ! V_82 )
goto V_424;
F_157 ( V_2 -> V_82 , V_82 ) ;
V_2 -> V_91 = F_322 ( & V_48 -> V_90 , 1 , 0 , V_54 ) ;
if ( V_2 -> V_91 < 0 )
goto V_425;
if ( ! F_9 ( V_6 ) ) {
V_284 = - V_233 ;
goto V_426;
}
F_28 ( & V_69 -> V_394 ) ;
F_111 ( V_2 ) ;
V_10 -> V_11 = V_2 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_48 = V_6 -> V_48 ;
if ( F_5 ( V_6 ) )
F_23 ( V_9 , & V_2 -> V_4 ) ;
if ( F_2 ( V_133 , & V_6 -> V_4 ) )
F_23 ( V_133 , & V_2 -> V_4 ) ;
F_65 (root, ss) {
struct V_15 * V_16 ;
V_16 = V_19 -> V_427 ( V_2 ) ;
if ( F_134 ( V_16 ) ) {
V_284 = F_135 ( V_16 ) ;
goto V_428;
}
V_284 = F_323 ( & V_16 -> V_420 , F_317 ) ;
if ( V_284 ) {
V_19 -> V_88 ( V_2 ) ;
goto V_428;
}
F_318 ( V_16 , V_19 , V_2 ) ;
if ( V_19 -> V_429 ) {
V_284 = F_324 ( V_19 , V_6 , V_2 ) ;
if ( V_284 )
goto V_428;
}
}
V_284 = F_218 ( V_10 , V_180 | V_67 , V_69 ) ;
if ( V_284 < 0 )
goto V_428;
F_46 ( & V_10 -> V_99 -> V_101 ) ;
V_2 -> V_325 = V_430 ++ ;
F_325 ( & V_2 -> V_122 , & V_2 -> V_6 -> V_157 ) ;
V_48 -> V_89 ++ ;
F_65 (root, ss)
F_81 ( V_10 ) ;
F_81 ( V_6 -> V_10 ) ;
F_65 (root, ss) {
V_284 = F_319 ( V_19 , V_2 ) ;
if ( V_284 )
goto V_431;
if ( V_19 -> V_432 && ! V_19 -> V_433 &&
V_6 -> V_6 ) {
F_104 ( L_34 ,
V_154 -> V_155 , V_154 -> V_231 , V_19 -> V_82 ) ;
if ( ! strcmp ( V_19 -> V_82 , L_35 ) )
F_104 ( L_36 ) ;
V_19 -> V_433 = true ;
}
}
V_284 = F_110 ( V_2 , true , V_48 -> V_50 ) ;
if ( V_284 )
goto V_431;
F_11 ( & V_14 ) ;
F_11 ( & V_2 -> V_10 -> V_99 -> V_101 ) ;
return 0 ;
V_428:
F_65 (root, ss) {
struct V_15 * V_16 = V_2 -> V_41 [ V_19 -> V_106 ] ;
if ( V_16 ) {
F_326 ( & V_16 -> V_420 ) ;
V_19 -> V_88 ( V_2 ) ;
}
}
F_11 ( & V_14 ) ;
F_68 ( V_69 ) ;
V_426:
F_67 ( & V_48 -> V_90 , V_2 -> V_91 ) ;
V_425:
F_25 ( F_70 ( V_2 -> V_82 ) ) ;
V_424:
F_25 ( V_2 ) ;
return V_284 ;
V_431:
F_327 ( V_2 ) ;
F_11 ( & V_14 ) ;
F_11 ( & V_10 -> V_99 -> V_101 ) ;
return V_284 ;
}
static int F_328 ( struct V_66 * V_102 , struct V_10 * V_10 , T_1 V_67 )
{
struct V_1 * V_434 = V_10 -> V_96 -> V_11 ;
return F_321 ( V_434 , V_10 , V_67 | V_180 ) ;
}
static void F_329 ( struct V_1 * V_2 )
{
if ( ! F_17 ( & V_2 -> V_435 ) )
return;
F_72 ( & V_2 -> V_87 , V_436 ) ;
F_73 ( & V_2 -> V_87 ) ;
}
static void F_330 ( struct V_418 * V_419 )
{
struct V_15 * V_16 =
F_64 ( V_419 , struct V_15 , V_420 ) ;
F_329 ( V_16 -> V_1 ) ;
}
static int F_327 ( struct V_1 * V_2 )
__releases( &cgroup_mutex
static void V_436 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = F_64 ( V_86 , struct V_1 , V_87 ) ;
struct V_1 * V_6 = V_2 -> V_6 ;
struct V_10 * V_98 = V_2 -> V_10 ;
struct V_18 * V_19 ;
F_10 ( & V_14 ) ;
F_65 (cgrp->root, ss)
F_320 ( V_19 , V_2 ) ;
F_65 (cgrp->root, ss)
F_331 ( V_2 -> V_41 [ V_19 -> V_106 ] ) ;
F_332 ( & V_2 -> V_122 ) ;
F_66 ( V_98 ) ;
F_23 ( V_8 , & V_6 -> V_4 ) ;
F_24 ( V_6 ) ;
F_11 ( & V_14 ) ;
}
static int F_333 ( struct V_66 * V_437 , struct V_10 * V_10 )
{
int V_152 ;
F_10 ( & V_14 ) ;
V_152 = F_327 ( V_10 -> V_11 ) ;
F_11 ( & V_14 ) ;
return V_152 ;
}
static void T_11 F_334 ( struct V_18 * V_19 )
{
F_38 ( & V_19 -> V_316 ) ;
if ( V_19 -> V_438 ) {
V_19 -> V_439 . V_107 = V_19 -> V_438 ;
F_44 ( & V_19 -> V_439 . V_97 , & V_19 -> V_316 ) ;
}
}
static void T_12 F_335 ( struct V_18 * V_19 )
{
struct V_15 * V_16 ;
F_336 ( V_440 L_37 , V_19 -> V_82 ) ;
F_10 ( & V_14 ) ;
F_334 ( V_19 ) ;
F_40 ( & V_19 -> V_122 , & V_119 . V_123 ) ;
V_19 -> V_48 = & V_119 ;
V_16 = V_19 -> V_427 ( V_121 ) ;
F_32 ( F_134 ( V_16 ) ) ;
F_318 ( V_16 , V_19 , V_121 ) ;
V_64 . V_41 [ V_19 -> V_106 ] = V_16 ;
V_441 |= V_19 -> V_442 || V_19 -> exit ;
F_32 ( ! F_22 ( & V_443 . V_58 ) ) ;
F_32 ( F_319 ( V_19 , V_121 ) ) ;
F_11 ( & V_14 ) ;
F_32 ( V_19 -> V_125 ) ;
}
int T_11 F_337 ( struct V_18 * V_19 )
{
struct V_15 * V_16 ;
int V_20 , V_152 ;
struct V_444 * V_268 ;
struct V_21 * V_22 ;
unsigned long V_17 ;
if ( V_19 -> V_82 == NULL || strlen ( V_19 -> V_82 ) > V_309 ||
V_19 -> V_427 == NULL || V_19 -> V_88 == NULL )
return - V_144 ;
if ( V_19 -> V_442 || V_19 -> exit )
return - V_144 ;
if ( V_19 -> V_125 == NULL ) {
F_32 ( V_18 [ V_19 -> V_106 ] != V_19 ) ;
return 0 ;
}
F_334 ( V_19 ) ;
F_10 ( & V_14 ) ;
V_18 [ V_19 -> V_106 ] = V_19 ;
V_16 = V_19 -> V_427 ( V_121 ) ;
if ( F_134 ( V_16 ) ) {
V_18 [ V_19 -> V_106 ] = NULL ;
F_11 ( & V_14 ) ;
return F_135 ( V_16 ) ;
}
F_40 ( & V_19 -> V_122 , & V_119 . V_123 ) ;
V_19 -> V_48 = & V_119 ;
F_318 ( V_16 , V_19 , V_121 ) ;
if ( V_19 -> V_429 ) {
V_152 = F_338 ( V_19 , V_16 ) ;
if ( V_152 )
goto V_445;
}
F_16 ( & V_28 ) ;
F_339 (css_set_table, i, tmp, cset, hlist) {
if ( V_22 -> V_41 [ V_19 -> V_106 ] )
continue;
F_19 ( & V_22 -> V_29 ) ;
V_22 -> V_41 [ V_19 -> V_106 ] = V_16 ;
V_17 = F_12 ( V_22 -> V_41 ) ;
F_52 ( V_60 , & V_22 -> V_29 , V_17 ) ;
}
F_18 ( & V_28 ) ;
V_152 = F_319 ( V_19 , V_121 ) ;
if ( V_152 )
goto V_445;
F_11 ( & V_14 ) ;
return 0 ;
V_445:
F_11 ( & V_14 ) ;
F_340 ( V_19 ) ;
return V_152 ;
}
void F_340 ( struct V_18 * V_19 )
{
struct V_24 * V_25 ;
F_32 ( V_19 -> V_125 == NULL ) ;
F_32 ( V_19 -> V_48 != & V_119 ) ;
F_10 ( & V_14 ) ;
F_320 ( V_19 , V_121 ) ;
if ( V_19 -> V_429 )
F_341 ( & V_19 -> V_446 ) ;
V_18 [ V_19 -> V_106 ] = NULL ;
F_86 ( & V_19 -> V_122 ) ;
F_16 ( & V_28 ) ;
F_51 (link, &cgroup_dummy_top->cset_links, cset_link) {
struct V_21 * V_22 = V_25 -> V_22 ;
unsigned long V_17 ;
F_19 ( & V_22 -> V_29 ) ;
V_22 -> V_41 [ V_19 -> V_106 ] = NULL ;
V_17 = F_12 ( V_22 -> V_41 ) ;
F_52 ( V_60 , & V_22 -> V_29 , V_17 ) ;
}
F_18 ( & V_28 ) ;
V_19 -> V_88 ( V_121 ) ;
V_121 -> V_41 [ V_19 -> V_106 ] = NULL ;
F_11 ( & V_14 ) ;
}
int T_12 F_342 ( void )
{
struct V_18 * V_19 ;
int V_20 ;
F_49 ( & V_64 . V_27 , 1 ) ;
F_38 ( & V_64 . V_42 ) ;
F_38 ( & V_64 . V_58 ) ;
F_50 ( & V_64 . V_29 ) ;
V_30 = 1 ;
F_115 ( & V_119 ) ;
V_57 = 1 ;
F_116 ( V_443 . V_219 , & V_64 ) ;
V_447 . V_22 = & V_64 ;
V_447 . V_2 = V_121 ;
F_40 ( & V_447 . V_31 , & V_121 -> V_33 ) ;
F_40 ( & V_447 . V_32 , & V_64 . V_42 ) ;
F_343 (ss, i) {
F_32 ( ! V_19 -> V_82 ) ;
F_32 ( strlen ( V_19 -> V_82 ) > V_309 ) ;
F_32 ( ! V_19 -> V_427 ) ;
F_32 ( ! V_19 -> V_88 ) ;
if ( V_19 -> V_106 != V_20 ) {
F_336 ( V_448 L_38 ,
V_19 -> V_82 , V_19 -> V_106 ) ;
F_344 () ;
}
if ( V_19 -> V_449 )
F_335 ( V_19 ) ;
}
return 0 ;
}
int T_12 F_345 ( void )
{
struct V_18 * V_19 ;
unsigned long V_17 ;
int V_20 , V_284 ;
V_284 = F_346 ( & V_80 ) ;
if ( V_284 )
return V_284 ;
F_343 (ss, i) {
if ( ! V_19 -> V_449 )
F_335 ( V_19 ) ;
if ( V_19 -> V_429 )
F_338 ( V_19 , V_64 . V_41 [ V_19 -> V_106 ] ) ;
}
F_10 ( & V_14 ) ;
F_10 ( & V_117 ) ;
V_17 = F_12 ( V_64 . V_41 ) ;
F_52 ( V_60 , & V_64 . V_29 , V_17 ) ;
F_32 ( F_117 ( & V_119 , 0 , 1 ) ) ;
F_11 ( & V_117 ) ;
F_11 ( & V_14 ) ;
V_450 = F_347 ( L_39 , V_451 ) ;
if ( ! V_450 ) {
V_284 = - V_55 ;
goto V_205;
}
V_284 = F_348 ( & V_452 ) ;
if ( V_284 < 0 ) {
F_349 ( V_450 ) ;
goto V_205;
}
F_350 ( L_40 , 0 , NULL , & V_453 ) ;
V_205:
if ( V_284 )
F_351 ( & V_80 ) ;
return V_284 ;
}
int F_352 ( struct V_127 * V_277 , void * V_387 )
{
struct V_231 * V_231 ;
struct V_61 * V_216 ;
char * V_202 ;
int V_222 ;
struct V_49 * V_48 ;
V_222 = - V_55 ;
V_202 = F_62 ( V_343 , V_54 ) ;
if ( ! V_202 )
goto V_205;
V_222 = - V_235 ;
V_231 = V_277 -> V_267 ;
V_216 = F_353 ( V_231 , V_454 ) ;
if ( ! V_216 )
goto V_455;
V_222 = 0 ;
F_10 ( & V_14 ) ;
F_137 (root) {
struct V_18 * V_19 ;
struct V_1 * V_2 ;
int V_52 = 0 ;
F_98 ( V_277 , L_41 , V_48 -> V_167 ) ;
F_65 (root, ss)
F_98 ( V_277 , L_42 , V_52 ++ ? L_9 : L_24 , V_19 -> V_82 ) ;
if ( strlen ( V_48 -> V_82 ) )
F_98 ( V_277 , L_43 , V_52 ? L_9 : L_24 ,
V_48 -> V_82 ) ;
F_180 ( V_277 , ':' ) ;
V_2 = F_53 ( V_216 , V_48 ) ;
V_222 = F_144 ( V_2 , V_202 , V_343 ) ;
if ( V_222 < 0 )
goto V_153;
F_99 ( V_277 , V_202 ) ;
F_180 ( V_277 , '\n' ) ;
}
V_153:
F_11 ( & V_14 ) ;
F_173 ( V_216 ) ;
V_455:
F_25 ( V_202 ) ;
V_205:
return V_222 ;
}
static int F_354 ( struct V_127 * V_277 , void * V_387 )
{
struct V_18 * V_19 ;
int V_20 ;
F_99 ( V_277 , L_44 ) ;
F_10 ( & V_14 ) ;
F_13 (ss, i)
F_98 ( V_277 , L_45 ,
V_19 -> V_82 , V_19 -> V_48 -> V_167 ,
V_19 -> V_48 -> V_89 , ! V_19 -> V_150 ) ;
F_11 ( & V_14 ) ;
return 0 ;
}
static int F_355 ( struct V_66 * V_66 , struct V_249 * V_249 )
{
return F_200 ( V_249 , F_354 , NULL ) ;
}
void F_356 ( struct V_61 * V_456 )
{
F_156 ( V_154 ) ;
F_27 ( F_55 ( V_154 ) ) ;
V_456 -> V_219 = V_154 -> V_219 ;
F_158 ( V_154 ) ;
F_38 ( & V_456 -> V_220 ) ;
}
void F_357 ( struct V_61 * V_456 )
{
struct V_18 * V_19 ;
int V_20 ;
if ( V_322 ) {
F_16 ( & V_28 ) ;
F_156 ( V_456 ) ;
if ( F_22 ( & V_456 -> V_220 ) )
F_40 ( & V_456 -> V_220 , & F_55 ( V_456 ) -> V_58 ) ;
F_158 ( V_456 ) ;
F_18 ( & V_28 ) ;
}
if ( V_441 ) {
F_343 (ss, i)
if ( V_19 -> V_442 )
V_19 -> V_442 ( V_456 ) ;
}
}
void F_358 ( struct V_61 * V_216 , int V_457 )
{
struct V_18 * V_19 ;
struct V_21 * V_22 ;
int V_20 ;
if ( ! F_22 ( & V_216 -> V_220 ) ) {
F_16 ( & V_28 ) ;
if ( ! F_22 ( & V_216 -> V_220 ) )
F_86 ( & V_216 -> V_220 ) ;
F_18 ( & V_28 ) ;
}
F_156 ( V_216 ) ;
V_22 = F_55 ( V_216 ) ;
F_116 ( V_216 -> V_219 , & V_64 ) ;
if ( V_457 && V_441 ) {
F_343 (ss, i) {
if ( V_19 -> exit ) {
struct V_1 * V_215 = V_22 -> V_41 [ V_20 ] -> V_1 ;
struct V_1 * V_2 = F_359 ( V_216 , V_20 ) ;
V_19 -> exit ( V_2 , V_215 , V_216 ) ;
}
}
}
F_158 ( V_216 ) ;
F_30 ( V_22 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 ) &&
F_22 ( & V_2 -> V_33 ) && F_22 ( & V_2 -> V_157 ) ) {
int V_458 = 0 ;
F_360 ( & V_459 ) ;
if ( ! F_1 ( V_2 ) &&
F_22 ( & V_2 -> V_158 ) ) {
F_40 ( & V_2 -> V_158 , & V_158 ) ;
V_458 = 1 ;
}
F_361 ( & V_459 ) ;
if ( V_458 )
F_73 ( & V_460 ) ;
}
}
static void F_362 ( struct V_85 * V_86 )
{
F_32 ( V_86 != & V_460 ) ;
F_10 ( & V_14 ) ;
F_360 ( & V_459 ) ;
while ( ! F_22 ( & V_158 ) ) {
char * V_461 [ 3 ] , * V_462 [ 3 ] ;
int V_20 ;
char * V_463 = NULL , * V_464 = NULL ;
struct V_1 * V_2 = F_33 ( V_158 . V_47 ,
struct V_1 ,
V_158 ) ;
F_86 ( & V_2 -> V_158 ) ;
F_361 ( & V_459 ) ;
V_463 = F_62 ( V_343 , V_54 ) ;
if ( ! V_463 )
goto V_465;
if ( F_144 ( V_2 , V_463 , V_343 ) < 0 )
goto V_465;
V_464 = F_363 ( V_2 -> V_48 -> V_132 , V_54 ) ;
if ( ! V_464 )
goto V_465;
V_20 = 0 ;
V_461 [ V_20 ++ ] = V_464 ;
V_461 [ V_20 ++ ] = V_463 ;
V_461 [ V_20 ] = NULL ;
V_20 = 0 ;
V_462 [ V_20 ++ ] = L_46 ;
V_462 [ V_20 ++ ] = L_47 ;
V_462 [ V_20 ] = NULL ;
F_11 ( & V_14 ) ;
F_364 ( V_461 [ 0 ] , V_461 , V_462 , V_466 ) ;
F_10 ( & V_14 ) ;
V_465:
F_25 ( V_463 ) ;
F_25 ( V_464 ) ;
F_360 ( & V_459 ) ;
}
F_361 ( & V_459 ) ;
F_11 ( & V_14 ) ;
}
static int T_12 F_365 ( char * V_467 )
{
struct V_18 * V_19 ;
char * V_137 ;
int V_20 ;
while ( ( V_137 = F_102 ( & V_467 , L_9 ) ) != NULL ) {
if ( ! * V_137 )
continue;
F_343 (ss, i) {
if ( ! strcmp ( V_137 , V_19 -> V_82 ) ) {
V_19 -> V_150 = 1 ;
F_336 ( V_440 L_48
L_49 , V_19 -> V_82 ) ;
break;
}
}
}
return 1 ;
}
unsigned short V_416 ( struct V_15 * V_16 )
{
struct V_416 * V_468 ;
V_468 = F_70 ( V_16 -> V_91 ) ;
if ( V_468 )
return V_468 -> V_91 ;
return 0 ;
}
bool F_366 ( struct V_15 * V_456 ,
const struct V_15 * V_48 )
{
struct V_416 * V_469 ;
struct V_416 * V_470 ;
V_469 = F_367 ( V_456 -> V_91 ) ;
if ( ! V_469 )
return false ;
V_470 = F_367 ( V_48 -> V_91 ) ;
if ( ! V_470 )
return false ;
if ( V_469 -> V_471 < V_470 -> V_471 )
return false ;
if ( V_469 -> V_472 [ V_470 -> V_471 ] != V_470 -> V_91 )
return false ;
return true ;
}
void F_368 ( struct V_18 * V_19 , struct V_15 * V_16 )
{
struct V_416 * V_91 = F_204 ( V_16 -> V_91 , true ) ;
if ( ! V_91 )
return;
F_32 ( ! V_19 -> V_429 ) ;
F_157 ( V_91 -> V_16 , NULL ) ;
F_157 ( V_16 -> V_91 , NULL ) ;
F_90 ( & V_19 -> V_473 ) ;
F_120 ( & V_19 -> V_446 , V_91 -> V_91 ) ;
F_92 ( & V_19 -> V_473 ) ;
F_26 ( V_91 , V_34 ) ;
}
static struct V_416 * F_369 ( struct V_18 * V_19 , int V_471 )
{
struct V_416 * V_474 ;
int V_152 , V_304 ;
F_32 ( ! V_19 -> V_429 ) ;
V_304 = sizeof( * V_474 ) + sizeof( unsigned short ) * ( V_471 + 1 ) ;
V_474 = F_39 ( V_304 , V_54 ) ;
if ( ! V_474 )
return F_123 ( - V_55 ) ;
F_370 ( V_54 ) ;
F_90 ( & V_19 -> V_473 ) ;
V_152 = F_371 ( & V_19 -> V_446 , V_474 , 1 , V_475 + 1 , V_476 ) ;
F_92 ( & V_19 -> V_473 ) ;
F_372 () ;
if ( V_152 < 0 )
goto V_477;
V_474 -> V_91 = V_152 ;
V_474 -> V_471 = V_471 ;
return V_474 ;
V_477:
F_25 ( V_474 ) ;
return F_123 ( V_152 ) ;
}
static int T_11 F_338 ( struct V_18 * V_19 ,
struct V_15 * V_478 )
{
struct V_416 * V_474 ;
F_113 ( & V_19 -> V_473 ) ;
F_373 ( & V_19 -> V_446 ) ;
V_474 = F_369 ( V_19 , 0 ) ;
if ( F_134 ( V_474 ) )
return F_135 ( V_474 ) ;
V_474 -> V_472 [ 0 ] = V_474 -> V_91 ;
F_116 ( V_474 -> V_16 , V_478 ) ;
F_116 ( V_478 -> V_91 , V_474 ) ;
return 0 ;
}
static int F_324 ( struct V_18 * V_19 , struct V_1 * V_6 ,
struct V_1 * V_456 )
{
int V_106 , V_20 , V_471 = 0 ;
struct V_15 * V_479 , * V_480 ;
struct V_416 * V_469 , * V_481 ;
V_106 = V_19 -> V_106 ;
V_479 = V_6 -> V_41 [ V_106 ] ;
V_480 = V_456 -> V_41 [ V_106 ] ;
V_481 = F_204 ( V_479 -> V_91 , true ) ;
V_471 = V_481 -> V_471 + 1 ;
V_469 = F_369 ( V_19 , V_471 ) ;
if ( F_134 ( V_469 ) )
return F_135 ( V_469 ) ;
for ( V_20 = 0 ; V_20 < V_471 ; V_20 ++ )
V_469 -> V_472 [ V_20 ] = V_481 -> V_472 [ V_20 ] ;
V_469 -> V_472 [ V_471 ] = V_469 -> V_91 ;
F_157 ( V_480 -> V_91 , V_469 ) ;
return 0 ;
}
struct V_15 * F_374 ( struct V_18 * V_19 , int V_91 )
{
struct V_416 * V_468 = NULL ;
F_32 ( ! V_19 -> V_429 ) ;
V_468 = F_375 ( & V_19 -> V_446 , V_91 ) ;
if ( F_272 ( ! V_468 ) )
return NULL ;
return F_367 ( V_468 -> V_16 ) ;
}
struct V_15 * F_376 ( struct V_249 * V_482 , int V_91 )
{
struct V_1 * V_2 ;
struct V_66 * V_66 ;
struct V_15 * V_16 ;
V_66 = F_217 ( V_482 ) ;
if ( V_66 -> V_186 != & V_187 )
return F_123 ( - V_411 ) ;
if ( V_91 < 0 || V_91 >= V_56 )
return F_123 ( - V_144 ) ;
V_2 = F_6 ( V_482 -> V_264 ) ;
V_16 = V_2 -> V_41 [ V_91 ] ;
return V_16 ? V_16 : F_123 ( - V_151 ) ;
}
static struct V_15 * F_377 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_39 ( sizeof( * V_16 ) , V_54 ) ;
if ( ! V_16 )
return F_123 ( - V_55 ) ;
return V_16 ;
}
static void F_378 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_41 [ V_483 ] ) ;
}
static T_3 F_379 ( struct V_1 * V_2 , struct V_13 * V_100 )
{
return F_230 ( V_2 ) ;
}
static T_3 F_380 ( struct V_1 * V_2 , struct V_13 * V_100 )
{
return ( T_3 ) ( unsigned long ) V_154 -> V_219 ;
}
static T_3 F_381 ( struct V_1 * V_2 ,
struct V_13 * V_100 )
{
T_3 V_52 ;
F_146 () ;
V_52 = F_231 ( & F_55 ( V_154 ) -> V_27 ) ;
F_147 () ;
return V_52 ;
}
static int F_382 ( struct V_1 * V_2 ,
struct V_13 * V_100 ,
struct V_127 * V_128 )
{
struct V_24 * V_25 ;
struct V_21 * V_22 ;
F_47 ( & V_28 ) ;
F_146 () ;
V_22 = F_367 ( V_154 -> V_219 ) ;
F_51 (link, &cset->cgrp_links, cgrp_link) {
struct V_1 * V_59 = V_25 -> V_2 ;
const char * V_82 ;
if ( V_59 -> V_10 )
V_82 = V_59 -> V_10 -> V_83 . V_82 ;
else
V_82 = L_50 ;
F_98 ( V_128 , L_51 ,
V_59 -> V_48 -> V_167 , V_82 ) ;
}
F_147 () ;
F_48 ( & V_28 ) ;
return 0 ;
}
static int F_383 ( struct V_1 * V_2 ,
struct V_13 * V_100 ,
struct V_127 * V_128 )
{
struct V_24 * V_25 ;
F_47 ( & V_28 ) ;
F_51 (link, &cgrp->cset_links, cset_link) {
struct V_21 * V_22 = V_25 -> V_22 ;
struct V_61 * V_62 ;
int V_52 = 0 ;
F_98 ( V_128 , L_52 , V_22 ) ;
F_51 (task, &cset->tasks, cg_list) {
if ( V_52 ++ > V_484 ) {
F_99 ( V_128 , L_53 ) ;
break;
} else {
F_98 ( V_128 , L_54 ,
F_274 ( V_62 ) ) ;
}
}
}
F_48 ( & V_28 ) ;
return 0 ;
}
static T_3 F_384 ( struct V_1 * V_2 , struct V_13 * V_100 )
{
return F_2 ( V_8 , & V_2 -> V_4 ) ;
}
