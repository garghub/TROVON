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
F_82 ( V_99 -> V_101 , V_99 ) ;
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
F_57 ( & V_89 -> V_122 ) ;
V_8 -> V_46 [ V_20 ] = V_121 -> V_46 [ V_20 ] ;
V_8 -> V_46 [ V_20 ] -> V_7 = V_8 ;
F_46 ( & V_89 -> V_123 , & V_53 -> V_124 ) ;
V_89 -> V_53 = V_53 ;
if ( V_89 -> V_125 )
V_89 -> V_125 ( V_8 ) ;
F_59 ( & V_89 -> V_122 ) ;
} else if ( V_118 & V_115 ) {
F_34 ( V_89 == NULL ) ;
F_34 ( V_8 -> V_46 [ V_20 ] != V_121 -> V_46 [ V_20 ] ) ;
F_34 ( V_8 -> V_46 [ V_20 ] -> V_7 != V_8 ) ;
F_57 ( & V_89 -> V_122 ) ;
if ( V_89 -> V_125 )
V_89 -> V_125 ( V_121 ) ;
V_121 -> V_46 [ V_20 ] -> V_7 = V_121 ;
V_8 -> V_46 [ V_20 ] = NULL ;
V_46 [ V_20 ] -> V_53 = & V_119 ;
F_46 ( & V_89 -> V_123 , & V_119 . V_124 ) ;
F_59 ( & V_89 -> V_122 ) ;
F_98 ( V_89 -> V_126 ) ;
} else if ( V_118 & V_113 ) {
F_34 ( V_89 == NULL ) ;
F_34 ( ! V_8 -> V_46 [ V_20 ] ) ;
F_98 ( V_89 -> V_126 ) ;
#ifdef F_99
F_34 ( V_89 -> V_126 && ! F_100 ( V_89 -> V_126 ) ) ;
#endif
} else {
F_34 ( V_8 -> V_46 [ V_20 ] ) ;
}
}
V_53 -> V_59 = V_53 -> V_117 = V_113 ;
F_70 () ;
return 0 ;
}
static int F_101 ( struct V_127 * V_128 , struct V_15 * V_15 )
{
struct V_55 * V_53 = V_15 -> V_129 -> V_130 ;
struct V_88 * V_89 ;
F_57 ( & V_116 ) ;
F_66 (root, ss)
F_102 ( V_128 , L_2 , V_89 -> V_98 ) ;
if ( F_8 ( V_131 , & V_53 -> V_10 ) )
F_103 ( V_128 , L_3 ) ;
if ( strlen ( V_53 -> V_132 ) )
F_102 ( V_128 , L_4 , V_53 -> V_132 ) ;
if ( F_11 ( & V_53 -> V_72 ) )
F_103 ( V_128 , L_5 ) ;
if ( strlen ( V_53 -> V_98 ) )
F_102 ( V_128 , L_6 , V_53 -> V_98 ) ;
F_59 ( & V_116 ) ;
return 0 ;
}
static int F_104 ( char * V_133 , struct V_134 * V_135 )
{
char * V_136 , * V_137 = V_133 ;
bool V_138 = false , V_139 = false ;
unsigned long V_140 = ( unsigned long ) - 1 ;
int V_20 ;
bool V_141 = false ;
F_34 ( ! F_3 ( & V_1 ) ) ;
#ifdef F_105
V_140 = ~ ( 1UL << V_142 ) ;
#endif
memset ( V_135 , 0 , sizeof( * V_135 ) ) ;
while ( ( V_136 = F_106 ( & V_137 , L_7 ) ) != NULL ) {
if ( ! * V_136 )
return - V_143 ;
if ( ! strcmp ( V_136 , L_8 ) ) {
V_135 -> V_144 = true ;
continue;
}
if ( ! strcmp ( V_136 , L_9 ) ) {
if ( V_139 )
return - V_143 ;
V_138 = true ;
continue;
}
if ( ! strcmp ( V_136 , L_10 ) ) {
F_25 ( V_131 , & V_135 -> V_10 ) ;
continue;
}
if ( ! strcmp ( V_136 , L_11 ) ) {
V_135 -> F_11 = true ;
continue;
}
if ( ! strncmp ( V_136 , L_12 , 14 ) ) {
if ( V_135 -> V_145 )
return - V_143 ;
V_135 -> V_145 =
F_107 ( V_136 + 14 , V_146 - 1 , V_60 ) ;
if ( ! V_135 -> V_145 )
return - V_61 ;
continue;
}
if ( ! strncmp ( V_136 , L_13 , 5 ) ) {
const char * V_98 = V_136 + 5 ;
if ( ! strlen ( V_98 ) )
return - V_143 ;
for ( V_20 = 0 ; V_20 < strlen ( V_98 ) ; V_20 ++ ) {
char V_67 = V_98 [ V_20 ] ;
if ( isalnum ( V_67 ) )
continue;
if ( ( V_67 == '.' ) || ( V_67 == '-' ) || ( V_67 == '_' ) )
continue;
return - V_143 ;
}
if ( V_135 -> V_98 )
return - V_143 ;
V_135 -> V_98 = F_107 ( V_98 ,
V_147 - 1 ,
V_60 ) ;
if ( ! V_135 -> V_98 )
return - V_61 ;
continue;
}
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 == NULL )
continue;
if ( strcmp ( V_136 , V_89 -> V_98 ) )
continue;
if ( V_89 -> V_148 )
continue;
if ( V_138 )
return - V_143 ;
F_25 ( V_20 , & V_135 -> V_59 ) ;
V_139 = true ;
break;
}
if ( V_20 == V_23 )
return - V_104 ;
}
if ( V_138 || ( ! V_139 && ! V_135 -> V_144 && ! V_135 -> V_98 ) ) {
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 == NULL )
continue;
if ( V_89 -> V_148 )
continue;
F_25 ( V_20 , & V_135 -> V_59 ) ;
}
}
if ( F_8 ( V_131 , & V_135 -> V_10 ) &&
( V_135 -> V_59 & V_140 ) )
return - V_143 ;
if ( V_135 -> V_59 && V_135 -> V_144 )
return - V_143 ;
if ( ! V_135 -> V_59 && ! V_135 -> V_98 )
return - V_143 ;
for ( V_20 = V_149 ; V_20 < V_23 ; V_20 ++ ) {
unsigned long V_118 = 1UL << V_20 ;
if ( ! ( V_118 & V_135 -> V_59 ) )
continue;
if ( ! F_108 ( V_46 [ V_20 ] -> V_126 ) ) {
V_141 = true ;
break;
}
}
if ( V_141 ) {
for ( V_20 -- ; V_20 >= V_149 ; V_20 -- ) {
unsigned long V_118 = 1UL << V_20 ;
if ( ! ( V_118 & V_135 -> V_59 ) )
continue;
F_98 ( V_46 [ V_20 ] -> V_126 ) ;
}
return - V_104 ;
}
return 0 ;
}
static void F_109 ( unsigned long V_59 )
{
int V_20 ;
for ( V_20 = V_149 ; V_20 < V_23 ; V_20 ++ ) {
unsigned long V_118 = 1UL << V_20 ;
if ( ! ( V_118 & V_59 ) )
continue;
F_98 ( V_46 [ V_20 ] -> V_126 ) ;
}
}
static int F_110 ( struct V_75 * V_76 , int * V_10 , char * V_133 )
{
int V_90 = 0 ;
struct V_55 * V_53 = V_76 -> V_130 ;
struct V_7 * V_8 = & V_53 -> V_72 ;
struct V_134 V_135 ;
F_57 ( & V_8 -> V_15 -> V_101 -> V_103 ) ;
F_57 ( & V_1 ) ;
F_57 ( & V_116 ) ;
V_90 = F_104 ( V_133 , & V_135 ) ;
if ( V_90 )
goto V_150;
if ( V_135 . V_59 != V_53 -> V_117 || V_135 . V_145 )
F_111 ( L_14 ,
F_112 ( V_151 ) , V_151 -> V_152 ) ;
if ( V_135 . V_10 != V_53 -> V_10 ||
( V_135 . V_98 && strcmp ( V_135 . V_98 , V_53 -> V_98 ) ) ) {
V_90 = - V_143 ;
F_109 ( V_135 . V_59 ) ;
goto V_150;
}
V_90 = F_97 ( V_53 , V_135 . V_59 ) ;
if ( V_90 ) {
F_109 ( V_135 . V_59 ) ;
goto V_150;
}
F_84 ( V_8 -> V_15 ) ;
F_113 ( V_8 ) ;
if ( V_135 . V_145 )
strcpy ( V_53 -> V_132 , V_135 . V_145 ) ;
V_150:
F_27 ( V_135 . V_145 ) ;
F_27 ( V_135 . V_98 ) ;
F_59 ( & V_116 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_8 -> V_15 -> V_101 -> V_103 ) ;
return V_90 ;
}
static void F_114 ( struct V_7 * V_8 )
{
F_40 ( & V_8 -> V_123 ) ;
F_40 ( & V_8 -> V_153 ) ;
F_40 ( & V_8 -> V_106 ) ;
F_40 ( & V_8 -> V_63 ) ;
F_40 ( & V_8 -> V_154 ) ;
F_40 ( & V_8 -> V_95 ) ;
F_115 ( & V_8 -> V_155 ) ;
F_40 ( & V_8 -> V_156 ) ;
F_116 ( & V_8 -> V_157 ) ;
}
static void F_117 ( struct V_55 * V_53 )
{
struct V_7 * V_8 = & V_53 -> V_72 ;
F_40 ( & V_53 -> V_124 ) ;
F_40 ( & V_53 -> V_158 ) ;
F_40 ( & V_53 -> V_159 ) ;
V_53 -> V_94 = 1 ;
V_8 -> V_53 = V_53 ;
V_8 -> V_72 = V_8 ;
F_47 ( & V_8 -> V_160 , & V_53 -> V_159 ) ;
F_114 ( V_8 ) ;
}
static bool F_118 ( struct V_55 * V_53 )
{
int V_90 = 0 ;
do {
if ( ! F_119 ( & V_161 , V_60 ) )
return false ;
F_86 ( & V_162 ) ;
V_90 = F_120 ( & V_161 , V_163 ,
& V_53 -> V_164 ) ;
if ( V_90 == - V_165 )
V_90 = F_121 ( & V_161 , & V_53 -> V_164 ) ;
if ( ! V_90 ) {
V_163 = V_53 -> V_164 + 1 ;
} else if ( V_90 != - V_166 ) {
F_34 ( V_90 ) ;
}
F_88 ( & V_162 ) ;
} while ( V_90 );
return true ;
}
static int F_122 ( struct V_75 * V_76 , void * V_133 )
{
struct V_134 * V_135 = V_133 ;
struct V_55 * V_53 = V_76 -> V_130 ;
if ( V_135 -> V_98 && strcmp ( V_135 -> V_98 , V_53 -> V_98 ) )
return 0 ;
if ( ( V_135 -> V_59 || V_135 -> V_144 )
&& ( V_135 -> V_59 != V_53 -> V_59 ) )
return 0 ;
return 1 ;
}
static struct V_55 * F_123 ( struct V_134 * V_135 )
{
struct V_55 * V_53 ;
if ( ! V_135 -> V_59 && ! V_135 -> V_144 )
return NULL ;
V_53 = F_124 ( sizeof( * V_53 ) , V_60 ) ;
if ( ! V_53 )
return F_125 ( - V_61 ) ;
if ( ! F_118 ( V_53 ) ) {
F_27 ( V_53 ) ;
return F_125 ( - V_61 ) ;
}
F_117 ( V_53 ) ;
V_53 -> V_59 = V_135 -> V_59 ;
V_53 -> V_10 = V_135 -> V_10 ;
if ( V_135 -> V_145 )
strcpy ( V_53 -> V_132 , V_135 -> V_145 ) ;
if ( V_135 -> V_98 )
strcpy ( V_53 -> V_98 , V_135 -> V_98 ) ;
if ( V_135 -> F_11 )
F_25 ( V_14 , & V_53 -> V_72 . V_10 ) ;
return V_53 ;
}
static void F_126 ( struct V_55 * V_53 )
{
if ( ! V_53 )
return;
F_34 ( ! V_53 -> V_164 ) ;
F_86 ( & V_162 ) ;
F_127 ( & V_161 , V_53 -> V_164 ) ;
F_88 ( & V_162 ) ;
F_27 ( V_53 ) ;
}
static int F_128 ( struct V_75 * V_76 , void * V_133 )
{
int V_90 ;
struct V_134 * V_135 = V_133 ;
if ( ! V_135 -> V_167 )
return - V_143 ;
F_34 ( ! V_135 -> V_59 && ! V_135 -> V_144 ) ;
V_90 = F_129 ( V_76 , NULL ) ;
if ( V_90 )
return V_90 ;
V_76 -> V_130 = V_135 -> V_167 ;
V_135 -> V_167 -> V_76 = V_76 ;
V_76 -> V_168 = V_169 ;
V_76 -> V_170 = V_171 ;
V_76 -> V_172 = V_173 ;
V_76 -> V_174 = & V_175 ;
return 0 ;
}
static int F_130 ( struct V_75 * V_76 )
{
static const struct V_176 V_177 = {
. V_178 = F_68 ,
. F_77 = F_74 ,
} ;
struct V_73 * V_73 =
F_60 ( V_179 | V_180 | V_181 | V_182 , V_76 ) ;
if ( ! V_73 )
return - V_61 ;
V_73 -> V_183 = & V_184 ;
V_73 -> V_185 = & V_186 ;
F_131 ( V_73 ) ;
V_76 -> V_187 = F_132 ( V_73 ) ;
if ( ! V_76 -> V_187 )
return - V_61 ;
V_76 -> V_188 = & V_177 ;
return 0 ;
}
static struct V_15 * F_133 ( struct V_189 * V_190 ,
int V_10 , const char * V_191 ,
void * V_133 )
{
struct V_134 V_135 ;
struct V_55 * V_53 ;
int V_90 = 0 ;
struct V_75 * V_76 ;
struct V_55 * V_167 ;
struct V_73 * V_73 ;
F_57 ( & V_1 ) ;
V_90 = F_104 ( V_133 , & V_135 ) ;
F_59 ( & V_1 ) ;
if ( V_90 )
goto V_192;
V_167 = F_123 ( & V_135 ) ;
if ( F_134 ( V_167 ) ) {
V_90 = F_135 ( V_167 ) ;
goto V_193;
}
V_135 . V_167 = V_167 ;
V_76 = F_136 ( V_190 , F_122 , F_128 , & V_135 ) ;
if ( F_134 ( V_76 ) ) {
V_90 = F_135 ( V_76 ) ;
F_126 ( V_135 . V_167 ) ;
goto V_193;
}
V_53 = V_76 -> V_130 ;
F_34 ( ! V_53 ) ;
if ( V_53 == V_135 . V_167 ) {
struct V_43 V_62 ;
struct V_7 * V_194 = & V_53 -> V_72 ;
struct V_55 * V_195 ;
const struct V_196 * V_196 ;
int V_20 ;
F_34 ( V_76 -> V_187 != NULL ) ;
V_90 = F_130 ( V_76 ) ;
if ( V_90 )
goto V_197;
V_73 = V_76 -> V_187 -> V_101 ;
F_57 ( & V_73 -> V_103 ) ;
F_57 ( & V_1 ) ;
F_57 ( & V_116 ) ;
V_90 = - V_120 ;
if ( strlen ( V_53 -> V_98 ) )
F_137 (existing_root)
if ( ! strcmp ( V_195 -> V_98 , V_53 -> V_98 ) )
goto V_198;
V_90 = F_39 ( V_35 , & V_62 ) ;
if ( V_90 )
goto V_198;
V_90 = F_97 ( V_53 , V_53 -> V_59 ) ;
if ( V_90 == - V_120 ) {
F_38 ( & V_62 ) ;
goto V_198;
}
F_34 ( V_90 ) ;
F_42 ( & V_53 -> V_158 , & V_199 ) ;
V_65 ++ ;
V_76 -> V_187 -> V_16 = V_194 ;
V_53 -> V_72 . V_15 = V_76 -> V_187 ;
F_19 ( & V_33 ) ;
for ( V_20 = 0 ; V_20 < V_200 ; V_20 ++ ) {
struct V_19 * V_56 = & V_25 [ V_20 ] ;
struct V_57 * V_58 ;
struct V_26 * V_27 ;
F_37 (cg, node, hhead, hlist)
F_43 ( & V_62 , V_27 , V_194 ) ;
}
F_21 ( & V_33 ) ;
F_38 ( & V_62 ) ;
F_34 ( ! F_44 ( & V_194 -> V_123 ) ) ;
F_34 ( ! F_44 ( & V_194 -> V_153 ) ) ;
F_34 ( V_53 -> V_94 != 1 ) ;
V_196 = F_138 ( & V_201 ) ;
F_113 ( V_194 ) ;
F_139 ( V_196 ) ;
F_59 ( & V_116 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_73 -> V_103 ) ;
} else {
F_126 ( V_135 . V_167 ) ;
F_109 ( V_135 . V_59 ) ;
}
F_27 ( V_135 . V_145 ) ;
F_27 ( V_135 . V_98 ) ;
return F_76 ( V_76 -> V_187 ) ;
V_198:
F_59 ( & V_116 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_73 -> V_103 ) ;
V_197:
F_140 ( V_76 ) ;
V_193:
F_109 ( V_135 . V_59 ) ;
V_192:
F_27 ( V_135 . V_145 ) ;
F_27 ( V_135 . V_98 ) ;
return F_125 ( V_90 ) ;
}
static void F_141 ( struct V_75 * V_76 ) {
struct V_55 * V_53 = V_76 -> V_130 ;
struct V_7 * V_8 = & V_53 -> V_72 ;
int V_90 ;
struct V_29 * V_30 ;
struct V_29 * V_31 ;
F_34 ( ! V_53 ) ;
F_34 ( V_53 -> V_94 != 1 ) ;
F_34 ( ! F_44 ( & V_8 -> V_153 ) ) ;
F_34 ( ! F_44 ( & V_8 -> V_123 ) ) ;
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
if ( ! F_44 ( & V_53 -> V_158 ) ) {
F_24 ( & V_53 -> V_158 ) ;
V_65 -- ;
}
F_59 ( & V_116 ) ;
F_59 ( & V_1 ) ;
F_142 ( V_76 ) ;
F_126 ( V_53 ) ;
}
int F_143 ( const struct V_7 * V_8 , char * V_202 , int V_203 )
{
char * V_204 ;
struct V_15 * V_15 = F_144 ( V_8 -> V_15 ,
F_1 () ) ;
if ( ! V_15 || V_8 == V_121 ) {
strcpy ( V_202 , L_15 ) ;
return 0 ;
}
V_204 = V_202 + V_203 ;
* -- V_204 = '\0' ;
for (; ; ) {
int V_205 = V_15 -> V_206 . V_205 ;
if ( ( V_204 -= V_205 ) < V_202 )
return - V_207 ;
memcpy ( V_204 , V_15 -> V_206 . V_98 , V_205 ) ;
V_8 = V_8 -> V_100 ;
if ( ! V_8 )
break;
V_15 = F_144 ( V_8 -> V_15 ,
F_1 () ) ;
if ( ! V_8 -> V_100 )
continue;
if ( -- V_204 < V_202 )
return - V_207 ;
* V_204 = '/' ;
}
memmove ( V_202 , V_204 , V_202 + V_203 - V_204 ) ;
return 0 ;
}
struct V_68 * F_145 ( struct V_208 * V_209 )
{
if ( V_209 -> V_210 ) {
V_209 -> V_211 = 0 ;
return F_146 ( V_209 ) ;
} else {
V_209 -> V_212 = V_209 -> V_213 . V_8 ;
return V_209 -> V_213 . V_69 ;
}
}
struct V_68 * F_146 ( struct V_208 * V_209 )
{
struct V_214 * V_215 ;
if ( ! V_209 -> V_210 || V_209 -> V_211 >= V_209 -> V_216 )
return NULL ;
V_215 = F_147 ( V_209 -> V_210 , V_209 -> V_211 ++ ) ;
V_209 -> V_212 = V_215 -> V_8 ;
return V_215 -> V_69 ;
}
struct V_7 * F_148 ( struct V_208 * V_209 )
{
return V_209 -> V_212 ;
}
int F_149 ( struct V_208 * V_209 )
{
return V_209 -> V_210 ? V_209 -> V_216 : 1 ;
}
static void F_150 ( struct V_7 * V_8 , struct V_7 * V_217 ,
struct V_68 * V_218 , struct V_26 * V_219 )
{
struct V_26 * V_54 ;
F_67 ( V_218 -> V_10 & V_220 ) ;
V_54 = V_218 -> V_70 ;
F_151 ( V_218 ) ;
F_152 ( V_218 -> V_70 , V_219 ) ;
F_153 ( V_218 ) ;
F_19 ( & V_33 ) ;
if ( ! F_44 ( & V_218 -> V_221 ) )
F_46 ( & V_218 -> V_221 , & V_219 -> V_66 ) ;
F_21 ( & V_33 ) ;
F_31 ( V_54 ) ;
F_25 ( V_12 , & V_217 -> V_10 ) ;
}
int F_154 ( struct V_7 * V_8 , struct V_68 * V_218 )
{
int V_222 = 0 ;
struct V_88 * V_89 , * V_223 = NULL ;
struct V_7 * V_217 ;
struct V_55 * V_53 = V_8 -> V_53 ;
struct V_208 V_209 = { } ;
struct V_26 * V_219 ;
if ( V_218 -> V_10 & V_220 )
return - V_224 ;
V_217 = F_55 ( V_218 , V_53 ) ;
if ( V_8 == V_217 )
return 0 ;
V_209 . V_213 . V_69 = V_218 ;
V_209 . V_213 . V_8 = V_217 ;
F_66 (root, ss) {
if ( V_89 -> V_225 ) {
V_222 = V_89 -> V_225 ( V_8 , & V_209 ) ;
if ( V_222 ) {
V_223 = V_89 ;
goto V_226;
}
}
}
V_219 = F_48 ( V_218 -> V_70 , V_8 ) ;
if ( ! V_219 ) {
V_222 = - V_61 ;
goto V_226;
}
F_150 ( V_8 , V_217 , V_218 , V_219 ) ;
F_66 (root, ss) {
if ( V_89 -> V_227 )
V_89 -> V_227 ( V_8 , & V_209 ) ;
}
F_70 () ;
F_89 ( V_8 ) ;
V_226:
if ( V_222 ) {
F_66 (root, ss) {
if ( V_89 == V_223 )
break;
if ( V_89 -> V_228 )
V_89 -> V_228 ( V_8 , & V_209 ) ;
}
}
return V_222 ;
}
int F_155 ( struct V_68 * V_229 , struct V_68 * V_218 )
{
struct V_55 * V_53 ;
int V_222 = 0 ;
F_56 () ;
F_137 (root) {
struct V_7 * V_230 = F_55 ( V_229 , V_53 ) ;
V_222 = F_154 ( V_230 , V_218 ) ;
if ( V_222 )
break;
}
F_58 () ;
return V_222 ;
}
static int F_156 ( struct V_7 * V_8 , struct V_68 * V_231 )
{
int V_222 , V_20 , V_232 ;
struct V_88 * V_89 , * V_223 = NULL ;
struct V_55 * V_53 = V_8 -> V_53 ;
struct V_68 * V_218 ;
struct V_214 * V_215 ;
struct V_233 * V_234 ;
struct V_208 V_209 = { } ;
V_232 = F_157 ( V_231 ) ;
V_234 = F_158 ( sizeof( * V_215 ) , V_232 , V_60 ) ;
if ( ! V_234 )
return - V_61 ;
V_222 = F_159 ( V_234 , 0 , V_232 - 1 , V_60 ) ;
if ( V_222 )
goto V_235;
V_218 = V_231 ;
V_20 = 0 ;
F_160 () ;
do {
struct V_214 V_236 ;
if ( V_218 -> V_10 & V_220 )
continue;
F_34 ( V_20 >= V_232 ) ;
V_236 . V_69 = V_218 ;
V_236 . V_8 = F_55 ( V_218 , V_53 ) ;
if ( V_236 . V_8 == V_8 )
continue;
V_222 = F_161 ( V_234 , V_20 , & V_236 , V_237 ) ;
F_34 ( V_222 != 0 ) ;
V_20 ++ ;
} while_each_thread(leader, tsk) ;
int F_162 ( struct V_7 * V_8 , T_2 V_238 , bool V_239 )
{
struct V_68 * V_218 ;
const struct V_196 * V_196 = F_163 () , * V_240 ;
int V_90 ;
if ( ! F_164 ( V_8 ) )
return - V_241 ;
V_242:
F_160 () ;
if ( V_238 ) {
V_218 = F_165 ( V_238 ) ;
if ( ! V_218 ) {
F_166 () ;
V_90 = - V_224 ;
goto V_243;
}
V_240 = F_167 ( V_218 ) ;
if ( ! F_168 ( V_196 -> V_244 , V_245 ) &&
! F_168 ( V_196 -> V_244 , V_240 -> V_246 ) &&
! F_168 ( V_196 -> V_244 , V_240 -> V_247 ) ) {
F_166 () ;
V_90 = - V_248 ;
goto V_243;
}
} else
V_218 = V_151 ;
if ( V_239 )
V_218 = V_218 -> V_249 ;
if ( V_218 == V_250 || ( V_218 -> V_10 & V_251 ) ) {
V_90 = - V_143 ;
F_166 () ;
goto V_243;
}
F_169 ( V_218 ) ;
F_166 () ;
F_170 ( V_218 ) ;
if ( V_239 ) {
if ( ! F_171 ( V_218 ) ) {
F_172 ( V_218 ) ;
F_173 ( V_218 ) ;
goto V_242;
}
V_90 = F_156 ( V_8 , V_218 ) ;
} else
V_90 = F_154 ( V_8 , V_218 ) ;
F_172 ( V_218 ) ;
F_173 ( V_218 ) ;
V_243:
F_58 () ;
return V_90 ;
}
static int F_174 ( struct V_7 * V_8 , struct V_18 * V_102 , T_2 V_238 )
{
return F_162 ( V_8 , V_238 , false ) ;
}
static int F_175 ( struct V_7 * V_8 , struct V_18 * V_102 , T_2 V_252 )
{
return F_162 ( V_8 , V_252 , true ) ;
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
const char * V_253 )
{
F_177 ( sizeof( V_8 -> V_53 -> V_132 ) < V_146 ) ;
if ( strlen ( V_253 ) >= V_146 )
return - V_143 ;
if ( ! F_164 ( V_8 ) )
return - V_241 ;
F_57 ( & V_116 ) ;
strcpy ( V_8 -> V_53 -> V_132 , V_253 ) ;
F_59 ( & V_116 ) ;
F_58 () ;
return 0 ;
}
static int F_178 ( struct V_7 * V_8 , struct V_18 * V_102 ,
struct V_127 * V_128 )
{
if ( ! F_164 ( V_8 ) )
return - V_241 ;
F_103 ( V_128 , V_8 -> V_53 -> V_132 ) ;
F_179 ( V_128 , '\n' ) ;
F_58 () ;
return 0 ;
}
static T_3 F_180 ( struct V_7 * V_8 , struct V_18 * V_102 ,
struct V_254 * V_254 ,
const char T_4 * V_255 ,
T_5 V_256 , T_6 * V_257 )
{
char V_253 [ V_258 ] ;
int V_222 = 0 ;
char * V_259 ;
if ( ! V_256 )
return - V_143 ;
if ( V_256 >= sizeof( V_253 ) )
return - V_260 ;
if ( F_181 ( V_253 , V_255 , V_256 ) )
return - V_261 ;
V_253 [ V_256 ] = 0 ;
if ( V_102 -> V_262 ) {
T_2 V_263 = F_182 ( F_183 ( V_253 ) , & V_259 , 0 ) ;
if ( * V_259 )
return - V_143 ;
V_222 = V_102 -> V_262 ( V_8 , V_102 , V_263 ) ;
} else {
T_7 V_263 = F_184 ( F_183 ( V_253 ) , & V_259 , 0 ) ;
if ( * V_259 )
return - V_143 ;
V_222 = V_102 -> V_264 ( V_8 , V_102 , V_263 ) ;
}
if ( ! V_222 )
V_222 = V_256 ;
return V_222 ;
}
static T_3 F_185 ( struct V_7 * V_8 , struct V_18 * V_102 ,
struct V_254 * V_254 ,
const char T_4 * V_255 ,
T_5 V_256 , T_6 * V_257 )
{
char V_265 [ V_258 ] ;
int V_222 = 0 ;
T_5 V_266 = V_102 -> V_267 ;
char * V_253 = V_265 ;
if ( ! V_266 )
V_266 = sizeof( V_265 ) - 1 ;
if ( V_256 >= V_266 )
return - V_260 ;
if ( V_256 >= sizeof( V_265 ) ) {
V_253 = F_41 ( V_256 + 1 , V_60 ) ;
if ( V_253 == NULL )
return - V_61 ;
}
if ( V_256 && F_181 ( V_253 , V_255 , V_256 ) ) {
V_222 = - V_261 ;
goto V_226;
}
V_253 [ V_256 ] = 0 ;
V_222 = V_102 -> V_268 ( V_8 , V_102 , F_183 ( V_253 ) ) ;
if ( ! V_222 )
V_222 = V_256 ;
V_226:
if ( V_253 != V_265 )
F_27 ( V_253 ) ;
return V_222 ;
}
static T_3 F_186 ( struct V_254 * V_254 , const char T_4 * V_202 ,
T_5 V_256 , T_6 * V_269 )
{
struct V_18 * V_102 = F_14 ( V_254 -> V_270 ) ;
struct V_7 * V_8 = F_12 ( V_254 -> V_270 -> V_97 ) ;
if ( F_7 ( V_8 ) )
return - V_241 ;
if ( V_102 -> V_271 )
return V_102 -> V_271 ( V_8 , V_102 , V_254 , V_202 , V_256 , V_269 ) ;
if ( V_102 -> V_262 || V_102 -> V_264 )
return F_180 ( V_8 , V_102 , V_254 , V_202 , V_256 , V_269 ) ;
if ( V_102 -> V_268 )
return F_185 ( V_8 , V_102 , V_254 , V_202 , V_256 , V_269 ) ;
if ( V_102 -> V_272 ) {
int V_90 = V_102 -> V_272 ( V_8 , ( unsigned int ) V_102 -> V_273 ) ;
return V_90 ? V_90 : V_256 ;
}
return - V_143 ;
}
static T_3 F_187 ( struct V_7 * V_8 , struct V_18 * V_102 ,
struct V_254 * V_254 ,
char T_4 * V_202 , T_5 V_256 ,
T_6 * V_269 )
{
char V_22 [ V_258 ] ;
T_2 V_263 = V_102 -> V_274 ( V_8 , V_102 ) ;
int V_205 = sprintf ( V_22 , L_16 , ( unsigned long long ) V_263 ) ;
return F_188 ( V_202 , V_256 , V_269 , V_22 , V_205 ) ;
}
static T_3 F_189 ( struct V_7 * V_8 , struct V_18 * V_102 ,
struct V_254 * V_254 ,
char T_4 * V_202 , T_5 V_256 ,
T_6 * V_269 )
{
char V_22 [ V_258 ] ;
T_7 V_263 = V_102 -> V_275 ( V_8 , V_102 ) ;
int V_205 = sprintf ( V_22 , L_17 , ( long long ) V_263 ) ;
return F_188 ( V_202 , V_256 , V_269 , V_22 , V_205 ) ;
}
static T_3 F_190 ( struct V_254 * V_254 , char T_4 * V_202 ,
T_5 V_256 , T_6 * V_269 )
{
struct V_18 * V_102 = F_14 ( V_254 -> V_270 ) ;
struct V_7 * V_8 = F_12 ( V_254 -> V_270 -> V_97 ) ;
if ( F_7 ( V_8 ) )
return - V_241 ;
if ( V_102 -> V_276 )
return V_102 -> V_276 ( V_8 , V_102 , V_254 , V_202 , V_256 , V_269 ) ;
if ( V_102 -> V_274 )
return F_187 ( V_8 , V_102 , V_254 , V_202 , V_256 , V_269 ) ;
if ( V_102 -> V_275 )
return F_189 ( V_8 , V_102 , V_254 , V_202 , V_256 , V_269 ) ;
return - V_143 ;
}
static int F_191 ( struct V_277 * V_278 , const char * V_279 , T_2 V_280 )
{
struct V_127 * V_281 = V_278 -> V_282 ;
return F_102 ( V_281 , L_18 , V_279 , ( unsigned long long ) V_280 ) ;
}
static int F_192 ( struct V_127 * V_283 , void * V_284 )
{
struct V_285 * V_282 = V_283 -> V_273 ;
struct V_18 * V_102 = V_282 -> V_102 ;
if ( V_102 -> V_286 ) {
struct V_277 V_278 = {
. V_287 = F_191 ,
. V_282 = V_283 ,
} ;
return V_102 -> V_286 ( V_282 -> V_7 , V_102 , & V_278 ) ;
}
return V_102 -> V_288 ( V_282 -> V_7 , V_102 , V_283 ) ;
}
static int F_193 ( struct V_73 * V_73 , struct V_254 * V_254 )
{
struct V_127 * V_128 = V_254 -> V_289 ;
F_27 ( V_128 -> V_273 ) ;
return F_194 ( V_73 , V_254 ) ;
}
static int F_195 ( struct V_73 * V_73 , struct V_254 * V_254 )
{
int V_290 ;
struct V_18 * V_102 ;
V_290 = F_196 ( V_73 , V_254 ) ;
if ( V_290 )
return V_290 ;
V_102 = F_14 ( V_254 -> V_270 ) ;
if ( V_102 -> V_286 || V_102 -> V_288 ) {
struct V_285 * V_282 =
F_124 ( sizeof( * V_282 ) , V_291 ) ;
if ( ! V_282 )
return - V_61 ;
V_282 -> V_102 = V_102 ;
V_282 -> V_7 = F_12 ( V_254 -> V_270 -> V_97 ) ;
V_254 -> V_292 = & V_293 ;
V_290 = F_197 ( V_254 , F_192 , V_282 ) ;
if ( V_290 < 0 )
F_27 ( V_282 ) ;
} else if ( V_102 -> V_294 )
V_290 = V_102 -> V_294 ( V_73 , V_254 ) ;
else
V_290 = 0 ;
return V_290 ;
}
static int F_198 ( struct V_73 * V_73 , struct V_254 * V_254 )
{
struct V_18 * V_102 = F_14 ( V_254 -> V_270 ) ;
if ( V_102 -> V_295 )
return V_102 -> V_295 ( V_73 , V_254 ) ;
return 0 ;
}
static int F_199 ( struct V_73 * V_296 , struct V_15 * V_297 ,
struct V_73 * V_298 , struct V_15 * V_299 )
{
if ( ! F_69 ( V_297 -> V_101 -> V_78 ) )
return - V_300 ;
if ( V_299 -> V_101 )
return - V_301 ;
if ( V_296 != V_298 )
return - V_302 ;
return F_200 ( V_296 , V_297 , V_298 , V_299 ) ;
}
static struct V_15 * F_201 ( struct V_73 * V_105 , struct V_15 * V_15 , struct V_303 * V_304 )
{
if ( V_15 -> V_206 . V_205 > V_305 )
return F_125 ( - V_207 ) ;
F_202 ( V_15 , NULL ) ;
return NULL ;
}
static inline struct V_18 * F_203 ( struct V_254 * V_254 )
{
if ( V_254 -> V_270 -> V_101 -> V_183 != & V_306 )
return F_125 ( - V_143 ) ;
return F_14 ( V_254 -> V_270 ) ;
}
static int F_204 ( struct V_15 * V_15 , T_1 V_74 ,
struct V_75 * V_76 )
{
struct V_73 * V_73 ;
if ( ! V_15 )
return - V_104 ;
if ( V_15 -> V_101 )
return - V_301 ;
V_73 = F_60 ( V_74 , V_76 ) ;
if ( ! V_73 )
return - V_61 ;
if ( F_69 ( V_74 ) ) {
V_73 -> V_185 = & V_186 ;
V_73 -> V_183 = & V_184 ;
F_131 ( V_73 ) ;
F_205 ( & V_73 -> V_103 , V_307 ) ;
} else if ( F_206 ( V_74 ) ) {
V_73 -> V_308 = 0 ;
V_73 -> V_183 = & V_306 ;
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
error = F_204 ( V_15 , V_179 | V_74 , V_8 -> V_53 -> V_76 ) ;
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
if ( V_102 -> V_276 || V_102 -> V_274 || V_102 -> V_275 ||
V_102 -> V_286 || V_102 -> V_288 )
V_74 |= V_180 ;
if ( V_102 -> V_271 || V_102 -> V_262 || V_102 -> V_264 ||
V_102 -> V_268 || V_102 -> V_272 )
V_74 |= V_182 ;
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
char V_98 [ V_309 + V_310 + 2 ] = { 0 } ;
if ( ( V_102 -> V_10 & V_311 ) && ! V_8 -> V_100 )
return 0 ;
if ( ( V_102 -> V_10 & V_312 ) && V_8 -> V_100 )
return 0 ;
if ( V_46 && ! F_8 ( V_131 , & V_8 -> V_53 -> V_10 ) ) {
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
goto V_226;
}
V_74 = F_209 ( V_102 ) ;
error = F_204 ( V_15 , V_74 | V_313 , V_8 -> V_53 -> V_76 ) ;
if ( ! error ) {
V_96 -> type = ( void * ) V_102 ;
V_96 -> V_15 = V_15 ;
V_15 -> V_16 = V_96 ;
F_47 ( & V_96 -> V_58 , & V_100 -> V_106 ) ;
V_96 = NULL ;
}
F_79 ( V_15 ) ;
V_226:
F_27 ( V_96 ) ;
return error ;
}
static int F_212 ( struct V_7 * V_8 , struct V_88 * V_46 ,
const struct V_18 V_314 [] , bool V_315 )
{
const struct V_18 * V_102 ;
int V_290 , V_90 = 0 ;
for ( V_102 = V_314 ; V_102 -> V_98 [ 0 ] != '\0' ; V_102 ++ ) {
if ( V_315 )
V_290 = F_210 ( V_8 , V_46 , V_102 ) ;
else
V_290 = F_80 ( V_8 , V_102 ) ;
if ( V_290 ) {
F_111 ( L_20 ,
V_315 ? L_21 : L_22 , V_102 -> V_98 , V_290 ) ;
V_90 = V_290 ;
}
}
return V_90 ;
}
static void F_213 ( void )
__acquires( &cgroup_cft_mutex
static void F_214 ( struct V_88 * V_89 ,
const struct V_18 * V_314 , bool V_315 )
__releases( &cgroup_mutex
int F_215 ( struct V_88 * V_89 , const struct V_18 * V_314 )
{
struct V_316 * V_317 ;
V_317 = F_124 ( sizeof( * V_317 ) , V_60 ) ;
if ( ! V_317 )
return - V_61 ;
F_213 () ;
V_317 -> V_314 = V_314 ;
F_47 ( & V_317 -> V_58 , & V_89 -> V_318 ) ;
F_214 ( V_89 , V_314 , true ) ;
return 0 ;
}
int F_216 ( struct V_88 * V_89 , const struct V_18 * V_314 )
{
struct V_316 * V_317 ;
F_213 () ;
F_53 (set, &ss->cftsets, node) {
if ( V_317 -> V_314 == V_314 ) {
F_83 ( & V_317 -> V_58 ) ;
F_214 ( V_89 , V_314 , false ) ;
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
struct V_319 * V_320 )
{
struct V_43 * V_321 = V_320 -> V_322 ;
struct V_29 * V_30 ;
struct V_26 * V_27 ;
do {
V_321 = V_321 -> V_52 ;
if ( V_321 == & V_8 -> V_63 ) {
V_320 -> V_322 = NULL ;
return;
}
V_30 = F_35 ( V_321 , struct V_29 , V_37 ) ;
V_27 = V_30 -> V_27 ;
} while ( F_44 ( & V_27 -> V_66 ) );
V_320 -> V_322 = V_321 ;
V_320 -> V_69 = V_27 -> V_66 . V_52 ;
}
static void F_219 ( void )
{
struct V_68 * V_323 , * V_324 ;
F_19 ( & V_33 ) ;
V_325 = 1 ;
F_49 ( & V_326 ) ;
F_220 (g, p) {
F_151 ( V_323 ) ;
if ( ! ( V_323 -> V_10 & V_220 ) && F_44 ( & V_323 -> V_221 ) )
F_42 ( & V_323 -> V_221 , & V_323 -> V_70 -> V_66 ) ;
F_153 ( V_323 ) ;
} F_221 ( V_324 , V_323 ) ;
F_50 ( & V_326 ) ;
F_21 ( & V_33 ) ;
}
void F_222 ( struct V_7 * V_8 , struct V_319 * V_320 )
__acquires( V_33 )
{
if ( ! V_325 )
F_219 () ;
F_49 ( & V_33 ) ;
V_320 -> V_322 = & V_8 -> V_63 ;
F_218 ( V_8 , V_320 ) ;
}
struct V_68 * F_223 ( struct V_7 * V_8 ,
struct V_319 * V_320 )
{
struct V_68 * V_64 ;
struct V_43 * V_321 = V_320 -> V_69 ;
struct V_29 * V_30 ;
if ( ! V_320 -> V_322 )
return NULL ;
V_64 = F_35 ( V_321 , struct V_68 , V_221 ) ;
V_321 = V_321 -> V_52 ;
V_30 = F_35 ( V_320 -> V_322 , struct V_29 , V_37 ) ;
if ( V_321 == & V_30 -> V_27 -> V_66 ) {
F_218 ( V_8 , V_320 ) ;
} else {
V_320 -> V_69 = V_321 ;
}
return V_64 ;
}
void F_224 ( struct V_7 * V_8 , struct V_319 * V_320 )
__releases( V_33 )
{
F_50 ( & V_33 ) ;
}
static inline int F_225 ( struct V_68 * V_327 ,
struct V_328 * time ,
struct V_68 * V_329 )
{
int V_330 = F_226 ( & V_327 -> V_331 , time ) ;
if ( V_330 > 0 ) {
return 1 ;
} else if ( V_330 < 0 ) {
return 0 ;
} else {
return V_327 > V_329 ;
}
}
static inline int F_227 ( void * V_332 , void * V_333 )
{
struct V_68 * V_327 = V_332 ;
struct V_68 * V_329 = V_333 ;
return F_225 ( V_327 , & V_329 -> V_331 , V_329 ) ;
}
int F_228 ( struct V_334 * V_335 )
{
int V_222 , V_20 ;
struct V_319 V_320 ;
struct V_68 * V_323 , * V_336 ;
struct V_68 * V_337 = NULL ;
struct V_338 V_339 ;
struct V_338 * V_340 ;
struct V_328 V_341 = { 0 , 0 } ;
if ( V_335 -> V_340 ) {
V_340 = V_335 -> V_340 ;
V_340 -> V_342 = & F_227 ;
} else {
V_340 = & V_339 ;
V_222 = F_229 ( V_340 , V_343 , V_60 , & F_227 ) ;
if ( V_222 )
return V_222 ;
}
V_344:
V_340 -> V_345 = 0 ;
F_222 ( V_335 -> V_27 , & V_320 ) ;
while ( ( V_323 = F_223 ( V_335 -> V_27 , & V_320 ) ) ) {
if ( V_335 -> V_346 && ! V_335 -> V_346 ( V_323 , V_335 ) )
continue;
if ( ! F_225 ( V_323 , & V_341 , V_337 ) )
continue;
V_336 = F_230 ( V_340 , V_323 ) ;
if ( V_336 == NULL ) {
F_169 ( V_323 ) ;
} else if ( V_336 != V_323 ) {
F_169 ( V_323 ) ;
F_173 ( V_336 ) ;
}
}
F_224 ( V_335 -> V_27 , & V_320 ) ;
if ( V_340 -> V_345 ) {
for ( V_20 = 0 ; V_20 < V_340 -> V_345 ; V_20 ++ ) {
struct V_68 * V_347 = V_340 -> V_348 [ V_20 ] ;
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
F_231 ( & V_339 ) ;
return 0 ;
}
static void * F_232 ( int V_38 )
{
if ( F_233 ( V_38 ) )
return F_234 ( V_38 * sizeof( V_350 ) ) ;
else
return F_41 ( V_38 * sizeof( V_350 ) , V_60 ) ;
}
static void F_235 ( void * V_323 )
{
if ( F_236 ( V_323 ) )
F_237 ( V_323 ) ;
else
F_27 ( V_323 ) ;
}
static void * F_238 ( void * V_323 , int V_351 )
{
void * V_352 ;
if ( F_236 ( V_323 ) ) {
V_352 = F_234 ( V_351 * sizeof( V_350 ) ) ;
if ( ! V_352 )
return NULL ;
memcpy ( V_352 , V_323 , V_351 * sizeof( V_350 ) ) ;
F_237 ( V_323 ) ;
} else {
V_352 = F_239 ( V_323 , V_351 * sizeof( V_350 ) , V_60 ) ;
}
return V_352 ;
}
static int F_240 ( V_350 * * V_323 , int V_353 )
{
int V_354 , V_355 = 1 ;
V_350 * V_356 = * V_323 ;
V_350 * V_352 ;
if ( V_353 == 0 || V_353 == 1 )
return V_353 ;
for ( V_354 = 1 ; V_354 < V_353 ; V_354 ++ ) {
while ( V_356 [ V_354 ] == V_356 [ V_354 - 1 ] ) {
V_354 ++ ;
if ( V_354 == V_353 )
goto V_357;
}
V_356 [ V_355 ] = V_356 [ V_354 ] ;
V_355 ++ ;
}
V_357:
if ( F_241 ( V_353 , V_355 ) ) {
V_352 = F_238 ( V_356 , V_355 ) ;
if ( V_352 )
* V_323 = V_352 ;
}
return V_355 ;
}
static int F_242 ( const void * V_358 , const void * V_359 )
{
return * ( V_350 * ) V_358 - * ( V_350 * ) V_359 ;
}
static struct V_360 * F_243 ( struct V_7 * V_8 ,
enum V_361 type )
{
struct V_360 * V_321 ;
struct V_362 * V_363 = V_151 -> V_364 -> V_365 ;
F_57 ( & V_8 -> V_155 ) ;
F_53 (l, &cgrp->pidlists, links) {
if ( V_321 -> V_279 . type == type && V_321 -> V_279 . V_363 == V_363 ) {
F_244 ( & V_321 -> V_366 ) ;
F_59 ( & V_8 -> V_155 ) ;
return V_321 ;
}
}
V_321 = F_41 ( sizeof( struct V_360 ) , V_60 ) ;
if ( ! V_321 ) {
F_59 ( & V_8 -> V_155 ) ;
return V_321 ;
}
F_245 ( & V_321 -> V_366 ) ;
F_244 ( & V_321 -> V_366 ) ;
V_321 -> V_279 . type = type ;
V_321 -> V_279 . V_363 = F_246 ( V_363 ) ;
V_321 -> V_367 = 0 ;
V_321 -> V_356 = NULL ;
V_321 -> V_368 = V_8 ;
F_42 ( & V_321 -> V_369 , & V_8 -> V_95 ) ;
F_59 ( & V_8 -> V_155 ) ;
return V_321 ;
}
static int F_247 ( struct V_7 * V_8 , enum V_361 type ,
struct V_360 * * V_370 )
{
V_350 * V_371 ;
int V_353 ;
int V_238 , V_372 = 0 ;
struct V_319 V_320 ;
struct V_68 * V_218 ;
struct V_360 * V_321 ;
V_353 = F_217 ( V_8 ) ;
V_371 = F_232 ( V_353 ) ;
if ( ! V_371 )
return - V_61 ;
F_222 ( V_8 , & V_320 ) ;
while ( ( V_218 = F_223 ( V_8 , & V_320 ) ) ) {
if ( F_90 ( V_372 == V_353 ) )
break;
if ( type == V_373 )
V_238 = F_248 ( V_218 ) ;
else
V_238 = F_249 ( V_218 ) ;
if ( V_238 > 0 )
V_371 [ V_372 ++ ] = V_238 ;
}
F_224 ( V_8 , & V_320 ) ;
V_353 = V_372 ;
F_250 ( V_371 , V_353 , sizeof( V_350 ) , F_242 , NULL ) ;
if ( type == V_373 )
V_353 = F_240 ( & V_371 , V_353 ) ;
V_321 = F_243 ( V_8 , type ) ;
if ( ! V_321 ) {
F_235 ( V_371 ) ;
return - V_61 ;
}
F_235 ( V_321 -> V_356 ) ;
V_321 -> V_356 = V_371 ;
V_321 -> V_353 = V_353 ;
V_321 -> V_367 ++ ;
F_251 ( & V_321 -> V_366 ) ;
* V_370 = V_321 ;
return 0 ;
}
int F_252 ( struct V_374 * V_375 , struct V_15 * V_15 )
{
int V_90 = - V_143 ;
struct V_7 * V_8 ;
struct V_319 V_320 ;
struct V_68 * V_218 ;
if ( V_15 -> V_129 -> V_174 != & V_175 ||
! F_69 ( V_15 -> V_101 -> V_78 ) )
goto V_290;
V_90 = 0 ;
V_8 = V_15 -> V_16 ;
F_222 ( V_8 , & V_320 ) ;
while ( ( V_218 = F_223 ( V_8 , & V_320 ) ) ) {
switch ( V_218 -> V_282 ) {
case V_376 :
V_375 -> V_377 ++ ;
break;
case V_378 :
V_375 -> V_379 ++ ;
break;
case V_380 :
V_375 -> V_381 ++ ;
break;
case V_382 :
V_375 -> V_383 ++ ;
break;
default:
if ( F_253 ( V_218 ) )
V_375 -> V_384 ++ ;
break;
}
}
F_224 ( V_8 , & V_320 ) ;
V_290:
return V_90 ;
}
static void * F_254 ( struct V_127 * V_385 , T_6 * V_386 )
{
struct V_360 * V_321 = V_385 -> V_273 ;
int V_21 = 0 , V_238 = * V_386 ;
int * V_387 ;
F_255 ( & V_321 -> V_366 ) ;
if ( V_238 ) {
int V_259 = V_321 -> V_353 ;
while ( V_21 < V_259 ) {
int V_388 = ( V_21 + V_259 ) / 2 ;
if ( V_321 -> V_356 [ V_388 ] == V_238 ) {
V_21 = V_388 ;
break;
} else if ( V_321 -> V_356 [ V_388 ] <= V_238 )
V_21 = V_388 + 1 ;
else
V_259 = V_388 ;
}
}
if ( V_21 >= V_321 -> V_353 )
return NULL ;
V_387 = V_321 -> V_356 + V_21 ;
* V_386 = * V_387 ;
return V_387 ;
}
static void F_256 ( struct V_127 * V_385 , void * V_6 )
{
struct V_360 * V_321 = V_385 -> V_273 ;
F_257 ( & V_321 -> V_366 ) ;
}
static void * F_258 ( struct V_127 * V_385 , void * V_6 , T_6 * V_386 )
{
struct V_360 * V_321 = V_385 -> V_273 ;
V_350 * V_323 = V_6 ;
V_350 * V_259 = V_321 -> V_356 + V_321 -> V_353 ;
V_323 ++ ;
if ( V_323 >= V_259 ) {
return NULL ;
} else {
* V_386 = * V_323 ;
return V_323 ;
}
}
static int F_259 ( struct V_127 * V_385 , void * V_6 )
{
return F_102 ( V_385 , L_23 , * ( int * ) V_6 ) ;
}
static void F_260 ( struct V_360 * V_321 )
{
F_57 ( & V_321 -> V_368 -> V_155 ) ;
F_244 ( & V_321 -> V_366 ) ;
F_34 ( ! V_321 -> V_367 ) ;
if ( ! -- V_321 -> V_367 ) {
F_24 ( & V_321 -> V_369 ) ;
F_59 ( & V_321 -> V_368 -> V_155 ) ;
F_235 ( V_321 -> V_356 ) ;
F_261 ( V_321 -> V_279 . V_363 ) ;
F_251 ( & V_321 -> V_366 ) ;
F_27 ( V_321 ) ;
return;
}
F_59 ( & V_321 -> V_368 -> V_155 ) ;
F_251 ( & V_321 -> V_366 ) ;
}
static int F_262 ( struct V_73 * V_73 , struct V_254 * V_254 )
{
struct V_360 * V_321 ;
if ( ! ( V_254 -> V_389 & V_390 ) )
return 0 ;
V_321 = ( (struct V_127 * ) V_254 -> V_289 ) -> V_273 ;
F_260 ( V_321 ) ;
return F_263 ( V_73 , V_254 ) ;
}
static int F_264 ( struct V_254 * V_254 , enum V_361 type )
{
struct V_7 * V_8 = F_12 ( V_254 -> V_270 -> V_97 ) ;
struct V_360 * V_321 ;
int V_222 ;
if ( ! ( V_254 -> V_389 & V_390 ) )
return 0 ;
V_222 = F_247 ( V_8 , type , & V_321 ) ;
if ( V_222 )
return V_222 ;
V_254 -> V_292 = & V_391 ;
V_222 = F_265 ( V_254 , & V_392 ) ;
if ( V_222 ) {
F_260 ( V_321 ) ;
return V_222 ;
}
( (struct V_127 * ) V_254 -> V_289 ) -> V_273 = V_321 ;
return 0 ;
}
static int F_266 ( struct V_73 * V_393 , struct V_254 * V_254 )
{
return F_264 ( V_254 , V_394 ) ;
}
static int F_267 ( struct V_73 * V_393 , struct V_254 * V_254 )
{
return F_264 ( V_254 , V_373 ) ;
}
static T_2 F_268 ( struct V_7 * V_8 ,
struct V_18 * V_102 )
{
return F_10 ( V_8 ) ;
}
static int F_269 ( struct V_7 * V_8 ,
struct V_18 * V_102 ,
T_2 V_263 )
{
F_270 ( V_12 , & V_8 -> V_10 ) ;
if ( V_263 )
F_25 ( V_13 , & V_8 -> V_10 ) ;
else
F_270 ( V_13 , & V_8 -> V_10 ) ;
return 0 ;
}
static void F_271 ( struct V_395 * V_396 )
{
struct V_397 * V_398 = F_272 ( V_396 , struct V_397 ,
remove ) ;
struct V_7 * V_8 = V_398 -> V_8 ;
V_398 -> V_102 -> V_399 ( V_8 , V_398 -> V_102 , V_398 -> V_400 ) ;
F_273 ( V_398 -> V_400 ) ;
F_27 ( V_398 ) ;
F_79 ( V_8 -> V_15 ) ;
}
static int F_274 ( T_8 * V_401 , unsigned V_74 ,
int V_402 , void * V_279 )
{
struct V_397 * V_398 = F_272 ( V_401 ,
struct V_397 , V_401 ) ;
struct V_7 * V_8 = V_398 -> V_8 ;
unsigned long V_10 = ( unsigned long ) V_279 ;
if ( V_10 & V_403 ) {
F_275 ( V_398 -> V_404 , & V_398 -> V_401 ) ;
F_86 ( & V_8 -> V_157 ) ;
F_24 ( & V_398 -> V_356 ) ;
F_88 ( & V_8 -> V_157 ) ;
F_276 ( & V_398 -> remove ) ;
}
return 0 ;
}
static void F_277 ( struct V_254 * V_254 ,
T_9 * V_404 , T_10 * V_405 )
{
struct V_397 * V_398 = F_272 ( V_405 ,
struct V_397 , V_405 ) ;
V_398 -> V_404 = V_404 ;
F_278 ( V_404 , & V_398 -> V_401 ) ;
}
static int F_279 ( struct V_7 * V_8 , struct V_18 * V_102 ,
const char * V_253 )
{
struct V_397 * V_398 = NULL ;
unsigned int V_406 , V_407 ;
struct V_254 * V_408 = NULL ;
struct V_254 * V_409 = NULL ;
char * V_410 ;
int V_90 ;
V_406 = F_280 ( V_253 , & V_410 , 10 ) ;
if ( * V_410 != ' ' )
return - V_143 ;
V_253 = V_410 + 1 ;
V_407 = F_280 ( V_253 , & V_410 , 10 ) ;
if ( ( * V_410 != ' ' ) && ( * V_410 != '\0' ) )
return - V_143 ;
V_253 = V_410 + 1 ;
V_398 = F_124 ( sizeof( * V_398 ) , V_60 ) ;
if ( ! V_398 )
return - V_61 ;
V_398 -> V_8 = V_8 ;
F_40 ( & V_398 -> V_356 ) ;
F_281 ( & V_398 -> V_405 , F_277 ) ;
F_282 ( & V_398 -> V_401 , F_274 ) ;
F_283 ( & V_398 -> remove , F_271 ) ;
V_408 = F_284 ( V_406 ) ;
if ( F_134 ( V_408 ) ) {
V_90 = F_135 ( V_408 ) ;
goto V_411;
}
V_398 -> V_400 = F_285 ( V_408 ) ;
if ( F_134 ( V_398 -> V_400 ) ) {
V_90 = F_135 ( V_398 -> V_400 ) ;
goto V_411;
}
V_409 = F_286 ( V_407 ) ;
if ( ! V_409 ) {
V_90 = - V_412 ;
goto V_411;
}
V_90 = F_287 ( V_409 -> V_413 . V_15 -> V_101 , V_414 ) ;
if ( V_90 < 0 )
goto V_411;
V_398 -> V_102 = F_203 ( V_409 ) ;
if ( F_134 ( V_398 -> V_102 ) ) {
V_90 = F_135 ( V_398 -> V_102 ) ;
goto V_411;
}
if ( ! V_398 -> V_102 -> V_415 || ! V_398 -> V_102 -> V_399 ) {
V_90 = - V_143 ;
goto V_411;
}
V_90 = V_398 -> V_102 -> V_415 ( V_8 , V_398 -> V_102 ,
V_398 -> V_400 , V_253 ) ;
if ( V_90 )
goto V_411;
if ( V_408 -> V_292 -> V_416 ( V_408 , & V_398 -> V_405 ) & V_403 ) {
V_398 -> V_102 -> V_399 ( V_8 , V_398 -> V_102 , V_398 -> V_400 ) ;
V_90 = 0 ;
goto V_411;
}
F_76 ( V_8 -> V_15 ) ;
F_86 ( & V_8 -> V_157 ) ;
F_42 ( & V_398 -> V_356 , & V_8 -> V_156 ) ;
F_88 ( & V_8 -> V_157 ) ;
F_288 ( V_409 ) ;
F_288 ( V_408 ) ;
return 0 ;
V_411:
if ( V_409 )
F_288 ( V_409 ) ;
if ( V_398 && V_398 -> V_400 && ! F_134 ( V_398 -> V_400 ) )
F_273 ( V_398 -> V_400 ) ;
if ( ! F_289 ( V_408 ) )
F_288 ( V_408 ) ;
F_27 ( V_398 ) ;
return V_90 ;
}
static T_2 F_290 ( struct V_7 * V_8 ,
struct V_18 * V_102 )
{
return F_11 ( V_8 ) ;
}
static int F_291 ( struct V_7 * V_8 ,
struct V_18 * V_102 ,
T_2 V_263 )
{
if ( V_263 )
F_25 ( V_14 , & V_8 -> V_10 ) ;
else
F_270 ( V_14 , & V_8 -> V_10 ) ;
return 0 ;
}
static int F_113 ( struct V_7 * V_8 )
{
int V_290 ;
struct V_88 * V_89 ;
V_290 = F_212 ( V_8 , NULL , V_106 , true ) ;
if ( V_290 < 0 )
return V_290 ;
F_66 (cgrp->root, ss) {
struct V_316 * V_317 ;
F_53 (set, &ss->cftsets, node)
F_212 ( V_8 , V_89 , V_317 -> V_314 , true ) ;
}
F_66 (cgrp->root, ss) {
struct V_4 * V_5 = V_8 -> V_46 [ V_89 -> V_417 ] ;
if ( V_5 -> V_418 )
F_152 ( V_5 -> V_418 -> V_5 , V_5 ) ;
}
return 0 ;
}
static void F_292 ( struct V_395 * V_396 )
{
struct V_4 * V_5 =
F_272 ( V_396 , struct V_4 , V_419 ) ;
struct V_15 * V_15 = V_5 -> V_7 -> V_15 ;
struct V_75 * V_76 = V_15 -> V_129 ;
F_30 ( & V_76 -> V_420 ) ;
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
V_5 -> V_418 = NULL ;
if ( V_8 == V_121 )
F_25 ( V_421 , & V_5 -> V_10 ) ;
F_34 ( V_8 -> V_46 [ V_89 -> V_417 ] ) ;
V_8 -> V_46 [ V_89 -> V_417 ] = V_5 ;
F_283 ( & V_5 -> V_419 , F_292 ) ;
if ( V_89 -> V_92 )
F_25 ( V_422 , & V_5 -> V_10 ) ;
}
static void F_294 ( struct V_55 * V_53 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 == NULL )
continue;
if ( V_89 -> V_53 == V_53 )
F_57 ( & V_89 -> V_122 ) ;
}
}
static void F_295 ( struct V_55 * V_53 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 == NULL )
continue;
if ( V_89 -> V_53 == V_53 )
F_59 ( & V_89 -> V_122 ) ;
}
}
static long F_296 ( struct V_7 * V_100 , struct V_15 * V_15 ,
T_1 V_74 )
{
struct V_7 * V_8 ;
struct V_55 * V_53 = V_100 -> V_53 ;
int V_290 = 0 ;
struct V_88 * V_89 ;
struct V_75 * V_76 = V_53 -> V_76 ;
V_8 = F_124 ( sizeof( * V_8 ) , V_60 ) ;
if ( ! V_8 )
return - V_61 ;
F_30 ( & V_76 -> V_420 ) ;
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
struct V_4 * V_5 = V_89 -> V_423 ( V_8 ) ;
if ( F_134 ( V_5 ) ) {
V_290 = F_135 ( V_5 ) ;
goto V_424;
}
F_293 ( V_5 , V_89 , V_8 ) ;
if ( V_89 -> V_425 ) {
V_290 = F_297 ( V_89 , V_100 , V_8 ) ;
if ( V_290 )
goto V_424;
}
if ( F_11 ( V_100 ) && V_89 -> V_426 )
V_89 -> V_426 ( V_8 ) ;
}
F_294 ( V_53 ) ;
F_42 ( & V_8 -> V_123 , & V_8 -> V_100 -> V_153 ) ;
F_295 ( V_53 ) ;
V_53 -> V_94 ++ ;
V_290 = F_208 ( V_8 , V_15 , V_74 ) ;
if ( V_290 < 0 )
goto V_427;
F_66 (root, ss)
if ( ! V_89 -> V_92 )
F_76 ( V_15 ) ;
F_34 ( ! F_3 ( & V_8 -> V_15 -> V_101 -> V_103 ) ) ;
F_47 ( & V_8 -> V_160 , & V_53 -> V_159 ) ;
V_290 = F_113 ( V_8 ) ;
F_59 ( & V_1 ) ;
F_59 ( & V_8 -> V_15 -> V_101 -> V_103 ) ;
return 0 ;
V_427:
F_294 ( V_53 ) ;
F_24 ( & V_8 -> V_123 ) ;
F_295 ( V_53 ) ;
V_53 -> V_94 -- ;
V_424:
F_66 (root, ss) {
if ( V_8 -> V_46 [ V_89 -> V_417 ] )
V_89 -> V_93 ( V_8 ) ;
}
F_59 ( & V_1 ) ;
F_71 ( V_76 ) ;
F_27 ( V_8 ) ;
return V_290 ;
}
static int F_298 ( struct V_73 * V_105 , struct V_15 * V_15 , T_1 V_74 )
{
struct V_7 * V_428 = V_15 -> V_97 -> V_16 ;
return F_296 ( V_428 , V_15 , V_74 | V_179 ) ;
}
static int F_299 ( struct V_7 * V_8 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
struct V_4 * V_5 ;
if ( V_89 == NULL || V_89 -> V_53 != V_8 -> V_53 )
continue;
V_5 = V_8 -> V_46 [ V_89 -> V_417 ] ;
if ( V_5 && F_5 ( V_5 ) > 1 )
return 1 ;
}
return 0 ;
}
static int F_300 ( struct V_7 * V_8 )
{
struct V_88 * V_89 ;
unsigned long V_10 ;
bool V_429 = false ;
F_301 ( V_10 ) ;
F_66 (cgrp->root, ss) {
struct V_4 * V_5 = V_8 -> V_46 [ V_89 -> V_417 ] ;
F_302 ( F_6 ( & V_5 -> V_2 ) < 0 ) ;
F_303 ( V_3 , & V_5 -> V_2 ) ;
if ( V_89 -> V_92 )
V_429 |= F_5 ( V_5 ) != 1 ;
}
F_66 (cgrp->root, ss) {
struct V_4 * V_5 = V_8 -> V_46 [ V_89 -> V_417 ] ;
if ( ! V_429 ) {
F_25 ( V_430 , & V_5 -> V_10 ) ;
F_96 ( V_5 ) ;
} else {
F_304 ( V_3 , & V_5 -> V_2 ) ;
}
}
F_305 ( V_10 ) ;
return ! V_429 ;
}
static int F_306 ( struct V_73 * V_431 , struct V_15 * V_15 )
{
struct V_7 * V_8 = V_15 -> V_16 ;
struct V_15 * V_99 ;
struct V_7 * V_100 ;
F_307 ( V_401 ) ;
struct V_397 * V_398 , * V_22 ;
int V_90 ;
V_344:
F_57 ( & V_1 ) ;
if ( F_6 ( & V_8 -> V_38 ) != 0 ) {
F_59 ( & V_1 ) ;
return - V_120 ;
}
if ( ! F_44 ( & V_8 -> V_153 ) ) {
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
if ( F_6 ( & V_8 -> V_38 ) || ! F_44 ( & V_8 -> V_153 ) ) {
F_270 ( V_111 , & V_8 -> V_10 ) ;
F_59 ( & V_1 ) ;
return - V_120 ;
}
F_308 ( & V_112 , & V_401 , V_378 ) ;
if ( ! F_300 ( V_8 ) ) {
F_59 ( & V_1 ) ;
if ( F_8 ( V_111 , & V_8 -> V_10 ) )
F_309 () ;
F_310 ( & V_112 , & V_401 ) ;
F_270 ( V_111 , & V_8 -> V_10 ) ;
if ( F_311 ( V_151 ) )
return - V_432 ;
goto V_344;
}
F_310 ( & V_112 , & V_401 ) ;
F_270 ( V_111 , & V_8 -> V_10 ) ;
F_312 ( & V_433 ) ;
F_25 ( V_9 , & V_8 -> V_10 ) ;
if ( ! F_44 ( & V_8 -> V_154 ) )
F_83 ( & V_8 -> V_154 ) ;
F_313 ( & V_433 ) ;
F_294 ( V_8 -> V_53 ) ;
F_83 ( & V_8 -> V_123 ) ;
F_295 ( V_8 -> V_53 ) ;
F_83 ( & V_8 -> V_160 ) ;
V_99 = F_76 ( V_8 -> V_15 ) ;
F_85 ( V_99 ) ;
F_79 ( V_99 ) ;
F_25 ( V_12 , & V_100 -> V_10 ) ;
F_26 ( V_100 ) ;
F_86 ( & V_8 -> V_157 ) ;
F_23 (event, tmp, &cgrp->event_list, list) {
F_24 ( & V_398 -> V_356 ) ;
F_314 ( V_398 -> V_404 , & V_398 -> V_401 ) ;
F_315 ( V_398 -> V_400 , 1 ) ;
F_276 ( & V_398 -> remove ) ;
}
F_88 ( & V_8 -> V_157 ) ;
F_59 ( & V_1 ) ;
return 0 ;
}
static void T_11 F_316 ( struct V_88 * V_89 )
{
F_40 ( & V_89 -> V_318 ) ;
if ( V_89 -> V_434 ) {
V_89 -> V_435 . V_314 = V_89 -> V_434 ;
F_47 ( & V_89 -> V_435 . V_58 , & V_89 -> V_318 ) ;
}
}
static void T_12 F_317 ( struct V_88 * V_89 )
{
struct V_4 * V_5 ;
F_318 ( V_436 L_24 , V_89 -> V_98 ) ;
F_316 ( V_89 ) ;
F_42 ( & V_89 -> V_123 , & V_119 . V_124 ) ;
V_89 -> V_53 = & V_119 ;
V_5 = V_89 -> V_423 ( V_121 ) ;
F_34 ( F_134 ( V_5 ) ) ;
F_293 ( V_5 , V_89 , V_121 ) ;
V_71 . V_46 [ V_89 -> V_417 ] = V_121 -> V_46 [ V_89 -> V_417 ] ;
V_437 |= V_89 -> V_438 || V_89 -> exit ;
F_34 ( ! F_44 ( & V_439 . V_66 ) ) ;
F_115 ( & V_89 -> V_122 ) ;
F_319 ( & V_89 -> V_122 , & V_89 -> V_440 ) ;
V_89 -> V_441 = 1 ;
F_34 ( V_89 -> V_126 ) ;
}
int T_11 F_320 ( struct V_88 * V_89 )
{
int V_20 ;
struct V_4 * V_5 ;
if ( V_89 -> V_98 == NULL || strlen ( V_89 -> V_98 ) > V_309 ||
V_89 -> V_423 == NULL || V_89 -> V_93 == NULL )
return - V_143 ;
if ( V_89 -> V_438 || V_89 -> exit )
return - V_143 ;
if ( V_89 -> V_126 == NULL ) {
F_34 ( V_89 -> V_417 >= V_149 ) ;
F_34 ( V_46 [ V_89 -> V_417 ] != V_89 ) ;
return 0 ;
}
F_316 ( V_89 ) ;
F_57 ( & V_1 ) ;
for ( V_20 = V_149 ; V_20 < V_23 ; V_20 ++ ) {
if ( V_46 [ V_20 ] == NULL )
break;
}
if ( V_20 == V_23 ) {
F_59 ( & V_1 ) ;
return - V_120 ;
}
V_89 -> V_417 = V_20 ;
V_46 [ V_20 ] = V_89 ;
V_5 = V_89 -> V_423 ( V_121 ) ;
if ( F_134 ( V_5 ) ) {
V_46 [ V_20 ] = NULL ;
F_59 ( & V_1 ) ;
return F_135 ( V_5 ) ;
}
F_42 ( & V_89 -> V_123 , & V_119 . V_124 ) ;
V_89 -> V_53 = & V_119 ;
F_293 ( V_5 , V_89 , V_121 ) ;
if ( V_89 -> V_425 ) {
int V_90 = F_321 ( V_89 , V_5 ) ;
if ( V_90 ) {
V_121 -> V_46 [ V_89 -> V_417 ] = NULL ;
V_89 -> V_93 ( V_121 ) ;
V_46 [ V_20 ] = NULL ;
F_59 ( & V_1 ) ;
return V_90 ;
}
}
F_19 ( & V_33 ) ;
for ( V_20 = 0 ; V_20 < V_200 ; V_20 ++ ) {
struct V_26 * V_27 ;
struct V_57 * V_58 , * V_22 ;
struct V_19 * V_442 = & V_25 [ V_20 ] , * V_443 ;
F_322 (cg, node, tmp, bucket, hlist) {
if ( V_27 -> V_46 [ V_89 -> V_417 ] )
continue;
F_22 ( & V_27 -> V_34 ) ;
V_27 -> V_46 [ V_89 -> V_417 ] = V_5 ;
V_443 = F_15 ( V_27 -> V_46 ) ;
F_54 ( & V_27 -> V_34 , V_443 ) ;
}
}
F_21 ( & V_33 ) ;
F_115 ( & V_89 -> V_122 ) ;
F_319 ( & V_89 -> V_122 , & V_89 -> V_440 ) ;
V_89 -> V_441 = 1 ;
F_59 ( & V_1 ) ;
return 0 ;
}
void F_323 ( struct V_88 * V_89 )
{
struct V_29 * V_30 ;
struct V_19 * V_56 ;
F_34 ( V_89 -> V_126 == NULL ) ;
F_34 ( V_89 -> V_53 != & V_119 ) ;
F_57 ( & V_1 ) ;
F_34 ( V_89 -> V_417 < V_149 ) ;
V_46 [ V_89 -> V_417 ] = NULL ;
F_83 ( & V_89 -> V_123 ) ;
F_19 ( & V_33 ) ;
F_53 (link, &dummytop->css_sets, cgrp_link_list) {
struct V_26 * V_27 = V_30 -> V_27 ;
F_22 ( & V_27 -> V_34 ) ;
F_34 ( ! V_27 -> V_46 [ V_89 -> V_417 ] ) ;
V_27 -> V_46 [ V_89 -> V_417 ] = NULL ;
V_56 = F_15 ( V_27 -> V_46 ) ;
F_54 ( & V_27 -> V_34 , V_56 ) ;
}
F_21 ( & V_33 ) ;
V_89 -> V_93 ( V_121 ) ;
V_121 -> V_46 [ V_89 -> V_417 ] = NULL ;
F_59 ( & V_1 ) ;
}
int T_12 F_324 ( void )
{
int V_20 ;
F_51 ( & V_71 . V_32 , 1 ) ;
F_40 ( & V_71 . V_47 ) ;
F_40 ( & V_71 . V_66 ) ;
F_52 ( & V_71 . V_34 ) ;
V_35 = 1 ;
F_117 ( & V_119 ) ;
V_65 = 1 ;
V_439 . V_70 = & V_71 ;
V_444 . V_27 = & V_71 ;
V_444 . V_8 = V_121 ;
F_42 ( & V_444 . V_37 ,
& V_119 . V_72 . V_63 ) ;
F_42 ( & V_444 . V_36 ,
& V_71 . V_47 ) ;
for ( V_20 = 0 ; V_20 < V_200 ; V_20 ++ )
F_325 ( & V_25 [ V_20 ] ) ;
for ( V_20 = 0 ; V_20 < V_149 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
F_34 ( ! V_89 -> V_98 ) ;
F_34 ( strlen ( V_89 -> V_98 ) > V_309 ) ;
F_34 ( ! V_89 -> V_423 ) ;
F_34 ( ! V_89 -> V_93 ) ;
if ( V_89 -> V_417 != V_20 ) {
F_318 ( V_445 L_25 ,
V_89 -> V_98 , V_89 -> V_417 ) ;
F_326 () ;
}
if ( V_89 -> V_446 )
F_317 ( V_89 ) ;
}
return 0 ;
}
int T_12 F_327 ( void )
{
int V_290 ;
int V_20 ;
struct V_19 * V_56 ;
V_290 = F_328 ( & V_87 ) ;
if ( V_290 )
return V_290 ;
for ( V_20 = 0 ; V_20 < V_149 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( ! V_89 -> V_446 )
F_317 ( V_89 ) ;
if ( V_89 -> V_425 )
F_321 ( V_89 , V_71 . V_46 [ V_89 -> V_417 ] ) ;
}
V_56 = F_15 ( V_71 . V_46 ) ;
F_54 ( & V_71 . V_34 , V_56 ) ;
F_34 ( ! F_118 ( & V_119 ) ) ;
V_447 = F_329 ( L_26 , V_448 ) ;
if ( ! V_447 ) {
V_290 = - V_61 ;
goto V_226;
}
V_290 = F_330 ( & V_449 ) ;
if ( V_290 < 0 ) {
F_331 ( V_447 ) ;
goto V_226;
}
F_332 ( L_27 , 0 , NULL , & V_450 ) ;
V_226:
if ( V_290 )
F_333 ( & V_87 ) ;
return V_290 ;
}
static int F_334 ( struct V_127 * V_283 , void * V_6 )
{
struct V_238 * V_238 ;
struct V_68 * V_218 ;
char * V_202 ;
int V_222 ;
struct V_55 * V_53 ;
V_222 = - V_61 ;
V_202 = F_41 ( V_343 , V_60 ) ;
if ( ! V_202 )
goto V_226;
V_222 = - V_224 ;
V_238 = V_283 -> V_273 ;
V_218 = F_335 ( V_238 , V_451 ) ;
if ( ! V_218 )
goto V_452;
V_222 = 0 ;
F_57 ( & V_1 ) ;
F_137 (root) {
struct V_88 * V_89 ;
struct V_7 * V_8 ;
int V_38 = 0 ;
F_102 ( V_283 , L_28 , V_53 -> V_164 ) ;
F_66 (root, ss)
F_102 ( V_283 , L_29 , V_38 ++ ? L_7 : L_30 , V_89 -> V_98 ) ;
if ( strlen ( V_53 -> V_98 ) )
F_102 ( V_283 , L_31 , V_38 ? L_7 : L_30 ,
V_53 -> V_98 ) ;
F_179 ( V_283 , ':' ) ;
V_8 = F_55 ( V_218 , V_53 ) ;
V_222 = F_143 ( V_8 , V_202 , V_343 ) ;
if ( V_222 < 0 )
goto V_150;
F_103 ( V_283 , V_202 ) ;
F_179 ( V_283 , '\n' ) ;
}
V_150:
F_59 ( & V_1 ) ;
F_173 ( V_218 ) ;
V_452:
F_27 ( V_202 ) ;
V_226:
return V_222 ;
}
static int F_336 ( struct V_73 * V_73 , struct V_254 * V_254 )
{
struct V_238 * V_238 = F_337 ( V_73 ) -> V_238 ;
return F_197 ( V_254 , F_334 , V_238 ) ;
}
static int F_338 ( struct V_127 * V_283 , void * V_6 )
{
int V_20 ;
F_103 ( V_283 , L_32 ) ;
F_57 ( & V_1 ) ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 == NULL )
continue;
F_102 ( V_283 , L_33 ,
V_89 -> V_98 , V_89 -> V_53 -> V_164 ,
V_89 -> V_53 -> V_94 , ! V_89 -> V_148 ) ;
}
F_59 ( & V_1 ) ;
return 0 ;
}
static int F_339 ( struct V_73 * V_73 , struct V_254 * V_254 )
{
return F_197 ( V_254 , F_338 , NULL ) ;
}
void F_340 ( struct V_68 * V_453 )
{
V_453 -> V_70 = V_151 -> V_70 ;
F_29 ( V_453 -> V_70 ) ;
F_40 ( & V_453 -> V_221 ) ;
}
void F_341 ( struct V_68 * V_453 )
{
if ( V_437 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_149 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 -> V_438 )
V_89 -> V_438 ( V_453 ) ;
}
}
}
void F_342 ( struct V_68 * V_453 )
{
if ( V_325 ) {
F_19 ( & V_33 ) ;
if ( F_44 ( & V_453 -> V_221 ) ) {
F_42 ( & V_453 -> V_221 , & V_453 -> V_70 -> V_66 ) ;
}
F_21 ( & V_33 ) ;
}
}
void F_343 ( struct V_68 * V_218 , int V_454 )
{
struct V_26 * V_27 ;
int V_20 ;
if ( ! F_44 ( & V_218 -> V_221 ) ) {
F_19 ( & V_33 ) ;
if ( ! F_44 ( & V_218 -> V_221 ) )
F_83 ( & V_218 -> V_221 ) ;
F_21 ( & V_33 ) ;
}
F_151 ( V_218 ) ;
V_27 = V_218 -> V_70 ;
V_218 -> V_70 = & V_71 ;
if ( V_454 && V_437 ) {
for ( V_20 = 0 ; V_20 < V_149 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( V_89 -> exit ) {
struct V_7 * V_455 =
F_344 ( V_27 -> V_46 [ V_20 ] ) -> V_7 ;
struct V_7 * V_8 = F_345 ( V_218 , V_20 ) ;
V_89 -> exit ( V_8 , V_455 , V_218 ) ;
}
}
}
F_153 ( V_218 ) ;
if ( V_27 )
F_32 ( V_27 ) ;
}
int F_346 ( const struct V_7 * V_8 , struct V_68 * V_69 )
{
int V_90 ;
struct V_7 * V_456 ;
if ( V_8 == V_121 )
return 1 ;
V_456 = F_55 ( V_69 , V_8 -> V_53 ) ;
while ( V_8 != V_456 && V_8 != V_8 -> V_72 )
V_8 = V_8 -> V_100 ;
V_90 = ( V_8 == V_456 ) ;
return V_90 ;
}
static void F_26 ( struct V_7 * V_8 )
{
if ( F_9 ( V_8 ) && ! F_6 ( & V_8 -> V_38 )
&& F_44 ( & V_8 -> V_153 ) && ! F_299 ( V_8 ) ) {
int V_457 = 0 ;
F_312 ( & V_433 ) ;
if ( ! F_7 ( V_8 ) &&
F_44 ( & V_8 -> V_154 ) ) {
F_42 ( & V_8 -> V_154 , & V_154 ) ;
V_457 = 1 ;
}
F_313 ( & V_433 ) ;
if ( V_457 )
F_276 ( & V_458 ) ;
}
}
bool F_347 ( struct V_4 * V_5 )
{
do {
int V_6 = F_5 ( V_5 ) ;
if ( F_348 ( & V_5 -> V_2 , V_6 , V_6 + 1 ) == V_6 )
return true ;
F_349 () ;
} while ( ! F_8 ( V_430 , & V_5 -> V_10 ) );
return false ;
}
void F_350 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_7 ;
int V_6 ;
F_160 () ;
V_6 = F_4 ( F_351 ( & V_5 -> V_2 ) ) ;
switch ( V_6 ) {
case 1 :
if ( F_10 ( V_8 ) ) {
F_25 ( V_12 , & V_8 -> V_10 ) ;
F_26 ( V_8 ) ;
}
F_89 ( V_8 ) ;
break;
case 0 :
if ( ! F_8 ( V_422 , & V_5 -> V_10 ) )
F_276 ( & V_5 -> V_419 ) ;
break;
}
F_166 () ;
}
static void F_352 ( struct V_395 * V_396 )
{
F_34 ( V_396 != & V_458 ) ;
F_57 ( & V_1 ) ;
F_312 ( & V_433 ) ;
while ( ! F_44 ( & V_154 ) ) {
char * V_459 [ 3 ] , * V_460 [ 3 ] ;
int V_20 ;
char * V_461 = NULL , * V_462 = NULL ;
struct V_7 * V_8 = F_35 ( V_154 . V_52 ,
struct V_7 ,
V_154 ) ;
F_83 ( & V_8 -> V_154 ) ;
F_313 ( & V_433 ) ;
V_461 = F_41 ( V_343 , V_60 ) ;
if ( ! V_461 )
goto V_463;
if ( F_143 ( V_8 , V_461 , V_343 ) < 0 )
goto V_463;
V_462 = F_353 ( V_8 -> V_53 -> V_132 , V_60 ) ;
if ( ! V_462 )
goto V_463;
V_20 = 0 ;
V_459 [ V_20 ++ ] = V_462 ;
V_459 [ V_20 ++ ] = V_461 ;
V_459 [ V_20 ] = NULL ;
V_20 = 0 ;
V_460 [ V_20 ++ ] = L_34 ;
V_460 [ V_20 ++ ] = L_35 ;
V_460 [ V_20 ] = NULL ;
F_59 ( & V_1 ) ;
F_354 ( V_459 [ 0 ] , V_459 , V_460 , V_464 ) ;
F_57 ( & V_1 ) ;
V_463:
F_27 ( V_461 ) ;
F_27 ( V_462 ) ;
F_312 ( & V_433 ) ;
}
F_313 ( & V_433 ) ;
F_59 ( & V_1 ) ;
}
static int T_12 F_355 ( char * V_465 )
{
int V_20 ;
char * V_136 ;
while ( ( V_136 = F_106 ( & V_465 , L_7 ) ) != NULL ) {
if ( ! * V_136 )
continue;
for ( V_20 = 0 ; V_20 < V_149 ; V_20 ++ ) {
struct V_88 * V_89 = V_46 [ V_20 ] ;
if ( ! strcmp ( V_136 , V_89 -> V_98 ) ) {
V_89 -> V_148 = 1 ;
F_318 ( V_436 L_36
L_37 , V_89 -> V_98 ) ;
break;
}
}
}
return 1 ;
}
unsigned short F_356 ( struct V_4 * V_5 )
{
struct F_356 * V_466 ;
V_466 = F_144 ( V_5 -> V_418 , F_5 ( V_5 ) ) ;
if ( V_466 )
return V_466 -> V_418 ;
return 0 ;
}
unsigned short F_357 ( struct V_4 * V_5 )
{
struct F_356 * V_466 ;
V_466 = F_144 ( V_5 -> V_418 , F_5 ( V_5 ) ) ;
if ( V_466 )
return V_466 -> V_467 ;
return 0 ;
}
bool F_358 ( struct V_4 * V_453 ,
const struct V_4 * V_53 )
{
struct F_356 * V_468 ;
struct F_356 * V_469 ;
V_468 = F_359 ( V_453 -> V_418 ) ;
if ( ! V_468 )
return false ;
V_469 = F_359 ( V_53 -> V_418 ) ;
if ( ! V_469 )
return false ;
if ( V_468 -> V_467 < V_469 -> V_467 )
return false ;
if ( V_468 -> V_470 [ V_469 -> V_467 ] != V_469 -> V_418 )
return false ;
return true ;
}
void F_360 ( struct V_88 * V_89 , struct V_4 * V_5 )
{
struct F_356 * V_418 = V_5 -> V_418 ;
if ( ! V_418 )
return;
F_34 ( ! V_89 -> V_425 ) ;
F_152 ( V_418 -> V_5 , NULL ) ;
F_152 ( V_5 -> V_418 , NULL ) ;
F_86 ( & V_89 -> V_471 ) ;
F_361 ( & V_89 -> V_472 , V_418 -> V_418 ) ;
F_88 ( & V_89 -> V_471 ) ;
F_28 ( V_418 , V_39 ) ;
}
static struct F_356 * F_362 ( struct V_88 * V_89 , int V_467 )
{
struct F_356 * V_473 ;
int V_474 , error , V_345 ;
F_34 ( ! V_89 -> V_425 ) ;
V_345 = sizeof( * V_473 ) + sizeof( unsigned short ) * ( V_467 + 1 ) ;
V_473 = F_124 ( V_345 , V_60 ) ;
if ( ! V_473 )
return F_125 ( - V_61 ) ;
if ( F_90 ( ! F_363 ( & V_89 -> V_472 , V_60 ) ) ) {
error = - V_61 ;
goto V_475;
}
F_86 ( & V_89 -> V_471 ) ;
error = F_364 ( & V_89 -> V_472 , V_473 , 1 , & V_474 ) ;
F_88 ( & V_89 -> V_471 ) ;
if ( error ) {
error = - V_165 ;
goto V_475;
}
if ( V_474 > V_476 )
goto V_477;
V_473 -> V_418 = V_474 ;
V_473 -> V_467 = V_467 ;
return V_473 ;
V_477:
error = - V_165 ;
F_86 ( & V_89 -> V_471 ) ;
F_361 ( & V_89 -> V_472 , V_474 ) ;
F_88 ( & V_89 -> V_471 ) ;
V_475:
F_27 ( V_473 ) ;
return F_125 ( error ) ;
}
static int T_11 F_321 ( struct V_88 * V_89 ,
struct V_4 * V_478 )
{
struct F_356 * V_473 ;
F_116 ( & V_89 -> V_471 ) ;
F_365 ( & V_89 -> V_472 ) ;
V_473 = F_362 ( V_89 , 0 ) ;
if ( F_134 ( V_473 ) )
return F_135 ( V_473 ) ;
V_473 -> V_470 [ 0 ] = V_473 -> V_418 ;
V_473 -> V_5 = V_478 ;
V_478 -> V_418 = V_473 ;
return 0 ;
}
static int F_297 ( struct V_88 * V_89 , struct V_7 * V_100 ,
struct V_7 * V_453 )
{
int V_417 , V_20 , V_467 = 0 ;
struct V_4 * V_479 , * V_480 ;
struct F_356 * V_468 , * V_481 ;
V_417 = V_89 -> V_417 ;
V_479 = V_100 -> V_46 [ V_417 ] ;
V_480 = V_453 -> V_46 [ V_417 ] ;
V_481 = V_479 -> V_418 ;
V_467 = V_481 -> V_467 + 1 ;
V_468 = F_362 ( V_89 , V_467 ) ;
if ( F_134 ( V_468 ) )
return F_135 ( V_468 ) ;
for ( V_20 = 0 ; V_20 < V_467 ; V_20 ++ )
V_468 -> V_470 [ V_20 ] = V_481 -> V_470 [ V_20 ] ;
V_468 -> V_470 [ V_467 ] = V_468 -> V_418 ;
F_152 ( V_480 -> V_418 , V_468 ) ;
return 0 ;
}
struct V_4 * F_366 ( struct V_88 * V_89 , int V_418 )
{
struct F_356 * V_466 = NULL ;
F_34 ( ! V_89 -> V_425 ) ;
V_466 = F_367 ( & V_89 -> V_472 , V_418 ) ;
if ( F_90 ( ! V_466 ) )
return NULL ;
return F_359 ( V_466 -> V_5 ) ;
}
struct V_4 *
F_368 ( struct V_88 * V_89 , int V_418 ,
struct V_4 * V_53 , int * V_482 )
{
struct V_4 * V_90 = NULL ;
struct F_356 * V_22 ;
int V_483 ;
int V_484 = F_356 ( V_53 ) ;
int V_467 = F_357 ( V_53 ) ;
if ( ! V_484 )
return NULL ;
F_34 ( ! V_89 -> V_425 ) ;
F_67 ( ! F_369 () ) ;
V_483 = V_418 ;
while ( 1 ) {
V_22 = F_370 ( & V_89 -> V_472 , & V_483 ) ;
if ( ! V_22 )
break;
if ( V_22 -> V_467 >= V_467 && V_22 -> V_470 [ V_467 ] == V_484 ) {
V_90 = F_359 ( V_22 -> V_5 ) ;
if ( V_90 ) {
* V_482 = V_483 ;
break;
}
}
V_483 = V_483 + 1 ;
}
return V_90 ;
}
struct V_4 * F_371 ( struct V_254 * V_485 , int V_418 )
{
struct V_7 * V_8 ;
struct V_73 * V_73 ;
struct V_4 * V_5 ;
V_73 = V_485 -> V_270 -> V_101 ;
if ( V_73 -> V_185 != & V_186 )
return F_125 ( - V_412 ) ;
if ( V_418 < 0 || V_418 >= V_23 )
return F_125 ( - V_143 ) ;
V_8 = F_12 ( V_485 -> V_270 ) ;
V_5 = V_8 -> V_46 [ V_418 ] ;
return V_5 ? V_5 : F_125 ( - V_104 ) ;
}
static struct V_4 * F_372 ( struct V_7 * V_486 )
{
struct V_4 * V_5 = F_124 ( sizeof( * V_5 ) , V_60 ) ;
if ( ! V_5 )
return F_125 ( - V_61 ) ;
return V_5 ;
}
static void F_373 ( struct V_7 * V_486 )
{
F_27 ( V_486 -> V_46 [ V_487 ] ) ;
}
static T_2 F_374 ( struct V_7 * V_486 , struct V_18 * V_102 )
{
return F_6 ( & V_486 -> V_38 ) ;
}
static T_2 F_375 ( struct V_7 * V_486 , struct V_18 * V_102 )
{
return F_217 ( V_486 ) ;
}
static T_2 F_376 ( struct V_7 * V_486 , struct V_18 * V_102 )
{
return ( T_2 ) ( unsigned long ) V_151 -> V_70 ;
}
static T_2 F_377 ( struct V_7 * V_486 ,
struct V_18 * V_102 )
{
T_2 V_38 ;
F_160 () ;
V_38 = F_6 ( & V_151 -> V_70 -> V_32 ) ;
F_166 () ;
return V_38 ;
}
static int F_378 ( struct V_7 * V_486 ,
struct V_18 * V_102 ,
struct V_127 * V_128 )
{
struct V_29 * V_30 ;
struct V_26 * V_27 ;
F_49 ( & V_33 ) ;
F_160 () ;
V_27 = F_359 ( V_151 -> V_70 ) ;
F_53 (link, &cg->cg_links, cg_link_list) {
struct V_7 * V_67 = V_30 -> V_8 ;
const char * V_98 ;
if ( V_67 -> V_15 )
V_98 = V_67 -> V_15 -> V_206 . V_98 ;
else
V_98 = L_38 ;
F_102 ( V_128 , L_39 ,
V_67 -> V_53 -> V_164 , V_98 ) ;
}
F_166 () ;
F_50 ( & V_33 ) ;
return 0 ;
}
static int F_379 ( struct V_7 * V_486 ,
struct V_18 * V_102 ,
struct V_127 * V_128 )
{
struct V_29 * V_30 ;
F_49 ( & V_33 ) ;
F_53 (link, &cont->css_sets, cgrp_link_list) {
struct V_26 * V_27 = V_30 -> V_27 ;
struct V_68 * V_69 ;
int V_38 = 0 ;
F_102 ( V_128 , L_40 , V_27 ) ;
F_53 (task, &cg->tasks, cg_list) {
if ( V_38 ++ > V_488 ) {
F_103 ( V_128 , L_41 ) ;
break;
} else {
F_102 ( V_128 , L_42 ,
F_249 ( V_69 ) ) ;
}
}
}
F_50 ( & V_33 ) ;
return 0 ;
}
static T_2 F_380 ( struct V_7 * V_8 , struct V_18 * V_102 )
{
return F_8 ( V_12 , & V_8 -> V_10 ) ;
}
