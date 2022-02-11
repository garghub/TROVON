static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
unsigned int V_5 = ( V_3 << 16 ) | V_3 ;
F_2 () ;
F_3 ( V_5 , V_2 -> V_6 + V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
F_3 ( V_3 << 16 , V_2 -> V_6 + V_4 ) ;
F_2 () ;
}
static bool F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
unsigned int V_5 ;
V_5 = F_6 ( V_2 -> V_6 + V_4 ) ;
return ( V_5 & V_3 ) ? true : false ;
}
static void F_7 ( struct V_1 * V_2 )
{
static const int V_7 = 10000 ;
int V_8 ;
F_1 ( V_2 , V_9 , V_10 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
if ( F_5 ( V_2 , V_9 , V_10 ) )
break;
F_8 ( 1 ) ;
}
if ( V_8 == V_7 )
F_9 ( V_2 -> V_11 ,
L_1 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
if ( ! ( F_6 ( V_2 -> V_6 + V_12 ) & V_13 ) )
break;
F_8 ( 1 ) ;
}
if ( V_8 == V_7 )
F_9 ( V_2 -> V_11 , L_2 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_1 V_14 )
{
F_3 ( V_15 | V_14 , V_2 -> V_6 + V_16 ) ;
F_7 ( V_2 ) ;
return F_6 ( V_2 -> V_6 + V_17 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_14 ,
T_1 V_18 )
{
F_3 ( V_19 | V_14 , V_2 -> V_6 + V_16 ) ;
F_3 ( V_18 , V_2 -> V_6 + V_17 ) ;
F_7 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_20 , unsigned int V_18 )
{
unsigned int V_5 ;
V_14 &= 0xffff ;
F_3 ( V_15 | V_14 , V_2 -> V_6 + V_16 ) ;
F_7 ( V_2 ) ;
F_3 ( V_19 | V_14 , V_2 -> V_6 + V_16 ) ;
V_5 = F_6 ( V_2 -> V_6 + V_17 ) ;
V_5 &= V_20 ;
V_5 |= V_18 ;
F_3 ( V_5 & 0xffff , V_2 -> V_6 + V_17 ) ;
F_7 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned long V_25 )
{
bool V_26 ;
V_26 = F_5 ( V_2 , V_27 , V_10 ) ;
if ( V_26 )
return 0 ;
return - V_28 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_5 )
{
unsigned int V_29 ;
int V_30 ;
F_3 ( V_5 , V_2 -> V_6 + V_31 ) ;
F_1 ( V_2 , V_27 , V_10 ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_13 , 0 ) ;
if ( V_30 )
return V_30 ;
do {
V_29 = F_6 ( V_2 -> V_6 + V_31 ) ;
} while ( ( V_29 & ( V_32 | V_33 ) ) == V_32 );
return V_29 & V_33 ;
}
static T_3 F_16 ( struct V_1 * V_2 , T_3 V_14 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
if ( F_14 ( V_2 , F_17 ( V_37 ,
V_35 -> V_38 ) |
F_18 ( V_39 , V_14 ) |
F_19 ( V_40 , 0 ) ) )
return 0 ;
if ( F_14 ( V_2 , F_17 ( V_37 ,
( V_35 -> V_38 | 1 ) ) |
F_18 ( V_39 , 0 ) |
F_19 ( V_40 , 0 ) ) )
return 0 ;
return ( F_6 ( V_2 -> V_6 + V_31 ) >> 16 ) & 0xff ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned long V_25 )
{
unsigned int V_26 ;
switch ( V_25 ) {
case V_41 :
V_26 = F_6 ( V_2 -> V_6 + V_42 ) ;
if ( ! ( V_26 & V_43 ) )
return 0 ;
break;
case V_44 :
V_26 = F_6 ( V_2 -> V_6 + V_45 ) ;
if ( V_26 & V_46 )
return 0 ;
break;
case V_47 :
V_26 = F_6 ( V_2 -> V_6 + V_48 ) ;
if ( ! ( V_26 & 0xff000000 ) )
return 0 ;
break;
case V_49 :
V_26 = F_6 ( V_2 -> V_6 + V_48 ) ;
if ( V_26 & 0xff000000 )
return 0 ;
break;
default:
return - V_50 ;
}
return - V_28 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_5 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
int V_30 ;
F_11 ( V_2 , V_51 , V_35 -> V_52 ) ;
* V_35 -> V_53 = V_5 ;
F_1 ( V_2 , V_43 , V_42 ) ;
F_3 ( V_54 , V_2 -> V_6 + V_55 ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_20 ,
V_41 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_11 , L_3 ) ;
return V_30 ;
}
F_3 ( V_56 | V_57 | V_58 ,
V_2 -> V_6 + F_22 ( 0 ) ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_20 ,
V_44 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_11 ,
L_4 ) ;
return V_30 ;
}
F_3 ( V_56 | V_59 | V_60 | V_58 | V_61 ,
V_2 -> V_6 + F_22 ( 0 ) ) ;
if ( F_6 ( V_2 -> V_6 + V_48 ) & 0xff000000 ) {
V_30 = F_15 ( V_2 , NULL , NULL , F_20 ,
V_47 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_11 ,
L_5 ) ;
return V_30 ;
}
}
F_3 ( V_57 | V_58 | V_61 ,
V_2 -> V_6 + F_22 ( 0 ) ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_20 ,
V_49 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_11 ,
L_5 ) ;
return V_30 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_1 V_62 , T_4 V_63 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_1 V_64 ;
T_2 V_65 ;
T_2 V_5 ;
V_64 = 1 << V_62 ;
if ( V_63 < 0 ) {
V_63 = - V_63 ;
V_35 -> V_52 |= V_64 ;
} else {
V_35 -> V_52 &= ~ V_64 ;
}
if ( ( T_1 ) V_63 > 0x1FFF )
V_63 = 0x1FFF ;
V_65 = ( V_62 & 2 ) ? V_66 : V_67 ;
F_3 ( V_56 | V_68 | V_65 ,
V_2 -> V_6 + F_22 ( 2 ) ) ;
F_3 ( V_56 | V_69 | V_65 ,
V_2 -> V_6 + F_22 ( 3 ) ) ;
F_3 ( V_56 | V_70 | V_71 ,
V_2 -> V_6 + F_22 ( 4 ) ) ;
F_3 ( V_56 | V_59 | V_71 | V_61 ,
V_2 -> V_6 + F_22 ( 5 ) ) ;
V_5 = 0x0F000000 ;
V_5 |= 0x00004000 ;
V_5 |= ( ( T_2 ) ( V_62 & 1 ) << 15 ) ;
V_5 |= ( T_2 ) V_63 ;
return F_21 ( V_2 , V_5 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
T_3 V_72 , T_3 V_73 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_2 V_62 ;
V_35 -> V_74 [ V_72 ] = ( T_3 ) V_73 ;
V_62 = V_75 [ V_72 ] ;
F_3 ( V_56 | V_68 | V_71 ,
V_2 -> V_6 + F_22 ( 2 ) ) ;
F_3 ( V_56 | V_69 | V_71 ,
V_2 -> V_6 + F_22 ( 3 ) ) ;
F_3 ( V_56 | V_70 | V_66 ,
V_2 -> V_6 + F_22 ( 4 ) ) ;
F_3 ( V_56 | V_59 | V_66 | V_61 ,
V_2 -> V_6 + F_22 ( 5 ) ) ;
return F_21 ( V_2 , ( V_62 << 8 ) | V_73 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_3 V_8 ;
int V_30 ;
for ( V_8 = 0 ; V_8 < F_26 ( V_75 ) ; V_8 ++ ) {
V_30 = F_24 ( V_2 , V_8 ,
F_16 ( V_2 , V_76 [ V_8 ] ) ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_77 )
{
F_12 ( V_2 , F_28 ( V_62 ) ,
~ ( V_78 | V_79 ) ,
F_29 ( V_77 ) ) ;
}
static void F_30 ( struct V_1 * V_2 ,
unsigned int V_62 , T_2 V_77 )
{
F_11 ( V_2 , F_31 ( V_62 ) , V_77 ) ;
F_11 ( V_2 , F_31 ( V_62 ) + 2 , V_77 >> 16 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
T_1 V_80 ;
V_80 = F_33 ( 1 ) ;
if ( V_62 < 3 )
V_80 |= F_34 ( 1 ) ;
else
V_80 |= F_35 ( 1 ) ;
F_12 ( V_2 , F_28 ( V_62 ) , ~ V_78 , V_80 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_81 ,
T_1 V_82 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_1 V_83 ;
T_1 V_84 ;
unsigned int V_85 , V_86 , V_87 ;
V_83 = F_37 ( F_38 ( V_81 ) ) ;
V_83 |= F_39 ( F_40 ( V_81 ) ) ;
V_84 = F_33 ( 1 ) | F_34 ( 1 ) ;
V_84 |= F_41 ( F_42 ( V_81 ) ) ;
if ( ! V_82 )
V_83 |= F_43 ( F_44 ( V_81 ) ) ;
V_87 = F_45 ( V_81 ) ;
switch ( F_46 ( V_81 ) ) {
case V_88 :
case V_89 :
V_85 = V_90 ;
V_85 |= V_87 ;
V_87 = 1 ;
V_86 = V_91 ;
break;
default:
V_85 = V_92 ;
V_86 = F_47 ( V_81 ) ;
if ( V_86 == V_93 )
V_86 = V_91 ;
break;
}
V_83 |= F_48 ( V_85 ) | F_49 ( V_87 ) |
F_50 ( V_86 ) ;
if ( F_40 ( V_81 ) != V_94 )
V_83 |= F_51 ( F_52 ( V_81 ) ) ;
if ( V_82 )
V_35 -> V_95 &= ~ ( F_53 ( V_62 ) |
F_54 ( V_62 ) ) ;
F_12 ( V_2 , F_55 ( V_62 ) ,
V_96 | V_97 , V_83 ) ;
F_12 ( V_2 , F_28 ( V_62 ) ,
~ ( V_78 | V_98 ) , V_84 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_81 ,
T_1 V_82 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_1 V_83 ;
T_1 V_84 ;
unsigned int V_85 , V_86 , V_87 ;
V_83 = F_57 ( F_40 ( V_81 ) ) ;
V_84 = F_33 ( 1 ) | F_35 ( 1 ) ;
V_84 |= F_58 ( F_42 ( V_81 ) ) ;
V_84 |= F_59 ( F_38 ( V_81 ) ) ;
if ( ! V_82 )
V_84 |= F_60 ( F_44 ( V_81 ) ) ;
V_87 = F_45 ( V_81 ) ;
switch ( F_46 ( V_81 ) ) {
case V_89 :
V_85 = V_90 ;
V_85 |= V_87 ;
V_87 = 1 ;
V_86 = V_91 ;
break;
case V_88 :
V_85 = V_90 ;
V_85 |= V_87 ;
V_87 = 1 ;
V_86 = V_93 ;
break;
default:
V_85 = V_92 ;
V_86 = F_47 ( V_81 ) ;
if ( V_86 == V_93 )
V_86 = V_91 ;
break;
}
V_83 |= F_61 ( V_85 ) ;
V_84 |= F_62 ( V_87 ) | F_63 ( V_86 ) ;
if ( F_40 ( V_81 ) != V_94 )
V_84 |= F_64 ( F_52 ( V_81 ) ) ;
if ( V_82 )
V_35 -> V_95 &= ~ ( F_53 ( V_62 ) |
F_54 ( V_62 ) ) ;
F_12 ( V_2 , F_55 ( V_62 ) ,
~ ( V_96 | V_97 ) , V_83 ) ;
F_12 ( V_2 , F_28 ( V_62 ) ,
V_98 | V_79 , V_84 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
unsigned int V_62 ,
T_1 V_81 , T_1 V_82 )
{
if ( V_62 < 3 )
F_36 ( V_2 , V_62 , V_81 , V_82 ) ;
else
F_56 ( V_2 , V_62 , V_81 , V_82 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_99 )
{
unsigned int V_20 = V_78 ;
unsigned int V_80 ;
if ( V_62 < 3 ) {
V_20 |= V_98 ;
V_80 = F_41 ( V_99 ) ;
} else {
V_20 |= V_100 ;
V_80 = F_58 ( V_99 ) ;
}
F_12 ( V_2 , F_28 ( V_62 ) , ~ V_20 , V_80 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_101 )
{
T_1 V_4 ;
T_1 V_20 ;
T_1 V_80 ;
if ( V_62 < 3 ) {
V_4 = F_55 ( V_62 ) ;
V_20 = V_102 ;
V_80 = F_37 ( V_101 ) ;
} else {
V_4 = F_28 ( V_62 ) ;
V_20 = V_103 | V_78 ;
V_80 = F_59 ( V_101 ) ;
}
F_12 ( V_2 , V_4 , ~ V_20 , V_80 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_104 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_1 V_105 = F_55 ( V_62 ) ;
T_1 V_106 = F_28 ( V_62 ) ;
if ( V_62 < 3 ) {
F_12 ( V_2 , V_106 , ~ V_78 ,
F_33 ( 1 ) |
F_34 ( 1 ) ) ;
F_12 ( V_2 , V_105 , ~ V_107 ,
F_43 ( V_104 ) ) ;
} else {
T_1 V_84 ;
V_84 = F_10 ( V_2 , V_106 ) ;
V_84 &= ~ V_78 ;
F_11 ( V_2 , V_106 ,
V_84 | F_33 ( 1 ) |
F_35 ( 1 ) ) ;
F_11 ( V_2 , V_106 ,
( V_84 & ~ V_108 ) |
F_60 ( V_104 ) ) ;
}
V_35 -> V_95 &= ~ ( F_53 ( V_62 ) |
F_54 ( V_62 ) ) ;
switch ( V_104 ) {
case 0 :
default:
break;
case 1 :
V_35 -> V_95 |= F_53 ( V_62 ) ;
break;
case 2 :
V_35 -> V_95 |= F_54 ( V_62 ) ;
break;
case 3 :
V_35 -> V_95 |= ( F_53 ( V_62 ) |
F_54 ( V_62 ) ) ;
break;
}
}
static void F_69 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
if ( V_62 < 3 ) {
T_1 V_83 ;
V_83 = F_10 ( V_2 , F_55 ( V_62 ) ) ;
F_11 ( V_2 , F_55 ( V_62 ) ,
( V_83 ^ V_109 ) ) ;
F_11 ( V_2 , F_55 ( V_62 ) , V_83 ) ;
} else {
T_1 V_84 ;
V_84 = F_10 ( V_2 , F_28 ( V_62 ) ) ;
V_84 &= ~ V_78 ;
F_11 ( V_2 , F_28 ( V_62 ) ,
( V_84 ^ V_110 ) ) ;
F_11 ( V_2 , F_28 ( V_62 ) , V_84 ) ;
}
}
static unsigned int F_70 ( unsigned int V_111 )
{
return ( ( V_111 >> 18 ) & 0x3fff ) ^ 0x2000 ;
}
static int F_71 ( struct V_1 * V_2 , unsigned int V_62 )
{
unsigned int V_112 = V_62 / 16 ;
unsigned int V_20 = 1 << ( V_62 - ( 16 * V_112 ) ) ;
unsigned int V_26 ;
V_26 = F_10 ( V_2 , F_72 ( V_112 ) ) ;
F_11 ( V_2 , F_73 ( V_112 ) , V_20 | V_26 ) ;
V_26 = F_10 ( V_2 , F_74 ( V_112 ) ) ;
F_11 ( V_2 , F_75 ( V_112 ) , V_20 | V_26 ) ;
F_11 ( V_2 , V_113 , V_114 ) ;
V_26 = F_10 ( V_2 , F_76 ( V_112 ) ) ;
F_11 ( V_2 , F_77 ( V_112 ) , V_20 | V_26 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , unsigned int V_112 ,
unsigned int V_20 )
{
F_11 ( V_2 , V_113 , V_115 ) ;
F_11 ( V_2 , F_77 ( V_112 ) , V_20 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
unsigned int V_112 ;
F_11 ( V_2 , V_113 , V_115 ) ;
for ( V_112 = 0 ; V_112 < V_116 ; V_112 ++ )
F_11 ( V_2 , F_77 ( V_112 ) , 0xffff ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 ,
T_1 V_117 , T_3 V_112 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_21 * V_22 = V_2 -> V_118 ;
struct V_119 * V_3 = & V_22 -> V_120 -> V_3 ;
F_78 ( V_2 , V_112 , V_117 ) ;
if ( V_35 -> V_121 ) {
if ( ( V_117 >> ( V_3 -> V_122 - ( 16 * V_112 ) ) ) == 1 &&
V_3 -> V_123 == V_124 ) {
F_1 ( V_2 , V_125 , V_42 ) ;
if ( V_3 -> V_126 == V_124 )
F_71 ( V_2 , V_3 -> V_127 ) ;
}
if ( ( V_117 >> ( V_3 -> V_127 - ( 16 * V_112 ) ) ) == 1 &&
V_3 -> V_126 == V_124 ) {
F_1 ( V_2 , V_128 , V_10 ) ;
if ( V_3 -> V_129 == V_124 ) {
V_35 -> V_130 = V_3 -> V_131 ;
F_71 ( V_2 , V_3 -> V_132 ) ;
}
if ( V_3 -> V_129 == V_133 ) {
V_35 -> V_130 = V_3 -> V_131 ;
F_66 ( V_2 , 5 , V_134 ) ;
}
}
if ( ( V_117 >> ( V_3 -> V_132 - ( 16 * V_112 ) ) ) == 1 &&
V_3 -> V_129 == V_124 ) {
F_1 ( V_2 , V_128 , V_10 ) ;
V_35 -> V_130 -- ;
if ( V_35 -> V_130 > 0 )
F_71 ( V_2 , V_3 -> V_132 ) ;
}
}
}
static void F_81 ( struct V_1 * V_2 )
{
T_1 V_117 ;
T_3 V_112 ;
for ( V_112 = 0 ; V_112 < V_116 ; V_112 ++ ) {
V_117 = F_10 ( V_2 , F_82 ( V_112 ) ) ;
if ( V_117 ) {
F_80 ( V_2 , V_117 , V_112 ) ;
return;
}
}
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_21 * V_22 = V_2 -> V_118 ;
struct V_135 * V_120 = V_22 -> V_120 ;
struct V_119 * V_3 = & V_120 -> V_3 ;
T_1 V_117 ;
V_117 = F_10 ( V_2 , V_136 ) ;
if ( V_117 & V_137 ) {
F_32 ( V_2 , 0 ) ;
}
if ( V_117 & V_138 ) {
F_32 ( V_2 , 1 ) ;
}
if ( V_117 & V_139 ) {
F_32 ( V_2 , 2 ) ;
}
if ( V_117 & V_140 ) {
F_32 ( V_2 , 3 ) ;
}
if ( V_117 & V_141 ) {
F_32 ( V_2 , 4 ) ;
if ( V_35 -> V_130 > 0 ) {
V_35 -> V_130 -- ;
if ( V_35 -> V_130 == 0 )
F_66 ( V_2 , 4 , V_142 ) ;
if ( V_3 -> V_129 == V_133 ) {
F_1 ( V_2 , V_128 ,
V_10 ) ;
}
}
}
if ( V_117 & V_143 ) {
F_32 ( V_2 , 5 ) ;
if ( V_3 -> V_126 == V_133 ) {
F_1 ( V_2 , V_128 , V_10 ) ;
}
if ( V_3 -> V_129 == V_133 ) {
V_35 -> V_130 = V_3 -> V_131 ;
F_66 ( V_2 , 4 , V_134 ) ;
}
}
}
static bool F_84 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_21 * V_22 = V_2 -> V_118 ;
struct V_135 * V_120 = V_22 -> V_120 ;
struct V_119 * V_3 = & V_120 -> V_3 ;
T_2 * V_144 = ( T_2 * ) V_35 -> V_145 . V_146 + 1 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_131 ; V_8 ++ ) {
unsigned short V_147 ;
V_147 = F_70 ( * V_144 ) ;
V_144 ++ ;
F_85 ( V_22 , & V_147 , 1 ) ;
}
if ( V_3 -> V_148 == V_149 && V_120 -> V_150 >= V_3 -> V_151 )
V_120 -> V_152 |= V_153 ;
if ( V_120 -> V_152 & V_154 )
V_35 -> V_121 = 0 ;
if ( V_35 -> V_121 && V_3 -> V_126 == V_124 )
F_71 ( V_2 , V_3 -> V_127 ) ;
F_86 ( V_2 , V_22 ) ;
return ! V_35 -> V_121 ;
}
static T_5 F_87 ( int V_155 , void * V_156 )
{
struct V_1 * V_2 = V_156 ;
unsigned long V_157 ;
T_2 V_158 , V_159 ;
if ( ! V_2 -> V_160 )
return V_161 ;
F_88 ( & V_2 -> V_162 , V_157 ) ;
V_159 = F_6 ( V_2 -> V_6 + V_163 ) ;
V_158 = F_6 ( V_2 -> V_6 + V_55 ) ;
F_3 ( 0 , V_2 -> V_6 + V_163 ) ;
F_3 ( V_158 , V_2 -> V_6 + V_55 ) ;
switch ( V_158 ) {
case V_164 :
if ( F_84 ( V_2 ) )
V_159 = 0 ;
break;
case V_165 :
F_81 ( V_2 ) ;
F_83 ( V_2 ) ;
break;
}
F_3 ( V_159 , V_2 -> V_6 + V_163 ) ;
F_89 ( & V_2 -> V_162 , V_157 ) ;
return V_166 ;
}
static void F_90 ( struct V_1 * V_2 , T_3 * V_167 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_21 * V_22 = V_2 -> V_118 ;
struct V_119 * V_3 = & V_22 -> V_120 -> V_3 ;
T_2 * V_168 ;
T_2 V_169 ;
T_1 V_8 ;
T_1 V_170 ;
T_2 V_171 ;
F_4 ( V_2 , V_125 , V_42 ) ;
V_168 = ( T_2 * ) V_35 -> V_172 . V_146 ;
F_3 ( ( T_2 ) V_35 -> V_172 . V_173 ,
V_2 -> V_6 + V_174 ) ;
if ( V_3 -> V_126 != V_175 ) {
* V_168 ++ = V_176 | V_177 ;
* V_168 ++ = V_178 | V_177 ;
}
* V_168 ++ = V_179 | ( V_16 >> 2 ) ;
* V_168 ++ = V_19 | V_180 ;
* V_168 ++ = V_179 | ( V_17 >> 2 ) ;
* V_168 ++ = V_181 ;
* V_168 ++ = V_178 | V_182 ;
* V_168 ++ = V_183 | V_182 ;
* V_168 ++ = V_176 | V_182 ;
for ( V_35 -> V_184 = 0 ; V_35 -> V_184 < 16 ;
V_35 -> V_184 ++ ) {
V_171 = ( * V_167 << 8 ) | ( * V_167 & 0x10 ? V_181 :
V_185 ) ;
* V_168 ++ = V_179 | ( V_16 >> 2 ) ;
* V_168 ++ = V_19 | V_180 ;
* V_168 ++ = V_179 | ( V_17 >> 2 ) ;
* V_168 ++ = V_171 ;
* V_168 ++ = V_178 | V_182 ;
* V_168 ++ = V_183 | V_182 ;
* V_168 ++ = V_176 | V_182 ;
* V_168 ++ = V_179 | ( V_16 >> 2 ) ;
* V_168 ++ = V_19 | V_186 ;
* V_168 ++ = V_179 | ( V_17 >> 2 ) ;
* V_168 ++ = V_171 ;
* V_168 ++ = V_178 | V_182 ;
* V_168 ++ = V_183 | V_182 ;
* V_168 ++ = V_176 | V_182 ;
V_169 =
( T_2 ) V_35 -> V_172 . V_173 +
( T_2 ) ( ( unsigned long ) V_168 -
( unsigned long ) V_35 ->
V_172 . V_146 ) ;
for ( V_8 = 0 ; V_8 < ( 10 * V_187 / 2 ) ; V_8 ++ ) {
V_169 += 8 ;
* V_168 ++ = V_188 ;
* V_168 ++ = V_169 ;
}
if ( V_3 -> V_129 != V_189 ) {
* V_168 ++ = V_176 | V_177 ;
* V_168 ++ = V_178 | V_177 ;
}
* V_168 ++ = V_179 | ( V_190 >> 2 ) ;
* V_168 ++ = V_191 | V_192 ;
* V_168 ++ = V_193 ;
* V_168 ++ = V_179 | ( V_190 >> 2 ) ;
* V_168 ++ = V_191 | V_194 ;
* V_168 ++ = V_176 | V_195 ;
* V_168 ++ = V_196 |
( F_91 ( V_197 ) >> 2 ) ;
* V_168 ++ = ( T_2 ) V_35 -> V_145 . V_173 +
( V_35 -> V_184 << 2 ) ;
if ( * V_167 ++ & V_198 ) {
V_35 -> V_184 ++ ;
break;
}
}
for ( V_170 = 0 ; V_170 < ( 2 * V_187 ) ; V_170 ++ )
* V_168 ++ = V_193 ;
* V_168 ++ = V_179 | ( V_190 >> 2 ) ;
* V_168 ++ = V_191 | V_192 ;
* V_168 ++ = V_193 ;
* V_168 ++ = V_179 | ( V_190 >> 2 ) ;
* V_168 ++ = V_191 | V_194 ;
* V_168 ++ = V_176 | V_195 ;
* V_168 ++ = V_196 | ( F_91 ( V_197 ) >> 2 ) ;
* V_168 ++ = ( T_2 ) V_35 -> V_145 . V_173 +
( V_35 -> V_184 << 2 ) ;
if ( V_35 -> V_121 == 1 )
* V_168 ++ = V_199 ;
* V_168 ++ = V_188 ;
* V_168 ++ = ( T_2 ) V_35 -> V_172 . V_173 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned long V_25 )
{
unsigned int V_26 ;
V_26 = F_6 ( V_2 -> V_6 + V_12 ) ;
if ( V_26 & V_200 )
return 0 ;
return - V_28 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_111 )
{
T_1 V_62 = F_94 ( V_24 -> V_201 ) ;
T_1 V_202 = F_95 ( V_24 -> V_201 ) ;
T_1 V_203 = 0 ;
T_2 V_204 ;
T_2 V_205 ;
int V_30 ;
int V_170 ;
if ( V_202 == 0 )
V_203 = ( V_62 << 8 ) | ( V_181 ) ;
else
V_203 = ( V_62 << 8 ) | ( V_185 ) ;
F_11 ( V_2 , V_180 , V_203 ) ;
F_11 ( V_2 , V_186 , V_203 ) ;
for ( V_170 = 0 ; V_170 < V_24 -> V_170 ; V_170 ++ ) {
F_8 ( 10 ) ;
V_204 = F_6 ( V_2 -> V_6 + V_190 ) ;
F_3 ( V_204 & ~ V_194 , V_2 -> V_6 + V_190 ) ;
F_3 ( V_204 & ~ V_194 , V_2 -> V_6 + V_190 ) ;
F_3 ( V_204 & ~ V_194 , V_2 -> V_6 + V_190 ) ;
F_3 ( V_204 | V_194 , V_2 -> V_6 + V_190 ) ;
V_30 = F_15 ( V_2 , V_22 , V_24 , F_92 , 0 ) ;
if ( V_30 )
return V_30 ;
if ( V_170 != 0 ) {
V_205 = F_6 ( V_2 -> V_6 + V_197 ) ;
V_111 [ V_170 - 1 ] = F_70 ( V_205 ) ;
}
F_8 ( 4 ) ;
}
V_204 = F_6 ( V_2 -> V_6 + V_190 ) ;
F_3 ( V_204 & ~ V_194 , V_2 -> V_6 + V_190 ) ;
F_3 ( V_204 & ~ V_194 , V_2 -> V_6 + V_190 ) ;
F_3 ( V_204 & ~ V_194 , V_2 -> V_6 + V_190 ) ;
F_3 ( V_204 | V_194 , V_2 -> V_6 + V_190 ) ;
V_30 = F_15 ( V_2 , V_22 , V_24 , F_92 , 0 ) ;
if ( V_30 )
return V_30 ;
if ( V_170 != 0 ) {
V_205 = F_6 ( V_2 -> V_6 + V_197 ) ;
V_111 [ V_170 - 1 ] = F_70 ( V_205 ) ;
}
return V_170 ;
}
static int F_96 ( T_3 * V_167 , struct V_119 * V_3 )
{
int V_170 ;
for ( V_170 = 0 ; V_170 < V_3 -> V_131 ; V_170 ++ ) {
if ( F_95 ( V_3 -> V_206 [ V_170 ] ) == 0 )
V_167 [ V_170 ] = F_94 ( V_3 -> V_206 [ V_170 ] ) | V_207 ;
else
V_167 [ V_170 ] = F_94 ( V_3 -> V_206 [ V_170 ] ) | V_208 ;
}
if ( V_170 != 0 )
V_167 [ V_170 - 1 ] |= V_198 ;
return V_170 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
unsigned int V_209 )
{
struct V_119 * V_3 = & V_22 -> V_120 -> V_3 ;
if ( V_209 != V_3 -> V_122 )
return - V_50 ;
F_1 ( V_2 , V_125 , V_42 ) ;
V_22 -> V_120 -> V_210 = NULL ;
return 1 ;
}
static int F_98 ( unsigned int * V_211 , unsigned int V_157 )
{
int V_212 , V_213 ;
V_213 = 500 ;
switch ( V_157 & V_214 ) {
case V_215 :
default:
V_212 = F_99 ( * V_211 , V_213 ) ;
break;
case V_216 :
V_212 = ( * V_211 ) / V_213 ;
break;
case V_217 :
V_212 = F_100 ( * V_211 , V_213 ) ;
break;
}
* V_211 = V_213 * V_212 ;
return V_212 - 1 ;
}
static void F_101 ( struct V_1 * V_2 ,
unsigned int V_62 , int V_218 )
{
T_1 V_81 =
F_102 ( V_219 ) |
F_103 ( V_94 ) |
F_104 ( V_89 ) |
F_105 ( V_220 ) |
F_106 ( V_91 ) |
F_107 ( V_142 ) ;
T_1 V_221 = V_222 ;
F_65 ( V_2 , V_62 , V_81 , false ) ;
F_30 ( V_2 , V_62 , V_218 ) ;
F_67 ( V_2 , V_62 , 0 ) ;
F_69 ( V_2 , V_62 ) ;
F_67 ( V_2 , V_62 , 1 ) ;
F_68 ( V_2 , V_62 , V_223 ) ;
F_27 ( V_2 , V_62 , V_221 ) ;
}
static int F_108 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_3 V_167 [ 16 ] ;
struct V_119 * V_3 = & V_22 -> V_120 -> V_3 ;
int V_218 ;
if ( V_35 -> V_121 ) {
F_9 ( V_2 -> V_11 ,
L_6 ) ;
return - V_28 ;
}
F_3 ( 0 , V_2 -> V_6 + V_163 ) ;
F_3 ( V_164 | V_165 , V_2 -> V_6 + V_55 ) ;
F_79 ( V_2 ) ;
V_35 -> V_121 = 0 ;
F_96 ( V_167 , V_3 ) ;
V_35 -> V_121 = 1 ;
V_35 -> V_130 = 0 ;
switch ( V_3 -> V_126 ) {
case V_175 :
break;
case V_133 :
V_218 = F_98 ( & V_3 -> V_127 , V_3 -> V_157 ) ;
F_101 ( V_2 , 5 , V_218 ) ;
F_66 ( V_2 , 5 , V_134 ) ;
break;
case V_124 :
if ( V_3 -> V_123 != V_124 )
F_71 ( V_2 , V_3 -> V_127 ) ;
break;
}
switch ( V_3 -> V_129 ) {
case V_189 :
break;
case V_133 :
V_218 = F_98 ( & V_3 -> V_132 , V_3 -> V_157 ) ;
F_101 ( V_2 , 4 , V_218 ) ;
F_66 ( V_2 , 4 , V_142 ) ;
break;
case V_124 :
if ( V_3 -> V_126 != V_124 &&
V_3 -> V_123 == V_124 )
F_71 ( V_2 , V_3 -> V_132 ) ;
break;
}
F_90 ( V_2 , V_167 ) ;
switch ( V_3 -> V_123 ) {
case V_189 :
F_1 ( V_2 , V_125 , V_42 ) ;
V_22 -> V_120 -> V_210 = NULL ;
break;
case V_124 :
F_71 ( V_2 , V_3 -> V_122 ) ;
V_22 -> V_120 -> V_210 = NULL ;
break;
case V_224 :
V_22 -> V_120 -> V_210 = F_97 ;
break;
}
F_3 ( V_165 | V_164 , V_2 -> V_6 + V_163 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_21 * V_22 , struct V_119 * V_3 )
{
int V_225 = 0 ;
unsigned int V_226 ;
V_225 |= F_110 ( & V_3 -> V_123 ,
V_189 | V_224 | V_124 ) ;
V_225 |= F_110 ( & V_3 -> V_126 ,
V_133 | V_124 | V_175 ) ;
V_225 |= F_110 ( & V_3 -> V_129 ,
V_133 | V_124 | V_189 ) ;
V_225 |= F_110 ( & V_3 -> V_227 , V_149 ) ;
V_225 |= F_110 ( & V_3 -> V_148 , V_149 | V_228 ) ;
if ( V_225 )
return 1 ;
V_225 |= F_111 ( V_3 -> V_123 ) ;
V_225 |= F_111 ( V_3 -> V_126 ) ;
V_225 |= F_111 ( V_3 -> V_129 ) ;
V_225 |= F_111 ( V_3 -> V_148 ) ;
if ( V_225 )
return 2 ;
switch ( V_3 -> V_123 ) {
case V_189 :
case V_224 :
V_225 |= F_112 ( & V_3 -> V_122 , 0 ) ;
break;
case V_124 :
V_225 |= F_113 ( & V_3 -> V_122 , 39 ) ;
break;
}
if ( V_3 -> V_126 == V_124 )
V_225 |= F_113 ( & V_3 -> V_127 , 39 ) ;
if ( V_3 -> V_129 == V_124 )
V_225 |= F_113 ( & V_3 -> V_132 , 39 ) ;
#define F_114 200000
#define F_115 2000000000
if ( V_3 -> V_126 == V_133 ) {
V_225 |= F_116 ( & V_3 -> V_127 ,
F_114 ) ;
V_225 |= F_113 ( & V_3 -> V_127 ,
F_115 ) ;
} else {
}
if ( V_3 -> V_129 == V_133 ) {
V_225 |= F_116 ( & V_3 -> V_132 ,
F_114 ) ;
V_225 |= F_113 ( & V_3 -> V_132 ,
F_115 ) ;
} else {
}
V_225 |= F_112 ( & V_3 -> V_229 ,
V_3 -> V_131 ) ;
if ( V_3 -> V_148 == V_149 )
V_225 |= F_116 ( & V_3 -> V_151 , 1 ) ;
else
V_225 |= F_112 ( & V_3 -> V_151 , 0 ) ;
if ( V_225 )
return 3 ;
if ( V_3 -> V_126 == V_133 ) {
V_226 = V_3 -> V_127 ;
F_98 ( & V_226 , V_3 -> V_157 ) ;
V_225 |= F_112 ( & V_3 -> V_127 , V_226 ) ;
}
if ( V_3 -> V_129 == V_133 ) {
V_226 = V_3 -> V_132 ;
F_98 ( & V_226 , V_3 -> V_157 ) ;
V_225 |= F_112 ( & V_3 -> V_132 , V_226 ) ;
if ( V_3 -> V_126 == V_133 ) {
V_226 = V_3 -> V_132 * V_3 -> V_229 ;
V_225 |= F_116 ( & V_3 ->
V_127 ,
V_226 ) ;
}
}
if ( V_225 )
return 4 ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
F_4 ( V_2 , V_125 , V_42 ) ;
F_3 ( 0 , V_2 -> V_6 + V_163 ) ;
V_35 -> V_121 = 0 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_111 )
{
unsigned int V_62 = F_94 ( V_24 -> V_201 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 -> V_170 ; V_8 ++ ) {
T_4 V_63 = ( T_4 ) V_111 [ V_8 ] ;
int V_30 ;
V_63 -= ( 0x1fff ) ;
V_30 = F_23 ( V_2 , V_62 , V_63 ) ;
if ( V_30 )
return V_30 ;
V_22 -> V_230 [ V_62 ] = V_111 [ V_8 ] ;
}
return V_24 -> V_170 ;
}
static void F_119 ( struct V_1 * V_2 )
{
T_1 V_112 ;
F_11 ( V_2 , V_113 , V_115 ) ;
for ( V_112 = 0 ; V_112 < V_116 ; V_112 ++ ) {
F_11 ( V_2 , F_75 ( V_112 ) , 0 ) ;
F_11 ( V_2 , F_77 ( V_112 ) , 0xffff ) ;
F_11 ( V_2 , F_73 ( V_112 ) , 0 ) ;
F_11 ( V_2 , F_120 ( V_112 ) , 0 ) ;
}
}
static int F_121 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_111 )
{
unsigned long V_112 = ( unsigned long ) V_22 -> V_36 ;
if ( F_122 ( V_22 , V_111 ) )
F_11 ( V_2 , F_120 ( V_112 ) , V_22 -> V_231 ) ;
V_111 [ 1 ] = F_10 ( V_2 , F_123 ( V_112 ) ) ;
return V_24 -> V_170 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_111 )
{
unsigned long V_112 = ( unsigned long ) V_22 -> V_36 ;
int V_30 ;
V_30 = F_125 ( V_2 , V_22 , V_24 , V_111 , 0 ) ;
if ( V_30 )
return V_30 ;
F_11 ( V_2 , F_120 ( V_112 ) , V_22 -> V_232 ) ;
return V_24 -> V_170 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_111 )
{
unsigned int V_62 = F_94 ( V_24 -> V_201 ) ;
T_1 V_81 =
F_102 ( V_219 ) |
F_103 ( V_94 ) |
F_104 ( V_233 ) |
F_105 ( V_234 ) |
F_106 ( V_91 ) |
F_107 ( V_142 ) ;
T_1 V_221 = V_235 ;
T_1 V_99 = V_134 ;
F_65 ( V_2 , V_62 , V_81 , true ) ;
F_30 ( V_2 , V_62 , V_111 [ 0 ] ) ;
F_69 ( V_2 , V_62 ) ;
F_27 ( V_2 , V_62 , V_221 ) ;
F_66 ( V_2 , V_62 , ( V_99 != 0 ) ) ;
return V_24 -> V_170 ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_111 )
{
unsigned int V_62 = F_94 ( V_24 -> V_201 ) ;
T_1 V_236 = F_31 ( V_62 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 -> V_170 ; V_8 ++ ) {
unsigned int V_5 ;
V_5 = F_10 ( V_2 , V_236 ) ;
V_5 |= ( F_10 ( V_2 , V_236 + 2 ) << 16 ) ;
V_111 [ V_8 ] = V_5 ;
}
return V_24 -> V_170 ;
}
static int F_128 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_111 )
{
unsigned int V_62 = F_94 ( V_24 -> V_201 ) ;
F_30 ( V_2 , V_62 , V_111 [ 0 ] ) ;
F_67 ( V_2 , V_62 , 0 ) ;
F_69 ( V_2 , V_62 ) ;
F_67 ( V_2 , V_62 , 2 ) ;
return 1 ;
}
static void F_129 ( struct V_1 * V_2 , T_1 V_237 )
{
F_11 ( V_2 , V_113 , V_238 ) ;
F_11 ( V_2 , V_239 , V_237 ) ;
F_11 ( V_2 , V_113 , V_240 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
int V_62 ;
T_1 V_81 =
F_102 ( V_219 ) |
F_103 ( V_94 ) |
F_104 ( V_233 ) |
F_105 ( V_234 ) |
F_106 ( V_91 ) |
F_107 ( V_142 ) ;
for ( V_62 = 0 ; V_62 < V_241 ; V_62 ++ ) {
F_65 ( V_2 , V_62 , V_81 , true ) ;
F_68 ( V_2 , V_62 , 0 ) ;
F_32 ( V_2 , V_62 ) ;
F_66 ( V_2 , V_62 , V_134 ) ;
}
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_242 * V_243 = F_132 ( V_2 ) ;
struct V_34 * V_35 = V_2 -> V_36 ;
void * V_14 ;
T_6 V_244 ;
V_14 = F_133 ( V_243 , V_245 , & V_244 ) ;
if ( ! V_14 )
return - V_246 ;
V_35 -> V_145 . V_146 = V_14 ;
V_35 -> V_145 . V_173 = V_244 ;
V_14 = F_133 ( V_243 , V_245 , & V_244 ) ;
if ( ! V_14 )
return - V_246 ;
V_35 -> V_172 . V_146 = V_14 ;
V_35 -> V_172 . V_173 = V_244 ;
return 0 ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_242 * V_243 = F_132 ( V_2 ) ;
struct V_34 * V_35 = V_2 -> V_36 ;
if ( ! V_35 )
return;
if ( V_35 -> V_172 . V_146 )
F_135 ( V_243 , V_245 ,
V_35 -> V_172 . V_146 ,
V_35 -> V_172 . V_173 ) ;
if ( V_35 -> V_145 . V_146 )
F_135 ( V_243 , V_245 ,
V_35 -> V_145 . V_146 ,
V_35 -> V_145 . V_173 ) ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_6 V_247 ;
T_1 V_62 ;
int V_8 ;
int V_30 ;
F_1 ( V_2 , V_248 | V_249 | V_250 ,
V_42 ) ;
F_3 ( V_251 |
( V_252 << V_253 ) | V_254 |
V_255 , V_2 -> V_6 + V_256 ) ;
F_3 ( V_257 , V_2 -> V_6 + V_258 ) ;
F_3 ( V_191 | V_194 , V_2 -> V_6 + V_190 ) ;
V_35 -> V_38 = 0xA0 ;
F_3 ( V_259 | V_260 ,
V_2 -> V_6 + V_261 ) ;
F_1 ( V_2 , V_27 , V_10 ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_13 , 0 ) ;
if ( V_30 )
return V_30 ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
F_3 ( V_259 , V_2 -> V_6 + V_261 ) ;
F_1 ( V_2 , V_27 , V_10 ) ;
V_30 = F_15 ( V_2 , NULL ,
NULL , F_13 , 0 ) ;
if ( V_30 )
return V_30 ;
}
F_3 ( V_262 , V_2 -> V_6 + V_263 ) ;
F_3 ( V_264 | V_265 , V_2 -> V_6 + V_266 ) ;
F_3 ( V_264 | V_265 | V_61 ,
V_2 -> V_6 + V_266 + 4 ) ;
F_3 ( V_267 , V_2 -> V_6 + V_268 ) ;
F_3 ( ( T_2 ) V_35 -> V_172 . V_173 ,
V_2 -> V_6 + V_174 ) ;
F_3 ( 0 , V_2 -> V_6 + V_269 ) ;
F_3 ( 0 , V_2 -> V_6 + V_270 ) ;
#if 0
{
struct comedi_subdevice *s = dev->read_subdev;
uint8_t poll_list;
uint16_t adc_data;
uint16_t start_val;
uint16_t index;
unsigned int data[16];
poll_list = S626_EOPL;
s626_reset_adc(dev, &poll_list);
s626_ai_rinsn(dev, s, NULL, data);
start_val = data[0];
for (index = 0; index < 500; index++) {
s626_ai_rinsn(dev, s, NULL, data);
adc_data = data[0];
if (adc_data != start_val)
break;
}
}
#endif
F_3 ( 0 , V_2 -> V_6 + V_271 ) ;
V_247 = V_35 -> V_145 . V_173 +
( V_272 * sizeof( T_2 ) ) ;
F_3 ( ( T_2 ) V_247 , V_2 -> V_6 + V_273 ) ;
F_3 ( ( T_2 ) ( V_247 + sizeof( T_2 ) ) ,
V_2 -> V_6 + V_274 ) ;
V_35 -> V_53 = ( T_2 * ) V_35 -> V_145 . V_146 +
V_272 ;
F_3 ( 8 , V_2 -> V_6 + V_275 ) ;
F_3 ( V_56 | V_57 | V_58 | V_61 ,
V_2 -> V_6 + F_22 ( 0 ) ) ;
F_3 ( V_276 , V_2 -> V_6 + F_22 ( 1 ) ) ;
F_3 ( V_277 , V_2 -> V_6 + V_268 ) ;
F_25 ( V_2 ) ;
V_30 = F_25 ( V_2 ) ;
if ( V_30 )
return V_30 ;
for ( V_62 = 0 ; V_62 < V_278 ; V_62 ++ ) {
V_30 = F_23 ( V_2 , V_62 , 0 ) ;
if ( V_30 )
return V_30 ;
}
F_130 ( V_2 ) ;
F_129 ( V_2 , ( F_10 ( V_2 , V_136 ) &
V_279 ) ) ;
F_119 ( V_2 ) ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 ,
unsigned long V_280 )
{
struct V_242 * V_243 = F_132 ( V_2 ) ;
struct V_34 * V_35 ;
struct V_21 * V_22 ;
int V_30 ;
V_35 = F_138 ( V_2 , sizeof( * V_35 ) ) ;
if ( ! V_35 )
return - V_246 ;
V_30 = F_139 ( V_2 ) ;
if ( V_30 )
return V_30 ;
V_2 -> V_6 = F_140 ( V_243 , 0 ) ;
if ( ! V_2 -> V_6 )
return - V_246 ;
F_3 ( 0 , V_2 -> V_6 + V_163 ) ;
F_3 ( V_281 , V_2 -> V_6 + V_42 ) ;
V_30 = F_131 ( V_2 ) ;
if ( V_30 )
return V_30 ;
if ( V_243 -> V_155 ) {
V_30 = F_141 ( V_243 -> V_155 , F_87 , V_282 ,
V_2 -> V_283 , V_2 ) ;
if ( V_30 == 0 )
V_2 -> V_155 = V_243 -> V_155 ;
}
V_30 = F_142 ( V_2 , 6 ) ;
if ( V_30 )
return V_30 ;
V_22 = & V_2 -> V_284 [ 0 ] ;
V_22 -> type = V_285 ;
V_22 -> V_286 = V_287 | V_288 ;
V_22 -> V_289 = V_290 ;
V_22 -> V_291 = 0x3fff ;
V_22 -> V_292 = & V_293 ;
V_22 -> V_294 = V_290 ;
V_22 -> V_295 = F_93 ;
if ( V_2 -> V_155 ) {
V_2 -> V_118 = V_22 ;
V_22 -> V_286 |= V_296 ;
V_22 -> V_297 = F_108 ;
V_22 -> V_298 = F_109 ;
V_22 -> V_299 = F_117 ;
}
V_22 = & V_2 -> V_284 [ 1 ] ;
V_22 -> type = V_300 ;
V_22 -> V_286 = V_301 | V_287 ;
V_22 -> V_289 = V_278 ;
V_22 -> V_291 = 0x3fff ;
V_22 -> V_292 = & V_302 ;
V_22 -> V_303 = F_118 ;
V_30 = F_143 ( V_22 ) ;
if ( V_30 )
return V_30 ;
V_22 = & V_2 -> V_284 [ 2 ] ;
V_22 -> type = V_304 ;
V_22 -> V_286 = V_301 | V_287 ;
V_22 -> V_289 = 16 ;
V_22 -> V_291 = 1 ;
V_22 -> V_232 = 0xffff ;
V_22 -> V_36 = ( void * ) 0 ;
V_22 -> V_292 = & V_305 ;
V_22 -> V_306 = F_124 ;
V_22 -> V_307 = F_121 ;
V_22 = & V_2 -> V_284 [ 3 ] ;
V_22 -> type = V_304 ;
V_22 -> V_286 = V_301 | V_287 ;
V_22 -> V_289 = 16 ;
V_22 -> V_291 = 1 ;
V_22 -> V_232 = 0xffff ;
V_22 -> V_36 = ( void * ) 1 ;
V_22 -> V_292 = & V_305 ;
V_22 -> V_306 = F_124 ;
V_22 -> V_307 = F_121 ;
V_22 = & V_2 -> V_284 [ 4 ] ;
V_22 -> type = V_304 ;
V_22 -> V_286 = V_301 | V_287 ;
V_22 -> V_289 = 16 ;
V_22 -> V_291 = 1 ;
V_22 -> V_232 = 0xffff ;
V_22 -> V_36 = ( void * ) 2 ;
V_22 -> V_292 = & V_305 ;
V_22 -> V_306 = F_124 ;
V_22 -> V_307 = F_121 ;
V_22 = & V_2 -> V_284 [ 5 ] ;
V_22 -> type = V_308 ;
V_22 -> V_286 = V_301 | V_287 | V_309 ;
V_22 -> V_289 = V_241 ;
V_22 -> V_291 = 0xffffff ;
V_22 -> V_292 = & V_310 ;
V_22 -> V_306 = F_126 ;
V_22 -> V_295 = F_127 ;
V_22 -> V_303 = F_128 ;
return F_136 ( V_2 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
if ( V_35 ) {
V_35 -> V_121 = 0 ;
if ( V_2 -> V_6 ) {
F_3 ( 0 , V_2 -> V_6 + V_163 ) ;
F_3 ( V_165 | V_164 ,
V_2 -> V_6 + V_55 ) ;
F_129 ( V_2 , 0 ) ;
F_3 ( V_311 , V_2 -> V_6 + V_42 ) ;
F_3 ( V_312 , V_2 -> V_6 + V_268 ) ;
}
}
F_145 ( V_2 ) ;
F_134 ( V_2 ) ;
}
static int F_146 ( struct V_242 * V_2 ,
const struct V_313 * V_314 )
{
return F_147 ( V_2 , & V_315 , V_314 -> V_316 ) ;
}
