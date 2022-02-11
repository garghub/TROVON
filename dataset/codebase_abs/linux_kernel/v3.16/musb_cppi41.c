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
static bool F_8 ( struct V_14 * V_8 , bool V_20 )
{
if ( V_20 && V_8 -> V_21 ) {
if ( V_8 -> V_21 -> type == V_22 )
return true ;
} else if ( V_8 -> V_23 ) {
if ( V_8 -> V_23 -> type == V_22 )
return true ;
}
return false ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_14 * V_8 = V_2 -> V_8 ;
struct V_7 * V_7 = V_8 -> V_7 ;
if ( ! V_2 -> V_24 ||
( V_2 -> V_25 . V_26 == V_27 ) ) {
V_2 -> V_25 . V_28 =
V_2 -> V_29 ;
V_2 -> V_25 . V_26 = V_27 ;
F_10 ( V_7 , V_8 -> V_15 , V_2 -> V_5 ) ;
} else {
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_32 * V_33 ;
enum V_34 V_35 ;
T_1 V_3 ;
T_4 V_36 ;
void T_3 * V_16 = V_2 -> V_8 -> V_9 ;
V_2 -> V_37 += V_2 -> V_38 ;
V_36 = V_2 -> V_39 ;
V_36 -= V_2 -> V_29 ;
V_36 = F_11 ( V_36 , V_2 -> V_38 ) ;
V_2 -> V_24 = V_36 ;
V_35 = V_2 -> V_5 ? V_40
: V_41 ;
V_33 = F_12 ( V_31 ,
V_2 -> V_37 ,
V_36 ,
V_35 ,
V_42 | V_43 ) ;
if ( F_13 ( ! V_33 ) )
return;
V_33 -> V_44 = V_45 ;
V_33 -> V_46 = & V_2 -> V_25 ;
V_2 -> V_47 = V_33 -> V_48 ( V_33 ) ;
F_14 ( V_31 ) ;
if ( ! V_2 -> V_5 ) {
V_3 = F_3 ( V_16 , V_10 ) ;
V_3 |= V_49 ;
F_5 ( V_16 , V_10 , V_3 ) ;
}
}
}
static void F_15 ( struct V_50 * V_51 )
{
unsigned long V_52 ;
struct V_1 * V_2 =
F_16 ( V_51 , struct V_1 , V_53 ) ;
struct V_54 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_7 ;
struct V_14 * V_8 = V_2 -> V_8 ;
bool V_55 ;
if ( ! V_2 -> V_5 && F_8 ( V_8 , 1 ) ) {
F_17 ( & V_7 -> V_56 , V_52 ) ;
F_9 ( V_2 ) ;
F_18 ( & V_7 -> V_56 , V_52 ) ;
} else {
V_55 = F_7 ( V_8 ) ;
if ( V_55 ) {
F_17 ( & V_7 -> V_56 , V_52 ) ;
F_9 ( V_2 ) ;
F_18 ( & V_7 -> V_56 , V_52 ) ;
} else {
F_19 ( & V_2 -> V_53 ) ;
}
}
}
static enum V_57 F_20 ( struct V_58 * V_59 )
{
struct V_54 * V_6 ;
struct V_1 * V_2 , * V_60 ;
struct V_7 * V_7 ;
unsigned long V_52 ;
enum V_57 V_61 = V_62 ;
V_6 = F_16 ( V_59 , struct V_54 ,
V_63 ) ;
V_7 = V_6 -> V_7 ;
F_17 ( & V_7 -> V_56 , V_52 ) ;
F_21 (cppi41_channel, n, &controller->early_tx_list,
tx_check) {
bool V_55 ;
struct V_14 * V_8 = V_2 -> V_8 ;
V_55 = F_7 ( V_8 ) ;
if ( V_55 ) {
F_22 ( & V_2 -> V_64 ) ;
F_9 ( V_2 ) ;
}
}
if ( ! F_23 ( & V_6 -> V_65 ) ) {
V_61 = V_66 ;
F_24 ( & V_6 -> V_63 ,
F_25 ( 0 , 150 * V_67 ) ) ;
}
F_18 ( & V_7 -> V_56 , V_52 ) ;
return V_61 ;
}
static void V_45 ( void * V_68 )
{
struct V_69 * V_25 = V_68 ;
struct V_1 * V_2 = V_25 -> V_68 ;
struct V_14 * V_8 = V_2 -> V_8 ;
struct V_7 * V_7 = V_8 -> V_7 ;
unsigned long V_52 ;
struct V_70 V_71 ;
T_4 V_29 ;
bool V_55 ;
F_17 ( & V_7 -> V_56 , V_52 ) ;
F_26 ( V_2 -> V_31 , V_2 -> V_47 ,
& V_71 ) ;
V_29 = V_2 -> V_24 - V_71 . V_72 ;
V_2 -> V_29 += V_29 ;
F_6 ( V_7 -> V_6 , L_2 ,
V_8 -> V_15 , V_2 -> V_29 ,
V_2 -> V_39 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_29 == V_2 -> V_39 ||
V_29 < V_2 -> V_38 )
V_2 -> V_24 = 0 ;
if ( ! V_2 -> V_5 ) {
if ( F_8 ( V_8 , 1 ) )
F_19 ( & V_2 -> V_53 ) ;
else
F_9 ( V_2 ) ;
goto V_73;
}
V_55 = F_7 ( V_8 ) ;
if ( V_55 ) {
F_9 ( V_2 ) ;
} else {
struct V_54 * V_6 ;
V_6 = V_2 -> V_6 ;
if ( V_7 -> V_74 . V_75 == V_76 ) {
unsigned V_77 = 25 ;
do {
V_55 = F_7 ( V_8 ) ;
if ( V_55 )
break;
V_77 -- ;
if ( ! V_77 )
break;
F_27 ( 1 ) ;
} while ( 1 );
V_55 = F_7 ( V_8 ) ;
if ( V_55 ) {
F_9 ( V_2 ) ;
goto V_73;
}
}
if ( F_8 ( V_8 , 0 ) ) {
F_19 ( & V_2 -> V_53 ) ;
goto V_73;
}
F_28 ( & V_2 -> V_64 ,
& V_6 -> V_65 ) ;
if ( ! F_29 ( & V_6 -> V_63 ) ) {
F_30 ( & V_6 -> V_63 ,
F_25 ( 0 , 140 * V_67 ) ,
40 * V_67 ,
V_78 ) ;
}
}
V_73:
F_18 ( & V_7 -> V_56 , V_52 ) ;
}
static T_4 F_31 ( unsigned V_79 , unsigned V_80 , T_4 V_81 )
{
unsigned V_82 ;
V_82 = ( V_79 - 1 ) * 2 ;
V_81 &= ~ ( 3 << V_82 ) ;
V_81 |= V_80 << V_82 ;
return V_81 ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned V_80 )
{
struct V_54 * V_6 = V_2 -> V_6 ;
T_4 V_83 ;
T_4 V_84 ;
T_4 V_85 ;
if ( V_2 -> V_5 )
V_85 = V_6 -> V_86 ;
else
V_85 = V_6 -> V_87 ;
V_83 = V_2 -> V_88 ;
V_84 = F_31 ( V_83 , V_80 , V_85 ) ;
if ( V_84 == V_85 )
return;
if ( V_2 -> V_5 ) {
V_6 -> V_86 = V_84 ;
F_33 ( V_6 -> V_7 -> V_89 , V_90 ,
V_84 ) ;
} else {
V_6 -> V_87 = V_84 ;
F_33 ( V_6 -> V_7 -> V_89 , V_91 ,
V_84 ) ;
}
}
static void F_34 ( struct V_1 * V_2 ,
unsigned V_80 )
{
struct V_54 * V_6 = V_2 -> V_6 ;
T_4 V_83 ;
T_4 V_84 ;
T_4 V_85 ;
V_85 = V_6 -> V_92 ;
V_83 = V_2 -> V_88 ;
V_84 = F_31 ( V_83 , V_80 , V_85 ) ;
if ( V_84 == V_85 )
return;
V_6 -> V_92 = V_84 ;
F_33 ( V_6 -> V_7 -> V_89 , V_93 , V_84 ) ;
}
static bool F_35 ( struct V_69 * V_25 ,
T_1 V_38 , T_2 V_80 ,
T_5 V_94 , T_4 V_95 )
{
struct V_1 * V_2 = V_25 -> V_68 ;
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_32 * V_33 ;
enum V_34 V_35 ;
struct V_7 * V_7 = V_2 -> V_6 -> V_7 ;
unsigned V_96 = 0 ;
F_6 ( V_7 -> V_6 ,
L_3 ,
V_2 -> V_88 , F_36 ( V_2 -> V_88 ) ,
V_38 , V_80 , ( unsigned long long ) V_94 ,
V_95 , V_2 -> V_5 ) ;
V_2 -> V_37 = V_94 ;
V_2 -> V_39 = V_95 ;
V_2 -> V_29 = 0 ;
V_2 -> V_38 = V_38 ;
if ( V_2 -> V_5 )
V_96 = 1 ;
if ( V_96 ) {
if ( V_95 > V_38 ) {
F_33 ( V_7 -> V_89 ,
F_36 ( V_2 -> V_88 ) , V_95 ) ;
F_32 ( V_2 ,
V_97 ) ;
F_34 ( V_2 ,
V_98 ) ;
} else {
F_33 ( V_7 -> V_89 ,
F_36 ( V_2 -> V_88 ) , 0 ) ;
F_32 ( V_2 ,
V_99 ) ;
F_34 ( V_2 ,
V_100 ) ;
}
} else {
F_32 ( V_2 , V_99 ) ;
F_34 ( V_2 , V_100 ) ;
V_95 = F_37 ( T_4 , V_38 , V_95 ) ;
}
V_2 -> V_24 = V_95 ;
V_35 = V_2 -> V_5 ? V_40 : V_41 ;
V_33 = F_12 ( V_31 , V_94 , V_95 , V_35 ,
V_42 | V_43 ) ;
if ( ! V_33 )
return false ;
V_33 -> V_44 = V_45 ;
V_33 -> V_46 = V_25 ;
V_2 -> V_47 = V_33 -> V_48 ( V_33 ) ;
F_1 ( V_2 ) ;
F_14 ( V_31 ) ;
return true ;
}
static struct V_69 * F_38 ( struct V_101 * V_102 ,
struct V_14 * V_8 , T_2 V_5 )
{
struct V_54 * V_6 = F_16 ( V_102 ,
struct V_54 , V_6 ) ;
struct V_1 * V_2 = NULL ;
T_2 V_103 = V_8 -> V_15 - 1 ;
if ( V_103 >= V_104 )
return NULL ;
if ( V_5 )
V_2 = & V_6 -> V_105 [ V_103 ] ;
else
V_2 = & V_6 -> V_106 [ V_103 ] ;
if ( ! V_2 -> V_31 )
return NULL ;
if ( V_2 -> V_107 )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_107 = 1 ;
return & V_2 -> V_25 ;
}
static void F_39 ( struct V_69 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_68 ;
if ( V_2 -> V_107 ) {
V_2 -> V_107 = 0 ;
V_25 -> V_26 = V_27 ;
V_25 -> V_28 = 0 ;
}
}
static int F_40 ( struct V_69 * V_25 ,
T_1 V_38 , T_2 V_80 ,
T_5 V_94 , T_4 V_95 )
{
int V_61 ;
struct V_1 * V_2 = V_25 -> V_68 ;
int V_108 = 0 ;
F_41 ( V_25 -> V_26 == V_109 ||
V_25 -> V_26 == V_110 ) ;
if ( F_2 ( V_2 -> V_6 -> V_7 ) ) {
if ( V_2 -> V_5 )
V_108 = V_2 -> V_8 -> V_23 -> V_108 ;
else
V_108 = V_2 -> V_8 -> V_21 -> V_108 ;
}
V_25 -> V_26 = V_110 ;
V_25 -> V_28 = 0 ;
if ( V_108 )
V_38 = V_108 * ( V_38 & 0x7FF ) ;
V_61 = F_35 ( V_25 , V_38 , V_80 , V_94 , V_95 ) ;
if ( ! V_61 )
V_25 -> V_26 = V_27 ;
return V_61 ;
}
static int F_42 ( struct V_69 * V_25 , T_1 V_111 ,
void * V_112 , T_4 V_113 )
{
struct V_1 * V_2 = V_25 -> V_68 ;
struct V_54 * V_6 = V_2 -> V_6 ;
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
static int F_43 ( struct V_69 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_68 ;
struct V_54 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_7 ;
void T_3 * V_16 = V_2 -> V_8 -> V_9 ;
int V_116 ;
int V_61 ;
unsigned V_5 ;
T_1 V_3 ;
V_5 = V_2 -> V_5 ;
F_6 ( V_7 -> V_6 , L_4 ,
V_2 -> V_88 , V_5 ) ;
if ( V_2 -> V_25 . V_26 == V_27 )
return 0 ;
F_22 ( & V_2 -> V_64 ) ;
if ( V_5 ) {
V_3 = F_3 ( V_16 , V_18 ) ;
V_3 &= ~ V_117 ;
F_5 ( V_16 , V_18 , V_3 ) ;
} else {
V_3 = F_3 ( V_16 , V_10 ) ;
V_3 &= ~ ( V_49 | V_118 ) ;
F_5 ( V_16 , V_10 , V_3 ) ;
V_3 = F_3 ( V_16 , V_10 ) ;
if ( V_3 & V_119 ) {
V_3 |= V_120 ;
F_5 ( V_16 , V_10 , V_3 ) ;
F_5 ( V_16 , V_10 , V_3 ) ;
}
}
V_116 = 1 << V_2 -> V_88 ;
if ( V_5 )
V_116 <<= 16 ;
do {
F_33 ( V_7 -> V_89 , V_121 , V_116 ) ;
V_61 = F_44 ( V_2 -> V_31 ) ;
} while ( V_61 == - V_122 );
F_33 ( V_7 -> V_89 , V_121 , V_116 ) ;
if ( V_5 ) {
V_3 = F_3 ( V_16 , V_18 ) ;
if ( V_3 & V_19 ) {
V_3 |= V_123 ;
F_5 ( V_16 , V_18 , V_3 ) ;
}
}
V_2 -> V_25 . V_26 = V_27 ;
return 0 ;
}
static void F_45 ( struct V_54 * V_124 )
{
struct V_30 * V_31 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_104 ; V_125 ++ ) {
V_31 = V_124 -> V_105 [ V_125 ] . V_31 ;
if ( V_31 )
F_46 ( V_31 ) ;
V_31 = V_124 -> V_106 [ V_125 ] . V_31 ;
if ( V_31 )
F_46 ( V_31 ) ;
}
}
static void F_47 ( struct V_54 * V_6 )
{
F_45 ( V_6 ) ;
}
static int F_48 ( struct V_54 * V_6 )
{
struct V_7 * V_7 = V_6 -> V_7 ;
struct V_126 * V_127 = V_7 -> V_6 ;
struct V_128 * V_129 = V_127 -> V_130 ;
struct V_1 * V_2 ;
int V_131 ;
int V_125 ;
int V_61 ;
V_131 = F_49 ( V_129 , L_5 ) ;
if ( V_131 < 0 )
return V_131 ;
for ( V_125 = 0 ; V_125 < V_131 ; V_125 ++ ) {
struct V_30 * V_31 ;
struct V_69 * V_132 ;
const char * V_133 ;
unsigned V_5 ;
unsigned int V_83 ;
V_61 = F_50 ( V_129 , L_5 , V_125 , & V_133 ) ;
if ( V_61 )
goto V_134;
if ( ! strncmp ( V_133 , L_6 , 2 ) )
V_5 = 1 ;
else if ( ! strncmp ( V_133 , L_7 , 2 ) )
V_5 = 0 ;
else {
F_51 ( V_127 , L_8 , V_133 ) ;
goto V_134;
}
V_61 = F_52 ( V_133 + 2 , 0 , & V_83 ) ;
if ( V_61 )
goto V_134;
V_61 = - V_135 ;
if ( V_83 > V_104 || ! V_83 )
goto V_134;
if ( V_5 )
V_2 = & V_6 -> V_105 [ V_83 - 1 ] ;
else
V_2 = & V_6 -> V_106 [ V_83 - 1 ] ;
V_2 -> V_6 = V_6 ;
V_2 -> V_88 = V_83 ;
V_2 -> V_5 = V_5 ;
F_53 ( & V_2 -> V_64 ) ;
F_54 ( & V_2 -> V_53 ,
F_15 ) ;
V_132 = & V_2 -> V_25 ;
V_132 -> V_68 = V_2 ;
V_132 -> V_26 = V_27 ;
V_132 -> V_136 = V_137 ;
V_31 = F_55 ( V_127 , V_133 ) ;
if ( ! V_31 ) {
F_51 ( V_127 , L_9 , V_133 ) ;
V_61 = - V_138 ;
goto V_134;
}
V_2 -> V_31 = V_31 ;
}
return 0 ;
V_134:
F_45 ( V_6 ) ;
return V_61 ;
}
void F_56 ( struct V_101 * V_102 )
{
struct V_54 * V_6 = F_16 ( V_102 ,
struct V_54 , V_6 ) ;
F_57 ( & V_6 -> V_63 ) ;
F_47 ( V_6 ) ;
F_58 ( V_6 ) ;
}
struct V_101 * F_59 ( struct V_7 * V_7 ,
void T_3 * V_139 )
{
struct V_54 * V_6 ;
int V_61 = 0 ;
if ( ! V_7 -> V_6 -> V_130 ) {
F_51 ( V_7 -> V_6 , L_10 ) ;
return NULL ;
}
V_6 = F_60 ( sizeof( * V_6 ) , V_140 ) ;
if ( ! V_6 )
goto V_141;
F_61 ( & V_6 -> V_63 , V_142 , V_78 ) ;
V_6 -> V_63 . V_143 = F_20 ;
F_53 ( & V_6 -> V_65 ) ;
V_6 -> V_7 = V_7 ;
V_6 -> V_6 . V_144 = F_38 ;
V_6 -> V_6 . V_145 = F_39 ;
V_6 -> V_6 . V_146 = F_40 ;
V_6 -> V_6 . V_147 = F_43 ;
V_6 -> V_6 . V_148 = F_42 ;
V_61 = F_48 ( V_6 ) ;
if ( V_61 )
goto V_149;
return & V_6 -> V_6 ;
V_149:
F_58 ( V_6 ) ;
V_141:
if ( V_61 == - V_138 )
return F_62 ( V_61 ) ;
return NULL ;
}
