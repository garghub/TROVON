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
int F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_15 ;
int V_7 ;
V_7 = F_9 ( V_16 -> clock ) ;
if ( V_7 )
goto V_17;
V_7 = F_5 ( V_16 -> V_18 , false ) ;
if ( V_7 )
goto V_17;
F_2 ( V_19 , V_16 -> V_18 + V_20 ) ;
F_2 ( V_21 ,
V_16 -> V_18 + V_22 ) ;
F_2 ( V_23 , V_16 -> V_18 + V_22 ) ;
F_2 ( V_24 , V_16 -> V_18 + V_22 ) ;
F_10 ( V_16 -> clock ) ;
return 0 ;
V_17:
return V_7 ;
}
void F_11 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_15 ;
struct V_25 * V_26 = & V_14 -> V_25 ;
T_2 V_27 ;
int V_28 ;
F_7 ( L_2 ) ;
for ( V_28 = 0 ; V_28 <= V_29 / 0x10 + 1 ; V_28 ++ ) {
V_27 = F_4 ( V_16 -> V_18 + V_28 * 0x10 ) ;
F_7 ( L_3 , V_28 * 0x10 , V_27 ) ;
}
F_7 ( L_4 ) ;
F_7 ( L_5 , V_26 -> V_30 ) ;
F_7 ( L_6 , V_26 -> V_31 ) ;
F_7 ( L_7 , V_26 -> V_32 ) ;
F_7 ( L_8 , V_26 -> V_33 ) ;
F_7 ( L_9 , V_26 -> V_34 ) ;
F_7 ( L_10 , V_26 -> V_35 ) ;
F_7 ( L_11 , V_26 -> V_36 ) ;
F_7 ( L_12 , V_26 -> V_37 ) ;
F_7 ( L_13 , V_26 -> V_38 ) ;
F_7 ( L_14 , V_26 -> V_39 ) ;
F_7 ( L_15 , V_26 -> V_40 ) ;
}
int F_12 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_15 ;
struct V_25 * V_41 = & V_14 -> V_25 ;
unsigned int V_42 ;
unsigned int V_43 ;
unsigned int V_33 ;
unsigned int V_31 ;
unsigned int V_32 ;
int V_7 ;
if ( F_13 ( V_14 ) )
return ! 0 ;
V_42 = V_41 -> V_35 - 1 ;
V_43 = V_41 -> V_34 ;
V_33 = V_41 -> V_33 ;
V_31 = V_41 -> V_31 >> 1 ;
V_32 = V_41 -> V_32 ;
V_7 = F_9 ( V_16 -> clock ) ;
if ( V_7 )
goto V_17;
V_7 = F_5 ( V_16 -> V_44 , F_14 ( V_14 ) ) ;
if ( V_7 )
goto V_17;
F_2 ( F_15 ( V_42 )
| F_16 ( V_33 )
| F_17 ( V_31 , V_14 )
| F_18 ( V_43 , V_14 ) ,
V_16 -> V_44 + V_45 ) ;
F_2 ( F_19 ( V_32 )
| F_20 ( V_31 , V_14 )
| F_21 ( V_43 , V_14 ) ,
V_16 -> V_44 + V_46 ) ;
F_2 ( 0 , V_16 -> V_44 + V_47 ) ;
F_2 ( V_48 ,
V_16 -> V_44 + V_49 ) ;
F_10 ( V_16 -> clock ) ;
return 0 ;
V_17:
return V_7 ;
}
static unsigned int F_22 ( unsigned int time ,
unsigned int V_50 , unsigned int V_51 )
{
unsigned int V_52 ;
V_52 = ( time + V_50 - 1 ) / V_50 ;
return F_23 ( V_52 , V_51 ) ;
}
static int F_24 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = & V_57 ;
struct V_58 * V_59 = & V_14 -> V_59 ;
struct V_60 V_61 = V_14 -> V_62 ;
bool V_63 ;
unsigned long V_64 ;
unsigned int V_65 ;
bool V_66 ;
unsigned int V_67 ;
unsigned int V_68 ;
unsigned int V_69 ;
unsigned int V_70 ;
unsigned int V_71 ;
unsigned int V_72 ;
int V_73 ;
unsigned int V_74 ;
int V_75 ;
unsigned int V_76 = V_77 ;
unsigned int V_78 = V_79 ;
if ( V_59 -> V_80 > 2 ) {
V_61 . V_70 += 10 ;
V_61 . V_81 += 10 ;
V_61 . V_82 += 10 ;
} else if ( V_59 -> V_80 > 1 ) {
V_61 . V_70 += 5 ;
V_61 . V_81 += 5 ;
V_61 . V_82 += 5 ;
}
V_63 =
( V_61 . V_83 >= 0 ) &&
( V_61 . V_84 >= 0 ) &&
( V_61 . V_85 >= 0 ) ;
V_64 = V_56 -> V_64 ;
V_65 = 1000000000 / V_64 ;
V_71 = F_22 ( V_61 . V_70 ,
V_65 , 1 ) ;
V_72 = F_22 ( V_61 . V_81 ,
V_65 , 1 ) ;
V_69 = F_22 ( V_61 . V_82 ,
V_65 , 0 ) ;
if ( V_65 > ( V_56 -> V_86 >> 1 ) ) {
V_66 = true ;
V_67 = 3 + 1 ;
} else {
V_66 = false ;
V_67 = 3 ;
}
if ( V_65 > V_56 -> V_86 )
V_68 = 0 ;
else {
V_68 =
( V_56 -> V_87 * V_65 ) >>
V_67 ;
if ( V_68 > V_56 -> V_88 )
V_68 = V_56 -> V_88 ;
}
if ( ! V_63 ) {
V_73 = V_61 . V_89 +
V_56 -> V_90 ;
while ( ( V_73 > V_68 ) &&
( V_71 < V_56 -> V_91 ) ) {
V_71 ++ ;
V_73 -= V_65 ;
if ( V_73 < 0 )
V_73 = 0 ;
}
V_74 =
F_22 (
V_73 << V_67 ,
V_65 , 0 ) ;
if ( V_74 > V_56 -> V_87 )
V_74 = V_56 -> V_87 ;
goto V_92;
}
V_78 += V_56 -> V_90 ;
V_70 = V_65 * V_71 ;
V_75 = ( int ) V_76 + ( int ) V_61 . V_85 +
( int ) V_70 ;
V_75 -= ( int ) V_78 + ( int ) V_61 . V_83 ;
while ( ( V_75 <= 0 ) &&
( V_71 < V_56 -> V_91 ) ) {
V_71 ++ ;
V_70 += V_65 ;
V_75 += V_65 ;
}
V_73 =
( ( int ) V_78 +
( int ) V_61 . V_83 +
( int ) V_76 +
( int ) V_61 . V_85 -
( int ) V_70 ) >> 1 ;
if ( V_73 < 0 )
V_73 = 0 ;
while ( ( V_73 > V_68 ) &&
( V_71 < V_56 -> V_91 ) ) {
V_71 ++ ;
V_70 += V_65 ;
V_75 += V_65 ;
V_73 -= ( V_65 >> 1 ) ;
if ( V_73 < 0 )
V_73 = 0 ;
}
V_74 =
F_22 ( V_73 << V_67 ,
V_65 , 0 ) ;
if ( V_74 > V_56 -> V_87 )
V_74 = V_56 -> V_87 ;
#define F_25 ((int) ideal_sample_delay_in_ns)
#define F_26 \
((int) ((sample_delay_factor * clock_period_in_ns) >> \
dll_delay_shift))
#define F_27 (abs(QUANTIZED_DELAY - IDEAL_DELAY))
#define F_28 (DELAY_ERROR > (tEYE >> 1))
while ( F_28 &&
( V_71 < V_56 -> V_91 ) ) {
if ( F_26 > F_25 ) {
if ( V_74 != 0 )
V_74 -- ;
continue;
}
V_71 ++ ;
V_70 += V_65 ;
V_75 += V_65 ;
V_73 -= ( V_65 >> 1 ) ;
V_73 -= V_65 ;
if ( V_73 < 0 )
V_73 = 0 ;
V_74 =
F_22 (
V_73 << V_67 ,
V_65 , 0 ) ;
if ( V_74 > V_56 -> V_87 )
V_74 = V_56 -> V_87 ;
}
V_92:
V_54 -> V_71 = V_71 ;
V_54 -> V_72 = V_72 ;
V_54 -> V_69 = V_69 ;
V_54 -> V_93 = V_66 ;
V_54 -> V_74 = V_74 ;
return 0 ;
}
void F_29 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_15 ;
struct V_55 * V_56 = & V_57 ;
unsigned char * V_18 = V_16 -> V_18 ;
unsigned int V_65 ;
T_3 V_27 ;
unsigned int V_94 ;
struct V_53 V_54 ;
int V_7 ;
V_7 = F_9 ( V_16 -> clock ) ;
if ( V_7 ) {
F_7 ( L_16 ) ;
goto V_17;
}
F_2 ( 0x500 << V_95 ,
V_18 + V_96 ) ;
V_56 -> V_64 = F_30 ( V_16 -> clock ) ;
V_65 = 1000000000 / V_56 -> V_64 ;
F_24 ( V_14 , & V_54 ) ;
V_27 = F_31 ( V_54 . V_69 ) |
F_32 ( V_54 . V_72 ) |
F_33 ( V_54 . V_71 ) ;
F_2 ( V_27 , V_18 + V_97 ) ;
F_2 ( V_98 , V_18 + V_20 ) ;
F_2 ( V_99 , V_18 + V_20 ) ;
F_2 ( V_100 , V_18 + V_20 ) ;
if ( ! V_54 . V_74 )
return;
if ( V_54 . V_93 )
F_2 ( V_100 ,
V_18 + V_22 ) ;
F_2 ( F_34 ( V_54 . V_74 ) ,
V_18 + V_22 ) ;
F_2 ( V_98 , V_18 + V_22 ) ;
V_94 = ( V_65 * 64 ) / 1000 ;
if ( ! V_94 )
V_94 = 1 ;
F_3 ( V_94 ) ;
V_17:
return;
}
void F_35 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_15 ;
F_10 ( V_16 -> clock ) ;
}
void F_36 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_15 ;
F_2 ( V_101 , V_16 -> V_44 + V_102 ) ;
}
int F_37 ( struct V_13 * V_14 , unsigned V_103 )
{
struct V_15 * V_16 = & V_14 -> V_15 ;
T_3 V_2 = 0 ;
T_3 V_27 = 0 ;
if ( F_14 ( V_14 ) ) {
V_2 = V_104 << V_103 ;
V_27 = F_4 ( V_16 -> V_18 + V_29 ) ;
} else if ( F_38 ( V_14 ) || F_39 ( V_14 ) ) {
V_2 = F_40 ( 1 << V_103 ) ;
V_27 = F_4 ( V_16 -> V_18 + V_105 ) ;
} else
F_7 ( L_17 ) ;
return V_27 & V_2 ;
}
static inline void F_41 ( struct V_13 * V_14 ,
enum V_106 type )
{
V_14 -> V_107 = V_14 -> V_108 ;
V_14 -> V_108 = type ;
}
int F_42 ( struct V_13 * V_14 )
{
struct V_109 * V_110 = F_43 ( V_14 ) ;
struct V_111 * V_112 ;
struct V_113 * V_114 ;
int V_103 = V_14 -> V_115 ;
T_2 V_116 [ 3 ] ;
V_116 [ 0 ] = F_44 ( V_117 )
| V_118
| F_45 ( V_103 , V_14 )
| F_46 ( V_119 , V_14 )
| F_47 ( V_120 )
| V_121
| F_48 ( V_14 -> V_122 ) ;
V_116 [ 1 ] = V_116 [ 2 ] = 0 ;
V_112 = F_49 ( V_110 ,
(struct V_113 * ) V_116 ,
F_50 ( V_116 ) , V_123 , 0 ) ;
if ( ! V_112 ) {
F_7 ( L_18 ) ;
return - 1 ;
}
V_114 = & V_14 -> V_124 ;
F_51 ( V_114 , V_14 -> V_125 , V_14 -> V_122 ) ;
F_52 ( V_14 -> V_126 , V_114 , 1 , V_127 ) ;
V_112 = F_49 ( V_110 ,
V_114 , 1 , V_128 ,
V_129 | V_130 ) ;
if ( ! V_112 ) {
F_7 ( L_19 ) ;
return - 1 ;
}
F_41 ( V_14 , V_131 ) ;
return F_53 ( V_14 , V_112 ) ;
}
int F_54 ( struct V_13 * V_14 )
{
struct V_111 * V_112 ;
struct V_109 * V_110 = F_43 ( V_14 ) ;
int V_103 = V_14 -> V_115 ;
T_3 V_132 ;
T_3 V_133 ;
T_2 V_116 [ 2 ] ;
V_132 = V_117 ;
V_133 = V_134 ;
V_116 [ 0 ] = F_44 ( V_132 )
| V_118
| F_45 ( V_103 , V_14 )
| F_46 ( V_119 , V_14 )
| F_47 ( V_133 )
| F_48 ( V_14 -> V_135 ) ;
V_116 [ 1 ] = 0 ;
V_112 = F_49 ( V_110 , (struct V_113 * ) V_116 ,
F_50 ( V_116 ) , V_123 , 0 ) ;
if ( ! V_112 ) {
F_7 ( L_18 ) ;
return - 1 ;
}
F_55 ( V_14 , V_127 ) ;
V_112 = F_49 ( V_110 , & V_14 -> V_136 ,
1 , V_128 ,
V_129 | V_130 ) ;
if ( ! V_112 ) {
F_7 ( L_19 ) ;
return - 1 ;
}
F_41 ( V_14 , V_137 ) ;
return F_53 ( V_14 , V_112 ) ;
}
int F_56 ( struct V_13 * V_14 )
{
struct V_111 * V_112 ;
struct V_109 * V_110 = F_43 ( V_14 ) ;
int V_103 = V_14 -> V_115 ;
T_2 V_116 [ 2 ] ;
V_116 [ 0 ] = F_44 ( V_138 )
| V_118
| F_45 ( V_103 , V_14 )
| F_46 ( V_119 , V_14 )
| F_47 ( V_134 )
| F_48 ( V_14 -> V_135 ) ;
V_116 [ 1 ] = 0 ;
V_112 = F_49 ( V_110 ,
(struct V_113 * ) V_116 ,
F_50 ( V_116 ) , V_123 , 0 ) ;
if ( ! V_112 ) {
F_7 ( L_18 ) ;
return - 1 ;
}
F_55 ( V_14 , V_139 ) ;
V_112 = F_49 ( V_110 , & V_14 -> V_136 ,
1 , V_140 ,
V_129 | V_130 ) ;
if ( ! V_112 ) {
F_7 ( L_19 ) ;
return - 1 ;
}
F_41 ( V_14 , V_141 ) ;
return F_53 ( V_14 , V_112 ) ;
}
int F_57 ( struct V_13 * V_14 ,
T_4 V_142 , T_4 V_143 )
{
struct V_25 * V_26 = & V_14 -> V_25 ;
T_3 V_132 ;
T_3 V_133 ;
T_3 V_144 ;
T_3 V_145 ;
struct V_111 * V_112 ;
struct V_109 * V_110 = F_43 ( V_14 ) ;
int V_103 = V_14 -> V_115 ;
T_2 V_116 [ 6 ] ;
V_132 = V_117 ;
V_133 = V_134 ;
V_144 = V_146 ;
V_145 = V_147 |
V_148 ;
V_116 [ 0 ] = F_44 ( V_132 )
| V_118
| F_45 ( V_103 , V_14 )
| F_46 ( V_119 , V_14 )
| F_47 ( V_133 )
| F_48 ( 0 ) ;
V_116 [ 1 ] = 0 ;
V_116 [ 2 ] = V_149
| F_58 ( V_144 )
| F_59 ( V_145 ) ;
V_116 [ 3 ] = V_26 -> V_32 ;
V_116 [ 4 ] = V_142 ;
V_116 [ 5 ] = V_143 ;
V_112 = F_49 ( V_110 ,
(struct V_113 * ) V_116 ,
F_50 ( V_116 ) , V_123 ,
V_130 ) ;
if ( ! V_112 ) {
F_7 ( L_19 ) ;
return - 1 ;
}
F_41 ( V_14 , V_150 ) ;
return F_60 ( V_14 , V_112 ) ;
}
int F_61 ( struct V_13 * V_14 ,
T_4 V_142 , T_4 V_143 )
{
struct V_25 * V_26 = & V_14 -> V_25 ;
T_3 V_132 ;
T_3 V_133 ;
T_3 V_144 ;
T_3 V_145 ;
struct V_111 * V_112 ;
struct V_109 * V_110 = F_43 ( V_14 ) ;
int V_103 = V_14 -> V_115 ;
T_2 V_116 [ 6 ] ;
V_132 = V_151 ;
V_133 = V_134 ;
V_116 [ 0 ] = F_44 ( V_132 )
| V_118
| F_45 ( V_103 , V_14 )
| F_46 ( V_119 , V_14 )
| F_47 ( V_133 )
| F_48 ( 0 ) ;
V_116 [ 1 ] = 0 ;
V_112 = F_49 ( V_110 ,
(struct V_113 * ) V_116 , 2 ,
V_123 , 0 ) ;
if ( ! V_112 ) {
F_7 ( L_18 ) ;
return - 1 ;
}
V_132 = V_138 ;
V_133 = V_134 ;
V_144 = V_152 ;
V_145 = V_147
| V_148 ;
V_116 [ 0 ] = F_44 ( V_132 )
| V_118
| F_45 ( V_103 , V_14 )
| F_46 ( V_119 , V_14 )
| F_47 ( V_133 )
| F_48 ( V_26 -> V_32 ) ;
V_116 [ 1 ] = 0 ;
V_116 [ 2 ] = V_149
| F_58 ( V_144 )
| F_59 ( V_145 ) ;
V_116 [ 3 ] = V_26 -> V_32 ;
V_116 [ 4 ] = V_142 ;
V_116 [ 5 ] = V_143 ;
V_112 = F_49 ( V_110 ,
(struct V_113 * ) V_116 ,
F_50 ( V_116 ) , V_123 ,
V_129 | V_130 ) ;
if ( ! V_112 ) {
F_7 ( L_19 ) ;
return - 1 ;
}
V_132 = V_151 ;
V_133 = V_134 ;
V_116 [ 0 ] = F_44 ( V_132 )
| V_118
| F_45 ( V_103 , V_14 )
| F_46 ( V_119 , V_14 )
| F_47 ( V_133 )
| F_48 ( V_26 -> V_32 ) ;
V_116 [ 1 ] = 0 ;
V_116 [ 2 ] = 0 ;
V_112 = F_49 ( V_110 ,
(struct V_113 * ) V_116 , 3 ,
V_123 ,
V_129 | V_130 ) ;
if ( ! V_112 ) {
F_7 ( L_20 ) ;
return - 1 ;
}
F_41 ( V_14 , V_153 ) ;
return F_60 ( V_14 , V_112 ) ;
}
