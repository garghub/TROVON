static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_11 ;
if ( ! V_2 -> V_12 )
return;
F_3 ( V_13 + V_14 , 0 ) ;
if ( V_10 && V_10 -> V_15 == 16 ) {
int V_16 = ( V_10 -> V_17 == 15 ) ? 8 : 4 ;
T_1 V_18 , V_19 ;
for ( V_11 = 0 ; V_11 < V_20 ; V_11 += V_16 ) {
if ( V_10 -> V_17 == 16 ) {
if ( V_11 > ( V_20 >> 1 ) ) {
V_18 = V_19 = 0 ;
} else {
V_18 = V_3 -> V_21 [ V_11 << 1 ] ;
V_19 = V_3 -> V_22 [ V_11 << 1 ] ;
}
} else {
V_18 = V_3 -> V_21 [ V_11 ] ;
V_19 = V_3 -> V_22 [ V_11 ] ;
}
F_3 ( V_13 + V_23 , V_18 ) ;
F_3 ( V_13 + V_23 , V_3 -> V_24 [ V_11 ] ) ;
F_3 ( V_13 + V_23 , V_19 ) ;
}
return;
}
for ( V_11 = 0 ; V_11 < V_20 ; V_11 ++ ) {
F_3 ( V_13 + V_23 , V_3 -> V_21 [ V_11 ] ) ;
F_3 ( V_13 + V_23 , V_3 -> V_24 [ V_11 ] ) ;
F_3 ( V_13 + V_23 , V_3 -> V_22 [ V_11 ] ) ;
}
}
static inline void F_4 ( struct V_6 * V_7 )
{
unsigned long V_25 = V_26 + V_27 / 10 ;
unsigned int V_28 = 0 ;
do {
V_28 = F_5 ( V_29 ) ;
} while ( ( V_28 & 0x08 ) && F_6 ( V_26 , V_25 ) );
V_25 = V_26 + V_27 / 10 ;
V_28 = 0 ;
do {
V_28 = F_5 ( V_29 ) ;
} while ( ! ( V_28 & 0x08 ) && F_6 ( V_26 , V_25 ) );
}
static inline void F_7 ( struct V_6 * V_7 )
{
unsigned long V_25 = V_26 + V_27 ;
unsigned int V_28 = 0 ;
do {
V_28 = F_8 ( V_29 + 2 ) ;
} while ( ( V_28 & 0x01 ) && F_6 ( V_26 , V_25 ) );
}
static bool F_9 ( struct V_1 * V_2 ,
const struct V_30 * V_31 ,
struct V_30 * V_32 )
{
return true ;
}
static int F_10 ( struct V_6 * V_7 , long clock )
{
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 , V_37 , V_38 ;
unsigned int V_39 , V_40 , V_41 ;
unsigned int V_42 , V_43 , V_44 ;
unsigned int V_45 ;
V_43 = V_44 = V_42 = 0 ;
V_33 = 320000 ;
V_34 = 160000 ;
V_35 = 25000 ;
V_36 = 0xffffffff ;
V_38 = clock * 5 / 1000 ;
for ( V_39 = 8 ; V_39 > 0 ; V_39 /= 2 ) {
if ( clock * V_39 > V_33 )
continue;
if ( clock * V_39 < V_34 )
continue;
for ( V_41 = 17 ; V_41 < 256 ; V_41 ++ ) {
for ( V_40 = 1 ; V_40 < 32 ; V_40 ++ ) {
V_45 = ( V_35 * V_41 ) /
( V_40 * V_39 ) ;
if ( V_45 > clock )
V_37 = V_45 - clock ;
else
V_37 = clock - V_45 ;
if ( V_37 < V_36 ) {
V_36 = V_37 ;
V_43 = V_40 - 1 ;
V_44 = V_41 - 1 ;
V_42 = V_39 - 1 ;
}
}
}
}
if ( V_36 > V_38 ) {
F_11 ( V_46 L_1 ) ;
return 1 ;
}
F_12 ( V_47 , V_43 ) ;
F_12 ( V_48 , V_44 ) ;
F_12 ( V_49 , V_42 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , long clock )
{
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 , V_37 , V_38 ;
unsigned int V_39 , V_40 , V_41 ;
unsigned int V_42 , V_43 , V_44 ;
unsigned int V_45 ;
int V_11 , V_50 , V_51 , V_52 ;
bool V_53 = false ;
T_1 V_54 ;
V_43 = V_44 = V_42 = 0 ;
V_33 = 550000 ;
V_34 = 150000 ;
V_35 = 48000 ;
V_36 = 0xffffffff ;
V_38 = clock * 5 / 1000 ;
for ( V_39 = 1 ; V_39 < 9 ; V_39 ++ ) {
if ( clock * V_39 > V_33 )
continue;
if ( clock * V_39 < V_34 )
continue;
for ( V_40 = 1 ; V_40 < 17 ; V_40 ++ ) {
for ( V_41 = 1 ; V_41 < 151 ; V_41 ++ ) {
V_45 = ( V_35 * V_41 ) /
( V_40 * V_39 ) ;
if ( V_45 > clock )
V_37 = V_45 - clock ;
else
V_37 = clock - V_45 ;
if ( V_37 < V_36 ) {
V_36 = V_37 ;
V_44 = V_41 - 1 ;
V_43 = ( V_40 - 1 ) | ( ( V_44 >> 1 ) & 0x80 ) ;
V_42 = V_39 - 1 ;
}
}
}
}
for ( V_11 = 0 ; V_11 <= 32 && V_53 == false ; V_11 ++ ) {
if ( V_11 > 0 ) {
F_3 ( V_55 , 0x1e ) ;
V_54 = F_8 ( V_56 ) ;
if ( V_54 < 0xff )
F_3 ( V_56 , V_54 + 1 ) ;
}
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= V_59 ;
F_3 ( V_58 , V_54 ) ;
F_3 ( V_13 , V_60 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= V_61 ;
F_3 ( V_58 , V_54 ) ;
V_54 = F_8 ( V_62 ) ;
V_54 |= 0x3 << 2 ;
F_3 ( V_63 , V_54 ) ;
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= V_64 | 0x80 ;
F_3 ( V_58 , V_54 ) ;
F_14 ( 500 ) ;
F_3 ( V_13 , V_65 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ 0x04 ;
F_3 ( V_58 , V_54 ) ;
F_14 ( 50 ) ;
F_12 ( V_66 , V_44 ) ;
F_12 ( V_67 , V_43 ) ;
F_12 ( V_68 , V_42 ) ;
F_14 ( 50 ) ;
F_3 ( V_13 , V_65 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= 0x04 ;
F_12 ( V_65 , V_54 ) ;
F_14 ( 500 ) ;
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ V_69 ;
V_54 |= V_70 ;
F_3 ( V_58 , V_54 ) ;
F_3 ( V_13 , V_60 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ V_71 ;
V_54 |= V_72 ;
F_3 ( V_58 , V_54 ) ;
F_3 ( V_73 , 1 ) ;
V_54 = F_8 ( V_74 ) ;
V_54 &= ~ 0x8 ;
F_3 ( V_74 , V_54 ) ;
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ V_59 ;
F_3 ( V_58 , V_54 ) ;
V_52 = F_8 ( V_75 ) ;
for ( V_50 = 0 ; V_50 < 30 && V_53 == false ; V_50 ++ ) {
V_51 = F_8 ( V_75 ) ;
if ( V_51 < V_52 )
V_52 = 0 ;
if ( ( V_51 - V_52 ) > 2 )
V_53 = true ;
else
F_14 ( 5 ) ;
}
}
F_3 ( V_13 , V_60 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ V_61 ;
F_12 ( V_60 , V_54 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , long clock )
{
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 , V_37 , V_38 ;
unsigned int V_39 , V_40 , V_41 ;
unsigned int V_42 , V_43 , V_44 ;
unsigned int V_45 ;
T_1 V_54 ;
V_43 = V_44 = V_42 = 0 ;
V_33 = 550000 ;
V_34 = 150000 ;
V_35 = 50000 ;
V_36 = 0xffffffff ;
V_38 = clock * 5 / 1000 ;
for ( V_39 = 16 ; V_39 > 0 ; V_39 -- ) {
if ( clock * V_39 > V_33 )
continue;
if ( clock * V_39 < V_34 )
continue;
for ( V_41 = 1 ; V_41 < 257 ; V_41 ++ ) {
for ( V_40 = 1 ; V_40 < 17 ; V_40 ++ ) {
V_45 = ( V_35 * V_41 ) /
( V_40 * V_39 ) ;
if ( V_45 > clock )
V_37 = V_45 - clock ;
else
V_37 = clock - V_45 ;
if ( V_37 < V_36 ) {
V_36 = V_37 ;
V_44 = V_41 - 1 ;
V_43 = V_40 - 1 ;
V_42 = V_39 - 1 ;
}
}
}
}
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= V_59 ;
F_3 ( V_58 , V_54 ) ;
V_54 = F_8 ( V_62 ) ;
V_54 |= 0x3 << 2 ;
F_3 ( V_63 , V_54 ) ;
F_3 ( V_13 , V_76 ) ;
V_54 = F_8 ( V_58 ) ;
F_3 ( V_58 , V_54 & ~ 0x40 ) ;
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= V_64 ;
F_3 ( V_58 , V_54 ) ;
F_12 ( V_77 , V_43 ) ;
F_12 ( V_78 , V_44 ) ;
F_12 ( V_79 , V_42 ) ;
F_14 ( 50 ) ;
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ V_64 ;
F_3 ( V_58 , V_54 ) ;
F_14 ( 500 ) ;
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ V_69 ;
V_54 |= V_70 ;
F_3 ( V_58 , V_54 ) ;
F_3 ( V_13 , V_76 ) ;
V_54 = F_8 ( V_58 ) ;
F_3 ( V_58 , V_54 | 0x40 ) ;
V_54 = F_8 ( V_62 ) ;
V_54 |= ( 0x3 << 2 ) ;
F_3 ( V_63 , V_54 ) ;
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ V_59 ;
F_3 ( V_58 , V_54 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , long clock )
{
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 , V_37 , V_38 ;
unsigned int V_39 , V_40 , V_41 ;
unsigned int V_42 , V_43 , V_44 ;
unsigned int V_45 ;
int V_11 , V_50 , V_51 , V_52 ;
T_1 V_54 ;
bool V_53 = false ;
V_43 = V_44 = V_42 = 0 ;
V_33 = 800000 ;
V_34 = 400000 ;
V_35 = 33333 ;
V_36 = 0xffffffff ;
V_38 = clock * 5 / 1000 ;
for ( V_39 = 16 ; V_39 > 0 ; V_39 >>= 1 ) {
if ( clock * V_39 > V_33 )
continue;
if ( clock * V_39 < V_34 )
continue;
for ( V_40 = 1 ; V_40 < 33 ; V_40 ++ ) {
for ( V_41 = 17 ; V_41 < 257 ; V_41 ++ ) {
V_45 = ( V_35 * V_41 ) /
( V_40 * V_39 ) ;
if ( V_45 > clock )
V_37 = V_45 - clock ;
else
V_37 = clock - V_45 ;
if ( V_37 < V_36 ) {
V_36 = V_37 ;
V_44 = V_41 - 1 ;
V_43 = ( V_40 - 1 ) ;
V_42 = V_39 - 1 ;
}
if ( ( clock * V_39 ) >= 600000 )
V_42 |= 0x80 ;
}
}
}
for ( V_11 = 0 ; V_11 <= 32 && V_53 == false ; V_11 ++ ) {
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= V_59 ;
F_3 ( V_58 , V_54 ) ;
V_54 = F_8 ( V_62 ) ;
V_54 |= 0x3 << 2 ;
F_3 ( V_63 , V_54 ) ;
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= V_64 ;
F_3 ( V_58 , V_54 ) ;
F_14 ( 500 ) ;
F_12 ( V_80 , V_43 ) ;
F_12 ( V_81 , V_44 ) ;
F_12 ( V_82 , V_42 ) ;
F_14 ( 500 ) ;
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ V_69 ;
V_54 |= V_70 ;
F_3 ( V_58 , V_54 ) ;
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ V_59 ;
V_54 &= ~ V_64 ;
F_3 ( V_58 , V_54 ) ;
V_52 = F_8 ( V_75 ) ;
for ( V_50 = 0 ; V_50 < 30 && V_53 == false ; V_50 ++ ) {
V_51 = F_8 ( V_75 ) ;
if ( V_51 < V_52 )
V_52 = 0 ;
if ( ( V_51 - V_52 ) > 2 )
V_53 = true ;
else
F_14 ( 5 ) ;
}
}
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , long clock )
{
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 , V_37 ;
int V_83 , V_41 , V_40 , V_84 ;
unsigned int V_42 , V_43 , V_44 ;
unsigned int V_45 , V_85 ;
int V_54 ;
const unsigned int V_86 [] = { 1 , 2 , 4 , 8 } ;
V_43 = V_44 = V_42 = 0 ;
V_33 = 1488000 ;
V_34 = 1056000 ;
V_35 = 48000 ;
V_36 = 0xffffffff ;
for ( V_83 = 0 ; V_83 < 4 ; V_83 ++ ) {
if ( V_36 == 0 )
break;
for ( V_41 = 5 ; V_41 < 129 ; V_41 ++ ) {
if ( V_36 == 0 )
break;
for ( V_40 = 3 ; V_40 >= 0 ; V_40 -- ) {
if ( V_36 == 0 )
break;
for ( V_84 = 5 ; V_84 < 33 ; V_84 ++ ) {
V_85 = V_35 * ( V_41 + 1 ) /
( V_83 + 1 ) ;
if ( V_85 < V_34 )
continue;
if ( V_85 > V_33 )
continue;
V_45 = V_85 / ( V_86 [ V_40 ] * ( V_84 + 1 ) ) ;
if ( V_45 > clock )
V_37 = V_45 - clock ;
else
V_37 = clock - V_45 ;
if ( V_37 < V_36 ) {
V_36 = V_37 ;
V_43 = V_40 | ( V_84 << 3 ) ;
V_44 = V_41 ;
V_42 = V_83 | ( V_83 << 3 ) ;
}
}
}
}
}
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= V_59 ;
F_3 ( V_58 , V_54 ) ;
F_3 ( V_13 , V_60 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= V_61 ;
F_3 ( V_58 , V_54 ) ;
V_54 = F_8 ( V_62 ) ;
V_54 |= ( 0x3 << 2 ) | 0xc0 ;
F_3 ( V_63 , V_54 ) ;
F_3 ( V_13 , V_57 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ V_59 ;
V_54 |= V_64 ;
F_3 ( V_58 , V_54 ) ;
F_14 ( 500 ) ;
F_12 ( V_87 , V_44 ) ;
F_12 ( V_88 , V_43 ) ;
F_12 ( V_89 , V_42 ) ;
F_14 ( 50 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , long clock )
{
switch( V_7 -> type ) {
case V_90 :
case V_91 :
return F_10 ( V_7 , clock ) ;
break;
case V_92 :
return F_13 ( V_7 , clock ) ;
break;
case V_93 :
return F_15 ( V_7 , clock ) ;
break;
case V_94 :
return F_16 ( V_7 , clock ) ;
break;
case V_95 :
return F_17 ( V_7 , clock ) ;
break;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_1 V_54 ;
int V_96 ;
F_3 ( V_13 , V_97 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= 0x10 ;
F_12 ( V_97 , V_54 ) ;
F_3 ( V_13 , V_98 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= 0x10 ;
F_12 ( V_98 , V_54 ) ;
F_3 ( V_13 , V_99 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= 0x80 ;
F_12 ( V_99 , V_54 ) ;
V_96 = 300 ;
while ( ! ( V_54 & 0x1 ) && V_96 ) {
F_3 ( V_13 , V_99 ) ;
V_54 = F_8 ( V_58 ) ;
F_14 ( 1000 ) ;
V_96 -- ;
}
if ( V_96 ) {
V_96 = 300 ;
while ( ( V_54 & 0x2 ) && V_96 ) {
F_3 ( V_13 , V_99 ) ;
V_54 = F_8 ( V_58 ) ;
F_14 ( 1000 ) ;
V_96 -- ;
}
}
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_54 ;
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
F_3 ( V_100 , 1 ) ;
V_54 = F_8 ( V_101 ) ;
F_3 ( V_101 , V_54 | 0x88 ) ;
F_3 ( V_13 , V_102 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 |= 0x8 ;
F_3 ( V_58 , V_54 ) ;
F_14 ( 10 ) ;
V_54 &= ~ 0x08 ;
F_3 ( V_13 , V_102 ) ;
F_3 ( V_58 , V_54 ) ;
F_3 ( V_13 , V_99 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ 0x80 ;
F_3 ( V_58 , V_54 ) ;
F_3 ( V_13 , V_98 ) ;
V_54 = F_8 ( V_58 ) ;
V_54 &= ~ 0x10 ;
F_12 ( V_98 , V_54 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned V_103 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_2 V_104 ;
int V_105 ;
T_1 V_106 ;
while ( F_8 ( 0x1fda ) & 0x08 ) ;
while ( ! ( F_8 ( 0x1fda ) & 0x08 ) ) ;
V_105 = F_8 ( V_75 ) + 2 ;
while ( F_8 ( V_75 ) < V_105 ) ;
F_3 ( V_100 , 0 ) ;
V_106 = F_8 ( V_101 ) ;
V_106 &= 0xB0 ;
V_104 = V_103 / 8 ;
F_22 ( V_104 > 0x1fffff ) ;
V_106 |= ( ! ! ( V_104 & ( 1 << 20 ) ) ) << 6 ;
F_23 ( 0x0d , ( T_1 ) ( V_104 & 0xff ) ) ;
F_23 ( 0x0c , ( T_1 ) ( V_104 >> 8 ) & 0xff ) ;
F_24 ( 0x0 , ( ( T_1 ) ( V_104 >> 16 ) & 0xf ) | V_106 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
int V_107 , int V_108 , int V_109 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_114 * V_115 ;
int V_116 ;
T_3 V_117 ;
if ( ! V_109 && V_10 ) {
V_113 = F_26 ( V_10 ) ;
V_111 = V_113 -> V_111 ;
V_115 = F_27 ( V_111 ) ;
V_116 = F_28 ( V_115 , false ) ;
if ( V_116 )
return V_116 ;
F_29 ( V_115 ) ;
F_30 ( V_115 ) ;
}
V_113 = F_26 ( V_2 -> V_10 ) ;
V_111 = V_113 -> V_111 ;
V_115 = F_27 ( V_111 ) ;
V_116 = F_28 ( V_115 , false ) ;
if ( V_116 )
return V_116 ;
V_116 = F_31 ( V_115 , V_118 , & V_117 ) ;
if ( V_116 ) {
F_30 ( V_115 ) ;
return V_116 ;
}
if ( & V_7 -> V_119 -> V_120 == V_113 ) {
V_116 = F_32 ( & V_115 -> V_115 , 0 , V_115 -> V_115 . V_121 , & V_115 -> V_122 ) ;
if ( V_116 )
F_33 ( L_2 ) ;
}
F_30 ( V_115 ) ;
F_21 ( V_2 , ( T_2 ) V_117 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_107 , int V_108 ,
struct V_9 * V_123 )
{
return F_25 ( V_2 , V_123 , V_107 , V_108 , 0 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_30 * V_32 ,
int V_107 , int V_108 , struct V_9 * V_123 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_124 , V_125 , V_126 , V_127 ;
int V_128 , V_129 , V_130 , V_131 ;
int V_132 ;
int V_133 = 0 , V_134 = 0 ;
int V_11 ;
unsigned char V_135 = 0 ;
unsigned char V_136 [ 6 ] ;
T_1 V_137 ;
static unsigned char V_138 [] = {
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
V_137 = V_7 -> V_139 [ ( V_2 -> V_10 -> V_15 >> 3 ) - 1 ] ;
switch ( V_7 -> type ) {
case V_90 :
case V_91 :
V_138 [ V_65 ] = 0x03 ;
V_138 [ V_57 ] = V_70 ;
V_138 [ V_140 ] = V_141 |
V_142 |
V_143 ;
if ( V_7 -> V_144 )
V_133 = 0x40049120 ;
else
V_133 = 0x4004d120 ;
V_134 = 0x00008000 ;
break;
case V_92 :
V_138 [ V_65 ] = 0x07 ;
V_133 = 0x41049120 ;
V_134 = 0x0000b000 ;
break;
case V_93 :
V_138 [ V_57 ] = V_70 ;
V_138 [ V_140 ] = V_142 |
V_143 ;
V_133 = 0x00000120 ;
V_134 = 0x0000b000 ;
break;
case V_94 :
V_138 [ V_140 ] = V_142 |
V_143 ;
V_133 = 0x00000120 ;
V_134 = 0x0000b000 ;
break;
case V_95 :
break;
}
switch ( V_2 -> V_10 -> V_15 ) {
case 8 :
V_138 [ V_145 ] = V_146 ;
break;
case 16 :
if ( V_2 -> V_10 -> V_17 == 15 )
V_138 [ V_145 ] = V_147 ;
else
V_138 [ V_145 ] = V_148 ;
break;
case 24 :
V_138 [ V_145 ] = V_149 ;
break;
case 32 :
V_138 [ V_145 ] = V_150 ;
break;
}
if ( V_31 -> V_151 & V_152 )
V_135 |= 0x40 ;
if ( V_31 -> V_151 & V_153 )
V_135 |= 0x80 ;
for ( V_11 = 0 ; V_11 < sizeof( V_138 ) ; V_11 ++ ) {
if ( ( V_11 <= 0x17 ) ||
( V_11 == 0x1b ) ||
( V_11 == 0x1c ) ||
( ( V_11 >= 0x1f ) && ( V_11 <= 0x29 ) ) ||
( ( V_11 >= 0x30 ) && ( V_11 <= 0x37 ) ) )
continue;
if ( F_36 ( V_7 ) &&
( ( V_11 == 0x2c ) || ( V_11 == 0x2d ) || ( V_11 == 0x2e ) ) )
continue;
if ( ( V_7 -> type == V_93 || V_7 -> type == V_92 || V_7 -> type == V_94 ) &&
( V_11 >= 0x44 ) && ( V_11 <= 0x4e ) )
continue;
F_12 ( V_11 , V_138 [ V_11 ] ) ;
}
if ( V_7 -> type == V_95 )
F_12 ( 0x90 , 0 ) ;
if ( V_133 )
F_37 ( V_5 -> V_154 , V_155 , V_133 ) ;
if ( V_134 )
F_37 ( V_5 -> V_154 , V_156 , V_134 ) ;
F_38 ( 2 , 0xf ) ;
F_38 ( 3 , 0 ) ;
F_38 ( 4 , 0xe ) ;
V_132 = V_2 -> V_10 -> V_157 [ 0 ] / ( V_2 -> V_10 -> V_15 / 8 ) ;
if ( V_2 -> V_10 -> V_15 == 24 )
V_132 = ( V_132 * 3 ) >> ( 4 - V_137 ) ;
else
V_132 = V_132 >> ( 4 - V_137 ) ;
V_124 = V_31 -> V_124 / 8 - 1 ;
V_125 = V_31 -> V_158 / 8 - 1 ;
V_126 = V_31 -> V_159 / 8 - 1 ;
V_127 = V_31 -> V_127 / 8 - 1 ;
if ( ( V_127 & 0x07 ) == 0x06 || ( V_127 & 0x07 ) == 0x04 )
V_127 ++ ;
V_128 = V_31 -> V_128 - 1 ;
V_129 = V_31 -> V_160 - 1 ;
V_130 = V_31 -> V_161 - 1 ;
V_131 = V_31 -> V_131 - 2 ;
F_39 ( 0 , 0 ) ;
F_39 ( 1 , 0 ) ;
F_39 ( 2 , 0 ) ;
F_39 ( 3 , 0 ) ;
F_39 ( 4 , 0 ) ;
F_39 ( 5 , 0x40 ) ;
F_39 ( 6 , 0x5 ) ;
F_39 ( 7 , 0xf ) ;
F_39 ( 8 , 0xf ) ;
F_23 ( 0 , V_127 - 4 ) ;
F_23 ( 1 , V_124 ) ;
F_23 ( 2 , V_124 ) ;
F_23 ( 3 , ( V_127 & 0x1F ) | 0x80 ) ;
F_23 ( 4 , V_125 ) ;
F_23 ( 5 , ( ( V_127 & 0x20 ) << 2 ) | ( V_126 & 0x1F ) ) ;
F_23 ( 6 , V_131 & 0xFF ) ;
F_23 ( 7 , ( ( V_131 & 0x100 ) >> 8 ) |
( ( V_128 & 0x100 ) >> 7 ) |
( ( V_129 & 0x100 ) >> 6 ) |
( ( V_128 & 0x100 ) >> 5 ) |
( ( V_128 & 0x100 ) >> 4 ) |
( ( V_131 & 0x200 ) >> 4 ) |
( ( V_128 & 0x200 ) >> 3 ) |
( ( V_129 & 0x200 ) >> 2 ) ) ;
F_23 ( 9 , ( ( V_128 & 0x200 ) >> 4 ) |
( ( V_128 & 0x200 ) >> 3 ) ) ;
F_23 ( 10 , 0 ) ;
F_23 ( 11 , 0 ) ;
F_23 ( 12 , 0 ) ;
F_23 ( 13 , 0 ) ;
F_23 ( 14 , 0 ) ;
F_23 ( 15 , 0 ) ;
F_23 ( 16 , V_129 & 0xFF ) ;
F_23 ( 17 , ( V_130 & 0x0F ) | 0x20 ) ;
F_23 ( 18 , V_128 & 0xFF ) ;
F_23 ( 19 , V_132 & 0xFF ) ;
F_23 ( 20 , 0 ) ;
F_23 ( 21 , V_128 & 0xFF ) ;
F_23 ( 22 , ( V_131 + 1 ) & 0xFF ) ;
F_23 ( 23 , 0xc3 ) ;
F_23 ( 24 , V_128 & 0xFF ) ;
V_136 [ 0 ] = 0 ;
V_136 [ 5 ] = 0 ;
V_136 [ 0 ] |= ( V_132 & 0x300 ) >> 4 ;
V_136 [ 1 ] = ( ( ( V_127 - 4 ) & 0x100 ) >> 8 ) |
( ( V_124 & 0x100 ) >> 7 ) |
( ( V_125 & 0x100 ) >> 6 ) |
( V_127 & 0x40 ) ;
V_136 [ 2 ] = ( ( V_131 & 0xc00 ) >> 10 ) |
( ( V_128 & 0x400 ) >> 8 ) |
( ( V_128 & 0xc00 ) >> 7 ) |
( ( V_129 & 0xc00 ) >> 5 ) |
( ( V_128 & 0x400 ) >> 3 ) ;
if ( V_2 -> V_10 -> V_15 == 24 )
V_136 [ 3 ] = ( ( ( 1 << V_137 ) * 3 ) - 1 ) | 0x80 ;
else
V_136 [ 3 ] = ( ( 1 << V_137 ) - 1 ) | 0x80 ;
V_136 [ 4 ] = 0 ;
if ( V_7 -> type == V_92 )
V_136 [ 1 ] |= 0x88 ;
V_135 = 0x2d ;
F_3 ( V_162 , V_135 ) ;
F_18 ( V_7 , V_31 -> clock ) ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
F_24 ( V_11 , V_136 [ V_11 ] ) ;
}
if ( V_7 -> type == V_95 )
F_24 ( 0x24 , 0x5 ) ;
if ( V_7 -> type == V_93 ) {
F_24 ( 6 , 0 ) ;
}
F_24 ( 0 , V_136 [ 0 ] ) ;
V_135 = 0x2d ;
F_3 ( V_162 , V_135 ) ;
if ( V_32 )
memcpy ( & V_7 -> V_31 , V_31 , sizeof( struct V_30 ) ) ;
F_25 ( V_2 , V_123 , V_107 , V_108 , 0 ) ;
if ( V_7 -> type == V_95 ) {
T_2 V_163 = F_5 ( V_164 ) ;
T_1 V_165 ;
F_3 ( V_73 , 0x01 ) ;
V_165 = F_8 ( V_74 ) | 0x20 ;
F_3 ( V_74 , V_165 ) ;
F_40 ( V_164 , V_163 | 0x00200000 ) ;
F_14 ( 1000 ) ;
F_40 ( V_164 , V_163 & ~ 0x00200000 ) ;
F_3 ( V_74 , V_165 & ~ 0x20 ) ;
}
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_166 >= 0x02 ) {
T_1 V_167 ;
T_2 V_168 ;
T_2 V_169 ;
if ( V_2 -> V_10 -> V_15 > 16 )
V_168 = 32 ;
else if ( V_2 -> V_10 -> V_15 > 8 )
V_168 = 16 ;
else
V_168 = 8 ;
V_169 = ( V_31 -> clock * V_168 ) / 1000 ;
if ( V_169 > 3100 )
V_167 = 0 ;
else if ( V_169 > 2600 )
V_167 = 1 ;
else if ( V_169 > 1900 )
V_167 = 2 ;
else if ( V_169 > 1160 )
V_167 = 3 ;
else if ( V_169 > 440 )
V_167 = 4 ;
else
V_167 = 5 ;
F_3 ( V_100 , 0x06 ) ;
F_3 ( V_101 , V_167 ) ;
} else {
F_3 ( V_100 , 0x06 ) ;
if ( V_7 -> V_166 >= 0x01 )
F_3 ( V_101 , 0x03 ) ;
else
F_3 ( V_101 , 0x04 ) ;
}
}
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , int V_31 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_165 = 0 , V_170 = 0 ;
switch ( V_31 ) {
case V_171 :
V_165 = 0 ;
V_170 = 0 ;
F_1 ( V_2 ) ;
break;
case V_172 :
V_165 = 0x20 ;
V_170 = 0x10 ;
break;
case V_173 :
V_165 = 0x20 ;
V_170 = 0x20 ;
break;
case V_174 :
V_165 = 0x20 ;
V_170 = 0x30 ;
break;
}
#if 0
if (mode == DRM_MODE_DPMS_OFF) {
mga_suspend(crtc);
}
#endif
F_3 ( V_73 , 0x01 ) ;
V_165 |= F_8 ( V_74 ) & ~ 0x20 ;
F_4 ( V_7 ) ;
F_7 ( V_7 ) ;
F_3 ( V_74 , V_165 ) ;
F_42 ( 20 ) ;
F_3 ( V_100 , 0x01 ) ;
V_170 |= F_8 ( V_101 ) & ~ 0x30 ;
F_3 ( V_101 , V_170 ) ;
#if 0
if (mode == DRM_MODE_DPMS_ON && mdev->suspended == true) {
mga_resume(crtc);
drm_helper_resume_force_mode(dev);
}
#endif
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_54 ;
F_3 ( V_55 , 0x11 ) ;
V_54 = F_8 ( V_56 ) ;
F_23 ( 0x11 , V_54 | 0x80 ) ;
if ( V_7 -> type == V_90 || V_7 -> type == V_91 ) {
F_38 ( 0 , 1 ) ;
F_42 ( 50 ) ;
F_38 ( 1 , 0x20 ) ;
F_42 ( 20 ) ;
} else {
F_3 ( V_73 , 0x1 ) ;
V_54 = F_8 ( V_74 ) ;
F_38 ( 0 , 1 ) ;
F_38 ( 1 , V_54 | 0x20 ) ;
}
if ( V_7 -> type == V_92 )
F_19 ( V_2 ) ;
F_23 ( 17 , 0 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_175 * V_176 = V_2 -> V_177 ;
T_1 V_54 ;
if ( V_7 -> type == V_92 )
F_20 ( V_2 ) ;
if ( V_7 -> type == V_90 || V_7 -> type == V_91 ) {
F_42 ( 50 ) ;
F_38 ( 1 , 0x0 ) ;
F_42 ( 20 ) ;
F_38 ( 0 , 0x3 ) ;
} else {
F_3 ( V_73 , 0x1 ) ;
V_54 = F_8 ( V_74 ) ;
V_54 &= ~ 0x20 ;
F_38 ( 0x1 , V_54 ) ;
F_38 ( 0 , 3 ) ;
}
V_176 -> V_178 ( V_2 , V_171 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_4 * V_179 , T_4 * V_180 ,
T_4 * V_181 , T_5 V_182 , T_5 V_183 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_184 = ( V_182 + V_183 > V_20 ) ? V_20 : V_182 + V_183 ;
int V_11 ;
for ( V_11 = V_182 ; V_11 < V_184 ; V_11 ++ ) {
V_3 -> V_21 [ V_11 ] = V_179 [ V_11 ] >> 8 ;
V_3 -> V_24 [ V_11 ] = V_180 [ V_11 ] >> 8 ;
V_3 -> V_22 [ V_11 ] = V_181 [ V_11 ] >> 8 ;
}
F_1 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_3 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
int V_116 ;
F_50 ( L_3 ) ;
F_41 ( V_2 , V_174 ) ;
if ( V_2 -> V_10 ) {
struct V_112 * V_113 = F_26 ( V_2 -> V_10 ) ;
struct V_110 * V_111 = V_113 -> V_111 ;
struct V_114 * V_115 = F_27 ( V_111 ) ;
V_116 = F_28 ( V_115 , false ) ;
if ( V_116 )
return;
F_29 ( V_115 ) ;
F_30 ( V_115 ) ;
}
V_2 -> V_10 = NULL ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_3 * V_3 ;
int V_11 ;
V_3 = F_52 ( sizeof( struct V_3 ) +
( V_185 * sizeof( struct V_186 * ) ) ,
V_187 ) ;
if ( V_3 == NULL )
return;
F_53 ( V_7 -> V_5 , & V_3 -> V_188 , & V_189 ) ;
F_54 ( & V_3 -> V_188 , V_20 ) ;
V_7 -> V_190 . V_2 = V_3 ;
for ( V_11 = 0 ; V_11 < V_20 ; V_11 ++ ) {
V_3 -> V_21 [ V_11 ] = V_11 ;
V_3 -> V_24 [ V_11 ] = V_11 ;
V_3 -> V_22 [ V_11 ] = V_11 ;
}
F_55 ( & V_3 -> V_188 , & V_191 ) ;
}
void F_56 ( struct V_1 * V_2 , T_4 V_179 , T_4 V_180 ,
T_4 V_181 , int V_192 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_21 [ V_192 ] = V_179 >> 8 ;
V_3 -> V_24 [ V_192 ] = V_180 >> 8 ;
V_3 -> V_22 [ V_192 ] = V_181 >> 8 ;
}
void F_57 ( struct V_1 * V_2 , T_4 * V_179 , T_4 * V_180 ,
T_4 * V_181 , int V_192 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_179 = ( T_4 ) V_3 -> V_21 [ V_192 ] << 8 ;
* V_180 = ( T_4 ) V_3 -> V_24 [ V_192 ] << 8 ;
* V_181 = ( T_4 ) V_3 -> V_22 [ V_192 ] << 8 ;
}
static bool F_58 ( struct V_193 * V_194 ,
const struct V_30 * V_31 ,
struct V_30 * V_32 )
{
return true ;
}
static void F_59 ( struct V_193 * V_194 ,
struct V_30 * V_31 ,
struct V_30 * V_32 )
{
}
static void F_60 ( struct V_193 * V_194 , int V_195 )
{
return;
}
static void F_61 ( struct V_193 * V_194 )
{
}
static void F_62 ( struct V_193 * V_194 )
{
}
static void F_63 ( struct V_193 * V_194 )
{
struct V_196 * V_196 = F_64 ( V_194 ) ;
F_65 ( V_194 ) ;
F_48 ( V_196 ) ;
}
static struct V_193 * F_66 ( struct V_4 * V_5 )
{
struct V_193 * V_194 ;
struct V_196 * V_196 ;
V_196 = F_52 ( sizeof( struct V_196 ) , V_187 ) ;
if ( ! V_196 )
return NULL ;
V_194 = & V_196 -> V_188 ;
V_194 -> V_197 = 0x1 ;
F_67 ( V_5 , V_194 , & V_198 ,
V_199 ) ;
F_68 ( V_194 , & V_200 ) ;
return V_194 ;
}
static int F_69 ( struct V_186 * V_201 )
{
struct V_202 * V_202 = F_70 ( V_201 ) ;
struct V_203 * V_203 ;
int V_116 = 0 ;
V_203 = F_71 ( V_201 , & V_202 -> V_204 -> V_205 ) ;
if ( V_203 ) {
F_72 ( V_201 , V_203 ) ;
V_116 = F_73 ( V_201 , V_203 ) ;
F_48 ( V_203 ) ;
}
return V_116 ;
}
static T_5 F_74 ( struct V_30 * V_31 ,
int V_15 )
{
T_5 V_206 , V_207 ;
T_6 V_208 , V_209 , V_210 ;
T_7 V_211 = ( V_15 + 7 ) / 8 ;
V_207 = 1024 ;
if ( ! V_31 -> V_127 || ! V_31 -> V_131 || ! V_31 -> clock )
return 0 ;
V_208 = V_31 -> V_124 * V_31 -> V_128 ;
V_206 = V_31 -> V_127 * V_31 -> V_131 ;
V_209 = V_208 * V_31 -> clock * 1000 ;
F_75 ( V_209 , V_206 ) ;
V_210 = V_209 * V_211 * 100 ;
F_75 ( V_210 , V_207 ) ;
return ( T_5 ) ( V_210 ) ;
}
static int F_76 ( struct V_186 * V_201 ,
struct V_30 * V_31 )
{
struct V_4 * V_5 = V_201 -> V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_5 -> V_8 ;
struct V_212 * V_119 = V_7 -> V_119 ;
struct V_213 * V_214 = & V_119 -> V_215 ;
struct V_216 * V_217 = NULL ;
int V_168 = 32 ;
int V_11 = 0 ;
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_166 == 0x01 ) {
if ( V_31 -> V_124 > 1600 )
return V_218 ;
if ( V_31 -> V_128 > 1200 )
return V_219 ;
if ( F_74 ( V_31 , V_168 )
> ( 24400 * 1024 ) )
return V_220 ;
} else if ( V_7 -> V_166 >= 0x02 ) {
if ( V_31 -> V_124 > 1920 )
return V_218 ;
if ( V_31 -> V_128 > 1200 )
return V_219 ;
if ( F_74 ( V_31 , V_168 )
> ( 30100 * 1024 ) )
return V_220 ;
}
} else if ( V_7 -> type == V_92 ) {
if ( V_31 -> V_124 > 1280 )
return V_218 ;
if ( V_31 -> V_128 > 1024 )
return V_219 ;
if ( F_74 ( V_31 ,
V_168 > ( 31877 * 1024 ) ) )
return V_220 ;
} else if ( V_7 -> type == V_93 &&
( F_74 ( V_31 , V_168 )
> ( 32700 * 1024 ) ) ) {
return V_220 ;
} else if ( V_7 -> type == V_94 &&
( F_74 ( V_31 , V_168 )
> ( 37500 * 1024 ) ) ) {
return V_220 ;
} else if ( V_7 -> type == V_95 &&
( F_74 ( V_31 ,
V_168 ) > ( 55000 * 1024 ) ) ) {
return V_220 ;
}
if ( V_31 -> V_221 > 2048 || V_31 -> V_222 > 4096 ||
V_31 -> V_223 > 4096 || V_31 -> V_224 > 4096 ||
V_31 -> V_225 > 2048 || V_31 -> V_226 > 4096 ||
V_31 -> V_227 > 4096 || V_31 -> V_228 > 4096 ) {
return V_229 ;
}
for ( V_11 = 0 ; V_11 < V_214 -> V_230 ; V_11 ++ ) {
if ( V_214 -> V_231 [ V_11 ] -> V_201 == V_201 ) {
V_217 = V_214 -> V_231 [ V_11 ] ;
if ( V_217 -> V_232 . V_233 ) {
if ( V_217 -> V_232 . V_234 ) {
V_168 = V_217 -> V_232 . V_168 ;
}
}
}
}
if ( ( V_31 -> V_124 * V_31 -> V_128 * ( V_168 / 8 ) ) > V_7 -> V_235 . V_236 ) {
if ( V_217 )
V_217 -> V_232 . V_233 = false ;
return V_229 ;
}
return V_237 ;
}
static struct V_193 * F_77 ( struct V_186
* V_201 )
{
int V_238 = V_201 -> V_239 [ 0 ] ;
struct V_240 * V_111 ;
struct V_193 * V_194 ;
if ( V_238 ) {
V_111 =
F_78 ( V_201 -> V_5 , V_238 ,
V_241 ) ;
if ( ! V_111 )
return NULL ;
V_194 = F_79 ( V_111 ) ;
return V_194 ;
}
return NULL ;
}
static enum V_242 F_80 ( struct V_186
* V_201 , bool V_243 )
{
return V_244 ;
}
static void F_81 ( struct V_186 * V_201 )
{
struct V_202 * V_202 = F_70 ( V_201 ) ;
F_82 ( V_202 -> V_204 ) ;
F_83 ( V_201 ) ;
F_48 ( V_201 ) ;
}
static struct V_186 * F_84 ( struct V_4 * V_5 )
{
struct V_186 * V_201 ;
struct V_202 * V_202 ;
V_202 = F_52 ( sizeof( struct V_202 ) , V_187 ) ;
if ( ! V_202 )
return NULL ;
V_201 = & V_202 -> V_188 ;
F_85 ( V_5 , V_201 ,
& V_245 , V_246 ) ;
F_86 ( V_201 , & V_247 ) ;
F_87 ( V_201 ) ;
V_202 -> V_204 = F_88 ( V_5 ) ;
if ( ! V_202 -> V_204 )
F_33 ( L_4 ) ;
return V_201 ;
}
int F_89 ( struct V_6 * V_7 )
{
struct V_193 * V_194 ;
struct V_186 * V_201 ;
int V_116 ;
V_7 -> V_190 . V_248 = true ;
V_7 -> V_5 -> V_249 . V_250 = V_251 ;
V_7 -> V_5 -> V_249 . V_252 = V_253 ;
V_7 -> V_5 -> V_249 . V_254 = V_7 -> V_235 . V_255 ;
F_51 ( V_7 ) ;
V_194 = F_66 ( V_7 -> V_5 ) ;
if ( ! V_194 ) {
F_33 ( L_5 ) ;
return - 1 ;
}
V_201 = F_84 ( V_7 -> V_5 ) ;
if ( ! V_201 ) {
F_33 ( L_6 ) ;
return - 1 ;
}
F_90 ( V_201 , V_194 ) ;
V_116 = F_91 ( V_7 ) ;
if ( V_116 ) {
F_33 ( L_7 ) ;
return V_116 ;
}
return 0 ;
}
void F_92 ( struct V_6 * V_7 )
{
}
