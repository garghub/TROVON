static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
if ( ! V_2 -> V_10 )
return;
F_3 ( V_11 + V_12 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
F_3 ( V_11 + V_14 , V_3 -> V_15 [ V_9 ] ) ;
F_3 ( V_11 + V_14 , V_3 -> V_16 [ V_9 ] ) ;
F_3 ( V_11 + V_14 , V_3 -> V_17 [ V_9 ] ) ;
}
}
static inline void F_4 ( struct V_6 * V_7 )
{
unsigned long V_18 = V_19 + V_20 / 10 ;
unsigned int V_21 = 0 ;
do {
V_21 = F_5 ( V_22 ) ;
} while ( ( V_21 & 0x08 ) && F_6 ( V_19 , V_18 ) );
V_18 = V_19 + V_20 / 10 ;
V_21 = 0 ;
do {
V_21 = F_5 ( V_22 ) ;
} while ( ! ( V_21 & 0x08 ) && F_6 ( V_19 , V_18 ) );
}
static inline void F_7 ( struct V_6 * V_7 )
{
unsigned long V_18 = V_19 + V_20 ;
unsigned int V_21 = 0 ;
do {
V_21 = F_8 ( V_22 + 2 ) ;
} while ( ( V_21 & 0x01 ) && F_6 ( V_19 , V_18 ) );
}
static bool F_9 ( struct V_1 * V_2 ,
const struct V_23 * V_24 ,
struct V_23 * V_25 )
{
return true ;
}
static int F_10 ( struct V_6 * V_7 , long clock )
{
unsigned int V_26 , V_27 , V_28 ;
unsigned int V_29 , V_30 , V_31 ;
unsigned int V_32 , V_33 , V_34 ;
unsigned int V_35 , V_36 , V_37 ;
unsigned int V_38 ;
V_36 = V_37 = V_35 = 0 ;
V_26 = 320000 ;
V_27 = 160000 ;
V_28 = 25000 ;
V_29 = 0xffffffff ;
V_31 = clock * 5 / 1000 ;
for ( V_32 = 8 ; V_32 > 0 ; V_32 /= 2 ) {
if ( clock * V_32 > V_26 )
continue;
if ( clock * V_32 < V_27 )
continue;
for ( V_34 = 17 ; V_34 < 256 ; V_34 ++ ) {
for ( V_33 = 1 ; V_33 < 32 ; V_33 ++ ) {
V_38 = ( V_28 * V_34 ) /
( V_33 * V_32 ) ;
if ( V_38 > clock )
V_30 = V_38 - clock ;
else
V_30 = clock - V_38 ;
if ( V_30 < V_29 ) {
V_29 = V_30 ;
V_36 = V_33 - 1 ;
V_37 = V_34 - 1 ;
V_35 = V_32 - 1 ;
}
}
}
}
if ( V_29 > V_31 ) {
F_11 ( V_39 L_1 ) ;
return 1 ;
}
F_12 ( V_40 , V_36 ) ;
F_12 ( V_41 , V_37 ) ;
F_12 ( V_42 , V_35 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , long clock )
{
unsigned int V_26 , V_27 , V_28 ;
unsigned int V_29 , V_30 , V_31 ;
unsigned int V_32 , V_33 , V_34 ;
unsigned int V_35 , V_36 , V_37 ;
unsigned int V_38 ;
int V_9 , V_43 , V_44 , V_45 ;
bool V_46 = false ;
T_1 V_47 ;
V_36 = V_37 = V_35 = 0 ;
V_26 = 550000 ;
V_27 = 150000 ;
V_28 = 48000 ;
V_29 = 0xffffffff ;
V_31 = clock * 5 / 1000 ;
for ( V_32 = 1 ; V_32 < 9 ; V_32 ++ ) {
if ( clock * V_32 > V_26 )
continue;
if ( clock * V_32 < V_27 )
continue;
for ( V_33 = 1 ; V_33 < 17 ; V_33 ++ ) {
for ( V_34 = 1 ; V_34 < 151 ; V_34 ++ ) {
V_38 = ( V_28 * V_34 ) /
( V_33 * V_32 ) ;
if ( V_38 > clock )
V_30 = V_38 - clock ;
else
V_30 = clock - V_38 ;
if ( V_30 < V_29 ) {
V_29 = V_30 ;
V_37 = V_34 - 1 ;
V_36 = ( V_33 - 1 ) | ( ( V_37 >> 1 ) & 0x80 ) ;
V_35 = V_32 - 1 ;
}
}
}
}
for ( V_9 = 0 ; V_9 <= 32 && V_46 == false ; V_9 ++ ) {
if ( V_9 > 0 ) {
F_3 ( V_48 , 0x1e ) ;
V_47 = F_8 ( V_49 ) ;
if ( V_47 < 0xff )
F_3 ( V_49 , V_47 + 1 ) ;
}
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= V_52 ;
F_3 ( V_51 , V_47 ) ;
F_3 ( V_11 , V_53 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= V_54 ;
F_3 ( V_51 , V_47 ) ;
V_47 = F_8 ( V_55 ) ;
V_47 |= 0x3 << 2 ;
F_3 ( V_56 , V_47 ) ;
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= V_57 | 0x80 ;
F_3 ( V_51 , V_47 ) ;
F_14 ( 500 ) ;
F_3 ( V_11 , V_58 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ 0x04 ;
F_3 ( V_51 , V_47 ) ;
F_14 ( 50 ) ;
F_12 ( V_59 , V_37 ) ;
F_12 ( V_60 , V_36 ) ;
F_12 ( V_61 , V_35 ) ;
F_14 ( 50 ) ;
F_3 ( V_11 , V_58 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= 0x04 ;
F_12 ( V_58 , V_47 ) ;
F_14 ( 500 ) ;
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ V_62 ;
V_47 |= V_63 ;
F_3 ( V_51 , V_47 ) ;
F_3 ( V_11 , V_53 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ V_64 ;
V_47 |= V_65 ;
F_3 ( V_51 , V_47 ) ;
F_3 ( V_66 , 1 ) ;
V_47 = F_8 ( V_67 ) ;
V_47 &= ~ 0x8 ;
F_3 ( V_67 , V_47 ) ;
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ V_52 ;
F_3 ( V_51 , V_47 ) ;
V_45 = F_8 ( V_68 ) ;
for ( V_43 = 0 ; V_43 < 30 && V_46 == false ; V_43 ++ ) {
V_44 = F_8 ( V_68 ) ;
if ( V_44 < V_45 )
V_45 = 0 ;
if ( ( V_44 - V_45 ) > 2 )
V_46 = true ;
else
F_14 ( 5 ) ;
}
}
F_3 ( V_11 , V_53 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ V_54 ;
F_12 ( V_53 , V_47 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , long clock )
{
unsigned int V_26 , V_27 , V_28 ;
unsigned int V_29 , V_30 , V_31 ;
unsigned int V_32 , V_33 , V_34 ;
unsigned int V_35 , V_36 , V_37 ;
unsigned int V_38 ;
T_1 V_47 ;
V_36 = V_37 = V_35 = 0 ;
V_26 = 550000 ;
V_27 = 150000 ;
V_28 = 50000 ;
V_29 = 0xffffffff ;
V_31 = clock * 5 / 1000 ;
for ( V_32 = 16 ; V_32 > 0 ; V_32 -- ) {
if ( clock * V_32 > V_26 )
continue;
if ( clock * V_32 < V_27 )
continue;
for ( V_34 = 1 ; V_34 < 257 ; V_34 ++ ) {
for ( V_33 = 1 ; V_33 < 17 ; V_33 ++ ) {
V_38 = ( V_28 * V_34 ) /
( V_33 * V_32 ) ;
if ( V_38 > clock )
V_30 = V_38 - clock ;
else
V_30 = clock - V_38 ;
if ( V_30 < V_29 ) {
V_29 = V_30 ;
V_37 = V_34 - 1 ;
V_36 = V_33 - 1 ;
V_35 = V_32 - 1 ;
}
}
}
}
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= V_52 ;
F_3 ( V_51 , V_47 ) ;
V_47 = F_8 ( V_55 ) ;
V_47 |= 0x3 << 2 ;
F_3 ( V_56 , V_47 ) ;
F_3 ( V_11 , V_69 ) ;
V_47 = F_8 ( V_51 ) ;
F_3 ( V_51 , V_47 & ~ 0x40 ) ;
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= V_57 ;
F_3 ( V_51 , V_47 ) ;
F_12 ( V_70 , V_36 ) ;
F_12 ( V_71 , V_37 ) ;
F_12 ( V_72 , V_35 ) ;
F_14 ( 50 ) ;
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ V_57 ;
F_3 ( V_51 , V_47 ) ;
F_14 ( 500 ) ;
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ V_62 ;
V_47 |= V_63 ;
F_3 ( V_51 , V_47 ) ;
F_3 ( V_11 , V_69 ) ;
V_47 = F_8 ( V_51 ) ;
F_3 ( V_51 , V_47 | 0x40 ) ;
V_47 = F_8 ( V_55 ) ;
V_47 |= ( 0x3 << 2 ) ;
F_3 ( V_56 , V_47 ) ;
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ V_52 ;
F_3 ( V_51 , V_47 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , long clock )
{
unsigned int V_26 , V_27 , V_28 ;
unsigned int V_29 , V_30 , V_31 ;
unsigned int V_32 , V_33 , V_34 ;
unsigned int V_35 , V_36 , V_37 ;
unsigned int V_38 ;
int V_9 , V_43 , V_44 , V_45 ;
T_1 V_47 ;
bool V_46 = false ;
V_36 = V_37 = V_35 = 0 ;
V_26 = 800000 ;
V_27 = 400000 ;
V_28 = 33333 ;
V_29 = 0xffffffff ;
V_31 = clock * 5 / 1000 ;
for ( V_32 = 16 ; V_32 > 0 ; V_32 >>= 1 ) {
if ( clock * V_32 > V_26 )
continue;
if ( clock * V_32 < V_27 )
continue;
for ( V_33 = 1 ; V_33 < 33 ; V_33 ++ ) {
for ( V_34 = 17 ; V_34 < 257 ; V_34 ++ ) {
V_38 = ( V_28 * V_34 ) /
( V_33 * V_32 ) ;
if ( V_38 > clock )
V_30 = V_38 - clock ;
else
V_30 = clock - V_38 ;
if ( V_30 < V_29 ) {
V_29 = V_30 ;
V_37 = V_34 - 1 ;
V_36 = ( V_33 - 1 ) ;
V_35 = V_32 - 1 ;
}
if ( ( clock * V_32 ) >= 600000 )
V_35 |= 0x80 ;
}
}
}
for ( V_9 = 0 ; V_9 <= 32 && V_46 == false ; V_9 ++ ) {
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= V_52 ;
F_3 ( V_51 , V_47 ) ;
V_47 = F_8 ( V_55 ) ;
V_47 |= 0x3 << 2 ;
F_3 ( V_56 , V_47 ) ;
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= V_57 ;
F_3 ( V_51 , V_47 ) ;
F_14 ( 500 ) ;
F_12 ( V_73 , V_36 ) ;
F_12 ( V_74 , V_37 ) ;
F_12 ( V_75 , V_35 ) ;
F_14 ( 500 ) ;
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ V_62 ;
V_47 |= V_63 ;
F_3 ( V_51 , V_47 ) ;
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ V_52 ;
V_47 &= ~ V_57 ;
F_3 ( V_51 , V_47 ) ;
V_45 = F_8 ( V_68 ) ;
for ( V_43 = 0 ; V_43 < 30 && V_46 == false ; V_43 ++ ) {
V_44 = F_8 ( V_68 ) ;
if ( V_44 < V_45 )
V_45 = 0 ;
if ( ( V_44 - V_45 ) > 2 )
V_46 = true ;
else
F_14 ( 5 ) ;
}
}
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , long clock )
{
unsigned int V_26 , V_27 , V_28 ;
unsigned int V_29 , V_30 ;
int V_76 , V_34 , V_33 , V_77 ;
unsigned int V_35 , V_36 , V_37 ;
unsigned int V_38 , V_78 ;
int V_47 ;
const unsigned int V_79 [] = { 1 , 2 , 4 , 8 } ;
V_36 = V_37 = V_35 = 0 ;
V_26 = 1488000 ;
V_27 = 1056000 ;
V_28 = 48000 ;
V_29 = 0xffffffff ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
if ( V_29 == 0 )
break;
for ( V_34 = 5 ; V_34 < 129 ; V_34 ++ ) {
if ( V_29 == 0 )
break;
for ( V_33 = 3 ; V_33 >= 0 ; V_33 -- ) {
if ( V_29 == 0 )
break;
for ( V_77 = 5 ; V_77 < 33 ; V_77 ++ ) {
V_78 = V_28 * ( V_34 + 1 ) /
( V_76 + 1 ) ;
if ( V_78 < V_27 )
continue;
if ( V_78 > V_26 )
continue;
V_38 = V_78 / ( V_79 [ V_33 ] * ( V_77 + 1 ) ) ;
if ( V_38 > clock )
V_30 = V_38 - clock ;
else
V_30 = clock - V_38 ;
if ( V_30 < V_29 ) {
V_29 = V_30 ;
V_36 = V_33 | ( V_77 << 3 ) ;
V_37 = V_34 ;
V_35 = V_76 | ( V_76 << 3 ) ;
}
}
}
}
}
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= V_52 ;
F_3 ( V_51 , V_47 ) ;
F_3 ( V_11 , V_53 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= V_54 ;
F_3 ( V_51 , V_47 ) ;
V_47 = F_8 ( V_55 ) ;
V_47 |= ( 0x3 << 2 ) | 0xc0 ;
F_3 ( V_56 , V_47 ) ;
F_3 ( V_11 , V_50 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ V_52 ;
V_47 |= V_57 ;
F_3 ( V_51 , V_47 ) ;
F_14 ( 500 ) ;
F_12 ( V_80 , V_37 ) ;
F_12 ( V_81 , V_36 ) ;
F_12 ( V_82 , V_35 ) ;
F_14 ( 50 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , long clock )
{
switch( V_7 -> type ) {
case V_83 :
case V_84 :
return F_10 ( V_7 , clock ) ;
break;
case V_85 :
return F_13 ( V_7 , clock ) ;
break;
case V_86 :
return F_15 ( V_7 , clock ) ;
break;
case V_87 :
return F_16 ( V_7 , clock ) ;
break;
case V_88 :
return F_17 ( V_7 , clock ) ;
break;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_1 V_47 ;
int V_89 ;
F_3 ( V_11 , V_90 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= 0x10 ;
F_12 ( V_90 , V_47 ) ;
F_3 ( V_11 , V_91 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= 0x10 ;
F_12 ( V_91 , V_47 ) ;
F_3 ( V_11 , V_92 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= 0x80 ;
F_12 ( V_92 , V_47 ) ;
V_89 = 300 ;
while ( ! ( V_47 & 0x1 ) && V_89 ) {
F_3 ( V_11 , V_92 ) ;
V_47 = F_8 ( V_51 ) ;
F_14 ( 1000 ) ;
V_89 -- ;
}
if ( V_89 ) {
V_89 = 300 ;
while ( ( V_47 & 0x2 ) && V_89 ) {
F_3 ( V_11 , V_92 ) ;
V_47 = F_8 ( V_51 ) ;
F_14 ( 1000 ) ;
V_89 -- ;
}
}
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_47 ;
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
F_3 ( V_93 , 1 ) ;
V_47 = F_8 ( V_94 ) ;
F_3 ( V_94 , V_47 | 0x88 ) ;
F_3 ( V_11 , V_95 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 |= 0x8 ;
F_3 ( V_51 , V_47 ) ;
F_14 ( 10 ) ;
V_47 &= ~ 0x08 ;
F_3 ( V_11 , V_95 ) ;
F_3 ( V_51 , V_47 ) ;
F_3 ( V_11 , V_92 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ 0x80 ;
F_3 ( V_51 , V_47 ) ;
F_3 ( V_11 , V_91 ) ;
V_47 = F_8 ( V_51 ) ;
V_47 &= ~ 0x10 ;
F_12 ( V_91 , V_47 ) ;
}
void F_21 ( struct V_1 * V_2 , unsigned V_96 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_2 V_97 ;
int V_98 ;
T_1 V_99 ;
while ( F_8 ( 0x1fda ) & 0x08 ) ;
while ( ! ( F_8 ( 0x1fda ) & 0x08 ) ) ;
V_98 = F_8 ( V_68 ) + 2 ;
while ( F_8 ( V_68 ) < V_98 ) ;
F_3 ( V_93 , 0 ) ;
V_99 = F_8 ( V_94 ) ;
V_99 &= 0xB0 ;
V_97 = V_96 / 8 ;
F_22 ( V_97 > 0x1fffff ) ;
V_99 |= ( ! ! ( V_97 & ( 1 << 20 ) ) ) << 6 ;
F_23 ( 0x0d , ( T_1 ) ( V_97 & 0xff ) ) ;
F_23 ( 0x0c , ( T_1 ) ( V_97 >> 8 ) & 0xff ) ;
F_24 ( 0x0 , ( ( T_1 ) ( V_97 >> 16 ) & 0xf ) | V_99 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_100 * V_101 ,
int V_102 , int V_103 , int V_104 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
int V_111 ;
T_3 V_112 ;
if ( ! V_104 && V_101 ) {
V_108 = F_26 ( V_101 ) ;
V_106 = V_108 -> V_106 ;
V_110 = F_27 ( V_106 ) ;
V_111 = F_28 ( V_110 , false ) ;
if ( V_111 )
return V_111 ;
F_29 ( V_110 ) ;
F_30 ( V_110 ) ;
}
V_108 = F_26 ( V_2 -> V_101 ) ;
V_106 = V_108 -> V_106 ;
V_110 = F_27 ( V_106 ) ;
V_111 = F_28 ( V_110 , false ) ;
if ( V_111 )
return V_111 ;
V_111 = F_31 ( V_110 , V_113 , & V_112 ) ;
if ( V_111 ) {
F_30 ( V_110 ) ;
return V_111 ;
}
if ( & V_7 -> V_114 -> V_115 == V_108 ) {
V_111 = F_32 ( & V_110 -> V_110 , 0 , V_110 -> V_110 . V_116 , & V_110 -> V_117 ) ;
if ( V_111 )
F_33 ( L_2 ) ;
}
F_30 ( V_110 ) ;
F_34 ( L_3 , V_112 ) ;
F_21 ( V_2 , ( T_2 ) V_112 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , int V_102 , int V_103 ,
struct V_100 * V_118 )
{
return F_25 ( V_2 , V_118 , V_102 , V_103 , 0 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_23 * V_25 ,
int V_102 , int V_103 , struct V_100 * V_118 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_119 , V_120 , V_121 , V_122 ;
int V_123 , V_124 , V_125 , V_126 ;
int V_127 ;
int V_128 = 0 , V_129 = 0 ;
int V_9 ;
unsigned char V_130 = 0 ;
unsigned char V_131 [ 6 ] ;
T_1 V_132 ;
static unsigned char V_133 [] = {
0 , 0 , 0 , 0 , 0 , 0 , 0x00 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0x00 , 0 , 0xC9 , 0xFF , 0xBF , 0x20 , 0x1F , 0x20 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0 , 0 , 0 , 0x40 ,
0x00 , 0xB0 , 0x00 , 0xC2 , 0x34 , 0x14 , 0x02 , 0x83 ,
0x00 , 0x93 , 0x00 , 0x77 , 0x00 , 0x00 , 0x00 , 0x3A ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
} ;
V_132 = V_7 -> V_134 [ ( V_2 -> V_101 -> V_135 >> 3 ) - 1 ] ;
switch ( V_7 -> type ) {
case V_83 :
case V_84 :
V_133 [ V_58 ] = 0x03 ;
V_133 [ V_50 ] = V_63 ;
V_133 [ V_136 ] = V_137 |
V_138 |
V_139 ;
if ( V_7 -> V_140 )
V_128 = 0x40049120 ;
else
V_128 = 0x4004d120 ;
V_129 = 0x00008000 ;
break;
case V_85 :
V_133 [ V_58 ] = 0x07 ;
V_128 = 0x41049120 ;
V_129 = 0x0000b000 ;
break;
case V_86 :
V_133 [ V_50 ] = V_63 ;
V_133 [ V_136 ] = V_138 |
V_139 ;
V_128 = 0x00000120 ;
V_129 = 0x0000b000 ;
break;
case V_87 :
V_133 [ V_136 ] = V_138 |
V_139 ;
V_128 = 0x00000120 ;
V_129 = 0x0000b000 ;
break;
case V_88 :
break;
}
switch ( V_2 -> V_101 -> V_135 ) {
case 8 :
V_133 [ V_141 ] = V_142 ;
break;
case 16 :
if ( V_2 -> V_101 -> V_143 == 15 )
V_133 [ V_141 ] = V_144 ;
else
V_133 [ V_141 ] = V_145 ;
break;
case 24 :
V_133 [ V_141 ] = V_146 ;
break;
case 32 :
V_133 [ V_141 ] = V_147 ;
break;
}
if ( V_24 -> V_148 & V_149 )
V_130 |= 0x40 ;
if ( V_24 -> V_148 & V_150 )
V_130 |= 0x80 ;
for ( V_9 = 0 ; V_9 < sizeof( V_133 ) ; V_9 ++ ) {
if ( ( V_9 <= 0x17 ) ||
( V_9 == 0x1b ) ||
( V_9 == 0x1c ) ||
( ( V_9 >= 0x1f ) && ( V_9 <= 0x29 ) ) ||
( ( V_9 >= 0x30 ) && ( V_9 <= 0x37 ) ) )
continue;
if ( F_37 ( V_7 ) &&
( ( V_9 == 0x2c ) || ( V_9 == 0x2d ) || ( V_9 == 0x2e ) ) )
continue;
if ( ( V_7 -> type == V_86 || V_7 -> type == V_85 || V_7 -> type == V_87 ) &&
( V_9 >= 0x44 ) && ( V_9 <= 0x4e ) )
continue;
F_12 ( V_9 , V_133 [ V_9 ] ) ;
}
if ( V_7 -> type == V_88 )
F_12 ( 0x90 , 0 ) ;
if ( V_128 )
F_38 ( V_5 -> V_151 , V_152 , V_128 ) ;
if ( V_129 )
F_38 ( V_5 -> V_151 , V_153 , V_129 ) ;
F_39 ( 2 , 0xf ) ;
F_39 ( 3 , 0 ) ;
F_39 ( 4 , 0xe ) ;
V_127 = V_2 -> V_101 -> V_154 [ 0 ] / ( V_2 -> V_101 -> V_135 / 8 ) ;
if ( V_2 -> V_101 -> V_135 == 24 )
V_127 = V_127 >> ( 4 - V_132 ) ;
else
V_127 = V_127 >> ( 4 - V_132 ) ;
V_119 = V_24 -> V_119 / 8 - 1 ;
V_120 = V_24 -> V_155 / 8 - 1 ;
V_121 = V_24 -> V_156 / 8 - 1 ;
V_122 = V_24 -> V_122 / 8 - 1 ;
if ( ( V_122 & 0x07 ) == 0x06 || ( V_122 & 0x07 ) == 0x04 )
V_122 ++ ;
V_123 = V_24 -> V_123 - 1 ;
V_124 = V_24 -> V_157 - 1 ;
V_125 = V_24 -> V_158 - 1 ;
V_126 = V_24 -> V_126 - 2 ;
F_40 ( 0 , 0 ) ;
F_40 ( 1 , 0 ) ;
F_40 ( 2 , 0 ) ;
F_40 ( 3 , 0 ) ;
F_40 ( 4 , 0 ) ;
F_40 ( 5 , 0x40 ) ;
F_40 ( 6 , 0x5 ) ;
F_40 ( 7 , 0xf ) ;
F_40 ( 8 , 0xf ) ;
F_23 ( 0 , V_122 - 4 ) ;
F_23 ( 1 , V_119 ) ;
F_23 ( 2 , V_119 ) ;
F_23 ( 3 , ( V_122 & 0x1F ) | 0x80 ) ;
F_23 ( 4 , V_120 ) ;
F_23 ( 5 , ( ( V_122 & 0x20 ) << 2 ) | ( V_121 & 0x1F ) ) ;
F_23 ( 6 , V_126 & 0xFF ) ;
F_23 ( 7 , ( ( V_126 & 0x100 ) >> 8 ) |
( ( V_123 & 0x100 ) >> 7 ) |
( ( V_124 & 0x100 ) >> 6 ) |
( ( V_123 & 0x100 ) >> 5 ) |
( ( V_123 & 0x100 ) >> 4 ) |
( ( V_126 & 0x200 ) >> 4 ) |
( ( V_123 & 0x200 ) >> 3 ) |
( ( V_124 & 0x200 ) >> 2 ) ) ;
F_23 ( 9 , ( ( V_123 & 0x200 ) >> 4 ) |
( ( V_123 & 0x200 ) >> 3 ) ) ;
F_23 ( 10 , 0 ) ;
F_23 ( 11 , 0 ) ;
F_23 ( 12 , 0 ) ;
F_23 ( 13 , 0 ) ;
F_23 ( 14 , 0 ) ;
F_23 ( 15 , 0 ) ;
F_23 ( 16 , V_124 & 0xFF ) ;
F_23 ( 17 , ( V_125 & 0x0F ) | 0x20 ) ;
F_23 ( 18 , V_123 & 0xFF ) ;
F_23 ( 19 , V_127 & 0xFF ) ;
F_23 ( 20 , 0 ) ;
F_23 ( 21 , V_123 & 0xFF ) ;
F_23 ( 22 , ( V_126 + 1 ) & 0xFF ) ;
F_23 ( 23 , 0xc3 ) ;
F_23 ( 24 , V_123 & 0xFF ) ;
V_131 [ 0 ] = 0 ;
V_131 [ 5 ] = 0 ;
V_131 [ 0 ] |= ( V_127 & 0x300 ) >> 4 ;
V_131 [ 1 ] = ( ( ( V_122 - 4 ) & 0x100 ) >> 8 ) |
( ( V_119 & 0x100 ) >> 7 ) |
( ( V_120 & 0x100 ) >> 6 ) |
( V_122 & 0x40 ) ;
V_131 [ 2 ] = ( ( V_126 & 0xc00 ) >> 10 ) |
( ( V_123 & 0x400 ) >> 8 ) |
( ( V_123 & 0xc00 ) >> 7 ) |
( ( V_124 & 0xc00 ) >> 5 ) |
( ( V_123 & 0x400 ) >> 3 ) ;
if ( V_2 -> V_101 -> V_135 == 24 )
V_131 [ 3 ] = ( ( ( 1 << V_132 ) * 3 ) - 1 ) | 0x80 ;
else
V_131 [ 3 ] = ( ( 1 << V_132 ) - 1 ) | 0x80 ;
V_131 [ 4 ] = 0 ;
if ( V_7 -> type == V_85 )
V_131 [ 1 ] |= 0x88 ;
V_130 = 0x2d ;
F_3 ( V_159 , V_130 ) ;
F_18 ( V_7 , V_24 -> clock ) ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ ) {
F_24 ( V_9 , V_131 [ V_9 ] ) ;
}
if ( V_7 -> type == V_88 )
F_24 ( 0x24 , 0x5 ) ;
if ( V_7 -> type == V_86 ) {
F_24 ( 6 , 0 ) ;
}
F_24 ( 0 , V_131 [ 0 ] ) ;
V_130 = 0x2d ;
F_3 ( V_159 , V_130 ) ;
if ( V_25 )
memcpy ( & V_7 -> V_24 , V_24 , sizeof( struct V_23 ) ) ;
F_25 ( V_2 , V_118 , V_102 , V_103 , 0 ) ;
if ( V_7 -> type == V_88 ) {
T_2 V_160 = F_5 ( V_161 ) ;
T_1 V_162 ;
F_3 ( V_66 , 0x01 ) ;
V_162 = F_8 ( V_67 ) | 0x20 ;
F_3 ( V_67 , V_162 ) ;
F_41 ( V_161 , V_160 | 0x00200000 ) ;
F_14 ( 1000 ) ;
F_41 ( V_161 , V_160 & ~ 0x00200000 ) ;
F_3 ( V_67 , V_162 & ~ 0x20 ) ;
}
if ( F_37 ( V_7 ) ) {
if ( V_7 -> V_163 >= 0x02 ) {
T_1 V_164 ;
T_2 V_165 ;
T_2 V_166 ;
if ( V_2 -> V_101 -> V_135 > 16 )
V_165 = 32 ;
else if ( V_2 -> V_101 -> V_135 > 8 )
V_165 = 16 ;
else
V_165 = 8 ;
V_166 = ( V_24 -> clock * V_165 ) / 1000 ;
if ( V_166 > 3100 )
V_164 = 0 ;
else if ( V_166 > 2600 )
V_164 = 1 ;
else if ( V_166 > 1900 )
V_164 = 2 ;
else if ( V_166 > 1160 )
V_164 = 3 ;
else if ( V_166 > 440 )
V_164 = 4 ;
else
V_164 = 5 ;
F_3 ( V_93 , 0x06 ) ;
F_3 ( V_94 , V_164 ) ;
} else {
F_3 ( V_93 , 0x06 ) ;
if ( V_7 -> V_163 >= 0x01 )
F_3 ( V_94 , 0x03 ) ;
else
F_3 ( V_94 , 0x04 ) ;
}
}
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , int V_24 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_162 = 0 , V_167 = 0 ;
switch ( V_24 ) {
case V_168 :
V_162 = 0 ;
V_167 = 0 ;
F_1 ( V_2 ) ;
break;
case V_169 :
V_162 = 0x20 ;
V_167 = 0x10 ;
break;
case V_170 :
V_162 = 0x20 ;
V_167 = 0x20 ;
break;
case V_171 :
V_162 = 0x20 ;
V_167 = 0x30 ;
break;
}
#if 0
if (mode == DRM_MODE_DPMS_OFF) {
mga_suspend(crtc);
}
#endif
F_3 ( V_66 , 0x01 ) ;
V_162 |= F_8 ( V_67 ) & ~ 0x20 ;
F_4 ( V_7 ) ;
F_7 ( V_7 ) ;
F_3 ( V_67 , V_162 ) ;
F_43 ( 20 ) ;
F_3 ( V_93 , 0x01 ) ;
V_167 |= F_8 ( V_94 ) & ~ 0x30 ;
F_3 ( V_94 , V_167 ) ;
#if 0
if (mode == DRM_MODE_DPMS_ON && mdev->suspended == true) {
mga_resume(crtc);
drm_helper_resume_force_mode(dev);
}
#endif
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_47 ;
F_3 ( V_48 , 0x11 ) ;
V_47 = F_8 ( V_49 ) ;
F_23 ( 0x11 , V_47 | 0x80 ) ;
if ( V_7 -> type == V_83 || V_7 -> type == V_84 ) {
F_39 ( 0 , 1 ) ;
F_43 ( 50 ) ;
F_39 ( 1 , 0x20 ) ;
F_43 ( 20 ) ;
} else {
F_3 ( V_66 , 0x1 ) ;
V_47 = F_8 ( V_67 ) ;
F_39 ( 0 , 1 ) ;
F_39 ( 1 , V_47 | 0x20 ) ;
}
if ( V_7 -> type == V_85 )
F_19 ( V_2 ) ;
F_23 ( 17 , 0 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_172 * V_173 = V_2 -> V_174 ;
T_1 V_47 ;
if ( V_7 -> type == V_85 )
F_20 ( V_2 ) ;
if ( V_7 -> type == V_83 || V_7 -> type == V_84 ) {
F_43 ( 50 ) ;
F_39 ( 1 , 0x0 ) ;
F_43 ( 20 ) ;
F_39 ( 0 , 0x3 ) ;
} else {
F_3 ( V_66 , 0x1 ) ;
V_47 = F_8 ( V_67 ) ;
V_47 &= ~ 0x20 ;
F_39 ( 0x1 , V_47 ) ;
F_39 ( 0 , 3 ) ;
}
V_173 -> V_175 ( V_2 , V_168 ) ;
}
static void F_46 ( struct V_1 * V_2 , T_4 * V_176 , T_4 * V_177 ,
T_4 * V_178 , T_5 V_179 , T_5 V_180 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_181 = ( V_179 + V_180 > V_13 ) ? V_13 : V_179 + V_180 ;
int V_9 ;
for ( V_9 = V_179 ; V_9 < V_181 ; V_9 ++ ) {
V_3 -> V_15 [ V_9 ] = V_176 [ V_9 ] >> 8 ;
V_3 -> V_16 [ V_9 ] = V_177 [ V_9 ] >> 8 ;
V_3 -> V_17 [ V_9 ] = V_178 [ V_9 ] >> 8 ;
}
F_1 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_48 ( V_2 ) ;
F_49 ( V_3 ) ;
}
static void F_50 ( struct V_6 * V_7 )
{
struct V_3 * V_3 ;
int V_9 ;
V_3 = F_51 ( sizeof( struct V_3 ) +
( V_182 * sizeof( struct V_183 * ) ) ,
V_184 ) ;
if ( V_3 == NULL )
return;
F_52 ( V_7 -> V_5 , & V_3 -> V_185 , & V_186 ) ;
F_53 ( & V_3 -> V_185 , V_13 ) ;
V_7 -> V_187 . V_2 = V_3 ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
V_3 -> V_15 [ V_9 ] = V_9 ;
V_3 -> V_16 [ V_9 ] = V_9 ;
V_3 -> V_17 [ V_9 ] = V_9 ;
}
F_54 ( & V_3 -> V_185 , & V_188 ) ;
}
void F_55 ( struct V_1 * V_2 , T_4 V_176 , T_4 V_177 ,
T_4 V_178 , int V_189 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_15 [ V_189 ] = V_176 >> 8 ;
V_3 -> V_16 [ V_189 ] = V_177 >> 8 ;
V_3 -> V_17 [ V_189 ] = V_178 >> 8 ;
}
void F_56 ( struct V_1 * V_2 , T_4 * V_176 , T_4 * V_177 ,
T_4 * V_178 , int V_189 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_176 = ( T_4 ) V_3 -> V_15 [ V_189 ] << 8 ;
* V_177 = ( T_4 ) V_3 -> V_16 [ V_189 ] << 8 ;
* V_178 = ( T_4 ) V_3 -> V_17 [ V_189 ] << 8 ;
}
static bool F_57 ( struct V_190 * V_191 ,
const struct V_23 * V_24 ,
struct V_23 * V_25 )
{
return true ;
}
static void F_58 ( struct V_190 * V_191 ,
struct V_23 * V_24 ,
struct V_23 * V_25 )
{
}
static void F_59 ( struct V_190 * V_191 , int V_192 )
{
return;
}
static void F_60 ( struct V_190 * V_191 )
{
}
static void F_61 ( struct V_190 * V_191 )
{
}
void F_62 ( struct V_190 * V_191 )
{
struct V_193 * V_193 = F_63 ( V_191 ) ;
F_64 ( V_191 ) ;
F_49 ( V_193 ) ;
}
static struct V_190 * F_65 ( struct V_4 * V_5 )
{
struct V_190 * V_191 ;
struct V_193 * V_193 ;
V_193 = F_51 ( sizeof( struct V_193 ) , V_184 ) ;
if ( ! V_193 )
return NULL ;
V_191 = & V_193 -> V_185 ;
V_191 -> V_194 = 0x1 ;
F_66 ( V_5 , V_191 , & V_195 ,
V_196 ) ;
F_67 ( V_191 , & V_197 ) ;
return V_191 ;
}
static int F_68 ( struct V_183 * V_198 )
{
struct V_199 * V_199 = F_69 ( V_198 ) ;
struct V_200 * V_200 ;
int V_111 = 0 ;
V_200 = F_70 ( V_198 , & V_199 -> V_201 -> V_202 ) ;
if ( V_200 ) {
F_71 ( V_198 , V_200 ) ;
V_111 = F_72 ( V_198 , V_200 ) ;
F_49 ( V_200 ) ;
}
return V_111 ;
}
static int F_73 ( struct V_183 * V_198 ,
struct V_23 * V_24 )
{
struct V_4 * V_5 = V_198 -> V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_5 -> V_8 ;
struct V_203 * V_114 = V_7 -> V_114 ;
struct V_204 * V_205 = & V_114 -> V_206 ;
struct V_207 * V_208 = NULL ;
int V_165 = 32 ;
int V_9 = 0 ;
if ( V_24 -> V_209 > 2048 || V_24 -> V_210 > 4096 ||
V_24 -> V_211 > 4096 || V_24 -> V_212 > 4096 ||
V_24 -> V_213 > 2048 || V_24 -> V_214 > 4096 ||
V_24 -> V_215 > 4096 || V_24 -> V_216 > 4096 ) {
return V_217 ;
}
for ( V_9 = 0 ; V_9 < V_205 -> V_218 ; V_9 ++ ) {
if ( V_205 -> V_219 [ V_9 ] -> V_198 == V_198 ) {
V_208 = V_205 -> V_219 [ V_9 ] ;
if ( V_208 -> V_220 . V_221 ) {
if ( V_208 -> V_220 . V_222 ) {
V_165 = V_208 -> V_220 . V_165 ;
}
}
}
}
if ( ( V_24 -> V_119 * V_24 -> V_123 * ( V_165 / 8 ) ) > V_7 -> V_223 . V_224 ) {
if ( V_208 )
V_208 -> V_220 . V_221 = false ;
return V_217 ;
}
return V_225 ;
}
struct V_190 * F_74 ( struct V_183
* V_198 )
{
int V_226 = V_198 -> V_227 [ 0 ] ;
struct V_228 * V_106 ;
struct V_190 * V_191 ;
if ( V_226 ) {
V_106 =
F_75 ( V_198 -> V_5 , V_226 ,
V_229 ) ;
if ( ! V_106 )
return NULL ;
V_191 = F_76 ( V_106 ) ;
return V_191 ;
}
return NULL ;
}
static enum V_230 F_77 ( struct V_183
* V_198 , bool V_231 )
{
return V_232 ;
}
static void F_78 ( struct V_183 * V_198 )
{
struct V_199 * V_199 = F_69 ( V_198 ) ;
F_79 ( V_199 -> V_201 ) ;
F_80 ( V_198 ) ;
F_49 ( V_198 ) ;
}
static struct V_183 * F_81 ( struct V_4 * V_5 )
{
struct V_183 * V_198 ;
struct V_199 * V_199 ;
V_199 = F_51 ( sizeof( struct V_199 ) , V_184 ) ;
if ( ! V_199 )
return NULL ;
V_198 = & V_199 -> V_185 ;
F_82 ( V_5 , V_198 ,
& V_233 , V_234 ) ;
F_83 ( V_198 , & V_235 ) ;
V_199 -> V_201 = F_84 ( V_5 ) ;
if ( ! V_199 -> V_201 )
F_33 ( L_4 ) ;
return V_198 ;
}
int F_85 ( struct V_6 * V_7 )
{
struct V_190 * V_191 ;
struct V_183 * V_198 ;
int V_111 ;
V_7 -> V_187 . V_236 = true ;
V_7 -> V_5 -> V_237 . V_238 = V_239 ;
V_7 -> V_5 -> V_237 . V_240 = V_241 ;
V_7 -> V_5 -> V_237 . V_242 = V_7 -> V_223 . V_243 ;
F_50 ( V_7 ) ;
V_191 = F_65 ( V_7 -> V_5 ) ;
if ( ! V_191 ) {
F_33 ( L_5 ) ;
return - 1 ;
}
V_198 = F_81 ( V_7 -> V_5 ) ;
if ( ! V_198 ) {
F_33 ( L_6 ) ;
return - 1 ;
}
F_86 ( V_198 , V_191 ) ;
V_111 = F_87 ( V_7 ) ;
if ( V_111 ) {
F_33 ( L_7 ) ;
return V_111 ;
}
return 0 ;
}
void F_88 ( struct V_6 * V_7 )
{
}
