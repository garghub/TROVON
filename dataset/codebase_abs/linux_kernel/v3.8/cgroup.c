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
static struct V_18 * F_14 ( struct V_4 * V_5 [] )
{
int V_19 ;
int V_20 ;
unsigned long V_21 = 0UL ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
V_21 += ( unsigned long ) V_5 [ V_19 ] ;
V_21 = ( V_21 >> 16 ) ^ V_21 ;
V_20 = F_15 ( V_21 , V_23 ) ;
return & V_24 [ V_20 ] ;
}
static void F_16 ( struct V_25 * V_26 , int V_27 )
{
struct V_28 * V_29 ;
struct V_28 * V_30 ;
if ( F_17 ( & V_26 -> V_31 , - 1 , 1 ) )
return;
F_18 ( & V_32 ) ;
if ( ! F_19 ( & V_26 -> V_31 ) ) {
F_20 ( & V_32 ) ;
return;
}
F_21 ( & V_26 -> V_33 ) ;
V_34 -- ;
F_22 (link, saved_link, &cg->cg_links,
cg_link_list) {
struct V_7 * V_8 = V_29 -> V_8 ;
F_23 ( & V_29 -> V_35 ) ;
F_23 ( & V_29 -> V_36 ) ;
if ( F_19 ( & V_8 -> V_37 ) &&
F_10 ( V_8 ) ) {
if ( V_27 )
F_24 ( V_12 , & V_8 -> V_10 ) ;
F_25 ( V_8 ) ;
}
F_26 ( V_29 ) ;
}
F_20 ( & V_32 ) ;
F_27 ( V_26 , V_38 ) ;
}
static inline void F_28 ( struct V_25 * V_26 )
{
F_29 ( & V_26 -> V_31 ) ;
}
static inline void F_30 ( struct V_25 * V_26 )
{
F_16 ( V_26 , 0 ) ;
}
static inline void F_31 ( struct V_25 * V_26 )
{
F_16 ( V_26 , 1 ) ;
}
static bool F_32 ( struct V_25 * V_26 ,
struct V_25 * V_39 ,
struct V_7 * V_40 ,
struct V_4 * V_41 [] )
{
struct V_42 * V_43 , * V_44 ;
if ( memcmp ( V_41 , V_26 -> V_45 , sizeof( V_26 -> V_45 ) ) ) {
return false ;
}
V_43 = & V_26 -> V_46 ;
V_44 = & V_39 -> V_46 ;
while ( 1 ) {
struct V_28 * V_47 , * V_48 ;
struct V_7 * V_49 , * V_50 ;
V_43 = V_43 -> V_51 ;
V_44 = V_44 -> V_51 ;
if ( V_43 == & V_26 -> V_46 ) {
F_33 ( V_44 != & V_39 -> V_46 ) ;
break;
} else {
F_33 ( V_44 == & V_39 -> V_46 ) ;
}
V_47 = F_34 ( V_43 , struct V_28 , V_35 ) ;
V_48 = F_34 ( V_44 , struct V_28 , V_35 ) ;
V_49 = V_47 -> V_8 ;
V_50 = V_48 -> V_8 ;
F_33 ( V_49 -> V_52 != V_50 -> V_52 ) ;
if ( V_49 -> V_52 == V_40 -> V_52 ) {
if ( V_49 != V_40 )
return false ;
} else {
if ( V_49 != V_50 )
return false ;
}
}
return true ;
}
static struct V_25 * F_35 (
struct V_25 * V_53 ,
struct V_7 * V_8 ,
struct V_4 * V_41 [] )
{
int V_19 ;
struct V_54 * V_52 = V_8 -> V_52 ;
struct V_18 * V_55 ;
struct V_56 * V_57 ;
struct V_25 * V_26 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
if ( V_52 -> V_58 & ( 1UL << V_19 ) ) {
V_41 [ V_19 ] = V_8 -> V_45 [ V_19 ] ;
} else {
V_41 [ V_19 ] = V_53 -> V_45 [ V_19 ] ;
}
}
V_55 = F_14 ( V_41 ) ;
F_36 (cg, node, hhead, hlist) {
if ( ! F_32 ( V_26 , V_53 , V_8 , V_41 ) )
continue;
return V_26 ;
}
return NULL ;
}
static void F_37 ( struct V_42 * V_21 )
{
struct V_28 * V_29 ;
struct V_28 * V_30 ;
F_22 (link, saved_link, tmp, cgrp_link_list) {
F_23 ( & V_29 -> V_36 ) ;
F_26 ( V_29 ) ;
}
}
static int F_38 ( int V_37 , struct V_42 * V_21 )
{
struct V_28 * V_29 ;
int V_19 ;
F_39 ( V_21 ) ;
for ( V_19 = 0 ; V_19 < V_37 ; V_19 ++ ) {
V_29 = F_40 ( sizeof( * V_29 ) , V_59 ) ;
if ( ! V_29 ) {
F_37 ( V_21 ) ;
return - V_60 ;
}
F_41 ( & V_29 -> V_36 , V_21 ) ;
}
return 0 ;
}
static void F_42 ( struct V_42 * V_61 ,
struct V_25 * V_26 , struct V_7 * V_8 )
{
struct V_28 * V_29 ;
F_33 ( F_43 ( V_61 ) ) ;
V_29 = F_44 ( V_61 , struct V_28 ,
V_36 ) ;
V_29 -> V_26 = V_26 ;
V_29 -> V_8 = V_8 ;
F_29 ( & V_8 -> V_37 ) ;
F_45 ( & V_29 -> V_36 , & V_8 -> V_62 ) ;
F_46 ( & V_29 -> V_35 , & V_26 -> V_46 ) ;
}
static struct V_25 * F_47 (
struct V_25 * V_53 , struct V_7 * V_8 )
{
struct V_25 * V_63 ;
struct V_4 * V_41 [ V_22 ] ;
struct V_42 V_61 ;
struct V_18 * V_55 ;
struct V_28 * V_29 ;
F_48 ( & V_32 ) ;
V_63 = F_35 ( V_53 , V_8 , V_41 ) ;
if ( V_63 )
F_28 ( V_63 ) ;
F_49 ( & V_32 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_40 ( sizeof( * V_63 ) , V_59 ) ;
if ( ! V_63 )
return NULL ;
if ( F_38 ( V_64 , & V_61 ) < 0 ) {
F_26 ( V_63 ) ;
return NULL ;
}
F_50 ( & V_63 -> V_31 , 1 ) ;
F_39 ( & V_63 -> V_46 ) ;
F_39 ( & V_63 -> V_65 ) ;
F_51 ( & V_63 -> V_33 ) ;
memcpy ( V_63 -> V_45 , V_41 , sizeof( V_63 -> V_45 ) ) ;
F_18 ( & V_32 ) ;
F_52 (link, &oldcg->cg_links, cg_link_list) {
struct V_7 * V_66 = V_29 -> V_8 ;
if ( V_66 -> V_52 == V_8 -> V_52 )
V_66 = V_8 ;
F_42 ( & V_61 , V_63 , V_66 ) ;
}
F_33 ( ! F_43 ( & V_61 ) ) ;
V_34 ++ ;
V_55 = F_14 ( V_63 -> V_45 ) ;
F_53 ( & V_63 -> V_33 , V_55 ) ;
F_20 ( & V_32 ) ;
return V_63 ;
}
static struct V_7 * F_54 ( struct V_67 * V_68 ,
struct V_54 * V_52 )
{
struct V_25 * V_5 ;
struct V_7 * V_63 = NULL ;
F_33 ( ! F_3 ( & V_1 ) ) ;
F_48 ( & V_32 ) ;
V_5 = V_68 -> V_69 ;
if ( V_5 == & V_70 ) {
V_63 = & V_52 -> V_71 ;
} else {
struct V_28 * V_29 ;
F_52 (link, &css->cg_links, cg_link_list) {
struct V_7 * V_66 = V_29 -> V_8 ;
if ( V_66 -> V_52 == V_52 ) {
V_63 = V_66 ;
break;
}
}
}
F_49 ( & V_32 ) ;
F_33 ( ! V_63 ) ;
return V_63 ;
}
void F_55 ( void )
{
F_56 ( & V_1 ) ;
}
void F_57 ( void )
{
F_58 ( & V_1 ) ;
}
static struct V_72 * F_59 ( T_1 V_73 , struct V_74 * V_75 )
{
struct V_72 * V_72 = F_60 ( V_75 ) ;
if ( V_72 ) {
V_72 -> V_76 = F_61 () ;
V_72 -> V_77 = V_73 ;
V_72 -> V_78 = F_62 () ;
V_72 -> V_79 = F_63 () ;
V_72 -> V_80 = V_72 -> V_81 = V_72 -> V_82 = V_83 ;
V_72 -> V_84 -> V_85 = & V_86 ;
}
return V_72 ;
}
static void F_64 ( struct V_14 * V_14 , struct V_72 * V_72 )
{
if ( F_65 ( V_72 -> V_77 ) ) {
struct V_7 * V_8 = V_14 -> V_15 ;
struct V_87 * V_88 ;
F_33 ( ! ( F_7 ( V_8 ) ) ) ;
F_66 () ;
F_56 ( & V_1 ) ;
F_67 (cgrp->root, ss)
V_88 -> V_89 ( V_8 ) ;
V_8 -> V_52 -> V_90 -- ;
F_58 ( & V_1 ) ;
F_68 ( V_8 -> V_52 -> V_75 ) ;
F_33 ( ! F_43 ( & V_8 -> V_91 ) ) ;
F_69 ( & V_8 -> V_92 ) ;
F_70 ( & V_8 -> V_52 -> V_93 , V_8 -> V_94 ) ;
F_27 ( V_8 , V_38 ) ;
} else {
struct V_16 * V_95 = F_12 ( V_14 ) ;
struct V_7 * V_8 = V_14 -> V_96 -> V_15 ;
struct V_17 * V_97 = V_95 -> type ;
F_71 ( ! F_43 ( & V_95 -> V_57 ) &&
V_8 != & V_8 -> V_52 -> V_71 ,
L_1 , V_95 -> type -> V_98 ) ;
F_26 ( V_95 ) ;
F_69 ( & V_97 -> V_92 ) ;
}
F_72 ( V_72 ) ;
}
static int F_73 ( const struct V_14 * V_99 )
{
return 1 ;
}
static void F_74 ( struct V_14 * V_99 )
{
struct V_14 * V_100 = F_75 ( V_99 -> V_96 ) ;
F_76 ( V_99 ) ;
F_77 ( V_100 -> V_101 , V_99 ) ;
F_78 ( V_100 ) ;
}
static int F_79 ( struct V_7 * V_8 , const struct V_17 * V_97 )
{
struct V_16 * V_95 ;
F_80 ( & V_8 -> V_14 -> V_101 -> V_102 ) ;
F_80 ( & V_1 ) ;
F_52 (cfe, &cgrp->files, node) {
struct V_14 * V_99 = V_95 -> V_14 ;
if ( V_97 && V_95 -> type != V_97 )
continue;
F_75 ( V_99 ) ;
F_76 ( V_99 ) ;
F_81 ( V_8 -> V_14 -> V_101 , V_99 ) ;
F_82 ( & V_95 -> V_57 ) ;
F_78 ( V_99 ) ;
return 0 ;
}
return - V_103 ;
}
static void F_83 ( struct V_14 * V_104 , bool V_105 ,
unsigned long V_58 )
{
struct V_7 * V_8 = F_11 ( V_104 ) ;
struct V_87 * V_88 ;
F_67 (cgrp->root, ss) {
struct V_106 * V_107 ;
if ( ! F_8 ( V_88 -> V_108 , & V_58 ) )
continue;
F_52 (set, &ss->cftsets, node)
F_84 ( V_8 , NULL , V_107 -> V_109 , false ) ;
}
if ( V_105 ) {
while ( ! F_43 ( & V_8 -> V_110 ) )
F_79 ( V_8 , NULL ) ;
}
}
static void F_85 ( struct V_14 * V_14 )
{
struct V_14 * V_100 ;
struct V_54 * V_52 = V_14 -> V_111 -> V_112 ;
F_83 ( V_14 , true , V_52 -> V_58 ) ;
V_100 = V_14 -> V_96 ;
F_86 ( & V_100 -> V_113 ) ;
F_87 ( & V_14 -> V_113 , V_114 ) ;
F_82 ( & V_14 -> V_115 . V_116 ) ;
F_88 ( & V_14 -> V_113 ) ;
F_88 ( & V_100 -> V_113 ) ;
F_74 ( V_14 ) ;
}
static int F_89 ( struct V_54 * V_52 ,
unsigned long V_117 )
{
unsigned long V_118 , V_119 ;
struct V_7 * V_8 = & V_52 -> V_71 ;
int V_19 ;
F_33 ( ! F_3 ( & V_1 ) ) ;
F_33 ( ! F_3 ( & V_120 ) ) ;
V_119 = V_52 -> V_121 & ~ V_117 ;
V_118 = V_117 & ~ V_52 -> V_121 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
unsigned long V_122 = 1UL << V_19 ;
struct V_87 * V_88 = V_45 [ V_19 ] ;
if ( ! ( V_122 & V_118 ) )
continue;
F_33 ( V_88 == NULL ) ;
if ( V_88 -> V_52 != & V_123 ) {
return - V_124 ;
}
}
if ( V_52 -> V_90 > 1 )
return - V_124 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
struct V_87 * V_88 = V_45 [ V_19 ] ;
unsigned long V_122 = 1UL << V_19 ;
if ( V_122 & V_118 ) {
F_33 ( V_88 == NULL ) ;
F_33 ( V_8 -> V_45 [ V_19 ] ) ;
F_33 ( ! V_125 -> V_45 [ V_19 ] ) ;
F_33 ( V_125 -> V_45 [ V_19 ] -> V_7 != V_125 ) ;
V_8 -> V_45 [ V_19 ] = V_125 -> V_45 [ V_19 ] ;
V_8 -> V_45 [ V_19 ] -> V_7 = V_8 ;
F_45 ( & V_88 -> V_126 , & V_52 -> V_127 ) ;
V_88 -> V_52 = V_52 ;
if ( V_88 -> V_128 )
V_88 -> V_128 ( V_8 ) ;
} else if ( V_122 & V_119 ) {
F_33 ( V_88 == NULL ) ;
F_33 ( V_8 -> V_45 [ V_19 ] != V_125 -> V_45 [ V_19 ] ) ;
F_33 ( V_8 -> V_45 [ V_19 ] -> V_7 != V_8 ) ;
if ( V_88 -> V_128 )
V_88 -> V_128 ( V_125 ) ;
V_125 -> V_45 [ V_19 ] -> V_7 = V_125 ;
V_8 -> V_45 [ V_19 ] = NULL ;
V_45 [ V_19 ] -> V_52 = & V_123 ;
F_45 ( & V_88 -> V_126 , & V_123 . V_127 ) ;
F_90 ( V_88 -> V_129 ) ;
} else if ( V_122 & V_117 ) {
F_33 ( V_88 == NULL ) ;
F_33 ( ! V_8 -> V_45 [ V_19 ] ) ;
F_90 ( V_88 -> V_129 ) ;
#ifdef F_91
F_33 ( V_88 -> V_129 && ! F_92 ( V_88 -> V_129 ) ) ;
#endif
} else {
F_33 ( V_8 -> V_45 [ V_19 ] ) ;
}
}
V_52 -> V_58 = V_52 -> V_121 = V_117 ;
F_66 () ;
return 0 ;
}
static int F_93 ( struct V_130 * V_131 , struct V_14 * V_14 )
{
struct V_54 * V_52 = V_14 -> V_111 -> V_112 ;
struct V_87 * V_88 ;
F_56 ( & V_120 ) ;
F_67 (root, ss)
F_94 ( V_131 , L_2 , V_88 -> V_98 ) ;
if ( F_8 ( V_132 , & V_52 -> V_10 ) )
F_95 ( V_131 , L_3 ) ;
if ( F_8 ( V_133 , & V_52 -> V_10 ) )
F_95 ( V_131 , L_4 ) ;
if ( strlen ( V_52 -> V_134 ) )
F_94 ( V_131 , L_5 , V_52 -> V_134 ) ;
if ( F_8 ( V_135 , & V_52 -> V_71 . V_10 ) )
F_95 ( V_131 , L_6 ) ;
if ( strlen ( V_52 -> V_98 ) )
F_94 ( V_131 , L_7 , V_52 -> V_98 ) ;
F_58 ( & V_120 ) ;
return 0 ;
}
static int F_96 ( char * V_136 , struct V_137 * V_138 )
{
char * V_139 , * V_140 = V_136 ;
bool V_141 = false , V_142 = false ;
unsigned long V_143 = ( unsigned long ) - 1 ;
int V_19 ;
bool V_144 = false ;
F_33 ( ! F_3 ( & V_1 ) ) ;
#ifdef F_97
V_143 = ~ ( 1UL << V_145 ) ;
#endif
memset ( V_138 , 0 , sizeof( * V_138 ) ) ;
while ( ( V_139 = F_98 ( & V_140 , L_8 ) ) != NULL ) {
if ( ! * V_139 )
return - V_146 ;
if ( ! strcmp ( V_139 , L_9 ) ) {
V_138 -> V_147 = true ;
continue;
}
if ( ! strcmp ( V_139 , L_10 ) ) {
if ( V_142 )
return - V_146 ;
V_141 = true ;
continue;
}
if ( ! strcmp ( V_139 , L_11 ) ) {
F_24 ( V_132 , & V_138 -> V_10 ) ;
continue;
}
if ( ! strcmp ( V_139 , L_12 ) ) {
V_138 -> V_148 = true ;
continue;
}
if ( ! strcmp ( V_139 , L_13 ) ) {
F_24 ( V_133 , & V_138 -> V_10 ) ;
continue;
}
if ( ! strncmp ( V_139 , L_14 , 14 ) ) {
if ( V_138 -> V_149 )
return - V_146 ;
V_138 -> V_149 =
F_99 ( V_139 + 14 , V_150 - 1 , V_59 ) ;
if ( ! V_138 -> V_149 )
return - V_60 ;
continue;
}
if ( ! strncmp ( V_139 , L_15 , 5 ) ) {
const char * V_98 = V_139 + 5 ;
if ( ! strlen ( V_98 ) )
return - V_146 ;
for ( V_19 = 0 ; V_19 < strlen ( V_98 ) ; V_19 ++ ) {
char V_66 = V_98 [ V_19 ] ;
if ( isalnum ( V_66 ) )
continue;
if ( ( V_66 == '.' ) || ( V_66 == '-' ) || ( V_66 == '_' ) )
continue;
return - V_146 ;
}
if ( V_138 -> V_98 )
return - V_146 ;
V_138 -> V_98 = F_99 ( V_98 ,
V_151 - 1 ,
V_59 ) ;
if ( ! V_138 -> V_98 )
return - V_60 ;
continue;
}
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
struct V_87 * V_88 = V_45 [ V_19 ] ;
if ( V_88 == NULL )
continue;
if ( strcmp ( V_139 , V_88 -> V_98 ) )
continue;
if ( V_88 -> V_152 )
continue;
if ( V_141 )
return - V_146 ;
F_24 ( V_19 , & V_138 -> V_58 ) ;
V_142 = true ;
break;
}
if ( V_19 == V_22 )
return - V_103 ;
}
if ( V_141 || ( ! V_142 && ! V_138 -> V_147 && ! V_138 -> V_98 ) ) {
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
struct V_87 * V_88 = V_45 [ V_19 ] ;
if ( V_88 == NULL )
continue;
if ( V_88 -> V_152 )
continue;
F_24 ( V_19 , & V_138 -> V_58 ) ;
}
}
if ( F_8 ( V_132 , & V_138 -> V_10 ) &&
( V_138 -> V_58 & V_143 ) )
return - V_146 ;
if ( V_138 -> V_58 && V_138 -> V_147 )
return - V_146 ;
if ( ! V_138 -> V_58 && ! V_138 -> V_98 )
return - V_146 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
unsigned long V_122 = 1UL << V_19 ;
if ( ! ( V_122 & V_138 -> V_58 ) )
continue;
if ( ! F_100 ( V_45 [ V_19 ] -> V_129 ) ) {
V_144 = true ;
break;
}
}
if ( V_144 ) {
for ( V_19 -- ; V_19 >= 0 ; V_19 -- ) {
unsigned long V_122 = 1UL << V_19 ;
if ( ! ( V_122 & V_138 -> V_58 ) )
continue;
F_90 ( V_45 [ V_19 ] -> V_129 ) ;
}
return - V_103 ;
}
return 0 ;
}
static void F_101 ( unsigned long V_58 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
unsigned long V_122 = 1UL << V_19 ;
if ( ! ( V_122 & V_58 ) )
continue;
F_90 ( V_45 [ V_19 ] -> V_129 ) ;
}
}
static int F_102 ( struct V_74 * V_75 , int * V_10 , char * V_136 )
{
int V_153 = 0 ;
struct V_54 * V_52 = V_75 -> V_112 ;
struct V_7 * V_8 = & V_52 -> V_71 ;
struct V_137 V_138 ;
unsigned long V_118 , V_119 ;
F_56 ( & V_8 -> V_14 -> V_101 -> V_102 ) ;
F_56 ( & V_1 ) ;
F_56 ( & V_120 ) ;
V_153 = F_96 ( V_136 , & V_138 ) ;
if ( V_153 )
goto V_154;
if ( V_138 . V_58 != V_52 -> V_121 || V_138 . V_149 )
F_103 ( L_16 ,
F_104 ( V_155 ) , V_155 -> V_156 ) ;
V_118 = V_138 . V_58 & ~ V_52 -> V_58 ;
V_119 = V_52 -> V_58 & ~ V_138 . V_58 ;
if ( V_138 . V_10 != V_52 -> V_10 ||
( V_138 . V_98 && strcmp ( V_138 . V_98 , V_52 -> V_98 ) ) ) {
V_153 = - V_146 ;
F_101 ( V_138 . V_58 ) ;
goto V_154;
}
F_83 ( V_8 -> V_14 , false , V_119 ) ;
V_153 = F_89 ( V_52 , V_138 . V_58 ) ;
if ( V_153 ) {
F_105 ( V_8 , false , V_119 ) ;
F_101 ( V_138 . V_58 ) ;
goto V_154;
}
F_105 ( V_8 , false , V_118 ) ;
if ( V_138 . V_149 )
strcpy ( V_52 -> V_134 , V_138 . V_149 ) ;
V_154:
F_26 ( V_138 . V_149 ) ;
F_26 ( V_138 . V_98 ) ;
F_58 ( & V_120 ) ;
F_58 ( & V_1 ) ;
F_58 ( & V_8 -> V_14 -> V_101 -> V_102 ) ;
return V_153 ;
}
static void F_106 ( struct V_7 * V_8 )
{
F_39 ( & V_8 -> V_126 ) ;
F_39 ( & V_8 -> V_157 ) ;
F_39 ( & V_8 -> V_110 ) ;
F_39 ( & V_8 -> V_62 ) ;
F_39 ( & V_8 -> V_158 ) ;
F_39 ( & V_8 -> V_159 ) ;
F_39 ( & V_8 -> V_91 ) ;
F_107 ( & V_8 -> V_160 ) ;
F_39 ( & V_8 -> V_161 ) ;
F_108 ( & V_8 -> V_162 ) ;
F_109 ( & V_8 -> V_92 ) ;
}
static void F_110 ( struct V_54 * V_52 )
{
struct V_7 * V_8 = & V_52 -> V_71 ;
F_39 ( & V_52 -> V_127 ) ;
F_39 ( & V_52 -> V_163 ) ;
F_39 ( & V_52 -> V_164 ) ;
V_52 -> V_90 = 1 ;
V_8 -> V_52 = V_52 ;
V_8 -> V_71 = V_8 ;
F_106 ( V_8 ) ;
F_46 ( & V_8 -> V_158 , & V_52 -> V_164 ) ;
}
static bool F_111 ( struct V_54 * V_52 )
{
int V_153 = 0 ;
do {
if ( ! F_112 ( & V_165 , V_59 ) )
return false ;
F_86 ( & V_166 ) ;
V_153 = F_113 ( & V_165 , V_167 ,
& V_52 -> V_168 ) ;
if ( V_153 == - V_169 )
V_153 = F_114 ( & V_165 , & V_52 -> V_168 ) ;
if ( ! V_153 ) {
V_167 = V_52 -> V_168 + 1 ;
} else if ( V_153 != - V_170 ) {
F_33 ( V_153 ) ;
}
F_88 ( & V_166 ) ;
} while ( V_153 );
return true ;
}
static int F_115 ( struct V_74 * V_75 , void * V_136 )
{
struct V_137 * V_138 = V_136 ;
struct V_54 * V_52 = V_75 -> V_112 ;
if ( V_138 -> V_98 && strcmp ( V_138 -> V_98 , V_52 -> V_98 ) )
return 0 ;
if ( ( V_138 -> V_58 || V_138 -> V_147 )
&& ( V_138 -> V_58 != V_52 -> V_58 ) )
return 0 ;
return 1 ;
}
static struct V_54 * F_116 ( struct V_137 * V_138 )
{
struct V_54 * V_52 ;
if ( ! V_138 -> V_58 && ! V_138 -> V_147 )
return NULL ;
V_52 = F_117 ( sizeof( * V_52 ) , V_59 ) ;
if ( ! V_52 )
return F_118 ( - V_60 ) ;
if ( ! F_111 ( V_52 ) ) {
F_26 ( V_52 ) ;
return F_118 ( - V_60 ) ;
}
F_110 ( V_52 ) ;
V_52 -> V_58 = V_138 -> V_58 ;
V_52 -> V_10 = V_138 -> V_10 ;
F_119 ( & V_52 -> V_93 ) ;
if ( V_138 -> V_149 )
strcpy ( V_52 -> V_134 , V_138 -> V_149 ) ;
if ( V_138 -> V_98 )
strcpy ( V_52 -> V_98 , V_138 -> V_98 ) ;
if ( V_138 -> V_148 )
F_24 ( V_135 , & V_52 -> V_71 . V_10 ) ;
return V_52 ;
}
static void F_120 ( struct V_54 * V_52 )
{
if ( ! V_52 )
return;
F_33 ( ! V_52 -> V_168 ) ;
F_86 ( & V_166 ) ;
F_121 ( & V_165 , V_52 -> V_168 ) ;
F_88 ( & V_166 ) ;
F_122 ( & V_52 -> V_93 ) ;
F_26 ( V_52 ) ;
}
static int F_123 ( struct V_74 * V_75 , void * V_136 )
{
int V_153 ;
struct V_137 * V_138 = V_136 ;
if ( ! V_138 -> V_171 )
return - V_146 ;
F_33 ( ! V_138 -> V_58 && ! V_138 -> V_147 ) ;
V_153 = F_124 ( V_75 , NULL ) ;
if ( V_153 )
return V_153 ;
V_75 -> V_112 = V_138 -> V_171 ;
V_138 -> V_171 -> V_75 = V_75 ;
V_75 -> V_172 = V_173 ;
V_75 -> V_174 = V_175 ;
V_75 -> V_176 = V_177 ;
V_75 -> V_178 = & V_179 ;
return 0 ;
}
static int F_125 ( struct V_74 * V_75 )
{
static const struct V_180 V_181 = {
. V_182 = F_64 ,
. F_76 = F_73 ,
} ;
struct V_72 * V_72 =
F_59 ( V_183 | V_184 | V_185 | V_186 , V_75 ) ;
if ( ! V_72 )
return - V_60 ;
V_72 -> V_187 = & V_188 ;
V_72 -> V_189 = & V_190 ;
F_126 ( V_72 ) ;
V_75 -> V_191 = F_127 ( V_72 ) ;
if ( ! V_75 -> V_191 )
return - V_60 ;
V_75 -> V_192 = & V_181 ;
return 0 ;
}
static struct V_14 * F_128 ( struct V_193 * V_194 ,
int V_10 , const char * V_195 ,
void * V_136 )
{
struct V_137 V_138 ;
struct V_54 * V_52 ;
int V_153 = 0 ;
struct V_74 * V_75 ;
struct V_54 * V_171 ;
struct V_72 * V_72 ;
F_56 ( & V_1 ) ;
V_153 = F_96 ( V_136 , & V_138 ) ;
F_58 ( & V_1 ) ;
if ( V_153 )
goto V_196;
V_171 = F_116 ( & V_138 ) ;
if ( F_129 ( V_171 ) ) {
V_153 = F_130 ( V_171 ) ;
goto V_197;
}
V_138 . V_171 = V_171 ;
V_75 = F_131 ( V_194 , F_115 , F_123 , 0 , & V_138 ) ;
if ( F_129 ( V_75 ) ) {
V_153 = F_130 ( V_75 ) ;
F_120 ( V_138 . V_171 ) ;
goto V_197;
}
V_52 = V_75 -> V_112 ;
F_33 ( ! V_52 ) ;
if ( V_52 == V_138 . V_171 ) {
struct V_42 V_61 ;
struct V_7 * V_198 = & V_52 -> V_71 ;
struct V_54 * V_199 ;
const struct V_200 * V_200 ;
int V_19 ;
F_33 ( V_75 -> V_191 != NULL ) ;
V_153 = F_125 ( V_75 ) ;
if ( V_153 )
goto V_201;
V_72 = V_75 -> V_191 -> V_101 ;
F_56 ( & V_72 -> V_102 ) ;
F_56 ( & V_1 ) ;
F_56 ( & V_120 ) ;
V_153 = - V_124 ;
if ( strlen ( V_52 -> V_98 ) )
F_132 (existing_root)
if ( ! strcmp ( V_199 -> V_98 , V_52 -> V_98 ) )
goto V_202;
V_153 = F_38 ( V_34 , & V_61 ) ;
if ( V_153 )
goto V_202;
V_153 = F_89 ( V_52 , V_52 -> V_58 ) ;
if ( V_153 == - V_124 ) {
F_37 ( & V_61 ) ;
goto V_202;
}
F_33 ( V_153 ) ;
F_41 ( & V_52 -> V_163 , & V_203 ) ;
V_64 ++ ;
V_75 -> V_191 -> V_15 = V_198 ;
V_52 -> V_71 . V_14 = V_75 -> V_191 ;
F_18 ( & V_32 ) ;
for ( V_19 = 0 ; V_19 < V_204 ; V_19 ++ ) {
struct V_18 * V_55 = & V_24 [ V_19 ] ;
struct V_56 * V_57 ;
struct V_25 * V_26 ;
F_36 (cg, node, hhead, hlist)
F_42 ( & V_61 , V_26 , V_198 ) ;
}
F_20 ( & V_32 ) ;
F_37 ( & V_61 ) ;
F_33 ( ! F_43 ( & V_198 -> V_157 ) ) ;
F_33 ( V_52 -> V_90 != 1 ) ;
V_200 = F_133 ( & V_205 ) ;
F_105 ( V_198 , true , V_52 -> V_58 ) ;
F_134 ( V_200 ) ;
F_58 ( & V_120 ) ;
F_58 ( & V_1 ) ;
F_58 ( & V_72 -> V_102 ) ;
} else {
F_120 ( V_138 . V_171 ) ;
F_101 ( V_138 . V_58 ) ;
}
F_26 ( V_138 . V_149 ) ;
F_26 ( V_138 . V_98 ) ;
return F_75 ( V_75 -> V_191 ) ;
V_202:
F_58 ( & V_120 ) ;
F_58 ( & V_1 ) ;
F_58 ( & V_72 -> V_102 ) ;
V_201:
F_135 ( V_75 ) ;
V_197:
F_101 ( V_138 . V_58 ) ;
V_196:
F_26 ( V_138 . V_149 ) ;
F_26 ( V_138 . V_98 ) ;
return F_118 ( V_153 ) ;
}
static void F_136 ( struct V_74 * V_75 ) {
struct V_54 * V_52 = V_75 -> V_112 ;
struct V_7 * V_8 = & V_52 -> V_71 ;
int V_153 ;
struct V_28 * V_29 ;
struct V_28 * V_30 ;
F_33 ( ! V_52 ) ;
F_33 ( V_52 -> V_90 != 1 ) ;
F_33 ( ! F_43 ( & V_8 -> V_157 ) ) ;
F_56 ( & V_1 ) ;
F_56 ( & V_120 ) ;
V_153 = F_89 ( V_52 , 0 ) ;
F_33 ( V_153 ) ;
F_18 ( & V_32 ) ;
F_22 (link, saved_link, &cgrp->css_sets,
cgrp_link_list) {
F_23 ( & V_29 -> V_35 ) ;
F_23 ( & V_29 -> V_36 ) ;
F_26 ( V_29 ) ;
}
F_20 ( & V_32 ) ;
if ( ! F_43 ( & V_52 -> V_163 ) ) {
F_23 ( & V_52 -> V_163 ) ;
V_64 -- ;
}
F_58 ( & V_120 ) ;
F_58 ( & V_1 ) ;
F_69 ( & V_8 -> V_92 ) ;
F_137 ( V_75 ) ;
F_120 ( V_52 ) ;
}
int F_138 ( const struct V_7 * V_8 , char * V_206 , int V_207 )
{
struct V_14 * V_14 = V_8 -> V_14 ;
char * V_208 ;
F_139 ( F_140 () || F_1 () ,
L_17 ) ;
if ( ! V_14 || V_8 == V_125 ) {
strcpy ( V_206 , L_18 ) ;
return 0 ;
}
V_208 = V_206 + V_207 - 1 ;
* V_208 = '\0' ;
for (; ; ) {
int V_209 = V_14 -> V_210 . V_209 ;
if ( ( V_208 -= V_209 ) < V_206 )
return - V_211 ;
memcpy ( V_208 , V_14 -> V_210 . V_98 , V_209 ) ;
V_8 = V_8 -> V_100 ;
if ( ! V_8 )
break;
V_14 = V_8 -> V_14 ;
if ( ! V_8 -> V_100 )
continue;
if ( -- V_208 < V_206 )
return - V_211 ;
* V_208 = '/' ;
}
memmove ( V_206 , V_208 , V_206 + V_207 - V_208 ) ;
return 0 ;
}
struct V_67 * F_141 ( struct V_212 * V_213 )
{
if ( V_213 -> V_214 ) {
V_213 -> V_215 = 0 ;
return F_142 ( V_213 ) ;
} else {
V_213 -> V_216 = V_213 -> V_217 . V_8 ;
return V_213 -> V_217 . V_68 ;
}
}
struct V_67 * F_142 ( struct V_212 * V_213 )
{
struct V_218 * V_219 ;
if ( ! V_213 -> V_214 || V_213 -> V_215 >= V_213 -> V_220 )
return NULL ;
V_219 = F_143 ( V_213 -> V_214 , V_213 -> V_215 ++ ) ;
V_213 -> V_216 = V_219 -> V_8 ;
return V_219 -> V_68 ;
}
struct V_7 * F_144 ( struct V_212 * V_213 )
{
return V_213 -> V_216 ;
}
int F_145 ( struct V_212 * V_213 )
{
return V_213 -> V_214 ? V_213 -> V_220 : 1 ;
}
static void F_146 ( struct V_7 * V_8 , struct V_7 * V_221 ,
struct V_67 * V_222 , struct V_25 * V_223 )
{
struct V_25 * V_53 ;
F_147 ( V_222 -> V_10 & V_224 ) ;
V_53 = V_222 -> V_69 ;
F_148 ( V_222 ) ;
F_149 ( V_222 -> V_69 , V_223 ) ;
F_150 ( V_222 ) ;
F_18 ( & V_32 ) ;
if ( ! F_43 ( & V_222 -> V_225 ) )
F_45 ( & V_222 -> V_225 , & V_223 -> V_65 ) ;
F_20 ( & V_32 ) ;
F_24 ( V_12 , & V_221 -> V_10 ) ;
F_30 ( V_53 ) ;
}
int F_151 ( struct V_7 * V_8 , struct V_67 * V_222 )
{
int V_226 = 0 ;
struct V_87 * V_88 , * V_227 = NULL ;
struct V_7 * V_221 ;
struct V_54 * V_52 = V_8 -> V_52 ;
struct V_212 V_213 = { } ;
struct V_25 * V_223 ;
if ( V_222 -> V_10 & V_224 )
return - V_228 ;
V_221 = F_54 ( V_222 , V_52 ) ;
if ( V_8 == V_221 )
return 0 ;
V_213 . V_217 . V_68 = V_222 ;
V_213 . V_217 . V_8 = V_221 ;
F_67 (root, ss) {
if ( V_88 -> V_229 ) {
V_226 = V_88 -> V_229 ( V_8 , & V_213 ) ;
if ( V_226 ) {
V_227 = V_88 ;
goto V_230;
}
}
}
V_223 = F_47 ( V_222 -> V_69 , V_8 ) ;
if ( ! V_223 ) {
V_226 = - V_60 ;
goto V_230;
}
F_146 ( V_8 , V_221 , V_222 , V_223 ) ;
F_67 (root, ss) {
if ( V_88 -> V_231 )
V_88 -> V_231 ( V_8 , & V_213 ) ;
}
F_66 () ;
V_230:
if ( V_226 ) {
F_67 (root, ss) {
if ( V_88 == V_227 )
break;
if ( V_88 -> V_232 )
V_88 -> V_232 ( V_8 , & V_213 ) ;
}
}
return V_226 ;
}
int F_152 ( struct V_67 * V_233 , struct V_67 * V_222 )
{
struct V_54 * V_52 ;
int V_226 = 0 ;
F_55 () ;
F_132 (root) {
struct V_7 * V_234 = F_54 ( V_233 , V_52 ) ;
V_226 = F_151 ( V_234 , V_222 ) ;
if ( V_226 )
break;
}
F_57 () ;
return V_226 ;
}
static int F_153 ( struct V_7 * V_8 , struct V_67 * V_235 )
{
int V_226 , V_19 , V_236 ;
struct V_87 * V_88 , * V_227 = NULL ;
struct V_54 * V_52 = V_8 -> V_52 ;
struct V_67 * V_222 ;
struct V_218 * V_219 ;
struct V_237 * V_238 ;
struct V_212 V_213 = { } ;
V_236 = F_154 ( V_235 ) ;
V_238 = F_155 ( sizeof( * V_219 ) , V_236 , V_59 ) ;
if ( ! V_238 )
return - V_60 ;
V_226 = F_156 ( V_238 , 0 , V_236 - 1 , V_59 ) ;
if ( V_226 )
goto V_239;
V_222 = V_235 ;
V_19 = 0 ;
F_157 () ;
do {
struct V_218 V_240 ;
if ( V_222 -> V_10 & V_224 )
continue;
F_33 ( V_19 >= V_236 ) ;
V_240 . V_68 = V_222 ;
V_240 . V_8 = F_54 ( V_222 , V_52 ) ;
if ( V_240 . V_8 == V_8 )
continue;
V_226 = F_158 ( V_238 , V_19 , & V_240 , V_241 ) ;
F_33 ( V_226 != 0 ) ;
V_19 ++ ;
} while_each_thread(leader, tsk) ;
int F_159 ( struct V_7 * V_8 , T_2 V_242 , bool V_243 )
{
struct V_67 * V_222 ;
const struct V_200 * V_200 = F_160 () , * V_244 ;
int V_153 ;
if ( ! F_161 ( V_8 ) )
return - V_245 ;
V_246:
F_157 () ;
if ( V_242 ) {
V_222 = F_162 ( V_242 ) ;
if ( ! V_222 ) {
F_163 () ;
V_153 = - V_228 ;
goto V_247;
}
V_244 = F_164 ( V_222 ) ;
if ( ! F_165 ( V_200 -> V_248 , V_249 ) &&
! F_165 ( V_200 -> V_248 , V_244 -> V_250 ) &&
! F_165 ( V_200 -> V_248 , V_244 -> V_251 ) ) {
F_163 () ;
V_153 = - V_252 ;
goto V_247;
}
} else
V_222 = V_155 ;
if ( V_243 )
V_222 = V_222 -> V_253 ;
if ( V_222 == V_254 || ( V_222 -> V_10 & V_255 ) ) {
V_153 = - V_146 ;
F_163 () ;
goto V_247;
}
F_166 ( V_222 ) ;
F_163 () ;
F_167 ( V_222 ) ;
if ( V_243 ) {
if ( ! F_168 ( V_222 ) ) {
F_169 ( V_222 ) ;
F_170 ( V_222 ) ;
goto V_246;
}
V_153 = F_153 ( V_8 , V_222 ) ;
} else
V_153 = F_151 ( V_8 , V_222 ) ;
F_169 ( V_222 ) ;
F_170 ( V_222 ) ;
V_247:
F_57 () ;
return V_153 ;
}
static int F_171 ( struct V_7 * V_8 , struct V_17 * V_97 , T_2 V_242 )
{
return F_159 ( V_8 , V_242 , false ) ;
}
static int F_172 ( struct V_7 * V_8 , struct V_17 * V_97 , T_2 V_256 )
{
return F_159 ( V_8 , V_256 , true ) ;
}
bool F_161 ( struct V_7 * V_8 )
{
F_56 ( & V_1 ) ;
if ( F_7 ( V_8 ) ) {
F_58 ( & V_1 ) ;
return false ;
}
return true ;
}
static int F_173 ( struct V_7 * V_8 , struct V_17 * V_97 ,
const char * V_257 )
{
F_174 ( sizeof( V_8 -> V_52 -> V_134 ) < V_150 ) ;
if ( strlen ( V_257 ) >= V_150 )
return - V_146 ;
if ( ! F_161 ( V_8 ) )
return - V_245 ;
F_56 ( & V_120 ) ;
strcpy ( V_8 -> V_52 -> V_134 , V_257 ) ;
F_58 ( & V_120 ) ;
F_57 () ;
return 0 ;
}
static int F_175 ( struct V_7 * V_8 , struct V_17 * V_97 ,
struct V_130 * V_131 )
{
if ( ! F_161 ( V_8 ) )
return - V_245 ;
F_95 ( V_131 , V_8 -> V_52 -> V_134 ) ;
F_176 ( V_131 , '\n' ) ;
F_57 () ;
return 0 ;
}
static T_3 F_177 ( struct V_7 * V_8 , struct V_17 * V_97 ,
struct V_258 * V_258 ,
const char T_4 * V_259 ,
T_5 V_260 , T_6 * V_261 )
{
char V_257 [ V_262 ] ;
int V_226 = 0 ;
char * V_263 ;
if ( ! V_260 )
return - V_146 ;
if ( V_260 >= sizeof( V_257 ) )
return - V_264 ;
if ( F_178 ( V_257 , V_259 , V_260 ) )
return - V_265 ;
V_257 [ V_260 ] = 0 ;
if ( V_97 -> V_266 ) {
T_2 V_267 = F_179 ( F_180 ( V_257 ) , & V_263 , 0 ) ;
if ( * V_263 )
return - V_146 ;
V_226 = V_97 -> V_266 ( V_8 , V_97 , V_267 ) ;
} else {
T_7 V_267 = F_181 ( F_180 ( V_257 ) , & V_263 , 0 ) ;
if ( * V_263 )
return - V_146 ;
V_226 = V_97 -> V_268 ( V_8 , V_97 , V_267 ) ;
}
if ( ! V_226 )
V_226 = V_260 ;
return V_226 ;
}
static T_3 F_182 ( struct V_7 * V_8 , struct V_17 * V_97 ,
struct V_258 * V_258 ,
const char T_4 * V_259 ,
T_5 V_260 , T_6 * V_261 )
{
char V_269 [ V_262 ] ;
int V_226 = 0 ;
T_5 V_270 = V_97 -> V_271 ;
char * V_257 = V_269 ;
if ( ! V_270 )
V_270 = sizeof( V_269 ) - 1 ;
if ( V_260 >= V_270 )
return - V_264 ;
if ( V_260 >= sizeof( V_269 ) ) {
V_257 = F_40 ( V_260 + 1 , V_59 ) ;
if ( V_257 == NULL )
return - V_60 ;
}
if ( V_260 && F_178 ( V_257 , V_259 , V_260 ) ) {
V_226 = - V_265 ;
goto V_230;
}
V_257 [ V_260 ] = 0 ;
V_226 = V_97 -> V_272 ( V_8 , V_97 , F_180 ( V_257 ) ) ;
if ( ! V_226 )
V_226 = V_260 ;
V_230:
if ( V_257 != V_269 )
F_26 ( V_257 ) ;
return V_226 ;
}
static T_3 F_183 ( struct V_258 * V_258 , const char T_4 * V_206 ,
T_5 V_260 , T_6 * V_273 )
{
struct V_17 * V_97 = F_13 ( V_258 -> V_274 ) ;
struct V_7 * V_8 = F_11 ( V_258 -> V_274 -> V_96 ) ;
if ( F_7 ( V_8 ) )
return - V_245 ;
if ( V_97 -> V_275 )
return V_97 -> V_275 ( V_8 , V_97 , V_258 , V_206 , V_260 , V_273 ) ;
if ( V_97 -> V_266 || V_97 -> V_268 )
return F_177 ( V_8 , V_97 , V_258 , V_206 , V_260 , V_273 ) ;
if ( V_97 -> V_272 )
return F_182 ( V_8 , V_97 , V_258 , V_206 , V_260 , V_273 ) ;
if ( V_97 -> V_276 ) {
int V_153 = V_97 -> V_276 ( V_8 , ( unsigned int ) V_97 -> V_277 ) ;
return V_153 ? V_153 : V_260 ;
}
return - V_146 ;
}
static T_3 F_184 ( struct V_7 * V_8 , struct V_17 * V_97 ,
struct V_258 * V_258 ,
char T_4 * V_206 , T_5 V_260 ,
T_6 * V_273 )
{
char V_21 [ V_262 ] ;
T_2 V_267 = V_97 -> V_278 ( V_8 , V_97 ) ;
int V_209 = sprintf ( V_21 , L_19 , ( unsigned long long ) V_267 ) ;
return F_185 ( V_206 , V_260 , V_273 , V_21 , V_209 ) ;
}
static T_3 F_186 ( struct V_7 * V_8 , struct V_17 * V_97 ,
struct V_258 * V_258 ,
char T_4 * V_206 , T_5 V_260 ,
T_6 * V_273 )
{
char V_21 [ V_262 ] ;
T_7 V_267 = V_97 -> V_279 ( V_8 , V_97 ) ;
int V_209 = sprintf ( V_21 , L_20 , ( long long ) V_267 ) ;
return F_185 ( V_206 , V_260 , V_273 , V_21 , V_209 ) ;
}
static T_3 F_187 ( struct V_258 * V_258 , char T_4 * V_206 ,
T_5 V_260 , T_6 * V_273 )
{
struct V_17 * V_97 = F_13 ( V_258 -> V_274 ) ;
struct V_7 * V_8 = F_11 ( V_258 -> V_274 -> V_96 ) ;
if ( F_7 ( V_8 ) )
return - V_245 ;
if ( V_97 -> V_280 )
return V_97 -> V_280 ( V_8 , V_97 , V_258 , V_206 , V_260 , V_273 ) ;
if ( V_97 -> V_278 )
return F_184 ( V_8 , V_97 , V_258 , V_206 , V_260 , V_273 ) ;
if ( V_97 -> V_279 )
return F_186 ( V_8 , V_97 , V_258 , V_206 , V_260 , V_273 ) ;
return - V_146 ;
}
static int F_188 ( struct V_281 * V_282 , const char * V_283 , T_2 V_284 )
{
struct V_130 * V_285 = V_282 -> V_286 ;
return F_94 ( V_285 , L_21 , V_283 , ( unsigned long long ) V_284 ) ;
}
static int F_189 ( struct V_130 * V_287 , void * V_288 )
{
struct V_289 * V_286 = V_287 -> V_277 ;
struct V_17 * V_97 = V_286 -> V_97 ;
if ( V_97 -> V_290 ) {
struct V_281 V_282 = {
. V_291 = F_188 ,
. V_286 = V_287 ,
} ;
return V_97 -> V_290 ( V_286 -> V_7 , V_97 , & V_282 ) ;
}
return V_97 -> V_292 ( V_286 -> V_7 , V_97 , V_287 ) ;
}
static int F_190 ( struct V_72 * V_72 , struct V_258 * V_258 )
{
struct V_130 * V_131 = V_258 -> V_293 ;
F_26 ( V_131 -> V_277 ) ;
return F_191 ( V_72 , V_258 ) ;
}
static int F_192 ( struct V_72 * V_72 , struct V_258 * V_258 )
{
int V_294 ;
struct V_17 * V_97 ;
V_294 = F_193 ( V_72 , V_258 ) ;
if ( V_294 )
return V_294 ;
V_97 = F_13 ( V_258 -> V_274 ) ;
if ( V_97 -> V_290 || V_97 -> V_292 ) {
struct V_289 * V_286 =
F_117 ( sizeof( * V_286 ) , V_295 ) ;
if ( ! V_286 )
return - V_60 ;
V_286 -> V_97 = V_97 ;
V_286 -> V_7 = F_11 ( V_258 -> V_274 -> V_96 ) ;
V_258 -> V_296 = & V_297 ;
V_294 = F_194 ( V_258 , F_189 , V_286 ) ;
if ( V_294 < 0 )
F_26 ( V_286 ) ;
} else if ( V_97 -> V_298 )
V_294 = V_97 -> V_298 ( V_72 , V_258 ) ;
else
V_294 = 0 ;
return V_294 ;
}
static int F_195 ( struct V_72 * V_72 , struct V_258 * V_258 )
{
struct V_17 * V_97 = F_13 ( V_258 -> V_274 ) ;
if ( V_97 -> V_299 )
return V_97 -> V_299 ( V_72 , V_258 ) ;
return 0 ;
}
static int F_196 ( struct V_72 * V_300 , struct V_14 * V_301 ,
struct V_72 * V_302 , struct V_14 * V_303 )
{
if ( ! F_65 ( V_301 -> V_101 -> V_77 ) )
return - V_304 ;
if ( V_303 -> V_101 )
return - V_305 ;
if ( V_300 != V_302 )
return - V_306 ;
return F_197 ( V_300 , V_301 , V_302 , V_303 ) ;
}
static struct V_307 * F_198 ( struct V_14 * V_14 )
{
if ( F_65 ( V_14 -> V_101 -> V_77 ) )
return & F_11 ( V_14 ) -> V_92 ;
else
return & F_13 ( V_14 ) -> V_92 ;
}
static inline int F_199 ( struct V_14 * V_14 )
{
struct V_54 * V_52 = V_14 -> V_111 -> V_112 ;
return F_8 ( V_133 , & V_52 -> V_10 ) ;
}
static bool F_200 ( const char * V_98 )
{
if ( ! strncmp ( V_98 , V_308 , V_309 ) ||
! strncmp ( V_98 , V_310 , V_311 ) )
return true ;
return false ;
}
static int F_201 ( struct V_14 * V_14 , const char * V_98 ,
const void * V_267 , T_5 V_312 , int V_10 )
{
if ( ! F_199 ( V_14 ) )
return - V_313 ;
if ( ! F_200 ( V_98 ) )
return - V_146 ;
return F_202 ( F_198 ( V_14 ) , V_98 , V_267 , V_312 , V_10 ) ;
}
static int F_203 ( struct V_14 * V_14 , const char * V_98 )
{
if ( ! F_199 ( V_14 ) )
return - V_313 ;
if ( ! F_200 ( V_98 ) )
return - V_146 ;
return F_204 ( F_198 ( V_14 ) , V_98 ) ;
}
static T_3 F_205 ( struct V_14 * V_14 , const char * V_98 ,
void * V_206 , T_5 V_312 )
{
if ( ! F_199 ( V_14 ) )
return - V_313 ;
if ( ! F_200 ( V_98 ) )
return - V_146 ;
return F_206 ( F_198 ( V_14 ) , V_98 , V_206 , V_312 ) ;
}
static T_3 F_207 ( struct V_14 * V_14 , char * V_206 , T_5 V_312 )
{
if ( ! F_199 ( V_14 ) )
return - V_313 ;
return F_208 ( F_198 ( V_14 ) , V_206 , V_312 ) ;
}
static struct V_14 * F_209 ( struct V_72 * V_104 , struct V_14 * V_14 , unsigned int V_10 )
{
if ( V_14 -> V_210 . V_209 > V_314 )
return F_118 ( - V_211 ) ;
F_210 ( V_14 , NULL ) ;
return NULL ;
}
static inline struct V_17 * F_211 ( struct V_258 * V_258 )
{
if ( V_258 -> V_274 -> V_101 -> V_187 != & V_315 )
return F_118 ( - V_146 ) ;
return F_13 ( V_258 -> V_274 ) ;
}
static int F_212 ( struct V_14 * V_14 , T_1 V_73 ,
struct V_74 * V_75 )
{
struct V_72 * V_72 ;
if ( ! V_14 )
return - V_103 ;
if ( V_14 -> V_101 )
return - V_305 ;
V_72 = F_59 ( V_73 , V_75 ) ;
if ( ! V_72 )
return - V_60 ;
if ( F_65 ( V_73 ) ) {
V_72 -> V_189 = & V_190 ;
V_72 -> V_187 = & V_188 ;
F_126 ( V_72 ) ;
F_126 ( V_14 -> V_96 -> V_101 ) ;
F_147 ( ! F_213 ( & V_72 -> V_102 ) ) ;
} else if ( F_214 ( V_73 ) ) {
V_72 -> V_316 = 0 ;
V_72 -> V_187 = & V_315 ;
V_72 -> V_189 = & V_317 ;
}
F_215 ( V_14 , V_72 ) ;
F_75 ( V_14 ) ;
return 0 ;
}
static T_1 F_216 ( const struct V_17 * V_97 )
{
T_1 V_73 = 0 ;
if ( V_97 -> V_73 )
return V_97 -> V_73 ;
if ( V_97 -> V_280 || V_97 -> V_278 || V_97 -> V_279 ||
V_97 -> V_290 || V_97 -> V_292 )
V_73 |= V_184 ;
if ( V_97 -> V_275 || V_97 -> V_266 || V_97 -> V_268 ||
V_97 -> V_272 || V_97 -> V_276 )
V_73 |= V_186 ;
return V_73 ;
}
static int F_217 ( struct V_7 * V_8 , struct V_87 * V_45 ,
struct V_17 * V_97 )
{
struct V_14 * V_104 = V_8 -> V_14 ;
struct V_7 * V_100 = F_11 ( V_104 ) ;
struct V_14 * V_14 ;
struct V_16 * V_95 ;
int error ;
T_1 V_73 ;
char V_98 [ V_318 + V_319 + 2 ] = { 0 } ;
F_109 ( & V_97 -> V_92 ) ;
if ( V_45 && ! F_8 ( V_132 , & V_8 -> V_52 -> V_10 ) ) {
strcpy ( V_98 , V_45 -> V_98 ) ;
strcat ( V_98 , L_22 ) ;
}
strcat ( V_98 , V_97 -> V_98 ) ;
F_33 ( ! F_3 ( & V_104 -> V_101 -> V_102 ) ) ;
V_95 = F_117 ( sizeof( * V_95 ) , V_59 ) ;
if ( ! V_95 )
return - V_60 ;
V_14 = F_218 ( V_98 , V_104 , strlen ( V_98 ) ) ;
if ( F_129 ( V_14 ) ) {
error = F_130 ( V_14 ) ;
goto V_230;
}
V_73 = F_216 ( V_97 ) ;
error = F_212 ( V_14 , V_73 | V_320 , V_8 -> V_52 -> V_75 ) ;
if ( ! error ) {
V_95 -> type = ( void * ) V_97 ;
V_95 -> V_14 = V_14 ;
V_14 -> V_15 = V_95 ;
F_46 ( & V_95 -> V_57 , & V_100 -> V_110 ) ;
V_95 = NULL ;
}
F_78 ( V_14 ) ;
V_230:
F_26 ( V_95 ) ;
return error ;
}
static int F_84 ( struct V_7 * V_8 , struct V_87 * V_45 ,
struct V_17 V_109 [] , bool V_321 )
{
struct V_17 * V_97 ;
int V_294 , V_153 = 0 ;
for ( V_97 = V_109 ; V_97 -> V_98 [ 0 ] != '\0' ; V_97 ++ ) {
if ( ( V_97 -> V_10 & V_322 ) && ! V_8 -> V_100 )
continue;
if ( ( V_97 -> V_10 & V_323 ) && V_8 -> V_100 )
continue;
if ( V_321 )
V_294 = F_217 ( V_8 , V_45 , V_97 ) ;
else
V_294 = F_79 ( V_8 , V_97 ) ;
if ( V_294 ) {
F_103 ( L_23 ,
V_321 ? L_24 : L_25 , V_97 -> V_98 , V_294 ) ;
V_153 = V_294 ;
}
}
return V_153 ;
}
static void F_219 ( void )
__acquires( &cgroup_cft_mutex
static void F_220 ( struct V_87 * V_88 ,
struct V_17 * V_109 , bool V_321 )
__releases( &cgroup_mutex
int F_221 ( struct V_87 * V_88 , struct V_17 * V_109 )
{
struct V_106 * V_107 ;
V_107 = F_117 ( sizeof( * V_107 ) , V_59 ) ;
if ( ! V_107 )
return - V_60 ;
F_219 () ;
V_107 -> V_109 = V_109 ;
F_46 ( & V_107 -> V_57 , & V_88 -> V_324 ) ;
F_220 ( V_88 , V_109 , true ) ;
return 0 ;
}
int F_222 ( struct V_87 * V_88 , struct V_17 * V_109 )
{
struct V_106 * V_107 ;
F_219 () ;
F_52 (set, &ss->cftsets, node) {
if ( V_107 -> V_109 == V_109 ) {
F_82 ( & V_107 -> V_57 ) ;
F_220 ( V_88 , V_109 , false ) ;
return 0 ;
}
}
F_220 ( V_88 , NULL , false ) ;
return - V_103 ;
}
int F_223 ( const struct V_7 * V_8 )
{
int V_37 = 0 ;
struct V_28 * V_29 ;
F_48 ( & V_32 ) ;
F_52 (link, &cgrp->css_sets, cgrp_link_list) {
V_37 += F_6 ( & V_29 -> V_26 -> V_31 ) ;
}
F_49 ( & V_32 ) ;
return V_37 ;
}
static void F_224 ( struct V_7 * V_8 ,
struct V_325 * V_326 )
{
struct V_42 * V_327 = V_326 -> V_328 ;
struct V_28 * V_29 ;
struct V_25 * V_26 ;
do {
V_327 = V_327 -> V_51 ;
if ( V_327 == & V_8 -> V_62 ) {
V_326 -> V_328 = NULL ;
return;
}
V_29 = F_34 ( V_327 , struct V_28 , V_36 ) ;
V_26 = V_29 -> V_26 ;
} while ( F_43 ( & V_26 -> V_65 ) );
V_326 -> V_328 = V_327 ;
V_326 -> V_68 = V_26 -> V_65 . V_51 ;
}
static void F_225 ( void )
{
struct V_67 * V_329 , * V_330 ;
F_18 ( & V_32 ) ;
V_331 = 1 ;
F_48 ( & V_332 ) ;
F_226 (g, p) {
F_148 ( V_329 ) ;
if ( ! ( V_329 -> V_10 & V_224 ) && F_43 ( & V_329 -> V_225 ) )
F_41 ( & V_329 -> V_225 , & V_329 -> V_69 -> V_65 ) ;
F_150 ( V_329 ) ;
} F_227 ( V_330 , V_329 ) ;
F_49 ( & V_332 ) ;
F_20 ( & V_32 ) ;
}
struct V_7 * F_228 ( struct V_7 * V_333 ,
struct V_7 * V_7 )
{
struct V_7 * V_51 ;
F_147 ( ! F_140 () ) ;
if ( ! V_333 ) {
if ( F_43 ( & V_7 -> V_157 ) )
return NULL ;
V_333 = V_7 ;
}
V_51 = F_229 ( & V_333 -> V_157 , struct V_7 , V_126 ) ;
if ( V_51 )
return V_51 ;
do {
V_51 = F_230 ( V_333 -> V_126 . V_51 , struct V_7 ,
V_126 ) ;
if ( & V_51 -> V_126 != & V_333 -> V_100 -> V_157 )
return V_51 ;
V_333 = V_333 -> V_100 ;
} while ( V_333 != V_7 );
return NULL ;
}
static struct V_7 * F_231 ( struct V_7 * V_333 )
{
struct V_7 * V_334 ;
do {
V_334 = V_333 ;
V_333 = F_229 ( & V_333 -> V_157 , struct V_7 ,
V_126 ) ;
} while ( V_333 );
return V_334 ;
}
struct V_7 * F_232 ( struct V_7 * V_333 ,
struct V_7 * V_7 )
{
struct V_7 * V_51 ;
F_147 ( ! F_140 () ) ;
if ( ! V_333 ) {
V_51 = F_231 ( V_7 ) ;
return V_51 != V_7 ? V_51 : NULL ;
}
V_51 = F_230 ( V_333 -> V_126 . V_51 , struct V_7 , V_126 ) ;
if ( & V_51 -> V_126 != & V_333 -> V_100 -> V_157 )
return F_231 ( V_51 ) ;
V_51 = V_333 -> V_100 ;
return V_51 != V_7 ? V_51 : NULL ;
}
void F_233 ( struct V_7 * V_8 , struct V_325 * V_326 )
__acquires( V_32 )
{
if ( ! V_331 )
F_225 () ;
F_48 ( & V_32 ) ;
V_326 -> V_328 = & V_8 -> V_62 ;
F_224 ( V_8 , V_326 ) ;
}
struct V_67 * F_234 ( struct V_7 * V_8 ,
struct V_325 * V_326 )
{
struct V_67 * V_63 ;
struct V_42 * V_327 = V_326 -> V_68 ;
struct V_28 * V_29 ;
if ( ! V_326 -> V_328 )
return NULL ;
V_63 = F_34 ( V_327 , struct V_67 , V_225 ) ;
V_327 = V_327 -> V_51 ;
V_29 = F_34 ( V_326 -> V_328 , struct V_28 , V_36 ) ;
if ( V_327 == & V_29 -> V_26 -> V_65 ) {
F_224 ( V_8 , V_326 ) ;
} else {
V_326 -> V_68 = V_327 ;
}
return V_63 ;
}
void F_235 ( struct V_7 * V_8 , struct V_325 * V_326 )
__releases( V_32 )
{
F_49 ( & V_32 ) ;
}
static inline int F_236 ( struct V_67 * V_335 ,
struct V_336 * time ,
struct V_67 * V_337 )
{
int V_338 = F_237 ( & V_335 -> V_339 , time ) ;
if ( V_338 > 0 ) {
return 1 ;
} else if ( V_338 < 0 ) {
return 0 ;
} else {
return V_335 > V_337 ;
}
}
static inline int F_238 ( void * V_340 , void * V_341 )
{
struct V_67 * V_335 = V_340 ;
struct V_67 * V_337 = V_341 ;
return F_236 ( V_335 , & V_337 -> V_339 , V_337 ) ;
}
int F_239 ( struct V_342 * V_343 )
{
int V_226 , V_19 ;
struct V_325 V_326 ;
struct V_67 * V_329 , * V_344 ;
struct V_67 * V_345 = NULL ;
struct V_346 V_347 ;
struct V_346 * V_348 ;
struct V_336 V_349 = { 0 , 0 } ;
if ( V_343 -> V_348 ) {
V_348 = V_343 -> V_348 ;
V_348 -> V_350 = & F_238 ;
} else {
V_348 = & V_347 ;
V_226 = F_240 ( V_348 , V_351 , V_59 , & F_238 ) ;
if ( V_226 )
return V_226 ;
}
V_352:
V_348 -> V_312 = 0 ;
F_233 ( V_343 -> V_26 , & V_326 ) ;
while ( ( V_329 = F_234 ( V_343 -> V_26 , & V_326 ) ) ) {
if ( V_343 -> V_353 && ! V_343 -> V_353 ( V_329 , V_343 ) )
continue;
if ( ! F_236 ( V_329 , & V_349 , V_345 ) )
continue;
V_344 = F_241 ( V_348 , V_329 ) ;
if ( V_344 == NULL ) {
F_166 ( V_329 ) ;
} else if ( V_344 != V_329 ) {
F_166 ( V_329 ) ;
F_170 ( V_344 ) ;
}
}
F_235 ( V_343 -> V_26 , & V_326 ) ;
if ( V_348 -> V_312 ) {
for ( V_19 = 0 ; V_19 < V_348 -> V_312 ; V_19 ++ ) {
struct V_67 * V_354 = V_348 -> V_355 [ V_19 ] ;
if ( V_19 == 0 ) {
V_349 = V_354 -> V_339 ;
V_345 = V_354 ;
}
V_343 -> V_356 ( V_354 , V_343 ) ;
F_170 ( V_354 ) ;
}
goto V_352;
}
if ( V_348 == & V_347 )
F_242 ( & V_347 ) ;
return 0 ;
}
static void * F_243 ( int V_37 )
{
if ( F_244 ( V_37 ) )
return F_245 ( V_37 * sizeof( V_357 ) ) ;
else
return F_40 ( V_37 * sizeof( V_357 ) , V_59 ) ;
}
static void F_246 ( void * V_329 )
{
if ( F_247 ( V_329 ) )
F_248 ( V_329 ) ;
else
F_26 ( V_329 ) ;
}
static void * F_249 ( void * V_329 , int V_358 )
{
void * V_359 ;
if ( F_247 ( V_329 ) ) {
V_359 = F_245 ( V_358 * sizeof( V_357 ) ) ;
if ( ! V_359 )
return NULL ;
memcpy ( V_359 , V_329 , V_358 * sizeof( V_357 ) ) ;
F_248 ( V_329 ) ;
} else {
V_359 = F_250 ( V_329 , V_358 * sizeof( V_357 ) , V_59 ) ;
}
return V_359 ;
}
static int F_251 ( V_357 * * V_329 , int V_360 )
{
int V_361 , V_362 = 1 ;
V_357 * V_363 = * V_329 ;
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
if ( F_252 ( V_360 , V_362 ) ) {
V_359 = F_249 ( V_363 , V_362 ) ;
if ( V_359 )
* V_329 = V_359 ;
}
return V_362 ;
}
static int F_253 ( const void * V_365 , const void * V_366 )
{
return * ( V_357 * ) V_365 - * ( V_357 * ) V_366 ;
}
static struct V_367 * F_254 ( struct V_7 * V_8 ,
enum V_368 type )
{
struct V_367 * V_327 ;
struct V_369 * V_370 = F_255 ( V_155 ) ;
F_56 ( & V_8 -> V_160 ) ;
F_52 (l, &cgrp->pidlists, links) {
if ( V_327 -> V_283 . type == type && V_327 -> V_283 . V_370 == V_370 ) {
F_256 ( & V_327 -> V_371 ) ;
F_58 ( & V_8 -> V_160 ) ;
return V_327 ;
}
}
V_327 = F_40 ( sizeof( struct V_367 ) , V_59 ) ;
if ( ! V_327 ) {
F_58 ( & V_8 -> V_160 ) ;
return V_327 ;
}
F_257 ( & V_327 -> V_371 ) ;
F_256 ( & V_327 -> V_371 ) ;
V_327 -> V_283 . type = type ;
V_327 -> V_283 . V_370 = F_258 ( V_370 ) ;
V_327 -> V_372 = 0 ;
V_327 -> V_363 = NULL ;
V_327 -> V_373 = V_8 ;
F_41 ( & V_327 -> V_374 , & V_8 -> V_91 ) ;
F_58 ( & V_8 -> V_160 ) ;
return V_327 ;
}
static int F_259 ( struct V_7 * V_8 , enum V_368 type ,
struct V_367 * * V_375 )
{
V_357 * V_376 ;
int V_360 ;
int V_242 , V_377 = 0 ;
struct V_325 V_326 ;
struct V_67 * V_222 ;
struct V_367 * V_327 ;
V_360 = F_223 ( V_8 ) ;
V_376 = F_243 ( V_360 ) ;
if ( ! V_376 )
return - V_60 ;
F_233 ( V_8 , & V_326 ) ;
while ( ( V_222 = F_234 ( V_8 , & V_326 ) ) ) {
if ( F_260 ( V_377 == V_360 ) )
break;
if ( type == V_378 )
V_242 = F_261 ( V_222 ) ;
else
V_242 = F_262 ( V_222 ) ;
if ( V_242 > 0 )
V_376 [ V_377 ++ ] = V_242 ;
}
F_235 ( V_8 , & V_326 ) ;
V_360 = V_377 ;
F_263 ( V_376 , V_360 , sizeof( V_357 ) , F_253 , NULL ) ;
if ( type == V_378 )
V_360 = F_251 ( & V_376 , V_360 ) ;
V_327 = F_254 ( V_8 , type ) ;
if ( ! V_327 ) {
F_246 ( V_376 ) ;
return - V_60 ;
}
F_246 ( V_327 -> V_363 ) ;
V_327 -> V_363 = V_376 ;
V_327 -> V_360 = V_360 ;
V_327 -> V_372 ++ ;
F_264 ( & V_327 -> V_371 ) ;
* V_375 = V_327 ;
return 0 ;
}
int F_265 ( struct V_379 * V_380 , struct V_14 * V_14 )
{
int V_153 = - V_146 ;
struct V_7 * V_8 ;
struct V_325 V_326 ;
struct V_67 * V_222 ;
if ( V_14 -> V_111 -> V_178 != & V_179 ||
! F_65 ( V_14 -> V_101 -> V_77 ) )
goto V_294;
V_153 = 0 ;
V_8 = V_14 -> V_15 ;
F_233 ( V_8 , & V_326 ) ;
while ( ( V_222 = F_234 ( V_8 , & V_326 ) ) ) {
switch ( V_222 -> V_286 ) {
case V_381 :
V_380 -> V_382 ++ ;
break;
case V_383 :
V_380 -> V_384 ++ ;
break;
case V_385 :
V_380 -> V_386 ++ ;
break;
case V_387 :
V_380 -> V_388 ++ ;
break;
default:
if ( F_266 ( V_222 ) )
V_380 -> V_389 ++ ;
break;
}
}
F_235 ( V_8 , & V_326 ) ;
V_294:
return V_153 ;
}
static void * F_267 ( struct V_130 * V_390 , T_6 * V_333 )
{
struct V_367 * V_327 = V_390 -> V_277 ;
int V_20 = 0 , V_242 = * V_333 ;
int * V_391 ;
F_268 ( & V_327 -> V_371 ) ;
if ( V_242 ) {
int V_263 = V_327 -> V_360 ;
while ( V_20 < V_263 ) {
int V_392 = ( V_20 + V_263 ) / 2 ;
if ( V_327 -> V_363 [ V_392 ] == V_242 ) {
V_20 = V_392 ;
break;
} else if ( V_327 -> V_363 [ V_392 ] <= V_242 )
V_20 = V_392 + 1 ;
else
V_263 = V_392 ;
}
}
if ( V_20 >= V_327 -> V_360 )
return NULL ;
V_391 = V_327 -> V_363 + V_20 ;
* V_333 = * V_391 ;
return V_391 ;
}
static void F_269 ( struct V_130 * V_390 , void * V_6 )
{
struct V_367 * V_327 = V_390 -> V_277 ;
F_270 ( & V_327 -> V_371 ) ;
}
static void * F_271 ( struct V_130 * V_390 , void * V_6 , T_6 * V_333 )
{
struct V_367 * V_327 = V_390 -> V_277 ;
V_357 * V_329 = V_6 ;
V_357 * V_263 = V_327 -> V_363 + V_327 -> V_360 ;
V_329 ++ ;
if ( V_329 >= V_263 ) {
return NULL ;
} else {
* V_333 = * V_329 ;
return V_329 ;
}
}
static int F_272 ( struct V_130 * V_390 , void * V_6 )
{
return F_94 ( V_390 , L_26 , * ( int * ) V_6 ) ;
}
static void F_273 ( struct V_367 * V_327 )
{
F_56 ( & V_327 -> V_373 -> V_160 ) ;
F_256 ( & V_327 -> V_371 ) ;
F_33 ( ! V_327 -> V_372 ) ;
if ( ! -- V_327 -> V_372 ) {
F_23 ( & V_327 -> V_374 ) ;
F_58 ( & V_327 -> V_373 -> V_160 ) ;
F_246 ( V_327 -> V_363 ) ;
F_274 ( V_327 -> V_283 . V_370 ) ;
F_264 ( & V_327 -> V_371 ) ;
F_26 ( V_327 ) ;
return;
}
F_58 ( & V_327 -> V_373 -> V_160 ) ;
F_264 ( & V_327 -> V_371 ) ;
}
static int F_275 ( struct V_72 * V_72 , struct V_258 * V_258 )
{
struct V_367 * V_327 ;
if ( ! ( V_258 -> V_393 & V_394 ) )
return 0 ;
V_327 = ( (struct V_130 * ) V_258 -> V_293 ) -> V_277 ;
F_273 ( V_327 ) ;
return F_276 ( V_72 , V_258 ) ;
}
static int F_277 ( struct V_258 * V_258 , enum V_368 type )
{
struct V_7 * V_8 = F_11 ( V_258 -> V_274 -> V_96 ) ;
struct V_367 * V_327 ;
int V_226 ;
if ( ! ( V_258 -> V_393 & V_394 ) )
return 0 ;
V_226 = F_259 ( V_8 , type , & V_327 ) ;
if ( V_226 )
return V_226 ;
V_258 -> V_296 = & V_395 ;
V_226 = F_278 ( V_258 , & V_396 ) ;
if ( V_226 ) {
F_273 ( V_327 ) ;
return V_226 ;
}
( (struct V_130 * ) V_258 -> V_293 ) -> V_277 = V_327 ;
return 0 ;
}
static int F_279 ( struct V_72 * V_397 , struct V_258 * V_258 )
{
return F_277 ( V_258 , V_398 ) ;
}
static int F_280 ( struct V_72 * V_397 , struct V_258 * V_258 )
{
return F_277 ( V_258 , V_378 ) ;
}
static T_2 F_281 ( struct V_7 * V_8 ,
struct V_17 * V_97 )
{
return F_10 ( V_8 ) ;
}
static int F_282 ( struct V_7 * V_8 ,
struct V_17 * V_97 ,
T_2 V_267 )
{
F_283 ( V_12 , & V_8 -> V_10 ) ;
if ( V_267 )
F_24 ( V_13 , & V_8 -> V_10 ) ;
else
F_283 ( V_13 , & V_8 -> V_10 ) ;
return 0 ;
}
static void F_284 ( struct V_399 * V_400 )
{
struct V_401 * V_402 = F_285 ( V_400 , struct V_401 ,
remove ) ;
struct V_7 * V_8 = V_402 -> V_8 ;
V_402 -> V_97 -> V_403 ( V_8 , V_402 -> V_97 , V_402 -> V_404 ) ;
F_286 ( V_402 -> V_404 ) ;
F_26 ( V_402 ) ;
F_78 ( V_8 -> V_14 ) ;
}
static int F_287 ( T_8 * V_405 , unsigned V_73 ,
int V_406 , void * V_283 )
{
struct V_401 * V_402 = F_285 ( V_405 ,
struct V_401 , V_405 ) ;
struct V_7 * V_8 = V_402 -> V_8 ;
unsigned long V_10 = ( unsigned long ) V_283 ;
if ( V_10 & V_407 ) {
F_288 ( V_402 -> V_408 , & V_402 -> V_405 ) ;
F_86 ( & V_8 -> V_162 ) ;
F_82 ( & V_402 -> V_363 ) ;
F_88 ( & V_8 -> V_162 ) ;
F_289 ( & V_402 -> remove ) ;
}
return 0 ;
}
static void F_290 ( struct V_258 * V_258 ,
T_9 * V_408 , T_10 * V_409 )
{
struct V_401 * V_402 = F_285 ( V_409 ,
struct V_401 , V_409 ) ;
V_402 -> V_408 = V_408 ;
F_291 ( V_408 , & V_402 -> V_405 ) ;
}
static int F_292 ( struct V_7 * V_8 , struct V_17 * V_97 ,
const char * V_257 )
{
struct V_401 * V_402 = NULL ;
unsigned int V_410 , V_411 ;
struct V_258 * V_412 = NULL ;
struct V_258 * V_413 = NULL ;
char * V_414 ;
int V_153 ;
V_410 = F_293 ( V_257 , & V_414 , 10 ) ;
if ( * V_414 != ' ' )
return - V_146 ;
V_257 = V_414 + 1 ;
V_411 = F_293 ( V_257 , & V_414 , 10 ) ;
if ( ( * V_414 != ' ' ) && ( * V_414 != '\0' ) )
return - V_146 ;
V_257 = V_414 + 1 ;
V_402 = F_117 ( sizeof( * V_402 ) , V_59 ) ;
if ( ! V_402 )
return - V_60 ;
V_402 -> V_8 = V_8 ;
F_39 ( & V_402 -> V_363 ) ;
F_294 ( & V_402 -> V_409 , F_290 ) ;
F_295 ( & V_402 -> V_405 , F_287 ) ;
F_296 ( & V_402 -> remove , F_284 ) ;
V_412 = F_297 ( V_410 ) ;
if ( F_129 ( V_412 ) ) {
V_153 = F_130 ( V_412 ) ;
goto V_415;
}
V_402 -> V_404 = F_298 ( V_412 ) ;
if ( F_129 ( V_402 -> V_404 ) ) {
V_153 = F_130 ( V_402 -> V_404 ) ;
goto V_415;
}
V_413 = F_299 ( V_411 ) ;
if ( ! V_413 ) {
V_153 = - V_416 ;
goto V_415;
}
V_153 = F_300 ( V_413 -> V_417 . V_14 -> V_101 , V_418 ) ;
if ( V_153 < 0 )
goto V_415;
V_402 -> V_97 = F_211 ( V_413 ) ;
if ( F_129 ( V_402 -> V_97 ) ) {
V_153 = F_130 ( V_402 -> V_97 ) ;
goto V_415;
}
if ( ! V_402 -> V_97 -> V_419 || ! V_402 -> V_97 -> V_403 ) {
V_153 = - V_146 ;
goto V_415;
}
V_153 = V_402 -> V_97 -> V_419 ( V_8 , V_402 -> V_97 ,
V_402 -> V_404 , V_257 ) ;
if ( V_153 )
goto V_415;
if ( V_412 -> V_296 -> V_420 ( V_412 , & V_402 -> V_409 ) & V_407 ) {
V_402 -> V_97 -> V_403 ( V_8 , V_402 -> V_97 , V_402 -> V_404 ) ;
V_153 = 0 ;
goto V_415;
}
F_75 ( V_8 -> V_14 ) ;
F_86 ( & V_8 -> V_162 ) ;
F_41 ( & V_402 -> V_363 , & V_8 -> V_161 ) ;
F_88 ( & V_8 -> V_162 ) ;
F_301 ( V_413 ) ;
F_301 ( V_412 ) ;
return 0 ;
V_415:
if ( V_413 )
F_301 ( V_413 ) ;
if ( V_402 && V_402 -> V_404 && ! F_129 ( V_402 -> V_404 ) )
F_286 ( V_402 -> V_404 ) ;
if ( ! F_302 ( V_412 ) )
F_301 ( V_412 ) ;
F_26 ( V_402 ) ;
return V_153 ;
}
static T_2 F_303 ( struct V_7 * V_8 ,
struct V_17 * V_97 )
{
return F_8 ( V_135 , & V_8 -> V_10 ) ;
}
static int F_304 ( struct V_7 * V_8 ,
struct V_17 * V_97 ,
T_2 V_267 )
{
if ( V_267 )
F_24 ( V_135 , & V_8 -> V_10 ) ;
else
F_283 ( V_135 , & V_8 -> V_10 ) ;
return 0 ;
}
static int F_105 ( struct V_7 * V_8 , bool V_105 ,
unsigned long V_58 )
{
int V_294 ;
struct V_87 * V_88 ;
if ( V_105 ) {
V_294 = F_84 ( V_8 , NULL , V_110 , true ) ;
if ( V_294 < 0 )
return V_294 ;
}
F_67 (cgrp->root, ss) {
struct V_106 * V_107 ;
if ( ! F_8 ( V_88 -> V_108 , & V_58 ) )
continue;
F_52 (set, &ss->cftsets, node)
F_84 ( V_8 , V_88 , V_107 -> V_109 , true ) ;
}
F_67 (cgrp->root, ss) {
struct V_4 * V_5 = V_8 -> V_45 [ V_88 -> V_108 ] ;
if ( V_5 -> V_94 )
F_149 ( V_5 -> V_94 -> V_5 , V_5 ) ;
}
return 0 ;
}
static void F_305 ( struct V_399 * V_400 )
{
struct V_4 * V_5 =
F_285 ( V_400 , struct V_4 , V_421 ) ;
struct V_14 * V_14 = V_5 -> V_7 -> V_14 ;
struct V_74 * V_75 = V_14 -> V_111 ;
F_29 ( & V_75 -> V_422 ) ;
F_78 ( V_14 ) ;
F_68 ( V_75 ) ;
}
static void F_306 ( struct V_4 * V_5 ,
struct V_87 * V_88 ,
struct V_7 * V_8 )
{
V_5 -> V_7 = V_8 ;
F_50 ( & V_5 -> V_2 , 1 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_94 = NULL ;
if ( V_8 == V_125 )
V_5 -> V_10 |= V_423 ;
F_33 ( V_8 -> V_45 [ V_88 -> V_108 ] ) ;
V_8 -> V_45 [ V_88 -> V_108 ] = V_5 ;
F_296 ( & V_5 -> V_421 , F_305 ) ;
}
static int F_307 ( struct V_87 * V_88 , struct V_7 * V_8 )
{
int V_153 = 0 ;
F_80 ( & V_1 ) ;
if ( V_88 -> V_424 )
V_153 = V_88 -> V_424 ( V_8 ) ;
if ( ! V_153 )
V_8 -> V_45 [ V_88 -> V_108 ] -> V_10 |= V_425 ;
return V_153 ;
}
static void F_308 ( struct V_87 * V_88 , struct V_7 * V_8 )
__releases( &cgroup_mutex
static long F_309 ( struct V_7 * V_100 , struct V_14 * V_14 ,
T_1 V_73 )
{
struct V_7 * V_8 ;
struct V_54 * V_52 = V_100 -> V_52 ;
int V_294 = 0 ;
struct V_87 * V_88 ;
struct V_74 * V_75 = V_52 -> V_75 ;
V_8 = F_117 ( sizeof( * V_8 ) , V_59 ) ;
if ( ! V_8 )
return - V_60 ;
V_8 -> V_94 = F_310 ( & V_52 -> V_93 , 1 , 0 , V_59 ) ;
if ( V_8 -> V_94 < 0 )
goto V_426;
if ( ! F_161 ( V_100 ) ) {
V_294 = - V_245 ;
goto V_427;
}
F_29 ( & V_75 -> V_422 ) ;
F_106 ( V_8 ) ;
V_8 -> V_100 = V_100 ;
V_8 -> V_52 = V_100 -> V_52 ;
V_8 -> V_71 = V_100 -> V_71 ;
if ( F_10 ( V_100 ) )
F_24 ( V_13 , & V_8 -> V_10 ) ;
if ( F_8 ( V_135 , & V_100 -> V_10 ) )
F_24 ( V_135 , & V_8 -> V_10 ) ;
F_67 (root, ss) {
struct V_4 * V_5 ;
V_5 = V_88 -> V_428 ( V_8 ) ;
if ( F_129 ( V_5 ) ) {
V_294 = F_130 ( V_5 ) ;
goto V_429;
}
F_306 ( V_5 , V_88 , V_8 ) ;
if ( V_88 -> V_430 ) {
V_294 = F_311 ( V_88 , V_100 , V_8 ) ;
if ( V_294 )
goto V_429;
}
}
V_294 = F_212 ( V_14 , V_183 | V_73 , V_75 ) ;
if ( V_294 < 0 )
goto V_429;
F_80 ( & V_14 -> V_101 -> V_102 ) ;
V_14 -> V_15 = V_8 ;
V_8 -> V_14 = V_14 ;
F_46 ( & V_8 -> V_158 , & V_52 -> V_164 ) ;
F_312 ( & V_8 -> V_126 , & V_8 -> V_100 -> V_157 ) ;
V_52 -> V_90 ++ ;
F_67 (root, ss)
F_75 ( V_14 ) ;
F_67 (root, ss) {
V_294 = F_307 ( V_88 , V_8 ) ;
if ( V_294 )
goto V_431;
if ( V_88 -> V_432 && ! V_88 -> V_433 &&
V_100 -> V_100 ) {
F_103 ( L_27 ,
V_155 -> V_156 , V_155 -> V_242 , V_88 -> V_98 ) ;
if ( ! strcmp ( V_88 -> V_98 , L_28 ) )
F_103 ( L_29 ) ;
V_88 -> V_433 = true ;
}
}
V_294 = F_105 ( V_8 , true , V_52 -> V_58 ) ;
if ( V_294 )
goto V_431;
F_58 ( & V_1 ) ;
F_58 ( & V_8 -> V_14 -> V_101 -> V_102 ) ;
return 0 ;
V_429:
F_67 (root, ss) {
if ( V_8 -> V_45 [ V_88 -> V_108 ] )
V_88 -> V_89 ( V_8 ) ;
}
F_58 ( & V_1 ) ;
F_68 ( V_75 ) ;
V_427:
F_70 ( & V_52 -> V_93 , V_8 -> V_94 ) ;
V_426:
F_26 ( V_8 ) ;
return V_294 ;
V_431:
F_313 ( V_8 ) ;
F_58 ( & V_1 ) ;
F_58 ( & V_14 -> V_101 -> V_102 ) ;
return V_294 ;
}
static int F_314 ( struct V_72 * V_104 , struct V_14 * V_14 , T_1 V_73 )
{
struct V_7 * V_434 = V_14 -> V_96 -> V_15 ;
return F_309 ( V_434 , V_14 , V_73 | V_183 ) ;
}
static int F_315 ( struct V_7 * V_8 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
struct V_87 * V_88 = V_45 [ V_19 ] ;
struct V_4 * V_5 ;
if ( V_88 == NULL || V_88 -> V_52 != V_8 -> V_52 )
continue;
V_5 = V_8 -> V_45 [ V_88 -> V_108 ] ;
if ( V_5 && F_5 ( V_5 ) > 1 )
return 1 ;
}
return 0 ;
}
static int F_313 ( struct V_7 * V_8 )
__releases( &cgroup_mutex
static int F_316 ( struct V_72 * V_435 , struct V_14 * V_14 )
{
int V_153 ;
F_56 ( & V_1 ) ;
V_153 = F_313 ( V_14 -> V_15 ) ;
F_58 ( & V_1 ) ;
return V_153 ;
}
static void T_11 F_317 ( struct V_87 * V_88 )
{
F_39 ( & V_88 -> V_324 ) ;
if ( V_88 -> V_436 ) {
V_88 -> V_437 . V_109 = V_88 -> V_436 ;
F_46 ( & V_88 -> V_437 . V_57 , & V_88 -> V_324 ) ;
}
}
static void T_12 F_318 ( struct V_87 * V_88 )
{
struct V_4 * V_5 ;
F_319 ( V_438 L_30 , V_88 -> V_98 ) ;
F_56 ( & V_1 ) ;
F_317 ( V_88 ) ;
F_41 ( & V_88 -> V_126 , & V_123 . V_127 ) ;
V_88 -> V_52 = & V_123 ;
V_5 = V_88 -> V_428 ( V_125 ) ;
F_33 ( F_129 ( V_5 ) ) ;
F_306 ( V_5 , V_88 , V_125 ) ;
V_70 . V_45 [ V_88 -> V_108 ] = V_5 ;
V_439 |= V_88 -> V_440 || V_88 -> exit ;
F_33 ( ! F_43 ( & V_441 . V_65 ) ) ;
V_88 -> V_442 = 1 ;
F_33 ( F_307 ( V_88 , V_125 ) ) ;
F_58 ( & V_1 ) ;
F_33 ( V_88 -> V_129 ) ;
}
int T_11 F_320 ( struct V_87 * V_88 )
{
struct V_4 * V_5 ;
int V_19 , V_153 ;
if ( V_88 -> V_98 == NULL || strlen ( V_88 -> V_98 ) > V_318 ||
V_88 -> V_428 == NULL || V_88 -> V_89 == NULL )
return - V_146 ;
if ( V_88 -> V_440 || V_88 -> exit )
return - V_146 ;
if ( V_88 -> V_129 == NULL ) {
F_33 ( V_45 [ V_88 -> V_108 ] != V_88 ) ;
return 0 ;
}
F_317 ( V_88 ) ;
F_56 ( & V_1 ) ;
V_45 [ V_88 -> V_108 ] = V_88 ;
V_5 = V_88 -> V_428 ( V_125 ) ;
if ( F_129 ( V_5 ) ) {
V_45 [ V_88 -> V_108 ] = NULL ;
F_58 ( & V_1 ) ;
return F_130 ( V_5 ) ;
}
F_41 ( & V_88 -> V_126 , & V_123 . V_127 ) ;
V_88 -> V_52 = & V_123 ;
F_306 ( V_5 , V_88 , V_125 ) ;
if ( V_88 -> V_430 ) {
V_153 = F_321 ( V_88 , V_5 ) ;
if ( V_153 )
goto V_443;
}
F_18 ( & V_32 ) ;
for ( V_19 = 0 ; V_19 < V_204 ; V_19 ++ ) {
struct V_25 * V_26 ;
struct V_56 * V_57 , * V_21 ;
struct V_18 * V_444 = & V_24 [ V_19 ] , * V_445 ;
F_322 (cg, node, tmp, bucket, hlist) {
if ( V_26 -> V_45 [ V_88 -> V_108 ] )
continue;
F_21 ( & V_26 -> V_33 ) ;
V_26 -> V_45 [ V_88 -> V_108 ] = V_5 ;
V_445 = F_14 ( V_26 -> V_45 ) ;
F_53 ( & V_26 -> V_33 , V_445 ) ;
}
}
F_20 ( & V_32 ) ;
V_88 -> V_442 = 1 ;
V_153 = F_307 ( V_88 , V_125 ) ;
if ( V_153 )
goto V_443;
F_58 ( & V_1 ) ;
return 0 ;
V_443:
F_58 ( & V_1 ) ;
F_323 ( V_88 ) ;
return V_153 ;
}
void F_323 ( struct V_87 * V_88 )
{
struct V_28 * V_29 ;
struct V_18 * V_55 ;
F_33 ( V_88 -> V_129 == NULL ) ;
F_33 ( V_88 -> V_52 != & V_123 ) ;
F_56 ( & V_1 ) ;
F_308 ( V_88 , V_125 ) ;
V_88 -> V_442 = 0 ;
if ( V_88 -> V_430 ) {
F_324 ( & V_88 -> V_446 ) ;
F_325 ( & V_88 -> V_446 ) ;
}
V_45 [ V_88 -> V_108 ] = NULL ;
F_82 ( & V_88 -> V_126 ) ;
F_18 ( & V_32 ) ;
F_52 (link, &dummytop->css_sets, cgrp_link_list) {
struct V_25 * V_26 = V_29 -> V_26 ;
F_21 ( & V_26 -> V_33 ) ;
V_26 -> V_45 [ V_88 -> V_108 ] = NULL ;
V_55 = F_14 ( V_26 -> V_45 ) ;
F_53 ( & V_26 -> V_33 , V_55 ) ;
}
F_20 ( & V_32 ) ;
V_88 -> V_89 ( V_125 ) ;
V_125 -> V_45 [ V_88 -> V_108 ] = NULL ;
F_58 ( & V_1 ) ;
}
int T_12 F_326 ( void )
{
int V_19 ;
F_50 ( & V_70 . V_31 , 1 ) ;
F_39 ( & V_70 . V_46 ) ;
F_39 ( & V_70 . V_65 ) ;
F_51 ( & V_70 . V_33 ) ;
V_34 = 1 ;
F_110 ( & V_123 ) ;
V_64 = 1 ;
V_441 . V_69 = & V_70 ;
V_447 . V_26 = & V_70 ;
V_447 . V_8 = V_125 ;
F_41 ( & V_447 . V_36 ,
& V_123 . V_71 . V_62 ) ;
F_41 ( & V_447 . V_35 ,
& V_70 . V_46 ) ;
for ( V_19 = 0 ; V_19 < V_204 ; V_19 ++ )
F_327 ( & V_24 [ V_19 ] ) ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
struct V_87 * V_88 = V_45 [ V_19 ] ;
if ( ! V_88 || V_88 -> V_129 )
continue;
F_33 ( ! V_88 -> V_98 ) ;
F_33 ( strlen ( V_88 -> V_98 ) > V_318 ) ;
F_33 ( ! V_88 -> V_428 ) ;
F_33 ( ! V_88 -> V_89 ) ;
if ( V_88 -> V_108 != V_19 ) {
F_319 ( V_448 L_31 ,
V_88 -> V_98 , V_88 -> V_108 ) ;
F_328 () ;
}
if ( V_88 -> V_449 )
F_318 ( V_88 ) ;
}
return 0 ;
}
int T_12 F_329 ( void )
{
int V_294 ;
int V_19 ;
struct V_18 * V_55 ;
V_294 = F_330 ( & V_86 ) ;
if ( V_294 )
return V_294 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
struct V_87 * V_88 = V_45 [ V_19 ] ;
if ( ! V_88 || V_88 -> V_129 )
continue;
if ( ! V_88 -> V_449 )
F_318 ( V_88 ) ;
if ( V_88 -> V_430 )
F_321 ( V_88 , V_70 . V_45 [ V_88 -> V_108 ] ) ;
}
V_55 = F_14 ( V_70 . V_45 ) ;
F_53 ( & V_70 . V_33 , V_55 ) ;
F_33 ( ! F_111 ( & V_123 ) ) ;
V_450 = F_331 ( L_32 , V_451 ) ;
if ( ! V_450 ) {
V_294 = - V_60 ;
goto V_230;
}
V_294 = F_332 ( & V_452 ) ;
if ( V_294 < 0 ) {
F_333 ( V_450 ) ;
goto V_230;
}
F_334 ( L_33 , 0 , NULL , & V_453 ) ;
V_230:
if ( V_294 )
F_335 ( & V_86 ) ;
return V_294 ;
}
static int F_336 ( struct V_130 * V_287 , void * V_6 )
{
struct V_242 * V_242 ;
struct V_67 * V_222 ;
char * V_206 ;
int V_226 ;
struct V_54 * V_52 ;
V_226 = - V_60 ;
V_206 = F_40 ( V_351 , V_59 ) ;
if ( ! V_206 )
goto V_230;
V_226 = - V_228 ;
V_242 = V_287 -> V_277 ;
V_222 = F_337 ( V_242 , V_454 ) ;
if ( ! V_222 )
goto V_455;
V_226 = 0 ;
F_56 ( & V_1 ) ;
F_132 (root) {
struct V_87 * V_88 ;
struct V_7 * V_8 ;
int V_37 = 0 ;
F_94 ( V_287 , L_34 , V_52 -> V_168 ) ;
F_67 (root, ss)
F_94 ( V_287 , L_35 , V_37 ++ ? L_8 : L_36 , V_88 -> V_98 ) ;
if ( strlen ( V_52 -> V_98 ) )
F_94 ( V_287 , L_37 , V_37 ? L_8 : L_36 ,
V_52 -> V_98 ) ;
F_176 ( V_287 , ':' ) ;
V_8 = F_54 ( V_222 , V_52 ) ;
V_226 = F_138 ( V_8 , V_206 , V_351 ) ;
if ( V_226 < 0 )
goto V_154;
F_95 ( V_287 , V_206 ) ;
F_176 ( V_287 , '\n' ) ;
}
V_154:
F_58 ( & V_1 ) ;
F_170 ( V_222 ) ;
V_455:
F_26 ( V_206 ) ;
V_230:
return V_226 ;
}
static int F_338 ( struct V_72 * V_72 , struct V_258 * V_258 )
{
struct V_242 * V_242 = F_339 ( V_72 ) -> V_242 ;
return F_194 ( V_258 , F_336 , V_242 ) ;
}
static int F_340 ( struct V_130 * V_287 , void * V_6 )
{
int V_19 ;
F_95 ( V_287 , L_38 ) ;
F_56 ( & V_1 ) ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
struct V_87 * V_88 = V_45 [ V_19 ] ;
if ( V_88 == NULL )
continue;
F_94 ( V_287 , L_39 ,
V_88 -> V_98 , V_88 -> V_52 -> V_168 ,
V_88 -> V_52 -> V_90 , ! V_88 -> V_152 ) ;
}
F_58 ( & V_1 ) ;
return 0 ;
}
static int F_341 ( struct V_72 * V_72 , struct V_258 * V_258 )
{
return F_194 ( V_258 , F_340 , NULL ) ;
}
void F_342 ( struct V_67 * V_456 )
{
F_148 ( V_155 ) ;
V_456 -> V_69 = V_155 -> V_69 ;
F_28 ( V_456 -> V_69 ) ;
F_150 ( V_155 ) ;
F_39 ( & V_456 -> V_225 ) ;
}
void F_343 ( struct V_67 * V_456 )
{
int V_19 ;
if ( V_331 ) {
F_18 ( & V_32 ) ;
F_148 ( V_456 ) ;
if ( F_43 ( & V_456 -> V_225 ) )
F_41 ( & V_456 -> V_225 , & V_456 -> V_69 -> V_65 ) ;
F_150 ( V_456 ) ;
F_20 ( & V_32 ) ;
}
if ( V_439 ) {
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
struct V_87 * V_88 = V_45 [ V_19 ] ;
if ( ! V_88 || V_88 -> V_129 )
continue;
if ( V_88 -> V_440 )
V_88 -> V_440 ( V_456 ) ;
}
}
}
void F_344 ( struct V_67 * V_222 , int V_457 )
{
struct V_25 * V_26 ;
int V_19 ;
if ( ! F_43 ( & V_222 -> V_225 ) ) {
F_18 ( & V_32 ) ;
if ( ! F_43 ( & V_222 -> V_225 ) )
F_82 ( & V_222 -> V_225 ) ;
F_20 ( & V_32 ) ;
}
F_148 ( V_222 ) ;
V_26 = V_222 -> V_69 ;
V_222 -> V_69 = & V_70 ;
if ( V_457 && V_439 ) {
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
struct V_87 * V_88 = V_45 [ V_19 ] ;
if ( ! V_88 || V_88 -> V_129 )
continue;
if ( V_88 -> exit ) {
struct V_7 * V_458 =
F_345 ( V_26 -> V_45 [ V_19 ] ) -> V_7 ;
struct V_7 * V_8 = F_346 ( V_222 , V_19 ) ;
V_88 -> exit ( V_8 , V_458 , V_222 ) ;
}
}
}
F_150 ( V_222 ) ;
if ( V_26 )
F_31 ( V_26 ) ;
}
int F_347 ( const struct V_7 * V_8 , struct V_67 * V_68 )
{
int V_153 ;
struct V_7 * V_459 ;
if ( V_8 == V_125 )
return 1 ;
V_459 = F_54 ( V_68 , V_8 -> V_52 ) ;
while ( V_8 != V_459 && V_8 != V_8 -> V_71 )
V_8 = V_8 -> V_100 ;
V_153 = ( V_8 == V_459 ) ;
return V_153 ;
}
static void F_25 ( struct V_7 * V_8 )
{
if ( F_9 ( V_8 ) && ! F_6 ( & V_8 -> V_37 )
&& F_43 ( & V_8 -> V_157 ) && ! F_315 ( V_8 ) ) {
int V_460 = 0 ;
F_348 ( & V_461 ) ;
if ( ! F_7 ( V_8 ) &&
F_43 ( & V_8 -> V_159 ) ) {
F_41 ( & V_8 -> V_159 , & V_159 ) ;
V_460 = 1 ;
}
F_349 ( & V_461 ) ;
if ( V_460 )
F_289 ( & V_462 ) ;
}
}
bool F_350 ( struct V_4 * V_5 )
{
while ( true ) {
int V_463 , V_6 ;
V_6 = F_5 ( V_5 ) ;
V_463 = F_351 ( & V_5 -> V_2 , V_6 , V_6 + 1 ) ;
if ( F_352 ( V_463 == V_6 ) )
return true ;
else if ( V_463 < 0 )
return false ;
F_353 () ;
}
}
void F_354 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_7 ;
int V_6 ;
F_157 () ;
V_6 = F_4 ( F_355 ( & V_5 -> V_2 ) ) ;
switch ( V_6 ) {
case 1 :
if ( F_10 ( V_8 ) ) {
F_24 ( V_12 , & V_8 -> V_10 ) ;
F_25 ( V_8 ) ;
}
break;
case 0 :
F_289 ( & V_5 -> V_421 ) ;
break;
}
F_163 () ;
}
static void F_356 ( struct V_399 * V_400 )
{
F_33 ( V_400 != & V_462 ) ;
F_56 ( & V_1 ) ;
F_348 ( & V_461 ) ;
while ( ! F_43 ( & V_159 ) ) {
char * V_464 [ 3 ] , * V_465 [ 3 ] ;
int V_19 ;
char * V_466 = NULL , * V_467 = NULL ;
struct V_7 * V_8 = F_34 ( V_159 . V_51 ,
struct V_7 ,
V_159 ) ;
F_82 ( & V_8 -> V_159 ) ;
F_349 ( & V_461 ) ;
V_466 = F_40 ( V_351 , V_59 ) ;
if ( ! V_466 )
goto V_468;
if ( F_138 ( V_8 , V_466 , V_351 ) < 0 )
goto V_468;
V_467 = F_357 ( V_8 -> V_52 -> V_134 , V_59 ) ;
if ( ! V_467 )
goto V_468;
V_19 = 0 ;
V_464 [ V_19 ++ ] = V_467 ;
V_464 [ V_19 ++ ] = V_466 ;
V_464 [ V_19 ] = NULL ;
V_19 = 0 ;
V_465 [ V_19 ++ ] = L_40 ;
V_465 [ V_19 ++ ] = L_41 ;
V_465 [ V_19 ] = NULL ;
F_58 ( & V_1 ) ;
F_358 ( V_464 [ 0 ] , V_464 , V_465 , V_469 ) ;
F_56 ( & V_1 ) ;
V_468:
F_26 ( V_466 ) ;
F_26 ( V_467 ) ;
F_348 ( & V_461 ) ;
}
F_349 ( & V_461 ) ;
F_58 ( & V_1 ) ;
}
static int T_12 F_359 ( char * V_470 )
{
int V_19 ;
char * V_139 ;
while ( ( V_139 = F_98 ( & V_470 , L_8 ) ) != NULL ) {
if ( ! * V_139 )
continue;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
struct V_87 * V_88 = V_45 [ V_19 ] ;
if ( ! V_88 || V_88 -> V_129 )
continue;
if ( ! strcmp ( V_139 , V_88 -> V_98 ) ) {
V_88 -> V_152 = 1 ;
F_319 ( V_438 L_42
L_43 , V_88 -> V_98 ) ;
break;
}
}
}
return 1 ;
}
unsigned short F_360 ( struct V_4 * V_5 )
{
struct F_360 * V_471 ;
V_471 = F_361 ( V_5 -> V_94 , F_5 ( V_5 ) ) ;
if ( V_471 )
return V_471 -> V_94 ;
return 0 ;
}
unsigned short F_362 ( struct V_4 * V_5 )
{
struct F_360 * V_471 ;
V_471 = F_361 ( V_5 -> V_94 , F_5 ( V_5 ) ) ;
if ( V_471 )
return V_471 -> V_472 ;
return 0 ;
}
bool F_363 ( struct V_4 * V_456 ,
const struct V_4 * V_52 )
{
struct F_360 * V_473 ;
struct F_360 * V_474 ;
V_473 = F_364 ( V_456 -> V_94 ) ;
if ( ! V_473 )
return false ;
V_474 = F_364 ( V_52 -> V_94 ) ;
if ( ! V_474 )
return false ;
if ( V_473 -> V_472 < V_474 -> V_472 )
return false ;
if ( V_473 -> V_475 [ V_474 -> V_472 ] != V_474 -> V_94 )
return false ;
return true ;
}
void F_365 ( struct V_87 * V_88 , struct V_4 * V_5 )
{
struct F_360 * V_94 = V_5 -> V_94 ;
if ( ! V_94 )
return;
F_33 ( ! V_88 -> V_430 ) ;
F_149 ( V_94 -> V_5 , NULL ) ;
F_149 ( V_5 -> V_94 , NULL ) ;
F_86 ( & V_88 -> V_476 ) ;
F_366 ( & V_88 -> V_446 , V_94 -> V_94 ) ;
F_88 ( & V_88 -> V_476 ) ;
F_27 ( V_94 , V_38 ) ;
}
static struct F_360 * F_367 ( struct V_87 * V_88 , int V_472 )
{
struct F_360 * V_477 ;
int V_478 , error , V_312 ;
F_33 ( ! V_88 -> V_430 ) ;
V_312 = sizeof( * V_477 ) + sizeof( unsigned short ) * ( V_472 + 1 ) ;
V_477 = F_117 ( V_312 , V_59 ) ;
if ( ! V_477 )
return F_118 ( - V_60 ) ;
if ( F_260 ( ! F_368 ( & V_88 -> V_446 , V_59 ) ) ) {
error = - V_60 ;
goto V_479;
}
F_86 ( & V_88 -> V_476 ) ;
error = F_369 ( & V_88 -> V_446 , V_477 , 1 , & V_478 ) ;
F_88 ( & V_88 -> V_476 ) ;
if ( error ) {
error = - V_169 ;
goto V_479;
}
if ( V_478 > V_480 )
goto V_481;
V_477 -> V_94 = V_478 ;
V_477 -> V_472 = V_472 ;
return V_477 ;
V_481:
error = - V_169 ;
F_86 ( & V_88 -> V_476 ) ;
F_366 ( & V_88 -> V_446 , V_478 ) ;
F_88 ( & V_88 -> V_476 ) ;
V_479:
F_26 ( V_477 ) ;
return F_118 ( error ) ;
}
static int T_11 F_321 ( struct V_87 * V_88 ,
struct V_4 * V_482 )
{
struct F_360 * V_477 ;
F_108 ( & V_88 -> V_476 ) ;
F_370 ( & V_88 -> V_446 ) ;
V_477 = F_367 ( V_88 , 0 ) ;
if ( F_129 ( V_477 ) )
return F_130 ( V_477 ) ;
V_477 -> V_475 [ 0 ] = V_477 -> V_94 ;
V_477 -> V_5 = V_482 ;
V_482 -> V_94 = V_477 ;
return 0 ;
}
static int F_311 ( struct V_87 * V_88 , struct V_7 * V_100 ,
struct V_7 * V_456 )
{
int V_108 , V_19 , V_472 = 0 ;
struct V_4 * V_483 , * V_484 ;
struct F_360 * V_473 , * V_485 ;
V_108 = V_88 -> V_108 ;
V_483 = V_100 -> V_45 [ V_108 ] ;
V_484 = V_456 -> V_45 [ V_108 ] ;
V_485 = V_483 -> V_94 ;
V_472 = V_485 -> V_472 + 1 ;
V_473 = F_367 ( V_88 , V_472 ) ;
if ( F_129 ( V_473 ) )
return F_130 ( V_473 ) ;
for ( V_19 = 0 ; V_19 < V_472 ; V_19 ++ )
V_473 -> V_475 [ V_19 ] = V_485 -> V_475 [ V_19 ] ;
V_473 -> V_475 [ V_472 ] = V_473 -> V_94 ;
F_149 ( V_484 -> V_94 , V_473 ) ;
return 0 ;
}
struct V_4 * F_371 ( struct V_87 * V_88 , int V_94 )
{
struct F_360 * V_471 = NULL ;
F_33 ( ! V_88 -> V_430 ) ;
V_471 = F_372 ( & V_88 -> V_446 , V_94 ) ;
if ( F_260 ( ! V_471 ) )
return NULL ;
return F_364 ( V_471 -> V_5 ) ;
}
struct V_4 *
F_373 ( struct V_87 * V_88 , int V_94 ,
struct V_4 * V_52 , int * V_486 )
{
struct V_4 * V_153 = NULL ;
struct F_360 * V_21 ;
int V_487 ;
int V_488 = F_360 ( V_52 ) ;
int V_472 = F_362 ( V_52 ) ;
if ( ! V_488 )
return NULL ;
F_33 ( ! V_88 -> V_430 ) ;
F_147 ( ! F_140 () ) ;
V_487 = V_94 ;
while ( 1 ) {
V_21 = F_374 ( & V_88 -> V_446 , & V_487 ) ;
if ( ! V_21 )
break;
if ( V_21 -> V_472 >= V_472 && V_21 -> V_475 [ V_472 ] == V_488 ) {
V_153 = F_364 ( V_21 -> V_5 ) ;
if ( V_153 ) {
* V_486 = V_487 ;
break;
}
}
V_487 = V_487 + 1 ;
}
return V_153 ;
}
struct V_4 * F_375 ( struct V_258 * V_489 , int V_94 )
{
struct V_7 * V_8 ;
struct V_72 * V_72 ;
struct V_4 * V_5 ;
V_72 = V_489 -> V_274 -> V_101 ;
if ( V_72 -> V_189 != & V_190 )
return F_118 ( - V_416 ) ;
if ( V_94 < 0 || V_94 >= V_22 )
return F_118 ( - V_146 ) ;
V_8 = F_11 ( V_489 -> V_274 ) ;
V_5 = V_8 -> V_45 [ V_94 ] ;
return V_5 ? V_5 : F_118 ( - V_103 ) ;
}
static struct V_4 * F_376 ( struct V_7 * V_490 )
{
struct V_4 * V_5 = F_117 ( sizeof( * V_5 ) , V_59 ) ;
if ( ! V_5 )
return F_118 ( - V_60 ) ;
return V_5 ;
}
static void F_377 ( struct V_7 * V_490 )
{
F_26 ( V_490 -> V_45 [ V_491 ] ) ;
}
static T_2 F_378 ( struct V_7 * V_490 , struct V_17 * V_97 )
{
return F_6 ( & V_490 -> V_37 ) ;
}
static T_2 F_379 ( struct V_7 * V_490 , struct V_17 * V_97 )
{
return F_223 ( V_490 ) ;
}
static T_2 F_380 ( struct V_7 * V_490 , struct V_17 * V_97 )
{
return ( T_2 ) ( unsigned long ) V_155 -> V_69 ;
}
static T_2 F_381 ( struct V_7 * V_490 ,
struct V_17 * V_97 )
{
T_2 V_37 ;
F_157 () ;
V_37 = F_6 ( & V_155 -> V_69 -> V_31 ) ;
F_163 () ;
return V_37 ;
}
static int F_382 ( struct V_7 * V_490 ,
struct V_17 * V_97 ,
struct V_130 * V_131 )
{
struct V_28 * V_29 ;
struct V_25 * V_26 ;
F_48 ( & V_32 ) ;
F_157 () ;
V_26 = F_364 ( V_155 -> V_69 ) ;
F_52 (link, &cg->cg_links, cg_link_list) {
struct V_7 * V_66 = V_29 -> V_8 ;
const char * V_98 ;
if ( V_66 -> V_14 )
V_98 = V_66 -> V_14 -> V_210 . V_98 ;
else
V_98 = L_44 ;
F_94 ( V_131 , L_45 ,
V_66 -> V_52 -> V_168 , V_98 ) ;
}
F_163 () ;
F_49 ( & V_32 ) ;
return 0 ;
}
static int F_383 ( struct V_7 * V_490 ,
struct V_17 * V_97 ,
struct V_130 * V_131 )
{
struct V_28 * V_29 ;
F_48 ( & V_32 ) ;
F_52 (link, &cont->css_sets, cgrp_link_list) {
struct V_25 * V_26 = V_29 -> V_26 ;
struct V_67 * V_68 ;
int V_37 = 0 ;
F_94 ( V_131 , L_46 , V_26 ) ;
F_52 (task, &cg->tasks, cg_list) {
if ( V_37 ++ > V_492 ) {
F_95 ( V_131 , L_47 ) ;
break;
} else {
F_94 ( V_131 , L_48 ,
F_262 ( V_68 ) ) ;
}
}
}
F_49 ( & V_32 ) ;
return 0 ;
}
static T_2 F_384 ( struct V_7 * V_8 , struct V_17 * V_97 )
{
return F_8 ( V_12 , & V_8 -> V_10 ) ;
}
