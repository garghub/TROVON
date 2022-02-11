static inline T_1 F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 . V_4 ) & V_5 ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 . V_4 & F_3 ( V_6 ) ) ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ? 2 : 1 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_6 ( V_2 -> V_9 ) ;
int V_10 = V_2 -> V_11 . V_10 ;
T_1 V_12 = F_1 ( V_2 ) ;
T_1 V_13 ;
V_13 = F_7 ( V_8 -> V_14 + V_15 ) ;
V_13 |= F_8 ( V_10 + 1 ) ;
F_9 ( V_13 , V_8 -> V_14 + V_15 ) ;
F_10 ( & V_2 -> V_11 . V_16 , 0 ) ;
F_9 ( 0 , V_8 -> V_14 + F_11 ( V_10 + 1 ) ) ;
F_9 ( 0 , V_8 -> V_14 + F_11 ( V_10 ) ) ;
F_9 ( F_12 ( 0 ) , V_8 -> V_14 + F_13 ( V_10 + 1 ) ) ;
F_9 ( F_12 ( V_12 ) , V_8 -> V_14 + F_13 ( V_10 ) ) ;
F_9 ( V_17 , V_8 -> V_14 + F_14 ( V_10 + 1 ) ) ;
F_9 ( F_15 ( V_10 + 1 ) , V_8 -> V_14 + V_18 ) ;
F_9 ( V_17 , V_8 -> V_14 + F_14 ( V_10 ) ) ;
F_9 ( F_15 ( V_10 ) , V_8 -> V_14 + V_18 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
int V_19 )
{
struct V_7 * V_8 = F_6 ( V_2 -> V_9 ) ;
int V_10 = V_2 -> V_11 . V_10 ;
T_1 V_13 = F_7 ( V_8 -> V_14 + V_15 ) ;
F_9 ( F_17 ( V_10 ) , V_8 -> V_14 + V_20 ) ;
F_9 ( F_17 ( V_10 + 1 ) , V_8 -> V_14 + V_20 ) ;
F_9 ( V_13 & ~ F_8 ( V_10 + 1 ) , V_8 -> V_14 + V_15 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_6 ( V_2 -> V_9 ) ;
int V_10 = V_2 -> V_11 . V_10 ;
T_1 V_21 , V_22 ;
T_2 V_23 , V_24 ;
do {
V_23 = F_19 ( & V_2 -> V_11 . V_16 ) ;
do {
V_21 = F_7 ( V_8 -> V_14 + F_11 ( V_10 + 1 ) ) ;
V_22 = F_7 ( V_8 -> V_14 + F_11 ( V_10 ) ) ;
} while ( V_21 != F_7 ( V_8 -> V_14 + F_11 ( V_10 + 1 ) ) );
V_24 = ( ( T_2 ) V_21 << 32 ) | V_22 ;
} while ( F_20 ( & V_2 -> V_11 . V_16 , V_23 , V_24 ) != V_23 );
F_21 ( V_24 - V_23 , & V_2 -> V_25 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_6 ( V_2 -> V_9 ) ;
int V_10 = V_2 -> V_11 . V_10 ;
T_1 V_12 = F_1 ( V_2 ) ;
T_1 V_26 = F_7 ( V_8 -> V_14 + V_27 ) ;
F_9 ( V_26 | F_23 ( V_10 ) , V_8 -> V_14 + V_27 ) ;
F_10 ( & V_2 -> V_11 . V_16 , 0 ) ;
F_9 ( 0 , V_8 -> V_14 + F_11 ( V_10 ) ) ;
F_9 ( F_12 ( V_12 ) , V_8 -> V_14 + F_13 ( V_10 ) ) ;
F_9 ( F_24 ( V_10 ) , V_8 -> V_14 + V_28 ) ;
F_9 ( V_17 , V_8 -> V_14 + F_14 ( V_10 ) ) ;
F_9 ( F_15 ( V_10 ) , V_8 -> V_14 + V_18 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
int V_19 )
{
struct V_7 * V_8 = F_6 ( V_2 -> V_9 ) ;
int V_10 = V_2 -> V_11 . V_10 ;
T_1 V_26 = F_7 ( V_8 -> V_14 + V_27 ) ;
F_9 ( F_17 ( V_10 ) , V_8 -> V_14 + V_20 ) ;
F_9 ( F_26 ( V_10 ) , V_8 -> V_14 + V_29 ) ;
F_9 ( V_26 & ~ F_23 ( V_10 ) , V_8 -> V_14 + V_27 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_6 ( V_2 -> V_9 ) ;
int V_10 = V_2 -> V_11 . V_10 ;
T_1 V_23 , V_24 ;
do {
V_23 = F_19 ( & V_2 -> V_11 . V_16 ) ;
V_24 = F_7 ( V_8 -> V_14 + F_11 ( V_10 ) ) ;
} while ( F_20 ( & V_2 -> V_11 . V_16 , V_23 , V_24 ) != V_23 );
F_21 ( V_24 - V_23 , & V_2 -> V_25 ) ;
}
static
const struct V_30 * F_28 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return & V_31 ;
else
return & V_32 ;
}
static inline void F_29 ( struct V_7 * V_8 )
{
int V_33 ;
F_9 ( V_34 , V_8 -> V_14 + V_35 ) ;
F_30 ( V_36 , V_8 -> V_14 + V_37 ) ;
F_9 ( V_38 , V_8 -> V_14 + V_20 ) ;
F_9 ( V_39 , V_8 -> V_14 + V_29 ) ;
F_9 ( V_40 , V_8 -> V_14 + V_41 ) ;
F_9 ( V_42 , V_8 -> V_14 + V_15 ) ;
F_9 ( V_43 , V_8 -> V_14 + V_27 ) ;
F_9 ( V_44 , V_8 -> V_14 + V_45 ) ;
for ( V_33 = 0 ; V_33 < V_46 ; ++ V_33 ) {
F_9 ( V_17 , V_8 -> V_14 + F_14 ( V_33 ) ) ;
F_9 ( F_12 ( 0 ) , V_8 -> V_14 + F_13 ( V_33 ) ) ;
}
F_9 ( V_47 , V_8 -> V_14 + V_48 ) ;
F_9 ( V_47 , V_8 -> V_14 + V_49 ) ;
F_9 ( V_47 , V_8 -> V_14 + V_50 ) ;
F_9 ( V_47 , V_8 -> V_14 + V_51 ) ;
F_9 ( V_47 , V_8 -> V_14 + V_52 ) ;
F_9 ( V_47 , V_8 -> V_14 + V_53 ) ;
F_30 ( V_54 , V_8 -> V_14 + V_35 ) ;
}
static T_3 F_31 ( int V_55 , void * V_56 )
{
struct V_7 * V_8 = V_56 ;
long V_57 = F_7 ( V_8 -> V_14 + V_41 ) ;
int V_10 ;
if ( V_57 == 0 )
return V_58 ;
F_9 ( V_57 , V_8 -> V_14 + V_41 ) ;
F_32 (idx, &status, L3_NUM_COUNTERS) {
struct V_1 * V_2 ;
const struct V_30 * V_59 ;
V_2 = V_8 -> V_60 [ V_10 ] ;
if ( ! V_2 )
continue;
V_59 = F_28 ( V_2 ) ;
V_59 -> V_61 ( V_2 ) ;
}
return V_62 ;
}
static void F_33 ( struct V_9 * V_9 )
{
struct V_7 * V_8 = F_6 ( V_9 ) ;
F_34 () ;
F_9 ( V_54 , V_8 -> V_14 + V_35 ) ;
}
static void F_35 ( struct V_9 * V_9 )
{
struct V_7 * V_8 = F_6 ( V_9 ) ;
F_9 ( 0 , V_8 -> V_14 + V_35 ) ;
F_34 () ;
}
static bool F_36 ( struct V_1 * V_2 )
{
struct V_1 * V_63 = V_2 -> V_64 ;
struct V_1 * V_65 ;
int V_66 = 0 ;
if ( V_63 -> V_9 != V_2 -> V_9 && ! F_37 ( V_63 ) )
return false ;
V_66 = F_4 ( V_2 ) ;
V_66 += F_4 ( V_63 ) ;
F_38 (sibling, &leader->sibling_list, group_entry) {
if ( F_37 ( V_65 ) )
continue;
if ( V_65 -> V_9 != V_2 -> V_9 )
return false ;
V_66 += F_4 ( V_65 ) ;
}
return V_66 <= V_46 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_6 ( V_2 -> V_9 ) ;
struct V_67 * V_68 = & V_2 -> V_11 ;
if ( V_2 -> V_3 . type != V_2 -> V_9 -> type )
return - V_69 ;
if ( V_2 -> V_3 . V_70 || V_2 -> V_3 . V_71 ||
V_2 -> V_3 . V_72 || V_2 -> V_3 . V_73 )
return - V_74 ;
if ( V_68 -> V_75 )
return - V_74 ;
if ( V_2 -> V_76 < 0 )
return - V_74 ;
if ( ! F_36 ( V_2 ) )
return - V_74 ;
V_68 -> V_10 = - 1 ;
V_2 -> V_76 = F_40 ( & V_8 -> V_77 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , int V_19 )
{
struct V_67 * V_68 = & V_2 -> V_11 ;
const struct V_30 * V_59 = F_28 ( V_2 ) ;
V_68 -> V_78 = 0 ;
V_59 -> V_79 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_19 )
{
struct V_67 * V_68 = & V_2 -> V_11 ;
const struct V_30 * V_59 = F_28 ( V_2 ) ;
if ( V_68 -> V_78 & V_80 )
return;
V_59 -> V_81 ( V_2 , V_19 ) ;
if ( V_19 & V_82 )
V_59 -> V_61 ( V_2 ) ;
V_68 -> V_78 |= V_80 | V_83 ;
}
static int F_43 ( struct V_1 * V_2 , int V_19 )
{
struct V_7 * V_8 = F_6 ( V_2 -> V_9 ) ;
struct V_67 * V_68 = & V_2 -> V_11 ;
int V_84 = F_2 ( V_2 ) ? 1 : 0 ;
int V_10 ;
V_10 = F_44 ( V_8 -> V_85 , V_46 , V_84 ) ;
if ( V_10 < 0 )
return - V_86 ;
V_68 -> V_10 = V_10 ;
V_68 -> V_78 = V_80 | V_83 ;
V_8 -> V_60 [ V_10 ] = V_2 ;
if ( V_19 & V_87 )
F_41 ( V_2 , 0 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , int V_19 )
{
struct V_7 * V_8 = F_6 ( V_2 -> V_9 ) ;
struct V_67 * V_68 = & V_2 -> V_11 ;
int V_84 = F_2 ( V_2 ) ? 1 : 0 ;
F_42 ( V_2 , V_19 | V_82 ) ;
V_8 -> V_60 [ V_68 -> V_10 ] = NULL ;
F_47 ( V_8 -> V_85 , V_68 -> V_10 , V_84 ) ;
F_45 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
const struct V_30 * V_59 = F_28 ( V_2 ) ;
V_59 -> V_61 ( V_2 ) ;
}
static T_4 F_49 ( struct V_88 * V_89 ,
struct V_90 * V_3 , char * V_91 )
{
struct V_92 * V_93 ;
V_93 = F_50 ( V_3 , struct V_92 , V_3 ) ;
return sprintf ( V_91 , L_1 , ( char * ) V_93 -> V_94 ) ;
}
static T_4 F_51 ( struct V_88 * V_89 ,
struct V_90 * V_3 , char * V_95 )
{
struct V_96 * V_97 ;
V_97 = F_50 ( V_3 , struct V_96 , V_3 ) ;
return sprintf ( V_95 , L_2 , V_97 -> V_98 ) ;
}
static T_4 F_52 ( struct V_88 * V_89 ,
struct V_90 * V_3 , char * V_91 )
{
struct V_7 * V_8 = F_6 ( F_53 ( V_89 ) ) ;
return F_54 ( true , V_91 , & V_8 -> V_77 ) ;
}
static int F_55 ( unsigned int V_76 , struct V_99 * V_100 )
{
struct V_7 * V_8 = F_56 ( V_100 , struct V_7 , V_100 ) ;
if ( F_57 ( & V_8 -> V_77 ) )
F_58 ( V_76 , & V_8 -> V_77 ) ;
return 0 ;
}
static int F_59 ( unsigned int V_76 , struct V_99 * V_100 )
{
struct V_7 * V_8 = F_56 ( V_100 , struct V_7 , V_100 ) ;
unsigned int V_101 ;
if ( ! F_60 ( V_76 , & V_8 -> V_77 ) )
return 0 ;
V_101 = F_61 ( V_102 , V_76 ) ;
if ( V_101 >= V_103 )
return 0 ;
F_62 ( & V_8 -> V_9 , V_76 , V_101 ) ;
F_58 ( V_101 , & V_8 -> V_77 ) ;
return 0 ;
}
static int F_63 ( struct V_104 * V_105 )
{
struct V_7 * V_8 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
int V_110 ;
char * V_111 ;
V_107 = F_64 ( & V_105 -> V_89 ) ;
if ( ! V_107 )
return - V_112 ;
V_8 = F_65 ( & V_105 -> V_89 , sizeof( * V_8 ) , V_113 ) ;
V_111 = F_66 ( & V_105 -> V_89 , V_113 , L_3 ,
V_107 -> V_114 -> V_115 . V_116 , V_107 -> V_115 . V_116 ) ;
if ( ! V_8 || ! V_111 )
return - V_117 ;
V_8 -> V_9 = (struct V_9 ) {
. V_118 = V_119 ,
. V_120 = F_33 ,
. V_121 = F_35 ,
. V_122 = F_39 ,
. V_123 = F_43 ,
. V_124 = F_46 ,
. V_79 = F_41 ,
. V_81 = F_42 ,
. V_125 = F_48 ,
. V_126 = V_127 ,
} ;
V_109 = F_67 ( V_105 , V_128 , 0 ) ;
V_8 -> V_14 = F_68 ( & V_105 -> V_89 , V_109 ) ;
if ( F_69 ( V_8 -> V_14 ) ) {
F_70 ( & V_105 -> V_89 , L_4 , & V_109 -> V_79 ) ;
return F_71 ( V_8 -> V_14 ) ;
}
F_29 ( V_8 ) ;
V_110 = F_72 ( V_105 , 0 ) ;
if ( V_110 <= 0 )
return V_110 ;
V_110 = F_73 ( & V_105 -> V_89 , V_110 , F_31 , 0 ,
V_111 , V_8 ) ;
if ( V_110 ) {
F_70 ( & V_105 -> V_89 , L_5 ,
& V_109 -> V_79 ) ;
return V_110 ;
}
V_110 = F_74 ( V_129 , & V_8 -> V_100 ) ;
if ( V_110 ) {
F_70 ( & V_105 -> V_89 , L_6 , V_110 ) ;
return V_110 ;
}
V_110 = F_75 ( & V_8 -> V_9 , V_111 , - 1 ) ;
if ( V_110 < 0 ) {
F_70 ( & V_105 -> V_89 , L_7 , V_110 ) ;
return V_110 ;
}
F_76 ( & V_105 -> V_89 , L_8 , V_111 , V_8 -> V_9 . type ) ;
return 0 ;
}
static int T_5 F_77 ( void )
{
int V_110 ;
V_110 = F_78 ( V_129 ,
L_9 ,
F_55 ,
F_59 ) ;
if ( V_110 )
return V_110 ;
return F_79 ( & V_130 ) ;
}
