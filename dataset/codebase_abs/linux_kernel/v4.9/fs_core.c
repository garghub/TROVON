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
V_59 = F_39 ( V_61 ) ;
if ( ! V_59 ) {
F_37 ( V_48 , L_3 ) ;
return;
}
F_35 ( V_54 , V_2 ) ;
F_35 ( V_58 , V_54 -> V_2 . V_7 ) ;
F_35 ( V_56 , V_58 -> V_2 . V_7 ) ;
memcpy ( V_59 , V_58 -> V_62 , sizeof( V_58 -> V_62 ) ) ;
F_35 ( V_50 , V_56 -> V_2 . V_7 ) ;
F_40 ( & V_54 -> V_2 . V_4 ) ;
if ( V_54 -> V_63 == V_64 ) {
F_12 ( & V_54 -> V_65 . V_50 -> V_6 ) ;
F_40 ( & V_54 -> V_66 ) ;
F_15 ( & V_54 -> V_65 . V_50 -> V_6 ) ;
}
if ( ( V_58 -> V_67 & V_68 ) &&
-- V_58 -> V_69 ) {
V_60 = F_41 ( V_70 ) ,
V_51 = F_42 ( V_48 , V_50 ,
V_56 -> V_71 ,
V_60 ,
V_58 ) ;
if ( V_51 )
F_37 ( V_48 ,
L_4 ,
V_72 , V_56 -> V_71 , V_58 -> V_73 ) ;
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
V_58 -> V_73 ) ;
if ( V_51 )
F_37 ( V_48 ,
L_5 ,
V_58 -> V_73 , V_56 -> V_71 ) ;
V_58 -> V_74 = 0 ;
V_56 -> V_75 -- ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
struct V_49 * V_50 ;
struct V_47 * V_48 ;
F_35 ( V_56 , V_2 ) ;
F_35 ( V_50 , V_56 -> V_2 . V_7 ) ;
V_48 = F_33 ( & V_50 -> V_2 ) ;
if ( V_50 -> V_76 . V_77 )
V_50 -> V_76 . V_78 -- ;
if ( F_47 ( V_48 , V_50 , V_56 -> V_71 ) )
F_37 ( V_48 , L_6 ,
V_56 -> V_71 , V_50 -> V_71 ) ;
}
static struct V_57 * F_48 ( V_23 V_67 ,
T_2 V_79 ,
T_2 * V_59 ,
unsigned int V_73 )
{
struct V_57 * V_58 ;
V_58 = F_49 ( sizeof( * V_58 ) , V_80 ) ;
if ( ! V_58 )
return F_50 ( - V_81 ) ;
memcpy ( V_58 -> V_62 , V_59 , sizeof( V_58 -> V_62 ) ) ;
V_58 -> V_2 . type = V_82 ;
V_58 -> V_79 = V_79 ;
V_58 -> V_73 = V_73 ;
V_58 -> V_67 = V_67 ;
return V_58 ;
}
static struct V_55 * F_51 ( T_2 * V_83 )
{
struct V_55 * V_56 ;
void * V_34 = F_26 ( V_84 ,
V_83 , V_34 ) ;
V_23 V_27 = F_52 ( V_84 ,
V_83 ,
V_27 ) ;
V_56 = F_49 ( sizeof( * V_56 ) , V_80 ) ;
if ( ! V_56 )
return F_50 ( - V_81 ) ;
V_56 -> V_18 . V_27 = V_27 ;
memcpy ( & V_56 -> V_18 . V_34 , V_34 ,
sizeof( V_56 -> V_18 . V_34 ) ) ;
V_56 -> V_2 . type = V_85 ;
V_56 -> V_86 = F_52 ( V_84 , V_83 ,
V_87 ) ;
V_56 -> V_88 = F_52 ( V_84 , V_83 ,
V_89 ) - V_56 -> V_86 + 1 ;
return V_56 ;
}
static struct V_49 * F_53 ( int V_90 , T_3 V_91 , int V_92 ,
enum V_93 V_94 ,
enum V_95 V_96 )
{
struct V_49 * V_50 ;
V_50 = F_49 ( sizeof( * V_50 ) , V_80 ) ;
if ( ! V_50 )
return NULL ;
V_50 -> V_90 = V_90 ;
V_50 -> V_2 . type = V_97 ;
V_50 -> V_96 = V_96 ;
V_50 -> type = V_94 ;
V_50 -> V_91 = V_91 ;
V_50 -> V_92 = V_92 ;
F_4 ( & V_50 -> V_98 ) ;
F_5 ( & V_50 -> V_6 ) ;
return V_50 ;
}
static struct V_49 * F_54 ( struct V_1 * V_8 ,
struct V_99 * V_100 ,
bool V_101 )
{
#define F_55 ( T_4 , V_101 ) \
((reverse) ? list_prev_entry(pos, list) : list_next_entry(pos, list))
#define F_56 ( T_4 , T_5 , V_101 ) \
for (pos = list_advance_entry(pos, reverse); \
&pos->list != (head); \
pos = list_advance_entry(pos, reverse))
struct V_1 * V_102 = F_57 ( V_100 , struct V_1 , V_4 ) ;
struct V_49 * V_50 = NULL ;
if ( ! V_8 )
return NULL ;
F_56 (iter, &root->children, reverse) {
if ( V_102 -> type == V_97 ) {
F_35 ( V_50 , V_102 ) ;
return V_50 ;
}
V_50 = F_54 ( V_102 , & V_102 -> V_5 , V_101 ) ;
if ( V_50 )
return V_50 ;
}
return V_50 ;
}
static struct V_49 * F_58 ( struct V_13 * V_16 , bool V_101 )
{
struct V_49 * V_50 = NULL ;
struct V_1 * V_103 ;
struct V_1 * V_7 ;
V_7 = V_16 -> V_2 . V_7 ;
V_103 = & V_16 -> V_2 ;
while ( ! V_50 && V_7 ) {
V_50 = F_54 ( V_7 , & V_103 -> V_4 , V_101 ) ;
V_103 = V_7 ;
V_7 = V_103 -> V_7 ;
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
struct V_49 * V_102 ;
int V_22 = 0 ;
int V_51 ;
F_62 (iter, prio) {
V_22 ++ ;
V_51 = F_63 ( V_48 ,
V_102 ,
V_50 ) ;
if ( V_51 ) {
F_37 ( V_48 , L_7 ,
V_102 -> V_71 ) ;
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
struct V_49 * V_104 ;
V_104 = F_60 ( V_16 ) ;
if ( V_104 ) {
struct V_13 * V_105 ;
F_35 ( V_105 , V_104 -> V_2 . V_7 ) ;
return F_61 ( V_48 , V_105 , V_50 ) ;
}
return 0 ;
}
static int F_65 ( struct V_49 * V_50 , struct V_13
* V_16 )
{
struct V_45 * V_8 = F_29 ( & V_16 -> V_2 ) ;
int V_106 = V_107 ;
int V_51 ;
if ( V_8 -> V_108 )
V_106 = V_8 -> V_108 -> V_90 ;
if ( V_50 -> V_90 >= V_106 )
return 0 ;
V_51 = F_66 ( V_8 -> V_48 , V_50 ) ;
if ( V_51 )
F_37 ( V_8 -> V_48 , L_8 ,
V_50 -> V_71 ) ;
else
V_8 -> V_108 = V_50 ;
return V_51 ;
}
int F_67 ( struct V_53 * V_54 ,
struct V_109 * V_110 )
{
struct V_49 * V_50 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_60 = F_41 ( V_70 ) ;
int V_51 = 0 ;
F_35 ( V_58 , V_54 -> V_2 . V_7 ) ;
if ( ! ( V_58 -> V_67 & V_68 ) )
return - V_111 ;
F_11 ( & V_58 -> V_2 ) ;
F_35 ( V_56 , V_58 -> V_2 . V_7 ) ;
F_35 ( V_50 , V_56 -> V_2 . V_7 ) ;
memcpy ( & V_54 -> V_65 , V_110 , sizeof( * V_110 ) ) ;
V_51 = F_42 ( F_33 ( & V_50 -> V_2 ) ,
V_50 , V_56 -> V_71 ,
V_60 ,
V_58 ) ;
F_13 ( & V_58 -> V_2 ) ;
return V_51 ;
}
static int F_68 ( struct V_47 * V_48 ,
struct V_49 * V_112 ,
struct V_49 * V_113 )
{
struct V_109 V_110 ;
struct V_53 * V_102 ;
int V_51 = 0 ;
if ( ! V_112 || ! V_113 )
return 0 ;
V_110 . type = V_114 ;
V_110 . V_50 = V_112 ;
F_12 ( & V_113 -> V_6 ) ;
F_69 ( & V_113 -> V_98 , & V_112 -> V_98 ) ;
F_15 ( & V_113 -> V_6 ) ;
F_70 (iter, &new_next_ft->fwd_rules, next_ft) {
V_51 = F_67 ( V_102 , & V_110 ) ;
if ( V_51 )
F_71 ( L_9 ,
V_112 -> V_71 ) ;
}
return 0 ;
}
static int F_72 ( struct V_47 * V_48 , struct V_49 * V_50 ,
struct V_13 * V_16 )
{
struct V_49 * V_66 ;
int V_51 = 0 ;
if ( F_73 ( & V_16 -> V_2 . V_5 ) ) {
V_51 = F_64 ( V_48 , V_50 , V_16 ) ;
if ( V_51 )
return V_51 ;
V_66 = F_59 ( V_16 ) ;
V_51 = F_68 ( V_48 , V_50 , V_66 ) ;
if ( V_51 )
return V_51 ;
}
if ( F_74 ( V_48 ,
V_115 . V_116 ) )
V_51 = F_65 ( V_50 , V_16 ) ;
return V_51 ;
}
static void F_75 ( struct V_49 * V_50 ,
struct V_13 * V_16 )
{
struct V_99 * V_117 = & V_16 -> V_2 . V_5 ;
struct V_49 * V_102 ;
F_62 (iter, prio) {
if ( V_102 -> V_90 > V_50 -> V_90 )
break;
V_117 = & V_102 -> V_2 . V_4 ;
}
F_76 ( & V_50 -> V_2 . V_4 , V_117 ) ;
}
static struct V_49 * F_77 ( struct V_14 * V_15 ,
enum V_95 V_96 ,
T_3 V_91 , int V_16 ,
int V_92 , T_2 V_90 )
{
struct V_49 * V_66 = NULL ;
struct V_49 * V_50 ;
int V_51 ;
int V_118 ;
struct V_45 * V_8 =
F_29 ( & V_15 -> V_2 ) ;
struct V_13 * V_13 = NULL ;
if ( ! V_8 ) {
F_71 ( L_10 ) ;
return F_50 ( - V_119 ) ;
}
F_12 ( & V_8 -> V_120 ) ;
V_13 = F_22 ( V_15 , V_16 ) ;
if ( ! V_13 ) {
V_51 = - V_111 ;
goto V_121;
}
if ( V_90 >= V_13 -> V_122 ) {
V_51 = - V_123 ;
goto V_121;
}
V_90 += V_13 -> V_124 ;
V_50 = F_53 ( V_90 ,
V_91 ,
V_92 ? F_78 ( V_92 ) : 0 ,
V_8 -> V_94 ,
V_96 ) ;
if ( ! V_50 ) {
V_51 = - V_81 ;
goto V_121;
}
F_1 ( & V_50 -> V_2 , 1 , F_34 ) ;
V_118 = V_50 -> V_92 ? F_79 ( V_50 -> V_92 ) : 0 ;
V_66 = F_59 ( V_13 ) ;
V_51 = F_80 ( V_8 -> V_48 , V_50 -> V_91 , V_50 -> V_96 , V_50 -> type ,
V_50 -> V_90 , V_118 , V_66 , & V_50 -> V_71 ) ;
if ( V_51 )
goto V_125;
V_51 = F_72 ( V_8 -> V_48 , V_50 , V_13 ) ;
if ( V_51 )
goto V_126;
F_11 ( & V_13 -> V_2 ) ;
F_6 ( & V_50 -> V_2 , & V_13 -> V_2 ) ;
F_75 ( V_50 , V_13 ) ;
V_13 -> V_52 ++ ;
F_13 ( & V_13 -> V_2 ) ;
F_15 ( & V_8 -> V_120 ) ;
return V_50 ;
V_126:
F_36 ( V_8 -> V_48 , V_50 ) ;
V_125:
F_19 ( V_50 ) ;
V_121:
F_15 ( & V_8 -> V_120 ) ;
return F_50 ( V_51 ) ;
}
struct V_49 * F_81 ( struct V_14 * V_15 ,
int V_16 , int V_92 ,
T_2 V_90 )
{
return F_77 ( V_15 , V_127 , 0 , V_16 ,
V_92 , V_90 ) ;
}
struct V_49 * F_82 ( struct V_14 * V_15 ,
int V_16 , int V_92 ,
T_2 V_90 , T_3 V_91 )
{
return F_77 ( V_15 , V_127 , V_91 , V_16 ,
V_92 , V_90 ) ;
}
struct V_49 * F_83 (
struct V_14 * V_15 ,
int V_16 , T_2 V_90 )
{
return F_77 ( V_15 , V_128 , 0 , V_16 , 0 ,
V_90 ) ;
}
struct V_49 * F_84 ( struct V_14 * V_15 ,
int V_16 ,
int V_129 ,
int V_130 ,
T_2 V_90 )
{
struct V_49 * V_50 ;
if ( V_130 > V_129 )
return F_50 ( - V_111 ) ;
V_50 = F_81 ( V_15 , V_16 , V_129 , V_90 ) ;
if ( F_85 ( V_50 ) )
return V_50 ;
V_50 -> V_76 . V_77 = true ;
V_50 -> V_76 . V_131 = V_130 ;
return V_50 ;
}
static struct V_55 * F_86 ( struct V_49 * V_50 ,
T_2 * V_132 ,
struct V_99
* V_133 ,
bool V_134 )
{
struct V_55 * V_56 ;
struct V_47 * V_48 = F_33 ( & V_50 -> V_2 ) ;
int V_51 ;
if ( ! V_48 )
return F_50 ( - V_119 ) ;
V_56 = F_51 ( V_132 ) ;
if ( F_85 ( V_56 ) )
return V_56 ;
V_51 = F_87 ( V_48 , V_50 , V_132 , & V_56 -> V_71 ) ;
if ( V_51 ) {
F_19 ( V_56 ) ;
return F_50 ( V_51 ) ;
}
if ( V_50 -> V_76 . V_77 )
V_50 -> V_76 . V_78 ++ ;
F_1 ( & V_56 -> V_2 , ! V_134 , F_46 ) ;
F_6 ( & V_56 -> V_2 , & V_50 -> V_2 ) ;
F_76 ( & V_56 -> V_2 . V_4 , V_133 ) ;
return V_56 ;
}
struct V_55 * F_88 ( struct V_49 * V_50 ,
T_2 * V_132 )
{
struct V_55 * V_56 ;
if ( V_50 -> V_76 . V_77 )
return F_50 ( - V_135 ) ;
F_11 ( & V_50 -> V_2 ) ;
V_56 = F_86 ( V_50 , V_132 , V_50 -> V_2 . V_5 . V_117 , false ) ;
F_13 ( & V_50 -> V_2 ) ;
return V_56 ;
}
static struct V_53 * F_89 ( struct V_109 * V_110 )
{
struct V_53 * V_54 ;
V_54 = F_49 ( sizeof( * V_54 ) , V_80 ) ;
if ( ! V_54 )
return NULL ;
F_4 ( & V_54 -> V_66 ) ;
V_54 -> V_2 . type = V_136 ;
if ( V_110 )
memcpy ( & V_54 -> V_65 , V_110 , sizeof( * V_110 ) ) ;
return V_54 ;
}
static struct V_53 * F_90 ( struct V_57 * V_58 ,
struct V_55 * V_56 ,
struct V_109 * V_110 )
{
struct V_49 * V_50 ;
struct V_53 * V_54 ;
int V_60 = 0 ;
int V_51 ;
V_54 = F_89 ( V_110 ) ;
if ( ! V_54 )
return F_50 ( - V_81 ) ;
F_35 ( V_50 , V_56 -> V_2 . V_7 ) ;
F_1 ( & V_54 -> V_2 , 1 , F_38 ) ;
if ( V_110 && V_110 -> type != V_114 )
F_76 ( & V_54 -> V_2 . V_4 , & V_58 -> V_2 . V_5 ) ;
else
F_91 ( & V_54 -> V_2 . V_4 , & V_58 -> V_2 . V_5 ) ;
if ( V_110 ) {
V_58 -> V_69 ++ ;
V_60 |= V_110 -> type == V_137 ?
F_41 ( V_138 ) :
F_41 ( V_70 ) ;
}
if ( V_58 -> V_69 == 1 || ! V_110 )
V_51 = F_92 ( F_33 ( & V_50 -> V_2 ) ,
V_50 , V_56 -> V_71 , V_58 ) ;
else
V_51 = F_42 ( F_33 ( & V_50 -> V_2 ) ,
V_50 , V_56 -> V_71 , V_60 , V_58 ) ;
if ( V_51 )
goto V_139;
V_58 -> V_74 |= V_140 ;
return V_54 ;
V_139:
F_40 ( & V_54 -> V_2 . V_4 ) ;
F_19 ( V_54 ) ;
if ( V_110 )
V_58 -> V_69 -- ;
return F_50 ( V_51 ) ;
}
static unsigned int F_93 ( struct V_55 * V_56 ,
struct V_99 * * V_117 )
{
struct V_57 * V_58 ;
unsigned int V_100 = V_56 -> V_86 ;
if ( V_117 )
* V_117 = & V_56 -> V_2 . V_5 ;
F_94 (fte, fg) {
if ( V_58 -> V_73 != V_100 )
return V_100 ;
V_100 ++ ;
if ( V_117 )
* V_117 = & V_58 -> V_2 . V_4 ;
}
return V_100 ;
}
static struct V_57 * F_95 ( struct V_55 * V_56 ,
T_2 * V_59 ,
V_23 V_67 ,
T_2 V_79 ,
struct V_99 * * V_117 )
{
struct V_57 * V_58 ;
int V_73 ;
V_73 = F_93 ( V_56 , V_117 ) ;
V_58 = F_48 ( V_67 , V_79 , V_59 , V_73 ) ;
if ( F_85 ( V_58 ) )
return V_58 ;
return V_58 ;
}
static struct V_55 * F_96 ( struct V_49 * V_50 ,
V_23 V_27 ,
T_2 * V_34 )
{
int V_141 = F_27 ( V_84 ) ;
struct V_99 * V_117 = V_50 -> V_2 . V_5 . V_117 ;
unsigned int V_142 = 0 ;
struct V_55 * V_56 ;
void * V_143 ;
unsigned int V_144 = 0 ;
T_2 * V_145 ;
if ( ! V_50 -> V_76 . V_77 )
return F_50 ( - V_146 ) ;
V_145 = F_39 ( V_141 ) ;
if ( ! V_145 )
return F_50 ( - V_81 ) ;
if ( V_50 -> V_76 . V_78 < V_50 -> V_76 . V_131 )
V_144 = V_50 -> V_92 / ( V_50 -> V_76 . V_131 + 1 ) ;
if ( V_144 == 0 )
V_144 = 1 ;
F_97 (fg, ft) {
if ( V_142 + V_144 > V_56 -> V_86 )
V_142 = V_56 -> V_86 + V_56 -> V_88 ;
else
break;
V_117 = & V_56 -> V_2 . V_4 ;
}
if ( V_142 + V_144 > V_50 -> V_92 ) {
V_56 = F_50 ( - V_123 ) ;
goto V_147;
}
F_98 ( V_84 , V_145 , V_27 ,
V_27 ) ;
F_98 ( V_84 , V_145 , V_87 , V_142 ) ;
F_98 ( V_84 , V_145 , V_89 , V_142 +
V_144 - 1 ) ;
V_143 = F_26 ( V_84 ,
V_145 , V_34 ) ;
memcpy ( V_143 , V_34 ,
F_27 ( V_30 ) ) ;
V_56 = F_86 ( V_50 , V_145 , V_117 , true ) ;
V_147:
F_43 ( V_145 ) ;
return V_56 ;
}
static struct V_53 * F_99 ( struct V_57 * V_58 ,
struct V_109 * V_110 )
{
struct V_53 * V_54 ;
F_70 (rule, &fte->node.children, node.list) {
if ( V_54 -> V_65 . type == V_110 -> type ) {
if ( ( V_110 -> type == V_148 &&
V_110 -> V_149 == V_54 -> V_65 . V_149 ) ||
( V_110 -> type == V_114 &&
V_110 -> V_50 == V_54 -> V_65 . V_50 ) ||
( V_110 -> type == V_150 &&
V_110 -> V_151 == V_54 -> V_65 . V_151 ) )
return V_54 ;
}
}
return NULL ;
}
static struct V_53 * F_100 ( struct V_55 * V_56 ,
T_2 * V_59 ,
V_23 V_67 ,
T_2 V_79 ,
struct V_109 * V_110 )
{
struct V_57 * V_58 ;
struct V_53 * V_54 ;
struct V_49 * V_50 ;
struct V_99 * V_117 ;
F_9 ( & V_56 -> V_2 , V_152 ) ;
F_94 (fte, fg) {
F_9 ( & V_58 -> V_2 , V_153 ) ;
if ( F_25 ( & V_56 -> V_18 , V_59 , & V_58 -> V_62 ) &&
V_67 == V_58 -> V_67 && V_79 == V_58 -> V_79 ) {
V_54 = F_99 ( V_58 , V_110 ) ;
if ( V_54 ) {
F_7 ( & V_54 -> V_2 . V_3 ) ;
F_13 ( & V_58 -> V_2 ) ;
F_13 ( & V_56 -> V_2 ) ;
return V_54 ;
}
V_54 = F_90 ( V_58 , V_56 , V_110 ) ;
F_13 ( & V_58 -> V_2 ) ;
if ( F_85 ( V_54 ) )
goto V_154;
else
goto V_155;
}
F_13 ( & V_58 -> V_2 ) ;
}
F_35 ( V_50 , V_56 -> V_2 . V_7 ) ;
if ( V_56 -> V_75 >= V_56 -> V_88 ) {
V_54 = F_50 ( - V_123 ) ;
goto V_154;
}
V_58 = F_95 ( V_56 , V_59 , V_67 , V_79 , & V_117 ) ;
if ( F_85 ( V_58 ) ) {
V_54 = ( void * ) V_58 ;
goto V_154;
}
F_1 ( & V_58 -> V_2 , 0 , F_44 ) ;
V_54 = F_90 ( V_58 , V_56 , V_110 ) ;
if ( F_85 ( V_54 ) ) {
F_19 ( V_58 ) ;
goto V_154;
}
V_56 -> V_75 ++ ;
F_6 ( & V_58 -> V_2 , & V_56 -> V_2 ) ;
F_76 ( & V_58 -> V_2 . V_4 , V_117 ) ;
V_155:
F_6 ( & V_54 -> V_2 , & V_58 -> V_2 ) ;
V_154:
F_13 ( & V_56 -> V_2 ) ;
return V_54 ;
}
struct V_156 * F_101 ( struct V_53 * V_54 )
{
struct V_53 * V_157 ;
struct V_57 * V_58 ;
F_35 ( V_58 , V_54 -> V_2 . V_7 ) ;
F_102 (dst, fte) {
if ( V_157 -> V_65 . type == V_137 )
return V_157 -> V_65 . V_158 ;
}
return NULL ;
}
static bool F_103 ( struct V_156 * V_158 , T_2 V_67 )
{
if ( ! ( V_67 & V_159 ) )
return ! V_158 ;
if ( ! V_158 )
return false ;
return V_67 == ( V_160 | V_159 ) ;
}
static bool F_104 ( struct V_109 * V_110 ,
T_2 V_67 ,
struct V_49 * V_50 )
{
if ( V_110 && ( V_110 -> type == V_137 ) )
return F_103 ( V_110 -> V_158 , V_67 ) ;
if ( ! ( V_67 & V_68 ) )
return true ;
if ( ! V_110 || ( ( V_110 -> type ==
V_114 ) &&
( V_110 -> V_50 -> V_90 <= V_50 -> V_90 ) ) )
return false ;
return true ;
}
static struct V_53 *
F_105 ( struct V_49 * V_50 ,
struct V_161 * V_162 ,
T_2 V_67 ,
T_2 V_79 ,
struct V_109 * V_110 )
{
struct V_55 * V_163 ;
struct V_53 * V_54 ;
if ( ! F_104 ( V_110 , V_67 , V_50 ) )
return F_50 ( - V_111 ) ;
F_9 ( & V_50 -> V_2 , V_164 ) ;
F_97 (g, ft)
if ( F_28 ( V_163 -> V_18 . V_27 ,
V_162 -> V_27 ,
V_163 -> V_18 . V_34 ,
V_162 -> V_34 ) ) {
V_54 = F_100 ( V_163 , V_162 -> V_59 ,
V_67 , V_79 , V_110 ) ;
if ( ! F_85 ( V_54 ) || F_106 ( V_54 ) != - V_123 )
goto V_165;
}
V_163 = F_96 ( V_50 , V_162 -> V_27 ,
V_162 -> V_34 ) ;
if ( F_85 ( V_163 ) ) {
V_54 = ( void * ) V_163 ;
goto V_165;
}
V_54 = F_100 ( V_163 , V_162 -> V_59 ,
V_67 , V_79 , V_110 ) ;
if ( F_85 ( V_54 ) ) {
F_13 ( & V_50 -> V_2 ) ;
F_8 ( & V_163 -> V_2 ) ;
F_20 ( & V_163 -> V_2 ) ;
return V_54 ;
}
V_165:
F_13 ( & V_50 -> V_2 ) ;
return V_54 ;
}
static bool F_107 ( struct V_49 * V_50 )
{
return ( ( V_50 -> type == V_166 ) &&
( F_74 ( F_33 ( & V_50 -> V_2 ) , V_167 ) ) ) ;
}
struct V_53 *
F_108 ( struct V_49 * V_50 ,
struct V_161 * V_162 ,
T_2 V_67 ,
T_2 V_79 ,
struct V_109 * V_110 )
{
struct V_45 * V_8 = F_29 ( & V_50 -> V_2 ) ;
struct V_109 V_168 ;
struct V_49 * V_66 = NULL ;
struct V_53 * V_54 = NULL ;
T_2 V_63 = V_67 ;
struct V_13 * V_16 ;
F_35 ( V_16 , V_50 -> V_2 . V_7 ) ;
if ( V_67 == V_64 ) {
if ( ! F_107 ( V_50 ) )
return F_50 ( - V_169 ) ;
if ( V_110 )
return F_50 ( - V_111 ) ;
F_12 ( & V_8 -> V_120 ) ;
V_66 = F_59 ( V_16 ) ;
if ( V_66 ) {
V_168 . type = V_114 ;
V_168 . V_50 = V_66 ;
V_110 = & V_168 ;
V_67 = V_68 ;
} else {
F_15 ( & V_8 -> V_120 ) ;
return F_50 ( - V_169 ) ;
}
}
V_54 = F_105 ( V_50 , V_162 , V_67 , V_79 , V_110 ) ;
if ( V_63 == V_64 ) {
if ( ! F_109 ( V_54 ) &&
( F_73 ( & V_54 -> V_66 ) ) ) {
F_12 ( & V_66 -> V_6 ) ;
F_76 ( & V_54 -> V_66 , & V_66 -> V_98 ) ;
F_15 ( & V_66 -> V_6 ) ;
V_54 -> V_63 = V_64 ;
}
F_15 ( & V_8 -> V_120 ) ;
}
return V_54 ;
}
void F_110 ( struct V_53 * V_54 )
{
F_20 ( & V_54 -> V_2 ) ;
}
static struct V_49 * F_111 ( struct V_49 * V_50 )
{
struct V_13 * V_16 ;
F_35 ( V_16 , V_50 -> V_2 . V_7 ) ;
if ( ! F_112 ( & V_50 -> V_2 . V_4 , & V_16 -> V_2 . V_5 ) )
return F_113 ( V_50 , V_2 . V_4 ) ;
return F_59 ( V_16 ) ;
}
static int F_114 ( struct V_49 * V_50 )
{
struct V_45 * V_8 = F_29 ( & V_50 -> V_2 ) ;
struct V_49 * V_170 = NULL ;
if ( V_8 -> V_108 != V_50 )
return 0 ;
V_170 = F_111 ( V_50 ) ;
if ( V_170 ) {
int V_51 = F_66 ( V_8 -> V_48 , V_170 ) ;
if ( V_51 ) {
F_37 ( V_8 -> V_48 , L_8 ,
V_50 -> V_71 ) ;
return V_51 ;
}
}
V_8 -> V_108 = V_170 ;
return 0 ;
}
static int F_115 ( struct V_49 * V_50 )
{
struct V_47 * V_48 = F_33 ( & V_50 -> V_2 ) ;
struct V_49 * V_66 ;
struct V_13 * V_16 ;
int V_51 = 0 ;
V_51 = F_114 ( V_50 ) ;
if ( V_51 )
return V_51 ;
F_35 ( V_16 , V_50 -> V_2 . V_7 ) ;
if ( ! ( F_116 ( & V_16 -> V_2 . V_5 ,
struct V_49 ,
V_2 . V_4 ) == V_50 ) )
return 0 ;
V_66 = F_59 ( V_16 ) ;
V_51 = F_68 ( V_48 , V_66 , V_50 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_64 ( V_48 , V_66 , V_16 ) ;
if ( V_51 )
F_37 ( V_48 , L_11 ,
V_50 -> V_71 ) ;
return V_51 ;
}
int F_117 ( struct V_49 * V_50 )
{
struct V_45 * V_8 = F_29 ( & V_50 -> V_2 ) ;
int V_51 = 0 ;
F_12 ( & V_8 -> V_120 ) ;
V_51 = F_115 ( V_50 ) ;
if ( V_51 ) {
F_15 ( & V_8 -> V_120 ) ;
return V_51 ;
}
if ( F_20 ( & V_50 -> V_2 ) )
F_37 ( F_33 ( & V_50 -> V_2 ) , L_12 ,
V_50 -> V_71 ) ;
F_15 ( & V_8 -> V_120 ) ;
return V_51 ;
}
void F_118 ( struct V_55 * V_56 )
{
if ( F_20 ( & V_56 -> V_2 ) )
F_37 ( F_33 ( & V_56 -> V_2 ) , L_13 ,
V_56 -> V_71 ) ;
}
struct V_14 * F_119 ( struct V_47 * V_48 ,
enum V_171 type )
{
struct V_172 * V_173 = V_48 -> V_174 . V_173 ;
struct V_45 * V_175 ;
int V_16 ;
struct V_13 * V_13 ;
struct V_14 * V_15 ;
if ( ! V_173 )
return NULL ;
switch ( type ) {
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
V_16 = type ;
break;
case V_183 :
if ( V_173 -> V_184 )
return & V_173 -> V_184 -> V_15 ;
else
return NULL ;
case V_185 :
if ( V_173 -> V_186 )
return & V_173 -> V_186 -> V_15 ;
else
return NULL ;
case V_187 :
if ( V_173 -> V_188 )
return & V_173 -> V_188 -> V_15 ;
else
return NULL ;
case V_189 :
if ( V_173 -> V_190 )
return & V_173 -> V_190 -> V_15 ;
else
return NULL ;
case V_191 :
if ( V_173 -> V_192 )
return & V_173 -> V_192 -> V_15 ;
else
return NULL ;
default:
return NULL ;
}
V_175 = V_173 -> V_175 ;
if ( ! V_175 )
return NULL ;
V_13 = F_22 ( & V_175 -> V_15 , V_16 ) ;
if ( ! V_13 )
return NULL ;
V_15 = F_116 ( & V_13 -> V_2 . V_5 ,
F_120 ( * V_15 ) ,
V_2 . V_4 ) ;
return V_15 ;
}
static struct V_13 * F_121 ( struct V_14 * V_15 ,
unsigned int V_16 , int V_122 )
{
struct V_13 * V_13 ;
V_13 = F_49 ( sizeof( * V_13 ) , V_80 ) ;
if ( ! V_13 )
return F_50 ( - V_81 ) ;
V_13 -> V_2 . type = V_193 ;
F_1 ( & V_13 -> V_2 , 1 , NULL ) ;
F_6 ( & V_13 -> V_2 , & V_15 -> V_2 ) ;
V_13 -> V_122 = V_122 ;
V_13 -> V_16 = V_16 ;
F_91 ( & V_13 -> V_2 . V_4 , & V_15 -> V_2 . V_5 ) ;
return V_13 ;
}
static struct V_14 * F_122 ( struct V_14
* V_15 )
{
V_15 -> V_2 . type = V_46 ;
return V_15 ;
}
static struct V_14 * F_123 ( struct V_13 * V_16 )
{
struct V_14 * V_15 ;
V_15 = F_49 ( sizeof( * V_15 ) , V_80 ) ;
if ( ! V_15 )
return F_50 ( - V_81 ) ;
F_122 ( V_15 ) ;
F_1 ( & V_15 -> V_2 , 1 , NULL ) ;
F_6 ( & V_15 -> V_2 , & V_16 -> V_2 ) ;
F_91 ( & V_15 -> V_2 . V_4 , & V_16 -> V_2 . V_5 ) ;
return V_15 ;
}
static int F_124 ( struct V_14 * V_15 , int V_16 ,
struct V_194 * V_195 )
{
struct V_13 * V_13 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_195 -> V_196 ; V_22 ++ ) {
V_13 = F_121 ( V_15 , V_16 ++ , V_195 -> V_122 ) ;
if ( F_85 ( V_13 ) )
return F_106 ( V_13 ) ;
}
return 0 ;
}
static bool F_125 ( struct V_47 * V_48 , struct V_197 * V_198 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_198 -> V_199 ; V_22 ++ ) {
if ( ! F_126 ( V_48 , V_198 -> V_198 [ V_22 ] ) )
return false ;
}
return true ;
}
static int F_127 ( struct V_172 * V_173 ,
struct V_194 * V_200 ,
struct V_1 * V_201 ,
struct V_194 * V_202 ,
int V_16 )
{
int V_203 = F_74 ( V_173 -> V_48 ,
V_115 .
V_203 ) ;
struct V_14 * V_204 ;
struct V_13 * V_13 ;
struct V_1 * V_205 ;
int V_22 ;
int V_51 ;
if ( V_200 -> type == V_193 ) {
if ( ( V_200 -> V_206 > V_203 ) ||
! F_125 ( V_173 -> V_48 , & V_200 -> V_198 ) )
return 0 ;
F_35 ( V_204 , V_201 ) ;
if ( V_200 -> V_196 )
return F_124 ( V_204 , V_16 , V_200 ) ;
V_13 = F_121 ( V_204 , V_16 , V_200 -> V_122 ) ;
if ( F_85 ( V_13 ) )
return F_106 ( V_13 ) ;
V_205 = & V_13 -> V_2 ;
} else if ( V_200 -> type == V_46 ) {
F_35 ( V_13 , V_201 ) ;
V_204 = F_123 ( V_13 ) ;
if ( F_85 ( V_204 ) )
return F_106 ( V_204 ) ;
V_205 = & V_204 -> V_2 ;
} else {
return - V_111 ;
}
V_16 = 0 ;
for ( V_22 = 0 ; V_22 < V_200 -> V_207 ; V_22 ++ ) {
V_51 = F_127 ( V_173 , & V_200 -> V_5 [ V_22 ] ,
V_205 , V_200 , V_16 ) ;
if ( V_51 )
return V_51 ;
if ( V_200 -> V_5 [ V_22 ] . type == V_193 &&
V_200 -> V_5 [ V_22 ] . V_196 ) {
V_16 += V_200 -> V_5 [ V_22 ] . V_196 ;
}
}
return 0 ;
}
static int F_128 ( struct V_172 * V_173 ,
struct V_194 * V_200 ,
struct V_1 * V_201 )
{
int V_22 ;
struct V_14 * V_204 ;
int V_51 ;
F_35 ( V_204 , V_201 ) ;
for ( V_22 = 0 ; V_22 < V_200 -> V_207 ; V_22 ++ ) {
V_51 = F_127 ( V_173 , & V_200 -> V_5 [ V_22 ] ,
& V_204 -> V_2 ,
V_200 , V_22 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static struct V_45 * F_129 ( struct V_172 * V_173 ,
enum V_93
V_94 )
{
struct V_45 * V_175 ;
struct V_14 * V_15 ;
V_175 = F_39 ( sizeof( * V_175 ) ) ;
if ( ! V_175 )
return NULL ;
V_175 -> V_48 = V_173 -> V_48 ;
V_175 -> V_94 = V_94 ;
V_15 = & V_175 -> V_15 ;
F_122 ( V_15 ) ;
F_5 ( & V_175 -> V_120 ) ;
F_1 ( & V_15 -> V_2 , 1 , NULL ) ;
F_6 ( & V_15 -> V_2 , NULL ) ;
return V_175 ;
}
static int F_130 ( struct V_14 * V_15 , int V_208 )
{
struct V_13 * V_16 ;
F_23 (prio, ns) {
F_131 ( V_16 , V_208 ) ;
V_208 += V_16 -> V_122 ;
}
return V_208 ;
}
static void F_131 ( struct V_13 * V_16 , int V_208 )
{
struct V_14 * V_15 ;
int V_209 = V_208 ;
V_16 -> V_124 = V_208 ;
F_132 (ns, prio)
V_209 = F_130 ( V_15 , V_208 ) ;
if ( ! V_16 -> V_122 )
V_16 -> V_122 = V_209 - V_16 -> V_124 ;
F_30 ( V_16 -> V_122 < V_209 - V_16 -> V_124 ) ;
}
static void F_133 ( struct V_45 * V_175 )
{
struct V_14 * V_15 = & V_175 -> V_15 ;
struct V_13 * V_16 ;
int V_124 = 0 ;
F_23 (prio, ns) {
F_131 ( V_16 , V_124 ) ;
V_124 += V_16 -> V_122 ;
}
}
static int F_134 ( struct V_172 * V_173 )
{
struct V_14 * V_15 = NULL ;
struct V_49 * V_50 ;
V_15 = F_119 ( V_173 -> V_48 , V_182 ) ;
if ( ! V_15 )
return - V_111 ;
V_50 = F_81 ( V_15 , V_210 , V_211 , V_212 ) ;
if ( F_85 ( V_50 ) ) {
F_135 ( V_173 -> V_48 , L_14 ) ;
return F_106 ( V_50 ) ;
}
return 0 ;
}
static int F_136 ( struct V_172 * V_173 )
{
V_173 -> V_175 = F_129 ( V_173 , V_166 ) ;
if ( ! V_173 -> V_175 )
goto V_213;
if ( F_128 ( V_173 , & V_214 , & V_173 -> V_175 -> V_15 . V_2 ) )
goto V_213;
F_133 ( V_173 -> V_175 ) ;
if ( F_134 ( V_173 ) )
goto V_213;
return 0 ;
V_213:
F_137 ( V_173 -> V_48 ) ;
return - V_81 ;
}
static void F_138 ( struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_1 * V_102 ;
struct V_1 * V_215 ;
F_139 (iter, temp, &node->children, list)
F_138 ( V_102 ) ;
F_20 ( V_2 ) ;
}
}
static void F_140 ( struct V_45 * V_175 )
{
if ( ! V_175 )
return;
F_138 ( & V_175 -> V_15 . V_2 ) ;
}
void F_137 ( struct V_47 * V_48 )
{
struct V_172 * V_173 = V_48 -> V_174 . V_173 ;
if ( F_141 ( V_48 , V_216 ) != V_217 )
return;
F_140 ( V_173 -> V_175 ) ;
F_140 ( V_173 -> V_186 ) ;
F_140 ( V_173 -> V_188 ) ;
F_140 ( V_173 -> V_184 ) ;
F_140 ( V_173 -> V_190 ) ;
F_140 ( V_173 -> V_192 ) ;
F_142 ( V_48 ) ;
F_19 ( V_173 ) ;
}
static int F_143 ( struct V_172 * V_173 )
{
struct V_13 * V_16 ;
V_173 -> V_192 = F_129 ( V_173 , V_218 ) ;
if ( ! V_173 -> V_192 )
return - V_81 ;
V_16 = F_121 ( & V_173 -> V_192 -> V_15 , 0 , 1 ) ;
if ( F_85 ( V_16 ) ) {
F_140 ( V_173 -> V_192 ) ;
return F_106 ( V_16 ) ;
}
return 0 ;
}
static int F_144 ( struct V_172 * V_173 )
{
struct V_13 * V_16 ;
V_173 -> V_190 = F_129 ( V_173 , V_219 ) ;
if ( ! V_173 -> V_190 )
return - V_81 ;
V_16 = F_121 ( & V_173 -> V_190 -> V_15 , 0 , 1 ) ;
if ( F_85 ( V_16 ) ) {
F_140 ( V_173 -> V_190 ) ;
return F_106 ( V_16 ) ;
}
return 0 ;
}
static int F_145 ( struct V_172 * V_173 )
{
struct V_13 * V_16 ;
V_173 -> V_184 = F_129 ( V_173 , V_220 ) ;
if ( ! V_173 -> V_184 )
return - V_81 ;
V_16 = F_121 ( & V_173 -> V_184 -> V_15 , 0 , 1 ) ;
if ( F_85 ( V_16 ) )
goto V_221;
V_16 = F_121 ( & V_173 -> V_184 -> V_15 , 1 , 1 ) ;
if ( F_85 ( V_16 ) )
goto V_221;
F_133 ( V_173 -> V_184 ) ;
return 0 ;
V_221:
F_140 ( V_173 -> V_184 ) ;
V_173 -> V_184 = NULL ;
return F_106 ( V_16 ) ;
}
static int F_146 ( struct V_172 * V_173 )
{
struct V_13 * V_16 ;
V_173 -> V_186 = F_129 ( V_173 , V_222 ) ;
if ( ! V_173 -> V_186 )
return - V_81 ;
V_16 = F_121 ( & V_173 -> V_186 -> V_15 , 0 ,
F_147 ( V_173 -> V_48 ) ) ;
return F_148 ( V_16 ) ;
}
static int F_149 ( struct V_172 * V_173 )
{
struct V_13 * V_16 ;
V_173 -> V_188 = F_129 ( V_173 , V_223 ) ;
if ( ! V_173 -> V_188 )
return - V_81 ;
V_16 = F_121 ( & V_173 -> V_188 -> V_15 , 0 ,
F_147 ( V_173 -> V_48 ) ) ;
return F_148 ( V_16 ) ;
}
int F_150 ( struct V_47 * V_48 )
{
struct V_172 * V_173 ;
int V_51 = 0 ;
if ( F_141 ( V_48 , V_216 ) != V_217 )
return 0 ;
V_51 = F_151 ( V_48 ) ;
if ( V_51 )
return V_51 ;
V_173 = F_49 ( sizeof( * V_173 ) , V_80 ) ;
if ( ! V_173 )
return - V_81 ;
V_173 -> V_48 = V_48 ;
V_48 -> V_174 . V_173 = V_173 ;
if ( F_141 ( V_48 , V_224 ) &&
F_152 ( V_48 , V_225 ) ) {
V_51 = F_136 ( V_173 ) ;
if ( V_51 )
goto V_51;
}
if ( F_141 ( V_48 , V_226 ) ) {
if ( F_153 ( V_48 , V_225 ) ) {
V_51 = F_145 ( V_173 ) ;
if ( V_51 )
goto V_51;
}
if ( F_154 ( V_48 , V_225 ) ) {
V_51 = F_149 ( V_173 ) ;
if ( V_51 )
goto V_51;
}
if ( F_155 ( V_48 , V_225 ) ) {
V_51 = F_146 ( V_173 ) ;
if ( V_51 )
goto V_51;
}
}
if ( F_156 ( V_48 , V_225 ) ) {
V_51 = F_144 ( V_173 ) ;
if ( V_51 )
goto V_51;
}
if ( F_157 ( V_48 , V_225 ) ) {
V_51 = F_143 ( V_173 ) ;
if ( V_51 )
goto V_51;
}
return 0 ;
V_51:
F_137 ( V_48 ) ;
return V_51 ;
}
