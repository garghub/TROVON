static inline void F_1 ( T_1 * V_1 , unsigned int V_2 )
{
T_2 V_3 = F_2 ( V_1 ) ;
T_2 V_4 = F_2 ( V_1 + V_2 ) ;
T_3 V_5 = V_4 - V_3 ;
F_3 ( V_1 , V_5 ) ;
F_4 ( V_3 , V_4 ) ;
}
static struct V_6 * F_5 ( struct V_7 * V_8 )
{
return F_6 ( V_8 , struct V_6 , V_9 ) ;
}
static inline T_2 F_7 ( T_1 V_10 )
{
return ( T_2 ) V_10 & V_11 ;
}
static inline bool F_8 ( T_1 V_10 )
{
return V_10 & V_12 ;
}
static T_1 F_9 ( T_1 * V_13 )
{
T_2 V_14 = F_2 ( V_13 ) ;
return ( V_14 & V_11 ) | V_12 ;
}
static inline T_2 F_10 ( T_1 V_15 )
{
return ( T_2 ) V_15 & V_16 ;
}
static inline bool F_11 ( T_1 V_15 )
{
return V_15 & V_17 ;
}
static T_1 F_12 ( T_2 V_18 , int V_19 )
{
T_1 V_20 = 0 ;
V_20 |= ( V_19 & V_21 ) ? V_22 : 0 ;
V_20 |= ( V_19 & V_23 ) ? V_24 : 0 ;
V_18 &= V_16 ;
return V_18 | V_20 | V_17 ;
}
static T_1 F_13 ( T_1 V_15 )
{
return V_15 & ~ V_17 ;
}
static T_1 F_14 ( T_4 V_25 )
{
return ( T_1 ) ( V_25 & V_26 ) >> V_27 ;
}
static T_1 F_15 ( T_4 V_25 )
{
return ( T_1 ) ( V_25 & V_28 ) >> V_29 ;
}
static T_1 F_16 ( T_4 V_25 )
{
return ( T_1 ) ( V_25 & V_30 ) >> V_31 ;
}
static T_1 F_17 ( struct V_32 * V_33 , T_1 V_34 )
{
return F_18 ( V_33 -> V_35 + V_34 ) ;
}
static void F_19 ( struct V_32 * V_33 , T_1 V_34 , T_1 V_36 )
{
F_20 ( V_36 , V_33 -> V_35 + V_34 ) ;
}
static void F_21 ( struct V_32 * V_33 , T_1 V_37 )
{
F_20 ( V_37 , V_33 -> V_35 + V_38 ) ;
}
static void F_22 ( struct V_32 * V_33 , T_4 V_25 ,
T_3 V_5 )
{
T_4 V_39 = V_25 + V_5 ;
for (; V_25 < V_39 ; V_25 += V_40 )
F_19 ( V_33 , V_41 , V_25 ) ;
}
static bool F_23 ( struct V_32 * V_33 )
{
return F_17 ( V_33 , V_42 ) & V_43 ;
}
static bool F_24 ( struct V_32 * V_33 )
{
return F_17 ( V_33 , V_42 ) &
V_44 ;
}
static int F_25 ( struct V_32 * V_33 )
{
int V_45 ;
if ( F_23 ( V_33 ) )
return 0 ;
if ( ! F_24 ( V_33 ) )
return 0 ;
F_21 ( V_33 , V_46 ) ;
V_45 = F_26 ( F_23 ( V_33 ) , 1 ) ;
if ( V_45 )
F_27 ( V_33 -> V_47 , L_1 ,
F_17 ( V_33 , V_42 ) ) ;
return V_45 ;
}
static int F_28 ( struct V_32 * V_33 )
{
int V_45 ;
if ( ! F_23 ( V_33 ) )
return 0 ;
F_21 ( V_33 , V_48 ) ;
V_45 = F_26 ( ! F_23 ( V_33 ) , 1 ) ;
if ( V_45 )
F_27 ( V_33 -> V_47 , L_2 ,
F_17 ( V_33 , V_42 ) ) ;
return V_45 ;
}
static int F_29 ( struct V_32 * V_33 )
{
int V_45 ;
if ( F_24 ( V_33 ) )
return 0 ;
F_21 ( V_33 , V_49 ) ;
V_45 = F_26 ( F_24 ( V_33 ) , 1 ) ;
if ( V_45 )
F_27 ( V_33 -> V_47 , L_3 ,
F_17 ( V_33 , V_42 ) ) ;
return V_45 ;
}
static int F_30 ( struct V_32 * V_33 )
{
int V_45 ;
if ( ! F_24 ( V_33 ) )
return 0 ;
F_21 ( V_33 , V_50 ) ;
V_45 = F_26 ( ! F_24 ( V_33 ) , 1 ) ;
if ( V_45 )
F_27 ( V_33 -> V_47 , L_4 ,
F_17 ( V_33 , V_42 ) ) ;
return V_45 ;
}
static int F_31 ( struct V_32 * V_33 )
{
int V_45 ;
T_1 V_51 ;
F_19 ( V_33 , V_52 , V_53 ) ;
V_51 = F_17 ( V_33 , V_52 ) ;
if ( V_51 != ( V_53 & V_11 ) ) {
F_27 ( V_33 -> V_47 , L_5 ) ;
return - V_54 ;
}
F_21 ( V_33 , V_55 ) ;
V_45 = F_26 ( F_17 ( V_33 , V_52 ) == 0x00000000 ,
V_56 ) ;
if ( V_45 )
F_27 ( V_33 -> V_47 , L_6 ) ;
return V_45 ;
}
static void F_32 ( struct V_32 * V_33 , T_4 V_25 )
{
T_1 V_57 , V_58 , V_59 ;
T_1 V_60 ;
T_2 V_61 , V_62 ;
T_1 * V_51 ;
T_1 V_10 ;
T_2 V_63 = 0 ;
T_1 * V_64 = NULL ;
T_1 V_15 = 0 ;
T_2 V_65 = 0 ;
T_1 V_66 = 0 ;
V_57 = F_14 ( V_25 ) ;
V_58 = F_15 ( V_25 ) ;
V_59 = F_16 ( V_25 ) ;
V_60 = F_17 ( V_33 , V_52 ) ;
V_61 = ( T_2 ) V_60 ;
V_62 = V_61 + ( 4 * V_57 ) ;
V_51 = F_33 ( V_62 ) ;
V_10 = * V_51 ;
if ( ! F_8 ( V_10 ) )
goto V_67;
V_63 = F_7 ( V_10 ) + ( V_58 * 4 ) ;
V_64 = F_33 ( V_63 ) ;
V_15 = * V_64 ;
if ( ! F_11 ( V_15 ) )
goto V_67;
V_65 = F_10 ( V_15 ) + V_59 ;
V_66 = V_15 & V_68 ;
V_67:
F_27 ( V_33 -> V_47 , L_7 ,
& V_25 , V_57 , V_58 , V_59 ) ;
F_27 ( V_33 -> V_47 , L_8 ,
& V_61 , & V_62 , V_10 ,
F_8 ( V_10 ) , & V_63 , V_15 ,
F_11 ( V_15 ) , & V_65 , V_66 ) ;
}
static T_5 F_34 ( int V_69 , void * V_70 )
{
struct V_32 * V_33 = V_70 ;
T_1 V_71 ;
T_1 V_72 ;
T_4 V_25 ;
V_72 = F_17 ( V_33 , V_73 ) ;
if ( V_72 == 0 )
return V_74 ;
V_25 = F_17 ( V_33 , V_75 ) ;
if ( V_72 & V_76 ) {
int V_20 ;
V_71 = F_17 ( V_33 , V_42 ) ;
V_20 = ( V_71 & V_77 ) ?
V_78 : V_79 ;
F_27 ( V_33 -> V_47 , L_9 ,
& V_25 ,
( V_20 == V_78 ) ? L_10 : L_11 ) ;
F_32 ( V_33 , V_25 ) ;
if ( V_33 -> V_9 )
F_35 ( V_33 -> V_9 , V_33 -> V_47 , V_25 ,
V_20 ) ;
else
F_27 ( V_33 -> V_47 , L_12 ) ;
F_21 ( V_33 , V_80 ) ;
F_21 ( V_33 , V_81 ) ;
}
if ( V_72 & V_82 )
F_27 ( V_33 -> V_47 , L_13 , & V_25 ) ;
if ( V_72 & ~ V_83 )
F_27 ( V_33 -> V_47 , L_14 ,
V_72 ) ;
F_19 ( V_33 , V_84 , V_72 ) ;
return V_85 ;
}
static T_2 F_36 ( struct V_7 * V_9 ,
T_4 V_25 )
{
struct V_6 * V_86 = F_5 ( V_9 ) ;
unsigned long V_20 ;
T_2 V_14 , V_87 = 0 ;
T_1 V_10 , V_15 ;
T_1 * V_88 ;
F_37 ( & V_86 -> V_89 , V_20 ) ;
V_10 = V_86 -> V_90 [ F_14 ( V_25 ) ] ;
if ( ! F_8 ( V_10 ) )
goto V_91;
V_14 = F_7 ( V_10 ) ;
V_88 = ( T_1 * ) F_33 ( V_14 ) ;
V_15 = V_88 [ F_15 ( V_25 ) ] ;
if ( ! F_11 ( V_15 ) )
goto V_91;
V_87 = F_10 ( V_15 ) + F_16 ( V_25 ) ;
V_91:
F_38 ( & V_86 -> V_89 , V_20 ) ;
return V_87 ;
}
static void F_39 ( struct V_6 * V_86 ,
T_4 V_25 , T_3 V_5 )
{
struct V_92 * V_93 ;
unsigned long V_20 ;
F_37 ( & V_86 -> V_94 , V_20 ) ;
F_40 (pos, &rk_domain->iommus) {
struct V_32 * V_33 ;
V_33 = F_41 ( V_93 , struct V_32 , V_95 ) ;
F_22 ( V_33 , V_25 , V_5 ) ;
}
F_38 ( & V_86 -> V_94 , V_20 ) ;
}
static T_1 * F_42 ( struct V_6 * V_86 ,
T_4 V_25 )
{
T_1 * V_88 , * V_51 ;
T_1 V_10 ;
T_2 V_14 ;
F_43 ( & V_86 -> V_89 ) ;
V_51 = & V_86 -> V_90 [ F_14 ( V_25 ) ] ;
V_10 = * V_51 ;
if ( F_8 ( V_10 ) )
goto V_96;
V_88 = ( T_1 * ) F_44 ( V_97 | V_98 ) ;
if ( ! V_88 )
return F_45 ( - V_99 ) ;
V_10 = F_9 ( V_88 ) ;
* V_51 = V_10 ;
F_1 ( V_88 , V_100 ) ;
F_1 ( V_51 , 1 ) ;
F_39 ( V_86 , V_25 , V_40 ) ;
V_96:
V_14 = F_7 ( V_10 ) ;
return ( T_1 * ) F_33 ( V_14 ) ;
}
static T_3 F_46 ( struct V_6 * V_86 ,
T_1 * V_64 , T_4 V_25 , T_3 V_5 )
{
unsigned int V_101 ;
unsigned int V_102 = V_5 / V_40 ;
F_43 ( & V_86 -> V_89 ) ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ ) {
T_1 V_15 = V_64 [ V_101 ] ;
if ( ! F_11 ( V_15 ) )
break;
V_64 [ V_101 ] = F_13 ( V_15 ) ;
}
F_1 ( V_64 , V_101 ) ;
return V_101 * V_40 ;
}
static int F_47 ( struct V_6 * V_86 , T_1 * V_64 ,
T_4 V_25 , T_2 V_103 , T_3 V_5 ,
int V_19 )
{
unsigned int V_101 ;
unsigned int V_102 = V_5 / V_40 ;
T_2 V_104 ;
F_43 ( & V_86 -> V_89 ) ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ ) {
T_1 V_15 = V_64 [ V_101 ] ;
if ( F_11 ( V_15 ) )
goto V_105;
V_64 [ V_101 ] = F_12 ( V_103 , V_19 ) ;
V_103 += V_40 ;
}
F_1 ( V_64 , V_101 ) ;
return 0 ;
V_105:
F_46 ( V_86 , V_64 , V_25 , V_101 * V_40 ) ;
V_25 += V_101 * V_40 ;
V_104 = F_10 ( V_64 [ V_101 ] ) ;
F_48 ( L_15 ,
& V_25 , & V_104 , & V_103 , V_19 ) ;
return - V_106 ;
}
static int F_49 ( struct V_7 * V_9 , unsigned long V_107 ,
T_2 V_103 , T_3 V_5 , int V_19 )
{
struct V_6 * V_86 = F_5 ( V_9 ) ;
unsigned long V_20 ;
T_4 V_25 = ( T_4 ) V_107 ;
T_1 * V_88 , * V_64 ;
int V_45 ;
F_37 ( & V_86 -> V_89 , V_20 ) ;
V_88 = F_42 ( V_86 , V_25 ) ;
if ( F_50 ( V_88 ) ) {
F_38 ( & V_86 -> V_89 , V_20 ) ;
return F_51 ( V_88 ) ;
}
V_64 = & V_88 [ F_15 ( V_25 ) ] ;
V_45 = F_47 ( V_86 , V_64 , V_25 , V_103 , V_5 , V_19 ) ;
F_38 ( & V_86 -> V_89 , V_20 ) ;
return V_45 ;
}
static T_3 F_52 ( struct V_7 * V_9 , unsigned long V_107 ,
T_3 V_5 )
{
struct V_6 * V_86 = F_5 ( V_9 ) ;
unsigned long V_20 ;
T_4 V_25 = ( T_4 ) V_107 ;
T_2 V_14 ;
T_1 V_10 ;
T_1 * V_64 ;
T_3 V_108 ;
F_37 ( & V_86 -> V_89 , V_20 ) ;
V_10 = V_86 -> V_90 [ F_14 ( V_25 ) ] ;
if ( ! F_8 ( V_10 ) ) {
F_38 ( & V_86 -> V_89 , V_20 ) ;
return 0 ;
}
V_14 = F_7 ( V_10 ) ;
V_64 = ( T_1 * ) F_33 ( V_14 ) + F_15 ( V_25 ) ;
V_108 = F_46 ( V_86 , V_64 , V_25 , V_5 ) ;
F_38 ( & V_86 -> V_89 , V_20 ) ;
F_39 ( V_86 , V_25 , V_108 ) ;
return V_108 ;
}
static struct V_32 * F_53 ( struct V_109 * V_47 )
{
struct V_110 * V_111 ;
struct V_109 * V_112 ;
struct V_32 * V_32 ;
V_111 = F_54 ( V_47 ) ;
if ( ! V_111 )
return NULL ;
V_112 = F_55 ( V_111 ) ;
V_32 = F_56 ( V_112 ) ;
F_57 ( V_111 ) ;
return V_32 ;
}
static int F_58 ( struct V_7 * V_9 ,
struct V_109 * V_47 )
{
struct V_32 * V_33 ;
struct V_6 * V_86 = F_5 ( V_9 ) ;
unsigned long V_20 ;
int V_45 ;
T_2 V_51 ;
V_33 = F_53 ( V_47 ) ;
if ( ! V_33 )
return 0 ;
V_45 = F_25 ( V_33 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_31 ( V_33 ) ;
if ( V_45 )
return V_45 ;
V_33 -> V_9 = V_9 ;
V_45 = F_59 ( V_47 , V_33 -> V_69 , F_34 ,
V_113 , F_60 ( V_47 ) , V_33 ) ;
if ( V_45 )
return V_45 ;
V_51 = F_2 ( V_86 -> V_90 ) ;
F_19 ( V_33 , V_52 , V_51 ) ;
F_21 ( V_33 , V_80 ) ;
F_19 ( V_33 , V_114 , V_83 ) ;
V_45 = F_29 ( V_33 ) ;
if ( V_45 )
return V_45 ;
F_37 ( & V_86 -> V_94 , V_20 ) ;
F_61 ( & V_33 -> V_95 , & V_86 -> V_115 ) ;
F_38 ( & V_86 -> V_94 , V_20 ) ;
F_62 ( V_47 , L_16 ) ;
F_28 ( V_33 ) ;
return 0 ;
}
static void F_63 ( struct V_7 * V_9 ,
struct V_109 * V_47 )
{
struct V_32 * V_33 ;
struct V_6 * V_86 = F_5 ( V_9 ) ;
unsigned long V_20 ;
V_33 = F_53 ( V_47 ) ;
if ( ! V_33 )
return;
F_37 ( & V_86 -> V_94 , V_20 ) ;
F_64 ( & V_33 -> V_95 ) ;
F_38 ( & V_86 -> V_94 , V_20 ) ;
F_25 ( V_33 ) ;
F_30 ( V_33 ) ;
F_19 ( V_33 , V_114 , 0 ) ;
F_19 ( V_33 , V_52 , 0 ) ;
F_28 ( V_33 ) ;
F_65 ( V_47 , V_33 -> V_69 , V_33 ) ;
V_33 -> V_9 = NULL ;
F_62 ( V_47 , L_17 ) ;
}
static struct V_7 * F_66 ( unsigned type )
{
struct V_6 * V_86 ;
if ( type != V_116 )
return NULL ;
V_86 = F_67 ( sizeof( * V_86 ) , V_117 ) ;
if ( ! V_86 )
return NULL ;
V_86 -> V_90 = ( T_1 * ) F_44 ( V_117 | V_98 ) ;
if ( ! V_86 -> V_90 )
goto V_118;
F_1 ( V_86 -> V_90 , V_119 ) ;
F_68 ( & V_86 -> V_94 ) ;
F_68 ( & V_86 -> V_89 ) ;
F_69 ( & V_86 -> V_115 ) ;
return & V_86 -> V_9 ;
V_118:
F_70 ( V_86 ) ;
return NULL ;
}
static void F_71 ( struct V_7 * V_9 )
{
struct V_6 * V_86 = F_5 ( V_9 ) ;
int V_120 ;
F_72 ( ! F_73 ( & V_86 -> V_115 ) ) ;
for ( V_120 = 0 ; V_120 < V_119 ; V_120 ++ ) {
T_1 V_10 = V_86 -> V_90 [ V_120 ] ;
if ( F_8 ( V_10 ) ) {
T_2 V_14 = F_7 ( V_10 ) ;
T_1 * V_88 = F_33 ( V_14 ) ;
F_74 ( ( unsigned long ) V_88 ) ;
}
}
F_74 ( ( unsigned long ) V_86 -> V_90 ) ;
F_70 ( V_86 ) ;
}
static bool F_75 ( struct V_109 * V_47 )
{
struct V_121 * V_122 = V_47 -> V_123 ;
int V_45 ;
V_45 = F_76 ( V_122 , L_18 , L_19 ) ;
return ( V_45 > 0 ) ;
}
static int F_77 ( struct V_110 * V_111 ,
struct V_109 * V_47 )
{
struct V_121 * V_122 = V_47 -> V_123 ;
struct V_124 * V_125 ;
int V_45 ;
struct V_126 args ;
V_45 = F_78 ( V_122 , L_18 , L_19 , 0 ,
& args ) ;
if ( V_45 ) {
F_27 ( V_47 , L_20 ,
V_122 -> V_127 , V_45 ) ;
return V_45 ;
}
if ( args . V_128 != 0 ) {
F_27 ( V_47 , L_21 ,
args . V_122 -> V_127 , args . V_128 ) ;
return - V_129 ;
}
V_125 = F_79 ( args . V_122 ) ;
F_80 ( args . V_122 ) ;
if ( ! V_125 ) {
F_27 ( V_47 , L_22 , args . V_122 -> V_127 ) ;
return - V_130 ;
}
F_81 ( V_111 , & V_125 -> V_47 , NULL ) ;
return 0 ;
}
static int F_82 ( struct V_109 * V_47 )
{
struct V_110 * V_111 ;
int V_45 ;
if ( ! F_75 ( V_47 ) )
return - V_131 ;
V_111 = F_54 ( V_47 ) ;
if ( ! V_111 ) {
V_111 = F_83 () ;
if ( F_50 ( V_111 ) ) {
F_27 ( V_47 , L_23 ) ;
return F_51 ( V_111 ) ;
}
}
V_45 = F_84 ( V_111 , V_47 ) ;
if ( V_45 )
goto V_132;
V_45 = F_77 ( V_111 , V_47 ) ;
if ( V_45 )
goto V_133;
F_57 ( V_111 ) ;
return 0 ;
V_133:
F_85 ( V_47 ) ;
V_132:
F_57 ( V_111 ) ;
return V_45 ;
}
static void F_86 ( struct V_109 * V_47 )
{
if ( ! F_75 ( V_47 ) )
return;
F_85 ( V_47 ) ;
}
static int F_87 ( struct V_124 * V_134 )
{
struct V_109 * V_47 = & V_134 -> V_47 ;
struct V_32 * V_33 ;
struct V_135 * V_136 ;
V_33 = F_88 ( V_47 , sizeof( * V_33 ) , V_117 ) ;
if ( ! V_33 )
return - V_99 ;
F_89 ( V_134 , V_33 ) ;
V_33 -> V_47 = V_47 ;
V_136 = F_90 ( V_134 , V_137 , 0 ) ;
V_33 -> V_35 = F_91 ( & V_134 -> V_47 , V_136 ) ;
if ( F_50 ( V_33 -> V_35 ) )
return F_51 ( V_33 -> V_35 ) ;
V_33 -> V_69 = F_92 ( V_134 , 0 ) ;
if ( V_33 -> V_69 < 0 ) {
F_27 ( V_47 , L_24 , V_33 -> V_69 ) ;
return - V_138 ;
}
return 0 ;
}
static int F_93 ( struct V_124 * V_134 )
{
return 0 ;
}
static int T_6 F_94 ( void )
{
struct V_121 * V_122 ;
int V_45 ;
V_122 = F_95 ( NULL , V_139 ) ;
if ( ! V_122 )
return 0 ;
F_80 ( V_122 ) ;
V_45 = F_96 ( & V_140 , & V_141 ) ;
if ( V_45 )
return V_45 ;
return F_97 ( & V_142 ) ;
}
static void T_7 F_98 ( void )
{
F_99 ( & V_142 ) ;
}
