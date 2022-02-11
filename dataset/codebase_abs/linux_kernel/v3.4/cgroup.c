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
V_83 = V_82 -> V_84 ( V_3 ) ;
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
V_82 -> V_87 ( V_3 ) ;
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
V_82 -> V_115 ( V_3 ) ;
F_53 ( & V_82 -> V_112 ) ;
} else if ( V_108 & V_105 ) {
F_28 ( V_82 == NULL ) ;
F_28 ( V_3 -> V_39 [ V_13 ] != V_111 -> V_39 [ V_13 ] ) ;
F_28 ( V_3 -> V_39 [ V_13 ] -> V_2 != V_3 ) ;
F_51 ( & V_82 -> V_112 ) ;
if ( V_82 -> V_115 )
V_82 -> V_115 ( V_111 ) ;
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
if ( ! V_66 )
return - V_54 ;
V_66 -> V_170 = & V_171 ;
V_66 -> V_172 = & V_173 ;
F_120 ( V_66 ) ;
V_69 -> V_174 = F_121 ( V_66 ) ;
if ( ! V_69 -> V_174 )
return - V_54 ;
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
static void F_141 ( struct V_2 * V_3 , struct V_2 * V_205 ,
struct V_61 * V_206 , struct V_19 * V_207 )
{
struct V_19 * V_47 ;
F_142 ( V_206 -> V_5 & V_208 ) ;
V_47 = V_206 -> V_63 ;
F_143 ( V_206 ) ;
F_144 ( V_206 -> V_63 , V_207 ) ;
F_145 ( V_206 ) ;
F_13 ( & V_26 ) ;
if ( ! F_38 ( & V_206 -> V_209 ) )
F_40 ( & V_206 -> V_209 , & V_207 -> V_59 ) ;
F_15 ( & V_26 ) ;
F_25 ( V_47 ) ;
F_19 ( V_7 , & V_205 -> V_5 ) ;
}
int F_146 ( struct V_2 * V_3 , struct V_61 * V_206 )
{
int V_210 = 0 ;
struct V_81 * V_82 , * V_211 = NULL ;
struct V_2 * V_205 ;
struct V_48 * V_46 = V_3 -> V_46 ;
struct V_196 V_197 = { } ;
struct V_19 * V_207 ;
if ( V_206 -> V_5 & V_208 )
return - V_212 ;
V_205 = F_49 ( V_206 , V_46 ) ;
if ( V_3 == V_205 )
return 0 ;
V_197 . V_201 . V_62 = V_206 ;
V_197 . V_201 . V_3 = V_205 ;
F_60 (root, ss) {
if ( V_82 -> V_213 ) {
V_210 = V_82 -> V_213 ( V_3 , & V_197 ) ;
if ( V_210 ) {
V_211 = V_82 ;
goto V_214;
}
}
}
V_207 = F_42 ( V_206 -> V_63 , V_3 ) ;
if ( ! V_207 ) {
V_210 = - V_54 ;
goto V_214;
}
F_141 ( V_3 , V_205 , V_206 , V_207 ) ;
F_60 (root, ss) {
if ( V_82 -> V_215 )
V_82 -> V_215 ( V_3 , & V_197 ) ;
}
F_63 () ;
F_80 ( V_3 ) ;
V_214:
if ( V_210 ) {
F_60 (root, ss) {
if ( V_82 == V_211 )
break;
if ( V_82 -> V_216 )
V_82 -> V_216 ( V_3 , & V_197 ) ;
}
}
return V_210 ;
}
int F_147 ( struct V_61 * V_217 , struct V_61 * V_206 )
{
struct V_48 * V_46 ;
int V_210 = 0 ;
F_50 () ;
F_126 (root) {
struct V_2 * V_218 = F_49 ( V_217 , V_46 ) ;
V_210 = F_146 ( V_218 , V_206 ) ;
if ( V_210 )
break;
}
F_52 () ;
return V_210 ;
}
static int F_148 ( struct V_2 * V_3 , struct V_61 * V_219 )
{
int V_210 , V_13 , V_220 ;
struct V_81 * V_82 , * V_211 = NULL ;
struct V_48 * V_46 = V_3 -> V_46 ;
struct V_61 * V_206 ;
struct V_202 * V_203 ;
struct V_221 * V_222 ;
struct V_196 V_197 = { } ;
V_220 = F_149 ( V_219 ) ;
V_222 = F_150 ( sizeof( * V_203 ) , V_220 , V_53 ) ;
if ( ! V_222 )
return - V_54 ;
V_210 = F_151 ( V_222 , 0 , V_220 - 1 , V_53 ) ;
if ( V_210 )
goto V_223;
V_206 = V_219 ;
V_13 = 0 ;
F_152 () ;
do {
struct V_202 V_224 ;
if ( V_206 -> V_5 & V_208 )
continue;
F_28 ( V_13 >= V_220 ) ;
V_224 . V_62 = V_206 ;
V_224 . V_3 = F_49 ( V_206 , V_46 ) ;
if ( V_224 . V_3 == V_3 )
continue;
V_210 = F_153 ( V_222 , V_13 , & V_224 , V_225 ) ;
F_28 ( V_210 != 0 ) ;
V_13 ++ ;
} while_each_thread(leader, tsk) ;
int F_154 ( struct V_2 * V_3 , T_2 V_226 , bool V_227 )
{
struct V_61 * V_206 ;
const struct V_183 * V_183 = F_155 () , * V_228 ;
int V_83 ;
if ( ! F_156 ( V_3 ) )
return - V_229 ;
V_230:
F_152 () ;
if ( V_226 ) {
V_206 = F_157 ( V_226 ) ;
if ( ! V_206 ) {
F_158 () ;
V_83 = - V_212 ;
goto V_231;
}
V_228 = F_159 ( V_206 ) ;
if ( V_183 -> V_232 &&
V_183 -> V_232 != V_228 -> V_233 &&
V_183 -> V_232 != V_228 -> V_234 ) {
F_158 () ;
V_83 = - V_235 ;
goto V_231;
}
} else
V_206 = V_236 ;
if ( V_227 )
V_206 = V_206 -> V_237 ;
F_160 ( V_206 ) ;
F_158 () ;
F_161 ( V_206 ) ;
if ( V_227 ) {
if ( ! F_162 ( V_206 ) ) {
F_163 ( V_206 ) ;
F_164 ( V_206 ) ;
goto V_230;
}
V_83 = F_148 ( V_3 , V_206 ) ;
} else
V_83 = F_146 ( V_3 , V_206 ) ;
F_163 ( V_206 ) ;
F_164 ( V_206 ) ;
V_231:
F_52 () ;
return V_83 ;
}
static int F_165 ( struct V_2 * V_3 , struct V_189 * V_238 , T_2 V_226 )
{
return F_154 ( V_3 , V_226 , false ) ;
}
static int F_166 ( struct V_2 * V_3 , struct V_189 * V_238 , T_2 V_239 )
{
return F_154 ( V_3 , V_239 , true ) ;
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
static int F_167 ( struct V_2 * V_3 , struct V_189 * V_238 ,
const char * V_240 )
{
F_168 ( sizeof( V_3 -> V_46 -> V_123 ) < V_137 ) ;
if ( strlen ( V_240 ) >= V_137 )
return - V_134 ;
if ( ! F_156 ( V_3 ) )
return - V_229 ;
F_51 ( & V_106 ) ;
strcpy ( V_3 -> V_46 -> V_123 , V_240 ) ;
F_53 ( & V_106 ) ;
F_52 () ;
return 0 ;
}
static int F_169 ( struct V_2 * V_3 , struct V_189 * V_238 ,
struct V_117 * V_118 )
{
if ( ! F_156 ( V_3 ) )
return - V_229 ;
F_94 ( V_118 , V_3 -> V_46 -> V_123 ) ;
F_170 ( V_118 , '\n' ) ;
F_52 () ;
return 0 ;
}
static T_3 F_171 ( struct V_2 * V_3 , struct V_189 * V_238 ,
struct V_241 * V_241 ,
const char T_4 * V_242 ,
T_5 V_243 , T_6 * V_244 )
{
char V_240 [ V_245 ] ;
int V_210 = 0 ;
char * V_246 ;
if ( ! V_243 )
return - V_134 ;
if ( V_243 >= sizeof( V_240 ) )
return - V_247 ;
if ( F_172 ( V_240 , V_242 , V_243 ) )
return - V_248 ;
V_240 [ V_243 ] = 0 ;
if ( V_238 -> V_249 ) {
T_2 V_250 = F_173 ( F_174 ( V_240 ) , & V_246 , 0 ) ;
if ( * V_246 )
return - V_134 ;
V_210 = V_238 -> V_249 ( V_3 , V_238 , V_250 ) ;
} else {
T_7 V_250 = F_175 ( F_174 ( V_240 ) , & V_246 , 0 ) ;
if ( * V_246 )
return - V_134 ;
V_210 = V_238 -> V_251 ( V_3 , V_238 , V_250 ) ;
}
if ( ! V_210 )
V_210 = V_243 ;
return V_210 ;
}
static T_3 F_176 ( struct V_2 * V_3 , struct V_189 * V_238 ,
struct V_241 * V_241 ,
const char T_4 * V_242 ,
T_5 V_243 , T_6 * V_244 )
{
char V_252 [ V_245 ] ;
int V_210 = 0 ;
T_5 V_253 = V_238 -> V_254 ;
char * V_240 = V_252 ;
if ( ! V_253 )
V_253 = sizeof( V_252 ) - 1 ;
if ( V_243 >= V_253 )
return - V_247 ;
if ( V_243 >= sizeof( V_252 ) ) {
V_240 = F_35 ( V_243 + 1 , V_53 ) ;
if ( V_240 == NULL )
return - V_54 ;
}
if ( V_243 && F_172 ( V_240 , V_242 , V_243 ) ) {
V_210 = - V_248 ;
goto V_214;
}
V_240 [ V_243 ] = 0 ;
V_210 = V_238 -> V_255 ( V_3 , V_238 , F_174 ( V_240 ) ) ;
if ( ! V_210 )
V_210 = V_243 ;
V_214:
if ( V_240 != V_252 )
F_21 ( V_240 ) ;
return V_210 ;
}
static T_3 F_177 ( struct V_241 * V_241 , const char T_4 * V_190 ,
T_5 V_243 , T_6 * V_256 )
{
struct V_189 * V_238 = F_133 ( V_241 -> V_257 ) ;
struct V_2 * V_3 = F_132 ( V_241 -> V_257 -> V_92 ) ;
if ( F_4 ( V_3 ) )
return - V_229 ;
if ( V_238 -> V_258 )
return V_238 -> V_258 ( V_3 , V_238 , V_241 , V_190 , V_243 , V_256 ) ;
if ( V_238 -> V_249 || V_238 -> V_251 )
return F_171 ( V_3 , V_238 , V_241 , V_190 , V_243 , V_256 ) ;
if ( V_238 -> V_255 )
return F_176 ( V_3 , V_238 , V_241 , V_190 , V_243 , V_256 ) ;
if ( V_238 -> V_259 ) {
int V_83 = V_238 -> V_259 ( V_3 , ( unsigned int ) V_238 -> V_260 ) ;
return V_83 ? V_83 : V_243 ;
}
return - V_134 ;
}
static T_3 F_178 ( struct V_2 * V_3 , struct V_189 * V_238 ,
struct V_241 * V_241 ,
char T_4 * V_190 , T_5 V_243 ,
T_6 * V_256 )
{
char V_15 [ V_245 ] ;
T_2 V_250 = V_238 -> V_261 ( V_3 , V_238 ) ;
int V_193 = sprintf ( V_15 , L_14 , ( unsigned long long ) V_250 ) ;
return F_179 ( V_190 , V_243 , V_256 , V_15 , V_193 ) ;
}
static T_3 F_180 ( struct V_2 * V_3 , struct V_189 * V_238 ,
struct V_241 * V_241 ,
char T_4 * V_190 , T_5 V_243 ,
T_6 * V_256 )
{
char V_15 [ V_245 ] ;
T_7 V_250 = V_238 -> V_262 ( V_3 , V_238 ) ;
int V_193 = sprintf ( V_15 , L_15 , ( long long ) V_250 ) ;
return F_179 ( V_190 , V_243 , V_256 , V_15 , V_193 ) ;
}
static T_3 F_181 ( struct V_241 * V_241 , char T_4 * V_190 ,
T_5 V_243 , T_6 * V_256 )
{
struct V_189 * V_238 = F_133 ( V_241 -> V_257 ) ;
struct V_2 * V_3 = F_132 ( V_241 -> V_257 -> V_92 ) ;
if ( F_4 ( V_3 ) )
return - V_229 ;
if ( V_238 -> V_263 )
return V_238 -> V_263 ( V_3 , V_238 , V_241 , V_190 , V_243 , V_256 ) ;
if ( V_238 -> V_261 )
return F_178 ( V_3 , V_238 , V_241 , V_190 , V_243 , V_256 ) ;
if ( V_238 -> V_262 )
return F_180 ( V_3 , V_238 , V_241 , V_190 , V_243 , V_256 ) ;
return - V_134 ;
}
static int F_182 ( struct V_264 * V_265 , const char * V_266 , T_2 V_267 )
{
struct V_117 * V_268 = V_265 -> V_269 ;
return F_93 ( V_268 , L_16 , V_266 , ( unsigned long long ) V_267 ) ;
}
static int F_183 ( struct V_117 * V_270 , void * V_271 )
{
struct V_272 * V_269 = V_270 -> V_260 ;
struct V_189 * V_238 = V_269 -> V_238 ;
if ( V_238 -> V_273 ) {
struct V_264 V_265 = {
. V_274 = F_182 ,
. V_269 = V_270 ,
} ;
return V_238 -> V_273 ( V_269 -> V_2 , V_238 , & V_265 ) ;
}
return V_238 -> V_275 ( V_269 -> V_2 , V_238 , V_270 ) ;
}
static int F_184 ( struct V_66 * V_66 , struct V_241 * V_241 )
{
struct V_117 * V_118 = V_241 -> V_276 ;
F_21 ( V_118 -> V_260 ) ;
return F_185 ( V_66 , V_241 ) ;
}
static int F_186 ( struct V_66 * V_66 , struct V_241 * V_241 )
{
int V_277 ;
struct V_189 * V_238 ;
V_277 = F_187 ( V_66 , V_241 ) ;
if ( V_277 )
return V_277 ;
V_238 = F_133 ( V_241 -> V_257 ) ;
if ( V_238 -> V_273 || V_238 -> V_275 ) {
struct V_272 * V_269 =
F_113 ( sizeof( * V_269 ) , V_278 ) ;
if ( ! V_269 )
return - V_54 ;
V_269 -> V_238 = V_238 ;
V_269 -> V_2 = F_132 ( V_241 -> V_257 -> V_92 ) ;
V_241 -> V_279 = & V_280 ;
V_277 = F_188 ( V_241 , F_183 , V_269 ) ;
if ( V_277 < 0 )
F_21 ( V_269 ) ;
} else if ( V_238 -> V_281 )
V_277 = V_238 -> V_281 ( V_66 , V_241 ) ;
else
V_277 = 0 ;
return V_277 ;
}
static int F_189 ( struct V_66 * V_66 , struct V_241 * V_241 )
{
struct V_189 * V_238 = F_133 ( V_241 -> V_257 ) ;
if ( V_238 -> V_282 )
return V_238 -> V_282 ( V_66 , V_241 ) ;
return 0 ;
}
static int F_190 ( struct V_66 * V_283 , struct V_85 * V_284 ,
struct V_66 * V_285 , struct V_85 * V_286 )
{
if ( ! F_62 ( V_284 -> V_93 -> V_71 ) )
return - V_287 ;
if ( V_286 -> V_93 )
return - V_288 ;
if ( V_283 != V_285 )
return - V_289 ;
return F_191 ( V_283 , V_284 , V_285 , V_286 ) ;
}
static struct V_85 * F_192 ( struct V_66 * V_290 , struct V_85 * V_85 , struct V_291 * V_292 )
{
if ( V_85 -> V_194 . V_193 > V_293 )
return F_114 ( - V_195 ) ;
F_193 ( V_85 , NULL ) ;
return NULL ;
}
static inline struct V_189 * F_194 ( struct V_241 * V_241 )
{
if ( V_241 -> V_257 -> V_93 -> V_170 != & V_294 )
return F_114 ( - V_134 ) ;
return F_133 ( V_241 -> V_257 ) ;
}
static int F_195 ( struct V_85 * V_85 , T_1 V_67 ,
struct V_68 * V_69 )
{
struct V_66 * V_66 ;
if ( ! V_85 )
return - V_140 ;
if ( V_85 -> V_93 )
return - V_288 ;
V_66 = F_54 ( V_67 , V_69 ) ;
if ( ! V_66 )
return - V_54 ;
if ( F_62 ( V_67 ) ) {
V_66 -> V_172 = & V_173 ;
V_66 -> V_170 = & V_171 ;
F_120 ( V_66 ) ;
F_196 ( & V_66 -> V_94 , V_295 ) ;
} else if ( F_197 ( V_67 ) ) {
V_66 -> V_296 = 0 ;
V_66 -> V_170 = & V_294 ;
}
F_198 ( V_85 , V_66 ) ;
F_68 ( V_85 ) ;
return 0 ;
}
static int F_199 ( struct V_2 * V_3 , struct V_85 * V_85 ,
T_1 V_67 )
{
struct V_85 * V_91 ;
int error = 0 ;
V_91 = V_3 -> V_91 -> V_85 ;
error = F_195 ( V_85 , V_100 | V_67 , V_3 -> V_46 -> V_69 ) ;
if ( ! error ) {
V_85 -> V_86 = V_3 ;
F_120 ( V_91 -> V_93 ) ;
F_144 ( V_3 -> V_85 , V_85 ) ;
F_68 ( V_85 ) ;
}
F_71 ( V_85 ) ;
return error ;
}
static T_1 F_200 ( const struct V_189 * V_238 )
{
T_1 V_67 = 0 ;
if ( V_238 -> V_67 )
return V_238 -> V_67 ;
if ( V_238 -> V_263 || V_238 -> V_261 || V_238 -> V_262 ||
V_238 -> V_273 || V_238 -> V_275 )
V_67 |= V_167 ;
if ( V_238 -> V_258 || V_238 -> V_249 || V_238 -> V_251 ||
V_238 -> V_255 || V_238 -> V_259 )
V_67 |= V_169 ;
return V_67 ;
}
int F_201 ( struct V_2 * V_3 ,
struct V_81 * V_39 ,
const struct V_189 * V_238 )
{
struct V_85 * V_290 = V_3 -> V_85 ;
struct V_85 * V_85 ;
int error ;
T_1 V_67 ;
char V_121 [ V_297 + V_298 + 2 ] = { 0 } ;
if ( V_39 && ! F_5 ( V_122 , & V_3 -> V_46 -> V_5 ) ) {
strcpy ( V_121 , V_39 -> V_121 ) ;
strcat ( V_121 , L_17 ) ;
}
strcat ( V_121 , V_238 -> V_121 ) ;
F_28 ( ! F_3 ( & V_290 -> V_93 -> V_94 ) ) ;
V_85 = F_202 ( V_121 , V_290 , strlen ( V_121 ) ) ;
if ( ! F_123 ( V_85 ) ) {
V_67 = F_200 ( V_238 ) ;
error = F_195 ( V_85 , V_67 | V_299 ,
V_3 -> V_46 -> V_69 ) ;
if ( ! error )
V_85 -> V_86 = ( void * ) V_238 ;
F_71 ( V_85 ) ;
} else
error = F_124 ( V_85 ) ;
return error ;
}
int F_203 ( struct V_2 * V_3 ,
struct V_81 * V_39 ,
const struct V_189 V_238 [] ,
int V_31 )
{
int V_13 , V_277 ;
for ( V_13 = 0 ; V_13 < V_31 ; V_13 ++ ) {
V_277 = F_201 ( V_3 , V_39 , & V_238 [ V_13 ] ) ;
if ( V_277 )
return V_277 ;
}
return 0 ;
}
int F_204 ( const struct V_2 * V_3 )
{
int V_31 = 0 ;
struct V_22 * V_23 ;
F_43 ( & V_26 ) ;
F_47 (link, &cgrp->css_sets, cgrp_link_list) {
V_31 += F_205 ( & V_23 -> V_20 -> V_25 ) ;
}
F_44 ( & V_26 ) ;
return V_31 ;
}
static void F_206 ( struct V_2 * V_3 ,
struct V_300 * V_301 )
{
struct V_36 * V_302 = V_301 -> V_303 ;
struct V_22 * V_23 ;
struct V_19 * V_20 ;
do {
V_302 = V_302 -> V_45 ;
if ( V_302 == & V_3 -> V_56 ) {
V_301 -> V_303 = NULL ;
return;
}
V_23 = F_29 ( V_302 , struct V_22 , V_30 ) ;
V_20 = V_23 -> V_20 ;
} while ( F_38 ( & V_20 -> V_59 ) );
V_301 -> V_303 = V_302 ;
V_301 -> V_62 = V_20 -> V_59 . V_45 ;
}
static void F_207 ( void )
{
struct V_61 * V_304 , * V_305 ;
F_13 ( & V_26 ) ;
V_306 = 1 ;
F_43 ( & V_307 ) ;
F_208 (g, p) {
F_143 ( V_304 ) ;
if ( ! ( V_304 -> V_5 & V_208 ) && F_38 ( & V_304 -> V_209 ) )
F_36 ( & V_304 -> V_209 , & V_304 -> V_63 -> V_59 ) ;
F_145 ( V_304 ) ;
} F_209 ( V_305 , V_304 ) ;
F_44 ( & V_307 ) ;
F_15 ( & V_26 ) ;
}
void F_210 ( struct V_2 * V_3 , struct V_300 * V_301 )
__acquires( V_26 )
{
if ( ! V_306 )
F_207 () ;
F_43 ( & V_26 ) ;
V_301 -> V_303 = & V_3 -> V_56 ;
F_206 ( V_3 , V_301 ) ;
}
struct V_61 * F_211 ( struct V_2 * V_3 ,
struct V_300 * V_301 )
{
struct V_61 * V_57 ;
struct V_36 * V_302 = V_301 -> V_62 ;
struct V_22 * V_23 ;
if ( ! V_301 -> V_303 )
return NULL ;
V_57 = F_29 ( V_302 , struct V_61 , V_209 ) ;
V_302 = V_302 -> V_45 ;
V_23 = F_29 ( V_301 -> V_303 , struct V_22 , V_30 ) ;
if ( V_302 == & V_23 -> V_20 -> V_59 ) {
F_206 ( V_3 , V_301 ) ;
} else {
V_301 -> V_62 = V_302 ;
}
return V_57 ;
}
void F_212 ( struct V_2 * V_3 , struct V_300 * V_301 )
__releases( V_26 )
{
F_44 ( & V_26 ) ;
}
static inline int F_213 ( struct V_61 * V_308 ,
struct V_309 * time ,
struct V_61 * V_310 )
{
int V_311 = F_214 ( & V_308 -> V_312 , time ) ;
if ( V_311 > 0 ) {
return 1 ;
} else if ( V_311 < 0 ) {
return 0 ;
} else {
return V_308 > V_310 ;
}
}
static inline int F_215 ( void * V_313 , void * V_314 )
{
struct V_61 * V_308 = V_313 ;
struct V_61 * V_310 = V_314 ;
return F_213 ( V_308 , & V_310 -> V_312 , V_310 ) ;
}
int F_216 ( struct V_315 * V_316 )
{
int V_210 , V_13 ;
struct V_300 V_301 ;
struct V_61 * V_304 , * V_317 ;
struct V_61 * V_318 = NULL ;
struct V_319 V_320 ;
struct V_319 * V_321 ;
struct V_309 V_322 = { 0 , 0 } ;
if ( V_316 -> V_321 ) {
V_321 = V_316 -> V_321 ;
V_321 -> V_323 = & F_215 ;
} else {
V_321 = & V_320 ;
V_210 = F_217 ( V_321 , V_324 , V_53 , & F_215 ) ;
if ( V_210 )
return V_210 ;
}
V_325:
V_321 -> V_326 = 0 ;
F_210 ( V_316 -> V_20 , & V_301 ) ;
while ( ( V_304 = F_211 ( V_316 -> V_20 , & V_301 ) ) ) {
if ( V_316 -> V_327 && ! V_316 -> V_327 ( V_304 , V_316 ) )
continue;
if ( ! F_213 ( V_304 , & V_322 , V_318 ) )
continue;
V_317 = F_218 ( V_321 , V_304 ) ;
if ( V_317 == NULL ) {
F_160 ( V_304 ) ;
} else if ( V_317 != V_304 ) {
F_160 ( V_304 ) ;
F_164 ( V_317 ) ;
}
}
F_212 ( V_316 -> V_20 , & V_301 ) ;
if ( V_321 -> V_326 ) {
for ( V_13 = 0 ; V_13 < V_321 -> V_326 ; V_13 ++ ) {
struct V_61 * V_328 = V_321 -> V_329 [ V_13 ] ;
if ( V_13 == 0 ) {
V_322 = V_328 -> V_312 ;
V_318 = V_328 ;
}
V_316 -> V_330 ( V_328 , V_316 ) ;
F_164 ( V_328 ) ;
}
goto V_325;
}
if ( V_321 == & V_320 )
F_219 ( & V_320 ) ;
return 0 ;
}
static void * F_220 ( int V_31 )
{
if ( F_221 ( V_31 ) )
return F_222 ( V_31 * sizeof( V_331 ) ) ;
else
return F_35 ( V_31 * sizeof( V_331 ) , V_53 ) ;
}
static void F_223 ( void * V_304 )
{
if ( F_224 ( V_304 ) )
F_225 ( V_304 ) ;
else
F_21 ( V_304 ) ;
}
static void * F_226 ( void * V_304 , int V_332 )
{
void * V_333 ;
if ( F_224 ( V_304 ) ) {
V_333 = F_222 ( V_332 * sizeof( V_331 ) ) ;
if ( ! V_333 )
return NULL ;
memcpy ( V_333 , V_304 , V_332 * sizeof( V_331 ) ) ;
F_225 ( V_304 ) ;
} else {
V_333 = F_227 ( V_304 , V_332 * sizeof( V_331 ) , V_53 ) ;
}
return V_333 ;
}
static int F_228 ( V_331 * * V_304 , int V_334 )
{
int V_335 , V_336 = 1 ;
V_331 * V_337 = * V_304 ;
V_331 * V_333 ;
if ( V_334 == 0 || V_334 == 1 )
return V_334 ;
for ( V_335 = 1 ; V_335 < V_334 ; V_335 ++ ) {
while ( V_337 [ V_335 ] == V_337 [ V_335 - 1 ] ) {
V_335 ++ ;
if ( V_335 == V_334 )
goto V_338;
}
V_337 [ V_336 ] = V_337 [ V_335 ] ;
V_336 ++ ;
}
V_338:
if ( F_229 ( V_334 , V_336 ) ) {
V_333 = F_226 ( V_337 , V_336 ) ;
if ( V_333 )
* V_304 = V_333 ;
}
return V_336 ;
}
static int F_230 ( const void * V_339 , const void * V_340 )
{
return * ( V_331 * ) V_339 - * ( V_331 * ) V_340 ;
}
static struct V_341 * F_231 ( struct V_2 * V_3 ,
enum V_342 type )
{
struct V_341 * V_302 ;
struct V_343 * V_344 = V_236 -> V_345 -> V_346 ;
F_51 ( & V_3 -> V_145 ) ;
F_47 (l, &cgrp->pidlists, links) {
if ( V_302 -> V_266 . type == type && V_302 -> V_266 . V_344 == V_344 ) {
F_232 ( & V_302 -> V_347 ) ;
F_53 ( & V_3 -> V_145 ) ;
return V_302 ;
}
}
V_302 = F_35 ( sizeof( struct V_341 ) , V_53 ) ;
if ( ! V_302 ) {
F_53 ( & V_3 -> V_145 ) ;
return V_302 ;
}
F_233 ( & V_302 -> V_347 ) ;
F_232 ( & V_302 -> V_347 ) ;
V_302 -> V_266 . type = type ;
V_302 -> V_266 . V_344 = F_234 ( V_344 ) ;
V_302 -> V_348 = 0 ;
V_302 -> V_337 = NULL ;
V_302 -> V_349 = V_3 ;
F_36 ( & V_302 -> V_350 , & V_3 -> V_89 ) ;
F_53 ( & V_3 -> V_145 ) ;
return V_302 ;
}
static int F_235 ( struct V_2 * V_3 , enum V_342 type ,
struct V_341 * * V_351 )
{
V_331 * V_352 ;
int V_334 ;
int V_226 , V_353 = 0 ;
struct V_300 V_301 ;
struct V_61 * V_206 ;
struct V_341 * V_302 ;
V_334 = F_204 ( V_3 ) ;
V_352 = F_220 ( V_334 ) ;
if ( ! V_352 )
return - V_54 ;
F_210 ( V_3 , & V_301 ) ;
while ( ( V_206 = F_211 ( V_3 , & V_301 ) ) ) {
if ( F_81 ( V_353 == V_334 ) )
break;
if ( type == V_354 )
V_226 = F_236 ( V_206 ) ;
else
V_226 = F_237 ( V_206 ) ;
if ( V_226 > 0 )
V_352 [ V_353 ++ ] = V_226 ;
}
F_212 ( V_3 , & V_301 ) ;
V_334 = V_353 ;
F_238 ( V_352 , V_334 , sizeof( V_331 ) , F_230 , NULL ) ;
if ( type == V_354 )
V_334 = F_228 ( & V_352 , V_334 ) ;
V_302 = F_231 ( V_3 , type ) ;
if ( ! V_302 ) {
F_223 ( V_352 ) ;
return - V_54 ;
}
F_223 ( V_302 -> V_337 ) ;
V_302 -> V_337 = V_352 ;
V_302 -> V_334 = V_334 ;
V_302 -> V_348 ++ ;
F_239 ( & V_302 -> V_347 ) ;
* V_351 = V_302 ;
return 0 ;
}
int F_240 ( struct V_355 * V_356 , struct V_85 * V_85 )
{
int V_83 = - V_134 ;
struct V_2 * V_3 ;
struct V_300 V_301 ;
struct V_61 * V_206 ;
if ( V_85 -> V_119 -> V_162 != & V_163 ||
! F_62 ( V_85 -> V_93 -> V_71 ) )
goto V_277;
V_83 = 0 ;
V_3 = V_85 -> V_86 ;
F_210 ( V_3 , & V_301 ) ;
while ( ( V_206 = F_211 ( V_3 , & V_301 ) ) ) {
switch ( V_206 -> V_269 ) {
case V_357 :
V_356 -> V_358 ++ ;
break;
case V_359 :
V_356 -> V_360 ++ ;
break;
case V_361 :
V_356 -> V_362 ++ ;
break;
case V_363 :
V_356 -> V_364 ++ ;
break;
default:
if ( F_241 ( V_206 ) )
V_356 -> V_365 ++ ;
break;
}
}
F_212 ( V_3 , & V_301 ) ;
V_277:
return V_83 ;
}
static void * F_242 ( struct V_117 * V_366 , T_6 * V_367 )
{
struct V_341 * V_302 = V_366 -> V_260 ;
int V_14 = 0 , V_226 = * V_367 ;
int * V_368 ;
F_243 ( & V_302 -> V_347 ) ;
if ( V_226 ) {
int V_246 = V_302 -> V_334 ;
while ( V_14 < V_246 ) {
int V_369 = ( V_14 + V_246 ) / 2 ;
if ( V_302 -> V_337 [ V_369 ] == V_226 ) {
V_14 = V_369 ;
break;
} else if ( V_302 -> V_337 [ V_369 ] <= V_226 )
V_14 = V_369 + 1 ;
else
V_246 = V_369 ;
}
}
if ( V_14 >= V_302 -> V_334 )
return NULL ;
V_368 = V_302 -> V_337 + V_14 ;
* V_367 = * V_368 ;
return V_368 ;
}
static void F_244 ( struct V_117 * V_366 , void * V_370 )
{
struct V_341 * V_302 = V_366 -> V_260 ;
F_245 ( & V_302 -> V_347 ) ;
}
static void * F_246 ( struct V_117 * V_366 , void * V_370 , T_6 * V_367 )
{
struct V_341 * V_302 = V_366 -> V_260 ;
V_331 * V_304 = V_370 ;
V_331 * V_246 = V_302 -> V_337 + V_302 -> V_334 ;
V_304 ++ ;
if ( V_304 >= V_246 ) {
return NULL ;
} else {
* V_367 = * V_304 ;
return V_304 ;
}
}
static int F_247 ( struct V_117 * V_366 , void * V_370 )
{
return F_93 ( V_366 , L_18 , * ( int * ) V_370 ) ;
}
static void F_248 ( struct V_341 * V_302 )
{
F_51 ( & V_302 -> V_349 -> V_145 ) ;
F_232 ( & V_302 -> V_347 ) ;
F_28 ( ! V_302 -> V_348 ) ;
if ( ! -- V_302 -> V_348 ) {
F_18 ( & V_302 -> V_350 ) ;
F_53 ( & V_302 -> V_349 -> V_145 ) ;
F_223 ( V_302 -> V_337 ) ;
F_249 ( V_302 -> V_266 . V_344 ) ;
F_239 ( & V_302 -> V_347 ) ;
F_21 ( V_302 ) ;
return;
}
F_53 ( & V_302 -> V_349 -> V_145 ) ;
F_239 ( & V_302 -> V_347 ) ;
}
static int F_250 ( struct V_66 * V_66 , struct V_241 * V_241 )
{
struct V_341 * V_302 ;
if ( ! ( V_241 -> V_371 & V_372 ) )
return 0 ;
V_302 = ( (struct V_117 * ) V_241 -> V_276 ) -> V_260 ;
F_248 ( V_302 ) ;
return F_251 ( V_66 , V_241 ) ;
}
static int F_252 ( struct V_241 * V_241 , enum V_342 type )
{
struct V_2 * V_3 = F_132 ( V_241 -> V_257 -> V_92 ) ;
struct V_341 * V_302 ;
int V_210 ;
if ( ! ( V_241 -> V_371 & V_372 ) )
return 0 ;
V_210 = F_235 ( V_3 , type , & V_302 ) ;
if ( V_210 )
return V_210 ;
V_241 -> V_279 = & V_373 ;
V_210 = F_253 ( V_241 , & V_374 ) ;
if ( V_210 ) {
F_248 ( V_302 ) ;
return V_210 ;
}
( (struct V_117 * ) V_241 -> V_276 ) -> V_260 = V_302 ;
return 0 ;
}
static int F_254 ( struct V_66 * V_375 , struct V_241 * V_241 )
{
return F_252 ( V_241 , V_376 ) ;
}
static int F_255 ( struct V_66 * V_375 , struct V_241 * V_241 )
{
return F_252 ( V_241 , V_354 ) ;
}
static T_2 F_256 ( struct V_2 * V_3 ,
struct V_189 * V_238 )
{
return F_7 ( V_3 ) ;
}
static int F_257 ( struct V_2 * V_3 ,
struct V_189 * V_238 ,
T_2 V_250 )
{
F_258 ( V_7 , & V_3 -> V_5 ) ;
if ( V_250 )
F_19 ( V_8 , & V_3 -> V_5 ) ;
else
F_258 ( V_8 , & V_3 -> V_5 ) ;
return 0 ;
}
static void F_259 ( struct V_377 * V_378 )
{
struct V_379 * V_380 = F_260 ( V_378 , struct V_379 ,
remove ) ;
struct V_2 * V_3 = V_380 -> V_3 ;
V_380 -> V_238 -> V_381 ( V_3 , V_380 -> V_238 , V_380 -> V_382 ) ;
F_261 ( V_380 -> V_382 ) ;
F_21 ( V_380 ) ;
F_71 ( V_3 -> V_85 ) ;
}
static int F_262 ( T_8 * V_383 , unsigned V_67 ,
int V_384 , void * V_266 )
{
struct V_379 * V_380 = F_260 ( V_383 ,
struct V_379 , V_383 ) ;
struct V_2 * V_3 = V_380 -> V_3 ;
unsigned long V_5 = ( unsigned long ) V_266 ;
if ( V_5 & V_385 ) {
F_263 ( V_380 -> V_386 , & V_380 -> V_383 ) ;
F_73 ( & V_3 -> V_147 ) ;
F_18 ( & V_380 -> V_337 ) ;
F_77 ( & V_3 -> V_147 ) ;
F_264 ( & V_380 -> remove ) ;
}
return 0 ;
}
static void F_265 ( struct V_241 * V_241 ,
T_9 * V_386 , T_10 * V_387 )
{
struct V_379 * V_380 = F_260 ( V_387 ,
struct V_379 , V_387 ) ;
V_380 -> V_386 = V_386 ;
F_266 ( V_386 , & V_380 -> V_383 ) ;
}
static int F_267 ( struct V_2 * V_3 , struct V_189 * V_238 ,
const char * V_240 )
{
struct V_379 * V_380 = NULL ;
unsigned int V_388 , V_389 ;
struct V_241 * V_390 = NULL ;
struct V_241 * V_391 = NULL ;
char * V_392 ;
int V_83 ;
V_388 = F_268 ( V_240 , & V_392 , 10 ) ;
if ( * V_392 != ' ' )
return - V_134 ;
V_240 = V_392 + 1 ;
V_389 = F_268 ( V_240 , & V_392 , 10 ) ;
if ( ( * V_392 != ' ' ) && ( * V_392 != '\0' ) )
return - V_134 ;
V_240 = V_392 + 1 ;
V_380 = F_113 ( sizeof( * V_380 ) , V_53 ) ;
if ( ! V_380 )
return - V_54 ;
V_380 -> V_3 = V_3 ;
F_34 ( & V_380 -> V_337 ) ;
F_269 ( & V_380 -> V_387 , F_265 ) ;
F_270 ( & V_380 -> V_383 , F_262 ) ;
F_271 ( & V_380 -> remove , F_259 ) ;
V_390 = F_272 ( V_388 ) ;
if ( F_123 ( V_390 ) ) {
V_83 = F_124 ( V_390 ) ;
goto V_393;
}
V_380 -> V_382 = F_273 ( V_390 ) ;
if ( F_123 ( V_380 -> V_382 ) ) {
V_83 = F_124 ( V_380 -> V_382 ) ;
goto V_393;
}
V_391 = F_274 ( V_389 ) ;
if ( ! V_391 ) {
V_83 = - V_394 ;
goto V_393;
}
V_83 = F_275 ( V_391 -> V_395 . V_85 -> V_93 , V_396 ) ;
if ( V_83 < 0 )
goto V_393;
V_380 -> V_238 = F_194 ( V_391 ) ;
if ( F_123 ( V_380 -> V_238 ) ) {
V_83 = F_124 ( V_380 -> V_238 ) ;
goto V_393;
}
if ( ! V_380 -> V_238 -> V_397 || ! V_380 -> V_238 -> V_381 ) {
V_83 = - V_134 ;
goto V_393;
}
V_83 = V_380 -> V_238 -> V_397 ( V_3 , V_380 -> V_238 ,
V_380 -> V_382 , V_240 ) ;
if ( V_83 )
goto V_393;
if ( V_390 -> V_279 -> V_398 ( V_390 , & V_380 -> V_387 ) & V_385 ) {
V_380 -> V_238 -> V_381 ( V_3 , V_380 -> V_238 , V_380 -> V_382 ) ;
V_83 = 0 ;
goto V_393;
}
F_68 ( V_3 -> V_85 ) ;
F_73 ( & V_3 -> V_147 ) ;
F_36 ( & V_380 -> V_337 , & V_3 -> V_146 ) ;
F_77 ( & V_3 -> V_147 ) ;
F_276 ( V_391 ) ;
F_276 ( V_390 ) ;
return 0 ;
V_393:
if ( V_391 )
F_276 ( V_391 ) ;
if ( V_380 && V_380 -> V_382 && ! F_123 ( V_380 -> V_382 ) )
F_261 ( V_380 -> V_382 ) ;
if ( ! F_277 ( V_390 ) )
F_276 ( V_390 ) ;
F_21 ( V_380 ) ;
return V_83 ;
}
static T_2 F_278 ( struct V_2 * V_3 ,
struct V_189 * V_238 )
{
return F_8 ( V_3 ) ;
}
static int F_279 ( struct V_2 * V_3 ,
struct V_189 * V_238 ,
T_2 V_250 )
{
if ( V_250 )
F_19 ( V_9 , & V_3 -> V_5 ) ;
else
F_258 ( V_9 , & V_3 -> V_5 ) ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 )
{
int V_277 ;
struct V_81 * V_82 ;
F_72 ( V_3 -> V_85 ) ;
V_277 = F_203 ( V_3 , NULL , V_399 , F_280 ( V_399 ) ) ;
if ( V_277 < 0 )
return V_277 ;
if ( V_3 == V_3 -> V_65 ) {
if ( ( V_277 = F_201 ( V_3 , NULL , & V_400 ) ) < 0 )
return V_277 ;
}
F_60 (cgrp->root, ss) {
if ( V_82 -> V_401 && ( V_277 = V_82 -> V_401 ( V_82 , V_3 ) ) < 0 )
return V_277 ;
}
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_402 ] ;
if ( V_12 -> V_403 )
F_144 ( V_12 -> V_403 -> V_12 , V_12 ) ;
}
return 0 ;
}
static void F_281 ( struct V_11 * V_12 ,
struct V_81 * V_82 ,
struct V_2 * V_3 )
{
V_12 -> V_2 = V_3 ;
F_45 ( & V_12 -> V_404 , 1 ) ;
V_12 -> V_5 = 0 ;
V_12 -> V_403 = NULL ;
if ( V_3 == V_111 )
F_19 ( V_405 , & V_12 -> V_5 ) ;
F_28 ( V_3 -> V_39 [ V_82 -> V_402 ] ) ;
V_3 -> V_39 [ V_82 -> V_402 ] = V_12 ;
}
static void F_282 ( struct V_48 * V_46 )
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
static void F_283 ( struct V_48 * V_46 )
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
static long F_284 ( struct V_2 * V_91 , struct V_85 * V_85 ,
T_1 V_67 )
{
struct V_2 * V_3 ;
struct V_48 * V_46 = V_91 -> V_46 ;
int V_277 = 0 ;
struct V_81 * V_82 ;
struct V_68 * V_69 = V_46 -> V_69 ;
V_3 = F_113 ( sizeof( * V_3 ) , V_53 ) ;
if ( ! V_3 )
return - V_54 ;
F_24 ( & V_69 -> V_406 ) ;
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
struct V_11 * V_12 = V_82 -> V_407 ( V_3 ) ;
if ( F_123 ( V_12 ) ) {
V_277 = F_124 ( V_12 ) ;
goto V_408;
}
F_281 ( V_12 , V_82 , V_3 ) ;
if ( V_82 -> V_409 ) {
V_277 = F_285 ( V_82 , V_91 , V_3 ) ;
if ( V_277 )
goto V_408;
}
if ( F_8 ( V_91 ) && V_82 -> V_410 )
V_82 -> V_410 ( V_3 ) ;
}
F_282 ( V_46 ) ;
F_36 ( & V_3 -> V_113 , & V_3 -> V_91 -> V_143 ) ;
F_283 ( V_46 ) ;
V_46 -> V_88 ++ ;
V_277 = F_199 ( V_3 , V_85 , V_67 ) ;
if ( V_277 < 0 )
goto V_411;
F_28 ( ! F_3 ( & V_3 -> V_85 -> V_93 -> V_94 ) ) ;
V_277 = F_102 ( V_3 ) ;
F_53 ( & V_1 ) ;
F_53 ( & V_3 -> V_85 -> V_93 -> V_94 ) ;
return 0 ;
V_411:
F_282 ( V_46 ) ;
F_18 ( & V_3 -> V_113 ) ;
F_283 ( V_46 ) ;
V_46 -> V_88 -- ;
V_408:
F_60 (root, ss) {
if ( V_3 -> V_39 [ V_82 -> V_402 ] )
V_82 -> V_87 ( V_3 ) ;
}
F_53 ( & V_1 ) ;
F_64 ( V_69 ) ;
F_21 ( V_3 ) ;
return V_277 ;
}
static int F_286 ( struct V_66 * V_290 , struct V_85 * V_85 , T_1 V_67 )
{
struct V_2 * V_412 = V_85 -> V_92 -> V_86 ;
return F_284 ( V_412 , V_85 , V_67 | V_100 ) ;
}
static int F_287 ( struct V_2 * V_3 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
struct V_11 * V_12 ;
if ( V_82 == NULL || V_82 -> V_46 != V_3 -> V_46 )
continue;
V_12 = V_3 -> V_39 [ V_82 -> V_402 ] ;
if ( V_12 && ( F_205 ( & V_12 -> V_404 ) > 1 ) )
return 1 ;
}
return 0 ;
}
static int F_288 ( struct V_2 * V_3 )
{
struct V_81 * V_82 ;
unsigned long V_5 ;
bool V_413 = false ;
F_289 ( V_5 ) ;
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_402 ] ;
int V_404 ;
while ( 1 ) {
V_404 = F_205 ( & V_12 -> V_404 ) ;
if ( V_404 > 1 ) {
V_413 = true ;
goto V_414;
}
F_28 ( ! V_404 ) ;
if ( F_290 ( & V_12 -> V_404 , V_404 , 0 ) == V_404 )
break;
F_291 () ;
}
}
V_414:
F_60 (cgrp->root, ss) {
struct V_11 * V_12 = V_3 -> V_39 [ V_82 -> V_402 ] ;
if ( V_413 ) {
if ( ! F_205 ( & V_12 -> V_404 ) )
F_45 ( & V_12 -> V_404 , 1 ) ;
} else {
F_19 ( V_415 , & V_12 -> V_5 ) ;
}
}
F_292 ( V_5 ) ;
return ! V_413 ;
}
static int F_293 ( struct V_66 * V_416 , struct V_85 * V_85 )
{
struct V_2 * V_3 = V_85 -> V_86 ;
struct V_85 * V_90 ;
struct V_2 * V_91 ;
F_294 ( V_383 ) ;
struct V_379 * V_380 , * V_15 ;
int V_83 ;
V_325:
F_51 ( & V_1 ) ;
if ( F_205 ( & V_3 -> V_31 ) != 0 ) {
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
F_258 ( V_101 , & V_3 -> V_5 ) ;
return V_83 ;
}
F_51 ( & V_1 ) ;
V_91 = V_3 -> V_91 ;
if ( F_205 ( & V_3 -> V_31 ) || ! F_38 ( & V_3 -> V_143 ) ) {
F_258 ( V_101 , & V_3 -> V_5 ) ;
F_53 ( & V_1 ) ;
return - V_110 ;
}
F_295 ( & V_102 , & V_383 , V_359 ) ;
if ( ! F_288 ( V_3 ) ) {
F_53 ( & V_1 ) ;
if ( F_5 ( V_101 , & V_3 -> V_5 ) )
F_296 () ;
F_297 ( & V_102 , & V_383 ) ;
F_258 ( V_101 , & V_3 -> V_5 ) ;
if ( F_298 ( V_236 ) )
return - V_417 ;
goto V_325;
}
F_297 ( & V_102 , & V_383 ) ;
F_258 ( V_101 , & V_3 -> V_5 ) ;
F_299 ( & V_418 ) ;
F_19 ( V_4 , & V_3 -> V_5 ) ;
if ( ! F_38 ( & V_3 -> V_144 ) )
F_75 ( & V_3 -> V_144 ) ;
F_300 ( & V_418 ) ;
F_282 ( V_3 -> V_46 ) ;
F_75 ( & V_3 -> V_113 ) ;
F_283 ( V_3 -> V_46 ) ;
V_90 = F_68 ( V_3 -> V_85 ) ;
F_79 ( V_90 ) ;
F_71 ( V_90 ) ;
F_19 ( V_7 , & V_91 -> V_5 ) ;
F_20 ( V_91 ) ;
F_73 ( & V_3 -> V_147 ) ;
F_17 (event, tmp, &cgrp->event_list, list) {
F_18 ( & V_380 -> V_337 ) ;
F_301 ( V_380 -> V_386 , & V_380 -> V_383 ) ;
F_302 ( V_380 -> V_382 , 1 ) ;
F_264 ( & V_380 -> remove ) ;
}
F_77 ( & V_3 -> V_147 ) ;
F_53 ( & V_1 ) ;
return 0 ;
}
static void T_11 F_303 ( struct V_81 * V_82 )
{
struct V_11 * V_12 ;
F_304 ( V_419 L_19 , V_82 -> V_121 ) ;
F_36 ( & V_82 -> V_113 , & V_109 . V_114 ) ;
V_82 -> V_46 = & V_109 ;
V_12 = V_82 -> V_407 ( V_111 ) ;
F_28 ( F_123 ( V_12 ) ) ;
F_281 ( V_12 , V_82 , V_111 ) ;
V_64 . V_39 [ V_82 -> V_402 ] = V_111 -> V_39 [ V_82 -> V_402 ] ;
V_420 |= V_82 -> V_421 || V_82 -> exit ;
F_28 ( ! F_38 ( & V_422 . V_59 ) ) ;
F_104 ( & V_82 -> V_112 ) ;
F_305 ( & V_82 -> V_112 , & V_82 -> V_423 ) ;
V_82 -> V_424 = 1 ;
F_28 ( V_82 -> V_116 ) ;
}
int T_12 F_306 ( struct V_81 * V_82 )
{
int V_13 ;
struct V_11 * V_12 ;
if ( V_82 -> V_121 == NULL || strlen ( V_82 -> V_121 ) > V_297 ||
V_82 -> V_407 == NULL || V_82 -> V_87 == NULL )
return - V_134 ;
if ( V_82 -> V_421 || V_82 -> exit )
return - V_134 ;
if ( V_82 -> V_116 == NULL ) {
F_28 ( V_82 -> V_402 >= V_141 ) ;
F_28 ( V_39 [ V_82 -> V_402 ] != V_82 ) ;
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
V_82 -> V_402 = V_13 ;
V_39 [ V_13 ] = V_82 ;
V_12 = V_82 -> V_407 ( V_111 ) ;
if ( F_123 ( V_12 ) ) {
V_39 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
return F_124 ( V_12 ) ;
}
F_36 ( & V_82 -> V_113 , & V_109 . V_114 ) ;
V_82 -> V_46 = & V_109 ;
F_281 ( V_12 , V_82 , V_111 ) ;
if ( V_82 -> V_409 ) {
int V_83 = F_307 ( V_82 , V_12 ) ;
if ( V_83 ) {
V_111 -> V_39 [ V_82 -> V_402 ] = NULL ;
V_82 -> V_87 ( V_111 ) ;
V_39 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
return V_83 ;
}
}
F_13 ( & V_26 ) ;
for ( V_13 = 0 ; V_13 < V_187 ; V_13 ++ ) {
struct V_19 * V_20 ;
struct V_50 * V_51 , * V_15 ;
struct V_10 * V_425 = & V_18 [ V_13 ] , * V_426 ;
F_308 (cg, node, tmp, bucket, hlist) {
if ( V_20 -> V_39 [ V_82 -> V_402 ] )
continue;
F_16 ( & V_20 -> V_27 ) ;
V_20 -> V_39 [ V_82 -> V_402 ] = V_12 ;
V_426 = F_9 ( V_20 -> V_39 ) ;
F_48 ( & V_20 -> V_27 , V_426 ) ;
}
}
F_15 ( & V_26 ) ;
F_104 ( & V_82 -> V_112 ) ;
F_305 ( & V_82 -> V_112 , & V_82 -> V_423 ) ;
V_82 -> V_424 = 1 ;
F_53 ( & V_1 ) ;
return 0 ;
}
void F_309 ( struct V_81 * V_82 )
{
struct V_22 * V_23 ;
struct V_10 * V_49 ;
F_28 ( V_82 -> V_116 == NULL ) ;
F_28 ( V_82 -> V_46 != & V_109 ) ;
F_51 ( & V_1 ) ;
F_28 ( V_82 -> V_402 < V_141 ) ;
V_39 [ V_82 -> V_402 ] = NULL ;
F_75 ( & V_82 -> V_113 ) ;
F_13 ( & V_26 ) ;
F_47 (link, &dummytop->css_sets, cgrp_link_list) {
struct V_19 * V_20 = V_23 -> V_20 ;
F_16 ( & V_20 -> V_27 ) ;
F_28 ( ! V_20 -> V_39 [ V_82 -> V_402 ] ) ;
V_20 -> V_39 [ V_82 -> V_402 ] = NULL ;
V_49 = F_9 ( V_20 -> V_39 ) ;
F_48 ( & V_20 -> V_27 , V_49 ) ;
}
F_15 ( & V_26 ) ;
V_82 -> V_87 ( V_111 ) ;
V_111 -> V_39 [ V_82 -> V_402 ] = NULL ;
F_53 ( & V_1 ) ;
}
int T_11 F_310 ( void )
{
int V_13 ;
F_45 ( & V_64 . V_25 , 1 ) ;
F_34 ( & V_64 . V_40 ) ;
F_34 ( & V_64 . V_59 ) ;
F_46 ( & V_64 . V_27 ) ;
V_28 = 1 ;
F_106 ( & V_109 ) ;
V_58 = 1 ;
V_422 . V_63 = & V_64 ;
V_427 . V_20 = & V_64 ;
V_427 . V_3 = V_111 ;
F_36 ( & V_427 . V_30 ,
& V_109 . V_65 . V_56 ) ;
F_36 ( & V_427 . V_29 ,
& V_64 . V_40 ) ;
for ( V_13 = 0 ; V_13 < V_187 ; V_13 ++ )
F_311 ( & V_18 [ V_13 ] ) ;
for ( V_13 = 0 ; V_13 < V_141 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
F_28 ( ! V_82 -> V_121 ) ;
F_28 ( strlen ( V_82 -> V_121 ) > V_297 ) ;
F_28 ( ! V_82 -> V_407 ) ;
F_28 ( ! V_82 -> V_87 ) ;
if ( V_82 -> V_402 != V_13 ) {
F_304 ( V_428 L_20 ,
V_82 -> V_121 , V_82 -> V_402 ) ;
F_312 () ;
}
if ( V_82 -> V_429 )
F_303 ( V_82 ) ;
}
return 0 ;
}
int T_11 F_313 ( void )
{
int V_277 ;
int V_13 ;
struct V_10 * V_49 ;
V_277 = F_314 ( & V_80 ) ;
if ( V_277 )
return V_277 ;
for ( V_13 = 0 ; V_13 < V_141 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( ! V_82 -> V_429 )
F_303 ( V_82 ) ;
if ( V_82 -> V_409 )
F_307 ( V_82 , V_64 . V_39 [ V_82 -> V_402 ] ) ;
}
V_49 = F_9 ( V_64 . V_39 ) ;
F_48 ( & V_64 . V_27 , V_49 ) ;
F_28 ( ! F_107 ( & V_109 ) ) ;
V_430 = F_315 ( L_21 , V_431 ) ;
if ( ! V_430 ) {
V_277 = - V_54 ;
goto V_214;
}
V_277 = F_316 ( & V_432 ) ;
if ( V_277 < 0 ) {
F_317 ( V_430 ) ;
goto V_214;
}
F_318 ( L_22 , 0 , NULL , & V_433 ) ;
V_214:
if ( V_277 )
F_319 ( & V_80 ) ;
return V_277 ;
}
static int F_320 ( struct V_117 * V_270 , void * V_370 )
{
struct V_226 * V_226 ;
struct V_61 * V_206 ;
char * V_190 ;
int V_210 ;
struct V_48 * V_46 ;
V_210 = - V_54 ;
V_190 = F_35 ( V_324 , V_53 ) ;
if ( ! V_190 )
goto V_214;
V_210 = - V_212 ;
V_226 = V_270 -> V_260 ;
V_206 = F_321 ( V_226 , V_434 ) ;
if ( ! V_206 )
goto V_435;
V_210 = 0 ;
F_51 ( & V_1 ) ;
F_126 (root) {
struct V_81 * V_82 ;
struct V_2 * V_3 ;
int V_31 = 0 ;
F_93 ( V_270 , L_23 , V_46 -> V_152 ) ;
F_60 (root, ss)
F_93 ( V_270 , L_24 , V_31 ++ ? L_6 : L_25 , V_82 -> V_121 ) ;
if ( strlen ( V_46 -> V_121 ) )
F_93 ( V_270 , L_26 , V_31 ? L_6 : L_25 ,
V_46 -> V_121 ) ;
F_170 ( V_270 , ':' ) ;
V_3 = F_49 ( V_206 , V_46 ) ;
V_210 = F_134 ( V_3 , V_190 , V_324 ) ;
if ( V_210 < 0 )
goto V_142;
F_94 ( V_270 , V_190 ) ;
F_170 ( V_270 , '\n' ) ;
}
V_142:
F_53 ( & V_1 ) ;
F_164 ( V_206 ) ;
V_435:
F_21 ( V_190 ) ;
V_214:
return V_210 ;
}
static int F_322 ( struct V_66 * V_66 , struct V_241 * V_241 )
{
struct V_226 * V_226 = F_323 ( V_66 ) -> V_226 ;
return F_188 ( V_241 , F_320 , V_226 ) ;
}
static int F_324 ( struct V_117 * V_270 , void * V_370 )
{
int V_13 ;
F_94 ( V_270 , L_27 ) ;
F_51 ( & V_1 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 == NULL )
continue;
F_93 ( V_270 , L_28 ,
V_82 -> V_121 , V_82 -> V_46 -> V_152 ,
V_82 -> V_46 -> V_88 , ! V_82 -> V_139 ) ;
}
F_53 ( & V_1 ) ;
return 0 ;
}
static int F_325 ( struct V_66 * V_66 , struct V_241 * V_241 )
{
return F_188 ( V_241 , F_324 , NULL ) ;
}
void F_326 ( struct V_61 * V_436 )
{
V_436 -> V_63 = V_236 -> V_63 ;
F_23 ( V_436 -> V_63 ) ;
F_34 ( & V_436 -> V_209 ) ;
}
void F_327 ( struct V_61 * V_436 )
{
if ( V_420 ) {
int V_13 ;
for ( V_13 = 0 ; V_13 < V_141 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 -> V_421 )
V_82 -> V_421 ( V_436 ) ;
}
}
}
void F_328 ( struct V_61 * V_436 )
{
if ( V_306 ) {
F_13 ( & V_26 ) ;
if ( F_38 ( & V_436 -> V_209 ) ) {
F_36 ( & V_436 -> V_209 , & V_436 -> V_63 -> V_59 ) ;
}
F_15 ( & V_26 ) ;
}
}
void F_329 ( struct V_61 * V_206 , int V_437 )
{
struct V_19 * V_20 ;
int V_13 ;
if ( ! F_38 ( & V_206 -> V_209 ) ) {
F_13 ( & V_26 ) ;
if ( ! F_38 ( & V_206 -> V_209 ) )
F_75 ( & V_206 -> V_209 ) ;
F_15 ( & V_26 ) ;
}
F_143 ( V_206 ) ;
V_20 = V_206 -> V_63 ;
V_206 -> V_63 = & V_64 ;
if ( V_437 && V_420 ) {
for ( V_13 = 0 ; V_13 < V_141 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( V_82 -> exit ) {
struct V_2 * V_438 =
F_330 ( V_20 -> V_39 [ V_13 ] ) -> V_2 ;
struct V_2 * V_3 = F_331 ( V_206 , V_13 ) ;
V_82 -> exit ( V_3 , V_438 , V_206 ) ;
}
}
}
F_145 ( V_206 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
}
int F_332 ( const struct V_2 * V_3 , struct V_61 * V_62 )
{
int V_83 ;
struct V_2 * V_439 ;
if ( V_3 == V_111 )
return 1 ;
V_439 = F_49 ( V_62 , V_3 -> V_46 ) ;
while ( V_3 != V_439 && V_3 != V_3 -> V_65 )
V_3 = V_3 -> V_91 ;
V_83 = ( V_3 == V_439 ) ;
return V_83 ;
}
static void F_20 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 ) && ! F_205 ( & V_3 -> V_31 )
&& F_38 ( & V_3 -> V_143 ) && ! F_287 ( V_3 ) ) {
int V_440 = 0 ;
F_299 ( & V_418 ) ;
if ( ! F_4 ( V_3 ) &&
F_38 ( & V_3 -> V_144 ) ) {
F_36 ( & V_3 -> V_144 , & V_144 ) ;
V_440 = 1 ;
}
F_300 ( & V_418 ) ;
if ( V_440 )
F_264 ( & V_441 ) ;
}
}
void F_333 ( struct V_11 * V_12 , int V_31 )
{
struct V_2 * V_3 = V_12 -> V_2 ;
int V_250 ;
F_152 () ;
V_250 = F_334 ( V_31 , & V_12 -> V_404 ) ;
if ( V_250 == 1 ) {
if ( F_7 ( V_3 ) ) {
F_19 ( V_7 , & V_3 -> V_5 ) ;
F_20 ( V_3 ) ;
}
F_80 ( V_3 ) ;
}
F_158 () ;
F_142 ( V_250 < 1 ) ;
}
static void F_335 ( struct V_377 * V_378 )
{
F_28 ( V_378 != & V_441 ) ;
F_51 ( & V_1 ) ;
F_299 ( & V_418 ) ;
while ( ! F_38 ( & V_144 ) ) {
char * V_442 [ 3 ] , * V_443 [ 3 ] ;
int V_13 ;
char * V_444 = NULL , * V_445 = NULL ;
struct V_2 * V_3 = F_29 ( V_144 . V_45 ,
struct V_2 ,
V_144 ) ;
F_75 ( & V_3 -> V_144 ) ;
F_300 ( & V_418 ) ;
V_444 = F_35 ( V_324 , V_53 ) ;
if ( ! V_444 )
goto V_446;
if ( F_134 ( V_3 , V_444 , V_324 ) < 0 )
goto V_446;
V_445 = F_336 ( V_3 -> V_46 -> V_123 , V_53 ) ;
if ( ! V_445 )
goto V_446;
V_13 = 0 ;
V_442 [ V_13 ++ ] = V_445 ;
V_442 [ V_13 ++ ] = V_444 ;
V_442 [ V_13 ] = NULL ;
V_13 = 0 ;
V_443 [ V_13 ++ ] = L_29 ;
V_443 [ V_13 ++ ] = L_30 ;
V_443 [ V_13 ] = NULL ;
F_53 ( & V_1 ) ;
F_337 ( V_442 [ 0 ] , V_442 , V_443 , V_447 ) ;
F_51 ( & V_1 ) ;
V_446:
F_21 ( V_444 ) ;
F_21 ( V_445 ) ;
F_299 ( & V_418 ) ;
}
F_300 ( & V_418 ) ;
F_53 ( & V_1 ) ;
}
static int T_11 F_338 ( char * V_448 )
{
int V_13 ;
char * V_127 ;
while ( ( V_127 = F_97 ( & V_448 , L_6 ) ) != NULL ) {
if ( ! * V_127 )
continue;
for ( V_13 = 0 ; V_13 < V_141 ; V_13 ++ ) {
struct V_81 * V_82 = V_39 [ V_13 ] ;
if ( ! strcmp ( V_127 , V_82 -> V_121 ) ) {
V_82 -> V_139 = 1 ;
F_304 ( V_419 L_31
L_32 , V_82 -> V_121 ) ;
break;
}
}
}
return 1 ;
}
unsigned short F_339 ( struct V_11 * V_12 )
{
struct F_339 * V_449 ;
V_449 = F_135 ( V_12 -> V_403 , F_205 ( & V_12 -> V_404 ) ) ;
if ( V_449 )
return V_449 -> V_403 ;
return 0 ;
}
unsigned short F_340 ( struct V_11 * V_12 )
{
struct F_339 * V_449 ;
V_449 = F_135 ( V_12 -> V_403 , F_205 ( & V_12 -> V_404 ) ) ;
if ( V_449 )
return V_449 -> V_450 ;
return 0 ;
}
bool F_341 ( struct V_11 * V_436 ,
const struct V_11 * V_46 )
{
struct F_339 * V_451 ;
struct F_339 * V_452 ;
bool V_83 = true ;
F_152 () ;
V_451 = F_342 ( V_436 -> V_403 ) ;
V_452 = F_342 ( V_46 -> V_403 ) ;
if ( ! V_451
|| ! V_452
|| ( V_451 -> V_450 < V_452 -> V_450 )
|| ( V_451 -> V_453 [ V_452 -> V_450 ] != V_452 -> V_403 ) )
V_83 = false ;
F_158 () ;
return V_83 ;
}
void F_343 ( struct V_81 * V_82 , struct V_11 * V_12 )
{
struct F_339 * V_403 = V_12 -> V_403 ;
if ( ! V_403 )
return;
F_28 ( ! V_82 -> V_409 ) ;
F_144 ( V_403 -> V_12 , NULL ) ;
F_144 ( V_12 -> V_403 , NULL ) ;
F_73 ( & V_82 -> V_454 ) ;
F_344 ( & V_82 -> V_455 , V_403 -> V_403 ) ;
F_77 ( & V_82 -> V_454 ) ;
F_22 ( V_403 , V_32 ) ;
}
static struct F_339 * F_345 ( struct V_81 * V_82 , int V_450 )
{
struct F_339 * V_456 ;
int V_457 , error , V_326 ;
F_28 ( ! V_82 -> V_409 ) ;
V_326 = sizeof( * V_456 ) + sizeof( unsigned short ) * ( V_450 + 1 ) ;
V_456 = F_113 ( V_326 , V_53 ) ;
if ( ! V_456 )
return F_114 ( - V_54 ) ;
if ( F_81 ( ! F_346 ( & V_82 -> V_455 , V_53 ) ) ) {
error = - V_54 ;
goto V_458;
}
F_73 ( & V_82 -> V_454 ) ;
error = F_347 ( & V_82 -> V_455 , V_456 , 1 , & V_457 ) ;
F_77 ( & V_82 -> V_454 ) ;
if ( error ) {
error = - V_153 ;
goto V_458;
}
if ( V_457 > V_459 )
goto V_460;
V_456 -> V_403 = V_457 ;
V_456 -> V_450 = V_450 ;
return V_456 ;
V_460:
error = - V_153 ;
F_73 ( & V_82 -> V_454 ) ;
F_344 ( & V_82 -> V_455 , V_457 ) ;
F_77 ( & V_82 -> V_454 ) ;
V_458:
F_21 ( V_456 ) ;
return F_114 ( error ) ;
}
static int T_12 F_307 ( struct V_81 * V_82 ,
struct V_11 * V_461 )
{
struct F_339 * V_456 ;
F_105 ( & V_82 -> V_454 ) ;
F_348 ( & V_82 -> V_455 ) ;
V_456 = F_345 ( V_82 , 0 ) ;
if ( F_123 ( V_456 ) )
return F_124 ( V_456 ) ;
V_456 -> V_453 [ 0 ] = V_456 -> V_403 ;
V_456 -> V_12 = V_461 ;
V_461 -> V_403 = V_456 ;
return 0 ;
}
static int F_285 ( struct V_81 * V_82 , struct V_2 * V_91 ,
struct V_2 * V_436 )
{
int V_402 , V_13 , V_450 = 0 ;
struct V_11 * V_462 , * V_463 ;
struct F_339 * V_451 , * V_464 ;
V_402 = V_82 -> V_402 ;
V_462 = V_91 -> V_39 [ V_402 ] ;
V_463 = V_436 -> V_39 [ V_402 ] ;
V_464 = V_462 -> V_403 ;
V_450 = V_464 -> V_450 + 1 ;
V_451 = F_345 ( V_82 , V_450 ) ;
if ( F_123 ( V_451 ) )
return F_124 ( V_451 ) ;
for ( V_13 = 0 ; V_13 < V_450 ; V_13 ++ )
V_451 -> V_453 [ V_13 ] = V_464 -> V_453 [ V_13 ] ;
V_451 -> V_453 [ V_450 ] = V_451 -> V_403 ;
F_144 ( V_463 -> V_403 , V_451 ) ;
return 0 ;
}
struct V_11 * F_349 ( struct V_81 * V_82 , int V_403 )
{
struct F_339 * V_449 = NULL ;
F_28 ( ! V_82 -> V_409 ) ;
V_449 = F_350 ( & V_82 -> V_455 , V_403 ) ;
if ( F_81 ( ! V_449 ) )
return NULL ;
return F_342 ( V_449 -> V_12 ) ;
}
struct V_11 *
F_351 ( struct V_81 * V_82 , int V_403 ,
struct V_11 * V_46 , int * V_465 )
{
struct V_11 * V_83 = NULL ;
struct F_339 * V_15 ;
int V_466 ;
int V_467 = F_339 ( V_46 ) ;
int V_450 = F_340 ( V_46 ) ;
if ( ! V_467 )
return NULL ;
F_28 ( ! V_82 -> V_409 ) ;
F_142 ( ! F_352 () ) ;
V_466 = V_403 ;
while ( 1 ) {
V_15 = F_353 ( & V_82 -> V_455 , & V_466 ) ;
if ( ! V_15 )
break;
if ( V_15 -> V_450 >= V_450 && V_15 -> V_453 [ V_450 ] == V_467 ) {
V_83 = F_342 ( V_15 -> V_12 ) ;
if ( V_83 ) {
* V_465 = V_466 ;
break;
}
}
V_466 = V_466 + 1 ;
}
return V_83 ;
}
struct V_11 * F_354 ( struct V_241 * V_468 , int V_403 )
{
struct V_2 * V_3 ;
struct V_66 * V_66 ;
struct V_11 * V_12 ;
V_66 = V_468 -> V_257 -> V_93 ;
if ( V_66 -> V_172 != & V_173 )
return F_114 ( - V_394 ) ;
if ( V_403 < 0 || V_403 >= V_16 )
return F_114 ( - V_134 ) ;
V_3 = F_132 ( V_468 -> V_257 ) ;
V_12 = V_3 -> V_39 [ V_403 ] ;
return V_12 ? V_12 : F_114 ( - V_140 ) ;
}
static struct V_11 * F_355 ( struct V_2 * V_469 )
{
struct V_11 * V_12 = F_113 ( sizeof( * V_12 ) , V_53 ) ;
if ( ! V_12 )
return F_114 ( - V_54 ) ;
return V_12 ;
}
static void F_356 ( struct V_2 * V_469 )
{
F_21 ( V_469 -> V_39 [ V_470 ] ) ;
}
static T_2 F_357 ( struct V_2 * V_469 , struct V_189 * V_238 )
{
return F_205 ( & V_469 -> V_31 ) ;
}
static T_2 F_358 ( struct V_2 * V_469 , struct V_189 * V_238 )
{
return F_204 ( V_469 ) ;
}
static T_2 F_359 ( struct V_2 * V_469 , struct V_189 * V_238 )
{
return ( T_2 ) ( unsigned long ) V_236 -> V_63 ;
}
static T_2 F_360 ( struct V_2 * V_469 ,
struct V_189 * V_238 )
{
T_2 V_31 ;
F_152 () ;
V_31 = F_205 ( & V_236 -> V_63 -> V_25 ) ;
F_158 () ;
return V_31 ;
}
static int F_361 ( struct V_2 * V_469 ,
struct V_189 * V_238 ,
struct V_117 * V_118 )
{
struct V_22 * V_23 ;
struct V_19 * V_20 ;
F_43 ( & V_26 ) ;
F_152 () ;
V_20 = F_342 ( V_236 -> V_63 ) ;
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
F_158 () ;
F_44 ( & V_26 ) ;
return 0 ;
}
static int F_362 ( struct V_2 * V_469 ,
struct V_189 * V_238 ,
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
if ( V_31 ++ > V_471 ) {
F_94 ( V_118 , L_36 ) ;
break;
} else {
F_93 ( V_118 , L_37 ,
F_237 ( V_62 ) ) ;
}
}
}
F_44 ( & V_26 ) ;
return 0 ;
}
static T_2 F_363 ( struct V_2 * V_3 , struct V_189 * V_238 )
{
return F_5 ( V_7 , & V_3 -> V_5 ) ;
}
static int F_364 ( struct V_81 * V_82 , struct V_2 * V_469 )
{
return F_203 ( V_469 , V_82 , V_472 ,
F_280 ( V_472 ) ) ;
}
