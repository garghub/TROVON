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
if ( V_61 < V_34 -> V_64 . V_65 )
return 0 ;
if ( ! ( V_60 & V_34 -> V_64 . V_66 ) )
return 0 ;
V_62 = ( V_34 -> V_67 >> 2 ) + 1 ;
for ( V_63 = 0 ; V_63 < V_34 -> V_67 ; V_63 ++ ) {
int V_68 = V_63 >> 2 ;
int V_69 = ( V_63 & 0x3 ) << 1 ;
int V_36 = ( V_5 [ V_68 ] >> V_69 ) &
0x03 ;
F_19 ( V_34 , V_63 , V_36 ,
& V_5 [ V_62 + 5 * V_63 ] ) ;
}
F_30 ( V_34 -> V_46 ) ;
F_31 ( V_34 -> V_46 ) ;
return V_34 -> V_64 . V_65 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_60 , T_1 * V_5 ,
int V_61 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
int V_63 ;
int V_70 = 0 ;
bool V_71 ;
if ( ! ( V_60 & V_34 -> V_72 . V_66 ) )
return 0 ;
for ( V_63 = 0 ; V_63 < V_34 -> V_73 ; V_63 ++ ) {
if ( F_14 ( V_63 , & V_34 -> V_74 ) ) {
V_71 = ( V_5 [ V_63 / 8 ] >> ( V_63 & 0x07 ) ) & F_33 ( 0 ) ;
if ( F_14 ( V_63 , & V_34 -> V_75 ) )
V_71 = ! V_71 ;
F_24 ( V_34 -> V_46 , V_76 , V_77 + V_70 ++ ,
V_71 ) ;
}
}
return V_34 -> V_72 . V_65 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 * V_5 , int V_61 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
unsigned long V_66 = 0 ;
unsigned V_78 = 2 ;
if ( ! ( F_14 ( V_79 , & V_34 -> V_29 ) ) )
return 0 ;
V_66 |= V_34 -> V_64 . V_66 ;
V_66 |= V_34 -> V_72 . V_66 ;
if ( V_5 [ 1 ] & ~ V_66 )
F_16 ( V_2 , L_6 ,
V_5 [ 1 ] & ~ V_66 , __FILE__ , __LINE__ ) ;
if ( V_34 -> V_64 . V_80 < V_34 -> V_72 . V_80 ) {
V_78 += F_29 ( V_2 , V_5 [ 1 ] , & V_5 [ V_78 ] ,
V_61 - V_78 ) ;
V_78 += F_32 ( V_2 , V_5 [ 1 ] , & V_5 [ V_78 ] ,
V_61 - V_78 ) ;
} else {
V_78 += F_32 ( V_2 , V_5 [ 1 ] , & V_5 [ V_78 ] ,
V_61 - V_78 ) ;
V_78 += F_29 ( V_2 , V_5 [ 1 ] , & V_5 [ V_78 ] ,
V_61 - V_78 ) ;
}
return 1 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 * V_5 , int V_61 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
if ( ! F_14 ( V_28 , & V_34 -> V_29 ) ) {
F_36 ( V_2 , L_7 ) ;
return 0 ;
}
memcpy ( V_34 -> V_33 , V_5 , V_61 < V_34 -> V_81 ?
V_61 : V_34 -> V_81 ) ;
F_11 ( V_31 , & V_34 -> V_29 ) ;
F_37 ( & V_34 -> V_30 ) ;
return 1 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_82 * V_18 , T_1 * V_5 , int V_61 )
{
switch ( V_5 [ 0 ] ) {
case V_83 :
return F_35 ( V_2 , V_5 , V_61 ) ;
case V_84 :
return F_34 ( V_2 , V_5 , V_61 ) ;
case V_85 :
F_27 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_59 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_59 ) ;
}
static inline unsigned long F_41 ( unsigned V_86 , unsigned V_87 )
{
return F_42 ( V_87 + V_86 - 1 , V_86 ) ;
}
static void F_43 ( struct V_4 * V_5 ,
struct V_88 * V_88 , int V_3 , unsigned V_89 )
{
struct V_90 * V_91 = NULL ;
T_2 V_92 = V_3 << 8 ;
switch ( V_88 -> V_93 ) {
case 0x11 :
V_91 = & V_5 -> V_64 ;
break;
case 0x30 :
V_91 = & V_5 -> V_72 ;
break;
}
if ( V_91 ) {
V_91 -> V_3 = V_3 ;
V_91 -> V_94 = V_92 | V_88 -> V_94 ;
V_91 -> V_95 = V_92 | V_88 -> V_95 ;
V_91 -> V_96 = V_92 | V_88 -> V_96 ;
V_91 -> V_97 = V_92 | V_88 -> V_97 ;
V_91 -> V_80 = V_89 ;
V_91 -> V_89 = V_88 -> V_98 ;
V_91 -> V_66 = F_41 ( V_91 -> V_80 ,
V_91 -> V_89 ) ;
}
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_88 V_99 ;
int V_3 ;
bool V_100 ;
int V_63 ;
int V_6 ;
int V_101 = 0 ;
T_2 V_102 , V_103 , V_104 ;
F_45 ( V_2 , L_8 ) ;
for ( V_3 = 0 ; ( V_3 <= V_105 ) ; V_3 ++ ) {
V_102 = V_106 * V_3 ;
V_103 = V_102 + V_107 ;
V_104 = V_102 + V_108 ;
V_100 = false ;
for ( V_63 = V_103 ; V_63 >= V_104 ; V_63 -= sizeof( V_99 ) ) {
V_6 = F_8 ( V_2 , V_63 , & V_99 , sizeof( V_99 ) ) ;
if ( V_6 ) {
F_36 ( V_2 ,
L_9 ,
V_63 ) ;
goto V_109;
}
if ( F_46 ( V_99 . V_93 ) )
break;
V_100 = true ;
F_45 ( V_2 , L_10 ,
V_99 . V_93 , V_3 ) ;
F_43 ( V_5 , & V_99 , V_3 , V_101 ) ;
V_101 += V_99 . V_98 ;
}
if ( ! V_100 )
break;
}
F_45 ( V_2 , L_11 , V_11 ) ;
V_6 = 0 ;
V_109:
return V_6 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_21 [ 20 ] ;
int V_13 ;
bool V_110 ;
bool V_111 ;
bool V_112 ;
bool V_113 ;
bool V_114 ;
unsigned V_115 , V_116 ;
T_2 V_117 ;
if ( ! V_5 -> V_64 . V_94 ) {
F_36 ( V_2 , L_12 ) ;
return - V_118 ;
}
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_94 , V_21 ) ;
if ( V_13 ) {
F_36 ( V_2 , L_13 , V_13 ) ;
return V_13 ;
}
V_110 = ! ! ( V_21 [ 0 ] & F_33 ( 3 ) ) ;
V_112 = ! ! ( V_21 [ 0 ] & F_33 ( 4 ) ) ;
V_113 = ! ! ( V_21 [ 0 ] & F_33 ( 5 ) ) ;
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_94 + 1 , V_21 ) ;
if ( V_13 ) {
F_36 ( V_2 , L_14 , V_13 ) ;
return V_13 ;
}
V_5 -> V_67 = ( V_21 [ 0 ] & 0x07 ) + 1 ;
if ( V_5 -> V_67 > 5 )
V_5 -> V_67 = 10 ;
V_5 -> V_64 . V_65 = V_5 -> V_67 * 5 +
F_48 ( V_5 -> V_67 , 4 ) ;
if ( ! ( V_21 [ 0 ] & F_33 ( 4 ) ) ) {
F_36 ( V_2 , L_15 ) ;
return - V_118 ;
}
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_94 + 8 , V_21 ) ;
if ( V_13 ) {
F_36 ( V_2 , L_16 , V_13 ) ;
return V_13 ;
}
V_111 = ! ! ( V_21 [ 0 ] & F_33 ( 2 ) ) ;
V_117 = 9 ;
if ( V_110 )
++ V_117 ;
if ( V_111 )
++ V_117 ;
if ( V_112 )
++ V_117 ;
if ( V_113 ) {
V_13 = F_18 ( V_2 , V_5 -> V_64 . V_94
+ V_117 , V_21 ) ;
if ( V_13 ) {
F_36 ( V_2 , L_17 , V_13 ) ;
return V_13 ;
}
V_114 = ! ! ( V_21 [ 0 ] & F_33 ( 5 ) ) ;
if ( V_114 ) {
V_13 = F_8 ( V_2 ,
V_5 -> V_64 . V_94
+ V_117 + 1 , V_21 , 4 ) ;
if ( V_13 ) {
F_36 ( V_2 , L_18 ,
V_13 ) ;
return V_13 ;
}
V_115 = V_21 [ 0 ] | ( V_21 [ 1 ] << 8 ) ;
V_116 = V_21 [ 2 ] | ( V_21 [ 3 ] << 8 ) ;
V_5 -> V_119 = F_49 ( V_115 , 10 ) ;
V_5 -> V_120 = F_49 ( V_116 , 10 ) ;
F_45 ( V_2 , L_19 ,
V_11 , V_5 -> V_119 , V_5 -> V_120 ) ;
}
}
V_13 = F_8 ( V_2 , V_5 -> V_64 . V_96 , V_21 , 10 ) ;
if ( V_13 ) {
F_36 ( V_2 , L_20 , V_13 ) ;
return V_13 ;
}
V_5 -> V_121 = V_21 [ 6 ] | ( V_21 [ 7 ] << 8 ) ;
V_5 -> V_48 = V_21 [ 8 ] | ( V_21 [ 9 ] << 8 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_21 [ 20 ] ;
int V_13 ;
bool V_122 , V_123 ;
unsigned V_124 ;
T_1 V_125 ;
int V_126 ;
int V_63 ;
if ( ! V_5 -> V_72 . V_94 ) {
F_36 ( V_2 , L_21 ) ;
return - V_118 ;
}
V_13 = F_8 ( V_2 , V_5 -> V_72 . V_94 , V_21 , 2 ) ;
if ( V_13 ) {
F_36 ( V_2 , L_22 , V_13 ) ;
return V_13 ;
}
V_122 = ! ! ( V_21 [ 0 ] & F_33 ( 3 ) ) ;
V_123 = ! ! ( V_21 [ 0 ] & F_33 ( 2 ) ) ;
V_5 -> V_73 = V_21 [ 1 ] & 0x1f ;
V_124 = ( V_5 -> V_73 + 7 ) / 8 ;
V_125 = ( V_122 && V_123 ) ? V_124 : 0 ;
V_125 += V_124 ;
V_126 = 2 * V_124 ;
V_5 -> V_72 . V_65 = V_124 ;
V_13 = F_8 ( V_2 , V_5 -> V_72 . V_96 + V_125 ,
V_21 , V_126 ) ;
if ( V_13 ) {
F_36 ( V_2 , L_23 ,
V_126 , V_13 ) ;
return V_13 ;
}
for ( V_63 = 0 ; V_63 < V_5 -> V_73 ; V_63 ++ ) {
int V_127 = V_63 >> 3 ;
int V_128 = V_63 & 0x07 ;
T_1 V_129 = V_21 [ V_127 ] ;
T_1 V_130 = V_21 [ V_127 + V_124 ] ;
bool V_131 = ( V_129 >> V_128 ) & F_33 ( 0 ) ;
bool V_132 = ( V_130 >> V_128 ) & F_33 ( 0 ) ;
if ( V_131 == 0 ) {
if ( V_132 ) {
V_5 -> V_133 ++ ;
F_11 ( V_63 , & V_5 -> V_74 ) ;
F_11 ( V_63 , & V_5 -> V_75 ) ;
}
}
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_44 ( V_2 ) ;
if ( V_13 ) {
F_36 ( V_2 , L_24 , V_13 ) ;
return V_13 ;
}
V_13 = F_47 ( V_2 ) ;
if ( V_13 ) {
F_36 ( V_2 , L_25 , V_13 ) ;
return V_13 ;
}
V_13 = F_50 ( V_2 ) ;
if ( V_13 )
F_16 ( V_2 , L_26 , V_13 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 , struct V_134 * V_135 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_136 * V_46 = V_135 -> V_46 ;
int V_13 ;
int V_137 , V_138 , V_63 ;
V_5 -> V_46 = V_46 ;
F_53 ( V_2 , L_27 ) ;
V_13 = F_54 ( V_2 ) ;
if ( V_13 )
return;
F_55 ( V_2 ) ;
V_13 = F_5 ( V_2 , V_59 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_28 ) ;
goto exit;
}
V_13 = F_1 ( V_2 , 0 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_10 , L_29 ) ;
goto exit;
}
V_13 = F_51 ( V_2 ) ;
if ( V_13 )
goto exit;
F_56 ( V_49 , V_46 -> V_139 ) ;
F_57 ( V_46 , V_50 , 1 , V_5 -> V_121 , 0 , 0 ) ;
F_57 ( V_46 , V_51 , 1 , V_5 -> V_48 , 0 , 0 ) ;
if ( V_5 -> V_119 && V_5 -> V_120 ) {
V_137 = ( V_5 -> V_121 - 1 ) / V_5 -> V_119 ;
V_138 = ( V_5 -> V_48 - 1 ) / V_5 -> V_120 ;
F_58 ( V_46 , V_50 , V_137 ) ;
F_58 ( V_46 , V_51 , V_138 ) ;
}
F_57 ( V_46 , V_52 , 0 , 1 , 0 , 0 ) ;
F_57 ( V_46 , V_53 , 0 , 0xff , 0 , 0 ) ;
F_57 ( V_46 , V_54 , 0 , 0x0f , 0 , 0 ) ;
F_57 ( V_46 , V_55 , 0 , 0x0f , 0 , 0 ) ;
F_59 ( V_46 , V_5 -> V_67 , V_140 ) ;
if ( V_5 -> V_133 ) {
F_56 ( V_76 , V_46 -> V_139 ) ;
for ( V_63 = 0 ; V_63 < V_5 -> V_133 ; V_63 ++ )
F_56 ( V_77 + V_63 , V_46 -> V_141 ) ;
if ( V_5 -> V_133 == 1 )
F_56 ( V_142 , V_46 -> V_143 ) ;
}
F_11 ( V_79 , & V_5 -> V_29 ) ;
exit:
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_134 * V_135 , struct V_144 * V_145 ,
struct V_146 * V_147 , unsigned long * * V_148 , int * F_22 )
{
return - 1 ;
}
static int F_63 ( struct V_1 * V_2 , const struct V_149 * V_150 )
{
struct V_4 * V_5 = NULL ;
int V_13 ;
T_3 V_151 ;
V_5 = F_64 ( & V_2 -> V_10 , sizeof( struct V_4 ) , V_152 ) ;
if ( ! V_5 )
return - V_153 ;
F_65 ( & V_5 -> V_58 , F_25 ) ;
V_5 -> V_2 = V_2 ;
F_66 ( V_2 , V_5 ) ;
V_2 -> V_154 |= V_155 ;
V_13 = F_67 ( V_2 ) ;
if ( V_13 ) {
F_36 ( V_2 , L_30 ) ;
return V_13 ;
}
V_5 -> V_81 = ( V_2 -> V_156 [ V_157 ]
. V_158 [ V_84 ] -> V_61 >> 3 )
+ 1 ;
V_5 -> V_9 = ( V_2 -> V_156 [ V_159 ]
. V_158 [ V_8 ] -> V_61 >> 3 )
+ 1 ;
V_151 = V_5 -> V_9 + V_5 -> V_81 ;
V_5 -> V_7 = F_64 ( & V_2 -> V_10 , V_151 , V_152 ) ;
if ( ! V_5 -> V_7 ) {
V_13 = - V_153 ;
return V_13 ;
}
V_5 -> V_33 = V_5 -> V_7 + V_5 -> V_9 ;
F_68 ( & V_5 -> V_30 ) ;
F_69 ( & V_5 -> V_26 ) ;
V_13 = F_70 ( V_2 , V_160 ) ;
if ( V_13 ) {
F_36 ( V_2 , L_31 ) ;
return V_13 ;
}
if ( ! F_14 ( V_79 , & V_5 -> V_29 ) ) {
F_71 ( V_2 ) ;
return - V_161 ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_4 * V_34 = F_2 ( V_2 ) ;
F_12 ( V_79 , & V_34 -> V_29 ) ;
F_71 ( V_2 ) ;
}
