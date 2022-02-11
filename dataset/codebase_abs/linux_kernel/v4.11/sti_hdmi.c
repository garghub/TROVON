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
if ( V_2 -> V_38 )
V_34 |= V_39 ;
if ( V_2 -> V_27 . V_40 & V_41 ) {
F_14 ( L_3 ) ;
V_34 |= V_42 ;
}
if ( V_2 -> V_27 . V_40 & V_43 ) {
F_14 ( L_4 ) ;
V_34 |= V_44 ;
}
V_34 |= V_45 ;
F_3 ( V_2 , V_34 , V_46 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
T_1 V_47 )
{
T_1 V_5 , V_48 ;
T_1 V_49 , V_50 ;
switch ( V_47 ) {
case V_51 :
V_49 = F_16 ( V_51 ) ;
V_50 = F_17 ( V_51 ) ;
break;
case V_52 :
V_49 = F_16 ( V_52 ) ;
V_50 = F_17 ( V_52 ) ;
break;
case V_53 :
V_49 = F_16 ( V_53 ) ;
V_50 = F_17 ( V_53 ) ;
break;
default:
F_18 ( L_5 , V_47 ) ;
return;
}
V_5 = F_1 ( V_2 , V_54 ) ;
V_5 &= ~ F_19 ( V_55 , V_47 ) ;
F_3 ( V_2 , V_5 , V_54 ) ;
F_3 ( V_2 , 0x0 , V_49 ) ;
for ( V_48 = 0 ; V_48 < V_56 ; V_48 += sizeof( T_1 ) )
F_3 ( V_2 , 0x0 , V_50 + V_48 ) ;
}
static inline unsigned int F_20 ( const T_3 * V_57 , T_4 V_58 )
{
unsigned long V_59 = 0 ;
T_4 V_48 ;
for ( V_48 = V_58 ; V_48 > 0 ; V_48 -- )
V_59 = ( V_59 << 8 ) | V_57 [ V_48 - 1 ] ;
return V_59 ;
}
static void F_21 ( struct V_1 * V_2 ,
const T_3 * V_60 ,
T_4 V_58 )
{
const T_3 * V_57 = V_60 ;
T_1 V_5 , V_47 , V_27 , V_48 ;
T_1 V_49 , V_50 ;
switch ( * V_57 ) {
case V_61 :
V_47 = V_51 ;
V_27 = V_62 ;
V_49 = F_16 ( V_51 ) ;
V_50 = F_17 ( V_51 ) ;
break;
case V_63 :
V_47 = V_52 ;
V_27 = V_64 ;
V_49 = F_16 ( V_52 ) ;
V_50 = F_17 ( V_52 ) ;
break;
case V_65 :
V_47 = V_53 ;
V_27 = V_64 ;
V_49 = F_16 ( V_53 ) ;
V_50 = F_17 ( V_53 ) ;
break;
default:
F_18 ( L_6 , * V_57 ) ;
return;
}
V_5 = F_1 ( V_2 , V_54 ) ;
V_5 &= ~ F_19 ( V_55 , V_47 ) ;
F_3 ( V_2 , V_5 , V_54 ) ;
V_5 = F_22 ( * V_57 ++ ) ;
V_5 |= F_23 ( * V_57 ++ ) ;
V_5 |= F_24 ( * V_57 ++ ) ;
F_4 ( V_5 , V_2 -> V_4 + V_49 ) ;
V_58 = V_58 - V_66 + 1 ;
for ( V_48 = 0 ; V_48 < V_58 ; V_48 += sizeof( T_1 ) ) {
T_4 V_67 ;
V_67 = F_25 ( T_4 , V_58 - V_48 , sizeof( T_1 ) ) ;
V_5 = F_20 ( V_57 , V_67 ) ;
V_57 += sizeof( T_1 ) ;
F_4 ( V_5 , V_2 -> V_4 + V_50 + V_48 ) ;
}
V_5 = F_1 ( V_2 , V_54 ) ;
V_5 |= F_19 ( V_27 , V_47 ) ;
F_3 ( V_2 , V_5 , V_54 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_68 * V_27 = & V_2 -> V_27 ;
struct V_69 V_70 ;
T_3 V_71 [ F_27 ( V_72 ) ] ;
int V_73 ;
F_14 ( L_2 ) ;
V_73 = F_28 ( & V_70 , V_27 ) ;
if ( V_73 < 0 ) {
F_18 ( L_7 , V_73 ) ;
return V_73 ;
}
V_70 . V_74 = V_2 -> V_74 ;
V_70 . V_75 = V_76 ;
V_70 . V_77 = V_78 ;
V_73 = F_29 ( & V_70 , V_71 , sizeof( V_71 ) ) ;
if ( V_73 < 0 ) {
F_18 ( L_8 , V_73 ) ;
return V_73 ;
}
F_21 ( V_2 , V_71 , V_73 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = & V_2 -> V_80 ;
T_3 V_71 [ F_27 ( V_81 ) ] ;
int V_73 , V_5 ;
F_14 ( L_9 , V_82 ,
V_80 -> V_83 ? L_10 : L_11 ) ;
if ( V_80 -> V_83 ) {
V_73 = F_31 ( & V_80 -> V_84 , V_71 ,
sizeof( V_71 ) ) ;
if ( V_73 < 0 ) {
F_18 ( L_12 , V_73 ) ;
return V_73 ;
}
F_21 ( V_2 , V_71 , V_73 ) ;
} else {
V_5 = F_1 ( V_2 , V_54 ) ;
V_5 &= ~ F_19 ( V_55 ,
V_52 ) ;
F_3 ( V_2 , V_5 , V_54 ) ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_68 * V_27 = & V_2 -> V_27 ;
struct V_85 V_70 ;
T_3 V_71 [ V_66 + V_86 ] ;
int V_73 ;
F_14 ( L_2 ) ;
V_73 = F_33 ( & V_70 , V_27 ) ;
if ( V_73 < 0 ) {
return 0 ;
}
V_73 = F_34 ( & V_70 , V_71 , sizeof( V_71 ) ) ;
if ( V_73 < 0 ) {
F_18 ( L_13 , V_73 ) ;
return V_73 ;
}
F_21 ( V_2 , V_71 , V_73 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_5 ;
F_14 ( L_2 ) ;
if ( F_36 ( V_2 -> V_87 ) )
F_8 ( L_14 ) ;
V_2 -> V_16 = false ;
V_5 = F_1 ( V_2 , V_46 ) ;
V_5 |= V_88 ;
F_3 ( V_2 , V_5 , V_46 ) ;
F_37 ( V_2 -> V_17 ,
V_2 -> V_16 ,
F_38
( V_89 ) ) ;
if ( ( F_1 ( V_2 , V_11 ) & V_90 ) == 0 )
F_14 ( L_15 ) ;
V_5 = F_1 ( V_2 , V_46 ) ;
V_5 &= ~ V_88 ;
F_3 ( V_2 , V_5 , V_46 ) ;
F_39 ( V_2 -> V_87 ) ;
}
static void F_40 ( struct V_91 * V_92 , int V_5 )
{
int V_93 ;
F_41 ( V_92 , L_16 ) ;
V_93 = V_5 & V_39 ;
F_42 ( L_17 , V_93 ? L_18 : L_19 ) ;
F_41 ( V_92 , L_20 ) ;
V_93 = V_5 & V_94 ;
F_42 ( L_21 , V_93 ? L_10 : L_11 ) ;
F_41 ( V_92 , L_20 ) ;
V_93 = V_5 & V_37 ;
F_42 ( L_22 , V_93 ? L_23 : L_24 ) ;
F_41 ( V_92 , L_20 ) ;
V_93 = V_5 & V_42 ;
F_42 ( L_25 , V_93 ? L_26 : L_27 ) ;
F_41 ( V_92 , L_20 ) ;
V_93 = V_5 & V_44 ;
F_42 ( L_28 , V_93 ? L_26 : L_27 ) ;
F_41 ( V_92 , L_20 ) ;
V_93 = V_5 & V_95 ;
F_42 ( L_29 , V_93 ? L_10 : L_11 ) ;
}
static void F_43 ( struct V_91 * V_92 , int V_5 )
{
int V_93 ;
F_41 ( V_92 , L_16 ) ;
V_93 = ( V_5 & V_96 ) ;
F_42 ( L_30 , V_93 ? L_31 : L_32 ) ;
F_41 ( V_92 , L_20 ) ;
V_93 = ( V_5 & V_12 ) ;
F_42 ( L_33 , V_93 ? L_34 : L_35 ) ;
}
static void F_44 ( struct V_91 * V_92 , int V_5 )
{
int V_93 ;
char * const V_97 [] = { L_36 ,
L_37 ,
L_38 ,
L_39 } ;
F_41 ( V_92 , L_16 ) ;
V_93 = ( V_5 & F_19 ( V_55 , 1 ) ) ;
F_42 ( L_40 , V_97 [ V_93 ] ) ;
F_41 ( V_92 , L_20 ) ;
V_93 = ( V_5 & F_19 ( V_55 , 2 ) ) >> 4 ;
F_42 ( L_41 , V_97 [ V_93 ] ) ;
F_41 ( V_92 , L_20 ) ;
V_93 = ( V_5 & F_19 ( V_55 , 3 ) ) >> 8 ;
F_42 ( L_42 , V_97 [ V_93 ] ) ;
F_41 ( V_92 , L_20 ) ;
V_93 = ( V_5 & F_19 ( V_55 , 4 ) ) >> 12 ;
F_42 ( L_43 , V_97 [ V_93 ] ) ;
F_41 ( V_92 , L_20 ) ;
V_93 = ( V_5 & F_19 ( V_55 , 5 ) ) >> 16 ;
F_42 ( L_44 , V_97 [ V_93 ] ) ;
F_41 ( V_92 , L_20 ) ;
V_93 = ( V_5 & F_19 ( V_55 , 6 ) ) >> 20 ;
F_42 ( L_45 , V_97 [ V_93 ] ) ;
}
static int F_45 ( struct V_91 * V_92 , void * V_60 )
{
struct V_98 * V_99 = V_92 -> V_100 ;
struct V_1 * V_2 = (struct V_1 * ) V_99 -> V_101 -> V_60 ;
F_46 ( V_92 , L_46 , V_2 -> V_4 ) ;
F_47 ( L_2 , V_46 ) ;
F_40 ( V_92 , F_1 ( V_2 , V_46 ) ) ;
F_47 ( L_47 , V_102 ) ;
F_47 ( L_2 , V_11 ) ;
F_43 ( V_92 , F_1 ( V_2 , V_11 ) ) ;
F_47 ( L_47 , V_30 ) ;
F_41 ( V_92 , L_16 ) ;
F_48 ( L_48 , F_1 ( V_2 , V_30 ) ) ;
F_47 ( L_47 , V_31 ) ;
F_41 ( V_92 , L_16 ) ;
F_48 ( L_49 , F_1 ( V_2 , V_31 ) ) ;
F_47 ( L_47 , V_32 ) ;
F_41 ( V_92 , L_16 ) ;
F_48 ( L_50 , F_1 ( V_2 , V_32 ) ) ;
F_47 ( L_47 , V_33 ) ;
F_41 ( V_92 , L_16 ) ;
F_48 ( L_51 , F_1 ( V_2 , V_33 ) ) ;
F_47 ( L_47 , V_54 ) ;
F_44 ( V_92 , F_1 ( V_2 , V_54 ) ) ;
F_47 ( L_2 , V_103 ) ;
F_47 ( L_2 , V_104 ) ;
F_47 ( L_2 , V_105 ) ;
F_46 ( V_92 , L_52 ,
V_51 ) ;
F_49 ( F_16 , V_51 ) ;
F_49 ( F_17 , V_51 ) ;
F_49 ( V_106 , V_51 ) ;
F_49 ( V_107 , V_51 ) ;
F_49 ( V_108 , V_51 ) ;
F_49 ( V_109 , V_51 ) ;
F_49 ( V_110 , V_51 ) ;
F_49 ( V_111 , V_51 ) ;
F_41 ( V_92 , L_2 ) ;
F_46 ( V_92 , L_53 ,
V_52 ) ;
F_49 ( F_16 , V_52 ) ;
F_49 ( F_17 , V_52 ) ;
F_49 ( V_106 , V_52 ) ;
F_49 ( V_107 , V_52 ) ;
F_49 ( V_108 , V_52 ) ;
F_49 ( V_109 , V_52 ) ;
F_49 ( V_110 , V_52 ) ;
F_49 ( V_111 , V_52 ) ;
F_41 ( V_92 , L_2 ) ;
F_46 ( V_92 , L_54 ,
V_53 ) ;
F_49 ( F_16 , V_53 ) ;
F_49 ( F_17 , V_53 ) ;
F_49 ( V_106 , V_53 ) ;
F_49 ( V_107 , V_53 ) ;
F_49 ( V_108 , V_53 ) ;
F_49 ( V_109 , V_53 ) ;
F_49 ( V_110 , V_53 ) ;
F_49 ( V_111 , V_53 ) ;
F_41 ( V_92 , L_2 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_112 * V_113 )
{
unsigned int V_48 ;
for ( V_48 = 0 ; V_48 < F_51 ( V_114 ) ; V_48 ++ )
V_114 [ V_48 ] . V_60 = V_2 ;
return F_52 ( V_114 ,
F_51 ( V_114 ) ,
V_113 -> V_115 , V_113 ) ;
}
static void F_53 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_118 ;
T_1 V_5 = F_1 ( V_2 , V_46 ) ;
if ( ! V_2 -> V_83 )
return;
F_14 ( L_2 ) ;
V_5 &= ~ V_45 ;
F_3 ( V_2 , V_5 , V_46 ) ;
F_3 ( V_2 , 0xffffffff , V_21 ) ;
V_2 -> V_119 -> V_120 ( V_2 ) ;
F_15 ( V_2 , V_51 ) ;
F_15 ( V_2 , V_52 ) ;
F_15 ( V_2 , V_53 ) ;
F_3 ( V_2 , 0x0000 , V_121 ) ;
F_3 ( V_2 , 0x0000 , V_122 ) ;
F_3 ( V_2 , 0x0060 , V_123 ) ;
F_39 ( V_2 -> V_124 ) ;
F_39 ( V_2 -> V_125 ) ;
F_39 ( V_2 -> V_126 ) ;
V_2 -> V_83 = false ;
}
static int F_54 ( unsigned int V_127 )
{
unsigned int V_128 ;
switch ( V_127 ) {
case 32000 :
V_128 = 4096 ;
break;
case 44100 :
V_128 = 6272 ;
break;
case 48000 :
V_128 = 6144 ;
break;
case 88200 :
V_128 = 6272 * 2 ;
break;
case 96000 :
V_128 = 6144 * 2 ;
break;
case 176400 :
V_128 = 6272 * 4 ;
break;
case 192000 :
V_128 = 6144 * 4 ;
break;
default:
V_128 = ( V_127 * 128 ) / 1000 ;
}
return V_128 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_129 , V_128 ;
struct V_79 * V_130 = & V_2 -> V_80 ;
struct V_131 * V_132 = & V_130 -> V_84 ;
F_14 ( L_2 ) ;
if ( ! V_2 -> V_83 )
return 0 ;
V_128 = F_54 ( V_130 -> V_133 ) ;
F_14 ( L_55 ,
V_130 -> V_133 , V_2 -> V_27 . clock * 1000 , V_128 ) ;
F_3 ( V_2 , V_128 , V_105 ) ;
V_129 = V_134 | V_135 |
V_136 ;
switch ( V_132 -> V_137 ) {
case 8 :
V_129 |= V_138 ;
case 6 :
V_129 |= V_139 ;
case 4 :
V_129 |= V_140 | V_141 ;
case 2 :
V_129 |= V_142 ;
break;
default:
F_18 ( L_56 ,
V_132 -> V_137 ) ;
return - V_143 ;
}
F_3 ( V_2 , V_129 , V_103 ) ;
return F_30 ( V_2 ) ;
}
static void F_56 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_118 ;
F_14 ( L_2 ) ;
if ( V_2 -> V_83 )
return;
if ( F_36 ( V_2 -> V_126 ) )
F_18 ( L_57 ) ;
if ( F_36 ( V_2 -> V_125 ) )
F_18 ( L_58 ) ;
if ( F_36 ( V_2 -> V_124 ) )
F_18 ( L_59 ) ;
V_2 -> V_83 = true ;
if ( ! V_2 -> V_119 -> V_144 ( V_2 ) ) {
F_18 ( L_60 ) ;
return;
}
F_10 ( V_2 ) ;
F_3 ( V_2 , V_145 , V_102 ) ;
F_13 ( V_2 ) ;
if ( F_26 ( V_2 ) )
F_18 ( L_61 ) ;
if ( V_2 -> V_80 . V_83 ) {
if ( F_55 ( V_2 ) )
F_18 ( L_62 ) ;
} else {
F_30 ( V_2 ) ;
}
if ( F_32 ( V_2 ) )
F_18 ( L_63 ) ;
F_35 ( V_2 ) ;
}
static void F_57 ( struct V_116 * V_117 ,
struct V_68 * V_27 ,
struct V_68 * V_146 )
{
struct V_1 * V_2 = V_117 -> V_118 ;
int V_73 ;
F_14 ( L_2 ) ;
memcpy ( & V_2 -> V_27 , V_27 , sizeof( struct V_68 ) ) ;
V_73 = F_58 ( V_2 -> V_126 , V_27 -> clock * 1000 ) ;
if ( V_73 < 0 ) {
F_18 ( L_64 ,
V_27 -> clock * 1000 ) ;
return;
}
V_73 = F_58 ( V_2 -> V_124 , V_27 -> clock * 1000 ) ;
if ( V_73 < 0 ) {
F_18 ( L_65 ,
V_27 -> clock * 1000 ) ;
return;
}
}
static void F_59 ( struct V_116 * V_117 )
{
}
static int F_60 ( struct V_147 * V_148 )
{
struct V_149 * V_150
= F_61 ( V_148 ) ;
struct V_1 * V_2 = V_150 -> V_2 ;
struct V_151 * V_151 ;
int V_152 ;
F_14 ( L_2 ) ;
V_151 = F_62 ( V_148 , V_2 -> V_153 ) ;
if ( ! V_151 )
goto V_154;
V_2 -> V_38 = F_63 ( V_151 ) ;
F_64 ( L_66 ,
( V_2 -> V_38 ? L_67 : L_68 ) ,
V_151 -> V_155 , V_151 -> V_156 ) ;
V_152 = F_65 ( V_148 , V_151 ) ;
F_66 ( V_148 , V_151 ) ;
F_67 ( V_148 , V_151 ) ;
F_68 ( V_151 ) ;
return V_152 ;
V_154:
F_18 ( L_69 ) ;
return 0 ;
}
static int F_69 ( struct V_147 * V_148 ,
struct V_68 * V_27 )
{
int V_157 = V_27 -> clock * 1000 ;
int V_158 = V_157 - V_159 ;
int V_160 = V_157 + V_159 ;
int V_161 ;
struct V_149 * V_150
= F_61 ( V_148 ) ;
struct V_1 * V_2 = V_150 -> V_2 ;
V_161 = F_70 ( V_2 -> V_126 , V_157 ) ;
F_14 ( L_70 ,
V_157 , V_161 ) ;
if ( ( V_161 < V_158 ) || ( V_161 > V_160 ) ) {
F_14 ( L_71 , V_157 ) ;
return V_162 ;
}
return V_163 ;
}
static enum V_164
F_71 ( struct V_147 * V_148 , bool V_165 )
{
struct V_149 * V_150
= F_61 ( V_148 ) ;
struct V_1 * V_2 = V_150 -> V_2 ;
F_14 ( L_2 ) ;
if ( V_2 -> V_10 ) {
F_14 ( L_72 ) ;
return V_166 ;
}
F_14 ( L_73 ) ;
return V_167 ;
}
static void F_72 ( struct V_168 * V_13 ,
struct V_147 * V_148 )
{
struct V_149 * V_150
= F_61 ( V_148 ) ;
struct V_1 * V_2 = V_150 -> V_2 ;
struct V_169 * V_170 ;
V_2 -> V_74 = V_171 ;
V_170 = F_73 ( V_13 , 0 , L_74 ,
V_172 ,
F_51 ( V_172 ) ) ;
if ( ! V_170 ) {
F_18 ( L_75 ) ;
return;
}
V_150 -> V_173 = V_170 ;
F_74 ( & V_148 -> V_174 , V_170 , V_2 -> V_74 ) ;
}
static int
F_75 ( struct V_147 * V_148 ,
struct V_175 * V_176 ,
struct V_169 * V_177 ,
T_5 V_5 )
{
struct V_149 * V_150
= F_61 ( V_148 ) ;
struct V_1 * V_2 = V_150 -> V_2 ;
if ( V_177 == V_150 -> V_173 ) {
V_2 -> V_74 = V_5 ;
return 0 ;
}
F_18 ( L_76 ) ;
return - V_143 ;
}
static int
F_76 ( struct V_147 * V_148 ,
const struct V_175 * V_176 ,
struct V_169 * V_177 ,
T_5 * V_5 )
{
struct V_149 * V_150
= F_61 ( V_148 ) ;
struct V_1 * V_2 = V_150 -> V_2 ;
if ( V_177 == V_150 -> V_173 ) {
* V_5 = V_2 -> V_74 ;
return 0 ;
}
F_18 ( L_77 ) ;
return - V_143 ;
}
static int F_77 ( struct V_147 * V_148 )
{
struct V_149 * V_150
= F_61 ( V_148 ) ;
struct V_1 * V_2 = V_150 -> V_2 ;
if ( F_50 ( V_2 , V_2 -> V_13 -> V_178 ) ) {
F_18 ( L_78 ) ;
return - V_143 ;
}
return 0 ;
}
static struct V_179 * F_78 ( struct V_168 * V_180 )
{
struct V_179 * V_181 ;
F_79 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_181 -> V_182 == V_183 )
return V_181 ;
}
return NULL ;
}
static void F_80 ( struct V_184 * V_180 , void * V_60 )
{
struct V_1 * V_2 = F_81 ( V_180 ) ;
int V_129 ;
F_14 ( L_2 ) ;
V_129 = V_134 | V_135 |
V_136 ;
F_3 ( V_2 , V_129 , V_103 ) ;
V_2 -> V_80 . V_83 = false ;
F_30 ( V_2 ) ;
}
static int F_82 ( struct V_184 * V_180 ,
void * V_60 ,
struct V_185 * V_186 ,
struct V_187 * V_130 )
{
struct V_1 * V_2 = F_81 ( V_180 ) ;
int V_73 ;
F_14 ( L_2 ) ;
if ( ( V_186 -> V_188 != V_189 ) || V_186 -> V_190 ||
V_186 -> V_191 || V_186 -> V_192 ||
V_186 -> V_193 ) {
F_83 ( V_180 , L_79 , V_82 ,
V_186 -> V_190 , V_186 -> V_191 ,
V_186 -> V_192 ,
V_186 -> V_193 ) ;
return - V_143 ;
}
V_2 -> V_80 . V_194 = V_130 -> V_194 ;
V_2 -> V_80 . V_133 = V_130 -> V_133 ;
V_2 -> V_80 . V_84 = V_130 -> V_84 ;
V_2 -> V_80 . V_83 = true ;
V_73 = F_55 ( V_2 ) ;
if ( V_73 < 0 )
return V_73 ;
return 0 ;
}
static int F_84 ( struct V_184 * V_180 , void * V_60 , bool V_195 )
{
struct V_1 * V_2 = F_81 ( V_180 ) ;
F_14 ( L_80 , V_195 ? L_10 : L_11 ) ;
if ( V_195 )
F_3 ( V_2 , V_196 , V_197 ) ;
else
F_3 ( V_2 , V_198 , V_197 ) ;
return 0 ;
}
static int F_85 ( struct V_184 * V_180 , void * V_60 , T_6 * V_199 , T_4 V_200 )
{
struct V_1 * V_2 = F_81 ( V_180 ) ;
struct V_147 * V_148 = V_2 -> V_147 ;
F_14 ( L_2 ) ;
memcpy ( V_199 , V_148 -> V_201 , F_86 ( sizeof( V_148 -> V_201 ) , V_200 ) ) ;
return 0 ;
}
static int F_87 ( struct V_184 * V_180 ,
struct V_1 * V_2 )
{
struct V_202 V_203 = {
. V_204 = & V_205 ,
. V_206 = 8 ,
. V_207 = 1 ,
} ;
F_14 ( L_2 ) ;
V_2 -> V_80 . V_83 = false ;
V_2 -> V_208 = F_88 (
V_180 , V_209 , V_210 ,
& V_203 , sizeof( V_203 ) ) ;
if ( F_89 ( V_2 -> V_208 ) )
return F_90 ( V_2 -> V_208 ) ;
F_8 ( L_81 , V_209 , F_91 ( V_180 ) ) ;
return 0 ;
}
static int F_92 ( struct V_184 * V_180 , struct V_184 * V_211 , void * V_60 )
{
struct V_1 * V_2 = F_81 ( V_180 ) ;
struct V_168 * V_13 = V_60 ;
struct V_179 * V_181 ;
struct V_149 * V_148 ;
struct V_147 * V_147 ;
struct V_116 * V_117 ;
int V_212 ;
V_2 -> V_13 = V_13 ;
V_181 = F_78 ( V_13 ) ;
if ( ! V_181 )
return - V_143 ;
V_148 = F_93 ( V_180 , sizeof( * V_148 ) , V_213 ) ;
if ( ! V_148 )
return - V_143 ;
V_148 -> V_2 = V_2 ;
V_117 = F_93 ( V_180 , sizeof( * V_117 ) , V_213 ) ;
if ( ! V_117 )
return - V_143 ;
V_117 -> V_118 = V_2 ;
V_117 -> V_214 = & V_215 ;
F_94 ( V_181 , V_117 , NULL ) ;
V_148 -> V_181 = V_181 ;
V_147 = (struct V_147 * ) V_148 ;
V_147 -> V_216 = V_217 ;
F_95 ( V_13 , V_147 ,
& V_218 , V_219 ) ;
F_96 ( V_147 ,
& V_220 ) ;
F_72 ( V_13 , V_147 ) ;
V_2 -> V_147 = V_147 ;
V_212 = F_97 ( V_147 , V_181 ) ;
if ( V_212 ) {
F_18 ( L_82 ) ;
goto V_221;
}
V_212 = F_87 ( V_180 , V_2 ) ;
if ( V_212 ) {
F_18 ( L_83 ) ;
goto V_221;
}
V_212 = F_98 ( & V_2 -> V_80 . V_84 ) ;
if ( V_212 ) {
F_18 ( L_84 ) ;
goto V_221;
}
F_3 ( V_2 , V_222 , V_102 ) ;
return 0 ;
V_221:
F_99 ( V_117 ) ;
V_2 -> V_147 = NULL ;
return - V_143 ;
}
static void F_100 ( struct V_184 * V_180 ,
struct V_184 * V_211 , void * V_60 )
{
}
static int F_101 ( struct V_223 * V_224 )
{
struct V_184 * V_180 = & V_224 -> V_180 ;
struct V_1 * V_2 ;
struct V_225 * V_226 = V_180 -> V_227 ;
struct V_228 * V_229 ;
struct V_225 * V_230 ;
int V_73 ;
F_8 ( L_80 , V_82 ) ;
V_2 = F_93 ( V_180 , sizeof( * V_2 ) , V_213 ) ;
if ( ! V_2 )
return - V_231 ;
V_230 = F_102 ( V_224 -> V_180 . V_227 , L_85 , 0 ) ;
if ( V_230 ) {
V_2 -> V_153 = F_103 ( V_230 ) ;
F_104 ( V_230 ) ;
if ( ! V_2 -> V_153 )
return - V_232 ;
}
V_2 -> V_180 = V_224 -> V_180 ;
V_229 = F_105 ( V_224 , V_233 , L_86 ) ;
if ( ! V_229 ) {
F_18 ( L_87 ) ;
V_73 = - V_231 ;
goto V_234;
}
V_2 -> V_4 = F_106 ( V_180 , V_229 -> V_144 , F_107 ( V_229 ) ) ;
if ( ! V_2 -> V_4 ) {
V_73 = - V_231 ;
goto V_234;
}
V_2 -> V_119 = (struct V_235 * )
F_108 ( V_236 , V_226 ) -> V_60 ;
V_2 -> V_126 = F_109 ( V_180 , L_88 ) ;
if ( F_89 ( V_2 -> V_126 ) ) {
F_18 ( L_89 ) ;
V_73 = F_90 ( V_2 -> V_126 ) ;
goto V_234;
}
V_2 -> V_125 = F_109 ( V_180 , L_90 ) ;
if ( F_89 ( V_2 -> V_125 ) ) {
F_18 ( L_91 ) ;
V_73 = F_90 ( V_2 -> V_125 ) ;
goto V_234;
}
V_2 -> V_124 = F_109 ( V_180 , L_92 ) ;
if ( F_89 ( V_2 -> V_124 ) ) {
F_18 ( L_93 ) ;
V_73 = F_90 ( V_2 -> V_124 ) ;
goto V_234;
}
V_2 -> V_87 = F_109 ( V_180 , L_94 ) ;
if ( F_89 ( V_2 -> V_87 ) ) {
F_18 ( L_95 ) ;
V_73 = F_90 ( V_2 -> V_87 ) ;
goto V_234;
}
V_2 -> V_10 = F_2 ( V_2 -> V_4 + V_11 ) & V_12 ;
F_110 ( & V_2 -> V_17 ) ;
V_2 -> V_6 = F_111 ( V_224 , L_96 ) ;
V_73 = F_112 ( V_180 , V_2 -> V_6 , F_9 ,
F_5 , V_237 , F_91 ( V_180 ) , V_2 ) ;
if ( V_73 ) {
F_18 ( L_97 ) ;
goto V_234;
}
V_2 -> V_238 = F_113 ( V_180 , L_98 ) ;
if ( ! F_89 ( V_2 -> V_238 ) )
F_114 ( V_2 -> V_238 ) ;
F_115 ( V_224 , V_2 ) ;
return F_116 ( & V_224 -> V_180 , & V_239 ) ;
V_234:
F_117 ( V_2 -> V_153 ) ;
return V_73 ;
}
static int F_118 ( struct V_223 * V_224 )
{
struct V_1 * V_2 = F_81 ( & V_224 -> V_180 ) ;
F_117 ( V_2 -> V_153 ) ;
if ( V_2 -> V_208 )
F_119 ( V_2 -> V_208 ) ;
F_120 ( & V_224 -> V_180 , & V_239 ) ;
return 0 ;
}
