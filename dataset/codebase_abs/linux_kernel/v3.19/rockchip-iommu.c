static inline void F_1 ( T_1 * V_1 , unsigned int V_2 )
{
T_2 V_3 = F_2 ( V_1 ) ;
T_2 V_4 = F_2 ( V_1 + V_2 ) ;
T_3 V_5 = V_4 - V_3 ;
F_3 ( V_1 , V_5 ) ;
F_4 ( V_3 , V_4 ) ;
}
static inline T_2 F_5 ( T_1 V_6 )
{
return ( T_2 ) V_6 & V_7 ;
}
static inline bool F_6 ( T_1 V_6 )
{
return V_6 & V_8 ;
}
static T_1 F_7 ( T_1 * V_9 )
{
T_2 V_10 = F_2 ( V_9 ) ;
return ( V_10 & V_7 ) | V_8 ;
}
static inline T_2 F_8 ( T_1 V_11 )
{
return ( T_2 ) V_11 & V_12 ;
}
static inline bool F_9 ( T_1 V_11 )
{
return V_11 & V_13 ;
}
static T_1 F_10 ( T_2 V_14 , int V_15 )
{
T_1 V_16 = 0 ;
V_16 |= ( V_15 & V_17 ) ? V_18 : 0 ;
V_16 |= ( V_15 & V_19 ) ? V_20 : 0 ;
V_14 &= V_12 ;
return V_14 | V_16 | V_13 ;
}
static T_1 F_11 ( T_1 V_11 )
{
return V_11 & ~ V_13 ;
}
static T_1 F_12 ( T_4 V_21 )
{
return ( T_1 ) ( V_21 & V_22 ) >> V_23 ;
}
static T_1 F_13 ( T_4 V_21 )
{
return ( T_1 ) ( V_21 & V_24 ) >> V_25 ;
}
static T_1 F_14 ( T_4 V_21 )
{
return ( T_1 ) ( V_21 & V_26 ) >> V_27 ;
}
static T_1 F_15 ( struct V_28 * V_29 , T_1 V_30 )
{
return F_16 ( V_29 -> V_31 + V_30 ) ;
}
static void F_17 ( struct V_28 * V_29 , T_1 V_30 , T_1 V_32 )
{
F_18 ( V_32 , V_29 -> V_31 + V_30 ) ;
}
static void F_19 ( struct V_28 * V_29 , T_1 V_33 )
{
F_18 ( V_33 , V_29 -> V_31 + V_34 ) ;
}
static void F_20 ( struct V_28 * V_29 , T_4 V_21 ,
T_3 V_5 )
{
T_4 V_35 = V_21 + V_5 ;
for (; V_21 < V_35 ; V_21 += V_36 )
F_17 ( V_29 , V_37 , V_21 ) ;
}
static bool F_21 ( struct V_28 * V_29 )
{
return F_15 ( V_29 , V_38 ) & V_39 ;
}
static bool F_22 ( struct V_28 * V_29 )
{
return F_15 ( V_29 , V_38 ) &
V_40 ;
}
static int F_23 ( struct V_28 * V_29 )
{
int V_41 ;
if ( F_21 ( V_29 ) )
return 0 ;
if ( ! F_22 ( V_29 ) )
return 0 ;
F_19 ( V_29 , V_42 ) ;
V_41 = F_24 ( F_21 ( V_29 ) , 1 ) ;
if ( V_41 )
F_25 ( V_29 -> V_43 , L_1 ,
F_15 ( V_29 , V_38 ) ) ;
return V_41 ;
}
static int F_26 ( struct V_28 * V_29 )
{
int V_41 ;
if ( ! F_21 ( V_29 ) )
return 0 ;
F_19 ( V_29 , V_44 ) ;
V_41 = F_24 ( ! F_21 ( V_29 ) , 1 ) ;
if ( V_41 )
F_25 ( V_29 -> V_43 , L_2 ,
F_15 ( V_29 , V_38 ) ) ;
return V_41 ;
}
static int F_27 ( struct V_28 * V_29 )
{
int V_41 ;
if ( F_22 ( V_29 ) )
return 0 ;
F_19 ( V_29 , V_45 ) ;
V_41 = F_24 ( F_22 ( V_29 ) , 1 ) ;
if ( V_41 )
F_25 ( V_29 -> V_43 , L_3 ,
F_15 ( V_29 , V_38 ) ) ;
return V_41 ;
}
static int F_28 ( struct V_28 * V_29 )
{
int V_41 ;
if ( ! F_22 ( V_29 ) )
return 0 ;
F_19 ( V_29 , V_46 ) ;
V_41 = F_24 ( ! F_22 ( V_29 ) , 1 ) ;
if ( V_41 )
F_25 ( V_29 -> V_43 , L_4 ,
F_15 ( V_29 , V_38 ) ) ;
return V_41 ;
}
static int F_29 ( struct V_28 * V_29 )
{
int V_41 ;
T_1 V_47 ;
F_17 ( V_29 , V_48 , V_49 ) ;
V_47 = F_15 ( V_29 , V_48 ) ;
if ( V_47 != ( V_49 & V_7 ) ) {
F_25 ( V_29 -> V_43 , L_5 ) ;
return - V_50 ;
}
F_19 ( V_29 , V_51 ) ;
V_41 = F_24 ( F_15 ( V_29 , V_48 ) == 0x00000000 ,
V_52 ) ;
if ( V_41 )
F_25 ( V_29 -> V_43 , L_6 ) ;
return V_41 ;
}
static void F_30 ( struct V_28 * V_29 , T_4 V_21 )
{
T_1 V_53 , V_54 , V_55 ;
T_1 V_56 ;
T_2 V_57 , V_58 ;
T_1 * V_47 ;
T_1 V_6 ;
T_2 V_59 = 0 ;
T_1 * V_60 = NULL ;
T_1 V_11 = 0 ;
T_2 V_61 = 0 ;
T_1 V_62 = 0 ;
V_53 = F_12 ( V_21 ) ;
V_54 = F_13 ( V_21 ) ;
V_55 = F_14 ( V_21 ) ;
V_56 = F_15 ( V_29 , V_48 ) ;
V_57 = ( T_2 ) V_56 ;
V_58 = V_57 + ( 4 * V_53 ) ;
V_47 = F_31 ( V_58 ) ;
V_6 = * V_47 ;
if ( ! F_6 ( V_6 ) )
goto V_63;
V_59 = F_5 ( V_6 ) + ( V_54 * 4 ) ;
V_60 = F_31 ( V_59 ) ;
V_11 = * V_60 ;
if ( ! F_9 ( V_11 ) )
goto V_63;
V_61 = F_8 ( V_11 ) + V_55 ;
V_62 = V_11 & V_64 ;
V_63:
F_25 ( V_29 -> V_43 , L_7 ,
& V_21 , V_53 , V_54 , V_55 ) ;
F_25 ( V_29 -> V_43 , L_8 ,
& V_57 , & V_58 , V_6 ,
F_6 ( V_6 ) , & V_59 , V_11 ,
F_9 ( V_11 ) , & V_61 , V_62 ) ;
}
static T_5 F_32 ( int V_65 , void * V_66 )
{
struct V_28 * V_29 = V_66 ;
T_1 V_67 ;
T_1 V_68 ;
T_4 V_21 ;
V_68 = F_15 ( V_29 , V_69 ) ;
if ( V_68 == 0 )
return V_70 ;
V_21 = F_15 ( V_29 , V_71 ) ;
if ( V_68 & V_72 ) {
int V_16 ;
V_67 = F_15 ( V_29 , V_38 ) ;
V_16 = ( V_67 & V_73 ) ?
V_74 : V_75 ;
F_25 ( V_29 -> V_43 , L_9 ,
& V_21 ,
( V_16 == V_74 ) ? L_10 : L_11 ) ;
F_30 ( V_29 , V_21 ) ;
if ( V_29 -> V_76 )
F_33 ( V_29 -> V_76 , V_29 -> V_43 , V_21 ,
V_16 ) ;
else
F_25 ( V_29 -> V_43 , L_12 ) ;
F_19 ( V_29 , V_77 ) ;
F_19 ( V_29 , V_78 ) ;
}
if ( V_68 & V_79 )
F_25 ( V_29 -> V_43 , L_13 , & V_21 ) ;
if ( V_68 & ~ V_80 )
F_25 ( V_29 -> V_43 , L_14 ,
V_68 ) ;
F_17 ( V_29 , V_81 , V_68 ) ;
return V_82 ;
}
static T_2 F_34 ( struct V_83 * V_76 ,
T_4 V_21 )
{
struct V_84 * V_85 = V_76 -> V_86 ;
unsigned long V_16 ;
T_2 V_10 , V_87 = 0 ;
T_1 V_6 , V_11 ;
T_1 * V_88 ;
F_35 ( & V_85 -> V_89 , V_16 ) ;
V_6 = V_85 -> V_90 [ F_12 ( V_21 ) ] ;
if ( ! F_6 ( V_6 ) )
goto V_91;
V_10 = F_5 ( V_6 ) ;
V_88 = ( T_1 * ) F_31 ( V_10 ) ;
V_11 = V_88 [ F_13 ( V_21 ) ] ;
if ( ! F_9 ( V_11 ) )
goto V_91;
V_87 = F_8 ( V_11 ) + F_14 ( V_21 ) ;
V_91:
F_36 ( & V_85 -> V_89 , V_16 ) ;
return V_87 ;
}
static void F_37 ( struct V_84 * V_85 ,
T_4 V_21 , T_3 V_5 )
{
struct V_92 * V_93 ;
unsigned long V_16 ;
F_35 ( & V_85 -> V_94 , V_16 ) ;
F_38 (pos, &rk_domain->iommus) {
struct V_28 * V_29 ;
V_29 = F_39 ( V_93 , struct V_28 , V_95 ) ;
F_20 ( V_29 , V_21 , V_5 ) ;
}
F_36 ( & V_85 -> V_94 , V_16 ) ;
}
static T_1 * F_40 ( struct V_84 * V_85 ,
T_4 V_21 )
{
T_1 * V_88 , * V_47 ;
T_1 V_6 ;
T_2 V_10 ;
F_41 ( & V_85 -> V_89 ) ;
V_47 = & V_85 -> V_90 [ F_12 ( V_21 ) ] ;
V_6 = * V_47 ;
if ( F_6 ( V_6 ) )
goto V_96;
V_88 = ( T_1 * ) F_42 ( V_97 | V_98 ) ;
if ( ! V_88 )
return F_43 ( - V_99 ) ;
V_6 = F_7 ( V_88 ) ;
* V_47 = V_6 ;
F_1 ( V_88 , V_100 ) ;
F_1 ( V_47 , 1 ) ;
F_37 ( V_85 , V_21 , V_36 ) ;
V_96:
V_10 = F_5 ( V_6 ) ;
return ( T_1 * ) F_31 ( V_10 ) ;
}
static T_3 F_44 ( struct V_84 * V_85 ,
T_1 * V_60 , T_4 V_21 , T_3 V_5 )
{
unsigned int V_101 ;
unsigned int V_102 = V_5 / V_36 ;
F_41 ( & V_85 -> V_89 ) ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ ) {
T_1 V_11 = V_60 [ V_101 ] ;
if ( ! F_9 ( V_11 ) )
break;
V_60 [ V_101 ] = F_11 ( V_11 ) ;
}
F_1 ( V_60 , V_101 ) ;
return V_101 * V_36 ;
}
static int F_45 ( struct V_84 * V_85 , T_1 * V_60 ,
T_4 V_21 , T_2 V_103 , T_3 V_5 ,
int V_15 )
{
unsigned int V_101 ;
unsigned int V_102 = V_5 / V_36 ;
T_2 V_104 ;
F_41 ( & V_85 -> V_89 ) ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ ) {
T_1 V_11 = V_60 [ V_101 ] ;
if ( F_9 ( V_11 ) )
goto V_105;
V_60 [ V_101 ] = F_10 ( V_103 , V_15 ) ;
V_103 += V_36 ;
}
F_1 ( V_60 , V_101 ) ;
return 0 ;
V_105:
F_44 ( V_85 , V_60 , V_21 , V_101 * V_36 ) ;
V_21 += V_101 * V_36 ;
V_104 = F_8 ( V_60 [ V_101 ] ) ;
F_46 ( L_15 ,
& V_21 , & V_104 , & V_103 , V_15 ) ;
return - V_106 ;
}
static int F_47 ( struct V_83 * V_76 , unsigned long V_107 ,
T_2 V_103 , T_3 V_5 , int V_15 )
{
struct V_84 * V_85 = V_76 -> V_86 ;
unsigned long V_16 ;
T_4 V_21 = ( T_4 ) V_107 ;
T_1 * V_88 , * V_60 ;
int V_41 ;
F_35 ( & V_85 -> V_89 , V_16 ) ;
V_88 = F_40 ( V_85 , V_21 ) ;
if ( F_48 ( V_88 ) ) {
F_36 ( & V_85 -> V_89 , V_16 ) ;
return F_49 ( V_88 ) ;
}
V_60 = & V_88 [ F_13 ( V_21 ) ] ;
V_41 = F_45 ( V_85 , V_60 , V_21 , V_103 , V_5 , V_15 ) ;
F_36 ( & V_85 -> V_89 , V_16 ) ;
return V_41 ;
}
static T_3 F_50 ( struct V_83 * V_76 , unsigned long V_107 ,
T_3 V_5 )
{
struct V_84 * V_85 = V_76 -> V_86 ;
unsigned long V_16 ;
T_4 V_21 = ( T_4 ) V_107 ;
T_2 V_10 ;
T_1 V_6 ;
T_1 * V_60 ;
T_3 V_108 ;
F_35 ( & V_85 -> V_89 , V_16 ) ;
V_6 = V_85 -> V_90 [ F_12 ( V_21 ) ] ;
if ( ! F_6 ( V_6 ) ) {
F_36 ( & V_85 -> V_89 , V_16 ) ;
return 0 ;
}
V_10 = F_5 ( V_6 ) ;
V_60 = ( T_1 * ) F_31 ( V_10 ) + F_13 ( V_21 ) ;
V_108 = F_44 ( V_85 , V_60 , V_21 , V_5 ) ;
F_36 ( & V_85 -> V_89 , V_16 ) ;
F_37 ( V_85 , V_21 , V_108 ) ;
return V_108 ;
}
static struct V_28 * F_51 ( struct V_109 * V_43 )
{
struct V_110 * V_111 ;
struct V_109 * V_112 ;
struct V_28 * V_28 ;
V_111 = F_52 ( V_43 ) ;
if ( ! V_111 )
return NULL ;
V_112 = F_53 ( V_111 ) ;
V_28 = F_54 ( V_112 ) ;
F_55 ( V_111 ) ;
return V_28 ;
}
static int F_56 ( struct V_83 * V_76 ,
struct V_109 * V_43 )
{
struct V_28 * V_29 ;
struct V_84 * V_85 = V_76 -> V_86 ;
unsigned long V_16 ;
int V_41 ;
T_2 V_47 ;
V_29 = F_51 ( V_43 ) ;
if ( ! V_29 )
return 0 ;
V_41 = F_23 ( V_29 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_29 ( V_29 ) ;
if ( V_41 )
return V_41 ;
V_29 -> V_76 = V_76 ;
V_41 = F_57 ( V_43 , V_29 -> V_65 , F_32 ,
V_113 , F_58 ( V_43 ) , V_29 ) ;
if ( V_41 )
return V_41 ;
V_47 = F_2 ( V_85 -> V_90 ) ;
F_17 ( V_29 , V_48 , V_47 ) ;
F_19 ( V_29 , V_77 ) ;
F_17 ( V_29 , V_114 , V_80 ) ;
V_41 = F_27 ( V_29 ) ;
if ( V_41 )
return V_41 ;
F_35 ( & V_85 -> V_94 , V_16 ) ;
F_59 ( & V_29 -> V_95 , & V_85 -> V_115 ) ;
F_36 ( & V_85 -> V_94 , V_16 ) ;
F_60 ( V_43 , L_16 ) ;
F_26 ( V_29 ) ;
return 0 ;
}
static void F_61 ( struct V_83 * V_76 ,
struct V_109 * V_43 )
{
struct V_28 * V_29 ;
struct V_84 * V_85 = V_76 -> V_86 ;
unsigned long V_16 ;
V_29 = F_51 ( V_43 ) ;
if ( ! V_29 )
return;
F_35 ( & V_85 -> V_94 , V_16 ) ;
F_62 ( & V_29 -> V_95 ) ;
F_36 ( & V_85 -> V_94 , V_16 ) ;
F_23 ( V_29 ) ;
F_28 ( V_29 ) ;
F_17 ( V_29 , V_114 , 0 ) ;
F_17 ( V_29 , V_48 , 0 ) ;
F_26 ( V_29 ) ;
F_63 ( V_43 , V_29 -> V_65 , V_29 ) ;
V_29 -> V_76 = NULL ;
F_60 ( V_43 , L_17 ) ;
}
static int F_64 ( struct V_83 * V_76 )
{
struct V_84 * V_85 ;
V_85 = F_65 ( sizeof( * V_85 ) , V_116 ) ;
if ( ! V_85 )
return - V_99 ;
V_85 -> V_90 = ( T_1 * ) F_42 ( V_116 | V_98 ) ;
if ( ! V_85 -> V_90 )
goto V_117;
F_1 ( V_85 -> V_90 , V_118 ) ;
F_66 ( & V_85 -> V_94 ) ;
F_66 ( & V_85 -> V_89 ) ;
F_67 ( & V_85 -> V_115 ) ;
V_76 -> V_86 = V_85 ;
return 0 ;
V_117:
F_68 ( V_85 ) ;
return - V_99 ;
}
static void F_69 ( struct V_83 * V_76 )
{
struct V_84 * V_85 = V_76 -> V_86 ;
int V_119 ;
F_70 ( ! F_71 ( & V_85 -> V_115 ) ) ;
for ( V_119 = 0 ; V_119 < V_118 ; V_119 ++ ) {
T_1 V_6 = V_85 -> V_90 [ V_119 ] ;
if ( F_6 ( V_6 ) ) {
T_2 V_10 = F_5 ( V_6 ) ;
T_1 * V_88 = F_31 ( V_10 ) ;
F_72 ( ( unsigned long ) V_88 ) ;
}
}
F_72 ( ( unsigned long ) V_85 -> V_90 ) ;
F_68 ( V_76 -> V_86 ) ;
V_76 -> V_86 = NULL ;
}
static bool F_73 ( struct V_109 * V_43 )
{
struct V_120 * V_121 = V_43 -> V_122 ;
int V_41 ;
V_41 = F_74 ( V_121 , L_18 , L_19 ) ;
return ( V_41 > 0 ) ;
}
static int F_75 ( struct V_110 * V_111 ,
struct V_109 * V_43 )
{
struct V_120 * V_121 = V_43 -> V_122 ;
struct V_123 * V_124 ;
int V_41 ;
struct V_125 args ;
V_41 = F_76 ( V_121 , L_18 , L_19 , 0 ,
& args ) ;
if ( V_41 ) {
F_25 ( V_43 , L_20 ,
V_121 -> V_126 , V_41 ) ;
return V_41 ;
}
if ( args . V_127 != 0 ) {
F_25 ( V_43 , L_21 ,
args . V_121 -> V_126 , args . V_127 ) ;
return - V_128 ;
}
V_124 = F_77 ( args . V_121 ) ;
F_78 ( args . V_121 ) ;
if ( ! V_124 ) {
F_25 ( V_43 , L_22 , args . V_121 -> V_126 ) ;
return - V_129 ;
}
F_79 ( V_111 , & V_124 -> V_43 , NULL ) ;
return 0 ;
}
static int F_80 ( struct V_109 * V_43 )
{
struct V_110 * V_111 ;
int V_41 ;
if ( ! F_73 ( V_43 ) )
return - V_130 ;
V_111 = F_52 ( V_43 ) ;
if ( ! V_111 ) {
V_111 = F_81 () ;
if ( F_48 ( V_111 ) ) {
F_25 ( V_43 , L_23 ) ;
return F_49 ( V_111 ) ;
}
}
V_41 = F_82 ( V_111 , V_43 ) ;
if ( V_41 )
goto V_131;
V_41 = F_75 ( V_111 , V_43 ) ;
if ( V_41 )
goto V_132;
F_55 ( V_111 ) ;
return 0 ;
V_132:
F_83 ( V_43 ) ;
V_131:
F_55 ( V_111 ) ;
return V_41 ;
}
static void F_84 ( struct V_109 * V_43 )
{
if ( ! F_73 ( V_43 ) )
return;
F_83 ( V_43 ) ;
}
static int F_85 ( struct V_123 * V_133 )
{
struct V_109 * V_43 = & V_133 -> V_43 ;
struct V_28 * V_29 ;
struct V_134 * V_135 ;
V_29 = F_86 ( V_43 , sizeof( * V_29 ) , V_116 ) ;
if ( ! V_29 )
return - V_99 ;
F_87 ( V_133 , V_29 ) ;
V_29 -> V_43 = V_43 ;
V_135 = F_88 ( V_133 , V_136 , 0 ) ;
V_29 -> V_31 = F_89 ( & V_133 -> V_43 , V_135 ) ;
if ( F_48 ( V_29 -> V_31 ) )
return F_49 ( V_29 -> V_31 ) ;
V_29 -> V_65 = F_90 ( V_133 , 0 ) ;
if ( V_29 -> V_65 < 0 ) {
F_25 ( V_43 , L_24 , V_29 -> V_65 ) ;
return - V_137 ;
}
return 0 ;
}
static int F_91 ( struct V_123 * V_133 )
{
return 0 ;
}
static int T_6 F_92 ( void )
{
int V_41 ;
V_41 = F_93 ( & V_138 , & V_139 ) ;
if ( V_41 )
return V_41 ;
return F_94 ( & V_140 ) ;
}
static void T_7 F_95 ( void )
{
F_96 ( & V_140 ) ;
}
