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
unsigned int V_18 = 0 ;
unsigned int V_19 = 0 ;
do {
V_19 = F_5 ( V_20 ) ;
V_18 ++ ;
} while ( ( V_19 & 0x08 ) && ( V_18 < 250000 ) );
V_18 = 0 ;
V_19 = 0 ;
do {
V_19 = F_5 ( V_20 ) ;
V_18 ++ ;
} while ( ! ( V_19 & 0x08 ) && ( V_18 < 250000 ) );
}
static inline void F_6 ( struct V_6 * V_7 )
{
unsigned int V_18 = 0 ;
unsigned int V_19 = 0 ;
do {
V_19 = F_7 ( V_20 + 2 ) ;
V_18 ++ ;
} while ( ( V_19 & 0x01 ) && ( V_18 < 500000 ) );
}
static bool F_8 ( struct V_1 * V_2 ,
const struct V_21 * V_22 ,
struct V_21 * V_23 )
{
return true ;
}
static int F_9 ( struct V_6 * V_7 , long clock )
{
unsigned int V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 , V_29 ;
unsigned int V_30 , V_31 , V_32 ;
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 ;
V_34 = V_35 = V_33 = 0 ;
V_24 = 320000 ;
V_25 = 160000 ;
V_26 = 25000 ;
V_27 = 0xffffffff ;
V_29 = clock * 5 / 1000 ;
for ( V_30 = 8 ; V_30 > 0 ; V_30 /= 2 ) {
if ( clock * V_30 > V_24 )
continue;
if ( clock * V_30 < V_25 )
continue;
for ( V_32 = 17 ; V_32 < 256 ; V_32 ++ ) {
for ( V_31 = 1 ; V_31 < 32 ; V_31 ++ ) {
V_36 = ( V_26 * V_32 ) /
( V_31 * V_30 ) ;
if ( V_36 > clock )
V_28 = V_36 - clock ;
else
V_28 = clock - V_36 ;
if ( V_28 < V_27 ) {
V_27 = V_28 ;
V_34 = V_31 - 1 ;
V_35 = V_32 - 1 ;
V_33 = V_30 - 1 ;
}
}
}
}
if ( V_27 > V_29 ) {
F_10 ( V_37 L_1 ) ;
return 1 ;
}
F_11 ( V_38 , V_34 ) ;
F_11 ( V_39 , V_35 ) ;
F_11 ( V_40 , V_33 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , long clock )
{
unsigned int V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 , V_29 ;
unsigned int V_30 , V_31 , V_32 ;
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 ;
int V_9 , V_41 , V_42 , V_43 ;
bool V_44 = false ;
T_1 V_45 ;
V_34 = V_35 = V_33 = 0 ;
V_24 = 550000 ;
V_25 = 150000 ;
V_26 = 48000 ;
V_27 = 0xffffffff ;
V_29 = clock * 5 / 1000 ;
for ( V_30 = 1 ; V_30 < 9 ; V_30 ++ ) {
if ( clock * V_30 > V_24 )
continue;
if ( clock * V_30 < V_25 )
continue;
for ( V_31 = 1 ; V_31 < 17 ; V_31 ++ ) {
for ( V_32 = 1 ; V_32 < 151 ; V_32 ++ ) {
V_36 = ( V_26 * V_32 ) /
( V_31 * V_30 ) ;
if ( V_36 > clock )
V_28 = V_36 - clock ;
else
V_28 = clock - V_36 ;
if ( V_28 < V_27 ) {
V_27 = V_28 ;
V_35 = V_32 - 1 ;
V_34 = ( V_31 - 1 ) | ( ( V_35 >> 1 ) & 0x80 ) ;
V_33 = V_30 - 1 ;
}
}
}
}
for ( V_9 = 0 ; V_9 <= 32 && V_44 == false ; V_9 ++ ) {
if ( V_9 > 0 ) {
F_3 ( V_46 , 0x1e ) ;
V_45 = F_7 ( V_47 ) ;
if ( V_45 < 0xff )
F_3 ( V_47 , V_45 + 1 ) ;
}
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= V_50 ;
F_11 ( V_50 , V_45 ) ;
F_3 ( V_11 , V_51 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= V_52 ;
F_11 ( V_51 , V_45 ) ;
V_45 = F_7 ( V_53 ) ;
V_45 |= 0x3 << 2 ;
F_3 ( V_54 , V_45 ) ;
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= V_55 | 0x80 ;
F_11 ( V_48 , V_45 ) ;
F_13 ( 500 ) ;
F_3 ( V_11 , V_56 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ 0x04 ;
F_11 ( V_56 , V_45 ) ;
F_13 ( 50 ) ;
F_11 ( V_57 , V_35 ) ;
F_11 ( V_58 , V_34 ) ;
F_11 ( V_59 , V_33 ) ;
F_13 ( 50 ) ;
F_3 ( V_11 , V_56 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= 0x04 ;
F_11 ( V_56 , V_45 ) ;
F_13 ( 500 ) ;
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ V_60 ;
V_45 |= V_61 ;
F_11 ( V_48 , V_45 ) ;
F_3 ( V_11 , V_51 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ V_62 ;
V_45 |= V_63 ;
F_11 ( V_51 , V_45 ) ;
F_3 ( V_64 , 1 ) ;
V_45 = F_7 ( V_65 ) ;
V_45 &= ~ 0x8 ;
F_3 ( V_65 , V_45 ) ;
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ V_50 ;
F_11 ( V_48 , V_45 ) ;
V_43 = F_7 ( V_66 ) ;
for ( V_41 = 0 ; V_41 < 30 && V_44 == false ; V_41 ++ ) {
V_42 = F_7 ( V_66 ) ;
if ( V_42 < V_43 )
V_43 = 0 ;
if ( ( V_42 - V_43 ) > 2 )
V_44 = true ;
else
F_13 ( 5 ) ;
}
}
F_3 ( V_11 , V_51 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ V_52 ;
F_11 ( V_51 , V_45 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 , long clock )
{
unsigned int V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 , V_29 ;
unsigned int V_30 , V_31 , V_32 ;
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 ;
T_1 V_45 ;
V_34 = V_35 = V_33 = 0 ;
V_24 = 550000 ;
V_25 = 150000 ;
V_26 = 50000 ;
V_27 = 0xffffffff ;
V_29 = clock * 5 / 1000 ;
for ( V_30 = 16 ; V_30 > 0 ; V_30 -- ) {
if ( clock * V_30 > V_24 )
continue;
if ( clock * V_30 < V_25 )
continue;
for ( V_32 = 1 ; V_32 < 257 ; V_32 ++ ) {
for ( V_31 = 1 ; V_31 < 17 ; V_31 ++ ) {
V_36 = ( V_26 * V_32 ) /
( V_31 * V_30 ) ;
if ( V_36 > clock )
V_28 = V_36 - clock ;
else
V_28 = clock - V_36 ;
if ( V_28 < V_27 ) {
V_27 = V_28 ;
V_35 = V_32 - 1 ;
V_34 = V_31 - 1 ;
V_33 = V_30 - 1 ;
}
}
}
}
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= V_50 ;
F_11 ( V_50 , V_45 ) ;
V_45 = F_7 ( V_53 ) ;
V_45 |= 0x3 << 2 ;
F_3 ( V_54 , V_45 ) ;
F_3 ( V_11 , V_67 ) ;
V_45 = F_7 ( V_49 ) ;
F_11 ( V_67 , V_45 & ~ 0x40 ) ;
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= V_55 ;
F_11 ( V_48 , V_45 ) ;
F_11 ( V_68 , V_34 ) ;
F_11 ( V_69 , V_35 ) ;
F_11 ( V_70 , V_33 ) ;
F_13 ( 50 ) ;
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ V_55 ;
F_11 ( V_48 , V_45 ) ;
F_13 ( 500 ) ;
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ V_60 ;
V_45 |= V_61 ;
F_11 ( V_48 , V_45 ) ;
F_3 ( V_11 , V_67 ) ;
V_45 = F_7 ( V_49 ) ;
F_11 ( V_67 , V_45 | 0x40 ) ;
V_45 = F_7 ( V_53 ) ;
V_45 |= ( 0x3 << 2 ) ;
F_3 ( V_54 , V_45 ) ;
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ V_50 ;
F_11 ( V_48 , V_45 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , long clock )
{
unsigned int V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 , V_29 ;
unsigned int V_30 , V_31 , V_32 ;
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 ;
int V_9 , V_41 , V_42 , V_43 ;
T_1 V_45 ;
bool V_44 = false ;
V_34 = V_35 = V_33 = 0 ;
V_24 = 800000 ;
V_25 = 400000 ;
V_26 = 33333 ;
V_27 = 0xffffffff ;
V_29 = clock * 5 / 1000 ;
for ( V_30 = 16 ; V_30 > 0 ; V_30 >>= 1 ) {
if ( clock * V_30 > V_24 )
continue;
if ( clock * V_30 < V_25 )
continue;
for ( V_31 = 1 ; V_31 < 33 ; V_31 ++ ) {
for ( V_32 = 17 ; V_32 < 257 ; V_32 ++ ) {
V_36 = ( V_26 * V_32 ) /
( V_31 * V_30 ) ;
if ( V_36 > clock )
V_28 = V_36 - clock ;
else
V_28 = clock - V_36 ;
if ( V_28 < V_27 ) {
V_27 = V_28 ;
V_35 = V_32 - 1 ;
V_34 = ( V_31 - 1 ) ;
V_33 = V_30 - 1 ;
}
if ( ( clock * V_30 ) >= 600000 )
V_33 |= 0x80 ;
}
}
}
for ( V_9 = 0 ; V_9 <= 32 && V_44 == false ; V_9 ++ ) {
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= V_50 ;
F_11 ( V_50 , V_45 ) ;
V_45 = F_7 ( V_53 ) ;
V_45 |= 0x3 << 2 ;
F_3 ( V_54 , V_45 ) ;
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= V_55 ;
F_11 ( V_48 , V_45 ) ;
F_13 ( 500 ) ;
F_11 ( V_71 , V_34 ) ;
F_11 ( V_72 , V_35 ) ;
F_11 ( V_73 , V_33 ) ;
F_13 ( 500 ) ;
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ V_60 ;
V_45 |= V_61 ;
F_11 ( V_48 , V_45 ) ;
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ V_50 ;
V_45 &= ~ V_55 ;
F_11 ( V_48 , V_45 ) ;
V_43 = F_7 ( V_66 ) ;
for ( V_41 = 0 ; V_41 < 30 && V_44 == false ; V_41 ++ ) {
V_42 = F_7 ( V_66 ) ;
if ( V_42 < V_43 )
V_43 = 0 ;
if ( ( V_42 - V_43 ) > 2 )
V_44 = true ;
else
F_13 ( 5 ) ;
}
}
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , long clock )
{
unsigned int V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 ;
int V_74 , V_32 , V_31 , V_75 ;
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 , V_76 ;
int V_45 ;
const unsigned int V_77 [] = { 1 , 2 , 4 , 8 } ;
V_34 = V_35 = V_33 = 0 ;
V_24 = 1488000 ;
V_25 = 1056000 ;
V_26 = 48000 ;
V_27 = 0xffffffff ;
for ( V_74 = 0 ; V_74 < 4 ; V_74 ++ ) {
if ( V_27 == 0 )
break;
for ( V_32 = 5 ; V_32 < 129 ; V_32 ++ ) {
if ( V_27 == 0 )
break;
for ( V_31 = 3 ; V_31 >= 0 ; V_31 -- ) {
if ( V_27 == 0 )
break;
for ( V_75 = 5 ; V_75 < 33 ; V_75 ++ ) {
V_76 = V_26 * ( V_32 + 1 ) /
( V_74 + 1 ) ;
if ( V_76 < V_25 )
continue;
if ( V_76 > V_24 )
continue;
V_36 = V_76 / ( V_77 [ V_31 ] * ( V_75 + 1 ) ) ;
if ( V_36 > clock )
V_28 = V_36 - clock ;
else
V_28 = clock - V_36 ;
if ( V_28 < V_27 ) {
V_27 = V_28 ;
V_34 = V_31 | ( V_75 << 3 ) ;
V_35 = V_32 ;
V_33 = V_74 | ( V_74 << 3 ) ;
}
}
}
}
}
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= V_50 ;
F_11 ( V_50 , V_45 ) ;
F_3 ( V_11 , V_51 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= V_52 ;
F_11 ( V_51 , V_45 ) ;
V_45 = F_7 ( V_53 ) ;
V_45 |= ( 0x3 << 2 ) | 0xc0 ;
F_3 ( V_54 , V_45 ) ;
F_3 ( V_11 , V_48 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ V_50 ;
V_45 |= V_55 ;
F_11 ( V_48 , V_45 ) ;
F_13 ( 500 ) ;
F_11 ( V_78 , V_35 ) ;
F_11 ( V_79 , V_34 ) ;
F_11 ( V_80 , V_33 ) ;
F_13 ( 50 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , long clock )
{
switch( V_7 -> type ) {
case V_81 :
case V_82 :
return F_9 ( V_7 , clock ) ;
break;
case V_83 :
return F_12 ( V_7 , clock ) ;
break;
case V_84 :
return F_14 ( V_7 , clock ) ;
break;
case V_85 :
return F_15 ( V_7 , clock ) ;
break;
case V_86 :
return F_16 ( V_7 , clock ) ;
break;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_1 V_45 ;
int V_87 ;
F_3 ( V_11 , V_88 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= 0x10 ;
F_11 ( V_88 , V_45 ) ;
F_3 ( V_11 , V_89 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= 0x10 ;
F_11 ( V_89 , V_45 ) ;
F_3 ( V_11 , V_90 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= 0x80 ;
F_11 ( V_90 , V_45 ) ;
V_87 = 300 ;
while ( ! ( V_45 & 0x1 ) && V_87 ) {
F_3 ( V_11 , V_90 ) ;
V_45 = F_7 ( V_49 ) ;
F_13 ( 1000 ) ;
V_87 -- ;
}
if ( V_87 ) {
V_87 = 300 ;
while ( ( V_45 & 0x2 ) && V_87 ) {
F_3 ( V_11 , V_90 ) ;
V_45 = F_7 ( V_49 ) ;
F_13 ( 1000 ) ;
V_87 -- ;
}
}
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_45 ;
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
F_3 ( V_91 , 1 ) ;
V_45 = F_7 ( V_92 ) ;
F_3 ( V_92 , V_45 | 0x88 ) ;
F_3 ( V_11 , V_93 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 |= 0x8 ;
F_3 ( V_49 , V_45 ) ;
F_13 ( 10 ) ;
V_45 &= ~ 0x08 ;
F_3 ( V_11 , V_93 ) ;
F_3 ( V_49 , V_45 ) ;
F_3 ( V_11 , V_90 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ 0x80 ;
F_3 ( V_49 , V_45 ) ;
F_3 ( V_11 , V_89 ) ;
V_45 = F_7 ( V_49 ) ;
V_45 &= ~ 0x10 ;
F_11 ( V_89 , V_45 ) ;
}
void F_20 ( struct V_1 * V_2 , unsigned V_94 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_2 V_95 ;
int V_18 ;
while ( F_7 ( 0x1fda ) & 0x08 ) ;
while ( ! ( F_7 ( 0x1fda ) & 0x08 ) ) ;
V_18 = F_7 ( V_66 ) + 2 ;
while ( F_7 ( V_66 ) < V_18 ) ;
V_95 = V_94 >> 2 ;
F_21 ( 0x0d , ( T_1 ) ( V_95 & 0xff ) ) ;
F_21 ( 0x0c , ( T_1 ) ( V_95 >> 8 ) & 0xff ) ;
F_21 ( 0xaf , ( T_1 ) ( V_95 >> 16 ) & 0xf ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
int V_98 , int V_99 , int V_100 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
int V_107 ;
T_3 V_108 ;
if ( ! V_100 && V_97 ) {
V_104 = F_23 ( V_97 ) ;
V_102 = V_104 -> V_102 ;
V_106 = F_24 ( V_102 ) ;
V_107 = F_25 ( V_106 , false ) ;
if ( V_107 )
return V_107 ;
F_26 ( V_106 ) ;
F_27 ( V_106 ) ;
}
V_104 = F_23 ( V_2 -> V_97 ) ;
V_102 = V_104 -> V_102 ;
V_106 = F_24 ( V_102 ) ;
V_107 = F_25 ( V_106 , false ) ;
if ( V_107 )
return V_107 ;
V_107 = F_28 ( V_106 , V_109 , & V_108 ) ;
if ( V_107 ) {
F_27 ( V_106 ) ;
return V_107 ;
}
if ( & V_7 -> V_110 -> V_111 == V_104 ) {
V_107 = F_29 ( & V_106 -> V_106 , 0 , V_106 -> V_106 . V_112 , & V_106 -> V_113 ) ;
if ( V_107 )
F_30 ( L_2 ) ;
}
F_27 ( V_106 ) ;
F_31 ( L_3 , V_108 ) ;
F_20 ( V_2 , ( T_2 ) V_108 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , int V_98 , int V_99 ,
struct V_96 * V_114 )
{
return F_22 ( V_2 , V_114 , V_98 , V_99 , 0 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_21 * V_23 ,
int V_98 , int V_99 , struct V_96 * V_114 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_115 , V_116 , V_117 , V_118 ;
int V_119 , V_120 , V_121 , V_122 ;
int V_123 ;
int V_124 = 0 , V_125 = 0 ;
int V_9 ;
unsigned char V_126 = 0 ;
unsigned char V_127 [ 6 ] ;
T_1 V_128 ;
static unsigned char V_129 [] = {
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
V_128 = V_7 -> V_130 [ ( V_2 -> V_97 -> V_131 >> 3 ) - 1 ] ;
switch ( V_7 -> type ) {
case V_81 :
case V_82 :
V_129 [ V_56 ] = 0x03 ;
V_129 [ V_48 ] = V_61 ;
V_129 [ V_132 ] = V_133 |
V_134 |
V_135 ;
if ( V_7 -> V_136 )
V_124 = 0x40049120 ;
else
V_124 = 0x4004d120 ;
V_125 = 0x00008000 ;
break;
case V_83 :
V_129 [ V_56 ] = 0x07 ;
V_124 = 0x41049120 ;
V_125 = 0x0000b000 ;
break;
case V_84 :
V_129 [ V_48 ] = V_61 ;
V_129 [ V_132 ] = V_134 |
V_135 ;
V_124 = 0x00000120 ;
V_125 = 0x0000b000 ;
break;
case V_85 :
V_129 [ V_132 ] = V_134 |
V_135 ;
V_124 = 0x00000120 ;
V_125 = 0x0000b000 ;
break;
case V_86 :
break;
}
switch ( V_2 -> V_97 -> V_131 ) {
case 8 :
V_129 [ V_137 ] = V_138 ;
break;
case 16 :
if ( V_2 -> V_97 -> V_139 == 15 )
V_129 [ V_137 ] = V_140 ;
else
V_129 [ V_137 ] = V_141 ;
break;
case 24 :
V_129 [ V_137 ] = V_142 ;
break;
case 32 :
V_129 [ V_137 ] = V_143 ;
break;
}
if ( V_22 -> V_144 & V_145 )
V_126 |= 0x40 ;
if ( V_22 -> V_144 & V_146 )
V_126 |= 0x80 ;
for ( V_9 = 0 ; V_9 < sizeof( V_129 ) ; V_9 ++ ) {
if ( ( V_9 <= 0x03 ) ||
( V_9 == 0x07 ) ||
( V_9 == 0x0b ) ||
( V_9 == 0x0f ) ||
( ( V_9 >= 0x13 ) && ( V_9 <= 0x17 ) ) ||
( V_9 == 0x1b ) ||
( V_9 == 0x1c ) ||
( ( V_9 >= 0x1f ) && ( V_9 <= 0x29 ) ) ||
( ( V_9 >= 0x30 ) && ( V_9 <= 0x37 ) ) )
continue;
if ( F_34 ( V_7 ) &&
( ( V_9 == 0x2c ) || ( V_9 == 0x2d ) || ( V_9 == 0x2e ) ) )
continue;
if ( ( V_7 -> type == V_84 || V_7 -> type == V_83 || V_7 -> type == V_85 ) &&
( V_9 >= 0x44 ) && ( V_9 <= 0x4e ) )
continue;
F_11 ( V_9 , V_129 [ V_9 ] ) ;
}
if ( V_7 -> type == V_86 )
F_11 ( 0x90 , 0 ) ;
if ( V_124 )
F_35 ( V_5 -> V_147 , V_148 , V_124 ) ;
if ( V_125 )
F_35 ( V_5 -> V_147 , V_149 , V_125 ) ;
F_36 ( 2 , 0xf ) ;
F_36 ( 3 , 0 ) ;
F_36 ( 4 , 0xe ) ;
V_123 = V_2 -> V_97 -> V_150 [ 0 ] / ( V_2 -> V_97 -> V_131 / 8 ) ;
if ( V_2 -> V_97 -> V_131 == 24 )
V_123 = V_123 >> ( 4 - V_128 ) ;
else
V_123 = V_123 >> ( 4 - V_128 ) ;
V_115 = V_22 -> V_115 / 8 - 1 ;
V_116 = V_22 -> V_151 / 8 - 1 ;
V_117 = V_22 -> V_152 / 8 - 1 ;
V_118 = V_22 -> V_118 / 8 - 1 ;
if ( ( V_118 & 0x07 ) == 0x06 || ( V_118 & 0x07 ) == 0x04 )
V_118 ++ ;
V_119 = V_22 -> V_119 - 1 ;
V_120 = V_22 -> V_153 - 1 ;
V_121 = V_22 -> V_154 - 1 ;
V_122 = V_22 -> V_122 - 2 ;
F_37 ( 0 , 0 ) ;
F_37 ( 1 , 0 ) ;
F_37 ( 2 , 0 ) ;
F_37 ( 3 , 0 ) ;
F_37 ( 4 , 0 ) ;
F_37 ( 5 , 0x40 ) ;
F_37 ( 6 , 0x5 ) ;
F_37 ( 7 , 0xf ) ;
F_37 ( 8 , 0xf ) ;
F_21 ( 0 , V_118 - 4 ) ;
F_21 ( 1 , V_115 ) ;
F_21 ( 2 , V_115 ) ;
F_21 ( 3 , ( V_118 & 0x1F ) | 0x80 ) ;
F_21 ( 4 , V_116 ) ;
F_21 ( 5 , ( ( V_118 & 0x20 ) << 2 ) | ( V_117 & 0x1F ) ) ;
F_21 ( 6 , V_122 & 0xFF ) ;
F_21 ( 7 , ( ( V_122 & 0x100 ) >> 8 ) |
( ( V_119 & 0x100 ) >> 7 ) |
( ( V_120 & 0x100 ) >> 6 ) |
( ( V_119 & 0x100 ) >> 5 ) |
( ( V_119 & 0x100 ) >> 4 ) |
( ( V_122 & 0x200 ) >> 4 ) |
( ( V_119 & 0x200 ) >> 3 ) |
( ( V_120 & 0x200 ) >> 2 ) ) ;
F_21 ( 9 , ( ( V_119 & 0x200 ) >> 4 ) |
( ( V_119 & 0x200 ) >> 3 ) ) ;
F_21 ( 10 , 0 ) ;
F_21 ( 11 , 0 ) ;
F_21 ( 12 , 0 ) ;
F_21 ( 13 , 0 ) ;
F_21 ( 14 , 0 ) ;
F_21 ( 15 , 0 ) ;
F_21 ( 16 , V_120 & 0xFF ) ;
F_21 ( 17 , ( V_121 & 0x0F ) | 0x20 ) ;
F_21 ( 18 , V_119 & 0xFF ) ;
F_21 ( 19 , V_123 & 0xFF ) ;
F_21 ( 20 , 0 ) ;
F_21 ( 21 , V_119 & 0xFF ) ;
F_21 ( 22 , ( V_122 + 1 ) & 0xFF ) ;
F_21 ( 23 , 0xc3 ) ;
F_21 ( 24 , V_119 & 0xFF ) ;
V_127 [ 0 ] = 0 ;
V_127 [ 5 ] = 0 ;
V_127 [ 0 ] |= ( V_123 & 0x300 ) >> 4 ;
V_127 [ 1 ] = ( ( ( V_118 - 4 ) & 0x100 ) >> 8 ) |
( ( V_115 & 0x100 ) >> 7 ) |
( ( V_116 & 0x100 ) >> 6 ) |
( V_118 & 0x40 ) ;
V_127 [ 2 ] = ( ( V_122 & 0xc00 ) >> 10 ) |
( ( V_119 & 0x400 ) >> 8 ) |
( ( V_119 & 0xc00 ) >> 7 ) |
( ( V_120 & 0xc00 ) >> 5 ) |
( ( V_119 & 0x400 ) >> 3 ) ;
if ( V_2 -> V_97 -> V_131 == 24 )
V_127 [ 3 ] = ( ( ( 1 << V_128 ) * 3 ) - 1 ) | 0x80 ;
else
V_127 [ 3 ] = ( ( 1 << V_128 ) - 1 ) | 0x80 ;
V_127 [ 4 ] = 0 ;
if ( V_7 -> type == V_83 )
V_127 [ 1 ] |= 0x88 ;
V_126 = 0x2d ;
F_3 ( V_155 , V_126 ) ;
F_17 ( V_7 , V_22 -> clock ) ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ ) {
F_38 ( V_9 , V_127 [ V_9 ] ) ;
}
if ( V_7 -> type == V_86 )
F_38 ( 0x24 , 0x5 ) ;
if ( V_7 -> type == V_84 ) {
F_38 ( 6 , 0 ) ;
}
F_38 ( 0 , V_127 [ 0 ] ) ;
V_126 = 0x2d ;
F_3 ( V_155 , V_126 ) ;
if ( V_23 )
memcpy ( & V_7 -> V_22 , V_22 , sizeof( struct V_21 ) ) ;
F_22 ( V_2 , V_114 , V_98 , V_99 , 0 ) ;
if ( V_7 -> type == V_86 ) {
T_2 V_156 = F_5 ( V_157 ) ;
T_1 V_158 ;
F_3 ( V_64 , 0x01 ) ;
V_158 = F_7 ( V_65 ) | 0x20 ;
F_3 ( V_65 , V_158 ) ;
F_39 ( V_157 , V_156 | 0x00200000 ) ;
F_13 ( 1000 ) ;
F_39 ( V_157 , V_156 & ~ 0x00200000 ) ;
F_3 ( V_65 , V_158 & ~ 0x20 ) ;
}
if ( F_34 ( V_7 ) ) {
if ( V_7 -> V_159 >= 0x02 ) {
T_1 V_160 ;
T_2 V_161 ;
T_2 V_162 ;
if ( V_2 -> V_97 -> V_131 > 16 )
V_161 = 32 ;
else if ( V_2 -> V_97 -> V_131 > 8 )
V_161 = 16 ;
else
V_161 = 8 ;
V_162 = ( V_22 -> clock * V_161 ) / 1000 ;
if ( V_162 > 3100 )
V_160 = 0 ;
else if ( V_162 > 2600 )
V_160 = 1 ;
else if ( V_162 > 1900 )
V_160 = 2 ;
else if ( V_162 > 1160 )
V_160 = 3 ;
else if ( V_162 > 440 )
V_160 = 4 ;
else
V_160 = 5 ;
F_3 ( 0x1fde , 0x06 ) ;
F_3 ( 0x1fdf , V_160 ) ;
} else {
if ( V_7 -> V_159 >= 0x01 )
F_3 ( 0x1fdf , 0x03 ) ;
else
F_3 ( 0x1fdf , 0x04 ) ;
}
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , int V_22 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_158 = 0 , V_163 = 0 ;
switch ( V_22 ) {
case V_164 :
V_158 = 0 ;
V_163 = 0 ;
F_1 ( V_2 ) ;
break;
case V_165 :
V_158 = 0x20 ;
V_163 = 0x10 ;
break;
case V_166 :
V_158 = 0x20 ;
V_163 = 0x20 ;
break;
case V_167 :
V_158 = 0x20 ;
V_163 = 0x30 ;
break;
}
#if 0
if (mode == DRM_MODE_DPMS_OFF) {
mga_suspend(crtc);
}
#endif
F_3 ( V_64 , 0x01 ) ;
V_158 |= F_7 ( V_65 ) & ~ 0x20 ;
F_4 ( V_7 ) ;
F_6 ( V_7 ) ;
F_3 ( V_65 , V_158 ) ;
F_41 ( 20 ) ;
F_3 ( V_91 , 0x01 ) ;
V_163 |= F_7 ( V_92 ) & ~ 0x30 ;
F_3 ( V_92 , V_163 ) ;
#if 0
if (mode == DRM_MODE_DPMS_ON && mdev->suspended == true) {
mga_resume(crtc);
drm_helper_resume_force_mode(dev);
}
#endif
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_45 ;
F_3 ( V_46 , 0x11 ) ;
V_45 = F_7 ( V_47 ) ;
F_21 ( 0x11 , V_45 | 0x80 ) ;
if ( V_7 -> type == V_81 || V_7 -> type == V_82 ) {
F_36 ( 0 , 1 ) ;
F_41 ( 50 ) ;
F_36 ( 1 , 0x20 ) ;
F_41 ( 20 ) ;
} else {
F_3 ( V_64 , 0x1 ) ;
V_45 = F_7 ( V_65 ) ;
F_36 ( 0 , 1 ) ;
F_36 ( 1 , V_45 | 0x20 ) ;
}
if ( V_7 -> type == V_83 )
F_18 ( V_2 ) ;
F_21 ( 17 , 0 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_168 * V_169 = V_2 -> V_170 ;
T_1 V_45 ;
if ( V_7 -> type == V_83 )
F_19 ( V_2 ) ;
if ( V_7 -> type == V_81 || V_7 -> type == V_82 ) {
F_41 ( 50 ) ;
F_36 ( 1 , 0x0 ) ;
F_41 ( 20 ) ;
F_36 ( 0 , 0x3 ) ;
} else {
F_3 ( V_64 , 0x1 ) ;
V_45 = F_7 ( V_65 ) ;
V_45 &= ~ 0x20 ;
F_36 ( 0x1 , V_45 ) ;
F_36 ( 0 , 3 ) ;
}
V_169 -> V_171 ( V_2 , V_164 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_4 * V_172 , T_4 * V_173 ,
T_4 * V_174 , T_5 V_175 , T_5 V_176 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_177 = ( V_175 + V_176 > V_13 ) ? V_13 : V_175 + V_176 ;
int V_9 ;
for ( V_9 = V_175 ; V_9 < V_177 ; V_9 ++ ) {
V_3 -> V_15 [ V_9 ] = V_172 [ V_9 ] >> 8 ;
V_3 -> V_16 [ V_9 ] = V_173 [ V_9 ] >> 8 ;
V_3 -> V_17 [ V_9 ] = V_174 [ V_9 ] >> 8 ;
}
F_1 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_3 ) ;
}
static void F_48 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_3 * V_3 ;
int V_9 ;
V_3 = F_49 ( sizeof( struct V_3 ) +
( V_178 * sizeof( struct V_179 * ) ) ,
V_180 ) ;
if ( V_3 == NULL )
return;
F_50 ( V_5 , & V_3 -> V_181 , & V_182 ) ;
F_51 ( & V_3 -> V_181 , V_13 ) ;
V_7 -> V_183 . V_2 = V_3 ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
V_3 -> V_15 [ V_9 ] = V_9 ;
V_3 -> V_16 [ V_9 ] = V_9 ;
V_3 -> V_17 [ V_9 ] = V_9 ;
}
F_52 ( & V_3 -> V_181 , & V_184 ) ;
}
void F_53 ( struct V_1 * V_2 , T_4 V_172 , T_4 V_173 ,
T_4 V_174 , int V_185 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_15 [ V_185 ] = V_172 >> 8 ;
V_3 -> V_16 [ V_185 ] = V_173 >> 8 ;
V_3 -> V_17 [ V_185 ] = V_174 >> 8 ;
}
void F_54 ( struct V_1 * V_2 , T_4 * V_172 , T_4 * V_173 ,
T_4 * V_174 , int V_185 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_172 = ( T_4 ) V_3 -> V_15 [ V_185 ] << 8 ;
* V_173 = ( T_4 ) V_3 -> V_16 [ V_185 ] << 8 ;
* V_174 = ( T_4 ) V_3 -> V_17 [ V_185 ] << 8 ;
}
static bool F_55 ( struct V_186 * V_187 ,
const struct V_21 * V_22 ,
struct V_21 * V_23 )
{
return true ;
}
static void F_56 ( struct V_186 * V_187 ,
struct V_21 * V_22 ,
struct V_21 * V_23 )
{
}
static void F_57 ( struct V_186 * V_187 , int V_188 )
{
return;
}
static void F_58 ( struct V_186 * V_187 )
{
}
static void F_59 ( struct V_186 * V_187 )
{
}
void F_60 ( struct V_186 * V_187 )
{
struct V_189 * V_189 = F_61 ( V_187 ) ;
F_62 ( V_187 ) ;
F_47 ( V_189 ) ;
}
static struct V_186 * F_63 ( struct V_4 * V_5 )
{
struct V_186 * V_187 ;
struct V_189 * V_189 ;
V_189 = F_49 ( sizeof( struct V_189 ) , V_180 ) ;
if ( ! V_189 )
return NULL ;
V_187 = & V_189 -> V_181 ;
V_187 -> V_190 = 0x1 ;
F_64 ( V_5 , V_187 , & V_191 ,
V_192 ) ;
F_65 ( V_187 , & V_193 ) ;
return V_187 ;
}
static int F_66 ( struct V_179 * V_194 )
{
struct V_195 * V_195 = F_67 ( V_194 ) ;
struct V_196 * V_196 ;
int V_107 = 0 ;
V_196 = F_68 ( V_194 , & V_195 -> V_197 -> V_198 ) ;
if ( V_196 ) {
F_69 ( V_194 , V_196 ) ;
V_107 = F_70 ( V_194 , V_196 ) ;
F_47 ( V_196 ) ;
}
return V_107 ;
}
static int F_71 ( struct V_179 * V_194 ,
struct V_21 * V_22 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_5 -> V_8 ;
struct V_199 * V_110 = V_7 -> V_110 ;
struct V_200 * V_201 = & V_110 -> V_202 ;
struct V_203 * V_204 = NULL ;
int V_161 = 32 ;
int V_9 = 0 ;
if ( V_22 -> V_205 > 2048 || V_22 -> V_206 > 4096 ||
V_22 -> V_207 > 4096 || V_22 -> V_208 > 4096 ||
V_22 -> V_209 > 2048 || V_22 -> V_210 > 4096 ||
V_22 -> V_211 > 4096 || V_22 -> V_212 > 4096 ) {
return V_213 ;
}
for ( V_9 = 0 ; V_9 < V_201 -> V_214 ; V_9 ++ ) {
if ( V_201 -> V_215 [ V_9 ] -> V_194 == V_194 ) {
V_204 = V_201 -> V_215 [ V_9 ] ;
if ( V_204 -> V_216 . V_217 ) {
if ( V_204 -> V_216 . V_218 ) {
V_161 = V_204 -> V_216 . V_161 ;
}
}
}
}
if ( ( V_22 -> V_115 * V_22 -> V_119 * ( V_161 / 8 ) ) > V_7 -> V_219 . V_220 ) {
if ( V_204 )
V_204 -> V_216 . V_217 = false ;
return V_213 ;
}
return V_221 ;
}
struct V_186 * F_72 ( struct V_179
* V_194 )
{
int V_222 = V_194 -> V_223 [ 0 ] ;
struct V_224 * V_102 ;
struct V_186 * V_187 ;
if ( V_222 ) {
V_102 =
F_73 ( V_194 -> V_5 , V_222 ,
V_225 ) ;
if ( ! V_102 )
return NULL ;
V_187 = F_74 ( V_102 ) ;
return V_187 ;
}
return NULL ;
}
static enum V_226 F_75 ( struct V_179
* V_194 , bool V_227 )
{
return V_228 ;
}
static void F_76 ( struct V_179 * V_194 )
{
struct V_195 * V_195 = F_67 ( V_194 ) ;
F_77 ( V_195 -> V_197 ) ;
F_78 ( V_194 ) ;
F_47 ( V_194 ) ;
}
static struct V_179 * F_79 ( struct V_4 * V_5 )
{
struct V_179 * V_194 ;
struct V_195 * V_195 ;
V_195 = F_49 ( sizeof( struct V_195 ) , V_180 ) ;
if ( ! V_195 )
return NULL ;
V_194 = & V_195 -> V_181 ;
F_80 ( V_5 , V_194 ,
& V_229 , V_230 ) ;
F_81 ( V_194 , & V_231 ) ;
V_195 -> V_197 = F_82 ( V_5 ) ;
if ( ! V_195 -> V_197 )
F_30 ( L_4 ) ;
return V_194 ;
}
int F_83 ( struct V_6 * V_7 )
{
struct V_186 * V_187 ;
struct V_179 * V_194 ;
int V_107 ;
V_7 -> V_183 . V_232 = true ;
V_7 -> V_5 -> V_233 . V_234 = V_235 ;
V_7 -> V_5 -> V_233 . V_236 = V_237 ;
V_7 -> V_5 -> V_233 . V_238 = V_7 -> V_219 . V_239 ;
F_48 ( V_7 -> V_5 ) ;
V_187 = F_63 ( V_7 -> V_5 ) ;
if ( ! V_187 ) {
F_30 ( L_5 ) ;
return - 1 ;
}
V_194 = F_79 ( V_7 -> V_5 ) ;
if ( ! V_194 ) {
F_30 ( L_6 ) ;
return - 1 ;
}
F_84 ( V_194 , V_187 ) ;
V_107 = F_85 ( V_7 ) ;
if ( V_107 ) {
F_30 ( L_7 ) ;
return V_107 ;
}
return 0 ;
}
void F_86 ( struct V_6 * V_7 )
{
}
