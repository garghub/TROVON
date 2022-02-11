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
T_2 V_47 , V_48 ;
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
switch ( V_48 ) {
case 16 :
V_47 |= ( V_56 << V_57 ) ;
break;
case 26 :
V_47 |= ( V_58 << V_57 ) ;
break;
case 27 :
V_47 |= ( V_59 << V_57 ) ;
break;
case 28 :
V_47 |= ( V_60 << V_57 ) ;
break;
case 32 :
V_47 |= ( V_61 << V_57 ) ;
break;
case 36 :
V_47 |= ( V_62 << V_57 ) ;
break;
case 40 :
V_47 |= ( V_63 << V_57 ) ;
break;
case 44 :
V_47 |= ( V_64 << V_57 ) ;
break;
case 48 :
V_47 |= ( V_65 << V_57 ) ;
break;
case 49 :
V_47 |= ( V_66 << V_57 ) ;
break;
case 50 :
V_47 |= ( V_67 << V_57 ) ;
break;
case 51 :
V_47 |= ( V_68 << V_57 ) ;
break;
case 52 :
V_47 |= ( V_69 << V_57 ) ;
break;
case 62 :
V_47 |= ( V_70 << V_57 ) ;
break;
case 63 :
V_47 |= ( V_71 << V_57 ) ;
break;
case 64 :
V_47 |= ( V_72 << V_57 ) ;
break;
default:
F_30 ( V_18 -> V_24 , L_5 , V_48 ) ;
return - V_55 ;
}
V_47 |= V_9 -> V_14 . V_15 << V_73 ;
V_47 |= V_9 -> V_14 . V_74 << V_75 ;
F_11 ( V_18 , V_47 , V_76 ) ;
V_18 -> V_77 . V_78 = V_4 -> V_7 . V_78 ;
V_18 -> V_77 . V_79 = V_4 -> V_7 . V_8 + V_9 -> V_14 . V_74 ;
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
F_9 ( V_18 , V_9 -> V_80 [ V_4 ] , V_81 ) ;
}
static int F_32 ( struct V_45 * V_46 )
{
struct V_17 * V_18 = F_7 ( F_28 ( V_46 ) ) ;
if ( F_15 ( V_18 , V_36 ) & V_82 )
return 0 ;
return 1 ;
}
static void F_33 ( struct V_45 * V_46 , int V_83 , unsigned int V_84 )
{
struct V_17 * V_18 = F_7 ( F_28 ( V_46 ) ) ;
if ( V_84 & V_85 ) {
F_26 ( V_18 , V_83 ) ;
} else if ( V_84 & V_86 ) {
F_21 ( V_18 ) ;
F_11 ( V_18 , V_87 , V_88 ) ;
F_24 ( V_18 , V_83 ) ;
}
}
static inline void F_34 ( struct V_17 * V_18 )
{
int V_89 ;
T_1 V_20 ;
V_89 = F_35 ( V_18 -> V_22 + V_90 , V_20 ,
V_20 & V_91 , 10 , V_38 ) ;
if ( V_89 < 0 )
F_30 ( V_18 -> V_24 , L_6 ) ;
}
static inline T_1 F_36 ( struct V_45 * V_46 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_17 * V_18 = F_7 ( V_4 ) ;
T_2 V_21 ;
V_21 = F_15 ( V_18 , V_36 ) & V_92 ;
if ( V_21 != V_93 ) {
V_21 = F_17 ( V_18 , V_88 ) ;
V_21 |= V_94 | V_95 ;
F_11 ( V_18 , V_21 , V_88 ) ;
V_21 = ( V_96 << V_97 ) | V_98 ;
F_9 ( V_18 , V_21 , V_28 ) ;
F_11 ( V_18 , V_99 , V_33 ) ;
}
F_34 ( V_18 ) ;
return F_19 ( V_18 , V_100 ) ;
}
static void F_37 ( struct V_45 * V_46 , T_1 * V_101 , int V_79 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_79 ; V_6 ++ )
V_101 [ V_6 ] = F_36 ( V_46 ) ;
}
static void F_38 ( struct V_45 * V_46 , T_1 V_102 )
{
struct V_17 * V_18 = F_7 ( F_28 ( V_46 ) ) ;
T_2 V_21 ;
V_21 = F_15 ( V_18 , V_36 ) & V_92 ;
if ( V_21 != V_93 ) {
V_21 = F_17 ( V_18 , V_88 ) | V_94 ;
F_11 ( V_18 , V_21 , V_88 ) ;
V_21 = V_96 << V_97 | V_103 ;
F_9 ( V_18 , V_21 , V_28 ) ;
F_11 ( V_18 , V_99 , V_33 ) ;
}
F_34 ( V_18 ) ;
F_13 ( V_18 , V_102 , V_104 ) ;
}
static void F_39 ( struct V_45 * V_46 , const T_1 * V_101 , int V_79 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_79 ; V_6 ++ )
F_38 ( V_46 , V_101 [ V_6 ] ) ;
}
static int F_40 ( struct V_2 * V_4 , T_1 * V_105 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
int V_8 = V_4 -> V_7 . V_8 + V_9 -> V_14 . V_15 ;
V_18 -> V_77 . V_106 = V_107 ;
V_18 -> V_77 . V_108 = V_109 ;
return F_41 ( V_18 -> V_7 , & V_18 -> V_77 , V_105 , V_8 ) ;
}
static void F_42 ( struct V_45 * V_110 , T_1 * V_111 , int V_112 )
{
}
static void F_43 ( struct V_45 * V_46 , T_1 * V_101 , int V_113 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_1 * V_3 = F_1 ( V_4 ) ;
T_2 V_114 = V_3 -> V_11 . V_115 ;
if ( V_113 )
V_114 += V_3 -> V_11 . V_12 * F_5 ( V_4 ) ;
else
V_114 += V_3 -> V_11 . V_12 * V_4 -> V_7 . V_8 ;
F_44 ( V_4 -> V_13 [ 0 ] , V_101 [ V_114 ] ) ;
}
static int F_45 ( struct V_45 * V_46 , T_2 V_116 ,
T_2 V_79 , const T_1 * V_101 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_117 * V_14 = & V_9 -> V_14 ;
T_2 V_118 , V_119 ;
int V_6 , V_25 ;
V_118 = V_116 / V_4 -> V_7 . V_8 ;
V_119 = F_46 ( V_116 + V_79 , V_4 -> V_7 . V_8 ) ;
memset ( V_18 -> V_19 , 0xff , V_46 -> V_49 + V_46 -> V_120 ) ;
for ( V_6 = 0 ; V_6 < V_4 -> V_7 . V_121 ; V_6 ++ ) {
memcpy ( F_6 ( V_4 , V_6 ) , F_3 ( V_4 , V_101 , V_6 ) ,
V_4 -> V_7 . V_8 ) ;
if ( V_118 > V_6 || V_6 >= V_119 )
continue;
if ( V_6 == V_9 -> V_11 . V_12 )
V_9 -> V_11 . V_122 ( V_46 , V_18 -> V_19 , 1 ) ;
memcpy ( F_8 ( V_4 , V_6 ) , F_4 ( V_4 , V_6 ) , V_14 -> V_15 ) ;
V_25 = F_40 ( V_4 , F_6 ( V_4 , V_6 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static void F_47 ( struct V_45 * V_46 , const T_1 * V_101 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_117 * V_14 = & V_9 -> V_14 ;
T_2 V_6 ;
memset ( V_18 -> V_19 , 0xff , V_46 -> V_49 + V_46 -> V_120 ) ;
for ( V_6 = 0 ; V_6 < V_4 -> V_7 . V_121 ; V_6 ++ ) {
if ( V_101 )
memcpy ( F_6 ( V_4 , V_6 ) , F_3 ( V_4 , V_101 , V_6 ) ,
V_4 -> V_7 . V_8 ) ;
if ( V_6 == V_9 -> V_11 . V_12 )
V_9 -> V_11 . V_122 ( V_46 , V_18 -> V_19 , 1 ) ;
memcpy ( F_8 ( V_4 , V_6 ) , F_4 ( V_4 , V_6 ) , V_14 -> V_15 ) ;
}
}
static inline void F_48 ( struct V_2 * V_4 , T_2 V_118 ,
T_2 V_123 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_117 * V_14 = & V_9 -> V_14 ;
T_2 V_124 , V_125 ;
T_1 * V_126 ;
int V_6 , V_127 ;
for ( V_6 = 0 ; V_6 < V_123 ; V_6 ++ ) {
V_126 = F_4 ( V_4 , V_118 + V_6 ) ;
V_124 = F_15 ( V_18 , F_49 ( V_6 ) ) ;
V_125 = F_15 ( V_18 , F_50 ( V_6 ) ) ;
for ( V_127 = 0 ; V_127 < V_14 -> V_15 ; V_127 ++ )
V_126 [ V_127 ] = ( V_127 >= 4 ? V_125 : V_124 ) >> ( ( V_127 % 4 ) * 8 ) ;
}
}
static inline void F_51 ( struct V_2 * V_4 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_117 * V_14 = & V_9 -> V_14 ;
T_2 V_124 , V_125 ;
T_1 * V_126 ;
int V_6 , V_127 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_7 . V_121 ; V_6 ++ ) {
V_126 = F_4 ( V_4 , V_6 ) ;
V_124 = 0 ;
V_125 = 0 ;
for ( V_127 = 0 ; V_127 < 8 ; V_127 ++ ) {
if ( V_127 < 4 )
V_124 |= ( V_127 < V_14 -> V_15 ? V_126 [ V_127 ] : 0xff )
<< ( V_127 * 8 ) ;
else
V_125 |= ( V_127 < V_14 -> V_15 ? V_126 [ V_127 ] : 0xff )
<< ( ( V_127 - 4 ) * 8 ) ;
}
F_9 ( V_18 , V_124 , F_49 ( V_6 ) ) ;
F_9 ( V_18 , V_125 , F_50 ( V_6 ) ) ;
}
}
static int F_52 ( struct V_45 * V_46 , struct V_2 * V_4 ,
const T_1 * V_101 , int V_128 , int V_79 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_23 * V_24 = V_18 -> V_24 ;
T_4 V_40 ;
T_2 V_21 ;
int V_25 ;
V_40 = F_53 ( V_24 , ( void * ) V_101 , V_79 , V_129 ) ;
V_25 = F_54 ( V_18 -> V_24 , V_40 ) ;
if ( V_25 ) {
F_30 ( V_18 -> V_24 , L_7 ) ;
return - V_55 ;
}
V_21 = F_17 ( V_18 , V_88 ) | V_130 | V_131 ;
F_11 ( V_18 , V_21 , V_88 ) ;
F_9 ( V_18 , V_4 -> V_7 . V_121 << V_97 , V_28 ) ;
F_9 ( V_18 , F_55 ( V_40 ) , V_132 ) ;
F_11 ( V_18 , V_133 , V_134 ) ;
F_56 ( & V_18 -> V_135 ) ;
V_21 = F_15 ( V_18 , V_28 ) | V_103 ;
F_9 ( V_18 , V_21 , V_28 ) ;
F_11 ( V_18 , V_99 , V_33 ) ;
V_25 = F_57 ( & V_18 -> V_135 , F_58 ( 500 ) ) ;
if ( ! V_25 ) {
F_30 ( V_24 , L_8 ) ;
F_11 ( V_18 , 0 , V_134 ) ;
V_25 = - V_136 ;
goto V_137;
}
V_25 = F_25 ( V_18 -> V_22 + V_138 , V_21 ,
F_59 ( V_21 ) >= V_4 -> V_7 . V_121 ,
10 , V_38 ) ;
if ( V_25 )
F_30 ( V_24 , L_9 ) ;
V_137:
F_60 ( V_18 -> V_24 , V_40 , V_79 , V_129 ) ;
F_9 ( V_18 , 0 , V_28 ) ;
return V_25 ;
}
static int F_61 ( struct V_45 * V_46 , struct V_2 * V_4 ,
const T_1 * V_101 , int V_128 , int V_113 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
T_5 V_79 ;
const T_1 * V_139 ;
T_2 V_21 ;
int V_25 ;
if ( ! V_113 ) {
V_21 = F_17 ( V_18 , V_88 ) | V_140 ;
F_11 ( V_18 , V_21 | V_141 , V_88 ) ;
V_18 -> V_77 . V_108 = V_109 ;
V_18 -> V_77 . V_106 = V_142 ;
V_25 = F_62 ( V_18 -> V_7 , & V_18 -> V_77 ) ;
if ( V_25 ) {
V_21 = F_17 ( V_18 , V_88 ) ;
V_21 &= ~ ( V_140 | V_141 ) ;
F_11 ( V_18 , V_21 , V_88 ) ;
return V_25 ;
}
memcpy ( V_18 -> V_19 , V_101 , V_46 -> V_49 ) ;
V_9 -> V_11 . V_122 ( V_46 , V_18 -> V_19 , V_113 ) ;
V_139 = V_18 -> V_19 ;
F_51 ( V_4 ) ;
} else {
V_139 = V_101 ;
}
V_79 = V_46 -> V_49 + ( V_113 ? V_46 -> V_120 : 0 ) ;
V_25 = F_52 ( V_46 , V_4 , V_139 , V_128 , V_79 ) ;
if ( ! V_113 )
F_63 ( V_18 -> V_7 ) ;
return V_25 ;
}
static int F_64 ( struct V_45 * V_46 ,
struct V_2 * V_4 , const T_1 * V_101 ,
int V_143 , int V_128 )
{
return F_61 ( V_46 , V_4 , V_101 , V_128 , 0 ) ;
}
static int F_65 ( struct V_45 * V_46 , struct V_2 * V_4 ,
const T_1 * V_101 , int V_143 , int V_144 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
F_47 ( V_46 , V_101 ) ;
return F_61 ( V_46 , V_4 , V_18 -> V_19 , V_144 , 1 ) ;
}
static int F_66 ( struct V_45 * V_46 ,
struct V_2 * V_4 , T_2 V_116 ,
T_2 V_145 , const T_1 * V_101 ,
int V_143 , int V_128 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
int V_25 ;
V_25 = F_45 ( V_46 , V_116 , V_145 , V_101 ) ;
if ( V_25 < 0 )
return V_25 ;
return F_61 ( V_46 , V_4 , V_18 -> V_19 , V_128 , 1 ) ;
}
static int F_67 ( struct V_45 * V_46 , struct V_2 * V_4 ,
int V_128 )
{
int V_25 ;
V_4 -> V_146 ( V_46 , V_147 , 0x00 , V_128 ) ;
V_25 = F_65 ( V_46 , V_4 , NULL , 1 , V_128 ) ;
if ( V_25 < 0 )
return - V_39 ;
V_4 -> V_146 ( V_46 , V_148 , - 1 , - 1 ) ;
V_25 = V_4 -> V_149 ( V_46 , V_4 ) ;
return V_25 & V_150 ? - V_39 : 0 ;
}
static int F_68 ( struct V_45 * V_46 , T_1 * V_101 , T_2 V_123 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_151 V_152 ;
int V_89 , V_6 ;
V_89 = F_15 ( V_18 , V_36 ) & V_153 ;
if ( V_89 ) {
memset ( V_101 , 0xff , V_123 * V_4 -> V_7 . V_8 ) ;
for ( V_6 = 0 ; V_6 < V_123 ; V_6 ++ )
memset ( F_4 ( V_4 , V_6 ) , 0xff , V_9 -> V_14 . V_15 ) ;
return 0 ;
}
F_69 ( V_18 -> V_7 , & V_152 , V_123 ) ;
V_46 -> V_154 . V_155 += V_152 . V_155 ;
V_46 -> V_154 . V_156 += V_152 . V_156 ;
return V_152 . V_157 ;
}
static int F_70 ( struct V_45 * V_46 , struct V_2 * V_4 ,
T_2 V_158 , T_2 V_159 ,
T_1 * V_139 , int V_128 , int V_113 )
{
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
T_2 V_48 = V_9 -> V_16 ;
T_2 V_160 , V_123 , V_118 , V_119 , V_21 ;
T_4 V_40 ;
int V_157 ;
T_5 V_79 ;
T_1 * V_101 ;
int V_89 ;
V_118 = V_158 / V_4 -> V_7 . V_8 ;
V_119 = F_46 ( V_158 + V_159 , V_4 -> V_7 . V_8 ) ;
V_123 = V_119 - V_118 ;
V_160 = V_118 * ( V_4 -> V_7 . V_8 + V_48 ) ;
V_79 = V_123 * V_4 -> V_7 . V_8 + ( V_113 ? V_123 * V_48 : 0 ) ;
V_101 = V_139 + V_118 * V_4 -> V_7 . V_8 ;
if ( V_160 != 0 )
V_4 -> V_146 ( V_46 , V_161 , V_160 , - 1 ) ;
V_40 = F_53 ( V_18 -> V_24 , V_101 , V_79 , V_162 ) ;
V_89 = F_54 ( V_18 -> V_24 , V_40 ) ;
if ( V_89 ) {
F_30 ( V_18 -> V_24 , L_7 ) ;
return - V_55 ;
}
V_21 = F_17 ( V_18 , V_88 ) ;
V_21 |= V_95 | V_131 | V_130 ;
if ( ! V_113 ) {
V_21 |= V_140 | V_141 ;
F_11 ( V_18 , V_21 , V_88 ) ;
V_18 -> V_77 . V_106 = V_142 ;
V_18 -> V_77 . V_123 = V_123 ;
V_18 -> V_77 . V_108 = V_163 ;
V_89 = F_62 ( V_18 -> V_7 , & V_18 -> V_77 ) ;
if ( V_89 ) {
F_30 ( V_18 -> V_24 , L_10 ) ;
V_21 &= ~ ( V_131 | V_130 | V_95 |
V_140 | V_141 ) ;
F_11 ( V_18 , V_21 , V_88 ) ;
F_60 ( V_18 -> V_24 , V_40 , V_79 , V_162 ) ;
return V_89 ;
}
} else {
F_11 ( V_18 , V_21 , V_88 ) ;
}
F_9 ( V_18 , V_123 << V_97 , V_28 ) ;
F_11 ( V_18 , V_133 , V_134 ) ;
F_9 ( V_18 , F_55 ( V_40 ) , V_132 ) ;
F_56 ( & V_18 -> V_135 ) ;
V_21 = F_15 ( V_18 , V_28 ) | V_98 ;
F_9 ( V_18 , V_21 , V_28 ) ;
F_11 ( V_18 , V_99 , V_33 ) ;
V_89 = F_57 ( & V_18 -> V_135 , F_58 ( 500 ) ) ;
if ( ! V_89 )
F_23 ( V_18 -> V_24 , L_11 ) ;
V_89 = F_25 ( V_18 -> V_22 + V_164 , V_21 ,
F_59 ( V_21 ) >= V_123 , 10 ,
V_38 ) ;
if ( V_89 < 0 ) {
F_30 ( V_18 -> V_24 , L_12 ) ;
V_157 = - V_39 ;
} else {
V_157 = 0 ;
if ( ! V_113 ) {
V_89 = F_71 ( V_18 -> V_7 , V_163 ) ;
V_157 = V_89 < 0 ? - V_136 :
F_68 ( V_46 , V_101 , V_123 ) ;
F_48 ( V_4 , V_118 , V_123 ) ;
}
}
F_60 ( V_18 -> V_24 , V_40 , V_79 , V_162 ) ;
if ( V_113 )
goto V_135;
F_63 ( V_18 -> V_7 ) ;
if ( F_72 ( V_9 -> V_11 . V_12 , V_118 , V_119 ) == V_9 -> V_11 . V_12 )
V_9 -> V_11 . V_122 ( V_46 , V_139 , V_113 ) ;
V_135:
F_9 ( V_18 , 0 , V_28 ) ;
return V_157 ;
}
static int F_73 ( struct V_45 * V_46 ,
struct V_2 * V_4 , T_2 V_165 ,
T_2 V_79 , T_1 * V_5 , int V_144 )
{
return F_70 ( V_46 , V_4 , V_165 , V_79 , V_5 , V_144 , 0 ) ;
}
static int F_74 ( struct V_45 * V_46 ,
struct V_2 * V_4 , T_1 * V_5 ,
int V_143 , int V_144 )
{
return F_70 ( V_46 , V_4 , 0 , V_46 -> V_49 , V_5 , V_144 , 0 ) ;
}
static int F_75 ( struct V_45 * V_46 , struct V_2 * V_4 ,
T_1 * V_101 , int V_143 , int V_128 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_17 * V_18 = F_7 ( V_4 ) ;
struct V_117 * V_14 = & V_9 -> V_14 ;
int V_6 , V_25 ;
memset ( V_18 -> V_19 , 0xff , V_46 -> V_49 + V_46 -> V_120 ) ;
V_25 = F_70 ( V_46 , V_4 , 0 , V_46 -> V_49 , V_18 -> V_19 ,
V_128 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_7 . V_121 ; V_6 ++ ) {
memcpy ( F_4 ( V_4 , V_6 ) , F_8 ( V_4 , V_6 ) , V_14 -> V_15 ) ;
if ( V_6 == V_9 -> V_11 . V_12 )
V_9 -> V_11 . V_122 ( V_46 , V_18 -> V_19 , 1 ) ;
if ( V_101 )
memcpy ( F_3 ( V_4 , V_101 , V_6 ) , F_6 ( V_4 , V_6 ) ,
V_4 -> V_7 . V_8 ) ;
}
return V_25 ;
}
static int F_76 ( struct V_45 * V_46 , struct V_2 * V_4 ,
int V_128 )
{
V_4 -> V_146 ( V_46 , V_166 , 0 , V_128 ) ;
return F_75 ( V_46 , V_4 , NULL , 1 , V_128 ) ;
}
static inline void F_77 ( struct V_17 * V_18 )
{
F_9 ( V_18 , 0x10804211 , V_167 ) ;
F_11 ( V_18 , 0xf1 , V_168 ) ;
F_11 ( V_18 , V_54 , V_76 ) ;
F_21 ( V_18 ) ;
F_15 ( V_18 , V_169 ) ;
F_9 ( V_18 , 0 , V_134 ) ;
}
static T_6 F_78 ( int V_170 , void * V_171 )
{
struct V_17 * V_18 = V_171 ;
T_3 V_172 , V_173 ;
V_172 = F_17 ( V_18 , V_169 ) ;
V_173 = F_17 ( V_18 , V_134 ) ;
if ( ! ( V_172 & V_173 ) )
return V_174 ;
F_11 ( V_18 , ~ V_172 & V_173 , V_134 ) ;
F_79 ( & V_18 -> V_135 ) ;
return V_175 ;
}
static int F_80 ( struct V_23 * V_24 , struct V_176 * V_177 )
{
int V_25 ;
V_25 = F_81 ( V_177 -> V_178 ) ;
if ( V_25 ) {
F_30 ( V_24 , L_13 ) ;
return V_25 ;
}
V_25 = F_81 ( V_177 -> V_179 ) ;
if ( V_25 ) {
F_30 ( V_24 , L_14 ) ;
F_82 ( V_177 -> V_178 ) ;
return V_25 ;
}
return 0 ;
}
static void F_83 ( struct V_176 * V_177 )
{
F_82 ( V_177 -> V_178 ) ;
F_82 ( V_177 -> V_179 ) ;
}
static int F_84 ( struct V_45 * V_46 , int V_180 ,
struct V_181 * V_182 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_117 * V_14 = & V_9 -> V_14 ;
T_2 V_183 ;
V_183 = V_46 -> V_49 / V_4 -> V_7 . V_8 ;
if ( V_180 >= V_183 )
return - V_184 ;
V_182 -> V_185 = V_14 -> V_15 - V_14 -> V_74 ;
V_182 -> V_116 = V_180 * V_14 -> V_15 + V_14 -> V_74 ;
return 0 ;
}
static int F_85 ( struct V_45 * V_46 , int V_180 ,
struct V_181 * V_182 )
{
struct V_2 * V_4 = F_28 ( V_46 ) ;
struct V_1 * V_9 = F_1 ( V_4 ) ;
T_2 V_183 ;
if ( V_180 )
return - V_184 ;
V_183 = V_46 -> V_49 / V_4 -> V_7 . V_8 ;
V_182 -> V_116 = V_9 -> V_14 . V_15 * V_183 ;
V_182 -> V_185 = V_46 -> V_120 - V_182 -> V_116 ;
return 0 ;
}
static void F_86 ( struct V_117 * V_14 , struct V_45 * V_46 )
{
struct V_2 * V_3 = F_28 ( V_46 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_186 ;
V_186 = F_46 ( V_3 -> V_7 . V_78 * V_187 , 8 ) ;
V_14 -> V_15 = V_4 -> V_16 - V_186 ;
if ( V_14 -> V_15 > V_188 )
V_14 -> V_15 = V_188 ;
V_14 -> V_74 = 1 ;
}
static void F_87 ( struct V_189 * V_190 ,
struct V_45 * V_46 )
{
struct V_2 * V_3 = F_28 ( V_46 ) ;
if ( V_46 -> V_49 == 512 ) {
V_190 -> V_122 = F_42 ;
} else {
V_190 -> V_122 = F_43 ;
V_190 -> V_12 = V_46 -> V_49 / F_5 ( V_3 ) ;
V_190 -> V_115 = V_46 -> V_49 % F_5 ( V_3 ) ;
}
}
static void F_88 ( T_2 * V_191 , struct V_45 * V_46 )
{
struct V_2 * V_3 = F_28 ( V_46 ) ;
T_2 V_48 [] = { 16 , 26 , 27 , 28 , 32 , 36 , 40 , 44 ,
48 , 49 , 50 , 51 , 52 , 62 , 63 , 64 } ;
T_2 V_183 , V_6 ;
V_183 = V_46 -> V_49 / V_3 -> V_7 . V_8 ;
* V_191 = V_46 -> V_120 / V_183 ;
if ( V_3 -> V_7 . V_8 == 1024 )
* V_191 >>= 1 ;
for ( V_6 = 0 ; V_6 < F_89 ( V_48 ) ; V_6 ++ ) {
if ( * V_191 <= V_48 [ V_6 ] ) {
if ( ! V_6 )
* V_191 = V_48 [ V_6 ] ;
else if ( * V_191 != V_48 [ V_6 ] )
* V_191 = V_48 [ V_6 - 1 ] ;
break;
}
}
if ( V_6 >= F_89 ( V_48 ) )
* V_191 = V_48 [ F_89 ( V_48 ) - 1 ] ;
if ( V_3 -> V_7 . V_8 == 1024 )
* V_191 <<= 1 ;
}
static int F_90 ( struct V_23 * V_24 , struct V_45 * V_46 )
{
struct V_2 * V_3 = F_28 ( V_46 ) ;
T_2 V_48 ;
int free ;
if ( V_3 -> V_7 . V_106 != V_192 ) {
F_30 ( V_24 , L_15 ) ;
return - V_55 ;
}
if ( ! V_3 -> V_7 . V_8 || ! V_3 -> V_7 . V_78 ) {
V_3 -> V_7 . V_78 = V_3 -> V_193 ;
V_3 -> V_7 . V_8 = V_3 -> V_194 ;
if ( V_3 -> V_7 . V_8 < 1024 ) {
if ( V_46 -> V_49 > 512 ) {
V_3 -> V_7 . V_8 = 1024 ;
V_3 -> V_7 . V_78 <<= 1 ;
} else {
V_3 -> V_7 . V_8 = 512 ;
}
} else {
V_3 -> V_7 . V_8 = 1024 ;
}
F_88 ( & V_48 , V_46 ) ;
free = ( ( V_3 -> V_7 . V_78 * V_187 ) + 7 ) >> 3 ;
free = V_48 - free ;
if ( free > V_188 ) {
V_48 -= V_188 ;
V_3 -> V_7 . V_78 = ( V_48 << 3 ) / V_187 ;
} else if ( free < 0 ) {
V_48 -= V_195 ;
V_3 -> V_7 . V_78 = ( V_48 << 3 ) / V_187 ;
}
}
F_91 ( & V_3 -> V_7 . V_78 ) ;
F_92 ( V_24 , L_16 ,
V_3 -> V_7 . V_8 , V_3 -> V_7 . V_78 ) ;
return 0 ;
}
static int F_93 ( struct V_23 * V_24 , struct V_17 * V_18 ,
struct V_196 * V_197 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_45 * V_46 ;
int V_198 , V_79 ;
T_2 V_199 ;
int V_25 ;
int V_6 ;
if ( ! F_94 ( V_197 , L_17 , & V_198 ) )
return - V_200 ;
V_198 /= sizeof( T_2 ) ;
if ( ! V_198 || V_198 > V_201 ) {
F_30 ( V_24 , L_18 , V_198 ) ;
return - V_55 ;
}
V_4 = F_95 ( V_24 , sizeof( * V_4 ) + V_198 * sizeof( T_1 ) ,
V_202 ) ;
if ( ! V_4 )
return - V_203 ;
V_4 -> V_198 = V_198 ;
for ( V_6 = 0 ; V_6 < V_198 ; V_6 ++ ) {
V_25 = F_96 ( V_197 , L_17 , V_6 , & V_199 ) ;
if ( V_25 ) {
F_30 ( V_24 , L_19 , V_25 ) ;
return V_25 ;
}
V_4 -> V_80 [ V_6 ] = V_199 ;
}
V_3 = & V_4 -> V_3 ;
V_3 -> V_204 = & V_18 -> V_204 ;
F_97 ( V_3 , V_197 ) ;
F_98 ( V_3 , V_18 ) ;
V_3 -> V_205 |= V_206 | V_207 ;
V_3 -> V_208 = F_32 ;
V_3 -> V_209 = F_31 ;
V_3 -> V_210 = F_38 ;
V_3 -> V_211 = F_39 ;
V_3 -> V_212 = F_36 ;
V_3 -> V_213 = F_37 ;
V_3 -> V_214 = F_33 ;
V_3 -> V_7 . V_106 = V_192 ;
V_3 -> V_7 . V_215 = F_66 ;
V_3 -> V_7 . V_216 = F_65 ;
V_3 -> V_7 . V_217 = F_64 ;
V_3 -> V_7 . V_218 = F_67 ;
V_3 -> V_7 . V_219 = F_67 ;
V_3 -> V_7 . V_220 = F_73 ;
V_3 -> V_7 . V_221 = F_75 ;
V_3 -> V_7 . V_222 = F_74 ;
V_3 -> V_7 . V_223 = F_76 ;
V_3 -> V_7 . V_224 = F_76 ;
V_46 = F_99 ( V_3 ) ;
V_46 -> V_225 = V_226 ;
V_46 -> V_24 . V_227 = V_24 ;
V_46 -> V_228 = V_229 ;
F_100 ( V_46 , & V_230 ) ;
F_77 ( V_18 ) ;
V_25 = F_101 ( V_46 , V_198 , NULL ) ;
if ( V_25 )
return - V_200 ;
if ( V_3 -> V_231 & V_232 )
V_3 -> V_231 |= V_233 ;
V_25 = F_90 ( V_24 , V_46 ) ;
if ( V_25 )
return - V_55 ;
if ( V_3 -> V_205 & V_234 ) {
F_30 ( V_24 , L_20 ) ;
return - V_55 ;
}
F_88 ( & V_4 -> V_16 , V_46 ) ;
F_86 ( & V_4 -> V_14 , V_46 ) ;
F_87 ( & V_4 -> V_11 , V_46 ) ;
V_79 = V_46 -> V_49 + V_46 -> V_120 ;
V_18 -> V_19 = F_95 ( V_24 , V_79 , V_202 ) ;
if ( ! V_18 -> V_19 )
return - V_203 ;
V_25 = F_102 ( V_46 ) ;
if ( V_25 )
return - V_200 ;
V_25 = F_103 ( V_46 , NULL , NULL , NULL , 0 ) ;
if ( V_25 ) {
F_30 ( V_24 , L_21 ) ;
F_104 ( V_46 ) ;
return V_25 ;
}
F_105 ( & V_4 -> V_235 , & V_18 -> V_236 ) ;
return 0 ;
}
static int F_106 ( struct V_23 * V_24 , struct V_17 * V_18 )
{
struct V_196 * V_197 = V_24 -> V_237 ;
struct V_196 * V_238 ;
int V_25 ;
F_107 (np, nand_np) {
V_25 = F_93 ( V_24 , V_18 , V_238 ) ;
if ( V_25 ) {
F_108 ( V_238 ) ;
return V_25 ;
}
}
return 0 ;
}
static int F_109 ( struct V_239 * V_240 )
{
struct V_23 * V_24 = & V_240 -> V_24 ;
struct V_196 * V_197 = V_24 -> V_237 ;
struct V_17 * V_18 ;
struct V_241 * V_242 ;
int V_25 , V_170 ;
V_18 = F_95 ( V_24 , sizeof( * V_18 ) , V_202 ) ;
if ( ! V_18 )
return - V_203 ;
F_110 ( & V_18 -> V_204 . V_243 ) ;
F_111 ( & V_18 -> V_204 . V_244 ) ;
F_112 ( & V_18 -> V_236 ) ;
V_18 -> V_7 = F_113 ( V_197 ) ;
if ( F_114 ( V_18 -> V_7 ) )
return F_115 ( V_18 -> V_7 ) ;
else if ( ! V_18 -> V_7 )
return - V_200 ;
V_18 -> V_24 = V_24 ;
V_242 = F_116 ( V_240 , V_245 , 0 ) ;
V_18 -> V_22 = F_117 ( V_24 , V_242 ) ;
if ( F_114 ( V_18 -> V_22 ) ) {
V_25 = F_115 ( V_18 -> V_22 ) ;
F_30 ( V_24 , L_22 ) ;
goto V_246;
}
V_18 -> V_177 . V_178 = F_118 ( V_24 , L_23 ) ;
if ( F_114 ( V_18 -> V_177 . V_178 ) ) {
F_30 ( V_24 , L_24 ) ;
V_25 = F_115 ( V_18 -> V_177 . V_178 ) ;
goto V_246;
}
V_18 -> V_177 . V_179 = F_118 ( V_24 , L_25 ) ;
if ( F_114 ( V_18 -> V_177 . V_179 ) ) {
F_30 ( V_24 , L_26 ) ;
V_25 = F_115 ( V_18 -> V_177 . V_179 ) ;
goto V_246;
}
V_25 = F_80 ( V_24 , & V_18 -> V_177 ) ;
if ( V_25 )
goto V_246;
V_170 = F_119 ( V_240 , 0 ) ;
if ( V_170 < 0 ) {
F_30 ( V_24 , L_27 ) ;
V_25 = - V_55 ;
goto V_247;
}
V_25 = F_120 ( V_24 , V_170 , F_78 , 0x0 , L_28 , V_18 ) ;
if ( V_25 ) {
F_30 ( V_24 , L_29 ) ;
goto V_247;
}
V_25 = F_121 ( V_24 , F_122 ( 32 ) ) ;
if ( V_25 ) {
F_30 ( V_24 , L_30 ) ;
goto V_247;
}
F_123 ( V_240 , V_18 ) ;
V_25 = F_106 ( V_24 , V_18 ) ;
if ( V_25 ) {
F_30 ( V_24 , L_31 ) ;
goto V_247;
}
return 0 ;
V_247:
F_83 ( & V_18 -> V_177 ) ;
V_246:
F_124 ( V_18 -> V_7 ) ;
return V_25 ;
}
static int F_125 ( struct V_239 * V_240 )
{
struct V_17 * V_18 = F_126 ( V_240 ) ;
struct V_1 * V_4 ;
while ( ! F_127 ( & V_18 -> V_236 ) ) {
V_4 = F_128 ( & V_18 -> V_236 , struct V_1 ,
V_235 ) ;
F_104 ( F_99 ( & V_4 -> V_3 ) ) ;
F_129 ( & V_4 -> V_235 ) ;
}
F_124 ( V_18 -> V_7 ) ;
F_83 ( & V_18 -> V_177 ) ;
return 0 ;
}
static int F_130 ( struct V_23 * V_24 )
{
struct V_17 * V_18 = F_131 ( V_24 ) ;
F_83 ( & V_18 -> V_177 ) ;
return 0 ;
}
static int F_132 ( struct V_23 * V_24 )
{
struct V_17 * V_18 = F_131 ( V_24 ) ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_45 * V_46 ;
int V_25 ;
T_2 V_6 ;
F_133 ( 200 ) ;
V_25 = F_80 ( V_24 , & V_18 -> V_177 ) ;
if ( V_25 )
return V_25 ;
F_77 ( V_18 ) ;
F_134 (chip, &nfc->chips, node) {
V_3 = & V_4 -> V_3 ;
V_46 = F_99 ( V_3 ) ;
for ( V_6 = 0 ; V_6 < V_4 -> V_198 ; V_6 ++ ) {
V_3 -> V_209 ( V_46 , V_6 ) ;
V_3 -> V_146 ( V_46 , V_248 , - 1 , - 1 ) ;
}
}
return 0 ;
}
