static int F_1 ( struct V_1 * V_1 , void * V_2 , int V_3 , int V_4 ,
T_1 V_5 )
{
int V_6 ;
F_2 ( V_5 ) ;
F_3 ( & V_7 ) ;
V_6 = F_4 ( V_1 , V_2 , V_3 , V_4 , V_5 & ~ V_8 ) ;
F_5 ( & V_7 ) ;
F_6 () ;
return V_6 ;
}
static void * F_7 ( struct V_1 * V_1 , void * V_2 , int V_9 )
{
void * V_6 ;
F_3 ( & V_7 ) ;
V_6 = F_8 ( V_1 , V_2 , V_9 ) ;
F_5 ( & V_7 ) ;
return V_6 ;
}
static void F_9 ( struct V_1 * V_1 , int V_9 )
{
F_3 ( & V_7 ) ;
F_10 ( V_1 , V_9 ) ;
F_5 ( & V_7 ) ;
}
static struct V_10 * F_11 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 . V_15 ;
if ( V_13 )
return F_12 ( V_13 , struct V_10 , V_14 ) ;
return NULL ;
}
static struct V_12 * F_13 ( struct V_10 * V_11 ,
struct V_16 * V_17 )
{
if ( V_17 )
return F_14 ( V_11 -> V_18 [ V_17 -> V_9 ] ,
F_15 ( & V_19 ) ) ;
else
return & V_11 -> V_14 ;
}
static struct V_12 * F_16 ( struct V_10 * V_11 ,
struct V_16 * V_17 )
{
F_17 ( & V_19 ) ;
if ( ! V_17 )
return & V_11 -> V_14 ;
if ( ! ( V_11 -> V_20 -> V_21 & ( 1 << V_17 -> V_9 ) ) )
return NULL ;
while ( F_11 ( V_11 ) &&
! ( F_11 ( V_11 ) -> V_22 & ( 1 << V_17 -> V_9 ) ) )
V_11 = F_11 ( V_11 ) ;
return F_13 ( V_11 , V_17 ) ;
}
struct V_12 * F_18 ( struct V_10 * V_11 ,
struct V_16 * V_17 )
{
struct V_12 * V_23 ;
F_19 () ;
do {
V_23 = F_13 ( V_11 , V_17 ) ;
if ( V_23 && F_20 ( V_23 ) )
goto V_24;
V_11 = F_11 ( V_11 ) ;
} while ( V_11 );
V_23 = V_25 . V_18 [ V_17 -> V_9 ] ;
F_21 ( V_23 ) ;
V_24:
F_22 () ;
return V_23 ;
}
static inline bool F_23 ( const struct V_10 * V_11 )
{
return ! ( V_11 -> V_14 . V_26 & V_27 ) ;
}
struct V_12 * F_24 ( struct V_28 * V_29 )
{
struct V_10 * V_11 = V_29 -> V_30 -> V_15 -> V_31 ;
struct V_32 * V_33 = F_25 ( V_29 ) ;
if ( V_33 -> V_17 )
return F_26 ( V_11 -> V_18 [ V_33 -> V_17 -> V_9 ] ) ;
else
return & V_11 -> V_14 ;
}
bool F_27 ( struct V_10 * V_11 , struct V_10 * V_34 )
{
while ( V_11 ) {
if ( V_11 == V_34 )
return true ;
V_11 = F_11 ( V_11 ) ;
}
return false ;
}
static int F_28 ( const struct V_10 * V_11 )
{
return F_29 ( V_35 , & V_11 -> V_26 ) ;
}
static void F_30 ( struct V_10 * V_11 , bool V_36 )
{
F_17 ( & V_37 ) ;
do {
bool V_38 ;
if ( V_36 )
V_38 = ! V_11 -> V_39 ++ ;
else
V_38 = ! -- V_11 -> V_39 ;
if ( ! V_38 )
break;
if ( V_11 -> V_40 )
F_31 ( V_11 -> V_40 ) ;
V_11 = F_11 ( V_11 ) ;
} while ( V_11 );
}
static unsigned long F_32 ( struct V_12 * V_23 [] )
{
unsigned long V_41 = 0UL ;
struct V_16 * V_17 ;
int V_42 ;
F_33 (ss, i)
V_41 += ( unsigned long ) V_23 [ V_42 ] ;
V_41 = ( V_41 >> 16 ) ^ V_41 ;
return V_41 ;
}
static void F_34 ( struct V_43 * V_44 )
{
struct V_45 * V_46 , * V_47 ;
struct V_16 * V_17 ;
int V_48 ;
F_17 ( & V_37 ) ;
if ( ! F_35 ( & V_44 -> V_49 ) )
return;
F_33 (ss, ssid)
F_36 ( & V_44 -> V_50 [ V_48 ] ) ;
F_37 ( & V_44 -> V_51 ) ;
V_52 -- ;
F_38 (link, tmp_link, &cset->cgrp_links, cgrp_link) {
struct V_10 * V_11 = V_46 -> V_11 ;
F_36 ( & V_46 -> V_53 ) ;
F_36 ( & V_46 -> V_54 ) ;
if ( F_39 ( & V_11 -> V_55 ) ) {
F_30 ( V_11 , false ) ;
F_40 ( V_11 ) ;
}
F_41 ( V_46 ) ;
}
F_42 ( V_44 , V_56 ) ;
}
static void F_43 ( struct V_43 * V_44 )
{
if ( F_44 ( & V_44 -> V_49 , - 1 , 1 ) )
return;
F_45 ( & V_37 ) ;
F_34 ( V_44 ) ;
F_46 ( & V_37 ) ;
}
static inline void F_47 ( struct V_43 * V_44 )
{
F_48 ( & V_44 -> V_49 ) ;
}
static bool F_49 ( struct V_43 * V_44 ,
struct V_43 * V_57 ,
struct V_10 * V_58 ,
struct V_12 * V_59 [] )
{
struct V_60 * V_61 , * V_62 ;
if ( memcmp ( V_59 , V_44 -> V_18 , sizeof( V_44 -> V_18 ) ) )
return false ;
V_61 = & V_44 -> V_63 ;
V_62 = & V_57 -> V_63 ;
while ( 1 ) {
struct V_45 * V_64 , * V_65 ;
struct V_10 * V_66 , * V_67 ;
V_61 = V_61 -> V_68 ;
V_62 = V_62 -> V_68 ;
if ( V_61 == & V_44 -> V_63 ) {
F_50 ( V_62 != & V_57 -> V_63 ) ;
break;
} else {
F_50 ( V_62 == & V_57 -> V_63 ) ;
}
V_64 = F_51 ( V_61 , struct V_45 , V_54 ) ;
V_65 = F_51 ( V_62 , struct V_45 , V_54 ) ;
V_66 = V_64 -> V_11 ;
V_67 = V_65 -> V_11 ;
F_50 ( V_66 -> V_20 != V_67 -> V_20 ) ;
if ( V_66 -> V_20 == V_58 -> V_20 ) {
if ( V_66 != V_58 )
return false ;
} else {
if ( V_66 != V_67 )
return false ;
}
}
return true ;
}
static struct V_43 * F_52 ( struct V_43 * V_57 ,
struct V_10 * V_11 ,
struct V_12 * V_59 [] )
{
struct V_69 * V_20 = V_11 -> V_20 ;
struct V_16 * V_17 ;
struct V_43 * V_44 ;
unsigned long V_41 ;
int V_42 ;
F_33 (ss, i) {
if ( V_20 -> V_21 & ( 1UL << V_42 ) ) {
V_59 [ V_42 ] = F_16 ( V_11 , V_17 ) ;
} else {
V_59 [ V_42 ] = V_57 -> V_18 [ V_42 ] ;
}
}
V_41 = F_32 ( V_59 ) ;
F_53 (css_set_table, cset, hlist, key) {
if ( ! F_49 ( V_44 , V_57 , V_11 , V_59 ) )
continue;
return V_44 ;
}
return NULL ;
}
static void F_54 ( struct V_60 * V_70 )
{
struct V_45 * V_46 , * V_47 ;
F_38 (link, tmp_link, links_to_free, cset_link) {
F_36 ( & V_46 -> V_53 ) ;
F_41 ( V_46 ) ;
}
}
static int F_55 ( int V_71 , struct V_60 * V_72 )
{
struct V_45 * V_46 ;
int V_42 ;
F_56 ( V_72 ) ;
for ( V_42 = 0 ; V_42 < V_71 ; V_42 ++ ) {
V_46 = F_57 ( sizeof( * V_46 ) , V_73 ) ;
if ( ! V_46 ) {
F_54 ( V_72 ) ;
return - V_74 ;
}
F_58 ( & V_46 -> V_53 , V_72 ) ;
}
return 0 ;
}
static void F_59 ( struct V_60 * V_72 , struct V_43 * V_44 ,
struct V_10 * V_11 )
{
struct V_45 * V_46 ;
F_50 ( F_39 ( V_72 ) ) ;
if ( F_60 ( V_11 ) )
V_44 -> V_75 = V_11 ;
V_46 = F_61 ( V_72 , struct V_45 , V_53 ) ;
V_46 -> V_44 = V_44 ;
V_46 -> V_11 = V_11 ;
if ( F_39 ( & V_11 -> V_55 ) )
F_30 ( V_11 , true ) ;
F_62 ( & V_46 -> V_53 , & V_11 -> V_55 ) ;
F_63 ( & V_46 -> V_54 , & V_44 -> V_63 ) ;
}
static struct V_43 * F_64 ( struct V_43 * V_57 ,
struct V_10 * V_11 )
{
struct V_12 * V_59 [ V_76 ] = { } ;
struct V_43 * V_44 ;
struct V_60 V_72 ;
struct V_45 * V_46 ;
struct V_16 * V_17 ;
unsigned long V_41 ;
int V_48 ;
F_17 ( & V_19 ) ;
F_65 ( & V_37 ) ;
V_44 = F_52 ( V_57 , V_11 , V_59 ) ;
if ( V_44 )
F_47 ( V_44 ) ;
F_66 ( & V_37 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_57 ( sizeof( * V_44 ) , V_73 ) ;
if ( ! V_44 )
return NULL ;
if ( F_55 ( V_77 , & V_72 ) < 0 ) {
F_41 ( V_44 ) ;
return NULL ;
}
F_67 ( & V_44 -> V_49 , 1 ) ;
F_56 ( & V_44 -> V_63 ) ;
F_56 ( & V_44 -> V_78 ) ;
F_56 ( & V_44 -> V_79 ) ;
F_56 ( & V_44 -> V_80 ) ;
F_56 ( & V_44 -> V_81 ) ;
F_68 ( & V_44 -> V_51 ) ;
memcpy ( V_44 -> V_18 , V_59 , sizeof( V_44 -> V_18 ) ) ;
F_45 ( & V_37 ) ;
F_69 (link, &old_cset->cgrp_links, cgrp_link) {
struct V_10 * V_82 = V_46 -> V_11 ;
if ( V_82 -> V_20 == V_11 -> V_20 )
V_82 = V_11 ;
F_59 ( & V_72 , V_44 , V_82 ) ;
}
F_50 ( ! F_39 ( & V_72 ) ) ;
V_52 ++ ;
V_41 = F_32 ( V_44 -> V_18 ) ;
F_70 ( V_83 , & V_44 -> V_51 , V_41 ) ;
F_33 (ss, ssid)
F_63 ( & V_44 -> V_50 [ V_48 ] ,
& V_44 -> V_18 [ V_48 ] -> V_10 -> V_84 [ V_48 ] ) ;
F_46 ( & V_37 ) ;
return V_44 ;
}
void F_71 ( struct V_85 * V_86 )
{
F_65 ( & V_86 -> signal -> V_87 ) ;
}
void F_72 ( struct V_85 * V_86 )
{
F_66 ( & V_86 -> signal -> V_87 ) ;
}
static void F_73 ( struct V_85 * V_86 )
{
F_45 ( & V_86 -> signal -> V_87 ) ;
}
static inline void F_74 ( struct V_85 * V_86 )
{
F_46 ( & V_86 -> signal -> V_87 ) ;
}
static struct V_69 * F_75 ( struct V_88 * V_89 )
{
struct V_10 * V_90 = V_89 -> V_30 -> V_31 ;
return V_90 -> V_20 ;
}
static int F_76 ( struct V_69 * V_20 )
{
int V_9 ;
F_17 ( & V_19 ) ;
V_9 = F_77 ( & V_91 , V_20 , 0 , 0 , V_73 ) ;
if ( V_9 < 0 )
return V_9 ;
V_20 -> V_92 = V_9 ;
return 0 ;
}
static void F_78 ( struct V_69 * V_20 )
{
F_17 ( & V_19 ) ;
if ( V_20 -> V_92 ) {
F_10 ( & V_91 , V_20 -> V_92 ) ;
V_20 -> V_92 = 0 ;
}
}
static void F_79 ( struct V_69 * V_20 )
{
if ( V_20 ) {
F_80 ( V_20 -> V_92 ) ;
F_81 ( & V_20 -> V_93 ) ;
F_41 ( V_20 ) ;
}
}
static void F_82 ( struct V_69 * V_20 )
{
struct V_10 * V_11 = & V_20 -> V_11 ;
struct V_45 * V_46 , * V_47 ;
F_83 ( & V_19 ) ;
F_50 ( F_84 ( & V_20 -> V_94 ) ) ;
F_50 ( ! F_39 ( & V_11 -> V_14 . V_95 ) ) ;
F_85 ( & V_96 , V_20 -> V_21 ) ;
F_45 ( & V_37 ) ;
F_38 (link, tmp_link, &cgrp->cset_links, cset_link) {
F_36 ( & V_46 -> V_53 ) ;
F_36 ( & V_46 -> V_54 ) ;
F_41 ( V_46 ) ;
}
F_46 ( & V_37 ) ;
if ( ! F_39 ( & V_20 -> V_97 ) ) {
F_36 ( & V_20 -> V_97 ) ;
V_77 -- ;
}
F_78 ( V_20 ) ;
F_86 ( & V_19 ) ;
F_87 ( V_20 -> V_89 ) ;
F_79 ( V_20 ) ;
}
static struct V_10 * F_88 ( struct V_43 * V_44 ,
struct V_69 * V_20 )
{
struct V_10 * V_98 = NULL ;
F_17 ( & V_19 ) ;
F_17 ( & V_37 ) ;
if ( V_44 == & V_25 ) {
V_98 = & V_20 -> V_11 ;
} else {
struct V_45 * V_46 ;
F_69 (link, &cset->cgrp_links, cgrp_link) {
struct V_10 * V_82 = V_46 -> V_11 ;
if ( V_82 -> V_20 == V_20 ) {
V_98 = V_82 ;
break;
}
}
}
F_50 ( ! V_98 ) ;
return V_98 ;
}
static struct V_10 * F_89 ( struct V_85 * V_99 ,
struct V_69 * V_20 )
{
return F_88 ( F_90 ( V_99 ) , V_20 ) ;
}
static char * F_91 ( struct V_10 * V_11 , const struct V_32 * V_33 ,
char * V_100 )
{
struct V_16 * V_17 = V_33 -> V_17 ;
if ( V_33 -> V_17 && ! ( V_33 -> V_26 & V_101 ) &&
! ( V_11 -> V_20 -> V_26 & V_102 ) )
snprintf ( V_100 , V_103 , L_1 ,
F_60 ( V_11 ) ? V_17 -> V_104 : V_17 -> V_105 ,
V_33 -> V_104 ) ;
else
strncpy ( V_100 , V_33 -> V_104 , V_103 ) ;
return V_100 ;
}
static T_2 F_92 ( const struct V_32 * V_33 )
{
T_2 V_106 = 0 ;
if ( V_33 -> V_106 )
return V_33 -> V_106 ;
if ( V_33 -> V_107 || V_33 -> V_108 || V_33 -> V_109 )
V_106 |= V_110 ;
if ( V_33 -> V_111 || V_33 -> V_112 || V_33 -> V_113 )
V_106 |= V_114 ;
return V_106 ;
}
static void F_93 ( struct V_10 * V_11 )
{
F_80 ( F_23 ( V_11 ) ) ;
F_21 ( & V_11 -> V_14 ) ;
}
static bool F_94 ( struct V_10 * V_11 )
{
return F_95 ( & V_11 -> V_14 ) ;
}
static void F_96 ( struct V_10 * V_11 )
{
F_97 ( & V_11 -> V_14 ) ;
}
static unsigned long F_98 ( struct V_10 * V_11 ,
unsigned long V_115 )
{
struct V_10 * V_15 = F_11 ( V_11 ) ;
unsigned long V_116 = V_115 ;
struct V_16 * V_17 ;
int V_48 ;
F_17 ( & V_19 ) ;
if ( ! F_60 ( V_11 ) )
return V_116 ;
while ( true ) {
unsigned long V_117 = V_116 ;
F_99 (ss, ssid, &cur_ss_mask)
V_117 |= V_17 -> V_118 ;
if ( V_15 )
V_117 &= V_15 -> V_22 ;
else
V_117 &= V_11 -> V_20 -> V_21 ;
if ( V_117 == V_116 )
break;
V_116 = V_117 ;
}
return V_116 ;
}
static void F_100 ( struct V_10 * V_11 )
{
V_11 -> V_22 =
F_98 ( V_11 , V_11 -> V_115 ) ;
}
static void F_101 ( struct V_119 * V_30 )
{
struct V_10 * V_11 ;
if ( F_102 ( V_30 ) == V_120 )
V_11 = V_30 -> V_31 ;
else
V_11 = V_30 -> V_15 -> V_31 ;
F_86 ( & V_19 ) ;
F_103 ( V_30 ) ;
F_96 ( V_11 ) ;
}
static struct V_10 * F_104 ( struct V_119 * V_30 )
{
struct V_10 * V_11 ;
if ( F_102 ( V_30 ) == V_120 )
V_11 = V_30 -> V_31 ;
else
V_11 = V_30 -> V_15 -> V_31 ;
if ( ! F_94 ( V_11 ) )
return NULL ;
F_105 ( V_30 ) ;
F_83 ( & V_19 ) ;
if ( ! F_23 ( V_11 ) )
return V_11 ;
F_101 ( V_30 ) ;
return NULL ;
}
static void F_106 ( struct V_10 * V_11 , const struct V_32 * V_33 )
{
char V_104 [ V_103 ] ;
F_17 ( & V_19 ) ;
F_107 ( V_11 -> V_30 , F_91 ( V_11 , V_33 , V_104 ) ) ;
}
static void F_108 ( struct V_10 * V_11 , unsigned long V_21 )
{
struct V_16 * V_17 ;
int V_42 ;
F_33 (ss, i) {
struct V_32 * V_121 ;
if ( ! ( V_21 & ( 1 << V_42 ) ) )
continue;
F_69 (cfts, &ss->cfts, node)
F_109 ( V_11 , V_121 , false ) ;
}
}
static int F_85 ( struct V_69 * V_122 ,
unsigned long V_123 )
{
struct V_16 * V_17 ;
unsigned long V_124 ;
int V_48 , V_42 , V_6 ;
F_17 ( & V_19 ) ;
F_99 (ss, ssid, &ss_mask) {
if ( F_110 ( NULL , F_13 ( & V_17 -> V_20 -> V_11 , V_17 ) ) )
return - V_125 ;
if ( V_17 -> V_20 != & V_96 && V_122 != & V_96 )
return - V_125 ;
}
V_124 = V_123 ;
if ( V_122 == & V_96 )
V_124 &= ~ V_126 ;
V_6 = F_111 ( & V_122 -> V_11 , V_124 ) ;
if ( V_6 ) {
if ( V_122 != & V_96 )
return V_6 ;
if ( V_127 ) {
F_112 ( L_2 ,
V_6 , V_123 ) ;
F_112 ( L_3 ) ;
}
}
F_99 (ss, ssid, &ss_mask)
F_108 ( & V_17 -> V_20 -> V_11 , 1 << V_48 ) ;
F_99 (ss, ssid, &ss_mask) {
struct V_69 * V_128 ;
struct V_12 * V_23 ;
struct V_43 * V_44 ;
V_128 = V_17 -> V_20 ;
V_23 = F_13 ( & V_128 -> V_11 , V_17 ) ;
F_113 ( ! V_23 || F_13 ( & V_122 -> V_11 , V_17 ) ) ;
F_114 ( V_128 -> V_11 . V_18 [ V_48 ] , NULL ) ;
F_115 ( V_122 -> V_11 . V_18 [ V_48 ] , V_23 ) ;
V_17 -> V_20 = V_122 ;
V_23 -> V_10 = & V_122 -> V_11 ;
F_45 ( & V_37 ) ;
F_116 (css_set_table, i, cset, hlist)
F_117 ( & V_44 -> V_50 [ V_17 -> V_9 ] ,
& V_122 -> V_11 . V_84 [ V_17 -> V_9 ] ) ;
F_46 ( & V_37 ) ;
V_128 -> V_21 &= ~ ( 1 << V_48 ) ;
V_128 -> V_11 . V_115 &= ~ ( 1 << V_48 ) ;
F_100 ( & V_128 -> V_11 ) ;
V_122 -> V_21 |= 1 << V_48 ;
if ( V_122 != & V_96 ) {
V_122 -> V_11 . V_115 |= 1 << V_48 ;
F_100 ( & V_122 -> V_11 ) ;
}
if ( V_17 -> V_129 )
V_17 -> V_129 ( V_23 ) ;
}
F_118 ( V_122 -> V_11 . V_30 ) ;
return 0 ;
}
static int F_119 ( struct V_130 * V_131 ,
struct V_88 * V_89 )
{
struct V_69 * V_20 = F_75 ( V_89 ) ;
struct V_16 * V_17 ;
int V_48 ;
if ( V_20 != & V_96 )
F_33 (ss, ssid)
if ( V_20 -> V_21 & ( 1 << V_48 ) )
F_120 ( V_131 , V_17 -> V_105 , NULL ) ;
if ( V_20 -> V_26 & V_102 )
F_121 ( V_131 , L_4 ) ;
if ( V_20 -> V_26 & V_132 )
F_121 ( V_131 , L_5 ) ;
F_122 ( & V_133 ) ;
if ( strlen ( V_20 -> V_134 ) )
F_120 ( V_131 , L_6 ,
V_20 -> V_134 ) ;
F_123 ( & V_133 ) ;
if ( F_29 ( V_135 , & V_20 -> V_11 . V_26 ) )
F_121 ( V_131 , L_7 ) ;
if ( strlen ( V_20 -> V_104 ) )
F_120 ( V_131 , L_8 , V_20 -> V_104 ) ;
return 0 ;
}
static int F_124 ( char * V_136 , struct V_137 * V_138 )
{
char * V_139 , * V_140 = V_136 ;
bool V_141 = false , V_142 = false ;
unsigned long V_143 = - 1UL ;
struct V_16 * V_17 ;
int V_144 = 0 ;
int V_42 ;
#ifdef F_125
V_143 = ~ ( 1U << V_145 ) ;
#endif
memset ( V_138 , 0 , sizeof( * V_138 ) ) ;
while ( ( V_139 = F_126 ( & V_140 , L_9 ) ) != NULL ) {
V_144 ++ ;
if ( ! * V_139 )
return - V_146 ;
if ( ! strcmp ( V_139 , L_10 ) ) {
V_138 -> V_147 = true ;
continue;
}
if ( ! strcmp ( V_139 , L_11 ) ) {
if ( V_142 )
return - V_146 ;
V_141 = true ;
continue;
}
if ( ! strcmp ( V_139 , L_12 ) ) {
V_138 -> V_26 |= V_148 ;
continue;
}
if ( ! strcmp ( V_139 , L_13 ) ) {
V_138 -> V_26 |= V_102 ;
continue;
}
if ( ! strcmp ( V_139 , L_14 ) ) {
V_138 -> V_149 = true ;
continue;
}
if ( ! strcmp ( V_139 , L_15 ) ) {
V_138 -> V_26 |= V_132 ;
continue;
}
if ( ! strncmp ( V_139 , L_16 , 14 ) ) {
if ( V_138 -> V_150 )
return - V_146 ;
V_138 -> V_150 =
F_127 ( V_139 + 14 , V_151 - 1 , V_73 ) ;
if ( ! V_138 -> V_150 )
return - V_74 ;
continue;
}
if ( ! strncmp ( V_139 , L_17 , 5 ) ) {
const char * V_104 = V_139 + 5 ;
if ( ! strlen ( V_104 ) )
return - V_146 ;
for ( V_42 = 0 ; V_42 < strlen ( V_104 ) ; V_42 ++ ) {
char V_82 = V_104 [ V_42 ] ;
if ( isalnum ( V_82 ) )
continue;
if ( ( V_82 == '.' ) || ( V_82 == '-' ) || ( V_82 == '_' ) )
continue;
return - V_146 ;
}
if ( V_138 -> V_104 )
return - V_146 ;
V_138 -> V_104 = F_127 ( V_104 ,
V_152 - 1 ,
V_73 ) ;
if ( ! V_138 -> V_104 )
return - V_74 ;
continue;
}
F_33 (ss, i) {
if ( strcmp ( V_139 , V_17 -> V_105 ) )
continue;
if ( V_17 -> V_153 )
continue;
if ( V_141 )
return - V_146 ;
V_138 -> V_21 |= ( 1 << V_42 ) ;
V_142 = true ;
break;
}
if ( V_42 == V_76 )
return - V_154 ;
}
if ( V_138 -> V_26 & V_148 ) {
F_112 ( L_18 ) ;
if ( V_144 != 1 ) {
F_128 ( L_19 ) ;
return - V_146 ;
}
return 0 ;
}
if ( V_141 || ( ! V_142 && ! V_138 -> V_147 && ! V_138 -> V_104 ) )
F_33 (ss, i)
if ( ! V_17 -> V_153 )
V_138 -> V_21 |= ( 1 << V_42 ) ;
if ( ! V_138 -> V_21 && ! V_138 -> V_104 )
return - V_146 ;
if ( ( V_138 -> V_26 & V_102 ) && ( V_138 -> V_21 & V_143 ) )
return - V_146 ;
if ( V_138 -> V_21 && V_138 -> V_147 )
return - V_146 ;
return 0 ;
}
static int F_129 ( struct V_88 * V_89 , int * V_26 , char * V_136 )
{
int V_6 = 0 ;
struct V_69 * V_20 = F_75 ( V_89 ) ;
struct V_137 V_138 ;
unsigned long V_155 , V_156 ;
if ( V_20 == & V_96 ) {
F_128 ( L_20 ) ;
return - V_146 ;
}
F_83 ( & V_19 ) ;
V_6 = F_124 ( V_136 , & V_138 ) ;
if ( V_6 )
goto V_24;
if ( V_138 . V_21 != V_20 -> V_21 || V_138 . V_150 )
F_112 ( L_21 ,
F_130 ( V_157 ) , V_157 -> V_158 ) ;
V_155 = V_138 . V_21 & ~ V_20 -> V_21 ;
V_156 = V_20 -> V_21 & ~ V_138 . V_21 ;
if ( ( V_138 . V_26 ^ V_20 -> V_26 ) ||
( V_138 . V_104 && strcmp ( V_138 . V_104 , V_20 -> V_104 ) ) ) {
F_128 ( L_22 ,
V_138 . V_26 , V_138 . V_104 ? : L_23 , V_20 -> V_26 , V_20 -> V_104 ) ;
V_6 = - V_146 ;
goto V_24;
}
if ( ! F_39 ( & V_20 -> V_11 . V_14 . V_95 ) ) {
V_6 = - V_125 ;
goto V_24;
}
V_6 = F_85 ( V_20 , V_155 ) ;
if ( V_6 )
goto V_24;
F_85 ( & V_96 , V_156 ) ;
if ( V_138 . V_150 ) {
F_122 ( & V_133 ) ;
strcpy ( V_20 -> V_134 , V_138 . V_150 ) ;
F_123 ( & V_133 ) ;
}
V_24:
F_41 ( V_138 . V_150 ) ;
F_41 ( V_138 . V_104 ) ;
F_86 ( & V_19 ) ;
return V_6 ;
}
static void F_131 ( void )
{
struct V_85 * V_159 , * V_160 ;
F_45 ( & V_37 ) ;
if ( V_161 )
goto V_24;
V_161 = true ;
F_132 ( & V_162 ) ;
F_133 (g, p) {
F_80 ( ! F_39 ( & V_159 -> V_163 ) ||
F_90 ( V_159 ) != & V_25 ) ;
F_134 ( & V_159 -> V_164 -> V_165 ) ;
if ( ! ( V_159 -> V_26 & V_166 ) ) {
struct V_43 * V_44 = F_90 ( V_159 ) ;
F_58 ( & V_159 -> V_163 , & V_44 -> V_78 ) ;
F_47 ( V_44 ) ;
}
F_135 ( & V_159 -> V_164 -> V_165 ) ;
} F_136 ( V_160 , V_159 ) ;
F_137 ( & V_162 ) ;
V_24:
F_46 ( & V_37 ) ;
}
static void F_138 ( struct V_10 * V_11 )
{
struct V_16 * V_17 ;
int V_48 ;
F_56 ( & V_11 -> V_14 . V_167 ) ;
F_56 ( & V_11 -> V_14 . V_95 ) ;
F_56 ( & V_11 -> V_55 ) ;
F_56 ( & V_11 -> V_168 ) ;
F_139 ( & V_11 -> V_169 ) ;
V_11 -> V_14 . V_10 = V_11 ;
V_11 -> V_14 . V_26 |= V_27 ;
F_33 (ss, ssid)
F_56 ( & V_11 -> V_84 [ V_48 ] ) ;
F_140 ( & V_11 -> V_170 ) ;
F_141 ( & V_11 -> V_171 , V_172 ) ;
}
static void F_142 ( struct V_69 * V_20 ,
struct V_137 * V_138 )
{
struct V_10 * V_11 = & V_20 -> V_11 ;
F_56 ( & V_20 -> V_97 ) ;
F_67 ( & V_20 -> V_94 , 1 ) ;
V_11 -> V_20 = V_20 ;
F_138 ( V_11 ) ;
F_143 ( & V_20 -> V_93 ) ;
V_20 -> V_26 = V_138 -> V_26 ;
if ( V_138 -> V_150 )
strcpy ( V_20 -> V_134 , V_138 -> V_150 ) ;
if ( V_138 -> V_104 )
strcpy ( V_20 -> V_104 , V_138 -> V_104 ) ;
if ( V_138 -> V_149 )
F_144 ( V_135 , & V_20 -> V_11 . V_26 ) ;
}
static int F_145 ( struct V_69 * V_20 , unsigned long V_123 )
{
F_146 ( V_72 ) ;
struct V_10 * V_90 = & V_20 -> V_11 ;
struct V_32 * V_173 ;
struct V_43 * V_44 ;
int V_42 , V_6 ;
F_17 ( & V_19 ) ;
V_6 = F_1 ( & V_20 -> V_93 , V_90 , 1 , 2 , V_73 ) ;
if ( V_6 < 0 )
goto V_174;
V_90 -> V_9 = V_6 ;
V_6 = F_147 ( & V_90 -> V_14 . V_175 , V_176 , 0 ,
V_73 ) ;
if ( V_6 )
goto V_174;
V_6 = F_55 ( V_52 , & V_72 ) ;
if ( V_6 )
goto V_177;
V_6 = F_76 ( V_20 ) ;
if ( V_6 )
goto V_177;
V_20 -> V_89 = F_148 ( & V_178 ,
V_179 ,
V_90 ) ;
if ( F_149 ( V_20 -> V_89 ) ) {
V_6 = F_150 ( V_20 -> V_89 ) ;
goto V_180;
}
V_90 -> V_30 = V_20 -> V_89 -> V_30 ;
if ( V_20 == & V_96 )
V_173 = V_181 ;
else
V_173 = V_182 ;
V_6 = F_109 ( V_90 , V_173 , true ) ;
if ( V_6 )
goto V_183;
V_6 = F_85 ( V_20 , V_123 ) ;
if ( V_6 )
goto V_183;
F_58 ( & V_20 -> V_97 , & V_184 ) ;
V_77 ++ ;
F_45 ( & V_37 ) ;
F_116 (css_set_table, i, cset, hlist)
F_59 ( & V_72 , V_44 , V_90 ) ;
F_46 ( & V_37 ) ;
F_50 ( ! F_39 ( & V_90 -> V_14 . V_95 ) ) ;
F_50 ( F_84 ( & V_20 -> V_94 ) != 1 ) ;
F_118 ( V_90 -> V_30 ) ;
V_6 = 0 ;
goto V_174;
V_183:
F_87 ( V_20 -> V_89 ) ;
V_20 -> V_89 = NULL ;
V_180:
F_78 ( V_20 ) ;
V_177:
F_151 ( & V_90 -> V_14 . V_175 ) ;
V_174:
F_54 ( & V_72 ) ;
return V_6 ;
}
static struct V_185 * F_152 ( struct V_186 * V_187 ,
int V_26 , const char * V_188 ,
void * V_136 )
{
struct V_189 * V_190 = NULL ;
struct V_16 * V_17 ;
struct V_69 * V_20 ;
struct V_137 V_138 ;
struct V_185 * V_185 ;
int V_6 ;
int V_42 ;
bool V_191 ;
if ( ! V_161 )
F_131 () ;
F_83 ( & V_19 ) ;
V_6 = F_124 ( V_136 , & V_138 ) ;
if ( V_6 )
goto V_24;
if ( V_138 . V_26 & V_148 ) {
V_127 = true ;
V_20 = & V_96 ;
F_93 ( & V_20 -> V_11 ) ;
V_6 = 0 ;
goto V_24;
}
F_33 (ss, i) {
if ( ! ( V_138 . V_21 & ( 1 << V_42 ) ) ||
V_17 -> V_20 == & V_96 )
continue;
if ( ! F_153 ( & V_17 -> V_20 -> V_11 . V_14 . V_175 ) ) {
F_86 ( & V_19 ) ;
F_154 ( 10 ) ;
V_6 = F_155 () ;
goto V_192;
}
F_96 ( & V_17 -> V_20 -> V_11 ) ;
}
F_156 (root) {
bool V_193 = false ;
if ( V_20 == & V_96 )
continue;
if ( V_138 . V_104 ) {
if ( strcmp ( V_138 . V_104 , V_20 -> V_104 ) )
continue;
V_193 = true ;
}
if ( ( V_138 . V_21 || V_138 . V_147 ) &&
( V_138 . V_21 != V_20 -> V_21 ) ) {
if ( ! V_193 )
continue;
V_6 = - V_125 ;
goto V_24;
}
if ( V_20 -> V_26 ^ V_138 . V_26 )
F_112 ( L_24 ) ;
V_190 = F_157 ( V_20 -> V_89 , NULL ) ;
if ( F_149 ( V_190 ) ||
! F_153 ( & V_20 -> V_11 . V_14 . V_175 ) ) {
F_86 ( & V_19 ) ;
if ( ! F_158 ( V_190 ) )
F_159 ( V_190 ) ;
F_154 ( 10 ) ;
V_6 = F_155 () ;
goto V_192;
}
V_6 = 0 ;
goto V_24;
}
if ( ! V_138 . V_21 && ! V_138 . V_147 ) {
V_6 = - V_146 ;
goto V_24;
}
V_20 = F_57 ( sizeof( * V_20 ) , V_73 ) ;
if ( ! V_20 ) {
V_6 = - V_74 ;
goto V_24;
}
F_142 ( V_20 , & V_138 ) ;
V_6 = F_145 ( V_20 , V_138 . V_21 ) ;
if ( V_6 )
F_79 ( V_20 ) ;
V_24:
F_86 ( & V_19 ) ;
V_192:
F_41 ( V_138 . V_150 ) ;
F_41 ( V_138 . V_104 ) ;
if ( V_6 )
return F_160 ( V_6 ) ;
V_185 = F_161 ( V_187 , V_26 , V_20 -> V_89 ,
V_194 , & V_191 ) ;
if ( F_149 ( V_185 ) || ! V_191 )
F_96 ( & V_20 -> V_11 ) ;
if ( V_190 ) {
F_113 ( V_191 ) ;
F_159 ( V_190 ) ;
}
return V_185 ;
}
static void F_162 ( struct V_189 * V_195 )
{
struct V_88 * V_89 = F_163 ( V_195 ) ;
struct V_69 * V_20 = F_75 ( V_89 ) ;
if ( ! F_39 ( & V_20 -> V_11 . V_14 . V_95 ) ||
V_20 == & V_96 )
F_96 ( & V_20 -> V_11 ) ;
else
F_164 ( & V_20 -> V_11 . V_14 . V_175 ) ;
F_165 ( V_195 ) ;
}
char * F_166 ( struct V_85 * V_99 , char * V_100 , T_3 V_196 )
{
struct V_69 * V_20 ;
struct V_10 * V_11 ;
int V_92 = 1 ;
char * V_197 = NULL ;
F_83 ( & V_19 ) ;
F_65 ( & V_37 ) ;
V_20 = F_167 ( & V_91 , & V_92 ) ;
if ( V_20 ) {
V_11 = F_89 ( V_99 , V_20 ) ;
V_197 = F_168 ( V_11 , V_100 , V_196 ) ;
} else {
if ( F_169 ( V_100 , L_25 , V_196 ) < V_196 )
V_197 = V_100 ;
}
F_66 ( & V_37 ) ;
F_86 ( & V_19 ) ;
return V_197 ;
}
struct V_85 * F_170 ( struct V_198 * V_199 )
{
V_199 -> V_200 = F_61 ( V_199 -> V_201 , struct V_43 , V_81 ) ;
V_199 -> V_202 = NULL ;
return F_171 ( V_199 ) ;
}
struct V_85 * F_171 ( struct V_198 * V_199 )
{
struct V_43 * V_44 = V_199 -> V_200 ;
struct V_85 * V_99 = V_199 -> V_202 ;
while ( & V_44 -> V_81 != V_199 -> V_201 ) {
if ( ! V_99 )
V_99 = F_61 ( & V_44 -> V_79 ,
struct V_85 , V_163 ) ;
else
V_99 = F_172 ( V_99 , V_163 ) ;
if ( & V_99 -> V_163 != & V_44 -> V_79 ) {
V_199 -> V_200 = V_44 ;
V_199 -> V_202 = V_99 ;
return V_99 ;
}
V_44 = F_172 ( V_44 , V_81 ) ;
V_99 = NULL ;
}
return NULL ;
}
static void F_173 ( struct V_10 * V_203 ,
struct V_85 * V_86 ,
struct V_43 * V_204 )
{
struct V_43 * V_57 ;
F_17 ( & V_19 ) ;
F_17 ( & V_37 ) ;
F_80 ( V_86 -> V_26 & V_166 ) ;
V_57 = F_90 ( V_86 ) ;
F_47 ( V_204 ) ;
F_115 ( V_86 -> V_205 , V_204 ) ;
F_117 ( & V_86 -> V_163 , & V_204 -> V_79 ) ;
F_34 ( V_57 ) ;
}
static void F_174 ( struct V_60 * V_206 )
{
struct V_43 * V_44 , * V_207 ;
F_17 ( & V_19 ) ;
F_45 ( & V_37 ) ;
F_38 (cset, tmp_cset, preloaded_csets, mg_preload_node) {
V_44 -> V_208 = NULL ;
V_44 -> V_209 = NULL ;
F_175 ( & V_44 -> V_80 ) ;
F_34 ( V_44 ) ;
}
F_46 ( & V_37 ) ;
}
static void F_176 ( struct V_43 * V_210 ,
struct V_10 * V_211 ,
struct V_60 * V_206 )
{
struct V_10 * V_212 ;
F_17 ( & V_19 ) ;
F_17 ( & V_37 ) ;
V_212 = F_88 ( V_210 , V_211 -> V_20 ) ;
if ( ! F_39 ( & V_210 -> V_80 ) )
return;
F_113 ( V_210 -> V_208 ) ;
F_113 ( ! F_39 ( & V_210 -> V_79 ) ) ;
F_113 ( ! F_39 ( & V_210 -> V_81 ) ) ;
V_210 -> V_208 = V_212 ;
F_47 ( V_210 ) ;
F_58 ( & V_210 -> V_80 , V_206 ) ;
}
static int F_177 ( struct V_10 * V_211 ,
struct V_60 * V_206 )
{
F_146 ( V_201 ) ;
struct V_43 * V_210 , * V_207 ;
F_17 ( & V_19 ) ;
if ( V_211 && F_60 ( V_211 ) && F_11 ( V_211 ) &&
V_211 -> V_22 )
return - V_125 ;
F_38 (src_cset, tmp_cset, preloaded_csets, mg_preload_node) {
struct V_43 * V_213 ;
V_213 = F_64 ( V_210 ,
V_211 ? : V_210 -> V_75 ) ;
if ( ! V_213 )
goto V_214;
F_80 ( V_210 -> V_209 || V_213 -> V_209 ) ;
if ( V_210 == V_213 ) {
V_210 -> V_208 = NULL ;
F_175 ( & V_210 -> V_80 ) ;
F_43 ( V_210 ) ;
F_43 ( V_213 ) ;
continue;
}
V_210 -> V_209 = V_213 ;
if ( F_39 ( & V_213 -> V_80 ) )
F_58 ( & V_213 -> V_80 , & V_201 ) ;
else
F_43 ( V_213 ) ;
}
F_178 ( & V_201 , V_206 ) ;
return 0 ;
V_214:
F_174 ( & V_201 ) ;
return - V_74 ;
}
static int F_179 ( struct V_10 * V_11 , struct V_85 * V_215 ,
bool V_216 )
{
struct V_198 V_199 = {
. V_217 = F_180 ( V_199 . V_217 ) ,
. V_218 = F_180 ( V_199 . V_218 ) ,
. V_201 = & V_199 . V_217 ,
} ;
struct V_12 * V_23 , * V_219 = NULL ;
struct V_43 * V_44 , * V_207 ;
struct V_85 * V_99 , * V_220 ;
int V_42 , V_6 ;
F_45 ( & V_37 ) ;
F_19 () ;
V_99 = V_215 ;
do {
if ( V_99 -> V_26 & V_166 )
goto V_68;
if ( F_39 ( & V_99 -> V_163 ) )
goto V_68;
V_44 = F_90 ( V_99 ) ;
if ( ! V_44 -> V_208 )
goto V_68;
F_117 ( & V_99 -> V_163 , & V_44 -> V_79 ) ;
if ( F_39 ( & V_44 -> V_81 ) )
F_63 ( & V_44 -> V_81 , & V_199 . V_217 ) ;
if ( F_39 ( & V_44 -> V_209 -> V_81 ) )
F_117 ( & V_44 -> V_209 -> V_81 ,
& V_199 . V_218 ) ;
V_68:
if ( ! V_216 )
break;
} while_each_thread(leader, task) ;
int F_181 ( struct V_10 * V_211 ,
struct V_85 * V_215 , bool V_216 )
{
F_146 ( V_206 ) ;
struct V_85 * V_99 ;
int V_6 ;
F_65 ( & V_37 ) ;
F_19 () ;
V_99 = V_215 ;
do {
F_176 ( F_90 ( V_99 ) , V_211 ,
& V_206 ) ;
if ( ! V_216 )
break;
} while_each_thread(leader, task) ;
int F_182 ( struct V_85 * V_99 ,
struct V_10 * V_211 ,
struct V_28 * V_29 )
{
const struct V_221 * V_221 = F_183 () ;
const struct V_221 * V_222 = F_184 ( V_99 ) ;
int V_6 = 0 ;
if ( ! F_185 ( V_221 -> V_223 , V_224 ) &&
! F_185 ( V_221 -> V_223 , V_222 -> V_225 ) &&
! F_185 ( V_221 -> V_223 , V_222 -> V_226 ) )
V_6 = - V_227 ;
if ( ! V_6 && F_60 ( V_211 ) ) {
struct V_189 * V_195 = V_29 -> V_228 -> V_229 . V_185 -> V_230 ;
struct V_10 * V_11 ;
struct V_231 * V_231 ;
F_65 ( & V_37 ) ;
V_11 = F_89 ( V_99 , & V_96 ) ;
F_66 ( & V_37 ) ;
while ( ! F_27 ( V_211 , V_11 ) )
V_11 = F_11 ( V_11 ) ;
V_6 = - V_74 ;
V_231 = F_186 ( V_195 , V_11 -> V_232 ) ;
if ( V_231 ) {
V_6 = F_187 ( V_231 , V_233 ) ;
F_188 ( V_231 ) ;
}
}
F_189 ( V_222 ) ;
return V_6 ;
}
static T_4 F_190 ( struct V_28 * V_29 , char * V_100 ,
T_3 V_234 , T_5 V_235 , bool V_216 )
{
struct V_85 * V_86 ;
struct V_10 * V_11 ;
T_6 V_236 ;
int V_6 ;
if ( F_191 ( F_192 ( V_100 ) , 0 , & V_236 ) || V_236 < 0 )
return - V_146 ;
V_11 = F_104 ( V_29 -> V_30 ) ;
if ( ! V_11 )
return - V_237 ;
V_238:
F_19 () ;
if ( V_236 ) {
V_86 = F_193 ( V_236 ) ;
if ( ! V_86 ) {
F_22 () ;
V_6 = - V_239 ;
goto V_240;
}
} else {
V_86 = V_157 ;
}
if ( V_216 )
V_86 = V_86 -> V_241 ;
if ( V_86 == V_242 || ( V_86 -> V_26 & V_243 ) ) {
V_6 = - V_146 ;
F_22 () ;
goto V_240;
}
F_194 ( V_86 ) ;
F_22 () ;
F_73 ( V_86 ) ;
if ( V_216 ) {
if ( ! F_195 ( V_86 ) ) {
F_74 ( V_86 ) ;
F_196 ( V_86 ) ;
goto V_238;
}
}
V_6 = F_182 ( V_86 , V_11 , V_29 ) ;
if ( ! V_6 )
V_6 = F_181 ( V_11 , V_86 , V_216 ) ;
F_74 ( V_86 ) ;
F_196 ( V_86 ) ;
V_240:
F_101 ( V_29 -> V_30 ) ;
return V_6 ? : V_234 ;
}
int F_197 ( struct V_85 * V_244 , struct V_85 * V_86 )
{
struct V_69 * V_20 ;
int V_245 = 0 ;
F_83 ( & V_19 ) ;
F_156 (root) {
struct V_10 * V_246 ;
if ( V_20 == & V_96 )
continue;
F_65 ( & V_37 ) ;
V_246 = F_89 ( V_244 , V_20 ) ;
F_66 ( & V_37 ) ;
V_245 = F_181 ( V_246 , V_86 , false ) ;
if ( V_245 )
break;
}
F_86 ( & V_19 ) ;
return V_245 ;
}
static T_4 F_198 ( struct V_28 * V_29 ,
char * V_100 , T_3 V_234 , T_5 V_235 )
{
return F_190 ( V_29 , V_100 , V_234 , V_235 , false ) ;
}
static T_4 F_199 ( struct V_28 * V_29 ,
char * V_100 , T_3 V_234 , T_5 V_235 )
{
return F_190 ( V_29 , V_100 , V_234 , V_235 , true ) ;
}
static T_4 F_200 ( struct V_28 * V_29 ,
char * V_100 , T_3 V_234 , T_5 V_235 )
{
struct V_10 * V_11 ;
F_201 ( sizeof( V_11 -> V_20 -> V_134 ) < V_151 ) ;
V_11 = F_104 ( V_29 -> V_30 ) ;
if ( ! V_11 )
return - V_237 ;
F_122 ( & V_133 ) ;
F_169 ( V_11 -> V_20 -> V_134 , F_192 ( V_100 ) ,
sizeof( V_11 -> V_20 -> V_134 ) ) ;
F_123 ( & V_133 ) ;
F_101 ( V_29 -> V_30 ) ;
return V_234 ;
}
static int F_202 ( struct V_130 * V_131 , void * V_247 )
{
struct V_10 * V_11 = F_203 ( V_131 ) -> V_10 ;
F_122 ( & V_133 ) ;
F_121 ( V_131 , V_11 -> V_20 -> V_134 ) ;
F_123 ( & V_133 ) ;
F_204 ( V_131 , '\n' ) ;
return 0 ;
}
static int F_205 ( struct V_130 * V_131 , void * V_247 )
{
F_121 ( V_131 , L_26 ) ;
return 0 ;
}
static void F_206 ( struct V_130 * V_131 , unsigned long V_123 )
{
struct V_16 * V_17 ;
bool V_248 = false ;
int V_48 ;
F_99 (ss, ssid, &ss_mask) {
if ( V_248 )
F_204 ( V_131 , ' ' ) ;
F_207 ( V_131 , L_27 , V_17 -> V_104 ) ;
V_248 = true ;
}
if ( V_248 )
F_204 ( V_131 , '\n' ) ;
}
static int F_208 ( struct V_130 * V_131 , void * V_247 )
{
struct V_10 * V_11 = F_203 ( V_131 ) -> V_10 ;
F_206 ( V_131 , V_11 -> V_20 -> V_21 &
~ V_126 ) ;
return 0 ;
}
static int F_209 ( struct V_130 * V_131 , void * V_247 )
{
struct V_10 * V_11 = F_203 ( V_131 ) -> V_10 ;
F_206 ( V_131 , F_11 ( V_11 ) -> V_115 ) ;
return 0 ;
}
static int F_210 ( struct V_130 * V_131 , void * V_247 )
{
struct V_10 * V_11 = F_203 ( V_131 ) -> V_10 ;
F_206 ( V_131 , V_11 -> V_115 ) ;
return 0 ;
}
static int F_211 ( struct V_10 * V_11 )
{
F_146 ( V_206 ) ;
struct V_12 * V_23 ;
struct V_43 * V_210 ;
int V_6 ;
F_17 ( & V_19 ) ;
F_65 ( & V_37 ) ;
F_212 (css, cgroup_css(cgrp, NULL)) {
struct V_45 * V_46 ;
if ( V_23 -> V_10 == V_11 )
continue;
F_69 (link, &css->cgroup->cset_links, cset_link)
F_176 ( V_46 -> V_44 , V_11 ,
& V_206 ) ;
}
F_66 ( & V_37 ) ;
V_6 = F_177 ( NULL , & V_206 ) ;
if ( V_6 )
goto V_249;
F_69 (src_cset, &preloaded_csets, mg_preload_node) {
struct V_85 * V_250 = NULL , * V_99 ;
if ( ! V_210 -> V_208 )
break;
while ( true ) {
F_65 ( & V_37 ) ;
V_99 = F_213 ( & V_210 -> V_78 ,
struct V_85 , V_163 ) ;
if ( V_99 ) {
V_99 = V_99 -> V_241 ;
F_80 ( ! F_90 ( V_99 ) -> V_208 ) ;
F_194 ( V_99 ) ;
}
F_66 ( & V_37 ) ;
if ( ! V_99 )
break;
if ( F_214 ( V_250 == V_99 ,
L_28 ) )
goto V_249;
V_250 = V_99 ;
F_73 ( V_99 ) ;
if ( ! F_195 ( V_99 ) ) {
F_74 ( V_99 ) ;
F_196 ( V_99 ) ;
continue;
}
V_6 = F_179 ( V_210 -> V_75 , V_99 , true ) ;
F_74 ( V_99 ) ;
F_196 ( V_99 ) ;
if ( F_214 ( V_6 , L_29 , V_6 ) )
goto V_249;
}
}
V_249:
F_174 ( & V_206 ) ;
return V_6 ;
}
static T_4 F_215 ( struct V_28 * V_29 ,
char * V_100 , T_3 V_234 ,
T_5 V_235 )
{
unsigned long V_251 = 0 , V_252 = 0 ;
unsigned long V_253 , V_254 , V_255 , V_256 , V_257 , V_258 ;
struct V_10 * V_11 , * V_259 ;
struct V_16 * V_17 ;
char * V_260 ;
int V_48 , V_6 ;
V_100 = F_192 ( V_100 ) ;
while ( ( V_260 = F_126 ( & V_100 , L_30 ) ) ) {
unsigned long V_124 = ~ V_126 ;
if ( V_260 [ 0 ] == '\0' )
continue;
F_99 (ss, ssid, &tmp_ss_mask) {
if ( V_17 -> V_153 || strcmp ( V_260 + 1 , V_17 -> V_104 ) )
continue;
if ( * V_260 == '+' ) {
V_251 |= 1 << V_48 ;
V_252 &= ~ ( 1 << V_48 ) ;
} else if ( * V_260 == '-' ) {
V_252 |= 1 << V_48 ;
V_251 &= ~ ( 1 << V_48 ) ;
} else {
return - V_146 ;
}
break;
}
if ( V_48 == V_76 )
return - V_146 ;
}
V_11 = F_104 ( V_29 -> V_30 ) ;
if ( ! V_11 )
return - V_237 ;
F_33 (ss, ssid) {
if ( V_251 & ( 1 << V_48 ) ) {
if ( V_11 -> V_115 & ( 1 << V_48 ) ) {
V_251 &= ~ ( 1 << V_48 ) ;
continue;
}
if ( ! ( V_96 . V_21 & ( 1 << V_48 ) ) ||
( F_11 ( V_11 ) &&
! ( F_11 ( V_11 ) -> V_115 & ( 1 << V_48 ) ) ) ) {
V_6 = - V_154 ;
goto V_24;
}
} else if ( V_252 & ( 1 << V_48 ) ) {
if ( ! ( V_11 -> V_115 & ( 1 << V_48 ) ) ) {
V_252 &= ~ ( 1 << V_48 ) ;
continue;
}
F_216 (child, cgrp) {
if ( V_259 -> V_115 & ( 1 << V_48 ) ) {
V_6 = - V_125 ;
goto V_24;
}
}
}
}
if ( ! V_251 && ! V_252 ) {
V_6 = 0 ;
goto V_24;
}
if ( V_251 && F_11 ( V_11 ) && ! F_39 ( & V_11 -> V_55 ) ) {
V_6 = - V_125 ;
goto V_24;
}
V_255 = V_11 -> V_115 ;
V_257 = V_11 -> V_22 ;
V_256 = ( V_255 | V_251 ) & ~ V_252 ;
V_258 = F_98 ( V_11 , V_256 ) ;
V_253 = ~ V_257 & V_258 ;
V_254 = V_257 & ~ V_258 ;
V_251 |= V_253 ;
V_252 |= V_254 ;
F_99 (ss, ssid, &css_enable) {
F_216 (child, cgrp) {
F_217 ( V_261 ) ;
if ( ! F_13 ( V_259 , V_17 ) )
continue;
F_93 ( V_259 ) ;
F_218 ( & V_259 -> V_170 , & V_261 ,
V_262 ) ;
F_101 ( V_29 -> V_30 ) ;
F_219 () ;
F_220 ( & V_259 -> V_170 , & V_261 ) ;
F_96 ( V_259 ) ;
return F_155 () ;
}
}
V_11 -> V_115 = V_256 ;
V_11 -> V_22 = V_258 ;
F_33 (ss, ssid) {
if ( ! ( V_251 & ( 1 << V_48 ) ) )
continue;
F_216 (child, cgrp) {
if ( V_253 & ( 1 << V_48 ) )
V_6 = F_221 ( V_259 , V_17 ,
V_11 -> V_115 & ( 1 << V_48 ) ) ;
else
V_6 = F_111 ( V_259 , 1 << V_48 ) ;
if ( V_6 )
goto V_263;
}
}
V_6 = F_211 ( V_11 ) ;
if ( V_6 )
goto V_263;
F_33 (ss, ssid) {
if ( ! ( V_252 & ( 1 << V_48 ) ) )
continue;
F_216 (child, cgrp) {
struct V_12 * V_23 = F_13 ( V_259 , V_17 ) ;
if ( V_254 & ( 1 << V_48 ) ) {
F_222 ( V_23 ) ;
} else {
F_108 ( V_259 , 1 << V_48 ) ;
if ( V_17 -> V_264 )
V_17 -> V_264 ( V_23 ) ;
}
}
}
F_33 (ss, ssid) {
struct V_12 * V_265 = F_13 ( V_11 , V_17 ) ;
struct V_12 * V_23 ;
if ( ! V_17 -> V_266 || ! V_265 )
continue;
F_212 (css, this_css)
if ( V_23 != V_265 )
V_17 -> V_266 ( V_23 ) ;
}
F_118 ( V_11 -> V_30 ) ;
V_6 = 0 ;
V_24:
F_101 ( V_29 -> V_30 ) ;
return V_6 ? : V_234 ;
V_263:
V_11 -> V_115 = V_255 ;
V_11 -> V_22 = V_257 ;
F_33 (ss, ssid) {
if ( ! ( V_251 & ( 1 << V_48 ) ) )
continue;
F_216 (child, cgrp) {
struct V_12 * V_23 = F_13 ( V_259 , V_17 ) ;
if ( ! V_23 )
continue;
if ( V_253 & ( 1 << V_48 ) )
F_222 ( V_23 ) ;
else
F_108 ( V_259 , 1 << V_48 ) ;
}
}
goto V_24;
}
static int F_223 ( struct V_130 * V_131 , void * V_247 )
{
F_207 ( V_131 , L_31 , ( bool ) F_203 ( V_131 ) -> V_10 -> V_39 ) ;
return 0 ;
}
static T_4 F_224 ( struct V_28 * V_29 , char * V_100 ,
T_3 V_234 , T_5 V_235 )
{
struct V_10 * V_11 = V_29 -> V_30 -> V_15 -> V_31 ;
struct V_32 * V_33 = V_29 -> V_30 -> V_31 ;
struct V_12 * V_23 ;
int V_6 ;
if ( V_33 -> V_113 )
return V_33 -> V_113 ( V_29 , V_100 , V_234 , V_235 ) ;
F_19 () ;
V_23 = F_13 ( V_11 , V_33 -> V_17 ) ;
F_22 () ;
if ( V_33 -> V_111 ) {
unsigned long long V_247 ;
V_6 = F_225 ( V_100 , 0 , & V_247 ) ;
if ( ! V_6 )
V_6 = V_33 -> V_111 ( V_23 , V_33 , V_247 ) ;
} else if ( V_33 -> V_112 ) {
long long V_247 ;
V_6 = F_226 ( V_100 , 0 , & V_247 ) ;
if ( ! V_6 )
V_6 = V_33 -> V_112 ( V_23 , V_33 , V_247 ) ;
} else {
V_6 = - V_146 ;
}
return V_6 ? : V_234 ;
}
static void * F_227 ( struct V_130 * V_131 , T_5 * V_267 )
{
return F_228 ( V_131 ) -> F_229 ( V_131 , V_267 ) ;
}
static void * F_230 ( struct V_130 * V_131 , void * V_247 , T_5 * V_267 )
{
return F_228 ( V_131 ) -> F_231 ( V_131 , V_247 , V_267 ) ;
}
static void F_232 ( struct V_130 * V_131 , void * V_247 )
{
F_228 ( V_131 ) -> F_233 ( V_131 , V_247 ) ;
}
static int F_234 ( struct V_130 * V_268 , void * V_269 )
{
struct V_32 * V_33 = F_228 ( V_268 ) ;
struct V_12 * V_23 = F_203 ( V_268 ) ;
if ( V_33 -> V_109 )
return V_33 -> V_109 ( V_268 , V_269 ) ;
if ( V_33 -> V_107 )
F_207 ( V_268 , L_32 , V_33 -> V_107 ( V_23 , V_33 ) ) ;
else if ( V_33 -> V_108 )
F_207 ( V_268 , L_33 , V_33 -> V_108 ( V_23 , V_33 ) ) ;
else
return - V_146 ;
return 0 ;
}
static int F_235 ( struct V_119 * V_30 , struct V_119 * V_270 ,
const char * V_271 )
{
struct V_10 * V_11 = V_30 -> V_31 ;
int V_6 ;
if ( F_102 ( V_30 ) != V_120 )
return - V_272 ;
if ( V_30 -> V_15 != V_270 )
return - V_273 ;
if ( F_60 ( V_11 ) )
return - V_274 ;
F_105 ( V_270 ) ;
F_105 ( V_30 ) ;
F_83 ( & V_19 ) ;
V_6 = F_236 ( V_30 , V_270 , V_271 ) ;
F_86 ( & V_19 ) ;
F_103 ( V_30 ) ;
F_103 ( V_270 ) ;
return V_6 ;
}
static int F_237 ( struct V_119 * V_30 )
{
struct V_275 V_275 = { . V_276 = V_277 | V_278 ,
. V_279 = F_238 () ,
. V_280 = F_239 () , } ;
if ( F_185 ( V_275 . V_279 , V_224 ) &&
F_240 ( V_275 . V_280 , V_281 ) )
return 0 ;
return F_241 ( V_30 , & V_275 ) ;
}
static int F_242 ( struct V_10 * V_11 , struct V_32 * V_33 )
{
char V_104 [ V_103 ] ;
struct V_119 * V_30 ;
struct V_282 * V_41 = NULL ;
int V_6 ;
#ifdef F_243
V_41 = & V_33 -> V_283 ;
#endif
V_30 = F_244 ( V_11 -> V_30 , F_91 ( V_11 , V_33 , V_104 ) ,
F_92 ( V_33 ) , 0 , V_33 -> V_284 , V_33 ,
NULL , V_41 ) ;
if ( F_149 ( V_30 ) )
return F_150 ( V_30 ) ;
V_6 = F_237 ( V_30 ) ;
if ( V_6 ) {
F_245 ( V_30 ) ;
return V_6 ;
}
if ( V_33 -> V_113 == F_199 )
V_11 -> V_232 = V_30 ;
else if ( V_33 -> V_109 == F_223 )
V_11 -> V_40 = V_30 ;
return 0 ;
}
static int F_109 ( struct V_10 * V_11 , struct V_32 V_121 [] ,
bool V_285 )
{
struct V_32 * V_33 ;
int V_6 ;
F_17 ( & V_19 ) ;
for ( V_33 = V_121 ; V_33 -> V_104 [ 0 ] != '\0' ; V_33 ++ ) {
if ( ( V_33 -> V_26 & V_286 ) && ! F_60 ( V_11 ) )
continue;
if ( ( V_33 -> V_26 & V_287 ) && F_60 ( V_11 ) )
continue;
if ( ( V_33 -> V_26 & V_288 ) && ! F_11 ( V_11 ) )
continue;
if ( ( V_33 -> V_26 & V_289 ) && F_11 ( V_11 ) )
continue;
if ( V_285 ) {
V_6 = F_242 ( V_11 , V_33 ) ;
if ( V_6 ) {
F_112 ( L_34 ,
V_290 , V_33 -> V_104 , V_6 ) ;
return V_6 ;
}
} else {
F_106 ( V_11 , V_33 ) ;
}
}
return 0 ;
}
static int F_246 ( struct V_32 * V_121 , bool V_285 )
{
F_146 ( V_291 ) ;
struct V_16 * V_17 = V_121 [ 0 ] . V_17 ;
struct V_10 * V_20 = & V_17 -> V_20 -> V_11 ;
struct V_12 * V_23 ;
int V_6 = 0 ;
F_17 ( & V_19 ) ;
F_212 (css, cgroup_css(root, ss)) {
struct V_10 * V_11 = V_23 -> V_10 ;
if ( F_23 ( V_11 ) )
continue;
V_6 = F_109 ( V_11 , V_121 , V_285 ) ;
if ( V_6 )
break;
}
if ( V_285 && ! V_6 )
F_118 ( V_20 -> V_30 ) ;
return V_6 ;
}
static void F_247 ( struct V_32 * V_121 )
{
struct V_32 * V_33 ;
for ( V_33 = V_121 ; V_33 -> V_104 [ 0 ] != '\0' ; V_33 ++ ) {
if ( V_33 -> V_292 && V_33 -> V_292 != V_293 )
F_41 ( V_33 -> V_284 ) ;
V_33 -> V_284 = NULL ;
V_33 -> V_17 = NULL ;
V_33 -> V_26 &= ~ ( V_286 | V_287 ) ;
}
}
static int F_248 ( struct V_16 * V_17 , struct V_32 * V_121 )
{
struct V_32 * V_33 ;
for ( V_33 = V_121 ; V_33 -> V_104 [ 0 ] != '\0' ; V_33 ++ ) {
struct V_294 * V_284 ;
F_113 ( V_33 -> V_17 || V_33 -> V_284 ) ;
if ( V_33 -> F_229 )
V_284 = & V_295 ;
else
V_284 = & V_296 ;
if ( V_33 -> V_292 && V_33 -> V_292 != V_293 ) {
V_284 = F_249 ( V_284 , sizeof( * V_284 ) , V_73 ) ;
if ( ! V_284 ) {
F_247 ( V_121 ) ;
return - V_74 ;
}
V_284 -> V_297 = V_33 -> V_292 ;
}
V_33 -> V_284 = V_284 ;
V_33 -> V_17 = V_17 ;
}
return 0 ;
}
static int F_250 ( struct V_32 * V_121 )
{
F_17 ( & V_19 ) ;
if ( ! V_121 || ! V_121 [ 0 ] . V_17 )
return - V_154 ;
F_36 ( & V_121 -> V_298 ) ;
F_246 ( V_121 , false ) ;
F_247 ( V_121 ) ;
return 0 ;
}
int F_251 ( struct V_32 * V_121 )
{
int V_6 ;
F_83 ( & V_19 ) ;
V_6 = F_250 ( V_121 ) ;
F_86 ( & V_19 ) ;
return V_6 ;
}
static int F_252 ( struct V_16 * V_17 , struct V_32 * V_121 )
{
int V_6 ;
if ( V_17 -> V_153 )
return 0 ;
if ( ! V_121 || V_121 [ 0 ] . V_104 [ 0 ] == '\0' )
return 0 ;
V_6 = F_248 ( V_17 , V_121 ) ;
if ( V_6 )
return V_6 ;
F_83 ( & V_19 ) ;
F_63 ( & V_121 -> V_298 , & V_17 -> V_121 ) ;
V_6 = F_246 ( V_121 , true ) ;
if ( V_6 )
F_250 ( V_121 ) ;
F_86 ( & V_19 ) ;
return V_6 ;
}
int F_253 ( struct V_16 * V_17 , struct V_32 * V_121 )
{
struct V_32 * V_33 ;
for ( V_33 = V_121 ; V_33 && V_33 -> V_104 [ 0 ] != '\0' ; V_33 ++ )
V_33 -> V_26 |= V_286 ;
return F_252 ( V_17 , V_121 ) ;
}
int F_254 ( struct V_16 * V_17 , struct V_32 * V_121 )
{
struct V_32 * V_33 ;
if ( ! V_299 ||
V_17 -> V_300 != V_17 -> V_301 ) {
for ( V_33 = V_121 ; V_33 && V_33 -> V_104 [ 0 ] != '\0' ; V_33 ++ )
V_33 -> V_26 |= V_287 ;
}
return F_252 ( V_17 , V_121 ) ;
}
static int F_255 ( const struct V_10 * V_11 )
{
int V_71 = 0 ;
struct V_45 * V_46 ;
F_65 ( & V_37 ) ;
F_69 (link, &cgrp->cset_links, cset_link)
V_71 += F_84 ( & V_46 -> V_44 -> V_49 ) ;
F_66 ( & V_37 ) ;
return V_71 ;
}
struct V_12 * F_110 ( struct V_12 * V_302 ,
struct V_12 * V_15 )
{
struct V_12 * V_68 ;
F_256 () ;
if ( ! V_302 ) {
V_68 = F_257 ( V_15 -> V_95 . V_68 , struct V_12 , V_167 ) ;
} else if ( F_258 ( ! ( V_302 -> V_26 & V_303 ) ) ) {
V_68 = F_257 ( V_302 -> V_167 . V_68 , struct V_12 , V_167 ) ;
} else {
F_259 (next, &parent->children, sibling)
if ( V_68 -> V_304 > V_302 -> V_304 )
break;
}
if ( & V_68 -> V_167 != & V_15 -> V_95 )
return V_68 ;
return NULL ;
}
struct V_12 *
F_260 ( struct V_12 * V_302 ,
struct V_12 * V_20 )
{
struct V_12 * V_68 ;
F_256 () ;
if ( ! V_302 )
return V_20 ;
V_68 = F_110 ( NULL , V_302 ) ;
if ( V_68 )
return V_68 ;
while ( V_302 != V_20 ) {
V_68 = F_110 ( V_302 , V_302 -> V_15 ) ;
if ( V_68 )
return V_68 ;
V_302 = V_302 -> V_15 ;
}
return NULL ;
}
struct V_12 *
F_261 ( struct V_12 * V_302 )
{
struct V_12 * V_305 , * V_306 ;
F_256 () ;
do {
V_305 = V_302 ;
V_302 = NULL ;
F_262 (tmp, last)
V_302 = V_306 ;
} while ( V_302 );
return V_305 ;
}
static struct V_12 *
F_263 ( struct V_12 * V_302 )
{
struct V_12 * V_305 ;
do {
V_305 = V_302 ;
V_302 = F_110 ( NULL , V_302 ) ;
} while ( V_302 );
return V_305 ;
}
struct V_12 *
F_264 ( struct V_12 * V_302 ,
struct V_12 * V_20 )
{
struct V_12 * V_68 ;
F_256 () ;
if ( ! V_302 )
return F_263 ( V_20 ) ;
if ( V_302 == V_20 )
return NULL ;
V_68 = F_110 ( V_302 , V_302 -> V_15 ) ;
if ( V_68 )
return F_263 ( V_68 ) ;
return V_302 -> V_15 ;
}
bool F_265 ( struct V_12 * V_23 )
{
struct V_12 * V_259 ;
bool V_6 = false ;
F_19 () ;
F_262 (child, css) {
if ( V_259 -> V_26 & V_27 ) {
V_6 = true ;
break;
}
}
F_22 () ;
return V_6 ;
}
static void F_266 ( struct V_307 * V_308 )
{
struct V_60 * V_309 = V_308 -> V_310 ;
struct V_45 * V_46 ;
struct V_43 * V_44 ;
do {
V_309 = V_309 -> V_68 ;
if ( V_309 == V_308 -> V_311 ) {
V_308 -> V_310 = NULL ;
return;
}
if ( V_308 -> V_17 ) {
V_44 = F_12 ( V_309 , struct V_43 ,
V_50 [ V_308 -> V_17 -> V_9 ] ) ;
} else {
V_46 = F_51 ( V_309 , struct V_45 , V_53 ) ;
V_44 = V_46 -> V_44 ;
}
} while ( F_39 ( & V_44 -> V_78 ) && F_39 ( & V_44 -> V_79 ) );
V_308 -> V_310 = V_309 ;
if ( ! F_39 ( & V_44 -> V_78 ) )
V_308 -> V_312 = V_44 -> V_78 . V_68 ;
else
V_308 -> V_312 = V_44 -> V_79 . V_68 ;
V_308 -> V_313 = & V_44 -> V_78 ;
V_308 -> V_314 = & V_44 -> V_79 ;
}
void F_267 ( struct V_12 * V_23 ,
struct V_307 * V_308 )
__acquires( V_37 )
{
F_80 ( ! V_161 ) ;
F_65 ( & V_37 ) ;
V_308 -> V_17 = V_23 -> V_17 ;
if ( V_308 -> V_17 )
V_308 -> V_310 = & V_23 -> V_10 -> V_84 [ V_23 -> V_17 -> V_9 ] ;
else
V_308 -> V_310 = & V_23 -> V_10 -> V_55 ;
V_308 -> V_311 = V_308 -> V_310 ;
F_266 ( V_308 ) ;
}
struct V_85 * F_268 ( struct V_307 * V_308 )
{
struct V_85 * V_98 ;
struct V_60 * V_309 = V_308 -> V_312 ;
if ( ! V_308 -> V_310 )
return NULL ;
V_98 = F_51 ( V_309 , struct V_85 , V_163 ) ;
V_309 = V_309 -> V_68 ;
if ( V_309 == V_308 -> V_313 )
V_309 = V_308 -> V_314 -> V_68 ;
if ( V_309 == V_308 -> V_314 )
F_266 ( V_308 ) ;
else
V_308 -> V_312 = V_309 ;
return V_98 ;
}
void F_269 ( struct V_307 * V_308 )
__releases( V_37 )
{
F_66 ( & V_37 ) ;
}
int F_270 ( struct V_10 * V_315 , struct V_10 * V_244 )
{
F_146 ( V_206 ) ;
struct V_45 * V_46 ;
struct V_307 V_308 ;
struct V_85 * V_99 ;
int V_6 ;
F_83 ( & V_19 ) ;
F_65 ( & V_37 ) ;
F_69 (link, &from->cset_links, cset_link)
F_176 ( V_46 -> V_44 , V_315 , & V_206 ) ;
F_66 ( & V_37 ) ;
V_6 = F_177 ( V_315 , & V_206 ) ;
if ( V_6 )
goto V_316;
do {
F_267 ( & V_244 -> V_14 , & V_308 ) ;
V_99 = F_268 ( & V_308 ) ;
if ( V_99 )
F_194 ( V_99 ) ;
F_269 ( & V_308 ) ;
if ( V_99 ) {
V_6 = F_179 ( V_315 , V_99 , false ) ;
F_196 ( V_99 ) ;
}
} while ( V_99 && ! V_6 );
V_316:
F_174 ( & V_206 ) ;
F_86 ( & V_19 ) ;
return V_6 ;
}
static void * F_271 ( int V_71 )
{
if ( F_272 ( V_71 ) )
return F_273 ( V_71 * sizeof( T_6 ) ) ;
else
return F_274 ( V_71 * sizeof( T_6 ) , V_73 ) ;
}
static void F_275 ( void * V_159 )
{
F_276 ( V_159 ) ;
}
static void F_277 ( struct V_10 * V_11 )
{
struct V_317 * V_309 , * V_318 ;
F_83 ( & V_11 -> V_169 ) ;
F_38 (l, tmp_l, &cgrp->pidlists, links)
F_278 ( V_319 , & V_309 -> V_320 , 0 ) ;
F_86 ( & V_11 -> V_169 ) ;
F_279 ( V_319 ) ;
F_50 ( ! F_39 ( & V_11 -> V_168 ) ) ;
}
static void F_280 ( struct V_321 * V_322 )
{
struct V_323 * V_324 = F_281 ( V_322 ) ;
struct V_317 * V_309 = F_12 ( V_324 , struct V_317 ,
V_320 ) ;
struct V_317 * V_325 = NULL ;
F_83 ( & V_309 -> V_326 -> V_169 ) ;
if ( ! F_282 ( V_324 ) ) {
F_36 ( & V_309 -> V_327 ) ;
F_275 ( V_309 -> V_328 ) ;
F_283 ( V_309 -> V_41 . V_329 ) ;
V_325 = V_309 ;
}
F_86 ( & V_309 -> V_326 -> V_169 ) ;
F_41 ( V_325 ) ;
}
static int F_284 ( T_6 * V_328 , int V_330 )
{
int V_331 , V_332 = 1 ;
if ( V_330 == 0 || V_330 == 1 )
return V_330 ;
for ( V_331 = 1 ; V_331 < V_330 ; V_331 ++ ) {
while ( V_328 [ V_331 ] == V_328 [ V_331 - 1 ] ) {
V_331 ++ ;
if ( V_331 == V_330 )
goto V_333;
}
V_328 [ V_332 ] = V_328 [ V_331 ] ;
V_332 ++ ;
}
V_333:
return V_332 ;
}
static T_6 F_285 ( T_6 V_236 )
{
unsigned V_334 = V_236 & 0x55555555 ;
unsigned V_335 = V_236 & 0xAAAAAAAA ;
return ( V_334 << 1 ) | ( V_335 >> 1 ) ;
}
static T_6 F_286 ( struct V_10 * V_11 , T_6 V_236 )
{
if ( F_60 ( V_11 ) )
return F_285 ( V_236 ) ;
else
return V_236 ;
}
static int F_287 ( const void * V_334 , const void * V_335 )
{
return * ( T_6 * ) V_334 - * ( T_6 * ) V_335 ;
}
static int F_288 ( const void * V_334 , const void * V_335 )
{
return F_285 ( * ( T_6 * ) V_334 ) - F_285 ( * ( T_6 * ) V_335 ) ;
}
static struct V_317 * F_289 ( struct V_10 * V_11 ,
enum V_336 type )
{
struct V_317 * V_309 ;
struct V_337 * V_329 = F_290 ( V_157 ) ;
F_17 ( & V_11 -> V_169 ) ;
F_69 (l, &cgrp->pidlists, links)
if ( V_309 -> V_41 . type == type && V_309 -> V_41 . V_329 == V_329 )
return V_309 ;
return NULL ;
}
static struct V_317 * F_291 ( struct V_10 * V_11 ,
enum V_336 type )
{
struct V_317 * V_309 ;
F_17 ( & V_11 -> V_169 ) ;
V_309 = F_289 ( V_11 , type ) ;
if ( V_309 )
return V_309 ;
V_309 = F_57 ( sizeof( struct V_317 ) , V_73 ) ;
if ( ! V_309 )
return V_309 ;
F_292 ( & V_309 -> V_320 , F_280 ) ;
V_309 -> V_41 . type = type ;
V_309 -> V_41 . V_329 = F_293 ( F_290 ( V_157 ) ) ;
V_309 -> V_326 = V_11 ;
F_58 ( & V_309 -> V_327 , & V_11 -> V_168 ) ;
return V_309 ;
}
static int F_294 ( struct V_10 * V_11 , enum V_336 type ,
struct V_317 * * V_338 )
{
T_6 * V_339 ;
int V_330 ;
int V_236 , V_340 = 0 ;
struct V_307 V_308 ;
struct V_85 * V_86 ;
struct V_317 * V_309 ;
F_17 ( & V_11 -> V_169 ) ;
V_330 = F_255 ( V_11 ) ;
V_339 = F_271 ( V_330 ) ;
if ( ! V_339 )
return - V_74 ;
F_267 ( & V_11 -> V_14 , & V_308 ) ;
while ( ( V_86 = F_268 ( & V_308 ) ) ) {
if ( F_295 ( V_340 == V_330 ) )
break;
if ( type == V_341 )
V_236 = F_296 ( V_86 ) ;
else
V_236 = F_297 ( V_86 ) ;
if ( V_236 > 0 )
V_339 [ V_340 ++ ] = V_236 ;
}
F_269 ( & V_308 ) ;
V_330 = V_340 ;
if ( F_60 ( V_11 ) )
F_298 ( V_339 , V_330 , sizeof( T_6 ) , F_288 , NULL ) ;
else
F_298 ( V_339 , V_330 , sizeof( T_6 ) , F_287 , NULL ) ;
if ( type == V_341 )
V_330 = F_284 ( V_339 , V_330 ) ;
V_309 = F_291 ( V_11 , type ) ;
if ( ! V_309 ) {
F_275 ( V_339 ) ;
return - V_74 ;
}
F_275 ( V_309 -> V_328 ) ;
V_309 -> V_328 = V_339 ;
V_309 -> V_330 = V_330 ;
* V_338 = V_309 ;
return 0 ;
}
int F_299 ( struct V_342 * V_343 , struct V_185 * V_185 )
{
struct V_119 * V_30 = F_300 ( V_185 ) ;
struct V_10 * V_11 ;
struct V_307 V_308 ;
struct V_85 * V_86 ;
if ( V_185 -> V_230 -> V_344 != & V_345 || ! V_30 ||
F_102 ( V_30 ) != V_120 )
return - V_146 ;
F_83 ( & V_19 ) ;
F_19 () ;
V_11 = F_301 ( V_30 -> V_31 ) ;
if ( ! V_11 || F_23 ( V_11 ) ) {
F_22 () ;
F_86 ( & V_19 ) ;
return - V_154 ;
}
F_22 () ;
F_267 ( & V_11 -> V_14 , & V_308 ) ;
while ( ( V_86 = F_268 ( & V_308 ) ) ) {
switch ( V_86 -> V_346 ) {
case V_347 :
V_343 -> V_348 ++ ;
break;
case V_349 :
V_343 -> V_350 ++ ;
break;
case V_262 :
V_343 -> V_351 ++ ;
break;
case V_352 :
V_343 -> V_353 ++ ;
break;
default:
if ( F_302 ( V_86 ) )
V_343 -> V_354 ++ ;
break;
}
}
F_269 ( & V_308 ) ;
F_86 ( & V_19 ) ;
return 0 ;
}
static void * F_303 ( struct V_130 * V_355 , T_5 * V_302 )
{
struct V_28 * V_29 = V_355 -> V_356 ;
struct V_10 * V_11 = F_203 ( V_355 ) -> V_10 ;
struct V_317 * V_309 ;
enum V_336 type = F_228 ( V_355 ) -> V_356 ;
int V_357 = 0 , V_236 = * V_302 ;
int * V_358 , V_6 ;
F_83 ( & V_11 -> V_169 ) ;
if ( V_29 -> V_31 )
V_29 -> V_31 = F_289 ( V_11 , type ) ;
if ( ! V_29 -> V_31 ) {
V_6 = F_294 ( V_11 , type ,
(struct V_317 * * ) & V_29 -> V_31 ) ;
if ( V_6 )
return F_160 ( V_6 ) ;
}
V_309 = V_29 -> V_31 ;
if ( V_236 ) {
int V_4 = V_309 -> V_330 ;
while ( V_357 < V_4 ) {
int V_359 = ( V_357 + V_4 ) / 2 ;
if ( F_286 ( V_11 , V_309 -> V_328 [ V_359 ] ) == V_236 ) {
V_357 = V_359 ;
break;
} else if ( F_286 ( V_11 , V_309 -> V_328 [ V_359 ] ) <= V_236 )
V_357 = V_359 + 1 ;
else
V_4 = V_359 ;
}
}
if ( V_357 >= V_309 -> V_330 )
return NULL ;
V_358 = V_309 -> V_328 + V_357 ;
* V_302 = F_286 ( V_11 , * V_358 ) ;
return V_358 ;
}
static void F_304 ( struct V_130 * V_355 , void * V_247 )
{
struct V_28 * V_29 = V_355 -> V_356 ;
struct V_317 * V_309 = V_29 -> V_31 ;
if ( V_309 )
F_278 ( V_319 , & V_309 -> V_320 ,
V_360 ) ;
F_86 ( & F_203 ( V_355 ) -> V_10 -> V_169 ) ;
}
static void * F_305 ( struct V_130 * V_355 , void * V_247 , T_5 * V_302 )
{
struct V_28 * V_29 = V_355 -> V_356 ;
struct V_317 * V_309 = V_29 -> V_31 ;
T_6 * V_159 = V_247 ;
T_6 * V_4 = V_309 -> V_328 + V_309 -> V_330 ;
V_159 ++ ;
if ( V_159 >= V_4 ) {
return NULL ;
} else {
* V_302 = F_286 ( F_203 ( V_355 ) -> V_10 , * V_159 ) ;
return V_159 ;
}
}
static int F_306 ( struct V_130 * V_355 , void * V_247 )
{
F_207 ( V_355 , L_31 , * ( int * ) V_247 ) ;
return 0 ;
}
static T_7 F_307 ( struct V_12 * V_23 ,
struct V_32 * V_33 )
{
return F_28 ( V_23 -> V_10 ) ;
}
static int F_308 ( struct V_12 * V_23 ,
struct V_32 * V_33 , T_7 V_361 )
{
if ( V_361 )
F_144 ( V_35 , & V_23 -> V_10 -> V_26 ) ;
else
F_309 ( V_35 , & V_23 -> V_10 -> V_26 ) ;
return 0 ;
}
static T_7 F_310 ( struct V_12 * V_23 ,
struct V_32 * V_33 )
{
return F_29 ( V_135 , & V_23 -> V_10 -> V_26 ) ;
}
static int F_311 ( struct V_12 * V_23 ,
struct V_32 * V_33 , T_7 V_361 )
{
if ( V_361 )
F_144 ( V_135 , & V_23 -> V_10 -> V_26 ) ;
else
F_309 ( V_135 , & V_23 -> V_10 -> V_26 ) ;
return 0 ;
}
static int F_111 ( struct V_10 * V_11 , unsigned long V_21 )
{
struct V_16 * V_17 ;
int V_42 , V_6 = 0 ;
F_33 (ss, i) {
struct V_32 * V_121 ;
if ( ! ( V_21 & ( 1 << V_42 ) ) )
continue;
F_69 (cfts, &ss->cfts, node) {
V_6 = F_109 ( V_11 , V_121 , true ) ;
if ( V_6 < 0 )
goto V_214;
}
}
return 0 ;
V_214:
F_108 ( V_11 , V_21 ) ;
return V_6 ;
}
static void F_312 ( struct V_321 * V_322 )
{
struct V_12 * V_23 =
F_12 ( V_322 , struct V_12 , V_362 ) ;
struct V_16 * V_17 = V_23 -> V_17 ;
struct V_10 * V_11 = V_23 -> V_10 ;
F_151 ( & V_23 -> V_175 ) ;
if ( V_17 ) {
int V_9 = V_23 -> V_9 ;
if ( V_23 -> V_15 )
F_97 ( V_23 -> V_15 ) ;
V_17 -> V_363 ( V_23 ) ;
F_9 ( & V_17 -> V_364 , V_9 ) ;
F_96 ( V_11 ) ;
} else {
F_313 ( & V_11 -> V_20 -> V_94 ) ;
F_277 ( V_11 ) ;
F_314 ( & V_11 -> V_171 ) ;
if ( F_11 ( V_11 ) ) {
F_96 ( F_11 ( V_11 ) ) ;
F_315 ( V_11 -> V_30 ) ;
F_41 ( V_11 ) ;
} else {
F_82 ( V_11 -> V_20 ) ;
}
}
}
static void F_316 ( struct V_56 * V_56 )
{
struct V_12 * V_23 =
F_12 ( V_56 , struct V_12 , V_56 ) ;
F_141 ( & V_23 -> V_362 , F_312 ) ;
F_317 ( V_365 , & V_23 -> V_362 ) ;
}
static void F_318 ( struct V_321 * V_322 )
{
struct V_12 * V_23 =
F_12 ( V_322 , struct V_12 , V_362 ) ;
struct V_16 * V_17 = V_23 -> V_17 ;
struct V_10 * V_11 = V_23 -> V_10 ;
F_83 ( & V_19 ) ;
V_23 -> V_26 |= V_303 ;
F_319 ( & V_23 -> V_167 ) ;
if ( V_17 ) {
F_7 ( & V_17 -> V_364 , NULL , V_23 -> V_9 ) ;
if ( V_17 -> V_366 )
V_17 -> V_366 ( V_23 ) ;
} else {
F_9 ( & V_11 -> V_20 -> V_93 , V_11 -> V_9 ) ;
V_11 -> V_9 = - 1 ;
F_114 ( * ( void V_367 V_368 * * ) & V_11 -> V_30 -> V_31 , NULL ) ;
}
F_86 ( & V_19 ) ;
F_320 ( & V_23 -> V_56 , F_316 ) ;
}
static void V_176 ( struct V_369 * V_370 )
{
struct V_12 * V_23 =
F_12 ( V_370 , struct V_12 , V_175 ) ;
F_141 ( & V_23 -> V_362 , F_318 ) ;
F_317 ( V_365 , & V_23 -> V_362 ) ;
}
static void F_321 ( struct V_12 * V_23 ,
struct V_16 * V_17 , struct V_10 * V_11 )
{
F_17 ( & V_19 ) ;
F_93 ( V_11 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_10 = V_11 ;
V_23 -> V_17 = V_17 ;
F_56 ( & V_23 -> V_167 ) ;
F_56 ( & V_23 -> V_95 ) ;
V_23 -> V_304 = V_371 ++ ;
if ( F_11 ( V_11 ) ) {
V_23 -> V_15 = F_13 ( F_11 ( V_11 ) , V_17 ) ;
F_21 ( V_23 -> V_15 ) ;
}
F_50 ( F_13 ( V_11 , V_17 ) ) ;
}
static int F_322 ( struct V_12 * V_23 )
{
struct V_16 * V_17 = V_23 -> V_17 ;
int V_6 = 0 ;
F_17 ( & V_19 ) ;
if ( V_17 -> V_372 )
V_6 = V_17 -> V_372 ( V_23 ) ;
if ( ! V_6 ) {
V_23 -> V_26 |= V_27 ;
F_115 ( V_23 -> V_10 -> V_18 [ V_17 -> V_9 ] , V_23 ) ;
}
return V_6 ;
}
static void F_323 ( struct V_12 * V_23 )
{
struct V_16 * V_17 = V_23 -> V_17 ;
F_17 ( & V_19 ) ;
if ( ! ( V_23 -> V_26 & V_27 ) )
return;
if ( V_17 -> V_373 )
V_17 -> V_373 ( V_23 ) ;
V_23 -> V_26 &= ~ V_27 ;
F_114 ( V_23 -> V_10 -> V_18 [ V_17 -> V_9 ] , NULL ) ;
F_324 ( & V_23 -> V_10 -> V_170 ) ;
}
static int F_221 ( struct V_10 * V_11 , struct V_16 * V_17 ,
bool V_374 )
{
struct V_10 * V_15 = F_11 ( V_11 ) ;
struct V_12 * V_13 = F_13 ( V_15 , V_17 ) ;
struct V_12 * V_23 ;
int V_214 ;
F_17 ( & V_19 ) ;
V_23 = V_17 -> V_375 ( V_13 ) ;
if ( F_149 ( V_23 ) )
return F_150 ( V_23 ) ;
F_321 ( V_23 , V_17 , V_11 ) ;
V_214 = F_147 ( & V_23 -> V_175 , V_176 , 0 , V_73 ) ;
if ( V_214 )
goto V_376;
V_214 = F_1 ( & V_17 -> V_364 , NULL , 2 , 0 , V_73 ) ;
if ( V_214 < 0 )
goto V_377;
V_23 -> V_9 = V_214 ;
if ( V_374 ) {
V_214 = F_111 ( V_11 , 1 << V_17 -> V_9 ) ;
if ( V_214 )
goto V_378;
}
F_325 ( & V_23 -> V_167 , & V_13 -> V_95 ) ;
F_7 ( & V_17 -> V_364 , V_23 , V_23 -> V_9 ) ;
V_214 = F_322 ( V_23 ) ;
if ( V_214 )
goto V_379;
if ( V_17 -> V_380 && ! V_17 -> V_381 &&
F_11 ( V_15 ) ) {
F_112 ( L_35 ,
V_157 -> V_158 , V_157 -> V_236 , V_17 -> V_104 ) ;
if ( ! strcmp ( V_17 -> V_104 , L_36 ) )
F_112 ( L_37 ) ;
V_17 -> V_381 = true ;
}
return 0 ;
V_379:
F_319 ( & V_23 -> V_167 ) ;
F_108 ( V_23 -> V_10 , 1 << V_23 -> V_17 -> V_9 ) ;
V_378:
F_9 ( & V_17 -> V_364 , V_23 -> V_9 ) ;
V_377:
F_151 ( & V_23 -> V_175 ) ;
V_376:
F_320 ( & V_23 -> V_56 , F_316 ) ;
return V_214 ;
}
static int F_326 ( struct V_119 * V_382 , const char * V_104 ,
T_2 V_106 )
{
struct V_10 * V_15 , * V_11 ;
struct V_69 * V_20 ;
struct V_16 * V_17 ;
struct V_119 * V_30 ;
struct V_32 * V_173 ;
int V_48 , V_6 ;
if ( strchr ( V_104 , '\n' ) )
return - V_146 ;
V_15 = F_104 ( V_382 ) ;
if ( ! V_15 )
return - V_237 ;
V_20 = V_15 -> V_20 ;
V_11 = F_57 ( sizeof( * V_11 ) , V_73 ) ;
if ( ! V_11 ) {
V_6 = - V_74 ;
goto V_24;
}
V_6 = F_147 ( & V_11 -> V_14 . V_175 , V_176 , 0 , V_73 ) ;
if ( V_6 )
goto V_383;
V_11 -> V_9 = F_1 ( & V_20 -> V_93 , NULL , 2 , 0 , V_73 ) ;
if ( V_11 -> V_9 < 0 ) {
V_6 = - V_74 ;
goto V_384;
}
F_138 ( V_11 ) ;
V_11 -> V_14 . V_15 = & V_15 -> V_14 ;
V_11 -> V_20 = V_20 ;
if ( F_28 ( V_15 ) )
F_144 ( V_35 , & V_11 -> V_26 ) ;
if ( F_29 ( V_135 , & V_15 -> V_26 ) )
F_144 ( V_135 , & V_11 -> V_26 ) ;
V_30 = F_327 ( V_15 -> V_30 , V_104 , V_106 , V_11 ) ;
if ( F_149 ( V_30 ) ) {
V_6 = F_150 ( V_30 ) ;
goto V_385;
}
V_11 -> V_30 = V_30 ;
F_328 ( V_30 ) ;
V_11 -> V_14 . V_304 = V_371 ++ ;
F_325 ( & V_11 -> V_14 . V_167 , & F_11 ( V_11 ) -> V_14 . V_95 ) ;
F_48 ( & V_20 -> V_94 ) ;
F_93 ( V_15 ) ;
F_7 ( & V_20 -> V_93 , V_11 , V_11 -> V_9 ) ;
V_6 = F_237 ( V_30 ) ;
if ( V_6 )
goto V_386;
if ( F_60 ( V_11 ) )
V_173 = V_181 ;
else
V_173 = V_182 ;
V_6 = F_109 ( V_11 , V_173 , true ) ;
if ( V_6 )
goto V_386;
F_33 (ss, ssid) {
if ( V_15 -> V_22 & ( 1 << V_48 ) ) {
V_6 = F_221 ( V_11 , V_17 ,
V_15 -> V_115 & ( 1 << V_48 ) ) ;
if ( V_6 )
goto V_386;
}
}
if ( ! F_60 ( V_11 ) ) {
V_11 -> V_115 = V_15 -> V_115 ;
F_100 ( V_11 ) ;
}
F_118 ( V_30 ) ;
V_6 = 0 ;
goto V_24;
V_385:
F_9 ( & V_20 -> V_93 , V_11 -> V_9 ) ;
V_384:
F_151 ( & V_11 -> V_14 . V_175 ) ;
V_383:
F_41 ( V_11 ) ;
V_24:
F_101 ( V_382 ) ;
return V_6 ;
V_386:
F_329 ( V_11 ) ;
goto V_24;
}
static void F_330 ( struct V_321 * V_322 )
{
struct V_12 * V_23 =
F_12 ( V_322 , struct V_12 , V_362 ) ;
F_83 ( & V_19 ) ;
F_323 ( V_23 ) ;
F_86 ( & V_19 ) ;
F_97 ( V_23 ) ;
}
static void F_331 ( struct V_369 * V_370 )
{
struct V_12 * V_23 =
F_12 ( V_370 , struct V_12 , V_175 ) ;
F_141 ( & V_23 -> V_362 , F_330 ) ;
F_317 ( V_365 , & V_23 -> V_362 ) ;
}
static void F_222 ( struct V_12 * V_23 )
{
F_17 ( & V_19 ) ;
F_108 ( V_23 -> V_10 , 1 << V_23 -> V_17 -> V_9 ) ;
F_21 ( V_23 ) ;
F_332 ( & V_23 -> V_175 , F_331 ) ;
}
static int F_329 ( struct V_10 * V_11 )
__releases( &cgroup_mutex
static int F_333 ( struct V_119 * V_30 )
{
struct V_10 * V_11 ;
int V_6 = 0 ;
V_11 = F_104 ( V_30 ) ;
if ( ! V_11 )
return 0 ;
V_6 = F_329 ( V_11 ) ;
F_101 ( V_30 ) ;
return V_6 ;
}
static void T_8 F_334 ( struct V_16 * V_17 , bool V_387 )
{
struct V_12 * V_23 ;
F_335 ( V_388 L_38 , V_17 -> V_104 ) ;
F_83 ( & V_19 ) ;
F_143 ( & V_17 -> V_364 ) ;
F_56 ( & V_17 -> V_121 ) ;
V_17 -> V_20 = & V_96 ;
V_23 = V_17 -> V_375 ( F_13 ( & V_96 . V_11 , V_17 ) ) ;
F_50 ( F_149 ( V_23 ) ) ;
F_321 ( V_23 , V_17 , & V_96 . V_11 ) ;
V_23 -> V_26 |= V_389 ;
if ( V_387 ) {
V_23 -> V_9 = 1 ;
} else {
V_23 -> V_9 = F_1 ( & V_17 -> V_364 , V_23 , 1 , 2 , V_73 ) ;
F_50 ( V_23 -> V_9 < 0 ) ;
}
V_25 . V_18 [ V_17 -> V_9 ] = V_23 ;
V_390 |= ( bool ) V_17 -> V_391 << V_17 -> V_9 ;
V_392 |= ( bool ) V_17 -> exit << V_17 -> V_9 ;
V_393 |= ( bool ) V_17 -> V_394 << V_17 -> V_9 ;
F_50 ( ! F_39 ( & V_395 . V_78 ) ) ;
F_50 ( F_322 ( V_23 ) ) ;
F_86 ( & V_19 ) ;
}
int T_8 F_336 ( void )
{
static struct V_137 T_9 V_138 ;
struct V_16 * V_17 ;
int V_42 ;
F_142 ( & V_96 , & V_138 ) ;
V_96 . V_11 . V_14 . V_26 |= V_389 ;
F_114 ( V_395 . V_205 , & V_25 ) ;
F_33 (ss, i) {
F_214 ( ! V_17 -> V_375 || ! V_17 -> V_363 || V_17 -> V_104 || V_17 -> V_9 ,
L_39 ,
V_42 , V_396 [ V_42 ] , V_17 -> V_375 , V_17 -> V_363 ,
V_17 -> V_9 , V_17 -> V_104 ) ;
F_214 ( strlen ( V_396 [ V_42 ] ) > V_397 ,
L_40 , V_396 [ V_42 ] ) ;
V_17 -> V_9 = V_42 ;
V_17 -> V_104 = V_396 [ V_42 ] ;
if ( ! V_17 -> V_105 )
V_17 -> V_105 = V_396 [ V_42 ] ;
if ( V_17 -> V_398 )
F_334 ( V_17 , true ) ;
}
return 0 ;
}
int T_8 F_337 ( void )
{
struct V_16 * V_17 ;
unsigned long V_41 ;
int V_48 , V_214 ;
F_50 ( F_248 ( NULL , V_181 ) ) ;
F_50 ( F_248 ( NULL , V_182 ) ) ;
F_83 ( & V_19 ) ;
V_41 = F_32 ( V_25 . V_18 ) ;
F_70 ( V_83 , & V_25 . V_51 , V_41 ) ;
F_50 ( F_145 ( & V_96 , 0 ) ) ;
F_86 ( & V_19 ) ;
F_33 (ss, ssid) {
if ( V_17 -> V_398 ) {
struct V_12 * V_23 =
V_25 . V_18 [ V_17 -> V_9 ] ;
V_23 -> V_9 = F_1 ( & V_17 -> V_364 , V_23 , 1 , 2 ,
V_73 ) ;
F_50 ( V_23 -> V_9 < 0 ) ;
} else {
F_334 ( V_17 , false ) ;
}
F_63 ( & V_25 . V_50 [ V_48 ] ,
& V_96 . V_11 . V_84 [ V_48 ] ) ;
if ( V_17 -> V_153 )
continue;
V_96 . V_21 |= 1 << V_17 -> V_9 ;
if ( V_299 && ! V_17 -> V_300 )
V_17 -> V_300 = V_17 -> V_301 ;
if ( ! V_17 -> V_300 )
V_126 |= 1 << V_17 -> V_9 ;
if ( V_17 -> V_300 == V_17 -> V_301 ) {
F_113 ( F_252 ( V_17 , V_17 -> V_300 ) ) ;
} else {
F_113 ( F_253 ( V_17 , V_17 -> V_300 ) ) ;
F_113 ( F_254 ( V_17 , V_17 -> V_301 ) ) ;
}
if ( V_17 -> V_129 )
V_17 -> V_129 ( V_25 . V_18 [ V_48 ] ) ;
}
V_214 = F_338 ( V_399 , L_41 ) ;
if ( V_214 )
return V_214 ;
V_214 = F_339 ( & V_345 ) ;
if ( V_214 < 0 ) {
F_340 ( V_399 , L_41 ) ;
return V_214 ;
}
F_341 ( L_42 , 0 , NULL , & V_400 ) ;
return 0 ;
}
static int T_8 F_342 ( void )
{
V_365 = F_343 ( L_43 , 0 , 1 ) ;
F_50 ( ! V_365 ) ;
V_319 = F_343 ( L_44 ,
0 , 1 ) ;
F_50 ( ! V_319 ) ;
return 0 ;
}
int F_344 ( struct V_130 * V_268 , struct V_337 * V_329 ,
struct V_236 * V_236 , struct V_85 * V_86 )
{
char * V_100 , * V_197 ;
int V_245 ;
struct V_69 * V_20 ;
V_245 = - V_74 ;
V_100 = F_274 ( V_151 , V_73 ) ;
if ( ! V_100 )
goto V_174;
F_83 ( & V_19 ) ;
F_65 ( & V_37 ) ;
F_156 (root) {
struct V_16 * V_17 ;
struct V_10 * V_11 ;
int V_48 , V_71 = 0 ;
if ( V_20 == & V_96 && ! V_127 )
continue;
F_207 ( V_268 , L_45 , V_20 -> V_92 ) ;
if ( V_20 != & V_96 )
F_33 (ss, ssid)
if ( V_20 -> V_21 & ( 1 << V_48 ) )
F_207 ( V_268 , L_46 , V_71 ++ ? L_9 : L_23 ,
V_17 -> V_105 ) ;
if ( strlen ( V_20 -> V_104 ) )
F_207 ( V_268 , L_47 , V_71 ? L_9 : L_23 ,
V_20 -> V_104 ) ;
F_204 ( V_268 , ':' ) ;
V_11 = F_89 ( V_86 , V_20 ) ;
V_197 = F_168 ( V_11 , V_100 , V_151 ) ;
if ( ! V_197 ) {
V_245 = - V_401 ;
goto V_24;
}
F_121 ( V_268 , V_197 ) ;
F_204 ( V_268 , '\n' ) ;
}
V_245 = 0 ;
V_24:
F_66 ( & V_37 ) ;
F_86 ( & V_19 ) ;
F_41 ( V_100 ) ;
V_174:
return V_245 ;
}
static int F_345 ( struct V_130 * V_268 , void * V_247 )
{
struct V_16 * V_17 ;
int V_42 ;
F_121 ( V_268 , L_48 ) ;
F_83 ( & V_19 ) ;
F_33 (ss, i)
F_207 ( V_268 , L_49 ,
V_17 -> V_105 , V_17 -> V_20 -> V_92 ,
F_84 ( & V_17 -> V_20 -> V_94 ) , ! V_17 -> V_153 ) ;
F_86 ( & V_19 ) ;
return 0 ;
}
static int F_346 ( struct V_231 * V_231 , struct V_228 * V_228 )
{
return F_347 ( V_228 , F_345 , NULL ) ;
}
static void * * F_348 ( void * V_402 [ V_403 ] , int V_42 )
{
if ( V_404 <= V_42 && V_42 < V_405 )
return & V_402 [ V_42 - V_404 ] ;
return NULL ;
}
static void * F_349 ( void * V_402 [ V_403 ] , int V_42 )
{
void * * V_356 = F_348 ( V_402 , V_42 ) ;
return V_356 ? * V_356 : NULL ;
}
void F_350 ( struct V_85 * V_259 )
{
F_114 ( V_259 -> V_205 , & V_25 ) ;
F_56 ( & V_259 -> V_163 ) ;
}
int F_351 ( struct V_85 * V_259 ,
void * V_402 [ V_403 ] )
{
struct V_16 * V_17 ;
int V_42 , V_406 , V_6 ;
F_99 (ss, i, &have_canfork_callback) {
V_6 = V_17 -> V_394 ( V_259 , F_348 ( V_402 , V_42 ) ) ;
if ( V_6 )
goto V_407;
}
return 0 ;
V_407:
F_33 (ss, j) {
if ( V_406 >= V_42 )
break;
if ( V_17 -> V_408 )
V_17 -> V_408 ( V_259 , F_349 ( V_402 , V_406 ) ) ;
}
return V_6 ;
}
void F_352 ( struct V_85 * V_259 ,
void * V_402 [ V_403 ] )
{
struct V_16 * V_17 ;
int V_42 ;
F_33 (ss, i)
if ( V_17 -> V_408 )
V_17 -> V_408 ( V_259 , F_349 ( V_402 , V_42 ) ) ;
}
void F_353 ( struct V_85 * V_259 ,
void * V_409 [ V_403 ] )
{
struct V_16 * V_17 ;
int V_42 ;
if ( V_161 ) {
struct V_43 * V_44 ;
F_45 ( & V_37 ) ;
V_44 = F_90 ( V_157 ) ;
if ( F_39 ( & V_259 -> V_163 ) ) {
F_115 ( V_259 -> V_205 , V_44 ) ;
F_58 ( & V_259 -> V_163 , & V_44 -> V_78 ) ;
F_47 ( V_44 ) ;
}
F_46 ( & V_37 ) ;
}
F_99 (ss, i, &have_fork_callback)
V_17 -> V_391 ( V_259 , F_349 ( V_409 , V_42 ) ) ;
}
void F_354 ( struct V_85 * V_86 )
{
struct V_16 * V_17 ;
struct V_43 * V_44 ;
bool V_410 = false ;
int V_42 ;
if ( ! F_39 ( & V_86 -> V_163 ) ) {
F_45 ( & V_37 ) ;
F_175 ( & V_86 -> V_163 ) ;
F_46 ( & V_37 ) ;
V_410 = true ;
}
V_44 = F_90 ( V_86 ) ;
F_114 ( V_86 -> V_205 , & V_25 ) ;
F_99 (ss, i, &have_exit_callback) {
struct V_12 * V_411 = V_44 -> V_18 [ V_42 ] ;
struct V_12 * V_23 = F_355 ( V_86 , V_42 ) ;
V_17 -> exit ( V_23 , V_411 , V_86 ) ;
}
if ( V_410 )
F_43 ( V_44 ) ;
}
static void F_40 ( struct V_10 * V_11 )
{
if ( F_28 ( V_11 ) && ! F_356 ( V_11 ) &&
! F_265 ( & V_11 -> V_14 ) && ! F_23 ( V_11 ) )
F_357 ( & V_11 -> V_171 ) ;
}
static void V_172 ( struct V_321 * V_322 )
{
struct V_10 * V_11 =
F_12 ( V_322 , struct V_10 , V_171 ) ;
char * V_412 = NULL , * V_413 = NULL , * V_197 ;
char * V_414 [ 3 ] , * V_415 [ 3 ] ;
F_83 ( & V_19 ) ;
V_412 = F_274 ( V_151 , V_73 ) ;
V_413 = F_358 ( V_11 -> V_20 -> V_134 , V_73 ) ;
if ( ! V_412 || ! V_413 )
goto V_174;
V_197 = F_168 ( V_11 , V_412 , V_151 ) ;
if ( ! V_197 )
goto V_174;
V_414 [ 0 ] = V_413 ;
V_414 [ 1 ] = V_197 ;
V_414 [ 2 ] = NULL ;
V_415 [ 0 ] = L_50 ;
V_415 [ 1 ] = L_51 ;
V_415 [ 2 ] = NULL ;
F_86 ( & V_19 ) ;
F_359 ( V_414 [ 0 ] , V_414 , V_415 , V_416 ) ;
goto V_192;
V_174:
F_86 ( & V_19 ) ;
V_192:
F_41 ( V_413 ) ;
F_41 ( V_412 ) ;
}
static int T_8 F_360 ( char * V_417 )
{
struct V_16 * V_17 ;
char * V_139 ;
int V_42 ;
while ( ( V_139 = F_126 ( & V_417 , L_9 ) ) != NULL ) {
if ( ! * V_139 )
continue;
F_33 (ss, i) {
if ( strcmp ( V_139 , V_17 -> V_104 ) &&
strcmp ( V_139 , V_17 -> V_105 ) )
continue;
V_17 -> V_153 = 1 ;
F_335 ( V_388 L_52 ,
V_17 -> V_104 ) ;
break;
}
}
return 1 ;
}
static int T_8 F_361 ( char * V_417 )
{
F_335 ( L_53 ) ;
V_299 = true ;
return 0 ;
}
struct V_12 * F_362 ( struct V_185 * V_185 ,
struct V_16 * V_17 )
{
struct V_119 * V_30 = F_300 ( V_185 ) ;
struct V_12 * V_23 = NULL ;
struct V_10 * V_11 ;
if ( V_185 -> V_230 -> V_344 != & V_345 || ! V_30 ||
F_102 ( V_30 ) != V_120 )
return F_160 ( - V_418 ) ;
F_19 () ;
V_11 = F_301 ( V_30 -> V_31 ) ;
if ( V_11 )
V_23 = F_13 ( V_11 , V_17 ) ;
if ( ! V_23 || ! F_20 ( V_23 ) )
V_23 = F_160 ( - V_154 ) ;
F_22 () ;
return V_23 ;
}
struct V_12 * F_363 ( int V_9 , struct V_16 * V_17 )
{
F_80 ( ! F_364 () ) ;
return V_9 > 0 ? F_365 ( & V_17 -> V_364 , V_9 ) : NULL ;
}
static struct V_12 *
F_366 ( struct V_12 * V_13 )
{
struct V_12 * V_23 = F_57 ( sizeof( * V_23 ) , V_73 ) ;
if ( ! V_23 )
return F_160 ( - V_74 ) ;
return V_23 ;
}
static void F_367 ( struct V_12 * V_23 )
{
F_41 ( V_23 ) ;
}
static T_7 F_368 ( struct V_12 * V_23 ,
struct V_32 * V_33 )
{
return F_255 ( V_23 -> V_10 ) ;
}
static T_7 F_369 ( struct V_12 * V_23 ,
struct V_32 * V_33 )
{
return ( T_7 ) ( unsigned long ) V_157 -> V_205 ;
}
static T_7 F_370 ( struct V_12 * V_23 ,
struct V_32 * V_33 )
{
T_7 V_71 ;
F_19 () ;
V_71 = F_84 ( & F_90 ( V_157 ) -> V_49 ) ;
F_22 () ;
return V_71 ;
}
static int F_371 ( struct V_130 * V_131 , void * V_247 )
{
struct V_45 * V_46 ;
struct V_43 * V_44 ;
char * V_419 ;
V_419 = F_274 ( V_420 + 1 , V_73 ) ;
if ( ! V_419 )
return - V_74 ;
F_65 ( & V_37 ) ;
F_19 () ;
V_44 = F_301 ( V_157 -> V_205 ) ;
F_69 (link, &cset->cgrp_links, cgrp_link) {
struct V_10 * V_82 = V_46 -> V_11 ;
F_372 ( V_82 , V_419 , V_420 + 1 ) ;
F_207 ( V_131 , L_54 ,
V_82 -> V_20 -> V_92 , V_419 ) ;
}
F_22 () ;
F_66 ( & V_37 ) ;
F_41 ( V_419 ) ;
return 0 ;
}
static int F_373 ( struct V_130 * V_131 , void * V_247 )
{
struct V_12 * V_23 = F_203 ( V_131 ) ;
struct V_45 * V_46 ;
F_65 ( & V_37 ) ;
F_69 (link, &css->cgroup->cset_links, cset_link) {
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_85 * V_99 ;
int V_71 = 0 ;
F_207 ( V_131 , L_55 , V_44 ) ;
F_69 (task, &cset->tasks, cg_list) {
if ( V_71 ++ > V_421 )
goto V_422;
F_207 ( V_131 , L_56 , F_297 ( V_99 ) ) ;
}
F_69 (task, &cset->mg_tasks, cg_list) {
if ( V_71 ++ > V_421 )
goto V_422;
F_207 ( V_131 , L_56 , F_297 ( V_99 ) ) ;
}
continue;
V_422:
F_121 ( V_131 , L_57 ) ;
}
F_66 ( & V_37 ) ;
return 0 ;
}
static T_7 F_374 ( struct V_12 * V_23 , struct V_32 * V_33 )
{
return ( ! F_356 ( V_23 -> V_10 ) &&
! F_265 ( & V_23 -> V_10 -> V_14 ) ) ;
}
