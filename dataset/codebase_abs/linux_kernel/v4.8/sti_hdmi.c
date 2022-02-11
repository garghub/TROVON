T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_5 , int V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_2 F_5 ( int V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
if ( V_2 -> V_8 & V_9 ) {
V_2 -> V_10 = F_2 ( V_2 -> V_4 + V_11 ) & V_12 ;
if ( V_2 -> V_13 )
F_6 ( V_2 -> V_13 ) ;
}
if ( V_2 -> V_8 & ( V_14 | V_15 ) ) {
V_2 -> V_16 = true ;
F_7 ( & V_2 -> V_17 ) ;
}
if ( V_2 -> V_8 & V_18 )
F_8 ( L_1 ) ;
return V_19 ;
}
static T_2 F_9 ( int V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
V_2 -> V_8 = F_1 ( V_2 , V_20 ) ;
F_3 ( V_2 , V_2 -> V_8 , V_21 ) ;
F_1 ( V_2 , V_20 ) ;
return V_22 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_23 , V_24 ;
T_1 V_25 , V_26 ;
V_23 = F_11 ( V_2 -> V_27 , 1 ) ;
V_24 = F_11 ( V_2 -> V_27 , V_2 -> V_27 . V_28 ) ;
V_25 = F_12 ( V_2 -> V_27 , 0 ) ;
V_26 = F_12 ( V_2 -> V_27 , V_2 -> V_27 . V_29 - 1 ) ;
F_3 ( V_2 , V_23 , V_30 ) ;
F_3 ( V_2 , V_24 , V_31 ) ;
F_3 ( V_2 , V_25 , V_32 ) ;
F_3 ( V_2 , V_26 , V_33 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_34 ;
F_14 ( L_2 ) ;
V_34 = V_35 | V_36 ;
V_34 |= V_37 ;
if ( V_2 -> V_38 == V_39 )
V_34 |= V_40 ;
V_34 |= V_41 ;
if ( V_2 -> V_27 . V_42 & V_43 ) {
F_14 ( L_3 ) ;
V_34 |= V_44 ;
}
if ( V_2 -> V_27 . V_42 & V_45 ) {
F_14 ( L_4 ) ;
V_34 |= V_46 ;
}
V_34 |= V_47 ;
F_3 ( V_2 , V_34 , V_48 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
T_1 V_49 )
{
T_1 V_5 , V_50 ;
T_1 V_51 , V_52 ;
switch ( V_49 ) {
case V_53 :
V_51 = F_16 ( V_53 ) ;
V_52 = F_17 ( V_53 ) ;
break;
case V_54 :
V_51 = F_16 ( V_54 ) ;
V_52 = F_17 ( V_54 ) ;
break;
case V_55 :
V_51 = F_16 ( V_55 ) ;
V_52 = F_17 ( V_55 ) ;
break;
default:
F_18 ( L_5 , V_49 ) ;
return;
}
V_5 = F_1 ( V_2 , V_56 ) ;
V_5 &= ~ F_19 ( V_57 , V_49 ) ;
F_3 ( V_2 , V_5 , V_56 ) ;
F_3 ( V_2 , 0x0 , V_51 ) ;
for ( V_50 = 0 ; V_50 < V_58 ; V_50 += sizeof( T_1 ) )
F_3 ( V_2 , 0x0 , V_52 + V_50 ) ;
}
static inline unsigned int F_20 ( const T_3 * V_59 , T_4 V_60 )
{
unsigned long V_61 = 0 ;
T_4 V_50 ;
for ( V_50 = V_60 ; V_50 > 0 ; V_50 -- )
V_61 = ( V_61 << 8 ) | V_59 [ V_50 - 1 ] ;
return V_61 ;
}
static void F_21 ( struct V_1 * V_2 ,
const T_3 * V_62 ,
T_4 V_60 )
{
const T_3 * V_59 = V_62 ;
T_1 V_5 , V_49 , V_27 , V_50 ;
T_1 V_51 , V_52 ;
switch ( * V_59 ) {
case V_63 :
V_49 = V_53 ;
V_27 = V_64 ;
V_51 = F_16 ( V_53 ) ;
V_52 = F_17 ( V_53 ) ;
break;
case V_65 :
V_49 = V_54 ;
V_27 = V_66 ;
V_51 = F_16 ( V_54 ) ;
V_52 = F_17 ( V_54 ) ;
break;
case V_67 :
V_49 = V_55 ;
V_27 = V_66 ;
V_51 = F_16 ( V_55 ) ;
V_52 = F_17 ( V_55 ) ;
break;
default:
F_18 ( L_6 , * V_59 ) ;
return;
}
V_5 = F_1 ( V_2 , V_56 ) ;
V_5 &= ~ F_19 ( V_57 , V_49 ) ;
F_3 ( V_2 , V_5 , V_56 ) ;
V_5 = F_22 ( * V_59 ++ ) ;
V_5 |= F_23 ( * V_59 ++ ) ;
V_5 |= F_24 ( * V_59 ++ ) ;
F_4 ( V_5 , V_2 -> V_4 + V_51 ) ;
V_60 = V_60 - V_68 + 1 ;
for ( V_50 = 0 ; V_50 < V_60 ; V_50 += sizeof( T_1 ) ) {
T_4 V_69 ;
V_69 = F_25 ( T_4 , V_60 - V_50 , sizeof( T_1 ) ) ;
V_5 = F_20 ( V_59 , V_69 ) ;
V_59 += sizeof( T_1 ) ;
F_4 ( V_5 , V_2 -> V_4 + V_52 + V_50 ) ;
}
V_5 = F_1 ( V_2 , V_56 ) ;
V_5 |= F_19 ( V_27 , V_49 ) ;
F_3 ( V_2 , V_5 , V_56 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_70 * V_27 = & V_2 -> V_27 ;
struct V_71 V_72 ;
T_3 V_73 [ F_27 ( V_74 ) ] ;
int V_75 ;
F_14 ( L_2 ) ;
V_75 = F_28 ( & V_72 , V_27 ) ;
if ( V_75 < 0 ) {
F_18 ( L_7 , V_75 ) ;
return V_75 ;
}
V_72 . V_76 = V_2 -> V_76 ;
V_72 . V_77 = V_78 ;
V_72 . V_79 = V_80 ;
V_75 = F_29 ( & V_72 , V_73 , sizeof( V_73 ) ) ;
if ( V_75 < 0 ) {
F_18 ( L_8 , V_75 ) ;
return V_75 ;
}
F_21 ( V_2 , V_73 , V_75 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = & V_2 -> V_82 ;
T_3 V_73 [ F_27 ( V_83 ) ] ;
int V_75 , V_5 ;
F_14 ( L_9 , V_84 ,
V_82 -> V_85 ? L_10 : L_11 ) ;
if ( V_82 -> V_85 ) {
V_75 = F_31 ( & V_82 -> V_86 , V_73 ,
sizeof( V_73 ) ) ;
if ( V_75 < 0 ) {
F_18 ( L_12 , V_75 ) ;
return V_75 ;
}
F_21 ( V_2 , V_73 , V_75 ) ;
} else {
V_5 = F_1 ( V_2 , V_56 ) ;
V_5 &= ~ F_19 ( V_57 ,
V_54 ) ;
F_3 ( V_2 , V_5 , V_56 ) ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_70 * V_27 = & V_2 -> V_27 ;
struct V_87 V_72 ;
T_3 V_73 [ V_68 + V_88 ] ;
int V_75 ;
F_14 ( L_2 ) ;
V_75 = F_33 ( & V_72 , V_27 ) ;
if ( V_75 < 0 ) {
return 0 ;
}
V_75 = F_34 ( & V_72 , V_73 , sizeof( V_73 ) ) ;
if ( V_75 < 0 ) {
F_18 ( L_13 , V_75 ) ;
return V_75 ;
}
F_21 ( V_2 , V_73 , V_75 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_5 ;
F_14 ( L_2 ) ;
if ( F_36 ( V_2 -> V_89 ) )
F_8 ( L_14 ) ;
V_2 -> V_16 = false ;
V_5 = F_1 ( V_2 , V_48 ) ;
V_5 |= V_90 ;
F_3 ( V_2 , V_5 , V_48 ) ;
F_37 ( V_2 -> V_17 ,
V_2 -> V_16 == true ,
F_38
( V_91 ) ) ;
if ( ( F_1 ( V_2 , V_11 ) & V_92 ) == 0 )
F_14 ( L_15 ) ;
V_5 = F_1 ( V_2 , V_48 ) ;
V_5 &= ~ V_90 ;
F_3 ( V_2 , V_5 , V_48 ) ;
F_39 ( V_2 -> V_89 ) ;
}
static void F_40 ( struct V_93 * V_94 , int V_5 )
{
int V_95 ;
F_41 ( V_94 , L_16 ) ;
V_95 = V_5 & V_40 ;
F_42 ( L_17 , V_95 ? L_18 : L_19 ) ;
F_41 ( V_94 , L_20 ) ;
V_95 = V_5 & V_96 ;
F_42 ( L_21 , V_95 ? L_10 : L_11 ) ;
F_41 ( V_94 , L_20 ) ;
V_95 = V_5 & V_37 ;
F_42 ( L_22 , V_95 ? L_23 : L_24 ) ;
F_41 ( V_94 , L_20 ) ;
V_95 = V_5 & V_41 ;
F_42 ( L_25 , V_95 ? L_10 : L_11 ) ;
F_41 ( V_94 , L_20 ) ;
V_95 = V_5 & V_44 ;
F_42 ( L_26 , V_95 ? L_27 : L_28 ) ;
F_41 ( V_94 , L_20 ) ;
V_95 = V_5 & V_46 ;
F_42 ( L_29 , V_95 ? L_27 : L_28 ) ;
F_41 ( V_94 , L_20 ) ;
V_95 = V_5 & V_97 ;
F_42 ( L_30 , V_95 ? L_10 : L_11 ) ;
}
static void F_43 ( struct V_93 * V_94 , int V_5 )
{
int V_95 ;
F_41 ( V_94 , L_16 ) ;
V_95 = ( V_5 & V_98 ) ;
F_42 ( L_31 , V_95 ? L_32 : L_33 ) ;
F_41 ( V_94 , L_20 ) ;
V_95 = ( V_5 & V_12 ) ;
F_42 ( L_34 , V_95 ? L_35 : L_36 ) ;
}
static void F_44 ( struct V_93 * V_94 , int V_5 )
{
int V_95 ;
char * const V_99 [] = { L_37 ,
L_38 ,
L_39 ,
L_40 } ;
F_41 ( V_94 , L_16 ) ;
V_95 = ( V_5 & F_19 ( V_57 , 1 ) ) ;
F_42 ( L_41 , V_99 [ V_95 ] ) ;
F_41 ( V_94 , L_20 ) ;
V_95 = ( V_5 & F_19 ( V_57 , 2 ) ) >> 4 ;
F_42 ( L_42 , V_99 [ V_95 ] ) ;
F_41 ( V_94 , L_20 ) ;
V_95 = ( V_5 & F_19 ( V_57 , 3 ) ) >> 8 ;
F_42 ( L_43 , V_99 [ V_95 ] ) ;
F_41 ( V_94 , L_20 ) ;
V_95 = ( V_5 & F_19 ( V_57 , 4 ) ) >> 12 ;
F_42 ( L_44 , V_99 [ V_95 ] ) ;
F_41 ( V_94 , L_20 ) ;
V_95 = ( V_5 & F_19 ( V_57 , 5 ) ) >> 16 ;
F_42 ( L_45 , V_99 [ V_95 ] ) ;
F_41 ( V_94 , L_20 ) ;
V_95 = ( V_5 & F_19 ( V_57 , 6 ) ) >> 20 ;
F_42 ( L_46 , V_99 [ V_95 ] ) ;
}
static int F_45 ( struct V_93 * V_94 , void * V_62 )
{
struct V_100 * V_101 = V_94 -> V_102 ;
struct V_1 * V_2 = (struct V_1 * ) V_101 -> V_103 -> V_62 ;
F_46 ( V_94 , L_47 , V_2 -> V_4 ) ;
F_47 ( L_2 , V_48 ) ;
F_40 ( V_94 , F_1 ( V_2 , V_48 ) ) ;
F_47 ( L_48 , V_104 ) ;
F_47 ( L_2 , V_11 ) ;
F_43 ( V_94 , F_1 ( V_2 , V_11 ) ) ;
F_47 ( L_48 , V_30 ) ;
F_41 ( V_94 , L_16 ) ;
F_48 ( L_49 , F_1 ( V_2 , V_30 ) ) ;
F_47 ( L_48 , V_31 ) ;
F_41 ( V_94 , L_16 ) ;
F_48 ( L_50 , F_1 ( V_2 , V_31 ) ) ;
F_47 ( L_48 , V_32 ) ;
F_41 ( V_94 , L_16 ) ;
F_48 ( L_51 , F_1 ( V_2 , V_32 ) ) ;
F_47 ( L_48 , V_33 ) ;
F_41 ( V_94 , L_16 ) ;
F_48 ( L_52 , F_1 ( V_2 , V_33 ) ) ;
F_47 ( L_48 , V_56 ) ;
F_44 ( V_94 , F_1 ( V_2 , V_56 ) ) ;
F_47 ( L_2 , V_105 ) ;
F_47 ( L_2 , V_106 ) ;
F_47 ( L_2 , V_107 ) ;
F_46 ( V_94 , L_53 ,
V_53 ) ;
F_49 ( F_16 , V_53 ) ;
F_49 ( F_17 , V_53 ) ;
F_49 ( V_108 , V_53 ) ;
F_49 ( V_109 , V_53 ) ;
F_49 ( V_110 , V_53 ) ;
F_49 ( V_111 , V_53 ) ;
F_49 ( V_112 , V_53 ) ;
F_49 ( V_113 , V_53 ) ;
F_41 ( V_94 , L_2 ) ;
F_46 ( V_94 , L_54 ,
V_54 ) ;
F_49 ( F_16 , V_54 ) ;
F_49 ( F_17 , V_54 ) ;
F_49 ( V_108 , V_54 ) ;
F_49 ( V_109 , V_54 ) ;
F_49 ( V_110 , V_54 ) ;
F_49 ( V_111 , V_54 ) ;
F_49 ( V_112 , V_54 ) ;
F_49 ( V_113 , V_54 ) ;
F_41 ( V_94 , L_2 ) ;
F_46 ( V_94 , L_55 ,
V_55 ) ;
F_49 ( F_16 , V_55 ) ;
F_49 ( F_17 , V_55 ) ;
F_49 ( V_108 , V_55 ) ;
F_49 ( V_109 , V_55 ) ;
F_49 ( V_110 , V_55 ) ;
F_49 ( V_111 , V_55 ) ;
F_49 ( V_112 , V_55 ) ;
F_49 ( V_113 , V_55 ) ;
F_41 ( V_94 , L_2 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 , struct V_114 * V_115 )
{
F_51 ( V_116 ,
F_52 ( V_116 ) ,
V_115 ) ;
}
static int F_53 ( struct V_1 * V_2 , struct V_114 * V_115 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < F_52 ( V_116 ) ; V_50 ++ )
V_116 [ V_50 ] . V_62 = V_2 ;
return F_54 ( V_116 ,
F_52 ( V_116 ) ,
V_115 -> V_117 , V_115 ) ;
}
static void F_55 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = V_119 -> V_120 ;
T_1 V_5 = F_1 ( V_2 , V_48 ) ;
if ( ! V_2 -> V_85 )
return;
F_14 ( L_2 ) ;
V_5 &= ~ V_47 ;
F_3 ( V_2 , V_5 , V_48 ) ;
F_3 ( V_2 , 0xffffffff , V_21 ) ;
V_2 -> V_121 -> V_122 ( V_2 ) ;
F_15 ( V_2 , V_53 ) ;
F_15 ( V_2 , V_54 ) ;
F_15 ( V_2 , V_55 ) ;
F_3 ( V_2 , 0x0000 , V_123 ) ;
F_3 ( V_2 , 0x0000 , V_124 ) ;
F_3 ( V_2 , 0x0060 , V_125 ) ;
F_39 ( V_2 -> V_126 ) ;
F_39 ( V_2 -> V_127 ) ;
F_39 ( V_2 -> V_128 ) ;
V_2 -> V_85 = false ;
}
static void F_56 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = V_119 -> V_120 ;
F_14 ( L_2 ) ;
if ( V_2 -> V_85 )
return;
if ( F_36 ( V_2 -> V_128 ) )
F_18 ( L_56 ) ;
if ( F_36 ( V_2 -> V_127 ) )
F_18 ( L_57 ) ;
if ( F_36 ( V_2 -> V_126 ) )
F_18 ( L_58 ) ;
V_2 -> V_85 = true ;
if ( ! V_2 -> V_121 -> V_129 ( V_2 ) ) {
F_18 ( L_59 ) ;
return;
}
F_10 ( V_2 ) ;
F_3 ( V_2 , V_130 , V_104 ) ;
F_13 ( V_2 ) ;
if ( F_26 ( V_2 ) )
F_18 ( L_60 ) ;
if ( F_30 ( V_2 ) )
F_18 ( L_61 ) ;
if ( F_32 ( V_2 ) )
F_18 ( L_62 ) ;
F_35 ( V_2 ) ;
}
static void F_57 ( struct V_118 * V_119 ,
struct V_70 * V_27 ,
struct V_70 * V_131 )
{
struct V_1 * V_2 = V_119 -> V_120 ;
int V_75 ;
F_14 ( L_2 ) ;
memcpy ( & V_2 -> V_27 , V_27 , sizeof( struct V_70 ) ) ;
V_75 = F_58 ( V_2 -> V_128 , V_27 -> clock * 1000 ) ;
if ( V_75 < 0 ) {
F_18 ( L_63 ,
V_27 -> clock * 1000 ) ;
return;
}
V_75 = F_58 ( V_2 -> V_126 , V_27 -> clock * 1000 ) ;
if ( V_75 < 0 ) {
F_18 ( L_64 ,
V_27 -> clock * 1000 ) ;
return;
}
}
static void F_59 ( struct V_118 * V_119 )
{
}
static int F_60 ( struct V_132 * V_133 )
{
struct V_134 * V_135
= F_61 ( V_133 ) ;
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_136 * V_136 ;
int V_137 ;
F_14 ( L_2 ) ;
V_136 = F_62 ( V_133 , V_2 -> V_138 ) ;
if ( ! V_136 )
goto V_139;
V_137 = F_63 ( V_133 , V_136 ) ;
F_64 ( V_133 , V_136 ) ;
F_65 ( V_133 , V_136 ) ;
F_66 ( V_136 ) ;
return V_137 ;
V_139:
F_18 ( L_65 ) ;
return 0 ;
}
static int F_67 ( struct V_132 * V_133 ,
struct V_70 * V_27 )
{
int V_140 = V_27 -> clock * 1000 ;
int V_141 = V_140 - V_142 ;
int V_143 = V_140 + V_142 ;
int V_144 ;
struct V_134 * V_135
= F_61 ( V_133 ) ;
struct V_1 * V_2 = V_135 -> V_2 ;
V_144 = F_68 ( V_2 -> V_128 , V_140 ) ;
F_14 ( L_66 ,
V_140 , V_144 ) ;
if ( ( V_144 < V_141 ) || ( V_144 > V_143 ) ) {
F_14 ( L_67 , V_140 ) ;
return V_145 ;
}
return V_146 ;
}
static enum V_147
F_69 ( struct V_132 * V_133 , bool V_148 )
{
struct V_134 * V_135
= F_61 ( V_133 ) ;
struct V_1 * V_2 = V_135 -> V_2 ;
F_14 ( L_2 ) ;
if ( V_2 -> V_10 ) {
F_14 ( L_68 ) ;
return V_149 ;
}
F_14 ( L_69 ) ;
return V_150 ;
}
static void F_70 ( struct V_151 * V_13 ,
struct V_132 * V_133 )
{
struct V_134 * V_135
= F_61 ( V_133 ) ;
struct V_1 * V_2 = V_135 -> V_2 ;
struct V_152 * V_153 ;
V_2 -> V_76 = V_154 ;
V_153 = F_71 ( V_13 , 0 , L_70 ,
V_155 ,
F_52 ( V_155 ) ) ;
if ( ! V_153 ) {
F_18 ( L_71 ) ;
return;
}
V_135 -> V_156 = V_153 ;
F_72 ( & V_133 -> V_157 , V_153 , V_2 -> V_76 ) ;
V_2 -> V_38 = V_158 ;
V_153 = F_71 ( V_13 , 0 , L_72 ,
V_159 ,
F_52 ( V_159 ) ) ;
if ( ! V_153 ) {
F_18 ( L_71 ) ;
return;
}
V_135 -> V_160 = V_153 ;
F_72 ( & V_133 -> V_157 , V_153 , V_2 -> V_38 ) ;
}
static int
F_73 ( struct V_132 * V_133 ,
struct V_161 * V_162 ,
struct V_152 * V_163 ,
T_5 V_5 )
{
struct V_134 * V_135
= F_61 ( V_133 ) ;
struct V_1 * V_2 = V_135 -> V_2 ;
if ( V_163 == V_135 -> V_156 ) {
V_2 -> V_76 = V_5 ;
return 0 ;
}
if ( V_163 == V_135 -> V_160 ) {
V_2 -> V_38 = V_5 ;
return 0 ;
}
F_18 ( L_73 ) ;
return - V_164 ;
}
static int
F_74 ( struct V_132 * V_133 ,
const struct V_161 * V_162 ,
struct V_152 * V_163 ,
T_5 * V_5 )
{
struct V_134 * V_135
= F_61 ( V_133 ) ;
struct V_1 * V_2 = V_135 -> V_2 ;
if ( V_163 == V_135 -> V_156 ) {
* V_5 = V_2 -> V_76 ;
return 0 ;
}
if ( V_163 == V_135 -> V_160 ) {
* V_5 = V_2 -> V_38 ;
return 0 ;
}
F_18 ( L_74 ) ;
return - V_164 ;
}
static int F_75 ( struct V_132 * V_133 )
{
struct V_134 * V_135
= F_61 ( V_133 ) ;
struct V_1 * V_2 = V_135 -> V_2 ;
if ( F_53 ( V_2 , V_2 -> V_13 -> V_165 ) ) {
F_18 ( L_75 ) ;
return - V_164 ;
}
return 0 ;
}
static struct V_166 * F_76 ( struct V_151 * V_167 )
{
struct V_166 * V_168 ;
F_77 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_168 -> V_169 == V_170 )
return V_168 ;
}
return NULL ;
}
static int F_78 ( unsigned int V_171 )
{
unsigned int V_172 ;
switch ( V_171 ) {
case 32000 :
V_172 = 4096 ;
break;
case 44100 :
V_172 = 6272 ;
break;
case 48000 :
V_172 = 6144 ;
break;
case 88200 :
V_172 = 6272 * 2 ;
break;
case 96000 :
V_172 = 6144 * 2 ;
break;
case 176400 :
V_172 = 6272 * 4 ;
break;
case 192000 :
V_172 = 6144 * 4 ;
break;
default:
V_172 = ( V_171 * 128 ) / 1000 ;
}
return V_172 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_81 * V_173 )
{
int V_174 , V_172 ;
struct V_175 * V_176 = & V_173 -> V_86 ;
F_14 ( L_2 ) ;
if ( ! V_2 -> V_85 )
return 0 ;
V_172 = F_78 ( V_173 -> V_177 ) ;
F_14 ( L_76 ,
V_173 -> V_177 , V_2 -> V_27 . clock * 1000 , V_172 ) ;
F_3 ( V_2 , V_172 , V_107 ) ;
V_174 = V_178 | V_179 |
V_180 ;
switch ( V_176 -> V_181 ) {
case 8 :
V_174 |= V_182 ;
case 6 :
V_174 |= V_183 ;
case 4 :
V_174 |= V_184 | V_185 ;
case 2 :
V_174 |= V_186 ;
break;
default:
F_18 ( L_77 ,
V_176 -> V_181 ) ;
return - V_164 ;
}
F_3 ( V_2 , V_174 , V_105 ) ;
V_2 -> V_82 = * V_173 ;
return F_30 ( V_2 ) ;
}
static void F_80 ( struct V_187 * V_167 , void * V_62 )
{
struct V_1 * V_2 = F_81 ( V_167 ) ;
int V_174 ;
F_14 ( L_2 ) ;
V_174 = V_178 | V_179 |
V_180 ;
F_3 ( V_2 , V_174 , V_105 ) ;
V_2 -> V_82 . V_85 = 0 ;
F_30 ( V_2 ) ;
}
static int F_82 ( struct V_187 * V_167 ,
void * V_62 ,
struct V_188 * V_189 ,
struct V_190 * V_173 )
{
struct V_1 * V_2 = F_81 ( V_167 ) ;
int V_75 ;
struct V_81 V_82 = {
. V_191 = V_173 -> V_191 ,
. V_177 = V_173 -> V_177 ,
. V_86 = V_173 -> V_86 ,
} ;
F_14 ( L_2 ) ;
if ( ! V_2 -> V_85 )
return 0 ;
if ( ( V_189 -> V_192 != V_193 ) || V_189 -> V_194 ||
V_189 -> V_195 || V_189 -> V_196 ||
V_189 -> V_197 ) {
F_83 ( V_167 , L_78 , V_84 ,
V_189 -> V_194 , V_189 -> V_195 ,
V_189 -> V_196 ,
V_189 -> V_197 ) ;
return - V_164 ;
}
V_82 . V_85 = 1 ;
V_75 = F_79 ( V_2 , & V_82 ) ;
if ( V_75 < 0 )
return V_75 ;
return 0 ;
}
static int F_84 ( struct V_187 * V_167 , void * V_62 , bool V_198 )
{
struct V_1 * V_2 = F_81 ( V_167 ) ;
F_14 ( L_79 , V_198 ? L_10 : L_11 ) ;
if ( V_198 )
F_3 ( V_2 , V_199 , V_200 ) ;
else
F_3 ( V_2 , V_201 , V_200 ) ;
return 0 ;
}
static int F_85 ( struct V_187 * V_167 , void * V_62 , T_6 * V_202 , T_4 V_203 )
{
struct V_1 * V_2 = F_81 ( V_167 ) ;
struct V_132 * V_133 = V_2 -> V_132 ;
F_14 ( L_2 ) ;
memcpy ( V_202 , V_133 -> V_204 , F_86 ( sizeof( V_133 -> V_204 ) , V_203 ) ) ;
return 0 ;
}
static int F_87 ( struct V_187 * V_167 ,
struct V_1 * V_2 )
{
struct V_205 V_206 = {
. V_207 = & V_208 ,
. V_209 = 8 ,
. V_210 = 1 ,
} ;
F_14 ( L_2 ) ;
V_2 -> V_82 . V_85 = 0 ;
V_2 -> V_211 = F_88 (
V_167 , V_212 , V_213 ,
& V_206 , sizeof( V_206 ) ) ;
if ( F_89 ( V_2 -> V_211 ) )
return F_90 ( V_2 -> V_211 ) ;
F_8 ( L_80 , V_212 , F_91 ( V_167 ) ) ;
return 0 ;
}
static int F_92 ( struct V_187 * V_167 , struct V_187 * V_214 , void * V_62 )
{
struct V_1 * V_2 = F_81 ( V_167 ) ;
struct V_151 * V_13 = V_62 ;
struct V_166 * V_168 ;
struct V_134 * V_133 ;
struct V_132 * V_132 ;
struct V_118 * V_119 ;
int V_215 ;
V_2 -> V_13 = V_13 ;
V_168 = F_76 ( V_13 ) ;
if ( ! V_168 )
return - V_164 ;
V_133 = F_93 ( V_167 , sizeof( * V_133 ) , V_216 ) ;
if ( ! V_133 )
return - V_164 ;
V_133 -> V_2 = V_2 ;
V_119 = F_93 ( V_167 , sizeof( * V_119 ) , V_216 ) ;
if ( ! V_119 )
return - V_164 ;
V_119 -> V_120 = V_2 ;
V_119 -> V_217 = & V_218 ;
F_94 ( V_13 , V_119 ) ;
V_168 -> V_119 = V_119 ;
V_133 -> V_168 = V_168 ;
V_132 = (struct V_132 * ) V_133 ;
V_132 -> V_219 = V_220 ;
F_95 ( V_13 , V_132 ,
& V_221 , V_222 ) ;
F_96 ( V_132 ,
& V_223 ) ;
F_70 ( V_13 , V_132 ) ;
V_2 -> V_132 = V_132 ;
V_215 = F_97 ( V_132 , V_168 ) ;
if ( V_215 ) {
F_18 ( L_81 ) ;
goto V_224;
}
V_215 = F_87 ( V_167 , V_2 ) ;
if ( V_215 ) {
F_18 ( L_82 ) ;
goto V_224;
}
V_215 = F_98 ( & V_2 -> V_82 . V_86 ) ;
if ( V_215 ) {
F_18 ( L_83 ) ;
goto V_224;
}
F_3 ( V_2 , V_225 , V_104 ) ;
return 0 ;
V_224:
F_99 ( V_119 ) ;
V_2 -> V_132 = NULL ;
return - V_164 ;
}
static void F_100 ( struct V_187 * V_167 ,
struct V_187 * V_214 , void * V_62 )
{
struct V_1 * V_2 = F_81 ( V_167 ) ;
struct V_151 * V_13 = V_62 ;
F_50 ( V_2 , V_13 -> V_165 ) ;
}
static int F_101 ( struct V_226 * V_227 )
{
struct V_187 * V_167 = & V_227 -> V_167 ;
struct V_1 * V_2 ;
struct V_228 * V_229 = V_167 -> V_230 ;
struct V_231 * V_232 ;
struct V_228 * V_233 ;
int V_75 ;
F_8 ( L_79 , V_84 ) ;
V_2 = F_93 ( V_167 , sizeof( * V_2 ) , V_216 ) ;
if ( ! V_2 )
return - V_234 ;
V_233 = F_102 ( V_227 -> V_167 . V_230 , L_84 , 0 ) ;
if ( V_233 ) {
V_2 -> V_138 = F_103 ( V_233 ) ;
F_104 ( V_233 ) ;
if ( ! V_2 -> V_138 )
return - V_235 ;
}
V_2 -> V_167 = V_227 -> V_167 ;
V_232 = F_105 ( V_227 , V_236 , L_85 ) ;
if ( ! V_232 ) {
F_18 ( L_86 ) ;
V_75 = - V_234 ;
goto V_237;
}
V_2 -> V_4 = F_106 ( V_167 , V_232 -> V_129 , F_107 ( V_232 ) ) ;
if ( ! V_2 -> V_4 ) {
V_75 = - V_234 ;
goto V_237;
}
if ( F_108 ( V_229 , L_87 ) ) {
V_232 = F_105 ( V_227 , V_236 ,
L_88 ) ;
if ( ! V_232 ) {
F_18 ( L_89 ) ;
V_75 = - V_234 ;
goto V_237;
}
V_2 -> V_238 = F_106 ( V_167 , V_232 -> V_129 ,
F_107 ( V_232 ) ) ;
if ( ! V_2 -> V_238 ) {
V_75 = - V_234 ;
goto V_237;
}
}
V_2 -> V_121 = (struct V_239 * )
F_109 ( V_240 , V_229 ) -> V_62 ;
V_2 -> V_128 = F_110 ( V_167 , L_90 ) ;
if ( F_89 ( V_2 -> V_128 ) ) {
F_18 ( L_91 ) ;
V_75 = F_90 ( V_2 -> V_128 ) ;
goto V_237;
}
V_2 -> V_127 = F_110 ( V_167 , L_92 ) ;
if ( F_89 ( V_2 -> V_127 ) ) {
F_18 ( L_93 ) ;
V_75 = F_90 ( V_2 -> V_127 ) ;
goto V_237;
}
V_2 -> V_126 = F_110 ( V_167 , L_94 ) ;
if ( F_89 ( V_2 -> V_126 ) ) {
F_18 ( L_95 ) ;
V_75 = F_90 ( V_2 -> V_126 ) ;
goto V_237;
}
V_2 -> V_89 = F_110 ( V_167 , L_96 ) ;
if ( F_89 ( V_2 -> V_89 ) ) {
F_18 ( L_97 ) ;
V_75 = F_90 ( V_2 -> V_89 ) ;
goto V_237;
}
V_2 -> V_10 = F_2 ( V_2 -> V_4 + V_11 ) & V_12 ;
F_111 ( & V_2 -> V_17 ) ;
V_2 -> V_6 = F_112 ( V_227 , L_98 ) ;
V_75 = F_113 ( V_167 , V_2 -> V_6 , F_9 ,
F_5 , V_241 , F_91 ( V_167 ) , V_2 ) ;
if ( V_75 ) {
F_18 ( L_99 ) ;
goto V_237;
}
V_2 -> V_242 = F_114 ( V_167 , L_100 ) ;
if ( ! F_89 ( V_2 -> V_242 ) )
F_115 ( V_2 -> V_242 ) ;
F_116 ( V_227 , V_2 ) ;
return F_117 ( & V_227 -> V_167 , & V_243 ) ;
V_237:
F_118 ( V_2 -> V_138 ) ;
return V_75 ;
}
static int F_119 ( struct V_226 * V_227 )
{
struct V_1 * V_2 = F_81 ( & V_227 -> V_167 ) ;
F_118 ( V_2 -> V_138 ) ;
if ( V_2 -> V_211 )
F_120 ( V_2 -> V_211 ) ;
F_121 ( & V_227 -> V_167 , & V_243 ) ;
return 0 ;
}
