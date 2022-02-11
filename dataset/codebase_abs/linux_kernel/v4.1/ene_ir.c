static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 >> 8 , V_2 -> V_4 + V_5 ) ;
F_2 ( V_3 & 0xFF , V_2 -> V_4 + V_6 ) ;
}
static T_2 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_7 ;
F_1 ( V_2 , V_3 ) ;
V_7 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_5 ( L_1 , V_3 , V_7 ) ;
return V_7 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_9 )
{
F_5 ( L_2 , V_3 , V_9 ) ;
F_1 ( V_2 , V_3 ) ;
F_2 ( V_9 , V_2 -> V_4 + V_8 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_10 )
{
F_5 ( L_3 , V_3 , V_10 ) ;
F_1 ( V_2 , V_3 ) ;
F_2 ( F_4 ( V_2 -> V_4 + V_8 ) | V_10 , V_2 -> V_4 + V_8 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_10 )
{
F_5 ( L_4 , V_3 , V_10 ) ;
F_1 ( V_2 , V_3 ) ;
F_2 ( F_4 ( V_2 -> V_4 + V_8 ) & ~ V_10 , V_2 -> V_4 + V_8 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_10 ,
bool V_11 )
{
if ( V_11 )
F_7 ( V_2 , V_3 , V_10 ) ;
else
F_8 ( V_2 , V_3 , V_10 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_12 , V_13 ;
T_2 V_14 , V_15 ;
T_2 V_16 , V_17 ;
F_8 ( V_2 , V_18 , V_19 ) ;
V_12 = F_3 ( V_2 , V_20 ) ;
V_13 = F_3 ( V_2 , V_21 ) ;
F_7 ( V_2 , V_18 , V_19 ) ;
V_14 = F_3 ( V_2 , V_22 ) ;
V_15 = F_3 ( V_2 , V_23 ) ;
V_2 -> V_24 = ( F_3 ( V_2 , V_25 ) << 4 ) +
( F_3 ( V_2 , V_26 ) >> 4 ) ;
if ( V_27 != V_28 )
V_2 -> V_29 =
V_2 -> V_24 == V_30 ? 2 : 4 ;
if ( V_14 == 0xFF ) {
F_11 ( L_5 ) ;
F_11 ( L_6 ) ;
F_11 ( L_7 ) ;
return - V_31 ;
}
F_12 ( L_8 ,
V_12 , V_13 , V_15 , V_14 ) ;
F_12 ( L_9 , V_2 -> V_24 ) ;
if ( V_12 == 0x33 ) {
F_11 ( L_10 ) ;
return - V_31 ;
}
if ( V_12 == 0x39 && V_13 == 0x26 && V_14 == 0xC0 ) {
V_2 -> V_14 = V_32 ;
F_12 ( L_11 ) ;
} else if ( V_15 == 0x24 && V_14 == 0xC0 ) {
V_2 -> V_14 = V_33 ;
F_12 ( L_12 ) ;
} else {
V_2 -> V_14 = V_34 ;
F_12 ( L_13 ) ;
}
if ( V_2 -> V_14 < V_32 )
return 0 ;
V_17 = F_3 ( V_2 , V_35 ) ;
V_16 = F_3 ( V_2 , V_36 ) ;
F_12 ( L_14 , V_17 , V_16 ) ;
V_2 -> V_37 = ! ! ( V_16 & V_38 ) ;
V_2 -> V_39 = ! ! ( V_16 & V_40 ) ;
V_2 -> V_41 = ! ! ( V_17 & V_42 ) ;
if ( V_2 -> V_39 )
V_2 -> V_43 = ! ! ( V_16 & V_44 ) ;
F_12 ( L_15 ) ;
if ( V_2 -> V_39 ) {
F_12 ( L_16 ) ;
F_12 ( L_17 ) ;
F_12 ( L_18 ) ;
F_12 ( L_19 ) ;
F_12 ( L_20 ) ;
F_12 ( L_21 ) ;
F_12 ( L_22 ,
V_2 -> V_37 ? L_23 : L_24 ) ;
if ( V_2 -> V_43 )
F_12 ( L_25 ) ;
}
if ( ! V_2 -> V_43 )
F_12 ( L_26 ,
V_2 -> V_37 ? L_24 : L_23 ) ;
if ( V_2 -> V_41 )
F_12 ( L_27 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_45 ;
F_14 ( V_2 ) ;
V_2 -> V_46 = V_2 -> V_47 ;
if ( ! V_2 -> V_41 ) {
V_2 -> V_48 = V_49 * 2 ;
return;
}
V_45 = F_3 ( V_2 , V_50 ) ;
V_45 |= F_3 ( V_2 , V_50 + 1 ) << 8 ;
V_2 -> V_51 = V_45 ;
V_2 -> V_52 = F_3 ( V_2 , V_50 + 2 ) ;
V_45 = F_3 ( V_2 , V_50 + 3 ) ;
V_45 |= F_3 ( V_2 , V_50 + 4 ) << 8 ;
V_2 -> V_53 = V_45 ;
V_2 -> V_54 = F_3 ( V_2 , V_50 + 5 ) ;
V_2 -> V_48 = V_2 -> V_52 + V_2 -> V_54 + 8 ;
F_12 ( L_28 ) ;
F_12 ( L_29 ,
V_2 -> V_51 , V_2 -> V_52 ) ;
F_12 ( L_29 ,
V_2 -> V_53 , V_2 -> V_54 ) ;
F_12 ( L_30 , V_2 -> V_48 ) ;
if ( V_2 -> V_48 > 64 || V_2 -> V_48 < 16 )
goto error;
if ( V_2 -> V_51 > 0xFBFC ||
V_2 -> V_51 < 0xEC00 )
goto error;
if ( V_2 -> V_53 > 0xFBFC ||
V_2 -> V_53 < 0xEC00 )
goto error;
if ( V_2 -> V_46 > V_2 -> V_48 )
goto error;
F_7 ( V_2 , V_35 , V_55 ) ;
return;
error:
F_11 ( L_31 ) ;
V_2 -> V_41 = false ;
F_8 ( V_2 , V_35 , V_55 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_41 )
return;
F_6 ( V_2 , V_50 + 0 ,
V_2 -> V_51 & 0xFF ) ;
F_6 ( V_2 , V_50 + 1 ,
V_2 -> V_51 >> 8 ) ;
F_6 ( V_2 , V_50 + 2 , V_2 -> V_52 ) ;
F_6 ( V_2 , V_50 + 3 ,
V_2 -> V_53 & 0xFF ) ;
F_6 ( V_2 , V_50 + 4 ,
V_2 -> V_53 >> 8 ) ;
F_6 ( V_2 , V_50 + 5 ,
V_2 -> V_54 ) ;
F_8 ( V_2 , V_35 , V_55 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 )
V_2 -> V_47 = F_3 ( V_2 , V_56 ) ;
else
V_2 -> V_47 = F_3 ( V_2 , V_36 )
& V_57 ? 0 : V_49 ;
F_16 ( L_32 ,
V_2 -> V_47 , V_2 -> V_46 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_46 ;
if ( V_2 -> V_46 == V_2 -> V_47 ) {
F_16 ( L_33 ) ;
F_14 ( V_2 ) ;
}
if ( V_2 -> V_46 == V_2 -> V_47 ) {
F_16 ( L_34 , V_2 -> V_46 ) ;
return 0 ;
}
F_16 ( L_35 , V_2 -> V_46 ) ;
V_46 = V_2 -> V_46 ;
V_2 -> V_46 ++ ;
if ( V_2 -> V_46 == V_2 -> V_48 )
V_2 -> V_46 = 0 ;
F_16 ( L_36 , V_2 -> V_46 ) ;
if ( V_46 < 8 ) {
F_16 ( L_37 , V_46 ) ;
return V_50 + V_46 ;
}
V_46 -= 8 ;
if ( V_46 < V_2 -> V_52 ) {
F_16 ( L_38 , V_46 ) ;
return V_2 -> V_51 + V_46 ;
}
V_46 -= V_2 -> V_52 ;
if ( V_46 < V_2 -> V_54 ) {
F_16 ( L_39 , V_46 ) ;
return V_2 -> V_53 + V_46 ;
}
F_18 ( L_40 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_58 ) ;
int V_59 , V_60 ;
int V_61 = F_3 ( V_2 , V_62 ) ;
int V_63 = F_3 ( V_2 , V_64 ) ;
if ( ! ( V_61 & V_65 ) )
return;
V_61 &= ~ V_65 ;
if ( ! V_61 )
return;
F_18 ( L_41 , V_61 ) ;
F_18 ( L_42 , V_63 ) ;
V_59 = 2000000 / V_61 ;
V_60 = ( V_63 * 100 ) / V_61 ;
F_18 ( L_43 ,
V_59 , V_60 ) ;
if ( V_2 -> V_66 ) {
V_58 . V_67 = true ;
V_58 . V_59 = V_59 ;
V_58 . V_60 = V_60 ;
F_21 ( V_2 -> V_68 , & V_58 ) ;
}
}
static void F_22 ( struct V_1 * V_2 , bool V_69 )
{
F_9 ( V_2 , V_70 ,
V_71 | V_72 , V_69 ) ;
}
static void F_23 ( struct V_1 * V_2 , bool V_73 )
{
F_9 ( V_2 , V_74 , V_75 , V_73 ) ;
}
static void F_24 ( struct V_1 * V_2 , bool V_69 )
{
if ( ! V_2 -> V_43 )
return;
if ( ! V_69 )
F_6 ( V_2 , V_76 , 0 ) ;
else {
F_6 ( V_2 , V_76 , V_77 ) ;
F_6 ( V_2 , V_78 , V_79 ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
bool V_80 = V_2 -> V_81 ||
V_2 -> V_66 ;
int V_82 = 0 ;
F_18 ( L_44 , V_80 ) ;
F_6 ( V_2 , V_74 , 0x00 ) ;
if ( V_27 == V_28 )
V_82 =
V_2 -> V_24 == V_30 ? 1 : 2 ;
F_6 ( V_2 , V_83 ,
( V_27 + V_82 ) |
V_84 ) ;
if ( V_2 -> V_14 < V_32 )
goto V_85;
if ( V_80 ) {
F_26 ( ! V_2 -> V_39 ) ;
F_23 ( V_2 , ! V_2 -> V_37 ) ;
V_2 -> V_86 = false ;
F_7 ( V_2 , V_70 , V_87 ) ;
F_6 ( V_2 , V_88 , 0x63 ) ;
F_9 ( V_2 , V_74 , V_89 ,
V_2 -> V_66 || V_90 ) ;
} else {
if ( V_2 -> V_43 )
V_2 -> V_86 = true ;
else
F_23 ( V_2 , V_2 -> V_37 ) ;
F_8 ( V_2 , V_70 , V_87 ) ;
F_8 ( V_2 , V_74 , V_89 ) ;
}
V_85:
if ( V_2 -> V_86 ) {
V_2 -> V_68 -> V_91 = F_27 ( V_92 ) ;
V_2 -> V_68 -> V_93 = V_2 -> V_68 -> V_94 =
F_27 ( V_95 *
V_92 ) ;
} else {
V_2 -> V_68 -> V_91 = F_27 ( V_27 ) ;
V_2 -> V_68 -> V_93 = F_27 ( 127 * V_27 ) ;
V_2 -> V_68 -> V_94 = F_27 ( 200000 ) ;
}
if ( V_2 -> V_39 )
V_2 -> V_68 -> V_96 = F_27 ( V_27 ) ;
if ( V_2 -> V_68 -> V_97 > V_2 -> V_68 -> V_94 )
V_2 -> V_68 -> V_97 = V_2 -> V_68 -> V_94 ;
if ( V_2 -> V_68 -> V_97 < V_2 -> V_68 -> V_93 )
V_2 -> V_68 -> V_97 = V_2 -> V_68 -> V_93 ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_2 V_98 ;
if ( V_2 -> V_14 < V_32 ) {
F_6 ( V_2 , V_99 , V_2 -> V_100 << 1 ) ;
F_6 ( V_2 , V_101 , 0x01 ) ;
} else {
V_98 = F_3 ( V_2 , V_102 ) & 0xF0 ;
V_98 |= V_103 ;
V_98 &= ~ V_104 ;
V_98 |= ( V_2 -> V_100 & V_105 ) ;
F_6 ( V_2 , V_102 , V_98 ) ;
}
F_24 ( V_2 , V_2 -> V_86 ) ;
F_22 ( V_2 , ! V_2 -> V_86 ) ;
F_29 ( V_2 ) ;
F_7 ( V_2 , V_35 , V_106 | V_107 ) ;
F_30 ( V_2 -> V_68 , true ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
V_2 -> V_108 = true ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_22 ( V_2 , false ) ;
F_24 ( V_2 , false ) ;
F_8 ( V_2 , V_35 , V_106 | V_107 ) ;
F_30 ( V_2 -> V_68 , true ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
V_2 -> V_108 = false ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_70 , V_71 ) ;
F_7 ( V_2 , V_70 , V_71 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_2 V_109 ;
unsigned long V_110 ;
F_36 ( & V_2 -> V_111 , V_110 ) ;
F_9 ( V_2 , V_70 ,
V_112 , V_2 -> V_113 > 0 ) ;
if ( ! V_2 -> V_113 )
goto V_114;
F_37 ( V_2 -> V_115 >= 100 || V_2 -> V_115 <= 0 ) ;
V_109 = V_2 -> V_113 / ( 100 / V_2 -> V_115 ) ;
if ( ! V_109 )
V_109 = 1 ;
F_18 ( L_45 , V_2 -> V_113 ) ;
F_18 ( L_46 , V_109 ) ;
F_6 ( V_2 , V_116 , V_2 -> V_113 | V_117 ) ;
F_6 ( V_2 , V_118 , V_109 ) ;
V_114:
F_38 ( & V_2 -> V_111 , V_110 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned long V_110 ;
F_36 ( & V_2 -> V_111 , V_110 ) ;
F_9 ( V_2 , V_119 , V_120 ,
! ! ( V_2 -> V_121 & 0x01 ) ) ;
F_9 ( V_2 , V_122 , V_123 ,
! ! ( V_2 -> V_121 & 0x02 ) ) ;
F_38 ( & V_2 -> V_111 , V_110 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_2 V_124 = F_3 ( V_2 , V_70 ) ;
T_2 V_125 = F_3 ( V_2 , V_36 ) ;
V_2 -> V_126 = V_124 ;
if ( V_125 & V_127 )
F_18 ( L_47 ) ;
if ( V_125 & V_128 )
F_18 ( L_48 ) ;
if ( ! ( V_125 & ( V_127 | V_128 ) ) )
F_11 ( L_49 ) ;
if ( V_2 -> V_14 == V_32 )
V_124 &= ~ V_71 ;
V_124 |= V_129 | V_130 ;
F_6 ( V_2 , V_70 , V_124 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_70 , V_2 -> V_126 ) ;
V_2 -> V_131 = NULL ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_2 V_132 ;
T_3 V_133 ;
bool V_134 = V_2 -> V_135 ;
if ( ! V_2 -> V_131 ) {
F_11 ( L_50 ) ;
return;
}
if ( ! V_2 -> V_136 ) {
if ( V_2 -> V_137 == V_2 -> V_138 ) {
if ( ! V_2 -> V_139 ) {
F_18 ( L_51 ) ;
V_2 -> V_139 = true ;
goto exit;
} else {
F_18 ( L_52 ) ;
F_41 ( V_2 ) ;
F_43 ( & V_2 -> V_140 ) ;
return;
}
}
V_133 = V_2 -> V_131 [ V_2 -> V_137 ++ ] ;
V_2 -> V_135 = ! V_2 -> V_135 ;
V_2 -> V_136 = F_44 ( V_133 , V_27 ) ;
if ( ! V_2 -> V_136 )
V_2 -> V_136 = 1 ;
}
V_132 = F_45 ( V_2 -> V_136 , ( unsigned int ) V_141 ) ;
V_2 -> V_136 -= V_132 ;
F_18 ( L_53 , V_132 * V_27 ,
V_134 ? L_54 : L_55 ) ;
if ( V_134 )
V_132 |= V_142 ;
F_6 ( V_2 ,
V_2 -> V_143 ? V_144 : V_145 , V_132 ) ;
V_2 -> V_143 = ! V_2 -> V_143 ;
exit:
if ( V_146 )
F_46 ( & V_2 -> V_147 , V_148 + V_149 / 500 ) ;
}
static void F_47 ( unsigned long V_150 )
{
struct V_1 * V_2 = (struct V_1 * ) V_150 ;
unsigned long V_110 ;
F_36 ( & V_2 -> V_111 , V_110 ) ;
F_42 ( V_2 ) ;
F_38 ( & V_2 -> V_111 , V_110 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_2 V_151 ;
T_2 V_152 , V_153 ;
int V_7 = 0 ;
V_153 = F_3 ( V_2 , V_36 ) ;
if ( V_2 -> V_14 < V_32 ) {
V_151 = F_3 ( V_2 , V_154 ) ;
if ( ! ( V_151 & V_155 ) )
return 0 ;
F_8 ( V_2 , V_154 , V_155 ) ;
return V_156 ;
}
V_151 = F_3 ( V_2 , V_102 ) ;
if ( ! ( V_151 & V_104 ) )
return 0 ;
F_6 ( V_2 , V_102 , V_151 & ~ V_104 ) ;
F_6 ( V_2 , V_102 , V_151 & ~ V_104 ) ;
if ( V_153 & V_157 ) {
V_7 |= V_156 ;
F_6 ( V_2 , V_36 , V_153 & ~ V_157 ) ;
}
V_152 = F_3 ( V_2 , V_35 ) ;
if ( V_152 & V_158 ) {
F_6 ( V_2 , V_35 , V_152 & ~ V_158 ) ;
V_7 |= V_159 ;
}
return V_7 ;
}
static T_4 F_48 ( int V_100 , void * V_150 )
{
T_1 V_160 , V_3 ;
int V_161 , V_151 ;
bool V_134 ;
unsigned long V_110 ;
T_4 V_7 = V_162 ;
struct V_1 * V_2 = (struct V_1 * ) V_150 ;
F_20 ( V_58 ) ;
F_36 ( & V_2 -> V_111 , V_110 ) ;
F_16 ( L_56 ) ;
F_14 ( V_2 ) ;
V_151 = F_29 ( V_2 ) ;
if ( ! V_151 )
goto V_114;
V_7 = V_163 ;
if ( V_151 & V_159 ) {
F_16 ( L_57 ) ;
if ( ! V_2 -> V_39 ) {
F_18 ( L_58 ) ;
goto V_114;
}
F_42 ( V_2 ) ;
}
if ( ! ( V_151 & V_156 ) )
goto V_114;
F_16 ( L_59 ) ;
if ( V_2 -> V_39 )
F_19 ( V_2 ) ;
if ( ! V_2 -> V_41 )
V_2 -> V_46 = V_2 -> V_47 == 0 ? V_49 : 0 ;
while ( 1 ) {
V_3 = F_17 ( V_2 ) ;
F_16 ( L_60 , V_3 ) ;
if ( ! V_3 )
break;
V_160 = F_3 ( V_2 , V_3 ) ;
if ( V_2 -> V_86 ) {
int V_164 = V_165 - V_50 ;
V_160 |= F_3 ( V_2 , V_3 + V_164 ) << 8 ;
V_134 = V_160 & V_166 ;
V_160 &= V_95 ;
V_161 = V_160 * V_92 ;
} else {
V_134 = ! ( V_160 & V_167 ) ;
V_160 &= ~ V_167 ;
V_161 = V_160 * V_27 ;
if ( V_2 -> V_29 ) {
V_161 *= 100 ;
V_161 /= ( 100 + V_2 -> V_29 ) ;
}
}
if ( ! V_2 -> V_41 && ! V_161 ) {
V_2 -> V_46 = V_2 -> V_47 ;
continue;
}
F_18 ( L_61 , V_161 , V_134 ? L_54 : L_55 ) ;
V_58 . V_168 = F_27 ( V_161 ) ;
V_58 . V_134 = V_134 ;
F_49 ( V_2 -> V_68 , & V_58 ) ;
}
F_50 ( V_2 -> V_68 ) ;
V_114:
F_38 ( & V_2 -> V_111 , V_110 ) ;
return V_7 ;
}
static void F_51 ( struct V_1 * V_2 )
{
V_2 -> V_113 = 32 ;
V_2 -> V_115 = 50 ;
V_2 -> V_121 = 0x03 ;
V_2 -> V_81 = V_169 ;
V_2 -> V_68 -> V_97 = F_27 ( 150000 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_39 ) {
F_35 ( V_2 ) ;
F_39 ( V_2 ) ;
}
F_25 ( V_2 ) ;
}
static int F_53 ( struct V_170 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_171 ;
unsigned long V_110 ;
F_36 ( & V_2 -> V_111 , V_110 ) ;
F_31 ( V_2 ) ;
F_38 ( & V_2 -> V_111 , V_110 ) ;
return 0 ;
}
static void F_54 ( struct V_170 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_171 ;
unsigned long V_110 ;
F_36 ( & V_2 -> V_111 , V_110 ) ;
F_33 ( V_2 ) ;
F_38 ( & V_2 -> V_111 , V_110 ) ;
}
static int F_55 ( struct V_170 * V_68 , T_3 V_172 )
{
struct V_1 * V_2 = V_68 -> V_171 ;
F_18 ( L_62 , V_172 ) ;
if ( ! V_172 || V_172 & ~ 0x03 ) {
F_18 ( L_63 ) ;
return 2 ;
}
V_2 -> V_121 = V_172 ;
F_39 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_170 * V_68 , T_3 V_59 )
{
struct V_1 * V_2 = V_68 -> V_171 ;
T_3 V_61 ;
F_18 ( L_64 , V_59 ) ;
if ( V_59 == 0 )
return - V_173 ;
V_61 = 2000000 / V_59 ;
if ( V_61 && ( V_61 > V_174 ||
V_61 < V_175 ) ) {
F_18 ( L_65 ,
2000 / V_175 , 2000 / V_174 ) ;
return - 1 ;
}
V_2 -> V_113 = V_61 ;
F_35 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_170 * V_68 , T_3 V_60 )
{
struct V_1 * V_2 = V_68 -> V_171 ;
F_18 ( L_66 , V_60 ) ;
V_2 -> V_115 = V_60 ;
F_35 ( V_2 ) ;
return 0 ;
}
static int F_58 ( struct V_170 * V_68 , int V_69 )
{
struct V_1 * V_2 = V_68 -> V_171 ;
unsigned long V_110 ;
if ( V_69 == V_2 -> V_81 )
return 0 ;
F_36 ( & V_2 -> V_111 , V_110 ) ;
V_2 -> V_81 = V_69 ;
F_33 ( V_2 ) ;
F_25 ( V_2 ) ;
F_31 ( V_2 ) ;
F_38 ( & V_2 -> V_111 , V_110 ) ;
return 0 ;
}
static int F_59 ( struct V_170 * V_68 , int V_69 )
{
struct V_1 * V_2 = V_68 -> V_171 ;
unsigned long V_110 ;
if ( V_69 == V_2 -> V_66 )
return 0 ;
F_36 ( & V_2 -> V_111 , V_110 ) ;
V_2 -> V_66 = V_69 ;
F_33 ( V_2 ) ;
F_25 ( V_2 ) ;
F_31 ( V_2 ) ;
F_38 ( & V_2 -> V_111 , V_110 ) ;
return 0 ;
}
static void F_60 ( struct V_170 * V_68 , bool V_176 )
{
struct V_1 * V_2 = V_68 -> V_171 ;
if ( V_176 ) {
F_34 ( V_2 ) ;
F_18 ( L_67 ) ;
}
}
static int F_61 ( struct V_170 * V_68 , unsigned * V_177 , unsigned V_178 )
{
struct V_1 * V_2 = V_68 -> V_171 ;
unsigned long V_110 ;
V_2 -> V_131 = V_177 ;
V_2 -> V_138 = V_178 ;
V_2 -> V_137 = 0 ;
V_2 -> V_143 = 0 ;
V_2 -> V_139 = 0 ;
V_2 -> V_136 = 0 ;
V_2 -> V_135 = false ;
F_18 ( L_68 , V_2 -> V_138 ) ;
F_36 ( & V_2 -> V_111 , V_110 ) ;
F_40 ( V_2 ) ;
F_42 ( V_2 ) ;
F_42 ( V_2 ) ;
F_38 ( & V_2 -> V_111 , V_110 ) ;
if ( F_62 ( & V_2 -> V_140 , 2 * V_149 ) == 0 ) {
F_18 ( L_69 ) ;
F_36 ( & V_2 -> V_111 , V_110 ) ;
F_41 ( V_2 ) ;
F_38 ( & V_2 -> V_111 , V_110 ) ;
} else
F_18 ( L_70 ) ;
return V_178 ;
}
static int F_63 ( struct V_179 * V_179 , const struct V_180 * V_181 )
{
int error = - V_182 ;
struct V_170 * V_68 ;
struct V_1 * V_2 ;
V_2 = F_64 ( sizeof( struct V_1 ) , V_183 ) ;
V_68 = F_65 () ;
if ( ! V_2 || ! V_68 )
goto V_184;
error = - V_31 ;
V_2 -> V_4 = - 1 ;
V_2 -> V_100 = - 1 ;
if ( ! F_66 ( V_179 , 0 ) ||
F_67 ( V_179 , 0 ) < V_185 )
goto V_184;
if ( ! F_68 ( V_179 , 0 ) )
goto V_184;
F_69 ( & V_2 -> V_111 ) ;
V_2 -> V_4 = F_70 ( V_179 , 0 ) ;
V_2 -> V_100 = F_71 ( V_179 , 0 ) ;
F_72 ( V_179 , V_2 ) ;
V_2 -> V_179 = V_179 ;
if ( V_27 < 5 || V_27 > 0x7F )
V_27 = V_28 ;
error = F_10 ( V_2 ) ;
if ( error )
goto V_184;
if ( ! V_2 -> V_39 && V_146 ) {
V_2 -> V_39 = true ;
F_73 ( & V_2 -> V_147 , F_47 ,
( long unsigned int ) V_2 ) ;
F_11 ( L_71 ) ;
}
if ( ! V_2 -> V_39 )
V_169 = false ;
V_68 -> V_186 = V_187 ;
V_68 -> V_188 = V_189 ;
V_68 -> V_171 = V_2 ;
V_68 -> V_190 = F_53 ;
V_68 -> V_191 = F_54 ;
V_68 -> V_192 = F_60 ;
V_68 -> V_193 = V_194 ;
V_68 -> V_195 = V_196 ;
V_68 -> V_197 = L_72 ;
if ( V_2 -> V_39 ) {
V_68 -> V_198 = F_58 ;
F_74 ( & V_2 -> V_140 ) ;
V_68 -> V_199 = F_61 ;
V_68 -> V_200 = F_55 ;
V_68 -> V_201 = F_56 ;
V_68 -> V_202 = F_57 ;
V_68 -> V_203 = F_59 ;
V_68 -> V_197 = L_73 ;
}
V_2 -> V_68 = V_68 ;
F_13 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
F_75 ( & V_179 -> V_2 , true ) ;
F_76 ( & V_179 -> V_2 , true ) ;
error = F_77 ( V_68 ) ;
if ( error < 0 )
goto V_184;
error = - V_204 ;
if ( ! F_78 ( V_2 -> V_4 , V_185 , V_194 ) ) {
goto V_205;
}
if ( F_79 ( V_2 -> V_100 , F_48 ,
V_206 , V_194 , ( void * ) V_2 ) ) {
goto V_207;
}
F_12 ( L_74 ) ;
return 0 ;
V_207:
F_80 ( V_2 -> V_4 , V_185 ) ;
V_205:
F_81 ( V_68 ) ;
V_68 = NULL ;
V_184:
F_82 ( V_68 ) ;
F_83 ( V_2 ) ;
return error ;
}
static void F_84 ( struct V_179 * V_179 )
{
struct V_1 * V_2 = F_85 ( V_179 ) ;
unsigned long V_110 ;
F_36 ( & V_2 -> V_111 , V_110 ) ;
F_33 ( V_2 ) ;
F_15 ( V_2 ) ;
F_38 ( & V_2 -> V_111 , V_110 ) ;
F_86 ( V_2 -> V_100 , V_2 ) ;
F_80 ( V_2 -> V_4 , V_185 ) ;
F_81 ( V_2 -> V_68 ) ;
F_83 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 , bool V_69 )
{
F_18 ( L_75 , V_69 ? L_76 : L_77 ) ;
F_9 ( V_2 , V_35 , V_208 , V_69 ) ;
}
static int F_88 ( struct V_179 * V_179 , T_5 V_209 )
{
struct V_1 * V_2 = F_85 ( V_179 ) ;
bool V_210 = F_89 ( & V_2 -> V_179 -> V_2 ) ;
if ( ! V_210 && V_2 -> V_108 )
F_32 ( V_2 ) ;
F_87 ( V_2 , V_210 ) ;
return 0 ;
}
static int F_90 ( struct V_179 * V_179 )
{
struct V_1 * V_2 = F_85 ( V_179 ) ;
F_52 ( V_2 ) ;
if ( V_2 -> V_108 )
F_31 ( V_2 ) ;
F_87 ( V_2 , false ) ;
return 0 ;
}
static void F_91 ( struct V_179 * V_179 )
{
struct V_1 * V_2 = F_85 ( V_179 ) ;
F_87 ( V_2 , true ) ;
}
