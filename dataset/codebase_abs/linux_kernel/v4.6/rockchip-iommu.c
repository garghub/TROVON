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
static T_1 F_17 ( void T_5 * V_32 , T_1 V_33 )
{
return F_18 ( V_32 + V_33 ) ;
}
static void F_19 ( void T_5 * V_32 , T_1 V_33 , T_1 V_34 )
{
F_20 ( V_34 , V_32 + V_33 ) ;
}
static void F_21 ( struct V_35 * V_36 , T_1 V_37 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ )
F_20 ( V_37 , V_36 -> V_40 [ V_38 ] + V_41 ) ;
}
static void F_22 ( void T_5 * V_32 , T_1 V_37 )
{
F_20 ( V_37 , V_32 + V_41 ) ;
}
static void F_23 ( struct V_35 * V_36 , T_4 V_25 ,
T_3 V_5 )
{
int V_38 ;
T_4 V_42 = V_25 + V_5 ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ )
for (; V_25 < V_42 ; V_25 += V_43 )
F_19 ( V_36 -> V_40 [ V_38 ] , V_44 , V_25 ) ;
}
static bool F_24 ( struct V_35 * V_36 )
{
bool V_45 = true ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ )
V_45 &= ! ! ( F_17 ( V_36 -> V_40 [ V_38 ] , V_46 ) &
V_47 ) ;
return V_45 ;
}
static bool F_25 ( struct V_35 * V_36 )
{
bool V_48 = true ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ )
V_48 &= ! ! ( F_17 ( V_36 -> V_40 [ V_38 ] , V_46 ) &
V_49 ) ;
return V_48 ;
}
static int F_26 ( struct V_35 * V_36 )
{
int V_50 , V_38 ;
if ( F_24 ( V_36 ) )
return 0 ;
if ( ! F_25 ( V_36 ) )
return 0 ;
F_21 ( V_36 , V_51 ) ;
V_50 = F_27 ( F_24 ( V_36 ) , 1 ) ;
if ( V_50 )
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ )
F_28 ( V_36 -> V_52 , L_1 ,
F_17 ( V_36 -> V_40 [ V_38 ] , V_46 ) ) ;
return V_50 ;
}
static int F_29 ( struct V_35 * V_36 )
{
int V_50 , V_38 ;
if ( ! F_24 ( V_36 ) )
return 0 ;
F_21 ( V_36 , V_53 ) ;
V_50 = F_27 ( ! F_24 ( V_36 ) , 1 ) ;
if ( V_50 )
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ )
F_28 ( V_36 -> V_52 , L_2 ,
F_17 ( V_36 -> V_40 [ V_38 ] , V_46 ) ) ;
return V_50 ;
}
static int F_30 ( struct V_35 * V_36 )
{
int V_50 , V_38 ;
if ( F_25 ( V_36 ) )
return 0 ;
F_21 ( V_36 , V_54 ) ;
V_50 = F_27 ( F_25 ( V_36 ) , 1 ) ;
if ( V_50 )
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ )
F_28 ( V_36 -> V_52 , L_3 ,
F_17 ( V_36 -> V_40 [ V_38 ] , V_46 ) ) ;
return V_50 ;
}
static int F_31 ( struct V_35 * V_36 )
{
int V_50 , V_38 ;
if ( ! F_25 ( V_36 ) )
return 0 ;
F_21 ( V_36 , V_55 ) ;
V_50 = F_27 ( ! F_25 ( V_36 ) , 1 ) ;
if ( V_50 )
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ )
F_28 ( V_36 -> V_52 , L_4 ,
F_17 ( V_36 -> V_40 [ V_38 ] , V_46 ) ) ;
return V_50 ;
}
static int F_32 ( struct V_35 * V_36 )
{
int V_50 , V_38 ;
T_1 V_56 ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ ) {
F_19 ( V_36 -> V_40 [ V_38 ] , V_57 , V_58 ) ;
V_56 = F_17 ( V_36 -> V_40 [ V_38 ] , V_57 ) ;
if ( V_56 != ( V_58 & V_11 ) ) {
F_28 ( V_36 -> V_52 , L_5 ) ;
return - V_59 ;
}
}
F_21 ( V_36 , V_60 ) ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ ) {
V_50 = F_27 ( F_17 ( V_36 -> V_40 [ V_38 ] , V_57 ) == 0x00000000 ,
V_61 ) ;
if ( V_50 ) {
F_28 ( V_36 -> V_52 , L_6 ) ;
return V_50 ;
}
}
return 0 ;
}
static void F_33 ( struct V_35 * V_36 , int V_62 , T_4 V_25 )
{
void T_5 * V_32 = V_36 -> V_40 [ V_62 ] ;
T_1 V_63 , V_64 , V_65 ;
T_1 V_66 ;
T_2 V_67 , V_68 ;
T_1 * V_56 ;
T_1 V_10 ;
T_2 V_69 = 0 ;
T_1 * V_70 = NULL ;
T_1 V_15 = 0 ;
T_2 V_71 = 0 ;
T_1 V_72 = 0 ;
V_63 = F_14 ( V_25 ) ;
V_64 = F_15 ( V_25 ) ;
V_65 = F_16 ( V_25 ) ;
V_66 = F_17 ( V_32 , V_57 ) ;
V_67 = ( T_2 ) V_66 ;
V_68 = V_67 + ( 4 * V_63 ) ;
V_56 = F_34 ( V_68 ) ;
V_10 = * V_56 ;
if ( ! F_8 ( V_10 ) )
goto V_73;
V_69 = F_7 ( V_10 ) + ( V_64 * 4 ) ;
V_70 = F_34 ( V_69 ) ;
V_15 = * V_70 ;
if ( ! F_11 ( V_15 ) )
goto V_73;
V_71 = F_10 ( V_15 ) + V_65 ;
V_72 = V_15 & V_74 ;
V_73:
F_28 ( V_36 -> V_52 , L_7 ,
& V_25 , V_63 , V_64 , V_65 ) ;
F_28 ( V_36 -> V_52 , L_8 ,
& V_67 , & V_68 , V_10 ,
F_8 ( V_10 ) , & V_69 , V_15 ,
F_11 ( V_15 ) , & V_71 , V_72 ) ;
}
static T_6 F_35 ( int V_75 , void * V_76 )
{
struct V_35 * V_36 = V_76 ;
T_1 V_77 ;
T_1 V_78 ;
T_4 V_25 ;
T_6 V_50 = V_79 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ ) {
V_78 = F_17 ( V_36 -> V_40 [ V_38 ] , V_80 ) ;
if ( V_78 == 0 )
continue;
V_50 = V_81 ;
V_25 = F_17 ( V_36 -> V_40 [ V_38 ] , V_82 ) ;
if ( V_78 & V_83 ) {
int V_20 ;
V_77 = F_17 ( V_36 -> V_40 [ V_38 ] , V_46 ) ;
V_20 = ( V_77 & V_84 ) ?
V_85 : V_86 ;
F_28 ( V_36 -> V_52 , L_9 ,
& V_25 ,
( V_20 == V_85 ) ? L_10 : L_11 ) ;
F_33 ( V_36 , V_38 , V_25 ) ;
if ( V_36 -> V_9 )
F_36 ( V_36 -> V_9 , V_36 -> V_52 , V_25 ,
V_20 ) ;
else
F_28 ( V_36 -> V_52 , L_12 ) ;
F_22 ( V_36 -> V_40 [ V_38 ] , V_87 ) ;
F_22 ( V_36 -> V_40 [ V_38 ] , V_88 ) ;
}
if ( V_78 & V_89 )
F_28 ( V_36 -> V_52 , L_13 , & V_25 ) ;
if ( V_78 & ~ V_90 )
F_28 ( V_36 -> V_52 , L_14 ,
V_78 ) ;
F_19 ( V_36 -> V_40 [ V_38 ] , V_91 , V_78 ) ;
}
return V_50 ;
}
static T_2 F_37 ( struct V_7 * V_9 ,
T_4 V_25 )
{
struct V_6 * V_92 = F_5 ( V_9 ) ;
unsigned long V_20 ;
T_2 V_14 , V_93 = 0 ;
T_1 V_10 , V_15 ;
T_1 * V_94 ;
F_38 ( & V_92 -> V_95 , V_20 ) ;
V_10 = V_92 -> V_96 [ F_14 ( V_25 ) ] ;
if ( ! F_8 ( V_10 ) )
goto V_97;
V_14 = F_7 ( V_10 ) ;
V_94 = ( T_1 * ) F_34 ( V_14 ) ;
V_15 = V_94 [ F_15 ( V_25 ) ] ;
if ( ! F_11 ( V_15 ) )
goto V_97;
V_93 = F_10 ( V_15 ) + F_16 ( V_25 ) ;
V_97:
F_39 ( & V_92 -> V_95 , V_20 ) ;
return V_93 ;
}
static void F_40 ( struct V_6 * V_92 ,
T_4 V_25 , T_3 V_5 )
{
struct V_98 * V_99 ;
unsigned long V_20 ;
F_38 ( & V_92 -> V_100 , V_20 ) ;
F_41 (pos, &rk_domain->iommus) {
struct V_35 * V_36 ;
V_36 = F_42 ( V_99 , struct V_35 , V_101 ) ;
F_23 ( V_36 , V_25 , V_5 ) ;
}
F_39 ( & V_92 -> V_100 , V_20 ) ;
}
static void F_43 ( struct V_6 * V_92 ,
T_4 V_25 , T_3 V_5 )
{
F_40 ( V_92 , V_25 , V_43 ) ;
if ( V_5 > V_43 )
F_40 ( V_92 , V_25 + V_5 - V_43 ,
V_43 ) ;
}
static T_1 * F_44 ( struct V_6 * V_92 ,
T_4 V_25 )
{
T_1 * V_94 , * V_56 ;
T_1 V_10 ;
T_2 V_14 ;
F_45 ( & V_92 -> V_95 ) ;
V_56 = & V_92 -> V_96 [ F_14 ( V_25 ) ] ;
V_10 = * V_56 ;
if ( F_8 ( V_10 ) )
goto V_102;
V_94 = ( T_1 * ) F_46 ( V_103 | V_104 ) ;
if ( ! V_94 )
return F_47 ( - V_105 ) ;
V_10 = F_9 ( V_94 ) ;
* V_56 = V_10 ;
F_1 ( V_94 , V_106 ) ;
F_1 ( V_56 , 1 ) ;
V_102:
V_14 = F_7 ( V_10 ) ;
return ( T_1 * ) F_34 ( V_14 ) ;
}
static T_3 F_48 ( struct V_6 * V_92 ,
T_1 * V_70 , T_4 V_25 , T_3 V_5 )
{
unsigned int V_107 ;
unsigned int V_108 = V_5 / V_43 ;
F_45 ( & V_92 -> V_95 ) ;
for ( V_107 = 0 ; V_107 < V_108 ; V_107 ++ ) {
T_1 V_15 = V_70 [ V_107 ] ;
if ( ! F_11 ( V_15 ) )
break;
V_70 [ V_107 ] = F_13 ( V_15 ) ;
}
F_1 ( V_70 , V_107 ) ;
return V_107 * V_43 ;
}
static int F_49 ( struct V_6 * V_92 , T_1 * V_70 ,
T_4 V_25 , T_2 V_109 , T_3 V_5 ,
int V_19 )
{
unsigned int V_107 ;
unsigned int V_108 = V_5 / V_43 ;
T_2 V_110 ;
F_45 ( & V_92 -> V_95 ) ;
for ( V_107 = 0 ; V_107 < V_108 ; V_107 ++ ) {
T_1 V_15 = V_70 [ V_107 ] ;
if ( F_11 ( V_15 ) )
goto V_111;
V_70 [ V_107 ] = F_12 ( V_109 , V_19 ) ;
V_109 += V_43 ;
}
F_1 ( V_70 , V_107 ) ;
F_43 ( V_92 , V_25 , V_5 ) ;
return 0 ;
V_111:
F_48 ( V_92 , V_70 , V_25 , V_107 * V_43 ) ;
V_25 += V_107 * V_43 ;
V_110 = F_10 ( V_70 [ V_107 ] ) ;
F_50 ( L_15 ,
& V_25 , & V_110 , & V_109 , V_19 ) ;
return - V_112 ;
}
static int F_51 ( struct V_7 * V_9 , unsigned long V_113 ,
T_2 V_109 , T_3 V_5 , int V_19 )
{
struct V_6 * V_92 = F_5 ( V_9 ) ;
unsigned long V_20 ;
T_4 V_25 = ( T_4 ) V_113 ;
T_1 * V_94 , * V_70 ;
int V_50 ;
F_38 ( & V_92 -> V_95 , V_20 ) ;
V_94 = F_44 ( V_92 , V_25 ) ;
if ( F_52 ( V_94 ) ) {
F_39 ( & V_92 -> V_95 , V_20 ) ;
return F_53 ( V_94 ) ;
}
V_70 = & V_94 [ F_15 ( V_25 ) ] ;
V_50 = F_49 ( V_92 , V_70 , V_25 , V_109 , V_5 , V_19 ) ;
F_39 ( & V_92 -> V_95 , V_20 ) ;
return V_50 ;
}
static T_3 F_54 ( struct V_7 * V_9 , unsigned long V_113 ,
T_3 V_5 )
{
struct V_6 * V_92 = F_5 ( V_9 ) ;
unsigned long V_20 ;
T_4 V_25 = ( T_4 ) V_113 ;
T_2 V_14 ;
T_1 V_10 ;
T_1 * V_70 ;
T_3 V_114 ;
F_38 ( & V_92 -> V_95 , V_20 ) ;
V_10 = V_92 -> V_96 [ F_14 ( V_25 ) ] ;
if ( ! F_8 ( V_10 ) ) {
F_39 ( & V_92 -> V_95 , V_20 ) ;
return 0 ;
}
V_14 = F_7 ( V_10 ) ;
V_70 = ( T_1 * ) F_34 ( V_14 ) + F_15 ( V_25 ) ;
V_114 = F_48 ( V_92 , V_70 , V_25 , V_5 ) ;
F_39 ( & V_92 -> V_95 , V_20 ) ;
F_40 ( V_92 , V_25 , V_114 ) ;
return V_114 ;
}
static struct V_35 * F_55 ( struct V_115 * V_52 )
{
struct V_116 * V_117 ;
struct V_115 * V_118 ;
struct V_35 * V_35 ;
V_117 = F_56 ( V_52 ) ;
if ( ! V_117 )
return NULL ;
V_118 = F_57 ( V_117 ) ;
V_35 = F_58 ( V_118 ) ;
F_59 ( V_117 ) ;
return V_35 ;
}
static int F_60 ( struct V_7 * V_9 ,
struct V_115 * V_52 )
{
struct V_35 * V_36 ;
struct V_6 * V_92 = F_5 ( V_9 ) ;
unsigned long V_20 ;
int V_50 , V_38 ;
T_2 V_56 ;
V_36 = F_55 ( V_52 ) ;
if ( ! V_36 )
return 0 ;
V_50 = F_26 ( V_36 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_32 ( V_36 ) ;
if ( V_50 )
return V_50 ;
V_36 -> V_9 = V_9 ;
V_50 = F_61 ( V_52 , V_36 -> V_75 , F_35 ,
V_119 , F_62 ( V_52 ) , V_36 ) ;
if ( V_50 )
return V_50 ;
V_56 = F_2 ( V_92 -> V_96 ) ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ ) {
F_19 ( V_36 -> V_40 [ V_38 ] , V_57 , V_56 ) ;
F_21 ( V_36 -> V_40 [ V_38 ] , V_87 ) ;
F_19 ( V_36 -> V_40 [ V_38 ] , V_120 , V_90 ) ;
}
V_50 = F_30 ( V_36 ) ;
if ( V_50 )
return V_50 ;
F_38 ( & V_92 -> V_100 , V_20 ) ;
F_63 ( & V_36 -> V_101 , & V_92 -> V_121 ) ;
F_39 ( & V_92 -> V_100 , V_20 ) ;
F_64 ( V_52 , L_16 ) ;
F_29 ( V_36 ) ;
return 0 ;
}
static void F_65 ( struct V_7 * V_9 ,
struct V_115 * V_52 )
{
struct V_35 * V_36 ;
struct V_6 * V_92 = F_5 ( V_9 ) ;
unsigned long V_20 ;
int V_38 ;
V_36 = F_55 ( V_52 ) ;
if ( ! V_36 )
return;
F_38 ( & V_92 -> V_100 , V_20 ) ;
F_66 ( & V_36 -> V_101 ) ;
F_39 ( & V_92 -> V_100 , V_20 ) ;
F_26 ( V_36 ) ;
F_31 ( V_36 ) ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ ) {
F_19 ( V_36 -> V_40 [ V_38 ] , V_120 , 0 ) ;
F_19 ( V_36 -> V_40 [ V_38 ] , V_57 , 0 ) ;
}
F_29 ( V_36 ) ;
F_67 ( V_52 , V_36 -> V_75 , V_36 ) ;
V_36 -> V_9 = NULL ;
F_64 ( V_52 , L_17 ) ;
}
static struct V_7 * F_68 ( unsigned type )
{
struct V_6 * V_92 ;
if ( type != V_122 )
return NULL ;
V_92 = F_69 ( sizeof( * V_92 ) , V_123 ) ;
if ( ! V_92 )
return NULL ;
V_92 -> V_96 = ( T_1 * ) F_46 ( V_123 | V_104 ) ;
if ( ! V_92 -> V_96 )
goto V_124;
F_1 ( V_92 -> V_96 , V_125 ) ;
F_70 ( & V_92 -> V_100 ) ;
F_70 ( & V_92 -> V_95 ) ;
F_71 ( & V_92 -> V_121 ) ;
return & V_92 -> V_9 ;
V_124:
F_72 ( V_92 ) ;
return NULL ;
}
static void F_73 ( struct V_7 * V_9 )
{
struct V_6 * V_92 = F_5 ( V_9 ) ;
int V_38 ;
F_74 ( ! F_75 ( & V_92 -> V_121 ) ) ;
for ( V_38 = 0 ; V_38 < V_125 ; V_38 ++ ) {
T_1 V_10 = V_92 -> V_96 [ V_38 ] ;
if ( F_8 ( V_10 ) ) {
T_2 V_14 = F_7 ( V_10 ) ;
T_1 * V_94 = F_34 ( V_14 ) ;
F_76 ( ( unsigned long ) V_94 ) ;
}
}
F_76 ( ( unsigned long ) V_92 -> V_96 ) ;
F_72 ( V_92 ) ;
}
static bool F_77 ( struct V_115 * V_52 )
{
struct V_126 * V_127 = V_52 -> V_128 ;
int V_50 ;
V_50 = F_78 ( V_127 , L_18 , L_19 ) ;
return ( V_50 > 0 ) ;
}
static int F_79 ( struct V_116 * V_117 ,
struct V_115 * V_52 )
{
struct V_126 * V_127 = V_52 -> V_128 ;
struct V_129 * V_130 ;
int V_50 ;
struct V_131 args ;
V_50 = F_80 ( V_127 , L_18 , L_19 , 0 ,
& args ) ;
if ( V_50 ) {
F_28 ( V_52 , L_20 ,
V_127 -> V_132 , V_50 ) ;
return V_50 ;
}
if ( args . V_133 != 0 ) {
F_28 ( V_52 , L_21 ,
args . V_127 -> V_132 , args . V_133 ) ;
return - V_134 ;
}
V_130 = F_81 ( args . V_127 ) ;
F_82 ( args . V_127 ) ;
if ( ! V_130 ) {
F_28 ( V_52 , L_22 , args . V_127 -> V_132 ) ;
return - V_135 ;
}
F_83 ( V_117 , & V_130 -> V_52 , NULL ) ;
return 0 ;
}
static int F_84 ( struct V_115 * V_52 )
{
struct V_116 * V_117 ;
int V_50 ;
if ( ! F_77 ( V_52 ) )
return - V_136 ;
V_117 = F_56 ( V_52 ) ;
if ( ! V_117 ) {
V_117 = F_85 () ;
if ( F_52 ( V_117 ) ) {
F_28 ( V_52 , L_23 ) ;
return F_53 ( V_117 ) ;
}
}
V_50 = F_86 ( V_117 , V_52 ) ;
if ( V_50 )
goto V_137;
V_50 = F_79 ( V_117 , V_52 ) ;
if ( V_50 )
goto V_138;
F_59 ( V_117 ) ;
return 0 ;
V_138:
F_87 ( V_52 ) ;
V_137:
F_59 ( V_117 ) ;
return V_50 ;
}
static void F_88 ( struct V_115 * V_52 )
{
if ( ! F_77 ( V_52 ) )
return;
F_87 ( V_52 ) ;
}
static int F_89 ( struct V_129 * V_139 )
{
struct V_115 * V_52 = & V_139 -> V_52 ;
struct V_35 * V_36 ;
struct V_140 * V_141 ;
int V_38 ;
V_36 = F_90 ( V_52 , sizeof( * V_36 ) , V_123 ) ;
if ( ! V_36 )
return - V_105 ;
F_91 ( V_139 , V_36 ) ;
V_36 -> V_52 = V_52 ;
V_36 -> V_39 = 0 ;
V_36 -> V_40 = F_90 ( V_52 , sizeof( * V_36 -> V_40 ) * V_36 -> V_39 ,
V_123 ) ;
if ( ! V_36 -> V_40 )
return - V_105 ;
for ( V_38 = 0 ; V_38 < V_139 -> V_142 ; V_38 ++ ) {
V_141 = F_92 ( V_139 , V_143 , V_38 ) ;
V_36 -> V_40 [ V_38 ] = F_93 ( & V_139 -> V_52 , V_141 ) ;
if ( F_52 ( V_36 -> V_40 [ V_38 ] ) )
continue;
V_36 -> V_39 ++ ;
}
if ( V_36 -> V_39 == 0 )
return F_53 ( V_36 -> V_40 [ 0 ] ) ;
V_36 -> V_75 = F_94 ( V_139 , 0 ) ;
if ( V_36 -> V_75 < 0 ) {
F_28 ( V_52 , L_24 , V_36 -> V_75 ) ;
return - V_144 ;
}
return 0 ;
}
static int F_95 ( struct V_129 * V_139 )
{
return 0 ;
}
static int T_7 F_96 ( void )
{
struct V_126 * V_127 ;
int V_50 ;
V_127 = F_97 ( NULL , V_145 ) ;
if ( ! V_127 )
return 0 ;
F_82 ( V_127 ) ;
V_50 = F_98 ( & V_146 , & V_147 ) ;
if ( V_50 )
return V_50 ;
return F_99 ( & V_148 ) ;
}
static void T_8 F_100 ( void )
{
F_101 ( & V_148 ) ;
}
