static void F_1 ( T_1 * V_1 , struct V_2 * V_3 , T_2 V_4 )
{
T_2 V_5 , V_6 , V_7 ;
V_6 = ( V_3 -> V_8 & V_9 ) ? 2 : 0 ;
V_7 = ( V_3 -> V_8 & V_10 ) ? 1 : 0 ;
if ( V_4 ) {
V_3 -> V_11 = V_12 ;
V_5 = 8 ;
} else {
V_3 -> V_11 = V_13 ;
if ( V_1 -> V_14 ) {
V_3 -> V_8 |= V_15 ;
V_5 = 0 ;
} else
V_5 = 4 ;
}
V_3 -> V_16 . V_17 = V_18 [ V_5 + V_6 + V_7 ] ;
}
static T_3 F_2 ( T_1 * V_1 , struct V_19 * V_20 ,
T_4 V_21 )
{
T_5 * V_22 = V_1 -> V_22 ;
T_6 V_23 = ( T_6 ) F_3 ( V_20 ) ;
T_2 V_6 = ! ! ( V_1 -> V_24 & V_25 ) ;
T_2 V_4 = ! ! ( V_1 -> V_24 & V_26 ) ;
struct V_2 V_3 ;
struct V_27 * V_16 = & V_3 . V_16 ;
T_3 V_28 ;
if ( ( V_22 -> V_29 & V_30 ) && V_6 && V_4 ) {
if ( V_21 + F_3 ( V_20 ) > 1ULL << 28 )
V_4 = 0 ;
else
V_6 = 0 ;
}
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_31 . V_32 . V_16 = V_33 | V_34 ;
V_3 . V_31 . V_35 . V_16 = V_36 | V_34 ;
if ( V_1 -> V_24 & V_37 ) {
if ( V_6 ) {
F_4 ( L_1 , V_1 -> V_38 ,
( unsigned long long ) V_21 ) ;
V_16 -> V_39 = V_23 & 0xff ;
V_16 -> V_40 = ( T_2 ) V_21 ;
V_16 -> V_41 = ( T_2 ) ( V_21 >> 8 ) ;
V_16 -> V_42 = ( T_2 ) ( V_21 >> 16 ) ;
V_16 -> V_43 = V_44 ;
V_16 = & V_3 . V_45 ;
V_16 -> V_39 = ( V_23 >> 8 ) & 0xff ;
V_16 -> V_40 = ( T_2 ) ( V_21 >> 24 ) ;
if ( sizeof( V_21 ) != 4 ) {
V_16 -> V_41 = ( T_2 ) ( ( V_46 ) V_21 >> 32 ) ;
V_16 -> V_42 = ( T_2 ) ( ( V_46 ) V_21 >> 40 ) ;
}
V_3 . V_31 . V_32 . V_45 = V_47 ;
V_3 . V_31 . V_35 . V_45 = V_48 ;
V_3 . V_8 |= V_9 ;
} else {
V_16 -> V_39 = V_23 & 0xff ;
V_16 -> V_40 = V_21 ;
V_16 -> V_41 = V_21 >>= 8 ;
V_16 -> V_42 = V_21 >>= 8 ;
V_16 -> V_43 = ( ( V_21 >> 8 ) & 0xf ) | V_44 ;
}
} else {
unsigned int V_49 , V_50 , V_51 , V_52 ;
V_52 = ( int ) V_21 / V_1 -> V_49 ;
V_49 = ( int ) V_21 % V_1 -> V_49 + 1 ;
V_50 = V_52 % V_1 -> V_50 ;
V_51 = V_52 / V_1 -> V_50 ;
F_4 ( L_2 , V_1 -> V_38 , V_51 , V_50 , V_49 ) ;
V_16 -> V_39 = V_23 & 0xff ;
V_16 -> V_40 = V_49 ;
V_16 -> V_41 = V_51 ;
V_16 -> V_42 = V_51 >> 8 ;
V_16 -> V_43 = V_50 ;
}
V_3 . V_8 |= V_53 ;
if ( F_5 ( V_20 ) )
V_3 . V_8 |= V_10 ;
F_1 ( V_1 , & V_3 , V_4 ) ;
V_3 . V_20 = V_20 ;
if ( V_4 == 0 ) {
F_6 ( & V_3 , V_23 << 9 ) ;
F_7 ( V_1 , & V_3 ) ;
}
V_28 = F_8 ( V_1 , & V_3 ) ;
if ( V_28 == V_54 && V_4 ) {
V_3 . V_8 |= V_55 ;
F_1 ( V_1 , & V_3 , 0 ) ;
F_6 ( & V_3 , V_23 << 9 ) ;
V_28 = F_8 ( V_1 , & V_3 ) ;
}
return V_28 ;
}
static T_3 F_9 ( T_1 * V_1 , struct V_19 * V_20 ,
T_4 V_21 )
{
T_5 * V_22 = V_1 -> V_22 ;
F_10 ( V_1 -> V_24 & V_56 ) ;
F_10 ( V_20 -> V_57 != V_58 ) ;
F_11 () ;
F_4 ( L_3 ,
V_1 -> V_38 , F_5 ( V_20 ) == V_59 ? L_4 : L_5 ,
( unsigned long long ) V_21 , F_3 ( V_20 ) ) ;
if ( V_22 -> V_60 )
V_22 -> V_60 ( V_1 , V_20 ) ;
return F_2 ( V_1 , V_20 , V_21 ) ;
}
static V_46 F_12 ( T_1 * V_1 , int V_6 )
{
struct V_2 V_3 ;
struct V_27 * V_16 = & V_3 . V_16 ;
V_46 V_61 = 0 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
if ( V_6 )
V_16 -> V_17 = V_62 ;
else
V_16 -> V_17 = V_63 ;
V_16 -> V_43 = V_44 ;
V_3 . V_31 . V_32 . V_16 = V_33 | V_34 ;
V_3 . V_31 . V_35 . V_16 = V_36 | V_34 ;
if ( V_6 ) {
V_3 . V_31 . V_32 . V_45 = V_47 ;
V_3 . V_31 . V_35 . V_45 = V_48 ;
V_3 . V_8 = V_9 ;
}
F_13 ( V_1 , & V_3 ) ;
if ( ! ( V_16 -> V_64 & V_65 ) )
V_61 = F_14 ( & V_3 , V_6 ) + 1 ;
return V_61 ;
}
static V_46 F_15 ( T_1 * V_1 , V_46 V_66 , int V_6 )
{
struct V_2 V_3 ;
struct V_27 * V_16 = & V_3 . V_16 ;
V_46 V_67 = 0 ;
V_66 -- ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_16 -> V_40 = ( V_66 >> 0 ) & 0xff ;
V_16 -> V_41 = ( V_66 >>= 8 ) & 0xff ;
V_16 -> V_42 = ( V_66 >>= 8 ) & 0xff ;
if ( V_6 ) {
V_3 . V_45 . V_40 = ( V_66 >>= 8 ) & 0xff ;
V_3 . V_45 . V_41 = ( V_66 >>= 8 ) & 0xff ;
V_3 . V_45 . V_42 = ( V_66 >>= 8 ) & 0xff ;
V_16 -> V_17 = V_68 ;
} else {
V_16 -> V_43 = ( V_66 >>= 8 ) & 0x0f ;
V_16 -> V_17 = V_69 ;
}
V_16 -> V_43 |= V_44 ;
V_3 . V_31 . V_32 . V_16 = V_33 | V_34 ;
V_3 . V_31 . V_35 . V_16 = V_36 | V_34 ;
if ( V_6 ) {
V_3 . V_31 . V_32 . V_45 = V_47 ;
V_3 . V_31 . V_35 . V_45 = V_48 ;
V_3 . V_8 = V_9 ;
}
F_13 ( V_1 , & V_3 ) ;
if ( ! ( V_16 -> V_64 & V_65 ) )
V_67 = F_14 ( & V_3 , V_6 ) + 1 ;
return V_67 ;
}
static unsigned long long F_16 ( unsigned long long V_70 )
{
V_70 <<= 9 ;
F_17 ( V_70 , 1000000 ) ;
return V_70 ;
}
static V_46 F_18 ( T_1 * V_1 , int V_6 )
{
V_46 V_71 , V_72 ;
V_71 = V_1 -> V_73 ;
V_72 = F_12 ( V_1 , V_6 ) ;
if ( F_19 ( V_1 -> V_74 , V_75 ) ) {
if ( V_72 == V_71 + 1 )
V_72 -- ;
}
return V_72 ;
}
static V_46 F_20 ( T_1 * V_1 , V_46 V_72 , int V_6 )
{
V_72 = F_15 ( V_1 , V_72 , V_6 ) ;
if ( V_72 )
V_1 -> V_73 = V_72 ;
return V_72 ;
}
static void F_21 ( T_1 * V_1 )
{
V_46 V_71 , V_72 ;
int V_6 = F_22 ( V_1 -> V_74 ) ;
V_71 = V_1 -> V_73 ;
V_72 = F_18 ( V_1 , V_6 ) ;
if ( V_72 <= V_71 )
return;
V_1 -> V_76 = V_72 ;
F_23 ( V_77 L_6
L_7
L_8 ,
V_1 -> V_38 ,
V_71 , F_16 ( V_71 ) ,
V_72 , F_16 ( V_72 ) ) ;
if ( ( V_1 -> V_24 & V_78 ) == 0 )
return;
V_72 = F_20 ( V_1 , V_72 , V_6 ) ;
if ( V_72 )
F_23 ( V_77 L_9 ,
V_1 -> V_38 ) ;
}
static int F_24 ( T_1 * V_1 )
{
T_6 * V_74 = V_1 -> V_74 ;
int V_79 ;
if ( F_22 ( V_74 ) ) {
V_79 = 1 ;
V_1 -> V_73 = F_25 ( V_74 , V_80 ) ;
} else if ( F_26 ( V_74 ) && F_27 ( V_74 ) ) {
V_79 = 1 ;
V_1 -> V_73 = F_28 ( V_74 , V_81 ) ;
} else {
V_79 = 0 ;
V_1 -> V_73 = V_1 -> V_51 * V_1 -> V_50 * V_1 -> V_49 ;
}
V_1 -> V_76 = V_1 -> V_73 ;
if ( V_79 ) {
V_1 -> V_24 |= V_37 ;
if ( F_29 ( V_74 ) )
F_21 ( V_1 ) ;
}
if ( ( V_1 -> V_24 & V_25 ) == 0 &&
V_1 -> V_73 > 1ULL << 28 ) {
F_23 ( V_82 L_10
L_11 ,
V_1 -> V_38 , ( unsigned long long ) V_1 -> V_73 ,
F_16 ( V_1 -> V_73 ) ) ;
V_1 -> V_76 = V_1 -> V_73 = 1ULL << 28 ;
}
if ( ( V_1 -> V_22 -> V_29 & V_30 ) &&
( V_1 -> V_24 & V_25 ) ) {
if ( V_1 -> V_73 > 1ULL << 28 ) {
F_23 ( V_77 L_12
L_13
L_14 , V_1 -> V_38 , 1 << 28 ) ;
} else
V_1 -> V_24 &= ~ V_25 ;
}
return 0 ;
}
static void F_30 ( T_1 * V_1 )
{
T_6 * V_74 = V_1 -> V_74 ;
int V_6 = F_22 ( V_74 ) ;
if ( ( V_1 -> V_24 & V_37 ) == 0 ||
F_29 ( V_74 ) == 0 )
return;
if ( ! F_18 ( V_1 , V_6 ) )
return;
if ( F_20 ( V_1 , V_1 -> V_76 , V_6 ) )
V_1 -> V_24 |= V_78 ;
}
static int F_31 ( struct V_83 * V_84 , struct V_19 * V_20 )
{
T_1 * V_1 = V_84 -> V_85 ;
struct V_2 * V_3 ;
if ( ! ( V_20 -> V_86 & V_87 ) )
return V_88 ;
if ( V_20 -> V_89 ) {
V_3 = V_20 -> V_89 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
} else {
V_3 = F_32 ( sizeof( * V_3 ) , V_90 ) ;
}
F_10 ( V_3 == NULL ) ;
if ( F_33 ( V_1 -> V_74 ) &&
( V_1 -> V_73 >= ( 1UL << 28 ) ) )
V_3 -> V_16 . V_17 = V_91 ;
else
V_3 -> V_16 . V_17 = V_92 ;
V_3 -> V_31 . V_32 . V_16 = V_33 | V_34 ;
V_3 -> V_8 = V_93 ;
V_3 -> V_11 = V_94 ;
V_20 -> V_57 = V_95 ;
V_20 -> V_89 = V_3 ;
V_3 -> V_20 = V_20 ;
return V_88 ;
}
static int F_34 ( T_1 * V_1 , int V_96 )
{
struct V_19 * V_20 ;
int error ;
if ( V_96 < 0 || V_96 > ( V_1 -> V_74 [ V_97 ] & 0xff ) )
return - V_98 ;
if ( V_1 -> V_99 & V_100 )
return - V_101 ;
V_20 = F_35 ( V_1 -> V_102 , V_59 , V_103 ) ;
V_20 -> V_57 = V_95 ;
V_1 -> V_104 = V_96 ;
V_1 -> V_99 |= V_100 ;
error = F_36 ( V_1 -> V_102 , NULL , V_20 , 0 ) ;
F_37 ( V_20 ) ;
return ( V_1 -> V_14 == V_96 ) ? 0 : - V_105 ;
}
static int F_38 ( T_1 * V_1 , int V_96 )
{
if ( V_96 < 0 || V_96 > 1 )
return - V_98 ;
if ( V_96 )
V_1 -> V_24 |= V_106 ;
else
V_1 -> V_24 &= ~ V_106 ;
V_1 -> V_107 = V_96 ? V_108 : V_109 ;
return 0 ;
}
static int F_39 ( T_1 * V_1 , T_2 V_110 , T_2 V_39 )
{
struct V_2 V_3 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_16 . V_110 = V_110 ;
V_3 . V_16 . V_39 = V_39 ;
V_3 . V_16 . V_17 = V_111 ;
V_3 . V_31 . V_32 . V_16 = V_33 | V_34 ;
V_3 . V_31 . V_35 . V_16 = V_36 | V_34 ;
return F_13 ( V_1 , & V_3 ) ;
}
static void F_40 ( T_1 * V_1 )
{
T_6 * V_74 = V_1 -> V_74 ;
bool V_112 = false ;
if ( V_1 -> V_24 & V_113 ) {
unsigned long long V_71 ;
int V_114 ;
V_71 = F_41 ( V_1 ) ;
V_114 = F_42 ( V_74 ) &&
( V_1 -> V_24 & V_115 ) == 0 &&
( ( V_1 -> V_24 & V_25 ) == 0 ||
V_71 <= ( 1ULL << 28 ) ||
F_33 ( V_74 ) ) ;
F_23 ( V_77 L_15 ,
V_1 -> V_38 , V_114 ? L_16 : L_17 ) ;
if ( V_114 ) {
V_112 = true ;
F_43 ( V_1 -> V_102 , F_31 ) ;
}
}
F_44 ( V_1 -> V_102 , V_112 , false ) ;
}
static int F_45 ( T_1 * V_1 , int V_96 )
{
int V_116 = 1 ;
if ( V_96 < 0 || V_96 > 1 )
return - V_98 ;
if ( F_42 ( V_1 -> V_74 ) ) {
V_116 = F_39 ( V_1 ,
V_96 ? V_117 : V_118 , 0 ) ;
if ( V_116 == 0 ) {
if ( V_96 )
V_1 -> V_24 |= V_113 ;
else
V_1 -> V_24 &= ~ V_113 ;
}
}
F_40 ( V_1 ) ;
return V_116 ;
}
static int F_46 ( T_1 * V_1 )
{
struct V_2 V_3 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
if ( F_33 ( V_1 -> V_74 ) )
V_3 . V_16 . V_17 = V_91 ;
else
V_3 . V_16 . V_17 = V_92 ;
V_3 . V_31 . V_32 . V_16 = V_33 | V_34 ;
V_3 . V_31 . V_35 . V_16 = V_36 | V_34 ;
return F_13 ( V_1 , & V_3 ) ;
}
static int F_47 ( T_1 * V_1 , int V_96 )
{
if ( V_96 < 0 || V_96 > 254 )
return - V_98 ;
F_39 ( V_1 ,
V_96 ? V_119 : V_120 , V_96 ) ;
V_1 -> V_121 = V_96 ;
return 0 ;
}
static int F_48 ( T_1 * V_1 , int V_96 )
{
if ( V_96 < 0 || V_96 > 2 )
return - V_98 ;
if ( V_96 && ( ( V_1 -> V_22 -> V_29 & V_122 ) ||
F_22 ( V_1 -> V_74 ) == 0 ) )
return - V_105 ;
if ( V_96 == 2 )
V_96 = 0 ;
if ( V_96 )
V_1 -> V_24 |= V_25 ;
else
V_1 -> V_24 &= ~ V_25 ;
return 0 ;
}
static int F_49 ( T_1 * V_1 , const char * V_123 )
{
return 1 ;
}
static void F_50 ( T_1 * V_1 )
{
struct V_124 * V_125 = V_1 -> V_126 ;
struct V_83 * V_84 = V_1 -> V_102 ;
T_5 * V_22 = V_1 -> V_22 ;
T_6 * V_74 = V_1 -> V_74 ;
char * V_127 = ( char * ) & V_74 [ V_128 ] ;
unsigned long long V_71 ;
F_51 ( V_1 , V_125 -> V_129 ) ;
if ( ( V_1 -> V_24 & V_130 ) == 0 )
return;
if ( V_1 -> V_24 & V_131 ) {
if ( V_127 [ 0 ] != 'W' || V_127 [ 1 ] != 'D' )
V_1 -> V_24 |= V_132 ;
}
( void ) F_48 ( V_1 , 1 ) ;
if ( V_1 -> V_24 & V_25 ) {
int V_133 = 2048 ;
if ( V_133 > V_22 -> V_134 )
V_133 = V_22 -> V_134 ;
F_52 ( V_84 , V_133 ) ;
}
F_23 ( V_77 L_18 , V_1 -> V_38 ,
F_53 ( V_84 ) / 2 ) ;
if ( F_54 ( V_74 ) ) {
F_55 ( V_135 , V_84 ) ;
F_56 ( V_136 , V_84 ) ;
}
F_24 ( V_1 ) ;
V_71 = F_41 ( V_1 ) ;
if ( ( V_1 -> V_24 & V_137 ) == 0 ) {
if ( F_22 ( V_1 -> V_74 ) ) {
V_1 -> V_138 = 63 ;
V_1 -> V_139 = 255 ;
}
if ( V_1 -> V_138 && V_1 -> V_139 ) {
unsigned int V_140 = V_71 ;
unsigned int V_141 , V_51 ;
if ( V_140 != V_71 )
V_1 -> V_142 = 65535 ;
else {
V_141 = V_1 -> V_138 * V_1 -> V_139 ;
V_51 = V_140 / V_141 ;
if ( V_51 > 65535 )
V_51 = 65535 ;
if ( V_51 > V_1 -> V_142 )
V_1 -> V_142 = V_51 ;
}
}
}
F_23 ( V_77 L_19 ,
V_1 -> V_38 , V_71 , F_16 ( V_71 ) ) ;
if ( V_74 [ V_143 ] )
F_23 ( V_144 L_20 , V_74 [ V_143 ] / 2 ) ;
F_23 ( V_144 L_21 ,
V_1 -> V_142 , V_1 -> V_139 , V_1 -> V_138 ) ;
if ( ( V_74 [ V_145 ] & 1 ) || F_57 ( V_74 ) )
V_1 -> V_24 |= V_113 ;
F_45 ( V_1 , 1 ) ;
if ( ( V_1 -> V_24 & V_37 ) == 0 &&
( V_1 -> V_50 == 0 || V_1 -> V_50 > 16 ) ) {
F_23 ( V_146 L_22 ,
V_1 -> V_38 , V_1 -> V_50 ) ;
V_1 -> V_24 &= ~ V_147 ;
} else
V_1 -> V_24 |= V_147 ;
}
static void F_58 ( T_1 * V_1 )
{
if ( F_42 ( V_1 -> V_74 ) == 0 ||
( V_1 -> V_24 & V_113 ) == 0 )
return;
if ( F_46 ( V_1 ) )
F_23 ( V_77 L_23 , V_1 -> V_38 ) ;
}
static int F_59 ( T_1 * V_1 , struct V_148 * V_149 )
{
return 0 ;
}
static int F_60 ( T_1 * V_1 , struct V_148 * V_149 ,
int V_150 )
{
struct V_2 V_3 ;
int V_151 ;
if ( ( V_1 -> V_24 & V_132 ) == 0 )
return 0 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_16 . V_17 = V_150 ? V_152 : V_153 ;
V_3 . V_31 . V_32 . V_16 = V_33 | V_34 ;
V_3 . V_31 . V_35 . V_16 = V_36 | V_34 ;
V_151 = F_13 ( V_1 , & V_3 ) ;
if ( V_151 )
V_1 -> V_24 &= ~ V_132 ;
return V_151 ;
}
