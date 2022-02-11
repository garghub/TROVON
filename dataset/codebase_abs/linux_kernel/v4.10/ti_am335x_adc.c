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
unsigned int V_33 , V_34 ;
V_33 = F_1 ( V_7 , V_35 ) ;
if ( V_33 & V_36 ) {
V_34 = F_1 ( V_7 , V_37 ) ;
V_34 &= ~ ( V_38 ) ;
F_3 ( V_7 , V_37 , V_34 ) ;
F_3 ( V_7 , V_35 , V_36
| V_39 | V_40 ) ;
F_3 ( V_7 , V_37 , ( V_34 | V_38 ) ) ;
return V_41 ;
} else if ( V_33 & V_40 ) {
F_3 ( V_7 , V_42 , V_40 ) ;
return V_43 ;
}
return V_44 ;
}
static T_2 F_22 ( int V_31 , void * V_32 )
{
struct V_18 * V_19 = V_32 ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_13 , V_45 , V_46 , V_47 ;
T_3 * V_48 = V_7 -> V_48 ;
V_46 = F_1 ( V_7 , V_49 ) ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 = V_45 + V_13 ) {
for ( V_13 = 0 ; V_13 < ( V_19 -> V_50 ) / 2 ; V_13 ++ ) {
V_47 = F_1 ( V_7 , V_51 ) ;
V_48 [ V_13 ] = V_47 & V_52 ;
}
F_23 ( V_19 , ( V_53 * ) V_48 ) ;
}
F_3 ( V_7 , V_35 , V_40 ) ;
F_3 ( V_7 , V_54 , V_40 ) ;
return V_41 ;
}
static void F_24 ( void * V_55 )
{
struct V_18 * V_19 = V_55 ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_56 * V_57 = & V_7 -> V_57 ;
V_53 * V_48 ;
int V_13 ;
V_48 = V_57 -> V_58 + V_57 -> V_59 * V_57 -> V_60 ;
V_57 -> V_59 = 1 - V_57 -> V_59 ;
for ( V_13 = 0 ; V_13 < V_57 -> V_60 ; V_13 += V_19 -> V_50 ) {
F_23 ( V_19 , V_48 ) ;
V_48 += V_19 -> V_50 ;
}
}
static int F_25 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_56 * V_57 = & V_7 -> V_57 ;
struct V_61 * V_62 ;
V_57 -> V_59 = 0 ;
V_57 -> V_63 = F_26 ( V_64 + 1 ,
V_7 -> V_65 ) - 1 ;
V_57 -> V_60 = F_26 ( V_66 / 2 ,
( V_57 -> V_63 + 1 ) * sizeof( T_3 ) ) ;
V_57 -> V_67 . V_68 = V_57 -> V_63 + 1 ;
F_27 ( V_57 -> V_12 , & V_57 -> V_67 ) ;
V_62 = F_28 ( V_57 -> V_12 , V_57 -> V_69 ,
V_57 -> V_60 * 2 ,
V_57 -> V_60 , V_70 ,
V_71 ) ;
if ( ! V_62 )
return - V_72 ;
V_62 -> V_73 = F_24 ;
V_62 -> V_74 = V_19 ;
V_57 -> V_75 = F_29 ( V_62 ) ;
F_30 ( V_57 -> V_12 ) ;
F_3 ( V_7 , V_76 , V_57 -> V_63 ) ;
F_3 ( V_7 , V_77 , V_57 -> V_63 ) ;
F_3 ( V_7 , V_78 , V_79 ) ;
return 0 ;
}
static int F_31 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_13 , V_46 , V_47 ;
F_3 ( V_7 , V_42 , ( V_40 |
V_36 |
V_39 ) ) ;
V_46 = F_1 ( V_7 , V_49 ) ;
for ( V_13 = 0 ; V_13 < V_46 ; V_13 ++ )
V_47 = F_1 ( V_7 , V_51 ) ;
return 0 ;
}
static int F_32 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_56 * V_57 = & V_7 -> V_57 ;
unsigned int V_80 ;
unsigned int V_81 = 0 ;
V_53 V_82 ;
F_10 ( V_19 ) ;
F_33 (bit, indio_dev->active_scan_mask, adc_dev->channels) {
V_81 |= ( F_9 ( V_7 , V_82 ) << 1 ) ;
V_7 -> V_65 ++ ;
}
V_7 -> V_83 = V_81 ;
if ( V_57 -> V_12 )
F_25 ( V_19 ) ;
F_34 ( V_7 -> V_4 , V_81 ) ;
F_3 ( V_7 , V_35 , V_40
| V_36 | V_39 ) ;
V_80 = V_36 ;
if ( ! V_57 -> V_12 )
V_80 |= V_40 ;
F_3 ( V_7 , V_54 , V_80 ) ;
return 0 ;
}
static int F_35 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_56 * V_57 = & V_7 -> V_57 ;
int V_46 , V_13 , V_47 ;
F_3 ( V_7 , V_42 , ( V_40 |
V_36 | V_39 ) ) ;
F_36 ( V_7 -> V_4 , V_7 -> V_83 ) ;
V_7 -> V_83 = 0 ;
V_7 -> V_65 = 0 ;
if ( V_57 -> V_12 ) {
F_3 ( V_7 , V_84 , 0x2 ) ;
F_37 ( V_57 -> V_12 ) ;
}
V_46 = F_1 ( V_7 , V_49 ) ;
for ( V_13 = 0 ; V_13 < V_46 ; V_13 ++ )
V_47 = F_1 ( V_7 , V_51 ) ;
return 0 ;
}
static int F_38 ( struct V_18 * V_19 )
{
F_10 ( V_19 ) ;
return 0 ;
}
static int F_39 ( struct V_18 * V_19 ,
T_2 (* F_40)( int V_31 , void * V_85 ) ,
T_2 (* F_41)( int V_31 , void * V_85 ) ,
int V_31 ,
unsigned long V_86 ,
const struct V_87 * V_88 )
{
struct V_89 * V_90 ;
int V_91 ;
V_90 = F_42 () ;
if ( ! V_90 )
return - V_92 ;
F_43 ( V_19 , V_90 ) ;
V_91 = F_44 ( V_31 , F_41 , F_40 ,
V_86 , V_19 -> V_93 , V_19 ) ;
if ( V_91 )
goto V_94;
V_19 -> V_88 = V_88 ;
V_19 -> V_95 |= V_96 ;
return 0 ;
V_94:
F_45 ( V_19 -> V_90 ) ;
return V_91 ;
}
static void F_46 ( struct V_18 * V_19 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
F_47 ( V_7 -> V_4 -> V_31 , V_19 ) ;
F_45 ( V_19 -> V_90 ) ;
}
static int F_48 ( struct V_18 * V_19 , int V_9 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_11 * V_97 ;
struct V_11 * V_12 ;
int V_13 ;
V_19 -> V_98 = V_9 ;
V_97 = F_49 ( V_9 , sizeof( * V_97 ) , V_99 ) ;
if ( V_97 == NULL )
return - V_92 ;
V_12 = V_97 ;
for ( V_13 = 0 ; V_13 < V_9 ; V_13 ++ , V_12 ++ ) {
V_12 -> type = V_100 ;
V_12 -> V_101 = 1 ;
V_12 -> V_15 = V_7 -> V_16 [ V_13 ] ;
V_12 -> V_102 = F_50 ( V_103 ) ;
V_12 -> V_104 = V_105 [ V_12 -> V_15 ] ;
V_12 -> V_106 = V_13 ;
V_12 -> V_107 . V_108 = 'u' ;
V_12 -> V_107 . V_109 = 12 ;
V_12 -> V_107 . V_110 = 16 ;
}
V_19 -> V_9 = V_97 ;
return 0 ;
}
static void F_51 ( struct V_18 * V_19 )
{
F_52 ( V_19 -> V_9 ) ;
}
static int F_53 ( struct V_18 * V_19 ,
struct V_11 const * V_12 ,
int * V_6 , int * V_111 , long V_112 )
{
struct V_1 * V_7 = F_11 ( V_19 ) ;
int V_91 = V_113 ;
int V_13 , V_114 ;
unsigned int V_46 , V_47 , V_115 ;
bool V_116 = false ;
T_1 V_8 ;
unsigned long V_117 ;
if ( F_15 ( V_19 ) )
return - V_72 ;
V_8 = F_6 ( V_7 , V_12 ) ;
if ( ! V_8 )
return - V_118 ;
F_54 ( & V_7 -> V_119 ) ;
V_46 = F_1 ( V_7 , V_49 ) ;
while ( V_46 -- )
F_1 ( V_7 , V_51 ) ;
F_55 ( V_7 -> V_4 , V_8 ) ;
V_117 = V_120 + F_56
( V_121 * V_7 -> V_9 ) ;
while ( 1 ) {
V_46 = F_1 ( V_7 , V_49 ) ;
if ( V_46 )
break;
if ( F_57 ( V_120 , V_117 ) ) {
F_58 ( V_7 -> V_4 ) ;
V_91 = - V_122 ;
goto V_123;
}
}
V_114 = V_7 -> V_14 [ V_12 -> V_106 ] ;
for ( V_13 = 0 ; V_13 < V_46 ; V_13 ++ ) {
V_47 = F_1 ( V_7 , V_51 ) ;
V_115 = V_47 & V_124 ;
V_115 = V_115 >> 0x10 ;
if ( V_115 == V_114 ) {
V_47 = V_47 & V_52 ;
V_116 = true ;
* V_6 = ( T_3 ) V_47 ;
}
}
F_58 ( V_7 -> V_4 ) ;
if ( V_116 == false )
V_91 = - V_72 ;
V_123:
F_59 ( & V_7 -> V_119 ) ;
return V_91 ;
}
static int F_60 ( struct V_125 * V_126 ,
struct V_1 * V_7 )
{
struct V_56 * V_57 = & V_7 -> V_57 ;
T_4 V_112 ;
V_57 -> V_67 . V_127 = V_70 ;
V_57 -> V_67 . V_128 = V_129 ;
V_57 -> V_67 . V_130 = V_7 -> V_4 -> V_131 + V_51 ;
F_61 ( V_112 ) ;
F_62 ( V_132 , V_112 ) ;
V_57 -> V_12 = F_63 ( V_7 -> V_4 -> V_21 , L_4 ) ;
if ( F_64 ( V_57 -> V_12 ) ) {
int V_91 = F_65 ( V_57 -> V_12 ) ;
V_57 -> V_12 = NULL ;
return V_91 ;
}
V_57 -> V_58 = F_66 ( V_57 -> V_12 -> V_20 -> V_21 , V_66 ,
& V_57 -> V_69 , V_99 ) ;
if ( ! V_57 -> V_58 )
goto V_133;
return 0 ;
V_133:
F_67 ( V_57 -> V_12 ) ;
return - V_92 ;
}
static int F_68 ( struct V_125 * V_126 ,
struct V_1 * V_7 )
{
struct V_134 * V_135 = V_126 -> V_21 . V_136 ;
struct V_137 * V_138 ;
const T_5 * V_139 ;
int V_9 = 0 ;
T_1 V_6 ;
F_69 (node, L_5 , prop, cur, val) {
V_7 -> V_16 [ V_9 ] = V_6 ;
V_7 -> V_28 [ V_9 ] = V_140 ;
V_7 -> V_30 [ V_9 ] = V_141 ;
V_7 -> V_24 [ V_9 ] = 16 ;
V_9 ++ ;
}
F_70 ( V_135 , L_6 ,
V_7 -> V_24 , V_9 ) ;
F_70 ( V_135 , L_7 ,
V_7 -> V_28 , V_9 ) ;
F_70 ( V_135 , L_8 ,
V_7 -> V_30 , V_9 ) ;
V_7 -> V_9 = V_9 ;
return 0 ;
}
static int F_71 ( struct V_125 * V_126 )
{
struct V_18 * V_19 ;
struct V_1 * V_7 ;
struct V_134 * V_135 = V_126 -> V_21 . V_136 ;
int V_133 ;
if ( ! V_135 ) {
F_72 ( & V_126 -> V_21 , L_9 ) ;
return - V_118 ;
}
V_19 = F_73 ( & V_126 -> V_21 , sizeof( * V_19 ) ) ;
if ( V_19 == NULL ) {
F_72 ( & V_126 -> V_21 , L_10 ) ;
return - V_92 ;
}
V_7 = F_11 ( V_19 ) ;
V_7 -> V_4 = F_74 ( V_126 ) ;
F_68 ( V_126 , V_7 ) ;
V_19 -> V_21 . V_142 = & V_126 -> V_21 ;
V_19 -> V_93 = F_75 ( & V_126 -> V_21 ) ;
V_19 -> V_95 = V_143 ;
V_19 -> V_144 = & V_145 ;
F_10 ( V_19 ) ;
F_3 ( V_7 , V_76 , V_64 ) ;
F_76 ( & V_7 -> V_119 ) ;
V_133 = F_48 ( V_19 , V_7 -> V_9 ) ;
if ( V_133 < 0 )
return V_133 ;
V_133 = F_39 ( V_19 ,
& F_22 ,
& F_21 ,
V_7 -> V_4 -> V_31 ,
V_146 ,
& V_147 ) ;
if ( V_133 )
goto V_148;
V_133 = F_77 ( V_19 ) ;
if ( V_133 )
goto V_149;
F_78 ( V_126 , V_19 ) ;
V_133 = F_60 ( V_126 , V_7 ) ;
if ( V_133 && V_133 == - V_150 )
goto V_151;
return 0 ;
V_151:
F_79 ( V_19 ) ;
V_149:
F_46 ( V_19 ) ;
V_148:
F_51 ( V_19 ) ;
return V_133 ;
}
static int F_80 ( struct V_125 * V_126 )
{
struct V_18 * V_19 = F_81 ( V_126 ) ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
struct V_56 * V_57 = & V_7 -> V_57 ;
T_1 V_8 ;
if ( V_57 -> V_12 ) {
F_82 ( V_57 -> V_12 -> V_20 -> V_21 , V_66 ,
V_57 -> V_58 , V_57 -> V_69 ) ;
F_67 ( V_57 -> V_12 ) ;
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
struct V_152 * V_153 ;
unsigned int V_154 ;
V_153 = F_74 ( F_85 ( V_21 ) ) ;
if ( ! F_86 ( V_153 -> V_21 ) ) {
V_154 = F_1 ( V_7 , V_37 ) ;
V_154 &= ~ ( V_38 ) ;
F_3 ( V_7 , V_37 , ( V_154 |
V_155 ) ) ;
}
return 0 ;
}
static int T_6 F_87 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = F_84 ( V_21 ) ;
struct V_1 * V_7 = F_11 ( V_19 ) ;
unsigned int V_156 ;
V_156 = F_1 ( V_7 , V_37 ) ;
V_156 &= ~ ( V_155 ) ;
F_3 ( V_7 , V_37 , V_156 ) ;
F_10 ( V_19 ) ;
F_34 ( V_7 -> V_4 ,
V_7 -> V_83 ) ;
return 0 ;
}
