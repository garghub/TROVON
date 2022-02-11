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
unsigned int V_88 )
{
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_6 . V_7 ;
unsigned int V_90 ;
T_4 V_91 ;
T_4 V_92 ;
T_4 V_93 ;
V_93 = V_6 -> V_94 ;
V_91 = V_2 -> V_96 ;
V_90 = ( V_91 - 1 ) * 4 ;
if ( ! V_2 -> V_5 )
V_90 += 16 ;
V_92 = V_93 & ~ ( 3 << V_90 ) ;
V_92 |= V_88 << V_90 ;
if ( V_92 == V_93 )
return;
V_6 -> V_94 = V_92 ;
F_33 ( V_7 -> V_97 , V_100 , V_92 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
unsigned V_88 )
{
struct V_53 * V_6 = V_2 -> V_6 ;
T_4 V_91 ;
T_4 V_92 ;
T_4 V_93 ;
V_93 = V_6 -> V_101 ;
V_91 = V_2 -> V_96 ;
V_92 = F_31 ( V_91 , V_88 , V_93 ) ;
if ( V_92 == V_93 )
return;
V_6 -> V_101 = V_92 ;
F_33 ( V_6 -> V_6 . V_7 -> V_97 ,
V_6 -> V_102 , V_92 ) ;
}
static bool F_36 ( struct V_68 * V_22 ,
T_1 V_29 , T_2 V_88 ,
T_5 V_103 , T_4 V_104 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_33 * V_34 ;
enum V_35 V_36 ;
struct V_7 * V_7 = V_2 -> V_6 -> V_6 . V_7 ;
unsigned V_105 = 0 ;
V_2 -> V_38 = V_103 ;
V_2 -> V_39 = V_104 ;
V_2 -> V_26 = 0 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_28 = ( V_2 -> V_5 && V_88 ) ? 1 : 0 ;
if ( V_2 -> V_5 )
V_105 = 1 ;
if ( V_105 ) {
if ( V_104 > V_29 ) {
F_33 ( V_7 -> V_97 ,
F_37 ( V_2 -> V_96 ) , V_104 ) ;
V_6 -> V_106 ( V_2 ,
V_107 ) ;
F_35 ( V_2 ,
V_108 ) ;
} else {
F_33 ( V_7 -> V_97 ,
F_37 ( V_2 -> V_96 ) , 0 ) ;
V_6 -> V_106 ( V_2 ,
V_109 ) ;
F_35 ( V_2 ,
V_110 ) ;
}
} else {
V_6 -> V_106 ( V_2 ,
V_109 ) ;
F_35 ( V_2 , V_110 ) ;
V_104 = F_38 ( T_4 , V_29 , V_104 ) ;
}
V_2 -> V_21 = V_104 ;
V_36 = V_2 -> V_5 ? V_40 : V_41 ;
V_34 = F_13 ( V_32 , V_103 , V_104 , V_36 ,
V_42 | V_43 ) ;
if ( ! V_34 )
return false ;
V_34 -> V_44 = V_45 ;
V_34 -> V_46 = V_22 ;
V_2 -> V_47 = V_34 -> V_48 ( V_34 ) ;
V_2 -> V_22 . V_27 = false ;
F_39 ( V_2 ) ;
F_1 ( V_2 ) ;
F_16 ( V_32 ) ;
return true ;
}
static struct V_68 * F_40 ( struct V_111 * V_112 ,
struct V_13 * V_8 , T_2 V_5 )
{
struct V_53 * V_6 = F_18 ( V_112 ,
struct V_53 , V_6 ) ;
struct V_1 * V_2 = NULL ;
T_2 V_113 = V_8 -> V_15 - 1 ;
if ( V_113 >= V_6 -> V_114 )
return NULL ;
if ( V_5 )
V_2 = & V_6 -> V_115 [ V_113 ] ;
else
V_2 = & V_6 -> V_116 [ V_113 ] ;
if ( ! V_2 -> V_32 )
return NULL ;
if ( V_2 -> V_117 )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_117 = 1 ;
F_41 ( V_2 ) ;
return & V_2 -> V_22 ;
}
static void F_42 ( struct V_68 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
F_43 ( V_2 ) ;
if ( V_2 -> V_117 ) {
V_2 -> V_117 = 0 ;
V_22 -> V_23 = V_24 ;
V_22 -> V_25 = 0 ;
}
}
static int F_44 ( struct V_68 * V_22 ,
T_1 V_29 , T_2 V_88 ,
T_5 V_103 , T_4 V_104 )
{
int V_56 ;
struct V_1 * V_2 = V_22 -> V_65 ;
int V_118 = 0 ;
F_45 ( V_22 -> V_23 == V_119 ||
V_22 -> V_23 == V_120 ) ;
if ( F_2 ( V_2 -> V_6 -> V_6 . V_7 ) ) {
if ( V_2 -> V_5 )
V_118 = V_2 -> V_8 -> V_75 -> V_118 ;
else
V_118 = V_2 -> V_8 -> V_121 -> V_118 ;
}
V_22 -> V_23 = V_120 ;
V_22 -> V_25 = 0 ;
if ( V_118 )
V_29 = V_118 * ( V_29 & 0x7FF ) ;
V_56 = F_36 ( V_22 , V_29 , V_88 , V_103 , V_104 ) ;
if ( ! V_56 )
V_22 -> V_23 = V_24 ;
return V_56 ;
}
static int F_46 ( struct V_68 * V_22 , T_1 V_122 ,
void * V_123 , T_4 V_124 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_6 . V_7 ;
if ( F_2 ( V_7 ) ) {
F_14 ( 1 ) ;
return 1 ;
}
if ( V_2 -> V_8 -> V_76 . type != V_125 )
return 0 ;
if ( V_2 -> V_5 )
return 1 ;
return 0 ;
}
static int F_47 ( struct V_68 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_65 ;
struct V_53 * V_6 = V_2 -> V_6 ;
struct V_7 * V_7 = V_6 -> V_6 . V_7 ;
void T_3 * V_17 = V_2 -> V_8 -> V_9 ;
int V_126 ;
int V_56 ;
unsigned V_5 ;
T_1 V_3 ;
V_5 = V_2 -> V_5 ;
F_48 ( V_2 ) ;
if ( V_2 -> V_22 . V_23 == V_24 )
return 0 ;
F_21 ( & V_2 -> V_61 ) ;
if ( V_5 ) {
V_3 = F_3 ( V_17 , V_19 ) ;
V_3 &= ~ V_127 ;
F_6 ( V_17 , V_19 , V_3 ) ;
} else {
F_35 ( V_2 , V_110 ) ;
F_49 ( 250 ) ;
V_3 = F_3 ( V_17 , V_10 ) ;
V_3 &= ~ ( V_49 | V_128 ) ;
F_6 ( V_17 , V_10 , V_3 ) ;
F_49 ( 50 ) ;
V_3 = F_3 ( V_17 , V_10 ) ;
if ( V_3 & V_129 ) {
V_3 |= V_130 ;
F_6 ( V_17 , V_10 , V_3 ) ;
F_6 ( V_17 , V_10 , V_3 ) ;
}
}
if ( V_7 -> V_131 . V_132 & V_133 )
F_50 ( 250 ) ;
V_126 = 1 << V_2 -> V_96 ;
if ( V_5 )
V_126 <<= 16 ;
do {
if ( V_5 )
F_33 ( V_7 -> V_97 , V_6 -> V_134 ,
V_126 ) ;
V_56 = F_51 ( V_2 -> V_32 ) ;
} while ( V_56 == - V_135 );
if ( V_5 ) {
F_33 ( V_7 -> V_97 , V_6 -> V_134 , V_126 ) ;
V_3 = F_3 ( V_17 , V_19 ) ;
if ( V_3 & V_20 ) {
V_3 |= V_136 ;
F_6 ( V_17 , V_19 , V_3 ) ;
}
}
V_2 -> V_22 . V_23 = V_24 ;
return 0 ;
}
static void F_52 ( struct V_53 * V_137 )
{
struct V_31 * V_32 ;
int V_138 ;
for ( V_138 = 0 ; V_138 < V_137 -> V_114 ; V_138 ++ ) {
V_32 = V_137 -> V_115 [ V_138 ] . V_32 ;
if ( V_32 )
F_53 ( V_32 ) ;
V_32 = V_137 -> V_116 [ V_138 ] . V_32 ;
if ( V_32 )
F_53 ( V_32 ) ;
}
}
static void F_54 ( struct V_53 * V_6 )
{
F_52 ( V_6 ) ;
}
static int F_55 ( struct V_53 * V_6 )
{
struct V_7 * V_7 = V_6 -> V_6 . V_7 ;
struct V_139 * V_140 = V_7 -> V_6 ;
struct V_141 * V_142 = V_140 -> V_143 -> V_144 ;
struct V_1 * V_2 ;
int V_145 ;
int V_138 ;
int V_56 ;
V_145 = F_56 ( V_142 , L_2 ) ;
if ( V_145 < 0 )
return V_145 ;
for ( V_138 = 0 ; V_138 < V_145 ; V_138 ++ ) {
struct V_31 * V_32 ;
struct V_68 * V_146 ;
const char * V_147 ;
unsigned V_5 ;
unsigned int V_91 ;
V_56 = F_57 ( V_142 , L_2 , V_138 , & V_147 ) ;
if ( V_56 )
goto V_148;
if ( F_58 ( V_147 , L_3 ) )
V_5 = 1 ;
else if ( F_58 ( V_147 , L_4 ) )
V_5 = 0 ;
else {
F_59 ( V_140 , L_5 , V_147 ) ;
goto V_148;
}
V_56 = F_60 ( V_147 + 2 , 0 , & V_91 ) ;
if ( V_56 )
goto V_148;
V_56 = - V_149 ;
if ( V_91 > V_6 -> V_114 || ! V_91 )
goto V_148;
if ( V_5 )
V_2 = & V_6 -> V_115 [ V_91 - 1 ] ;
else
V_2 = & V_6 -> V_116 [ V_91 - 1 ] ;
V_2 -> V_6 = V_6 ;
V_2 -> V_96 = V_91 ;
V_2 -> V_5 = V_5 ;
F_61 ( & V_2 -> V_61 ) ;
V_146 = & V_2 -> V_22 ;
V_146 -> V_65 = V_2 ;
V_146 -> V_23 = V_24 ;
V_146 -> V_150 = V_151 ;
V_32 = F_62 ( V_140 -> V_143 , V_147 ) ;
if ( F_63 ( V_32 ) ) {
V_56 = F_64 ( V_32 ) ;
if ( V_56 != - V_152 )
F_59 ( V_140 , L_6 ,
V_147 , V_56 ) ;
goto V_148;
}
V_2 -> V_32 = V_32 ;
}
return 0 ;
V_148:
F_52 ( V_6 ) ;
return V_56 ;
}
void F_65 ( struct V_111 * V_112 )
{
struct V_53 * V_6 = F_18 ( V_112 ,
struct V_53 , V_6 ) ;
F_66 ( & V_6 -> V_58 ) ;
F_54 ( V_6 ) ;
F_67 ( V_6 -> V_116 ) ;
F_67 ( V_6 -> V_115 ) ;
F_67 ( V_6 ) ;
}
struct V_111 *
F_68 ( struct V_7 * V_7 , void T_3 * V_153 )
{
struct V_53 * V_6 ;
int V_154 ;
int V_56 = 0 ;
if ( ! V_7 -> V_6 -> V_143 -> V_144 ) {
F_59 ( V_7 -> V_6 , L_7 ) ;
return NULL ;
}
V_6 = F_69 ( sizeof( * V_6 ) , V_155 ) ;
if ( ! V_6 )
goto V_156;
F_70 ( & V_6 -> V_58 , V_157 , V_86 ) ;
V_6 -> V_58 . V_158 = F_17 ;
F_61 ( & V_6 -> V_62 ) ;
V_6 -> V_6 . V_159 = F_40 ;
V_6 -> V_6 . V_160 = F_42 ;
V_6 -> V_6 . V_161 = F_44 ;
V_6 -> V_6 . V_162 = F_47 ;
V_6 -> V_6 . V_163 = F_46 ;
V_6 -> V_6 . V_7 = V_7 ;
if ( V_7 -> V_131 . V_132 & V_133 ) {
V_6 -> V_134 = V_164 ;
V_6 -> V_102 = V_165 ;
V_6 -> V_106 = F_34 ;
V_6 -> V_114 = V_166 ;
} else {
V_6 -> V_134 = V_167 ;
V_6 -> V_102 = V_168 ;
V_6 -> V_106 = F_32 ;
V_6 -> V_114 = V_169 ;
}
V_154 = V_6 -> V_114 *
sizeof( struct V_1 ) ;
V_6 -> V_116 = F_69 ( V_154 , V_155 ) ;
if ( ! V_6 -> V_116 )
goto V_170;
V_6 -> V_115 = F_69 ( V_154 , V_155 ) ;
if ( ! V_6 -> V_115 )
goto V_171;
V_56 = F_55 ( V_6 ) ;
if ( V_56 )
goto V_172;
return & V_6 -> V_6 ;
V_172:
F_67 ( V_6 -> V_115 ) ;
V_171:
F_67 ( V_6 -> V_116 ) ;
V_170:
F_67 ( V_6 ) ;
V_156:
if ( V_56 == - V_152 )
return F_71 ( V_56 ) ;
return NULL ;
}
