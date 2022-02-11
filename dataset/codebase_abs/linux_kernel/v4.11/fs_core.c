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
static bool F_24 ( void * V_18 , void * V_19 , void * V_20 , T_1 V_21 )
{
unsigned int V_22 ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ , V_18 ++ , V_19 ++ , V_20 ++ )
if ( ( * ( ( V_23 * ) V_19 ) & ( * ( V_23 * ) V_18 ) ) !=
( ( * ( V_23 * ) V_20 ) & ( * ( V_23 * ) V_18 ) ) )
return false ;
return true ;
}
static bool F_25 ( struct V_24 * V_18 ,
void * V_25 , void * V_26 )
{
if ( V_18 -> V_27 &
1 << V_28 ) {
void * V_29 = F_26 ( V_30 ,
V_25 , V_31 ) ;
void * V_32 = F_26 ( V_30 ,
V_26 , V_31 ) ;
void * V_33 = F_26 ( V_30 ,
V_18 -> V_34 , V_31 ) ;
if ( ! F_24 ( V_33 , V_29 , V_32 ,
F_27 ( V_35 ) ) )
return false ;
}
if ( V_18 -> V_27 &
1 << V_36 ) {
void * V_29 = F_26 ( V_30 ,
V_25 , V_37 ) ;
void * V_32 = F_26 ( V_30 ,
V_26 , V_37 ) ;
void * V_33 = F_26 ( V_30 ,
V_18 -> V_34 , V_37 ) ;
if ( ! F_24 ( V_33 , V_29 , V_32 ,
F_27 ( V_38 ) ) )
return false ;
}
if ( V_18 -> V_27 &
1 << V_39 ) {
void * V_29 = F_26 ( V_30 ,
V_25 , V_40 ) ;
void * V_32 = F_26 ( V_30 ,
V_26 , V_40 ) ;
void * V_33 = F_26 ( V_30 ,
V_18 -> V_34 , V_40 ) ;
if ( ! F_24 ( V_33 , V_29 , V_32 ,
F_27 ( V_35 ) ) )
return false ;
}
return true ;
}
static bool F_28 ( V_23 V_41 ,
V_23 V_42 ,
void * V_43 , void * V_44 )
{
return V_41 == V_42 &&
! memcmp ( V_43 , V_44 , F_27 ( V_30 ) ) ;
}
static struct V_45 * F_29 ( struct V_1 * V_2 )
{
struct V_1 * V_8 ;
struct V_14 * V_15 ;
V_8 = V_2 -> V_8 ;
if ( F_30 ( V_8 -> type != V_46 ) ) {
F_31 ( L_1 ) ;
return NULL ;
}
V_15 = F_32 ( V_8 , struct V_14 , V_2 ) ;
return F_32 ( V_15 , struct V_45 , V_15 ) ;
}
static inline struct V_47 * F_33 ( struct V_1 * V_2 )
{
struct V_45 * V_8 = F_29 ( V_2 ) ;
if ( V_8 )
return V_8 -> V_48 ;
return NULL ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
struct V_47 * V_48 ;
struct V_13 * V_16 ;
int V_51 ;
F_35 ( V_50 , V_2 ) ;
V_48 = F_33 ( & V_50 -> V_2 ) ;
V_51 = F_36 ( V_48 , V_50 ) ;
if ( V_51 )
F_37 ( V_48 , L_2 ) ;
F_35 ( V_16 , V_50 -> V_2 . V_7 ) ;
V_16 -> V_52 -- ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_53 * V_54 ;
struct V_49 * V_50 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
T_2 * V_59 ;
int V_60 ;
struct V_47 * V_48 = F_33 ( V_2 ) ;
int V_61 = F_27 ( V_30 ) ;
int V_51 ;
bool V_62 = false ;
V_59 = F_39 ( V_61 ) ;
if ( ! V_59 ) {
F_37 ( V_48 , L_3 ) ;
return;
}
F_35 ( V_54 , V_2 ) ;
F_35 ( V_58 , V_54 -> V_2 . V_7 ) ;
F_35 ( V_56 , V_58 -> V_2 . V_7 ) ;
memcpy ( V_59 , V_58 -> V_63 , sizeof( V_58 -> V_63 ) ) ;
F_35 ( V_50 , V_56 -> V_2 . V_7 ) ;
F_40 ( & V_54 -> V_2 . V_4 ) ;
if ( V_54 -> V_64 == V_65 ) {
F_12 ( & V_54 -> V_66 . V_50 -> V_6 ) ;
F_40 ( & V_54 -> V_67 ) ;
F_15 ( & V_54 -> V_66 . V_50 -> V_6 ) ;
}
if ( V_54 -> V_66 . type == V_68 &&
-- V_58 -> V_69 ) {
V_60 = F_41 ( V_70 ) ;
V_58 -> V_71 &= ~ V_72 ;
V_62 = true ;
goto V_73;
}
if ( ( V_58 -> V_71 & V_74 ) &&
-- V_58 -> V_69 ) {
V_60 = F_41 ( V_75 ) ,
V_62 = true ;
}
V_73:
if ( V_62 && V_58 -> V_69 ) {
V_51 = F_42 ( V_48 , V_50 , V_56 -> V_76 , V_60 , V_58 ) ;
if ( V_51 )
F_37 ( V_48 ,
L_4 ,
V_77 , V_56 -> V_76 , V_58 -> V_78 ) ;
}
F_43 ( V_59 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
struct V_55 * V_56 ;
struct V_47 * V_48 ;
struct V_57 * V_58 ;
int V_51 ;
F_35 ( V_58 , V_2 ) ;
F_35 ( V_56 , V_58 -> V_2 . V_7 ) ;
F_35 ( V_50 , V_56 -> V_2 . V_7 ) ;
V_48 = F_33 ( & V_50 -> V_2 ) ;
V_51 = F_45 ( V_48 , V_50 ,
V_58 -> V_78 ) ;
if ( V_51 )
F_37 ( V_48 ,
L_5 ,
V_58 -> V_78 , V_56 -> V_76 ) ;
V_58 -> V_79 = 0 ;
V_56 -> V_80 -- ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
struct V_49 * V_50 ;
struct V_47 * V_48 ;
F_35 ( V_56 , V_2 ) ;
F_35 ( V_50 , V_56 -> V_2 . V_7 ) ;
V_48 = F_33 ( & V_50 -> V_2 ) ;
if ( V_50 -> V_81 . V_82 )
V_50 -> V_81 . V_83 -- ;
if ( F_47 ( V_48 , V_50 , V_56 -> V_76 ) )
F_37 ( V_48 , L_6 ,
V_56 -> V_76 , V_50 -> V_76 ) ;
}
static struct V_57 * F_48 ( struct V_84 * V_85 ,
T_2 * V_59 ,
unsigned int V_78 )
{
struct V_57 * V_58 ;
V_58 = F_49 ( sizeof( * V_58 ) , V_86 ) ;
if ( ! V_58 )
return F_50 ( - V_87 ) ;
memcpy ( V_58 -> V_63 , V_59 , sizeof( V_58 -> V_63 ) ) ;
V_58 -> V_2 . type = V_88 ;
V_58 -> V_89 = V_85 -> V_89 ;
V_58 -> V_78 = V_78 ;
V_58 -> V_71 = V_85 -> V_71 ;
V_58 -> V_90 = V_85 -> V_90 ;
return V_58 ;
}
static struct V_55 * F_51 ( T_2 * V_91 )
{
struct V_55 * V_56 ;
void * V_34 = F_26 ( V_92 ,
V_91 , V_34 ) ;
V_23 V_27 = F_52 ( V_92 ,
V_91 ,
V_27 ) ;
V_56 = F_49 ( sizeof( * V_56 ) , V_86 ) ;
if ( ! V_56 )
return F_50 ( - V_87 ) ;
V_56 -> V_18 . V_27 = V_27 ;
memcpy ( & V_56 -> V_18 . V_34 , V_34 ,
sizeof( V_56 -> V_18 . V_34 ) ) ;
V_56 -> V_2 . type = V_93 ;
V_56 -> V_94 = F_52 ( V_92 , V_91 ,
V_95 ) ;
V_56 -> V_96 = F_52 ( V_92 , V_91 ,
V_97 ) - V_56 -> V_94 + 1 ;
return V_56 ;
}
static struct V_49 * F_53 ( int V_98 , T_3 V_99 , int V_100 ,
enum V_101 V_102 ,
enum V_103 V_104 ,
T_2 V_105 )
{
struct V_49 * V_50 ;
V_50 = F_49 ( sizeof( * V_50 ) , V_86 ) ;
if ( ! V_50 )
return NULL ;
V_50 -> V_98 = V_98 ;
V_50 -> V_2 . type = V_106 ;
V_50 -> V_104 = V_104 ;
V_50 -> type = V_102 ;
V_50 -> V_99 = V_99 ;
V_50 -> V_100 = V_100 ;
V_50 -> V_105 = V_105 ;
F_4 ( & V_50 -> V_107 ) ;
F_5 ( & V_50 -> V_6 ) ;
return V_50 ;
}
static struct V_49 * F_54 ( struct V_1 * V_8 ,
struct V_108 * V_109 ,
bool V_110 )
{
#define F_55 ( T_4 , V_110 ) \
((reverse) ? list_prev_entry(pos, list) : list_next_entry(pos, list))
#define F_56 ( T_4 , T_5 , V_110 ) \
for (pos = list_advance_entry(pos, reverse); \
&pos->list != (head); \
pos = list_advance_entry(pos, reverse))
struct V_1 * V_111 = F_57 ( V_109 , struct V_1 , V_4 ) ;
struct V_49 * V_50 = NULL ;
if ( ! V_8 )
return NULL ;
F_56 (iter, &root->children, reverse) {
if ( V_111 -> type == V_106 ) {
F_35 ( V_50 , V_111 ) ;
return V_50 ;
}
V_50 = F_54 ( V_111 , & V_111 -> V_5 , V_110 ) ;
if ( V_50 )
return V_50 ;
}
return V_50 ;
}
static struct V_49 * F_58 ( struct V_13 * V_16 , bool V_110 )
{
struct V_49 * V_50 = NULL ;
struct V_1 * V_112 ;
struct V_1 * V_7 ;
V_7 = V_16 -> V_2 . V_7 ;
V_112 = & V_16 -> V_2 ;
while ( ! V_50 && V_7 ) {
V_50 = F_54 ( V_7 , & V_112 -> V_4 , V_110 ) ;
V_112 = V_7 ;
V_7 = V_112 -> V_7 ;
}
return V_50 ;
}
static struct V_49 * F_59 ( struct V_13 * V_16 )
{
return F_58 ( V_16 , false ) ;
}
static struct V_49 * F_60 ( struct V_13 * V_16 )
{
return F_58 ( V_16 , true ) ;
}
static int F_61 ( struct V_47 * V_48 ,
struct V_13 * V_16 ,
struct V_49 * V_50 )
{
struct V_49 * V_111 ;
int V_22 = 0 ;
int V_51 ;
F_62 (iter, prio) {
V_22 ++ ;
V_51 = F_63 ( V_48 ,
V_111 ,
V_50 ) ;
if ( V_51 ) {
F_37 ( V_48 , L_7 ,
V_111 -> V_76 ) ;
if ( V_22 > 1 )
F_30 ( true ) ;
return V_51 ;
}
}
return 0 ;
}
static int F_64 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_13 * V_16 )
{
struct V_49 * V_113 ;
V_113 = F_60 ( V_16 ) ;
if ( V_113 ) {
struct V_13 * V_114 ;
F_35 ( V_114 , V_113 -> V_2 . V_7 ) ;
return F_61 ( V_48 , V_114 , V_50 ) ;
}
return 0 ;
}
static int F_65 ( struct V_49 * V_50 , struct V_13
* V_16 )
{
struct V_45 * V_8 = F_29 ( & V_16 -> V_2 ) ;
int V_115 = V_116 ;
int V_51 ;
if ( V_8 -> V_117 )
V_115 = V_8 -> V_117 -> V_98 ;
if ( V_50 -> V_98 >= V_115 )
return 0 ;
V_51 = F_66 ( V_8 -> V_48 , V_50 ) ;
if ( V_51 )
F_37 ( V_8 -> V_48 , L_8 ,
V_50 -> V_76 ) ;
else
V_8 -> V_117 = V_50 ;
return V_51 ;
}
static int F_67 ( struct V_53 * V_54 ,
struct V_118 * V_119 )
{
struct V_49 * V_50 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_60 = F_41 ( V_75 ) ;
int V_51 = 0 ;
F_35 ( V_58 , V_54 -> V_2 . V_7 ) ;
if ( ! ( V_58 -> V_71 & V_74 ) )
return - V_120 ;
F_11 ( & V_58 -> V_2 ) ;
F_35 ( V_56 , V_58 -> V_2 . V_7 ) ;
F_35 ( V_50 , V_56 -> V_2 . V_7 ) ;
memcpy ( & V_54 -> V_66 , V_119 , sizeof( * V_119 ) ) ;
V_51 = F_42 ( F_33 ( & V_50 -> V_2 ) ,
V_50 , V_56 -> V_76 ,
V_60 ,
V_58 ) ;
F_13 ( & V_58 -> V_2 ) ;
return V_51 ;
}
int F_68 ( struct V_121 * V_122 ,
struct V_118 * V_123 ,
struct V_118 * V_124 )
{
int V_22 ;
if ( ! V_124 ) {
if ( V_122 -> V_125 != 1 )
return - V_120 ;
return F_67 ( V_122 -> V_54 [ 0 ] ,
V_123 ) ;
}
for ( V_22 = 0 ; V_22 < V_122 -> V_125 ; V_22 ++ ) {
if ( F_69 ( V_123 , & V_122 -> V_54 [ V_22 ] -> V_66 ) )
return F_67 ( V_122 -> V_54 [ V_22 ] ,
V_123 ) ;
}
return - V_120 ;
}
static int F_70 ( struct V_47 * V_48 ,
struct V_49 * V_126 ,
struct V_49 * V_127 )
{
struct V_118 V_119 ;
struct V_53 * V_111 ;
int V_51 = 0 ;
if ( ! V_126 || ! V_127 )
return 0 ;
V_119 . type = V_128 ;
V_119 . V_50 = V_126 ;
F_12 ( & V_127 -> V_6 ) ;
F_71 ( & V_127 -> V_107 , & V_126 -> V_107 ) ;
F_15 ( & V_127 -> V_6 ) ;
F_72 (iter, &new_next_ft->fwd_rules, next_ft) {
V_51 = F_67 ( V_111 , & V_119 ) ;
if ( V_51 )
F_73 ( L_9 ,
V_126 -> V_76 ) ;
}
return 0 ;
}
static int F_74 ( struct V_47 * V_48 , struct V_49 * V_50 ,
struct V_13 * V_16 )
{
struct V_49 * V_67 ;
int V_51 = 0 ;
if ( F_75 ( & V_16 -> V_2 . V_5 ) ) {
V_51 = F_64 ( V_48 , V_50 , V_16 ) ;
if ( V_51 )
return V_51 ;
V_67 = F_59 ( V_16 ) ;
V_51 = F_70 ( V_48 , V_50 , V_67 ) ;
if ( V_51 )
return V_51 ;
}
if ( F_76 ( V_48 ,
V_129 . V_130 ) )
V_51 = F_65 ( V_50 , V_16 ) ;
return V_51 ;
}
static void F_77 ( struct V_49 * V_50 ,
struct V_13 * V_16 )
{
struct V_108 * V_131 = & V_16 -> V_2 . V_5 ;
struct V_49 * V_111 ;
F_62 (iter, prio) {
if ( V_111 -> V_98 > V_50 -> V_98 )
break;
V_131 = & V_111 -> V_2 . V_4 ;
}
F_78 ( & V_50 -> V_2 . V_4 , V_131 ) ;
}
static struct V_49 * F_79 ( struct V_14 * V_15 ,
enum V_103 V_104 ,
T_3 V_99 , int V_16 ,
int V_100 , T_2 V_98 ,
T_2 V_105 )
{
struct V_49 * V_67 = NULL ;
struct V_49 * V_50 ;
int V_51 ;
int V_132 ;
struct V_45 * V_8 =
F_29 ( & V_15 -> V_2 ) ;
struct V_13 * V_13 = NULL ;
if ( ! V_8 ) {
F_73 ( L_10 ) ;
return F_50 ( - V_133 ) ;
}
F_12 ( & V_8 -> V_134 ) ;
V_13 = F_22 ( V_15 , V_16 ) ;
if ( ! V_13 ) {
V_51 = - V_120 ;
goto V_135;
}
if ( V_98 >= V_13 -> V_136 ) {
V_51 = - V_137 ;
goto V_135;
}
V_98 += V_13 -> V_138 ;
V_50 = F_53 ( V_98 ,
V_99 ,
V_100 ? F_80 ( V_100 ) : 0 ,
V_8 -> V_102 ,
V_104 , V_105 ) ;
if ( ! V_50 ) {
V_51 = - V_87 ;
goto V_135;
}
F_1 ( & V_50 -> V_2 , 1 , F_34 ) ;
V_132 = V_50 -> V_100 ? F_81 ( V_50 -> V_100 ) : 0 ;
V_67 = F_59 ( V_13 ) ;
V_51 = F_82 ( V_8 -> V_48 , V_50 -> V_99 , V_50 -> V_104 , V_50 -> type ,
V_50 -> V_98 , V_132 , V_67 , & V_50 -> V_76 ,
V_50 -> V_105 ) ;
if ( V_51 )
goto V_139;
V_51 = F_74 ( V_8 -> V_48 , V_50 , V_13 ) ;
if ( V_51 )
goto V_140;
F_11 ( & V_13 -> V_2 ) ;
F_6 ( & V_50 -> V_2 , & V_13 -> V_2 ) ;
F_77 ( V_50 , V_13 ) ;
V_13 -> V_52 ++ ;
F_13 ( & V_13 -> V_2 ) ;
F_15 ( & V_8 -> V_134 ) ;
return V_50 ;
V_140:
F_36 ( V_8 -> V_48 , V_50 ) ;
V_139:
F_19 ( V_50 ) ;
V_135:
F_15 ( & V_8 -> V_134 ) ;
return F_50 ( V_51 ) ;
}
struct V_49 * F_83 ( struct V_14 * V_15 ,
int V_16 , int V_100 ,
T_2 V_98 ,
T_2 V_105 )
{
return F_79 ( V_15 , V_141 , 0 , V_16 ,
V_100 , V_98 , V_105 ) ;
}
struct V_49 * F_84 ( struct V_14 * V_15 ,
int V_16 , int V_100 ,
T_2 V_98 , T_3 V_99 )
{
return F_79 ( V_15 , V_141 , V_99 , V_16 ,
V_100 , V_98 , 0 ) ;
}
struct V_49 * F_85 (
struct V_14 * V_15 ,
int V_16 , T_2 V_98 )
{
return F_79 ( V_15 , V_142 , 0 , V_16 , 0 ,
V_98 , 0 ) ;
}
struct V_49 * F_86 ( struct V_14 * V_15 ,
int V_16 ,
int V_143 ,
int V_144 ,
T_2 V_98 ,
T_2 V_105 )
{
struct V_49 * V_50 ;
if ( V_144 > V_143 )
return F_50 ( - V_120 ) ;
V_50 = F_83 ( V_15 , V_16 , V_143 , V_98 , V_105 ) ;
if ( F_87 ( V_50 ) )
return V_50 ;
V_50 -> V_81 . V_82 = true ;
V_50 -> V_81 . V_145 = V_144 ;
return V_50 ;
}
static struct V_55 * F_88 ( struct V_49 * V_50 ,
T_2 * V_146 ,
struct V_108
* V_147 ,
bool V_148 )
{
struct V_55 * V_56 ;
struct V_47 * V_48 = F_33 ( & V_50 -> V_2 ) ;
int V_51 ;
if ( ! V_48 )
return F_50 ( - V_133 ) ;
V_56 = F_51 ( V_146 ) ;
if ( F_87 ( V_56 ) )
return V_56 ;
V_51 = F_89 ( V_48 , V_50 , V_146 , & V_56 -> V_76 ) ;
if ( V_51 ) {
F_19 ( V_56 ) ;
return F_50 ( V_51 ) ;
}
if ( V_50 -> V_81 . V_82 )
V_50 -> V_81 . V_83 ++ ;
F_1 ( & V_56 -> V_2 , ! V_148 , F_46 ) ;
F_6 ( & V_56 -> V_2 , & V_50 -> V_2 ) ;
F_78 ( & V_56 -> V_2 . V_4 , V_147 ) ;
return V_56 ;
}
struct V_55 * F_90 ( struct V_49 * V_50 ,
T_2 * V_146 )
{
struct V_55 * V_56 ;
if ( V_50 -> V_81 . V_82 )
return F_50 ( - V_149 ) ;
F_11 ( & V_50 -> V_2 ) ;
V_56 = F_88 ( V_50 , V_146 , V_50 -> V_2 . V_5 . V_131 , false ) ;
F_13 ( & V_50 -> V_2 ) ;
return V_56 ;
}
static struct V_53 * F_91 ( struct V_118 * V_119 )
{
struct V_53 * V_54 ;
V_54 = F_49 ( sizeof( * V_54 ) , V_86 ) ;
if ( ! V_54 )
return NULL ;
F_4 ( & V_54 -> V_67 ) ;
V_54 -> V_2 . type = V_150 ;
if ( V_119 )
memcpy ( & V_54 -> V_66 , V_119 , sizeof( * V_119 ) ) ;
return V_54 ;
}
static struct V_121 * F_92 ( int V_125 )
{
struct V_121 * V_122 ;
V_122 = F_49 ( sizeof( * V_122 ) + sizeof( V_122 -> V_54 [ 0 ] ) *
V_125 , V_86 ) ;
if ( ! V_122 )
return NULL ;
V_122 -> V_125 = V_125 ;
return V_122 ;
}
static void F_93 ( struct V_57 * V_58 ,
struct V_121 * V_122 ,
struct V_118 * V_119 ,
int V_22 )
{
for (; -- V_22 >= 0 ; ) {
if ( F_17 ( & V_122 -> V_54 [ V_22 ] -> V_2 . V_3 ) ) {
V_58 -> V_69 -- ;
F_40 ( & V_122 -> V_54 [ V_22 ] -> V_2 . V_4 ) ;
F_19 ( V_122 -> V_54 [ V_22 ] ) ;
}
}
F_19 ( V_122 ) ;
}
static struct V_121 *
F_94 ( struct V_57 * V_58 ,
struct V_118 * V_119 ,
int V_151 ,
int * V_60 ,
bool * V_152 )
{
struct V_121 * V_122 ;
struct V_53 * V_54 = NULL ;
static int V_153 = F_41 ( V_154 ) ;
static int V_155 = F_41 ( V_75 ) ;
int type ;
int V_22 = 0 ;
V_122 = F_92 ( ( V_151 ) ? V_151 : 1 ) ;
if ( ! V_122 )
return F_50 ( - V_87 ) ;
do {
if ( V_119 ) {
V_54 = F_95 ( V_58 , V_119 + V_22 ) ;
if ( V_54 ) {
F_7 ( & V_54 -> V_2 . V_3 ) ;
goto V_156;
}
}
* V_152 = true ;
V_54 = F_91 ( V_119 + V_22 ) ;
if ( ! V_54 )
goto V_157;
F_1 ( & V_54 -> V_2 , 1 , F_38 ) ;
if ( V_119 &&
V_119 [ V_22 ] . type != V_128 )
F_78 ( & V_54 -> V_2 . V_4 , & V_58 -> V_2 . V_5 ) ;
else
F_96 ( & V_54 -> V_2 . V_4 , & V_58 -> V_2 . V_5 ) ;
if ( V_119 ) {
V_58 -> V_69 ++ ;
type = V_119 [ V_22 ] . type ==
V_68 ;
* V_60 |= type ? V_153 : V_155 ;
}
V_156:
V_122 -> V_54 [ V_22 ] = V_54 ;
} while ( ++ V_22 < V_151 );
return V_122 ;
V_157:
F_93 ( V_58 , V_122 , V_119 , V_22 ) ;
return F_50 ( - V_87 ) ;
}
static struct V_121 *
F_97 ( struct V_57 * V_58 ,
struct V_55 * V_56 ,
struct V_118 * V_119 ,
int V_151 ,
bool V_158 )
{
struct V_121 * V_122 ;
struct V_49 * V_50 ;
int V_60 = 0 ;
int V_51 ;
bool V_152 = false ;
V_122 = F_94 ( V_58 , V_119 , V_151 , & V_60 ,
& V_152 ) ;
if ( F_87 ( V_122 ) || ! V_152 )
goto V_73;
if ( V_158 )
V_60 |= F_41 ( V_70 ) ;
F_35 ( V_50 , V_56 -> V_2 . V_7 ) ;
if ( ! ( V_58 -> V_79 & V_159 ) )
V_51 = F_98 ( F_33 ( & V_50 -> V_2 ) ,
V_50 , V_56 -> V_76 , V_58 ) ;
else
V_51 = F_42 ( F_33 ( & V_50 -> V_2 ) ,
V_50 , V_56 -> V_76 , V_60 , V_58 ) ;
if ( V_51 )
goto V_160;
V_58 -> V_79 |= V_159 ;
V_73:
return V_122 ;
V_160:
F_93 ( V_58 , V_122 , V_119 , V_122 -> V_125 ) ;
return F_50 ( V_51 ) ;
}
static unsigned int F_99 ( struct V_55 * V_56 ,
struct V_108 * * V_131 )
{
struct V_57 * V_58 ;
unsigned int V_109 = V_56 -> V_94 ;
if ( V_131 )
* V_131 = & V_56 -> V_2 . V_5 ;
F_100 (fte, fg) {
if ( V_58 -> V_78 != V_109 )
return V_109 ;
V_109 ++ ;
if ( V_131 )
* V_131 = & V_58 -> V_2 . V_4 ;
}
return V_109 ;
}
static struct V_57 * F_101 ( struct V_55 * V_56 ,
T_2 * V_59 ,
struct V_84 * V_85 ,
struct V_108 * * V_131 )
{
struct V_57 * V_58 ;
int V_78 ;
V_78 = F_99 ( V_56 , V_131 ) ;
V_58 = F_48 ( V_85 , V_59 , V_78 ) ;
if ( F_87 ( V_58 ) )
return V_58 ;
return V_58 ;
}
static struct V_55 * F_102 ( struct V_49 * V_50 ,
V_23 V_27 ,
T_2 * V_34 )
{
int V_161 = F_27 ( V_92 ) ;
struct V_108 * V_131 = & V_50 -> V_2 . V_5 ;
unsigned int V_162 = 0 ;
struct V_55 * V_56 ;
void * V_163 ;
unsigned int V_164 = 0 ;
T_2 * V_165 ;
if ( ! V_50 -> V_81 . V_82 )
return F_50 ( - V_166 ) ;
V_165 = F_39 ( V_161 ) ;
if ( ! V_165 )
return F_50 ( - V_87 ) ;
if ( V_50 -> V_81 . V_83 < V_50 -> V_81 . V_145 )
V_164 = V_50 -> V_100 / ( V_50 -> V_81 . V_145 + 1 ) ;
if ( V_164 == 0 )
V_164 = 1 ;
F_103 (fg, ft) {
if ( V_162 + V_164 > V_56 -> V_94 )
V_162 = V_56 -> V_94 + V_56 -> V_96 ;
else
break;
V_131 = & V_56 -> V_2 . V_4 ;
}
if ( V_162 + V_164 > V_50 -> V_100 ) {
V_56 = F_50 ( - V_137 ) ;
goto V_73;
}
F_104 ( V_92 , V_165 , V_27 ,
V_27 ) ;
F_104 ( V_92 , V_165 , V_95 , V_162 ) ;
F_104 ( V_92 , V_165 , V_97 , V_162 +
V_164 - 1 ) ;
V_163 = F_26 ( V_92 ,
V_165 , V_34 ) ;
memcpy ( V_163 , V_34 ,
F_27 ( V_30 ) ) ;
V_56 = F_88 ( V_50 , V_165 , V_131 , true ) ;
V_73:
F_43 ( V_165 ) ;
return V_56 ;
}
static bool F_69 ( struct V_118 * V_167 ,
struct V_118 * V_168 )
{
if ( V_167 -> type == V_168 -> type ) {
if ( ( V_167 -> type == V_169 &&
V_167 -> V_170 == V_168 -> V_170 ) ||
( V_167 -> type == V_128 &&
V_167 -> V_50 == V_168 -> V_50 ) ||
( V_167 -> type == V_171 &&
V_167 -> V_172 == V_168 -> V_172 ) )
return true ;
}
return false ;
}
static struct V_53 * F_95 ( struct V_57 * V_58 ,
struct V_118 * V_119 )
{
struct V_53 * V_54 ;
F_72 (rule, &fte->node.children, node.list) {
if ( F_69 ( & V_54 -> V_66 , V_119 ) )
return V_54 ;
}
return NULL ;
}
static struct V_121 * F_105 ( struct V_55 * V_56 ,
T_2 * V_59 ,
struct V_84 * V_85 ,
struct V_118 * V_119 ,
int V_151 )
{
struct V_121 * V_122 ;
struct V_49 * V_50 ;
struct V_108 * V_131 ;
struct V_57 * V_58 ;
int V_22 ;
F_9 ( & V_56 -> V_2 , V_173 ) ;
F_100 (fte, fg) {
F_9 ( & V_58 -> V_2 , V_174 ) ;
if ( F_25 ( & V_56 -> V_18 , V_59 , & V_58 -> V_63 ) &&
( V_85 -> V_71 & V_58 -> V_71 ) ) {
int V_175 = V_58 -> V_71 ;
if ( V_58 -> V_89 != V_85 -> V_89 ) {
F_37 ( F_33 ( & V_58 -> V_2 ) ,
L_11 ,
V_58 -> V_89 ,
V_85 -> V_89 ) ;
V_122 = F_50 ( - V_12 ) ;
goto V_176;
}
V_58 -> V_71 |= V_85 -> V_71 ;
V_122 = F_97 ( V_58 , V_56 , V_119 , V_151 ,
V_175 != V_85 -> V_71 ) ;
if ( F_87 ( V_122 ) ) {
V_58 -> V_71 = V_175 ;
goto V_176;
} else {
goto V_177;
}
}
F_13 ( & V_58 -> V_2 ) ;
}
F_35 ( V_50 , V_56 -> V_2 . V_7 ) ;
if ( V_56 -> V_80 >= V_56 -> V_96 ) {
V_122 = F_50 ( - V_137 ) ;
goto V_178;
}
V_58 = F_101 ( V_56 , V_59 , V_85 , & V_131 ) ;
if ( F_87 ( V_58 ) ) {
V_122 = ( void * ) V_58 ;
goto V_178;
}
F_1 ( & V_58 -> V_2 , 0 , F_44 ) ;
F_9 ( & V_58 -> V_2 , V_174 ) ;
V_122 = F_97 ( V_58 , V_56 , V_119 , V_151 , false ) ;
if ( F_87 ( V_122 ) ) {
F_13 ( & V_58 -> V_2 ) ;
F_19 ( V_58 ) ;
goto V_178;
}
V_56 -> V_80 ++ ;
F_6 ( & V_58 -> V_2 , & V_56 -> V_2 ) ;
F_78 ( & V_58 -> V_2 . V_4 , V_131 ) ;
V_177:
for ( V_22 = 0 ; V_22 < V_122 -> V_125 ; V_22 ++ ) {
if ( F_21 ( & V_122 -> V_54 [ V_22 ] -> V_2 . V_3 ) == 1 )
F_6 ( & V_122 -> V_54 [ V_22 ] -> V_2 , & V_58 -> V_2 ) ;
}
V_176:
F_13 ( & V_58 -> V_2 ) ;
V_178:
F_13 ( & V_56 -> V_2 ) ;
return V_122 ;
}
struct V_179 * F_106 ( struct V_121 * V_122 )
{
struct V_53 * V_155 ;
struct V_57 * V_58 ;
F_35 ( V_58 , V_122 -> V_54 [ 0 ] -> V_2 . V_7 ) ;
F_107 (dst, fte) {
if ( V_155 -> V_66 . type == V_68 )
return V_155 -> V_66 . V_180 ;
}
return NULL ;
}
static bool F_108 ( struct V_179 * V_180 , T_2 V_71 )
{
if ( ! ( V_71 & V_72 ) )
return ! V_180 ;
if ( ! V_180 )
return false ;
return ( V_71 & ( V_181 |
V_74 ) ) ;
}
static bool F_109 ( struct V_118 * V_119 ,
T_2 V_71 ,
struct V_49 * V_50 )
{
if ( V_119 && ( V_119 -> type == V_68 ) )
return F_108 ( V_119 -> V_180 , V_71 ) ;
if ( ! ( V_71 & V_74 ) )
return true ;
if ( ! V_119 || ( ( V_119 -> type ==
V_128 ) &&
( V_119 -> V_50 -> V_98 <= V_50 -> V_98 ) ) )
return false ;
return true ;
}
static struct V_121 *
F_110 ( struct V_49 * V_50 ,
struct V_182 * V_183 ,
struct V_84 * V_85 ,
struct V_118 * V_119 ,
int V_151 )
{
struct V_55 * V_184 ;
struct V_121 * V_54 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_151 ; V_22 ++ ) {
if ( ! F_109 ( & V_119 [ V_22 ] , V_85 -> V_71 , V_50 ) )
return F_50 ( - V_120 ) ;
}
F_9 ( & V_50 -> V_2 , V_185 ) ;
F_103 (g, ft)
if ( F_28 ( V_184 -> V_18 . V_27 ,
V_183 -> V_27 ,
V_184 -> V_18 . V_34 ,
V_183 -> V_34 ) ) {
V_54 = F_105 ( V_184 , V_183 -> V_59 ,
V_85 , V_119 , V_151 ) ;
if ( ! F_87 ( V_54 ) || F_111 ( V_54 ) != - V_137 )
goto V_186;
}
V_184 = F_102 ( V_50 , V_183 -> V_27 ,
V_183 -> V_34 ) ;
if ( F_87 ( V_184 ) ) {
V_54 = ( void * ) V_184 ;
goto V_186;
}
V_54 = F_105 ( V_184 , V_183 -> V_59 , V_85 , V_119 , V_151 ) ;
if ( F_87 ( V_54 ) ) {
F_13 ( & V_50 -> V_2 ) ;
F_8 ( & V_184 -> V_2 ) ;
F_20 ( & V_184 -> V_2 ) ;
return V_54 ;
}
V_186:
F_13 ( & V_50 -> V_2 ) ;
return V_54 ;
}
static bool F_112 ( struct V_49 * V_50 )
{
return ( ( V_50 -> type == V_187 ) &&
( F_76 ( F_33 ( & V_50 -> V_2 ) , V_188 ) ) ) ;
}
struct V_121 *
F_113 ( struct V_49 * V_50 ,
struct V_182 * V_183 ,
struct V_84 * V_85 ,
struct V_118 * V_119 ,
int V_151 )
{
struct V_45 * V_8 = F_29 ( & V_50 -> V_2 ) ;
struct V_118 V_189 ;
struct V_49 * V_67 = NULL ;
struct V_121 * V_122 = NULL ;
T_2 V_64 = V_85 -> V_71 ;
struct V_13 * V_16 ;
F_35 ( V_16 , V_50 -> V_2 . V_7 ) ;
if ( V_85 -> V_71 == V_65 ) {
if ( ! F_112 ( V_50 ) )
return F_50 ( - V_190 ) ;
if ( V_119 )
return F_50 ( - V_120 ) ;
F_12 ( & V_8 -> V_134 ) ;
V_67 = F_59 ( V_16 ) ;
if ( V_67 ) {
V_189 . type = V_128 ;
V_189 . V_50 = V_67 ;
V_119 = & V_189 ;
V_151 = 1 ;
V_85 -> V_71 = V_74 ;
} else {
F_15 ( & V_8 -> V_134 ) ;
return F_50 ( - V_190 ) ;
}
}
V_122 = F_110 ( V_50 , V_183 , V_85 , V_119 , V_151 ) ;
if ( V_64 == V_65 ) {
if ( ! F_114 ( V_122 ) &&
( F_75 ( & V_122 -> V_54 [ 0 ] -> V_67 ) ) ) {
F_12 ( & V_67 -> V_6 ) ;
F_78 ( & V_122 -> V_54 [ 0 ] -> V_67 ,
& V_67 -> V_107 ) ;
F_15 ( & V_67 -> V_6 ) ;
V_122 -> V_54 [ 0 ] -> V_64 = V_65 ;
}
F_15 ( & V_8 -> V_134 ) ;
}
return V_122 ;
}
void F_115 ( struct V_121 * V_122 )
{
int V_22 ;
for ( V_22 = V_122 -> V_125 - 1 ; V_22 >= 0 ; V_22 -- )
F_20 ( & V_122 -> V_54 [ V_22 ] -> V_2 ) ;
F_19 ( V_122 ) ;
}
static struct V_49 * F_116 ( struct V_49 * V_50 )
{
struct V_13 * V_16 ;
F_35 ( V_16 , V_50 -> V_2 . V_7 ) ;
if ( ! F_117 ( & V_50 -> V_2 . V_4 , & V_16 -> V_2 . V_5 ) )
return F_118 ( V_50 , V_2 . V_4 ) ;
return F_59 ( V_16 ) ;
}
static int F_119 ( struct V_49 * V_50 )
{
struct V_45 * V_8 = F_29 ( & V_50 -> V_2 ) ;
struct V_49 * V_191 = NULL ;
if ( V_8 -> V_117 != V_50 )
return 0 ;
V_191 = F_116 ( V_50 ) ;
if ( V_191 ) {
int V_51 = F_66 ( V_8 -> V_48 , V_191 ) ;
if ( V_51 ) {
F_37 ( V_8 -> V_48 , L_8 ,
V_50 -> V_76 ) ;
return V_51 ;
}
}
V_8 -> V_117 = V_191 ;
return 0 ;
}
static int F_120 ( struct V_49 * V_50 )
{
struct V_47 * V_48 = F_33 ( & V_50 -> V_2 ) ;
struct V_49 * V_67 ;
struct V_13 * V_16 ;
int V_51 = 0 ;
V_51 = F_119 ( V_50 ) ;
if ( V_51 )
return V_51 ;
F_35 ( V_16 , V_50 -> V_2 . V_7 ) ;
if ( ! ( F_121 ( & V_16 -> V_2 . V_5 ,
struct V_49 ,
V_2 . V_4 ) == V_50 ) )
return 0 ;
V_67 = F_59 ( V_16 ) ;
V_51 = F_70 ( V_48 , V_67 , V_50 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_64 ( V_48 , V_67 , V_16 ) ;
if ( V_51 )
F_37 ( V_48 , L_12 ,
V_50 -> V_76 ) ;
return V_51 ;
}
int F_122 ( struct V_49 * V_50 )
{
struct V_45 * V_8 = F_29 ( & V_50 -> V_2 ) ;
int V_51 = 0 ;
F_12 ( & V_8 -> V_134 ) ;
V_51 = F_120 ( V_50 ) ;
if ( V_51 ) {
F_15 ( & V_8 -> V_134 ) ;
return V_51 ;
}
if ( F_20 ( & V_50 -> V_2 ) )
F_37 ( F_33 ( & V_50 -> V_2 ) , L_13 ,
V_50 -> V_76 ) ;
F_15 ( & V_8 -> V_134 ) ;
return V_51 ;
}
void F_123 ( struct V_55 * V_56 )
{
if ( F_20 ( & V_56 -> V_2 ) )
F_37 ( F_33 ( & V_56 -> V_2 ) , L_14 ,
V_56 -> V_76 ) ;
}
struct V_14 * F_124 ( struct V_47 * V_48 ,
enum V_192 type )
{
struct V_193 * V_194 = V_48 -> V_195 . V_194 ;
struct V_45 * V_196 ;
int V_16 ;
struct V_13 * V_13 ;
struct V_14 * V_15 ;
if ( ! V_194 )
return NULL ;
switch ( type ) {
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
V_16 = type ;
break;
case V_204 :
if ( V_194 -> V_205 )
return & V_194 -> V_205 -> V_15 ;
else
return NULL ;
case V_206 :
if ( V_194 -> V_207 )
return & V_194 -> V_207 -> V_15 ;
else
return NULL ;
case V_208 :
if ( V_194 -> V_209 )
return & V_194 -> V_209 -> V_15 ;
else
return NULL ;
case V_210 :
if ( V_194 -> V_211 )
return & V_194 -> V_211 -> V_15 ;
else
return NULL ;
case V_212 :
if ( V_194 -> V_213 )
return & V_194 -> V_213 -> V_15 ;
else
return NULL ;
default:
return NULL ;
}
V_196 = V_194 -> V_196 ;
if ( ! V_196 )
return NULL ;
V_13 = F_22 ( & V_196 -> V_15 , V_16 ) ;
if ( ! V_13 )
return NULL ;
V_15 = F_121 ( & V_13 -> V_2 . V_5 ,
F_125 ( * V_15 ) ,
V_2 . V_4 ) ;
return V_15 ;
}
static struct V_13 * F_126 ( struct V_14 * V_15 ,
unsigned int V_16 , int V_136 )
{
struct V_13 * V_13 ;
V_13 = F_49 ( sizeof( * V_13 ) , V_86 ) ;
if ( ! V_13 )
return F_50 ( - V_87 ) ;
V_13 -> V_2 . type = V_214 ;
F_1 ( & V_13 -> V_2 , 1 , NULL ) ;
F_6 ( & V_13 -> V_2 , & V_15 -> V_2 ) ;
V_13 -> V_136 = V_136 ;
V_13 -> V_16 = V_16 ;
F_96 ( & V_13 -> V_2 . V_4 , & V_15 -> V_2 . V_5 ) ;
return V_13 ;
}
static struct V_14 * F_127 ( struct V_14
* V_15 )
{
V_15 -> V_2 . type = V_46 ;
return V_15 ;
}
static struct V_14 * F_128 ( struct V_13 * V_16 )
{
struct V_14 * V_15 ;
V_15 = F_49 ( sizeof( * V_15 ) , V_86 ) ;
if ( ! V_15 )
return F_50 ( - V_87 ) ;
F_127 ( V_15 ) ;
F_1 ( & V_15 -> V_2 , 1 , NULL ) ;
F_6 ( & V_15 -> V_2 , & V_16 -> V_2 ) ;
F_96 ( & V_15 -> V_2 . V_4 , & V_16 -> V_2 . V_5 ) ;
return V_15 ;
}
static int F_129 ( struct V_14 * V_15 , int V_16 ,
struct V_215 * V_216 )
{
struct V_13 * V_13 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_216 -> V_217 ; V_22 ++ ) {
V_13 = F_126 ( V_15 , V_16 ++ , V_216 -> V_136 ) ;
if ( F_87 ( V_13 ) )
return F_111 ( V_13 ) ;
}
return 0 ;
}
static bool F_130 ( struct V_47 * V_48 , struct V_218 * V_219 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_219 -> V_220 ; V_22 ++ ) {
if ( ! F_131 ( V_48 , V_219 -> V_219 [ V_22 ] ) )
return false ;
}
return true ;
}
static int F_132 ( struct V_193 * V_194 ,
struct V_215 * V_221 ,
struct V_1 * V_222 ,
struct V_215 * V_223 ,
int V_16 )
{
int V_224 = F_76 ( V_194 -> V_48 ,
V_129 .
V_224 ) ;
struct V_14 * V_225 ;
struct V_13 * V_13 ;
struct V_1 * V_226 ;
int V_22 ;
int V_51 ;
if ( V_221 -> type == V_214 ) {
if ( ( V_221 -> V_227 > V_224 ) ||
! F_130 ( V_194 -> V_48 , & V_221 -> V_219 ) )
return 0 ;
F_35 ( V_225 , V_222 ) ;
if ( V_221 -> V_217 )
return F_129 ( V_225 , V_16 , V_221 ) ;
V_13 = F_126 ( V_225 , V_16 , V_221 -> V_136 ) ;
if ( F_87 ( V_13 ) )
return F_111 ( V_13 ) ;
V_226 = & V_13 -> V_2 ;
} else if ( V_221 -> type == V_46 ) {
F_35 ( V_13 , V_222 ) ;
V_225 = F_128 ( V_13 ) ;
if ( F_87 ( V_225 ) )
return F_111 ( V_225 ) ;
V_226 = & V_225 -> V_2 ;
} else {
return - V_120 ;
}
V_16 = 0 ;
for ( V_22 = 0 ; V_22 < V_221 -> V_228 ; V_22 ++ ) {
V_51 = F_132 ( V_194 , & V_221 -> V_5 [ V_22 ] ,
V_226 , V_221 , V_16 ) ;
if ( V_51 )
return V_51 ;
if ( V_221 -> V_5 [ V_22 ] . type == V_214 &&
V_221 -> V_5 [ V_22 ] . V_217 ) {
V_16 += V_221 -> V_5 [ V_22 ] . V_217 ;
}
}
return 0 ;
}
static int F_133 ( struct V_193 * V_194 ,
struct V_215 * V_221 ,
struct V_1 * V_222 )
{
int V_22 ;
struct V_14 * V_225 ;
int V_51 ;
F_35 ( V_225 , V_222 ) ;
for ( V_22 = 0 ; V_22 < V_221 -> V_228 ; V_22 ++ ) {
V_51 = F_132 ( V_194 , & V_221 -> V_5 [ V_22 ] ,
& V_225 -> V_2 ,
V_221 , V_22 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static struct V_45 * F_134 ( struct V_193 * V_194 ,
enum V_101
V_102 )
{
struct V_45 * V_196 ;
struct V_14 * V_15 ;
V_196 = F_39 ( sizeof( * V_196 ) ) ;
if ( ! V_196 )
return NULL ;
V_196 -> V_48 = V_194 -> V_48 ;
V_196 -> V_102 = V_102 ;
V_15 = & V_196 -> V_15 ;
F_127 ( V_15 ) ;
F_5 ( & V_196 -> V_134 ) ;
F_1 ( & V_15 -> V_2 , 1 , NULL ) ;
F_6 ( & V_15 -> V_2 , NULL ) ;
return V_196 ;
}
static int F_135 ( struct V_14 * V_15 , int V_229 )
{
struct V_13 * V_16 ;
F_23 (prio, ns) {
F_136 ( V_16 , V_229 ) ;
V_229 += V_16 -> V_136 ;
}
return V_229 ;
}
static void F_136 ( struct V_13 * V_16 , int V_229 )
{
struct V_14 * V_15 ;
int V_230 = V_229 ;
V_16 -> V_138 = V_229 ;
F_137 (ns, prio)
V_230 = F_135 ( V_15 , V_229 ) ;
if ( ! V_16 -> V_136 )
V_16 -> V_136 = V_230 - V_16 -> V_138 ;
F_30 ( V_16 -> V_136 < V_230 - V_16 -> V_138 ) ;
}
static void F_138 ( struct V_45 * V_196 )
{
struct V_14 * V_15 = & V_196 -> V_15 ;
struct V_13 * V_16 ;
int V_138 = 0 ;
F_23 (prio, ns) {
F_136 ( V_16 , V_138 ) ;
V_138 += V_16 -> V_136 ;
}
}
static int F_139 ( struct V_193 * V_194 )
{
struct V_14 * V_15 = NULL ;
struct V_49 * V_50 ;
V_15 = F_124 ( V_194 -> V_48 , V_203 ) ;
if ( F_30 ( ! V_15 ) )
return - V_120 ;
V_50 = F_83 ( V_15 , V_231 , V_232 , V_233 , 0 ) ;
if ( F_87 ( V_50 ) ) {
F_140 ( V_194 -> V_48 , L_15 ) ;
return F_111 ( V_50 ) ;
}
return 0 ;
}
static int F_141 ( struct V_193 * V_194 )
{
V_194 -> V_196 = F_134 ( V_194 , V_187 ) ;
if ( ! V_194 -> V_196 )
goto V_234;
if ( F_133 ( V_194 , & V_235 , & V_194 -> V_196 -> V_15 . V_2 ) )
goto V_234;
F_138 ( V_194 -> V_196 ) ;
if ( F_139 ( V_194 ) )
goto V_234;
return 0 ;
V_234:
F_142 ( V_194 -> V_48 ) ;
return - V_87 ;
}
static void F_143 ( struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_1 * V_111 ;
struct V_1 * V_236 ;
F_144 (iter, temp, &node->children, list)
F_143 ( V_111 ) ;
F_20 ( V_2 ) ;
}
}
static void F_145 ( struct V_45 * V_196 )
{
if ( ! V_196 )
return;
F_143 ( & V_196 -> V_15 . V_2 ) ;
}
void F_142 ( struct V_47 * V_48 )
{
struct V_193 * V_194 = V_48 -> V_195 . V_194 ;
if ( F_146 ( V_48 , V_237 ) != V_238 )
return;
F_145 ( V_194 -> V_196 ) ;
F_145 ( V_194 -> V_207 ) ;
F_145 ( V_194 -> V_209 ) ;
F_145 ( V_194 -> V_205 ) ;
F_145 ( V_194 -> V_211 ) ;
F_145 ( V_194 -> V_213 ) ;
F_147 ( V_48 ) ;
F_19 ( V_194 ) ;
}
static int F_148 ( struct V_193 * V_194 )
{
struct V_13 * V_16 ;
V_194 -> V_213 = F_134 ( V_194 , V_239 ) ;
if ( ! V_194 -> V_213 )
return - V_87 ;
V_16 = F_126 ( & V_194 -> V_213 -> V_15 , 0 , 1 ) ;
if ( F_87 ( V_16 ) ) {
F_145 ( V_194 -> V_213 ) ;
return F_111 ( V_16 ) ;
}
return 0 ;
}
static int F_149 ( struct V_193 * V_194 )
{
struct V_13 * V_16 ;
V_194 -> V_211 = F_134 ( V_194 , V_240 ) ;
if ( ! V_194 -> V_211 )
return - V_87 ;
V_16 = F_126 ( & V_194 -> V_211 -> V_15 , 0 , 1 ) ;
if ( F_87 ( V_16 ) ) {
F_145 ( V_194 -> V_211 ) ;
return F_111 ( V_16 ) ;
}
return 0 ;
}
static int F_150 ( struct V_193 * V_194 )
{
struct V_13 * V_16 ;
V_194 -> V_205 = F_134 ( V_194 , V_241 ) ;
if ( ! V_194 -> V_205 )
return - V_87 ;
V_16 = F_126 ( & V_194 -> V_205 -> V_15 , 0 , 1 ) ;
if ( F_87 ( V_16 ) )
goto V_242;
V_16 = F_126 ( & V_194 -> V_205 -> V_15 , 1 , 1 ) ;
if ( F_87 ( V_16 ) )
goto V_242;
F_138 ( V_194 -> V_205 ) ;
return 0 ;
V_242:
F_145 ( V_194 -> V_205 ) ;
V_194 -> V_205 = NULL ;
return F_111 ( V_16 ) ;
}
static int F_151 ( struct V_193 * V_194 )
{
struct V_13 * V_16 ;
V_194 -> V_207 = F_134 ( V_194 , V_243 ) ;
if ( ! V_194 -> V_207 )
return - V_87 ;
V_16 = F_126 ( & V_194 -> V_207 -> V_15 , 0 ,
F_152 ( V_194 -> V_48 ) ) ;
return F_153 ( V_16 ) ;
}
static int F_154 ( struct V_193 * V_194 )
{
struct V_13 * V_16 ;
V_194 -> V_209 = F_134 ( V_194 , V_244 ) ;
if ( ! V_194 -> V_209 )
return - V_87 ;
V_16 = F_126 ( & V_194 -> V_209 -> V_15 , 0 ,
F_152 ( V_194 -> V_48 ) ) ;
return F_153 ( V_16 ) ;
}
int F_155 ( struct V_47 * V_48 )
{
struct V_193 * V_194 ;
int V_51 = 0 ;
if ( F_146 ( V_48 , V_237 ) != V_238 )
return 0 ;
V_51 = F_156 ( V_48 ) ;
if ( V_51 )
return V_51 ;
V_194 = F_49 ( sizeof( * V_194 ) , V_86 ) ;
if ( ! V_194 )
return - V_87 ;
V_194 -> V_48 = V_48 ;
V_48 -> V_195 . V_194 = V_194 ;
if ( F_146 ( V_48 , V_245 ) &&
F_157 ( V_48 , V_246 ) ) {
V_51 = F_141 ( V_194 ) ;
if ( V_51 )
goto V_51;
}
if ( F_146 ( V_48 , V_247 ) ) {
if ( F_158 ( V_48 , V_246 ) ) {
V_51 = F_150 ( V_194 ) ;
if ( V_51 )
goto V_51;
}
if ( F_159 ( V_48 , V_246 ) ) {
V_51 = F_154 ( V_194 ) ;
if ( V_51 )
goto V_51;
}
if ( F_160 ( V_48 , V_246 ) ) {
V_51 = F_151 ( V_194 ) ;
if ( V_51 )
goto V_51;
}
}
if ( F_161 ( V_48 , V_246 ) ) {
V_51 = F_149 ( V_194 ) ;
if ( V_51 )
goto V_51;
}
if ( F_162 ( V_48 , V_246 ) ) {
V_51 = F_148 ( V_194 ) ;
if ( V_51 )
goto V_51;
}
return 0 ;
V_51:
F_142 ( V_48 ) ;
return V_51 ;
}
