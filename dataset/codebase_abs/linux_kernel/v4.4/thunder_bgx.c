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
struct V_51 * V_52 = V_2 -> V_52 ;
int V_53 = 0 ;
if ( ! V_2 )
return;
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
F_5 ( V_1 , V_20 , V_119 , V_120 ) ;
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
if ( F_6 ( V_1 , V_20 , V_121 ,
V_122 , true ) ) {
F_24 ( & V_1 -> V_73 -> V_74 , L_7 ) ;
return - 1 ;
}
if ( F_6 ( V_1 , V_20 , V_123 , V_124 , false ) ) {
F_24 ( & V_1 -> V_73 -> V_74 , L_8 ) ;
return - 1 ;
}
if ( F_6 ( V_1 , V_20 , V_123 , V_125 , false ) ) {
F_24 ( & V_1 -> V_73 -> V_74 , L_9 ) ;
return - 1 ;
}
if ( F_1 ( V_1 , V_20 , V_119 ) & V_120 ) {
F_24 ( & V_1 -> V_73 -> V_74 , L_10 ) ;
return - 1 ;
}
F_5 ( V_1 , V_20 , V_126 , V_127 ) ;
if ( F_6 ( V_1 , V_20 , V_126 ,
V_127 , false ) ) {
F_24 ( & V_1 -> V_73 -> V_74 , L_11 ) ;
return - 1 ;
}
V_31 = F_1 ( V_1 , V_20 , V_84 ) ;
V_31 &= ~ V_85 ;
F_3 ( V_1 , V_20 , V_84 , V_31 ) ;
return 0 ;
}
static void F_26 ( struct V_128 * V_129 )
{
struct V_2 * V_2 ;
T_1 V_23 ;
V_2 = F_17 ( V_129 , struct V_2 , V_130 . V_129 ) ;
F_5 ( V_2 -> V_1 , V_2 -> V_20 ,
V_126 , V_127 ) ;
F_6 ( V_2 -> V_1 , V_2 -> V_20 , V_126 ,
V_127 , false ) ;
V_23 = F_1 ( V_2 -> V_1 , V_2 -> V_20 , V_126 ) ;
if ( V_23 & V_127 ) {
V_2 -> V_24 = 1 ;
if ( V_2 -> V_1 -> V_80 == V_114 )
V_2 -> V_28 = 40000 ;
else
V_2 -> V_28 = 10000 ;
V_2 -> V_26 = 1 ;
} else {
V_2 -> V_24 = 0 ;
V_2 -> V_28 = V_131 ;
V_2 -> V_26 = V_132 ;
}
if ( V_2 -> V_54 != V_2 -> V_24 ) {
V_2 -> V_54 = V_2 -> V_24 ;
if ( V_2 -> V_24 )
F_18 ( V_2 ) ;
}
F_27 ( V_2 -> V_133 , & V_2 -> V_130 , V_134 * 2 ) ;
}
static int F_28 ( struct V_1 * V_1 , T_2 V_20 )
{
struct V_2 * V_2 ;
T_1 V_31 ;
V_2 = & V_1 -> V_2 [ V_20 ] ;
V_2 -> V_1 = V_1 ;
if ( V_1 -> V_80 == V_135 ) {
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
F_3 ( V_1 , V_20 , V_136 , 60 - 1 ) ;
} else {
V_31 = F_1 ( V_1 , V_20 , V_96 ) ;
V_31 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_20 , V_96 , V_31 ) ;
F_3 ( V_1 , V_20 , V_137 , 60 + 4 ) ;
}
F_5 ( V_1 , V_20 , V_32 , V_38 ) ;
F_3 ( V_1 , V_20 , V_138 , 0x03 ) ;
if ( ( V_1 -> V_80 != V_113 ) &&
( V_1 -> V_80 != V_114 ) &&
( V_1 -> V_80 != V_105 ) &&
( V_1 -> V_80 != V_104 ) ) {
if ( ! V_2 -> V_52 )
return - V_139 ;
V_2 -> V_52 -> V_140 = 0 ;
if ( F_29 ( & V_2 -> V_50 , V_2 -> V_52 ,
F_16 ,
V_141 ) )
return - V_139 ;
F_30 ( V_2 -> V_52 ) ;
} else {
V_2 -> V_133 = F_31 ( L_12 , V_142 |
V_143 , 1 ) ;
if ( ! V_2 -> V_133 )
return - V_144 ;
F_32 ( & V_2 -> V_130 , F_26 ) ;
F_27 ( V_2 -> V_133 , & V_2 -> V_130 , 0 ) ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_1 , T_2 V_20 )
{
struct V_2 * V_2 ;
T_1 V_145 ;
V_2 = & V_1 -> V_2 [ V_20 ] ;
if ( V_2 -> V_133 ) {
F_34 ( & V_2 -> V_130 ) ;
F_35 ( V_2 -> V_133 ) ;
}
V_145 = F_1 ( V_1 , V_20 , V_32 ) ;
V_145 &= ~ ( 1 << 15 ) ;
F_3 ( V_1 , V_20 , V_32 , V_145 ) ;
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
switch ( V_1 -> V_146 ) {
case V_147 :
V_1 -> V_19 = 4 ;
V_1 -> V_80 = V_135 ;
V_1 -> V_148 = 0 ;
break;
case V_149 :
V_1 -> V_19 = 1 ;
V_1 -> V_80 = V_150 ;
V_1 -> V_148 = 0xE4 ;
break;
case V_151 :
V_1 -> V_19 = 2 ;
V_1 -> V_80 = V_83 ;
V_1 -> V_148 = 0xE4 ;
break;
case V_152 :
V_1 -> V_19 = 4 ;
V_1 -> V_80 = V_113 ;
V_1 -> V_148 = 0 ;
break;
case V_153 :
V_1 -> V_19 = 1 ;
V_1 -> V_80 = V_114 ;
V_1 -> V_148 = 0xE4 ;
break;
case V_154 :
V_1 -> V_19 = 4 ;
V_1 -> V_80 = V_104 ;
V_1 -> V_148 = 0 ;
V_1 -> V_90 = 1 ;
break;
case V_155 :
V_1 -> V_19 = 1 ;
V_1 -> V_80 = V_105 ;
V_1 -> V_148 = 0xE4 ;
V_1 -> V_90 = 1 ;
break;
default:
V_1 -> V_19 = 0 ;
break;
}
V_19 = F_1 ( V_1 , 0 , V_156 ) & 0x7 ;
if ( V_19 != 4 )
V_1 -> V_19 = V_19 ;
}
static void F_38 ( struct V_1 * V_1 )
{
int V_14 ;
F_37 ( V_1 ) ;
F_5 ( V_1 , 0 , V_157 , V_158 ) ;
if ( F_1 ( V_1 , 0 , V_159 ) )
F_24 ( & V_1 -> V_73 -> V_74 , L_13 , V_1 -> V_160 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_19 ; V_14 ++ ) {
if ( V_1 -> V_80 == V_83 ) {
if ( V_14 )
V_1 -> V_148 = 0x0e ;
else
V_1 -> V_148 = 0x04 ;
F_3 ( V_1 , V_14 , V_32 ,
( V_1 -> V_80 << 8 ) | V_1 -> V_148 ) ;
continue;
}
F_3 ( V_1 , V_14 , V_32 ,
( V_1 -> V_80 << 8 ) | ( V_1 -> V_148 + V_14 ) ) ;
V_1 -> V_2 [ V_14 ] . V_161 = V_19 ;
V_19 ++ ;
}
F_3 ( V_1 , 0 , V_162 , V_1 -> V_19 ) ;
F_3 ( V_1 , 0 , V_156 , V_1 -> V_19 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_19 ; V_14 ++ )
F_5 ( V_1 , 0 , V_163 ,
( ( 1ULL << V_164 ) - 1 ) <<
( V_14 * V_164 ) ) ;
for ( V_14 = 0 ; V_14 < V_165 ; V_14 ++ )
F_3 ( V_1 , 0 , V_61 + ( V_14 * 8 ) , 0x00 ) ;
for ( V_14 = 0 ; V_14 < V_166 ; V_14 ++ )
F_3 ( V_1 , 0 , V_167 + ( V_14 * 8 ) , 0x00 ) ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_168 * V_74 = & V_1 -> V_73 -> V_74 ;
int V_80 ;
int V_169 ;
V_80 = F_1 ( V_1 , 0 , V_32 ) ;
V_80 = ( V_80 >> 8 ) & 0x07 ;
V_169 = F_1 ( V_1 , 0 , V_94 ) &
V_95 ;
switch ( V_80 ) {
case V_135 :
V_1 -> V_146 = V_147 ;
F_40 ( V_74 , L_14 , V_1 -> V_160 ) ;
break;
case V_150 :
V_1 -> V_146 = V_149 ;
F_40 ( V_74 , L_15 , V_1 -> V_160 ) ;
break;
case V_83 :
V_1 -> V_146 = V_151 ;
F_40 ( V_74 , L_16 , V_1 -> V_160 ) ;
break;
case V_113 :
if ( ! V_169 ) {
V_1 -> V_146 = V_152 ;
F_40 ( V_74 , L_17 , V_1 -> V_160 ) ;
} else {
V_1 -> V_146 = V_154 ;
F_40 ( V_74 , L_18 , V_1 -> V_160 ) ;
}
break;
case V_114 :
if ( ! V_169 ) {
V_1 -> V_146 = V_153 ;
F_40 ( V_74 , L_19 , V_1 -> V_160 ) ;
} else {
V_1 -> V_146 = V_155 ;
F_40 ( V_74 , L_20 , V_1 -> V_160 ) ;
}
break;
default:
V_1 -> V_146 = V_147 ;
F_40 ( V_74 , L_21 , V_1 -> V_160 ) ;
}
}
static int F_41 ( struct V_170 * V_171 , T_2 * V_172 )
{
T_2 V_29 [ V_173 ] ;
int V_174 ;
V_174 = F_42 ( F_43 ( V_171 ) ,
L_22 , V_29 , V_173 ) ;
if ( V_174 )
goto V_175;
if ( ! F_44 ( V_29 ) ) {
V_174 = - V_176 ;
goto V_175;
}
memcpy ( V_172 , V_29 , V_173 ) ;
V_175:
return V_174 ;
}
static T_4 F_45 ( T_5 V_177 ,
V_6 V_178 , void * V_179 , void * * V_180 )
{
struct V_1 * V_1 = V_179 ;
struct V_170 * V_171 ;
if ( F_46 ( V_177 , & V_171 ) )
goto V_175;
F_41 ( V_171 , V_1 -> V_2 [ V_1 -> V_19 ] . V_29 ) ;
F_47 ( & V_1 -> V_2 [ V_1 -> V_19 ] . V_50 , & V_1 -> V_73 -> V_74 ) ;
V_1 -> V_2 [ V_1 -> V_19 ] . V_20 = V_1 -> V_19 ;
V_175:
V_1 -> V_19 ++ ;
return V_181 ;
}
static T_4 F_48 ( T_5 V_177 , V_6 V_178 ,
void * V_179 , void * * V_182 )
{
struct V_183 string = { V_184 , NULL } ;
struct V_1 * V_1 = V_179 ;
char V_185 [ 5 ] ;
snprintf ( V_185 , 5 , L_23 , V_1 -> V_160 ) ;
if ( F_49 ( F_50 ( V_177 , V_186 , & string ) ) ) {
F_51 ( L_24 ) ;
return V_181 ;
}
if ( strncmp ( string . V_187 , V_185 , 4 ) )
return V_181 ;
F_52 ( V_188 , V_177 , 1 ,
F_45 , NULL , V_1 , NULL ) ;
F_53 ( string . V_187 ) ;
return V_189 ;
}
static int F_54 ( struct V_1 * V_1 )
{
F_55 ( NULL , F_48 , V_1 , ( void * * ) NULL ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_1 )
{
return - V_139 ;
}
static int F_56 ( struct V_1 * V_1 )
{
struct V_190 * V_191 ;
struct V_190 * V_192 ;
T_2 V_2 = 0 ;
char V_185 [ 5 ] ;
const char * V_29 ;
snprintf ( V_185 , 5 , L_25 , V_1 -> V_160 ) ;
V_191 = F_57 ( NULL , V_185 ) ;
if ( ! V_191 )
return - V_139 ;
F_58 (np, np_child) {
struct V_190 * V_193 = F_59 ( V_192 ,
L_26 , 0 ) ;
if ( ! V_193 )
continue;
V_1 -> V_2 [ V_2 ] . V_52 = F_60 ( V_193 ) ;
V_29 = F_61 ( V_192 ) ;
if ( V_29 )
F_13 ( V_1 -> V_2 [ V_2 ] . V_29 , V_29 ) ;
F_47 ( & V_1 -> V_2 [ V_2 ] . V_50 , & V_1 -> V_73 -> V_74 ) ;
V_1 -> V_2 [ V_2 ] . V_20 = V_2 ;
V_2 ++ ;
if ( V_2 == V_194 ) {
F_62 ( V_192 ) ;
break;
}
}
return 0 ;
}
static int F_56 ( struct V_1 * V_1 )
{
return - V_139 ;
}
static int F_63 ( struct V_1 * V_1 )
{
if ( ! V_195 )
return F_54 ( V_1 ) ;
return F_56 ( V_1 ) ;
}
static int F_64 ( struct V_196 * V_73 , const struct V_197 * V_198 )
{
int V_199 ;
struct V_168 * V_74 = & V_73 -> V_74 ;
struct V_1 * V_1 = NULL ;
T_2 V_2 ;
F_65 () ;
V_1 = F_66 ( V_74 , sizeof( * V_1 ) , V_200 ) ;
if ( ! V_1 )
return - V_144 ;
V_1 -> V_73 = V_73 ;
F_67 ( V_73 , V_1 ) ;
V_199 = F_68 ( V_73 ) ;
if ( V_199 ) {
F_24 ( V_74 , L_27 ) ;
F_67 ( V_73 , NULL ) ;
return V_199 ;
}
V_199 = F_69 ( V_73 , V_201 ) ;
if ( V_199 ) {
F_24 ( V_74 , L_28 , V_199 ) ;
goto V_202;
}
V_1 -> V_5 = F_70 ( V_73 , V_203 , 0 ) ;
if ( ! V_1 -> V_5 ) {
F_24 ( V_74 , L_29 ) ;
V_199 = - V_144 ;
goto V_204;
}
V_1 -> V_160 = ( F_71 ( V_73 , V_203 ) >> 24 ) & 1 ;
V_1 -> V_160 += F_72 ( V_73 ) * V_16 ;
V_17 [ V_1 -> V_160 ] = V_1 ;
F_39 ( V_1 ) ;
V_199 = F_63 ( V_1 ) ;
if ( V_199 )
goto V_205;
F_38 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_1 -> V_19 ; V_2 ++ ) {
V_199 = F_28 ( V_1 , V_2 ) ;
if ( V_199 ) {
F_24 ( V_74 , L_30 ,
V_1 -> V_160 , V_2 ) ;
goto V_205;
}
}
return 0 ;
V_205:
V_17 [ V_1 -> V_160 ] = NULL ;
V_204:
F_73 ( V_73 ) ;
V_202:
F_74 ( V_73 ) ;
F_67 ( V_73 , NULL ) ;
return V_199 ;
}
static void F_75 ( struct V_196 * V_73 )
{
struct V_1 * V_1 = F_76 ( V_73 ) ;
T_2 V_2 ;
for ( V_2 = 0 ; V_2 < V_1 -> V_19 ; V_2 ++ )
F_33 ( V_1 , V_2 ) ;
V_17 [ V_1 -> V_160 ] = NULL ;
F_73 ( V_73 ) ;
F_74 ( V_73 ) ;
F_67 ( V_73 , NULL ) ;
}
static int T_6 F_77 ( void )
{
F_78 ( L_31 , V_201 , V_206 ) ;
return F_79 ( & V_207 ) ;
}
static void T_7 F_80 ( void )
{
F_81 ( & V_207 ) ;
}
