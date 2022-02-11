static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 =
F_2 ( V_2 , struct V_4 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_3 ( & V_7 -> V_9 . V_10 ) ;
F_4 ( V_3 ) ;
F_5 ( & V_7 -> V_9 . V_10 ) ;
}
static void F_6 ( struct V_11 * V_12 , int V_13 )
{
static const T_1 V_14 [] = {
V_15 ,
V_16 ,
} ;
static const T_1 V_17 [] = {
V_18 ,
V_19 ,
} ;
static const T_1 V_20 [] = {
V_21 , V_22 ,
} ;
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
F_8 ( V_7 -> V_7 ) ;
F_9 ( V_7 , V_14 [ V_13 ] , V_4 -> V_26 ) ;
F_9 ( V_7 , V_17 [ V_13 ] , V_4 -> V_27 ) ;
if ( V_4 -> V_28 [ V_13 ] ) {
F_10 ( & V_4 -> V_5 , V_4 -> V_28 [ V_13 ] ) ;
F_11 ( & V_4 -> V_5 , V_24 -> V_29 ) ;
}
V_4 -> V_28 [ V_13 ] = V_12 -> V_30 -> V_31 ;
F_12 ( V_4 -> V_28 [ V_13 ] ) ;
V_4 -> V_32 &= ~ V_20 [ V_13 ] ;
F_13 ( V_7 -> V_7 ) ;
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_33 * V_31 = V_12 -> V_30 -> V_31 ;
struct V_34 * V_35 ;
unsigned int V_36 , V_37 ;
F_15 ( V_31 -> V_38 , & V_36 , & V_37 ) ;
V_35 = F_16 ( V_31 , 0 ) ;
V_4 -> V_26 = V_35 -> V_39 + V_31 -> V_40 [ 0 ] +
( V_12 -> V_41 * V_31 -> V_42 [ 0 ] ) + ( V_12 -> V_43 * V_37 / 8 ) ;
V_4 -> V_27 = V_4 -> V_26 +
( V_12 -> V_44 . V_45 * V_31 -> V_42 [ 0 ] ) ;
if ( V_4 -> V_46 == V_47 ) {
V_4 -> V_32 |= V_21 | V_22 ;
F_17 ( V_7 , 0 ) ;
} else {
F_6 ( V_12 , 0 ) ;
F_6 ( V_12 , 1 ) ;
}
}
static void V_26 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
if ( V_24 -> V_48 == 2 ) {
F_18 ( V_7 , V_49 , V_50 ) ;
F_19 ( 1 ) ;
F_20 ( V_7 , V_49 , V_50 ) ;
F_19 ( 1 ) ;
}
F_18 ( V_7 , V_51 , V_52 ) ;
F_18 ( V_7 , V_53 , F_21 ( V_54 ) ) ;
F_18 ( V_7 , V_53 , V_55 ) ;
}
static void F_22 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
F_20 ( V_7 , V_53 , V_55 ) ;
}
static void F_23 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
F_24 ( V_12 , V_56 ) ;
F_25 ( V_12 ) ;
F_26 ( & V_4 -> V_5 ) ;
F_27 ( V_4 ) ;
}
static int F_28 ( struct V_11 * V_12 ,
struct V_33 * V_31 ,
struct V_57 * V_58 ,
T_1 V_59 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
if ( V_4 -> V_58 ) {
F_29 ( V_7 -> V_7 , L_1 ) ;
return - V_60 ;
}
V_12 -> V_30 -> V_31 = V_31 ;
V_4 -> V_58 = V_58 ;
F_14 ( V_12 ) ;
return 0 ;
}
static void F_24 ( struct V_11 * V_12 , int V_44 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
if ( V_44 != V_47 )
V_44 = V_56 ;
if ( V_4 -> V_46 == V_44 )
return;
V_4 -> V_46 = V_44 ;
F_8 ( V_7 -> V_7 ) ;
if ( V_44 == V_47 ) {
F_30 ( V_7 -> V_7 ) ;
V_26 ( V_12 ) ;
} else {
V_4 -> V_61 = false ;
F_22 ( V_12 ) ;
if ( V_24 -> V_48 == 2 ) {
int V_62 = F_31 (
V_4 -> V_63 ,
V_4 -> V_61 ,
F_32 ( 50 ) ) ;
if ( V_62 == 0 )
F_29 ( V_7 -> V_7 , L_2 ) ;
}
F_33 ( V_7 -> V_7 ) ;
}
F_13 ( V_7 -> V_7 ) ;
}
static bool F_34 ( struct V_11 * V_12 ,
const struct V_64 * V_44 ,
struct V_64 * V_65 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
if ( ! V_4 -> V_66 )
return true ;
V_65 -> V_67 = V_44 -> V_68 - V_44 -> V_69 ;
V_65 -> V_70 |= V_71 ;
if ( V_44 -> V_70 & V_72 ) {
V_65 -> V_70 |= V_73 ;
V_65 -> V_70 &= ~ V_72 ;
} else {
V_65 -> V_70 |= V_72 ;
V_65 -> V_70 &= ~ V_73 ;
}
return true ;
}
static void F_35 ( struct V_11 * V_12 )
{
F_24 ( V_12 , V_56 ) ;
}
static void F_36 ( struct V_11 * V_12 )
{
F_24 ( V_12 , V_47 ) ;
}
static int F_37 ( struct V_11 * V_12 ,
struct V_64 * V_44 ,
struct V_64 * V_65 ,
int V_43 , int V_41 ,
struct V_33 * V_74 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
const struct V_75 * V_76 = V_4 -> V_76 ;
T_1 V_77 , V_78 , V_79 , V_80 , V_81 , V_82 , V_83 ;
int V_62 ;
V_62 = F_38 ( V_12 , V_44 ) ;
if ( F_39 ( V_62 ) )
return V_62 ;
if ( F_39 ( ! V_76 ) )
return - V_84 ;
F_8 ( V_7 -> V_7 ) ;
V_77 = F_40 ( V_7 , V_51 ) & ~ 0x00000770 ;
switch ( V_76 -> V_85 ) {
case 1 :
V_77 |= F_41 ( V_86 ) ;
break;
case 2 :
V_77 |= F_41 ( V_87 ) ;
break;
case 4 :
V_77 |= F_41 ( V_88 ) ;
break;
case 8 :
V_77 |= F_41 ( V_89 ) ;
break;
case 16 :
V_77 |= F_41 ( V_90 ) ;
break;
default:
return - V_84 ;
}
V_77 |= ( V_76 -> V_91 << 8 ) ;
F_9 ( V_7 , V_51 , V_77 ) ;
V_78 = V_44 -> V_92 - V_44 -> V_68 ;
V_79 = V_44 -> V_69 - V_44 -> V_93 ;
V_80 = V_44 -> V_68 - V_44 -> V_69 ;
V_81 = V_44 -> V_94 - V_44 -> V_95 ;
V_82 = V_44 -> V_96 - V_44 -> V_45 ;
V_83 = V_44 -> V_95 - V_44 -> V_96 ;
F_42 ( L_3 ,
V_44 -> V_93 , V_44 -> V_45 , V_78 , V_79 , V_80 , V_81 , V_82 , V_83 ) ;
V_77 = F_40 ( V_7 , V_97 ) & ~ 0x000fff00 ;
V_77 |= F_43 ( V_76 -> V_98 ) |
F_44 ( V_76 -> V_99 ) ;
if ( V_24 -> V_48 == 2 ) {
V_77 &= ~ 0x78000033 ;
V_77 |= ( ( V_79 - 1 ) & 0x300 ) >> 8 ;
V_77 |= ( ( V_78 - 1 ) & 0x300 ) >> 4 ;
V_77 |= ( ( V_80 - 1 ) & 0x3c0 ) << 21 ;
}
F_9 ( V_7 , V_97 , V_77 ) ;
V_77 = ( ( ( V_44 -> V_93 >> 4 ) - 1 ) << 4 ) |
( ( ( V_78 - 1 ) & 0xff ) << 24 ) |
( ( ( V_79 - 1 ) & 0xff ) << 16 ) |
( ( ( V_80 - 1 ) & 0x3f ) << 10 ) ;
if ( V_24 -> V_48 == 2 )
V_77 |= ( ( ( V_44 -> V_93 >> 4 ) - 1 ) & 0x40 ) >> 3 ;
F_9 ( V_7 , V_100 , V_77 ) ;
V_77 = ( ( V_44 -> V_45 - 1 ) & 0x3ff ) |
( ( V_81 & 0xff ) << 24 ) |
( ( V_82 & 0xff ) << 16 ) |
( ( ( V_83 - 1 ) & 0x3f ) << 10 ) ;
F_9 ( V_7 , V_101 , V_77 ) ;
if ( V_24 -> V_48 == 2 ) {
if ( ( V_44 -> V_45 - 1 ) & 0x400 ) {
F_18 ( V_7 , V_97 ,
V_102 ) ;
} else {
F_20 ( V_7 , V_97 ,
V_102 ) ;
}
}
V_77 = F_40 ( V_7 , V_53 ) &
~ ( V_103 | V_104 | V_105 |
V_106 | V_107 | 0x000ff000 ) ;
V_77 |= V_103 ;
if ( V_76 -> V_108 )
V_77 |= V_109 ;
if ( V_24 -> V_48 == 2 ) {
unsigned int V_36 , V_37 ;
F_15 ( V_12 -> V_30 -> V_31 -> V_38 , & V_36 , & V_37 ) ;
switch ( V_37 ) {
case 16 :
break;
case 32 :
V_77 |= V_107 ;
case 24 :
V_77 |= V_106 ;
break;
default:
F_29 ( V_7 -> V_7 , L_4 ) ;
return - V_84 ;
}
}
V_77 |= V_76 -> V_110 < 12 ;
F_9 ( V_7 , V_53 , V_77 ) ;
if ( V_76 -> V_111 )
F_18 ( V_7 , V_97 , V_112 ) ;
else
F_20 ( V_7 , V_97 , V_112 ) ;
if ( V_76 -> V_113 )
F_18 ( V_7 , V_97 , V_114 ) ;
else
F_20 ( V_7 , V_97 , V_114 ) ;
if ( V_76 -> V_115 )
F_18 ( V_7 , V_97 , V_116 ) ;
else
F_20 ( V_7 , V_97 , V_116 ) ;
if ( V_65 -> V_70 & V_72 )
F_18 ( V_7 , V_97 , V_117 ) ;
else
F_20 ( V_7 , V_97 , V_117 ) ;
if ( V_44 -> V_70 & V_118 )
F_18 ( V_7 , V_97 , V_119 ) ;
else
F_20 ( V_7 , V_97 , V_119 ) ;
if ( V_76 -> V_120 )
F_18 ( V_7 , V_53 , V_121 ) ;
else
F_20 ( V_7 , V_53 , V_121 ) ;
F_14 ( V_12 ) ;
F_45 ( V_12 ) ;
F_13 ( V_7 -> V_7 ) ;
return 0 ;
}
static int F_46 ( struct V_11 * V_12 , int V_43 , int V_41 ,
struct V_33 * V_74 )
{
F_14 ( V_12 ) ;
return 0 ;
}
int F_47 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
int V_122 = 0 ;
if ( V_24 -> V_48 == 1 )
V_122 = 1024 ;
else if ( V_24 -> V_48 == 2 )
V_122 = 2048 ;
return V_122 ;
}
int F_38 ( struct V_11 * V_12 , struct V_64 * V_44 )
{
struct V_23 * V_24 = V_12 -> V_7 -> V_25 ;
unsigned int V_123 ;
T_1 V_78 , V_79 , V_80 , V_81 , V_82 , V_83 ;
if ( V_44 -> V_93 > F_47 ( V_12 ) )
return V_124 ;
if ( V_44 -> V_93 & 0xf )
return V_124 ;
if ( V_44 -> V_45 > 2048 )
return V_125 ;
F_42 ( L_5 ,
V_44 -> V_93 , V_44 -> V_45 ,
F_48 ( V_44 ) , V_44 -> clock ) ;
V_78 = V_44 -> V_92 - V_44 -> V_68 ;
V_79 = V_44 -> V_69 - V_44 -> V_93 ;
V_80 = V_44 -> V_68 - V_44 -> V_69 ;
V_81 = V_44 -> V_94 - V_44 -> V_95 ;
V_82 = V_44 -> V_96 - V_44 -> V_45 ;
V_83 = V_44 -> V_95 - V_44 -> V_96 ;
if ( ( V_78 - 1 ) & ~ 0x3ff ) {
F_42 ( L_6 ) ;
return V_126 ;
}
if ( ( V_79 - 1 ) & ~ 0x3ff ) {
F_42 ( L_7 ) ;
return V_126 ;
}
if ( ( V_80 - 1 ) & ~ 0x3ff ) {
F_42 ( L_8 ) ;
return V_127 ;
}
if ( V_81 & ~ 0xff ) {
F_42 ( L_9 ) ;
return V_128 ;
}
if ( V_82 & ~ 0xff ) {
F_42 ( L_10 ) ;
return V_128 ;
}
if ( ( V_83 - 1 ) & ~ 0x3f ) {
F_42 ( L_11 ) ;
return V_129 ;
}
if ( V_44 -> clock > V_24 -> V_130 ) {
F_42 ( L_12 ) ;
return V_131 ;
}
if ( V_44 -> V_93 > V_24 -> V_122 )
return V_132 ;
V_123 = V_44 -> V_93 * V_44 -> V_45 *
F_48 ( V_44 ) ;
if ( V_123 > V_24 -> V_133 ) {
F_42 ( L_13 ) ;
return V_134 ;
}
return V_135 ;
}
void F_49 ( struct V_11 * V_12 ,
const struct V_75 * V_76 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
V_4 -> V_76 = V_76 ;
}
void F_50 ( struct V_11 * V_12 ,
bool V_66 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
V_4 -> V_66 = V_66 ;
}
void F_45 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
int V_46 = V_4 -> V_46 ;
unsigned int V_136 , div ;
int V_62 ;
F_8 ( V_7 -> V_7 ) ;
if ( V_46 == V_47 )
F_24 ( V_12 , V_56 ) ;
V_62 = F_51 ( V_24 -> V_137 , V_12 -> V_44 . clock * 1000 * 2 ) ;
if ( V_62 ) {
F_29 ( V_7 -> V_7 , L_14 ,
V_12 -> V_44 . clock ) ;
goto V_138;
}
V_136 = F_52 ( V_24 -> V_139 ) ;
div = V_136 / ( V_12 -> V_44 . clock * 1000 ) ;
F_42 ( L_15 , V_136 , V_12 -> V_44 . clock , div ) ;
F_42 ( L_16 , F_52 ( V_24 -> V_139 ) , F_52 ( V_24 -> V_137 ) ) ;
F_9 ( V_7 , V_140 , F_53 ( div ) |
V_141 ) ;
if ( V_24 -> V_48 == 2 )
F_18 ( V_7 , V_142 ,
V_143 | V_144 |
V_145 ) ;
if ( V_46 == V_47 )
F_24 ( V_12 , V_47 ) ;
V_138:
F_13 ( V_7 -> V_7 ) ;
}
T_2 F_54 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
T_1 V_20 = F_55 ( V_7 ) ;
if ( ( V_20 & V_146 ) && ( V_20 & V_147 ) ) {
F_22 ( V_12 ) ;
F_29 ( V_7 -> V_7 , L_17 , V_20 ) ;
F_56 ( V_7 , V_20 ) ;
V_26 ( V_12 ) ;
} else if ( V_20 & V_148 ) {
F_56 ( V_7 , V_20 ) ;
} else {
struct V_57 * V_58 ;
unsigned long V_70 ;
T_1 V_32 = V_4 -> V_32 & V_20 ;
F_56 ( V_7 , V_20 ) ;
if ( V_32 & V_21 )
F_6 ( V_12 , 0 ) ;
if ( V_32 & V_22 )
F_6 ( V_12 , 1 ) ;
F_57 ( V_7 , 0 ) ;
F_58 ( & V_7 -> V_149 , V_70 ) ;
V_58 = V_4 -> V_58 ;
V_4 -> V_58 = NULL ;
if ( V_58 )
F_59 ( V_7 , 0 , V_58 ) ;
F_60 ( & V_7 -> V_149 , V_70 ) ;
if ( V_32 && ! V_4 -> V_32 )
F_61 ( V_7 , 0 ) ;
}
if ( V_24 -> V_48 == 2 ) {
if ( V_20 & V_150 ) {
V_4 -> V_61 = true ;
F_62 ( & V_4 -> V_63 ) ;
}
F_9 ( V_7 , V_151 , 0 ) ;
}
return V_152 ;
}
void F_63 ( struct V_11 * V_12 , struct V_153 * V_154 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_57 * V_58 ;
struct V_6 * V_7 = V_12 -> V_7 ;
unsigned long V_70 ;
F_58 ( & V_7 -> V_149 , V_70 ) ;
V_58 = V_4 -> V_58 ;
if ( V_58 && V_58 -> V_8 . V_155 == V_154 ) {
V_4 -> V_58 = NULL ;
V_58 -> V_8 . V_156 ( & V_58 -> V_8 ) ;
F_61 ( V_7 , 0 ) ;
}
F_60 ( & V_7 -> V_149 , V_70 ) ;
}
struct V_11 * F_64 ( struct V_6 * V_7 )
{
struct V_4 * V_4 ;
struct V_11 * V_12 ;
int V_62 ;
V_4 = F_65 ( sizeof( * V_4 ) , V_157 ) ;
if ( ! V_4 ) {
F_29 ( V_7 -> V_7 , L_18 ) ;
return NULL ;
}
V_12 = & V_4 -> V_8 ;
V_4 -> V_46 = V_56 ;
F_66 ( & V_4 -> V_63 ) ;
F_67 ( & V_4 -> V_5 ,
L_19 , F_1 ) ;
V_62 = F_68 ( V_7 , V_12 , & V_158 ) ;
if ( V_62 < 0 )
goto V_159;
F_69 ( V_12 , & V_160 ) ;
return V_12 ;
V_159:
F_23 ( V_12 ) ;
return NULL ;
}
