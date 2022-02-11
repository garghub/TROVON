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
F_41 ( V_92 , '\t' ) ;
V_93 = V_5 & V_39 ;
F_42 ( L_16 , V_93 ? L_17 : L_18 ) ;
F_43 ( V_92 , L_19 ) ;
V_93 = V_5 & V_94 ;
F_42 ( L_20 , V_93 ? L_10 : L_11 ) ;
F_43 ( V_92 , L_19 ) ;
V_93 = V_5 & V_37 ;
F_42 ( L_21 , V_93 ? L_22 : L_23 ) ;
F_43 ( V_92 , L_19 ) ;
V_93 = V_5 & V_42 ;
F_42 ( L_24 , V_93 ? L_25 : L_26 ) ;
F_43 ( V_92 , L_19 ) ;
V_93 = V_5 & V_44 ;
F_42 ( L_27 , V_93 ? L_25 : L_26 ) ;
F_43 ( V_92 , L_19 ) ;
V_93 = V_5 & V_95 ;
F_42 ( L_28 , V_93 ? L_10 : L_11 ) ;
}
static void F_44 ( struct V_91 * V_92 , int V_5 )
{
int V_93 ;
F_41 ( V_92 , '\t' ) ;
V_93 = ( V_5 & V_96 ) ;
F_42 ( L_29 , V_93 ? L_30 : L_31 ) ;
F_43 ( V_92 , L_19 ) ;
V_93 = ( V_5 & V_12 ) ;
F_42 ( L_32 , V_93 ? L_33 : L_34 ) ;
}
static void F_45 ( struct V_91 * V_92 , int V_5 )
{
int V_93 ;
char * const V_97 [] = { L_35 ,
L_36 ,
L_37 ,
L_38 } ;
F_41 ( V_92 , '\t' ) ;
V_93 = ( V_5 & F_19 ( V_55 , 1 ) ) ;
F_42 ( L_39 , V_97 [ V_93 ] ) ;
F_43 ( V_92 , L_19 ) ;
V_93 = ( V_5 & F_19 ( V_55 , 2 ) ) >> 4 ;
F_42 ( L_40 , V_97 [ V_93 ] ) ;
F_43 ( V_92 , L_19 ) ;
V_93 = ( V_5 & F_19 ( V_55 , 3 ) ) >> 8 ;
F_42 ( L_41 , V_97 [ V_93 ] ) ;
F_43 ( V_92 , L_19 ) ;
V_93 = ( V_5 & F_19 ( V_55 , 4 ) ) >> 12 ;
F_42 ( L_42 , V_97 [ V_93 ] ) ;
F_43 ( V_92 , L_19 ) ;
V_93 = ( V_5 & F_19 ( V_55 , 5 ) ) >> 16 ;
F_42 ( L_43 , V_97 [ V_93 ] ) ;
F_43 ( V_92 , L_19 ) ;
V_93 = ( V_5 & F_19 ( V_55 , 6 ) ) >> 20 ;
F_42 ( L_44 , V_97 [ V_93 ] ) ;
}
static int F_46 ( struct V_91 * V_92 , void * V_60 )
{
struct V_98 * V_99 = V_92 -> V_100 ;
struct V_1 * V_2 = (struct V_1 * ) V_99 -> V_101 -> V_60 ;
F_47 ( V_92 , L_45 , V_2 -> V_4 ) ;
F_48 ( L_2 , V_46 ) ;
F_40 ( V_92 , F_1 ( V_2 , V_46 ) ) ;
F_48 ( L_46 , V_102 ) ;
F_48 ( L_2 , V_11 ) ;
F_44 ( V_92 , F_1 ( V_2 , V_11 ) ) ;
F_48 ( L_46 , V_30 ) ;
F_41 ( V_92 , '\t' ) ;
F_49 ( L_47 , F_1 ( V_2 , V_30 ) ) ;
F_48 ( L_46 , V_31 ) ;
F_41 ( V_92 , '\t' ) ;
F_49 ( L_48 , F_1 ( V_2 , V_31 ) ) ;
F_48 ( L_46 , V_32 ) ;
F_41 ( V_92 , '\t' ) ;
F_49 ( L_49 , F_1 ( V_2 , V_32 ) ) ;
F_48 ( L_46 , V_33 ) ;
F_41 ( V_92 , '\t' ) ;
F_49 ( L_50 , F_1 ( V_2 , V_33 ) ) ;
F_48 ( L_46 , V_54 ) ;
F_45 ( V_92 , F_1 ( V_2 , V_54 ) ) ;
F_48 ( L_2 , V_103 ) ;
F_48 ( L_2 , V_104 ) ;
F_48 ( L_2 , V_105 ) ;
F_47 ( V_92 , L_51 ,
V_51 ) ;
F_50 ( F_16 , V_51 ) ;
F_50 ( F_17 , V_51 ) ;
F_50 ( V_106 , V_51 ) ;
F_50 ( V_107 , V_51 ) ;
F_50 ( V_108 , V_51 ) ;
F_50 ( V_109 , V_51 ) ;
F_50 ( V_110 , V_51 ) ;
F_50 ( V_111 , V_51 ) ;
F_47 ( V_92 , L_52 ,
V_52 ) ;
F_50 ( F_16 , V_52 ) ;
F_50 ( F_17 , V_52 ) ;
F_50 ( V_106 , V_52 ) ;
F_50 ( V_107 , V_52 ) ;
F_50 ( V_108 , V_52 ) ;
F_50 ( V_109 , V_52 ) ;
F_50 ( V_110 , V_52 ) ;
F_50 ( V_111 , V_52 ) ;
F_47 ( V_92 , L_53 ,
V_53 ) ;
F_50 ( F_16 , V_53 ) ;
F_50 ( F_17 , V_53 ) ;
F_50 ( V_106 , V_53 ) ;
F_50 ( V_107 , V_53 ) ;
F_50 ( V_108 , V_53 ) ;
F_50 ( V_109 , V_53 ) ;
F_50 ( V_110 , V_53 ) ;
F_50 ( V_111 , V_53 ) ;
F_41 ( V_92 , '\n' ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_112 * V_113 )
{
unsigned int V_48 ;
for ( V_48 = 0 ; V_48 < F_52 ( V_114 ) ; V_48 ++ )
V_114 [ V_48 ] . V_60 = V_2 ;
return F_53 ( V_114 ,
F_52 ( V_114 ) ,
V_113 -> V_115 , V_113 ) ;
}
static void F_54 ( struct V_116 * V_117 )
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
F_55 ( V_2 -> V_127 , V_128 ) ;
}
static int F_56 ( unsigned int V_129 )
{
unsigned int V_130 ;
switch ( V_129 ) {
case 32000 :
V_130 = 4096 ;
break;
case 44100 :
V_130 = 6272 ;
break;
case 48000 :
V_130 = 6144 ;
break;
case 88200 :
V_130 = 6272 * 2 ;
break;
case 96000 :
V_130 = 6144 * 2 ;
break;
case 176400 :
V_130 = 6272 * 4 ;
break;
case 192000 :
V_130 = 6144 * 4 ;
break;
default:
V_130 = ( V_129 * 128 ) / 1000 ;
}
return V_130 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_131 , V_130 ;
struct V_79 * V_132 = & V_2 -> V_80 ;
struct V_133 * V_134 = & V_132 -> V_84 ;
F_14 ( L_2 ) ;
if ( ! V_2 -> V_83 )
return 0 ;
V_130 = F_56 ( V_132 -> V_135 ) ;
F_14 ( L_54 ,
V_132 -> V_135 , V_2 -> V_27 . clock * 1000 , V_130 ) ;
F_3 ( V_2 , V_130 , V_105 ) ;
V_131 = V_136 | V_137 |
V_138 ;
switch ( V_134 -> V_139 ) {
case 8 :
V_131 |= V_140 ;
case 6 :
V_131 |= V_141 ;
case 4 :
V_131 |= V_142 | V_143 ;
case 2 :
V_131 |= V_144 ;
break;
default:
F_18 ( L_55 ,
V_134 -> V_139 ) ;
return - V_145 ;
}
F_3 ( V_2 , V_131 , V_103 ) ;
return F_30 ( V_2 ) ;
}
static void F_58 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_118 ;
F_14 ( L_2 ) ;
if ( V_2 -> V_83 )
return;
if ( F_36 ( V_2 -> V_126 ) )
F_18 ( L_56 ) ;
if ( F_36 ( V_2 -> V_125 ) )
F_18 ( L_57 ) ;
if ( F_36 ( V_2 -> V_124 ) )
F_18 ( L_58 ) ;
V_2 -> V_83 = true ;
if ( ! V_2 -> V_119 -> V_146 ( V_2 ) ) {
F_18 ( L_59 ) ;
return;
}
F_10 ( V_2 ) ;
F_3 ( V_2 , V_147 , V_102 ) ;
F_13 ( V_2 ) ;
if ( F_26 ( V_2 ) )
F_18 ( L_60 ) ;
if ( V_2 -> V_80 . V_83 ) {
if ( F_57 ( V_2 ) )
F_18 ( L_61 ) ;
} else {
F_30 ( V_2 ) ;
}
if ( F_32 ( V_2 ) )
F_18 ( L_62 ) ;
F_35 ( V_2 ) ;
}
static void F_59 ( struct V_116 * V_117 ,
struct V_68 * V_27 ,
struct V_68 * V_148 )
{
struct V_1 * V_2 = V_117 -> V_118 ;
int V_73 ;
F_14 ( L_2 ) ;
memcpy ( & V_2 -> V_27 , V_27 , sizeof( struct V_68 ) ) ;
V_73 = F_60 ( V_2 -> V_126 , V_27 -> clock * 1000 ) ;
if ( V_73 < 0 ) {
F_18 ( L_63 ,
V_27 -> clock * 1000 ) ;
return;
}
V_73 = F_60 ( V_2 -> V_124 , V_27 -> clock * 1000 ) ;
if ( V_73 < 0 ) {
F_18 ( L_64 ,
V_27 -> clock * 1000 ) ;
return;
}
}
static void F_61 ( struct V_116 * V_117 )
{
}
static int F_62 ( struct V_149 * V_150 )
{
struct V_151 * V_152
= F_63 ( V_150 ) ;
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_153 * V_153 ;
int V_154 ;
F_14 ( L_2 ) ;
V_153 = F_64 ( V_150 , V_2 -> V_155 ) ;
if ( ! V_153 )
goto V_156;
V_2 -> V_38 = F_65 ( V_153 ) ;
F_66 ( L_65 ,
( V_2 -> V_38 ? L_66 : L_67 ) ,
V_153 -> V_157 , V_153 -> V_158 ) ;
F_67 ( V_2 -> V_127 , V_153 ) ;
V_154 = F_68 ( V_150 , V_153 ) ;
F_69 ( V_150 , V_153 ) ;
F_70 ( V_150 , V_153 ) ;
F_71 ( V_153 ) ;
return V_154 ;
V_156:
F_18 ( L_68 ) ;
return 0 ;
}
static int F_72 ( struct V_149 * V_150 ,
struct V_68 * V_27 )
{
int V_159 = V_27 -> clock * 1000 ;
int V_160 = V_159 - V_161 ;
int V_162 = V_159 + V_161 ;
int V_163 ;
struct V_151 * V_152
= F_63 ( V_150 ) ;
struct V_1 * V_2 = V_152 -> V_2 ;
V_163 = F_73 ( V_2 -> V_126 , V_159 ) ;
F_14 ( L_69 ,
V_159 , V_163 ) ;
if ( ( V_163 < V_160 ) || ( V_163 > V_162 ) ) {
F_14 ( L_70 , V_159 ) ;
return V_164 ;
}
return V_165 ;
}
static enum V_166
F_74 ( struct V_149 * V_150 , bool V_167 )
{
struct V_151 * V_152
= F_63 ( V_150 ) ;
struct V_1 * V_2 = V_152 -> V_2 ;
F_14 ( L_2 ) ;
if ( V_2 -> V_10 ) {
F_14 ( L_71 ) ;
return V_168 ;
}
F_14 ( L_72 ) ;
F_55 ( V_2 -> V_127 , V_128 ) ;
return V_169 ;
}
static void F_75 ( struct V_170 * V_13 ,
struct V_149 * V_150 )
{
struct V_151 * V_152
= F_63 ( V_150 ) ;
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_171 * V_172 ;
V_2 -> V_74 = V_173 ;
V_172 = F_76 ( V_13 , 0 , L_73 ,
V_174 ,
F_52 ( V_174 ) ) ;
if ( ! V_172 ) {
F_18 ( L_74 ) ;
return;
}
V_152 -> V_175 = V_172 ;
F_77 ( & V_150 -> V_176 , V_172 , V_2 -> V_74 ) ;
}
static int
F_78 ( struct V_149 * V_150 ,
struct V_177 * V_178 ,
struct V_171 * V_179 ,
T_5 V_5 )
{
struct V_151 * V_152
= F_63 ( V_150 ) ;
struct V_1 * V_2 = V_152 -> V_2 ;
if ( V_179 == V_152 -> V_175 ) {
V_2 -> V_74 = V_5 ;
return 0 ;
}
F_18 ( L_75 ) ;
return - V_145 ;
}
static int
F_79 ( struct V_149 * V_150 ,
const struct V_177 * V_178 ,
struct V_171 * V_179 ,
T_5 * V_5 )
{
struct V_151 * V_152
= F_63 ( V_150 ) ;
struct V_1 * V_2 = V_152 -> V_2 ;
if ( V_179 == V_152 -> V_175 ) {
* V_5 = V_2 -> V_74 ;
return 0 ;
}
F_18 ( L_76 ) ;
return - V_145 ;
}
static int F_80 ( struct V_149 * V_150 )
{
struct V_151 * V_152
= F_63 ( V_150 ) ;
struct V_1 * V_2 = V_152 -> V_2 ;
if ( F_51 ( V_2 , V_2 -> V_13 -> V_180 ) ) {
F_18 ( L_77 ) ;
return - V_145 ;
}
return 0 ;
}
static struct V_181 * F_81 ( struct V_170 * V_182 )
{
struct V_181 * V_183 ;
F_82 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_183 -> V_184 == V_185 )
return V_183 ;
}
return NULL ;
}
static void F_83 ( struct V_186 * V_182 , void * V_60 )
{
struct V_1 * V_2 = F_84 ( V_182 ) ;
int V_131 ;
F_14 ( L_2 ) ;
V_131 = V_136 | V_137 |
V_138 ;
F_3 ( V_2 , V_131 , V_103 ) ;
V_2 -> V_80 . V_83 = false ;
F_30 ( V_2 ) ;
}
static int F_85 ( struct V_186 * V_182 ,
void * V_60 ,
struct V_187 * V_188 ,
struct V_189 * V_132 )
{
struct V_1 * V_2 = F_84 ( V_182 ) ;
int V_73 ;
F_14 ( L_2 ) ;
if ( ( V_188 -> V_190 != V_191 ) || V_188 -> V_192 ||
V_188 -> V_193 || V_188 -> V_194 ||
V_188 -> V_195 ) {
F_86 ( V_182 , L_78 , V_82 ,
V_188 -> V_192 , V_188 -> V_193 ,
V_188 -> V_194 ,
V_188 -> V_195 ) ;
return - V_145 ;
}
V_2 -> V_80 . V_196 = V_132 -> V_196 ;
V_2 -> V_80 . V_135 = V_132 -> V_135 ;
V_2 -> V_80 . V_84 = V_132 -> V_84 ;
V_2 -> V_80 . V_83 = true ;
V_73 = F_57 ( V_2 ) ;
if ( V_73 < 0 )
return V_73 ;
return 0 ;
}
static int F_87 ( struct V_186 * V_182 , void * V_60 , bool V_197 )
{
struct V_1 * V_2 = F_84 ( V_182 ) ;
F_14 ( L_79 , V_197 ? L_10 : L_11 ) ;
if ( V_197 )
F_3 ( V_2 , V_198 , V_199 ) ;
else
F_3 ( V_2 , V_200 , V_199 ) ;
return 0 ;
}
static int F_88 ( struct V_186 * V_182 , void * V_60 , T_6 * V_201 , T_4 V_202 )
{
struct V_1 * V_2 = F_84 ( V_182 ) ;
struct V_149 * V_150 = V_2 -> V_149 ;
F_14 ( L_2 ) ;
memcpy ( V_201 , V_150 -> V_203 , F_89 ( sizeof( V_150 -> V_203 ) , V_202 ) ) ;
return 0 ;
}
static int F_90 ( struct V_186 * V_182 ,
struct V_1 * V_2 )
{
struct V_204 V_205 = {
. V_206 = & V_207 ,
. V_208 = 8 ,
. V_209 = 1 ,
} ;
F_14 ( L_2 ) ;
V_2 -> V_80 . V_83 = false ;
V_2 -> V_210 = F_91 (
V_182 , V_211 , V_212 ,
& V_205 , sizeof( V_205 ) ) ;
if ( F_92 ( V_2 -> V_210 ) )
return F_93 ( V_2 -> V_210 ) ;
F_8 ( L_80 , V_211 , F_94 ( V_182 ) ) ;
return 0 ;
}
static int F_95 ( struct V_186 * V_182 , struct V_186 * V_213 , void * V_60 )
{
struct V_1 * V_2 = F_84 ( V_182 ) ;
struct V_170 * V_13 = V_60 ;
struct V_181 * V_183 ;
struct V_151 * V_150 ;
struct V_149 * V_149 ;
struct V_116 * V_117 ;
int V_214 ;
V_2 -> V_13 = V_13 ;
V_183 = F_81 ( V_13 ) ;
if ( ! V_183 )
return - V_145 ;
V_150 = F_96 ( V_182 , sizeof( * V_150 ) , V_215 ) ;
if ( ! V_150 )
return - V_145 ;
V_150 -> V_2 = V_2 ;
V_117 = F_96 ( V_182 , sizeof( * V_117 ) , V_215 ) ;
if ( ! V_117 )
return - V_145 ;
V_117 -> V_118 = V_2 ;
V_117 -> V_216 = & V_217 ;
F_97 ( V_183 , V_117 , NULL ) ;
V_150 -> V_183 = V_183 ;
V_149 = (struct V_149 * ) V_150 ;
V_149 -> V_218 = V_219 ;
F_98 ( V_13 , V_149 ,
& V_220 , V_221 ) ;
F_99 ( V_149 ,
& V_222 ) ;
F_75 ( V_13 , V_149 ) ;
V_2 -> V_149 = V_149 ;
V_214 = F_100 ( V_149 , V_183 ) ;
if ( V_214 ) {
F_18 ( L_81 ) ;
goto V_223;
}
V_214 = F_90 ( V_182 , V_2 ) ;
if ( V_214 ) {
F_18 ( L_82 ) ;
goto V_223;
}
V_214 = F_101 ( & V_2 -> V_80 . V_84 ) ;
if ( V_214 ) {
F_18 ( L_83 ) ;
goto V_223;
}
F_3 ( V_2 , V_224 , V_102 ) ;
return 0 ;
V_223:
F_102 ( V_117 ) ;
V_2 -> V_149 = NULL ;
return - V_145 ;
}
static void F_103 ( struct V_186 * V_182 ,
struct V_186 * V_213 , void * V_60 )
{
}
static int F_104 ( struct V_225 * V_226 )
{
struct V_186 * V_182 = & V_226 -> V_182 ;
struct V_1 * V_2 ;
struct V_227 * V_228 = V_182 -> V_229 ;
struct V_230 * V_231 ;
struct V_227 * V_232 ;
int V_73 ;
F_8 ( L_79 , V_82 ) ;
V_2 = F_96 ( V_182 , sizeof( * V_2 ) , V_215 ) ;
if ( ! V_2 )
return - V_233 ;
V_232 = F_105 ( V_226 -> V_182 . V_229 , L_84 , 0 ) ;
if ( V_232 ) {
V_2 -> V_155 = F_106 ( V_232 ) ;
F_107 ( V_232 ) ;
if ( ! V_2 -> V_155 )
return - V_234 ;
}
V_2 -> V_182 = V_226 -> V_182 ;
V_231 = F_108 ( V_226 , V_235 , L_85 ) ;
if ( ! V_231 ) {
F_18 ( L_86 ) ;
V_73 = - V_233 ;
goto V_236;
}
V_2 -> V_4 = F_109 ( V_182 , V_231 -> V_146 , F_110 ( V_231 ) ) ;
if ( ! V_2 -> V_4 ) {
V_73 = - V_233 ;
goto V_236;
}
V_2 -> V_119 = (struct V_237 * )
F_111 ( V_238 , V_228 ) -> V_60 ;
V_2 -> V_126 = F_112 ( V_182 , L_87 ) ;
if ( F_92 ( V_2 -> V_126 ) ) {
F_18 ( L_88 ) ;
V_73 = F_93 ( V_2 -> V_126 ) ;
goto V_236;
}
V_2 -> V_125 = F_112 ( V_182 , L_89 ) ;
if ( F_92 ( V_2 -> V_125 ) ) {
F_18 ( L_90 ) ;
V_73 = F_93 ( V_2 -> V_125 ) ;
goto V_236;
}
V_2 -> V_124 = F_112 ( V_182 , L_91 ) ;
if ( F_92 ( V_2 -> V_124 ) ) {
F_18 ( L_92 ) ;
V_73 = F_93 ( V_2 -> V_124 ) ;
goto V_236;
}
V_2 -> V_87 = F_112 ( V_182 , L_93 ) ;
if ( F_92 ( V_2 -> V_87 ) ) {
F_18 ( L_94 ) ;
V_73 = F_93 ( V_2 -> V_87 ) ;
goto V_236;
}
V_2 -> V_10 = F_2 ( V_2 -> V_4 + V_11 ) & V_12 ;
F_113 ( & V_2 -> V_17 ) ;
V_2 -> V_6 = F_114 ( V_226 , L_95 ) ;
V_73 = F_115 ( V_182 , V_2 -> V_6 , F_9 ,
F_5 , V_239 , F_94 ( V_182 ) , V_2 ) ;
if ( V_73 ) {
F_18 ( L_96 ) ;
goto V_236;
}
V_2 -> V_127 = F_116 ( & V_226 -> V_182 ) ;
if ( ! V_2 -> V_127 )
goto V_236;
V_2 -> V_240 = F_117 ( V_182 , L_97 ) ;
if ( ! F_92 ( V_2 -> V_240 ) )
F_118 ( V_2 -> V_240 ) ;
F_119 ( V_226 , V_2 ) ;
return F_120 ( & V_226 -> V_182 , & V_241 ) ;
V_236:
F_121 ( V_2 -> V_155 ) ;
return V_73 ;
}
static int F_122 ( struct V_225 * V_226 )
{
struct V_1 * V_2 = F_84 ( & V_226 -> V_182 ) ;
F_55 ( V_2 -> V_127 , V_128 ) ;
F_121 ( V_2 -> V_155 ) ;
if ( V_2 -> V_210 )
F_123 ( V_2 -> V_210 ) ;
F_124 ( & V_226 -> V_182 , & V_241 ) ;
F_125 ( V_2 -> V_127 ) ;
return 0 ;
}
