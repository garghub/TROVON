static inline void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned long V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 , V_6 -> V_7 + V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_8 ,
( ( V_2 -> V_9 [ 0 ] << 8 ) | ( V_2 -> V_9 [ 1 ] ) ) ) ;
F_1 ( V_2 , V_8 + 4 ,
( ( V_2 -> V_9 [ 2 ] << 24 ) |
( V_2 -> V_9 [ 3 ] << 16 ) |
( V_2 -> V_9 [ 4 ] << 8 ) |
( V_2 -> V_9 [ 5 ] ) ) ) ;
}
static int F_5 ( struct V_1 * V_2 , void * V_10 )
{
struct V_11 * V_12 = V_10 ;
if ( ! F_6 ( V_12 -> V_13 ) )
return - V_14 ;
memcpy ( V_2 -> V_9 , V_12 -> V_13 , V_2 -> V_15 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
F_8 ( & V_2 -> V_18 , V_6 -> V_19 [ V_16 ] ,
V_6 -> V_20 , V_21 ) ;
if ( V_6 -> V_22 )
F_9 ( NULL , V_23 * V_24 ,
V_6 -> V_22 , V_6 -> V_25 ) ;
if ( V_6 -> V_26 )
F_9 ( NULL , V_27 * V_17 ,
V_6 -> V_26 , V_6 -> V_28 ) ;
F_10 ( V_6 -> V_29 ) ;
F_10 ( V_6 -> V_30 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_31 , V_6 -> V_7 + V_32 ) ;
while ( F_12 ( V_6 -> V_7 + V_32 ) & V_31 )
F_13 ( 10 ) ;
F_3 ( 0 , V_6 -> V_7 + V_33 ) ;
V_6 -> V_34 = V_35 | V_36 | V_37 | V_38 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( 0x00001010 , V_6 -> V_7 + V_39 ) ;
F_3 ( 0x00000001 , V_6 -> V_7 + V_40 ) ;
F_3 ( 0x00000390 , V_6 -> V_7 + V_41 ) ;
V_6 -> V_42 |= ( V_43 | V_44 ) ;
F_3 ( V_6 -> V_42 , V_6 -> V_7 + V_33 ) ;
V_6 -> V_34 |= ( V_45 | V_46 | V_47 | V_48 ) ;
F_3 ( V_6 -> V_34 , V_6 -> V_7 + V_32 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_49 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_24 ; V_16 ++ ) {
V_49 = V_6 -> V_22 + V_16 * V_23 ;
memset ( V_49 , 0 , V_23 ) ;
V_6 -> V_50 [ V_16 ] = V_6 -> V_29 + V_6 -> V_51 * V_16 ;
}
F_3 ( V_52 , V_49 + V_53 ) ;
V_6 -> V_54 = 0 ;
V_6 -> V_55 = 0 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_49 = V_6 -> V_26 + V_16 * V_27 ;
memset ( V_49 , 0 , V_27 ) ;
F_3 ( V_56 , V_49 + V_57 ) ;
F_3 ( V_58 & V_59 ,
V_49 + V_60 ) ;
V_6 -> V_61 [ V_16 ] = V_6 -> V_30 + V_6 -> V_20 * V_16 ;
V_6 -> V_19 [ V_16 ] = F_16 ( & V_2 -> V_18 ,
V_6 -> V_61 [ V_16 ] ,
V_6 -> V_20 ,
V_21 ) ;
if ( F_17 ( & V_2 -> V_18 , V_6 -> V_19 [ V_16 ] ) )
F_18 ( V_2 , L_1 ) ;
F_3 ( V_6 -> V_19 [ V_16 ] ,
V_49 + V_62 + V_63 ) ;
F_3 ( V_6 -> V_61 [ V_16 ] ,
V_49 + V_62 + V_64 ) ;
}
F_3 ( V_65 , V_49 + V_60 ) ;
V_6 -> V_66 = 0 ;
F_3 ( V_6 -> V_25 , V_6 -> V_7 + V_67 ) ;
F_3 ( V_6 -> V_28 , V_6 -> V_7 + V_68 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_6 ( V_2 -> V_9 ) )
return - V_14 ;
F_20 ( & V_6 -> V_69 ) ;
F_11 ( V_2 ) ;
F_4 ( V_2 ) ;
F_15 ( V_2 ) ;
F_14 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 , L_2 ,
V_70 , F_12 ( V_6 -> V_7 + V_33 ) ,
F_12 ( V_6 -> V_7 + V_32 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_24 ( & V_6 -> V_69 ) ;
F_25 ( V_2 ) ;
F_3 ( 0 , V_6 -> V_7 + V_33 ) ;
F_3 ( 0 , V_6 -> V_7 + V_32 ) ;
return 0 ;
}
static int F_26 ( struct V_71 * V_69 , int V_72 )
{
struct V_5 * V_6 = F_27 ( V_69 ,
struct V_5 ,
V_69 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_73 * V_74 ;
void T_1 * V_49 ;
unsigned int V_75 , V_76 ;
int V_66 = V_6 -> V_66 ;
int V_77 = 0 ;
while ( V_77 < V_72 ) {
V_49 = V_6 -> V_26 + ( V_27 * V_66 ) ;
V_75 = F_12 ( V_49 + V_57 ) ;
if ( V_75 & V_56 )
break;
if ( V_75 & ( V_78 | V_79 | V_80 |
V_81 | V_82 ) ) {
F_28 ( L_3 ) ;
V_6 -> V_83 . V_84 ++ ;
V_6 -> V_83 . V_85 ++ ;
goto V_86;
}
V_76 = V_75 & V_87 ;
if ( V_76 > V_58 )
V_76 = V_58 ;
F_29 ( & V_2 -> V_18 ,
V_6 -> V_19 [ V_66 ] ,
V_6 -> V_20 , V_21 ) ;
V_74 = F_30 ( V_2 , V_76 ) ;
if ( F_31 ( ! V_74 ) ) {
F_28 ( L_4 ) ;
V_6 -> V_83 . V_84 ++ ;
V_6 -> V_83 . V_85 ++ ;
goto V_86;
}
memcpy ( V_74 -> V_88 , V_6 -> V_61 [ V_66 ] , V_76 ) ;
F_32 ( V_74 , V_76 ) ;
V_74 -> V_89 = F_33 ( V_74 , V_2 ) ;
F_34 ( & V_6 -> V_69 , V_74 ) ;
V_77 ++ ;
V_2 -> V_90 = V_91 ;
V_6 -> V_83 . V_92 ++ ;
V_6 -> V_83 . V_93 += V_76 ;
if ( V_75 & V_94 )
V_6 -> V_83 . V_95 ++ ;
V_86:
F_3 ( V_56 , V_49 + V_57 ) ;
V_66 = F_35 ( V_66 ) ;
V_6 -> V_66 = V_66 ;
}
if ( V_77 < V_72 ) {
F_36 ( V_69 ) ;
}
V_6 -> V_42 |= V_43 ;
F_3 ( V_6 -> V_42 , V_6 -> V_7 + V_33 ) ;
return V_77 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned V_54 = V_6 -> V_54 ;
unsigned V_55 = V_6 -> V_55 ;
while ( V_55 != V_54 ) {
F_8 ( & V_2 -> V_18 , V_6 -> V_96 [ V_55 ] ,
V_6 -> V_97 [ V_55 ] , V_98 ) ;
V_6 -> V_83 . V_99 ++ ;
V_6 -> V_83 . V_100 += V_6 -> V_101 [ V_55 ] -> V_76 ;
F_38 ( V_6 -> V_101 [ V_55 ] ) ;
V_6 -> V_101 [ V_55 ] = NULL ;
V_55 = F_39 ( V_55 ) ;
}
V_6 -> V_55 = V_55 ;
}
static T_2 F_40 ( int V_102 , void * V_103 )
{
struct V_1 * V_2 = (struct V_1 * ) V_103 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_104 = F_12 ( V_6 -> V_7 + V_105 ) ;
if ( V_104 & V_106 )
F_37 ( V_2 ) ;
if ( V_104 & V_107 ) {
if ( F_41 ( & V_6 -> V_69 ) ) {
V_6 -> V_42 &= ~ V_43 ;
F_3 ( V_6 -> V_42 , V_6 -> V_7 + V_33 ) ;
F_42 ( & V_6 -> V_69 ) ;
}
}
return V_108 ;
}
static int F_43 ( struct V_73 * V_74 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_49 ;
unsigned int V_76 ;
unsigned int V_54 = V_6 -> V_54 ;
T_3 V_109 ;
int V_110 = V_111 ;
V_49 = V_6 -> V_22 + ( V_23 * V_54 ) ;
F_44 ( & V_6 -> V_112 ) ;
if ( F_12 ( V_49 + V_113 ) & V_114 ) {
F_28 ( L_5 ) ;
V_6 -> V_83 . V_115 ++ ;
goto V_116;
}
V_76 = V_74 -> V_76 > V_117 ? V_117 : V_74 -> V_76 ;
V_6 -> V_96 [ V_54 ] = F_16 ( & V_2 -> V_18 , V_74 -> V_88 ,
V_76 , V_98 ) ;
if ( F_17 ( & V_2 -> V_18 , V_6 -> V_96 [ V_54 ] ) ) {
F_18 ( V_2 , L_1 ) ;
goto V_116;
}
V_6 -> V_97 [ V_54 ] = V_76 ;
V_6 -> V_101 [ V_54 ] = V_74 ;
F_3 ( V_6 -> V_96 [ V_54 ] ,
V_49 + V_118 + V_119 ) ;
F_3 ( V_74 -> V_88 ,
V_49 + V_118 + V_120 ) ;
if ( V_74 -> V_76 < V_121 ) {
memset ( & V_74 -> V_88 [ V_74 -> V_76 ] ,
0 , V_121 - V_74 -> V_76 ) ;
V_76 = V_121 ;
}
F_45 ( & V_2 -> V_18 , V_6 -> V_96 [ V_54 ] ,
V_6 -> V_51 , V_98 ) ;
V_109 = V_122 | V_123 | ( V_76 & V_124 ) ;
if ( V_54 == V_125 )
V_109 |= V_52 ;
F_3 ( V_109 , V_49 + V_53 ) ;
F_3 ( V_114 , V_49 + V_113 ) ;
F_3 ( 0xffffffff , V_6 -> V_7 + V_126 ) ;
V_6 -> V_54 = F_39 ( V_54 ) ;
V_2 -> V_127 = V_91 ;
V_110 = V_128 ;
V_116:
F_46 ( & V_6 -> V_112 ) ;
return V_110 ;
}
static struct V_129 * F_47 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return & V_6 -> V_83 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_130 * V_131 ;
int V_132 ;
F_49 (ha, ndev) {
V_132 = F_50 ( ~ 0 , V_131 -> V_10 , V_133 ) ;
V_132 = ( V_132 >> 26 ) & 0x3f ;
if ( V_132 >= 32 ) {
F_3 ( F_12 ( V_6 -> V_7 + V_134 ) |
( 1UL << ( V_132 - 32 ) ) ,
V_6 -> V_7 + V_134 ) ;
} else {
F_3 ( F_12 ( V_6 -> V_7 + V_135 ) |
( 1UL << V_132 ) ,
V_6 -> V_7 + V_135 ) ;
}
}
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_44 ( & V_6 -> V_112 ) ;
( V_2 -> V_136 & V_137 ) ? ( V_6 -> V_34 |= V_138 ) :
( V_6 -> V_34 &= ~ V_138 ) ;
( V_2 -> V_136 & V_139 ) ? ( V_6 -> V_34 |= V_140 ) :
( V_6 -> V_34 &= ~ V_140 ) ;
if ( ( V_2 -> V_136 & V_141 ) && F_52 ( V_2 ) ) {
V_6 -> V_34 |= V_142 ;
F_48 ( V_2 ) ;
} else {
V_6 -> V_34 &= ~ V_142 ;
}
F_3 ( V_6 -> V_34 , V_6 -> V_7 + V_32 ) ;
F_46 ( & V_6 -> V_112 ) ;
}
static int F_53 ( struct V_143 * V_144 )
{
struct V_145 * V_146 = & V_144 -> V_18 ;
struct V_147 * V_148 = V_146 -> V_149 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_150 * V_151 ;
unsigned int V_102 ;
int V_110 ;
V_2 = F_54 ( sizeof( struct V_5 ) ) ;
if ( ! V_2 )
return - V_152 ;
V_102 = F_55 ( V_148 , 0 ) ;
if ( V_102 <= 0 ) {
F_18 ( V_2 , L_6 ) ;
V_110 = - V_153 ;
goto V_154;
}
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_151 = F_56 ( V_144 , V_155 , 0 ) ;
V_2 -> V_156 = V_151 -> V_157 ;
V_6 -> V_7 = F_57 ( V_146 , V_151 ) ;
V_110 = F_58 ( V_6 -> V_7 ) ;
if ( V_110 ) {
F_59 ( V_146 , L_7 ) ;
goto V_158;
}
F_60 ( & V_6 -> V_112 ) ;
V_6 -> V_51 = V_117 ;
V_6 -> V_20 = V_58 ;
V_6 -> V_22 = F_61 ( NULL , V_23 *
V_24 , & V_6 -> V_25 ,
V_159 | V_160 ) ;
if ( V_6 -> V_22 == NULL ) {
V_110 = - V_152 ;
goto V_158;
}
V_6 -> V_26 = F_61 ( NULL , V_27 *
V_17 , & V_6 -> V_28 ,
V_159 | V_160 ) ;
if ( V_6 -> V_26 == NULL ) {
V_110 = - V_152 ;
goto V_158;
}
V_6 -> V_29 = F_62 ( V_6 -> V_51 * V_24 ,
V_161 ) ;
if ( ! V_6 -> V_29 ) {
V_110 = - V_152 ;
goto V_158;
}
V_6 -> V_30 = F_62 ( V_6 -> V_20 * V_17 ,
V_161 ) ;
if ( ! V_6 -> V_30 ) {
V_110 = - V_152 ;
goto V_158;
}
F_63 ( V_144 , V_2 ) ;
V_110 = F_64 ( V_146 , V_102 , F_40 , 0 ,
V_144 -> V_162 , V_2 ) ;
if ( V_110 ) {
F_18 ( V_2 , L_8 ) ;
goto V_158;
}
F_65 ( V_2 ) ;
V_2 -> V_163 = & V_164 ;
F_66 ( V_2 , & V_6 -> V_69 , F_26 , V_17 ) ;
V_2 -> V_165 |= V_166 ;
V_2 -> V_102 = V_102 ;
F_67 ( V_2 , & V_144 -> V_18 ) ;
V_110 = F_68 ( V_2 ) ;
if ( V_110 ) {
F_69 ( V_2 ) ;
goto V_158;
}
F_22 ( V_2 , L_9 ,
V_70 , V_2 -> V_102 , V_2 -> V_9 ) ;
return 0 ;
V_158:
F_18 ( V_2 , L_10 ) ;
F_7 ( V_2 ) ;
V_154:
F_69 ( V_2 ) ;
return V_110 ;
}
static int F_70 ( struct V_143 * V_144 )
{
struct V_1 * V_2 = F_71 ( V_144 ) ;
F_72 ( V_2 ) ;
F_73 ( V_2 -> V_102 , V_2 ) ;
F_7 ( V_2 ) ;
F_69 ( V_2 ) ;
return 0 ;
}
