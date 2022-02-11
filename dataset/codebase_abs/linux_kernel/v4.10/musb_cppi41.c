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
F_7 ( V_2 -> V_6 -> V_7 ,
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
F_10 ( V_2 ) ;
F_11 ( V_7 , V_8 -> V_15 , V_2 -> V_5 ) ;
} else {
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_33 * V_34 ;
enum V_35 V_36 ;
T_4 V_37 ;
V_2 -> V_38 += V_2 -> V_29 ;
V_37 = V_2 -> V_39 ;
V_37 -= V_2 -> V_26 ;
V_37 = F_12 ( V_37 , V_2 -> V_29 ) ;
V_2 -> V_21 = V_37 ;
V_36 = V_2 -> V_5 ? V_40
: V_41 ;
V_34 = F_13 ( V_32 ,
V_2 -> V_38 ,
V_37 ,
V_36 ,
V_42 | V_43 ) ;
if ( F_14 ( ! V_34 ) )
return;
V_34 -> V_44 = V_45 ;
V_34 -> V_46 = & V_2 -> V_22 ;
V_2 -> V_47 = V_34 -> V_48 ( V_34 ) ;
F_15 ( V_2 ) ;
F_16 ( V_32 ) ;
if ( ! V_2 -> V_5 ) {
F_5 ( V_7 -> V_14 , V_8 -> V_15 ) ;
V_3 = F_3 ( V_17 , V_10 ) ;
V_3 |= V_49 ;
F_6 ( V_17 , V_10 , V_3 ) ;
}
}
}
static enum V_50 F_17 ( struct V_51 * V_52 )
{
struct V_53 * V_6 ;
struct V_1 * V_2 , * V_54 ;
struct V_7 * V_7 ;
unsigned long V_55 ;
enum V_50 V_56 = V_57 ;
V_6 = F_18 ( V_52 , struct V_53 ,
V_58 ) ;
V_7 = V_6 -> V_7 ;
F_19 ( & V_7 -> V_59 , V_55 ) ;
F_20 (cppi41_channel, n, &controller->early_tx_list,
tx_check) {
bool V_60 ;
struct V_13 * V_8 = V_2 -> V_8 ;
V_60 = F_8 ( V_8 ) ;
if ( V_60 ) {
F_21 ( & V_2 -> V_61 ) ;
F_9 ( V_2 ) ;
}
}
if ( ! F_22 ( & V_6 -> V_62 ) &&
! F_23 ( & V_6 -> V_58 ) ) {
V_56 = V_63 ;
F_24 ( & V_6 -> V_58 , 20 * V_64 ) ;
}
F_25 ( & V_7 -> V_59 , V_55 ) ;
return V_56 ;
}
static void V_45 ( void * V_65 )
{
struct V_66 * V_22 = V_65 ;
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_13 * V_8 = V_2 -> V_8 ;
struct V_53 * V_6 ;
struct V_7 * V_7 = V_8 -> V_7 ;
unsigned long V_55 ;
struct V_67 V_68 ;
T_4 V_26 ;
int V_69 = 0 ;
bool V_60 ;
F_19 ( & V_7 -> V_59 , V_55 ) ;
F_26 ( V_2 -> V_32 , V_2 -> V_47 ,
& V_68 ) ;
V_26 = V_2 -> V_21 - V_68 . V_70 ;
V_2 -> V_26 += V_26 ;
F_27 ( V_2 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_26 == V_2 -> V_39 ||
V_26 < V_2 -> V_29 )
V_2 -> V_21 = 0 ;
if ( V_2 -> V_5 )
V_60 = F_8 ( V_8 ) ;
if ( ! V_2 -> V_5 || V_60 ) {
F_9 ( V_2 ) ;
goto V_71;
}
V_6 = V_2 -> V_6 ;
if ( F_2 ( V_7 ) ) {
if ( V_7 -> V_72 & V_73 )
V_69 = 1 ;
} else {
if ( V_7 -> V_74 . V_75 == V_76 )
V_69 = 1 ;
}
if ( V_69 ) {
unsigned V_77 = 25 ;
do {
V_60 = F_8 ( V_8 ) ;
if ( V_60 ) {
F_9 ( V_2 ) ;
goto V_71;
}
V_77 -- ;
if ( ! V_77 )
break;
F_28 () ;
} while ( 1 );
}
F_29 ( & V_2 -> V_61 ,
& V_6 -> V_62 ) ;
if ( ! F_23 ( & V_6 -> V_58 ) ) {
unsigned long V_78 = V_2 -> V_39 / 10 ;
F_30 ( & V_6 -> V_58 ,
V_78 * V_64 ,
20 * V_64 ,
V_79 ) ;
}
V_71:
F_25 ( & V_7 -> V_59 , V_55 ) ;
}
static T_4 F_31 ( unsigned V_80 , unsigned V_81 , T_4 V_82 )
{
unsigned V_83 ;
V_83 = ( V_80 - 1 ) * 2 ;
V_82 &= ~ ( 3 << V_83 ) ;
V_82 |= V_81 << V_83 ;
return V_82 ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned V_81 )
{
struct V_53 * V_6 = V_2 -> V_6 ;
T_4 V_84 ;
T_4 V_85 ;
T_4 V_86 ;
if ( V_2 -> V_5 )
V_86 = V_6 -> V_87 ;
else
V_86 = V_6 -> V_88 ;
V_84 = V_2 -> V_89 ;
V_85 = F_31 ( V_84 , V_81 , V_86 ) ;
if ( V_85 == V_86 )
return;
if ( V_2 -> V_5 ) {
V_6 -> V_87 = V_85 ;
F_33 ( V_6 -> V_7 -> V_90 , V_91 ,
V_85 ) ;
} else {
V_6 -> V_88 = V_85 ;
F_33 ( V_6 -> V_7 -> V_90 , V_92 ,
V_85 ) ;
}
}
static void F_34 ( struct V_1 * V_2 ,
unsigned V_81 )
{
struct V_53 * V_6 = V_2 -> V_6 ;
T_4 V_84 ;
T_4 V_85 ;
T_4 V_86 ;
V_86 = V_6 -> V_93 ;
V_84 = V_2 -> V_89 ;
V_85 = F_31 ( V_84 , V_81 , V_86 ) ;
if ( V_85 == V_86 )
return;
V_6 -> V_93 = V_85 ;
F_33 ( V_6 -> V_7 -> V_90 , V_94 , V_85 ) ;
}
static bool F_35 ( struct V_66 * V_22 ,
T_1 V_29 , T_2 V_81 ,
T_5 V_95 , T_4 V_96 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_33 * V_34 ;
enum V_35 V_36 ;
struct V_7 * V_7 = V_2 -> V_6 -> V_7 ;
unsigned V_97 = 0 ;
V_2 -> V_38 = V_95 ;
V_2 -> V_39 = V_96 ;
V_2 -> V_26 = 0 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_28 = ( V_2 -> V_5 && V_81 ) ? 1 : 0 ;
if ( V_2 -> V_5 )
V_97 = 1 ;
if ( V_97 ) {
if ( V_96 > V_29 ) {
F_33 ( V_7 -> V_90 ,
F_36 ( V_2 -> V_89 ) , V_96 ) ;
F_32 ( V_2 ,
V_98 ) ;
F_34 ( V_2 ,
V_99 ) ;
} else {
F_33 ( V_7 -> V_90 ,
F_36 ( V_2 -> V_89 ) , 0 ) ;
F_32 ( V_2 ,
V_100 ) ;
F_34 ( V_2 ,
V_101 ) ;
}
} else {
F_32 ( V_2 , V_100 ) ;
F_34 ( V_2 , V_101 ) ;
V_96 = F_37 ( T_4 , V_29 , V_96 ) ;
}
V_2 -> V_21 = V_96 ;
V_36 = V_2 -> V_5 ? V_40 : V_41 ;
V_34 = F_13 ( V_32 , V_95 , V_96 , V_36 ,
V_42 | V_43 ) ;
if ( ! V_34 )
return false ;
V_34 -> V_44 = V_45 ;
V_34 -> V_46 = V_22 ;
V_2 -> V_47 = V_34 -> V_48 ( V_34 ) ;
V_2 -> V_22 . V_27 = false ;
F_38 ( V_2 ) ;
F_1 ( V_2 ) ;
F_16 ( V_32 ) ;
return true ;
}
static struct V_66 * F_39 ( struct V_102 * V_103 ,
struct V_13 * V_8 , T_2 V_5 )
{
struct V_53 * V_6 = F_18 ( V_103 ,
struct V_53 , V_6 ) ;
struct V_1 * V_2 = NULL ;
T_2 V_104 = V_8 -> V_15 - 1 ;
if ( V_104 >= V_105 )
return NULL ;
if ( V_5 )
V_2 = & V_6 -> V_106 [ V_104 ] ;
else
V_2 = & V_6 -> V_107 [ V_104 ] ;
if ( ! V_2 -> V_32 )
return NULL ;
if ( V_2 -> V_108 )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_108 = 1 ;
F_40 ( V_2 ) ;
return & V_2 -> V_22 ;
}
static void F_41 ( struct V_66 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
F_42 ( V_2 ) ;
if ( V_2 -> V_108 ) {
V_2 -> V_108 = 0 ;
V_22 -> V_23 = V_24 ;
V_22 -> V_25 = 0 ;
}
}
static int F_43 ( struct V_66 * V_22 ,
T_1 V_29 , T_2 V_81 ,
T_5 V_95 , T_4 V_96 )
{
int V_56 ;
struct V_1 * V_2 = V_22 -> V_65 ;
int V_109 = 0 ;
F_44 ( V_22 -> V_23 == V_110 ||
V_22 -> V_23 == V_111 ) ;
if ( F_2 ( V_2 -> V_6 -> V_7 ) ) {
if ( V_2 -> V_5 )
V_109 = V_2 -> V_8 -> V_112 -> V_109 ;
else
V_109 = V_2 -> V_8 -> V_113 -> V_109 ;
}
V_22 -> V_23 = V_111 ;
V_22 -> V_25 = 0 ;
if ( V_109 )
V_29 = V_109 * ( V_29 & 0x7FF ) ;
V_56 = F_35 ( V_22 , V_29 , V_81 , V_95 , V_96 ) ;
if ( ! V_56 )
V_22 -> V_23 = V_24 ;
return V_56 ;
}
static int F_45 ( struct V_66 * V_22 , T_1 V_114 ,
void * V_115 , T_4 V_116 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_7 ;
if ( F_2 ( V_7 ) ) {
F_14 ( 1 ) ;
return 1 ;
}
if ( V_2 -> V_8 -> V_117 . type != V_118 )
return 0 ;
if ( V_2 -> V_5 )
return 1 ;
return 0 ;
}
static int F_46 ( struct V_66 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_7 ;
void T_3 * V_17 = V_2 -> V_8 -> V_9 ;
int V_119 ;
int V_56 ;
unsigned V_5 ;
T_1 V_3 ;
V_5 = V_2 -> V_5 ;
F_47 ( V_2 ) ;
if ( V_2 -> V_22 . V_23 == V_24 )
return 0 ;
F_21 ( & V_2 -> V_61 ) ;
if ( V_5 ) {
V_3 = F_3 ( V_17 , V_19 ) ;
V_3 &= ~ V_120 ;
F_6 ( V_17 , V_19 , V_3 ) ;
} else {
F_34 ( V_2 , V_101 ) ;
F_48 ( 250 ) ;
V_3 = F_3 ( V_17 , V_10 ) ;
V_3 &= ~ ( V_49 | V_121 ) ;
F_6 ( V_17 , V_10 , V_3 ) ;
F_48 ( 50 ) ;
V_3 = F_3 ( V_17 , V_10 ) ;
if ( V_3 & V_122 ) {
V_3 |= V_123 ;
F_6 ( V_17 , V_10 , V_3 ) ;
F_6 ( V_17 , V_10 , V_3 ) ;
}
}
V_119 = 1 << V_2 -> V_89 ;
if ( V_5 )
V_119 <<= 16 ;
do {
if ( V_5 )
F_33 ( V_7 -> V_90 , V_124 , V_119 ) ;
V_56 = F_49 ( V_2 -> V_32 ) ;
} while ( V_56 == - V_125 );
if ( V_5 ) {
F_33 ( V_7 -> V_90 , V_124 , V_119 ) ;
V_3 = F_3 ( V_17 , V_19 ) ;
if ( V_3 & V_20 ) {
V_3 |= V_126 ;
F_6 ( V_17 , V_19 , V_3 ) ;
}
}
V_2 -> V_22 . V_23 = V_24 ;
return 0 ;
}
static void F_50 ( struct V_53 * V_127 )
{
struct V_31 * V_32 ;
int V_128 ;
for ( V_128 = 0 ; V_128 < V_105 ; V_128 ++ ) {
V_32 = V_127 -> V_106 [ V_128 ] . V_32 ;
if ( V_32 )
F_51 ( V_32 ) ;
V_32 = V_127 -> V_107 [ V_128 ] . V_32 ;
if ( V_32 )
F_51 ( V_32 ) ;
}
}
static void F_52 ( struct V_53 * V_6 )
{
F_50 ( V_6 ) ;
}
static int F_53 ( struct V_53 * V_6 )
{
struct V_7 * V_7 = V_6 -> V_7 ;
struct V_129 * V_130 = V_7 -> V_6 ;
struct V_131 * V_132 = V_130 -> V_133 -> V_134 ;
struct V_1 * V_2 ;
int V_135 ;
int V_128 ;
int V_56 ;
V_135 = F_54 ( V_132 , L_2 ) ;
if ( V_135 < 0 )
return V_135 ;
for ( V_128 = 0 ; V_128 < V_135 ; V_128 ++ ) {
struct V_31 * V_32 ;
struct V_66 * V_136 ;
const char * V_137 ;
unsigned V_5 ;
unsigned int V_84 ;
V_56 = F_55 ( V_132 , L_2 , V_128 , & V_137 ) ;
if ( V_56 )
goto V_138;
if ( F_56 ( V_137 , L_3 ) )
V_5 = 1 ;
else if ( F_56 ( V_137 , L_4 ) )
V_5 = 0 ;
else {
F_57 ( V_130 , L_5 , V_137 ) ;
goto V_138;
}
V_56 = F_58 ( V_137 + 2 , 0 , & V_84 ) ;
if ( V_56 )
goto V_138;
V_56 = - V_139 ;
if ( V_84 > V_105 || ! V_84 )
goto V_138;
if ( V_5 )
V_2 = & V_6 -> V_106 [ V_84 - 1 ] ;
else
V_2 = & V_6 -> V_107 [ V_84 - 1 ] ;
V_2 -> V_6 = V_6 ;
V_2 -> V_89 = V_84 ;
V_2 -> V_5 = V_5 ;
F_59 ( & V_2 -> V_61 ) ;
V_136 = & V_2 -> V_22 ;
V_136 -> V_65 = V_2 ;
V_136 -> V_23 = V_24 ;
V_136 -> V_140 = V_141 ;
V_32 = F_60 ( V_130 -> V_133 , V_137 ) ;
if ( ! V_32 ) {
F_57 ( V_130 , L_6 , V_137 ) ;
V_56 = - V_142 ;
goto V_138;
}
V_2 -> V_32 = V_32 ;
}
return 0 ;
V_138:
F_50 ( V_6 ) ;
return V_56 ;
}
void F_61 ( struct V_102 * V_103 )
{
struct V_53 * V_6 = F_18 ( V_103 ,
struct V_53 , V_6 ) ;
F_62 ( & V_6 -> V_58 ) ;
F_52 ( V_6 ) ;
F_63 ( V_6 ) ;
}
struct V_102 *
F_64 ( struct V_7 * V_7 , void T_3 * V_143 )
{
struct V_53 * V_6 ;
int V_56 = 0 ;
if ( ! V_7 -> V_6 -> V_133 -> V_134 ) {
F_57 ( V_7 -> V_6 , L_7 ) ;
return NULL ;
}
V_6 = F_65 ( sizeof( * V_6 ) , V_144 ) ;
if ( ! V_6 )
goto V_145;
F_66 ( & V_6 -> V_58 , V_146 , V_79 ) ;
V_6 -> V_58 . V_147 = F_17 ;
F_59 ( & V_6 -> V_62 ) ;
V_6 -> V_7 = V_7 ;
V_6 -> V_6 . V_148 = F_39 ;
V_6 -> V_6 . V_149 = F_41 ;
V_6 -> V_6 . V_150 = F_43 ;
V_6 -> V_6 . V_151 = F_46 ;
V_6 -> V_6 . V_152 = F_45 ;
V_56 = F_53 ( V_6 ) ;
if ( V_56 )
goto V_153;
return & V_6 -> V_6 ;
V_153:
F_63 ( V_6 ) ;
V_145:
if ( V_56 == - V_142 )
return F_67 ( V_56 ) ;
return NULL ;
}
