int F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
int F_1 ( void )
{
return F_3 ( & V_1 ) ;
}
inline int F_4 ( const struct V_2 * V_3 )
{
return F_5 ( V_4 , & V_3 -> V_5 ) ;
}
static int F_6 ( const struct V_2 * V_3 )
{
const int V_6 =
( 1 << V_7 ) |
( 1 << V_8 ) ;
return ( V_3 -> V_5 & V_6 ) == V_6 ;
}
static int F_7 ( const struct V_2 * V_3 )
{
return F_5 ( V_8 , & V_3 -> V_5 ) ;
}
static int F_8 ( const struct V_2 * V_3 )
{
return F_5 ( V_9 , & V_3 -> V_5 ) ;
}
static struct V_10 * F_9 ( struct V_11 * V_12 [] )
{
int V_13 ;
int V_14 ;
unsigned long V_15 = 0UL ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ )
V_15 += ( unsigned long ) V_12 [ V_13 ] ;
V_15 = ( V_15 >> 16 ) ^ V_15 ;
V_14 = F_10 ( V_15 , V_17 ) ;
return & V_18 [ V_14 ] ;
}
static void F_11 ( struct V_19 * V_20 , int V_21 )
{
struct V_22 * V_23 ;
struct V_22 * V_24 ;
if ( F_12 ( & V_20 -> V_25 , - 1 , 1 ) )
return;
F_13 ( & V_26 ) ;
if ( ! F_14 ( & V_20 -> V_25 ) ) {
F_15 ( & V_26 ) ;
return;
}
F_16 ( & V_20 -> V_27 ) ;
V_28 -- ;
F_17 (link, saved_link, &cg->cg_links,
cg_link_list) {
struct V_2 * V_3 = V_23 -> V_3 ;
F_18 ( & V_23 -> V_29 ) ;
F_18 ( & V_23 -> V_30 ) ;
if ( F_14 ( & V_3 -> V_31 ) &&
F_7 ( V_3 ) ) {
if ( V_21 )
F_19 ( V_7 , & V_3 -> V_5 ) ;
F_20 ( V_3 ) ;
}
F_21 ( V_23 ) ;
}
F_15 ( & V_26 ) ;
F_22 ( V_20 , V_32 ) ;
}
static inline void F_23 ( struct V_19 * V_20 )
{
F_24 ( & V_20 -> V_25 ) ;
}
static inline void F_25 ( struct V_19 * V_20 )
{
F_11 ( V_20 , 0 ) ;
}
static inline void F_26 ( struct V_19 * V_20 )
{
F_11 ( V_20 , 1 ) ;
}
static bool F_27 ( struct V_19 * V_20 ,
struct V_19 * V_33 ,
struct V_2 * V_34 ,
struct V_11 * V_35 [] )
{
struct V_36 * V_37 , * V_38 ;
if ( memcmp ( V_35 , V_20 -> V_39 , sizeof( V_20 -> V_39 ) ) ) {
return false ;
}
V_37 = & V_20 -> V_40 ;
V_38 = & V_33 -> V_40 ;
while ( 1 ) {
struct V_22 * V_41 , * V_42 ;
struct V_2 * V_43 , * V_44 ;
V_37 = V_37 -> V_45 ;
V_38 = V_38 -> V_45 ;
if ( V_37 == & V_20 -> V_40 ) {
F_28 ( V_38 != & V_33 -> V_40 ) ;
break;
} else {
F_28 ( V_38 == & V_33 -> V_40 ) ;
}
V_41 = F_29 ( V_37 , struct V_22 , V_29 ) ;
V_42 = F_29 ( V_38 , struct V_22 , V_29 ) ;
V_43 = V_41 -> V_3 ;
V_44 = V_42 -> V_3 ;
F_28 ( V_43 -> V_46 != V_44 -> V_46 ) ;
if ( V_43 -> V_46 == V_34 -> V_46 ) {
if ( V_43 != V_34 )
return false ;
} else {
if ( V_43 != V_44 )
return false ;
}
}
return true ;
}
static struct V_19 * F_30 (
struct V_19 * V_47 ,
struct V_2 * V_3 ,
struct V_11 * V_35 [] )
{
int V_13 ;
struct V_48 * V_46 = V_3 -> V_46 ;
struct V_10 * V_49 ;
struct V_50 * V_51 ;
struct V_19 * V_20 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( V_46 -> V_52 & ( 1UL << V_13 ) ) {
V_35 [ V_13 ] = V_3 -> V_39 [ V_13 ] ;
} else {
V_35 [ V_13 ] = V_47 -> V_39 [ V_13 ] ;
}
}
V_49 = F_9 ( V_35 ) ;
F_31 (cg, node, hhead, hlist) {
if ( ! F_27 ( V_20 , V_47 , V_3 , V_35 ) )
continue;
return V_20 ;
}
return NULL ;
}
static void F_32 ( struct V_36 * V_15 )
{
struct V_22 * V_23 ;
struct V_22 * V_24 ;
F_17 (link, saved_link, tmp, cgrp_link_list) {
F_18 ( & V_23 -> V_30 ) ;
F_21 ( V_23 ) ;
}
}
static int F_33 ( int V_31 , struct V_36 * V_15 )
{
struct V_22 * V_23 ;
int V_13 ;
F_34 ( V_15 ) ;
for ( V_13 = 0 ; V_13 < V_31 ; V_13 ++ ) {
V_23 = F_35 ( sizeof( * V_23 ) , V_53 ) ;
if ( ! V_23 ) {
F_32 ( V_15 ) ;
return - V_54 ;
}
F_36 ( & V_23 -> V_30 , V_15 ) ;
}
return 0 ;
}
static void F_37 ( struct V_36 * V_55 ,
struct V_19 * V_20 , struct V_2 * V_3 )
{
struct V_22 * V_23 ;
F_28 ( F_38 ( V_55 ) ) ;
V_23 = F_39 ( V_55 , struct V_22 ,
V_30 ) ;
V_23 -> V_20 = V_20 ;
V_23 -> V_3 = V_3 ;
F_24 ( & V_3 -> V_31 ) ;
F_40 ( & V_23 -> V_30 , & V_3 -> V_56 ) ;
F_41 ( & V_23 -> V_29 , & V_20 -> V_40 ) ;
}
static struct V_19 * F_42 (
struct V_19 * V_47 , struct V_2 * V_3 )
{
struct V_19 * V_57 ;
struct V_11 * V_35 [ V_16 ] ;
struct V_36 V_55 ;
struct V_10 * V_49 ;
struct V_22 * V_23 ;
F_43 ( & V_26 ) ;
V_57 = F_30 ( V_47 , V_3 , V_35 ) ;
if ( V_57 )
F_23 ( V_57 ) ;
F_44 ( & V_26 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_35 ( sizeof( * V_57 ) , V_53 ) ;
if ( ! V_57 )
return NULL ;
if ( F_33 ( V_58 , & V_55 ) < 0 ) {
F_21 ( V_57 ) ;
return NULL ;
}
F_45 ( & V_57 -> V_25 , 1 ) ;
F_34 ( & V_57 -> V_40 ) ;
F_34 ( & V_57 -> V_59 ) ;
F_46 ( & V_57 -> V_27 ) ;
memcpy ( V_57 -> V_39 , V_35 , sizeof( V_57 -> V_39 ) ) ;
F_13 ( & V_26 ) ;
F_47 (link, &oldcg->cg_links, cg_link_list) {
struct V_2 * V_60 = V_23 -> V_3 ;
if ( V_60 -> V_46 == V_3 -> V_46 )
V_60 = V_3 ;
F_37 ( & V_55 , V_57 , V_60 ) ;
}
F_28 ( ! F_38 ( & V_55 ) ) ;
V_28 ++ ;
V_49 = F_9 ( V_57 -> V_39 ) ;
F_48 ( & V_57 -> V_27 , V_49 ) ;
F_15 ( & V_26 ) ;
return V_57 ;
}
static struct V_2 * F_49 ( struct V_61 * V_62 ,
struct V_48 * V_46 )
{
struct V_19 * V_12 ;
struct V_2 * V_57 = NULL ;
F_28 ( ! F_3 ( & V_1 ) ) ;
F_43 ( & V_26 ) ;
V_12 = V_62 -> V_63 ;
if ( V_12 == & V_64 ) {
V_57 = & V_46 -> V_65 ;
} else {
struct V_22 * V_23 ;
F_47 (link, &css->cg_links, cg_link_list) {
struct V_2 * V_60 = V_23 -> V_3 ;
if ( V_60 -> V_46 == V_46 ) {
V_57 = V_60 ;
break;
}
}
}
F_44 ( & V_26 ) ;
F_28 ( ! V_57 ) ;
return V_57 ;
}
void F_50 ( void )
{
F_51 ( & V_1 ) ;
}
void F_52 ( void )
{
F_53 ( & V_1 ) ;
}
static struct V_66 * F_54 ( T_1 V_67 , struct V_68 * V_69 )
{
struct V_66 * V_66 = F_55 ( V_69 ) ;
if ( V_66 ) {
V_66 -> V_70 = F_56 () ;
V_66 -> V_71 = V_67 ;
V_66 -> V_72 = F_57 () ;
V_66 -> V_73 = F_58 () ;
V_66 -> V_74 = V_66 -> V_75 = V_66 -> V_76 = V_77 ;
V_66 -> V_78 -> V_79 = & V_80 ;
}
return V_66 ;
}
static int F_59 ( struct V_2 * V_3 )
{
struct V_81 * V_82 ;
int V_83 = 0 ;
F_60 (cgrp->root, ss)
if ( V_82 -> V_84 ) {
V_83 = V_82 -> V_84 ( V_82 , V_3 ) ;
if ( V_83 )
break;
}
return V_83 ;
}
static void F_61 ( struct V_85 * V_85 , struct V_66 * V_66 )
{
if ( F_62 ( V_66 -> V_71 ) ) {
struct V_2 * V_3 = V_85 -> V_86 ;
struct V_81 * V_82 ;
F_28 ( ! ( F_4 ( V_3 ) ) ) ;
F_63 () ;
F_51 ( & V_1 ) ;
F_60 (cgrp->root, ss)
V_82 -> V_87 ( V_82 , V_3 ) ;
V_3 -> V_46 -> V_88 -- ;
F_53 ( & V_1 ) ;
F_64 ( V_3 -> V_46 -> V_69 ) ;
F_28 ( ! F_38 ( & V_3 -> V_89 ) ) ;
F_22 ( V_3 , V_32 ) ;
}
F_65 ( V_66 ) ;
}
static int F_66 ( const struct V_85 * V_90 )
{
return 1 ;
}
static void F_67 ( struct V_85 * V_90 )
{
struct V_85 * V_91 = F_68 ( V_90 -> V_92 ) ;
F_69 ( V_90 ) ;
F_70 ( V_91 -> V_93 , V_90 ) ;
F_71 ( V_91 ) ;
}
static void F_72 ( struct V_85 * V_85 )
{
struct V_36 * V_51 ;
F_28 ( ! F_3 ( & V_85 -> V_93 -> V_94 ) ) ;
F_73 ( & V_85 -> V_95 ) ;
V_51 = V_85 -> V_96 . V_45 ;
while ( V_51 != & V_85 -> V_96 ) {
struct V_85 * V_90 = F_29 ( V_51 , struct V_85 , V_97 . V_98 ) ;
F_74 ( & V_90 -> V_95 , V_99 ) ;
F_75 ( V_51 ) ;
if ( V_90 -> V_93 ) {
F_28 ( V_90 -> V_93 -> V_71 & V_100 ) ;
F_76 ( V_90 ) ;
F_77 ( & V_90 -> V_95 ) ;
F_77 ( & V_85 -> V_95 ) ;
F_69 ( V_90 ) ;
F_78 ( V_85 -> V_93 , V_90 ) ;
F_71 ( V_90 ) ;
F_73 ( & V_85 -> V_95 ) ;
} else
F_77 ( & V_90 -> V_95 ) ;
V_51 = V_85 -> V_96 . V_45 ;
}
F_77 ( & V_85 -> V_95 ) ;
}
static void F_79 ( struct V_85 * V_85 )
{
struct V_85 * V_91 ;
F_72 ( V_85 ) ;
V_91 = V_85 -> V_92 ;
F_73 ( & V_91 -> V_95 ) ;
F_74 ( & V_85 -> V_95 , V_99 ) ;
F_75 ( & V_85 -> V_97 . V_98 ) ;
F_77 ( & V_85 -> V_95 ) ;
F_77 ( & V_91 -> V_95 ) ;
F_67 ( V_85 ) ;
}
static void F_80 ( struct V_2 * V_3 )
{
if ( F_81 ( F_82 ( V_101 , & V_3 -> V_5 ) ) )
F_83 ( & V_102 ) ;
}
void F_84 ( struct V_11 * V_12 )
{
F_85 ( V_12 ) ;
}
void F_86 ( struct V_11 * V_12 )
{
F_80 ( V_12 -> V_2 ) ;
F_87 ( V_12 ) ;
}
static int F_88 ( struct V_48 * V_46 ,
unsigned long V_103 )
{
unsigned long V_104 , V_105 ;
struct V_2 * V_3 = & V_46 -> V_65 ;
int V_13 ;
F_28 ( ! F_3 ( & V_1 ) ) ;
V_105 = V_46 -> V_106 & ~ V_103 ;
V_104 = V_103 & ~ V_46 -> V_106 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
unsigned long V_107 = 1UL << V_13 ;
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( ! ( V_107 & V_104 ) )
continue;
F_28 ( V_82 == NULL ) ;
if ( V_82 -> V_46 != & V_108 ) {
return - V_109 ;
}
}
if ( V_46 -> V_88 > 1 )
return - V_109 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
unsigned long V_107 = 1UL << V_13 ;
if ( V_107 & V_104 ) {
F_28 ( V_82 == NULL ) ;
F_28 ( V_3 -> V_39 [ V_13 ] ) ;
F_28 ( ! V_110 -> V_39 [ V_13 ] ) ;
F_28 ( V_110 -> V_39 [ V_13 ] -> V_2 != V_110 ) ;
F_51 ( & V_82 -> V_111 ) ;
V_3 -> V_39 [ V_13 ] = V_110 -> V_39 [ V_13 ] ;
V_3 -> V_39 [ V_13 ] -> V_2 = V_3 ;
F_40 ( & V_82 -> V_112 , & V_46 -> V_113 ) ;
V_82 -> V_46 = V_46 ;
if ( V_82 -> V_114 )
V_82 -> V_114 ( V_82 , V_3 ) ;
F_53 ( & V_82 -> V_111 ) ;
} else if ( V_107 & V_105 ) {
F_28 ( V_82 == NULL ) ;
F_28 ( V_3 -> V_39 [ V_13 ] != V_110 -> V_39 [ V_13 ] ) ;
F_28 ( V_3 -> V_39 [ V_13 ] -> V_2 != V_3 ) ;
F_51 ( & V_82 -> V_111 ) ;
if ( V_82 -> V_114 )
V_82 -> V_114 ( V_82 , V_110 ) ;
V_110 -> V_39 [ V_13 ] -> V_2 = V_110 ;
V_3 -> V_39 [ V_13 ] = NULL ;
V_39 [ V_13 ] -> V_46 = & V_108 ;
F_40 ( & V_82 -> V_112 , & V_108 . V_113 ) ;
F_53 ( & V_82 -> V_111 ) ;
F_89 ( V_82 -> V_115 ) ;
} else if ( V_107 & V_103 ) {
F_28 ( V_82 == NULL ) ;
F_28 ( ! V_3 -> V_39 [ V_13 ] ) ;
F_89 ( V_82 -> V_115 ) ;
#ifdef F_90
F_28 ( V_82 -> V_115 && ! F_91 ( V_82 -> V_115 ) ) ;
#endif
} else {
F_28 ( V_3 -> V_39 [ V_13 ] ) ;
}
}
V_46 -> V_52 = V_46 -> V_106 = V_103 ;
F_63 () ;
return 0 ;
}
static int F_92 ( struct V_116 * V_117 , struct V_118 * V_119 )
{
struct V_48 * V_46 = V_119 -> V_120 -> V_121 ;
struct V_81 * V_82 ;
F_51 ( & V_1 ) ;
F_60 (root, ss)
F_93 ( V_117 , L_1 , V_82 -> V_122 ) ;
if ( F_5 ( V_123 , & V_46 -> V_5 ) )
F_94 ( V_117 , L_2 ) ;
if ( strlen ( V_46 -> V_124 ) )
F_93 ( V_117 , L_3 , V_46 -> V_124 ) ;
if ( F_8 ( & V_46 -> V_65 ) )
F_94 ( V_117 , L_4 ) ;
if ( strlen ( V_46 -> V_122 ) )
F_93 ( V_117 , L_5 , V_46 -> V_122 ) ;
F_53 ( & V_1 ) ;
return 0 ;
}
static int F_95 ( char * V_125 , struct V_126 * V_127 )
{
char * V_128 , * V_129 = V_125 ;
bool V_130 = false , V_131 = false ;
unsigned long V_132 = ( unsigned long ) - 1 ;
int V_13 ;
bool V_133 = false ;
F_28 ( ! F_3 ( & V_1 ) ) ;
#ifdef F_96
V_132 = ~ ( 1UL << V_134 ) ;
#endif
memset ( V_127 , 0 , sizeof( * V_127 ) ) ;
while ( ( V_128 = F_97 ( & V_129 , L_6 ) ) != NULL ) {
if ( ! * V_128 )
return - V_135 ;
if ( ! strcmp ( V_128 , L_7 ) ) {
V_127 -> V_136 = true ;
continue;
}
if ( ! strcmp ( V_128 , L_8 ) ) {
if ( V_131 )
return - V_135 ;
V_130 = true ;
continue;
}
if ( ! strcmp ( V_128 , L_9 ) ) {
F_19 ( V_123 , & V_127 -> V_5 ) ;
continue;
}
if ( ! strcmp ( V_128 , L_10 ) ) {
V_127 -> F_8 = true ;
continue;
}
if ( ! strncmp ( V_128 , L_11 , 14 ) ) {
if ( V_127 -> V_137 )
return - V_135 ;
V_127 -> V_137 =
F_98 ( V_128 + 14 , V_138 - 1 , V_53 ) ;
if ( ! V_127 -> V_137 )
return - V_54 ;
continue;
}
if ( ! strncmp ( V_128 , L_12 , 5 ) ) {
const char * V_122 = V_128 + 5 ;
if ( ! strlen ( V_122 ) )
return - V_135 ;
for ( V_13 = 0 ; V_13 < strlen ( V_122 ) ; V_13 ++ ) {
char V_60 = V_122 [ V_13 ] ;
if ( isalnum ( V_60 ) )
continue;
if ( ( V_60 == '.' ) || ( V_60 == '-' ) || ( V_60 == '_' ) )
continue;
return - V_135 ;
}
if ( V_127 -> V_122 )
return - V_135 ;
V_127 -> V_122 = F_98 ( V_122 ,
V_139 - 1 ,
V_53 ) ;
if ( ! V_127 -> V_122 )
return - V_54 ;
continue;
}
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
if ( strcmp ( V_128 , V_82 -> V_122 ) )
continue;
if ( V_82 -> V_140 )
continue;
if ( V_130 )
return - V_135 ;
F_19 ( V_13 , & V_127 -> V_52 ) ;
V_131 = true ;
break;
}
if ( V_13 == V_16 )
return - V_141 ;
}
if ( V_130 || ( ! V_130 && ! V_131 && ! V_127 -> V_136 ) ) {
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
if ( V_82 -> V_140 )
continue;
F_19 ( V_13 , & V_127 -> V_52 ) ;
}
}
if ( F_5 ( V_123 , & V_127 -> V_5 ) &&
( V_127 -> V_52 & V_132 ) )
return - V_135 ;
if ( V_127 -> V_52 && V_127 -> V_136 )
return - V_135 ;
if ( ! V_127 -> V_52 && ! V_127 -> V_122 )
return - V_135 ;
for ( V_13 = V_142 ; V_13 < V_16 ; V_13 ++ ) {
unsigned long V_107 = 1UL << V_13 ;
if ( ! ( V_107 & V_127 -> V_52 ) )
continue;
if ( ! F_99 ( V_39 [ V_13 ] -> V_115 ) ) {
V_133 = true ;
break;
}
}
if ( V_133 ) {
for ( V_13 -- ; V_13 >= V_142 ; V_13 -- ) {
unsigned long V_107 = 1UL << V_13 ;
if ( ! ( V_107 & V_127 -> V_52 ) )
continue;
F_89 ( V_39 [ V_13 ] -> V_115 ) ;
}
return - V_141 ;
}
return 0 ;
}
static void F_100 ( unsigned long V_52 )
{
int V_13 ;
for ( V_13 = V_142 ; V_13 < V_16 ; V_13 ++ ) {
unsigned long V_107 = 1UL << V_13 ;
if ( ! ( V_107 & V_52 ) )
continue;
F_89 ( V_39 [ V_13 ] -> V_115 ) ;
}
}
static int F_101 ( struct V_68 * V_69 , int * V_5 , char * V_125 )
{
int V_83 = 0 ;
struct V_48 * V_46 = V_69 -> V_121 ;
struct V_2 * V_3 = & V_46 -> V_65 ;
struct V_126 V_127 ;
F_51 ( & V_3 -> V_85 -> V_93 -> V_94 ) ;
F_51 ( & V_1 ) ;
V_83 = F_95 ( V_125 , & V_127 ) ;
if ( V_83 )
goto V_143;
if ( V_127 . V_5 != V_46 -> V_5 ||
( V_127 . V_122 && strcmp ( V_127 . V_122 , V_46 -> V_122 ) ) ) {
V_83 = - V_135 ;
F_100 ( V_127 . V_52 ) ;
goto V_143;
}
V_83 = F_88 ( V_46 , V_127 . V_52 ) ;
if ( V_83 ) {
F_100 ( V_127 . V_52 ) ;
goto V_143;
}
F_102 ( V_3 ) ;
if ( V_127 . V_137 )
strcpy ( V_46 -> V_124 , V_127 . V_137 ) ;
V_143:
F_21 ( V_127 . V_137 ) ;
F_21 ( V_127 . V_122 ) ;
F_53 ( & V_1 ) ;
F_53 ( & V_3 -> V_85 -> V_93 -> V_94 ) ;
return V_83 ;
}
static void F_103 ( struct V_2 * V_3 )
{
F_34 ( & V_3 -> V_112 ) ;
F_34 ( & V_3 -> V_144 ) ;
F_34 ( & V_3 -> V_56 ) ;
F_34 ( & V_3 -> V_145 ) ;
F_34 ( & V_3 -> V_89 ) ;
F_104 ( & V_3 -> V_146 ) ;
F_34 ( & V_3 -> V_147 ) ;
F_105 ( & V_3 -> V_148 ) ;
}
static void F_106 ( struct V_48 * V_46 )
{
struct V_2 * V_3 = & V_46 -> V_65 ;
F_34 ( & V_46 -> V_113 ) ;
F_34 ( & V_46 -> V_149 ) ;
V_46 -> V_88 = 1 ;
V_3 -> V_46 = V_46 ;
V_3 -> V_65 = V_3 ;
F_103 ( V_3 ) ;
}
static bool F_107 ( struct V_48 * V_46 )
{
int V_83 = 0 ;
do {
if ( ! F_108 ( & V_150 , V_53 ) )
return false ;
F_73 ( & V_151 ) ;
V_83 = F_109 ( & V_150 , V_152 ,
& V_46 -> V_153 ) ;
if ( V_83 == - V_154 )
V_83 = F_110 ( & V_150 , & V_46 -> V_153 ) ;
if ( ! V_83 ) {
V_152 = V_46 -> V_153 + 1 ;
} else if ( V_83 != - V_155 ) {
F_28 ( V_83 ) ;
}
F_77 ( & V_151 ) ;
} while ( V_83 );
return true ;
}
static int F_111 ( struct V_68 * V_69 , void * V_125 )
{
struct V_126 * V_127 = V_125 ;
struct V_48 * V_46 = V_69 -> V_121 ;
if ( V_127 -> V_122 && strcmp ( V_127 -> V_122 , V_46 -> V_122 ) )
return 0 ;
if ( ( V_127 -> V_52 || V_127 -> V_136 )
&& ( V_127 -> V_52 != V_46 -> V_52 ) )
return 0 ;
return 1 ;
}
static struct V_48 * F_112 ( struct V_126 * V_127 )
{
struct V_48 * V_46 ;
if ( ! V_127 -> V_52 && ! V_127 -> V_136 )
return NULL ;
V_46 = F_113 ( sizeof( * V_46 ) , V_53 ) ;
if ( ! V_46 )
return F_114 ( - V_54 ) ;
if ( ! F_107 ( V_46 ) ) {
F_21 ( V_46 ) ;
return F_114 ( - V_54 ) ;
}
F_106 ( V_46 ) ;
V_46 -> V_52 = V_127 -> V_52 ;
V_46 -> V_5 = V_127 -> V_5 ;
if ( V_127 -> V_137 )
strcpy ( V_46 -> V_124 , V_127 -> V_137 ) ;
if ( V_127 -> V_122 )
strcpy ( V_46 -> V_122 , V_127 -> V_122 ) ;
if ( V_127 -> F_8 )
F_19 ( V_9 , & V_46 -> V_65 . V_5 ) ;
return V_46 ;
}
static void F_115 ( struct V_48 * V_46 )
{
if ( ! V_46 )
return;
F_28 ( ! V_46 -> V_153 ) ;
F_73 ( & V_151 ) ;
F_116 ( & V_150 , V_46 -> V_153 ) ;
F_77 ( & V_151 ) ;
F_21 ( V_46 ) ;
}
static int F_117 ( struct V_68 * V_69 , void * V_125 )
{
int V_83 ;
struct V_126 * V_127 = V_125 ;
if ( ! V_127 -> V_156 )
return - V_135 ;
F_28 ( ! V_127 -> V_52 && ! V_127 -> V_136 ) ;
V_83 = F_118 ( V_69 , NULL ) ;
if ( V_83 )
return V_83 ;
V_69 -> V_121 = V_127 -> V_156 ;
V_127 -> V_156 -> V_69 = V_69 ;
V_69 -> V_157 = V_158 ;
V_69 -> V_159 = V_160 ;
V_69 -> V_161 = V_162 ;
V_69 -> V_163 = & V_164 ;
return 0 ;
}
static int F_119 ( struct V_68 * V_69 )
{
static const struct V_165 V_166 = {
. V_167 = F_61 ,
. F_69 = F_66 ,
} ;
struct V_66 * V_66 =
F_54 ( V_100 | V_168 | V_169 | V_170 , V_69 ) ;
struct V_85 * V_85 ;
if ( ! V_66 )
return - V_54 ;
V_66 -> V_171 = & V_172 ;
V_66 -> V_173 = & V_174 ;
F_120 ( V_66 ) ;
V_85 = F_121 ( V_66 ) ;
if ( ! V_85 ) {
F_65 ( V_66 ) ;
return - V_54 ;
}
V_69 -> V_175 = V_85 ;
V_69 -> V_176 = & V_166 ;
return 0 ;
}
static struct V_85 * F_122 ( struct V_177 * V_178 ,
int V_5 , const char * V_179 ,
void * V_125 )
{
struct V_126 V_127 ;
struct V_48 * V_46 ;
int V_83 = 0 ;
struct V_68 * V_69 ;
struct V_48 * V_156 ;
F_51 ( & V_1 ) ;
V_83 = F_95 ( V_125 , & V_127 ) ;
F_53 ( & V_1 ) ;
if ( V_83 )
goto V_180;
V_156 = F_112 ( & V_127 ) ;
if ( F_123 ( V_156 ) ) {
V_83 = F_124 ( V_156 ) ;
goto V_181;
}
V_127 . V_156 = V_156 ;
V_69 = F_125 ( V_178 , F_111 , F_117 , & V_127 ) ;
if ( F_123 ( V_69 ) ) {
V_83 = F_124 ( V_69 ) ;
F_115 ( V_127 . V_156 ) ;
goto V_181;
}
V_46 = V_69 -> V_121 ;
F_28 ( ! V_46 ) ;
if ( V_46 == V_127 . V_156 ) {
struct V_36 V_55 ;
struct V_2 * V_182 = & V_46 -> V_65 ;
struct V_66 * V_66 ;
struct V_48 * V_183 ;
int V_13 ;
F_28 ( V_69 -> V_175 != NULL ) ;
V_83 = F_119 ( V_69 ) ;
if ( V_83 )
goto V_184;
V_66 = V_69 -> V_175 -> V_93 ;
F_51 ( & V_66 -> V_94 ) ;
F_51 ( & V_1 ) ;
if ( strlen ( V_46 -> V_122 ) ) {
F_126 (existing_root) {
if ( ! strcmp ( V_183 -> V_122 , V_46 -> V_122 ) ) {
V_83 = - V_109 ;
F_53 ( & V_1 ) ;
F_53 ( & V_66 -> V_94 ) ;
goto V_184;
}
}
}
V_83 = F_33 ( V_28 , & V_55 ) ;
if ( V_83 ) {
F_53 ( & V_1 ) ;
F_53 ( & V_66 -> V_94 ) ;
goto V_184;
}
V_83 = F_88 ( V_46 , V_46 -> V_52 ) ;
if ( V_83 == - V_109 ) {
F_53 ( & V_1 ) ;
F_53 ( & V_66 -> V_94 ) ;
F_32 ( & V_55 ) ;
goto V_184;
}
F_28 ( V_83 ) ;
F_36 ( & V_46 -> V_149 , & V_185 ) ;
V_58 ++ ;
V_69 -> V_175 -> V_86 = V_182 ;
V_46 -> V_65 . V_85 = V_69 -> V_175 ;
F_13 ( & V_26 ) ;
for ( V_13 = 0 ; V_13 < V_186 ; V_13 ++ ) {
struct V_10 * V_49 = & V_18 [ V_13 ] ;
struct V_50 * V_51 ;
struct V_19 * V_20 ;
F_31 (cg, node, hhead, hlist)
F_37 ( & V_55 , V_20 , V_182 ) ;
}
F_15 ( & V_26 ) ;
F_32 ( & V_55 ) ;
F_28 ( ! F_38 ( & V_182 -> V_112 ) ) ;
F_28 ( ! F_38 ( & V_182 -> V_144 ) ) ;
F_28 ( V_46 -> V_88 != 1 ) ;
F_102 ( V_182 ) ;
F_53 ( & V_1 ) ;
F_53 ( & V_66 -> V_94 ) ;
} else {
F_115 ( V_127 . V_156 ) ;
F_100 ( V_127 . V_52 ) ;
}
F_21 ( V_127 . V_137 ) ;
F_21 ( V_127 . V_122 ) ;
return F_68 ( V_69 -> V_175 ) ;
V_184:
F_127 ( V_69 ) ;
V_181:
F_100 ( V_127 . V_52 ) ;
V_180:
F_21 ( V_127 . V_137 ) ;
F_21 ( V_127 . V_122 ) ;
return F_114 ( V_83 ) ;
}
static void F_128 ( struct V_68 * V_69 ) {
struct V_48 * V_46 = V_69 -> V_121 ;
struct V_2 * V_3 = & V_46 -> V_65 ;
int V_83 ;
struct V_22 * V_23 ;
struct V_22 * V_24 ;
F_28 ( ! V_46 ) ;
F_28 ( V_46 -> V_88 != 1 ) ;
F_28 ( ! F_38 ( & V_3 -> V_144 ) ) ;
F_28 ( ! F_38 ( & V_3 -> V_112 ) ) ;
F_51 ( & V_1 ) ;
V_83 = F_88 ( V_46 , 0 ) ;
F_28 ( V_83 ) ;
F_13 ( & V_26 ) ;
F_17 (link, saved_link, &cgrp->css_sets,
cgrp_link_list) {
F_18 ( & V_23 -> V_29 ) ;
F_18 ( & V_23 -> V_30 ) ;
F_21 ( V_23 ) ;
}
F_15 ( & V_26 ) ;
if ( ! F_38 ( & V_46 -> V_149 ) ) {
F_18 ( & V_46 -> V_149 ) ;
V_58 -- ;
}
F_53 ( & V_1 ) ;
F_129 ( V_69 ) ;
F_115 ( V_46 ) ;
}
static inline struct V_2 * F_130 ( struct V_85 * V_85 )
{
return V_85 -> V_86 ;
}
static inline struct V_187 * F_131 ( struct V_85 * V_85 )
{
return V_85 -> V_86 ;
}
int F_132 ( const struct V_2 * V_3 , char * V_188 , int V_189 )
{
char * V_190 ;
struct V_85 * V_85 = F_133 ( V_3 -> V_85 ,
F_134 () ||
F_1 () ) ;
if ( ! V_85 || V_3 == V_110 ) {
strcpy ( V_188 , L_13 ) ;
return 0 ;
}
V_190 = V_188 + V_189 ;
* -- V_190 = '\0' ;
for (; ; ) {
int V_191 = V_85 -> V_192 . V_191 ;
if ( ( V_190 -= V_191 ) < V_188 )
return - V_193 ;
memcpy ( V_190 , V_85 -> V_192 . V_122 , V_191 ) ;
V_3 = V_3 -> V_91 ;
if ( ! V_3 )
break;
V_85 = F_133 ( V_3 -> V_85 ,
F_134 () ||
F_1 () ) ;
if ( ! V_3 -> V_91 )
continue;
if ( -- V_190 < V_188 )
return - V_193 ;
* V_190 = '/' ;
}
memmove ( V_188 , V_190 , V_188 + V_189 - V_190 ) ;
return 0 ;
}
static int F_135 ( struct V_2 * V_3 , struct V_2 * V_194 ,
struct V_61 * V_195 , bool V_196 )
{
struct V_19 * V_47 ;
struct V_19 * V_197 ;
F_136 ( V_195 ) ;
V_47 = V_195 -> V_63 ;
F_23 ( V_47 ) ;
F_137 ( V_195 ) ;
if ( V_196 ) {
struct V_11 * V_35 [ V_16 ] ;
F_43 ( & V_26 ) ;
V_197 = F_30 ( V_47 , V_3 , V_35 ) ;
F_28 ( ! V_197 ) ;
F_23 ( V_197 ) ;
F_44 ( & V_26 ) ;
} else {
F_138 () ;
V_197 = F_42 ( V_47 , V_3 ) ;
if ( ! V_197 ) {
F_25 ( V_47 ) ;
return - V_54 ;
}
}
F_25 ( V_47 ) ;
F_136 ( V_195 ) ;
if ( V_195 -> V_5 & V_198 ) {
F_137 ( V_195 ) ;
F_25 ( V_197 ) ;
return - V_199 ;
}
F_139 ( V_195 -> V_63 , V_197 ) ;
F_137 ( V_195 ) ;
F_13 ( & V_26 ) ;
if ( ! F_38 ( & V_195 -> V_200 ) )
F_40 ( & V_195 -> V_200 , & V_197 -> V_59 ) ;
F_15 ( & V_26 ) ;
F_25 ( V_47 ) ;
F_19 ( V_7 , & V_194 -> V_5 ) ;
return 0 ;
}
int F_140 ( struct V_2 * V_3 , struct V_61 * V_195 )
{
int V_201 ;
struct V_81 * V_82 , * V_202 = NULL ;
struct V_2 * V_194 ;
struct V_48 * V_46 = V_3 -> V_46 ;
V_194 = F_49 ( V_195 , V_46 ) ;
if ( V_3 == V_194 )
return 0 ;
F_60 (root, ss) {
if ( V_82 -> V_203 ) {
V_201 = V_82 -> V_203 ( V_82 , V_3 , V_195 ) ;
if ( V_201 ) {
V_202 = V_82 ;
goto V_204;
}
}
if ( V_82 -> V_205 ) {
V_201 = V_82 -> V_205 ( V_3 , V_195 ) ;
if ( V_201 ) {
V_202 = V_82 ;
goto V_204;
}
}
}
V_201 = F_135 ( V_3 , V_194 , V_195 , false ) ;
if ( V_201 )
goto V_204;
F_60 (root, ss) {
if ( V_82 -> V_206 )
V_82 -> V_206 ( V_3 ) ;
if ( V_82 -> V_207 )
V_82 -> V_207 ( V_3 , V_195 ) ;
if ( V_82 -> V_208 )
V_82 -> V_208 ( V_82 , V_3 , V_194 , V_195 ) ;
}
F_63 () ;
F_80 ( V_3 ) ;
V_204:
if ( V_201 ) {
F_60 (root, ss) {
if ( V_82 == V_202 )
break;
if ( V_82 -> V_209 )
V_82 -> V_209 ( V_82 , V_3 , V_195 ) ;
}
}
return V_201 ;
}
int F_141 ( struct V_61 * V_210 , struct V_61 * V_195 )
{
struct V_48 * V_46 ;
int V_201 = 0 ;
F_50 () ;
F_126 (root) {
struct V_2 * V_211 = F_49 ( V_210 , V_46 ) ;
V_201 = F_140 ( V_211 , V_195 ) ;
if ( V_201 )
break;
}
F_52 () ;
return V_201 ;
}
static bool F_142 ( struct V_2 * V_3 ,
struct V_61 * V_195 , struct V_19 * V_20 ,
struct V_36 * V_212 )
{
struct V_19 * V_197 ;
struct V_213 * V_214 ;
struct V_11 * V_35 [ V_16 ] ;
F_43 ( & V_26 ) ;
V_197 = F_30 ( V_20 , V_3 , V_35 ) ;
if ( V_197 )
F_23 ( V_197 ) ;
F_44 ( & V_26 ) ;
if ( ! V_197 )
return false ;
F_47 (cg_entry, newcg_list, links) {
if ( V_214 -> V_20 == V_197 ) {
F_25 ( V_197 ) ;
return true ;
}
}
F_25 ( V_197 ) ;
return false ;
}
static int F_143 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_36 * V_212 )
{
struct V_19 * V_197 ;
struct V_213 * V_214 ;
V_197 = F_42 ( V_20 , V_3 ) ;
if ( ! V_197 )
return - V_54 ;
V_214 = F_35 ( sizeof( struct V_213 ) , V_53 ) ;
if ( ! V_214 ) {
F_25 ( V_197 ) ;
return - V_54 ;
}
V_214 -> V_20 = V_197 ;
F_36 ( & V_214 -> V_215 , V_212 ) ;
return 0 ;
}
int F_144 ( struct V_2 * V_3 , struct V_61 * V_216 )
{
int V_201 , V_13 , V_217 ;
struct V_81 * V_82 , * V_202 = NULL ;
bool V_218 = false ;
struct V_2 * V_194 = NULL ;
struct V_19 * V_47 ;
struct V_48 * V_46 = V_3 -> V_46 ;
struct V_61 * V_195 ;
struct V_219 * V_220 ;
struct V_36 V_212 ;
struct V_213 * V_214 , * V_221 ;
V_217 = F_145 ( V_216 ) ;
V_220 = F_146 ( sizeof( struct V_61 * ) , V_217 ,
V_53 ) ;
if ( ! V_220 )
return - V_54 ;
V_201 = F_147 ( V_220 , 0 , V_217 - 1 , V_53 ) ;
if ( V_201 )
goto V_222;
F_148 () ;
if ( ! F_149 ( V_216 ) ) {
F_150 () ;
V_201 = - V_155 ;
goto V_222;
}
V_195 = V_216 ;
V_13 = 0 ;
do {
F_28 ( V_13 >= V_217 ) ;
F_151 ( V_195 ) ;
V_201 = F_152 ( V_220 , V_13 , V_195 , V_223 ) ;
F_28 ( V_201 != 0 ) ;
V_13 ++ ;
} while_each_thread(leader, tsk) ;
int F_153 ( struct V_2 * V_3 , T_2 V_224 , bool V_225 )
{
struct V_61 * V_195 ;
const struct V_226 * V_226 = F_154 () , * V_227 ;
int V_83 ;
if ( ! F_155 ( V_3 ) )
return - V_228 ;
if ( V_224 ) {
F_148 () ;
V_195 = F_156 ( V_224 ) ;
if ( ! V_195 ) {
F_150 () ;
F_52 () ;
return - V_199 ;
}
if ( V_225 ) {
V_195 = V_195 -> V_229 ;
} else if ( V_195 -> V_5 & V_198 ) {
F_150 () ;
F_52 () ;
return - V_199 ;
}
V_227 = F_157 ( V_195 ) ;
if ( V_226 -> V_230 &&
V_226 -> V_230 != V_227 -> V_231 &&
V_226 -> V_230 != V_227 -> V_232 ) {
F_150 () ;
F_52 () ;
return - V_233 ;
}
F_151 ( V_195 ) ;
F_150 () ;
} else {
if ( V_225 )
V_195 = V_234 -> V_229 ;
else
V_195 = V_234 ;
F_151 ( V_195 ) ;
}
if ( V_225 ) {
F_158 ( V_195 ) ;
V_83 = F_144 ( V_3 , V_195 ) ;
F_159 ( V_195 ) ;
} else {
V_83 = F_140 ( V_3 , V_195 ) ;
}
F_160 ( V_195 ) ;
F_52 () ;
return V_83 ;
}
static int F_161 ( struct V_2 * V_3 , struct V_187 * V_235 , T_2 V_224 )
{
return F_153 ( V_3 , V_224 , false ) ;
}
static int F_162 ( struct V_2 * V_3 , struct V_187 * V_235 , T_2 V_236 )
{
int V_83 ;
do {
V_83 = F_153 ( V_3 , V_236 , true ) ;
} while ( V_83 == - V_155 );
return V_83 ;
}
bool F_155 ( struct V_2 * V_3 )
{
F_51 ( & V_1 ) ;
if ( F_4 ( V_3 ) ) {
F_53 ( & V_1 ) ;
return false ;
}
return true ;
}
static int F_163 ( struct V_2 * V_3 , struct V_187 * V_235 ,
const char * V_237 )
{
F_164 ( sizeof( V_3 -> V_46 -> V_124 ) < V_138 ) ;
if ( strlen ( V_237 ) >= V_138 )
return - V_135 ;
if ( ! F_155 ( V_3 ) )
return - V_228 ;
strcpy ( V_3 -> V_46 -> V_124 , V_237 ) ;
F_52 () ;
return 0 ;
}
static int F_165 ( struct V_2 * V_3 , struct V_187 * V_235 ,
struct V_116 * V_117 )
{
if ( ! F_155 ( V_3 ) )
return - V_228 ;
F_94 ( V_117 , V_3 -> V_46 -> V_124 ) ;
F_166 ( V_117 , '\n' ) ;
F_52 () ;
return 0 ;
}
static T_3 F_167 ( struct V_2 * V_3 , struct V_187 * V_235 ,
struct V_238 * V_238 ,
const char T_4 * V_239 ,
T_5 V_240 , T_6 * V_241 )
{
char V_237 [ V_242 ] ;
int V_201 = 0 ;
char * V_243 ;
if ( ! V_240 )
return - V_135 ;
if ( V_240 >= sizeof( V_237 ) )
return - V_244 ;
if ( F_168 ( V_237 , V_239 , V_240 ) )
return - V_245 ;
V_237 [ V_240 ] = 0 ;
if ( V_235 -> V_246 ) {
T_2 V_247 = F_169 ( F_170 ( V_237 ) , & V_243 , 0 ) ;
if ( * V_243 )
return - V_135 ;
V_201 = V_235 -> V_246 ( V_3 , V_235 , V_247 ) ;
} else {
T_7 V_247 = F_171 ( F_170 ( V_237 ) , & V_243 , 0 ) ;
if ( * V_243 )
return - V_135 ;
V_201 = V_235 -> V_248 ( V_3 , V_235 , V_247 ) ;
}
if ( ! V_201 )
V_201 = V_240 ;
return V_201 ;
}
static T_3 F_172 ( struct V_2 * V_3 , struct V_187 * V_235 ,
struct V_238 * V_238 ,
const char T_4 * V_239 ,
T_5 V_240 , T_6 * V_241 )
{
char V_249 [ V_242 ] ;
int V_201 = 0 ;
T_5 V_250 = V_235 -> V_251 ;
char * V_237 = V_249 ;
if ( ! V_250 )
V_250 = sizeof( V_249 ) - 1 ;
if ( V_240 >= V_250 )
return - V_244 ;
if ( V_240 >= sizeof( V_249 ) ) {
V_237 = F_35 ( V_240 + 1 , V_53 ) ;
if ( V_237 == NULL )
return - V_54 ;
}
if ( V_240 && F_168 ( V_237 , V_239 , V_240 ) ) {
V_201 = - V_245 ;
goto V_204;
}
V_237 [ V_240 ] = 0 ;
V_201 = V_235 -> V_252 ( V_3 , V_235 , F_170 ( V_237 ) ) ;
if ( ! V_201 )
V_201 = V_240 ;
V_204:
if ( V_237 != V_249 )
F_21 ( V_237 ) ;
return V_201 ;
}
static T_3 F_173 ( struct V_238 * V_238 , const char T_4 * V_188 ,
T_5 V_240 , T_6 * V_253 )
{
struct V_187 * V_235 = F_131 ( V_238 -> V_254 ) ;
struct V_2 * V_3 = F_130 ( V_238 -> V_254 -> V_92 ) ;
if ( F_4 ( V_3 ) )
return - V_228 ;
if ( V_235 -> V_255 )
return V_235 -> V_255 ( V_3 , V_235 , V_238 , V_188 , V_240 , V_253 ) ;
if ( V_235 -> V_246 || V_235 -> V_248 )
return F_167 ( V_3 , V_235 , V_238 , V_188 , V_240 , V_253 ) ;
if ( V_235 -> V_252 )
return F_172 ( V_3 , V_235 , V_238 , V_188 , V_240 , V_253 ) ;
if ( V_235 -> V_256 ) {
int V_83 = V_235 -> V_256 ( V_3 , ( unsigned int ) V_235 -> V_257 ) ;
return V_83 ? V_83 : V_240 ;
}
return - V_135 ;
}
static T_3 F_174 ( struct V_2 * V_3 , struct V_187 * V_235 ,
struct V_238 * V_238 ,
char T_4 * V_188 , T_5 V_240 ,
T_6 * V_253 )
{
char V_15 [ V_242 ] ;
T_2 V_247 = V_235 -> V_258 ( V_3 , V_235 ) ;
int V_191 = sprintf ( V_15 , L_14 , ( unsigned long long ) V_247 ) ;
return F_175 ( V_188 , V_240 , V_253 , V_15 , V_191 ) ;
}
static T_3 F_176 ( struct V_2 * V_3 , struct V_187 * V_235 ,
struct V_238 * V_238 ,
char T_4 * V_188 , T_5 V_240 ,
T_6 * V_253 )
{
char V_15 [ V_242 ] ;
T_7 V_247 = V_235 -> V_259 ( V_3 , V_235 ) ;
int V_191 = sprintf ( V_15 , L_15 , ( long long ) V_247 ) ;
return F_175 ( V_188 , V_240 , V_253 , V_15 , V_191 ) ;
}
static T_3 F_177 ( struct V_238 * V_238 , char T_4 * V_188 ,
T_5 V_240 , T_6 * V_253 )
{
struct V_187 * V_235 = F_131 ( V_238 -> V_254 ) ;
struct V_2 * V_3 = F_130 ( V_238 -> V_254 -> V_92 ) ;
if ( F_4 ( V_3 ) )
return - V_228 ;
if ( V_235 -> V_260 )
return V_235 -> V_260 ( V_3 , V_235 , V_238 , V_188 , V_240 , V_253 ) ;
if ( V_235 -> V_258 )
return F_174 ( V_3 , V_235 , V_238 , V_188 , V_240 , V_253 ) ;
if ( V_235 -> V_259 )
return F_176 ( V_3 , V_235 , V_238 , V_188 , V_240 , V_253 ) ;
return - V_135 ;
}
static int F_178 ( struct V_261 * V_262 , const char * V_263 , T_2 V_264 )
{
struct V_116 * V_265 = V_262 -> V_266 ;
return F_93 ( V_265 , L_16 , V_263 , ( unsigned long long ) V_264 ) ;
}
static int F_179 ( struct V_116 * V_267 , void * V_268 )
{
struct V_269 * V_266 = V_267 -> V_257 ;
struct V_187 * V_235 = V_266 -> V_235 ;
if ( V_235 -> V_270 ) {
struct V_261 V_262 = {
. V_271 = F_178 ,
. V_266 = V_267 ,
} ;
return V_235 -> V_270 ( V_266 -> V_2 , V_235 , & V_262 ) ;
}
return V_235 -> V_272 ( V_266 -> V_2 , V_235 , V_267 ) ;
}
static int F_180 ( struct V_66 * V_66 , struct V_238 * V_238 )
{
struct V_116 * V_117 = V_238 -> V_273 ;
F_21 ( V_117 -> V_257 ) ;
return F_181 ( V_66 , V_238 ) ;
}
static int F_182 ( struct V_66 * V_66 , struct V_238 * V_238 )
{
int V_274 ;
struct V_187 * V_235 ;
V_274 = F_183 ( V_66 , V_238 ) ;
if ( V_274 )
return V_274 ;
V_235 = F_131 ( V_238 -> V_254 ) ;
if ( V_235 -> V_270 || V_235 -> V_272 ) {
struct V_269 * V_266 =
F_113 ( sizeof( * V_266 ) , V_275 ) ;
if ( ! V_266 )
return - V_54 ;
V_266 -> V_235 = V_235 ;
V_266 -> V_2 = F_130 ( V_238 -> V_254 -> V_92 ) ;
V_238 -> V_276 = & V_277 ;
V_274 = F_184 ( V_238 , F_179 , V_266 ) ;
if ( V_274 < 0 )
F_21 ( V_266 ) ;
} else if ( V_235 -> V_278 )
V_274 = V_235 -> V_278 ( V_66 , V_238 ) ;
else
V_274 = 0 ;
return V_274 ;
}
static int F_185 ( struct V_66 * V_66 , struct V_238 * V_238 )
{
struct V_187 * V_235 = F_131 ( V_238 -> V_254 ) ;
if ( V_235 -> V_279 )
return V_235 -> V_279 ( V_66 , V_238 ) ;
return 0 ;
}
static int F_186 ( struct V_66 * V_280 , struct V_85 * V_281 ,
struct V_66 * V_282 , struct V_85 * V_283 )
{
if ( ! F_62 ( V_281 -> V_93 -> V_71 ) )
return - V_284 ;
if ( V_283 -> V_93 )
return - V_285 ;
if ( V_280 != V_282 )
return - V_286 ;
return F_187 ( V_280 , V_281 , V_282 , V_283 ) ;
}
static struct V_85 * F_188 ( struct V_66 * V_287 , struct V_85 * V_85 , struct V_288 * V_289 )
{
if ( V_85 -> V_192 . V_191 > V_290 )
return F_114 ( - V_193 ) ;
F_189 ( V_85 , NULL ) ;
return NULL ;
}
static inline struct V_187 * F_190 ( struct V_238 * V_238 )
{
if ( V_238 -> V_254 -> V_93 -> V_171 != & V_291 )
return F_114 ( - V_135 ) ;
return F_131 ( V_238 -> V_254 ) ;
}
static int F_191 ( struct V_85 * V_85 , T_1 V_67 ,
struct V_68 * V_69 )
{
struct V_66 * V_66 ;
if ( ! V_85 )
return - V_141 ;
if ( V_85 -> V_93 )
return - V_285 ;
V_66 = F_54 ( V_67 , V_69 ) ;
if ( ! V_66 )
return - V_54 ;
if ( F_62 ( V_67 ) ) {
V_66 -> V_173 = & V_174 ;
V_66 -> V_171 = & V_172 ;
F_120 ( V_66 ) ;
F_192 ( & V_66 -> V_94 , V_292 ) ;
} else if ( F_193 ( V_67 ) ) {
V_66 -> V_293 = 0 ;
V_66 -> V_171 = & V_291 ;
}
F_194 ( V_85 , V_66 ) ;
F_68 ( V_85 ) ;
return 0 ;
}
static int F_195 ( struct V_2 * V_3 , struct V_85 * V_85 ,
T_1 V_67 )
{
struct V_85 * V_91 ;
int error = 0 ;
V_91 = V_3 -> V_91 -> V_85 ;
error = F_191 ( V_85 , V_100 | V_67 , V_3 -> V_46 -> V_69 ) ;
if ( ! error ) {
V_85 -> V_86 = V_3 ;
F_120 ( V_91 -> V_93 ) ;
F_139 ( V_3 -> V_85 , V_85 ) ;
F_68 ( V_85 ) ;
}
F_71 ( V_85 ) ;
return error ;
}
static T_1 F_196 ( const struct V_187 * V_235 )
{
T_1 V_67 = 0 ;
if ( V_235 -> V_67 )
return V_235 -> V_67 ;
if ( V_235 -> V_260 || V_235 -> V_258 || V_235 -> V_259 ||
V_235 -> V_270 || V_235 -> V_272 )
V_67 |= V_168 ;
if ( V_235 -> V_255 || V_235 -> V_246 || V_235 -> V_248 ||
V_235 -> V_252 || V_235 -> V_256 )
V_67 |= V_170 ;
return V_67 ;
}
int F_197 ( struct V_2 * V_3 ,
struct V_81 * V_39 ,
const struct V_187 * V_235 )
{
struct V_85 * V_287 = V_3 -> V_85 ;
struct V_85 * V_85 ;
int error ;
T_1 V_67 ;
char V_122 [ V_294 + V_295 + 2 ] = { 0 } ;
if ( V_39 && ! F_5 ( V_123 , & V_3 -> V_46 -> V_5 ) ) {
strcpy ( V_122 , V_39 -> V_122 ) ;
strcat ( V_122 , L_17 ) ;
}
strcat ( V_122 , V_235 -> V_122 ) ;
F_28 ( ! F_3 ( & V_287 -> V_93 -> V_94 ) ) ;
V_85 = F_198 ( V_122 , V_287 , strlen ( V_122 ) ) ;
if ( ! F_123 ( V_85 ) ) {
V_67 = F_196 ( V_235 ) ;
error = F_191 ( V_85 , V_67 | V_296 ,
V_3 -> V_46 -> V_69 ) ;
if ( ! error )
V_85 -> V_86 = ( void * ) V_235 ;
F_71 ( V_85 ) ;
} else
error = F_124 ( V_85 ) ;
return error ;
}
int F_199 ( struct V_2 * V_3 ,
struct V_81 * V_39 ,
const struct V_187 V_235 [] ,
int V_31 )
{
int V_13 , V_274 ;
for ( V_13 = 0 ; V_13 < V_31 ; V_13 ++ ) {
V_274 = F_197 ( V_3 , V_39 , & V_235 [ V_13 ] ) ;
if ( V_274 )
return V_274 ;
}
return 0 ;
}
int F_200 ( const struct V_2 * V_3 )
{
int V_31 = 0 ;
struct V_22 * V_23 ;
F_43 ( & V_26 ) ;
F_47 (link, &cgrp->css_sets, cgrp_link_list) {
V_31 += F_201 ( & V_23 -> V_20 -> V_25 ) ;
}
F_44 ( & V_26 ) ;
return V_31 ;
}
static void F_202 ( struct V_2 * V_3 ,
struct V_297 * V_298 )
{
struct V_36 * V_299 = V_298 -> V_300 ;
struct V_22 * V_23 ;
struct V_19 * V_20 ;
do {
V_299 = V_299 -> V_45 ;
if ( V_299 == & V_3 -> V_56 ) {
V_298 -> V_300 = NULL ;
return;
}
V_23 = F_29 ( V_299 , struct V_22 , V_30 ) ;
V_20 = V_23 -> V_20 ;
} while ( F_38 ( & V_20 -> V_59 ) );
V_298 -> V_300 = V_299 ;
V_298 -> V_62 = V_20 -> V_59 . V_45 ;
}
static void F_203 ( void )
{
struct V_61 * V_301 , * V_302 ;
F_13 ( & V_26 ) ;
V_303 = 1 ;
F_204 (g, p) {
F_136 ( V_301 ) ;
if ( ! ( V_301 -> V_5 & V_198 ) && F_38 ( & V_301 -> V_200 ) )
F_36 ( & V_301 -> V_200 , & V_301 -> V_63 -> V_59 ) ;
F_137 ( V_301 ) ;
} F_205 ( V_302 , V_301 ) ;
F_15 ( & V_26 ) ;
}
void F_206 ( struct V_2 * V_3 , struct V_297 * V_298 )
{
if ( ! V_303 )
F_203 () ;
F_43 ( & V_26 ) ;
V_298 -> V_300 = & V_3 -> V_56 ;
F_202 ( V_3 , V_298 ) ;
}
struct V_61 * F_207 ( struct V_2 * V_3 ,
struct V_297 * V_298 )
{
struct V_61 * V_57 ;
struct V_36 * V_299 = V_298 -> V_62 ;
struct V_22 * V_23 ;
if ( ! V_298 -> V_300 )
return NULL ;
V_57 = F_29 ( V_299 , struct V_61 , V_200 ) ;
V_299 = V_299 -> V_45 ;
V_23 = F_29 ( V_298 -> V_300 , struct V_22 , V_30 ) ;
if ( V_299 == & V_23 -> V_20 -> V_59 ) {
F_202 ( V_3 , V_298 ) ;
} else {
V_298 -> V_62 = V_299 ;
}
return V_57 ;
}
void F_208 ( struct V_2 * V_3 , struct V_297 * V_298 )
{
F_44 ( & V_26 ) ;
}
static inline int F_209 ( struct V_61 * V_304 ,
struct V_305 * time ,
struct V_61 * V_306 )
{
int V_307 = F_210 ( & V_304 -> V_308 , time ) ;
if ( V_307 > 0 ) {
return 1 ;
} else if ( V_307 < 0 ) {
return 0 ;
} else {
return V_304 > V_306 ;
}
}
static inline int F_211 ( void * V_309 , void * V_310 )
{
struct V_61 * V_304 = V_309 ;
struct V_61 * V_306 = V_310 ;
return F_209 ( V_304 , & V_306 -> V_308 , V_306 ) ;
}
int F_212 ( struct V_311 * V_312 )
{
int V_201 , V_13 ;
struct V_297 V_298 ;
struct V_61 * V_301 , * V_313 ;
struct V_61 * V_314 = NULL ;
struct V_315 V_316 ;
struct V_315 * V_317 ;
struct V_305 V_318 = { 0 , 0 } ;
if ( V_312 -> V_317 ) {
V_317 = V_312 -> V_317 ;
V_317 -> V_319 = & F_211 ;
} else {
V_317 = & V_316 ;
V_201 = F_213 ( V_317 , V_320 , V_53 , & F_211 ) ;
if ( V_201 )
return V_201 ;
}
V_321:
V_317 -> V_322 = 0 ;
F_206 ( V_312 -> V_20 , & V_298 ) ;
while ( ( V_301 = F_207 ( V_312 -> V_20 , & V_298 ) ) ) {
if ( V_312 -> V_323 && ! V_312 -> V_323 ( V_301 , V_312 ) )
continue;
if ( ! F_209 ( V_301 , & V_318 , V_314 ) )
continue;
V_313 = F_214 ( V_317 , V_301 ) ;
if ( V_313 == NULL ) {
F_151 ( V_301 ) ;
} else if ( V_313 != V_301 ) {
F_151 ( V_301 ) ;
F_160 ( V_313 ) ;
}
}
F_208 ( V_312 -> V_20 , & V_298 ) ;
if ( V_317 -> V_322 ) {
for ( V_13 = 0 ; V_13 < V_317 -> V_322 ; V_13 ++ ) {
struct V_61 * V_324 = V_317 -> V_325 [ V_13 ] ;
if ( V_13 == 0 ) {
V_318 = V_324 -> V_308 ;
V_314 = V_324 ;
}
V_312 -> V_326 ( V_324 , V_312 ) ;
F_160 ( V_324 ) ;
}
goto V_321;
}
if ( V_317 == & V_316 )
F_215 ( & V_316 ) ;
return 0 ;
}
static void * F_216 ( int V_31 )
{
if ( F_217 ( V_31 ) )
return F_218 ( V_31 * sizeof( V_327 ) ) ;
else
return F_35 ( V_31 * sizeof( V_327 ) , V_53 ) ;
}
static void F_219 ( void * V_301 )
{
if ( F_220 ( V_301 ) )
F_221 ( V_301 ) ;
else
F_21 ( V_301 ) ;
}
static void * F_222 ( void * V_301 , int V_328 )
{
void * V_329 ;
if ( F_220 ( V_301 ) ) {
V_329 = F_218 ( V_328 * sizeof( V_327 ) ) ;
if ( ! V_329 )
return NULL ;
memcpy ( V_329 , V_301 , V_328 * sizeof( V_327 ) ) ;
F_221 ( V_301 ) ;
} else {
V_329 = F_223 ( V_301 , V_328 * sizeof( V_327 ) , V_53 ) ;
}
return V_329 ;
}
static int F_224 ( V_327 * * V_301 , int V_330 )
{
int V_331 , V_332 = 1 ;
V_327 * V_333 = * V_301 ;
V_327 * V_329 ;
if ( V_330 == 0 || V_330 == 1 )
return V_330 ;
for ( V_331 = 1 ; V_331 < V_330 ; V_331 ++ ) {
while ( V_333 [ V_331 ] == V_333 [ V_331 - 1 ] ) {
V_331 ++ ;
if ( V_331 == V_330 )
goto V_334;
}
V_333 [ V_332 ] = V_333 [ V_331 ] ;
V_332 ++ ;
}
V_334:
if ( F_225 ( V_330 , V_332 ) ) {
V_329 = F_222 ( V_333 , V_332 ) ;
if ( V_329 )
* V_301 = V_329 ;
}
return V_332 ;
}
static int F_226 ( const void * V_335 , const void * V_336 )
{
return * ( V_327 * ) V_335 - * ( V_327 * ) V_336 ;
}
static struct V_337 * F_227 ( struct V_2 * V_3 ,
enum V_338 type )
{
struct V_337 * V_299 ;
struct V_339 * V_340 = V_234 -> V_341 -> V_342 ;
F_51 ( & V_3 -> V_146 ) ;
F_47 (l, &cgrp->pidlists, links) {
if ( V_299 -> V_263 . type == type && V_299 -> V_263 . V_340 == V_340 ) {
F_228 ( & V_299 -> V_343 ) ;
F_53 ( & V_3 -> V_146 ) ;
return V_299 ;
}
}
V_299 = F_35 ( sizeof( struct V_337 ) , V_53 ) ;
if ( ! V_299 ) {
F_53 ( & V_3 -> V_146 ) ;
return V_299 ;
}
F_229 ( & V_299 -> V_343 ) ;
F_228 ( & V_299 -> V_343 ) ;
V_299 -> V_263 . type = type ;
V_299 -> V_263 . V_340 = F_230 ( V_340 ) ;
V_299 -> V_344 = 0 ;
V_299 -> V_333 = NULL ;
V_299 -> V_345 = V_3 ;
F_36 ( & V_299 -> V_215 , & V_3 -> V_89 ) ;
F_53 ( & V_3 -> V_146 ) ;
return V_299 ;
}
static int F_231 ( struct V_2 * V_3 , enum V_338 type ,
struct V_337 * * V_346 )
{
V_327 * V_347 ;
int V_330 ;
int V_224 , V_348 = 0 ;
struct V_297 V_298 ;
struct V_61 * V_195 ;
struct V_337 * V_299 ;
V_330 = F_200 ( V_3 ) ;
V_347 = F_216 ( V_330 ) ;
if ( ! V_347 )
return - V_54 ;
F_206 ( V_3 , & V_298 ) ;
while ( ( V_195 = F_207 ( V_3 , & V_298 ) ) ) {
if ( F_81 ( V_348 == V_330 ) )
break;
if ( type == V_349 )
V_224 = F_232 ( V_195 ) ;
else
V_224 = F_233 ( V_195 ) ;
if ( V_224 > 0 )
V_347 [ V_348 ++ ] = V_224 ;
}
F_208 ( V_3 , & V_298 ) ;
V_330 = V_348 ;
F_234 ( V_347 , V_330 , sizeof( V_327 ) , F_226 , NULL ) ;
if ( type == V_349 )
V_330 = F_224 ( & V_347 , V_330 ) ;
V_299 = F_227 ( V_3 , type ) ;
if ( ! V_299 ) {
F_219 ( V_347 ) ;
return - V_54 ;
}
F_219 ( V_299 -> V_333 ) ;
V_299 -> V_333 = V_347 ;
V_299 -> V_330 = V_330 ;
V_299 -> V_344 ++ ;
F_235 ( & V_299 -> V_343 ) ;
* V_346 = V_299 ;
return 0 ;
}
int F_236 ( struct V_350 * V_351 , struct V_85 * V_85 )
{
int V_83 = - V_135 ;
struct V_2 * V_3 ;
struct V_297 V_298 ;
struct V_61 * V_195 ;
if ( V_85 -> V_352 -> V_163 != & V_164 ||
! F_62 ( V_85 -> V_93 -> V_71 ) )
goto V_274;
V_83 = 0 ;
V_3 = V_85 -> V_86 ;
F_206 ( V_3 , & V_298 ) ;
while ( ( V_195 = F_207 ( V_3 , & V_298 ) ) ) {
switch ( V_195 -> V_266 ) {
case V_353 :
V_351 -> V_354 ++ ;
break;
case V_355 :
V_351 -> V_356 ++ ;
break;
case V_357 :
V_351 -> V_358 ++ ;
break;
case V_359 :
V_351 -> V_360 ++ ;
break;
default:
if ( F_237 ( V_195 ) )
V_351 -> V_361 ++ ;
break;
}
}
F_208 ( V_3 , & V_298 ) ;
V_274:
return V_83 ;
}
static void * F_238 ( struct V_116 * V_362 , T_6 * V_363 )
{
struct V_337 * V_299 = V_362 -> V_257 ;
int V_14 = 0 , V_224 = * V_363 ;
int * V_364 ;
F_239 ( & V_299 -> V_343 ) ;
if ( V_224 ) {
int V_243 = V_299 -> V_330 ;
while ( V_14 < V_243 ) {
int V_365 = ( V_14 + V_243 ) / 2 ;
if ( V_299 -> V_333 [ V_365 ] == V_224 ) {
V_14 = V_365 ;
break;
} else if ( V_299 -> V_333 [ V_365 ] <= V_224 )
V_14 = V_365 + 1 ;
else
V_243 = V_365 ;
}
}
if ( V_14 >= V_299 -> V_330 )
return NULL ;
V_364 = V_299 -> V_333 + V_14 ;
* V_363 = * V_364 ;
return V_364 ;
}
static void F_240 ( struct V_116 * V_362 , void * V_366 )
{
struct V_337 * V_299 = V_362 -> V_257 ;
F_241 ( & V_299 -> V_343 ) ;
}
static void * F_242 ( struct V_116 * V_362 , void * V_366 , T_6 * V_363 )
{
struct V_337 * V_299 = V_362 -> V_257 ;
V_327 * V_301 = V_366 ;
V_327 * V_243 = V_299 -> V_333 + V_299 -> V_330 ;
V_301 ++ ;
if ( V_301 >= V_243 ) {
return NULL ;
} else {
* V_363 = * V_301 ;
return V_301 ;
}
}
static int F_243 ( struct V_116 * V_362 , void * V_366 )
{
return F_93 ( V_362 , L_18 , * ( int * ) V_366 ) ;
}
static void F_244 ( struct V_337 * V_299 )
{
F_51 ( & V_299 -> V_345 -> V_146 ) ;
F_228 ( & V_299 -> V_343 ) ;
F_28 ( ! V_299 -> V_344 ) ;
if ( ! -- V_299 -> V_344 ) {
F_18 ( & V_299 -> V_215 ) ;
F_53 ( & V_299 -> V_345 -> V_146 ) ;
F_219 ( V_299 -> V_333 ) ;
F_245 ( V_299 -> V_263 . V_340 ) ;
F_235 ( & V_299 -> V_343 ) ;
F_21 ( V_299 ) ;
return;
}
F_53 ( & V_299 -> V_345 -> V_146 ) ;
F_235 ( & V_299 -> V_343 ) ;
}
static int F_246 ( struct V_66 * V_66 , struct V_238 * V_238 )
{
struct V_337 * V_299 ;
if ( ! ( V_238 -> V_367 & V_368 ) )
return 0 ;
V_299 = ( (struct V_116 * ) V_238 -> V_273 ) -> V_257 ;
F_244 ( V_299 ) ;
return F_247 ( V_66 , V_238 ) ;
}
static int F_248 ( struct V_238 * V_238 , enum V_338 type )
{
struct V_2 * V_3 = F_130 ( V_238 -> V_254 -> V_92 ) ;
struct V_337 * V_299 ;
int V_201 ;
if ( ! ( V_238 -> V_367 & V_368 ) )
return 0 ;
V_201 = F_231 ( V_3 , type , & V_299 ) ;
if ( V_201 )
return V_201 ;
V_238 -> V_276 = & V_369 ;
V_201 = F_249 ( V_238 , & V_370 ) ;
if ( V_201 ) {
F_244 ( V_299 ) ;
return V_201 ;
}
( (struct V_116 * ) V_238 -> V_273 ) -> V_257 = V_299 ;
return 0 ;
}
static int F_250 ( struct V_66 * V_371 , struct V_238 * V_238 )
{
return F_248 ( V_238 , V_372 ) ;
}
static int F_251 ( struct V_66 * V_371 , struct V_238 * V_238 )
{
return F_248 ( V_238 , V_349 ) ;
}
static T_2 F_252 ( struct V_2 * V_3 ,
struct V_187 * V_235 )
{
return F_7 ( V_3 ) ;
}
static int F_253 ( struct V_2 * V_3 ,
struct V_187 * V_235 ,
T_2 V_247 )
{
F_254 ( V_7 , & V_3 -> V_5 ) ;
if ( V_247 )
F_19 ( V_8 , & V_3 -> V_5 ) ;
else
F_254 ( V_8 , & V_3 -> V_5 ) ;
return 0 ;
}
static void F_255 ( struct V_373 * V_374 )
{
struct V_375 * V_376 = F_256 ( V_374 , struct V_375 ,
remove ) ;
struct V_2 * V_3 = V_376 -> V_3 ;
V_376 -> V_235 -> V_377 ( V_3 , V_376 -> V_235 , V_376 -> V_378 ) ;
F_257 ( V_376 -> V_378 ) ;
F_21 ( V_376 ) ;
F_71 ( V_3 -> V_85 ) ;
}
static int F_258 ( T_8 * V_379 , unsigned V_67 ,
int V_380 , void * V_263 )
{
struct V_375 * V_376 = F_256 ( V_379 ,
struct V_375 , V_379 ) ;
struct V_2 * V_3 = V_376 -> V_3 ;
unsigned long V_5 = ( unsigned long ) V_263 ;
if ( V_5 & V_381 ) {
F_259 ( V_376 -> V_382 , & V_376 -> V_379 ) ;
F_73 ( & V_3 -> V_148 ) ;
F_18 ( & V_376 -> V_333 ) ;
F_77 ( & V_3 -> V_148 ) ;
F_260 ( & V_376 -> remove ) ;
}
return 0 ;
}
static void F_261 ( struct V_238 * V_238 ,
T_9 * V_382 , T_10 * V_383 )
{
struct V_375 * V_376 = F_256 ( V_383 ,
struct V_375 , V_383 ) ;
V_376 -> V_382 = V_382 ;
F_262 ( V_382 , & V_376 -> V_379 ) ;
}
static int F_263 ( struct V_2 * V_3 , struct V_187 * V_235 ,
const char * V_237 )
{
struct V_375 * V_376 = NULL ;
unsigned int V_384 , V_385 ;
struct V_238 * V_386 = NULL ;
struct V_238 * V_387 = NULL ;
char * V_388 ;
int V_83 ;
V_384 = F_264 ( V_237 , & V_388 , 10 ) ;
if ( * V_388 != ' ' )
return - V_135 ;
V_237 = V_388 + 1 ;
V_385 = F_264 ( V_237 , & V_388 , 10 ) ;
if ( ( * V_388 != ' ' ) && ( * V_388 != '\0' ) )
return - V_135 ;
V_237 = V_388 + 1 ;
V_376 = F_113 ( sizeof( * V_376 ) , V_53 ) ;
if ( ! V_376 )
return - V_54 ;
V_376 -> V_3 = V_3 ;
F_34 ( & V_376 -> V_333 ) ;
F_265 ( & V_376 -> V_383 , F_261 ) ;
F_266 ( & V_376 -> V_379 , F_258 ) ;
F_267 ( & V_376 -> remove , F_255 ) ;
V_386 = F_268 ( V_384 ) ;
if ( F_123 ( V_386 ) ) {
V_83 = F_124 ( V_386 ) ;
goto V_389;
}
V_376 -> V_378 = F_269 ( V_386 ) ;
if ( F_123 ( V_376 -> V_378 ) ) {
V_83 = F_124 ( V_376 -> V_378 ) ;
goto V_389;
}
V_387 = F_270 ( V_385 ) ;
if ( ! V_387 ) {
V_83 = - V_390 ;
goto V_389;
}
V_83 = F_271 ( V_387 , V_391 ) ;
if ( V_83 < 0 )
goto V_389;
V_376 -> V_235 = F_190 ( V_387 ) ;
if ( F_123 ( V_376 -> V_235 ) ) {
V_83 = F_124 ( V_376 -> V_235 ) ;
goto V_389;
}
if ( ! V_376 -> V_235 -> V_392 || ! V_376 -> V_235 -> V_377 ) {
V_83 = - V_135 ;
goto V_389;
}
V_83 = V_376 -> V_235 -> V_392 ( V_3 , V_376 -> V_235 ,
V_376 -> V_378 , V_237 ) ;
if ( V_83 )
goto V_389;
if ( V_386 -> V_276 -> V_393 ( V_386 , & V_376 -> V_383 ) & V_381 ) {
V_376 -> V_235 -> V_377 ( V_3 , V_376 -> V_235 , V_376 -> V_378 ) ;
V_83 = 0 ;
goto V_389;
}
F_68 ( V_3 -> V_85 ) ;
F_73 ( & V_3 -> V_148 ) ;
F_36 ( & V_376 -> V_333 , & V_3 -> V_147 ) ;
F_77 ( & V_3 -> V_148 ) ;
F_272 ( V_387 ) ;
F_272 ( V_386 ) ;
return 0 ;
V_389:
if ( V_387 )
F_272 ( V_387 ) ;
if ( V_376 && V_376 -> V_378 && ! F_123 ( V_376 -> V_378 ) )
F_257 ( V_376 -> V_378 ) ;
if ( ! F_273 ( V_386 ) )
F_272 ( V_386 ) ;
F_21 ( V_376 ) ;
return V_83 ;
}
static T_2 F_274 ( struct V_2 * V_3 ,
struct V_187 * V_235 )
{
return F_8 ( V_3 ) ;
}
static int F_275 ( struct V_2 * V_3 ,
struct V_187 * V_235 ,
T_2 V_247 )
{
if ( V_247 )
F_19 ( V_9 , & V_3 -> V_5 ) ;
else
F_254 ( V_9 , & V_3 -> V_5 ) ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 )
{
int V_274 ;
struct V_81 * V_82 ;
F_72 ( V_3 -> V_85 ) ;
V_274 = F_199 ( V_3 , NULL , V_394 , F_276 ( V_394 ) ) ;
if ( V_274 < 0 )
return V_274 ;
if ( V_3 == V_3 -> V_65 ) {
if ( ( V_274 = F_197 ( V_3 , NULL , & V_395 ) ) < 0 )
return V_274 ;
}
F_60 (cgrp->root, ss) {
if ( V_82 -> V_396 && ( V_274 = V_82 -> V_396 ( V_82 , V_3 ) ) < 0 )
return V_274 ;
}
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_397 ] ;
if ( V_12 -> V_398 )
F_139 ( V_12 -> V_398 -> V_12 , V_12 ) ;
}
return 0 ;
}
static void F_277 ( struct V_11 * V_12 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
V_12 -> V_2 = V_3 ;
F_45 ( & V_12 -> V_399 , 1 ) ;
V_12 -> V_5 = 0 ;
V_12 -> V_398 = NULL ;
if ( V_3 == V_110 )
F_19 ( V_400 , & V_12 -> V_5 ) ;
F_28 ( V_3 -> V_39 [ V_82 -> V_397 ] ) ;
V_3 -> V_39 [ V_82 -> V_397 ] = V_12 ;
}
static void F_278 ( struct V_48 * V_46 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
if ( V_82 -> V_46 == V_46 )
F_51 ( & V_82 -> V_111 ) ;
}
}
static void F_279 ( struct V_48 * V_46 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
if ( V_82 -> V_46 == V_46 )
F_53 ( & V_82 -> V_111 ) ;
}
}
static long F_280 ( struct V_2 * V_91 , struct V_85 * V_85 ,
T_1 V_67 )
{
struct V_2 * V_3 ;
struct V_48 * V_46 = V_91 -> V_46 ;
int V_274 = 0 ;
struct V_81 * V_82 ;
struct V_68 * V_69 = V_46 -> V_69 ;
V_3 = F_113 ( sizeof( * V_3 ) , V_53 ) ;
if ( ! V_3 )
return - V_54 ;
F_24 ( & V_69 -> V_401 ) ;
F_51 ( & V_1 ) ;
F_103 ( V_3 ) ;
V_3 -> V_91 = V_91 ;
V_3 -> V_46 = V_91 -> V_46 ;
V_3 -> V_65 = V_91 -> V_65 ;
if ( F_7 ( V_91 ) )
F_19 ( V_8 , & V_3 -> V_5 ) ;
if ( F_8 ( V_91 ) )
F_19 ( V_9 , & V_3 -> V_5 ) ;
F_60 (root, ss) {
struct V_11 * V_12 = V_82 -> V_402 ( V_82 , V_3 ) ;
if ( F_123 ( V_12 ) ) {
V_274 = F_124 ( V_12 ) ;
goto V_403;
}
F_277 ( V_12 , V_82 , V_3 ) ;
if ( V_82 -> V_404 ) {
V_274 = F_281 ( V_82 , V_91 , V_3 ) ;
if ( V_274 )
goto V_403;
}
if ( F_8 ( V_91 ) && V_82 -> V_405 )
V_82 -> V_405 ( V_82 , V_3 ) ;
}
F_278 ( V_46 ) ;
F_36 ( & V_3 -> V_112 , & V_3 -> V_91 -> V_144 ) ;
F_279 ( V_46 ) ;
V_46 -> V_88 ++ ;
V_274 = F_195 ( V_3 , V_85 , V_67 ) ;
if ( V_274 < 0 )
goto V_406;
F_28 ( ! F_3 ( & V_3 -> V_85 -> V_93 -> V_94 ) ) ;
V_274 = F_102 ( V_3 ) ;
F_53 ( & V_1 ) ;
F_53 ( & V_3 -> V_85 -> V_93 -> V_94 ) ;
return 0 ;
V_406:
F_278 ( V_46 ) ;
F_18 ( & V_3 -> V_112 ) ;
F_279 ( V_46 ) ;
V_46 -> V_88 -- ;
V_403:
F_60 (root, ss) {
if ( V_3 -> V_39 [ V_82 -> V_397 ] )
V_82 -> V_87 ( V_82 , V_3 ) ;
}
F_53 ( & V_1 ) ;
F_64 ( V_69 ) ;
F_21 ( V_3 ) ;
return V_274 ;
}
static int F_282 ( struct V_66 * V_287 , struct V_85 * V_85 , int V_67 )
{
struct V_2 * V_407 = V_85 -> V_92 -> V_86 ;
return F_280 ( V_407 , V_85 , V_67 | V_100 ) ;
}
static int F_283 ( struct V_2 * V_3 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
struct V_11 * V_12 ;
if ( V_82 == NULL || V_82 -> V_46 != V_3 -> V_46 )
continue;
V_12 = V_3 -> V_39 [ V_82 -> V_397 ] ;
if ( V_12 && ( F_201 ( & V_12 -> V_399 ) > 1 ) )
return 1 ;
}
return 0 ;
}
static int F_284 ( struct V_2 * V_3 )
{
struct V_81 * V_82 ;
unsigned long V_5 ;
bool V_408 = false ;
F_285 ( V_5 ) ;
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_397 ] ;
int V_399 ;
while ( 1 ) {
V_399 = F_201 ( & V_12 -> V_399 ) ;
if ( V_399 > 1 ) {
V_408 = true ;
goto V_409;
}
F_28 ( ! V_399 ) ;
if ( F_286 ( & V_12 -> V_399 , V_399 , 0 ) == V_399 )
break;
F_287 () ;
}
}
V_409:
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_397 ] ;
if ( V_408 ) {
if ( ! F_201 ( & V_12 -> V_399 ) )
F_45 ( & V_12 -> V_399 , 1 ) ;
} else {
F_19 ( V_410 , & V_12 -> V_5 ) ;
}
}
F_288 ( V_5 ) ;
return ! V_408 ;
}
static int F_289 ( struct V_66 * V_411 , struct V_85 * V_85 )
{
struct V_2 * V_3 = V_85 -> V_86 ;
struct V_85 * V_90 ;
struct V_2 * V_91 ;
F_290 ( V_379 ) ;
struct V_375 * V_376 , * V_15 ;
int V_83 ;
V_321:
F_51 ( & V_1 ) ;
if ( F_201 ( & V_3 -> V_31 ) != 0 ) {
F_53 ( & V_1 ) ;
return - V_109 ;
}
if ( ! F_38 ( & V_3 -> V_144 ) ) {
F_53 ( & V_1 ) ;
return - V_109 ;
}
F_53 ( & V_1 ) ;
F_19 ( V_101 , & V_3 -> V_5 ) ;
V_83 = F_59 ( V_3 ) ;
if ( V_83 ) {
F_254 ( V_101 , & V_3 -> V_5 ) ;
return V_83 ;
}
F_51 ( & V_1 ) ;
V_91 = V_3 -> V_91 ;
if ( F_201 ( & V_3 -> V_31 ) || ! F_38 ( & V_3 -> V_144 ) ) {
F_254 ( V_101 , & V_3 -> V_5 ) ;
F_53 ( & V_1 ) ;
return - V_109 ;
}
F_291 ( & V_102 , & V_379 , V_355 ) ;
if ( ! F_284 ( V_3 ) ) {
F_53 ( & V_1 ) ;
if ( F_5 ( V_101 , & V_3 -> V_5 ) )
F_292 () ;
F_293 ( & V_102 , & V_379 ) ;
F_254 ( V_101 , & V_3 -> V_5 ) ;
if ( F_294 ( V_234 ) )
return - V_412 ;
goto V_321;
}
F_293 ( & V_102 , & V_379 ) ;
F_254 ( V_101 , & V_3 -> V_5 ) ;
F_73 ( & V_413 ) ;
F_19 ( V_4 , & V_3 -> V_5 ) ;
if ( ! F_38 ( & V_3 -> V_145 ) )
F_75 ( & V_3 -> V_145 ) ;
F_77 ( & V_413 ) ;
F_278 ( V_3 -> V_46 ) ;
F_75 ( & V_3 -> V_112 ) ;
F_279 ( V_3 -> V_46 ) ;
V_90 = F_68 ( V_3 -> V_85 ) ;
F_79 ( V_90 ) ;
F_71 ( V_90 ) ;
F_19 ( V_7 , & V_91 -> V_5 ) ;
F_20 ( V_91 ) ;
F_73 ( & V_3 -> V_148 ) ;
F_17 (event, tmp, &cgrp->event_list, list) {
F_18 ( & V_376 -> V_333 ) ;
F_295 ( V_376 -> V_382 , & V_376 -> V_379 ) ;
F_296 ( V_376 -> V_378 , 1 ) ;
F_260 ( & V_376 -> remove ) ;
}
F_77 ( & V_3 -> V_148 ) ;
F_53 ( & V_1 ) ;
return 0 ;
}
static void T_11 F_297 ( struct V_81 * V_82 )
{
struct V_11 * V_12 ;
F_298 ( V_414 L_19 , V_82 -> V_122 ) ;
F_36 ( & V_82 -> V_112 , & V_108 . V_113 ) ;
V_82 -> V_46 = & V_108 ;
V_12 = V_82 -> V_402 ( V_82 , V_110 ) ;
F_28 ( F_123 ( V_12 ) ) ;
F_277 ( V_12 , V_82 , V_110 ) ;
V_64 . V_39 [ V_82 -> V_397 ] = V_110 -> V_39 [ V_82 -> V_397 ] ;
V_415 |= V_82 -> V_416 || V_82 -> exit ;
F_28 ( ! F_38 ( & V_417 . V_59 ) ) ;
F_104 ( & V_82 -> V_111 ) ;
F_299 ( & V_82 -> V_111 , & V_82 -> V_418 ) ;
V_82 -> V_419 = 1 ;
F_28 ( V_82 -> V_115 ) ;
}
int T_12 F_300 ( struct V_81 * V_82 )
{
int V_13 ;
struct V_11 * V_12 ;
if ( V_82 -> V_122 == NULL || strlen ( V_82 -> V_122 ) > V_294 ||
V_82 -> V_402 == NULL || V_82 -> V_87 == NULL )
return - V_135 ;
if ( V_82 -> V_416 || V_82 -> exit )
return - V_135 ;
if ( V_82 -> V_115 == NULL ) {
F_28 ( V_82 -> V_397 >= V_142 ) ;
F_28 ( V_39 [ V_82 -> V_397 ] != V_82 ) ;
return 0 ;
}
F_51 ( & V_1 ) ;
for ( V_13 = V_142 ; V_13 < V_16 ; V_13 ++ ) {
if ( V_39 [ V_13 ] == NULL )
break;
}
if ( V_13 == V_16 ) {
F_53 ( & V_1 ) ;
return - V_109 ;
}
V_82 -> V_397 = V_13 ;
V_39 [ V_13 ] = V_82 ;
V_12 = V_82 -> V_402 ( V_82 , V_110 ) ;
if ( F_123 ( V_12 ) ) {
V_39 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
return F_124 ( V_12 ) ;
}
F_36 ( & V_82 -> V_112 , & V_108 . V_113 ) ;
V_82 -> V_46 = & V_108 ;
F_277 ( V_12 , V_82 , V_110 ) ;
if ( V_82 -> V_404 ) {
int V_83 = F_301 ( V_82 , V_12 ) ;
if ( V_83 ) {
V_110 -> V_39 [ V_82 -> V_397 ] = NULL ;
V_82 -> V_87 ( V_82 , V_110 ) ;
V_39 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
return V_83 ;
}
}
F_13 ( & V_26 ) ;
for ( V_13 = 0 ; V_13 < V_186 ; V_13 ++ ) {
struct V_19 * V_20 ;
struct V_50 * V_51 , * V_15 ;
struct V_10 * V_420 = & V_18 [ V_13 ] , * V_421 ;
F_302 (cg, node, tmp, bucket, hlist) {
if ( V_20 -> V_39 [ V_82 -> V_397 ] )
continue;
F_16 ( & V_20 -> V_27 ) ;
V_20 -> V_39 [ V_82 -> V_397 ] = V_12 ;
V_421 = F_9 ( V_20 -> V_39 ) ;
F_48 ( & V_20 -> V_27 , V_421 ) ;
}
}
F_15 ( & V_26 ) ;
F_104 ( & V_82 -> V_111 ) ;
F_299 ( & V_82 -> V_111 , & V_82 -> V_418 ) ;
V_82 -> V_419 = 1 ;
F_53 ( & V_1 ) ;
return 0 ;
}
void F_303 ( struct V_81 * V_82 )
{
struct V_22 * V_23 ;
struct V_10 * V_49 ;
F_28 ( V_82 -> V_115 == NULL ) ;
F_28 ( V_82 -> V_46 != & V_108 ) ;
F_51 ( & V_1 ) ;
F_28 ( V_82 -> V_397 < V_142 ) ;
V_39 [ V_82 -> V_397 ] = NULL ;
F_75 ( & V_82 -> V_112 ) ;
F_13 ( & V_26 ) ;
F_47 (link, &dummytop->css_sets, cgrp_link_list) {
struct V_19 * V_20 = V_23 -> V_20 ;
F_16 ( & V_20 -> V_27 ) ;
F_28 ( ! V_20 -> V_39 [ V_82 -> V_397 ] ) ;
V_20 -> V_39 [ V_82 -> V_397 ] = NULL ;
V_49 = F_9 ( V_20 -> V_39 ) ;
F_48 ( & V_20 -> V_27 , V_49 ) ;
}
F_15 ( & V_26 ) ;
V_82 -> V_87 ( V_82 , V_110 ) ;
V_110 -> V_39 [ V_82 -> V_397 ] = NULL ;
F_53 ( & V_1 ) ;
}
int T_11 F_304 ( void )
{
int V_13 ;
F_45 ( & V_64 . V_25 , 1 ) ;
F_34 ( & V_64 . V_40 ) ;
F_34 ( & V_64 . V_59 ) ;
F_46 ( & V_64 . V_27 ) ;
V_28 = 1 ;
F_106 ( & V_108 ) ;
V_58 = 1 ;
V_417 . V_63 = & V_64 ;
V_422 . V_20 = & V_64 ;
V_422 . V_3 = V_110 ;
F_36 ( & V_422 . V_30 ,
& V_108 . V_65 . V_56 ) ;
F_36 ( & V_422 . V_29 ,
& V_64 . V_40 ) ;
for ( V_13 = 0 ; V_13 < V_186 ; V_13 ++ )
F_305 ( & V_18 [ V_13 ] ) ;
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
F_28 ( ! V_82 -> V_122 ) ;
F_28 ( strlen ( V_82 -> V_122 ) > V_294 ) ;
F_28 ( ! V_82 -> V_402 ) ;
F_28 ( ! V_82 -> V_87 ) ;
if ( V_82 -> V_397 != V_13 ) {
F_298 ( V_423 L_20 ,
V_82 -> V_122 , V_82 -> V_397 ) ;
F_306 () ;
}
if ( V_82 -> V_424 )
F_297 ( V_82 ) ;
}
return 0 ;
}
int T_11 F_307 ( void )
{
int V_274 ;
int V_13 ;
struct V_10 * V_49 ;
V_274 = F_308 ( & V_80 ) ;
if ( V_274 )
return V_274 ;
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( ! V_82 -> V_424 )
F_297 ( V_82 ) ;
if ( V_82 -> V_404 )
F_301 ( V_82 , V_64 . V_39 [ V_82 -> V_397 ] ) ;
}
V_49 = F_9 ( V_64 . V_39 ) ;
F_48 ( & V_64 . V_27 , V_49 ) ;
F_28 ( ! F_107 ( & V_108 ) ) ;
V_425 = F_309 ( L_21 , V_426 ) ;
if ( ! V_425 ) {
V_274 = - V_54 ;
goto V_204;
}
V_274 = F_310 ( & V_427 ) ;
if ( V_274 < 0 ) {
F_311 ( V_425 ) ;
goto V_204;
}
F_312 ( L_22 , 0 , NULL , & V_428 ) ;
V_204:
if ( V_274 )
F_313 ( & V_80 ) ;
return V_274 ;
}
static int F_314 ( struct V_116 * V_267 , void * V_366 )
{
struct V_224 * V_224 ;
struct V_61 * V_195 ;
char * V_188 ;
int V_201 ;
struct V_48 * V_46 ;
V_201 = - V_54 ;
V_188 = F_35 ( V_320 , V_53 ) ;
if ( ! V_188 )
goto V_204;
V_201 = - V_199 ;
V_224 = V_267 -> V_257 ;
V_195 = F_315 ( V_224 , V_429 ) ;
if ( ! V_195 )
goto V_430;
V_201 = 0 ;
F_51 ( & V_1 ) ;
F_126 (root) {
struct V_81 * V_82 ;
struct V_2 * V_3 ;
int V_31 = 0 ;
F_93 ( V_267 , L_23 , V_46 -> V_153 ) ;
F_60 (root, ss)
F_93 ( V_267 , L_24 , V_31 ++ ? L_6 : L_25 , V_82 -> V_122 ) ;
if ( strlen ( V_46 -> V_122 ) )
F_93 ( V_267 , L_26 , V_31 ? L_6 : L_25 ,
V_46 -> V_122 ) ;
F_166 ( V_267 , ':' ) ;
V_3 = F_49 ( V_195 , V_46 ) ;
V_201 = F_132 ( V_3 , V_188 , V_320 ) ;
if ( V_201 < 0 )
goto V_143;
F_94 ( V_267 , V_188 ) ;
F_166 ( V_267 , '\n' ) ;
}
V_143:
F_53 ( & V_1 ) ;
F_160 ( V_195 ) ;
V_430:
F_21 ( V_188 ) ;
V_204:
return V_201 ;
}
static int F_316 ( struct V_66 * V_66 , struct V_238 * V_238 )
{
struct V_224 * V_224 = F_317 ( V_66 ) -> V_224 ;
return F_184 ( V_238 , F_314 , V_224 ) ;
}
static int F_318 ( struct V_116 * V_267 , void * V_366 )
{
int V_13 ;
F_94 ( V_267 , L_27 ) ;
F_51 ( & V_1 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
F_93 ( V_267 , L_28 ,
V_82 -> V_122 , V_82 -> V_46 -> V_153 ,
V_82 -> V_46 -> V_88 , ! V_82 -> V_140 ) ;
}
F_53 ( & V_1 ) ;
return 0 ;
}
static int F_319 ( struct V_66 * V_66 , struct V_238 * V_238 )
{
return F_184 ( V_238 , F_318 , NULL ) ;
}
void F_320 ( struct V_61 * V_431 )
{
F_136 ( V_234 ) ;
V_431 -> V_63 = V_234 -> V_63 ;
F_23 ( V_431 -> V_63 ) ;
F_137 ( V_234 ) ;
F_34 ( & V_431 -> V_200 ) ;
}
void F_321 ( struct V_61 * V_431 )
{
if ( V_415 ) {
int V_13 ;
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 -> V_416 )
V_82 -> V_416 ( V_82 , V_431 ) ;
}
}
}
void F_322 ( struct V_61 * V_431 )
{
if ( V_303 ) {
F_13 ( & V_26 ) ;
F_136 ( V_431 ) ;
if ( F_38 ( & V_431 -> V_200 ) )
F_36 ( & V_431 -> V_200 , & V_431 -> V_63 -> V_59 ) ;
F_137 ( V_431 ) ;
F_15 ( & V_26 ) ;
}
}
void F_323 ( struct V_61 * V_195 , int V_432 )
{
struct V_19 * V_20 ;
int V_13 ;
if ( ! F_38 ( & V_195 -> V_200 ) ) {
F_13 ( & V_26 ) ;
if ( ! F_38 ( & V_195 -> V_200 ) )
F_75 ( & V_195 -> V_200 ) ;
F_15 ( & V_26 ) ;
}
F_136 ( V_195 ) ;
V_20 = V_195 -> V_63 ;
V_195 -> V_63 = & V_64 ;
if ( V_432 && V_415 ) {
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 -> exit ) {
struct V_2 * V_433 =
F_324 ( V_20 -> V_39 [ V_13 ] ) -> V_2 ;
struct V_2 * V_3 = F_325 ( V_195 , V_13 ) ;
V_82 -> exit ( V_82 , V_3 , V_433 , V_195 ) ;
}
}
}
F_137 ( V_195 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
}
int F_326 ( const struct V_2 * V_3 , struct V_61 * V_62 )
{
int V_83 ;
struct V_2 * V_434 ;
if ( V_3 == V_110 )
return 1 ;
V_434 = F_49 ( V_62 , V_3 -> V_46 ) ;
while ( V_3 != V_434 && V_3 != V_3 -> V_65 )
V_3 = V_3 -> V_91 ;
V_83 = ( V_3 == V_434 ) ;
return V_83 ;
}
static void F_20 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 ) && ! F_201 ( & V_3 -> V_31 )
&& F_38 ( & V_3 -> V_144 ) && ! F_283 ( V_3 ) ) {
int V_435 = 0 ;
F_73 ( & V_413 ) ;
if ( ! F_4 ( V_3 ) &&
F_38 ( & V_3 -> V_145 ) ) {
F_36 ( & V_3 -> V_145 , & V_145 ) ;
V_435 = 1 ;
}
F_77 ( & V_413 ) ;
if ( V_435 )
F_260 ( & V_436 ) ;
}
}
void F_327 ( struct V_11 * V_12 , int V_31 )
{
struct V_2 * V_3 = V_12 -> V_2 ;
int V_247 ;
F_148 () ;
V_247 = F_328 ( V_31 , & V_12 -> V_399 ) ;
if ( V_247 == 1 ) {
if ( F_7 ( V_3 ) ) {
F_19 ( V_7 , & V_3 -> V_5 ) ;
F_20 ( V_3 ) ;
}
F_80 ( V_3 ) ;
}
F_150 () ;
F_329 ( V_247 < 1 ) ;
}
static void F_330 ( struct V_373 * V_374 )
{
F_28 ( V_374 != & V_436 ) ;
F_51 ( & V_1 ) ;
F_73 ( & V_413 ) ;
while ( ! F_38 ( & V_145 ) ) {
char * V_437 [ 3 ] , * V_438 [ 3 ] ;
int V_13 ;
char * V_439 = NULL , * V_440 = NULL ;
struct V_2 * V_3 = F_29 ( V_145 . V_45 ,
struct V_2 ,
V_145 ) ;
F_75 ( & V_3 -> V_145 ) ;
F_77 ( & V_413 ) ;
V_439 = F_35 ( V_320 , V_53 ) ;
if ( ! V_439 )
goto V_441;
if ( F_132 ( V_3 , V_439 , V_320 ) < 0 )
goto V_441;
V_440 = F_331 ( V_3 -> V_46 -> V_124 , V_53 ) ;
if ( ! V_440 )
goto V_441;
V_13 = 0 ;
V_437 [ V_13 ++ ] = V_440 ;
V_437 [ V_13 ++ ] = V_439 ;
V_437 [ V_13 ] = NULL ;
V_13 = 0 ;
V_438 [ V_13 ++ ] = L_29 ;
V_438 [ V_13 ++ ] = L_30 ;
V_438 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
F_332 ( V_437 [ 0 ] , V_437 , V_438 , V_442 ) ;
F_51 ( & V_1 ) ;
V_441:
F_21 ( V_439 ) ;
F_21 ( V_440 ) ;
F_73 ( & V_413 ) ;
}
F_77 ( & V_413 ) ;
F_53 ( & V_1 ) ;
}
static int T_11 F_333 ( char * V_443 )
{
int V_13 ;
char * V_128 ;
while ( ( V_128 = F_97 ( & V_443 , L_6 ) ) != NULL ) {
if ( ! * V_128 )
continue;
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( ! strcmp ( V_128 , V_82 -> V_122 ) ) {
V_82 -> V_140 = 1 ;
F_298 ( V_414 L_31
L_32 , V_82 -> V_122 ) ;
break;
}
}
}
return 1 ;
}
unsigned short F_334 ( struct V_11 * V_12 )
{
struct F_334 * V_444 ;
V_444 = F_133 ( V_12 -> V_398 ,
F_134 () || F_201 ( & V_12 -> V_399 ) ) ;
if ( V_444 )
return V_444 -> V_398 ;
return 0 ;
}
unsigned short F_335 ( struct V_11 * V_12 )
{
struct F_334 * V_444 ;
V_444 = F_133 ( V_12 -> V_398 ,
F_134 () || F_201 ( & V_12 -> V_399 ) ) ;
if ( V_444 )
return V_444 -> V_445 ;
return 0 ;
}
bool F_336 ( struct V_11 * V_431 ,
const struct V_11 * V_46 )
{
struct F_334 * V_446 ;
struct F_334 * V_447 ;
bool V_83 = true ;
F_148 () ;
V_446 = F_337 ( V_431 -> V_398 ) ;
V_447 = F_337 ( V_46 -> V_398 ) ;
if ( ! V_446
|| ! V_447
|| ( V_446 -> V_445 < V_447 -> V_445 )
|| ( V_446 -> V_448 [ V_447 -> V_445 ] != V_447 -> V_398 ) )
V_83 = false ;
F_150 () ;
return V_83 ;
}
void F_338 ( struct V_81 * V_82 , struct V_11 * V_12 )
{
struct F_334 * V_398 = V_12 -> V_398 ;
if ( ! V_398 )
return;
F_28 ( ! V_82 -> V_404 ) ;
F_139 ( V_398 -> V_12 , NULL ) ;
F_139 ( V_12 -> V_398 , NULL ) ;
F_73 ( & V_82 -> V_449 ) ;
F_339 ( & V_82 -> V_450 , V_398 -> V_398 ) ;
F_77 ( & V_82 -> V_449 ) ;
F_22 ( V_398 , V_32 ) ;
}
static struct F_334 * F_340 ( struct V_81 * V_82 , int V_445 )
{
struct F_334 * V_451 ;
int V_452 , error , V_322 ;
F_28 ( ! V_82 -> V_404 ) ;
V_322 = sizeof( * V_451 ) + sizeof( unsigned short ) * ( V_445 + 1 ) ;
V_451 = F_113 ( V_322 , V_53 ) ;
if ( ! V_451 )
return F_114 ( - V_54 ) ;
if ( F_81 ( ! F_341 ( & V_82 -> V_450 , V_53 ) ) ) {
error = - V_54 ;
goto V_453;
}
F_73 ( & V_82 -> V_449 ) ;
error = F_342 ( & V_82 -> V_450 , V_451 , 1 , & V_452 ) ;
F_77 ( & V_82 -> V_449 ) ;
if ( error ) {
error = - V_154 ;
goto V_453;
}
if ( V_452 > V_454 )
goto V_455;
V_451 -> V_398 = V_452 ;
V_451 -> V_445 = V_445 ;
return V_451 ;
V_455:
error = - V_154 ;
F_73 ( & V_82 -> V_449 ) ;
F_339 ( & V_82 -> V_450 , V_452 ) ;
F_77 ( & V_82 -> V_449 ) ;
V_453:
F_21 ( V_451 ) ;
return F_114 ( error ) ;
}
static int T_12 F_301 ( struct V_81 * V_82 ,
struct V_11 * V_456 )
{
struct F_334 * V_451 ;
F_105 ( & V_82 -> V_449 ) ;
F_343 ( & V_82 -> V_450 ) ;
V_451 = F_340 ( V_82 , 0 ) ;
if ( F_123 ( V_451 ) )
return F_124 ( V_451 ) ;
V_451 -> V_448 [ 0 ] = V_451 -> V_398 ;
V_451 -> V_12 = V_456 ;
V_456 -> V_398 = V_451 ;
return 0 ;
}
static int F_281 ( struct V_81 * V_82 , struct V_2 * V_91 ,
struct V_2 * V_431 )
{
int V_397 , V_13 , V_445 = 0 ;
struct V_11 * V_457 , * V_458 ;
struct F_334 * V_446 , * V_459 ;
V_397 = V_82 -> V_397 ;
V_457 = V_91 -> V_39 [ V_397 ] ;
V_458 = V_431 -> V_39 [ V_397 ] ;
V_459 = V_457 -> V_398 ;
V_445 = V_459 -> V_445 + 1 ;
V_446 = F_340 ( V_82 , V_445 ) ;
if ( F_123 ( V_446 ) )
return F_124 ( V_446 ) ;
for ( V_13 = 0 ; V_13 < V_445 ; V_13 ++ )
V_446 -> V_448 [ V_13 ] = V_459 -> V_448 [ V_13 ] ;
V_446 -> V_448 [ V_445 ] = V_446 -> V_398 ;
F_139 ( V_458 -> V_398 , V_446 ) ;
return 0 ;
}
struct V_11 * F_344 ( struct V_81 * V_82 , int V_398 )
{
struct F_334 * V_444 = NULL ;
F_28 ( ! V_82 -> V_404 ) ;
V_444 = F_345 ( & V_82 -> V_450 , V_398 ) ;
if ( F_81 ( ! V_444 ) )
return NULL ;
return F_337 ( V_444 -> V_12 ) ;
}
struct V_11 *
F_346 ( struct V_81 * V_82 , int V_398 ,
struct V_11 * V_46 , int * V_460 )
{
struct V_11 * V_83 = NULL ;
struct F_334 * V_15 ;
int V_461 ;
int V_462 = F_334 ( V_46 ) ;
int V_445 = F_335 ( V_46 ) ;
if ( ! V_462 )
return NULL ;
F_28 ( ! V_82 -> V_404 ) ;
V_461 = V_398 ;
while ( 1 ) {
F_73 ( & V_82 -> V_449 ) ;
V_15 = F_347 ( & V_82 -> V_450 , & V_461 ) ;
F_77 ( & V_82 -> V_449 ) ;
if ( ! V_15 )
break;
if ( V_15 -> V_445 >= V_445 && V_15 -> V_448 [ V_445 ] == V_462 ) {
V_83 = F_337 ( V_15 -> V_12 ) ;
if ( V_83 ) {
* V_460 = V_461 ;
break;
}
}
V_461 = V_461 + 1 ;
}
return V_83 ;
}
struct V_11 * F_348 ( struct V_238 * V_463 , int V_398 )
{
struct V_2 * V_3 ;
struct V_66 * V_66 ;
struct V_11 * V_12 ;
V_66 = V_463 -> V_254 -> V_93 ;
if ( V_66 -> V_173 != & V_174 )
return F_114 ( - V_390 ) ;
if ( V_398 < 0 || V_398 >= V_16 )
return F_114 ( - V_135 ) ;
V_3 = F_130 ( V_463 -> V_254 ) ;
V_12 = V_3 -> V_39 [ V_398 ] ;
return V_12 ? V_12 : F_114 ( - V_141 ) ;
}
static struct V_11 * F_349 ( struct V_81 * V_82 ,
struct V_2 * V_464 )
{
struct V_11 * V_12 = F_113 ( sizeof( * V_12 ) , V_53 ) ;
if ( ! V_12 )
return F_114 ( - V_54 ) ;
return V_12 ;
}
static void F_350 ( struct V_81 * V_82 , struct V_2 * V_464 )
{
F_21 ( V_464 -> V_39 [ V_465 ] ) ;
}
static T_2 F_351 ( struct V_2 * V_464 , struct V_187 * V_235 )
{
return F_201 ( & V_464 -> V_31 ) ;
}
static T_2 F_352 ( struct V_2 * V_464 , struct V_187 * V_235 )
{
return F_200 ( V_464 ) ;
}
static T_2 F_353 ( struct V_2 * V_464 , struct V_187 * V_235 )
{
return ( T_2 ) ( unsigned long ) V_234 -> V_63 ;
}
static T_2 F_354 ( struct V_2 * V_464 ,
struct V_187 * V_235 )
{
T_2 V_31 ;
F_148 () ;
V_31 = F_201 ( & V_234 -> V_63 -> V_25 ) ;
F_150 () ;
return V_31 ;
}
static int F_355 ( struct V_2 * V_464 ,
struct V_187 * V_235 ,
struct V_116 * V_117 )
{
struct V_22 * V_23 ;
struct V_19 * V_20 ;
F_43 ( & V_26 ) ;
F_148 () ;
V_20 = F_337 ( V_234 -> V_63 ) ;
F_47 (link, &cg->cg_links, cg_link_list) {
struct V_2 * V_60 = V_23 -> V_3 ;
const char * V_122 ;
if ( V_60 -> V_85 )
V_122 = V_60 -> V_85 -> V_192 . V_122 ;
else
V_122 = L_33 ;
F_93 ( V_117 , L_34 ,
V_60 -> V_46 -> V_153 , V_122 ) ;
}
F_150 () ;
F_44 ( & V_26 ) ;
return 0 ;
}
static int F_356 ( struct V_2 * V_464 ,
struct V_187 * V_235 ,
struct V_116 * V_117 )
{
struct V_22 * V_23 ;
F_43 ( & V_26 ) ;
F_47 (link, &cont->css_sets, cgrp_link_list) {
struct V_19 * V_20 = V_23 -> V_20 ;
struct V_61 * V_62 ;
int V_31 = 0 ;
F_93 ( V_117 , L_35 , V_20 ) ;
F_47 (task, &cg->tasks, cg_list) {
if ( V_31 ++ > V_466 ) {
F_94 ( V_117 , L_36 ) ;
break;
} else {
F_93 ( V_117 , L_37 ,
F_233 ( V_62 ) ) ;
}
}
}
F_44 ( & V_26 ) ;
return 0 ;
}
static T_2 F_357 ( struct V_2 * V_3 , struct V_187 * V_235 )
{
return F_5 ( V_7 , & V_3 -> V_5 ) ;
}
static int F_358 ( struct V_81 * V_82 , struct V_2 * V_464 )
{
return F_199 ( V_464 , V_82 , V_467 ,
F_276 ( V_467 ) ) ;
}
