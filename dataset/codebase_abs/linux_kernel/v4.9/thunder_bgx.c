static T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_3 )
{
void T_3 * V_4 = V_1 -> V_5 + ( ( V_6 ) V_2 << 20 ) + V_3 ;
return F_2 ( V_4 ) ;
}
static void F_3 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_3 , T_1 V_7 )
{
void T_3 * V_4 = V_1 -> V_5 + ( ( V_6 ) V_2 << 20 ) + V_3 ;
F_4 ( V_7 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_3 , T_1 V_7 )
{
void T_3 * V_4 = V_1 -> V_5 + ( ( V_6 ) V_2 << 20 ) + V_3 ;
F_4 ( V_7 | F_2 ( V_4 ) , V_4 ) ;
}
static int F_6 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_8 , T_1 V_9 , bool V_10 )
{
int V_11 = 100 ;
T_1 V_12 ;
while ( V_11 ) {
V_12 = F_1 ( V_1 , V_2 , V_8 ) ;
if ( V_10 && ! ( V_12 & V_9 ) )
return 0 ;
if ( ! V_10 && ( V_12 & V_9 ) )
return 0 ;
F_7 ( 1000 , 2000 ) ;
V_11 -- ;
}
return 1 ;
}
unsigned F_8 ( int V_13 )
{
int V_14 ;
unsigned V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
if ( V_17 [ ( V_13 * V_16 ) + V_14 ] )
V_15 |= ( 1 << V_14 ) ;
}
return V_15 ;
}
int F_9 ( int V_13 , int V_18 )
{
struct V_1 * V_1 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( V_1 )
return V_1 -> V_19 ;
return 0 ;
}
void F_10 ( int V_13 , int V_18 , int V_20 , void * V_21 )
{
struct V_22 * V_23 = (struct V_22 * ) V_21 ;
struct V_1 * V_1 ;
struct V_2 * V_2 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_20 ] ;
V_23 -> V_24 = V_2 -> V_24 ;
V_23 -> V_25 = V_2 -> V_26 ;
V_23 -> V_27 = V_2 -> V_28 ;
}
const T_2 * F_11 ( int V_13 , int V_18 , int V_20 )
{
struct V_1 * V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( V_1 )
return V_1 -> V_2 [ V_20 ] . V_29 ;
return NULL ;
}
void F_12 ( int V_13 , int V_18 , int V_20 , const T_2 * V_29 )
{
struct V_1 * V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return;
F_13 ( V_1 -> V_2 [ V_20 ] . V_29 , V_29 ) ;
}
void F_14 ( int V_13 , int V_18 , int V_20 , bool V_30 )
{
struct V_1 * V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
struct V_2 * V_2 ;
T_1 V_31 ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_20 ] ;
V_31 = F_1 ( V_1 , V_20 , V_32 ) ;
if ( V_30 )
V_31 |= V_33 | V_34 ;
else
V_31 &= ~ ( V_33 | V_34 ) ;
F_3 ( V_1 , V_20 , V_32 , V_31 ) ;
if ( V_1 -> V_35 )
F_15 ( V_30 ? V_2 -> V_24 : 0 , V_2 -> V_28 ) ;
}
static void F_16 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_1 ;
T_1 V_36 ;
T_1 V_37 = 0 ;
T_1 V_38 = 0 ;
V_36 = F_1 ( V_1 , V_2 -> V_20 , V_32 ) ;
V_36 &= ~ V_39 ;
F_3 ( V_1 , V_2 -> V_20 , V_32 , V_36 ) ;
V_37 = F_1 ( V_1 , V_2 -> V_20 , V_40 ) ;
V_38 = F_1 ( V_1 , V_2 -> V_20 , V_41 ) ;
if ( V_2 -> V_24 ) {
V_38 &= ~ V_42 ;
V_37 &= ~ V_43 ;
V_37 |= ( V_2 -> V_26 << 2 ) ;
} else {
V_38 |= V_42 ;
}
switch ( V_2 -> V_28 ) {
case 10 :
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
V_37 &= ~ V_46 ;
V_38 &= ~ V_47 ;
V_38 |= 50 ;
F_3 ( V_1 , V_2 -> V_20 , V_48 , 64 ) ;
F_3 ( V_1 , V_2 -> V_20 , V_49 , 0 ) ;
break;
case 100 :
V_37 &= ~ V_44 ;
V_37 &= ~ V_45 ;
V_37 &= ~ V_46 ;
V_38 &= ~ V_47 ;
V_38 |= 5 ;
F_3 ( V_1 , V_2 -> V_20 , V_48 , 64 ) ;
F_3 ( V_1 , V_2 -> V_20 , V_49 , 0 ) ;
break;
case 1000 :
V_37 |= V_44 ;
V_37 &= ~ V_45 ;
V_37 |= V_46 ;
V_38 &= ~ V_47 ;
V_38 |= 1 ;
F_3 ( V_1 , V_2 -> V_20 , V_48 , 512 ) ;
if ( V_2 -> V_26 )
F_3 ( V_1 , V_2 -> V_20 ,
V_49 , 0 ) ;
else
F_3 ( V_1 , V_2 -> V_20 ,
V_49 , 8192 ) ;
break;
default:
break;
}
F_3 ( V_1 , V_2 -> V_20 , V_41 , V_38 ) ;
F_3 ( V_1 , V_2 -> V_20 , V_40 , V_37 ) ;
V_37 = F_1 ( V_1 , V_2 -> V_20 , V_40 ) ;
V_36 |= V_39 ;
F_3 ( V_1 , V_2 -> V_20 , V_32 , V_36 ) ;
if ( V_1 -> V_35 && ( V_36 & ( V_33 | V_34 ) ) )
F_15 ( V_2 -> V_24 , V_2 -> V_28 ) ;
}
static void F_17 ( struct V_50 * V_51 )
{
struct V_2 * V_2 = F_18 ( V_51 , struct V_2 , V_51 ) ;
struct V_52 * V_53 ;
int V_54 = 0 ;
if ( ! V_2 )
return;
V_53 = V_2 -> V_53 ;
if ( ! V_53 -> V_23 && V_2 -> V_55 )
V_54 = - 1 ;
if ( V_53 -> V_23 &&
( V_2 -> V_26 != V_53 -> V_25 ||
V_2 -> V_55 != V_53 -> V_23 ||
V_2 -> V_28 != V_53 -> V_27 ) ) {
V_54 = 1 ;
}
V_2 -> V_55 = V_53 -> V_23 ;
V_2 -> V_28 = V_53 -> V_27 ;
V_2 -> V_26 = V_53 -> V_25 ;
if ( ! V_54 )
return;
if ( V_54 > 0 )
V_2 -> V_24 = true ;
else
V_2 -> V_24 = false ;
if ( V_2 -> V_56 )
F_16 ( V_2 ) ;
else
F_19 ( V_2 ) ;
}
T_1 F_20 ( int V_13 , int V_18 , int V_2 , int V_57 )
{
struct V_1 * V_1 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return 0 ;
if ( V_57 > 8 )
V_2 = 0 ;
return F_1 ( V_1 , V_2 , V_58 + ( V_57 * 8 ) ) ;
}
T_1 F_21 ( int V_13 , int V_18 , int V_2 , int V_57 )
{
struct V_1 * V_1 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return 0 ;
return F_1 ( V_1 , V_2 , V_59 + ( V_57 * 8 ) ) ;
}
static void F_22 ( struct V_1 * V_1 , int V_2 )
{
T_1 V_3 ;
while ( V_1 -> V_2 [ V_2 ] . V_60 > 0 ) {
V_3 = ( ( V_1 -> V_2 [ V_2 ] . V_60 - 1 ) * sizeof( T_1 ) ) +
( V_2 * V_61 * sizeof( T_1 ) ) ;
F_3 ( V_1 , 0 , V_62 + V_3 , 0 ) ;
V_1 -> V_2 [ V_2 ] . V_60 -- ;
}
}
void F_23 ( int V_13 , int V_18 ,
int V_63 , bool V_30 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
T_1 V_31 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_63 ] ;
if ( V_2 -> V_56 ) {
V_31 = F_1 ( V_1 , V_63 , V_64 ) ;
if ( V_30 )
V_31 |= V_65 ;
else
V_31 &= ~ V_65 ;
F_3 ( V_1 , V_63 , V_64 , V_31 ) ;
} else {
V_31 = F_1 ( V_1 , V_63 , V_66 ) ;
if ( V_30 )
V_31 |= V_67 ;
else
V_31 &= ~ V_67 ;
F_3 ( V_1 , V_63 , V_66 , V_31 ) ;
}
}
static int F_24 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
int V_20 = V_2 -> V_20 ;
T_1 V_31 ;
F_5 ( V_1 , V_20 , V_68 , 0x30 ) ;
F_5 ( V_1 , V_20 , V_69 , V_70 ) ;
V_31 = F_1 ( V_1 , V_20 , V_71 ) ;
if ( V_31 & 1 )
F_3 ( V_1 , V_20 , V_72 , 0 ) ;
F_5 ( V_1 , V_20 , V_32 , V_39 ) ;
F_5 ( V_1 , V_20 , V_64 , V_73 ) ;
if ( F_6 ( V_1 , V_20 , V_64 ,
V_73 , true ) ) {
F_25 ( & V_1 -> V_74 -> V_75 , L_1 ) ;
return - 1 ;
}
V_31 = F_1 ( V_1 , V_20 , V_64 ) ;
V_31 &= ~ V_76 ;
V_31 |= ( V_77 | V_78 ) ;
F_3 ( V_1 , V_20 , V_64 , V_31 ) ;
if ( V_2 -> V_79 == V_80 ) {
V_31 = F_1 ( V_1 , V_20 , V_41 ) ;
V_31 &= ~ V_81 ;
F_3 ( V_1 , V_20 , V_41 , V_31 ) ;
return 0 ;
}
if ( V_2 -> V_79 == V_82 ) {
if ( F_6 ( V_1 , V_20 , V_83 ,
V_84 , false ) ) {
F_25 ( & V_1 -> V_74 -> V_75 , L_2 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_26 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
T_1 V_31 ;
int V_20 = V_2 -> V_20 ;
F_5 ( V_1 , V_20 , V_66 , V_85 ) ;
if ( F_6 ( V_1 , V_20 , V_66 , V_85 , true ) ) {
F_25 ( & V_1 -> V_74 -> V_75 , L_3 ) ;
return - 1 ;
}
V_31 = F_1 ( V_1 , V_20 , V_32 ) ;
V_31 &= ~ V_39 ;
F_3 ( V_1 , V_20 , V_32 , V_31 ) ;
F_5 ( V_1 , V_20 , V_66 , V_86 ) ;
if ( V_2 -> V_79 == V_87 )
F_5 ( V_1 , V_20 , V_88 ,
V_89 ) ;
V_31 = F_1 ( V_1 , V_20 , V_88 ) ;
V_31 &= ~ V_90 ;
F_3 ( V_1 , V_20 , V_88 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_91 ) ;
F_3 ( V_1 , V_20 , V_91 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_92 ) ;
F_3 ( V_1 , V_20 , V_92 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_93 ) ;
F_3 ( V_1 , V_20 , V_93 , V_31 ) ;
if ( V_2 -> V_94 ) {
F_3 ( V_1 , V_20 , V_95 , 0x00 ) ;
F_3 ( V_1 , V_20 , V_96 , 0x00 ) ;
F_3 ( V_1 , V_20 , V_97 , 0x00 ) ;
F_5 ( V_1 , V_20 ,
V_98 , V_99 ) ;
}
F_5 ( V_1 , V_20 , V_100 , V_101 ) ;
V_31 = F_1 ( V_1 , V_20 , V_102 ) ;
V_31 &= ~ V_103 ;
F_3 ( V_1 , V_20 , V_102 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_104 ) ;
V_31 = V_31 & ~ ( V_105 | V_106 ) ;
F_3 ( V_1 , V_20 , V_104 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_107 ) ;
if ( V_2 -> V_79 == V_108 )
V_31 |= ( 1 << 23 ) ;
else if ( V_2 -> V_79 == V_109 )
V_31 |= ( 1 << 24 ) ;
else
V_31 &= ~ ( ( 1 << 23 ) | ( 1 << 24 ) ) ;
V_31 = V_31 & ( ~ ( ( 1ULL << 25 ) | ( 1ULL << 22 ) | ( 1ULL << 12 ) ) ) ;
F_3 ( V_1 , V_20 , V_107 , V_31 ) ;
V_31 = F_1 ( V_1 , 0 , V_110 ) ;
V_31 &= ~ V_111 ;
F_3 ( V_1 , 0 , V_110 , V_31 ) ;
F_5 ( V_1 , V_20 , V_32 , V_39 ) ;
V_31 = F_1 ( V_1 , V_20 , V_66 ) ;
V_31 &= ~ V_86 ;
F_3 ( V_1 , V_20 , V_66 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_112 ) ;
V_31 &= ~ V_113 ;
V_31 |= V_114 ;
F_3 ( V_1 , V_20 , V_112 , V_31 ) ;
F_5 ( V_1 , V_20 , V_115 , ( 0x100 - 1 ) ) ;
F_5 ( V_1 , V_20 , V_116 , V_70 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_1 ;
int V_20 = V_2 -> V_20 ;
int V_79 = V_2 -> V_79 ;
T_1 V_31 ;
if ( V_2 -> V_94 ) {
V_31 = F_1 ( V_1 , V_20 , V_93 ) ;
if ( ! ( V_31 & ( 1ull << 13 ) ) ) {
V_31 = ( 1ull << 13 ) | ( 1ull << 14 ) ;
F_3 ( V_1 , V_20 , V_93 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_98 ) ;
V_31 |= ( 1ull << 0 ) ;
F_3 ( V_1 , V_20 , V_98 , V_31 ) ;
return - 1 ;
}
}
if ( F_6 ( V_1 , V_20 , V_66 , V_85 , true ) ) {
F_25 ( & V_1 -> V_74 -> V_75 , L_3 ) ;
return - 1 ;
}
if ( ( V_79 == V_108 ) || ( V_79 == V_117 ) ||
( V_79 == V_109 ) || ( V_79 == V_118 ) ) {
if ( F_6 ( V_1 , V_20 , V_119 ,
V_120 , false ) ) {
F_25 ( & V_1 -> V_74 -> V_75 ,
L_4 ) ;
return - 1 ;
}
} else {
if ( F_6 ( V_1 , V_20 , V_121 ,
V_122 , false ) ) {
F_25 ( & V_1 -> V_74 -> V_75 ,
L_5 ) ;
return - 1 ;
}
}
if ( F_1 ( V_1 , V_20 , V_123 ) & V_124 )
F_5 ( V_1 , V_20 ,
V_123 , V_124 ) ;
if ( F_1 ( V_1 , V_20 , V_123 ) & V_124 ) {
F_25 ( & V_1 -> V_74 -> V_75 , L_6 ) ;
if ( V_2 -> V_94 ) {
V_31 = F_1 ( V_1 , V_20 , V_93 ) ;
if ( ! ( V_31 & ( 1ull << 13 ) ) ) {
V_31 = ( 1ull << 13 ) | ( 1ull << 14 ) ;
F_3 ( V_1 , V_20 , V_93 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 ,
V_98 ) ;
V_31 |= ( 1ull << 0 ) ;
F_3 ( V_1 , V_20 ,
V_98 , V_31 ) ;
return - 1 ;
}
}
return - 1 ;
}
if ( F_6 ( V_1 , V_20 , V_125 , V_126 , false ) ) {
F_25 ( & V_1 -> V_74 -> V_75 , L_7 ) ;
return - 1 ;
}
if ( F_6 ( V_1 , V_20 , V_125 , V_127 , false ) ) {
F_25 ( & V_1 -> V_74 -> V_75 , L_8 ) ;
return - 1 ;
}
V_31 = F_1 ( V_1 , V_20 , V_128 ) ;
V_31 &= V_129 ;
if ( ! V_31 )
return 0 ;
F_26 ( V_1 , V_2 ) ;
return - 1 ;
}
static void F_27 ( struct V_130 * V_131 )
{
struct V_2 * V_2 ;
T_1 V_132 , V_133 ;
V_2 = F_18 ( V_131 , struct V_2 , V_134 . V_131 ) ;
F_5 ( V_2 -> V_1 , V_2 -> V_20 ,
V_135 , V_136 ) ;
F_6 ( V_2 -> V_1 , V_2 -> V_20 , V_135 ,
V_136 , false ) ;
V_132 = F_1 ( V_2 -> V_1 , V_2 -> V_20 , V_135 ) ;
V_133 = F_1 ( V_2 -> V_1 , V_2 -> V_20 , V_128 ) ;
if ( ( V_132 & V_136 ) &&
! ( V_133 & V_129 ) ) {
V_2 -> V_24 = 1 ;
if ( V_2 -> V_79 == V_118 )
V_2 -> V_28 = 40000 ;
else
V_2 -> V_28 = 10000 ;
V_2 -> V_26 = 1 ;
} else {
V_2 -> V_24 = 0 ;
V_2 -> V_28 = V_137 ;
V_2 -> V_26 = V_138 ;
}
if ( V_2 -> V_55 != V_2 -> V_24 ) {
if ( V_2 -> V_24 ) {
if ( F_19 ( V_2 ) ) {
V_2 -> V_24 = 0 ;
V_2 -> V_28 = V_137 ;
V_2 -> V_26 = V_138 ;
}
}
V_2 -> V_55 = V_2 -> V_24 ;
}
F_28 ( V_2 -> V_139 , & V_2 -> V_134 , V_140 * 2 ) ;
}
static int F_29 ( T_2 V_79 )
{
if ( V_79 == V_80 )
return V_141 ;
if ( V_79 == V_142 )
return V_143 ;
return V_144 ;
}
static int F_30 ( struct V_1 * V_1 , T_2 V_20 )
{
struct V_2 * V_2 ;
T_1 V_31 ;
V_2 = & V_1 -> V_2 [ V_20 ] ;
V_2 -> V_1 = V_1 ;
if ( ( V_2 -> V_79 == V_82 ) ||
( V_2 -> V_79 == V_80 ) ||
( V_2 -> V_79 == V_142 ) ) {
V_2 -> V_56 = 1 ;
if ( F_24 ( V_1 , V_2 ) )
return - 1 ;
} else {
V_2 -> V_56 = 0 ;
if ( F_26 ( V_1 , V_2 ) )
return - 1 ;
}
if ( V_2 -> V_56 ) {
V_31 = F_1 ( V_1 , V_20 , V_71 ) ;
V_31 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_20 , V_71 , V_31 ) ;
F_3 ( V_1 , V_20 , V_145 , 60 - 1 ) ;
} else {
V_31 = F_1 ( V_1 , V_20 , V_100 ) ;
V_31 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_20 , V_100 , V_31 ) ;
F_3 ( V_1 , V_20 , V_146 , 60 + 4 ) ;
}
F_5 ( V_1 , V_20 , V_32 , V_39 ) ;
F_3 ( V_1 , V_20 , V_147 , 0x03 ) ;
if ( ( V_2 -> V_79 != V_117 ) &&
( V_2 -> V_79 != V_118 ) &&
( V_2 -> V_79 != V_109 ) &&
( V_2 -> V_79 != V_108 ) ) {
if ( ! V_2 -> V_53 )
return - V_148 ;
V_2 -> V_53 -> V_149 = 0 ;
if ( F_31 ( & V_2 -> V_51 , V_2 -> V_53 ,
F_17 ,
F_29 ( V_2 -> V_79 ) ) )
return - V_148 ;
F_32 ( V_2 -> V_53 ) ;
} else {
V_2 -> V_139 = F_33 ( L_9 , V_150 |
V_151 , 1 ) ;
if ( ! V_2 -> V_139 )
return - V_152 ;
F_34 ( & V_2 -> V_134 , F_27 ) ;
F_28 ( V_2 -> V_139 , & V_2 -> V_134 , 0 ) ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_1 , T_2 V_20 )
{
struct V_2 * V_2 ;
T_1 V_31 ;
V_2 = & V_1 -> V_2 [ V_20 ] ;
if ( V_2 -> V_139 ) {
F_36 ( & V_2 -> V_134 ) ;
F_37 ( V_2 -> V_139 ) ;
}
V_31 = F_1 ( V_1 , V_20 , V_32 ) ;
V_31 &= ~ V_33 ;
F_3 ( V_1 , V_20 , V_32 , V_31 ) ;
F_6 ( V_1 , V_20 , V_153 , ( T_1 ) 0x1FFF , true ) ;
F_6 ( V_1 , V_20 , V_154 , ( T_1 ) 0x3FFF , true ) ;
V_31 = F_1 ( V_1 , V_20 , V_32 ) ;
V_31 &= ~ V_34 ;
F_3 ( V_1 , V_20 , V_32 , V_31 ) ;
if ( ! V_2 -> V_56 )
F_5 ( V_1 , V_20 ,
V_66 , V_86 ) ;
else
F_5 ( V_1 , V_20 ,
V_64 , V_76 ) ;
V_31 = F_1 ( V_1 , V_20 , V_32 ) ;
V_31 &= ~ V_39 ;
F_3 ( V_1 , V_20 , V_32 , V_31 ) ;
F_22 ( V_1 , V_20 ) ;
if ( ( V_2 -> V_79 != V_117 ) &&
( V_2 -> V_79 != V_118 ) &&
( V_2 -> V_79 != V_109 ) &&
( V_2 -> V_79 != V_108 ) && V_2 -> V_53 )
F_38 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
}
static void F_39 ( struct V_1 * V_1 )
{
int V_14 ;
struct V_2 * V_2 ;
F_5 ( V_1 , 0 , V_155 , V_156 ) ;
if ( F_1 ( V_1 , 0 , V_157 ) )
F_25 ( & V_1 -> V_74 -> V_75 , L_10 , V_1 -> V_158 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_19 ; V_14 ++ ) {
V_2 = & V_1 -> V_2 [ V_14 ] ;
F_3 ( V_1 , V_14 , V_32 ,
( V_2 -> V_79 << 8 ) | V_2 -> V_159 ) ;
V_1 -> V_2 [ V_14 ] . V_160 = V_19 ;
V_19 ++ ;
}
F_3 ( V_1 , 0 , V_161 , V_1 -> V_19 ) ;
F_3 ( V_1 , 0 , V_162 , V_1 -> V_19 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_19 ; V_14 ++ )
F_5 ( V_1 , 0 , V_163 ,
( ( 1ULL << V_164 ) - 1 ) <<
( V_14 * V_164 ) ) ;
for ( V_14 = 0 ; V_14 < V_165 ; V_14 ++ )
F_3 ( V_1 , 0 , V_62 + ( V_14 * 8 ) , 0x00 ) ;
for ( V_14 = 0 ; V_14 < V_166 ; V_14 ++ )
F_3 ( V_1 , 0 , V_167 + ( V_14 * 8 ) , 0x00 ) ;
}
static T_2 F_40 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return ( T_2 ) ( F_1 ( V_1 , V_2 -> V_20 , V_32 ) & 0xFF ) ;
}
static void F_41 ( struct V_1 * V_1 , T_2 V_20 )
{
struct V_168 * V_75 = & V_1 -> V_74 -> V_75 ;
struct V_2 * V_2 ;
char V_169 [ 20 ] ;
T_2 V_170 ;
if ( V_20 > V_1 -> V_171 )
return;
V_2 = & V_1 -> V_2 [ V_20 ] ;
V_170 = ( V_20 / 2 ) + ( V_1 -> V_158 * 2 ) ;
if ( ! V_1 -> V_172 )
sprintf ( V_169 , L_11 , V_1 -> V_158 ) ;
else
sprintf ( V_169 , L_12 , V_1 -> V_158 , V_170 ) ;
switch ( V_2 -> V_79 ) {
case V_82 :
F_42 ( V_75 , L_13 , ( char * ) V_169 ) ;
break;
case V_173 :
F_42 ( V_75 , L_14 , ( char * ) V_169 ) ;
break;
case V_87 :
F_42 ( V_75 , L_15 , ( char * ) V_169 ) ;
break;
case V_117 :
if ( ! V_2 -> V_94 )
F_42 ( V_75 , L_16 , ( char * ) V_169 ) ;
else
F_42 ( V_75 , L_17 , ( char * ) V_169 ) ;
break;
case V_118 :
if ( ! V_2 -> V_94 )
F_42 ( V_75 , L_18 , ( char * ) V_169 ) ;
else
F_42 ( V_75 , L_19 , ( char * ) V_169 ) ;
break;
case V_80 :
if ( ( V_20 == 0 ) &&
( F_40 ( V_1 , V_2 ) != V_20 ) )
return;
if ( ( V_20 == 2 ) &&
( F_40 ( V_1 , V_2 ) == V_20 ) )
return;
F_42 ( V_75 , L_20 , ( char * ) V_169 ) ;
break;
case V_142 :
F_42 ( V_75 , L_21 , ( char * ) V_169 ) ;
break;
case V_174 :
break;
}
}
static void F_43 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
switch ( V_2 -> V_79 ) {
case V_82 :
case V_117 :
V_2 -> V_159 = V_2 -> V_20 ;
break;
case V_173 :
case V_118 :
case V_142 :
V_2 -> V_159 = 0xE4 ;
break;
case V_87 :
V_2 -> V_159 = ( V_2 -> V_20 ) ? 0xE : 0x4 ;
break;
case V_80 :
V_2 -> V_159 = F_40 ( V_1 , V_2 ) ;
break;
default:
V_2 -> V_159 = 0 ;
break;
}
}
static void F_44 ( struct V_1 * V_1 , struct V_2 * V_2 , int V_20 )
{
if ( ( V_2 -> V_79 != V_108 ) &&
( V_2 -> V_79 != V_109 ) ) {
V_2 -> V_94 = 0 ;
return;
}
V_2 -> V_94 = F_1 ( V_1 , V_20 , V_98 ) &
V_99 ;
}
static void F_45 ( struct V_1 * V_1 , T_2 V_57 )
{
struct V_2 * V_2 ;
struct V_2 * V_175 ;
T_1 V_36 ;
T_2 V_79 ;
T_2 V_159 ;
V_2 = & V_1 -> V_2 [ V_57 ] ;
if ( ! V_1 -> V_172 || V_1 -> V_35 ) {
V_36 = F_1 ( V_1 , 0 , V_32 ) ;
V_2 -> V_79 = ( V_36 >> 8 ) & 0x07 ;
if ( V_1 -> V_35 )
V_2 -> V_79 = V_142 ;
F_44 ( V_1 , V_2 , 0 ) ;
F_43 ( V_1 , V_2 ) ;
return;
}
if ( ( V_57 == 0 ) || ( V_57 == 2 ) ) {
V_36 = F_1 ( V_1 , V_57 , V_32 ) ;
V_79 = ( T_2 ) ( ( V_36 >> 8 ) & 0x07 ) ;
V_159 = ( T_2 ) ( V_36 & 0xFF ) ;
if ( ( V_79 == 0 ) && ( V_159 == 0xE4 ) )
V_2 -> V_79 = V_174 ;
else
V_2 -> V_79 = V_79 ;
F_44 ( V_1 , V_2 , V_2 -> V_20 ) ;
F_43 ( V_1 , V_2 ) ;
V_175 = & V_1 -> V_2 [ V_57 + 1 ] ;
V_175 -> V_79 = V_2 -> V_79 ;
F_44 ( V_1 , V_175 , V_175 -> V_20 ) ;
F_43 ( V_1 , V_175 ) ;
}
}
static bool F_46 ( struct V_1 * V_1 )
{
struct V_2 * V_2 ;
if ( ! V_1 -> V_172 )
return true ;
V_2 = & V_1 -> V_2 [ 0 ] ;
if ( V_2 -> V_79 == V_174 )
return false ;
return true ;
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_2 * V_2 ;
struct V_2 * V_176 ;
struct V_2 * V_177 ;
T_2 V_57 ;
for ( V_57 = 0 ; V_57 < V_1 -> V_171 ; V_57 ++ ) {
V_2 = & V_1 -> V_2 [ V_57 ] ;
V_2 -> V_20 = V_57 ;
V_2 -> V_79 = V_174 ;
V_2 -> V_94 = false ;
}
V_1 -> V_19 = F_1 ( V_1 , 0 , V_162 ) & 0x7 ;
if ( V_1 -> V_19 > V_1 -> V_171 )
V_1 -> V_19 = V_1 -> V_171 ;
for ( V_57 = 0 ; V_57 < V_1 -> V_171 ; V_57 ++ )
F_45 ( V_1 , V_57 ) ;
if ( ! V_1 -> V_172 || V_1 -> V_35 ) {
F_41 ( V_1 , 0 ) ;
return;
}
if ( V_1 -> V_19 ) {
F_41 ( V_1 , 0 ) ;
F_41 ( V_1 , 2 ) ;
}
if ( F_46 ( V_1 ) || ( V_1 -> V_19 > 2 ) )
return;
for ( V_57 = 0 ; V_57 < V_1 -> V_19 ; V_57 ++ ) {
V_176 = & V_1 -> V_2 [ V_57 ] ;
V_177 = & V_1 -> V_2 [ V_57 + 2 ] ;
V_176 -> V_79 = V_177 -> V_79 ;
V_176 -> V_159 = V_177 -> V_159 ;
}
}
static int F_48 ( struct V_168 * V_75 , struct V_178 * V_179 ,
T_2 * V_180 )
{
T_2 V_29 [ V_181 ] ;
int V_182 ;
V_182 = F_49 ( F_50 ( V_179 ) ,
L_22 , V_29 , V_181 ) ;
if ( V_182 )
goto V_183;
if ( ! F_51 ( V_29 ) ) {
F_25 ( V_75 , L_23 , V_29 ) ;
V_182 = - V_184 ;
goto V_183;
}
F_42 ( V_75 , L_24 , V_29 ) ;
memcpy ( V_180 , V_29 , V_181 ) ;
V_183:
return V_182 ;
}
static T_4 F_52 ( T_5 V_185 ,
V_6 V_186 , void * V_187 , void * * V_188 )
{
struct V_1 * V_1 = V_187 ;
struct V_168 * V_75 = & V_1 -> V_74 -> V_75 ;
struct V_178 * V_179 ;
if ( F_53 ( V_185 , & V_179 ) )
goto V_183;
F_48 ( V_75 , V_179 , V_1 -> V_2 [ V_1 -> V_19 ] . V_29 ) ;
F_54 ( & V_1 -> V_2 [ V_1 -> V_19 ] . V_51 , V_75 ) ;
V_1 -> V_2 [ V_1 -> V_19 ] . V_20 = V_1 -> V_19 ;
V_183:
V_1 -> V_19 ++ ;
return V_189 ;
}
static T_4 F_55 ( T_5 V_185 , V_6 V_186 ,
void * V_187 , void * * V_190 )
{
struct V_191 string = { V_192 , NULL } ;
struct V_1 * V_1 = V_187 ;
char V_193 [ 5 ] ;
snprintf ( V_193 , 5 , L_25 , V_1 -> V_158 ) ;
if ( F_56 ( F_57 ( V_185 , V_194 , & string ) ) ) {
F_58 ( L_26 ) ;
return V_189 ;
}
if ( strncmp ( string . V_195 , V_193 , 4 ) )
return V_189 ;
F_59 ( V_196 , V_185 , 1 ,
F_52 , NULL , V_1 , NULL ) ;
F_60 ( string . V_195 ) ;
return V_197 ;
}
static int F_61 ( struct V_1 * V_1 )
{
F_62 ( NULL , F_55 , V_1 , ( void * * ) NULL ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_1 )
{
return - V_148 ;
}
static int F_63 ( struct V_1 * V_1 )
{
struct V_198 * V_199 ;
struct V_200 * V_13 = NULL ;
T_2 V_2 = 0 ;
F_64 (&bgx->pdev->dev, fwn) {
struct V_52 * V_201 ;
struct V_200 * V_202 ;
const char * V_29 ;
V_13 = F_65 ( V_199 ) ;
if ( ! V_13 )
break;
V_29 = F_66 ( V_13 ) ;
if ( V_29 )
F_13 ( V_1 -> V_2 [ V_2 ] . V_29 , V_29 ) ;
F_54 ( & V_1 -> V_2 [ V_2 ] . V_51 , & V_1 -> V_74 -> V_75 ) ;
V_1 -> V_2 [ V_2 ] . V_20 = V_2 ;
V_202 = F_67 ( V_13 , L_27 , 0 ) ;
if ( V_202 &&
! F_68 ( V_202 , L_28 ) ) {
V_201 = F_69 ( V_202 ) ;
if ( ! V_201 )
goto V_203;
V_1 -> V_2 [ V_2 ] . V_53 = V_201 ;
}
V_2 ++ ;
if ( V_2 == V_1 -> V_171 ) {
F_70 ( V_13 ) ;
break;
}
}
return 0 ;
V_203:
while ( V_2 ) {
if ( V_1 -> V_2 [ V_2 ] . V_53 ) {
F_71 ( & V_1 -> V_2 [ V_2 ] . V_53 -> V_204 . V_75 ) ;
V_1 -> V_2 [ V_2 ] . V_53 = NULL ;
}
V_2 -- ;
}
F_70 ( V_13 ) ;
return - V_205 ;
}
static int F_63 ( struct V_1 * V_1 )
{
return - V_148 ;
}
static int F_72 ( struct V_1 * V_1 )
{
if ( ! V_206 )
return F_61 ( V_1 ) ;
return F_63 ( V_1 ) ;
}
static int F_73 ( struct V_207 * V_74 , const struct V_208 * V_209 )
{
int V_210 ;
struct V_168 * V_75 = & V_74 -> V_75 ;
struct V_1 * V_1 = NULL ;
T_2 V_2 ;
T_6 V_211 ;
V_1 = F_74 ( V_75 , sizeof( * V_1 ) , V_212 ) ;
if ( ! V_1 )
return - V_152 ;
V_1 -> V_74 = V_74 ;
F_75 ( V_74 , V_1 ) ;
V_210 = F_76 ( V_74 ) ;
if ( V_210 ) {
F_25 ( V_75 , L_29 ) ;
F_75 ( V_74 , NULL ) ;
return V_210 ;
}
V_210 = F_77 ( V_74 , V_213 ) ;
if ( V_210 ) {
F_25 ( V_75 , L_30 , V_210 ) ;
goto V_214;
}
V_1 -> V_5 = F_78 ( V_74 , V_215 , 0 ) ;
if ( ! V_1 -> V_5 ) {
F_25 ( V_75 , L_31 ) ;
V_210 = - V_152 ;
goto V_216;
}
F_79 ( V_74 , V_217 , & V_211 ) ;
if ( V_211 != V_218 ) {
V_1 -> V_158 = ( F_80 ( V_74 ,
V_215 ) >> 24 ) & V_219 ;
V_1 -> V_158 += F_81 ( V_74 ) * V_16 ;
V_1 -> V_171 = V_220 ;
V_17 [ V_1 -> V_158 ] = V_1 ;
} else {
V_1 -> V_35 = true ;
V_1 -> V_171 = 1 ;
V_1 -> V_158 = V_221 - 1 ;
V_17 [ V_1 -> V_158 ] = V_1 ;
F_82 () ;
}
F_79 ( V_74 , V_222 , & V_211 ) ;
if ( ( V_211 == V_223 ) ||
( ( V_211 == V_224 ) && ( V_1 -> V_158 == 2 ) ) )
V_1 -> V_172 = true ;
F_47 ( V_1 ) ;
V_210 = F_72 ( V_1 ) ;
if ( V_210 )
goto V_225;
F_39 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_1 -> V_19 ; V_2 ++ ) {
V_210 = F_30 ( V_1 , V_2 ) ;
if ( V_210 ) {
F_25 ( V_75 , L_32 ,
V_1 -> V_158 , V_2 ) ;
while ( V_2 )
F_35 ( V_1 , -- V_2 ) ;
goto V_225;
}
}
return 0 ;
V_225:
V_17 [ V_1 -> V_158 ] = NULL ;
V_216:
F_83 ( V_74 ) ;
V_214:
F_84 ( V_74 ) ;
F_75 ( V_74 , NULL ) ;
return V_210 ;
}
static void F_85 ( struct V_207 * V_74 )
{
struct V_1 * V_1 = F_86 ( V_74 ) ;
T_2 V_2 ;
for ( V_2 = 0 ; V_2 < V_1 -> V_19 ; V_2 ++ )
F_35 ( V_1 , V_2 ) ;
V_17 [ V_1 -> V_158 ] = NULL ;
F_83 ( V_74 ) ;
F_84 ( V_74 ) ;
F_75 ( V_74 , NULL ) ;
}
static int T_7 F_87 ( void )
{
F_88 ( L_33 , V_213 , V_226 ) ;
return F_89 ( & V_227 ) ;
}
static void T_8 F_90 ( void )
{
F_91 ( & V_227 ) ;
}
