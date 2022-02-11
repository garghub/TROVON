static T_1 F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( const struct V_1 * V_2 , T_1 V_5 ,
T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( const struct V_1 * V_2 , T_1 V_6 ,
T_1 V_7 , T_1 V_3 )
{
T_1 V_5 = F_2 ( V_2 -> V_4 + V_3 ) ;
V_5 &= ~ V_6 ;
V_5 |= V_7 ;
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static unsigned int F_6 ( const struct V_1 * V_2 )
{
T_1 V_8 = F_1 ( V_2 , V_9 ) ;
return ( V_8 & V_10 ) >> V_11 ;
}
static unsigned int F_7 ( const struct V_1 * V_2 )
{
T_1 V_8 = F_1 ( V_2 , V_9 ) ;
return V_8 & V_12 ;
}
static unsigned int F_8 ( const struct V_1 * V_2 )
{
return V_2 -> V_13 - F_6 ( V_2 ) ;
}
static void F_9 ( const struct V_1 * V_2 )
{
T_1 V_5 = V_2 -> V_14 << V_15 ;
V_5 |= V_16 | V_17 ;
F_3 ( V_2 , V_5 , V_18 ) ;
}
static void F_10 ( const struct V_1 * V_2 )
{
T_1 V_5 = 1 << V_19 ;
V_5 |= V_20 | V_21 ;
F_3 ( V_2 , V_5 , V_22 ) ;
}
static void F_11 ( const struct V_1 * V_2 )
{
F_5 ( V_2 , 0 , V_17 , V_18 ) ;
}
static void F_12 ( const struct V_1 * V_2 )
{
F_5 ( V_2 , 0 , V_21 , V_22 ) ;
}
static void F_13 ( const struct V_1 * V_2 )
{
F_3 ( V_2 , V_23 , V_24 ) ;
}
static void F_14 ( const struct V_1 * V_2 )
{
F_3 ( V_2 , V_25 , V_24 ) ;
}
static void F_15 ( const struct V_1 * V_2 ,
unsigned int V_26 )
{
T_1 V_27 , V_28 ;
V_27 = F_16 ( V_2 -> V_29 ) / 2 ;
if ( V_26 > V_27 )
V_28 = 0 ;
else
V_28 = V_27 / V_26 - 1 ;
if ( V_28 > 0xFFFF )
V_28 = 0xFFFF ;
F_17 ( V_2 -> V_30 , L_1 ,
V_27 , V_26 , V_28 ) ;
F_3 ( V_2 , V_28 , V_31 ) ;
}
static void F_18 ( const struct V_1 * V_2 ,
unsigned int V_32 )
{
T_1 V_33 ;
V_33 = ( V_32 - 1 ) << V_34 ;
F_5 ( V_2 , V_35 , V_33 , V_36 ) ;
}
static void F_19 ( const struct V_1 * V_2 ,
unsigned int V_37 )
{
T_1 V_38 = 0 , V_39 = 0 ;
if ( V_37 & V_40 )
V_39 |= V_41 ;
else
V_38 |= V_41 ;
if ( V_37 & V_42 )
V_38 |= V_43 | V_44 ;
else
V_39 |= V_43 | V_44 ;
if ( V_37 & V_45 )
V_39 |= V_46 ;
else
V_38 |= V_46 ;
if ( V_37 & V_47 )
V_38 |= V_48 ;
else
V_39 |= V_48 ;
F_5 ( V_2 , V_39 , V_38 , V_36 ) ;
}
static void F_20 ( const struct V_1 * V_2 )
{
const struct V_49 * V_50 = V_2 -> V_50 ;
F_3 ( V_2 , 1 << V_51 , V_52 ) ;
F_13 ( V_2 ) ;
F_5 ( V_2 , 0 , V_53 , V_24 ) ;
F_3 ( V_2 , V_54 | V_55 |
V_56 | V_57 | V_58 |
V_59 , V_36 ) ;
F_18 ( V_2 , V_2 -> V_32 ) ;
F_19 ( V_2 , V_60 ) ;
F_3 ( V_2 , V_61 |
V_53 ,
V_24 ) ;
F_3 ( V_2 , 0 , V_62 ) ;
F_3 ( V_2 , 0xFF00 , V_63 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
F_3 ( V_2 , V_50 -> V_64 | V_50 -> V_65 |
V_66 , V_67 ) ;
}
static int F_21 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = V_69 -> V_71 ;
struct V_1 * V_2 = F_22 ( V_71 ) ;
unsigned int V_72 = V_69 -> V_73 ;
T_1 V_74 ;
if ( F_23 ( V_69 -> V_75 ) )
return 0 ;
F_17 ( V_2 -> V_30 , L_2 , V_72 ) ;
if ( V_72 < V_2 -> V_76 ) {
F_24 ( V_2 -> V_30 ,
L_3 , V_72 , V_2 -> V_76 ) ;
return - V_77 ;
}
V_74 = 1 << ( ( V_72 - V_2 -> V_76 ) + V_78 ) ;
if ( V_69 -> V_37 & V_79 )
V_74 |= 1 << ( V_72 - V_2 -> V_76 ) ;
F_5 ( V_2 , 0 , V_74 , V_62 ) ;
return 0 ;
}
static int F_25 ( struct V_70 * V_71 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = F_22 ( V_71 ) ;
F_13 ( V_2 ) ;
F_19 ( V_2 , V_81 -> V_2 -> V_37 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_68 * V_69 , struct V_82 * V_83 )
{
unsigned int V_84 = V_83 -> V_84 ;
unsigned int V_32 = V_83 -> V_32 ;
T_1 V_85 ;
if ( V_32 != V_2 -> V_32 ||
V_84 != V_2 -> V_84 ) {
F_13 ( V_2 ) ;
F_15 ( V_2 , V_84 ) ;
F_18 ( V_2 , V_32 ) ;
F_14 ( V_2 ) ;
V_2 -> V_84 = V_84 ;
V_2 -> V_32 = V_32 ;
}
V_85 = F_1 ( V_2 , V_36 ) ;
if ( V_83 -> V_86 )
V_85 &= ~ V_58 ;
else
V_85 |= V_58 ;
if ( V_83 -> V_87 )
V_85 &= ~ V_59 ;
else
V_85 |= V_59 ;
F_3 ( V_2 , V_85 , V_36 ) ;
}
static int F_27 ( struct V_70 * V_71 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = F_22 ( V_71 ) ;
F_28 ( V_2 -> V_88 ) ;
F_5 ( V_2 , 0 , V_58 | V_59 ,
V_36 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
const T_2 * V_89 ;
const T_3 * V_90 ;
const T_1 * V_91 ;
T_1 V_92 ;
unsigned int V_93 = F_8 ( V_2 ) ;
while ( V_2 -> V_94 && V_93 ) {
switch ( V_2 -> V_32 ) {
case 2 ... 8 :
V_89 = V_2 -> V_95 ;
V_92 = * V_89 ;
V_2 -> V_94 -- ;
V_2 -> V_95 ++ ;
break;
case 16 :
V_90 = ( T_3 * ) V_2 -> V_95 ;
V_92 = * V_90 ;
V_2 -> V_94 -= 2 ;
V_2 -> V_95 += 2 ;
break;
case 32 :
V_91 = ( T_1 * ) V_2 -> V_95 ;
V_92 = * V_91 ;
V_2 -> V_94 -= 4 ;
V_2 -> V_95 += 4 ;
break;
default:
F_30 ( 1 ) ;
V_92 = 0 ;
break;
}
F_3 ( V_2 , V_92 , V_96 ) ;
V_93 -- ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
T_2 * V_97 ;
T_3 * V_98 ;
T_1 * V_99 ;
T_1 V_92 ;
unsigned int V_100 = F_7 ( V_2 ) ;
while ( V_100 ) {
V_92 = F_1 ( V_2 , V_101 ) ;
switch ( V_2 -> V_32 ) {
case 2 ... 8 :
V_97 = V_2 -> V_102 ;
* V_97 = V_92 ;
V_2 -> V_103 -- ;
V_2 -> V_102 ++ ;
break;
case 16 :
V_98 = ( T_3 * ) V_2 -> V_102 ;
* V_98 = V_92 ;
V_2 -> V_103 -= 2 ;
V_2 -> V_102 += 2 ;
break;
case 32 :
V_99 = ( T_1 * ) V_2 -> V_102 ;
* V_99 = V_92 ;
V_2 -> V_103 -= 4 ;
V_2 -> V_102 += 4 ;
break;
default:
F_30 ( 1 ) ;
break;
}
V_100 -- ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_92 , * V_99 ;
T_2 * V_97 ;
unsigned int V_104 , V_105 ;
unsigned int V_100 = F_7 ( V_2 ) ;
while ( V_100 ) {
if ( V_2 -> V_103 < 4 ) {
V_104 = ( F_1 ( V_2 , V_106 ) &
V_107 ) >> V_108 ;
V_92 = F_1 ( V_2 , V_101 ) ;
V_105 = ( V_104 - 1 ) * 8 ;
V_97 = V_2 -> V_102 ;
while ( V_104 ) {
* V_97 ++ = ( V_92 >> V_105 ) & 0xFF ;
V_104 -- ;
V_105 -= 8 ;
V_2 -> V_103 -- ;
V_2 -> V_102 ++ ;
}
} else {
V_92 = F_1 ( V_2 , V_101 ) ;
V_99 = ( T_1 * ) V_2 -> V_102 ;
* V_99 ++ = V_92 ;
V_2 -> V_103 -= 4 ;
V_2 -> V_102 += 4 ;
}
V_100 -- ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
unsigned int V_109 , V_110 ;
V_109 = V_2 -> V_103 ;
V_110 = V_2 -> V_14 * 4 ;
if ( V_109 > V_110 )
V_109 = V_110 ;
F_3 ( V_2 , V_109 , V_111 ) ;
}
static T_4 F_34 ( int V_112 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
if ( V_2 -> V_95 ) {
if ( V_2 -> V_102 && V_2 -> V_103 )
F_31 ( V_2 ) ;
if ( V_2 -> V_94 )
F_29 ( V_2 ) ;
else if ( ! F_6 ( V_2 ) )
goto V_113;
} else if ( V_2 -> V_102 ) {
if ( V_2 -> V_103 ) {
F_32 ( V_2 ) ;
if ( V_2 -> V_103 )
F_33 ( V_2 ) ;
else
goto V_113;
} else {
goto V_113;
}
}
return V_114 ;
V_113:
F_35 ( V_2 -> V_88 , & V_2 -> V_115 ) ;
return V_114 ;
}
static T_4 F_36 ( int V_112 , void * V_92 )
{
struct V_1 * V_2 = V_92 ;
T_1 V_116 = F_1 ( V_2 , V_106 ) ;
if ( ! ( V_116 & V_117 ) )
return V_118 ;
if ( V_116 & V_119 )
F_24 ( V_2 -> V_30 , L_4 ) ;
if ( V_116 & V_120 )
F_24 ( V_2 -> V_30 , L_5 ) ;
if ( V_116 & V_121 )
F_24 ( V_2 -> V_30 , L_6 ) ;
if ( V_116 & V_122 )
F_24 ( V_2 -> V_30 , L_7 ) ;
if ( V_116 & V_123 )
F_24 ( V_2 -> V_30 , L_8 ) ;
if ( V_116 & V_124 )
F_24 ( V_2 -> V_30 , L_9 ) ;
F_5 ( V_2 , 0 , V_53 , V_24 ) ;
if ( V_2 -> V_71 -> V_125 )
V_2 -> V_71 -> V_125 -> V_126 = - V_127 ;
F_35 ( V_2 -> V_88 , & V_2 -> V_115 ) ;
return V_114 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_68 * V_69 ,
struct V_82 * V_83 )
{
unsigned long V_128 ;
F_38 ( & V_2 -> V_129 , V_128 ) ;
V_2 -> V_95 = V_83 -> V_86 ;
V_2 -> V_102 = V_83 -> V_87 ;
if ( V_83 -> V_86 ) {
V_2 -> V_94 = V_83 -> V_130 ;
F_29 ( V_2 ) ;
}
if ( V_2 -> V_102 ) {
V_2 -> V_103 = V_83 -> V_130 ;
if ( ! V_2 -> V_95 )
F_33 ( V_2 ) ;
}
F_39 ( & V_2 -> V_129 , V_128 ) ;
return V_83 -> V_130 ;
}
static void F_40 ( struct V_131 * V_115 )
{
struct V_1 * V_2 ;
unsigned long long V_132 = 8LL * 1000LL ;
unsigned long V_133 ;
V_2 = F_41 ( V_115 , F_42 ( * V_2 ) , V_115 ) ;
F_43 ( V_132 , V_2 -> V_84 ) ;
V_132 += V_132 + 100 ;
V_133 = V_134 + F_44 ( V_132 ) ;
do {
T_1 V_116 = F_1 ( V_2 , V_106 ) ;
if ( ! ( V_116 & V_135 ) ) {
F_45 ( V_2 -> V_71 ) ;
return;
}
F_46 () ;
} while ( ! F_47 ( V_134 , V_133 ) );
if ( V_2 -> V_71 -> V_125 )
V_2 -> V_71 -> V_125 -> V_126 = - V_127 ;
F_45 ( V_2 -> V_71 ) ;
}
static void F_48 ( struct V_70 * V_71 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = F_22 ( V_71 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void F_49 ( struct V_68 * V_69 , bool V_136 )
{
struct V_1 * V_2 = F_22 ( V_69 -> V_71 ) ;
unsigned int V_72 = V_69 -> V_73 ;
T_1 V_137 ;
if ( ! ! ( V_69 -> V_37 & V_79 ) == V_136 )
V_137 = ( 1 << ( V_72 - V_2 -> V_76 ) ) ;
else
V_137 = ( 1 << ( V_72 - V_2 -> V_76 + V_138 ) ) ;
F_3 ( V_2 , V_137 , V_63 ) ;
}
static int F_50 ( struct V_70 * V_71 ,
struct V_68 * V_69 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_22 ( V_71 ) ;
F_26 ( V_2 , V_69 , V_83 ) ;
return F_37 ( V_2 , V_69 , V_83 ) ;
}
static int F_51 ( struct V_139 * V_140 )
{
struct V_141 * V_30 = & V_140 -> V_30 ;
struct V_70 * V_71 ;
struct V_142 * V_143 ;
struct V_1 * V_2 ;
const struct V_49 * V_50 ;
const struct V_144 * V_145 ;
int V_146 , V_147 , V_148 , V_149 ;
T_1 V_150 , V_151 , V_152 ;
unsigned int V_153 ;
V_145 = F_52 ( V_154 , V_30 ) ;
if ( ! V_145 ) {
F_24 ( V_30 , L_10 ) ;
return - V_77 ;
}
V_50 = V_145 -> V_92 ;
V_143 = F_53 ( V_140 , V_155 , 0 ) ;
if ( ! V_143 ) {
F_24 ( V_30 , L_11 ) ;
return - V_156 ;
}
V_147 = F_54 ( V_140 , V_157 ) ;
if ( V_147 < 0 ) {
F_24 ( V_30 , L_12 , V_157 ) ;
return - V_156 ;
}
V_148 = F_54 ( V_140 , V_158 ) ;
if ( V_148 < 0 ) {
F_24 ( V_30 , L_12 , V_158 ) ;
return - V_156 ;
}
V_149 = F_54 ( V_140 , V_159 ) ;
if ( V_149 < 0 ) {
F_24 ( V_30 , L_12 , V_159 ) ;
return - V_156 ;
}
V_71 = F_55 ( V_30 , sizeof( struct V_1 ) ) ;
if ( ! V_71 )
return - V_160 ;
V_2 = F_22 ( V_71 ) ;
V_2 -> V_71 = V_71 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_50 = V_50 ;
F_56 ( V_140 , V_2 ) ;
V_2 -> V_4 = F_57 ( V_30 , V_143 ) ;
if ( F_58 ( V_2 -> V_4 ) ) {
V_146 = F_59 ( V_2 -> V_4 ) ;
goto V_161;
}
V_146 = F_60 ( V_30 , V_147 , F_34 ,
0 , V_157 , V_2 ) ;
if ( V_146 )
goto V_161;
V_146 = F_60 ( V_30 , V_148 , F_34 ,
0 , V_158 , V_2 ) ;
if ( V_146 )
goto V_161;
V_146 = F_60 ( V_30 , V_149 , F_36 ,
0 , V_159 , V_2 ) ;
if ( V_146 )
goto V_161;
V_2 -> V_27 = F_61 ( V_30 , L_13 ) ;
if ( F_58 ( V_2 -> V_27 ) ) {
V_146 = F_59 ( V_2 -> V_27 ) ;
goto V_161;
}
V_146 = F_62 ( V_2 -> V_27 ) ;
if ( V_146 )
goto V_161;
#if F_63 ( V_162 ) && ! F_63 ( V_163 )
V_2 -> V_29 = F_64 () ;
#else
V_2 -> V_29 = F_65 ( V_30 , L_14 ) ;
#endif
if ( F_58 ( V_2 -> V_29 ) ) {
V_146 = F_59 ( V_2 -> V_29 ) ;
goto V_164;
}
V_153 = 8 ;
F_66 ( V_140 -> V_30 . V_165 , L_15 , & V_153 ) ;
V_2 -> V_76 = 1 ;
F_66 ( V_140 -> V_30 . V_165 , L_16 , & V_2 -> V_76 ) ;
F_67 ( & V_2 -> V_129 ) ;
V_2 -> V_32 = 8 ;
V_2 -> V_84 = 0 ;
V_71 -> V_30 . V_165 = V_140 -> V_30 . V_165 ;
V_71 -> V_166 = V_153 ;
V_71 -> V_167 = F_21 ;
V_71 -> V_168 = F_49 ;
V_71 -> V_169 = F_48 ;
V_71 -> V_170 = F_25 ;
V_71 -> V_171 = F_27 ;
V_71 -> V_172 = F_50 ;
V_71 -> V_173 = V_42 | V_40 | V_45 | V_79 |
V_47 ;
V_71 -> V_174 = F_68 ( 2 , 8 ) |
F_69 ( 16 ) | F_69 ( 32 ) ;
V_2 -> V_88 = F_70 ( F_71 ( V_30 ) , 0 ) ;
if ( ! V_2 -> V_88 ) {
V_146 = - V_160 ;
goto V_175;
}
F_72 ( & V_2 -> V_115 , F_40 ) ;
V_150 = F_1 ( V_2 , V_176 ) ;
V_2 -> V_13 = ( V_150 & V_177 ) >> V_178 ;
V_2 -> V_14 = ( V_150 & V_179 ) >> V_180 ;
V_151 = ( V_150 & V_181 ) >> V_182 ;
V_152 = V_150 & V_183 ;
F_20 ( V_2 ) ;
F_73 ( V_30 ,
L_17 ,
V_152 , V_2 -> V_13 , V_2 -> V_14 , V_151 ) ;
V_146 = F_74 ( V_30 , V_71 ) ;
if ( V_146 ) {
F_24 ( V_30 , L_18 ) ;
goto V_184;
}
return 0 ;
V_184:
F_75 ( V_2 -> V_88 ) ;
V_175:
F_76 ( V_2 -> V_29 ) ;
V_164:
F_77 ( V_2 -> V_27 ) ;
V_161:
F_78 ( V_71 ) ;
return V_146 ;
}
static int F_79 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = F_80 ( V_140 ) ;
F_3 ( V_2 , 0 , V_67 ) ;
F_3 ( V_2 , 0 , V_52 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_75 ( V_2 -> V_88 ) ;
F_77 ( V_2 -> V_27 ) ;
F_76 ( V_2 -> V_29 ) ;
return 0 ;
}
