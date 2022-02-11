static int F_1 ( void T_1 * V_1 , T_2 V_2 )
{
int V_3 = 0x400 ;
F_2 ( V_2 , V_1 + V_4 ) ;
F_3 ( 1 ) ;
while ( ( F_4 ( V_1 ) & V_2 ) && -- V_3 )
;
return ! V_3 ;
}
static int F_5 ( void T_1 * V_5 , bool V_6 )
{
int V_7 ;
int V_3 = 0x400 ;
V_7 = F_1 ( V_5 , V_8 ) ;
if ( F_6 ( V_7 ) )
goto error;
F_2 ( V_9 , V_5 + V_4 ) ;
if ( ! V_6 ) {
F_2 ( V_8 , V_5 + V_10 ) ;
F_3 ( 1 ) ;
while ( ( ! ( F_4 ( V_5 ) & V_9 ) ) && -- V_3 )
;
if ( F_6 ( ! V_3 ) )
goto error;
}
V_7 = F_1 ( V_5 , V_8 ) ;
if ( F_6 ( V_7 ) )
goto error;
V_7 = F_1 ( V_5 , V_9 ) ;
if ( F_6 ( V_7 ) )
goto error;
return 0 ;
error:
F_7 ( L_1 , V_11 , V_5 ) ;
return - V_12 ;
}
static int F_8 ( struct V_13 * V_14 , bool V_15 )
{
struct V_16 * V_16 ;
int V_7 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
V_16 = V_14 -> V_19 . clock [ V_17 ] ;
if ( ! V_16 )
break;
if ( V_15 ) {
V_7 = F_9 ( V_16 ) ;
if ( V_7 )
goto V_20;
} else {
F_10 ( V_16 ) ;
}
}
return 0 ;
V_20:
for (; V_17 > 0 ; V_17 -- )
F_10 ( V_14 -> V_19 . clock [ V_17 - 1 ] ) ;
return V_7 ;
}
int F_11 ( struct V_13 * V_14 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
int V_7 ;
V_7 = F_12 ( V_14 ) ;
if ( V_7 )
goto V_22;
V_7 = F_5 ( V_21 -> V_23 , false ) ;
if ( V_7 )
goto V_22;
V_7 = F_5 ( V_21 -> V_24 , F_13 ( V_14 ) ) ;
if ( V_7 )
goto V_22;
F_2 ( V_25 , V_21 -> V_23 + V_26 ) ;
F_2 ( V_27 ,
V_21 -> V_23 + V_28 ) ;
F_2 ( V_29 , V_21 -> V_23 + V_28 ) ;
F_2 ( V_30 , V_21 -> V_23 + V_28 ) ;
F_2 ( V_31 , V_21 -> V_23 + V_28 ) ;
F_14 ( V_14 ) ;
return 0 ;
V_22:
return V_7 ;
}
void F_15 ( struct V_13 * V_14 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
struct V_32 * V_33 = & V_14 -> V_32 ;
T_2 V_34 ;
int V_17 ;
F_7 ( L_2 ) ;
for ( V_17 = 0 ; V_17 <= V_35 / 0x10 + 1 ; V_17 ++ ) {
V_34 = F_4 ( V_21 -> V_23 + V_17 * 0x10 ) ;
F_7 ( L_3 , V_17 * 0x10 , V_34 ) ;
}
F_7 ( L_4 ) ;
for ( V_17 = 0 ; V_17 <= V_36 / 0x10 + 1 ; V_17 ++ ) {
V_34 = F_4 ( V_21 -> V_24 + V_17 * 0x10 ) ;
F_7 ( L_3 , V_17 * 0x10 , V_34 ) ;
}
F_7 ( L_5 ) ;
F_7 ( L_6 , V_33 -> V_37 ) ;
F_7 ( L_7 , V_33 -> V_38 ) ;
F_7 ( L_8 , V_33 -> V_39 ) ;
F_7 ( L_9 , V_33 -> V_40 ) ;
F_7 ( L_10 , V_33 -> V_41 ) ;
F_7 ( L_11 , V_33 -> V_42 ) ;
F_7 ( L_12 , V_33 -> V_43 ) ;
F_7 ( L_13 , V_33 -> V_44 ) ;
F_7 ( L_14 , V_33 -> V_45 ) ;
F_7 ( L_15 , V_33 -> V_46 ) ;
F_7 ( L_16 , V_33 -> V_47 ) ;
}
int F_16 ( struct V_13 * V_14 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
struct V_32 * V_48 = & V_14 -> V_32 ;
unsigned int V_49 ;
unsigned int V_50 ;
unsigned int V_40 ;
unsigned int V_38 ;
unsigned int V_39 ;
unsigned int V_37 ;
int V_7 ;
if ( F_17 ( V_14 ) )
return ! 0 ;
V_49 = V_48 -> V_42 - 1 ;
V_50 = V_48 -> V_41 ;
V_40 = V_48 -> V_40 ;
V_38 = V_48 -> V_38 >> 1 ;
V_39 = V_48 -> V_39 ;
V_37 = V_48 -> V_37 ;
V_7 = F_12 ( V_14 ) ;
if ( V_7 )
goto V_22;
V_7 = F_5 ( V_21 -> V_24 , F_13 ( V_14 ) ) ;
if ( V_7 )
goto V_22;
F_2 ( F_18 ( V_49 )
| F_19 ( V_40 )
| F_20 ( V_38 , V_14 )
| F_21 ( V_37 , V_14 )
| F_22 ( V_50 , V_14 ) ,
V_21 -> V_24 + V_51 ) ;
F_2 ( F_23 ( V_39 )
| F_24 ( V_38 , V_14 )
| F_25 ( V_37 , V_14 )
| F_26 ( V_50 , V_14 ) ,
V_21 -> V_24 + V_52 ) ;
F_2 ( 0 , V_21 -> V_24 + V_53 ) ;
F_2 ( V_54 ,
V_21 -> V_24 + V_55 ) ;
F_14 ( V_14 ) ;
return 0 ;
V_22:
return V_7 ;
}
static unsigned int F_27 ( unsigned int time ,
unsigned int V_56 , unsigned int V_57 )
{
unsigned int V_58 ;
V_58 = ( time + V_56 - 1 ) / V_56 ;
return F_28 ( V_58 , V_57 ) ;
}
static int F_29 ( struct V_13 * V_14 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 = & V_63 ;
struct V_19 * V_21 = & V_14 -> V_19 ;
struct V_64 * V_65 = & V_14 -> V_65 ;
struct V_66 V_67 = V_14 -> V_68 ;
bool V_69 ;
unsigned long V_70 ;
unsigned int V_71 ;
bool V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_75 ;
unsigned int V_76 ;
unsigned int V_77 ;
unsigned int V_78 ;
int V_79 ;
unsigned int V_80 ;
int V_81 ;
unsigned int V_82 = V_83 ;
unsigned int V_84 = V_85 ;
if ( V_65 -> V_86 > 2 ) {
V_67 . V_76 += 10 ;
V_67 . V_87 += 10 ;
V_67 . V_88 += 10 ;
} else if ( V_65 -> V_86 > 1 ) {
V_67 . V_76 += 5 ;
V_67 . V_87 += 5 ;
V_67 . V_88 += 5 ;
}
V_69 =
( V_67 . V_89 >= 0 ) &&
( V_67 . V_90 >= 0 ) &&
( V_67 . V_91 >= 0 ) ;
V_62 -> V_70 = F_30 ( V_21 -> clock [ 0 ] ) ;
V_70 = V_62 -> V_70 ;
V_71 = V_92 / V_70 ;
V_77 = F_27 ( V_67 . V_76 ,
V_71 , 1 ) ;
V_78 = F_27 ( V_67 . V_87 ,
V_71 , 1 ) ;
V_75 = F_27 ( V_67 . V_88 ,
V_71 , 0 ) ;
if ( V_71 > ( V_62 -> V_93 >> 1 ) ) {
V_72 = true ;
V_73 = 3 + 1 ;
} else {
V_72 = false ;
V_73 = 3 ;
}
if ( V_71 > V_62 -> V_93 )
V_74 = 0 ;
else {
V_74 =
( V_62 -> V_94 * V_71 ) >>
V_73 ;
if ( V_74 > V_62 -> V_95 )
V_74 = V_62 -> V_95 ;
}
if ( ! V_69 ) {
V_79 = V_67 . V_96 +
V_62 -> V_97 ;
while ( ( V_79 > V_74 ) &&
( V_77 < V_62 -> V_98 ) ) {
V_77 ++ ;
V_79 -= V_71 ;
if ( V_79 < 0 )
V_79 = 0 ;
}
V_80 =
F_27 (
V_79 << V_73 ,
V_71 , 0 ) ;
if ( V_80 > V_62 -> V_94 )
V_80 = V_62 -> V_94 ;
goto V_99;
}
V_84 += V_62 -> V_97 ;
V_76 = V_71 * V_77 ;
V_81 = ( int ) V_82 + ( int ) V_67 . V_91 +
( int ) V_76 ;
V_81 -= ( int ) V_84 + ( int ) V_67 . V_89 ;
while ( ( V_81 <= 0 ) &&
( V_77 < V_62 -> V_98 ) ) {
V_77 ++ ;
V_76 += V_71 ;
V_81 += V_71 ;
}
V_79 =
( ( int ) V_84 +
( int ) V_67 . V_89 +
( int ) V_82 +
( int ) V_67 . V_91 -
( int ) V_76 ) >> 1 ;
if ( V_79 < 0 )
V_79 = 0 ;
while ( ( V_79 > V_74 ) &&
( V_77 < V_62 -> V_98 ) ) {
V_77 ++ ;
V_76 += V_71 ;
V_81 += V_71 ;
V_79 -= ( V_71 >> 1 ) ;
if ( V_79 < 0 )
V_79 = 0 ;
}
V_80 =
F_27 ( V_79 << V_73 ,
V_71 , 0 ) ;
if ( V_80 > V_62 -> V_94 )
V_80 = V_62 -> V_94 ;
#define F_31 ((int) ideal_sample_delay_in_ns)
#define F_32 \
((int) ((sample_delay_factor * clock_period_in_ns) >> \
dll_delay_shift))
#define F_33 (abs(QUANTIZED_DELAY - IDEAL_DELAY))
#define F_34 (DELAY_ERROR > (tEYE >> 1))
while ( F_34 &&
( V_77 < V_62 -> V_98 ) ) {
if ( F_32 > F_31 ) {
if ( V_80 != 0 )
V_80 -- ;
continue;
}
V_77 ++ ;
V_76 += V_71 ;
V_81 += V_71 ;
V_79 -= ( V_71 >> 1 ) ;
V_79 -= V_71 ;
if ( V_79 < 0 )
V_79 = 0 ;
V_80 =
F_27 (
V_79 << V_73 ,
V_71 , 0 ) ;
if ( V_80 > V_62 -> V_94 )
V_80 = V_62 -> V_94 ;
}
V_99:
V_60 -> V_77 = V_77 ;
V_60 -> V_78 = V_78 ;
V_60 -> V_75 = V_75 ;
V_60 -> V_100 = V_72 ;
V_60 -> V_80 = V_80 ;
V_60 -> V_101 = V_102 ;
V_60 -> V_103 = V_104 ;
return 0 ;
}
static void F_35 ( struct V_13 * V_14 ,
struct V_59 * V_60 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
unsigned long V_105 = F_30 ( V_21 -> clock [ 0 ] ) ;
int V_106 = V_14 -> V_107 ;
int V_108 = 16 ;
unsigned long V_109 ;
unsigned long V_110 ;
int V_111 ;
int V_112 = 4 ;
int V_113 ;
int V_114 ;
V_60 -> V_77 = 1 ;
V_60 -> V_78 = 1 ;
V_60 -> V_75 = ( ( V_106 == 5 ) ? 1 : 0 ) ;
V_60 -> V_101 = 0x9000 ;
V_60 -> V_103 = V_115 ;
if ( F_36 ( V_14 ) )
V_108 = 12 ;
V_110 = V_92 / ( V_105 / 10 ) ;
V_108 *= 10 ;
V_111 = ( ( V_106 == 5 ) ? 16 : 20 ) * 10 ;
V_112 *= 10 ;
V_113 = V_110 * 1 ;
if ( V_110 > V_108 ) {
V_60 -> V_100 = 1 ;
V_114 = V_110 / 2 ;
} else {
V_60 -> V_100 = 0 ;
V_114 = V_110 ;
}
V_109 = ( ( ( V_111 + V_112 - V_113 ) * 8 ) * 10 ) / V_114 ;
V_109 = ( V_109 + 5 ) / 10 ;
V_60 -> V_80 = V_109 ;
}
static int F_37 ( struct V_13 * V_14 , int V_106 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
struct V_64 * V_65 = & V_14 -> V_65 ;
struct V_116 * V_117 = & V_14 -> V_117 ;
T_3 V_118 [ V_119 ] = {} ;
unsigned long V_105 ;
int V_7 ;
V_65 -> V_120 ( V_117 , 0 ) ;
V_118 [ 0 ] = V_106 ;
V_7 = V_65 -> V_121 ( V_117 , V_65 ,
V_122 , V_118 ) ;
if ( V_7 )
goto V_22;
memset ( V_118 , 0 , V_119 ) ;
V_7 = V_65 -> V_123 ( V_117 , V_65 ,
V_122 , V_118 ) ;
if ( V_7 || V_118 [ 0 ] != V_106 )
goto V_22;
V_65 -> V_120 ( V_117 , - 1 ) ;
V_105 = ( V_106 == 5 ) ? 100000000 : 80000000 ;
F_38 ( V_21 -> clock [ 0 ] , V_105 ) ;
V_14 -> V_124 &= ~ V_125 ;
V_14 -> V_124 |= V_126 ;
V_14 -> V_107 = V_106 ;
F_39 ( V_14 -> V_127 , L_17 , V_106 ) ;
return 0 ;
V_22:
V_65 -> V_120 ( V_117 , - 1 ) ;
F_40 ( V_14 -> V_127 , L_18 , V_106 ) ;
return - V_128 ;
}
int F_41 ( struct V_13 * V_14 )
{
struct V_64 * V_129 = & V_14 -> V_65 ;
if ( F_36 ( V_14 ) && V_129 -> V_130 ) {
int V_106 = F_42 ( V_129 ) ;
if ( V_106 & V_131 )
V_106 = 5 ;
else if ( V_106 & V_132 )
V_106 = 4 ;
else
return 0 ;
return F_37 ( V_14 , V_106 ) ;
}
return 0 ;
}
void F_43 ( struct V_13 * V_14 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
void T_1 * V_23 = V_21 -> V_23 ;
unsigned int V_71 ;
T_4 V_34 ;
unsigned int V_133 ;
struct V_59 V_60 ;
int V_7 ;
V_7 = F_12 ( V_14 ) ;
if ( V_7 ) {
F_7 ( L_19 ) ;
goto V_22;
}
if ( V_14 -> V_124 & V_125 )
return;
V_14 -> V_124 |= V_125 ;
if ( V_14 -> V_124 & V_126 )
F_35 ( V_14 , & V_60 ) ;
else
F_29 ( V_14 , & V_60 ) ;
V_34 = F_44 ( V_60 . V_75 ) |
F_45 ( V_60 . V_78 ) |
F_46 ( V_60 . V_77 ) ;
F_2 ( V_34 , V_23 + V_134 ) ;
F_2 ( F_47 ( V_60 . V_101 ) ,
V_23 + V_135 ) ;
F_2 ( V_136 , V_23 + V_26 ) ;
F_2 ( F_48 ( V_60 . V_103 ) ,
V_23 + V_28 ) ;
F_2 ( V_137 , V_23 + V_26 ) ;
V_34 = V_138 | V_139 ;
F_2 ( V_34 , V_23 + V_26 ) ;
if ( ! V_60 . V_80 )
return;
V_34 = ( ( V_60 . V_100 ) ? V_139 : 0 )
| F_49 ( V_60 . V_80 ) ;
F_2 ( V_34 , V_23 + V_28 ) ;
F_2 ( V_137 , V_23 + V_28 ) ;
V_71 = V_92 / F_30 ( V_21 -> clock [ 0 ] ) ;
V_133 = ( V_71 * 64 ) / 1000 ;
if ( ! V_133 )
V_133 = 1 ;
F_3 ( V_133 ) ;
V_22:
return;
}
void F_50 ( struct V_13 * V_14 )
{
F_14 ( V_14 ) ;
}
void F_51 ( struct V_13 * V_14 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
F_2 ( V_140 , V_21 -> V_24 + V_141 ) ;
}
int F_52 ( struct V_13 * V_14 , unsigned V_129 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
T_4 V_2 = 0 ;
T_4 V_34 = 0 ;
if ( F_13 ( V_14 ) ) {
V_2 = V_142 << V_129 ;
V_34 = F_4 ( V_21 -> V_23 + V_35 ) ;
} else if ( F_53 ( V_14 ) || F_36 ( V_14 ) ) {
if ( F_36 ( V_14 ) )
V_129 = 0 ;
V_2 = F_54 ( 1 << V_129 ) ;
V_34 = F_4 ( V_21 -> V_23 + V_143 ) ;
} else
F_7 ( L_20 ) ;
return V_34 & V_2 ;
}
static inline void F_55 ( struct V_13 * V_14 ,
enum V_144 type )
{
V_14 -> V_145 = V_14 -> V_146 ;
V_14 -> V_146 = type ;
}
int F_56 ( struct V_13 * V_14 )
{
struct V_147 * V_148 = F_57 ( V_14 ) ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
int V_129 = V_14 -> V_153 ;
T_2 V_154 [ 3 ] ;
V_154 [ 0 ] = F_58 ( V_155 )
| V_156
| F_59 ( V_129 , V_14 )
| F_60 ( V_157 , V_14 )
| F_61 ( V_158 )
| V_159
| F_62 ( V_14 -> V_160 ) ;
V_154 [ 1 ] = V_154 [ 2 ] = 0 ;
V_150 = F_63 ( V_148 ,
(struct V_151 * ) V_154 ,
F_64 ( V_154 ) , V_161 , 0 ) ;
if ( ! V_150 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
V_152 = & V_14 -> V_162 ;
F_65 ( V_152 , V_14 -> V_163 , V_14 -> V_160 ) ;
F_66 ( V_14 -> V_127 , V_152 , 1 , V_164 ) ;
V_150 = F_63 ( V_148 ,
V_152 , 1 , V_165 ,
V_166 | V_167 ) ;
if ( ! V_150 ) {
F_7 ( L_22 ) ;
return - 1 ;
}
F_55 ( V_14 , V_168 ) ;
return F_67 ( V_14 , V_150 ) ;
}
int F_68 ( struct V_13 * V_14 )
{
struct V_149 * V_150 ;
struct V_147 * V_148 = F_57 ( V_14 ) ;
int V_129 = V_14 -> V_153 ;
T_4 V_169 ;
T_4 V_170 ;
T_2 V_154 [ 2 ] ;
V_169 = V_155 ;
V_170 = V_171 ;
V_154 [ 0 ] = F_58 ( V_169 )
| V_156
| F_59 ( V_129 , V_14 )
| F_60 ( V_157 , V_14 )
| F_61 ( V_170 )
| F_62 ( V_14 -> V_172 ) ;
V_154 [ 1 ] = 0 ;
V_150 = F_63 ( V_148 , (struct V_151 * ) V_154 ,
F_64 ( V_154 ) , V_161 , 0 ) ;
if ( ! V_150 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
F_69 ( V_14 , V_164 ) ;
V_150 = F_63 ( V_148 , & V_14 -> V_173 ,
1 , V_165 ,
V_166 | V_167 ) ;
if ( ! V_150 ) {
F_7 ( L_22 ) ;
return - 1 ;
}
F_55 ( V_14 , V_174 ) ;
return F_67 ( V_14 , V_150 ) ;
}
int F_70 ( struct V_13 * V_14 )
{
struct V_149 * V_150 ;
struct V_147 * V_148 = F_57 ( V_14 ) ;
int V_129 = V_14 -> V_153 ;
T_2 V_154 [ 2 ] ;
V_154 [ 0 ] = F_58 ( V_175 )
| V_156
| F_59 ( V_129 , V_14 )
| F_60 ( V_157 , V_14 )
| F_61 ( V_171 )
| F_62 ( V_14 -> V_172 ) ;
V_154 [ 1 ] = 0 ;
V_150 = F_63 ( V_148 ,
(struct V_151 * ) V_154 ,
F_64 ( V_154 ) , V_161 , 0 ) ;
if ( ! V_150 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
F_69 ( V_14 , V_176 ) ;
V_150 = F_63 ( V_148 , & V_14 -> V_173 ,
1 , V_177 ,
V_166 | V_167 ) ;
if ( ! V_150 ) {
F_7 ( L_22 ) ;
return - 1 ;
}
F_55 ( V_14 , V_178 ) ;
return F_67 ( V_14 , V_150 ) ;
}
int F_71 ( struct V_13 * V_14 ,
T_5 V_179 , T_5 V_180 )
{
struct V_32 * V_33 = & V_14 -> V_32 ;
T_4 V_169 ;
T_4 V_170 ;
T_4 V_181 ;
T_4 V_182 ;
struct V_149 * V_150 ;
struct V_147 * V_148 = F_57 ( V_14 ) ;
int V_129 = V_14 -> V_153 ;
T_2 V_154 [ 6 ] ;
V_169 = V_155 ;
V_170 = V_171 ;
V_181 = V_183 ;
V_182 = V_184 |
V_185 ;
V_154 [ 0 ] = F_58 ( V_169 )
| V_156
| F_59 ( V_129 , V_14 )
| F_60 ( V_157 , V_14 )
| F_61 ( V_170 )
| F_62 ( 0 ) ;
V_154 [ 1 ] = 0 ;
V_154 [ 2 ] = V_186
| F_72 ( V_181 )
| F_73 ( V_182 ) ;
V_154 [ 3 ] = V_33 -> V_39 ;
V_154 [ 4 ] = V_179 ;
V_154 [ 5 ] = V_180 ;
V_150 = F_63 ( V_148 ,
(struct V_151 * ) V_154 ,
F_64 ( V_154 ) , V_161 ,
V_167 ) ;
if ( ! V_150 ) {
F_7 ( L_22 ) ;
return - 1 ;
}
F_55 ( V_14 , V_187 ) ;
return F_74 ( V_14 , V_150 ) ;
}
int F_75 ( struct V_13 * V_14 ,
T_5 V_179 , T_5 V_180 )
{
struct V_32 * V_33 = & V_14 -> V_32 ;
T_4 V_169 ;
T_4 V_170 ;
T_4 V_181 ;
T_4 V_182 ;
struct V_149 * V_150 ;
struct V_147 * V_148 = F_57 ( V_14 ) ;
int V_129 = V_14 -> V_153 ;
T_2 V_154 [ 6 ] ;
V_169 = V_188 ;
V_170 = V_171 ;
V_154 [ 0 ] = F_58 ( V_169 )
| V_156
| F_59 ( V_129 , V_14 )
| F_60 ( V_157 , V_14 )
| F_61 ( V_170 )
| F_62 ( 0 ) ;
V_154 [ 1 ] = 0 ;
V_150 = F_63 ( V_148 ,
(struct V_151 * ) V_154 , 2 ,
V_161 , 0 ) ;
if ( ! V_150 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
V_169 = V_175 ;
V_170 = V_171 ;
V_181 = V_189 ;
V_182 = V_184
| V_185 ;
V_154 [ 0 ] = F_58 ( V_169 )
| V_156
| F_59 ( V_129 , V_14 )
| F_60 ( V_157 , V_14 )
| F_61 ( V_170 )
| F_62 ( V_33 -> V_39 ) ;
V_154 [ 1 ] = 0 ;
V_154 [ 2 ] = V_186
| F_72 ( V_181 )
| F_73 ( V_182 ) ;
V_154 [ 3 ] = V_33 -> V_39 ;
V_154 [ 4 ] = V_179 ;
V_154 [ 5 ] = V_180 ;
V_150 = F_63 ( V_148 ,
(struct V_151 * ) V_154 ,
F_64 ( V_154 ) , V_161 ,
V_166 | V_167 ) ;
if ( ! V_150 ) {
F_7 ( L_22 ) ;
return - 1 ;
}
V_169 = V_188 ;
V_170 = V_171 ;
V_154 [ 0 ] = F_58 ( V_169 )
| V_156
| F_59 ( V_129 , V_14 )
| F_60 ( V_157 , V_14 )
| F_61 ( V_170 )
| F_62 ( V_33 -> V_39 ) ;
V_154 [ 1 ] = 0 ;
V_154 [ 2 ] = 0 ;
V_150 = F_63 ( V_148 ,
(struct V_151 * ) V_154 , 3 ,
V_161 ,
V_166 | V_167 ) ;
if ( ! V_150 ) {
F_7 ( L_23 ) ;
return - 1 ;
}
F_55 ( V_14 , V_190 ) ;
return F_74 ( V_14 , V_150 ) ;
}
