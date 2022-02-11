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
const struct V_184 * V_184 ;
int V_13 ;
F_28 ( V_69 -> V_175 != NULL ) ;
V_83 = F_119 ( V_69 ) ;
if ( V_83 )
goto V_185;
V_66 = V_69 -> V_175 -> V_93 ;
F_51 ( & V_66 -> V_94 ) ;
F_51 ( & V_1 ) ;
if ( strlen ( V_46 -> V_122 ) ) {
F_126 (existing_root) {
if ( ! strcmp ( V_183 -> V_122 , V_46 -> V_122 ) ) {
V_83 = - V_109 ;
F_53 ( & V_1 ) ;
F_53 ( & V_66 -> V_94 ) ;
goto V_185;
}
}
}
V_83 = F_33 ( V_28 , & V_55 ) ;
if ( V_83 ) {
F_53 ( & V_1 ) ;
F_53 ( & V_66 -> V_94 ) ;
goto V_185;
}
V_83 = F_88 ( V_46 , V_46 -> V_52 ) ;
if ( V_83 == - V_109 ) {
F_53 ( & V_1 ) ;
F_53 ( & V_66 -> V_94 ) ;
F_32 ( & V_55 ) ;
goto V_185;
}
F_28 ( V_83 ) ;
F_36 ( & V_46 -> V_149 , & V_186 ) ;
V_58 ++ ;
V_69 -> V_175 -> V_86 = V_182 ;
V_46 -> V_65 . V_85 = V_69 -> V_175 ;
F_13 ( & V_26 ) ;
for ( V_13 = 0 ; V_13 < V_187 ; V_13 ++ ) {
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
V_184 = F_127 ( & V_188 ) ;
F_102 ( V_182 ) ;
F_128 ( V_184 ) ;
F_53 ( & V_1 ) ;
F_53 ( & V_66 -> V_94 ) ;
} else {
F_115 ( V_127 . V_156 ) ;
F_100 ( V_127 . V_52 ) ;
}
F_21 ( V_127 . V_137 ) ;
F_21 ( V_127 . V_122 ) ;
return F_68 ( V_69 -> V_175 ) ;
V_185:
F_129 ( V_69 ) ;
V_181:
F_100 ( V_127 . V_52 ) ;
V_180:
F_21 ( V_127 . V_137 ) ;
F_21 ( V_127 . V_122 ) ;
return F_114 ( V_83 ) ;
}
static void F_130 ( struct V_68 * V_69 ) {
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
F_131 ( V_69 ) ;
F_115 ( V_46 ) ;
}
static inline struct V_2 * F_132 ( struct V_85 * V_85 )
{
return V_85 -> V_86 ;
}
static inline struct V_189 * F_133 ( struct V_85 * V_85 )
{
return V_85 -> V_86 ;
}
int F_134 ( const struct V_2 * V_3 , char * V_190 , int V_191 )
{
char * V_192 ;
struct V_85 * V_85 = F_135 ( V_3 -> V_85 ,
F_1 () ) ;
if ( ! V_85 || V_3 == V_110 ) {
strcpy ( V_190 , L_13 ) ;
return 0 ;
}
V_192 = V_190 + V_191 ;
* -- V_192 = '\0' ;
for (; ; ) {
int V_193 = V_85 -> V_194 . V_193 ;
if ( ( V_192 -= V_193 ) < V_190 )
return - V_195 ;
memcpy ( V_192 , V_85 -> V_194 . V_122 , V_193 ) ;
V_3 = V_3 -> V_91 ;
if ( ! V_3 )
break;
V_85 = F_135 ( V_3 -> V_85 ,
F_1 () ) ;
if ( ! V_3 -> V_91 )
continue;
if ( -- V_192 < V_190 )
return - V_195 ;
* V_192 = '/' ;
}
memmove ( V_190 , V_192 , V_190 + V_191 - V_192 ) ;
return 0 ;
}
static int F_136 ( struct V_2 * V_3 , struct V_2 * V_196 ,
struct V_61 * V_197 , bool V_198 )
{
struct V_19 * V_47 ;
struct V_19 * V_199 ;
F_137 ( V_197 ) ;
V_47 = V_197 -> V_63 ;
F_23 ( V_47 ) ;
F_138 ( V_197 ) ;
if ( V_198 ) {
struct V_11 * V_35 [ V_16 ] ;
F_43 ( & V_26 ) ;
V_199 = F_30 ( V_47 , V_3 , V_35 ) ;
F_28 ( ! V_199 ) ;
F_23 ( V_199 ) ;
F_44 ( & V_26 ) ;
} else {
F_139 () ;
V_199 = F_42 ( V_47 , V_3 ) ;
if ( ! V_199 ) {
F_25 ( V_47 ) ;
return - V_54 ;
}
}
F_25 ( V_47 ) ;
F_137 ( V_197 ) ;
if ( V_197 -> V_5 & V_200 ) {
F_138 ( V_197 ) ;
F_25 ( V_199 ) ;
return - V_201 ;
}
F_140 ( V_197 -> V_63 , V_199 ) ;
F_138 ( V_197 ) ;
F_13 ( & V_26 ) ;
if ( ! F_38 ( & V_197 -> V_202 ) )
F_40 ( & V_197 -> V_202 , & V_199 -> V_59 ) ;
F_15 ( & V_26 ) ;
F_25 ( V_47 ) ;
F_19 ( V_7 , & V_196 -> V_5 ) ;
return 0 ;
}
int F_141 ( struct V_2 * V_3 , struct V_61 * V_197 )
{
int V_203 ;
struct V_81 * V_82 , * V_204 = NULL ;
struct V_2 * V_196 ;
struct V_48 * V_46 = V_3 -> V_46 ;
V_196 = F_49 ( V_197 , V_46 ) ;
if ( V_3 == V_196 )
return 0 ;
F_60 (root, ss) {
if ( V_82 -> V_205 ) {
V_203 = V_82 -> V_205 ( V_82 , V_3 , V_197 ) ;
if ( V_203 ) {
V_204 = V_82 ;
goto V_206;
}
}
if ( V_82 -> V_207 ) {
V_203 = V_82 -> V_207 ( V_3 , V_197 ) ;
if ( V_203 ) {
V_204 = V_82 ;
goto V_206;
}
}
}
V_203 = F_136 ( V_3 , V_196 , V_197 , false ) ;
if ( V_203 )
goto V_206;
F_60 (root, ss) {
if ( V_82 -> V_208 )
V_82 -> V_208 ( V_3 ) ;
if ( V_82 -> V_209 )
V_82 -> V_209 ( V_3 , V_197 ) ;
if ( V_82 -> V_210 )
V_82 -> V_210 ( V_82 , V_3 , V_196 , V_197 ) ;
}
F_63 () ;
F_80 ( V_3 ) ;
V_206:
if ( V_203 ) {
F_60 (root, ss) {
if ( V_82 == V_204 )
break;
if ( V_82 -> V_211 )
V_82 -> V_211 ( V_82 , V_3 , V_197 ) ;
}
}
return V_203 ;
}
int F_142 ( struct V_61 * V_212 , struct V_61 * V_197 )
{
struct V_48 * V_46 ;
int V_203 = 0 ;
F_50 () ;
F_126 (root) {
struct V_2 * V_213 = F_49 ( V_212 , V_46 ) ;
V_203 = F_141 ( V_213 , V_197 ) ;
if ( V_203 )
break;
}
F_52 () ;
return V_203 ;
}
static bool F_143 ( struct V_2 * V_3 ,
struct V_61 * V_197 , struct V_19 * V_20 ,
struct V_36 * V_214 )
{
struct V_19 * V_199 ;
struct V_215 * V_216 ;
struct V_11 * V_35 [ V_16 ] ;
F_43 ( & V_26 ) ;
V_199 = F_30 ( V_20 , V_3 , V_35 ) ;
if ( V_199 )
F_23 ( V_199 ) ;
F_44 ( & V_26 ) ;
if ( ! V_199 )
return false ;
F_47 (cg_entry, newcg_list, links) {
if ( V_216 -> V_20 == V_199 ) {
F_25 ( V_199 ) ;
return true ;
}
}
F_25 ( V_199 ) ;
return false ;
}
static int F_144 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_36 * V_214 )
{
struct V_19 * V_199 ;
struct V_215 * V_216 ;
V_199 = F_42 ( V_20 , V_3 ) ;
if ( ! V_199 )
return - V_54 ;
V_216 = F_35 ( sizeof( struct V_215 ) , V_53 ) ;
if ( ! V_216 ) {
F_25 ( V_199 ) ;
return - V_54 ;
}
V_216 -> V_20 = V_199 ;
F_36 ( & V_216 -> V_217 , V_214 ) ;
return 0 ;
}
int F_145 ( struct V_2 * V_3 , struct V_61 * V_218 )
{
int V_203 , V_13 , V_219 ;
struct V_81 * V_82 , * V_204 = NULL ;
bool V_220 = false ;
struct V_2 * V_196 = NULL ;
struct V_19 * V_47 ;
struct V_48 * V_46 = V_3 -> V_46 ;
struct V_61 * V_197 ;
struct V_221 * V_222 ;
struct V_36 V_214 ;
struct V_215 * V_216 , * V_223 ;
V_219 = F_146 ( V_218 ) ;
V_222 = F_147 ( sizeof( struct V_61 * ) , V_219 ,
V_53 ) ;
if ( ! V_222 )
return - V_54 ;
V_203 = F_148 ( V_222 , 0 , V_219 - 1 , V_53 ) ;
if ( V_203 )
goto V_224;
F_149 () ;
if ( ! F_150 ( V_218 ) ) {
F_151 () ;
V_203 = - V_155 ;
goto V_224;
}
V_197 = V_218 ;
V_13 = 0 ;
do {
F_28 ( V_13 >= V_219 ) ;
F_152 ( V_197 ) ;
V_203 = F_153 ( V_222 , V_13 , V_197 , V_225 ) ;
F_28 ( V_203 != 0 ) ;
V_13 ++ ;
} while_each_thread(leader, tsk) ;
int F_154 ( struct V_2 * V_3 , T_2 V_226 , bool V_227 )
{
struct V_61 * V_197 ;
const struct V_184 * V_184 = F_155 () , * V_228 ;
int V_83 ;
if ( ! F_156 ( V_3 ) )
return - V_229 ;
if ( V_226 ) {
F_149 () ;
V_197 = F_157 ( V_226 ) ;
if ( ! V_197 ) {
F_151 () ;
F_52 () ;
return - V_201 ;
}
if ( V_227 ) {
V_197 = V_197 -> V_230 ;
} else if ( V_197 -> V_5 & V_200 ) {
F_151 () ;
F_52 () ;
return - V_201 ;
}
V_228 = F_158 ( V_197 ) ;
if ( V_184 -> V_231 &&
V_184 -> V_231 != V_228 -> V_232 &&
V_184 -> V_231 != V_228 -> V_233 ) {
F_151 () ;
F_52 () ;
return - V_234 ;
}
F_152 ( V_197 ) ;
F_151 () ;
} else {
if ( V_227 )
V_197 = V_235 -> V_230 ;
else
V_197 = V_235 ;
F_152 ( V_197 ) ;
}
if ( V_227 ) {
F_159 ( V_197 ) ;
V_83 = F_145 ( V_3 , V_197 ) ;
F_160 ( V_197 ) ;
} else {
V_83 = F_141 ( V_3 , V_197 ) ;
}
F_161 ( V_197 ) ;
F_52 () ;
return V_83 ;
}
static int F_162 ( struct V_2 * V_3 , struct V_189 * V_236 , T_2 V_226 )
{
return F_154 ( V_3 , V_226 , false ) ;
}
static int F_163 ( struct V_2 * V_3 , struct V_189 * V_236 , T_2 V_237 )
{
int V_83 ;
do {
V_83 = F_154 ( V_3 , V_237 , true ) ;
} while ( V_83 == - V_155 );
return V_83 ;
}
bool F_156 ( struct V_2 * V_3 )
{
F_51 ( & V_1 ) ;
if ( F_4 ( V_3 ) ) {
F_53 ( & V_1 ) ;
return false ;
}
return true ;
}
static int F_164 ( struct V_2 * V_3 , struct V_189 * V_236 ,
const char * V_238 )
{
F_165 ( sizeof( V_3 -> V_46 -> V_124 ) < V_138 ) ;
if ( strlen ( V_238 ) >= V_138 )
return - V_135 ;
if ( ! F_156 ( V_3 ) )
return - V_229 ;
strcpy ( V_3 -> V_46 -> V_124 , V_238 ) ;
F_52 () ;
return 0 ;
}
static int F_166 ( struct V_2 * V_3 , struct V_189 * V_236 ,
struct V_116 * V_117 )
{
if ( ! F_156 ( V_3 ) )
return - V_229 ;
F_94 ( V_117 , V_3 -> V_46 -> V_124 ) ;
F_167 ( V_117 , '\n' ) ;
F_52 () ;
return 0 ;
}
static T_3 F_168 ( struct V_2 * V_3 , struct V_189 * V_236 ,
struct V_239 * V_239 ,
const char T_4 * V_240 ,
T_5 V_241 , T_6 * V_242 )
{
char V_238 [ V_243 ] ;
int V_203 = 0 ;
char * V_244 ;
if ( ! V_241 )
return - V_135 ;
if ( V_241 >= sizeof( V_238 ) )
return - V_245 ;
if ( F_169 ( V_238 , V_240 , V_241 ) )
return - V_246 ;
V_238 [ V_241 ] = 0 ;
if ( V_236 -> V_247 ) {
T_2 V_248 = F_170 ( F_171 ( V_238 ) , & V_244 , 0 ) ;
if ( * V_244 )
return - V_135 ;
V_203 = V_236 -> V_247 ( V_3 , V_236 , V_248 ) ;
} else {
T_7 V_248 = F_172 ( F_171 ( V_238 ) , & V_244 , 0 ) ;
if ( * V_244 )
return - V_135 ;
V_203 = V_236 -> V_249 ( V_3 , V_236 , V_248 ) ;
}
if ( ! V_203 )
V_203 = V_241 ;
return V_203 ;
}
static T_3 F_173 ( struct V_2 * V_3 , struct V_189 * V_236 ,
struct V_239 * V_239 ,
const char T_4 * V_240 ,
T_5 V_241 , T_6 * V_242 )
{
char V_250 [ V_243 ] ;
int V_203 = 0 ;
T_5 V_251 = V_236 -> V_252 ;
char * V_238 = V_250 ;
if ( ! V_251 )
V_251 = sizeof( V_250 ) - 1 ;
if ( V_241 >= V_251 )
return - V_245 ;
if ( V_241 >= sizeof( V_250 ) ) {
V_238 = F_35 ( V_241 + 1 , V_53 ) ;
if ( V_238 == NULL )
return - V_54 ;
}
if ( V_241 && F_169 ( V_238 , V_240 , V_241 ) ) {
V_203 = - V_246 ;
goto V_206;
}
V_238 [ V_241 ] = 0 ;
V_203 = V_236 -> V_253 ( V_3 , V_236 , F_171 ( V_238 ) ) ;
if ( ! V_203 )
V_203 = V_241 ;
V_206:
if ( V_238 != V_250 )
F_21 ( V_238 ) ;
return V_203 ;
}
static T_3 F_174 ( struct V_239 * V_239 , const char T_4 * V_190 ,
T_5 V_241 , T_6 * V_254 )
{
struct V_189 * V_236 = F_133 ( V_239 -> V_255 ) ;
struct V_2 * V_3 = F_132 ( V_239 -> V_255 -> V_92 ) ;
if ( F_4 ( V_3 ) )
return - V_229 ;
if ( V_236 -> V_256 )
return V_236 -> V_256 ( V_3 , V_236 , V_239 , V_190 , V_241 , V_254 ) ;
if ( V_236 -> V_247 || V_236 -> V_249 )
return F_168 ( V_3 , V_236 , V_239 , V_190 , V_241 , V_254 ) ;
if ( V_236 -> V_253 )
return F_173 ( V_3 , V_236 , V_239 , V_190 , V_241 , V_254 ) ;
if ( V_236 -> V_257 ) {
int V_83 = V_236 -> V_257 ( V_3 , ( unsigned int ) V_236 -> V_258 ) ;
return V_83 ? V_83 : V_241 ;
}
return - V_135 ;
}
static T_3 F_175 ( struct V_2 * V_3 , struct V_189 * V_236 ,
struct V_239 * V_239 ,
char T_4 * V_190 , T_5 V_241 ,
T_6 * V_254 )
{
char V_15 [ V_243 ] ;
T_2 V_248 = V_236 -> V_259 ( V_3 , V_236 ) ;
int V_193 = sprintf ( V_15 , L_14 , ( unsigned long long ) V_248 ) ;
return F_176 ( V_190 , V_241 , V_254 , V_15 , V_193 ) ;
}
static T_3 F_177 ( struct V_2 * V_3 , struct V_189 * V_236 ,
struct V_239 * V_239 ,
char T_4 * V_190 , T_5 V_241 ,
T_6 * V_254 )
{
char V_15 [ V_243 ] ;
T_7 V_248 = V_236 -> V_260 ( V_3 , V_236 ) ;
int V_193 = sprintf ( V_15 , L_15 , ( long long ) V_248 ) ;
return F_176 ( V_190 , V_241 , V_254 , V_15 , V_193 ) ;
}
static T_3 F_178 ( struct V_239 * V_239 , char T_4 * V_190 ,
T_5 V_241 , T_6 * V_254 )
{
struct V_189 * V_236 = F_133 ( V_239 -> V_255 ) ;
struct V_2 * V_3 = F_132 ( V_239 -> V_255 -> V_92 ) ;
if ( F_4 ( V_3 ) )
return - V_229 ;
if ( V_236 -> V_261 )
return V_236 -> V_261 ( V_3 , V_236 , V_239 , V_190 , V_241 , V_254 ) ;
if ( V_236 -> V_259 )
return F_175 ( V_3 , V_236 , V_239 , V_190 , V_241 , V_254 ) ;
if ( V_236 -> V_260 )
return F_177 ( V_3 , V_236 , V_239 , V_190 , V_241 , V_254 ) ;
return - V_135 ;
}
static int F_179 ( struct V_262 * V_263 , const char * V_264 , T_2 V_265 )
{
struct V_116 * V_266 = V_263 -> V_267 ;
return F_93 ( V_266 , L_16 , V_264 , ( unsigned long long ) V_265 ) ;
}
static int F_180 ( struct V_116 * V_268 , void * V_269 )
{
struct V_270 * V_267 = V_268 -> V_258 ;
struct V_189 * V_236 = V_267 -> V_236 ;
if ( V_236 -> V_271 ) {
struct V_262 V_263 = {
. V_272 = F_179 ,
. V_267 = V_268 ,
} ;
return V_236 -> V_271 ( V_267 -> V_2 , V_236 , & V_263 ) ;
}
return V_236 -> V_273 ( V_267 -> V_2 , V_236 , V_268 ) ;
}
static int F_181 ( struct V_66 * V_66 , struct V_239 * V_239 )
{
struct V_116 * V_117 = V_239 -> V_274 ;
F_21 ( V_117 -> V_258 ) ;
return F_182 ( V_66 , V_239 ) ;
}
static int F_183 ( struct V_66 * V_66 , struct V_239 * V_239 )
{
int V_275 ;
struct V_189 * V_236 ;
V_275 = F_184 ( V_66 , V_239 ) ;
if ( V_275 )
return V_275 ;
V_236 = F_133 ( V_239 -> V_255 ) ;
if ( V_236 -> V_271 || V_236 -> V_273 ) {
struct V_270 * V_267 =
F_113 ( sizeof( * V_267 ) , V_276 ) ;
if ( ! V_267 )
return - V_54 ;
V_267 -> V_236 = V_236 ;
V_267 -> V_2 = F_132 ( V_239 -> V_255 -> V_92 ) ;
V_239 -> V_277 = & V_278 ;
V_275 = F_185 ( V_239 , F_180 , V_267 ) ;
if ( V_275 < 0 )
F_21 ( V_267 ) ;
} else if ( V_236 -> V_279 )
V_275 = V_236 -> V_279 ( V_66 , V_239 ) ;
else
V_275 = 0 ;
return V_275 ;
}
static int F_186 ( struct V_66 * V_66 , struct V_239 * V_239 )
{
struct V_189 * V_236 = F_133 ( V_239 -> V_255 ) ;
if ( V_236 -> V_280 )
return V_236 -> V_280 ( V_66 , V_239 ) ;
return 0 ;
}
static int F_187 ( struct V_66 * V_281 , struct V_85 * V_282 ,
struct V_66 * V_283 , struct V_85 * V_284 )
{
if ( ! F_62 ( V_282 -> V_93 -> V_71 ) )
return - V_285 ;
if ( V_284 -> V_93 )
return - V_286 ;
if ( V_281 != V_283 )
return - V_287 ;
return F_188 ( V_281 , V_282 , V_283 , V_284 ) ;
}
static struct V_85 * F_189 ( struct V_66 * V_288 , struct V_85 * V_85 , struct V_289 * V_290 )
{
if ( V_85 -> V_194 . V_193 > V_291 )
return F_114 ( - V_195 ) ;
F_190 ( V_85 , NULL ) ;
return NULL ;
}
static inline struct V_189 * F_191 ( struct V_239 * V_239 )
{
if ( V_239 -> V_255 -> V_93 -> V_171 != & V_292 )
return F_114 ( - V_135 ) ;
return F_133 ( V_239 -> V_255 ) ;
}
static int F_192 ( struct V_85 * V_85 , T_1 V_67 ,
struct V_68 * V_69 )
{
struct V_66 * V_66 ;
if ( ! V_85 )
return - V_141 ;
if ( V_85 -> V_93 )
return - V_286 ;
V_66 = F_54 ( V_67 , V_69 ) ;
if ( ! V_66 )
return - V_54 ;
if ( F_62 ( V_67 ) ) {
V_66 -> V_173 = & V_174 ;
V_66 -> V_171 = & V_172 ;
F_120 ( V_66 ) ;
F_193 ( & V_66 -> V_94 , V_293 ) ;
} else if ( F_194 ( V_67 ) ) {
V_66 -> V_294 = 0 ;
V_66 -> V_171 = & V_292 ;
}
F_195 ( V_85 , V_66 ) ;
F_68 ( V_85 ) ;
return 0 ;
}
static int F_196 ( struct V_2 * V_3 , struct V_85 * V_85 ,
T_1 V_67 )
{
struct V_85 * V_91 ;
int error = 0 ;
V_91 = V_3 -> V_91 -> V_85 ;
error = F_192 ( V_85 , V_100 | V_67 , V_3 -> V_46 -> V_69 ) ;
if ( ! error ) {
V_85 -> V_86 = V_3 ;
F_120 ( V_91 -> V_93 ) ;
F_140 ( V_3 -> V_85 , V_85 ) ;
F_68 ( V_85 ) ;
}
F_71 ( V_85 ) ;
return error ;
}
static T_1 F_197 ( const struct V_189 * V_236 )
{
T_1 V_67 = 0 ;
if ( V_236 -> V_67 )
return V_236 -> V_67 ;
if ( V_236 -> V_261 || V_236 -> V_259 || V_236 -> V_260 ||
V_236 -> V_271 || V_236 -> V_273 )
V_67 |= V_168 ;
if ( V_236 -> V_256 || V_236 -> V_247 || V_236 -> V_249 ||
V_236 -> V_253 || V_236 -> V_257 )
V_67 |= V_170 ;
return V_67 ;
}
int F_198 ( struct V_2 * V_3 ,
struct V_81 * V_39 ,
const struct V_189 * V_236 )
{
struct V_85 * V_288 = V_3 -> V_85 ;
struct V_85 * V_85 ;
int error ;
T_1 V_67 ;
char V_122 [ V_295 + V_296 + 2 ] = { 0 } ;
if ( V_39 && ! F_5 ( V_123 , & V_3 -> V_46 -> V_5 ) ) {
strcpy ( V_122 , V_39 -> V_122 ) ;
strcat ( V_122 , L_17 ) ;
}
strcat ( V_122 , V_236 -> V_122 ) ;
F_28 ( ! F_3 ( & V_288 -> V_93 -> V_94 ) ) ;
V_85 = F_199 ( V_122 , V_288 , strlen ( V_122 ) ) ;
if ( ! F_123 ( V_85 ) ) {
V_67 = F_197 ( V_236 ) ;
error = F_192 ( V_85 , V_67 | V_297 ,
V_3 -> V_46 -> V_69 ) ;
if ( ! error )
V_85 -> V_86 = ( void * ) V_236 ;
F_71 ( V_85 ) ;
} else
error = F_124 ( V_85 ) ;
return error ;
}
int F_200 ( struct V_2 * V_3 ,
struct V_81 * V_39 ,
const struct V_189 V_236 [] ,
int V_31 )
{
int V_13 , V_275 ;
for ( V_13 = 0 ; V_13 < V_31 ; V_13 ++ ) {
V_275 = F_198 ( V_3 , V_39 , & V_236 [ V_13 ] ) ;
if ( V_275 )
return V_275 ;
}
return 0 ;
}
int F_201 ( const struct V_2 * V_3 )
{
int V_31 = 0 ;
struct V_22 * V_23 ;
F_43 ( & V_26 ) ;
F_47 (link, &cgrp->css_sets, cgrp_link_list) {
V_31 += F_202 ( & V_23 -> V_20 -> V_25 ) ;
}
F_44 ( & V_26 ) ;
return V_31 ;
}
static void F_203 ( struct V_2 * V_3 ,
struct V_298 * V_299 )
{
struct V_36 * V_300 = V_299 -> V_301 ;
struct V_22 * V_23 ;
struct V_19 * V_20 ;
do {
V_300 = V_300 -> V_45 ;
if ( V_300 == & V_3 -> V_56 ) {
V_299 -> V_301 = NULL ;
return;
}
V_23 = F_29 ( V_300 , struct V_22 , V_30 ) ;
V_20 = V_23 -> V_20 ;
} while ( F_38 ( & V_20 -> V_59 ) );
V_299 -> V_301 = V_300 ;
V_299 -> V_62 = V_20 -> V_59 . V_45 ;
}
static void F_204 ( void )
{
struct V_61 * V_302 , * V_303 ;
F_13 ( & V_26 ) ;
V_304 = 1 ;
F_205 (g, p) {
F_137 ( V_302 ) ;
if ( ! ( V_302 -> V_5 & V_200 ) && F_38 ( & V_302 -> V_202 ) )
F_36 ( & V_302 -> V_202 , & V_302 -> V_63 -> V_59 ) ;
F_138 ( V_302 ) ;
} F_206 ( V_303 , V_302 ) ;
F_15 ( & V_26 ) ;
}
void F_207 ( struct V_2 * V_3 , struct V_298 * V_299 )
{
if ( ! V_304 )
F_204 () ;
F_43 ( & V_26 ) ;
V_299 -> V_301 = & V_3 -> V_56 ;
F_203 ( V_3 , V_299 ) ;
}
struct V_61 * F_208 ( struct V_2 * V_3 ,
struct V_298 * V_299 )
{
struct V_61 * V_57 ;
struct V_36 * V_300 = V_299 -> V_62 ;
struct V_22 * V_23 ;
if ( ! V_299 -> V_301 )
return NULL ;
V_57 = F_29 ( V_300 , struct V_61 , V_202 ) ;
V_300 = V_300 -> V_45 ;
V_23 = F_29 ( V_299 -> V_301 , struct V_22 , V_30 ) ;
if ( V_300 == & V_23 -> V_20 -> V_59 ) {
F_203 ( V_3 , V_299 ) ;
} else {
V_299 -> V_62 = V_300 ;
}
return V_57 ;
}
void F_209 ( struct V_2 * V_3 , struct V_298 * V_299 )
{
F_44 ( & V_26 ) ;
}
static inline int F_210 ( struct V_61 * V_305 ,
struct V_306 * time ,
struct V_61 * V_307 )
{
int V_308 = F_211 ( & V_305 -> V_309 , time ) ;
if ( V_308 > 0 ) {
return 1 ;
} else if ( V_308 < 0 ) {
return 0 ;
} else {
return V_305 > V_307 ;
}
}
static inline int F_212 ( void * V_310 , void * V_311 )
{
struct V_61 * V_305 = V_310 ;
struct V_61 * V_307 = V_311 ;
return F_210 ( V_305 , & V_307 -> V_309 , V_307 ) ;
}
int F_213 ( struct V_312 * V_313 )
{
int V_203 , V_13 ;
struct V_298 V_299 ;
struct V_61 * V_302 , * V_314 ;
struct V_61 * V_315 = NULL ;
struct V_316 V_317 ;
struct V_316 * V_318 ;
struct V_306 V_319 = { 0 , 0 } ;
if ( V_313 -> V_318 ) {
V_318 = V_313 -> V_318 ;
V_318 -> V_320 = & F_212 ;
} else {
V_318 = & V_317 ;
V_203 = F_214 ( V_318 , V_321 , V_53 , & F_212 ) ;
if ( V_203 )
return V_203 ;
}
V_322:
V_318 -> V_323 = 0 ;
F_207 ( V_313 -> V_20 , & V_299 ) ;
while ( ( V_302 = F_208 ( V_313 -> V_20 , & V_299 ) ) ) {
if ( V_313 -> V_324 && ! V_313 -> V_324 ( V_302 , V_313 ) )
continue;
if ( ! F_210 ( V_302 , & V_319 , V_315 ) )
continue;
V_314 = F_215 ( V_318 , V_302 ) ;
if ( V_314 == NULL ) {
F_152 ( V_302 ) ;
} else if ( V_314 != V_302 ) {
F_152 ( V_302 ) ;
F_161 ( V_314 ) ;
}
}
F_209 ( V_313 -> V_20 , & V_299 ) ;
if ( V_318 -> V_323 ) {
for ( V_13 = 0 ; V_13 < V_318 -> V_323 ; V_13 ++ ) {
struct V_61 * V_325 = V_318 -> V_326 [ V_13 ] ;
if ( V_13 == 0 ) {
V_319 = V_325 -> V_309 ;
V_315 = V_325 ;
}
V_313 -> V_327 ( V_325 , V_313 ) ;
F_161 ( V_325 ) ;
}
goto V_322;
}
if ( V_318 == & V_317 )
F_216 ( & V_317 ) ;
return 0 ;
}
static void * F_217 ( int V_31 )
{
if ( F_218 ( V_31 ) )
return F_219 ( V_31 * sizeof( V_328 ) ) ;
else
return F_35 ( V_31 * sizeof( V_328 ) , V_53 ) ;
}
static void F_220 ( void * V_302 )
{
if ( F_221 ( V_302 ) )
F_222 ( V_302 ) ;
else
F_21 ( V_302 ) ;
}
static void * F_223 ( void * V_302 , int V_329 )
{
void * V_330 ;
if ( F_221 ( V_302 ) ) {
V_330 = F_219 ( V_329 * sizeof( V_328 ) ) ;
if ( ! V_330 )
return NULL ;
memcpy ( V_330 , V_302 , V_329 * sizeof( V_328 ) ) ;
F_222 ( V_302 ) ;
} else {
V_330 = F_224 ( V_302 , V_329 * sizeof( V_328 ) , V_53 ) ;
}
return V_330 ;
}
static int F_225 ( V_328 * * V_302 , int V_331 )
{
int V_332 , V_333 = 1 ;
V_328 * V_334 = * V_302 ;
V_328 * V_330 ;
if ( V_331 == 0 || V_331 == 1 )
return V_331 ;
for ( V_332 = 1 ; V_332 < V_331 ; V_332 ++ ) {
while ( V_334 [ V_332 ] == V_334 [ V_332 - 1 ] ) {
V_332 ++ ;
if ( V_332 == V_331 )
goto V_335;
}
V_334 [ V_333 ] = V_334 [ V_332 ] ;
V_333 ++ ;
}
V_335:
if ( F_226 ( V_331 , V_333 ) ) {
V_330 = F_223 ( V_334 , V_333 ) ;
if ( V_330 )
* V_302 = V_330 ;
}
return V_333 ;
}
static int F_227 ( const void * V_336 , const void * V_337 )
{
return * ( V_328 * ) V_336 - * ( V_328 * ) V_337 ;
}
static struct V_338 * F_228 ( struct V_2 * V_3 ,
enum V_339 type )
{
struct V_338 * V_300 ;
struct V_340 * V_341 = V_235 -> V_342 -> V_343 ;
F_51 ( & V_3 -> V_146 ) ;
F_47 (l, &cgrp->pidlists, links) {
if ( V_300 -> V_264 . type == type && V_300 -> V_264 . V_341 == V_341 ) {
F_229 ( & V_300 -> V_344 ) ;
F_53 ( & V_3 -> V_146 ) ;
return V_300 ;
}
}
V_300 = F_35 ( sizeof( struct V_338 ) , V_53 ) ;
if ( ! V_300 ) {
F_53 ( & V_3 -> V_146 ) ;
return V_300 ;
}
F_230 ( & V_300 -> V_344 ) ;
F_229 ( & V_300 -> V_344 ) ;
V_300 -> V_264 . type = type ;
V_300 -> V_264 . V_341 = F_231 ( V_341 ) ;
V_300 -> V_345 = 0 ;
V_300 -> V_334 = NULL ;
V_300 -> V_346 = V_3 ;
F_36 ( & V_300 -> V_217 , & V_3 -> V_89 ) ;
F_53 ( & V_3 -> V_146 ) ;
return V_300 ;
}
static int F_232 ( struct V_2 * V_3 , enum V_339 type ,
struct V_338 * * V_347 )
{
V_328 * V_348 ;
int V_331 ;
int V_226 , V_349 = 0 ;
struct V_298 V_299 ;
struct V_61 * V_197 ;
struct V_338 * V_300 ;
V_331 = F_201 ( V_3 ) ;
V_348 = F_217 ( V_331 ) ;
if ( ! V_348 )
return - V_54 ;
F_207 ( V_3 , & V_299 ) ;
while ( ( V_197 = F_208 ( V_3 , & V_299 ) ) ) {
if ( F_81 ( V_349 == V_331 ) )
break;
if ( type == V_350 )
V_226 = F_233 ( V_197 ) ;
else
V_226 = F_234 ( V_197 ) ;
if ( V_226 > 0 )
V_348 [ V_349 ++ ] = V_226 ;
}
F_209 ( V_3 , & V_299 ) ;
V_331 = V_349 ;
F_235 ( V_348 , V_331 , sizeof( V_328 ) , F_227 , NULL ) ;
if ( type == V_350 )
V_331 = F_225 ( & V_348 , V_331 ) ;
V_300 = F_228 ( V_3 , type ) ;
if ( ! V_300 ) {
F_220 ( V_348 ) ;
return - V_54 ;
}
F_220 ( V_300 -> V_334 ) ;
V_300 -> V_334 = V_348 ;
V_300 -> V_331 = V_331 ;
V_300 -> V_345 ++ ;
F_236 ( & V_300 -> V_344 ) ;
* V_347 = V_300 ;
return 0 ;
}
int F_237 ( struct V_351 * V_352 , struct V_85 * V_85 )
{
int V_83 = - V_135 ;
struct V_2 * V_3 ;
struct V_298 V_299 ;
struct V_61 * V_197 ;
if ( V_85 -> V_353 -> V_163 != & V_164 ||
! F_62 ( V_85 -> V_93 -> V_71 ) )
goto V_275;
V_83 = 0 ;
V_3 = V_85 -> V_86 ;
F_207 ( V_3 , & V_299 ) ;
while ( ( V_197 = F_208 ( V_3 , & V_299 ) ) ) {
switch ( V_197 -> V_267 ) {
case V_354 :
V_352 -> V_355 ++ ;
break;
case V_356 :
V_352 -> V_357 ++ ;
break;
case V_358 :
V_352 -> V_359 ++ ;
break;
case V_360 :
V_352 -> V_361 ++ ;
break;
default:
if ( F_238 ( V_197 ) )
V_352 -> V_362 ++ ;
break;
}
}
F_209 ( V_3 , & V_299 ) ;
V_275:
return V_83 ;
}
static void * F_239 ( struct V_116 * V_363 , T_6 * V_364 )
{
struct V_338 * V_300 = V_363 -> V_258 ;
int V_14 = 0 , V_226 = * V_364 ;
int * V_365 ;
F_240 ( & V_300 -> V_344 ) ;
if ( V_226 ) {
int V_244 = V_300 -> V_331 ;
while ( V_14 < V_244 ) {
int V_366 = ( V_14 + V_244 ) / 2 ;
if ( V_300 -> V_334 [ V_366 ] == V_226 ) {
V_14 = V_366 ;
break;
} else if ( V_300 -> V_334 [ V_366 ] <= V_226 )
V_14 = V_366 + 1 ;
else
V_244 = V_366 ;
}
}
if ( V_14 >= V_300 -> V_331 )
return NULL ;
V_365 = V_300 -> V_334 + V_14 ;
* V_364 = * V_365 ;
return V_365 ;
}
static void F_241 ( struct V_116 * V_363 , void * V_367 )
{
struct V_338 * V_300 = V_363 -> V_258 ;
F_242 ( & V_300 -> V_344 ) ;
}
static void * F_243 ( struct V_116 * V_363 , void * V_367 , T_6 * V_364 )
{
struct V_338 * V_300 = V_363 -> V_258 ;
V_328 * V_302 = V_367 ;
V_328 * V_244 = V_300 -> V_334 + V_300 -> V_331 ;
V_302 ++ ;
if ( V_302 >= V_244 ) {
return NULL ;
} else {
* V_364 = * V_302 ;
return V_302 ;
}
}
static int F_244 ( struct V_116 * V_363 , void * V_367 )
{
return F_93 ( V_363 , L_18 , * ( int * ) V_367 ) ;
}
static void F_245 ( struct V_338 * V_300 )
{
F_51 ( & V_300 -> V_346 -> V_146 ) ;
F_229 ( & V_300 -> V_344 ) ;
F_28 ( ! V_300 -> V_345 ) ;
if ( ! -- V_300 -> V_345 ) {
F_18 ( & V_300 -> V_217 ) ;
F_53 ( & V_300 -> V_346 -> V_146 ) ;
F_220 ( V_300 -> V_334 ) ;
F_246 ( V_300 -> V_264 . V_341 ) ;
F_236 ( & V_300 -> V_344 ) ;
F_21 ( V_300 ) ;
return;
}
F_53 ( & V_300 -> V_346 -> V_146 ) ;
F_236 ( & V_300 -> V_344 ) ;
}
static int F_247 ( struct V_66 * V_66 , struct V_239 * V_239 )
{
struct V_338 * V_300 ;
if ( ! ( V_239 -> V_368 & V_369 ) )
return 0 ;
V_300 = ( (struct V_116 * ) V_239 -> V_274 ) -> V_258 ;
F_245 ( V_300 ) ;
return F_248 ( V_66 , V_239 ) ;
}
static int F_249 ( struct V_239 * V_239 , enum V_339 type )
{
struct V_2 * V_3 = F_132 ( V_239 -> V_255 -> V_92 ) ;
struct V_338 * V_300 ;
int V_203 ;
if ( ! ( V_239 -> V_368 & V_369 ) )
return 0 ;
V_203 = F_232 ( V_3 , type , & V_300 ) ;
if ( V_203 )
return V_203 ;
V_239 -> V_277 = & V_370 ;
V_203 = F_250 ( V_239 , & V_371 ) ;
if ( V_203 ) {
F_245 ( V_300 ) ;
return V_203 ;
}
( (struct V_116 * ) V_239 -> V_274 ) -> V_258 = V_300 ;
return 0 ;
}
static int F_251 ( struct V_66 * V_372 , struct V_239 * V_239 )
{
return F_249 ( V_239 , V_373 ) ;
}
static int F_252 ( struct V_66 * V_372 , struct V_239 * V_239 )
{
return F_249 ( V_239 , V_350 ) ;
}
static T_2 F_253 ( struct V_2 * V_3 ,
struct V_189 * V_236 )
{
return F_7 ( V_3 ) ;
}
static int F_254 ( struct V_2 * V_3 ,
struct V_189 * V_236 ,
T_2 V_248 )
{
F_255 ( V_7 , & V_3 -> V_5 ) ;
if ( V_248 )
F_19 ( V_8 , & V_3 -> V_5 ) ;
else
F_255 ( V_8 , & V_3 -> V_5 ) ;
return 0 ;
}
static void F_256 ( struct V_374 * V_375 )
{
struct V_376 * V_377 = F_257 ( V_375 , struct V_376 ,
remove ) ;
struct V_2 * V_3 = V_377 -> V_3 ;
V_377 -> V_236 -> V_378 ( V_3 , V_377 -> V_236 , V_377 -> V_379 ) ;
F_258 ( V_377 -> V_379 ) ;
F_21 ( V_377 ) ;
F_71 ( V_3 -> V_85 ) ;
}
static int F_259 ( T_8 * V_380 , unsigned V_67 ,
int V_381 , void * V_264 )
{
struct V_376 * V_377 = F_257 ( V_380 ,
struct V_376 , V_380 ) ;
struct V_2 * V_3 = V_377 -> V_3 ;
unsigned long V_5 = ( unsigned long ) V_264 ;
if ( V_5 & V_382 ) {
F_260 ( V_377 -> V_383 , & V_377 -> V_380 ) ;
F_73 ( & V_3 -> V_148 ) ;
F_18 ( & V_377 -> V_334 ) ;
F_77 ( & V_3 -> V_148 ) ;
F_261 ( & V_377 -> remove ) ;
}
return 0 ;
}
static void F_262 ( struct V_239 * V_239 ,
T_9 * V_383 , T_10 * V_384 )
{
struct V_376 * V_377 = F_257 ( V_384 ,
struct V_376 , V_384 ) ;
V_377 -> V_383 = V_383 ;
F_263 ( V_383 , & V_377 -> V_380 ) ;
}
static int F_264 ( struct V_2 * V_3 , struct V_189 * V_236 ,
const char * V_238 )
{
struct V_376 * V_377 = NULL ;
unsigned int V_385 , V_386 ;
struct V_239 * V_387 = NULL ;
struct V_239 * V_388 = NULL ;
char * V_389 ;
int V_83 ;
V_385 = F_265 ( V_238 , & V_389 , 10 ) ;
if ( * V_389 != ' ' )
return - V_135 ;
V_238 = V_389 + 1 ;
V_386 = F_265 ( V_238 , & V_389 , 10 ) ;
if ( ( * V_389 != ' ' ) && ( * V_389 != '\0' ) )
return - V_135 ;
V_238 = V_389 + 1 ;
V_377 = F_113 ( sizeof( * V_377 ) , V_53 ) ;
if ( ! V_377 )
return - V_54 ;
V_377 -> V_3 = V_3 ;
F_34 ( & V_377 -> V_334 ) ;
F_266 ( & V_377 -> V_384 , F_262 ) ;
F_267 ( & V_377 -> V_380 , F_259 ) ;
F_268 ( & V_377 -> remove , F_256 ) ;
V_387 = F_269 ( V_385 ) ;
if ( F_123 ( V_387 ) ) {
V_83 = F_124 ( V_387 ) ;
goto V_390;
}
V_377 -> V_379 = F_270 ( V_387 ) ;
if ( F_123 ( V_377 -> V_379 ) ) {
V_83 = F_124 ( V_377 -> V_379 ) ;
goto V_390;
}
V_388 = F_271 ( V_386 ) ;
if ( ! V_388 ) {
V_83 = - V_391 ;
goto V_390;
}
V_83 = F_272 ( V_388 -> V_392 . V_85 -> V_93 , V_393 ) ;
if ( V_83 < 0 )
goto V_390;
V_377 -> V_236 = F_191 ( V_388 ) ;
if ( F_123 ( V_377 -> V_236 ) ) {
V_83 = F_124 ( V_377 -> V_236 ) ;
goto V_390;
}
if ( ! V_377 -> V_236 -> V_394 || ! V_377 -> V_236 -> V_378 ) {
V_83 = - V_135 ;
goto V_390;
}
V_83 = V_377 -> V_236 -> V_394 ( V_3 , V_377 -> V_236 ,
V_377 -> V_379 , V_238 ) ;
if ( V_83 )
goto V_390;
if ( V_387 -> V_277 -> V_395 ( V_387 , & V_377 -> V_384 ) & V_382 ) {
V_377 -> V_236 -> V_378 ( V_3 , V_377 -> V_236 , V_377 -> V_379 ) ;
V_83 = 0 ;
goto V_390;
}
F_68 ( V_3 -> V_85 ) ;
F_73 ( & V_3 -> V_148 ) ;
F_36 ( & V_377 -> V_334 , & V_3 -> V_147 ) ;
F_77 ( & V_3 -> V_148 ) ;
F_273 ( V_388 ) ;
F_273 ( V_387 ) ;
return 0 ;
V_390:
if ( V_388 )
F_273 ( V_388 ) ;
if ( V_377 && V_377 -> V_379 && ! F_123 ( V_377 -> V_379 ) )
F_258 ( V_377 -> V_379 ) ;
if ( ! F_274 ( V_387 ) )
F_273 ( V_387 ) ;
F_21 ( V_377 ) ;
return V_83 ;
}
static T_2 F_275 ( struct V_2 * V_3 ,
struct V_189 * V_236 )
{
return F_8 ( V_3 ) ;
}
static int F_276 ( struct V_2 * V_3 ,
struct V_189 * V_236 ,
T_2 V_248 )
{
if ( V_248 )
F_19 ( V_9 , & V_3 -> V_5 ) ;
else
F_255 ( V_9 , & V_3 -> V_5 ) ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 )
{
int V_275 ;
struct V_81 * V_82 ;
F_72 ( V_3 -> V_85 ) ;
V_275 = F_200 ( V_3 , NULL , V_396 , F_277 ( V_396 ) ) ;
if ( V_275 < 0 )
return V_275 ;
if ( V_3 == V_3 -> V_65 ) {
if ( ( V_275 = F_198 ( V_3 , NULL , & V_397 ) ) < 0 )
return V_275 ;
}
F_60 (cgrp->root, ss) {
if ( V_82 -> V_398 && ( V_275 = V_82 -> V_398 ( V_82 , V_3 ) ) < 0 )
return V_275 ;
}
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_399 ] ;
if ( V_12 -> V_400 )
F_140 ( V_12 -> V_400 -> V_12 , V_12 ) ;
}
return 0 ;
}
static void F_278 ( struct V_11 * V_12 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
V_12 -> V_2 = V_3 ;
F_45 ( & V_12 -> V_401 , 1 ) ;
V_12 -> V_5 = 0 ;
V_12 -> V_400 = NULL ;
if ( V_3 == V_110 )
F_19 ( V_402 , & V_12 -> V_5 ) ;
F_28 ( V_3 -> V_39 [ V_82 -> V_399 ] ) ;
V_3 -> V_39 [ V_82 -> V_399 ] = V_12 ;
}
static void F_279 ( struct V_48 * V_46 )
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
static void F_280 ( struct V_48 * V_46 )
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
static long F_281 ( struct V_2 * V_91 , struct V_85 * V_85 ,
T_1 V_67 )
{
struct V_2 * V_3 ;
struct V_48 * V_46 = V_91 -> V_46 ;
int V_275 = 0 ;
struct V_81 * V_82 ;
struct V_68 * V_69 = V_46 -> V_69 ;
V_3 = F_113 ( sizeof( * V_3 ) , V_53 ) ;
if ( ! V_3 )
return - V_54 ;
F_24 ( & V_69 -> V_403 ) ;
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
struct V_11 * V_12 = V_82 -> V_404 ( V_82 , V_3 ) ;
if ( F_123 ( V_12 ) ) {
V_275 = F_124 ( V_12 ) ;
goto V_405;
}
F_278 ( V_12 , V_82 , V_3 ) ;
if ( V_82 -> V_406 ) {
V_275 = F_282 ( V_82 , V_91 , V_3 ) ;
if ( V_275 )
goto V_405;
}
if ( F_8 ( V_91 ) && V_82 -> V_407 )
V_82 -> V_407 ( V_82 , V_3 ) ;
}
F_279 ( V_46 ) ;
F_36 ( & V_3 -> V_112 , & V_3 -> V_91 -> V_144 ) ;
F_280 ( V_46 ) ;
V_46 -> V_88 ++ ;
V_275 = F_196 ( V_3 , V_85 , V_67 ) ;
if ( V_275 < 0 )
goto V_408;
F_28 ( ! F_3 ( & V_3 -> V_85 -> V_93 -> V_94 ) ) ;
V_275 = F_102 ( V_3 ) ;
F_53 ( & V_1 ) ;
F_53 ( & V_3 -> V_85 -> V_93 -> V_94 ) ;
return 0 ;
V_408:
F_279 ( V_46 ) ;
F_18 ( & V_3 -> V_112 ) ;
F_280 ( V_46 ) ;
V_46 -> V_88 -- ;
V_405:
F_60 (root, ss) {
if ( V_3 -> V_39 [ V_82 -> V_399 ] )
V_82 -> V_87 ( V_82 , V_3 ) ;
}
F_53 ( & V_1 ) ;
F_64 ( V_69 ) ;
F_21 ( V_3 ) ;
return V_275 ;
}
static int F_283 ( struct V_66 * V_288 , struct V_85 * V_85 , int V_67 )
{
struct V_2 * V_409 = V_85 -> V_92 -> V_86 ;
return F_281 ( V_409 , V_85 , V_67 | V_100 ) ;
}
static int F_284 ( struct V_2 * V_3 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
struct V_11 * V_12 ;
if ( V_82 == NULL || V_82 -> V_46 != V_3 -> V_46 )
continue;
V_12 = V_3 -> V_39 [ V_82 -> V_399 ] ;
if ( V_12 && ( F_202 ( & V_12 -> V_401 ) > 1 ) )
return 1 ;
}
return 0 ;
}
static int F_285 ( struct V_2 * V_3 )
{
struct V_81 * V_82 ;
unsigned long V_5 ;
bool V_410 = false ;
F_286 ( V_5 ) ;
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_399 ] ;
int V_401 ;
while ( 1 ) {
V_401 = F_202 ( & V_12 -> V_401 ) ;
if ( V_401 > 1 ) {
V_410 = true ;
goto V_411;
}
F_28 ( ! V_401 ) ;
if ( F_287 ( & V_12 -> V_401 , V_401 , 0 ) == V_401 )
break;
F_288 () ;
}
}
V_411:
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_399 ] ;
if ( V_410 ) {
if ( ! F_202 ( & V_12 -> V_401 ) )
F_45 ( & V_12 -> V_401 , 1 ) ;
} else {
F_19 ( V_412 , & V_12 -> V_5 ) ;
}
}
F_289 ( V_5 ) ;
return ! V_410 ;
}
static int F_290 ( struct V_66 * V_413 , struct V_85 * V_85 )
{
struct V_2 * V_3 = V_85 -> V_86 ;
struct V_85 * V_90 ;
struct V_2 * V_91 ;
F_291 ( V_380 ) ;
struct V_376 * V_377 , * V_15 ;
int V_83 ;
V_322:
F_51 ( & V_1 ) ;
if ( F_202 ( & V_3 -> V_31 ) != 0 ) {
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
F_255 ( V_101 , & V_3 -> V_5 ) ;
return V_83 ;
}
F_51 ( & V_1 ) ;
V_91 = V_3 -> V_91 ;
if ( F_202 ( & V_3 -> V_31 ) || ! F_38 ( & V_3 -> V_144 ) ) {
F_255 ( V_101 , & V_3 -> V_5 ) ;
F_53 ( & V_1 ) ;
return - V_109 ;
}
F_292 ( & V_102 , & V_380 , V_356 ) ;
if ( ! F_285 ( V_3 ) ) {
F_53 ( & V_1 ) ;
if ( F_5 ( V_101 , & V_3 -> V_5 ) )
F_293 () ;
F_294 ( & V_102 , & V_380 ) ;
F_255 ( V_101 , & V_3 -> V_5 ) ;
if ( F_295 ( V_235 ) )
return - V_414 ;
goto V_322;
}
F_294 ( & V_102 , & V_380 ) ;
F_255 ( V_101 , & V_3 -> V_5 ) ;
F_73 ( & V_415 ) ;
F_19 ( V_4 , & V_3 -> V_5 ) ;
if ( ! F_38 ( & V_3 -> V_145 ) )
F_75 ( & V_3 -> V_145 ) ;
F_77 ( & V_415 ) ;
F_279 ( V_3 -> V_46 ) ;
F_75 ( & V_3 -> V_112 ) ;
F_280 ( V_3 -> V_46 ) ;
V_90 = F_68 ( V_3 -> V_85 ) ;
F_79 ( V_90 ) ;
F_71 ( V_90 ) ;
F_19 ( V_7 , & V_91 -> V_5 ) ;
F_20 ( V_91 ) ;
F_73 ( & V_3 -> V_148 ) ;
F_17 (event, tmp, &cgrp->event_list, list) {
F_18 ( & V_377 -> V_334 ) ;
F_296 ( V_377 -> V_383 , & V_377 -> V_380 ) ;
F_297 ( V_377 -> V_379 , 1 ) ;
F_261 ( & V_377 -> remove ) ;
}
F_77 ( & V_3 -> V_148 ) ;
F_53 ( & V_1 ) ;
return 0 ;
}
static void T_11 F_298 ( struct V_81 * V_82 )
{
struct V_11 * V_12 ;
F_299 ( V_416 L_19 , V_82 -> V_122 ) ;
F_36 ( & V_82 -> V_112 , & V_108 . V_113 ) ;
V_82 -> V_46 = & V_108 ;
V_12 = V_82 -> V_404 ( V_82 , V_110 ) ;
F_28 ( F_123 ( V_12 ) ) ;
F_278 ( V_12 , V_82 , V_110 ) ;
V_64 . V_39 [ V_82 -> V_399 ] = V_110 -> V_39 [ V_82 -> V_399 ] ;
V_417 |= V_82 -> V_418 || V_82 -> exit ;
F_28 ( ! F_38 ( & V_419 . V_59 ) ) ;
F_104 ( & V_82 -> V_111 ) ;
F_300 ( & V_82 -> V_111 , & V_82 -> V_420 ) ;
V_82 -> V_421 = 1 ;
F_28 ( V_82 -> V_115 ) ;
}
int T_12 F_301 ( struct V_81 * V_82 )
{
int V_13 ;
struct V_11 * V_12 ;
if ( V_82 -> V_122 == NULL || strlen ( V_82 -> V_122 ) > V_295 ||
V_82 -> V_404 == NULL || V_82 -> V_87 == NULL )
return - V_135 ;
if ( V_82 -> V_418 || V_82 -> exit )
return - V_135 ;
if ( V_82 -> V_115 == NULL ) {
F_28 ( V_82 -> V_399 >= V_142 ) ;
F_28 ( V_39 [ V_82 -> V_399 ] != V_82 ) ;
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
V_82 -> V_399 = V_13 ;
V_39 [ V_13 ] = V_82 ;
V_12 = V_82 -> V_404 ( V_82 , V_110 ) ;
if ( F_123 ( V_12 ) ) {
V_39 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
return F_124 ( V_12 ) ;
}
F_36 ( & V_82 -> V_112 , & V_108 . V_113 ) ;
V_82 -> V_46 = & V_108 ;
F_278 ( V_12 , V_82 , V_110 ) ;
if ( V_82 -> V_406 ) {
int V_83 = F_302 ( V_82 , V_12 ) ;
if ( V_83 ) {
V_110 -> V_39 [ V_82 -> V_399 ] = NULL ;
V_82 -> V_87 ( V_82 , V_110 ) ;
V_39 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
return V_83 ;
}
}
F_13 ( & V_26 ) ;
for ( V_13 = 0 ; V_13 < V_187 ; V_13 ++ ) {
struct V_19 * V_20 ;
struct V_50 * V_51 , * V_15 ;
struct V_10 * V_422 = & V_18 [ V_13 ] , * V_423 ;
F_303 (cg, node, tmp, bucket, hlist) {
if ( V_20 -> V_39 [ V_82 -> V_399 ] )
continue;
F_16 ( & V_20 -> V_27 ) ;
V_20 -> V_39 [ V_82 -> V_399 ] = V_12 ;
V_423 = F_9 ( V_20 -> V_39 ) ;
F_48 ( & V_20 -> V_27 , V_423 ) ;
}
}
F_15 ( & V_26 ) ;
F_104 ( & V_82 -> V_111 ) ;
F_300 ( & V_82 -> V_111 , & V_82 -> V_420 ) ;
V_82 -> V_421 = 1 ;
F_53 ( & V_1 ) ;
return 0 ;
}
void F_304 ( struct V_81 * V_82 )
{
struct V_22 * V_23 ;
struct V_10 * V_49 ;
F_28 ( V_82 -> V_115 == NULL ) ;
F_28 ( V_82 -> V_46 != & V_108 ) ;
F_51 ( & V_1 ) ;
F_28 ( V_82 -> V_399 < V_142 ) ;
V_39 [ V_82 -> V_399 ] = NULL ;
F_75 ( & V_82 -> V_112 ) ;
F_13 ( & V_26 ) ;
F_47 (link, &dummytop->css_sets, cgrp_link_list) {
struct V_19 * V_20 = V_23 -> V_20 ;
F_16 ( & V_20 -> V_27 ) ;
F_28 ( ! V_20 -> V_39 [ V_82 -> V_399 ] ) ;
V_20 -> V_39 [ V_82 -> V_399 ] = NULL ;
V_49 = F_9 ( V_20 -> V_39 ) ;
F_48 ( & V_20 -> V_27 , V_49 ) ;
}
F_15 ( & V_26 ) ;
V_82 -> V_87 ( V_82 , V_110 ) ;
V_110 -> V_39 [ V_82 -> V_399 ] = NULL ;
F_53 ( & V_1 ) ;
}
int T_11 F_305 ( void )
{
int V_13 ;
F_45 ( & V_64 . V_25 , 1 ) ;
F_34 ( & V_64 . V_40 ) ;
F_34 ( & V_64 . V_59 ) ;
F_46 ( & V_64 . V_27 ) ;
V_28 = 1 ;
F_106 ( & V_108 ) ;
V_58 = 1 ;
V_419 . V_63 = & V_64 ;
V_424 . V_20 = & V_64 ;
V_424 . V_3 = V_110 ;
F_36 ( & V_424 . V_30 ,
& V_108 . V_65 . V_56 ) ;
F_36 ( & V_424 . V_29 ,
& V_64 . V_40 ) ;
for ( V_13 = 0 ; V_13 < V_187 ; V_13 ++ )
F_306 ( & V_18 [ V_13 ] ) ;
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
F_28 ( ! V_82 -> V_122 ) ;
F_28 ( strlen ( V_82 -> V_122 ) > V_295 ) ;
F_28 ( ! V_82 -> V_404 ) ;
F_28 ( ! V_82 -> V_87 ) ;
if ( V_82 -> V_399 != V_13 ) {
F_299 ( V_425 L_20 ,
V_82 -> V_122 , V_82 -> V_399 ) ;
F_307 () ;
}
if ( V_82 -> V_426 )
F_298 ( V_82 ) ;
}
return 0 ;
}
int T_11 F_308 ( void )
{
int V_275 ;
int V_13 ;
struct V_10 * V_49 ;
V_275 = F_309 ( & V_80 ) ;
if ( V_275 )
return V_275 ;
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( ! V_82 -> V_426 )
F_298 ( V_82 ) ;
if ( V_82 -> V_406 )
F_302 ( V_82 , V_64 . V_39 [ V_82 -> V_399 ] ) ;
}
V_49 = F_9 ( V_64 . V_39 ) ;
F_48 ( & V_64 . V_27 , V_49 ) ;
F_28 ( ! F_107 ( & V_108 ) ) ;
V_427 = F_310 ( L_21 , V_428 ) ;
if ( ! V_427 ) {
V_275 = - V_54 ;
goto V_206;
}
V_275 = F_311 ( & V_429 ) ;
if ( V_275 < 0 ) {
F_312 ( V_427 ) ;
goto V_206;
}
F_313 ( L_22 , 0 , NULL , & V_430 ) ;
V_206:
if ( V_275 )
F_314 ( & V_80 ) ;
return V_275 ;
}
static int F_315 ( struct V_116 * V_268 , void * V_367 )
{
struct V_226 * V_226 ;
struct V_61 * V_197 ;
char * V_190 ;
int V_203 ;
struct V_48 * V_46 ;
V_203 = - V_54 ;
V_190 = F_35 ( V_321 , V_53 ) ;
if ( ! V_190 )
goto V_206;
V_203 = - V_201 ;
V_226 = V_268 -> V_258 ;
V_197 = F_316 ( V_226 , V_431 ) ;
if ( ! V_197 )
goto V_432;
V_203 = 0 ;
F_51 ( & V_1 ) ;
F_126 (root) {
struct V_81 * V_82 ;
struct V_2 * V_3 ;
int V_31 = 0 ;
F_93 ( V_268 , L_23 , V_46 -> V_153 ) ;
F_60 (root, ss)
F_93 ( V_268 , L_24 , V_31 ++ ? L_6 : L_25 , V_82 -> V_122 ) ;
if ( strlen ( V_46 -> V_122 ) )
F_93 ( V_268 , L_26 , V_31 ? L_6 : L_25 ,
V_46 -> V_122 ) ;
F_167 ( V_268 , ':' ) ;
V_3 = F_49 ( V_197 , V_46 ) ;
V_203 = F_134 ( V_3 , V_190 , V_321 ) ;
if ( V_203 < 0 )
goto V_143;
F_94 ( V_268 , V_190 ) ;
F_167 ( V_268 , '\n' ) ;
}
V_143:
F_53 ( & V_1 ) ;
F_161 ( V_197 ) ;
V_432:
F_21 ( V_190 ) ;
V_206:
return V_203 ;
}
static int F_317 ( struct V_66 * V_66 , struct V_239 * V_239 )
{
struct V_226 * V_226 = F_318 ( V_66 ) -> V_226 ;
return F_185 ( V_239 , F_315 , V_226 ) ;
}
static int F_319 ( struct V_116 * V_268 , void * V_367 )
{
int V_13 ;
F_94 ( V_268 , L_27 ) ;
F_51 ( & V_1 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
F_93 ( V_268 , L_28 ,
V_82 -> V_122 , V_82 -> V_46 -> V_153 ,
V_82 -> V_46 -> V_88 , ! V_82 -> V_140 ) ;
}
F_53 ( & V_1 ) ;
return 0 ;
}
static int F_320 ( struct V_66 * V_66 , struct V_239 * V_239 )
{
return F_185 ( V_239 , F_319 , NULL ) ;
}
void F_321 ( struct V_61 * V_433 )
{
F_137 ( V_235 ) ;
V_433 -> V_63 = V_235 -> V_63 ;
F_23 ( V_433 -> V_63 ) ;
F_138 ( V_235 ) ;
F_34 ( & V_433 -> V_202 ) ;
}
void F_322 ( struct V_61 * V_433 )
{
if ( V_417 ) {
int V_13 ;
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 -> V_418 )
V_82 -> V_418 ( V_82 , V_433 ) ;
}
}
}
void F_323 ( struct V_61 * V_433 )
{
if ( V_304 ) {
F_13 ( & V_26 ) ;
F_137 ( V_433 ) ;
if ( F_38 ( & V_433 -> V_202 ) )
F_36 ( & V_433 -> V_202 , & V_433 -> V_63 -> V_59 ) ;
F_138 ( V_433 ) ;
F_15 ( & V_26 ) ;
}
}
void F_324 ( struct V_61 * V_197 , int V_434 )
{
struct V_19 * V_20 ;
int V_13 ;
if ( ! F_38 ( & V_197 -> V_202 ) ) {
F_13 ( & V_26 ) ;
if ( ! F_38 ( & V_197 -> V_202 ) )
F_75 ( & V_197 -> V_202 ) ;
F_15 ( & V_26 ) ;
}
F_137 ( V_197 ) ;
V_20 = V_197 -> V_63 ;
V_197 -> V_63 = & V_64 ;
if ( V_434 && V_417 ) {
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 -> exit ) {
struct V_2 * V_435 =
F_325 ( V_20 -> V_39 [ V_13 ] ) -> V_2 ;
struct V_2 * V_3 = F_326 ( V_197 , V_13 ) ;
V_82 -> exit ( V_82 , V_3 , V_435 , V_197 ) ;
}
}
}
F_138 ( V_197 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
}
int F_327 ( const struct V_2 * V_3 , struct V_61 * V_62 )
{
int V_83 ;
struct V_2 * V_436 ;
if ( V_3 == V_110 )
return 1 ;
V_436 = F_49 ( V_62 , V_3 -> V_46 ) ;
while ( V_3 != V_436 && V_3 != V_3 -> V_65 )
V_3 = V_3 -> V_91 ;
V_83 = ( V_3 == V_436 ) ;
return V_83 ;
}
static void F_20 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 ) && ! F_202 ( & V_3 -> V_31 )
&& F_38 ( & V_3 -> V_144 ) && ! F_284 ( V_3 ) ) {
int V_437 = 0 ;
F_73 ( & V_415 ) ;
if ( ! F_4 ( V_3 ) &&
F_38 ( & V_3 -> V_145 ) ) {
F_36 ( & V_3 -> V_145 , & V_145 ) ;
V_437 = 1 ;
}
F_77 ( & V_415 ) ;
if ( V_437 )
F_261 ( & V_438 ) ;
}
}
void F_328 ( struct V_11 * V_12 , int V_31 )
{
struct V_2 * V_3 = V_12 -> V_2 ;
int V_248 ;
F_149 () ;
V_248 = F_329 ( V_31 , & V_12 -> V_401 ) ;
if ( V_248 == 1 ) {
if ( F_7 ( V_3 ) ) {
F_19 ( V_7 , & V_3 -> V_5 ) ;
F_20 ( V_3 ) ;
}
F_80 ( V_3 ) ;
}
F_151 () ;
F_330 ( V_248 < 1 ) ;
}
static void F_331 ( struct V_374 * V_375 )
{
F_28 ( V_375 != & V_438 ) ;
F_51 ( & V_1 ) ;
F_73 ( & V_415 ) ;
while ( ! F_38 ( & V_145 ) ) {
char * V_439 [ 3 ] , * V_440 [ 3 ] ;
int V_13 ;
char * V_441 = NULL , * V_442 = NULL ;
struct V_2 * V_3 = F_29 ( V_145 . V_45 ,
struct V_2 ,
V_145 ) ;
F_75 ( & V_3 -> V_145 ) ;
F_77 ( & V_415 ) ;
V_441 = F_35 ( V_321 , V_53 ) ;
if ( ! V_441 )
goto V_443;
if ( F_134 ( V_3 , V_441 , V_321 ) < 0 )
goto V_443;
V_442 = F_332 ( V_3 -> V_46 -> V_124 , V_53 ) ;
if ( ! V_442 )
goto V_443;
V_13 = 0 ;
V_439 [ V_13 ++ ] = V_442 ;
V_439 [ V_13 ++ ] = V_441 ;
V_439 [ V_13 ] = NULL ;
V_13 = 0 ;
V_440 [ V_13 ++ ] = L_29 ;
V_440 [ V_13 ++ ] = L_30 ;
V_440 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
F_333 ( V_439 [ 0 ] , V_439 , V_440 , V_444 ) ;
F_51 ( & V_1 ) ;
V_443:
F_21 ( V_441 ) ;
F_21 ( V_442 ) ;
F_73 ( & V_415 ) ;
}
F_77 ( & V_415 ) ;
F_53 ( & V_1 ) ;
}
static int T_11 F_334 ( char * V_445 )
{
int V_13 ;
char * V_128 ;
while ( ( V_128 = F_97 ( & V_445 , L_6 ) ) != NULL ) {
if ( ! * V_128 )
continue;
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( ! strcmp ( V_128 , V_82 -> V_122 ) ) {
V_82 -> V_140 = 1 ;
F_299 ( V_416 L_31
L_32 , V_82 -> V_122 ) ;
break;
}
}
}
return 1 ;
}
unsigned short F_335 ( struct V_11 * V_12 )
{
struct F_335 * V_446 ;
V_446 = F_135 ( V_12 -> V_400 , F_202 ( & V_12 -> V_401 ) ) ;
if ( V_446 )
return V_446 -> V_400 ;
return 0 ;
}
unsigned short F_336 ( struct V_11 * V_12 )
{
struct F_335 * V_446 ;
V_446 = F_135 ( V_12 -> V_400 , F_202 ( & V_12 -> V_401 ) ) ;
if ( V_446 )
return V_446 -> V_447 ;
return 0 ;
}
bool F_337 ( struct V_11 * V_433 ,
const struct V_11 * V_46 )
{
struct F_335 * V_448 ;
struct F_335 * V_449 ;
bool V_83 = true ;
F_149 () ;
V_448 = F_338 ( V_433 -> V_400 ) ;
V_449 = F_338 ( V_46 -> V_400 ) ;
if ( ! V_448
|| ! V_449
|| ( V_448 -> V_447 < V_449 -> V_447 )
|| ( V_448 -> V_450 [ V_449 -> V_447 ] != V_449 -> V_400 ) )
V_83 = false ;
F_151 () ;
return V_83 ;
}
void F_339 ( struct V_81 * V_82 , struct V_11 * V_12 )
{
struct F_335 * V_400 = V_12 -> V_400 ;
if ( ! V_400 )
return;
F_28 ( ! V_82 -> V_406 ) ;
F_140 ( V_400 -> V_12 , NULL ) ;
F_140 ( V_12 -> V_400 , NULL ) ;
F_73 ( & V_82 -> V_451 ) ;
F_340 ( & V_82 -> V_452 , V_400 -> V_400 ) ;
F_77 ( & V_82 -> V_451 ) ;
F_22 ( V_400 , V_32 ) ;
}
static struct F_335 * F_341 ( struct V_81 * V_82 , int V_447 )
{
struct F_335 * V_453 ;
int V_454 , error , V_323 ;
F_28 ( ! V_82 -> V_406 ) ;
V_323 = sizeof( * V_453 ) + sizeof( unsigned short ) * ( V_447 + 1 ) ;
V_453 = F_113 ( V_323 , V_53 ) ;
if ( ! V_453 )
return F_114 ( - V_54 ) ;
if ( F_81 ( ! F_342 ( & V_82 -> V_452 , V_53 ) ) ) {
error = - V_54 ;
goto V_455;
}
F_73 ( & V_82 -> V_451 ) ;
error = F_343 ( & V_82 -> V_452 , V_453 , 1 , & V_454 ) ;
F_77 ( & V_82 -> V_451 ) ;
if ( error ) {
error = - V_154 ;
goto V_455;
}
if ( V_454 > V_456 )
goto V_457;
V_453 -> V_400 = V_454 ;
V_453 -> V_447 = V_447 ;
return V_453 ;
V_457:
error = - V_154 ;
F_73 ( & V_82 -> V_451 ) ;
F_340 ( & V_82 -> V_452 , V_454 ) ;
F_77 ( & V_82 -> V_451 ) ;
V_455:
F_21 ( V_453 ) ;
return F_114 ( error ) ;
}
static int T_12 F_302 ( struct V_81 * V_82 ,
struct V_11 * V_458 )
{
struct F_335 * V_453 ;
F_105 ( & V_82 -> V_451 ) ;
F_344 ( & V_82 -> V_452 ) ;
V_453 = F_341 ( V_82 , 0 ) ;
if ( F_123 ( V_453 ) )
return F_124 ( V_453 ) ;
V_453 -> V_450 [ 0 ] = V_453 -> V_400 ;
V_453 -> V_12 = V_458 ;
V_458 -> V_400 = V_453 ;
return 0 ;
}
static int F_282 ( struct V_81 * V_82 , struct V_2 * V_91 ,
struct V_2 * V_433 )
{
int V_399 , V_13 , V_447 = 0 ;
struct V_11 * V_459 , * V_460 ;
struct F_335 * V_448 , * V_461 ;
V_399 = V_82 -> V_399 ;
V_459 = V_91 -> V_39 [ V_399 ] ;
V_460 = V_433 -> V_39 [ V_399 ] ;
V_461 = V_459 -> V_400 ;
V_447 = V_461 -> V_447 + 1 ;
V_448 = F_341 ( V_82 , V_447 ) ;
if ( F_123 ( V_448 ) )
return F_124 ( V_448 ) ;
for ( V_13 = 0 ; V_13 < V_447 ; V_13 ++ )
V_448 -> V_450 [ V_13 ] = V_461 -> V_450 [ V_13 ] ;
V_448 -> V_450 [ V_447 ] = V_448 -> V_400 ;
F_140 ( V_460 -> V_400 , V_448 ) ;
return 0 ;
}
struct V_11 * F_345 ( struct V_81 * V_82 , int V_400 )
{
struct F_335 * V_446 = NULL ;
F_28 ( ! V_82 -> V_406 ) ;
V_446 = F_346 ( & V_82 -> V_452 , V_400 ) ;
if ( F_81 ( ! V_446 ) )
return NULL ;
return F_338 ( V_446 -> V_12 ) ;
}
struct V_11 *
F_347 ( struct V_81 * V_82 , int V_400 ,
struct V_11 * V_46 , int * V_462 )
{
struct V_11 * V_83 = NULL ;
struct F_335 * V_15 ;
int V_463 ;
int V_464 = F_335 ( V_46 ) ;
int V_447 = F_336 ( V_46 ) ;
if ( ! V_464 )
return NULL ;
F_28 ( ! V_82 -> V_406 ) ;
V_463 = V_400 ;
while ( 1 ) {
F_73 ( & V_82 -> V_451 ) ;
V_15 = F_348 ( & V_82 -> V_452 , & V_463 ) ;
F_77 ( & V_82 -> V_451 ) ;
if ( ! V_15 )
break;
if ( V_15 -> V_447 >= V_447 && V_15 -> V_450 [ V_447 ] == V_464 ) {
V_83 = F_338 ( V_15 -> V_12 ) ;
if ( V_83 ) {
* V_462 = V_463 ;
break;
}
}
V_463 = V_463 + 1 ;
}
return V_83 ;
}
struct V_11 * F_349 ( struct V_239 * V_465 , int V_400 )
{
struct V_2 * V_3 ;
struct V_66 * V_66 ;
struct V_11 * V_12 ;
V_66 = V_465 -> V_255 -> V_93 ;
if ( V_66 -> V_173 != & V_174 )
return F_114 ( - V_391 ) ;
if ( V_400 < 0 || V_400 >= V_16 )
return F_114 ( - V_135 ) ;
V_3 = F_132 ( V_465 -> V_255 ) ;
V_12 = V_3 -> V_39 [ V_400 ] ;
return V_12 ? V_12 : F_114 ( - V_141 ) ;
}
static struct V_11 * F_350 ( struct V_81 * V_82 ,
struct V_2 * V_466 )
{
struct V_11 * V_12 = F_113 ( sizeof( * V_12 ) , V_53 ) ;
if ( ! V_12 )
return F_114 ( - V_54 ) ;
return V_12 ;
}
static void F_351 ( struct V_81 * V_82 , struct V_2 * V_466 )
{
F_21 ( V_466 -> V_39 [ V_467 ] ) ;
}
static T_2 F_352 ( struct V_2 * V_466 , struct V_189 * V_236 )
{
return F_202 ( & V_466 -> V_31 ) ;
}
static T_2 F_353 ( struct V_2 * V_466 , struct V_189 * V_236 )
{
return F_201 ( V_466 ) ;
}
static T_2 F_354 ( struct V_2 * V_466 , struct V_189 * V_236 )
{
return ( T_2 ) ( unsigned long ) V_235 -> V_63 ;
}
static T_2 F_355 ( struct V_2 * V_466 ,
struct V_189 * V_236 )
{
T_2 V_31 ;
F_149 () ;
V_31 = F_202 ( & V_235 -> V_63 -> V_25 ) ;
F_151 () ;
return V_31 ;
}
static int F_356 ( struct V_2 * V_466 ,
struct V_189 * V_236 ,
struct V_116 * V_117 )
{
struct V_22 * V_23 ;
struct V_19 * V_20 ;
F_43 ( & V_26 ) ;
F_149 () ;
V_20 = F_338 ( V_235 -> V_63 ) ;
F_47 (link, &cg->cg_links, cg_link_list) {
struct V_2 * V_60 = V_23 -> V_3 ;
const char * V_122 ;
if ( V_60 -> V_85 )
V_122 = V_60 -> V_85 -> V_194 . V_122 ;
else
V_122 = L_33 ;
F_93 ( V_117 , L_34 ,
V_60 -> V_46 -> V_153 , V_122 ) ;
}
F_151 () ;
F_44 ( & V_26 ) ;
return 0 ;
}
static int F_357 ( struct V_2 * V_466 ,
struct V_189 * V_236 ,
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
if ( V_31 ++ > V_468 ) {
F_94 ( V_117 , L_36 ) ;
break;
} else {
F_93 ( V_117 , L_37 ,
F_234 ( V_62 ) ) ;
}
}
}
F_44 ( & V_26 ) ;
return 0 ;
}
static T_2 F_358 ( struct V_2 * V_3 , struct V_189 * V_236 )
{
return F_5 ( V_7 , & V_3 -> V_5 ) ;
}
static int F_359 ( struct V_81 * V_82 , struct V_2 * V_466 )
{
return F_200 ( V_466 , V_82 , V_469 ,
F_277 ( V_469 ) ) ;
}
