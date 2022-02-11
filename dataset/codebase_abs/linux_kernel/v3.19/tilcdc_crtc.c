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
F_24 ( V_4 -> V_46 == V_47 ) ;
F_25 ( V_12 ) ;
F_26 ( & V_4 -> V_5 ) ;
F_27 ( V_4 ) ;
}
static int F_28 ( struct V_11 * V_12 ,
struct V_33 * V_31 ,
struct V_56 * V_57 ,
T_1 V_58 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
if ( V_4 -> V_57 ) {
F_29 ( V_7 -> V_7 , L_1 ) ;
return - V_59 ;
}
V_12 -> V_30 -> V_31 = V_31 ;
V_4 -> V_57 = V_57 ;
F_14 ( V_12 ) ;
return 0 ;
}
static void F_30 ( struct V_11 * V_12 , int V_44 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
if ( V_44 != V_47 )
V_44 = V_60 ;
if ( V_4 -> V_46 == V_44 )
return;
V_4 -> V_46 = V_44 ;
F_8 ( V_7 -> V_7 ) ;
if ( V_44 == V_47 ) {
F_31 ( V_7 -> V_7 ) ;
V_26 ( V_12 ) ;
} else {
V_4 -> V_61 = false ;
F_22 ( V_12 ) ;
if ( V_24 -> V_48 == 2 ) {
int V_62 = F_32 (
V_4 -> V_63 ,
V_4 -> V_61 ,
F_33 ( 50 ) ) ;
if ( V_62 == 0 )
F_29 ( V_7 -> V_7 , L_2 ) ;
}
F_34 ( V_7 -> V_7 ) ;
}
F_13 ( V_7 -> V_7 ) ;
}
static bool F_35 ( struct V_11 * V_12 ,
const struct V_64 * V_44 ,
struct V_64 * V_65 )
{
return true ;
}
static void F_36 ( struct V_11 * V_12 )
{
F_30 ( V_12 , V_60 ) ;
}
static void F_37 ( struct V_11 * V_12 )
{
F_30 ( V_12 , V_47 ) ;
}
static int F_38 ( struct V_11 * V_12 ,
struct V_64 * V_44 ,
struct V_64 * V_65 ,
int V_43 , int V_41 ,
struct V_33 * V_66 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
const struct V_67 * V_68 = V_4 -> V_68 ;
T_1 V_69 , V_70 , V_71 , V_72 , V_73 , V_74 , V_75 ;
int V_62 ;
V_62 = F_39 ( V_12 , V_44 ) ;
if ( F_24 ( V_62 ) )
return V_62 ;
if ( F_24 ( ! V_68 ) )
return - V_76 ;
F_8 ( V_7 -> V_7 ) ;
V_69 = F_40 ( V_7 , V_51 ) & ~ 0x00000770 ;
switch ( V_68 -> V_77 ) {
case 1 :
V_69 |= F_41 ( V_78 ) ;
break;
case 2 :
V_69 |= F_41 ( V_79 ) ;
break;
case 4 :
V_69 |= F_41 ( V_80 ) ;
break;
case 8 :
V_69 |= F_41 ( V_81 ) ;
break;
case 16 :
V_69 |= F_41 ( V_82 ) ;
break;
default:
return - V_76 ;
}
V_69 |= ( V_68 -> V_83 << 8 ) ;
F_9 ( V_7 , V_51 , V_69 ) ;
V_70 = V_44 -> V_84 - V_44 -> V_85 ;
V_71 = V_44 -> V_86 - V_44 -> V_87 ;
V_72 = V_44 -> V_85 - V_44 -> V_86 ;
V_73 = V_44 -> V_88 - V_44 -> V_89 ;
V_74 = V_44 -> V_90 - V_44 -> V_45 ;
V_75 = V_44 -> V_89 - V_44 -> V_90 ;
F_42 ( L_3 ,
V_44 -> V_87 , V_44 -> V_45 , V_70 , V_71 , V_72 , V_73 , V_74 , V_75 ) ;
V_69 = F_40 ( V_7 , V_91 ) & ~ 0x000fff00 ;
V_69 |= F_43 ( V_68 -> V_92 ) |
F_44 ( V_68 -> V_93 ) ;
if ( V_24 -> V_48 == 2 ) {
V_69 &= ~ 0x78000033 ;
V_69 |= ( ( V_71 - 1 ) & 0x300 ) >> 8 ;
V_69 |= ( ( V_70 - 1 ) & 0x300 ) >> 4 ;
V_69 |= ( ( V_72 - 1 ) & 0x3c0 ) << 21 ;
}
F_9 ( V_7 , V_91 , V_69 ) ;
V_69 = ( ( ( V_44 -> V_87 >> 4 ) - 1 ) << 4 ) |
( ( ( V_70 - 1 ) & 0xff ) << 24 ) |
( ( ( V_71 - 1 ) & 0xff ) << 16 ) |
( ( ( V_72 - 1 ) & 0x3f ) << 10 ) ;
if ( V_24 -> V_48 == 2 )
V_69 |= ( ( ( V_44 -> V_87 >> 4 ) - 1 ) & 0x40 ) >> 3 ;
F_9 ( V_7 , V_94 , V_69 ) ;
V_69 = ( ( V_44 -> V_45 - 1 ) & 0x3ff ) |
( ( V_73 & 0xff ) << 24 ) |
( ( V_74 & 0xff ) << 16 ) |
( ( ( V_75 - 1 ) & 0x3f ) << 10 ) ;
F_9 ( V_7 , V_95 , V_69 ) ;
if ( V_24 -> V_48 == 2 ) {
if ( ( V_44 -> V_45 - 1 ) & 0x400 ) {
F_18 ( V_7 , V_91 ,
V_96 ) ;
} else {
F_20 ( V_7 , V_91 ,
V_96 ) ;
}
}
V_69 = F_40 ( V_7 , V_53 ) &
~ ( V_97 | V_98 | V_99 |
V_100 | V_101 | 0x000ff000 ) ;
V_69 |= V_97 ;
if ( V_68 -> V_102 )
V_69 |= V_103 ;
if ( V_24 -> V_48 == 2 ) {
unsigned int V_36 , V_37 ;
F_15 ( V_12 -> V_30 -> V_31 -> V_38 , & V_36 , & V_37 ) ;
switch ( V_37 ) {
case 16 :
break;
case 32 :
V_69 |= V_101 ;
case 24 :
V_69 |= V_100 ;
break;
default:
F_29 ( V_7 -> V_7 , L_4 ) ;
return - V_76 ;
}
}
V_69 |= V_68 -> V_104 < 12 ;
F_9 ( V_7 , V_53 , V_69 ) ;
if ( V_68 -> V_105 )
F_18 ( V_7 , V_91 , V_106 ) ;
else
F_20 ( V_7 , V_91 , V_106 ) ;
if ( V_68 -> V_107 )
F_18 ( V_7 , V_91 , V_108 ) ;
else
F_20 ( V_7 , V_91 , V_108 ) ;
if ( V_68 -> V_109 )
F_18 ( V_7 , V_91 , V_110 ) ;
else
F_20 ( V_7 , V_91 , V_110 ) ;
if ( V_65 -> V_111 & V_112 )
F_18 ( V_7 , V_91 , V_113 ) ;
else
F_20 ( V_7 , V_91 , V_113 ) ;
if ( V_44 -> V_111 & V_114 )
F_18 ( V_7 , V_91 , V_115 ) ;
else
F_20 ( V_7 , V_91 , V_115 ) ;
if ( V_68 -> V_116 )
F_18 ( V_7 , V_53 , V_117 ) ;
else
F_20 ( V_7 , V_53 , V_117 ) ;
F_14 ( V_12 ) ;
F_45 ( V_12 ) ;
F_13 ( V_7 -> V_7 ) ;
return 0 ;
}
static int F_46 ( struct V_11 * V_12 , int V_43 , int V_41 ,
struct V_33 * V_66 )
{
F_14 ( V_12 ) ;
return 0 ;
}
int F_47 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
int V_118 = 0 ;
if ( V_24 -> V_48 == 1 )
V_118 = 1024 ;
else if ( V_24 -> V_48 == 2 )
V_118 = 2048 ;
return V_118 ;
}
int F_39 ( struct V_11 * V_12 , struct V_64 * V_44 )
{
struct V_23 * V_24 = V_12 -> V_7 -> V_25 ;
unsigned int V_119 ;
T_1 V_70 , V_71 , V_72 , V_73 , V_74 , V_75 ;
if ( V_44 -> V_87 > F_47 ( V_12 ) )
return V_120 ;
if ( V_44 -> V_87 & 0xf )
return V_120 ;
if ( V_44 -> V_45 > 2048 )
return V_121 ;
F_42 ( L_5 ,
V_44 -> V_87 , V_44 -> V_45 ,
F_48 ( V_44 ) , V_44 -> clock ) ;
V_70 = V_44 -> V_84 - V_44 -> V_85 ;
V_71 = V_44 -> V_86 - V_44 -> V_87 ;
V_72 = V_44 -> V_85 - V_44 -> V_86 ;
V_73 = V_44 -> V_88 - V_44 -> V_89 ;
V_74 = V_44 -> V_90 - V_44 -> V_45 ;
V_75 = V_44 -> V_89 - V_44 -> V_90 ;
if ( ( V_70 - 1 ) & ~ 0x3ff ) {
F_42 ( L_6 ) ;
return V_122 ;
}
if ( ( V_71 - 1 ) & ~ 0x3ff ) {
F_42 ( L_7 ) ;
return V_122 ;
}
if ( ( V_72 - 1 ) & ~ 0x3ff ) {
F_42 ( L_8 ) ;
return V_123 ;
}
if ( V_73 & ~ 0xff ) {
F_42 ( L_9 ) ;
return V_124 ;
}
if ( V_74 & ~ 0xff ) {
F_42 ( L_10 ) ;
return V_124 ;
}
if ( ( V_75 - 1 ) & ~ 0x3f ) {
F_42 ( L_11 ) ;
return V_125 ;
}
if ( V_44 -> clock > V_24 -> V_126 ) {
F_42 ( L_12 ) ;
return V_127 ;
}
if ( V_44 -> V_87 > V_24 -> V_118 )
return V_128 ;
V_119 = V_44 -> V_87 * V_44 -> V_45 *
F_48 ( V_44 ) ;
if ( V_119 > V_24 -> V_129 ) {
F_42 ( L_13 ) ;
return V_130 ;
}
return V_131 ;
}
void F_49 ( struct V_11 * V_12 ,
const struct V_67 * V_68 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
V_4 -> V_68 = V_68 ;
}
void F_45 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
int V_46 = V_4 -> V_46 ;
unsigned int V_132 , div ;
int V_62 ;
F_8 ( V_7 -> V_7 ) ;
if ( V_46 == V_47 )
F_30 ( V_12 , V_60 ) ;
V_62 = F_50 ( V_24 -> V_133 , V_12 -> V_44 . clock * 1000 * 2 ) ;
if ( V_62 ) {
F_29 ( V_7 -> V_7 , L_14 ,
V_12 -> V_44 . clock ) ;
goto V_134;
}
V_132 = F_51 ( V_24 -> V_135 ) ;
div = V_132 / ( V_12 -> V_44 . clock * 1000 ) ;
F_42 ( L_15 , V_132 , V_12 -> V_44 . clock , div ) ;
F_42 ( L_16 , F_51 ( V_24 -> V_135 ) , F_51 ( V_24 -> V_133 ) ) ;
F_9 ( V_7 , V_136 , F_52 ( div ) |
V_137 ) ;
if ( V_24 -> V_48 == 2 )
F_18 ( V_7 , V_138 ,
V_139 | V_140 |
V_141 ) ;
if ( V_46 == V_47 )
F_30 ( V_12 , V_47 ) ;
V_134:
F_13 ( V_7 -> V_7 ) ;
}
T_2 F_53 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_23 * V_24 = V_7 -> V_25 ;
T_1 V_20 = F_54 ( V_7 ) ;
if ( ( V_20 & V_142 ) && ( V_20 & V_143 ) ) {
F_22 ( V_12 ) ;
F_29 ( V_7 -> V_7 , L_17 , V_20 ) ;
F_55 ( V_7 , V_20 ) ;
V_26 ( V_12 ) ;
} else if ( V_20 & V_144 ) {
F_55 ( V_7 , V_20 ) ;
} else {
struct V_56 * V_57 ;
unsigned long V_111 ;
T_1 V_32 = V_4 -> V_32 & V_20 ;
F_55 ( V_7 , V_20 ) ;
if ( V_32 & V_21 )
F_6 ( V_12 , 0 ) ;
if ( V_32 & V_22 )
F_6 ( V_12 , 1 ) ;
F_56 ( V_7 , 0 ) ;
F_57 ( & V_7 -> V_145 , V_111 ) ;
V_57 = V_4 -> V_57 ;
V_4 -> V_57 = NULL ;
if ( V_57 )
F_58 ( V_7 , 0 , V_57 ) ;
F_59 ( & V_7 -> V_145 , V_111 ) ;
if ( V_32 && ! V_4 -> V_32 )
F_60 ( V_7 , 0 ) ;
}
if ( V_24 -> V_48 == 2 ) {
if ( V_20 & V_146 ) {
V_4 -> V_61 = true ;
F_61 ( & V_4 -> V_63 ) ;
}
F_9 ( V_7 , V_147 , 0 ) ;
}
return V_148 ;
}
void F_62 ( struct V_11 * V_12 , struct V_149 * V_150 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_56 * V_57 ;
struct V_6 * V_7 = V_12 -> V_7 ;
unsigned long V_111 ;
F_57 ( & V_7 -> V_145 , V_111 ) ;
V_57 = V_4 -> V_57 ;
if ( V_57 && V_57 -> V_8 . V_151 == V_150 ) {
V_4 -> V_57 = NULL ;
V_57 -> V_8 . V_152 ( & V_57 -> V_8 ) ;
F_60 ( V_7 , 0 ) ;
}
F_59 ( & V_7 -> V_145 , V_111 ) ;
}
struct V_11 * F_63 ( struct V_6 * V_7 )
{
struct V_4 * V_4 ;
struct V_11 * V_12 ;
int V_62 ;
V_4 = F_64 ( sizeof( * V_4 ) , V_153 ) ;
if ( ! V_4 ) {
F_29 ( V_7 -> V_7 , L_18 ) ;
return NULL ;
}
V_12 = & V_4 -> V_8 ;
V_4 -> V_46 = V_60 ;
F_65 ( & V_4 -> V_63 ) ;
F_66 ( & V_4 -> V_5 ,
L_19 , F_1 ) ;
V_62 = F_67 ( V_7 , V_12 , & V_154 ) ;
if ( V_62 < 0 )
goto V_155;
F_68 ( V_12 , & V_156 ) ;
return V_12 ;
V_155:
F_23 ( V_12 ) ;
return NULL ;
}
