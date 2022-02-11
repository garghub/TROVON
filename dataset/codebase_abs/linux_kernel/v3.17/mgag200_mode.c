static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 -> V_10 ;
int V_12 ;
if ( ! V_2 -> V_13 )
return;
F_3 ( V_14 + V_15 , 0 ) ;
if ( V_10 && V_10 -> V_16 == 16 ) {
int V_17 = ( V_10 -> V_18 == 15 ) ? 8 : 4 ;
T_1 V_19 , V_20 ;
for ( V_12 = 0 ; V_12 < V_21 ; V_12 += V_17 ) {
if ( V_10 -> V_18 == 16 ) {
if ( V_12 > ( V_21 >> 1 ) ) {
V_19 = V_20 = 0 ;
} else {
V_19 = V_3 -> V_22 [ V_12 << 1 ] ;
V_20 = V_3 -> V_23 [ V_12 << 1 ] ;
}
} else {
V_19 = V_3 -> V_22 [ V_12 ] ;
V_20 = V_3 -> V_23 [ V_12 ] ;
}
F_3 ( V_14 + V_24 , V_19 ) ;
F_3 ( V_14 + V_24 , V_3 -> V_25 [ V_12 ] ) ;
F_3 ( V_14 + V_24 , V_20 ) ;
}
return;
}
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ ) {
F_3 ( V_14 + V_24 , V_3 -> V_22 [ V_12 ] ) ;
F_3 ( V_14 + V_24 , V_3 -> V_25 [ V_12 ] ) ;
F_3 ( V_14 + V_24 , V_3 -> V_23 [ V_12 ] ) ;
}
}
static inline void F_4 ( struct V_6 * V_7 )
{
unsigned long V_26 = V_27 + V_28 / 10 ;
unsigned int V_29 = 0 ;
do {
V_29 = F_5 ( V_30 ) ;
} while ( ( V_29 & 0x08 ) && F_6 ( V_27 , V_26 ) );
V_26 = V_27 + V_28 / 10 ;
V_29 = 0 ;
do {
V_29 = F_5 ( V_30 ) ;
} while ( ! ( V_29 & 0x08 ) && F_6 ( V_27 , V_26 ) );
}
static inline void F_7 ( struct V_6 * V_7 )
{
unsigned long V_26 = V_27 + V_28 ;
unsigned int V_29 = 0 ;
do {
V_29 = F_8 ( V_30 + 2 ) ;
} while ( ( V_29 & 0x01 ) && F_6 ( V_27 , V_26 ) );
}
static bool F_9 ( struct V_1 * V_2 ,
const struct V_31 * V_32 ,
struct V_31 * V_33 )
{
return true ;
}
static int F_10 ( struct V_6 * V_7 , long clock )
{
unsigned int V_34 , V_35 , V_36 ;
unsigned int V_37 , V_38 , V_39 ;
unsigned int V_40 , V_41 , V_42 ;
unsigned int V_43 , V_44 , V_45 ;
unsigned int V_46 ;
V_44 = V_45 = V_43 = 0 ;
V_34 = 320000 ;
V_35 = 160000 ;
V_36 = 25000 ;
V_37 = 0xffffffff ;
V_39 = clock * 5 / 1000 ;
for ( V_40 = 8 ; V_40 > 0 ; V_40 /= 2 ) {
if ( clock * V_40 > V_34 )
continue;
if ( clock * V_40 < V_35 )
continue;
for ( V_42 = 17 ; V_42 < 256 ; V_42 ++ ) {
for ( V_41 = 1 ; V_41 < 32 ; V_41 ++ ) {
V_46 = ( V_36 * V_42 ) /
( V_41 * V_40 ) ;
if ( V_46 > clock )
V_38 = V_46 - clock ;
else
V_38 = clock - V_46 ;
if ( V_38 < V_37 ) {
V_37 = V_38 ;
V_44 = V_41 - 1 ;
V_45 = V_42 - 1 ;
V_43 = V_40 - 1 ;
}
}
}
}
if ( V_37 > V_39 ) {
F_11 ( V_47 L_1 ) ;
return 1 ;
}
F_12 ( V_48 , V_44 ) ;
F_12 ( V_49 , V_45 ) ;
F_12 ( V_50 , V_43 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , long clock )
{
unsigned int V_34 , V_35 , V_36 ;
unsigned int V_37 , V_38 , V_39 ;
unsigned int V_40 , V_41 , V_42 ;
unsigned int V_43 , V_44 , V_45 ;
unsigned int V_46 ;
int V_12 , V_51 , V_52 , V_53 ;
bool V_54 = false ;
T_1 V_55 ;
V_44 = V_45 = V_43 = 0 ;
V_34 = 550000 ;
V_35 = 150000 ;
V_36 = 48000 ;
V_37 = 0xffffffff ;
V_39 = clock * 5 / 1000 ;
for ( V_40 = 1 ; V_40 < 9 ; V_40 ++ ) {
if ( clock * V_40 > V_34 )
continue;
if ( clock * V_40 < V_35 )
continue;
for ( V_41 = 1 ; V_41 < 17 ; V_41 ++ ) {
for ( V_42 = 1 ; V_42 < 151 ; V_42 ++ ) {
V_46 = ( V_36 * V_42 ) /
( V_41 * V_40 ) ;
if ( V_46 > clock )
V_38 = V_46 - clock ;
else
V_38 = clock - V_46 ;
if ( V_38 < V_37 ) {
V_37 = V_38 ;
V_45 = V_42 - 1 ;
V_44 = ( V_41 - 1 ) | ( ( V_45 >> 1 ) & 0x80 ) ;
V_43 = V_40 - 1 ;
}
}
}
}
for ( V_12 = 0 ; V_12 <= 32 && V_54 == false ; V_12 ++ ) {
if ( V_12 > 0 ) {
F_3 ( V_56 , 0x1e ) ;
V_55 = F_8 ( V_57 ) ;
if ( V_55 < 0xff )
F_3 ( V_57 , V_55 + 1 ) ;
}
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= V_60 ;
F_3 ( V_59 , V_55 ) ;
F_3 ( V_14 , V_61 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= V_62 ;
F_3 ( V_59 , V_55 ) ;
V_55 = F_8 ( V_63 ) ;
V_55 |= 0x3 << 2 ;
F_3 ( V_64 , V_55 ) ;
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= V_65 | 0x80 ;
F_3 ( V_59 , V_55 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_66 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ 0x04 ;
F_3 ( V_59 , V_55 ) ;
F_14 ( 50 ) ;
F_12 ( V_67 , V_45 ) ;
F_12 ( V_68 , V_44 ) ;
F_12 ( V_69 , V_43 ) ;
F_14 ( 50 ) ;
F_3 ( V_14 , V_66 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= 0x04 ;
F_12 ( V_66 , V_55 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ V_70 ;
V_55 |= V_71 ;
F_3 ( V_59 , V_55 ) ;
F_3 ( V_14 , V_61 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ V_72 ;
V_55 |= V_73 ;
F_3 ( V_59 , V_55 ) ;
F_3 ( V_74 , 1 ) ;
V_55 = F_8 ( V_75 ) ;
V_55 &= ~ 0x8 ;
F_3 ( V_75 , V_55 ) ;
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ V_60 ;
F_3 ( V_59 , V_55 ) ;
V_53 = F_8 ( V_76 ) ;
for ( V_51 = 0 ; V_51 < 30 && V_54 == false ; V_51 ++ ) {
V_52 = F_8 ( V_76 ) ;
if ( V_52 < V_53 )
V_53 = 0 ;
if ( ( V_52 - V_53 ) > 2 )
V_54 = true ;
else
F_14 ( 5 ) ;
}
}
F_3 ( V_14 , V_61 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ V_62 ;
F_12 ( V_61 , V_55 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , long clock )
{
unsigned int V_34 , V_35 , V_36 ;
unsigned int V_37 , V_38 , V_39 ;
unsigned int V_40 , V_41 , V_42 ;
unsigned int V_43 , V_44 , V_45 ;
unsigned int V_46 ;
T_1 V_55 ;
V_44 = V_45 = V_43 = 0 ;
V_34 = 550000 ;
V_35 = 150000 ;
V_36 = 50000 ;
V_37 = 0xffffffff ;
V_39 = clock * 5 / 1000 ;
for ( V_40 = 16 ; V_40 > 0 ; V_40 -- ) {
if ( clock * V_40 > V_34 )
continue;
if ( clock * V_40 < V_35 )
continue;
for ( V_42 = 1 ; V_42 < 257 ; V_42 ++ ) {
for ( V_41 = 1 ; V_41 < 17 ; V_41 ++ ) {
V_46 = ( V_36 * V_42 ) /
( V_41 * V_40 ) ;
if ( V_46 > clock )
V_38 = V_46 - clock ;
else
V_38 = clock - V_46 ;
if ( V_38 < V_37 ) {
V_37 = V_38 ;
V_45 = V_42 - 1 ;
V_44 = V_41 - 1 ;
V_43 = V_40 - 1 ;
}
}
}
}
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= V_60 ;
F_3 ( V_59 , V_55 ) ;
V_55 = F_8 ( V_63 ) ;
V_55 |= 0x3 << 2 ;
F_3 ( V_64 , V_55 ) ;
F_3 ( V_14 , V_77 ) ;
V_55 = F_8 ( V_59 ) ;
F_3 ( V_59 , V_55 & ~ 0x40 ) ;
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= V_65 ;
F_3 ( V_59 , V_55 ) ;
F_12 ( V_78 , V_44 ) ;
F_12 ( V_79 , V_45 ) ;
F_12 ( V_80 , V_43 ) ;
F_14 ( 50 ) ;
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ V_65 ;
F_3 ( V_59 , V_55 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ V_70 ;
V_55 |= V_71 ;
F_3 ( V_59 , V_55 ) ;
F_3 ( V_14 , V_77 ) ;
V_55 = F_8 ( V_59 ) ;
F_3 ( V_59 , V_55 | 0x40 ) ;
V_55 = F_8 ( V_63 ) ;
V_55 |= ( 0x3 << 2 ) ;
F_3 ( V_64 , V_55 ) ;
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ V_60 ;
F_3 ( V_59 , V_55 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , long clock )
{
unsigned int V_34 , V_35 , V_36 ;
unsigned int V_37 , V_38 , V_39 ;
unsigned int V_40 , V_41 , V_42 ;
unsigned int V_43 , V_44 , V_45 ;
unsigned int V_46 ;
int V_12 , V_51 , V_52 , V_53 ;
T_1 V_55 ;
bool V_54 = false ;
V_44 = V_45 = V_43 = 0 ;
V_34 = 800000 ;
V_35 = 400000 ;
V_36 = 33333 ;
V_37 = 0xffffffff ;
V_39 = clock * 5 / 1000 ;
for ( V_40 = 16 ; V_40 > 0 ; V_40 >>= 1 ) {
if ( clock * V_40 > V_34 )
continue;
if ( clock * V_40 < V_35 )
continue;
for ( V_41 = 1 ; V_41 < 33 ; V_41 ++ ) {
for ( V_42 = 17 ; V_42 < 257 ; V_42 ++ ) {
V_46 = ( V_36 * V_42 ) /
( V_41 * V_40 ) ;
if ( V_46 > clock )
V_38 = V_46 - clock ;
else
V_38 = clock - V_46 ;
if ( V_38 < V_37 ) {
V_37 = V_38 ;
V_45 = V_42 - 1 ;
V_44 = ( V_41 - 1 ) ;
V_43 = V_40 - 1 ;
}
if ( ( clock * V_40 ) >= 600000 )
V_43 |= 0x80 ;
}
}
}
for ( V_12 = 0 ; V_12 <= 32 && V_54 == false ; V_12 ++ ) {
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= V_60 ;
F_3 ( V_59 , V_55 ) ;
V_55 = F_8 ( V_63 ) ;
V_55 |= 0x3 << 2 ;
F_3 ( V_64 , V_55 ) ;
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= V_65 ;
F_3 ( V_59 , V_55 ) ;
F_14 ( 500 ) ;
F_12 ( V_81 , V_44 ) ;
F_12 ( V_82 , V_45 ) ;
F_12 ( V_83 , V_43 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ V_70 ;
V_55 |= V_71 ;
F_3 ( V_59 , V_55 ) ;
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ V_60 ;
V_55 &= ~ V_65 ;
F_3 ( V_59 , V_55 ) ;
V_53 = F_8 ( V_76 ) ;
for ( V_51 = 0 ; V_51 < 30 && V_54 == false ; V_51 ++ ) {
V_52 = F_8 ( V_76 ) ;
if ( V_52 < V_53 )
V_53 = 0 ;
if ( ( V_52 - V_53 ) > 2 )
V_54 = true ;
else
F_14 ( 5 ) ;
}
}
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , long clock )
{
unsigned int V_34 , V_35 , V_36 ;
unsigned int V_37 , V_38 ;
int V_84 , V_42 , V_41 , V_85 ;
unsigned int V_43 , V_44 , V_45 ;
unsigned int V_46 , V_86 ;
int V_55 ;
const unsigned int V_87 [] = { 1 , 2 , 4 , 8 } ;
V_44 = V_45 = V_43 = 0 ;
V_34 = 1488000 ;
V_35 = 1056000 ;
V_36 = 48000 ;
V_37 = 0xffffffff ;
for ( V_84 = 0 ; V_84 < 4 ; V_84 ++ ) {
if ( V_37 == 0 )
break;
for ( V_42 = 5 ; V_42 < 129 ; V_42 ++ ) {
if ( V_37 == 0 )
break;
for ( V_41 = 3 ; V_41 >= 0 ; V_41 -- ) {
if ( V_37 == 0 )
break;
for ( V_85 = 5 ; V_85 < 33 ; V_85 ++ ) {
V_86 = V_36 * ( V_42 + 1 ) /
( V_84 + 1 ) ;
if ( V_86 < V_35 )
continue;
if ( V_86 > V_34 )
continue;
V_46 = V_86 / ( V_87 [ V_41 ] * ( V_85 + 1 ) ) ;
if ( V_46 > clock )
V_38 = V_46 - clock ;
else
V_38 = clock - V_46 ;
if ( V_38 < V_37 ) {
V_37 = V_38 ;
V_44 = V_41 | ( V_85 << 3 ) ;
V_45 = V_42 ;
V_43 = V_84 | ( V_84 << 3 ) ;
}
}
}
}
}
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= V_60 ;
F_3 ( V_59 , V_55 ) ;
F_3 ( V_14 , V_61 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= V_62 ;
F_3 ( V_59 , V_55 ) ;
V_55 = F_8 ( V_63 ) ;
V_55 |= ( 0x3 << 2 ) | 0xc0 ;
F_3 ( V_64 , V_55 ) ;
F_3 ( V_14 , V_58 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ V_60 ;
V_55 |= V_65 ;
F_3 ( V_59 , V_55 ) ;
F_14 ( 500 ) ;
F_12 ( V_88 , V_45 ) ;
F_12 ( V_89 , V_44 ) ;
F_12 ( V_90 , V_43 ) ;
F_14 ( 50 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , long clock )
{
switch( V_7 -> type ) {
case V_91 :
case V_92 :
return F_10 ( V_7 , clock ) ;
break;
case V_93 :
return F_13 ( V_7 , clock ) ;
break;
case V_94 :
return F_15 ( V_7 , clock ) ;
break;
case V_95 :
return F_16 ( V_7 , clock ) ;
break;
case V_96 :
return F_17 ( V_7 , clock ) ;
break;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_1 V_55 ;
int V_97 ;
F_3 ( V_14 , V_98 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= 0x10 ;
F_12 ( V_98 , V_55 ) ;
F_3 ( V_14 , V_99 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= 0x10 ;
F_12 ( V_99 , V_55 ) ;
F_3 ( V_14 , V_100 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= 0x80 ;
F_12 ( V_100 , V_55 ) ;
V_97 = 300 ;
while ( ! ( V_55 & 0x1 ) && V_97 ) {
F_3 ( V_14 , V_100 ) ;
V_55 = F_8 ( V_59 ) ;
F_14 ( 1000 ) ;
V_97 -- ;
}
if ( V_97 ) {
V_97 = 300 ;
while ( ( V_55 & 0x2 ) && V_97 ) {
F_3 ( V_14 , V_100 ) ;
V_55 = F_8 ( V_59 ) ;
F_14 ( 1000 ) ;
V_97 -- ;
}
}
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_55 ;
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
F_3 ( V_101 , 1 ) ;
V_55 = F_8 ( V_102 ) ;
F_3 ( V_102 , V_55 | 0x88 ) ;
F_3 ( V_14 , V_103 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 |= 0x8 ;
F_3 ( V_59 , V_55 ) ;
F_14 ( 10 ) ;
V_55 &= ~ 0x08 ;
F_3 ( V_14 , V_103 ) ;
F_3 ( V_59 , V_55 ) ;
F_3 ( V_14 , V_100 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ 0x80 ;
F_3 ( V_59 , V_55 ) ;
F_3 ( V_14 , V_99 ) ;
V_55 = F_8 ( V_59 ) ;
V_55 &= ~ 0x10 ;
F_12 ( V_99 , V_55 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned V_104 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_2 V_105 ;
int V_106 ;
T_1 V_107 ;
while ( F_8 ( 0x1fda ) & 0x08 ) ;
while ( ! ( F_8 ( 0x1fda ) & 0x08 ) ) ;
V_106 = F_8 ( V_76 ) + 2 ;
while ( F_8 ( V_76 ) < V_106 ) ;
F_3 ( V_101 , 0 ) ;
V_107 = F_8 ( V_102 ) ;
V_107 &= 0xB0 ;
V_105 = V_104 / 8 ;
F_22 ( V_105 > 0x1fffff ) ;
V_107 |= ( ! ! ( V_105 & ( 1 << 20 ) ) ) << 6 ;
F_23 ( 0x0d , ( T_1 ) ( V_105 & 0xff ) ) ;
F_23 ( 0x0c , ( T_1 ) ( V_105 >> 8 ) & 0xff ) ;
F_24 ( 0x0 , ( ( T_1 ) ( V_105 >> 16 ) & 0xf ) | V_107 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
int V_108 , int V_109 , int V_110 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_111 * V_112 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
int V_117 ;
T_3 V_118 ;
if ( ! V_110 && V_10 ) {
V_114 = F_26 ( V_10 ) ;
V_112 = V_114 -> V_112 ;
V_116 = F_27 ( V_112 ) ;
V_117 = F_28 ( V_116 , false ) ;
if ( V_117 )
return V_117 ;
F_29 ( V_116 ) ;
F_30 ( V_116 ) ;
}
V_114 = F_26 ( V_2 -> V_11 -> V_10 ) ;
V_112 = V_114 -> V_112 ;
V_116 = F_27 ( V_112 ) ;
V_117 = F_28 ( V_116 , false ) ;
if ( V_117 )
return V_117 ;
V_117 = F_31 ( V_116 , V_119 , & V_118 ) ;
if ( V_117 ) {
F_30 ( V_116 ) ;
return V_117 ;
}
if ( & V_7 -> V_120 -> V_121 == V_114 ) {
V_117 = F_32 ( & V_116 -> V_116 , 0 , V_116 -> V_116 . V_122 , & V_116 -> V_123 ) ;
if ( V_117 )
F_33 ( L_2 ) ;
}
F_30 ( V_116 ) ;
F_21 ( V_2 , ( T_2 ) V_118 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_108 , int V_109 ,
struct V_9 * V_124 )
{
return F_25 ( V_2 , V_124 , V_108 , V_109 , 0 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_31 * V_33 ,
int V_108 , int V_109 , struct V_9 * V_124 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_125 , V_126 , V_127 , V_128 ;
int V_129 , V_130 , V_131 , V_132 ;
int V_133 ;
int V_134 = 0 , V_135 = 0 ;
int V_12 ;
unsigned char V_136 = 0 ;
unsigned char V_137 [ 6 ] ;
T_1 V_138 ;
static unsigned char V_139 [] = {
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
V_138 = V_7 -> V_140 [ ( V_2 -> V_11 -> V_10 -> V_16 >> 3 ) - 1 ] ;
switch ( V_7 -> type ) {
case V_91 :
case V_92 :
V_139 [ V_66 ] = 0x03 ;
V_139 [ V_58 ] = V_71 ;
V_139 [ V_141 ] = V_142 |
V_143 |
V_144 ;
if ( V_7 -> V_145 )
V_134 = 0x40049120 ;
else
V_134 = 0x4004d120 ;
V_135 = 0x00008000 ;
break;
case V_93 :
V_139 [ V_66 ] = 0x07 ;
V_134 = 0x41049120 ;
V_135 = 0x0000b000 ;
break;
case V_94 :
V_139 [ V_58 ] = V_71 ;
V_139 [ V_141 ] = V_143 |
V_144 ;
V_134 = 0x00000120 ;
V_135 = 0x0000b000 ;
break;
case V_95 :
V_139 [ V_141 ] = V_143 |
V_144 ;
V_134 = 0x00000120 ;
V_135 = 0x0000b000 ;
break;
case V_96 :
break;
}
switch ( V_2 -> V_11 -> V_10 -> V_16 ) {
case 8 :
V_139 [ V_146 ] = V_147 ;
break;
case 16 :
if ( V_2 -> V_11 -> V_10 -> V_18 == 15 )
V_139 [ V_146 ] = V_148 ;
else
V_139 [ V_146 ] = V_149 ;
break;
case 24 :
V_139 [ V_146 ] = V_150 ;
break;
case 32 :
V_139 [ V_146 ] = V_151 ;
break;
}
if ( V_32 -> V_152 & V_153 )
V_136 |= 0x40 ;
if ( V_32 -> V_152 & V_154 )
V_136 |= 0x80 ;
for ( V_12 = 0 ; V_12 < sizeof( V_139 ) ; V_12 ++ ) {
if ( ( V_12 <= 0x17 ) ||
( V_12 == 0x1b ) ||
( V_12 == 0x1c ) ||
( ( V_12 >= 0x1f ) && ( V_12 <= 0x29 ) ) ||
( ( V_12 >= 0x30 ) && ( V_12 <= 0x37 ) ) )
continue;
if ( F_36 ( V_7 ) &&
( ( V_12 == 0x2c ) || ( V_12 == 0x2d ) || ( V_12 == 0x2e ) ) )
continue;
if ( ( V_7 -> type == V_94 || V_7 -> type == V_93 || V_7 -> type == V_95 ) &&
( V_12 >= 0x44 ) && ( V_12 <= 0x4e ) )
continue;
F_12 ( V_12 , V_139 [ V_12 ] ) ;
}
if ( V_7 -> type == V_96 )
F_12 ( 0x90 , 0 ) ;
if ( V_134 )
F_37 ( V_5 -> V_155 , V_156 , V_134 ) ;
if ( V_135 )
F_37 ( V_5 -> V_155 , V_157 , V_135 ) ;
F_38 ( 2 , 0xf ) ;
F_38 ( 3 , 0 ) ;
F_38 ( 4 , 0xe ) ;
V_133 = V_2 -> V_11 -> V_10 -> V_158 [ 0 ] / ( V_2 -> V_11 -> V_10 -> V_16 / 8 ) ;
if ( V_2 -> V_11 -> V_10 -> V_16 == 24 )
V_133 = ( V_133 * 3 ) >> ( 4 - V_138 ) ;
else
V_133 = V_133 >> ( 4 - V_138 ) ;
V_125 = V_32 -> V_125 / 8 - 1 ;
V_126 = V_32 -> V_159 / 8 - 1 ;
V_127 = V_32 -> V_160 / 8 - 1 ;
V_128 = V_32 -> V_128 / 8 - 1 ;
if ( ( V_128 & 0x07 ) == 0x06 || ( V_128 & 0x07 ) == 0x04 )
V_128 ++ ;
V_129 = V_32 -> V_129 - 1 ;
V_130 = V_32 -> V_161 - 1 ;
V_131 = V_32 -> V_162 - 1 ;
V_132 = V_32 -> V_132 - 2 ;
F_39 ( 0 , 0 ) ;
F_39 ( 1 , 0 ) ;
F_39 ( 2 , 0 ) ;
F_39 ( 3 , 0 ) ;
F_39 ( 4 , 0 ) ;
F_39 ( 5 , 0x40 ) ;
F_39 ( 6 , 0x5 ) ;
F_39 ( 7 , 0xf ) ;
F_39 ( 8 , 0xf ) ;
F_23 ( 0 , V_128 - 4 ) ;
F_23 ( 1 , V_125 ) ;
F_23 ( 2 , V_125 ) ;
F_23 ( 3 , ( V_128 & 0x1F ) | 0x80 ) ;
F_23 ( 4 , V_126 ) ;
F_23 ( 5 , ( ( V_128 & 0x20 ) << 2 ) | ( V_127 & 0x1F ) ) ;
F_23 ( 6 , V_132 & 0xFF ) ;
F_23 ( 7 , ( ( V_132 & 0x100 ) >> 8 ) |
( ( V_129 & 0x100 ) >> 7 ) |
( ( V_130 & 0x100 ) >> 6 ) |
( ( V_129 & 0x100 ) >> 5 ) |
( ( V_129 & 0x100 ) >> 4 ) |
( ( V_132 & 0x200 ) >> 4 ) |
( ( V_129 & 0x200 ) >> 3 ) |
( ( V_130 & 0x200 ) >> 2 ) ) ;
F_23 ( 9 , ( ( V_129 & 0x200 ) >> 4 ) |
( ( V_129 & 0x200 ) >> 3 ) ) ;
F_23 ( 10 , 0 ) ;
F_23 ( 11 , 0 ) ;
F_23 ( 12 , 0 ) ;
F_23 ( 13 , 0 ) ;
F_23 ( 14 , 0 ) ;
F_23 ( 15 , 0 ) ;
F_23 ( 16 , V_130 & 0xFF ) ;
F_23 ( 17 , ( V_131 & 0x0F ) | 0x20 ) ;
F_23 ( 18 , V_129 & 0xFF ) ;
F_23 ( 19 , V_133 & 0xFF ) ;
F_23 ( 20 , 0 ) ;
F_23 ( 21 , V_129 & 0xFF ) ;
F_23 ( 22 , ( V_132 + 1 ) & 0xFF ) ;
F_23 ( 23 , 0xc3 ) ;
F_23 ( 24 , V_129 & 0xFF ) ;
V_137 [ 0 ] = 0 ;
V_137 [ 5 ] = 0 ;
V_137 [ 0 ] |= ( V_133 & 0x300 ) >> 4 ;
V_137 [ 1 ] = ( ( ( V_128 - 4 ) & 0x100 ) >> 8 ) |
( ( V_125 & 0x100 ) >> 7 ) |
( ( V_126 & 0x100 ) >> 6 ) |
( V_128 & 0x40 ) ;
V_137 [ 2 ] = ( ( V_132 & 0xc00 ) >> 10 ) |
( ( V_129 & 0x400 ) >> 8 ) |
( ( V_129 & 0xc00 ) >> 7 ) |
( ( V_130 & 0xc00 ) >> 5 ) |
( ( V_129 & 0x400 ) >> 3 ) ;
if ( V_2 -> V_11 -> V_10 -> V_16 == 24 )
V_137 [ 3 ] = ( ( ( 1 << V_138 ) * 3 ) - 1 ) | 0x80 ;
else
V_137 [ 3 ] = ( ( 1 << V_138 ) - 1 ) | 0x80 ;
V_137 [ 4 ] = 0 ;
if ( V_7 -> type == V_93 )
V_137 [ 1 ] |= 0x88 ;
V_136 = 0x2d ;
F_3 ( V_163 , V_136 ) ;
F_18 ( V_7 , V_32 -> clock ) ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
F_24 ( V_12 , V_137 [ V_12 ] ) ;
}
if ( V_7 -> type == V_96 )
F_24 ( 0x24 , 0x5 ) ;
if ( V_7 -> type == V_94 ) {
F_24 ( 6 , 0 ) ;
}
F_24 ( 0 , V_137 [ 0 ] ) ;
V_136 = 0x2d ;
F_3 ( V_163 , V_136 ) ;
if ( V_33 )
memcpy ( & V_7 -> V_32 , V_32 , sizeof( struct V_31 ) ) ;
F_25 ( V_2 , V_124 , V_108 , V_109 , 0 ) ;
if ( V_7 -> type == V_96 ) {
T_2 V_164 = F_5 ( V_165 ) ;
T_1 V_166 ;
F_3 ( V_74 , 0x01 ) ;
V_166 = F_8 ( V_75 ) | 0x20 ;
F_3 ( V_75 , V_166 ) ;
F_40 ( V_165 , V_164 | 0x00200000 ) ;
F_14 ( 1000 ) ;
F_40 ( V_165 , V_164 & ~ 0x00200000 ) ;
F_3 ( V_75 , V_166 & ~ 0x20 ) ;
}
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_167 >= 0x02 ) {
T_1 V_168 ;
T_2 V_169 ;
T_2 V_170 ;
if ( V_2 -> V_11 -> V_10 -> V_16 > 16 )
V_169 = 32 ;
else if ( V_2 -> V_11 -> V_10 -> V_16 > 8 )
V_169 = 16 ;
else
V_169 = 8 ;
V_170 = ( V_32 -> clock * V_169 ) / 1000 ;
if ( V_170 > 3100 )
V_168 = 0 ;
else if ( V_170 > 2600 )
V_168 = 1 ;
else if ( V_170 > 1900 )
V_168 = 2 ;
else if ( V_170 > 1160 )
V_168 = 3 ;
else if ( V_170 > 440 )
V_168 = 4 ;
else
V_168 = 5 ;
F_3 ( V_101 , 0x06 ) ;
F_3 ( V_102 , V_168 ) ;
} else {
F_3 ( V_101 , 0x06 ) ;
if ( V_7 -> V_167 >= 0x01 )
F_3 ( V_102 , 0x03 ) ;
else
F_3 ( V_102 , 0x04 ) ;
}
}
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , int V_32 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_166 = 0 , V_171 = 0 ;
switch ( V_32 ) {
case V_172 :
V_166 = 0 ;
V_171 = 0 ;
F_1 ( V_2 ) ;
break;
case V_173 :
V_166 = 0x20 ;
V_171 = 0x10 ;
break;
case V_174 :
V_166 = 0x20 ;
V_171 = 0x20 ;
break;
case V_175 :
V_166 = 0x20 ;
V_171 = 0x30 ;
break;
}
#if 0
if (mode == DRM_MODE_DPMS_OFF) {
mga_suspend(crtc);
}
#endif
F_3 ( V_74 , 0x01 ) ;
V_166 |= F_8 ( V_75 ) & ~ 0x20 ;
F_4 ( V_7 ) ;
F_7 ( V_7 ) ;
F_3 ( V_75 , V_166 ) ;
F_42 ( 20 ) ;
F_3 ( V_101 , 0x01 ) ;
V_171 |= F_8 ( V_102 ) & ~ 0x30 ;
F_3 ( V_102 , V_171 ) ;
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
T_1 V_55 ;
F_3 ( V_56 , 0x11 ) ;
V_55 = F_8 ( V_57 ) ;
F_23 ( 0x11 , V_55 | 0x80 ) ;
if ( V_7 -> type == V_91 || V_7 -> type == V_92 ) {
F_38 ( 0 , 1 ) ;
F_42 ( 50 ) ;
F_38 ( 1 , 0x20 ) ;
F_42 ( 20 ) ;
} else {
F_3 ( V_74 , 0x1 ) ;
V_55 = F_8 ( V_75 ) ;
F_38 ( 0 , 1 ) ;
F_38 ( 1 , V_55 | 0x20 ) ;
}
if ( V_7 -> type == V_93 )
F_19 ( V_2 ) ;
F_23 ( 17 , 0 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_176 * V_177 = V_2 -> V_178 ;
T_1 V_55 ;
if ( V_7 -> type == V_93 )
F_20 ( V_2 ) ;
if ( V_7 -> type == V_91 || V_7 -> type == V_92 ) {
F_42 ( 50 ) ;
F_38 ( 1 , 0x0 ) ;
F_42 ( 20 ) ;
F_38 ( 0 , 0x3 ) ;
} else {
F_3 ( V_74 , 0x1 ) ;
V_55 = F_8 ( V_75 ) ;
V_55 &= ~ 0x20 ;
F_38 ( 0x1 , V_55 ) ;
F_38 ( 0 , 3 ) ;
}
V_177 -> V_179 ( V_2 , V_172 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_4 * V_180 , T_4 * V_181 ,
T_4 * V_182 , T_5 V_183 , T_5 V_184 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_185 = ( V_183 + V_184 > V_21 ) ? V_21 : V_183 + V_184 ;
int V_12 ;
for ( V_12 = V_183 ; V_12 < V_185 ; V_12 ++ ) {
V_3 -> V_22 [ V_12 ] = V_180 [ V_12 ] >> 8 ;
V_3 -> V_25 [ V_12 ] = V_181 [ V_12 ] >> 8 ;
V_3 -> V_23 [ V_12 ] = V_182 [ V_12 ] >> 8 ;
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
int V_117 ;
F_50 ( L_3 ) ;
F_41 ( V_2 , V_175 ) ;
if ( V_2 -> V_11 -> V_10 ) {
struct V_113 * V_114 = F_26 ( V_2 -> V_11 -> V_10 ) ;
struct V_111 * V_112 = V_114 -> V_112 ;
struct V_115 * V_116 = F_27 ( V_112 ) ;
V_117 = F_28 ( V_116 , false ) ;
if ( V_117 )
return;
F_29 ( V_116 ) ;
F_30 ( V_116 ) ;
}
V_2 -> V_11 -> V_10 = NULL ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_3 * V_3 ;
int V_12 ;
V_3 = F_52 ( sizeof( struct V_3 ) +
( V_186 * sizeof( struct V_187 * ) ) ,
V_188 ) ;
if ( V_3 == NULL )
return;
F_53 ( V_7 -> V_5 , & V_3 -> V_189 , & V_190 ) ;
F_54 ( & V_3 -> V_189 , V_21 ) ;
V_7 -> V_191 . V_2 = V_3 ;
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ ) {
V_3 -> V_22 [ V_12 ] = V_12 ;
V_3 -> V_25 [ V_12 ] = V_12 ;
V_3 -> V_23 [ V_12 ] = V_12 ;
}
F_55 ( & V_3 -> V_189 , & V_192 ) ;
}
void F_56 ( struct V_1 * V_2 , T_4 V_180 , T_4 V_181 ,
T_4 V_182 , int V_193 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_22 [ V_193 ] = V_180 >> 8 ;
V_3 -> V_25 [ V_193 ] = V_181 >> 8 ;
V_3 -> V_23 [ V_193 ] = V_182 >> 8 ;
}
void F_57 ( struct V_1 * V_2 , T_4 * V_180 , T_4 * V_181 ,
T_4 * V_182 , int V_193 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_180 = ( T_4 ) V_3 -> V_22 [ V_193 ] << 8 ;
* V_181 = ( T_4 ) V_3 -> V_25 [ V_193 ] << 8 ;
* V_182 = ( T_4 ) V_3 -> V_23 [ V_193 ] << 8 ;
}
static bool F_58 ( struct V_194 * V_195 ,
const struct V_31 * V_32 ,
struct V_31 * V_33 )
{
return true ;
}
static void F_59 ( struct V_194 * V_195 ,
struct V_31 * V_32 ,
struct V_31 * V_33 )
{
}
static void F_60 ( struct V_194 * V_195 , int V_196 )
{
return;
}
static void F_61 ( struct V_194 * V_195 )
{
}
static void F_62 ( struct V_194 * V_195 )
{
}
static void F_63 ( struct V_194 * V_195 )
{
struct V_197 * V_197 = F_64 ( V_195 ) ;
F_65 ( V_195 ) ;
F_48 ( V_197 ) ;
}
static struct V_194 * F_66 ( struct V_4 * V_5 )
{
struct V_194 * V_195 ;
struct V_197 * V_197 ;
V_197 = F_52 ( sizeof( struct V_197 ) , V_188 ) ;
if ( ! V_197 )
return NULL ;
V_195 = & V_197 -> V_189 ;
V_195 -> V_198 = 0x1 ;
F_67 ( V_5 , V_195 , & V_199 ,
V_200 ) ;
F_68 ( V_195 , & V_201 ) ;
return V_195 ;
}
static int F_69 ( struct V_187 * V_202 )
{
struct V_203 * V_203 = F_70 ( V_202 ) ;
struct V_204 * V_204 ;
int V_117 = 0 ;
V_204 = F_71 ( V_202 , & V_203 -> V_205 -> V_206 ) ;
if ( V_204 ) {
F_72 ( V_202 , V_204 ) ;
V_117 = F_73 ( V_202 , V_204 ) ;
F_48 ( V_204 ) ;
}
return V_117 ;
}
static T_5 F_74 ( struct V_31 * V_32 ,
int V_16 )
{
T_5 V_207 , V_208 ;
T_6 V_209 , V_210 , V_211 ;
T_7 V_212 = ( V_16 + 7 ) / 8 ;
V_208 = 1024 ;
if ( ! V_32 -> V_128 || ! V_32 -> V_132 || ! V_32 -> clock )
return 0 ;
V_209 = V_32 -> V_125 * V_32 -> V_129 ;
V_207 = V_32 -> V_128 * V_32 -> V_132 ;
V_210 = V_209 * V_32 -> clock * 1000 ;
F_75 ( V_210 , V_207 ) ;
V_211 = V_210 * V_212 * 100 ;
F_75 ( V_211 , V_208 ) ;
return ( T_5 ) ( V_211 ) ;
}
static int F_76 ( struct V_187 * V_202 ,
struct V_31 * V_32 )
{
struct V_4 * V_5 = V_202 -> V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_5 -> V_8 ;
struct V_213 * V_120 = V_7 -> V_120 ;
struct V_214 * V_215 = & V_120 -> V_216 ;
struct V_217 * V_218 = NULL ;
int V_169 = 32 ;
int V_12 = 0 ;
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_167 == 0x01 ) {
if ( V_32 -> V_125 > 1600 )
return V_219 ;
if ( V_32 -> V_129 > 1200 )
return V_220 ;
if ( F_74 ( V_32 , V_169 )
> ( 24400 * 1024 ) )
return V_221 ;
} else if ( V_7 -> V_167 >= 0x02 ) {
if ( V_32 -> V_125 > 1920 )
return V_219 ;
if ( V_32 -> V_129 > 1200 )
return V_220 ;
if ( F_74 ( V_32 , V_169 )
> ( 30100 * 1024 ) )
return V_221 ;
}
} else if ( V_7 -> type == V_93 ) {
if ( V_32 -> V_125 > 1280 )
return V_219 ;
if ( V_32 -> V_129 > 1024 )
return V_220 ;
if ( F_74 ( V_32 ,
V_169 > ( 31877 * 1024 ) ) )
return V_221 ;
} else if ( V_7 -> type == V_94 &&
( F_74 ( V_32 , V_169 )
> ( 32700 * 1024 ) ) ) {
return V_221 ;
} else if ( V_7 -> type == V_95 &&
( F_74 ( V_32 , V_169 )
> ( 37500 * 1024 ) ) ) {
return V_221 ;
} else if ( V_7 -> type == V_96 &&
( F_74 ( V_32 ,
V_169 ) > ( 55000 * 1024 ) ) ) {
return V_221 ;
}
if ( V_32 -> V_222 > 2048 || V_32 -> V_223 > 4096 ||
V_32 -> V_224 > 4096 || V_32 -> V_225 > 4096 ||
V_32 -> V_226 > 2048 || V_32 -> V_227 > 4096 ||
V_32 -> V_228 > 4096 || V_32 -> V_229 > 4096 ) {
return V_230 ;
}
for ( V_12 = 0 ; V_12 < V_215 -> V_231 ; V_12 ++ ) {
if ( V_215 -> V_232 [ V_12 ] -> V_202 == V_202 ) {
V_218 = V_215 -> V_232 [ V_12 ] ;
if ( V_218 -> V_233 . V_234 ) {
if ( V_218 -> V_233 . V_235 ) {
V_169 = V_218 -> V_233 . V_169 ;
}
}
}
}
if ( ( V_32 -> V_125 * V_32 -> V_129 * ( V_169 / 8 ) ) > V_7 -> V_236 . V_237 ) {
if ( V_218 )
V_218 -> V_233 . V_234 = false ;
return V_230 ;
}
return V_238 ;
}
static struct V_194 * F_77 ( struct V_187
* V_202 )
{
int V_239 = V_202 -> V_240 [ 0 ] ;
if ( V_239 )
return F_78 ( V_202 -> V_5 , V_239 ) ;
return NULL ;
}
static enum V_241 F_79 ( struct V_187
* V_202 , bool V_242 )
{
return V_243 ;
}
static void F_80 ( struct V_187 * V_202 )
{
struct V_203 * V_203 = F_70 ( V_202 ) ;
F_81 ( V_203 -> V_205 ) ;
F_82 ( V_202 ) ;
F_48 ( V_202 ) ;
}
static struct V_187 * F_83 ( struct V_4 * V_5 )
{
struct V_187 * V_202 ;
struct V_203 * V_203 ;
V_203 = F_52 ( sizeof( struct V_203 ) , V_188 ) ;
if ( ! V_203 )
return NULL ;
V_202 = & V_203 -> V_189 ;
F_84 ( V_5 , V_202 ,
& V_244 , V_245 ) ;
F_85 ( V_202 , & V_246 ) ;
F_86 ( V_202 ) ;
V_203 -> V_205 = F_87 ( V_5 ) ;
if ( ! V_203 -> V_205 )
F_33 ( L_4 ) ;
return V_202 ;
}
int F_88 ( struct V_6 * V_7 )
{
struct V_194 * V_195 ;
struct V_187 * V_202 ;
int V_117 ;
V_7 -> V_191 . V_247 = true ;
V_7 -> V_5 -> V_248 . V_249 = V_250 ;
V_7 -> V_5 -> V_248 . V_251 = V_252 ;
V_7 -> V_5 -> V_248 . V_253 = V_7 -> V_236 . V_254 ;
F_51 ( V_7 ) ;
V_195 = F_66 ( V_7 -> V_5 ) ;
if ( ! V_195 ) {
F_33 ( L_5 ) ;
return - 1 ;
}
V_202 = F_83 ( V_7 -> V_5 ) ;
if ( ! V_202 ) {
F_33 ( L_6 ) ;
return - 1 ;
}
F_89 ( V_202 , V_195 ) ;
V_117 = F_90 ( V_7 ) ;
if ( V_117 ) {
F_33 ( L_7 ) ;
return V_117 ;
}
return 0 ;
}
void F_91 ( struct V_6 * V_7 )
{
}
