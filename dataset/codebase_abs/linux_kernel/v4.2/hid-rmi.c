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
static void F_27 ( struct V_56 * V_57 )
{
struct V_4 * V_34 = F_28 ( V_57 , struct V_4 ,
V_58 ) ;
F_5 ( V_34 -> V_2 , V_59 ) ;
}
static inline int F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
return F_30 ( & V_34 -> V_58 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_60 , T_1 * V_5 ,
int V_61 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
int V_62 ;
int V_63 ;
if ( ! ( V_60 & V_34 -> V_64 . V_65 ) || V_61 <= 0 )
return 0 ;
V_62 = ( V_34 -> V_66 >> 2 ) + 1 ;
for ( V_63 = 0 ; V_63 < V_34 -> V_66 ; V_63 ++ ) {
int V_67 = V_63 >> 2 ;
int V_68 = ( V_63 & 0x3 ) << 1 ;
int V_36 = ( V_5 [ V_67 ] >> V_68 ) &
0x03 ;
int V_69 = V_62 + 5 * V_63 ;
if ( V_69 + 5 > V_61 ) {
F_32 ( V_70
L_6 ,
F_33 ( & V_2 -> V_10 ) ,
F_34 ( & V_2 -> V_10 ) ) ;
F_35 ( V_2 , L_7 ) ;
break;
}
F_21 ( V_34 , V_63 , V_36 , & V_5 [ V_69 ] ) ;
}
F_36 ( V_34 -> V_46 ) ;
F_37 ( V_34 -> V_46 ) ;
return V_34 -> V_64 . V_71 ;
}
static int F_38 ( struct V_1 * V_2 , T_1 V_60 , T_1 * V_5 ,
int V_61 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
int V_63 ;
int V_72 = 0 ;
bool V_73 ;
if ( ! ( V_60 & V_34 -> V_74 . V_65 ) )
return 0 ;
if ( V_61 < ( int ) V_34 -> V_74 . V_71 ) {
F_16 ( V_2 , L_8 ) ;
return 0 ;
}
for ( V_63 = 0 ; V_63 < V_34 -> V_75 ; V_63 ++ ) {
if ( F_14 ( V_63 , & V_34 -> V_76 ) ) {
V_73 = ( V_5 [ V_63 / 8 ] >> ( V_63 & 0x07 ) ) & F_39 ( 0 ) ;
if ( F_14 ( V_63 , & V_34 -> V_77 ) )
V_73 = ! V_73 ;
F_26 ( V_34 -> V_46 , V_78 , V_79 + V_72 ++ ,
V_73 ) ;
}
}
return V_34 -> V_74 . V_71 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 * V_5 , int V_61 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
unsigned long V_65 = 0 ;
unsigned V_80 = 2 ;
if ( ! ( F_14 ( V_81 , & V_34 -> V_29 ) ) )
return 0 ;
V_65 |= V_34 -> V_64 . V_65 ;
V_65 |= V_34 -> V_74 . V_65 ;
if ( V_5 [ 1 ] & ~ V_65 )
F_35 ( V_2 , L_9 ,
V_5 [ 1 ] & ~ V_65 , __FILE__ , __LINE__ ) ;
if ( V_34 -> V_64 . V_82 < V_34 -> V_74 . V_82 ) {
V_80 += F_31 ( V_2 , V_5 [ 1 ] , & V_5 [ V_80 ] ,
V_61 - V_80 ) ;
V_80 += F_38 ( V_2 , V_5 [ 1 ] , & V_5 [ V_80 ] ,
V_61 - V_80 ) ;
} else {
V_80 += F_38 ( V_2 , V_5 [ 1 ] , & V_5 [ V_80 ] ,
V_61 - V_80 ) ;
V_80 += F_31 ( V_2 , V_5 [ 1 ] , & V_5 [ V_80 ] ,
V_61 - V_80 ) ;
}
return 1 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 * V_5 , int V_61 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
if ( ! F_14 ( V_28 , & V_34 -> V_29 ) ) {
F_35 ( V_2 , L_10 ) ;
return 0 ;
}
memcpy ( V_34 -> V_33 , V_5 , V_61 < V_34 -> V_83 ?
V_61 : V_34 -> V_83 ) ;
F_11 ( V_31 , & V_34 -> V_29 ) ;
F_42 ( & V_34 -> V_30 ) ;
return 1 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 * V_5 , int V_61 )
{
int V_84 = V_61 ;
while ( ( V_5 [ V_84 - 1 ] == 0xff ) && V_84 > 0 )
V_84 -- ;
return V_84 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_85 * V_18 , T_1 * V_5 , int V_61 )
{
V_61 = F_43 ( V_2 , V_5 , V_61 ) ;
if ( V_61 < 2 )
return 0 ;
switch ( V_5 [ 0 ] ) {
case V_86 :
return F_41 ( V_2 , V_5 , V_61 ) ;
case V_87 :
return F_40 ( V_2 , V_5 , V_61 ) ;
default:
return 1 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_88 * V_89 ,
struct V_90 * V_91 , T_3 V_73 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ( V_5 -> V_92 & V_93 ) &&
( V_89 -> V_94 == V_95 ||
V_89 -> V_94 == V_96 ) ) {
if ( V_5 -> V_92 & V_97 ) {
if ( ( V_91 -> V_98 & V_99 ) == V_100 )
return 0 ;
if ( ( V_91 -> V_98 == V_101 || V_91 -> V_98 == V_102 )
&& ! V_73 )
return 1 ;
}
F_29 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_59 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_59 ) ;
}
static inline unsigned long F_48 ( unsigned V_103 , unsigned V_104 )
{
return F_49 ( V_104 + V_103 - 1 , V_103 ) ;
}
static void F_50 ( struct V_4 * V_5 ,
struct V_105 * V_105 , int V_3 , unsigned V_106 )
{
struct V_107 * V_108 = NULL ;
T_2 V_109 = V_3 << 8 ;
switch ( V_105 -> V_110 ) {
case 0x01 :
V_108 = & V_5 -> V_111 ;
break;
case 0x11 :
V_108 = & V_5 -> V_64 ;
break;
case 0x30 :
V_108 = & V_5 -> V_74 ;
break;
}
if ( V_108 ) {
V_108 -> V_3 = V_3 ;
V_108 -> V_112 = V_109 | V_105 -> V_112 ;
V_108 -> V_113 = V_109 | V_105 -> V_113 ;
V_108 -> V_114 = V_109 | V_105 -> V_114 ;
V_108 -> V_115 = V_109 | V_105 -> V_115 ;
V_108 -> V_82 = V_106 ;
V_108 -> V_106 = V_105 -> V_116 ;
V_108 -> V_65 = F_48 ( V_108 -> V_82 ,
V_108 -> V_106 ) ;
}
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_105 V_117 ;
int V_3 ;
bool V_118 ;
int V_63 ;
int V_6 ;
int V_119 = 0 ;
T_2 V_120 , V_121 , V_122 ;
F_52 ( V_2 , L_11 ) ;
for ( V_3 = 0 ; ( V_3 <= V_123 ) ; V_3 ++ ) {
V_120 = V_124 * V_3 ;
V_121 = V_120 + V_125 ;
V_122 = V_120 + V_126 ;
V_118 = false ;
for ( V_63 = V_121 ; V_63 >= V_122 ; V_63 -= sizeof( V_117 ) ) {
V_6 = F_8 ( V_2 , V_63 , & V_117 , sizeof( V_117 ) ) ;
if ( V_6 ) {
F_53 ( V_2 ,
L_12 ,
V_63 ) ;
goto V_127;
}
if ( F_54 ( V_117 . V_110 ) )
break;
V_118 = true ;
F_52 ( V_2 , L_13 ,
V_117 . V_110 , V_3 ) ;
F_50 ( V_5 , & V_117 , V_3 , V_119 ) ;
V_119 += V_117 . V_116 ;
}
if ( ! V_118 )
break;
}
F_52 ( V_2 , L_14 , V_11 ) ;
V_6 = 0 ;
V_127:
return V_6 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_128 [ V_129 ] ;
T_1 V_130 [ 3 ] ;
int V_13 ;
bool V_131 ;
bool V_132 ;
bool V_133 ;
bool V_134 = false ;
bool V_135 = false ;
bool V_136 = false ;
T_2 V_137 = V_5 -> V_111 . V_112 ;
T_2 V_138 ;
T_1 V_139 ;
V_13 = F_8 ( V_2 , V_137 , V_128 ,
V_129 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_15 ) ;
return V_13 ;
}
V_132 = ! ! ( V_128 [ 0 ] & F_39 ( 2 ) ) ;
V_133 = ! ! ( V_128 [ 1 ] & F_39 ( 3 ) ) ;
V_131 = ! ! ( V_128 [ 1 ] & F_39 ( 7 ) ) ;
V_137 += 11 ;
V_138 = V_137 + 6 ;
V_137 += 10 ;
if ( V_132 )
V_137 += 20 ;
if ( V_133 )
V_137 ++ ;
if ( V_131 ) {
V_13 = F_18 ( V_2 , V_137 , V_130 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_16 ) ;
return V_13 ;
}
V_134 = ! ! ( V_130 [ 0 ] & F_39 ( 0 ) ) ;
V_137 ++ ;
}
if ( V_134 ) {
V_13 = F_18 ( V_2 , V_137 , & V_139 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_17 ) ;
return V_13 ;
}
V_137 ++ ;
if ( V_139 > 0 ) {
V_13 = F_18 ( V_2 , V_137 , V_130 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_18 ) ;
return V_13 ;
}
V_136 = ! ! ( V_130 [ 0 ] & F_39 ( 0 ) ) ;
V_135 = ! ! ( V_130 [ 0 ] & F_39 ( 1 ) ) ;
}
}
if ( V_136 )
V_138 ++ ;
if ( V_135 ) {
V_13 = F_8 ( V_2 , V_138 , V_130 , 3 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_19 ) ;
return V_13 ;
}
V_5 -> V_140 = V_130 [ 1 ] << 8 | V_130 [ 0 ] ;
V_5 -> V_140 += V_130 [ 2 ] * 65536 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_21 [ 20 ] ;
int V_13 ;
bool V_141 ;
bool V_142 = false ;
bool V_143 ;
bool V_144 ;
bool V_145 ;
bool V_146 ;
bool V_147 = false ;
bool V_148 ;
bool V_149 ;
bool V_150 ;
bool V_151 = false ;
bool V_152 = false ;
bool V_153 = false ;
unsigned V_154 , V_155 ;
T_2 V_137 ;
if ( ! V_5 -> V_64 . V_112 ) {
F_53 ( V_2 , L_20 ) ;
return - V_156 ;
}
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_112 , V_21 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_21 , V_13 ) ;
return V_13 ;
}
V_141 = ! ! ( V_21 [ 0 ] & F_39 ( 3 ) ) ;
V_143 = ! ! ( V_21 [ 0 ] & F_39 ( 4 ) ) ;
V_144 = ! ! ( V_21 [ 0 ] & F_39 ( 5 ) ) ;
V_145 = ! ! ( V_21 [ 0 ] & F_39 ( 6 ) ) ;
V_146 = ! ! ( V_21 [ 0 ] & F_39 ( 7 ) ) ;
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_112 + 1 , V_21 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_22 , V_13 ) ;
return V_13 ;
}
V_5 -> V_66 = ( V_21 [ 0 ] & 0x07 ) + 1 ;
if ( V_5 -> V_66 > 5 )
V_5 -> V_66 = 10 ;
V_5 -> V_64 . V_71 = V_5 -> V_66 * 5 +
F_57 ( V_5 -> V_66 , 4 ) ;
if ( ! ( V_21 [ 0 ] & F_39 ( 4 ) ) ) {
F_53 ( V_2 , L_23 ) ;
return - V_156 ;
}
V_150 = ! ! ( V_21 [ 0 ] & F_39 ( 3 ) ) ;
V_149 = ! ! ( V_21 [ 0 ] & F_39 ( 5 ) ) ;
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_112 + 5 , V_21 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_24 , V_13 ) ;
return V_13 ;
}
V_152 = ! ! ( V_21 [ 0 ] & F_39 ( 4 ) ) ;
V_137 = 6 ;
if ( V_150 )
++ V_137 ;
if ( V_149 ) {
V_13 = F_18 ( V_2 ,
V_5 -> V_64 . V_112 + V_137 + 1 , V_21 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_25 ,
V_13 ) ;
return V_13 ;
}
V_153 = ! ! ( V_21 [ 0 ] & F_39 ( 0 ) ) ;
V_142 = ! ! ( V_21 [ 0 ] & F_39 ( 2 ) ) ;
V_137 += 2 ;
}
if ( V_141 )
++ V_137 ;
if ( V_142 )
++ V_137 ;
if ( V_143 )
++ V_137 ;
if ( V_144 ) {
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_112
+ V_137 , V_21 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_26 , V_13 ) ;
return V_13 ;
}
V_148 = ! ! ( V_21 [ 0 ] & F_39 ( 5 ) ) ;
if ( V_148 ) {
V_137 += 1 ;
V_13 = F_8 ( V_2 ,
V_5 -> V_64 . V_112
+ V_137 , V_21 , 4 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_27 ,
V_13 ) ;
return V_13 ;
}
V_154 = V_21 [ 0 ] | ( V_21 [ 1 ] << 8 ) ;
V_155 = V_21 [ 2 ] | ( V_21 [ 3 ] << 8 ) ;
V_5 -> V_157 = F_58 ( V_154 , 10 ) ;
V_5 -> V_158 = F_58 ( V_155 , 10 ) ;
F_52 ( V_2 , L_28 ,
V_11 , V_5 -> V_157 , V_5 -> V_158 ) ;
V_137 += 12 ;
}
}
if ( V_145 )
++ V_137 ;
if ( V_146 ) {
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_112
+ V_137 , V_21 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_29 , V_13 ) ;
return V_13 ;
}
V_147 = ! ! ( V_21 [ 0 ] & F_39 ( 6 ) ) ;
}
if ( V_147 ) {
V_137 += 2 ;
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_112
+ V_137 , V_21 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_30 , V_13 ) ;
return V_13 ;
}
V_151 = ! ! ( V_21 [ 0 ] & F_39 ( 5 ) ) ;
}
if ( V_151 )
V_5 -> V_64 . V_71 += V_5 -> V_66 * 2 ;
V_13 = F_8 ( V_2 , V_5 -> V_64 . V_114 , V_21 , 12 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_31 , V_13 ) ;
return V_13 ;
}
V_5 -> V_159 = V_21 [ 6 ] | ( V_21 [ 7 ] << 8 ) ;
V_5 -> V_48 = V_21 [ 8 ] | ( V_21 [ 9 ] << 8 ) ;
if ( V_152 ) {
V_21 [ 0 ] = V_21 [ 0 ] & ~ F_39 ( 6 ) ;
V_13 = F_20 ( V_2 , V_5 -> V_64 . V_114 , V_21 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_32 ,
V_13 ) ;
return V_13 ;
}
}
if ( V_153 ) {
V_21 [ 11 ] = V_21 [ 11 ] & ~ F_39 ( 0 ) ;
V_13 = F_20 ( V_2 , V_5 -> V_64 . V_114 + 11 ,
& V_21 [ 11 ] ) ;
if ( V_13 ) {
F_53 ( V_2 , L_33 ,
V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_21 [ 20 ] ;
int V_13 ;
bool V_160 , V_161 ;
unsigned V_162 ;
T_1 V_163 ;
int V_164 ;
int V_63 ;
if ( ! V_5 -> V_74 . V_112 ) {
F_53 ( V_2 , L_34 ) ;
return - V_156 ;
}
V_13 = F_8 ( V_2 , V_5 -> V_74 . V_112 , V_21 , 2 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_35 , V_13 ) ;
return V_13 ;
}
V_160 = ! ! ( V_21 [ 0 ] & F_39 ( 3 ) ) ;
V_161 = ! ! ( V_21 [ 0 ] & F_39 ( 2 ) ) ;
V_5 -> V_75 = V_21 [ 1 ] & 0x1f ;
V_162 = ( V_5 -> V_75 + 7 ) / 8 ;
V_163 = ( V_160 && V_161 ) ? V_162 : 0 ;
V_163 += V_162 ;
V_164 = 2 * V_162 ;
V_5 -> V_74 . V_71 = V_162 ;
V_13 = F_8 ( V_2 , V_5 -> V_74 . V_114 + V_163 ,
V_21 , V_164 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_36 ,
V_164 , V_13 ) ;
return V_13 ;
}
for ( V_63 = 0 ; V_63 < V_5 -> V_75 ; V_63 ++ ) {
int V_165 = V_63 >> 3 ;
int V_166 = V_63 & 0x07 ;
T_1 V_167 = V_21 [ V_165 ] ;
T_1 V_168 = V_21 [ V_165 + V_162 ] ;
bool V_169 = ( V_167 >> V_166 ) & F_39 ( 0 ) ;
bool V_170 = ( V_168 >> V_166 ) & F_39 ( 0 ) ;
if ( V_169 == 0 ) {
if ( V_170 ) {
V_5 -> V_171 ++ ;
F_11 ( V_63 , & V_5 -> V_76 ) ;
F_11 ( V_63 , & V_5 -> V_77 ) ;
}
}
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_13 ;
V_13 = F_51 ( V_2 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_37 , V_13 ) ;
return V_13 ;
}
V_13 = F_55 ( V_2 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_38 , V_13 ) ;
return V_13 ;
}
V_13 = F_56 ( V_2 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_39 , V_13 ) ;
return V_13 ;
}
if ( ! ( V_5 -> V_92 & V_97 ) ) {
V_13 = F_59 ( V_2 ) ;
if ( V_13 )
F_16 ( V_2 , L_40 , V_13 ) ;
}
return 0 ;
}
static void F_61 ( struct V_1 * V_2 , struct V_172 * V_173 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_174 * V_46 = V_173 -> V_46 ;
int V_13 ;
int V_175 , V_176 , V_63 ;
V_5 -> V_46 = V_46 ;
F_35 ( V_2 , L_41 ) ;
V_13 = F_62 ( V_2 ) ;
if ( V_13 )
return;
if ( ! ( V_5 -> V_92 & V_93 ) )
return;
F_63 ( V_2 ) ;
V_13 = F_5 ( V_2 , V_59 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_42 ) ;
goto exit;
}
V_13 = F_1 ( V_2 , 0 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_43 ) ;
goto exit;
}
V_13 = F_60 ( V_2 ) ;
if ( V_13 )
goto exit;
F_52 ( V_2 , L_44 , V_5 -> V_140 ) ;
F_64 ( V_49 , V_46 -> V_177 ) ;
F_65 ( V_46 , V_50 , 1 , V_5 -> V_159 , 0 , 0 ) ;
F_65 ( V_46 , V_51 , 1 , V_5 -> V_48 , 0 , 0 ) ;
if ( V_5 -> V_157 && V_5 -> V_158 ) {
V_175 = ( V_5 -> V_159 - 1 ) / V_5 -> V_157 ;
V_176 = ( V_5 -> V_48 - 1 ) / V_5 -> V_158 ;
F_66 ( V_46 , V_50 , V_175 ) ;
F_66 ( V_46 , V_51 , V_176 ) ;
}
F_65 ( V_46 , V_52 , 0 , 1 , 0 , 0 ) ;
F_65 ( V_46 , V_53 , 0 , 0xff , 0 , 0 ) ;
F_65 ( V_46 , V_54 , 0 , 0x0f , 0 , 0 ) ;
F_65 ( V_46 , V_55 , 0 , 0x0f , 0 , 0 ) ;
F_67 ( V_46 , V_5 -> V_66 , V_178 ) ;
if ( V_5 -> V_171 ) {
F_64 ( V_78 , V_46 -> V_177 ) ;
for ( V_63 = 0 ; V_63 < V_5 -> V_171 ; V_63 ++ )
F_64 ( V_79 + V_63 , V_46 -> V_179 ) ;
if ( V_5 -> V_171 == 1 )
F_64 ( V_180 , V_46 -> V_181 ) ;
}
F_11 ( V_81 , & V_5 -> V_29 ) ;
exit:
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_172 * V_173 , struct V_88 * V_89 ,
struct V_90 * V_91 , unsigned long * * V_182 , int * F_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_92 & V_93 ) {
if ( ( V_5 -> V_92 & V_97 ) &&
( ( V_91 -> V_98 & V_99 ) == V_100 ) )
return 0 ;
return - 1 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , unsigned type ,
unsigned V_183 , struct V_85 * * V_18 )
{
int V_63 ;
* V_18 = V_2 -> V_184 [ type ] . V_185 [ V_183 ] ;
if ( * V_18 ) {
for ( V_63 = 0 ; V_63 < ( * V_18 ) -> V_186 ; V_63 ++ ) {
unsigned V_187 = ( * V_18 ) -> V_89 [ V_63 ] -> V_94 ;
if ( ( V_187 & V_99 ) >= V_188 )
return 1 ;
}
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , const struct V_189 * V_183 )
{
struct V_4 * V_5 = NULL ;
int V_13 ;
T_4 V_190 ;
struct V_85 * V_191 ;
struct V_85 * V_192 ;
struct V_85 * V_193 ;
V_5 = F_73 ( & V_2 -> V_10 , sizeof( struct V_4 ) , V_194 ) ;
if ( ! V_5 )
return - V_195 ;
F_74 ( & V_5 -> V_58 , F_27 ) ;
V_5 -> V_2 = V_2 ;
F_75 ( V_2 , V_5 ) ;
V_2 -> V_196 |= V_197 ;
V_13 = F_76 ( V_2 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_45 ) ;
return V_13 ;
}
if ( V_183 -> V_198 )
V_5 -> V_92 = V_183 -> V_198 ;
if ( ! F_71 ( V_2 , V_16 ,
V_15 , & V_193 ) ) {
F_35 ( V_2 , L_46 ) ;
goto V_199;
}
if ( ! F_71 ( V_2 , V_200 ,
V_87 , & V_191 ) ) {
F_35 ( V_2 , L_47 ) ;
goto V_199;
}
V_5 -> V_83 = F_77 ( V_191 ) ;
if ( ! F_71 ( V_2 , V_201 ,
V_8 , & V_192 ) ) {
F_35 ( V_2 ,
L_48 ) ;
goto V_199;
}
V_5 -> V_9 = F_77 ( V_192 ) ;
V_5 -> V_92 |= V_93 ;
V_190 = V_5 -> V_9 + V_5 -> V_83 ;
V_5 -> V_7 = F_73 ( & V_2 -> V_10 , V_190 , V_194 ) ;
if ( ! V_5 -> V_7 ) {
V_13 = - V_195 ;
return V_13 ;
}
V_5 -> V_33 = V_5 -> V_7 + V_5 -> V_9 ;
F_78 ( & V_5 -> V_30 ) ;
F_79 ( & V_5 -> V_26 ) ;
V_199:
V_13 = F_80 ( V_2 , V_202 ) ;
if ( V_13 ) {
F_53 ( V_2 , L_49 ) ;
return V_13 ;
}
if ( ( V_5 -> V_92 & V_93 ) &&
! F_14 ( V_81 , & V_5 -> V_29 ) )
F_53 ( V_2 , L_50 ) ;
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
F_12 ( V_81 , & V_34 -> V_29 ) ;
F_82 ( V_2 ) ;
}
