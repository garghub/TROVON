static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_5 -> V_7 [ 0 ] = V_8 ;
V_5 -> V_7 [ 1 ] = 1 ;
V_5 -> V_7 [ 2 ] = 0xFF ;
V_5 -> V_7 [ 4 ] = V_3 ;
V_6 = F_3 ( V_2 , V_5 -> V_7 ,
V_5 -> V_9 ) ;
if ( V_6 != V_5 -> V_9 ) {
F_4 ( & V_2 -> V_10 ,
L_1 , V_11 , V_6 ) ;
return V_6 ;
}
V_5 -> V_3 = V_3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_12 )
{
int V_13 ;
const T_1 V_14 [ 2 ] = { V_15 , V_12 } ;
T_1 * V_16 ;
V_16 = F_6 ( V_14 , sizeof( V_14 ) , V_17 ) ;
if ( ! V_16 )
return - V_18 ;
V_13 = F_7 ( V_2 , V_15 , V_16 ,
sizeof( V_14 ) , V_19 , V_20 ) ;
F_8 ( V_16 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_2 , V_12 ,
V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_21 , int V_22 )
{
int V_13 ;
V_13 = F_9 ( V_2 , ( void * ) V_21 , V_22 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_3 , V_13 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_23 , void * V_16 ,
const int V_22 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
int V_24 ;
int V_25 ;
int V_26 ;
int V_27 ;
F_11 ( & V_5 -> V_28 ) ;
if ( F_12 ( V_23 ) != V_5 -> V_3 ) {
V_13 = F_1 ( V_2 , F_12 ( V_23 ) ) ;
if ( V_13 < 0 )
goto exit;
}
for ( V_26 = 5 ; V_26 > 0 ; V_26 -- ) {
V_5 -> V_7 [ 0 ] = V_29 ;
V_5 -> V_7 [ 1 ] = 0 ;
V_5 -> V_7 [ 2 ] = V_23 & 0xFF ;
V_5 -> V_7 [ 3 ] = ( V_23 >> 8 ) & 0xFF ;
V_5 -> V_7 [ 4 ] = V_22 & 0xFF ;
V_5 -> V_7 [ 5 ] = ( V_22 >> 8 ) & 0xFF ;
F_13 ( V_30 , & V_5 -> V_31 ) ;
V_13 = F_3 ( V_2 , V_5 -> V_7 ,
V_5 -> V_9 ) ;
if ( V_13 != V_5 -> V_9 ) {
F_14 ( V_30 , & V_5 -> V_31 ) ;
F_4 ( & V_2 -> V_10 ,
L_4 ,
V_13 ) ;
goto exit;
}
V_24 = 0 ;
V_25 = V_22 ;
while ( V_24 < V_22 ) {
if ( ! F_15 ( V_5 -> V_32 ,
F_16 ( V_33 , & V_5 -> V_31 ) ,
F_17 ( 1000 ) ) ) {
F_18 ( V_2 , L_5 ,
V_11 ) ;
V_13 = - V_34 ;
break;
}
V_27 = V_5 -> V_35 [ 1 ] ;
memcpy ( V_16 + V_24 , & V_5 -> V_35 [ 2 ] ,
V_27 < V_25 ?
V_27 : V_25 ) ;
V_24 += V_27 ;
V_25 -= V_27 ;
F_14 ( V_33 , & V_5 -> V_31 ) ;
}
if ( V_13 >= 0 ) {
V_13 = 0 ;
break;
}
}
exit:
F_14 ( V_30 , & V_5 -> V_31 ) ;
F_19 ( & V_5 -> V_28 ) ;
return V_13 ;
}
static inline int F_20 ( struct V_1 * V_2 , T_2 V_23 , void * V_16 )
{
return F_10 ( V_2 , V_23 , V_16 , 1 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_23 , void * V_16 ,
const int V_22 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
F_11 ( & V_5 -> V_28 ) ;
if ( F_12 ( V_23 ) != V_5 -> V_3 ) {
V_13 = F_1 ( V_2 , F_12 ( V_23 ) ) ;
if ( V_13 < 0 )
goto exit;
}
V_5 -> V_7 [ 0 ] = V_8 ;
V_5 -> V_7 [ 1 ] = V_22 ;
V_5 -> V_7 [ 2 ] = V_23 & 0xFF ;
V_5 -> V_7 [ 3 ] = ( V_23 >> 8 ) & 0xFF ;
memcpy ( & V_5 -> V_7 [ 4 ] , V_16 , V_22 ) ;
V_13 = F_3 ( V_2 , V_5 -> V_7 ,
V_5 -> V_9 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 ,
L_4 ,
V_13 ) ;
goto exit;
}
V_13 = 0 ;
exit:
F_19 ( & V_5 -> V_28 ) ;
return V_13 ;
}
static inline int F_22 ( struct V_1 * V_2 , T_2 V_23 , void * V_16 )
{
return F_21 ( V_2 , V_23 , V_16 , 1 ) ;
}
static void F_23 ( struct V_4 * V_36 , int V_37 ,
T_1 V_38 , T_1 * V_39 )
{
int V_40 , V_41 , V_42 , V_43 ;
int V_44 , V_45 , V_46 ;
int V_47 ;
F_24 ( V_36 -> V_48 , V_37 ) ;
F_25 ( V_36 -> V_48 , V_49 ,
V_38 == 0x01 ) ;
if ( V_38 == 0x01 ) {
V_40 = ( V_39 [ 0 ] << 4 ) | ( V_39 [ 2 ] & 0x0F ) ;
V_41 = ( V_39 [ 1 ] << 4 ) | ( V_39 [ 2 ] >> 4 ) ;
V_42 = V_39 [ 3 ] & 0x0F ;
V_43 = V_39 [ 3 ] >> 4 ;
V_44 = ( V_42 > V_43 ) ;
V_45 = F_26 ( V_42 , V_43 ) ;
V_46 = F_27 ( V_42 , V_43 ) ;
V_47 = V_39 [ 4 ] ;
V_41 = V_36 -> V_50 - V_41 ;
F_28 ( V_36 -> V_48 , V_51 , V_52 , V_40 ) ;
F_28 ( V_36 -> V_48 , V_51 , V_53 , V_41 ) ;
F_28 ( V_36 -> V_48 , V_51 , V_54 , V_44 ) ;
F_28 ( V_36 -> V_48 , V_51 , V_55 , V_47 ) ;
F_28 ( V_36 -> V_48 , V_51 , V_56 , V_45 ) ;
F_28 ( V_36 -> V_48 , V_51 , V_57 , V_46 ) ;
}
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
V_13 = F_5 ( V_2 , V_58 ) ;
if ( V_13 )
return V_13 ;
if ( V_5 -> V_59 ) {
V_13 = F_22 ( V_2 , V_5 -> V_60 . V_61 + 1 ,
& V_5 -> V_62 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_6 ) ;
return V_13 ;
}
}
return 0 ;
}
static void F_31 ( struct V_63 * V_64 )
{
struct V_4 * V_36 = F_32 ( V_64 , struct V_4 ,
V_65 ) ;
F_29 ( V_36 -> V_2 ) ;
}
static inline int F_33 ( struct V_1 * V_2 )
{
struct V_4 * V_36 = F_2 ( V_2 ) ;
return F_34 ( & V_36 -> V_65 ) ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_66 , T_1 * V_5 ,
int V_67 )
{
struct V_4 * V_36 = F_2 ( V_2 ) ;
int V_68 ;
int V_69 ;
if ( ! ( V_66 & V_36 -> V_70 . V_71 ) || V_67 <= 0 )
return 0 ;
V_68 = ( V_36 -> V_72 >> 2 ) + 1 ;
for ( V_69 = 0 ; V_69 < V_36 -> V_72 ; V_69 ++ ) {
int V_73 = V_69 >> 2 ;
int V_74 = ( V_69 & 0x3 ) << 1 ;
int V_38 = ( V_5 [ V_73 ] >> V_74 ) &
0x03 ;
int V_75 = V_68 + 5 * V_69 ;
if ( V_75 + 5 > V_67 ) {
F_36 ( V_76
L_7 ,
F_37 ( & V_2 -> V_10 ) ,
F_38 ( & V_2 -> V_10 ) ) ;
F_39 ( V_2 , L_8 ) ;
break;
}
F_23 ( V_36 , V_69 , V_38 , & V_5 [ V_75 ] ) ;
}
F_40 ( V_36 -> V_48 ) ;
F_41 ( V_36 -> V_48 ) ;
return V_36 -> V_70 . V_77 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_66 , T_1 * V_5 ,
int V_67 )
{
struct V_4 * V_36 = F_2 ( V_2 ) ;
int V_69 ;
int V_78 = 0 ;
bool V_79 ;
if ( ! ( V_66 & V_36 -> V_80 . V_71 ) )
return 0 ;
if ( V_67 < ( int ) V_36 -> V_80 . V_77 ) {
F_18 ( V_2 , L_9 ) ;
return 0 ;
}
for ( V_69 = 0 ; V_69 < V_36 -> V_81 ; V_69 ++ ) {
if ( F_16 ( V_69 , & V_36 -> V_82 ) ) {
V_79 = ( V_5 [ V_69 / 8 ] >> ( V_69 & 0x07 ) ) & F_43 ( 0 ) ;
if ( F_16 ( V_69 , & V_36 -> V_83 ) )
V_79 = ! V_79 ;
F_28 ( V_36 -> V_48 , V_84 , V_85 + V_78 ++ ,
V_79 ) ;
}
}
return V_36 -> V_80 . V_77 ;
}
static int F_44 ( struct V_1 * V_2 , T_1 * V_5 , int V_67 )
{
struct V_4 * V_36 = F_2 ( V_2 ) ;
unsigned long V_71 = 0 ;
unsigned V_86 = 2 ;
if ( ! ( F_16 ( V_87 , & V_36 -> V_31 ) ) )
return 0 ;
V_71 |= V_36 -> V_70 . V_71 ;
V_71 |= V_36 -> V_80 . V_71 ;
if ( V_5 [ 1 ] & ~ V_71 )
F_39 ( V_2 , L_10 ,
V_5 [ 1 ] & ~ V_71 , __FILE__ , __LINE__ ) ;
if ( V_36 -> V_70 . V_88 < V_36 -> V_80 . V_88 ) {
V_86 += F_35 ( V_2 , V_5 [ 1 ] , & V_5 [ V_86 ] ,
V_67 - V_86 ) ;
V_86 += F_42 ( V_2 , V_5 [ 1 ] , & V_5 [ V_86 ] ,
V_67 - V_86 ) ;
} else {
V_86 += F_42 ( V_2 , V_5 [ 1 ] , & V_5 [ V_86 ] ,
V_67 - V_86 ) ;
V_86 += F_35 ( V_2 , V_5 [ 1 ] , & V_5 [ V_86 ] ,
V_67 - V_86 ) ;
}
return 1 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 * V_5 , int V_67 )
{
struct V_4 * V_36 = F_2 ( V_2 ) ;
if ( ! F_16 ( V_30 , & V_36 -> V_31 ) ) {
F_39 ( V_2 , L_11 ) ;
return 0 ;
}
memcpy ( V_36 -> V_35 , V_5 , V_67 < V_36 -> V_89 ?
V_67 : V_36 -> V_89 ) ;
F_13 ( V_33 , & V_36 -> V_31 ) ;
F_46 ( & V_36 -> V_32 ) ;
return 1 ;
}
static int F_47 ( struct V_1 * V_2 , T_1 * V_5 , int V_67 )
{
int V_90 = V_67 ;
while ( ( V_5 [ V_90 - 1 ] == 0xff ) && V_90 > 0 )
V_90 -- ;
return V_90 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_91 * V_21 , T_1 * V_5 , int V_67 )
{
V_67 = F_47 ( V_2 , V_5 , V_67 ) ;
if ( V_67 < 2 )
return 0 ;
switch ( V_5 [ 0 ] ) {
case V_92 :
return F_45 ( V_2 , V_5 , V_67 ) ;
case V_93 :
return F_44 ( V_2 , V_5 , V_67 ) ;
default:
return 1 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_94 * V_95 ,
struct V_96 * V_97 , T_3 V_79 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ( V_5 -> V_98 & V_99 ) &&
( V_95 -> V_100 == V_101 ||
V_95 -> V_100 == V_102 ) ) {
if ( V_5 -> V_98 & V_103 ) {
if ( ( V_97 -> V_104 & V_105 ) == V_106 )
return 0 ;
if ( ( V_97 -> V_104 == V_107 || V_97 -> V_104 == V_108 )
&& ! V_79 )
return 1 ;
}
F_33 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , int V_109 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
T_1 V_110 ;
V_110 = ( V_5 -> V_110 & ~ 0x3 ) | V_109 ;
V_13 = F_22 ( V_2 , V_5 -> V_60 . V_61 ,
& V_110 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_12 ) ;
return V_13 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , T_4 V_111 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
T_1 V_16 [ V_112 ] ;
if ( ! ( V_5 -> V_98 & V_99 ) )
return 0 ;
V_13 = F_10 ( V_2 , V_5 -> V_70 . V_61 , V_16 ,
V_112 ) ;
if ( V_13 )
F_18 ( V_2 , L_13 ) ;
else
memcpy ( V_5 -> V_113 , V_16 , V_112 ) ;
if ( ! F_52 ( V_2 -> V_10 . V_114 ) )
return F_50 ( V_2 , V_115 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
if ( ! ( V_5 -> V_98 & V_99 ) )
return 0 ;
V_13 = F_29 ( V_2 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_14 ) ;
return V_13 ;
}
if ( V_5 -> V_116 ) {
V_13 = F_21 ( V_2 , V_5 -> V_70 . V_61 ,
V_5 -> V_113 , V_112 ) ;
if ( V_13 )
F_18 ( V_2 ,
L_15 ) ;
}
if ( ! F_52 ( V_2 -> V_10 . V_114 ) ) {
V_13 = F_50 ( V_2 , V_117 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_12 ) ;
return V_13 ;
}
}
return V_13 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! ( V_5 -> V_98 & V_99 ) )
return 0 ;
return F_29 ( V_2 ) ;
}
static inline unsigned long F_55 ( unsigned V_118 , unsigned V_119 )
{
return F_56 ( V_119 + V_118 - 1 , V_118 ) ;
}
static void F_57 ( struct V_4 * V_5 ,
struct V_120 * V_120 , int V_3 , unsigned V_121 )
{
struct V_122 * V_123 = NULL ;
T_2 V_124 = V_3 << 8 ;
switch ( V_120 -> V_125 ) {
case 0x01 :
V_123 = & V_5 -> V_60 ;
break;
case 0x11 :
V_123 = & V_5 -> V_70 ;
break;
case 0x30 :
V_123 = & V_5 -> V_80 ;
break;
}
if ( V_123 ) {
V_123 -> V_3 = V_3 ;
V_123 -> V_126 = V_124 | V_120 -> V_126 ;
V_123 -> V_127 = V_124 | V_120 -> V_127 ;
V_123 -> V_61 = V_124 | V_120 -> V_61 ;
V_123 -> V_128 = V_124 | V_120 -> V_128 ;
V_123 -> V_88 = V_121 ;
V_123 -> V_121 = V_120 -> V_129 ;
V_123 -> V_71 = F_55 ( V_123 -> V_88 ,
V_123 -> V_121 ) ;
V_5 -> V_62 |= V_123 -> V_71 ;
}
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_120 V_130 ;
int V_3 ;
bool V_131 ;
int V_69 ;
int V_6 ;
int V_132 = 0 ;
T_2 V_133 , V_134 , V_135 ;
F_59 ( V_2 , L_16 ) ;
for ( V_3 = 0 ; ( V_3 <= V_136 ) ; V_3 ++ ) {
V_133 = V_137 * V_3 ;
V_134 = V_133 + V_138 ;
V_135 = V_133 + V_139 ;
V_131 = false ;
for ( V_69 = V_134 ; V_69 >= V_135 ; V_69 -= sizeof( V_130 ) ) {
V_6 = F_10 ( V_2 , V_69 , & V_130 , sizeof( V_130 ) ) ;
if ( V_6 ) {
F_30 ( V_2 ,
L_17 ,
V_69 ) ;
goto V_140;
}
if ( F_60 ( V_130 . V_125 ) )
break;
V_131 = true ;
F_59 ( V_2 , L_18 ,
V_130 . V_125 , V_3 ) ;
F_57 ( V_5 , & V_130 , V_3 , V_132 ) ;
V_132 += V_130 . V_129 ;
}
if ( ! V_131 )
break;
}
F_59 ( V_2 , L_19 , V_11 ) ;
V_6 = 0 ;
V_140:
return V_6 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_141 [ V_142 ] ;
T_1 V_143 [ 3 ] ;
int V_13 ;
bool V_144 ;
bool V_145 ;
bool V_146 ;
bool V_147 = false ;
bool V_148 = false ;
bool V_149 = false ;
T_2 V_150 = V_5 -> V_60 . V_126 ;
T_2 V_151 ;
T_1 V_152 ;
V_13 = F_10 ( V_2 , V_150 , V_141 ,
V_142 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_20 ) ;
return V_13 ;
}
V_145 = ! ! ( V_141 [ 0 ] & F_43 ( 2 ) ) ;
V_146 = ! ! ( V_141 [ 1 ] & F_43 ( 3 ) ) ;
V_144 = ! ! ( V_141 [ 1 ] & F_43 ( 7 ) ) ;
V_150 += 11 ;
V_151 = V_150 + 6 ;
V_150 += 10 ;
if ( V_145 )
V_150 += 20 ;
if ( V_146 )
V_150 ++ ;
if ( V_144 ) {
V_13 = F_20 ( V_2 , V_150 , V_143 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_21 ) ;
return V_13 ;
}
V_147 = ! ! ( V_143 [ 0 ] & F_43 ( 0 ) ) ;
V_150 ++ ;
}
if ( V_147 ) {
V_13 = F_20 ( V_2 , V_150 , & V_152 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_22 ) ;
return V_13 ;
}
V_150 ++ ;
if ( V_152 > 0 ) {
V_13 = F_20 ( V_2 , V_150 , V_143 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_23 ) ;
return V_13 ;
}
V_149 = ! ! ( V_143 [ 0 ] & F_43 ( 0 ) ) ;
V_148 = ! ! ( V_143 [ 0 ] & F_43 ( 1 ) ) ;
}
}
if ( V_149 )
V_151 ++ ;
if ( V_148 ) {
V_13 = F_10 ( V_2 , V_151 , V_143 , 3 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_24 ) ;
return V_13 ;
}
V_5 -> V_153 = V_143 [ 1 ] << 8 | V_143 [ 0 ] ;
V_5 -> V_153 += V_143 [ 2 ] * 65536 ;
}
V_13 = F_10 ( V_2 , V_5 -> V_60 . V_61 , V_143 ,
2 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_25 ) ;
return V_13 ;
}
V_5 -> V_110 = V_143 [ 0 ] ;
if ( ! V_143 [ 1 ] ) {
V_5 -> V_59 = true ;
V_13 = F_22 ( V_2 , V_5 -> V_60 . V_61 + 1 ,
& V_5 -> V_62 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_26 ,
V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_16 [ 20 ] ;
int V_13 ;
bool V_154 ;
bool V_155 = false ;
bool V_156 ;
bool V_157 ;
bool V_158 ;
bool V_159 ;
bool V_160 = false ;
bool V_161 ;
bool V_162 ;
bool V_163 ;
bool V_164 = false ;
bool V_165 = false ;
bool V_166 = false ;
unsigned V_167 , V_168 ;
T_2 V_150 ;
if ( ! V_5 -> V_70 . V_126 ) {
F_30 ( V_2 , L_27 ) ;
return - V_169 ;
}
V_13 = F_20 ( V_2 , V_5 -> V_70 . V_126 , V_16 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_28 , V_13 ) ;
return V_13 ;
}
V_154 = ! ! ( V_16 [ 0 ] & F_43 ( 3 ) ) ;
V_156 = ! ! ( V_16 [ 0 ] & F_43 ( 4 ) ) ;
V_157 = ! ! ( V_16 [ 0 ] & F_43 ( 5 ) ) ;
V_158 = ! ! ( V_16 [ 0 ] & F_43 ( 6 ) ) ;
V_159 = ! ! ( V_16 [ 0 ] & F_43 ( 7 ) ) ;
V_13 = F_20 ( V_2 , V_5 -> V_70 . V_126 + 1 , V_16 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_29 , V_13 ) ;
return V_13 ;
}
V_5 -> V_72 = ( V_16 [ 0 ] & 0x07 ) + 1 ;
if ( V_5 -> V_72 > 5 )
V_5 -> V_72 = 10 ;
V_5 -> V_70 . V_77 = V_5 -> V_72 * 5 +
F_63 ( V_5 -> V_72 , 4 ) ;
if ( ! ( V_16 [ 0 ] & F_43 ( 4 ) ) ) {
F_30 ( V_2 , L_30 ) ;
return - V_169 ;
}
V_163 = ! ! ( V_16 [ 0 ] & F_43 ( 3 ) ) ;
V_162 = ! ! ( V_16 [ 0 ] & F_43 ( 5 ) ) ;
V_13 = F_20 ( V_2 , V_5 -> V_70 . V_126 + 5 , V_16 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_31 , V_13 ) ;
return V_13 ;
}
V_165 = ! ! ( V_16 [ 0 ] & F_43 ( 4 ) ) ;
V_150 = 6 ;
if ( V_163 )
++ V_150 ;
if ( V_162 ) {
V_13 = F_20 ( V_2 ,
V_5 -> V_70 . V_126 + V_150 + 1 , V_16 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_32 ,
V_13 ) ;
return V_13 ;
}
V_166 = ! ! ( V_16 [ 0 ] & F_43 ( 0 ) ) ;
V_155 = ! ! ( V_16 [ 0 ] & F_43 ( 2 ) ) ;
V_150 += 2 ;
}
if ( V_154 )
++ V_150 ;
if ( V_155 )
++ V_150 ;
if ( V_156 )
++ V_150 ;
if ( V_157 ) {
V_13 = F_20 ( V_2 , V_5 -> V_70 . V_126
+ V_150 , V_16 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_33 , V_13 ) ;
return V_13 ;
}
V_161 = ! ! ( V_16 [ 0 ] & F_43 ( 5 ) ) ;
if ( V_161 ) {
V_150 += 1 ;
V_13 = F_10 ( V_2 ,
V_5 -> V_70 . V_126
+ V_150 , V_16 , 4 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_34 ,
V_13 ) ;
return V_13 ;
}
V_167 = V_16 [ 0 ] | ( V_16 [ 1 ] << 8 ) ;
V_168 = V_16 [ 2 ] | ( V_16 [ 3 ] << 8 ) ;
V_5 -> V_170 = F_64 ( V_167 , 10 ) ;
V_5 -> V_171 = F_64 ( V_168 , 10 ) ;
F_59 ( V_2 , L_35 ,
V_11 , V_5 -> V_170 , V_5 -> V_171 ) ;
V_150 += 12 ;
}
}
if ( V_158 )
++ V_150 ;
if ( V_159 ) {
V_13 = F_20 ( V_2 , V_5 -> V_70 . V_126
+ V_150 , V_16 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_36 , V_13 ) ;
return V_13 ;
}
V_160 = ! ! ( V_16 [ 0 ] & F_43 ( 6 ) ) ;
}
if ( V_160 ) {
V_150 += 2 ;
V_13 = F_20 ( V_2 , V_5 -> V_70 . V_126
+ V_150 , V_16 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_37 , V_13 ) ;
return V_13 ;
}
V_164 = ! ! ( V_16 [ 0 ] & F_43 ( 5 ) ) ;
}
if ( V_164 )
V_5 -> V_70 . V_77 += V_5 -> V_72 * 2 ;
V_13 = F_10 ( V_2 , V_5 -> V_70 . V_61 ,
V_5 -> V_113 , V_112 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_38 , V_13 ) ;
return V_13 ;
}
V_5 -> V_116 = true ;
V_5 -> V_172 = V_5 -> V_113 [ 6 ] | ( V_5 -> V_113 [ 7 ] << 8 ) ;
V_5 -> V_50 = V_5 -> V_113 [ 8 ] | ( V_5 -> V_113 [ 9 ] << 8 ) ;
if ( V_165 ) {
V_5 -> V_113 [ 0 ] = V_5 -> V_113 [ 0 ] & ~ F_43 ( 6 ) ;
V_13 = F_22 ( V_2 , V_5 -> V_70 . V_61 ,
V_5 -> V_113 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_39 ,
V_13 ) ;
return V_13 ;
}
}
if ( V_166 ) {
V_5 -> V_113 [ 11 ] = V_5 -> V_113 [ 11 ] & ~ F_43 ( 0 ) ;
V_13 = F_22 ( V_2 , V_5 -> V_70 . V_61 + 11 ,
& V_5 -> V_113 [ 11 ] ) ;
if ( V_13 ) {
F_30 ( V_2 , L_40 ,
V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_16 [ 20 ] ;
int V_13 ;
bool V_173 , V_174 ;
unsigned V_175 ;
T_1 V_176 ;
int V_177 ;
int V_69 ;
if ( ! V_5 -> V_80 . V_126 ) {
F_30 ( V_2 , L_41 ) ;
return - V_169 ;
}
V_13 = F_10 ( V_2 , V_5 -> V_80 . V_126 , V_16 , 2 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_42 , V_13 ) ;
return V_13 ;
}
V_173 = ! ! ( V_16 [ 0 ] & F_43 ( 3 ) ) ;
V_174 = ! ! ( V_16 [ 0 ] & F_43 ( 2 ) ) ;
V_5 -> V_81 = V_16 [ 1 ] & 0x1f ;
V_175 = ( V_5 -> V_81 + 7 ) / 8 ;
V_176 = ( V_173 && V_174 ) ? V_175 : 0 ;
V_176 += V_175 ;
V_177 = 2 * V_175 ;
V_5 -> V_80 . V_77 = V_175 ;
V_13 = F_10 ( V_2 , V_5 -> V_80 . V_61 + V_176 ,
V_16 , V_177 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_43 ,
V_177 , V_13 ) ;
return V_13 ;
}
for ( V_69 = 0 ; V_69 < V_5 -> V_81 ; V_69 ++ ) {
int V_178 = V_69 >> 3 ;
int V_179 = V_69 & 0x07 ;
T_1 V_180 = V_16 [ V_178 ] ;
T_1 V_181 = V_16 [ V_178 + V_175 ] ;
bool V_182 = ( V_180 >> V_179 ) & F_43 ( 0 ) ;
bool V_183 = ( V_181 >> V_179 ) & F_43 ( 0 ) ;
if ( V_182 == 0 ) {
if ( V_183 ) {
V_5 -> V_184 ++ ;
F_13 ( V_69 , & V_5 -> V_82 ) ;
F_13 ( V_69 , & V_5 -> V_83 ) ;
}
}
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
V_13 = F_58 ( V_2 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_44 , V_13 ) ;
return V_13 ;
}
V_13 = F_61 ( V_2 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_45 , V_13 ) ;
return V_13 ;
}
V_13 = F_62 ( V_2 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_46 , V_13 ) ;
return V_13 ;
}
if ( ! ( V_5 -> V_98 & V_103 ) ) {
V_13 = F_65 ( V_2 ) ;
if ( V_13 )
F_18 ( V_2 , L_47 , V_13 ) ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_185 * V_186 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_187 * V_48 = V_186 -> V_48 ;
int V_13 ;
int V_188 , V_189 , V_69 ;
V_5 -> V_48 = V_48 ;
F_39 ( V_2 , L_48 ) ;
V_13 = F_68 ( V_2 ) ;
if ( V_13 )
return V_13 ;
if ( ! ( V_5 -> V_98 & V_99 ) )
return 0 ;
F_69 ( V_2 ) ;
V_13 = F_5 ( V_2 , V_58 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_49 ) ;
goto exit;
}
V_13 = F_1 ( V_2 , 0 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_50 ) ;
goto exit;
}
V_13 = F_66 ( V_2 ) ;
if ( V_13 )
goto exit;
F_59 ( V_2 , L_51 , V_5 -> V_153 ) ;
F_70 ( V_51 , V_48 -> V_190 ) ;
F_71 ( V_48 , V_52 , 1 , V_5 -> V_172 , 0 , 0 ) ;
F_71 ( V_48 , V_53 , 1 , V_5 -> V_50 , 0 , 0 ) ;
if ( V_5 -> V_170 && V_5 -> V_171 ) {
V_188 = ( V_5 -> V_172 - 1 ) / V_5 -> V_170 ;
V_189 = ( V_5 -> V_50 - 1 ) / V_5 -> V_171 ;
F_72 ( V_48 , V_52 , V_188 ) ;
F_72 ( V_48 , V_53 , V_189 ) ;
}
F_71 ( V_48 , V_54 , 0 , 1 , 0 , 0 ) ;
F_71 ( V_48 , V_55 , 0 , 0xff , 0 , 0 ) ;
F_71 ( V_48 , V_56 , 0 , 0x0f , 0 , 0 ) ;
F_71 ( V_48 , V_57 , 0 , 0x0f , 0 , 0 ) ;
V_13 = F_73 ( V_48 , V_5 -> V_72 , V_191 ) ;
if ( V_13 < 0 )
goto exit;
if ( V_5 -> V_184 ) {
F_70 ( V_84 , V_48 -> V_190 ) ;
for ( V_69 = 0 ; V_69 < V_5 -> V_184 ; V_69 ++ )
F_70 ( V_85 + V_69 , V_48 -> V_192 ) ;
if ( V_5 -> V_184 == 1 )
F_70 ( V_193 , V_48 -> V_194 ) ;
}
F_13 ( V_87 , & V_5 -> V_31 ) ;
exit:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
return V_13 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_185 * V_186 , struct V_94 * V_95 ,
struct V_96 * V_97 , unsigned long * * V_195 , int * F_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_98 & V_99 ) {
if ( ( V_5 -> V_98 & V_103 ) &&
( ( V_97 -> V_104 & V_105 ) == V_106 ) )
return 0 ;
return - 1 ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , unsigned type ,
unsigned V_196 , struct V_91 * * V_21 )
{
int V_69 ;
* V_21 = V_2 -> V_197 [ type ] . V_198 [ V_196 ] ;
if ( * V_21 ) {
for ( V_69 = 0 ; V_69 < ( * V_21 ) -> V_199 ; V_69 ++ ) {
unsigned V_200 = ( * V_21 ) -> V_95 [ V_69 ] -> V_100 ;
if ( ( V_200 & V_105 ) >= V_201 )
return 1 ;
}
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , const struct V_202 * V_196 )
{
struct V_4 * V_5 = NULL ;
int V_13 ;
T_5 V_203 ;
struct V_91 * V_204 ;
struct V_91 * V_205 ;
struct V_91 * V_206 ;
V_5 = F_79 ( & V_2 -> V_10 , sizeof( struct V_4 ) , V_17 ) ;
if ( ! V_5 )
return - V_18 ;
F_80 ( & V_5 -> V_65 , F_31 ) ;
V_5 -> V_2 = V_2 ;
F_81 ( V_2 , V_5 ) ;
V_2 -> V_207 |= V_208 ;
V_13 = F_82 ( V_2 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_52 ) ;
return V_13 ;
}
if ( V_196 -> V_209 )
V_5 -> V_98 = V_196 -> V_209 ;
if ( ! F_77 ( V_2 , V_19 ,
V_15 , & V_206 ) ) {
F_39 ( V_2 , L_53 ) ;
goto V_210;
}
if ( ! F_77 ( V_2 , V_211 ,
V_93 , & V_204 ) ) {
F_39 ( V_2 , L_54 ) ;
goto V_210;
}
V_5 -> V_89 = F_83 ( V_204 ) ;
if ( ! F_77 ( V_2 , V_212 ,
V_8 , & V_205 ) ) {
F_39 ( V_2 ,
L_55 ) ;
goto V_210;
}
V_5 -> V_9 = F_83 ( V_205 ) ;
V_5 -> V_98 |= V_99 ;
V_203 = V_5 -> V_9 + V_5 -> V_89 ;
V_5 -> V_7 = F_79 ( & V_2 -> V_10 , V_203 , V_17 ) ;
if ( ! V_5 -> V_7 ) {
V_13 = - V_18 ;
return V_13 ;
}
V_5 -> V_35 = V_5 -> V_7 + V_5 -> V_9 ;
F_84 ( & V_5 -> V_32 ) ;
F_85 ( & V_5 -> V_28 ) ;
V_210:
V_13 = F_86 ( V_2 , V_213 ) ;
if ( V_13 ) {
F_30 ( V_2 , L_56 ) ;
return V_13 ;
}
if ( ( V_5 -> V_98 & V_99 ) &&
! F_16 ( V_87 , & V_5 -> V_31 ) )
F_30 ( V_2 , L_57 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_4 * V_36 = F_2 ( V_2 ) ;
F_14 ( V_87 , & V_36 -> V_31 ) ;
F_88 ( V_2 ) ;
}
