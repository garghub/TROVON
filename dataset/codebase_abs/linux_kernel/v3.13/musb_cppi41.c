static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
if ( V_2 -> V_5 )
return;
if ( ! F_2 ( V_2 -> V_6 -> V_7 ) )
return;
V_3 = F_3 ( V_2 -> V_8 -> V_9 , V_10 ) ;
V_4 = V_3 & V_11 ? 1 : 0 ;
V_2 -> V_12 = V_4 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
if ( V_2 -> V_5 )
return;
if ( ! F_2 ( V_2 -> V_6 -> V_7 ) )
return;
V_3 = F_3 ( V_2 -> V_8 -> V_9 , V_10 ) ;
V_4 = V_3 & V_11 ? 1 : 0 ;
if ( ! V_4 && V_4 == V_2 -> V_12 ) {
V_3 |= V_11 | V_13 ;
F_5 ( V_2 -> V_8 -> V_9 , V_10 , V_3 ) ;
F_6 ( V_2 -> V_6 -> V_7 -> V_6 ,
L_1 ) ;
}
V_2 -> V_12 = V_4 ;
}
static bool F_7 ( struct V_14 * V_8 )
{
T_2 V_15 = V_8 -> V_15 ;
struct V_7 * V_7 = V_8 -> V_7 ;
void T_3 * V_16 = V_7 -> V_17 [ V_15 ] . V_9 ;
T_1 V_3 ;
V_3 = F_3 ( V_16 , V_18 ) ;
if ( V_3 & V_19 )
return false ;
return true ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_14 * V_8 = V_2 -> V_8 ;
struct V_7 * V_7 = V_8 -> V_7 ;
if ( ! V_2 -> V_20 ) {
V_2 -> V_21 . V_22 =
V_2 -> V_23 ;
V_2 -> V_21 . V_24 = V_25 ;
F_9 ( V_7 , V_8 -> V_15 , V_2 -> V_5 ) ;
} else {
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_28 * V_29 ;
enum V_30 V_31 ;
T_1 V_3 ;
T_4 V_32 ;
void T_3 * V_16 = V_2 -> V_8 -> V_9 ;
V_2 -> V_33 += V_2 -> V_34 ;
V_32 = V_2 -> V_35 ;
V_32 -= V_2 -> V_23 ;
V_32 = F_10 ( V_32 , V_2 -> V_34 ) ;
V_2 -> V_20 = V_32 ;
V_31 = V_2 -> V_5 ? V_36
: V_37 ;
V_29 = F_11 ( V_27 ,
V_2 -> V_33 ,
V_32 ,
V_31 ,
V_38 | V_39 ) ;
if ( F_12 ( ! V_29 ) )
return;
V_29 -> V_40 = V_41 ;
V_29 -> V_42 = & V_2 -> V_21 ;
V_2 -> V_43 = V_29 -> V_44 ( V_29 ) ;
F_13 ( V_27 ) ;
if ( ! V_2 -> V_5 ) {
V_3 = F_3 ( V_16 , V_10 ) ;
V_3 |= V_45 ;
F_5 ( V_16 , V_10 , V_3 ) ;
}
}
}
static enum V_46 F_14 ( struct V_47 * V_48 )
{
struct V_49 * V_6 ;
struct V_1 * V_2 , * V_50 ;
struct V_7 * V_7 ;
unsigned long V_51 ;
enum V_46 V_52 = V_53 ;
V_6 = F_15 ( V_48 , struct V_49 ,
V_54 ) ;
V_7 = V_6 -> V_7 ;
F_16 ( & V_7 -> V_55 , V_51 ) ;
F_17 (cppi41_channel, n, &controller->early_tx_list,
tx_check) {
bool V_56 ;
struct V_14 * V_8 = V_2 -> V_8 ;
V_56 = F_7 ( V_8 ) ;
if ( V_56 ) {
F_18 ( & V_2 -> V_57 ) ;
F_8 ( V_2 ) ;
}
}
if ( ! F_19 ( & V_6 -> V_58 ) ) {
V_52 = V_59 ;
F_20 ( & V_6 -> V_54 ,
F_21 ( 0 , 150 * V_60 ) ) ;
}
F_22 ( & V_7 -> V_55 , V_51 ) ;
return V_52 ;
}
static void V_41 ( void * V_61 )
{
struct V_62 * V_21 = V_61 ;
struct V_1 * V_2 = V_21 -> V_61 ;
struct V_14 * V_8 = V_2 -> V_8 ;
struct V_7 * V_7 = V_8 -> V_7 ;
unsigned long V_51 ;
struct V_63 V_64 ;
T_4 V_23 ;
bool V_56 ;
F_16 ( & V_7 -> V_55 , V_51 ) ;
F_23 ( V_2 -> V_27 , V_2 -> V_43 ,
& V_64 ) ;
V_23 = V_2 -> V_20 - V_64 . V_65 ;
V_2 -> V_23 += V_23 ;
F_6 ( V_7 -> V_6 , L_2 ,
V_8 -> V_15 , V_2 -> V_23 ,
V_2 -> V_35 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_23 == V_2 -> V_35 ||
V_23 < V_2 -> V_34 )
V_2 -> V_20 = 0 ;
V_56 = F_7 ( V_8 ) ;
if ( V_56 ) {
F_8 ( V_2 ) ;
} else {
struct V_49 * V_6 ;
V_6 = V_2 -> V_6 ;
if ( V_7 -> V_66 . V_67 == V_68 ) {
unsigned V_69 = 25 ;
do {
V_56 = F_7 ( V_8 ) ;
if ( V_56 )
break;
V_69 -- ;
if ( ! V_69 )
break;
F_24 ( 1 ) ;
} while ( 1 );
V_56 = F_7 ( V_8 ) ;
if ( V_56 ) {
F_8 ( V_2 ) ;
goto V_70;
}
}
F_25 ( & V_2 -> V_57 ,
& V_6 -> V_58 ) ;
if ( ! F_26 ( & V_6 -> V_54 ) ) {
F_27 ( & V_6 -> V_54 ,
F_21 ( 0 , 140 * V_60 ) ,
40 * V_60 ,
V_71 ) ;
}
}
V_70:
F_22 ( & V_7 -> V_55 , V_51 ) ;
}
static T_4 F_28 ( unsigned V_72 , unsigned V_73 , T_4 V_74 )
{
unsigned V_75 ;
V_75 = ( V_72 - 1 ) * 2 ;
V_74 &= ~ ( 3 << V_75 ) ;
V_74 |= V_73 << V_75 ;
return V_74 ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned V_73 )
{
struct V_49 * V_6 = V_2 -> V_6 ;
T_4 V_76 ;
T_4 V_77 ;
T_4 V_78 ;
if ( V_2 -> V_5 )
V_78 = V_6 -> V_79 ;
else
V_78 = V_6 -> V_80 ;
V_76 = V_2 -> V_81 ;
V_77 = F_28 ( V_76 , V_73 , V_78 ) ;
if ( V_77 == V_78 )
return;
if ( V_2 -> V_5 ) {
V_6 -> V_79 = V_77 ;
F_30 ( V_6 -> V_7 -> V_82 , V_83 ,
V_77 ) ;
} else {
V_6 -> V_80 = V_77 ;
F_30 ( V_6 -> V_7 -> V_82 , V_84 ,
V_77 ) ;
}
}
static void F_31 ( struct V_1 * V_2 ,
unsigned V_73 )
{
struct V_49 * V_6 = V_2 -> V_6 ;
T_4 V_76 ;
T_4 V_77 ;
T_4 V_78 ;
V_78 = V_6 -> V_85 ;
V_76 = V_2 -> V_81 ;
V_77 = F_28 ( V_76 , V_73 , V_78 ) ;
if ( V_77 == V_78 )
return;
V_6 -> V_85 = V_77 ;
F_30 ( V_6 -> V_7 -> V_82 , V_86 , V_77 ) ;
}
static bool F_32 ( struct V_62 * V_21 ,
T_1 V_34 , T_2 V_73 ,
T_5 V_87 , T_4 V_88 )
{
struct V_1 * V_2 = V_21 -> V_61 ;
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_28 * V_29 ;
enum V_30 V_31 ;
struct V_7 * V_7 = V_2 -> V_6 -> V_7 ;
unsigned V_89 = 0 ;
F_6 ( V_7 -> V_6 ,
L_3 ,
V_2 -> V_81 , F_33 ( V_2 -> V_81 ) ,
V_34 , V_73 , ( unsigned long long ) V_87 ,
V_88 , V_2 -> V_5 ) ;
V_2 -> V_33 = V_87 ;
V_2 -> V_35 = V_88 ;
V_2 -> V_23 = 0 ;
V_2 -> V_34 = V_34 ;
if ( V_2 -> V_5 )
V_89 = 1 ;
if ( V_89 ) {
if ( V_88 > V_34 ) {
F_30 ( V_7 -> V_82 ,
F_33 ( V_2 -> V_81 ) , V_88 ) ;
F_29 ( V_2 ,
V_90 ) ;
F_31 ( V_2 ,
V_91 ) ;
} else {
F_30 ( V_7 -> V_82 ,
F_33 ( V_2 -> V_81 ) , 0 ) ;
F_29 ( V_2 ,
V_92 ) ;
F_31 ( V_2 ,
V_93 ) ;
}
} else {
F_29 ( V_2 , V_92 ) ;
F_31 ( V_2 , V_93 ) ;
V_88 = F_34 ( T_4 , V_34 , V_88 ) ;
}
V_2 -> V_20 = V_88 ;
V_31 = V_2 -> V_5 ? V_36 : V_37 ;
V_29 = F_11 ( V_27 , V_87 , V_88 , V_31 ,
V_38 | V_39 ) ;
if ( ! V_29 )
return false ;
V_29 -> V_40 = V_41 ;
V_29 -> V_42 = V_21 ;
V_2 -> V_43 = V_29 -> V_44 ( V_29 ) ;
F_1 ( V_2 ) ;
F_13 ( V_27 ) ;
return true ;
}
static struct V_62 * F_35 ( struct V_94 * V_95 ,
struct V_14 * V_8 , T_2 V_5 )
{
struct V_49 * V_6 = F_15 ( V_95 ,
struct V_49 , V_6 ) ;
struct V_1 * V_2 = NULL ;
T_2 V_96 = V_8 -> V_15 - 1 ;
if ( V_96 >= V_97 )
return NULL ;
if ( V_5 )
V_2 = & V_6 -> V_98 [ V_96 ] ;
else
V_2 = & V_6 -> V_99 [ V_96 ] ;
if ( ! V_2 -> V_27 )
return NULL ;
if ( V_2 -> V_100 )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_100 = 1 ;
return & V_2 -> V_21 ;
}
static void F_36 ( struct V_62 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_61 ;
if ( V_2 -> V_100 ) {
V_2 -> V_100 = 0 ;
V_21 -> V_24 = V_25 ;
V_21 -> V_22 = 0 ;
}
}
static int F_37 ( struct V_62 * V_21 ,
T_1 V_34 , T_2 V_73 ,
T_5 V_87 , T_4 V_88 )
{
int V_52 ;
F_38 ( V_21 -> V_24 == V_101 ||
V_21 -> V_24 == V_102 ) ;
V_21 -> V_24 = V_102 ;
V_21 -> V_22 = 0 ;
V_52 = F_32 ( V_21 , V_34 , V_73 , V_87 , V_88 ) ;
if ( ! V_52 )
V_21 -> V_24 = V_25 ;
return V_52 ;
}
static int F_39 ( struct V_62 * V_21 , T_1 V_103 ,
void * V_104 , T_4 V_105 )
{
struct V_1 * V_2 = V_21 -> V_61 ;
struct V_49 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_7 ;
if ( F_2 ( V_7 ) ) {
F_12 ( 1 ) ;
return 1 ;
}
if ( V_2 -> V_8 -> V_106 . type != V_107 )
return 0 ;
if ( V_2 -> V_5 )
return 1 ;
return 0 ;
}
static int F_40 ( struct V_62 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_61 ;
struct V_49 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_7 ;
void T_3 * V_16 = V_2 -> V_8 -> V_9 ;
int V_108 ;
int V_52 ;
unsigned V_5 ;
T_1 V_3 ;
V_5 = V_2 -> V_5 ;
F_6 ( V_7 -> V_6 , L_4 ,
V_2 -> V_81 , V_5 ) ;
if ( V_2 -> V_21 . V_24 == V_25 )
return 0 ;
F_18 ( & V_2 -> V_57 ) ;
if ( V_5 ) {
V_3 = F_3 ( V_16 , V_18 ) ;
V_3 &= ~ V_109 ;
F_5 ( V_16 , V_18 , V_3 ) ;
} else {
V_3 = F_3 ( V_16 , V_10 ) ;
V_3 &= ~ ( V_45 | V_110 ) ;
F_5 ( V_16 , V_10 , V_3 ) ;
V_3 = F_3 ( V_16 , V_10 ) ;
if ( V_3 & V_111 ) {
V_3 |= V_112 ;
F_5 ( V_16 , V_10 , V_3 ) ;
F_5 ( V_16 , V_10 , V_3 ) ;
}
}
V_108 = 1 << V_2 -> V_81 ;
if ( V_5 )
V_108 <<= 16 ;
do {
F_30 ( V_7 -> V_82 , V_113 , V_108 ) ;
V_52 = F_41 ( V_2 -> V_27 ) ;
} while ( V_52 == - V_114 );
F_30 ( V_7 -> V_82 , V_113 , V_108 ) ;
if ( V_5 ) {
V_3 = F_3 ( V_16 , V_18 ) ;
if ( V_3 & V_19 ) {
V_3 |= V_115 ;
F_5 ( V_16 , V_18 , V_3 ) ;
}
}
V_2 -> V_21 . V_24 = V_25 ;
return 0 ;
}
static void F_42 ( struct V_49 * V_116 )
{
struct V_26 * V_27 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_97 ; V_117 ++ ) {
V_27 = V_116 -> V_98 [ V_117 ] . V_27 ;
if ( V_27 )
F_43 ( V_27 ) ;
V_27 = V_116 -> V_99 [ V_117 ] . V_27 ;
if ( V_27 )
F_43 ( V_27 ) ;
}
}
static void F_44 ( struct V_49 * V_6 )
{
F_42 ( V_6 ) ;
}
static int F_45 ( struct V_49 * V_6 )
{
struct V_7 * V_7 = V_6 -> V_7 ;
struct V_118 * V_119 = V_7 -> V_6 ;
struct V_120 * V_121 = V_119 -> V_122 ;
struct V_1 * V_2 ;
int V_123 ;
int V_117 ;
int V_52 ;
V_123 = F_46 ( V_121 , L_5 ) ;
if ( V_123 < 0 )
return V_123 ;
for ( V_117 = 0 ; V_117 < V_123 ; V_117 ++ ) {
struct V_26 * V_27 ;
struct V_62 * V_124 ;
const char * V_125 ;
unsigned V_5 ;
unsigned int V_76 ;
V_52 = F_47 ( V_121 , L_5 , V_117 , & V_125 ) ;
if ( V_52 )
goto V_126;
if ( ! strncmp ( V_125 , L_6 , 2 ) )
V_5 = 1 ;
else if ( ! strncmp ( V_125 , L_7 , 2 ) )
V_5 = 0 ;
else {
F_48 ( V_119 , L_8 , V_125 ) ;
goto V_126;
}
V_52 = F_49 ( V_125 + 2 , 0 , & V_76 ) ;
if ( V_52 )
goto V_126;
V_52 = - V_127 ;
if ( V_76 > V_97 || ! V_76 )
goto V_126;
if ( V_5 )
V_2 = & V_6 -> V_98 [ V_76 - 1 ] ;
else
V_2 = & V_6 -> V_99 [ V_76 - 1 ] ;
V_2 -> V_6 = V_6 ;
V_2 -> V_81 = V_76 ;
V_2 -> V_5 = V_5 ;
F_50 ( & V_2 -> V_57 ) ;
V_124 = & V_2 -> V_21 ;
V_124 -> V_61 = V_2 ;
V_124 -> V_24 = V_25 ;
V_124 -> V_128 = V_129 ;
V_27 = F_51 ( V_119 , V_125 ) ;
if ( ! V_27 ) {
F_48 ( V_119 , L_9 , V_125 ) ;
V_52 = - V_130 ;
goto V_126;
}
V_2 -> V_27 = V_27 ;
}
return 0 ;
V_126:
F_42 ( V_6 ) ;
return V_52 ;
}
void F_52 ( struct V_94 * V_95 )
{
struct V_49 * V_6 = F_15 ( V_95 ,
struct V_49 , V_6 ) ;
F_53 ( & V_6 -> V_54 ) ;
F_44 ( V_6 ) ;
F_54 ( V_6 ) ;
}
struct V_94 * F_55 ( struct V_7 * V_7 ,
void T_3 * V_131 )
{
struct V_49 * V_6 ;
int V_52 = 0 ;
if ( ! V_7 -> V_6 -> V_122 ) {
F_48 ( V_7 -> V_6 , L_10 ) ;
return NULL ;
}
V_6 = F_56 ( sizeof( * V_6 ) , V_132 ) ;
if ( ! V_6 )
goto V_133;
F_57 ( & V_6 -> V_54 , V_134 , V_71 ) ;
V_6 -> V_54 . V_135 = F_14 ;
F_50 ( & V_6 -> V_58 ) ;
V_6 -> V_7 = V_7 ;
V_6 -> V_6 . V_136 = F_35 ;
V_6 -> V_6 . V_137 = F_36 ;
V_6 -> V_6 . V_138 = F_37 ;
V_6 -> V_6 . V_139 = F_40 ;
V_6 -> V_6 . V_140 = F_39 ;
V_52 = F_45 ( V_6 ) ;
if ( V_52 )
goto V_141;
return & V_6 -> V_6 ;
V_141:
F_54 ( V_6 ) ;
V_133:
if ( V_52 == - V_130 )
return F_58 ( V_52 ) ;
return NULL ;
}
