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
T_1 V_14 [ 2 ] = { V_15 , V_12 } ;
V_13 = F_6 ( V_2 , V_15 , V_14 ,
sizeof( V_14 ) , V_16 , V_17 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_2 , V_12 ,
V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_18 , int V_19 )
{
int V_13 ;
V_13 = F_7 ( V_2 , ( void * ) V_18 , V_19 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_3 , V_13 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_20 , void * V_21 ,
const int V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
int V_22 ;
int V_23 ;
int V_24 ;
int V_25 ;
F_9 ( & V_5 -> V_26 ) ;
if ( F_10 ( V_20 ) != V_5 -> V_3 ) {
V_13 = F_1 ( V_2 , F_10 ( V_20 ) ) ;
if ( V_13 < 0 )
goto exit;
}
for ( V_24 = 5 ; V_24 > 0 ; V_24 -- ) {
V_5 -> V_7 [ 0 ] = V_27 ;
V_5 -> V_7 [ 1 ] = 0 ;
V_5 -> V_7 [ 2 ] = V_20 & 0xFF ;
V_5 -> V_7 [ 3 ] = ( V_20 >> 8 ) & 0xFF ;
V_5 -> V_7 [ 4 ] = V_19 & 0xFF ;
V_5 -> V_7 [ 5 ] = ( V_19 >> 8 ) & 0xFF ;
F_11 ( V_28 , & V_5 -> V_29 ) ;
V_13 = F_3 ( V_2 , V_5 -> V_7 ,
V_5 -> V_9 ) ;
if ( V_13 != V_5 -> V_9 ) {
F_12 ( V_28 , & V_5 -> V_29 ) ;
F_4 ( & V_2 -> V_10 ,
L_4 ,
V_13 ) ;
goto exit;
}
V_22 = 0 ;
V_23 = V_19 ;
while ( V_22 < V_19 ) {
if ( ! F_13 ( V_5 -> V_30 ,
F_14 ( V_31 , & V_5 -> V_29 ) ,
F_15 ( 1000 ) ) ) {
F_16 ( V_2 , L_5 ,
V_11 ) ;
V_13 = - V_32 ;
break;
}
V_25 = V_5 -> V_33 [ 1 ] ;
memcpy ( V_21 + V_22 , & V_5 -> V_33 [ 2 ] ,
V_25 < V_23 ?
V_25 : V_23 ) ;
V_22 += V_25 ;
V_23 -= V_25 ;
F_12 ( V_31 , & V_5 -> V_29 ) ;
}
if ( V_13 >= 0 ) {
V_13 = 0 ;
break;
}
}
exit:
F_12 ( V_28 , & V_5 -> V_29 ) ;
F_17 ( & V_5 -> V_26 ) ;
return V_13 ;
}
static inline int F_18 ( struct V_1 * V_2 , T_2 V_20 , void * V_21 )
{
return F_8 ( V_2 , V_20 , V_21 , 1 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_20 , void * V_21 ,
const int V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
F_9 ( & V_5 -> V_26 ) ;
if ( F_10 ( V_20 ) != V_5 -> V_3 ) {
V_13 = F_1 ( V_2 , F_10 ( V_20 ) ) ;
if ( V_13 < 0 )
goto exit;
}
V_5 -> V_7 [ 0 ] = V_8 ;
V_5 -> V_7 [ 1 ] = V_19 ;
V_5 -> V_7 [ 2 ] = V_20 & 0xFF ;
V_5 -> V_7 [ 3 ] = ( V_20 >> 8 ) & 0xFF ;
memcpy ( & V_5 -> V_7 [ 4 ] , V_21 , V_19 ) ;
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
F_17 ( & V_5 -> V_26 ) ;
return V_13 ;
}
static inline int F_20 ( struct V_1 * V_2 , T_2 V_20 , void * V_21 )
{
return F_19 ( V_2 , V_20 , V_21 , 1 ) ;
}
static void F_21 ( struct V_4 * V_34 , int V_35 ,
T_1 V_36 , T_1 * V_37 )
{
int V_38 , V_39 , V_40 , V_41 ;
int V_42 , V_43 , V_44 ;
int V_45 ;
F_22 ( V_34 -> V_46 , V_35 ) ;
F_23 ( V_34 -> V_46 , V_47 ,
V_36 == 0x01 ) ;
if ( V_36 == 0x01 ) {
V_38 = ( V_37 [ 0 ] << 4 ) | ( V_37 [ 2 ] & 0x0F ) ;
V_39 = ( V_37 [ 1 ] << 4 ) | ( V_37 [ 2 ] >> 4 ) ;
V_40 = V_37 [ 3 ] & 0x0F ;
V_41 = V_37 [ 3 ] >> 4 ;
V_42 = ( V_40 > V_41 ) ;
V_43 = F_24 ( V_40 , V_41 ) ;
V_44 = F_25 ( V_40 , V_41 ) ;
V_45 = V_37 [ 4 ] ;
V_39 = V_34 -> V_48 - V_39 ;
F_26 ( V_34 -> V_46 , V_49 , V_50 , V_38 ) ;
F_26 ( V_34 -> V_46 , V_49 , V_51 , V_39 ) ;
F_26 ( V_34 -> V_46 , V_49 , V_52 , V_42 ) ;
F_26 ( V_34 -> V_46 , V_49 , V_53 , V_45 ) ;
F_26 ( V_34 -> V_46 , V_49 , V_54 , V_43 ) ;
F_26 ( V_34 -> V_46 , V_49 , V_55 , V_44 ) ;
}
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
V_13 = F_5 ( V_2 , V_56 ) ;
if ( V_13 )
return V_13 ;
if ( V_5 -> V_57 ) {
V_13 = F_20 ( V_2 , V_5 -> V_58 . V_59 + 1 ,
& V_5 -> V_60 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_6 ) ;
return V_13 ;
}
}
return 0 ;
}
static void F_29 ( struct V_61 * V_62 )
{
struct V_4 * V_34 = F_30 ( V_62 , struct V_4 ,
V_63 ) ;
F_27 ( V_34 -> V_2 ) ;
}
static inline int F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
return F_32 ( & V_34 -> V_63 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_64 , T_1 * V_5 ,
int V_65 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
int V_66 ;
int V_67 ;
if ( ! ( V_64 & V_34 -> V_68 . V_69 ) || V_65 <= 0 )
return 0 ;
V_66 = ( V_34 -> V_70 >> 2 ) + 1 ;
for ( V_67 = 0 ; V_67 < V_34 -> V_70 ; V_67 ++ ) {
int V_71 = V_67 >> 2 ;
int V_72 = ( V_67 & 0x3 ) << 1 ;
int V_36 = ( V_5 [ V_71 ] >> V_72 ) &
0x03 ;
int V_73 = V_66 + 5 * V_67 ;
if ( V_73 + 5 > V_65 ) {
F_34 ( V_74
L_7 ,
F_35 ( & V_2 -> V_10 ) ,
F_36 ( & V_2 -> V_10 ) ) ;
F_37 ( V_2 , L_8 ) ;
break;
}
F_21 ( V_34 , V_67 , V_36 , & V_5 [ V_73 ] ) ;
}
F_38 ( V_34 -> V_46 ) ;
F_39 ( V_34 -> V_46 ) ;
return V_34 -> V_68 . V_75 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_64 , T_1 * V_5 ,
int V_65 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
int V_67 ;
int V_76 = 0 ;
bool V_77 ;
if ( ! ( V_64 & V_34 -> V_78 . V_69 ) )
return 0 ;
if ( V_65 < ( int ) V_34 -> V_78 . V_75 ) {
F_16 ( V_2 , L_9 ) ;
return 0 ;
}
for ( V_67 = 0 ; V_67 < V_34 -> V_79 ; V_67 ++ ) {
if ( F_14 ( V_67 , & V_34 -> V_80 ) ) {
V_77 = ( V_5 [ V_67 / 8 ] >> ( V_67 & 0x07 ) ) & F_41 ( 0 ) ;
if ( F_14 ( V_67 , & V_34 -> V_81 ) )
V_77 = ! V_77 ;
F_26 ( V_34 -> V_46 , V_82 , V_83 + V_76 ++ ,
V_77 ) ;
}
}
return V_34 -> V_78 . V_75 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 * V_5 , int V_65 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
unsigned long V_69 = 0 ;
unsigned V_84 = 2 ;
if ( ! ( F_14 ( V_85 , & V_34 -> V_29 ) ) )
return 0 ;
V_69 |= V_34 -> V_68 . V_69 ;
V_69 |= V_34 -> V_78 . V_69 ;
if ( V_5 [ 1 ] & ~ V_69 )
F_37 ( V_2 , L_10 ,
V_5 [ 1 ] & ~ V_69 , __FILE__ , __LINE__ ) ;
if ( V_34 -> V_68 . V_86 < V_34 -> V_78 . V_86 ) {
V_84 += F_33 ( V_2 , V_5 [ 1 ] , & V_5 [ V_84 ] ,
V_65 - V_84 ) ;
V_84 += F_40 ( V_2 , V_5 [ 1 ] , & V_5 [ V_84 ] ,
V_65 - V_84 ) ;
} else {
V_84 += F_40 ( V_2 , V_5 [ 1 ] , & V_5 [ V_84 ] ,
V_65 - V_84 ) ;
V_84 += F_33 ( V_2 , V_5 [ 1 ] , & V_5 [ V_84 ] ,
V_65 - V_84 ) ;
}
return 1 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 * V_5 , int V_65 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
if ( ! F_14 ( V_28 , & V_34 -> V_29 ) ) {
F_37 ( V_2 , L_11 ) ;
return 0 ;
}
memcpy ( V_34 -> V_33 , V_5 , V_65 < V_34 -> V_87 ?
V_65 : V_34 -> V_87 ) ;
F_11 ( V_31 , & V_34 -> V_29 ) ;
F_44 ( & V_34 -> V_30 ) ;
return 1 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 * V_5 , int V_65 )
{
int V_88 = V_65 ;
while ( ( V_5 [ V_88 - 1 ] == 0xff ) && V_88 > 0 )
V_88 -- ;
return V_88 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_89 * V_18 , T_1 * V_5 , int V_65 )
{
V_65 = F_45 ( V_2 , V_5 , V_65 ) ;
if ( V_65 < 2 )
return 0 ;
switch ( V_5 [ 0 ] ) {
case V_90 :
return F_43 ( V_2 , V_5 , V_65 ) ;
case V_91 :
return F_42 ( V_2 , V_5 , V_65 ) ;
default:
return 1 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_92 * V_93 ,
struct V_94 * V_95 , T_3 V_77 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ( V_5 -> V_96 & V_97 ) &&
( V_93 -> V_98 == V_99 ||
V_93 -> V_98 == V_100 ) ) {
if ( V_5 -> V_96 & V_101 ) {
if ( ( V_95 -> V_102 & V_103 ) == V_104 )
return 0 ;
if ( ( V_95 -> V_102 == V_105 || V_95 -> V_102 == V_106 )
&& ! V_77 )
return 1 ;
}
F_31 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , int V_107 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
T_1 V_108 ;
V_108 = ( V_5 -> V_108 & ~ 0x3 ) | V_107 ;
V_13 = F_20 ( V_2 , V_5 -> V_58 . V_59 ,
& V_108 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_12 ) ;
return V_13 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , T_4 V_109 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
T_1 V_21 [ V_110 ] ;
if ( ! ( V_5 -> V_96 & V_97 ) )
return 0 ;
V_13 = F_8 ( V_2 , V_5 -> V_68 . V_59 , V_21 ,
V_110 ) ;
if ( V_13 )
F_16 ( V_2 , L_13 ) ;
else
memcpy ( V_5 -> V_111 , V_21 , V_110 ) ;
if ( ! F_50 ( V_2 -> V_10 . V_112 ) )
return F_48 ( V_2 , V_113 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
if ( ! ( V_5 -> V_96 & V_97 ) )
return 0 ;
V_13 = F_27 ( V_2 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_14 ) ;
return V_13 ;
}
if ( V_5 -> V_114 ) {
V_13 = F_19 ( V_2 , V_5 -> V_68 . V_59 ,
V_5 -> V_111 , V_110 ) ;
if ( V_13 )
F_16 ( V_2 ,
L_15 ) ;
}
if ( ! F_50 ( V_2 -> V_10 . V_112 ) ) {
V_13 = F_48 ( V_2 , V_115 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_12 ) ;
return V_13 ;
}
}
return V_13 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! ( V_5 -> V_96 & V_97 ) )
return 0 ;
return F_27 ( V_2 ) ;
}
static inline unsigned long F_53 ( unsigned V_116 , unsigned V_117 )
{
return F_54 ( V_117 + V_116 - 1 , V_116 ) ;
}
static void F_55 ( struct V_4 * V_5 ,
struct V_118 * V_118 , int V_3 , unsigned V_119 )
{
struct V_120 * V_121 = NULL ;
T_2 V_122 = V_3 << 8 ;
switch ( V_118 -> V_123 ) {
case 0x01 :
V_121 = & V_5 -> V_58 ;
break;
case 0x11 :
V_121 = & V_5 -> V_68 ;
break;
case 0x30 :
V_121 = & V_5 -> V_78 ;
break;
}
if ( V_121 ) {
V_121 -> V_3 = V_3 ;
V_121 -> V_124 = V_122 | V_118 -> V_124 ;
V_121 -> V_125 = V_122 | V_118 -> V_125 ;
V_121 -> V_59 = V_122 | V_118 -> V_59 ;
V_121 -> V_126 = V_122 | V_118 -> V_126 ;
V_121 -> V_86 = V_119 ;
V_121 -> V_119 = V_118 -> V_127 ;
V_121 -> V_69 = F_53 ( V_121 -> V_86 ,
V_121 -> V_119 ) ;
V_5 -> V_60 |= V_121 -> V_69 ;
}
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_118 V_128 ;
int V_3 ;
bool V_129 ;
int V_67 ;
int V_6 ;
int V_130 = 0 ;
T_2 V_131 , V_132 , V_133 ;
F_57 ( V_2 , L_16 ) ;
for ( V_3 = 0 ; ( V_3 <= V_134 ) ; V_3 ++ ) {
V_131 = V_135 * V_3 ;
V_132 = V_131 + V_136 ;
V_133 = V_131 + V_137 ;
V_129 = false ;
for ( V_67 = V_132 ; V_67 >= V_133 ; V_67 -= sizeof( V_128 ) ) {
V_6 = F_8 ( V_2 , V_67 , & V_128 , sizeof( V_128 ) ) ;
if ( V_6 ) {
F_28 ( V_2 ,
L_17 ,
V_67 ) ;
goto V_138;
}
if ( F_58 ( V_128 . V_123 ) )
break;
V_129 = true ;
F_57 ( V_2 , L_18 ,
V_128 . V_123 , V_3 ) ;
F_55 ( V_5 , & V_128 , V_3 , V_130 ) ;
V_130 += V_128 . V_127 ;
}
if ( ! V_129 )
break;
}
F_57 ( V_2 , L_19 , V_11 ) ;
V_6 = 0 ;
V_138:
return V_6 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_139 [ V_140 ] ;
T_1 V_141 [ 3 ] ;
int V_13 ;
bool V_142 ;
bool V_143 ;
bool V_144 ;
bool V_145 = false ;
bool V_146 = false ;
bool V_147 = false ;
T_2 V_148 = V_5 -> V_58 . V_124 ;
T_2 V_149 ;
T_1 V_150 ;
V_13 = F_8 ( V_2 , V_148 , V_139 ,
V_140 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_20 ) ;
return V_13 ;
}
V_143 = ! ! ( V_139 [ 0 ] & F_41 ( 2 ) ) ;
V_144 = ! ! ( V_139 [ 1 ] & F_41 ( 3 ) ) ;
V_142 = ! ! ( V_139 [ 1 ] & F_41 ( 7 ) ) ;
V_148 += 11 ;
V_149 = V_148 + 6 ;
V_148 += 10 ;
if ( V_143 )
V_148 += 20 ;
if ( V_144 )
V_148 ++ ;
if ( V_142 ) {
V_13 = F_18 ( V_2 , V_148 , V_141 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_21 ) ;
return V_13 ;
}
V_145 = ! ! ( V_141 [ 0 ] & F_41 ( 0 ) ) ;
V_148 ++ ;
}
if ( V_145 ) {
V_13 = F_18 ( V_2 , V_148 , & V_150 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_22 ) ;
return V_13 ;
}
V_148 ++ ;
if ( V_150 > 0 ) {
V_13 = F_18 ( V_2 , V_148 , V_141 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_23 ) ;
return V_13 ;
}
V_147 = ! ! ( V_141 [ 0 ] & F_41 ( 0 ) ) ;
V_146 = ! ! ( V_141 [ 0 ] & F_41 ( 1 ) ) ;
}
}
if ( V_147 )
V_149 ++ ;
if ( V_146 ) {
V_13 = F_8 ( V_2 , V_149 , V_141 , 3 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_24 ) ;
return V_13 ;
}
V_5 -> V_151 = V_141 [ 1 ] << 8 | V_141 [ 0 ] ;
V_5 -> V_151 += V_141 [ 2 ] * 65536 ;
}
V_13 = F_8 ( V_2 , V_5 -> V_58 . V_59 , V_141 ,
2 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_25 ) ;
return V_13 ;
}
V_5 -> V_108 = V_141 [ 0 ] ;
if ( ! V_141 [ 1 ] ) {
V_5 -> V_57 = true ;
V_13 = F_20 ( V_2 , V_5 -> V_58 . V_59 + 1 ,
& V_5 -> V_60 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_26 ,
V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_21 [ 20 ] ;
int V_13 ;
bool V_152 ;
bool V_153 = false ;
bool V_154 ;
bool V_155 ;
bool V_156 ;
bool V_157 ;
bool V_158 = false ;
bool V_159 ;
bool V_160 ;
bool V_161 ;
bool V_162 = false ;
bool V_163 = false ;
bool V_164 = false ;
unsigned V_165 , V_166 ;
T_2 V_148 ;
if ( ! V_5 -> V_68 . V_124 ) {
F_28 ( V_2 , L_27 ) ;
return - V_167 ;
}
V_13 = F_18 ( V_2 , V_5 -> V_68 . V_124 , V_21 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_28 , V_13 ) ;
return V_13 ;
}
V_152 = ! ! ( V_21 [ 0 ] & F_41 ( 3 ) ) ;
V_154 = ! ! ( V_21 [ 0 ] & F_41 ( 4 ) ) ;
V_155 = ! ! ( V_21 [ 0 ] & F_41 ( 5 ) ) ;
V_156 = ! ! ( V_21 [ 0 ] & F_41 ( 6 ) ) ;
V_157 = ! ! ( V_21 [ 0 ] & F_41 ( 7 ) ) ;
V_13 = F_18 ( V_2 , V_5 -> V_68 . V_124 + 1 , V_21 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_29 , V_13 ) ;
return V_13 ;
}
V_5 -> V_70 = ( V_21 [ 0 ] & 0x07 ) + 1 ;
if ( V_5 -> V_70 > 5 )
V_5 -> V_70 = 10 ;
V_5 -> V_68 . V_75 = V_5 -> V_70 * 5 +
F_61 ( V_5 -> V_70 , 4 ) ;
if ( ! ( V_21 [ 0 ] & F_41 ( 4 ) ) ) {
F_28 ( V_2 , L_30 ) ;
return - V_167 ;
}
V_161 = ! ! ( V_21 [ 0 ] & F_41 ( 3 ) ) ;
V_160 = ! ! ( V_21 [ 0 ] & F_41 ( 5 ) ) ;
V_13 = F_18 ( V_2 , V_5 -> V_68 . V_124 + 5 , V_21 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_31 , V_13 ) ;
return V_13 ;
}
V_163 = ! ! ( V_21 [ 0 ] & F_41 ( 4 ) ) ;
V_148 = 6 ;
if ( V_161 )
++ V_148 ;
if ( V_160 ) {
V_13 = F_18 ( V_2 ,
V_5 -> V_68 . V_124 + V_148 + 1 , V_21 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_32 ,
V_13 ) ;
return V_13 ;
}
V_164 = ! ! ( V_21 [ 0 ] & F_41 ( 0 ) ) ;
V_153 = ! ! ( V_21 [ 0 ] & F_41 ( 2 ) ) ;
V_148 += 2 ;
}
if ( V_152 )
++ V_148 ;
if ( V_153 )
++ V_148 ;
if ( V_154 )
++ V_148 ;
if ( V_155 ) {
V_13 = F_18 ( V_2 , V_5 -> V_68 . V_124
+ V_148 , V_21 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_33 , V_13 ) ;
return V_13 ;
}
V_159 = ! ! ( V_21 [ 0 ] & F_41 ( 5 ) ) ;
if ( V_159 ) {
V_148 += 1 ;
V_13 = F_8 ( V_2 ,
V_5 -> V_68 . V_124
+ V_148 , V_21 , 4 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_34 ,
V_13 ) ;
return V_13 ;
}
V_165 = V_21 [ 0 ] | ( V_21 [ 1 ] << 8 ) ;
V_166 = V_21 [ 2 ] | ( V_21 [ 3 ] << 8 ) ;
V_5 -> V_168 = F_62 ( V_165 , 10 ) ;
V_5 -> V_169 = F_62 ( V_166 , 10 ) ;
F_57 ( V_2 , L_35 ,
V_11 , V_5 -> V_168 , V_5 -> V_169 ) ;
V_148 += 12 ;
}
}
if ( V_156 )
++ V_148 ;
if ( V_157 ) {
V_13 = F_18 ( V_2 , V_5 -> V_68 . V_124
+ V_148 , V_21 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_36 , V_13 ) ;
return V_13 ;
}
V_158 = ! ! ( V_21 [ 0 ] & F_41 ( 6 ) ) ;
}
if ( V_158 ) {
V_148 += 2 ;
V_13 = F_18 ( V_2 , V_5 -> V_68 . V_124
+ V_148 , V_21 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_37 , V_13 ) ;
return V_13 ;
}
V_162 = ! ! ( V_21 [ 0 ] & F_41 ( 5 ) ) ;
}
if ( V_162 )
V_5 -> V_68 . V_75 += V_5 -> V_70 * 2 ;
V_13 = F_8 ( V_2 , V_5 -> V_68 . V_59 ,
V_5 -> V_111 , V_110 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_38 , V_13 ) ;
return V_13 ;
}
V_5 -> V_114 = true ;
V_5 -> V_170 = V_5 -> V_111 [ 6 ] | ( V_5 -> V_111 [ 7 ] << 8 ) ;
V_5 -> V_48 = V_5 -> V_111 [ 8 ] | ( V_5 -> V_111 [ 9 ] << 8 ) ;
if ( V_163 ) {
V_5 -> V_111 [ 0 ] = V_5 -> V_111 [ 0 ] & ~ F_41 ( 6 ) ;
V_13 = F_20 ( V_2 , V_5 -> V_68 . V_59 ,
V_5 -> V_111 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_39 ,
V_13 ) ;
return V_13 ;
}
}
if ( V_164 ) {
V_5 -> V_111 [ 11 ] = V_5 -> V_111 [ 11 ] & ~ F_41 ( 0 ) ;
V_13 = F_20 ( V_2 , V_5 -> V_68 . V_59 + 11 ,
& V_5 -> V_111 [ 11 ] ) ;
if ( V_13 ) {
F_28 ( V_2 , L_40 ,
V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_21 [ 20 ] ;
int V_13 ;
bool V_171 , V_172 ;
unsigned V_173 ;
T_1 V_174 ;
int V_175 ;
int V_67 ;
if ( ! V_5 -> V_78 . V_124 ) {
F_28 ( V_2 , L_41 ) ;
return - V_167 ;
}
V_13 = F_8 ( V_2 , V_5 -> V_78 . V_124 , V_21 , 2 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_42 , V_13 ) ;
return V_13 ;
}
V_171 = ! ! ( V_21 [ 0 ] & F_41 ( 3 ) ) ;
V_172 = ! ! ( V_21 [ 0 ] & F_41 ( 2 ) ) ;
V_5 -> V_79 = V_21 [ 1 ] & 0x1f ;
V_173 = ( V_5 -> V_79 + 7 ) / 8 ;
V_174 = ( V_171 && V_172 ) ? V_173 : 0 ;
V_174 += V_173 ;
V_175 = 2 * V_173 ;
V_5 -> V_78 . V_75 = V_173 ;
V_13 = F_8 ( V_2 , V_5 -> V_78 . V_59 + V_174 ,
V_21 , V_175 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_43 ,
V_175 , V_13 ) ;
return V_13 ;
}
for ( V_67 = 0 ; V_67 < V_5 -> V_79 ; V_67 ++ ) {
int V_176 = V_67 >> 3 ;
int V_177 = V_67 & 0x07 ;
T_1 V_178 = V_21 [ V_176 ] ;
T_1 V_179 = V_21 [ V_176 + V_173 ] ;
bool V_180 = ( V_178 >> V_177 ) & F_41 ( 0 ) ;
bool V_181 = ( V_179 >> V_177 ) & F_41 ( 0 ) ;
if ( V_180 == 0 ) {
if ( V_181 ) {
V_5 -> V_182 ++ ;
F_11 ( V_67 , & V_5 -> V_80 ) ;
F_11 ( V_67 , & V_5 -> V_81 ) ;
}
}
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
V_13 = F_56 ( V_2 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_44 , V_13 ) ;
return V_13 ;
}
V_13 = F_59 ( V_2 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_45 , V_13 ) ;
return V_13 ;
}
V_13 = F_60 ( V_2 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_46 , V_13 ) ;
return V_13 ;
}
if ( ! ( V_5 -> V_96 & V_101 ) ) {
V_13 = F_63 ( V_2 ) ;
if ( V_13 )
F_16 ( V_2 , L_47 , V_13 ) ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_183 * V_184 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_185 * V_46 = V_184 -> V_46 ;
int V_13 ;
int V_186 , V_187 , V_67 ;
V_5 -> V_46 = V_46 ;
F_37 ( V_2 , L_48 ) ;
V_13 = F_66 ( V_2 ) ;
if ( V_13 )
return V_13 ;
if ( ! ( V_5 -> V_96 & V_97 ) )
return 0 ;
F_67 ( V_2 ) ;
V_13 = F_5 ( V_2 , V_56 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_49 ) ;
goto exit;
}
V_13 = F_1 ( V_2 , 0 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_50 ) ;
goto exit;
}
V_13 = F_64 ( V_2 ) ;
if ( V_13 )
goto exit;
F_57 ( V_2 , L_51 , V_5 -> V_151 ) ;
F_68 ( V_49 , V_46 -> V_188 ) ;
F_69 ( V_46 , V_50 , 1 , V_5 -> V_170 , 0 , 0 ) ;
F_69 ( V_46 , V_51 , 1 , V_5 -> V_48 , 0 , 0 ) ;
if ( V_5 -> V_168 && V_5 -> V_169 ) {
V_186 = ( V_5 -> V_170 - 1 ) / V_5 -> V_168 ;
V_187 = ( V_5 -> V_48 - 1 ) / V_5 -> V_169 ;
F_70 ( V_46 , V_50 , V_186 ) ;
F_70 ( V_46 , V_51 , V_187 ) ;
}
F_69 ( V_46 , V_52 , 0 , 1 , 0 , 0 ) ;
F_69 ( V_46 , V_53 , 0 , 0xff , 0 , 0 ) ;
F_69 ( V_46 , V_54 , 0 , 0x0f , 0 , 0 ) ;
F_69 ( V_46 , V_55 , 0 , 0x0f , 0 , 0 ) ;
V_13 = F_71 ( V_46 , V_5 -> V_70 , V_189 ) ;
if ( V_13 < 0 )
goto exit;
if ( V_5 -> V_182 ) {
F_68 ( V_82 , V_46 -> V_188 ) ;
for ( V_67 = 0 ; V_67 < V_5 -> V_182 ; V_67 ++ )
F_68 ( V_83 + V_67 , V_46 -> V_190 ) ;
if ( V_5 -> V_182 == 1 )
F_68 ( V_191 , V_46 -> V_192 ) ;
}
F_11 ( V_85 , & V_5 -> V_29 ) ;
exit:
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
return V_13 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_183 * V_184 , struct V_92 * V_93 ,
struct V_94 * V_95 , unsigned long * * V_193 , int * F_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_96 & V_97 ) {
if ( ( V_5 -> V_96 & V_101 ) &&
( ( V_95 -> V_102 & V_103 ) == V_104 ) )
return 0 ;
return - 1 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , unsigned type ,
unsigned V_194 , struct V_89 * * V_18 )
{
int V_67 ;
* V_18 = V_2 -> V_195 [ type ] . V_196 [ V_194 ] ;
if ( * V_18 ) {
for ( V_67 = 0 ; V_67 < ( * V_18 ) -> V_197 ; V_67 ++ ) {
unsigned V_198 = ( * V_18 ) -> V_93 [ V_67 ] -> V_98 ;
if ( ( V_198 & V_103 ) >= V_199 )
return 1 ;
}
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , const struct V_200 * V_194 )
{
struct V_4 * V_5 = NULL ;
int V_13 ;
T_5 V_201 ;
struct V_89 * V_202 ;
struct V_89 * V_203 ;
struct V_89 * V_204 ;
V_5 = F_77 ( & V_2 -> V_10 , sizeof( struct V_4 ) , V_205 ) ;
if ( ! V_5 )
return - V_206 ;
F_78 ( & V_5 -> V_63 , F_29 ) ;
V_5 -> V_2 = V_2 ;
F_79 ( V_2 , V_5 ) ;
V_2 -> V_207 |= V_208 ;
V_13 = F_80 ( V_2 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_52 ) ;
return V_13 ;
}
if ( V_194 -> V_209 )
V_5 -> V_96 = V_194 -> V_209 ;
if ( ! F_75 ( V_2 , V_16 ,
V_15 , & V_204 ) ) {
F_37 ( V_2 , L_53 ) ;
goto V_210;
}
if ( ! F_75 ( V_2 , V_211 ,
V_91 , & V_202 ) ) {
F_37 ( V_2 , L_54 ) ;
goto V_210;
}
V_5 -> V_87 = F_81 ( V_202 ) ;
if ( ! F_75 ( V_2 , V_212 ,
V_8 , & V_203 ) ) {
F_37 ( V_2 ,
L_55 ) ;
goto V_210;
}
V_5 -> V_9 = F_81 ( V_203 ) ;
V_5 -> V_96 |= V_97 ;
V_201 = V_5 -> V_9 + V_5 -> V_87 ;
V_5 -> V_7 = F_77 ( & V_2 -> V_10 , V_201 , V_205 ) ;
if ( ! V_5 -> V_7 ) {
V_13 = - V_206 ;
return V_13 ;
}
V_5 -> V_33 = V_5 -> V_7 + V_5 -> V_9 ;
F_82 ( & V_5 -> V_30 ) ;
F_83 ( & V_5 -> V_26 ) ;
V_210:
V_13 = F_84 ( V_2 , V_213 ) ;
if ( V_13 ) {
F_28 ( V_2 , L_56 ) ;
return V_13 ;
}
if ( ( V_5 -> V_96 & V_97 ) &&
! F_14 ( V_85 , & V_5 -> V_29 ) )
F_28 ( V_2 , L_57 ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
F_12 ( V_85 , & V_34 -> V_29 ) ;
F_86 ( V_2 ) ;
}
