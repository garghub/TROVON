static void F_1 ( T_1 V_1 , T_1 V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( V_1 , V_5 ) ;
F_4 () ;
F_3 ( V_2 , V_6 ) ;
F_4 () ;
F_5 ( & V_4 , V_3 ) ;
}
static T_1 F_6 ( T_1 V_1 )
{
T_1 V_2 ;
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
F_3 ( V_1 , V_5 ) ;
F_4 () ;
V_2 = F_7 ( V_6 ) ;
F_5 ( & V_4 , V_3 ) ;
return V_2 ;
}
static inline T_2 F_8 ( T_2 V_7 )
{
if ( V_7 == V_8 )
return F_9 ( V_9 ) ;
return F_9 ( V_7 ) ;
}
static inline struct V_10 * F_10 (
struct V_11 * V_11 , int V_12 )
{
return * F_11 ( V_11 -> V_13 , V_12 ) ;
}
static void F_12 ( void )
{
F_1 ( V_14 , V_15 ) ;
F_1 ( V_16 , V_17 ) ;
F_1 ( V_18 , V_17 ) ;
F_1 ( V_19 , V_17 ) ;
}
static inline void F_13 ( void )
{
F_1 ( V_14 , V_20 ) ;
}
static inline void F_14 ( void )
{
F_1 ( V_14 , V_21 ) ;
}
static inline void F_15 ( T_2 V_7 , T_1 V_22 )
{
if ( V_7 == V_8 )
F_1 ( V_23 , V_22 ) ;
else
F_1 ( F_16 ( V_24 , V_7 ) , V_22 ) ;
}
static inline T_1 F_17 ( T_2 V_7 )
{
T_1 V_22 ;
if ( V_7 == V_8 )
V_22 = F_6 ( V_23 ) ;
else
V_22 = F_6 ( F_16 ( V_24 , V_7 ) ) ;
return V_22 ;
}
static inline void F_18 ( T_2 V_7 )
{
F_1 ( V_25 , F_8 ( V_7 ) ) ;
}
static inline void F_19 ( T_2 V_7 )
{
F_1 ( V_16 , F_8 ( V_7 ) ) ;
}
static inline void F_20 ( T_2 V_7 )
{
F_1 ( V_26 , F_8 ( V_7 ) ) ;
}
static inline void F_21 ( T_2 V_7 )
{
F_1 ( V_18 , F_8 ( V_7 ) ) ;
}
static inline void F_22 ( T_2 V_2 )
{
F_1 ( V_27 , V_2 ) ;
}
static inline void F_23 ( T_2 V_28 , T_2 V_2 )
{
F_1 ( F_16 ( V_29 , V_28 ) , V_2 ) ;
}
static inline void F_24 ( T_2 V_28 , T_2 V_2 )
{
F_1 ( F_16 ( V_30 , V_28 ) , V_2 ) ;
}
static void F_25 ( struct V_10 * V_31 ,
T_2 V_32 , T_2 V_33 )
{
T_1 V_34 ;
T_1 V_35 ;
T_2 V_36 ;
unsigned long V_3 ;
V_36 = V_37 * V_32 ;
V_34 = ( ( T_1 ) ( V_33 & V_38 ) << V_36 ) ;
F_26 ( & V_31 -> V_39 , V_3 ) ;
V_35 = F_6 ( V_40 ) ;
V_35 &= ~ ( V_38 << V_36 ) ;
V_35 |= V_34 ;
V_35 |= V_41 ;
F_1 ( V_40 , V_35 ) ;
F_27 ( & V_31 -> V_39 , V_3 ) ;
}
static inline void F_28 ( T_2 V_28 )
{
T_2 V_2 = V_42 |
V_43 |
V_44 ;
F_1 ( F_16 ( V_45 , V_28 ) , V_2 ) ;
}
static inline T_2 F_29 ( void )
{
T_2 V_46 = F_6 ( V_47 ) ;
F_1 ( V_19 , V_46 ) ;
return V_46 ;
}
static inline bool F_30 ( T_2 V_48 )
{
return ! ! ( V_48 & V_17 ) ;
}
static inline bool F_31 ( T_2 V_48 , T_2 V_7 )
{
return ! ! ( V_48 & F_8 ( V_7 ) ) ;
}
static void F_32 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = & V_50 -> V_53 ;
T_1 V_54 , V_55 , V_56 ;
T_2 V_7 = V_52 -> V_7 ;
do {
V_55 = F_33 ( & V_52 -> V_57 ) ;
V_56 = F_17 ( V_7 ) ;
} while ( F_34 ( & V_52 -> V_57 , V_55 , V_56 ) != V_55 );
V_54 = V_56 - V_55 ;
if ( V_7 != V_8 )
V_54 &= 0xffffffff ;
F_35 ( V_54 , & V_50 -> V_58 ) ;
}
static void F_36 ( struct V_10 * V_31 ,
struct V_51 * V_52 )
{
T_2 V_7 = V_52 -> V_7 ;
T_1 V_59 ;
if ( V_7 == V_8 )
V_59 = V_60 ;
else
V_59 = V_61 ;
F_37 ( & V_52 -> V_57 , V_59 ) ;
F_15 ( V_7 , V_59 ) ;
}
static int F_38 ( struct V_10 * V_31 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = & V_50 -> V_53 ;
int V_7 ;
int V_62 = V_31 -> V_11 -> V_63 - 1 ;
unsigned int V_64 ;
if ( V_52 -> V_65 == V_66 ) {
if ( F_39 ( V_8 , V_31 -> V_67 ) )
return - V_68 ;
return V_8 ;
}
V_7 = F_40 ( V_31 -> V_67 , V_62 ) ;
if ( V_7 == V_62 )
return - V_68 ;
V_64 = F_41 ( V_52 -> V_65 ) ;
if ( F_42 ( V_64 , V_31 -> V_69 ) )
return - V_68 ;
F_43 ( V_7 , V_31 -> V_67 ) ;
F_43 ( V_64 , V_31 -> V_69 ) ;
return V_7 ;
}
static void F_44 ( struct V_10 * V_31 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = & V_50 -> V_53 ;
int V_7 = V_52 -> V_7 ;
F_45 ( V_7 , V_31 -> V_67 ) ;
if ( V_52 -> V_65 != V_66 )
F_45 ( F_41 ( V_52 -> V_65 ) , V_31 -> V_69 ) ;
}
static T_3 F_46 ( int V_70 , void * V_71 )
{
struct V_10 * V_31 = V_71 ;
int V_63 = V_31 -> V_11 -> V_63 ;
T_2 V_48 ;
int V_7 ;
V_48 = F_29 () ;
if ( ! F_30 ( V_48 ) )
return V_72 ;
F_47 (idx, cluster->used_counters, num_counters) {
struct V_49 * V_50 = V_31 -> V_73 [ V_7 ] ;
struct V_51 * V_52 ;
if ( F_48 ( ! V_50 ) )
continue;
if ( ! F_31 ( V_48 , V_7 ) )
continue;
F_32 ( V_50 ) ;
V_52 = & V_50 -> V_53 ;
F_36 ( V_31 , V_52 ) ;
}
return V_74 ;
}
static void F_49 ( struct V_75 * V_75 )
{
F_13 () ;
}
static void F_50 ( struct V_75 * V_75 )
{
F_14 () ;
}
static int F_51 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = & V_50 -> V_53 ;
struct V_10 * V_31 ;
struct V_49 * V_76 ;
struct V_11 * V_11 ;
if ( V_50 -> V_77 . type != V_50 -> V_75 -> type )
return - V_78 ;
V_11 = F_52 ( V_50 -> V_75 ) ;
if ( V_52 -> V_79 ) {
F_53 ( & V_11 -> V_80 -> V_81 ,
L_1 ) ;
return - V_82 ;
}
if ( V_50 -> V_12 < 0 ) {
F_53 ( & V_11 -> V_80 -> V_81 ,
L_2 ) ;
return - V_82 ;
}
if ( V_50 -> V_77 . V_83 || V_50 -> V_77 . V_84 ||
V_50 -> V_77 . V_85 || V_50 -> V_77 . V_86 ) {
F_53 ( & V_11 -> V_80 -> V_81 ,
L_3 ) ;
return - V_82 ;
}
if ( ( ( F_41 ( V_50 -> V_77 . V_87 ) > V_88 ) ||
( ( V_50 -> V_77 . V_87 & ~ V_89 ) != 0 ) ) &&
( V_50 -> V_77 . V_87 != V_66 ) ) {
F_53 ( & V_11 -> V_80 -> V_81 ,
L_4 ,
V_50 -> V_77 . V_87 ) ;
return - V_90 ;
}
if ( V_50 -> V_91 -> V_75 != V_50 -> V_75 &&
! F_54 ( V_50 -> V_91 ) ) {
F_53 ( & V_11 -> V_80 -> V_81 ,
L_5 ) ;
return - V_90 ;
}
F_55 (sibling, &event->group_leader->sibling_list,
group_entry)
if ( V_76 -> V_75 != V_50 -> V_75 &&
! F_54 ( V_76 ) ) {
F_53 ( & V_11 -> V_80 -> V_81 ,
L_5 ) ;
return - V_90 ;
}
V_31 = F_10 ( V_11 , V_50 -> V_12 ) ;
if ( ! V_31 ) {
F_53 ( & V_11 -> V_80 -> V_81 ,
L_6 , V_50 -> V_12 ) ;
return - V_90 ;
}
if ( ( V_50 -> V_91 != V_50 ) &&
( V_31 -> V_92 != V_50 -> V_91 -> V_12 ) ) {
F_53 ( & V_11 -> V_80 -> V_81 ,
L_7 ,
V_50 -> V_12 , V_50 -> V_91 -> V_12 ) ;
return - V_90 ;
}
if ( ( V_50 != V_50 -> V_91 ) &&
( F_41 ( V_50 -> V_91 -> V_77 . V_87 ) ==
F_41 ( V_50 -> V_77 . V_87 ) ) ) {
F_53 ( & V_11 -> V_80 -> V_81 ,
L_8 ,
V_50 -> V_91 -> V_77 . V_87 ,
V_50 -> V_77 . V_87 ) ;
return - V_90 ;
}
F_55 (sibling, &event->group_leader->sibling_list,
group_entry) {
if ( ( V_76 != V_50 ) &&
( F_41 ( V_76 -> V_77 . V_87 ) ==
F_41 ( V_50 -> V_77 . V_87 ) ) ) {
F_53 ( & V_11 -> V_80 -> V_81 ,
L_8 ,
V_76 -> V_77 . V_87 ,
V_50 -> V_77 . V_87 ) ;
return - V_90 ;
}
}
V_52 -> V_7 = - 1 ;
V_52 -> V_65 = V_50 -> V_77 . V_87 ;
V_50 -> V_12 = V_31 -> V_92 ;
return 0 ;
}
static void F_56 ( struct V_49 * V_50 , int V_3 )
{
struct V_10 * V_31 ;
struct V_51 * V_52 = & V_50 -> V_53 ;
int V_7 = V_52 -> V_7 ;
T_2 V_87 ;
T_2 V_33 , V_32 ;
V_52 -> V_93 = 0 ;
V_31 = F_10 ( F_52 ( V_50 -> V_75 ) , V_50 -> V_12 ) ;
F_36 ( V_31 , V_52 ) ;
if ( V_52 -> V_65 == V_66 ) {
F_22 ( 0 ) ;
} else {
V_87 = V_52 -> V_65 ;
V_33 = F_57 ( V_87 ) ;
V_32 = F_41 ( V_87 ) ;
F_23 ( V_7 , 0 ) ;
F_24 ( V_7 , V_32 ) ;
F_25 ( V_31 , V_32 , V_33 ) ;
F_28 ( V_7 ) ;
}
F_20 ( V_7 ) ;
F_18 ( V_7 ) ;
}
static void F_58 ( struct V_49 * V_50 , int V_3 )
{
struct V_51 * V_52 = & V_50 -> V_53 ;
int V_7 = V_52 -> V_7 ;
if ( V_52 -> V_93 & V_94 )
return;
F_21 ( V_7 ) ;
F_19 ( V_7 ) ;
if ( V_3 & V_95 )
F_32 ( V_50 ) ;
V_52 -> V_93 |= V_94 | V_96 ;
}
static int F_59 ( struct V_49 * V_50 , int V_3 )
{
struct V_51 * V_52 = & V_50 -> V_53 ;
int V_7 ;
int V_97 = 0 ;
struct V_10 * V_31 ;
V_31 = F_10 ( F_52 ( V_50 -> V_75 ) , V_50 -> V_12 ) ;
V_7 = F_38 ( V_31 , V_50 ) ;
if ( V_7 < 0 )
return V_7 ;
V_52 -> V_7 = V_7 ;
V_52 -> V_93 = V_94 | V_96 ;
V_31 -> V_73 [ V_7 ] = V_50 ;
F_37 ( & V_52 -> V_57 , 0 ) ;
if ( V_3 & V_98 )
F_56 ( V_50 , V_3 ) ;
F_60 ( V_50 ) ;
return V_97 ;
}
static void F_61 ( struct V_49 * V_50 , int V_3 )
{
struct V_51 * V_52 = & V_50 -> V_53 ;
struct V_10 * V_31 ;
int V_7 = V_52 -> V_7 ;
V_31 = F_10 ( F_52 ( V_50 -> V_75 ) , V_50 -> V_12 ) ;
F_58 ( V_50 , V_3 | V_95 ) ;
V_31 -> V_73 [ V_7 ] = NULL ;
F_44 ( V_31 , V_50 ) ;
F_60 ( V_50 ) ;
}
static void F_62 ( struct V_49 * V_50 )
{
F_32 ( V_50 ) ;
}
static T_4 F_63 ( struct V_99 * V_81 ,
struct V_100 * V_77 ,
char * V_101 )
{
struct V_11 * V_11 = F_52 ( F_64 ( V_81 ) ) ;
return F_65 ( true , V_101 , & V_11 -> V_102 ) ;
}
static int F_66 ( void )
{
int V_2 ;
V_2 = F_6 ( V_14 ) ;
return ( ( V_2 >> V_103 ) & V_104 ) + 1 ;
}
static struct V_10 * F_67 (
struct V_11 * V_11 , int V_12 )
{
T_1 V_105 ;
int V_106 ;
struct V_10 * V_31 = NULL ;
V_105 = F_68 () ;
if ( V_105 & V_107 )
V_106 = F_69 ( V_105 , 2 ) ;
else
V_106 = F_69 ( V_105 , 1 ) ;
F_55 (cluster, &l2cache_pmu->clusters, next) {
if ( V_31 -> V_108 != V_106 )
continue;
F_70 ( & V_11 -> V_80 -> V_81 ,
L_9 , V_12 ,
V_31 -> V_108 ) ;
F_71 ( V_12 , & V_31 -> V_109 ) ;
* F_11 ( V_11 -> V_13 , V_12 ) = V_31 ;
break;
}
return V_31 ;
}
static int F_72 ( unsigned int V_12 , struct V_110 * V_111 )
{
struct V_10 * V_31 ;
struct V_11 * V_11 ;
V_11 = F_73 ( V_111 , struct V_11 , V_111 ) ;
V_31 = F_10 ( V_11 , V_12 ) ;
if ( ! V_31 ) {
V_31 = F_67 ( V_11 , V_12 ) ;
if ( ! V_31 ) {
F_74 ( 1 , L_10 , V_12 ) ;
return 0 ;
}
}
if ( V_31 -> V_92 != - 1 )
return 0 ;
V_31 -> V_92 = V_12 ;
F_71 ( V_12 , & V_11 -> V_102 ) ;
F_12 () ;
F_75 ( F_76 ( V_31 -> V_112 , F_77 ( V_12 ) ) ) ;
F_78 ( V_31 -> V_112 ) ;
return 0 ;
}
static int F_79 ( unsigned int V_12 , struct V_110 * V_111 )
{
struct V_10 * V_31 ;
struct V_11 * V_11 ;
T_5 V_113 ;
unsigned int V_114 ;
V_11 = F_73 ( V_111 , struct V_11 , V_111 ) ;
V_31 = F_10 ( V_11 , V_12 ) ;
if ( ! V_31 )
return 0 ;
if ( V_31 -> V_92 != V_12 )
return 0 ;
F_80 ( V_12 , & V_11 -> V_102 ) ;
V_31 -> V_92 = - 1 ;
F_81 ( & V_113 , & V_31 -> V_109 ,
V_115 ) ;
V_114 = F_82 ( & V_113 , V_12 ) ;
if ( V_114 >= V_116 ) {
F_83 ( V_31 -> V_112 ) ;
return 0 ;
}
F_84 ( & V_11 -> V_75 , V_12 , V_114 ) ;
V_31 -> V_92 = V_114 ;
F_71 ( V_114 , & V_11 -> V_102 ) ;
F_75 ( F_76 ( V_31 -> V_112 , F_77 ( V_114 ) ) ) ;
return 0 ;
}
static int F_85 ( struct V_99 * V_81 , void * V_71 )
{
struct V_117 * V_80 = F_86 ( V_81 -> V_118 ) ;
struct V_117 * V_119 = F_86 ( V_81 ) ;
struct V_11 * V_11 = V_71 ;
struct V_10 * V_31 ;
struct V_120 * V_99 ;
unsigned long V_121 ;
int V_97 ;
int V_112 ;
if ( F_87 ( F_88 ( V_81 ) , & V_99 ) )
return - V_122 ;
if ( F_89 ( V_99 -> V_123 . V_124 , 10 , & V_121 ) < 0 ) {
F_90 ( & V_80 -> V_81 , L_11 ) ;
return - V_122 ;
}
V_31 = F_91 ( & V_80 -> V_81 , sizeof( * V_31 ) , V_125 ) ;
if ( ! V_31 )
return - V_126 ;
F_92 ( & V_31 -> V_127 ) ;
F_93 ( & V_31 -> V_127 , & V_11 -> V_128 ) ;
V_31 -> V_108 = V_121 ;
V_112 = F_94 ( V_119 , 0 ) ;
if ( V_112 < 0 ) {
F_90 ( & V_80 -> V_81 ,
L_12 ,
V_121 ) ;
return V_112 ;
}
F_95 ( V_112 , V_129 ) ;
V_31 -> V_112 = V_112 ;
V_31 -> V_11 = V_11 ;
V_31 -> V_92 = - 1 ;
V_97 = F_96 ( & V_80 -> V_81 , V_112 , F_46 ,
V_130 | V_131 ,
L_13 , V_31 ) ;
if ( V_97 ) {
F_90 ( & V_80 -> V_81 ,
L_14 , V_112 ) ;
return V_97 ;
}
F_70 ( & V_80 -> V_81 ,
L_15 , V_121 ) ;
F_97 ( & V_31 -> V_39 ) ;
V_11 -> V_132 ++ ;
return 0 ;
}
static int F_98 ( struct V_117 * V_80 )
{
int V_97 ;
struct V_11 * V_11 ;
V_11 =
F_91 ( & V_80 -> V_81 , sizeof( * V_11 ) , V_125 ) ;
if ( ! V_11 )
return - V_126 ;
F_92 ( & V_11 -> V_128 ) ;
F_99 ( V_80 , V_11 ) ;
V_11 -> V_75 = (struct V_75 ) {
. V_133 = L_16 ,
. V_134 = V_135 ,
. V_136 = F_49 ,
. V_137 = F_50 ,
. V_138 = F_51 ,
. V_139 = F_59 ,
. V_140 = F_61 ,
. V_141 = F_56 ,
. V_142 = F_58 ,
. V_143 = F_62 ,
. V_144 = V_145 ,
} ;
V_11 -> V_63 = F_66 () ;
V_11 -> V_80 = V_80 ;
V_11 -> V_13 = F_100 ( & V_80 -> V_81 ,
struct V_10 * ) ;
if ( ! V_11 -> V_13 )
return - V_126 ;
V_8 = V_11 -> V_63 - 1 ;
V_17 = F_101 ( V_11 -> V_63 - 2 , 0 ) |
F_9 ( V_9 ) ;
F_102 ( & V_11 -> V_102 ) ;
V_97 = F_103 ( & V_80 -> V_81 , V_11 ,
F_85 ) ;
if ( V_97 )
return V_97 ;
if ( V_11 -> V_132 == 0 ) {
F_90 ( & V_80 -> V_81 , L_17 ) ;
return - V_122 ;
}
V_97 = F_104 ( V_146 ,
& V_11 -> V_111 ) ;
if ( V_97 ) {
F_90 ( & V_80 -> V_81 , L_18 , V_97 ) ;
return V_97 ;
}
V_97 = F_105 ( & V_11 -> V_75 , V_11 -> V_75 . V_133 , - 1 ) ;
if ( V_97 ) {
F_90 ( & V_80 -> V_81 , L_19 , V_97 ) ;
goto V_147;
}
F_70 ( & V_80 -> V_81 , L_20 ,
V_11 -> V_132 ) ;
return V_97 ;
V_147:
F_106 ( V_146 ,
& V_11 -> V_111 ) ;
return V_97 ;
}
static int F_107 ( struct V_117 * V_80 )
{
struct V_11 * V_11 =
F_52 ( F_108 ( V_80 ) ) ;
F_109 ( & V_11 -> V_75 ) ;
F_106 ( V_146 ,
& V_11 -> V_111 ) ;
return 0 ;
}
static int T_6 F_110 ( void )
{
int V_97 ;
V_97 = F_111 ( V_146 ,
L_21 ,
F_72 ,
F_79 ) ;
if ( V_97 )
return V_97 ;
return F_112 ( & V_148 ) ;
}
