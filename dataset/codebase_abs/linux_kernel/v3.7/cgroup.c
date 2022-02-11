int F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
int F_1 ( void )
{
return F_3 ( & V_1 ) ;
}
static int F_4 ( int V_2 )
{
return V_2 >= 0 ? V_2 : V_2 - V_3 ;
}
static int F_5 ( struct V_4 * V_5 )
{
int V_6 = F_6 ( & V_5 -> V_2 ) ;
return F_4 ( V_6 ) ;
}
inline int F_7 ( const struct V_7 * V_8 )
{
return F_8 ( V_9 , & V_8 -> V_10 ) ;
}
static int F_9 ( const struct V_7 * V_8 )
{
const int V_11 =
( 1 << V_12 ) |
( 1 << V_13 ) ;
return ( V_8 -> V_10 & V_11 ) == V_11 ;
}
static int F_10 ( const struct V_7 * V_8 )
{
return F_8 ( V_13 , & V_8 -> V_10 ) ;
}
static int F_11 ( const struct V_7 * V_8 )
{
return F_8 ( V_14 , & V_8 -> V_10 ) ;
}
static inline struct V_7 * F_12 ( struct V_15 * V_15 )
{
return V_15 -> V_16 ;
}
static inline struct V_17 * F_13 ( struct V_15 * V_15 )
{
return V_15 -> V_16 ;
}
static inline struct V_18 * F_14 ( struct V_15 * V_15 )
{
return F_13 ( V_15 ) -> type ;
}
static struct V_19 * F_15 ( struct V_4 * V_5 [] )
{
int V_20 ;
int V_21 ;
unsigned long V_22 = 0UL ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ )
V_22 += ( unsigned long ) V_5 [ V_20 ] ;
V_22 = ( V_22 >> 16 ) ^ V_22 ;
V_21 = F_16 ( V_22 , V_24 ) ;
return & V_25 [ V_21 ] ;
}
static void F_17 ( struct V_26 * V_27 , int V_28 )
{
struct V_29 * V_30 ;
struct V_29 * V_31 ;
if ( F_18 ( & V_27 -> V_32 , - 1 , 1 ) )
return;
F_19 ( & V_33 ) ;
if ( ! F_20 ( & V_27 -> V_32 ) ) {
F_21 ( & V_33 ) ;
return;
}
F_22 ( & V_27 -> V_34 ) ;
V_35 -- ;
F_23 (link, saved_link, &cg->cg_links,
cg_link_list) {
struct V_7 * V_8 = V_30 -> V_8 ;
F_24 ( & V_30 -> V_36 ) ;
F_24 ( & V_30 -> V_37 ) ;
if ( F_20 ( & V_8 -> V_38 ) &&
F_10 ( V_8 ) ) {
if ( V_28 )
F_25 ( V_12 , & V_8 -> V_10 ) ;
F_26 ( V_8 ) ;
}
F_27 ( V_30 ) ;
}
F_21 ( & V_33 ) ;
F_28 ( V_27 , V_39 ) ;
}
static inline void F_29 ( struct V_26 * V_27 )
{
F_30 ( & V_27 -> V_32 ) ;
}
static inline void F_31 ( struct V_26 * V_27 )
{
F_17 ( V_27 , 0 ) ;
}
static inline void F_32 ( struct V_26 * V_27 )
{
F_17 ( V_27 , 1 ) ;
}
static bool F_33 ( struct V_26 * V_27 ,
struct V_26 * V_40 ,
struct V_7 * V_41 ,
struct V_4 * V_42 [] )
{
struct V_43 * V_44 , * V_45 ;
if ( memcmp ( V_42 , V_27 -> V_46 , sizeof( V_27 -> V_46 ) ) ) {
return false ;
}
V_44 = & V_27 -> V_47 ;
V_45 = & V_40 -> V_47 ;
while ( 1 ) {
struct V_29 * V_48 , * V_49 ;
struct V_7 * V_50 , * V_51 ;
V_44 = V_44 -> V_52 ;
V_45 = V_45 -> V_52 ;
if ( V_44 == & V_27 -> V_47 ) {
F_34 ( V_45 != & V_40 -> V_47 ) ;
break;
} else {
F_34 ( V_45 == & V_40 -> V_47 ) ;
}
V_48 = F_35 ( V_44 , struct V_29 , V_36 ) ;
V_49 = F_35 ( V_45 , struct V_29 , V_36 ) ;
V_50 = V_48 -> V_8 ;
V_51 = V_49 -> V_8 ;
F_34 ( V_50 -> V_53 != V_51 -> V_53 ) ;
if ( V_50 -> V_53 == V_41 -> V_53 ) {
if ( V_50 != V_41 )
return false ;
} else {
if ( V_50 != V_51 )
return false ;
}
}
return true ;
}
static struct V_26 * F_36 (
struct V_26 * V_54 ,
struct V_7 * V_8 ,
struct V_4 * V_42 [] )
{
int V_20 ;
struct V_55 * V_53 = V_8 -> V_53 ;
struct V_19 * V_56 ;
struct V_57 * V_58 ;
struct V_26 * V_27 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
if ( V_53 -> V_59 & ( 1UL << V_20 ) ) {
V_42 [ V_20 ] = V_8 -> V_46 [ V_20 ] ;
} else {
V_42 [ V_20 ] = V_54 -> V_46 [ V_20 ] ;
}
}
V_56 = F_15 ( V_42 ) ;
F_37 (cg, node, hhead, hlist) {
if ( ! F_33 ( V_27 , V_54 , V_8 , V_42 ) )
continue;
return V_27 ;
}
return NULL ;
}
static void F_38 ( struct V_43 * V_22 )
{
struct V_29 * V_30 ;
struct V_29 * V_31 ;
F_23 (link, saved_link, tmp, cgrp_link_list) {
F_24 ( & V_30 -> V_37 ) ;
F_27 ( V_30 ) ;
}
}
static int F_39 ( int V_38 , struct V_43 * V_22 )
{
struct V_29 * V_30 ;
int V_20 ;
F_40 ( V_22 ) ;
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
V_30 = F_41 ( sizeof( * V_30 ) , V_60 ) ;
if ( ! V_30 ) {
F_38 ( V_22 ) ;
return - V_61 ;
}
F_42 ( & V_30 -> V_37 , V_22 ) ;
}
return 0 ;
}
static void F_43 ( struct V_43 * V_62 ,
struct V_26 * V_27 , struct V_7 * V_8 )
{
struct V_29 * V_30 ;
F_34 ( F_44 ( V_62 ) ) ;
V_30 = F_45 ( V_62 , struct V_29 ,
V_37 ) ;
V_30 -> V_27 = V_27 ;
V_30 -> V_8 = V_8 ;
F_30 ( & V_8 -> V_38 ) ;
F_46 ( & V_30 -> V_37 , & V_8 -> V_63 ) ;
F_47 ( & V_30 -> V_36 , & V_27 -> V_47 ) ;
}
static struct V_26 * F_48 (
struct V_26 * V_54 , struct V_7 * V_8 )
{
struct V_26 * V_64 ;
struct V_4 * V_42 [ V_23 ] ;
struct V_43 V_62 ;
struct V_19 * V_56 ;
struct V_29 * V_30 ;
F_49 ( & V_33 ) ;
V_64 = F_36 ( V_54 , V_8 , V_42 ) ;
if ( V_64 )
F_29 ( V_64 ) ;
F_50 ( & V_33 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_41 ( sizeof( * V_64 ) , V_60 ) ;
if ( ! V_64 )
return NULL ;
if ( F_39 ( V_65 , & V_62 ) < 0 ) {
F_27 ( V_64 ) ;
return NULL ;
}
F_51 ( & V_64 -> V_32 , 1 ) ;
F_40 ( & V_64 -> V_47 ) ;
F_40 ( & V_64 -> V_66 ) ;
F_52 ( & V_64 -> V_34 ) ;
memcpy ( V_64 -> V_46 , V_42 , sizeof( V_64 -> V_46 ) ) ;
F_19 ( & V_33 ) ;
F_53 (link, &oldcg->cg_links, cg_link_list) {
struct V_7 * V_67 = V_30 -> V_8 ;
if ( V_67 -> V_53 == V_8 -> V_53 )
V_67 = V_8 ;
F_43 ( & V_62 , V_64 , V_67 ) ;
}
F_34 ( ! F_44 ( & V_62 ) ) ;
V_35 ++ ;
V_56 = F_15 ( V_64 -> V_46 ) ;
F_54 ( & V_64 -> V_34 , V_56 ) ;
F_21 ( & V_33 ) ;
return V_64 ;
}
static struct V_7 * F_55 ( struct V_68 * V_69 ,
struct V_55 * V_53 )
{
struct V_26 * V_5 ;
struct V_7 * V_64 = NULL ;
F_34 ( ! F_3 ( & V_1 ) ) ;
F_49 ( & V_33 ) ;
V_5 = V_69 -> V_70 ;
if ( V_5 == & V_71 ) {
V_64 = & V_53 -> V_72 ;
} else {
struct V_29 * V_30 ;
F_53 (link, &css->cg_links, cg_link_list) {
struct V_7 * V_67 = V_30 -> V_8 ;
if ( V_67 -> V_53 == V_53 ) {
V_64 = V_67 ;
break;
}
}
}
F_50 ( & V_33 ) ;
F_34 ( ! V_64 ) ;
return V_64 ;
}
void F_56 ( void )
{
F_57 ( & V_1 ) ;
}
void F_58 ( void )
{
F_59 ( & V_1 ) ;
}
static struct V_73 * F_60 ( T_1 V_74 , struct V_75 * V_76 )
{
struct V_73 * V_73 = F_61 ( V_76 ) ;
if ( V_73 ) {
V_73 -> V_77 = F_62 () ;
V_73 -> V_78 = V_74 ;
V_73 -> V_79 = F_63 () ;
V_73 -> V_80 = F_64 () ;
V_73 -> V_81 = V_73 -> V_82 = V_73 -> V_83 = V_84 ;
V_73 -> V_85 -> V_86 = & V_87 ;
}
return V_73 ;
}
static int F_65 ( struct V_7 * V_8 )
{
struct V_88 * V_89 ;
int V_90 = 0 ;
F_66 (cgrp->root, ss) {
if ( ! V_89 -> V_91 )
continue;
V_90 = V_89 -> V_91 ( V_8 ) ;
if ( V_90 ) {
F_67 ( ! V_89 -> V_92 ) ;
break;
}
}
return V_90 ;
}
static void F_68 ( struct V_15 * V_15 , struct V_73 * V_73 )
{
if ( F_69 ( V_73 -> V_78 ) ) {
struct V_7 * V_8 = V_15 -> V_16 ;
struct V_88 * V_89 ;
F_34 ( ! ( F_7 ( V_8 ) ) ) ;
F_70 () ;
F_57 ( & V_1 ) ;
F_66 (cgrp->root, ss)
V_89 -> V_93 ( V_8 ) ;
V_8 -> V_53 -> V_94 -- ;
F_59 ( & V_1 ) ;
F_71 ( V_8 -> V_53 -> V_76 ) ;
F_34 ( ! F_44 ( & V_8 -> V_95 ) ) ;
F_72 ( & V_8 -> V_96 ) ;
F_28 ( V_8 , V_39 ) ;
} else {
struct V_17 * V_97 = F_13 ( V_15 ) ;
struct V_7 * V_8 = V_15 -> V_98 -> V_16 ;
struct V_18 * V_99 = V_97 -> type ;
F_73 ( ! F_44 ( & V_97 -> V_58 ) &&
V_8 != & V_8 -> V_53 -> V_72 ,
L_1 , V_97 -> type -> V_100 ) ;
F_27 ( V_97 ) ;
F_72 ( & V_99 -> V_96 ) ;
}
F_74 ( V_73 ) ;
}
static int F_75 ( const struct V_15 * V_101 )
{
return 1 ;
}
static void F_76 ( struct V_15 * V_101 )
{
struct V_15 * V_102 = F_77 ( V_101 -> V_98 ) ;
F_78 ( V_101 ) ;
F_79 ( V_102 -> V_103 , V_101 ) ;
F_80 ( V_102 ) ;
}
static int F_81 ( struct V_7 * V_8 , const struct V_18 * V_99 )
{
struct V_17 * V_97 ;
F_82 ( & V_8 -> V_15 -> V_103 -> V_104 ) ;
F_82 ( & V_1 ) ;
F_53 (cfe, &cgrp->files, node) {
struct V_15 * V_101 = V_97 -> V_15 ;
if ( V_99 && V_97 -> type != V_99 )
continue;
F_77 ( V_101 ) ;
F_78 ( V_101 ) ;
F_83 ( V_8 -> V_15 -> V_103 , V_101 ) ;
F_84 ( & V_97 -> V_58 ) ;
F_80 ( V_101 ) ;
return 0 ;
}
return - V_105 ;
}
static void F_85 ( struct V_15 * V_106 , bool V_107 ,
unsigned long V_59 )
{
struct V_7 * V_8 = F_12 ( V_106 ) ;
struct V_88 * V_89 ;
F_66 (cgrp->root, ss) {
struct V_108 * V_109 ;
if ( ! F_8 ( V_89 -> V_110 , & V_59 ) )
continue;
F_53 (set, &ss->cftsets, node)
F_81 ( V_8 , V_109 -> V_111 ) ;
}
if ( V_107 ) {
while ( ! F_44 ( & V_8 -> V_112 ) )
F_81 ( V_8 , NULL ) ;
}
}
static void F_86 ( struct V_15 * V_15 )
{
struct V_15 * V_102 ;
struct V_55 * V_53 = V_15 -> V_113 -> V_114 ;
F_85 ( V_15 , true , V_53 -> V_59 ) ;
V_102 = V_15 -> V_98 ;
F_87 ( & V_102 -> V_115 ) ;
F_88 ( & V_15 -> V_115 , V_116 ) ;
F_84 ( & V_15 -> V_117 . V_118 ) ;
F_89 ( & V_15 -> V_115 ) ;
F_89 ( & V_102 -> V_115 ) ;
F_76 ( V_15 ) ;
}
static void F_90 ( struct V_7 * V_8 )
{
if ( F_91 ( F_92 ( V_119 , & V_8 -> V_10 ) ) )
F_93 ( & V_120 ) ;
}
void F_94 ( struct V_4 * V_5 )
{
F_95 ( V_5 ) ;
}
void F_96 ( struct V_4 * V_5 )
{
F_90 ( V_5 -> V_7 ) ;
F_97 ( V_5 ) ;
}
static int F_98 ( struct V_55 * V_53 ,
unsigned long V_121 )
{
unsigned long V_122 , V_123 ;
struct V_7 * V_8 = & V_53 -> V_72 ;
int V_20 ;
F_34 ( ! F_3 ( & V_1 ) ) ;
F_34 ( ! F_3 ( & V_124 ) ) ;
V_123 = V_53 -> V_125 & ~ V_121 ;
V_122 = V_121 & ~ V_53 -> V_125 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
unsigned long V_126 = 1UL << V_20 ;
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( ! ( V_126 & V_122 ) )
continue;
F_34 ( V_89 == NULL ) ;
if ( V_89 -> V_53 != & V_127 ) {
return - V_128 ;
}
}
if ( V_53 -> V_94 > 1 )
return - V_128 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
unsigned long V_126 = 1UL << V_20 ;
if ( V_126 & V_122 ) {
F_34 ( V_89 == NULL ) ;
F_34 ( V_8 -> V_46 [ V_20 ] ) ;
F_34 ( ! V_129 -> V_46 [ V_20 ] ) ;
F_34 ( V_129 -> V_46 [ V_20 ] -> V_7 != V_129 ) ;
V_8 -> V_46 [ V_20 ] = V_129 -> V_46 [ V_20 ] ;
V_8 -> V_46 [ V_20 ] -> V_7 = V_8 ;
F_46 ( & V_89 -> V_130 , & V_53 -> V_131 ) ;
V_89 -> V_53 = V_53 ;
if ( V_89 -> V_132 )
V_89 -> V_132 ( V_8 ) ;
} else if ( V_126 & V_123 ) {
F_34 ( V_89 == NULL ) ;
F_34 ( V_8 -> V_46 [ V_20 ] != V_129 -> V_46 [ V_20 ] ) ;
F_34 ( V_8 -> V_46 [ V_20 ] -> V_7 != V_8 ) ;
if ( V_89 -> V_132 )
V_89 -> V_132 ( V_129 ) ;
V_129 -> V_46 [ V_20 ] -> V_7 = V_129 ;
V_8 -> V_46 [ V_20 ] = NULL ;
V_46 [ V_20 ] -> V_53 = & V_127 ;
F_46 ( & V_89 -> V_130 , & V_127 . V_131 ) ;
F_99 ( V_89 -> V_133 ) ;
} else if ( V_126 & V_121 ) {
F_34 ( V_89 == NULL ) ;
F_34 ( ! V_8 -> V_46 [ V_20 ] ) ;
F_99 ( V_89 -> V_133 ) ;
#ifdef F_100
F_34 ( V_89 -> V_133 && ! F_101 ( V_89 -> V_133 ) ) ;
#endif
} else {
F_34 ( V_8 -> V_46 [ V_20 ] ) ;
}
}
V_53 -> V_59 = V_53 -> V_125 = V_121 ;
F_70 () ;
return 0 ;
}
static int F_102 ( struct V_134 * V_135 , struct V_15 * V_15 )
{
struct V_55 * V_53 = V_15 -> V_113 -> V_114 ;
struct V_88 * V_89 ;
F_57 ( & V_124 ) ;
F_66 (root, ss)
F_103 ( V_135 , L_2 , V_89 -> V_100 ) ;
if ( F_8 ( V_136 , & V_53 -> V_10 ) )
F_104 ( V_135 , L_3 ) ;
if ( F_8 ( V_137 , & V_53 -> V_10 ) )
F_104 ( V_135 , L_4 ) ;
if ( strlen ( V_53 -> V_138 ) )
F_103 ( V_135 , L_5 , V_53 -> V_138 ) ;
if ( F_11 ( & V_53 -> V_72 ) )
F_104 ( V_135 , L_6 ) ;
if ( strlen ( V_53 -> V_100 ) )
F_103 ( V_135 , L_7 , V_53 -> V_100 ) ;
F_59 ( & V_124 ) ;
return 0 ;
}
static int F_105 ( char * V_139 , struct V_140 * V_141 )
{
char * V_142 , * V_143 = V_139 ;
bool V_144 = false , V_145 = false ;
unsigned long V_146 = ( unsigned long ) - 1 ;
int V_20 ;
bool V_147 = false ;
F_34 ( ! F_3 ( & V_1 ) ) ;
#ifdef F_106
V_146 = ~ ( 1UL << V_148 ) ;
#endif
memset ( V_141 , 0 , sizeof( * V_141 ) ) ;
while ( ( V_142 = F_107 ( & V_143 , L_8 ) ) != NULL ) {
if ( ! * V_142 )
return - V_149 ;
if ( ! strcmp ( V_142 , L_9 ) ) {
V_141 -> V_150 = true ;
continue;
}
if ( ! strcmp ( V_142 , L_10 ) ) {
if ( V_145 )
return - V_149 ;
V_144 = true ;
continue;
}
if ( ! strcmp ( V_142 , L_11 ) ) {
F_25 ( V_136 , & V_141 -> V_10 ) ;
continue;
}
if ( ! strcmp ( V_142 , L_12 ) ) {
V_141 -> F_11 = true ;
continue;
}
if ( ! strcmp ( V_142 , L_13 ) ) {
F_25 ( V_137 , & V_141 -> V_10 ) ;
continue;
}
if ( ! strncmp ( V_142 , L_14 , 14 ) ) {
if ( V_141 -> V_151 )
return - V_149 ;
V_141 -> V_151 =
F_108 ( V_142 + 14 , V_152 - 1 , V_60 ) ;
if ( ! V_141 -> V_151 )
return - V_61 ;
continue;
}
if ( ! strncmp ( V_142 , L_15 , 5 ) ) {
const char * V_100 = V_142 + 5 ;
if ( ! strlen ( V_100 ) )
return - V_149 ;
for ( V_20 = 0 ; V_20 < strlen ( V_100 ) ; V_20 ++ ) {
char V_67 = V_100 [ V_20 ] ;
if ( isalnum ( V_67 ) )
continue;
if ( ( V_67 == '.' ) || ( V_67 == '-' ) || ( V_67 == '_' ) )
continue;
return - V_149 ;
}
if ( V_141 -> V_100 )
return - V_149 ;
V_141 -> V_100 = F_108 ( V_100 ,
V_153 - 1 ,
V_60 ) ;
if ( ! V_141 -> V_100 )
return - V_61 ;
continue;
}
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 == NULL )
continue;
if ( strcmp ( V_142 , V_89 -> V_100 ) )
continue;
if ( V_89 -> V_154 )
continue;
if ( V_144 )
return - V_149 ;
F_25 ( V_20 , & V_141 -> V_59 ) ;
V_145 = true ;
break;
}
if ( V_20 == V_23 )
return - V_105 ;
}
if ( V_144 || ( ! V_145 && ! V_141 -> V_150 && ! V_141 -> V_100 ) ) {
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 == NULL )
continue;
if ( V_89 -> V_154 )
continue;
F_25 ( V_20 , & V_141 -> V_59 ) ;
}
}
if ( F_8 ( V_136 , & V_141 -> V_10 ) &&
( V_141 -> V_59 & V_146 ) )
return - V_149 ;
if ( V_141 -> V_59 && V_141 -> V_150 )
return - V_149 ;
if ( ! V_141 -> V_59 && ! V_141 -> V_100 )
return - V_149 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
unsigned long V_126 = 1UL << V_20 ;
if ( ! ( V_126 & V_141 -> V_59 ) )
continue;
if ( ! F_109 ( V_46 [ V_20 ] -> V_133 ) ) {
V_147 = true ;
break;
}
}
if ( V_147 ) {
for ( V_20 -- ; V_20 >= 0 ; V_20 -- ) {
unsigned long V_126 = 1UL << V_20 ;
if ( ! ( V_126 & V_141 -> V_59 ) )
continue;
F_99 ( V_46 [ V_20 ] -> V_133 ) ;
}
return - V_105 ;
}
return 0 ;
}
static void F_110 ( unsigned long V_59 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
unsigned long V_126 = 1UL << V_20 ;
if ( ! ( V_126 & V_59 ) )
continue;
F_99 ( V_46 [ V_20 ] -> V_133 ) ;
}
}
static int F_111 ( struct V_75 * V_76 , int * V_10 , char * V_139 )
{
int V_90 = 0 ;
struct V_55 * V_53 = V_76 -> V_114 ;
struct V_7 * V_8 = & V_53 -> V_72 ;
struct V_140 V_141 ;
unsigned long V_122 , V_123 ;
F_57 ( & V_8 -> V_15 -> V_103 -> V_104 ) ;
F_57 ( & V_1 ) ;
F_57 ( & V_124 ) ;
V_90 = F_105 ( V_139 , & V_141 ) ;
if ( V_90 )
goto V_155;
if ( V_141 . V_59 != V_53 -> V_125 || V_141 . V_151 )
F_112 ( L_16 ,
F_113 ( V_156 ) , V_156 -> V_157 ) ;
V_122 = V_141 . V_59 & ~ V_53 -> V_59 ;
V_123 = V_53 -> V_59 & ~ V_141 . V_59 ;
if ( V_141 . V_10 != V_53 -> V_10 ||
( V_141 . V_100 && strcmp ( V_141 . V_100 , V_53 -> V_100 ) ) ) {
V_90 = - V_149 ;
F_110 ( V_141 . V_59 ) ;
goto V_155;
}
V_90 = F_98 ( V_53 , V_141 . V_59 ) ;
if ( V_90 ) {
F_110 ( V_141 . V_59 ) ;
goto V_155;
}
F_85 ( V_8 -> V_15 , false , V_123 ) ;
F_114 ( V_8 , false , V_122 ) ;
if ( V_141 . V_151 )
strcpy ( V_53 -> V_138 , V_141 . V_151 ) ;
V_155:
F_27 ( V_141 . V_151 ) ;
F_27 ( V_141 . V_100 ) ;
F_59 ( & V_124 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_8 -> V_15 -> V_103 -> V_104 ) ;
return V_90 ;
}
static void F_115 ( struct V_7 * V_8 )
{
F_40 ( & V_8 -> V_130 ) ;
F_40 ( & V_8 -> V_158 ) ;
F_40 ( & V_8 -> V_112 ) ;
F_40 ( & V_8 -> V_63 ) ;
F_40 ( & V_8 -> V_159 ) ;
F_40 ( & V_8 -> V_95 ) ;
F_116 ( & V_8 -> V_160 ) ;
F_40 ( & V_8 -> V_161 ) ;
F_117 ( & V_8 -> V_162 ) ;
F_118 ( & V_8 -> V_96 ) ;
}
static void F_119 ( struct V_55 * V_53 )
{
struct V_7 * V_8 = & V_53 -> V_72 ;
F_40 ( & V_53 -> V_131 ) ;
F_40 ( & V_53 -> V_163 ) ;
F_40 ( & V_53 -> V_164 ) ;
V_53 -> V_94 = 1 ;
V_8 -> V_53 = V_53 ;
V_8 -> V_72 = V_8 ;
F_47 ( & V_8 -> V_165 , & V_53 -> V_164 ) ;
F_115 ( V_8 ) ;
}
static bool F_120 ( struct V_55 * V_53 )
{
int V_90 = 0 ;
do {
if ( ! F_121 ( & V_166 , V_60 ) )
return false ;
F_87 ( & V_167 ) ;
V_90 = F_122 ( & V_166 , V_168 ,
& V_53 -> V_169 ) ;
if ( V_90 == - V_170 )
V_90 = F_123 ( & V_166 , & V_53 -> V_169 ) ;
if ( ! V_90 ) {
V_168 = V_53 -> V_169 + 1 ;
} else if ( V_90 != - V_171 ) {
F_34 ( V_90 ) ;
}
F_89 ( & V_167 ) ;
} while ( V_90 );
return true ;
}
static int F_124 ( struct V_75 * V_76 , void * V_139 )
{
struct V_140 * V_141 = V_139 ;
struct V_55 * V_53 = V_76 -> V_114 ;
if ( V_141 -> V_100 && strcmp ( V_141 -> V_100 , V_53 -> V_100 ) )
return 0 ;
if ( ( V_141 -> V_59 || V_141 -> V_150 )
&& ( V_141 -> V_59 != V_53 -> V_59 ) )
return 0 ;
return 1 ;
}
static struct V_55 * F_125 ( struct V_140 * V_141 )
{
struct V_55 * V_53 ;
if ( ! V_141 -> V_59 && ! V_141 -> V_150 )
return NULL ;
V_53 = F_126 ( sizeof( * V_53 ) , V_60 ) ;
if ( ! V_53 )
return F_127 ( - V_61 ) ;
if ( ! F_120 ( V_53 ) ) {
F_27 ( V_53 ) ;
return F_127 ( - V_61 ) ;
}
F_119 ( V_53 ) ;
V_53 -> V_59 = V_141 -> V_59 ;
V_53 -> V_10 = V_141 -> V_10 ;
if ( V_141 -> V_151 )
strcpy ( V_53 -> V_138 , V_141 -> V_151 ) ;
if ( V_141 -> V_100 )
strcpy ( V_53 -> V_100 , V_141 -> V_100 ) ;
if ( V_141 -> F_11 )
F_25 ( V_14 , & V_53 -> V_72 . V_10 ) ;
return V_53 ;
}
static void F_128 ( struct V_55 * V_53 )
{
if ( ! V_53 )
return;
F_34 ( ! V_53 -> V_169 ) ;
F_87 ( & V_167 ) ;
F_129 ( & V_166 , V_53 -> V_169 ) ;
F_89 ( & V_167 ) ;
F_27 ( V_53 ) ;
}
static int F_130 ( struct V_75 * V_76 , void * V_139 )
{
int V_90 ;
struct V_140 * V_141 = V_139 ;
if ( ! V_141 -> V_172 )
return - V_149 ;
F_34 ( ! V_141 -> V_59 && ! V_141 -> V_150 ) ;
V_90 = F_131 ( V_76 , NULL ) ;
if ( V_90 )
return V_90 ;
V_76 -> V_114 = V_141 -> V_172 ;
V_141 -> V_172 -> V_76 = V_76 ;
V_76 -> V_173 = V_174 ;
V_76 -> V_175 = V_176 ;
V_76 -> V_177 = V_178 ;
V_76 -> V_179 = & V_180 ;
return 0 ;
}
static int F_132 ( struct V_75 * V_76 )
{
static const struct V_181 V_182 = {
. V_183 = F_68 ,
. F_78 = F_75 ,
} ;
struct V_73 * V_73 =
F_60 ( V_184 | V_185 | V_186 | V_187 , V_76 ) ;
if ( ! V_73 )
return - V_61 ;
V_73 -> V_188 = & V_189 ;
V_73 -> V_190 = & V_191 ;
F_133 ( V_73 ) ;
V_76 -> V_192 = F_134 ( V_73 ) ;
if ( ! V_76 -> V_192 )
return - V_61 ;
V_76 -> V_193 = & V_182 ;
return 0 ;
}
static struct V_15 * F_135 ( struct V_194 * V_195 ,
int V_10 , const char * V_196 ,
void * V_139 )
{
struct V_140 V_141 ;
struct V_55 * V_53 ;
int V_90 = 0 ;
struct V_75 * V_76 ;
struct V_55 * V_172 ;
struct V_73 * V_73 ;
F_57 ( & V_1 ) ;
V_90 = F_105 ( V_139 , & V_141 ) ;
F_59 ( & V_1 ) ;
if ( V_90 )
goto V_197;
V_172 = F_125 ( & V_141 ) ;
if ( F_136 ( V_172 ) ) {
V_90 = F_137 ( V_172 ) ;
goto V_198;
}
V_141 . V_172 = V_172 ;
V_76 = F_138 ( V_195 , F_124 , F_130 , 0 , & V_141 ) ;
if ( F_136 ( V_76 ) ) {
V_90 = F_137 ( V_76 ) ;
F_128 ( V_141 . V_172 ) ;
goto V_198;
}
V_53 = V_76 -> V_114 ;
F_34 ( ! V_53 ) ;
if ( V_53 == V_141 . V_172 ) {
struct V_43 V_62 ;
struct V_7 * V_199 = & V_53 -> V_72 ;
struct V_55 * V_200 ;
const struct V_201 * V_201 ;
int V_20 ;
F_34 ( V_76 -> V_192 != NULL ) ;
V_90 = F_132 ( V_76 ) ;
if ( V_90 )
goto V_202;
V_73 = V_76 -> V_192 -> V_103 ;
F_57 ( & V_73 -> V_104 ) ;
F_57 ( & V_1 ) ;
F_57 ( & V_124 ) ;
V_90 = - V_128 ;
if ( strlen ( V_53 -> V_100 ) )
F_139 (existing_root)
if ( ! strcmp ( V_200 -> V_100 , V_53 -> V_100 ) )
goto V_203;
V_90 = F_39 ( V_35 , & V_62 ) ;
if ( V_90 )
goto V_203;
V_90 = F_98 ( V_53 , V_53 -> V_59 ) ;
if ( V_90 == - V_128 ) {
F_38 ( & V_62 ) ;
goto V_203;
}
F_34 ( V_90 ) ;
F_42 ( & V_53 -> V_163 , & V_204 ) ;
V_65 ++ ;
V_76 -> V_192 -> V_16 = V_199 ;
V_53 -> V_72 . V_15 = V_76 -> V_192 ;
F_19 ( & V_33 ) ;
for ( V_20 = 0 ; V_20 < V_205 ; V_20 ++ ) {
struct V_19 * V_56 = & V_25 [ V_20 ] ;
struct V_57 * V_58 ;
struct V_26 * V_27 ;
F_37 (cg, node, hhead, hlist)
F_43 ( & V_62 , V_27 , V_199 ) ;
}
F_21 ( & V_33 ) ;
F_38 ( & V_62 ) ;
F_34 ( ! F_44 ( & V_199 -> V_130 ) ) ;
F_34 ( ! F_44 ( & V_199 -> V_158 ) ) ;
F_34 ( V_53 -> V_94 != 1 ) ;
V_201 = F_140 ( & V_206 ) ;
F_114 ( V_199 , true , V_53 -> V_59 ) ;
F_141 ( V_201 ) ;
F_59 ( & V_124 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_73 -> V_104 ) ;
} else {
F_128 ( V_141 . V_172 ) ;
F_110 ( V_141 . V_59 ) ;
}
F_27 ( V_141 . V_151 ) ;
F_27 ( V_141 . V_100 ) ;
return F_77 ( V_76 -> V_192 ) ;
V_203:
F_59 ( & V_124 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_73 -> V_104 ) ;
V_202:
F_142 ( V_76 ) ;
V_198:
F_110 ( V_141 . V_59 ) ;
V_197:
F_27 ( V_141 . V_151 ) ;
F_27 ( V_141 . V_100 ) ;
return F_127 ( V_90 ) ;
}
static void F_143 ( struct V_75 * V_76 ) {
struct V_55 * V_53 = V_76 -> V_114 ;
struct V_7 * V_8 = & V_53 -> V_72 ;
int V_90 ;
struct V_29 * V_30 ;
struct V_29 * V_31 ;
F_34 ( ! V_53 ) ;
F_34 ( V_53 -> V_94 != 1 ) ;
F_34 ( ! F_44 ( & V_8 -> V_158 ) ) ;
F_34 ( ! F_44 ( & V_8 -> V_130 ) ) ;
F_57 ( & V_1 ) ;
F_57 ( & V_124 ) ;
V_90 = F_98 ( V_53 , 0 ) ;
F_34 ( V_90 ) ;
F_19 ( & V_33 ) ;
F_23 (link, saved_link, &cgrp->css_sets,
cgrp_link_list) {
F_24 ( & V_30 -> V_36 ) ;
F_24 ( & V_30 -> V_37 ) ;
F_27 ( V_30 ) ;
}
F_21 ( & V_33 ) ;
if ( ! F_44 ( & V_53 -> V_163 ) ) {
F_24 ( & V_53 -> V_163 ) ;
V_65 -- ;
}
F_59 ( & V_124 ) ;
F_59 ( & V_1 ) ;
F_72 ( & V_8 -> V_96 ) ;
F_144 ( V_76 ) ;
F_128 ( V_53 ) ;
}
int F_145 ( const struct V_7 * V_8 , char * V_207 , int V_208 )
{
char * V_209 ;
struct V_15 * V_15 = F_146 ( V_8 -> V_15 ,
F_1 () ) ;
if ( ! V_15 || V_8 == V_129 ) {
strcpy ( V_207 , L_17 ) ;
return 0 ;
}
V_209 = V_207 + V_208 ;
* -- V_209 = '\0' ;
for (; ; ) {
int V_210 = V_15 -> V_211 . V_210 ;
if ( ( V_209 -= V_210 ) < V_207 )
return - V_212 ;
memcpy ( V_209 , V_15 -> V_211 . V_100 , V_210 ) ;
V_8 = V_8 -> V_102 ;
if ( ! V_8 )
break;
V_15 = F_146 ( V_8 -> V_15 ,
F_1 () ) ;
if ( ! V_8 -> V_102 )
continue;
if ( -- V_209 < V_207 )
return - V_212 ;
* V_209 = '/' ;
}
memmove ( V_207 , V_209 , V_207 + V_208 - V_209 ) ;
return 0 ;
}
struct V_68 * F_147 ( struct V_213 * V_214 )
{
if ( V_214 -> V_215 ) {
V_214 -> V_216 = 0 ;
return F_148 ( V_214 ) ;
} else {
V_214 -> V_217 = V_214 -> V_218 . V_8 ;
return V_214 -> V_218 . V_69 ;
}
}
struct V_68 * F_148 ( struct V_213 * V_214 )
{
struct V_219 * V_220 ;
if ( ! V_214 -> V_215 || V_214 -> V_216 >= V_214 -> V_221 )
return NULL ;
V_220 = F_149 ( V_214 -> V_215 , V_214 -> V_216 ++ ) ;
V_214 -> V_217 = V_220 -> V_8 ;
return V_220 -> V_69 ;
}
struct V_7 * F_150 ( struct V_213 * V_214 )
{
return V_214 -> V_217 ;
}
int F_151 ( struct V_213 * V_214 )
{
return V_214 -> V_215 ? V_214 -> V_221 : 1 ;
}
static void F_152 ( struct V_7 * V_8 , struct V_7 * V_222 ,
struct V_68 * V_223 , struct V_26 * V_224 )
{
struct V_26 * V_54 ;
F_67 ( V_223 -> V_10 & V_225 ) ;
V_54 = V_223 -> V_70 ;
F_153 ( V_223 ) ;
F_154 ( V_223 -> V_70 , V_224 ) ;
F_155 ( V_223 ) ;
F_19 ( & V_33 ) ;
if ( ! F_44 ( & V_223 -> V_226 ) )
F_46 ( & V_223 -> V_226 , & V_224 -> V_66 ) ;
F_21 ( & V_33 ) ;
F_25 ( V_12 , & V_222 -> V_10 ) ;
F_31 ( V_54 ) ;
}
int F_156 ( struct V_7 * V_8 , struct V_68 * V_223 )
{
int V_227 = 0 ;
struct V_88 * V_89 , * V_228 = NULL ;
struct V_7 * V_222 ;
struct V_55 * V_53 = V_8 -> V_53 ;
struct V_213 V_214 = { } ;
struct V_26 * V_224 ;
if ( V_223 -> V_10 & V_225 )
return - V_229 ;
V_222 = F_55 ( V_223 , V_53 ) ;
if ( V_8 == V_222 )
return 0 ;
V_214 . V_218 . V_69 = V_223 ;
V_214 . V_218 . V_8 = V_222 ;
F_66 (root, ss) {
if ( V_89 -> V_230 ) {
V_227 = V_89 -> V_230 ( V_8 , & V_214 ) ;
if ( V_227 ) {
V_228 = V_89 ;
goto V_231;
}
}
}
V_224 = F_48 ( V_223 -> V_70 , V_8 ) ;
if ( ! V_224 ) {
V_227 = - V_61 ;
goto V_231;
}
F_152 ( V_8 , V_222 , V_223 , V_224 ) ;
F_66 (root, ss) {
if ( V_89 -> V_232 )
V_89 -> V_232 ( V_8 , & V_214 ) ;
}
F_70 () ;
F_90 ( V_8 ) ;
V_231:
if ( V_227 ) {
F_66 (root, ss) {
if ( V_89 == V_228 )
break;
if ( V_89 -> V_233 )
V_89 -> V_233 ( V_8 , & V_214 ) ;
}
}
return V_227 ;
}
int F_157 ( struct V_68 * V_234 , struct V_68 * V_223 )
{
struct V_55 * V_53 ;
int V_227 = 0 ;
F_56 () ;
F_139 (root) {
struct V_7 * V_235 = F_55 ( V_234 , V_53 ) ;
V_227 = F_156 ( V_235 , V_223 ) ;
if ( V_227 )
break;
}
F_58 () ;
return V_227 ;
}
static int F_158 ( struct V_7 * V_8 , struct V_68 * V_236 )
{
int V_227 , V_20 , V_237 ;
struct V_88 * V_89 , * V_228 = NULL ;
struct V_55 * V_53 = V_8 -> V_53 ;
struct V_68 * V_223 ;
struct V_219 * V_220 ;
struct V_238 * V_239 ;
struct V_213 V_214 = { } ;
V_237 = F_159 ( V_236 ) ;
V_239 = F_160 ( sizeof( * V_220 ) , V_237 , V_60 ) ;
if ( ! V_239 )
return - V_61 ;
V_227 = F_161 ( V_239 , 0 , V_237 - 1 , V_60 ) ;
if ( V_227 )
goto V_240;
V_223 = V_236 ;
V_20 = 0 ;
F_162 () ;
do {
struct V_219 V_241 ;
if ( V_223 -> V_10 & V_225 )
continue;
F_34 ( V_20 >= V_237 ) ;
V_241 . V_69 = V_223 ;
V_241 . V_8 = F_55 ( V_223 , V_53 ) ;
if ( V_241 . V_8 == V_8 )
continue;
V_227 = F_163 ( V_239 , V_20 , & V_241 , V_242 ) ;
F_34 ( V_227 != 0 ) ;
V_20 ++ ;
} while_each_thread(leader, tsk) ;
int F_164 ( struct V_7 * V_8 , T_2 V_243 , bool V_244 )
{
struct V_68 * V_223 ;
const struct V_201 * V_201 = F_165 () , * V_245 ;
int V_90 ;
if ( ! F_166 ( V_8 ) )
return - V_246 ;
V_247:
F_162 () ;
if ( V_243 ) {
V_223 = F_167 ( V_243 ) ;
if ( ! V_223 ) {
F_168 () ;
V_90 = - V_229 ;
goto V_248;
}
V_245 = F_169 ( V_223 ) ;
if ( ! F_170 ( V_201 -> V_249 , V_250 ) &&
! F_170 ( V_201 -> V_249 , V_245 -> V_251 ) &&
! F_170 ( V_201 -> V_249 , V_245 -> V_252 ) ) {
F_168 () ;
V_90 = - V_253 ;
goto V_248;
}
} else
V_223 = V_156 ;
if ( V_244 )
V_223 = V_223 -> V_254 ;
if ( V_223 == V_255 || ( V_223 -> V_10 & V_256 ) ) {
V_90 = - V_149 ;
F_168 () ;
goto V_248;
}
F_171 ( V_223 ) ;
F_168 () ;
F_172 ( V_223 ) ;
if ( V_244 ) {
if ( ! F_173 ( V_223 ) ) {
F_174 ( V_223 ) ;
F_175 ( V_223 ) ;
goto V_247;
}
V_90 = F_158 ( V_8 , V_223 ) ;
} else
V_90 = F_156 ( V_8 , V_223 ) ;
F_174 ( V_223 ) ;
F_175 ( V_223 ) ;
V_248:
F_58 () ;
return V_90 ;
}
static int F_176 ( struct V_7 * V_8 , struct V_18 * V_99 , T_2 V_243 )
{
return F_164 ( V_8 , V_243 , false ) ;
}
static int F_177 ( struct V_7 * V_8 , struct V_18 * V_99 , T_2 V_257 )
{
return F_164 ( V_8 , V_257 , true ) ;
}
bool F_166 ( struct V_7 * V_8 )
{
F_57 ( & V_1 ) ;
if ( F_7 ( V_8 ) ) {
F_59 ( & V_1 ) ;
return false ;
}
return true ;
}
static int F_178 ( struct V_7 * V_8 , struct V_18 * V_99 ,
const char * V_258 )
{
F_179 ( sizeof( V_8 -> V_53 -> V_138 ) < V_152 ) ;
if ( strlen ( V_258 ) >= V_152 )
return - V_149 ;
if ( ! F_166 ( V_8 ) )
return - V_246 ;
F_57 ( & V_124 ) ;
strcpy ( V_8 -> V_53 -> V_138 , V_258 ) ;
F_59 ( & V_124 ) ;
F_58 () ;
return 0 ;
}
static int F_180 ( struct V_7 * V_8 , struct V_18 * V_99 ,
struct V_134 * V_135 )
{
if ( ! F_166 ( V_8 ) )
return - V_246 ;
F_104 ( V_135 , V_8 -> V_53 -> V_138 ) ;
F_181 ( V_135 , '\n' ) ;
F_58 () ;
return 0 ;
}
static T_3 F_182 ( struct V_7 * V_8 , struct V_18 * V_99 ,
struct V_259 * V_259 ,
const char T_4 * V_260 ,
T_5 V_261 , T_6 * V_262 )
{
char V_258 [ V_263 ] ;
int V_227 = 0 ;
char * V_264 ;
if ( ! V_261 )
return - V_149 ;
if ( V_261 >= sizeof( V_258 ) )
return - V_265 ;
if ( F_183 ( V_258 , V_260 , V_261 ) )
return - V_266 ;
V_258 [ V_261 ] = 0 ;
if ( V_99 -> V_267 ) {
T_2 V_268 = F_184 ( F_185 ( V_258 ) , & V_264 , 0 ) ;
if ( * V_264 )
return - V_149 ;
V_227 = V_99 -> V_267 ( V_8 , V_99 , V_268 ) ;
} else {
T_7 V_268 = F_186 ( F_185 ( V_258 ) , & V_264 , 0 ) ;
if ( * V_264 )
return - V_149 ;
V_227 = V_99 -> V_269 ( V_8 , V_99 , V_268 ) ;
}
if ( ! V_227 )
V_227 = V_261 ;
return V_227 ;
}
static T_3 F_187 ( struct V_7 * V_8 , struct V_18 * V_99 ,
struct V_259 * V_259 ,
const char T_4 * V_260 ,
T_5 V_261 , T_6 * V_262 )
{
char V_270 [ V_263 ] ;
int V_227 = 0 ;
T_5 V_271 = V_99 -> V_272 ;
char * V_258 = V_270 ;
if ( ! V_271 )
V_271 = sizeof( V_270 ) - 1 ;
if ( V_261 >= V_271 )
return - V_265 ;
if ( V_261 >= sizeof( V_270 ) ) {
V_258 = F_41 ( V_261 + 1 , V_60 ) ;
if ( V_258 == NULL )
return - V_61 ;
}
if ( V_261 && F_183 ( V_258 , V_260 , V_261 ) ) {
V_227 = - V_266 ;
goto V_231;
}
V_258 [ V_261 ] = 0 ;
V_227 = V_99 -> V_273 ( V_8 , V_99 , F_185 ( V_258 ) ) ;
if ( ! V_227 )
V_227 = V_261 ;
V_231:
if ( V_258 != V_270 )
F_27 ( V_258 ) ;
return V_227 ;
}
static T_3 F_188 ( struct V_259 * V_259 , const char T_4 * V_207 ,
T_5 V_261 , T_6 * V_274 )
{
struct V_18 * V_99 = F_14 ( V_259 -> V_275 ) ;
struct V_7 * V_8 = F_12 ( V_259 -> V_275 -> V_98 ) ;
if ( F_7 ( V_8 ) )
return - V_246 ;
if ( V_99 -> V_276 )
return V_99 -> V_276 ( V_8 , V_99 , V_259 , V_207 , V_261 , V_274 ) ;
if ( V_99 -> V_267 || V_99 -> V_269 )
return F_182 ( V_8 , V_99 , V_259 , V_207 , V_261 , V_274 ) ;
if ( V_99 -> V_273 )
return F_187 ( V_8 , V_99 , V_259 , V_207 , V_261 , V_274 ) ;
if ( V_99 -> V_277 ) {
int V_90 = V_99 -> V_277 ( V_8 , ( unsigned int ) V_99 -> V_278 ) ;
return V_90 ? V_90 : V_261 ;
}
return - V_149 ;
}
static T_3 F_189 ( struct V_7 * V_8 , struct V_18 * V_99 ,
struct V_259 * V_259 ,
char T_4 * V_207 , T_5 V_261 ,
T_6 * V_274 )
{
char V_22 [ V_263 ] ;
T_2 V_268 = V_99 -> V_279 ( V_8 , V_99 ) ;
int V_210 = sprintf ( V_22 , L_18 , ( unsigned long long ) V_268 ) ;
return F_190 ( V_207 , V_261 , V_274 , V_22 , V_210 ) ;
}
static T_3 F_191 ( struct V_7 * V_8 , struct V_18 * V_99 ,
struct V_259 * V_259 ,
char T_4 * V_207 , T_5 V_261 ,
T_6 * V_274 )
{
char V_22 [ V_263 ] ;
T_7 V_268 = V_99 -> V_280 ( V_8 , V_99 ) ;
int V_210 = sprintf ( V_22 , L_19 , ( long long ) V_268 ) ;
return F_190 ( V_207 , V_261 , V_274 , V_22 , V_210 ) ;
}
static T_3 F_192 ( struct V_259 * V_259 , char T_4 * V_207 ,
T_5 V_261 , T_6 * V_274 )
{
struct V_18 * V_99 = F_14 ( V_259 -> V_275 ) ;
struct V_7 * V_8 = F_12 ( V_259 -> V_275 -> V_98 ) ;
if ( F_7 ( V_8 ) )
return - V_246 ;
if ( V_99 -> V_281 )
return V_99 -> V_281 ( V_8 , V_99 , V_259 , V_207 , V_261 , V_274 ) ;
if ( V_99 -> V_279 )
return F_189 ( V_8 , V_99 , V_259 , V_207 , V_261 , V_274 ) ;
if ( V_99 -> V_280 )
return F_191 ( V_8 , V_99 , V_259 , V_207 , V_261 , V_274 ) ;
return - V_149 ;
}
static int F_193 ( struct V_282 * V_283 , const char * V_284 , T_2 V_285 )
{
struct V_134 * V_286 = V_283 -> V_287 ;
return F_103 ( V_286 , L_20 , V_284 , ( unsigned long long ) V_285 ) ;
}
static int F_194 ( struct V_134 * V_288 , void * V_289 )
{
struct V_290 * V_287 = V_288 -> V_278 ;
struct V_18 * V_99 = V_287 -> V_99 ;
if ( V_99 -> V_291 ) {
struct V_282 V_283 = {
. V_292 = F_193 ,
. V_287 = V_288 ,
} ;
return V_99 -> V_291 ( V_287 -> V_7 , V_99 , & V_283 ) ;
}
return V_99 -> V_293 ( V_287 -> V_7 , V_99 , V_288 ) ;
}
static int F_195 ( struct V_73 * V_73 , struct V_259 * V_259 )
{
struct V_134 * V_135 = V_259 -> V_294 ;
F_27 ( V_135 -> V_278 ) ;
return F_196 ( V_73 , V_259 ) ;
}
static int F_197 ( struct V_73 * V_73 , struct V_259 * V_259 )
{
int V_295 ;
struct V_18 * V_99 ;
V_295 = F_198 ( V_73 , V_259 ) ;
if ( V_295 )
return V_295 ;
V_99 = F_14 ( V_259 -> V_275 ) ;
if ( V_99 -> V_291 || V_99 -> V_293 ) {
struct V_290 * V_287 =
F_126 ( sizeof( * V_287 ) , V_296 ) ;
if ( ! V_287 )
return - V_61 ;
V_287 -> V_99 = V_99 ;
V_287 -> V_7 = F_12 ( V_259 -> V_275 -> V_98 ) ;
V_259 -> V_297 = & V_298 ;
V_295 = F_199 ( V_259 , F_194 , V_287 ) ;
if ( V_295 < 0 )
F_27 ( V_287 ) ;
} else if ( V_99 -> V_299 )
V_295 = V_99 -> V_299 ( V_73 , V_259 ) ;
else
V_295 = 0 ;
return V_295 ;
}
static int F_200 ( struct V_73 * V_73 , struct V_259 * V_259 )
{
struct V_18 * V_99 = F_14 ( V_259 -> V_275 ) ;
if ( V_99 -> V_300 )
return V_99 -> V_300 ( V_73 , V_259 ) ;
return 0 ;
}
static int F_201 ( struct V_73 * V_301 , struct V_15 * V_302 ,
struct V_73 * V_303 , struct V_15 * V_304 )
{
if ( ! F_69 ( V_302 -> V_103 -> V_78 ) )
return - V_305 ;
if ( V_304 -> V_103 )
return - V_306 ;
if ( V_301 != V_303 )
return - V_307 ;
return F_202 ( V_301 , V_302 , V_303 , V_304 ) ;
}
static struct V_308 * F_203 ( struct V_15 * V_15 )
{
if ( F_69 ( V_15 -> V_103 -> V_78 ) )
return & F_12 ( V_15 ) -> V_96 ;
else
return & F_14 ( V_15 ) -> V_96 ;
}
static inline int F_204 ( struct V_15 * V_15 )
{
struct V_55 * V_53 = V_15 -> V_113 -> V_114 ;
return F_8 ( V_137 , & V_53 -> V_10 ) ;
}
static bool F_205 ( const char * V_100 )
{
if ( ! strncmp ( V_100 , V_309 , V_310 ) ||
! strncmp ( V_100 , V_311 , V_312 ) )
return true ;
return false ;
}
static int F_206 ( struct V_15 * V_15 , const char * V_100 ,
const void * V_268 , T_5 V_313 , int V_10 )
{
if ( ! F_204 ( V_15 ) )
return - V_314 ;
if ( ! F_205 ( V_100 ) )
return - V_149 ;
return F_207 ( F_203 ( V_15 ) , V_100 , V_268 , V_313 , V_10 ) ;
}
static int F_208 ( struct V_15 * V_15 , const char * V_100 )
{
if ( ! F_204 ( V_15 ) )
return - V_314 ;
if ( ! F_205 ( V_100 ) )
return - V_149 ;
return F_209 ( F_203 ( V_15 ) , V_100 ) ;
}
static T_3 F_210 ( struct V_15 * V_15 , const char * V_100 ,
void * V_207 , T_5 V_313 )
{
if ( ! F_204 ( V_15 ) )
return - V_314 ;
if ( ! F_205 ( V_100 ) )
return - V_149 ;
return F_211 ( F_203 ( V_15 ) , V_100 , V_207 , V_313 ) ;
}
static T_3 F_212 ( struct V_15 * V_15 , char * V_207 , T_5 V_313 )
{
if ( ! F_204 ( V_15 ) )
return - V_314 ;
return F_213 ( F_203 ( V_15 ) , V_207 , V_313 ) ;
}
static struct V_15 * F_214 ( struct V_73 * V_106 , struct V_15 * V_15 , unsigned int V_10 )
{
if ( V_15 -> V_211 . V_210 > V_315 )
return F_127 ( - V_212 ) ;
F_215 ( V_15 , NULL ) ;
return NULL ;
}
static inline struct V_18 * F_216 ( struct V_259 * V_259 )
{
if ( V_259 -> V_275 -> V_103 -> V_188 != & V_316 )
return F_127 ( - V_149 ) ;
return F_14 ( V_259 -> V_275 ) ;
}
static int F_217 ( struct V_15 * V_15 , T_1 V_74 ,
struct V_75 * V_76 )
{
struct V_73 * V_73 ;
if ( ! V_15 )
return - V_105 ;
if ( V_15 -> V_103 )
return - V_306 ;
V_73 = F_60 ( V_74 , V_76 ) ;
if ( ! V_73 )
return - V_61 ;
if ( F_69 ( V_74 ) ) {
V_73 -> V_190 = & V_191 ;
V_73 -> V_188 = & V_189 ;
F_133 ( V_73 ) ;
F_218 ( & V_73 -> V_104 , V_317 ) ;
} else if ( F_219 ( V_74 ) ) {
V_73 -> V_318 = 0 ;
V_73 -> V_188 = & V_316 ;
V_73 -> V_190 = & V_319 ;
}
F_220 ( V_15 , V_73 ) ;
F_77 ( V_15 ) ;
return 0 ;
}
static int F_221 ( struct V_7 * V_8 , struct V_15 * V_15 ,
T_1 V_74 )
{
struct V_15 * V_102 ;
int error = 0 ;
V_102 = V_8 -> V_102 -> V_15 ;
error = F_217 ( V_15 , V_184 | V_74 , V_8 -> V_53 -> V_76 ) ;
if ( ! error ) {
V_15 -> V_16 = V_8 ;
F_133 ( V_102 -> V_103 ) ;
F_154 ( V_8 -> V_15 , V_15 ) ;
F_77 ( V_15 ) ;
}
F_80 ( V_15 ) ;
return error ;
}
static T_1 F_222 ( const struct V_18 * V_99 )
{
T_1 V_74 = 0 ;
if ( V_99 -> V_74 )
return V_99 -> V_74 ;
if ( V_99 -> V_281 || V_99 -> V_279 || V_99 -> V_280 ||
V_99 -> V_291 || V_99 -> V_293 )
V_74 |= V_185 ;
if ( V_99 -> V_276 || V_99 -> V_267 || V_99 -> V_269 ||
V_99 -> V_273 || V_99 -> V_277 )
V_74 |= V_187 ;
return V_74 ;
}
static int F_223 ( struct V_7 * V_8 , struct V_88 * V_46 ,
struct V_18 * V_99 )
{
struct V_15 * V_106 = V_8 -> V_15 ;
struct V_7 * V_102 = F_12 ( V_106 ) ;
struct V_15 * V_15 ;
struct V_17 * V_97 ;
int error ;
T_1 V_74 ;
char V_100 [ V_320 + V_321 + 2 ] = { 0 } ;
F_118 ( & V_99 -> V_96 ) ;
if ( ( V_99 -> V_10 & V_322 ) && ! V_8 -> V_102 )
return 0 ;
if ( ( V_99 -> V_10 & V_323 ) && V_8 -> V_102 )
return 0 ;
if ( V_46 && ! F_8 ( V_136 , & V_8 -> V_53 -> V_10 ) ) {
strcpy ( V_100 , V_46 -> V_100 ) ;
strcat ( V_100 , L_21 ) ;
}
strcat ( V_100 , V_99 -> V_100 ) ;
F_34 ( ! F_3 ( & V_106 -> V_103 -> V_104 ) ) ;
V_97 = F_126 ( sizeof( * V_97 ) , V_60 ) ;
if ( ! V_97 )
return - V_61 ;
V_15 = F_224 ( V_100 , V_106 , strlen ( V_100 ) ) ;
if ( F_136 ( V_15 ) ) {
error = F_137 ( V_15 ) ;
goto V_231;
}
V_74 = F_222 ( V_99 ) ;
error = F_217 ( V_15 , V_74 | V_324 , V_8 -> V_53 -> V_76 ) ;
if ( ! error ) {
V_97 -> type = ( void * ) V_99 ;
V_97 -> V_15 = V_15 ;
V_15 -> V_16 = V_97 ;
F_47 ( & V_97 -> V_58 , & V_102 -> V_112 ) ;
V_97 = NULL ;
}
F_80 ( V_15 ) ;
V_231:
F_27 ( V_97 ) ;
return error ;
}
static int F_225 ( struct V_7 * V_8 , struct V_88 * V_46 ,
struct V_18 V_111 [] , bool V_325 )
{
struct V_18 * V_99 ;
int V_295 , V_90 = 0 ;
for ( V_99 = V_111 ; V_99 -> V_100 [ 0 ] != '\0' ; V_99 ++ ) {
if ( V_325 )
V_295 = F_223 ( V_8 , V_46 , V_99 ) ;
else
V_295 = F_81 ( V_8 , V_99 ) ;
if ( V_295 ) {
F_112 ( L_22 ,
V_325 ? L_23 : L_24 , V_99 -> V_100 , V_295 ) ;
V_90 = V_295 ;
}
}
return V_90 ;
}
static void F_226 ( void )
__acquires( &cgroup_cft_mutex
static void F_227 ( struct V_88 * V_89 ,
struct V_18 * V_111 , bool V_325 )
__releases( &cgroup_mutex
int F_228 ( struct V_88 * V_89 , struct V_18 * V_111 )
{
struct V_108 * V_109 ;
V_109 = F_126 ( sizeof( * V_109 ) , V_60 ) ;
if ( ! V_109 )
return - V_61 ;
F_226 () ;
V_109 -> V_111 = V_111 ;
F_47 ( & V_109 -> V_58 , & V_89 -> V_326 ) ;
F_227 ( V_89 , V_111 , true ) ;
return 0 ;
}
int F_229 ( struct V_88 * V_89 , struct V_18 * V_111 )
{
struct V_108 * V_109 ;
F_226 () ;
F_53 (set, &ss->cftsets, node) {
if ( V_109 -> V_111 == V_111 ) {
F_84 ( & V_109 -> V_58 ) ;
F_227 ( V_89 , V_111 , false ) ;
return 0 ;
}
}
F_227 ( V_89 , NULL , false ) ;
return - V_105 ;
}
int F_230 ( const struct V_7 * V_8 )
{
int V_38 = 0 ;
struct V_29 * V_30 ;
F_49 ( & V_33 ) ;
F_53 (link, &cgrp->css_sets, cgrp_link_list) {
V_38 += F_6 ( & V_30 -> V_27 -> V_32 ) ;
}
F_50 ( & V_33 ) ;
return V_38 ;
}
static void F_231 ( struct V_7 * V_8 ,
struct V_327 * V_328 )
{
struct V_43 * V_329 = V_328 -> V_330 ;
struct V_29 * V_30 ;
struct V_26 * V_27 ;
do {
V_329 = V_329 -> V_52 ;
if ( V_329 == & V_8 -> V_63 ) {
V_328 -> V_330 = NULL ;
return;
}
V_30 = F_35 ( V_329 , struct V_29 , V_37 ) ;
V_27 = V_30 -> V_27 ;
} while ( F_44 ( & V_27 -> V_66 ) );
V_328 -> V_330 = V_329 ;
V_328 -> V_69 = V_27 -> V_66 . V_52 ;
}
static void F_232 ( void )
{
struct V_68 * V_331 , * V_332 ;
F_19 ( & V_33 ) ;
V_333 = 1 ;
F_49 ( & V_334 ) ;
F_233 (g, p) {
F_153 ( V_331 ) ;
if ( ! ( V_331 -> V_10 & V_225 ) && F_44 ( & V_331 -> V_226 ) )
F_42 ( & V_331 -> V_226 , & V_331 -> V_70 -> V_66 ) ;
F_155 ( V_331 ) ;
} F_234 ( V_332 , V_331 ) ;
F_50 ( & V_334 ) ;
F_21 ( & V_33 ) ;
}
void F_235 ( struct V_7 * V_8 , struct V_327 * V_328 )
__acquires( V_33 )
{
if ( ! V_333 )
F_232 () ;
F_49 ( & V_33 ) ;
V_328 -> V_330 = & V_8 -> V_63 ;
F_231 ( V_8 , V_328 ) ;
}
struct V_68 * F_236 ( struct V_7 * V_8 ,
struct V_327 * V_328 )
{
struct V_68 * V_64 ;
struct V_43 * V_329 = V_328 -> V_69 ;
struct V_29 * V_30 ;
if ( ! V_328 -> V_330 )
return NULL ;
V_64 = F_35 ( V_329 , struct V_68 , V_226 ) ;
V_329 = V_329 -> V_52 ;
V_30 = F_35 ( V_328 -> V_330 , struct V_29 , V_37 ) ;
if ( V_329 == & V_30 -> V_27 -> V_66 ) {
F_231 ( V_8 , V_328 ) ;
} else {
V_328 -> V_69 = V_329 ;
}
return V_64 ;
}
void F_237 ( struct V_7 * V_8 , struct V_327 * V_328 )
__releases( V_33 )
{
F_50 ( & V_33 ) ;
}
static inline int F_238 ( struct V_68 * V_335 ,
struct V_336 * time ,
struct V_68 * V_337 )
{
int V_338 = F_239 ( & V_335 -> V_339 , time ) ;
if ( V_338 > 0 ) {
return 1 ;
} else if ( V_338 < 0 ) {
return 0 ;
} else {
return V_335 > V_337 ;
}
}
static inline int F_240 ( void * V_340 , void * V_341 )
{
struct V_68 * V_335 = V_340 ;
struct V_68 * V_337 = V_341 ;
return F_238 ( V_335 , & V_337 -> V_339 , V_337 ) ;
}
int F_241 ( struct V_342 * V_343 )
{
int V_227 , V_20 ;
struct V_327 V_328 ;
struct V_68 * V_331 , * V_344 ;
struct V_68 * V_345 = NULL ;
struct V_346 V_347 ;
struct V_346 * V_348 ;
struct V_336 V_349 = { 0 , 0 } ;
if ( V_343 -> V_348 ) {
V_348 = V_343 -> V_348 ;
V_348 -> V_350 = & F_240 ;
} else {
V_348 = & V_347 ;
V_227 = F_242 ( V_348 , V_351 , V_60 , & F_240 ) ;
if ( V_227 )
return V_227 ;
}
V_352:
V_348 -> V_313 = 0 ;
F_235 ( V_343 -> V_27 , & V_328 ) ;
while ( ( V_331 = F_236 ( V_343 -> V_27 , & V_328 ) ) ) {
if ( V_343 -> V_353 && ! V_343 -> V_353 ( V_331 , V_343 ) )
continue;
if ( ! F_238 ( V_331 , & V_349 , V_345 ) )
continue;
V_344 = F_243 ( V_348 , V_331 ) ;
if ( V_344 == NULL ) {
F_171 ( V_331 ) ;
} else if ( V_344 != V_331 ) {
F_171 ( V_331 ) ;
F_175 ( V_344 ) ;
}
}
F_237 ( V_343 -> V_27 , & V_328 ) ;
if ( V_348 -> V_313 ) {
for ( V_20 = 0 ; V_20 < V_348 -> V_313 ; V_20 ++ ) {
struct V_68 * V_354 = V_348 -> V_355 [ V_20 ] ;
if ( V_20 == 0 ) {
V_349 = V_354 -> V_339 ;
V_345 = V_354 ;
}
V_343 -> V_356 ( V_354 , V_343 ) ;
F_175 ( V_354 ) ;
}
goto V_352;
}
if ( V_348 == & V_347 )
F_244 ( & V_347 ) ;
return 0 ;
}
static void * F_245 ( int V_38 )
{
if ( F_246 ( V_38 ) )
return F_247 ( V_38 * sizeof( V_357 ) ) ;
else
return F_41 ( V_38 * sizeof( V_357 ) , V_60 ) ;
}
static void F_248 ( void * V_331 )
{
if ( F_249 ( V_331 ) )
F_250 ( V_331 ) ;
else
F_27 ( V_331 ) ;
}
static void * F_251 ( void * V_331 , int V_358 )
{
void * V_359 ;
if ( F_249 ( V_331 ) ) {
V_359 = F_247 ( V_358 * sizeof( V_357 ) ) ;
if ( ! V_359 )
return NULL ;
memcpy ( V_359 , V_331 , V_358 * sizeof( V_357 ) ) ;
F_250 ( V_331 ) ;
} else {
V_359 = F_252 ( V_331 , V_358 * sizeof( V_357 ) , V_60 ) ;
}
return V_359 ;
}
static int F_253 ( V_357 * * V_331 , int V_360 )
{
int V_361 , V_362 = 1 ;
V_357 * V_363 = * V_331 ;
V_357 * V_359 ;
if ( V_360 == 0 || V_360 == 1 )
return V_360 ;
for ( V_361 = 1 ; V_361 < V_360 ; V_361 ++ ) {
while ( V_363 [ V_361 ] == V_363 [ V_361 - 1 ] ) {
V_361 ++ ;
if ( V_361 == V_360 )
goto V_364;
}
V_363 [ V_362 ] = V_363 [ V_361 ] ;
V_362 ++ ;
}
V_364:
if ( F_254 ( V_360 , V_362 ) ) {
V_359 = F_251 ( V_363 , V_362 ) ;
if ( V_359 )
* V_331 = V_359 ;
}
return V_362 ;
}
static int F_255 ( const void * V_365 , const void * V_366 )
{
return * ( V_357 * ) V_365 - * ( V_357 * ) V_366 ;
}
static struct V_367 * F_256 ( struct V_7 * V_8 ,
enum V_368 type )
{
struct V_367 * V_329 ;
struct V_369 * V_370 = V_156 -> V_371 -> V_372 ;
F_57 ( & V_8 -> V_160 ) ;
F_53 (l, &cgrp->pidlists, links) {
if ( V_329 -> V_284 . type == type && V_329 -> V_284 . V_370 == V_370 ) {
F_257 ( & V_329 -> V_373 ) ;
F_59 ( & V_8 -> V_160 ) ;
return V_329 ;
}
}
V_329 = F_41 ( sizeof( struct V_367 ) , V_60 ) ;
if ( ! V_329 ) {
F_59 ( & V_8 -> V_160 ) ;
return V_329 ;
}
F_258 ( & V_329 -> V_373 ) ;
F_257 ( & V_329 -> V_373 ) ;
V_329 -> V_284 . type = type ;
V_329 -> V_284 . V_370 = F_259 ( V_370 ) ;
V_329 -> V_374 = 0 ;
V_329 -> V_363 = NULL ;
V_329 -> V_375 = V_8 ;
F_42 ( & V_329 -> V_376 , & V_8 -> V_95 ) ;
F_59 ( & V_8 -> V_160 ) ;
return V_329 ;
}
static int F_260 ( struct V_7 * V_8 , enum V_368 type ,
struct V_367 * * V_377 )
{
V_357 * V_378 ;
int V_360 ;
int V_243 , V_379 = 0 ;
struct V_327 V_328 ;
struct V_68 * V_223 ;
struct V_367 * V_329 ;
V_360 = F_230 ( V_8 ) ;
V_378 = F_245 ( V_360 ) ;
if ( ! V_378 )
return - V_61 ;
F_235 ( V_8 , & V_328 ) ;
while ( ( V_223 = F_236 ( V_8 , & V_328 ) ) ) {
if ( F_91 ( V_379 == V_360 ) )
break;
if ( type == V_380 )
V_243 = F_261 ( V_223 ) ;
else
V_243 = F_262 ( V_223 ) ;
if ( V_243 > 0 )
V_378 [ V_379 ++ ] = V_243 ;
}
F_237 ( V_8 , & V_328 ) ;
V_360 = V_379 ;
F_263 ( V_378 , V_360 , sizeof( V_357 ) , F_255 , NULL ) ;
if ( type == V_380 )
V_360 = F_253 ( & V_378 , V_360 ) ;
V_329 = F_256 ( V_8 , type ) ;
if ( ! V_329 ) {
F_248 ( V_378 ) ;
return - V_61 ;
}
F_248 ( V_329 -> V_363 ) ;
V_329 -> V_363 = V_378 ;
V_329 -> V_360 = V_360 ;
V_329 -> V_374 ++ ;
F_264 ( & V_329 -> V_373 ) ;
* V_377 = V_329 ;
return 0 ;
}
int F_265 ( struct V_381 * V_382 , struct V_15 * V_15 )
{
int V_90 = - V_149 ;
struct V_7 * V_8 ;
struct V_327 V_328 ;
struct V_68 * V_223 ;
if ( V_15 -> V_113 -> V_179 != & V_180 ||
! F_69 ( V_15 -> V_103 -> V_78 ) )
goto V_295;
V_90 = 0 ;
V_8 = V_15 -> V_16 ;
F_235 ( V_8 , & V_328 ) ;
while ( ( V_223 = F_236 ( V_8 , & V_328 ) ) ) {
switch ( V_223 -> V_287 ) {
case V_383 :
V_382 -> V_384 ++ ;
break;
case V_385 :
V_382 -> V_386 ++ ;
break;
case V_387 :
V_382 -> V_388 ++ ;
break;
case V_389 :
V_382 -> V_390 ++ ;
break;
default:
if ( F_266 ( V_223 ) )
V_382 -> V_391 ++ ;
break;
}
}
F_237 ( V_8 , & V_328 ) ;
V_295:
return V_90 ;
}
static void * F_267 ( struct V_134 * V_392 , T_6 * V_393 )
{
struct V_367 * V_329 = V_392 -> V_278 ;
int V_21 = 0 , V_243 = * V_393 ;
int * V_394 ;
F_268 ( & V_329 -> V_373 ) ;
if ( V_243 ) {
int V_264 = V_329 -> V_360 ;
while ( V_21 < V_264 ) {
int V_395 = ( V_21 + V_264 ) / 2 ;
if ( V_329 -> V_363 [ V_395 ] == V_243 ) {
V_21 = V_395 ;
break;
} else if ( V_329 -> V_363 [ V_395 ] <= V_243 )
V_21 = V_395 + 1 ;
else
V_264 = V_395 ;
}
}
if ( V_21 >= V_329 -> V_360 )
return NULL ;
V_394 = V_329 -> V_363 + V_21 ;
* V_393 = * V_394 ;
return V_394 ;
}
static void F_269 ( struct V_134 * V_392 , void * V_6 )
{
struct V_367 * V_329 = V_392 -> V_278 ;
F_270 ( & V_329 -> V_373 ) ;
}
static void * F_271 ( struct V_134 * V_392 , void * V_6 , T_6 * V_393 )
{
struct V_367 * V_329 = V_392 -> V_278 ;
V_357 * V_331 = V_6 ;
V_357 * V_264 = V_329 -> V_363 + V_329 -> V_360 ;
V_331 ++ ;
if ( V_331 >= V_264 ) {
return NULL ;
} else {
* V_393 = * V_331 ;
return V_331 ;
}
}
static int F_272 ( struct V_134 * V_392 , void * V_6 )
{
return F_103 ( V_392 , L_25 , * ( int * ) V_6 ) ;
}
static void F_273 ( struct V_367 * V_329 )
{
F_57 ( & V_329 -> V_375 -> V_160 ) ;
F_257 ( & V_329 -> V_373 ) ;
F_34 ( ! V_329 -> V_374 ) ;
if ( ! -- V_329 -> V_374 ) {
F_24 ( & V_329 -> V_376 ) ;
F_59 ( & V_329 -> V_375 -> V_160 ) ;
F_248 ( V_329 -> V_363 ) ;
F_274 ( V_329 -> V_284 . V_370 ) ;
F_264 ( & V_329 -> V_373 ) ;
F_27 ( V_329 ) ;
return;
}
F_59 ( & V_329 -> V_375 -> V_160 ) ;
F_264 ( & V_329 -> V_373 ) ;
}
static int F_275 ( struct V_73 * V_73 , struct V_259 * V_259 )
{
struct V_367 * V_329 ;
if ( ! ( V_259 -> V_396 & V_397 ) )
return 0 ;
V_329 = ( (struct V_134 * ) V_259 -> V_294 ) -> V_278 ;
F_273 ( V_329 ) ;
return F_276 ( V_73 , V_259 ) ;
}
static int F_277 ( struct V_259 * V_259 , enum V_368 type )
{
struct V_7 * V_8 = F_12 ( V_259 -> V_275 -> V_98 ) ;
struct V_367 * V_329 ;
int V_227 ;
if ( ! ( V_259 -> V_396 & V_397 ) )
return 0 ;
V_227 = F_260 ( V_8 , type , & V_329 ) ;
if ( V_227 )
return V_227 ;
V_259 -> V_297 = & V_398 ;
V_227 = F_278 ( V_259 , & V_399 ) ;
if ( V_227 ) {
F_273 ( V_329 ) ;
return V_227 ;
}
( (struct V_134 * ) V_259 -> V_294 ) -> V_278 = V_329 ;
return 0 ;
}
static int F_279 ( struct V_73 * V_400 , struct V_259 * V_259 )
{
return F_277 ( V_259 , V_401 ) ;
}
static int F_280 ( struct V_73 * V_400 , struct V_259 * V_259 )
{
return F_277 ( V_259 , V_380 ) ;
}
static T_2 F_281 ( struct V_7 * V_8 ,
struct V_18 * V_99 )
{
return F_10 ( V_8 ) ;
}
static int F_282 ( struct V_7 * V_8 ,
struct V_18 * V_99 ,
T_2 V_268 )
{
F_283 ( V_12 , & V_8 -> V_10 ) ;
if ( V_268 )
F_25 ( V_13 , & V_8 -> V_10 ) ;
else
F_283 ( V_13 , & V_8 -> V_10 ) ;
return 0 ;
}
static void F_284 ( struct V_402 * V_403 )
{
struct V_404 * V_405 = F_285 ( V_403 , struct V_404 ,
remove ) ;
struct V_7 * V_8 = V_405 -> V_8 ;
V_405 -> V_99 -> V_406 ( V_8 , V_405 -> V_99 , V_405 -> V_407 ) ;
F_286 ( V_405 -> V_407 ) ;
F_27 ( V_405 ) ;
F_80 ( V_8 -> V_15 ) ;
}
static int F_287 ( T_8 * V_408 , unsigned V_74 ,
int V_409 , void * V_284 )
{
struct V_404 * V_405 = F_285 ( V_408 ,
struct V_404 , V_408 ) ;
struct V_7 * V_8 = V_405 -> V_8 ;
unsigned long V_10 = ( unsigned long ) V_284 ;
if ( V_10 & V_410 ) {
F_288 ( V_405 -> V_411 , & V_405 -> V_408 ) ;
F_87 ( & V_8 -> V_162 ) ;
F_24 ( & V_405 -> V_363 ) ;
F_89 ( & V_8 -> V_162 ) ;
F_289 ( & V_405 -> remove ) ;
}
return 0 ;
}
static void F_290 ( struct V_259 * V_259 ,
T_9 * V_411 , T_10 * V_412 )
{
struct V_404 * V_405 = F_285 ( V_412 ,
struct V_404 , V_412 ) ;
V_405 -> V_411 = V_411 ;
F_291 ( V_411 , & V_405 -> V_408 ) ;
}
static int F_292 ( struct V_7 * V_8 , struct V_18 * V_99 ,
const char * V_258 )
{
struct V_404 * V_405 = NULL ;
unsigned int V_413 , V_414 ;
struct V_259 * V_415 = NULL ;
struct V_259 * V_416 = NULL ;
char * V_417 ;
int V_90 ;
V_413 = F_293 ( V_258 , & V_417 , 10 ) ;
if ( * V_417 != ' ' )
return - V_149 ;
V_258 = V_417 + 1 ;
V_414 = F_293 ( V_258 , & V_417 , 10 ) ;
if ( ( * V_417 != ' ' ) && ( * V_417 != '\0' ) )
return - V_149 ;
V_258 = V_417 + 1 ;
V_405 = F_126 ( sizeof( * V_405 ) , V_60 ) ;
if ( ! V_405 )
return - V_61 ;
V_405 -> V_8 = V_8 ;
F_40 ( & V_405 -> V_363 ) ;
F_294 ( & V_405 -> V_412 , F_290 ) ;
F_295 ( & V_405 -> V_408 , F_287 ) ;
F_296 ( & V_405 -> remove , F_284 ) ;
V_415 = F_297 ( V_413 ) ;
if ( F_136 ( V_415 ) ) {
V_90 = F_137 ( V_415 ) ;
goto V_418;
}
V_405 -> V_407 = F_298 ( V_415 ) ;
if ( F_136 ( V_405 -> V_407 ) ) {
V_90 = F_137 ( V_405 -> V_407 ) ;
goto V_418;
}
V_416 = F_299 ( V_414 ) ;
if ( ! V_416 ) {
V_90 = - V_419 ;
goto V_418;
}
V_90 = F_300 ( V_416 -> V_420 . V_15 -> V_103 , V_421 ) ;
if ( V_90 < 0 )
goto V_418;
V_405 -> V_99 = F_216 ( V_416 ) ;
if ( F_136 ( V_405 -> V_99 ) ) {
V_90 = F_137 ( V_405 -> V_99 ) ;
goto V_418;
}
if ( ! V_405 -> V_99 -> V_422 || ! V_405 -> V_99 -> V_406 ) {
V_90 = - V_149 ;
goto V_418;
}
V_90 = V_405 -> V_99 -> V_422 ( V_8 , V_405 -> V_99 ,
V_405 -> V_407 , V_258 ) ;
if ( V_90 )
goto V_418;
if ( V_415 -> V_297 -> V_423 ( V_415 , & V_405 -> V_412 ) & V_410 ) {
V_405 -> V_99 -> V_406 ( V_8 , V_405 -> V_99 , V_405 -> V_407 ) ;
V_90 = 0 ;
goto V_418;
}
F_77 ( V_8 -> V_15 ) ;
F_87 ( & V_8 -> V_162 ) ;
F_42 ( & V_405 -> V_363 , & V_8 -> V_161 ) ;
F_89 ( & V_8 -> V_162 ) ;
F_301 ( V_416 ) ;
F_301 ( V_415 ) ;
return 0 ;
V_418:
if ( V_416 )
F_301 ( V_416 ) ;
if ( V_405 && V_405 -> V_407 && ! F_136 ( V_405 -> V_407 ) )
F_286 ( V_405 -> V_407 ) ;
if ( ! F_302 ( V_415 ) )
F_301 ( V_415 ) ;
F_27 ( V_405 ) ;
return V_90 ;
}
static T_2 F_303 ( struct V_7 * V_8 ,
struct V_18 * V_99 )
{
return F_11 ( V_8 ) ;
}
static int F_304 ( struct V_7 * V_8 ,
struct V_18 * V_99 ,
T_2 V_268 )
{
if ( V_268 )
F_25 ( V_14 , & V_8 -> V_10 ) ;
else
F_283 ( V_14 , & V_8 -> V_10 ) ;
return 0 ;
}
static int F_114 ( struct V_7 * V_8 , bool V_107 ,
unsigned long V_59 )
{
int V_295 ;
struct V_88 * V_89 ;
if ( V_107 ) {
V_295 = F_225 ( V_8 , NULL , V_112 , true ) ;
if ( V_295 < 0 )
return V_295 ;
}
F_66 (cgrp->root, ss) {
struct V_108 * V_109 ;
if ( ! F_8 ( V_89 -> V_110 , & V_59 ) )
continue;
F_53 (set, &ss->cftsets, node)
F_225 ( V_8 , V_89 , V_109 -> V_111 , true ) ;
}
F_66 (cgrp->root, ss) {
struct V_4 * V_5 = V_8 -> V_46 [ V_89 -> V_110 ] ;
if ( V_5 -> V_424 )
F_154 ( V_5 -> V_424 -> V_5 , V_5 ) ;
}
return 0 ;
}
static void F_305 ( struct V_402 * V_403 )
{
struct V_4 * V_5 =
F_285 ( V_403 , struct V_4 , V_425 ) ;
struct V_15 * V_15 = V_5 -> V_7 -> V_15 ;
struct V_75 * V_76 = V_15 -> V_113 ;
F_30 ( & V_76 -> V_426 ) ;
F_80 ( V_15 ) ;
F_71 ( V_76 ) ;
}
static void F_306 ( struct V_4 * V_5 ,
struct V_88 * V_89 ,
struct V_7 * V_8 )
{
V_5 -> V_7 = V_8 ;
F_51 ( & V_5 -> V_2 , 1 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_424 = NULL ;
if ( V_8 == V_129 )
F_25 ( V_427 , & V_5 -> V_10 ) ;
F_34 ( V_8 -> V_46 [ V_89 -> V_110 ] ) ;
V_8 -> V_46 [ V_89 -> V_110 ] = V_5 ;
F_296 ( & V_5 -> V_425 , F_305 ) ;
if ( V_89 -> V_92 )
F_25 ( V_428 , & V_5 -> V_10 ) ;
}
static long F_307 ( struct V_7 * V_102 , struct V_15 * V_15 ,
T_1 V_74 )
{
struct V_7 * V_8 ;
struct V_55 * V_53 = V_102 -> V_53 ;
int V_295 = 0 ;
struct V_88 * V_89 ;
struct V_75 * V_76 = V_53 -> V_76 ;
V_8 = F_126 ( sizeof( * V_8 ) , V_60 ) ;
if ( ! V_8 )
return - V_61 ;
F_30 ( & V_76 -> V_426 ) ;
F_57 ( & V_1 ) ;
F_115 ( V_8 ) ;
V_8 -> V_102 = V_102 ;
V_8 -> V_53 = V_102 -> V_53 ;
V_8 -> V_72 = V_102 -> V_72 ;
if ( F_10 ( V_102 ) )
F_25 ( V_13 , & V_8 -> V_10 ) ;
if ( F_11 ( V_102 ) )
F_25 ( V_14 , & V_8 -> V_10 ) ;
F_66 (root, ss) {
struct V_4 * V_5 ;
V_5 = V_89 -> V_429 ( V_8 ) ;
if ( F_136 ( V_5 ) ) {
V_295 = F_137 ( V_5 ) ;
goto V_430;
}
F_306 ( V_5 , V_89 , V_8 ) ;
if ( V_89 -> V_431 ) {
V_295 = F_308 ( V_89 , V_102 , V_8 ) ;
if ( V_295 )
goto V_430;
}
if ( F_11 ( V_102 ) && V_89 -> V_432 )
V_89 -> V_432 ( V_8 ) ;
if ( V_89 -> V_433 && ! V_89 -> V_434 &&
V_102 -> V_102 ) {
F_112 ( L_26 ,
V_156 -> V_157 , V_156 -> V_243 , V_89 -> V_100 ) ;
if ( ! strcmp ( V_89 -> V_100 , L_27 ) )
F_112 ( L_28 ) ;
V_89 -> V_434 = true ;
}
}
F_42 ( & V_8 -> V_130 , & V_8 -> V_102 -> V_158 ) ;
V_53 -> V_94 ++ ;
V_295 = F_221 ( V_8 , V_15 , V_74 ) ;
if ( V_295 < 0 )
goto V_435;
F_66 (root, ss)
if ( ! V_89 -> V_92 )
F_77 ( V_15 ) ;
F_34 ( ! F_3 ( & V_8 -> V_15 -> V_103 -> V_104 ) ) ;
F_47 ( & V_8 -> V_165 , & V_53 -> V_164 ) ;
V_295 = F_114 ( V_8 , true , V_53 -> V_59 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_8 -> V_15 -> V_103 -> V_104 ) ;
return 0 ;
V_435:
F_24 ( & V_8 -> V_130 ) ;
V_53 -> V_94 -- ;
V_430:
F_66 (root, ss) {
if ( V_8 -> V_46 [ V_89 -> V_110 ] )
V_89 -> V_93 ( V_8 ) ;
}
F_59 ( & V_1 ) ;
F_71 ( V_76 ) ;
F_27 ( V_8 ) ;
return V_295 ;
}
static int F_309 ( struct V_73 * V_106 , struct V_15 * V_15 , T_1 V_74 )
{
struct V_7 * V_436 = V_15 -> V_98 -> V_16 ;
return F_307 ( V_436 , V_15 , V_74 | V_184 ) ;
}
static int F_310 ( struct V_7 * V_8 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
struct V_4 * V_5 ;
if ( V_89 == NULL || V_89 -> V_53 != V_8 -> V_53 )
continue;
V_5 = V_8 -> V_46 [ V_89 -> V_110 ] ;
if ( V_5 && F_5 ( V_5 ) > 1 )
return 1 ;
}
return 0 ;
}
static int F_311 ( struct V_7 * V_8 )
{
struct V_88 * V_89 ;
unsigned long V_10 ;
bool V_437 = false ;
F_312 ( V_10 ) ;
F_66 (cgrp->root, ss) {
struct V_4 * V_5 = V_8 -> V_46 [ V_89 -> V_110 ] ;
F_313 ( F_6 ( & V_5 -> V_2 ) < 0 ) ;
F_314 ( V_3 , & V_5 -> V_2 ) ;
if ( V_89 -> V_92 )
V_437 |= F_5 ( V_5 ) != 1 ;
}
F_66 (cgrp->root, ss) {
struct V_4 * V_5 = V_8 -> V_46 [ V_89 -> V_110 ] ;
if ( ! V_437 ) {
F_25 ( V_438 , & V_5 -> V_10 ) ;
F_97 ( V_5 ) ;
} else {
F_315 ( V_3 , & V_5 -> V_2 ) ;
}
}
F_316 ( V_10 ) ;
return ! V_437 ;
}
static int F_317 ( struct V_73 * V_439 , struct V_15 * V_15 )
{
struct V_7 * V_8 = V_15 -> V_16 ;
struct V_15 * V_101 ;
struct V_7 * V_102 ;
F_318 ( V_408 ) ;
struct V_404 * V_405 , * V_22 ;
int V_90 ;
V_352:
F_57 ( & V_1 ) ;
if ( F_6 ( & V_8 -> V_38 ) != 0 ) {
F_59 ( & V_1 ) ;
return - V_128 ;
}
if ( ! F_44 ( & V_8 -> V_158 ) ) {
F_59 ( & V_1 ) ;
return - V_128 ;
}
F_59 ( & V_1 ) ;
F_25 ( V_119 , & V_8 -> V_10 ) ;
V_90 = F_65 ( V_8 ) ;
if ( V_90 ) {
F_283 ( V_119 , & V_8 -> V_10 ) ;
return V_90 ;
}
F_57 ( & V_1 ) ;
V_102 = V_8 -> V_102 ;
if ( F_6 ( & V_8 -> V_38 ) || ! F_44 ( & V_8 -> V_158 ) ) {
F_283 ( V_119 , & V_8 -> V_10 ) ;
F_59 ( & V_1 ) ;
return - V_128 ;
}
F_319 ( & V_120 , & V_408 , V_385 ) ;
if ( ! F_311 ( V_8 ) ) {
F_59 ( & V_1 ) ;
if ( F_8 ( V_119 , & V_8 -> V_10 ) )
F_320 () ;
F_321 ( & V_120 , & V_408 ) ;
F_283 ( V_119 , & V_8 -> V_10 ) ;
if ( F_322 ( V_156 ) )
return - V_440 ;
goto V_352;
}
F_321 ( & V_120 , & V_408 ) ;
F_283 ( V_119 , & V_8 -> V_10 ) ;
F_323 ( & V_441 ) ;
F_25 ( V_9 , & V_8 -> V_10 ) ;
if ( ! F_44 ( & V_8 -> V_159 ) )
F_84 ( & V_8 -> V_159 ) ;
F_324 ( & V_441 ) ;
F_84 ( & V_8 -> V_130 ) ;
F_84 ( & V_8 -> V_165 ) ;
V_101 = F_77 ( V_8 -> V_15 ) ;
F_86 ( V_101 ) ;
F_80 ( V_101 ) ;
F_25 ( V_12 , & V_102 -> V_10 ) ;
F_26 ( V_102 ) ;
F_87 ( & V_8 -> V_162 ) ;
F_23 (event, tmp, &cgrp->event_list, list) {
F_24 ( & V_405 -> V_363 ) ;
F_325 ( V_405 -> V_411 , & V_405 -> V_408 ) ;
F_326 ( V_405 -> V_407 , 1 ) ;
F_289 ( & V_405 -> remove ) ;
}
F_89 ( & V_8 -> V_162 ) ;
F_59 ( & V_1 ) ;
return 0 ;
}
static void T_11 F_327 ( struct V_88 * V_89 )
{
F_40 ( & V_89 -> V_326 ) ;
if ( V_89 -> V_442 ) {
V_89 -> V_443 . V_111 = V_89 -> V_442 ;
F_47 ( & V_89 -> V_443 . V_58 , & V_89 -> V_326 ) ;
}
}
static void T_12 F_328 ( struct V_88 * V_89 )
{
struct V_4 * V_5 ;
F_329 ( V_444 L_29 , V_89 -> V_100 ) ;
F_327 ( V_89 ) ;
F_42 ( & V_89 -> V_130 , & V_127 . V_131 ) ;
V_89 -> V_53 = & V_127 ;
V_5 = V_89 -> V_429 ( V_129 ) ;
F_34 ( F_136 ( V_5 ) ) ;
F_306 ( V_5 , V_89 , V_129 ) ;
V_71 . V_46 [ V_89 -> V_110 ] = V_129 -> V_46 [ V_89 -> V_110 ] ;
V_445 |= V_89 -> V_446 || V_89 -> exit ;
F_34 ( ! F_44 ( & V_447 . V_66 ) ) ;
V_89 -> V_448 = 1 ;
F_34 ( V_89 -> V_133 ) ;
}
int T_11 F_330 ( struct V_88 * V_89 )
{
int V_20 ;
struct V_4 * V_5 ;
if ( V_89 -> V_100 == NULL || strlen ( V_89 -> V_100 ) > V_320 ||
V_89 -> V_429 == NULL || V_89 -> V_93 == NULL )
return - V_149 ;
if ( V_89 -> V_446 || V_89 -> exit )
return - V_149 ;
if ( V_89 -> V_133 == NULL ) {
F_34 ( V_46 [ V_89 -> V_110 ] != V_89 ) ;
return 0 ;
}
F_327 ( V_89 ) ;
F_57 ( & V_1 ) ;
V_46 [ V_89 -> V_110 ] = V_89 ;
V_5 = V_89 -> V_429 ( V_129 ) ;
if ( F_136 ( V_5 ) ) {
V_46 [ V_89 -> V_110 ] = NULL ;
F_59 ( & V_1 ) ;
return F_137 ( V_5 ) ;
}
F_42 ( & V_89 -> V_130 , & V_127 . V_131 ) ;
V_89 -> V_53 = & V_127 ;
F_306 ( V_5 , V_89 , V_129 ) ;
if ( V_89 -> V_431 ) {
int V_90 = F_331 ( V_89 , V_5 ) ;
if ( V_90 ) {
V_129 -> V_46 [ V_89 -> V_110 ] = NULL ;
V_89 -> V_93 ( V_129 ) ;
V_46 [ V_89 -> V_110 ] = NULL ;
F_59 ( & V_1 ) ;
return V_90 ;
}
}
F_19 ( & V_33 ) ;
for ( V_20 = 0 ; V_20 < V_205 ; V_20 ++ ) {
struct V_26 * V_27 ;
struct V_57 * V_58 , * V_22 ;
struct V_19 * V_449 = & V_25 [ V_20 ] , * V_450 ;
F_332 (cg, node, tmp, bucket, hlist) {
if ( V_27 -> V_46 [ V_89 -> V_110 ] )
continue;
F_22 ( & V_27 -> V_34 ) ;
V_27 -> V_46 [ V_89 -> V_110 ] = V_5 ;
V_450 = F_15 ( V_27 -> V_46 ) ;
F_54 ( & V_27 -> V_34 , V_450 ) ;
}
}
F_21 ( & V_33 ) ;
V_89 -> V_448 = 1 ;
F_59 ( & V_1 ) ;
return 0 ;
}
void F_333 ( struct V_88 * V_89 )
{
struct V_29 * V_30 ;
struct V_19 * V_56 ;
F_34 ( V_89 -> V_133 == NULL ) ;
F_34 ( V_89 -> V_53 != & V_127 ) ;
F_57 ( & V_1 ) ;
V_46 [ V_89 -> V_110 ] = NULL ;
F_84 ( & V_89 -> V_130 ) ;
F_19 ( & V_33 ) ;
F_53 (link, &dummytop->css_sets, cgrp_link_list) {
struct V_26 * V_27 = V_30 -> V_27 ;
F_22 ( & V_27 -> V_34 ) ;
F_34 ( ! V_27 -> V_46 [ V_89 -> V_110 ] ) ;
V_27 -> V_46 [ V_89 -> V_110 ] = NULL ;
V_56 = F_15 ( V_27 -> V_46 ) ;
F_54 ( & V_27 -> V_34 , V_56 ) ;
}
F_21 ( & V_33 ) ;
V_89 -> V_93 ( V_129 ) ;
V_129 -> V_46 [ V_89 -> V_110 ] = NULL ;
F_59 ( & V_1 ) ;
}
int T_12 F_334 ( void )
{
int V_20 ;
F_51 ( & V_71 . V_32 , 1 ) ;
F_40 ( & V_71 . V_47 ) ;
F_40 ( & V_71 . V_66 ) ;
F_52 ( & V_71 . V_34 ) ;
V_35 = 1 ;
F_119 ( & V_127 ) ;
V_65 = 1 ;
V_447 . V_70 = & V_71 ;
V_451 . V_27 = & V_71 ;
V_451 . V_8 = V_129 ;
F_42 ( & V_451 . V_37 ,
& V_127 . V_72 . V_63 ) ;
F_42 ( & V_451 . V_36 ,
& V_71 . V_47 ) ;
for ( V_20 = 0 ; V_20 < V_205 ; V_20 ++ )
F_335 ( & V_25 [ V_20 ] ) ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( ! V_89 || V_89 -> V_133 )
continue;
F_34 ( ! V_89 -> V_100 ) ;
F_34 ( strlen ( V_89 -> V_100 ) > V_320 ) ;
F_34 ( ! V_89 -> V_429 ) ;
F_34 ( ! V_89 -> V_93 ) ;
if ( V_89 -> V_110 != V_20 ) {
F_329 ( V_452 L_30 ,
V_89 -> V_100 , V_89 -> V_110 ) ;
F_336 () ;
}
if ( V_89 -> V_453 )
F_328 ( V_89 ) ;
}
return 0 ;
}
int T_12 F_337 ( void )
{
int V_295 ;
int V_20 ;
struct V_19 * V_56 ;
V_295 = F_338 ( & V_87 ) ;
if ( V_295 )
return V_295 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( ! V_89 || V_89 -> V_133 )
continue;
if ( ! V_89 -> V_453 )
F_328 ( V_89 ) ;
if ( V_89 -> V_431 )
F_331 ( V_89 , V_71 . V_46 [ V_89 -> V_110 ] ) ;
}
V_56 = F_15 ( V_71 . V_46 ) ;
F_54 ( & V_71 . V_34 , V_56 ) ;
F_34 ( ! F_120 ( & V_127 ) ) ;
V_454 = F_339 ( L_31 , V_455 ) ;
if ( ! V_454 ) {
V_295 = - V_61 ;
goto V_231;
}
V_295 = F_340 ( & V_456 ) ;
if ( V_295 < 0 ) {
F_341 ( V_454 ) ;
goto V_231;
}
F_342 ( L_32 , 0 , NULL , & V_457 ) ;
V_231:
if ( V_295 )
F_343 ( & V_87 ) ;
return V_295 ;
}
static int F_344 ( struct V_134 * V_288 , void * V_6 )
{
struct V_243 * V_243 ;
struct V_68 * V_223 ;
char * V_207 ;
int V_227 ;
struct V_55 * V_53 ;
V_227 = - V_61 ;
V_207 = F_41 ( V_351 , V_60 ) ;
if ( ! V_207 )
goto V_231;
V_227 = - V_229 ;
V_243 = V_288 -> V_278 ;
V_223 = F_345 ( V_243 , V_458 ) ;
if ( ! V_223 )
goto V_459;
V_227 = 0 ;
F_57 ( & V_1 ) ;
F_139 (root) {
struct V_88 * V_89 ;
struct V_7 * V_8 ;
int V_38 = 0 ;
F_103 ( V_288 , L_33 , V_53 -> V_169 ) ;
F_66 (root, ss)
F_103 ( V_288 , L_34 , V_38 ++ ? L_8 : L_35 , V_89 -> V_100 ) ;
if ( strlen ( V_53 -> V_100 ) )
F_103 ( V_288 , L_36 , V_38 ? L_8 : L_35 ,
V_53 -> V_100 ) ;
F_181 ( V_288 , ':' ) ;
V_8 = F_55 ( V_223 , V_53 ) ;
V_227 = F_145 ( V_8 , V_207 , V_351 ) ;
if ( V_227 < 0 )
goto V_155;
F_104 ( V_288 , V_207 ) ;
F_181 ( V_288 , '\n' ) ;
}
V_155:
F_59 ( & V_1 ) ;
F_175 ( V_223 ) ;
V_459:
F_27 ( V_207 ) ;
V_231:
return V_227 ;
}
static int F_346 ( struct V_73 * V_73 , struct V_259 * V_259 )
{
struct V_243 * V_243 = F_347 ( V_73 ) -> V_243 ;
return F_199 ( V_259 , F_344 , V_243 ) ;
}
static int F_348 ( struct V_134 * V_288 , void * V_6 )
{
int V_20 ;
F_104 ( V_288 , L_37 ) ;
F_57 ( & V_1 ) ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 == NULL )
continue;
F_103 ( V_288 , L_38 ,
V_89 -> V_100 , V_89 -> V_53 -> V_169 ,
V_89 -> V_53 -> V_94 , ! V_89 -> V_154 ) ;
}
F_59 ( & V_1 ) ;
return 0 ;
}
static int F_349 ( struct V_73 * V_73 , struct V_259 * V_259 )
{
return F_199 ( V_259 , F_348 , NULL ) ;
}
void F_350 ( struct V_68 * V_460 )
{
F_153 ( V_156 ) ;
V_460 -> V_70 = V_156 -> V_70 ;
F_29 ( V_460 -> V_70 ) ;
F_155 ( V_156 ) ;
F_40 ( & V_460 -> V_226 ) ;
}
void F_351 ( struct V_68 * V_460 )
{
if ( V_445 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( ! V_89 || V_89 -> V_133 )
continue;
if ( V_89 -> V_446 )
V_89 -> V_446 ( V_460 ) ;
}
}
}
void F_352 ( struct V_68 * V_460 )
{
if ( V_333 ) {
F_19 ( & V_33 ) ;
F_153 ( V_460 ) ;
if ( F_44 ( & V_460 -> V_226 ) )
F_42 ( & V_460 -> V_226 , & V_460 -> V_70 -> V_66 ) ;
F_155 ( V_460 ) ;
F_21 ( & V_33 ) ;
}
}
void F_353 ( struct V_68 * V_223 , int V_461 )
{
struct V_26 * V_27 ;
int V_20 ;
if ( ! F_44 ( & V_223 -> V_226 ) ) {
F_19 ( & V_33 ) ;
if ( ! F_44 ( & V_223 -> V_226 ) )
F_84 ( & V_223 -> V_226 ) ;
F_21 ( & V_33 ) ;
}
F_153 ( V_223 ) ;
V_27 = V_223 -> V_70 ;
V_223 -> V_70 = & V_71 ;
if ( V_461 && V_445 ) {
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( ! V_89 || V_89 -> V_133 )
continue;
if ( V_89 -> exit ) {
struct V_7 * V_462 =
F_354 ( V_27 -> V_46 [ V_20 ] ) -> V_7 ;
struct V_7 * V_8 = F_355 ( V_223 , V_20 ) ;
V_89 -> exit ( V_8 , V_462 , V_223 ) ;
}
}
}
F_155 ( V_223 ) ;
if ( V_27 )
F_32 ( V_27 ) ;
}
int F_356 ( const struct V_7 * V_8 , struct V_68 * V_69 )
{
int V_90 ;
struct V_7 * V_463 ;
if ( V_8 == V_129 )
return 1 ;
V_463 = F_55 ( V_69 , V_8 -> V_53 ) ;
while ( V_8 != V_463 && V_8 != V_8 -> V_72 )
V_8 = V_8 -> V_102 ;
V_90 = ( V_8 == V_463 ) ;
return V_90 ;
}
static void F_26 ( struct V_7 * V_8 )
{
if ( F_9 ( V_8 ) && ! F_6 ( & V_8 -> V_38 )
&& F_44 ( & V_8 -> V_158 ) && ! F_310 ( V_8 ) ) {
int V_464 = 0 ;
F_323 ( & V_441 ) ;
if ( ! F_7 ( V_8 ) &&
F_44 ( & V_8 -> V_159 ) ) {
F_42 ( & V_8 -> V_159 , & V_159 ) ;
V_464 = 1 ;
}
F_324 ( & V_441 ) ;
if ( V_464 )
F_289 ( & V_465 ) ;
}
}
bool F_357 ( struct V_4 * V_5 )
{
do {
int V_6 = F_5 ( V_5 ) ;
if ( F_358 ( & V_5 -> V_2 , V_6 , V_6 + 1 ) == V_6 )
return true ;
F_359 () ;
} while ( ! F_8 ( V_438 , & V_5 -> V_10 ) );
return false ;
}
void F_360 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_7 ;
int V_6 ;
F_162 () ;
V_6 = F_4 ( F_361 ( & V_5 -> V_2 ) ) ;
switch ( V_6 ) {
case 1 :
if ( F_10 ( V_8 ) ) {
F_25 ( V_12 , & V_8 -> V_10 ) ;
F_26 ( V_8 ) ;
}
F_90 ( V_8 ) ;
break;
case 0 :
if ( ! F_8 ( V_428 , & V_5 -> V_10 ) )
F_289 ( & V_5 -> V_425 ) ;
break;
}
F_168 () ;
}
static void F_362 ( struct V_402 * V_403 )
{
F_34 ( V_403 != & V_465 ) ;
F_57 ( & V_1 ) ;
F_323 ( & V_441 ) ;
while ( ! F_44 ( & V_159 ) ) {
char * V_466 [ 3 ] , * V_467 [ 3 ] ;
int V_20 ;
char * V_468 = NULL , * V_469 = NULL ;
struct V_7 * V_8 = F_35 ( V_159 . V_52 ,
struct V_7 ,
V_159 ) ;
F_84 ( & V_8 -> V_159 ) ;
F_324 ( & V_441 ) ;
V_468 = F_41 ( V_351 , V_60 ) ;
if ( ! V_468 )
goto V_470;
if ( F_145 ( V_8 , V_468 , V_351 ) < 0 )
goto V_470;
V_469 = F_363 ( V_8 -> V_53 -> V_138 , V_60 ) ;
if ( ! V_469 )
goto V_470;
V_20 = 0 ;
V_466 [ V_20 ++ ] = V_469 ;
V_466 [ V_20 ++ ] = V_468 ;
V_466 [ V_20 ] = NULL ;
V_20 = 0 ;
V_467 [ V_20 ++ ] = L_39 ;
V_467 [ V_20 ++ ] = L_40 ;
V_467 [ V_20 ] = NULL ;
F_59 ( & V_1 ) ;
F_364 ( V_466 [ 0 ] , V_466 , V_467 , V_471 ) ;
F_57 ( & V_1 ) ;
V_470:
F_27 ( V_468 ) ;
F_27 ( V_469 ) ;
F_323 ( & V_441 ) ;
}
F_324 ( & V_441 ) ;
F_59 ( & V_1 ) ;
}
static int T_12 F_365 ( char * V_472 )
{
int V_20 ;
char * V_142 ;
while ( ( V_142 = F_107 ( & V_472 , L_8 ) ) != NULL ) {
if ( ! * V_142 )
continue;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( ! V_89 || V_89 -> V_133 )
continue;
if ( ! strcmp ( V_142 , V_89 -> V_100 ) ) {
V_89 -> V_154 = 1 ;
F_329 ( V_444 L_41
L_42 , V_89 -> V_100 ) ;
break;
}
}
}
return 1 ;
}
unsigned short F_366 ( struct V_4 * V_5 )
{
struct F_366 * V_473 ;
V_473 = F_146 ( V_5 -> V_424 , F_5 ( V_5 ) ) ;
if ( V_473 )
return V_473 -> V_424 ;
return 0 ;
}
unsigned short F_367 ( struct V_4 * V_5 )
{
struct F_366 * V_473 ;
V_473 = F_146 ( V_5 -> V_424 , F_5 ( V_5 ) ) ;
if ( V_473 )
return V_473 -> V_474 ;
return 0 ;
}
bool F_368 ( struct V_4 * V_460 ,
const struct V_4 * V_53 )
{
struct F_366 * V_475 ;
struct F_366 * V_476 ;
V_475 = F_369 ( V_460 -> V_424 ) ;
if ( ! V_475 )
return false ;
V_476 = F_369 ( V_53 -> V_424 ) ;
if ( ! V_476 )
return false ;
if ( V_475 -> V_474 < V_476 -> V_474 )
return false ;
if ( V_475 -> V_477 [ V_476 -> V_474 ] != V_476 -> V_424 )
return false ;
return true ;
}
void F_370 ( struct V_88 * V_89 , struct V_4 * V_5 )
{
struct F_366 * V_424 = V_5 -> V_424 ;
if ( ! V_424 )
return;
F_34 ( ! V_89 -> V_431 ) ;
F_154 ( V_424 -> V_5 , NULL ) ;
F_154 ( V_5 -> V_424 , NULL ) ;
F_87 ( & V_89 -> V_478 ) ;
F_371 ( & V_89 -> V_479 , V_424 -> V_424 ) ;
F_89 ( & V_89 -> V_478 ) ;
F_28 ( V_424 , V_39 ) ;
}
static struct F_366 * F_372 ( struct V_88 * V_89 , int V_474 )
{
struct F_366 * V_480 ;
int V_481 , error , V_313 ;
F_34 ( ! V_89 -> V_431 ) ;
V_313 = sizeof( * V_480 ) + sizeof( unsigned short ) * ( V_474 + 1 ) ;
V_480 = F_126 ( V_313 , V_60 ) ;
if ( ! V_480 )
return F_127 ( - V_61 ) ;
if ( F_91 ( ! F_373 ( & V_89 -> V_479 , V_60 ) ) ) {
error = - V_61 ;
goto V_482;
}
F_87 ( & V_89 -> V_478 ) ;
error = F_374 ( & V_89 -> V_479 , V_480 , 1 , & V_481 ) ;
F_89 ( & V_89 -> V_478 ) ;
if ( error ) {
error = - V_170 ;
goto V_482;
}
if ( V_481 > V_483 )
goto V_484;
V_480 -> V_424 = V_481 ;
V_480 -> V_474 = V_474 ;
return V_480 ;
V_484:
error = - V_170 ;
F_87 ( & V_89 -> V_478 ) ;
F_371 ( & V_89 -> V_479 , V_481 ) ;
F_89 ( & V_89 -> V_478 ) ;
V_482:
F_27 ( V_480 ) ;
return F_127 ( error ) ;
}
static int T_11 F_331 ( struct V_88 * V_89 ,
struct V_4 * V_485 )
{
struct F_366 * V_480 ;
F_117 ( & V_89 -> V_478 ) ;
F_375 ( & V_89 -> V_479 ) ;
V_480 = F_372 ( V_89 , 0 ) ;
if ( F_136 ( V_480 ) )
return F_137 ( V_480 ) ;
V_480 -> V_477 [ 0 ] = V_480 -> V_424 ;
V_480 -> V_5 = V_485 ;
V_485 -> V_424 = V_480 ;
return 0 ;
}
static int F_308 ( struct V_88 * V_89 , struct V_7 * V_102 ,
struct V_7 * V_460 )
{
int V_110 , V_20 , V_474 = 0 ;
struct V_4 * V_486 , * V_487 ;
struct F_366 * V_475 , * V_488 ;
V_110 = V_89 -> V_110 ;
V_486 = V_102 -> V_46 [ V_110 ] ;
V_487 = V_460 -> V_46 [ V_110 ] ;
V_488 = V_486 -> V_424 ;
V_474 = V_488 -> V_474 + 1 ;
V_475 = F_372 ( V_89 , V_474 ) ;
if ( F_136 ( V_475 ) )
return F_137 ( V_475 ) ;
for ( V_20 = 0 ; V_20 < V_474 ; V_20 ++ )
V_475 -> V_477 [ V_20 ] = V_488 -> V_477 [ V_20 ] ;
V_475 -> V_477 [ V_474 ] = V_475 -> V_424 ;
F_154 ( V_487 -> V_424 , V_475 ) ;
return 0 ;
}
struct V_4 * F_376 ( struct V_88 * V_89 , int V_424 )
{
struct F_366 * V_473 = NULL ;
F_34 ( ! V_89 -> V_431 ) ;
V_473 = F_377 ( & V_89 -> V_479 , V_424 ) ;
if ( F_91 ( ! V_473 ) )
return NULL ;
return F_369 ( V_473 -> V_5 ) ;
}
struct V_4 *
F_378 ( struct V_88 * V_89 , int V_424 ,
struct V_4 * V_53 , int * V_489 )
{
struct V_4 * V_90 = NULL ;
struct F_366 * V_22 ;
int V_490 ;
int V_491 = F_366 ( V_53 ) ;
int V_474 = F_367 ( V_53 ) ;
if ( ! V_491 )
return NULL ;
F_34 ( ! V_89 -> V_431 ) ;
F_67 ( ! F_379 () ) ;
V_490 = V_424 ;
while ( 1 ) {
V_22 = F_380 ( & V_89 -> V_479 , & V_490 ) ;
if ( ! V_22 )
break;
if ( V_22 -> V_474 >= V_474 && V_22 -> V_477 [ V_474 ] == V_491 ) {
V_90 = F_369 ( V_22 -> V_5 ) ;
if ( V_90 ) {
* V_489 = V_490 ;
break;
}
}
V_490 = V_490 + 1 ;
}
return V_90 ;
}
struct V_4 * F_381 ( struct V_259 * V_492 , int V_424 )
{
struct V_7 * V_8 ;
struct V_73 * V_73 ;
struct V_4 * V_5 ;
V_73 = V_492 -> V_275 -> V_103 ;
if ( V_73 -> V_190 != & V_191 )
return F_127 ( - V_419 ) ;
if ( V_424 < 0 || V_424 >= V_23 )
return F_127 ( - V_149 ) ;
V_8 = F_12 ( V_492 -> V_275 ) ;
V_5 = V_8 -> V_46 [ V_424 ] ;
return V_5 ? V_5 : F_127 ( - V_105 ) ;
}
static struct V_4 * F_382 ( struct V_7 * V_493 )
{
struct V_4 * V_5 = F_126 ( sizeof( * V_5 ) , V_60 ) ;
if ( ! V_5 )
return F_127 ( - V_61 ) ;
return V_5 ;
}
static void F_383 ( struct V_7 * V_493 )
{
F_27 ( V_493 -> V_46 [ V_494 ] ) ;
}
static T_2 F_384 ( struct V_7 * V_493 , struct V_18 * V_99 )
{
return F_6 ( & V_493 -> V_38 ) ;
}
static T_2 F_385 ( struct V_7 * V_493 , struct V_18 * V_99 )
{
return F_230 ( V_493 ) ;
}
static T_2 F_386 ( struct V_7 * V_493 , struct V_18 * V_99 )
{
return ( T_2 ) ( unsigned long ) V_156 -> V_70 ;
}
static T_2 F_387 ( struct V_7 * V_493 ,
struct V_18 * V_99 )
{
T_2 V_38 ;
F_162 () ;
V_38 = F_6 ( & V_156 -> V_70 -> V_32 ) ;
F_168 () ;
return V_38 ;
}
static int F_388 ( struct V_7 * V_493 ,
struct V_18 * V_99 ,
struct V_134 * V_135 )
{
struct V_29 * V_30 ;
struct V_26 * V_27 ;
F_49 ( & V_33 ) ;
F_162 () ;
V_27 = F_369 ( V_156 -> V_70 ) ;
F_53 (link, &cg->cg_links, cg_link_list) {
struct V_7 * V_67 = V_30 -> V_8 ;
const char * V_100 ;
if ( V_67 -> V_15 )
V_100 = V_67 -> V_15 -> V_211 . V_100 ;
else
V_100 = L_43 ;
F_103 ( V_135 , L_44 ,
V_67 -> V_53 -> V_169 , V_100 ) ;
}
F_168 () ;
F_50 ( & V_33 ) ;
return 0 ;
}
static int F_389 ( struct V_7 * V_493 ,
struct V_18 * V_99 ,
struct V_134 * V_135 )
{
struct V_29 * V_30 ;
F_49 ( & V_33 ) ;
F_53 (link, &cont->css_sets, cgrp_link_list) {
struct V_26 * V_27 = V_30 -> V_27 ;
struct V_68 * V_69 ;
int V_38 = 0 ;
F_103 ( V_135 , L_45 , V_27 ) ;
F_53 (task, &cg->tasks, cg_list) {
if ( V_38 ++ > V_495 ) {
F_104 ( V_135 , L_46 ) ;
break;
} else {
F_103 ( V_135 , L_47 ,
F_262 ( V_69 ) ) ;
}
}
}
F_50 ( & V_33 ) ;
return 0 ;
}
static T_2 F_390 ( struct V_7 * V_8 , struct V_18 * V_99 )
{
return F_8 ( V_12 , & V_8 -> V_10 ) ;
}
