static int F_1 ( struct V_1 * V_1 , void * V_2 , int V_3 , int V_4 ,
T_1 V_5 )
{
int V_6 ;
F_2 ( V_5 ) ;
F_3 ( & V_7 ) ;
V_6 = F_4 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_5 ( & V_7 ) ;
F_6 () ;
return V_6 ;
}
static void * F_7 ( struct V_1 * V_1 , void * V_2 , int V_8 )
{
void * V_6 ;
F_3 ( & V_7 ) ;
V_6 = F_8 ( V_1 , V_2 , V_8 ) ;
F_5 ( & V_7 ) ;
return V_6 ;
}
static void F_9 ( struct V_1 * V_1 , int V_8 )
{
F_3 ( & V_7 ) ;
F_10 ( V_1 , V_8 ) ;
F_5 ( & V_7 ) ;
}
static struct V_9 * F_11 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
if ( V_12 )
return F_12 ( V_12 , struct V_9 , V_13 ) ;
return NULL ;
}
static struct V_11 * F_13 ( struct V_9 * V_10 ,
struct V_15 * V_16 )
{
if ( V_16 )
return F_14 ( V_10 -> V_17 [ V_16 -> V_8 ] ,
F_15 ( & V_18 ) ) ;
else
return & V_10 -> V_13 ;
}
static struct V_11 * F_16 ( struct V_9 * V_10 ,
struct V_15 * V_16 )
{
F_17 ( & V_18 ) ;
if ( ! V_16 )
return & V_10 -> V_13 ;
if ( ! ( V_10 -> V_19 -> V_20 & ( 1 << V_16 -> V_8 ) ) )
return NULL ;
while ( F_11 ( V_10 ) &&
! ( F_11 ( V_10 ) -> V_21 & ( 1 << V_16 -> V_8 ) ) )
V_10 = F_11 ( V_10 ) ;
return F_13 ( V_10 , V_16 ) ;
}
struct V_11 * F_18 ( struct V_9 * V_10 ,
struct V_15 * V_16 )
{
struct V_11 * V_22 ;
F_19 () ;
do {
V_22 = F_13 ( V_10 , V_16 ) ;
if ( V_22 && F_20 ( V_22 ) )
goto V_23;
V_10 = F_11 ( V_10 ) ;
} while ( V_10 );
V_22 = V_24 . V_17 [ V_16 -> V_8 ] ;
F_21 ( V_22 ) ;
V_23:
F_22 () ;
return V_22 ;
}
static inline bool F_23 ( const struct V_9 * V_10 )
{
return ! ( V_10 -> V_13 . V_25 & V_26 ) ;
}
struct V_11 * F_24 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_29 -> V_14 -> V_30 ;
struct V_31 * V_32 = F_25 ( V_28 ) ;
if ( V_32 -> V_16 )
return F_26 ( V_10 -> V_17 [ V_32 -> V_16 -> V_8 ] ) ;
else
return & V_10 -> V_13 ;
}
bool F_27 ( struct V_9 * V_10 , struct V_9 * V_33 )
{
while ( V_10 ) {
if ( V_10 == V_33 )
return true ;
V_10 = F_11 ( V_10 ) ;
}
return false ;
}
static int F_28 ( const struct V_9 * V_10 )
{
return F_29 ( V_34 , & V_10 -> V_25 ) ;
}
static void F_30 ( struct V_9 * V_10 , bool V_35 )
{
F_17 ( & V_36 ) ;
do {
bool V_37 ;
if ( V_35 )
V_37 = ! V_10 -> V_38 ++ ;
else
V_37 = ! -- V_10 -> V_38 ;
if ( ! V_37 )
break;
if ( V_10 -> V_39 )
F_31 ( V_10 -> V_39 ) ;
V_10 = F_11 ( V_10 ) ;
} while ( V_10 );
}
static unsigned long F_32 ( struct V_11 * V_22 [] )
{
unsigned long V_40 = 0UL ;
struct V_15 * V_16 ;
int V_41 ;
F_33 (ss, i)
V_40 += ( unsigned long ) V_22 [ V_41 ] ;
V_40 = ( V_40 >> 16 ) ^ V_40 ;
return V_40 ;
}
static void F_34 ( struct V_42 * V_43 )
{
struct V_44 * V_45 , * V_46 ;
struct V_15 * V_16 ;
int V_47 ;
F_17 ( & V_36 ) ;
if ( ! F_35 ( & V_43 -> V_48 ) )
return;
F_33 (ss, ssid)
F_36 ( & V_43 -> V_49 [ V_47 ] ) ;
F_37 ( & V_43 -> V_50 ) ;
V_51 -- ;
F_38 (link, tmp_link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_10 = V_45 -> V_10 ;
F_36 ( & V_45 -> V_52 ) ;
F_36 ( & V_45 -> V_53 ) ;
if ( F_39 ( & V_10 -> V_54 ) ) {
F_30 ( V_10 , false ) ;
F_40 ( V_10 ) ;
}
F_41 ( V_45 ) ;
}
F_42 ( V_43 , V_55 ) ;
}
static void F_43 ( struct V_42 * V_43 )
{
if ( F_44 ( & V_43 -> V_48 , - 1 , 1 ) )
return;
F_45 ( & V_36 ) ;
F_34 ( V_43 ) ;
F_46 ( & V_36 ) ;
}
static inline void F_47 ( struct V_42 * V_43 )
{
F_48 ( & V_43 -> V_48 ) ;
}
static bool F_49 ( struct V_42 * V_43 ,
struct V_42 * V_56 ,
struct V_9 * V_57 ,
struct V_11 * V_58 [] )
{
struct V_59 * V_60 , * V_61 ;
if ( memcmp ( V_58 , V_43 -> V_17 , sizeof( V_43 -> V_17 ) ) )
return false ;
V_60 = & V_43 -> V_62 ;
V_61 = & V_56 -> V_62 ;
while ( 1 ) {
struct V_44 * V_63 , * V_64 ;
struct V_9 * V_65 , * V_66 ;
V_60 = V_60 -> V_67 ;
V_61 = V_61 -> V_67 ;
if ( V_60 == & V_43 -> V_62 ) {
F_50 ( V_61 != & V_56 -> V_62 ) ;
break;
} else {
F_50 ( V_61 == & V_56 -> V_62 ) ;
}
V_63 = F_51 ( V_60 , struct V_44 , V_53 ) ;
V_64 = F_51 ( V_61 , struct V_44 , V_53 ) ;
V_65 = V_63 -> V_10 ;
V_66 = V_64 -> V_10 ;
F_50 ( V_65 -> V_19 != V_66 -> V_19 ) ;
if ( V_65 -> V_19 == V_57 -> V_19 ) {
if ( V_65 != V_57 )
return false ;
} else {
if ( V_65 != V_66 )
return false ;
}
}
return true ;
}
static struct V_42 * F_52 ( struct V_42 * V_56 ,
struct V_9 * V_10 ,
struct V_11 * V_58 [] )
{
struct V_68 * V_19 = V_10 -> V_19 ;
struct V_15 * V_16 ;
struct V_42 * V_43 ;
unsigned long V_40 ;
int V_41 ;
F_33 (ss, i) {
if ( V_19 -> V_20 & ( 1UL << V_41 ) ) {
V_58 [ V_41 ] = F_16 ( V_10 , V_16 ) ;
} else {
V_58 [ V_41 ] = V_56 -> V_17 [ V_41 ] ;
}
}
V_40 = F_32 ( V_58 ) ;
F_53 (css_set_table, cset, hlist, key) {
if ( ! F_49 ( V_43 , V_56 , V_10 , V_58 ) )
continue;
return V_43 ;
}
return NULL ;
}
static void F_54 ( struct V_59 * V_69 )
{
struct V_44 * V_45 , * V_46 ;
F_38 (link, tmp_link, links_to_free, cset_link) {
F_36 ( & V_45 -> V_52 ) ;
F_41 ( V_45 ) ;
}
}
static int F_55 ( int V_70 , struct V_59 * V_71 )
{
struct V_44 * V_45 ;
int V_41 ;
F_56 ( V_71 ) ;
for ( V_41 = 0 ; V_41 < V_70 ; V_41 ++ ) {
V_45 = F_57 ( sizeof( * V_45 ) , V_72 ) ;
if ( ! V_45 ) {
F_54 ( V_71 ) ;
return - V_73 ;
}
F_58 ( & V_45 -> V_52 , V_71 ) ;
}
return 0 ;
}
static void F_59 ( struct V_59 * V_71 , struct V_42 * V_43 ,
struct V_9 * V_10 )
{
struct V_44 * V_45 ;
F_50 ( F_39 ( V_71 ) ) ;
if ( F_60 ( V_10 ) )
V_43 -> V_74 = V_10 ;
V_45 = F_61 ( V_71 , struct V_44 , V_52 ) ;
V_45 -> V_43 = V_43 ;
V_45 -> V_10 = V_10 ;
if ( F_39 ( & V_10 -> V_54 ) )
F_30 ( V_10 , true ) ;
F_62 ( & V_45 -> V_52 , & V_10 -> V_54 ) ;
F_63 ( & V_45 -> V_53 , & V_43 -> V_62 ) ;
}
static struct V_42 * F_64 ( struct V_42 * V_56 ,
struct V_9 * V_10 )
{
struct V_11 * V_58 [ V_75 ] = { } ;
struct V_42 * V_43 ;
struct V_59 V_71 ;
struct V_44 * V_45 ;
struct V_15 * V_16 ;
unsigned long V_40 ;
int V_47 ;
F_17 ( & V_18 ) ;
F_65 ( & V_36 ) ;
V_43 = F_52 ( V_56 , V_10 , V_58 ) ;
if ( V_43 )
F_47 ( V_43 ) ;
F_66 ( & V_36 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_57 ( sizeof( * V_43 ) , V_72 ) ;
if ( ! V_43 )
return NULL ;
if ( F_55 ( V_76 , & V_71 ) < 0 ) {
F_41 ( V_43 ) ;
return NULL ;
}
F_67 ( & V_43 -> V_48 , 1 ) ;
F_56 ( & V_43 -> V_62 ) ;
F_56 ( & V_43 -> V_77 ) ;
F_56 ( & V_43 -> V_78 ) ;
F_56 ( & V_43 -> V_79 ) ;
F_56 ( & V_43 -> V_80 ) ;
F_68 ( & V_43 -> V_50 ) ;
memcpy ( V_43 -> V_17 , V_58 , sizeof( V_43 -> V_17 ) ) ;
F_45 ( & V_36 ) ;
F_69 (link, &old_cset->cgrp_links, cgrp_link) {
struct V_9 * V_81 = V_45 -> V_10 ;
if ( V_81 -> V_19 == V_10 -> V_19 )
V_81 = V_10 ;
F_59 ( & V_71 , V_43 , V_81 ) ;
}
F_50 ( ! F_39 ( & V_71 ) ) ;
V_51 ++ ;
V_40 = F_32 ( V_43 -> V_17 ) ;
F_70 ( V_82 , & V_43 -> V_50 , V_40 ) ;
F_33 (ss, ssid)
F_63 ( & V_43 -> V_49 [ V_47 ] ,
& V_43 -> V_17 [ V_47 ] -> V_9 -> V_83 [ V_47 ] ) ;
F_46 ( & V_36 ) ;
return V_43 ;
}
static struct V_68 * F_71 ( struct V_84 * V_85 )
{
struct V_9 * V_86 = V_85 -> V_29 -> V_30 ;
return V_86 -> V_19 ;
}
static int F_72 ( struct V_68 * V_19 )
{
int V_8 ;
F_17 ( & V_18 ) ;
V_8 = F_73 ( & V_87 , V_19 , 0 , 0 , V_72 ) ;
if ( V_8 < 0 )
return V_8 ;
V_19 -> V_88 = V_8 ;
return 0 ;
}
static void F_74 ( struct V_68 * V_19 )
{
F_17 ( & V_18 ) ;
if ( V_19 -> V_88 ) {
F_10 ( & V_87 , V_19 -> V_88 ) ;
V_19 -> V_88 = 0 ;
}
}
static void F_75 ( struct V_68 * V_19 )
{
if ( V_19 ) {
F_76 ( V_19 -> V_88 ) ;
F_77 ( & V_19 -> V_89 ) ;
F_41 ( V_19 ) ;
}
}
static void F_78 ( struct V_68 * V_19 )
{
struct V_9 * V_10 = & V_19 -> V_10 ;
struct V_44 * V_45 , * V_46 ;
F_79 ( & V_18 ) ;
F_50 ( F_80 ( & V_19 -> V_90 ) ) ;
F_50 ( ! F_39 ( & V_10 -> V_13 . V_91 ) ) ;
F_81 ( & V_92 , V_19 -> V_20 ) ;
F_45 ( & V_36 ) ;
F_38 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_36 ( & V_45 -> V_52 ) ;
F_36 ( & V_45 -> V_53 ) ;
F_41 ( V_45 ) ;
}
F_46 ( & V_36 ) ;
if ( ! F_39 ( & V_19 -> V_93 ) ) {
F_36 ( & V_19 -> V_93 ) ;
V_76 -- ;
}
F_74 ( V_19 ) ;
F_82 ( & V_18 ) ;
F_83 ( V_19 -> V_85 ) ;
F_75 ( V_19 ) ;
}
static struct V_9 * F_84 ( struct V_42 * V_43 ,
struct V_68 * V_19 )
{
struct V_9 * V_94 = NULL ;
F_17 ( & V_18 ) ;
F_17 ( & V_36 ) ;
if ( V_43 == & V_24 ) {
V_94 = & V_19 -> V_10 ;
} else {
struct V_44 * V_45 ;
F_69 (link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_81 = V_45 -> V_10 ;
if ( V_81 -> V_19 == V_19 ) {
V_94 = V_81 ;
break;
}
}
}
F_50 ( ! V_94 ) ;
return V_94 ;
}
static struct V_9 * F_85 ( struct V_95 * V_96 ,
struct V_68 * V_19 )
{
return F_84 ( F_86 ( V_96 ) , V_19 ) ;
}
static char * F_87 ( struct V_9 * V_10 , const struct V_31 * V_32 ,
char * V_97 )
{
if ( V_32 -> V_16 && ! ( V_32 -> V_25 & V_98 ) &&
! ( V_10 -> V_19 -> V_25 & V_99 ) )
snprintf ( V_97 , V_100 , L_1 ,
V_32 -> V_16 -> V_101 , V_32 -> V_101 ) ;
else
strncpy ( V_97 , V_32 -> V_101 , V_100 ) ;
return V_97 ;
}
static T_2 F_88 ( const struct V_31 * V_32 )
{
T_2 V_102 = 0 ;
if ( V_32 -> V_102 )
return V_32 -> V_102 ;
if ( V_32 -> V_103 || V_32 -> V_104 || V_32 -> V_105 )
V_102 |= V_106 ;
if ( V_32 -> V_107 || V_32 -> V_108 || V_32 -> V_109 )
V_102 |= V_110 ;
return V_102 ;
}
static void F_89 ( struct V_9 * V_10 )
{
F_76 ( F_23 ( V_10 ) ) ;
F_21 ( & V_10 -> V_13 ) ;
}
static bool F_90 ( struct V_9 * V_10 )
{
return F_91 ( & V_10 -> V_13 ) ;
}
static void F_92 ( struct V_9 * V_10 )
{
F_93 ( & V_10 -> V_13 ) ;
}
static unsigned int F_94 ( struct V_9 * V_10 ,
unsigned int V_111 )
{
struct V_9 * V_14 = F_11 ( V_10 ) ;
unsigned int V_112 = V_111 ;
struct V_15 * V_16 ;
int V_47 ;
F_17 ( & V_18 ) ;
if ( ! F_60 ( V_10 ) )
return V_112 ;
while ( true ) {
unsigned int V_113 = V_112 ;
F_33 (ss, ssid)
if ( V_112 & ( 1 << V_47 ) )
V_113 |= V_16 -> V_114 ;
if ( V_14 )
V_113 &= V_14 -> V_21 ;
else
V_113 &= V_10 -> V_19 -> V_20 ;
if ( V_113 == V_112 )
break;
V_112 = V_113 ;
}
return V_112 ;
}
static void F_95 ( struct V_9 * V_10 )
{
V_10 -> V_21 =
F_94 ( V_10 , V_10 -> V_111 ) ;
}
static void F_96 ( struct V_115 * V_29 )
{
struct V_9 * V_10 ;
if ( F_97 ( V_29 ) == V_116 )
V_10 = V_29 -> V_30 ;
else
V_10 = V_29 -> V_14 -> V_30 ;
F_82 ( & V_18 ) ;
F_98 ( V_29 ) ;
F_92 ( V_10 ) ;
}
static struct V_9 * F_99 ( struct V_115 * V_29 )
{
struct V_9 * V_10 ;
if ( F_97 ( V_29 ) == V_116 )
V_10 = V_29 -> V_30 ;
else
V_10 = V_29 -> V_14 -> V_30 ;
if ( ! F_90 ( V_10 ) )
return NULL ;
F_100 ( V_29 ) ;
F_79 ( & V_18 ) ;
if ( ! F_23 ( V_10 ) )
return V_10 ;
F_96 ( V_29 ) ;
return NULL ;
}
static void F_101 ( struct V_9 * V_10 , const struct V_31 * V_32 )
{
char V_101 [ V_100 ] ;
F_17 ( & V_18 ) ;
F_102 ( V_10 -> V_29 , F_87 ( V_10 , V_32 , V_101 ) ) ;
}
static void F_103 ( struct V_9 * V_10 , unsigned int V_20 )
{
struct V_15 * V_16 ;
int V_41 ;
F_33 (ss, i) {
struct V_31 * V_117 ;
if ( ! ( V_20 & ( 1 << V_41 ) ) )
continue;
F_69 (cfts, &ss->cfts, node)
F_104 ( V_10 , V_117 , false ) ;
}
}
static int F_81 ( struct V_68 * V_118 , unsigned int V_119 )
{
struct V_15 * V_16 ;
unsigned int V_120 ;
int V_47 , V_41 , V_6 ;
F_17 ( & V_18 ) ;
F_33 (ss, ssid) {
if ( ! ( V_119 & ( 1 << V_47 ) ) )
continue;
if ( F_105 ( NULL , F_13 ( & V_16 -> V_19 -> V_10 , V_16 ) ) )
return - V_121 ;
if ( V_16 -> V_19 != & V_92 && V_118 != & V_92 )
return - V_121 ;
}
V_120 = V_119 ;
if ( V_118 == & V_92 )
V_120 &= ~ V_122 ;
V_6 = F_106 ( & V_118 -> V_10 , V_120 ) ;
if ( V_6 ) {
if ( V_118 != & V_92 )
return V_6 ;
if ( V_123 ) {
F_107 ( L_2 ,
V_6 , V_119 ) ;
F_107 ( L_3 ) ;
}
}
F_33 (ss, ssid)
if ( V_119 & ( 1 << V_47 ) )
F_103 ( & V_16 -> V_19 -> V_10 , 1 << V_47 ) ;
F_33 (ss, ssid) {
struct V_68 * V_124 ;
struct V_11 * V_22 ;
struct V_42 * V_43 ;
if ( ! ( V_119 & ( 1 << V_47 ) ) )
continue;
V_124 = V_16 -> V_19 ;
V_22 = F_13 ( & V_124 -> V_10 , V_16 ) ;
F_108 ( ! V_22 || F_13 ( & V_118 -> V_10 , V_16 ) ) ;
F_109 ( V_124 -> V_10 . V_17 [ V_47 ] , NULL ) ;
F_110 ( V_118 -> V_10 . V_17 [ V_47 ] , V_22 ) ;
V_16 -> V_19 = V_118 ;
V_22 -> V_9 = & V_118 -> V_10 ;
F_45 ( & V_36 ) ;
F_111 (css_set_table, i, cset, hlist)
F_112 ( & V_43 -> V_49 [ V_16 -> V_8 ] ,
& V_118 -> V_10 . V_83 [ V_16 -> V_8 ] ) ;
F_46 ( & V_36 ) ;
V_124 -> V_20 &= ~ ( 1 << V_47 ) ;
V_124 -> V_10 . V_111 &= ~ ( 1 << V_47 ) ;
F_95 ( & V_124 -> V_10 ) ;
V_118 -> V_20 |= 1 << V_47 ;
if ( V_118 != & V_92 ) {
V_118 -> V_10 . V_111 |= 1 << V_47 ;
F_95 ( & V_118 -> V_10 ) ;
}
if ( V_16 -> V_125 )
V_16 -> V_125 ( V_22 ) ;
}
F_113 ( V_118 -> V_10 . V_29 ) ;
return 0 ;
}
static int F_114 ( struct V_126 * V_127 ,
struct V_84 * V_85 )
{
struct V_68 * V_19 = F_71 ( V_85 ) ;
struct V_15 * V_16 ;
int V_47 ;
F_33 (ss, ssid)
if ( V_19 -> V_20 & ( 1 << V_47 ) )
F_115 ( V_127 , L_4 , V_16 -> V_101 ) ;
if ( V_19 -> V_25 & V_99 )
F_116 ( V_127 , L_5 ) ;
if ( V_19 -> V_25 & V_128 )
F_116 ( V_127 , L_6 ) ;
F_117 ( & V_129 ) ;
if ( strlen ( V_19 -> V_130 ) )
F_115 ( V_127 , L_7 , V_19 -> V_130 ) ;
F_118 ( & V_129 ) ;
if ( F_29 ( V_131 , & V_19 -> V_10 . V_25 ) )
F_116 ( V_127 , L_8 ) ;
if ( strlen ( V_19 -> V_101 ) )
F_115 ( V_127 , L_9 , V_19 -> V_101 ) ;
return 0 ;
}
static int F_119 ( char * V_132 , struct V_133 * V_134 )
{
char * V_135 , * V_136 = V_132 ;
bool V_137 = false , V_138 = false ;
unsigned int V_139 = - 1U ;
struct V_15 * V_16 ;
int V_140 = 0 ;
int V_41 ;
#ifdef F_120
V_139 = ~ ( 1U << V_141 ) ;
#endif
memset ( V_134 , 0 , sizeof( * V_134 ) ) ;
while ( ( V_135 = F_121 ( & V_136 , L_10 ) ) != NULL ) {
V_140 ++ ;
if ( ! * V_135 )
return - V_142 ;
if ( ! strcmp ( V_135 , L_11 ) ) {
V_134 -> V_143 = true ;
continue;
}
if ( ! strcmp ( V_135 , L_12 ) ) {
if ( V_138 )
return - V_142 ;
V_137 = true ;
continue;
}
if ( ! strcmp ( V_135 , L_13 ) ) {
V_134 -> V_25 |= V_144 ;
continue;
}
if ( ! strcmp ( V_135 , L_14 ) ) {
V_134 -> V_25 |= V_99 ;
continue;
}
if ( ! strcmp ( V_135 , L_15 ) ) {
V_134 -> V_145 = true ;
continue;
}
if ( ! strcmp ( V_135 , L_16 ) ) {
V_134 -> V_25 |= V_128 ;
continue;
}
if ( ! strncmp ( V_135 , L_17 , 14 ) ) {
if ( V_134 -> V_146 )
return - V_142 ;
V_134 -> V_146 =
F_122 ( V_135 + 14 , V_147 - 1 , V_72 ) ;
if ( ! V_134 -> V_146 )
return - V_73 ;
continue;
}
if ( ! strncmp ( V_135 , L_18 , 5 ) ) {
const char * V_101 = V_135 + 5 ;
if ( ! strlen ( V_101 ) )
return - V_142 ;
for ( V_41 = 0 ; V_41 < strlen ( V_101 ) ; V_41 ++ ) {
char V_81 = V_101 [ V_41 ] ;
if ( isalnum ( V_81 ) )
continue;
if ( ( V_81 == '.' ) || ( V_81 == '-' ) || ( V_81 == '_' ) )
continue;
return - V_142 ;
}
if ( V_134 -> V_101 )
return - V_142 ;
V_134 -> V_101 = F_122 ( V_101 ,
V_148 - 1 ,
V_72 ) ;
if ( ! V_134 -> V_101 )
return - V_73 ;
continue;
}
F_33 (ss, i) {
if ( strcmp ( V_135 , V_16 -> V_101 ) )
continue;
if ( V_16 -> V_149 )
continue;
if ( V_137 )
return - V_142 ;
V_134 -> V_20 |= ( 1 << V_41 ) ;
V_138 = true ;
break;
}
if ( V_41 == V_75 )
return - V_150 ;
}
if ( V_134 -> V_25 & V_144 ) {
F_107 ( L_19 ) ;
if ( V_140 != 1 ) {
F_123 ( L_20 ) ;
return - V_142 ;
}
return 0 ;
}
if ( V_137 || ( ! V_138 && ! V_134 -> V_143 && ! V_134 -> V_101 ) )
F_33 (ss, i)
if ( ! V_16 -> V_149 )
V_134 -> V_20 |= ( 1 << V_41 ) ;
if ( ! V_134 -> V_20 && ! V_134 -> V_101 )
return - V_142 ;
if ( ( V_134 -> V_25 & V_99 ) && ( V_134 -> V_20 & V_139 ) )
return - V_142 ;
if ( V_134 -> V_20 && V_134 -> V_143 )
return - V_142 ;
return 0 ;
}
static int F_124 ( struct V_84 * V_85 , int * V_25 , char * V_132 )
{
int V_6 = 0 ;
struct V_68 * V_19 = F_71 ( V_85 ) ;
struct V_133 V_134 ;
unsigned int V_151 , V_152 ;
if ( V_19 == & V_92 ) {
F_123 ( L_21 ) ;
return - V_142 ;
}
F_79 ( & V_18 ) ;
V_6 = F_119 ( V_132 , & V_134 ) ;
if ( V_6 )
goto V_23;
if ( V_134 . V_20 != V_19 -> V_20 || V_134 . V_146 )
F_107 ( L_22 ,
F_125 ( V_153 ) , V_153 -> V_154 ) ;
V_151 = V_134 . V_20 & ~ V_19 -> V_20 ;
V_152 = V_19 -> V_20 & ~ V_134 . V_20 ;
if ( ( V_134 . V_25 ^ V_19 -> V_25 ) ||
( V_134 . V_101 && strcmp ( V_134 . V_101 , V_19 -> V_101 ) ) ) {
F_123 ( L_23 ,
V_134 . V_25 , V_134 . V_101 ? : L_24 , V_19 -> V_25 , V_19 -> V_101 ) ;
V_6 = - V_142 ;
goto V_23;
}
if ( ! F_39 ( & V_19 -> V_10 . V_13 . V_91 ) ) {
V_6 = - V_121 ;
goto V_23;
}
V_6 = F_81 ( V_19 , V_151 ) ;
if ( V_6 )
goto V_23;
F_81 ( & V_92 , V_152 ) ;
if ( V_134 . V_146 ) {
F_117 ( & V_129 ) ;
strcpy ( V_19 -> V_130 , V_134 . V_146 ) ;
F_118 ( & V_129 ) ;
}
V_23:
F_41 ( V_134 . V_146 ) ;
F_41 ( V_134 . V_101 ) ;
F_82 ( & V_18 ) ;
return V_6 ;
}
static void F_126 ( void )
{
struct V_95 * V_155 , * V_156 ;
F_45 ( & V_36 ) ;
if ( V_157 )
goto V_23;
V_157 = true ;
F_127 ( & V_158 ) ;
F_128 (g, p) {
F_76 ( ! F_39 ( & V_155 -> V_159 ) ||
F_86 ( V_155 ) != & V_24 ) ;
F_129 ( & V_155 -> V_160 -> V_161 ) ;
if ( ! ( V_155 -> V_25 & V_162 ) ) {
struct V_42 * V_43 = F_86 ( V_155 ) ;
F_58 ( & V_155 -> V_159 , & V_43 -> V_77 ) ;
F_47 ( V_43 ) ;
}
F_130 ( & V_155 -> V_160 -> V_161 ) ;
} F_131 ( V_156 , V_155 ) ;
F_132 ( & V_158 ) ;
V_23:
F_46 ( & V_36 ) ;
}
static void F_133 ( struct V_9 * V_10 )
{
struct V_15 * V_16 ;
int V_47 ;
F_56 ( & V_10 -> V_13 . V_163 ) ;
F_56 ( & V_10 -> V_13 . V_91 ) ;
F_56 ( & V_10 -> V_54 ) ;
F_56 ( & V_10 -> V_164 ) ;
F_134 ( & V_10 -> V_165 ) ;
V_10 -> V_13 . V_9 = V_10 ;
V_10 -> V_13 . V_25 |= V_26 ;
F_33 (ss, ssid)
F_56 ( & V_10 -> V_83 [ V_47 ] ) ;
F_135 ( & V_10 -> V_166 ) ;
F_136 ( & V_10 -> V_167 , V_168 ) ;
}
static void F_137 ( struct V_68 * V_19 ,
struct V_133 * V_134 )
{
struct V_9 * V_10 = & V_19 -> V_10 ;
F_56 ( & V_19 -> V_93 ) ;
F_67 ( & V_19 -> V_90 , 1 ) ;
V_10 -> V_19 = V_19 ;
F_133 ( V_10 ) ;
F_138 ( & V_19 -> V_89 ) ;
V_19 -> V_25 = V_134 -> V_25 ;
if ( V_134 -> V_146 )
strcpy ( V_19 -> V_130 , V_134 -> V_146 ) ;
if ( V_134 -> V_101 )
strcpy ( V_19 -> V_101 , V_134 -> V_101 ) ;
if ( V_134 -> V_145 )
F_139 ( V_131 , & V_19 -> V_10 . V_25 ) ;
}
static int F_140 ( struct V_68 * V_19 , unsigned int V_119 )
{
F_141 ( V_71 ) ;
struct V_9 * V_86 = & V_19 -> V_10 ;
struct V_31 * V_169 ;
struct V_42 * V_43 ;
int V_41 , V_6 ;
F_17 ( & V_18 ) ;
V_6 = F_1 ( & V_19 -> V_89 , V_86 , 1 , 2 , V_170 ) ;
if ( V_6 < 0 )
goto V_171;
V_86 -> V_8 = V_6 ;
V_6 = F_142 ( & V_86 -> V_13 . V_172 , V_173 , 0 ,
V_72 ) ;
if ( V_6 )
goto V_171;
V_6 = F_55 ( V_51 , & V_71 ) ;
if ( V_6 )
goto V_174;
V_6 = F_72 ( V_19 ) ;
if ( V_6 )
goto V_174;
V_19 -> V_85 = F_143 ( & V_175 ,
V_176 ,
V_86 ) ;
if ( F_144 ( V_19 -> V_85 ) ) {
V_6 = F_145 ( V_19 -> V_85 ) ;
goto V_177;
}
V_86 -> V_29 = V_19 -> V_85 -> V_29 ;
if ( V_19 == & V_92 )
V_169 = V_178 ;
else
V_169 = V_179 ;
V_6 = F_104 ( V_86 , V_169 , true ) ;
if ( V_6 )
goto V_180;
V_6 = F_81 ( V_19 , V_119 ) ;
if ( V_6 )
goto V_180;
F_58 ( & V_19 -> V_93 , & V_181 ) ;
V_76 ++ ;
F_45 ( & V_36 ) ;
F_111 (css_set_table, i, cset, hlist)
F_59 ( & V_71 , V_43 , V_86 ) ;
F_46 ( & V_36 ) ;
F_50 ( ! F_39 ( & V_86 -> V_13 . V_91 ) ) ;
F_50 ( F_80 ( & V_19 -> V_90 ) != 1 ) ;
F_113 ( V_86 -> V_29 ) ;
V_6 = 0 ;
goto V_171;
V_180:
F_83 ( V_19 -> V_85 ) ;
V_19 -> V_85 = NULL ;
V_177:
F_74 ( V_19 ) ;
V_174:
F_146 ( & V_86 -> V_13 . V_172 ) ;
V_171:
F_54 ( & V_71 ) ;
return V_6 ;
}
static struct V_182 * F_147 ( struct V_183 * V_184 ,
int V_25 , const char * V_185 ,
void * V_132 )
{
struct V_186 * V_187 = NULL ;
struct V_15 * V_16 ;
struct V_68 * V_19 ;
struct V_133 V_134 ;
struct V_182 * V_182 ;
int V_6 ;
int V_41 ;
bool V_188 ;
if ( ! V_157 )
F_126 () ;
F_79 ( & V_18 ) ;
V_6 = F_119 ( V_132 , & V_134 ) ;
if ( V_6 )
goto V_23;
if ( V_134 . V_25 & V_144 ) {
V_123 = true ;
V_19 = & V_92 ;
F_89 ( & V_19 -> V_10 ) ;
V_6 = 0 ;
goto V_23;
}
F_33 (ss, i) {
if ( ! ( V_134 . V_20 & ( 1 << V_41 ) ) ||
V_16 -> V_19 == & V_92 )
continue;
if ( ! F_148 ( & V_16 -> V_19 -> V_10 . V_13 . V_172 ) ) {
F_82 ( & V_18 ) ;
F_149 ( 10 ) ;
V_6 = F_150 () ;
goto V_189;
}
F_92 ( & V_16 -> V_19 -> V_10 ) ;
}
F_151 (root) {
bool V_190 = false ;
if ( V_19 == & V_92 )
continue;
if ( V_134 . V_101 ) {
if ( strcmp ( V_134 . V_101 , V_19 -> V_101 ) )
continue;
V_190 = true ;
}
if ( ( V_134 . V_20 || V_134 . V_143 ) &&
( V_134 . V_20 != V_19 -> V_20 ) ) {
if ( ! V_190 )
continue;
V_6 = - V_121 ;
goto V_23;
}
if ( V_19 -> V_25 ^ V_134 . V_25 )
F_107 ( L_25 ) ;
V_187 = F_152 ( V_19 -> V_85 , NULL ) ;
if ( F_144 ( V_187 ) ||
! F_148 ( & V_19 -> V_10 . V_13 . V_172 ) ) {
F_82 ( & V_18 ) ;
if ( ! F_153 ( V_187 ) )
F_154 ( V_187 ) ;
F_149 ( 10 ) ;
V_6 = F_150 () ;
goto V_189;
}
V_6 = 0 ;
goto V_23;
}
if ( ! V_134 . V_20 && ! V_134 . V_143 ) {
V_6 = - V_142 ;
goto V_23;
}
V_19 = F_57 ( sizeof( * V_19 ) , V_72 ) ;
if ( ! V_19 ) {
V_6 = - V_73 ;
goto V_23;
}
F_137 ( V_19 , & V_134 ) ;
V_6 = F_140 ( V_19 , V_134 . V_20 ) ;
if ( V_6 )
F_75 ( V_19 ) ;
V_23:
F_82 ( & V_18 ) ;
V_189:
F_41 ( V_134 . V_146 ) ;
F_41 ( V_134 . V_101 ) ;
if ( V_6 )
return F_155 ( V_6 ) ;
V_182 = F_156 ( V_184 , V_25 , V_19 -> V_85 ,
V_191 , & V_188 ) ;
if ( F_144 ( V_182 ) || ! V_188 )
F_92 ( & V_19 -> V_10 ) ;
if ( V_187 ) {
F_108 ( V_188 ) ;
F_154 ( V_187 ) ;
}
return V_182 ;
}
static void F_157 ( struct V_186 * V_192 )
{
struct V_84 * V_85 = F_158 ( V_192 ) ;
struct V_68 * V_19 = F_71 ( V_85 ) ;
if ( ! F_39 ( & V_19 -> V_10 . V_13 . V_91 ) ||
V_19 == & V_92 )
F_92 ( & V_19 -> V_10 ) ;
else
F_159 ( & V_19 -> V_10 . V_13 . V_172 ) ;
F_160 ( V_192 ) ;
}
char * F_161 ( struct V_95 * V_96 , char * V_97 , T_3 V_193 )
{
struct V_68 * V_19 ;
struct V_9 * V_10 ;
int V_88 = 1 ;
char * V_194 = NULL ;
F_79 ( & V_18 ) ;
F_65 ( & V_36 ) ;
V_19 = F_162 ( & V_87 , & V_88 ) ;
if ( V_19 ) {
V_10 = F_85 ( V_96 , V_19 ) ;
V_194 = F_163 ( V_10 , V_97 , V_193 ) ;
} else {
if ( F_164 ( V_97 , L_26 , V_193 ) < V_193 )
V_194 = V_97 ;
}
F_66 ( & V_36 ) ;
F_82 ( & V_18 ) ;
return V_194 ;
}
struct V_95 * F_165 ( struct V_195 * V_196 )
{
V_196 -> V_197 = F_61 ( V_196 -> V_198 , struct V_42 , V_80 ) ;
V_196 -> V_199 = NULL ;
return F_166 ( V_196 ) ;
}
struct V_95 * F_166 ( struct V_195 * V_196 )
{
struct V_42 * V_43 = V_196 -> V_197 ;
struct V_95 * V_96 = V_196 -> V_199 ;
while ( & V_43 -> V_80 != V_196 -> V_198 ) {
if ( ! V_96 )
V_96 = F_61 ( & V_43 -> V_78 ,
struct V_95 , V_159 ) ;
else
V_96 = F_167 ( V_96 , V_159 ) ;
if ( & V_96 -> V_159 != & V_43 -> V_78 ) {
V_196 -> V_197 = V_43 ;
V_196 -> V_199 = V_96 ;
return V_96 ;
}
V_43 = F_167 ( V_43 , V_80 ) ;
V_96 = NULL ;
}
return NULL ;
}
static void F_168 ( struct V_9 * V_200 ,
struct V_95 * V_201 ,
struct V_42 * V_202 )
{
struct V_42 * V_56 ;
F_17 ( & V_18 ) ;
F_17 ( & V_36 ) ;
F_76 ( V_201 -> V_25 & V_162 ) ;
V_56 = F_86 ( V_201 ) ;
F_47 ( V_202 ) ;
F_110 ( V_201 -> V_203 , V_202 ) ;
F_112 ( & V_201 -> V_159 , & V_202 -> V_78 ) ;
F_34 ( V_56 ) ;
}
static void F_169 ( struct V_59 * V_204 )
{
struct V_42 * V_43 , * V_205 ;
F_17 ( & V_18 ) ;
F_45 ( & V_36 ) ;
F_38 (cset, tmp_cset, preloaded_csets, mg_preload_node) {
V_43 -> V_206 = NULL ;
V_43 -> V_207 = NULL ;
F_170 ( & V_43 -> V_79 ) ;
F_34 ( V_43 ) ;
}
F_46 ( & V_36 ) ;
}
static void F_171 ( struct V_42 * V_208 ,
struct V_9 * V_209 ,
struct V_59 * V_204 )
{
struct V_9 * V_210 ;
F_17 ( & V_18 ) ;
F_17 ( & V_36 ) ;
V_210 = F_84 ( V_208 , V_209 -> V_19 ) ;
if ( ! F_39 ( & V_208 -> V_79 ) )
return;
F_108 ( V_208 -> V_206 ) ;
F_108 ( ! F_39 ( & V_208 -> V_78 ) ) ;
F_108 ( ! F_39 ( & V_208 -> V_80 ) ) ;
V_208 -> V_206 = V_210 ;
F_47 ( V_208 ) ;
F_58 ( & V_208 -> V_79 , V_204 ) ;
}
static int F_172 ( struct V_9 * V_209 ,
struct V_59 * V_204 )
{
F_141 ( V_198 ) ;
struct V_42 * V_208 , * V_205 ;
F_17 ( & V_18 ) ;
if ( V_209 && F_60 ( V_209 ) && F_11 ( V_209 ) &&
V_209 -> V_21 )
return - V_121 ;
F_38 (src_cset, tmp_cset, preloaded_csets, mg_preload_node) {
struct V_42 * V_211 ;
V_211 = F_64 ( V_208 ,
V_209 ? : V_208 -> V_74 ) ;
if ( ! V_211 )
goto V_212;
F_76 ( V_208 -> V_207 || V_211 -> V_207 ) ;
if ( V_208 == V_211 ) {
V_208 -> V_206 = NULL ;
F_170 ( & V_208 -> V_79 ) ;
F_43 ( V_208 ) ;
F_43 ( V_211 ) ;
continue;
}
V_208 -> V_207 = V_211 ;
if ( F_39 ( & V_211 -> V_79 ) )
F_58 ( & V_211 -> V_79 , & V_198 ) ;
else
F_43 ( V_211 ) ;
}
F_173 ( & V_198 , V_204 ) ;
return 0 ;
V_212:
F_169 ( & V_198 ) ;
return - V_73 ;
}
static int F_174 ( struct V_9 * V_10 , struct V_95 * V_213 ,
bool V_214 )
{
struct V_195 V_196 = {
. V_215 = F_175 ( V_196 . V_215 ) ,
. V_216 = F_175 ( V_196 . V_216 ) ,
. V_198 = & V_196 . V_215 ,
} ;
struct V_11 * V_22 , * V_217 = NULL ;
struct V_42 * V_43 , * V_205 ;
struct V_95 * V_96 , * V_218 ;
int V_41 , V_6 ;
F_45 ( & V_36 ) ;
F_19 () ;
V_96 = V_213 ;
do {
if ( V_96 -> V_25 & V_162 )
goto V_67;
if ( F_39 ( & V_96 -> V_159 ) )
goto V_67;
V_43 = F_86 ( V_96 ) ;
if ( ! V_43 -> V_206 )
goto V_67;
F_112 ( & V_96 -> V_159 , & V_43 -> V_78 ) ;
if ( F_39 ( & V_43 -> V_80 ) )
F_63 ( & V_43 -> V_80 , & V_196 . V_215 ) ;
if ( F_39 ( & V_43 -> V_207 -> V_80 ) )
F_112 ( & V_43 -> V_207 -> V_80 ,
& V_196 . V_216 ) ;
V_67:
if ( ! V_214 )
break;
} while_each_thread(leader, task) ;
int F_176 ( struct V_9 * V_209 ,
struct V_95 * V_213 , bool V_214 )
{
F_141 ( V_204 ) ;
struct V_95 * V_96 ;
int V_6 ;
F_65 ( & V_36 ) ;
F_19 () ;
V_96 = V_213 ;
do {
F_171 ( F_86 ( V_96 ) , V_209 ,
& V_204 ) ;
if ( ! V_214 )
break;
} while_each_thread(leader, task) ;
T_4 F_177 ( struct V_27 * V_28 , char * V_97 ,
T_3 V_219 , T_5 V_220 , bool V_214 )
{
struct V_95 * V_201 ;
const struct V_221 * V_221 = F_178 () , * V_222 ;
struct V_9 * V_10 ;
T_6 V_223 ;
int V_6 ;
if ( F_179 ( F_180 ( V_97 ) , 0 , & V_223 ) || V_223 < 0 )
return - V_142 ;
V_10 = F_99 ( V_28 -> V_29 ) ;
if ( ! V_10 )
return - V_224 ;
V_225:
F_19 () ;
if ( V_223 ) {
V_201 = F_181 ( V_223 ) ;
if ( ! V_201 ) {
F_22 () ;
V_6 = - V_226 ;
goto V_227;
}
V_222 = F_182 ( V_201 ) ;
if ( ! F_183 ( V_221 -> V_228 , V_229 ) &&
! F_183 ( V_221 -> V_228 , V_222 -> V_230 ) &&
! F_183 ( V_221 -> V_228 , V_222 -> V_231 ) ) {
F_22 () ;
V_6 = - V_232 ;
goto V_227;
}
} else
V_201 = V_153 ;
if ( V_214 )
V_201 = V_201 -> V_233 ;
if ( V_201 == V_234 || ( V_201 -> V_25 & V_235 ) ) {
V_6 = - V_142 ;
F_22 () ;
goto V_227;
}
F_184 ( V_201 ) ;
F_22 () ;
F_185 ( V_201 ) ;
if ( V_214 ) {
if ( ! F_186 ( V_201 ) ) {
F_187 ( V_201 ) ;
F_188 ( V_201 ) ;
goto V_225;
}
}
V_6 = F_176 ( V_10 , V_201 , V_214 ) ;
F_187 ( V_201 ) ;
F_188 ( V_201 ) ;
V_227:
F_96 ( V_28 -> V_29 ) ;
return V_6 ? : V_219 ;
}
int F_189 ( struct V_95 * V_236 , struct V_95 * V_201 )
{
struct V_68 * V_19 ;
int V_237 = 0 ;
F_79 ( & V_18 ) ;
F_151 (root) {
struct V_9 * V_238 ;
if ( V_19 == & V_92 )
continue;
F_65 ( & V_36 ) ;
V_238 = F_85 ( V_236 , V_19 ) ;
F_66 ( & V_36 ) ;
V_237 = F_176 ( V_238 , V_201 , false ) ;
if ( V_237 )
break;
}
F_82 ( & V_18 ) ;
return V_237 ;
}
static T_4 F_190 ( struct V_27 * V_28 ,
char * V_97 , T_3 V_219 , T_5 V_220 )
{
return F_177 ( V_28 , V_97 , V_219 , V_220 , false ) ;
}
static T_4 F_191 ( struct V_27 * V_28 ,
char * V_97 , T_3 V_219 , T_5 V_220 )
{
return F_177 ( V_28 , V_97 , V_219 , V_220 , true ) ;
}
static T_4 F_192 ( struct V_27 * V_28 ,
char * V_97 , T_3 V_219 , T_5 V_220 )
{
struct V_9 * V_10 ;
F_193 ( sizeof( V_10 -> V_19 -> V_130 ) < V_147 ) ;
V_10 = F_99 ( V_28 -> V_29 ) ;
if ( ! V_10 )
return - V_224 ;
F_117 ( & V_129 ) ;
F_164 ( V_10 -> V_19 -> V_130 , F_180 ( V_97 ) ,
sizeof( V_10 -> V_19 -> V_130 ) ) ;
F_118 ( & V_129 ) ;
F_96 ( V_28 -> V_29 ) ;
return V_219 ;
}
static int F_194 ( struct V_126 * V_127 , void * V_239 )
{
struct V_9 * V_10 = F_195 ( V_127 ) -> V_9 ;
F_117 ( & V_129 ) ;
F_116 ( V_127 , V_10 -> V_19 -> V_130 ) ;
F_118 ( & V_129 ) ;
F_196 ( V_127 , '\n' ) ;
return 0 ;
}
static int F_197 ( struct V_126 * V_127 , void * V_239 )
{
F_116 ( V_127 , L_27 ) ;
return 0 ;
}
static void F_198 ( struct V_126 * V_127 , unsigned int V_119 )
{
struct V_15 * V_16 ;
bool V_240 = false ;
int V_47 ;
F_33 (ss, ssid) {
if ( V_119 & ( 1 << V_47 ) ) {
if ( V_240 )
F_196 ( V_127 , ' ' ) ;
F_115 ( V_127 , L_28 , V_16 -> V_101 ) ;
V_240 = true ;
}
}
if ( V_240 )
F_196 ( V_127 , '\n' ) ;
}
static int F_199 ( struct V_126 * V_127 , void * V_239 )
{
struct V_9 * V_10 = F_195 ( V_127 ) -> V_9 ;
F_198 ( V_127 , V_10 -> V_19 -> V_20 &
~ V_122 ) ;
return 0 ;
}
static int F_200 ( struct V_126 * V_127 , void * V_239 )
{
struct V_9 * V_10 = F_195 ( V_127 ) -> V_9 ;
F_198 ( V_127 , F_11 ( V_10 ) -> V_111 ) ;
return 0 ;
}
static int F_201 ( struct V_126 * V_127 , void * V_239 )
{
struct V_9 * V_10 = F_195 ( V_127 ) -> V_9 ;
F_198 ( V_127 , V_10 -> V_111 ) ;
return 0 ;
}
static int F_202 ( struct V_9 * V_10 )
{
F_141 ( V_204 ) ;
struct V_11 * V_22 ;
struct V_42 * V_208 ;
int V_6 ;
F_17 ( & V_18 ) ;
F_65 ( & V_36 ) ;
F_203 (css, cgroup_css(cgrp, NULL)) {
struct V_44 * V_45 ;
if ( V_22 -> V_9 == V_10 )
continue;
F_69 (link, &css->cgroup->cset_links, cset_link)
F_171 ( V_45 -> V_43 , V_10 ,
& V_204 ) ;
}
F_66 ( & V_36 ) ;
V_6 = F_172 ( NULL , & V_204 ) ;
if ( V_6 )
goto V_241;
F_69 (src_cset, &preloaded_csets, mg_preload_node) {
struct V_95 * V_242 = NULL , * V_96 ;
if ( ! V_208 -> V_206 )
break;
while ( true ) {
F_65 ( & V_36 ) ;
V_96 = F_204 ( & V_208 -> V_77 ,
struct V_95 , V_159 ) ;
if ( V_96 ) {
V_96 = V_96 -> V_233 ;
F_76 ( ! F_86 ( V_96 ) -> V_206 ) ;
F_184 ( V_96 ) ;
}
F_66 ( & V_36 ) ;
if ( ! V_96 )
break;
if ( F_205 ( V_242 == V_96 ,
L_29 ) )
goto V_241;
V_242 = V_96 ;
F_185 ( V_96 ) ;
if ( ! F_186 ( V_96 ) ) {
F_187 ( V_96 ) ;
F_188 ( V_96 ) ;
continue;
}
V_6 = F_174 ( V_208 -> V_74 , V_96 , true ) ;
F_187 ( V_96 ) ;
F_188 ( V_96 ) ;
if ( F_205 ( V_6 , L_30 , V_6 ) )
goto V_241;
}
}
V_241:
F_169 ( & V_204 ) ;
return V_6 ;
}
static T_4 F_206 ( struct V_27 * V_28 ,
char * V_97 , T_3 V_219 ,
T_5 V_220 )
{
unsigned int V_243 = 0 , V_244 = 0 ;
unsigned int V_245 , V_246 , V_247 , V_248 , V_249 , V_250 ;
struct V_9 * V_10 , * V_251 ;
struct V_15 * V_16 ;
char * V_252 ;
int V_47 , V_6 ;
V_97 = F_180 ( V_97 ) ;
while ( ( V_252 = F_121 ( & V_97 , L_31 ) ) ) {
if ( V_252 [ 0 ] == '\0' )
continue;
F_33 (ss, ssid) {
if ( V_16 -> V_149 || strcmp ( V_252 + 1 , V_16 -> V_101 ) ||
( ( 1 << V_16 -> V_8 ) & V_122 ) )
continue;
if ( * V_252 == '+' ) {
V_243 |= 1 << V_47 ;
V_244 &= ~ ( 1 << V_47 ) ;
} else if ( * V_252 == '-' ) {
V_244 |= 1 << V_47 ;
V_243 &= ~ ( 1 << V_47 ) ;
} else {
return - V_142 ;
}
break;
}
if ( V_47 == V_75 )
return - V_142 ;
}
V_10 = F_99 ( V_28 -> V_29 ) ;
if ( ! V_10 )
return - V_224 ;
F_33 (ss, ssid) {
if ( V_243 & ( 1 << V_47 ) ) {
if ( V_10 -> V_111 & ( 1 << V_47 ) ) {
V_243 &= ~ ( 1 << V_47 ) ;
continue;
}
if ( ! ( V_92 . V_20 & ( 1 << V_47 ) ) ||
( F_11 ( V_10 ) &&
! ( F_11 ( V_10 ) -> V_111 & ( 1 << V_47 ) ) ) ) {
V_6 = - V_150 ;
goto V_23;
}
} else if ( V_244 & ( 1 << V_47 ) ) {
if ( ! ( V_10 -> V_111 & ( 1 << V_47 ) ) ) {
V_244 &= ~ ( 1 << V_47 ) ;
continue;
}
F_207 (child, cgrp) {
if ( V_251 -> V_111 & ( 1 << V_47 ) ) {
V_6 = - V_121 ;
goto V_23;
}
}
}
}
if ( ! V_243 && ! V_244 ) {
V_6 = 0 ;
goto V_23;
}
if ( V_243 && F_11 ( V_10 ) && ! F_39 ( & V_10 -> V_54 ) ) {
V_6 = - V_121 ;
goto V_23;
}
V_247 = V_10 -> V_111 ;
V_249 = V_10 -> V_21 ;
V_248 = ( V_247 | V_243 ) & ~ V_244 ;
V_250 = F_94 ( V_10 , V_248 ) ;
V_245 = ~ V_249 & V_250 ;
V_246 = V_249 & ~ V_250 ;
V_243 |= V_245 ;
V_244 |= V_246 ;
F_33 (ss, ssid) {
if ( ! ( V_245 & ( 1 << V_47 ) ) )
continue;
F_207 (child, cgrp) {
F_208 ( V_253 ) ;
if ( ! F_13 ( V_251 , V_16 ) )
continue;
F_89 ( V_251 ) ;
F_209 ( & V_251 -> V_166 , & V_253 ,
V_254 ) ;
F_96 ( V_28 -> V_29 ) ;
F_210 () ;
F_211 ( & V_251 -> V_166 , & V_253 ) ;
F_92 ( V_251 ) ;
return F_150 () ;
}
}
V_10 -> V_111 = V_248 ;
V_10 -> V_21 = V_250 ;
F_33 (ss, ssid) {
if ( ! ( V_243 & ( 1 << V_47 ) ) )
continue;
F_207 (child, cgrp) {
if ( V_245 & ( 1 << V_47 ) )
V_6 = F_212 ( V_251 , V_16 ,
V_10 -> V_111 & ( 1 << V_47 ) ) ;
else
V_6 = F_106 ( V_251 , 1 << V_47 ) ;
if ( V_6 )
goto V_255;
}
}
V_6 = F_202 ( V_10 ) ;
if ( V_6 )
goto V_255;
F_33 (ss, ssid) {
if ( ! ( V_244 & ( 1 << V_47 ) ) )
continue;
F_207 (child, cgrp) {
struct V_11 * V_22 = F_13 ( V_251 , V_16 ) ;
if ( V_246 & ( 1 << V_47 ) ) {
F_213 ( V_22 ) ;
} else {
F_103 ( V_251 , 1 << V_47 ) ;
if ( V_16 -> V_256 )
V_16 -> V_256 ( V_22 ) ;
}
}
}
F_33 (ss, ssid) {
struct V_11 * V_257 = F_13 ( V_10 , V_16 ) ;
struct V_11 * V_22 ;
if ( ! V_16 -> V_258 || ! V_257 )
continue;
F_203 (css, this_css)
if ( V_22 != V_257 )
V_16 -> V_258 ( V_22 ) ;
}
F_113 ( V_10 -> V_29 ) ;
V_6 = 0 ;
V_23:
F_96 ( V_28 -> V_29 ) ;
return V_6 ? : V_219 ;
V_255:
V_10 -> V_111 = V_247 ;
V_10 -> V_21 = V_249 ;
F_33 (ss, ssid) {
if ( ! ( V_243 & ( 1 << V_47 ) ) )
continue;
F_207 (child, cgrp) {
struct V_11 * V_22 = F_13 ( V_251 , V_16 ) ;
if ( ! V_22 )
continue;
if ( V_245 & ( 1 << V_47 ) )
F_213 ( V_22 ) ;
else
F_103 ( V_251 , 1 << V_47 ) ;
}
}
goto V_23;
}
static int F_214 ( struct V_126 * V_127 , void * V_239 )
{
F_115 ( V_127 , L_32 , ( bool ) F_195 ( V_127 ) -> V_9 -> V_38 ) ;
return 0 ;
}
static T_4 F_215 ( struct V_27 * V_28 , char * V_97 ,
T_3 V_219 , T_5 V_220 )
{
struct V_9 * V_10 = V_28 -> V_29 -> V_14 -> V_30 ;
struct V_31 * V_32 = V_28 -> V_29 -> V_30 ;
struct V_11 * V_22 ;
int V_6 ;
if ( V_32 -> V_109 )
return V_32 -> V_109 ( V_28 , V_97 , V_219 , V_220 ) ;
F_19 () ;
V_22 = F_13 ( V_10 , V_32 -> V_16 ) ;
F_22 () ;
if ( V_32 -> V_107 ) {
unsigned long long V_239 ;
V_6 = F_216 ( V_97 , 0 , & V_239 ) ;
if ( ! V_6 )
V_6 = V_32 -> V_107 ( V_22 , V_32 , V_239 ) ;
} else if ( V_32 -> V_108 ) {
long long V_239 ;
V_6 = F_217 ( V_97 , 0 , & V_239 ) ;
if ( ! V_6 )
V_6 = V_32 -> V_108 ( V_22 , V_32 , V_239 ) ;
} else {
V_6 = - V_142 ;
}
return V_6 ? : V_219 ;
}
static void * F_218 ( struct V_126 * V_127 , T_5 * V_259 )
{
return F_219 ( V_127 ) -> F_220 ( V_127 , V_259 ) ;
}
static void * F_221 ( struct V_126 * V_127 , void * V_239 , T_5 * V_259 )
{
return F_219 ( V_127 ) -> F_222 ( V_127 , V_239 , V_259 ) ;
}
static void F_223 ( struct V_126 * V_127 , void * V_239 )
{
F_219 ( V_127 ) -> F_224 ( V_127 , V_239 ) ;
}
static int F_225 ( struct V_126 * V_260 , void * V_261 )
{
struct V_31 * V_32 = F_219 ( V_260 ) ;
struct V_11 * V_22 = F_195 ( V_260 ) ;
if ( V_32 -> V_105 )
return V_32 -> V_105 ( V_260 , V_261 ) ;
if ( V_32 -> V_103 )
F_115 ( V_260 , L_33 , V_32 -> V_103 ( V_22 , V_32 ) ) ;
else if ( V_32 -> V_104 )
F_115 ( V_260 , L_34 , V_32 -> V_104 ( V_22 , V_32 ) ) ;
else
return - V_142 ;
return 0 ;
}
static int F_226 ( struct V_115 * V_29 , struct V_115 * V_262 ,
const char * V_263 )
{
struct V_9 * V_10 = V_29 -> V_30 ;
int V_6 ;
if ( F_97 ( V_29 ) != V_116 )
return - V_264 ;
if ( V_29 -> V_14 != V_262 )
return - V_265 ;
if ( F_60 ( V_10 ) )
return - V_266 ;
F_100 ( V_262 ) ;
F_100 ( V_29 ) ;
F_79 ( & V_18 ) ;
V_6 = F_227 ( V_29 , V_262 , V_263 ) ;
F_82 ( & V_18 ) ;
F_98 ( V_29 ) ;
F_98 ( V_262 ) ;
return V_6 ;
}
static int F_228 ( struct V_115 * V_29 )
{
struct V_267 V_267 = { . V_268 = V_269 | V_270 ,
. V_271 = F_229 () ,
. V_272 = F_230 () , } ;
if ( F_183 ( V_267 . V_271 , V_229 ) &&
F_231 ( V_267 . V_272 , V_273 ) )
return 0 ;
return F_232 ( V_29 , & V_267 ) ;
}
static int F_233 ( struct V_9 * V_10 , struct V_31 * V_32 )
{
char V_101 [ V_100 ] ;
struct V_115 * V_29 ;
struct V_274 * V_40 = NULL ;
int V_6 ;
#ifdef F_234
V_40 = & V_32 -> V_275 ;
#endif
V_29 = F_235 ( V_10 -> V_29 , F_87 ( V_10 , V_32 , V_101 ) ,
F_88 ( V_32 ) , 0 , V_32 -> V_276 , V_32 ,
NULL , false , V_40 ) ;
if ( F_144 ( V_29 ) )
return F_145 ( V_29 ) ;
V_6 = F_228 ( V_29 ) ;
if ( V_6 ) {
F_236 ( V_29 ) ;
return V_6 ;
}
if ( V_32 -> V_105 == F_214 )
V_10 -> V_39 = V_29 ;
return 0 ;
}
static int F_104 ( struct V_9 * V_10 , struct V_31 V_117 [] ,
bool V_277 )
{
struct V_31 * V_32 ;
int V_6 ;
F_17 ( & V_18 ) ;
for ( V_32 = V_117 ; V_32 -> V_101 [ 0 ] != '\0' ; V_32 ++ ) {
if ( ( V_32 -> V_25 & V_278 ) && ! F_60 ( V_10 ) )
continue;
if ( ( V_32 -> V_25 & V_279 ) && F_60 ( V_10 ) )
continue;
if ( ( V_32 -> V_25 & V_280 ) && ! F_11 ( V_10 ) )
continue;
if ( ( V_32 -> V_25 & V_281 ) && F_11 ( V_10 ) )
continue;
if ( V_277 ) {
V_6 = F_233 ( V_10 , V_32 ) ;
if ( V_6 ) {
F_107 ( L_35 ,
V_282 , V_32 -> V_101 , V_6 ) ;
return V_6 ;
}
} else {
F_101 ( V_10 , V_32 ) ;
}
}
return 0 ;
}
static int F_237 ( struct V_31 * V_117 , bool V_277 )
{
F_141 ( V_283 ) ;
struct V_15 * V_16 = V_117 [ 0 ] . V_16 ;
struct V_9 * V_19 = & V_16 -> V_19 -> V_10 ;
struct V_11 * V_22 ;
int V_6 = 0 ;
F_17 ( & V_18 ) ;
F_203 (css, cgroup_css(root, ss)) {
struct V_9 * V_10 = V_22 -> V_9 ;
if ( F_23 ( V_10 ) )
continue;
V_6 = F_104 ( V_10 , V_117 , V_277 ) ;
if ( V_6 )
break;
}
if ( V_277 && ! V_6 )
F_113 ( V_19 -> V_29 ) ;
return V_6 ;
}
static void F_238 ( struct V_31 * V_117 )
{
struct V_31 * V_32 ;
for ( V_32 = V_117 ; V_32 -> V_101 [ 0 ] != '\0' ; V_32 ++ ) {
if ( V_32 -> V_284 && V_32 -> V_284 != V_285 )
F_41 ( V_32 -> V_276 ) ;
V_32 -> V_276 = NULL ;
V_32 -> V_16 = NULL ;
V_32 -> V_25 &= ~ ( V_278 | V_279 ) ;
}
}
static int F_239 ( struct V_15 * V_16 , struct V_31 * V_117 )
{
struct V_31 * V_32 ;
for ( V_32 = V_117 ; V_32 -> V_101 [ 0 ] != '\0' ; V_32 ++ ) {
struct V_286 * V_276 ;
F_108 ( V_32 -> V_16 || V_32 -> V_276 ) ;
if ( V_32 -> F_220 )
V_276 = & V_287 ;
else
V_276 = & V_288 ;
if ( V_32 -> V_284 && V_32 -> V_284 != V_285 ) {
V_276 = F_240 ( V_276 , sizeof( * V_276 ) , V_72 ) ;
if ( ! V_276 ) {
F_238 ( V_117 ) ;
return - V_73 ;
}
V_276 -> V_289 = V_32 -> V_284 ;
}
V_32 -> V_276 = V_276 ;
V_32 -> V_16 = V_16 ;
}
return 0 ;
}
static int F_241 ( struct V_31 * V_117 )
{
F_17 ( & V_18 ) ;
if ( ! V_117 || ! V_117 [ 0 ] . V_16 )
return - V_150 ;
F_36 ( & V_117 -> V_290 ) ;
F_237 ( V_117 , false ) ;
F_238 ( V_117 ) ;
return 0 ;
}
int F_242 ( struct V_31 * V_117 )
{
int V_6 ;
F_79 ( & V_18 ) ;
V_6 = F_241 ( V_117 ) ;
F_82 ( & V_18 ) ;
return V_6 ;
}
static int F_243 ( struct V_15 * V_16 , struct V_31 * V_117 )
{
int V_6 ;
if ( V_16 -> V_149 )
return 0 ;
if ( ! V_117 || V_117 [ 0 ] . V_101 [ 0 ] == '\0' )
return 0 ;
V_6 = F_239 ( V_16 , V_117 ) ;
if ( V_6 )
return V_6 ;
F_79 ( & V_18 ) ;
F_63 ( & V_117 -> V_290 , & V_16 -> V_117 ) ;
V_6 = F_237 ( V_117 , true ) ;
if ( V_6 )
F_241 ( V_117 ) ;
F_82 ( & V_18 ) ;
return V_6 ;
}
int F_244 ( struct V_15 * V_16 , struct V_31 * V_117 )
{
struct V_31 * V_32 ;
for ( V_32 = V_117 ; V_32 && V_32 -> V_101 [ 0 ] != '\0' ; V_32 ++ )
V_32 -> V_25 |= V_278 ;
return F_243 ( V_16 , V_117 ) ;
}
int F_245 ( struct V_15 * V_16 , struct V_31 * V_117 )
{
struct V_31 * V_32 ;
if ( ! V_291 ||
V_16 -> V_292 != V_16 -> V_293 ) {
for ( V_32 = V_117 ; V_32 && V_32 -> V_101 [ 0 ] != '\0' ; V_32 ++ )
V_32 -> V_25 |= V_279 ;
}
return F_243 ( V_16 , V_117 ) ;
}
static int F_246 ( const struct V_9 * V_10 )
{
int V_70 = 0 ;
struct V_44 * V_45 ;
F_65 ( & V_36 ) ;
F_69 (link, &cgrp->cset_links, cset_link)
V_70 += F_80 ( & V_45 -> V_43 -> V_48 ) ;
F_66 ( & V_36 ) ;
return V_70 ;
}
struct V_11 * F_105 ( struct V_11 * V_294 ,
struct V_11 * V_14 )
{
struct V_11 * V_67 ;
F_247 () ;
if ( ! V_294 ) {
V_67 = F_248 ( V_14 -> V_91 . V_67 , struct V_11 , V_163 ) ;
} else if ( F_249 ( ! ( V_294 -> V_25 & V_295 ) ) ) {
V_67 = F_248 ( V_294 -> V_163 . V_67 , struct V_11 , V_163 ) ;
} else {
F_250 (next, &parent->children, sibling)
if ( V_67 -> V_296 > V_294 -> V_296 )
break;
}
if ( & V_67 -> V_163 != & V_14 -> V_91 )
return V_67 ;
return NULL ;
}
struct V_11 *
F_251 ( struct V_11 * V_294 ,
struct V_11 * V_19 )
{
struct V_11 * V_67 ;
F_247 () ;
if ( ! V_294 )
return V_19 ;
V_67 = F_105 ( NULL , V_294 ) ;
if ( V_67 )
return V_67 ;
while ( V_294 != V_19 ) {
V_67 = F_105 ( V_294 , V_294 -> V_14 ) ;
if ( V_67 )
return V_67 ;
V_294 = V_294 -> V_14 ;
}
return NULL ;
}
struct V_11 *
F_252 ( struct V_11 * V_294 )
{
struct V_11 * V_297 , * V_298 ;
F_247 () ;
do {
V_297 = V_294 ;
V_294 = NULL ;
F_253 (tmp, last)
V_294 = V_298 ;
} while ( V_294 );
return V_297 ;
}
static struct V_11 *
F_254 ( struct V_11 * V_294 )
{
struct V_11 * V_297 ;
do {
V_297 = V_294 ;
V_294 = F_105 ( NULL , V_294 ) ;
} while ( V_294 );
return V_297 ;
}
struct V_11 *
F_255 ( struct V_11 * V_294 ,
struct V_11 * V_19 )
{
struct V_11 * V_67 ;
F_247 () ;
if ( ! V_294 )
return F_254 ( V_19 ) ;
if ( V_294 == V_19 )
return NULL ;
V_67 = F_105 ( V_294 , V_294 -> V_14 ) ;
if ( V_67 )
return F_254 ( V_67 ) ;
return V_294 -> V_14 ;
}
bool F_256 ( struct V_11 * V_22 )
{
struct V_11 * V_251 ;
bool V_6 = false ;
F_19 () ;
F_253 (child, css) {
if ( V_251 -> V_25 & V_26 ) {
V_6 = true ;
break;
}
}
F_22 () ;
return V_6 ;
}
static void F_257 ( struct V_299 * V_300 )
{
struct V_59 * V_301 = V_300 -> V_302 ;
struct V_44 * V_45 ;
struct V_42 * V_43 ;
do {
V_301 = V_301 -> V_67 ;
if ( V_301 == V_300 -> V_303 ) {
V_300 -> V_302 = NULL ;
return;
}
if ( V_300 -> V_16 ) {
V_43 = F_12 ( V_301 , struct V_42 ,
V_49 [ V_300 -> V_16 -> V_8 ] ) ;
} else {
V_45 = F_51 ( V_301 , struct V_44 , V_52 ) ;
V_43 = V_45 -> V_43 ;
}
} while ( F_39 ( & V_43 -> V_77 ) && F_39 ( & V_43 -> V_78 ) );
V_300 -> V_302 = V_301 ;
if ( ! F_39 ( & V_43 -> V_77 ) )
V_300 -> V_304 = V_43 -> V_77 . V_67 ;
else
V_300 -> V_304 = V_43 -> V_78 . V_67 ;
V_300 -> V_305 = & V_43 -> V_77 ;
V_300 -> V_306 = & V_43 -> V_78 ;
}
void F_258 ( struct V_11 * V_22 ,
struct V_299 * V_300 )
__acquires( V_36 )
{
F_76 ( ! V_157 ) ;
F_65 ( & V_36 ) ;
V_300 -> V_16 = V_22 -> V_16 ;
if ( V_300 -> V_16 )
V_300 -> V_302 = & V_22 -> V_9 -> V_83 [ V_22 -> V_16 -> V_8 ] ;
else
V_300 -> V_302 = & V_22 -> V_9 -> V_54 ;
V_300 -> V_303 = V_300 -> V_302 ;
F_257 ( V_300 ) ;
}
struct V_95 * F_259 ( struct V_299 * V_300 )
{
struct V_95 * V_94 ;
struct V_59 * V_301 = V_300 -> V_304 ;
if ( ! V_300 -> V_302 )
return NULL ;
V_94 = F_51 ( V_301 , struct V_95 , V_159 ) ;
V_301 = V_301 -> V_67 ;
if ( V_301 == V_300 -> V_305 )
V_301 = V_300 -> V_306 -> V_67 ;
if ( V_301 == V_300 -> V_306 )
F_257 ( V_300 ) ;
else
V_300 -> V_304 = V_301 ;
return V_94 ;
}
void F_260 ( struct V_299 * V_300 )
__releases( V_36 )
{
F_66 ( & V_36 ) ;
}
int F_261 ( struct V_9 * V_307 , struct V_9 * V_236 )
{
F_141 ( V_204 ) ;
struct V_44 * V_45 ;
struct V_299 V_300 ;
struct V_95 * V_96 ;
int V_6 ;
F_79 ( & V_18 ) ;
F_65 ( & V_36 ) ;
F_69 (link, &from->cset_links, cset_link)
F_171 ( V_45 -> V_43 , V_307 , & V_204 ) ;
F_66 ( & V_36 ) ;
V_6 = F_172 ( V_307 , & V_204 ) ;
if ( V_6 )
goto V_308;
do {
F_258 ( & V_236 -> V_13 , & V_300 ) ;
V_96 = F_259 ( & V_300 ) ;
if ( V_96 )
F_184 ( V_96 ) ;
F_260 ( & V_300 ) ;
if ( V_96 ) {
V_6 = F_174 ( V_307 , V_96 , false ) ;
F_188 ( V_96 ) ;
}
} while ( V_96 && ! V_6 );
V_308:
F_169 ( & V_204 ) ;
F_82 ( & V_18 ) ;
return V_6 ;
}
static void * F_262 ( int V_70 )
{
if ( F_263 ( V_70 ) )
return F_264 ( V_70 * sizeof( T_6 ) ) ;
else
return F_265 ( V_70 * sizeof( T_6 ) , V_72 ) ;
}
static void F_266 ( void * V_155 )
{
if ( F_267 ( V_155 ) )
F_268 ( V_155 ) ;
else
F_41 ( V_155 ) ;
}
static void F_269 ( struct V_9 * V_10 )
{
struct V_309 * V_301 , * V_310 ;
F_79 ( & V_10 -> V_165 ) ;
F_38 (l, tmp_l, &cgrp->pidlists, links)
F_270 ( V_311 , & V_301 -> V_312 , 0 ) ;
F_82 ( & V_10 -> V_165 ) ;
F_271 ( V_311 ) ;
F_50 ( ! F_39 ( & V_10 -> V_164 ) ) ;
}
static void F_272 ( struct V_313 * V_314 )
{
struct V_315 * V_316 = F_273 ( V_314 ) ;
struct V_309 * V_301 = F_12 ( V_316 , struct V_309 ,
V_312 ) ;
struct V_309 * V_317 = NULL ;
F_79 ( & V_301 -> V_318 -> V_165 ) ;
if ( ! F_274 ( V_316 ) ) {
F_36 ( & V_301 -> V_319 ) ;
F_266 ( V_301 -> V_320 ) ;
F_275 ( V_301 -> V_40 . V_321 ) ;
V_317 = V_301 ;
}
F_82 ( & V_301 -> V_318 -> V_165 ) ;
F_41 ( V_317 ) ;
}
static int F_276 ( T_6 * V_320 , int V_322 )
{
int V_323 , V_324 = 1 ;
if ( V_322 == 0 || V_322 == 1 )
return V_322 ;
for ( V_323 = 1 ; V_323 < V_322 ; V_323 ++ ) {
while ( V_320 [ V_323 ] == V_320 [ V_323 - 1 ] ) {
V_323 ++ ;
if ( V_323 == V_322 )
goto V_325;
}
V_320 [ V_324 ] = V_320 [ V_323 ] ;
V_324 ++ ;
}
V_325:
return V_324 ;
}
static T_6 F_277 ( T_6 V_223 )
{
unsigned V_326 = V_223 & 0x55555555 ;
unsigned V_327 = V_223 & 0xAAAAAAAA ;
return ( V_326 << 1 ) | ( V_327 >> 1 ) ;
}
static T_6 F_278 ( struct V_9 * V_10 , T_6 V_223 )
{
if ( F_60 ( V_10 ) )
return F_277 ( V_223 ) ;
else
return V_223 ;
}
static int F_279 ( const void * V_326 , const void * V_327 )
{
return * ( T_6 * ) V_326 - * ( T_6 * ) V_327 ;
}
static int F_280 ( const void * V_326 , const void * V_327 )
{
return F_277 ( * ( T_6 * ) V_326 ) - F_277 ( * ( T_6 * ) V_327 ) ;
}
static struct V_309 * F_281 ( struct V_9 * V_10 ,
enum V_328 type )
{
struct V_309 * V_301 ;
struct V_329 * V_321 = F_282 ( V_153 ) ;
F_17 ( & V_10 -> V_165 ) ;
F_69 (l, &cgrp->pidlists, links)
if ( V_301 -> V_40 . type == type && V_301 -> V_40 . V_321 == V_321 )
return V_301 ;
return NULL ;
}
static struct V_309 * F_283 ( struct V_9 * V_10 ,
enum V_328 type )
{
struct V_309 * V_301 ;
F_17 ( & V_10 -> V_165 ) ;
V_301 = F_281 ( V_10 , type ) ;
if ( V_301 )
return V_301 ;
V_301 = F_57 ( sizeof( struct V_309 ) , V_72 ) ;
if ( ! V_301 )
return V_301 ;
F_284 ( & V_301 -> V_312 , F_272 ) ;
V_301 -> V_40 . type = type ;
V_301 -> V_40 . V_321 = F_285 ( F_282 ( V_153 ) ) ;
V_301 -> V_318 = V_10 ;
F_58 ( & V_301 -> V_319 , & V_10 -> V_164 ) ;
return V_301 ;
}
static int F_286 ( struct V_9 * V_10 , enum V_328 type ,
struct V_309 * * V_330 )
{
T_6 * V_331 ;
int V_322 ;
int V_223 , V_332 = 0 ;
struct V_299 V_300 ;
struct V_95 * V_201 ;
struct V_309 * V_301 ;
F_17 ( & V_10 -> V_165 ) ;
V_322 = F_246 ( V_10 ) ;
V_331 = F_262 ( V_322 ) ;
if ( ! V_331 )
return - V_73 ;
F_258 ( & V_10 -> V_13 , & V_300 ) ;
while ( ( V_201 = F_259 ( & V_300 ) ) ) {
if ( F_287 ( V_332 == V_322 ) )
break;
if ( type == V_333 )
V_223 = F_288 ( V_201 ) ;
else
V_223 = F_289 ( V_201 ) ;
if ( V_223 > 0 )
V_331 [ V_332 ++ ] = V_223 ;
}
F_260 ( & V_300 ) ;
V_322 = V_332 ;
if ( F_60 ( V_10 ) )
F_290 ( V_331 , V_322 , sizeof( T_6 ) , F_280 , NULL ) ;
else
F_290 ( V_331 , V_322 , sizeof( T_6 ) , F_279 , NULL ) ;
if ( type == V_333 )
V_322 = F_276 ( V_331 , V_322 ) ;
V_301 = F_283 ( V_10 , type ) ;
if ( ! V_301 ) {
F_266 ( V_331 ) ;
return - V_73 ;
}
F_266 ( V_301 -> V_320 ) ;
V_301 -> V_320 = V_331 ;
V_301 -> V_322 = V_322 ;
* V_330 = V_301 ;
return 0 ;
}
int F_291 ( struct V_334 * V_335 , struct V_182 * V_182 )
{
struct V_115 * V_29 = F_292 ( V_182 ) ;
struct V_9 * V_10 ;
struct V_299 V_300 ;
struct V_95 * V_201 ;
if ( V_182 -> V_336 -> V_337 != & V_338 || ! V_29 ||
F_97 ( V_29 ) != V_116 )
return - V_142 ;
F_79 ( & V_18 ) ;
F_19 () ;
V_10 = F_293 ( V_29 -> V_30 ) ;
if ( ! V_10 || F_23 ( V_10 ) ) {
F_22 () ;
F_82 ( & V_18 ) ;
return - V_150 ;
}
F_22 () ;
F_258 ( & V_10 -> V_13 , & V_300 ) ;
while ( ( V_201 = F_259 ( & V_300 ) ) ) {
switch ( V_201 -> V_339 ) {
case V_340 :
V_335 -> V_341 ++ ;
break;
case V_342 :
V_335 -> V_343 ++ ;
break;
case V_254 :
V_335 -> V_344 ++ ;
break;
case V_345 :
V_335 -> V_346 ++ ;
break;
default:
if ( F_294 ( V_201 ) )
V_335 -> V_347 ++ ;
break;
}
}
F_260 ( & V_300 ) ;
F_82 ( & V_18 ) ;
return 0 ;
}
static void * F_295 ( struct V_126 * V_348 , T_5 * V_294 )
{
struct V_27 * V_28 = V_348 -> V_349 ;
struct V_9 * V_10 = F_195 ( V_348 ) -> V_9 ;
struct V_309 * V_301 ;
enum V_328 type = F_219 ( V_348 ) -> V_349 ;
int V_350 = 0 , V_223 = * V_294 ;
int * V_351 , V_6 ;
F_79 ( & V_10 -> V_165 ) ;
if ( V_28 -> V_30 )
V_28 -> V_30 = F_281 ( V_10 , type ) ;
if ( ! V_28 -> V_30 ) {
V_6 = F_286 ( V_10 , type ,
(struct V_309 * * ) & V_28 -> V_30 ) ;
if ( V_6 )
return F_155 ( V_6 ) ;
}
V_301 = V_28 -> V_30 ;
if ( V_223 ) {
int V_4 = V_301 -> V_322 ;
while ( V_350 < V_4 ) {
int V_352 = ( V_350 + V_4 ) / 2 ;
if ( F_278 ( V_10 , V_301 -> V_320 [ V_352 ] ) == V_223 ) {
V_350 = V_352 ;
break;
} else if ( F_278 ( V_10 , V_301 -> V_320 [ V_352 ] ) <= V_223 )
V_350 = V_352 + 1 ;
else
V_4 = V_352 ;
}
}
if ( V_350 >= V_301 -> V_322 )
return NULL ;
V_351 = V_301 -> V_320 + V_350 ;
* V_294 = F_278 ( V_10 , * V_351 ) ;
return V_351 ;
}
static void F_296 ( struct V_126 * V_348 , void * V_239 )
{
struct V_27 * V_28 = V_348 -> V_349 ;
struct V_309 * V_301 = V_28 -> V_30 ;
if ( V_301 )
F_270 ( V_311 , & V_301 -> V_312 ,
V_353 ) ;
F_82 ( & F_195 ( V_348 ) -> V_9 -> V_165 ) ;
}
static void * F_297 ( struct V_126 * V_348 , void * V_239 , T_5 * V_294 )
{
struct V_27 * V_28 = V_348 -> V_349 ;
struct V_309 * V_301 = V_28 -> V_30 ;
T_6 * V_155 = V_239 ;
T_6 * V_4 = V_301 -> V_320 + V_301 -> V_322 ;
V_155 ++ ;
if ( V_155 >= V_4 ) {
return NULL ;
} else {
* V_294 = F_278 ( F_195 ( V_348 ) -> V_9 , * V_155 ) ;
return V_155 ;
}
}
static int F_298 ( struct V_126 * V_348 , void * V_239 )
{
return F_115 ( V_348 , L_32 , * ( int * ) V_239 ) ;
}
static T_7 F_299 ( struct V_11 * V_22 ,
struct V_31 * V_32 )
{
return F_28 ( V_22 -> V_9 ) ;
}
static int F_300 ( struct V_11 * V_22 ,
struct V_31 * V_32 , T_7 V_354 )
{
if ( V_354 )
F_139 ( V_34 , & V_22 -> V_9 -> V_25 ) ;
else
F_301 ( V_34 , & V_22 -> V_9 -> V_25 ) ;
return 0 ;
}
static T_7 F_302 ( struct V_11 * V_22 ,
struct V_31 * V_32 )
{
return F_29 ( V_131 , & V_22 -> V_9 -> V_25 ) ;
}
static int F_303 ( struct V_11 * V_22 ,
struct V_31 * V_32 , T_7 V_354 )
{
if ( V_354 )
F_139 ( V_131 , & V_22 -> V_9 -> V_25 ) ;
else
F_301 ( V_131 , & V_22 -> V_9 -> V_25 ) ;
return 0 ;
}
static int F_106 ( struct V_9 * V_10 , unsigned int V_20 )
{
struct V_15 * V_16 ;
int V_41 , V_6 = 0 ;
F_33 (ss, i) {
struct V_31 * V_117 ;
if ( ! ( V_20 & ( 1 << V_41 ) ) )
continue;
F_69 (cfts, &ss->cfts, node) {
V_6 = F_104 ( V_10 , V_117 , true ) ;
if ( V_6 < 0 )
goto V_212;
}
}
return 0 ;
V_212:
F_103 ( V_10 , V_20 ) ;
return V_6 ;
}
static void F_304 ( struct V_313 * V_314 )
{
struct V_11 * V_22 =
F_12 ( V_314 , struct V_11 , V_355 ) ;
struct V_9 * V_10 = V_22 -> V_9 ;
F_146 ( & V_22 -> V_172 ) ;
if ( V_22 -> V_16 ) {
if ( V_22 -> V_14 )
F_93 ( V_22 -> V_14 ) ;
V_22 -> V_16 -> V_356 ( V_22 ) ;
F_92 ( V_10 ) ;
} else {
F_305 ( & V_10 -> V_19 -> V_90 ) ;
F_269 ( V_10 ) ;
F_306 ( & V_10 -> V_167 ) ;
if ( F_11 ( V_10 ) ) {
F_92 ( F_11 ( V_10 ) ) ;
F_307 ( V_10 -> V_29 ) ;
F_41 ( V_10 ) ;
} else {
F_78 ( V_10 -> V_19 ) ;
}
}
}
static void F_308 ( struct V_55 * V_55 )
{
struct V_11 * V_22 =
F_12 ( V_55 , struct V_11 , V_55 ) ;
F_136 ( & V_22 -> V_355 , F_304 ) ;
F_309 ( V_357 , & V_22 -> V_355 ) ;
}
static void F_310 ( struct V_313 * V_314 )
{
struct V_11 * V_22 =
F_12 ( V_314 , struct V_11 , V_355 ) ;
struct V_15 * V_16 = V_22 -> V_16 ;
struct V_9 * V_10 = V_22 -> V_9 ;
F_79 ( & V_18 ) ;
V_22 -> V_25 |= V_295 ;
F_311 ( & V_22 -> V_163 ) ;
if ( V_16 ) {
F_9 ( & V_16 -> V_358 , V_22 -> V_8 ) ;
if ( V_16 -> V_359 )
V_16 -> V_359 ( V_22 ) ;
} else {
F_9 ( & V_10 -> V_19 -> V_89 , V_10 -> V_8 ) ;
V_10 -> V_8 = - 1 ;
F_109 ( * ( void V_360 V_361 * * ) & V_10 -> V_29 -> V_30 , NULL ) ;
}
F_82 ( & V_18 ) ;
F_312 ( & V_22 -> V_55 , F_308 ) ;
}
static void V_173 ( struct V_362 * V_363 )
{
struct V_11 * V_22 =
F_12 ( V_363 , struct V_11 , V_172 ) ;
F_136 ( & V_22 -> V_355 , F_310 ) ;
F_309 ( V_357 , & V_22 -> V_355 ) ;
}
static void F_313 ( struct V_11 * V_22 ,
struct V_15 * V_16 , struct V_9 * V_10 )
{
F_17 ( & V_18 ) ;
F_89 ( V_10 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_9 = V_10 ;
V_22 -> V_16 = V_16 ;
F_56 ( & V_22 -> V_163 ) ;
F_56 ( & V_22 -> V_91 ) ;
V_22 -> V_296 = V_364 ++ ;
if ( F_11 ( V_10 ) ) {
V_22 -> V_14 = F_13 ( F_11 ( V_10 ) , V_16 ) ;
F_21 ( V_22 -> V_14 ) ;
}
F_50 ( F_13 ( V_10 , V_16 ) ) ;
}
static int F_314 ( struct V_11 * V_22 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
int V_6 = 0 ;
F_17 ( & V_18 ) ;
if ( V_16 -> V_365 )
V_6 = V_16 -> V_365 ( V_22 ) ;
if ( ! V_6 ) {
V_22 -> V_25 |= V_26 ;
F_110 ( V_22 -> V_9 -> V_17 [ V_16 -> V_8 ] , V_22 ) ;
}
return V_6 ;
}
static void F_315 ( struct V_11 * V_22 )
{
struct V_15 * V_16 = V_22 -> V_16 ;
F_17 ( & V_18 ) ;
if ( ! ( V_22 -> V_25 & V_26 ) )
return;
if ( V_16 -> V_366 )
V_16 -> V_366 ( V_22 ) ;
V_22 -> V_25 &= ~ V_26 ;
F_109 ( V_22 -> V_9 -> V_17 [ V_16 -> V_8 ] , NULL ) ;
F_316 ( & V_22 -> V_9 -> V_166 ) ;
}
static int F_212 ( struct V_9 * V_10 , struct V_15 * V_16 ,
bool V_367 )
{
struct V_9 * V_14 = F_11 ( V_10 ) ;
struct V_11 * V_12 = F_13 ( V_14 , V_16 ) ;
struct V_11 * V_22 ;
int V_212 ;
F_17 ( & V_18 ) ;
V_22 = V_16 -> V_368 ( V_12 ) ;
if ( F_144 ( V_22 ) )
return F_145 ( V_22 ) ;
F_313 ( V_22 , V_16 , V_10 ) ;
V_212 = F_142 ( & V_22 -> V_172 , V_173 , 0 , V_72 ) ;
if ( V_212 )
goto V_369;
V_212 = F_1 ( & V_16 -> V_358 , NULL , 2 , 0 , V_170 ) ;
if ( V_212 < 0 )
goto V_370;
V_22 -> V_8 = V_212 ;
if ( V_367 ) {
V_212 = F_106 ( V_10 , 1 << V_16 -> V_8 ) ;
if ( V_212 )
goto V_371;
}
F_317 ( & V_22 -> V_163 , & V_12 -> V_91 ) ;
F_7 ( & V_16 -> V_358 , V_22 , V_22 -> V_8 ) ;
V_212 = F_314 ( V_22 ) ;
if ( V_212 )
goto V_372;
if ( V_16 -> V_373 && ! V_16 -> V_374 &&
F_11 ( V_14 ) ) {
F_107 ( L_36 ,
V_153 -> V_154 , V_153 -> V_223 , V_16 -> V_101 ) ;
if ( ! strcmp ( V_16 -> V_101 , L_37 ) )
F_107 ( L_38 ) ;
V_16 -> V_374 = true ;
}
return 0 ;
V_372:
F_311 ( & V_22 -> V_163 ) ;
F_103 ( V_22 -> V_9 , 1 << V_22 -> V_16 -> V_8 ) ;
V_371:
F_9 ( & V_16 -> V_358 , V_22 -> V_8 ) ;
V_370:
F_146 ( & V_22 -> V_172 ) ;
V_369:
F_312 ( & V_22 -> V_55 , F_308 ) ;
return V_212 ;
}
static int F_318 ( struct V_115 * V_375 , const char * V_101 ,
T_2 V_102 )
{
struct V_9 * V_14 , * V_10 ;
struct V_68 * V_19 ;
struct V_15 * V_16 ;
struct V_115 * V_29 ;
struct V_31 * V_169 ;
int V_47 , V_6 ;
if ( strchr ( V_101 , '\n' ) )
return - V_142 ;
V_14 = F_99 ( V_375 ) ;
if ( ! V_14 )
return - V_224 ;
V_19 = V_14 -> V_19 ;
V_10 = F_57 ( sizeof( * V_10 ) , V_72 ) ;
if ( ! V_10 ) {
V_6 = - V_73 ;
goto V_23;
}
V_6 = F_142 ( & V_10 -> V_13 . V_172 , V_173 , 0 , V_72 ) ;
if ( V_6 )
goto V_376;
V_10 -> V_8 = F_1 ( & V_19 -> V_89 , NULL , 2 , 0 , V_170 ) ;
if ( V_10 -> V_8 < 0 ) {
V_6 = - V_73 ;
goto V_377;
}
F_133 ( V_10 ) ;
V_10 -> V_13 . V_14 = & V_14 -> V_13 ;
V_10 -> V_19 = V_19 ;
if ( F_28 ( V_14 ) )
F_139 ( V_34 , & V_10 -> V_25 ) ;
if ( F_29 ( V_131 , & V_14 -> V_25 ) )
F_139 ( V_131 , & V_10 -> V_25 ) ;
V_29 = F_319 ( V_14 -> V_29 , V_101 , V_102 , V_10 ) ;
if ( F_144 ( V_29 ) ) {
V_6 = F_145 ( V_29 ) ;
goto V_378;
}
V_10 -> V_29 = V_29 ;
F_320 ( V_29 ) ;
V_10 -> V_13 . V_296 = V_364 ++ ;
F_317 ( & V_10 -> V_13 . V_163 , & F_11 ( V_10 ) -> V_13 . V_91 ) ;
F_48 ( & V_19 -> V_90 ) ;
F_89 ( V_14 ) ;
F_7 ( & V_19 -> V_89 , V_10 , V_10 -> V_8 ) ;
V_6 = F_228 ( V_29 ) ;
if ( V_6 )
goto V_379;
if ( F_60 ( V_10 ) )
V_169 = V_178 ;
else
V_169 = V_179 ;
V_6 = F_104 ( V_10 , V_169 , true ) ;
if ( V_6 )
goto V_379;
F_33 (ss, ssid) {
if ( V_14 -> V_21 & ( 1 << V_47 ) ) {
V_6 = F_212 ( V_10 , V_16 ,
V_14 -> V_111 & ( 1 << V_47 ) ) ;
if ( V_6 )
goto V_379;
}
}
if ( ! F_60 ( V_10 ) ) {
V_10 -> V_111 = V_14 -> V_111 ;
F_95 ( V_10 ) ;
}
F_113 ( V_29 ) ;
V_6 = 0 ;
goto V_23;
V_378:
F_9 ( & V_19 -> V_89 , V_10 -> V_8 ) ;
V_377:
F_146 ( & V_10 -> V_13 . V_172 ) ;
V_376:
F_41 ( V_10 ) ;
V_23:
F_96 ( V_375 ) ;
return V_6 ;
V_379:
F_321 ( V_10 ) ;
goto V_23;
}
static void F_322 ( struct V_313 * V_314 )
{
struct V_11 * V_22 =
F_12 ( V_314 , struct V_11 , V_355 ) ;
F_79 ( & V_18 ) ;
F_315 ( V_22 ) ;
F_82 ( & V_18 ) ;
F_93 ( V_22 ) ;
}
static void F_323 ( struct V_362 * V_363 )
{
struct V_11 * V_22 =
F_12 ( V_363 , struct V_11 , V_172 ) ;
F_136 ( & V_22 -> V_355 , F_322 ) ;
F_309 ( V_357 , & V_22 -> V_355 ) ;
}
static void F_213 ( struct V_11 * V_22 )
{
F_17 ( & V_18 ) ;
F_103 ( V_22 -> V_9 , 1 << V_22 -> V_16 -> V_8 ) ;
F_21 ( V_22 ) ;
F_324 ( & V_22 -> V_172 , F_323 ) ;
}
static int F_321 ( struct V_9 * V_10 )
__releases( &cgroup_mutex
static int F_325 ( struct V_115 * V_29 )
{
struct V_9 * V_10 ;
int V_6 = 0 ;
V_10 = F_99 ( V_29 ) ;
if ( ! V_10 )
return 0 ;
V_6 = F_321 ( V_10 ) ;
F_96 ( V_29 ) ;
return V_6 ;
}
static void T_8 F_326 ( struct V_15 * V_16 , bool V_380 )
{
struct V_11 * V_22 ;
F_327 ( V_381 L_39 , V_16 -> V_101 ) ;
F_79 ( & V_18 ) ;
F_138 ( & V_16 -> V_358 ) ;
F_56 ( & V_16 -> V_117 ) ;
V_16 -> V_19 = & V_92 ;
V_22 = V_16 -> V_368 ( F_13 ( & V_92 . V_10 , V_16 ) ) ;
F_50 ( F_144 ( V_22 ) ) ;
F_313 ( V_22 , V_16 , & V_92 . V_10 ) ;
V_22 -> V_25 |= V_382 ;
if ( V_380 ) {
V_22 -> V_8 = 1 ;
} else {
V_22 -> V_8 = F_1 ( & V_16 -> V_358 , V_22 , 1 , 2 , V_72 ) ;
F_50 ( V_22 -> V_8 < 0 ) ;
}
V_24 . V_17 [ V_16 -> V_8 ] = V_22 ;
V_383 |= V_16 -> V_384 || V_16 -> exit ;
F_50 ( ! F_39 ( & V_385 . V_77 ) ) ;
F_50 ( F_314 ( V_22 ) ) ;
F_82 ( & V_18 ) ;
}
int T_8 F_328 ( void )
{
static struct V_133 T_9 V_134 ;
struct V_15 * V_16 ;
int V_41 ;
F_137 ( & V_92 , & V_134 ) ;
V_92 . V_10 . V_13 . V_25 |= V_382 ;
F_109 ( V_385 . V_203 , & V_24 ) ;
F_33 (ss, i) {
F_205 ( ! V_16 -> V_368 || ! V_16 -> V_356 || V_16 -> V_101 || V_16 -> V_8 ,
L_40 ,
V_41 , V_386 [ V_41 ] , V_16 -> V_368 , V_16 -> V_356 ,
V_16 -> V_8 , V_16 -> V_101 ) ;
F_205 ( strlen ( V_386 [ V_41 ] ) > V_387 ,
L_41 , V_386 [ V_41 ] ) ;
V_16 -> V_8 = V_41 ;
V_16 -> V_101 = V_386 [ V_41 ] ;
if ( V_16 -> V_388 )
F_326 ( V_16 , true ) ;
}
return 0 ;
}
int T_8 F_329 ( void )
{
struct V_15 * V_16 ;
unsigned long V_40 ;
int V_47 , V_212 ;
F_50 ( F_239 ( NULL , V_178 ) ) ;
F_50 ( F_239 ( NULL , V_179 ) ) ;
F_79 ( & V_18 ) ;
V_40 = F_32 ( V_24 . V_17 ) ;
F_70 ( V_82 , & V_24 . V_50 , V_40 ) ;
F_50 ( F_140 ( & V_92 , 0 ) ) ;
F_82 ( & V_18 ) ;
F_33 (ss, ssid) {
if ( V_16 -> V_388 ) {
struct V_11 * V_22 =
V_24 . V_17 [ V_16 -> V_8 ] ;
V_22 -> V_8 = F_1 ( & V_16 -> V_358 , V_22 , 1 , 2 ,
V_72 ) ;
F_50 ( V_22 -> V_8 < 0 ) ;
} else {
F_326 ( V_16 , false ) ;
}
F_63 ( & V_24 . V_49 [ V_47 ] ,
& V_92 . V_10 . V_83 [ V_47 ] ) ;
if ( V_16 -> V_149 )
continue;
V_92 . V_20 |= 1 << V_16 -> V_8 ;
if ( V_291 && ! V_16 -> V_292 )
V_16 -> V_292 = V_16 -> V_293 ;
if ( ! V_16 -> V_292 )
V_122 |= 1 << V_16 -> V_8 ;
if ( V_16 -> V_292 == V_16 -> V_293 ) {
F_108 ( F_243 ( V_16 , V_16 -> V_292 ) ) ;
} else {
F_108 ( F_244 ( V_16 , V_16 -> V_292 ) ) ;
F_108 ( F_245 ( V_16 , V_16 -> V_293 ) ) ;
}
}
V_389 = F_330 ( L_42 , V_390 ) ;
if ( ! V_389 )
return - V_73 ;
V_212 = F_331 ( & V_338 ) ;
if ( V_212 < 0 ) {
F_332 ( V_389 ) ;
return V_212 ;
}
F_333 ( L_43 , 0 , NULL , & V_391 ) ;
return 0 ;
}
static int T_8 F_334 ( void )
{
V_357 = F_335 ( L_44 , 0 , 1 ) ;
F_50 ( ! V_357 ) ;
V_311 = F_335 ( L_45 ,
0 , 1 ) ;
F_50 ( ! V_311 ) ;
return 0 ;
}
int F_336 ( struct V_126 * V_260 , struct V_329 * V_321 ,
struct V_223 * V_223 , struct V_95 * V_201 )
{
char * V_97 , * V_194 ;
int V_237 ;
struct V_68 * V_19 ;
V_237 = - V_73 ;
V_97 = F_265 ( V_147 , V_72 ) ;
if ( ! V_97 )
goto V_171;
F_79 ( & V_18 ) ;
F_65 ( & V_36 ) ;
F_151 (root) {
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_47 , V_70 = 0 ;
if ( V_19 == & V_92 && ! V_123 )
continue;
F_115 ( V_260 , L_46 , V_19 -> V_88 ) ;
F_33 (ss, ssid)
if ( V_19 -> V_20 & ( 1 << V_47 ) )
F_115 ( V_260 , L_47 , V_70 ++ ? L_10 : L_24 , V_16 -> V_101 ) ;
if ( strlen ( V_19 -> V_101 ) )
F_115 ( V_260 , L_48 , V_70 ? L_10 : L_24 ,
V_19 -> V_101 ) ;
F_196 ( V_260 , ':' ) ;
V_10 = F_85 ( V_201 , V_19 ) ;
V_194 = F_163 ( V_10 , V_97 , V_147 ) ;
if ( ! V_194 ) {
V_237 = - V_392 ;
goto V_23;
}
F_116 ( V_260 , V_194 ) ;
F_196 ( V_260 , '\n' ) ;
}
V_237 = 0 ;
V_23:
F_66 ( & V_36 ) ;
F_82 ( & V_18 ) ;
F_41 ( V_97 ) ;
V_171:
return V_237 ;
}
static int F_337 ( struct V_126 * V_260 , void * V_239 )
{
struct V_15 * V_16 ;
int V_41 ;
F_116 ( V_260 , L_49 ) ;
F_79 ( & V_18 ) ;
F_33 (ss, i)
F_115 ( V_260 , L_50 ,
V_16 -> V_101 , V_16 -> V_19 -> V_88 ,
F_80 ( & V_16 -> V_19 -> V_90 ) , ! V_16 -> V_149 ) ;
F_82 ( & V_18 ) ;
return 0 ;
}
static int F_338 ( struct V_393 * V_393 , struct V_394 * V_394 )
{
return F_339 ( V_394 , F_337 , NULL ) ;
}
void F_340 ( struct V_95 * V_251 )
{
F_109 ( V_251 -> V_203 , & V_24 ) ;
F_56 ( & V_251 -> V_159 ) ;
}
void F_341 ( struct V_95 * V_251 )
{
struct V_15 * V_16 ;
int V_41 ;
if ( V_157 ) {
struct V_42 * V_43 ;
F_45 ( & V_36 ) ;
V_43 = F_86 ( V_153 ) ;
if ( F_39 ( & V_251 -> V_159 ) ) {
F_110 ( V_251 -> V_203 , V_43 ) ;
F_58 ( & V_251 -> V_159 , & V_43 -> V_77 ) ;
F_47 ( V_43 ) ;
}
F_46 ( & V_36 ) ;
}
if ( V_383 ) {
F_33 (ss, i)
if ( V_16 -> V_384 )
V_16 -> V_384 ( V_251 ) ;
}
}
void F_342 ( struct V_95 * V_201 )
{
struct V_15 * V_16 ;
struct V_42 * V_43 ;
bool V_395 = false ;
int V_41 ;
if ( ! F_39 ( & V_201 -> V_159 ) ) {
F_45 ( & V_36 ) ;
F_170 ( & V_201 -> V_159 ) ;
F_46 ( & V_36 ) ;
V_395 = true ;
}
V_43 = F_86 ( V_201 ) ;
F_109 ( V_201 -> V_203 , & V_24 ) ;
if ( V_383 ) {
F_33 (ss, i) {
if ( V_16 -> exit ) {
struct V_11 * V_396 = V_43 -> V_17 [ V_41 ] ;
struct V_11 * V_22 = F_343 ( V_201 , V_41 ) ;
V_16 -> exit ( V_22 , V_396 , V_201 ) ;
}
}
}
if ( V_395 )
F_43 ( V_43 ) ;
}
static void F_40 ( struct V_9 * V_10 )
{
if ( F_28 ( V_10 ) && ! F_344 ( V_10 ) &&
! F_256 ( & V_10 -> V_13 ) && ! F_23 ( V_10 ) )
F_345 ( & V_10 -> V_167 ) ;
}
static void V_168 ( struct V_313 * V_314 )
{
struct V_9 * V_10 =
F_12 ( V_314 , struct V_9 , V_167 ) ;
char * V_397 = NULL , * V_398 = NULL , * V_194 ;
char * V_399 [ 3 ] , * V_400 [ 3 ] ;
F_79 ( & V_18 ) ;
V_397 = F_265 ( V_147 , V_72 ) ;
V_398 = F_346 ( V_10 -> V_19 -> V_130 , V_72 ) ;
if ( ! V_397 || ! V_398 )
goto V_171;
V_194 = F_163 ( V_10 , V_397 , V_147 ) ;
if ( ! V_194 )
goto V_171;
V_399 [ 0 ] = V_398 ;
V_399 [ 1 ] = V_194 ;
V_399 [ 2 ] = NULL ;
V_400 [ 0 ] = L_51 ;
V_400 [ 1 ] = L_52 ;
V_400 [ 2 ] = NULL ;
F_82 ( & V_18 ) ;
F_347 ( V_399 [ 0 ] , V_399 , V_400 , V_401 ) ;
goto V_189;
V_171:
F_82 ( & V_18 ) ;
V_189:
F_41 ( V_398 ) ;
F_41 ( V_397 ) ;
}
static int T_8 F_348 ( char * V_402 )
{
struct V_15 * V_16 ;
char * V_135 ;
int V_41 ;
while ( ( V_135 = F_121 ( & V_402 , L_10 ) ) != NULL ) {
if ( ! * V_135 )
continue;
F_33 (ss, i) {
if ( ! strcmp ( V_135 , V_16 -> V_101 ) ) {
V_16 -> V_149 = 1 ;
F_327 ( V_381 L_53
L_54 , V_16 -> V_101 ) ;
break;
}
}
}
return 1 ;
}
static int T_8 F_349 ( char * V_402 )
{
F_327 ( L_55 ) ;
V_291 = true ;
return 0 ;
}
struct V_11 * F_350 ( struct V_182 * V_182 ,
struct V_15 * V_16 )
{
struct V_115 * V_29 = F_292 ( V_182 ) ;
struct V_11 * V_22 = NULL ;
struct V_9 * V_10 ;
if ( V_182 -> V_336 -> V_337 != & V_338 || ! V_29 ||
F_97 ( V_29 ) != V_116 )
return F_155 ( - V_403 ) ;
F_19 () ;
V_10 = F_293 ( V_29 -> V_30 ) ;
if ( V_10 )
V_22 = F_13 ( V_10 , V_16 ) ;
if ( ! V_22 || ! F_20 ( V_22 ) )
V_22 = F_155 ( - V_150 ) ;
F_22 () ;
return V_22 ;
}
struct V_11 * F_351 ( int V_8 , struct V_15 * V_16 )
{
F_76 ( ! F_352 () ) ;
return F_353 ( & V_16 -> V_358 , V_8 ) ;
}
static struct V_11 *
F_354 ( struct V_11 * V_12 )
{
struct V_11 * V_22 = F_57 ( sizeof( * V_22 ) , V_72 ) ;
if ( ! V_22 )
return F_155 ( - V_73 ) ;
return V_22 ;
}
static void F_355 ( struct V_11 * V_22 )
{
F_41 ( V_22 ) ;
}
static T_7 F_356 ( struct V_11 * V_22 ,
struct V_31 * V_32 )
{
return F_246 ( V_22 -> V_9 ) ;
}
static T_7 F_357 ( struct V_11 * V_22 ,
struct V_31 * V_32 )
{
return ( T_7 ) ( unsigned long ) V_153 -> V_203 ;
}
static T_7 F_358 ( struct V_11 * V_22 ,
struct V_31 * V_32 )
{
T_7 V_70 ;
F_19 () ;
V_70 = F_80 ( & F_86 ( V_153 ) -> V_48 ) ;
F_22 () ;
return V_70 ;
}
static int F_359 ( struct V_126 * V_127 , void * V_239 )
{
struct V_44 * V_45 ;
struct V_42 * V_43 ;
char * V_404 ;
V_404 = F_265 ( V_405 + 1 , V_72 ) ;
if ( ! V_404 )
return - V_73 ;
F_65 ( & V_36 ) ;
F_19 () ;
V_43 = F_293 ( V_153 -> V_203 ) ;
F_69 (link, &cset->cgrp_links, cgrp_link) {
struct V_9 * V_81 = V_45 -> V_10 ;
F_360 ( V_81 , V_404 , V_405 + 1 ) ;
F_115 ( V_127 , L_56 ,
V_81 -> V_19 -> V_88 , V_404 ) ;
}
F_22 () ;
F_66 ( & V_36 ) ;
F_41 ( V_404 ) ;
return 0 ;
}
static int F_361 ( struct V_126 * V_127 , void * V_239 )
{
struct V_11 * V_22 = F_195 ( V_127 ) ;
struct V_44 * V_45 ;
F_65 ( & V_36 ) ;
F_69 (link, &css->cgroup->cset_links, cset_link) {
struct V_42 * V_43 = V_45 -> V_43 ;
struct V_95 * V_96 ;
int V_70 = 0 ;
F_115 ( V_127 , L_57 , V_43 ) ;
F_69 (task, &cset->tasks, cg_list) {
if ( V_70 ++ > V_406 )
goto V_407;
F_115 ( V_127 , L_58 , F_289 ( V_96 ) ) ;
}
F_69 (task, &cset->mg_tasks, cg_list) {
if ( V_70 ++ > V_406 )
goto V_407;
F_115 ( V_127 , L_58 , F_289 ( V_96 ) ) ;
}
continue;
V_407:
F_116 ( V_127 , L_59 ) ;
}
F_66 ( & V_36 ) ;
return 0 ;
}
static T_7 F_362 ( struct V_11 * V_22 , struct V_31 * V_32 )
{
return ( ! F_344 ( V_22 -> V_9 ) &&
! F_256 ( & V_22 -> V_9 -> V_13 ) ) ;
}
