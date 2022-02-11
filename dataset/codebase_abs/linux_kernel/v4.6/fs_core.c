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
static unsigned int F_24 ( struct V_13 * V_16 )
{
if ( ! F_25 ( & V_16 -> V_2 . V_5 ) ) {
struct V_18 * V_19 ;
V_19 = F_26 ( & V_16 -> V_2 . V_5 ,
struct V_18 ,
V_2 . V_4 ) ;
return V_19 -> V_20 + 1 ;
}
return V_16 -> V_21 ;
}
static bool F_27 ( void * V_22 , void * V_23 , void * V_24 , T_1 V_25 )
{
unsigned int V_26 ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ , V_22 ++ , V_23 ++ , V_24 ++ )
if ( ( * ( ( V_27 * ) V_23 ) & ( * ( V_27 * ) V_22 ) ) !=
( ( * ( V_27 * ) V_24 ) & ( * ( V_27 * ) V_22 ) ) )
return false ;
return true ;
}
static bool F_28 ( struct V_28 * V_22 ,
void * V_29 , void * V_30 )
{
if ( V_22 -> V_31 &
1 << V_32 ) {
void * V_33 = F_29 ( V_34 ,
V_29 , V_35 ) ;
void * V_36 = F_29 ( V_34 ,
V_30 , V_35 ) ;
void * V_37 = F_29 ( V_34 ,
V_22 -> V_38 , V_35 ) ;
if ( ! F_27 ( V_37 , V_33 , V_36 ,
F_30 ( V_39 ) ) )
return false ;
}
if ( V_22 -> V_31 &
1 << V_40 ) {
void * V_33 = F_29 ( V_34 ,
V_29 , V_41 ) ;
void * V_36 = F_29 ( V_34 ,
V_30 , V_41 ) ;
void * V_37 = F_29 ( V_34 ,
V_22 -> V_38 , V_41 ) ;
if ( ! F_27 ( V_37 , V_33 , V_36 ,
F_30 ( V_42 ) ) )
return false ;
}
if ( V_22 -> V_31 &
1 << V_43 ) {
void * V_33 = F_29 ( V_34 ,
V_29 , V_44 ) ;
void * V_36 = F_29 ( V_34 ,
V_30 , V_44 ) ;
void * V_37 = F_29 ( V_34 ,
V_22 -> V_38 , V_44 ) ;
if ( ! F_27 ( V_37 , V_33 , V_36 ,
F_30 ( V_39 ) ) )
return false ;
}
return true ;
}
static bool F_31 ( V_27 V_45 ,
V_27 V_46 ,
void * V_47 , void * V_48 )
{
return V_45 == V_46 &&
! memcmp ( V_47 , V_48 , F_30 ( V_34 ) ) ;
}
static struct V_49 * F_32 ( struct V_1 * V_2 )
{
struct V_1 * V_8 ;
struct V_14 * V_15 ;
V_8 = V_2 -> V_8 ;
if ( F_33 ( V_8 -> type != V_50 ) ) {
F_34 ( L_1 ) ;
return NULL ;
}
V_15 = F_35 ( V_8 , struct V_14 , V_2 ) ;
return F_35 ( V_15 , struct V_49 , V_15 ) ;
}
static inline struct V_51 * F_36 ( struct V_1 * V_2 )
{
struct V_49 * V_8 = F_32 ( V_2 ) ;
if ( V_8 )
return V_8 -> V_52 ;
return NULL ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_51 * V_52 ;
struct V_13 * V_16 ;
int V_53 ;
F_38 ( V_19 , V_2 ) ;
V_52 = F_36 ( & V_19 -> V_2 ) ;
V_53 = F_39 ( V_52 , V_19 ) ;
if ( V_53 )
F_34 ( L_2 ) ;
F_38 ( V_16 , V_19 -> V_2 . V_7 ) ;
V_16 -> V_54 -- ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
struct V_18 * V_19 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
T_2 * V_61 ;
struct V_51 * V_52 = F_36 ( V_2 ) ;
int V_62 = F_30 ( V_34 ) ;
int V_53 ;
V_61 = F_41 ( V_62 ) ;
if ( ! V_61 ) {
F_34 ( L_3 ) ;
return;
}
F_38 ( V_56 , V_2 ) ;
F_38 ( V_60 , V_56 -> V_2 . V_7 ) ;
F_38 ( V_58 , V_60 -> V_2 . V_7 ) ;
memcpy ( V_61 , V_60 -> V_63 , sizeof( V_60 -> V_63 ) ) ;
F_38 ( V_19 , V_58 -> V_2 . V_7 ) ;
F_42 ( & V_56 -> V_2 . V_4 ) ;
if ( V_56 -> V_64 == V_65 ) {
F_12 ( & V_56 -> V_66 . V_19 -> V_6 ) ;
F_42 ( & V_56 -> V_67 ) ;
F_15 ( & V_56 -> V_66 . V_19 -> V_6 ) ;
}
if ( ( V_60 -> V_68 & V_69 ) &&
-- V_60 -> V_70 ) {
V_53 = F_43 ( V_52 , V_19 ,
V_58 -> V_71 , V_60 ) ;
if ( V_53 )
F_34 ( L_4 ,
V_72 , V_58 -> V_71 , V_60 -> V_73 ) ;
}
F_44 ( V_61 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_57 * V_58 ;
struct V_51 * V_52 ;
struct V_59 * V_60 ;
int V_53 ;
F_38 ( V_60 , V_2 ) ;
F_38 ( V_58 , V_60 -> V_2 . V_7 ) ;
F_38 ( V_19 , V_58 -> V_2 . V_7 ) ;
V_52 = F_36 ( & V_19 -> V_2 ) ;
V_53 = F_46 ( V_52 , V_19 ,
V_60 -> V_73 ) ;
if ( V_53 )
F_34 ( L_5 ,
V_60 -> V_73 , V_58 -> V_71 ) ;
V_60 -> V_74 = 0 ;
V_58 -> V_75 -- ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
struct V_18 * V_19 ;
struct V_51 * V_52 ;
F_38 ( V_58 , V_2 ) ;
F_38 ( V_19 , V_58 -> V_2 . V_7 ) ;
V_52 = F_36 ( & V_19 -> V_2 ) ;
if ( F_48 ( V_52 , V_19 , V_58 -> V_71 ) )
F_34 ( L_6 ,
V_58 -> V_71 , V_19 -> V_71 ) ;
}
static struct V_59 * F_49 ( V_27 V_68 ,
T_2 V_76 ,
T_2 * V_61 ,
unsigned int V_73 )
{
struct V_59 * V_60 ;
V_60 = F_50 ( sizeof( * V_60 ) , V_77 ) ;
if ( ! V_60 )
return F_51 ( - V_78 ) ;
memcpy ( V_60 -> V_63 , V_61 , sizeof( V_60 -> V_63 ) ) ;
V_60 -> V_2 . type = V_79 ;
V_60 -> V_76 = V_76 ;
V_60 -> V_73 = V_73 ;
V_60 -> V_68 = V_68 ;
return V_60 ;
}
static struct V_57 * F_52 ( T_2 * V_80 )
{
struct V_57 * V_58 ;
void * V_38 = F_29 ( V_81 ,
V_80 , V_38 ) ;
V_27 V_31 = F_53 ( V_81 ,
V_80 ,
V_31 ) ;
V_58 = F_50 ( sizeof( * V_58 ) , V_77 ) ;
if ( ! V_58 )
return F_51 ( - V_78 ) ;
V_58 -> V_22 . V_31 = V_31 ;
memcpy ( & V_58 -> V_22 . V_38 , V_38 ,
sizeof( V_58 -> V_22 . V_38 ) ) ;
V_58 -> V_2 . type = V_82 ;
V_58 -> V_83 = F_53 ( V_81 , V_80 ,
V_84 ) ;
V_58 -> V_85 = F_53 ( V_81 , V_80 ,
V_86 ) - V_58 -> V_83 + 1 ;
return V_58 ;
}
static struct V_18 * F_54 ( int V_20 , int V_87 ,
enum V_88 V_89 )
{
struct V_18 * V_19 ;
V_19 = F_50 ( sizeof( * V_19 ) , V_77 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_20 = V_20 ;
V_19 -> V_2 . type = V_90 ;
V_19 -> type = V_89 ;
V_19 -> V_87 = V_87 ;
F_4 ( & V_19 -> V_91 ) ;
F_5 ( & V_19 -> V_6 ) ;
return V_19 ;
}
static struct V_18 * F_55 ( struct V_1 * V_8 ,
struct V_92 * V_93 ,
bool V_94 )
{
#define F_56 ( T_3 , V_94 ) \
((reverse) ? list_prev_entry(pos, list) : list_next_entry(pos, list))
#define F_57 ( T_3 , T_4 , V_94 ) \
for (pos = list_advance_entry(pos, reverse); \
&pos->list != (head); \
pos = list_advance_entry(pos, reverse))
struct V_1 * V_95 = F_58 ( V_93 , struct V_1 , V_4 ) ;
struct V_18 * V_19 = NULL ;
if ( ! V_8 )
return NULL ;
F_57 (iter, &root->children, reverse) {
if ( V_95 -> type == V_90 ) {
F_38 ( V_19 , V_95 ) ;
return V_19 ;
}
V_19 = F_55 ( V_95 , & V_95 -> V_5 , V_94 ) ;
if ( V_19 )
return V_19 ;
}
return V_19 ;
}
static struct V_18 * F_59 ( struct V_13 * V_16 , bool V_94 )
{
struct V_18 * V_19 = NULL ;
struct V_1 * V_96 ;
struct V_1 * V_7 ;
V_7 = V_16 -> V_2 . V_7 ;
V_96 = & V_16 -> V_2 ;
while ( ! V_19 && V_7 ) {
V_19 = F_55 ( V_7 , & V_96 -> V_4 , V_94 ) ;
V_96 = V_7 ;
V_7 = V_96 -> V_7 ;
}
return V_19 ;
}
static struct V_18 * F_60 ( struct V_13 * V_16 )
{
return F_59 ( V_16 , false ) ;
}
static struct V_18 * F_61 ( struct V_13 * V_16 )
{
return F_59 ( V_16 , true ) ;
}
static int F_62 ( struct V_51 * V_52 ,
struct V_13 * V_16 ,
struct V_18 * V_19 )
{
struct V_18 * V_95 ;
int V_26 = 0 ;
int V_53 ;
F_63 (iter, prio) {
V_26 ++ ;
V_53 = F_64 ( V_52 ,
V_95 ,
V_19 ) ;
if ( V_53 ) {
F_65 ( V_52 , L_7 ,
V_95 -> V_71 ) ;
if ( V_26 > 1 )
F_33 ( true ) ;
return V_53 ;
}
}
return 0 ;
}
static int F_66 ( struct V_51 * V_52 ,
struct V_18 * V_19 ,
struct V_13 * V_16 )
{
struct V_18 * V_97 ;
V_97 = F_61 ( V_16 ) ;
if ( V_97 ) {
struct V_13 * V_98 ;
F_38 ( V_98 , V_97 -> V_2 . V_7 ) ;
return F_62 ( V_52 , V_98 , V_19 ) ;
}
return 0 ;
}
static int F_67 ( struct V_18 * V_19 , struct V_13
* V_16 )
{
struct V_49 * V_8 = F_32 ( & V_16 -> V_2 ) ;
int V_99 = V_100 ;
int V_53 ;
if ( V_8 -> V_101 )
V_99 = V_8 -> V_101 -> V_20 ;
if ( V_19 -> V_20 >= V_99 )
return 0 ;
V_53 = F_68 ( V_8 -> V_52 , V_19 ) ;
if ( V_53 )
F_65 ( V_8 -> V_52 , L_8 ,
V_19 -> V_71 ) ;
else
V_8 -> V_101 = V_19 ;
return V_53 ;
}
static int F_69 ( struct V_55 * V_56 ,
struct V_102 * V_103 )
{
struct V_18 * V_19 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
int V_53 = 0 ;
F_38 ( V_60 , V_56 -> V_2 . V_7 ) ;
if ( ! ( V_60 -> V_68 & V_69 ) )
return - V_104 ;
F_11 ( & V_60 -> V_2 ) ;
F_38 ( V_58 , V_60 -> V_2 . V_7 ) ;
F_38 ( V_19 , V_58 -> V_2 . V_7 ) ;
memcpy ( & V_56 -> V_66 , V_103 , sizeof( * V_103 ) ) ;
V_53 = F_43 ( F_36 ( & V_19 -> V_2 ) ,
V_19 , V_58 -> V_71 , V_60 ) ;
F_13 ( & V_60 -> V_2 ) ;
return V_53 ;
}
static int F_70 ( struct V_51 * V_52 ,
struct V_18 * V_105 ,
struct V_18 * V_106 )
{
struct V_102 V_103 ;
struct V_55 * V_95 ;
int V_53 = 0 ;
if ( ! V_105 || ! V_106 )
return 0 ;
V_103 . type = V_107 ;
V_103 . V_19 = V_105 ;
F_12 ( & V_106 -> V_6 ) ;
F_71 ( & V_106 -> V_91 , & V_105 -> V_91 ) ;
F_15 ( & V_106 -> V_6 ) ;
F_72 (iter, &new_next_ft->fwd_rules, next_ft) {
V_53 = F_69 ( V_95 , & V_103 ) ;
if ( V_53 )
F_73 ( L_9 ,
V_105 -> V_71 ) ;
}
return 0 ;
}
static int F_74 ( struct V_51 * V_52 , struct V_18 * V_19 ,
struct V_13 * V_16 )
{
struct V_18 * V_67 ;
int V_53 = 0 ;
if ( F_25 ( & V_16 -> V_2 . V_5 ) ) {
V_53 = F_66 ( V_52 , V_19 , V_16 ) ;
if ( V_53 )
return V_53 ;
V_67 = F_60 ( V_16 ) ;
V_53 = F_70 ( V_52 , V_19 , V_67 ) ;
if ( V_53 )
return V_53 ;
}
if ( F_75 ( V_52 ,
V_108 . V_109 ) )
V_53 = F_67 ( V_19 , V_16 ) ;
return V_53 ;
}
struct V_18 * F_76 ( struct V_14 * V_15 ,
int V_16 ,
int V_87 )
{
struct V_18 * V_67 = NULL ;
struct V_18 * V_19 ;
int V_53 ;
int V_110 ;
struct V_49 * V_8 =
F_32 ( & V_15 -> V_2 ) ;
struct V_13 * V_13 = NULL ;
if ( ! V_8 ) {
F_73 ( L_10 ) ;
return F_51 ( - V_111 ) ;
}
F_12 ( & V_8 -> V_112 ) ;
V_13 = F_22 ( V_15 , V_16 ) ;
if ( ! V_13 ) {
V_53 = - V_104 ;
goto V_113;
}
if ( V_13 -> V_54 == V_13 -> V_114 ) {
V_53 = - V_115 ;
goto V_113;
}
V_19 = F_54 ( F_24 ( V_13 ) ,
F_77 ( V_87 ) ,
V_8 -> V_89 ) ;
if ( ! V_19 ) {
V_53 = - V_78 ;
goto V_113;
}
F_1 ( & V_19 -> V_2 , 1 , F_37 ) ;
V_110 = F_78 ( V_19 -> V_87 ) ;
V_67 = F_60 ( V_13 ) ;
V_53 = F_79 ( V_8 -> V_52 , V_19 -> type , V_19 -> V_20 ,
V_110 , V_67 , & V_19 -> V_71 ) ;
if ( V_53 )
goto V_116;
V_53 = F_74 ( V_8 -> V_52 , V_19 , V_13 ) ;
if ( V_53 )
goto V_117;
F_11 ( & V_13 -> V_2 ) ;
F_6 ( & V_19 -> V_2 , & V_13 -> V_2 ) ;
F_80 ( & V_19 -> V_2 . V_4 , & V_13 -> V_2 . V_5 ) ;
V_13 -> V_54 ++ ;
F_13 ( & V_13 -> V_2 ) ;
F_15 ( & V_8 -> V_112 ) ;
return V_19 ;
V_117:
F_39 ( V_8 -> V_52 , V_19 ) ;
V_116:
F_19 ( V_19 ) ;
V_113:
F_15 ( & V_8 -> V_112 ) ;
return F_51 ( V_53 ) ;
}
struct V_18 * F_81 ( struct V_14 * V_15 ,
int V_16 ,
int V_118 ,
int V_119 )
{
struct V_18 * V_19 ;
if ( V_119 > V_118 )
return F_51 ( - V_104 ) ;
V_19 = F_76 ( V_15 , V_16 , V_118 ) ;
if ( F_82 ( V_19 ) )
return V_19 ;
V_19 -> V_120 . V_121 = true ;
V_19 -> V_120 . V_122 = V_119 ;
return V_19 ;
}
static struct V_57 * F_83 ( struct V_18 * V_19 ,
T_2 * V_123 ,
struct V_92
* V_124 ,
bool V_125 )
{
struct V_57 * V_58 ;
struct V_51 * V_52 = F_36 ( & V_19 -> V_2 ) ;
int V_53 ;
if ( ! V_52 )
return F_51 ( - V_111 ) ;
V_58 = F_52 ( V_123 ) ;
if ( F_82 ( V_58 ) )
return V_58 ;
V_53 = F_84 ( V_52 , V_19 , V_123 , & V_58 -> V_71 ) ;
if ( V_53 ) {
F_19 ( V_58 ) ;
return F_51 ( V_53 ) ;
}
if ( V_19 -> V_120 . V_121 )
V_19 -> V_120 . V_126 ++ ;
F_1 ( & V_58 -> V_2 , ! V_125 , F_47 ) ;
F_6 ( & V_58 -> V_2 , & V_19 -> V_2 ) ;
F_85 ( & V_58 -> V_2 . V_4 , V_19 -> V_2 . V_5 . V_127 ) ;
return V_58 ;
}
struct V_57 * F_86 ( struct V_18 * V_19 ,
T_2 * V_123 )
{
struct V_57 * V_58 ;
if ( V_19 -> V_120 . V_121 )
return F_51 ( - V_128 ) ;
F_11 ( & V_19 -> V_2 ) ;
V_58 = F_83 ( V_19 , V_123 , & V_19 -> V_2 . V_5 , false ) ;
F_13 ( & V_19 -> V_2 ) ;
return V_58 ;
}
static struct V_55 * F_87 ( struct V_102 * V_103 )
{
struct V_55 * V_56 ;
V_56 = F_50 ( sizeof( * V_56 ) , V_77 ) ;
if ( ! V_56 )
return NULL ;
F_4 ( & V_56 -> V_67 ) ;
V_56 -> V_2 . type = V_129 ;
if ( V_103 )
memcpy ( & V_56 -> V_66 , V_103 , sizeof( * V_103 ) ) ;
return V_56 ;
}
static struct V_55 * F_88 ( struct V_59 * V_60 ,
struct V_57 * V_58 ,
struct V_102 * V_103 )
{
struct V_18 * V_19 ;
struct V_55 * V_56 ;
int V_53 ;
V_56 = F_87 ( V_103 ) ;
if ( ! V_56 )
return F_51 ( - V_78 ) ;
F_38 ( V_19 , V_58 -> V_2 . V_7 ) ;
F_1 ( & V_56 -> V_2 , 1 , F_40 ) ;
if ( V_103 && V_103 -> type != V_107 )
F_85 ( & V_56 -> V_2 . V_4 , & V_60 -> V_2 . V_5 ) ;
else
F_80 ( & V_56 -> V_2 . V_4 , & V_60 -> V_2 . V_5 ) ;
if ( V_103 )
V_60 -> V_70 ++ ;
if ( V_60 -> V_70 == 1 || ! V_103 )
V_53 = F_89 ( F_36 ( & V_19 -> V_2 ) ,
V_19 , V_58 -> V_71 , V_60 ) ;
else
V_53 = F_43 ( F_36 ( & V_19 -> V_2 ) ,
V_19 , V_58 -> V_71 , V_60 ) ;
if ( V_53 )
goto V_130;
V_60 -> V_74 |= V_131 ;
return V_56 ;
V_130:
F_42 ( & V_56 -> V_2 . V_4 ) ;
F_19 ( V_56 ) ;
if ( V_103 )
V_60 -> V_70 -- ;
return F_51 ( V_53 ) ;
}
static unsigned int F_90 ( struct V_57 * V_58 ,
struct V_92 * * V_127 )
{
struct V_59 * V_60 ;
unsigned int V_93 = V_58 -> V_83 ;
if ( V_127 )
* V_127 = & V_58 -> V_2 . V_5 ;
F_91 (fte, fg) {
if ( V_60 -> V_73 != V_93 )
return V_93 ;
V_93 ++ ;
if ( V_127 )
* V_127 = & V_60 -> V_2 . V_4 ;
}
return V_93 ;
}
static struct V_59 * F_92 ( struct V_57 * V_58 ,
T_2 * V_61 ,
V_27 V_68 ,
T_2 V_76 ,
struct V_92 * * V_127 )
{
struct V_59 * V_60 ;
int V_73 ;
V_73 = F_90 ( V_58 , V_127 ) ;
V_60 = F_49 ( V_68 , V_76 , V_61 , V_73 ) ;
if ( F_82 ( V_60 ) )
return V_60 ;
return V_60 ;
}
static struct V_57 * F_93 ( struct V_18 * V_19 ,
V_27 V_31 ,
T_2 * V_38 )
{
int V_132 = F_30 ( V_81 ) ;
struct V_92 * V_127 = & V_19 -> V_2 . V_5 ;
unsigned int V_133 = 0 ;
struct V_57 * V_58 ;
void * V_134 ;
unsigned int V_135 = 0 ;
T_2 * V_136 ;
if ( ! V_19 -> V_120 . V_121 )
return F_51 ( - V_137 ) ;
V_136 = F_41 ( V_132 ) ;
if ( ! V_136 )
return F_51 ( - V_78 ) ;
if ( V_19 -> V_120 . V_126 < V_19 -> V_120 . V_122 )
V_135 = V_19 -> V_87 / ( V_19 -> V_120 . V_122 + 1 ) ;
if ( V_135 == 0 )
V_135 = 1 ;
F_94 (fg, ft) {
if ( V_133 + V_135 > V_58 -> V_83 )
V_133 = V_58 -> V_83 + V_58 -> V_85 ;
else
break;
V_127 = & V_58 -> V_2 . V_4 ;
}
if ( V_133 + V_135 > V_19 -> V_87 ) {
V_58 = F_51 ( - V_115 ) ;
goto V_138;
}
F_95 ( V_81 , V_136 , V_31 ,
V_31 ) ;
F_95 ( V_81 , V_136 , V_84 , V_133 ) ;
F_95 ( V_81 , V_136 , V_86 , V_133 +
V_135 - 1 ) ;
V_134 = F_29 ( V_81 ,
V_136 , V_38 ) ;
memcpy ( V_134 , V_38 ,
F_30 ( V_34 ) ) ;
V_58 = F_83 ( V_19 , V_136 , V_127 , true ) ;
V_138:
F_44 ( V_136 ) ;
return V_58 ;
}
static struct V_55 * F_96 ( struct V_59 * V_60 ,
struct V_102 * V_103 )
{
struct V_55 * V_56 ;
F_72 (rule, &fte->node.children, node.list) {
if ( V_56 -> V_66 . type == V_103 -> type ) {
if ( ( V_103 -> type == V_139 &&
V_103 -> V_140 == V_56 -> V_66 . V_140 ) ||
( V_103 -> type == V_107 &&
V_103 -> V_19 == V_56 -> V_66 . V_19 ) ||
( V_103 -> type == V_141 &&
V_103 -> V_142 == V_56 -> V_66 . V_142 ) )
return V_56 ;
}
}
return NULL ;
}
static struct V_55 * F_97 ( struct V_57 * V_58 ,
T_2 * V_61 ,
V_27 V_68 ,
T_2 V_76 ,
struct V_102 * V_103 )
{
struct V_59 * V_60 ;
struct V_55 * V_56 ;
struct V_18 * V_19 ;
struct V_92 * V_127 ;
F_9 ( & V_58 -> V_2 , V_143 ) ;
F_91 (fte, fg) {
F_9 ( & V_60 -> V_2 , V_144 ) ;
if ( F_28 ( & V_58 -> V_22 , V_61 , & V_60 -> V_63 ) &&
V_68 == V_60 -> V_68 && V_76 == V_60 -> V_76 ) {
V_56 = F_96 ( V_60 , V_103 ) ;
if ( V_56 ) {
F_7 ( & V_56 -> V_2 . V_3 ) ;
F_13 ( & V_60 -> V_2 ) ;
F_13 ( & V_58 -> V_2 ) ;
return V_56 ;
}
V_56 = F_88 ( V_60 , V_58 , V_103 ) ;
F_13 ( & V_60 -> V_2 ) ;
if ( F_82 ( V_56 ) )
goto V_145;
else
goto V_146;
}
F_13 ( & V_60 -> V_2 ) ;
}
F_38 ( V_19 , V_58 -> V_2 . V_7 ) ;
if ( V_58 -> V_75 >= V_58 -> V_85 ) {
V_56 = F_51 ( - V_115 ) ;
goto V_145;
}
V_60 = F_92 ( V_58 , V_61 , V_68 , V_76 , & V_127 ) ;
if ( F_82 ( V_60 ) ) {
V_56 = ( void * ) V_60 ;
goto V_145;
}
F_1 ( & V_60 -> V_2 , 0 , F_45 ) ;
V_56 = F_88 ( V_60 , V_58 , V_103 ) ;
if ( F_82 ( V_56 ) ) {
F_19 ( V_60 ) ;
goto V_145;
}
V_58 -> V_75 ++ ;
F_6 ( & V_60 -> V_2 , & V_58 -> V_2 ) ;
F_85 ( & V_60 -> V_2 . V_4 , V_127 ) ;
V_146:
F_6 ( & V_56 -> V_2 , & V_60 -> V_2 ) ;
V_145:
F_13 ( & V_58 -> V_2 ) ;
return V_56 ;
}
static struct V_55 *
F_98 ( struct V_18 * V_19 ,
V_27 V_31 ,
T_2 * V_38 ,
T_2 * V_61 ,
T_2 V_68 ,
T_2 V_76 ,
struct V_102 * V_103 )
{
struct V_57 * V_147 ;
struct V_55 * V_56 ;
if ( ( V_68 & V_69 ) && ! V_103 )
return F_51 ( - V_104 ) ;
F_9 ( & V_19 -> V_2 , V_148 ) ;
F_94 (g, ft)
if ( F_31 ( V_147 -> V_22 . V_31 ,
V_31 ,
V_147 -> V_22 . V_38 ,
V_38 ) ) {
V_56 = F_97 ( V_147 , V_61 ,
V_68 , V_76 , V_103 ) ;
if ( ! F_82 ( V_56 ) || F_99 ( V_56 ) != - V_115 )
goto V_149;
}
V_147 = F_93 ( V_19 , V_31 , V_38 ) ;
if ( F_82 ( V_147 ) ) {
V_56 = ( void * ) V_147 ;
goto V_149;
}
V_56 = F_97 ( V_147 , V_61 ,
V_68 , V_76 , V_103 ) ;
if ( F_82 ( V_56 ) ) {
F_13 ( & V_19 -> V_2 ) ;
F_8 ( & V_147 -> V_2 ) ;
F_20 ( & V_147 -> V_2 ) ;
return V_56 ;
}
V_149:
F_13 ( & V_19 -> V_2 ) ;
return V_56 ;
}
static bool F_100 ( struct V_18 * V_19 )
{
return ( ( V_19 -> type == V_150 ) &&
( F_75 ( F_36 ( & V_19 -> V_2 ) , V_151 ) ) ) ;
}
struct V_55 *
F_101 ( struct V_18 * V_19 ,
V_27 V_31 ,
T_2 * V_38 ,
T_2 * V_61 ,
T_2 V_68 ,
T_2 V_76 ,
struct V_102 * V_103 )
{
struct V_49 * V_8 = F_32 ( & V_19 -> V_2 ) ;
struct V_102 V_152 ;
struct V_18 * V_67 = NULL ;
struct V_55 * V_56 = NULL ;
T_2 V_64 = V_68 ;
struct V_13 * V_16 ;
F_38 ( V_16 , V_19 -> V_2 . V_7 ) ;
if ( V_68 == V_65 ) {
if ( ! F_100 ( V_19 ) )
return F_51 ( - V_153 ) ;
if ( V_103 )
return F_51 ( - V_104 ) ;
F_12 ( & V_8 -> V_112 ) ;
V_67 = F_60 ( V_16 ) ;
if ( V_67 ) {
V_152 . type = V_107 ;
V_152 . V_19 = V_67 ;
V_103 = & V_152 ;
V_68 = V_69 ;
} else {
F_15 ( & V_8 -> V_112 ) ;
return F_51 ( - V_153 ) ;
}
}
V_56 = F_98 ( V_19 , V_31 , V_38 ,
V_61 , V_68 , V_76 , V_103 ) ;
if ( V_64 == V_65 ) {
if ( ! F_102 ( V_56 ) &&
( F_25 ( & V_56 -> V_67 ) ) ) {
F_12 ( & V_67 -> V_6 ) ;
F_85 ( & V_56 -> V_67 , & V_67 -> V_91 ) ;
F_15 ( & V_67 -> V_6 ) ;
V_56 -> V_64 = V_65 ;
}
F_15 ( & V_8 -> V_112 ) ;
}
return V_56 ;
}
void F_103 ( struct V_55 * V_56 )
{
F_20 ( & V_56 -> V_2 ) ;
}
static struct V_18 * F_104 ( struct V_18 * V_19 )
{
struct V_13 * V_16 ;
F_38 ( V_16 , V_19 -> V_2 . V_7 ) ;
if ( ! F_105 ( & V_19 -> V_2 . V_4 , & V_16 -> V_2 . V_5 ) )
return F_106 ( V_19 , V_2 . V_4 ) ;
return F_60 ( V_16 ) ;
}
static int F_107 ( struct V_18 * V_19 )
{
struct V_49 * V_8 = F_32 ( & V_19 -> V_2 ) ;
struct V_18 * V_154 = NULL ;
if ( V_8 -> V_101 != V_19 )
return 0 ;
V_154 = F_104 ( V_19 ) ;
if ( V_154 ) {
int V_53 = F_68 ( V_8 -> V_52 , V_154 ) ;
if ( V_53 ) {
F_65 ( V_8 -> V_52 , L_8 ,
V_19 -> V_71 ) ;
return V_53 ;
}
V_8 -> V_101 = V_154 ;
}
return 0 ;
}
static int F_108 ( struct V_18 * V_19 )
{
struct V_51 * V_52 = F_36 ( & V_19 -> V_2 ) ;
struct V_18 * V_67 ;
struct V_13 * V_16 ;
int V_53 = 0 ;
V_53 = F_107 ( V_19 ) ;
if ( V_53 )
return V_53 ;
F_38 ( V_16 , V_19 -> V_2 . V_7 ) ;
if ( ! ( F_109 ( & V_16 -> V_2 . V_5 ,
struct V_18 ,
V_2 . V_4 ) == V_19 ) )
return 0 ;
V_67 = F_60 ( V_16 ) ;
V_53 = F_70 ( V_52 , V_67 , V_19 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_66 ( V_52 , V_67 , V_16 ) ;
if ( V_53 )
F_65 ( V_52 , L_11 ,
V_19 -> V_71 ) ;
return V_53 ;
}
int F_110 ( struct V_18 * V_19 )
{
struct V_49 * V_8 = F_32 ( & V_19 -> V_2 ) ;
int V_53 = 0 ;
F_12 ( & V_8 -> V_112 ) ;
V_53 = F_108 ( V_19 ) ;
if ( V_53 ) {
F_15 ( & V_8 -> V_112 ) ;
return V_53 ;
}
if ( F_20 ( & V_19 -> V_2 ) )
F_65 ( F_36 ( & V_19 -> V_2 ) , L_12 ,
V_19 -> V_71 ) ;
F_15 ( & V_8 -> V_112 ) ;
return V_53 ;
}
void F_111 ( struct V_57 * V_58 )
{
if ( F_20 ( & V_58 -> V_2 ) )
F_65 ( F_36 ( & V_58 -> V_2 ) , L_13 ,
V_58 -> V_71 ) ;
}
struct V_14 * F_112 ( struct V_51 * V_52 ,
enum V_155 type )
{
struct V_49 * V_156 = V_52 -> V_157 . V_156 ;
int V_16 ;
struct V_13 * V_13 ;
struct V_14 * V_15 ;
if ( ! V_156 )
return NULL ;
switch ( type ) {
case V_158 :
case V_159 :
case V_160 :
case V_161 :
V_16 = type ;
break;
case V_162 :
if ( V_52 -> V_157 . V_163 )
return & V_52 -> V_157 . V_163 -> V_15 ;
else
return NULL ;
default:
return NULL ;
}
V_13 = F_22 ( & V_156 -> V_15 , V_16 ) ;
if ( ! V_13 )
return NULL ;
V_15 = F_109 ( & V_13 -> V_2 . V_5 ,
F_113 ( * V_15 ) ,
V_2 . V_4 ) ;
return V_15 ;
}
static struct V_13 * F_114 ( struct V_14 * V_15 ,
unsigned V_16 , int V_114 )
{
struct V_13 * V_13 ;
V_13 = F_50 ( sizeof( * V_13 ) , V_77 ) ;
if ( ! V_13 )
return F_51 ( - V_78 ) ;
V_13 -> V_2 . type = V_164 ;
F_1 ( & V_13 -> V_2 , 1 , NULL ) ;
F_6 ( & V_13 -> V_2 , & V_15 -> V_2 ) ;
V_13 -> V_114 = V_114 ;
V_13 -> V_16 = V_16 ;
F_80 ( & V_13 -> V_2 . V_4 , & V_15 -> V_2 . V_5 ) ;
return V_13 ;
}
static struct V_14 * F_115 ( struct V_14
* V_15 )
{
V_15 -> V_2 . type = V_50 ;
return V_15 ;
}
static struct V_14 * F_116 ( struct V_13 * V_16 )
{
struct V_14 * V_15 ;
V_15 = F_50 ( sizeof( * V_15 ) , V_77 ) ;
if ( ! V_15 )
return F_51 ( - V_78 ) ;
F_115 ( V_15 ) ;
F_1 ( & V_15 -> V_2 , 1 , NULL ) ;
F_6 ( & V_15 -> V_2 , & V_16 -> V_2 ) ;
F_80 ( & V_15 -> V_2 . V_4 , & V_16 -> V_2 . V_5 ) ;
return V_15 ;
}
static int F_117 ( struct V_14 * V_15 , struct V_165
* V_166 )
{
struct V_13 * V_13 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_166 -> V_167 ; V_26 ++ ) {
V_13 = F_114 ( V_15 , V_26 , V_166 -> V_114 ) ;
if ( F_82 ( V_13 ) )
return F_99 ( V_13 ) ;
}
return 0 ;
}
static bool F_118 ( struct V_51 * V_52 , struct V_168 * V_169 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_169 -> V_170 ; V_26 ++ ) {
if ( ! F_119 ( V_52 , V_169 -> V_169 [ V_26 ] ) )
return false ;
}
return true ;
}
static int F_120 ( struct V_51 * V_52 ,
struct V_165 * V_171 ,
struct V_1 * V_172 ,
struct V_165 * V_173 ,
int V_73 )
{
int V_174 = F_75 ( V_52 ,
V_108 .
V_174 ) ;
struct V_14 * V_175 ;
struct V_13 * V_13 ;
struct V_1 * V_176 ;
int V_26 ;
int V_53 ;
if ( V_171 -> type == V_164 ) {
if ( ( V_171 -> V_177 > V_174 ) ||
! F_118 ( V_52 , & V_171 -> V_169 ) )
return 0 ;
F_38 ( V_175 , V_172 ) ;
if ( V_171 -> V_167 )
return F_117 ( V_175 , V_171 ) ;
V_13 = F_114 ( V_175 , V_73 , V_171 -> V_114 ) ;
if ( F_82 ( V_13 ) )
return F_99 ( V_13 ) ;
V_176 = & V_13 -> V_2 ;
} else if ( V_171 -> type == V_50 ) {
F_38 ( V_13 , V_172 ) ;
V_175 = F_116 ( V_13 ) ;
if ( F_82 ( V_175 ) )
return F_99 ( V_175 ) ;
V_176 = & V_175 -> V_2 ;
} else {
return - V_104 ;
}
for ( V_26 = 0 ; V_26 < V_171 -> V_178 ; V_26 ++ ) {
V_53 = F_120 ( V_52 , & V_171 -> V_5 [ V_26 ] ,
V_176 , V_171 , V_26 ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
static int F_121 ( struct V_51 * V_52 ,
struct V_165 * V_171 ,
struct V_1 * V_172 )
{
int V_26 ;
struct V_14 * V_175 ;
int V_53 ;
F_38 ( V_175 , V_172 ) ;
for ( V_26 = 0 ; V_26 < V_171 -> V_178 ; V_26 ++ ) {
V_53 = F_120 ( V_52 , & V_171 -> V_5 [ V_26 ] ,
& V_175 -> V_2 ,
V_171 , V_26 ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
static struct V_49 * F_122 ( struct V_51 * V_52 ,
enum V_88
V_89 )
{
struct V_49 * V_156 ;
struct V_14 * V_15 ;
V_156 = F_41 ( sizeof( * V_156 ) ) ;
if ( ! V_156 )
return NULL ;
V_156 -> V_52 = V_52 ;
V_156 -> V_89 = V_89 ;
V_15 = & V_156 -> V_15 ;
F_115 ( V_15 ) ;
F_5 ( & V_156 -> V_112 ) ;
F_1 ( & V_15 -> V_2 , 1 , NULL ) ;
F_6 ( & V_15 -> V_2 , NULL ) ;
return V_156 ;
}
static int F_123 ( struct V_14 * V_15 , int V_179 )
{
struct V_13 * V_16 ;
F_23 (prio, ns) {
F_124 ( V_16 , V_179 ) ;
V_179 += V_16 -> V_114 ;
}
return V_179 ;
}
static void F_124 ( struct V_13 * V_16 , int V_179 )
{
struct V_14 * V_15 ;
int V_180 = V_179 ;
V_16 -> V_21 = V_179 ;
F_125 (ns, prio)
V_180 = F_123 ( V_15 , V_179 ) ;
if ( ! V_16 -> V_114 )
V_16 -> V_114 = V_180 - V_16 -> V_21 ;
F_33 ( V_16 -> V_114 < V_180 - V_16 -> V_21 ) ;
}
static void F_126 ( struct V_49 * V_156 )
{
struct V_14 * V_15 = & V_156 -> V_15 ;
struct V_13 * V_16 ;
int V_21 = 0 ;
F_23 (prio, ns) {
F_124 ( V_16 , V_21 ) ;
V_21 += V_16 -> V_114 ;
}
}
static int F_127 ( struct V_51
* V_52 )
{
struct V_14 * V_15 = NULL ;
struct V_18 * V_19 ;
V_15 = F_112 ( V_52 , V_161 ) ;
if ( ! V_15 )
return - V_104 ;
V_19 = F_76 ( V_15 , V_181 , V_182 ) ;
if ( F_82 ( V_19 ) ) {
F_128 ( V_52 , L_14 ) ;
return F_99 ( V_19 ) ;
}
return 0 ;
}
static int F_129 ( struct V_51 * V_52 )
{
V_52 -> V_157 . V_156 = F_122 ( V_52 , V_150 ) ;
if ( F_102 ( V_52 -> V_157 . V_156 ) )
goto V_183;
if ( F_121 ( V_52 , & V_184 , & V_52 -> V_157 . V_156 -> V_15 . V_2 ) )
goto V_183;
F_126 ( V_52 -> V_157 . V_156 ) ;
if ( F_127 ( V_52 ) )
goto V_183;
return 0 ;
V_183:
F_130 ( V_52 ) ;
return - V_78 ;
}
static void F_131 ( struct V_51 * V_52 ,
struct V_49 * V_156 )
{
struct V_1 * V_16 ;
if ( ! V_156 )
return;
if ( ! F_25 ( & V_156 -> V_15 . V_2 . V_5 ) ) {
V_16 = F_109 ( & V_156 -> V_15 . V_2 . V_5 ,
struct V_1 ,
V_4 ) ;
if ( F_20 ( V_16 ) )
F_65 ( V_52 ,
L_15 ) ;
}
if ( F_20 ( & V_156 -> V_15 . V_2 ) )
F_65 ( V_52 ,
L_16 ) ;
V_156 = NULL ;
}
static void F_132 ( struct V_13 * V_16 )
{
struct V_18 * V_95 ;
struct V_18 * V_185 ;
F_133 (iter, tmp, prio)
F_110 ( V_95 ) ;
}
static void F_134 ( struct V_51 * V_52 )
{
struct V_49 * V_156 = V_52 -> V_157 . V_156 ;
struct V_13 * V_17 ;
if ( ! F_135 ( V_52 , V_186 ) )
return;
if ( ! V_156 )
return;
F_23 (iter_prio, &root_ns->ns) {
struct V_1 * V_2 ;
struct V_14 * V_187 ;
F_136 (node, iter_prio) {
if ( V_2 -> type == V_90 )
continue;
F_38 ( V_187 , V_2 ) ;
while ( ! F_25 ( & V_187 -> V_2 . V_5 ) ) {
struct V_13 * V_188 ;
struct V_1 * V_189 =
F_109 ( & V_187 -> V_2 . V_5 ,
struct V_1 ,
V_4 ) ;
F_38 ( V_188 , V_189 ) ;
F_132 ( V_188 ) ;
if ( F_20 ( V_189 ) ) {
F_65 ( V_52 ,
L_17 ,
V_188 -> V_16 ) ;
return;
}
}
}
}
F_23 (iter_prio, &root_ns->ns) {
while ( ! F_25 ( & V_17 -> V_2 . V_5 ) ) {
struct V_1 * V_187 =
F_109 ( & V_17 -> V_2 . V_5 ,
struct V_1 ,
V_4 ) ;
if ( F_20 ( V_187 ) ) {
F_65 ( V_52 ,
L_18 ) ;
return;
}
}
}
while ( ! F_25 ( & V_156 -> V_15 . V_2 . V_5 ) ) {
struct V_13 * V_190 ;
struct V_1 * V_191 =
F_109 ( & V_156 -> V_15 . V_2 . V_5 ,
struct V_1 ,
V_4 ) ;
F_38 ( V_190 , V_191 ) ;
if ( F_20 ( V_191 ) ) {
F_65 ( V_52 ,
L_17 ,
V_190 -> V_16 ) ;
return;
}
}
if ( F_20 ( & V_156 -> V_15 . V_2 ) ) {
F_65 ( V_52 ,
L_19 ) ;
return;
}
V_52 -> V_157 . V_156 = NULL ;
}
void F_130 ( struct V_51 * V_52 )
{
F_134 ( V_52 ) ;
F_131 ( V_52 , V_52 -> V_157 . V_163 ) ;
}
static int F_137 ( struct V_51 * V_52 )
{
struct V_13 * V_16 ;
V_52 -> V_157 . V_163 = F_122 ( V_52 , V_192 ) ;
if ( ! V_52 -> V_157 . V_163 )
return - V_78 ;
V_16 = F_114 ( & V_52 -> V_157 . V_163 -> V_15 , 0 , 1 ) ;
if ( F_82 ( V_16 ) ) {
F_131 ( V_52 , V_52 -> V_157 . V_163 ) ;
return F_99 ( V_16 ) ;
} else {
return 0 ;
}
}
int F_138 ( struct V_51 * V_52 )
{
int V_53 = 0 ;
if ( F_135 ( V_52 , V_186 ) ) {
V_53 = F_129 ( V_52 ) ;
if ( V_53 )
return V_53 ;
}
if ( F_135 ( V_52 , V_193 ) ) {
V_53 = F_137 ( V_52 ) ;
if ( V_53 )
F_134 ( V_52 ) ;
}
return V_53 ;
}
