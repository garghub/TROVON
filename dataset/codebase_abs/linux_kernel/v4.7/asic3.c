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
static void F_9 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_10 ( V_17 ) ;
struct V_18 * V_19 = F_11 ( V_17 ) ;
int V_20 , V_21 ;
unsigned long V_9 ;
V_19 -> V_22 -> V_23 ( V_19 ) ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
T_1 V_25 ;
int V_26 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_25 = F_3 ( V_2 ,
F_12 ( V_27 , V_28 ) ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
if ( ( V_25 & 0x3ff ) == 0 )
break;
for ( V_26 = 0 ; V_26 < V_29 ; V_26 ++ ) {
if ( V_25 & ( 1 << V_26 ) ) {
unsigned long V_12 , V_30 ;
V_12 = V_31
+ V_26 * V_32 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_30 = F_3 ( V_2 ,
V_12 +
V_33 ) ;
F_1 ( V_2 ,
V_12 +
V_33 , 0 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
for ( V_21 = 0 ; V_21 < V_34 ; V_21 ++ ) {
int V_13 = ( 1 << V_21 ) ;
unsigned int V_35 ;
if ( ! ( V_30 & V_13 ) )
continue;
V_35 = V_2 -> V_36 +
( V_34 * V_26 )
+ V_21 ;
F_13 ( V_35 ) ;
if ( V_2 -> V_37 [ V_26 ] & V_13 )
F_8 ( V_2 , V_12 ,
V_13 ) ;
}
}
}
for ( V_21 = V_38 ; V_21 < V_39 ; V_21 ++ ) {
if ( V_25 & ( 1 << ( V_21 - V_38 + 4 ) ) )
F_13 ( V_2 -> V_36 + V_21 ) ;
}
}
if ( V_20 >= V_24 )
F_14 ( V_2 -> V_40 , L_1 ) ;
}
static inline int F_15 ( struct V_1 * V_2 , int V_41 )
{
int V_42 ;
V_42 = ( V_41 - V_2 -> V_36 ) >> 4 ;
return ( V_42 * ( V_43 - V_31 ) ) ;
}
static inline int F_16 ( struct V_1 * V_2 , int V_41 )
{
return ( V_41 - V_2 -> V_36 ) & 0xf ;
}
static void F_17 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_18 ( V_19 ) ;
T_1 V_10 , V_26 , V_44 ;
unsigned long V_9 ;
V_26 = F_15 ( V_2 , V_19 -> V_41 ) ;
V_44 = F_16 ( V_2 , V_19 -> V_41 ) ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_10 = F_3 ( V_2 , V_26 + V_45 ) ;
V_10 |= 1 << V_44 ;
F_1 ( V_2 , V_26 + V_45 , V_10 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static void F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_18 ( V_19 ) ;
int V_46 ;
unsigned long V_9 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_46 = F_3 ( V_2 ,
V_47 +
V_48 ) ;
V_46 &= ~ ( V_49 <<
( V_19 -> V_41 - ( V_2 -> V_36 + V_38 ) ) ) ;
F_1 ( V_2 ,
V_47 +
V_48 ,
V_46 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static void F_20 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_18 ( V_19 ) ;
T_1 V_10 , V_26 , V_44 ;
unsigned long V_9 ;
V_26 = F_15 ( V_2 , V_19 -> V_41 ) ;
V_44 = F_16 ( V_2 , V_19 -> V_41 ) ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_10 = F_3 ( V_2 , V_26 + V_45 ) ;
V_10 &= ~ ( 1 << V_44 ) ;
F_1 ( V_2 , V_26 + V_45 , V_10 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static void F_21 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_18 ( V_19 ) ;
int V_46 ;
unsigned long V_9 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_46 = F_3 ( V_2 ,
V_47 +
V_48 ) ;
V_46 |= ( V_49 <<
( V_19 -> V_41 - ( V_2 -> V_36 + V_38 ) ) ) ;
F_1 ( V_2 ,
V_47 +
V_48 ,
V_46 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static int F_22 ( struct V_18 * V_19 , unsigned int type )
{
struct V_1 * V_2 = F_18 ( V_19 ) ;
T_1 V_26 , V_44 ;
T_2 V_50 , V_51 , V_14 , V_13 ;
unsigned long V_9 ;
V_26 = F_15 ( V_2 , V_19 -> V_41 ) ;
V_44 = F_16 ( V_2 , V_19 -> V_41 ) ;
V_13 = 1 << V_44 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_51 = F_3 ( V_2 ,
V_26 + V_52 ) ;
V_14 = F_3 ( V_2 ,
V_26 + V_15 ) ;
V_50 = F_3 ( V_2 ,
V_26 + V_53 ) ;
V_2 -> V_37 [ ( V_19 -> V_41 - V_2 -> V_36 ) >> 4 ] &= ~ V_13 ;
if ( type == V_54 ) {
V_50 |= V_13 ;
V_14 |= V_13 ;
} else if ( type == V_55 ) {
V_50 |= V_13 ;
V_14 &= ~ V_13 ;
} else if ( type == V_56 ) {
V_50 |= V_13 ;
if ( F_23 ( & V_2 -> V_57 , V_19 -> V_41 - V_2 -> V_36 ) )
V_14 &= ~ V_13 ;
else
V_14 |= V_13 ;
V_2 -> V_37 [ ( V_19 -> V_41 - V_2 -> V_36 ) >> 4 ] |= V_13 ;
} else if ( type == V_58 ) {
V_50 &= ~ V_13 ;
V_51 &= ~ V_13 ;
} else if ( type == V_59 ) {
V_50 &= ~ V_13 ;
V_51 |= V_13 ;
} else {
F_24 ( V_2 -> V_40 , L_2 ) ;
}
F_1 ( V_2 , V_26 + V_52 ,
V_51 ) ;
F_1 ( V_2 , V_26 + V_15 ,
V_14 ) ;
F_1 ( V_2 , V_26 + V_53 ,
V_50 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_25 ( struct V_18 * V_19 , unsigned int V_60 )
{
struct V_1 * V_2 = F_18 ( V_19 ) ;
T_1 V_26 , V_44 ;
T_2 V_13 ;
V_26 = F_15 ( V_2 , V_19 -> V_41 ) ;
V_44 = F_16 ( V_2 , V_19 -> V_41 ) ;
V_13 = 1 << V_44 ;
F_5 ( V_2 , V_26 + V_61 , V_13 , ! V_60 ) ;
return 0 ;
}
static int T_3 F_26 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_27 ( V_63 ) ;
unsigned long V_64 = 0 ;
unsigned int V_41 , V_36 ;
int V_65 ;
V_65 = F_28 ( V_63 , 0 ) ;
if ( V_65 < 0 )
return V_65 ;
V_2 -> V_66 = V_65 ;
V_64 |= V_67 ;
F_1 ( V_2 , F_12 ( CLOCK , V_68 ) ,
V_64 ) ;
V_36 = V_2 -> V_36 ;
for ( V_41 = V_36 ; V_41 < V_36 + V_39 ; V_41 ++ ) {
if ( V_41 < V_2 -> V_36 + V_38 )
F_29 ( V_41 , & V_69 ) ;
else
F_29 ( V_41 , & V_70 ) ;
F_30 ( V_41 , V_2 ) ;
F_31 ( V_41 , V_71 ) ;
F_32 ( V_41 , V_72 | V_73 ) ;
}
F_1 ( V_2 , F_12 ( V_27 , V_74 ) ,
V_75 ) ;
F_33 ( V_2 -> V_66 , F_9 , V_2 ) ;
F_34 ( V_2 -> V_66 , V_54 ) ;
return 0 ;
}
static void F_35 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_27 ( V_63 ) ;
unsigned int V_41 , V_36 ;
V_36 = V_2 -> V_36 ;
for ( V_41 = V_36 ; V_41 < V_36 + V_39 ; V_41 ++ ) {
F_36 ( V_41 , V_72 | V_73 ) ;
F_37 ( V_41 , NULL , NULL ) ;
F_30 ( V_41 , NULL ) ;
}
F_38 ( V_2 -> V_66 , NULL ) ;
}
static int F_39 ( struct V_76 * V_22 ,
unsigned V_77 , int V_78 )
{
T_1 V_79 = F_40 ( V_77 ) , V_80 ;
unsigned int V_81 ;
unsigned long V_9 ;
struct V_1 * V_2 ;
V_2 = F_41 ( V_22 ) ;
V_81 = F_42 ( V_77 ) ;
if ( V_81 > V_82 ) {
F_14 ( V_2 -> V_40 , L_3 ,
V_81 , V_77 ) ;
return - V_83 ;
}
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_80 = F_3 ( V_2 , V_81 + V_84 ) ;
if ( V_78 )
V_80 |= V_79 ;
else
V_80 &= ~ V_79 ;
F_1 ( V_2 , V_81 + V_84 , V_80 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_43 ( struct V_76 * V_22 ,
unsigned V_77 )
{
return F_39 ( V_22 , V_77 , 0 ) ;
}
static int F_44 ( struct V_76 * V_22 ,
unsigned V_77 , int V_4 )
{
return F_39 ( V_22 , V_77 , 1 ) ;
}
static int F_23 ( struct V_76 * V_22 ,
unsigned V_77 )
{
unsigned int V_81 ;
T_1 V_79 = F_40 ( V_77 ) ;
struct V_1 * V_2 ;
V_2 = F_41 ( V_22 ) ;
V_81 = F_42 ( V_77 ) ;
if ( V_81 > V_82 ) {
F_14 ( V_2 -> V_40 , L_3 ,
V_81 , V_77 ) ;
return - V_83 ;
}
return ! ! ( F_3 ( V_2 ,
V_81 + V_85 ) & V_79 ) ;
}
static void F_45 ( struct V_76 * V_22 ,
unsigned V_77 , int V_4 )
{
T_1 V_79 , V_80 ;
unsigned int V_81 ;
unsigned long V_9 ;
struct V_1 * V_2 ;
V_2 = F_41 ( V_22 ) ;
V_81 = F_42 ( V_77 ) ;
if ( V_81 > V_82 ) {
F_14 ( V_2 -> V_40 , L_3 ,
V_81 , V_77 ) ;
return;
}
V_79 = F_40 ( V_77 ) ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_80 = F_3 ( V_2 , V_81 + V_86 ) ;
if ( V_4 )
V_80 |= V_79 ;
else
V_80 &= ~ V_79 ;
F_1 ( V_2 , V_81 + V_86 , V_80 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static int F_46 ( struct V_76 * V_22 , unsigned V_77 )
{
struct V_1 * V_2 = F_41 ( V_22 ) ;
return V_2 -> V_36 + V_77 ;
}
static T_3 int F_47 ( struct V_62 * V_63 ,
T_2 * V_87 , int V_88 )
{
struct V_1 * V_2 = F_27 ( V_63 ) ;
T_2 V_89 [ V_29 ] ;
T_2 V_80 [ V_29 ] ;
T_2 V_90 [ V_29 ] ;
int V_21 ;
memset ( V_89 , 0 , V_29 * sizeof( T_2 ) ) ;
memset ( V_80 , 0 , V_29 * sizeof( T_2 ) ) ;
memset ( V_90 , 0 , V_29 * sizeof( T_2 ) ) ;
F_1 ( V_2 , F_48 ( V_91 , V_92 ) , 0xffff ) ;
F_1 ( V_2 , F_48 ( V_93 , V_92 ) , 0xffff ) ;
F_1 ( V_2 , F_48 ( V_94 , V_92 ) , 0xffff ) ;
F_1 ( V_2 , F_48 ( V_95 , V_92 ) , 0xffff ) ;
for ( V_21 = 0 ; V_21 < V_88 ; V_21 ++ ) {
T_4 V_96 , V_97 , V_98 , V_99 , V_100 , V_101 ;
T_2 V_102 = V_87 [ V_21 ] ;
V_97 = F_49 ( V_102 ) ;
V_96 = F_50 ( V_102 ) ;
V_98 = F_51 ( V_102 ) ;
V_99 = F_52 ( V_102 ) ;
V_100 = F_53 ( V_97 ) ;
V_101 = F_54 ( V_97 ) ;
V_89 [ V_100 ] |= ( V_96 << V_101 ) ;
V_80 [ V_100 ] |= ( V_99 << V_101 ) ;
V_90 [ V_100 ] |= ( V_98 << V_101 ) ;
}
for ( V_21 = 0 ; V_21 < V_29 ; V_21 ++ ) {
F_1 ( V_2 ,
F_55 ( V_21 ) +
V_84 ,
V_90 [ V_21 ] ) ;
F_1 ( V_2 ,
F_55 ( V_21 ) + V_86 ,
V_80 [ V_21 ] ) ;
F_1 ( V_2 ,
F_55 ( V_21 ) +
V_103 ,
V_89 [ V_21 ] ) ;
}
return F_56 ( & V_2 -> V_57 , V_2 ) ;
}
static int F_57 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_27 ( V_63 ) ;
F_58 ( & V_2 -> V_57 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
unsigned long V_9 ;
T_1 V_106 ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
if ( V_105 -> V_107 ++ == 0 ) {
V_106 = F_3 ( V_2 , F_12 ( CLOCK , V_108 ) ) ;
V_106 |= V_105 -> V_106 ;
F_1 ( V_2 , F_12 ( CLOCK , V_108 ) , V_106 ) ;
}
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static void F_60 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
unsigned long V_9 ;
T_1 V_106 ;
F_61 ( V_105 -> V_107 == 0 ) ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
if ( -- V_105 -> V_107 == 0 ) {
V_106 = F_3 ( V_2 , F_12 ( CLOCK , V_108 ) ) ;
V_106 &= ~ V_105 -> V_106 ;
F_1 ( V_2 , F_12 ( CLOCK , V_108 ) , V_106 ) ;
}
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static int F_62 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_63 ( V_63 -> V_40 . V_109 ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_111 ] ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_112 ] ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_113 ] ) ;
F_64 ( 1000 , 5000 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_115 ) ,
V_116 , 1 ) ;
F_64 ( 1000 , 5000 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_115 ) ,
V_116 , 0 ) ;
F_64 ( 1000 , 5000 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_117 ) ,
V_118 , 1 ) ;
F_64 ( 1000 , 5000 ) ;
return 0 ;
}
static int F_65 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_63 ( V_63 -> V_40 . V_109 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_117 ) ,
V_118 , 0 ) ;
F_60 ( V_2 , & V_2 -> V_110 [ V_113 ] ) ;
F_60 ( V_2 , & V_2 -> V_110 [ V_111 ] ) ;
F_60 ( V_2 , & V_2 -> V_110 [ V_112 ] ) ;
return 0 ;
}
static void F_66 ( struct V_62 * V_63 , int V_119 )
{
struct V_1 * V_2 = F_63 ( V_63 -> V_40 . V_109 ) ;
F_67 ( V_2 -> V_120 , 1 - V_2 -> V_6 , V_119 ) ;
}
static void F_68 ( struct V_62 * V_63 , int V_119 )
{
struct V_1 * V_2 = F_63 ( V_63 -> V_40 . V_109 ) ;
F_69 ( V_2 -> V_120 , 1 - V_2 -> V_6 , V_119 ) ;
}
static int F_70 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_63 ( V_63 -> V_40 . V_109 ) ;
F_5 ( V_2 , F_12 ( V_121 , V_122 ) ,
V_123 , 1 ) ;
F_5 ( V_2 , F_12 ( V_121 , V_122 ) ,
V_124 , 1 ) ;
F_5 ( V_2 , F_12 ( V_121 , V_122 ) ,
V_125 , 0 ) ;
F_5 ( V_2 , F_12 ( V_121 , V_122 ) ,
V_126 , 0 ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_111 ] ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_112 ] ) ;
F_64 ( 1000 , 5000 ) ;
F_1 ( V_2 , F_12 ( CLOCK , V_68 ) ,
V_67 | V_127 ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_128 ] ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_129 ] ) ;
F_64 ( 1000 , 5000 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_117 ) ,
V_130 , 1 ) ;
F_5 ( V_2 , F_12 ( V_121 , V_122 ) ,
V_131 , 1 ) ;
F_71 ( V_2 -> V_120 , 1 - V_2 -> V_6 ,
V_132 >> 1 ) ;
return 0 ;
}
static int F_72 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_63 ( V_63 -> V_40 . V_109 ) ;
F_5 ( V_2 , F_12 ( V_121 , V_122 ) ,
V_125 , 1 ) ;
F_60 ( V_2 , & V_2 -> V_110 [ V_128 ] ) ;
F_60 ( V_2 , & V_2 -> V_110 [ V_129 ] ) ;
F_60 ( V_2 , & V_2 -> V_110 [ V_111 ] ) ;
F_60 ( V_2 , & V_2 -> V_110 [ V_112 ] ) ;
return 0 ;
}
static int F_73 ( struct V_62 * V_63 )
{
const struct V_133 * V_134 = F_74 ( V_63 ) ;
struct V_1 * V_2 = F_63 ( V_63 -> V_40 . V_109 ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_135 [ V_134 -> V_136 ] ] ) ;
return 0 ;
}
static int F_75 ( struct V_62 * V_63 )
{
const struct V_133 * V_134 = F_74 ( V_63 ) ;
struct V_1 * V_2 = F_63 ( V_63 -> V_40 . V_109 ) ;
F_60 ( V_2 , & V_2 -> V_110 [ V_135 [ V_134 -> V_136 ] ] ) ;
return 0 ;
}
static int F_76 ( struct V_62 * V_63 )
{
const struct V_133 * V_134 = F_74 ( V_63 ) ;
struct V_1 * V_2 = F_63 ( V_63 -> V_40 . V_109 ) ;
while ( F_23 ( & V_2 -> V_57 , F_77 ( V_94 , V_134 -> V_136 ) ) != 0 )
F_64 ( 1000 , 5000 ) ;
F_60 ( V_2 , & V_2 -> V_110 [ V_135 [ V_134 -> V_136 ] ] ) ;
return 0 ;
}
static int T_3 F_78 ( struct V_62 * V_63 ,
struct V_137 * V_138 ,
struct V_139 * V_140 )
{
struct V_1 * V_2 = F_27 ( V_63 ) ;
struct V_139 * V_141 ;
int V_41 , V_65 ;
V_141 = F_79 ( V_63 , V_142 , 1 ) ;
if ( ! V_141 )
F_80 ( V_2 -> V_40 , L_4 ) ;
V_41 = F_28 ( V_63 , 1 ) ;
if ( V_41 < 0 )
F_80 ( V_2 -> V_40 , L_5 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_117 ) ,
V_143 , 0 ) ;
V_144 [ 0 ] . V_145 >>= V_2 -> V_6 ;
V_144 [ 0 ] . V_146 >>= V_2 -> V_6 ;
if ( V_141 ) {
V_2 -> V_120 = F_81 ( ( V_147 >>
V_2 -> V_6 ) + V_141 -> V_145 ,
V_148 >> V_2 -> V_6 ) ;
if ( ! V_2 -> V_120 ) {
V_65 = - V_149 ;
F_80 ( V_2 -> V_40 , L_6 ) ;
goto V_78;
}
}
V_150 [ 0 ] . V_145 >>= V_2 -> V_6 ;
V_150 [ 0 ] . V_146 >>= V_2 -> V_6 ;
if ( V_138 -> V_151 ) {
V_152 . V_151 = V_138 -> V_151 ;
V_65 = F_82 ( & V_63 -> V_40 , V_63 -> V_136 ,
& V_153 , 1 , V_140 , V_2 -> V_36 , NULL ) ;
if ( V_65 < 0 )
goto V_78;
}
if ( V_141 && ( V_41 >= 0 ) ) {
V_65 = F_82 ( & V_63 -> V_40 , V_63 -> V_136 ,
& V_154 , 1 , V_141 , V_41 , NULL ) ;
if ( V_65 < 0 )
goto V_78;
}
V_65 = 0 ;
if ( V_138 -> V_155 ) {
int V_21 ;
for ( V_21 = 0 ; V_21 < V_156 ; ++ V_21 ) {
V_157 [ V_21 ] . V_158 = & V_138 -> V_155 [ V_21 ] ;
V_157 [ V_21 ] . V_159 = sizeof( V_138 -> V_155 [ V_21 ] ) ;
}
V_65 = F_82 ( & V_63 -> V_40 , 0 ,
V_157 , V_156 , NULL , 0 , NULL ) ;
}
V_78:
return V_65 ;
}
static void F_83 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_27 ( V_63 ) ;
F_84 ( & V_63 -> V_40 ) ;
F_85 ( V_2 -> V_120 ) ;
}
static int T_3 F_86 ( struct V_62 * V_63 )
{
struct V_137 * V_138 = F_87 ( & V_63 -> V_40 ) ;
struct V_1 * V_2 ;
struct V_139 * V_140 ;
unsigned long V_64 ;
int V_65 = 0 ;
V_2 = F_88 ( & V_63 -> V_40 ,
sizeof( struct V_1 ) , V_160 ) ;
if ( ! V_2 )
return - V_149 ;
F_89 ( & V_2 -> V_11 ) ;
F_90 ( V_63 , V_2 ) ;
V_2 -> V_40 = & V_63 -> V_40 ;
V_140 = F_79 ( V_63 , V_142 , 0 ) ;
if ( ! V_140 ) {
F_14 ( V_2 -> V_40 , L_7 ) ;
return - V_149 ;
}
V_2 -> V_5 = F_81 ( V_140 -> V_145 , F_91 ( V_140 ) ) ;
if ( ! V_2 -> V_5 ) {
F_14 ( V_2 -> V_40 , L_8 ) ;
return - V_149 ;
}
V_2 -> V_36 = V_138 -> V_36 ;
V_2 -> V_6 = 2 - ( F_91 ( V_140 ) >> 12 ) ;
V_64 = 0 ;
F_1 ( V_2 , F_12 ( CLOCK , V_68 ) , V_64 ) ;
V_65 = F_26 ( V_63 ) ;
if ( V_65 < 0 ) {
F_14 ( V_2 -> V_40 , L_9 ) ;
goto V_161;
}
V_2 -> V_57 . V_162 = L_10 ;
V_2 -> V_57 . V_12 = V_138 -> V_81 ;
V_2 -> V_57 . V_163 = V_38 ;
V_2 -> V_57 . V_164 = F_23 ;
V_2 -> V_57 . V_8 = F_45 ;
V_2 -> V_57 . V_165 = F_43 ;
V_2 -> V_57 . V_166 = F_44 ;
V_2 -> V_57 . V_167 = F_46 ;
V_65 = F_47 ( V_63 ,
V_138 -> V_87 ,
V_138 -> V_168 ) ;
if ( V_65 < 0 ) {
F_14 ( V_2 -> V_40 , L_11 ) ;
goto V_169;
}
memcpy ( V_2 -> V_110 , V_170 , sizeof( V_170 ) ) ;
F_78 ( V_63 , V_138 , V_140 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_117 ) ,
( V_171 | V_172 ) , 1 ) ;
F_92 ( V_2 -> V_40 , L_12 ) ;
return 0 ;
V_169:
F_35 ( V_63 ) ;
V_161:
F_85 ( V_2 -> V_5 ) ;
return V_65 ;
}
static int F_93 ( struct V_62 * V_63 )
{
int V_65 ;
struct V_1 * V_2 = F_27 ( V_63 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_117 ) ,
( V_171 | V_172 ) , 0 ) ;
F_83 ( V_63 ) ;
V_65 = F_57 ( V_63 ) ;
if ( V_65 < 0 )
return V_65 ;
F_35 ( V_63 ) ;
F_1 ( V_2 , F_12 ( CLOCK , V_68 ) , 0 ) ;
F_85 ( V_2 -> V_5 ) ;
return 0 ;
}
static void F_94 ( struct V_62 * V_63 )
{
}
static int T_3 F_95 ( void )
{
int V_173 = 0 ;
V_173 = F_96 ( & V_174 , F_86 ) ;
return V_173 ;
}
