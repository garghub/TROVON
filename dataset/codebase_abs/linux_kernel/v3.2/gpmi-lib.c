static int F_1 ( void T_1 * V_1 , T_2 V_2 )
{
int V_3 = 0x400 ;
F_2 ( V_2 , V_1 ) ;
F_3 ( 1 ) ;
while ( ( F_4 ( V_1 ) & V_2 ) && -- V_3 )
;
return ! V_3 ;
}
int F_5 ( void T_1 * V_4 , bool V_5 )
{
int V_6 ;
int V_3 = 0x400 ;
V_6 = F_1 ( V_4 , V_7 ) ;
if ( F_6 ( V_6 ) )
goto error;
F_2 ( V_8 , V_4 ) ;
if ( ! V_5 ) {
F_7 ( V_7 , V_4 ) ;
F_3 ( 1 ) ;
while ( ( ! ( F_4 ( V_4 ) & V_8 ) ) && -- V_3 )
;
if ( F_6 ( ! V_3 ) )
goto error;
}
V_6 = F_1 ( V_4 , V_7 ) ;
if ( F_6 ( V_6 ) )
goto error;
V_6 = F_1 ( V_4 , V_8 ) ;
if ( F_6 ( V_6 ) )
goto error;
return 0 ;
error:
F_8 ( L_1 , V_9 , V_4 ) ;
return - V_10 ;
}
int F_9 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_13 ;
int V_6 ;
V_6 = F_10 ( V_14 -> clock ) ;
if ( V_6 )
goto V_15;
V_6 = F_5 ( V_14 -> V_16 , false ) ;
if ( V_6 )
goto V_15;
F_11 ( V_17 , V_14 -> V_16 + V_18 ) ;
F_11 ( V_19 ,
V_14 -> V_16 + V_20 ) ;
F_11 ( V_21 , V_14 -> V_16 + V_20 ) ;
F_11 ( V_22 , V_14 -> V_16 + V_20 ) ;
F_12 ( V_14 -> clock ) ;
return 0 ;
V_15:
return V_6 ;
}
void F_13 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_13 ;
struct V_23 * V_24 = & V_12 -> V_23 ;
T_2 V_25 ;
int V_26 ;
F_8 ( L_2 ) ;
for ( V_26 = 0 ; V_26 <= V_27 / 0x10 + 1 ; V_26 ++ ) {
V_25 = F_4 ( V_14 -> V_16 + V_26 * 0x10 ) ;
F_8 ( L_3 , V_26 * 0x10 , V_25 ) ;
}
F_8 ( L_4 ) ;
F_8 ( L_5 , V_24 -> V_28 ) ;
F_8 ( L_6 , V_24 -> V_29 ) ;
F_8 ( L_7 , V_24 -> V_30 ) ;
F_8 ( L_8 , V_24 -> V_31 ) ;
F_8 ( L_9 , V_24 -> V_32 ) ;
F_8 ( L_10 , V_24 -> V_33 ) ;
F_8 ( L_11 , V_24 -> V_34 ) ;
F_8 ( L_12 , V_24 -> V_35 ) ;
F_8 ( L_13 , V_24 -> V_36 ) ;
F_8 ( L_14 , V_24 -> V_37 ) ;
F_8 ( L_15 , V_24 -> V_38 ) ;
}
int F_14 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_13 ;
struct V_23 * V_39 = & V_12 -> V_23 ;
unsigned int V_40 ;
unsigned int V_41 ;
unsigned int V_31 ;
unsigned int V_29 ;
unsigned int V_30 ;
int V_6 ;
if ( F_15 ( V_12 ) )
return ! 0 ;
V_40 = V_39 -> V_33 - 1 ;
V_41 = V_39 -> V_32 ;
V_31 = V_39 -> V_31 ;
V_29 = V_39 -> V_29 >> 1 ;
V_30 = V_39 -> V_30 ;
V_6 = F_10 ( V_14 -> clock ) ;
if ( V_6 )
goto V_15;
V_6 = F_5 ( V_14 -> V_42 , true ) ;
if ( V_6 )
goto V_15;
F_11 ( F_16 ( V_40 )
| F_17 ( V_31 )
| F_18 ( V_29 )
| F_19 ( V_41 ) ,
V_14 -> V_42 + V_43 ) ;
F_11 ( F_20 ( V_30 )
| F_21 ( V_29 )
| F_22 ( V_41 ) ,
V_14 -> V_42 + V_44 ) ;
F_11 ( 0 , V_14 -> V_42 + V_45 ) ;
F_11 ( V_46 ,
V_14 -> V_42 + V_47 ) ;
F_12 ( V_14 -> clock ) ;
return 0 ;
V_15:
return V_6 ;
}
static unsigned int F_23 ( unsigned int time ,
unsigned int V_48 , unsigned int V_49 )
{
unsigned int V_50 ;
V_50 = ( time + V_48 - 1 ) / V_48 ;
return F_24 ( V_50 , V_49 ) ;
}
static int F_25 ( struct V_11 * V_12 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 = V_12 -> V_54 ;
struct V_55 * V_56 = & V_57 ;
struct V_58 * V_59 = & V_12 -> V_59 ;
struct V_60 V_61 = V_12 -> V_62 ;
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
unsigned int V_76 = V_54 -> V_76 ;
unsigned int V_77 = V_54 -> V_77 ;
if ( V_59 -> V_78 > 2 ) {
V_61 . V_70 += 10 ;
V_61 . V_79 += 10 ;
V_61 . V_80 += 10 ;
} else if ( V_59 -> V_78 > 1 ) {
V_61 . V_70 += 5 ;
V_61 . V_79 += 5 ;
V_61 . V_80 += 5 ;
}
V_63 =
( V_61 . V_81 >= 0 ) &&
( V_61 . V_82 >= 0 ) &&
( V_61 . V_83 >= 0 ) ;
V_64 = V_56 -> V_64 ;
V_65 = 1000000000 / V_64 ;
V_71 = F_23 ( V_61 . V_70 ,
V_65 , 1 ) ;
V_72 = F_23 ( V_61 . V_79 ,
V_65 , 1 ) ;
V_69 = F_23 ( V_61 . V_80 ,
V_65 , 0 ) ;
if ( V_65 > ( V_56 -> V_84 >> 1 ) ) {
V_66 = true ;
V_67 = 3 + 1 ;
} else {
V_66 = false ;
V_67 = 3 ;
}
if ( V_65 > V_56 -> V_84 )
V_68 = 0 ;
else {
V_68 =
( V_56 -> V_85 * V_65 ) >>
V_67 ;
if ( V_68 > V_56 -> V_86 )
V_68 = V_56 -> V_86 ;
}
if ( ! V_63 ) {
V_73 = V_61 . V_87 +
V_56 -> V_88 ;
while ( ( V_73 > V_68 ) &&
( V_71 < V_56 -> V_89 ) ) {
V_71 ++ ;
V_73 -= V_65 ;
if ( V_73 < 0 )
V_73 = 0 ;
}
V_74 =
F_23 (
V_73 << V_67 ,
V_65 , 0 ) ;
if ( V_74 > V_56 -> V_85 )
V_74 = V_56 -> V_85 ;
goto V_90;
}
V_77 += V_56 -> V_88 ;
V_70 = V_65 * V_71 ;
V_75 = ( int ) V_76 + ( int ) V_61 . V_83 +
( int ) V_70 ;
V_75 -= ( int ) V_77 + ( int ) V_61 . V_81 ;
while ( ( V_75 <= 0 ) &&
( V_71 < V_56 -> V_89 ) ) {
V_71 ++ ;
V_70 += V_65 ;
V_75 += V_65 ;
}
V_73 =
( ( int ) V_77 +
( int ) V_61 . V_81 +
( int ) V_76 +
( int ) V_61 . V_83 -
( int ) V_70 ) >> 1 ;
if ( V_73 < 0 )
V_73 = 0 ;
while ( ( V_73 > V_68 ) &&
( V_71 < V_56 -> V_89 ) ) {
V_71 ++ ;
V_70 += V_65 ;
V_75 += V_65 ;
V_73 -= ( V_65 >> 1 ) ;
if ( V_73 < 0 )
V_73 = 0 ;
}
V_74 =
F_23 ( V_73 << V_67 ,
V_65 , 0 ) ;
if ( V_74 > V_56 -> V_85 )
V_74 = V_56 -> V_85 ;
#define F_26 ((int) ideal_sample_delay_in_ns)
#define F_27 \
((int) ((sample_delay_factor * clock_period_in_ns) >> \
dll_delay_shift))
#define F_28 (abs(QUANTIZED_DELAY - IDEAL_DELAY))
#define F_29 (DELAY_ERROR > (tEYE >> 1))
while ( F_29 &&
( V_71 < V_56 -> V_89 ) ) {
if ( F_27 > F_26 ) {
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
F_23 (
V_73 << V_67 ,
V_65 , 0 ) ;
if ( V_74 > V_56 -> V_85 )
V_74 = V_56 -> V_85 ;
}
V_90:
V_52 -> V_71 = V_71 ;
V_52 -> V_72 = V_72 ;
V_52 -> V_69 = V_69 ;
V_52 -> V_91 = V_66 ;
V_52 -> V_74 = V_74 ;
return 0 ;
}
void F_30 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_13 ;
struct V_55 * V_56 = & V_57 ;
unsigned char * V_16 = V_14 -> V_16 ;
unsigned int V_65 ;
T_3 V_25 ;
unsigned int V_92 ;
struct V_51 V_52 ;
int V_6 ;
V_6 = F_10 ( V_14 -> clock ) ;
if ( V_6 ) {
F_8 ( L_16 ) ;
goto V_15;
}
F_11 ( 0x500 << V_93 ,
V_16 + V_94 ) ;
V_56 -> V_64 = F_31 ( V_14 -> clock ) ;
V_65 = 1000000000 / V_56 -> V_64 ;
F_25 ( V_12 , & V_52 ) ;
V_25 = F_32 ( V_52 . V_69 ) |
F_33 ( V_52 . V_72 ) |
F_34 ( V_52 . V_71 ) ;
F_11 ( V_25 , V_16 + V_95 ) ;
F_11 ( V_96 , V_16 + V_18 ) ;
F_11 ( V_97 , V_16 + V_18 ) ;
F_11 ( V_98 , V_16 + V_18 ) ;
if ( ! V_52 . V_74 )
return;
if ( V_52 . V_91 )
F_11 ( V_98 ,
V_16 + V_20 ) ;
F_11 ( F_35 ( V_52 . V_74 ) ,
V_16 + V_20 ) ;
F_11 ( V_96 , V_16 + V_20 ) ;
V_92 = ( V_65 * 64 ) / 1000 ;
if ( ! V_92 )
V_92 = 1 ;
F_3 ( V_92 ) ;
V_15:
return;
}
void F_36 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_13 ;
F_12 ( V_14 -> clock ) ;
}
void F_37 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_13 ;
F_11 ( V_99 , V_14 -> V_42 + V_100 ) ;
}
int F_38 ( struct V_11 * V_12 , unsigned V_101 )
{
struct V_13 * V_14 = & V_12 -> V_13 ;
T_3 V_2 = 0 ;
T_3 V_25 = 0 ;
if ( F_39 ( V_12 ) ) {
V_2 = V_102 << V_101 ;
V_25 = F_4 ( V_14 -> V_16 + V_27 ) ;
} else if ( F_40 ( V_12 ) ) {
V_2 = F_41 ( 1 << V_101 ) ;
V_25 = F_4 ( V_14 -> V_16 + V_103 ) ;
} else
F_8 ( L_17 ) ;
return V_25 & V_2 ;
}
static inline void F_42 ( struct V_11 * V_12 ,
enum V_104 type )
{
V_12 -> V_105 = V_12 -> V_106 ;
V_12 -> V_106 = type ;
}
int F_43 ( struct V_11 * V_12 )
{
struct V_107 * V_108 = F_44 ( V_12 ) ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
int V_101 = V_12 -> V_113 ;
T_2 V_114 [ 3 ] ;
V_114 [ 0 ] = F_45 ( V_115 )
| V_116
| F_46 ( V_101 , V_12 )
| F_47 ( V_117 , V_12 )
| F_48 ( V_118 )
| V_119
| F_49 ( V_12 -> V_120 ) ;
V_114 [ 1 ] = V_114 [ 2 ] = 0 ;
V_110 = V_108 -> V_121 -> V_122 ( V_108 ,
(struct V_111 * ) V_114 ,
F_50 ( V_114 ) , V_123 , 0 ) ;
if ( ! V_110 ) {
F_8 ( L_18 ) ;
return - 1 ;
}
V_112 = & V_12 -> V_124 ;
F_51 ( V_112 , V_12 -> V_125 , V_12 -> V_120 ) ;
F_52 ( V_12 -> V_126 , V_112 , 1 , V_127 ) ;
V_110 = V_108 -> V_121 -> V_122 ( V_108 ,
V_112 , 1 , V_127 , 1 ) ;
if ( ! V_110 ) {
F_8 ( L_19 ) ;
return - 1 ;
}
F_42 ( V_12 , V_128 ) ;
return F_53 ( V_12 , V_110 ) ;
}
int F_54 ( struct V_11 * V_12 )
{
struct V_109 * V_110 ;
struct V_107 * V_108 = F_44 ( V_12 ) ;
int V_101 = V_12 -> V_113 ;
T_3 V_129 ;
T_3 V_130 ;
T_2 V_114 [ 2 ] ;
V_129 = V_115 ;
V_130 = V_131 ;
V_114 [ 0 ] = F_45 ( V_129 )
| V_116
| F_46 ( V_101 , V_12 )
| F_47 ( V_117 , V_12 )
| F_48 ( V_130 )
| F_49 ( V_12 -> V_132 ) ;
V_114 [ 1 ] = 0 ;
V_110 = V_108 -> V_121 -> V_122 ( V_108 ,
(struct V_111 * ) V_114 ,
F_50 ( V_114 ) , V_123 , 0 ) ;
if ( ! V_110 ) {
F_8 ( L_18 ) ;
return - 1 ;
}
F_55 ( V_12 , V_127 ) ;
V_110 = V_108 -> V_121 -> V_122 ( V_108 , & V_12 -> V_133 ,
1 , V_127 , 1 ) ;
if ( ! V_110 ) {
F_8 ( L_19 ) ;
return - 1 ;
}
F_42 ( V_12 , V_134 ) ;
return F_53 ( V_12 , V_110 ) ;
}
int F_56 ( struct V_11 * V_12 )
{
struct V_109 * V_110 ;
struct V_107 * V_108 = F_44 ( V_12 ) ;
int V_101 = V_12 -> V_113 ;
T_2 V_114 [ 2 ] ;
V_114 [ 0 ] = F_45 ( V_135 )
| V_116
| F_46 ( V_101 , V_12 )
| F_47 ( V_117 , V_12 )
| F_48 ( V_131 )
| F_49 ( V_12 -> V_132 ) ;
V_114 [ 1 ] = 0 ;
V_110 = V_108 -> V_121 -> V_122 ( V_108 ,
(struct V_111 * ) V_114 ,
F_50 ( V_114 ) , V_123 , 0 ) ;
if ( ! V_110 ) {
F_8 ( L_18 ) ;
return - 1 ;
}
F_55 ( V_12 , V_136 ) ;
V_110 = V_108 -> V_121 -> V_122 ( V_108 , & V_12 -> V_133 ,
1 , V_136 , 1 ) ;
if ( ! V_110 ) {
F_8 ( L_19 ) ;
return - 1 ;
}
F_42 ( V_12 , V_137 ) ;
return F_53 ( V_12 , V_110 ) ;
}
int F_57 ( struct V_11 * V_12 ,
T_4 V_138 , T_4 V_139 )
{
struct V_23 * V_24 = & V_12 -> V_23 ;
T_3 V_129 ;
T_3 V_130 ;
T_3 V_140 ;
T_3 V_141 ;
struct V_109 * V_110 ;
struct V_107 * V_108 = F_44 ( V_12 ) ;
int V_101 = V_12 -> V_113 ;
T_2 V_114 [ 6 ] ;
V_129 = V_115 ;
V_130 = V_131 ;
V_140 = V_142 ;
V_141 = V_143 |
V_144 ;
V_114 [ 0 ] = F_45 ( V_129 )
| V_116
| F_46 ( V_101 , V_12 )
| F_47 ( V_117 , V_12 )
| F_48 ( V_130 )
| F_49 ( 0 ) ;
V_114 [ 1 ] = 0 ;
V_114 [ 2 ] = V_145
| F_58 ( V_140 )
| F_59 ( V_141 ) ;
V_114 [ 3 ] = V_24 -> V_30 ;
V_114 [ 4 ] = V_138 ;
V_114 [ 5 ] = V_139 ;
V_110 = V_108 -> V_121 -> V_122 ( V_108 ,
(struct V_111 * ) V_114 ,
F_50 ( V_114 ) , V_123 , 0 ) ;
if ( ! V_110 ) {
F_8 ( L_19 ) ;
return - 1 ;
}
F_42 ( V_12 , V_146 ) ;
return F_60 ( V_12 , V_110 ) ;
}
int F_61 ( struct V_11 * V_12 ,
T_4 V_138 , T_4 V_139 )
{
struct V_23 * V_24 = & V_12 -> V_23 ;
T_3 V_129 ;
T_3 V_130 ;
T_3 V_140 ;
T_3 V_141 ;
struct V_109 * V_110 ;
struct V_107 * V_108 = F_44 ( V_12 ) ;
int V_101 = V_12 -> V_113 ;
T_2 V_114 [ 6 ] ;
V_129 = V_147 ;
V_130 = V_131 ;
V_114 [ 0 ] = F_45 ( V_129 )
| V_116
| F_46 ( V_101 , V_12 )
| F_47 ( V_117 , V_12 )
| F_48 ( V_130 )
| F_49 ( 0 ) ;
V_114 [ 1 ] = 0 ;
V_110 = V_108 -> V_121 -> V_122 ( V_108 ,
(struct V_111 * ) V_114 , 2 , V_123 , 0 ) ;
if ( ! V_110 ) {
F_8 ( L_18 ) ;
return - 1 ;
}
V_129 = V_135 ;
V_130 = V_131 ;
V_140 = V_148 ;
V_141 = V_143
| V_144 ;
V_114 [ 0 ] = F_45 ( V_129 )
| V_116
| F_46 ( V_101 , V_12 )
| F_47 ( V_117 , V_12 )
| F_48 ( V_130 )
| F_49 ( V_24 -> V_30 ) ;
V_114 [ 1 ] = 0 ;
V_114 [ 2 ] = V_145
| F_58 ( V_140 )
| F_59 ( V_141 ) ;
V_114 [ 3 ] = V_24 -> V_30 ;
V_114 [ 4 ] = V_138 ;
V_114 [ 5 ] = V_139 ;
V_110 = V_108 -> V_121 -> V_122 ( V_108 ,
(struct V_111 * ) V_114 ,
F_50 ( V_114 ) , V_123 , 1 ) ;
if ( ! V_110 ) {
F_8 ( L_19 ) ;
return - 1 ;
}
V_129 = V_147 ;
V_130 = V_131 ;
V_114 [ 0 ] = F_45 ( V_129 )
| V_116
| F_46 ( V_101 , V_12 )
| F_47 ( V_117 , V_12 )
| F_48 ( V_130 )
| F_49 ( V_24 -> V_30 ) ;
V_114 [ 1 ] = 0 ;
V_110 = V_108 -> V_121 -> V_122 ( V_108 ,
(struct V_111 * ) V_114 , 2 , V_123 , 1 ) ;
if ( ! V_110 ) {
F_8 ( L_20 ) ;
return - 1 ;
}
F_42 ( V_12 , V_149 ) ;
return F_60 ( V_12 , V_110 ) ;
}
