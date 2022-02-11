static int F_1 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
int * V_4 , int * V_5 , long V_6 )
{
struct V_7 * V_8 = F_2 ( V_1 ) ;
int V_9 ;
if ( V_6 != V_10 )
return - V_11 ;
if ( V_3 -> V_12 > V_13 )
return - V_11 ;
V_9 = F_3 ( & V_8 -> V_14 ) ;
if ( ! V_9 )
return - V_15 ;
F_4 ( V_8 -> V_16 ) ;
F_5 ( V_17 ,
V_8 -> V_18 + V_19 + V_20 ) ;
F_5 ( 0xff , V_8 -> V_18 + V_21 + V_20 ) ;
F_5 ( F_6 ( 0 ) ,
V_8 -> V_18 + V_22 + V_20 ) ;
F_5 ( V_3 -> V_12 , V_8 -> V_18 + V_22 + V_23 ) ;
F_5 ( 0 , V_8 -> V_18 + F_7 ( 0 ) ) ;
F_5 ( F_8 ( 0 ) ,
V_8 -> V_18 + V_19 + V_23 ) ;
F_5 ( 1 << 0 , V_8 -> V_18 + V_21 + V_23 ) ;
V_9 = F_9 ( & V_8 -> V_16 , V_24 ) ;
if ( ! V_9 )
V_9 = - V_25 ;
if ( V_9 < 0 )
goto V_26;
* V_4 = F_10 ( V_8 -> V_18 + F_7 ( 0 ) ) & V_27 ;
V_9 = V_28 ;
V_26:
F_5 ( F_8 ( 0 ) ,
V_8 -> V_18 + V_19 + V_20 ) ;
F_11 ( & V_8 -> V_14 ) ;
return V_9 ;
}
static int F_12 ( struct V_7 * V_8 )
{
T_1 V_29 ;
F_5 ( V_30 ,
V_8 -> V_18 + V_21 + V_20 ) ;
F_5 ( V_31 ,
V_8 -> V_18 + V_21 + V_23 ) ;
F_13 ( V_32 ) ;
V_29 = F_10 ( V_8 -> V_18 + V_33 ) ;
return V_29 & V_34 ;
}
static T_2 F_14 ( struct V_7 * V_8 ,
enum V_35 V_36 , int V_37 )
{
unsigned long V_38 , V_39 ;
T_1 V_29 , V_40 = 0 , V_3 = 0 ;
const T_3 V_41 = 7 ;
T_1 V_4 ;
switch ( V_36 ) {
case V_42 :
V_40 = V_43 | V_44 ;
V_3 = 3 ;
break;
case V_45 :
V_40 = V_46 | V_47 ;
V_3 = 4 ;
break;
case V_48 :
V_40 = V_46 | V_44 ;
V_3 = 5 ;
break;
}
if ( V_37 ) {
F_5 ( V_30 ,
V_8 -> V_18 + V_21 + V_20 ) ;
F_5 ( V_40 , V_8 -> V_18 + V_21 + V_23 ) ;
F_5 ( F_6 ( V_41 ) ,
V_8 -> V_18 + V_22 + V_20 ) ;
F_5 ( V_3 << F_15 ( V_41 ) ,
V_8 -> V_18 + V_22 + V_23 ) ;
}
F_5 ( 0xffffffff , V_8 -> V_18 + F_7 ( V_41 ) + V_20 ) ;
F_5 ( 1 << V_41 , V_8 -> V_18 + V_21 + V_23 ) ;
V_38 = V_49 + F_16 ( V_32 ) ;
do {
V_39 = V_49 ;
V_29 = F_17 ( V_8 -> V_18 + V_19 ) ;
if ( V_29 & F_18 ( V_41 ) )
break;
} while ( F_19 ( V_39 , V_38 ) );
F_5 ( F_18 ( V_41 ) ,
V_8 -> V_18 + V_19 + V_20 ) ;
if ( F_20 ( V_39 , V_38 ) )
return - V_25 ;
V_4 = F_10 ( V_8 -> V_18 + F_7 ( V_41 ) ) ;
V_4 &= V_27 ;
return V_4 ;
}
static T_2 F_21 ( struct V_7 * V_8 ,
enum V_35 V_36 )
{
T_2 V_4 , V_50 = 0 ;
int V_51 ;
V_4 = F_14 ( V_8 , V_36 , 1 ) ;
F_22 ( 2 ) ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
V_4 = F_14 ( V_8 , V_36 , 0 ) ;
V_50 += V_4 ;
}
return V_50 / V_52 ;
}
static void F_23 ( struct V_53 * V_54 )
{
struct V_7 * V_8 = F_24 ( V_54 ,
struct V_7 , V_54 ) ;
int V_55 , V_56 , V_57 ;
bool V_58 = false ;
while ( F_12 ( V_8 ) ) {
F_5 ( V_31 ,
V_8 -> V_18 + V_21 + V_20 ) ;
if ( F_25 ( V_58 ) ) {
F_26 ( V_8 -> V_59 , V_60 , V_55 ) ;
F_26 ( V_8 -> V_59 , V_61 , V_56 ) ;
F_26 ( V_8 -> V_59 , V_62 , V_57 ) ;
F_27 ( V_8 -> V_59 , V_63 , 1 ) ;
F_28 ( V_8 -> V_59 ) ;
}
V_58 = false ;
V_55 = F_21 ( V_8 , V_42 ) ;
if ( V_55 < 0 )
continue;
V_56 = F_21 ( V_8 , V_45 ) ;
if ( V_56 < 0 )
continue;
V_57 = F_21 ( V_8 , V_48 ) ;
if ( V_57 < 0 )
continue;
V_58 = true ;
}
F_26 ( V_8 -> V_59 , V_62 , 0 ) ;
F_27 ( V_8 -> V_59 , V_63 , 0 ) ;
F_28 ( V_8 -> V_59 ) ;
if ( V_8 -> V_64 )
return;
F_5 ( V_65 ,
V_8 -> V_18 + V_19 + V_20 ) ;
F_5 ( V_66 ,
V_8 -> V_18 + V_19 + V_23 ) ;
}
static int F_29 ( struct V_67 * V_68 )
{
struct V_7 * V_8 = F_30 ( V_68 ) ;
V_8 -> V_64 = false ;
F_5 ( V_31 ,
V_8 -> V_18 + V_21 + V_23 ) ;
F_5 ( V_66 ,
V_8 -> V_18 + V_19 + V_23 ) ;
return 0 ;
}
static void F_31 ( struct V_67 * V_68 )
{
struct V_7 * V_8 = F_30 ( V_68 ) ;
V_8 -> V_64 = true ;
F_32 () ;
F_33 ( & V_8 -> V_54 ) ;
F_5 ( V_66 ,
V_8 -> V_18 + V_19 + V_20 ) ;
F_5 ( V_31 ,
V_8 -> V_18 + V_21 + V_20 ) ;
}
static int F_34 ( struct V_7 * V_8 )
{
struct V_67 * V_69 ;
struct V_70 * V_68 = V_8 -> V_68 ;
int V_9 ;
if ( ! V_8 -> V_71 )
return 0 ;
V_69 = F_35 () ;
if ( ! V_69 ) {
F_36 ( V_68 , L_1 ) ;
return - V_72 ;
}
V_69 -> V_73 = V_74 ;
V_69 -> V_75 . V_76 = V_77 ;
V_69 -> V_68 . V_78 = V_68 ;
V_69 -> V_79 = F_29 ;
V_69 -> V_80 = F_31 ;
F_37 ( V_81 , V_69 -> V_82 ) ;
F_37 ( V_83 , V_69 -> V_82 ) ;
F_37 ( V_63 , V_69 -> V_84 ) ;
F_38 ( V_69 , V_60 , 0 , V_85 , 0 , 0 ) ;
F_38 ( V_69 , V_61 , 0 , V_85 , 0 , 0 ) ;
F_38 ( V_69 , V_62 , 0 , V_85 ,
0 , 0 ) ;
V_8 -> V_59 = V_69 ;
F_39 ( V_69 , V_8 ) ;
V_9 = F_40 ( V_69 ) ;
if ( V_9 )
F_41 ( V_8 -> V_59 ) ;
return V_9 ;
}
static void F_42 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_71 )
return;
F_33 ( & V_8 -> V_54 ) ;
F_43 ( V_8 -> V_59 ) ;
}
static T_4 F_44 ( int V_86 , void * V_87 )
{
struct V_1 * V_88 = V_87 ;
struct V_7 * V_8 = F_2 ( V_88 ) ;
unsigned long V_29 = F_10 ( V_8 -> V_18 + V_19 ) ;
const T_1 V_89 =
V_66 |
V_65 ;
if ( ! ( V_29 & V_90 ) )
return V_91 ;
if ( V_29 & V_65 ) {
F_5 ( V_89 ,
V_8 -> V_18 + V_19 + V_20 ) ;
if ( ! V_8 -> V_64 )
F_45 ( & V_8 -> V_54 ) ;
}
if ( F_46 ( V_88 ) )
F_47 ( V_88 -> V_92 , F_48 () ) ;
else if ( V_29 & F_18 ( 0 ) )
F_49 ( & V_8 -> V_16 ) ;
F_5 ( V_29 & V_90 ,
V_8 -> V_18 + V_19 + V_20 ) ;
return V_93 ;
}
static T_4 F_50 ( int V_86 , void * V_94 )
{
struct V_95 * V_96 = V_94 ;
struct V_1 * V_88 = V_96 -> V_97 ;
struct V_7 * V_8 = F_2 ( V_88 ) ;
const T_1 V_98 = V_99 |
( ( V_100 - 1 ) << V_101 ) ;
unsigned int V_51 , V_102 = 0 ;
F_51 (i, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_8 -> V_103 [ V_102 ] = F_10 ( V_8 -> V_18 + F_7 ( V_102 ) ) ;
F_5 ( V_98 , V_8 -> V_18 + F_7 ( V_102 ) ) ;
V_8 -> V_103 [ V_102 ] &= V_27 ;
V_8 -> V_103 [ V_102 ] /= V_100 ;
V_102 ++ ;
}
if ( V_88 -> V_104 ) {
T_5 * V_105 = ( T_5 * ) ( ( V_106 * ) V_8 -> V_103 +
F_52 ( V_102 , sizeof( T_5 ) ) ) ;
* V_105 = V_96 -> V_105 ;
}
F_53 ( V_88 , ( V_106 * ) V_8 -> V_103 ) ;
F_54 ( V_88 -> V_92 ) ;
return V_93 ;
}
static int F_55 ( struct V_107 * V_92 , bool V_108 )
{
struct V_1 * V_88 = F_56 ( V_92 ) ;
struct V_7 * V_8 = F_2 ( V_88 ) ;
const T_1 V_109 = V_108 ? V_23 : V_20 ;
F_5 ( V_110 , V_8 -> V_18 + F_57 ( 0 ) + V_109 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_88 )
{
int V_9 ;
struct V_107 * V_92 ;
struct V_7 * V_8 = F_2 ( V_88 ) ;
V_92 = F_59 ( L_2 , V_88 -> V_73 , V_88 -> V_75 ) ;
if ( V_92 == NULL )
return - V_72 ;
V_92 -> V_68 . V_78 = V_8 -> V_68 ;
F_60 ( V_92 , V_88 ) ;
V_92 -> V_111 = & V_112 ;
V_9 = F_61 ( V_92 ) ;
if ( V_9 ) {
F_62 ( V_92 ) ;
return V_9 ;
}
V_8 -> V_92 = V_92 ;
return 0 ;
}
static void F_63 ( struct V_1 * V_88 )
{
struct V_7 * V_8 = F_2 ( V_88 ) ;
F_64 ( V_8 -> V_92 ) ;
F_62 ( V_8 -> V_92 ) ;
}
static int F_65 ( struct V_1 * V_88 )
{
struct V_7 * V_8 = F_2 ( V_88 ) ;
int V_9 = 0 , V_3 , V_113 = 0 ;
unsigned long V_114 = 0 ;
T_1 V_115 = 0 ;
T_1 V_116 = 0 ;
T_1 V_117 = 0 ;
const T_1 V_98 = V_99 |
( ( V_100 - 1 ) << V_101 ) ;
const int V_118 = F_66 ( V_88 -> V_119 , V_13 ) ;
if ( ! V_118 )
return - V_11 ;
V_9 = F_3 ( & V_8 -> V_14 ) ;
if ( ! V_9 )
return - V_15 ;
V_8 -> V_103 = F_67 ( V_118 * sizeof( * V_8 -> V_103 ) , V_120 ) ;
if ( ! V_8 -> V_103 ) {
V_9 = - V_72 ;
goto V_121;
}
V_9 = F_68 ( V_88 ) ;
if ( V_9 < 0 )
goto V_122;
F_5 ( V_17 ,
V_8 -> V_18 + V_19 + V_20 ) ;
F_5 ( 0xff , V_8 -> V_18 + V_21 + V_20 ) ;
F_51 (chan, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_115 |= V_3 << F_15 ( V_113 ) ;
V_116 |= F_6 ( V_113 ) ;
V_117 |= F_8 ( V_113 ) ;
F_5 ( V_98 , V_8 -> V_18 + F_7 ( V_113 ) ) ;
F_69 ( & V_114 , V_113 , 1 ) ;
V_113 ++ ;
}
F_5 ( V_123 | V_110 ,
V_8 -> V_18 + F_57 ( 0 ) + V_20 ) ;
F_5 ( V_116 , V_8 -> V_18 + V_22 + V_20 ) ;
F_5 ( V_115 , V_8 -> V_18 + V_22 + V_23 ) ;
F_5 ( V_117 , V_8 -> V_18 + V_19 + V_23 ) ;
F_5 ( V_114 << V_124 ,
V_8 -> V_18 + F_57 ( 0 ) + V_23 ) ;
return 0 ;
V_122:
F_70 ( V_8 -> V_103 ) ;
V_121:
F_11 ( & V_8 -> V_14 ) ;
return V_9 ;
}
static int F_71 ( struct V_1 * V_88 )
{
struct V_7 * V_8 = F_2 ( V_88 ) ;
F_5 ( V_123 | V_110 ,
V_8 -> V_18 + F_57 ( 0 ) + V_20 ) ;
F_5 ( 0xff , V_8 -> V_18 + V_21 + V_20 ) ;
F_5 ( V_17 ,
V_8 -> V_18 + V_19 + V_20 ) ;
F_70 ( V_8 -> V_103 ) ;
F_11 ( & V_8 -> V_14 ) ;
return 0 ;
}
static bool F_72 ( struct V_1 * V_88 ,
const unsigned long * V_125 )
{
struct V_7 * V_8 = F_2 ( V_88 ) ;
const int V_126 = F_66 ( V_125 , V_13 ) ;
int V_127 = 0 ;
unsigned long V_128 = 0 ;
if ( V_8 -> V_129 )
V_128 |= V_130 ;
if ( V_8 -> V_71 == V_131 )
V_128 |= V_132 ;
if ( V_8 -> V_71 == V_133 )
V_128 |= V_134 ;
if ( V_8 -> V_129 )
V_127 ++ ;
if ( V_8 -> V_71 )
V_127 ++ ;
if ( F_73 ( V_125 , & V_128 , V_13 ) )
return false ;
if ( V_126 + V_127 > V_135 )
return false ;
return true ;
}
static int F_74 ( struct V_7 * V_8 )
{
const T_1 V_136 =
( 1 << ( V_137 + 0 ) ) |
( V_138 << V_139 ) ;
int V_9 = F_75 ( V_8 -> V_18 ) ;
if ( V_9 )
return V_9 ;
F_5 ( V_136 , V_8 -> V_18 + F_57 ( 0 ) ) ;
F_5 ( 0 , V_8 -> V_18 + F_57 ( 1 ) ) ;
F_5 ( 0 , V_8 -> V_18 + F_57 ( 2 ) ) ;
F_5 ( 0 , V_8 -> V_18 + F_57 ( 3 ) ) ;
F_5 ( V_140 ,
V_8 -> V_18 + V_21 + V_20 ) ;
if ( V_8 -> V_71 == V_133 ) {
F_5 ( V_140 ,
V_8 -> V_18 + V_21 + V_23 ) ;
}
F_5 ( 0 , V_8 -> V_18 + V_141 ) ;
return 0 ;
}
static void F_76 ( struct V_7 * V_8 )
{
int V_51 ;
F_5 ( V_17 ,
V_8 -> V_18 + V_19 + V_20 ) ;
for ( V_51 = 0 ; V_51 < V_142 ; V_51 ++ )
F_5 ( 0 , V_8 -> V_18 + F_57 ( V_51 ) ) ;
}
static int F_77 ( struct V_143 * V_144 )
{
const struct V_145 * V_146 =
F_78 ( V_147 , & V_144 -> V_68 ) ;
const struct V_148 * V_149 =
& V_148 [ ( enum V_150 ) V_146 -> V_87 ];
struct V_70 * V_68 = & V_144 -> V_68 ;
struct V_151 * V_152 = V_68 -> V_153 ;
struct V_7 * V_8 ;
struct V_1 * V_88 ;
struct V_154 * V_155 ;
T_1 V_156 = 0 ;
int V_9 = 0 ;
int V_51 ;
V_88 = F_79 ( V_68 , sizeof( * V_8 ) ) ;
if ( ! V_88 ) {
F_36 ( V_68 , L_3 ) ;
return - V_72 ;
}
V_8 = F_2 ( V_88 ) ;
V_155 = F_80 ( V_144 , V_157 , 0 ) ;
V_8 -> V_68 = & V_144 -> V_68 ;
V_8 -> V_18 = F_81 ( V_68 , V_155 ) ;
if ( F_82 ( V_8 -> V_18 ) )
return F_83 ( V_8 -> V_18 ) ;
F_84 ( & V_8 -> V_54 , F_23 ) ;
V_9 = F_85 ( V_152 , L_4 ,
& V_156 ) ;
if ( V_9 )
F_86 ( V_68 , L_5 ) ;
else if ( V_156 == 4 )
V_8 -> V_71 = V_131 ;
else if ( V_156 == 5 )
V_8 -> V_71 = V_133 ;
else
F_87 ( V_68 , L_6 ,
V_156 ) ;
for ( V_51 = 0 ; V_51 < V_149 -> V_158 ; V_51 ++ ) {
V_8 -> V_86 [ V_51 ] = F_88 ( V_144 , V_51 ) ;
if ( V_8 -> V_86 [ V_51 ] < 0 )
return - V_11 ;
V_9 = F_89 ( V_68 , V_8 -> V_86 [ V_51 ] ,
F_44 , 0 ,
V_149 -> V_159 [ V_51 ] , V_88 ) ;
if ( V_9 )
return V_9 ;
}
F_90 ( V_144 , V_88 ) ;
F_91 ( & V_8 -> V_16 ) ;
F_92 ( & V_8 -> V_14 ) ;
V_88 -> V_73 = V_144 -> V_73 ;
V_88 -> V_68 . V_78 = & V_144 -> V_68 ;
V_88 -> V_160 = & V_161 ;
V_88 -> V_162 = V_163 ;
V_88 -> V_164 = V_165 ;
V_88 -> V_166 = F_93 ( V_165 ) ;
V_88 -> V_167 = V_13 ;
V_9 = F_94 ( V_88 , & V_168 ,
& F_50 ,
& V_169 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_58 ( V_88 ) ;
if ( V_9 )
goto V_170;
V_9 = F_74 ( V_8 ) ;
if ( V_9 )
goto V_171;
V_9 = F_34 ( V_8 ) ;
if ( V_9 )
goto V_171;
V_9 = F_95 ( V_88 ) ;
if ( V_9 ) {
F_36 ( V_68 , L_7 ) ;
goto V_172;
}
return 0 ;
V_172:
F_42 ( V_8 ) ;
V_171:
F_63 ( V_88 ) ;
V_170:
F_96 ( V_88 ) ;
return V_9 ;
}
static int F_97 ( struct V_143 * V_144 )
{
struct V_1 * V_88 = F_98 ( V_144 ) ;
struct V_7 * V_8 = F_2 ( V_88 ) ;
F_42 ( V_8 ) ;
F_76 ( V_8 ) ;
F_99 ( V_88 ) ;
F_96 ( V_88 ) ;
F_63 ( V_88 ) ;
return 0 ;
}
