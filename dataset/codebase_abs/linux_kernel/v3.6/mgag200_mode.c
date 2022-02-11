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
V_26 = 3333 ;
V_27 = 0xffffffff ;
V_29 = clock * 5 / 1000 ;
for ( V_30 = 16 ; V_30 > 0 ; V_30 -- ) {
if ( clock * V_30 > V_24 )
continue;
if ( clock * V_30 < V_25 )
continue;
for ( V_31 = 1 ; V_31 < 33 ; V_31 ++ ) {
for ( V_32 = 1 ; V_32 < 257 ; V_32 ++ ) {
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
if ( ( clock * V_30 ) >= 600000 )
V_33 |= 80 ;
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
unsigned char V_128 ;
unsigned char V_129 = 0 ;
T_1 V_130 ;
static unsigned char V_131 [] = {
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
V_130 = V_7 -> V_132 [ ( V_2 -> V_97 -> V_133 >> 3 ) - 1 ] ;
switch ( V_7 -> type ) {
case V_81 :
case V_82 :
V_131 [ V_56 ] = 0x03 ;
V_131 [ V_48 ] = V_61 ;
V_131 [ V_134 ] = V_135 |
V_136 |
V_137 ;
if ( V_7 -> V_138 )
V_124 = 0x40049120 ;
else
V_124 = 0x4004d120 ;
V_125 = 0x00008000 ;
break;
case V_83 :
V_131 [ V_56 ] = 0x07 ;
V_124 = 0x41049120 ;
V_125 = 0x0000b000 ;
break;
case V_84 :
V_131 [ V_48 ] = V_61 ;
V_131 [ V_134 ] = V_136 |
V_137 ;
V_124 = 0x00000120 ;
V_125 = 0x0000b000 ;
break;
case V_85 :
V_131 [ V_134 ] = V_136 |
V_137 ;
V_124 = 0x00000120 ;
V_125 = 0x0000b000 ;
break;
case V_86 :
V_129 = 0 ;
break;
}
switch ( V_2 -> V_97 -> V_133 ) {
case 8 :
V_131 [ V_139 ] = V_140 ;
break;
case 16 :
if ( V_2 -> V_97 -> V_141 == 15 )
V_131 [ V_139 ] = V_142 ;
else
V_131 [ V_139 ] = V_143 ;
break;
case 24 :
V_131 [ V_139 ] = V_144 ;
break;
case 32 :
V_131 [ V_139 ] = V_145 ;
break;
}
if ( V_22 -> V_146 & V_147 )
V_126 |= 0x40 ;
if ( V_22 -> V_146 & V_148 )
V_126 |= 0x80 ;
for ( V_9 = 0 ; V_9 < sizeof( V_131 ) ; V_9 ++ ) {
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
F_11 ( V_9 , V_131 [ V_9 ] ) ;
}
if ( V_7 -> type == V_86 ) {
F_11 ( 0x90 , V_129 ) ;
}
if ( V_124 )
F_35 ( V_5 -> V_149 , V_150 , V_124 ) ;
if ( V_125 )
F_35 ( V_5 -> V_149 , V_151 , V_125 ) ;
F_36 ( 2 , 0xf ) ;
F_36 ( 3 , 0 ) ;
F_36 ( 4 , 0xe ) ;
V_123 = V_2 -> V_97 -> V_152 [ 0 ] / ( V_2 -> V_97 -> V_133 / 8 ) ;
if ( V_2 -> V_97 -> V_133 == 24 )
V_123 = V_123 >> ( 4 - V_130 ) ;
else
V_123 = V_123 >> ( 4 - V_130 ) ;
V_115 = V_22 -> V_115 / 8 - 1 ;
V_116 = V_22 -> V_153 / 8 - 1 ;
V_117 = V_22 -> V_154 / 8 - 1 ;
V_118 = V_22 -> V_118 / 8 - 1 ;
if ( ( V_118 & 0x07 ) == 0x06 || ( V_118 & 0x07 ) == 0x04 )
V_118 ++ ;
V_119 = V_22 -> V_119 - 1 ;
V_120 = V_22 -> V_155 - 1 ;
V_121 = V_22 -> V_156 - 1 ;
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
if ( V_2 -> V_97 -> V_133 == 24 )
V_127 [ 3 ] = ( ( ( 1 << V_130 ) * 3 ) - 1 ) | 0x80 ;
else
V_127 [ 3 ] = ( ( 1 << V_130 ) - 1 ) | 0x80 ;
V_127 [ 4 ] = 0 ;
if ( V_7 -> type == V_83 )
V_127 [ 1 ] |= 0x88 ;
V_128 = 0x05 ;
V_126 = 0x2d ;
F_3 ( V_157 , V_126 ) ;
F_17 ( V_7 , V_22 -> clock ) ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ ) {
F_38 ( V_9 , V_127 [ V_9 ] ) ;
}
if ( V_7 -> type == V_86 )
F_38 ( 24 , V_128 ) ;
if ( V_7 -> type == V_84 ) {
F_38 ( 6 , 0 ) ;
}
F_38 ( 0 , V_127 [ 0 ] ) ;
V_126 = 0x2d ;
F_3 ( V_157 , V_126 ) ;
if ( V_23 )
memcpy ( & V_7 -> V_22 , V_22 , sizeof( struct V_21 ) ) ;
F_22 ( V_2 , V_114 , V_98 , V_99 , 0 ) ;
if ( V_7 -> type == V_86 ) {
T_2 V_158 = F_5 ( V_159 ) ;
T_1 V_160 ;
F_3 ( V_64 , 0x01 ) ;
V_160 = F_7 ( V_65 ) | 0x20 ;
F_3 ( V_65 , V_160 ) ;
F_39 ( V_159 , V_158 | 0x00200000 ) ;
F_13 ( 1000 ) ;
F_39 ( V_159 , V_158 & ~ 0x00200000 ) ;
F_3 ( V_65 , V_160 & ~ 0x20 ) ;
}
if ( F_34 ( V_7 ) ) {
if ( V_7 -> V_161 >= 0x02 ) {
T_1 V_162 ;
T_2 V_163 ;
T_2 V_164 ;
if ( V_2 -> V_97 -> V_133 > 16 )
V_163 = 32 ;
else if ( V_2 -> V_97 -> V_133 > 8 )
V_163 = 16 ;
else
V_163 = 8 ;
V_164 = ( V_22 -> clock * V_163 ) / 1000 ;
if ( V_164 > 3100 )
V_162 = 0 ;
else if ( V_164 > 2600 )
V_162 = 1 ;
else if ( V_164 > 1900 )
V_162 = 2 ;
else if ( V_164 > 1160 )
V_162 = 3 ;
else if ( V_164 > 440 )
V_162 = 4 ;
else
V_162 = 5 ;
F_3 ( 0x1fde , 0x06 ) ;
F_3 ( 0x1fdf , V_162 ) ;
} else {
if ( V_7 -> V_161 >= 0x01 )
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
T_1 V_160 = 0 , V_165 = 0 ;
switch ( V_22 ) {
case V_166 :
V_160 = 0 ;
V_165 = 0 ;
F_1 ( V_2 ) ;
break;
case V_167 :
V_160 = 0x20 ;
V_165 = 0x10 ;
break;
case V_168 :
V_160 = 0x20 ;
V_165 = 0x20 ;
break;
case V_169 :
V_160 = 0x20 ;
V_165 = 0x30 ;
break;
}
#if 0
if (mode == DRM_MODE_DPMS_OFF) {
mga_suspend(crtc);
}
#endif
F_3 ( V_64 , 0x01 ) ;
V_160 |= F_7 ( V_65 ) & ~ 0x20 ;
F_4 ( V_7 ) ;
F_6 ( V_7 ) ;
F_3 ( V_65 , V_160 ) ;
F_41 ( 20 ) ;
F_3 ( V_91 , 0x01 ) ;
V_165 |= F_7 ( V_92 ) & ~ 0x30 ;
F_3 ( V_92 , V_165 ) ;
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
struct V_170 * V_171 = V_2 -> V_172 ;
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
V_171 -> V_173 ( V_2 , V_166 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_4 * V_174 , T_4 * V_175 ,
T_4 * V_176 , T_5 V_177 , T_5 V_178 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_179 = ( V_177 + V_178 > V_13 ) ? V_13 : V_177 + V_178 ;
int V_9 ;
for ( V_9 = V_177 ; V_9 < V_179 ; V_9 ++ ) {
V_3 -> V_15 [ V_9 ] = V_174 [ V_9 ] >> 8 ;
V_3 -> V_16 [ V_9 ] = V_175 [ V_9 ] >> 8 ;
V_3 -> V_17 [ V_9 ] = V_176 [ V_9 ] >> 8 ;
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
( V_180 * sizeof( struct V_181 * ) ) ,
V_182 ) ;
if ( V_3 == NULL )
return;
F_50 ( V_5 , & V_3 -> V_183 , & V_184 ) ;
F_51 ( & V_3 -> V_183 , V_13 ) ;
V_7 -> V_185 . V_2 = V_3 ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
V_3 -> V_15 [ V_9 ] = V_9 ;
V_3 -> V_16 [ V_9 ] = V_9 ;
V_3 -> V_17 [ V_9 ] = V_9 ;
}
F_52 ( & V_3 -> V_183 , & V_186 ) ;
}
void F_53 ( struct V_1 * V_2 , T_4 V_174 , T_4 V_175 ,
T_4 V_176 , int V_187 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_15 [ V_187 ] = V_174 >> 8 ;
V_3 -> V_16 [ V_187 ] = V_175 >> 8 ;
V_3 -> V_17 [ V_187 ] = V_176 >> 8 ;
}
void F_54 ( struct V_1 * V_2 , T_4 * V_174 , T_4 * V_175 ,
T_4 * V_176 , int V_187 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_174 = ( T_4 ) V_3 -> V_15 [ V_187 ] << 8 ;
* V_175 = ( T_4 ) V_3 -> V_16 [ V_187 ] << 8 ;
* V_176 = ( T_4 ) V_3 -> V_17 [ V_187 ] << 8 ;
}
static bool F_55 ( struct V_188 * V_189 ,
const struct V_21 * V_22 ,
struct V_21 * V_23 )
{
return true ;
}
static void F_56 ( struct V_188 * V_189 ,
struct V_21 * V_22 ,
struct V_21 * V_23 )
{
}
static void F_57 ( struct V_188 * V_189 , int V_190 )
{
return;
}
static void F_58 ( struct V_188 * V_189 )
{
}
static void F_59 ( struct V_188 * V_189 )
{
}
void F_60 ( struct V_188 * V_189 )
{
struct V_191 * V_191 = F_61 ( V_189 ) ;
F_62 ( V_189 ) ;
F_47 ( V_191 ) ;
}
static struct V_188 * F_63 ( struct V_4 * V_5 )
{
struct V_188 * V_189 ;
struct V_191 * V_191 ;
V_191 = F_49 ( sizeof( struct V_191 ) , V_182 ) ;
if ( ! V_191 )
return NULL ;
V_189 = & V_191 -> V_183 ;
V_189 -> V_192 = 0x1 ;
F_64 ( V_5 , V_189 , & V_193 ,
V_194 ) ;
F_65 ( V_189 , & V_195 ) ;
return V_189 ;
}
static int F_66 ( struct V_181 * V_196 )
{
struct V_197 * V_197 = F_67 ( V_196 ) ;
struct V_198 * V_198 ;
int V_107 = 0 ;
V_198 = F_68 ( V_196 , & V_197 -> V_199 -> V_200 ) ;
if ( V_198 ) {
F_69 ( V_196 , V_198 ) ;
V_107 = F_70 ( V_196 , V_198 ) ;
V_196 -> V_201 . V_202 = NULL ;
F_47 ( V_198 ) ;
}
return V_107 ;
}
static int F_71 ( struct V_181 * V_196 ,
struct V_21 * V_22 )
{
if ( V_22 -> V_203 > 2048 || V_22 -> V_204 > 4096 ||
V_22 -> V_205 > 4096 || V_22 -> V_206 > 4096 ||
V_22 -> V_207 > 2048 || V_22 -> V_208 > 4096 ||
V_22 -> V_209 > 4096 || V_22 -> V_210 > 4096 ) {
return V_211 ;
}
return V_212 ;
}
struct V_188 * F_72 ( struct V_181
* V_196 )
{
int V_213 = V_196 -> V_214 [ 0 ] ;
struct V_215 * V_102 ;
struct V_188 * V_189 ;
if ( V_213 ) {
V_102 =
F_73 ( V_196 -> V_5 , V_213 ,
V_216 ) ;
if ( ! V_102 )
return NULL ;
V_189 = F_74 ( V_102 ) ;
return V_189 ;
}
return NULL ;
}
static enum V_217 F_75 ( struct V_181
* V_196 , bool V_218 )
{
return V_219 ;
}
static void F_76 ( struct V_181 * V_196 )
{
struct V_197 * V_197 = F_67 ( V_196 ) ;
F_77 ( V_197 -> V_199 ) ;
F_78 ( V_196 ) ;
F_47 ( V_196 ) ;
}
static struct V_181 * F_79 ( struct V_4 * V_5 )
{
struct V_181 * V_196 ;
struct V_197 * V_197 ;
V_197 = F_49 ( sizeof( struct V_197 ) , V_182 ) ;
if ( ! V_197 )
return NULL ;
V_196 = & V_197 -> V_183 ;
F_80 ( V_5 , V_196 ,
& V_220 , V_221 ) ;
F_81 ( V_196 , & V_222 ) ;
V_197 -> V_199 = F_82 ( V_5 ) ;
if ( ! V_197 -> V_199 )
F_30 ( L_4 ) ;
return V_196 ;
}
int F_83 ( struct V_6 * V_7 )
{
struct V_188 * V_189 ;
struct V_181 * V_196 ;
int V_107 ;
V_7 -> V_185 . V_223 = true ;
V_7 -> V_5 -> V_224 . V_225 = V_226 ;
V_7 -> V_5 -> V_224 . V_227 = V_228 ;
V_7 -> V_5 -> V_224 . V_229 = V_7 -> V_230 . V_231 ;
F_48 ( V_7 -> V_5 ) ;
V_189 = F_63 ( V_7 -> V_5 ) ;
if ( ! V_189 ) {
F_30 ( L_5 ) ;
return - 1 ;
}
V_196 = F_79 ( V_7 -> V_5 ) ;
if ( ! V_196 ) {
F_30 ( L_6 ) ;
return - 1 ;
}
F_84 ( V_196 , V_189 ) ;
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
