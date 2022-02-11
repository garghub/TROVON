static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_6 )
{
F_4 ( V_6 , V_2 -> V_4 -> V_5 + V_3 ) ;
}
static T_1 F_5 ( struct V_1 * V_7 )
{
T_1 V_8 ;
V_8 = ( ( 1 << V_7 -> V_9 ) - 1 ) ;
V_8 <<= V_10 - V_7 -> V_9 + 1 ;
return V_8 ;
}
static T_1 F_6 ( struct V_1 * V_7 ,
struct V_11 const * V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < F_7 ( V_7 -> V_14 ) ; V_13 ++ ) {
if ( V_12 -> V_15 == V_7 -> V_16 [ V_13 ] ) {
T_1 V_17 ;
V_17 = V_7 -> V_14 [ V_13 ] ;
return 1 << ( V_17 + 1 ) ;
}
}
F_8 ( 1 ) ;
return 0 ;
}
static T_1 F_9 ( struct V_1 * V_7 , int V_12 )
{
return 1 << V_7 -> V_14 [ V_12 ] ;
}
static void F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_20 * V_21 = V_7 -> V_4 -> V_21 ;
unsigned int V_22 ;
int V_13 , V_23 = 0 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_9 ; V_13 ++ ) {
int V_12 ;
V_12 = V_7 -> V_16 [ V_13 ] ;
if ( V_7 -> V_24 [ V_13 ] > V_25 ) {
F_12 ( V_21 , L_1 ,
V_12 , V_25 ) ;
V_7 -> V_24 [ V_13 ] = V_25 ;
}
if ( V_7 -> V_24 [ V_13 ] )
V_22 =
F_13 ( F_14 ( V_7 -> V_24 [ V_13 ] ) - 1 ) |
V_26 ;
else
V_22 = V_26 ;
if ( F_15 ( V_19 ) )
V_22 |= V_27 ;
F_3 ( V_7 , F_16 ( V_23 ) ,
V_22 | F_17 ( V_12 ) ) ;
if ( V_7 -> V_28 [ V_13 ] > V_29 ) {
F_12 ( V_21 , L_2 ,
V_12 ) ;
V_7 -> V_28 [ V_13 ] = V_29 ;
}
if ( V_7 -> V_30 [ V_13 ] > 0xFF ) {
F_12 ( V_21 , L_3 ,
V_12 ) ;
V_7 -> V_30 [ V_13 ] = 0xFF ;
}
F_3 ( V_7 , F_18 ( V_23 ) ,
F_19 ( V_7 -> V_28 [ V_13 ] ) |
F_20 ( V_7 -> V_30 [ V_13 ] ) ) ;
V_7 -> V_14 [ V_13 ] = V_23 ;
V_23 ++ ;
}
}
static T_2 F_21 ( int V_31 , void * V_32 )
{
struct V_18 * V_19 = V_32 ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
unsigned int V_33 , V_34 , V_35 ;
unsigned short V_36 = 0 ;
V_33 = F_1 ( V_7 , V_37 ) ;
if ( V_33 & V_38 ) {
V_34 = F_1 ( V_7 , V_39 ) ;
V_34 &= ~ ( V_40 ) ;
F_3 ( V_7 , V_39 , V_34 ) ;
F_3 ( V_7 , V_37 , V_38
| V_41 | V_42 ) ;
do {
V_35 = F_1 ( V_7 , V_43 ) ;
} while ( V_35 != 0x10 && V_36 ++ < 100 );
F_3 ( V_7 , V_39 , ( V_34 | V_40 ) ) ;
return V_44 ;
} else if ( V_33 & V_42 ) {
F_3 ( V_7 , V_45 , V_42 ) ;
return V_46 ;
}
return V_47 ;
}
static T_2 F_22 ( int V_31 , void * V_32 )
{
struct V_18 * V_19 = V_32 ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_13 , V_48 , V_49 , V_50 ;
T_3 * V_51 = V_7 -> V_51 ;
V_49 = F_1 ( V_7 , V_52 ) ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 = V_48 + V_13 ) {
for ( V_13 = 0 ; V_13 < ( V_19 -> V_53 ) / 2 ; V_13 ++ ) {
V_50 = F_1 ( V_7 , V_54 ) ;
V_51 [ V_13 ] = V_50 & V_55 ;
}
F_23 ( V_19 , ( V_56 * ) V_51 ) ;
}
F_3 ( V_7 , V_37 , V_42 ) ;
F_3 ( V_7 , V_57 , V_42 ) ;
return V_44 ;
}
static void F_24 ( void * V_58 )
{
struct V_18 * V_19 = V_58 ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_59 * V_60 = & V_7 -> V_60 ;
V_56 * V_51 ;
int V_13 ;
V_51 = V_60 -> V_61 + V_60 -> V_62 * V_60 -> V_63 ;
V_60 -> V_62 = 1 - V_60 -> V_62 ;
for ( V_13 = 0 ; V_13 < V_60 -> V_63 ; V_13 += V_19 -> V_53 ) {
F_23 ( V_19 , V_51 ) ;
V_51 += V_19 -> V_53 ;
}
}
static int F_25 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_59 * V_60 = & V_7 -> V_60 ;
struct V_64 * V_65 ;
V_60 -> V_62 = 0 ;
V_60 -> V_66 = F_26 ( V_67 + 1 ,
V_7 -> V_68 ) - 1 ;
V_60 -> V_63 = F_26 ( V_69 / 2 ,
( V_60 -> V_66 + 1 ) * sizeof( T_3 ) ) ;
V_60 -> V_70 . V_71 = V_60 -> V_66 + 1 ;
F_27 ( V_60 -> V_12 , & V_60 -> V_70 ) ;
V_65 = F_28 ( V_60 -> V_12 , V_60 -> V_72 ,
V_60 -> V_63 * 2 ,
V_60 -> V_63 , V_73 ,
V_74 ) ;
if ( ! V_65 )
return - V_75 ;
V_65 -> V_76 = F_24 ;
V_65 -> V_77 = V_19 ;
V_60 -> V_78 = F_29 ( V_65 ) ;
F_30 ( V_60 -> V_12 ) ;
F_3 ( V_7 , V_79 , V_60 -> V_66 ) ;
F_3 ( V_7 , V_80 , V_60 -> V_66 ) ;
F_3 ( V_7 , V_81 , V_82 ) ;
return 0 ;
}
static int F_31 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_13 , V_49 , V_50 ;
F_3 ( V_7 , V_45 , ( V_42 |
V_38 |
V_41 ) ) ;
V_49 = F_1 ( V_7 , V_52 ) ;
for ( V_13 = 0 ; V_13 < V_49 ; V_13 ++ )
V_50 = F_1 ( V_7 , V_54 ) ;
return 0 ;
}
static int F_32 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_59 * V_60 = & V_7 -> V_60 ;
unsigned int V_83 ;
unsigned int V_84 = 0 ;
V_56 V_85 ;
F_10 ( V_19 ) ;
F_33 (bit, indio_dev->active_scan_mask, adc_dev->channels) {
V_84 |= ( F_9 ( V_7 , V_85 ) << 1 ) ;
V_7 -> V_68 ++ ;
}
V_7 -> V_86 = V_84 ;
if ( V_60 -> V_12 )
F_25 ( V_19 ) ;
F_34 ( V_7 -> V_4 , V_84 ) ;
F_3 ( V_7 , V_37 , V_42
| V_38 | V_41 ) ;
V_83 = V_38 ;
if ( ! V_60 -> V_12 )
V_83 |= V_42 ;
F_3 ( V_7 , V_57 , V_83 ) ;
return 0 ;
}
static int F_35 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_59 * V_60 = & V_7 -> V_60 ;
int V_49 , V_13 , V_50 ;
F_3 ( V_7 , V_45 , ( V_42 |
V_38 | V_41 ) ) ;
F_36 ( V_7 -> V_4 , V_7 -> V_86 ) ;
V_7 -> V_86 = 0 ;
V_7 -> V_68 = 0 ;
if ( V_60 -> V_12 ) {
F_3 ( V_7 , V_87 , 0x2 ) ;
F_37 ( V_60 -> V_12 ) ;
}
V_49 = F_1 ( V_7 , V_52 ) ;
for ( V_13 = 0 ; V_13 < V_49 ; V_13 ++ )
V_50 = F_1 ( V_7 , V_54 ) ;
return 0 ;
}
static int F_38 ( struct V_18 * V_19 )
{
F_10 ( V_19 ) ;
return 0 ;
}
static int F_39 ( struct V_18 * V_19 ,
T_2 (* F_40)( int V_31 , void * V_88 ) ,
T_2 (* F_41)( int V_31 , void * V_88 ) ,
int V_31 ,
unsigned long V_89 ,
const struct V_90 * V_91 )
{
struct V_92 * V_93 ;
int V_94 ;
V_93 = F_42 () ;
if ( ! V_93 )
return - V_95 ;
F_43 ( V_19 , V_93 ) ;
V_94 = F_44 ( V_31 , F_41 , F_40 ,
V_89 , V_19 -> V_96 , V_19 ) ;
if ( V_94 )
goto V_97;
V_19 -> V_91 = V_91 ;
V_19 -> V_98 |= V_99 ;
return 0 ;
V_97:
F_45 ( V_19 -> V_93 ) ;
return V_94 ;
}
static void F_46 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
F_47 ( V_7 -> V_4 -> V_31 , V_19 ) ;
F_45 ( V_19 -> V_93 ) ;
}
static int F_48 ( struct V_18 * V_19 , int V_9 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_11 * V_100 ;
struct V_11 * V_12 ;
int V_13 ;
V_19 -> V_101 = V_9 ;
V_100 = F_49 ( V_9 , sizeof( * V_100 ) , V_102 ) ;
if ( V_100 == NULL )
return - V_95 ;
V_12 = V_100 ;
for ( V_13 = 0 ; V_13 < V_9 ; V_13 ++ , V_12 ++ ) {
V_12 -> type = V_103 ;
V_12 -> V_104 = 1 ;
V_12 -> V_15 = V_7 -> V_16 [ V_13 ] ;
V_12 -> V_105 = F_50 ( V_106 ) ;
V_12 -> V_107 = V_108 [ V_12 -> V_15 ] ;
V_12 -> V_109 = V_13 ;
V_12 -> V_110 . V_111 = 'u' ;
V_12 -> V_110 . V_112 = 12 ;
V_12 -> V_110 . V_113 = 16 ;
}
V_19 -> V_9 = V_100 ;
return 0 ;
}
static void F_51 ( struct V_18 * V_19 )
{
F_52 ( V_19 -> V_9 ) ;
}
static int F_53 ( struct V_18 * V_19 ,
struct V_11 const * V_12 ,
int * V_6 , int * V_114 , long V_115 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_94 = V_116 ;
int V_13 , V_117 ;
unsigned int V_49 , V_50 , V_118 ;
bool V_119 = false ;
T_1 V_8 ;
unsigned long V_120 ;
if ( F_15 ( V_19 ) )
return - V_75 ;
V_8 = F_6 ( V_7 , V_12 ) ;
if ( ! V_8 )
return - V_121 ;
F_54 ( & V_7 -> V_122 ) ;
V_49 = F_1 ( V_7 , V_52 ) ;
while ( V_49 -- )
F_1 ( V_7 , V_54 ) ;
F_55 ( V_7 -> V_4 , V_8 ) ;
V_120 = V_123 + F_56
( V_124 * V_7 -> V_9 ) ;
while ( 1 ) {
V_49 = F_1 ( V_7 , V_52 ) ;
if ( V_49 )
break;
if ( F_57 ( V_123 , V_120 ) ) {
F_58 ( V_7 -> V_4 ) ;
V_94 = - V_125 ;
goto V_126;
}
}
V_117 = V_7 -> V_14 [ V_12 -> V_109 ] ;
for ( V_13 = 0 ; V_13 < V_49 ; V_13 ++ ) {
V_50 = F_1 ( V_7 , V_54 ) ;
V_118 = V_50 & V_127 ;
V_118 = V_118 >> 0x10 ;
if ( V_118 == V_117 ) {
V_50 = V_50 & V_55 ;
V_119 = true ;
* V_6 = ( T_3 ) V_50 ;
}
}
F_58 ( V_7 -> V_4 ) ;
if ( V_119 == false )
V_94 = - V_75 ;
V_126:
F_59 ( & V_7 -> V_122 ) ;
return V_94 ;
}
static int F_60 ( struct V_128 * V_129 ,
struct V_1 * V_7 )
{
struct V_59 * V_60 = & V_7 -> V_60 ;
T_4 V_115 ;
V_60 -> V_70 . V_130 = V_73 ;
V_60 -> V_70 . V_131 = V_132 ;
V_60 -> V_70 . V_133 = V_7 -> V_4 -> V_134 + V_54 ;
F_61 ( V_115 ) ;
F_62 ( V_135 , V_115 ) ;
V_60 -> V_12 = F_63 ( V_7 -> V_4 -> V_21 , L_4 ) ;
if ( F_64 ( V_60 -> V_12 ) ) {
int V_94 = F_65 ( V_60 -> V_12 ) ;
V_60 -> V_12 = NULL ;
return V_94 ;
}
V_60 -> V_61 = F_66 ( V_60 -> V_12 -> V_20 -> V_21 , V_69 ,
& V_60 -> V_72 , V_102 ) ;
if ( ! V_60 -> V_61 )
goto V_136;
return 0 ;
V_136:
F_67 ( V_60 -> V_12 ) ;
return - V_95 ;
}
static int F_68 ( struct V_128 * V_129 ,
struct V_1 * V_7 )
{
struct V_137 * V_138 = V_129 -> V_21 . V_139 ;
struct V_140 * V_141 ;
const T_5 * V_142 ;
int V_9 = 0 ;
T_1 V_6 ;
F_69 (node, L_5 , prop, cur, val) {
V_7 -> V_16 [ V_9 ] = V_6 ;
V_7 -> V_28 [ V_9 ] = V_143 ;
V_7 -> V_30 [ V_9 ] = V_144 ;
V_7 -> V_24 [ V_9 ] = 16 ;
V_9 ++ ;
}
F_70 ( V_138 , L_6 ,
V_7 -> V_24 , V_9 ) ;
F_70 ( V_138 , L_7 ,
V_7 -> V_28 , V_9 ) ;
F_70 ( V_138 , L_8 ,
V_7 -> V_30 , V_9 ) ;
V_7 -> V_9 = V_9 ;
return 0 ;
}
static int F_71 ( struct V_128 * V_129 )
{
struct V_18 * V_19 ;
struct V_1 * V_7 ;
struct V_137 * V_138 = V_129 -> V_21 . V_139 ;
int V_136 ;
if ( ! V_138 ) {
F_72 ( & V_129 -> V_21 , L_9 ) ;
return - V_121 ;
}
V_19 = F_73 ( & V_129 -> V_21 , sizeof( * V_19 ) ) ;
if ( V_19 == NULL ) {
F_72 ( & V_129 -> V_21 , L_10 ) ;
return - V_95 ;
}
V_7 = F_11 ( V_19 ) ;
V_7 -> V_4 = F_74 ( V_129 ) ;
F_68 ( V_129 , V_7 ) ;
V_19 -> V_21 . V_145 = & V_129 -> V_21 ;
V_19 -> V_96 = F_75 ( & V_129 -> V_21 ) ;
V_19 -> V_98 = V_146 ;
V_19 -> V_147 = & V_148 ;
F_10 ( V_19 ) ;
F_3 ( V_7 , V_79 , V_67 ) ;
F_76 ( & V_7 -> V_122 ) ;
V_136 = F_48 ( V_19 , V_7 -> V_9 ) ;
if ( V_136 < 0 )
return V_136 ;
V_136 = F_39 ( V_19 ,
& F_22 ,
& F_21 ,
V_7 -> V_4 -> V_31 ,
V_149 ,
& V_150 ) ;
if ( V_136 )
goto V_151;
V_136 = F_77 ( V_19 ) ;
if ( V_136 )
goto V_152;
F_78 ( V_129 , V_19 ) ;
V_136 = F_60 ( V_129 , V_7 ) ;
if ( V_136 && V_136 == - V_153 )
goto V_154;
return 0 ;
V_154:
F_79 ( V_19 ) ;
V_152:
F_46 ( V_19 ) ;
V_151:
F_51 ( V_19 ) ;
return V_136 ;
}
static int F_80 ( struct V_128 * V_129 )
{
struct V_18 * V_19 = F_81 ( V_129 ) ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_59 * V_60 = & V_7 -> V_60 ;
T_1 V_8 ;
if ( V_60 -> V_12 ) {
F_82 ( V_60 -> V_12 -> V_20 -> V_21 , V_69 ,
V_60 -> V_61 , V_60 -> V_72 ) ;
F_67 ( V_60 -> V_12 ) ;
}
F_79 ( V_19 ) ;
F_46 ( V_19 ) ;
F_51 ( V_19 ) ;
V_8 = F_5 ( V_7 ) ;
F_36 ( V_7 -> V_4 , V_8 ) ;
return 0 ;
}
static int T_6 F_83 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = F_84 ( V_21 ) ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_155 * V_156 ;
unsigned int V_157 ;
V_156 = F_74 ( F_85 ( V_21 ) ) ;
if ( ! F_86 ( V_156 -> V_21 ) ) {
V_157 = F_1 ( V_7 , V_39 ) ;
V_157 &= ~ ( V_40 ) ;
F_3 ( V_7 , V_39 , ( V_157 |
V_158 ) ) ;
}
return 0 ;
}
static int T_6 F_87 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = F_84 ( V_21 ) ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
unsigned int V_159 ;
V_159 = F_1 ( V_7 , V_39 ) ;
V_159 &= ~ ( V_158 ) ;
F_3 ( V_7 , V_39 , V_159 ) ;
F_10 ( V_19 ) ;
F_34 ( V_7 -> V_4 ,
V_7 -> V_86 ) ;
return 0 ;
}
