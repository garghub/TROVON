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
unsigned int V_47 [ V_48 ] = { 16 , 14 , 12 , 10 , 8 , 6 , 4 , 2 , 1 } ;
unsigned int V_49 ;
unsigned int V_12 ;
if ( V_7 -> V_50 <= 0x03 ) {
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
} else {
V_44 = V_45 = V_43 = 0 ;
V_34 = 1600000 ;
V_35 = 800000 ;
V_36 = 25000 ;
if ( clock < 25000 )
clock = 25000 ;
clock = clock * 2 ;
V_37 = 0xFFFFFFFF ;
V_39 = clock * 5 / 1000 ;
for ( V_12 = 0 ; V_12 < V_48 ; V_12 ++ ) {
V_40 = V_47 [ V_12 ] ;
if ( ( clock * V_40 ) > V_34 )
continue;
if ( ( clock * V_40 ) < V_35 )
continue;
for ( V_42 = 50 ; V_42 <= 256 ; V_42 ++ ) {
for ( V_41 = 1 ; V_41 <= 32 ; V_41 ++ ) {
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
V_49 = V_36 * V_42 / V_41 ;
V_49 = ( V_49 - 800000 ) / 50000 ;
if ( V_49 > 15 )
V_49 = 15 ;
V_43 |= ( V_49 << 4 ) ;
V_44 |= 0x80 ;
clock = clock / 2 ;
}
if ( V_37 > V_39 ) {
F_11 ( V_51 L_1 ) ;
return 1 ;
}
F_12 ( V_52 , V_44 ) ;
F_12 ( V_53 , V_45 ) ;
F_12 ( V_54 , V_43 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , long clock )
{
unsigned int V_34 , V_35 , V_36 ;
unsigned int V_37 , V_38 ;
unsigned int V_40 , V_41 , V_42 , V_55 ;
unsigned int V_43 , V_44 , V_45 ;
unsigned int V_46 ;
int V_12 , V_56 , V_57 , V_58 ;
bool V_59 = false ;
T_1 V_60 ;
V_44 = V_45 = V_43 = 0 ;
V_37 = 0xffffffff ;
if ( V_7 -> type == V_61 ) {
V_34 = 800000 ;
V_35 = 400000 ;
V_36 = 25000 ;
for ( V_40 = 1 ; V_40 < 8 ; V_40 ++ ) {
for ( V_55 = 1 ; V_55 < 8 ; V_55 ++ ) {
if ( V_40 < V_55 )
continue;
if ( ( clock * V_40 * V_55 ) > V_34 )
continue;
if ( ( clock * V_40 * V_55 ) < V_35 )
continue;
for ( V_41 = 1 ; V_41 < 26 ; V_41 ++ ) {
for ( V_42 = 32 ; V_42 < 2048 ; V_42 ++ ) {
V_46 = ( V_36 * V_42 ) /
( V_41 * V_40 * V_55 ) ;
if ( V_46 > clock )
V_38 = V_46 - clock ;
else
V_38 = clock - V_46 ;
if ( V_38 < V_37 ) {
V_37 = V_38 ;
V_44 = ( ( V_42 & 0x100 ) >> 1 ) |
( V_41 ) ;
V_45 = ( V_42 & 0xFF ) ;
V_43 = ( ( V_42 & 0x600 ) >> 3 ) |
( V_55 << 3 ) |
( V_40 ) ;
}
}
}
}
}
} else {
V_34 = 550000 ;
V_35 = 150000 ;
V_36 = 48000 ;
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
V_44 = ( V_41 - 1 ) |
( ( V_45 >> 1 ) & 0x80 ) ;
V_43 = V_40 - 1 ;
}
}
}
}
}
for ( V_12 = 0 ; V_12 <= 32 && V_59 == false ; V_12 ++ ) {
if ( V_12 > 0 ) {
F_3 ( V_62 , 0x1e ) ;
V_60 = F_8 ( V_63 ) ;
if ( V_60 < 0xff )
F_3 ( V_63 , V_60 + 1 ) ;
}
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= V_66 ;
F_3 ( V_65 , V_60 ) ;
F_3 ( V_14 , V_67 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= V_68 ;
F_3 ( V_65 , V_60 ) ;
V_60 = F_8 ( V_69 ) ;
V_60 |= 0x3 << 2 ;
F_3 ( V_70 , V_60 ) ;
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= V_71 | 0x80 ;
F_3 ( V_65 , V_60 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_72 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ 0x04 ;
F_3 ( V_65 , V_60 ) ;
F_14 ( 50 ) ;
F_12 ( V_73 , V_45 ) ;
F_12 ( V_74 , V_44 ) ;
F_12 ( V_75 , V_43 ) ;
F_14 ( 50 ) ;
F_3 ( V_14 , V_72 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= 0x04 ;
F_12 ( V_72 , V_60 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ V_76 ;
V_60 |= V_77 ;
F_3 ( V_65 , V_60 ) ;
F_3 ( V_14 , V_67 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ V_78 ;
V_60 |= V_79 ;
F_3 ( V_65 , V_60 ) ;
F_3 ( V_80 , 1 ) ;
V_60 = F_8 ( V_81 ) ;
V_60 &= ~ 0x8 ;
F_3 ( V_81 , V_60 ) ;
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ V_66 ;
F_3 ( V_65 , V_60 ) ;
V_58 = F_8 ( V_82 ) ;
for ( V_56 = 0 ; V_56 < 30 && V_59 == false ; V_56 ++ ) {
V_57 = F_8 ( V_82 ) ;
if ( V_57 < V_58 )
V_58 = 0 ;
if ( ( V_57 - V_58 ) > 2 )
V_59 = true ;
else
F_14 ( 5 ) ;
}
}
F_3 ( V_14 , V_67 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ V_68 ;
F_12 ( V_67 , V_60 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , long clock )
{
unsigned int V_34 , V_35 , V_36 ;
unsigned int V_37 , V_38 ;
unsigned int V_40 , V_41 , V_42 ;
unsigned int V_43 , V_44 , V_45 ;
unsigned int V_46 ;
T_1 V_60 ;
V_44 = V_45 = V_43 = 0 ;
V_34 = 550000 ;
V_35 = 150000 ;
V_36 = 50000 ;
V_37 = 0xffffffff ;
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
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= V_66 ;
F_3 ( V_65 , V_60 ) ;
V_60 = F_8 ( V_69 ) ;
V_60 |= 0x3 << 2 ;
F_3 ( V_70 , V_60 ) ;
F_3 ( V_14 , V_83 ) ;
V_60 = F_8 ( V_65 ) ;
F_3 ( V_65 , V_60 & ~ 0x40 ) ;
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= V_71 ;
F_3 ( V_65 , V_60 ) ;
F_12 ( V_84 , V_44 ) ;
F_12 ( V_85 , V_45 ) ;
F_12 ( V_86 , V_43 ) ;
F_14 ( 50 ) ;
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ V_71 ;
F_3 ( V_65 , V_60 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ V_76 ;
V_60 |= V_77 ;
F_3 ( V_65 , V_60 ) ;
F_3 ( V_14 , V_83 ) ;
V_60 = F_8 ( V_65 ) ;
F_3 ( V_65 , V_60 | 0x40 ) ;
V_60 = F_8 ( V_69 ) ;
V_60 |= ( 0x3 << 2 ) ;
F_3 ( V_70 , V_60 ) ;
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ V_66 ;
F_3 ( V_65 , V_60 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , long clock )
{
unsigned int V_34 , V_35 , V_36 ;
unsigned int V_37 , V_38 ;
unsigned int V_40 , V_41 , V_42 ;
unsigned int V_43 , V_44 , V_45 ;
unsigned int V_46 ;
int V_12 , V_56 , V_57 , V_58 ;
T_1 V_60 ;
bool V_59 = false ;
V_44 = V_45 = V_43 = 0 ;
V_34 = 800000 ;
V_35 = 400000 ;
V_36 = 33333 ;
V_37 = 0xffffffff ;
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
for ( V_12 = 0 ; V_12 <= 32 && V_59 == false ; V_12 ++ ) {
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= V_66 ;
F_3 ( V_65 , V_60 ) ;
V_60 = F_8 ( V_69 ) ;
V_60 |= 0x3 << 2 ;
F_3 ( V_70 , V_60 ) ;
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= V_71 ;
F_3 ( V_65 , V_60 ) ;
F_14 ( 500 ) ;
F_12 ( V_87 , V_44 ) ;
F_12 ( V_88 , V_45 ) ;
F_12 ( V_89 , V_43 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ V_76 ;
V_60 |= V_77 ;
F_3 ( V_65 , V_60 ) ;
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ V_66 ;
V_60 &= ~ V_71 ;
F_3 ( V_65 , V_60 ) ;
V_58 = F_8 ( V_82 ) ;
for ( V_56 = 0 ; V_56 < 30 && V_59 == false ; V_56 ++ ) {
V_57 = F_8 ( V_82 ) ;
if ( V_57 < V_58 )
V_58 = 0 ;
if ( ( V_57 - V_58 ) > 2 )
V_59 = true ;
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
int V_90 , V_42 , V_41 , V_91 ;
unsigned int V_43 , V_44 , V_45 ;
unsigned int V_46 , V_92 ;
int V_60 ;
const unsigned int V_93 [] = { 1 , 2 , 4 , 8 } ;
V_44 = V_45 = V_43 = 0 ;
V_34 = 1488000 ;
V_35 = 1056000 ;
V_36 = 48000 ;
V_37 = 0xffffffff ;
for ( V_90 = 0 ; V_90 < 4 ; V_90 ++ ) {
if ( V_37 == 0 )
break;
for ( V_42 = 5 ; V_42 < 129 ; V_42 ++ ) {
if ( V_37 == 0 )
break;
for ( V_41 = 3 ; V_41 >= 0 ; V_41 -- ) {
if ( V_37 == 0 )
break;
for ( V_91 = 5 ; V_91 < 33 ; V_91 ++ ) {
V_92 = V_36 * ( V_42 + 1 ) /
( V_90 + 1 ) ;
if ( V_92 < V_35 )
continue;
if ( V_92 > V_34 )
continue;
V_46 = V_92 / ( V_93 [ V_41 ] * ( V_91 + 1 ) ) ;
if ( V_46 > clock )
V_38 = V_46 - clock ;
else
V_38 = clock - V_46 ;
if ( V_38 < V_37 ) {
V_37 = V_38 ;
V_44 = V_41 | ( V_91 << 3 ) ;
V_45 = V_42 ;
V_43 = V_90 | ( V_90 << 3 ) ;
}
}
}
}
}
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= V_66 ;
F_3 ( V_65 , V_60 ) ;
F_3 ( V_14 , V_67 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= V_68 ;
F_3 ( V_65 , V_60 ) ;
V_60 = F_8 ( V_69 ) ;
V_60 |= ( 0x3 << 2 ) | 0xc0 ;
F_3 ( V_70 , V_60 ) ;
F_3 ( V_14 , V_64 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ V_66 ;
V_60 |= V_71 ;
F_3 ( V_65 , V_60 ) ;
F_14 ( 500 ) ;
F_12 ( V_94 , V_45 ) ;
F_12 ( V_95 , V_44 ) ;
F_12 ( V_96 , V_43 ) ;
F_14 ( 50 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , long clock )
{
switch( V_7 -> type ) {
case V_97 :
case V_98 :
return F_10 ( V_7 , clock ) ;
break;
case V_99 :
case V_61 :
return F_13 ( V_7 , clock ) ;
break;
case V_100 :
return F_15 ( V_7 , clock ) ;
break;
case V_101 :
return F_16 ( V_7 , clock ) ;
break;
case V_102 :
return F_17 ( V_7 , clock ) ;
break;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_1 V_60 ;
int V_103 ;
F_3 ( V_14 , V_104 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= 0x10 ;
F_12 ( V_104 , V_60 ) ;
F_3 ( V_14 , V_105 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= 0x10 ;
F_12 ( V_105 , V_60 ) ;
F_3 ( V_14 , V_106 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= 0x80 ;
F_12 ( V_106 , V_60 ) ;
V_103 = 300 ;
while ( ! ( V_60 & 0x1 ) && V_103 ) {
F_3 ( V_14 , V_106 ) ;
V_60 = F_8 ( V_65 ) ;
F_14 ( 1000 ) ;
V_103 -- ;
}
if ( V_103 ) {
V_103 = 300 ;
while ( ( V_60 & 0x2 ) && V_103 ) {
F_3 ( V_14 , V_106 ) ;
V_60 = F_8 ( V_65 ) ;
F_14 ( 1000 ) ;
V_103 -- ;
}
}
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_60 ;
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
F_3 ( V_107 , 1 ) ;
V_60 = F_8 ( V_108 ) ;
F_3 ( V_108 , V_60 | 0x88 ) ;
F_3 ( V_14 , V_109 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 |= 0x8 ;
F_3 ( V_65 , V_60 ) ;
F_14 ( 10 ) ;
V_60 &= ~ 0x08 ;
F_3 ( V_14 , V_109 ) ;
F_3 ( V_65 , V_60 ) ;
F_3 ( V_14 , V_106 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ 0x80 ;
F_3 ( V_65 , V_60 ) ;
F_3 ( V_14 , V_105 ) ;
V_60 = F_8 ( V_65 ) ;
V_60 &= ~ 0x10 ;
F_12 ( V_105 , V_60 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned V_110 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_2 V_111 ;
int V_112 ;
T_1 V_113 ;
while ( F_8 ( 0x1fda ) & 0x08 ) ;
while ( ! ( F_8 ( 0x1fda ) & 0x08 ) ) ;
V_112 = F_8 ( V_82 ) + 2 ;
while ( F_8 ( V_82 ) < V_112 ) ;
F_3 ( V_107 , 0 ) ;
V_113 = F_8 ( V_108 ) ;
V_113 &= 0xB0 ;
V_111 = V_110 / 8 ;
F_22 ( V_111 > 0x1fffff ) ;
V_113 |= ( ! ! ( V_111 & ( 1 << 20 ) ) ) << 6 ;
F_23 ( 0x0d , ( T_1 ) ( V_111 & 0xff ) ) ;
F_23 ( 0x0c , ( T_1 ) ( V_111 >> 8 ) & 0xff ) ;
F_24 ( 0x0 , ( ( T_1 ) ( V_111 >> 16 ) & 0xf ) | V_113 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
int V_114 , int V_115 , int V_116 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
int V_123 ;
T_3 V_124 ;
if ( ! V_116 && V_10 ) {
V_120 = F_26 ( V_10 ) ;
V_118 = V_120 -> V_118 ;
V_122 = F_27 ( V_118 ) ;
V_123 = F_28 ( V_122 , false ) ;
if ( V_123 )
return V_123 ;
F_29 ( V_122 ) ;
F_30 ( V_122 ) ;
}
V_120 = F_26 ( V_2 -> V_11 -> V_10 ) ;
V_118 = V_120 -> V_118 ;
V_122 = F_27 ( V_118 ) ;
V_123 = F_28 ( V_122 , false ) ;
if ( V_123 )
return V_123 ;
V_123 = F_31 ( V_122 , V_125 , & V_124 ) ;
if ( V_123 ) {
F_30 ( V_122 ) ;
return V_123 ;
}
if ( & V_7 -> V_126 -> V_127 == V_120 ) {
V_123 = F_32 ( & V_122 -> V_122 , 0 , V_122 -> V_122 . V_128 , & V_122 -> V_129 ) ;
if ( V_123 )
F_33 ( L_2 ) ;
}
F_30 ( V_122 ) ;
F_21 ( V_2 , ( T_2 ) V_124 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_114 , int V_115 ,
struct V_9 * V_130 )
{
return F_25 ( V_2 , V_130 , V_114 , V_115 , 0 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_31 * V_33 ,
int V_114 , int V_115 , struct V_9 * V_130 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_131 , V_132 , V_133 , V_134 ;
int V_135 , V_136 , V_137 , V_138 ;
int V_139 ;
int V_140 = 0 , V_141 = 0 ;
int V_12 ;
unsigned char V_142 = 0 ;
unsigned char V_143 [ 6 ] ;
T_1 V_144 ;
static unsigned char V_145 [] = {
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
V_144 = V_7 -> V_146 [ ( V_2 -> V_11 -> V_10 -> V_16 >> 3 ) - 1 ] ;
switch ( V_7 -> type ) {
case V_97 :
case V_98 :
V_145 [ V_72 ] = 0x03 ;
V_145 [ V_64 ] = V_77 ;
V_145 [ V_147 ] = V_148 |
V_149 |
V_150 ;
if ( V_7 -> V_151 )
V_140 = 0x40049120 ;
else
V_140 = 0x4004d120 ;
V_141 = 0x00008000 ;
break;
case V_99 :
case V_61 :
V_145 [ V_72 ] = 0x07 ;
V_140 = 0x41049120 ;
V_141 = 0x0000b000 ;
break;
case V_100 :
V_145 [ V_64 ] = V_77 ;
V_145 [ V_147 ] = V_149 |
V_150 ;
V_140 = 0x00000120 ;
V_141 = 0x0000b000 ;
break;
case V_101 :
V_145 [ V_147 ] = V_149 |
V_150 ;
V_140 = 0x00000120 ;
V_141 = 0x0000b000 ;
break;
case V_102 :
break;
}
switch ( V_2 -> V_11 -> V_10 -> V_16 ) {
case 8 :
V_145 [ V_152 ] = V_153 ;
break;
case 16 :
if ( V_2 -> V_11 -> V_10 -> V_18 == 15 )
V_145 [ V_152 ] = V_154 ;
else
V_145 [ V_152 ] = V_155 ;
break;
case 24 :
V_145 [ V_152 ] = V_156 ;
break;
case 32 :
V_145 [ V_152 ] = V_157 ;
break;
}
if ( V_32 -> V_158 & V_159 )
V_142 |= 0x40 ;
if ( V_32 -> V_158 & V_160 )
V_142 |= 0x80 ;
for ( V_12 = 0 ; V_12 < sizeof( V_145 ) ; V_12 ++ ) {
if ( ( V_12 <= 0x17 ) ||
( V_12 == 0x1b ) ||
( V_12 == 0x1c ) ||
( ( V_12 >= 0x1f ) && ( V_12 <= 0x29 ) ) ||
( ( V_12 >= 0x30 ) && ( V_12 <= 0x37 ) ) )
continue;
if ( F_36 ( V_7 ) &&
( ( V_12 == 0x2c ) || ( V_12 == 0x2d ) || ( V_12 == 0x2e ) ) )
continue;
if ( ( V_7 -> type == V_100 ||
V_7 -> type == V_99 ||
V_7 -> type == V_101 ||
V_7 -> type == V_61 ) &&
( V_12 >= 0x44 ) && ( V_12 <= 0x4e ) )
continue;
F_12 ( V_12 , V_145 [ V_12 ] ) ;
}
if ( V_7 -> type == V_102 )
F_12 ( 0x90 , 0 ) ;
if ( V_140 )
F_37 ( V_5 -> V_161 , V_162 , V_140 ) ;
if ( V_141 )
F_37 ( V_5 -> V_161 , V_163 , V_141 ) ;
F_38 ( 2 , 0xf ) ;
F_38 ( 3 , 0 ) ;
F_38 ( 4 , 0xe ) ;
V_139 = V_2 -> V_11 -> V_10 -> V_164 [ 0 ] / ( V_2 -> V_11 -> V_10 -> V_16 / 8 ) ;
if ( V_2 -> V_11 -> V_10 -> V_16 == 24 )
V_139 = ( V_139 * 3 ) >> ( 4 - V_144 ) ;
else
V_139 = V_139 >> ( 4 - V_144 ) ;
V_131 = V_32 -> V_131 / 8 - 1 ;
V_132 = V_32 -> V_165 / 8 - 1 ;
V_133 = V_32 -> V_166 / 8 - 1 ;
V_134 = V_32 -> V_134 / 8 - 1 ;
if ( ( V_134 & 0x07 ) == 0x06 || ( V_134 & 0x07 ) == 0x04 )
V_134 ++ ;
V_135 = V_32 -> V_135 - 1 ;
V_136 = V_32 -> V_167 - 1 ;
V_137 = V_32 -> V_168 - 1 ;
V_138 = V_32 -> V_138 - 2 ;
F_39 ( 0 , 0 ) ;
F_39 ( 1 , 0 ) ;
F_39 ( 2 , 0 ) ;
F_39 ( 3 , 0 ) ;
F_39 ( 4 , 0 ) ;
F_39 ( 5 , 0x40 ) ;
F_39 ( 6 , 0x5 ) ;
F_39 ( 7 , 0xf ) ;
F_39 ( 8 , 0xf ) ;
F_23 ( 0 , V_134 - 4 ) ;
F_23 ( 1 , V_131 ) ;
F_23 ( 2 , V_131 ) ;
F_23 ( 3 , ( V_134 & 0x1F ) | 0x80 ) ;
F_23 ( 4 , V_132 ) ;
F_23 ( 5 , ( ( V_134 & 0x20 ) << 2 ) | ( V_133 & 0x1F ) ) ;
F_23 ( 6 , V_138 & 0xFF ) ;
F_23 ( 7 , ( ( V_138 & 0x100 ) >> 8 ) |
( ( V_135 & 0x100 ) >> 7 ) |
( ( V_136 & 0x100 ) >> 6 ) |
( ( V_135 & 0x100 ) >> 5 ) |
( ( V_135 & 0x100 ) >> 4 ) |
( ( V_138 & 0x200 ) >> 4 ) |
( ( V_135 & 0x200 ) >> 3 ) |
( ( V_136 & 0x200 ) >> 2 ) ) ;
F_23 ( 9 , ( ( V_135 & 0x200 ) >> 4 ) |
( ( V_135 & 0x200 ) >> 3 ) ) ;
F_23 ( 10 , 0 ) ;
F_23 ( 11 , 0 ) ;
F_23 ( 12 , 0 ) ;
F_23 ( 13 , 0 ) ;
F_23 ( 14 , 0 ) ;
F_23 ( 15 , 0 ) ;
F_23 ( 16 , V_136 & 0xFF ) ;
F_23 ( 17 , ( V_137 & 0x0F ) | 0x20 ) ;
F_23 ( 18 , V_135 & 0xFF ) ;
F_23 ( 19 , V_139 & 0xFF ) ;
F_23 ( 20 , 0 ) ;
F_23 ( 21 , V_135 & 0xFF ) ;
F_23 ( 22 , ( V_138 + 1 ) & 0xFF ) ;
F_23 ( 23 , 0xc3 ) ;
F_23 ( 24 , V_135 & 0xFF ) ;
V_143 [ 0 ] = 0 ;
V_143 [ 5 ] = 0 ;
V_143 [ 0 ] |= ( V_139 & 0x300 ) >> 4 ;
V_143 [ 1 ] = ( ( ( V_134 - 4 ) & 0x100 ) >> 8 ) |
( ( V_131 & 0x100 ) >> 7 ) |
( ( V_132 & 0x100 ) >> 6 ) |
( V_134 & 0x40 ) ;
V_143 [ 2 ] = ( ( V_138 & 0xc00 ) >> 10 ) |
( ( V_135 & 0x400 ) >> 8 ) |
( ( V_135 & 0xc00 ) >> 7 ) |
( ( V_136 & 0xc00 ) >> 5 ) |
( ( V_135 & 0x400 ) >> 3 ) ;
if ( V_2 -> V_11 -> V_10 -> V_16 == 24 )
V_143 [ 3 ] = ( ( ( 1 << V_144 ) * 3 ) - 1 ) | 0x80 ;
else
V_143 [ 3 ] = ( ( 1 << V_144 ) - 1 ) | 0x80 ;
V_143 [ 4 ] = 0 ;
if ( V_7 -> type == V_99 || V_7 -> type == V_61 )
V_143 [ 1 ] |= 0x88 ;
V_142 = 0x2d ;
F_3 ( V_169 , V_142 ) ;
F_18 ( V_7 , V_32 -> clock ) ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
F_24 ( V_12 , V_143 [ V_12 ] ) ;
}
if ( V_7 -> type == V_102 )
F_24 ( 0x24 , 0x5 ) ;
if ( V_7 -> type == V_61 )
F_24 ( 0x34 , 0x5 ) ;
if ( V_7 -> type == V_100 ) {
F_24 ( 6 , 0 ) ;
}
F_24 ( 0 , V_143 [ 0 ] ) ;
V_142 = 0x2d ;
F_3 ( V_169 , V_142 ) ;
if ( V_33 )
memcpy ( & V_7 -> V_32 , V_32 , sizeof( struct V_31 ) ) ;
F_25 ( V_2 , V_130 , V_114 , V_115 , 0 ) ;
if ( V_7 -> type == V_102 ) {
T_2 V_170 = F_5 ( V_171 ) ;
T_1 V_172 ;
F_3 ( V_80 , 0x01 ) ;
V_172 = F_8 ( V_81 ) | 0x20 ;
F_3 ( V_81 , V_172 ) ;
F_40 ( V_171 , V_170 | 0x00200000 ) ;
F_14 ( 1000 ) ;
F_40 ( V_171 , V_170 & ~ 0x00200000 ) ;
F_3 ( V_81 , V_172 & ~ 0x20 ) ;
}
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_50 >= 0x02 ) {
T_1 V_173 ;
T_2 V_174 ;
T_2 V_175 ;
if ( V_2 -> V_11 -> V_10 -> V_16 > 16 )
V_174 = 32 ;
else if ( V_2 -> V_11 -> V_10 -> V_16 > 8 )
V_174 = 16 ;
else
V_174 = 8 ;
V_175 = ( V_32 -> clock * V_174 ) / 1000 ;
if ( V_175 > 3100 )
V_173 = 0 ;
else if ( V_175 > 2600 )
V_173 = 1 ;
else if ( V_175 > 1900 )
V_173 = 2 ;
else if ( V_175 > 1160 )
V_173 = 3 ;
else if ( V_175 > 440 )
V_173 = 4 ;
else
V_173 = 5 ;
F_3 ( V_107 , 0x06 ) ;
F_3 ( V_108 , V_173 ) ;
} else {
F_3 ( V_107 , 0x06 ) ;
if ( V_7 -> V_50 >= 0x01 )
F_3 ( V_108 , 0x03 ) ;
else
F_3 ( V_108 , 0x04 ) ;
}
}
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , int V_32 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_172 = 0 , V_176 = 0 ;
switch ( V_32 ) {
case V_177 :
V_172 = 0 ;
V_176 = 0 ;
F_1 ( V_2 ) ;
break;
case V_178 :
V_172 = 0x20 ;
V_176 = 0x10 ;
break;
case V_179 :
V_172 = 0x20 ;
V_176 = 0x20 ;
break;
case V_180 :
V_172 = 0x20 ;
V_176 = 0x30 ;
break;
}
#if 0
if (mode == DRM_MODE_DPMS_OFF) {
mga_suspend(crtc);
}
#endif
F_3 ( V_80 , 0x01 ) ;
V_172 |= F_8 ( V_81 ) & ~ 0x20 ;
F_4 ( V_7 ) ;
F_7 ( V_7 ) ;
F_3 ( V_81 , V_172 ) ;
F_42 ( 20 ) ;
F_3 ( V_107 , 0x01 ) ;
V_176 |= F_8 ( V_108 ) & ~ 0x30 ;
F_3 ( V_108 , V_176 ) ;
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
T_1 V_60 ;
F_3 ( V_62 , 0x11 ) ;
V_60 = F_8 ( V_63 ) ;
F_23 ( 0x11 , V_60 | 0x80 ) ;
if ( V_7 -> type == V_97 || V_7 -> type == V_98 ) {
F_38 ( 0 , 1 ) ;
F_42 ( 50 ) ;
F_38 ( 1 , 0x20 ) ;
F_42 ( 20 ) ;
} else {
F_3 ( V_80 , 0x1 ) ;
V_60 = F_8 ( V_81 ) ;
F_38 ( 0 , 1 ) ;
F_38 ( 1 , V_60 | 0x20 ) ;
}
if ( V_7 -> type == V_99 || V_7 -> type == V_61 )
F_19 ( V_2 ) ;
F_23 ( 17 , 0 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_181 * V_182 = V_2 -> V_183 ;
T_1 V_60 ;
if ( V_7 -> type == V_99 || V_7 -> type == V_61 )
F_20 ( V_2 ) ;
if ( V_7 -> type == V_97 || V_7 -> type == V_98 ) {
F_42 ( 50 ) ;
F_38 ( 1 , 0x0 ) ;
F_42 ( 20 ) ;
F_38 ( 0 , 0x3 ) ;
} else {
F_3 ( V_80 , 0x1 ) ;
V_60 = F_8 ( V_81 ) ;
V_60 &= ~ 0x20 ;
F_38 ( 0x1 , V_60 ) ;
F_38 ( 0 , 3 ) ;
}
V_182 -> V_184 ( V_2 , V_177 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_4 * V_185 , T_4 * V_186 ,
T_4 * V_187 , T_5 V_188 , T_5 V_189 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_190 = ( V_188 + V_189 > V_21 ) ? V_21 : V_188 + V_189 ;
int V_12 ;
for ( V_12 = V_188 ; V_12 < V_190 ; V_12 ++ ) {
V_3 -> V_22 [ V_12 ] = V_185 [ V_12 ] >> 8 ;
V_3 -> V_25 [ V_12 ] = V_186 [ V_12 ] >> 8 ;
V_3 -> V_23 [ V_12 ] = V_187 [ V_12 ] >> 8 ;
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
int V_123 ;
F_50 ( L_3 ) ;
F_41 ( V_2 , V_180 ) ;
if ( V_2 -> V_11 -> V_10 ) {
struct V_119 * V_120 = F_26 ( V_2 -> V_11 -> V_10 ) ;
struct V_117 * V_118 = V_120 -> V_118 ;
struct V_121 * V_122 = F_27 ( V_118 ) ;
V_123 = F_28 ( V_122 , false ) ;
if ( V_123 )
return;
F_29 ( V_122 ) ;
F_30 ( V_122 ) ;
}
V_2 -> V_11 -> V_10 = NULL ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_3 * V_3 ;
int V_12 ;
V_3 = F_52 ( sizeof( struct V_3 ) +
( V_191 * sizeof( struct V_192 * ) ) ,
V_193 ) ;
if ( V_3 == NULL )
return;
F_53 ( V_7 -> V_5 , & V_3 -> V_194 , & V_195 ) ;
F_54 ( & V_3 -> V_194 , V_21 ) ;
V_7 -> V_196 . V_2 = V_3 ;
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ ) {
V_3 -> V_22 [ V_12 ] = V_12 ;
V_3 -> V_25 [ V_12 ] = V_12 ;
V_3 -> V_23 [ V_12 ] = V_12 ;
}
F_55 ( & V_3 -> V_194 , & V_197 ) ;
}
void F_56 ( struct V_1 * V_2 , T_4 V_185 , T_4 V_186 ,
T_4 V_187 , int V_198 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_22 [ V_198 ] = V_185 >> 8 ;
V_3 -> V_25 [ V_198 ] = V_186 >> 8 ;
V_3 -> V_23 [ V_198 ] = V_187 >> 8 ;
}
void F_57 ( struct V_1 * V_2 , T_4 * V_185 , T_4 * V_186 ,
T_4 * V_187 , int V_198 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_185 = ( T_4 ) V_3 -> V_22 [ V_198 ] << 8 ;
* V_186 = ( T_4 ) V_3 -> V_25 [ V_198 ] << 8 ;
* V_187 = ( T_4 ) V_3 -> V_23 [ V_198 ] << 8 ;
}
static bool F_58 ( struct V_199 * V_200 ,
const struct V_31 * V_32 ,
struct V_31 * V_33 )
{
return true ;
}
static void F_59 ( struct V_199 * V_200 ,
struct V_31 * V_32 ,
struct V_31 * V_33 )
{
}
static void F_60 ( struct V_199 * V_200 , int V_201 )
{
return;
}
static void F_61 ( struct V_199 * V_200 )
{
}
static void F_62 ( struct V_199 * V_200 )
{
}
static void F_63 ( struct V_199 * V_200 )
{
struct V_202 * V_202 = F_64 ( V_200 ) ;
F_65 ( V_200 ) ;
F_48 ( V_202 ) ;
}
static struct V_199 * F_66 ( struct V_4 * V_5 )
{
struct V_199 * V_200 ;
struct V_202 * V_202 ;
V_202 = F_52 ( sizeof( struct V_202 ) , V_193 ) ;
if ( ! V_202 )
return NULL ;
V_200 = & V_202 -> V_194 ;
V_200 -> V_203 = 0x1 ;
F_67 ( V_5 , V_200 , & V_204 ,
V_205 ) ;
F_68 ( V_200 , & V_206 ) ;
return V_200 ;
}
static int F_69 ( struct V_192 * V_207 )
{
struct V_208 * V_208 = F_70 ( V_207 ) ;
struct V_209 * V_209 ;
int V_123 = 0 ;
V_209 = F_71 ( V_207 , & V_208 -> V_210 -> V_211 ) ;
if ( V_209 ) {
F_72 ( V_207 , V_209 ) ;
V_123 = F_73 ( V_207 , V_209 ) ;
F_48 ( V_209 ) ;
}
return V_123 ;
}
static T_5 F_74 ( struct V_31 * V_32 ,
int V_16 )
{
T_5 V_212 , V_213 ;
T_6 V_214 , V_215 , V_216 ;
T_7 V_217 = ( V_16 + 7 ) / 8 ;
V_213 = 1024 ;
if ( ! V_32 -> V_134 || ! V_32 -> V_138 || ! V_32 -> clock )
return 0 ;
V_214 = V_32 -> V_131 * V_32 -> V_135 ;
V_212 = V_32 -> V_134 * V_32 -> V_138 ;
V_215 = V_214 * V_32 -> clock * 1000 ;
F_75 ( V_215 , V_212 ) ;
V_216 = V_215 * V_217 * 100 ;
F_75 ( V_216 , V_213 ) ;
return ( T_5 ) ( V_216 ) ;
}
static int F_76 ( struct V_192 * V_207 ,
struct V_31 * V_32 )
{
struct V_4 * V_5 = V_207 -> V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_5 -> V_8 ;
int V_174 = 32 ;
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_50 == 0x01 ) {
if ( V_32 -> V_131 > 1600 )
return V_218 ;
if ( V_32 -> V_135 > 1200 )
return V_219 ;
if ( F_74 ( V_32 , V_174 )
> ( 24400 * 1024 ) )
return V_220 ;
} else if ( V_7 -> V_50 == 0x02 ) {
if ( V_32 -> V_131 > 1920 )
return V_218 ;
if ( V_32 -> V_135 > 1200 )
return V_219 ;
if ( F_74 ( V_32 , V_174 )
> ( 30100 * 1024 ) )
return V_220 ;
}
} else if ( V_7 -> type == V_99 ) {
if ( V_32 -> V_131 > 1280 )
return V_218 ;
if ( V_32 -> V_135 > 1024 )
return V_219 ;
if ( F_74 ( V_32 ,
V_174 > ( 31877 * 1024 ) ) )
return V_220 ;
} else if ( V_7 -> type == V_100 &&
( F_74 ( V_32 , V_174 )
> ( 32700 * 1024 ) ) ) {
return V_220 ;
} else if ( V_7 -> type == V_101 &&
( F_74 ( V_32 , V_174 )
> ( 37500 * 1024 ) ) ) {
return V_220 ;
} else if ( V_7 -> type == V_102 &&
( F_74 ( V_32 ,
V_174 ) > ( 55000 * 1024 ) ) ) {
return V_220 ;
}
if ( ( V_32 -> V_131 % 8 ) != 0 || ( V_32 -> V_165 % 8 ) != 0 ||
( V_32 -> V_166 % 8 ) != 0 || ( V_32 -> V_134 % 8 ) != 0 ) {
return V_221 ;
}
if ( V_32 -> V_222 > 2048 || V_32 -> V_223 > 4096 ||
V_32 -> V_224 > 4096 || V_32 -> V_225 > 4096 ||
V_32 -> V_226 > 2048 || V_32 -> V_227 > 4096 ||
V_32 -> V_228 > 4096 || V_32 -> V_229 > 4096 ) {
return V_230 ;
}
if ( V_207 -> V_231 . V_232 ) {
if ( V_207 -> V_231 . V_233 )
V_174 = V_207 -> V_231 . V_174 ;
}
if ( ( V_32 -> V_131 * V_32 -> V_135 * ( V_174 / 8 ) ) > V_7 -> V_234 . V_235 ) {
if ( V_207 -> V_231 . V_232 )
V_207 -> V_231 . V_232 = false ;
return V_230 ;
}
return V_236 ;
}
static struct V_199 * F_77 ( struct V_192
* V_207 )
{
int V_237 = V_207 -> V_238 [ 0 ] ;
if ( V_237 )
return F_78 ( V_207 -> V_5 , V_237 ) ;
return NULL ;
}
static enum V_239 F_79 ( struct V_192
* V_207 , bool V_240 )
{
return V_241 ;
}
static void F_80 ( struct V_192 * V_207 )
{
struct V_208 * V_208 = F_70 ( V_207 ) ;
F_81 ( V_208 -> V_210 ) ;
F_82 ( V_207 ) ;
F_48 ( V_207 ) ;
}
static struct V_192 * F_83 ( struct V_4 * V_5 )
{
struct V_192 * V_207 ;
struct V_208 * V_208 ;
V_208 = F_52 ( sizeof( struct V_208 ) , V_193 ) ;
if ( ! V_208 )
return NULL ;
V_207 = & V_208 -> V_194 ;
F_84 ( V_5 , V_207 ,
& V_242 , V_243 ) ;
F_85 ( V_207 , & V_244 ) ;
F_86 ( V_207 ) ;
V_208 -> V_210 = F_87 ( V_5 ) ;
if ( ! V_208 -> V_210 )
F_33 ( L_4 ) ;
return V_207 ;
}
int F_88 ( struct V_6 * V_7 )
{
struct V_199 * V_200 ;
struct V_192 * V_207 ;
int V_123 ;
V_7 -> V_196 . V_245 = true ;
V_7 -> V_5 -> V_246 . V_247 = V_248 ;
V_7 -> V_5 -> V_246 . V_249 = V_250 ;
V_7 -> V_5 -> V_246 . V_251 = V_7 -> V_234 . V_252 ;
F_51 ( V_7 ) ;
V_200 = F_66 ( V_7 -> V_5 ) ;
if ( ! V_200 ) {
F_33 ( L_5 ) ;
return - 1 ;
}
V_207 = F_83 ( V_7 -> V_5 ) ;
if ( ! V_207 ) {
F_33 ( L_6 ) ;
return - 1 ;
}
F_89 ( V_207 , V_200 ) ;
V_123 = F_90 ( V_7 ) ;
if ( V_123 ) {
F_33 ( L_7 ) ;
return V_123 ;
}
return 0 ;
}
void F_91 ( struct V_6 * V_7 )
{
}
