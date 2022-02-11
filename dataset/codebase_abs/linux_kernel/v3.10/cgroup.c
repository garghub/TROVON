static int F_1 ( int V_1 )
{
return V_1 >= 0 ? V_1 : V_1 - V_2 ;
}
static int F_2 ( struct V_3 * V_4 )
{
int V_5 = F_3 ( & V_4 -> V_1 ) ;
return F_1 ( V_5 ) ;
}
inline int F_4 ( const struct V_6 * V_7 )
{
return F_5 ( V_8 , & V_7 -> V_9 ) ;
}
bool F_6 ( struct V_6 * V_7 , struct V_6 * V_10 )
{
while ( V_7 ) {
if ( V_7 == V_10 )
return true ;
V_7 = V_7 -> V_11 ;
}
return false ;
}
static int F_7 ( const struct V_6 * V_7 )
{
const int V_12 =
( 1 << V_13 ) |
( 1 << V_14 ) ;
return ( V_7 -> V_9 & V_12 ) == V_12 ;
}
static int F_8 ( const struct V_6 * V_7 )
{
return F_5 ( V_14 , & V_7 -> V_9 ) ;
}
static inline struct V_6 * F_9 ( struct V_15 * V_15 )
{
return V_15 -> V_16 ;
}
static inline struct V_17 * F_10 ( struct V_15 * V_15 )
{
return V_15 -> V_16 ;
}
static inline struct V_18 * F_11 ( struct V_15 * V_15 )
{
return F_10 ( V_15 ) -> type ;
}
static bool F_12 ( struct V_6 * V_7 )
{
F_13 ( & V_19 ) ;
if ( F_4 ( V_7 ) ) {
F_14 ( & V_19 ) ;
return false ;
}
return true ;
}
static unsigned long F_15 ( struct V_3 * V_4 [] )
{
int V_20 ;
unsigned long V_21 = 0UL ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ )
V_21 += ( unsigned long ) V_4 [ V_20 ] ;
V_21 = ( V_21 >> 16 ) ^ V_21 ;
return V_21 ;
}
static void F_16 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 ;
struct V_26 * V_28 ;
if ( F_17 ( & V_24 -> V_29 , - 1 , 1 ) )
return;
F_18 ( & V_30 ) ;
if ( ! F_19 ( & V_24 -> V_29 ) ) {
F_20 ( & V_30 ) ;
return;
}
F_21 ( & V_24 -> V_31 ) ;
V_32 -- ;
F_22 (link, saved_link, &cg->cg_links,
cg_link_list) {
struct V_6 * V_7 = V_27 -> V_7 ;
F_23 ( & V_27 -> V_33 ) ;
F_23 ( & V_27 -> V_34 ) ;
F_24 () ;
if ( F_19 ( & V_7 -> V_35 ) &&
F_8 ( V_7 ) ) {
if ( V_25 )
F_25 ( V_13 , & V_7 -> V_9 ) ;
F_26 ( V_7 ) ;
}
F_27 () ;
F_28 ( V_27 ) ;
}
F_20 ( & V_30 ) ;
F_29 ( V_24 , V_36 ) ;
}
static inline void F_30 ( struct V_23 * V_24 )
{
F_31 ( & V_24 -> V_29 ) ;
}
static inline void F_32 ( struct V_23 * V_24 )
{
F_16 ( V_24 , 0 ) ;
}
static inline void F_33 ( struct V_23 * V_24 )
{
F_16 ( V_24 , 1 ) ;
}
static bool F_34 ( struct V_23 * V_24 ,
struct V_23 * V_37 ,
struct V_6 * V_38 ,
struct V_3 * V_39 [] )
{
struct V_40 * V_41 , * V_42 ;
if ( memcmp ( V_39 , V_24 -> V_43 , sizeof( V_24 -> V_43 ) ) ) {
return false ;
}
V_41 = & V_24 -> V_44 ;
V_42 = & V_37 -> V_44 ;
while ( 1 ) {
struct V_26 * V_45 , * V_46 ;
struct V_6 * V_47 , * V_48 ;
V_41 = V_41 -> V_49 ;
V_42 = V_42 -> V_49 ;
if ( V_41 == & V_24 -> V_44 ) {
F_35 ( V_42 != & V_37 -> V_44 ) ;
break;
} else {
F_35 ( V_42 == & V_37 -> V_44 ) ;
}
V_45 = F_36 ( V_41 , struct V_26 , V_33 ) ;
V_46 = F_36 ( V_42 , struct V_26 , V_33 ) ;
V_47 = V_45 -> V_7 ;
V_48 = V_46 -> V_7 ;
F_35 ( V_47 -> V_50 != V_48 -> V_50 ) ;
if ( V_47 -> V_50 == V_38 -> V_50 ) {
if ( V_47 != V_38 )
return false ;
} else {
if ( V_47 != V_48 )
return false ;
}
}
return true ;
}
static struct V_23 * F_37 (
struct V_23 * V_51 ,
struct V_6 * V_7 ,
struct V_3 * V_39 [] )
{
int V_20 ;
struct V_52 * V_50 = V_7 -> V_50 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
if ( V_50 -> V_53 & ( 1UL << V_20 ) ) {
V_39 [ V_20 ] = V_7 -> V_43 [ V_20 ] ;
} else {
V_39 [ V_20 ] = V_51 -> V_43 [ V_20 ] ;
}
}
V_21 = F_15 ( V_39 ) ;
F_38 (css_set_table, cg, hlist, key) {
if ( ! F_34 ( V_24 , V_51 , V_7 , V_39 ) )
continue;
return V_24 ;
}
return NULL ;
}
static void F_39 ( struct V_40 * V_54 )
{
struct V_26 * V_27 ;
struct V_26 * V_28 ;
F_22 (link, saved_link, tmp, cgrp_link_list) {
F_23 ( & V_27 -> V_34 ) ;
F_28 ( V_27 ) ;
}
}
static int F_40 ( int V_35 , struct V_40 * V_54 )
{
struct V_26 * V_27 ;
int V_20 ;
F_41 ( V_54 ) ;
for ( V_20 = 0 ; V_20 < V_35 ; V_20 ++ ) {
V_27 = F_42 ( sizeof( * V_27 ) , V_55 ) ;
if ( ! V_27 ) {
F_39 ( V_54 ) ;
return - V_56 ;
}
F_43 ( & V_27 -> V_34 , V_54 ) ;
}
return 0 ;
}
static void F_44 ( struct V_40 * V_57 ,
struct V_23 * V_24 , struct V_6 * V_7 )
{
struct V_26 * V_27 ;
F_35 ( F_45 ( V_57 ) ) ;
V_27 = F_46 ( V_57 , struct V_26 ,
V_34 ) ;
V_27 -> V_24 = V_24 ;
V_27 -> V_7 = V_7 ;
F_31 ( & V_7 -> V_35 ) ;
F_47 ( & V_27 -> V_34 , & V_7 -> V_58 ) ;
F_48 ( & V_27 -> V_33 , & V_24 -> V_44 ) ;
}
static struct V_23 * F_49 (
struct V_23 * V_51 , struct V_6 * V_7 )
{
struct V_23 * V_59 ;
struct V_3 * V_39 [ V_22 ] ;
struct V_40 V_57 ;
struct V_26 * V_27 ;
unsigned long V_21 ;
F_50 ( & V_30 ) ;
V_59 = F_37 ( V_51 , V_7 , V_39 ) ;
if ( V_59 )
F_30 ( V_59 ) ;
F_51 ( & V_30 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_42 ( sizeof( * V_59 ) , V_55 ) ;
if ( ! V_59 )
return NULL ;
if ( F_40 ( V_60 , & V_57 ) < 0 ) {
F_28 ( V_59 ) ;
return NULL ;
}
F_52 ( & V_59 -> V_29 , 1 ) ;
F_41 ( & V_59 -> V_44 ) ;
F_41 ( & V_59 -> V_61 ) ;
F_53 ( & V_59 -> V_31 ) ;
memcpy ( V_59 -> V_43 , V_39 , sizeof( V_59 -> V_43 ) ) ;
F_18 ( & V_30 ) ;
F_54 (link, &oldcg->cg_links, cg_link_list) {
struct V_6 * V_62 = V_27 -> V_7 ;
if ( V_62 -> V_50 == V_7 -> V_50 )
V_62 = V_7 ;
F_44 ( & V_57 , V_59 , V_62 ) ;
}
F_35 ( ! F_45 ( & V_57 ) ) ;
V_32 ++ ;
V_21 = F_15 ( V_59 -> V_43 ) ;
F_55 ( V_63 , & V_59 -> V_31 , V_21 ) ;
F_20 ( & V_30 ) ;
return V_59 ;
}
static struct V_6 * F_56 ( struct V_64 * V_65 ,
struct V_52 * V_50 )
{
struct V_23 * V_4 ;
struct V_6 * V_59 = NULL ;
F_35 ( ! F_57 ( & V_19 ) ) ;
F_50 ( & V_30 ) ;
V_4 = V_65 -> V_66 ;
if ( V_4 == & V_67 ) {
V_59 = & V_50 -> V_68 ;
} else {
struct V_26 * V_27 ;
F_54 (link, &css->cg_links, cg_link_list) {
struct V_6 * V_62 = V_27 -> V_7 ;
if ( V_62 -> V_50 == V_50 ) {
V_59 = V_62 ;
break;
}
}
}
F_51 ( & V_30 ) ;
F_35 ( ! V_59 ) ;
return V_59 ;
}
static struct V_69 * F_58 ( T_1 V_70 , struct V_71 * V_72 )
{
struct V_69 * V_69 = F_59 ( V_72 ) ;
if ( V_69 ) {
V_69 -> V_73 = F_60 () ;
V_69 -> V_74 = V_70 ;
V_69 -> V_75 = F_61 () ;
V_69 -> V_76 = F_62 () ;
V_69 -> V_77 = V_69 -> V_78 = V_69 -> V_79 = V_80 ;
V_69 -> V_81 -> V_82 = & V_83 ;
}
return V_69 ;
}
static struct V_84 * F_63 ( struct V_15 * V_15 )
{
struct V_84 * V_85 ;
V_85 = F_42 ( sizeof( * V_85 ) + V_15 -> V_86 . V_87 + 1 , V_55 ) ;
if ( ! V_85 )
return NULL ;
strcpy ( V_85 -> V_85 , V_15 -> V_86 . V_85 ) ;
return V_85 ;
}
static void F_64 ( struct V_88 * V_89 )
{
struct V_6 * V_7 = F_65 ( V_89 , struct V_6 , V_90 ) ;
struct V_91 * V_92 ;
F_13 ( & V_19 ) ;
F_66 (cgrp->root, ss)
V_92 -> V_93 ( V_7 ) ;
V_7 -> V_50 -> V_94 -- ;
F_14 ( & V_19 ) ;
F_67 ( V_7 -> V_11 -> V_15 ) ;
F_68 ( & V_7 -> V_50 -> V_95 , V_7 -> V_96 ) ;
F_69 ( V_7 -> V_50 -> V_72 ) ;
F_35 ( ! F_45 ( & V_7 -> V_97 ) ) ;
F_70 ( & V_7 -> V_98 ) ;
F_28 ( F_71 ( V_7 -> V_85 ) ) ;
F_28 ( V_7 ) ;
}
static void F_72 ( struct V_36 * V_99 )
{
struct V_6 * V_7 = F_65 ( V_99 , struct V_6 , V_36 ) ;
F_73 ( & V_7 -> V_90 ) ;
}
static void F_74 ( struct V_15 * V_15 , struct V_69 * V_69 )
{
if ( F_75 ( V_69 -> V_74 ) ) {
struct V_6 * V_7 = V_15 -> V_16 ;
F_35 ( ! ( F_4 ( V_7 ) ) ) ;
F_76 ( & V_7 -> V_36 , F_72 ) ;
} else {
struct V_17 * V_100 = F_10 ( V_15 ) ;
struct V_6 * V_7 = V_15 -> V_101 -> V_16 ;
F_77 ( ! F_45 ( & V_100 -> V_102 ) &&
V_7 != & V_7 -> V_50 -> V_68 ,
L_1 , V_100 -> type -> V_85 ) ;
F_70 ( & V_100 -> V_98 ) ;
F_28 ( V_100 ) ;
}
F_78 ( V_69 ) ;
}
static int F_79 ( const struct V_15 * V_103 )
{
return 1 ;
}
static void F_80 ( struct V_15 * V_103 )
{
struct V_15 * V_11 = F_81 ( V_103 -> V_101 ) ;
F_82 ( V_103 ) ;
F_83 ( V_11 -> V_104 , V_103 ) ;
F_67 ( V_11 ) ;
}
static void F_84 ( struct V_6 * V_7 , const struct V_18 * V_105 )
{
struct V_17 * V_100 ;
F_85 ( & V_7 -> V_15 -> V_104 -> V_106 ) ;
F_85 ( & V_19 ) ;
F_54 (cfe, &cgrp->files, node) {
struct V_15 * V_103 = V_100 -> V_15 ;
if ( V_105 && V_100 -> type != V_105 )
continue;
F_81 ( V_103 ) ;
F_82 ( V_103 ) ;
F_86 ( V_7 -> V_15 -> V_104 , V_103 ) ;
F_87 ( & V_100 -> V_102 ) ;
F_67 ( V_103 ) ;
break;
}
}
static void F_88 ( struct V_15 * V_107 , bool V_108 ,
unsigned long V_53 )
{
struct V_6 * V_7 = F_9 ( V_107 ) ;
struct V_91 * V_92 ;
F_66 (cgrp->root, ss) {
struct V_109 * V_110 ;
if ( ! F_5 ( V_92 -> V_111 , & V_53 ) )
continue;
F_54 (set, &ss->cftsets, node)
F_89 ( V_7 , NULL , V_110 -> V_112 , false ) ;
}
if ( V_108 ) {
while ( ! F_45 ( & V_7 -> V_113 ) )
F_84 ( V_7 , NULL ) ;
}
}
static void F_90 ( struct V_15 * V_15 )
{
struct V_15 * V_11 ;
struct V_52 * V_50 = V_15 -> V_114 -> V_115 ;
F_88 ( V_15 , true , V_50 -> V_53 ) ;
V_11 = V_15 -> V_101 ;
F_91 ( & V_11 -> V_116 ) ;
F_92 ( & V_15 -> V_116 , V_117 ) ;
F_87 ( & V_15 -> V_118 . V_119 ) ;
F_93 ( & V_15 -> V_116 ) ;
F_93 ( & V_11 -> V_116 ) ;
F_80 ( V_15 ) ;
}
static int F_94 ( struct V_52 * V_50 ,
unsigned long V_120 )
{
unsigned long V_121 , V_122 ;
struct V_6 * V_7 = & V_50 -> V_68 ;
int V_20 ;
F_35 ( ! F_57 ( & V_19 ) ) ;
F_35 ( ! F_57 ( & V_123 ) ) ;
V_122 = V_50 -> V_124 & ~ V_120 ;
V_121 = V_120 & ~ V_50 -> V_124 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
unsigned long V_125 = 1UL << V_20 ;
struct V_91 * V_92 = V_43 [ V_20 ] ;
if ( ! ( V_125 & V_121 ) )
continue;
F_35 ( V_92 == NULL ) ;
if ( V_92 -> V_50 != & V_126 ) {
return - V_127 ;
}
}
if ( V_50 -> V_94 > 1 )
return - V_127 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_91 * V_92 = V_43 [ V_20 ] ;
unsigned long V_125 = 1UL << V_20 ;
if ( V_125 & V_121 ) {
F_35 ( V_92 == NULL ) ;
F_35 ( V_7 -> V_43 [ V_20 ] ) ;
F_35 ( ! V_128 -> V_43 [ V_20 ] ) ;
F_35 ( V_128 -> V_43 [ V_20 ] -> V_6 != V_128 ) ;
V_7 -> V_43 [ V_20 ] = V_128 -> V_43 [ V_20 ] ;
V_7 -> V_43 [ V_20 ] -> V_6 = V_7 ;
F_47 ( & V_92 -> V_129 , & V_50 -> V_130 ) ;
V_92 -> V_50 = V_50 ;
if ( V_92 -> V_131 )
V_92 -> V_131 ( V_7 ) ;
} else if ( V_125 & V_122 ) {
F_35 ( V_92 == NULL ) ;
F_35 ( V_7 -> V_43 [ V_20 ] != V_128 -> V_43 [ V_20 ] ) ;
F_35 ( V_7 -> V_43 [ V_20 ] -> V_6 != V_7 ) ;
if ( V_92 -> V_131 )
V_92 -> V_131 ( V_128 ) ;
V_128 -> V_43 [ V_20 ] -> V_6 = V_128 ;
V_7 -> V_43 [ V_20 ] = NULL ;
V_43 [ V_20 ] -> V_50 = & V_126 ;
F_47 ( & V_92 -> V_129 , & V_126 . V_130 ) ;
F_95 ( V_92 -> V_132 ) ;
} else if ( V_125 & V_120 ) {
F_35 ( V_92 == NULL ) ;
F_35 ( ! V_7 -> V_43 [ V_20 ] ) ;
F_95 ( V_92 -> V_132 ) ;
#ifdef F_96
F_35 ( V_92 -> V_132 && ! F_97 ( V_92 -> V_132 ) ) ;
#endif
} else {
F_35 ( V_7 -> V_43 [ V_20 ] ) ;
}
}
V_50 -> V_53 = V_50 -> V_124 = V_120 ;
return 0 ;
}
static int F_98 ( struct V_133 * V_134 , struct V_15 * V_15 )
{
struct V_52 * V_50 = V_15 -> V_114 -> V_115 ;
struct V_91 * V_92 ;
F_13 ( & V_123 ) ;
F_66 (root, ss)
F_99 ( V_134 , L_2 , V_92 -> V_85 ) ;
if ( V_50 -> V_9 & V_135 )
F_100 ( V_134 , L_3 ) ;
if ( V_50 -> V_9 & V_136 )
F_100 ( V_134 , L_4 ) ;
if ( V_50 -> V_9 & V_137 )
F_100 ( V_134 , L_5 ) ;
if ( strlen ( V_50 -> V_138 ) )
F_99 ( V_134 , L_6 , V_50 -> V_138 ) ;
if ( F_5 ( V_139 , & V_50 -> V_68 . V_9 ) )
F_100 ( V_134 , L_7 ) ;
if ( strlen ( V_50 -> V_85 ) )
F_99 ( V_134 , L_8 , V_50 -> V_85 ) ;
F_14 ( & V_123 ) ;
return 0 ;
}
static int F_101 ( char * V_140 , struct V_141 * V_142 )
{
char * V_143 , * V_144 = V_140 ;
bool V_145 = false , V_146 = false ;
unsigned long V_147 = ( unsigned long ) - 1 ;
int V_20 ;
bool V_148 = false ;
F_35 ( ! F_57 ( & V_19 ) ) ;
#ifdef F_102
V_147 = ~ ( 1UL << V_149 ) ;
#endif
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
while ( ( V_143 = F_103 ( & V_144 , L_9 ) ) != NULL ) {
if ( ! * V_143 )
return - V_150 ;
if ( ! strcmp ( V_143 , L_10 ) ) {
V_142 -> V_151 = true ;
continue;
}
if ( ! strcmp ( V_143 , L_11 ) ) {
if ( V_146 )
return - V_150 ;
V_145 = true ;
continue;
}
if ( ! strcmp ( V_143 , L_12 ) ) {
V_142 -> V_9 |= V_135 ;
continue;
}
if ( ! strcmp ( V_143 , L_13 ) ) {
V_142 -> V_9 |= V_136 ;
continue;
}
if ( ! strcmp ( V_143 , L_14 ) ) {
V_142 -> V_152 = true ;
continue;
}
if ( ! strcmp ( V_143 , L_15 ) ) {
V_142 -> V_9 |= V_137 ;
continue;
}
if ( ! strncmp ( V_143 , L_16 , 14 ) ) {
if ( V_142 -> V_153 )
return - V_150 ;
V_142 -> V_153 =
F_104 ( V_143 + 14 , V_154 - 1 , V_55 ) ;
if ( ! V_142 -> V_153 )
return - V_56 ;
continue;
}
if ( ! strncmp ( V_143 , L_17 , 5 ) ) {
const char * V_85 = V_143 + 5 ;
if ( ! strlen ( V_85 ) )
return - V_150 ;
for ( V_20 = 0 ; V_20 < strlen ( V_85 ) ; V_20 ++ ) {
char V_62 = V_85 [ V_20 ] ;
if ( isalnum ( V_62 ) )
continue;
if ( ( V_62 == '.' ) || ( V_62 == '-' ) || ( V_62 == '_' ) )
continue;
return - V_150 ;
}
if ( V_142 -> V_85 )
return - V_150 ;
V_142 -> V_85 = F_104 ( V_85 ,
V_155 - 1 ,
V_55 ) ;
if ( ! V_142 -> V_85 )
return - V_56 ;
continue;
}
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_91 * V_92 = V_43 [ V_20 ] ;
if ( V_92 == NULL )
continue;
if ( strcmp ( V_143 , V_92 -> V_85 ) )
continue;
if ( V_92 -> V_156 )
continue;
if ( V_145 )
return - V_150 ;
F_25 ( V_20 , & V_142 -> V_53 ) ;
V_146 = true ;
break;
}
if ( V_20 == V_22 )
return - V_157 ;
}
if ( V_145 || ( ! V_146 && ! V_142 -> V_151 && ! V_142 -> V_85 ) ) {
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_91 * V_92 = V_43 [ V_20 ] ;
if ( V_92 == NULL )
continue;
if ( V_92 -> V_156 )
continue;
F_25 ( V_20 , & V_142 -> V_53 ) ;
}
}
if ( V_142 -> V_9 & V_135 ) {
F_105 ( L_18 ) ;
if ( V_142 -> V_9 & V_136 ) {
F_106 ( L_19 ) ;
return - V_150 ;
}
if ( V_142 -> V_152 ) {
F_106 ( L_20 ) ;
return - V_150 ;
}
}
if ( ( V_142 -> V_9 & V_136 ) && ( V_142 -> V_53 & V_147 ) )
return - V_150 ;
if ( V_142 -> V_53 && V_142 -> V_151 )
return - V_150 ;
if ( ! V_142 -> V_53 && ! V_142 -> V_85 )
return - V_150 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
unsigned long V_125 = 1UL << V_20 ;
if ( ! ( V_125 & V_142 -> V_53 ) )
continue;
if ( ! F_107 ( V_43 [ V_20 ] -> V_132 ) ) {
V_148 = true ;
break;
}
}
if ( V_148 ) {
for ( V_20 -- ; V_20 >= 0 ; V_20 -- ) {
unsigned long V_125 = 1UL << V_20 ;
if ( ! ( V_125 & V_142 -> V_53 ) )
continue;
F_95 ( V_43 [ V_20 ] -> V_132 ) ;
}
return - V_157 ;
}
return 0 ;
}
static void F_108 ( unsigned long V_53 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
unsigned long V_125 = 1UL << V_20 ;
if ( ! ( V_125 & V_53 ) )
continue;
F_95 ( V_43 [ V_20 ] -> V_132 ) ;
}
}
static int F_109 ( struct V_71 * V_72 , int * V_9 , char * V_140 )
{
int V_158 = 0 ;
struct V_52 * V_50 = V_72 -> V_115 ;
struct V_6 * V_7 = & V_50 -> V_68 ;
struct V_141 V_142 ;
unsigned long V_121 , V_122 ;
if ( V_50 -> V_9 & V_135 ) {
F_106 ( L_21 ) ;
return - V_150 ;
}
F_13 ( & V_7 -> V_15 -> V_104 -> V_106 ) ;
F_13 ( & V_19 ) ;
F_13 ( & V_123 ) ;
V_158 = F_101 ( V_140 , & V_142 ) ;
if ( V_158 )
goto V_159;
if ( V_142 . V_53 != V_50 -> V_124 || V_142 . V_153 )
F_105 ( L_22 ,
F_110 ( V_160 ) , V_160 -> V_161 ) ;
V_121 = V_142 . V_53 & ~ V_50 -> V_53 ;
V_122 = V_50 -> V_53 & ~ V_142 . V_53 ;
if ( V_142 . V_9 != V_50 -> V_9 ||
( V_142 . V_85 && strcmp ( V_142 . V_85 , V_50 -> V_85 ) ) ) {
V_158 = - V_150 ;
F_108 ( V_142 . V_53 ) ;
goto V_159;
}
F_88 ( V_7 -> V_15 , false , V_122 ) ;
V_158 = F_94 ( V_50 , V_142 . V_53 ) ;
if ( V_158 ) {
F_111 ( V_7 , false , V_122 ) ;
F_108 ( V_142 . V_53 ) ;
goto V_159;
}
F_111 ( V_7 , false , V_121 ) ;
if ( V_142 . V_153 )
strcpy ( V_50 -> V_138 , V_142 . V_153 ) ;
V_159:
F_28 ( V_142 . V_153 ) ;
F_28 ( V_142 . V_85 ) ;
F_14 ( & V_123 ) ;
F_14 ( & V_19 ) ;
F_14 ( & V_7 -> V_15 -> V_104 -> V_106 ) ;
return V_158 ;
}
static void F_112 ( struct V_6 * V_7 )
{
F_41 ( & V_7 -> V_129 ) ;
F_41 ( & V_7 -> V_162 ) ;
F_41 ( & V_7 -> V_113 ) ;
F_41 ( & V_7 -> V_58 ) ;
F_41 ( & V_7 -> V_163 ) ;
F_41 ( & V_7 -> V_164 ) ;
F_41 ( & V_7 -> V_97 ) ;
F_113 ( & V_7 -> V_90 , F_64 ) ;
F_114 ( & V_7 -> V_165 ) ;
F_41 ( & V_7 -> V_166 ) ;
F_115 ( & V_7 -> V_167 ) ;
F_116 ( & V_7 -> V_98 ) ;
}
static void F_117 ( struct V_52 * V_50 )
{
struct V_6 * V_7 = & V_50 -> V_68 ;
F_41 ( & V_50 -> V_130 ) ;
F_41 ( & V_50 -> V_168 ) ;
F_41 ( & V_50 -> V_169 ) ;
V_50 -> V_94 = 1 ;
V_7 -> V_50 = V_50 ;
V_7 -> V_85 = & V_170 ;
F_112 ( V_7 ) ;
F_48 ( & V_7 -> V_163 , & V_50 -> V_169 ) ;
}
static bool F_118 ( struct V_52 * V_50 )
{
int V_158 = 0 ;
do {
if ( ! F_119 ( & V_171 , V_55 ) )
return false ;
F_91 ( & V_172 ) ;
V_158 = F_120 ( & V_171 , V_173 ,
& V_50 -> V_174 ) ;
if ( V_158 == - V_175 )
V_158 = F_121 ( & V_171 , & V_50 -> V_174 ) ;
if ( ! V_158 ) {
V_173 = V_50 -> V_174 + 1 ;
} else if ( V_158 != - V_176 ) {
F_35 ( V_158 ) ;
}
F_93 ( & V_172 ) ;
} while ( V_158 );
return true ;
}
static int F_122 ( struct V_71 * V_72 , void * V_140 )
{
struct V_141 * V_142 = V_140 ;
struct V_52 * V_50 = V_72 -> V_115 ;
if ( V_142 -> V_85 && strcmp ( V_142 -> V_85 , V_50 -> V_85 ) )
return 0 ;
if ( ( V_142 -> V_53 || V_142 -> V_151 )
&& ( V_142 -> V_53 != V_50 -> V_53 ) )
return 0 ;
return 1 ;
}
static struct V_52 * F_123 ( struct V_141 * V_142 )
{
struct V_52 * V_50 ;
if ( ! V_142 -> V_53 && ! V_142 -> V_151 )
return NULL ;
V_50 = F_124 ( sizeof( * V_50 ) , V_55 ) ;
if ( ! V_50 )
return F_125 ( - V_56 ) ;
if ( ! F_118 ( V_50 ) ) {
F_28 ( V_50 ) ;
return F_125 ( - V_56 ) ;
}
F_117 ( V_50 ) ;
V_50 -> V_53 = V_142 -> V_53 ;
V_50 -> V_9 = V_142 -> V_9 ;
F_126 ( & V_50 -> V_95 ) ;
if ( V_142 -> V_153 )
strcpy ( V_50 -> V_138 , V_142 -> V_153 ) ;
if ( V_142 -> V_85 )
strcpy ( V_50 -> V_85 , V_142 -> V_85 ) ;
if ( V_142 -> V_152 )
F_25 ( V_139 , & V_50 -> V_68 . V_9 ) ;
return V_50 ;
}
static void F_127 ( struct V_52 * V_50 )
{
if ( ! V_50 )
return;
F_35 ( ! V_50 -> V_174 ) ;
F_91 ( & V_172 ) ;
F_128 ( & V_171 , V_50 -> V_174 ) ;
F_93 ( & V_172 ) ;
F_129 ( & V_50 -> V_95 ) ;
F_28 ( V_50 ) ;
}
static int F_130 ( struct V_71 * V_72 , void * V_140 )
{
int V_158 ;
struct V_141 * V_142 = V_140 ;
if ( ! V_142 -> V_177 )
return - V_150 ;
F_35 ( ! V_142 -> V_53 && ! V_142 -> V_151 ) ;
V_158 = F_131 ( V_72 , NULL ) ;
if ( V_158 )
return V_158 ;
V_72 -> V_115 = V_142 -> V_177 ;
V_142 -> V_177 -> V_72 = V_72 ;
V_72 -> V_178 = V_179 ;
V_72 -> V_180 = V_181 ;
V_72 -> V_182 = V_183 ;
V_72 -> V_184 = & V_185 ;
return 0 ;
}
static int F_132 ( struct V_71 * V_72 )
{
static const struct V_186 V_187 = {
. V_188 = F_74 ,
. F_82 = F_79 ,
} ;
struct V_69 * V_69 =
F_58 ( V_189 | V_190 | V_191 | V_192 , V_72 ) ;
if ( ! V_69 )
return - V_56 ;
V_69 -> V_193 = & V_194 ;
V_69 -> V_195 = & V_196 ;
F_133 ( V_69 ) ;
V_72 -> V_197 = F_134 ( V_69 ) ;
if ( ! V_72 -> V_197 )
return - V_56 ;
V_72 -> V_198 = & V_187 ;
return 0 ;
}
static struct V_15 * F_135 ( struct V_199 * V_200 ,
int V_9 , const char * V_201 ,
void * V_140 )
{
struct V_141 V_142 ;
struct V_52 * V_50 ;
int V_158 = 0 ;
struct V_71 * V_72 ;
struct V_52 * V_177 ;
struct V_69 * V_69 ;
F_13 ( & V_19 ) ;
V_158 = F_101 ( V_140 , & V_142 ) ;
F_14 ( & V_19 ) ;
if ( V_158 )
goto V_202;
V_177 = F_123 ( & V_142 ) ;
if ( F_136 ( V_177 ) ) {
V_158 = F_137 ( V_177 ) ;
goto V_203;
}
V_142 . V_177 = V_177 ;
V_72 = F_138 ( V_200 , F_122 , F_130 , 0 , & V_142 ) ;
if ( F_136 ( V_72 ) ) {
V_158 = F_137 ( V_72 ) ;
F_127 ( V_142 . V_177 ) ;
goto V_203;
}
V_50 = V_72 -> V_115 ;
F_35 ( ! V_50 ) ;
if ( V_50 == V_142 . V_177 ) {
struct V_40 V_57 ;
struct V_6 * V_204 = & V_50 -> V_68 ;
struct V_52 * V_205 ;
const struct V_206 * V_206 ;
int V_20 ;
struct V_23 * V_24 ;
F_35 ( V_72 -> V_197 != NULL ) ;
V_158 = F_132 ( V_72 ) ;
if ( V_158 )
goto V_207;
V_69 = V_72 -> V_197 -> V_104 ;
F_13 ( & V_69 -> V_106 ) ;
F_13 ( & V_19 ) ;
F_13 ( & V_123 ) ;
V_158 = - V_127 ;
if ( strlen ( V_50 -> V_85 ) )
F_139 (existing_root)
if ( ! strcmp ( V_205 -> V_85 , V_50 -> V_85 ) )
goto V_208;
V_158 = F_40 ( V_32 , & V_57 ) ;
if ( V_158 )
goto V_208;
V_158 = F_94 ( V_50 , V_50 -> V_53 ) ;
if ( V_158 == - V_127 ) {
F_39 ( & V_57 ) ;
goto V_208;
}
F_35 ( V_158 ) ;
F_43 ( & V_50 -> V_168 , & V_209 ) ;
V_60 ++ ;
V_72 -> V_197 -> V_16 = V_204 ;
V_50 -> V_68 . V_15 = V_72 -> V_197 ;
F_18 ( & V_30 ) ;
F_140 (css_set_table, i, cg, hlist)
F_44 ( & V_57 , V_24 , V_204 ) ;
F_20 ( & V_30 ) ;
F_39 ( & V_57 ) ;
F_35 ( ! F_45 ( & V_204 -> V_162 ) ) ;
F_35 ( V_50 -> V_94 != 1 ) ;
V_206 = F_141 ( & V_210 ) ;
F_111 ( V_204 , true , V_50 -> V_53 ) ;
F_142 ( V_206 ) ;
F_14 ( & V_123 ) ;
F_14 ( & V_19 ) ;
F_14 ( & V_69 -> V_106 ) ;
} else {
F_127 ( V_142 . V_177 ) ;
if ( V_50 -> V_9 != V_142 . V_9 ) {
if ( ( V_50 -> V_9 | V_142 . V_9 ) & V_135 ) {
F_106 ( L_23 ) ;
V_158 = - V_150 ;
goto V_207;
} else {
F_105 ( L_24 ) ;
}
}
F_108 ( V_142 . V_53 ) ;
}
F_28 ( V_142 . V_153 ) ;
F_28 ( V_142 . V_85 ) ;
return F_81 ( V_72 -> V_197 ) ;
V_208:
F_14 ( & V_123 ) ;
F_14 ( & V_19 ) ;
F_14 ( & V_69 -> V_106 ) ;
V_207:
F_143 ( V_72 ) ;
V_203:
F_108 ( V_142 . V_53 ) ;
V_202:
F_28 ( V_142 . V_153 ) ;
F_28 ( V_142 . V_85 ) ;
return F_125 ( V_158 ) ;
}
static void F_144 ( struct V_71 * V_72 ) {
struct V_52 * V_50 = V_72 -> V_115 ;
struct V_6 * V_7 = & V_50 -> V_68 ;
int V_158 ;
struct V_26 * V_27 ;
struct V_26 * V_28 ;
F_35 ( ! V_50 ) ;
F_35 ( V_50 -> V_94 != 1 ) ;
F_35 ( ! F_45 ( & V_7 -> V_162 ) ) ;
F_13 ( & V_19 ) ;
F_13 ( & V_123 ) ;
V_158 = F_94 ( V_50 , 0 ) ;
F_35 ( V_158 ) ;
F_18 ( & V_30 ) ;
F_22 (link, saved_link, &cgrp->css_sets,
cgrp_link_list) {
F_23 ( & V_27 -> V_33 ) ;
F_23 ( & V_27 -> V_34 ) ;
F_28 ( V_27 ) ;
}
F_20 ( & V_30 ) ;
if ( ! F_45 ( & V_50 -> V_168 ) ) {
F_23 ( & V_50 -> V_168 ) ;
V_60 -- ;
}
F_14 ( & V_123 ) ;
F_14 ( & V_19 ) ;
F_70 ( & V_7 -> V_98 ) ;
F_145 ( V_72 ) ;
F_127 ( V_50 ) ;
}
int F_146 ( const struct V_6 * V_7 , char * V_211 , int V_212 )
{
int V_158 = - V_213 ;
char * V_214 ;
if ( ! V_7 -> V_11 ) {
if ( F_147 ( V_211 , L_25 , V_212 ) >= V_212 )
return - V_213 ;
return 0 ;
}
V_214 = V_211 + V_212 - 1 ;
* V_214 = '\0' ;
F_24 () ;
do {
const char * V_85 = V_84 ( V_7 ) ;
int V_87 ;
V_87 = strlen ( V_85 ) ;
if ( ( V_214 -= V_87 ) < V_211 )
goto V_215;
memcpy ( V_214 , V_85 , V_87 ) ;
if ( -- V_214 < V_211 )
goto V_215;
* V_214 = '/' ;
V_7 = V_7 -> V_11 ;
} while ( V_7 -> V_11 );
V_158 = 0 ;
memmove ( V_211 , V_214 , V_211 + V_212 - V_214 ) ;
V_215:
F_27 () ;
return V_158 ;
}
struct V_64 * F_148 ( struct V_216 * V_217 )
{
if ( V_217 -> V_218 ) {
V_217 -> V_219 = 0 ;
return F_149 ( V_217 ) ;
} else {
V_217 -> V_220 = V_217 -> V_221 . V_7 ;
return V_217 -> V_221 . V_65 ;
}
}
struct V_64 * F_149 ( struct V_216 * V_217 )
{
struct V_222 * V_223 ;
if ( ! V_217 -> V_218 || V_217 -> V_219 >= V_217 -> V_224 )
return NULL ;
V_223 = F_150 ( V_217 -> V_218 , V_217 -> V_219 ++ ) ;
V_217 -> V_220 = V_223 -> V_7 ;
return V_223 -> V_65 ;
}
struct V_6 * F_151 ( struct V_216 * V_217 )
{
return V_217 -> V_220 ;
}
int F_152 ( struct V_216 * V_217 )
{
return V_217 -> V_218 ? V_217 -> V_224 : 1 ;
}
static void F_153 ( struct V_6 * V_225 ,
struct V_64 * V_226 , struct V_23 * V_227 )
{
struct V_23 * V_51 ;
F_154 ( V_226 -> V_9 & V_228 ) ;
V_51 = V_226 -> V_66 ;
F_155 ( V_226 ) ;
F_156 ( V_226 -> V_66 , V_227 ) ;
F_157 ( V_226 ) ;
F_18 ( & V_30 ) ;
if ( ! F_45 ( & V_226 -> V_229 ) )
F_47 ( & V_226 -> V_229 , & V_227 -> V_61 ) ;
F_20 ( & V_30 ) ;
F_25 ( V_13 , & V_225 -> V_9 ) ;
F_32 ( V_51 ) ;
}
static int F_158 ( struct V_6 * V_7 , struct V_64 * V_226 ,
bool V_230 )
{
int V_231 , V_20 , V_232 ;
struct V_91 * V_92 , * V_233 = NULL ;
struct V_52 * V_50 = V_7 -> V_50 ;
struct V_64 * V_234 = V_226 ;
struct V_222 * V_223 ;
struct V_235 * V_236 ;
struct V_216 V_217 = { } ;
if ( V_230 )
V_232 = F_159 ( V_226 ) ;
else
V_232 = 1 ;
V_236 = F_160 ( sizeof( * V_223 ) , V_232 , V_55 ) ;
if ( ! V_236 )
return - V_56 ;
V_231 = F_161 ( V_236 , 0 , V_232 , V_55 ) ;
if ( V_231 )
goto V_237;
V_20 = 0 ;
F_24 () ;
do {
struct V_222 V_238 ;
if ( V_226 -> V_9 & V_228 )
continue;
F_35 ( V_20 >= V_232 ) ;
V_238 . V_65 = V_226 ;
V_238 . V_7 = F_56 ( V_226 , V_50 ) ;
if ( V_238 . V_7 == V_7 )
continue;
V_231 = F_162 ( V_236 , V_20 , & V_238 , V_239 ) ;
F_35 ( V_231 != 0 ) ;
V_20 ++ ;
if ( ! V_230 )
break;
} while_each_thread(leader, tsk) ;
int F_163 ( struct V_6 * V_7 , T_2 V_240 , bool V_230 )
{
struct V_64 * V_226 ;
const struct V_206 * V_206 = F_164 () , * V_241 ;
int V_158 ;
if ( ! F_12 ( V_7 ) )
return - V_242 ;
V_243:
F_24 () ;
if ( V_240 ) {
V_226 = F_165 ( V_240 ) ;
if ( ! V_226 ) {
F_27 () ;
V_158 = - V_244 ;
goto V_245;
}
V_241 = F_166 ( V_226 ) ;
if ( ! F_167 ( V_206 -> V_246 , V_247 ) &&
! F_167 ( V_206 -> V_246 , V_241 -> V_248 ) &&
! F_167 ( V_206 -> V_246 , V_241 -> V_249 ) ) {
F_27 () ;
V_158 = - V_250 ;
goto V_245;
}
} else
V_226 = V_160 ;
if ( V_230 )
V_226 = V_226 -> V_251 ;
if ( V_226 == V_252 || ( V_226 -> V_9 & V_253 ) ) {
V_158 = - V_150 ;
F_27 () ;
goto V_245;
}
F_168 ( V_226 ) ;
F_27 () ;
F_169 ( V_226 ) ;
if ( V_230 ) {
if ( ! F_170 ( V_226 ) ) {
F_171 ( V_226 ) ;
F_172 ( V_226 ) ;
goto V_243;
}
}
V_158 = F_158 ( V_7 , V_226 , V_230 ) ;
F_171 ( V_226 ) ;
F_172 ( V_226 ) ;
V_245:
F_14 ( & V_19 ) ;
return V_158 ;
}
int F_173 ( struct V_64 * V_254 , struct V_64 * V_226 )
{
struct V_52 * V_50 ;
int V_231 = 0 ;
F_13 ( & V_19 ) ;
F_139 (root) {
struct V_6 * V_255 = F_56 ( V_254 , V_50 ) ;
V_231 = F_158 ( V_255 , V_226 , false ) ;
if ( V_231 )
break;
}
F_14 ( & V_19 ) ;
return V_231 ;
}
static int F_174 ( struct V_6 * V_7 , struct V_18 * V_105 , T_2 V_240 )
{
return F_163 ( V_7 , V_240 , false ) ;
}
static int F_175 ( struct V_6 * V_7 , struct V_18 * V_105 , T_2 V_256 )
{
return F_163 ( V_7 , V_256 , true ) ;
}
static int F_176 ( struct V_6 * V_7 , struct V_18 * V_105 ,
const char * V_257 )
{
F_177 ( sizeof( V_7 -> V_50 -> V_138 ) < V_154 ) ;
if ( strlen ( V_257 ) >= V_154 )
return - V_150 ;
if ( ! F_12 ( V_7 ) )
return - V_242 ;
F_13 ( & V_123 ) ;
strcpy ( V_7 -> V_50 -> V_138 , V_257 ) ;
F_14 ( & V_123 ) ;
F_14 ( & V_19 ) ;
return 0 ;
}
static int F_178 ( struct V_6 * V_7 , struct V_18 * V_105 ,
struct V_133 * V_134 )
{
if ( ! F_12 ( V_7 ) )
return - V_242 ;
F_100 ( V_134 , V_7 -> V_50 -> V_138 ) ;
F_179 ( V_134 , '\n' ) ;
F_14 ( & V_19 ) ;
return 0 ;
}
static int F_180 ( struct V_6 * V_7 , struct V_18 * V_105 ,
struct V_133 * V_134 )
{
F_99 ( V_134 , L_26 , F_181 ( V_7 ) ) ;
return 0 ;
}
static T_3 F_182 ( struct V_6 * V_7 , struct V_18 * V_105 ,
struct V_258 * V_258 ,
const char T_4 * V_259 ,
T_5 V_260 , T_6 * V_261 )
{
char V_257 [ V_262 ] ;
int V_231 = 0 ;
char * V_263 ;
if ( ! V_260 )
return - V_150 ;
if ( V_260 >= sizeof( V_257 ) )
return - V_264 ;
if ( F_183 ( V_257 , V_259 , V_260 ) )
return - V_265 ;
V_257 [ V_260 ] = 0 ;
if ( V_105 -> V_266 ) {
T_2 V_267 = F_184 ( F_185 ( V_257 ) , & V_263 , 0 ) ;
if ( * V_263 )
return - V_150 ;
V_231 = V_105 -> V_266 ( V_7 , V_105 , V_267 ) ;
} else {
T_7 V_267 = F_186 ( F_185 ( V_257 ) , & V_263 , 0 ) ;
if ( * V_263 )
return - V_150 ;
V_231 = V_105 -> V_268 ( V_7 , V_105 , V_267 ) ;
}
if ( ! V_231 )
V_231 = V_260 ;
return V_231 ;
}
static T_3 F_187 ( struct V_6 * V_7 , struct V_18 * V_105 ,
struct V_258 * V_258 ,
const char T_4 * V_259 ,
T_5 V_260 , T_6 * V_261 )
{
char V_269 [ V_262 ] ;
int V_231 = 0 ;
T_5 V_270 = V_105 -> V_271 ;
char * V_257 = V_269 ;
if ( ! V_270 )
V_270 = sizeof( V_269 ) - 1 ;
if ( V_260 >= V_270 )
return - V_264 ;
if ( V_260 >= sizeof( V_269 ) ) {
V_257 = F_42 ( V_260 + 1 , V_55 ) ;
if ( V_257 == NULL )
return - V_56 ;
}
if ( V_260 && F_183 ( V_257 , V_259 , V_260 ) ) {
V_231 = - V_265 ;
goto V_215;
}
V_257 [ V_260 ] = 0 ;
V_231 = V_105 -> V_272 ( V_7 , V_105 , F_185 ( V_257 ) ) ;
if ( ! V_231 )
V_231 = V_260 ;
V_215:
if ( V_257 != V_269 )
F_28 ( V_257 ) ;
return V_231 ;
}
static T_3 F_188 ( struct V_258 * V_258 , const char T_4 * V_211 ,
T_5 V_260 , T_6 * V_273 )
{
struct V_18 * V_105 = F_11 ( V_258 -> V_274 ) ;
struct V_6 * V_7 = F_9 ( V_258 -> V_274 -> V_101 ) ;
if ( F_4 ( V_7 ) )
return - V_242 ;
if ( V_105 -> V_275 )
return V_105 -> V_275 ( V_7 , V_105 , V_258 , V_211 , V_260 , V_273 ) ;
if ( V_105 -> V_266 || V_105 -> V_268 )
return F_182 ( V_7 , V_105 , V_258 , V_211 , V_260 , V_273 ) ;
if ( V_105 -> V_272 )
return F_187 ( V_7 , V_105 , V_258 , V_211 , V_260 , V_273 ) ;
if ( V_105 -> V_276 ) {
int V_158 = V_105 -> V_276 ( V_7 , ( unsigned int ) V_105 -> V_277 ) ;
return V_158 ? V_158 : V_260 ;
}
return - V_150 ;
}
static T_3 F_189 ( struct V_6 * V_7 , struct V_18 * V_105 ,
struct V_258 * V_258 ,
char T_4 * V_211 , T_5 V_260 ,
T_6 * V_273 )
{
char V_54 [ V_262 ] ;
T_2 V_267 = V_105 -> V_278 ( V_7 , V_105 ) ;
int V_87 = sprintf ( V_54 , L_27 , ( unsigned long long ) V_267 ) ;
return F_190 ( V_211 , V_260 , V_273 , V_54 , V_87 ) ;
}
static T_3 F_191 ( struct V_6 * V_7 , struct V_18 * V_105 ,
struct V_258 * V_258 ,
char T_4 * V_211 , T_5 V_260 ,
T_6 * V_273 )
{
char V_54 [ V_262 ] ;
T_7 V_267 = V_105 -> V_279 ( V_7 , V_105 ) ;
int V_87 = sprintf ( V_54 , L_28 , ( long long ) V_267 ) ;
return F_190 ( V_211 , V_260 , V_273 , V_54 , V_87 ) ;
}
static T_3 F_192 ( struct V_258 * V_258 , char T_4 * V_211 ,
T_5 V_260 , T_6 * V_273 )
{
struct V_18 * V_105 = F_11 ( V_258 -> V_274 ) ;
struct V_6 * V_7 = F_9 ( V_258 -> V_274 -> V_101 ) ;
if ( F_4 ( V_7 ) )
return - V_242 ;
if ( V_105 -> V_280 )
return V_105 -> V_280 ( V_7 , V_105 , V_258 , V_211 , V_260 , V_273 ) ;
if ( V_105 -> V_278 )
return F_189 ( V_7 , V_105 , V_258 , V_211 , V_260 , V_273 ) ;
if ( V_105 -> V_279 )
return F_191 ( V_7 , V_105 , V_258 , V_211 , V_260 , V_273 ) ;
return - V_150 ;
}
static int F_193 ( struct V_281 * V_282 , const char * V_21 , T_2 V_283 )
{
struct V_133 * V_284 = V_282 -> V_285 ;
return F_99 ( V_284 , L_29 , V_21 , ( unsigned long long ) V_283 ) ;
}
static int F_194 ( struct V_133 * V_286 , void * V_287 )
{
struct V_288 * V_285 = V_286 -> V_277 ;
struct V_18 * V_105 = V_285 -> V_105 ;
if ( V_105 -> V_289 ) {
struct V_281 V_282 = {
. V_290 = F_193 ,
. V_285 = V_286 ,
} ;
return V_105 -> V_289 ( V_285 -> V_6 , V_105 , & V_282 ) ;
}
return V_105 -> V_291 ( V_285 -> V_6 , V_105 , V_286 ) ;
}
static int F_195 ( struct V_69 * V_69 , struct V_258 * V_258 )
{
struct V_133 * V_134 = V_258 -> V_292 ;
F_28 ( V_134 -> V_277 ) ;
return F_196 ( V_69 , V_258 ) ;
}
static int F_197 ( struct V_69 * V_69 , struct V_258 * V_258 )
{
int V_293 ;
struct V_18 * V_105 ;
V_293 = F_198 ( V_69 , V_258 ) ;
if ( V_293 )
return V_293 ;
V_105 = F_11 ( V_258 -> V_274 ) ;
if ( V_105 -> V_289 || V_105 -> V_291 ) {
struct V_288 * V_285 =
F_124 ( sizeof( * V_285 ) , V_294 ) ;
if ( ! V_285 )
return - V_56 ;
V_285 -> V_105 = V_105 ;
V_285 -> V_6 = F_9 ( V_258 -> V_274 -> V_101 ) ;
V_258 -> V_295 = & V_296 ;
V_293 = F_199 ( V_258 , F_194 , V_285 ) ;
if ( V_293 < 0 )
F_28 ( V_285 ) ;
} else if ( V_105 -> V_297 )
V_293 = V_105 -> V_297 ( V_69 , V_258 ) ;
else
V_293 = 0 ;
return V_293 ;
}
static int F_200 ( struct V_69 * V_69 , struct V_258 * V_258 )
{
struct V_18 * V_105 = F_11 ( V_258 -> V_274 ) ;
if ( V_105 -> V_298 )
return V_105 -> V_298 ( V_69 , V_258 ) ;
return 0 ;
}
static int F_201 ( struct V_69 * V_299 , struct V_15 * V_300 ,
struct V_69 * V_301 , struct V_15 * V_302 )
{
int V_158 ;
struct V_84 * V_85 , * V_303 ;
struct V_6 * V_7 ;
F_85 ( & V_299 -> V_106 ) ;
if ( ! F_75 ( V_300 -> V_104 -> V_74 ) )
return - V_304 ;
if ( V_302 -> V_104 )
return - V_305 ;
if ( V_299 != V_301 )
return - V_306 ;
V_7 = F_9 ( V_300 ) ;
V_85 = F_63 ( V_302 ) ;
if ( ! V_85 )
return - V_56 ;
V_158 = F_202 ( V_299 , V_300 , V_301 , V_302 ) ;
if ( V_158 ) {
F_28 ( V_85 ) ;
return V_158 ;
}
V_303 = V_7 -> V_85 ;
F_156 ( V_7 -> V_85 , V_85 ) ;
F_29 ( V_303 , V_36 ) ;
return 0 ;
}
static struct V_307 * F_203 ( struct V_15 * V_15 )
{
if ( F_75 ( V_15 -> V_104 -> V_74 ) )
return & F_9 ( V_15 ) -> V_98 ;
else
return & F_10 ( V_15 ) -> V_98 ;
}
static inline int F_204 ( struct V_15 * V_15 )
{
struct V_52 * V_50 = V_15 -> V_114 -> V_115 ;
return V_50 -> V_9 & V_137 ;
}
static bool F_205 ( const char * V_85 )
{
if ( ! strncmp ( V_85 , V_308 , V_309 ) ||
! strncmp ( V_85 , V_310 , V_311 ) )
return true ;
return false ;
}
static int F_206 ( struct V_15 * V_15 , const char * V_85 ,
const void * V_267 , T_5 V_312 , int V_9 )
{
if ( ! F_204 ( V_15 ) )
return - V_313 ;
if ( ! F_205 ( V_85 ) )
return - V_150 ;
return F_207 ( F_203 ( V_15 ) , V_85 , V_267 , V_312 , V_9 ) ;
}
static int F_208 ( struct V_15 * V_15 , const char * V_85 )
{
if ( ! F_204 ( V_15 ) )
return - V_313 ;
if ( ! F_205 ( V_85 ) )
return - V_150 ;
return F_209 ( F_203 ( V_15 ) , V_85 ) ;
}
static T_3 F_210 ( struct V_15 * V_15 , const char * V_85 ,
void * V_211 , T_5 V_312 )
{
if ( ! F_204 ( V_15 ) )
return - V_313 ;
if ( ! F_205 ( V_85 ) )
return - V_150 ;
return F_211 ( F_203 ( V_15 ) , V_85 , V_211 , V_312 ) ;
}
static T_3 F_212 ( struct V_15 * V_15 , char * V_211 , T_5 V_312 )
{
if ( ! F_204 ( V_15 ) )
return - V_313 ;
return F_213 ( F_203 ( V_15 ) , V_211 , V_312 ) ;
}
static struct V_15 * F_214 ( struct V_69 * V_107 , struct V_15 * V_15 , unsigned int V_9 )
{
if ( V_15 -> V_86 . V_87 > V_314 )
return F_125 ( - V_213 ) ;
F_215 ( V_15 , NULL ) ;
return NULL ;
}
static inline struct V_18 * F_216 ( struct V_258 * V_258 )
{
if ( F_217 ( V_258 ) -> V_193 != & V_315 )
return F_125 ( - V_150 ) ;
return F_11 ( V_258 -> V_274 ) ;
}
static int F_218 ( struct V_15 * V_15 , T_1 V_70 ,
struct V_71 * V_72 )
{
struct V_69 * V_69 ;
if ( ! V_15 )
return - V_157 ;
if ( V_15 -> V_104 )
return - V_305 ;
V_69 = F_58 ( V_70 , V_72 ) ;
if ( ! V_69 )
return - V_56 ;
if ( F_75 ( V_70 ) ) {
V_69 -> V_195 = & V_196 ;
V_69 -> V_193 = & V_194 ;
F_133 ( V_69 ) ;
F_133 ( V_15 -> V_101 -> V_104 ) ;
F_154 ( ! F_219 ( & V_69 -> V_106 ) ) ;
} else if ( F_220 ( V_70 ) ) {
V_69 -> V_316 = 0 ;
V_69 -> V_193 = & V_315 ;
V_69 -> V_195 = & V_317 ;
}
F_221 ( V_15 , V_69 ) ;
F_81 ( V_15 ) ;
return 0 ;
}
static T_1 F_222 ( const struct V_18 * V_105 )
{
T_1 V_70 = 0 ;
if ( V_105 -> V_70 )
return V_105 -> V_70 ;
if ( V_105 -> V_280 || V_105 -> V_278 || V_105 -> V_279 ||
V_105 -> V_289 || V_105 -> V_291 )
V_70 |= V_190 ;
if ( V_105 -> V_275 || V_105 -> V_266 || V_105 -> V_268 ||
V_105 -> V_272 || V_105 -> V_276 )
V_70 |= V_192 ;
return V_70 ;
}
static int F_223 ( struct V_6 * V_7 , struct V_91 * V_43 ,
struct V_18 * V_105 )
{
struct V_15 * V_107 = V_7 -> V_15 ;
struct V_6 * V_11 = F_9 ( V_107 ) ;
struct V_15 * V_15 ;
struct V_17 * V_100 ;
int error ;
T_1 V_70 ;
char V_85 [ V_318 + V_319 + 2 ] = { 0 } ;
if ( V_43 && ! ( V_7 -> V_50 -> V_9 & V_136 ) ) {
strcpy ( V_85 , V_43 -> V_85 ) ;
strcat ( V_85 , L_30 ) ;
}
strcat ( V_85 , V_105 -> V_85 ) ;
F_35 ( ! F_57 ( & V_107 -> V_104 -> V_106 ) ) ;
V_100 = F_124 ( sizeof( * V_100 ) , V_55 ) ;
if ( ! V_100 )
return - V_56 ;
V_15 = F_224 ( V_85 , V_107 , strlen ( V_85 ) ) ;
if ( F_136 ( V_15 ) ) {
error = F_137 ( V_15 ) ;
goto V_215;
}
V_100 -> type = ( void * ) V_105 ;
V_100 -> V_15 = V_15 ;
V_15 -> V_16 = V_100 ;
F_116 ( & V_100 -> V_98 ) ;
V_70 = F_222 ( V_105 ) ;
error = F_218 ( V_15 , V_70 | V_320 , V_7 -> V_50 -> V_72 ) ;
if ( ! error ) {
F_48 ( & V_100 -> V_102 , & V_11 -> V_113 ) ;
V_100 = NULL ;
}
F_67 ( V_15 ) ;
V_215:
F_28 ( V_100 ) ;
return error ;
}
static int F_89 ( struct V_6 * V_7 , struct V_91 * V_43 ,
struct V_18 V_112 [] , bool V_321 )
{
struct V_18 * V_105 ;
int V_293 , V_158 = 0 ;
for ( V_105 = V_112 ; V_105 -> V_85 [ 0 ] != '\0' ; V_105 ++ ) {
if ( ( V_105 -> V_9 & V_322 ) && F_181 ( V_7 ) )
continue;
if ( ( V_105 -> V_9 & V_323 ) && ! V_7 -> V_11 )
continue;
if ( ( V_105 -> V_9 & V_324 ) && V_7 -> V_11 )
continue;
if ( V_321 ) {
V_293 = F_223 ( V_7 , V_43 , V_105 ) ;
if ( V_293 )
F_225 ( L_31 ,
V_105 -> V_85 , V_293 ) ;
V_158 = V_293 ;
} else {
F_84 ( V_7 , V_105 ) ;
}
}
return V_158 ;
}
static void F_226 ( void )
__acquires( &cgroup_cft_mutex
static void F_227 ( struct V_91 * V_92 ,
struct V_18 * V_112 , bool V_321 )
__releases( &cgroup_mutex
int F_228 ( struct V_91 * V_92 , struct V_18 * V_112 )
{
struct V_109 * V_110 ;
V_110 = F_124 ( sizeof( * V_110 ) , V_55 ) ;
if ( ! V_110 )
return - V_56 ;
F_226 () ;
V_110 -> V_112 = V_112 ;
F_48 ( & V_110 -> V_102 , & V_92 -> V_325 ) ;
F_227 ( V_92 , V_112 , true ) ;
return 0 ;
}
int F_229 ( struct V_91 * V_92 , struct V_18 * V_112 )
{
struct V_109 * V_110 ;
F_226 () ;
F_54 (set, &ss->cftsets, node) {
if ( V_110 -> V_112 == V_112 ) {
F_87 ( & V_110 -> V_102 ) ;
F_227 ( V_92 , V_112 , false ) ;
return 0 ;
}
}
F_227 ( V_92 , NULL , false ) ;
return - V_157 ;
}
int F_230 ( const struct V_6 * V_7 )
{
int V_35 = 0 ;
struct V_26 * V_27 ;
F_50 ( & V_30 ) ;
F_54 (link, &cgrp->css_sets, cgrp_link_list) {
V_35 += F_3 ( & V_27 -> V_24 -> V_29 ) ;
}
F_51 ( & V_30 ) ;
return V_35 ;
}
static void F_231 ( struct V_6 * V_7 ,
struct V_326 * V_327 )
{
struct V_40 * V_328 = V_327 -> V_329 ;
struct V_26 * V_27 ;
struct V_23 * V_24 ;
do {
V_328 = V_328 -> V_49 ;
if ( V_328 == & V_7 -> V_58 ) {
V_327 -> V_329 = NULL ;
return;
}
V_27 = F_36 ( V_328 , struct V_26 , V_34 ) ;
V_24 = V_27 -> V_24 ;
} while ( F_45 ( & V_24 -> V_61 ) );
V_327 -> V_329 = V_328 ;
V_327 -> V_65 = V_24 -> V_61 . V_49 ;
}
static void F_232 ( void )
{
struct V_64 * V_330 , * V_331 ;
F_18 ( & V_30 ) ;
V_332 = 1 ;
F_50 ( & V_333 ) ;
F_233 (g, p) {
F_155 ( V_330 ) ;
if ( ! ( V_330 -> V_9 & V_228 ) && F_45 ( & V_330 -> V_229 ) )
F_43 ( & V_330 -> V_229 , & V_330 -> V_66 -> V_61 ) ;
F_157 ( V_330 ) ;
} F_234 ( V_331 , V_330 ) ;
F_51 ( & V_333 ) ;
F_20 ( & V_30 ) ;
}
struct V_6 * F_235 ( struct V_6 * V_334 ,
struct V_6 * V_6 )
{
struct V_6 * V_49 ;
F_154 ( ! F_236 () ) ;
if ( ! V_334 )
V_334 = V_6 ;
V_49 = F_237 ( & V_334 -> V_162 , struct V_6 , V_129 ) ;
if ( V_49 )
return V_49 ;
while ( V_334 != V_6 ) {
V_49 = F_238 ( V_334 -> V_129 . V_49 , struct V_6 ,
V_129 ) ;
if ( & V_49 -> V_129 != & V_334 -> V_11 -> V_162 )
return V_49 ;
V_334 = V_334 -> V_11 ;
}
return NULL ;
}
struct V_6 * F_239 ( struct V_6 * V_334 )
{
struct V_6 * V_335 , * V_54 ;
F_154 ( ! F_236 () ) ;
do {
V_335 = V_334 ;
V_334 = NULL ;
F_240 (tmp, &last->children, sibling)
V_334 = V_54 ;
} while ( V_334 );
return V_335 ;
}
static struct V_6 * F_241 ( struct V_6 * V_334 )
{
struct V_6 * V_335 ;
do {
V_335 = V_334 ;
V_334 = F_237 ( & V_334 -> V_162 , struct V_6 ,
V_129 ) ;
} while ( V_334 );
return V_335 ;
}
struct V_6 * F_242 ( struct V_6 * V_334 ,
struct V_6 * V_6 )
{
struct V_6 * V_49 ;
F_154 ( ! F_236 () ) ;
if ( ! V_334 ) {
V_49 = F_241 ( V_6 ) ;
return V_49 != V_6 ? V_49 : NULL ;
}
V_49 = F_238 ( V_334 -> V_129 . V_49 , struct V_6 , V_129 ) ;
if ( & V_49 -> V_129 != & V_334 -> V_11 -> V_162 )
return F_241 ( V_49 ) ;
V_49 = V_334 -> V_11 ;
return V_49 != V_6 ? V_49 : NULL ;
}
void F_243 ( struct V_6 * V_7 , struct V_326 * V_327 )
__acquires( V_30 )
{
if ( ! V_332 )
F_232 () ;
F_50 ( & V_30 ) ;
V_327 -> V_329 = & V_7 -> V_58 ;
F_231 ( V_7 , V_327 ) ;
}
struct V_64 * F_244 ( struct V_6 * V_7 ,
struct V_326 * V_327 )
{
struct V_64 * V_59 ;
struct V_40 * V_328 = V_327 -> V_65 ;
struct V_26 * V_27 ;
if ( ! V_327 -> V_329 )
return NULL ;
V_59 = F_36 ( V_328 , struct V_64 , V_229 ) ;
V_328 = V_328 -> V_49 ;
V_27 = F_36 ( V_327 -> V_329 , struct V_26 , V_34 ) ;
if ( V_328 == & V_27 -> V_24 -> V_61 ) {
F_231 ( V_7 , V_327 ) ;
} else {
V_327 -> V_65 = V_328 ;
}
return V_59 ;
}
void F_245 ( struct V_6 * V_7 , struct V_326 * V_327 )
__releases( V_30 )
{
F_51 ( & V_30 ) ;
}
static inline int F_246 ( struct V_64 * V_336 ,
struct V_337 * time ,
struct V_64 * V_338 )
{
int V_339 = F_247 ( & V_336 -> V_340 , time ) ;
if ( V_339 > 0 ) {
return 1 ;
} else if ( V_339 < 0 ) {
return 0 ;
} else {
return V_336 > V_338 ;
}
}
static inline int F_248 ( void * V_341 , void * V_342 )
{
struct V_64 * V_336 = V_341 ;
struct V_64 * V_338 = V_342 ;
return F_246 ( V_336 , & V_338 -> V_340 , V_338 ) ;
}
int F_249 ( struct V_343 * V_344 )
{
int V_231 , V_20 ;
struct V_326 V_327 ;
struct V_64 * V_330 , * V_345 ;
struct V_64 * V_346 = NULL ;
struct V_347 V_348 ;
struct V_347 * V_349 ;
struct V_337 V_350 = { 0 , 0 } ;
if ( V_344 -> V_349 ) {
V_349 = V_344 -> V_349 ;
V_349 -> V_351 = & F_248 ;
} else {
V_349 = & V_348 ;
V_231 = F_250 ( V_349 , V_352 , V_55 , & F_248 ) ;
if ( V_231 )
return V_231 ;
}
V_353:
V_349 -> V_312 = 0 ;
F_243 ( V_344 -> V_24 , & V_327 ) ;
while ( ( V_330 = F_244 ( V_344 -> V_24 , & V_327 ) ) ) {
if ( V_344 -> V_354 && ! V_344 -> V_354 ( V_330 , V_344 ) )
continue;
if ( ! F_246 ( V_330 , & V_350 , V_346 ) )
continue;
V_345 = F_251 ( V_349 , V_330 ) ;
if ( V_345 == NULL ) {
F_168 ( V_330 ) ;
} else if ( V_345 != V_330 ) {
F_168 ( V_330 ) ;
F_172 ( V_345 ) ;
}
}
F_245 ( V_344 -> V_24 , & V_327 ) ;
if ( V_349 -> V_312 ) {
for ( V_20 = 0 ; V_20 < V_349 -> V_312 ; V_20 ++ ) {
struct V_64 * V_355 = V_349 -> V_356 [ V_20 ] ;
if ( V_20 == 0 ) {
V_350 = V_355 -> V_340 ;
V_346 = V_355 ;
}
V_344 -> V_357 ( V_355 , V_344 ) ;
F_172 ( V_355 ) ;
}
goto V_353;
}
if ( V_349 == & V_348 )
F_252 ( & V_348 ) ;
return 0 ;
}
static void F_253 ( struct V_64 * V_65 ,
struct V_343 * V_344 )
{
struct V_6 * V_358 = V_344 -> V_140 ;
F_13 ( & V_19 ) ;
F_158 ( V_358 , V_65 , false ) ;
F_14 ( & V_19 ) ;
}
int F_254 ( struct V_6 * V_359 , struct V_6 * V_254 )
{
struct V_343 V_344 ;
V_344 . V_24 = V_254 ;
V_344 . V_354 = NULL ;
V_344 . V_357 = F_253 ;
V_344 . V_349 = NULL ;
V_344 . V_140 = V_359 ;
return F_249 ( & V_344 ) ;
}
static void * F_255 ( int V_35 )
{
if ( F_256 ( V_35 ) )
return F_257 ( V_35 * sizeof( V_360 ) ) ;
else
return F_42 ( V_35 * sizeof( V_360 ) , V_55 ) ;
}
static void F_258 ( void * V_330 )
{
if ( F_259 ( V_330 ) )
F_260 ( V_330 ) ;
else
F_28 ( V_330 ) ;
}
static int F_261 ( V_360 * V_361 , int V_362 )
{
int V_363 , V_364 = 1 ;
if ( V_362 == 0 || V_362 == 1 )
return V_362 ;
for ( V_363 = 1 ; V_363 < V_362 ; V_363 ++ ) {
while ( V_361 [ V_363 ] == V_361 [ V_363 - 1 ] ) {
V_363 ++ ;
if ( V_363 == V_362 )
goto V_365;
}
V_361 [ V_364 ] = V_361 [ V_363 ] ;
V_364 ++ ;
}
V_365:
return V_364 ;
}
static int F_262 ( const void * V_366 , const void * V_367 )
{
return * ( V_360 * ) V_366 - * ( V_360 * ) V_367 ;
}
static struct V_368 * F_263 ( struct V_6 * V_7 ,
enum V_369 type )
{
struct V_368 * V_328 ;
struct V_370 * V_371 = F_264 ( V_160 ) ;
F_13 ( & V_7 -> V_165 ) ;
F_54 (l, &cgrp->pidlists, links) {
if ( V_328 -> V_21 . type == type && V_328 -> V_21 . V_371 == V_371 ) {
F_265 ( & V_328 -> V_372 ) ;
F_14 ( & V_7 -> V_165 ) ;
return V_328 ;
}
}
V_328 = F_42 ( sizeof( struct V_368 ) , V_55 ) ;
if ( ! V_328 ) {
F_14 ( & V_7 -> V_165 ) ;
return V_328 ;
}
F_266 ( & V_328 -> V_372 ) ;
F_265 ( & V_328 -> V_372 ) ;
V_328 -> V_21 . type = type ;
V_328 -> V_21 . V_371 = F_267 ( V_371 ) ;
V_328 -> V_373 = 0 ;
V_328 -> V_361 = NULL ;
V_328 -> V_374 = V_7 ;
F_43 ( & V_328 -> V_375 , & V_7 -> V_97 ) ;
F_14 ( & V_7 -> V_165 ) ;
return V_328 ;
}
static int F_268 ( struct V_6 * V_7 , enum V_369 type ,
struct V_368 * * V_376 )
{
V_360 * V_377 ;
int V_362 ;
int V_240 , V_378 = 0 ;
struct V_326 V_327 ;
struct V_64 * V_226 ;
struct V_368 * V_328 ;
V_362 = F_230 ( V_7 ) ;
V_377 = F_255 ( V_362 ) ;
if ( ! V_377 )
return - V_56 ;
F_243 ( V_7 , & V_327 ) ;
while ( ( V_226 = F_244 ( V_7 , & V_327 ) ) ) {
if ( F_269 ( V_378 == V_362 ) )
break;
if ( type == V_379 )
V_240 = F_270 ( V_226 ) ;
else
V_240 = F_271 ( V_226 ) ;
if ( V_240 > 0 )
V_377 [ V_378 ++ ] = V_240 ;
}
F_245 ( V_7 , & V_327 ) ;
V_362 = V_378 ;
F_272 ( V_377 , V_362 , sizeof( V_360 ) , F_262 , NULL ) ;
if ( type == V_379 )
V_362 = F_261 ( V_377 , V_362 ) ;
V_328 = F_263 ( V_7 , type ) ;
if ( ! V_328 ) {
F_258 ( V_377 ) ;
return - V_56 ;
}
F_258 ( V_328 -> V_361 ) ;
V_328 -> V_361 = V_377 ;
V_328 -> V_362 = V_362 ;
V_328 -> V_373 ++ ;
F_273 ( & V_328 -> V_372 ) ;
* V_376 = V_328 ;
return 0 ;
}
int F_274 ( struct V_380 * V_381 , struct V_15 * V_15 )
{
int V_158 = - V_150 ;
struct V_6 * V_7 ;
struct V_326 V_327 ;
struct V_64 * V_226 ;
if ( V_15 -> V_114 -> V_184 != & V_185 ||
! F_75 ( V_15 -> V_104 -> V_74 ) )
goto V_293;
V_158 = 0 ;
V_7 = V_15 -> V_16 ;
F_243 ( V_7 , & V_327 ) ;
while ( ( V_226 = F_244 ( V_7 , & V_327 ) ) ) {
switch ( V_226 -> V_285 ) {
case V_382 :
V_381 -> V_383 ++ ;
break;
case V_384 :
V_381 -> V_385 ++ ;
break;
case V_386 :
V_381 -> V_387 ++ ;
break;
case V_388 :
V_381 -> V_389 ++ ;
break;
default:
if ( F_275 ( V_226 ) )
V_381 -> V_390 ++ ;
break;
}
}
F_245 ( V_7 , & V_327 ) ;
V_293:
return V_158 ;
}
static void * F_276 ( struct V_133 * V_391 , T_6 * V_334 )
{
struct V_368 * V_328 = V_391 -> V_277 ;
int V_392 = 0 , V_240 = * V_334 ;
int * V_393 ;
F_277 ( & V_328 -> V_372 ) ;
if ( V_240 ) {
int V_263 = V_328 -> V_362 ;
while ( V_392 < V_263 ) {
int V_394 = ( V_392 + V_263 ) / 2 ;
if ( V_328 -> V_361 [ V_394 ] == V_240 ) {
V_392 = V_394 ;
break;
} else if ( V_328 -> V_361 [ V_394 ] <= V_240 )
V_392 = V_394 + 1 ;
else
V_263 = V_394 ;
}
}
if ( V_392 >= V_328 -> V_362 )
return NULL ;
V_393 = V_328 -> V_361 + V_392 ;
* V_334 = * V_393 ;
return V_393 ;
}
static void F_278 ( struct V_133 * V_391 , void * V_5 )
{
struct V_368 * V_328 = V_391 -> V_277 ;
F_279 ( & V_328 -> V_372 ) ;
}
static void * F_280 ( struct V_133 * V_391 , void * V_5 , T_6 * V_334 )
{
struct V_368 * V_328 = V_391 -> V_277 ;
V_360 * V_330 = V_5 ;
V_360 * V_263 = V_328 -> V_361 + V_328 -> V_362 ;
V_330 ++ ;
if ( V_330 >= V_263 ) {
return NULL ;
} else {
* V_334 = * V_330 ;
return V_330 ;
}
}
static int F_281 ( struct V_133 * V_391 , void * V_5 )
{
return F_99 ( V_391 , L_26 , * ( int * ) V_5 ) ;
}
static void F_282 ( struct V_368 * V_328 )
{
F_13 ( & V_328 -> V_374 -> V_165 ) ;
F_265 ( & V_328 -> V_372 ) ;
F_35 ( ! V_328 -> V_373 ) ;
if ( ! -- V_328 -> V_373 ) {
F_23 ( & V_328 -> V_375 ) ;
F_14 ( & V_328 -> V_374 -> V_165 ) ;
F_258 ( V_328 -> V_361 ) ;
F_283 ( V_328 -> V_21 . V_371 ) ;
F_273 ( & V_328 -> V_372 ) ;
F_28 ( V_328 ) ;
return;
}
F_14 ( & V_328 -> V_374 -> V_165 ) ;
F_273 ( & V_328 -> V_372 ) ;
}
static int F_284 ( struct V_69 * V_69 , struct V_258 * V_258 )
{
struct V_368 * V_328 ;
if ( ! ( V_258 -> V_395 & V_396 ) )
return 0 ;
V_328 = ( (struct V_133 * ) V_258 -> V_292 ) -> V_277 ;
F_282 ( V_328 ) ;
return F_285 ( V_69 , V_258 ) ;
}
static int F_286 ( struct V_258 * V_258 , enum V_369 type )
{
struct V_6 * V_7 = F_9 ( V_258 -> V_274 -> V_101 ) ;
struct V_368 * V_328 ;
int V_231 ;
if ( ! ( V_258 -> V_395 & V_396 ) )
return 0 ;
V_231 = F_268 ( V_7 , type , & V_328 ) ;
if ( V_231 )
return V_231 ;
V_258 -> V_295 = & V_397 ;
V_231 = F_287 ( V_258 , & V_398 ) ;
if ( V_231 ) {
F_282 ( V_328 ) ;
return V_231 ;
}
( (struct V_133 * ) V_258 -> V_292 ) -> V_277 = V_328 ;
return 0 ;
}
static int F_288 ( struct V_69 * V_399 , struct V_258 * V_258 )
{
return F_286 ( V_258 , V_400 ) ;
}
static int F_289 ( struct V_69 * V_399 , struct V_258 * V_258 )
{
return F_286 ( V_258 , V_379 ) ;
}
static T_2 F_290 ( struct V_6 * V_7 ,
struct V_18 * V_105 )
{
return F_8 ( V_7 ) ;
}
static int F_291 ( struct V_6 * V_7 ,
struct V_18 * V_105 ,
T_2 V_267 )
{
F_292 ( V_13 , & V_7 -> V_9 ) ;
if ( V_267 )
F_25 ( V_14 , & V_7 -> V_9 ) ;
else
F_292 ( V_14 , & V_7 -> V_9 ) ;
return 0 ;
}
static void F_293 ( struct V_88 * V_89 )
{
struct V_401 * V_402 = F_65 ( V_89 , struct V_401 ,
remove ) ;
struct V_6 * V_7 = V_402 -> V_7 ;
F_294 ( V_402 -> V_403 , & V_402 -> V_404 ) ;
V_402 -> V_105 -> V_405 ( V_7 , V_402 -> V_105 , V_402 -> V_406 ) ;
F_295 ( V_402 -> V_406 , 1 ) ;
F_296 ( V_402 -> V_406 ) ;
F_28 ( V_402 ) ;
F_67 ( V_7 -> V_15 ) ;
}
static int F_297 ( T_8 * V_404 , unsigned V_70 ,
int V_407 , void * V_21 )
{
struct V_401 * V_402 = F_65 ( V_404 ,
struct V_401 , V_404 ) ;
struct V_6 * V_7 = V_402 -> V_7 ;
unsigned long V_9 = ( unsigned long ) V_21 ;
if ( V_9 & V_408 ) {
F_91 ( & V_7 -> V_167 ) ;
if ( ! F_45 ( & V_402 -> V_361 ) ) {
F_87 ( & V_402 -> V_361 ) ;
F_73 ( & V_402 -> remove ) ;
}
F_93 ( & V_7 -> V_167 ) ;
}
return 0 ;
}
static void F_298 ( struct V_258 * V_258 ,
T_9 * V_403 , T_10 * V_409 )
{
struct V_401 * V_402 = F_65 ( V_409 ,
struct V_401 , V_409 ) ;
V_402 -> V_403 = V_403 ;
F_299 ( V_403 , & V_402 -> V_404 ) ;
}
static int F_300 ( struct V_6 * V_7 , struct V_18 * V_105 ,
const char * V_257 )
{
struct V_401 * V_402 = NULL ;
struct V_6 * V_410 ;
unsigned int V_411 , V_412 ;
struct V_258 * V_413 = NULL ;
struct V_258 * V_414 = NULL ;
char * V_415 ;
int V_158 ;
V_411 = F_301 ( V_257 , & V_415 , 10 ) ;
if ( * V_415 != ' ' )
return - V_150 ;
V_257 = V_415 + 1 ;
V_412 = F_301 ( V_257 , & V_415 , 10 ) ;
if ( ( * V_415 != ' ' ) && ( * V_415 != '\0' ) )
return - V_150 ;
V_257 = V_415 + 1 ;
V_402 = F_124 ( sizeof( * V_402 ) , V_55 ) ;
if ( ! V_402 )
return - V_56 ;
V_402 -> V_7 = V_7 ;
F_41 ( & V_402 -> V_361 ) ;
F_302 ( & V_402 -> V_409 , F_298 ) ;
F_303 ( & V_402 -> V_404 , F_297 ) ;
F_113 ( & V_402 -> remove , F_293 ) ;
V_413 = F_304 ( V_411 ) ;
if ( F_136 ( V_413 ) ) {
V_158 = F_137 ( V_413 ) ;
goto V_416;
}
V_402 -> V_406 = F_305 ( V_413 ) ;
if ( F_136 ( V_402 -> V_406 ) ) {
V_158 = F_137 ( V_402 -> V_406 ) ;
goto V_416;
}
V_414 = F_306 ( V_412 ) ;
if ( ! V_414 ) {
V_158 = - V_417 ;
goto V_416;
}
V_158 = F_307 ( F_217 ( V_414 ) , V_418 ) ;
if ( V_158 < 0 )
goto V_416;
V_402 -> V_105 = F_216 ( V_414 ) ;
if ( F_136 ( V_402 -> V_105 ) ) {
V_158 = F_137 ( V_402 -> V_105 ) ;
goto V_416;
}
V_410 = F_9 ( V_414 -> V_274 -> V_101 ) ;
if ( V_410 != V_7 ) {
V_158 = - V_150 ;
goto V_416;
}
if ( ! V_402 -> V_105 -> V_419 || ! V_402 -> V_105 -> V_405 ) {
V_158 = - V_150 ;
goto V_416;
}
V_158 = V_402 -> V_105 -> V_419 ( V_7 , V_402 -> V_105 ,
V_402 -> V_406 , V_257 ) ;
if ( V_158 )
goto V_416;
V_413 -> V_295 -> V_420 ( V_413 , & V_402 -> V_409 ) ;
F_81 ( V_7 -> V_15 ) ;
F_91 ( & V_7 -> V_167 ) ;
F_43 ( & V_402 -> V_361 , & V_7 -> V_166 ) ;
F_93 ( & V_7 -> V_167 ) ;
F_308 ( V_414 ) ;
F_308 ( V_413 ) ;
return 0 ;
V_416:
if ( V_414 )
F_308 ( V_414 ) ;
if ( V_402 && V_402 -> V_406 && ! F_136 ( V_402 -> V_406 ) )
F_296 ( V_402 -> V_406 ) ;
if ( ! F_309 ( V_413 ) )
F_308 ( V_413 ) ;
F_28 ( V_402 ) ;
return V_158 ;
}
static T_2 F_310 ( struct V_6 * V_7 ,
struct V_18 * V_105 )
{
return F_5 ( V_139 , & V_7 -> V_9 ) ;
}
static int F_311 ( struct V_6 * V_7 ,
struct V_18 * V_105 ,
T_2 V_267 )
{
if ( V_267 )
F_25 ( V_139 , & V_7 -> V_9 ) ;
else
F_292 ( V_139 , & V_7 -> V_9 ) ;
return 0 ;
}
static int F_111 ( struct V_6 * V_7 , bool V_108 ,
unsigned long V_53 )
{
int V_293 ;
struct V_91 * V_92 ;
if ( V_108 ) {
V_293 = F_89 ( V_7 , NULL , V_113 , true ) ;
if ( V_293 < 0 )
return V_293 ;
}
F_66 (cgrp->root, ss) {
struct V_109 * V_110 ;
if ( ! F_5 ( V_92 -> V_111 , & V_53 ) )
continue;
F_54 (set, &ss->cftsets, node)
F_89 ( V_7 , V_92 , V_110 -> V_112 , true ) ;
}
F_66 (cgrp->root, ss) {
struct V_3 * V_4 = V_7 -> V_43 [ V_92 -> V_111 ] ;
if ( V_4 -> V_96 )
F_156 ( V_4 -> V_96 -> V_4 , V_4 ) ;
}
return 0 ;
}
static void F_312 ( struct V_88 * V_89 )
{
struct V_3 * V_4 =
F_65 ( V_89 , struct V_3 , V_421 ) ;
struct V_15 * V_15 = V_4 -> V_6 -> V_15 ;
struct V_71 * V_72 = V_15 -> V_114 ;
F_31 ( & V_72 -> V_422 ) ;
F_67 ( V_15 ) ;
F_69 ( V_72 ) ;
}
static void F_313 ( struct V_3 * V_4 ,
struct V_91 * V_92 ,
struct V_6 * V_7 )
{
V_4 -> V_6 = V_7 ;
F_52 ( & V_4 -> V_1 , 1 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_96 = NULL ;
if ( V_7 == V_128 )
V_4 -> V_9 |= V_423 ;
F_35 ( V_7 -> V_43 [ V_92 -> V_111 ] ) ;
V_7 -> V_43 [ V_92 -> V_111 ] = V_4 ;
F_113 ( & V_4 -> V_421 , F_312 ) ;
}
static int F_314 ( struct V_91 * V_92 , struct V_6 * V_7 )
{
int V_158 = 0 ;
F_85 ( & V_19 ) ;
if ( V_92 -> V_424 )
V_158 = V_92 -> V_424 ( V_7 ) ;
if ( ! V_158 )
V_7 -> V_43 [ V_92 -> V_111 ] -> V_9 |= V_425 ;
return V_158 ;
}
static void F_315 ( struct V_91 * V_92 , struct V_6 * V_7 )
__releases( &cgroup_mutex
static long F_316 ( struct V_6 * V_11 , struct V_15 * V_15 ,
T_1 V_70 )
{
struct V_6 * V_7 ;
struct V_84 * V_85 ;
struct V_52 * V_50 = V_11 -> V_50 ;
int V_293 = 0 ;
struct V_91 * V_92 ;
struct V_71 * V_72 = V_50 -> V_72 ;
V_7 = F_124 ( sizeof( * V_7 ) , V_55 ) ;
if ( ! V_7 )
return - V_56 ;
V_85 = F_63 ( V_15 ) ;
if ( ! V_85 )
goto V_426;
F_156 ( V_7 -> V_85 , V_85 ) ;
V_7 -> V_96 = F_317 ( & V_50 -> V_95 , 1 , 0 , V_55 ) ;
if ( V_7 -> V_96 < 0 )
goto V_427;
if ( ! F_12 ( V_11 ) ) {
V_293 = - V_242 ;
goto V_428;
}
F_31 ( & V_72 -> V_422 ) ;
F_112 ( V_7 ) ;
V_15 -> V_16 = V_7 ;
V_7 -> V_15 = V_15 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_50 = V_11 -> V_50 ;
if ( F_8 ( V_11 ) )
F_25 ( V_14 , & V_7 -> V_9 ) ;
if ( F_5 ( V_139 , & V_11 -> V_9 ) )
F_25 ( V_139 , & V_7 -> V_9 ) ;
F_66 (root, ss) {
struct V_3 * V_4 ;
V_4 = V_92 -> V_429 ( V_7 ) ;
if ( F_136 ( V_4 ) ) {
V_293 = F_137 ( V_4 ) ;
goto V_430;
}
F_313 ( V_4 , V_92 , V_7 ) ;
if ( V_92 -> V_431 ) {
V_293 = F_318 ( V_92 , V_11 , V_7 ) ;
if ( V_293 )
goto V_430;
}
}
V_293 = F_218 ( V_15 , V_189 | V_70 , V_72 ) ;
if ( V_293 < 0 )
goto V_430;
F_85 ( & V_15 -> V_104 -> V_106 ) ;
F_48 ( & V_7 -> V_163 , & V_50 -> V_169 ) ;
F_319 ( & V_7 -> V_129 , & V_7 -> V_11 -> V_162 ) ;
V_50 -> V_94 ++ ;
F_66 (root, ss)
F_81 ( V_15 ) ;
F_81 ( V_11 -> V_15 ) ;
F_66 (root, ss) {
V_293 = F_314 ( V_92 , V_7 ) ;
if ( V_293 )
goto V_432;
if ( V_92 -> V_433 && ! V_92 -> V_434 &&
V_11 -> V_11 ) {
F_105 ( L_32 ,
V_160 -> V_161 , V_160 -> V_240 , V_92 -> V_85 ) ;
if ( ! strcmp ( V_92 -> V_85 , L_33 ) )
F_105 ( L_34 ) ;
V_92 -> V_434 = true ;
}
}
V_293 = F_111 ( V_7 , true , V_50 -> V_53 ) ;
if ( V_293 )
goto V_432;
F_14 ( & V_19 ) ;
F_14 ( & V_7 -> V_15 -> V_104 -> V_106 ) ;
return 0 ;
V_430:
F_66 (root, ss) {
if ( V_7 -> V_43 [ V_92 -> V_111 ] )
V_92 -> V_93 ( V_7 ) ;
}
F_14 ( & V_19 ) ;
F_69 ( V_72 ) ;
V_428:
F_68 ( & V_50 -> V_95 , V_7 -> V_96 ) ;
V_427:
F_28 ( F_71 ( V_7 -> V_85 ) ) ;
V_426:
F_28 ( V_7 ) ;
return V_293 ;
V_432:
F_320 ( V_7 ) ;
F_14 ( & V_19 ) ;
F_14 ( & V_15 -> V_104 -> V_106 ) ;
return V_293 ;
}
static int F_321 ( struct V_69 * V_107 , struct V_15 * V_15 , T_1 V_70 )
{
struct V_6 * V_435 = V_15 -> V_101 -> V_16 ;
return F_316 ( V_435 , V_15 , V_70 | V_189 ) ;
}
static int F_320 ( struct V_6 * V_7 )
__releases( &cgroup_mutex
static int F_322 ( struct V_69 * V_436 , struct V_15 * V_15 )
{
int V_158 ;
F_13 ( & V_19 ) ;
V_158 = F_320 ( V_15 -> V_16 ) ;
F_14 ( & V_19 ) ;
return V_158 ;
}
static void T_11 F_323 ( struct V_91 * V_92 )
{
F_41 ( & V_92 -> V_325 ) ;
if ( V_92 -> V_437 ) {
V_92 -> V_438 . V_112 = V_92 -> V_437 ;
F_48 ( & V_92 -> V_438 . V_102 , & V_92 -> V_325 ) ;
}
}
static void T_12 F_324 ( struct V_91 * V_92 )
{
struct V_3 * V_4 ;
F_325 ( V_439 L_35 , V_92 -> V_85 ) ;
F_13 ( & V_19 ) ;
F_323 ( V_92 ) ;
F_43 ( & V_92 -> V_129 , & V_126 . V_130 ) ;
V_92 -> V_50 = & V_126 ;
V_4 = V_92 -> V_429 ( V_128 ) ;
F_35 ( F_136 ( V_4 ) ) ;
F_313 ( V_4 , V_92 , V_128 ) ;
V_67 . V_43 [ V_92 -> V_111 ] = V_4 ;
V_440 |= V_92 -> V_441 || V_92 -> exit ;
F_35 ( ! F_45 ( & V_442 . V_61 ) ) ;
F_35 ( F_314 ( V_92 , V_128 ) ) ;
F_14 ( & V_19 ) ;
F_35 ( V_92 -> V_132 ) ;
}
int T_11 F_326 ( struct V_91 * V_92 )
{
struct V_3 * V_4 ;
int V_20 , V_158 ;
struct V_443 * V_54 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
if ( V_92 -> V_85 == NULL || strlen ( V_92 -> V_85 ) > V_318 ||
V_92 -> V_429 == NULL || V_92 -> V_93 == NULL )
return - V_150 ;
if ( V_92 -> V_441 || V_92 -> exit )
return - V_150 ;
if ( V_92 -> V_132 == NULL ) {
F_35 ( V_43 [ V_92 -> V_111 ] != V_92 ) ;
return 0 ;
}
F_323 ( V_92 ) ;
F_13 ( & V_19 ) ;
V_43 [ V_92 -> V_111 ] = V_92 ;
V_4 = V_92 -> V_429 ( V_128 ) ;
if ( F_136 ( V_4 ) ) {
V_43 [ V_92 -> V_111 ] = NULL ;
F_14 ( & V_19 ) ;
return F_137 ( V_4 ) ;
}
F_43 ( & V_92 -> V_129 , & V_126 . V_130 ) ;
V_92 -> V_50 = & V_126 ;
F_313 ( V_4 , V_92 , V_128 ) ;
if ( V_92 -> V_431 ) {
V_158 = F_327 ( V_92 , V_4 ) ;
if ( V_158 )
goto V_444;
}
F_18 ( & V_30 ) ;
F_328 (css_set_table, i, tmp, cg, hlist) {
if ( V_24 -> V_43 [ V_92 -> V_111 ] )
continue;
F_21 ( & V_24 -> V_31 ) ;
V_24 -> V_43 [ V_92 -> V_111 ] = V_4 ;
V_21 = F_15 ( V_24 -> V_43 ) ;
F_55 ( V_63 , & V_24 -> V_31 , V_21 ) ;
}
F_20 ( & V_30 ) ;
V_158 = F_314 ( V_92 , V_128 ) ;
if ( V_158 )
goto V_444;
F_14 ( & V_19 ) ;
return 0 ;
V_444:
F_14 ( & V_19 ) ;
F_329 ( V_92 ) ;
return V_158 ;
}
void F_329 ( struct V_91 * V_92 )
{
struct V_26 * V_27 ;
F_35 ( V_92 -> V_132 == NULL ) ;
F_35 ( V_92 -> V_50 != & V_126 ) ;
F_13 ( & V_19 ) ;
F_315 ( V_92 , V_128 ) ;
if ( V_92 -> V_431 )
F_330 ( & V_92 -> V_445 ) ;
V_43 [ V_92 -> V_111 ] = NULL ;
F_87 ( & V_92 -> V_129 ) ;
F_18 ( & V_30 ) ;
F_54 (link, &dummytop->css_sets, cgrp_link_list) {
struct V_23 * V_24 = V_27 -> V_24 ;
unsigned long V_21 ;
F_21 ( & V_24 -> V_31 ) ;
V_24 -> V_43 [ V_92 -> V_111 ] = NULL ;
V_21 = F_15 ( V_24 -> V_43 ) ;
F_55 ( V_63 , & V_24 -> V_31 , V_21 ) ;
}
F_20 ( & V_30 ) ;
V_92 -> V_93 ( V_128 ) ;
V_128 -> V_43 [ V_92 -> V_111 ] = NULL ;
F_14 ( & V_19 ) ;
}
int T_12 F_331 ( void )
{
int V_20 ;
F_52 ( & V_67 . V_29 , 1 ) ;
F_41 ( & V_67 . V_44 ) ;
F_41 ( & V_67 . V_61 ) ;
F_53 ( & V_67 . V_31 ) ;
V_32 = 1 ;
F_117 ( & V_126 ) ;
V_60 = 1 ;
V_442 . V_66 = & V_67 ;
V_446 . V_24 = & V_67 ;
V_446 . V_7 = V_128 ;
F_43 ( & V_446 . V_34 ,
& V_126 . V_68 . V_58 ) ;
F_43 ( & V_446 . V_33 ,
& V_67 . V_44 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_91 * V_92 = V_43 [ V_20 ] ;
if ( ! V_92 || V_92 -> V_132 )
continue;
F_35 ( ! V_92 -> V_85 ) ;
F_35 ( strlen ( V_92 -> V_85 ) > V_318 ) ;
F_35 ( ! V_92 -> V_429 ) ;
F_35 ( ! V_92 -> V_93 ) ;
if ( V_92 -> V_111 != V_20 ) {
F_325 ( V_447 L_36 ,
V_92 -> V_85 , V_92 -> V_111 ) ;
F_332 () ;
}
if ( V_92 -> V_448 )
F_324 ( V_92 ) ;
}
return 0 ;
}
int T_12 F_333 ( void )
{
int V_293 ;
int V_20 ;
unsigned long V_21 ;
V_293 = F_334 ( & V_83 ) ;
if ( V_293 )
return V_293 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_91 * V_92 = V_43 [ V_20 ] ;
if ( ! V_92 || V_92 -> V_132 )
continue;
if ( ! V_92 -> V_448 )
F_324 ( V_92 ) ;
if ( V_92 -> V_431 )
F_327 ( V_92 , V_67 . V_43 [ V_92 -> V_111 ] ) ;
}
V_21 = F_15 ( V_67 . V_43 ) ;
F_55 ( V_63 , & V_67 . V_31 , V_21 ) ;
F_35 ( ! F_118 ( & V_126 ) ) ;
V_449 = F_335 ( L_37 , V_450 ) ;
if ( ! V_449 ) {
V_293 = - V_56 ;
goto V_215;
}
V_293 = F_336 ( & V_451 ) ;
if ( V_293 < 0 ) {
F_337 ( V_449 ) ;
goto V_215;
}
F_338 ( L_38 , 0 , NULL , & V_452 ) ;
V_215:
if ( V_293 )
F_339 ( & V_83 ) ;
return V_293 ;
}
int F_340 ( struct V_133 * V_286 , void * V_5 )
{
struct V_240 * V_240 ;
struct V_64 * V_226 ;
char * V_211 ;
int V_231 ;
struct V_52 * V_50 ;
V_231 = - V_56 ;
V_211 = F_42 ( V_352 , V_55 ) ;
if ( ! V_211 )
goto V_215;
V_231 = - V_244 ;
V_240 = V_286 -> V_277 ;
V_226 = F_341 ( V_240 , V_453 ) ;
if ( ! V_226 )
goto V_454;
V_231 = 0 ;
F_13 ( & V_19 ) ;
F_139 (root) {
struct V_91 * V_92 ;
struct V_6 * V_7 ;
int V_35 = 0 ;
F_99 ( V_286 , L_39 , V_50 -> V_174 ) ;
F_66 (root, ss)
F_99 ( V_286 , L_40 , V_35 ++ ? L_9 : L_41 , V_92 -> V_85 ) ;
if ( strlen ( V_50 -> V_85 ) )
F_99 ( V_286 , L_42 , V_35 ? L_9 : L_41 ,
V_50 -> V_85 ) ;
F_179 ( V_286 , ':' ) ;
V_7 = F_56 ( V_226 , V_50 ) ;
V_231 = F_146 ( V_7 , V_211 , V_352 ) ;
if ( V_231 < 0 )
goto V_159;
F_100 ( V_286 , V_211 ) ;
F_179 ( V_286 , '\n' ) ;
}
V_159:
F_14 ( & V_19 ) ;
F_172 ( V_226 ) ;
V_454:
F_28 ( V_211 ) ;
V_215:
return V_231 ;
}
static int F_342 ( struct V_133 * V_286 , void * V_5 )
{
int V_20 ;
F_100 ( V_286 , L_43 ) ;
F_13 ( & V_19 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_91 * V_92 = V_43 [ V_20 ] ;
if ( V_92 == NULL )
continue;
F_99 ( V_286 , L_44 ,
V_92 -> V_85 , V_92 -> V_50 -> V_174 ,
V_92 -> V_50 -> V_94 , ! V_92 -> V_156 ) ;
}
F_14 ( & V_19 ) ;
return 0 ;
}
static int F_343 ( struct V_69 * V_69 , struct V_258 * V_258 )
{
return F_199 ( V_258 , F_342 , NULL ) ;
}
void F_344 ( struct V_64 * V_455 )
{
F_155 ( V_160 ) ;
V_455 -> V_66 = V_160 -> V_66 ;
F_30 ( V_455 -> V_66 ) ;
F_157 ( V_160 ) ;
F_41 ( & V_455 -> V_229 ) ;
}
void F_345 ( struct V_64 * V_455 )
{
int V_20 ;
if ( V_332 ) {
F_18 ( & V_30 ) ;
F_155 ( V_455 ) ;
if ( F_45 ( & V_455 -> V_229 ) )
F_43 ( & V_455 -> V_229 , & V_455 -> V_66 -> V_61 ) ;
F_157 ( V_455 ) ;
F_20 ( & V_30 ) ;
}
if ( V_440 ) {
for ( V_20 = 0 ; V_20 < V_456 ; V_20 ++ ) {
struct V_91 * V_92 = V_43 [ V_20 ] ;
if ( V_92 -> V_441 )
V_92 -> V_441 ( V_455 ) ;
}
}
}
void F_346 ( struct V_64 * V_226 , int V_457 )
{
struct V_23 * V_24 ;
int V_20 ;
if ( ! F_45 ( & V_226 -> V_229 ) ) {
F_18 ( & V_30 ) ;
if ( ! F_45 ( & V_226 -> V_229 ) )
F_87 ( & V_226 -> V_229 ) ;
F_20 ( & V_30 ) ;
}
F_155 ( V_226 ) ;
V_24 = V_226 -> V_66 ;
V_226 -> V_66 = & V_67 ;
if ( V_457 && V_440 ) {
for ( V_20 = 0 ; V_20 < V_456 ; V_20 ++ ) {
struct V_91 * V_92 = V_43 [ V_20 ] ;
if ( V_92 -> exit ) {
struct V_6 * V_458 =
F_71 ( V_24 -> V_43 [ V_20 ] ) -> V_6 ;
struct V_6 * V_7 = F_347 ( V_226 , V_20 ) ;
V_92 -> exit ( V_7 , V_458 , V_226 ) ;
}
}
}
F_157 ( V_226 ) ;
F_33 ( V_24 ) ;
}
static void F_26 ( struct V_6 * V_7 )
{
if ( F_7 ( V_7 ) &&
! F_3 ( & V_7 -> V_35 ) && F_45 ( & V_7 -> V_162 ) ) {
int V_459 = 0 ;
F_348 ( & V_460 ) ;
if ( ! F_4 ( V_7 ) &&
F_45 ( & V_7 -> V_164 ) ) {
F_43 ( & V_7 -> V_164 , & V_164 ) ;
V_459 = 1 ;
}
F_349 ( & V_460 ) ;
if ( V_459 )
F_73 ( & V_461 ) ;
}
}
bool F_350 ( struct V_3 * V_4 )
{
while ( true ) {
int V_462 , V_5 ;
V_5 = F_2 ( V_4 ) ;
V_462 = F_351 ( & V_4 -> V_1 , V_5 , V_5 + 1 ) ;
if ( F_352 ( V_462 == V_5 ) )
return true ;
else if ( V_462 < 0 )
return false ;
F_353 () ;
}
}
void F_354 ( struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_1 ( F_355 ( & V_4 -> V_1 ) ) ;
if ( V_5 == 0 )
F_73 ( & V_4 -> V_421 ) ;
}
static void F_356 ( struct V_88 * V_89 )
{
F_35 ( V_89 != & V_461 ) ;
F_13 ( & V_19 ) ;
F_348 ( & V_460 ) ;
while ( ! F_45 ( & V_164 ) ) {
char * V_463 [ 3 ] , * V_464 [ 3 ] ;
int V_20 ;
char * V_465 = NULL , * V_466 = NULL ;
struct V_6 * V_7 = F_36 ( V_164 . V_49 ,
struct V_6 ,
V_164 ) ;
F_87 ( & V_7 -> V_164 ) ;
F_349 ( & V_460 ) ;
V_465 = F_42 ( V_352 , V_55 ) ;
if ( ! V_465 )
goto V_467;
if ( F_146 ( V_7 , V_465 , V_352 ) < 0 )
goto V_467;
V_466 = F_357 ( V_7 -> V_50 -> V_138 , V_55 ) ;
if ( ! V_466 )
goto V_467;
V_20 = 0 ;
V_463 [ V_20 ++ ] = V_466 ;
V_463 [ V_20 ++ ] = V_465 ;
V_463 [ V_20 ] = NULL ;
V_20 = 0 ;
V_464 [ V_20 ++ ] = L_45 ;
V_464 [ V_20 ++ ] = L_46 ;
V_464 [ V_20 ] = NULL ;
F_14 ( & V_19 ) ;
F_358 ( V_463 [ 0 ] , V_463 , V_464 , V_468 ) ;
F_13 ( & V_19 ) ;
V_467:
F_28 ( V_465 ) ;
F_28 ( V_466 ) ;
F_348 ( & V_460 ) ;
}
F_349 ( & V_460 ) ;
F_14 ( & V_19 ) ;
}
static int T_12 F_359 ( char * V_469 )
{
int V_20 ;
char * V_143 ;
while ( ( V_143 = F_103 ( & V_469 , L_9 ) ) != NULL ) {
if ( ! * V_143 )
continue;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_91 * V_92 = V_43 [ V_20 ] ;
if ( ! V_92 || V_92 -> V_132 )
continue;
if ( ! strcmp ( V_143 , V_92 -> V_85 ) ) {
V_92 -> V_156 = 1 ;
F_325 ( V_439 L_47
L_48 , V_92 -> V_85 ) ;
break;
}
}
}
return 1 ;
}
unsigned short F_360 ( struct V_3 * V_4 )
{
struct F_360 * V_470 ;
V_470 = F_361 ( V_4 -> V_96 , F_2 ( V_4 ) ) ;
if ( V_470 )
return V_470 -> V_96 ;
return 0 ;
}
unsigned short F_362 ( struct V_3 * V_4 )
{
struct F_360 * V_470 ;
V_470 = F_361 ( V_4 -> V_96 , F_2 ( V_4 ) ) ;
if ( V_470 )
return V_470 -> V_471 ;
return 0 ;
}
bool F_363 ( struct V_3 * V_455 ,
const struct V_3 * V_50 )
{
struct F_360 * V_472 ;
struct F_360 * V_473 ;
V_472 = F_364 ( V_455 -> V_96 ) ;
if ( ! V_472 )
return false ;
V_473 = F_364 ( V_50 -> V_96 ) ;
if ( ! V_473 )
return false ;
if ( V_472 -> V_471 < V_473 -> V_471 )
return false ;
if ( V_472 -> V_474 [ V_473 -> V_471 ] != V_473 -> V_96 )
return false ;
return true ;
}
void F_365 ( struct V_91 * V_92 , struct V_3 * V_4 )
{
struct F_360 * V_96 = V_4 -> V_96 ;
if ( ! V_96 )
return;
F_35 ( ! V_92 -> V_431 ) ;
F_156 ( V_96 -> V_4 , NULL ) ;
F_156 ( V_4 -> V_96 , NULL ) ;
F_91 ( & V_92 -> V_475 ) ;
F_366 ( & V_92 -> V_445 , V_96 -> V_96 ) ;
F_93 ( & V_92 -> V_475 ) ;
F_29 ( V_96 , V_36 ) ;
}
static struct F_360 * F_367 ( struct V_91 * V_92 , int V_471 )
{
struct F_360 * V_476 ;
int V_158 , V_312 ;
F_35 ( ! V_92 -> V_431 ) ;
V_312 = sizeof( * V_476 ) + sizeof( unsigned short ) * ( V_471 + 1 ) ;
V_476 = F_124 ( V_312 , V_55 ) ;
if ( ! V_476 )
return F_125 ( - V_56 ) ;
F_368 ( V_55 ) ;
F_91 ( & V_92 -> V_475 ) ;
V_158 = F_369 ( & V_92 -> V_445 , V_476 , 1 , V_477 + 1 , V_478 ) ;
F_93 ( & V_92 -> V_475 ) ;
F_370 () ;
if ( V_158 < 0 )
goto V_479;
V_476 -> V_96 = V_158 ;
V_476 -> V_471 = V_471 ;
return V_476 ;
V_479:
F_28 ( V_476 ) ;
return F_125 ( V_158 ) ;
}
static int T_11 F_327 ( struct V_91 * V_92 ,
struct V_3 * V_480 )
{
struct F_360 * V_476 ;
F_115 ( & V_92 -> V_475 ) ;
F_371 ( & V_92 -> V_445 ) ;
V_476 = F_367 ( V_92 , 0 ) ;
if ( F_136 ( V_476 ) )
return F_137 ( V_476 ) ;
V_476 -> V_474 [ 0 ] = V_476 -> V_96 ;
V_476 -> V_4 = V_480 ;
V_480 -> V_96 = V_476 ;
return 0 ;
}
static int F_318 ( struct V_91 * V_92 , struct V_6 * V_11 ,
struct V_6 * V_455 )
{
int V_111 , V_20 , V_471 = 0 ;
struct V_3 * V_481 , * V_482 ;
struct F_360 * V_472 , * V_483 ;
V_111 = V_92 -> V_111 ;
V_481 = V_11 -> V_43 [ V_111 ] ;
V_482 = V_455 -> V_43 [ V_111 ] ;
V_483 = V_481 -> V_96 ;
V_471 = V_483 -> V_471 + 1 ;
V_472 = F_367 ( V_92 , V_471 ) ;
if ( F_136 ( V_472 ) )
return F_137 ( V_472 ) ;
for ( V_20 = 0 ; V_20 < V_471 ; V_20 ++ )
V_472 -> V_474 [ V_20 ] = V_483 -> V_474 [ V_20 ] ;
V_472 -> V_474 [ V_471 ] = V_472 -> V_96 ;
F_156 ( V_482 -> V_96 , V_472 ) ;
return 0 ;
}
struct V_3 * F_372 ( struct V_91 * V_92 , int V_96 )
{
struct F_360 * V_470 = NULL ;
F_35 ( ! V_92 -> V_431 ) ;
V_470 = F_373 ( & V_92 -> V_445 , V_96 ) ;
if ( F_269 ( ! V_470 ) )
return NULL ;
return F_364 ( V_470 -> V_4 ) ;
}
struct V_3 * F_374 ( struct V_258 * V_484 , int V_96 )
{
struct V_6 * V_7 ;
struct V_69 * V_69 ;
struct V_3 * V_4 ;
V_69 = F_217 ( V_484 ) ;
if ( V_69 -> V_195 != & V_196 )
return F_125 ( - V_417 ) ;
if ( V_96 < 0 || V_96 >= V_22 )
return F_125 ( - V_150 ) ;
V_7 = F_9 ( V_484 -> V_274 ) ;
V_4 = V_7 -> V_43 [ V_96 ] ;
return V_4 ? V_4 : F_125 ( - V_157 ) ;
}
static struct V_3 * F_375 ( struct V_6 * V_485 )
{
struct V_3 * V_4 = F_124 ( sizeof( * V_4 ) , V_55 ) ;
if ( ! V_4 )
return F_125 ( - V_56 ) ;
return V_4 ;
}
static void F_376 ( struct V_6 * V_485 )
{
F_28 ( V_485 -> V_43 [ V_486 ] ) ;
}
static T_2 F_377 ( struct V_6 * V_485 , struct V_18 * V_105 )
{
return F_3 ( & V_485 -> V_35 ) ;
}
static T_2 F_378 ( struct V_6 * V_485 , struct V_18 * V_105 )
{
return F_230 ( V_485 ) ;
}
static T_2 F_379 ( struct V_6 * V_485 , struct V_18 * V_105 )
{
return ( T_2 ) ( unsigned long ) V_160 -> V_66 ;
}
static T_2 F_380 ( struct V_6 * V_485 ,
struct V_18 * V_105 )
{
T_2 V_35 ;
F_24 () ;
V_35 = F_3 ( & V_160 -> V_66 -> V_29 ) ;
F_27 () ;
return V_35 ;
}
static int F_381 ( struct V_6 * V_485 ,
struct V_18 * V_105 ,
struct V_133 * V_134 )
{
struct V_26 * V_27 ;
struct V_23 * V_24 ;
F_50 ( & V_30 ) ;
F_24 () ;
V_24 = F_364 ( V_160 -> V_66 ) ;
F_54 (link, &cg->cg_links, cg_link_list) {
struct V_6 * V_62 = V_27 -> V_7 ;
const char * V_85 ;
if ( V_62 -> V_15 )
V_85 = V_62 -> V_15 -> V_86 . V_85 ;
else
V_85 = L_49 ;
F_99 ( V_134 , L_50 ,
V_62 -> V_50 -> V_174 , V_85 ) ;
}
F_27 () ;
F_51 ( & V_30 ) ;
return 0 ;
}
static int F_382 ( struct V_6 * V_485 ,
struct V_18 * V_105 ,
struct V_133 * V_134 )
{
struct V_26 * V_27 ;
F_50 ( & V_30 ) ;
F_54 (link, &cont->css_sets, cgrp_link_list) {
struct V_23 * V_24 = V_27 -> V_24 ;
struct V_64 * V_65 ;
int V_35 = 0 ;
F_99 ( V_134 , L_51 , V_24 ) ;
F_54 (task, &cg->tasks, cg_list) {
if ( V_35 ++ > V_487 ) {
F_100 ( V_134 , L_52 ) ;
break;
} else {
F_99 ( V_134 , L_53 ,
F_271 ( V_65 ) ) ;
}
}
}
F_51 ( & V_30 ) ;
return 0 ;
}
static T_2 F_383 ( struct V_6 * V_7 , struct V_18 * V_105 )
{
return F_5 ( V_13 , & V_7 -> V_9 ) ;
}
