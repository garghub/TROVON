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
V_4 -> V_28 [ V_13 ] = V_12 -> V_30 ;
F_12 ( V_4 -> V_28 [ V_13 ] ) ;
V_4 -> V_31 &= ~ V_20 [ V_13 ] ;
F_13 ( V_7 -> V_7 ) ;
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_30 = V_12 -> V_30 ;
struct V_33 * V_34 ;
unsigned int V_35 , V_36 ;
F_15 ( V_30 -> V_37 , & V_35 , & V_36 ) ;
V_34 = F_16 ( V_30 , 0 ) ;
V_4 -> V_26 = V_34 -> V_38 + V_30 -> V_39 [ 0 ] +
( V_12 -> V_40 * V_30 -> V_41 [ 0 ] ) + ( V_12 -> V_42 * V_36 / 8 ) ;
V_4 -> V_27 = V_4 -> V_26 +
( V_12 -> V_43 . V_44 * V_30 -> V_41 [ 0 ] ) ;
if ( V_4 -> V_45 == V_46 ) {
V_4 -> V_31 |= V_21 | V_22 ;
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
if ( V_24 -> V_47 == 2 ) {
F_18 ( V_7 , V_48 , V_49 ) ;
F_19 ( 1 ) ;
F_20 ( V_7 , V_48 , V_49 ) ;
F_19 ( 1 ) ;
}
F_18 ( V_7 , V_50 , V_51 ) ;
F_18 ( V_7 , V_52 , F_21 ( V_53 ) ) ;
F_18 ( V_7 , V_52 , V_54 ) ;
}
static void F_22 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
F_20 ( V_7 , V_52 , V_54 ) ;
}
static void F_23 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
F_24 ( V_4 -> V_45 == V_46 ) ;
F_25 ( V_12 ) ;
F_26 ( & V_4 -> V_5 ) ;
F_27 ( V_4 ) ;
}
static int F_28 ( struct V_11 * V_12 ,
struct V_32 * V_30 ,
struct V_55 * V_56 ,
T_1 V_57 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
if ( V_4 -> V_56 ) {
F_29 ( V_7 -> V_7 , L_1 ) ;
return - V_58 ;
}
V_12 -> V_30 = V_30 ;
V_4 -> V_56 = V_56 ;
F_14 ( V_12 ) ;
return 0 ;
}
static void F_30 ( struct V_11 * V_12 , int V_43 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
if ( V_43 != V_46 )
V_43 = V_59 ;
if ( V_4 -> V_45 == V_43 )
return;
V_4 -> V_45 = V_43 ;
F_8 ( V_7 -> V_7 ) ;
if ( V_43 == V_46 ) {
F_31 ( V_7 -> V_7 ) ;
V_26 ( V_12 ) ;
} else {
V_4 -> V_60 = false ;
F_22 ( V_12 ) ;
if ( V_24 -> V_47 == 2 ) {
int V_61 = F_32 (
V_4 -> V_62 ,
V_4 -> V_60 ,
F_33 ( 50 ) ) ;
if ( V_61 == 0 )
F_29 ( V_7 -> V_7 , L_2 ) ;
}
F_34 ( V_7 -> V_7 ) ;
}
F_13 ( V_7 -> V_7 ) ;
}
static bool F_35 ( struct V_11 * V_12 ,
const struct V_63 * V_43 ,
struct V_63 * V_64 )
{
return true ;
}
static void F_36 ( struct V_11 * V_12 )
{
F_30 ( V_12 , V_59 ) ;
}
static void F_37 ( struct V_11 * V_12 )
{
F_30 ( V_12 , V_46 ) ;
}
static int F_38 ( struct V_11 * V_12 ,
struct V_63 * V_43 ,
struct V_63 * V_64 ,
int V_42 , int V_40 ,
struct V_32 * V_65 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
const struct V_66 * V_67 = V_4 -> V_67 ;
T_1 V_68 , V_69 , V_70 , V_71 , V_72 , V_73 , V_74 ;
int V_61 ;
V_61 = F_39 ( V_12 , V_43 ) ;
if ( F_24 ( V_61 ) )
return V_61 ;
if ( F_24 ( ! V_67 ) )
return - V_75 ;
F_8 ( V_7 -> V_7 ) ;
V_68 = F_40 ( V_7 , V_50 ) & ~ 0x00000770 ;
switch ( V_67 -> V_76 ) {
case 1 :
V_68 |= F_41 ( V_77 ) ;
break;
case 2 :
V_68 |= F_41 ( V_78 ) ;
break;
case 4 :
V_68 |= F_41 ( V_79 ) ;
break;
case 8 :
V_68 |= F_41 ( V_80 ) ;
break;
case 16 :
V_68 |= F_41 ( V_81 ) ;
break;
default:
return - V_75 ;
}
V_68 |= ( V_67 -> V_82 << 8 ) ;
F_9 ( V_7 , V_50 , V_68 ) ;
V_69 = V_43 -> V_83 - V_43 -> V_84 ;
V_70 = V_43 -> V_85 - V_43 -> V_86 ;
V_71 = V_43 -> V_84 - V_43 -> V_85 ;
V_72 = V_43 -> V_87 - V_43 -> V_88 ;
V_73 = V_43 -> V_89 - V_43 -> V_44 ;
V_74 = V_43 -> V_88 - V_43 -> V_89 ;
F_42 ( L_3 ,
V_43 -> V_86 , V_43 -> V_44 , V_69 , V_70 , V_71 , V_72 , V_73 , V_74 ) ;
V_68 = F_40 ( V_7 , V_90 ) & ~ 0x000fff00 ;
V_68 |= F_43 ( V_67 -> V_91 ) |
F_44 ( V_67 -> V_92 ) ;
if ( V_24 -> V_47 == 2 ) {
V_68 &= ~ 0x78000033 ;
V_68 |= ( ( V_70 - 1 ) & 0x300 ) >> 8 ;
V_68 |= ( ( V_69 - 1 ) & 0x300 ) >> 4 ;
V_68 |= ( ( V_71 - 1 ) & 0x3c0 ) << 21 ;
}
F_9 ( V_7 , V_90 , V_68 ) ;
V_68 = ( ( ( V_43 -> V_86 >> 4 ) - 1 ) << 4 ) |
( ( ( V_69 - 1 ) & 0xff ) << 24 ) |
( ( ( V_70 - 1 ) & 0xff ) << 16 ) |
( ( ( V_71 - 1 ) & 0x3f ) << 10 ) ;
if ( V_24 -> V_47 == 2 )
V_68 |= ( ( ( V_43 -> V_86 >> 4 ) - 1 ) & 0x40 ) >> 3 ;
F_9 ( V_7 , V_93 , V_68 ) ;
V_68 = ( ( V_43 -> V_44 - 1 ) & 0x3ff ) |
( ( V_72 & 0xff ) << 24 ) |
( ( V_73 & 0xff ) << 16 ) |
( ( ( V_74 - 1 ) & 0x3f ) << 10 ) ;
F_9 ( V_7 , V_94 , V_68 ) ;
if ( V_24 -> V_47 == 2 ) {
if ( ( V_43 -> V_44 - 1 ) & 0x400 ) {
F_18 ( V_7 , V_90 ,
V_95 ) ;
} else {
F_20 ( V_7 , V_90 ,
V_95 ) ;
}
}
V_68 = F_40 ( V_7 , V_52 ) &
~ ( V_96 | V_97 | V_98 |
V_99 | V_100 | 0x000ff000 ) ;
V_68 |= V_96 ;
if ( V_67 -> V_101 )
V_68 |= V_102 ;
if ( V_24 -> V_47 == 2 ) {
unsigned int V_35 , V_36 ;
F_15 ( V_12 -> V_30 -> V_37 , & V_35 , & V_36 ) ;
switch ( V_36 ) {
case 16 :
break;
case 32 :
V_68 |= V_100 ;
case 24 :
V_68 |= V_99 ;
break;
default:
F_29 ( V_7 -> V_7 , L_4 ) ;
return - V_75 ;
}
}
V_68 |= V_67 -> V_103 < 12 ;
F_9 ( V_7 , V_52 , V_68 ) ;
if ( V_67 -> V_104 )
F_18 ( V_7 , V_90 , V_105 ) ;
else
F_20 ( V_7 , V_90 , V_105 ) ;
if ( V_67 -> V_106 )
F_18 ( V_7 , V_90 , V_107 ) ;
else
F_20 ( V_7 , V_90 , V_107 ) ;
if ( V_67 -> V_108 )
F_18 ( V_7 , V_90 , V_109 ) ;
else
F_20 ( V_7 , V_90 , V_109 ) ;
if ( V_64 -> V_110 & V_111 )
F_18 ( V_7 , V_90 , V_112 ) ;
else
F_20 ( V_7 , V_90 , V_112 ) ;
if ( V_43 -> V_110 & V_113 )
F_18 ( V_7 , V_90 , V_114 ) ;
else
F_20 ( V_7 , V_90 , V_114 ) ;
if ( V_67 -> V_115 )
F_18 ( V_7 , V_52 , V_116 ) ;
else
F_20 ( V_7 , V_52 , V_116 ) ;
F_14 ( V_12 ) ;
F_45 ( V_12 ) ;
F_13 ( V_7 -> V_7 ) ;
return 0 ;
}
static int F_46 ( struct V_11 * V_12 , int V_42 , int V_40 ,
struct V_32 * V_65 )
{
F_14 ( V_12 ) ;
return 0 ;
}
int F_47 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
int V_117 = 0 ;
if ( V_24 -> V_47 == 1 )
V_117 = 1024 ;
else if ( V_24 -> V_47 == 2 )
V_117 = 2048 ;
return V_117 ;
}
int F_39 ( struct V_11 * V_12 , struct V_63 * V_43 )
{
struct V_23 * V_24 = V_12 -> V_7 -> V_25 ;
unsigned int V_118 ;
T_1 V_69 , V_70 , V_71 , V_72 , V_73 , V_74 ;
if ( V_43 -> V_86 > F_47 ( V_12 ) )
return V_119 ;
if ( V_43 -> V_86 & 0xf )
return V_119 ;
if ( V_43 -> V_44 > 2048 )
return V_120 ;
F_42 ( L_5 ,
V_43 -> V_86 , V_43 -> V_44 ,
F_48 ( V_43 ) , V_43 -> clock ) ;
V_69 = V_43 -> V_83 - V_43 -> V_84 ;
V_70 = V_43 -> V_85 - V_43 -> V_86 ;
V_71 = V_43 -> V_84 - V_43 -> V_85 ;
V_72 = V_43 -> V_87 - V_43 -> V_88 ;
V_73 = V_43 -> V_89 - V_43 -> V_44 ;
V_74 = V_43 -> V_88 - V_43 -> V_89 ;
if ( ( V_69 - 1 ) & ~ 0x3ff ) {
F_42 ( L_6 ) ;
return V_121 ;
}
if ( ( V_70 - 1 ) & ~ 0x3ff ) {
F_42 ( L_7 ) ;
return V_121 ;
}
if ( ( V_71 - 1 ) & ~ 0x3ff ) {
F_42 ( L_8 ) ;
return V_122 ;
}
if ( V_72 & ~ 0xff ) {
F_42 ( L_9 ) ;
return V_123 ;
}
if ( V_73 & ~ 0xff ) {
F_42 ( L_10 ) ;
return V_123 ;
}
if ( ( V_74 - 1 ) & ~ 0x3f ) {
F_42 ( L_11 ) ;
return V_124 ;
}
if ( V_43 -> clock > V_24 -> V_125 ) {
F_42 ( L_12 ) ;
return V_126 ;
}
if ( V_43 -> V_86 > V_24 -> V_117 )
return V_127 ;
V_118 = V_43 -> V_86 * V_43 -> V_44 *
F_48 ( V_43 ) ;
if ( V_118 > V_24 -> V_128 ) {
F_42 ( L_13 ) ;
return V_129 ;
}
return V_130 ;
}
void F_49 ( struct V_11 * V_12 ,
const struct V_66 * V_67 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
V_4 -> V_67 = V_67 ;
}
void F_45 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
int V_45 = V_4 -> V_45 ;
unsigned int V_131 , div ;
int V_61 ;
F_8 ( V_7 -> V_7 ) ;
if ( V_45 == V_46 )
F_30 ( V_12 , V_59 ) ;
V_61 = F_50 ( V_24 -> V_132 , V_12 -> V_43 . clock * 1000 * 2 ) ;
if ( V_61 ) {
F_29 ( V_7 -> V_7 , L_14 ,
V_12 -> V_43 . clock ) ;
goto V_133;
}
V_131 = F_51 ( V_24 -> V_134 ) ;
div = V_131 / ( V_12 -> V_43 . clock * 1000 ) ;
F_42 ( L_15 , V_131 , V_12 -> V_43 . clock , div ) ;
F_42 ( L_16 , F_51 ( V_24 -> V_134 ) , F_51 ( V_24 -> V_132 ) ) ;
F_9 ( V_7 , V_135 , F_52 ( div ) |
V_136 ) ;
if ( V_24 -> V_47 == 2 )
F_18 ( V_7 , V_137 ,
V_138 | V_139 |
V_140 ) ;
if ( V_45 == V_46 )
F_30 ( V_12 , V_46 ) ;
V_133:
F_13 ( V_7 -> V_7 ) ;
}
T_2 F_53 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
T_1 V_20 = F_54 ( V_7 ) ;
if ( ( V_20 & V_141 ) && ( V_20 & V_142 ) ) {
F_22 ( V_12 ) ;
F_29 ( V_7 -> V_7 , L_17 , V_20 ) ;
F_55 ( V_7 , V_20 ) ;
V_26 ( V_12 ) ;
} else if ( V_20 & V_143 ) {
F_55 ( V_7 , V_20 ) ;
} else {
struct V_55 * V_56 ;
unsigned long V_110 ;
T_1 V_31 = V_4 -> V_31 & V_20 ;
F_55 ( V_7 , V_20 ) ;
if ( V_31 & V_21 )
F_6 ( V_12 , 0 ) ;
if ( V_31 & V_22 )
F_6 ( V_12 , 1 ) ;
F_56 ( V_7 , 0 ) ;
F_57 ( & V_7 -> V_144 , V_110 ) ;
V_56 = V_4 -> V_56 ;
V_4 -> V_56 = NULL ;
if ( V_56 )
F_58 ( V_7 , 0 , V_56 ) ;
F_59 ( & V_7 -> V_144 , V_110 ) ;
if ( V_31 && ! V_4 -> V_31 )
F_60 ( V_7 , 0 ) ;
}
if ( V_24 -> V_47 == 2 ) {
if ( V_20 & V_145 ) {
V_4 -> V_60 = true ;
F_61 ( & V_4 -> V_62 ) ;
}
F_9 ( V_7 , V_146 , 0 ) ;
}
return V_147 ;
}
void F_62 ( struct V_11 * V_12 , struct V_148 * V_149 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_55 * V_56 ;
struct V_6 * V_7 = V_12 -> V_7 ;
unsigned long V_110 ;
F_57 ( & V_7 -> V_144 , V_110 ) ;
V_56 = V_4 -> V_56 ;
if ( V_56 && V_56 -> V_8 . V_150 == V_149 ) {
V_4 -> V_56 = NULL ;
V_56 -> V_8 . V_151 ( & V_56 -> V_8 ) ;
F_60 ( V_7 , 0 ) ;
}
F_59 ( & V_7 -> V_144 , V_110 ) ;
}
struct V_11 * F_63 ( struct V_6 * V_7 )
{
struct V_4 * V_4 ;
struct V_11 * V_12 ;
int V_61 ;
V_4 = F_64 ( sizeof( * V_4 ) , V_152 ) ;
if ( ! V_4 ) {
F_29 ( V_7 -> V_7 , L_18 ) ;
return NULL ;
}
V_12 = & V_4 -> V_8 ;
V_4 -> V_45 = V_59 ;
F_65 ( & V_4 -> V_62 ) ;
V_61 = F_66 ( & V_4 -> V_5 , 16 ,
L_19 , F_1 ) ;
if ( V_61 ) {
F_29 ( V_7 -> V_7 , L_20 ) ;
goto V_153;
}
V_61 = F_67 ( V_7 , V_12 , & V_154 ) ;
if ( V_61 < 0 )
goto V_153;
F_68 ( V_12 , & V_155 ) ;
return V_12 ;
V_153:
F_23 ( V_12 ) ;
return NULL ;
}
