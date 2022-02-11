static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 =
F_2 ( V_2 , struct V_4 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_3 ( & V_7 -> V_9 . V_10 ) ;
F_4 ( V_3 ) ;
F_5 ( & V_7 -> V_9 . V_10 ) ;
}
static void F_6 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 ;
unsigned int V_17 , V_18 ;
T_1 V_19 , V_20 ;
T_2 V_21 ;
F_8 ( V_14 -> V_22 , & V_17 , & V_18 ) ;
V_16 = F_9 ( V_14 , 0 ) ;
V_19 = V_16 -> V_23 + V_14 -> V_24 [ 0 ] +
V_12 -> V_25 * V_14 -> V_26 [ 0 ] +
V_12 -> V_27 * V_18 / 8 ;
V_20 = V_19 + ( V_12 -> V_28 . V_29 * V_14 -> V_26 [ 0 ] ) ;
V_21 = ( T_2 ) ( V_20 - 1 ) << 32 | V_19 ;
F_10 ( V_7 , V_30 , V_21 ) ;
if ( V_4 -> V_31 )
F_11 ( & V_4 -> V_5 ,
V_4 -> V_31 ) ;
V_4 -> V_31 = V_14 ;
}
static void F_12 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = V_7 -> V_34 ;
F_13 ( V_7 , 0xffffffff ) ;
if ( V_33 -> V_35 == 1 ) {
F_14 ( V_7 , V_36 ,
V_37 ) ;
F_14 ( V_7 , V_38 ,
V_39 ) ;
} else {
F_15 ( V_7 , V_40 ,
V_41 |
V_42 |
V_43 | V_44 ) ;
}
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = V_7 -> V_34 ;
if ( V_33 -> V_35 == 1 ) {
F_17 ( V_7 , V_36 ,
V_37 | V_45 ) ;
F_17 ( V_7 , V_38 ,
V_39 ) ;
} else {
F_15 ( V_7 , V_46 ,
V_41 | V_47 |
V_42 |
V_43 | V_44 ) ;
}
}
static void F_18 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
if ( V_33 -> V_35 != 2 )
return;
F_14 ( V_7 , V_48 , V_49 ) ;
F_19 ( 250 , 1000 ) ;
F_17 ( V_7 , V_48 , V_49 ) ;
}
static void F_20 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_4 * V_4 = F_7 ( V_12 ) ;
F_21 ( ! F_22 ( & V_12 -> V_10 ) ) ;
if ( V_4 -> V_50 )
return;
F_23 ( V_7 -> V_7 ) ;
F_18 ( V_12 ) ;
F_12 ( V_7 ) ;
F_17 ( V_7 , V_38 , V_51 ) ;
F_14 ( V_7 , V_36 , F_24 ( V_52 ) ) ;
F_14 ( V_7 , V_36 , V_53 ) ;
F_25 ( V_12 ) ;
V_4 -> V_50 = true ;
}
void F_26 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
F_21 ( ! F_22 ( & V_12 -> V_10 ) ) ;
if ( ! V_4 -> V_50 )
return;
V_4 -> V_54 = false ;
F_17 ( V_7 , V_36 , V_53 ) ;
if ( V_33 -> V_35 == 2 ) {
int V_55 = F_27 ( V_4 -> V_56 ,
V_4 -> V_54 ,
F_28 ( 500 ) ) ;
if ( V_55 == 0 )
F_29 ( V_7 -> V_7 , L_1 ,
V_57 ) ;
}
F_30 ( V_12 ) ;
F_16 ( V_7 ) ;
F_31 ( V_7 -> V_7 ) ;
if ( V_4 -> V_58 ) {
F_11 ( & V_4 -> V_5 ,
V_4 -> V_58 ) ;
V_4 -> V_58 = NULL ;
}
if ( V_4 -> V_31 ) {
F_11 ( & V_4 -> V_5 ,
V_4 -> V_31 ) ;
V_4 -> V_31 = NULL ;
}
F_32 ( & V_4 -> V_5 , V_33 -> V_59 ) ;
V_4 -> V_60 = F_33 ( 0 , 0 ) ;
V_4 -> V_50 = false ;
}
static bool F_34 ( struct V_11 * V_12 )
{
return V_12 -> V_61 && V_12 -> V_61 -> V_62 && V_12 -> V_61 -> V_63 ;
}
static void F_35 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_32 * V_33 = V_12 -> V_7 -> V_34 ;
F_36 ( V_12 , NULL ) ;
F_26 ( V_12 ) ;
F_37 ( V_12 ) ;
F_38 ( V_33 -> V_59 ) ;
F_39 ( V_12 -> V_64 ) ;
F_40 ( V_12 ) ;
F_41 ( & V_4 -> V_5 ) ;
}
int F_42 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_65 * V_66 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
unsigned long V_67 ;
F_21 ( ! F_22 ( & V_12 -> V_10 ) ) ;
if ( V_4 -> V_66 ) {
F_29 ( V_7 -> V_7 , L_2 ) ;
return - V_68 ;
}
F_43 ( V_14 ) ;
V_12 -> V_69 -> V_14 = V_14 ;
F_44 ( & V_4 -> V_70 , V_67 ) ;
if ( V_12 -> V_71 . V_72 && F_45 ( V_4 -> V_60 ) ) {
T_3 V_73 ;
T_4 V_74 ;
V_73 = F_46 ( V_4 -> V_60 ,
1000000 / V_12 -> V_71 . V_72 ) ;
V_74 = F_47 ( F_48 ( V_73 , F_49 () ) ) ;
if ( V_74 < V_75 )
V_4 -> V_58 = V_14 ;
}
if ( V_4 -> V_58 != V_14 )
F_6 ( V_12 , V_14 ) ;
V_4 -> V_66 = V_66 ;
F_50 ( & V_4 -> V_70 , V_67 ) ;
return 0 ;
}
static bool F_51 ( struct V_11 * V_12 ,
const struct V_76 * V_28 ,
struct V_76 * V_77 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
if ( ! V_4 -> V_78 )
return true ;
V_77 -> V_79 = V_28 -> V_80 - V_28 -> V_81 ;
V_77 -> V_67 |= V_82 ;
if ( V_28 -> V_67 & V_83 ) {
V_77 -> V_67 |= V_84 ;
V_77 -> V_67 &= ~ V_83 ;
} else {
V_77 -> V_67 |= V_83 ;
V_77 -> V_67 &= ~ V_84 ;
}
return true ;
}
static void F_52 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
struct V_4 * V_4 = F_7 ( V_12 ) ;
const unsigned V_85 = 2 ;
int V_55 ;
V_55 = F_53 ( V_33 -> V_86 , V_12 -> V_28 . clock * 1000 * V_85 ) ;
if ( V_55 < 0 ) {
F_29 ( V_7 -> V_7 , L_3 ,
V_12 -> V_28 . clock ) ;
return;
}
V_4 -> V_87 = F_54 ( V_33 -> V_86 ) ;
F_55 ( L_4 ,
V_4 -> V_87 , V_12 -> V_28 . clock , V_85 ) ;
F_15 ( V_7 , V_88 , F_56 ( V_85 ) |
V_89 ) ;
if ( V_33 -> V_35 == 2 )
F_14 ( V_7 , V_90 ,
V_91 | V_92 |
V_93 ) ;
}
static void F_57 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
const struct V_94 * V_95 = V_4 -> V_95 ;
T_5 V_96 , V_97 , V_98 , V_99 , V_100 , V_101 , V_102 ;
struct V_76 * V_28 = & V_12 -> V_61 -> V_77 ;
struct V_13 * V_14 = V_12 -> V_69 -> V_61 -> V_14 ;
F_21 ( ! F_22 ( & V_12 -> V_10 ) ) ;
if ( F_21 ( ! V_95 ) )
return;
if ( F_21 ( ! V_14 ) )
return;
V_96 = F_58 ( V_7 , V_38 ) & ~ 0x00000770 ;
switch ( V_95 -> V_103 ) {
case 1 :
V_96 |= F_59 ( V_104 ) ;
break;
case 2 :
V_96 |= F_59 ( V_105 ) ;
break;
case 4 :
V_96 |= F_59 ( V_106 ) ;
break;
case 8 :
V_96 |= F_59 ( V_107 ) ;
break;
case 16 :
V_96 |= F_59 ( V_108 ) ;
break;
default:
F_29 ( V_7 -> V_7 , L_5 ) ;
return;
}
V_96 |= ( V_95 -> V_109 << 8 ) ;
F_15 ( V_7 , V_38 , V_96 ) ;
V_97 = V_28 -> V_110 - V_28 -> V_80 ;
V_98 = V_28 -> V_81 - V_28 -> V_111 ;
V_99 = V_28 -> V_80 - V_28 -> V_81 ;
V_100 = V_28 -> V_112 - V_28 -> V_113 ;
V_101 = V_28 -> V_114 - V_28 -> V_29 ;
V_102 = V_28 -> V_113 - V_28 -> V_114 ;
F_55 ( L_6 ,
V_28 -> V_111 , V_28 -> V_29 , V_97 , V_98 , V_99 , V_100 , V_101 , V_102 ) ;
V_96 = F_58 ( V_7 , V_115 ) & ~ 0x000fff00 ;
V_96 |= F_60 ( V_95 -> V_116 ) |
F_61 ( V_95 -> V_117 ) ;
if ( V_33 -> V_35 == 2 ) {
V_96 &= ~ 0x78000033 ;
V_96 |= ( ( V_98 - 1 ) & 0x300 ) >> 8 ;
V_96 |= ( ( V_97 - 1 ) & 0x300 ) >> 4 ;
V_96 |= ( ( V_99 - 1 ) & 0x3c0 ) << 21 ;
}
F_15 ( V_7 , V_115 , V_96 ) ;
V_96 = ( ( ( V_28 -> V_111 >> 4 ) - 1 ) << 4 ) |
( ( ( V_97 - 1 ) & 0xff ) << 24 ) |
( ( ( V_98 - 1 ) & 0xff ) << 16 ) |
( ( ( V_99 - 1 ) & 0x3f ) << 10 ) ;
if ( V_33 -> V_35 == 2 )
V_96 |= ( ( ( V_28 -> V_111 >> 4 ) - 1 ) & 0x40 ) >> 3 ;
F_15 ( V_7 , V_118 , V_96 ) ;
V_96 = ( ( V_28 -> V_29 - 1 ) & 0x3ff ) |
( ( V_100 & 0xff ) << 24 ) |
( ( V_101 & 0xff ) << 16 ) |
( ( ( V_102 - 1 ) & 0x3f ) << 10 ) ;
F_15 ( V_7 , V_119 , V_96 ) ;
if ( V_33 -> V_35 == 2 ) {
if ( ( V_28 -> V_29 - 1 ) & 0x400 ) {
F_14 ( V_7 , V_115 ,
V_120 ) ;
} else {
F_17 ( V_7 , V_115 ,
V_120 ) ;
}
}
V_96 = F_58 ( V_7 , V_36 ) &
~ ( V_121 | V_122 | V_123 |
V_124 | V_125 |
0x000ff000 ) ;
V_96 |= V_121 ;
if ( V_95 -> V_126 )
V_96 |= V_127 ;
if ( V_33 -> V_35 == 2 ) {
unsigned int V_17 , V_18 ;
F_8 ( V_14 -> V_22 , & V_17 , & V_18 ) ;
switch ( V_18 ) {
case 16 :
break;
case 32 :
V_96 |= V_125 ;
case 24 :
V_96 |= V_124 ;
break;
default:
F_29 ( V_7 -> V_7 , L_7 ) ;
return;
}
}
V_96 |= V_95 -> V_128 < 12 ;
F_15 ( V_7 , V_36 , V_96 ) ;
if ( V_95 -> V_129 )
F_14 ( V_7 , V_115 , V_130 ) ;
else
F_17 ( V_7 , V_115 , V_130 ) ;
if ( V_95 -> V_131 )
F_14 ( V_7 , V_115 , V_132 ) ;
else
F_17 ( V_7 , V_115 , V_132 ) ;
if ( V_95 -> V_133 )
F_14 ( V_7 , V_115 , V_134 ) ;
else
F_17 ( V_7 , V_115 , V_134 ) ;
if ( V_28 -> V_67 & V_83 )
F_14 ( V_7 , V_115 , V_135 ) ;
else
F_17 ( V_7 , V_115 , V_135 ) ;
if ( V_28 -> V_67 & V_136 )
F_14 ( V_7 , V_115 , V_137 ) ;
else
F_17 ( V_7 , V_115 , V_137 ) ;
if ( V_95 -> V_138 )
F_14 ( V_7 , V_36 , V_139 ) ;
else
F_17 ( V_7 , V_36 , V_139 ) ;
F_43 ( V_14 ) ;
F_6 ( V_12 , V_14 ) ;
F_52 ( V_12 ) ;
V_12 -> V_71 = V_12 -> V_61 -> V_77 ;
}
static int F_62 ( struct V_11 * V_12 ,
struct V_140 * V_61 )
{
struct V_76 * V_28 = & V_61 -> V_28 ;
int V_55 ;
if ( ! V_61 -> V_63 )
return 0 ;
if ( V_61 -> V_61 -> V_141 [ 0 ] . V_142 != V_12 -> V_69 ||
V_61 -> V_61 -> V_141 [ 0 ] . V_61 == NULL ||
V_61 -> V_61 -> V_141 [ 0 ] . V_61 -> V_12 != V_12 ) {
F_63 ( V_12 -> V_7 -> V_7 , L_8 ) ;
return - V_143 ;
}
V_55 = F_64 ( V_12 , V_28 ) ;
if ( V_55 ) {
F_63 ( V_12 -> V_7 -> V_7 , L_9 , V_28 -> V_144 ) ;
return - V_143 ;
}
return 0 ;
}
int F_65 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
int V_145 = 0 ;
if ( V_33 -> V_35 == 1 )
V_145 = 1024 ;
else if ( V_33 -> V_35 == 2 )
V_145 = 2048 ;
return V_145 ;
}
int F_64 ( struct V_11 * V_12 , struct V_76 * V_28 )
{
struct V_32 * V_33 = V_12 -> V_7 -> V_34 ;
unsigned int V_146 ;
T_5 V_97 , V_98 , V_99 , V_100 , V_101 , V_102 ;
if ( V_28 -> V_111 > F_65 ( V_12 ) )
return V_147 ;
if ( V_28 -> V_111 & 0xf )
return V_147 ;
if ( V_28 -> V_29 > 2048 )
return V_148 ;
F_55 ( L_10 ,
V_28 -> V_111 , V_28 -> V_29 ,
F_66 ( V_28 ) , V_28 -> clock ) ;
V_97 = V_28 -> V_110 - V_28 -> V_80 ;
V_98 = V_28 -> V_81 - V_28 -> V_111 ;
V_99 = V_28 -> V_80 - V_28 -> V_81 ;
V_100 = V_28 -> V_112 - V_28 -> V_113 ;
V_101 = V_28 -> V_114 - V_28 -> V_29 ;
V_102 = V_28 -> V_113 - V_28 -> V_114 ;
if ( ( V_97 - 1 ) & ~ 0x3ff ) {
F_55 ( L_11 ) ;
return V_149 ;
}
if ( ( V_98 - 1 ) & ~ 0x3ff ) {
F_55 ( L_12 ) ;
return V_149 ;
}
if ( ( V_99 - 1 ) & ~ 0x3ff ) {
F_55 ( L_13 ) ;
return V_150 ;
}
if ( V_100 & ~ 0xff ) {
F_55 ( L_14 ) ;
return V_151 ;
}
if ( V_101 & ~ 0xff ) {
F_55 ( L_15 ) ;
return V_151 ;
}
if ( ( V_102 - 1 ) & ~ 0x3f ) {
F_55 ( L_16 ) ;
return V_152 ;
}
if ( V_28 -> clock > V_33 -> V_153 ) {
F_55 ( L_17 ) ;
return V_154 ;
}
if ( V_28 -> V_111 > V_33 -> V_145 )
return V_155 ;
V_146 = V_28 -> V_111 * V_28 -> V_29 *
F_66 ( V_28 ) ;
if ( V_146 > V_33 -> V_156 ) {
F_55 ( L_18 ) ;
return V_157 ;
}
return V_158 ;
}
void F_67 ( struct V_11 * V_12 ,
const struct V_94 * V_95 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
V_4 -> V_95 = V_95 ;
}
void F_68 ( struct V_11 * V_12 ,
bool V_78 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
V_4 -> V_78 = V_78 ;
}
void F_69 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
struct V_4 * V_4 = F_7 ( V_12 ) ;
F_36 ( V_12 , NULL ) ;
if ( V_4 -> V_87 != F_54 ( V_33 -> V_86 ) ) {
if ( F_34 ( V_12 ) ) {
F_23 ( V_7 -> V_7 ) ;
F_26 ( V_12 ) ;
F_52 ( V_12 ) ;
F_20 ( V_12 ) ;
F_31 ( V_7 -> V_7 ) ;
}
}
F_37 ( V_12 ) ;
}
T_6 F_70 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
T_5 V_159 ;
V_159 = F_71 ( V_7 ) ;
F_13 ( V_7 , V_159 ) ;
if ( V_159 & V_160 ) {
unsigned long V_67 ;
bool V_161 = false ;
T_3 V_162 ;
V_162 = F_49 () ;
F_32 ( & V_4 -> V_5 , V_33 -> V_59 ) ;
F_44 ( & V_4 -> V_70 , V_67 ) ;
V_4 -> V_60 = V_162 ;
if ( V_4 -> V_58 ) {
F_6 ( V_12 , V_4 -> V_58 ) ;
V_4 -> V_58 = NULL ;
V_161 = true ;
}
F_50 ( & V_4 -> V_70 , V_67 ) ;
F_72 ( V_12 ) ;
if ( ! V_161 ) {
struct V_65 * V_66 ;
F_44 ( & V_7 -> V_163 , V_67 ) ;
V_66 = V_4 -> V_66 ;
V_4 -> V_66 = NULL ;
if ( V_66 )
F_73 ( V_12 , V_66 ) ;
F_50 ( & V_7 -> V_163 , V_67 ) ;
}
if ( V_4 -> V_164 )
V_4 -> V_165 = 0 ;
else
V_4 -> V_164 = true ;
}
if ( V_159 & V_166 )
F_74 ( V_7 -> V_7 , L_19 ,
V_57 , V_159 ) ;
if ( V_33 -> V_35 == 2 ) {
if ( V_159 & V_43 ) {
V_4 -> V_54 = true ;
F_75 ( & V_4 -> V_56 ) ;
}
if ( V_159 & V_44 ) {
F_74 ( V_7 -> V_7 , L_20 ,
V_57 , V_159 ) ;
V_4 -> V_164 = false ;
if ( V_4 -> V_165 ++ >
V_167 ) {
F_29 ( V_7 -> V_7 , L_21 , V_57 , V_159 ) ;
F_15 ( V_7 , V_46 ,
V_44 ) ;
}
}
F_15 ( V_7 , V_168 , 0 ) ;
}
return V_169 ;
}
struct V_11 * F_76 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = V_7 -> V_34 ;
struct V_4 * V_4 ;
struct V_11 * V_12 ;
int V_55 ;
V_4 = F_77 ( V_7 -> V_7 , sizeof( * V_4 ) , V_170 ) ;
if ( ! V_4 ) {
F_29 ( V_7 -> V_7 , L_22 ) ;
return NULL ;
}
V_12 = & V_4 -> V_8 ;
V_55 = F_78 ( V_7 , & V_4 -> V_69 ) ;
if ( V_55 < 0 )
goto V_171;
F_79 ( & V_4 -> V_56 ) ;
F_80 ( & V_4 -> V_5 ,
L_23 , F_1 ) ;
F_81 ( & V_4 -> V_70 ) ;
V_55 = F_82 ( V_7 , V_12 ,
& V_4 -> V_69 ,
NULL ,
& V_172 ,
L_24 ) ;
if ( V_55 < 0 )
goto V_171;
F_83 ( V_12 , & V_173 ) ;
if ( V_33 -> V_174 ) {
struct V_175 * V_176 =
F_84 ( V_7 -> V_7 -> V_177 , L_25 ) ;
if ( V_176 ) {
V_12 -> V_64 = F_84 ( V_176 , L_26 ) ;
F_39 ( V_176 ) ;
} else {
V_12 -> V_64 =
F_84 ( V_7 -> V_7 -> V_177 , L_26 ) ;
}
if ( ! V_12 -> V_64 ) {
F_29 ( V_7 -> V_7 , L_27 ,
V_7 -> V_7 -> V_177 -> V_178 ) ;
goto V_171;
}
}
return V_12 ;
V_171:
F_35 ( V_12 ) ;
return NULL ;
}
