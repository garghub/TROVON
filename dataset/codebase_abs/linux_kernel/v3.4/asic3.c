void F_1 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 +
( V_3 >> V_2 -> V_6 ) ) ;
}
T_1 F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_4 ( V_2 -> V_5 +
( V_3 >> V_2 -> V_6 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 , bool V_8 )
{
unsigned long V_9 ;
T_1 V_10 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_10 = F_3 ( V_2 , V_3 ) ;
if ( V_8 )
V_10 |= V_7 ;
else
V_10 &= ~ V_7 ;
F_1 ( V_2 , V_3 , V_10 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
T_1 V_12 , int V_13 )
{
T_2 V_14 ;
unsigned long V_9 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_14 = F_3 ( V_2 ,
V_12 + V_15 ) ;
V_14 ^= V_13 ;
F_1 ( V_2 ,
V_12 + V_15 , V_14 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static void F_9 ( unsigned int V_16 , struct V_17 * V_18 )
{
struct V_1 * V_2 = F_10 ( V_18 ) ;
struct V_19 * V_20 = F_11 ( V_18 ) ;
int V_21 , V_22 ;
unsigned long V_9 ;
V_20 -> V_23 -> V_24 ( V_20 ) ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
T_1 V_26 ;
int V_27 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_26 = F_3 ( V_2 ,
F_12 ( V_28 , V_29 ) ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
if ( ( V_26 & 0x3ff ) == 0 )
break;
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
if ( V_26 & ( 1 << V_27 ) ) {
unsigned long V_12 , V_31 ;
V_12 = V_32
+ V_27 * V_33 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_31 = F_3 ( V_2 ,
V_12 +
V_34 ) ;
F_1 ( V_2 ,
V_12 +
V_34 , 0 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
for ( V_22 = 0 ; V_22 < V_35 ; V_22 ++ ) {
int V_13 = ( 1 << V_22 ) ;
unsigned int V_36 ;
if ( ! ( V_31 & V_13 ) )
continue;
V_36 = V_2 -> V_37 +
( V_35 * V_27 )
+ V_22 ;
F_13 ( V_36 ) ;
if ( V_2 -> V_38 [ V_27 ] & V_13 )
F_8 ( V_2 , V_12 ,
V_13 ) ;
}
}
}
for ( V_22 = V_39 ; V_22 < V_40 ; V_22 ++ ) {
if ( V_26 & ( 1 << ( V_22 - V_39 + 4 ) ) )
F_13 ( V_2 -> V_37 + V_22 ) ;
}
}
if ( V_21 >= V_25 )
F_14 ( V_2 -> V_41 , L_1 ) ;
}
static inline int F_15 ( struct V_1 * V_2 , int V_16 )
{
int V_42 ;
V_42 = ( V_16 - V_2 -> V_37 ) >> 4 ;
return ( V_42 * ( V_43 - V_32 ) ) ;
}
static inline int F_16 ( struct V_1 * V_2 , int V_16 )
{
return ( V_16 - V_2 -> V_37 ) & 0xf ;
}
static void F_17 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_18 ( V_20 ) ;
T_1 V_10 , V_27 , V_44 ;
unsigned long V_9 ;
V_27 = F_15 ( V_2 , V_20 -> V_16 ) ;
V_44 = F_16 ( V_2 , V_20 -> V_16 ) ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_10 = F_3 ( V_2 , V_27 + V_45 ) ;
V_10 |= 1 << V_44 ;
F_1 ( V_2 , V_27 + V_45 , V_10 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static void F_19 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_18 ( V_20 ) ;
int V_46 ;
unsigned long V_9 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_46 = F_3 ( V_2 ,
V_47 +
V_48 ) ;
V_46 &= ~ ( V_49 <<
( V_20 -> V_16 - ( V_2 -> V_37 + V_39 ) ) ) ;
F_1 ( V_2 ,
V_47 +
V_48 ,
V_46 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static void F_20 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_18 ( V_20 ) ;
T_1 V_10 , V_27 , V_44 ;
unsigned long V_9 ;
V_27 = F_15 ( V_2 , V_20 -> V_16 ) ;
V_44 = F_16 ( V_2 , V_20 -> V_16 ) ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_10 = F_3 ( V_2 , V_27 + V_45 ) ;
V_10 &= ~ ( 1 << V_44 ) ;
F_1 ( V_2 , V_27 + V_45 , V_10 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static void F_21 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_18 ( V_20 ) ;
int V_46 ;
unsigned long V_9 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_46 = F_3 ( V_2 ,
V_47 +
V_48 ) ;
V_46 |= ( V_49 <<
( V_20 -> V_16 - ( V_2 -> V_37 + V_39 ) ) ) ;
F_1 ( V_2 ,
V_47 +
V_48 ,
V_46 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static int F_22 ( struct V_19 * V_20 , unsigned int type )
{
struct V_1 * V_2 = F_18 ( V_20 ) ;
T_1 V_27 , V_44 ;
T_2 V_50 , V_51 , V_14 , V_13 ;
unsigned long V_9 ;
V_27 = F_15 ( V_2 , V_20 -> V_16 ) ;
V_44 = F_16 ( V_2 , V_20 -> V_16 ) ;
V_13 = 1 << V_44 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_51 = F_3 ( V_2 ,
V_27 + V_52 ) ;
V_14 = F_3 ( V_2 ,
V_27 + V_15 ) ;
V_50 = F_3 ( V_2 ,
V_27 + V_53 ) ;
V_2 -> V_38 [ ( V_20 -> V_16 - V_2 -> V_37 ) >> 4 ] &= ~ V_13 ;
if ( type == V_54 ) {
V_50 |= V_13 ;
V_14 |= V_13 ;
} else if ( type == V_55 ) {
V_50 |= V_13 ;
V_14 &= ~ V_13 ;
} else if ( type == V_56 ) {
V_50 |= V_13 ;
if ( F_23 ( & V_2 -> V_57 , V_20 -> V_16 - V_2 -> V_37 ) )
V_14 &= ~ V_13 ;
else
V_14 |= V_13 ;
V_2 -> V_38 [ ( V_20 -> V_16 - V_2 -> V_37 ) >> 4 ] |= V_13 ;
} else if ( type == V_58 ) {
V_50 &= ~ V_13 ;
V_51 &= ~ V_13 ;
} else if ( type == V_59 ) {
V_50 &= ~ V_13 ;
V_51 |= V_13 ;
} else {
F_24 ( V_2 -> V_41 , L_2 ) ;
}
F_1 ( V_2 , V_27 + V_52 ,
V_51 ) ;
F_1 ( V_2 , V_27 + V_15 ,
V_14 ) ;
F_1 ( V_2 , V_27 + V_53 ,
V_50 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
return 0 ;
}
static int T_3 F_25 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_26 ( V_61 ) ;
unsigned long V_62 = 0 ;
unsigned int V_16 , V_37 ;
int V_63 ;
V_63 = F_27 ( V_61 , 0 ) ;
if ( V_63 < 0 )
return V_63 ;
V_2 -> V_64 = V_63 ;
V_62 |= V_65 ;
F_1 ( V_2 , F_12 ( CLOCK , V_66 ) ,
V_62 ) ;
V_37 = V_2 -> V_37 ;
for ( V_16 = V_37 ; V_16 < V_37 + V_40 ; V_16 ++ ) {
if ( V_16 < V_2 -> V_37 + V_39 )
F_28 ( V_16 , & V_67 ) ;
else
F_28 ( V_16 , & V_68 ) ;
F_29 ( V_16 , V_2 ) ;
F_30 ( V_16 , V_69 ) ;
F_31 ( V_16 , V_70 | V_71 ) ;
}
F_1 ( V_2 , F_12 ( V_28 , V_72 ) ,
V_73 ) ;
F_32 ( V_2 -> V_64 , F_9 ) ;
F_33 ( V_2 -> V_64 , V_54 ) ;
F_34 ( V_2 -> V_64 , V_2 ) ;
return 0 ;
}
static void F_35 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_26 ( V_61 ) ;
unsigned int V_16 , V_37 ;
V_37 = V_2 -> V_37 ;
for ( V_16 = V_37 ; V_16 < V_37 + V_40 ; V_16 ++ ) {
F_31 ( V_16 , 0 ) ;
F_36 ( V_16 , NULL , NULL ) ;
F_29 ( V_16 , NULL ) ;
}
F_32 ( V_2 -> V_64 , NULL ) ;
}
static int F_37 ( struct V_74 * V_23 ,
unsigned V_75 , int V_76 )
{
T_1 V_77 = F_38 ( V_75 ) , V_78 ;
unsigned int V_79 ;
unsigned long V_9 ;
struct V_1 * V_2 ;
V_2 = F_39 ( V_23 , struct V_1 , V_57 ) ;
V_79 = F_40 ( V_75 ) ;
if ( V_79 > V_80 ) {
F_14 ( V_2 -> V_41 , L_3 ,
V_79 , V_75 ) ;
return - V_81 ;
}
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_78 = F_3 ( V_2 , V_79 + V_82 ) ;
if ( V_76 )
V_78 |= V_77 ;
else
V_78 &= ~ V_77 ;
F_1 ( V_2 , V_79 + V_82 , V_78 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_41 ( struct V_74 * V_23 ,
unsigned V_75 )
{
return F_37 ( V_23 , V_75 , 0 ) ;
}
static int F_42 ( struct V_74 * V_23 ,
unsigned V_75 , int V_4 )
{
return F_37 ( V_23 , V_75 , 1 ) ;
}
static int F_23 ( struct V_74 * V_23 ,
unsigned V_75 )
{
unsigned int V_79 ;
T_1 V_77 = F_38 ( V_75 ) ;
struct V_1 * V_2 ;
V_2 = F_39 ( V_23 , struct V_1 , V_57 ) ;
V_79 = F_40 ( V_75 ) ;
if ( V_79 > V_80 ) {
F_14 ( V_2 -> V_41 , L_3 ,
V_79 , V_75 ) ;
return - V_81 ;
}
return F_3 ( V_2 , V_79 + V_83 ) & V_77 ;
}
static void F_43 ( struct V_74 * V_23 ,
unsigned V_75 , int V_4 )
{
T_1 V_77 , V_78 ;
unsigned int V_79 ;
unsigned long V_9 ;
struct V_1 * V_2 ;
V_2 = F_39 ( V_23 , struct V_1 , V_57 ) ;
V_79 = F_40 ( V_75 ) ;
if ( V_79 > V_80 ) {
F_14 ( V_2 -> V_41 , L_3 ,
V_79 , V_75 ) ;
return;
}
V_77 = F_38 ( V_75 ) ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_78 = F_3 ( V_2 , V_79 + V_84 ) ;
if ( V_4 )
V_78 |= V_77 ;
else
V_78 &= ~ V_77 ;
F_1 ( V_2 , V_79 + V_84 , V_78 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
return;
}
static int F_44 ( struct V_74 * V_23 , unsigned V_75 )
{
struct V_1 * V_2 = F_39 ( V_23 , struct V_1 , V_57 ) ;
return ( V_75 < V_39 ) ? V_2 -> V_37 + V_75 : - V_85 ;
}
static T_3 int F_45 ( struct V_60 * V_61 ,
T_2 * V_86 , int V_87 )
{
struct V_1 * V_2 = F_26 ( V_61 ) ;
T_2 V_88 [ V_30 ] ;
T_2 V_78 [ V_30 ] ;
T_2 V_89 [ V_30 ] ;
int V_22 ;
memset ( V_88 , 0 , V_30 * sizeof( T_2 ) ) ;
memset ( V_78 , 0 , V_30 * sizeof( T_2 ) ) ;
memset ( V_89 , 0 , V_30 * sizeof( T_2 ) ) ;
F_1 ( V_2 , F_46 ( V_90 , V_91 ) , 0xffff ) ;
F_1 ( V_2 , F_46 ( V_92 , V_91 ) , 0xffff ) ;
F_1 ( V_2 , F_46 ( V_93 , V_91 ) , 0xffff ) ;
F_1 ( V_2 , F_46 ( V_94 , V_91 ) , 0xffff ) ;
for ( V_22 = 0 ; V_22 < V_87 ; V_22 ++ ) {
T_4 V_95 , V_96 , V_97 , V_98 , V_99 , V_100 ;
T_2 V_101 = V_86 [ V_22 ] ;
V_96 = F_47 ( V_101 ) ;
V_95 = F_48 ( V_101 ) ;
V_97 = F_49 ( V_101 ) ;
V_98 = F_50 ( V_101 ) ;
V_99 = F_51 ( V_96 ) ;
V_100 = F_52 ( V_96 ) ;
V_88 [ V_99 ] |= ( V_95 << V_100 ) ;
V_78 [ V_99 ] |= ( V_98 << V_100 ) ;
V_89 [ V_99 ] |= ( V_97 << V_100 ) ;
}
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ ) {
F_1 ( V_2 ,
F_53 ( V_22 ) +
V_82 ,
V_89 [ V_22 ] ) ;
F_1 ( V_2 ,
F_53 ( V_22 ) + V_84 ,
V_78 [ V_22 ] ) ;
F_1 ( V_2 ,
F_53 ( V_22 ) +
V_102 ,
V_88 [ V_22 ] ) ;
}
return F_54 ( & V_2 -> V_57 ) ;
}
static int F_55 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_26 ( V_61 ) ;
return F_56 ( & V_2 -> V_57 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
unsigned long V_9 ;
T_1 V_105 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
if ( V_104 -> V_106 ++ == 0 ) {
V_105 = F_3 ( V_2 , F_12 ( CLOCK , V_107 ) ) ;
V_105 |= V_104 -> V_105 ;
F_1 ( V_2 , F_12 ( CLOCK , V_107 ) , V_105 ) ;
}
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static void F_58 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
unsigned long V_9 ;
T_1 V_105 ;
F_59 ( V_104 -> V_106 == 0 ) ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
if ( -- V_104 -> V_106 == 0 ) {
V_105 = F_3 ( V_2 , F_12 ( CLOCK , V_107 ) ) ;
V_105 &= ~ V_104 -> V_105 ;
F_1 ( V_2 , F_12 ( CLOCK , V_107 ) , V_105 ) ;
}
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static int F_60 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_61 ( V_61 -> V_41 . V_108 ) ;
F_57 ( V_2 , & V_2 -> V_109 [ V_110 ] ) ;
F_57 ( V_2 , & V_2 -> V_109 [ V_111 ] ) ;
F_57 ( V_2 , & V_2 -> V_109 [ V_112 ] ) ;
F_62 ( 1 ) ;
F_5 ( V_2 , F_12 ( V_113 , V_114 ) ,
V_115 , 1 ) ;
F_62 ( 1 ) ;
F_5 ( V_2 , F_12 ( V_113 , V_114 ) ,
V_115 , 0 ) ;
F_62 ( 1 ) ;
F_5 ( V_2 , F_12 ( V_113 , V_116 ) ,
V_117 , 1 ) ;
F_62 ( 1 ) ;
return 0 ;
}
static int F_63 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_61 ( V_61 -> V_41 . V_108 ) ;
F_5 ( V_2 , F_12 ( V_113 , V_116 ) ,
V_117 , 0 ) ;
F_58 ( V_2 , & V_2 -> V_109 [ V_112 ] ) ;
F_58 ( V_2 , & V_2 -> V_109 [ V_110 ] ) ;
F_58 ( V_2 , & V_2 -> V_109 [ V_111 ] ) ;
return 0 ;
}
static void F_64 ( struct V_60 * V_61 , int V_118 )
{
struct V_1 * V_2 = F_61 ( V_61 -> V_41 . V_108 ) ;
F_65 ( V_2 -> V_119 , 1 - V_2 -> V_6 , V_118 ) ;
}
static void F_66 ( struct V_60 * V_61 , int V_118 )
{
struct V_1 * V_2 = F_61 ( V_61 -> V_41 . V_108 ) ;
F_67 ( V_2 -> V_119 , 1 - V_2 -> V_6 , V_118 ) ;
}
static int F_68 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_61 ( V_61 -> V_41 . V_108 ) ;
F_5 ( V_2 , F_12 ( V_120 , V_121 ) ,
V_122 , 1 ) ;
F_5 ( V_2 , F_12 ( V_120 , V_121 ) ,
V_123 , 1 ) ;
F_5 ( V_2 , F_12 ( V_120 , V_121 ) ,
V_124 , 0 ) ;
F_5 ( V_2 , F_12 ( V_120 , V_121 ) ,
V_125 , 0 ) ;
F_57 ( V_2 , & V_2 -> V_109 [ V_110 ] ) ;
F_57 ( V_2 , & V_2 -> V_109 [ V_111 ] ) ;
F_62 ( 1 ) ;
F_1 ( V_2 , F_12 ( CLOCK , V_66 ) ,
V_65 | V_126 ) ;
F_57 ( V_2 , & V_2 -> V_109 [ V_127 ] ) ;
F_57 ( V_2 , & V_2 -> V_109 [ V_128 ] ) ;
F_62 ( 1 ) ;
F_5 ( V_2 , F_12 ( V_113 , V_116 ) ,
V_129 , 1 ) ;
F_5 ( V_2 , F_12 ( V_120 , V_121 ) ,
V_130 , 1 ) ;
F_69 ( V_2 -> V_119 , 1 - V_2 -> V_6 ,
V_131 >> 1 ) ;
return 0 ;
}
static int F_70 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_61 ( V_61 -> V_41 . V_108 ) ;
F_5 ( V_2 , F_12 ( V_120 , V_121 ) ,
V_124 , 1 ) ;
F_58 ( V_2 , & V_2 -> V_109 [ V_127 ] ) ;
F_58 ( V_2 , & V_2 -> V_109 [ V_128 ] ) ;
F_58 ( V_2 , & V_2 -> V_109 [ V_110 ] ) ;
F_58 ( V_2 , & V_2 -> V_109 [ V_111 ] ) ;
return 0 ;
}
static int F_71 ( struct V_60 * V_61 )
{
const struct V_132 * V_133 = F_72 ( V_61 ) ;
struct V_1 * V_2 = F_61 ( V_61 -> V_41 . V_108 ) ;
F_57 ( V_2 , & V_2 -> V_109 [ V_134 [ V_133 -> V_135 ] ] ) ;
return 0 ;
}
static int F_73 ( struct V_60 * V_61 )
{
const struct V_132 * V_133 = F_72 ( V_61 ) ;
struct V_1 * V_2 = F_61 ( V_61 -> V_41 . V_108 ) ;
F_58 ( V_2 , & V_2 -> V_109 [ V_134 [ V_133 -> V_135 ] ] ) ;
return 0 ;
}
static int F_74 ( struct V_60 * V_61 )
{
const struct V_132 * V_133 = F_72 ( V_61 ) ;
struct V_1 * V_2 = F_61 ( V_61 -> V_41 . V_108 ) ;
while ( F_23 ( & V_2 -> V_57 , F_75 ( V_93 , V_133 -> V_135 ) ) != 0 )
F_62 ( 1 ) ;
F_58 ( V_2 , & V_2 -> V_109 [ V_134 [ V_133 -> V_135 ] ] ) ;
return 0 ;
}
static int T_3 F_76 ( struct V_60 * V_61 ,
struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_26 ( V_61 ) ;
struct V_138 * V_140 ;
int V_16 , V_63 ;
V_140 = F_77 ( V_61 , V_141 , 1 ) ;
if ( ! V_140 )
F_78 ( V_2 -> V_41 , L_4 ) ;
V_16 = F_27 ( V_61 , 1 ) ;
if ( V_16 < 0 )
F_78 ( V_2 -> V_41 , L_5 ) ;
F_5 ( V_2 , F_12 ( V_113 , V_116 ) ,
V_142 , 0 ) ;
V_143 [ 0 ] . V_144 >>= V_2 -> V_6 ;
V_143 [ 0 ] . V_145 >>= V_2 -> V_6 ;
V_2 -> V_119 = F_79 ( ( V_146 >> V_2 -> V_6 ) +
V_140 -> V_144 ,
V_147 >> V_2 -> V_6 ) ;
if ( ! V_2 -> V_119 ) {
V_63 = - V_148 ;
F_78 ( V_2 -> V_41 , L_6 ) ;
goto V_76;
}
V_149 [ 0 ] . V_144 >>= V_2 -> V_6 ;
V_149 [ 0 ] . V_145 >>= V_2 -> V_6 ;
V_63 = F_80 ( & V_61 -> V_41 , V_61 -> V_135 ,
& V_150 , 1 , V_139 , V_2 -> V_37 ) ;
if ( V_63 < 0 )
goto V_76;
if ( V_140 && ( V_16 >= 0 ) ) {
V_63 = F_80 ( & V_61 -> V_41 , V_61 -> V_135 ,
& V_151 , 1 , V_140 , V_16 ) ;
if ( V_63 < 0 )
goto V_76;
}
if ( V_137 -> V_152 ) {
int V_22 ;
for ( V_22 = 0 ; V_22 < V_153 ; ++ V_22 ) {
V_154 [ V_22 ] . V_155 = & V_137 -> V_152 [ V_22 ] ;
V_154 [ V_22 ] . V_156 = sizeof( V_137 -> V_152 [ V_22 ] ) ;
}
V_63 = F_80 ( & V_61 -> V_41 , 0 ,
V_154 , V_153 , NULL , 0 ) ;
}
V_76:
return V_63 ;
}
static void F_81 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_26 ( V_61 ) ;
F_82 ( & V_61 -> V_41 ) ;
F_83 ( V_2 -> V_119 ) ;
}
static int T_3 F_84 ( struct V_60 * V_61 )
{
struct V_136 * V_137 = V_61 -> V_41 . V_155 ;
struct V_1 * V_2 ;
struct V_138 * V_139 ;
unsigned long V_62 ;
int V_63 = 0 ;
V_2 = F_85 ( sizeof( struct V_1 ) , V_157 ) ;
if ( V_2 == NULL ) {
F_86 ( V_158 L_7 ) ;
return - V_148 ;
}
F_87 ( & V_2 -> V_11 ) ;
F_88 ( V_61 , V_2 ) ;
V_2 -> V_41 = & V_61 -> V_41 ;
V_139 = F_77 ( V_61 , V_141 , 0 ) ;
if ( ! V_139 ) {
V_63 = - V_148 ;
F_14 ( V_2 -> V_41 , L_8 ) ;
goto V_159;
}
V_2 -> V_5 = F_79 ( V_139 -> V_144 , F_89 ( V_139 ) ) ;
if ( ! V_2 -> V_5 ) {
V_63 = - V_148 ;
F_14 ( V_2 -> V_41 , L_9 ) ;
goto V_159;
}
V_2 -> V_37 = V_137 -> V_37 ;
V_2 -> V_6 = 2 - ( F_89 ( V_139 ) >> 12 ) ;
V_62 = 0 ;
F_1 ( V_2 , F_12 ( CLOCK , V_66 ) , V_62 ) ;
V_63 = F_25 ( V_61 ) ;
if ( V_63 < 0 ) {
F_14 ( V_2 -> V_41 , L_10 ) ;
goto V_160;
}
V_2 -> V_57 . V_161 = L_11 ;
V_2 -> V_57 . V_12 = V_137 -> V_79 ;
V_2 -> V_57 . V_162 = V_39 ;
V_2 -> V_57 . V_163 = F_23 ;
V_2 -> V_57 . V_8 = F_43 ;
V_2 -> V_57 . V_164 = F_41 ;
V_2 -> V_57 . V_165 = F_42 ;
V_2 -> V_57 . V_166 = F_44 ;
V_63 = F_45 ( V_61 ,
V_137 -> V_86 ,
V_137 -> V_167 ) ;
if ( V_63 < 0 ) {
F_14 ( V_2 -> V_41 , L_12 ) ;
goto V_168;
}
memcpy ( V_2 -> V_109 , V_169 , sizeof( V_169 ) ) ;
F_76 ( V_61 , V_137 , V_139 ) ;
F_90 ( V_2 -> V_41 , L_13 ) ;
return 0 ;
V_168:
F_35 ( V_61 ) ;
V_160:
F_83 ( V_2 -> V_5 ) ;
V_159:
F_91 ( V_2 ) ;
return V_63 ;
}
static int T_5 F_92 ( struct V_60 * V_61 )
{
int V_63 ;
struct V_1 * V_2 = F_26 ( V_61 ) ;
F_81 ( V_61 ) ;
V_63 = F_55 ( V_61 ) ;
if ( V_63 < 0 )
return V_63 ;
F_35 ( V_61 ) ;
F_1 ( V_2 , F_12 ( CLOCK , V_66 ) , 0 ) ;
F_83 ( V_2 -> V_5 ) ;
F_91 ( V_2 ) ;
return 0 ;
}
static void F_93 ( struct V_60 * V_61 )
{
}
static int T_3 F_94 ( void )
{
int V_170 = 0 ;
V_170 = F_95 ( & V_171 , F_84 ) ;
return V_170 ;
}
