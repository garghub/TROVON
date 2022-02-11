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
static inline struct V_7 * F_11 ( struct V_14 * V_14 )
{
return V_14 -> V_15 ;
}
static inline struct V_16 * F_12 ( struct V_14 * V_14 )
{
return V_14 -> V_15 ;
}
static inline struct V_17 * F_13 ( struct V_14 * V_14 )
{
return F_12 ( V_14 ) -> type ;
}
static unsigned long F_14 ( struct V_4 * V_5 [] )
{
int V_18 ;
unsigned long V_19 = 0UL ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ )
V_19 += ( unsigned long ) V_5 [ V_18 ] ;
V_19 = ( V_19 >> 16 ) ^ V_19 ;
return V_19 ;
}
static void F_15 ( struct V_21 * V_22 , int V_23 )
{
struct V_24 * V_25 ;
struct V_24 * V_26 ;
if ( F_16 ( & V_22 -> V_27 , - 1 , 1 ) )
return;
F_17 ( & V_28 ) ;
if ( ! F_18 ( & V_22 -> V_27 ) ) {
F_19 ( & V_28 ) ;
return;
}
F_20 ( & V_22 -> V_29 ) ;
V_30 -- ;
F_21 (link, saved_link, &cg->cg_links,
cg_link_list) {
struct V_7 * V_8 = V_25 -> V_8 ;
F_22 ( & V_25 -> V_31 ) ;
F_22 ( & V_25 -> V_32 ) ;
F_23 () ;
if ( F_18 ( & V_8 -> V_33 ) &&
F_10 ( V_8 ) ) {
if ( V_23 )
F_24 ( V_12 , & V_8 -> V_10 ) ;
F_25 ( V_8 ) ;
}
F_26 () ;
F_27 ( V_25 ) ;
}
F_19 ( & V_28 ) ;
F_28 ( V_22 , V_34 ) ;
}
static inline void F_29 ( struct V_21 * V_22 )
{
F_30 ( & V_22 -> V_27 ) ;
}
static inline void F_31 ( struct V_21 * V_22 )
{
F_15 ( V_22 , 0 ) ;
}
static inline void F_32 ( struct V_21 * V_22 )
{
F_15 ( V_22 , 1 ) ;
}
static bool F_33 ( struct V_21 * V_22 ,
struct V_21 * V_35 ,
struct V_7 * V_36 ,
struct V_4 * V_37 [] )
{
struct V_38 * V_39 , * V_40 ;
if ( memcmp ( V_37 , V_22 -> V_41 , sizeof( V_22 -> V_41 ) ) ) {
return false ;
}
V_39 = & V_22 -> V_42 ;
V_40 = & V_35 -> V_42 ;
while ( 1 ) {
struct V_24 * V_43 , * V_44 ;
struct V_7 * V_45 , * V_46 ;
V_39 = V_39 -> V_47 ;
V_40 = V_40 -> V_47 ;
if ( V_39 == & V_22 -> V_42 ) {
F_34 ( V_40 != & V_35 -> V_42 ) ;
break;
} else {
F_34 ( V_40 == & V_35 -> V_42 ) ;
}
V_43 = F_35 ( V_39 , struct V_24 , V_31 ) ;
V_44 = F_35 ( V_40 , struct V_24 , V_31 ) ;
V_45 = V_43 -> V_8 ;
V_46 = V_44 -> V_8 ;
F_34 ( V_45 -> V_48 != V_46 -> V_48 ) ;
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
static struct V_21 * F_36 (
struct V_21 * V_49 ,
struct V_7 * V_8 ,
struct V_4 * V_37 [] )
{
int V_18 ;
struct V_50 * V_48 = V_8 -> V_48 ;
struct V_21 * V_22 ;
unsigned long V_19 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
if ( V_48 -> V_51 & ( 1UL << V_18 ) ) {
V_37 [ V_18 ] = V_8 -> V_41 [ V_18 ] ;
} else {
V_37 [ V_18 ] = V_49 -> V_41 [ V_18 ] ;
}
}
V_19 = F_14 ( V_37 ) ;
F_37 (css_set_table, cg, hlist, key) {
if ( ! F_33 ( V_22 , V_49 , V_8 , V_37 ) )
continue;
return V_22 ;
}
return NULL ;
}
static void F_38 ( struct V_38 * V_52 )
{
struct V_24 * V_25 ;
struct V_24 * V_26 ;
F_21 (link, saved_link, tmp, cgrp_link_list) {
F_22 ( & V_25 -> V_32 ) ;
F_27 ( V_25 ) ;
}
}
static int F_39 ( int V_33 , struct V_38 * V_52 )
{
struct V_24 * V_25 ;
int V_18 ;
F_40 ( V_52 ) ;
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
V_25 = F_41 ( sizeof( * V_25 ) , V_53 ) ;
if ( ! V_25 ) {
F_38 ( V_52 ) ;
return - V_54 ;
}
F_42 ( & V_25 -> V_32 , V_52 ) ;
}
return 0 ;
}
static void F_43 ( struct V_38 * V_55 ,
struct V_21 * V_22 , struct V_7 * V_8 )
{
struct V_24 * V_25 ;
F_34 ( F_44 ( V_55 ) ) ;
V_25 = F_45 ( V_55 , struct V_24 ,
V_32 ) ;
V_25 -> V_22 = V_22 ;
V_25 -> V_8 = V_8 ;
F_30 ( & V_8 -> V_33 ) ;
F_46 ( & V_25 -> V_32 , & V_8 -> V_56 ) ;
F_47 ( & V_25 -> V_31 , & V_22 -> V_42 ) ;
}
static struct V_21 * F_48 (
struct V_21 * V_49 , struct V_7 * V_8 )
{
struct V_21 * V_57 ;
struct V_4 * V_37 [ V_20 ] ;
struct V_38 V_55 ;
struct V_24 * V_25 ;
unsigned long V_19 ;
F_49 ( & V_28 ) ;
V_57 = F_36 ( V_49 , V_8 , V_37 ) ;
if ( V_57 )
F_29 ( V_57 ) ;
F_50 ( & V_28 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_41 ( sizeof( * V_57 ) , V_53 ) ;
if ( ! V_57 )
return NULL ;
if ( F_39 ( V_58 , & V_55 ) < 0 ) {
F_27 ( V_57 ) ;
return NULL ;
}
F_51 ( & V_57 -> V_27 , 1 ) ;
F_40 ( & V_57 -> V_42 ) ;
F_40 ( & V_57 -> V_59 ) ;
F_52 ( & V_57 -> V_29 ) ;
memcpy ( V_57 -> V_41 , V_37 , sizeof( V_57 -> V_41 ) ) ;
F_17 ( & V_28 ) ;
F_53 (link, &oldcg->cg_links, cg_link_list) {
struct V_7 * V_60 = V_25 -> V_8 ;
if ( V_60 -> V_48 == V_8 -> V_48 )
V_60 = V_8 ;
F_43 ( & V_55 , V_57 , V_60 ) ;
}
F_34 ( ! F_44 ( & V_55 ) ) ;
V_30 ++ ;
V_19 = F_14 ( V_57 -> V_41 ) ;
F_54 ( V_61 , & V_57 -> V_29 , V_19 ) ;
F_19 ( & V_28 ) ;
return V_57 ;
}
static struct V_7 * F_55 ( struct V_62 * V_63 ,
struct V_50 * V_48 )
{
struct V_21 * V_5 ;
struct V_7 * V_57 = NULL ;
F_34 ( ! F_3 ( & V_1 ) ) ;
F_49 ( & V_28 ) ;
V_5 = V_63 -> V_64 ;
if ( V_5 == & V_65 ) {
V_57 = & V_48 -> V_66 ;
} else {
struct V_24 * V_25 ;
F_53 (link, &css->cg_links, cg_link_list) {
struct V_7 * V_60 = V_25 -> V_8 ;
if ( V_60 -> V_48 == V_48 ) {
V_57 = V_60 ;
break;
}
}
}
F_50 ( & V_28 ) ;
F_34 ( ! V_57 ) ;
return V_57 ;
}
void F_56 ( void )
{
F_57 ( & V_1 ) ;
}
void F_58 ( void )
{
F_59 ( & V_1 ) ;
}
static struct V_67 * F_60 ( T_1 V_68 , struct V_69 * V_70 )
{
struct V_67 * V_67 = F_61 ( V_70 ) ;
if ( V_67 ) {
V_67 -> V_71 = F_62 () ;
V_67 -> V_72 = V_68 ;
V_67 -> V_73 = F_63 () ;
V_67 -> V_74 = F_64 () ;
V_67 -> V_75 = V_67 -> V_76 = V_67 -> V_77 = V_78 ;
V_67 -> V_79 -> V_80 = & V_81 ;
}
return V_67 ;
}
static void F_65 ( struct V_82 * V_83 )
{
struct V_7 * V_8 = F_66 ( V_83 , struct V_7 , V_84 ) ;
struct V_85 * V_86 ;
F_57 ( & V_1 ) ;
F_67 (cgrp->root, ss)
V_86 -> V_87 ( V_8 ) ;
V_8 -> V_48 -> V_88 -- ;
F_59 ( & V_1 ) ;
F_68 ( V_8 -> V_48 -> V_70 ) ;
F_34 ( ! F_44 ( & V_8 -> V_89 ) ) ;
F_69 ( & V_8 -> V_90 ) ;
F_70 ( & V_8 -> V_48 -> V_91 , V_8 -> V_92 ) ;
F_27 ( V_8 ) ;
}
static void F_71 ( struct V_34 * V_93 )
{
struct V_7 * V_8 = F_66 ( V_93 , struct V_7 , V_34 ) ;
F_72 ( & V_8 -> V_84 ) ;
}
static void F_73 ( struct V_14 * V_14 , struct V_67 * V_67 )
{
if ( F_74 ( V_67 -> V_72 ) ) {
struct V_7 * V_8 = V_14 -> V_15 ;
F_34 ( ! ( F_7 ( V_8 ) ) ) ;
F_75 ( & V_8 -> V_34 , F_71 ) ;
} else {
struct V_16 * V_94 = F_12 ( V_14 ) ;
struct V_7 * V_8 = V_14 -> V_95 -> V_15 ;
struct V_17 * V_96 = V_94 -> type ;
F_76 ( ! F_44 ( & V_94 -> V_97 ) &&
V_8 != & V_8 -> V_48 -> V_66 ,
L_1 , V_94 -> type -> V_98 ) ;
F_27 ( V_94 ) ;
F_69 ( & V_96 -> V_90 ) ;
}
F_77 ( V_67 ) ;
}
static int F_78 ( const struct V_14 * V_99 )
{
return 1 ;
}
static void F_79 ( struct V_14 * V_99 )
{
struct V_14 * V_100 = F_80 ( V_99 -> V_95 ) ;
F_81 ( V_99 ) ;
F_82 ( V_100 -> V_101 , V_99 ) ;
F_83 ( V_100 ) ;
}
static void F_84 ( struct V_7 * V_8 , const struct V_17 * V_96 )
{
struct V_16 * V_94 ;
F_85 ( & V_8 -> V_14 -> V_101 -> V_102 ) ;
F_85 ( & V_1 ) ;
F_53 (cfe, &cgrp->files, node) {
struct V_14 * V_99 = V_94 -> V_14 ;
if ( V_96 && V_94 -> type != V_96 )
continue;
F_80 ( V_99 ) ;
F_81 ( V_99 ) ;
F_86 ( V_8 -> V_14 -> V_101 , V_99 ) ;
F_87 ( & V_94 -> V_97 ) ;
F_83 ( V_99 ) ;
break;
}
}
static void F_88 ( struct V_14 * V_103 , bool V_104 ,
unsigned long V_51 )
{
struct V_7 * V_8 = F_11 ( V_103 ) ;
struct V_85 * V_86 ;
F_67 (cgrp->root, ss) {
struct V_105 * V_106 ;
if ( ! F_8 ( V_86 -> V_107 , & V_51 ) )
continue;
F_53 (set, &ss->cftsets, node)
F_89 ( V_8 , NULL , V_106 -> V_108 , false ) ;
}
if ( V_104 ) {
while ( ! F_44 ( & V_8 -> V_109 ) )
F_84 ( V_8 , NULL ) ;
}
}
static void F_90 ( struct V_14 * V_14 )
{
struct V_14 * V_100 ;
struct V_50 * V_48 = V_14 -> V_110 -> V_111 ;
F_88 ( V_14 , true , V_48 -> V_51 ) ;
V_100 = V_14 -> V_95 ;
F_91 ( & V_100 -> V_112 ) ;
F_92 ( & V_14 -> V_112 , V_113 ) ;
F_87 ( & V_14 -> V_114 . V_115 ) ;
F_93 ( & V_14 -> V_112 ) ;
F_93 ( & V_100 -> V_112 ) ;
F_79 ( V_14 ) ;
}
static int F_94 ( struct V_50 * V_48 ,
unsigned long V_116 )
{
unsigned long V_117 , V_118 ;
struct V_7 * V_8 = & V_48 -> V_66 ;
int V_18 ;
F_34 ( ! F_3 ( & V_1 ) ) ;
F_34 ( ! F_3 ( & V_119 ) ) ;
V_118 = V_48 -> V_120 & ~ V_116 ;
V_117 = V_116 & ~ V_48 -> V_120 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
unsigned long V_121 = 1UL << V_18 ;
struct V_85 * V_86 = V_41 [ V_18 ] ;
if ( ! ( V_121 & V_117 ) )
continue;
F_34 ( V_86 == NULL ) ;
if ( V_86 -> V_48 != & V_122 ) {
return - V_123 ;
}
}
if ( V_48 -> V_88 > 1 )
return - V_123 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_85 * V_86 = V_41 [ V_18 ] ;
unsigned long V_121 = 1UL << V_18 ;
if ( V_121 & V_117 ) {
F_34 ( V_86 == NULL ) ;
F_34 ( V_8 -> V_41 [ V_18 ] ) ;
F_34 ( ! V_124 -> V_41 [ V_18 ] ) ;
F_34 ( V_124 -> V_41 [ V_18 ] -> V_7 != V_124 ) ;
V_8 -> V_41 [ V_18 ] = V_124 -> V_41 [ V_18 ] ;
V_8 -> V_41 [ V_18 ] -> V_7 = V_8 ;
F_46 ( & V_86 -> V_125 , & V_48 -> V_126 ) ;
V_86 -> V_48 = V_48 ;
if ( V_86 -> V_127 )
V_86 -> V_127 ( V_8 ) ;
} else if ( V_121 & V_118 ) {
F_34 ( V_86 == NULL ) ;
F_34 ( V_8 -> V_41 [ V_18 ] != V_124 -> V_41 [ V_18 ] ) ;
F_34 ( V_8 -> V_41 [ V_18 ] -> V_7 != V_8 ) ;
if ( V_86 -> V_127 )
V_86 -> V_127 ( V_124 ) ;
V_124 -> V_41 [ V_18 ] -> V_7 = V_124 ;
V_8 -> V_41 [ V_18 ] = NULL ;
V_41 [ V_18 ] -> V_48 = & V_122 ;
F_46 ( & V_86 -> V_125 , & V_122 . V_126 ) ;
F_95 ( V_86 -> V_128 ) ;
} else if ( V_121 & V_116 ) {
F_34 ( V_86 == NULL ) ;
F_34 ( ! V_8 -> V_41 [ V_18 ] ) ;
F_95 ( V_86 -> V_128 ) ;
#ifdef F_96
F_34 ( V_86 -> V_128 && ! F_97 ( V_86 -> V_128 ) ) ;
#endif
} else {
F_34 ( V_8 -> V_41 [ V_18 ] ) ;
}
}
V_48 -> V_51 = V_48 -> V_120 = V_116 ;
return 0 ;
}
static int F_98 ( struct V_129 * V_130 , struct V_14 * V_14 )
{
struct V_50 * V_48 = V_14 -> V_110 -> V_111 ;
struct V_85 * V_86 ;
F_57 ( & V_119 ) ;
F_67 (root, ss)
F_99 ( V_130 , L_2 , V_86 -> V_98 ) ;
if ( F_8 ( V_131 , & V_48 -> V_10 ) )
F_100 ( V_130 , L_3 ) ;
if ( F_8 ( V_132 , & V_48 -> V_10 ) )
F_100 ( V_130 , L_4 ) ;
if ( strlen ( V_48 -> V_133 ) )
F_99 ( V_130 , L_5 , V_48 -> V_133 ) ;
if ( F_8 ( V_134 , & V_48 -> V_66 . V_10 ) )
F_100 ( V_130 , L_6 ) ;
if ( strlen ( V_48 -> V_98 ) )
F_99 ( V_130 , L_7 , V_48 -> V_98 ) ;
F_59 ( & V_119 ) ;
return 0 ;
}
static int F_101 ( char * V_135 , struct V_136 * V_137 )
{
char * V_138 , * V_139 = V_135 ;
bool V_140 = false , V_141 = false ;
unsigned long V_142 = ( unsigned long ) - 1 ;
int V_18 ;
bool V_143 = false ;
F_34 ( ! F_3 ( & V_1 ) ) ;
#ifdef F_102
V_142 = ~ ( 1UL << V_144 ) ;
#endif
memset ( V_137 , 0 , sizeof( * V_137 ) ) ;
while ( ( V_138 = F_103 ( & V_139 , L_8 ) ) != NULL ) {
if ( ! * V_138 )
return - V_145 ;
if ( ! strcmp ( V_138 , L_9 ) ) {
V_137 -> V_146 = true ;
continue;
}
if ( ! strcmp ( V_138 , L_10 ) ) {
if ( V_141 )
return - V_145 ;
V_140 = true ;
continue;
}
if ( ! strcmp ( V_138 , L_11 ) ) {
F_24 ( V_131 , & V_137 -> V_10 ) ;
continue;
}
if ( ! strcmp ( V_138 , L_12 ) ) {
V_137 -> V_147 = true ;
continue;
}
if ( ! strcmp ( V_138 , L_13 ) ) {
F_24 ( V_132 , & V_137 -> V_10 ) ;
continue;
}
if ( ! strncmp ( V_138 , L_14 , 14 ) ) {
if ( V_137 -> V_148 )
return - V_145 ;
V_137 -> V_148 =
F_104 ( V_138 + 14 , V_149 - 1 , V_53 ) ;
if ( ! V_137 -> V_148 )
return - V_54 ;
continue;
}
if ( ! strncmp ( V_138 , L_15 , 5 ) ) {
const char * V_98 = V_138 + 5 ;
if ( ! strlen ( V_98 ) )
return - V_145 ;
for ( V_18 = 0 ; V_18 < strlen ( V_98 ) ; V_18 ++ ) {
char V_60 = V_98 [ V_18 ] ;
if ( isalnum ( V_60 ) )
continue;
if ( ( V_60 == '.' ) || ( V_60 == '-' ) || ( V_60 == '_' ) )
continue;
return - V_145 ;
}
if ( V_137 -> V_98 )
return - V_145 ;
V_137 -> V_98 = F_104 ( V_98 ,
V_150 - 1 ,
V_53 ) ;
if ( ! V_137 -> V_98 )
return - V_54 ;
continue;
}
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_85 * V_86 = V_41 [ V_18 ] ;
if ( V_86 == NULL )
continue;
if ( strcmp ( V_138 , V_86 -> V_98 ) )
continue;
if ( V_86 -> V_151 )
continue;
if ( V_140 )
return - V_145 ;
F_24 ( V_18 , & V_137 -> V_51 ) ;
V_141 = true ;
break;
}
if ( V_18 == V_20 )
return - V_152 ;
}
if ( V_140 || ( ! V_141 && ! V_137 -> V_146 && ! V_137 -> V_98 ) ) {
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_85 * V_86 = V_41 [ V_18 ] ;
if ( V_86 == NULL )
continue;
if ( V_86 -> V_151 )
continue;
F_24 ( V_18 , & V_137 -> V_51 ) ;
}
}
if ( F_8 ( V_131 , & V_137 -> V_10 ) &&
( V_137 -> V_51 & V_142 ) )
return - V_145 ;
if ( V_137 -> V_51 && V_137 -> V_146 )
return - V_145 ;
if ( ! V_137 -> V_51 && ! V_137 -> V_98 )
return - V_145 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
unsigned long V_121 = 1UL << V_18 ;
if ( ! ( V_121 & V_137 -> V_51 ) )
continue;
if ( ! F_105 ( V_41 [ V_18 ] -> V_128 ) ) {
V_143 = true ;
break;
}
}
if ( V_143 ) {
for ( V_18 -- ; V_18 >= 0 ; V_18 -- ) {
unsigned long V_121 = 1UL << V_18 ;
if ( ! ( V_121 & V_137 -> V_51 ) )
continue;
F_95 ( V_41 [ V_18 ] -> V_128 ) ;
}
return - V_152 ;
}
return 0 ;
}
static void F_106 ( unsigned long V_51 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
unsigned long V_121 = 1UL << V_18 ;
if ( ! ( V_121 & V_51 ) )
continue;
F_95 ( V_41 [ V_18 ] -> V_128 ) ;
}
}
static int F_107 ( struct V_69 * V_70 , int * V_10 , char * V_135 )
{
int V_153 = 0 ;
struct V_50 * V_48 = V_70 -> V_111 ;
struct V_7 * V_8 = & V_48 -> V_66 ;
struct V_136 V_137 ;
unsigned long V_117 , V_118 ;
F_57 ( & V_8 -> V_14 -> V_101 -> V_102 ) ;
F_57 ( & V_1 ) ;
F_57 ( & V_119 ) ;
V_153 = F_101 ( V_135 , & V_137 ) ;
if ( V_153 )
goto V_154;
if ( V_137 . V_51 != V_48 -> V_120 || V_137 . V_148 )
F_108 ( L_16 ,
F_109 ( V_155 ) , V_155 -> V_156 ) ;
V_117 = V_137 . V_51 & ~ V_48 -> V_51 ;
V_118 = V_48 -> V_51 & ~ V_137 . V_51 ;
if ( V_137 . V_10 != V_48 -> V_10 ||
( V_137 . V_98 && strcmp ( V_137 . V_98 , V_48 -> V_98 ) ) ) {
V_153 = - V_145 ;
F_106 ( V_137 . V_51 ) ;
goto V_154;
}
F_88 ( V_8 -> V_14 , false , V_118 ) ;
V_153 = F_94 ( V_48 , V_137 . V_51 ) ;
if ( V_153 ) {
F_110 ( V_8 , false , V_118 ) ;
F_106 ( V_137 . V_51 ) ;
goto V_154;
}
F_110 ( V_8 , false , V_117 ) ;
if ( V_137 . V_148 )
strcpy ( V_48 -> V_133 , V_137 . V_148 ) ;
V_154:
F_27 ( V_137 . V_148 ) ;
F_27 ( V_137 . V_98 ) ;
F_59 ( & V_119 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_8 -> V_14 -> V_101 -> V_102 ) ;
return V_153 ;
}
static void F_111 ( struct V_7 * V_8 )
{
F_40 ( & V_8 -> V_125 ) ;
F_40 ( & V_8 -> V_157 ) ;
F_40 ( & V_8 -> V_109 ) ;
F_40 ( & V_8 -> V_56 ) ;
F_40 ( & V_8 -> V_158 ) ;
F_40 ( & V_8 -> V_159 ) ;
F_40 ( & V_8 -> V_89 ) ;
F_112 ( & V_8 -> V_84 , F_65 ) ;
F_113 ( & V_8 -> V_160 ) ;
F_40 ( & V_8 -> V_161 ) ;
F_114 ( & V_8 -> V_162 ) ;
F_115 ( & V_8 -> V_90 ) ;
}
static void F_116 ( struct V_50 * V_48 )
{
struct V_7 * V_8 = & V_48 -> V_66 ;
F_40 ( & V_48 -> V_126 ) ;
F_40 ( & V_48 -> V_163 ) ;
F_40 ( & V_48 -> V_164 ) ;
V_48 -> V_88 = 1 ;
V_8 -> V_48 = V_48 ;
V_8 -> V_66 = V_8 ;
F_111 ( V_8 ) ;
F_47 ( & V_8 -> V_158 , & V_48 -> V_164 ) ;
}
static bool F_117 ( struct V_50 * V_48 )
{
int V_153 = 0 ;
do {
if ( ! F_118 ( & V_165 , V_53 ) )
return false ;
F_91 ( & V_166 ) ;
V_153 = F_119 ( & V_165 , V_167 ,
& V_48 -> V_168 ) ;
if ( V_153 == - V_169 )
V_153 = F_120 ( & V_165 , & V_48 -> V_168 ) ;
if ( ! V_153 ) {
V_167 = V_48 -> V_168 + 1 ;
} else if ( V_153 != - V_170 ) {
F_34 ( V_153 ) ;
}
F_93 ( & V_166 ) ;
} while ( V_153 );
return true ;
}
static int F_121 ( struct V_69 * V_70 , void * V_135 )
{
struct V_136 * V_137 = V_135 ;
struct V_50 * V_48 = V_70 -> V_111 ;
if ( V_137 -> V_98 && strcmp ( V_137 -> V_98 , V_48 -> V_98 ) )
return 0 ;
if ( ( V_137 -> V_51 || V_137 -> V_146 )
&& ( V_137 -> V_51 != V_48 -> V_51 ) )
return 0 ;
return 1 ;
}
static struct V_50 * F_122 ( struct V_136 * V_137 )
{
struct V_50 * V_48 ;
if ( ! V_137 -> V_51 && ! V_137 -> V_146 )
return NULL ;
V_48 = F_123 ( sizeof( * V_48 ) , V_53 ) ;
if ( ! V_48 )
return F_124 ( - V_54 ) ;
if ( ! F_117 ( V_48 ) ) {
F_27 ( V_48 ) ;
return F_124 ( - V_54 ) ;
}
F_116 ( V_48 ) ;
V_48 -> V_51 = V_137 -> V_51 ;
V_48 -> V_10 = V_137 -> V_10 ;
F_125 ( & V_48 -> V_91 ) ;
if ( V_137 -> V_148 )
strcpy ( V_48 -> V_133 , V_137 -> V_148 ) ;
if ( V_137 -> V_98 )
strcpy ( V_48 -> V_98 , V_137 -> V_98 ) ;
if ( V_137 -> V_147 )
F_24 ( V_134 , & V_48 -> V_66 . V_10 ) ;
return V_48 ;
}
static void F_126 ( struct V_50 * V_48 )
{
if ( ! V_48 )
return;
F_34 ( ! V_48 -> V_168 ) ;
F_91 ( & V_166 ) ;
F_127 ( & V_165 , V_48 -> V_168 ) ;
F_93 ( & V_166 ) ;
F_128 ( & V_48 -> V_91 ) ;
F_27 ( V_48 ) ;
}
static int F_129 ( struct V_69 * V_70 , void * V_135 )
{
int V_153 ;
struct V_136 * V_137 = V_135 ;
if ( ! V_137 -> V_171 )
return - V_145 ;
F_34 ( ! V_137 -> V_51 && ! V_137 -> V_146 ) ;
V_153 = F_130 ( V_70 , NULL ) ;
if ( V_153 )
return V_153 ;
V_70 -> V_111 = V_137 -> V_171 ;
V_137 -> V_171 -> V_70 = V_70 ;
V_70 -> V_172 = V_173 ;
V_70 -> V_174 = V_175 ;
V_70 -> V_176 = V_177 ;
V_70 -> V_178 = & V_179 ;
return 0 ;
}
static int F_131 ( struct V_69 * V_70 )
{
static const struct V_180 V_181 = {
. V_182 = F_73 ,
. F_81 = F_78 ,
} ;
struct V_67 * V_67 =
F_60 ( V_183 | V_184 | V_185 | V_186 , V_70 ) ;
if ( ! V_67 )
return - V_54 ;
V_67 -> V_187 = & V_188 ;
V_67 -> V_189 = & V_190 ;
F_132 ( V_67 ) ;
V_70 -> V_191 = F_133 ( V_67 ) ;
if ( ! V_70 -> V_191 )
return - V_54 ;
V_70 -> V_192 = & V_181 ;
return 0 ;
}
static struct V_14 * F_134 ( struct V_193 * V_194 ,
int V_10 , const char * V_195 ,
void * V_135 )
{
struct V_136 V_137 ;
struct V_50 * V_48 ;
int V_153 = 0 ;
struct V_69 * V_70 ;
struct V_50 * V_171 ;
struct V_67 * V_67 ;
F_57 ( & V_1 ) ;
V_153 = F_101 ( V_135 , & V_137 ) ;
F_59 ( & V_1 ) ;
if ( V_153 )
goto V_196;
V_171 = F_122 ( & V_137 ) ;
if ( F_135 ( V_171 ) ) {
V_153 = F_136 ( V_171 ) ;
goto V_197;
}
V_137 . V_171 = V_171 ;
V_70 = F_137 ( V_194 , F_121 , F_129 , 0 , & V_137 ) ;
if ( F_135 ( V_70 ) ) {
V_153 = F_136 ( V_70 ) ;
F_126 ( V_137 . V_171 ) ;
goto V_197;
}
V_48 = V_70 -> V_111 ;
F_34 ( ! V_48 ) ;
if ( V_48 == V_137 . V_171 ) {
struct V_38 V_55 ;
struct V_7 * V_198 = & V_48 -> V_66 ;
struct V_50 * V_199 ;
const struct V_200 * V_200 ;
int V_18 ;
struct V_21 * V_22 ;
F_34 ( V_70 -> V_191 != NULL ) ;
V_153 = F_131 ( V_70 ) ;
if ( V_153 )
goto V_201;
V_67 = V_70 -> V_191 -> V_101 ;
F_57 ( & V_67 -> V_102 ) ;
F_57 ( & V_1 ) ;
F_57 ( & V_119 ) ;
V_153 = - V_123 ;
if ( strlen ( V_48 -> V_98 ) )
F_138 (existing_root)
if ( ! strcmp ( V_199 -> V_98 , V_48 -> V_98 ) )
goto V_202;
V_153 = F_39 ( V_30 , & V_55 ) ;
if ( V_153 )
goto V_202;
V_153 = F_94 ( V_48 , V_48 -> V_51 ) ;
if ( V_153 == - V_123 ) {
F_38 ( & V_55 ) ;
goto V_202;
}
F_34 ( V_153 ) ;
F_42 ( & V_48 -> V_163 , & V_203 ) ;
V_58 ++ ;
V_70 -> V_191 -> V_15 = V_198 ;
V_48 -> V_66 . V_14 = V_70 -> V_191 ;
F_17 ( & V_28 ) ;
F_139 (css_set_table, i, cg, hlist)
F_43 ( & V_55 , V_22 , V_198 ) ;
F_19 ( & V_28 ) ;
F_38 ( & V_55 ) ;
F_34 ( ! F_44 ( & V_198 -> V_157 ) ) ;
F_34 ( V_48 -> V_88 != 1 ) ;
V_200 = F_140 ( & V_204 ) ;
F_110 ( V_198 , true , V_48 -> V_51 ) ;
F_141 ( V_200 ) ;
F_59 ( & V_119 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_67 -> V_102 ) ;
} else {
F_126 ( V_137 . V_171 ) ;
F_106 ( V_137 . V_51 ) ;
}
F_27 ( V_137 . V_148 ) ;
F_27 ( V_137 . V_98 ) ;
return F_80 ( V_70 -> V_191 ) ;
V_202:
F_59 ( & V_119 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_67 -> V_102 ) ;
V_201:
F_142 ( V_70 ) ;
V_197:
F_106 ( V_137 . V_51 ) ;
V_196:
F_27 ( V_137 . V_148 ) ;
F_27 ( V_137 . V_98 ) ;
return F_124 ( V_153 ) ;
}
static void F_143 ( struct V_69 * V_70 ) {
struct V_50 * V_48 = V_70 -> V_111 ;
struct V_7 * V_8 = & V_48 -> V_66 ;
int V_153 ;
struct V_24 * V_25 ;
struct V_24 * V_26 ;
F_34 ( ! V_48 ) ;
F_34 ( V_48 -> V_88 != 1 ) ;
F_34 ( ! F_44 ( & V_8 -> V_157 ) ) ;
F_57 ( & V_1 ) ;
F_57 ( & V_119 ) ;
V_153 = F_94 ( V_48 , 0 ) ;
F_34 ( V_153 ) ;
F_17 ( & V_28 ) ;
F_21 (link, saved_link, &cgrp->css_sets,
cgrp_link_list) {
F_22 ( & V_25 -> V_31 ) ;
F_22 ( & V_25 -> V_32 ) ;
F_27 ( V_25 ) ;
}
F_19 ( & V_28 ) ;
if ( ! F_44 ( & V_48 -> V_163 ) ) {
F_22 ( & V_48 -> V_163 ) ;
V_58 -- ;
}
F_59 ( & V_119 ) ;
F_59 ( & V_1 ) ;
F_69 ( & V_8 -> V_90 ) ;
F_144 ( V_70 ) ;
F_126 ( V_48 ) ;
}
int F_145 ( const struct V_7 * V_8 , char * V_205 , int V_206 )
{
struct V_14 * V_14 = V_8 -> V_14 ;
char * V_207 ;
F_146 ( F_147 () || F_1 () ,
L_17 ) ;
if ( V_8 == V_124 ) {
strcpy ( V_205 , L_18 ) ;
return 0 ;
}
V_207 = V_205 + V_206 - 1 ;
* V_207 = '\0' ;
for (; ; ) {
int V_208 = V_14 -> V_209 . V_208 ;
if ( ( V_207 -= V_208 ) < V_205 )
return - V_210 ;
memcpy ( V_207 , V_14 -> V_209 . V_98 , V_208 ) ;
V_8 = V_8 -> V_100 ;
if ( ! V_8 )
break;
V_14 = V_8 -> V_14 ;
if ( ! V_8 -> V_100 )
continue;
if ( -- V_207 < V_205 )
return - V_210 ;
* V_207 = '/' ;
}
memmove ( V_205 , V_207 , V_205 + V_206 - V_207 ) ;
return 0 ;
}
struct V_62 * F_148 ( struct V_211 * V_212 )
{
if ( V_212 -> V_213 ) {
V_212 -> V_214 = 0 ;
return F_149 ( V_212 ) ;
} else {
V_212 -> V_215 = V_212 -> V_216 . V_8 ;
return V_212 -> V_216 . V_63 ;
}
}
struct V_62 * F_149 ( struct V_211 * V_212 )
{
struct V_217 * V_218 ;
if ( ! V_212 -> V_213 || V_212 -> V_214 >= V_212 -> V_219 )
return NULL ;
V_218 = F_150 ( V_212 -> V_213 , V_212 -> V_214 ++ ) ;
V_212 -> V_215 = V_218 -> V_8 ;
return V_218 -> V_63 ;
}
struct V_7 * F_151 ( struct V_211 * V_212 )
{
return V_212 -> V_215 ;
}
int F_152 ( struct V_211 * V_212 )
{
return V_212 -> V_213 ? V_212 -> V_219 : 1 ;
}
static void F_153 ( struct V_7 * V_8 , struct V_7 * V_220 ,
struct V_62 * V_221 , struct V_21 * V_222 )
{
struct V_21 * V_49 ;
F_154 ( V_221 -> V_10 & V_223 ) ;
V_49 = V_221 -> V_64 ;
F_155 ( V_221 ) ;
F_156 ( V_221 -> V_64 , V_222 ) ;
F_157 ( V_221 ) ;
F_17 ( & V_28 ) ;
if ( ! F_44 ( & V_221 -> V_224 ) )
F_46 ( & V_221 -> V_224 , & V_222 -> V_59 ) ;
F_19 ( & V_28 ) ;
F_24 ( V_12 , & V_220 -> V_10 ) ;
F_31 ( V_49 ) ;
}
int F_158 ( struct V_7 * V_8 , struct V_62 * V_221 )
{
int V_225 = 0 ;
struct V_85 * V_86 , * V_226 = NULL ;
struct V_7 * V_220 ;
struct V_50 * V_48 = V_8 -> V_48 ;
struct V_211 V_212 = { } ;
struct V_21 * V_222 ;
if ( V_221 -> V_10 & V_223 )
return - V_227 ;
V_220 = F_55 ( V_221 , V_48 ) ;
if ( V_8 == V_220 )
return 0 ;
V_212 . V_216 . V_63 = V_221 ;
V_212 . V_216 . V_8 = V_220 ;
F_67 (root, ss) {
if ( V_86 -> V_228 ) {
V_225 = V_86 -> V_228 ( V_8 , & V_212 ) ;
if ( V_225 ) {
V_226 = V_86 ;
goto V_229;
}
}
}
V_222 = F_48 ( V_221 -> V_64 , V_8 ) ;
if ( ! V_222 ) {
V_225 = - V_54 ;
goto V_229;
}
F_153 ( V_8 , V_220 , V_221 , V_222 ) ;
F_67 (root, ss) {
if ( V_86 -> V_230 )
V_86 -> V_230 ( V_8 , & V_212 ) ;
}
V_229:
if ( V_225 ) {
F_67 (root, ss) {
if ( V_86 == V_226 )
break;
if ( V_86 -> V_231 )
V_86 -> V_231 ( V_8 , & V_212 ) ;
}
}
return V_225 ;
}
int F_159 ( struct V_62 * V_232 , struct V_62 * V_221 )
{
struct V_50 * V_48 ;
int V_225 = 0 ;
F_56 () ;
F_138 (root) {
struct V_7 * V_233 = F_55 ( V_232 , V_48 ) ;
V_225 = F_158 ( V_233 , V_221 ) ;
if ( V_225 )
break;
}
F_58 () ;
return V_225 ;
}
static int F_160 ( struct V_7 * V_8 , struct V_62 * V_234 )
{
int V_225 , V_18 , V_235 ;
struct V_85 * V_86 , * V_226 = NULL ;
struct V_50 * V_48 = V_8 -> V_48 ;
struct V_62 * V_221 ;
struct V_217 * V_218 ;
struct V_236 * V_237 ;
struct V_211 V_212 = { } ;
V_235 = F_161 ( V_234 ) ;
V_237 = F_162 ( sizeof( * V_218 ) , V_235 , V_53 ) ;
if ( ! V_237 )
return - V_54 ;
V_225 = F_163 ( V_237 , 0 , V_235 - 1 , V_53 ) ;
if ( V_225 )
goto V_238;
V_221 = V_234 ;
V_18 = 0 ;
F_23 () ;
do {
struct V_217 V_239 ;
if ( V_221 -> V_10 & V_223 )
continue;
F_34 ( V_18 >= V_235 ) ;
V_239 . V_63 = V_221 ;
V_239 . V_8 = F_55 ( V_221 , V_48 ) ;
if ( V_239 . V_8 == V_8 )
continue;
V_225 = F_164 ( V_237 , V_18 , & V_239 , V_240 ) ;
F_34 ( V_225 != 0 ) ;
V_18 ++ ;
} while_each_thread(leader, tsk) ;
int F_165 ( struct V_7 * V_8 , T_2 V_241 , bool V_242 )
{
struct V_62 * V_221 ;
const struct V_200 * V_200 = F_166 () , * V_243 ;
int V_153 ;
if ( ! F_167 ( V_8 ) )
return - V_244 ;
V_245:
F_23 () ;
if ( V_241 ) {
V_221 = F_168 ( V_241 ) ;
if ( ! V_221 ) {
F_26 () ;
V_153 = - V_227 ;
goto V_246;
}
V_243 = F_169 ( V_221 ) ;
if ( ! F_170 ( V_200 -> V_247 , V_248 ) &&
! F_170 ( V_200 -> V_247 , V_243 -> V_249 ) &&
! F_170 ( V_200 -> V_247 , V_243 -> V_250 ) ) {
F_26 () ;
V_153 = - V_251 ;
goto V_246;
}
} else
V_221 = V_155 ;
if ( V_242 )
V_221 = V_221 -> V_252 ;
if ( V_221 == V_253 || ( V_221 -> V_10 & V_254 ) ) {
V_153 = - V_145 ;
F_26 () ;
goto V_246;
}
F_171 ( V_221 ) ;
F_26 () ;
F_172 ( V_221 ) ;
if ( V_242 ) {
if ( ! F_173 ( V_221 ) ) {
F_174 ( V_221 ) ;
F_175 ( V_221 ) ;
goto V_245;
}
V_153 = F_160 ( V_8 , V_221 ) ;
} else
V_153 = F_158 ( V_8 , V_221 ) ;
F_174 ( V_221 ) ;
F_175 ( V_221 ) ;
V_246:
F_58 () ;
return V_153 ;
}
static int F_176 ( struct V_7 * V_8 , struct V_17 * V_96 , T_2 V_241 )
{
return F_165 ( V_8 , V_241 , false ) ;
}
static int F_177 ( struct V_7 * V_8 , struct V_17 * V_96 , T_2 V_255 )
{
return F_165 ( V_8 , V_255 , true ) ;
}
bool F_167 ( struct V_7 * V_8 )
{
F_57 ( & V_1 ) ;
if ( F_7 ( V_8 ) ) {
F_59 ( & V_1 ) ;
return false ;
}
return true ;
}
static int F_178 ( struct V_7 * V_8 , struct V_17 * V_96 ,
const char * V_256 )
{
F_179 ( sizeof( V_8 -> V_48 -> V_133 ) < V_149 ) ;
if ( strlen ( V_256 ) >= V_149 )
return - V_145 ;
if ( ! F_167 ( V_8 ) )
return - V_244 ;
F_57 ( & V_119 ) ;
strcpy ( V_8 -> V_48 -> V_133 , V_256 ) ;
F_59 ( & V_119 ) ;
F_58 () ;
return 0 ;
}
static int F_180 ( struct V_7 * V_8 , struct V_17 * V_96 ,
struct V_129 * V_130 )
{
if ( ! F_167 ( V_8 ) )
return - V_244 ;
F_100 ( V_130 , V_8 -> V_48 -> V_133 ) ;
F_181 ( V_130 , '\n' ) ;
F_58 () ;
return 0 ;
}
static T_3 F_182 ( struct V_7 * V_8 , struct V_17 * V_96 ,
struct V_257 * V_257 ,
const char T_4 * V_258 ,
T_5 V_259 , T_6 * V_260 )
{
char V_256 [ V_261 ] ;
int V_225 = 0 ;
char * V_262 ;
if ( ! V_259 )
return - V_145 ;
if ( V_259 >= sizeof( V_256 ) )
return - V_263 ;
if ( F_183 ( V_256 , V_258 , V_259 ) )
return - V_264 ;
V_256 [ V_259 ] = 0 ;
if ( V_96 -> V_265 ) {
T_2 V_266 = F_184 ( F_185 ( V_256 ) , & V_262 , 0 ) ;
if ( * V_262 )
return - V_145 ;
V_225 = V_96 -> V_265 ( V_8 , V_96 , V_266 ) ;
} else {
T_7 V_266 = F_186 ( F_185 ( V_256 ) , & V_262 , 0 ) ;
if ( * V_262 )
return - V_145 ;
V_225 = V_96 -> V_267 ( V_8 , V_96 , V_266 ) ;
}
if ( ! V_225 )
V_225 = V_259 ;
return V_225 ;
}
static T_3 F_187 ( struct V_7 * V_8 , struct V_17 * V_96 ,
struct V_257 * V_257 ,
const char T_4 * V_258 ,
T_5 V_259 , T_6 * V_260 )
{
char V_268 [ V_261 ] ;
int V_225 = 0 ;
T_5 V_269 = V_96 -> V_270 ;
char * V_256 = V_268 ;
if ( ! V_269 )
V_269 = sizeof( V_268 ) - 1 ;
if ( V_259 >= V_269 )
return - V_263 ;
if ( V_259 >= sizeof( V_268 ) ) {
V_256 = F_41 ( V_259 + 1 , V_53 ) ;
if ( V_256 == NULL )
return - V_54 ;
}
if ( V_259 && F_183 ( V_256 , V_258 , V_259 ) ) {
V_225 = - V_264 ;
goto V_229;
}
V_256 [ V_259 ] = 0 ;
V_225 = V_96 -> V_271 ( V_8 , V_96 , F_185 ( V_256 ) ) ;
if ( ! V_225 )
V_225 = V_259 ;
V_229:
if ( V_256 != V_268 )
F_27 ( V_256 ) ;
return V_225 ;
}
static T_3 F_188 ( struct V_257 * V_257 , const char T_4 * V_205 ,
T_5 V_259 , T_6 * V_272 )
{
struct V_17 * V_96 = F_13 ( V_257 -> V_273 ) ;
struct V_7 * V_8 = F_11 ( V_257 -> V_273 -> V_95 ) ;
if ( F_7 ( V_8 ) )
return - V_244 ;
if ( V_96 -> V_274 )
return V_96 -> V_274 ( V_8 , V_96 , V_257 , V_205 , V_259 , V_272 ) ;
if ( V_96 -> V_265 || V_96 -> V_267 )
return F_182 ( V_8 , V_96 , V_257 , V_205 , V_259 , V_272 ) ;
if ( V_96 -> V_271 )
return F_187 ( V_8 , V_96 , V_257 , V_205 , V_259 , V_272 ) ;
if ( V_96 -> V_275 ) {
int V_153 = V_96 -> V_275 ( V_8 , ( unsigned int ) V_96 -> V_276 ) ;
return V_153 ? V_153 : V_259 ;
}
return - V_145 ;
}
static T_3 F_189 ( struct V_7 * V_8 , struct V_17 * V_96 ,
struct V_257 * V_257 ,
char T_4 * V_205 , T_5 V_259 ,
T_6 * V_272 )
{
char V_52 [ V_261 ] ;
T_2 V_266 = V_96 -> V_277 ( V_8 , V_96 ) ;
int V_208 = sprintf ( V_52 , L_19 , ( unsigned long long ) V_266 ) ;
return F_190 ( V_205 , V_259 , V_272 , V_52 , V_208 ) ;
}
static T_3 F_191 ( struct V_7 * V_8 , struct V_17 * V_96 ,
struct V_257 * V_257 ,
char T_4 * V_205 , T_5 V_259 ,
T_6 * V_272 )
{
char V_52 [ V_261 ] ;
T_7 V_266 = V_96 -> V_278 ( V_8 , V_96 ) ;
int V_208 = sprintf ( V_52 , L_20 , ( long long ) V_266 ) ;
return F_190 ( V_205 , V_259 , V_272 , V_52 , V_208 ) ;
}
static T_3 F_192 ( struct V_257 * V_257 , char T_4 * V_205 ,
T_5 V_259 , T_6 * V_272 )
{
struct V_17 * V_96 = F_13 ( V_257 -> V_273 ) ;
struct V_7 * V_8 = F_11 ( V_257 -> V_273 -> V_95 ) ;
if ( F_7 ( V_8 ) )
return - V_244 ;
if ( V_96 -> V_279 )
return V_96 -> V_279 ( V_8 , V_96 , V_257 , V_205 , V_259 , V_272 ) ;
if ( V_96 -> V_277 )
return F_189 ( V_8 , V_96 , V_257 , V_205 , V_259 , V_272 ) ;
if ( V_96 -> V_278 )
return F_191 ( V_8 , V_96 , V_257 , V_205 , V_259 , V_272 ) ;
return - V_145 ;
}
static int F_193 ( struct V_280 * V_281 , const char * V_19 , T_2 V_282 )
{
struct V_129 * V_283 = V_281 -> V_284 ;
return F_99 ( V_283 , L_21 , V_19 , ( unsigned long long ) V_282 ) ;
}
static int F_194 ( struct V_129 * V_285 , void * V_286 )
{
struct V_287 * V_284 = V_285 -> V_276 ;
struct V_17 * V_96 = V_284 -> V_96 ;
if ( V_96 -> V_288 ) {
struct V_280 V_281 = {
. V_289 = F_193 ,
. V_284 = V_285 ,
} ;
return V_96 -> V_288 ( V_284 -> V_7 , V_96 , & V_281 ) ;
}
return V_96 -> V_290 ( V_284 -> V_7 , V_96 , V_285 ) ;
}
static int F_195 ( struct V_67 * V_67 , struct V_257 * V_257 )
{
struct V_129 * V_130 = V_257 -> V_291 ;
F_27 ( V_130 -> V_276 ) ;
return F_196 ( V_67 , V_257 ) ;
}
static int F_197 ( struct V_67 * V_67 , struct V_257 * V_257 )
{
int V_292 ;
struct V_17 * V_96 ;
V_292 = F_198 ( V_67 , V_257 ) ;
if ( V_292 )
return V_292 ;
V_96 = F_13 ( V_257 -> V_273 ) ;
if ( V_96 -> V_288 || V_96 -> V_290 ) {
struct V_287 * V_284 =
F_123 ( sizeof( * V_284 ) , V_293 ) ;
if ( ! V_284 )
return - V_54 ;
V_284 -> V_96 = V_96 ;
V_284 -> V_7 = F_11 ( V_257 -> V_273 -> V_95 ) ;
V_257 -> V_294 = & V_295 ;
V_292 = F_199 ( V_257 , F_194 , V_284 ) ;
if ( V_292 < 0 )
F_27 ( V_284 ) ;
} else if ( V_96 -> V_296 )
V_292 = V_96 -> V_296 ( V_67 , V_257 ) ;
else
V_292 = 0 ;
return V_292 ;
}
static int F_200 ( struct V_67 * V_67 , struct V_257 * V_257 )
{
struct V_17 * V_96 = F_13 ( V_257 -> V_273 ) ;
if ( V_96 -> V_297 )
return V_96 -> V_297 ( V_67 , V_257 ) ;
return 0 ;
}
static int F_201 ( struct V_67 * V_298 , struct V_14 * V_299 ,
struct V_67 * V_300 , struct V_14 * V_301 )
{
if ( ! F_74 ( V_299 -> V_101 -> V_72 ) )
return - V_302 ;
if ( V_301 -> V_101 )
return - V_303 ;
if ( V_298 != V_300 )
return - V_304 ;
return F_202 ( V_298 , V_299 , V_300 , V_301 ) ;
}
static struct V_305 * F_203 ( struct V_14 * V_14 )
{
if ( F_74 ( V_14 -> V_101 -> V_72 ) )
return & F_11 ( V_14 ) -> V_90 ;
else
return & F_13 ( V_14 ) -> V_90 ;
}
static inline int F_204 ( struct V_14 * V_14 )
{
struct V_50 * V_48 = V_14 -> V_110 -> V_111 ;
return F_8 ( V_132 , & V_48 -> V_10 ) ;
}
static bool F_205 ( const char * V_98 )
{
if ( ! strncmp ( V_98 , V_306 , V_307 ) ||
! strncmp ( V_98 , V_308 , V_309 ) )
return true ;
return false ;
}
static int F_206 ( struct V_14 * V_14 , const char * V_98 ,
const void * V_266 , T_5 V_310 , int V_10 )
{
if ( ! F_204 ( V_14 ) )
return - V_311 ;
if ( ! F_205 ( V_98 ) )
return - V_145 ;
return F_207 ( F_203 ( V_14 ) , V_98 , V_266 , V_310 , V_10 ) ;
}
static int F_208 ( struct V_14 * V_14 , const char * V_98 )
{
if ( ! F_204 ( V_14 ) )
return - V_311 ;
if ( ! F_205 ( V_98 ) )
return - V_145 ;
return F_209 ( F_203 ( V_14 ) , V_98 ) ;
}
static T_3 F_210 ( struct V_14 * V_14 , const char * V_98 ,
void * V_205 , T_5 V_310 )
{
if ( ! F_204 ( V_14 ) )
return - V_311 ;
if ( ! F_205 ( V_98 ) )
return - V_145 ;
return F_211 ( F_203 ( V_14 ) , V_98 , V_205 , V_310 ) ;
}
static T_3 F_212 ( struct V_14 * V_14 , char * V_205 , T_5 V_310 )
{
if ( ! F_204 ( V_14 ) )
return - V_311 ;
return F_213 ( F_203 ( V_14 ) , V_205 , V_310 ) ;
}
static struct V_14 * F_214 ( struct V_67 * V_103 , struct V_14 * V_14 , unsigned int V_10 )
{
if ( V_14 -> V_209 . V_208 > V_312 )
return F_124 ( - V_210 ) ;
F_215 ( V_14 , NULL ) ;
return NULL ;
}
static inline struct V_17 * F_216 ( struct V_257 * V_257 )
{
if ( F_217 ( V_257 ) -> V_187 != & V_313 )
return F_124 ( - V_145 ) ;
return F_13 ( V_257 -> V_273 ) ;
}
static int F_218 ( struct V_14 * V_14 , T_1 V_68 ,
struct V_69 * V_70 )
{
struct V_67 * V_67 ;
if ( ! V_14 )
return - V_152 ;
if ( V_14 -> V_101 )
return - V_303 ;
V_67 = F_60 ( V_68 , V_70 ) ;
if ( ! V_67 )
return - V_54 ;
if ( F_74 ( V_68 ) ) {
V_67 -> V_189 = & V_190 ;
V_67 -> V_187 = & V_188 ;
F_132 ( V_67 ) ;
F_132 ( V_14 -> V_95 -> V_101 ) ;
F_154 ( ! F_219 ( & V_67 -> V_102 ) ) ;
} else if ( F_220 ( V_68 ) ) {
V_67 -> V_314 = 0 ;
V_67 -> V_187 = & V_313 ;
V_67 -> V_189 = & V_315 ;
}
F_221 ( V_14 , V_67 ) ;
F_80 ( V_14 ) ;
return 0 ;
}
static T_1 F_222 ( const struct V_17 * V_96 )
{
T_1 V_68 = 0 ;
if ( V_96 -> V_68 )
return V_96 -> V_68 ;
if ( V_96 -> V_279 || V_96 -> V_277 || V_96 -> V_278 ||
V_96 -> V_288 || V_96 -> V_290 )
V_68 |= V_184 ;
if ( V_96 -> V_274 || V_96 -> V_265 || V_96 -> V_267 ||
V_96 -> V_271 || V_96 -> V_275 )
V_68 |= V_186 ;
return V_68 ;
}
static int F_223 ( struct V_7 * V_8 , struct V_85 * V_41 ,
struct V_17 * V_96 )
{
struct V_14 * V_103 = V_8 -> V_14 ;
struct V_7 * V_100 = F_11 ( V_103 ) ;
struct V_14 * V_14 ;
struct V_16 * V_94 ;
int error ;
T_1 V_68 ;
char V_98 [ V_316 + V_317 + 2 ] = { 0 } ;
F_115 ( & V_96 -> V_90 ) ;
if ( V_41 && ! F_8 ( V_131 , & V_8 -> V_48 -> V_10 ) ) {
strcpy ( V_98 , V_41 -> V_98 ) ;
strcat ( V_98 , L_22 ) ;
}
strcat ( V_98 , V_96 -> V_98 ) ;
F_34 ( ! F_3 ( & V_103 -> V_101 -> V_102 ) ) ;
V_94 = F_123 ( sizeof( * V_94 ) , V_53 ) ;
if ( ! V_94 )
return - V_54 ;
V_14 = F_224 ( V_98 , V_103 , strlen ( V_98 ) ) ;
if ( F_135 ( V_14 ) ) {
error = F_136 ( V_14 ) ;
goto V_229;
}
V_68 = F_222 ( V_96 ) ;
error = F_218 ( V_14 , V_68 | V_318 , V_8 -> V_48 -> V_70 ) ;
if ( ! error ) {
V_94 -> type = ( void * ) V_96 ;
V_94 -> V_14 = V_14 ;
V_14 -> V_15 = V_94 ;
F_47 ( & V_94 -> V_97 , & V_100 -> V_109 ) ;
V_94 = NULL ;
}
F_83 ( V_14 ) ;
V_229:
F_27 ( V_94 ) ;
return error ;
}
static int F_89 ( struct V_7 * V_8 , struct V_85 * V_41 ,
struct V_17 V_108 [] , bool V_319 )
{
struct V_17 * V_96 ;
int V_292 , V_153 = 0 ;
for ( V_96 = V_108 ; V_96 -> V_98 [ 0 ] != '\0' ; V_96 ++ ) {
if ( ( V_96 -> V_10 & V_320 ) && ! V_8 -> V_100 )
continue;
if ( ( V_96 -> V_10 & V_321 ) && V_8 -> V_100 )
continue;
if ( V_319 ) {
V_292 = F_223 ( V_8 , V_41 , V_96 ) ;
if ( V_292 )
F_225 ( L_23 ,
V_96 -> V_98 , V_292 ) ;
V_153 = V_292 ;
} else {
F_84 ( V_8 , V_96 ) ;
}
}
return V_153 ;
}
static void F_226 ( void )
__acquires( &cgroup_cft_mutex
static void F_227 ( struct V_85 * V_86 ,
struct V_17 * V_108 , bool V_319 )
__releases( &cgroup_mutex
int F_228 ( struct V_85 * V_86 , struct V_17 * V_108 )
{
struct V_105 * V_106 ;
V_106 = F_123 ( sizeof( * V_106 ) , V_53 ) ;
if ( ! V_106 )
return - V_54 ;
F_226 () ;
V_106 -> V_108 = V_108 ;
F_47 ( & V_106 -> V_97 , & V_86 -> V_322 ) ;
F_227 ( V_86 , V_108 , true ) ;
return 0 ;
}
int F_229 ( struct V_85 * V_86 , struct V_17 * V_108 )
{
struct V_105 * V_106 ;
F_226 () ;
F_53 (set, &ss->cftsets, node) {
if ( V_106 -> V_108 == V_108 ) {
F_87 ( & V_106 -> V_97 ) ;
F_227 ( V_86 , V_108 , false ) ;
return 0 ;
}
}
F_227 ( V_86 , NULL , false ) ;
return - V_152 ;
}
int F_230 ( const struct V_7 * V_8 )
{
int V_33 = 0 ;
struct V_24 * V_25 ;
F_49 ( & V_28 ) ;
F_53 (link, &cgrp->css_sets, cgrp_link_list) {
V_33 += F_6 ( & V_25 -> V_22 -> V_27 ) ;
}
F_50 ( & V_28 ) ;
return V_33 ;
}
static void F_231 ( struct V_7 * V_8 ,
struct V_323 * V_324 )
{
struct V_38 * V_325 = V_324 -> V_326 ;
struct V_24 * V_25 ;
struct V_21 * V_22 ;
do {
V_325 = V_325 -> V_47 ;
if ( V_325 == & V_8 -> V_56 ) {
V_324 -> V_326 = NULL ;
return;
}
V_25 = F_35 ( V_325 , struct V_24 , V_32 ) ;
V_22 = V_25 -> V_22 ;
} while ( F_44 ( & V_22 -> V_59 ) );
V_324 -> V_326 = V_325 ;
V_324 -> V_63 = V_22 -> V_59 . V_47 ;
}
static void F_232 ( void )
{
struct V_62 * V_327 , * V_328 ;
F_17 ( & V_28 ) ;
V_329 = 1 ;
F_49 ( & V_330 ) ;
F_233 (g, p) {
F_155 ( V_327 ) ;
if ( ! ( V_327 -> V_10 & V_223 ) && F_44 ( & V_327 -> V_224 ) )
F_42 ( & V_327 -> V_224 , & V_327 -> V_64 -> V_59 ) ;
F_157 ( V_327 ) ;
} F_234 ( V_328 , V_327 ) ;
F_50 ( & V_330 ) ;
F_19 ( & V_28 ) ;
}
struct V_7 * F_235 ( struct V_7 * V_331 ,
struct V_7 * V_7 )
{
struct V_7 * V_47 ;
F_154 ( ! F_147 () ) ;
if ( ! V_331 ) {
if ( F_44 ( & V_7 -> V_157 ) )
return NULL ;
V_331 = V_7 ;
}
V_47 = F_236 ( & V_331 -> V_157 , struct V_7 , V_125 ) ;
if ( V_47 )
return V_47 ;
do {
V_47 = F_237 ( V_331 -> V_125 . V_47 , struct V_7 ,
V_125 ) ;
if ( & V_47 -> V_125 != & V_331 -> V_100 -> V_157 )
return V_47 ;
V_331 = V_331 -> V_100 ;
} while ( V_331 != V_7 );
return NULL ;
}
struct V_7 * F_238 ( struct V_7 * V_331 )
{
struct V_7 * V_332 , * V_52 ;
F_154 ( ! F_147 () ) ;
do {
V_332 = V_331 ;
V_331 = NULL ;
F_239 (tmp, &last->children, sibling)
V_331 = V_52 ;
} while ( V_331 );
return V_332 ;
}
static struct V_7 * F_240 ( struct V_7 * V_331 )
{
struct V_7 * V_332 ;
do {
V_332 = V_331 ;
V_331 = F_236 ( & V_331 -> V_157 , struct V_7 ,
V_125 ) ;
} while ( V_331 );
return V_332 ;
}
struct V_7 * F_241 ( struct V_7 * V_331 ,
struct V_7 * V_7 )
{
struct V_7 * V_47 ;
F_154 ( ! F_147 () ) ;
if ( ! V_331 ) {
V_47 = F_240 ( V_7 ) ;
return V_47 != V_7 ? V_47 : NULL ;
}
V_47 = F_237 ( V_331 -> V_125 . V_47 , struct V_7 , V_125 ) ;
if ( & V_47 -> V_125 != & V_331 -> V_100 -> V_157 )
return F_240 ( V_47 ) ;
V_47 = V_331 -> V_100 ;
return V_47 != V_7 ? V_47 : NULL ;
}
void F_242 ( struct V_7 * V_8 , struct V_323 * V_324 )
__acquires( V_28 )
{
if ( ! V_329 )
F_232 () ;
F_49 ( & V_28 ) ;
V_324 -> V_326 = & V_8 -> V_56 ;
F_231 ( V_8 , V_324 ) ;
}
struct V_62 * F_243 ( struct V_7 * V_8 ,
struct V_323 * V_324 )
{
struct V_62 * V_57 ;
struct V_38 * V_325 = V_324 -> V_63 ;
struct V_24 * V_25 ;
if ( ! V_324 -> V_326 )
return NULL ;
V_57 = F_35 ( V_325 , struct V_62 , V_224 ) ;
V_325 = V_325 -> V_47 ;
V_25 = F_35 ( V_324 -> V_326 , struct V_24 , V_32 ) ;
if ( V_325 == & V_25 -> V_22 -> V_59 ) {
F_231 ( V_8 , V_324 ) ;
} else {
V_324 -> V_63 = V_325 ;
}
return V_57 ;
}
void F_244 ( struct V_7 * V_8 , struct V_323 * V_324 )
__releases( V_28 )
{
F_50 ( & V_28 ) ;
}
static inline int F_245 ( struct V_62 * V_333 ,
struct V_334 * time ,
struct V_62 * V_335 )
{
int V_336 = F_246 ( & V_333 -> V_337 , time ) ;
if ( V_336 > 0 ) {
return 1 ;
} else if ( V_336 < 0 ) {
return 0 ;
} else {
return V_333 > V_335 ;
}
}
static inline int F_247 ( void * V_338 , void * V_339 )
{
struct V_62 * V_333 = V_338 ;
struct V_62 * V_335 = V_339 ;
return F_245 ( V_333 , & V_335 -> V_337 , V_335 ) ;
}
int F_248 ( struct V_340 * V_341 )
{
int V_225 , V_18 ;
struct V_323 V_324 ;
struct V_62 * V_327 , * V_342 ;
struct V_62 * V_343 = NULL ;
struct V_344 V_345 ;
struct V_344 * V_346 ;
struct V_334 V_347 = { 0 , 0 } ;
if ( V_341 -> V_346 ) {
V_346 = V_341 -> V_346 ;
V_346 -> V_348 = & F_247 ;
} else {
V_346 = & V_345 ;
V_225 = F_249 ( V_346 , V_349 , V_53 , & F_247 ) ;
if ( V_225 )
return V_225 ;
}
V_350:
V_346 -> V_310 = 0 ;
F_242 ( V_341 -> V_22 , & V_324 ) ;
while ( ( V_327 = F_243 ( V_341 -> V_22 , & V_324 ) ) ) {
if ( V_341 -> V_351 && ! V_341 -> V_351 ( V_327 , V_341 ) )
continue;
if ( ! F_245 ( V_327 , & V_347 , V_343 ) )
continue;
V_342 = F_250 ( V_346 , V_327 ) ;
if ( V_342 == NULL ) {
F_171 ( V_327 ) ;
} else if ( V_342 != V_327 ) {
F_171 ( V_327 ) ;
F_175 ( V_342 ) ;
}
}
F_244 ( V_341 -> V_22 , & V_324 ) ;
if ( V_346 -> V_310 ) {
for ( V_18 = 0 ; V_18 < V_346 -> V_310 ; V_18 ++ ) {
struct V_62 * V_352 = V_346 -> V_353 [ V_18 ] ;
if ( V_18 == 0 ) {
V_347 = V_352 -> V_337 ;
V_343 = V_352 ;
}
V_341 -> V_354 ( V_352 , V_341 ) ;
F_175 ( V_352 ) ;
}
goto V_350;
}
if ( V_346 == & V_345 )
F_251 ( & V_345 ) ;
return 0 ;
}
static void * F_252 ( int V_33 )
{
if ( F_253 ( V_33 ) )
return F_254 ( V_33 * sizeof( V_355 ) ) ;
else
return F_41 ( V_33 * sizeof( V_355 ) , V_53 ) ;
}
static void F_255 ( void * V_327 )
{
if ( F_256 ( V_327 ) )
F_257 ( V_327 ) ;
else
F_27 ( V_327 ) ;
}
static void * F_258 ( void * V_327 , int V_356 )
{
void * V_357 ;
if ( F_256 ( V_327 ) ) {
V_357 = F_254 ( V_356 * sizeof( V_355 ) ) ;
if ( ! V_357 )
return NULL ;
memcpy ( V_357 , V_327 , V_356 * sizeof( V_355 ) ) ;
F_257 ( V_327 ) ;
} else {
V_357 = F_259 ( V_327 , V_356 * sizeof( V_355 ) , V_53 ) ;
}
return V_357 ;
}
static int F_260 ( V_355 * * V_327 , int V_358 )
{
int V_359 , V_360 = 1 ;
V_355 * V_361 = * V_327 ;
V_355 * V_357 ;
if ( V_358 == 0 || V_358 == 1 )
return V_358 ;
for ( V_359 = 1 ; V_359 < V_358 ; V_359 ++ ) {
while ( V_361 [ V_359 ] == V_361 [ V_359 - 1 ] ) {
V_359 ++ ;
if ( V_359 == V_358 )
goto V_362;
}
V_361 [ V_360 ] = V_361 [ V_359 ] ;
V_360 ++ ;
}
V_362:
if ( F_261 ( V_358 , V_360 ) ) {
V_357 = F_258 ( V_361 , V_360 ) ;
if ( V_357 )
* V_327 = V_357 ;
}
return V_360 ;
}
static int F_262 ( const void * V_363 , const void * V_364 )
{
return * ( V_355 * ) V_363 - * ( V_355 * ) V_364 ;
}
static struct V_365 * F_263 ( struct V_7 * V_8 ,
enum V_366 type )
{
struct V_365 * V_325 ;
struct V_367 * V_368 = F_264 ( V_155 ) ;
F_57 ( & V_8 -> V_160 ) ;
F_53 (l, &cgrp->pidlists, links) {
if ( V_325 -> V_19 . type == type && V_325 -> V_19 . V_368 == V_368 ) {
F_265 ( & V_325 -> V_369 ) ;
F_59 ( & V_8 -> V_160 ) ;
return V_325 ;
}
}
V_325 = F_41 ( sizeof( struct V_365 ) , V_53 ) ;
if ( ! V_325 ) {
F_59 ( & V_8 -> V_160 ) ;
return V_325 ;
}
F_266 ( & V_325 -> V_369 ) ;
F_265 ( & V_325 -> V_369 ) ;
V_325 -> V_19 . type = type ;
V_325 -> V_19 . V_368 = F_267 ( V_368 ) ;
V_325 -> V_370 = 0 ;
V_325 -> V_361 = NULL ;
V_325 -> V_371 = V_8 ;
F_42 ( & V_325 -> V_372 , & V_8 -> V_89 ) ;
F_59 ( & V_8 -> V_160 ) ;
return V_325 ;
}
static int F_268 ( struct V_7 * V_8 , enum V_366 type ,
struct V_365 * * V_373 )
{
V_355 * V_374 ;
int V_358 ;
int V_241 , V_375 = 0 ;
struct V_323 V_324 ;
struct V_62 * V_221 ;
struct V_365 * V_325 ;
V_358 = F_230 ( V_8 ) ;
V_374 = F_252 ( V_358 ) ;
if ( ! V_374 )
return - V_54 ;
F_242 ( V_8 , & V_324 ) ;
while ( ( V_221 = F_243 ( V_8 , & V_324 ) ) ) {
if ( F_269 ( V_375 == V_358 ) )
break;
if ( type == V_376 )
V_241 = F_270 ( V_221 ) ;
else
V_241 = F_271 ( V_221 ) ;
if ( V_241 > 0 )
V_374 [ V_375 ++ ] = V_241 ;
}
F_244 ( V_8 , & V_324 ) ;
V_358 = V_375 ;
F_272 ( V_374 , V_358 , sizeof( V_355 ) , F_262 , NULL ) ;
if ( type == V_376 )
V_358 = F_260 ( & V_374 , V_358 ) ;
V_325 = F_263 ( V_8 , type ) ;
if ( ! V_325 ) {
F_255 ( V_374 ) ;
return - V_54 ;
}
F_255 ( V_325 -> V_361 ) ;
V_325 -> V_361 = V_374 ;
V_325 -> V_358 = V_358 ;
V_325 -> V_370 ++ ;
F_273 ( & V_325 -> V_369 ) ;
* V_373 = V_325 ;
return 0 ;
}
int F_274 ( struct V_377 * V_378 , struct V_14 * V_14 )
{
int V_153 = - V_145 ;
struct V_7 * V_8 ;
struct V_323 V_324 ;
struct V_62 * V_221 ;
if ( V_14 -> V_110 -> V_178 != & V_179 ||
! F_74 ( V_14 -> V_101 -> V_72 ) )
goto V_292;
V_153 = 0 ;
V_8 = V_14 -> V_15 ;
F_242 ( V_8 , & V_324 ) ;
while ( ( V_221 = F_243 ( V_8 , & V_324 ) ) ) {
switch ( V_221 -> V_284 ) {
case V_379 :
V_378 -> V_380 ++ ;
break;
case V_381 :
V_378 -> V_382 ++ ;
break;
case V_383 :
V_378 -> V_384 ++ ;
break;
case V_385 :
V_378 -> V_386 ++ ;
break;
default:
if ( F_275 ( V_221 ) )
V_378 -> V_387 ++ ;
break;
}
}
F_244 ( V_8 , & V_324 ) ;
V_292:
return V_153 ;
}
static void * F_276 ( struct V_129 * V_388 , T_6 * V_331 )
{
struct V_365 * V_325 = V_388 -> V_276 ;
int V_389 = 0 , V_241 = * V_331 ;
int * V_390 ;
F_277 ( & V_325 -> V_369 ) ;
if ( V_241 ) {
int V_262 = V_325 -> V_358 ;
while ( V_389 < V_262 ) {
int V_391 = ( V_389 + V_262 ) / 2 ;
if ( V_325 -> V_361 [ V_391 ] == V_241 ) {
V_389 = V_391 ;
break;
} else if ( V_325 -> V_361 [ V_391 ] <= V_241 )
V_389 = V_391 + 1 ;
else
V_262 = V_391 ;
}
}
if ( V_389 >= V_325 -> V_358 )
return NULL ;
V_390 = V_325 -> V_361 + V_389 ;
* V_331 = * V_390 ;
return V_390 ;
}
static void F_278 ( struct V_129 * V_388 , void * V_6 )
{
struct V_365 * V_325 = V_388 -> V_276 ;
F_279 ( & V_325 -> V_369 ) ;
}
static void * F_280 ( struct V_129 * V_388 , void * V_6 , T_6 * V_331 )
{
struct V_365 * V_325 = V_388 -> V_276 ;
V_355 * V_327 = V_6 ;
V_355 * V_262 = V_325 -> V_361 + V_325 -> V_358 ;
V_327 ++ ;
if ( V_327 >= V_262 ) {
return NULL ;
} else {
* V_331 = * V_327 ;
return V_327 ;
}
}
static int F_281 ( struct V_129 * V_388 , void * V_6 )
{
return F_99 ( V_388 , L_24 , * ( int * ) V_6 ) ;
}
static void F_282 ( struct V_365 * V_325 )
{
F_57 ( & V_325 -> V_371 -> V_160 ) ;
F_265 ( & V_325 -> V_369 ) ;
F_34 ( ! V_325 -> V_370 ) ;
if ( ! -- V_325 -> V_370 ) {
F_22 ( & V_325 -> V_372 ) ;
F_59 ( & V_325 -> V_371 -> V_160 ) ;
F_255 ( V_325 -> V_361 ) ;
F_283 ( V_325 -> V_19 . V_368 ) ;
F_273 ( & V_325 -> V_369 ) ;
F_27 ( V_325 ) ;
return;
}
F_59 ( & V_325 -> V_371 -> V_160 ) ;
F_273 ( & V_325 -> V_369 ) ;
}
static int F_284 ( struct V_67 * V_67 , struct V_257 * V_257 )
{
struct V_365 * V_325 ;
if ( ! ( V_257 -> V_392 & V_393 ) )
return 0 ;
V_325 = ( (struct V_129 * ) V_257 -> V_291 ) -> V_276 ;
F_282 ( V_325 ) ;
return F_285 ( V_67 , V_257 ) ;
}
static int F_286 ( struct V_257 * V_257 , enum V_366 type )
{
struct V_7 * V_8 = F_11 ( V_257 -> V_273 -> V_95 ) ;
struct V_365 * V_325 ;
int V_225 ;
if ( ! ( V_257 -> V_392 & V_393 ) )
return 0 ;
V_225 = F_268 ( V_8 , type , & V_325 ) ;
if ( V_225 )
return V_225 ;
V_257 -> V_294 = & V_394 ;
V_225 = F_287 ( V_257 , & V_395 ) ;
if ( V_225 ) {
F_282 ( V_325 ) ;
return V_225 ;
}
( (struct V_129 * ) V_257 -> V_291 ) -> V_276 = V_325 ;
return 0 ;
}
static int F_288 ( struct V_67 * V_396 , struct V_257 * V_257 )
{
return F_286 ( V_257 , V_397 ) ;
}
static int F_289 ( struct V_67 * V_396 , struct V_257 * V_257 )
{
return F_286 ( V_257 , V_376 ) ;
}
static T_2 F_290 ( struct V_7 * V_8 ,
struct V_17 * V_96 )
{
return F_10 ( V_8 ) ;
}
static int F_291 ( struct V_7 * V_8 ,
struct V_17 * V_96 ,
T_2 V_266 )
{
F_292 ( V_12 , & V_8 -> V_10 ) ;
if ( V_266 )
F_24 ( V_13 , & V_8 -> V_10 ) ;
else
F_292 ( V_13 , & V_8 -> V_10 ) ;
return 0 ;
}
static void F_293 ( struct V_82 * V_83 )
{
struct V_398 * V_399 = F_66 ( V_83 , struct V_398 ,
remove ) ;
struct V_7 * V_8 = V_399 -> V_8 ;
F_294 ( V_399 -> V_400 , & V_399 -> V_401 ) ;
V_399 -> V_96 -> V_402 ( V_8 , V_399 -> V_96 , V_399 -> V_403 ) ;
F_295 ( V_399 -> V_403 , 1 ) ;
F_296 ( V_399 -> V_403 ) ;
F_27 ( V_399 ) ;
F_83 ( V_8 -> V_14 ) ;
}
static int F_297 ( T_8 * V_401 , unsigned V_68 ,
int V_404 , void * V_19 )
{
struct V_398 * V_399 = F_66 ( V_401 ,
struct V_398 , V_401 ) ;
struct V_7 * V_8 = V_399 -> V_8 ;
unsigned long V_10 = ( unsigned long ) V_19 ;
if ( V_10 & V_405 ) {
F_91 ( & V_8 -> V_162 ) ;
if ( ! F_44 ( & V_399 -> V_361 ) ) {
F_87 ( & V_399 -> V_361 ) ;
F_72 ( & V_399 -> remove ) ;
}
F_93 ( & V_8 -> V_162 ) ;
}
return 0 ;
}
static void F_298 ( struct V_257 * V_257 ,
T_9 * V_400 , T_10 * V_406 )
{
struct V_398 * V_399 = F_66 ( V_406 ,
struct V_398 , V_406 ) ;
V_399 -> V_400 = V_400 ;
F_299 ( V_400 , & V_399 -> V_401 ) ;
}
static int F_300 ( struct V_7 * V_8 , struct V_17 * V_96 ,
const char * V_256 )
{
struct V_398 * V_399 = NULL ;
struct V_7 * V_407 ;
unsigned int V_408 , V_409 ;
struct V_257 * V_410 = NULL ;
struct V_257 * V_411 = NULL ;
char * V_412 ;
int V_153 ;
V_408 = F_301 ( V_256 , & V_412 , 10 ) ;
if ( * V_412 != ' ' )
return - V_145 ;
V_256 = V_412 + 1 ;
V_409 = F_301 ( V_256 , & V_412 , 10 ) ;
if ( ( * V_412 != ' ' ) && ( * V_412 != '\0' ) )
return - V_145 ;
V_256 = V_412 + 1 ;
V_399 = F_123 ( sizeof( * V_399 ) , V_53 ) ;
if ( ! V_399 )
return - V_54 ;
V_399 -> V_8 = V_8 ;
F_40 ( & V_399 -> V_361 ) ;
F_302 ( & V_399 -> V_406 , F_298 ) ;
F_303 ( & V_399 -> V_401 , F_297 ) ;
F_112 ( & V_399 -> remove , F_293 ) ;
V_410 = F_304 ( V_408 ) ;
if ( F_135 ( V_410 ) ) {
V_153 = F_136 ( V_410 ) ;
goto V_413;
}
V_399 -> V_403 = F_305 ( V_410 ) ;
if ( F_135 ( V_399 -> V_403 ) ) {
V_153 = F_136 ( V_399 -> V_403 ) ;
goto V_413;
}
V_411 = F_306 ( V_409 ) ;
if ( ! V_411 ) {
V_153 = - V_414 ;
goto V_413;
}
V_153 = F_307 ( F_217 ( V_411 ) , V_415 ) ;
if ( V_153 < 0 )
goto V_413;
V_399 -> V_96 = F_216 ( V_411 ) ;
if ( F_135 ( V_399 -> V_96 ) ) {
V_153 = F_136 ( V_399 -> V_96 ) ;
goto V_413;
}
V_407 = F_11 ( V_411 -> V_273 -> V_95 ) ;
if ( V_407 != V_8 ) {
V_153 = - V_145 ;
goto V_413;
}
if ( ! V_399 -> V_96 -> V_416 || ! V_399 -> V_96 -> V_402 ) {
V_153 = - V_145 ;
goto V_413;
}
V_153 = V_399 -> V_96 -> V_416 ( V_8 , V_399 -> V_96 ,
V_399 -> V_403 , V_256 ) ;
if ( V_153 )
goto V_413;
if ( V_410 -> V_294 -> V_417 ( V_410 , & V_399 -> V_406 ) & V_405 ) {
V_399 -> V_96 -> V_402 ( V_8 , V_399 -> V_96 , V_399 -> V_403 ) ;
V_153 = 0 ;
goto V_413;
}
F_80 ( V_8 -> V_14 ) ;
F_91 ( & V_8 -> V_162 ) ;
F_42 ( & V_399 -> V_361 , & V_8 -> V_161 ) ;
F_93 ( & V_8 -> V_162 ) ;
F_308 ( V_411 ) ;
F_308 ( V_410 ) ;
return 0 ;
V_413:
if ( V_411 )
F_308 ( V_411 ) ;
if ( V_399 && V_399 -> V_403 && ! F_135 ( V_399 -> V_403 ) )
F_296 ( V_399 -> V_403 ) ;
if ( ! F_309 ( V_410 ) )
F_308 ( V_410 ) ;
F_27 ( V_399 ) ;
return V_153 ;
}
static T_2 F_310 ( struct V_7 * V_8 ,
struct V_17 * V_96 )
{
return F_8 ( V_134 , & V_8 -> V_10 ) ;
}
static int F_311 ( struct V_7 * V_8 ,
struct V_17 * V_96 ,
T_2 V_266 )
{
if ( V_266 )
F_24 ( V_134 , & V_8 -> V_10 ) ;
else
F_292 ( V_134 , & V_8 -> V_10 ) ;
return 0 ;
}
static int F_110 ( struct V_7 * V_8 , bool V_104 ,
unsigned long V_51 )
{
int V_292 ;
struct V_85 * V_86 ;
if ( V_104 ) {
V_292 = F_89 ( V_8 , NULL , V_109 , true ) ;
if ( V_292 < 0 )
return V_292 ;
}
F_67 (cgrp->root, ss) {
struct V_105 * V_106 ;
if ( ! F_8 ( V_86 -> V_107 , & V_51 ) )
continue;
F_53 (set, &ss->cftsets, node)
F_89 ( V_8 , V_86 , V_106 -> V_108 , true ) ;
}
F_67 (cgrp->root, ss) {
struct V_4 * V_5 = V_8 -> V_41 [ V_86 -> V_107 ] ;
if ( V_5 -> V_92 )
F_156 ( V_5 -> V_92 -> V_5 , V_5 ) ;
}
return 0 ;
}
static void F_312 ( struct V_82 * V_83 )
{
struct V_4 * V_5 =
F_66 ( V_83 , struct V_4 , V_418 ) ;
struct V_14 * V_14 = V_5 -> V_7 -> V_14 ;
struct V_69 * V_70 = V_14 -> V_110 ;
F_30 ( & V_70 -> V_419 ) ;
F_83 ( V_14 ) ;
F_68 ( V_70 ) ;
}
static void F_313 ( struct V_4 * V_5 ,
struct V_85 * V_86 ,
struct V_7 * V_8 )
{
V_5 -> V_7 = V_8 ;
F_51 ( & V_5 -> V_2 , 1 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_92 = NULL ;
if ( V_8 == V_124 )
V_5 -> V_10 |= V_420 ;
F_34 ( V_8 -> V_41 [ V_86 -> V_107 ] ) ;
V_8 -> V_41 [ V_86 -> V_107 ] = V_5 ;
F_112 ( & V_5 -> V_418 , F_312 ) ;
}
static int F_314 ( struct V_85 * V_86 , struct V_7 * V_8 )
{
int V_153 = 0 ;
F_85 ( & V_1 ) ;
if ( V_86 -> V_421 )
V_153 = V_86 -> V_421 ( V_8 ) ;
if ( ! V_153 )
V_8 -> V_41 [ V_86 -> V_107 ] -> V_10 |= V_422 ;
return V_153 ;
}
static void F_315 ( struct V_85 * V_86 , struct V_7 * V_8 )
__releases( &cgroup_mutex
static long F_316 ( struct V_7 * V_100 , struct V_14 * V_14 ,
T_1 V_68 )
{
struct V_7 * V_8 ;
struct V_50 * V_48 = V_100 -> V_48 ;
int V_292 = 0 ;
struct V_85 * V_86 ;
struct V_69 * V_70 = V_48 -> V_70 ;
V_8 = F_123 ( sizeof( * V_8 ) , V_53 ) ;
if ( ! V_8 )
return - V_54 ;
V_8 -> V_92 = F_317 ( & V_48 -> V_91 , 1 , 0 , V_53 ) ;
if ( V_8 -> V_92 < 0 )
goto V_423;
if ( ! F_167 ( V_100 ) ) {
V_292 = - V_244 ;
goto V_424;
}
F_30 ( & V_70 -> V_419 ) ;
F_111 ( V_8 ) ;
V_14 -> V_15 = V_8 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_100 = V_100 ;
V_8 -> V_48 = V_100 -> V_48 ;
V_8 -> V_66 = V_100 -> V_66 ;
if ( F_10 ( V_100 ) )
F_24 ( V_13 , & V_8 -> V_10 ) ;
if ( F_8 ( V_134 , & V_100 -> V_10 ) )
F_24 ( V_134 , & V_8 -> V_10 ) ;
F_67 (root, ss) {
struct V_4 * V_5 ;
V_5 = V_86 -> V_425 ( V_8 ) ;
if ( F_135 ( V_5 ) ) {
V_292 = F_136 ( V_5 ) ;
goto V_426;
}
F_313 ( V_5 , V_86 , V_8 ) ;
if ( V_86 -> V_427 ) {
V_292 = F_318 ( V_86 , V_100 , V_8 ) ;
if ( V_292 )
goto V_426;
}
}
V_292 = F_218 ( V_14 , V_183 | V_68 , V_70 ) ;
if ( V_292 < 0 )
goto V_426;
F_85 ( & V_14 -> V_101 -> V_102 ) ;
F_47 ( & V_8 -> V_158 , & V_48 -> V_164 ) ;
F_319 ( & V_8 -> V_125 , & V_8 -> V_100 -> V_157 ) ;
V_48 -> V_88 ++ ;
F_67 (root, ss)
F_80 ( V_14 ) ;
F_67 (root, ss) {
V_292 = F_314 ( V_86 , V_8 ) ;
if ( V_292 )
goto V_428;
if ( V_86 -> V_429 && ! V_86 -> V_430 &&
V_100 -> V_100 ) {
F_108 ( L_25 ,
V_155 -> V_156 , V_155 -> V_241 , V_86 -> V_98 ) ;
if ( ! strcmp ( V_86 -> V_98 , L_26 ) )
F_108 ( L_27 ) ;
V_86 -> V_430 = true ;
}
}
V_292 = F_110 ( V_8 , true , V_48 -> V_51 ) ;
if ( V_292 )
goto V_428;
F_59 ( & V_1 ) ;
F_59 ( & V_8 -> V_14 -> V_101 -> V_102 ) ;
return 0 ;
V_426:
F_67 (root, ss) {
if ( V_8 -> V_41 [ V_86 -> V_107 ] )
V_86 -> V_87 ( V_8 ) ;
}
F_59 ( & V_1 ) ;
F_68 ( V_70 ) ;
V_424:
F_70 ( & V_48 -> V_91 , V_8 -> V_92 ) ;
V_423:
F_27 ( V_8 ) ;
return V_292 ;
V_428:
F_320 ( V_8 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_14 -> V_101 -> V_102 ) ;
return V_292 ;
}
static int F_321 ( struct V_67 * V_103 , struct V_14 * V_14 , T_1 V_68 )
{
struct V_7 * V_431 = V_14 -> V_95 -> V_15 ;
return F_316 ( V_431 , V_14 , V_68 | V_183 ) ;
}
static int F_322 ( struct V_7 * V_8 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_85 * V_86 = V_41 [ V_18 ] ;
struct V_4 * V_5 ;
if ( V_86 == NULL || V_86 -> V_48 != V_8 -> V_48 )
continue;
V_5 = V_8 -> V_41 [ V_86 -> V_107 ] ;
if ( V_5 && F_5 ( V_5 ) > 1 )
return 1 ;
}
return 0 ;
}
static int F_320 ( struct V_7 * V_8 )
__releases( &cgroup_mutex
static int F_323 ( struct V_67 * V_432 , struct V_14 * V_14 )
{
int V_153 ;
F_57 ( & V_1 ) ;
V_153 = F_320 ( V_14 -> V_15 ) ;
F_59 ( & V_1 ) ;
return V_153 ;
}
static void T_11 F_324 ( struct V_85 * V_86 )
{
F_40 ( & V_86 -> V_322 ) ;
if ( V_86 -> V_433 ) {
V_86 -> V_434 . V_108 = V_86 -> V_433 ;
F_47 ( & V_86 -> V_434 . V_97 , & V_86 -> V_322 ) ;
}
}
static void T_12 F_325 ( struct V_85 * V_86 )
{
struct V_4 * V_5 ;
F_326 ( V_435 L_28 , V_86 -> V_98 ) ;
F_57 ( & V_1 ) ;
F_324 ( V_86 ) ;
F_42 ( & V_86 -> V_125 , & V_122 . V_126 ) ;
V_86 -> V_48 = & V_122 ;
V_5 = V_86 -> V_425 ( V_124 ) ;
F_34 ( F_135 ( V_5 ) ) ;
F_313 ( V_5 , V_86 , V_124 ) ;
V_65 . V_41 [ V_86 -> V_107 ] = V_5 ;
V_436 |= V_86 -> V_437 || V_86 -> exit ;
F_34 ( ! F_44 ( & V_438 . V_59 ) ) ;
V_86 -> V_439 = 1 ;
F_34 ( F_314 ( V_86 , V_124 ) ) ;
F_59 ( & V_1 ) ;
F_34 ( V_86 -> V_128 ) ;
}
int T_11 F_327 ( struct V_85 * V_86 )
{
struct V_4 * V_5 ;
int V_18 , V_153 ;
struct V_440 * V_52 ;
struct V_21 * V_22 ;
unsigned long V_19 ;
if ( V_86 -> V_98 == NULL || strlen ( V_86 -> V_98 ) > V_316 ||
V_86 -> V_425 == NULL || V_86 -> V_87 == NULL )
return - V_145 ;
if ( V_86 -> V_437 || V_86 -> exit )
return - V_145 ;
if ( V_86 -> V_128 == NULL ) {
F_34 ( V_41 [ V_86 -> V_107 ] != V_86 ) ;
return 0 ;
}
F_324 ( V_86 ) ;
F_57 ( & V_1 ) ;
V_41 [ V_86 -> V_107 ] = V_86 ;
V_5 = V_86 -> V_425 ( V_124 ) ;
if ( F_135 ( V_5 ) ) {
V_41 [ V_86 -> V_107 ] = NULL ;
F_59 ( & V_1 ) ;
return F_136 ( V_5 ) ;
}
F_42 ( & V_86 -> V_125 , & V_122 . V_126 ) ;
V_86 -> V_48 = & V_122 ;
F_313 ( V_5 , V_86 , V_124 ) ;
if ( V_86 -> V_427 ) {
V_153 = F_328 ( V_86 , V_5 ) ;
if ( V_153 )
goto V_441;
}
F_17 ( & V_28 ) ;
F_329 (css_set_table, i, tmp, cg, hlist) {
if ( V_22 -> V_41 [ V_86 -> V_107 ] )
continue;
F_20 ( & V_22 -> V_29 ) ;
V_22 -> V_41 [ V_86 -> V_107 ] = V_5 ;
V_19 = F_14 ( V_22 -> V_41 ) ;
F_54 ( V_61 , & V_22 -> V_29 , V_19 ) ;
}
F_19 ( & V_28 ) ;
V_86 -> V_439 = 1 ;
V_153 = F_314 ( V_86 , V_124 ) ;
if ( V_153 )
goto V_441;
F_59 ( & V_1 ) ;
return 0 ;
V_441:
F_59 ( & V_1 ) ;
F_330 ( V_86 ) ;
return V_153 ;
}
void F_330 ( struct V_85 * V_86 )
{
struct V_24 * V_25 ;
F_34 ( V_86 -> V_128 == NULL ) ;
F_34 ( V_86 -> V_48 != & V_122 ) ;
F_57 ( & V_1 ) ;
F_315 ( V_86 , V_124 ) ;
V_86 -> V_439 = 0 ;
if ( V_86 -> V_427 )
F_331 ( & V_86 -> V_442 ) ;
V_41 [ V_86 -> V_107 ] = NULL ;
F_87 ( & V_86 -> V_125 ) ;
F_17 ( & V_28 ) ;
F_53 (link, &dummytop->css_sets, cgrp_link_list) {
struct V_21 * V_22 = V_25 -> V_22 ;
unsigned long V_19 ;
F_20 ( & V_22 -> V_29 ) ;
V_22 -> V_41 [ V_86 -> V_107 ] = NULL ;
V_19 = F_14 ( V_22 -> V_41 ) ;
F_54 ( V_61 , & V_22 -> V_29 , V_19 ) ;
}
F_19 ( & V_28 ) ;
V_86 -> V_87 ( V_124 ) ;
V_124 -> V_41 [ V_86 -> V_107 ] = NULL ;
F_59 ( & V_1 ) ;
}
int T_12 F_332 ( void )
{
int V_18 ;
F_51 ( & V_65 . V_27 , 1 ) ;
F_40 ( & V_65 . V_42 ) ;
F_40 ( & V_65 . V_59 ) ;
F_52 ( & V_65 . V_29 ) ;
V_30 = 1 ;
F_116 ( & V_122 ) ;
V_58 = 1 ;
V_438 . V_64 = & V_65 ;
V_443 . V_22 = & V_65 ;
V_443 . V_8 = V_124 ;
F_42 ( & V_443 . V_32 ,
& V_122 . V_66 . V_56 ) ;
F_42 ( & V_443 . V_31 ,
& V_65 . V_42 ) ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_85 * V_86 = V_41 [ V_18 ] ;
if ( ! V_86 || V_86 -> V_128 )
continue;
F_34 ( ! V_86 -> V_98 ) ;
F_34 ( strlen ( V_86 -> V_98 ) > V_316 ) ;
F_34 ( ! V_86 -> V_425 ) ;
F_34 ( ! V_86 -> V_87 ) ;
if ( V_86 -> V_107 != V_18 ) {
F_326 ( V_444 L_29 ,
V_86 -> V_98 , V_86 -> V_107 ) ;
F_333 () ;
}
if ( V_86 -> V_445 )
F_325 ( V_86 ) ;
}
return 0 ;
}
int T_12 F_334 ( void )
{
int V_292 ;
int V_18 ;
unsigned long V_19 ;
V_292 = F_335 ( & V_81 ) ;
if ( V_292 )
return V_292 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_85 * V_86 = V_41 [ V_18 ] ;
if ( ! V_86 || V_86 -> V_128 )
continue;
if ( ! V_86 -> V_445 )
F_325 ( V_86 ) ;
if ( V_86 -> V_427 )
F_328 ( V_86 , V_65 . V_41 [ V_86 -> V_107 ] ) ;
}
V_19 = F_14 ( V_65 . V_41 ) ;
F_54 ( V_61 , & V_65 . V_29 , V_19 ) ;
F_34 ( ! F_117 ( & V_122 ) ) ;
V_446 = F_336 ( L_30 , V_447 ) ;
if ( ! V_446 ) {
V_292 = - V_54 ;
goto V_229;
}
V_292 = F_337 ( & V_448 ) ;
if ( V_292 < 0 ) {
F_338 ( V_446 ) ;
goto V_229;
}
F_339 ( L_31 , 0 , NULL , & V_449 ) ;
V_229:
if ( V_292 )
F_340 ( & V_81 ) ;
return V_292 ;
}
static int F_341 ( struct V_129 * V_285 , void * V_6 )
{
struct V_241 * V_241 ;
struct V_62 * V_221 ;
char * V_205 ;
int V_225 ;
struct V_50 * V_48 ;
V_225 = - V_54 ;
V_205 = F_41 ( V_349 , V_53 ) ;
if ( ! V_205 )
goto V_229;
V_225 = - V_227 ;
V_241 = V_285 -> V_276 ;
V_221 = F_342 ( V_241 , V_450 ) ;
if ( ! V_221 )
goto V_451;
V_225 = 0 ;
F_57 ( & V_1 ) ;
F_138 (root) {
struct V_85 * V_86 ;
struct V_7 * V_8 ;
int V_33 = 0 ;
F_99 ( V_285 , L_32 , V_48 -> V_168 ) ;
F_67 (root, ss)
F_99 ( V_285 , L_33 , V_33 ++ ? L_8 : L_34 , V_86 -> V_98 ) ;
if ( strlen ( V_48 -> V_98 ) )
F_99 ( V_285 , L_35 , V_33 ? L_8 : L_34 ,
V_48 -> V_98 ) ;
F_181 ( V_285 , ':' ) ;
V_8 = F_55 ( V_221 , V_48 ) ;
V_225 = F_145 ( V_8 , V_205 , V_349 ) ;
if ( V_225 < 0 )
goto V_154;
F_100 ( V_285 , V_205 ) ;
F_181 ( V_285 , '\n' ) ;
}
V_154:
F_59 ( & V_1 ) ;
F_175 ( V_221 ) ;
V_451:
F_27 ( V_205 ) ;
V_229:
return V_225 ;
}
static int F_343 ( struct V_67 * V_67 , struct V_257 * V_257 )
{
struct V_241 * V_241 = F_344 ( V_67 ) -> V_241 ;
return F_199 ( V_257 , F_341 , V_241 ) ;
}
static int F_345 ( struct V_129 * V_285 , void * V_6 )
{
int V_18 ;
F_100 ( V_285 , L_36 ) ;
F_57 ( & V_1 ) ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_85 * V_86 = V_41 [ V_18 ] ;
if ( V_86 == NULL )
continue;
F_99 ( V_285 , L_37 ,
V_86 -> V_98 , V_86 -> V_48 -> V_168 ,
V_86 -> V_48 -> V_88 , ! V_86 -> V_151 ) ;
}
F_59 ( & V_1 ) ;
return 0 ;
}
static int F_346 ( struct V_67 * V_67 , struct V_257 * V_257 )
{
return F_199 ( V_257 , F_345 , NULL ) ;
}
void F_347 ( struct V_62 * V_452 )
{
F_155 ( V_155 ) ;
V_452 -> V_64 = V_155 -> V_64 ;
F_29 ( V_452 -> V_64 ) ;
F_157 ( V_155 ) ;
F_40 ( & V_452 -> V_224 ) ;
}
void F_348 ( struct V_62 * V_452 )
{
int V_18 ;
if ( V_329 ) {
F_17 ( & V_28 ) ;
F_155 ( V_452 ) ;
if ( F_44 ( & V_452 -> V_224 ) )
F_42 ( & V_452 -> V_224 , & V_452 -> V_64 -> V_59 ) ;
F_157 ( V_452 ) ;
F_19 ( & V_28 ) ;
}
if ( V_436 ) {
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_85 * V_86 = V_41 [ V_18 ] ;
if ( ! V_86 || V_86 -> V_128 )
continue;
if ( V_86 -> V_437 )
V_86 -> V_437 ( V_452 ) ;
}
}
}
void F_349 ( struct V_62 * V_221 , int V_453 )
{
struct V_21 * V_22 ;
int V_18 ;
if ( ! F_44 ( & V_221 -> V_224 ) ) {
F_17 ( & V_28 ) ;
if ( ! F_44 ( & V_221 -> V_224 ) )
F_87 ( & V_221 -> V_224 ) ;
F_19 ( & V_28 ) ;
}
F_155 ( V_221 ) ;
V_22 = V_221 -> V_64 ;
V_221 -> V_64 = & V_65 ;
if ( V_453 && V_436 ) {
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_85 * V_86 = V_41 [ V_18 ] ;
if ( ! V_86 || V_86 -> V_128 )
continue;
if ( V_86 -> exit ) {
struct V_7 * V_454 =
F_350 ( V_22 -> V_41 [ V_18 ] ) -> V_7 ;
struct V_7 * V_8 = F_351 ( V_221 , V_18 ) ;
V_86 -> exit ( V_8 , V_454 , V_221 ) ;
}
}
}
F_157 ( V_221 ) ;
F_32 ( V_22 ) ;
}
int F_352 ( const struct V_7 * V_8 , struct V_62 * V_63 )
{
int V_153 ;
struct V_7 * V_455 ;
if ( V_8 == V_124 )
return 1 ;
V_455 = F_55 ( V_63 , V_8 -> V_48 ) ;
while ( V_8 != V_455 && V_8 != V_8 -> V_66 )
V_8 = V_8 -> V_100 ;
V_153 = ( V_8 == V_455 ) ;
return V_153 ;
}
static void F_25 ( struct V_7 * V_8 )
{
if ( F_9 ( V_8 ) && ! F_6 ( & V_8 -> V_33 )
&& F_44 ( & V_8 -> V_157 ) && ! F_322 ( V_8 ) ) {
int V_456 = 0 ;
F_353 ( & V_457 ) ;
if ( ! F_7 ( V_8 ) &&
F_44 ( & V_8 -> V_159 ) ) {
F_42 ( & V_8 -> V_159 , & V_159 ) ;
V_456 = 1 ;
}
F_354 ( & V_457 ) ;
if ( V_456 )
F_72 ( & V_458 ) ;
}
}
bool F_355 ( struct V_4 * V_5 )
{
while ( true ) {
int V_459 , V_6 ;
V_6 = F_5 ( V_5 ) ;
V_459 = F_356 ( & V_5 -> V_2 , V_6 , V_6 + 1 ) ;
if ( F_357 ( V_459 == V_6 ) )
return true ;
else if ( V_459 < 0 )
return false ;
F_358 () ;
}
}
void F_359 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_7 ;
int V_6 ;
F_23 () ;
V_6 = F_4 ( F_360 ( & V_5 -> V_2 ) ) ;
switch ( V_6 ) {
case 1 :
if ( F_10 ( V_8 ) ) {
F_24 ( V_12 , & V_8 -> V_10 ) ;
F_25 ( V_8 ) ;
}
break;
case 0 :
F_72 ( & V_5 -> V_418 ) ;
break;
}
F_26 () ;
}
static void F_361 ( struct V_82 * V_83 )
{
F_34 ( V_83 != & V_458 ) ;
F_57 ( & V_1 ) ;
F_353 ( & V_457 ) ;
while ( ! F_44 ( & V_159 ) ) {
char * V_460 [ 3 ] , * V_461 [ 3 ] ;
int V_18 ;
char * V_462 = NULL , * V_463 = NULL ;
struct V_7 * V_8 = F_35 ( V_159 . V_47 ,
struct V_7 ,
V_159 ) ;
F_87 ( & V_8 -> V_159 ) ;
F_354 ( & V_457 ) ;
V_462 = F_41 ( V_349 , V_53 ) ;
if ( ! V_462 )
goto V_464;
if ( F_145 ( V_8 , V_462 , V_349 ) < 0 )
goto V_464;
V_463 = F_362 ( V_8 -> V_48 -> V_133 , V_53 ) ;
if ( ! V_463 )
goto V_464;
V_18 = 0 ;
V_460 [ V_18 ++ ] = V_463 ;
V_460 [ V_18 ++ ] = V_462 ;
V_460 [ V_18 ] = NULL ;
V_18 = 0 ;
V_461 [ V_18 ++ ] = L_38 ;
V_461 [ V_18 ++ ] = L_39 ;
V_461 [ V_18 ] = NULL ;
F_59 ( & V_1 ) ;
F_363 ( V_460 [ 0 ] , V_460 , V_461 , V_465 ) ;
F_57 ( & V_1 ) ;
V_464:
F_27 ( V_462 ) ;
F_27 ( V_463 ) ;
F_353 ( & V_457 ) ;
}
F_354 ( & V_457 ) ;
F_59 ( & V_1 ) ;
}
static int T_12 F_364 ( char * V_466 )
{
int V_18 ;
char * V_138 ;
while ( ( V_138 = F_103 ( & V_466 , L_8 ) ) != NULL ) {
if ( ! * V_138 )
continue;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_85 * V_86 = V_41 [ V_18 ] ;
if ( ! V_86 || V_86 -> V_128 )
continue;
if ( ! strcmp ( V_138 , V_86 -> V_98 ) ) {
V_86 -> V_151 = 1 ;
F_326 ( V_435 L_40
L_41 , V_86 -> V_98 ) ;
break;
}
}
}
return 1 ;
}
unsigned short F_365 ( struct V_4 * V_5 )
{
struct F_365 * V_467 ;
V_467 = F_366 ( V_5 -> V_92 , F_5 ( V_5 ) ) ;
if ( V_467 )
return V_467 -> V_92 ;
return 0 ;
}
unsigned short F_367 ( struct V_4 * V_5 )
{
struct F_365 * V_467 ;
V_467 = F_366 ( V_5 -> V_92 , F_5 ( V_5 ) ) ;
if ( V_467 )
return V_467 -> V_468 ;
return 0 ;
}
bool F_368 ( struct V_4 * V_452 ,
const struct V_4 * V_48 )
{
struct F_365 * V_469 ;
struct F_365 * V_470 ;
V_469 = F_369 ( V_452 -> V_92 ) ;
if ( ! V_469 )
return false ;
V_470 = F_369 ( V_48 -> V_92 ) ;
if ( ! V_470 )
return false ;
if ( V_469 -> V_468 < V_470 -> V_468 )
return false ;
if ( V_469 -> V_471 [ V_470 -> V_468 ] != V_470 -> V_92 )
return false ;
return true ;
}
void F_370 ( struct V_85 * V_86 , struct V_4 * V_5 )
{
struct F_365 * V_92 = V_5 -> V_92 ;
if ( ! V_92 )
return;
F_34 ( ! V_86 -> V_427 ) ;
F_156 ( V_92 -> V_5 , NULL ) ;
F_156 ( V_5 -> V_92 , NULL ) ;
F_91 ( & V_86 -> V_472 ) ;
F_371 ( & V_86 -> V_442 , V_92 -> V_92 ) ;
F_93 ( & V_86 -> V_472 ) ;
F_28 ( V_92 , V_34 ) ;
}
static struct F_365 * F_372 ( struct V_85 * V_86 , int V_468 )
{
struct F_365 * V_473 ;
int V_153 , V_310 ;
F_34 ( ! V_86 -> V_427 ) ;
V_310 = sizeof( * V_473 ) + sizeof( unsigned short ) * ( V_468 + 1 ) ;
V_473 = F_123 ( V_310 , V_53 ) ;
if ( ! V_473 )
return F_124 ( - V_54 ) ;
F_373 ( V_53 ) ;
F_91 ( & V_86 -> V_472 ) ;
V_153 = F_374 ( & V_86 -> V_442 , V_473 , 1 , V_474 + 1 , V_475 ) ;
F_93 ( & V_86 -> V_472 ) ;
F_375 () ;
if ( V_153 < 0 )
goto V_476;
V_473 -> V_92 = V_153 ;
V_473 -> V_468 = V_468 ;
return V_473 ;
V_476:
F_27 ( V_473 ) ;
return F_124 ( V_153 ) ;
}
static int T_11 F_328 ( struct V_85 * V_86 ,
struct V_4 * V_477 )
{
struct F_365 * V_473 ;
F_114 ( & V_86 -> V_472 ) ;
F_376 ( & V_86 -> V_442 ) ;
V_473 = F_372 ( V_86 , 0 ) ;
if ( F_135 ( V_473 ) )
return F_136 ( V_473 ) ;
V_473 -> V_471 [ 0 ] = V_473 -> V_92 ;
V_473 -> V_5 = V_477 ;
V_477 -> V_92 = V_473 ;
return 0 ;
}
static int F_318 ( struct V_85 * V_86 , struct V_7 * V_100 ,
struct V_7 * V_452 )
{
int V_107 , V_18 , V_468 = 0 ;
struct V_4 * V_478 , * V_479 ;
struct F_365 * V_469 , * V_480 ;
V_107 = V_86 -> V_107 ;
V_478 = V_100 -> V_41 [ V_107 ] ;
V_479 = V_452 -> V_41 [ V_107 ] ;
V_480 = V_478 -> V_92 ;
V_468 = V_480 -> V_468 + 1 ;
V_469 = F_372 ( V_86 , V_468 ) ;
if ( F_135 ( V_469 ) )
return F_136 ( V_469 ) ;
for ( V_18 = 0 ; V_18 < V_468 ; V_18 ++ )
V_469 -> V_471 [ V_18 ] = V_480 -> V_471 [ V_18 ] ;
V_469 -> V_471 [ V_468 ] = V_469 -> V_92 ;
F_156 ( V_479 -> V_92 , V_469 ) ;
return 0 ;
}
struct V_4 * F_377 ( struct V_85 * V_86 , int V_92 )
{
struct F_365 * V_467 = NULL ;
F_34 ( ! V_86 -> V_427 ) ;
V_467 = F_378 ( & V_86 -> V_442 , V_92 ) ;
if ( F_269 ( ! V_467 ) )
return NULL ;
return F_369 ( V_467 -> V_5 ) ;
}
struct V_4 *
F_379 ( struct V_85 * V_86 , int V_92 ,
struct V_4 * V_48 , int * V_481 )
{
struct V_4 * V_153 = NULL ;
struct F_365 * V_52 ;
int V_482 ;
int V_483 = F_365 ( V_48 ) ;
int V_468 = F_367 ( V_48 ) ;
if ( ! V_483 )
return NULL ;
F_34 ( ! V_86 -> V_427 ) ;
F_154 ( ! F_147 () ) ;
V_482 = V_92 ;
while ( 1 ) {
V_52 = F_380 ( & V_86 -> V_442 , & V_482 ) ;
if ( ! V_52 )
break;
if ( V_52 -> V_468 >= V_468 && V_52 -> V_471 [ V_468 ] == V_483 ) {
V_153 = F_369 ( V_52 -> V_5 ) ;
if ( V_153 ) {
* V_481 = V_482 ;
break;
}
}
V_482 = V_482 + 1 ;
}
return V_153 ;
}
struct V_4 * F_381 ( struct V_257 * V_484 , int V_92 )
{
struct V_7 * V_8 ;
struct V_67 * V_67 ;
struct V_4 * V_5 ;
V_67 = F_217 ( V_484 ) ;
if ( V_67 -> V_189 != & V_190 )
return F_124 ( - V_414 ) ;
if ( V_92 < 0 || V_92 >= V_20 )
return F_124 ( - V_145 ) ;
V_8 = F_11 ( V_484 -> V_273 ) ;
V_5 = V_8 -> V_41 [ V_92 ] ;
return V_5 ? V_5 : F_124 ( - V_152 ) ;
}
static struct V_4 * F_382 ( struct V_7 * V_485 )
{
struct V_4 * V_5 = F_123 ( sizeof( * V_5 ) , V_53 ) ;
if ( ! V_5 )
return F_124 ( - V_54 ) ;
return V_5 ;
}
static void F_383 ( struct V_7 * V_485 )
{
F_27 ( V_485 -> V_41 [ V_486 ] ) ;
}
static T_2 F_384 ( struct V_7 * V_485 , struct V_17 * V_96 )
{
return F_6 ( & V_485 -> V_33 ) ;
}
static T_2 F_385 ( struct V_7 * V_485 , struct V_17 * V_96 )
{
return F_230 ( V_485 ) ;
}
static T_2 F_386 ( struct V_7 * V_485 , struct V_17 * V_96 )
{
return ( T_2 ) ( unsigned long ) V_155 -> V_64 ;
}
static T_2 F_387 ( struct V_7 * V_485 ,
struct V_17 * V_96 )
{
T_2 V_33 ;
F_23 () ;
V_33 = F_6 ( & V_155 -> V_64 -> V_27 ) ;
F_26 () ;
return V_33 ;
}
static int F_388 ( struct V_7 * V_485 ,
struct V_17 * V_96 ,
struct V_129 * V_130 )
{
struct V_24 * V_25 ;
struct V_21 * V_22 ;
F_49 ( & V_28 ) ;
F_23 () ;
V_22 = F_369 ( V_155 -> V_64 ) ;
F_53 (link, &cg->cg_links, cg_link_list) {
struct V_7 * V_60 = V_25 -> V_8 ;
const char * V_98 ;
if ( V_60 -> V_14 )
V_98 = V_60 -> V_14 -> V_209 . V_98 ;
else
V_98 = L_42 ;
F_99 ( V_130 , L_43 ,
V_60 -> V_48 -> V_168 , V_98 ) ;
}
F_26 () ;
F_50 ( & V_28 ) ;
return 0 ;
}
static int F_389 ( struct V_7 * V_485 ,
struct V_17 * V_96 ,
struct V_129 * V_130 )
{
struct V_24 * V_25 ;
F_49 ( & V_28 ) ;
F_53 (link, &cont->css_sets, cgrp_link_list) {
struct V_21 * V_22 = V_25 -> V_22 ;
struct V_62 * V_63 ;
int V_33 = 0 ;
F_99 ( V_130 , L_44 , V_22 ) ;
F_53 (task, &cg->tasks, cg_list) {
if ( V_33 ++ > V_487 ) {
F_100 ( V_130 , L_45 ) ;
break;
} else {
F_99 ( V_130 , L_46 ,
F_271 ( V_63 ) ) ;
}
}
}
F_50 ( & V_28 ) ;
return 0 ;
}
static T_2 F_390 ( struct V_7 * V_8 , struct V_17 * V_96 )
{
return F_8 ( V_12 , & V_8 -> V_10 ) ;
}
