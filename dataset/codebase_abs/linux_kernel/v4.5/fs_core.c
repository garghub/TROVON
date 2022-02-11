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
if ( F_21 ( & V_2 -> V_3 ) > 1 )
return - V_12 ;
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
V_60 -> V_64 -- ;
if ( V_60 -> V_64 ) {
V_53 = F_43 ( V_52 , V_19 ,
V_58 -> V_65 , V_60 ) ;
if ( V_53 )
F_34 ( L_4 ,
V_66 , V_58 -> V_65 , V_60 -> V_67 ) ;
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
V_60 -> V_67 ) ;
if ( V_53 )
F_34 ( L_5 ,
V_60 -> V_67 , V_58 -> V_65 ) ;
V_60 -> V_68 = 0 ;
V_58 -> V_69 -- ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
struct V_18 * V_19 ;
struct V_51 * V_52 ;
F_38 ( V_58 , V_2 ) ;
F_38 ( V_19 , V_58 -> V_2 . V_7 ) ;
V_52 = F_36 ( & V_19 -> V_2 ) ;
if ( F_48 ( V_52 , V_19 , V_58 -> V_65 ) )
F_34 ( L_6 ,
V_58 -> V_65 , V_19 -> V_65 ) ;
}
static struct V_59 * F_49 ( V_27 V_70 ,
T_2 V_71 ,
T_2 * V_61 ,
unsigned int V_67 )
{
struct V_59 * V_60 ;
V_60 = F_50 ( sizeof( * V_60 ) , V_72 ) ;
if ( ! V_60 )
return F_51 ( - V_73 ) ;
memcpy ( V_60 -> V_63 , V_61 , sizeof( V_60 -> V_63 ) ) ;
V_60 -> V_2 . type = V_74 ;
V_60 -> V_71 = V_71 ;
V_60 -> V_67 = V_67 ;
V_60 -> V_70 = V_70 ;
return V_60 ;
}
static struct V_57 * F_52 ( T_2 * V_75 )
{
struct V_57 * V_58 ;
void * V_38 = F_29 ( V_76 ,
V_75 , V_38 ) ;
V_27 V_31 = F_53 ( V_76 ,
V_75 ,
V_31 ) ;
V_58 = F_50 ( sizeof( * V_58 ) , V_72 ) ;
if ( ! V_58 )
return F_51 ( - V_73 ) ;
V_58 -> V_22 . V_31 = V_31 ;
memcpy ( & V_58 -> V_22 . V_38 , V_38 ,
sizeof( V_58 -> V_22 . V_38 ) ) ;
V_58 -> V_2 . type = V_77 ;
V_58 -> V_78 = F_53 ( V_76 , V_75 ,
V_79 ) ;
V_58 -> V_80 = F_53 ( V_76 , V_75 ,
V_81 ) - V_58 -> V_78 + 1 ;
return V_58 ;
}
static struct V_18 * F_54 ( int V_20 , int V_82 ,
enum V_83 V_84 )
{
struct V_18 * V_19 ;
V_19 = F_50 ( sizeof( * V_19 ) , V_72 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_20 = V_20 ;
V_19 -> V_2 . type = V_85 ;
V_19 -> type = V_84 ;
V_19 -> V_82 = V_82 ;
return V_19 ;
}
static struct V_18 * F_55 ( struct V_1 * V_8 ,
struct V_86 * V_87 ,
bool V_88 )
{
#define F_56 ( T_3 , V_88 ) \
((reverse) ? list_prev_entry(pos, list) : list_next_entry(pos, list))
#define F_57 ( T_3 , T_4 , V_88 ) \
for (pos = list_advance_entry(pos, reverse); \
&pos->list != (head); \
pos = list_advance_entry(pos, reverse))
struct V_1 * V_89 = F_58 ( V_87 , struct V_1 , V_4 ) ;
struct V_18 * V_19 = NULL ;
if ( ! V_8 )
return NULL ;
F_57 (iter, &root->children, reverse) {
if ( V_89 -> type == V_85 ) {
F_38 ( V_19 , V_89 ) ;
return V_19 ;
}
V_19 = F_55 ( V_89 , & V_89 -> V_5 , V_88 ) ;
if ( V_19 )
return V_19 ;
}
return V_19 ;
}
static struct V_18 * F_59 ( struct V_13 * V_16 , bool V_88 )
{
struct V_18 * V_19 = NULL ;
struct V_1 * V_90 ;
struct V_1 * V_7 ;
V_7 = V_16 -> V_2 . V_7 ;
V_90 = & V_16 -> V_2 ;
while ( ! V_19 && V_7 ) {
V_19 = F_55 ( V_7 , & V_90 -> V_4 , V_88 ) ;
V_90 = V_7 ;
V_7 = V_90 -> V_7 ;
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
struct V_18 * V_89 ;
int V_26 = 0 ;
int V_53 ;
F_63 (iter, prio) {
V_26 ++ ;
V_53 = F_64 ( V_52 ,
V_89 ,
V_19 ) ;
if ( V_53 ) {
F_65 ( V_52 , L_7 ,
V_89 -> V_65 ) ;
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
struct V_18 * V_91 ;
V_91 = F_61 ( V_16 ) ;
if ( V_91 ) {
struct V_13 * V_92 ;
F_38 ( V_92 , V_91 -> V_2 . V_7 ) ;
return F_62 ( V_52 , V_92 , V_19 ) ;
}
return 0 ;
}
static int F_67 ( struct V_18 * V_19 , struct V_13
* V_16 )
{
struct V_49 * V_8 = F_32 ( & V_16 -> V_2 ) ;
int V_93 = V_94 ;
int V_53 ;
if ( V_8 -> V_95 )
V_93 = V_8 -> V_95 -> V_20 ;
if ( V_19 -> V_20 >= V_93 )
return 0 ;
V_53 = F_68 ( V_8 -> V_52 , V_19 ) ;
if ( V_53 )
F_65 ( V_8 -> V_52 , L_8 ,
V_19 -> V_65 ) ;
else
V_8 -> V_95 = V_19 ;
return V_53 ;
}
static int F_69 ( struct V_51 * V_52 , struct V_18 * V_19 ,
struct V_13 * V_16 )
{
int V_53 = 0 ;
if ( F_25 ( & V_16 -> V_2 . V_5 ) ) {
V_53 = F_66 ( V_52 , V_19 , V_16 ) ;
if ( V_53 )
return V_53 ;
}
if ( F_70 ( V_52 ,
V_96 . V_97 ) )
V_53 = F_67 ( V_19 , V_16 ) ;
return V_53 ;
}
struct V_18 * F_71 ( struct V_14 * V_15 ,
int V_16 ,
int V_82 )
{
struct V_18 * V_98 = NULL ;
struct V_18 * V_19 ;
int V_53 ;
int V_99 ;
struct V_49 * V_8 =
F_32 ( & V_15 -> V_2 ) ;
struct V_13 * V_13 = NULL ;
if ( ! V_8 ) {
F_72 ( L_9 ) ;
return F_51 ( - V_100 ) ;
}
F_12 ( & V_8 -> V_101 ) ;
V_13 = F_22 ( V_15 , V_16 ) ;
if ( ! V_13 ) {
V_53 = - V_102 ;
goto V_103;
}
if ( V_13 -> V_54 == V_13 -> V_104 ) {
V_53 = - V_105 ;
goto V_103;
}
V_19 = F_54 ( F_24 ( V_13 ) ,
F_73 ( V_82 ) ,
V_8 -> V_84 ) ;
if ( ! V_19 ) {
V_53 = - V_73 ;
goto V_103;
}
F_1 ( & V_19 -> V_2 , 1 , F_37 ) ;
V_99 = F_74 ( V_19 -> V_82 ) ;
V_98 = F_60 ( V_13 ) ;
V_53 = F_75 ( V_8 -> V_52 , V_19 -> type , V_19 -> V_20 ,
V_99 , V_98 , & V_19 -> V_65 ) ;
if ( V_53 )
goto V_106;
V_53 = F_69 ( V_8 -> V_52 , V_19 , V_13 ) ;
if ( V_53 )
goto V_107;
F_11 ( & V_13 -> V_2 ) ;
F_6 ( & V_19 -> V_2 , & V_13 -> V_2 ) ;
F_76 ( & V_19 -> V_2 . V_4 , & V_13 -> V_2 . V_5 ) ;
V_13 -> V_54 ++ ;
F_13 ( & V_13 -> V_2 ) ;
F_15 ( & V_8 -> V_101 ) ;
return V_19 ;
V_107:
F_39 ( V_8 -> V_52 , V_19 ) ;
V_106:
F_19 ( V_19 ) ;
V_103:
F_15 ( & V_8 -> V_101 ) ;
return F_51 ( V_53 ) ;
}
struct V_18 * F_77 ( struct V_14 * V_15 ,
int V_16 ,
int V_108 ,
int V_109 )
{
struct V_18 * V_19 ;
if ( V_109 > V_108 )
return F_51 ( - V_102 ) ;
V_19 = F_71 ( V_15 , V_16 , V_108 ) ;
if ( F_78 ( V_19 ) )
return V_19 ;
V_19 -> V_110 . V_111 = true ;
V_19 -> V_110 . V_112 = V_109 ;
return V_19 ;
}
static struct V_57 * F_79 ( struct V_18 * V_19 ,
T_2 * V_113 ,
struct V_86
* V_114 ,
bool V_115 )
{
struct V_57 * V_58 ;
struct V_51 * V_52 = F_36 ( & V_19 -> V_2 ) ;
int V_53 ;
if ( ! V_52 )
return F_51 ( - V_100 ) ;
V_58 = F_52 ( V_113 ) ;
if ( F_78 ( V_58 ) )
return V_58 ;
V_53 = F_80 ( V_52 , V_19 , V_113 , & V_58 -> V_65 ) ;
if ( V_53 ) {
F_19 ( V_58 ) ;
return F_51 ( V_53 ) ;
}
if ( V_19 -> V_110 . V_111 )
V_19 -> V_110 . V_116 ++ ;
F_1 ( & V_58 -> V_2 , ! V_115 , F_47 ) ;
F_6 ( & V_58 -> V_2 , & V_19 -> V_2 ) ;
F_81 ( & V_58 -> V_2 . V_4 , V_19 -> V_2 . V_5 . V_117 ) ;
return V_58 ;
}
struct V_57 * F_82 ( struct V_18 * V_19 ,
T_2 * V_113 )
{
struct V_57 * V_58 ;
if ( V_19 -> V_110 . V_111 )
return F_51 ( - V_12 ) ;
F_11 ( & V_19 -> V_2 ) ;
V_58 = F_79 ( V_19 , V_113 , & V_19 -> V_2 . V_5 , false ) ;
F_13 ( & V_19 -> V_2 ) ;
return V_58 ;
}
static struct V_55 * F_83 ( struct V_118 * V_119 )
{
struct V_55 * V_56 ;
V_56 = F_50 ( sizeof( * V_56 ) , V_72 ) ;
if ( ! V_56 )
return NULL ;
V_56 -> V_2 . type = V_120 ;
memcpy ( & V_56 -> V_121 , V_119 , sizeof( * V_119 ) ) ;
return V_56 ;
}
static struct V_55 * F_84 ( struct V_59 * V_60 ,
struct V_57 * V_58 ,
struct V_118 * V_119 )
{
struct V_18 * V_19 ;
struct V_55 * V_56 ;
int V_53 ;
V_56 = F_83 ( V_119 ) ;
if ( ! V_56 )
return F_51 ( - V_73 ) ;
F_38 ( V_19 , V_58 -> V_2 . V_7 ) ;
F_1 ( & V_56 -> V_2 , 1 , F_40 ) ;
F_76 ( & V_56 -> V_2 . V_4 , & V_60 -> V_2 . V_5 ) ;
V_60 -> V_64 ++ ;
if ( V_60 -> V_64 == 1 )
V_53 = F_85 ( F_36 ( & V_19 -> V_2 ) ,
V_19 , V_58 -> V_65 , V_60 ) ;
else
V_53 = F_43 ( F_36 ( & V_19 -> V_2 ) ,
V_19 , V_58 -> V_65 , V_60 ) ;
if ( V_53 )
goto V_122;
V_60 -> V_68 |= V_123 ;
return V_56 ;
V_122:
F_42 ( & V_56 -> V_2 . V_4 ) ;
F_19 ( V_56 ) ;
V_60 -> V_64 -- ;
return F_51 ( V_53 ) ;
}
static unsigned int F_86 ( struct V_57 * V_58 ,
struct V_86 * * V_117 )
{
struct V_59 * V_60 ;
unsigned int V_87 = V_58 -> V_78 ;
if ( V_117 )
* V_117 = & V_58 -> V_2 . V_5 ;
F_87 (fte, fg) {
if ( V_60 -> V_67 != V_87 )
return V_87 ;
V_87 ++ ;
if ( V_117 )
* V_117 = & V_60 -> V_2 . V_4 ;
}
return V_87 ;
}
static struct V_59 * F_88 ( struct V_57 * V_58 ,
T_2 * V_61 ,
V_27 V_70 ,
T_2 V_71 ,
struct V_86 * * V_117 )
{
struct V_59 * V_60 ;
int V_67 ;
V_67 = F_86 ( V_58 , V_117 ) ;
V_60 = F_49 ( V_70 , V_71 , V_61 , V_67 ) ;
if ( F_78 ( V_60 ) )
return V_60 ;
return V_60 ;
}
static struct V_57 * F_89 ( struct V_18 * V_19 ,
V_27 V_31 ,
T_2 * V_38 )
{
int V_124 = F_30 ( V_76 ) ;
struct V_86 * V_117 = & V_19 -> V_2 . V_5 ;
unsigned int V_125 = 0 ;
struct V_57 * V_58 ;
void * V_126 ;
unsigned int V_127 = 0 ;
T_2 * V_128 ;
if ( ! V_19 -> V_110 . V_111 )
return F_51 ( - V_129 ) ;
V_128 = F_41 ( V_124 ) ;
if ( ! V_128 )
return F_51 ( - V_73 ) ;
if ( V_19 -> V_110 . V_116 < V_19 -> V_110 . V_112 )
V_127 = V_19 -> V_82 / ( V_19 -> V_110 . V_112 + 1 ) ;
if ( V_127 == 0 )
V_127 = 1 ;
F_90 (fg, ft) {
if ( V_125 + V_127 > V_58 -> V_78 )
V_125 = V_58 -> V_78 + V_58 -> V_80 ;
else
break;
V_117 = & V_58 -> V_2 . V_4 ;
}
if ( V_125 + V_127 > V_19 -> V_82 ) {
V_58 = F_51 ( - V_105 ) ;
goto V_130;
}
F_91 ( V_76 , V_128 , V_31 ,
V_31 ) ;
F_91 ( V_76 , V_128 , V_79 , V_125 ) ;
F_91 ( V_76 , V_128 , V_81 , V_125 +
V_127 - 1 ) ;
V_126 = F_29 ( V_76 ,
V_128 , V_38 ) ;
memcpy ( V_126 , V_38 ,
F_30 ( V_34 ) ) ;
V_58 = F_79 ( V_19 , V_128 , V_117 , true ) ;
V_130:
F_44 ( V_128 ) ;
return V_58 ;
}
static struct V_55 * F_92 ( struct V_57 * V_58 ,
T_2 * V_61 ,
V_27 V_70 ,
T_2 V_71 ,
struct V_118 * V_119 )
{
struct V_59 * V_60 ;
struct V_55 * V_56 ;
struct V_18 * V_19 ;
struct V_86 * V_117 ;
F_9 ( & V_58 -> V_2 , V_131 ) ;
F_87 (fte, fg) {
F_9 ( & V_60 -> V_2 , V_132 ) ;
if ( F_28 ( & V_58 -> V_22 , V_61 , & V_60 -> V_63 ) &&
V_70 == V_60 -> V_70 && V_71 == V_60 -> V_71 ) {
V_56 = F_84 ( V_60 , V_58 , V_119 ) ;
F_13 ( & V_60 -> V_2 ) ;
if ( F_78 ( V_56 ) )
goto V_133;
else
goto V_134;
}
F_13 ( & V_60 -> V_2 ) ;
}
F_38 ( V_19 , V_58 -> V_2 . V_7 ) ;
if ( V_58 -> V_69 >= V_58 -> V_80 ) {
V_56 = F_51 ( - V_105 ) ;
goto V_133;
}
V_60 = F_88 ( V_58 , V_61 , V_70 , V_71 , & V_117 ) ;
if ( F_78 ( V_60 ) ) {
V_56 = ( void * ) V_60 ;
goto V_133;
}
F_1 ( & V_60 -> V_2 , 0 , F_45 ) ;
V_56 = F_84 ( V_60 , V_58 , V_119 ) ;
if ( F_78 ( V_56 ) ) {
F_19 ( V_60 ) ;
goto V_133;
}
V_58 -> V_69 ++ ;
F_6 ( & V_60 -> V_2 , & V_58 -> V_2 ) ;
F_81 ( & V_60 -> V_2 . V_4 , V_117 ) ;
V_134:
F_6 ( & V_56 -> V_2 , & V_60 -> V_2 ) ;
V_133:
F_13 ( & V_58 -> V_2 ) ;
return V_56 ;
}
static struct V_55 * F_93 ( struct V_18 * V_19 ,
V_27 V_31 ,
T_2 * V_38 ,
T_2 * V_61 ,
V_27 V_70 ,
T_2 V_71 ,
struct V_118 * V_119 )
{
struct V_55 * V_56 ;
struct V_57 * V_135 ;
V_135 = F_89 ( V_19 , V_31 , V_38 ) ;
if ( F_78 ( V_135 ) )
return ( void * ) V_135 ;
V_56 = F_92 ( V_135 , V_61 ,
V_70 , V_71 , V_119 ) ;
if ( F_78 ( V_56 ) ) {
F_8 ( & V_135 -> V_2 ) ;
F_20 ( & V_135 -> V_2 ) ;
}
return V_56 ;
}
struct V_55 *
F_94 ( struct V_18 * V_19 ,
V_27 V_31 ,
T_2 * V_38 ,
T_2 * V_61 ,
T_2 V_70 ,
T_2 V_71 ,
struct V_118 * V_119 )
{
struct V_57 * V_135 ;
struct V_55 * V_56 ;
F_9 ( & V_19 -> V_2 , V_136 ) ;
F_90 (g, ft)
if ( F_31 ( V_135 -> V_22 . V_31 ,
V_31 ,
V_135 -> V_22 . V_38 ,
V_38 ) ) {
V_56 = F_92 ( V_135 , V_61 ,
V_70 , V_71 , V_119 ) ;
if ( ! F_78 ( V_56 ) || F_95 ( V_56 ) != - V_105 )
goto V_137;
}
V_56 = F_93 ( V_19 , V_31 , V_38 ,
V_61 , V_70 , V_71 , V_119 ) ;
V_137:
F_13 ( & V_19 -> V_2 ) ;
return V_56 ;
}
void F_96 ( struct V_55 * V_56 )
{
F_20 ( & V_56 -> V_2 ) ;
}
static struct V_18 * F_97 ( struct V_18 * V_19 )
{
struct V_13 * V_16 ;
F_38 ( V_16 , V_19 -> V_2 . V_7 ) ;
if ( ! F_98 ( & V_19 -> V_2 . V_4 , & V_16 -> V_2 . V_5 ) )
return F_99 ( V_19 , V_2 . V_4 ) ;
return F_60 ( V_16 ) ;
}
static int F_100 ( struct V_18 * V_19 )
{
struct V_49 * V_8 = F_32 ( & V_19 -> V_2 ) ;
struct V_18 * V_138 = NULL ;
if ( V_8 -> V_95 != V_19 )
return 0 ;
V_138 = F_97 ( V_19 ) ;
if ( V_138 ) {
int V_53 = F_68 ( V_8 -> V_52 , V_138 ) ;
if ( V_53 ) {
F_65 ( V_8 -> V_52 , L_8 ,
V_19 -> V_65 ) ;
return V_53 ;
}
V_8 -> V_95 = V_138 ;
}
return 0 ;
}
static int F_101 ( struct V_18 * V_19 )
{
struct V_51 * V_52 = F_36 ( & V_19 -> V_2 ) ;
struct V_18 * V_98 ;
struct V_13 * V_16 ;
int V_53 = 0 ;
V_53 = F_100 ( V_19 ) ;
if ( V_53 )
return V_53 ;
F_38 ( V_16 , V_19 -> V_2 . V_7 ) ;
if ( ! ( F_102 ( & V_16 -> V_2 . V_5 ,
struct V_18 ,
V_2 . V_4 ) == V_19 ) )
return 0 ;
V_98 = F_60 ( V_16 ) ;
V_53 = F_66 ( V_52 , V_98 , V_16 ) ;
if ( V_53 )
F_65 ( V_52 , L_10 ,
V_19 -> V_65 ) ;
return V_53 ;
}
int F_103 ( struct V_18 * V_19 )
{
struct V_49 * V_8 = F_32 ( & V_19 -> V_2 ) ;
int V_53 = 0 ;
F_12 ( & V_8 -> V_101 ) ;
V_53 = F_101 ( V_19 ) ;
if ( V_53 ) {
F_15 ( & V_8 -> V_101 ) ;
return V_53 ;
}
if ( F_20 ( & V_19 -> V_2 ) )
F_65 ( F_36 ( & V_19 -> V_2 ) , L_11 ,
V_19 -> V_65 ) ;
F_15 ( & V_8 -> V_101 ) ;
return V_53 ;
}
void F_104 ( struct V_57 * V_58 )
{
if ( F_20 ( & V_58 -> V_2 ) )
F_65 ( F_36 ( & V_58 -> V_2 ) , L_12 ,
V_58 -> V_65 ) ;
}
struct V_14 * F_105 ( struct V_51 * V_52 ,
enum V_139 type )
{
struct V_49 * V_140 = V_52 -> V_141 . V_140 ;
int V_16 ;
static struct V_13 * V_13 ;
struct V_14 * V_15 ;
if ( ! V_140 )
return NULL ;
switch ( type ) {
case V_142 :
case V_143 :
case V_144 :
V_16 = type ;
break;
case V_145 :
if ( V_52 -> V_141 . V_146 )
return & V_52 -> V_141 . V_146 -> V_15 ;
else
return NULL ;
default:
return NULL ;
}
V_13 = F_22 ( & V_140 -> V_15 , V_16 ) ;
if ( ! V_13 )
return NULL ;
V_15 = F_102 ( & V_13 -> V_2 . V_5 ,
F_106 ( * V_15 ) ,
V_2 . V_4 ) ;
return V_15 ;
}
static struct V_13 * F_107 ( struct V_14 * V_15 ,
unsigned V_16 , int V_104 )
{
struct V_13 * V_13 ;
V_13 = F_50 ( sizeof( * V_13 ) , V_72 ) ;
if ( ! V_13 )
return F_51 ( - V_73 ) ;
V_13 -> V_2 . type = V_147 ;
F_1 ( & V_13 -> V_2 , 1 , NULL ) ;
F_6 ( & V_13 -> V_2 , & V_15 -> V_2 ) ;
V_13 -> V_104 = V_104 ;
V_13 -> V_16 = V_16 ;
F_76 ( & V_13 -> V_2 . V_4 , & V_15 -> V_2 . V_5 ) ;
return V_13 ;
}
static struct V_14 * F_108 ( struct V_14
* V_15 )
{
V_15 -> V_2 . type = V_50 ;
return V_15 ;
}
static struct V_14 * F_109 ( struct V_13 * V_16 )
{
struct V_14 * V_15 ;
V_15 = F_50 ( sizeof( * V_15 ) , V_72 ) ;
if ( ! V_15 )
return F_51 ( - V_73 ) ;
F_108 ( V_15 ) ;
F_1 ( & V_15 -> V_2 , 1 , NULL ) ;
F_6 ( & V_15 -> V_2 , & V_16 -> V_2 ) ;
F_76 ( & V_15 -> V_2 . V_4 , & V_16 -> V_2 . V_5 ) ;
return V_15 ;
}
static int F_110 ( struct V_14 * V_15 , struct V_148
* V_149 )
{
struct V_13 * V_13 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_149 -> V_150 ; V_26 ++ ) {
V_13 = F_107 ( V_15 , V_26 , V_149 -> V_104 ) ;
if ( F_78 ( V_13 ) )
return F_95 ( V_13 ) ;
}
return 0 ;
}
static bool F_111 ( struct V_51 * V_52 , struct V_151 * V_152 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_152 -> V_153 ; V_26 ++ ) {
if ( ! F_112 ( V_52 , V_152 -> V_152 [ V_26 ] ) )
return false ;
}
return true ;
}
static int F_113 ( struct V_51 * V_52 ,
struct V_148 * V_154 ,
struct V_1 * V_155 ,
struct V_148 * V_156 ,
int V_67 )
{
int V_157 = F_70 ( V_52 ,
V_96 .
V_157 ) ;
struct V_14 * V_158 ;
struct V_13 * V_13 ;
struct V_1 * V_159 ;
int V_26 ;
int V_53 ;
if ( V_154 -> type == V_147 ) {
if ( ( V_154 -> V_160 > V_157 ) ||
! F_111 ( V_52 , & V_154 -> V_152 ) )
return 0 ;
F_38 ( V_158 , V_155 ) ;
if ( V_154 -> V_150 )
return F_110 ( V_158 , V_154 ) ;
V_13 = F_107 ( V_158 , V_67 , V_154 -> V_104 ) ;
if ( F_78 ( V_13 ) )
return F_95 ( V_13 ) ;
V_159 = & V_13 -> V_2 ;
} else if ( V_154 -> type == V_50 ) {
F_38 ( V_13 , V_155 ) ;
V_158 = F_109 ( V_13 ) ;
if ( F_78 ( V_158 ) )
return F_95 ( V_158 ) ;
V_159 = & V_158 -> V_2 ;
} else {
return - V_102 ;
}
for ( V_26 = 0 ; V_26 < V_154 -> V_161 ; V_26 ++ ) {
V_53 = F_113 ( V_52 , & V_154 -> V_5 [ V_26 ] ,
V_159 , V_154 , V_26 ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
static int F_114 ( struct V_51 * V_52 ,
struct V_148 * V_154 ,
struct V_1 * V_155 )
{
int V_26 ;
struct V_14 * V_158 ;
int V_53 ;
F_38 ( V_158 , V_155 ) ;
for ( V_26 = 0 ; V_26 < V_154 -> V_161 ; V_26 ++ ) {
V_53 = F_113 ( V_52 , & V_154 -> V_5 [ V_26 ] ,
& V_158 -> V_2 ,
V_154 , V_26 ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
static struct V_49 * F_115 ( struct V_51 * V_52 ,
enum V_83
V_84 )
{
struct V_49 * V_140 ;
struct V_14 * V_15 ;
V_140 = F_41 ( sizeof( * V_140 ) ) ;
if ( ! V_140 )
return NULL ;
V_140 -> V_52 = V_52 ;
V_140 -> V_84 = V_84 ;
V_15 = & V_140 -> V_15 ;
F_108 ( V_15 ) ;
F_5 ( & V_140 -> V_101 ) ;
F_1 ( & V_15 -> V_2 , 1 , NULL ) ;
F_6 ( & V_15 -> V_2 , NULL ) ;
return V_140 ;
}
static int F_116 ( struct V_14 * V_15 , int V_162 )
{
struct V_13 * V_16 ;
F_23 (prio, ns) {
F_117 ( V_16 , V_162 ) ;
V_162 += V_16 -> V_104 ;
}
return V_162 ;
}
static void F_117 ( struct V_13 * V_16 , int V_162 )
{
struct V_14 * V_15 ;
int V_163 = V_162 ;
V_16 -> V_21 = V_162 ;
F_118 (ns, prio)
V_163 = F_116 ( V_15 , V_162 ) ;
if ( ! V_16 -> V_104 )
V_16 -> V_104 = V_163 - V_16 -> V_21 ;
F_33 ( V_16 -> V_104 < V_163 - V_16 -> V_21 ) ;
}
static void F_119 ( struct V_49 * V_140 )
{
struct V_14 * V_15 = & V_140 -> V_15 ;
struct V_13 * V_16 ;
int V_21 = 0 ;
F_23 (prio, ns) {
F_117 ( V_16 , V_21 ) ;
V_21 += V_16 -> V_104 ;
}
}
static int F_120 ( struct V_51 * V_52 )
{
V_52 -> V_141 . V_140 = F_115 ( V_52 , V_164 ) ;
if ( F_121 ( V_52 -> V_141 . V_140 ) )
goto V_165;
if ( F_114 ( V_52 , & V_166 , & V_52 -> V_141 . V_140 -> V_15 . V_2 ) )
goto V_165;
F_119 ( V_52 -> V_141 . V_140 ) ;
return 0 ;
V_165:
F_122 ( V_52 ) ;
return - V_73 ;
}
static void F_123 ( struct V_51 * V_52 ,
struct V_49 * V_140 )
{
struct V_1 * V_16 ;
if ( ! V_140 )
return;
if ( ! F_25 ( & V_140 -> V_15 . V_2 . V_5 ) ) {
V_16 = F_102 ( & V_140 -> V_15 . V_2 . V_5 ,
struct V_1 ,
V_4 ) ;
if ( F_20 ( V_16 ) )
F_65 ( V_52 ,
L_13 ) ;
}
if ( F_20 ( & V_140 -> V_15 . V_2 ) )
F_65 ( V_52 ,
L_14 ) ;
V_140 = NULL ;
}
static void F_124 ( struct V_51 * V_52 )
{
struct V_49 * V_140 = V_52 -> V_141 . V_140 ;
struct V_13 * V_17 ;
if ( ! F_125 ( V_52 , V_167 ) )
return;
if ( ! V_140 )
return;
F_23 (iter_prio, &root_ns->ns) {
struct V_1 * V_2 ;
struct V_14 * V_168 ;
F_126 (node, iter_prio) {
if ( V_2 -> type == V_85 )
continue;
F_38 ( V_168 , V_2 ) ;
while ( ! F_25 ( & V_168 -> V_2 . V_5 ) ) {
struct V_13 * V_169 ;
struct V_1 * V_170 =
F_102 ( & V_168 -> V_2 . V_5 ,
struct V_1 ,
V_4 ) ;
F_38 ( V_169 , V_170 ) ;
if ( F_20 ( V_170 ) ) {
F_65 ( V_52 ,
L_15 ,
V_169 -> V_16 ) ;
return;
}
}
}
}
F_23 (iter_prio, &root_ns->ns) {
while ( ! F_25 ( & V_17 -> V_2 . V_5 ) ) {
struct V_1 * V_168 =
F_102 ( & V_17 -> V_2 . V_5 ,
struct V_1 ,
V_4 ) ;
if ( F_20 ( V_168 ) ) {
F_65 ( V_52 ,
L_16 ) ;
return;
}
}
}
while ( ! F_25 ( & V_140 -> V_15 . V_2 . V_5 ) ) {
struct V_13 * V_171 ;
struct V_1 * V_172 =
F_102 ( & V_140 -> V_15 . V_2 . V_5 ,
struct V_1 ,
V_4 ) ;
F_38 ( V_171 , V_172 ) ;
if ( F_20 ( V_172 ) ) {
F_65 ( V_52 ,
L_15 ,
V_171 -> V_16 ) ;
return;
}
}
if ( F_20 ( & V_140 -> V_15 . V_2 ) ) {
F_65 ( V_52 ,
L_17 ) ;
return;
}
V_52 -> V_141 . V_140 = NULL ;
}
void F_122 ( struct V_51 * V_52 )
{
F_124 ( V_52 ) ;
F_123 ( V_52 , V_52 -> V_141 . V_146 ) ;
}
static int F_127 ( struct V_51 * V_52 )
{
struct V_13 * V_16 ;
V_52 -> V_141 . V_146 = F_115 ( V_52 , V_173 ) ;
if ( ! V_52 -> V_141 . V_146 )
return - V_73 ;
V_16 = F_107 ( & V_52 -> V_141 . V_146 -> V_15 , 0 , 1 ) ;
if ( F_78 ( V_16 ) ) {
F_123 ( V_52 , V_52 -> V_141 . V_146 ) ;
return F_95 ( V_16 ) ;
} else {
return 0 ;
}
}
int F_128 ( struct V_51 * V_52 )
{
int V_53 = 0 ;
if ( F_125 ( V_52 , V_167 ) ) {
V_53 = F_120 ( V_52 ) ;
if ( V_53 )
return V_53 ;
}
if ( F_125 ( V_52 , V_174 ) ) {
V_53 = F_127 ( V_52 ) ;
if ( V_53 )
F_124 ( V_52 ) ;
}
return V_53 ;
}
