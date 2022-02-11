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
static void F_19 ( struct V_4 * V_34 , int V_35 ,
T_1 V_36 , T_1 * V_37 )
{
int V_38 , V_39 , V_40 , V_41 ;
int V_42 , V_43 , V_44 ;
int V_45 ;
F_20 ( V_34 -> V_46 , V_35 ) ;
F_21 ( V_34 -> V_46 , V_47 ,
V_36 == 0x01 ) ;
if ( V_36 == 0x01 ) {
V_38 = ( V_37 [ 0 ] << 4 ) | ( V_37 [ 2 ] & 0x0F ) ;
V_39 = ( V_37 [ 1 ] << 4 ) | ( V_37 [ 2 ] >> 4 ) ;
V_40 = V_37 [ 3 ] & 0x0F ;
V_41 = V_37 [ 3 ] >> 4 ;
V_42 = ( V_40 > V_41 ) ;
V_43 = F_22 ( V_40 , V_41 ) ;
V_44 = F_23 ( V_40 , V_41 ) ;
V_45 = V_37 [ 4 ] ;
V_39 = V_34 -> V_48 - V_39 ;
F_24 ( V_34 -> V_46 , V_49 , V_50 , V_38 ) ;
F_24 ( V_34 -> V_46 , V_49 , V_51 , V_39 ) ;
F_24 ( V_34 -> V_46 , V_49 , V_52 , V_42 ) ;
F_24 ( V_34 -> V_46 , V_49 , V_53 , V_45 ) ;
F_24 ( V_34 -> V_46 , V_49 , V_54 , V_43 ) ;
F_24 ( V_34 -> V_46 , V_49 , V_55 , V_44 ) ;
}
}
static void F_25 ( struct V_56 * V_57 )
{
struct V_4 * V_34 = F_26 ( V_57 , struct V_4 ,
V_58 ) ;
F_5 ( V_34 -> V_2 , V_59 ) ;
}
static inline int F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
return F_28 ( & V_34 -> V_58 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_60 , T_1 * V_5 ,
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
F_30 ( V_70
L_6 ,
F_31 ( & V_2 -> V_10 ) ,
F_32 ( & V_2 -> V_10 ) ) ;
F_33 ( V_2 , L_7 ) ;
break;
}
F_19 ( V_34 , V_63 , V_36 , & V_5 [ V_69 ] ) ;
}
F_34 ( V_34 -> V_46 ) ;
F_35 ( V_34 -> V_46 ) ;
return V_34 -> V_64 . V_71 ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_60 , T_1 * V_5 ,
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
V_73 = ( V_5 [ V_63 / 8 ] >> ( V_63 & 0x07 ) ) & F_37 ( 0 ) ;
if ( F_14 ( V_63 , & V_34 -> V_77 ) )
V_73 = ! V_73 ;
F_24 ( V_34 -> V_46 , V_78 , V_79 + V_72 ++ ,
V_73 ) ;
}
}
return V_34 -> V_74 . V_71 ;
}
static int F_38 ( struct V_1 * V_2 , T_1 * V_5 , int V_61 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
unsigned long V_65 = 0 ;
unsigned V_80 = 2 ;
if ( ! ( F_14 ( V_81 , & V_34 -> V_29 ) ) )
return 0 ;
V_65 |= V_34 -> V_64 . V_65 ;
V_65 |= V_34 -> V_74 . V_65 ;
if ( V_5 [ 1 ] & ~ V_65 )
F_33 ( V_2 , L_9 ,
V_5 [ 1 ] & ~ V_65 , __FILE__ , __LINE__ ) ;
if ( V_34 -> V_64 . V_82 < V_34 -> V_74 . V_82 ) {
V_80 += F_29 ( V_2 , V_5 [ 1 ] , & V_5 [ V_80 ] ,
V_61 - V_80 ) ;
V_80 += F_36 ( V_2 , V_5 [ 1 ] , & V_5 [ V_80 ] ,
V_61 - V_80 ) ;
} else {
V_80 += F_36 ( V_2 , V_5 [ 1 ] , & V_5 [ V_80 ] ,
V_61 - V_80 ) ;
V_80 += F_29 ( V_2 , V_5 [ 1 ] , & V_5 [ V_80 ] ,
V_61 - V_80 ) ;
}
return 1 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 * V_5 , int V_61 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
if ( ! F_14 ( V_28 , & V_34 -> V_29 ) ) {
F_33 ( V_2 , L_10 ) ;
return 0 ;
}
memcpy ( V_34 -> V_33 , V_5 , V_61 < V_34 -> V_83 ?
V_61 : V_34 -> V_83 ) ;
F_11 ( V_31 , & V_34 -> V_29 ) ;
F_40 ( & V_34 -> V_30 ) ;
return 1 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 * V_5 , int V_61 )
{
int V_84 = V_61 ;
while ( ( V_5 [ V_84 - 1 ] == 0xff ) && V_84 > 0 )
V_84 -- ;
return V_84 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_85 * V_18 , T_1 * V_5 , int V_61 )
{
V_61 = F_41 ( V_2 , V_5 , V_61 ) ;
if ( V_61 < 2 )
return 0 ;
switch ( V_5 [ 0 ] ) {
case V_86 :
return F_39 ( V_2 , V_5 , V_61 ) ;
case V_87 :
return F_38 ( V_2 , V_5 , V_61 ) ;
case V_88 :
F_27 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_59 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_59 ) ;
}
static inline unsigned long F_45 ( unsigned V_89 , unsigned V_90 )
{
return F_46 ( V_90 + V_89 - 1 , V_89 ) ;
}
static void F_47 ( struct V_4 * V_5 ,
struct V_91 * V_91 , int V_3 , unsigned V_92 )
{
struct V_93 * V_94 = NULL ;
T_2 V_95 = V_3 << 8 ;
switch ( V_91 -> V_96 ) {
case 0x11 :
V_94 = & V_5 -> V_64 ;
break;
case 0x30 :
V_94 = & V_5 -> V_74 ;
break;
}
if ( V_94 ) {
V_94 -> V_3 = V_3 ;
V_94 -> V_97 = V_95 | V_91 -> V_97 ;
V_94 -> V_98 = V_95 | V_91 -> V_98 ;
V_94 -> V_99 = V_95 | V_91 -> V_99 ;
V_94 -> V_100 = V_95 | V_91 -> V_100 ;
V_94 -> V_82 = V_92 ;
V_94 -> V_92 = V_91 -> V_101 ;
V_94 -> V_65 = F_45 ( V_94 -> V_82 ,
V_94 -> V_92 ) ;
}
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_91 V_102 ;
int V_3 ;
bool V_103 ;
int V_63 ;
int V_6 ;
int V_104 = 0 ;
T_2 V_105 , V_106 , V_107 ;
F_49 ( V_2 , L_11 ) ;
for ( V_3 = 0 ; ( V_3 <= V_108 ) ; V_3 ++ ) {
V_105 = V_109 * V_3 ;
V_106 = V_105 + V_110 ;
V_107 = V_105 + V_111 ;
V_103 = false ;
for ( V_63 = V_106 ; V_63 >= V_107 ; V_63 -= sizeof( V_102 ) ) {
V_6 = F_8 ( V_2 , V_63 , & V_102 , sizeof( V_102 ) ) ;
if ( V_6 ) {
F_50 ( V_2 ,
L_12 ,
V_63 ) ;
goto V_112;
}
if ( F_51 ( V_102 . V_96 ) )
break;
V_103 = true ;
F_49 ( V_2 , L_13 ,
V_102 . V_96 , V_3 ) ;
F_47 ( V_5 , & V_102 , V_3 , V_104 ) ;
V_104 += V_102 . V_101 ;
}
if ( ! V_103 )
break;
}
F_49 ( V_2 , L_14 , V_11 ) ;
V_6 = 0 ;
V_112:
return V_6 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_21 [ 20 ] ;
int V_13 ;
bool V_113 ;
bool V_114 = false ;
bool V_115 ;
bool V_116 ;
bool V_117 ;
bool V_118 ;
bool V_119 = false ;
bool V_120 ;
bool V_121 ;
bool V_122 ;
bool V_123 = false ;
unsigned V_124 , V_125 ;
T_2 V_126 ;
if ( ! V_5 -> V_64 . V_97 ) {
F_50 ( V_2 , L_15 ) ;
return - V_127 ;
}
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_97 , V_21 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_16 , V_13 ) ;
return V_13 ;
}
V_113 = ! ! ( V_21 [ 0 ] & F_37 ( 3 ) ) ;
V_115 = ! ! ( V_21 [ 0 ] & F_37 ( 4 ) ) ;
V_116 = ! ! ( V_21 [ 0 ] & F_37 ( 5 ) ) ;
V_117 = ! ! ( V_21 [ 0 ] & F_37 ( 6 ) ) ;
V_118 = ! ! ( V_21 [ 0 ] & F_37 ( 7 ) ) ;
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_97 + 1 , V_21 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_17 , V_13 ) ;
return V_13 ;
}
V_5 -> V_66 = ( V_21 [ 0 ] & 0x07 ) + 1 ;
if ( V_5 -> V_66 > 5 )
V_5 -> V_66 = 10 ;
V_5 -> V_64 . V_71 = V_5 -> V_66 * 5 +
F_53 ( V_5 -> V_66 , 4 ) ;
if ( ! ( V_21 [ 0 ] & F_37 ( 4 ) ) ) {
F_50 ( V_2 , L_18 ) ;
return - V_127 ;
}
V_122 = ! ! ( V_21 [ 0 ] & F_37 ( 3 ) ) ;
V_121 = ! ! ( V_21 [ 0 ] & F_37 ( 5 ) ) ;
V_126 = 6 ;
if ( V_122 )
++ V_126 ;
if ( V_121 ) {
V_13 = F_18 ( V_2 ,
V_5 -> V_64 . V_97 + V_126 + 1 , V_21 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_19 ,
V_13 ) ;
return V_13 ;
}
V_114 = ! ! ( V_21 [ 0 ] & F_37 ( 2 ) ) ;
V_126 += 2 ;
}
if ( V_113 )
++ V_126 ;
if ( V_114 )
++ V_126 ;
if ( V_115 )
++ V_126 ;
if ( V_116 ) {
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_97
+ V_126 , V_21 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_20 , V_13 ) ;
return V_13 ;
}
V_120 = ! ! ( V_21 [ 0 ] & F_37 ( 5 ) ) ;
if ( V_120 ) {
V_126 += 1 ;
V_13 = F_8 ( V_2 ,
V_5 -> V_64 . V_97
+ V_126 , V_21 , 4 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_21 ,
V_13 ) ;
return V_13 ;
}
V_124 = V_21 [ 0 ] | ( V_21 [ 1 ] << 8 ) ;
V_125 = V_21 [ 2 ] | ( V_21 [ 3 ] << 8 ) ;
V_5 -> V_128 = F_54 ( V_124 , 10 ) ;
V_5 -> V_129 = F_54 ( V_125 , 10 ) ;
F_49 ( V_2 , L_22 ,
V_11 , V_5 -> V_128 , V_5 -> V_129 ) ;
V_126 += 12 ;
}
}
if ( V_117 )
++ V_126 ;
if ( V_118 ) {
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_97
+ V_126 , V_21 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_23 , V_13 ) ;
return V_13 ;
}
V_119 = ! ! ( V_21 [ 0 ] & F_37 ( 6 ) ) ;
}
if ( V_119 ) {
V_126 += 2 ;
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_97
+ V_126 , V_21 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_24 , V_13 ) ;
return V_13 ;
}
V_123 = ! ! ( V_21 [ 0 ] & F_37 ( 5 ) ) ;
}
if ( V_123 )
V_5 -> V_64 . V_71 += V_5 -> V_66 * 2 ;
V_13 = F_8 ( V_2 , V_5 -> V_64 . V_99 , V_21 , 10 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_25 , V_13 ) ;
return V_13 ;
}
V_5 -> V_130 = V_21 [ 6 ] | ( V_21 [ 7 ] << 8 ) ;
V_5 -> V_48 = V_21 [ 8 ] | ( V_21 [ 9 ] << 8 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_21 [ 20 ] ;
int V_13 ;
bool V_131 , V_132 ;
unsigned V_133 ;
T_1 V_134 ;
int V_135 ;
int V_63 ;
if ( ! V_5 -> V_74 . V_97 ) {
F_50 ( V_2 , L_26 ) ;
return - V_127 ;
}
V_13 = F_8 ( V_2 , V_5 -> V_74 . V_97 , V_21 , 2 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_27 , V_13 ) ;
return V_13 ;
}
V_131 = ! ! ( V_21 [ 0 ] & F_37 ( 3 ) ) ;
V_132 = ! ! ( V_21 [ 0 ] & F_37 ( 2 ) ) ;
V_5 -> V_75 = V_21 [ 1 ] & 0x1f ;
V_133 = ( V_5 -> V_75 + 7 ) / 8 ;
V_134 = ( V_131 && V_132 ) ? V_133 : 0 ;
V_134 += V_133 ;
V_135 = 2 * V_133 ;
V_5 -> V_74 . V_71 = V_133 ;
V_13 = F_8 ( V_2 , V_5 -> V_74 . V_99 + V_134 ,
V_21 , V_135 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_28 ,
V_135 , V_13 ) ;
return V_13 ;
}
for ( V_63 = 0 ; V_63 < V_5 -> V_75 ; V_63 ++ ) {
int V_136 = V_63 >> 3 ;
int V_137 = V_63 & 0x07 ;
T_1 V_138 = V_21 [ V_136 ] ;
T_1 V_139 = V_21 [ V_136 + V_133 ] ;
bool V_140 = ( V_138 >> V_137 ) & F_37 ( 0 ) ;
bool V_141 = ( V_139 >> V_137 ) & F_37 ( 0 ) ;
if ( V_140 == 0 ) {
if ( V_141 ) {
V_5 -> V_142 ++ ;
F_11 ( V_63 , & V_5 -> V_76 ) ;
F_11 ( V_63 , & V_5 -> V_77 ) ;
}
}
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_48 ( V_2 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_29 , V_13 ) ;
return V_13 ;
}
V_13 = F_52 ( V_2 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_30 , V_13 ) ;
return V_13 ;
}
V_13 = F_55 ( V_2 ) ;
if ( V_13 )
F_16 ( V_2 , L_31 , V_13 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , struct V_143 * V_144 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_145 * V_46 = V_144 -> V_46 ;
int V_13 ;
int V_146 , V_147 , V_63 ;
V_5 -> V_46 = V_46 ;
F_33 ( V_2 , L_32 ) ;
V_13 = F_58 ( V_2 ) ;
if ( V_13 )
return;
F_59 ( V_2 ) ;
V_13 = F_5 ( V_2 , V_59 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_33 ) ;
goto exit;
}
V_13 = F_1 ( V_2 , 0 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_34 ) ;
goto exit;
}
V_13 = F_56 ( V_2 ) ;
if ( V_13 )
goto exit;
F_60 ( V_49 , V_46 -> V_148 ) ;
F_61 ( V_46 , V_50 , 1 , V_5 -> V_130 , 0 , 0 ) ;
F_61 ( V_46 , V_51 , 1 , V_5 -> V_48 , 0 , 0 ) ;
if ( V_5 -> V_128 && V_5 -> V_129 ) {
V_146 = ( V_5 -> V_130 - 1 ) / V_5 -> V_128 ;
V_147 = ( V_5 -> V_48 - 1 ) / V_5 -> V_129 ;
F_62 ( V_46 , V_50 , V_146 ) ;
F_62 ( V_46 , V_51 , V_147 ) ;
}
F_61 ( V_46 , V_52 , 0 , 1 , 0 , 0 ) ;
F_61 ( V_46 , V_53 , 0 , 0xff , 0 , 0 ) ;
F_61 ( V_46 , V_54 , 0 , 0x0f , 0 , 0 ) ;
F_61 ( V_46 , V_55 , 0 , 0x0f , 0 , 0 ) ;
F_63 ( V_46 , V_5 -> V_66 , V_149 ) ;
if ( V_5 -> V_142 ) {
F_60 ( V_78 , V_46 -> V_148 ) ;
for ( V_63 = 0 ; V_63 < V_5 -> V_142 ; V_63 ++ )
F_60 ( V_79 + V_63 , V_46 -> V_150 ) ;
if ( V_5 -> V_142 == 1 )
F_60 ( V_151 , V_46 -> V_152 ) ;
}
F_11 ( V_81 , & V_5 -> V_29 ) ;
exit:
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_143 * V_144 , struct V_153 * V_154 ,
struct V_155 * V_156 , unsigned long * * V_157 , int * F_22 )
{
return - 1 ;
}
static int F_67 ( struct V_1 * V_2 , const struct V_158 * V_159 )
{
struct V_4 * V_5 = NULL ;
int V_13 ;
T_3 V_160 ;
struct V_85 * V_161 ;
struct V_85 * V_162 ;
V_5 = F_68 ( & V_2 -> V_10 , sizeof( struct V_4 ) , V_163 ) ;
if ( ! V_5 )
return - V_164 ;
F_69 ( & V_5 -> V_58 , F_25 ) ;
V_5 -> V_2 = V_2 ;
F_70 ( V_2 , V_5 ) ;
V_2 -> V_165 |= V_166 ;
V_13 = F_71 ( V_2 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_35 ) ;
return V_13 ;
}
V_161 = V_2 -> V_167 [ V_168 ]
. V_169 [ V_87 ] ;
if ( ! V_161 ) {
F_50 ( V_2 , L_36 ) ;
V_13 = - V_127 ;
return V_13 ;
}
V_5 -> V_83 = ( V_161 -> V_61 >> 3 ) + 1 ;
V_162 = V_2 -> V_167 [ V_170 ]
. V_169 [ V_8 ] ;
if ( ! V_162 ) {
F_50 ( V_2 , L_37 ) ;
V_13 = - V_127 ;
return V_13 ;
}
V_5 -> V_9 = ( V_162 -> V_61 >> 3 )
+ 1 ;
V_160 = V_5 -> V_9 + V_5 -> V_83 ;
V_5 -> V_7 = F_68 ( & V_2 -> V_10 , V_160 , V_163 ) ;
if ( ! V_5 -> V_7 ) {
V_13 = - V_164 ;
return V_13 ;
}
V_5 -> V_33 = V_5 -> V_7 + V_5 -> V_9 ;
F_72 ( & V_5 -> V_30 ) ;
F_73 ( & V_5 -> V_26 ) ;
V_13 = F_74 ( V_2 , V_171 ) ;
if ( V_13 ) {
F_50 ( V_2 , L_38 ) ;
return V_13 ;
}
if ( ! F_14 ( V_81 , & V_5 -> V_29 ) )
F_50 ( V_2 , L_39 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
F_12 ( V_81 , & V_34 -> V_29 ) ;
F_76 ( V_2 ) ;
}
