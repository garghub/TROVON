static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 )
{
V_5 = ( V_5 & V_4 ) | ( F_2 ( V_2 -> V_6 + V_3 ) & ~ V_4 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_5 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return - V_11 ;
if ( ! F_6 ( V_12 , & V_2 -> V_10 ) ) {
V_5 = V_13 ;
if ( V_2 -> V_14 & V_15 )
V_5 |= V_16 ;
else
V_5 |= V_17 ;
F_3 ( V_5 , V_2 -> V_6 + V_18 ) ;
}
return 0 ;
}
static void F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
if ( F_8 ( V_12 , & V_2 -> V_10 ) )
F_3 ( 0 , V_2 -> V_6 + V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_5 = ! ( V_2 -> V_14 & V_19 )
? V_20 | V_21 |
V_22 | V_23
: V_20 | V_21 |
V_24 | V_25 ;
F_3 ( V_5 , V_2 -> V_6 + V_26 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_27 * V_28 = & V_8 -> V_29 . V_30 ;
T_1 V_5 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
if ( V_2 -> V_14 & V_31 ) {
V_28 -> V_32 = V_28 -> V_33 + 10 ;
V_28 -> V_34 = V_28 -> V_35 - 92 ;
V_28 -> V_36 = V_28 -> V_37 + 1 ;
V_28 -> V_38 = V_28 -> V_36 + 1 ;
}
if ( V_2 -> V_14 & ( V_15 | V_19 ) )
F_9 ( V_2 ) ;
V_5 = V_39 ;
if ( V_2 -> V_14 & V_15 ) {
V_5 |= V_40 ;
} else {
V_5 |= V_41 ;
}
F_3 ( V_5 , V_2 -> V_6 + V_42 ) ;
V_5 = F_11 ( V_28 -> V_43 - 1 ) |
F_12 ( V_28 -> V_44 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_45 ) ;
if ( ! ( V_2 -> V_14 & V_15 ) ) {
V_5 = F_13 (
V_28 -> V_46 - V_28 -> V_38 - 1 ) |
F_14 (
V_28 -> V_36 - V_28 -> V_37 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_47 ) ;
V_5 = F_15 (
V_28 -> V_38 - V_28 -> V_36 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_48 ) ;
V_5 = F_16 (
V_28 -> V_35 - V_28 -> V_34 - 1 ) |
F_17 (
V_28 -> V_32 - V_28 -> V_33 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_49 ) ;
V_5 = F_18 (
V_28 -> V_34 - V_28 -> V_32 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_50 ) ;
}
F_1 ( V_2 , V_51 , V_52 | V_53 , ~ 0 ) ;
F_1 ( V_2 , V_54 , V_55 , ~ 0 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_56 ,
struct V_57 * V_58 )
{
unsigned long V_5 ;
V_5 = F_2 ( V_2 -> V_6 + F_20 ( V_56 ) ) ;
V_5 &= ~ V_59 ;
switch ( V_58 -> V_60 ) {
case V_61 :
V_5 |= V_62 ;
V_5 |= V_63 ;
V_5 |= V_64 ;
break;
case V_65 :
V_5 |= V_66 ;
V_5 |= V_63 ;
V_5 |= V_64 ;
break;
case V_67 :
V_5 |= V_68 ;
V_5 |= V_69 ;
V_5 |= V_64 ;
break;
case V_70 :
V_5 |= V_71 ;
V_5 |= V_69 | V_72 | V_73 ;
V_5 |= V_64 ;
break;
default:
F_21 ( L_1 ) ;
return;
}
F_22 ( L_2 , V_58 -> V_74 ) ;
if ( V_58 -> V_75 < V_76 ) {
V_5 &= ~ V_77 ;
V_5 |= V_78 ;
}
F_3 ( V_5 , V_2 -> V_6 + F_20 ( V_56 ) ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_56 ,
bool V_79 )
{
F_1 ( V_2 , V_80 , F_24 ( V_56 ) ,
V_79 ? ~ 0 : 0 ) ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_81 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
for ( V_81 = V_2 -> V_82 ; V_81 < V_83 ; V_81 ++ )
F_23 ( V_2 , V_81 , true ) ;
}
static void F_26 ( struct V_7 * V_8 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 =
F_27 ( V_85 -> V_29 . V_87 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_57 * V_58 = V_87 -> V_29 . V_58 ;
unsigned int V_56 = V_85 -> V_88 ;
unsigned int V_89 = V_58 -> V_74 >> 3 ;
unsigned int V_90 = V_58 -> V_91 [ 0 ] ;
T_2 V_92 = F_28 ( V_58 , 0 ) ;
T_1 V_5 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
V_5 = F_29 ( V_87 -> V_8 . V_93 ) | F_30 ( V_87 -> V_8 . V_94 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_31 ( V_56 ) ) ;
V_5 = F_29 ( V_87 -> V_8 . V_93 + V_87 -> V_8 . V_95 - 1 ) |
F_30 ( V_87 -> V_8 . V_94 + V_87 -> V_8 . V_96 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_32 ( V_56 ) ) ;
V_5 = F_33 ( 0x0 ) | F_34 ( 0x0 ) |
F_35 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_36 ( V_56 ) ) ;
V_5 = F_33 ( 0x0 ) | F_34 ( 0x0 ) |
F_35 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_37 ( V_56 ) ) ;
F_3 ( V_92 , V_2 -> V_6 + F_38 ( V_56 ) ) ;
V_5 = V_92 + V_90 * V_87 -> V_97 . V_96 ;
F_3 ( V_5 , V_2 -> V_6 + F_39 ( V_56 ) ) ;
if ( ! ( V_2 -> V_14 & V_31 ) )
V_5 = F_40 ( V_90 - V_87 -> V_8 . V_95 * V_89 , 27 , 14 )
| F_40 ( V_87 -> V_8 . V_95 * V_89 , 13 , 0 ) ;
else
V_5 = F_40 ( V_90 - V_87 -> V_8 . V_95 * V_89 , 29 , 15 )
| F_40 ( V_87 -> V_8 . V_95 * V_89 , 14 , 0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_41 ( V_56 ) ) ;
F_19 ( V_2 , V_56 , V_58 ) ;
F_1 ( V_2 , F_20 ( V_56 ) , V_98 , ~ 0 ) ;
F_42 ( V_99 , & V_2 -> V_10 ) ;
}
static void F_43 ( struct V_7 * V_8 ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_56 = V_85 -> V_88 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
F_1 ( V_2 , F_20 ( V_56 ) , V_98 , 0 ) ;
F_42 ( V_99 , & V_2 -> V_10 ) ;
}
static void F_44 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_81 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
for ( V_81 = V_2 -> V_82 ; V_81 < V_83 ; V_81 ++ )
F_23 ( V_2 , V_81 , false ) ;
if ( F_8 ( V_99 , & V_2 -> V_10 ) )
F_1 ( V_2 , V_54 , V_55 , ~ 0 ) ;
if ( V_2 -> V_14 & V_15 )
F_42 ( V_100 , & V_2 -> V_10 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned int V_101 ;
F_3 ( 0 , V_2 -> V_6 + V_51 ) ;
for ( V_101 = 2000 ; V_101 ; -- V_101 ) {
if ( ~ F_2 ( V_2 -> V_6 + V_51 ) & V_102 )
break;
F_46 ( 10 ) ;
}
F_47 ( V_101 == 0 , L_3 ) ;
F_3 ( V_103 , V_2 -> V_6 + V_51 ) ;
for ( V_101 = 2000 ; V_101 ; -- V_101 ) {
if ( ~ F_2 ( V_2 -> V_6 + V_51 ) & V_103 )
break;
F_46 ( 10 ) ;
}
F_47 ( V_101 == 0 , L_4 ) ;
if ( ! ( V_2 -> V_14 & V_31 ) )
return;
F_3 ( V_104 | V_105 , V_2 -> V_6 + V_51 ) ;
F_1 ( V_2 , V_106 ,
V_107 | V_108 , ~ 0 ) ;
F_3 ( V_109 , V_2 -> V_6 + V_110 ) ;
F_3 ( V_111 | V_112 | V_113 ,
V_2 -> V_6 + V_114 ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_8 ( V_9 , & V_2 -> V_10 ) )
return;
F_49 ( V_2 -> V_115 ) ;
F_50 ( V_8 , true ) ;
F_42 ( V_116 , & V_2 -> V_10 ) ;
F_45 ( V_2 ) ;
if ( F_8 ( V_12 , & V_2 -> V_10 ) )
F_4 ( V_2 -> V_8 ) ;
F_10 ( V_2 -> V_8 ) ;
}
static void F_51 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_81 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
for ( V_81 = V_2 -> V_82 ; V_81 < V_83 ; V_81 ++ )
F_43 ( V_8 , & V_2 -> V_117 [ V_81 ] ) ;
F_45 ( V_2 ) ;
F_52 ( V_116 , & V_2 -> V_10 ) ;
F_50 ( V_8 , false ) ;
F_53 ( V_2 -> V_115 ) ;
F_42 ( V_9 , & V_2 -> V_10 ) ;
}
static void F_54 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_5 ( V_116 , & V_2 -> V_10 ) ||
( V_2 -> V_14 & V_19 ) )
return;
if ( F_8 ( V_100 , & V_2 -> V_10 ) )
F_1 ( V_2 , V_26 , V_118 , ~ 0 ) ;
}
static void F_55 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_56 , V_81 , V_119 ;
F_22 ( L_5 , __FILE__ ) ;
for ( V_81 = 0 ; V_81 < F_56 ( V_120 ) ; V_81 ++ ) {
V_119 = F_57 ( V_2 -> V_121 [ V_81 ] ) ;
if ( V_119 < 0 )
goto V_122;
}
for ( V_56 = 0 ; V_56 < V_83 ; V_56 ++ ) {
F_23 ( V_2 , V_56 , true ) ;
F_1 ( V_2 , F_20 ( V_56 ) , V_98 , 0 ) ;
F_23 ( V_2 , V_56 , false ) ;
}
F_1 ( V_2 , V_54 , V_55 , ~ 0 ) ;
F_58 ( 50 ) ;
V_122:
while ( -- V_81 >= 0 )
F_59 ( V_2 -> V_121 [ V_81 ] ) ;
}
static int F_60 ( struct V_123 * V_115 , struct V_123 * V_124 , void * V_125 )
{
struct V_1 * V_2 = F_61 ( V_115 ) ;
struct V_126 * V_127 = V_125 ;
struct V_128 * V_129 = V_127 -> V_130 ;
struct V_84 * V_131 ;
enum V_132 V_14 ;
unsigned int V_56 ;
int V_119 ;
V_2 -> V_127 = V_127 ;
V_2 -> V_133 = V_129 -> V_133 ++ ;
for ( V_56 = V_2 -> V_82 ; V_56 < V_83 ; V_56 ++ ) {
int V_134 = ( V_56 == V_2 -> V_82 ) ? 0 : V_56 ;
V_2 -> V_135 [ V_56 ] . V_136 = V_137 ;
V_2 -> V_135 [ V_56 ] . V_138 = F_56 ( V_137 ) ;
V_2 -> V_135 [ V_56 ] . V_139 = V_56 ;
V_2 -> V_135 [ V_56 ] . type = V_140 [ V_134 ] ;
V_119 = F_62 ( V_127 , & V_2 -> V_117 [ V_56 ] , V_56 ,
1 << V_2 -> V_133 , & V_2 -> V_135 [ V_56 ] ) ;
if ( V_119 )
return V_119 ;
}
V_131 = & V_2 -> V_117 [ V_2 -> V_82 ] ;
V_14 = ( V_2 -> V_14 & V_31 ) ? V_141
: V_142 ;
V_2 -> V_8 = F_63 ( V_127 , & V_131 -> V_29 ,
V_2 -> V_133 , V_14 ,
& V_143 , V_2 ) ;
if ( F_64 ( V_2 -> V_8 ) ) {
V_119 = F_65 ( V_2 -> V_8 ) ;
goto V_122;
}
F_55 ( V_2 -> V_8 ) ;
V_119 = F_66 ( V_127 , V_115 ) ;
if ( V_119 )
goto V_122;
return V_119 ;
V_122:
V_129 -> V_133 -- ;
return V_119 ;
}
static void F_67 ( struct V_123 * V_115 , struct V_123 * V_124 , void * V_125 )
{
struct V_1 * V_2 = F_61 ( V_115 ) ;
F_51 ( V_2 -> V_8 ) ;
F_68 ( V_2 -> V_127 , V_2 -> V_115 ) ;
}
static T_3 F_69 ( int V_144 , void * V_145 )
{
struct V_1 * V_2 = V_145 ;
T_1 V_5 ;
if ( ! F_5 ( V_116 , & V_2 -> V_10 ) )
goto V_146;
V_5 = F_2 ( V_2 -> V_6 + V_147 ) ;
V_5 &= V_148 | V_149 ;
if ( V_5 ) {
F_3 ( V_5 , V_2 -> V_6 + V_147 ) ;
F_70 ( & V_2 -> V_8 -> V_29 ) ;
}
V_146:
return V_150 ;
}
static int F_71 ( struct V_123 * V_115 )
{
struct V_1 * V_2 = F_61 ( V_115 ) ;
int V_81 = F_56 ( V_120 ) ;
while ( -- V_81 >= 0 )
F_59 ( V_2 -> V_121 [ V_81 ] ) ;
return 0 ;
}
static int F_72 ( struct V_123 * V_115 )
{
struct V_1 * V_2 = F_61 ( V_115 ) ;
int V_81 , V_119 ;
for ( V_81 = 0 ; V_81 < F_56 ( V_120 ) ; V_81 ++ ) {
V_119 = F_57 ( V_2 -> V_121 [ V_81 ] ) ;
if ( V_119 < 0 )
goto V_122;
}
return 0 ;
V_122:
while ( -- V_81 >= 0 )
F_59 ( V_2 -> V_121 [ V_81 ] ) ;
return V_119 ;
}
static int F_73 ( struct V_151 * V_152 )
{
struct V_123 * V_115 = & V_152 -> V_115 ;
struct V_1 * V_2 ;
struct V_153 * V_154 ;
int V_119 ;
int V_81 ;
V_2 = F_74 ( V_115 , sizeof( * V_2 ) , V_155 ) ;
if ( ! V_2 )
return - V_156 ;
F_75 ( V_9 , & V_2 -> V_10 ) ;
V_2 -> V_115 = V_115 ;
V_2 -> V_14 = ( unsigned long ) F_76 ( V_115 ) ;
if ( V_2 -> V_14 & V_31 ) {
V_2 -> V_82 = 1 ;
} else if ( F_77 ( V_115 -> V_157 , L_6 ) ) {
V_2 -> V_14 |= V_15 ;
}
for ( V_81 = 0 ; V_81 < F_56 ( V_120 ) ; V_81 ++ ) {
struct V_158 * V_158 ;
V_158 = F_78 ( V_2 -> V_115 , V_120 [ V_81 ] ) ;
if ( F_64 ( V_158 ) )
return F_65 ( V_158 ) ;
V_2 -> V_121 [ V_81 ] = V_158 ;
}
V_154 = F_79 ( V_152 , V_159 , 0 ) ;
if ( ! V_154 ) {
F_80 ( V_115 , L_7 ) ;
return - V_160 ;
}
V_2 -> V_6 = F_81 ( V_115 , V_154 ) ;
if ( F_64 ( V_2 -> V_6 ) ) {
F_80 ( V_115 , L_8 ) ;
return F_65 ( V_2 -> V_6 ) ;
}
V_154 = F_82 ( V_152 , V_161 ,
( V_2 -> V_14 & V_15 ) ? L_9 : L_10 ) ;
if ( ! V_154 ) {
F_80 ( V_115 , L_11 ) ;
return - V_160 ;
}
V_119 = F_83 ( V_115 , V_154 -> V_162 , F_69 , 0 ,
L_12 , V_2 ) ;
if ( V_119 < 0 ) {
F_80 ( V_115 , L_13 ) ;
return V_119 ;
}
F_84 ( V_152 , V_2 ) ;
F_85 ( V_115 ) ;
V_119 = F_86 ( V_115 , & V_163 ) ;
if ( V_119 )
goto V_164;
return 0 ;
V_164:
F_87 ( V_115 ) ;
return V_119 ;
}
static int F_88 ( struct V_151 * V_152 )
{
F_87 ( & V_152 -> V_115 ) ;
F_89 ( & V_152 -> V_115 , & V_163 ) ;
return 0 ;
}
