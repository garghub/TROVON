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
static void F_14 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_1 ;
T_1 V_30 ;
T_1 V_31 = 0 ;
T_1 V_32 = 0 ;
V_30 = F_1 ( V_1 , V_2 -> V_20 , V_33 ) ;
V_30 &= ~ V_34 ;
F_3 ( V_1 , V_2 -> V_20 , V_33 , V_30 ) ;
V_31 = F_1 ( V_1 , V_2 -> V_20 , V_35 ) ;
V_32 = F_1 ( V_1 , V_2 -> V_20 , V_36 ) ;
if ( V_2 -> V_24 ) {
V_32 &= ~ V_37 ;
V_31 &= ~ V_38 ;
V_31 |= ( V_2 -> V_26 << 2 ) ;
} else {
V_32 |= V_37 ;
}
switch ( V_2 -> V_28 ) {
case 10 :
V_31 &= ~ V_39 ;
V_31 |= V_40 ;
V_31 &= ~ V_41 ;
V_32 &= ~ V_42 ;
V_32 |= 50 ;
F_3 ( V_1 , V_2 -> V_20 , V_43 , 64 ) ;
F_3 ( V_1 , V_2 -> V_20 , V_44 , 0 ) ;
break;
case 100 :
V_31 &= ~ V_39 ;
V_31 &= ~ V_40 ;
V_31 &= ~ V_41 ;
V_32 &= ~ V_42 ;
V_32 |= 5 ;
F_3 ( V_1 , V_2 -> V_20 , V_43 , 64 ) ;
F_3 ( V_1 , V_2 -> V_20 , V_44 , 0 ) ;
break;
case 1000 :
V_31 |= V_39 ;
V_31 &= ~ V_40 ;
V_31 |= V_41 ;
V_32 &= ~ V_42 ;
V_32 |= 1 ;
F_3 ( V_1 , V_2 -> V_20 , V_43 , 512 ) ;
if ( V_2 -> V_26 )
F_3 ( V_1 , V_2 -> V_20 ,
V_44 , 0 ) ;
else
F_3 ( V_1 , V_2 -> V_20 ,
V_44 , 8192 ) ;
break;
default:
break;
}
F_3 ( V_1 , V_2 -> V_20 , V_36 , V_32 ) ;
F_3 ( V_1 , V_2 -> V_20 , V_35 , V_31 ) ;
V_31 = F_1 ( V_1 , V_2 -> V_20 , V_35 ) ;
V_30 |= V_34 ;
F_3 ( V_1 , V_2 -> V_20 , V_33 , V_30 ) ;
}
static void F_15 ( struct V_45 * V_46 )
{
struct V_2 * V_2 = F_16 ( V_46 , struct V_2 , V_46 ) ;
struct V_47 * V_48 = V_2 -> V_48 ;
int V_49 = 0 ;
if ( ! V_2 )
return;
if ( ! V_48 -> V_23 && V_2 -> V_50 )
V_49 = - 1 ;
if ( V_48 -> V_23 &&
( V_2 -> V_26 != V_48 -> V_25 ||
V_2 -> V_50 != V_48 -> V_23 ||
V_2 -> V_28 != V_48 -> V_27 ) ) {
V_49 = 1 ;
}
V_2 -> V_50 = V_48 -> V_23 ;
V_2 -> V_28 = V_48 -> V_27 ;
V_2 -> V_26 = V_48 -> V_25 ;
if ( ! V_49 )
return;
if ( V_49 > 0 )
V_2 -> V_24 = true ;
else
V_2 -> V_24 = false ;
if ( V_2 -> V_51 )
F_14 ( V_2 ) ;
else
F_17 ( V_2 ) ;
}
T_1 F_18 ( int V_13 , int V_18 , int V_2 , int V_52 )
{
struct V_1 * V_1 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return 0 ;
if ( V_52 > 8 )
V_2 = 0 ;
return F_1 ( V_1 , V_2 , V_53 + ( V_52 * 8 ) ) ;
}
T_1 F_19 ( int V_13 , int V_18 , int V_2 , int V_52 )
{
struct V_1 * V_1 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return 0 ;
return F_1 ( V_1 , V_2 , V_54 + ( V_52 * 8 ) ) ;
}
static void F_20 ( struct V_1 * V_1 , int V_2 )
{
T_1 V_3 ;
while ( V_1 -> V_2 [ V_2 ] . V_55 > 0 ) {
V_3 = ( ( V_1 -> V_2 [ V_2 ] . V_55 - 1 ) * sizeof( T_1 ) ) +
( V_2 * V_56 * sizeof( T_1 ) ) ;
F_3 ( V_1 , 0 , V_57 + V_3 , 0 ) ;
V_1 -> V_2 [ V_2 ] . V_55 -- ;
}
}
void F_21 ( int V_13 , int V_18 ,
int V_58 , bool V_59 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
T_1 V_60 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_58 ] ;
if ( V_2 -> V_51 ) {
V_60 = F_1 ( V_1 , V_58 , V_61 ) ;
if ( V_59 )
V_60 |= V_62 ;
else
V_60 &= ~ V_62 ;
F_3 ( V_1 , V_58 , V_61 , V_60 ) ;
} else {
V_60 = F_1 ( V_1 , V_58 , V_63 ) ;
if ( V_59 )
V_60 |= V_64 ;
else
V_60 &= ~ V_64 ;
F_3 ( V_1 , V_58 , V_63 , V_60 ) ;
}
}
static int F_22 ( struct V_1 * V_1 , int V_20 )
{
T_1 V_60 ;
F_5 ( V_1 , V_20 , V_65 , 0x30 ) ;
F_5 ( V_1 , V_20 , V_66 , V_67 ) ;
V_60 = F_1 ( V_1 , V_20 , V_68 ) ;
if ( V_60 & 1 )
F_3 ( V_1 , V_20 , V_69 , 0 ) ;
F_5 ( V_1 , V_20 , V_33 , V_34 ) ;
F_5 ( V_1 , V_20 , V_61 , V_70 ) ;
if ( F_6 ( V_1 , V_20 , V_61 ,
V_70 , true ) ) {
F_23 ( & V_1 -> V_71 -> V_72 , L_1 ) ;
return - 1 ;
}
V_60 = F_1 ( V_1 , V_20 , V_61 ) ;
V_60 &= ~ V_73 ;
V_60 |= ( V_74 | V_75 ) ;
F_3 ( V_1 , V_20 , V_61 , V_60 ) ;
if ( F_6 ( V_1 , V_20 , V_76 ,
V_77 , false ) ) {
F_23 ( & V_1 -> V_71 -> V_72 , L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_1 , int V_20 , int V_78 )
{
T_1 V_60 ;
F_5 ( V_1 , V_20 , V_63 , V_79 ) ;
if ( F_6 ( V_1 , V_20 , V_63 , V_79 , true ) ) {
F_23 ( & V_1 -> V_71 -> V_72 , L_3 ) ;
return - 1 ;
}
V_60 = F_1 ( V_1 , V_20 , V_33 ) ;
V_60 &= ~ V_34 ;
F_3 ( V_1 , V_20 , V_33 , V_60 ) ;
F_5 ( V_1 , V_20 , V_63 , V_80 ) ;
if ( V_1 -> V_78 != V_81 )
F_5 ( V_1 , V_20 ,
V_82 , V_83 ) ;
else
F_5 ( V_1 , V_20 , V_82 ,
V_83 | V_84 ) ;
V_60 = F_1 ( V_1 , V_20 , V_85 ) ;
F_3 ( V_1 , V_20 , V_85 , V_60 ) ;
V_60 = F_1 ( V_1 , V_20 , V_86 ) ;
F_3 ( V_1 , V_20 , V_86 , V_60 ) ;
V_60 = F_1 ( V_1 , V_20 , V_87 ) ;
F_3 ( V_1 , V_20 , V_87 , V_60 ) ;
if ( V_1 -> V_88 ) {
F_3 ( V_1 , V_20 , V_89 , 0x00 ) ;
F_3 ( V_1 , V_20 , V_90 , 0x00 ) ;
F_3 ( V_1 , V_20 , V_91 , 0x00 ) ;
F_5 ( V_1 , V_20 ,
V_92 , V_93 ) ;
}
F_5 ( V_1 , V_20 , V_94 , V_95 ) ;
V_60 = F_1 ( V_1 , V_20 , V_96 ) ;
V_60 &= ~ V_97 ;
F_3 ( V_1 , V_20 , V_96 , V_60 ) ;
V_60 = F_1 ( V_1 , V_20 , V_98 ) ;
V_60 = V_60 & ~ ( V_99 | V_100 ) ;
F_3 ( V_1 , V_20 , V_98 , V_60 ) ;
V_60 = F_1 ( V_1 , V_20 , V_101 ) ;
if ( V_1 -> V_78 == V_102 )
V_60 |= ( 1 << 23 ) ;
else if ( V_1 -> V_78 == V_103 )
V_60 |= ( 1 << 24 ) ;
else
V_60 &= ~ ( ( 1 << 23 ) | ( 1 << 24 ) ) ;
V_60 = V_60 & ( ~ ( ( 1ULL << 25 ) | ( 1ULL << 22 ) | ( 1ULL << 12 ) ) ) ;
F_3 ( V_1 , V_20 , V_101 , V_60 ) ;
V_60 = F_1 ( V_1 , 0 , V_104 ) ;
V_60 &= ~ V_105 ;
F_3 ( V_1 , 0 , V_104 , V_60 ) ;
F_5 ( V_1 , V_20 , V_33 , V_34 ) ;
V_60 = F_1 ( V_1 , V_20 , V_63 ) ;
V_60 &= ~ V_80 ;
F_3 ( V_1 , V_20 , V_63 , V_60 ) ;
V_60 = F_1 ( V_1 , V_20 , V_106 ) ;
V_60 &= ~ V_107 ;
V_60 |= V_108 ;
F_3 ( V_1 , V_20 , V_106 , V_60 ) ;
F_5 ( V_1 , V_20 , V_109 , ( 0x100 - 1 ) ) ;
F_5 ( V_1 , V_20 , V_110 , V_67 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_1 ;
int V_20 = V_2 -> V_20 ;
int V_78 = V_1 -> V_78 ;
T_1 V_60 ;
F_5 ( V_1 , V_20 , V_82 , V_83 ) ;
if ( V_1 -> V_88 ) {
V_60 = F_1 ( V_1 , V_20 , V_87 ) ;
if ( ! ( V_60 & ( 1ull << 13 ) ) ) {
V_60 = ( 1ull << 13 ) | ( 1ull << 14 ) ;
F_3 ( V_1 , V_20 , V_87 , V_60 ) ;
V_60 = F_1 ( V_1 , V_20 , V_92 ) ;
V_60 |= ( 1ull << 0 ) ;
F_3 ( V_1 , V_20 , V_92 , V_60 ) ;
return - 1 ;
}
}
if ( F_6 ( V_1 , V_20 , V_63 , V_79 , true ) ) {
F_23 ( & V_1 -> V_71 -> V_72 , L_3 ) ;
return - 1 ;
}
if ( ( V_78 == V_102 ) || ( V_78 == V_111 ) ||
( V_78 == V_103 ) || ( V_78 == V_112 ) ) {
if ( F_6 ( V_1 , V_20 , V_113 ,
V_114 , false ) ) {
F_23 ( & V_1 -> V_71 -> V_72 ,
L_4 ) ;
return - 1 ;
}
} else {
if ( F_6 ( V_1 , V_20 , V_115 ,
V_116 , false ) ) {
F_23 ( & V_1 -> V_71 -> V_72 ,
L_5 ) ;
return - 1 ;
}
}
F_5 ( V_1 , V_20 , V_117 , V_118 ) ;
if ( F_1 ( V_1 , V_20 , V_117 ) & V_118 ) {
F_23 ( & V_1 -> V_71 -> V_72 , L_6 ) ;
if ( V_1 -> V_88 ) {
V_60 = F_1 ( V_1 , V_20 , V_87 ) ;
if ( ! ( V_60 & ( 1ull << 13 ) ) ) {
V_60 = ( 1ull << 13 ) | ( 1ull << 14 ) ;
F_3 ( V_1 , V_20 , V_87 , V_60 ) ;
V_60 = F_1 ( V_1 , V_20 ,
V_92 ) ;
V_60 |= ( 1ull << 0 ) ;
F_3 ( V_1 , V_20 ,
V_92 , V_60 ) ;
return - 1 ;
}
}
return - 1 ;
}
if ( F_6 ( V_1 , V_20 , V_119 ,
V_120 , true ) ) {
F_23 ( & V_1 -> V_71 -> V_72 , L_7 ) ;
return - 1 ;
}
if ( F_6 ( V_1 , V_20 , V_121 , V_122 , false ) ) {
F_23 ( & V_1 -> V_71 -> V_72 , L_8 ) ;
return - 1 ;
}
if ( F_6 ( V_1 , V_20 , V_121 , V_123 , false ) ) {
F_23 ( & V_1 -> V_71 -> V_72 , L_9 ) ;
return - 1 ;
}
if ( F_1 ( V_1 , V_20 , V_117 ) & V_118 ) {
F_23 ( & V_1 -> V_71 -> V_72 , L_10 ) ;
return - 1 ;
}
F_5 ( V_1 , V_20 , V_124 , V_125 ) ;
if ( F_6 ( V_1 , V_20 , V_124 ,
V_125 , false ) ) {
F_23 ( & V_1 -> V_71 -> V_72 , L_11 ) ;
return - 1 ;
}
V_60 = F_1 ( V_1 , V_20 , V_82 ) ;
V_60 &= ~ V_83 ;
F_3 ( V_1 , V_20 , V_82 , V_60 ) ;
return 0 ;
}
static void F_25 ( struct V_126 * V_127 )
{
struct V_2 * V_2 ;
T_1 V_23 ;
V_2 = F_16 ( V_127 , struct V_2 , V_128 . V_127 ) ;
F_5 ( V_2 -> V_1 , V_2 -> V_20 ,
V_124 , V_125 ) ;
F_6 ( V_2 -> V_1 , V_2 -> V_20 , V_124 ,
V_125 , false ) ;
V_23 = F_1 ( V_2 -> V_1 , V_2 -> V_20 , V_124 ) ;
if ( V_23 & V_125 ) {
V_2 -> V_24 = 1 ;
if ( V_2 -> V_1 -> V_78 == V_112 )
V_2 -> V_28 = 40000 ;
else
V_2 -> V_28 = 10000 ;
V_2 -> V_26 = 1 ;
} else {
V_2 -> V_24 = 0 ;
}
if ( V_2 -> V_50 != V_2 -> V_24 ) {
V_2 -> V_50 = V_2 -> V_24 ;
if ( V_2 -> V_24 )
F_17 ( V_2 ) ;
}
F_26 ( V_2 -> V_129 , & V_2 -> V_128 , V_130 * 2 ) ;
}
static int F_27 ( struct V_1 * V_1 , T_2 V_20 )
{
struct V_2 * V_2 ;
T_1 V_60 ;
V_2 = & V_1 -> V_2 [ V_20 ] ;
V_2 -> V_1 = V_1 ;
if ( V_1 -> V_78 == V_131 ) {
V_2 -> V_51 = 1 ;
if ( F_22 ( V_1 , V_20 ) )
return - 1 ;
} else {
V_2 -> V_51 = 0 ;
if ( F_24 ( V_1 , V_20 , V_1 -> V_78 ) )
return - 1 ;
}
if ( V_2 -> V_51 ) {
V_60 = F_1 ( V_1 , V_20 , V_68 ) ;
V_60 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_20 , V_68 , V_60 ) ;
F_3 ( V_1 , V_20 , V_132 , 60 - 1 ) ;
} else {
V_60 = F_1 ( V_1 , V_20 , V_94 ) ;
V_60 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_20 , V_94 , V_60 ) ;
F_3 ( V_1 , V_20 , V_133 , 60 + 4 ) ;
}
F_5 ( V_1 , V_20 , V_33 ,
V_34 | V_134 | V_135 ) ;
F_3 ( V_1 , V_20 , V_136 , 0x03 ) ;
if ( ( V_1 -> V_78 != V_111 ) &&
( V_1 -> V_78 != V_112 ) &&
( V_1 -> V_78 != V_103 ) &&
( V_1 -> V_78 != V_102 ) ) {
if ( ! V_2 -> V_48 )
return - V_137 ;
V_2 -> V_48 -> V_138 = 0 ;
if ( F_28 ( & V_2 -> V_46 , V_2 -> V_48 ,
F_15 ,
V_139 ) )
return - V_137 ;
F_29 ( V_2 -> V_48 ) ;
} else {
V_2 -> V_129 = F_30 ( L_12 , V_140 |
V_141 , 1 ) ;
if ( ! V_2 -> V_129 )
return - V_142 ;
F_31 ( & V_2 -> V_128 , F_25 ) ;
F_26 ( V_2 -> V_129 , & V_2 -> V_128 , 0 ) ;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_1 , T_2 V_20 )
{
struct V_2 * V_2 ;
T_1 V_143 ;
V_2 = & V_1 -> V_2 [ V_20 ] ;
if ( V_2 -> V_129 ) {
F_33 ( & V_2 -> V_128 ) ;
F_34 ( V_2 -> V_129 ) ;
F_35 ( V_2 -> V_129 ) ;
}
V_143 = F_1 ( V_1 , V_20 , V_33 ) ;
V_143 &= ~ ( 1 << 15 ) ;
F_3 ( V_1 , V_20 , V_33 , V_143 ) ;
F_20 ( V_1 , V_20 ) ;
if ( ( V_1 -> V_78 != V_111 ) &&
( V_1 -> V_78 != V_112 ) &&
( V_1 -> V_78 != V_103 ) &&
( V_1 -> V_78 != V_102 ) && V_2 -> V_48 )
F_36 ( V_2 -> V_48 ) ;
V_2 -> V_48 = NULL ;
}
static void F_37 ( struct V_1 * V_1 )
{
T_1 V_19 ;
switch ( V_1 -> V_144 ) {
case V_145 :
V_1 -> V_19 = 4 ;
V_1 -> V_78 = V_131 ;
V_1 -> V_146 = 0 ;
break;
case V_147 :
V_1 -> V_19 = 1 ;
V_1 -> V_78 = V_148 ;
V_1 -> V_146 = 0xE4 ;
break;
case V_149 :
V_1 -> V_19 = 2 ;
V_1 -> V_78 = V_81 ;
V_1 -> V_146 = 0xE4 ;
break;
case V_150 :
V_1 -> V_19 = 4 ;
V_1 -> V_78 = V_111 ;
V_1 -> V_146 = 0 ;
break;
case V_151 :
V_1 -> V_19 = 1 ;
V_1 -> V_78 = V_112 ;
V_1 -> V_146 = 0xE4 ;
break;
case V_152 :
V_1 -> V_19 = 4 ;
V_1 -> V_78 = V_102 ;
V_1 -> V_146 = 0 ;
V_1 -> V_88 = 1 ;
break;
case V_153 :
V_1 -> V_19 = 1 ;
V_1 -> V_78 = V_103 ;
V_1 -> V_146 = 0xE4 ;
V_1 -> V_88 = 1 ;
break;
default:
V_1 -> V_19 = 0 ;
break;
}
V_19 = F_1 ( V_1 , 0 , V_154 ) & 0x7 ;
if ( V_19 != 4 )
V_1 -> V_19 = V_19 ;
}
static void F_38 ( struct V_1 * V_1 )
{
int V_14 ;
F_37 ( V_1 ) ;
F_5 ( V_1 , 0 , V_155 , V_156 ) ;
if ( F_1 ( V_1 , 0 , V_157 ) )
F_23 ( & V_1 -> V_71 -> V_72 , L_13 , V_1 -> V_158 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_19 ; V_14 ++ ) {
if ( V_1 -> V_78 == V_81 ) {
if ( V_14 )
V_1 -> V_146 = 0x0e ;
else
V_1 -> V_146 = 0x04 ;
F_3 ( V_1 , V_14 , V_33 ,
( V_1 -> V_78 << 8 ) | V_1 -> V_146 ) ;
continue;
}
F_3 ( V_1 , V_14 , V_33 ,
( V_1 -> V_78 << 8 ) | ( V_1 -> V_146 + V_14 ) ) ;
V_1 -> V_2 [ V_14 ] . V_159 = V_19 ;
V_19 ++ ;
}
F_3 ( V_1 , 0 , V_160 , V_1 -> V_19 ) ;
F_3 ( V_1 , 0 , V_154 , V_1 -> V_19 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_19 ; V_14 ++ )
F_5 ( V_1 , 0 , V_161 ,
( ( 1ULL << V_162 ) - 1 ) <<
( V_14 * V_162 ) ) ;
for ( V_14 = 0 ; V_14 < V_163 ; V_14 ++ )
F_3 ( V_1 , 0 , V_57 + ( V_14 * 8 ) , 0x00 ) ;
for ( V_14 = 0 ; V_14 < V_164 ; V_14 ++ )
F_3 ( V_1 , 0 , V_165 + ( V_14 * 8 ) , 0x00 ) ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_166 * V_72 = & V_1 -> V_71 -> V_72 ;
int V_78 ;
int V_167 ;
V_78 = F_1 ( V_1 , 0 , V_33 ) ;
V_78 = ( V_78 >> 8 ) & 0x07 ;
V_167 = F_1 ( V_1 , 0 , V_92 ) &
V_93 ;
switch ( V_78 ) {
case V_131 :
V_1 -> V_144 = V_145 ;
F_40 ( V_72 , L_14 , V_1 -> V_158 ) ;
break;
case V_148 :
V_1 -> V_144 = V_147 ;
F_40 ( V_72 , L_15 , V_1 -> V_158 ) ;
break;
case V_81 :
V_1 -> V_144 = V_149 ;
F_40 ( V_72 , L_16 , V_1 -> V_158 ) ;
break;
case V_111 :
if ( ! V_167 ) {
V_1 -> V_144 = V_150 ;
F_40 ( V_72 , L_17 , V_1 -> V_158 ) ;
} else {
V_1 -> V_144 = V_152 ;
F_40 ( V_72 , L_18 , V_1 -> V_158 ) ;
}
break;
case V_112 :
if ( ! V_167 ) {
V_1 -> V_144 = V_151 ;
F_40 ( V_72 , L_19 , V_1 -> V_158 ) ;
} else {
V_1 -> V_144 = V_153 ;
F_40 ( V_72 , L_20 , V_1 -> V_158 ) ;
}
break;
default:
V_1 -> V_144 = V_145 ;
F_40 ( V_72 , L_21 , V_1 -> V_158 ) ;
}
}
static int F_41 ( struct V_168 * V_169 , T_2 * V_170 )
{
T_2 V_29 [ V_171 ] ;
int V_172 ;
V_172 = F_42 ( F_43 ( V_169 ) ,
L_22 , V_29 , V_171 ) ;
if ( V_172 )
goto V_173;
if ( ! F_44 ( V_29 ) ) {
V_172 = - V_174 ;
goto V_173;
}
memcpy ( V_170 , V_29 , V_171 ) ;
V_173:
return V_172 ;
}
static T_4 F_45 ( T_5 V_175 ,
V_6 V_176 , void * V_177 , void * * V_178 )
{
struct V_1 * V_1 = V_177 ;
struct V_168 * V_169 ;
if ( F_46 ( V_175 , & V_169 ) )
goto V_173;
F_41 ( V_169 , V_1 -> V_2 [ V_1 -> V_19 ] . V_29 ) ;
F_47 ( & V_1 -> V_2 [ V_1 -> V_19 ] . V_46 , & V_1 -> V_71 -> V_72 ) ;
V_1 -> V_2 [ V_1 -> V_19 ] . V_20 = V_1 -> V_19 ;
V_173:
V_1 -> V_19 ++ ;
return V_179 ;
}
static T_4 F_48 ( T_5 V_175 , V_6 V_176 ,
void * V_177 , void * * V_180 )
{
struct V_181 string = { V_182 , NULL } ;
struct V_1 * V_1 = V_177 ;
char V_183 [ 5 ] ;
snprintf ( V_183 , 5 , L_23 , V_1 -> V_158 ) ;
if ( F_49 ( F_50 ( V_175 , V_184 , & string ) ) ) {
F_51 ( L_24 ) ;
return V_179 ;
}
if ( strncmp ( string . V_185 , V_183 , 4 ) )
return V_179 ;
F_52 ( V_186 , V_175 , 1 ,
F_45 , NULL , V_1 , NULL ) ;
F_53 ( string . V_185 ) ;
return V_187 ;
}
static int F_54 ( struct V_1 * V_1 )
{
F_55 ( NULL , F_48 , V_1 , ( void * * ) NULL ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_1 )
{
return - V_137 ;
}
static int F_56 ( struct V_1 * V_1 )
{
struct V_188 * V_189 ;
struct V_188 * V_190 ;
T_2 V_2 = 0 ;
char V_183 [ 5 ] ;
const char * V_29 ;
snprintf ( V_183 , 5 , L_25 , V_1 -> V_158 ) ;
V_189 = F_57 ( NULL , V_183 ) ;
if ( ! V_189 )
return - V_137 ;
F_58 (np, np_child) {
struct V_188 * V_191 = F_59 ( V_190 ,
L_26 , 0 ) ;
if ( ! V_191 )
continue;
V_1 -> V_2 [ V_2 ] . V_48 = F_60 ( V_191 ) ;
V_29 = F_61 ( V_190 ) ;
if ( V_29 )
F_13 ( V_1 -> V_2 [ V_2 ] . V_29 , V_29 ) ;
F_47 ( & V_1 -> V_2 [ V_2 ] . V_46 , & V_1 -> V_71 -> V_72 ) ;
V_1 -> V_2 [ V_2 ] . V_20 = V_2 ;
V_2 ++ ;
if ( V_2 == V_192 ) {
F_62 ( V_190 ) ;
break;
}
}
return 0 ;
}
static int F_56 ( struct V_1 * V_1 )
{
return - V_137 ;
}
static int F_63 ( struct V_1 * V_1 )
{
if ( ! V_193 )
return F_54 ( V_1 ) ;
return F_56 ( V_1 ) ;
}
static int F_64 ( struct V_194 * V_71 , const struct V_195 * V_196 )
{
int V_197 ;
struct V_166 * V_72 = & V_71 -> V_72 ;
struct V_1 * V_1 = NULL ;
T_2 V_2 ;
V_1 = F_65 ( V_72 , sizeof( * V_1 ) , V_198 ) ;
if ( ! V_1 )
return - V_142 ;
V_1 -> V_71 = V_71 ;
F_66 ( V_71 , V_1 ) ;
V_197 = F_67 ( V_71 ) ;
if ( V_197 ) {
F_23 ( V_72 , L_27 ) ;
F_66 ( V_71 , NULL ) ;
return V_197 ;
}
V_197 = F_68 ( V_71 , V_199 ) ;
if ( V_197 ) {
F_23 ( V_72 , L_28 , V_197 ) ;
goto V_200;
}
V_1 -> V_5 = F_69 ( V_71 , V_201 , 0 ) ;
if ( ! V_1 -> V_5 ) {
F_23 ( V_72 , L_29 ) ;
V_197 = - V_142 ;
goto V_202;
}
V_1 -> V_158 = ( F_70 ( V_71 , V_201 ) >> 24 ) & 1 ;
V_1 -> V_158 += F_71 ( V_71 ) * V_16 ;
V_17 [ V_1 -> V_158 ] = V_1 ;
F_39 ( V_1 ) ;
V_197 = F_63 ( V_1 ) ;
if ( V_197 )
goto V_203;
F_38 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_1 -> V_19 ; V_2 ++ ) {
V_197 = F_27 ( V_1 , V_2 ) ;
if ( V_197 ) {
F_23 ( V_72 , L_30 ,
V_1 -> V_158 , V_2 ) ;
goto V_203;
}
}
return 0 ;
V_203:
V_17 [ V_1 -> V_158 ] = NULL ;
V_202:
F_72 ( V_71 ) ;
V_200:
F_73 ( V_71 ) ;
F_66 ( V_71 , NULL ) ;
return V_197 ;
}
static void F_74 ( struct V_194 * V_71 )
{
struct V_1 * V_1 = F_75 ( V_71 ) ;
T_2 V_2 ;
for ( V_2 = 0 ; V_2 < V_1 -> V_19 ; V_2 ++ )
F_32 ( V_1 , V_2 ) ;
V_17 [ V_1 -> V_158 ] = NULL ;
F_72 ( V_71 ) ;
F_73 ( V_71 ) ;
F_66 ( V_71 , NULL ) ;
}
static int T_6 F_76 ( void )
{
F_77 ( L_31 , V_199 , V_204 ) ;
return F_78 ( & V_205 ) ;
}
static void T_7 F_79 ( void )
{
F_80 ( & V_205 ) ;
}
