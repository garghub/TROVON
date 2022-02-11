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
static int F_25 ( struct V_19 * V_20 , unsigned int V_60 )
{
struct V_1 * V_2 = F_18 ( V_20 ) ;
T_1 V_27 , V_44 ;
T_2 V_13 ;
V_27 = F_15 ( V_2 , V_20 -> V_16 ) ;
V_44 = F_16 ( V_2 , V_20 -> V_16 ) ;
V_13 = 1 << V_44 ;
F_5 ( V_2 , V_27 + V_61 , V_13 , ! V_60 ) ;
return 0 ;
}
static int T_3 F_26 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_27 ( V_63 ) ;
unsigned long V_64 = 0 ;
unsigned int V_16 , V_37 ;
int V_65 ;
V_65 = F_28 ( V_63 , 0 ) ;
if ( V_65 < 0 )
return V_65 ;
V_2 -> V_66 = V_65 ;
V_64 |= V_67 ;
F_1 ( V_2 , F_12 ( CLOCK , V_68 ) ,
V_64 ) ;
V_37 = V_2 -> V_37 ;
for ( V_16 = V_37 ; V_16 < V_37 + V_40 ; V_16 ++ ) {
if ( V_16 < V_2 -> V_37 + V_39 )
F_29 ( V_16 , & V_69 ) ;
else
F_29 ( V_16 , & V_70 ) ;
F_30 ( V_16 , V_2 ) ;
F_31 ( V_16 , V_71 ) ;
F_32 ( V_16 , V_72 | V_73 ) ;
}
F_1 ( V_2 , F_12 ( V_28 , V_74 ) ,
V_75 ) ;
F_33 ( V_2 -> V_66 , F_9 ) ;
F_34 ( V_2 -> V_66 , V_54 ) ;
F_35 ( V_2 -> V_66 , V_2 ) ;
return 0 ;
}
static void F_36 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_27 ( V_63 ) ;
unsigned int V_16 , V_37 ;
V_37 = V_2 -> V_37 ;
for ( V_16 = V_37 ; V_16 < V_37 + V_40 ; V_16 ++ ) {
F_32 ( V_16 , 0 ) ;
F_37 ( V_16 , NULL , NULL ) ;
F_30 ( V_16 , NULL ) ;
}
F_33 ( V_2 -> V_66 , NULL ) ;
}
static int F_38 ( struct V_76 * V_23 ,
unsigned V_77 , int V_78 )
{
T_1 V_79 = F_39 ( V_77 ) , V_80 ;
unsigned int V_81 ;
unsigned long V_9 ;
struct V_1 * V_2 ;
V_2 = F_40 ( V_23 , struct V_1 , V_57 ) ;
V_81 = F_41 ( V_77 ) ;
if ( V_81 > V_82 ) {
F_14 ( V_2 -> V_41 , L_3 ,
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
static int F_42 ( struct V_76 * V_23 ,
unsigned V_77 )
{
return F_38 ( V_23 , V_77 , 0 ) ;
}
static int F_43 ( struct V_76 * V_23 ,
unsigned V_77 , int V_4 )
{
return F_38 ( V_23 , V_77 , 1 ) ;
}
static int F_23 ( struct V_76 * V_23 ,
unsigned V_77 )
{
unsigned int V_81 ;
T_1 V_79 = F_39 ( V_77 ) ;
struct V_1 * V_2 ;
V_2 = F_40 ( V_23 , struct V_1 , V_57 ) ;
V_81 = F_41 ( V_77 ) ;
if ( V_81 > V_82 ) {
F_14 ( V_2 -> V_41 , L_3 ,
V_81 , V_77 ) ;
return - V_83 ;
}
return F_3 ( V_2 , V_81 + V_85 ) & V_79 ;
}
static void F_44 ( struct V_76 * V_23 ,
unsigned V_77 , int V_4 )
{
T_1 V_79 , V_80 ;
unsigned int V_81 ;
unsigned long V_9 ;
struct V_1 * V_2 ;
V_2 = F_40 ( V_23 , struct V_1 , V_57 ) ;
V_81 = F_41 ( V_77 ) ;
if ( V_81 > V_82 ) {
F_14 ( V_2 -> V_41 , L_3 ,
V_81 , V_77 ) ;
return;
}
V_79 = F_39 ( V_77 ) ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
V_80 = F_3 ( V_2 , V_81 + V_86 ) ;
if ( V_4 )
V_80 |= V_79 ;
else
V_80 &= ~ V_79 ;
F_1 ( V_2 , V_81 + V_86 , V_80 ) ;
F_7 ( & V_2 -> V_11 , V_9 ) ;
return;
}
static int F_45 ( struct V_76 * V_23 , unsigned V_77 )
{
struct V_1 * V_2 = F_40 ( V_23 , struct V_1 , V_57 ) ;
return V_2 -> V_37 + V_77 ;
}
static T_3 int F_46 ( struct V_62 * V_63 ,
T_2 * V_87 , int V_88 )
{
struct V_1 * V_2 = F_27 ( V_63 ) ;
T_2 V_89 [ V_30 ] ;
T_2 V_80 [ V_30 ] ;
T_2 V_90 [ V_30 ] ;
int V_22 ;
memset ( V_89 , 0 , V_30 * sizeof( T_2 ) ) ;
memset ( V_80 , 0 , V_30 * sizeof( T_2 ) ) ;
memset ( V_90 , 0 , V_30 * sizeof( T_2 ) ) ;
F_1 ( V_2 , F_47 ( V_91 , V_92 ) , 0xffff ) ;
F_1 ( V_2 , F_47 ( V_93 , V_92 ) , 0xffff ) ;
F_1 ( V_2 , F_47 ( V_94 , V_92 ) , 0xffff ) ;
F_1 ( V_2 , F_47 ( V_95 , V_92 ) , 0xffff ) ;
for ( V_22 = 0 ; V_22 < V_88 ; V_22 ++ ) {
T_4 V_96 , V_97 , V_98 , V_99 , V_100 , V_101 ;
T_2 V_102 = V_87 [ V_22 ] ;
V_97 = F_48 ( V_102 ) ;
V_96 = F_49 ( V_102 ) ;
V_98 = F_50 ( V_102 ) ;
V_99 = F_51 ( V_102 ) ;
V_100 = F_52 ( V_97 ) ;
V_101 = F_53 ( V_97 ) ;
V_89 [ V_100 ] |= ( V_96 << V_101 ) ;
V_80 [ V_100 ] |= ( V_99 << V_101 ) ;
V_90 [ V_100 ] |= ( V_98 << V_101 ) ;
}
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ ) {
F_1 ( V_2 ,
F_54 ( V_22 ) +
V_84 ,
V_90 [ V_22 ] ) ;
F_1 ( V_2 ,
F_54 ( V_22 ) + V_86 ,
V_80 [ V_22 ] ) ;
F_1 ( V_2 ,
F_54 ( V_22 ) +
V_103 ,
V_89 [ V_22 ] ) ;
}
return F_55 ( & V_2 -> V_57 ) ;
}
static int F_56 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_27 ( V_63 ) ;
return F_57 ( & V_2 -> V_57 ) ;
}
static void F_58 ( struct V_1 * V_2 , struct V_104 * V_105 )
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
static void F_59 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
unsigned long V_9 ;
T_1 V_106 ;
F_60 ( V_105 -> V_107 == 0 ) ;
F_6 ( & V_2 -> V_11 , V_9 ) ;
if ( -- V_105 -> V_107 == 0 ) {
V_106 = F_3 ( V_2 , F_12 ( CLOCK , V_108 ) ) ;
V_106 &= ~ V_105 -> V_106 ;
F_1 ( V_2 , F_12 ( CLOCK , V_108 ) , V_106 ) ;
}
F_7 ( & V_2 -> V_11 , V_9 ) ;
}
static int F_61 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_62 ( V_63 -> V_41 . V_109 ) ;
F_58 ( V_2 , & V_2 -> V_110 [ V_111 ] ) ;
F_58 ( V_2 , & V_2 -> V_110 [ V_112 ] ) ;
F_58 ( V_2 , & V_2 -> V_110 [ V_113 ] ) ;
F_63 ( 1 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_115 ) ,
V_116 , 1 ) ;
F_63 ( 1 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_115 ) ,
V_116 , 0 ) ;
F_63 ( 1 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_117 ) ,
V_118 , 1 ) ;
F_63 ( 1 ) ;
return 0 ;
}
static int F_64 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_62 ( V_63 -> V_41 . V_109 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_117 ) ,
V_118 , 0 ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_113 ] ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_111 ] ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_112 ] ) ;
return 0 ;
}
static void F_65 ( struct V_62 * V_63 , int V_119 )
{
struct V_1 * V_2 = F_62 ( V_63 -> V_41 . V_109 ) ;
F_66 ( V_2 -> V_120 , 1 - V_2 -> V_6 , V_119 ) ;
}
static void F_67 ( struct V_62 * V_63 , int V_119 )
{
struct V_1 * V_2 = F_62 ( V_63 -> V_41 . V_109 ) ;
F_68 ( V_2 -> V_120 , 1 - V_2 -> V_6 , V_119 ) ;
}
static int F_69 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_62 ( V_63 -> V_41 . V_109 ) ;
F_5 ( V_2 , F_12 ( V_121 , V_122 ) ,
V_123 , 1 ) ;
F_5 ( V_2 , F_12 ( V_121 , V_122 ) ,
V_124 , 1 ) ;
F_5 ( V_2 , F_12 ( V_121 , V_122 ) ,
V_125 , 0 ) ;
F_5 ( V_2 , F_12 ( V_121 , V_122 ) ,
V_126 , 0 ) ;
F_58 ( V_2 , & V_2 -> V_110 [ V_111 ] ) ;
F_58 ( V_2 , & V_2 -> V_110 [ V_112 ] ) ;
F_63 ( 1 ) ;
F_1 ( V_2 , F_12 ( CLOCK , V_68 ) ,
V_67 | V_127 ) ;
F_58 ( V_2 , & V_2 -> V_110 [ V_128 ] ) ;
F_58 ( V_2 , & V_2 -> V_110 [ V_129 ] ) ;
F_63 ( 1 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_117 ) ,
V_130 , 1 ) ;
F_5 ( V_2 , F_12 ( V_121 , V_122 ) ,
V_131 , 1 ) ;
F_70 ( V_2 -> V_120 , 1 - V_2 -> V_6 ,
V_132 >> 1 ) ;
return 0 ;
}
static int F_71 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_62 ( V_63 -> V_41 . V_109 ) ;
F_5 ( V_2 , F_12 ( V_121 , V_122 ) ,
V_125 , 1 ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_128 ] ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_129 ] ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_111 ] ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_112 ] ) ;
return 0 ;
}
static int F_72 ( struct V_62 * V_63 )
{
const struct V_133 * V_134 = F_73 ( V_63 ) ;
struct V_1 * V_2 = F_62 ( V_63 -> V_41 . V_109 ) ;
F_58 ( V_2 , & V_2 -> V_110 [ V_135 [ V_134 -> V_136 ] ] ) ;
return 0 ;
}
static int F_74 ( struct V_62 * V_63 )
{
const struct V_133 * V_134 = F_73 ( V_63 ) ;
struct V_1 * V_2 = F_62 ( V_63 -> V_41 . V_109 ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_135 [ V_134 -> V_136 ] ] ) ;
return 0 ;
}
static int F_75 ( struct V_62 * V_63 )
{
const struct V_133 * V_134 = F_73 ( V_63 ) ;
struct V_1 * V_2 = F_62 ( V_63 -> V_41 . V_109 ) ;
while ( F_23 ( & V_2 -> V_57 , F_76 ( V_94 , V_134 -> V_136 ) ) != 0 )
F_63 ( 1 ) ;
F_59 ( V_2 , & V_2 -> V_110 [ V_135 [ V_134 -> V_136 ] ] ) ;
return 0 ;
}
static int T_3 F_77 ( struct V_62 * V_63 ,
struct V_137 * V_138 ,
struct V_139 * V_140 )
{
struct V_1 * V_2 = F_27 ( V_63 ) ;
struct V_139 * V_141 ;
int V_16 , V_65 ;
V_141 = F_78 ( V_63 , V_142 , 1 ) ;
if ( ! V_141 )
F_79 ( V_2 -> V_41 , L_4 ) ;
V_16 = F_28 ( V_63 , 1 ) ;
if ( V_16 < 0 )
F_79 ( V_2 -> V_41 , L_5 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_117 ) ,
V_143 , 0 ) ;
V_144 [ 0 ] . V_145 >>= V_2 -> V_6 ;
V_144 [ 0 ] . V_146 >>= V_2 -> V_6 ;
V_2 -> V_120 = F_80 ( ( V_147 >> V_2 -> V_6 ) +
V_141 -> V_145 ,
V_148 >> V_2 -> V_6 ) ;
if ( ! V_2 -> V_120 ) {
V_65 = - V_149 ;
F_79 ( V_2 -> V_41 , L_6 ) ;
goto V_78;
}
V_150 [ 0 ] . V_145 >>= V_2 -> V_6 ;
V_150 [ 0 ] . V_146 >>= V_2 -> V_6 ;
if ( V_138 -> V_151 ) {
V_152 . V_151 = V_138 -> V_151 ;
V_65 = F_81 ( & V_63 -> V_41 , V_63 -> V_136 ,
& V_153 , 1 , V_140 , V_2 -> V_37 , NULL ) ;
if ( V_65 < 0 )
goto V_78;
}
if ( V_141 && ( V_16 >= 0 ) ) {
V_65 = F_81 ( & V_63 -> V_41 , V_63 -> V_136 ,
& V_154 , 1 , V_141 , V_16 , NULL ) ;
if ( V_65 < 0 )
goto V_78;
}
V_65 = 0 ;
if ( V_138 -> V_155 ) {
int V_22 ;
for ( V_22 = 0 ; V_22 < V_156 ; ++ V_22 ) {
V_157 [ V_22 ] . V_158 = & V_138 -> V_155 [ V_22 ] ;
V_157 [ V_22 ] . V_159 = sizeof( V_138 -> V_155 [ V_22 ] ) ;
}
V_65 = F_81 ( & V_63 -> V_41 , 0 ,
V_157 , V_156 , NULL , 0 , NULL ) ;
}
V_78:
return V_65 ;
}
static void F_82 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_27 ( V_63 ) ;
F_83 ( & V_63 -> V_41 ) ;
F_84 ( V_2 -> V_120 ) ;
}
static int T_3 F_85 ( struct V_62 * V_63 )
{
struct V_137 * V_138 = F_86 ( & V_63 -> V_41 ) ;
struct V_1 * V_2 ;
struct V_139 * V_140 ;
unsigned long V_64 ;
int V_65 = 0 ;
V_2 = F_87 ( & V_63 -> V_41 ,
sizeof( struct V_1 ) , V_160 ) ;
if ( V_2 == NULL ) {
F_88 ( V_161 L_7 ) ;
return - V_149 ;
}
F_89 ( & V_2 -> V_11 ) ;
F_90 ( V_63 , V_2 ) ;
V_2 -> V_41 = & V_63 -> V_41 ;
V_140 = F_78 ( V_63 , V_142 , 0 ) ;
if ( ! V_140 ) {
F_14 ( V_2 -> V_41 , L_8 ) ;
return - V_149 ;
}
V_2 -> V_5 = F_80 ( V_140 -> V_145 , F_91 ( V_140 ) ) ;
if ( ! V_2 -> V_5 ) {
F_14 ( V_2 -> V_41 , L_9 ) ;
return - V_149 ;
}
V_2 -> V_37 = V_138 -> V_37 ;
V_2 -> V_6 = 2 - ( F_91 ( V_140 ) >> 12 ) ;
V_64 = 0 ;
F_1 ( V_2 , F_12 ( CLOCK , V_68 ) , V_64 ) ;
V_65 = F_26 ( V_63 ) ;
if ( V_65 < 0 ) {
F_14 ( V_2 -> V_41 , L_10 ) ;
goto V_162;
}
V_2 -> V_57 . V_163 = L_11 ;
V_2 -> V_57 . V_12 = V_138 -> V_81 ;
V_2 -> V_57 . V_164 = V_39 ;
V_2 -> V_57 . V_165 = F_23 ;
V_2 -> V_57 . V_8 = F_44 ;
V_2 -> V_57 . V_166 = F_42 ;
V_2 -> V_57 . V_167 = F_43 ;
V_2 -> V_57 . V_168 = F_45 ;
V_65 = F_46 ( V_63 ,
V_138 -> V_87 ,
V_138 -> V_169 ) ;
if ( V_65 < 0 ) {
F_14 ( V_2 -> V_41 , L_12 ) ;
goto V_170;
}
memcpy ( V_2 -> V_110 , V_171 , sizeof( V_171 ) ) ;
F_77 ( V_63 , V_138 , V_140 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_117 ) ,
( V_172 | V_173 ) , 1 ) ;
F_92 ( V_2 -> V_41 , L_13 ) ;
return 0 ;
V_170:
F_36 ( V_63 ) ;
V_162:
F_84 ( V_2 -> V_5 ) ;
return V_65 ;
}
static int F_93 ( struct V_62 * V_63 )
{
int V_65 ;
struct V_1 * V_2 = F_27 ( V_63 ) ;
F_5 ( V_2 , F_12 ( V_114 , V_117 ) ,
( V_172 | V_173 ) , 0 ) ;
F_82 ( V_63 ) ;
V_65 = F_56 ( V_63 ) ;
if ( V_65 < 0 )
return V_65 ;
F_36 ( V_63 ) ;
F_1 ( V_2 , F_12 ( CLOCK , V_68 ) , 0 ) ;
F_84 ( V_2 -> V_5 ) ;
return 0 ;
}
static void F_94 ( struct V_62 * V_63 )
{
}
static int T_3 F_95 ( void )
{
int V_174 = 0 ;
V_174 = F_96 ( & V_175 , F_85 ) ;
return V_174 ;
}
