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
T_1 V_31 ;
if ( ! V_1 )
return;
V_31 = F_1 ( V_1 , V_20 , V_32 ) ;
if ( V_30 )
V_31 |= V_33 | V_34 ;
else
V_31 &= ~ ( V_33 | V_34 ) ;
F_3 ( V_1 , V_20 , V_32 , V_31 ) ;
}
static void F_15 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_1 ;
T_1 V_35 ;
T_1 V_36 = 0 ;
T_1 V_37 = 0 ;
V_35 = F_1 ( V_1 , V_2 -> V_20 , V_32 ) ;
V_35 &= ~ V_38 ;
F_3 ( V_1 , V_2 -> V_20 , V_32 , V_35 ) ;
V_36 = F_1 ( V_1 , V_2 -> V_20 , V_39 ) ;
V_37 = F_1 ( V_1 , V_2 -> V_20 , V_40 ) ;
if ( V_2 -> V_24 ) {
V_37 &= ~ V_41 ;
V_36 &= ~ V_42 ;
V_36 |= ( V_2 -> V_26 << 2 ) ;
} else {
V_37 |= V_41 ;
}
switch ( V_2 -> V_28 ) {
case 10 :
V_36 &= ~ V_43 ;
V_36 |= V_44 ;
V_36 &= ~ V_45 ;
V_37 &= ~ V_46 ;
V_37 |= 50 ;
F_3 ( V_1 , V_2 -> V_20 , V_47 , 64 ) ;
F_3 ( V_1 , V_2 -> V_20 , V_48 , 0 ) ;
break;
case 100 :
V_36 &= ~ V_43 ;
V_36 &= ~ V_44 ;
V_36 &= ~ V_45 ;
V_37 &= ~ V_46 ;
V_37 |= 5 ;
F_3 ( V_1 , V_2 -> V_20 , V_47 , 64 ) ;
F_3 ( V_1 , V_2 -> V_20 , V_48 , 0 ) ;
break;
case 1000 :
V_36 |= V_43 ;
V_36 &= ~ V_44 ;
V_36 |= V_45 ;
V_37 &= ~ V_46 ;
V_37 |= 1 ;
F_3 ( V_1 , V_2 -> V_20 , V_47 , 512 ) ;
if ( V_2 -> V_26 )
F_3 ( V_1 , V_2 -> V_20 ,
V_48 , 0 ) ;
else
F_3 ( V_1 , V_2 -> V_20 ,
V_48 , 8192 ) ;
break;
default:
break;
}
F_3 ( V_1 , V_2 -> V_20 , V_40 , V_37 ) ;
F_3 ( V_1 , V_2 -> V_20 , V_39 , V_36 ) ;
V_36 = F_1 ( V_1 , V_2 -> V_20 , V_39 ) ;
V_35 |= V_38 ;
F_3 ( V_1 , V_2 -> V_20 , V_32 , V_35 ) ;
}
static void F_16 ( struct V_49 * V_50 )
{
struct V_2 * V_2 = F_17 ( V_50 , struct V_2 , V_50 ) ;
struct V_51 * V_52 ;
int V_53 = 0 ;
if ( ! V_2 )
return;
V_52 = V_2 -> V_52 ;
if ( ! V_52 -> V_23 && V_2 -> V_54 )
V_53 = - 1 ;
if ( V_52 -> V_23 &&
( V_2 -> V_26 != V_52 -> V_25 ||
V_2 -> V_54 != V_52 -> V_23 ||
V_2 -> V_28 != V_52 -> V_27 ) ) {
V_53 = 1 ;
}
V_2 -> V_54 = V_52 -> V_23 ;
V_2 -> V_28 = V_52 -> V_27 ;
V_2 -> V_26 = V_52 -> V_25 ;
if ( ! V_53 )
return;
if ( V_53 > 0 )
V_2 -> V_24 = true ;
else
V_2 -> V_24 = false ;
if ( V_2 -> V_55 )
F_15 ( V_2 ) ;
else
F_18 ( V_2 ) ;
}
T_1 F_19 ( int V_13 , int V_18 , int V_2 , int V_56 )
{
struct V_1 * V_1 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return 0 ;
if ( V_56 > 8 )
V_2 = 0 ;
return F_1 ( V_1 , V_2 , V_57 + ( V_56 * 8 ) ) ;
}
T_1 F_20 ( int V_13 , int V_18 , int V_2 , int V_56 )
{
struct V_1 * V_1 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return 0 ;
return F_1 ( V_1 , V_2 , V_58 + ( V_56 * 8 ) ) ;
}
static void F_21 ( struct V_1 * V_1 , int V_2 )
{
T_1 V_3 ;
while ( V_1 -> V_2 [ V_2 ] . V_59 > 0 ) {
V_3 = ( ( V_1 -> V_2 [ V_2 ] . V_59 - 1 ) * sizeof( T_1 ) ) +
( V_2 * V_60 * sizeof( T_1 ) ) ;
F_3 ( V_1 , 0 , V_61 + V_3 , 0 ) ;
V_1 -> V_2 [ V_2 ] . V_59 -- ;
}
}
void F_22 ( int V_13 , int V_18 ,
int V_62 , bool V_30 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
T_1 V_31 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_62 ] ;
if ( V_2 -> V_55 ) {
V_31 = F_1 ( V_1 , V_62 , V_63 ) ;
if ( V_30 )
V_31 |= V_64 ;
else
V_31 &= ~ V_64 ;
F_3 ( V_1 , V_62 , V_63 , V_31 ) ;
} else {
V_31 = F_1 ( V_1 , V_62 , V_65 ) ;
if ( V_30 )
V_31 |= V_66 ;
else
V_31 &= ~ V_66 ;
F_3 ( V_1 , V_62 , V_65 , V_31 ) ;
}
}
static int F_23 ( struct V_1 * V_1 , int V_20 )
{
T_1 V_31 ;
F_5 ( V_1 , V_20 , V_67 , 0x30 ) ;
F_5 ( V_1 , V_20 , V_68 , V_69 ) ;
V_31 = F_1 ( V_1 , V_20 , V_70 ) ;
if ( V_31 & 1 )
F_3 ( V_1 , V_20 , V_71 , 0 ) ;
F_5 ( V_1 , V_20 , V_32 , V_38 ) ;
F_5 ( V_1 , V_20 , V_63 , V_72 ) ;
if ( F_6 ( V_1 , V_20 , V_63 ,
V_72 , true ) ) {
F_24 ( & V_1 -> V_73 -> V_74 , L_1 ) ;
return - 1 ;
}
V_31 = F_1 ( V_1 , V_20 , V_63 ) ;
V_31 &= ~ V_75 ;
V_31 |= ( V_76 | V_77 ) ;
F_3 ( V_1 , V_20 , V_63 , V_31 ) ;
if ( F_6 ( V_1 , V_20 , V_78 ,
V_79 , false ) ) {
F_24 ( & V_1 -> V_73 -> V_74 , L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_1 , int V_20 , int V_80 )
{
T_1 V_31 ;
F_5 ( V_1 , V_20 , V_65 , V_81 ) ;
if ( F_6 ( V_1 , V_20 , V_65 , V_81 , true ) ) {
F_24 ( & V_1 -> V_73 -> V_74 , L_3 ) ;
return - 1 ;
}
V_31 = F_1 ( V_1 , V_20 , V_32 ) ;
V_31 &= ~ V_38 ;
F_3 ( V_1 , V_20 , V_32 , V_31 ) ;
F_5 ( V_1 , V_20 , V_65 , V_82 ) ;
if ( V_1 -> V_80 != V_83 )
F_5 ( V_1 , V_20 ,
V_84 , V_85 ) ;
else
F_5 ( V_1 , V_20 , V_84 ,
V_85 | V_86 ) ;
V_31 = F_1 ( V_1 , V_20 , V_87 ) ;
F_3 ( V_1 , V_20 , V_87 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_88 ) ;
F_3 ( V_1 , V_20 , V_88 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_89 ) ;
F_3 ( V_1 , V_20 , V_89 , V_31 ) ;
if ( V_1 -> V_90 ) {
F_3 ( V_1 , V_20 , V_91 , 0x00 ) ;
F_3 ( V_1 , V_20 , V_92 , 0x00 ) ;
F_3 ( V_1 , V_20 , V_93 , 0x00 ) ;
F_5 ( V_1 , V_20 ,
V_94 , V_95 ) ;
}
F_5 ( V_1 , V_20 , V_96 , V_97 ) ;
V_31 = F_1 ( V_1 , V_20 , V_98 ) ;
V_31 &= ~ V_99 ;
F_3 ( V_1 , V_20 , V_98 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_100 ) ;
V_31 = V_31 & ~ ( V_101 | V_102 ) ;
F_3 ( V_1 , V_20 , V_100 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_103 ) ;
if ( V_1 -> V_80 == V_104 )
V_31 |= ( 1 << 23 ) ;
else if ( V_1 -> V_80 == V_105 )
V_31 |= ( 1 << 24 ) ;
else
V_31 &= ~ ( ( 1 << 23 ) | ( 1 << 24 ) ) ;
V_31 = V_31 & ( ~ ( ( 1ULL << 25 ) | ( 1ULL << 22 ) | ( 1ULL << 12 ) ) ) ;
F_3 ( V_1 , V_20 , V_103 , V_31 ) ;
V_31 = F_1 ( V_1 , 0 , V_106 ) ;
V_31 &= ~ V_107 ;
F_3 ( V_1 , 0 , V_106 , V_31 ) ;
F_5 ( V_1 , V_20 , V_32 , V_38 ) ;
V_31 = F_1 ( V_1 , V_20 , V_65 ) ;
V_31 &= ~ V_82 ;
F_3 ( V_1 , V_20 , V_65 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_108 ) ;
V_31 &= ~ V_109 ;
V_31 |= V_110 ;
F_3 ( V_1 , V_20 , V_108 , V_31 ) ;
F_5 ( V_1 , V_20 , V_111 , ( 0x100 - 1 ) ) ;
F_5 ( V_1 , V_20 , V_112 , V_69 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_1 ;
int V_20 = V_2 -> V_20 ;
int V_80 = V_1 -> V_80 ;
T_1 V_31 ;
F_5 ( V_1 , V_20 , V_84 , V_85 ) ;
if ( V_1 -> V_90 ) {
V_31 = F_1 ( V_1 , V_20 , V_89 ) ;
if ( ! ( V_31 & ( 1ull << 13 ) ) ) {
V_31 = ( 1ull << 13 ) | ( 1ull << 14 ) ;
F_3 ( V_1 , V_20 , V_89 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_94 ) ;
V_31 |= ( 1ull << 0 ) ;
F_3 ( V_1 , V_20 , V_94 , V_31 ) ;
return - 1 ;
}
}
if ( F_6 ( V_1 , V_20 , V_65 , V_81 , true ) ) {
F_24 ( & V_1 -> V_73 -> V_74 , L_3 ) ;
return - 1 ;
}
if ( ( V_80 == V_104 ) || ( V_80 == V_113 ) ||
( V_80 == V_105 ) || ( V_80 == V_114 ) ) {
if ( F_6 ( V_1 , V_20 , V_115 ,
V_116 , false ) ) {
F_24 ( & V_1 -> V_73 -> V_74 ,
L_4 ) ;
return - 1 ;
}
} else {
if ( F_6 ( V_1 , V_20 , V_117 ,
V_118 , false ) ) {
F_24 ( & V_1 -> V_73 -> V_74 ,
L_5 ) ;
return - 1 ;
}
}
if ( F_1 ( V_1 , V_20 , V_119 ) & V_120 )
F_5 ( V_1 , V_20 ,
V_119 , V_120 ) ;
if ( F_1 ( V_1 , V_20 , V_119 ) & V_120 ) {
F_24 ( & V_1 -> V_73 -> V_74 , L_6 ) ;
if ( V_1 -> V_90 ) {
V_31 = F_1 ( V_1 , V_20 , V_89 ) ;
if ( ! ( V_31 & ( 1ull << 13 ) ) ) {
V_31 = ( 1ull << 13 ) | ( 1ull << 14 ) ;
F_3 ( V_1 , V_20 , V_89 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 ,
V_94 ) ;
V_31 |= ( 1ull << 0 ) ;
F_3 ( V_1 , V_20 ,
V_94 , V_31 ) ;
return - 1 ;
}
}
return - 1 ;
}
if ( F_6 ( V_1 , V_20 , V_121 , V_122 , false ) ) {
F_24 ( & V_1 -> V_73 -> V_74 , L_7 ) ;
return - 1 ;
}
if ( F_6 ( V_1 , V_20 , V_121 , V_123 , false ) ) {
F_24 ( & V_1 -> V_73 -> V_74 , L_8 ) ;
return - 1 ;
}
V_31 = F_1 ( V_1 , V_20 , V_84 ) ;
V_31 &= ~ V_85 ;
F_3 ( V_1 , V_20 , V_84 , V_31 ) ;
V_31 = F_1 ( V_1 , V_20 , V_124 ) ;
V_31 &= V_125 ;
if ( ! V_31 )
return 0 ;
F_25 ( V_1 , V_20 , V_1 -> V_80 ) ;
return - 1 ;
}
static void F_26 ( struct V_126 * V_127 )
{
struct V_2 * V_2 ;
T_1 V_128 , V_129 ;
V_2 = F_17 ( V_127 , struct V_2 , V_130 . V_127 ) ;
F_5 ( V_2 -> V_1 , V_2 -> V_20 ,
V_131 , V_132 ) ;
F_6 ( V_2 -> V_1 , V_2 -> V_20 , V_131 ,
V_132 , false ) ;
V_128 = F_1 ( V_2 -> V_1 , V_2 -> V_20 , V_131 ) ;
V_129 = F_1 ( V_2 -> V_1 , V_2 -> V_20 , V_124 ) ;
if ( ( V_128 & V_132 ) &&
! ( V_129 & V_125 ) ) {
V_2 -> V_24 = 1 ;
if ( V_2 -> V_1 -> V_80 == V_114 )
V_2 -> V_28 = 40000 ;
else
V_2 -> V_28 = 10000 ;
V_2 -> V_26 = 1 ;
} else {
V_2 -> V_24 = 0 ;
V_2 -> V_28 = V_133 ;
V_2 -> V_26 = V_134 ;
}
if ( V_2 -> V_54 != V_2 -> V_24 ) {
if ( V_2 -> V_24 ) {
if ( F_18 ( V_2 ) ) {
V_2 -> V_24 = 0 ;
V_2 -> V_28 = V_133 ;
V_2 -> V_26 = V_134 ;
}
}
V_2 -> V_54 = V_2 -> V_24 ;
}
F_27 ( V_2 -> V_135 , & V_2 -> V_130 , V_136 * 2 ) ;
}
static int F_28 ( struct V_1 * V_1 , T_2 V_20 )
{
struct V_2 * V_2 ;
T_1 V_31 ;
V_2 = & V_1 -> V_2 [ V_20 ] ;
V_2 -> V_1 = V_1 ;
if ( V_1 -> V_80 == V_137 ) {
V_2 -> V_55 = 1 ;
if ( F_23 ( V_1 , V_20 ) )
return - 1 ;
} else {
V_2 -> V_55 = 0 ;
if ( F_25 ( V_1 , V_20 , V_1 -> V_80 ) )
return - 1 ;
}
if ( V_2 -> V_55 ) {
V_31 = F_1 ( V_1 , V_20 , V_70 ) ;
V_31 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_20 , V_70 , V_31 ) ;
F_3 ( V_1 , V_20 , V_138 , 60 - 1 ) ;
} else {
V_31 = F_1 ( V_1 , V_20 , V_96 ) ;
V_31 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_20 , V_96 , V_31 ) ;
F_3 ( V_1 , V_20 , V_139 , 60 + 4 ) ;
}
F_5 ( V_1 , V_20 , V_32 , V_38 ) ;
F_3 ( V_1 , V_20 , V_140 , 0x03 ) ;
if ( ( V_1 -> V_80 != V_113 ) &&
( V_1 -> V_80 != V_114 ) &&
( V_1 -> V_80 != V_105 ) &&
( V_1 -> V_80 != V_104 ) ) {
if ( ! V_2 -> V_52 )
return - V_141 ;
V_2 -> V_52 -> V_142 = 0 ;
if ( F_29 ( & V_2 -> V_50 , V_2 -> V_52 ,
F_16 ,
V_143 ) )
return - V_141 ;
F_30 ( V_2 -> V_52 ) ;
} else {
V_2 -> V_135 = F_31 ( L_9 , V_144 |
V_145 , 1 ) ;
if ( ! V_2 -> V_135 )
return - V_146 ;
F_32 ( & V_2 -> V_130 , F_26 ) ;
F_27 ( V_2 -> V_135 , & V_2 -> V_130 , 0 ) ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_1 , T_2 V_20 )
{
struct V_2 * V_2 ;
T_1 V_31 ;
V_2 = & V_1 -> V_2 [ V_20 ] ;
if ( V_2 -> V_135 ) {
F_34 ( & V_2 -> V_130 ) ;
F_35 ( V_2 -> V_135 ) ;
}
V_31 = F_1 ( V_1 , V_20 , V_32 ) ;
V_31 &= ~ V_33 ;
F_3 ( V_1 , V_20 , V_32 , V_31 ) ;
F_6 ( V_1 , V_20 , V_147 , ( T_1 ) 0x1FFF , true ) ;
F_6 ( V_1 , V_20 , V_148 , ( T_1 ) 0x3FFF , true ) ;
V_31 = F_1 ( V_1 , V_20 , V_32 ) ;
V_31 &= ~ V_34 ;
F_3 ( V_1 , V_20 , V_32 , V_31 ) ;
if ( ! V_2 -> V_55 )
F_5 ( V_1 , V_20 ,
V_65 , V_82 ) ;
else
F_5 ( V_1 , V_20 ,
V_63 , V_75 ) ;
V_31 = F_1 ( V_1 , V_20 , V_32 ) ;
V_31 &= ~ V_38 ;
F_3 ( V_1 , V_20 , V_32 , V_31 ) ;
F_21 ( V_1 , V_20 ) ;
if ( ( V_1 -> V_80 != V_113 ) &&
( V_1 -> V_80 != V_114 ) &&
( V_1 -> V_80 != V_105 ) &&
( V_1 -> V_80 != V_104 ) && V_2 -> V_52 )
F_36 ( V_2 -> V_52 ) ;
V_2 -> V_52 = NULL ;
}
static void F_37 ( struct V_1 * V_1 )
{
T_1 V_19 ;
switch ( V_1 -> V_149 ) {
case V_150 :
V_1 -> V_19 = 4 ;
V_1 -> V_80 = V_137 ;
V_1 -> V_151 = 0 ;
break;
case V_152 :
V_1 -> V_19 = 1 ;
V_1 -> V_80 = V_153 ;
V_1 -> V_151 = 0xE4 ;
break;
case V_154 :
V_1 -> V_19 = 2 ;
V_1 -> V_80 = V_83 ;
V_1 -> V_151 = 0xE4 ;
break;
case V_155 :
V_1 -> V_19 = 4 ;
V_1 -> V_80 = V_113 ;
V_1 -> V_151 = 0 ;
break;
case V_156 :
V_1 -> V_19 = 1 ;
V_1 -> V_80 = V_114 ;
V_1 -> V_151 = 0xE4 ;
break;
case V_157 :
V_1 -> V_19 = 4 ;
V_1 -> V_80 = V_104 ;
V_1 -> V_151 = 0 ;
V_1 -> V_90 = 1 ;
break;
case V_158 :
V_1 -> V_19 = 1 ;
V_1 -> V_80 = V_105 ;
V_1 -> V_151 = 0xE4 ;
V_1 -> V_90 = 1 ;
break;
default:
V_1 -> V_19 = 0 ;
break;
}
V_19 = F_1 ( V_1 , 0 , V_159 ) & 0x7 ;
if ( V_19 != 4 )
V_1 -> V_19 = V_19 ;
}
static void F_38 ( struct V_1 * V_1 )
{
int V_14 ;
F_37 ( V_1 ) ;
F_5 ( V_1 , 0 , V_160 , V_161 ) ;
if ( F_1 ( V_1 , 0 , V_162 ) )
F_24 ( & V_1 -> V_73 -> V_74 , L_10 , V_1 -> V_163 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_19 ; V_14 ++ ) {
if ( V_1 -> V_80 == V_83 ) {
if ( V_14 )
V_1 -> V_151 = 0x0e ;
else
V_1 -> V_151 = 0x04 ;
F_3 ( V_1 , V_14 , V_32 ,
( V_1 -> V_80 << 8 ) | V_1 -> V_151 ) ;
continue;
}
F_3 ( V_1 , V_14 , V_32 ,
( V_1 -> V_80 << 8 ) | ( V_1 -> V_151 + V_14 ) ) ;
V_1 -> V_2 [ V_14 ] . V_164 = V_19 ;
V_19 ++ ;
}
F_3 ( V_1 , 0 , V_165 , V_1 -> V_19 ) ;
F_3 ( V_1 , 0 , V_159 , V_1 -> V_19 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_19 ; V_14 ++ )
F_5 ( V_1 , 0 , V_166 ,
( ( 1ULL << V_167 ) - 1 ) <<
( V_14 * V_167 ) ) ;
for ( V_14 = 0 ; V_14 < V_168 ; V_14 ++ )
F_3 ( V_1 , 0 , V_61 + ( V_14 * 8 ) , 0x00 ) ;
for ( V_14 = 0 ; V_14 < V_169 ; V_14 ++ )
F_3 ( V_1 , 0 , V_170 + ( V_14 * 8 ) , 0x00 ) ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_171 * V_74 = & V_1 -> V_73 -> V_74 ;
int V_80 ;
int V_172 ;
V_80 = F_1 ( V_1 , 0 , V_32 ) ;
V_80 = ( V_80 >> 8 ) & 0x07 ;
V_172 = F_1 ( V_1 , 0 , V_94 ) &
V_95 ;
switch ( V_80 ) {
case V_137 :
V_1 -> V_149 = V_150 ;
F_40 ( V_74 , L_11 , V_1 -> V_163 ) ;
break;
case V_153 :
V_1 -> V_149 = V_152 ;
F_40 ( V_74 , L_12 , V_1 -> V_163 ) ;
break;
case V_83 :
V_1 -> V_149 = V_154 ;
F_40 ( V_74 , L_13 , V_1 -> V_163 ) ;
break;
case V_113 :
if ( ! V_172 ) {
V_1 -> V_149 = V_155 ;
F_40 ( V_74 , L_14 , V_1 -> V_163 ) ;
} else {
V_1 -> V_149 = V_157 ;
F_40 ( V_74 , L_15 , V_1 -> V_163 ) ;
}
break;
case V_114 :
if ( ! V_172 ) {
V_1 -> V_149 = V_156 ;
F_40 ( V_74 , L_16 , V_1 -> V_163 ) ;
} else {
V_1 -> V_149 = V_158 ;
F_40 ( V_74 , L_17 , V_1 -> V_163 ) ;
}
break;
default:
V_1 -> V_149 = V_150 ;
F_40 ( V_74 , L_18 , V_1 -> V_163 ) ;
}
}
static int F_41 ( struct V_171 * V_74 , struct V_173 * V_174 ,
T_2 * V_175 )
{
T_2 V_29 [ V_176 ] ;
int V_177 ;
V_177 = F_42 ( F_43 ( V_174 ) ,
L_19 , V_29 , V_176 ) ;
if ( V_177 )
goto V_178;
if ( ! F_44 ( V_29 ) ) {
F_24 ( V_74 , L_20 , V_29 ) ;
V_177 = - V_179 ;
goto V_178;
}
F_40 ( V_74 , L_21 , V_29 ) ;
memcpy ( V_175 , V_29 , V_176 ) ;
V_178:
return V_177 ;
}
static T_4 F_45 ( T_5 V_180 ,
V_6 V_181 , void * V_182 , void * * V_183 )
{
struct V_1 * V_1 = V_182 ;
struct V_171 * V_74 = & V_1 -> V_73 -> V_74 ;
struct V_173 * V_174 ;
if ( F_46 ( V_180 , & V_174 ) )
goto V_178;
F_41 ( V_74 , V_174 , V_1 -> V_2 [ V_1 -> V_19 ] . V_29 ) ;
F_47 ( & V_1 -> V_2 [ V_1 -> V_19 ] . V_50 , V_74 ) ;
V_1 -> V_2 [ V_1 -> V_19 ] . V_20 = V_1 -> V_19 ;
V_178:
V_1 -> V_19 ++ ;
return V_184 ;
}
static T_4 F_48 ( T_5 V_180 , V_6 V_181 ,
void * V_182 , void * * V_185 )
{
struct V_186 string = { V_187 , NULL } ;
struct V_1 * V_1 = V_182 ;
char V_188 [ 5 ] ;
snprintf ( V_188 , 5 , L_22 , V_1 -> V_163 ) ;
if ( F_49 ( F_50 ( V_180 , V_189 , & string ) ) ) {
F_51 ( L_23 ) ;
return V_184 ;
}
if ( strncmp ( string . V_190 , V_188 , 4 ) )
return V_184 ;
F_52 ( V_191 , V_180 , 1 ,
F_45 , NULL , V_1 , NULL ) ;
F_53 ( string . V_190 ) ;
return V_192 ;
}
static int F_54 ( struct V_1 * V_1 )
{
F_55 ( NULL , F_48 , V_1 , ( void * * ) NULL ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_1 )
{
return - V_141 ;
}
static int F_56 ( struct V_1 * V_1 )
{
struct V_193 * V_194 ;
struct V_195 * V_13 = NULL ;
T_2 V_2 = 0 ;
F_57 (&bgx->pdev->dev, fwn) {
struct V_51 * V_196 ;
struct V_195 * V_197 ;
const char * V_29 ;
V_13 = F_58 ( V_194 ) ;
if ( ! V_13 )
break;
V_29 = F_59 ( V_13 ) ;
if ( V_29 )
F_13 ( V_1 -> V_2 [ V_2 ] . V_29 , V_29 ) ;
F_47 ( & V_1 -> V_2 [ V_2 ] . V_50 , & V_1 -> V_73 -> V_74 ) ;
V_1 -> V_2 [ V_2 ] . V_20 = V_2 ;
V_197 = F_60 ( V_13 , L_24 , 0 ) ;
if ( V_197 &&
! F_61 ( V_197 , L_25 ) ) {
V_196 = F_62 ( V_197 ) ;
if ( ! V_196 )
goto V_198;
V_1 -> V_2 [ V_2 ] . V_52 = V_196 ;
}
V_2 ++ ;
if ( V_2 == V_199 ) {
F_63 ( V_13 ) ;
break;
}
}
return 0 ;
V_198:
while ( V_2 ) {
if ( V_1 -> V_2 [ V_2 ] . V_52 ) {
F_64 ( & V_1 -> V_2 [ V_2 ] . V_52 -> V_200 . V_74 ) ;
V_1 -> V_2 [ V_2 ] . V_52 = NULL ;
}
V_2 -- ;
}
F_63 ( V_13 ) ;
return - V_201 ;
}
static int F_56 ( struct V_1 * V_1 )
{
return - V_141 ;
}
static int F_65 ( struct V_1 * V_1 )
{
if ( ! V_202 )
return F_54 ( V_1 ) ;
return F_56 ( V_1 ) ;
}
static int F_66 ( struct V_203 * V_73 , const struct V_204 * V_205 )
{
int V_206 ;
struct V_171 * V_74 = & V_73 -> V_74 ;
struct V_1 * V_1 = NULL ;
T_2 V_2 ;
V_1 = F_67 ( V_74 , sizeof( * V_1 ) , V_207 ) ;
if ( ! V_1 )
return - V_146 ;
V_1 -> V_73 = V_73 ;
F_68 ( V_73 , V_1 ) ;
V_206 = F_69 ( V_73 ) ;
if ( V_206 ) {
F_24 ( V_74 , L_26 ) ;
F_68 ( V_73 , NULL ) ;
return V_206 ;
}
V_206 = F_70 ( V_73 , V_208 ) ;
if ( V_206 ) {
F_24 ( V_74 , L_27 , V_206 ) ;
goto V_209;
}
V_1 -> V_5 = F_71 ( V_73 , V_210 , 0 ) ;
if ( ! V_1 -> V_5 ) {
F_24 ( V_74 , L_28 ) ;
V_206 = - V_146 ;
goto V_211;
}
V_1 -> V_163 = ( F_72 ( V_73 , V_210 ) >> 24 ) & 1 ;
V_1 -> V_163 += F_73 ( V_73 ) * V_16 ;
V_17 [ V_1 -> V_163 ] = V_1 ;
F_39 ( V_1 ) ;
V_206 = F_65 ( V_1 ) ;
if ( V_206 )
goto V_212;
F_38 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_1 -> V_19 ; V_2 ++ ) {
V_206 = F_28 ( V_1 , V_2 ) ;
if ( V_206 ) {
F_24 ( V_74 , L_29 ,
V_1 -> V_163 , V_2 ) ;
goto V_212;
}
}
return 0 ;
V_212:
V_17 [ V_1 -> V_163 ] = NULL ;
V_211:
F_74 ( V_73 ) ;
V_209:
F_75 ( V_73 ) ;
F_68 ( V_73 , NULL ) ;
return V_206 ;
}
static void F_76 ( struct V_203 * V_73 )
{
struct V_1 * V_1 = F_77 ( V_73 ) ;
T_2 V_2 ;
for ( V_2 = 0 ; V_2 < V_1 -> V_19 ; V_2 ++ )
F_33 ( V_1 , V_2 ) ;
V_17 [ V_1 -> V_163 ] = NULL ;
F_74 ( V_73 ) ;
F_75 ( V_73 ) ;
F_68 ( V_73 , NULL ) ;
}
static int T_6 F_78 ( void )
{
F_79 ( L_30 , V_208 , V_213 ) ;
return F_80 ( & V_214 ) ;
}
static void T_7 F_81 ( void )
{
F_82 ( & V_214 ) ;
}
