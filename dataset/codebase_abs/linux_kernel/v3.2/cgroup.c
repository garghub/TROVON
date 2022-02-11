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
F_43 ( & V_225 ) ;
if ( ! F_149 ( V_218 ) ) {
F_44 ( & V_225 ) ;
V_203 = - V_155 ;
goto V_224;
}
V_197 = V_218 ;
V_13 = 0 ;
do {
F_28 ( V_13 >= V_219 ) ;
F_150 ( V_197 ) ;
V_203 = F_151 ( V_222 , V_13 , V_197 , V_226 ) ;
F_28 ( V_203 != 0 ) ;
V_13 ++ ;
} while_each_thread(leader, tsk) ;
int F_152 ( struct V_2 * V_3 , T_2 V_227 , bool V_228 )
{
struct V_61 * V_197 ;
const struct V_184 * V_184 = F_153 () , * V_229 ;
int V_83 ;
if ( ! F_154 ( V_3 ) )
return - V_230 ;
if ( V_227 ) {
F_155 () ;
V_197 = F_156 ( V_227 ) ;
if ( ! V_197 ) {
F_157 () ;
F_52 () ;
return - V_201 ;
}
if ( V_228 ) {
V_197 = V_197 -> V_231 ;
} else if ( V_197 -> V_5 & V_200 ) {
F_157 () ;
F_52 () ;
return - V_201 ;
}
V_229 = F_158 ( V_197 ) ;
if ( V_184 -> V_232 &&
V_184 -> V_232 != V_229 -> V_233 &&
V_184 -> V_232 != V_229 -> V_234 ) {
F_157 () ;
F_52 () ;
return - V_235 ;
}
F_150 ( V_197 ) ;
F_157 () ;
} else {
if ( V_228 )
V_197 = V_236 -> V_231 ;
else
V_197 = V_236 ;
F_150 ( V_197 ) ;
}
if ( V_228 ) {
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
static int F_162 ( struct V_2 * V_3 , struct V_189 * V_237 , T_2 V_227 )
{
return F_152 ( V_3 , V_227 , false ) ;
}
static int F_163 ( struct V_2 * V_3 , struct V_189 * V_237 , T_2 V_238 )
{
int V_83 ;
do {
V_83 = F_152 ( V_3 , V_238 , true ) ;
} while ( V_83 == - V_155 );
return V_83 ;
}
bool F_154 ( struct V_2 * V_3 )
{
F_51 ( & V_1 ) ;
if ( F_4 ( V_3 ) ) {
F_53 ( & V_1 ) ;
return false ;
}
return true ;
}
static int F_164 ( struct V_2 * V_3 , struct V_189 * V_237 ,
const char * V_239 )
{
F_165 ( sizeof( V_3 -> V_46 -> V_124 ) < V_138 ) ;
if ( strlen ( V_239 ) >= V_138 )
return - V_135 ;
if ( ! F_154 ( V_3 ) )
return - V_230 ;
strcpy ( V_3 -> V_46 -> V_124 , V_239 ) ;
F_52 () ;
return 0 ;
}
static int F_166 ( struct V_2 * V_3 , struct V_189 * V_237 ,
struct V_116 * V_117 )
{
if ( ! F_154 ( V_3 ) )
return - V_230 ;
F_94 ( V_117 , V_3 -> V_46 -> V_124 ) ;
F_167 ( V_117 , '\n' ) ;
F_52 () ;
return 0 ;
}
static T_3 F_168 ( struct V_2 * V_3 , struct V_189 * V_237 ,
struct V_240 * V_240 ,
const char T_4 * V_241 ,
T_5 V_242 , T_6 * V_243 )
{
char V_239 [ V_244 ] ;
int V_203 = 0 ;
char * V_245 ;
if ( ! V_242 )
return - V_135 ;
if ( V_242 >= sizeof( V_239 ) )
return - V_246 ;
if ( F_169 ( V_239 , V_241 , V_242 ) )
return - V_247 ;
V_239 [ V_242 ] = 0 ;
if ( V_237 -> V_248 ) {
T_2 V_249 = F_170 ( F_171 ( V_239 ) , & V_245 , 0 ) ;
if ( * V_245 )
return - V_135 ;
V_203 = V_237 -> V_248 ( V_3 , V_237 , V_249 ) ;
} else {
T_7 V_249 = F_172 ( F_171 ( V_239 ) , & V_245 , 0 ) ;
if ( * V_245 )
return - V_135 ;
V_203 = V_237 -> V_250 ( V_3 , V_237 , V_249 ) ;
}
if ( ! V_203 )
V_203 = V_242 ;
return V_203 ;
}
static T_3 F_173 ( struct V_2 * V_3 , struct V_189 * V_237 ,
struct V_240 * V_240 ,
const char T_4 * V_241 ,
T_5 V_242 , T_6 * V_243 )
{
char V_251 [ V_244 ] ;
int V_203 = 0 ;
T_5 V_252 = V_237 -> V_253 ;
char * V_239 = V_251 ;
if ( ! V_252 )
V_252 = sizeof( V_251 ) - 1 ;
if ( V_242 >= V_252 )
return - V_246 ;
if ( V_242 >= sizeof( V_251 ) ) {
V_239 = F_35 ( V_242 + 1 , V_53 ) ;
if ( V_239 == NULL )
return - V_54 ;
}
if ( V_242 && F_169 ( V_239 , V_241 , V_242 ) ) {
V_203 = - V_247 ;
goto V_206;
}
V_239 [ V_242 ] = 0 ;
V_203 = V_237 -> V_254 ( V_3 , V_237 , F_171 ( V_239 ) ) ;
if ( ! V_203 )
V_203 = V_242 ;
V_206:
if ( V_239 != V_251 )
F_21 ( V_239 ) ;
return V_203 ;
}
static T_3 F_174 ( struct V_240 * V_240 , const char T_4 * V_190 ,
T_5 V_242 , T_6 * V_255 )
{
struct V_189 * V_237 = F_133 ( V_240 -> V_256 ) ;
struct V_2 * V_3 = F_132 ( V_240 -> V_256 -> V_92 ) ;
if ( F_4 ( V_3 ) )
return - V_230 ;
if ( V_237 -> V_257 )
return V_237 -> V_257 ( V_3 , V_237 , V_240 , V_190 , V_242 , V_255 ) ;
if ( V_237 -> V_248 || V_237 -> V_250 )
return F_168 ( V_3 , V_237 , V_240 , V_190 , V_242 , V_255 ) ;
if ( V_237 -> V_254 )
return F_173 ( V_3 , V_237 , V_240 , V_190 , V_242 , V_255 ) ;
if ( V_237 -> V_258 ) {
int V_83 = V_237 -> V_258 ( V_3 , ( unsigned int ) V_237 -> V_259 ) ;
return V_83 ? V_83 : V_242 ;
}
return - V_135 ;
}
static T_3 F_175 ( struct V_2 * V_3 , struct V_189 * V_237 ,
struct V_240 * V_240 ,
char T_4 * V_190 , T_5 V_242 ,
T_6 * V_255 )
{
char V_15 [ V_244 ] ;
T_2 V_249 = V_237 -> V_260 ( V_3 , V_237 ) ;
int V_193 = sprintf ( V_15 , L_14 , ( unsigned long long ) V_249 ) ;
return F_176 ( V_190 , V_242 , V_255 , V_15 , V_193 ) ;
}
static T_3 F_177 ( struct V_2 * V_3 , struct V_189 * V_237 ,
struct V_240 * V_240 ,
char T_4 * V_190 , T_5 V_242 ,
T_6 * V_255 )
{
char V_15 [ V_244 ] ;
T_7 V_249 = V_237 -> V_261 ( V_3 , V_237 ) ;
int V_193 = sprintf ( V_15 , L_15 , ( long long ) V_249 ) ;
return F_176 ( V_190 , V_242 , V_255 , V_15 , V_193 ) ;
}
static T_3 F_178 ( struct V_240 * V_240 , char T_4 * V_190 ,
T_5 V_242 , T_6 * V_255 )
{
struct V_189 * V_237 = F_133 ( V_240 -> V_256 ) ;
struct V_2 * V_3 = F_132 ( V_240 -> V_256 -> V_92 ) ;
if ( F_4 ( V_3 ) )
return - V_230 ;
if ( V_237 -> V_262 )
return V_237 -> V_262 ( V_3 , V_237 , V_240 , V_190 , V_242 , V_255 ) ;
if ( V_237 -> V_260 )
return F_175 ( V_3 , V_237 , V_240 , V_190 , V_242 , V_255 ) ;
if ( V_237 -> V_261 )
return F_177 ( V_3 , V_237 , V_240 , V_190 , V_242 , V_255 ) ;
return - V_135 ;
}
static int F_179 ( struct V_263 * V_264 , const char * V_265 , T_2 V_266 )
{
struct V_116 * V_267 = V_264 -> V_268 ;
return F_93 ( V_267 , L_16 , V_265 , ( unsigned long long ) V_266 ) ;
}
static int F_180 ( struct V_116 * V_269 , void * V_270 )
{
struct V_271 * V_268 = V_269 -> V_259 ;
struct V_189 * V_237 = V_268 -> V_237 ;
if ( V_237 -> V_272 ) {
struct V_263 V_264 = {
. V_273 = F_179 ,
. V_268 = V_269 ,
} ;
return V_237 -> V_272 ( V_268 -> V_2 , V_237 , & V_264 ) ;
}
return V_237 -> V_274 ( V_268 -> V_2 , V_237 , V_269 ) ;
}
static int F_181 ( struct V_66 * V_66 , struct V_240 * V_240 )
{
struct V_116 * V_117 = V_240 -> V_275 ;
F_21 ( V_117 -> V_259 ) ;
return F_182 ( V_66 , V_240 ) ;
}
static int F_183 ( struct V_66 * V_66 , struct V_240 * V_240 )
{
int V_276 ;
struct V_189 * V_237 ;
V_276 = F_184 ( V_66 , V_240 ) ;
if ( V_276 )
return V_276 ;
V_237 = F_133 ( V_240 -> V_256 ) ;
if ( V_237 -> V_272 || V_237 -> V_274 ) {
struct V_271 * V_268 =
F_113 ( sizeof( * V_268 ) , V_277 ) ;
if ( ! V_268 )
return - V_54 ;
V_268 -> V_237 = V_237 ;
V_268 -> V_2 = F_132 ( V_240 -> V_256 -> V_92 ) ;
V_240 -> V_278 = & V_279 ;
V_276 = F_185 ( V_240 , F_180 , V_268 ) ;
if ( V_276 < 0 )
F_21 ( V_268 ) ;
} else if ( V_237 -> V_280 )
V_276 = V_237 -> V_280 ( V_66 , V_240 ) ;
else
V_276 = 0 ;
return V_276 ;
}
static int F_186 ( struct V_66 * V_66 , struct V_240 * V_240 )
{
struct V_189 * V_237 = F_133 ( V_240 -> V_256 ) ;
if ( V_237 -> V_281 )
return V_237 -> V_281 ( V_66 , V_240 ) ;
return 0 ;
}
static int F_187 ( struct V_66 * V_282 , struct V_85 * V_283 ,
struct V_66 * V_284 , struct V_85 * V_285 )
{
if ( ! F_62 ( V_283 -> V_93 -> V_71 ) )
return - V_286 ;
if ( V_285 -> V_93 )
return - V_287 ;
if ( V_282 != V_284 )
return - V_288 ;
return F_188 ( V_282 , V_283 , V_284 , V_285 ) ;
}
static struct V_85 * F_189 ( struct V_66 * V_289 , struct V_85 * V_85 , struct V_290 * V_291 )
{
if ( V_85 -> V_194 . V_193 > V_292 )
return F_114 ( - V_195 ) ;
F_190 ( V_85 , NULL ) ;
return NULL ;
}
static inline struct V_189 * F_191 ( struct V_240 * V_240 )
{
if ( V_240 -> V_256 -> V_93 -> V_171 != & V_293 )
return F_114 ( - V_135 ) ;
return F_133 ( V_240 -> V_256 ) ;
}
static int F_192 ( struct V_85 * V_85 , T_1 V_67 ,
struct V_68 * V_69 )
{
struct V_66 * V_66 ;
if ( ! V_85 )
return - V_141 ;
if ( V_85 -> V_93 )
return - V_287 ;
V_66 = F_54 ( V_67 , V_69 ) ;
if ( ! V_66 )
return - V_54 ;
if ( F_62 ( V_67 ) ) {
V_66 -> V_173 = & V_174 ;
V_66 -> V_171 = & V_172 ;
F_120 ( V_66 ) ;
F_193 ( & V_66 -> V_94 , V_294 ) ;
} else if ( F_194 ( V_67 ) ) {
V_66 -> V_295 = 0 ;
V_66 -> V_171 = & V_293 ;
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
static T_1 F_197 ( const struct V_189 * V_237 )
{
T_1 V_67 = 0 ;
if ( V_237 -> V_67 )
return V_237 -> V_67 ;
if ( V_237 -> V_262 || V_237 -> V_260 || V_237 -> V_261 ||
V_237 -> V_272 || V_237 -> V_274 )
V_67 |= V_168 ;
if ( V_237 -> V_257 || V_237 -> V_248 || V_237 -> V_250 ||
V_237 -> V_254 || V_237 -> V_258 )
V_67 |= V_170 ;
return V_67 ;
}
int F_198 ( struct V_2 * V_3 ,
struct V_81 * V_39 ,
const struct V_189 * V_237 )
{
struct V_85 * V_289 = V_3 -> V_85 ;
struct V_85 * V_85 ;
int error ;
T_1 V_67 ;
char V_122 [ V_296 + V_297 + 2 ] = { 0 } ;
if ( V_39 && ! F_5 ( V_123 , & V_3 -> V_46 -> V_5 ) ) {
strcpy ( V_122 , V_39 -> V_122 ) ;
strcat ( V_122 , L_17 ) ;
}
strcat ( V_122 , V_237 -> V_122 ) ;
F_28 ( ! F_3 ( & V_289 -> V_93 -> V_94 ) ) ;
V_85 = F_199 ( V_122 , V_289 , strlen ( V_122 ) ) ;
if ( ! F_123 ( V_85 ) ) {
V_67 = F_197 ( V_237 ) ;
error = F_192 ( V_85 , V_67 | V_298 ,
V_3 -> V_46 -> V_69 ) ;
if ( ! error )
V_85 -> V_86 = ( void * ) V_237 ;
F_71 ( V_85 ) ;
} else
error = F_124 ( V_85 ) ;
return error ;
}
int F_200 ( struct V_2 * V_3 ,
struct V_81 * V_39 ,
const struct V_189 V_237 [] ,
int V_31 )
{
int V_13 , V_276 ;
for ( V_13 = 0 ; V_13 < V_31 ; V_13 ++ ) {
V_276 = F_198 ( V_3 , V_39 , & V_237 [ V_13 ] ) ;
if ( V_276 )
return V_276 ;
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
struct V_299 * V_300 )
{
struct V_36 * V_301 = V_300 -> V_302 ;
struct V_22 * V_23 ;
struct V_19 * V_20 ;
do {
V_301 = V_301 -> V_45 ;
if ( V_301 == & V_3 -> V_56 ) {
V_300 -> V_302 = NULL ;
return;
}
V_23 = F_29 ( V_301 , struct V_22 , V_30 ) ;
V_20 = V_23 -> V_20 ;
} while ( F_38 ( & V_20 -> V_59 ) );
V_300 -> V_302 = V_301 ;
V_300 -> V_62 = V_20 -> V_59 . V_45 ;
}
static void F_204 ( void )
{
struct V_61 * V_303 , * V_304 ;
F_13 ( & V_26 ) ;
V_305 = 1 ;
F_205 (g, p) {
F_137 ( V_303 ) ;
if ( ! ( V_303 -> V_5 & V_200 ) && F_38 ( & V_303 -> V_202 ) )
F_36 ( & V_303 -> V_202 , & V_303 -> V_63 -> V_59 ) ;
F_138 ( V_303 ) ;
} F_206 ( V_304 , V_303 ) ;
F_15 ( & V_26 ) ;
}
void F_207 ( struct V_2 * V_3 , struct V_299 * V_300 )
{
if ( ! V_305 )
F_204 () ;
F_43 ( & V_26 ) ;
V_300 -> V_302 = & V_3 -> V_56 ;
F_203 ( V_3 , V_300 ) ;
}
struct V_61 * F_208 ( struct V_2 * V_3 ,
struct V_299 * V_300 )
{
struct V_61 * V_57 ;
struct V_36 * V_301 = V_300 -> V_62 ;
struct V_22 * V_23 ;
if ( ! V_300 -> V_302 )
return NULL ;
V_57 = F_29 ( V_301 , struct V_61 , V_202 ) ;
V_301 = V_301 -> V_45 ;
V_23 = F_29 ( V_300 -> V_302 , struct V_22 , V_30 ) ;
if ( V_301 == & V_23 -> V_20 -> V_59 ) {
F_203 ( V_3 , V_300 ) ;
} else {
V_300 -> V_62 = V_301 ;
}
return V_57 ;
}
void F_209 ( struct V_2 * V_3 , struct V_299 * V_300 )
{
F_44 ( & V_26 ) ;
}
static inline int F_210 ( struct V_61 * V_306 ,
struct V_307 * time ,
struct V_61 * V_308 )
{
int V_309 = F_211 ( & V_306 -> V_310 , time ) ;
if ( V_309 > 0 ) {
return 1 ;
} else if ( V_309 < 0 ) {
return 0 ;
} else {
return V_306 > V_308 ;
}
}
static inline int F_212 ( void * V_311 , void * V_312 )
{
struct V_61 * V_306 = V_311 ;
struct V_61 * V_308 = V_312 ;
return F_210 ( V_306 , & V_308 -> V_310 , V_308 ) ;
}
int F_213 ( struct V_313 * V_314 )
{
int V_203 , V_13 ;
struct V_299 V_300 ;
struct V_61 * V_303 , * V_315 ;
struct V_61 * V_316 = NULL ;
struct V_317 V_318 ;
struct V_317 * V_319 ;
struct V_307 V_320 = { 0 , 0 } ;
if ( V_314 -> V_319 ) {
V_319 = V_314 -> V_319 ;
V_319 -> V_321 = & F_212 ;
} else {
V_319 = & V_318 ;
V_203 = F_214 ( V_319 , V_322 , V_53 , & F_212 ) ;
if ( V_203 )
return V_203 ;
}
V_323:
V_319 -> V_324 = 0 ;
F_207 ( V_314 -> V_20 , & V_300 ) ;
while ( ( V_303 = F_208 ( V_314 -> V_20 , & V_300 ) ) ) {
if ( V_314 -> V_325 && ! V_314 -> V_325 ( V_303 , V_314 ) )
continue;
if ( ! F_210 ( V_303 , & V_320 , V_316 ) )
continue;
V_315 = F_215 ( V_319 , V_303 ) ;
if ( V_315 == NULL ) {
F_150 ( V_303 ) ;
} else if ( V_315 != V_303 ) {
F_150 ( V_303 ) ;
F_161 ( V_315 ) ;
}
}
F_209 ( V_314 -> V_20 , & V_300 ) ;
if ( V_319 -> V_324 ) {
for ( V_13 = 0 ; V_13 < V_319 -> V_324 ; V_13 ++ ) {
struct V_61 * V_326 = V_319 -> V_327 [ V_13 ] ;
if ( V_13 == 0 ) {
V_320 = V_326 -> V_310 ;
V_316 = V_326 ;
}
V_314 -> V_328 ( V_326 , V_314 ) ;
F_161 ( V_326 ) ;
}
goto V_323;
}
if ( V_319 == & V_318 )
F_216 ( & V_318 ) ;
return 0 ;
}
static void * F_217 ( int V_31 )
{
if ( F_218 ( V_31 ) )
return F_219 ( V_31 * sizeof( V_329 ) ) ;
else
return F_35 ( V_31 * sizeof( V_329 ) , V_53 ) ;
}
static void F_220 ( void * V_303 )
{
if ( F_221 ( V_303 ) )
F_222 ( V_303 ) ;
else
F_21 ( V_303 ) ;
}
static void * F_223 ( void * V_303 , int V_330 )
{
void * V_331 ;
if ( F_221 ( V_303 ) ) {
V_331 = F_219 ( V_330 * sizeof( V_329 ) ) ;
if ( ! V_331 )
return NULL ;
memcpy ( V_331 , V_303 , V_330 * sizeof( V_329 ) ) ;
F_222 ( V_303 ) ;
} else {
V_331 = F_224 ( V_303 , V_330 * sizeof( V_329 ) , V_53 ) ;
}
return V_331 ;
}
static int F_225 ( V_329 * * V_303 , int V_332 )
{
int V_333 , V_334 = 1 ;
V_329 * V_335 = * V_303 ;
V_329 * V_331 ;
if ( V_332 == 0 || V_332 == 1 )
return V_332 ;
for ( V_333 = 1 ; V_333 < V_332 ; V_333 ++ ) {
while ( V_335 [ V_333 ] == V_335 [ V_333 - 1 ] ) {
V_333 ++ ;
if ( V_333 == V_332 )
goto V_336;
}
V_335 [ V_334 ] = V_335 [ V_333 ] ;
V_334 ++ ;
}
V_336:
if ( F_226 ( V_332 , V_334 ) ) {
V_331 = F_223 ( V_335 , V_334 ) ;
if ( V_331 )
* V_303 = V_331 ;
}
return V_334 ;
}
static int F_227 ( const void * V_337 , const void * V_338 )
{
return * ( V_329 * ) V_337 - * ( V_329 * ) V_338 ;
}
static struct V_339 * F_228 ( struct V_2 * V_3 ,
enum V_340 type )
{
struct V_339 * V_301 ;
struct V_341 * V_342 = V_236 -> V_343 -> V_344 ;
F_51 ( & V_3 -> V_146 ) ;
F_47 (l, &cgrp->pidlists, links) {
if ( V_301 -> V_265 . type == type && V_301 -> V_265 . V_342 == V_342 ) {
F_229 ( & V_301 -> V_345 ) ;
F_53 ( & V_3 -> V_146 ) ;
return V_301 ;
}
}
V_301 = F_35 ( sizeof( struct V_339 ) , V_53 ) ;
if ( ! V_301 ) {
F_53 ( & V_3 -> V_146 ) ;
return V_301 ;
}
F_230 ( & V_301 -> V_345 ) ;
F_229 ( & V_301 -> V_345 ) ;
V_301 -> V_265 . type = type ;
V_301 -> V_265 . V_342 = F_231 ( V_342 ) ;
V_301 -> V_346 = 0 ;
V_301 -> V_335 = NULL ;
V_301 -> V_347 = V_3 ;
F_36 ( & V_301 -> V_217 , & V_3 -> V_89 ) ;
F_53 ( & V_3 -> V_146 ) ;
return V_301 ;
}
static int F_232 ( struct V_2 * V_3 , enum V_340 type ,
struct V_339 * * V_348 )
{
V_329 * V_349 ;
int V_332 ;
int V_227 , V_350 = 0 ;
struct V_299 V_300 ;
struct V_61 * V_197 ;
struct V_339 * V_301 ;
V_332 = F_201 ( V_3 ) ;
V_349 = F_217 ( V_332 ) ;
if ( ! V_349 )
return - V_54 ;
F_207 ( V_3 , & V_300 ) ;
while ( ( V_197 = F_208 ( V_3 , & V_300 ) ) ) {
if ( F_81 ( V_350 == V_332 ) )
break;
if ( type == V_351 )
V_227 = F_233 ( V_197 ) ;
else
V_227 = F_234 ( V_197 ) ;
if ( V_227 > 0 )
V_349 [ V_350 ++ ] = V_227 ;
}
F_209 ( V_3 , & V_300 ) ;
V_332 = V_350 ;
F_235 ( V_349 , V_332 , sizeof( V_329 ) , F_227 , NULL ) ;
if ( type == V_351 )
V_332 = F_225 ( & V_349 , V_332 ) ;
V_301 = F_228 ( V_3 , type ) ;
if ( ! V_301 ) {
F_220 ( V_349 ) ;
return - V_54 ;
}
F_220 ( V_301 -> V_335 ) ;
V_301 -> V_335 = V_349 ;
V_301 -> V_332 = V_332 ;
V_301 -> V_346 ++ ;
F_236 ( & V_301 -> V_345 ) ;
* V_348 = V_301 ;
return 0 ;
}
int F_237 ( struct V_352 * V_353 , struct V_85 * V_85 )
{
int V_83 = - V_135 ;
struct V_2 * V_3 ;
struct V_299 V_300 ;
struct V_61 * V_197 ;
if ( V_85 -> V_354 -> V_163 != & V_164 ||
! F_62 ( V_85 -> V_93 -> V_71 ) )
goto V_276;
V_83 = 0 ;
V_3 = V_85 -> V_86 ;
F_207 ( V_3 , & V_300 ) ;
while ( ( V_197 = F_208 ( V_3 , & V_300 ) ) ) {
switch ( V_197 -> V_268 ) {
case V_355 :
V_353 -> V_356 ++ ;
break;
case V_357 :
V_353 -> V_358 ++ ;
break;
case V_359 :
V_353 -> V_360 ++ ;
break;
case V_361 :
V_353 -> V_362 ++ ;
break;
default:
if ( F_238 ( V_197 ) )
V_353 -> V_363 ++ ;
break;
}
}
F_209 ( V_3 , & V_300 ) ;
V_276:
return V_83 ;
}
static void * F_239 ( struct V_116 * V_364 , T_6 * V_365 )
{
struct V_339 * V_301 = V_364 -> V_259 ;
int V_14 = 0 , V_227 = * V_365 ;
int * V_366 ;
F_240 ( & V_301 -> V_345 ) ;
if ( V_227 ) {
int V_245 = V_301 -> V_332 ;
while ( V_14 < V_245 ) {
int V_367 = ( V_14 + V_245 ) / 2 ;
if ( V_301 -> V_335 [ V_367 ] == V_227 ) {
V_14 = V_367 ;
break;
} else if ( V_301 -> V_335 [ V_367 ] <= V_227 )
V_14 = V_367 + 1 ;
else
V_245 = V_367 ;
}
}
if ( V_14 >= V_301 -> V_332 )
return NULL ;
V_366 = V_301 -> V_335 + V_14 ;
* V_365 = * V_366 ;
return V_366 ;
}
static void F_241 ( struct V_116 * V_364 , void * V_368 )
{
struct V_339 * V_301 = V_364 -> V_259 ;
F_242 ( & V_301 -> V_345 ) ;
}
static void * F_243 ( struct V_116 * V_364 , void * V_368 , T_6 * V_365 )
{
struct V_339 * V_301 = V_364 -> V_259 ;
V_329 * V_303 = V_368 ;
V_329 * V_245 = V_301 -> V_335 + V_301 -> V_332 ;
V_303 ++ ;
if ( V_303 >= V_245 ) {
return NULL ;
} else {
* V_365 = * V_303 ;
return V_303 ;
}
}
static int F_244 ( struct V_116 * V_364 , void * V_368 )
{
return F_93 ( V_364 , L_18 , * ( int * ) V_368 ) ;
}
static void F_245 ( struct V_339 * V_301 )
{
F_51 ( & V_301 -> V_347 -> V_146 ) ;
F_229 ( & V_301 -> V_345 ) ;
F_28 ( ! V_301 -> V_346 ) ;
if ( ! -- V_301 -> V_346 ) {
F_18 ( & V_301 -> V_217 ) ;
F_53 ( & V_301 -> V_347 -> V_146 ) ;
F_220 ( V_301 -> V_335 ) ;
F_246 ( V_301 -> V_265 . V_342 ) ;
F_236 ( & V_301 -> V_345 ) ;
F_21 ( V_301 ) ;
return;
}
F_53 ( & V_301 -> V_347 -> V_146 ) ;
F_236 ( & V_301 -> V_345 ) ;
}
static int F_247 ( struct V_66 * V_66 , struct V_240 * V_240 )
{
struct V_339 * V_301 ;
if ( ! ( V_240 -> V_369 & V_370 ) )
return 0 ;
V_301 = ( (struct V_116 * ) V_240 -> V_275 ) -> V_259 ;
F_245 ( V_301 ) ;
return F_248 ( V_66 , V_240 ) ;
}
static int F_249 ( struct V_240 * V_240 , enum V_340 type )
{
struct V_2 * V_3 = F_132 ( V_240 -> V_256 -> V_92 ) ;
struct V_339 * V_301 ;
int V_203 ;
if ( ! ( V_240 -> V_369 & V_370 ) )
return 0 ;
V_203 = F_232 ( V_3 , type , & V_301 ) ;
if ( V_203 )
return V_203 ;
V_240 -> V_278 = & V_371 ;
V_203 = F_250 ( V_240 , & V_372 ) ;
if ( V_203 ) {
F_245 ( V_301 ) ;
return V_203 ;
}
( (struct V_116 * ) V_240 -> V_275 ) -> V_259 = V_301 ;
return 0 ;
}
static int F_251 ( struct V_66 * V_373 , struct V_240 * V_240 )
{
return F_249 ( V_240 , V_374 ) ;
}
static int F_252 ( struct V_66 * V_373 , struct V_240 * V_240 )
{
return F_249 ( V_240 , V_351 ) ;
}
static T_2 F_253 ( struct V_2 * V_3 ,
struct V_189 * V_237 )
{
return F_7 ( V_3 ) ;
}
static int F_254 ( struct V_2 * V_3 ,
struct V_189 * V_237 ,
T_2 V_249 )
{
F_255 ( V_7 , & V_3 -> V_5 ) ;
if ( V_249 )
F_19 ( V_8 , & V_3 -> V_5 ) ;
else
F_255 ( V_8 , & V_3 -> V_5 ) ;
return 0 ;
}
static void F_256 ( struct V_375 * V_376 )
{
struct V_377 * V_378 = F_257 ( V_376 , struct V_377 ,
remove ) ;
struct V_2 * V_3 = V_378 -> V_3 ;
V_378 -> V_237 -> V_379 ( V_3 , V_378 -> V_237 , V_378 -> V_380 ) ;
F_258 ( V_378 -> V_380 ) ;
F_21 ( V_378 ) ;
F_71 ( V_3 -> V_85 ) ;
}
static int F_259 ( T_8 * V_381 , unsigned V_67 ,
int V_382 , void * V_265 )
{
struct V_377 * V_378 = F_257 ( V_381 ,
struct V_377 , V_381 ) ;
struct V_2 * V_3 = V_378 -> V_3 ;
unsigned long V_5 = ( unsigned long ) V_265 ;
if ( V_5 & V_383 ) {
F_260 ( V_378 -> V_384 , & V_378 -> V_381 ) ;
F_73 ( & V_3 -> V_148 ) ;
F_18 ( & V_378 -> V_335 ) ;
F_77 ( & V_3 -> V_148 ) ;
F_261 ( & V_378 -> remove ) ;
}
return 0 ;
}
static void F_262 ( struct V_240 * V_240 ,
T_9 * V_384 , T_10 * V_385 )
{
struct V_377 * V_378 = F_257 ( V_385 ,
struct V_377 , V_385 ) ;
V_378 -> V_384 = V_384 ;
F_263 ( V_384 , & V_378 -> V_381 ) ;
}
static int F_264 ( struct V_2 * V_3 , struct V_189 * V_237 ,
const char * V_239 )
{
struct V_377 * V_378 = NULL ;
unsigned int V_386 , V_387 ;
struct V_240 * V_388 = NULL ;
struct V_240 * V_389 = NULL ;
char * V_390 ;
int V_83 ;
V_386 = F_265 ( V_239 , & V_390 , 10 ) ;
if ( * V_390 != ' ' )
return - V_135 ;
V_239 = V_390 + 1 ;
V_387 = F_265 ( V_239 , & V_390 , 10 ) ;
if ( ( * V_390 != ' ' ) && ( * V_390 != '\0' ) )
return - V_135 ;
V_239 = V_390 + 1 ;
V_378 = F_113 ( sizeof( * V_378 ) , V_53 ) ;
if ( ! V_378 )
return - V_54 ;
V_378 -> V_3 = V_3 ;
F_34 ( & V_378 -> V_335 ) ;
F_266 ( & V_378 -> V_385 , F_262 ) ;
F_267 ( & V_378 -> V_381 , F_259 ) ;
F_268 ( & V_378 -> remove , F_256 ) ;
V_388 = F_269 ( V_386 ) ;
if ( F_123 ( V_388 ) ) {
V_83 = F_124 ( V_388 ) ;
goto V_391;
}
V_378 -> V_380 = F_270 ( V_388 ) ;
if ( F_123 ( V_378 -> V_380 ) ) {
V_83 = F_124 ( V_378 -> V_380 ) ;
goto V_391;
}
V_389 = F_271 ( V_387 ) ;
if ( ! V_389 ) {
V_83 = - V_392 ;
goto V_391;
}
V_83 = F_272 ( V_389 -> V_393 . V_85 -> V_93 , V_394 ) ;
if ( V_83 < 0 )
goto V_391;
V_378 -> V_237 = F_191 ( V_389 ) ;
if ( F_123 ( V_378 -> V_237 ) ) {
V_83 = F_124 ( V_378 -> V_237 ) ;
goto V_391;
}
if ( ! V_378 -> V_237 -> V_395 || ! V_378 -> V_237 -> V_379 ) {
V_83 = - V_135 ;
goto V_391;
}
V_83 = V_378 -> V_237 -> V_395 ( V_3 , V_378 -> V_237 ,
V_378 -> V_380 , V_239 ) ;
if ( V_83 )
goto V_391;
if ( V_388 -> V_278 -> V_396 ( V_388 , & V_378 -> V_385 ) & V_383 ) {
V_378 -> V_237 -> V_379 ( V_3 , V_378 -> V_237 , V_378 -> V_380 ) ;
V_83 = 0 ;
goto V_391;
}
F_68 ( V_3 -> V_85 ) ;
F_73 ( & V_3 -> V_148 ) ;
F_36 ( & V_378 -> V_335 , & V_3 -> V_147 ) ;
F_77 ( & V_3 -> V_148 ) ;
F_273 ( V_389 ) ;
F_273 ( V_388 ) ;
return 0 ;
V_391:
if ( V_389 )
F_273 ( V_389 ) ;
if ( V_378 && V_378 -> V_380 && ! F_123 ( V_378 -> V_380 ) )
F_258 ( V_378 -> V_380 ) ;
if ( ! F_274 ( V_388 ) )
F_273 ( V_388 ) ;
F_21 ( V_378 ) ;
return V_83 ;
}
static T_2 F_275 ( struct V_2 * V_3 ,
struct V_189 * V_237 )
{
return F_8 ( V_3 ) ;
}
static int F_276 ( struct V_2 * V_3 ,
struct V_189 * V_237 ,
T_2 V_249 )
{
if ( V_249 )
F_19 ( V_9 , & V_3 -> V_5 ) ;
else
F_255 ( V_9 , & V_3 -> V_5 ) ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 )
{
int V_276 ;
struct V_81 * V_82 ;
F_72 ( V_3 -> V_85 ) ;
V_276 = F_200 ( V_3 , NULL , V_397 , F_277 ( V_397 ) ) ;
if ( V_276 < 0 )
return V_276 ;
if ( V_3 == V_3 -> V_65 ) {
if ( ( V_276 = F_198 ( V_3 , NULL , & V_398 ) ) < 0 )
return V_276 ;
}
F_60 (cgrp->root, ss) {
if ( V_82 -> V_399 && ( V_276 = V_82 -> V_399 ( V_82 , V_3 ) ) < 0 )
return V_276 ;
}
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_400 ] ;
if ( V_12 -> V_401 )
F_140 ( V_12 -> V_401 -> V_12 , V_12 ) ;
}
return 0 ;
}
static void F_278 ( struct V_11 * V_12 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
V_12 -> V_2 = V_3 ;
F_45 ( & V_12 -> V_402 , 1 ) ;
V_12 -> V_5 = 0 ;
V_12 -> V_401 = NULL ;
if ( V_3 == V_110 )
F_19 ( V_403 , & V_12 -> V_5 ) ;
F_28 ( V_3 -> V_39 [ V_82 -> V_400 ] ) ;
V_3 -> V_39 [ V_82 -> V_400 ] = V_12 ;
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
int V_276 = 0 ;
struct V_81 * V_82 ;
struct V_68 * V_69 = V_46 -> V_69 ;
V_3 = F_113 ( sizeof( * V_3 ) , V_53 ) ;
if ( ! V_3 )
return - V_54 ;
F_24 ( & V_69 -> V_404 ) ;
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
struct V_11 * V_12 = V_82 -> V_405 ( V_82 , V_3 ) ;
if ( F_123 ( V_12 ) ) {
V_276 = F_124 ( V_12 ) ;
goto V_406;
}
F_278 ( V_12 , V_82 , V_3 ) ;
if ( V_82 -> V_407 ) {
V_276 = F_282 ( V_82 , V_91 , V_3 ) ;
if ( V_276 )
goto V_406;
}
if ( F_8 ( V_91 ) && V_82 -> V_408 )
V_82 -> V_408 ( V_82 , V_3 ) ;
}
F_279 ( V_46 ) ;
F_36 ( & V_3 -> V_112 , & V_3 -> V_91 -> V_144 ) ;
F_280 ( V_46 ) ;
V_46 -> V_88 ++ ;
V_276 = F_196 ( V_3 , V_85 , V_67 ) ;
if ( V_276 < 0 )
goto V_409;
F_28 ( ! F_3 ( & V_3 -> V_85 -> V_93 -> V_94 ) ) ;
V_276 = F_102 ( V_3 ) ;
F_53 ( & V_1 ) ;
F_53 ( & V_3 -> V_85 -> V_93 -> V_94 ) ;
return 0 ;
V_409:
F_279 ( V_46 ) ;
F_18 ( & V_3 -> V_112 ) ;
F_280 ( V_46 ) ;
V_46 -> V_88 -- ;
V_406:
F_60 (root, ss) {
if ( V_3 -> V_39 [ V_82 -> V_400 ] )
V_82 -> V_87 ( V_82 , V_3 ) ;
}
F_53 ( & V_1 ) ;
F_64 ( V_69 ) ;
F_21 ( V_3 ) ;
return V_276 ;
}
static int F_283 ( struct V_66 * V_289 , struct V_85 * V_85 , int V_67 )
{
struct V_2 * V_410 = V_85 -> V_92 -> V_86 ;
return F_281 ( V_410 , V_85 , V_67 | V_100 ) ;
}
static int F_284 ( struct V_2 * V_3 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
struct V_11 * V_12 ;
if ( V_82 == NULL || V_82 -> V_46 != V_3 -> V_46 )
continue;
V_12 = V_3 -> V_39 [ V_82 -> V_400 ] ;
if ( V_12 && ( F_202 ( & V_12 -> V_402 ) > 1 ) )
return 1 ;
}
return 0 ;
}
static int F_285 ( struct V_2 * V_3 )
{
struct V_81 * V_82 ;
unsigned long V_5 ;
bool V_411 = false ;
F_286 ( V_5 ) ;
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_400 ] ;
int V_402 ;
while ( 1 ) {
V_402 = F_202 ( & V_12 -> V_402 ) ;
if ( V_402 > 1 ) {
V_411 = true ;
goto V_412;
}
F_28 ( ! V_402 ) ;
if ( F_287 ( & V_12 -> V_402 , V_402 , 0 ) == V_402 )
break;
F_288 () ;
}
}
V_412:
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_400 ] ;
if ( V_411 ) {
if ( ! F_202 ( & V_12 -> V_402 ) )
F_45 ( & V_12 -> V_402 , 1 ) ;
} else {
F_19 ( V_413 , & V_12 -> V_5 ) ;
}
}
F_289 ( V_5 ) ;
return ! V_411 ;
}
static int F_290 ( struct V_66 * V_414 , struct V_85 * V_85 )
{
struct V_2 * V_3 = V_85 -> V_86 ;
struct V_85 * V_90 ;
struct V_2 * V_91 ;
F_291 ( V_381 ) ;
struct V_377 * V_378 , * V_15 ;
int V_83 ;
V_323:
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
F_292 ( & V_102 , & V_381 , V_357 ) ;
if ( ! F_285 ( V_3 ) ) {
F_53 ( & V_1 ) ;
if ( F_5 ( V_101 , & V_3 -> V_5 ) )
F_293 () ;
F_294 ( & V_102 , & V_381 ) ;
F_255 ( V_101 , & V_3 -> V_5 ) ;
if ( F_295 ( V_236 ) )
return - V_415 ;
goto V_323;
}
F_294 ( & V_102 , & V_381 ) ;
F_255 ( V_101 , & V_3 -> V_5 ) ;
F_296 ( & V_416 ) ;
F_19 ( V_4 , & V_3 -> V_5 ) ;
if ( ! F_38 ( & V_3 -> V_145 ) )
F_75 ( & V_3 -> V_145 ) ;
F_297 ( & V_416 ) ;
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
F_18 ( & V_378 -> V_335 ) ;
F_298 ( V_378 -> V_384 , & V_378 -> V_381 ) ;
F_299 ( V_378 -> V_380 , 1 ) ;
F_261 ( & V_378 -> remove ) ;
}
F_77 ( & V_3 -> V_148 ) ;
F_53 ( & V_1 ) ;
return 0 ;
}
static void T_11 F_300 ( struct V_81 * V_82 )
{
struct V_11 * V_12 ;
F_301 ( V_417 L_19 , V_82 -> V_122 ) ;
F_36 ( & V_82 -> V_112 , & V_108 . V_113 ) ;
V_82 -> V_46 = & V_108 ;
V_12 = V_82 -> V_405 ( V_82 , V_110 ) ;
F_28 ( F_123 ( V_12 ) ) ;
F_278 ( V_12 , V_82 , V_110 ) ;
V_64 . V_39 [ V_82 -> V_400 ] = V_110 -> V_39 [ V_82 -> V_400 ] ;
V_418 |= V_82 -> V_419 || V_82 -> exit ;
F_28 ( ! F_38 ( & V_420 . V_59 ) ) ;
F_104 ( & V_82 -> V_111 ) ;
F_302 ( & V_82 -> V_111 , & V_82 -> V_421 ) ;
V_82 -> V_422 = 1 ;
F_28 ( V_82 -> V_115 ) ;
}
int T_12 F_303 ( struct V_81 * V_82 )
{
int V_13 ;
struct V_11 * V_12 ;
if ( V_82 -> V_122 == NULL || strlen ( V_82 -> V_122 ) > V_296 ||
V_82 -> V_405 == NULL || V_82 -> V_87 == NULL )
return - V_135 ;
if ( V_82 -> V_419 || V_82 -> exit )
return - V_135 ;
if ( V_82 -> V_115 == NULL ) {
F_28 ( V_82 -> V_400 >= V_142 ) ;
F_28 ( V_39 [ V_82 -> V_400 ] != V_82 ) ;
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
V_82 -> V_400 = V_13 ;
V_39 [ V_13 ] = V_82 ;
V_12 = V_82 -> V_405 ( V_82 , V_110 ) ;
if ( F_123 ( V_12 ) ) {
V_39 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
return F_124 ( V_12 ) ;
}
F_36 ( & V_82 -> V_112 , & V_108 . V_113 ) ;
V_82 -> V_46 = & V_108 ;
F_278 ( V_12 , V_82 , V_110 ) ;
if ( V_82 -> V_407 ) {
int V_83 = F_304 ( V_82 , V_12 ) ;
if ( V_83 ) {
V_110 -> V_39 [ V_82 -> V_400 ] = NULL ;
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
struct V_10 * V_423 = & V_18 [ V_13 ] , * V_424 ;
F_305 (cg, node, tmp, bucket, hlist) {
if ( V_20 -> V_39 [ V_82 -> V_400 ] )
continue;
F_16 ( & V_20 -> V_27 ) ;
V_20 -> V_39 [ V_82 -> V_400 ] = V_12 ;
V_424 = F_9 ( V_20 -> V_39 ) ;
F_48 ( & V_20 -> V_27 , V_424 ) ;
}
}
F_15 ( & V_26 ) ;
F_104 ( & V_82 -> V_111 ) ;
F_302 ( & V_82 -> V_111 , & V_82 -> V_421 ) ;
V_82 -> V_422 = 1 ;
F_53 ( & V_1 ) ;
return 0 ;
}
void F_306 ( struct V_81 * V_82 )
{
struct V_22 * V_23 ;
struct V_10 * V_49 ;
F_28 ( V_82 -> V_115 == NULL ) ;
F_28 ( V_82 -> V_46 != & V_108 ) ;
F_51 ( & V_1 ) ;
F_28 ( V_82 -> V_400 < V_142 ) ;
V_39 [ V_82 -> V_400 ] = NULL ;
F_75 ( & V_82 -> V_112 ) ;
F_13 ( & V_26 ) ;
F_47 (link, &dummytop->css_sets, cgrp_link_list) {
struct V_19 * V_20 = V_23 -> V_20 ;
F_16 ( & V_20 -> V_27 ) ;
F_28 ( ! V_20 -> V_39 [ V_82 -> V_400 ] ) ;
V_20 -> V_39 [ V_82 -> V_400 ] = NULL ;
V_49 = F_9 ( V_20 -> V_39 ) ;
F_48 ( & V_20 -> V_27 , V_49 ) ;
}
F_15 ( & V_26 ) ;
V_82 -> V_87 ( V_82 , V_110 ) ;
V_110 -> V_39 [ V_82 -> V_400 ] = NULL ;
F_53 ( & V_1 ) ;
}
int T_11 F_307 ( void )
{
int V_13 ;
F_45 ( & V_64 . V_25 , 1 ) ;
F_34 ( & V_64 . V_40 ) ;
F_34 ( & V_64 . V_59 ) ;
F_46 ( & V_64 . V_27 ) ;
V_28 = 1 ;
F_106 ( & V_108 ) ;
V_58 = 1 ;
V_420 . V_63 = & V_64 ;
V_425 . V_20 = & V_64 ;
V_425 . V_3 = V_110 ;
F_36 ( & V_425 . V_30 ,
& V_108 . V_65 . V_56 ) ;
F_36 ( & V_425 . V_29 ,
& V_64 . V_40 ) ;
for ( V_13 = 0 ; V_13 < V_187 ; V_13 ++ )
F_308 ( & V_18 [ V_13 ] ) ;
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
F_28 ( ! V_82 -> V_122 ) ;
F_28 ( strlen ( V_82 -> V_122 ) > V_296 ) ;
F_28 ( ! V_82 -> V_405 ) ;
F_28 ( ! V_82 -> V_87 ) ;
if ( V_82 -> V_400 != V_13 ) {
F_301 ( V_426 L_20 ,
V_82 -> V_122 , V_82 -> V_400 ) ;
F_309 () ;
}
if ( V_82 -> V_427 )
F_300 ( V_82 ) ;
}
return 0 ;
}
int T_11 F_310 ( void )
{
int V_276 ;
int V_13 ;
struct V_10 * V_49 ;
V_276 = F_311 ( & V_80 ) ;
if ( V_276 )
return V_276 ;
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( ! V_82 -> V_427 )
F_300 ( V_82 ) ;
if ( V_82 -> V_407 )
F_304 ( V_82 , V_64 . V_39 [ V_82 -> V_400 ] ) ;
}
V_49 = F_9 ( V_64 . V_39 ) ;
F_48 ( & V_64 . V_27 , V_49 ) ;
F_28 ( ! F_107 ( & V_108 ) ) ;
V_428 = F_312 ( L_21 , V_429 ) ;
if ( ! V_428 ) {
V_276 = - V_54 ;
goto V_206;
}
V_276 = F_313 ( & V_430 ) ;
if ( V_276 < 0 ) {
F_314 ( V_428 ) ;
goto V_206;
}
F_315 ( L_22 , 0 , NULL , & V_431 ) ;
V_206:
if ( V_276 )
F_316 ( & V_80 ) ;
return V_276 ;
}
static int F_317 ( struct V_116 * V_269 , void * V_368 )
{
struct V_227 * V_227 ;
struct V_61 * V_197 ;
char * V_190 ;
int V_203 ;
struct V_48 * V_46 ;
V_203 = - V_54 ;
V_190 = F_35 ( V_322 , V_53 ) ;
if ( ! V_190 )
goto V_206;
V_203 = - V_201 ;
V_227 = V_269 -> V_259 ;
V_197 = F_318 ( V_227 , V_432 ) ;
if ( ! V_197 )
goto V_433;
V_203 = 0 ;
F_51 ( & V_1 ) ;
F_126 (root) {
struct V_81 * V_82 ;
struct V_2 * V_3 ;
int V_31 = 0 ;
F_93 ( V_269 , L_23 , V_46 -> V_153 ) ;
F_60 (root, ss)
F_93 ( V_269 , L_24 , V_31 ++ ? L_6 : L_25 , V_82 -> V_122 ) ;
if ( strlen ( V_46 -> V_122 ) )
F_93 ( V_269 , L_26 , V_31 ? L_6 : L_25 ,
V_46 -> V_122 ) ;
F_167 ( V_269 , ':' ) ;
V_3 = F_49 ( V_197 , V_46 ) ;
V_203 = F_134 ( V_3 , V_190 , V_322 ) ;
if ( V_203 < 0 )
goto V_143;
F_94 ( V_269 , V_190 ) ;
F_167 ( V_269 , '\n' ) ;
}
V_143:
F_53 ( & V_1 ) ;
F_161 ( V_197 ) ;
V_433:
F_21 ( V_190 ) ;
V_206:
return V_203 ;
}
static int F_319 ( struct V_66 * V_66 , struct V_240 * V_240 )
{
struct V_227 * V_227 = F_320 ( V_66 ) -> V_227 ;
return F_185 ( V_240 , F_317 , V_227 ) ;
}
static int F_321 ( struct V_116 * V_269 , void * V_368 )
{
int V_13 ;
F_94 ( V_269 , L_27 ) ;
F_51 ( & V_1 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
F_93 ( V_269 , L_28 ,
V_82 -> V_122 , V_82 -> V_46 -> V_153 ,
V_82 -> V_46 -> V_88 , ! V_82 -> V_140 ) ;
}
F_53 ( & V_1 ) ;
return 0 ;
}
static int F_322 ( struct V_66 * V_66 , struct V_240 * V_240 )
{
return F_185 ( V_240 , F_321 , NULL ) ;
}
void F_323 ( struct V_61 * V_434 )
{
F_137 ( V_236 ) ;
V_434 -> V_63 = V_236 -> V_63 ;
F_23 ( V_434 -> V_63 ) ;
F_138 ( V_236 ) ;
F_34 ( & V_434 -> V_202 ) ;
}
void F_324 ( struct V_61 * V_434 )
{
if ( V_418 ) {
int V_13 ;
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 -> V_419 )
V_82 -> V_419 ( V_82 , V_434 ) ;
}
}
}
void F_325 ( struct V_61 * V_434 )
{
if ( V_305 ) {
F_13 ( & V_26 ) ;
F_137 ( V_434 ) ;
if ( F_38 ( & V_434 -> V_202 ) )
F_36 ( & V_434 -> V_202 , & V_434 -> V_63 -> V_59 ) ;
F_138 ( V_434 ) ;
F_15 ( & V_26 ) ;
}
}
void F_326 ( struct V_61 * V_197 , int V_435 )
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
if ( V_435 && V_418 ) {
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 -> exit ) {
struct V_2 * V_436 =
F_327 ( V_20 -> V_39 [ V_13 ] ) -> V_2 ;
struct V_2 * V_3 = F_328 ( V_197 , V_13 ) ;
V_82 -> exit ( V_82 , V_3 , V_436 , V_197 ) ;
}
}
}
F_138 ( V_197 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
}
int F_329 ( const struct V_2 * V_3 , struct V_61 * V_62 )
{
int V_83 ;
struct V_2 * V_437 ;
if ( V_3 == V_110 )
return 1 ;
V_437 = F_49 ( V_62 , V_3 -> V_46 ) ;
while ( V_3 != V_437 && V_3 != V_3 -> V_65 )
V_3 = V_3 -> V_91 ;
V_83 = ( V_3 == V_437 ) ;
return V_83 ;
}
static void F_20 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 ) && ! F_202 ( & V_3 -> V_31 )
&& F_38 ( & V_3 -> V_144 ) && ! F_284 ( V_3 ) ) {
int V_438 = 0 ;
F_296 ( & V_416 ) ;
if ( ! F_4 ( V_3 ) &&
F_38 ( & V_3 -> V_145 ) ) {
F_36 ( & V_3 -> V_145 , & V_145 ) ;
V_438 = 1 ;
}
F_297 ( & V_416 ) ;
if ( V_438 )
F_261 ( & V_439 ) ;
}
}
void F_330 ( struct V_11 * V_12 , int V_31 )
{
struct V_2 * V_3 = V_12 -> V_2 ;
int V_249 ;
F_155 () ;
V_249 = F_331 ( V_31 , & V_12 -> V_402 ) ;
if ( V_249 == 1 ) {
if ( F_7 ( V_3 ) ) {
F_19 ( V_7 , & V_3 -> V_5 ) ;
F_20 ( V_3 ) ;
}
F_80 ( V_3 ) ;
}
F_157 () ;
F_332 ( V_249 < 1 ) ;
}
static void F_333 ( struct V_375 * V_376 )
{
F_28 ( V_376 != & V_439 ) ;
F_51 ( & V_1 ) ;
F_296 ( & V_416 ) ;
while ( ! F_38 ( & V_145 ) ) {
char * V_440 [ 3 ] , * V_441 [ 3 ] ;
int V_13 ;
char * V_442 = NULL , * V_443 = NULL ;
struct V_2 * V_3 = F_29 ( V_145 . V_45 ,
struct V_2 ,
V_145 ) ;
F_75 ( & V_3 -> V_145 ) ;
F_297 ( & V_416 ) ;
V_442 = F_35 ( V_322 , V_53 ) ;
if ( ! V_442 )
goto V_444;
if ( F_134 ( V_3 , V_442 , V_322 ) < 0 )
goto V_444;
V_443 = F_334 ( V_3 -> V_46 -> V_124 , V_53 ) ;
if ( ! V_443 )
goto V_444;
V_13 = 0 ;
V_440 [ V_13 ++ ] = V_443 ;
V_440 [ V_13 ++ ] = V_442 ;
V_440 [ V_13 ] = NULL ;
V_13 = 0 ;
V_441 [ V_13 ++ ] = L_29 ;
V_441 [ V_13 ++ ] = L_30 ;
V_441 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
F_335 ( V_440 [ 0 ] , V_440 , V_441 , V_445 ) ;
F_51 ( & V_1 ) ;
V_444:
F_21 ( V_442 ) ;
F_21 ( V_443 ) ;
F_296 ( & V_416 ) ;
}
F_297 ( & V_416 ) ;
F_53 ( & V_1 ) ;
}
static int T_11 F_336 ( char * V_446 )
{
int V_13 ;
char * V_128 ;
while ( ( V_128 = F_97 ( & V_446 , L_6 ) ) != NULL ) {
if ( ! * V_128 )
continue;
for ( V_13 = 0 ; V_13 < V_142 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( ! strcmp ( V_128 , V_82 -> V_122 ) ) {
V_82 -> V_140 = 1 ;
F_301 ( V_417 L_31
L_32 , V_82 -> V_122 ) ;
break;
}
}
}
return 1 ;
}
unsigned short F_337 ( struct V_11 * V_12 )
{
struct F_337 * V_447 ;
V_447 = F_135 ( V_12 -> V_401 , F_202 ( & V_12 -> V_402 ) ) ;
if ( V_447 )
return V_447 -> V_401 ;
return 0 ;
}
unsigned short F_338 ( struct V_11 * V_12 )
{
struct F_337 * V_447 ;
V_447 = F_135 ( V_12 -> V_401 , F_202 ( & V_12 -> V_402 ) ) ;
if ( V_447 )
return V_447 -> V_448 ;
return 0 ;
}
bool F_339 ( struct V_11 * V_434 ,
const struct V_11 * V_46 )
{
struct F_337 * V_449 ;
struct F_337 * V_450 ;
bool V_83 = true ;
F_155 () ;
V_449 = F_340 ( V_434 -> V_401 ) ;
V_450 = F_340 ( V_46 -> V_401 ) ;
if ( ! V_449
|| ! V_450
|| ( V_449 -> V_448 < V_450 -> V_448 )
|| ( V_449 -> V_451 [ V_450 -> V_448 ] != V_450 -> V_401 ) )
V_83 = false ;
F_157 () ;
return V_83 ;
}
void F_341 ( struct V_81 * V_82 , struct V_11 * V_12 )
{
struct F_337 * V_401 = V_12 -> V_401 ;
if ( ! V_401 )
return;
F_28 ( ! V_82 -> V_407 ) ;
F_140 ( V_401 -> V_12 , NULL ) ;
F_140 ( V_12 -> V_401 , NULL ) ;
F_13 ( & V_82 -> V_452 ) ;
F_342 ( & V_82 -> V_453 , V_401 -> V_401 ) ;
F_15 ( & V_82 -> V_452 ) ;
F_22 ( V_401 , V_32 ) ;
}
static struct F_337 * F_343 ( struct V_81 * V_82 , int V_448 )
{
struct F_337 * V_454 ;
int V_455 , error , V_324 ;
F_28 ( ! V_82 -> V_407 ) ;
V_324 = sizeof( * V_454 ) + sizeof( unsigned short ) * ( V_448 + 1 ) ;
V_454 = F_113 ( V_324 , V_53 ) ;
if ( ! V_454 )
return F_114 ( - V_54 ) ;
if ( F_81 ( ! F_344 ( & V_82 -> V_453 , V_53 ) ) ) {
error = - V_54 ;
goto V_456;
}
F_13 ( & V_82 -> V_452 ) ;
error = F_345 ( & V_82 -> V_453 , V_454 , 1 , & V_455 ) ;
F_15 ( & V_82 -> V_452 ) ;
if ( error ) {
error = - V_154 ;
goto V_456;
}
if ( V_455 > V_457 )
goto V_458;
V_454 -> V_401 = V_455 ;
V_454 -> V_448 = V_448 ;
return V_454 ;
V_458:
error = - V_154 ;
F_13 ( & V_82 -> V_452 ) ;
F_342 ( & V_82 -> V_453 , V_455 ) ;
F_15 ( & V_82 -> V_452 ) ;
V_456:
F_21 ( V_454 ) ;
return F_114 ( error ) ;
}
static int T_12 F_304 ( struct V_81 * V_82 ,
struct V_11 * V_459 )
{
struct F_337 * V_454 ;
F_346 ( & V_82 -> V_452 ) ;
F_347 ( & V_82 -> V_453 ) ;
V_454 = F_343 ( V_82 , 0 ) ;
if ( F_123 ( V_454 ) )
return F_124 ( V_454 ) ;
V_454 -> V_451 [ 0 ] = V_454 -> V_401 ;
V_454 -> V_12 = V_459 ;
V_459 -> V_401 = V_454 ;
return 0 ;
}
static int F_282 ( struct V_81 * V_82 , struct V_2 * V_91 ,
struct V_2 * V_434 )
{
int V_400 , V_13 , V_448 = 0 ;
struct V_11 * V_460 , * V_461 ;
struct F_337 * V_449 , * V_462 ;
V_400 = V_82 -> V_400 ;
V_460 = V_91 -> V_39 [ V_400 ] ;
V_461 = V_434 -> V_39 [ V_400 ] ;
V_462 = V_460 -> V_401 ;
V_448 = V_462 -> V_448 + 1 ;
V_449 = F_343 ( V_82 , V_448 ) ;
if ( F_123 ( V_449 ) )
return F_124 ( V_449 ) ;
for ( V_13 = 0 ; V_13 < V_448 ; V_13 ++ )
V_449 -> V_451 [ V_13 ] = V_462 -> V_451 [ V_13 ] ;
V_449 -> V_451 [ V_448 ] = V_449 -> V_401 ;
F_140 ( V_461 -> V_401 , V_449 ) ;
return 0 ;
}
struct V_11 * F_348 ( struct V_81 * V_82 , int V_401 )
{
struct F_337 * V_447 = NULL ;
F_28 ( ! V_82 -> V_407 ) ;
V_447 = F_349 ( & V_82 -> V_453 , V_401 ) ;
if ( F_81 ( ! V_447 ) )
return NULL ;
return F_340 ( V_447 -> V_12 ) ;
}
struct V_11 *
F_350 ( struct V_81 * V_82 , int V_401 ,
struct V_11 * V_46 , int * V_463 )
{
struct V_11 * V_83 = NULL ;
struct F_337 * V_15 ;
int V_464 ;
int V_465 = F_337 ( V_46 ) ;
int V_448 = F_338 ( V_46 ) ;
if ( ! V_465 )
return NULL ;
F_28 ( ! V_82 -> V_407 ) ;
V_464 = V_401 ;
while ( 1 ) {
F_43 ( & V_82 -> V_452 ) ;
V_15 = F_351 ( & V_82 -> V_453 , & V_464 ) ;
F_44 ( & V_82 -> V_452 ) ;
if ( ! V_15 )
break;
if ( V_15 -> V_448 >= V_448 && V_15 -> V_451 [ V_448 ] == V_465 ) {
V_83 = F_340 ( V_15 -> V_12 ) ;
if ( V_83 ) {
* V_463 = V_464 ;
break;
}
}
V_464 = V_464 + 1 ;
}
return V_83 ;
}
struct V_11 * F_352 ( struct V_240 * V_466 , int V_401 )
{
struct V_2 * V_3 ;
struct V_66 * V_66 ;
struct V_11 * V_12 ;
V_66 = V_466 -> V_256 -> V_93 ;
if ( V_66 -> V_173 != & V_174 )
return F_114 ( - V_392 ) ;
if ( V_401 < 0 || V_401 >= V_16 )
return F_114 ( - V_135 ) ;
V_3 = F_132 ( V_466 -> V_256 ) ;
V_12 = V_3 -> V_39 [ V_401 ] ;
return V_12 ? V_12 : F_114 ( - V_141 ) ;
}
static struct V_11 * F_353 ( struct V_81 * V_82 ,
struct V_2 * V_467 )
{
struct V_11 * V_12 = F_113 ( sizeof( * V_12 ) , V_53 ) ;
if ( ! V_12 )
return F_114 ( - V_54 ) ;
return V_12 ;
}
static void F_354 ( struct V_81 * V_82 , struct V_2 * V_467 )
{
F_21 ( V_467 -> V_39 [ V_468 ] ) ;
}
static T_2 F_355 ( struct V_2 * V_467 , struct V_189 * V_237 )
{
return F_202 ( & V_467 -> V_31 ) ;
}
static T_2 F_356 ( struct V_2 * V_467 , struct V_189 * V_237 )
{
return F_201 ( V_467 ) ;
}
static T_2 F_357 ( struct V_2 * V_467 , struct V_189 * V_237 )
{
return ( T_2 ) ( unsigned long ) V_236 -> V_63 ;
}
static T_2 F_358 ( struct V_2 * V_467 ,
struct V_189 * V_237 )
{
T_2 V_31 ;
F_155 () ;
V_31 = F_202 ( & V_236 -> V_63 -> V_25 ) ;
F_157 () ;
return V_31 ;
}
static int F_359 ( struct V_2 * V_467 ,
struct V_189 * V_237 ,
struct V_116 * V_117 )
{
struct V_22 * V_23 ;
struct V_19 * V_20 ;
F_43 ( & V_26 ) ;
F_155 () ;
V_20 = F_340 ( V_236 -> V_63 ) ;
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
F_157 () ;
F_44 ( & V_26 ) ;
return 0 ;
}
static int F_360 ( struct V_2 * V_467 ,
struct V_189 * V_237 ,
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
if ( V_31 ++ > V_469 ) {
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
static T_2 F_361 ( struct V_2 * V_3 , struct V_189 * V_237 )
{
return F_5 ( V_7 , & V_3 -> V_5 ) ;
}
static int F_362 ( struct V_81 * V_82 , struct V_2 * V_467 )
{
return F_200 ( V_467 , V_82 , V_470 ,
F_277 ( V_470 ) ) ;
}
