static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) == 1 ) {
unsigned long V_4 = ( V_5 + 19 ) / 20 ;
V_2 -> V_6 . V_7 = V_8 + V_4 ;
F_3 ( & V_2 -> V_6 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
if ( F_5 ( & V_2 -> V_3 ) != 0 ) {
unsigned long V_4 = ( V_5 + 19 ) / 20 ;
F_6 ( & V_2 -> V_6 , V_8 + V_4 ) ;
} else {
F_7 ( & V_2 -> V_6 ) ;
}
}
static void F_8 ( unsigned long V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
if ( F_9 ( & V_2 -> V_3 ) != 0 ) {
F_10 ( L_1 ) ;
F_11 ( V_2 , 1 ) ;
F_12 ( V_2 ) ;
} else {
F_10 ( L_2
L_3 ) ;
}
}
static void F_13 ( struct V_1 * V_2 , unsigned V_10 )
{
T_1 * V_11 = & V_2 -> V_12 [ V_10 ] . V_13 [ 0 ] ;
T_2 V_14 [ 2 ] ;
T_3 V_15 ;
T_4 V_16 ;
V_14 [ 0 ] = F_14 ( V_11 [ 0 ] ) ;
V_14 [ 1 ] = F_14 ( V_11 [ 1 ] ) ;
V_15 = ( V_14 [ 1 ] << 32 ) | ( V_14 [ 0 ] >> 32 ) ;
V_16 = ( V_14 [ 0 ] >> 14 ) & ( 0x7ffULL << 2 ) ;
F_15 ( & V_2 -> V_17 -> V_18 , V_15 , V_16 , V_19 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = NULL ;
struct V_22 * V_23 = NULL ;
T_5 V_24 ;
T_5 V_25 = 0 ;
int V_26 = 0 ;
if ( ! F_17 ( & V_2 -> V_27 ) ) {
V_21 = V_2 -> V_27 . V_28 ;
V_23 = F_18 ( V_21 , struct V_22 , V_29 ) ;
V_25 = V_23 -> V_25 ;
}
V_24 = ( T_5 ) F_19 ( V_2 , V_2 -> V_30 -> V_31 ) ;
if ( V_24 >= V_2 -> V_32 )
goto V_33;
while ( V_2 -> V_34 != V_24 ) {
if ( V_23 && V_23 -> V_35 & V_36 &&
V_2 -> V_34 == V_25 ) {
F_13 ( V_2 , V_2 -> V_34 ) ;
V_25 ++ ;
if ( V_25 == V_2 -> V_32 )
V_25 = 0 ;
}
V_2 -> V_37 ++ ;
if ( ++ V_2 -> V_34 == V_2 -> V_32 )
V_2 -> V_34 = 0 ;
if ( V_23 && V_23 -> V_38 == V_2 -> V_34 ) {
if ( V_23 -> V_35 & V_39 )
F_4 ( V_2 ) ;
F_20 ( V_21 , & V_2 -> V_40 ) ;
if ( ! F_17 ( & V_2 -> V_27 ) ) {
V_21 = V_2 -> V_27 . V_28 ;
V_23 = F_18 ( V_21 , struct V_22 ,
V_29 ) ;
V_25 = V_23 -> V_25 ;
} else {
V_21 = NULL ;
V_23 = NULL ;
}
}
V_26 = 1 ;
}
if ( V_26 )
F_21 ( & V_2 -> V_41 ) ;
V_33:
return V_26 ;
}
static void F_22 ( struct V_1 * V_2 , struct V_20 * V_29 )
{
struct V_22 * V_23 , * V_42 ;
F_23 (txp, txp_next, list, list) {
F_24 ( & V_23 -> V_29 ) ;
if ( V_23 -> V_43 )
(* V_23 -> V_43 )( V_23 -> V_44 ,
V_23 -> V_45 ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
struct V_20 V_29 ;
F_26 ( & V_29 ) ;
F_27 ( & V_2 -> V_46 , V_35 ) ;
F_28 ( & V_2 -> V_40 , & V_29 ) ;
F_29 ( & V_2 -> V_46 , V_35 ) ;
F_22 ( V_2 , & V_29 ) ;
F_30 ( V_2 -> V_47 ) ;
}
static void F_31 ( unsigned long V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
if ( ! F_32 ( V_48 , & V_2 -> V_49 ) )
F_25 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
unsigned long V_50 ;
V_50 = F_34 ( V_2 , V_2 -> V_30 -> V_51 ) ;
F_35 ( V_52 , L_4 , V_50 ) ;
V_50 = F_34 ( V_2 , V_2 -> V_30 -> V_53 ) ;
F_35 ( V_52 , L_5 , V_50 ) ;
V_50 = F_34 ( V_2 , V_2 -> V_30 -> V_54 ) ;
F_35 ( V_52 , L_6 , V_50 ) ;
V_50 = F_34 ( V_2 , V_2 -> V_30 -> V_55 ) ;
F_35 ( V_52 , L_7 , V_50 ) ;
V_50 = F_34 ( V_2 , V_2 -> V_30 -> V_56 ) ;
F_35 ( V_52 , L_8 , V_50 ) ;
V_50 = F_34 ( V_2 , V_2 -> V_30 -> V_57 ) ;
F_35 ( V_52 , L_9 , V_50 ) ;
V_50 = F_34 ( V_2 , V_2 -> V_30 -> V_31 ) ;
F_35 ( V_52 , L_10 , V_50 ) ;
}
static void F_36 ( unsigned long V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
T_2 V_58 ;
unsigned long V_35 ;
if ( F_32 ( V_48 , & V_2 -> V_49 ) )
return;
F_27 ( & V_2 -> V_46 , V_35 ) ;
V_58 = V_2 -> V_49 & V_59 ;
if ( V_58 == V_60 )
goto V_61;
if ( V_58 == V_62 ) {
if ( F_37 ( V_8 , V_2 -> V_63 ) )
goto V_64;
F_10 ( L_11 ) ;
F_38 ( V_65 , & V_2 -> V_49 ) ;
V_58 = V_66 ;
}
if ( V_58 == V_66 ) {
struct V_22 * V_23 , * V_67 ;
T_2 V_68 ;
int V_69 = 0 ;
V_68 = F_34 ( V_2 ,
V_2 -> V_30 -> V_51 ) ;
if ( ( V_68 & ( V_70 |
V_71 |
V_72 ) ) ||
! ( V_68 & V_73 ) ) {
if ( V_2 -> V_74 > 0 ) {
-- V_2 -> V_74 ;
goto V_75;
}
F_35 ( V_52 , L_12
L_13 ) ;
F_33 ( V_2 ) ;
}
F_23 (txp, txpnext,
&dd->ipath_sdma_activelist, list) {
V_23 -> V_45 = V_76 ;
if ( V_23 -> V_35 & V_39 )
F_4 ( V_2 ) ;
F_20 ( & V_23 -> V_29 , & V_2 -> V_40 ) ;
V_69 = 1 ;
}
if ( V_69 )
F_21 ( & V_2 -> V_41 ) ;
V_2 -> V_77 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_78 [ 0 ] = 0 ;
V_2 -> V_79 = 0 ;
V_2 -> V_37 = V_2 -> V_80 ;
F_39 ( V_2 , V_2 -> V_30 -> V_81 ,
( T_2 ) V_2 -> V_32 | ( 1ULL << 18 ) ) ;
F_29 ( & V_2 -> V_46 , V_35 ) ;
F_27 ( & V_2 -> V_82 , V_35 ) ;
V_2 -> V_83 &= ~ V_84 ;
F_39 ( V_2 , V_2 -> V_30 -> V_53 ,
V_2 -> V_83 ) ;
F_34 ( V_2 , V_2 -> V_30 -> V_85 ) ;
F_29 ( & V_2 -> V_82 , V_35 ) ;
V_2 -> V_86 = 0 ;
if ( V_2 -> V_87 & V_88 )
F_40 ( V_2 ) ;
goto V_33;
}
V_75:
if ( F_41 ( V_8 , V_2 -> V_86 ) ) {
F_10 ( L_14 ,
V_2 -> V_49 ) ;
V_2 -> V_86 = V_8 + 5 * V_5 ;
}
V_64:
F_29 ( & V_2 -> V_46 , V_35 ) ;
if ( ! F_32 ( V_48 , & V_2 -> V_49 ) )
F_21 ( & V_2 -> V_89 ) ;
return;
V_61:
F_29 ( & V_2 -> V_46 , V_35 ) ;
V_33:
return;
}
void F_42 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
F_27 ( & V_2 -> V_46 , V_35 ) ;
( void ) F_16 ( V_2 ) ;
F_29 ( & V_2 -> V_46 , V_35 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_90 = 0 ;
V_2 -> V_12 = F_44 ( & V_2 -> V_17 -> V_18 ,
V_91 , & V_2 -> V_92 , V_93 ) ;
if ( ! V_2 -> V_12 ) {
F_45 ( V_2 , L_15
L_16 ) ;
V_90 = - V_94 ;
goto V_33;
}
V_2 -> V_32 =
V_91 / sizeof( struct V_95 ) ;
V_2 -> V_78 = F_44 ( & V_2 -> V_17 -> V_18 ,
V_96 , & V_2 -> V_97 , V_93 ) ;
if ( ! V_2 -> V_78 ) {
F_45 ( V_2 , L_17 ) ;
V_90 = - V_94 ;
goto V_98;
}
V_2 -> V_78 [ 0 ] = 0 ;
F_46 ( & V_2 -> V_6 ) ;
V_2 -> V_6 . V_99 = F_8 ;
V_2 -> V_6 . V_100 = ( unsigned long ) V_2 ;
F_47 ( & V_2 -> V_3 , 0 ) ;
goto V_33;
V_98:
F_48 ( & V_2 -> V_17 -> V_18 , V_91 ,
( void * ) V_2 -> V_12 , V_2 -> V_92 ) ;
V_2 -> V_12 = NULL ;
V_2 -> V_92 = 0 ;
V_33:
return V_90 ;
}
int F_49 ( struct V_1 * V_2 )
{
int V_90 = 0 ;
unsigned V_101 , V_102 ;
T_2 V_103 ;
T_2 V_104 [ 3 ] = { 0 } ;
unsigned long V_35 ;
V_90 = F_43 ( V_2 ) ;
if ( V_90 )
goto V_33;
if ( ! V_2 -> V_12 ) {
F_45 ( V_2 , L_18 ) ;
goto V_33;
}
V_2 -> V_49 = V_66 ;
V_2 -> V_86 = 0 ;
V_2 -> V_79 = 0 ;
V_2 -> V_77 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_37 = 0 ;
V_2 -> V_80 = 0 ;
F_39 ( V_2 , V_2 -> V_30 -> V_105 ,
V_2 -> V_92 ) ;
V_103 = V_2 -> V_32 ;
V_103 |= 1 << 18 ;
F_39 ( V_2 , V_2 -> V_30 -> V_81 , V_103 ) ;
F_39 ( V_2 , V_2 -> V_30 -> V_57 ,
V_2 -> V_77 ) ;
F_39 ( V_2 , V_2 -> V_30 -> V_106 ,
V_2 -> V_97 ) ;
V_102 = V_2 -> V_107 + V_2 -> V_108 ;
V_101 = V_2 -> V_109 + V_2 -> V_110 ;
F_50 ( V_2 , V_101 , V_102 - V_101 , 0 ) ;
for (; V_101 < V_102 ; ++ V_101 ) {
unsigned V_111 = V_101 / 64 ;
unsigned V_112 = V_101 & 63 ;
F_51 ( V_111 >= 3 ) ;
V_104 [ V_111 ] |= 1ULL << V_112 ;
}
F_39 ( V_2 , V_2 -> V_30 -> V_54 ,
V_104 [ 0 ] ) ;
F_39 ( V_2 , V_2 -> V_30 -> V_55 ,
V_104 [ 1 ] ) ;
F_39 ( V_2 , V_2 -> V_30 -> V_56 ,
V_104 [ 2 ] ) ;
F_26 ( & V_2 -> V_27 ) ;
F_26 ( & V_2 -> V_40 ) ;
F_52 ( & V_2 -> V_41 , F_31 ,
( unsigned long ) V_2 ) ;
F_52 ( & V_2 -> V_89 , F_36 ,
( unsigned long ) V_2 ) ;
F_27 ( & V_2 -> V_82 , V_35 ) ;
V_2 -> V_83 |= V_113 ;
F_39 ( V_2 , V_2 -> V_30 -> V_53 , V_2 -> V_83 ) ;
F_34 ( V_2 , V_2 -> V_30 -> V_85 ) ;
F_38 ( V_114 , & V_2 -> V_49 ) ;
F_29 ( & V_2 -> V_82 , V_35 ) ;
V_33:
return V_90 ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_22 * V_23 , * V_67 ;
unsigned long V_35 ;
T_3 V_115 = 0 ;
T_3 V_116 = 0 ;
void * V_117 = NULL ;
void * V_118 = NULL ;
F_27 ( & V_2 -> V_46 , V_35 ) ;
F_54 ( V_114 , & V_2 -> V_49 ) ;
F_38 ( V_119 , & V_2 -> V_49 ) ;
F_38 ( V_48 , & V_2 -> V_49 ) ;
F_29 ( & V_2 -> V_46 , V_35 ) ;
F_55 ( & V_2 -> V_89 ) ;
F_55 ( & V_2 -> V_41 ) ;
F_27 ( & V_2 -> V_82 , V_35 ) ;
V_2 -> V_83 &= ~ V_84 ;
F_39 ( V_2 , V_2 -> V_30 -> V_53 ,
V_2 -> V_83 ) ;
F_34 ( V_2 , V_2 -> V_30 -> V_85 ) ;
F_29 ( & V_2 -> V_82 , V_35 ) ;
F_27 ( & V_2 -> V_46 , V_35 ) ;
F_23 (txp, txpnext, &dd->ipath_sdma_activelist,
list) {
V_23 -> V_45 = V_120 ;
if ( V_23 -> V_35 & V_39 )
F_4 ( V_2 ) ;
F_20 ( & V_23 -> V_29 , & V_2 -> V_40 ) ;
}
F_29 ( & V_2 -> V_46 , V_35 ) ;
F_25 ( V_2 ) ;
F_56 ( & V_2 -> V_6 ) ;
F_27 ( & V_2 -> V_46 , V_35 ) ;
V_2 -> V_86 = 0 ;
F_39 ( V_2 , V_2 -> V_30 -> V_105 , 0 ) ;
F_39 ( V_2 , V_2 -> V_30 -> V_81 , 0 ) ;
F_39 ( V_2 , V_2 -> V_30 -> V_57 , 0 ) ;
F_39 ( V_2 , V_2 -> V_30 -> V_106 , 0 ) ;
F_39 ( V_2 , V_2 -> V_30 -> V_54 , 0 ) ;
F_39 ( V_2 , V_2 -> V_30 -> V_55 , 0 ) ;
F_39 ( V_2 , V_2 -> V_30 -> V_56 , 0 ) ;
if ( V_2 -> V_78 ) {
V_118 = ( void * ) V_2 -> V_78 ;
V_115 = V_2 -> V_97 ;
V_2 -> V_78 = NULL ;
V_2 -> V_97 = 0 ;
}
if ( V_2 -> V_12 ) {
V_117 = V_2 -> V_12 ;
V_116 = V_2 -> V_92 ;
V_2 -> V_12 = NULL ;
V_2 -> V_92 = 0 ;
}
F_29 ( & V_2 -> V_46 , V_35 ) ;
if ( V_118 )
F_48 ( & V_2 -> V_17 -> V_18 , V_96 ,
V_118 , V_115 ) ;
if ( V_117 )
F_48 ( & V_2 -> V_17 -> V_18 , V_91 ,
V_117 , V_116 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
int V_121 = 1 ;
if ( ! ( V_2 -> V_87 & V_122 ) )
goto V_123;
F_27 ( & V_2 -> V_46 , V_35 ) ;
if ( ! F_32 ( V_114 , & V_2 -> V_49 )
|| F_32 ( V_48 , & V_2 -> V_49 ) )
V_121 = 0 ;
else {
F_54 ( V_65 , & V_2 -> V_49 ) ;
F_54 ( V_124 , & V_2 -> V_49 ) ;
F_54 ( V_119 , & V_2 -> V_49 ) ;
}
F_29 ( & V_2 -> V_46 , V_35 ) ;
if ( ! V_121 ) {
F_10 ( L_19 ,
V_2 -> V_49 ) ;
goto V_123;
}
F_27 ( & V_2 -> V_82 , V_35 ) ;
V_2 -> V_83 &= ~ V_84 ;
F_39 ( V_2 , V_2 -> V_30 -> V_53 , V_2 -> V_83 ) ;
F_34 ( V_2 , V_2 -> V_30 -> V_85 ) ;
V_2 -> V_83 |= V_84 ;
F_39 ( V_2 , V_2 -> V_30 -> V_53 , V_2 -> V_83 ) ;
F_34 ( V_2 , V_2 -> V_30 -> V_85 ) ;
F_29 ( & V_2 -> V_82 , V_35 ) ;
F_30 ( V_2 -> V_47 ) ;
V_123:
return;
}
static inline void F_57 ( struct V_1 * V_2 ,
T_2 * V_125 , T_2 V_15 , T_2 V_126 , T_2 V_127 )
{
F_58 ( V_15 & 3 ) ;
V_125 [ 1 ] = V_15 >> 32 ;
V_125 [ 0 ] = ( V_15 & 0xfffffffcULL ) << 32 ;
V_125 [ 0 ] |= ( V_2 -> V_79 & 3ULL ) << 30 ;
V_125 [ 0 ] |= ( V_126 & 0x7ffULL ) << 16 ;
V_125 [ 0 ] |= V_127 & 0x7ffULL ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_128 * V_129 , T_6 V_130 ,
struct V_131 * V_132 )
{
unsigned long V_35 ;
struct V_133 * V_134 ;
int V_90 = 0 ;
T_5 V_135 ;
T_1 * V_11 ;
T_2 V_125 [ 2 ] ;
T_6 V_127 ;
T_3 V_15 ;
if ( ( V_132 -> V_136 + ( V_130 << 2 ) ) > V_2 -> V_137 ) {
F_10 ( L_20 ,
V_132 -> V_136 + ( V_130 << 2 ) , V_2 -> V_137 ) ;
V_90 = - V_138 ;
goto V_139;
}
F_27 ( & V_2 -> V_46 , V_35 ) ;
V_140:
if ( F_60 ( F_32 ( V_119 , & V_2 -> V_49 ) ) ) {
V_90 = - V_141 ;
goto V_61;
}
if ( V_132 -> V_142 . V_143 > F_61 ( V_2 ) ) {
if ( F_16 ( V_2 ) )
goto V_140;
V_90 = - V_144 ;
goto V_61;
}
V_15 = F_62 ( & V_2 -> V_17 -> V_18 , V_132 -> V_142 . V_145 ,
V_132 -> V_136 , V_19 ) ;
if ( F_63 ( & V_2 -> V_17 -> V_18 , V_15 ) )
goto V_146;
V_127 = V_132 -> V_136 >> 2 ;
F_57 ( V_2 , V_125 , ( T_2 ) V_15 , V_127 , 0 ) ;
V_125 [ 0 ] |= 1ULL << 12 ;
if ( V_132 -> V_142 . V_35 & V_147 )
V_125 [ 0 ] |= 1ULL << 14 ;
V_135 = V_2 -> V_77 ;
V_11 = & V_2 -> V_12 [ V_135 ] . V_13 [ 0 ] ;
* V_11 ++ = F_64 ( V_125 [ 0 ] ) ;
* V_11 ++ = F_64 ( V_125 [ 1 ] ) ;
if ( V_132 -> V_142 . V_35 & V_36 )
V_132 -> V_142 . V_25 = V_135 ;
if ( ++ V_135 == V_2 -> V_32 ) {
V_135 = 0 ;
V_11 = & V_2 -> V_12 [ 0 ] . V_13 [ 0 ] ;
++ V_2 -> V_79 ;
}
V_134 = & V_129 -> V_134 ;
while ( V_130 ) {
T_6 V_148 ;
T_6 V_16 ;
V_16 = V_130 << 2 ;
if ( V_16 > V_134 -> V_149 )
V_16 = V_134 -> V_149 ;
if ( V_16 > V_134 -> V_150 )
V_16 = V_134 -> V_150 ;
F_51 ( V_16 == 0 ) ;
V_148 = ( V_16 + 3 ) >> 2 ;
V_15 = F_62 ( & V_2 -> V_17 -> V_18 , V_134 -> V_151 , V_148 << 2 ,
V_19 ) ;
if ( F_63 ( & V_2 -> V_17 -> V_18 , V_15 ) )
goto V_152;
F_57 ( V_2 , V_125 , ( T_2 ) V_15 , V_148 , V_127 ) ;
if ( V_132 -> V_142 . V_35 & V_147 )
V_125 [ 0 ] |= 1ULL << 14 ;
* V_11 ++ = F_64 ( V_125 [ 0 ] ) ;
* V_11 ++ = F_64 ( V_125 [ 1 ] ) ;
if ( ++ V_135 == V_2 -> V_32 ) {
V_135 = 0 ;
V_11 = & V_2 -> V_12 [ 0 ] . V_13 [ 0 ] ;
++ V_2 -> V_79 ;
}
V_134 -> V_151 += V_16 ;
V_134 -> V_149 -= V_16 ;
V_134 -> V_150 -= V_16 ;
if ( V_134 -> V_150 == 0 ) {
if ( -- V_129 -> V_153 )
* V_134 = * V_129 -> V_154 ++ ;
} else if ( V_134 -> V_149 == 0 && V_134 -> V_155 != NULL ) {
if ( ++ V_134 -> V_102 >= V_156 ) {
if ( ++ V_134 -> V_157 >= V_134 -> V_155 -> V_158 )
break;
V_134 -> V_102 = 0 ;
}
V_134 -> V_151 =
V_134 -> V_155 -> V_159 [ V_134 -> V_157 ] -> V_160 [ V_134 -> V_102 ] . V_151 ;
V_134 -> V_149 =
V_134 -> V_155 -> V_159 [ V_134 -> V_157 ] -> V_160 [ V_134 -> V_102 ] . V_149 ;
}
V_127 += V_148 ;
V_130 -= V_148 ;
}
if ( ! V_135 )
V_11 = & V_2 -> V_12 [ V_2 -> V_32 ] . V_13 [ 0 ] ;
V_11 -= 2 ;
V_11 [ 0 ] |= F_64 ( 1ULL << 11 ) ;
if ( V_132 -> V_142 . V_35 & V_161 ) {
V_11 [ 0 ] |= F_64 ( 1ULL << 15 ) ;
}
F_65 () ;
F_39 ( V_2 , V_2 -> V_30 -> V_57 , V_135 ) ;
V_132 -> V_142 . V_38 = V_135 ;
V_132 -> V_142 . V_45 = V_162 ;
V_2 -> V_77 = V_135 ;
V_2 -> V_80 += V_132 -> V_142 . V_143 ;
F_66 ( & V_132 -> V_142 . V_29 , & V_2 -> V_27 ) ;
if ( V_132 -> V_142 . V_35 & V_39 )
F_1 ( V_2 ) ;
goto V_61;
V_152:
while ( V_135 != V_2 -> V_77 ) {
if ( ! V_135 )
V_135 = V_2 -> V_32 - 1 ;
else
V_135 -- ;
F_13 ( V_2 , V_135 ) ;
}
V_146:
V_90 = - V_163 ;
V_61:
F_29 ( & V_2 -> V_46 , V_35 ) ;
V_139:
return V_90 ;
}
