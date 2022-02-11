static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline int F_3 ( int V_5 )
{
int V_6 ;
for ( V_6 = F_4 ( V_7 ) - 1 ; V_6 >= 0 ; V_6 -- )
if ( ( V_5 ) >= V_7 [ V_6 ] )
return V_6 ;
return 0 ;
}
static inline int F_5 ( int V_5 )
{
int V_8 = F_3 ( V_5 ) ;
return V_5 - V_7 [ V_8 ] ;
}
static void F_6 ( struct V_9 * V_10 )
{
F_7 ( V_11 | V_12 ,
V_10 -> V_13 + V_14 ) ;
F_7 ( V_15 , V_10 -> V_13 + V_16 ) ;
F_8 () ;
}
static void F_9 ( struct V_9 * V_10 ,
unsigned long V_17 , T_1 V_18 )
{
int V_19 ;
T_2 V_20 ;
F_7 ( V_11 | V_12 ,
V_10 -> V_13 + V_14 ) ;
F_7 ( V_17 & V_21 ,
V_10 -> V_13 + V_22 ) ;
F_7 ( ( V_17 + V_18 - 1 ) & V_21 ,
V_10 -> V_13 + V_23 ) ;
F_7 ( V_24 , V_10 -> V_13 + V_16 ) ;
V_19 = F_10 ( V_10 -> V_13 + V_25 ,
V_20 , V_20 != 0 , 10 , 100000 ) ;
if ( V_19 ) {
F_11 ( V_10 -> V_26 ,
L_1 ) ;
F_6 ( V_10 ) ;
}
F_7 ( 0 , V_10 -> V_13 + V_25 ) ;
}
static T_3 F_12 ( int V_27 , void * V_28 )
{
struct V_9 * V_10 = V_28 ;
struct V_1 * V_3 = V_10 -> V_29 ;
T_2 V_30 , V_31 , V_32 , V_33 ;
unsigned int V_34 , V_35 ;
V_30 = F_13 ( V_10 -> V_13 + V_36 ) ;
V_32 = F_13 ( V_10 -> V_13 + V_37 ) ;
V_32 &= V_21 ;
V_33 = F_13 ( V_10 -> V_13 + V_38 ) ;
V_31 = F_13 ( V_10 -> V_13 + V_39 ) ;
V_34 = F_14 ( V_31 ) ;
V_35 = F_15 ( V_31 ) ;
if ( F_16 ( & V_3 -> V_4 , V_10 -> V_26 , V_32 ,
V_40 ) )
F_17 ( V_10 -> V_26 ,
L_2 ,
V_30 , V_32 , V_33 ,
V_34 , V_35 ) ;
V_31 = F_13 ( V_10 -> V_13 + V_41 ) ;
V_31 |= V_42 ;
F_7 ( V_31 , V_10 -> V_13 + V_41 ) ;
F_6 ( V_10 ) ;
return V_43 ;
}
static void F_18 ( struct V_9 * V_10 ,
struct V_44 * V_26 , bool V_45 )
{
struct V_46 * V_47 ;
unsigned int V_48 , V_49 ;
struct V_50 * V_51 = V_26 -> V_50 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_51 -> V_52 ; ++ V_6 ) {
V_48 = F_3 ( V_51 -> V_53 [ V_6 ] ) ;
V_49 = F_5 ( V_51 -> V_53 [ V_6 ] ) ;
V_47 = & V_10 -> V_54 . V_55 [ V_48 ] ;
F_19 ( V_26 , L_3 ,
V_45 ? L_4 : L_5 , V_49 ) ;
if ( V_45 )
V_47 -> V_56 |= F_20 ( V_49 ) ;
else
V_47 -> V_56 &= ~ F_20 ( V_49 ) ;
}
}
static int F_21 ( struct V_9 * V_10 )
{
struct V_1 * V_3 = V_10 -> V_29 ;
F_22 ( & V_3 -> V_57 ) ;
V_3 -> V_58 = F_23 ( V_10 -> V_26 ,
V_59 ,
& V_3 -> V_60 , V_61 ) ;
if ( ! V_3 -> V_58 )
return - V_62 ;
F_24 ( V_3 -> V_60 , V_10 -> V_13 + V_63 ) ;
V_3 -> V_10 = V_10 ;
return 0 ;
}
static struct V_2 * F_25 ( unsigned type )
{
struct V_1 * V_3 ;
if ( type != V_64 )
return NULL ;
V_3 = F_26 ( sizeof( * V_3 ) , V_61 ) ;
if ( ! V_3 )
return NULL ;
return & V_3 -> V_4 ;
}
static void F_27 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
F_28 ( V_10 -> V_26 , V_59 ,
V_3 -> V_58 , V_3 -> V_60 ) ;
F_29 ( F_1 ( V_4 ) ) ;
}
static int F_30 ( struct V_2 * V_4 ,
struct V_44 * V_26 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_9 * V_10 = V_26 -> V_50 -> V_65 ;
int V_19 ;
if ( ! V_10 )
return - V_66 ;
if ( ! V_10 -> V_29 ) {
V_10 -> V_29 = V_3 ;
V_19 = F_21 ( V_10 ) ;
if ( V_19 ) {
V_10 -> V_29 = NULL ;
return V_19 ;
}
}
F_18 ( V_10 , V_26 , true ) ;
return 0 ;
}
static void F_31 ( struct V_2 * V_4 ,
struct V_44 * V_26 )
{
struct V_9 * V_10 = V_26 -> V_50 -> V_65 ;
if ( ! V_10 )
return;
F_18 ( V_10 , V_26 , false ) ;
}
static int F_32 ( struct V_2 * V_4 , unsigned long V_17 ,
T_4 V_67 , T_1 V_18 , int V_68 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned int V_69 = V_18 >> V_70 ;
unsigned long V_71 ;
unsigned int V_6 ;
T_2 * V_72 = V_3 -> V_58 + ( V_17 >> V_70 ) ;
T_2 V_73 = ( T_2 ) V_67 ;
int V_74 = 0 ;
F_33 ( & V_3 -> V_57 , V_71 ) ;
for ( V_6 = 0 ; V_6 < V_69 ; V_6 ++ ) {
if ( V_72 [ V_6 ] ) {
memset ( V_72 , 0 , V_6 * sizeof( T_2 ) ) ;
break;
}
V_72 [ V_6 ] = V_73 | V_75 | V_76 ;
V_73 += V_77 ;
V_74 += V_77 ;
}
F_34 ( & V_3 -> V_57 , V_71 ) ;
F_9 ( V_3 -> V_10 , V_17 , V_18 ) ;
return V_74 == V_18 ? 0 : - V_78 ;
}
static T_1 F_35 ( struct V_2 * V_4 ,
unsigned long V_17 , T_1 V_18 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_71 ;
T_2 * V_72 = V_3 -> V_58 + ( V_17 >> V_70 ) ;
unsigned int V_69 = V_18 >> V_70 ;
F_33 ( & V_3 -> V_57 , V_71 ) ;
memset ( V_72 , 0 , V_69 * sizeof( T_2 ) ) ;
F_34 ( & V_3 -> V_57 , V_71 ) ;
F_9 ( V_3 -> V_10 , V_17 , V_18 ) ;
return V_18 ;
}
static T_4 F_36 ( struct V_2 * V_4 ,
T_5 V_17 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_71 ;
T_4 V_79 ;
F_33 ( & V_3 -> V_57 , V_71 ) ;
V_79 = * ( V_3 -> V_58 + ( V_17 >> V_70 ) ) ;
V_79 = V_79 & ( ~ ( V_77 - 1 ) ) ;
F_34 ( & V_3 -> V_57 , V_71 ) ;
return V_79 ;
}
static int F_37 ( struct V_44 * V_26 ,
struct V_80 * args )
{
struct V_9 * V_10 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_44 * V_85 ;
int V_19 ;
if ( args -> V_86 != 1 ) {
F_38 ( V_26 , L_6 ,
args -> V_86 ) ;
return - V_87 ;
}
if ( ! V_26 -> V_50 ) {
V_19 = F_39 ( V_26 , & args -> V_88 -> V_89 , & V_90 ) ;
if ( V_19 )
return V_19 ;
} else if ( V_26 -> V_50 -> V_91 != & V_90 ) {
return - V_87 ;
}
if ( ! V_26 -> V_50 -> V_65 ) {
V_82 = F_40 ( args -> V_88 ) ;
if ( F_41 ( ! V_82 ) )
return - V_87 ;
V_26 -> V_50 -> V_65 = F_42 ( V_82 ) ;
}
V_19 = F_43 ( V_26 , args -> args , 1 ) ;
if ( V_19 )
return V_19 ;
V_10 = V_26 -> V_50 -> V_65 ;
V_85 = V_10 -> V_26 ;
V_84 = V_85 -> V_92 . V_93 ;
if ( ! V_84 ) {
V_84 = F_44 ( & V_94 ,
0 , 1ULL << 32 ) ;
if ( F_45 ( V_84 ) )
return F_46 ( V_84 ) ;
V_85 -> V_92 . V_93 = V_84 ;
}
V_19 = F_47 ( V_26 , V_84 ) ;
if ( V_19 )
goto V_95;
return 0 ;
V_95:
F_48 ( V_84 ) ;
V_85 -> V_92 . V_93 = NULL ;
return V_19 ;
}
static int F_49 ( struct V_44 * V_26 )
{
struct V_96 * V_97 ;
struct V_80 V_98 ;
struct V_99 V_100 ;
int V_101 ;
F_50 (&it, err, dev->of_node, L_7 ,
L_8 , 0 ) {
int V_102 = F_51 ( & V_100 , V_98 . args ,
V_103 ) ;
V_98 . V_88 = F_52 ( V_100 . V_104 ) ;
V_98 . V_86 = V_102 ;
F_37 ( V_26 , & V_98 ) ;
F_53 ( V_98 . V_88 ) ;
}
if ( ! V_26 -> V_50 || V_26 -> V_50 -> V_91 != & V_90 )
return - V_66 ;
V_97 = F_54 ( V_26 ) ;
if ( F_45 ( V_97 ) )
return F_46 ( V_97 ) ;
F_55 ( V_97 ) ;
return 0 ;
}
static void F_56 ( struct V_44 * V_26 )
{
if ( ! V_26 -> V_50 || V_26 -> V_50 -> V_91 != & V_90 )
return;
F_57 ( V_26 ) ;
F_58 ( V_26 ) ;
}
static struct V_96 * F_59 ( struct V_44 * V_26 )
{
struct V_9 * V_10 = V_26 -> V_50 -> V_65 ;
if ( ! V_10 )
return F_60 ( - V_66 ) ;
if ( ! V_10 -> V_105 ) {
V_10 -> V_105 = F_61 () ;
if ( F_45 ( V_10 -> V_105 ) )
F_38 ( V_26 , L_9 ) ;
} else {
F_62 ( V_10 -> V_105 ) ;
}
return V_10 -> V_105 ;
}
static int F_63 ( const struct V_9 * V_10 )
{
T_2 V_31 ;
int V_19 ;
V_19 = F_64 ( V_10 -> V_106 ) ;
if ( V_19 ) {
F_38 ( V_10 -> V_26 , L_10 , V_19 ) ;
return V_19 ;
}
V_31 = V_107 | F_65 ( 2 ) ;
F_7 ( V_31 , V_10 -> V_13 + V_108 ) ;
V_31 = V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 ;
F_7 ( V_31 , V_10 -> V_13 + V_41 ) ;
F_7 ( V_10 -> V_117 ,
V_10 -> V_13 + V_118 ) ;
F_7 ( V_119 , V_10 -> V_13 + V_120 ) ;
if ( F_66 ( V_10 -> V_26 , V_10 -> V_27 , F_12 , 0 ,
F_67 ( V_10 -> V_26 ) , ( void * ) V_10 ) ) {
F_7 ( 0 , V_10 -> V_13 + V_63 ) ;
F_68 ( V_10 -> V_106 ) ;
F_38 ( V_10 -> V_26 , L_11 , V_10 -> V_27 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_69 ( struct V_81 * V_121 )
{
struct V_9 * V_10 ;
struct V_44 * V_26 = & V_121 -> V_26 ;
struct V_122 * V_123 ;
struct V_124 * V_125 = NULL ;
struct V_80 V_126 ;
struct V_99 V_100 ;
void * V_127 ;
int V_128 , V_19 , V_101 ;
V_10 = F_70 ( V_26 , sizeof( * V_10 ) , V_61 ) ;
if ( ! V_10 )
return - V_62 ;
V_10 -> V_26 = V_26 ;
V_127 = F_70 ( V_26 , V_129 * 2 ,
V_61 | V_130 ) ;
if ( ! V_127 )
return - V_62 ;
V_10 -> V_117 = F_71 ( F_72 ( V_127 ) , V_129 ) ;
V_123 = F_73 ( V_121 , V_131 , 0 ) ;
V_10 -> V_13 = F_74 ( V_26 , V_123 ) ;
if ( F_45 ( V_10 -> V_13 ) )
return F_46 ( V_10 -> V_13 ) ;
V_10 -> V_27 = F_75 ( V_121 , 0 ) ;
if ( V_10 -> V_27 < 0 )
return V_10 -> V_27 ;
V_10 -> V_106 = F_76 ( V_26 , L_12 ) ;
if ( F_45 ( V_10 -> V_106 ) )
return F_46 ( V_10 -> V_106 ) ;
V_128 = 0 ;
F_50 (&it, err, dev->of_node,
L_13 , NULL, 0 ) {
struct V_81 * V_132 ;
int V_102 = F_51 ( & V_100 , V_126 . args ,
V_103 ) ;
if ( V_102 )
continue;
V_126 . V_88 = F_52 ( V_100 . V_104 ) ;
if ( ! F_77 ( V_126 . V_88 ) )
continue;
V_132 = F_40 ( V_126 . V_88 ) ;
if ( ! V_132 ) {
V_132 = F_78 (
V_126 . V_88 , NULL ,
V_94 . V_133 ) ;
if ( ! V_132 ) {
F_53 ( V_126 . V_88 ) ;
return - V_134 ;
}
}
V_10 -> V_54 . V_55 [ V_128 ] . V_26 = & V_132 -> V_26 ;
F_79 ( V_26 , & V_125 , V_135 ,
V_136 , V_126 . V_88 ) ;
V_128 ++ ;
}
V_10 -> V_54 . V_128 = V_128 ;
F_80 ( V_121 , V_10 ) ;
V_19 = F_63 ( V_10 ) ;
if ( V_19 )
return V_19 ;
if ( ! F_81 ( & V_94 ) )
F_82 ( & V_94 , & V_90 ) ;
return F_83 ( V_26 , & V_137 , V_125 ) ;
}
static int F_84 ( struct V_81 * V_121 )
{
struct V_9 * V_10 = F_42 ( V_121 ) ;
if ( F_81 ( & V_94 ) )
F_82 ( & V_94 , NULL ) ;
F_68 ( V_10 -> V_106 ) ;
F_85 ( & V_121 -> V_26 , V_10 -> V_27 , V_10 ) ;
F_86 ( & V_121 -> V_26 , & V_137 ) ;
return 0 ;
}
static int T_6 F_87 ( struct V_44 * V_26 )
{
struct V_9 * V_10 = F_88 ( V_26 ) ;
struct V_138 * V_139 = & V_10 -> V_139 ;
void T_7 * V_13 = V_10 -> V_13 ;
V_139 -> V_140 = F_13 ( V_13 +
V_141 ) ;
V_139 -> V_142 = F_13 ( V_13 + V_120 ) ;
V_139 -> V_143 = F_13 ( V_13 + V_108 ) ;
V_139 -> V_144 = F_13 ( V_13 + V_41 ) ;
return 0 ;
}
static int T_6 F_89 ( struct V_44 * V_26 )
{
struct V_9 * V_10 = F_88 ( V_26 ) ;
struct V_138 * V_139 = & V_10 -> V_139 ;
void T_7 * V_13 = V_10 -> V_13 ;
F_7 ( V_10 -> V_29 -> V_60 , V_13 + V_63 ) ;
F_7 ( V_139 -> V_140 ,
V_13 + V_141 ) ;
F_7 ( V_139 -> V_142 , V_13 + V_120 ) ;
F_7 ( V_139 -> V_143 , V_13 + V_108 ) ;
F_7 ( V_139 -> V_144 , V_13 + V_41 ) ;
F_7 ( V_10 -> V_117 , V_13 + V_118 ) ;
return 0 ;
}
static int T_8 F_90 ( void )
{
return F_91 ( & V_145 ) ;
}
static void T_9 F_92 ( void )
{
return F_93 ( & V_145 ) ;
}
