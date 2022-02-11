static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
if ( V_2 -> V_5 )
return;
if ( ! F_2 ( V_2 -> V_6 -> V_6 . V_7 ) )
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
F_7 ( V_7 , L_1 ) ;
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
V_7 = V_6 -> V_6 . V_7 ;
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
static void V_45 ( void * V_65 ,
const struct V_66 * V_67 )
{
struct V_68 * V_22 = V_65 ;
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_13 * V_8 = V_2 -> V_8 ;
struct V_53 * V_6 ;
struct V_7 * V_7 = V_8 -> V_7 ;
unsigned long V_55 ;
struct V_69 V_70 ;
T_4 V_26 ;
int V_71 = 0 ;
bool V_60 ;
V_6 = V_2 -> V_6 ;
if ( V_6 -> V_6 . V_72 )
V_6 -> V_6 . V_72 ( & V_6 -> V_6 ) ;
if ( V_67 -> V_67 == V_73 )
return;
F_19 ( & V_7 -> V_59 , V_55 ) ;
F_26 ( V_2 -> V_32 , V_2 -> V_47 ,
& V_70 ) ;
V_26 = V_2 -> V_21 - V_70 . V_74 ;
V_2 -> V_26 += V_26 ;
F_27 ( V_2 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_26 == V_2 -> V_39 ||
V_26 < V_2 -> V_29 )
V_2 -> V_21 = 0 ;
if ( V_2 -> V_5 ) {
T_2 type ;
if ( F_2 ( V_7 ) )
type = V_8 -> V_75 -> type ;
else
type = V_8 -> V_76 . type ;
if ( type == V_77 )
V_60 = true ;
else
V_60 = F_8 ( V_8 ) ;
}
if ( ! V_2 -> V_5 || V_60 ) {
F_9 ( V_2 ) ;
goto V_78;
}
if ( F_2 ( V_7 ) ) {
if ( V_7 -> V_79 & V_80 )
V_71 = 1 ;
} else {
if ( V_7 -> V_81 . V_82 == V_83 )
V_71 = 1 ;
}
if ( V_71 ) {
unsigned V_84 = 25 ;
do {
V_60 = F_8 ( V_8 ) ;
if ( V_60 ) {
F_9 ( V_2 ) ;
goto V_78;
}
V_84 -- ;
if ( ! V_84 )
break;
F_28 () ;
} while ( 1 );
}
F_29 ( & V_2 -> V_61 ,
& V_6 -> V_62 ) ;
if ( ! F_23 ( & V_6 -> V_58 ) ) {
unsigned long V_85 = V_2 -> V_39 / 10 ;
F_30 ( & V_6 -> V_58 ,
V_85 * V_64 ,
20 * V_64 ,
V_86 ) ;
}
V_78:
F_25 ( & V_7 -> V_59 , V_55 ) ;
}
static T_4 F_31 ( unsigned V_87 , unsigned V_88 , T_4 V_89 )
{
unsigned V_90 ;
V_90 = ( V_87 - 1 ) * 2 ;
V_89 &= ~ ( 3 << V_90 ) ;
V_89 |= V_88 << V_90 ;
return V_89 ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned V_88 )
{
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_6 . V_7 ;
T_4 V_91 ;
T_4 V_92 ;
T_4 V_93 ;
if ( V_2 -> V_5 )
V_93 = V_6 -> V_94 ;
else
V_93 = V_6 -> V_95 ;
V_91 = V_2 -> V_96 ;
V_92 = F_31 ( V_91 , V_88 , V_93 ) ;
if ( V_92 == V_93 )
return;
if ( V_2 -> V_5 ) {
V_6 -> V_94 = V_92 ;
F_33 ( V_7 -> V_97 , V_98 , V_92 ) ;
} else {
V_6 -> V_95 = V_92 ;
F_33 ( V_7 -> V_97 , V_99 , V_92 ) ;
}
}
static void F_34 ( struct V_1 * V_2 ,
unsigned V_88 )
{
struct V_53 * V_6 = V_2 -> V_6 ;
T_4 V_91 ;
T_4 V_92 ;
T_4 V_93 ;
V_93 = V_6 -> V_100 ;
V_91 = V_2 -> V_96 ;
V_92 = F_31 ( V_91 , V_88 , V_93 ) ;
if ( V_92 == V_93 )
return;
V_6 -> V_100 = V_92 ;
F_33 ( V_6 -> V_6 . V_7 -> V_97 , V_101 ,
V_92 ) ;
}
static bool F_35 ( struct V_68 * V_22 ,
T_1 V_29 , T_2 V_88 ,
T_5 V_102 , T_4 V_103 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_33 * V_34 ;
enum V_35 V_36 ;
struct V_7 * V_7 = V_2 -> V_6 -> V_6 . V_7 ;
unsigned V_104 = 0 ;
V_2 -> V_38 = V_102 ;
V_2 -> V_39 = V_103 ;
V_2 -> V_26 = 0 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_28 = ( V_2 -> V_5 && V_88 ) ? 1 : 0 ;
if ( V_2 -> V_5 )
V_104 = 1 ;
if ( V_104 ) {
if ( V_103 > V_29 ) {
F_33 ( V_7 -> V_97 ,
F_36 ( V_2 -> V_96 ) , V_103 ) ;
F_32 ( V_2 ,
V_105 ) ;
F_34 ( V_2 ,
V_106 ) ;
} else {
F_33 ( V_7 -> V_97 ,
F_36 ( V_2 -> V_96 ) , 0 ) ;
F_32 ( V_2 ,
V_107 ) ;
F_34 ( V_2 ,
V_108 ) ;
}
} else {
F_32 ( V_2 , V_107 ) ;
F_34 ( V_2 , V_108 ) ;
V_103 = F_37 ( T_4 , V_29 , V_103 ) ;
}
V_2 -> V_21 = V_103 ;
V_36 = V_2 -> V_5 ? V_40 : V_41 ;
V_34 = F_13 ( V_32 , V_102 , V_103 , V_36 ,
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
static struct V_68 * F_39 ( struct V_109 * V_110 ,
struct V_13 * V_8 , T_2 V_5 )
{
struct V_53 * V_6 = F_18 ( V_110 ,
struct V_53 , V_6 ) ;
struct V_1 * V_2 = NULL ;
T_2 V_111 = V_8 -> V_15 - 1 ;
if ( V_111 >= V_112 )
return NULL ;
if ( V_5 )
V_2 = & V_6 -> V_113 [ V_111 ] ;
else
V_2 = & V_6 -> V_114 [ V_111 ] ;
if ( ! V_2 -> V_32 )
return NULL ;
if ( V_2 -> V_115 )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_115 = 1 ;
F_40 ( V_2 ) ;
return & V_2 -> V_22 ;
}
static void F_41 ( struct V_68 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
F_42 ( V_2 ) ;
if ( V_2 -> V_115 ) {
V_2 -> V_115 = 0 ;
V_22 -> V_23 = V_24 ;
V_22 -> V_25 = 0 ;
}
}
static int F_43 ( struct V_68 * V_22 ,
T_1 V_29 , T_2 V_88 ,
T_5 V_102 , T_4 V_103 )
{
int V_56 ;
struct V_1 * V_2 = V_22 -> V_65 ;
int V_116 = 0 ;
F_44 ( V_22 -> V_23 == V_117 ||
V_22 -> V_23 == V_118 ) ;
if ( F_2 ( V_2 -> V_6 -> V_6 . V_7 ) ) {
if ( V_2 -> V_5 )
V_116 = V_2 -> V_8 -> V_75 -> V_116 ;
else
V_116 = V_2 -> V_8 -> V_119 -> V_116 ;
}
V_22 -> V_23 = V_118 ;
V_22 -> V_25 = 0 ;
if ( V_116 )
V_29 = V_116 * ( V_29 & 0x7FF ) ;
V_56 = F_35 ( V_22 , V_29 , V_88 , V_102 , V_103 ) ;
if ( ! V_56 )
V_22 -> V_23 = V_24 ;
return V_56 ;
}
static int F_45 ( struct V_68 * V_22 , T_1 V_120 ,
void * V_121 , T_4 V_122 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_6 . V_7 ;
if ( F_2 ( V_7 ) ) {
F_14 ( 1 ) ;
return 1 ;
}
if ( V_2 -> V_8 -> V_76 . type != V_123 )
return 0 ;
if ( V_2 -> V_5 )
return 1 ;
return 0 ;
}
static int F_46 ( struct V_68 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_6 . V_7 ;
void T_3 * V_17 = V_2 -> V_8 -> V_9 ;
int V_124 ;
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
V_3 &= ~ V_125 ;
F_6 ( V_17 , V_19 , V_3 ) ;
} else {
F_34 ( V_2 , V_108 ) ;
F_48 ( 250 ) ;
V_3 = F_3 ( V_17 , V_10 ) ;
V_3 &= ~ ( V_49 | V_126 ) ;
F_6 ( V_17 , V_10 , V_3 ) ;
F_48 ( 50 ) ;
V_3 = F_3 ( V_17 , V_10 ) ;
if ( V_3 & V_127 ) {
V_3 |= V_128 ;
F_6 ( V_17 , V_10 , V_3 ) ;
F_6 ( V_17 , V_10 , V_3 ) ;
}
}
V_124 = 1 << V_2 -> V_96 ;
if ( V_5 )
V_124 <<= 16 ;
do {
if ( V_5 )
F_33 ( V_7 -> V_97 , V_129 , V_124 ) ;
V_56 = F_49 ( V_2 -> V_32 ) ;
} while ( V_56 == - V_130 );
if ( V_5 ) {
F_33 ( V_7 -> V_97 , V_129 , V_124 ) ;
V_3 = F_3 ( V_17 , V_19 ) ;
if ( V_3 & V_20 ) {
V_3 |= V_131 ;
F_6 ( V_17 , V_19 , V_3 ) ;
}
}
V_2 -> V_22 . V_23 = V_24 ;
return 0 ;
}
static void F_50 ( struct V_53 * V_132 )
{
struct V_31 * V_32 ;
int V_133 ;
for ( V_133 = 0 ; V_133 < V_112 ; V_133 ++ ) {
V_32 = V_132 -> V_113 [ V_133 ] . V_32 ;
if ( V_32 )
F_51 ( V_32 ) ;
V_32 = V_132 -> V_114 [ V_133 ] . V_32 ;
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
struct V_7 * V_7 = V_6 -> V_6 . V_7 ;
struct V_134 * V_135 = V_7 -> V_6 ;
struct V_136 * V_137 = V_135 -> V_138 -> V_139 ;
struct V_1 * V_2 ;
int V_140 ;
int V_133 ;
int V_56 ;
V_140 = F_54 ( V_137 , L_2 ) ;
if ( V_140 < 0 )
return V_140 ;
for ( V_133 = 0 ; V_133 < V_140 ; V_133 ++ ) {
struct V_31 * V_32 ;
struct V_68 * V_141 ;
const char * V_142 ;
unsigned V_5 ;
unsigned int V_91 ;
V_56 = F_55 ( V_137 , L_2 , V_133 , & V_142 ) ;
if ( V_56 )
goto V_143;
if ( F_56 ( V_142 , L_3 ) )
V_5 = 1 ;
else if ( F_56 ( V_142 , L_4 ) )
V_5 = 0 ;
else {
F_57 ( V_135 , L_5 , V_142 ) ;
goto V_143;
}
V_56 = F_58 ( V_142 + 2 , 0 , & V_91 ) ;
if ( V_56 )
goto V_143;
V_56 = - V_144 ;
if ( V_91 > V_112 || ! V_91 )
goto V_143;
if ( V_5 )
V_2 = & V_6 -> V_113 [ V_91 - 1 ] ;
else
V_2 = & V_6 -> V_114 [ V_91 - 1 ] ;
V_2 -> V_6 = V_6 ;
V_2 -> V_96 = V_91 ;
V_2 -> V_5 = V_5 ;
F_59 ( & V_2 -> V_61 ) ;
V_141 = & V_2 -> V_22 ;
V_141 -> V_65 = V_2 ;
V_141 -> V_23 = V_24 ;
V_141 -> V_145 = V_146 ;
V_32 = F_60 ( V_135 -> V_138 , V_142 ) ;
if ( ! V_32 ) {
F_57 ( V_135 , L_6 , V_142 ) ;
V_56 = - V_147 ;
goto V_143;
}
V_2 -> V_32 = V_32 ;
}
return 0 ;
V_143:
F_50 ( V_6 ) ;
return V_56 ;
}
void F_61 ( struct V_109 * V_110 )
{
struct V_53 * V_6 = F_18 ( V_110 ,
struct V_53 , V_6 ) ;
F_62 ( & V_6 -> V_58 ) ;
F_52 ( V_6 ) ;
F_63 ( V_6 ) ;
}
struct V_109 *
F_64 ( struct V_7 * V_7 , void T_3 * V_148 )
{
struct V_53 * V_6 ;
int V_56 = 0 ;
if ( ! V_7 -> V_6 -> V_138 -> V_139 ) {
F_57 ( V_7 -> V_6 , L_7 ) ;
return NULL ;
}
V_6 = F_65 ( sizeof( * V_6 ) , V_149 ) ;
if ( ! V_6 )
goto V_150;
F_66 ( & V_6 -> V_58 , V_151 , V_86 ) ;
V_6 -> V_58 . V_152 = F_17 ;
F_59 ( & V_6 -> V_62 ) ;
V_6 -> V_6 . V_153 = F_39 ;
V_6 -> V_6 . V_154 = F_41 ;
V_6 -> V_6 . V_155 = F_43 ;
V_6 -> V_6 . V_156 = F_46 ;
V_6 -> V_6 . V_157 = F_45 ;
V_6 -> V_6 . V_7 = V_7 ;
V_56 = F_53 ( V_6 ) ;
if ( V_56 )
goto V_158;
return & V_6 -> V_6 ;
V_158:
F_63 ( V_6 ) ;
V_150:
if ( V_56 == - V_147 )
return F_67 ( V_56 ) ;
return NULL ;
}
