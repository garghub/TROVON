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
F_7 ( L_5 , V_32 -> V_35 ) ;
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
}
int F_16 ( struct V_13 * V_14 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
struct V_31 * V_46 = & V_14 -> V_31 ;
unsigned int V_47 ;
unsigned int V_48 ;
unsigned int V_38 ;
unsigned int V_36 ;
unsigned int V_37 ;
int V_7 ;
if ( F_17 ( V_14 ) )
return ! 0 ;
V_47 = V_46 -> V_40 - 1 ;
V_48 = V_46 -> V_39 ;
V_38 = V_46 -> V_38 ;
V_36 = V_46 -> V_36 >> 1 ;
V_37 = V_46 -> V_37 ;
V_7 = F_12 ( V_14 ) ;
if ( V_7 )
goto V_22;
V_7 = F_5 ( V_21 -> V_24 , F_13 ( V_14 ) ) ;
if ( V_7 )
goto V_22;
F_2 ( F_18 ( V_47 )
| F_19 ( V_38 )
| F_20 ( V_36 , V_14 )
| F_21 ( V_48 , V_14 ) ,
V_21 -> V_24 + V_49 ) ;
F_2 ( F_22 ( V_37 )
| F_23 ( V_36 , V_14 )
| F_24 ( V_48 , V_14 ) ,
V_21 -> V_24 + V_50 ) ;
F_2 ( 0 , V_21 -> V_24 + V_51 ) ;
F_2 ( V_52 ,
V_21 -> V_24 + V_53 ) ;
F_14 ( V_14 ) ;
return 0 ;
V_22:
return V_7 ;
}
static unsigned int F_25 ( unsigned int time ,
unsigned int V_54 , unsigned int V_55 )
{
unsigned int V_56 ;
V_56 = ( time + V_54 - 1 ) / V_54 ;
return F_26 ( V_56 , V_55 ) ;
}
static int F_27 ( struct V_13 * V_14 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 = & V_61 ;
struct V_19 * V_21 = & V_14 -> V_19 ;
struct V_62 * V_63 = & V_14 -> V_63 ;
struct V_64 V_65 = V_14 -> V_66 ;
bool V_67 ;
unsigned long V_68 ;
unsigned int V_69 ;
bool V_70 ;
unsigned int V_71 ;
unsigned int V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_75 ;
unsigned int V_76 ;
int V_77 ;
unsigned int V_78 ;
int V_79 ;
unsigned int V_80 = V_81 ;
unsigned int V_82 = V_83 ;
if ( V_63 -> V_84 > 2 ) {
V_65 . V_74 += 10 ;
V_65 . V_85 += 10 ;
V_65 . V_86 += 10 ;
} else if ( V_63 -> V_84 > 1 ) {
V_65 . V_74 += 5 ;
V_65 . V_85 += 5 ;
V_65 . V_86 += 5 ;
}
V_67 =
( V_65 . V_87 >= 0 ) &&
( V_65 . V_88 >= 0 ) &&
( V_65 . V_89 >= 0 ) ;
V_60 -> V_68 = F_28 ( V_21 -> clock [ 0 ] ) ;
V_68 = V_60 -> V_68 ;
V_69 = V_90 / V_68 ;
V_75 = F_25 ( V_65 . V_74 ,
V_69 , 1 ) ;
V_76 = F_25 ( V_65 . V_85 ,
V_69 , 1 ) ;
V_73 = F_25 ( V_65 . V_86 ,
V_69 , 0 ) ;
if ( V_69 > ( V_60 -> V_91 >> 1 ) ) {
V_70 = true ;
V_71 = 3 + 1 ;
} else {
V_70 = false ;
V_71 = 3 ;
}
if ( V_69 > V_60 -> V_91 )
V_72 = 0 ;
else {
V_72 =
( V_60 -> V_92 * V_69 ) >>
V_71 ;
if ( V_72 > V_60 -> V_93 )
V_72 = V_60 -> V_93 ;
}
if ( ! V_67 ) {
V_77 = V_65 . V_94 +
V_60 -> V_95 ;
while ( ( V_77 > V_72 ) &&
( V_75 < V_60 -> V_96 ) ) {
V_75 ++ ;
V_77 -= V_69 ;
if ( V_77 < 0 )
V_77 = 0 ;
}
V_78 =
F_25 (
V_77 << V_71 ,
V_69 , 0 ) ;
if ( V_78 > V_60 -> V_92 )
V_78 = V_60 -> V_92 ;
goto V_97;
}
V_82 += V_60 -> V_95 ;
V_74 = V_69 * V_75 ;
V_79 = ( int ) V_80 + ( int ) V_65 . V_89 +
( int ) V_74 ;
V_79 -= ( int ) V_82 + ( int ) V_65 . V_87 ;
while ( ( V_79 <= 0 ) &&
( V_75 < V_60 -> V_96 ) ) {
V_75 ++ ;
V_74 += V_69 ;
V_79 += V_69 ;
}
V_77 =
( ( int ) V_82 +
( int ) V_65 . V_87 +
( int ) V_80 +
( int ) V_65 . V_89 -
( int ) V_74 ) >> 1 ;
if ( V_77 < 0 )
V_77 = 0 ;
while ( ( V_77 > V_72 ) &&
( V_75 < V_60 -> V_96 ) ) {
V_75 ++ ;
V_74 += V_69 ;
V_79 += V_69 ;
V_77 -= ( V_69 >> 1 ) ;
if ( V_77 < 0 )
V_77 = 0 ;
}
V_78 =
F_25 ( V_77 << V_71 ,
V_69 , 0 ) ;
if ( V_78 > V_60 -> V_92 )
V_78 = V_60 -> V_92 ;
#define F_29 ((int) ideal_sample_delay_in_ns)
#define F_30 \
((int) ((sample_delay_factor * clock_period_in_ns) >> \
dll_delay_shift))
#define F_31 (abs(QUANTIZED_DELAY - IDEAL_DELAY))
#define F_32 (DELAY_ERROR > (tEYE >> 1))
while ( F_32 &&
( V_75 < V_60 -> V_96 ) ) {
if ( F_30 > F_29 ) {
if ( V_78 != 0 )
V_78 -- ;
continue;
}
V_75 ++ ;
V_74 += V_69 ;
V_79 += V_69 ;
V_77 -= ( V_69 >> 1 ) ;
V_77 -= V_69 ;
if ( V_77 < 0 )
V_77 = 0 ;
V_78 =
F_25 (
V_77 << V_71 ,
V_69 , 0 ) ;
if ( V_78 > V_60 -> V_92 )
V_78 = V_60 -> V_92 ;
}
V_97:
V_58 -> V_75 = V_75 ;
V_58 -> V_76 = V_76 ;
V_58 -> V_73 = V_73 ;
V_58 -> V_98 = V_70 ;
V_58 -> V_78 = V_78 ;
V_58 -> V_99 = V_100 ;
V_58 -> V_101 = V_102 ;
return 0 ;
}
static void F_33 ( struct V_13 * V_14 ,
struct V_57 * V_58 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
unsigned long V_103 = F_28 ( V_21 -> clock [ 0 ] ) ;
int V_104 = V_14 -> V_105 ;
int V_106 = 16 ;
unsigned long V_107 ;
unsigned long V_108 ;
int V_109 ;
int V_110 = 4 ;
int V_111 ;
int V_112 ;
V_58 -> V_75 = 1 ;
V_58 -> V_76 = 1 ;
V_58 -> V_73 = ( ( V_104 == 5 ) ? 1 : 0 ) ;
V_58 -> V_99 = 0x9000 ;
V_58 -> V_101 = V_113 ;
if ( F_34 ( V_14 ) )
V_106 = 12 ;
V_108 = V_90 / ( V_103 / 10 ) ;
V_106 *= 10 ;
V_109 = ( ( V_104 == 5 ) ? 16 : 20 ) * 10 ;
V_110 *= 10 ;
V_111 = V_108 * 1 ;
if ( V_108 > V_106 ) {
V_58 -> V_98 = 1 ;
V_112 = V_108 / 2 ;
} else {
V_58 -> V_98 = 0 ;
V_112 = V_108 ;
}
V_107 = ( ( ( V_109 + V_110 - V_111 ) * 8 ) * 10 ) / V_112 ;
V_107 = ( V_107 + 5 ) / 10 ;
V_58 -> V_78 = V_107 ;
}
static int F_35 ( struct V_13 * V_14 , int V_104 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
struct V_62 * V_63 = & V_14 -> V_63 ;
struct V_114 * V_115 = & V_14 -> V_115 ;
T_3 V_116 [ V_117 ] = {} ;
unsigned long V_103 ;
int V_7 ;
V_63 -> V_118 ( V_115 , 0 ) ;
V_116 [ 0 ] = V_104 ;
V_7 = V_63 -> V_119 ( V_115 , V_63 ,
V_120 , V_116 ) ;
if ( V_7 )
goto V_22;
memset ( V_116 , 0 , V_117 ) ;
V_7 = V_63 -> V_121 ( V_115 , V_63 ,
V_120 , V_116 ) ;
if ( V_7 || V_116 [ 0 ] != V_104 )
goto V_22;
V_63 -> V_118 ( V_115 , - 1 ) ;
V_103 = ( V_104 == 5 ) ? 100000000 : 80000000 ;
F_36 ( V_21 -> clock [ 0 ] , V_103 ) ;
V_14 -> V_122 &= ~ V_123 ;
V_14 -> V_122 |= V_124 ;
V_14 -> V_105 = V_104 ;
F_37 ( V_14 -> V_125 , L_16 , V_104 ) ;
return 0 ;
V_22:
V_63 -> V_118 ( V_115 , - 1 ) ;
F_38 ( V_14 -> V_125 , L_17 , V_104 ) ;
return - V_126 ;
}
int F_39 ( struct V_13 * V_14 )
{
struct V_62 * V_127 = & V_14 -> V_63 ;
if ( F_34 ( V_14 ) && V_127 -> V_128 ) {
int V_104 = F_40 ( V_127 ) ;
if ( V_104 & V_129 )
V_104 = 5 ;
else if ( V_104 & V_130 )
V_104 = 4 ;
else
return 0 ;
return F_35 ( V_14 , V_104 ) ;
}
return 0 ;
}
void F_41 ( struct V_13 * V_14 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
void T_1 * V_23 = V_21 -> V_23 ;
unsigned int V_69 ;
T_4 V_33 ;
unsigned int V_131 ;
struct V_57 V_58 ;
int V_7 ;
V_7 = F_12 ( V_14 ) ;
if ( V_7 ) {
F_7 ( L_18 ) ;
goto V_22;
}
if ( V_14 -> V_122 & V_123 )
return;
V_14 -> V_122 |= V_123 ;
if ( V_14 -> V_122 & V_124 )
F_33 ( V_14 , & V_58 ) ;
else
F_27 ( V_14 , & V_58 ) ;
V_33 = F_42 ( V_58 . V_73 ) |
F_43 ( V_58 . V_76 ) |
F_44 ( V_58 . V_75 ) ;
F_2 ( V_33 , V_23 + V_132 ) ;
F_2 ( F_45 ( V_58 . V_99 ) ,
V_23 + V_133 ) ;
F_2 ( V_134 , V_23 + V_26 ) ;
F_2 ( F_46 ( V_58 . V_101 ) ,
V_23 + V_28 ) ;
F_2 ( V_135 , V_23 + V_26 ) ;
V_33 = V_136 | V_137 ;
F_2 ( V_33 , V_23 + V_26 ) ;
if ( ! V_58 . V_78 )
return;
V_33 = ( ( V_58 . V_98 ) ? V_137 : 0 )
| F_47 ( V_58 . V_78 ) ;
F_2 ( V_33 , V_23 + V_28 ) ;
F_2 ( V_135 , V_23 + V_28 ) ;
V_69 = V_90 / F_28 ( V_21 -> clock [ 0 ] ) ;
V_131 = ( V_69 * 64 ) / 1000 ;
if ( ! V_131 )
V_131 = 1 ;
F_3 ( V_131 ) ;
V_22:
return;
}
void F_48 ( struct V_13 * V_14 )
{
F_14 ( V_14 ) ;
}
void F_49 ( struct V_13 * V_14 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
F_2 ( V_138 , V_21 -> V_24 + V_139 ) ;
}
int F_50 ( struct V_13 * V_14 , unsigned V_127 )
{
struct V_19 * V_21 = & V_14 -> V_19 ;
T_4 V_2 = 0 ;
T_4 V_33 = 0 ;
if ( F_13 ( V_14 ) ) {
V_2 = V_140 << V_127 ;
V_33 = F_4 ( V_21 -> V_23 + V_34 ) ;
} else if ( F_51 ( V_14 ) || F_34 ( V_14 ) ) {
V_2 = F_52 ( 1 << V_127 ) ;
V_33 = F_4 ( V_21 -> V_23 + V_141 ) ;
} else
F_7 ( L_19 ) ;
return V_33 & V_2 ;
}
static inline void F_53 ( struct V_13 * V_14 ,
enum V_142 type )
{
V_14 -> V_143 = V_14 -> V_144 ;
V_14 -> V_144 = type ;
}
int F_54 ( struct V_13 * V_14 )
{
struct V_145 * V_146 = F_55 ( V_14 ) ;
struct V_147 * V_148 ;
struct V_149 * V_150 ;
int V_127 = V_14 -> V_151 ;
T_2 V_152 [ 3 ] ;
V_152 [ 0 ] = F_56 ( V_153 )
| V_154
| F_57 ( V_127 , V_14 )
| F_58 ( V_155 , V_14 )
| F_59 ( V_156 )
| V_157
| F_60 ( V_14 -> V_158 ) ;
V_152 [ 1 ] = V_152 [ 2 ] = 0 ;
V_148 = F_61 ( V_146 ,
(struct V_149 * ) V_152 ,
F_62 ( V_152 ) , V_159 , 0 ) ;
if ( ! V_148 ) {
F_7 ( L_20 ) ;
return - 1 ;
}
V_150 = & V_14 -> V_160 ;
F_63 ( V_150 , V_14 -> V_161 , V_14 -> V_158 ) ;
F_64 ( V_14 -> V_125 , V_150 , 1 , V_162 ) ;
V_148 = F_61 ( V_146 ,
V_150 , 1 , V_163 ,
V_164 | V_165 ) ;
if ( ! V_148 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
F_53 ( V_14 , V_166 ) ;
return F_65 ( V_14 , V_148 ) ;
}
int F_66 ( struct V_13 * V_14 )
{
struct V_147 * V_148 ;
struct V_145 * V_146 = F_55 ( V_14 ) ;
int V_127 = V_14 -> V_151 ;
T_4 V_167 ;
T_4 V_168 ;
T_2 V_152 [ 2 ] ;
V_167 = V_153 ;
V_168 = V_169 ;
V_152 [ 0 ] = F_56 ( V_167 )
| V_154
| F_57 ( V_127 , V_14 )
| F_58 ( V_155 , V_14 )
| F_59 ( V_168 )
| F_60 ( V_14 -> V_170 ) ;
V_152 [ 1 ] = 0 ;
V_148 = F_61 ( V_146 , (struct V_149 * ) V_152 ,
F_62 ( V_152 ) , V_159 , 0 ) ;
if ( ! V_148 ) {
F_7 ( L_20 ) ;
return - 1 ;
}
F_67 ( V_14 , V_162 ) ;
V_148 = F_61 ( V_146 , & V_14 -> V_171 ,
1 , V_163 ,
V_164 | V_165 ) ;
if ( ! V_148 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
F_53 ( V_14 , V_172 ) ;
return F_65 ( V_14 , V_148 ) ;
}
int F_68 ( struct V_13 * V_14 )
{
struct V_147 * V_148 ;
struct V_145 * V_146 = F_55 ( V_14 ) ;
int V_127 = V_14 -> V_151 ;
T_2 V_152 [ 2 ] ;
V_152 [ 0 ] = F_56 ( V_173 )
| V_154
| F_57 ( V_127 , V_14 )
| F_58 ( V_155 , V_14 )
| F_59 ( V_169 )
| F_60 ( V_14 -> V_170 ) ;
V_152 [ 1 ] = 0 ;
V_148 = F_61 ( V_146 ,
(struct V_149 * ) V_152 ,
F_62 ( V_152 ) , V_159 , 0 ) ;
if ( ! V_148 ) {
F_7 ( L_20 ) ;
return - 1 ;
}
F_67 ( V_14 , V_174 ) ;
V_148 = F_61 ( V_146 , & V_14 -> V_171 ,
1 , V_175 ,
V_164 | V_165 ) ;
if ( ! V_148 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
F_53 ( V_14 , V_176 ) ;
return F_65 ( V_14 , V_148 ) ;
}
int F_69 ( struct V_13 * V_14 ,
T_5 V_177 , T_5 V_178 )
{
struct V_31 * V_32 = & V_14 -> V_31 ;
T_4 V_167 ;
T_4 V_168 ;
T_4 V_179 ;
T_4 V_180 ;
struct V_147 * V_148 ;
struct V_145 * V_146 = F_55 ( V_14 ) ;
int V_127 = V_14 -> V_151 ;
T_2 V_152 [ 6 ] ;
V_167 = V_153 ;
V_168 = V_169 ;
V_179 = V_181 ;
V_180 = V_182 |
V_183 ;
V_152 [ 0 ] = F_56 ( V_167 )
| V_154
| F_57 ( V_127 , V_14 )
| F_58 ( V_155 , V_14 )
| F_59 ( V_168 )
| F_60 ( 0 ) ;
V_152 [ 1 ] = 0 ;
V_152 [ 2 ] = V_184
| F_70 ( V_179 )
| F_71 ( V_180 ) ;
V_152 [ 3 ] = V_32 -> V_37 ;
V_152 [ 4 ] = V_177 ;
V_152 [ 5 ] = V_178 ;
V_148 = F_61 ( V_146 ,
(struct V_149 * ) V_152 ,
F_62 ( V_152 ) , V_159 ,
V_165 ) ;
if ( ! V_148 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
F_53 ( V_14 , V_185 ) ;
return F_72 ( V_14 , V_148 ) ;
}
int F_73 ( struct V_13 * V_14 ,
T_5 V_177 , T_5 V_178 )
{
struct V_31 * V_32 = & V_14 -> V_31 ;
T_4 V_167 ;
T_4 V_168 ;
T_4 V_179 ;
T_4 V_180 ;
struct V_147 * V_148 ;
struct V_145 * V_146 = F_55 ( V_14 ) ;
int V_127 = V_14 -> V_151 ;
T_2 V_152 [ 6 ] ;
V_167 = V_186 ;
V_168 = V_169 ;
V_152 [ 0 ] = F_56 ( V_167 )
| V_154
| F_57 ( V_127 , V_14 )
| F_58 ( V_155 , V_14 )
| F_59 ( V_168 )
| F_60 ( 0 ) ;
V_152 [ 1 ] = 0 ;
V_148 = F_61 ( V_146 ,
(struct V_149 * ) V_152 , 2 ,
V_159 , 0 ) ;
if ( ! V_148 ) {
F_7 ( L_20 ) ;
return - 1 ;
}
V_167 = V_173 ;
V_168 = V_169 ;
V_179 = V_187 ;
V_180 = V_182
| V_183 ;
V_152 [ 0 ] = F_56 ( V_167 )
| V_154
| F_57 ( V_127 , V_14 )
| F_58 ( V_155 , V_14 )
| F_59 ( V_168 )
| F_60 ( V_32 -> V_37 ) ;
V_152 [ 1 ] = 0 ;
V_152 [ 2 ] = V_184
| F_70 ( V_179 )
| F_71 ( V_180 ) ;
V_152 [ 3 ] = V_32 -> V_37 ;
V_152 [ 4 ] = V_177 ;
V_152 [ 5 ] = V_178 ;
V_148 = F_61 ( V_146 ,
(struct V_149 * ) V_152 ,
F_62 ( V_152 ) , V_159 ,
V_164 | V_165 ) ;
if ( ! V_148 ) {
F_7 ( L_21 ) ;
return - 1 ;
}
V_167 = V_186 ;
V_168 = V_169 ;
V_152 [ 0 ] = F_56 ( V_167 )
| V_154
| F_57 ( V_127 , V_14 )
| F_58 ( V_155 , V_14 )
| F_59 ( V_168 )
| F_60 ( V_32 -> V_37 ) ;
V_152 [ 1 ] = 0 ;
V_152 [ 2 ] = 0 ;
V_148 = F_61 ( V_146 ,
(struct V_149 * ) V_152 , 3 ,
V_159 ,
V_164 | V_165 ) ;
if ( ! V_148 ) {
F_7 ( L_22 ) ;
return - 1 ;
}
F_53 ( V_14 , V_188 ) ;
return F_72 ( V_14 , V_148 ) ;
}
