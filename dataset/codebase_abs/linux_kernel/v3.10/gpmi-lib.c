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
F_14 ( V_14 ) ;
return 0 ;
V_22:
return V_7 ;
}
void F_15 ( struct V_13 * V_14 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
struct V_31 * V_32 = & V_14 -> V_31 ;
T_2 V_33 ;
int V_17 ;
F_7 ( L_2 ) ;
for ( V_17 = 0 ; V_17 <= V_34 / 0x10 + 1 ; V_17 ++ ) {
V_33 = F_4 ( V_21 -> V_23 + V_17 * 0x10 ) ;
F_7 ( L_3 , V_17 * 0x10 , V_33 ) ;
}
F_7 ( L_4 ) ;
for ( V_17 = 0 ; V_17 <= V_35 / 0x10 + 1 ; V_17 ++ ) {
V_33 = F_4 ( V_21 -> V_24 + V_17 * 0x10 ) ;
F_7 ( L_3 , V_17 * 0x10 , V_33 ) ;
}
F_7 ( L_5 ) ;
F_7 ( L_6 , V_32 -> V_36 ) ;
F_7 ( L_7 , V_32 -> V_37 ) ;
F_7 ( L_8 , V_32 -> V_38 ) ;
F_7 ( L_9 , V_32 -> V_39 ) ;
F_7 ( L_10 , V_32 -> V_40 ) ;
F_7 ( L_11 , V_32 -> V_41 ) ;
F_7 ( L_12 , V_32 -> V_42 ) ;
F_7 ( L_13 , V_32 -> V_43 ) ;
F_7 ( L_14 , V_32 -> V_44 ) ;
F_7 ( L_15 , V_32 -> V_45 ) ;
F_7 ( L_16 , V_32 -> V_46 ) ;
}
int F_16 ( struct V_13 * V_14 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
struct V_31 * V_47 = & V_14 -> V_31 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_39 ;
unsigned int V_37 ;
unsigned int V_38 ;
unsigned int V_36 ;
int V_7 ;
if ( F_17 ( V_14 ) )
return ! 0 ;
V_48 = V_47 -> V_41 - 1 ;
V_49 = V_47 -> V_40 ;
V_39 = V_47 -> V_39 ;
V_37 = V_47 -> V_37 >> 1 ;
V_38 = V_47 -> V_38 ;
V_36 = V_47 -> V_36 ;
V_7 = F_12 ( V_14 ) ;
if ( V_7 )
goto V_22;
V_7 = F_5 ( V_21 -> V_24 , F_13 ( V_14 ) ) ;
if ( V_7 )
goto V_22;
F_2 ( F_18 ( V_48 )
| F_19 ( V_39 )
| F_20 ( V_37 , V_14 )
| F_21 ( V_36 , V_14 )
| F_22 ( V_49 , V_14 ) ,
V_21 -> V_24 + V_50 ) ;
F_2 ( F_23 ( V_38 )
| F_24 ( V_37 , V_14 )
| F_25 ( V_36 , V_14 )
| F_26 ( V_49 , V_14 ) ,
V_21 -> V_24 + V_51 ) ;
F_2 ( 0 , V_21 -> V_24 + V_52 ) ;
F_2 ( V_53 ,
V_21 -> V_24 + V_54 ) ;
F_14 ( V_14 ) ;
return 0 ;
V_22:
return V_7 ;
}
static unsigned int F_27 ( unsigned int time ,
unsigned int V_55 , unsigned int V_56 )
{
unsigned int V_57 ;
V_57 = ( time + V_55 - 1 ) / V_55 ;
return F_28 ( V_57 , V_56 ) ;
}
static int F_29 ( struct V_13 * V_14 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = & V_62 ;
struct V_19 * V_21 = & V_14 -> V_19 ;
struct V_63 * V_64 = & V_14 -> V_64 ;
struct V_65 V_66 = V_14 -> V_67 ;
bool V_68 ;
unsigned long V_69 ;
unsigned int V_70 ;
bool V_71 ;
unsigned int V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_75 ;
unsigned int V_76 ;
unsigned int V_77 ;
int V_78 ;
unsigned int V_79 ;
int V_80 ;
unsigned int V_81 = V_82 ;
unsigned int V_83 = V_84 ;
if ( V_64 -> V_85 > 2 ) {
V_66 . V_75 += 10 ;
V_66 . V_86 += 10 ;
V_66 . V_87 += 10 ;
} else if ( V_64 -> V_85 > 1 ) {
V_66 . V_75 += 5 ;
V_66 . V_86 += 5 ;
V_66 . V_87 += 5 ;
}
V_68 =
( V_66 . V_88 >= 0 ) &&
( V_66 . V_89 >= 0 ) &&
( V_66 . V_90 >= 0 ) ;
V_61 -> V_69 = F_30 ( V_21 -> clock [ 0 ] ) ;
V_69 = V_61 -> V_69 ;
V_70 = V_91 / V_69 ;
V_76 = F_27 ( V_66 . V_75 ,
V_70 , 1 ) ;
V_77 = F_27 ( V_66 . V_86 ,
V_70 , 1 ) ;
V_74 = F_27 ( V_66 . V_87 ,
V_70 , 0 ) ;
if ( V_70 > ( V_61 -> V_92 >> 1 ) ) {
V_71 = true ;
V_72 = 3 + 1 ;
} else {
V_71 = false ;
V_72 = 3 ;
}
if ( V_70 > V_61 -> V_92 )
V_73 = 0 ;
else {
V_73 =
( V_61 -> V_93 * V_70 ) >>
V_72 ;
if ( V_73 > V_61 -> V_94 )
V_73 = V_61 -> V_94 ;
}
if ( ! V_68 ) {
V_78 = V_66 . V_95 +
V_61 -> V_96 ;
while ( ( V_78 > V_73 ) &&
( V_76 < V_61 -> V_97 ) ) {
V_76 ++ ;
V_78 -= V_70 ;
if ( V_78 < 0 )
V_78 = 0 ;
}
V_79 =
F_27 (
V_78 << V_72 ,
V_70 , 0 ) ;
if ( V_79 > V_61 -> V_93 )
V_79 = V_61 -> V_93 ;
goto V_98;
}
V_83 += V_61 -> V_96 ;
V_75 = V_70 * V_76 ;
V_80 = ( int ) V_81 + ( int ) V_66 . V_90 +
( int ) V_75 ;
V_80 -= ( int ) V_83 + ( int ) V_66 . V_88 ;
while ( ( V_80 <= 0 ) &&
( V_76 < V_61 -> V_97 ) ) {
V_76 ++ ;
V_75 += V_70 ;
V_80 += V_70 ;
}
V_78 =
( ( int ) V_83 +
( int ) V_66 . V_88 +
( int ) V_81 +
( int ) V_66 . V_90 -
( int ) V_75 ) >> 1 ;
if ( V_78 < 0 )
V_78 = 0 ;
while ( ( V_78 > V_73 ) &&
( V_76 < V_61 -> V_97 ) ) {
V_76 ++ ;
V_75 += V_70 ;
V_80 += V_70 ;
V_78 -= ( V_70 >> 1 ) ;
if ( V_78 < 0 )
V_78 = 0 ;
}
V_79 =
F_27 ( V_78 << V_72 ,
V_70 , 0 ) ;
if ( V_79 > V_61 -> V_93 )
V_79 = V_61 -> V_93 ;
#define F_31 ((int) ideal_sample_delay_in_ns)
#define F_32 \
((int) ((sample_delay_factor * clock_period_in_ns) >> \
dll_delay_shift))
#define F_33 (abs(QUANTIZED_DELAY - IDEAL_DELAY))
#define F_34 (DELAY_ERROR > (tEYE >> 1))
while ( F_34 &&
( V_76 < V_61 -> V_97 ) ) {
if ( F_32 > F_31 ) {
if ( V_79 != 0 )
V_79 -- ;
continue;
}
V_76 ++ ;
V_75 += V_70 ;
V_80 += V_70 ;
V_78 -= ( V_70 >> 1 ) ;
V_78 -= V_70 ;
if ( V_78 < 0 )
V_78 = 0 ;
V_79 =
F_27 (
V_78 << V_72 ,
V_70 , 0 ) ;
if ( V_79 > V_61 -> V_93 )
V_79 = V_61 -> V_93 ;
}
V_98:
V_59 -> V_76 = V_76 ;
V_59 -> V_77 = V_77 ;
V_59 -> V_74 = V_74 ;
V_59 -> V_99 = V_71 ;
V_59 -> V_79 = V_79 ;
V_59 -> V_100 = V_101 ;
V_59 -> V_102 = V_103 ;
return 0 ;
}
static void F_35 ( struct V_13 * V_14 ,
struct V_58 * V_59 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
unsigned long V_104 = F_30 ( V_21 -> clock [ 0 ] ) ;
int V_105 = V_14 -> V_106 ;
int V_107 = 16 ;
unsigned long V_108 ;
unsigned long V_109 ;
int V_110 ;
int V_111 = 4 ;
int V_112 ;
int V_113 ;
V_59 -> V_76 = 1 ;
V_59 -> V_77 = 1 ;
V_59 -> V_74 = ( ( V_105 == 5 ) ? 1 : 0 ) ;
V_59 -> V_100 = 0x9000 ;
V_59 -> V_102 = V_114 ;
if ( F_36 ( V_14 ) )
V_107 = 12 ;
V_109 = V_91 / ( V_104 / 10 ) ;
V_107 *= 10 ;
V_110 = ( ( V_105 == 5 ) ? 16 : 20 ) * 10 ;
V_111 *= 10 ;
V_112 = V_109 * 1 ;
if ( V_109 > V_107 ) {
V_59 -> V_99 = 1 ;
V_113 = V_109 / 2 ;
} else {
V_59 -> V_99 = 0 ;
V_113 = V_109 ;
}
V_108 = ( ( ( V_110 + V_111 - V_112 ) * 8 ) * 10 ) / V_113 ;
V_108 = ( V_108 + 5 ) / 10 ;
V_59 -> V_79 = V_108 ;
}
static int F_37 ( struct V_13 * V_14 , int V_105 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
struct V_63 * V_64 = & V_14 -> V_64 ;
struct V_115 * V_116 = & V_14 -> V_116 ;
T_3 V_117 [ V_118 ] = {} ;
unsigned long V_104 ;
int V_7 ;
V_64 -> V_119 ( V_116 , 0 ) ;
V_117 [ 0 ] = V_105 ;
V_7 = V_64 -> V_120 ( V_116 , V_64 ,
V_121 , V_117 ) ;
if ( V_7 )
goto V_22;
memset ( V_117 , 0 , V_118 ) ;
V_7 = V_64 -> V_122 ( V_116 , V_64 ,
V_121 , V_117 ) ;
if ( V_7 || V_117 [ 0 ] != V_105 )
goto V_22;
V_64 -> V_119 ( V_116 , - 1 ) ;
V_104 = ( V_105 == 5 ) ? 100000000 : 80000000 ;
F_38 ( V_21 -> clock [ 0 ] , V_104 ) ;
V_14 -> V_123 &= ~ V_124 ;
V_14 -> V_123 |= V_125 ;
V_14 -> V_106 = V_105 ;
F_39 ( V_14 -> V_126 , L_17 , V_105 ) ;
return 0 ;
V_22:
V_64 -> V_119 ( V_116 , - 1 ) ;
F_40 ( V_14 -> V_126 , L_18 , V_105 ) ;
return - V_127 ;
}
int F_41 ( struct V_13 * V_14 )
{
struct V_63 * V_128 = & V_14 -> V_64 ;
if ( F_36 ( V_14 ) && V_128 -> V_129 ) {
int V_105 = F_42 ( V_128 ) ;
if ( V_105 & V_130 )
V_105 = 5 ;
else if ( V_105 & V_131 )
V_105 = 4 ;
else
return 0 ;
return F_37 ( V_14 , V_105 ) ;
}
return 0 ;
}
void F_43 ( struct V_13 * V_14 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
void T_1 * V_23 = V_21 -> V_23 ;
unsigned int V_70 ;
T_4 V_33 ;
unsigned int V_132 ;
struct V_58 V_59 ;
int V_7 ;
V_7 = F_12 ( V_14 ) ;
if ( V_7 ) {
F_7 ( L_19 ) ;
goto V_22;
}
if ( V_14 -> V_123 & V_124 )
return;
V_14 -> V_123 |= V_124 ;
if ( V_14 -> V_123 & V_125 )
F_35 ( V_14 , & V_59 ) ;
else
F_29 ( V_14 , & V_59 ) ;
V_33 = F_44 ( V_59 . V_74 ) |
F_45 ( V_59 . V_77 ) |
F_46 ( V_59 . V_76 ) ;
F_2 ( V_33 , V_23 + V_133 ) ;
F_2 ( F_47 ( V_59 . V_100 ) ,
V_23 + V_134 ) ;
F_2 ( V_135 , V_23 + V_26 ) ;
F_2 ( F_48 ( V_59 . V_102 ) ,
V_23 + V_28 ) ;
F_2 ( V_136 , V_23 + V_26 ) ;
V_33 = V_137 | V_138 ;
F_2 ( V_33 , V_23 + V_26 ) ;
if ( ! V_59 . V_79 )
return;
V_33 = ( ( V_59 . V_99 ) ? V_138 : 0 )
| F_49 ( V_59 . V_79 ) ;
F_2 ( V_33 , V_23 + V_28 ) ;
F_2 ( V_136 , V_23 + V_28 ) ;
V_70 = V_91 / F_30 ( V_21 -> clock [ 0 ] ) ;
V_132 = ( V_70 * 64 ) / 1000 ;
if ( ! V_132 )
V_132 = 1 ;
F_3 ( V_132 ) ;
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
F_2 ( V_139 , V_21 -> V_24 + V_140 ) ;
}
int F_52 ( struct V_13 * V_14 , unsigned V_128 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
T_4 V_2 = 0 ;
T_4 V_33 = 0 ;
if ( F_13 ( V_14 ) ) {
V_2 = V_141 << V_128 ;
V_33 = F_4 ( V_21 -> V_23 + V_34 ) ;
} else if ( F_53 ( V_14 ) || F_36 ( V_14 ) ) {
V_2 = F_54 ( 1 << V_128 ) ;
V_33 = F_4 ( V_21 -> V_23 + V_142 ) ;
} else
F_7 ( L_20 ) ;
return V_33 & V_2 ;
}
static inline void F_55 ( struct V_13 * V_14 ,
enum V_143 type )
{
V_14 -> V_144 = V_14 -> V_145 ;
V_14 -> V_145 = type ;
}
int F_56 ( struct V_13 * V_14 )
{
struct V_146 * V_147 = F_57 ( V_14 ) ;
struct V_148 * V_149 ;
struct V_150 * V_151 ;
int V_128 = V_14 -> V_152 ;
T_2 V_153 [ 3 ] ;
V_153 [ 0 ] = F_58 ( V_154 )
| V_155
| F_59 ( V_128 , V_14 )
| F_60 ( V_156 , V_14 )
| F_61 ( V_157 )
| V_158
| F_62 ( V_14 -> V_159 ) ;
V_153 [ 1 ] = V_153 [ 2 ] = 0 ;
V_149 = F_63 ( V_147 ,
(struct V_150 * ) V_153 ,
F_64 ( V_153 ) , V_160 , 0 ) ;
if ( ! V_149 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
V_151 = & V_14 -> V_161 ;
F_65 ( V_151 , V_14 -> V_162 , V_14 -> V_159 ) ;
F_66 ( V_14 -> V_126 , V_151 , 1 , V_163 ) ;
V_149 = F_63 ( V_147 ,
V_151 , 1 , V_164 ,
V_165 | V_166 ) ;
if ( ! V_149 ) {
F_7 ( L_22 ) ;
return - 1 ;
}
F_55 ( V_14 , V_167 ) ;
return F_67 ( V_14 , V_149 ) ;
}
int F_68 ( struct V_13 * V_14 )
{
struct V_148 * V_149 ;
struct V_146 * V_147 = F_57 ( V_14 ) ;
int V_128 = V_14 -> V_152 ;
T_4 V_168 ;
T_4 V_169 ;
T_2 V_153 [ 2 ] ;
V_168 = V_154 ;
V_169 = V_170 ;
V_153 [ 0 ] = F_58 ( V_168 )
| V_155
| F_59 ( V_128 , V_14 )
| F_60 ( V_156 , V_14 )
| F_61 ( V_169 )
| F_62 ( V_14 -> V_171 ) ;
V_153 [ 1 ] = 0 ;
V_149 = F_63 ( V_147 , (struct V_150 * ) V_153 ,
F_64 ( V_153 ) , V_160 , 0 ) ;
if ( ! V_149 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
F_69 ( V_14 , V_163 ) ;
V_149 = F_63 ( V_147 , & V_14 -> V_172 ,
1 , V_164 ,
V_165 | V_166 ) ;
if ( ! V_149 ) {
F_7 ( L_22 ) ;
return - 1 ;
}
F_55 ( V_14 , V_173 ) ;
return F_67 ( V_14 , V_149 ) ;
}
int F_70 ( struct V_13 * V_14 )
{
struct V_148 * V_149 ;
struct V_146 * V_147 = F_57 ( V_14 ) ;
int V_128 = V_14 -> V_152 ;
T_2 V_153 [ 2 ] ;
V_153 [ 0 ] = F_58 ( V_174 )
| V_155
| F_59 ( V_128 , V_14 )
| F_60 ( V_156 , V_14 )
| F_61 ( V_170 )
| F_62 ( V_14 -> V_171 ) ;
V_153 [ 1 ] = 0 ;
V_149 = F_63 ( V_147 ,
(struct V_150 * ) V_153 ,
F_64 ( V_153 ) , V_160 , 0 ) ;
if ( ! V_149 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
F_69 ( V_14 , V_175 ) ;
V_149 = F_63 ( V_147 , & V_14 -> V_172 ,
1 , V_176 ,
V_165 | V_166 ) ;
if ( ! V_149 ) {
F_7 ( L_22 ) ;
return - 1 ;
}
F_55 ( V_14 , V_177 ) ;
return F_67 ( V_14 , V_149 ) ;
}
int F_71 ( struct V_13 * V_14 ,
T_5 V_178 , T_5 V_179 )
{
struct V_31 * V_32 = & V_14 -> V_31 ;
T_4 V_168 ;
T_4 V_169 ;
T_4 V_180 ;
T_4 V_181 ;
struct V_148 * V_149 ;
struct V_146 * V_147 = F_57 ( V_14 ) ;
int V_128 = V_14 -> V_152 ;
T_2 V_153 [ 6 ] ;
V_168 = V_154 ;
V_169 = V_170 ;
V_180 = V_182 ;
V_181 = V_183 |
V_184 ;
V_153 [ 0 ] = F_58 ( V_168 )
| V_155
| F_59 ( V_128 , V_14 )
| F_60 ( V_156 , V_14 )
| F_61 ( V_169 )
| F_62 ( 0 ) ;
V_153 [ 1 ] = 0 ;
V_153 [ 2 ] = V_185
| F_72 ( V_180 )
| F_73 ( V_181 ) ;
V_153 [ 3 ] = V_32 -> V_38 ;
V_153 [ 4 ] = V_178 ;
V_153 [ 5 ] = V_179 ;
V_149 = F_63 ( V_147 ,
(struct V_150 * ) V_153 ,
F_64 ( V_153 ) , V_160 ,
V_166 ) ;
if ( ! V_149 ) {
F_7 ( L_22 ) ;
return - 1 ;
}
F_55 ( V_14 , V_186 ) ;
return F_74 ( V_14 , V_149 ) ;
}
int F_75 ( struct V_13 * V_14 ,
T_5 V_178 , T_5 V_179 )
{
struct V_31 * V_32 = & V_14 -> V_31 ;
T_4 V_168 ;
T_4 V_169 ;
T_4 V_180 ;
T_4 V_181 ;
struct V_148 * V_149 ;
struct V_146 * V_147 = F_57 ( V_14 ) ;
int V_128 = V_14 -> V_152 ;
T_2 V_153 [ 6 ] ;
V_168 = V_187 ;
V_169 = V_170 ;
V_153 [ 0 ] = F_58 ( V_168 )
| V_155
| F_59 ( V_128 , V_14 )
| F_60 ( V_156 , V_14 )
| F_61 ( V_169 )
| F_62 ( 0 ) ;
V_153 [ 1 ] = 0 ;
V_149 = F_63 ( V_147 ,
(struct V_150 * ) V_153 , 2 ,
V_160 , 0 ) ;
if ( ! V_149 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
V_168 = V_174 ;
V_169 = V_170 ;
V_180 = V_188 ;
V_181 = V_183
| V_184 ;
V_153 [ 0 ] = F_58 ( V_168 )
| V_155
| F_59 ( V_128 , V_14 )
| F_60 ( V_156 , V_14 )
| F_61 ( V_169 )
| F_62 ( V_32 -> V_38 ) ;
V_153 [ 1 ] = 0 ;
V_153 [ 2 ] = V_185
| F_72 ( V_180 )
| F_73 ( V_181 ) ;
V_153 [ 3 ] = V_32 -> V_38 ;
V_153 [ 4 ] = V_178 ;
V_153 [ 5 ] = V_179 ;
V_149 = F_63 ( V_147 ,
(struct V_150 * ) V_153 ,
F_64 ( V_153 ) , V_160 ,
V_165 | V_166 ) ;
if ( ! V_149 ) {
F_7 ( L_22 ) ;
return - 1 ;
}
V_168 = V_187 ;
V_169 = V_170 ;
V_153 [ 0 ] = F_58 ( V_168 )
| V_155
| F_59 ( V_128 , V_14 )
| F_60 ( V_156 , V_14 )
| F_61 ( V_169 )
| F_62 ( V_32 -> V_38 ) ;
V_153 [ 1 ] = 0 ;
V_153 [ 2 ] = 0 ;
V_149 = F_63 ( V_147 ,
(struct V_150 * ) V_153 , 3 ,
V_160 ,
V_165 | V_166 ) ;
if ( ! V_149 ) {
F_7 ( L_23 ) ;
return - 1 ;
}
F_55 ( V_14 , V_189 ) ;
return F_74 ( V_14 , V_149 ) ;
}
