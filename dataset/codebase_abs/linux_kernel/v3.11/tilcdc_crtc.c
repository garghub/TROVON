static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_4 * V_5 = V_3 -> V_6 . V_5 ;
struct V_7 * V_8 ;
F_3 ( & V_5 -> V_9 . V_10 ) ;
while ( F_4 ( & V_3 -> V_11 , & V_8 ) )
F_5 ( V_8 ) ;
F_6 ( & V_5 -> V_9 . V_10 ) ;
}
static void F_7 ( struct V_12 * V_13 , int V_14 )
{
static const T_1 V_15 [] = {
V_16 ,
V_17 ,
} ;
static const T_1 V_18 [] = {
V_19 ,
V_20 ,
} ;
static const T_1 V_21 [] = {
V_22 , V_23 ,
} ;
struct V_3 * V_3 = F_8 ( V_13 ) ;
struct V_4 * V_5 = V_13 -> V_5 ;
F_9 ( V_5 -> V_5 ) ;
F_10 ( V_5 , V_15 [ V_14 ] , V_3 -> V_24 ) ;
F_10 ( V_5 , V_18 [ V_14 ] , V_3 -> V_25 ) ;
if ( V_3 -> V_26 [ V_14 ] ) {
if ( F_11 ( & V_3 -> V_11 ,
( const struct V_7 * * ) & V_3 -> V_26 [ V_14 ] ) ) {
struct V_27 * V_28 = V_5 -> V_29 ;
F_12 ( V_28 -> V_30 , & V_3 -> V_2 ) ;
} else {
F_13 ( V_5 -> V_5 , L_1 ) ;
F_5 ( V_3 -> V_26 [ V_14 ] ) ;
}
}
V_3 -> V_26 [ V_14 ] = V_13 -> V_8 ;
F_14 ( V_3 -> V_26 [ V_14 ] ) ;
V_3 -> V_31 &= ~ V_21 [ V_14 ] ;
F_15 ( V_5 -> V_5 ) ;
}
static void F_16 ( struct V_12 * V_13 )
{
struct V_3 * V_3 = F_8 ( V_13 ) ;
struct V_4 * V_5 = V_13 -> V_5 ;
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_32 * V_33 ;
unsigned int V_34 , V_35 ;
F_17 ( V_8 -> V_36 , & V_34 , & V_35 ) ;
V_33 = F_18 ( V_8 , 0 ) ;
V_3 -> V_24 = V_33 -> V_37 + V_8 -> V_38 [ 0 ] +
( V_13 -> V_39 * V_8 -> V_40 [ 0 ] ) + ( V_13 -> V_41 * V_35 / 8 ) ;
V_3 -> V_25 = V_3 -> V_24 +
( V_13 -> V_42 . V_43 * V_8 -> V_40 [ 0 ] ) ;
if ( V_3 -> V_44 == V_45 ) {
V_3 -> V_31 |= V_22 | V_23 ;
F_19 ( V_5 , 0 ) ;
} else {
F_7 ( V_13 , 0 ) ;
F_7 ( V_13 , 1 ) ;
}
}
static void V_24 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = V_13 -> V_5 ;
struct V_27 * V_28 = V_5 -> V_29 ;
if ( V_28 -> V_46 == 2 ) {
F_20 ( V_5 , V_47 , V_48 ) ;
F_21 ( 1 ) ;
F_22 ( V_5 , V_47 , V_48 ) ;
F_21 ( 1 ) ;
}
F_20 ( V_5 , V_49 , V_50 ) ;
F_20 ( V_5 , V_51 , F_23 ( V_52 ) ) ;
F_20 ( V_5 , V_51 , V_53 ) ;
}
static void F_24 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = V_13 -> V_5 ;
F_22 ( V_5 , V_51 , V_53 ) ;
}
static void F_25 ( struct V_12 * V_13 )
{
struct V_3 * V_3 = F_8 ( V_13 ) ;
F_26 ( V_3 -> V_44 == V_45 ) ;
F_27 ( V_13 ) ;
F_26 ( ! F_28 ( & V_3 -> V_11 ) ) ;
F_29 ( & V_3 -> V_11 ) ;
F_30 ( V_3 ) ;
}
static int F_31 ( struct V_12 * V_13 ,
struct V_7 * V_8 ,
struct V_54 * V_55 )
{
struct V_3 * V_3 = F_8 ( V_13 ) ;
struct V_4 * V_5 = V_13 -> V_5 ;
if ( V_3 -> V_55 ) {
F_13 ( V_5 -> V_5 , L_2 ) ;
return - V_56 ;
}
V_13 -> V_8 = V_8 ;
V_3 -> V_55 = V_55 ;
F_16 ( V_13 ) ;
return 0 ;
}
static void F_32 ( struct V_12 * V_13 , int V_42 )
{
struct V_3 * V_3 = F_8 ( V_13 ) ;
struct V_4 * V_5 = V_13 -> V_5 ;
struct V_27 * V_28 = V_5 -> V_29 ;
if ( V_42 != V_45 )
V_42 = V_57 ;
if ( V_3 -> V_44 == V_42 )
return;
V_3 -> V_44 = V_42 ;
F_9 ( V_5 -> V_5 ) ;
if ( V_42 == V_45 ) {
F_33 ( V_5 -> V_5 ) ;
V_24 ( V_13 ) ;
} else {
V_3 -> V_58 = false ;
F_24 ( V_13 ) ;
if ( V_28 -> V_46 == 2 ) {
int V_59 = F_34 (
V_3 -> V_60 ,
V_3 -> V_58 ,
F_35 ( 50 ) ) ;
if ( V_59 == 0 )
F_13 ( V_5 -> V_5 , L_3 ) ;
}
F_36 ( V_5 -> V_5 ) ;
}
F_15 ( V_5 -> V_5 ) ;
}
static bool F_37 ( struct V_12 * V_13 ,
const struct V_61 * V_42 ,
struct V_61 * V_62 )
{
return true ;
}
static void F_38 ( struct V_12 * V_13 )
{
F_32 ( V_13 , V_57 ) ;
}
static void F_39 ( struct V_12 * V_13 )
{
F_32 ( V_13 , V_45 ) ;
}
static int F_40 ( struct V_12 * V_13 ,
struct V_61 * V_42 ,
struct V_61 * V_62 ,
int V_41 , int V_39 ,
struct V_7 * V_63 )
{
struct V_3 * V_3 = F_8 ( V_13 ) ;
struct V_4 * V_5 = V_13 -> V_5 ;
struct V_27 * V_28 = V_5 -> V_29 ;
const struct V_64 * V_65 = V_3 -> V_65 ;
T_1 V_66 , V_67 , V_68 , V_69 , V_70 , V_71 , V_72 ;
int V_59 ;
V_59 = F_41 ( V_13 , V_42 ) ;
if ( F_26 ( V_59 ) )
return V_59 ;
if ( F_26 ( ! V_65 ) )
return - V_73 ;
F_9 ( V_5 -> V_5 ) ;
V_66 = F_42 ( V_5 , V_49 ) & ~ 0x00000770 ;
switch ( V_65 -> V_74 ) {
case 1 :
V_66 |= F_43 ( V_75 ) ;
break;
case 2 :
V_66 |= F_43 ( V_76 ) ;
break;
case 4 :
V_66 |= F_43 ( V_77 ) ;
break;
case 8 :
V_66 |= F_43 ( V_78 ) ;
break;
case 16 :
V_66 |= F_43 ( V_79 ) ;
break;
default:
return - V_73 ;
}
V_66 |= ( V_65 -> V_80 << 8 ) ;
F_10 ( V_5 , V_49 , V_66 ) ;
V_67 = V_42 -> V_81 - V_42 -> V_82 ;
V_68 = V_42 -> V_83 - V_42 -> V_84 ;
V_69 = V_42 -> V_82 - V_42 -> V_83 ;
V_70 = V_42 -> V_85 - V_42 -> V_86 ;
V_71 = V_42 -> V_87 - V_42 -> V_43 ;
V_72 = V_42 -> V_86 - V_42 -> V_87 ;
F_44 ( L_4 ,
V_42 -> V_84 , V_42 -> V_43 , V_67 , V_68 , V_69 , V_70 , V_71 , V_72 ) ;
V_66 = F_42 ( V_5 , V_88 ) & ~ 0x000fff00 ;
V_66 |= F_45 ( V_65 -> V_89 ) |
F_46 ( V_65 -> V_90 ) ;
if ( V_28 -> V_46 == 2 ) {
V_66 &= ~ 0x78000033 ;
V_66 |= ( ( V_68 - 1 ) & 0x300 ) >> 8 ;
V_66 |= ( ( V_67 - 1 ) & 0x300 ) >> 4 ;
V_66 |= ( ( V_69 - 1 ) & 0x3c0 ) << 21 ;
}
F_10 ( V_5 , V_88 , V_66 ) ;
V_66 = ( ( ( V_42 -> V_84 >> 4 ) - 1 ) << 4 ) |
( ( ( V_67 - 1 ) & 0xff ) << 24 ) |
( ( ( V_68 - 1 ) & 0xff ) << 16 ) |
( ( ( V_69 - 1 ) & 0x3f ) << 10 ) ;
if ( V_28 -> V_46 == 2 )
V_66 |= ( ( ( V_42 -> V_84 >> 4 ) - 1 ) & 0x40 ) >> 3 ;
F_10 ( V_5 , V_91 , V_66 ) ;
V_66 = ( ( V_42 -> V_43 - 1 ) & 0x3ff ) |
( ( V_70 & 0xff ) << 24 ) |
( ( V_71 & 0xff ) << 16 ) |
( ( ( V_72 - 1 ) & 0x3f ) << 10 ) ;
F_10 ( V_5 , V_92 , V_66 ) ;
if ( V_28 -> V_46 == 2 ) {
if ( ( V_42 -> V_43 - 1 ) & 0x400 ) {
F_20 ( V_5 , V_88 ,
V_93 ) ;
} else {
F_22 ( V_5 , V_88 ,
V_93 ) ;
}
}
V_66 = F_42 ( V_5 , V_51 ) &
~ ( V_94 | V_95 | V_96 |
V_97 | V_98 | 0x000ff000 ) ;
V_66 |= V_94 ;
if ( V_65 -> V_99 )
V_66 |= V_100 ;
if ( V_28 -> V_46 == 2 ) {
unsigned int V_34 , V_35 ;
F_17 ( V_13 -> V_8 -> V_36 , & V_34 , & V_35 ) ;
switch ( V_35 ) {
case 16 :
break;
case 32 :
V_66 |= V_98 ;
case 24 :
V_66 |= V_97 ;
break;
default:
F_13 ( V_5 -> V_5 , L_5 ) ;
return - V_73 ;
}
}
V_66 |= V_65 -> V_101 < 12 ;
F_10 ( V_5 , V_51 , V_66 ) ;
if ( V_65 -> V_102 )
F_20 ( V_5 , V_88 , V_103 ) ;
else
F_22 ( V_5 , V_88 , V_103 ) ;
if ( V_65 -> V_104 )
F_20 ( V_5 , V_88 , V_105 ) ;
else
F_22 ( V_5 , V_88 , V_105 ) ;
if ( V_65 -> V_106 )
F_20 ( V_5 , V_88 , V_107 ) ;
else
F_22 ( V_5 , V_88 , V_107 ) ;
if ( V_42 -> V_108 & V_109 )
F_20 ( V_5 , V_88 , V_110 ) ;
else
F_22 ( V_5 , V_88 , V_110 ) ;
if ( V_42 -> V_108 & V_111 )
F_20 ( V_5 , V_88 , V_112 ) ;
else
F_22 ( V_5 , V_88 , V_112 ) ;
if ( V_65 -> V_113 )
F_20 ( V_5 , V_51 , V_114 ) ;
else
F_22 ( V_5 , V_51 , V_114 ) ;
F_16 ( V_13 ) ;
F_47 ( V_13 ) ;
F_15 ( V_5 -> V_5 ) ;
return 0 ;
}
static int F_48 ( struct V_12 * V_13 , int V_41 , int V_39 ,
struct V_7 * V_63 )
{
F_16 ( V_13 ) ;
return 0 ;
}
int F_49 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = V_13 -> V_5 ;
struct V_27 * V_28 = V_5 -> V_29 ;
int V_115 = 0 ;
if ( V_28 -> V_46 == 1 )
V_115 = 1024 ;
else if ( V_28 -> V_46 == 2 )
V_115 = 2048 ;
return V_115 ;
}
int F_41 ( struct V_12 * V_13 , struct V_61 * V_42 )
{
struct V_27 * V_28 = V_13 -> V_5 -> V_29 ;
unsigned int V_116 ;
T_1 V_67 , V_68 , V_69 , V_70 , V_71 , V_72 ;
if ( V_42 -> V_84 > F_49 ( V_13 ) )
return V_117 ;
if ( V_42 -> V_84 & 0xf )
return V_117 ;
if ( V_42 -> V_43 > 2048 )
return V_118 ;
F_44 ( L_6 ,
V_42 -> V_84 , V_42 -> V_43 ,
F_50 ( V_42 ) , V_42 -> clock ) ;
V_67 = V_42 -> V_81 - V_42 -> V_82 ;
V_68 = V_42 -> V_83 - V_42 -> V_84 ;
V_69 = V_42 -> V_82 - V_42 -> V_83 ;
V_70 = V_42 -> V_85 - V_42 -> V_86 ;
V_71 = V_42 -> V_87 - V_42 -> V_43 ;
V_72 = V_42 -> V_86 - V_42 -> V_87 ;
if ( ( V_67 - 1 ) & ~ 0x3ff ) {
F_44 ( L_7 ) ;
return V_119 ;
}
if ( ( V_68 - 1 ) & ~ 0x3ff ) {
F_44 ( L_8 ) ;
return V_119 ;
}
if ( ( V_69 - 1 ) & ~ 0x3ff ) {
F_44 ( L_9 ) ;
return V_120 ;
}
if ( V_70 & ~ 0xff ) {
F_44 ( L_10 ) ;
return V_121 ;
}
if ( V_71 & ~ 0xff ) {
F_44 ( L_11 ) ;
return V_121 ;
}
if ( ( V_72 - 1 ) & ~ 0x3f ) {
F_44 ( L_12 ) ;
return V_122 ;
}
if ( V_42 -> clock > V_28 -> V_123 ) {
F_44 ( L_13 ) ;
return V_124 ;
}
if ( V_42 -> V_84 > V_28 -> V_115 )
return V_125 ;
V_116 = V_42 -> V_84 * V_42 -> V_43 *
F_50 ( V_42 ) ;
if ( V_116 > V_28 -> V_126 ) {
F_44 ( L_14 ) ;
return V_127 ;
}
return V_128 ;
}
void F_51 ( struct V_12 * V_13 ,
const struct V_64 * V_65 )
{
struct V_3 * V_3 = F_8 ( V_13 ) ;
V_3 -> V_65 = V_65 ;
}
void F_47 ( struct V_12 * V_13 )
{
struct V_3 * V_3 = F_8 ( V_13 ) ;
struct V_4 * V_5 = V_13 -> V_5 ;
struct V_27 * V_28 = V_5 -> V_29 ;
int V_44 = V_3 -> V_44 ;
unsigned int V_129 , div ;
int V_59 ;
F_9 ( V_5 -> V_5 ) ;
if ( V_44 == V_45 )
F_32 ( V_13 , V_57 ) ;
V_59 = F_52 ( V_28 -> V_130 , V_13 -> V_42 . clock * 1000 * 2 ) ;
if ( V_59 ) {
F_13 ( V_5 -> V_5 , L_15 ,
V_13 -> V_42 . clock ) ;
goto V_131;
}
V_129 = F_53 ( V_28 -> V_132 ) ;
div = V_129 / ( V_13 -> V_42 . clock * 1000 ) ;
F_44 ( L_16 , V_129 , V_13 -> V_42 . clock , div ) ;
F_44 ( L_17 , F_53 ( V_28 -> V_132 ) , F_53 ( V_28 -> V_130 ) ) ;
F_10 ( V_5 , V_133 , F_54 ( div ) |
V_134 ) ;
if ( V_28 -> V_46 == 2 )
F_20 ( V_5 , V_135 ,
V_136 | V_137 |
V_138 ) ;
if ( V_44 == V_45 )
F_32 ( V_13 , V_45 ) ;
V_131:
F_15 ( V_5 -> V_5 ) ;
}
T_2 F_55 ( struct V_12 * V_13 )
{
struct V_3 * V_3 = F_8 ( V_13 ) ;
struct V_4 * V_5 = V_13 -> V_5 ;
struct V_27 * V_28 = V_5 -> V_29 ;
T_1 V_21 = F_56 ( V_5 ) ;
if ( ( V_21 & V_139 ) && ( V_21 & V_140 ) ) {
F_24 ( V_13 ) ;
F_13 ( V_5 -> V_5 , L_18 , V_21 ) ;
F_57 ( V_5 , V_21 ) ;
V_24 ( V_13 ) ;
} else if ( V_21 & V_141 ) {
F_57 ( V_5 , V_21 ) ;
} else {
struct V_54 * V_55 ;
unsigned long V_108 ;
T_1 V_31 = V_3 -> V_31 & V_21 ;
F_57 ( V_5 , V_21 ) ;
if ( V_31 & V_22 )
F_7 ( V_13 , 0 ) ;
if ( V_31 & V_23 )
F_7 ( V_13 , 1 ) ;
F_58 ( V_5 , 0 ) ;
F_59 ( & V_5 -> V_142 , V_108 ) ;
V_55 = V_3 -> V_55 ;
V_3 -> V_55 = NULL ;
if ( V_55 )
F_60 ( V_5 , 0 , V_55 ) ;
F_61 ( & V_5 -> V_142 , V_108 ) ;
if ( V_31 && ! V_3 -> V_31 )
F_62 ( V_5 , 0 ) ;
}
if ( V_28 -> V_46 == 2 ) {
if ( V_21 & V_143 ) {
V_3 -> V_58 = true ;
F_63 ( & V_3 -> V_60 ) ;
}
F_10 ( V_5 , V_144 , 0 ) ;
}
return V_145 ;
}
void F_64 ( struct V_12 * V_13 , struct V_146 * V_147 )
{
struct V_3 * V_3 = F_8 ( V_13 ) ;
struct V_54 * V_55 ;
struct V_4 * V_5 = V_13 -> V_5 ;
unsigned long V_108 ;
F_59 ( & V_5 -> V_142 , V_108 ) ;
V_55 = V_3 -> V_55 ;
if ( V_55 && V_55 -> V_6 . V_148 == V_147 ) {
V_3 -> V_55 = NULL ;
V_55 -> V_6 . V_149 ( & V_55 -> V_6 ) ;
F_62 ( V_5 , 0 ) ;
}
F_61 ( & V_5 -> V_142 , V_108 ) ;
}
struct V_12 * F_65 ( struct V_4 * V_5 )
{
struct V_3 * V_3 ;
struct V_12 * V_13 ;
int V_59 ;
V_3 = F_66 ( sizeof( * V_3 ) , V_150 ) ;
if ( ! V_3 ) {
F_13 ( V_5 -> V_5 , L_19 ) ;
return NULL ;
}
V_13 = & V_3 -> V_6 ;
V_3 -> V_44 = V_57 ;
F_67 ( & V_3 -> V_60 ) ;
V_59 = F_68 ( & V_3 -> V_11 , 16 , V_150 ) ;
if ( V_59 ) {
F_13 ( V_5 -> V_5 , L_20 ) ;
goto V_151;
}
F_69 ( & V_3 -> V_2 , F_1 ) ;
V_59 = F_70 ( V_5 , V_13 , & V_152 ) ;
if ( V_59 < 0 )
goto V_151;
F_71 ( V_13 , & V_153 ) ;
return V_13 ;
V_151:
F_25 ( V_13 ) ;
return NULL ;
}
