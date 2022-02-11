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
F_28 ( V_8 , V_39 ) ;
} else {
struct V_17 * V_96 = F_13 ( V_15 ) ;
struct V_7 * V_8 = V_15 -> V_97 -> V_16 ;
F_72 ( ! F_44 ( & V_96 -> V_58 ) &&
V_8 != & V_8 -> V_53 -> V_72 ,
L_1 , V_96 -> type -> V_98 ) ;
F_27 ( V_96 ) ;
}
F_73 ( V_73 ) ;
}
static int F_74 ( const struct V_15 * V_99 )
{
return 1 ;
}
static void F_75 ( struct V_15 * V_99 )
{
struct V_15 * V_100 = F_76 ( V_99 -> V_97 ) ;
F_77 ( V_99 ) ;
F_78 ( V_100 -> V_101 , V_99 ) ;
F_79 ( V_100 ) ;
}
static int F_80 ( struct V_7 * V_8 , const struct V_18 * V_102 )
{
struct V_17 * V_96 ;
F_81 ( & V_8 -> V_15 -> V_101 -> V_103 ) ;
F_81 ( & V_1 ) ;
F_53 (cfe, &cgrp->files, node) {
struct V_15 * V_99 = V_96 -> V_15 ;
if ( V_102 && V_96 -> type != V_102 )
continue;
F_76 ( V_99 ) ;
F_77 ( V_99 ) ;
F_82 ( V_8 -> V_15 -> V_101 , V_99 ) ;
F_83 ( & V_96 -> V_58 ) ;
F_79 ( V_99 ) ;
return 0 ;
}
return - V_104 ;
}
static void F_84 ( struct V_15 * V_105 )
{
struct V_7 * V_8 = F_12 ( V_105 ) ;
while ( ! F_44 ( & V_8 -> V_106 ) )
F_80 ( V_8 , NULL ) ;
}
static void F_85 ( struct V_15 * V_15 )
{
struct V_15 * V_100 ;
F_84 ( V_15 ) ;
V_100 = V_15 -> V_97 ;
F_86 ( & V_100 -> V_107 ) ;
F_87 ( & V_15 -> V_107 , V_108 ) ;
F_83 ( & V_15 -> V_109 . V_110 ) ;
F_88 ( & V_15 -> V_107 ) ;
F_88 ( & V_100 -> V_107 ) ;
F_75 ( V_15 ) ;
}
static void F_89 ( struct V_7 * V_8 )
{
if ( F_90 ( F_91 ( V_111 , & V_8 -> V_10 ) ) )
F_92 ( & V_112 ) ;
}
void F_93 ( struct V_4 * V_5 )
{
F_94 ( V_5 ) ;
}
void F_95 ( struct V_4 * V_5 )
{
F_89 ( V_5 -> V_7 ) ;
F_96 ( V_5 ) ;
}
static int F_97 ( struct V_55 * V_53 ,
unsigned long V_113 )
{
unsigned long V_114 , V_115 ;
struct V_7 * V_8 = & V_53 -> V_72 ;
int V_20 ;
F_34 ( ! F_3 ( & V_1 ) ) ;
F_34 ( ! F_3 ( & V_116 ) ) ;
V_115 = V_53 -> V_117 & ~ V_113 ;
V_114 = V_113 & ~ V_53 -> V_117 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
unsigned long V_118 = 1UL << V_20 ;
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( ! ( V_118 & V_114 ) )
continue;
F_34 ( V_89 == NULL ) ;
if ( V_89 -> V_53 != & V_119 ) {
return - V_120 ;
}
}
if ( V_53 -> V_94 > 1 )
return - V_120 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
unsigned long V_118 = 1UL << V_20 ;
if ( V_118 & V_114 ) {
F_34 ( V_89 == NULL ) ;
F_34 ( V_8 -> V_46 [ V_20 ] ) ;
F_34 ( ! V_121 -> V_46 [ V_20 ] ) ;
F_34 ( V_121 -> V_46 [ V_20 ] -> V_7 != V_121 ) ;
V_8 -> V_46 [ V_20 ] = V_121 -> V_46 [ V_20 ] ;
V_8 -> V_46 [ V_20 ] -> V_7 = V_8 ;
F_46 ( & V_89 -> V_122 , & V_53 -> V_123 ) ;
V_89 -> V_53 = V_53 ;
if ( V_89 -> V_124 )
V_89 -> V_124 ( V_8 ) ;
} else if ( V_118 & V_115 ) {
F_34 ( V_89 == NULL ) ;
F_34 ( V_8 -> V_46 [ V_20 ] != V_121 -> V_46 [ V_20 ] ) ;
F_34 ( V_8 -> V_46 [ V_20 ] -> V_7 != V_8 ) ;
if ( V_89 -> V_124 )
V_89 -> V_124 ( V_121 ) ;
V_121 -> V_46 [ V_20 ] -> V_7 = V_121 ;
V_8 -> V_46 [ V_20 ] = NULL ;
V_46 [ V_20 ] -> V_53 = & V_119 ;
F_46 ( & V_89 -> V_122 , & V_119 . V_123 ) ;
F_98 ( V_89 -> V_125 ) ;
} else if ( V_118 & V_113 ) {
F_34 ( V_89 == NULL ) ;
F_34 ( ! V_8 -> V_46 [ V_20 ] ) ;
F_98 ( V_89 -> V_125 ) ;
#ifdef F_99
F_34 ( V_89 -> V_125 && ! F_100 ( V_89 -> V_125 ) ) ;
#endif
} else {
F_34 ( V_8 -> V_46 [ V_20 ] ) ;
}
}
V_53 -> V_59 = V_53 -> V_117 = V_113 ;
F_70 () ;
return 0 ;
}
static int F_101 ( struct V_126 * V_127 , struct V_15 * V_15 )
{
struct V_55 * V_53 = V_15 -> V_128 -> V_129 ;
struct V_88 * V_89 ;
F_57 ( & V_116 ) ;
F_66 (root, ss)
F_102 ( V_127 , L_2 , V_89 -> V_98 ) ;
if ( F_8 ( V_130 , & V_53 -> V_10 ) )
F_103 ( V_127 , L_3 ) ;
if ( strlen ( V_53 -> V_131 ) )
F_102 ( V_127 , L_4 , V_53 -> V_131 ) ;
if ( F_11 ( & V_53 -> V_72 ) )
F_103 ( V_127 , L_5 ) ;
if ( strlen ( V_53 -> V_98 ) )
F_102 ( V_127 , L_6 , V_53 -> V_98 ) ;
F_59 ( & V_116 ) ;
return 0 ;
}
static int F_104 ( char * V_132 , struct V_133 * V_134 )
{
char * V_135 , * V_136 = V_132 ;
bool V_137 = false , V_138 = false ;
unsigned long V_139 = ( unsigned long ) - 1 ;
int V_20 ;
bool V_140 = false ;
F_34 ( ! F_3 ( & V_1 ) ) ;
#ifdef F_105
V_139 = ~ ( 1UL << V_141 ) ;
#endif
memset ( V_134 , 0 , sizeof( * V_134 ) ) ;
while ( ( V_135 = F_106 ( & V_136 , L_7 ) ) != NULL ) {
if ( ! * V_135 )
return - V_142 ;
if ( ! strcmp ( V_135 , L_8 ) ) {
V_134 -> V_143 = true ;
continue;
}
if ( ! strcmp ( V_135 , L_9 ) ) {
if ( V_138 )
return - V_142 ;
V_137 = true ;
continue;
}
if ( ! strcmp ( V_135 , L_10 ) ) {
F_25 ( V_130 , & V_134 -> V_10 ) ;
continue;
}
if ( ! strcmp ( V_135 , L_11 ) ) {
V_134 -> F_11 = true ;
continue;
}
if ( ! strncmp ( V_135 , L_12 , 14 ) ) {
if ( V_134 -> V_144 )
return - V_142 ;
V_134 -> V_144 =
F_107 ( V_135 + 14 , V_145 - 1 , V_60 ) ;
if ( ! V_134 -> V_144 )
return - V_61 ;
continue;
}
if ( ! strncmp ( V_135 , L_13 , 5 ) ) {
const char * V_98 = V_135 + 5 ;
if ( ! strlen ( V_98 ) )
return - V_142 ;
for ( V_20 = 0 ; V_20 < strlen ( V_98 ) ; V_20 ++ ) {
char V_67 = V_98 [ V_20 ] ;
if ( isalnum ( V_67 ) )
continue;
if ( ( V_67 == '.' ) || ( V_67 == '-' ) || ( V_67 == '_' ) )
continue;
return - V_142 ;
}
if ( V_134 -> V_98 )
return - V_142 ;
V_134 -> V_98 = F_107 ( V_98 ,
V_146 - 1 ,
V_60 ) ;
if ( ! V_134 -> V_98 )
return - V_61 ;
continue;
}
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 == NULL )
continue;
if ( strcmp ( V_135 , V_89 -> V_98 ) )
continue;
if ( V_89 -> V_147 )
continue;
if ( V_137 )
return - V_142 ;
F_25 ( V_20 , & V_134 -> V_59 ) ;
V_138 = true ;
break;
}
if ( V_20 == V_23 )
return - V_104 ;
}
if ( V_137 || ( ! V_138 && ! V_134 -> V_143 && ! V_134 -> V_98 ) ) {
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 == NULL )
continue;
if ( V_89 -> V_147 )
continue;
F_25 ( V_20 , & V_134 -> V_59 ) ;
}
}
if ( F_8 ( V_130 , & V_134 -> V_10 ) &&
( V_134 -> V_59 & V_139 ) )
return - V_142 ;
if ( V_134 -> V_59 && V_134 -> V_143 )
return - V_142 ;
if ( ! V_134 -> V_59 && ! V_134 -> V_98 )
return - V_142 ;
for ( V_20 = V_148 ; V_20 < V_23 ; V_20 ++ ) {
unsigned long V_118 = 1UL << V_20 ;
if ( ! ( V_118 & V_134 -> V_59 ) )
continue;
if ( ! F_108 ( V_46 [ V_20 ] -> V_125 ) ) {
V_140 = true ;
break;
}
}
if ( V_140 ) {
for ( V_20 -- ; V_20 >= V_148 ; V_20 -- ) {
unsigned long V_118 = 1UL << V_20 ;
if ( ! ( V_118 & V_134 -> V_59 ) )
continue;
F_98 ( V_46 [ V_20 ] -> V_125 ) ;
}
return - V_104 ;
}
return 0 ;
}
static void F_109 ( unsigned long V_59 )
{
int V_20 ;
for ( V_20 = V_148 ; V_20 < V_23 ; V_20 ++ ) {
unsigned long V_118 = 1UL << V_20 ;
if ( ! ( V_118 & V_59 ) )
continue;
F_98 ( V_46 [ V_20 ] -> V_125 ) ;
}
}
static int F_110 ( struct V_75 * V_76 , int * V_10 , char * V_132 )
{
int V_90 = 0 ;
struct V_55 * V_53 = V_76 -> V_129 ;
struct V_7 * V_8 = & V_53 -> V_72 ;
struct V_133 V_134 ;
F_57 ( & V_8 -> V_15 -> V_101 -> V_103 ) ;
F_57 ( & V_1 ) ;
F_57 ( & V_116 ) ;
V_90 = F_104 ( V_132 , & V_134 ) ;
if ( V_90 )
goto V_149;
if ( V_134 . V_59 != V_53 -> V_117 || V_134 . V_144 )
F_111 ( L_14 ,
F_112 ( V_150 ) , V_150 -> V_151 ) ;
if ( V_134 . V_10 != V_53 -> V_10 ||
( V_134 . V_98 && strcmp ( V_134 . V_98 , V_53 -> V_98 ) ) ) {
V_90 = - V_142 ;
F_109 ( V_134 . V_59 ) ;
goto V_149;
}
V_90 = F_97 ( V_53 , V_134 . V_59 ) ;
if ( V_90 ) {
F_109 ( V_134 . V_59 ) ;
goto V_149;
}
F_84 ( V_8 -> V_15 ) ;
F_113 ( V_8 ) ;
if ( V_134 . V_144 )
strcpy ( V_53 -> V_131 , V_134 . V_144 ) ;
V_149:
F_27 ( V_134 . V_144 ) ;
F_27 ( V_134 . V_98 ) ;
F_59 ( & V_116 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_8 -> V_15 -> V_101 -> V_103 ) ;
return V_90 ;
}
static void F_114 ( struct V_7 * V_8 )
{
F_40 ( & V_8 -> V_122 ) ;
F_40 ( & V_8 -> V_152 ) ;
F_40 ( & V_8 -> V_106 ) ;
F_40 ( & V_8 -> V_63 ) ;
F_40 ( & V_8 -> V_153 ) ;
F_40 ( & V_8 -> V_95 ) ;
F_115 ( & V_8 -> V_154 ) ;
F_40 ( & V_8 -> V_155 ) ;
F_116 ( & V_8 -> V_156 ) ;
}
static void F_117 ( struct V_55 * V_53 )
{
struct V_7 * V_8 = & V_53 -> V_72 ;
F_40 ( & V_53 -> V_123 ) ;
F_40 ( & V_53 -> V_157 ) ;
F_40 ( & V_53 -> V_158 ) ;
V_53 -> V_94 = 1 ;
V_8 -> V_53 = V_53 ;
V_8 -> V_72 = V_8 ;
F_47 ( & V_8 -> V_159 , & V_53 -> V_158 ) ;
F_114 ( V_8 ) ;
}
static bool F_118 ( struct V_55 * V_53 )
{
int V_90 = 0 ;
do {
if ( ! F_119 ( & V_160 , V_60 ) )
return false ;
F_86 ( & V_161 ) ;
V_90 = F_120 ( & V_160 , V_162 ,
& V_53 -> V_163 ) ;
if ( V_90 == - V_164 )
V_90 = F_121 ( & V_160 , & V_53 -> V_163 ) ;
if ( ! V_90 ) {
V_162 = V_53 -> V_163 + 1 ;
} else if ( V_90 != - V_165 ) {
F_34 ( V_90 ) ;
}
F_88 ( & V_161 ) ;
} while ( V_90 );
return true ;
}
static int F_122 ( struct V_75 * V_76 , void * V_132 )
{
struct V_133 * V_134 = V_132 ;
struct V_55 * V_53 = V_76 -> V_129 ;
if ( V_134 -> V_98 && strcmp ( V_134 -> V_98 , V_53 -> V_98 ) )
return 0 ;
if ( ( V_134 -> V_59 || V_134 -> V_143 )
&& ( V_134 -> V_59 != V_53 -> V_59 ) )
return 0 ;
return 1 ;
}
static struct V_55 * F_123 ( struct V_133 * V_134 )
{
struct V_55 * V_53 ;
if ( ! V_134 -> V_59 && ! V_134 -> V_143 )
return NULL ;
V_53 = F_124 ( sizeof( * V_53 ) , V_60 ) ;
if ( ! V_53 )
return F_125 ( - V_61 ) ;
if ( ! F_118 ( V_53 ) ) {
F_27 ( V_53 ) ;
return F_125 ( - V_61 ) ;
}
F_117 ( V_53 ) ;
V_53 -> V_59 = V_134 -> V_59 ;
V_53 -> V_10 = V_134 -> V_10 ;
if ( V_134 -> V_144 )
strcpy ( V_53 -> V_131 , V_134 -> V_144 ) ;
if ( V_134 -> V_98 )
strcpy ( V_53 -> V_98 , V_134 -> V_98 ) ;
if ( V_134 -> F_11 )
F_25 ( V_14 , & V_53 -> V_72 . V_10 ) ;
return V_53 ;
}
static void F_126 ( struct V_55 * V_53 )
{
if ( ! V_53 )
return;
F_34 ( ! V_53 -> V_163 ) ;
F_86 ( & V_161 ) ;
F_127 ( & V_160 , V_53 -> V_163 ) ;
F_88 ( & V_161 ) ;
F_27 ( V_53 ) ;
}
static int F_128 ( struct V_75 * V_76 , void * V_132 )
{
int V_90 ;
struct V_133 * V_134 = V_132 ;
if ( ! V_134 -> V_166 )
return - V_142 ;
F_34 ( ! V_134 -> V_59 && ! V_134 -> V_143 ) ;
V_90 = F_129 ( V_76 , NULL ) ;
if ( V_90 )
return V_90 ;
V_76 -> V_129 = V_134 -> V_166 ;
V_134 -> V_166 -> V_76 = V_76 ;
V_76 -> V_167 = V_168 ;
V_76 -> V_169 = V_170 ;
V_76 -> V_171 = V_172 ;
V_76 -> V_173 = & V_174 ;
return 0 ;
}
static int F_130 ( struct V_75 * V_76 )
{
static const struct V_175 V_176 = {
. V_177 = F_68 ,
. F_77 = F_74 ,
} ;
struct V_73 * V_73 =
F_60 ( V_178 | V_179 | V_180 | V_181 , V_76 ) ;
if ( ! V_73 )
return - V_61 ;
V_73 -> V_182 = & V_183 ;
V_73 -> V_184 = & V_185 ;
F_131 ( V_73 ) ;
V_76 -> V_186 = F_132 ( V_73 ) ;
if ( ! V_76 -> V_186 )
return - V_61 ;
V_76 -> V_187 = & V_176 ;
return 0 ;
}
static struct V_15 * F_133 ( struct V_188 * V_189 ,
int V_10 , const char * V_190 ,
void * V_132 )
{
struct V_133 V_134 ;
struct V_55 * V_53 ;
int V_90 = 0 ;
struct V_75 * V_76 ;
struct V_55 * V_166 ;
struct V_73 * V_73 ;
F_57 ( & V_1 ) ;
V_90 = F_104 ( V_132 , & V_134 ) ;
F_59 ( & V_1 ) ;
if ( V_90 )
goto V_191;
V_166 = F_123 ( & V_134 ) ;
if ( F_134 ( V_166 ) ) {
V_90 = F_135 ( V_166 ) ;
goto V_192;
}
V_134 . V_166 = V_166 ;
V_76 = F_136 ( V_189 , F_122 , F_128 , 0 , & V_134 ) ;
if ( F_134 ( V_76 ) ) {
V_90 = F_135 ( V_76 ) ;
F_126 ( V_134 . V_166 ) ;
goto V_192;
}
V_53 = V_76 -> V_129 ;
F_34 ( ! V_53 ) ;
if ( V_53 == V_134 . V_166 ) {
struct V_43 V_62 ;
struct V_7 * V_193 = & V_53 -> V_72 ;
struct V_55 * V_194 ;
const struct V_195 * V_195 ;
int V_20 ;
F_34 ( V_76 -> V_186 != NULL ) ;
V_90 = F_130 ( V_76 ) ;
if ( V_90 )
goto V_196;
V_73 = V_76 -> V_186 -> V_101 ;
F_57 ( & V_73 -> V_103 ) ;
F_57 ( & V_1 ) ;
F_57 ( & V_116 ) ;
V_90 = - V_120 ;
if ( strlen ( V_53 -> V_98 ) )
F_137 (existing_root)
if ( ! strcmp ( V_194 -> V_98 , V_53 -> V_98 ) )
goto V_197;
V_90 = F_39 ( V_35 , & V_62 ) ;
if ( V_90 )
goto V_197;
V_90 = F_97 ( V_53 , V_53 -> V_59 ) ;
if ( V_90 == - V_120 ) {
F_38 ( & V_62 ) ;
goto V_197;
}
F_34 ( V_90 ) ;
F_42 ( & V_53 -> V_157 , & V_198 ) ;
V_65 ++ ;
V_76 -> V_186 -> V_16 = V_193 ;
V_53 -> V_72 . V_15 = V_76 -> V_186 ;
F_19 ( & V_33 ) ;
for ( V_20 = 0 ; V_20 < V_199 ; V_20 ++ ) {
struct V_19 * V_56 = & V_25 [ V_20 ] ;
struct V_57 * V_58 ;
struct V_26 * V_27 ;
F_37 (cg, node, hhead, hlist)
F_43 ( & V_62 , V_27 , V_193 ) ;
}
F_21 ( & V_33 ) ;
F_38 ( & V_62 ) ;
F_34 ( ! F_44 ( & V_193 -> V_122 ) ) ;
F_34 ( ! F_44 ( & V_193 -> V_152 ) ) ;
F_34 ( V_53 -> V_94 != 1 ) ;
V_195 = F_138 ( & V_200 ) ;
F_113 ( V_193 ) ;
F_139 ( V_195 ) ;
F_59 ( & V_116 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_73 -> V_103 ) ;
} else {
F_126 ( V_134 . V_166 ) ;
F_109 ( V_134 . V_59 ) ;
}
F_27 ( V_134 . V_144 ) ;
F_27 ( V_134 . V_98 ) ;
return F_76 ( V_76 -> V_186 ) ;
V_197:
F_59 ( & V_116 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_73 -> V_103 ) ;
V_196:
F_140 ( V_76 ) ;
V_192:
F_109 ( V_134 . V_59 ) ;
V_191:
F_27 ( V_134 . V_144 ) ;
F_27 ( V_134 . V_98 ) ;
return F_125 ( V_90 ) ;
}
static void F_141 ( struct V_75 * V_76 ) {
struct V_55 * V_53 = V_76 -> V_129 ;
struct V_7 * V_8 = & V_53 -> V_72 ;
int V_90 ;
struct V_29 * V_30 ;
struct V_29 * V_31 ;
F_34 ( ! V_53 ) ;
F_34 ( V_53 -> V_94 != 1 ) ;
F_34 ( ! F_44 ( & V_8 -> V_152 ) ) ;
F_34 ( ! F_44 ( & V_8 -> V_122 ) ) ;
F_57 ( & V_1 ) ;
F_57 ( & V_116 ) ;
V_90 = F_97 ( V_53 , 0 ) ;
F_34 ( V_90 ) ;
F_19 ( & V_33 ) ;
F_23 (link, saved_link, &cgrp->css_sets,
cgrp_link_list) {
F_24 ( & V_30 -> V_36 ) ;
F_24 ( & V_30 -> V_37 ) ;
F_27 ( V_30 ) ;
}
F_21 ( & V_33 ) ;
if ( ! F_44 ( & V_53 -> V_157 ) ) {
F_24 ( & V_53 -> V_157 ) ;
V_65 -- ;
}
F_59 ( & V_116 ) ;
F_59 ( & V_1 ) ;
F_142 ( V_76 ) ;
F_126 ( V_53 ) ;
}
int F_143 ( const struct V_7 * V_8 , char * V_201 , int V_202 )
{
char * V_203 ;
struct V_15 * V_15 = F_144 ( V_8 -> V_15 ,
F_1 () ) ;
if ( ! V_15 || V_8 == V_121 ) {
strcpy ( V_201 , L_15 ) ;
return 0 ;
}
V_203 = V_201 + V_202 ;
* -- V_203 = '\0' ;
for (; ; ) {
int V_204 = V_15 -> V_205 . V_204 ;
if ( ( V_203 -= V_204 ) < V_201 )
return - V_206 ;
memcpy ( V_203 , V_15 -> V_205 . V_98 , V_204 ) ;
V_8 = V_8 -> V_100 ;
if ( ! V_8 )
break;
V_15 = F_144 ( V_8 -> V_15 ,
F_1 () ) ;
if ( ! V_8 -> V_100 )
continue;
if ( -- V_203 < V_201 )
return - V_206 ;
* V_203 = '/' ;
}
memmove ( V_201 , V_203 , V_201 + V_202 - V_203 ) ;
return 0 ;
}
struct V_68 * F_145 ( struct V_207 * V_208 )
{
if ( V_208 -> V_209 ) {
V_208 -> V_210 = 0 ;
return F_146 ( V_208 ) ;
} else {
V_208 -> V_211 = V_208 -> V_212 . V_8 ;
return V_208 -> V_212 . V_69 ;
}
}
struct V_68 * F_146 ( struct V_207 * V_208 )
{
struct V_213 * V_214 ;
if ( ! V_208 -> V_209 || V_208 -> V_210 >= V_208 -> V_215 )
return NULL ;
V_214 = F_147 ( V_208 -> V_209 , V_208 -> V_210 ++ ) ;
V_208 -> V_211 = V_214 -> V_8 ;
return V_214 -> V_69 ;
}
struct V_7 * F_148 ( struct V_207 * V_208 )
{
return V_208 -> V_211 ;
}
int F_149 ( struct V_207 * V_208 )
{
return V_208 -> V_209 ? V_208 -> V_215 : 1 ;
}
static void F_150 ( struct V_7 * V_8 , struct V_7 * V_216 ,
struct V_68 * V_217 , struct V_26 * V_218 )
{
struct V_26 * V_54 ;
F_67 ( V_217 -> V_10 & V_219 ) ;
V_54 = V_217 -> V_70 ;
F_151 ( V_217 ) ;
F_152 ( V_217 -> V_70 , V_218 ) ;
F_153 ( V_217 ) ;
F_19 ( & V_33 ) ;
if ( ! F_44 ( & V_217 -> V_220 ) )
F_46 ( & V_217 -> V_220 , & V_218 -> V_66 ) ;
F_21 ( & V_33 ) ;
F_31 ( V_54 ) ;
F_25 ( V_12 , & V_216 -> V_10 ) ;
}
int F_154 ( struct V_7 * V_8 , struct V_68 * V_217 )
{
int V_221 = 0 ;
struct V_88 * V_89 , * V_222 = NULL ;
struct V_7 * V_216 ;
struct V_55 * V_53 = V_8 -> V_53 ;
struct V_207 V_208 = { } ;
struct V_26 * V_218 ;
if ( V_217 -> V_10 & V_219 )
return - V_223 ;
V_216 = F_55 ( V_217 , V_53 ) ;
if ( V_8 == V_216 )
return 0 ;
V_208 . V_212 . V_69 = V_217 ;
V_208 . V_212 . V_8 = V_216 ;
F_66 (root, ss) {
if ( V_89 -> V_224 ) {
V_221 = V_89 -> V_224 ( V_8 , & V_208 ) ;
if ( V_221 ) {
V_222 = V_89 ;
goto V_225;
}
}
}
V_218 = F_48 ( V_217 -> V_70 , V_8 ) ;
if ( ! V_218 ) {
V_221 = - V_61 ;
goto V_225;
}
F_150 ( V_8 , V_216 , V_217 , V_218 ) ;
F_66 (root, ss) {
if ( V_89 -> V_226 )
V_89 -> V_226 ( V_8 , & V_208 ) ;
}
F_70 () ;
F_89 ( V_8 ) ;
V_225:
if ( V_221 ) {
F_66 (root, ss) {
if ( V_89 == V_222 )
break;
if ( V_89 -> V_227 )
V_89 -> V_227 ( V_8 , & V_208 ) ;
}
}
return V_221 ;
}
int F_155 ( struct V_68 * V_228 , struct V_68 * V_217 )
{
struct V_55 * V_53 ;
int V_221 = 0 ;
F_56 () ;
F_137 (root) {
struct V_7 * V_229 = F_55 ( V_228 , V_53 ) ;
V_221 = F_154 ( V_229 , V_217 ) ;
if ( V_221 )
break;
}
F_58 () ;
return V_221 ;
}
static int F_156 ( struct V_7 * V_8 , struct V_68 * V_230 )
{
int V_221 , V_20 , V_231 ;
struct V_88 * V_89 , * V_222 = NULL ;
struct V_55 * V_53 = V_8 -> V_53 ;
struct V_68 * V_217 ;
struct V_213 * V_214 ;
struct V_232 * V_233 ;
struct V_207 V_208 = { } ;
V_231 = F_157 ( V_230 ) ;
V_233 = F_158 ( sizeof( * V_214 ) , V_231 , V_60 ) ;
if ( ! V_233 )
return - V_61 ;
V_221 = F_159 ( V_233 , 0 , V_231 - 1 , V_60 ) ;
if ( V_221 )
goto V_234;
V_217 = V_230 ;
V_20 = 0 ;
F_160 () ;
do {
struct V_213 V_235 ;
if ( V_217 -> V_10 & V_219 )
continue;
F_34 ( V_20 >= V_231 ) ;
V_235 . V_69 = V_217 ;
V_235 . V_8 = F_55 ( V_217 , V_53 ) ;
if ( V_235 . V_8 == V_8 )
continue;
V_221 = F_161 ( V_233 , V_20 , & V_235 , V_236 ) ;
F_34 ( V_221 != 0 ) ;
V_20 ++ ;
} while_each_thread(leader, tsk) ;
int F_162 ( struct V_7 * V_8 , T_2 V_237 , bool V_238 )
{
struct V_68 * V_217 ;
const struct V_195 * V_195 = F_163 () , * V_239 ;
int V_90 ;
if ( ! F_164 ( V_8 ) )
return - V_240 ;
V_241:
F_160 () ;
if ( V_237 ) {
V_217 = F_165 ( V_237 ) ;
if ( ! V_217 ) {
F_166 () ;
V_90 = - V_223 ;
goto V_242;
}
V_239 = F_167 ( V_217 ) ;
if ( ! F_168 ( V_195 -> V_243 , V_244 ) &&
! F_168 ( V_195 -> V_243 , V_239 -> V_245 ) &&
! F_168 ( V_195 -> V_243 , V_239 -> V_246 ) ) {
F_166 () ;
V_90 = - V_247 ;
goto V_242;
}
} else
V_217 = V_150 ;
if ( V_238 )
V_217 = V_217 -> V_248 ;
if ( V_217 == V_249 || ( V_217 -> V_10 & V_250 ) ) {
V_90 = - V_142 ;
F_166 () ;
goto V_242;
}
F_169 ( V_217 ) ;
F_166 () ;
F_170 ( V_217 ) ;
if ( V_238 ) {
if ( ! F_171 ( V_217 ) ) {
F_172 ( V_217 ) ;
F_173 ( V_217 ) ;
goto V_241;
}
V_90 = F_156 ( V_8 , V_217 ) ;
} else
V_90 = F_154 ( V_8 , V_217 ) ;
F_172 ( V_217 ) ;
F_173 ( V_217 ) ;
V_242:
F_58 () ;
return V_90 ;
}
static int F_174 ( struct V_7 * V_8 , struct V_18 * V_102 , T_2 V_237 )
{
return F_162 ( V_8 , V_237 , false ) ;
}
static int F_175 ( struct V_7 * V_8 , struct V_18 * V_102 , T_2 V_251 )
{
return F_162 ( V_8 , V_251 , true ) ;
}
bool F_164 ( struct V_7 * V_8 )
{
F_57 ( & V_1 ) ;
if ( F_7 ( V_8 ) ) {
F_59 ( & V_1 ) ;
return false ;
}
return true ;
}
static int F_176 ( struct V_7 * V_8 , struct V_18 * V_102 ,
const char * V_252 )
{
F_177 ( sizeof( V_8 -> V_53 -> V_131 ) < V_145 ) ;
if ( strlen ( V_252 ) >= V_145 )
return - V_142 ;
if ( ! F_164 ( V_8 ) )
return - V_240 ;
F_57 ( & V_116 ) ;
strcpy ( V_8 -> V_53 -> V_131 , V_252 ) ;
F_59 ( & V_116 ) ;
F_58 () ;
return 0 ;
}
static int F_178 ( struct V_7 * V_8 , struct V_18 * V_102 ,
struct V_126 * V_127 )
{
if ( ! F_164 ( V_8 ) )
return - V_240 ;
F_103 ( V_127 , V_8 -> V_53 -> V_131 ) ;
F_179 ( V_127 , '\n' ) ;
F_58 () ;
return 0 ;
}
static T_3 F_180 ( struct V_7 * V_8 , struct V_18 * V_102 ,
struct V_253 * V_253 ,
const char T_4 * V_254 ,
T_5 V_255 , T_6 * V_256 )
{
char V_252 [ V_257 ] ;
int V_221 = 0 ;
char * V_258 ;
if ( ! V_255 )
return - V_142 ;
if ( V_255 >= sizeof( V_252 ) )
return - V_259 ;
if ( F_181 ( V_252 , V_254 , V_255 ) )
return - V_260 ;
V_252 [ V_255 ] = 0 ;
if ( V_102 -> V_261 ) {
T_2 V_262 = F_182 ( F_183 ( V_252 ) , & V_258 , 0 ) ;
if ( * V_258 )
return - V_142 ;
V_221 = V_102 -> V_261 ( V_8 , V_102 , V_262 ) ;
} else {
T_7 V_262 = F_184 ( F_183 ( V_252 ) , & V_258 , 0 ) ;
if ( * V_258 )
return - V_142 ;
V_221 = V_102 -> V_263 ( V_8 , V_102 , V_262 ) ;
}
if ( ! V_221 )
V_221 = V_255 ;
return V_221 ;
}
static T_3 F_185 ( struct V_7 * V_8 , struct V_18 * V_102 ,
struct V_253 * V_253 ,
const char T_4 * V_254 ,
T_5 V_255 , T_6 * V_256 )
{
char V_264 [ V_257 ] ;
int V_221 = 0 ;
T_5 V_265 = V_102 -> V_266 ;
char * V_252 = V_264 ;
if ( ! V_265 )
V_265 = sizeof( V_264 ) - 1 ;
if ( V_255 >= V_265 )
return - V_259 ;
if ( V_255 >= sizeof( V_264 ) ) {
V_252 = F_41 ( V_255 + 1 , V_60 ) ;
if ( V_252 == NULL )
return - V_61 ;
}
if ( V_255 && F_181 ( V_252 , V_254 , V_255 ) ) {
V_221 = - V_260 ;
goto V_225;
}
V_252 [ V_255 ] = 0 ;
V_221 = V_102 -> V_267 ( V_8 , V_102 , F_183 ( V_252 ) ) ;
if ( ! V_221 )
V_221 = V_255 ;
V_225:
if ( V_252 != V_264 )
F_27 ( V_252 ) ;
return V_221 ;
}
static T_3 F_186 ( struct V_253 * V_253 , const char T_4 * V_201 ,
T_5 V_255 , T_6 * V_268 )
{
struct V_18 * V_102 = F_14 ( V_253 -> V_269 ) ;
struct V_7 * V_8 = F_12 ( V_253 -> V_269 -> V_97 ) ;
if ( F_7 ( V_8 ) )
return - V_240 ;
if ( V_102 -> V_270 )
return V_102 -> V_270 ( V_8 , V_102 , V_253 , V_201 , V_255 , V_268 ) ;
if ( V_102 -> V_261 || V_102 -> V_263 )
return F_180 ( V_8 , V_102 , V_253 , V_201 , V_255 , V_268 ) ;
if ( V_102 -> V_267 )
return F_185 ( V_8 , V_102 , V_253 , V_201 , V_255 , V_268 ) ;
if ( V_102 -> V_271 ) {
int V_90 = V_102 -> V_271 ( V_8 , ( unsigned int ) V_102 -> V_272 ) ;
return V_90 ? V_90 : V_255 ;
}
return - V_142 ;
}
static T_3 F_187 ( struct V_7 * V_8 , struct V_18 * V_102 ,
struct V_253 * V_253 ,
char T_4 * V_201 , T_5 V_255 ,
T_6 * V_268 )
{
char V_22 [ V_257 ] ;
T_2 V_262 = V_102 -> V_273 ( V_8 , V_102 ) ;
int V_204 = sprintf ( V_22 , L_16 , ( unsigned long long ) V_262 ) ;
return F_188 ( V_201 , V_255 , V_268 , V_22 , V_204 ) ;
}
static T_3 F_189 ( struct V_7 * V_8 , struct V_18 * V_102 ,
struct V_253 * V_253 ,
char T_4 * V_201 , T_5 V_255 ,
T_6 * V_268 )
{
char V_22 [ V_257 ] ;
T_7 V_262 = V_102 -> V_274 ( V_8 , V_102 ) ;
int V_204 = sprintf ( V_22 , L_17 , ( long long ) V_262 ) ;
return F_188 ( V_201 , V_255 , V_268 , V_22 , V_204 ) ;
}
static T_3 F_190 ( struct V_253 * V_253 , char T_4 * V_201 ,
T_5 V_255 , T_6 * V_268 )
{
struct V_18 * V_102 = F_14 ( V_253 -> V_269 ) ;
struct V_7 * V_8 = F_12 ( V_253 -> V_269 -> V_97 ) ;
if ( F_7 ( V_8 ) )
return - V_240 ;
if ( V_102 -> V_275 )
return V_102 -> V_275 ( V_8 , V_102 , V_253 , V_201 , V_255 , V_268 ) ;
if ( V_102 -> V_273 )
return F_187 ( V_8 , V_102 , V_253 , V_201 , V_255 , V_268 ) ;
if ( V_102 -> V_274 )
return F_189 ( V_8 , V_102 , V_253 , V_201 , V_255 , V_268 ) ;
return - V_142 ;
}
static int F_191 ( struct V_276 * V_277 , const char * V_278 , T_2 V_279 )
{
struct V_126 * V_280 = V_277 -> V_281 ;
return F_102 ( V_280 , L_18 , V_278 , ( unsigned long long ) V_279 ) ;
}
static int F_192 ( struct V_126 * V_282 , void * V_283 )
{
struct V_284 * V_281 = V_282 -> V_272 ;
struct V_18 * V_102 = V_281 -> V_102 ;
if ( V_102 -> V_285 ) {
struct V_276 V_277 = {
. V_286 = F_191 ,
. V_281 = V_282 ,
} ;
return V_102 -> V_285 ( V_281 -> V_7 , V_102 , & V_277 ) ;
}
return V_102 -> V_287 ( V_281 -> V_7 , V_102 , V_282 ) ;
}
static int F_193 ( struct V_73 * V_73 , struct V_253 * V_253 )
{
struct V_126 * V_127 = V_253 -> V_288 ;
F_27 ( V_127 -> V_272 ) ;
return F_194 ( V_73 , V_253 ) ;
}
static int F_195 ( struct V_73 * V_73 , struct V_253 * V_253 )
{
int V_289 ;
struct V_18 * V_102 ;
V_289 = F_196 ( V_73 , V_253 ) ;
if ( V_289 )
return V_289 ;
V_102 = F_14 ( V_253 -> V_269 ) ;
if ( V_102 -> V_285 || V_102 -> V_287 ) {
struct V_284 * V_281 =
F_124 ( sizeof( * V_281 ) , V_290 ) ;
if ( ! V_281 )
return - V_61 ;
V_281 -> V_102 = V_102 ;
V_281 -> V_7 = F_12 ( V_253 -> V_269 -> V_97 ) ;
V_253 -> V_291 = & V_292 ;
V_289 = F_197 ( V_253 , F_192 , V_281 ) ;
if ( V_289 < 0 )
F_27 ( V_281 ) ;
} else if ( V_102 -> V_293 )
V_289 = V_102 -> V_293 ( V_73 , V_253 ) ;
else
V_289 = 0 ;
return V_289 ;
}
static int F_198 ( struct V_73 * V_73 , struct V_253 * V_253 )
{
struct V_18 * V_102 = F_14 ( V_253 -> V_269 ) ;
if ( V_102 -> V_294 )
return V_102 -> V_294 ( V_73 , V_253 ) ;
return 0 ;
}
static int F_199 ( struct V_73 * V_295 , struct V_15 * V_296 ,
struct V_73 * V_297 , struct V_15 * V_298 )
{
if ( ! F_69 ( V_296 -> V_101 -> V_78 ) )
return - V_299 ;
if ( V_298 -> V_101 )
return - V_300 ;
if ( V_295 != V_297 )
return - V_301 ;
return F_200 ( V_295 , V_296 , V_297 , V_298 ) ;
}
static struct V_15 * F_201 ( struct V_73 * V_105 , struct V_15 * V_15 , unsigned int V_10 )
{
if ( V_15 -> V_205 . V_204 > V_302 )
return F_125 ( - V_206 ) ;
F_202 ( V_15 , NULL ) ;
return NULL ;
}
static inline struct V_18 * F_203 ( struct V_253 * V_253 )
{
if ( V_253 -> V_269 -> V_101 -> V_182 != & V_303 )
return F_125 ( - V_142 ) ;
return F_14 ( V_253 -> V_269 ) ;
}
static int F_204 ( struct V_15 * V_15 , T_1 V_74 ,
struct V_75 * V_76 )
{
struct V_73 * V_73 ;
if ( ! V_15 )
return - V_104 ;
if ( V_15 -> V_101 )
return - V_300 ;
V_73 = F_60 ( V_74 , V_76 ) ;
if ( ! V_73 )
return - V_61 ;
if ( F_69 ( V_74 ) ) {
V_73 -> V_184 = & V_185 ;
V_73 -> V_182 = & V_183 ;
F_131 ( V_73 ) ;
F_205 ( & V_73 -> V_103 , V_304 ) ;
} else if ( F_206 ( V_74 ) ) {
V_73 -> V_305 = 0 ;
V_73 -> V_182 = & V_303 ;
}
F_207 ( V_15 , V_73 ) ;
F_76 ( V_15 ) ;
return 0 ;
}
static int F_208 ( struct V_7 * V_8 , struct V_15 * V_15 ,
T_1 V_74 )
{
struct V_15 * V_100 ;
int error = 0 ;
V_100 = V_8 -> V_100 -> V_15 ;
error = F_204 ( V_15 , V_178 | V_74 , V_8 -> V_53 -> V_76 ) ;
if ( ! error ) {
V_15 -> V_16 = V_8 ;
F_131 ( V_100 -> V_101 ) ;
F_152 ( V_8 -> V_15 , V_15 ) ;
F_76 ( V_15 ) ;
}
F_79 ( V_15 ) ;
return error ;
}
static T_1 F_209 ( const struct V_18 * V_102 )
{
T_1 V_74 = 0 ;
if ( V_102 -> V_74 )
return V_102 -> V_74 ;
if ( V_102 -> V_275 || V_102 -> V_273 || V_102 -> V_274 ||
V_102 -> V_285 || V_102 -> V_287 )
V_74 |= V_179 ;
if ( V_102 -> V_270 || V_102 -> V_261 || V_102 -> V_263 ||
V_102 -> V_267 || V_102 -> V_271 )
V_74 |= V_181 ;
return V_74 ;
}
static int F_210 ( struct V_7 * V_8 , struct V_88 * V_46 ,
const struct V_18 * V_102 )
{
struct V_15 * V_105 = V_8 -> V_15 ;
struct V_7 * V_100 = F_12 ( V_105 ) ;
struct V_15 * V_15 ;
struct V_17 * V_96 ;
int error ;
T_1 V_74 ;
char V_98 [ V_306 + V_307 + 2 ] = { 0 } ;
if ( ( V_102 -> V_10 & V_308 ) && ! V_8 -> V_100 )
return 0 ;
if ( ( V_102 -> V_10 & V_309 ) && V_8 -> V_100 )
return 0 ;
if ( V_46 && ! F_8 ( V_130 , & V_8 -> V_53 -> V_10 ) ) {
strcpy ( V_98 , V_46 -> V_98 ) ;
strcat ( V_98 , L_19 ) ;
}
strcat ( V_98 , V_102 -> V_98 ) ;
F_34 ( ! F_3 ( & V_105 -> V_101 -> V_103 ) ) ;
V_96 = F_124 ( sizeof( * V_96 ) , V_60 ) ;
if ( ! V_96 )
return - V_61 ;
V_15 = F_211 ( V_98 , V_105 , strlen ( V_98 ) ) ;
if ( F_134 ( V_15 ) ) {
error = F_135 ( V_15 ) ;
goto V_225;
}
V_74 = F_209 ( V_102 ) ;
error = F_204 ( V_15 , V_74 | V_310 , V_8 -> V_53 -> V_76 ) ;
if ( ! error ) {
V_96 -> type = ( void * ) V_102 ;
V_96 -> V_15 = V_15 ;
V_15 -> V_16 = V_96 ;
F_47 ( & V_96 -> V_58 , & V_100 -> V_106 ) ;
V_96 = NULL ;
}
F_79 ( V_15 ) ;
V_225:
F_27 ( V_96 ) ;
return error ;
}
static int F_212 ( struct V_7 * V_8 , struct V_88 * V_46 ,
const struct V_18 V_311 [] , bool V_312 )
{
const struct V_18 * V_102 ;
int V_289 , V_90 = 0 ;
for ( V_102 = V_311 ; V_102 -> V_98 [ 0 ] != '\0' ; V_102 ++ ) {
if ( V_312 )
V_289 = F_210 ( V_8 , V_46 , V_102 ) ;
else
V_289 = F_80 ( V_8 , V_102 ) ;
if ( V_289 ) {
F_111 ( L_20 ,
V_312 ? L_21 : L_22 , V_102 -> V_98 , V_289 ) ;
V_90 = V_289 ;
}
}
return V_90 ;
}
static void F_213 ( void )
__acquires( &cgroup_cft_mutex
static void F_214 ( struct V_88 * V_89 ,
const struct V_18 * V_311 , bool V_312 )
__releases( &cgroup_mutex
int F_215 ( struct V_88 * V_89 , const struct V_18 * V_311 )
{
struct V_313 * V_314 ;
V_314 = F_124 ( sizeof( * V_314 ) , V_60 ) ;
if ( ! V_314 )
return - V_61 ;
F_213 () ;
V_314 -> V_311 = V_311 ;
F_47 ( & V_314 -> V_58 , & V_89 -> V_315 ) ;
F_214 ( V_89 , V_311 , true ) ;
return 0 ;
}
int F_216 ( struct V_88 * V_89 , const struct V_18 * V_311 )
{
struct V_313 * V_314 ;
F_213 () ;
F_53 (set, &ss->cftsets, node) {
if ( V_314 -> V_311 == V_311 ) {
F_83 ( & V_314 -> V_58 ) ;
F_214 ( V_89 , V_311 , false ) ;
return 0 ;
}
}
F_214 ( V_89 , NULL , false ) ;
return - V_104 ;
}
int F_217 ( const struct V_7 * V_8 )
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
static void F_218 ( struct V_7 * V_8 ,
struct V_316 * V_317 )
{
struct V_43 * V_318 = V_317 -> V_319 ;
struct V_29 * V_30 ;
struct V_26 * V_27 ;
do {
V_318 = V_318 -> V_52 ;
if ( V_318 == & V_8 -> V_63 ) {
V_317 -> V_319 = NULL ;
return;
}
V_30 = F_35 ( V_318 , struct V_29 , V_37 ) ;
V_27 = V_30 -> V_27 ;
} while ( F_44 ( & V_27 -> V_66 ) );
V_317 -> V_319 = V_318 ;
V_317 -> V_69 = V_27 -> V_66 . V_52 ;
}
static void F_219 ( void )
{
struct V_68 * V_320 , * V_321 ;
F_19 ( & V_33 ) ;
V_322 = 1 ;
F_49 ( & V_323 ) ;
F_220 (g, p) {
F_151 ( V_320 ) ;
if ( ! ( V_320 -> V_10 & V_219 ) && F_44 ( & V_320 -> V_220 ) )
F_42 ( & V_320 -> V_220 , & V_320 -> V_70 -> V_66 ) ;
F_153 ( V_320 ) ;
} F_221 ( V_321 , V_320 ) ;
F_50 ( & V_323 ) ;
F_21 ( & V_33 ) ;
}
void F_222 ( struct V_7 * V_8 , struct V_316 * V_317 )
__acquires( V_33 )
{
if ( ! V_322 )
F_219 () ;
F_49 ( & V_33 ) ;
V_317 -> V_319 = & V_8 -> V_63 ;
F_218 ( V_8 , V_317 ) ;
}
struct V_68 * F_223 ( struct V_7 * V_8 ,
struct V_316 * V_317 )
{
struct V_68 * V_64 ;
struct V_43 * V_318 = V_317 -> V_69 ;
struct V_29 * V_30 ;
if ( ! V_317 -> V_319 )
return NULL ;
V_64 = F_35 ( V_318 , struct V_68 , V_220 ) ;
V_318 = V_318 -> V_52 ;
V_30 = F_35 ( V_317 -> V_319 , struct V_29 , V_37 ) ;
if ( V_318 == & V_30 -> V_27 -> V_66 ) {
F_218 ( V_8 , V_317 ) ;
} else {
V_317 -> V_69 = V_318 ;
}
return V_64 ;
}
void F_224 ( struct V_7 * V_8 , struct V_316 * V_317 )
__releases( V_33 )
{
F_50 ( & V_33 ) ;
}
static inline int F_225 ( struct V_68 * V_324 ,
struct V_325 * time ,
struct V_68 * V_326 )
{
int V_327 = F_226 ( & V_324 -> V_328 , time ) ;
if ( V_327 > 0 ) {
return 1 ;
} else if ( V_327 < 0 ) {
return 0 ;
} else {
return V_324 > V_326 ;
}
}
static inline int F_227 ( void * V_329 , void * V_330 )
{
struct V_68 * V_324 = V_329 ;
struct V_68 * V_326 = V_330 ;
return F_225 ( V_324 , & V_326 -> V_328 , V_326 ) ;
}
int F_228 ( struct V_331 * V_332 )
{
int V_221 , V_20 ;
struct V_316 V_317 ;
struct V_68 * V_320 , * V_333 ;
struct V_68 * V_334 = NULL ;
struct V_335 V_336 ;
struct V_335 * V_337 ;
struct V_325 V_338 = { 0 , 0 } ;
if ( V_332 -> V_337 ) {
V_337 = V_332 -> V_337 ;
V_337 -> V_339 = & F_227 ;
} else {
V_337 = & V_336 ;
V_221 = F_229 ( V_337 , V_340 , V_60 , & F_227 ) ;
if ( V_221 )
return V_221 ;
}
V_341:
V_337 -> V_342 = 0 ;
F_222 ( V_332 -> V_27 , & V_317 ) ;
while ( ( V_320 = F_223 ( V_332 -> V_27 , & V_317 ) ) ) {
if ( V_332 -> V_343 && ! V_332 -> V_343 ( V_320 , V_332 ) )
continue;
if ( ! F_225 ( V_320 , & V_338 , V_334 ) )
continue;
V_333 = F_230 ( V_337 , V_320 ) ;
if ( V_333 == NULL ) {
F_169 ( V_320 ) ;
} else if ( V_333 != V_320 ) {
F_169 ( V_320 ) ;
F_173 ( V_333 ) ;
}
}
F_224 ( V_332 -> V_27 , & V_317 ) ;
if ( V_337 -> V_342 ) {
for ( V_20 = 0 ; V_20 < V_337 -> V_342 ; V_20 ++ ) {
struct V_68 * V_344 = V_337 -> V_345 [ V_20 ] ;
if ( V_20 == 0 ) {
V_338 = V_344 -> V_328 ;
V_334 = V_344 ;
}
V_332 -> V_346 ( V_344 , V_332 ) ;
F_173 ( V_344 ) ;
}
goto V_341;
}
if ( V_337 == & V_336 )
F_231 ( & V_336 ) ;
return 0 ;
}
static void * F_232 ( int V_38 )
{
if ( F_233 ( V_38 ) )
return F_234 ( V_38 * sizeof( V_347 ) ) ;
else
return F_41 ( V_38 * sizeof( V_347 ) , V_60 ) ;
}
static void F_235 ( void * V_320 )
{
if ( F_236 ( V_320 ) )
F_237 ( V_320 ) ;
else
F_27 ( V_320 ) ;
}
static void * F_238 ( void * V_320 , int V_348 )
{
void * V_349 ;
if ( F_236 ( V_320 ) ) {
V_349 = F_234 ( V_348 * sizeof( V_347 ) ) ;
if ( ! V_349 )
return NULL ;
memcpy ( V_349 , V_320 , V_348 * sizeof( V_347 ) ) ;
F_237 ( V_320 ) ;
} else {
V_349 = F_239 ( V_320 , V_348 * sizeof( V_347 ) , V_60 ) ;
}
return V_349 ;
}
static int F_240 ( V_347 * * V_320 , int V_350 )
{
int V_351 , V_352 = 1 ;
V_347 * V_353 = * V_320 ;
V_347 * V_349 ;
if ( V_350 == 0 || V_350 == 1 )
return V_350 ;
for ( V_351 = 1 ; V_351 < V_350 ; V_351 ++ ) {
while ( V_353 [ V_351 ] == V_353 [ V_351 - 1 ] ) {
V_351 ++ ;
if ( V_351 == V_350 )
goto V_354;
}
V_353 [ V_352 ] = V_353 [ V_351 ] ;
V_352 ++ ;
}
V_354:
if ( F_241 ( V_350 , V_352 ) ) {
V_349 = F_238 ( V_353 , V_352 ) ;
if ( V_349 )
* V_320 = V_349 ;
}
return V_352 ;
}
static int F_242 ( const void * V_355 , const void * V_356 )
{
return * ( V_347 * ) V_355 - * ( V_347 * ) V_356 ;
}
static struct V_357 * F_243 ( struct V_7 * V_8 ,
enum V_358 type )
{
struct V_357 * V_318 ;
struct V_359 * V_360 = V_150 -> V_361 -> V_362 ;
F_57 ( & V_8 -> V_154 ) ;
F_53 (l, &cgrp->pidlists, links) {
if ( V_318 -> V_278 . type == type && V_318 -> V_278 . V_360 == V_360 ) {
F_244 ( & V_318 -> V_363 ) ;
F_59 ( & V_8 -> V_154 ) ;
return V_318 ;
}
}
V_318 = F_41 ( sizeof( struct V_357 ) , V_60 ) ;
if ( ! V_318 ) {
F_59 ( & V_8 -> V_154 ) ;
return V_318 ;
}
F_245 ( & V_318 -> V_363 ) ;
F_244 ( & V_318 -> V_363 ) ;
V_318 -> V_278 . type = type ;
V_318 -> V_278 . V_360 = F_246 ( V_360 ) ;
V_318 -> V_364 = 0 ;
V_318 -> V_353 = NULL ;
V_318 -> V_365 = V_8 ;
F_42 ( & V_318 -> V_366 , & V_8 -> V_95 ) ;
F_59 ( & V_8 -> V_154 ) ;
return V_318 ;
}
static int F_247 ( struct V_7 * V_8 , enum V_358 type ,
struct V_357 * * V_367 )
{
V_347 * V_368 ;
int V_350 ;
int V_237 , V_369 = 0 ;
struct V_316 V_317 ;
struct V_68 * V_217 ;
struct V_357 * V_318 ;
V_350 = F_217 ( V_8 ) ;
V_368 = F_232 ( V_350 ) ;
if ( ! V_368 )
return - V_61 ;
F_222 ( V_8 , & V_317 ) ;
while ( ( V_217 = F_223 ( V_8 , & V_317 ) ) ) {
if ( F_90 ( V_369 == V_350 ) )
break;
if ( type == V_370 )
V_237 = F_248 ( V_217 ) ;
else
V_237 = F_249 ( V_217 ) ;
if ( V_237 > 0 )
V_368 [ V_369 ++ ] = V_237 ;
}
F_224 ( V_8 , & V_317 ) ;
V_350 = V_369 ;
F_250 ( V_368 , V_350 , sizeof( V_347 ) , F_242 , NULL ) ;
if ( type == V_370 )
V_350 = F_240 ( & V_368 , V_350 ) ;
V_318 = F_243 ( V_8 , type ) ;
if ( ! V_318 ) {
F_235 ( V_368 ) ;
return - V_61 ;
}
F_235 ( V_318 -> V_353 ) ;
V_318 -> V_353 = V_368 ;
V_318 -> V_350 = V_350 ;
V_318 -> V_364 ++ ;
F_251 ( & V_318 -> V_363 ) ;
* V_367 = V_318 ;
return 0 ;
}
int F_252 ( struct V_371 * V_372 , struct V_15 * V_15 )
{
int V_90 = - V_142 ;
struct V_7 * V_8 ;
struct V_316 V_317 ;
struct V_68 * V_217 ;
if ( V_15 -> V_128 -> V_173 != & V_174 ||
! F_69 ( V_15 -> V_101 -> V_78 ) )
goto V_289;
V_90 = 0 ;
V_8 = V_15 -> V_16 ;
F_222 ( V_8 , & V_317 ) ;
while ( ( V_217 = F_223 ( V_8 , & V_317 ) ) ) {
switch ( V_217 -> V_281 ) {
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
if ( F_253 ( V_217 ) )
V_372 -> V_381 ++ ;
break;
}
}
F_224 ( V_8 , & V_317 ) ;
V_289:
return V_90 ;
}
static void * F_254 ( struct V_126 * V_382 , T_6 * V_383 )
{
struct V_357 * V_318 = V_382 -> V_272 ;
int V_21 = 0 , V_237 = * V_383 ;
int * V_384 ;
F_255 ( & V_318 -> V_363 ) ;
if ( V_237 ) {
int V_258 = V_318 -> V_350 ;
while ( V_21 < V_258 ) {
int V_385 = ( V_21 + V_258 ) / 2 ;
if ( V_318 -> V_353 [ V_385 ] == V_237 ) {
V_21 = V_385 ;
break;
} else if ( V_318 -> V_353 [ V_385 ] <= V_237 )
V_21 = V_385 + 1 ;
else
V_258 = V_385 ;
}
}
if ( V_21 >= V_318 -> V_350 )
return NULL ;
V_384 = V_318 -> V_353 + V_21 ;
* V_383 = * V_384 ;
return V_384 ;
}
static void F_256 ( struct V_126 * V_382 , void * V_6 )
{
struct V_357 * V_318 = V_382 -> V_272 ;
F_257 ( & V_318 -> V_363 ) ;
}
static void * F_258 ( struct V_126 * V_382 , void * V_6 , T_6 * V_383 )
{
struct V_357 * V_318 = V_382 -> V_272 ;
V_347 * V_320 = V_6 ;
V_347 * V_258 = V_318 -> V_353 + V_318 -> V_350 ;
V_320 ++ ;
if ( V_320 >= V_258 ) {
return NULL ;
} else {
* V_383 = * V_320 ;
return V_320 ;
}
}
static int F_259 ( struct V_126 * V_382 , void * V_6 )
{
return F_102 ( V_382 , L_23 , * ( int * ) V_6 ) ;
}
static void F_260 ( struct V_357 * V_318 )
{
F_57 ( & V_318 -> V_365 -> V_154 ) ;
F_244 ( & V_318 -> V_363 ) ;
F_34 ( ! V_318 -> V_364 ) ;
if ( ! -- V_318 -> V_364 ) {
F_24 ( & V_318 -> V_366 ) ;
F_59 ( & V_318 -> V_365 -> V_154 ) ;
F_235 ( V_318 -> V_353 ) ;
F_261 ( V_318 -> V_278 . V_360 ) ;
F_251 ( & V_318 -> V_363 ) ;
F_27 ( V_318 ) ;
return;
}
F_59 ( & V_318 -> V_365 -> V_154 ) ;
F_251 ( & V_318 -> V_363 ) ;
}
static int F_262 ( struct V_73 * V_73 , struct V_253 * V_253 )
{
struct V_357 * V_318 ;
if ( ! ( V_253 -> V_386 & V_387 ) )
return 0 ;
V_318 = ( (struct V_126 * ) V_253 -> V_288 ) -> V_272 ;
F_260 ( V_318 ) ;
return F_263 ( V_73 , V_253 ) ;
}
static int F_264 ( struct V_253 * V_253 , enum V_358 type )
{
struct V_7 * V_8 = F_12 ( V_253 -> V_269 -> V_97 ) ;
struct V_357 * V_318 ;
int V_221 ;
if ( ! ( V_253 -> V_386 & V_387 ) )
return 0 ;
V_221 = F_247 ( V_8 , type , & V_318 ) ;
if ( V_221 )
return V_221 ;
V_253 -> V_291 = & V_388 ;
V_221 = F_265 ( V_253 , & V_389 ) ;
if ( V_221 ) {
F_260 ( V_318 ) ;
return V_221 ;
}
( (struct V_126 * ) V_253 -> V_288 ) -> V_272 = V_318 ;
return 0 ;
}
static int F_266 ( struct V_73 * V_390 , struct V_253 * V_253 )
{
return F_264 ( V_253 , V_391 ) ;
}
static int F_267 ( struct V_73 * V_390 , struct V_253 * V_253 )
{
return F_264 ( V_253 , V_370 ) ;
}
static T_2 F_268 ( struct V_7 * V_8 ,
struct V_18 * V_102 )
{
return F_10 ( V_8 ) ;
}
static int F_269 ( struct V_7 * V_8 ,
struct V_18 * V_102 ,
T_2 V_262 )
{
F_270 ( V_12 , & V_8 -> V_10 ) ;
if ( V_262 )
F_25 ( V_13 , & V_8 -> V_10 ) ;
else
F_270 ( V_13 , & V_8 -> V_10 ) ;
return 0 ;
}
static void F_271 ( struct V_392 * V_393 )
{
struct V_394 * V_395 = F_272 ( V_393 , struct V_394 ,
remove ) ;
struct V_7 * V_8 = V_395 -> V_8 ;
V_395 -> V_102 -> V_396 ( V_8 , V_395 -> V_102 , V_395 -> V_397 ) ;
F_273 ( V_395 -> V_397 ) ;
F_27 ( V_395 ) ;
F_79 ( V_8 -> V_15 ) ;
}
static int F_274 ( T_8 * V_398 , unsigned V_74 ,
int V_399 , void * V_278 )
{
struct V_394 * V_395 = F_272 ( V_398 ,
struct V_394 , V_398 ) ;
struct V_7 * V_8 = V_395 -> V_8 ;
unsigned long V_10 = ( unsigned long ) V_278 ;
if ( V_10 & V_400 ) {
F_275 ( V_395 -> V_401 , & V_395 -> V_398 ) ;
F_86 ( & V_8 -> V_156 ) ;
F_24 ( & V_395 -> V_353 ) ;
F_88 ( & V_8 -> V_156 ) ;
F_276 ( & V_395 -> remove ) ;
}
return 0 ;
}
static void F_277 ( struct V_253 * V_253 ,
T_9 * V_401 , T_10 * V_402 )
{
struct V_394 * V_395 = F_272 ( V_402 ,
struct V_394 , V_402 ) ;
V_395 -> V_401 = V_401 ;
F_278 ( V_401 , & V_395 -> V_398 ) ;
}
static int F_279 ( struct V_7 * V_8 , struct V_18 * V_102 ,
const char * V_252 )
{
struct V_394 * V_395 = NULL ;
unsigned int V_403 , V_404 ;
struct V_253 * V_405 = NULL ;
struct V_253 * V_406 = NULL ;
char * V_407 ;
int V_90 ;
V_403 = F_280 ( V_252 , & V_407 , 10 ) ;
if ( * V_407 != ' ' )
return - V_142 ;
V_252 = V_407 + 1 ;
V_404 = F_280 ( V_252 , & V_407 , 10 ) ;
if ( ( * V_407 != ' ' ) && ( * V_407 != '\0' ) )
return - V_142 ;
V_252 = V_407 + 1 ;
V_395 = F_124 ( sizeof( * V_395 ) , V_60 ) ;
if ( ! V_395 )
return - V_61 ;
V_395 -> V_8 = V_8 ;
F_40 ( & V_395 -> V_353 ) ;
F_281 ( & V_395 -> V_402 , F_277 ) ;
F_282 ( & V_395 -> V_398 , F_274 ) ;
F_283 ( & V_395 -> remove , F_271 ) ;
V_405 = F_284 ( V_403 ) ;
if ( F_134 ( V_405 ) ) {
V_90 = F_135 ( V_405 ) ;
goto V_408;
}
V_395 -> V_397 = F_285 ( V_405 ) ;
if ( F_134 ( V_395 -> V_397 ) ) {
V_90 = F_135 ( V_395 -> V_397 ) ;
goto V_408;
}
V_406 = F_286 ( V_404 ) ;
if ( ! V_406 ) {
V_90 = - V_409 ;
goto V_408;
}
V_90 = F_287 ( V_406 -> V_410 . V_15 -> V_101 , V_411 ) ;
if ( V_90 < 0 )
goto V_408;
V_395 -> V_102 = F_203 ( V_406 ) ;
if ( F_134 ( V_395 -> V_102 ) ) {
V_90 = F_135 ( V_395 -> V_102 ) ;
goto V_408;
}
if ( ! V_395 -> V_102 -> V_412 || ! V_395 -> V_102 -> V_396 ) {
V_90 = - V_142 ;
goto V_408;
}
V_90 = V_395 -> V_102 -> V_412 ( V_8 , V_395 -> V_102 ,
V_395 -> V_397 , V_252 ) ;
if ( V_90 )
goto V_408;
if ( V_405 -> V_291 -> V_413 ( V_405 , & V_395 -> V_402 ) & V_400 ) {
V_395 -> V_102 -> V_396 ( V_8 , V_395 -> V_102 , V_395 -> V_397 ) ;
V_90 = 0 ;
goto V_408;
}
F_76 ( V_8 -> V_15 ) ;
F_86 ( & V_8 -> V_156 ) ;
F_42 ( & V_395 -> V_353 , & V_8 -> V_155 ) ;
F_88 ( & V_8 -> V_156 ) ;
F_288 ( V_406 ) ;
F_288 ( V_405 ) ;
return 0 ;
V_408:
if ( V_406 )
F_288 ( V_406 ) ;
if ( V_395 && V_395 -> V_397 && ! F_134 ( V_395 -> V_397 ) )
F_273 ( V_395 -> V_397 ) ;
if ( ! F_289 ( V_405 ) )
F_288 ( V_405 ) ;
F_27 ( V_395 ) ;
return V_90 ;
}
static T_2 F_290 ( struct V_7 * V_8 ,
struct V_18 * V_102 )
{
return F_11 ( V_8 ) ;
}
static int F_291 ( struct V_7 * V_8 ,
struct V_18 * V_102 ,
T_2 V_262 )
{
if ( V_262 )
F_25 ( V_14 , & V_8 -> V_10 ) ;
else
F_270 ( V_14 , & V_8 -> V_10 ) ;
return 0 ;
}
static int F_113 ( struct V_7 * V_8 )
{
int V_289 ;
struct V_88 * V_89 ;
V_289 = F_212 ( V_8 , NULL , V_106 , true ) ;
if ( V_289 < 0 )
return V_289 ;
F_66 (cgrp->root, ss) {
struct V_313 * V_314 ;
F_53 (set, &ss->cftsets, node)
F_212 ( V_8 , V_89 , V_314 -> V_311 , true ) ;
}
F_66 (cgrp->root, ss) {
struct V_4 * V_5 = V_8 -> V_46 [ V_89 -> V_414 ] ;
if ( V_5 -> V_415 )
F_152 ( V_5 -> V_415 -> V_5 , V_5 ) ;
}
return 0 ;
}
static void F_292 ( struct V_392 * V_393 )
{
struct V_4 * V_5 =
F_272 ( V_393 , struct V_4 , V_416 ) ;
struct V_15 * V_15 = V_5 -> V_7 -> V_15 ;
struct V_75 * V_76 = V_15 -> V_128 ;
F_30 ( & V_76 -> V_417 ) ;
F_79 ( V_15 ) ;
F_71 ( V_76 ) ;
}
static void F_293 ( struct V_4 * V_5 ,
struct V_88 * V_89 ,
struct V_7 * V_8 )
{
V_5 -> V_7 = V_8 ;
F_51 ( & V_5 -> V_2 , 1 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_415 = NULL ;
if ( V_8 == V_121 )
F_25 ( V_418 , & V_5 -> V_10 ) ;
F_34 ( V_8 -> V_46 [ V_89 -> V_414 ] ) ;
V_8 -> V_46 [ V_89 -> V_414 ] = V_5 ;
F_283 ( & V_5 -> V_416 , F_292 ) ;
if ( V_89 -> V_92 )
F_25 ( V_419 , & V_5 -> V_10 ) ;
}
static long F_294 ( struct V_7 * V_100 , struct V_15 * V_15 ,
T_1 V_74 )
{
struct V_7 * V_8 ;
struct V_55 * V_53 = V_100 -> V_53 ;
int V_289 = 0 ;
struct V_88 * V_89 ;
struct V_75 * V_76 = V_53 -> V_76 ;
V_8 = F_124 ( sizeof( * V_8 ) , V_60 ) ;
if ( ! V_8 )
return - V_61 ;
F_30 ( & V_76 -> V_417 ) ;
F_57 ( & V_1 ) ;
F_114 ( V_8 ) ;
V_8 -> V_100 = V_100 ;
V_8 -> V_53 = V_100 -> V_53 ;
V_8 -> V_72 = V_100 -> V_72 ;
if ( F_10 ( V_100 ) )
F_25 ( V_13 , & V_8 -> V_10 ) ;
if ( F_11 ( V_100 ) )
F_25 ( V_14 , & V_8 -> V_10 ) ;
F_66 (root, ss) {
struct V_4 * V_5 = V_89 -> V_420 ( V_8 ) ;
if ( F_134 ( V_5 ) ) {
V_289 = F_135 ( V_5 ) ;
goto V_421;
}
F_293 ( V_5 , V_89 , V_8 ) ;
if ( V_89 -> V_422 ) {
V_289 = F_295 ( V_89 , V_100 , V_8 ) ;
if ( V_289 )
goto V_421;
}
if ( F_11 ( V_100 ) && V_89 -> V_423 )
V_89 -> V_423 ( V_8 ) ;
}
F_42 ( & V_8 -> V_122 , & V_8 -> V_100 -> V_152 ) ;
V_53 -> V_94 ++ ;
V_289 = F_208 ( V_8 , V_15 , V_74 ) ;
if ( V_289 < 0 )
goto V_424;
F_66 (root, ss)
if ( ! V_89 -> V_92 )
F_76 ( V_15 ) ;
F_34 ( ! F_3 ( & V_8 -> V_15 -> V_101 -> V_103 ) ) ;
F_47 ( & V_8 -> V_159 , & V_53 -> V_158 ) ;
V_289 = F_113 ( V_8 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_8 -> V_15 -> V_101 -> V_103 ) ;
return 0 ;
V_424:
F_24 ( & V_8 -> V_122 ) ;
V_53 -> V_94 -- ;
V_421:
F_66 (root, ss) {
if ( V_8 -> V_46 [ V_89 -> V_414 ] )
V_89 -> V_93 ( V_8 ) ;
}
F_59 ( & V_1 ) ;
F_71 ( V_76 ) ;
F_27 ( V_8 ) ;
return V_289 ;
}
static int F_296 ( struct V_73 * V_105 , struct V_15 * V_15 , T_1 V_74 )
{
struct V_7 * V_425 = V_15 -> V_97 -> V_16 ;
return F_294 ( V_425 , V_15 , V_74 | V_178 ) ;
}
static int F_297 ( struct V_7 * V_8 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
struct V_4 * V_5 ;
if ( V_89 == NULL || V_89 -> V_53 != V_8 -> V_53 )
continue;
V_5 = V_8 -> V_46 [ V_89 -> V_414 ] ;
if ( V_5 && F_5 ( V_5 ) > 1 )
return 1 ;
}
return 0 ;
}
static int F_298 ( struct V_7 * V_8 )
{
struct V_88 * V_89 ;
unsigned long V_10 ;
bool V_426 = false ;
F_299 ( V_10 ) ;
F_66 (cgrp->root, ss) {
struct V_4 * V_5 = V_8 -> V_46 [ V_89 -> V_414 ] ;
F_300 ( F_6 ( & V_5 -> V_2 ) < 0 ) ;
F_301 ( V_3 , & V_5 -> V_2 ) ;
if ( V_89 -> V_92 )
V_426 |= F_5 ( V_5 ) != 1 ;
}
F_66 (cgrp->root, ss) {
struct V_4 * V_5 = V_8 -> V_46 [ V_89 -> V_414 ] ;
if ( ! V_426 ) {
F_25 ( V_427 , & V_5 -> V_10 ) ;
F_96 ( V_5 ) ;
} else {
F_302 ( V_3 , & V_5 -> V_2 ) ;
}
}
F_303 ( V_10 ) ;
return ! V_426 ;
}
static int F_304 ( struct V_73 * V_428 , struct V_15 * V_15 )
{
struct V_7 * V_8 = V_15 -> V_16 ;
struct V_15 * V_99 ;
struct V_7 * V_100 ;
F_305 ( V_398 ) ;
struct V_394 * V_395 , * V_22 ;
int V_90 ;
V_341:
F_57 ( & V_1 ) ;
if ( F_6 ( & V_8 -> V_38 ) != 0 ) {
F_59 ( & V_1 ) ;
return - V_120 ;
}
if ( ! F_44 ( & V_8 -> V_152 ) ) {
F_59 ( & V_1 ) ;
return - V_120 ;
}
F_59 ( & V_1 ) ;
F_25 ( V_111 , & V_8 -> V_10 ) ;
V_90 = F_65 ( V_8 ) ;
if ( V_90 ) {
F_270 ( V_111 , & V_8 -> V_10 ) ;
return V_90 ;
}
F_57 ( & V_1 ) ;
V_100 = V_8 -> V_100 ;
if ( F_6 ( & V_8 -> V_38 ) || ! F_44 ( & V_8 -> V_152 ) ) {
F_270 ( V_111 , & V_8 -> V_10 ) ;
F_59 ( & V_1 ) ;
return - V_120 ;
}
F_306 ( & V_112 , & V_398 , V_375 ) ;
if ( ! F_298 ( V_8 ) ) {
F_59 ( & V_1 ) ;
if ( F_8 ( V_111 , & V_8 -> V_10 ) )
F_307 () ;
F_308 ( & V_112 , & V_398 ) ;
F_270 ( V_111 , & V_8 -> V_10 ) ;
if ( F_309 ( V_150 ) )
return - V_429 ;
goto V_341;
}
F_308 ( & V_112 , & V_398 ) ;
F_270 ( V_111 , & V_8 -> V_10 ) ;
F_310 ( & V_430 ) ;
F_25 ( V_9 , & V_8 -> V_10 ) ;
if ( ! F_44 ( & V_8 -> V_153 ) )
F_83 ( & V_8 -> V_153 ) ;
F_311 ( & V_430 ) ;
F_83 ( & V_8 -> V_122 ) ;
F_83 ( & V_8 -> V_159 ) ;
V_99 = F_76 ( V_8 -> V_15 ) ;
F_85 ( V_99 ) ;
F_79 ( V_99 ) ;
F_25 ( V_12 , & V_100 -> V_10 ) ;
F_26 ( V_100 ) ;
F_86 ( & V_8 -> V_156 ) ;
F_23 (event, tmp, &cgrp->event_list, list) {
F_24 ( & V_395 -> V_353 ) ;
F_312 ( V_395 -> V_401 , & V_395 -> V_398 ) ;
F_313 ( V_395 -> V_397 , 1 ) ;
F_276 ( & V_395 -> remove ) ;
}
F_88 ( & V_8 -> V_156 ) ;
F_59 ( & V_1 ) ;
return 0 ;
}
static void T_11 F_314 ( struct V_88 * V_89 )
{
F_40 ( & V_89 -> V_315 ) ;
if ( V_89 -> V_431 ) {
V_89 -> V_432 . V_311 = V_89 -> V_431 ;
F_47 ( & V_89 -> V_432 . V_58 , & V_89 -> V_315 ) ;
}
}
static void T_12 F_315 ( struct V_88 * V_89 )
{
struct V_4 * V_5 ;
F_316 ( V_433 L_24 , V_89 -> V_98 ) ;
F_314 ( V_89 ) ;
F_42 ( & V_89 -> V_122 , & V_119 . V_123 ) ;
V_89 -> V_53 = & V_119 ;
V_5 = V_89 -> V_420 ( V_121 ) ;
F_34 ( F_134 ( V_5 ) ) ;
F_293 ( V_5 , V_89 , V_121 ) ;
V_71 . V_46 [ V_89 -> V_414 ] = V_121 -> V_46 [ V_89 -> V_414 ] ;
V_434 |= V_89 -> V_435 || V_89 -> exit ;
F_34 ( ! F_44 ( & V_436 . V_66 ) ) ;
V_89 -> V_437 = 1 ;
F_34 ( V_89 -> V_125 ) ;
}
int T_11 F_317 ( struct V_88 * V_89 )
{
int V_20 ;
struct V_4 * V_5 ;
if ( V_89 -> V_98 == NULL || strlen ( V_89 -> V_98 ) > V_306 ||
V_89 -> V_420 == NULL || V_89 -> V_93 == NULL )
return - V_142 ;
if ( V_89 -> V_435 || V_89 -> exit )
return - V_142 ;
if ( V_89 -> V_125 == NULL ) {
F_34 ( V_89 -> V_414 >= V_148 ) ;
F_34 ( V_46 [ V_89 -> V_414 ] != V_89 ) ;
return 0 ;
}
F_314 ( V_89 ) ;
F_57 ( & V_1 ) ;
for ( V_20 = V_148 ; V_20 < V_23 ; V_20 ++ ) {
if ( V_46 [ V_20 ] == NULL )
break;
}
if ( V_20 == V_23 ) {
F_59 ( & V_1 ) ;
return - V_120 ;
}
V_89 -> V_414 = V_20 ;
V_46 [ V_20 ] = V_89 ;
V_5 = V_89 -> V_420 ( V_121 ) ;
if ( F_134 ( V_5 ) ) {
V_46 [ V_20 ] = NULL ;
F_59 ( & V_1 ) ;
return F_135 ( V_5 ) ;
}
F_42 ( & V_89 -> V_122 , & V_119 . V_123 ) ;
V_89 -> V_53 = & V_119 ;
F_293 ( V_5 , V_89 , V_121 ) ;
if ( V_89 -> V_422 ) {
int V_90 = F_318 ( V_89 , V_5 ) ;
if ( V_90 ) {
V_121 -> V_46 [ V_89 -> V_414 ] = NULL ;
V_89 -> V_93 ( V_121 ) ;
V_46 [ V_20 ] = NULL ;
F_59 ( & V_1 ) ;
return V_90 ;
}
}
F_19 ( & V_33 ) ;
for ( V_20 = 0 ; V_20 < V_199 ; V_20 ++ ) {
struct V_26 * V_27 ;
struct V_57 * V_58 , * V_22 ;
struct V_19 * V_438 = & V_25 [ V_20 ] , * V_439 ;
F_319 (cg, node, tmp, bucket, hlist) {
if ( V_27 -> V_46 [ V_89 -> V_414 ] )
continue;
F_22 ( & V_27 -> V_34 ) ;
V_27 -> V_46 [ V_89 -> V_414 ] = V_5 ;
V_439 = F_15 ( V_27 -> V_46 ) ;
F_54 ( & V_27 -> V_34 , V_439 ) ;
}
}
F_21 ( & V_33 ) ;
V_89 -> V_437 = 1 ;
F_59 ( & V_1 ) ;
return 0 ;
}
void F_320 ( struct V_88 * V_89 )
{
struct V_29 * V_30 ;
struct V_19 * V_56 ;
F_34 ( V_89 -> V_125 == NULL ) ;
F_34 ( V_89 -> V_53 != & V_119 ) ;
F_57 ( & V_1 ) ;
F_34 ( V_89 -> V_414 < V_148 ) ;
V_46 [ V_89 -> V_414 ] = NULL ;
F_83 ( & V_89 -> V_122 ) ;
F_19 ( & V_33 ) ;
F_53 (link, &dummytop->css_sets, cgrp_link_list) {
struct V_26 * V_27 = V_30 -> V_27 ;
F_22 ( & V_27 -> V_34 ) ;
F_34 ( ! V_27 -> V_46 [ V_89 -> V_414 ] ) ;
V_27 -> V_46 [ V_89 -> V_414 ] = NULL ;
V_56 = F_15 ( V_27 -> V_46 ) ;
F_54 ( & V_27 -> V_34 , V_56 ) ;
}
F_21 ( & V_33 ) ;
V_89 -> V_93 ( V_121 ) ;
V_121 -> V_46 [ V_89 -> V_414 ] = NULL ;
F_59 ( & V_1 ) ;
}
int T_12 F_321 ( void )
{
int V_20 ;
F_51 ( & V_71 . V_32 , 1 ) ;
F_40 ( & V_71 . V_47 ) ;
F_40 ( & V_71 . V_66 ) ;
F_52 ( & V_71 . V_34 ) ;
V_35 = 1 ;
F_117 ( & V_119 ) ;
V_65 = 1 ;
V_436 . V_70 = & V_71 ;
V_440 . V_27 = & V_71 ;
V_440 . V_8 = V_121 ;
F_42 ( & V_440 . V_37 ,
& V_119 . V_72 . V_63 ) ;
F_42 ( & V_440 . V_36 ,
& V_71 . V_47 ) ;
for ( V_20 = 0 ; V_20 < V_199 ; V_20 ++ )
F_322 ( & V_25 [ V_20 ] ) ;
for ( V_20 = 0 ; V_20 < V_148 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
F_34 ( ! V_89 -> V_98 ) ;
F_34 ( strlen ( V_89 -> V_98 ) > V_306 ) ;
F_34 ( ! V_89 -> V_420 ) ;
F_34 ( ! V_89 -> V_93 ) ;
if ( V_89 -> V_414 != V_20 ) {
F_316 ( V_441 L_25 ,
V_89 -> V_98 , V_89 -> V_414 ) ;
F_323 () ;
}
if ( V_89 -> V_442 )
F_315 ( V_89 ) ;
}
return 0 ;
}
int T_12 F_324 ( void )
{
int V_289 ;
int V_20 ;
struct V_19 * V_56 ;
V_289 = F_325 ( & V_87 ) ;
if ( V_289 )
return V_289 ;
for ( V_20 = 0 ; V_20 < V_148 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( ! V_89 -> V_442 )
F_315 ( V_89 ) ;
if ( V_89 -> V_422 )
F_318 ( V_89 , V_71 . V_46 [ V_89 -> V_414 ] ) ;
}
V_56 = F_15 ( V_71 . V_46 ) ;
F_54 ( & V_71 . V_34 , V_56 ) ;
F_34 ( ! F_118 ( & V_119 ) ) ;
V_443 = F_326 ( L_26 , V_444 ) ;
if ( ! V_443 ) {
V_289 = - V_61 ;
goto V_225;
}
V_289 = F_327 ( & V_445 ) ;
if ( V_289 < 0 ) {
F_328 ( V_443 ) ;
goto V_225;
}
F_329 ( L_27 , 0 , NULL , & V_446 ) ;
V_225:
if ( V_289 )
F_330 ( & V_87 ) ;
return V_289 ;
}
static int F_331 ( struct V_126 * V_282 , void * V_6 )
{
struct V_237 * V_237 ;
struct V_68 * V_217 ;
char * V_201 ;
int V_221 ;
struct V_55 * V_53 ;
V_221 = - V_61 ;
V_201 = F_41 ( V_340 , V_60 ) ;
if ( ! V_201 )
goto V_225;
V_221 = - V_223 ;
V_237 = V_282 -> V_272 ;
V_217 = F_332 ( V_237 , V_447 ) ;
if ( ! V_217 )
goto V_448;
V_221 = 0 ;
F_57 ( & V_1 ) ;
F_137 (root) {
struct V_88 * V_89 ;
struct V_7 * V_8 ;
int V_38 = 0 ;
F_102 ( V_282 , L_28 , V_53 -> V_163 ) ;
F_66 (root, ss)
F_102 ( V_282 , L_29 , V_38 ++ ? L_7 : L_30 , V_89 -> V_98 ) ;
if ( strlen ( V_53 -> V_98 ) )
F_102 ( V_282 , L_31 , V_38 ? L_7 : L_30 ,
V_53 -> V_98 ) ;
F_179 ( V_282 , ':' ) ;
V_8 = F_55 ( V_217 , V_53 ) ;
V_221 = F_143 ( V_8 , V_201 , V_340 ) ;
if ( V_221 < 0 )
goto V_149;
F_103 ( V_282 , V_201 ) ;
F_179 ( V_282 , '\n' ) ;
}
V_149:
F_59 ( & V_1 ) ;
F_173 ( V_217 ) ;
V_448:
F_27 ( V_201 ) ;
V_225:
return V_221 ;
}
static int F_333 ( struct V_73 * V_73 , struct V_253 * V_253 )
{
struct V_237 * V_237 = F_334 ( V_73 ) -> V_237 ;
return F_197 ( V_253 , F_331 , V_237 ) ;
}
static int F_335 ( struct V_126 * V_282 , void * V_6 )
{
int V_20 ;
F_103 ( V_282 , L_32 ) ;
F_57 ( & V_1 ) ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 == NULL )
continue;
F_102 ( V_282 , L_33 ,
V_89 -> V_98 , V_89 -> V_53 -> V_163 ,
V_89 -> V_53 -> V_94 , ! V_89 -> V_147 ) ;
}
F_59 ( & V_1 ) ;
return 0 ;
}
static int F_336 ( struct V_73 * V_73 , struct V_253 * V_253 )
{
return F_197 ( V_253 , F_335 , NULL ) ;
}
void F_337 ( struct V_68 * V_449 )
{
V_449 -> V_70 = V_150 -> V_70 ;
F_29 ( V_449 -> V_70 ) ;
F_40 ( & V_449 -> V_220 ) ;
}
void F_338 ( struct V_68 * V_449 )
{
if ( V_434 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_148 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 -> V_435 )
V_89 -> V_435 ( V_449 ) ;
}
}
}
void F_339 ( struct V_68 * V_449 )
{
if ( V_322 ) {
F_19 ( & V_33 ) ;
if ( F_44 ( & V_449 -> V_220 ) ) {
F_42 ( & V_449 -> V_220 , & V_449 -> V_70 -> V_66 ) ;
}
F_21 ( & V_33 ) ;
}
}
void F_340 ( struct V_68 * V_217 , int V_450 )
{
struct V_26 * V_27 ;
int V_20 ;
if ( ! F_44 ( & V_217 -> V_220 ) ) {
F_19 ( & V_33 ) ;
if ( ! F_44 ( & V_217 -> V_220 ) )
F_83 ( & V_217 -> V_220 ) ;
F_21 ( & V_33 ) ;
}
F_151 ( V_217 ) ;
V_27 = V_217 -> V_70 ;
V_217 -> V_70 = & V_71 ;
if ( V_450 && V_434 ) {
for ( V_20 = 0 ; V_20 < V_148 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 -> exit ) {
struct V_7 * V_451 =
F_341 ( V_27 -> V_46 [ V_20 ] ) -> V_7 ;
struct V_7 * V_8 = F_342 ( V_217 , V_20 ) ;
V_89 -> exit ( V_8 , V_451 , V_217 ) ;
}
}
}
F_153 ( V_217 ) ;
if ( V_27 )
F_32 ( V_27 ) ;
}
int F_343 ( const struct V_7 * V_8 , struct V_68 * V_69 )
{
int V_90 ;
struct V_7 * V_452 ;
if ( V_8 == V_121 )
return 1 ;
V_452 = F_55 ( V_69 , V_8 -> V_53 ) ;
while ( V_8 != V_452 && V_8 != V_8 -> V_72 )
V_8 = V_8 -> V_100 ;
V_90 = ( V_8 == V_452 ) ;
return V_90 ;
}
static void F_26 ( struct V_7 * V_8 )
{
if ( F_9 ( V_8 ) && ! F_6 ( & V_8 -> V_38 )
&& F_44 ( & V_8 -> V_152 ) && ! F_297 ( V_8 ) ) {
int V_453 = 0 ;
F_310 ( & V_430 ) ;
if ( ! F_7 ( V_8 ) &&
F_44 ( & V_8 -> V_153 ) ) {
F_42 ( & V_8 -> V_153 , & V_153 ) ;
V_453 = 1 ;
}
F_311 ( & V_430 ) ;
if ( V_453 )
F_276 ( & V_454 ) ;
}
}
bool F_344 ( struct V_4 * V_5 )
{
do {
int V_6 = F_5 ( V_5 ) ;
if ( F_345 ( & V_5 -> V_2 , V_6 , V_6 + 1 ) == V_6 )
return true ;
F_346 () ;
} while ( ! F_8 ( V_427 , & V_5 -> V_10 ) );
return false ;
}
void F_347 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_7 ;
int V_6 ;
F_160 () ;
V_6 = F_4 ( F_348 ( & V_5 -> V_2 ) ) ;
switch ( V_6 ) {
case 1 :
if ( F_10 ( V_8 ) ) {
F_25 ( V_12 , & V_8 -> V_10 ) ;
F_26 ( V_8 ) ;
}
F_89 ( V_8 ) ;
break;
case 0 :
if ( ! F_8 ( V_419 , & V_5 -> V_10 ) )
F_276 ( & V_5 -> V_416 ) ;
break;
}
F_166 () ;
}
static void F_349 ( struct V_392 * V_393 )
{
F_34 ( V_393 != & V_454 ) ;
F_57 ( & V_1 ) ;
F_310 ( & V_430 ) ;
while ( ! F_44 ( & V_153 ) ) {
char * V_455 [ 3 ] , * V_456 [ 3 ] ;
int V_20 ;
char * V_457 = NULL , * V_458 = NULL ;
struct V_7 * V_8 = F_35 ( V_153 . V_52 ,
struct V_7 ,
V_153 ) ;
F_83 ( & V_8 -> V_153 ) ;
F_311 ( & V_430 ) ;
V_457 = F_41 ( V_340 , V_60 ) ;
if ( ! V_457 )
goto V_459;
if ( F_143 ( V_8 , V_457 , V_340 ) < 0 )
goto V_459;
V_458 = F_350 ( V_8 -> V_53 -> V_131 , V_60 ) ;
if ( ! V_458 )
goto V_459;
V_20 = 0 ;
V_455 [ V_20 ++ ] = V_458 ;
V_455 [ V_20 ++ ] = V_457 ;
V_455 [ V_20 ] = NULL ;
V_20 = 0 ;
V_456 [ V_20 ++ ] = L_34 ;
V_456 [ V_20 ++ ] = L_35 ;
V_456 [ V_20 ] = NULL ;
F_59 ( & V_1 ) ;
F_351 ( V_455 [ 0 ] , V_455 , V_456 , V_460 ) ;
F_57 ( & V_1 ) ;
V_459:
F_27 ( V_457 ) ;
F_27 ( V_458 ) ;
F_310 ( & V_430 ) ;
}
F_311 ( & V_430 ) ;
F_59 ( & V_1 ) ;
}
static int T_12 F_352 ( char * V_461 )
{
int V_20 ;
char * V_135 ;
while ( ( V_135 = F_106 ( & V_461 , L_7 ) ) != NULL ) {
if ( ! * V_135 )
continue;
for ( V_20 = 0 ; V_20 < V_148 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( ! strcmp ( V_135 , V_89 -> V_98 ) ) {
V_89 -> V_147 = 1 ;
F_316 ( V_433 L_36
L_37 , V_89 -> V_98 ) ;
break;
}
}
}
return 1 ;
}
unsigned short F_353 ( struct V_4 * V_5 )
{
struct F_353 * V_462 ;
V_462 = F_144 ( V_5 -> V_415 , F_5 ( V_5 ) ) ;
if ( V_462 )
return V_462 -> V_415 ;
return 0 ;
}
unsigned short F_354 ( struct V_4 * V_5 )
{
struct F_353 * V_462 ;
V_462 = F_144 ( V_5 -> V_415 , F_5 ( V_5 ) ) ;
if ( V_462 )
return V_462 -> V_463 ;
return 0 ;
}
bool F_355 ( struct V_4 * V_449 ,
const struct V_4 * V_53 )
{
struct F_353 * V_464 ;
struct F_353 * V_465 ;
V_464 = F_356 ( V_449 -> V_415 ) ;
if ( ! V_464 )
return false ;
V_465 = F_356 ( V_53 -> V_415 ) ;
if ( ! V_465 )
return false ;
if ( V_464 -> V_463 < V_465 -> V_463 )
return false ;
if ( V_464 -> V_466 [ V_465 -> V_463 ] != V_465 -> V_415 )
return false ;
return true ;
}
void F_357 ( struct V_88 * V_89 , struct V_4 * V_5 )
{
struct F_353 * V_415 = V_5 -> V_415 ;
if ( ! V_415 )
return;
F_34 ( ! V_89 -> V_422 ) ;
F_152 ( V_415 -> V_5 , NULL ) ;
F_152 ( V_5 -> V_415 , NULL ) ;
F_86 ( & V_89 -> V_467 ) ;
F_358 ( & V_89 -> V_468 , V_415 -> V_415 ) ;
F_88 ( & V_89 -> V_467 ) ;
F_28 ( V_415 , V_39 ) ;
}
static struct F_353 * F_359 ( struct V_88 * V_89 , int V_463 )
{
struct F_353 * V_469 ;
int V_470 , error , V_342 ;
F_34 ( ! V_89 -> V_422 ) ;
V_342 = sizeof( * V_469 ) + sizeof( unsigned short ) * ( V_463 + 1 ) ;
V_469 = F_124 ( V_342 , V_60 ) ;
if ( ! V_469 )
return F_125 ( - V_61 ) ;
if ( F_90 ( ! F_360 ( & V_89 -> V_468 , V_60 ) ) ) {
error = - V_61 ;
goto V_471;
}
F_86 ( & V_89 -> V_467 ) ;
error = F_361 ( & V_89 -> V_468 , V_469 , 1 , & V_470 ) ;
F_88 ( & V_89 -> V_467 ) ;
if ( error ) {
error = - V_164 ;
goto V_471;
}
if ( V_470 > V_472 )
goto V_473;
V_469 -> V_415 = V_470 ;
V_469 -> V_463 = V_463 ;
return V_469 ;
V_473:
error = - V_164 ;
F_86 ( & V_89 -> V_467 ) ;
F_358 ( & V_89 -> V_468 , V_470 ) ;
F_88 ( & V_89 -> V_467 ) ;
V_471:
F_27 ( V_469 ) ;
return F_125 ( error ) ;
}
static int T_11 F_318 ( struct V_88 * V_89 ,
struct V_4 * V_474 )
{
struct F_353 * V_469 ;
F_116 ( & V_89 -> V_467 ) ;
F_362 ( & V_89 -> V_468 ) ;
V_469 = F_359 ( V_89 , 0 ) ;
if ( F_134 ( V_469 ) )
return F_135 ( V_469 ) ;
V_469 -> V_466 [ 0 ] = V_469 -> V_415 ;
V_469 -> V_5 = V_474 ;
V_474 -> V_415 = V_469 ;
return 0 ;
}
static int F_295 ( struct V_88 * V_89 , struct V_7 * V_100 ,
struct V_7 * V_449 )
{
int V_414 , V_20 , V_463 = 0 ;
struct V_4 * V_475 , * V_476 ;
struct F_353 * V_464 , * V_477 ;
V_414 = V_89 -> V_414 ;
V_475 = V_100 -> V_46 [ V_414 ] ;
V_476 = V_449 -> V_46 [ V_414 ] ;
V_477 = V_475 -> V_415 ;
V_463 = V_477 -> V_463 + 1 ;
V_464 = F_359 ( V_89 , V_463 ) ;
if ( F_134 ( V_464 ) )
return F_135 ( V_464 ) ;
for ( V_20 = 0 ; V_20 < V_463 ; V_20 ++ )
V_464 -> V_466 [ V_20 ] = V_477 -> V_466 [ V_20 ] ;
V_464 -> V_466 [ V_463 ] = V_464 -> V_415 ;
F_152 ( V_476 -> V_415 , V_464 ) ;
return 0 ;
}
struct V_4 * F_363 ( struct V_88 * V_89 , int V_415 )
{
struct F_353 * V_462 = NULL ;
F_34 ( ! V_89 -> V_422 ) ;
V_462 = F_364 ( & V_89 -> V_468 , V_415 ) ;
if ( F_90 ( ! V_462 ) )
return NULL ;
return F_356 ( V_462 -> V_5 ) ;
}
struct V_4 *
F_365 ( struct V_88 * V_89 , int V_415 ,
struct V_4 * V_53 , int * V_478 )
{
struct V_4 * V_90 = NULL ;
struct F_353 * V_22 ;
int V_479 ;
int V_480 = F_353 ( V_53 ) ;
int V_463 = F_354 ( V_53 ) ;
if ( ! V_480 )
return NULL ;
F_34 ( ! V_89 -> V_422 ) ;
F_67 ( ! F_366 () ) ;
V_479 = V_415 ;
while ( 1 ) {
V_22 = F_367 ( & V_89 -> V_468 , & V_479 ) ;
if ( ! V_22 )
break;
if ( V_22 -> V_463 >= V_463 && V_22 -> V_466 [ V_463 ] == V_480 ) {
V_90 = F_356 ( V_22 -> V_5 ) ;
if ( V_90 ) {
* V_478 = V_479 ;
break;
}
}
V_479 = V_479 + 1 ;
}
return V_90 ;
}
struct V_4 * F_368 ( struct V_253 * V_481 , int V_415 )
{
struct V_7 * V_8 ;
struct V_73 * V_73 ;
struct V_4 * V_5 ;
V_73 = V_481 -> V_269 -> V_101 ;
if ( V_73 -> V_184 != & V_185 )
return F_125 ( - V_409 ) ;
if ( V_415 < 0 || V_415 >= V_23 )
return F_125 ( - V_142 ) ;
V_8 = F_12 ( V_481 -> V_269 ) ;
V_5 = V_8 -> V_46 [ V_415 ] ;
return V_5 ? V_5 : F_125 ( - V_104 ) ;
}
static struct V_4 * F_369 ( struct V_7 * V_482 )
{
struct V_4 * V_5 = F_124 ( sizeof( * V_5 ) , V_60 ) ;
if ( ! V_5 )
return F_125 ( - V_61 ) ;
return V_5 ;
}
static void F_370 ( struct V_7 * V_482 )
{
F_27 ( V_482 -> V_46 [ V_483 ] ) ;
}
static T_2 F_371 ( struct V_7 * V_482 , struct V_18 * V_102 )
{
return F_6 ( & V_482 -> V_38 ) ;
}
static T_2 F_372 ( struct V_7 * V_482 , struct V_18 * V_102 )
{
return F_217 ( V_482 ) ;
}
static T_2 F_373 ( struct V_7 * V_482 , struct V_18 * V_102 )
{
return ( T_2 ) ( unsigned long ) V_150 -> V_70 ;
}
static T_2 F_374 ( struct V_7 * V_482 ,
struct V_18 * V_102 )
{
T_2 V_38 ;
F_160 () ;
V_38 = F_6 ( & V_150 -> V_70 -> V_32 ) ;
F_166 () ;
return V_38 ;
}
static int F_375 ( struct V_7 * V_482 ,
struct V_18 * V_102 ,
struct V_126 * V_127 )
{
struct V_29 * V_30 ;
struct V_26 * V_27 ;
F_49 ( & V_33 ) ;
F_160 () ;
V_27 = F_356 ( V_150 -> V_70 ) ;
F_53 (link, &cg->cg_links, cg_link_list) {
struct V_7 * V_67 = V_30 -> V_8 ;
const char * V_98 ;
if ( V_67 -> V_15 )
V_98 = V_67 -> V_15 -> V_205 . V_98 ;
else
V_98 = L_38 ;
F_102 ( V_127 , L_39 ,
V_67 -> V_53 -> V_163 , V_98 ) ;
}
F_166 () ;
F_50 ( & V_33 ) ;
return 0 ;
}
static int F_376 ( struct V_7 * V_482 ,
struct V_18 * V_102 ,
struct V_126 * V_127 )
{
struct V_29 * V_30 ;
F_49 ( & V_33 ) ;
F_53 (link, &cont->css_sets, cgrp_link_list) {
struct V_26 * V_27 = V_30 -> V_27 ;
struct V_68 * V_69 ;
int V_38 = 0 ;
F_102 ( V_127 , L_40 , V_27 ) ;
F_53 (task, &cg->tasks, cg_list) {
if ( V_38 ++ > V_484 ) {
F_103 ( V_127 , L_41 ) ;
break;
} else {
F_102 ( V_127 , L_42 ,
F_249 ( V_69 ) ) ;
}
}
}
F_50 ( & V_33 ) ;
return 0 ;
}
static T_2 F_377 ( struct V_7 * V_8 , struct V_18 * V_102 )
{
return F_8 ( V_12 , & V_8 -> V_10 ) ;
}
