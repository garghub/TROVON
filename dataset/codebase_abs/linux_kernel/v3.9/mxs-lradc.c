static int F_1 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
int * V_4 , int * V_5 , long V_6 )
{
struct V_7 * V_8 = F_2 ( V_1 ) ;
int V_9 ;
unsigned long V_10 ;
if ( V_6 != V_11 )
return - V_12 ;
if ( V_3 -> V_13 > V_14 )
return - V_12 ;
F_3 ( & V_10 , V_3 -> V_13 , 1 ) ;
V_9 = F_4 ( V_1 , & V_10 ) ;
if ( V_9 )
return - V_12 ;
V_9 = F_5 ( & V_8 -> V_15 ) ;
if ( ! V_9 )
return - V_16 ;
F_6 ( V_8 -> V_17 ) ;
F_7 ( V_18 ,
V_8 -> V_19 + V_20 + V_21 ) ;
F_7 ( 0xff , V_8 -> V_19 + V_22 + V_21 ) ;
F_7 ( F_8 ( 0 ) ,
V_8 -> V_19 + V_23 + V_21 ) ;
F_7 ( V_3 -> V_13 , V_8 -> V_19 + V_23 + V_24 ) ;
F_7 ( 0 , V_8 -> V_19 + F_9 ( 0 ) ) ;
F_7 ( F_10 ( 0 ) ,
V_8 -> V_19 + V_20 + V_24 ) ;
F_7 ( 1 << 0 , V_8 -> V_19 + V_22 + V_24 ) ;
V_9 = F_11 ( & V_8 -> V_17 , V_25 ) ;
if ( ! V_9 )
V_9 = - V_26 ;
if ( V_9 < 0 )
goto V_27;
* V_4 = F_12 ( V_8 -> V_19 + F_9 ( 0 ) ) & V_28 ;
V_9 = V_29 ;
V_27:
F_7 ( F_10 ( 0 ) ,
V_8 -> V_19 + V_20 + V_21 ) ;
F_13 ( & V_8 -> V_15 ) ;
return V_9 ;
}
static int F_14 ( struct V_7 * V_8 )
{
T_1 V_30 ;
F_7 ( V_31 ,
V_8 -> V_19 + V_22 + V_21 ) ;
F_7 ( V_32 ,
V_8 -> V_19 + V_22 + V_24 ) ;
F_15 ( V_33 ) ;
V_30 = F_12 ( V_8 -> V_19 + V_34 ) ;
return V_30 & V_35 ;
}
static T_2 F_16 ( struct V_7 * V_8 ,
enum V_36 V_37 , int V_38 )
{
unsigned long V_39 , V_40 ;
T_1 V_30 , V_41 = 0 , V_3 = 0 ;
const T_3 V_42 = 7 ;
T_1 V_4 ;
switch ( V_37 ) {
case V_43 :
V_41 = V_44 | V_45 ;
V_3 = 3 ;
break;
case V_46 :
V_41 = V_47 | V_48 ;
V_3 = 4 ;
break;
case V_49 :
V_41 = V_47 | V_45 ;
V_3 = 5 ;
break;
}
if ( V_38 ) {
F_7 ( V_31 ,
V_8 -> V_19 + V_22 + V_21 ) ;
F_7 ( V_41 , V_8 -> V_19 + V_22 + V_24 ) ;
F_7 ( F_8 ( V_42 ) ,
V_8 -> V_19 + V_23 + V_21 ) ;
F_7 ( V_3 << F_17 ( V_42 ) ,
V_8 -> V_19 + V_23 + V_24 ) ;
}
F_7 ( 0xffffffff , V_8 -> V_19 + F_9 ( V_42 ) + V_21 ) ;
F_7 ( 1 << V_42 , V_8 -> V_19 + V_22 + V_24 ) ;
V_39 = V_50 + F_18 ( V_33 ) ;
do {
V_40 = V_50 ;
V_30 = F_19 ( V_8 -> V_19 + V_20 ) ;
if ( V_30 & F_20 ( V_42 ) )
break;
} while ( F_21 ( V_40 , V_39 ) );
F_7 ( F_20 ( V_42 ) ,
V_8 -> V_19 + V_20 + V_21 ) ;
if ( F_22 ( V_40 , V_39 ) )
return - V_26 ;
V_4 = F_12 ( V_8 -> V_19 + F_9 ( V_42 ) ) ;
V_4 &= V_28 ;
return V_4 ;
}
static T_2 F_23 ( struct V_7 * V_8 ,
enum V_36 V_37 )
{
T_2 V_4 , V_51 = 0 ;
int V_52 ;
V_4 = F_16 ( V_8 , V_37 , 1 ) ;
F_24 ( 2 ) ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
V_4 = F_16 ( V_8 , V_37 , 0 ) ;
V_51 += V_4 ;
}
return V_51 / V_53 ;
}
static void F_25 ( struct V_54 * V_55 )
{
struct V_7 * V_8 = F_26 ( V_55 ,
struct V_7 , V_55 ) ;
int V_56 , V_57 , V_58 ;
bool V_59 = false ;
while ( F_14 ( V_8 ) ) {
F_7 ( V_32 ,
V_8 -> V_19 + V_22 + V_21 ) ;
if ( F_27 ( V_59 ) ) {
F_28 ( V_8 -> V_60 , V_61 , V_56 ) ;
F_28 ( V_8 -> V_60 , V_62 , V_57 ) ;
F_28 ( V_8 -> V_60 , V_63 , V_58 ) ;
F_29 ( V_8 -> V_60 , V_64 , 1 ) ;
F_30 ( V_8 -> V_60 ) ;
}
V_59 = false ;
V_56 = F_23 ( V_8 , V_43 ) ;
if ( V_56 < 0 )
continue;
V_57 = F_23 ( V_8 , V_46 ) ;
if ( V_57 < 0 )
continue;
V_58 = F_23 ( V_8 , V_49 ) ;
if ( V_58 < 0 )
continue;
V_59 = true ;
}
F_28 ( V_8 -> V_60 , V_63 , 0 ) ;
F_29 ( V_8 -> V_60 , V_64 , 0 ) ;
F_30 ( V_8 -> V_60 ) ;
if ( V_8 -> V_65 )
return;
F_7 ( V_66 ,
V_8 -> V_19 + V_20 + V_21 ) ;
F_7 ( V_67 ,
V_8 -> V_19 + V_20 + V_24 ) ;
}
static int F_31 ( struct V_68 * V_69 )
{
struct V_7 * V_8 = F_32 ( V_69 ) ;
V_8 -> V_65 = false ;
F_7 ( V_32 ,
V_8 -> V_19 + V_22 + V_24 ) ;
F_7 ( V_67 ,
V_8 -> V_19 + V_20 + V_24 ) ;
return 0 ;
}
static void F_33 ( struct V_68 * V_69 )
{
struct V_7 * V_8 = F_32 ( V_69 ) ;
V_8 -> V_65 = true ;
F_34 () ;
F_35 ( & V_8 -> V_55 ) ;
F_7 ( V_67 ,
V_8 -> V_19 + V_20 + V_21 ) ;
F_7 ( V_32 ,
V_8 -> V_19 + V_22 + V_21 ) ;
}
static int F_36 ( struct V_7 * V_8 )
{
struct V_68 * V_70 ;
struct V_71 * V_69 = V_8 -> V_69 ;
int V_9 ;
if ( ! V_8 -> V_72 )
return 0 ;
V_70 = F_37 () ;
if ( ! V_70 ) {
F_38 ( V_69 , L_1 ) ;
return - V_73 ;
}
V_70 -> V_74 = V_75 ;
V_70 -> V_76 . V_77 = V_78 ;
V_70 -> V_69 . V_79 = V_69 ;
V_70 -> V_80 = F_31 ;
V_70 -> V_81 = F_33 ;
F_39 ( V_82 , V_70 -> V_83 ) ;
F_39 ( V_84 , V_70 -> V_83 ) ;
F_39 ( V_64 , V_70 -> V_85 ) ;
F_40 ( V_70 , V_61 , 0 , V_28 , 0 , 0 ) ;
F_40 ( V_70 , V_62 , 0 , V_28 , 0 , 0 ) ;
F_40 ( V_70 , V_63 , 0 , V_28 , 0 , 0 ) ;
V_8 -> V_60 = V_70 ;
F_41 ( V_70 , V_8 ) ;
V_9 = F_42 ( V_70 ) ;
if ( V_9 )
F_43 ( V_8 -> V_60 ) ;
return V_9 ;
}
static void F_44 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_72 )
return;
F_35 ( & V_8 -> V_55 ) ;
F_45 ( V_8 -> V_60 ) ;
}
static T_4 F_46 ( int V_86 , void * V_87 )
{
struct V_1 * V_88 = V_87 ;
struct V_7 * V_8 = F_2 ( V_88 ) ;
unsigned long V_30 = F_12 ( V_8 -> V_19 + V_20 ) ;
const T_1 V_89 =
V_67 |
V_66 ;
if ( ! ( V_30 & V_90 ) )
return V_91 ;
if ( V_30 & V_66 ) {
F_7 ( V_89 ,
V_8 -> V_19 + V_20 + V_21 ) ;
if ( ! V_8 -> V_65 )
F_47 ( & V_8 -> V_55 ) ;
}
if ( F_48 ( V_88 ) )
F_49 ( V_88 -> V_92 , F_50 () ) ;
else if ( V_30 & F_20 ( 0 ) )
F_51 ( & V_8 -> V_17 ) ;
F_7 ( V_30 & V_90 ,
V_8 -> V_19 + V_20 + V_21 ) ;
return V_93 ;
}
static T_4 F_52 ( int V_86 , void * V_94 )
{
struct V_95 * V_96 = V_94 ;
struct V_1 * V_88 = V_96 -> V_97 ;
struct V_7 * V_8 = F_2 ( V_88 ) ;
const T_1 V_98 = V_99 |
( ( V_100 - 1 ) << V_101 ) ;
unsigned int V_52 , V_102 = 0 ;
F_53 (i, iio->active_scan_mask, iio->masklength) {
V_8 -> V_103 [ V_102 ] = F_12 ( V_8 -> V_19 + F_9 ( V_102 ) ) ;
F_7 ( V_98 , V_8 -> V_19 + F_9 ( V_102 ) ) ;
V_8 -> V_103 [ V_102 ] &= V_28 ;
V_8 -> V_103 [ V_102 ] /= V_100 ;
V_102 ++ ;
}
if ( V_88 -> V_104 ) {
T_5 * V_105 = ( T_5 * ) ( ( V_106 * ) V_8 -> V_103 +
F_54 ( V_102 , sizeof( T_5 ) ) ) ;
* V_105 = V_96 -> V_105 ;
}
F_55 ( V_88 , ( V_106 * ) V_8 -> V_103 ) ;
F_56 ( V_88 -> V_92 ) ;
return V_93 ;
}
static int F_57 ( struct V_107 * V_92 , bool V_108 )
{
struct V_1 * V_88 = V_92 -> V_109 ;
struct V_7 * V_8 = F_2 ( V_88 ) ;
const T_1 V_110 = V_108 ? V_24 : V_21 ;
F_7 ( V_111 , V_8 -> V_19 + F_58 ( 0 ) + V_110 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_88 )
{
int V_9 ;
struct V_107 * V_92 ;
V_92 = F_60 ( L_2 , V_88 -> V_74 , V_88 -> V_76 ) ;
if ( V_92 == NULL )
return - V_73 ;
V_92 -> V_69 . V_79 = V_88 -> V_69 . V_79 ;
V_92 -> V_109 = V_88 ;
V_92 -> V_112 = & V_113 ;
V_9 = F_61 ( V_92 ) ;
if ( V_9 ) {
F_62 ( V_92 ) ;
return V_9 ;
}
V_88 -> V_92 = V_92 ;
return 0 ;
}
static void F_63 ( struct V_1 * V_88 )
{
F_64 ( V_88 -> V_92 ) ;
F_62 ( V_88 -> V_92 ) ;
}
static int F_65 ( struct V_1 * V_88 )
{
struct V_7 * V_8 = F_2 ( V_88 ) ;
struct V_114 * V_103 = V_88 -> V_103 ;
int V_9 = 0 , V_3 , V_115 = 0 ;
unsigned long V_116 = 0 ;
T_1 V_117 = 0 ;
T_1 V_118 = 0 ;
T_1 V_119 = 0 ;
const T_1 V_98 = V_99 |
( ( V_100 - 1 ) << V_101 ) ;
const int V_120 = F_66 ( V_103 -> V_121 , V_14 ) ;
if ( ! V_120 )
return - V_12 ;
V_9 = F_5 ( & V_8 -> V_15 ) ;
if ( ! V_9 )
return - V_16 ;
V_8 -> V_103 = F_67 ( V_120 * sizeof( * V_8 -> V_103 ) , V_122 ) ;
if ( ! V_8 -> V_103 ) {
V_9 = - V_73 ;
goto V_123;
}
V_9 = F_68 ( V_88 ) ;
if ( V_9 < 0 )
goto V_124;
F_7 ( V_18 ,
V_8 -> V_19 + V_20 + V_21 ) ;
F_7 ( 0xff , V_8 -> V_19 + V_22 + V_21 ) ;
F_53 (chan, buffer->scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_117 |= V_3 << F_17 ( V_115 ) ;
V_118 |= F_8 ( V_115 ) ;
V_119 |= F_10 ( V_115 ) ;
F_7 ( V_98 , V_8 -> V_19 + F_9 ( V_115 ) ) ;
F_3 ( & V_116 , V_115 , 1 ) ;
V_115 ++ ;
}
F_7 ( V_125 | V_111 ,
V_8 -> V_19 + F_58 ( 0 ) + V_21 ) ;
F_7 ( V_118 , V_8 -> V_19 + V_23 + V_21 ) ;
F_7 ( V_117 , V_8 -> V_19 + V_23 + V_24 ) ;
F_7 ( V_119 , V_8 -> V_19 + V_20 + V_24 ) ;
F_7 ( V_116 << V_126 ,
V_8 -> V_19 + F_58 ( 0 ) + V_24 ) ;
return 0 ;
V_124:
F_69 ( V_8 -> V_103 ) ;
V_123:
F_13 ( & V_8 -> V_15 ) ;
return V_9 ;
}
static int F_70 ( struct V_1 * V_88 )
{
struct V_7 * V_8 = F_2 ( V_88 ) ;
F_7 ( V_125 | V_111 ,
V_8 -> V_19 + F_58 ( 0 ) + V_21 ) ;
F_7 ( 0xff , V_8 -> V_19 + V_22 + V_21 ) ;
F_7 ( V_18 ,
V_8 -> V_19 + V_20 + V_21 ) ;
F_69 ( V_8 -> V_103 ) ;
F_13 ( & V_8 -> V_15 ) ;
return 0 ;
}
static bool F_71 ( struct V_1 * V_88 ,
const unsigned long * V_10 )
{
struct V_7 * V_8 = F_2 ( V_88 ) ;
const int V_120 = V_88 -> V_127 ;
const int V_128 = F_66 ( V_10 , V_120 ) ;
int V_129 = 0 ;
unsigned long V_130 = 0 ;
if ( V_8 -> V_131 )
V_130 |= V_132 ;
if ( V_8 -> V_72 == V_133 )
V_130 |= V_134 ;
if ( V_8 -> V_72 == V_135 )
V_130 |= V_136 ;
if ( V_8 -> V_131 )
V_129 ++ ;
if ( V_8 -> V_72 )
V_129 ++ ;
if ( F_72 ( V_10 , & V_130 , V_120 ) )
return false ;
if ( V_128 + V_129 > V_137 )
return false ;
return true ;
}
static void F_73 ( struct V_7 * V_8 )
{
const T_1 V_138 =
( 1 << ( V_139 + 0 ) ) |
( V_140 << V_141 ) ;
F_74 ( V_8 -> V_19 ) ;
F_7 ( V_138 , V_8 -> V_19 + F_58 ( 0 ) ) ;
F_7 ( 0 , V_8 -> V_19 + F_58 ( 1 ) ) ;
F_7 ( 0 , V_8 -> V_19 + F_58 ( 2 ) ) ;
F_7 ( 0 , V_8 -> V_19 + F_58 ( 3 ) ) ;
F_7 ( V_142 ,
V_8 -> V_19 + V_22 + V_21 ) ;
if ( V_8 -> V_72 == V_135 ) {
F_7 ( V_142 ,
V_8 -> V_19 + V_22 + V_24 ) ;
}
F_7 ( 0 , V_8 -> V_19 + V_143 ) ;
}
static void F_75 ( struct V_7 * V_8 )
{
int V_52 ;
F_7 ( V_18 ,
V_8 -> V_19 + V_20 + V_21 ) ;
for ( V_52 = 0 ; V_52 < V_144 ; V_52 ++ )
F_7 ( 0 , V_8 -> V_19 + F_58 ( V_52 ) ) ;
}
static int F_76 ( struct V_145 * V_146 )
{
const struct V_147 * V_148 =
F_77 ( V_149 , & V_146 -> V_69 ) ;
const struct V_150 * V_151 =
& V_150 [ ( enum V_152 ) V_148 -> V_87 ];
struct V_71 * V_69 = & V_146 -> V_69 ;
struct V_153 * V_154 = V_69 -> V_155 ;
struct V_7 * V_8 ;
struct V_1 * V_88 ;
struct V_156 * V_157 ;
T_1 V_158 = 0 ;
int V_9 = 0 ;
int V_52 ;
V_88 = F_78 ( sizeof( * V_8 ) ) ;
if ( ! V_88 ) {
F_38 ( V_69 , L_3 ) ;
return - V_73 ;
}
V_8 = F_2 ( V_88 ) ;
V_157 = F_79 ( V_146 , V_159 , 0 ) ;
V_8 -> V_69 = & V_146 -> V_69 ;
V_8 -> V_19 = F_80 ( V_69 , V_157 ) ;
if ( F_81 ( V_8 -> V_19 ) ) {
V_9 = F_82 ( V_8 -> V_19 ) ;
goto V_160;
}
F_83 ( & V_8 -> V_55 , F_25 ) ;
V_9 = F_84 ( V_154 , L_4 ,
& V_158 ) ;
if ( V_9 )
F_85 ( V_69 , L_5 ) ;
else if ( V_158 == 4 )
V_8 -> V_72 = V_133 ;
else if ( V_158 == 5 )
V_8 -> V_72 = V_135 ;
else
F_86 ( V_69 , L_6 ,
V_158 ) ;
for ( V_52 = 0 ; V_52 < V_151 -> V_161 ; V_52 ++ ) {
V_8 -> V_86 [ V_52 ] = F_87 ( V_146 , V_52 ) ;
if ( V_8 -> V_86 [ V_52 ] < 0 ) {
V_9 = - V_12 ;
goto V_160;
}
V_9 = F_88 ( V_69 , V_8 -> V_86 [ V_52 ] ,
F_46 , 0 ,
V_151 -> V_162 [ V_52 ] , V_88 ) ;
if ( V_9 )
goto V_160;
}
F_89 ( V_146 , V_88 ) ;
F_90 ( & V_8 -> V_17 ) ;
F_91 ( & V_8 -> V_15 ) ;
V_88 -> V_74 = V_146 -> V_74 ;
V_88 -> V_69 . V_79 = & V_146 -> V_69 ;
V_88 -> V_163 = & V_164 ;
V_88 -> V_165 = V_166 ;
V_88 -> V_167 = V_168 ;
V_88 -> V_169 = F_92 ( V_168 ) ;
V_9 = F_93 ( V_88 , & V_170 ,
& F_52 ,
& V_171 ) ;
if ( V_9 )
goto V_160;
V_9 = F_59 ( V_88 ) ;
if ( V_9 )
goto V_172;
V_9 = F_36 ( V_8 ) ;
if ( V_9 )
goto V_173;
V_9 = F_94 ( V_88 ) ;
if ( V_9 ) {
F_38 ( V_69 , L_7 ) ;
goto V_174;
}
F_73 ( V_8 ) ;
return 0 ;
V_174:
F_44 ( V_8 ) ;
V_173:
F_63 ( V_88 ) ;
V_172:
F_95 ( V_88 ) ;
V_160:
F_96 ( V_88 ) ;
return V_9 ;
}
static int F_97 ( struct V_145 * V_146 )
{
struct V_1 * V_88 = F_98 ( V_146 ) ;
struct V_7 * V_8 = F_2 ( V_88 ) ;
F_44 ( V_8 ) ;
F_75 ( V_8 ) ;
F_99 ( V_88 ) ;
F_95 ( V_88 ) ;
F_63 ( V_88 ) ;
F_96 ( V_88 ) ;
return 0 ;
}
