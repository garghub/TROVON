static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( V_5 )
return F_2 ( V_3 -> V_6 [ V_5 -> V_7 ] ,
F_3 ( & V_8 ) ) ;
else
return & V_3 -> V_9 ;
}
static inline bool F_4 ( const struct V_2 * V_3 )
{
return F_5 ( V_10 , & V_3 -> V_11 ) ;
}
bool F_6 ( struct V_2 * V_3 , struct V_2 * V_12 )
{
while ( V_3 ) {
if ( V_3 == V_12 )
return true ;
V_3 = V_3 -> V_13 ;
}
return false ;
}
static int F_7 ( const struct V_2 * V_3 )
{
const int V_14 =
( 1 << V_15 ) |
( 1 << V_16 ) ;
return ( V_3 -> V_11 & V_14 ) == V_14 ;
}
static int F_8 ( const struct V_2 * V_3 )
{
return F_5 ( V_16 , & V_3 -> V_11 ) ;
}
static inline struct V_2 * F_9 ( struct V_17 * V_17 )
{
return V_17 -> V_18 ;
}
static inline struct V_19 * F_10 ( struct V_17 * V_17 )
{
return V_17 -> V_18 ;
}
static inline struct V_20 * F_11 ( struct V_17 * V_17 )
{
return F_10 ( V_17 ) -> type ;
}
static bool F_12 ( struct V_2 * V_3 )
{
F_13 ( & V_8 ) ;
if ( F_4 ( V_3 ) ) {
F_14 ( & V_8 ) ;
return false ;
}
return true ;
}
static unsigned long F_15 ( struct V_1 * V_21 [] )
{
unsigned long V_22 = 0UL ;
struct V_4 * V_5 ;
int V_23 ;
F_16 (ss, i)
V_22 += ( unsigned long ) V_21 [ V_23 ] ;
V_22 = ( V_22 >> 16 ) ^ V_22 ;
return V_22 ;
}
static void F_17 ( struct V_24 * V_25 , int V_26 )
{
struct V_27 * V_28 , * V_29 ;
if ( F_18 ( & V_25 -> V_30 , - 1 , 1 ) )
return;
F_19 ( & V_31 ) ;
if ( ! F_20 ( & V_25 -> V_30 ) ) {
F_21 ( & V_31 ) ;
return;
}
F_22 ( & V_25 -> V_32 ) ;
V_33 -- ;
F_23 (link, tmp_link, &cset->cgrp_links, cgrp_link) {
struct V_2 * V_3 = V_28 -> V_3 ;
F_24 ( & V_28 -> V_34 ) ;
F_24 ( & V_28 -> V_35 ) ;
if ( F_25 ( & V_3 -> V_36 ) && F_8 ( V_3 ) ) {
if ( V_26 )
F_26 ( V_15 , & V_3 -> V_11 ) ;
F_27 ( V_3 ) ;
}
F_28 ( V_28 ) ;
}
F_21 ( & V_31 ) ;
F_29 ( V_25 , V_37 ) ;
}
static inline void F_30 ( struct V_24 * V_25 )
{
F_31 ( & V_25 -> V_30 ) ;
}
static inline void F_32 ( struct V_24 * V_25 )
{
F_17 ( V_25 , 0 ) ;
}
static inline void F_33 ( struct V_24 * V_25 )
{
F_17 ( V_25 , 1 ) ;
}
static bool F_34 ( struct V_24 * V_25 ,
struct V_24 * V_38 ,
struct V_2 * V_39 ,
struct V_1 * V_40 [] )
{
struct V_41 * V_42 , * V_43 ;
if ( memcmp ( V_40 , V_25 -> V_6 , sizeof( V_25 -> V_6 ) ) ) {
return false ;
}
V_42 = & V_25 -> V_44 ;
V_43 = & V_38 -> V_44 ;
while ( 1 ) {
struct V_27 * V_45 , * V_46 ;
struct V_2 * V_47 , * V_48 ;
V_42 = V_42 -> V_49 ;
V_43 = V_43 -> V_49 ;
if ( V_42 == & V_25 -> V_44 ) {
F_35 ( V_43 != & V_38 -> V_44 ) ;
break;
} else {
F_35 ( V_43 == & V_38 -> V_44 ) ;
}
V_45 = F_36 ( V_42 , struct V_27 , V_35 ) ;
V_46 = F_36 ( V_43 , struct V_27 , V_35 ) ;
V_47 = V_45 -> V_3 ;
V_48 = V_46 -> V_3 ;
F_35 ( V_47 -> V_50 != V_48 -> V_50 ) ;
if ( V_47 -> V_50 == V_39 -> V_50 ) {
if ( V_47 != V_39 )
return false ;
} else {
if ( V_47 != V_48 )
return false ;
}
}
return true ;
}
static struct V_24 * F_37 ( struct V_24 * V_38 ,
struct V_2 * V_3 ,
struct V_1 * V_40 [] )
{
struct V_51 * V_50 = V_3 -> V_50 ;
struct V_4 * V_5 ;
struct V_24 * V_25 ;
unsigned long V_22 ;
int V_23 ;
F_16 (ss, i) {
if ( V_50 -> V_52 & ( 1UL << V_23 ) ) {
V_40 [ V_23 ] = F_1 ( V_3 , V_5 ) ;
} else {
V_40 [ V_23 ] = V_38 -> V_6 [ V_23 ] ;
}
}
V_22 = F_15 ( V_40 ) ;
F_38 (css_set_table, cset, hlist, key) {
if ( ! F_34 ( V_25 , V_38 , V_3 , V_40 ) )
continue;
return V_25 ;
}
return NULL ;
}
static void F_39 ( struct V_41 * V_53 )
{
struct V_27 * V_28 , * V_29 ;
F_23 (link, tmp_link, links_to_free, cset_link) {
F_24 ( & V_28 -> V_34 ) ;
F_28 ( V_28 ) ;
}
}
static int F_40 ( int V_54 , struct V_41 * V_55 )
{
struct V_27 * V_28 ;
int V_23 ;
F_41 ( V_55 ) ;
for ( V_23 = 0 ; V_23 < V_54 ; V_23 ++ ) {
V_28 = F_42 ( sizeof( * V_28 ) , V_56 ) ;
if ( ! V_28 ) {
F_39 ( V_55 ) ;
return - V_57 ;
}
F_43 ( & V_28 -> V_34 , V_55 ) ;
}
return 0 ;
}
static void F_44 ( struct V_41 * V_55 , struct V_24 * V_25 ,
struct V_2 * V_3 )
{
struct V_27 * V_28 ;
F_35 ( F_25 ( V_55 ) ) ;
V_28 = F_45 ( V_55 , struct V_27 , V_34 ) ;
V_28 -> V_25 = V_25 ;
V_28 -> V_3 = V_3 ;
F_46 ( & V_28 -> V_34 , & V_3 -> V_36 ) ;
F_47 ( & V_28 -> V_35 , & V_25 -> V_44 ) ;
}
static struct V_24 * F_48 ( struct V_24 * V_38 ,
struct V_2 * V_3 )
{
struct V_1 * V_40 [ V_58 ] = { } ;
struct V_24 * V_25 ;
struct V_41 V_55 ;
struct V_27 * V_28 ;
unsigned long V_22 ;
F_49 ( & V_8 ) ;
F_50 ( & V_31 ) ;
V_25 = F_37 ( V_38 , V_3 , V_40 ) ;
if ( V_25 )
F_30 ( V_25 ) ;
F_51 ( & V_31 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_42 ( sizeof( * V_25 ) , V_56 ) ;
if ( ! V_25 )
return NULL ;
if ( F_40 ( V_59 , & V_55 ) < 0 ) {
F_28 ( V_25 ) ;
return NULL ;
}
F_52 ( & V_25 -> V_30 , 1 ) ;
F_41 ( & V_25 -> V_44 ) ;
F_41 ( & V_25 -> V_60 ) ;
F_53 ( & V_25 -> V_32 ) ;
memcpy ( V_25 -> V_6 , V_40 , sizeof( V_25 -> V_6 ) ) ;
F_19 ( & V_31 ) ;
F_54 (link, &old_cset->cgrp_links, cgrp_link) {
struct V_2 * V_61 = V_28 -> V_3 ;
if ( V_61 -> V_50 == V_3 -> V_50 )
V_61 = V_3 ;
F_44 ( & V_55 , V_25 , V_61 ) ;
}
F_35 ( ! F_25 ( & V_55 ) ) ;
V_33 ++ ;
V_22 = F_15 ( V_25 -> V_6 ) ;
F_55 ( V_62 , & V_25 -> V_32 , V_22 ) ;
F_21 ( & V_31 ) ;
return V_25 ;
}
static struct V_2 * F_56 ( struct V_63 * V_64 ,
struct V_51 * V_50 )
{
struct V_24 * V_25 ;
struct V_2 * V_65 = NULL ;
F_35 ( ! F_57 ( & V_8 ) ) ;
F_50 ( & V_31 ) ;
V_25 = F_58 ( V_64 ) ;
if ( V_25 == & V_66 ) {
V_65 = & V_50 -> V_67 ;
} else {
struct V_27 * V_28 ;
F_54 (link, &cset->cgrp_links, cgrp_link) {
struct V_2 * V_61 = V_28 -> V_3 ;
if ( V_61 -> V_50 == V_50 ) {
V_65 = V_61 ;
break;
}
}
}
F_51 ( & V_31 ) ;
F_35 ( ! V_65 ) ;
return V_65 ;
}
static struct V_68 * F_59 ( T_1 V_69 , struct V_70 * V_71 )
{
struct V_68 * V_68 = F_60 ( V_71 ) ;
if ( V_68 ) {
V_68 -> V_72 = F_61 () ;
V_68 -> V_73 = V_69 ;
V_68 -> V_74 = F_62 () ;
V_68 -> V_75 = F_63 () ;
V_68 -> V_76 = V_68 -> V_77 = V_68 -> V_78 = V_79 ;
V_68 -> V_80 -> V_81 = & V_82 ;
}
return V_68 ;
}
static struct V_83 * F_64 ( struct V_17 * V_17 )
{
struct V_83 * V_84 ;
V_84 = F_65 ( sizeof( * V_84 ) + V_17 -> V_85 . V_86 + 1 , V_56 ) ;
if ( ! V_84 )
return NULL ;
strcpy ( V_84 -> V_84 , V_17 -> V_85 . V_84 ) ;
return V_84 ;
}
static void F_66 ( struct V_87 * V_88 )
{
struct V_2 * V_3 = F_67 ( V_88 , struct V_2 , V_89 ) ;
F_13 ( & V_8 ) ;
V_3 -> V_50 -> V_90 -- ;
F_14 ( & V_8 ) ;
F_68 ( V_3 -> V_13 -> V_17 ) ;
F_69 ( V_3 -> V_50 -> V_71 ) ;
F_70 ( V_3 ) ;
F_71 ( & V_3 -> V_91 ) ;
F_28 ( F_72 ( V_3 -> V_84 ) ) ;
F_28 ( V_3 ) ;
}
static void F_73 ( struct V_37 * V_92 )
{
struct V_2 * V_3 = F_67 ( V_92 , struct V_2 , V_37 ) ;
F_74 ( & V_3 -> V_89 , F_66 ) ;
F_75 ( V_93 , & V_3 -> V_89 ) ;
}
static void F_76 ( struct V_17 * V_17 , struct V_68 * V_68 )
{
if ( F_77 ( V_68 -> V_73 ) ) {
struct V_2 * V_3 = V_17 -> V_18 ;
F_35 ( ! ( F_4 ( V_3 ) ) ) ;
F_13 ( & V_8 ) ;
F_78 ( & V_3 -> V_50 -> V_94 , V_3 -> V_95 ) ;
F_14 ( & V_8 ) ;
V_3 -> V_95 = - 1 ;
F_79 ( & V_3 -> V_37 , F_73 ) ;
} else {
struct V_19 * V_96 = F_10 ( V_17 ) ;
struct V_2 * V_3 = V_17 -> V_97 -> V_18 ;
F_80 ( ! F_25 ( & V_96 -> V_98 ) &&
V_3 != & V_3 -> V_50 -> V_67 ,
L_1 , V_96 -> type -> V_84 ) ;
F_71 ( & V_96 -> V_91 ) ;
F_28 ( V_96 ) ;
}
F_81 ( V_68 ) ;
}
static void F_82 ( struct V_17 * V_99 )
{
struct V_17 * V_13 = F_83 ( V_99 -> V_97 ) ;
F_84 ( V_99 ) ;
F_85 ( V_13 -> V_100 , V_99 ) ;
F_68 ( V_13 ) ;
}
static void F_86 ( struct V_2 * V_3 , const struct V_20 * V_101 )
{
struct V_19 * V_96 ;
F_49 ( & V_3 -> V_17 -> V_100 -> V_102 ) ;
F_49 ( & V_8 ) ;
F_54 (cfe, &cgrp->files, node) {
struct V_17 * V_99 = V_96 -> V_17 ;
if ( V_101 && V_96 -> type != V_101 )
continue;
F_83 ( V_99 ) ;
F_84 ( V_99 ) ;
F_87 ( V_3 -> V_17 -> V_100 , V_99 ) ;
F_88 ( & V_96 -> V_98 ) ;
F_68 ( V_99 ) ;
break;
}
}
static void F_89 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_4 * V_5 ;
int V_23 ;
F_16 (ss, i) {
struct V_103 * V_104 ;
if ( ! F_5 ( V_23 , & V_52 ) )
continue;
F_54 (set, &ss->cftsets, node)
F_90 ( V_3 , V_104 -> V_105 , false ) ;
}
}
static void F_91 ( struct V_17 * V_17 )
{
struct V_17 * V_13 ;
V_13 = V_17 -> V_97 ;
F_92 ( & V_13 -> V_106 ) ;
F_93 ( & V_17 -> V_106 , V_107 ) ;
F_88 ( & V_17 -> V_108 . V_109 ) ;
F_94 ( & V_17 -> V_106 ) ;
F_94 ( & V_13 -> V_106 ) ;
F_82 ( V_17 ) ;
}
static int F_95 ( struct V_51 * V_50 ,
unsigned long V_110 , unsigned V_111 )
{
struct V_2 * V_3 = & V_50 -> V_67 ;
struct V_4 * V_5 ;
unsigned long V_112 = 0 ;
int V_23 , V_113 ;
F_35 ( ! F_57 ( & V_8 ) ) ;
F_35 ( ! F_57 ( & V_114 ) ) ;
F_16 (ss, i) {
if ( ! ( V_110 & ( 1 << V_23 ) ) )
continue;
if ( V_5 -> V_50 != & V_115 ) {
V_113 = - V_116 ;
goto V_117;
}
if ( ! F_96 ( V_5 -> V_118 ) ) {
V_113 = - V_119 ;
goto V_117;
}
V_112 |= 1 << V_23 ;
}
if ( V_110 != V_112 ) {
V_113 = - V_119 ;
goto V_117;
}
V_113 = F_97 ( V_3 , V_110 ) ;
if ( V_113 )
goto V_117;
F_89 ( V_3 , V_111 ) ;
F_16 (ss, i) {
unsigned long V_120 = 1UL << V_23 ;
if ( V_120 & V_110 ) {
F_35 ( F_1 ( V_3 , V_5 ) ) ;
F_35 ( ! F_1 ( V_121 , V_5 ) ) ;
F_35 ( F_1 ( V_121 , V_5 ) -> V_2 != V_121 ) ;
F_98 ( V_3 -> V_6 [ V_23 ] ,
F_1 ( V_121 , V_5 ) ) ;
F_1 ( V_3 , V_5 ) -> V_2 = V_3 ;
V_5 -> V_50 = V_50 ;
if ( V_5 -> V_122 )
V_5 -> V_122 ( F_1 ( V_3 , V_5 ) ) ;
V_50 -> V_52 |= V_120 ;
} else if ( V_120 & V_111 ) {
F_35 ( F_1 ( V_3 , V_5 ) != F_1 ( V_121 , V_5 ) ) ;
F_35 ( F_1 ( V_3 , V_5 ) -> V_2 != V_3 ) ;
if ( V_5 -> V_122 )
V_5 -> V_122 ( F_1 ( V_121 , V_5 ) ) ;
F_1 ( V_121 , V_5 ) -> V_2 = V_121 ;
F_99 ( V_3 -> V_6 [ V_23 ] , NULL ) ;
V_4 [ V_23 ] -> V_50 = & V_115 ;
F_100 ( V_5 -> V_118 ) ;
V_50 -> V_52 &= ~ V_120 ;
}
}
V_50 -> V_11 |= V_123 ;
return 0 ;
V_117:
F_16 (ss, i)
if ( V_112 & ( 1 << V_23 ) )
F_100 ( V_5 -> V_118 ) ;
return V_113 ;
}
static int F_101 ( struct V_124 * V_125 , struct V_17 * V_17 )
{
struct V_51 * V_50 = V_17 -> V_126 -> V_127 ;
struct V_4 * V_5 ;
int V_128 ;
F_13 ( & V_114 ) ;
F_16 (ss, ssid)
if ( V_50 -> V_52 & ( 1 << V_128 ) )
F_102 ( V_125 , L_2 , V_5 -> V_84 ) ;
if ( V_50 -> V_11 & V_129 )
F_103 ( V_125 , L_3 ) ;
if ( V_50 -> V_11 & V_130 )
F_103 ( V_125 , L_4 ) ;
if ( V_50 -> V_11 & V_131 )
F_103 ( V_125 , L_5 ) ;
if ( strlen ( V_50 -> V_132 ) )
F_102 ( V_125 , L_6 , V_50 -> V_132 ) ;
if ( F_5 ( V_133 , & V_50 -> V_67 . V_11 ) )
F_103 ( V_125 , L_7 ) ;
if ( strlen ( V_50 -> V_84 ) )
F_102 ( V_125 , L_8 , V_50 -> V_84 ) ;
F_14 ( & V_114 ) ;
return 0 ;
}
static int F_104 ( char * V_134 , struct V_135 * V_136 )
{
char * V_137 , * V_138 = V_134 ;
bool V_139 = false , V_140 = false ;
unsigned long V_141 = ( unsigned long ) - 1 ;
struct V_4 * V_5 ;
int V_23 ;
F_35 ( ! F_57 ( & V_8 ) ) ;
#ifdef F_105
V_141 = ~ ( 1UL << V_142 ) ;
#endif
memset ( V_136 , 0 , sizeof( * V_136 ) ) ;
while ( ( V_137 = F_106 ( & V_138 , L_9 ) ) != NULL ) {
if ( ! * V_137 )
return - V_143 ;
if ( ! strcmp ( V_137 , L_10 ) ) {
V_136 -> V_144 = true ;
continue;
}
if ( ! strcmp ( V_137 , L_11 ) ) {
if ( V_140 )
return - V_143 ;
V_139 = true ;
continue;
}
if ( ! strcmp ( V_137 , L_12 ) ) {
V_136 -> V_11 |= V_129 ;
continue;
}
if ( ! strcmp ( V_137 , L_13 ) ) {
V_136 -> V_11 |= V_130 ;
continue;
}
if ( ! strcmp ( V_137 , L_14 ) ) {
V_136 -> V_145 = true ;
continue;
}
if ( ! strcmp ( V_137 , L_15 ) ) {
V_136 -> V_11 |= V_131 ;
continue;
}
if ( ! strncmp ( V_137 , L_16 , 14 ) ) {
if ( V_136 -> V_146 )
return - V_143 ;
V_136 -> V_146 =
F_107 ( V_137 + 14 , V_147 - 1 , V_56 ) ;
if ( ! V_136 -> V_146 )
return - V_57 ;
continue;
}
if ( ! strncmp ( V_137 , L_17 , 5 ) ) {
const char * V_84 = V_137 + 5 ;
if ( ! strlen ( V_84 ) )
return - V_143 ;
for ( V_23 = 0 ; V_23 < strlen ( V_84 ) ; V_23 ++ ) {
char V_61 = V_84 [ V_23 ] ;
if ( isalnum ( V_61 ) )
continue;
if ( ( V_61 == '.' ) || ( V_61 == '-' ) || ( V_61 == '_' ) )
continue;
return - V_143 ;
}
if ( V_136 -> V_84 )
return - V_143 ;
V_136 -> V_84 = F_107 ( V_84 ,
V_148 - 1 ,
V_56 ) ;
if ( ! V_136 -> V_84 )
return - V_57 ;
continue;
}
F_16 (ss, i) {
if ( strcmp ( V_137 , V_5 -> V_84 ) )
continue;
if ( V_5 -> V_149 )
continue;
if ( V_139 )
return - V_143 ;
F_26 ( V_23 , & V_136 -> V_52 ) ;
V_140 = true ;
break;
}
if ( V_23 == V_58 )
return - V_119 ;
}
if ( V_139 || ( ! V_140 && ! V_136 -> V_144 && ! V_136 -> V_84 ) )
F_16 (ss, i)
if ( ! V_5 -> V_149 )
F_26 ( V_23 , & V_136 -> V_52 ) ;
if ( V_136 -> V_11 & V_129 ) {
F_108 ( L_18 ) ;
if ( V_136 -> V_11 & V_130 ) {
F_109 ( L_19 ) ;
return - V_143 ;
}
if ( V_136 -> V_145 ) {
F_109 ( L_20 ) ;
return - V_143 ;
}
}
if ( ( V_136 -> V_11 & V_130 ) && ( V_136 -> V_52 & V_141 ) )
return - V_143 ;
if ( V_136 -> V_52 && V_136 -> V_144 )
return - V_143 ;
if ( ! V_136 -> V_52 && ! V_136 -> V_84 )
return - V_143 ;
return 0 ;
}
static int F_110 ( struct V_70 * V_71 , int * V_11 , char * V_134 )
{
int V_113 = 0 ;
struct V_51 * V_50 = V_71 -> V_127 ;
struct V_2 * V_3 = & V_50 -> V_67 ;
struct V_135 V_136 ;
unsigned long V_110 , V_111 ;
if ( V_50 -> V_11 & V_129 ) {
F_109 ( L_21 ) ;
return - V_143 ;
}
F_13 ( & V_3 -> V_17 -> V_100 -> V_102 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_114 ) ;
V_113 = F_104 ( V_134 , & V_136 ) ;
if ( V_113 )
goto V_150;
if ( V_136 . V_52 != V_50 -> V_52 || V_136 . V_146 )
F_108 ( L_22 ,
F_111 ( V_151 ) , V_151 -> V_152 ) ;
V_110 = V_136 . V_52 & ~ V_50 -> V_52 ;
V_111 = V_50 -> V_52 & ~ V_136 . V_52 ;
if ( ( ( V_136 . V_11 ^ V_50 -> V_11 ) & V_153 ) ||
( V_136 . V_84 && strcmp ( V_136 . V_84 , V_50 -> V_84 ) ) ) {
F_109 ( L_23 ,
V_136 . V_11 & V_153 , V_136 . V_84 ? : L_24 ,
V_50 -> V_11 & V_153 , V_50 -> V_84 ) ;
V_113 = - V_143 ;
goto V_150;
}
if ( V_50 -> V_90 > 1 ) {
V_113 = - V_116 ;
goto V_150;
}
V_113 = F_95 ( V_50 , V_110 , V_111 ) ;
if ( V_113 )
goto V_150;
if ( V_136 . V_146 )
strcpy ( V_50 -> V_132 , V_136 . V_146 ) ;
V_150:
F_28 ( V_136 . V_146 ) ;
F_28 ( V_136 . V_84 ) ;
F_14 ( & V_114 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_3 -> V_17 -> V_100 -> V_102 ) ;
return V_113 ;
}
static void F_112 ( struct V_2 * V_3 )
{
F_41 ( & V_3 -> V_154 ) ;
F_41 ( & V_3 -> V_155 ) ;
F_41 ( & V_3 -> V_156 ) ;
F_41 ( & V_3 -> V_36 ) ;
F_41 ( & V_3 -> V_157 ) ;
F_41 ( & V_3 -> V_158 ) ;
F_113 ( & V_3 -> V_159 ) ;
V_3 -> V_9 . V_2 = V_3 ;
F_114 ( & V_3 -> V_91 ) ;
}
static void F_115 ( struct V_51 * V_50 )
{
struct V_2 * V_3 = & V_50 -> V_67 ;
F_41 ( & V_50 -> V_160 ) ;
V_50 -> V_90 = 1 ;
V_3 -> V_50 = V_50 ;
F_99 ( V_3 -> V_84 , & V_161 ) ;
F_112 ( V_3 ) ;
F_116 ( & V_50 -> V_94 ) ;
}
static int F_117 ( struct V_51 * V_50 , int V_162 , int V_163 )
{
int V_95 ;
F_49 ( & V_8 ) ;
F_49 ( & V_114 ) ;
V_95 = F_118 ( & V_164 , V_50 , V_162 , V_163 ,
V_56 ) ;
if ( V_95 < 0 )
return V_95 ;
V_50 -> V_165 = V_95 ;
return 0 ;
}
static void F_119 ( struct V_51 * V_50 )
{
F_49 ( & V_8 ) ;
F_49 ( & V_114 ) ;
if ( V_50 -> V_165 ) {
F_78 ( & V_164 , V_50 -> V_165 ) ;
V_50 -> V_165 = 0 ;
}
}
static int F_120 ( struct V_70 * V_71 , void * V_134 )
{
struct V_135 * V_136 = V_134 ;
struct V_51 * V_50 = V_71 -> V_127 ;
if ( V_136 -> V_84 && strcmp ( V_136 -> V_84 , V_50 -> V_84 ) )
return 0 ;
if ( ( V_136 -> V_52 || V_136 -> V_144 )
&& ( V_136 -> V_52 != V_50 -> V_52 ) )
return 0 ;
return 1 ;
}
static struct V_51 * F_121 ( struct V_135 * V_136 )
{
struct V_51 * V_50 ;
if ( ! V_136 -> V_52 && ! V_136 -> V_144 )
return NULL ;
V_50 = F_42 ( sizeof( * V_50 ) , V_56 ) ;
if ( ! V_50 )
return F_122 ( - V_57 ) ;
F_115 ( V_50 ) ;
V_50 -> V_52 = V_136 -> V_52 ;
V_50 -> V_11 = V_136 -> V_11 ;
if ( V_136 -> V_146 )
strcpy ( V_50 -> V_132 , V_136 -> V_146 ) ;
if ( V_136 -> V_84 )
strcpy ( V_50 -> V_84 , V_136 -> V_84 ) ;
if ( V_136 -> V_145 )
F_26 ( V_133 , & V_50 -> V_67 . V_11 ) ;
return V_50 ;
}
static void F_123 ( struct V_51 * V_50 )
{
if ( V_50 ) {
F_124 ( V_50 -> V_165 ) ;
F_125 ( & V_50 -> V_94 ) ;
F_28 ( V_50 ) ;
}
}
static int F_126 ( struct V_70 * V_71 , void * V_134 )
{
int V_113 ;
struct V_135 * V_136 = V_134 ;
if ( ! V_136 -> V_166 )
return - V_143 ;
F_35 ( ! V_136 -> V_52 && ! V_136 -> V_144 ) ;
V_113 = F_127 ( V_71 , NULL ) ;
if ( V_113 )
return V_113 ;
V_71 -> V_127 = V_136 -> V_166 ;
V_136 -> V_166 -> V_71 = V_71 ;
V_71 -> V_167 = V_168 ;
V_71 -> V_169 = V_170 ;
V_71 -> V_171 = V_172 ;
V_71 -> V_173 = & V_174 ;
return 0 ;
}
static int F_128 ( struct V_70 * V_71 )
{
static const struct V_175 V_176 = {
. V_177 = F_76 ,
. F_84 = V_178 ,
} ;
struct V_68 * V_68 =
F_59 ( V_179 | V_180 | V_181 | V_182 , V_71 ) ;
if ( ! V_68 )
return - V_57 ;
V_68 -> V_183 = & V_184 ;
V_68 -> V_185 = & V_186 ;
F_129 ( V_68 ) ;
V_71 -> V_187 = F_130 ( V_68 ) ;
if ( ! V_71 -> V_187 )
return - V_57 ;
V_71 -> V_188 = & V_176 ;
return 0 ;
}
static struct V_17 * F_131 ( struct V_189 * V_190 ,
int V_11 , const char * V_191 ,
void * V_134 )
{
struct V_135 V_136 ;
struct V_51 * V_50 ;
int V_113 = 0 ;
struct V_70 * V_71 ;
struct V_51 * V_166 ;
struct V_41 V_55 ;
struct V_68 * V_68 ;
const struct V_192 * V_192 ;
F_13 ( & V_8 ) ;
V_113 = F_104 ( V_134 , & V_136 ) ;
F_14 ( & V_8 ) ;
if ( V_113 )
goto V_193;
V_166 = F_121 ( & V_136 ) ;
if ( F_132 ( V_166 ) ) {
V_113 = F_133 ( V_166 ) ;
goto V_193;
}
V_136 . V_166 = V_166 ;
V_71 = F_134 ( V_190 , F_120 , F_126 , 0 , & V_136 ) ;
if ( F_132 ( V_71 ) ) {
V_113 = F_133 ( V_71 ) ;
F_123 ( V_136 . V_166 ) ;
goto V_193;
}
V_50 = V_71 -> V_127 ;
F_35 ( ! V_50 ) ;
if ( V_50 == V_136 . V_166 ) {
struct V_2 * V_194 = & V_50 -> V_67 ;
struct V_51 * V_195 ;
int V_23 ;
struct V_24 * V_25 ;
F_35 ( V_71 -> V_187 != NULL ) ;
V_113 = F_128 ( V_71 ) ;
if ( V_113 )
goto V_196;
V_68 = V_71 -> V_187 -> V_100 ;
F_13 ( & V_68 -> V_102 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_114 ) ;
V_113 = F_135 ( & V_50 -> V_94 , V_194 , 0 , 1 , V_56 ) ;
if ( V_113 < 0 )
goto V_197;
V_194 -> V_95 = V_113 ;
V_113 = - V_116 ;
if ( strlen ( V_50 -> V_84 ) )
F_136 (existing_root)
if ( ! strcmp ( V_195 -> V_84 , V_50 -> V_84 ) )
goto V_197;
V_113 = F_40 ( V_33 , & V_55 ) ;
if ( V_113 )
goto V_197;
V_113 = F_117 ( V_50 , 2 , 0 ) ;
if ( V_113 )
goto V_197;
V_71 -> V_187 -> V_18 = V_194 ;
V_194 -> V_17 = V_71 -> V_187 ;
V_192 = F_137 ( & V_198 ) ;
V_113 = F_90 ( V_194 , V_199 , true ) ;
if ( V_113 )
goto V_200;
V_113 = F_95 ( V_50 , V_50 -> V_52 , 0 ) ;
if ( V_113 )
goto V_200;
F_138 ( V_192 ) ;
F_43 ( & V_50 -> V_160 , & V_201 ) ;
V_59 ++ ;
F_19 ( & V_31 ) ;
F_139 (css_set_table, i, cset, hlist)
F_44 ( & V_55 , V_25 , V_194 ) ;
F_21 ( & V_31 ) ;
F_39 ( & V_55 ) ;
F_35 ( ! F_25 ( & V_194 -> V_155 ) ) ;
F_35 ( V_50 -> V_90 != 1 ) ;
F_14 ( & V_114 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_68 -> V_102 ) ;
} else {
F_123 ( V_136 . V_166 ) ;
if ( ( V_50 -> V_11 ^ V_136 . V_11 ) & V_153 ) {
if ( ( V_50 -> V_11 | V_136 . V_11 ) & V_129 ) {
F_109 ( L_25 ) ;
V_113 = - V_143 ;
goto V_196;
} else {
F_108 ( L_26 ) ;
}
}
}
F_28 ( V_136 . V_146 ) ;
F_28 ( V_136 . V_84 ) ;
return F_83 ( V_71 -> V_187 ) ;
V_200:
F_39 ( & V_55 ) ;
F_90 ( & V_50 -> V_67 , V_199 , false ) ;
F_138 ( V_192 ) ;
V_197:
F_119 ( V_50 ) ;
F_14 ( & V_114 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_68 -> V_102 ) ;
V_196:
F_140 ( V_71 ) ;
V_193:
F_28 ( V_136 . V_146 ) ;
F_28 ( V_136 . V_84 ) ;
return F_122 ( V_113 ) ;
}
static void F_141 ( struct V_70 * V_71 )
{
struct V_51 * V_50 = V_71 -> V_127 ;
struct V_2 * V_3 = & V_50 -> V_67 ;
struct V_27 * V_28 , * V_29 ;
int V_113 ;
F_35 ( ! V_50 ) ;
F_35 ( V_50 -> V_90 != 1 ) ;
F_35 ( ! F_25 ( & V_3 -> V_155 ) ) ;
F_13 ( & V_3 -> V_17 -> V_100 -> V_102 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_114 ) ;
if ( V_50 -> V_11 & V_123 ) {
V_113 = F_95 ( V_50 , 0 , V_50 -> V_52 ) ;
F_35 ( V_113 ) ;
}
F_19 ( & V_31 ) ;
F_23 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_24 ( & V_28 -> V_34 ) ;
F_24 ( & V_28 -> V_35 ) ;
F_28 ( V_28 ) ;
}
F_21 ( & V_31 ) ;
if ( ! F_25 ( & V_50 -> V_160 ) ) {
F_24 ( & V_50 -> V_160 ) ;
V_59 -- ;
}
F_119 ( V_50 ) ;
F_14 ( & V_114 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_3 -> V_17 -> V_100 -> V_102 ) ;
F_71 ( & V_3 -> V_91 ) ;
F_142 ( V_71 ) ;
F_123 ( V_50 ) ;
}
int F_143 ( const struct V_2 * V_3 , char * V_202 , int V_203 )
{
int V_113 = - V_204 ;
char * V_162 ;
if ( ! V_3 -> V_13 ) {
if ( F_144 ( V_202 , L_27 , V_203 ) >= V_203 )
return - V_204 ;
return 0 ;
}
V_162 = V_202 + V_203 - 1 ;
* V_162 = '\0' ;
F_145 () ;
do {
const char * V_84 = V_83 ( V_3 ) ;
int V_86 ;
V_86 = strlen ( V_84 ) ;
if ( ( V_162 -= V_86 ) < V_202 )
goto V_205;
memcpy ( V_162 , V_84 , V_86 ) ;
if ( -- V_162 < V_202 )
goto V_205;
* V_162 = '/' ;
V_3 = V_3 -> V_13 ;
} while ( V_3 -> V_13 );
V_113 = 0 ;
memmove ( V_202 , V_162 , V_202 + V_203 - V_162 ) ;
V_205:
F_146 () ;
return V_113 ;
}
int F_147 ( struct V_63 * V_64 , char * V_202 , T_2 V_203 )
{
struct V_51 * V_50 ;
struct V_2 * V_3 ;
int V_165 = 1 , V_113 = 0 ;
if ( V_203 < 2 )
return - V_204 ;
F_13 ( & V_8 ) ;
V_50 = F_148 ( & V_164 , & V_165 ) ;
if ( V_50 ) {
V_3 = F_56 ( V_64 , V_50 ) ;
V_113 = F_143 ( V_3 , V_202 , V_203 ) ;
} else {
memcpy ( V_202 , L_27 , 2 ) ;
}
F_14 ( & V_8 ) ;
return V_113 ;
}
struct V_63 * F_149 ( struct V_206 * V_207 )
{
if ( V_207 -> V_208 ) {
V_207 -> V_209 = 0 ;
return F_150 ( V_207 ) ;
} else {
V_207 -> V_210 = V_207 -> V_211 . V_3 ;
return V_207 -> V_211 . V_64 ;
}
}
struct V_63 * F_150 ( struct V_206 * V_207 )
{
struct V_212 * V_213 ;
if ( ! V_207 -> V_208 || V_207 -> V_209 >= V_207 -> V_214 )
return NULL ;
V_213 = F_151 ( V_207 -> V_208 , V_207 -> V_209 ++ ) ;
V_207 -> V_210 = V_213 -> V_3 ;
return V_213 -> V_64 ;
}
struct V_1 * F_152 ( struct V_206 * V_207 ,
int V_7 )
{
return F_1 ( V_207 -> V_210 , V_4 [ V_7 ] ) ;
}
int F_153 ( struct V_206 * V_207 )
{
return V_207 -> V_208 ? V_207 -> V_214 : 1 ;
}
static void F_154 ( struct V_2 * V_215 ,
struct V_63 * V_216 ,
struct V_24 * V_217 )
{
struct V_24 * V_38 ;
F_124 ( V_216 -> V_11 & V_218 ) ;
V_38 = F_58 ( V_216 ) ;
F_155 ( V_216 ) ;
F_98 ( V_216 -> V_219 , V_217 ) ;
F_156 ( V_216 ) ;
F_19 ( & V_31 ) ;
if ( ! F_25 ( & V_216 -> V_220 ) )
F_46 ( & V_216 -> V_220 , & V_217 -> V_60 ) ;
F_21 ( & V_31 ) ;
F_26 ( V_15 , & V_215 -> V_11 ) ;
F_32 ( V_38 ) ;
}
static int F_157 ( struct V_2 * V_3 , struct V_63 * V_216 ,
bool V_221 )
{
int V_222 , V_23 , V_223 ;
struct V_51 * V_50 = V_3 -> V_50 ;
struct V_1 * V_21 , * V_224 = NULL ;
struct V_63 * V_225 = V_216 ;
struct V_212 * V_213 ;
struct V_226 * V_227 ;
struct V_206 V_207 = { } ;
if ( V_221 )
V_223 = F_158 ( V_216 ) ;
else
V_223 = 1 ;
V_227 = F_159 ( sizeof( * V_213 ) , V_223 , V_56 ) ;
if ( ! V_227 )
return - V_57 ;
V_222 = F_160 ( V_227 , 0 , V_223 , V_56 ) ;
if ( V_222 )
goto V_228;
V_23 = 0 ;
F_145 () ;
do {
struct V_212 V_229 ;
if ( V_216 -> V_11 & V_218 )
goto V_49;
F_35 ( V_23 >= V_223 ) ;
V_229 . V_64 = V_216 ;
V_229 . V_3 = F_56 ( V_216 , V_50 ) ;
if ( V_229 . V_3 == V_3 )
goto V_49;
V_222 = F_161 ( V_227 , V_23 , & V_229 , V_230 ) ;
F_35 ( V_222 != 0 ) ;
V_23 ++ ;
V_49:
if ( ! V_221 )
break;
} while_each_thread(leader, tsk) ;
int F_162 ( struct V_2 * V_3 , T_3 V_231 , bool V_221 )
{
struct V_63 * V_216 ;
const struct V_192 * V_192 = F_163 () , * V_232 ;
int V_113 ;
if ( ! F_12 ( V_3 ) )
return - V_233 ;
V_234:
F_145 () ;
if ( V_231 ) {
V_216 = F_164 ( V_231 ) ;
if ( ! V_216 ) {
F_146 () ;
V_113 = - V_235 ;
goto V_236;
}
V_232 = F_165 ( V_216 ) ;
if ( ! F_166 ( V_192 -> V_237 , V_238 ) &&
! F_166 ( V_192 -> V_237 , V_232 -> V_239 ) &&
! F_166 ( V_192 -> V_237 , V_232 -> V_240 ) ) {
F_146 () ;
V_113 = - V_241 ;
goto V_236;
}
} else
V_216 = V_151 ;
if ( V_221 )
V_216 = V_216 -> V_242 ;
if ( V_216 == V_243 || ( V_216 -> V_11 & V_244 ) ) {
V_113 = - V_143 ;
F_146 () ;
goto V_236;
}
F_167 ( V_216 ) ;
F_146 () ;
F_168 ( V_216 ) ;
if ( V_221 ) {
if ( ! F_169 ( V_216 ) ) {
F_170 ( V_216 ) ;
F_171 ( V_216 ) ;
goto V_234;
}
}
V_113 = F_157 ( V_3 , V_216 , V_221 ) ;
F_170 ( V_216 ) ;
F_171 ( V_216 ) ;
V_236:
F_14 ( & V_8 ) ;
return V_113 ;
}
int F_172 ( struct V_63 * V_245 , struct V_63 * V_216 )
{
struct V_51 * V_50 ;
int V_222 = 0 ;
F_13 ( & V_8 ) ;
F_136 (root) {
struct V_2 * V_246 = F_56 ( V_245 , V_50 ) ;
V_222 = F_157 ( V_246 , V_216 , false ) ;
if ( V_222 )
break;
}
F_14 ( & V_8 ) ;
return V_222 ;
}
static int F_173 ( struct V_1 * V_21 ,
struct V_20 * V_101 , T_3 V_231 )
{
return F_162 ( V_21 -> V_2 , V_231 , false ) ;
}
static int F_174 ( struct V_1 * V_21 ,
struct V_20 * V_101 , T_3 V_247 )
{
return F_162 ( V_21 -> V_2 , V_247 , true ) ;
}
static int F_175 ( struct V_1 * V_21 ,
struct V_20 * V_101 , const char * V_248 )
{
F_176 ( sizeof( V_21 -> V_2 -> V_50 -> V_132 ) < V_147 ) ;
if ( strlen ( V_248 ) >= V_147 )
return - V_143 ;
if ( ! F_12 ( V_21 -> V_2 ) )
return - V_233 ;
F_13 ( & V_114 ) ;
strcpy ( V_21 -> V_2 -> V_50 -> V_132 , V_248 ) ;
F_14 ( & V_114 ) ;
F_14 ( & V_8 ) ;
return 0 ;
}
static int F_177 ( struct V_124 * V_125 , void * V_249 )
{
struct V_2 * V_3 = F_178 ( V_125 ) -> V_2 ;
if ( ! F_12 ( V_3 ) )
return - V_233 ;
F_103 ( V_125 , V_3 -> V_50 -> V_132 ) ;
F_179 ( V_125 , '\n' ) ;
F_14 ( & V_8 ) ;
return 0 ;
}
static int F_180 ( struct V_124 * V_125 , void * V_249 )
{
struct V_2 * V_3 = F_178 ( V_125 ) -> V_2 ;
F_102 ( V_125 , L_28 , F_181 ( V_3 ) ) ;
return 0 ;
}
static T_4 F_182 ( struct V_250 * V_250 , const char T_5 * V_251 ,
T_2 V_252 , T_6 * V_253 )
{
struct V_19 * V_96 = F_10 ( V_250 -> V_254 ) ;
struct V_20 * V_101 = F_11 ( V_250 -> V_254 ) ;
struct V_1 * V_21 = V_96 -> V_21 ;
T_2 V_255 = V_101 -> V_256 ? : V_257 - 1 ;
char * V_202 ;
int V_113 ;
if ( V_252 >= V_255 )
return - V_258 ;
V_202 = F_65 ( V_252 + 1 , V_56 ) ;
if ( ! V_202 )
return - V_57 ;
if ( F_183 ( V_202 , V_251 , V_252 ) ) {
V_113 = - V_259 ;
goto V_260;
}
V_202 [ V_252 ] = '\0' ;
if ( V_101 -> V_261 ) {
V_113 = V_101 -> V_261 ( V_21 , V_101 , F_184 ( V_202 ) ) ;
} else if ( V_101 -> V_262 ) {
unsigned long long V_249 ;
V_113 = F_185 ( V_202 , 0 , & V_249 ) ;
if ( ! V_113 )
V_113 = V_101 -> V_262 ( V_21 , V_101 , V_249 ) ;
} else if ( V_101 -> V_263 ) {
long long V_249 ;
V_113 = F_186 ( V_202 , 0 , & V_249 ) ;
if ( ! V_113 )
V_113 = V_101 -> V_263 ( V_21 , V_101 , V_249 ) ;
} else if ( V_101 -> V_264 ) {
V_113 = V_101 -> V_264 ( V_21 , ( unsigned int ) V_101 -> V_265 ) ;
} else {
V_113 = - V_143 ;
}
V_260:
F_28 ( V_202 ) ;
return V_113 ? : V_252 ;
}
static void * F_187 ( struct V_124 * V_125 , T_6 * V_253 )
{
struct V_20 * V_101 = F_188 ( V_125 ) ;
if ( V_101 -> V_266 ) {
return V_101 -> V_266 ( V_125 , V_253 ) ;
} else {
return NULL + ! * V_253 ;
}
}
static void * F_189 ( struct V_124 * V_125 , void * V_249 , T_6 * V_253 )
{
struct V_20 * V_101 = F_188 ( V_125 ) ;
if ( V_101 -> V_267 ) {
return V_101 -> V_267 ( V_125 , V_249 , V_253 ) ;
} else {
++ * V_253 ;
return NULL ;
}
}
static void F_190 ( struct V_124 * V_125 , void * V_249 )
{
struct V_20 * V_101 = F_188 ( V_125 ) ;
if ( V_101 -> V_268 )
V_101 -> V_268 ( V_125 , V_249 ) ;
}
static int F_191 ( struct V_124 * V_269 , void * V_270 )
{
struct V_20 * V_101 = F_188 ( V_269 ) ;
struct V_1 * V_21 = F_178 ( V_269 ) ;
if ( V_101 -> V_271 )
return V_101 -> V_271 ( V_269 , V_270 ) ;
if ( V_101 -> V_272 )
F_102 ( V_269 , L_29 , V_101 -> V_272 ( V_21 , V_101 ) ) ;
else if ( V_101 -> V_273 )
F_102 ( V_269 , L_30 , V_101 -> V_273 ( V_21 , V_101 ) ) ;
else
return - V_143 ;
return 0 ;
}
static int F_192 ( struct V_68 * V_68 , struct V_250 * V_250 )
{
struct V_19 * V_96 = F_10 ( V_250 -> V_254 ) ;
struct V_20 * V_101 = F_11 ( V_250 -> V_254 ) ;
struct V_2 * V_3 = F_9 ( V_96 -> V_17 -> V_97 ) ;
struct V_1 * V_21 ;
struct V_274 * V_275 ;
int V_276 ;
V_276 = F_193 ( V_68 , V_250 ) ;
if ( V_276 )
return V_276 ;
F_145 () ;
V_21 = F_1 ( V_3 , V_101 -> V_5 ) ;
if ( V_101 -> V_5 && ! F_194 ( V_21 ) )
V_21 = NULL ;
F_146 () ;
if ( ! V_21 )
return - V_233 ;
F_124 ( V_96 -> V_21 && V_96 -> V_21 != V_21 ) ;
V_96 -> V_21 = V_21 ;
V_275 = F_195 ( V_250 , & V_277 ,
sizeof( struct V_274 ) ) ;
if ( V_275 ) {
V_275 -> V_96 = V_96 ;
return 0 ;
}
if ( V_21 -> V_5 )
F_196 ( V_21 ) ;
return - V_57 ;
}
static int F_197 ( struct V_68 * V_68 , struct V_250 * V_250 )
{
struct V_19 * V_96 = F_10 ( V_250 -> V_254 ) ;
struct V_1 * V_21 = V_96 -> V_21 ;
if ( V_21 -> V_5 )
F_196 ( V_21 ) ;
return F_198 ( V_68 , V_250 ) ;
}
static int F_199 ( struct V_68 * V_278 , struct V_17 * V_279 ,
struct V_68 * V_280 , struct V_17 * V_281 )
{
int V_113 ;
struct V_83 * V_84 , * V_282 ;
struct V_2 * V_3 ;
F_49 ( & V_278 -> V_102 ) ;
if ( ! F_77 ( V_279 -> V_100 -> V_73 ) )
return - V_283 ;
if ( V_281 -> V_100 )
return - V_284 ;
if ( V_278 != V_280 )
return - V_285 ;
V_3 = F_9 ( V_279 ) ;
if ( F_181 ( V_3 ) )
return - V_286 ;
V_84 = F_64 ( V_281 ) ;
if ( ! V_84 )
return - V_57 ;
V_113 = F_200 ( V_278 , V_279 , V_280 , V_281 ) ;
if ( V_113 ) {
F_28 ( V_84 ) ;
return V_113 ;
}
V_282 = F_201 ( V_3 -> V_84 , true ) ;
F_98 ( V_3 -> V_84 , V_84 ) ;
F_29 ( V_282 , V_37 ) ;
return 0 ;
}
static struct V_287 * F_202 ( struct V_17 * V_17 )
{
if ( F_77 ( V_17 -> V_100 -> V_73 ) )
return & F_9 ( V_17 ) -> V_91 ;
else
return & F_10 ( V_17 ) -> V_91 ;
}
static inline int F_203 ( struct V_17 * V_17 )
{
struct V_51 * V_50 = V_17 -> V_126 -> V_127 ;
return V_50 -> V_11 & V_131 ;
}
static bool F_204 ( const char * V_84 )
{
if ( ! strncmp ( V_84 , V_288 , V_289 ) ||
! strncmp ( V_84 , V_290 , V_291 ) )
return true ;
return false ;
}
static int F_205 ( struct V_17 * V_17 , const char * V_84 ,
const void * V_292 , T_2 V_293 , int V_11 )
{
if ( ! F_203 ( V_17 ) )
return - V_294 ;
if ( ! F_204 ( V_84 ) )
return - V_143 ;
return F_206 ( F_202 ( V_17 ) , V_84 , V_292 , V_293 , V_11 ) ;
}
static int F_207 ( struct V_17 * V_17 , const char * V_84 )
{
if ( ! F_203 ( V_17 ) )
return - V_294 ;
if ( ! F_204 ( V_84 ) )
return - V_143 ;
return F_208 ( F_202 ( V_17 ) , V_84 ) ;
}
static T_4 F_209 ( struct V_17 * V_17 , const char * V_84 ,
void * V_202 , T_2 V_293 )
{
if ( ! F_203 ( V_17 ) )
return - V_294 ;
if ( ! F_204 ( V_84 ) )
return - V_143 ;
return F_210 ( F_202 ( V_17 ) , V_84 , V_202 , V_293 ) ;
}
static T_4 F_211 ( struct V_17 * V_17 , char * V_202 , T_2 V_293 )
{
if ( ! F_203 ( V_17 ) )
return - V_294 ;
return F_212 ( F_202 ( V_17 ) , V_202 , V_293 ) ;
}
static int F_213 ( struct V_17 * V_17 , T_1 V_69 ,
struct V_70 * V_71 )
{
struct V_68 * V_68 ;
if ( ! V_17 )
return - V_119 ;
if ( V_17 -> V_100 )
return - V_284 ;
V_68 = F_59 ( V_69 , V_71 ) ;
if ( ! V_68 )
return - V_57 ;
if ( F_77 ( V_69 ) ) {
V_68 -> V_185 = & V_186 ;
V_68 -> V_183 = & V_184 ;
F_129 ( V_68 ) ;
F_129 ( V_17 -> V_97 -> V_100 ) ;
F_124 ( ! F_214 ( & V_68 -> V_102 ) ) ;
} else if ( F_215 ( V_69 ) ) {
V_68 -> V_295 = 0 ;
V_68 -> V_183 = & V_296 ;
V_68 -> V_185 = & V_297 ;
}
F_216 ( V_17 , V_68 ) ;
F_83 ( V_17 ) ;
return 0 ;
}
static T_1 F_217 ( const struct V_20 * V_101 )
{
T_1 V_69 = 0 ;
if ( V_101 -> V_69 )
return V_101 -> V_69 ;
if ( V_101 -> V_272 || V_101 -> V_273 || V_101 -> V_271 )
V_69 |= V_180 ;
if ( V_101 -> V_262 || V_101 -> V_263 || V_101 -> V_261 ||
V_101 -> V_264 )
V_69 |= V_182 ;
return V_69 ;
}
static int F_218 ( struct V_2 * V_3 , struct V_20 * V_101 )
{
struct V_17 * V_298 = V_3 -> V_17 ;
struct V_2 * V_13 = F_9 ( V_298 ) ;
struct V_17 * V_17 ;
struct V_19 * V_96 ;
int error ;
T_1 V_69 ;
char V_84 [ V_299 + V_300 + 2 ] = { 0 } ;
if ( V_101 -> V_5 && ! ( V_101 -> V_11 & V_301 ) &&
! ( V_3 -> V_50 -> V_11 & V_130 ) ) {
strcpy ( V_84 , V_101 -> V_5 -> V_84 ) ;
strcat ( V_84 , L_31 ) ;
}
strcat ( V_84 , V_101 -> V_84 ) ;
F_35 ( ! F_57 ( & V_298 -> V_100 -> V_102 ) ) ;
V_96 = F_42 ( sizeof( * V_96 ) , V_56 ) ;
if ( ! V_96 )
return - V_57 ;
V_17 = F_219 ( V_84 , V_298 , strlen ( V_84 ) ) ;
if ( F_132 ( V_17 ) ) {
error = F_133 ( V_17 ) ;
goto V_205;
}
V_96 -> type = ( void * ) V_101 ;
V_96 -> V_17 = V_17 ;
V_17 -> V_18 = V_96 ;
F_114 ( & V_96 -> V_91 ) ;
V_69 = F_217 ( V_101 ) ;
error = F_213 ( V_17 , V_69 | V_302 , V_3 -> V_50 -> V_71 ) ;
if ( ! error ) {
F_47 ( & V_96 -> V_98 , & V_13 -> V_156 ) ;
V_96 = NULL ;
}
F_68 ( V_17 ) ;
V_205:
F_28 ( V_96 ) ;
return error ;
}
static int F_90 ( struct V_2 * V_3 , struct V_20 V_105 [] ,
bool V_303 )
{
struct V_20 * V_101 ;
int V_113 ;
F_49 ( & V_3 -> V_17 -> V_100 -> V_102 ) ;
F_49 ( & V_8 ) ;
for ( V_101 = V_105 ; V_101 -> V_84 [ 0 ] != '\0' ; V_101 ++ ) {
if ( ( V_101 -> V_11 & V_304 ) && F_181 ( V_3 ) )
continue;
if ( ( V_101 -> V_11 & V_305 ) && ! V_3 -> V_13 )
continue;
if ( ( V_101 -> V_11 & V_306 ) && V_3 -> V_13 )
continue;
if ( V_303 ) {
V_113 = F_218 ( V_3 , V_101 ) ;
if ( V_113 ) {
F_220 ( L_32 ,
V_101 -> V_84 , V_113 ) ;
return V_113 ;
}
} else {
F_86 ( V_3 , V_101 ) ;
}
}
return 0 ;
}
static void F_221 ( void )
__acquires( &cgroup_mutex
static int F_222 ( struct V_20 * V_105 , bool V_303 )
__releases( &cgroup_mutex
int F_223 ( struct V_4 * V_5 , struct V_20 * V_105 )
{
struct V_103 * V_104 ;
struct V_20 * V_101 ;
int V_113 ;
V_104 = F_42 ( sizeof( * V_104 ) , V_56 ) ;
if ( ! V_104 )
return - V_57 ;
for ( V_101 = V_105 ; V_101 -> V_84 [ 0 ] != '\0' ; V_101 ++ )
V_101 -> V_5 = V_5 ;
F_221 () ;
V_104 -> V_105 = V_105 ;
F_47 ( & V_104 -> V_98 , & V_5 -> V_307 ) ;
V_113 = F_222 ( V_105 , true ) ;
if ( V_113 )
F_224 ( V_105 ) ;
return V_113 ;
}
int F_224 ( struct V_20 * V_105 )
{
struct V_103 * V_104 ;
if ( ! V_105 || ! V_105 [ 0 ] . V_5 )
return - V_119 ;
F_221 () ;
F_54 (set, &cfts[0].ss->cftsets, node) {
if ( V_104 -> V_105 == V_105 ) {
F_24 ( & V_104 -> V_98 ) ;
F_28 ( V_104 ) ;
F_222 ( V_105 , false ) ;
return 0 ;
}
}
F_222 ( NULL , false ) ;
return - V_119 ;
}
int F_225 ( const struct V_2 * V_3 )
{
int V_54 = 0 ;
struct V_27 * V_28 ;
F_50 ( & V_31 ) ;
F_54 (link, &cgrp->cset_links, cset_link)
V_54 += F_226 ( & V_28 -> V_25 -> V_30 ) ;
F_51 ( & V_31 ) ;
return V_54 ;
}
static void F_227 ( void )
{
struct V_63 * V_308 , * V_309 ;
F_19 ( & V_31 ) ;
V_310 = 1 ;
F_50 ( & V_311 ) ;
F_228 (g, p) {
F_155 ( V_308 ) ;
F_229 ( & V_308 -> V_312 -> V_313 ) ;
if ( ! ( V_308 -> V_11 & V_218 ) && F_25 ( & V_308 -> V_220 ) )
F_43 ( & V_308 -> V_220 , & F_58 ( V_308 ) -> V_60 ) ;
F_230 ( & V_308 -> V_312 -> V_313 ) ;
F_156 ( V_308 ) ;
} F_231 ( V_309 , V_308 ) ;
F_51 ( & V_311 ) ;
F_21 ( & V_31 ) ;
}
struct V_1 *
F_232 ( struct V_1 * V_314 ,
struct V_1 * V_315 )
{
struct V_2 * V_316 = V_314 ? V_314 -> V_2 : NULL ;
struct V_2 * V_3 = V_315 -> V_2 ;
struct V_2 * V_49 ;
F_233 () ;
if ( ! V_316 ) {
V_49 = F_234 ( V_3 -> V_155 . V_49 , struct V_2 , V_154 ) ;
} else if ( F_235 ( ! F_4 ( V_316 ) ) ) {
V_49 = F_234 ( V_316 -> V_154 . V_49 , struct V_2 , V_154 ) ;
} else {
F_236 (next, &cgrp->children, sibling)
if ( V_49 -> V_317 > V_316 -> V_317 )
break;
}
if ( & V_49 -> V_154 == & V_3 -> V_155 )
return NULL ;
return F_1 ( V_49 , V_315 -> V_5 ) ;
}
struct V_1 *
F_237 ( struct V_1 * V_316 ,
struct V_1 * V_50 )
{
struct V_1 * V_49 ;
F_233 () ;
if ( ! V_316 )
return V_50 ;
V_49 = F_232 ( NULL , V_316 ) ;
if ( V_49 )
return V_49 ;
while ( V_316 != V_50 ) {
V_49 = F_232 ( V_316 , F_238 ( V_316 ) ) ;
if ( V_49 )
return V_49 ;
V_316 = F_238 ( V_316 ) ;
}
return NULL ;
}
struct V_1 *
F_239 ( struct V_1 * V_316 )
{
struct V_1 * V_318 , * V_319 ;
F_233 () ;
do {
V_318 = V_316 ;
V_316 = NULL ;
F_240 (tmp, last)
V_316 = V_319 ;
} while ( V_316 );
return V_318 ;
}
static struct V_1 *
F_241 ( struct V_1 * V_316 )
{
struct V_1 * V_318 ;
do {
V_318 = V_316 ;
V_316 = F_232 ( NULL , V_316 ) ;
} while ( V_316 );
return V_318 ;
}
struct V_1 *
F_242 ( struct V_1 * V_316 ,
struct V_1 * V_50 )
{
struct V_1 * V_49 ;
F_233 () ;
if ( ! V_316 )
return F_241 ( V_50 ) ;
if ( V_316 == V_50 )
return NULL ;
V_49 = F_232 ( V_316 , F_238 ( V_316 ) ) ;
if ( V_49 )
return F_241 ( V_49 ) ;
return F_238 ( V_316 ) ;
}
static void F_243 ( struct V_320 * V_321 )
{
struct V_41 * V_322 = V_321 -> V_34 ;
struct V_27 * V_28 ;
struct V_24 * V_25 ;
do {
V_322 = V_322 -> V_49 ;
if ( V_322 == & V_321 -> V_323 -> V_2 -> V_36 ) {
V_321 -> V_34 = NULL ;
return;
}
V_28 = F_36 ( V_322 , struct V_27 , V_34 ) ;
V_25 = V_28 -> V_25 ;
} while ( F_25 ( & V_25 -> V_60 ) );
V_321 -> V_34 = V_322 ;
V_321 -> V_64 = V_25 -> V_60 . V_49 ;
}
void F_244 ( struct V_1 * V_21 ,
struct V_320 * V_321 )
__acquires( V_31 )
{
if ( ! V_310 )
F_227 () ;
F_50 ( & V_31 ) ;
V_321 -> V_323 = V_21 ;
V_321 -> V_34 = & V_21 -> V_2 -> V_36 ;
F_243 ( V_321 ) ;
}
struct V_63 * F_245 ( struct V_320 * V_321 )
{
struct V_63 * V_65 ;
struct V_41 * V_322 = V_321 -> V_64 ;
struct V_27 * V_28 ;
if ( ! V_321 -> V_34 )
return NULL ;
V_65 = F_36 ( V_322 , struct V_63 , V_220 ) ;
V_322 = V_322 -> V_49 ;
V_28 = F_36 ( V_321 -> V_34 , struct V_27 , V_34 ) ;
if ( V_322 == & V_28 -> V_25 -> V_60 ) {
F_243 ( V_321 ) ;
} else {
V_321 -> V_64 = V_322 ;
}
return V_65 ;
}
void F_246 ( struct V_320 * V_321 )
__releases( V_31 )
{
F_51 ( & V_31 ) ;
}
static inline int F_247 ( struct V_63 * V_324 ,
struct V_325 * time ,
struct V_63 * V_326 )
{
int V_327 = F_248 ( & V_324 -> V_328 , time ) ;
if ( V_327 > 0 ) {
return 1 ;
} else if ( V_327 < 0 ) {
return 0 ;
} else {
return V_324 > V_326 ;
}
}
static inline int F_249 ( void * V_329 , void * V_330 )
{
struct V_63 * V_324 = V_329 ;
struct V_63 * V_326 = V_330 ;
return F_247 ( V_324 , & V_326 -> V_328 , V_326 ) ;
}
int F_250 ( struct V_1 * V_21 ,
bool (* F_251)( struct V_63 * , void * ) ,
void (* F_252)( struct V_63 * , void * ) ,
void * V_134 , struct V_331 * V_332 )
{
int V_222 , V_23 ;
struct V_320 V_321 ;
struct V_63 * V_308 , * V_333 ;
struct V_63 * V_334 = NULL ;
struct V_331 V_335 ;
struct V_325 V_336 = { 0 , 0 } ;
if ( V_332 ) {
V_332 -> V_337 = & F_249 ;
} else {
V_332 = & V_335 ;
V_222 = F_253 ( V_332 , V_338 , V_56 , & F_249 ) ;
if ( V_222 )
return V_222 ;
}
V_339:
V_332 -> V_293 = 0 ;
F_244 ( V_21 , & V_321 ) ;
while ( ( V_308 = F_245 ( & V_321 ) ) ) {
if ( F_251 && ! F_251 ( V_308 , V_134 ) )
continue;
if ( ! F_247 ( V_308 , & V_336 , V_334 ) )
continue;
V_333 = F_254 ( V_332 , V_308 ) ;
if ( V_333 == NULL ) {
F_167 ( V_308 ) ;
} else if ( V_333 != V_308 ) {
F_167 ( V_308 ) ;
F_171 ( V_333 ) ;
}
}
F_246 ( & V_321 ) ;
if ( V_332 -> V_293 ) {
for ( V_23 = 0 ; V_23 < V_332 -> V_293 ; V_23 ++ ) {
struct V_63 * V_340 = V_332 -> V_341 [ V_23 ] ;
if ( V_23 == 0 ) {
V_336 = V_340 -> V_328 ;
V_334 = V_340 ;
}
F_252 ( V_340 , V_134 ) ;
F_171 ( V_340 ) ;
}
goto V_339;
}
if ( V_332 == & V_335 )
F_255 ( & V_335 ) ;
return 0 ;
}
static void F_256 ( struct V_63 * V_64 , void * V_134 )
{
struct V_2 * V_342 = V_134 ;
F_13 ( & V_8 ) ;
F_157 ( V_342 , V_64 , false ) ;
F_14 ( & V_8 ) ;
}
int F_257 ( struct V_2 * V_343 , struct V_2 * V_245 )
{
return F_250 ( & V_245 -> V_9 , NULL , F_256 ,
V_343 , NULL ) ;
}
static void * F_258 ( int V_54 )
{
if ( F_259 ( V_54 ) )
return F_260 ( V_54 * sizeof( V_344 ) ) ;
else
return F_65 ( V_54 * sizeof( V_344 ) , V_56 ) ;
}
static void F_261 ( void * V_308 )
{
if ( F_262 ( V_308 ) )
F_263 ( V_308 ) ;
else
F_28 ( V_308 ) ;
}
static void F_70 ( struct V_2 * V_3 )
{
struct V_345 * V_322 , * V_346 ;
F_13 ( & V_3 -> V_159 ) ;
F_23 (l, tmp_l, &cgrp->pidlists, links)
F_264 ( V_347 , & V_322 -> V_348 , 0 ) ;
F_14 ( & V_3 -> V_159 ) ;
F_265 ( V_347 ) ;
F_35 ( ! F_25 ( & V_3 -> V_158 ) ) ;
}
static void F_266 ( struct V_87 * V_88 )
{
struct V_349 * V_350 = F_267 ( V_88 ) ;
struct V_345 * V_322 = F_67 ( V_350 , struct V_345 ,
V_348 ) ;
struct V_345 * V_351 = NULL ;
F_13 ( & V_322 -> V_352 -> V_159 ) ;
if ( ! F_268 ( V_350 ) ) {
F_24 ( & V_322 -> V_353 ) ;
F_261 ( V_322 -> V_354 ) ;
F_269 ( V_322 -> V_22 . V_355 ) ;
V_351 = V_322 ;
}
F_14 ( & V_322 -> V_352 -> V_159 ) ;
F_28 ( V_351 ) ;
}
static int F_270 ( V_344 * V_354 , int V_356 )
{
int V_357 , V_358 = 1 ;
if ( V_356 == 0 || V_356 == 1 )
return V_356 ;
for ( V_357 = 1 ; V_357 < V_356 ; V_357 ++ ) {
while ( V_354 [ V_357 ] == V_354 [ V_357 - 1 ] ) {
V_357 ++ ;
if ( V_357 == V_356 )
goto V_359;
}
V_354 [ V_358 ] = V_354 [ V_357 ] ;
V_358 ++ ;
}
V_359:
return V_358 ;
}
static V_344 F_271 ( V_344 V_231 )
{
unsigned V_360 = V_231 & 0x55555555 ;
unsigned V_361 = V_231 & 0xAAAAAAAA ;
return ( V_360 << 1 ) | ( V_361 >> 1 ) ;
}
static V_344 F_272 ( struct V_2 * V_3 , V_344 V_231 )
{
if ( F_181 ( V_3 ) )
return F_271 ( V_231 ) ;
else
return V_231 ;
}
static int F_273 ( const void * V_360 , const void * V_361 )
{
return * ( V_344 * ) V_360 - * ( V_344 * ) V_361 ;
}
static int F_274 ( const void * V_360 , const void * V_361 )
{
return F_271 ( * ( V_344 * ) V_360 ) - F_271 ( * ( V_344 * ) V_361 ) ;
}
static struct V_345 * F_275 ( struct V_2 * V_3 ,
enum V_362 type )
{
struct V_345 * V_322 ;
struct V_363 * V_355 = F_276 ( V_151 ) ;
F_49 ( & V_3 -> V_159 ) ;
F_54 (l, &cgrp->pidlists, links)
if ( V_322 -> V_22 . type == type && V_322 -> V_22 . V_355 == V_355 )
return V_322 ;
return NULL ;
}
static struct V_345 * F_277 ( struct V_2 * V_3 ,
enum V_362 type )
{
struct V_345 * V_322 ;
F_49 ( & V_3 -> V_159 ) ;
V_322 = F_275 ( V_3 , type ) ;
if ( V_322 )
return V_322 ;
V_322 = F_42 ( sizeof( struct V_345 ) , V_56 ) ;
if ( ! V_322 )
return V_322 ;
F_278 ( & V_322 -> V_348 , F_266 ) ;
V_322 -> V_22 . type = type ;
V_322 -> V_22 . V_355 = F_279 ( F_276 ( V_151 ) ) ;
V_322 -> V_352 = V_3 ;
F_43 ( & V_322 -> V_353 , & V_3 -> V_158 ) ;
return V_322 ;
}
static int F_280 ( struct V_2 * V_3 , enum V_362 type ,
struct V_345 * * V_364 )
{
V_344 * V_365 ;
int V_356 ;
int V_231 , V_366 = 0 ;
struct V_320 V_321 ;
struct V_63 * V_216 ;
struct V_345 * V_322 ;
F_49 ( & V_3 -> V_159 ) ;
V_356 = F_225 ( V_3 ) ;
V_365 = F_258 ( V_356 ) ;
if ( ! V_365 )
return - V_57 ;
F_244 ( & V_3 -> V_9 , & V_321 ) ;
while ( ( V_216 = F_245 ( & V_321 ) ) ) {
if ( F_281 ( V_366 == V_356 ) )
break;
if ( type == V_367 )
V_231 = F_282 ( V_216 ) ;
else
V_231 = F_283 ( V_216 ) ;
if ( V_231 > 0 )
V_365 [ V_366 ++ ] = V_231 ;
}
F_246 ( & V_321 ) ;
V_356 = V_366 ;
if ( F_181 ( V_3 ) )
F_284 ( V_365 , V_356 , sizeof( V_344 ) , F_274 , NULL ) ;
else
F_284 ( V_365 , V_356 , sizeof( V_344 ) , F_273 , NULL ) ;
if ( type == V_367 )
V_356 = F_270 ( V_365 , V_356 ) ;
V_322 = F_277 ( V_3 , type ) ;
if ( ! V_322 ) {
F_14 ( & V_3 -> V_159 ) ;
F_261 ( V_365 ) ;
return - V_57 ;
}
F_261 ( V_322 -> V_354 ) ;
V_322 -> V_354 = V_365 ;
V_322 -> V_356 = V_356 ;
* V_364 = V_322 ;
return 0 ;
}
int F_285 ( struct V_368 * V_369 , struct V_17 * V_17 )
{
int V_113 = - V_143 ;
struct V_2 * V_3 ;
struct V_320 V_321 ;
struct V_63 * V_216 ;
if ( V_17 -> V_126 -> V_173 != & V_174 ||
! F_77 ( V_17 -> V_100 -> V_73 ) )
goto V_276;
V_113 = 0 ;
V_3 = V_17 -> V_18 ;
F_244 ( & V_3 -> V_9 , & V_321 ) ;
while ( ( V_216 = F_245 ( & V_321 ) ) ) {
switch ( V_216 -> V_370 ) {
case V_371 :
V_369 -> V_372 ++ ;
break;
case V_373 :
V_369 -> V_374 ++ ;
break;
case V_375 :
V_369 -> V_376 ++ ;
break;
case V_377 :
V_369 -> V_378 ++ ;
break;
default:
if ( F_286 ( V_216 ) )
V_369 -> V_379 ++ ;
break;
}
}
F_246 ( & V_321 ) ;
V_276:
return V_113 ;
}
static void * F_287 ( struct V_124 * V_380 , T_6 * V_316 )
{
struct V_274 * V_275 = V_380 -> V_265 ;
struct V_2 * V_3 = F_178 ( V_380 ) -> V_2 ;
struct V_345 * V_322 ;
enum V_362 type = F_188 ( V_380 ) -> V_265 ;
int V_381 = 0 , V_231 = * V_316 ;
int * V_382 , V_113 ;
F_13 ( & V_3 -> V_159 ) ;
if ( V_275 -> V_383 )
V_275 -> V_383 = F_275 ( V_3 , type ) ;
if ( ! V_275 -> V_383 ) {
V_113 = F_280 ( V_3 , type ,
(struct V_345 * * ) & V_275 -> V_383 ) ;
if ( V_113 )
return F_122 ( V_113 ) ;
}
V_322 = V_275 -> V_383 ;
if ( V_231 ) {
int V_163 = V_322 -> V_356 ;
while ( V_381 < V_163 ) {
int V_384 = ( V_381 + V_163 ) / 2 ;
if ( F_272 ( V_3 , V_322 -> V_354 [ V_384 ] ) == V_231 ) {
V_381 = V_384 ;
break;
} else if ( F_272 ( V_3 , V_322 -> V_354 [ V_384 ] ) <= V_231 )
V_381 = V_384 + 1 ;
else
V_163 = V_384 ;
}
}
if ( V_381 >= V_322 -> V_356 )
return NULL ;
V_382 = V_322 -> V_354 + V_381 ;
* V_316 = F_272 ( V_3 , * V_382 ) ;
return V_382 ;
}
static void F_288 ( struct V_124 * V_380 , void * V_249 )
{
struct V_274 * V_275 = V_380 -> V_265 ;
struct V_345 * V_322 = V_275 -> V_383 ;
if ( V_322 )
F_264 ( V_347 , & V_322 -> V_348 ,
V_385 ) ;
F_14 ( & F_178 ( V_380 ) -> V_2 -> V_159 ) ;
}
static void * F_289 ( struct V_124 * V_380 , void * V_249 , T_6 * V_316 )
{
struct V_274 * V_275 = V_380 -> V_265 ;
struct V_345 * V_322 = V_275 -> V_383 ;
V_344 * V_308 = V_249 ;
V_344 * V_163 = V_322 -> V_354 + V_322 -> V_356 ;
V_308 ++ ;
if ( V_308 >= V_163 ) {
return NULL ;
} else {
* V_316 = F_272 ( F_178 ( V_380 ) -> V_2 , * V_308 ) ;
return V_308 ;
}
}
static int F_290 ( struct V_124 * V_380 , void * V_249 )
{
return F_102 ( V_380 , L_28 , * ( int * ) V_249 ) ;
}
static T_3 F_291 ( struct V_1 * V_21 ,
struct V_20 * V_101 )
{
return F_8 ( V_21 -> V_2 ) ;
}
static int F_292 ( struct V_1 * V_21 ,
struct V_20 * V_101 , T_3 V_292 )
{
F_293 ( V_15 , & V_21 -> V_2 -> V_11 ) ;
if ( V_292 )
F_26 ( V_16 , & V_21 -> V_2 -> V_11 ) ;
else
F_293 ( V_16 , & V_21 -> V_2 -> V_11 ) ;
return 0 ;
}
static void F_294 ( struct V_2 * V_3 )
{
struct V_70 * V_71 = V_3 -> V_50 -> V_71 ;
F_31 ( & V_71 -> V_386 ) ;
F_68 ( V_3 -> V_17 ) ;
F_69 ( V_71 ) ;
}
static T_3 F_295 ( struct V_1 * V_21 ,
struct V_20 * V_101 )
{
return F_5 ( V_133 , & V_21 -> V_2 -> V_11 ) ;
}
static int F_296 ( struct V_1 * V_21 ,
struct V_20 * V_101 , T_3 V_292 )
{
if ( V_292 )
F_26 ( V_133 , & V_21 -> V_2 -> V_11 ) ;
else
F_293 ( V_133 , & V_21 -> V_2 -> V_11 ) ;
return 0 ;
}
static int F_97 ( struct V_2 * V_3 , unsigned long V_52 )
{
struct V_4 * V_5 ;
int V_23 , V_113 = 0 ;
F_16 (ss, i) {
struct V_103 * V_104 ;
if ( ! F_5 ( V_23 , & V_52 ) )
continue;
F_54 (set, &ss->cftsets, node) {
V_113 = F_90 ( V_3 , V_104 -> V_105 , true ) ;
if ( V_113 < 0 )
goto V_276;
}
}
return 0 ;
V_276:
F_89 ( V_3 , V_52 ) ;
return V_113 ;
}
static void F_297 ( struct V_87 * V_88 )
{
struct V_1 * V_21 =
F_67 ( V_88 , struct V_1 , V_89 ) ;
struct V_2 * V_3 = V_21 -> V_2 ;
if ( V_21 -> V_13 )
F_196 ( V_21 -> V_13 ) ;
V_21 -> V_5 -> V_387 ( V_21 ) ;
F_294 ( V_3 ) ;
}
static void F_298 ( struct V_37 * V_37 )
{
struct V_1 * V_21 =
F_67 ( V_37 , struct V_1 , V_37 ) ;
F_74 ( & V_21 -> V_89 , F_297 ) ;
F_75 ( V_93 , & V_21 -> V_89 ) ;
}
static void F_299 ( struct V_388 * V_389 )
{
struct V_1 * V_21 =
F_67 ( V_389 , struct V_1 , V_390 ) ;
F_98 ( V_21 -> V_2 -> V_6 [ V_21 -> V_5 -> V_7 ] , NULL ) ;
F_79 ( & V_21 -> V_37 , F_298 ) ;
}
static void F_300 ( struct V_1 * V_21 , struct V_4 * V_5 ,
struct V_2 * V_3 )
{
V_21 -> V_2 = V_3 ;
V_21 -> V_5 = V_5 ;
V_21 -> V_11 = 0 ;
if ( V_3 -> V_13 )
V_21 -> V_13 = F_1 ( V_3 -> V_13 , V_5 ) ;
else
V_21 -> V_11 |= V_391 ;
F_35 ( F_1 ( V_3 , V_5 ) ) ;
}
static int F_301 ( struct V_1 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
int V_113 = 0 ;
F_49 ( & V_8 ) ;
if ( V_5 -> V_392 )
V_113 = V_5 -> V_392 ( V_21 ) ;
if ( ! V_113 ) {
V_21 -> V_11 |= V_393 ;
V_21 -> V_2 -> V_394 ++ ;
F_98 ( V_21 -> V_2 -> V_6 [ V_5 -> V_7 ] , V_21 ) ;
}
return V_113 ;
}
static void F_302 ( struct V_1 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
F_49 ( & V_8 ) ;
if ( ! ( V_21 -> V_11 & V_393 ) )
return;
if ( V_5 -> V_395 )
V_5 -> V_395 ( V_21 ) ;
V_21 -> V_11 &= ~ V_393 ;
V_21 -> V_2 -> V_394 -- ;
F_99 ( V_21 -> V_2 -> V_6 [ V_5 -> V_7 ] , V_21 ) ;
}
static int F_303 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_2 * V_13 = V_3 -> V_13 ;
struct V_1 * V_21 ;
int V_276 ;
F_49 ( & V_3 -> V_17 -> V_100 -> V_102 ) ;
F_49 ( & V_8 ) ;
V_21 = V_5 -> V_396 ( F_1 ( V_13 , V_5 ) ) ;
if ( F_132 ( V_21 ) )
return F_133 ( V_21 ) ;
V_276 = F_304 ( & V_21 -> V_390 , F_299 ) ;
if ( V_276 )
goto V_397;
F_300 ( V_21 , V_5 , V_3 ) ;
V_276 = F_97 ( V_3 , 1 << V_5 -> V_7 ) ;
if ( V_276 )
goto V_398;
V_276 = F_301 ( V_21 ) ;
if ( V_276 )
goto V_399;
F_83 ( V_3 -> V_17 ) ;
F_305 ( V_21 -> V_13 ) ;
if ( V_5 -> V_400 && ! V_5 -> V_401 &&
V_13 -> V_13 ) {
F_108 ( L_33 ,
V_151 -> V_152 , V_151 -> V_231 , V_5 -> V_84 ) ;
if ( ! strcmp ( V_5 -> V_84 , L_34 ) )
F_108 ( L_35 ) ;
V_5 -> V_401 = true ;
}
return 0 ;
V_399:
F_89 ( V_21 -> V_2 , 1 << V_21 -> V_5 -> V_7 ) ;
V_398:
F_306 ( & V_21 -> V_390 ) ;
V_397:
V_5 -> V_387 ( V_21 ) ;
return V_276 ;
}
static long F_307 ( struct V_2 * V_13 , struct V_17 * V_17 ,
T_1 V_69 )
{
struct V_2 * V_3 ;
struct V_83 * V_84 ;
struct V_51 * V_50 = V_13 -> V_50 ;
int V_128 , V_276 ;
struct V_4 * V_5 ;
struct V_70 * V_71 = V_50 -> V_71 ;
V_3 = F_42 ( sizeof( * V_3 ) , V_56 ) ;
if ( ! V_3 )
return - V_57 ;
V_84 = F_64 ( V_17 ) ;
if ( ! V_84 ) {
V_276 = - V_57 ;
goto V_402;
}
F_98 ( V_3 -> V_84 , V_84 ) ;
if ( ! F_12 ( V_13 ) ) {
V_276 = - V_233 ;
goto V_403;
}
V_3 -> V_95 = F_135 ( & V_50 -> V_94 , NULL , 1 , 0 , V_56 ) ;
if ( V_3 -> V_95 < 0 ) {
V_276 = - V_57 ;
goto V_404;
}
F_31 ( & V_71 -> V_386 ) ;
F_112 ( V_3 ) ;
V_17 -> V_18 = V_3 ;
V_3 -> V_17 = V_17 ;
V_3 -> V_13 = V_13 ;
V_3 -> V_9 . V_13 = & V_13 -> V_9 ;
V_3 -> V_50 = V_13 -> V_50 ;
if ( F_8 ( V_13 ) )
F_26 ( V_16 , & V_3 -> V_11 ) ;
if ( F_5 ( V_133 , & V_13 -> V_11 ) )
F_26 ( V_133 , & V_3 -> V_11 ) ;
V_276 = F_213 ( V_17 , V_179 | V_69 , V_71 ) ;
if ( V_276 < 0 )
goto V_405;
F_49 ( & V_17 -> V_100 -> V_102 ) ;
V_3 -> V_317 = V_406 ++ ;
F_308 ( & V_3 -> V_154 , & V_3 -> V_13 -> V_155 ) ;
V_50 -> V_90 ++ ;
F_83 ( V_13 -> V_17 ) ;
F_309 ( & V_50 -> V_94 , V_3 , V_3 -> V_95 ) ;
V_276 = F_90 ( V_3 , V_199 , true ) ;
if ( V_276 )
goto V_407;
F_16 (ss, ssid) {
if ( V_50 -> V_52 & ( 1 << V_128 ) ) {
V_276 = F_303 ( V_3 , V_5 ) ;
if ( V_276 )
goto V_407;
}
}
F_14 ( & V_8 ) ;
F_14 ( & V_3 -> V_17 -> V_100 -> V_102 ) ;
return 0 ;
V_405:
F_78 ( & V_50 -> V_94 , V_3 -> V_95 ) ;
F_69 ( V_71 ) ;
V_404:
F_14 ( & V_8 ) ;
V_403:
F_28 ( F_72 ( V_3 -> V_84 ) ) ;
V_402:
F_28 ( V_3 ) ;
return V_276 ;
V_407:
F_310 ( V_3 ) ;
F_14 ( & V_8 ) ;
F_14 ( & V_17 -> V_100 -> V_102 ) ;
return V_276 ;
}
static int F_311 ( struct V_68 * V_298 , struct V_17 * V_17 , T_1 V_69 )
{
struct V_2 * V_408 = V_17 -> V_97 -> V_18 ;
return F_307 ( V_408 , V_17 , V_69 | V_179 ) ;
}
static void F_312 ( struct V_87 * V_88 )
{
struct V_1 * V_21 =
F_67 ( V_88 , struct V_1 , V_89 ) ;
struct V_2 * V_3 = V_21 -> V_2 ;
F_13 ( & V_8 ) ;
F_302 ( V_21 ) ;
if ( ! V_3 -> V_394 && F_4 ( V_3 ) )
F_313 ( V_3 ) ;
F_14 ( & V_8 ) ;
F_196 ( V_21 ) ;
}
static void F_314 ( struct V_388 * V_389 )
{
struct V_1 * V_21 =
F_67 ( V_389 , struct V_1 , V_390 ) ;
F_74 ( & V_21 -> V_89 , F_312 ) ;
F_75 ( V_93 , & V_21 -> V_89 ) ;
}
static void F_315 ( struct V_1 * V_21 )
{
F_89 ( V_21 -> V_2 , 1 << V_21 -> V_5 -> V_7 ) ;
F_305 ( V_21 ) ;
F_316 ( & V_21 -> V_390 , F_314 ) ;
}
static int F_310 ( struct V_2 * V_3 )
__releases( &cgroup_mutex
static void F_313 ( struct V_2 * V_3 )
{
struct V_2 * V_13 = V_3 -> V_13 ;
struct V_17 * V_99 = V_3 -> V_17 ;
F_49 ( & V_8 ) ;
F_317 ( & V_3 -> V_154 ) ;
F_68 ( V_99 ) ;
F_26 ( V_15 , & V_13 -> V_11 ) ;
F_27 ( V_13 ) ;
}
static int F_318 ( struct V_68 * V_409 , struct V_17 * V_17 )
{
int V_113 ;
F_13 ( & V_8 ) ;
V_113 = F_310 ( V_17 -> V_18 ) ;
F_14 ( & V_8 ) ;
return V_113 ;
}
static void T_7 F_319 ( struct V_4 * V_5 )
{
F_41 ( & V_5 -> V_307 ) ;
if ( V_5 -> V_410 ) {
struct V_20 * V_101 ;
for ( V_101 = V_5 -> V_410 ; V_101 -> V_84 [ 0 ] != '\0' ; V_101 ++ )
V_101 -> V_5 = V_5 ;
V_5 -> V_411 . V_105 = V_5 -> V_410 ;
F_47 ( & V_5 -> V_411 . V_98 , & V_5 -> V_307 ) ;
}
}
static void T_8 F_320 ( struct V_4 * V_5 )
{
struct V_1 * V_21 ;
F_321 ( V_412 L_36 , V_5 -> V_84 ) ;
F_13 ( & V_8 ) ;
F_319 ( V_5 ) ;
V_5 -> V_50 = & V_115 ;
V_21 = V_5 -> V_396 ( F_1 ( V_121 , V_5 ) ) ;
F_35 ( F_132 ( V_21 ) ) ;
F_300 ( V_21 , V_5 , V_121 ) ;
V_66 . V_6 [ V_5 -> V_7 ] = V_21 ;
V_413 |= V_5 -> V_414 || V_5 -> exit ;
F_35 ( ! F_25 ( & V_415 . V_60 ) ) ;
F_35 ( F_301 ( V_21 ) ) ;
F_14 ( & V_8 ) ;
F_35 ( V_5 -> V_118 ) ;
}
int T_7 F_322 ( struct V_4 * V_5 )
{
struct V_1 * V_21 ;
int V_23 , V_113 ;
struct V_416 * V_319 ;
struct V_24 * V_25 ;
unsigned long V_22 ;
if ( V_5 -> V_84 == NULL || strlen ( V_5 -> V_84 ) > V_299 ||
V_5 -> V_396 == NULL || V_5 -> V_387 == NULL )
return - V_143 ;
if ( V_5 -> V_414 || V_5 -> exit )
return - V_143 ;
if ( V_5 -> V_118 == NULL ) {
F_35 ( V_4 [ V_5 -> V_7 ] != V_5 ) ;
return 0 ;
}
F_319 ( V_5 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_114 ) ;
V_4 [ V_5 -> V_7 ] = V_5 ;
V_21 = V_5 -> V_396 ( F_1 ( V_121 , V_5 ) ) ;
if ( F_132 ( V_21 ) ) {
V_4 [ V_5 -> V_7 ] = NULL ;
F_14 ( & V_114 ) ;
F_14 ( & V_8 ) ;
return F_133 ( V_21 ) ;
}
V_5 -> V_50 = & V_115 ;
F_300 ( V_21 , V_5 , V_121 ) ;
F_19 ( & V_31 ) ;
F_323 (css_set_table, i, tmp, cset, hlist) {
if ( V_25 -> V_6 [ V_5 -> V_7 ] )
continue;
F_22 ( & V_25 -> V_32 ) ;
V_25 -> V_6 [ V_5 -> V_7 ] = V_21 ;
V_22 = F_15 ( V_25 -> V_6 ) ;
F_55 ( V_62 , & V_25 -> V_32 , V_22 ) ;
}
F_21 ( & V_31 ) ;
V_113 = F_301 ( V_21 ) ;
if ( V_113 ) {
V_5 -> V_387 ( V_21 ) ;
goto V_417;
}
F_14 ( & V_114 ) ;
F_14 ( & V_8 ) ;
return 0 ;
V_417:
F_14 ( & V_114 ) ;
F_14 ( & V_8 ) ;
F_324 ( V_5 ) ;
return V_113 ;
}
void F_324 ( struct V_4 * V_5 )
{
struct V_27 * V_28 ;
struct V_1 * V_21 ;
F_35 ( V_5 -> V_118 == NULL ) ;
F_35 ( V_5 -> V_50 != & V_115 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_114 ) ;
V_21 = F_1 ( V_121 , V_5 ) ;
if ( V_21 )
F_302 ( V_21 ) ;
V_4 [ V_5 -> V_7 ] = NULL ;
F_19 ( & V_31 ) ;
F_54 (link, &cgroup_dummy_top->cset_links, cset_link) {
struct V_24 * V_25 = V_28 -> V_25 ;
unsigned long V_22 ;
F_22 ( & V_25 -> V_32 ) ;
V_25 -> V_6 [ V_5 -> V_7 ] = NULL ;
V_22 = F_15 ( V_25 -> V_6 ) ;
F_55 ( V_62 , & V_25 -> V_32 , V_22 ) ;
}
F_21 ( & V_31 ) ;
if ( V_21 )
V_5 -> V_387 ( V_21 ) ;
F_99 ( V_121 -> V_6 [ V_5 -> V_7 ] , NULL ) ;
F_14 ( & V_114 ) ;
F_14 ( & V_8 ) ;
}
int T_8 F_325 ( void )
{
struct V_4 * V_5 ;
int V_23 ;
F_52 ( & V_66 . V_30 , 1 ) ;
F_41 ( & V_66 . V_44 ) ;
F_41 ( & V_66 . V_60 ) ;
F_53 ( & V_66 . V_32 ) ;
V_33 = 1 ;
F_115 ( & V_115 ) ;
V_59 = 1 ;
F_99 ( V_415 . V_219 , & V_66 ) ;
V_418 . V_25 = & V_66 ;
V_418 . V_3 = V_121 ;
F_43 ( & V_418 . V_34 , & V_121 -> V_36 ) ;
F_43 ( & V_418 . V_35 , & V_66 . V_44 ) ;
F_326 (ss, i) {
F_35 ( ! V_5 -> V_84 ) ;
F_35 ( strlen ( V_5 -> V_84 ) > V_299 ) ;
F_35 ( ! V_5 -> V_396 ) ;
F_35 ( ! V_5 -> V_387 ) ;
if ( V_5 -> V_7 != V_23 ) {
F_321 ( V_419 L_37 ,
V_5 -> V_84 , V_5 -> V_7 ) ;
F_327 () ;
}
if ( V_5 -> V_420 )
F_320 ( V_5 ) ;
}
return 0 ;
}
int T_8 F_328 ( void )
{
struct V_4 * V_5 ;
unsigned long V_22 ;
int V_23 , V_276 ;
V_276 = F_329 ( & V_82 ) ;
if ( V_276 )
return V_276 ;
F_326 (ss, i) {
if ( ! V_5 -> V_420 )
F_320 ( V_5 ) ;
}
F_13 ( & V_8 ) ;
F_13 ( & V_114 ) ;
V_22 = F_15 ( V_66 . V_6 ) ;
F_55 ( V_62 , & V_66 . V_32 , V_22 ) ;
F_35 ( F_117 ( & V_115 , 0 , 1 ) ) ;
V_276 = F_135 ( & V_115 . V_94 , V_121 ,
0 , 1 , V_56 ) ;
F_35 ( V_276 < 0 ) ;
F_14 ( & V_114 ) ;
F_14 ( & V_8 ) ;
V_421 = F_330 ( L_38 , V_422 ) ;
if ( ! V_421 ) {
V_276 = - V_57 ;
goto V_205;
}
V_276 = F_331 ( & V_423 ) ;
if ( V_276 < 0 ) {
F_332 ( V_421 ) ;
goto V_205;
}
F_333 ( L_39 , 0 , NULL , & V_424 ) ;
V_205:
if ( V_276 )
F_334 ( & V_82 ) ;
return V_276 ;
}
static int T_8 F_335 ( void )
{
V_93 = F_336 ( L_40 , 0 , 1 ) ;
F_35 ( ! V_93 ) ;
V_347 = F_336 ( L_41 ,
0 , 1 ) ;
F_35 ( ! V_347 ) ;
return 0 ;
}
int F_337 ( struct V_124 * V_269 , void * V_249 )
{
struct V_231 * V_231 ;
struct V_63 * V_216 ;
char * V_202 ;
int V_222 ;
struct V_51 * V_50 ;
V_222 = - V_57 ;
V_202 = F_65 ( V_338 , V_56 ) ;
if ( ! V_202 )
goto V_205;
V_222 = - V_235 ;
V_231 = V_269 -> V_265 ;
V_216 = F_338 ( V_231 , V_425 ) ;
if ( ! V_216 )
goto V_260;
V_222 = 0 ;
F_13 ( & V_8 ) ;
F_136 (root) {
struct V_4 * V_5 ;
struct V_2 * V_3 ;
int V_128 , V_54 = 0 ;
F_102 ( V_269 , L_42 , V_50 -> V_165 ) ;
F_16 (ss, ssid)
if ( V_50 -> V_52 & ( 1 << V_128 ) )
F_102 ( V_269 , L_43 , V_54 ++ ? L_9 : L_24 , V_5 -> V_84 ) ;
if ( strlen ( V_50 -> V_84 ) )
F_102 ( V_269 , L_44 , V_54 ? L_9 : L_24 ,
V_50 -> V_84 ) ;
F_179 ( V_269 , ':' ) ;
V_3 = F_56 ( V_216 , V_50 ) ;
V_222 = F_143 ( V_3 , V_202 , V_338 ) ;
if ( V_222 < 0 )
goto V_150;
F_103 ( V_269 , V_202 ) ;
F_179 ( V_269 , '\n' ) ;
}
V_150:
F_14 ( & V_8 ) ;
F_171 ( V_216 ) ;
V_260:
F_28 ( V_202 ) ;
V_205:
return V_222 ;
}
static int F_339 ( struct V_124 * V_269 , void * V_249 )
{
struct V_4 * V_5 ;
int V_23 ;
F_103 ( V_269 , L_45 ) ;
F_13 ( & V_8 ) ;
F_16 (ss, i)
F_102 ( V_269 , L_46 ,
V_5 -> V_84 , V_5 -> V_50 -> V_165 ,
V_5 -> V_50 -> V_90 , ! V_5 -> V_149 ) ;
F_14 ( & V_8 ) ;
return 0 ;
}
static int F_340 ( struct V_68 * V_68 , struct V_250 * V_250 )
{
return F_341 ( V_250 , F_339 , NULL ) ;
}
void F_342 ( struct V_63 * V_426 )
{
F_155 ( V_151 ) ;
F_30 ( F_58 ( V_151 ) ) ;
V_426 -> V_219 = V_151 -> V_219 ;
F_156 ( V_151 ) ;
F_41 ( & V_426 -> V_220 ) ;
}
void F_343 ( struct V_63 * V_426 )
{
struct V_4 * V_5 ;
int V_23 ;
if ( V_310 ) {
F_19 ( & V_31 ) ;
F_155 ( V_426 ) ;
if ( F_25 ( & V_426 -> V_220 ) )
F_43 ( & V_426 -> V_220 , & F_58 ( V_426 ) -> V_60 ) ;
F_156 ( V_426 ) ;
F_21 ( & V_31 ) ;
}
if ( V_413 ) {
F_326 (ss, i)
if ( V_5 -> V_414 )
V_5 -> V_414 ( V_426 ) ;
}
}
void F_344 ( struct V_63 * V_216 , int V_427 )
{
struct V_4 * V_5 ;
struct V_24 * V_25 ;
int V_23 ;
if ( ! F_25 ( & V_216 -> V_220 ) ) {
F_19 ( & V_31 ) ;
if ( ! F_25 ( & V_216 -> V_220 ) )
F_88 ( & V_216 -> V_220 ) ;
F_21 ( & V_31 ) ;
}
F_155 ( V_216 ) ;
V_25 = F_58 ( V_216 ) ;
F_99 ( V_216 -> V_219 , & V_66 ) ;
if ( V_427 && V_413 ) {
F_326 (ss, i) {
if ( V_5 -> exit ) {
struct V_1 * V_428 = V_25 -> V_6 [ V_23 ] ;
struct V_1 * V_21 = F_345 ( V_216 , V_23 ) ;
V_5 -> exit ( V_21 , V_428 , V_216 ) ;
}
}
}
F_156 ( V_216 ) ;
F_33 ( V_25 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
if ( F_7 ( V_3 ) &&
F_25 ( & V_3 -> V_36 ) && F_25 ( & V_3 -> V_155 ) ) {
int V_429 = 0 ;
F_346 ( & V_430 ) ;
if ( ! F_4 ( V_3 ) &&
F_25 ( & V_3 -> V_157 ) ) {
F_43 ( & V_3 -> V_157 , & V_157 ) ;
V_429 = 1 ;
}
F_347 ( & V_430 ) ;
if ( V_429 )
F_348 ( & V_431 ) ;
}
}
static void F_349 ( struct V_87 * V_88 )
{
F_35 ( V_88 != & V_431 ) ;
F_13 ( & V_8 ) ;
F_346 ( & V_430 ) ;
while ( ! F_25 ( & V_157 ) ) {
char * V_432 [ 3 ] , * V_433 [ 3 ] ;
int V_23 ;
char * V_434 = NULL , * V_435 = NULL ;
struct V_2 * V_3 = F_36 ( V_157 . V_49 ,
struct V_2 ,
V_157 ) ;
F_88 ( & V_3 -> V_157 ) ;
F_347 ( & V_430 ) ;
V_434 = F_65 ( V_338 , V_56 ) ;
if ( ! V_434 )
goto V_436;
if ( F_143 ( V_3 , V_434 , V_338 ) < 0 )
goto V_436;
V_435 = F_350 ( V_3 -> V_50 -> V_132 , V_56 ) ;
if ( ! V_435 )
goto V_436;
V_23 = 0 ;
V_432 [ V_23 ++ ] = V_435 ;
V_432 [ V_23 ++ ] = V_434 ;
V_432 [ V_23 ] = NULL ;
V_23 = 0 ;
V_433 [ V_23 ++ ] = L_47 ;
V_433 [ V_23 ++ ] = L_48 ;
V_433 [ V_23 ] = NULL ;
F_14 ( & V_8 ) ;
F_351 ( V_432 [ 0 ] , V_432 , V_433 , V_437 ) ;
F_13 ( & V_8 ) ;
V_436:
F_28 ( V_434 ) ;
F_28 ( V_435 ) ;
F_346 ( & V_430 ) ;
}
F_347 ( & V_430 ) ;
F_14 ( & V_8 ) ;
}
static int T_8 F_352 ( char * V_438 )
{
struct V_4 * V_5 ;
char * V_137 ;
int V_23 ;
while ( ( V_137 = F_106 ( & V_438 , L_9 ) ) != NULL ) {
if ( ! * V_137 )
continue;
F_326 (ss, i) {
if ( ! strcmp ( V_137 , V_5 -> V_84 ) ) {
V_5 -> V_149 = 1 ;
F_321 ( V_412 L_49
L_50 , V_5 -> V_84 ) ;
break;
}
}
}
return 1 ;
}
struct V_1 * F_353 ( struct V_17 * V_17 ,
struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_233 () ;
if ( ! V_17 -> V_100 ||
V_17 -> V_100 -> V_185 != & V_186 )
return F_122 ( - V_439 ) ;
V_3 = F_9 ( V_17 ) ;
return F_1 ( V_3 , V_5 ) ? : F_122 ( - V_119 ) ;
}
struct V_1 * F_354 ( int V_95 , struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_233 () ;
V_3 = F_355 ( & V_5 -> V_50 -> V_94 , V_95 ) ;
if ( V_3 )
return F_1 ( V_3 , V_5 ) ;
return NULL ;
}
static struct V_1 *
F_356 ( struct V_1 * V_315 )
{
struct V_1 * V_21 = F_42 ( sizeof( * V_21 ) , V_56 ) ;
if ( ! V_21 )
return F_122 ( - V_57 ) ;
return V_21 ;
}
static void F_357 ( struct V_1 * V_21 )
{
F_28 ( V_21 ) ;
}
static T_3 F_358 ( struct V_1 * V_21 ,
struct V_20 * V_101 )
{
return F_225 ( V_21 -> V_2 ) ;
}
static T_3 F_359 ( struct V_1 * V_21 ,
struct V_20 * V_101 )
{
return ( T_3 ) ( unsigned long ) V_151 -> V_219 ;
}
static T_3 F_360 ( struct V_1 * V_21 ,
struct V_20 * V_101 )
{
T_3 V_54 ;
F_145 () ;
V_54 = F_226 ( & F_58 ( V_151 ) -> V_30 ) ;
F_146 () ;
return V_54 ;
}
static int F_361 ( struct V_124 * V_125 , void * V_249 )
{
struct V_27 * V_28 ;
struct V_24 * V_25 ;
F_50 ( & V_31 ) ;
F_145 () ;
V_25 = F_362 ( V_151 -> V_219 ) ;
F_54 (link, &cset->cgrp_links, cgrp_link) {
struct V_2 * V_61 = V_28 -> V_3 ;
const char * V_84 ;
if ( V_61 -> V_17 )
V_84 = V_61 -> V_17 -> V_85 . V_84 ;
else
V_84 = L_51 ;
F_102 ( V_125 , L_52 ,
V_61 -> V_50 -> V_165 , V_84 ) ;
}
F_146 () ;
F_51 ( & V_31 ) ;
return 0 ;
}
static int F_363 ( struct V_124 * V_125 , void * V_249 )
{
struct V_1 * V_21 = F_178 ( V_125 ) ;
struct V_27 * V_28 ;
F_50 ( & V_31 ) ;
F_54 (link, &css->cgroup->cset_links, cset_link) {
struct V_24 * V_25 = V_28 -> V_25 ;
struct V_63 * V_64 ;
int V_54 = 0 ;
F_102 ( V_125 , L_53 , V_25 ) ;
F_54 (task, &cset->tasks, cg_list) {
if ( V_54 ++ > V_440 ) {
F_103 ( V_125 , L_54 ) ;
break;
} else {
F_102 ( V_125 , L_55 ,
F_283 ( V_64 ) ) ;
}
}
}
F_51 ( & V_31 ) ;
return 0 ;
}
static T_3 F_364 ( struct V_1 * V_21 , struct V_20 * V_101 )
{
return F_5 ( V_15 , & V_21 -> V_2 -> V_11 ) ;
}
