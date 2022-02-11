static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 * F_3 ( struct V_2 * V_4 , const T_1 * V_5 , int V_6 )
{
return ( T_1 * ) V_5 + V_6 * V_4 -> V_7 . V_8 ;
}
static inline T_1 * F_4 ( struct V_2 * V_4 , int V_6 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
T_1 * V_10 ;
if ( V_6 < V_9 -> V_11 . V_12 )
V_10 = V_4 -> V_13 + ( V_6 + 1 ) * V_9 -> V_14 . V_15 ;
else if ( V_6 == V_9 -> V_11 . V_12 )
V_10 = V_4 -> V_13 ;
else
V_10 = V_4 -> V_13 + V_6 * V_9 -> V_14 . V_15 ;
return V_10 ;
}
static inline int F_5 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
return V_4 -> V_7 . V_8 + V_9 -> V_16 ;
}
static inline T_1 * F_6 ( struct V_2 * V_4 , int V_6 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
return V_18 -> V_19 + V_6 * F_5 ( V_4 ) ;
}
static inline T_1 * F_8 ( struct V_2 * V_4 , int V_6 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
return V_18 -> V_19 + V_6 * F_5 ( V_4 ) + V_4 -> V_7 . V_8 ;
}
static inline void F_9 ( struct V_17 * V_18 , T_2 V_20 , T_2 V_21 )
{
F_10 ( V_20 , V_18 -> V_22 + V_21 ) ;
}
static inline void F_11 ( struct V_17 * V_18 , T_3 V_20 , T_2 V_21 )
{
F_12 ( V_20 , V_18 -> V_22 + V_21 ) ;
}
static inline void F_13 ( struct V_17 * V_18 , T_1 V_20 , T_2 V_21 )
{
F_14 ( V_20 , V_18 -> V_22 + V_21 ) ;
}
static inline T_2 F_15 ( struct V_17 * V_18 , T_2 V_21 )
{
return F_16 ( V_18 -> V_22 + V_21 ) ;
}
static inline T_3 F_17 ( struct V_17 * V_18 , T_2 V_21 )
{
return F_18 ( V_18 -> V_22 + V_21 ) ;
}
static inline T_1 F_19 ( struct V_17 * V_18 , T_2 V_21 )
{
return F_20 ( V_18 -> V_22 + V_21 ) ;
}
static void F_21 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = V_18 -> V_24 ;
T_2 V_20 ;
int V_25 ;
F_9 ( V_18 , V_26 | V_27 , V_28 ) ;
V_25 = F_22 ( V_18 -> V_22 + V_29 , V_20 ,
! ( V_20 & V_30 ) , 50 ,
V_31 ) ;
if ( V_25 )
F_23 ( V_24 , L_1 ,
V_29 , V_20 ) ;
F_9 ( V_18 , V_26 | V_27 , V_28 ) ;
F_11 ( V_18 , V_32 , V_33 ) ;
}
static int F_24 ( struct V_17 * V_18 , T_1 V_34 )
{
struct V_23 * V_24 = V_18 -> V_24 ;
T_2 V_20 ;
int V_25 ;
F_9 ( V_18 , V_34 , V_35 ) ;
V_25 = F_25 ( V_18 -> V_22 + V_36 , V_20 ,
! ( V_20 & V_37 ) , 10 , V_38 ) ;
if ( V_25 ) {
F_23 ( V_24 , L_2 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_26 ( struct V_17 * V_18 , int V_40 )
{
struct V_23 * V_24 = V_18 -> V_24 ;
T_2 V_20 ;
int V_25 ;
F_9 ( V_18 , V_40 , V_41 ) ;
F_9 ( V_18 , 0 , V_42 ) ;
F_11 ( V_18 , 1 , V_43 ) ;
V_25 = F_25 ( V_18 -> V_22 + V_36 , V_20 ,
! ( V_20 & V_44 ) , 10 , V_38 ) ;
if ( V_25 ) {
F_23 ( V_24 , L_3 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_27 ( struct V_45 * V_46 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_17 * V_18 = F_7 ( V_4 ) ;
T_2 V_47 , V_48 , V_6 ;
if ( ! V_46 -> V_49 )
return 0 ;
V_48 = V_9 -> V_16 ;
switch ( V_46 -> V_49 ) {
case 512 :
V_47 = V_50 | V_51 ;
break;
case F_29 ( 2 ) :
if ( V_4 -> V_7 . V_8 == 512 )
V_47 = V_52 | V_51 ;
else
V_47 = V_50 ;
break;
case F_29 ( 4 ) :
if ( V_4 -> V_7 . V_8 == 512 )
V_47 = V_53 | V_51 ;
else
V_47 = V_52 ;
break;
case F_29 ( 8 ) :
if ( V_4 -> V_7 . V_8 == 512 )
V_47 = V_54 | V_51 ;
else
V_47 = V_53 ;
break;
case F_29 ( 16 ) :
V_47 = V_54 ;
break;
default:
F_30 ( V_18 -> V_24 , L_4 , V_46 -> V_49 ) ;
return - V_55 ;
}
if ( V_4 -> V_7 . V_8 == 1024 )
V_48 >>= 1 ;
for ( V_6 = 0 ; V_6 < V_18 -> V_56 -> V_57 ; V_6 ++ ) {
if ( V_18 -> V_56 -> V_58 [ V_6 ] == V_48 )
break;
}
if ( V_6 == V_18 -> V_56 -> V_57 ) {
F_30 ( V_18 -> V_24 , L_5 , V_48 ) ;
return - V_55 ;
}
V_47 |= V_6 << V_18 -> V_56 -> V_59 ;
V_47 |= V_9 -> V_14 . V_15 << V_60 ;
V_47 |= V_9 -> V_14 . V_61 << V_62 ;
F_9 ( V_18 , V_47 , V_63 ) ;
V_18 -> V_64 . V_65 = V_4 -> V_7 . V_65 ;
V_18 -> V_64 . V_66 = V_4 -> V_7 . V_8 + V_9 -> V_14 . V_61 ;
return 0 ;
}
static void F_31 ( struct V_45 * V_46 , int V_4 )
{
struct V_2 * V_3 = F_28 ( V_46 ) ;
struct V_17 * V_18 = F_7 ( V_3 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( V_4 < 0 )
return;
F_27 ( V_46 ) ;
F_9 ( V_18 , V_9 -> V_67 [ V_4 ] , V_68 ) ;
}
static int F_32 ( struct V_45 * V_46 )
{
struct V_17 * V_18 = F_7 ( F_28 ( V_46 ) ) ;
if ( F_15 ( V_18 , V_36 ) & V_69 )
return 0 ;
return 1 ;
}
static void F_33 ( struct V_45 * V_46 , int V_70 , unsigned int V_71 )
{
struct V_17 * V_18 = F_7 ( F_28 ( V_46 ) ) ;
if ( V_71 & V_72 ) {
F_26 ( V_18 , V_70 ) ;
} else if ( V_71 & V_73 ) {
F_21 ( V_18 ) ;
F_11 ( V_18 , V_74 , V_75 ) ;
F_24 ( V_18 , V_70 ) ;
}
}
static inline void F_34 ( struct V_17 * V_18 )
{
int V_76 ;
T_1 V_20 ;
V_76 = F_35 ( V_18 -> V_22 + V_77 , V_20 ,
V_20 & V_78 , 10 , V_38 ) ;
if ( V_76 < 0 )
F_30 ( V_18 -> V_24 , L_6 ) ;
}
static inline T_1 F_36 ( struct V_45 * V_46 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_17 * V_18 = F_7 ( V_4 ) ;
T_2 V_21 ;
V_21 = F_15 ( V_18 , V_36 ) & V_79 ;
if ( V_21 != V_80 ) {
V_21 = F_17 ( V_18 , V_75 ) ;
V_21 |= V_81 | V_82 ;
F_11 ( V_18 , V_21 , V_75 ) ;
V_21 = ( V_83 << V_84 ) | V_85 ;
F_9 ( V_18 , V_21 , V_28 ) ;
F_11 ( V_18 , V_86 , V_33 ) ;
}
F_34 ( V_18 ) ;
return F_19 ( V_18 , V_87 ) ;
}
static void F_37 ( struct V_45 * V_46 , T_1 * V_88 , int V_66 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_66 ; V_6 ++ )
V_88 [ V_6 ] = F_36 ( V_46 ) ;
}
static void F_38 ( struct V_45 * V_46 , T_1 V_89 )
{
struct V_17 * V_18 = F_7 ( F_28 ( V_46 ) ) ;
T_2 V_21 ;
V_21 = F_15 ( V_18 , V_36 ) & V_79 ;
if ( V_21 != V_80 ) {
V_21 = F_17 ( V_18 , V_75 ) | V_81 ;
F_11 ( V_18 , V_21 , V_75 ) ;
V_21 = V_83 << V_84 | V_90 ;
F_9 ( V_18 , V_21 , V_28 ) ;
F_11 ( V_18 , V_86 , V_33 ) ;
}
F_34 ( V_18 ) ;
F_13 ( V_18 , V_89 , V_91 ) ;
}
static void F_39 ( struct V_45 * V_46 , const T_1 * V_88 , int V_66 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_66 ; V_6 ++ )
F_38 ( V_46 , V_88 [ V_6 ] ) ;
}
static int F_40 ( struct V_45 * V_46 , int V_92 ,
const struct V_93 * V_94 )
{
struct V_17 * V_18 = F_7 ( F_28 ( V_46 ) ) ;
const struct V_95 * V_96 ;
T_2 V_97 , V_98 , V_99 , V_100 , V_101 , V_102 , V_103 , V_104 ;
V_96 = F_41 ( V_94 ) ;
if ( F_42 ( V_96 ) )
return - V_105 ;
if ( V_92 == V_106 )
return 0 ;
V_97 = F_43 ( V_18 -> V_107 . V_108 ) ;
V_97 /= V_18 -> V_56 -> V_109 ;
V_97 /= 1000 ;
V_98 = F_44 ( V_96 -> V_110 , V_96 -> V_111 ) / 1000 ;
V_98 = F_45 ( V_98 * V_97 , 1000000 ) ;
V_98 &= 0xf ;
V_99 = F_44 ( V_96 -> V_112 , V_96 -> V_113 ) / 1000 ;
V_99 = F_45 ( V_99 * V_97 , 1000000 ) ;
V_99 &= 0x3f ;
V_100 = 0 ;
V_101 = V_96 -> V_114 / 1000 ;
V_101 = F_45 ( V_101 * V_97 , 1000000 ) ;
V_101 = F_45 ( V_101 - 1 , 2 ) ;
V_101 &= 0xf ;
V_102 = F_44 ( V_96 -> V_115 , V_96 -> V_116 ) / 1000 ;
V_102 = F_45 ( V_102 * V_97 , 1000000 ) - 1 ;
V_102 &= 0xf ;
V_103 = V_96 -> V_117 / 1000 ;
V_103 = F_45 ( V_103 * V_97 , 1000000 ) - 1 ;
V_103 &= 0xf ;
V_104 = F_44 ( V_96 -> V_118 , V_96 -> V_119 ) / 1000 ;
V_104 = F_45 ( V_104 * V_97 , 1000000 ) - 1 ;
V_104 &= 0xf ;
V_104 = F_46 ( V_98 , V_99 , V_100 , V_101 , V_102 , V_103 , V_104 ) ;
F_9 ( V_18 , V_104 , V_120 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_4 , T_1 * V_121 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
int V_8 = V_4 -> V_7 . V_8 + V_9 -> V_14 . V_15 ;
V_18 -> V_64 . V_122 = V_123 ;
V_18 -> V_64 . V_124 = V_125 ;
return F_48 ( V_18 -> V_7 , & V_18 -> V_64 , V_121 , V_8 ) ;
}
static void F_49 ( struct V_45 * V_126 , T_1 * V_127 , int V_128 )
{
}
static void F_50 ( struct V_45 * V_46 , T_1 * V_88 , int V_129 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_1 * V_3 = F_1 ( V_4 ) ;
T_2 V_130 = V_3 -> V_11 . V_131 ;
if ( V_129 )
V_130 += V_3 -> V_11 . V_12 * F_5 ( V_4 ) ;
else
V_130 += V_3 -> V_11 . V_12 * V_4 -> V_7 . V_8 ;
F_51 ( V_4 -> V_13 [ 0 ] , V_88 [ V_130 ] ) ;
}
static int F_52 ( struct V_45 * V_46 , T_2 V_132 ,
T_2 V_66 , const T_1 * V_88 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_133 * V_14 = & V_9 -> V_14 ;
T_2 V_134 , V_135 ;
int V_6 , V_25 ;
V_134 = V_132 / V_4 -> V_7 . V_8 ;
V_135 = F_45 ( V_132 + V_66 , V_4 -> V_7 . V_8 ) ;
memset ( V_18 -> V_19 , 0xff , V_46 -> V_49 + V_46 -> V_136 ) ;
for ( V_6 = 0 ; V_6 < V_4 -> V_7 . V_137 ; V_6 ++ ) {
memcpy ( F_6 ( V_4 , V_6 ) , F_3 ( V_4 , V_88 , V_6 ) ,
V_4 -> V_7 . V_8 ) ;
if ( V_134 > V_6 || V_6 >= V_135 )
continue;
if ( V_6 == V_9 -> V_11 . V_12 )
V_9 -> V_11 . V_138 ( V_46 , V_18 -> V_19 , 1 ) ;
memcpy ( F_8 ( V_4 , V_6 ) , F_4 ( V_4 , V_6 ) , V_14 -> V_15 ) ;
V_25 = F_47 ( V_4 , F_6 ( V_4 , V_6 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static void F_53 ( struct V_45 * V_46 , const T_1 * V_88 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_133 * V_14 = & V_9 -> V_14 ;
T_2 V_6 ;
memset ( V_18 -> V_19 , 0xff , V_46 -> V_49 + V_46 -> V_136 ) ;
for ( V_6 = 0 ; V_6 < V_4 -> V_7 . V_137 ; V_6 ++ ) {
if ( V_88 )
memcpy ( F_6 ( V_4 , V_6 ) , F_3 ( V_4 , V_88 , V_6 ) ,
V_4 -> V_7 . V_8 ) ;
if ( V_6 == V_9 -> V_11 . V_12 )
V_9 -> V_11 . V_138 ( V_46 , V_18 -> V_19 , 1 ) ;
memcpy ( F_8 ( V_4 , V_6 ) , F_4 ( V_4 , V_6 ) , V_14 -> V_15 ) ;
}
}
static inline void F_54 ( struct V_2 * V_4 , T_2 V_134 ,
T_2 V_139 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_133 * V_14 = & V_9 -> V_14 ;
T_2 V_140 , V_141 ;
T_1 * V_142 ;
int V_6 , V_143 ;
for ( V_6 = 0 ; V_6 < V_139 ; V_6 ++ ) {
V_142 = F_4 ( V_4 , V_134 + V_6 ) ;
V_140 = F_15 ( V_18 , F_55 ( V_6 ) ) ;
V_141 = F_15 ( V_18 , F_56 ( V_6 ) ) ;
for ( V_143 = 0 ; V_143 < V_14 -> V_15 ; V_143 ++ )
V_142 [ V_143 ] = ( V_143 >= 4 ? V_141 : V_140 ) >> ( ( V_143 % 4 ) * 8 ) ;
}
}
static inline void F_57 ( struct V_2 * V_4 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_133 * V_14 = & V_9 -> V_14 ;
T_2 V_140 , V_141 ;
T_1 * V_142 ;
int V_6 , V_143 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_7 . V_137 ; V_6 ++ ) {
V_142 = F_4 ( V_4 , V_6 ) ;
V_140 = 0 ;
V_141 = 0 ;
for ( V_143 = 0 ; V_143 < 8 ; V_143 ++ ) {
if ( V_143 < 4 )
V_140 |= ( V_143 < V_14 -> V_15 ? V_142 [ V_143 ] : 0xff )
<< ( V_143 * 8 ) ;
else
V_141 |= ( V_143 < V_14 -> V_15 ? V_142 [ V_143 ] : 0xff )
<< ( ( V_143 - 4 ) * 8 ) ;
}
F_9 ( V_18 , V_140 , F_55 ( V_6 ) ) ;
F_9 ( V_18 , V_141 , F_56 ( V_6 ) ) ;
}
}
static int F_58 ( struct V_45 * V_46 , struct V_2 * V_4 ,
const T_1 * V_88 , int V_144 , int V_66 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_23 * V_24 = V_18 -> V_24 ;
T_4 V_40 ;
T_2 V_21 ;
int V_25 ;
V_40 = F_59 ( V_24 , ( void * ) V_88 , V_66 , V_145 ) ;
V_25 = F_60 ( V_18 -> V_24 , V_40 ) ;
if ( V_25 ) {
F_30 ( V_18 -> V_24 , L_7 ) ;
return - V_55 ;
}
V_21 = F_17 ( V_18 , V_75 ) | V_146 | V_147 ;
F_11 ( V_18 , V_21 , V_75 ) ;
F_9 ( V_18 , V_4 -> V_7 . V_137 << V_84 , V_28 ) ;
F_9 ( V_18 , F_61 ( V_40 ) , V_148 ) ;
F_11 ( V_18 , V_149 , V_150 ) ;
F_62 ( & V_18 -> V_151 ) ;
V_21 = F_15 ( V_18 , V_28 ) | V_90 ;
F_9 ( V_18 , V_21 , V_28 ) ;
F_11 ( V_18 , V_86 , V_33 ) ;
V_25 = F_63 ( & V_18 -> V_151 , F_64 ( 500 ) ) ;
if ( ! V_25 ) {
F_30 ( V_24 , L_8 ) ;
F_11 ( V_18 , 0 , V_150 ) ;
V_25 = - V_152 ;
goto V_153;
}
V_25 = F_25 ( V_18 -> V_22 + V_154 , V_21 ,
F_65 ( V_21 ) >= V_4 -> V_7 . V_137 ,
10 , V_38 ) ;
if ( V_25 )
F_30 ( V_24 , L_9 ) ;
V_153:
F_66 ( V_18 -> V_24 , V_40 , V_66 , V_145 ) ;
F_9 ( V_18 , 0 , V_28 ) ;
return V_25 ;
}
static int F_67 ( struct V_45 * V_46 , struct V_2 * V_4 ,
const T_1 * V_88 , int V_144 , int V_129 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
T_5 V_66 ;
const T_1 * V_155 ;
T_2 V_21 ;
int V_25 ;
if ( ! V_129 ) {
V_21 = F_17 ( V_18 , V_75 ) | V_156 ;
F_11 ( V_18 , V_21 | V_157 , V_75 ) ;
V_18 -> V_64 . V_124 = V_125 ;
V_18 -> V_64 . V_122 = V_158 ;
V_25 = F_68 ( V_18 -> V_7 , & V_18 -> V_64 ) ;
if ( V_25 ) {
V_21 = F_17 ( V_18 , V_75 ) ;
V_21 &= ~ ( V_156 | V_157 ) ;
F_11 ( V_18 , V_21 , V_75 ) ;
return V_25 ;
}
memcpy ( V_18 -> V_19 , V_88 , V_46 -> V_49 ) ;
V_9 -> V_11 . V_138 ( V_46 , V_18 -> V_19 , V_129 ) ;
V_155 = V_18 -> V_19 ;
F_57 ( V_4 ) ;
} else {
V_155 = V_88 ;
}
V_66 = V_46 -> V_49 + ( V_129 ? V_46 -> V_136 : 0 ) ;
V_25 = F_58 ( V_46 , V_4 , V_155 , V_144 , V_66 ) ;
if ( ! V_129 )
F_69 ( V_18 -> V_7 ) ;
return V_25 ;
}
static int F_70 ( struct V_45 * V_46 ,
struct V_2 * V_4 , const T_1 * V_88 ,
int V_159 , int V_144 )
{
return F_67 ( V_46 , V_4 , V_88 , V_144 , 0 ) ;
}
static int F_71 ( struct V_45 * V_46 , struct V_2 * V_4 ,
const T_1 * V_88 , int V_159 , int V_160 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
F_53 ( V_46 , V_88 ) ;
return F_67 ( V_46 , V_4 , V_18 -> V_19 , V_160 , 1 ) ;
}
static int F_72 ( struct V_45 * V_46 ,
struct V_2 * V_4 , T_2 V_132 ,
T_2 V_161 , const T_1 * V_88 ,
int V_159 , int V_144 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
int V_25 ;
V_25 = F_52 ( V_46 , V_132 , V_161 , V_88 ) ;
if ( V_25 < 0 )
return V_25 ;
return F_67 ( V_46 , V_4 , V_18 -> V_19 , V_144 , 1 ) ;
}
static int F_73 ( struct V_45 * V_46 , struct V_2 * V_4 ,
int V_144 )
{
int V_25 ;
V_4 -> V_162 ( V_46 , V_163 , 0x00 , V_144 ) ;
V_25 = F_71 ( V_46 , V_4 , NULL , 1 , V_144 ) ;
if ( V_25 < 0 )
return - V_39 ;
V_4 -> V_162 ( V_46 , V_164 , - 1 , - 1 ) ;
V_25 = V_4 -> V_165 ( V_46 , V_4 ) ;
return V_25 & V_166 ? - V_39 : 0 ;
}
static int F_74 ( struct V_45 * V_46 , T_1 * V_88 , T_2 V_139 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_167 V_168 ;
int V_76 , V_6 ;
V_76 = F_15 ( V_18 , V_36 ) & V_169 ;
if ( V_76 ) {
memset ( V_88 , 0xff , V_139 * V_4 -> V_7 . V_8 ) ;
for ( V_6 = 0 ; V_6 < V_139 ; V_6 ++ )
memset ( F_4 ( V_4 , V_6 ) , 0xff , V_9 -> V_14 . V_15 ) ;
return 0 ;
}
F_75 ( V_18 -> V_7 , & V_168 , V_139 ) ;
V_46 -> V_170 . V_171 += V_168 . V_171 ;
V_46 -> V_170 . V_172 += V_168 . V_172 ;
return V_168 . V_173 ;
}
static int F_76 ( struct V_45 * V_46 , struct V_2 * V_4 ,
T_2 V_174 , T_2 V_175 ,
T_1 * V_155 , int V_144 , int V_129 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
T_2 V_48 = V_9 -> V_16 ;
T_2 V_176 , V_139 , V_134 , V_135 , V_21 ;
T_4 V_40 ;
int V_173 ;
T_5 V_66 ;
T_1 * V_88 ;
int V_76 ;
V_134 = V_174 / V_4 -> V_7 . V_8 ;
V_135 = F_45 ( V_174 + V_175 , V_4 -> V_7 . V_8 ) ;
V_139 = V_135 - V_134 ;
V_176 = V_134 * ( V_4 -> V_7 . V_8 + V_48 ) ;
V_66 = V_139 * V_4 -> V_7 . V_8 + ( V_129 ? V_139 * V_48 : 0 ) ;
V_88 = V_155 + V_134 * V_4 -> V_7 . V_8 ;
if ( V_176 != 0 )
V_4 -> V_162 ( V_46 , V_177 , V_176 , - 1 ) ;
V_40 = F_59 ( V_18 -> V_24 , V_88 , V_66 , V_178 ) ;
V_76 = F_60 ( V_18 -> V_24 , V_40 ) ;
if ( V_76 ) {
F_30 ( V_18 -> V_24 , L_7 ) ;
return - V_55 ;
}
V_21 = F_17 ( V_18 , V_75 ) ;
V_21 |= V_82 | V_147 | V_146 ;
if ( ! V_129 ) {
V_21 |= V_156 | V_157 ;
F_11 ( V_18 , V_21 , V_75 ) ;
V_18 -> V_64 . V_122 = V_158 ;
V_18 -> V_64 . V_139 = V_139 ;
V_18 -> V_64 . V_124 = V_179 ;
V_76 = F_68 ( V_18 -> V_7 , & V_18 -> V_64 ) ;
if ( V_76 ) {
F_30 ( V_18 -> V_24 , L_10 ) ;
V_21 &= ~ ( V_147 | V_146 | V_82 |
V_156 | V_157 ) ;
F_11 ( V_18 , V_21 , V_75 ) ;
F_66 ( V_18 -> V_24 , V_40 , V_66 , V_178 ) ;
return V_76 ;
}
} else {
F_11 ( V_18 , V_21 , V_75 ) ;
}
F_9 ( V_18 , V_139 << V_84 , V_28 ) ;
F_11 ( V_18 , V_149 , V_150 ) ;
F_9 ( V_18 , F_61 ( V_40 ) , V_148 ) ;
F_62 ( & V_18 -> V_151 ) ;
V_21 = F_15 ( V_18 , V_28 ) | V_85 ;
F_9 ( V_18 , V_21 , V_28 ) ;
F_11 ( V_18 , V_86 , V_33 ) ;
V_76 = F_63 ( & V_18 -> V_151 , F_64 ( 500 ) ) ;
if ( ! V_76 )
F_23 ( V_18 -> V_24 , L_11 ) ;
V_76 = F_25 ( V_18 -> V_22 + V_180 , V_21 ,
F_65 ( V_21 ) >= V_139 , 10 ,
V_38 ) ;
if ( V_76 < 0 ) {
F_30 ( V_18 -> V_24 , L_12 ) ;
V_173 = - V_39 ;
} else {
V_173 = 0 ;
if ( ! V_129 ) {
V_76 = F_77 ( V_18 -> V_7 , V_179 ) ;
V_173 = V_76 < 0 ? - V_152 :
F_74 ( V_46 , V_88 , V_139 ) ;
F_54 ( V_4 , V_134 , V_139 ) ;
}
}
F_66 ( V_18 -> V_24 , V_40 , V_66 , V_178 ) ;
if ( V_129 )
goto V_151;
F_69 ( V_18 -> V_7 ) ;
if ( F_78 ( V_9 -> V_11 . V_12 , V_134 , V_135 ) == V_9 -> V_11 . V_12 )
V_9 -> V_11 . V_138 ( V_46 , V_155 , V_129 ) ;
V_151:
F_9 ( V_18 , 0 , V_28 ) ;
return V_173 ;
}
static int F_79 ( struct V_45 * V_46 ,
struct V_2 * V_4 , T_2 V_181 ,
T_2 V_66 , T_1 * V_5 , int V_160 )
{
return F_76 ( V_46 , V_4 , V_181 , V_66 , V_5 , V_160 , 0 ) ;
}
static int F_80 ( struct V_45 * V_46 ,
struct V_2 * V_4 , T_1 * V_5 ,
int V_159 , int V_160 )
{
return F_76 ( V_46 , V_4 , 0 , V_46 -> V_49 , V_5 , V_160 , 0 ) ;
}
static int F_81 ( struct V_45 * V_46 , struct V_2 * V_4 ,
T_1 * V_88 , int V_159 , int V_144 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_133 * V_14 = & V_9 -> V_14 ;
int V_6 , V_25 ;
memset ( V_18 -> V_19 , 0xff , V_46 -> V_49 + V_46 -> V_136 ) ;
V_25 = F_76 ( V_46 , V_4 , 0 , V_46 -> V_49 , V_18 -> V_19 ,
V_144 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_7 . V_137 ; V_6 ++ ) {
memcpy ( F_4 ( V_4 , V_6 ) , F_8 ( V_4 , V_6 ) , V_14 -> V_15 ) ;
if ( V_6 == V_9 -> V_11 . V_12 )
V_9 -> V_11 . V_138 ( V_46 , V_18 -> V_19 , 1 ) ;
if ( V_88 )
memcpy ( F_3 ( V_4 , V_88 , V_6 ) , F_6 ( V_4 , V_6 ) ,
V_4 -> V_7 . V_8 ) ;
}
return V_25 ;
}
static int F_82 ( struct V_45 * V_46 , struct V_2 * V_4 ,
int V_144 )
{
V_4 -> V_162 ( V_46 , V_182 , 0 , V_144 ) ;
return F_81 ( V_46 , V_4 , NULL , 1 , V_144 ) ;
}
static inline void F_83 ( struct V_17 * V_18 )
{
F_11 ( V_18 , 0xf1 , V_183 ) ;
F_9 ( V_18 , V_54 , V_63 ) ;
F_21 ( V_18 ) ;
F_15 ( V_18 , V_184 ) ;
F_9 ( V_18 , 0 , V_150 ) ;
}
static T_6 F_84 ( int V_185 , void * V_186 )
{
struct V_17 * V_18 = V_186 ;
T_3 V_187 , V_188 ;
V_187 = F_17 ( V_18 , V_184 ) ;
V_188 = F_17 ( V_18 , V_150 ) ;
if ( ! ( V_187 & V_188 ) )
return V_189 ;
F_11 ( V_18 , ~ V_187 & V_188 , V_150 ) ;
F_85 ( & V_18 -> V_151 ) ;
return V_190 ;
}
static int F_86 ( struct V_23 * V_24 , struct V_191 * V_107 )
{
int V_25 ;
V_25 = F_87 ( V_107 -> V_108 ) ;
if ( V_25 ) {
F_30 ( V_24 , L_13 ) ;
return V_25 ;
}
V_25 = F_87 ( V_107 -> V_192 ) ;
if ( V_25 ) {
F_30 ( V_24 , L_14 ) ;
F_88 ( V_107 -> V_108 ) ;
return V_25 ;
}
return 0 ;
}
static void F_89 ( struct V_191 * V_107 )
{
F_88 ( V_107 -> V_108 ) ;
F_88 ( V_107 -> V_192 ) ;
}
static int F_90 ( struct V_45 * V_46 , int V_193 ,
struct V_194 * V_195 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_133 * V_14 = & V_9 -> V_14 ;
T_2 V_196 ;
V_196 = V_46 -> V_49 / V_4 -> V_7 . V_8 ;
if ( V_193 >= V_196 )
return - V_197 ;
V_195 -> V_198 = V_14 -> V_15 - V_14 -> V_61 ;
V_195 -> V_132 = V_193 * V_14 -> V_15 + V_14 -> V_61 ;
return 0 ;
}
static int F_91 ( struct V_45 * V_46 , int V_193 ,
struct V_194 * V_195 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
T_2 V_196 ;
if ( V_193 )
return - V_197 ;
V_196 = V_46 -> V_49 / V_4 -> V_7 . V_8 ;
V_195 -> V_132 = V_9 -> V_14 . V_15 * V_196 ;
V_195 -> V_198 = V_46 -> V_136 - V_195 -> V_132 ;
return 0 ;
}
static void F_92 ( struct V_133 * V_14 , struct V_45 * V_46 )
{
struct V_2 * V_3 = F_28 ( V_46 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_199 ;
V_199 = F_45 ( V_3 -> V_7 . V_65 * V_200 , 8 ) ;
V_14 -> V_15 = V_4 -> V_16 - V_199 ;
if ( V_14 -> V_15 > V_201 )
V_14 -> V_15 = V_201 ;
V_14 -> V_61 = 1 ;
}
static void F_93 ( struct V_202 * V_203 ,
struct V_45 * V_46 )
{
struct V_2 * V_3 = F_28 ( V_46 ) ;
if ( V_46 -> V_49 == 512 ) {
V_203 -> V_138 = F_49 ;
} else {
V_203 -> V_138 = F_50 ;
V_203 -> V_12 = V_46 -> V_49 / F_5 ( V_3 ) ;
V_203 -> V_131 = V_46 -> V_49 % F_5 ( V_3 ) ;
}
}
static int F_94 ( T_2 * V_204 , struct V_45 * V_46 )
{
struct V_2 * V_3 = F_28 ( V_46 ) ;
struct V_17 * V_18 = F_7 ( V_3 ) ;
const T_1 * V_48 = V_18 -> V_56 -> V_58 ;
T_2 V_196 , V_6 , V_205 = 0 ;
V_196 = V_46 -> V_49 / V_3 -> V_7 . V_8 ;
* V_204 = V_46 -> V_136 / V_196 ;
if ( V_3 -> V_7 . V_8 == 1024 )
* V_204 >>= 1 ;
if ( * V_204 < V_206 )
return - V_55 ;
for ( V_6 = 0 ; V_6 < V_18 -> V_56 -> V_57 ; V_6 ++ ) {
if ( * V_204 >= V_48 [ V_6 ] && V_48 [ V_6 ] >= V_48 [ V_205 ] ) {
V_205 = V_6 ;
if ( * V_204 == V_48 [ V_6 ] )
break;
}
}
* V_204 = V_48 [ V_205 ] ;
if ( V_3 -> V_7 . V_8 == 1024 )
* V_204 <<= 1 ;
return 0 ;
}
static int F_95 ( struct V_23 * V_24 , struct V_45 * V_46 )
{
struct V_2 * V_3 = F_28 ( V_46 ) ;
struct V_17 * V_18 = F_7 ( V_3 ) ;
T_2 V_48 ;
int free , V_25 ;
if ( V_3 -> V_7 . V_122 != V_207 ) {
F_30 ( V_24 , L_15 ) ;
return - V_55 ;
}
if ( ! V_3 -> V_7 . V_8 || ! V_3 -> V_7 . V_65 ) {
V_3 -> V_7 . V_65 = V_3 -> V_208 ;
V_3 -> V_7 . V_8 = V_3 -> V_209 ;
if ( V_3 -> V_7 . V_8 < 1024 ) {
if ( V_46 -> V_49 > 512 ) {
V_3 -> V_7 . V_8 = 1024 ;
V_3 -> V_7 . V_65 <<= 1 ;
} else {
V_3 -> V_7 . V_8 = 512 ;
}
} else {
V_3 -> V_7 . V_8 = 1024 ;
}
V_25 = F_94 ( & V_48 , V_46 ) ;
if ( V_25 )
return V_25 ;
free = ( ( V_3 -> V_7 . V_65 * V_200 ) + 7 ) >> 3 ;
free = V_48 - free ;
if ( free > V_201 ) {
V_48 -= V_201 ;
V_3 -> V_7 . V_65 = ( V_48 << 3 ) / V_200 ;
} else if ( free < 0 ) {
V_48 -= V_210 ;
V_3 -> V_7 . V_65 = ( V_48 << 3 ) / V_200 ;
}
}
F_96 ( V_18 -> V_7 , & V_3 -> V_7 . V_65 ) ;
F_97 ( V_24 , L_16 ,
V_3 -> V_7 . V_8 , V_3 -> V_7 . V_65 ) ;
return 0 ;
}
static int F_98 ( struct V_23 * V_24 , struct V_17 * V_18 ,
struct V_211 * V_212 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_45 * V_46 ;
int V_213 , V_66 ;
T_2 V_214 ;
int V_25 ;
int V_6 ;
if ( ! F_99 ( V_212 , L_17 , & V_213 ) )
return - V_215 ;
V_213 /= sizeof( T_2 ) ;
if ( ! V_213 || V_213 > V_216 ) {
F_30 ( V_24 , L_18 , V_213 ) ;
return - V_55 ;
}
V_4 = F_100 ( V_24 , sizeof( * V_4 ) + V_213 * sizeof( T_1 ) ,
V_217 ) ;
if ( ! V_4 )
return - V_218 ;
V_4 -> V_213 = V_213 ;
for ( V_6 = 0 ; V_6 < V_213 ; V_6 ++ ) {
V_25 = F_101 ( V_212 , L_17 , V_6 , & V_214 ) ;
if ( V_25 ) {
F_30 ( V_24 , L_19 , V_25 ) ;
return V_25 ;
}
V_4 -> V_67 [ V_6 ] = V_214 ;
}
V_3 = & V_4 -> V_3 ;
V_3 -> V_219 = & V_18 -> V_219 ;
F_102 ( V_3 , V_212 ) ;
F_103 ( V_3 , V_18 ) ;
V_3 -> V_220 |= V_221 | V_222 ;
V_3 -> V_223 = F_32 ;
V_3 -> V_224 = F_31 ;
V_3 -> V_225 = F_38 ;
V_3 -> V_226 = F_39 ;
V_3 -> V_227 = F_36 ;
V_3 -> V_228 = F_37 ;
V_3 -> V_229 = F_33 ;
V_3 -> V_230 = F_40 ;
V_3 -> V_7 . V_122 = V_207 ;
V_3 -> V_7 . V_231 = F_72 ;
V_3 -> V_7 . V_232 = F_71 ;
V_3 -> V_7 . V_233 = F_70 ;
V_3 -> V_7 . V_234 = F_73 ;
V_3 -> V_7 . V_235 = F_73 ;
V_3 -> V_7 . V_236 = F_79 ;
V_3 -> V_7 . V_237 = F_81 ;
V_3 -> V_7 . V_238 = F_80 ;
V_3 -> V_7 . V_239 = F_82 ;
V_3 -> V_7 . V_240 = F_82 ;
V_46 = F_104 ( V_3 ) ;
V_46 -> V_241 = V_242 ;
V_46 -> V_24 . V_243 = V_24 ;
V_46 -> V_244 = V_245 ;
F_105 ( V_46 , & V_246 ) ;
F_83 ( V_18 ) ;
V_25 = F_106 ( V_46 , V_213 , NULL ) ;
if ( V_25 )
return V_25 ;
if ( V_3 -> V_247 & V_248 )
V_3 -> V_247 |= V_249 ;
V_25 = F_95 ( V_24 , V_46 ) ;
if ( V_25 )
return - V_55 ;
if ( V_3 -> V_220 & V_250 ) {
F_30 ( V_24 , L_20 ) ;
return - V_55 ;
}
V_25 = F_94 ( & V_4 -> V_16 , V_46 ) ;
if ( V_25 )
return V_25 ;
F_92 ( & V_4 -> V_14 , V_46 ) ;
F_93 ( & V_4 -> V_11 , V_46 ) ;
V_66 = V_46 -> V_49 + V_46 -> V_136 ;
V_18 -> V_19 = F_100 ( V_24 , V_66 , V_217 ) ;
if ( ! V_18 -> V_19 )
return - V_218 ;
V_25 = F_107 ( V_46 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_108 ( V_46 , NULL , NULL , NULL , 0 ) ;
if ( V_25 ) {
F_30 ( V_24 , L_21 ) ;
F_109 ( V_46 ) ;
return V_25 ;
}
F_110 ( & V_4 -> V_251 , & V_18 -> V_252 ) ;
return 0 ;
}
static int F_111 ( struct V_23 * V_24 , struct V_17 * V_18 )
{
struct V_211 * V_212 = V_24 -> V_253 ;
struct V_211 * V_254 ;
int V_25 ;
F_112 (np, nand_np) {
V_25 = F_98 ( V_24 , V_18 , V_254 ) ;
if ( V_25 ) {
F_113 ( V_254 ) ;
return V_25 ;
}
}
return 0 ;
}
static int F_114 ( struct V_255 * V_256 )
{
struct V_23 * V_24 = & V_256 -> V_24 ;
struct V_211 * V_212 = V_24 -> V_253 ;
struct V_17 * V_18 ;
struct V_257 * V_258 ;
const struct V_259 * V_260 = NULL ;
int V_25 , V_185 ;
V_18 = F_100 ( V_24 , sizeof( * V_18 ) , V_217 ) ;
if ( ! V_18 )
return - V_218 ;
F_115 ( & V_18 -> V_219 . V_261 ) ;
F_116 ( & V_18 -> V_219 . V_262 ) ;
F_117 ( & V_18 -> V_252 ) ;
V_18 -> V_7 = F_118 ( V_212 ) ;
if ( F_42 ( V_18 -> V_7 ) )
return F_119 ( V_18 -> V_7 ) ;
else if ( ! V_18 -> V_7 )
return - V_215 ;
V_18 -> V_24 = V_24 ;
V_258 = F_120 ( V_256 , V_263 , 0 ) ;
V_18 -> V_22 = F_121 ( V_24 , V_258 ) ;
if ( F_42 ( V_18 -> V_22 ) ) {
V_25 = F_119 ( V_18 -> V_22 ) ;
goto V_264;
}
V_18 -> V_107 . V_108 = F_122 ( V_24 , L_22 ) ;
if ( F_42 ( V_18 -> V_107 . V_108 ) ) {
F_30 ( V_24 , L_23 ) ;
V_25 = F_119 ( V_18 -> V_107 . V_108 ) ;
goto V_264;
}
V_18 -> V_107 . V_192 = F_122 ( V_24 , L_24 ) ;
if ( F_42 ( V_18 -> V_107 . V_192 ) ) {
F_30 ( V_24 , L_25 ) ;
V_25 = F_119 ( V_18 -> V_107 . V_192 ) ;
goto V_264;
}
V_25 = F_86 ( V_24 , & V_18 -> V_107 ) ;
if ( V_25 )
goto V_264;
V_185 = F_123 ( V_256 , 0 ) ;
if ( V_185 < 0 ) {
F_30 ( V_24 , L_26 ) ;
V_25 = - V_55 ;
goto V_265;
}
V_25 = F_124 ( V_24 , V_185 , F_84 , 0x0 , L_27 , V_18 ) ;
if ( V_25 ) {
F_30 ( V_24 , L_28 ) ;
goto V_265;
}
V_25 = F_125 ( V_24 , F_126 ( 32 ) ) ;
if ( V_25 ) {
F_30 ( V_24 , L_29 ) ;
goto V_265;
}
V_260 = F_127 ( V_266 , & V_256 -> V_24 ) ;
if ( ! V_260 ) {
V_25 = - V_215 ;
goto V_265;
}
V_18 -> V_56 = V_260 -> V_121 ;
F_128 ( V_256 , V_18 ) ;
V_25 = F_111 ( V_24 , V_18 ) ;
if ( V_25 ) {
F_30 ( V_24 , L_30 ) ;
goto V_265;
}
return 0 ;
V_265:
F_89 ( & V_18 -> V_107 ) ;
V_264:
F_129 ( V_18 -> V_7 ) ;
return V_25 ;
}
static int F_130 ( struct V_255 * V_256 )
{
struct V_17 * V_18 = F_131 ( V_256 ) ;
struct V_1 * V_4 ;
while ( ! F_132 ( & V_18 -> V_252 ) ) {
V_4 = F_133 ( & V_18 -> V_252 , struct V_1 ,
V_251 ) ;
F_109 ( F_104 ( & V_4 -> V_3 ) ) ;
F_134 ( & V_4 -> V_251 ) ;
}
F_129 ( V_18 -> V_7 ) ;
F_89 ( & V_18 -> V_107 ) ;
return 0 ;
}
static int F_135 ( struct V_23 * V_24 )
{
struct V_17 * V_18 = F_136 ( V_24 ) ;
F_89 ( & V_18 -> V_107 ) ;
return 0 ;
}
static int F_137 ( struct V_23 * V_24 )
{
struct V_17 * V_18 = F_136 ( V_24 ) ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_45 * V_46 ;
int V_25 ;
T_2 V_6 ;
F_138 ( 200 ) ;
V_25 = F_86 ( V_24 , & V_18 -> V_107 ) ;
if ( V_25 )
return V_25 ;
F_139 (chip, &nfc->chips, node) {
V_3 = & V_4 -> V_3 ;
V_46 = F_104 ( V_3 ) ;
for ( V_6 = 0 ; V_6 < V_4 -> V_213 ; V_6 ++ ) {
V_3 -> V_224 ( V_46 , V_6 ) ;
V_3 -> V_162 ( V_46 , V_267 , - 1 , - 1 ) ;
}
}
return 0 ;
}
