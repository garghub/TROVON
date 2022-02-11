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
struct V_13 * V_8 = V_2 -> V_8 ;
struct V_7 * V_7 = V_8 -> V_7 ;
T_1 V_3 ;
T_2 V_4 ;
if ( V_2 -> V_5 )
return;
if ( ! F_2 ( V_7 ) )
return;
F_5 ( V_7 -> V_14 , V_8 -> V_15 ) ;
V_3 = F_3 ( V_8 -> V_9 , V_10 ) ;
V_4 = V_3 & V_11 ? 1 : 0 ;
if ( ! V_4 && V_4 == V_2 -> V_12 ) {
V_3 |= V_11 | V_16 ;
F_6 ( V_2 -> V_8 -> V_9 , V_10 , V_3 ) ;
F_7 ( V_2 -> V_6 -> V_7 -> V_6 ,
L_1 ) ;
}
V_2 -> V_12 = V_4 ;
}
static bool F_8 ( struct V_13 * V_8 )
{
T_2 V_15 = V_8 -> V_15 ;
struct V_7 * V_7 = V_8 -> V_7 ;
void T_3 * V_17 = V_7 -> V_18 [ V_15 ] . V_9 ;
T_1 V_3 ;
F_5 ( V_7 -> V_14 , V_8 -> V_15 ) ;
V_3 = F_3 ( V_17 , V_19 ) ;
if ( V_3 & V_20 )
return false ;
return true ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_13 * V_8 = V_2 -> V_8 ;
struct V_7 * V_7 = V_8 -> V_7 ;
void T_3 * V_17 = V_8 -> V_9 ;
T_1 V_3 ;
if ( ! V_2 -> V_21 ||
( V_2 -> V_22 . V_23 == V_24 ) ) {
V_2 -> V_22 . V_25 =
V_2 -> V_26 ;
V_2 -> V_22 . V_23 = V_24 ;
V_2 -> V_22 . V_27 = true ;
if ( V_2 -> V_28 && ( V_2 -> V_26 %
V_2 -> V_29 ) == 0 ) {
F_5 ( V_7 -> V_14 , V_8 -> V_15 ) ;
V_3 = V_30 | V_20 ;
F_6 ( V_17 , V_19 , V_3 ) ;
}
F_10 ( V_7 , V_8 -> V_15 , V_2 -> V_5 ) ;
} else {
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_33 * V_34 ;
enum V_35 V_36 ;
T_4 V_37 ;
V_2 -> V_38 += V_2 -> V_29 ;
V_37 = V_2 -> V_39 ;
V_37 -= V_2 -> V_26 ;
V_37 = F_11 ( V_37 , V_2 -> V_29 ) ;
V_2 -> V_21 = V_37 ;
V_36 = V_2 -> V_5 ? V_40
: V_41 ;
V_34 = F_12 ( V_32 ,
V_2 -> V_38 ,
V_37 ,
V_36 ,
V_42 | V_43 ) ;
if ( F_13 ( ! V_34 ) )
return;
V_34 -> V_44 = V_45 ;
V_34 -> V_46 = & V_2 -> V_22 ;
V_2 -> V_47 = V_34 -> V_48 ( V_34 ) ;
F_14 ( V_32 ) ;
if ( ! V_2 -> V_5 ) {
F_5 ( V_7 -> V_14 , V_8 -> V_15 ) ;
V_3 = F_3 ( V_17 , V_10 ) ;
V_3 |= V_49 ;
F_6 ( V_17 , V_10 , V_3 ) ;
}
}
}
static enum V_50 F_15 ( struct V_51 * V_52 )
{
struct V_53 * V_6 ;
struct V_1 * V_2 , * V_54 ;
struct V_7 * V_7 ;
unsigned long V_55 ;
enum V_50 V_56 = V_57 ;
V_6 = F_16 ( V_52 , struct V_53 ,
V_58 ) ;
V_7 = V_6 -> V_7 ;
F_17 ( & V_7 -> V_59 , V_55 ) ;
F_18 (cppi41_channel, n, &controller->early_tx_list,
tx_check) {
bool V_60 ;
struct V_13 * V_8 = V_2 -> V_8 ;
V_60 = F_8 ( V_8 ) ;
if ( V_60 ) {
F_19 ( & V_2 -> V_61 ) ;
F_9 ( V_2 ) ;
}
}
if ( ! F_20 ( & V_6 -> V_62 ) ) {
V_56 = V_63 ;
F_21 ( & V_6 -> V_58 ,
F_22 ( 0 , 50 * V_64 ) ) ;
}
F_23 ( & V_7 -> V_59 , V_55 ) ;
return V_56 ;
}
static void V_45 ( void * V_65 )
{
struct V_66 * V_22 = V_65 ;
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_13 * V_8 = V_2 -> V_8 ;
struct V_7 * V_7 = V_8 -> V_7 ;
unsigned long V_55 ;
struct V_67 V_68 ;
T_4 V_26 ;
bool V_60 ;
F_17 ( & V_7 -> V_59 , V_55 ) ;
F_24 ( V_2 -> V_32 , V_2 -> V_47 ,
& V_68 ) ;
V_26 = V_2 -> V_21 - V_68 . V_69 ;
V_2 -> V_26 += V_26 ;
F_7 ( V_7 -> V_6 , L_2 ,
V_8 -> V_15 , V_2 -> V_26 ,
V_2 -> V_39 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_26 == V_2 -> V_39 ||
V_26 < V_2 -> V_29 )
V_2 -> V_21 = 0 ;
V_60 = F_8 ( V_8 ) ;
if ( V_60 ) {
F_9 ( V_2 ) ;
} else {
struct V_53 * V_6 ;
V_6 = V_2 -> V_6 ;
if ( V_7 -> V_70 . V_71 == V_72 ) {
unsigned V_73 = 25 ;
do {
V_60 = F_8 ( V_8 ) ;
if ( V_60 )
break;
V_73 -- ;
if ( ! V_73 )
break;
F_25 ( 1 ) ;
} while ( 1 );
V_60 = F_8 ( V_8 ) ;
if ( V_60 ) {
F_9 ( V_2 ) ;
goto V_74;
}
}
F_26 ( & V_2 -> V_61 ,
& V_6 -> V_62 ) ;
if ( ! F_27 ( & V_6 -> V_58 ) ) {
unsigned long V_75 = V_2 -> V_39 / 10 ;
F_28 ( & V_6 -> V_58 ,
F_22 ( 0 , V_75 * V_64 ) ,
40 * V_64 ,
V_76 ) ;
}
}
V_74:
F_23 ( & V_7 -> V_59 , V_55 ) ;
}
static T_4 F_29 ( unsigned V_77 , unsigned V_78 , T_4 V_79 )
{
unsigned V_80 ;
V_80 = ( V_77 - 1 ) * 2 ;
V_79 &= ~ ( 3 << V_80 ) ;
V_79 |= V_78 << V_80 ;
return V_79 ;
}
static void F_30 ( struct V_1 * V_2 ,
unsigned V_78 )
{
struct V_53 * V_6 = V_2 -> V_6 ;
T_4 V_81 ;
T_4 V_82 ;
T_4 V_83 ;
if ( V_2 -> V_5 )
V_83 = V_6 -> V_84 ;
else
V_83 = V_6 -> V_85 ;
V_81 = V_2 -> V_86 ;
V_82 = F_29 ( V_81 , V_78 , V_83 ) ;
if ( V_82 == V_83 )
return;
if ( V_2 -> V_5 ) {
V_6 -> V_84 = V_82 ;
F_31 ( V_6 -> V_7 -> V_87 , V_88 ,
V_82 ) ;
} else {
V_6 -> V_85 = V_82 ;
F_31 ( V_6 -> V_7 -> V_87 , V_89 ,
V_82 ) ;
}
}
static void F_32 ( struct V_1 * V_2 ,
unsigned V_78 )
{
struct V_53 * V_6 = V_2 -> V_6 ;
T_4 V_81 ;
T_4 V_82 ;
T_4 V_83 ;
V_83 = V_6 -> V_90 ;
V_81 = V_2 -> V_86 ;
V_82 = F_29 ( V_81 , V_78 , V_83 ) ;
if ( V_82 == V_83 )
return;
V_6 -> V_90 = V_82 ;
F_31 ( V_6 -> V_7 -> V_87 , V_91 , V_82 ) ;
}
static bool F_33 ( struct V_66 * V_22 ,
T_1 V_29 , T_2 V_78 ,
T_5 V_92 , T_4 V_93 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_33 * V_34 ;
enum V_35 V_36 ;
struct V_7 * V_7 = V_2 -> V_6 -> V_7 ;
unsigned V_94 = 0 ;
F_7 ( V_7 -> V_6 ,
L_3 ,
V_2 -> V_86 , F_34 ( V_2 -> V_86 ) ,
V_29 , V_78 , ( unsigned long long ) V_92 ,
V_93 , V_2 -> V_5 ) ;
V_2 -> V_38 = V_92 ;
V_2 -> V_39 = V_93 ;
V_2 -> V_26 = 0 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_28 = ( V_2 -> V_5 && V_78 ) ? 1 : 0 ;
if ( V_2 -> V_5 )
V_94 = 1 ;
if ( V_94 ) {
if ( V_93 > V_29 ) {
F_31 ( V_7 -> V_87 ,
F_34 ( V_2 -> V_86 ) , V_93 ) ;
F_30 ( V_2 ,
V_95 ) ;
F_32 ( V_2 ,
V_96 ) ;
} else {
F_31 ( V_7 -> V_87 ,
F_34 ( V_2 -> V_86 ) , 0 ) ;
F_30 ( V_2 ,
V_97 ) ;
F_32 ( V_2 ,
V_98 ) ;
}
} else {
F_30 ( V_2 , V_97 ) ;
F_32 ( V_2 , V_98 ) ;
V_93 = F_35 ( T_4 , V_29 , V_93 ) ;
}
V_2 -> V_21 = V_93 ;
V_36 = V_2 -> V_5 ? V_40 : V_41 ;
V_34 = F_12 ( V_32 , V_92 , V_93 , V_36 ,
V_42 | V_43 ) ;
if ( ! V_34 )
return false ;
V_34 -> V_44 = V_45 ;
V_34 -> V_46 = V_22 ;
V_2 -> V_47 = V_34 -> V_48 ( V_34 ) ;
V_2 -> V_22 . V_27 = false ;
F_1 ( V_2 ) ;
F_14 ( V_32 ) ;
return true ;
}
static struct V_66 * F_36 ( struct V_99 * V_100 ,
struct V_13 * V_8 , T_2 V_5 )
{
struct V_53 * V_6 = F_16 ( V_100 ,
struct V_53 , V_6 ) ;
struct V_1 * V_2 = NULL ;
T_2 V_101 = V_8 -> V_15 - 1 ;
if ( V_101 >= V_102 )
return NULL ;
if ( V_5 )
V_2 = & V_6 -> V_103 [ V_101 ] ;
else
V_2 = & V_6 -> V_104 [ V_101 ] ;
if ( ! V_2 -> V_32 )
return NULL ;
if ( V_2 -> V_105 )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_105 = 1 ;
return & V_2 -> V_22 ;
}
static void F_37 ( struct V_66 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
if ( V_2 -> V_105 ) {
V_2 -> V_105 = 0 ;
V_22 -> V_23 = V_24 ;
V_22 -> V_25 = 0 ;
}
}
static int F_38 ( struct V_66 * V_22 ,
T_1 V_29 , T_2 V_78 ,
T_5 V_92 , T_4 V_93 )
{
int V_56 ;
struct V_1 * V_2 = V_22 -> V_65 ;
int V_106 = 0 ;
F_39 ( V_22 -> V_23 == V_107 ||
V_22 -> V_23 == V_108 ) ;
if ( F_2 ( V_2 -> V_6 -> V_7 ) ) {
if ( V_2 -> V_5 )
V_106 = V_2 -> V_8 -> V_109 -> V_106 ;
else
V_106 = V_2 -> V_8 -> V_110 -> V_106 ;
}
V_22 -> V_23 = V_108 ;
V_22 -> V_25 = 0 ;
if ( V_106 )
V_29 = V_106 * ( V_29 & 0x7FF ) ;
V_56 = F_33 ( V_22 , V_29 , V_78 , V_92 , V_93 ) ;
if ( ! V_56 )
V_22 -> V_23 = V_24 ;
return V_56 ;
}
static int F_40 ( struct V_66 * V_22 , T_1 V_111 ,
void * V_112 , T_4 V_113 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_7 ;
if ( F_2 ( V_7 ) ) {
F_13 ( 1 ) ;
return 1 ;
}
if ( V_2 -> V_8 -> V_114 . type != V_115 )
return 0 ;
if ( V_2 -> V_5 )
return 1 ;
return 0 ;
}
static int F_41 ( struct V_66 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_7 ;
void T_3 * V_17 = V_2 -> V_8 -> V_9 ;
int V_116 ;
int V_56 ;
unsigned V_5 ;
T_1 V_3 ;
V_5 = V_2 -> V_5 ;
F_7 ( V_7 -> V_6 , L_4 ,
V_2 -> V_86 , V_5 ) ;
if ( V_2 -> V_22 . V_23 == V_24 )
return 0 ;
F_19 ( & V_2 -> V_61 ) ;
if ( V_5 ) {
V_3 = F_3 ( V_17 , V_19 ) ;
V_3 &= ~ V_117 ;
F_6 ( V_17 , V_19 , V_3 ) ;
} else {
V_3 = F_3 ( V_17 , V_10 ) ;
V_3 &= ~ ( V_49 | V_118 ) ;
F_6 ( V_17 , V_10 , V_3 ) ;
V_3 = F_3 ( V_17 , V_10 ) ;
if ( V_3 & V_119 ) {
V_3 |= V_120 ;
F_6 ( V_17 , V_10 , V_3 ) ;
F_6 ( V_17 , V_10 , V_3 ) ;
}
}
V_116 = 1 << V_2 -> V_86 ;
if ( V_5 )
V_116 <<= 16 ;
do {
F_31 ( V_7 -> V_87 , V_121 , V_116 ) ;
V_56 = F_42 ( V_2 -> V_32 ) ;
} while ( V_56 == - V_122 );
F_31 ( V_7 -> V_87 , V_121 , V_116 ) ;
if ( V_5 ) {
V_3 = F_3 ( V_17 , V_19 ) ;
if ( V_3 & V_20 ) {
V_3 |= V_123 ;
F_6 ( V_17 , V_19 , V_3 ) ;
}
}
V_2 -> V_22 . V_23 = V_24 ;
return 0 ;
}
static void F_43 ( struct V_53 * V_124 )
{
struct V_31 * V_32 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_102 ; V_125 ++ ) {
V_32 = V_124 -> V_103 [ V_125 ] . V_32 ;
if ( V_32 )
F_44 ( V_32 ) ;
V_32 = V_124 -> V_104 [ V_125 ] . V_32 ;
if ( V_32 )
F_44 ( V_32 ) ;
}
}
static void F_45 ( struct V_53 * V_6 )
{
F_43 ( V_6 ) ;
}
static int F_46 ( struct V_53 * V_6 )
{
struct V_7 * V_7 = V_6 -> V_7 ;
struct V_126 * V_127 = V_7 -> V_6 ;
struct V_128 * V_129 = V_127 -> V_130 ;
struct V_1 * V_2 ;
int V_131 ;
int V_125 ;
int V_56 ;
V_131 = F_47 ( V_129 , L_5 ) ;
if ( V_131 < 0 )
return V_131 ;
for ( V_125 = 0 ; V_125 < V_131 ; V_125 ++ ) {
struct V_31 * V_32 ;
struct V_66 * V_132 ;
const char * V_133 ;
unsigned V_5 ;
unsigned int V_81 ;
V_56 = F_48 ( V_129 , L_5 , V_125 , & V_133 ) ;
if ( V_56 )
goto V_134;
if ( ! strncmp ( V_133 , L_6 , 2 ) )
V_5 = 1 ;
else if ( ! strncmp ( V_133 , L_7 , 2 ) )
V_5 = 0 ;
else {
F_49 ( V_127 , L_8 , V_133 ) ;
goto V_134;
}
V_56 = F_50 ( V_133 + 2 , 0 , & V_81 ) ;
if ( V_56 )
goto V_134;
V_56 = - V_135 ;
if ( V_81 > V_102 || ! V_81 )
goto V_134;
if ( V_5 )
V_2 = & V_6 -> V_103 [ V_81 - 1 ] ;
else
V_2 = & V_6 -> V_104 [ V_81 - 1 ] ;
V_2 -> V_6 = V_6 ;
V_2 -> V_86 = V_81 ;
V_2 -> V_5 = V_5 ;
F_51 ( & V_2 -> V_61 ) ;
V_132 = & V_2 -> V_22 ;
V_132 -> V_65 = V_2 ;
V_132 -> V_23 = V_24 ;
V_132 -> V_136 = V_137 ;
V_32 = F_52 ( V_127 , V_133 ) ;
if ( ! V_32 ) {
F_49 ( V_127 , L_9 , V_133 ) ;
V_56 = - V_138 ;
goto V_134;
}
V_2 -> V_32 = V_32 ;
}
return 0 ;
V_134:
F_43 ( V_6 ) ;
return V_56 ;
}
void F_53 ( struct V_99 * V_100 )
{
struct V_53 * V_6 = F_16 ( V_100 ,
struct V_53 , V_6 ) ;
F_54 ( & V_6 -> V_58 ) ;
F_45 ( V_6 ) ;
F_55 ( V_6 ) ;
}
struct V_99 * F_56 ( struct V_7 * V_7 ,
void T_3 * V_139 )
{
struct V_53 * V_6 ;
int V_56 = 0 ;
if ( ! V_7 -> V_6 -> V_130 ) {
F_49 ( V_7 -> V_6 , L_10 ) ;
return NULL ;
}
V_6 = F_57 ( sizeof( * V_6 ) , V_140 ) ;
if ( ! V_6 )
goto V_141;
F_58 ( & V_6 -> V_58 , V_142 , V_76 ) ;
V_6 -> V_58 . V_143 = F_15 ;
F_51 ( & V_6 -> V_62 ) ;
V_6 -> V_7 = V_7 ;
V_6 -> V_6 . V_144 = F_36 ;
V_6 -> V_6 . V_145 = F_37 ;
V_6 -> V_6 . V_146 = F_38 ;
V_6 -> V_6 . V_147 = F_41 ;
V_6 -> V_6 . V_148 = F_40 ;
V_56 = F_46 ( V_6 ) ;
if ( V_56 )
goto V_149;
return & V_6 -> V_6 ;
V_149:
F_55 ( V_6 ) ;
V_141:
if ( V_56 == - V_138 )
return F_59 ( V_56 ) ;
return NULL ;
}
