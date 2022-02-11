static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
void (* F_2)( struct V_1 * ) )
{
F_3 ( & V_2 -> V_3 , V_3 ) ;
F_4 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_6 ) ;
V_2 -> F_2 = F_2 ;
}
static void F_6 ( struct V_1 * V_2 , struct V_1 * V_7 )
{
if ( V_7 )
F_7 ( & V_7 -> V_3 ) ;
V_2 -> V_7 = V_7 ;
if ( ! V_7 )
V_2 -> V_8 = V_2 ;
else
V_2 -> V_8 = V_7 -> V_8 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
enum V_9 V_10 )
{
if ( V_2 ) {
F_10 ( & V_2 -> V_6 , V_10 ) ;
F_7 ( & V_2 -> V_3 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_12 ( & V_2 -> V_6 ) ;
F_7 ( & V_2 -> V_3 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_14 ( & V_2 -> V_3 ) ;
F_15 ( & V_2 -> V_6 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_1 * V_11 = V_2 -> V_7 ;
F_11 ( V_11 ) ;
if ( F_17 ( & V_2 -> V_3 ) ) {
if ( V_11 )
F_18 ( & V_2 -> V_4 ) ;
if ( V_2 -> F_2 )
V_2 -> F_2 ( V_2 ) ;
F_19 ( V_2 ) ;
V_2 = NULL ;
}
F_13 ( V_11 ) ;
if ( ! V_2 && V_11 )
F_16 ( V_11 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
if ( F_21 ( & V_2 -> V_3 ) > 1 ) {
F_14 ( & V_2 -> V_3 ) ;
return - V_12 ;
}
F_16 ( V_2 ) ;
return 0 ;
}
static struct V_13 * F_22 ( struct V_14 * V_15 ,
unsigned int V_16 )
{
struct V_13 * V_17 ;
F_23 (iter_prio, ns) {
if ( V_17 -> V_16 == V_16 )
return V_17 ;
}
return NULL ;
}
static bool F_24 ( const T_1 * V_18 )
{
char * V_19 =
F_25 ( V_20 , V_18 , V_21 ) ;
return ! V_19 [ 0 ] &&
! memcmp ( V_19 , V_19 + 1 ,
F_26 ( V_20 ,
V_21 ) - 1 ) ;
}
static bool F_27 ( T_2 V_22 , const T_1 * V_18 )
{
if ( V_22 & ~ (
( 1 << V_23 ) |
( 1 << V_24 ) |
( 1 << V_25 ) ) )
return false ;
if ( ! ( V_22 &
1 << V_23 ) ) {
char * V_26 = F_25 ( V_20 ,
V_18 , V_27 ) ;
if ( V_26 [ 0 ] ||
memcmp ( V_26 , V_26 + 1 ,
F_28 ( V_28 ) - 1 ) )
return false ;
}
if ( ! ( V_22 &
1 << V_24 ) ) {
char * V_26 = F_25 ( V_20 ,
V_18 , V_29 ) ;
if ( V_26 [ 0 ] ||
memcmp ( V_26 , V_26 + 1 ,
F_28 ( V_30 ) - 1 ) )
return false ;
}
if ( ! ( V_22 &
1 << V_25 ) ) {
char * V_26 = F_25 ( V_20 ,
V_18 , V_31 ) ;
if ( V_26 [ 0 ] ||
memcmp ( V_26 , V_26 + 1 ,
F_28 ( V_28 ) - 1 ) )
return false ;
}
return F_24 ( V_18 ) ;
}
static bool F_29 ( const struct V_32 * V_33 )
{
int V_34 ;
if ( ! F_27 ( V_33 -> V_22 , V_33 -> V_18 ) ) {
F_30 ( L_1 ) ;
return false ;
}
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
if ( V_33 -> V_36 [ V_34 ] & ~ V_33 -> V_18 [ V_34 ] ) {
F_30 ( L_2 ) ;
return false ;
}
return F_24 ( V_33 -> V_36 ) ;
}
static struct V_37 * F_31 ( struct V_1 * V_2 )
{
struct V_1 * V_8 ;
struct V_14 * V_15 ;
V_8 = V_2 -> V_8 ;
if ( F_32 ( V_8 -> type != V_38 ) ) {
F_30 ( L_3 ) ;
return NULL ;
}
V_15 = F_33 ( V_8 , struct V_14 , V_2 ) ;
return F_33 ( V_15 , struct V_37 , V_15 ) ;
}
static inline struct V_39 * F_34 ( struct V_1 * V_2 )
{
struct V_37 * V_8 = F_31 ( V_2 ) ;
if ( V_8 )
return V_8 -> V_40 ;
return NULL ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
struct V_39 * V_40 ;
struct V_13 * V_16 ;
int V_43 ;
F_36 ( V_42 , V_2 ) ;
V_40 = F_34 ( & V_42 -> V_2 ) ;
V_43 = F_37 ( V_40 , V_42 ) ;
if ( V_43 )
F_38 ( V_40 , L_4 ) ;
F_39 ( & V_42 -> V_44 ) ;
F_40 ( & V_42 -> V_45 ) ;
F_36 ( V_16 , V_42 -> V_2 . V_7 ) ;
V_16 -> V_46 -- ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_47 * V_48 ;
struct V_41 * V_42 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
int V_53 ;
struct V_39 * V_40 = F_34 ( V_2 ) ;
int V_43 ;
bool V_54 = false ;
F_36 ( V_48 , V_2 ) ;
F_36 ( V_52 , V_48 -> V_2 . V_7 ) ;
F_36 ( V_50 , V_52 -> V_2 . V_7 ) ;
F_36 ( V_42 , V_50 -> V_2 . V_7 ) ;
F_42 ( V_48 ) ;
F_43 ( & V_48 -> V_2 . V_4 ) ;
if ( V_48 -> V_55 == V_56 ) {
F_12 ( & V_48 -> V_57 . V_42 -> V_6 ) ;
F_43 ( & V_48 -> V_58 ) ;
F_15 ( & V_48 -> V_57 . V_42 -> V_6 ) ;
}
if ( V_48 -> V_57 . type == V_59 &&
-- V_52 -> V_60 ) {
V_53 = F_44 ( V_61 ) ;
V_52 -> V_62 &= ~ V_63 ;
V_54 = true ;
goto V_64;
}
if ( ( V_52 -> V_62 & V_65 ) &&
-- V_52 -> V_60 ) {
V_53 = F_44 ( V_66 ) ,
V_54 = true ;
}
V_64:
if ( V_54 && V_52 -> V_60 ) {
V_43 = F_45 ( V_40 , V_42 , V_50 -> V_67 , V_53 , V_52 ) ;
if ( V_43 )
F_38 ( V_40 ,
L_5 ,
V_68 , V_50 -> V_67 , V_52 -> V_69 ) ;
}
}
static void F_46 ( struct V_51 * V_52 , struct V_49 * V_50 )
{
struct V_41 * V_42 ;
int V_70 ;
V_70 = F_47 ( & V_50 -> V_71 , & V_52 -> V_72 , V_73 ) ;
F_32 ( V_70 ) ;
V_52 -> V_74 = 0 ;
F_36 ( V_42 , V_50 -> V_2 . V_7 ) ;
F_48 ( & V_42 -> V_44 , V_52 -> V_69 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
struct V_49 * V_50 ;
struct V_39 * V_40 ;
struct V_51 * V_52 ;
int V_43 ;
F_36 ( V_52 , V_2 ) ;
F_36 ( V_50 , V_52 -> V_2 . V_7 ) ;
F_36 ( V_42 , V_50 -> V_2 . V_7 ) ;
F_50 ( V_52 ) ;
V_40 = F_34 ( & V_42 -> V_2 ) ;
V_43 = F_51 ( V_40 , V_42 ,
V_52 -> V_69 ) ;
if ( V_43 )
F_38 ( V_40 ,
L_6 ,
V_52 -> V_69 , V_50 -> V_67 ) ;
F_46 ( V_52 , V_50 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
struct V_41 * V_42 ;
struct V_39 * V_40 ;
int V_43 ;
F_36 ( V_50 , V_2 ) ;
F_36 ( V_42 , V_50 -> V_2 . V_7 ) ;
V_40 = F_34 ( & V_42 -> V_2 ) ;
F_53 ( V_50 ) ;
if ( V_42 -> V_75 . V_76 )
V_42 -> V_75 . V_77 -- ;
F_54 ( & V_50 -> V_71 ) ;
V_43 = F_55 ( & V_42 -> V_45 ,
& V_50 -> V_72 ,
V_78 ) ;
F_32 ( V_43 ) ;
if ( F_56 ( V_40 , V_42 , V_50 -> V_67 ) )
F_38 ( V_40 , L_7 ,
V_50 -> V_67 , V_42 -> V_67 ) ;
}
static struct V_51 * F_57 ( struct V_79 * V_80 ,
T_1 * V_36 ,
unsigned int V_69 )
{
struct V_51 * V_52 ;
V_52 = F_58 ( sizeof( * V_52 ) , V_81 ) ;
if ( ! V_52 )
return F_59 ( - V_82 ) ;
memcpy ( V_52 -> V_83 , V_36 , sizeof( V_52 -> V_83 ) ) ;
V_52 -> V_2 . type = V_84 ;
V_52 -> V_85 = V_80 -> V_85 ;
V_52 -> V_69 = V_69 ;
V_52 -> V_62 = V_80 -> V_62 ;
V_52 -> V_86 = V_80 -> V_86 ;
V_52 -> V_87 = V_80 -> V_87 ;
return V_52 ;
}
static struct V_49 * F_60 ( T_1 * V_88 )
{
struct V_49 * V_50 ;
void * V_18 = F_25 ( V_89 ,
V_88 , V_18 ) ;
T_2 V_22 = F_61 ( V_89 ,
V_88 ,
V_22 ) ;
int V_70 ;
V_50 = F_58 ( sizeof( * V_50 ) , V_81 ) ;
if ( ! V_50 )
return F_59 ( - V_82 ) ;
V_70 = F_62 ( & V_50 -> V_71 , & V_73 ) ;
if ( V_70 ) {
F_19 ( V_50 ) ;
return F_59 ( V_70 ) ;
}
V_50 -> V_90 . V_22 = V_22 ;
memcpy ( & V_50 -> V_90 . V_18 , V_18 ,
sizeof( V_50 -> V_90 . V_18 ) ) ;
V_50 -> V_2 . type = V_91 ;
V_50 -> V_92 = F_61 ( V_89 , V_88 ,
V_93 ) ;
V_50 -> V_94 = F_61 ( V_89 , V_88 ,
V_95 ) - V_50 -> V_92 + 1 ;
return V_50 ;
}
static struct V_41 * F_63 ( int V_96 , T_3 V_97 , int V_98 ,
enum V_99 V_100 ,
enum V_101 V_102 ,
T_1 V_103 )
{
struct V_41 * V_42 ;
int V_70 ;
V_42 = F_58 ( sizeof( * V_42 ) , V_81 ) ;
if ( ! V_42 )
return F_59 ( - V_82 ) ;
V_70 = F_64 ( & V_42 -> V_45 , & V_78 ) ;
if ( V_70 ) {
F_19 ( V_42 ) ;
return F_59 ( V_70 ) ;
}
V_42 -> V_96 = V_96 ;
V_42 -> V_2 . type = V_104 ;
V_42 -> V_102 = V_102 ;
V_42 -> type = V_100 ;
V_42 -> V_97 = V_97 ;
V_42 -> V_98 = V_98 ;
V_42 -> V_103 = V_103 ;
F_4 ( & V_42 -> V_105 ) ;
F_5 ( & V_42 -> V_6 ) ;
F_65 ( & V_42 -> V_44 ) ;
return V_42 ;
}
static struct V_41 * F_66 ( struct V_1 * V_8 ,
struct V_106 * V_107 ,
bool V_108 )
{
#define F_67 ( T_4 , V_108 ) \
((reverse) ? list_prev_entry(pos, list) : list_next_entry(pos, list))
#define F_68 ( T_4 , T_5 , V_108 ) \
for (pos = list_advance_entry(pos, reverse); \
&pos->list != (head); \
pos = list_advance_entry(pos, reverse))
struct V_1 * V_109 = F_69 ( V_107 , struct V_1 , V_4 ) ;
struct V_41 * V_42 = NULL ;
if ( ! V_8 )
return NULL ;
F_68 (iter, &root->children, reverse) {
if ( V_109 -> type == V_104 ) {
F_36 ( V_42 , V_109 ) ;
return V_42 ;
}
V_42 = F_66 ( V_109 , & V_109 -> V_5 , V_108 ) ;
if ( V_42 )
return V_42 ;
}
return V_42 ;
}
static struct V_41 * F_70 ( struct V_13 * V_16 , bool V_108 )
{
struct V_41 * V_42 = NULL ;
struct V_1 * V_110 ;
struct V_1 * V_7 ;
V_7 = V_16 -> V_2 . V_7 ;
V_110 = & V_16 -> V_2 ;
while ( ! V_42 && V_7 ) {
V_42 = F_66 ( V_7 , & V_110 -> V_4 , V_108 ) ;
V_110 = V_7 ;
V_7 = V_110 -> V_7 ;
}
return V_42 ;
}
static struct V_41 * F_71 ( struct V_13 * V_16 )
{
return F_70 ( V_16 , false ) ;
}
static struct V_41 * F_72 ( struct V_13 * V_16 )
{
return F_70 ( V_16 , true ) ;
}
static int F_73 ( struct V_39 * V_40 ,
struct V_13 * V_16 ,
struct V_41 * V_42 )
{
struct V_41 * V_109 ;
int V_34 = 0 ;
int V_43 ;
F_74 (iter, prio) {
V_34 ++ ;
V_43 = F_75 ( V_40 ,
V_109 ,
V_42 ) ;
if ( V_43 ) {
F_38 ( V_40 , L_8 ,
V_109 -> V_67 ) ;
if ( V_34 > 1 )
F_32 ( true ) ;
return V_43 ;
}
}
return 0 ;
}
static int F_76 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_13 * V_16 )
{
struct V_41 * V_111 ;
V_111 = F_72 ( V_16 ) ;
if ( V_111 ) {
struct V_13 * V_112 ;
F_36 ( V_112 , V_111 -> V_2 . V_7 ) ;
return F_73 ( V_40 , V_112 , V_42 ) ;
}
return 0 ;
}
static int F_77 ( struct V_41 * V_42 , struct V_13
* V_16 )
{
struct V_37 * V_8 = F_31 ( & V_16 -> V_2 ) ;
int V_113 = V_114 ;
int V_43 ;
if ( V_8 -> V_115 )
V_113 = V_8 -> V_115 -> V_96 ;
if ( V_42 -> V_96 >= V_113 )
return 0 ;
V_43 = F_78 ( V_8 -> V_40 , V_42 , V_8 -> V_116 ) ;
if ( V_43 )
F_38 ( V_8 -> V_40 , L_9 ,
V_42 -> V_67 ) ;
else
V_8 -> V_115 = V_42 ;
return V_43 ;
}
static int F_79 ( struct V_47 * V_48 ,
struct V_117 * V_118 )
{
struct V_41 * V_42 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
int V_53 = F_44 ( V_66 ) ;
int V_43 = 0 ;
F_36 ( V_52 , V_48 -> V_2 . V_7 ) ;
if ( ! ( V_52 -> V_62 & V_65 ) )
return - V_119 ;
F_11 ( & V_52 -> V_2 ) ;
F_36 ( V_50 , V_52 -> V_2 . V_7 ) ;
F_36 ( V_42 , V_50 -> V_2 . V_7 ) ;
memcpy ( & V_48 -> V_57 , V_118 , sizeof( * V_118 ) ) ;
V_43 = F_45 ( F_34 ( & V_42 -> V_2 ) ,
V_42 , V_50 -> V_67 ,
V_53 ,
V_52 ) ;
F_13 ( & V_52 -> V_2 ) ;
return V_43 ;
}
int F_80 ( struct V_120 * V_121 ,
struct V_117 * V_122 ,
struct V_117 * V_123 )
{
int V_34 ;
if ( ! V_123 ) {
if ( V_121 -> V_124 != 1 )
return - V_119 ;
return F_79 ( V_121 -> V_48 [ 0 ] ,
V_122 ) ;
}
for ( V_34 = 0 ; V_34 < V_121 -> V_124 ; V_34 ++ ) {
if ( F_81 ( V_122 , & V_121 -> V_48 [ V_34 ] -> V_57 ) )
return F_79 ( V_121 -> V_48 [ V_34 ] ,
V_122 ) ;
}
return - V_119 ;
}
static int F_82 ( struct V_39 * V_40 ,
struct V_41 * V_125 ,
struct V_41 * V_126 )
{
struct V_117 V_118 ;
struct V_47 * V_109 ;
int V_43 = 0 ;
if ( ! V_125 || ! V_126 )
return 0 ;
V_118 . type = V_127 ;
V_118 . V_42 = V_125 ;
F_12 ( & V_126 -> V_6 ) ;
F_83 ( & V_126 -> V_105 , & V_125 -> V_105 ) ;
F_15 ( & V_126 -> V_6 ) ;
F_84 (iter, &new_next_ft->fwd_rules, next_ft) {
V_43 = F_79 ( V_109 , & V_118 ) ;
if ( V_43 )
F_85 ( L_10 ,
V_125 -> V_67 ) ;
}
return 0 ;
}
static int F_86 ( struct V_39 * V_40 , struct V_41 * V_42 ,
struct V_13 * V_16 )
{
struct V_41 * V_58 ;
int V_43 = 0 ;
if ( F_87 ( & V_16 -> V_2 . V_5 ) ) {
V_43 = F_76 ( V_40 , V_42 , V_16 ) ;
if ( V_43 )
return V_43 ;
V_58 = F_71 ( V_16 ) ;
V_43 = F_82 ( V_40 , V_42 , V_58 ) ;
if ( V_43 )
return V_43 ;
}
if ( F_88 ( V_40 ,
V_128 . V_129 ) )
V_43 = F_77 ( V_42 , V_16 ) ;
return V_43 ;
}
static void F_89 ( struct V_41 * V_42 ,
struct V_13 * V_16 )
{
struct V_106 * V_130 = & V_16 -> V_2 . V_5 ;
struct V_41 * V_109 ;
F_74 (iter, prio) {
if ( V_109 -> V_96 > V_42 -> V_96 )
break;
V_130 = & V_109 -> V_2 . V_4 ;
}
F_90 ( & V_42 -> V_2 . V_4 , V_130 ) ;
}
static struct V_41 * F_91 ( struct V_14 * V_15 ,
struct V_131 * V_132 ,
enum V_101 V_102 ,
T_3 V_97 )
{
struct V_37 * V_8 = F_31 ( & V_15 -> V_2 ) ;
struct V_41 * V_58 = NULL ;
struct V_13 * V_13 = NULL ;
struct V_41 * V_42 ;
int V_133 ;
int V_43 ;
if ( ! V_8 ) {
F_85 ( L_11 ) ;
return F_59 ( - V_134 ) ;
}
F_12 ( & V_8 -> V_135 ) ;
V_13 = F_22 ( V_15 , V_132 -> V_16 ) ;
if ( ! V_13 ) {
V_43 = - V_119 ;
goto V_136;
}
if ( V_132 -> V_96 >= V_13 -> V_137 ) {
V_43 = - V_138 ;
goto V_136;
}
V_132 -> V_96 += V_13 -> V_139 ;
V_42 = F_63 ( V_132 -> V_96 ,
V_97 ,
V_132 -> V_98 ? F_92 ( V_132 -> V_98 ) : 0 ,
V_8 -> V_100 ,
V_102 , V_132 -> V_103 ) ;
if ( F_93 ( V_42 ) ) {
V_43 = F_94 ( V_42 ) ;
goto V_136;
}
F_1 ( & V_42 -> V_2 , 1 , F_35 ) ;
V_133 = V_42 -> V_98 ? F_95 ( V_42 -> V_98 ) : 0 ;
V_58 = F_71 ( V_13 ) ;
V_43 = F_96 ( V_8 -> V_40 , V_42 -> V_97 , V_42 -> V_102 , V_42 -> type ,
V_42 -> V_96 , V_133 , V_58 , & V_42 -> V_67 ,
V_42 -> V_103 ) ;
if ( V_43 )
goto V_140;
V_43 = F_86 ( V_8 -> V_40 , V_42 , V_13 ) ;
if ( V_43 )
goto V_141;
F_11 ( & V_13 -> V_2 ) ;
F_6 ( & V_42 -> V_2 , & V_13 -> V_2 ) ;
F_89 ( V_42 , V_13 ) ;
V_13 -> V_46 ++ ;
F_13 ( & V_13 -> V_2 ) ;
F_15 ( & V_8 -> V_135 ) ;
return V_42 ;
V_141:
F_37 ( V_8 -> V_40 , V_42 ) ;
V_140:
F_39 ( & V_42 -> V_44 ) ;
F_19 ( V_42 ) ;
V_136:
F_15 ( & V_8 -> V_135 ) ;
return F_59 ( V_43 ) ;
}
struct V_41 * F_97 ( struct V_14 * V_15 ,
struct V_131 * V_132 )
{
return F_91 ( V_15 , V_132 , V_142 , 0 ) ;
}
struct V_41 * F_98 ( struct V_14 * V_15 ,
int V_16 , int V_98 ,
T_1 V_96 , T_3 V_97 )
{
struct V_131 V_132 = {} ;
V_132 . V_98 = V_98 ;
V_132 . V_96 = V_96 ;
V_132 . V_16 = V_16 ;
return F_91 ( V_15 , & V_132 , V_142 , V_97 ) ;
}
struct V_41 *
F_99 ( struct V_14 * V_15 ,
int V_16 , T_1 V_96 )
{
struct V_131 V_132 = {} ;
V_132 . V_96 = V_96 ;
V_132 . V_16 = V_16 ;
return F_91 ( V_15 , & V_132 , V_143 , 0 ) ;
}
struct V_41 *
F_100 ( struct V_14 * V_15 ,
int V_16 ,
int V_144 ,
int V_145 ,
T_1 V_96 ,
T_1 V_103 )
{
struct V_131 V_132 = {} ;
struct V_41 * V_42 ;
if ( V_145 > V_144 )
return F_59 ( - V_119 ) ;
V_132 . V_98 = V_144 ;
V_132 . V_16 = V_16 ;
V_132 . V_96 = V_96 ;
V_132 . V_103 = V_103 ;
V_42 = F_97 ( V_15 , & V_132 ) ;
if ( F_93 ( V_42 ) )
return V_42 ;
V_42 -> V_75 . V_76 = true ;
V_42 -> V_75 . V_146 = V_145 ;
return V_42 ;
}
static struct V_49 * F_101 ( struct V_41 * V_42 ,
T_1 * V_147 ,
struct V_106
* V_148 ,
bool V_149 )
{
struct V_49 * V_50 ;
struct V_39 * V_40 = F_34 ( & V_42 -> V_2 ) ;
int V_43 ;
if ( ! V_40 )
return F_59 ( - V_134 ) ;
V_50 = F_60 ( V_147 ) ;
if ( F_93 ( V_50 ) )
return V_50 ;
V_43 = F_102 ( & V_42 -> V_45 , & V_50 -> V_72 , V_78 ) ;
if ( V_43 )
goto V_150;
V_43 = F_103 ( V_40 , V_42 , V_147 , & V_50 -> V_67 ) ;
if ( V_43 )
goto V_151;
if ( V_42 -> V_75 . V_76 )
V_42 -> V_75 . V_77 ++ ;
F_1 ( & V_50 -> V_2 , ! V_149 , F_52 ) ;
F_6 ( & V_50 -> V_2 , & V_42 -> V_2 ) ;
F_90 ( & V_50 -> V_2 . V_4 , V_148 ) ;
F_104 ( V_50 ) ;
return V_50 ;
V_151:
F_32 ( F_55 ( & V_42 -> V_45 ,
& V_50 -> V_72 ,
V_78 ) ) ;
V_150:
F_54 ( & V_50 -> V_71 ) ;
F_19 ( V_50 ) ;
return F_59 ( V_43 ) ;
}
struct V_49 * F_105 ( struct V_41 * V_42 ,
T_1 * V_147 )
{
void * V_18 = F_25 ( V_89 ,
V_147 , V_18 ) ;
T_2 V_22 = F_61 ( V_89 ,
V_147 ,
V_22 ) ;
struct V_49 * V_50 ;
if ( ! F_27 ( V_22 , V_18 ) )
return F_59 ( - V_119 ) ;
if ( V_42 -> V_75 . V_76 )
return F_59 ( - V_152 ) ;
F_11 ( & V_42 -> V_2 ) ;
V_50 = F_101 ( V_42 , V_147 , V_42 -> V_2 . V_5 . V_130 , false ) ;
F_13 ( & V_42 -> V_2 ) ;
return V_50 ;
}
static struct V_47 * F_106 ( struct V_117 * V_118 )
{
struct V_47 * V_48 ;
V_48 = F_58 ( sizeof( * V_48 ) , V_81 ) ;
if ( ! V_48 )
return NULL ;
F_4 ( & V_48 -> V_58 ) ;
V_48 -> V_2 . type = V_153 ;
if ( V_118 )
memcpy ( & V_48 -> V_57 , V_118 , sizeof( * V_118 ) ) ;
return V_48 ;
}
static struct V_120 * F_107 ( int V_124 )
{
struct V_120 * V_121 ;
V_121 = F_58 ( sizeof( * V_121 ) + sizeof( V_121 -> V_48 [ 0 ] ) *
V_124 , V_81 ) ;
if ( ! V_121 )
return NULL ;
V_121 -> V_124 = V_124 ;
return V_121 ;
}
static void F_108 ( struct V_51 * V_52 ,
struct V_120 * V_121 ,
struct V_117 * V_118 ,
int V_34 )
{
for (; -- V_34 >= 0 ; ) {
if ( F_17 ( & V_121 -> V_48 [ V_34 ] -> V_2 . V_3 ) ) {
V_52 -> V_60 -- ;
F_43 ( & V_121 -> V_48 [ V_34 ] -> V_2 . V_4 ) ;
F_19 ( V_121 -> V_48 [ V_34 ] ) ;
}
}
F_19 ( V_121 ) ;
}
static struct V_120 *
F_109 ( struct V_51 * V_52 ,
struct V_117 * V_118 ,
int V_154 ,
int * V_53 ,
bool * V_155 )
{
struct V_120 * V_121 ;
struct V_47 * V_48 = NULL ;
static int V_156 = F_44 ( V_157 ) ;
static int V_158 = F_44 ( V_66 ) ;
int type ;
int V_34 = 0 ;
V_121 = F_107 ( ( V_154 ) ? V_154 : 1 ) ;
if ( ! V_121 )
return F_59 ( - V_82 ) ;
do {
if ( V_118 ) {
V_48 = F_110 ( V_52 , V_118 + V_34 ) ;
if ( V_48 ) {
F_7 ( & V_48 -> V_2 . V_3 ) ;
goto V_159;
}
}
* V_155 = true ;
V_48 = F_106 ( V_118 + V_34 ) ;
if ( ! V_48 )
goto V_160;
F_1 ( & V_48 -> V_2 , 1 , F_41 ) ;
if ( V_118 &&
V_118 [ V_34 ] . type != V_127 )
F_90 ( & V_48 -> V_2 . V_4 , & V_52 -> V_2 . V_5 ) ;
else
F_111 ( & V_48 -> V_2 . V_4 , & V_52 -> V_2 . V_5 ) ;
if ( V_118 ) {
V_52 -> V_60 ++ ;
type = V_118 [ V_34 ] . type ==
V_59 ;
* V_53 |= type ? V_156 : V_158 ;
}
V_159:
V_121 -> V_48 [ V_34 ] = V_48 ;
} while ( ++ V_34 < V_154 );
return V_121 ;
V_160:
F_108 ( V_52 , V_121 , V_118 , V_34 ) ;
return F_59 ( - V_82 ) ;
}
static struct V_120 *
F_112 ( struct V_51 * V_52 ,
struct V_49 * V_50 ,
struct V_117 * V_118 ,
int V_154 ,
bool V_161 )
{
struct V_120 * V_121 ;
struct V_41 * V_42 ;
int V_53 = 0 ;
int V_43 ;
bool V_155 = false ;
V_121 = F_109 ( V_52 , V_118 , V_154 , & V_53 ,
& V_155 ) ;
if ( F_93 ( V_121 ) || ! V_155 )
goto V_64;
if ( V_161 )
V_53 |= F_44 ( V_61 ) ;
F_36 ( V_42 , V_50 -> V_2 . V_7 ) ;
if ( ! ( V_52 -> V_74 & V_162 ) )
V_43 = F_113 ( F_34 ( & V_42 -> V_2 ) ,
V_42 , V_50 -> V_67 , V_52 ) ;
else
V_43 = F_45 ( F_34 ( & V_42 -> V_2 ) ,
V_42 , V_50 -> V_67 , V_53 , V_52 ) ;
if ( V_43 )
goto V_163;
V_52 -> V_74 |= V_162 ;
V_64:
return V_121 ;
V_163:
F_108 ( V_52 , V_121 , V_118 , V_121 -> V_124 ) ;
return F_59 ( V_43 ) ;
}
static struct V_51 * F_114 ( struct V_49 * V_50 ,
T_1 * V_36 ,
struct V_79 * V_80 )
{
struct V_41 * V_42 ;
struct V_51 * V_52 ;
int V_69 ;
int V_70 ;
F_36 ( V_42 , V_50 -> V_2 . V_7 ) ;
V_69 = F_115 ( & V_42 -> V_44 , V_50 -> V_92 ,
V_50 -> V_92 + V_50 -> V_94 ,
V_81 ) ;
if ( V_69 < 0 )
return F_59 ( V_69 ) ;
V_52 = F_57 ( V_80 , V_36 , V_69 ) ;
if ( F_93 ( V_52 ) ) {
V_70 = F_94 ( V_52 ) ;
goto V_164;
}
V_70 = F_116 ( & V_50 -> V_71 , & V_52 -> V_72 , V_73 ) ;
if ( V_70 )
goto V_165;
return V_52 ;
V_165:
F_19 ( V_52 ) ;
V_164:
F_48 ( & V_42 -> V_44 , V_69 ) ;
return F_59 ( V_70 ) ;
}
static struct V_49 * F_117 ( struct V_41 * V_42 ,
T_2 V_22 ,
T_1 * V_18 )
{
int V_166 = F_28 ( V_89 ) ;
struct V_106 * V_130 = & V_42 -> V_2 . V_5 ;
unsigned int V_167 = 0 ;
struct V_49 * V_50 ;
void * V_168 ;
unsigned int V_169 = 0 ;
T_1 * V_170 ;
if ( ! V_42 -> V_75 . V_76 )
return F_59 ( - V_171 ) ;
V_170 = F_118 ( V_166 , V_81 ) ;
if ( ! V_170 )
return F_59 ( - V_82 ) ;
if ( V_42 -> V_75 . V_77 < V_42 -> V_75 . V_146 )
V_169 = V_42 -> V_98 / ( V_42 -> V_75 . V_146 + 1 ) ;
if ( V_169 == 0 )
V_169 = 1 ;
F_119 (fg, ft) {
if ( V_167 + V_169 > V_50 -> V_92 )
V_167 = V_50 -> V_92 + V_50 -> V_94 ;
else
break;
V_130 = & V_50 -> V_2 . V_4 ;
}
if ( V_167 + V_169 > V_42 -> V_98 ) {
V_50 = F_59 ( - V_138 ) ;
goto V_64;
}
F_120 ( V_89 , V_170 , V_22 ,
V_22 ) ;
F_120 ( V_89 , V_170 , V_93 , V_167 ) ;
F_120 ( V_89 , V_170 , V_95 , V_167 +
V_169 - 1 ) ;
V_168 = F_25 ( V_89 ,
V_170 , V_18 ) ;
memcpy ( V_168 , V_18 ,
F_28 ( V_20 ) ) ;
V_50 = F_101 ( V_42 , V_170 , V_130 , true ) ;
V_64:
F_121 ( V_170 ) ;
return V_50 ;
}
static bool F_81 ( struct V_117 * V_172 ,
struct V_117 * V_173 )
{
if ( V_172 -> type == V_173 -> type ) {
if ( ( V_172 -> type == V_174 &&
V_172 -> V_175 == V_173 -> V_175 ) ||
( V_172 -> type == V_127 &&
V_172 -> V_42 == V_173 -> V_42 ) ||
( V_172 -> type == V_176 &&
V_172 -> V_177 == V_173 -> V_177 ) )
return true ;
}
return false ;
}
static struct V_47 * F_110 ( struct V_51 * V_52 ,
struct V_117 * V_118 )
{
struct V_47 * V_48 ;
F_84 (rule, &fte->node.children, node.list) {
if ( F_81 ( & V_48 -> V_57 , V_118 ) )
return V_48 ;
}
return NULL ;
}
static bool F_122 ( T_1 V_178 , T_1 V_179 )
{
T_1 V_180 = V_178 ^ V_179 ;
if ( V_178 == V_63 ||
V_179 == V_63 )
return false ;
if ( V_180 & ( V_181 |
V_182 |
V_183 ) )
return true ;
return false ;
}
static int F_123 ( struct V_51 * V_52 , const struct V_79 * V_80 )
{
if ( F_122 ( V_80 -> V_62 , V_52 -> V_62 ) ) {
F_38 ( F_34 ( & V_52 -> V_2 ) ,
L_12 ) ;
return - V_12 ;
}
if ( V_52 -> V_85 != V_80 -> V_85 ) {
F_38 ( F_34 ( & V_52 -> V_2 ) ,
L_13 ,
V_52 -> V_85 ,
V_80 -> V_85 ) ;
return - V_12 ;
}
return 0 ;
}
static struct V_120 * F_124 ( struct V_49 * V_50 ,
T_1 * V_36 ,
struct V_79 * V_80 ,
struct V_117 * V_118 ,
int V_154 ,
struct V_51 * V_52 )
{
struct V_120 * V_121 ;
struct V_41 * V_42 ;
int V_34 ;
if ( V_52 ) {
int V_184 ;
int V_70 ;
F_9 ( & V_52 -> V_2 , V_185 ) ;
V_70 = F_123 ( V_52 , V_80 ) ;
if ( V_70 ) {
V_121 = F_59 ( V_70 ) ;
goto V_186;
}
V_184 = V_52 -> V_62 ;
V_52 -> V_62 |= V_80 -> V_62 ;
V_121 = F_112 ( V_52 , V_50 , V_118 , V_154 ,
V_184 != V_80 -> V_62 ) ;
if ( F_93 ( V_121 ) ) {
V_52 -> V_62 = V_184 ;
goto V_186;
} else {
F_125 ( V_52 , false ) ;
goto V_187;
}
}
F_36 ( V_42 , V_50 -> V_2 . V_7 ) ;
V_52 = F_114 ( V_50 , V_36 , V_80 ) ;
if ( F_93 ( V_52 ) )
return ( void * ) V_52 ;
F_1 ( & V_52 -> V_2 , 0 , F_49 ) ;
F_9 ( & V_52 -> V_2 , V_185 ) ;
V_121 = F_112 ( V_52 , V_50 , V_118 , V_154 , false ) ;
if ( F_93 ( V_121 ) ) {
F_13 ( & V_52 -> V_2 ) ;
F_46 ( V_52 , V_50 ) ;
F_19 ( V_52 ) ;
return V_121 ;
}
F_6 ( & V_52 -> V_2 , & V_50 -> V_2 ) ;
F_111 ( & V_52 -> V_2 . V_4 , & V_50 -> V_2 . V_5 ) ;
F_125 ( V_52 , true ) ;
V_187:
for ( V_34 = 0 ; V_34 < V_121 -> V_124 ; V_34 ++ ) {
if ( F_21 ( & V_121 -> V_48 [ V_34 ] -> V_2 . V_3 ) == 1 ) {
F_6 ( & V_121 -> V_48 [ V_34 ] -> V_2 , & V_52 -> V_2 ) ;
F_126 ( V_121 -> V_48 [ V_34 ] ) ;
}
}
V_186:
F_13 ( & V_52 -> V_2 ) ;
return V_121 ;
}
struct V_188 * F_127 ( struct V_120 * V_121 )
{
struct V_47 * V_158 ;
struct V_51 * V_52 ;
F_36 ( V_52 , V_121 -> V_48 [ 0 ] -> V_2 . V_7 ) ;
F_128 (dst, fte) {
if ( V_158 -> V_57 . type == V_59 )
return V_158 -> V_57 . V_189 ;
}
return NULL ;
}
static bool F_129 ( struct V_188 * V_189 , T_1 V_62 )
{
if ( ! ( V_62 & V_63 ) )
return ! V_189 ;
if ( ! V_189 )
return false ;
return ( V_62 & ( V_181 |
V_65 ) ) ;
}
static bool F_130 ( struct V_117 * V_118 ,
T_1 V_62 ,
struct V_41 * V_42 )
{
if ( V_118 && ( V_118 -> type == V_59 ) )
return F_129 ( V_118 -> V_189 , V_62 ) ;
if ( ! ( V_62 & V_65 ) )
return true ;
if ( ! V_118 || ( ( V_118 -> type ==
V_127 ) &&
( V_118 -> V_42 -> V_96 <= V_42 -> V_96 ) ) )
return false ;
return true ;
}
static struct V_120 *
F_131 ( struct V_41 * V_42 ,
struct V_32 * V_33 ,
struct V_79 * V_80 ,
struct V_117 * V_118 ,
int V_154 )
{
struct V_49 * V_190 ;
struct V_120 * V_48 = F_59 ( - V_171 ) ;
struct V_191 * V_192 , * V_4 ;
struct V_193 {
struct V_106 V_4 ;
struct V_49 * V_190 ;
} V_193 , * V_109 ;
F_132 ( V_194 ) ;
F_133 () ;
V_4 = F_134 ( & V_42 -> V_45 , V_33 , V_78 ) ;
F_135 (g, tmp, list, hash) {
struct V_193 * V_195 ;
if ( F_136 ( F_87 ( & V_194 ) ) ) {
V_193 . V_190 = V_190 ;
F_111 ( & V_193 . V_4 , & V_194 ) ;
continue;
}
V_195 = F_137 ( sizeof( * V_195 ) , V_196 ) ;
if ( ! V_195 ) {
F_138 () ;
V_48 = F_59 ( - V_82 ) ;
goto V_197;
}
V_195 -> V_190 = V_190 ;
F_111 ( & V_195 -> V_4 , & V_194 ) ;
}
F_138 () ;
F_84 (iter, &match_head, list) {
struct V_51 * V_52 ;
V_190 = V_109 -> V_190 ;
F_9 ( & V_190 -> V_2 , V_198 ) ;
V_52 = F_139 ( & V_190 -> V_71 , V_33 -> V_36 ,
V_73 ) ;
if ( V_52 ) {
V_48 = F_124 ( V_190 , V_33 -> V_36 ,
V_80 , V_118 , V_154 , V_52 ) ;
F_13 ( & V_190 -> V_2 ) ;
goto V_197;
}
F_13 ( & V_190 -> V_2 ) ;
}
F_84 (iter, &match_head, list) {
V_190 = V_109 -> V_190 ;
F_9 ( & V_190 -> V_2 , V_198 ) ;
V_48 = F_124 ( V_190 , V_33 -> V_36 ,
V_80 , V_118 , V_154 , NULL ) ;
if ( ! F_93 ( V_48 ) || F_94 ( V_48 ) != - V_138 ) {
F_13 ( & V_190 -> V_2 ) ;
goto V_197;
}
F_13 ( & V_190 -> V_2 ) ;
}
V_197:
if ( ! F_87 ( & V_194 ) ) {
struct V_193 * V_199 ;
F_43 ( & F_140 ( & V_194 , F_141 ( * V_109 ) , V_4 ) -> V_4 ) ;
F_142 (iter, match_tmp, &match_head, list) {
F_43 ( & V_109 -> V_4 ) ;
F_19 ( V_109 ) ;
}
}
return V_48 ;
}
static struct V_120 *
F_143 ( struct V_41 * V_42 ,
struct V_32 * V_33 ,
struct V_79 * V_80 ,
struct V_117 * V_118 ,
int V_154 )
{
struct V_49 * V_190 ;
struct V_120 * V_48 ;
int V_34 ;
if ( ! F_29 ( V_33 ) )
return F_59 ( - V_119 ) ;
for ( V_34 = 0 ; V_34 < V_154 ; V_34 ++ ) {
if ( ! F_130 ( & V_118 [ V_34 ] , V_80 -> V_62 , V_42 ) )
return F_59 ( - V_119 ) ;
}
F_9 ( & V_42 -> V_2 , V_200 ) ;
V_48 = F_131 ( V_42 , V_33 , V_80 , V_118 , V_154 ) ;
if ( ! F_93 ( V_48 ) )
goto V_201;
V_190 = F_117 ( V_42 , V_33 -> V_22 ,
V_33 -> V_18 ) ;
if ( F_93 ( V_190 ) ) {
V_48 = ( void * ) V_190 ;
goto V_201;
}
V_48 = F_124 ( V_190 , V_33 -> V_36 , V_80 , V_118 ,
V_154 , NULL ) ;
if ( F_93 ( V_48 ) ) {
F_13 ( & V_42 -> V_2 ) ;
F_8 ( & V_190 -> V_2 ) ;
F_20 ( & V_190 -> V_2 ) ;
return V_48 ;
}
V_201:
F_13 ( & V_42 -> V_2 ) ;
return V_48 ;
}
static bool F_144 ( struct V_41 * V_42 )
{
return ( ( V_42 -> type == V_202 ) &&
( F_88 ( F_34 ( & V_42 -> V_2 ) , V_203 ) ) ) ;
}
struct V_120 *
F_145 ( struct V_41 * V_42 ,
struct V_32 * V_33 ,
struct V_79 * V_80 ,
struct V_117 * V_118 ,
int V_154 )
{
struct V_37 * V_8 = F_31 ( & V_42 -> V_2 ) ;
struct V_117 V_204 ;
struct V_41 * V_58 = NULL ;
struct V_120 * V_121 = NULL ;
T_1 V_55 = V_80 -> V_62 ;
struct V_13 * V_16 ;
F_36 ( V_16 , V_42 -> V_2 . V_7 ) ;
if ( V_80 -> V_62 == V_56 ) {
if ( ! F_144 ( V_42 ) )
return F_59 ( - V_205 ) ;
if ( V_118 )
return F_59 ( - V_119 ) ;
F_12 ( & V_8 -> V_135 ) ;
V_58 = F_71 ( V_16 ) ;
if ( V_58 ) {
V_204 . type = V_127 ;
V_204 . V_42 = V_58 ;
V_118 = & V_204 ;
V_154 = 1 ;
V_80 -> V_62 = V_65 ;
} else {
F_15 ( & V_8 -> V_135 ) ;
return F_59 ( - V_205 ) ;
}
}
V_121 = F_143 ( V_42 , V_33 , V_80 , V_118 , V_154 ) ;
if ( V_55 == V_56 ) {
if ( ! F_146 ( V_121 ) &&
( F_87 ( & V_121 -> V_48 [ 0 ] -> V_58 ) ) ) {
F_12 ( & V_58 -> V_6 ) ;
F_90 ( & V_121 -> V_48 [ 0 ] -> V_58 ,
& V_58 -> V_105 ) ;
F_15 ( & V_58 -> V_6 ) ;
V_121 -> V_48 [ 0 ] -> V_55 = V_56 ;
}
F_15 ( & V_8 -> V_135 ) ;
}
return V_121 ;
}
void F_147 ( struct V_120 * V_121 )
{
int V_34 ;
for ( V_34 = V_121 -> V_124 - 1 ; V_34 >= 0 ; V_34 -- )
F_20 ( & V_121 -> V_48 [ V_34 ] -> V_2 ) ;
F_19 ( V_121 ) ;
}
static struct V_41 * F_148 ( struct V_41 * V_42 )
{
struct V_13 * V_16 ;
F_36 ( V_16 , V_42 -> V_2 . V_7 ) ;
if ( ! F_149 ( & V_42 -> V_2 . V_4 , & V_16 -> V_2 . V_5 ) )
return F_150 ( V_42 , V_2 . V_4 ) ;
return F_71 ( V_16 ) ;
}
static int F_151 ( struct V_41 * V_42 )
{
struct V_37 * V_8 = F_31 ( & V_42 -> V_2 ) ;
struct V_41 * V_206 = NULL ;
if ( V_8 -> V_115 != V_42 )
return 0 ;
V_206 = F_148 ( V_42 ) ;
if ( V_206 ) {
int V_43 = F_78 ( V_8 -> V_40 , V_206 ,
V_8 -> V_116 ) ;
if ( V_43 ) {
F_38 ( V_8 -> V_40 , L_9 ,
V_42 -> V_67 ) ;
return V_43 ;
}
}
V_8 -> V_115 = V_206 ;
return 0 ;
}
static int F_152 ( struct V_41 * V_42 )
{
struct V_39 * V_40 = F_34 ( & V_42 -> V_2 ) ;
struct V_41 * V_58 ;
struct V_13 * V_16 ;
int V_43 = 0 ;
V_43 = F_151 ( V_42 ) ;
if ( V_43 )
return V_43 ;
F_36 ( V_16 , V_42 -> V_2 . V_7 ) ;
if ( ! ( F_140 ( & V_16 -> V_2 . V_5 ,
struct V_41 ,
V_2 . V_4 ) == V_42 ) )
return 0 ;
V_58 = F_71 ( V_16 ) ;
V_43 = F_82 ( V_40 , V_58 , V_42 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_76 ( V_40 , V_58 , V_16 ) ;
if ( V_43 )
F_38 ( V_40 , L_14 ,
V_42 -> V_67 ) ;
return V_43 ;
}
int F_153 ( struct V_41 * V_42 )
{
struct V_37 * V_8 = F_31 ( & V_42 -> V_2 ) ;
int V_43 = 0 ;
F_12 ( & V_8 -> V_135 ) ;
V_43 = F_152 ( V_42 ) ;
if ( V_43 ) {
F_15 ( & V_8 -> V_135 ) ;
return V_43 ;
}
if ( F_20 ( & V_42 -> V_2 ) )
F_38 ( F_34 ( & V_42 -> V_2 ) , L_15 ,
V_42 -> V_67 ) ;
F_15 ( & V_8 -> V_135 ) ;
return V_43 ;
}
void F_154 ( struct V_49 * V_50 )
{
if ( F_20 ( & V_50 -> V_2 ) )
F_38 ( F_34 ( & V_50 -> V_2 ) , L_16 ,
V_50 -> V_67 ) ;
}
struct V_14 * F_155 ( struct V_39 * V_40 ,
enum V_207 type )
{
struct V_208 * V_209 = V_40 -> V_210 . V_209 ;
struct V_37 * V_211 ;
int V_16 ;
struct V_13 * V_13 ;
struct V_14 * V_15 ;
if ( ! V_209 )
return NULL ;
switch ( type ) {
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
V_16 = type ;
break;
case V_219 :
if ( V_209 -> V_220 )
return & V_209 -> V_220 -> V_15 ;
else
return NULL ;
case V_221 :
if ( V_209 -> V_222 )
return & V_209 -> V_222 -> V_15 ;
else
return NULL ;
case V_223 :
if ( V_209 -> V_224 )
return & V_209 -> V_224 -> V_15 ;
else
return NULL ;
case V_225 :
if ( V_209 -> V_226 )
return & V_209 -> V_226 -> V_15 ;
else
return NULL ;
case V_227 :
if ( V_209 -> V_228 )
return & V_209 -> V_228 -> V_15 ;
else
return NULL ;
default:
return NULL ;
}
V_211 = V_209 -> V_211 ;
if ( ! V_211 )
return NULL ;
V_13 = F_22 ( & V_211 -> V_15 , V_16 ) ;
if ( ! V_13 )
return NULL ;
V_15 = F_140 ( & V_13 -> V_2 . V_5 ,
F_141 ( * V_15 ) ,
V_2 . V_4 ) ;
return V_15 ;
}
static struct V_13 * F_156 ( struct V_14 * V_15 ,
unsigned int V_16 , int V_137 )
{
struct V_13 * V_13 ;
V_13 = F_58 ( sizeof( * V_13 ) , V_81 ) ;
if ( ! V_13 )
return F_59 ( - V_82 ) ;
V_13 -> V_2 . type = V_229 ;
F_1 ( & V_13 -> V_2 , 1 , NULL ) ;
F_6 ( & V_13 -> V_2 , & V_15 -> V_2 ) ;
V_13 -> V_137 = V_137 ;
V_13 -> V_16 = V_16 ;
F_111 ( & V_13 -> V_2 . V_4 , & V_15 -> V_2 . V_5 ) ;
return V_13 ;
}
static struct V_14 * F_157 ( struct V_14
* V_15 )
{
V_15 -> V_2 . type = V_38 ;
return V_15 ;
}
static struct V_14 * F_158 ( struct V_13 * V_16 )
{
struct V_14 * V_15 ;
V_15 = F_58 ( sizeof( * V_15 ) , V_81 ) ;
if ( ! V_15 )
return F_59 ( - V_82 ) ;
F_157 ( V_15 ) ;
F_1 ( & V_15 -> V_2 , 1 , NULL ) ;
F_6 ( & V_15 -> V_2 , & V_16 -> V_2 ) ;
F_111 ( & V_15 -> V_2 . V_4 , & V_16 -> V_2 . V_5 ) ;
return V_15 ;
}
static int F_159 ( struct V_14 * V_15 , int V_16 ,
struct V_230 * V_231 )
{
struct V_13 * V_13 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_231 -> V_232 ; V_34 ++ ) {
V_13 = F_156 ( V_15 , V_16 ++ , V_231 -> V_137 ) ;
if ( F_93 ( V_13 ) )
return F_94 ( V_13 ) ;
}
return 0 ;
}
static bool F_160 ( struct V_39 * V_40 , struct V_233 * V_234 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_234 -> V_235 ; V_34 ++ ) {
if ( ! F_161 ( V_40 , V_234 -> V_234 [ V_34 ] ) )
return false ;
}
return true ;
}
static int F_162 ( struct V_208 * V_209 ,
struct V_230 * V_236 ,
struct V_1 * V_237 ,
struct V_230 * V_238 ,
int V_16 )
{
int V_239 = F_88 ( V_209 -> V_40 ,
V_128 .
V_239 ) ;
struct V_14 * V_240 ;
struct V_13 * V_13 ;
struct V_1 * V_241 ;
int V_34 ;
int V_43 ;
if ( V_236 -> type == V_229 ) {
if ( ( V_236 -> V_242 > V_239 ) ||
! F_160 ( V_209 -> V_40 , & V_236 -> V_234 ) )
return 0 ;
F_36 ( V_240 , V_237 ) ;
if ( V_236 -> V_232 )
return F_159 ( V_240 , V_16 , V_236 ) ;
V_13 = F_156 ( V_240 , V_16 , V_236 -> V_137 ) ;
if ( F_93 ( V_13 ) )
return F_94 ( V_13 ) ;
V_241 = & V_13 -> V_2 ;
} else if ( V_236 -> type == V_38 ) {
F_36 ( V_13 , V_237 ) ;
V_240 = F_158 ( V_13 ) ;
if ( F_93 ( V_240 ) )
return F_94 ( V_240 ) ;
V_241 = & V_240 -> V_2 ;
} else {
return - V_119 ;
}
V_16 = 0 ;
for ( V_34 = 0 ; V_34 < V_236 -> V_243 ; V_34 ++ ) {
V_43 = F_162 ( V_209 , & V_236 -> V_5 [ V_34 ] ,
V_241 , V_236 , V_16 ) ;
if ( V_43 )
return V_43 ;
if ( V_236 -> V_5 [ V_34 ] . type == V_229 &&
V_236 -> V_5 [ V_34 ] . V_232 ) {
V_16 += V_236 -> V_5 [ V_34 ] . V_232 ;
}
}
return 0 ;
}
static int F_163 ( struct V_208 * V_209 ,
struct V_230 * V_236 ,
struct V_1 * V_237 )
{
int V_34 ;
struct V_14 * V_240 ;
int V_43 ;
F_36 ( V_240 , V_237 ) ;
for ( V_34 = 0 ; V_34 < V_236 -> V_243 ; V_34 ++ ) {
V_43 = F_162 ( V_209 , & V_236 -> V_5 [ V_34 ] ,
& V_240 -> V_2 ,
V_236 , V_34 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
static struct V_37 * F_164 ( struct V_208 * V_209 ,
enum V_99
V_100 )
{
struct V_37 * V_211 ;
struct V_14 * V_15 ;
V_211 = F_118 ( sizeof( * V_211 ) , V_81 ) ;
if ( ! V_211 )
return NULL ;
V_211 -> V_40 = V_209 -> V_40 ;
V_211 -> V_100 = V_100 ;
V_15 = & V_211 -> V_15 ;
F_157 ( V_15 ) ;
F_5 ( & V_211 -> V_135 ) ;
F_1 ( & V_15 -> V_2 , 1 , NULL ) ;
F_6 ( & V_15 -> V_2 , NULL ) ;
return V_211 ;
}
static int F_165 ( struct V_14 * V_15 , int V_244 )
{
struct V_13 * V_16 ;
F_23 (prio, ns) {
F_166 ( V_16 , V_244 ) ;
V_244 += V_16 -> V_137 ;
}
return V_244 ;
}
static void F_166 ( struct V_13 * V_16 , int V_244 )
{
struct V_14 * V_15 ;
int V_245 = V_244 ;
V_16 -> V_139 = V_244 ;
F_167 (ns, prio)
V_245 = F_165 ( V_15 , V_244 ) ;
if ( ! V_16 -> V_137 )
V_16 -> V_137 = V_245 - V_16 -> V_139 ;
F_32 ( V_16 -> V_137 < V_245 - V_16 -> V_139 ) ;
}
static void F_168 ( struct V_37 * V_211 )
{
struct V_14 * V_15 = & V_211 -> V_15 ;
struct V_13 * V_16 ;
int V_139 = 0 ;
F_23 (prio, ns) {
F_166 ( V_16 , V_139 ) ;
V_139 += V_16 -> V_137 ;
}
}
static int F_169 ( struct V_208 * V_209 )
{
struct V_14 * V_15 = NULL ;
struct V_131 V_132 = {} ;
struct V_41 * V_42 ;
V_15 = F_155 ( V_209 -> V_40 , V_218 ) ;
if ( F_32 ( ! V_15 ) )
return - V_119 ;
V_132 . V_98 = V_246 ;
V_132 . V_96 = V_247 ;
V_132 . V_16 = V_248 ;
V_42 = F_97 ( V_15 , & V_132 ) ;
if ( F_93 ( V_42 ) ) {
F_170 ( V_209 -> V_40 , L_17 ) ;
return F_94 ( V_42 ) ;
}
return 0 ;
}
static int F_171 ( struct V_208 * V_209 )
{
V_209 -> V_211 = F_164 ( V_209 , V_202 ) ;
if ( ! V_209 -> V_211 )
goto V_249;
if ( F_163 ( V_209 , & V_250 , & V_209 -> V_211 -> V_15 . V_2 ) )
goto V_249;
F_168 ( V_209 -> V_211 ) ;
if ( F_169 ( V_209 ) )
goto V_249;
return 0 ;
V_249:
F_172 ( V_209 -> V_40 ) ;
return - V_82 ;
}
static void F_173 ( struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_1 * V_109 ;
struct V_1 * V_251 ;
F_142 (iter, temp, &node->children, list)
F_173 ( V_109 ) ;
F_20 ( V_2 ) ;
}
}
static void F_174 ( struct V_37 * V_211 )
{
if ( ! V_211 )
return;
F_173 ( & V_211 -> V_15 . V_2 ) ;
}
void F_172 ( struct V_39 * V_40 )
{
struct V_208 * V_209 = V_40 -> V_210 . V_209 ;
F_174 ( V_209 -> V_211 ) ;
F_174 ( V_209 -> V_222 ) ;
F_174 ( V_209 -> V_224 ) ;
F_174 ( V_209 -> V_220 ) ;
F_174 ( V_209 -> V_226 ) ;
F_174 ( V_209 -> V_228 ) ;
F_175 ( V_40 ) ;
F_19 ( V_209 ) ;
}
static int F_176 ( struct V_208 * V_209 )
{
struct V_13 * V_16 ;
V_209 -> V_228 = F_164 ( V_209 , V_252 ) ;
if ( ! V_209 -> V_228 )
return - V_82 ;
V_16 = F_156 ( & V_209 -> V_228 -> V_15 , 0 , 1 ) ;
if ( F_93 ( V_16 ) ) {
F_174 ( V_209 -> V_228 ) ;
return F_94 ( V_16 ) ;
}
return 0 ;
}
static int F_177 ( struct V_208 * V_209 )
{
struct V_13 * V_16 ;
V_209 -> V_226 = F_164 ( V_209 , V_253 ) ;
if ( ! V_209 -> V_226 )
return - V_82 ;
V_16 = F_156 ( & V_209 -> V_226 -> V_15 , 0 , 1 ) ;
if ( F_93 ( V_16 ) ) {
F_174 ( V_209 -> V_226 ) ;
return F_94 ( V_16 ) ;
}
return 0 ;
}
static int F_178 ( struct V_208 * V_209 )
{
struct V_13 * V_16 ;
V_209 -> V_220 = F_164 ( V_209 , V_254 ) ;
if ( ! V_209 -> V_220 )
return - V_82 ;
V_16 = F_156 ( & V_209 -> V_220 -> V_15 , 0 , 1 ) ;
if ( F_93 ( V_16 ) )
goto V_255;
V_16 = F_156 ( & V_209 -> V_220 -> V_15 , 1 , 1 ) ;
if ( F_93 ( V_16 ) )
goto V_255;
F_168 ( V_209 -> V_220 ) ;
return 0 ;
V_255:
F_174 ( V_209 -> V_220 ) ;
V_209 -> V_220 = NULL ;
return F_94 ( V_16 ) ;
}
static int F_179 ( struct V_208 * V_209 )
{
struct V_13 * V_16 ;
V_209 -> V_222 = F_164 ( V_209 , V_256 ) ;
if ( ! V_209 -> V_222 )
return - V_82 ;
V_16 = F_156 ( & V_209 -> V_222 -> V_15 , 0 ,
F_180 ( V_209 -> V_40 ) ) ;
return F_181 ( V_16 ) ;
}
static int F_182 ( struct V_208 * V_209 )
{
struct V_13 * V_16 ;
V_209 -> V_224 = F_164 ( V_209 , V_257 ) ;
if ( ! V_209 -> V_224 )
return - V_82 ;
V_16 = F_156 ( & V_209 -> V_224 -> V_15 , 0 ,
F_180 ( V_209 -> V_40 ) ) ;
return F_181 ( V_16 ) ;
}
int F_183 ( struct V_39 * V_40 )
{
struct V_208 * V_209 ;
int V_43 = 0 ;
V_43 = F_184 ( V_40 ) ;
if ( V_43 )
return V_43 ;
V_209 = F_58 ( sizeof( * V_209 ) , V_81 ) ;
if ( ! V_209 )
return - V_82 ;
V_209 -> V_40 = V_40 ;
V_40 -> V_210 . V_209 = V_209 ;
if ( ( ( ( F_185 ( V_40 , V_258 ) == V_259 ) &&
( F_185 ( V_40 , V_260 ) ) ) ||
( ( F_185 ( V_40 , V_258 ) == V_261 ) &&
F_185 ( V_40 , V_262 ) ) ) &&
F_186 ( V_40 , V_263 ) ) {
V_43 = F_171 ( V_209 ) ;
if ( V_43 )
goto V_43;
}
if ( F_185 ( V_40 , V_264 ) ) {
if ( F_187 ( V_40 , V_263 ) ) {
V_43 = F_178 ( V_209 ) ;
if ( V_43 )
goto V_43;
}
if ( F_188 ( V_40 , V_263 ) ) {
V_43 = F_182 ( V_209 ) ;
if ( V_43 )
goto V_43;
}
if ( F_189 ( V_40 , V_263 ) ) {
V_43 = F_179 ( V_209 ) ;
if ( V_43 )
goto V_43;
}
}
if ( F_190 ( V_40 , V_263 ) ) {
V_43 = F_177 ( V_209 ) ;
if ( V_43 )
goto V_43;
}
if ( F_191 ( V_40 , V_263 ) ) {
V_43 = F_176 ( V_209 ) ;
if ( V_43 )
goto V_43;
}
return 0 ;
V_43:
F_172 ( V_40 ) ;
return V_43 ;
}
int F_192 ( struct V_39 * V_40 , T_1 V_116 )
{
struct V_37 * V_8 = V_40 -> V_210 . V_209 -> V_211 ;
V_8 -> V_116 = V_116 ;
return 0 ;
}
int F_193 ( struct V_39 * V_40 , T_1 V_116 )
{
struct V_37 * V_8 = V_40 -> V_210 . V_209 -> V_211 ;
V_8 -> V_116 = 0 ;
return 0 ;
}
