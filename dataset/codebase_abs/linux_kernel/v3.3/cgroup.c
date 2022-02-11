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
F_28 ( ! F_3 ( & V_106 ) ) ;
V_105 = V_46 -> V_107 & ~ V_103 ;
V_104 = V_103 & ~ V_46 -> V_107 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
unsigned long V_108 = 1UL << V_13 ;
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( ! ( V_108 & V_104 ) )
continue;
F_28 ( V_82 == NULL ) ;
if ( V_82 -> V_46 != & V_109 ) {
return - V_110 ;
}
}
if ( V_46 -> V_88 > 1 )
return - V_110 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
unsigned long V_108 = 1UL << V_13 ;
if ( V_108 & V_104 ) {
F_28 ( V_82 == NULL ) ;
F_28 ( V_3 -> V_39 [ V_13 ] ) ;
F_28 ( ! V_111 -> V_39 [ V_13 ] ) ;
F_28 ( V_111 -> V_39 [ V_13 ] -> V_2 != V_111 ) ;
F_51 ( & V_82 -> V_112 ) ;
V_3 -> V_39 [ V_13 ] = V_111 -> V_39 [ V_13 ] ;
V_3 -> V_39 [ V_13 ] -> V_2 = V_3 ;
F_40 ( & V_82 -> V_113 , & V_46 -> V_114 ) ;
V_82 -> V_46 = V_46 ;
if ( V_82 -> V_115 )
V_82 -> V_115 ( V_82 , V_3 ) ;
F_53 ( & V_82 -> V_112 ) ;
} else if ( V_108 & V_105 ) {
F_28 ( V_82 == NULL ) ;
F_28 ( V_3 -> V_39 [ V_13 ] != V_111 -> V_39 [ V_13 ] ) ;
F_28 ( V_3 -> V_39 [ V_13 ] -> V_2 != V_3 ) ;
F_51 ( & V_82 -> V_112 ) ;
if ( V_82 -> V_115 )
V_82 -> V_115 ( V_82 , V_111 ) ;
V_111 -> V_39 [ V_13 ] -> V_2 = V_111 ;
V_3 -> V_39 [ V_13 ] = NULL ;
V_39 [ V_13 ] -> V_46 = & V_109 ;
F_40 ( & V_82 -> V_113 , & V_109 . V_114 ) ;
F_53 ( & V_82 -> V_112 ) ;
F_89 ( V_82 -> V_116 ) ;
} else if ( V_108 & V_103 ) {
F_28 ( V_82 == NULL ) ;
F_28 ( ! V_3 -> V_39 [ V_13 ] ) ;
F_89 ( V_82 -> V_116 ) ;
#ifdef F_90
F_28 ( V_82 -> V_116 && ! F_91 ( V_82 -> V_116 ) ) ;
#endif
} else {
F_28 ( V_3 -> V_39 [ V_13 ] ) ;
}
}
V_46 -> V_52 = V_46 -> V_107 = V_103 ;
F_63 () ;
return 0 ;
}
static int F_92 ( struct V_117 * V_118 , struct V_85 * V_85 )
{
struct V_48 * V_46 = V_85 -> V_119 -> V_120 ;
struct V_81 * V_82 ;
F_51 ( & V_106 ) ;
F_60 (root, ss)
F_93 ( V_118 , L_1 , V_82 -> V_121 ) ;
if ( F_5 ( V_122 , & V_46 -> V_5 ) )
F_94 ( V_118 , L_2 ) ;
if ( strlen ( V_46 -> V_123 ) )
F_93 ( V_118 , L_3 , V_46 -> V_123 ) ;
if ( F_8 ( & V_46 -> V_65 ) )
F_94 ( V_118 , L_4 ) ;
if ( strlen ( V_46 -> V_121 ) )
F_93 ( V_118 , L_5 , V_46 -> V_121 ) ;
F_53 ( & V_106 ) ;
return 0 ;
}
static int F_95 ( char * V_124 , struct V_125 * V_126 )
{
char * V_127 , * V_128 = V_124 ;
bool V_129 = false , V_130 = false ;
unsigned long V_131 = ( unsigned long ) - 1 ;
int V_13 ;
bool V_132 = false ;
F_28 ( ! F_3 ( & V_1 ) ) ;
#ifdef F_96
V_131 = ~ ( 1UL << V_133 ) ;
#endif
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
while ( ( V_127 = F_97 ( & V_128 , L_6 ) ) != NULL ) {
if ( ! * V_127 )
return - V_134 ;
if ( ! strcmp ( V_127 , L_7 ) ) {
V_126 -> V_135 = true ;
continue;
}
if ( ! strcmp ( V_127 , L_8 ) ) {
if ( V_130 )
return - V_134 ;
V_129 = true ;
continue;
}
if ( ! strcmp ( V_127 , L_9 ) ) {
F_19 ( V_122 , & V_126 -> V_5 ) ;
continue;
}
if ( ! strcmp ( V_127 , L_10 ) ) {
V_126 -> F_8 = true ;
continue;
}
if ( ! strncmp ( V_127 , L_11 , 14 ) ) {
if ( V_126 -> V_136 )
return - V_134 ;
V_126 -> V_136 =
F_98 ( V_127 + 14 , V_137 - 1 , V_53 ) ;
if ( ! V_126 -> V_136 )
return - V_54 ;
continue;
}
if ( ! strncmp ( V_127 , L_12 , 5 ) ) {
const char * V_121 = V_127 + 5 ;
if ( ! strlen ( V_121 ) )
return - V_134 ;
for ( V_13 = 0 ; V_13 < strlen ( V_121 ) ; V_13 ++ ) {
char V_60 = V_121 [ V_13 ] ;
if ( isalnum ( V_60 ) )
continue;
if ( ( V_60 == '.' ) || ( V_60 == '-' ) || ( V_60 == '_' ) )
continue;
return - V_134 ;
}
if ( V_126 -> V_121 )
return - V_134 ;
V_126 -> V_121 = F_98 ( V_121 ,
V_138 - 1 ,
V_53 ) ;
if ( ! V_126 -> V_121 )
return - V_54 ;
continue;
}
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
if ( strcmp ( V_127 , V_82 -> V_121 ) )
continue;
if ( V_82 -> V_139 )
continue;
if ( V_129 )
return - V_134 ;
F_19 ( V_13 , & V_126 -> V_52 ) ;
V_130 = true ;
break;
}
if ( V_13 == V_16 )
return - V_140 ;
}
if ( V_129 || ( ! V_130 && ! V_126 -> V_135 && ! V_126 -> V_121 ) ) {
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
if ( V_82 -> V_139 )
continue;
F_19 ( V_13 , & V_126 -> V_52 ) ;
}
}
if ( F_5 ( V_122 , & V_126 -> V_5 ) &&
( V_126 -> V_52 & V_131 ) )
return - V_134 ;
if ( V_126 -> V_52 && V_126 -> V_135 )
return - V_134 ;
if ( ! V_126 -> V_52 && ! V_126 -> V_121 )
return - V_134 ;
for ( V_13 = V_141 ; V_13 < V_16 ; V_13 ++ ) {
unsigned long V_108 = 1UL << V_13 ;
if ( ! ( V_108 & V_126 -> V_52 ) )
continue;
if ( ! F_99 ( V_39 [ V_13 ] -> V_116 ) ) {
V_132 = true ;
break;
}
}
if ( V_132 ) {
for ( V_13 -- ; V_13 >= V_141 ; V_13 -- ) {
unsigned long V_108 = 1UL << V_13 ;
if ( ! ( V_108 & V_126 -> V_52 ) )
continue;
F_89 ( V_39 [ V_13 ] -> V_116 ) ;
}
return - V_140 ;
}
return 0 ;
}
static void F_100 ( unsigned long V_52 )
{
int V_13 ;
for ( V_13 = V_141 ; V_13 < V_16 ; V_13 ++ ) {
unsigned long V_108 = 1UL << V_13 ;
if ( ! ( V_108 & V_52 ) )
continue;
F_89 ( V_39 [ V_13 ] -> V_116 ) ;
}
}
static int F_101 ( struct V_68 * V_69 , int * V_5 , char * V_124 )
{
int V_83 = 0 ;
struct V_48 * V_46 = V_69 -> V_120 ;
struct V_2 * V_3 = & V_46 -> V_65 ;
struct V_125 V_126 ;
F_51 ( & V_3 -> V_85 -> V_93 -> V_94 ) ;
F_51 ( & V_1 ) ;
F_51 ( & V_106 ) ;
V_83 = F_95 ( V_124 , & V_126 ) ;
if ( V_83 )
goto V_142;
if ( V_126 . V_5 != V_46 -> V_5 ||
( V_126 . V_121 && strcmp ( V_126 . V_121 , V_46 -> V_121 ) ) ) {
V_83 = - V_134 ;
F_100 ( V_126 . V_52 ) ;
goto V_142;
}
V_83 = F_88 ( V_46 , V_126 . V_52 ) ;
if ( V_83 ) {
F_100 ( V_126 . V_52 ) ;
goto V_142;
}
F_102 ( V_3 ) ;
if ( V_126 . V_136 )
strcpy ( V_46 -> V_123 , V_126 . V_136 ) ;
V_142:
F_21 ( V_126 . V_136 ) ;
F_21 ( V_126 . V_121 ) ;
F_53 ( & V_106 ) ;
F_53 ( & V_1 ) ;
F_53 ( & V_3 -> V_85 -> V_93 -> V_94 ) ;
return V_83 ;
}
static void F_103 ( struct V_2 * V_3 )
{
F_34 ( & V_3 -> V_113 ) ;
F_34 ( & V_3 -> V_143 ) ;
F_34 ( & V_3 -> V_56 ) ;
F_34 ( & V_3 -> V_144 ) ;
F_34 ( & V_3 -> V_89 ) ;
F_104 ( & V_3 -> V_145 ) ;
F_34 ( & V_3 -> V_146 ) ;
F_105 ( & V_3 -> V_147 ) ;
}
static void F_106 ( struct V_48 * V_46 )
{
struct V_2 * V_3 = & V_46 -> V_65 ;
F_34 ( & V_46 -> V_114 ) ;
F_34 ( & V_46 -> V_148 ) ;
V_46 -> V_88 = 1 ;
V_3 -> V_46 = V_46 ;
V_3 -> V_65 = V_3 ;
F_103 ( V_3 ) ;
}
static bool F_107 ( struct V_48 * V_46 )
{
int V_83 = 0 ;
do {
if ( ! F_108 ( & V_149 , V_53 ) )
return false ;
F_73 ( & V_150 ) ;
V_83 = F_109 ( & V_149 , V_151 ,
& V_46 -> V_152 ) ;
if ( V_83 == - V_153 )
V_83 = F_110 ( & V_149 , & V_46 -> V_152 ) ;
if ( ! V_83 ) {
V_151 = V_46 -> V_152 + 1 ;
} else if ( V_83 != - V_154 ) {
F_28 ( V_83 ) ;
}
F_77 ( & V_150 ) ;
} while ( V_83 );
return true ;
}
static int F_111 ( struct V_68 * V_69 , void * V_124 )
{
struct V_125 * V_126 = V_124 ;
struct V_48 * V_46 = V_69 -> V_120 ;
if ( V_126 -> V_121 && strcmp ( V_126 -> V_121 , V_46 -> V_121 ) )
return 0 ;
if ( ( V_126 -> V_52 || V_126 -> V_135 )
&& ( V_126 -> V_52 != V_46 -> V_52 ) )
return 0 ;
return 1 ;
}
static struct V_48 * F_112 ( struct V_125 * V_126 )
{
struct V_48 * V_46 ;
if ( ! V_126 -> V_52 && ! V_126 -> V_135 )
return NULL ;
V_46 = F_113 ( sizeof( * V_46 ) , V_53 ) ;
if ( ! V_46 )
return F_114 ( - V_54 ) ;
if ( ! F_107 ( V_46 ) ) {
F_21 ( V_46 ) ;
return F_114 ( - V_54 ) ;
}
F_106 ( V_46 ) ;
V_46 -> V_52 = V_126 -> V_52 ;
V_46 -> V_5 = V_126 -> V_5 ;
if ( V_126 -> V_136 )
strcpy ( V_46 -> V_123 , V_126 -> V_136 ) ;
if ( V_126 -> V_121 )
strcpy ( V_46 -> V_121 , V_126 -> V_121 ) ;
if ( V_126 -> F_8 )
F_19 ( V_9 , & V_46 -> V_65 . V_5 ) ;
return V_46 ;
}
static void F_115 ( struct V_48 * V_46 )
{
if ( ! V_46 )
return;
F_28 ( ! V_46 -> V_152 ) ;
F_73 ( & V_150 ) ;
F_116 ( & V_149 , V_46 -> V_152 ) ;
F_77 ( & V_150 ) ;
F_21 ( V_46 ) ;
}
static int F_117 ( struct V_68 * V_69 , void * V_124 )
{
int V_83 ;
struct V_125 * V_126 = V_124 ;
if ( ! V_126 -> V_155 )
return - V_134 ;
F_28 ( ! V_126 -> V_52 && ! V_126 -> V_135 ) ;
V_83 = F_118 ( V_69 , NULL ) ;
if ( V_83 )
return V_83 ;
V_69 -> V_120 = V_126 -> V_155 ;
V_126 -> V_155 -> V_69 = V_69 ;
V_69 -> V_156 = V_157 ;
V_69 -> V_158 = V_159 ;
V_69 -> V_160 = V_161 ;
V_69 -> V_162 = & V_163 ;
return 0 ;
}
static int F_119 ( struct V_68 * V_69 )
{
static const struct V_164 V_165 = {
. V_166 = F_61 ,
. F_69 = F_66 ,
} ;
struct V_66 * V_66 =
F_54 ( V_100 | V_167 | V_168 | V_169 , V_69 ) ;
struct V_85 * V_85 ;
if ( ! V_66 )
return - V_54 ;
V_66 -> V_170 = & V_171 ;
V_66 -> V_172 = & V_173 ;
F_120 ( V_66 ) ;
V_85 = F_121 ( V_66 ) ;
if ( ! V_85 ) {
F_65 ( V_66 ) ;
return - V_54 ;
}
V_69 -> V_174 = V_85 ;
V_69 -> V_175 = & V_165 ;
return 0 ;
}
static struct V_85 * F_122 ( struct V_176 * V_177 ,
int V_5 , const char * V_178 ,
void * V_124 )
{
struct V_125 V_126 ;
struct V_48 * V_46 ;
int V_83 = 0 ;
struct V_68 * V_69 ;
struct V_48 * V_155 ;
struct V_66 * V_66 ;
F_51 ( & V_1 ) ;
V_83 = F_95 ( V_124 , & V_126 ) ;
F_53 ( & V_1 ) ;
if ( V_83 )
goto V_179;
V_155 = F_112 ( & V_126 ) ;
if ( F_123 ( V_155 ) ) {
V_83 = F_124 ( V_155 ) ;
goto V_180;
}
V_126 . V_155 = V_155 ;
V_69 = F_125 ( V_177 , F_111 , F_117 , & V_126 ) ;
if ( F_123 ( V_69 ) ) {
V_83 = F_124 ( V_69 ) ;
F_115 ( V_126 . V_155 ) ;
goto V_180;
}
V_46 = V_69 -> V_120 ;
F_28 ( ! V_46 ) ;
if ( V_46 == V_126 . V_155 ) {
struct V_36 V_55 ;
struct V_2 * V_181 = & V_46 -> V_65 ;
struct V_48 * V_182 ;
const struct V_183 * V_183 ;
int V_13 ;
F_28 ( V_69 -> V_174 != NULL ) ;
V_83 = F_119 ( V_69 ) ;
if ( V_83 )
goto V_184;
V_66 = V_69 -> V_174 -> V_93 ;
F_51 ( & V_66 -> V_94 ) ;
F_51 ( & V_1 ) ;
F_51 ( & V_106 ) ;
V_83 = - V_110 ;
if ( strlen ( V_46 -> V_121 ) )
F_126 (existing_root)
if ( ! strcmp ( V_182 -> V_121 , V_46 -> V_121 ) )
goto V_185;
V_83 = F_33 ( V_28 , & V_55 ) ;
if ( V_83 )
goto V_185;
V_83 = F_88 ( V_46 , V_46 -> V_52 ) ;
if ( V_83 == - V_110 ) {
F_32 ( & V_55 ) ;
goto V_185;
}
F_28 ( V_83 ) ;
F_36 ( & V_46 -> V_148 , & V_186 ) ;
V_58 ++ ;
V_69 -> V_174 -> V_86 = V_181 ;
V_46 -> V_65 . V_85 = V_69 -> V_174 ;
F_13 ( & V_26 ) ;
for ( V_13 = 0 ; V_13 < V_187 ; V_13 ++ ) {
struct V_10 * V_49 = & V_18 [ V_13 ] ;
struct V_50 * V_51 ;
struct V_19 * V_20 ;
F_31 (cg, node, hhead, hlist)
F_37 ( & V_55 , V_20 , V_181 ) ;
}
F_15 ( & V_26 ) ;
F_32 ( & V_55 ) ;
F_28 ( ! F_38 ( & V_181 -> V_113 ) ) ;
F_28 ( ! F_38 ( & V_181 -> V_143 ) ) ;
F_28 ( V_46 -> V_88 != 1 ) ;
V_183 = F_127 ( & V_188 ) ;
F_102 ( V_181 ) ;
F_128 ( V_183 ) ;
F_53 ( & V_106 ) ;
F_53 ( & V_1 ) ;
F_53 ( & V_66 -> V_94 ) ;
} else {
F_115 ( V_126 . V_155 ) ;
F_100 ( V_126 . V_52 ) ;
}
F_21 ( V_126 . V_136 ) ;
F_21 ( V_126 . V_121 ) ;
return F_68 ( V_69 -> V_174 ) ;
V_185:
F_53 ( & V_106 ) ;
F_53 ( & V_1 ) ;
F_53 ( & V_66 -> V_94 ) ;
V_184:
F_129 ( V_69 ) ;
V_180:
F_100 ( V_126 . V_52 ) ;
V_179:
F_21 ( V_126 . V_136 ) ;
F_21 ( V_126 . V_121 ) ;
return F_114 ( V_83 ) ;
}
static void F_130 ( struct V_68 * V_69 ) {
struct V_48 * V_46 = V_69 -> V_120 ;
struct V_2 * V_3 = & V_46 -> V_65 ;
int V_83 ;
struct V_22 * V_23 ;
struct V_22 * V_24 ;
F_28 ( ! V_46 ) ;
F_28 ( V_46 -> V_88 != 1 ) ;
F_28 ( ! F_38 ( & V_3 -> V_143 ) ) ;
F_28 ( ! F_38 ( & V_3 -> V_113 ) ) ;
F_51 ( & V_1 ) ;
F_51 ( & V_106 ) ;
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
if ( ! F_38 ( & V_46 -> V_148 ) ) {
F_18 ( & V_46 -> V_148 ) ;
V_58 -- ;
}
F_53 ( & V_106 ) ;
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
if ( ! V_85 || V_3 == V_111 ) {
strcpy ( V_190 , L_13 ) ;
return 0 ;
}
V_192 = V_190 + V_191 ;
* -- V_192 = '\0' ;
for (; ; ) {
int V_193 = V_85 -> V_194 . V_193 ;
if ( ( V_192 -= V_193 ) < V_190 )
return - V_195 ;
memcpy ( V_192 , V_85 -> V_194 . V_121 , V_193 ) ;
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
struct V_61 * F_136 ( struct V_196 * V_197 )
{
if ( V_197 -> V_198 ) {
V_197 -> V_199 = 0 ;
return F_137 ( V_197 ) ;
} else {
V_197 -> V_200 = V_197 -> V_201 . V_3 ;
return V_197 -> V_201 . V_62 ;
}
}
struct V_61 * F_137 ( struct V_196 * V_197 )
{
struct V_202 * V_203 ;
if ( ! V_197 -> V_198 || V_197 -> V_199 >= V_197 -> V_204 )
return NULL ;
V_203 = F_138 ( V_197 -> V_198 , V_197 -> V_199 ++ ) ;
V_197 -> V_200 = V_203 -> V_3 ;
return V_203 -> V_62 ;
}
struct V_2 * F_139 ( struct V_196 * V_197 )
{
return V_197 -> V_200 ;
}
int F_140 ( struct V_196 * V_197 )
{
return V_197 -> V_198 ? V_197 -> V_204 : 1 ;
}
static int F_141 ( struct V_2 * V_3 , struct V_2 * V_205 ,
struct V_61 * V_206 , bool V_207 )
{
struct V_19 * V_47 ;
struct V_19 * V_208 ;
F_142 ( V_206 -> V_5 & V_209 ) ;
V_47 = V_206 -> V_63 ;
if ( V_207 ) {
struct V_11 * V_35 [ V_16 ] ;
F_43 ( & V_26 ) ;
V_208 = F_30 ( V_47 , V_3 , V_35 ) ;
F_28 ( ! V_208 ) ;
F_23 ( V_208 ) ;
F_44 ( & V_26 ) ;
} else {
F_143 () ;
V_208 = F_42 ( V_47 , V_3 ) ;
if ( ! V_208 )
return - V_54 ;
}
F_144 ( V_206 ) ;
F_145 ( V_206 -> V_63 , V_208 ) ;
F_146 ( V_206 ) ;
F_13 ( & V_26 ) ;
if ( ! F_38 ( & V_206 -> V_210 ) )
F_40 ( & V_206 -> V_210 , & V_208 -> V_59 ) ;
F_15 ( & V_26 ) ;
F_25 ( V_47 ) ;
F_19 ( V_7 , & V_205 -> V_5 ) ;
return 0 ;
}
int F_147 ( struct V_2 * V_3 , struct V_61 * V_206 )
{
int V_211 ;
struct V_81 * V_82 , * V_212 = NULL ;
struct V_2 * V_205 ;
struct V_48 * V_46 = V_3 -> V_46 ;
struct V_196 V_197 = { } ;
if ( V_206 -> V_5 & V_209 )
return - V_213 ;
V_205 = F_49 ( V_206 , V_46 ) ;
if ( V_3 == V_205 )
return 0 ;
V_197 . V_201 . V_62 = V_206 ;
V_197 . V_201 . V_3 = V_205 ;
F_60 (root, ss) {
if ( V_82 -> V_214 ) {
V_211 = V_82 -> V_214 ( V_82 , V_3 , & V_197 ) ;
if ( V_211 ) {
V_212 = V_82 ;
goto V_215;
}
}
}
V_211 = F_141 ( V_3 , V_205 , V_206 , false ) ;
if ( V_211 )
goto V_215;
F_60 (root, ss) {
if ( V_82 -> V_216 )
V_82 -> V_216 ( V_82 , V_3 , & V_197 ) ;
}
F_63 () ;
F_80 ( V_3 ) ;
V_215:
if ( V_211 ) {
F_60 (root, ss) {
if ( V_82 == V_212 )
break;
if ( V_82 -> V_217 )
V_82 -> V_217 ( V_82 , V_3 , & V_197 ) ;
}
}
return V_211 ;
}
int F_148 ( struct V_61 * V_218 , struct V_61 * V_206 )
{
struct V_48 * V_46 ;
int V_211 = 0 ;
F_50 () ;
F_126 (root) {
struct V_2 * V_219 = F_49 ( V_218 , V_46 ) ;
V_211 = F_147 ( V_219 , V_206 ) ;
if ( V_211 )
break;
}
F_52 () ;
return V_211 ;
}
static bool F_149 ( struct V_2 * V_3 ,
struct V_61 * V_206 , struct V_19 * V_20 ,
struct V_36 * V_220 )
{
struct V_19 * V_208 ;
struct V_221 * V_222 ;
struct V_11 * V_35 [ V_16 ] ;
F_43 ( & V_26 ) ;
V_208 = F_30 ( V_20 , V_3 , V_35 ) ;
F_44 ( & V_26 ) ;
if ( ! V_208 )
return false ;
F_47 (cg_entry, newcg_list, links)
if ( V_222 -> V_20 == V_208 )
return true ;
return false ;
}
static int F_150 ( struct V_2 * V_3 , struct V_19 * V_20 ,
struct V_36 * V_220 )
{
struct V_19 * V_208 ;
struct V_221 * V_222 ;
V_208 = F_42 ( V_20 , V_3 ) ;
if ( ! V_208 )
return - V_54 ;
V_222 = F_35 ( sizeof( struct V_221 ) , V_53 ) ;
if ( ! V_222 ) {
F_25 ( V_208 ) ;
return - V_54 ;
}
V_222 -> V_20 = V_208 ;
F_36 ( & V_222 -> V_223 , V_220 ) ;
return 0 ;
}
static int F_151 ( struct V_2 * V_3 , struct V_61 * V_224 )
{
int V_211 , V_13 , V_225 ;
struct V_81 * V_82 , * V_212 = NULL ;
struct V_19 * V_47 ;
struct V_48 * V_46 = V_3 -> V_46 ;
struct V_61 * V_206 ;
struct V_202 * V_203 ;
struct V_226 * V_227 ;
struct V_196 V_197 = { } ;
struct V_36 V_220 ;
struct V_221 * V_222 , * V_228 ;
V_225 = F_152 ( V_224 ) ;
V_227 = F_153 ( sizeof( * V_203 ) , V_225 , V_53 ) ;
if ( ! V_227 )
return - V_54 ;
V_211 = F_154 ( V_227 , 0 , V_225 - 1 , V_53 ) ;
if ( V_211 )
goto V_229;
F_43 ( & V_230 ) ;
if ( ! F_155 ( V_224 ) ) {
F_44 ( & V_230 ) ;
V_211 = - V_154 ;
goto V_229;
}
V_206 = V_224 ;
V_13 = 0 ;
do {
struct V_202 V_231 ;
if ( V_206 -> V_5 & V_209 )
continue;
F_28 ( V_13 >= V_225 ) ;
V_231 . V_62 = V_206 ;
V_231 . V_3 = F_49 ( V_206 , V_46 ) ;
if ( V_231 . V_3 == V_3 )
continue;
V_211 = F_156 ( V_227 , V_13 , & V_231 , V_232 ) ;
F_28 ( V_211 != 0 ) ;
V_13 ++ ;
} while_each_thread(leader, tsk) ;
int F_157 ( struct V_2 * V_3 , T_2 V_233 , bool V_234 )
{
struct V_61 * V_206 ;
const struct V_183 * V_183 = F_158 () , * V_235 ;
int V_83 ;
if ( ! F_159 ( V_3 ) )
return - V_236 ;
if ( V_233 ) {
F_160 () ;
V_206 = F_161 ( V_233 ) ;
if ( ! V_206 ) {
F_162 () ;
F_52 () ;
return - V_213 ;
}
if ( V_234 ) {
V_206 = V_206 -> V_237 ;
}
V_235 = F_163 ( V_206 ) ;
if ( V_183 -> V_238 &&
V_183 -> V_238 != V_235 -> V_239 &&
V_183 -> V_238 != V_235 -> V_240 ) {
F_162 () ;
F_52 () ;
return - V_241 ;
}
F_164 ( V_206 ) ;
F_162 () ;
} else {
if ( V_234 )
V_206 = V_242 -> V_237 ;
else
V_206 = V_242 ;
F_164 ( V_206 ) ;
}
F_165 ( V_206 ) ;
if ( V_234 )
V_83 = F_151 ( V_3 , V_206 ) ;
else
V_83 = F_147 ( V_3 , V_206 ) ;
F_166 ( V_206 ) ;
F_167 ( V_206 ) ;
F_52 () ;
return V_83 ;
}
static int F_168 ( struct V_2 * V_3 , struct V_189 * V_243 , T_2 V_233 )
{
return F_157 ( V_3 , V_233 , false ) ;
}
static int F_169 ( struct V_2 * V_3 , struct V_189 * V_243 , T_2 V_244 )
{
int V_83 ;
do {
V_83 = F_157 ( V_3 , V_244 , true ) ;
} while ( V_83 == - V_154 );
return V_83 ;
}
bool F_159 ( struct V_2 * V_3 )
{
F_51 ( & V_1 ) ;
if ( F_4 ( V_3 ) ) {
F_53 ( & V_1 ) ;
return false ;
}
return true ;
}
static int F_170 ( struct V_2 * V_3 , struct V_189 * V_243 ,
const char * V_245 )
{
F_171 ( sizeof( V_3 -> V_46 -> V_123 ) < V_137 ) ;
if ( strlen ( V_245 ) >= V_137 )
return - V_134 ;
if ( ! F_159 ( V_3 ) )
return - V_236 ;
F_51 ( & V_106 ) ;
strcpy ( V_3 -> V_46 -> V_123 , V_245 ) ;
F_53 ( & V_106 ) ;
F_52 () ;
return 0 ;
}
static int F_172 ( struct V_2 * V_3 , struct V_189 * V_243 ,
struct V_117 * V_118 )
{
if ( ! F_159 ( V_3 ) )
return - V_236 ;
F_94 ( V_118 , V_3 -> V_46 -> V_123 ) ;
F_173 ( V_118 , '\n' ) ;
F_52 () ;
return 0 ;
}
static T_3 F_174 ( struct V_2 * V_3 , struct V_189 * V_243 ,
struct V_246 * V_246 ,
const char T_4 * V_247 ,
T_5 V_248 , T_6 * V_249 )
{
char V_245 [ V_250 ] ;
int V_211 = 0 ;
char * V_251 ;
if ( ! V_248 )
return - V_134 ;
if ( V_248 >= sizeof( V_245 ) )
return - V_252 ;
if ( F_175 ( V_245 , V_247 , V_248 ) )
return - V_253 ;
V_245 [ V_248 ] = 0 ;
if ( V_243 -> V_254 ) {
T_2 V_255 = F_176 ( F_177 ( V_245 ) , & V_251 , 0 ) ;
if ( * V_251 )
return - V_134 ;
V_211 = V_243 -> V_254 ( V_3 , V_243 , V_255 ) ;
} else {
T_7 V_255 = F_178 ( F_177 ( V_245 ) , & V_251 , 0 ) ;
if ( * V_251 )
return - V_134 ;
V_211 = V_243 -> V_256 ( V_3 , V_243 , V_255 ) ;
}
if ( ! V_211 )
V_211 = V_248 ;
return V_211 ;
}
static T_3 F_179 ( struct V_2 * V_3 , struct V_189 * V_243 ,
struct V_246 * V_246 ,
const char T_4 * V_247 ,
T_5 V_248 , T_6 * V_249 )
{
char V_257 [ V_250 ] ;
int V_211 = 0 ;
T_5 V_258 = V_243 -> V_259 ;
char * V_245 = V_257 ;
if ( ! V_258 )
V_258 = sizeof( V_257 ) - 1 ;
if ( V_248 >= V_258 )
return - V_252 ;
if ( V_248 >= sizeof( V_257 ) ) {
V_245 = F_35 ( V_248 + 1 , V_53 ) ;
if ( V_245 == NULL )
return - V_54 ;
}
if ( V_248 && F_175 ( V_245 , V_247 , V_248 ) ) {
V_211 = - V_253 ;
goto V_215;
}
V_245 [ V_248 ] = 0 ;
V_211 = V_243 -> V_260 ( V_3 , V_243 , F_177 ( V_245 ) ) ;
if ( ! V_211 )
V_211 = V_248 ;
V_215:
if ( V_245 != V_257 )
F_21 ( V_245 ) ;
return V_211 ;
}
static T_3 F_180 ( struct V_246 * V_246 , const char T_4 * V_190 ,
T_5 V_248 , T_6 * V_261 )
{
struct V_189 * V_243 = F_133 ( V_246 -> V_262 ) ;
struct V_2 * V_3 = F_132 ( V_246 -> V_262 -> V_92 ) ;
if ( F_4 ( V_3 ) )
return - V_236 ;
if ( V_243 -> V_263 )
return V_243 -> V_263 ( V_3 , V_243 , V_246 , V_190 , V_248 , V_261 ) ;
if ( V_243 -> V_254 || V_243 -> V_256 )
return F_174 ( V_3 , V_243 , V_246 , V_190 , V_248 , V_261 ) ;
if ( V_243 -> V_260 )
return F_179 ( V_3 , V_243 , V_246 , V_190 , V_248 , V_261 ) ;
if ( V_243 -> V_264 ) {
int V_83 = V_243 -> V_264 ( V_3 , ( unsigned int ) V_243 -> V_265 ) ;
return V_83 ? V_83 : V_248 ;
}
return - V_134 ;
}
static T_3 F_181 ( struct V_2 * V_3 , struct V_189 * V_243 ,
struct V_246 * V_246 ,
char T_4 * V_190 , T_5 V_248 ,
T_6 * V_261 )
{
char V_15 [ V_250 ] ;
T_2 V_255 = V_243 -> V_266 ( V_3 , V_243 ) ;
int V_193 = sprintf ( V_15 , L_14 , ( unsigned long long ) V_255 ) ;
return F_182 ( V_190 , V_248 , V_261 , V_15 , V_193 ) ;
}
static T_3 F_183 ( struct V_2 * V_3 , struct V_189 * V_243 ,
struct V_246 * V_246 ,
char T_4 * V_190 , T_5 V_248 ,
T_6 * V_261 )
{
char V_15 [ V_250 ] ;
T_7 V_255 = V_243 -> V_267 ( V_3 , V_243 ) ;
int V_193 = sprintf ( V_15 , L_15 , ( long long ) V_255 ) ;
return F_182 ( V_190 , V_248 , V_261 , V_15 , V_193 ) ;
}
static T_3 F_184 ( struct V_246 * V_246 , char T_4 * V_190 ,
T_5 V_248 , T_6 * V_261 )
{
struct V_189 * V_243 = F_133 ( V_246 -> V_262 ) ;
struct V_2 * V_3 = F_132 ( V_246 -> V_262 -> V_92 ) ;
if ( F_4 ( V_3 ) )
return - V_236 ;
if ( V_243 -> V_268 )
return V_243 -> V_268 ( V_3 , V_243 , V_246 , V_190 , V_248 , V_261 ) ;
if ( V_243 -> V_266 )
return F_181 ( V_3 , V_243 , V_246 , V_190 , V_248 , V_261 ) ;
if ( V_243 -> V_267 )
return F_183 ( V_3 , V_243 , V_246 , V_190 , V_248 , V_261 ) ;
return - V_134 ;
}
static int F_185 ( struct V_269 * V_270 , const char * V_271 , T_2 V_272 )
{
struct V_117 * V_273 = V_270 -> V_274 ;
return F_93 ( V_273 , L_16 , V_271 , ( unsigned long long ) V_272 ) ;
}
static int F_186 ( struct V_117 * V_275 , void * V_276 )
{
struct V_277 * V_274 = V_275 -> V_265 ;
struct V_189 * V_243 = V_274 -> V_243 ;
if ( V_243 -> V_278 ) {
struct V_269 V_270 = {
. V_279 = F_185 ,
. V_274 = V_275 ,
} ;
return V_243 -> V_278 ( V_274 -> V_2 , V_243 , & V_270 ) ;
}
return V_243 -> V_280 ( V_274 -> V_2 , V_243 , V_275 ) ;
}
static int F_187 ( struct V_66 * V_66 , struct V_246 * V_246 )
{
struct V_117 * V_118 = V_246 -> V_281 ;
F_21 ( V_118 -> V_265 ) ;
return F_188 ( V_66 , V_246 ) ;
}
static int F_189 ( struct V_66 * V_66 , struct V_246 * V_246 )
{
int V_282 ;
struct V_189 * V_243 ;
V_282 = F_190 ( V_66 , V_246 ) ;
if ( V_282 )
return V_282 ;
V_243 = F_133 ( V_246 -> V_262 ) ;
if ( V_243 -> V_278 || V_243 -> V_280 ) {
struct V_277 * V_274 =
F_113 ( sizeof( * V_274 ) , V_283 ) ;
if ( ! V_274 )
return - V_54 ;
V_274 -> V_243 = V_243 ;
V_274 -> V_2 = F_132 ( V_246 -> V_262 -> V_92 ) ;
V_246 -> V_284 = & V_285 ;
V_282 = F_191 ( V_246 , F_186 , V_274 ) ;
if ( V_282 < 0 )
F_21 ( V_274 ) ;
} else if ( V_243 -> V_286 )
V_282 = V_243 -> V_286 ( V_66 , V_246 ) ;
else
V_282 = 0 ;
return V_282 ;
}
static int F_192 ( struct V_66 * V_66 , struct V_246 * V_246 )
{
struct V_189 * V_243 = F_133 ( V_246 -> V_262 ) ;
if ( V_243 -> V_287 )
return V_243 -> V_287 ( V_66 , V_246 ) ;
return 0 ;
}
static int F_193 ( struct V_66 * V_288 , struct V_85 * V_289 ,
struct V_66 * V_290 , struct V_85 * V_291 )
{
if ( ! F_62 ( V_289 -> V_93 -> V_71 ) )
return - V_292 ;
if ( V_291 -> V_93 )
return - V_293 ;
if ( V_288 != V_290 )
return - V_294 ;
return F_194 ( V_288 , V_289 , V_290 , V_291 ) ;
}
static struct V_85 * F_195 ( struct V_66 * V_295 , struct V_85 * V_85 , struct V_296 * V_297 )
{
if ( V_85 -> V_194 . V_193 > V_298 )
return F_114 ( - V_195 ) ;
F_196 ( V_85 , NULL ) ;
return NULL ;
}
static inline struct V_189 * F_197 ( struct V_246 * V_246 )
{
if ( V_246 -> V_262 -> V_93 -> V_170 != & V_299 )
return F_114 ( - V_134 ) ;
return F_133 ( V_246 -> V_262 ) ;
}
static int F_198 ( struct V_85 * V_85 , T_1 V_67 ,
struct V_68 * V_69 )
{
struct V_66 * V_66 ;
if ( ! V_85 )
return - V_140 ;
if ( V_85 -> V_93 )
return - V_293 ;
V_66 = F_54 ( V_67 , V_69 ) ;
if ( ! V_66 )
return - V_54 ;
if ( F_62 ( V_67 ) ) {
V_66 -> V_172 = & V_173 ;
V_66 -> V_170 = & V_171 ;
F_120 ( V_66 ) ;
F_199 ( & V_66 -> V_94 , V_300 ) ;
} else if ( F_200 ( V_67 ) ) {
V_66 -> V_301 = 0 ;
V_66 -> V_170 = & V_299 ;
}
F_201 ( V_85 , V_66 ) ;
F_68 ( V_85 ) ;
return 0 ;
}
static int F_202 ( struct V_2 * V_3 , struct V_85 * V_85 ,
T_1 V_67 )
{
struct V_85 * V_91 ;
int error = 0 ;
V_91 = V_3 -> V_91 -> V_85 ;
error = F_198 ( V_85 , V_100 | V_67 , V_3 -> V_46 -> V_69 ) ;
if ( ! error ) {
V_85 -> V_86 = V_3 ;
F_120 ( V_91 -> V_93 ) ;
F_145 ( V_3 -> V_85 , V_85 ) ;
F_68 ( V_85 ) ;
}
F_71 ( V_85 ) ;
return error ;
}
static T_1 F_203 ( const struct V_189 * V_243 )
{
T_1 V_67 = 0 ;
if ( V_243 -> V_67 )
return V_243 -> V_67 ;
if ( V_243 -> V_268 || V_243 -> V_266 || V_243 -> V_267 ||
V_243 -> V_278 || V_243 -> V_280 )
V_67 |= V_167 ;
if ( V_243 -> V_263 || V_243 -> V_254 || V_243 -> V_256 ||
V_243 -> V_260 || V_243 -> V_264 )
V_67 |= V_169 ;
return V_67 ;
}
int F_204 ( struct V_2 * V_3 ,
struct V_81 * V_39 ,
const struct V_189 * V_243 )
{
struct V_85 * V_295 = V_3 -> V_85 ;
struct V_85 * V_85 ;
int error ;
T_1 V_67 ;
char V_121 [ V_302 + V_303 + 2 ] = { 0 } ;
if ( V_39 && ! F_5 ( V_122 , & V_3 -> V_46 -> V_5 ) ) {
strcpy ( V_121 , V_39 -> V_121 ) ;
strcat ( V_121 , L_17 ) ;
}
strcat ( V_121 , V_243 -> V_121 ) ;
F_28 ( ! F_3 ( & V_295 -> V_93 -> V_94 ) ) ;
V_85 = F_205 ( V_121 , V_295 , strlen ( V_121 ) ) ;
if ( ! F_123 ( V_85 ) ) {
V_67 = F_203 ( V_243 ) ;
error = F_198 ( V_85 , V_67 | V_304 ,
V_3 -> V_46 -> V_69 ) ;
if ( ! error )
V_85 -> V_86 = ( void * ) V_243 ;
F_71 ( V_85 ) ;
} else
error = F_124 ( V_85 ) ;
return error ;
}
int F_206 ( struct V_2 * V_3 ,
struct V_81 * V_39 ,
const struct V_189 V_243 [] ,
int V_31 )
{
int V_13 , V_282 ;
for ( V_13 = 0 ; V_13 < V_31 ; V_13 ++ ) {
V_282 = F_204 ( V_3 , V_39 , & V_243 [ V_13 ] ) ;
if ( V_282 )
return V_282 ;
}
return 0 ;
}
int F_207 ( const struct V_2 * V_3 )
{
int V_31 = 0 ;
struct V_22 * V_23 ;
F_43 ( & V_26 ) ;
F_47 (link, &cgrp->css_sets, cgrp_link_list) {
V_31 += F_208 ( & V_23 -> V_20 -> V_25 ) ;
}
F_44 ( & V_26 ) ;
return V_31 ;
}
static void F_209 ( struct V_2 * V_3 ,
struct V_305 * V_306 )
{
struct V_36 * V_307 = V_306 -> V_308 ;
struct V_22 * V_23 ;
struct V_19 * V_20 ;
do {
V_307 = V_307 -> V_45 ;
if ( V_307 == & V_3 -> V_56 ) {
V_306 -> V_308 = NULL ;
return;
}
V_23 = F_29 ( V_307 , struct V_22 , V_30 ) ;
V_20 = V_23 -> V_20 ;
} while ( F_38 ( & V_20 -> V_59 ) );
V_306 -> V_308 = V_307 ;
V_306 -> V_62 = V_20 -> V_59 . V_45 ;
}
static void F_210 ( void )
{
struct V_61 * V_309 , * V_310 ;
F_13 ( & V_26 ) ;
V_311 = 1 ;
F_211 (g, p) {
F_144 ( V_309 ) ;
if ( ! ( V_309 -> V_5 & V_209 ) && F_38 ( & V_309 -> V_210 ) )
F_36 ( & V_309 -> V_210 , & V_309 -> V_63 -> V_59 ) ;
F_146 ( V_309 ) ;
} F_212 ( V_310 , V_309 ) ;
F_15 ( & V_26 ) ;
}
void F_213 ( struct V_2 * V_3 , struct V_305 * V_306 )
__acquires( V_26 )
{
if ( ! V_311 )
F_210 () ;
F_43 ( & V_26 ) ;
V_306 -> V_308 = & V_3 -> V_56 ;
F_209 ( V_3 , V_306 ) ;
}
struct V_61 * F_214 ( struct V_2 * V_3 ,
struct V_305 * V_306 )
{
struct V_61 * V_57 ;
struct V_36 * V_307 = V_306 -> V_62 ;
struct V_22 * V_23 ;
if ( ! V_306 -> V_308 )
return NULL ;
V_57 = F_29 ( V_307 , struct V_61 , V_210 ) ;
V_307 = V_307 -> V_45 ;
V_23 = F_29 ( V_306 -> V_308 , struct V_22 , V_30 ) ;
if ( V_307 == & V_23 -> V_20 -> V_59 ) {
F_209 ( V_3 , V_306 ) ;
} else {
V_306 -> V_62 = V_307 ;
}
return V_57 ;
}
void F_215 ( struct V_2 * V_3 , struct V_305 * V_306 )
__releases( V_26 )
{
F_44 ( & V_26 ) ;
}
static inline int F_216 ( struct V_61 * V_312 ,
struct V_313 * time ,
struct V_61 * V_314 )
{
int V_315 = F_217 ( & V_312 -> V_316 , time ) ;
if ( V_315 > 0 ) {
return 1 ;
} else if ( V_315 < 0 ) {
return 0 ;
} else {
return V_312 > V_314 ;
}
}
static inline int F_218 ( void * V_317 , void * V_318 )
{
struct V_61 * V_312 = V_317 ;
struct V_61 * V_314 = V_318 ;
return F_216 ( V_312 , & V_314 -> V_316 , V_314 ) ;
}
int F_219 ( struct V_319 * V_320 )
{
int V_211 , V_13 ;
struct V_305 V_306 ;
struct V_61 * V_309 , * V_321 ;
struct V_61 * V_322 = NULL ;
struct V_323 V_324 ;
struct V_323 * V_325 ;
struct V_313 V_326 = { 0 , 0 } ;
if ( V_320 -> V_325 ) {
V_325 = V_320 -> V_325 ;
V_325 -> V_327 = & F_218 ;
} else {
V_325 = & V_324 ;
V_211 = F_220 ( V_325 , V_328 , V_53 , & F_218 ) ;
if ( V_211 )
return V_211 ;
}
V_329:
V_325 -> V_330 = 0 ;
F_213 ( V_320 -> V_20 , & V_306 ) ;
while ( ( V_309 = F_214 ( V_320 -> V_20 , & V_306 ) ) ) {
if ( V_320 -> V_331 && ! V_320 -> V_331 ( V_309 , V_320 ) )
continue;
if ( ! F_216 ( V_309 , & V_326 , V_322 ) )
continue;
V_321 = F_221 ( V_325 , V_309 ) ;
if ( V_321 == NULL ) {
F_164 ( V_309 ) ;
} else if ( V_321 != V_309 ) {
F_164 ( V_309 ) ;
F_167 ( V_321 ) ;
}
}
F_215 ( V_320 -> V_20 , & V_306 ) ;
if ( V_325 -> V_330 ) {
for ( V_13 = 0 ; V_13 < V_325 -> V_330 ; V_13 ++ ) {
struct V_61 * V_332 = V_325 -> V_333 [ V_13 ] ;
if ( V_13 == 0 ) {
V_326 = V_332 -> V_316 ;
V_322 = V_332 ;
}
V_320 -> V_334 ( V_332 , V_320 ) ;
F_167 ( V_332 ) ;
}
goto V_329;
}
if ( V_325 == & V_324 )
F_222 ( & V_324 ) ;
return 0 ;
}
static void * F_223 ( int V_31 )
{
if ( F_224 ( V_31 ) )
return F_225 ( V_31 * sizeof( V_335 ) ) ;
else
return F_35 ( V_31 * sizeof( V_335 ) , V_53 ) ;
}
static void F_226 ( void * V_309 )
{
if ( F_227 ( V_309 ) )
F_228 ( V_309 ) ;
else
F_21 ( V_309 ) ;
}
static void * F_229 ( void * V_309 , int V_336 )
{
void * V_337 ;
if ( F_227 ( V_309 ) ) {
V_337 = F_225 ( V_336 * sizeof( V_335 ) ) ;
if ( ! V_337 )
return NULL ;
memcpy ( V_337 , V_309 , V_336 * sizeof( V_335 ) ) ;
F_228 ( V_309 ) ;
} else {
V_337 = F_230 ( V_309 , V_336 * sizeof( V_335 ) , V_53 ) ;
}
return V_337 ;
}
static int F_231 ( V_335 * * V_309 , int V_338 )
{
int V_339 , V_340 = 1 ;
V_335 * V_341 = * V_309 ;
V_335 * V_337 ;
if ( V_338 == 0 || V_338 == 1 )
return V_338 ;
for ( V_339 = 1 ; V_339 < V_338 ; V_339 ++ ) {
while ( V_341 [ V_339 ] == V_341 [ V_339 - 1 ] ) {
V_339 ++ ;
if ( V_339 == V_338 )
goto V_342;
}
V_341 [ V_340 ] = V_341 [ V_339 ] ;
V_340 ++ ;
}
V_342:
if ( F_232 ( V_338 , V_340 ) ) {
V_337 = F_229 ( V_341 , V_340 ) ;
if ( V_337 )
* V_309 = V_337 ;
}
return V_340 ;
}
static int F_233 ( const void * V_343 , const void * V_344 )
{
return * ( V_335 * ) V_343 - * ( V_335 * ) V_344 ;
}
static struct V_345 * F_234 ( struct V_2 * V_3 ,
enum V_346 type )
{
struct V_345 * V_307 ;
struct V_347 * V_348 = V_242 -> V_349 -> V_350 ;
F_51 ( & V_3 -> V_145 ) ;
F_47 (l, &cgrp->pidlists, links) {
if ( V_307 -> V_271 . type == type && V_307 -> V_271 . V_348 == V_348 ) {
F_235 ( & V_307 -> V_351 ) ;
F_53 ( & V_3 -> V_145 ) ;
return V_307 ;
}
}
V_307 = F_35 ( sizeof( struct V_345 ) , V_53 ) ;
if ( ! V_307 ) {
F_53 ( & V_3 -> V_145 ) ;
return V_307 ;
}
F_236 ( & V_307 -> V_351 ) ;
F_235 ( & V_307 -> V_351 ) ;
V_307 -> V_271 . type = type ;
V_307 -> V_271 . V_348 = F_237 ( V_348 ) ;
V_307 -> V_352 = 0 ;
V_307 -> V_341 = NULL ;
V_307 -> V_353 = V_3 ;
F_36 ( & V_307 -> V_223 , & V_3 -> V_89 ) ;
F_53 ( & V_3 -> V_145 ) ;
return V_307 ;
}
static int F_238 ( struct V_2 * V_3 , enum V_346 type ,
struct V_345 * * V_354 )
{
V_335 * V_355 ;
int V_338 ;
int V_233 , V_356 = 0 ;
struct V_305 V_306 ;
struct V_61 * V_206 ;
struct V_345 * V_307 ;
V_338 = F_207 ( V_3 ) ;
V_355 = F_223 ( V_338 ) ;
if ( ! V_355 )
return - V_54 ;
F_213 ( V_3 , & V_306 ) ;
while ( ( V_206 = F_214 ( V_3 , & V_306 ) ) ) {
if ( F_81 ( V_356 == V_338 ) )
break;
if ( type == V_357 )
V_233 = F_239 ( V_206 ) ;
else
V_233 = F_240 ( V_206 ) ;
if ( V_233 > 0 )
V_355 [ V_356 ++ ] = V_233 ;
}
F_215 ( V_3 , & V_306 ) ;
V_338 = V_356 ;
F_241 ( V_355 , V_338 , sizeof( V_335 ) , F_233 , NULL ) ;
if ( type == V_357 )
V_338 = F_231 ( & V_355 , V_338 ) ;
V_307 = F_234 ( V_3 , type ) ;
if ( ! V_307 ) {
F_226 ( V_355 ) ;
return - V_54 ;
}
F_226 ( V_307 -> V_341 ) ;
V_307 -> V_341 = V_355 ;
V_307 -> V_338 = V_338 ;
V_307 -> V_352 ++ ;
F_242 ( & V_307 -> V_351 ) ;
* V_354 = V_307 ;
return 0 ;
}
int F_243 ( struct V_358 * V_359 , struct V_85 * V_85 )
{
int V_83 = - V_134 ;
struct V_2 * V_3 ;
struct V_305 V_306 ;
struct V_61 * V_206 ;
if ( V_85 -> V_119 -> V_162 != & V_163 ||
! F_62 ( V_85 -> V_93 -> V_71 ) )
goto V_282;
V_83 = 0 ;
V_3 = V_85 -> V_86 ;
F_213 ( V_3 , & V_306 ) ;
while ( ( V_206 = F_214 ( V_3 , & V_306 ) ) ) {
switch ( V_206 -> V_274 ) {
case V_360 :
V_359 -> V_361 ++ ;
break;
case V_362 :
V_359 -> V_363 ++ ;
break;
case V_364 :
V_359 -> V_365 ++ ;
break;
case V_366 :
V_359 -> V_367 ++ ;
break;
default:
if ( F_244 ( V_206 ) )
V_359 -> V_368 ++ ;
break;
}
}
F_215 ( V_3 , & V_306 ) ;
V_282:
return V_83 ;
}
static void * F_245 ( struct V_117 * V_369 , T_6 * V_370 )
{
struct V_345 * V_307 = V_369 -> V_265 ;
int V_14 = 0 , V_233 = * V_370 ;
int * V_371 ;
F_246 ( & V_307 -> V_351 ) ;
if ( V_233 ) {
int V_251 = V_307 -> V_338 ;
while ( V_14 < V_251 ) {
int V_372 = ( V_14 + V_251 ) / 2 ;
if ( V_307 -> V_341 [ V_372 ] == V_233 ) {
V_14 = V_372 ;
break;
} else if ( V_307 -> V_341 [ V_372 ] <= V_233 )
V_14 = V_372 + 1 ;
else
V_251 = V_372 ;
}
}
if ( V_14 >= V_307 -> V_338 )
return NULL ;
V_371 = V_307 -> V_341 + V_14 ;
* V_370 = * V_371 ;
return V_371 ;
}
static void F_247 ( struct V_117 * V_369 , void * V_373 )
{
struct V_345 * V_307 = V_369 -> V_265 ;
F_248 ( & V_307 -> V_351 ) ;
}
static void * F_249 ( struct V_117 * V_369 , void * V_373 , T_6 * V_370 )
{
struct V_345 * V_307 = V_369 -> V_265 ;
V_335 * V_309 = V_373 ;
V_335 * V_251 = V_307 -> V_341 + V_307 -> V_338 ;
V_309 ++ ;
if ( V_309 >= V_251 ) {
return NULL ;
} else {
* V_370 = * V_309 ;
return V_309 ;
}
}
static int F_250 ( struct V_117 * V_369 , void * V_373 )
{
return F_93 ( V_369 , L_18 , * ( int * ) V_373 ) ;
}
static void F_251 ( struct V_345 * V_307 )
{
F_51 ( & V_307 -> V_353 -> V_145 ) ;
F_235 ( & V_307 -> V_351 ) ;
F_28 ( ! V_307 -> V_352 ) ;
if ( ! -- V_307 -> V_352 ) {
F_18 ( & V_307 -> V_223 ) ;
F_53 ( & V_307 -> V_353 -> V_145 ) ;
F_226 ( V_307 -> V_341 ) ;
F_252 ( V_307 -> V_271 . V_348 ) ;
F_242 ( & V_307 -> V_351 ) ;
F_21 ( V_307 ) ;
return;
}
F_53 ( & V_307 -> V_353 -> V_145 ) ;
F_242 ( & V_307 -> V_351 ) ;
}
static int F_253 ( struct V_66 * V_66 , struct V_246 * V_246 )
{
struct V_345 * V_307 ;
if ( ! ( V_246 -> V_374 & V_375 ) )
return 0 ;
V_307 = ( (struct V_117 * ) V_246 -> V_281 ) -> V_265 ;
F_251 ( V_307 ) ;
return F_254 ( V_66 , V_246 ) ;
}
static int F_255 ( struct V_246 * V_246 , enum V_346 type )
{
struct V_2 * V_3 = F_132 ( V_246 -> V_262 -> V_92 ) ;
struct V_345 * V_307 ;
int V_211 ;
if ( ! ( V_246 -> V_374 & V_375 ) )
return 0 ;
V_211 = F_238 ( V_3 , type , & V_307 ) ;
if ( V_211 )
return V_211 ;
V_246 -> V_284 = & V_376 ;
V_211 = F_256 ( V_246 , & V_377 ) ;
if ( V_211 ) {
F_251 ( V_307 ) ;
return V_211 ;
}
( (struct V_117 * ) V_246 -> V_281 ) -> V_265 = V_307 ;
return 0 ;
}
static int F_257 ( struct V_66 * V_378 , struct V_246 * V_246 )
{
return F_255 ( V_246 , V_379 ) ;
}
static int F_258 ( struct V_66 * V_378 , struct V_246 * V_246 )
{
return F_255 ( V_246 , V_357 ) ;
}
static T_2 F_259 ( struct V_2 * V_3 ,
struct V_189 * V_243 )
{
return F_7 ( V_3 ) ;
}
static int F_260 ( struct V_2 * V_3 ,
struct V_189 * V_243 ,
T_2 V_255 )
{
F_261 ( V_7 , & V_3 -> V_5 ) ;
if ( V_255 )
F_19 ( V_8 , & V_3 -> V_5 ) ;
else
F_261 ( V_8 , & V_3 -> V_5 ) ;
return 0 ;
}
static void F_262 ( struct V_380 * V_381 )
{
struct V_382 * V_383 = F_263 ( V_381 , struct V_382 ,
remove ) ;
struct V_2 * V_3 = V_383 -> V_3 ;
V_383 -> V_243 -> V_384 ( V_3 , V_383 -> V_243 , V_383 -> V_385 ) ;
F_264 ( V_383 -> V_385 ) ;
F_21 ( V_383 ) ;
F_71 ( V_3 -> V_85 ) ;
}
static int F_265 ( T_8 * V_386 , unsigned V_67 ,
int V_387 , void * V_271 )
{
struct V_382 * V_383 = F_263 ( V_386 ,
struct V_382 , V_386 ) ;
struct V_2 * V_3 = V_383 -> V_3 ;
unsigned long V_5 = ( unsigned long ) V_271 ;
if ( V_5 & V_388 ) {
F_266 ( V_383 -> V_389 , & V_383 -> V_386 ) ;
F_73 ( & V_3 -> V_147 ) ;
F_18 ( & V_383 -> V_341 ) ;
F_77 ( & V_3 -> V_147 ) ;
F_267 ( & V_383 -> remove ) ;
}
return 0 ;
}
static void F_268 ( struct V_246 * V_246 ,
T_9 * V_389 , T_10 * V_390 )
{
struct V_382 * V_383 = F_263 ( V_390 ,
struct V_382 , V_390 ) ;
V_383 -> V_389 = V_389 ;
F_269 ( V_389 , & V_383 -> V_386 ) ;
}
static int F_270 ( struct V_2 * V_3 , struct V_189 * V_243 ,
const char * V_245 )
{
struct V_382 * V_383 = NULL ;
unsigned int V_391 , V_392 ;
struct V_246 * V_393 = NULL ;
struct V_246 * V_394 = NULL ;
char * V_395 ;
int V_83 ;
V_391 = F_271 ( V_245 , & V_395 , 10 ) ;
if ( * V_395 != ' ' )
return - V_134 ;
V_245 = V_395 + 1 ;
V_392 = F_271 ( V_245 , & V_395 , 10 ) ;
if ( ( * V_395 != ' ' ) && ( * V_395 != '\0' ) )
return - V_134 ;
V_245 = V_395 + 1 ;
V_383 = F_113 ( sizeof( * V_383 ) , V_53 ) ;
if ( ! V_383 )
return - V_54 ;
V_383 -> V_3 = V_3 ;
F_34 ( & V_383 -> V_341 ) ;
F_272 ( & V_383 -> V_390 , F_268 ) ;
F_273 ( & V_383 -> V_386 , F_265 ) ;
F_274 ( & V_383 -> remove , F_262 ) ;
V_393 = F_275 ( V_391 ) ;
if ( F_123 ( V_393 ) ) {
V_83 = F_124 ( V_393 ) ;
goto V_396;
}
V_383 -> V_385 = F_276 ( V_393 ) ;
if ( F_123 ( V_383 -> V_385 ) ) {
V_83 = F_124 ( V_383 -> V_385 ) ;
goto V_396;
}
V_394 = F_277 ( V_392 ) ;
if ( ! V_394 ) {
V_83 = - V_397 ;
goto V_396;
}
V_83 = F_278 ( V_394 -> V_398 . V_85 -> V_93 , V_399 ) ;
if ( V_83 < 0 )
goto V_396;
V_383 -> V_243 = F_197 ( V_394 ) ;
if ( F_123 ( V_383 -> V_243 ) ) {
V_83 = F_124 ( V_383 -> V_243 ) ;
goto V_396;
}
if ( ! V_383 -> V_243 -> V_400 || ! V_383 -> V_243 -> V_384 ) {
V_83 = - V_134 ;
goto V_396;
}
V_83 = V_383 -> V_243 -> V_400 ( V_3 , V_383 -> V_243 ,
V_383 -> V_385 , V_245 ) ;
if ( V_83 )
goto V_396;
if ( V_393 -> V_284 -> V_401 ( V_393 , & V_383 -> V_390 ) & V_388 ) {
V_383 -> V_243 -> V_384 ( V_3 , V_383 -> V_243 , V_383 -> V_385 ) ;
V_83 = 0 ;
goto V_396;
}
F_68 ( V_3 -> V_85 ) ;
F_73 ( & V_3 -> V_147 ) ;
F_36 ( & V_383 -> V_341 , & V_3 -> V_146 ) ;
F_77 ( & V_3 -> V_147 ) ;
F_279 ( V_394 ) ;
F_279 ( V_393 ) ;
return 0 ;
V_396:
if ( V_394 )
F_279 ( V_394 ) ;
if ( V_383 && V_383 -> V_385 && ! F_123 ( V_383 -> V_385 ) )
F_264 ( V_383 -> V_385 ) ;
if ( ! F_280 ( V_393 ) )
F_279 ( V_393 ) ;
F_21 ( V_383 ) ;
return V_83 ;
}
static T_2 F_281 ( struct V_2 * V_3 ,
struct V_189 * V_243 )
{
return F_8 ( V_3 ) ;
}
static int F_282 ( struct V_2 * V_3 ,
struct V_189 * V_243 ,
T_2 V_255 )
{
if ( V_255 )
F_19 ( V_9 , & V_3 -> V_5 ) ;
else
F_261 ( V_9 , & V_3 -> V_5 ) ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 )
{
int V_282 ;
struct V_81 * V_82 ;
F_72 ( V_3 -> V_85 ) ;
V_282 = F_206 ( V_3 , NULL , V_402 , F_283 ( V_402 ) ) ;
if ( V_282 < 0 )
return V_282 ;
if ( V_3 == V_3 -> V_65 ) {
if ( ( V_282 = F_204 ( V_3 , NULL , & V_403 ) ) < 0 )
return V_282 ;
}
F_60 (cgrp->root, ss) {
if ( V_82 -> V_404 && ( V_282 = V_82 -> V_404 ( V_82 , V_3 ) ) < 0 )
return V_282 ;
}
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_405 ] ;
if ( V_12 -> V_406 )
F_145 ( V_12 -> V_406 -> V_12 , V_12 ) ;
}
return 0 ;
}
static void F_284 ( struct V_11 * V_12 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
V_12 -> V_2 = V_3 ;
F_45 ( & V_12 -> V_407 , 1 ) ;
V_12 -> V_5 = 0 ;
V_12 -> V_406 = NULL ;
if ( V_3 == V_111 )
F_19 ( V_408 , & V_12 -> V_5 ) ;
F_28 ( V_3 -> V_39 [ V_82 -> V_405 ] ) ;
V_3 -> V_39 [ V_82 -> V_405 ] = V_12 ;
}
static void F_285 ( struct V_48 * V_46 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
if ( V_82 -> V_46 == V_46 )
F_51 ( & V_82 -> V_112 ) ;
}
}
static void F_286 ( struct V_48 * V_46 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
if ( V_82 -> V_46 == V_46 )
F_53 ( & V_82 -> V_112 ) ;
}
}
static long F_287 ( struct V_2 * V_91 , struct V_85 * V_85 ,
T_1 V_67 )
{
struct V_2 * V_3 ;
struct V_48 * V_46 = V_91 -> V_46 ;
int V_282 = 0 ;
struct V_81 * V_82 ;
struct V_68 * V_69 = V_46 -> V_69 ;
V_3 = F_113 ( sizeof( * V_3 ) , V_53 ) ;
if ( ! V_3 )
return - V_54 ;
F_24 ( & V_69 -> V_409 ) ;
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
struct V_11 * V_12 = V_82 -> V_410 ( V_82 , V_3 ) ;
if ( F_123 ( V_12 ) ) {
V_282 = F_124 ( V_12 ) ;
goto V_411;
}
F_284 ( V_12 , V_82 , V_3 ) ;
if ( V_82 -> V_412 ) {
V_282 = F_288 ( V_82 , V_91 , V_3 ) ;
if ( V_282 )
goto V_411;
}
if ( F_8 ( V_91 ) && V_82 -> V_413 )
V_82 -> V_413 ( V_82 , V_3 ) ;
}
F_285 ( V_46 ) ;
F_36 ( & V_3 -> V_113 , & V_3 -> V_91 -> V_143 ) ;
F_286 ( V_46 ) ;
V_46 -> V_88 ++ ;
V_282 = F_202 ( V_3 , V_85 , V_67 ) ;
if ( V_282 < 0 )
goto V_414;
F_28 ( ! F_3 ( & V_3 -> V_85 -> V_93 -> V_94 ) ) ;
V_282 = F_102 ( V_3 ) ;
F_53 ( & V_1 ) ;
F_53 ( & V_3 -> V_85 -> V_93 -> V_94 ) ;
return 0 ;
V_414:
F_285 ( V_46 ) ;
F_18 ( & V_3 -> V_113 ) ;
F_286 ( V_46 ) ;
V_46 -> V_88 -- ;
V_411:
F_60 (root, ss) {
if ( V_3 -> V_39 [ V_82 -> V_405 ] )
V_82 -> V_87 ( V_82 , V_3 ) ;
}
F_53 ( & V_1 ) ;
F_64 ( V_69 ) ;
F_21 ( V_3 ) ;
return V_282 ;
}
static int F_289 ( struct V_66 * V_295 , struct V_85 * V_85 , T_1 V_67 )
{
struct V_2 * V_415 = V_85 -> V_92 -> V_86 ;
return F_287 ( V_415 , V_85 , V_67 | V_100 ) ;
}
static int F_290 ( struct V_2 * V_3 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
struct V_11 * V_12 ;
if ( V_82 == NULL || V_82 -> V_46 != V_3 -> V_46 )
continue;
V_12 = V_3 -> V_39 [ V_82 -> V_405 ] ;
if ( V_12 && ( F_208 ( & V_12 -> V_407 ) > 1 ) )
return 1 ;
}
return 0 ;
}
static int F_291 ( struct V_2 * V_3 )
{
struct V_81 * V_82 ;
unsigned long V_5 ;
bool V_416 = false ;
F_292 ( V_5 ) ;
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_405 ] ;
int V_407 ;
while ( 1 ) {
V_407 = F_208 ( & V_12 -> V_407 ) ;
if ( V_407 > 1 ) {
V_416 = true ;
goto V_417;
}
F_28 ( ! V_407 ) ;
if ( F_293 ( & V_12 -> V_407 , V_407 , 0 ) == V_407 )
break;
F_294 () ;
}
}
V_417:
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_405 ] ;
if ( V_416 ) {
if ( ! F_208 ( & V_12 -> V_407 ) )
F_45 ( & V_12 -> V_407 , 1 ) ;
} else {
F_19 ( V_418 , & V_12 -> V_5 ) ;
}
}
F_295 ( V_5 ) ;
return ! V_416 ;
}
static int F_296 ( struct V_66 * V_419 , struct V_85 * V_85 )
{
struct V_2 * V_3 = V_85 -> V_86 ;
struct V_85 * V_90 ;
struct V_2 * V_91 ;
F_297 ( V_386 ) ;
struct V_382 * V_383 , * V_15 ;
int V_83 ;
V_329:
F_51 ( & V_1 ) ;
if ( F_208 ( & V_3 -> V_31 ) != 0 ) {
F_53 ( & V_1 ) ;
return - V_110 ;
}
if ( ! F_38 ( & V_3 -> V_143 ) ) {
F_53 ( & V_1 ) ;
return - V_110 ;
}
F_53 ( & V_1 ) ;
F_19 ( V_101 , & V_3 -> V_5 ) ;
V_83 = F_59 ( V_3 ) ;
if ( V_83 ) {
F_261 ( V_101 , & V_3 -> V_5 ) ;
return V_83 ;
}
F_51 ( & V_1 ) ;
V_91 = V_3 -> V_91 ;
if ( F_208 ( & V_3 -> V_31 ) || ! F_38 ( & V_3 -> V_143 ) ) {
F_261 ( V_101 , & V_3 -> V_5 ) ;
F_53 ( & V_1 ) ;
return - V_110 ;
}
F_298 ( & V_102 , & V_386 , V_362 ) ;
if ( ! F_291 ( V_3 ) ) {
F_53 ( & V_1 ) ;
if ( F_5 ( V_101 , & V_3 -> V_5 ) )
F_299 () ;
F_300 ( & V_102 , & V_386 ) ;
F_261 ( V_101 , & V_3 -> V_5 ) ;
if ( F_301 ( V_242 ) )
return - V_420 ;
goto V_329;
}
F_300 ( & V_102 , & V_386 ) ;
F_261 ( V_101 , & V_3 -> V_5 ) ;
F_302 ( & V_421 ) ;
F_19 ( V_4 , & V_3 -> V_5 ) ;
if ( ! F_38 ( & V_3 -> V_144 ) )
F_75 ( & V_3 -> V_144 ) ;
F_303 ( & V_421 ) ;
F_285 ( V_3 -> V_46 ) ;
F_75 ( & V_3 -> V_113 ) ;
F_286 ( V_3 -> V_46 ) ;
V_90 = F_68 ( V_3 -> V_85 ) ;
F_79 ( V_90 ) ;
F_71 ( V_90 ) ;
F_19 ( V_7 , & V_91 -> V_5 ) ;
F_20 ( V_91 ) ;
F_73 ( & V_3 -> V_147 ) ;
F_17 (event, tmp, &cgrp->event_list, list) {
F_18 ( & V_383 -> V_341 ) ;
F_304 ( V_383 -> V_389 , & V_383 -> V_386 ) ;
F_305 ( V_383 -> V_385 , 1 ) ;
F_267 ( & V_383 -> remove ) ;
}
F_77 ( & V_3 -> V_147 ) ;
F_53 ( & V_1 ) ;
return 0 ;
}
static void T_11 F_306 ( struct V_81 * V_82 )
{
struct V_11 * V_12 ;
F_307 ( V_422 L_19 , V_82 -> V_121 ) ;
F_36 ( & V_82 -> V_113 , & V_109 . V_114 ) ;
V_82 -> V_46 = & V_109 ;
V_12 = V_82 -> V_410 ( V_82 , V_111 ) ;
F_28 ( F_123 ( V_12 ) ) ;
F_284 ( V_12 , V_82 , V_111 ) ;
V_64 . V_39 [ V_82 -> V_405 ] = V_111 -> V_39 [ V_82 -> V_405 ] ;
V_423 |= V_82 -> V_424 || V_82 -> exit ;
F_28 ( ! F_38 ( & V_425 . V_59 ) ) ;
F_104 ( & V_82 -> V_112 ) ;
F_308 ( & V_82 -> V_112 , & V_82 -> V_426 ) ;
V_82 -> V_427 = 1 ;
F_28 ( V_82 -> V_116 ) ;
}
int T_12 F_309 ( struct V_81 * V_82 )
{
int V_13 ;
struct V_11 * V_12 ;
if ( V_82 -> V_121 == NULL || strlen ( V_82 -> V_121 ) > V_302 ||
V_82 -> V_410 == NULL || V_82 -> V_87 == NULL )
return - V_134 ;
if ( V_82 -> V_424 || V_82 -> exit )
return - V_134 ;
if ( V_82 -> V_116 == NULL ) {
F_28 ( V_82 -> V_405 >= V_141 ) ;
F_28 ( V_39 [ V_82 -> V_405 ] != V_82 ) ;
return 0 ;
}
F_51 ( & V_1 ) ;
for ( V_13 = V_141 ; V_13 < V_16 ; V_13 ++ ) {
if ( V_39 [ V_13 ] == NULL )
break;
}
if ( V_13 == V_16 ) {
F_53 ( & V_1 ) ;
return - V_110 ;
}
V_82 -> V_405 = V_13 ;
V_39 [ V_13 ] = V_82 ;
V_12 = V_82 -> V_410 ( V_82 , V_111 ) ;
if ( F_123 ( V_12 ) ) {
V_39 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
return F_124 ( V_12 ) ;
}
F_36 ( & V_82 -> V_113 , & V_109 . V_114 ) ;
V_82 -> V_46 = & V_109 ;
F_284 ( V_12 , V_82 , V_111 ) ;
if ( V_82 -> V_412 ) {
int V_83 = F_310 ( V_82 , V_12 ) ;
if ( V_83 ) {
V_111 -> V_39 [ V_82 -> V_405 ] = NULL ;
V_82 -> V_87 ( V_82 , V_111 ) ;
V_39 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
return V_83 ;
}
}
F_13 ( & V_26 ) ;
for ( V_13 = 0 ; V_13 < V_187 ; V_13 ++ ) {
struct V_19 * V_20 ;
struct V_50 * V_51 , * V_15 ;
struct V_10 * V_428 = & V_18 [ V_13 ] , * V_429 ;
F_311 (cg, node, tmp, bucket, hlist) {
if ( V_20 -> V_39 [ V_82 -> V_405 ] )
continue;
F_16 ( & V_20 -> V_27 ) ;
V_20 -> V_39 [ V_82 -> V_405 ] = V_12 ;
V_429 = F_9 ( V_20 -> V_39 ) ;
F_48 ( & V_20 -> V_27 , V_429 ) ;
}
}
F_15 ( & V_26 ) ;
F_104 ( & V_82 -> V_112 ) ;
F_308 ( & V_82 -> V_112 , & V_82 -> V_426 ) ;
V_82 -> V_427 = 1 ;
F_53 ( & V_1 ) ;
return 0 ;
}
void F_312 ( struct V_81 * V_82 )
{
struct V_22 * V_23 ;
struct V_10 * V_49 ;
F_28 ( V_82 -> V_116 == NULL ) ;
F_28 ( V_82 -> V_46 != & V_109 ) ;
F_51 ( & V_1 ) ;
F_28 ( V_82 -> V_405 < V_141 ) ;
V_39 [ V_82 -> V_405 ] = NULL ;
F_75 ( & V_82 -> V_113 ) ;
F_13 ( & V_26 ) ;
F_47 (link, &dummytop->css_sets, cgrp_link_list) {
struct V_19 * V_20 = V_23 -> V_20 ;
F_16 ( & V_20 -> V_27 ) ;
F_28 ( ! V_20 -> V_39 [ V_82 -> V_405 ] ) ;
V_20 -> V_39 [ V_82 -> V_405 ] = NULL ;
V_49 = F_9 ( V_20 -> V_39 ) ;
F_48 ( & V_20 -> V_27 , V_49 ) ;
}
F_15 ( & V_26 ) ;
V_82 -> V_87 ( V_82 , V_111 ) ;
V_111 -> V_39 [ V_82 -> V_405 ] = NULL ;
F_53 ( & V_1 ) ;
}
int T_11 F_313 ( void )
{
int V_13 ;
F_45 ( & V_64 . V_25 , 1 ) ;
F_34 ( & V_64 . V_40 ) ;
F_34 ( & V_64 . V_59 ) ;
F_46 ( & V_64 . V_27 ) ;
V_28 = 1 ;
F_106 ( & V_109 ) ;
V_58 = 1 ;
V_425 . V_63 = & V_64 ;
V_430 . V_20 = & V_64 ;
V_430 . V_3 = V_111 ;
F_36 ( & V_430 . V_30 ,
& V_109 . V_65 . V_56 ) ;
F_36 ( & V_430 . V_29 ,
& V_64 . V_40 ) ;
for ( V_13 = 0 ; V_13 < V_187 ; V_13 ++ )
F_314 ( & V_18 [ V_13 ] ) ;
for ( V_13 = 0 ; V_13 < V_141 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
F_28 ( ! V_82 -> V_121 ) ;
F_28 ( strlen ( V_82 -> V_121 ) > V_302 ) ;
F_28 ( ! V_82 -> V_410 ) ;
F_28 ( ! V_82 -> V_87 ) ;
if ( V_82 -> V_405 != V_13 ) {
F_307 ( V_431 L_20 ,
V_82 -> V_121 , V_82 -> V_405 ) ;
F_315 () ;
}
if ( V_82 -> V_432 )
F_306 ( V_82 ) ;
}
return 0 ;
}
int T_11 F_316 ( void )
{
int V_282 ;
int V_13 ;
struct V_10 * V_49 ;
V_282 = F_317 ( & V_80 ) ;
if ( V_282 )
return V_282 ;
for ( V_13 = 0 ; V_13 < V_141 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( ! V_82 -> V_432 )
F_306 ( V_82 ) ;
if ( V_82 -> V_412 )
F_310 ( V_82 , V_64 . V_39 [ V_82 -> V_405 ] ) ;
}
V_49 = F_9 ( V_64 . V_39 ) ;
F_48 ( & V_64 . V_27 , V_49 ) ;
F_28 ( ! F_107 ( & V_109 ) ) ;
V_433 = F_318 ( L_21 , V_434 ) ;
if ( ! V_433 ) {
V_282 = - V_54 ;
goto V_215;
}
V_282 = F_319 ( & V_435 ) ;
if ( V_282 < 0 ) {
F_320 ( V_433 ) ;
goto V_215;
}
F_321 ( L_22 , 0 , NULL , & V_436 ) ;
V_215:
if ( V_282 )
F_322 ( & V_80 ) ;
return V_282 ;
}
static int F_323 ( struct V_117 * V_275 , void * V_373 )
{
struct V_233 * V_233 ;
struct V_61 * V_206 ;
char * V_190 ;
int V_211 ;
struct V_48 * V_46 ;
V_211 = - V_54 ;
V_190 = F_35 ( V_328 , V_53 ) ;
if ( ! V_190 )
goto V_215;
V_211 = - V_213 ;
V_233 = V_275 -> V_265 ;
V_206 = F_324 ( V_233 , V_437 ) ;
if ( ! V_206 )
goto V_438;
V_211 = 0 ;
F_51 ( & V_1 ) ;
F_126 (root) {
struct V_81 * V_82 ;
struct V_2 * V_3 ;
int V_31 = 0 ;
F_93 ( V_275 , L_23 , V_46 -> V_152 ) ;
F_60 (root, ss)
F_93 ( V_275 , L_24 , V_31 ++ ? L_6 : L_25 , V_82 -> V_121 ) ;
if ( strlen ( V_46 -> V_121 ) )
F_93 ( V_275 , L_26 , V_31 ? L_6 : L_25 ,
V_46 -> V_121 ) ;
F_173 ( V_275 , ':' ) ;
V_3 = F_49 ( V_206 , V_46 ) ;
V_211 = F_134 ( V_3 , V_190 , V_328 ) ;
if ( V_211 < 0 )
goto V_142;
F_94 ( V_275 , V_190 ) ;
F_173 ( V_275 , '\n' ) ;
}
V_142:
F_53 ( & V_1 ) ;
F_167 ( V_206 ) ;
V_438:
F_21 ( V_190 ) ;
V_215:
return V_211 ;
}
static int F_325 ( struct V_66 * V_66 , struct V_246 * V_246 )
{
struct V_233 * V_233 = F_326 ( V_66 ) -> V_233 ;
return F_191 ( V_246 , F_323 , V_233 ) ;
}
static int F_327 ( struct V_117 * V_275 , void * V_373 )
{
int V_13 ;
F_94 ( V_275 , L_27 ) ;
F_51 ( & V_1 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
F_93 ( V_275 , L_28 ,
V_82 -> V_121 , V_82 -> V_46 -> V_152 ,
V_82 -> V_46 -> V_88 , ! V_82 -> V_139 ) ;
}
F_53 ( & V_1 ) ;
return 0 ;
}
static int F_328 ( struct V_66 * V_66 , struct V_246 * V_246 )
{
return F_191 ( V_246 , F_327 , NULL ) ;
}
void F_329 ( struct V_61 * V_439 )
{
V_439 -> V_63 = V_242 -> V_63 ;
F_23 ( V_439 -> V_63 ) ;
F_34 ( & V_439 -> V_210 ) ;
}
void F_330 ( struct V_61 * V_439 )
{
if ( V_423 ) {
int V_13 ;
for ( V_13 = 0 ; V_13 < V_141 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 -> V_424 )
V_82 -> V_424 ( V_82 , V_439 ) ;
}
}
}
void F_331 ( struct V_61 * V_439 )
{
if ( V_311 ) {
F_13 ( & V_26 ) ;
if ( F_38 ( & V_439 -> V_210 ) ) {
F_36 ( & V_439 -> V_210 , & V_439 -> V_63 -> V_59 ) ;
}
F_15 ( & V_26 ) ;
}
}
void F_332 ( struct V_61 * V_206 , int V_440 )
{
struct V_19 * V_20 ;
int V_13 ;
if ( ! F_38 ( & V_206 -> V_210 ) ) {
F_13 ( & V_26 ) ;
if ( ! F_38 ( & V_206 -> V_210 ) )
F_75 ( & V_206 -> V_210 ) ;
F_15 ( & V_26 ) ;
}
F_144 ( V_206 ) ;
V_20 = V_206 -> V_63 ;
V_206 -> V_63 = & V_64 ;
if ( V_440 && V_423 ) {
for ( V_13 = 0 ; V_13 < V_141 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 -> exit ) {
struct V_2 * V_441 =
F_333 ( V_20 -> V_39 [ V_13 ] ) -> V_2 ;
struct V_2 * V_3 = F_334 ( V_206 , V_13 ) ;
V_82 -> exit ( V_82 , V_3 , V_441 , V_206 ) ;
}
}
}
F_146 ( V_206 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
}
int F_335 ( const struct V_2 * V_3 , struct V_61 * V_62 )
{
int V_83 ;
struct V_2 * V_442 ;
if ( V_3 == V_111 )
return 1 ;
V_442 = F_49 ( V_62 , V_3 -> V_46 ) ;
while ( V_3 != V_442 && V_3 != V_3 -> V_65 )
V_3 = V_3 -> V_91 ;
V_83 = ( V_3 == V_442 ) ;
return V_83 ;
}
static void F_20 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 ) && ! F_208 ( & V_3 -> V_31 )
&& F_38 ( & V_3 -> V_143 ) && ! F_290 ( V_3 ) ) {
int V_443 = 0 ;
F_302 ( & V_421 ) ;
if ( ! F_4 ( V_3 ) &&
F_38 ( & V_3 -> V_144 ) ) {
F_36 ( & V_3 -> V_144 , & V_144 ) ;
V_443 = 1 ;
}
F_303 ( & V_421 ) ;
if ( V_443 )
F_267 ( & V_444 ) ;
}
}
void F_336 ( struct V_11 * V_12 , int V_31 )
{
struct V_2 * V_3 = V_12 -> V_2 ;
int V_255 ;
F_160 () ;
V_255 = F_337 ( V_31 , & V_12 -> V_407 ) ;
if ( V_255 == 1 ) {
if ( F_7 ( V_3 ) ) {
F_19 ( V_7 , & V_3 -> V_5 ) ;
F_20 ( V_3 ) ;
}
F_80 ( V_3 ) ;
}
F_162 () ;
F_142 ( V_255 < 1 ) ;
}
static void F_338 ( struct V_380 * V_381 )
{
F_28 ( V_381 != & V_444 ) ;
F_51 ( & V_1 ) ;
F_302 ( & V_421 ) ;
while ( ! F_38 ( & V_144 ) ) {
char * V_445 [ 3 ] , * V_446 [ 3 ] ;
int V_13 ;
char * V_447 = NULL , * V_448 = NULL ;
struct V_2 * V_3 = F_29 ( V_144 . V_45 ,
struct V_2 ,
V_144 ) ;
F_75 ( & V_3 -> V_144 ) ;
F_303 ( & V_421 ) ;
V_447 = F_35 ( V_328 , V_53 ) ;
if ( ! V_447 )
goto V_449;
if ( F_134 ( V_3 , V_447 , V_328 ) < 0 )
goto V_449;
V_448 = F_339 ( V_3 -> V_46 -> V_123 , V_53 ) ;
if ( ! V_448 )
goto V_449;
V_13 = 0 ;
V_445 [ V_13 ++ ] = V_448 ;
V_445 [ V_13 ++ ] = V_447 ;
V_445 [ V_13 ] = NULL ;
V_13 = 0 ;
V_446 [ V_13 ++ ] = L_29 ;
V_446 [ V_13 ++ ] = L_30 ;
V_446 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
F_340 ( V_445 [ 0 ] , V_445 , V_446 , V_450 ) ;
F_51 ( & V_1 ) ;
V_449:
F_21 ( V_447 ) ;
F_21 ( V_448 ) ;
F_302 ( & V_421 ) ;
}
F_303 ( & V_421 ) ;
F_53 ( & V_1 ) ;
}
static int T_11 F_341 ( char * V_451 )
{
int V_13 ;
char * V_127 ;
while ( ( V_127 = F_97 ( & V_451 , L_6 ) ) != NULL ) {
if ( ! * V_127 )
continue;
for ( V_13 = 0 ; V_13 < V_141 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( ! strcmp ( V_127 , V_82 -> V_121 ) ) {
V_82 -> V_139 = 1 ;
F_307 ( V_422 L_31
L_32 , V_82 -> V_121 ) ;
break;
}
}
}
return 1 ;
}
unsigned short F_342 ( struct V_11 * V_12 )
{
struct F_342 * V_452 ;
V_452 = F_135 ( V_12 -> V_406 , F_208 ( & V_12 -> V_407 ) ) ;
if ( V_452 )
return V_452 -> V_406 ;
return 0 ;
}
unsigned short F_343 ( struct V_11 * V_12 )
{
struct F_342 * V_452 ;
V_452 = F_135 ( V_12 -> V_406 , F_208 ( & V_12 -> V_407 ) ) ;
if ( V_452 )
return V_452 -> V_453 ;
return 0 ;
}
bool F_344 ( struct V_11 * V_439 ,
const struct V_11 * V_46 )
{
struct F_342 * V_454 ;
struct F_342 * V_455 ;
bool V_83 = true ;
F_160 () ;
V_454 = F_345 ( V_439 -> V_406 ) ;
V_455 = F_345 ( V_46 -> V_406 ) ;
if ( ! V_454
|| ! V_455
|| ( V_454 -> V_453 < V_455 -> V_453 )
|| ( V_454 -> V_456 [ V_455 -> V_453 ] != V_455 -> V_406 ) )
V_83 = false ;
F_162 () ;
return V_83 ;
}
void F_346 ( struct V_81 * V_82 , struct V_11 * V_12 )
{
struct F_342 * V_406 = V_12 -> V_406 ;
if ( ! V_406 )
return;
F_28 ( ! V_82 -> V_412 ) ;
F_145 ( V_406 -> V_12 , NULL ) ;
F_145 ( V_12 -> V_406 , NULL ) ;
F_13 ( & V_82 -> V_457 ) ;
F_347 ( & V_82 -> V_458 , V_406 -> V_406 ) ;
F_15 ( & V_82 -> V_457 ) ;
F_22 ( V_406 , V_32 ) ;
}
static struct F_342 * F_348 ( struct V_81 * V_82 , int V_453 )
{
struct F_342 * V_459 ;
int V_460 , error , V_330 ;
F_28 ( ! V_82 -> V_412 ) ;
V_330 = sizeof( * V_459 ) + sizeof( unsigned short ) * ( V_453 + 1 ) ;
V_459 = F_113 ( V_330 , V_53 ) ;
if ( ! V_459 )
return F_114 ( - V_54 ) ;
if ( F_81 ( ! F_349 ( & V_82 -> V_458 , V_53 ) ) ) {
error = - V_54 ;
goto V_461;
}
F_13 ( & V_82 -> V_457 ) ;
error = F_350 ( & V_82 -> V_458 , V_459 , 1 , & V_460 ) ;
F_15 ( & V_82 -> V_457 ) ;
if ( error ) {
error = - V_153 ;
goto V_461;
}
if ( V_460 > V_462 )
goto V_463;
V_459 -> V_406 = V_460 ;
V_459 -> V_453 = V_453 ;
return V_459 ;
V_463:
error = - V_153 ;
F_13 ( & V_82 -> V_457 ) ;
F_347 ( & V_82 -> V_458 , V_460 ) ;
F_15 ( & V_82 -> V_457 ) ;
V_461:
F_21 ( V_459 ) ;
return F_114 ( error ) ;
}
static int T_12 F_310 ( struct V_81 * V_82 ,
struct V_11 * V_464 )
{
struct F_342 * V_459 ;
F_351 ( & V_82 -> V_457 ) ;
F_352 ( & V_82 -> V_458 ) ;
V_459 = F_348 ( V_82 , 0 ) ;
if ( F_123 ( V_459 ) )
return F_124 ( V_459 ) ;
V_459 -> V_456 [ 0 ] = V_459 -> V_406 ;
V_459 -> V_12 = V_464 ;
V_464 -> V_406 = V_459 ;
return 0 ;
}
static int F_288 ( struct V_81 * V_82 , struct V_2 * V_91 ,
struct V_2 * V_439 )
{
int V_405 , V_13 , V_453 = 0 ;
struct V_11 * V_465 , * V_466 ;
struct F_342 * V_454 , * V_467 ;
V_405 = V_82 -> V_405 ;
V_465 = V_91 -> V_39 [ V_405 ] ;
V_466 = V_439 -> V_39 [ V_405 ] ;
V_467 = V_465 -> V_406 ;
V_453 = V_467 -> V_453 + 1 ;
V_454 = F_348 ( V_82 , V_453 ) ;
if ( F_123 ( V_454 ) )
return F_124 ( V_454 ) ;
for ( V_13 = 0 ; V_13 < V_453 ; V_13 ++ )
V_454 -> V_456 [ V_13 ] = V_467 -> V_456 [ V_13 ] ;
V_454 -> V_456 [ V_453 ] = V_454 -> V_406 ;
F_145 ( V_466 -> V_406 , V_454 ) ;
return 0 ;
}
struct V_11 * F_353 ( struct V_81 * V_82 , int V_406 )
{
struct F_342 * V_452 = NULL ;
F_28 ( ! V_82 -> V_412 ) ;
V_452 = F_354 ( & V_82 -> V_458 , V_406 ) ;
if ( F_81 ( ! V_452 ) )
return NULL ;
return F_345 ( V_452 -> V_12 ) ;
}
struct V_11 *
F_355 ( struct V_81 * V_82 , int V_406 ,
struct V_11 * V_46 , int * V_468 )
{
struct V_11 * V_83 = NULL ;
struct F_342 * V_15 ;
int V_469 ;
int V_470 = F_342 ( V_46 ) ;
int V_453 = F_343 ( V_46 ) ;
if ( ! V_470 )
return NULL ;
F_28 ( ! V_82 -> V_412 ) ;
V_469 = V_406 ;
while ( 1 ) {
F_43 ( & V_82 -> V_457 ) ;
V_15 = F_356 ( & V_82 -> V_458 , & V_469 ) ;
F_44 ( & V_82 -> V_457 ) ;
if ( ! V_15 )
break;
if ( V_15 -> V_453 >= V_453 && V_15 -> V_456 [ V_453 ] == V_470 ) {
V_83 = F_345 ( V_15 -> V_12 ) ;
if ( V_83 ) {
* V_468 = V_469 ;
break;
}
}
V_469 = V_469 + 1 ;
}
return V_83 ;
}
struct V_11 * F_357 ( struct V_246 * V_471 , int V_406 )
{
struct V_2 * V_3 ;
struct V_66 * V_66 ;
struct V_11 * V_12 ;
V_66 = V_471 -> V_262 -> V_93 ;
if ( V_66 -> V_172 != & V_173 )
return F_114 ( - V_397 ) ;
if ( V_406 < 0 || V_406 >= V_16 )
return F_114 ( - V_134 ) ;
V_3 = F_132 ( V_471 -> V_262 ) ;
V_12 = V_3 -> V_39 [ V_406 ] ;
return V_12 ? V_12 : F_114 ( - V_140 ) ;
}
static struct V_11 * F_358 ( struct V_81 * V_82 ,
struct V_2 * V_472 )
{
struct V_11 * V_12 = F_113 ( sizeof( * V_12 ) , V_53 ) ;
if ( ! V_12 )
return F_114 ( - V_54 ) ;
return V_12 ;
}
static void F_359 ( struct V_81 * V_82 , struct V_2 * V_472 )
{
F_21 ( V_472 -> V_39 [ V_473 ] ) ;
}
static T_2 F_360 ( struct V_2 * V_472 , struct V_189 * V_243 )
{
return F_208 ( & V_472 -> V_31 ) ;
}
static T_2 F_361 ( struct V_2 * V_472 , struct V_189 * V_243 )
{
return F_207 ( V_472 ) ;
}
static T_2 F_362 ( struct V_2 * V_472 , struct V_189 * V_243 )
{
return ( T_2 ) ( unsigned long ) V_242 -> V_63 ;
}
static T_2 F_363 ( struct V_2 * V_472 ,
struct V_189 * V_243 )
{
T_2 V_31 ;
F_160 () ;
V_31 = F_208 ( & V_242 -> V_63 -> V_25 ) ;
F_162 () ;
return V_31 ;
}
static int F_364 ( struct V_2 * V_472 ,
struct V_189 * V_243 ,
struct V_117 * V_118 )
{
struct V_22 * V_23 ;
struct V_19 * V_20 ;
F_43 ( & V_26 ) ;
F_160 () ;
V_20 = F_345 ( V_242 -> V_63 ) ;
F_47 (link, &cg->cg_links, cg_link_list) {
struct V_2 * V_60 = V_23 -> V_3 ;
const char * V_121 ;
if ( V_60 -> V_85 )
V_121 = V_60 -> V_85 -> V_194 . V_121 ;
else
V_121 = L_33 ;
F_93 ( V_118 , L_34 ,
V_60 -> V_46 -> V_152 , V_121 ) ;
}
F_162 () ;
F_44 ( & V_26 ) ;
return 0 ;
}
static int F_365 ( struct V_2 * V_472 ,
struct V_189 * V_243 ,
struct V_117 * V_118 )
{
struct V_22 * V_23 ;
F_43 ( & V_26 ) ;
F_47 (link, &cont->css_sets, cgrp_link_list) {
struct V_19 * V_20 = V_23 -> V_20 ;
struct V_61 * V_62 ;
int V_31 = 0 ;
F_93 ( V_118 , L_35 , V_20 ) ;
F_47 (task, &cg->tasks, cg_list) {
if ( V_31 ++ > V_474 ) {
F_94 ( V_118 , L_36 ) ;
break;
} else {
F_93 ( V_118 , L_37 ,
F_240 ( V_62 ) ) ;
}
}
}
F_44 ( & V_26 ) ;
return 0 ;
}
static T_2 F_366 ( struct V_2 * V_3 , struct V_189 * V_243 )
{
return F_5 ( V_7 , & V_3 -> V_5 ) ;
}
static int F_367 ( struct V_81 * V_82 , struct V_2 * V_472 )
{
return F_206 ( V_472 , V_82 , V_475 ,
F_283 ( V_475 ) ) ;
}
