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
if ( V_10 && V_10 -> V_16 -> V_17 [ 0 ] * 8 == 16 ) {
int V_18 = ( V_10 -> V_16 -> V_19 == 15 ) ? 8 : 4 ;
T_1 V_20 , V_21 ;
for ( V_12 = 0 ; V_12 < V_22 ; V_12 += V_18 ) {
if ( V_10 -> V_16 -> V_19 == 16 ) {
if ( V_12 > ( V_22 >> 1 ) ) {
V_20 = V_21 = 0 ;
} else {
V_20 = V_3 -> V_23 [ V_12 << 1 ] ;
V_21 = V_3 -> V_24 [ V_12 << 1 ] ;
}
} else {
V_20 = V_3 -> V_23 [ V_12 ] ;
V_21 = V_3 -> V_24 [ V_12 ] ;
}
F_3 ( V_14 + V_25 , V_20 ) ;
F_3 ( V_14 + V_25 , V_3 -> V_26 [ V_12 ] ) ;
F_3 ( V_14 + V_25 , V_21 ) ;
}
return;
}
for ( V_12 = 0 ; V_12 < V_22 ; V_12 ++ ) {
F_3 ( V_14 + V_25 , V_3 -> V_23 [ V_12 ] ) ;
F_3 ( V_14 + V_25 , V_3 -> V_26 [ V_12 ] ) ;
F_3 ( V_14 + V_25 , V_3 -> V_24 [ V_12 ] ) ;
}
}
static inline void F_4 ( struct V_6 * V_7 )
{
unsigned long V_27 = V_28 + V_29 / 10 ;
unsigned int V_30 = 0 ;
do {
V_30 = F_5 ( V_31 ) ;
} while ( ( V_30 & 0x08 ) && F_6 ( V_28 , V_27 ) );
V_27 = V_28 + V_29 / 10 ;
V_30 = 0 ;
do {
V_30 = F_5 ( V_31 ) ;
} while ( ! ( V_30 & 0x08 ) && F_6 ( V_28 , V_27 ) );
}
static inline void F_7 ( struct V_6 * V_7 )
{
unsigned long V_27 = V_28 + V_29 ;
unsigned int V_30 = 0 ;
do {
V_30 = F_8 ( V_31 + 2 ) ;
} while ( ( V_30 & 0x01 ) && F_6 ( V_28 , V_27 ) );
}
static int F_9 ( struct V_6 * V_7 , long clock )
{
unsigned int V_32 , V_33 , V_34 ;
unsigned int V_35 , V_36 , V_37 ;
unsigned int V_38 , V_39 , V_40 ;
unsigned int V_41 , V_42 , V_43 ;
unsigned int V_44 ;
unsigned int V_45 [ V_46 ] = { 16 , 14 , 12 , 10 , 8 , 6 , 4 , 2 , 1 } ;
unsigned int V_47 ;
unsigned int V_12 ;
if ( V_7 -> V_48 <= 0x03 ) {
V_42 = V_43 = V_41 = 0 ;
V_32 = 320000 ;
V_33 = 160000 ;
V_34 = 25000 ;
V_35 = 0xffffffff ;
V_37 = clock * 5 / 1000 ;
for ( V_38 = 8 ; V_38 > 0 ; V_38 /= 2 ) {
if ( clock * V_38 > V_32 )
continue;
if ( clock * V_38 < V_33 )
continue;
for ( V_40 = 17 ; V_40 < 256 ; V_40 ++ ) {
for ( V_39 = 1 ; V_39 < 32 ; V_39 ++ ) {
V_44 = ( V_34 * V_40 ) /
( V_39 * V_38 ) ;
if ( V_44 > clock )
V_36 = V_44 - clock ;
else
V_36 = clock - V_44 ;
if ( V_36 < V_35 ) {
V_35 = V_36 ;
V_42 = V_39 - 1 ;
V_43 = V_40 - 1 ;
V_41 = V_38 - 1 ;
}
}
}
}
} else {
V_42 = V_43 = V_41 = 0 ;
V_32 = 1600000 ;
V_33 = 800000 ;
V_34 = 25000 ;
if ( clock < 25000 )
clock = 25000 ;
clock = clock * 2 ;
V_35 = 0xFFFFFFFF ;
V_37 = clock * 5 / 1000 ;
for ( V_12 = 0 ; V_12 < V_46 ; V_12 ++ ) {
V_38 = V_45 [ V_12 ] ;
if ( ( clock * V_38 ) > V_32 )
continue;
if ( ( clock * V_38 ) < V_33 )
continue;
for ( V_40 = 50 ; V_40 <= 256 ; V_40 ++ ) {
for ( V_39 = 1 ; V_39 <= 32 ; V_39 ++ ) {
V_44 = ( V_34 * V_40 ) /
( V_39 * V_38 ) ;
if ( V_44 > clock )
V_36 = V_44 - clock ;
else
V_36 = clock - V_44 ;
if ( V_36 < V_35 ) {
V_35 = V_36 ;
V_42 = V_39 - 1 ;
V_43 = V_40 - 1 ;
V_41 = V_38 - 1 ;
}
}
}
}
V_47 = V_34 * ( V_43 + 1 ) / ( V_42 + 1 ) ;
V_47 = ( V_47 - 800000 ) / 50000 ;
if ( V_47 > 15 )
V_47 = 15 ;
V_41 |= ( V_47 << 4 ) ;
V_42 |= 0x80 ;
clock = clock / 2 ;
}
if ( V_35 > V_37 ) {
F_10 ( V_49 L_1 ) ;
return 1 ;
}
F_11 ( V_50 , V_42 ) ;
F_11 ( V_51 , V_43 ) ;
F_11 ( V_52 , V_41 ) ;
if ( V_7 -> V_48 >= 0x04 ) {
F_11 ( 0x1a , 0x09 ) ;
F_12 ( 20 ) ;
F_11 ( 0x1a , 0x01 ) ;
}
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , long clock )
{
unsigned int V_32 , V_33 , V_34 ;
unsigned int V_35 , V_36 ;
unsigned int V_38 , V_39 , V_40 , V_53 ;
unsigned int V_41 , V_42 , V_43 ;
unsigned int V_44 ;
int V_12 , V_54 , V_55 , V_56 ;
bool V_57 = false ;
T_1 V_58 ;
V_42 = V_43 = V_41 = 0 ;
V_35 = 0xffffffff ;
if ( V_7 -> type == V_59 ) {
V_32 = 800000 ;
V_33 = 400000 ;
V_34 = 25000 ;
for ( V_38 = 1 ; V_38 < 8 ; V_38 ++ ) {
for ( V_53 = 1 ; V_53 < 8 ; V_53 ++ ) {
if ( V_38 < V_53 )
continue;
if ( ( clock * V_38 * V_53 ) > V_32 )
continue;
if ( ( clock * V_38 * V_53 ) < V_33 )
continue;
for ( V_39 = 1 ; V_39 < 26 ; V_39 ++ ) {
for ( V_40 = 32 ; V_40 < 2048 ; V_40 ++ ) {
V_44 = ( V_34 * V_40 ) /
( V_39 * V_38 * V_53 ) ;
if ( V_44 > clock )
V_36 = V_44 - clock ;
else
V_36 = clock - V_44 ;
if ( V_36 < V_35 ) {
V_35 = V_36 ;
V_42 = ( ( V_40 & 0x100 ) >> 1 ) |
( V_39 ) ;
V_43 = ( V_40 & 0xFF ) ;
V_41 = ( ( V_40 & 0x600 ) >> 3 ) |
( V_53 << 3 ) |
( V_38 ) ;
}
}
}
}
}
} else {
V_32 = 550000 ;
V_33 = 150000 ;
V_34 = 48000 ;
for ( V_38 = 1 ; V_38 < 9 ; V_38 ++ ) {
if ( clock * V_38 > V_32 )
continue;
if ( clock * V_38 < V_33 )
continue;
for ( V_39 = 1 ; V_39 < 17 ; V_39 ++ ) {
for ( V_40 = 1 ; V_40 < 151 ; V_40 ++ ) {
V_44 = ( V_34 * V_40 ) /
( V_39 * V_38 ) ;
if ( V_44 > clock )
V_36 = V_44 - clock ;
else
V_36 = clock - V_44 ;
if ( V_36 < V_35 ) {
V_35 = V_36 ;
V_43 = V_40 - 1 ;
V_42 = ( V_39 - 1 ) |
( ( V_43 >> 1 ) & 0x80 ) ;
V_41 = V_38 - 1 ;
}
}
}
}
}
for ( V_12 = 0 ; V_12 <= 32 && V_57 == false ; V_12 ++ ) {
if ( V_12 > 0 ) {
F_3 ( V_60 , 0x1e ) ;
V_58 = F_8 ( V_61 ) ;
if ( V_58 < 0xff )
F_3 ( V_61 , V_58 + 1 ) ;
}
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= V_64 ;
F_3 ( V_63 , V_58 ) ;
F_3 ( V_14 , V_65 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= V_66 ;
F_3 ( V_63 , V_58 ) ;
V_58 = F_8 ( V_67 ) ;
V_58 |= 0x3 << 2 ;
F_3 ( V_68 , V_58 ) ;
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= V_69 | 0x80 ;
F_3 ( V_63 , V_58 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_70 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ 0x04 ;
F_3 ( V_63 , V_58 ) ;
F_14 ( 50 ) ;
F_11 ( V_71 , V_43 ) ;
F_11 ( V_72 , V_42 ) ;
F_11 ( V_73 , V_41 ) ;
F_14 ( 50 ) ;
F_3 ( V_14 , V_70 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= 0x04 ;
F_11 ( V_70 , V_58 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ V_74 ;
V_58 |= V_75 ;
F_3 ( V_63 , V_58 ) ;
F_3 ( V_14 , V_65 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ V_76 ;
V_58 |= V_77 ;
F_3 ( V_63 , V_58 ) ;
F_3 ( V_78 , 1 ) ;
V_58 = F_8 ( V_79 ) ;
V_58 &= ~ 0x8 ;
F_3 ( V_79 , V_58 ) ;
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ V_64 ;
F_3 ( V_63 , V_58 ) ;
V_56 = F_8 ( V_80 ) ;
for ( V_54 = 0 ; V_54 < 30 && V_57 == false ; V_54 ++ ) {
V_55 = F_8 ( V_80 ) ;
if ( V_55 < V_56 )
V_56 = 0 ;
if ( ( V_55 - V_56 ) > 2 )
V_57 = true ;
else
F_14 ( 5 ) ;
}
}
F_3 ( V_14 , V_65 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ V_66 ;
F_11 ( V_65 , V_58 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , long clock )
{
unsigned int V_32 , V_33 , V_34 ;
unsigned int V_35 , V_36 ;
unsigned int V_38 , V_39 , V_40 ;
unsigned int V_41 , V_42 , V_43 ;
unsigned int V_44 ;
T_1 V_58 ;
V_42 = V_43 = V_41 = 0 ;
V_32 = 550000 ;
V_33 = 150000 ;
V_34 = 50000 ;
V_35 = 0xffffffff ;
for ( V_38 = 16 ; V_38 > 0 ; V_38 -- ) {
if ( clock * V_38 > V_32 )
continue;
if ( clock * V_38 < V_33 )
continue;
for ( V_40 = 1 ; V_40 < 257 ; V_40 ++ ) {
for ( V_39 = 1 ; V_39 < 17 ; V_39 ++ ) {
V_44 = ( V_34 * V_40 ) /
( V_39 * V_38 ) ;
if ( V_44 > clock )
V_36 = V_44 - clock ;
else
V_36 = clock - V_44 ;
if ( V_36 < V_35 ) {
V_35 = V_36 ;
V_43 = V_40 - 1 ;
V_42 = V_39 - 1 ;
V_41 = V_38 - 1 ;
}
}
}
}
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= V_64 ;
F_3 ( V_63 , V_58 ) ;
V_58 = F_8 ( V_67 ) ;
V_58 |= 0x3 << 2 ;
F_3 ( V_68 , V_58 ) ;
F_3 ( V_14 , V_81 ) ;
V_58 = F_8 ( V_63 ) ;
F_3 ( V_63 , V_58 & ~ 0x40 ) ;
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= V_69 ;
F_3 ( V_63 , V_58 ) ;
F_11 ( V_82 , V_42 ) ;
F_11 ( V_83 , V_43 ) ;
F_11 ( V_84 , V_41 ) ;
F_14 ( 50 ) ;
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ V_69 ;
F_3 ( V_63 , V_58 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ V_74 ;
V_58 |= V_75 ;
F_3 ( V_63 , V_58 ) ;
F_3 ( V_14 , V_81 ) ;
V_58 = F_8 ( V_63 ) ;
F_3 ( V_63 , V_58 | 0x40 ) ;
V_58 = F_8 ( V_67 ) ;
V_58 |= ( 0x3 << 2 ) ;
F_3 ( V_68 , V_58 ) ;
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ V_64 ;
F_3 ( V_63 , V_58 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , long clock )
{
unsigned int V_32 , V_33 , V_34 ;
unsigned int V_35 , V_36 ;
unsigned int V_38 , V_39 , V_40 ;
unsigned int V_41 , V_42 , V_43 ;
unsigned int V_44 ;
int V_12 , V_54 , V_55 , V_56 ;
T_1 V_58 ;
bool V_57 = false ;
V_42 = V_43 = V_41 = 0 ;
if ( V_7 -> type == V_85 ) {
V_32 = 3000000 ;
V_33 = 1500000 ;
V_34 = 25000 ;
V_35 = 0xffffffff ;
V_38 = 0 ;
for ( V_39 = 150 ; V_39 >= 6 ; V_39 -- ) {
if ( clock * V_39 > V_32 )
continue;
if ( clock * V_39 < V_33 )
continue;
for ( V_40 = 120 ; V_40 >= 60 ; V_40 -- ) {
V_44 = ( V_34 * V_40 ) / V_39 ;
if ( V_44 > clock )
V_36 = V_44 - clock ;
else
V_36 = clock - V_44 ;
if ( V_36 < V_35 ) {
V_35 = V_36 ;
V_43 = V_40 ;
V_42 = V_39 ;
V_41 = V_38 ;
}
if ( V_35 == 0 )
break;
}
if ( V_35 == 0 )
break;
}
} else {
V_32 = 800000 ;
V_33 = 400000 ;
V_34 = 33333 ;
V_35 = 0xffffffff ;
for ( V_38 = 16 ; V_38 > 0 ; V_38 >>= 1 ) {
if ( clock * V_38 > V_32 )
continue;
if ( clock * V_38 < V_33 )
continue;
for ( V_39 = 1 ; V_39 < 33 ; V_39 ++ ) {
for ( V_40 = 17 ; V_40 < 257 ; V_40 ++ ) {
V_44 = ( V_34 * V_40 ) /
( V_39 * V_38 ) ;
if ( V_44 > clock )
V_36 = V_44 - clock ;
else
V_36 = clock - V_44 ;
if ( V_36 < V_35 ) {
V_35 = V_36 ;
V_43 = V_40 - 1 ;
V_42 = ( V_39 - 1 ) ;
V_41 = V_38 - 1 ;
}
if ( ( clock * V_38 ) >= 600000 )
V_41 |= 0x80 ;
}
}
}
}
for ( V_12 = 0 ; V_12 <= 32 && V_57 == false ; V_12 ++ ) {
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= V_64 ;
F_3 ( V_63 , V_58 ) ;
V_58 = F_8 ( V_67 ) ;
V_58 |= 0x3 << 2 ;
F_3 ( V_68 , V_58 ) ;
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= V_69 ;
F_3 ( V_63 , V_58 ) ;
F_14 ( 500 ) ;
F_11 ( V_86 , V_42 ) ;
F_11 ( V_87 , V_43 ) ;
F_11 ( V_88 , V_41 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ V_74 ;
V_58 |= V_75 ;
F_3 ( V_63 , V_58 ) ;
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ V_64 ;
V_58 &= ~ V_69 ;
F_3 ( V_63 , V_58 ) ;
V_56 = F_8 ( V_80 ) ;
for ( V_54 = 0 ; V_54 < 30 && V_57 == false ; V_54 ++ ) {
V_55 = F_8 ( V_80 ) ;
if ( V_55 < V_56 )
V_56 = 0 ;
if ( ( V_55 - V_56 ) > 2 )
V_57 = true ;
else
F_14 ( 5 ) ;
}
}
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , long clock )
{
unsigned int V_32 , V_33 , V_34 ;
unsigned int V_35 , V_36 ;
int V_89 , V_40 , V_39 , V_90 ;
unsigned int V_41 , V_42 , V_43 ;
unsigned int V_44 , V_91 ;
int V_58 ;
const unsigned int V_92 [] = { 1 , 2 , 4 , 8 } ;
V_42 = V_43 = V_41 = 0 ;
V_32 = 1488000 ;
V_33 = 1056000 ;
V_34 = 48000 ;
V_35 = 0xffffffff ;
for ( V_89 = 0 ; V_89 < 4 ; V_89 ++ ) {
if ( V_35 == 0 )
break;
for ( V_40 = 5 ; V_40 < 129 ; V_40 ++ ) {
if ( V_35 == 0 )
break;
for ( V_39 = 3 ; V_39 >= 0 ; V_39 -- ) {
if ( V_35 == 0 )
break;
for ( V_90 = 5 ; V_90 < 33 ; V_90 ++ ) {
V_91 = V_34 * ( V_40 + 1 ) /
( V_89 + 1 ) ;
if ( V_91 < V_33 )
continue;
if ( V_91 > V_32 )
continue;
V_44 = V_91 / ( V_92 [ V_39 ] * ( V_90 + 1 ) ) ;
if ( V_44 > clock )
V_36 = V_44 - clock ;
else
V_36 = clock - V_44 ;
if ( V_36 < V_35 ) {
V_35 = V_36 ;
V_42 = V_39 | ( V_90 << 3 ) ;
V_43 = V_40 ;
V_41 = V_89 | ( V_89 << 3 ) ;
}
}
}
}
}
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= V_64 ;
F_3 ( V_63 , V_58 ) ;
F_3 ( V_14 , V_65 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= V_66 ;
F_3 ( V_63 , V_58 ) ;
V_58 = F_8 ( V_67 ) ;
V_58 |= ( 0x3 << 2 ) | 0xc0 ;
F_3 ( V_68 , V_58 ) ;
F_3 ( V_14 , V_62 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ V_64 ;
V_58 |= V_69 ;
F_3 ( V_63 , V_58 ) ;
F_14 ( 500 ) ;
F_11 ( V_93 , V_43 ) ;
F_11 ( V_94 , V_42 ) ;
F_11 ( V_95 , V_41 ) ;
F_14 ( 50 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , long clock )
{
switch( V_7 -> type ) {
case V_96 :
case V_97 :
return F_9 ( V_7 , clock ) ;
break;
case V_98 :
case V_59 :
return F_13 ( V_7 , clock ) ;
break;
case V_99 :
return F_15 ( V_7 , clock ) ;
break;
case V_100 :
case V_85 :
return F_16 ( V_7 , clock ) ;
break;
case V_101 :
return F_17 ( V_7 , clock ) ;
break;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_1 V_58 ;
int V_102 ;
F_3 ( V_14 , V_103 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= 0x10 ;
F_11 ( V_103 , V_58 ) ;
F_3 ( V_14 , V_104 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= 0x10 ;
F_11 ( V_104 , V_58 ) ;
F_3 ( V_14 , V_105 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= 0x80 ;
F_11 ( V_105 , V_58 ) ;
V_102 = 300 ;
while ( ! ( V_58 & 0x1 ) && V_102 ) {
F_3 ( V_14 , V_105 ) ;
V_58 = F_8 ( V_63 ) ;
F_14 ( 1000 ) ;
V_102 -- ;
}
if ( V_102 ) {
V_102 = 300 ;
while ( ( V_58 & 0x2 ) && V_102 ) {
F_3 ( V_14 , V_105 ) ;
V_58 = F_8 ( V_63 ) ;
F_14 ( 1000 ) ;
V_102 -- ;
}
}
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_58 ;
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
F_3 ( V_106 , 1 ) ;
V_58 = F_8 ( V_107 ) ;
F_3 ( V_107 , V_58 | 0x88 ) ;
F_3 ( V_14 , V_108 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 |= 0x8 ;
F_3 ( V_63 , V_58 ) ;
F_14 ( 10 ) ;
V_58 &= ~ 0x08 ;
F_3 ( V_14 , V_108 ) ;
F_3 ( V_63 , V_58 ) ;
F_3 ( V_14 , V_105 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ 0x80 ;
F_3 ( V_63 , V_58 ) ;
F_3 ( V_14 , V_104 ) ;
V_58 = F_8 ( V_63 ) ;
V_58 &= ~ 0x10 ;
F_11 ( V_104 , V_58 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned V_109 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_2 V_110 ;
int V_111 ;
T_1 V_112 ;
while ( F_8 ( 0x1fda ) & 0x08 ) ;
while ( ! ( F_8 ( 0x1fda ) & 0x08 ) ) ;
V_111 = F_8 ( V_80 ) + 2 ;
while ( F_8 ( V_80 ) < V_111 ) ;
F_3 ( V_106 , 0 ) ;
V_112 = F_8 ( V_107 ) ;
V_112 &= 0xB0 ;
V_110 = V_109 / 8 ;
F_22 ( V_110 > 0x1fffff ) ;
V_112 |= ( ! ! ( V_110 & ( 1 << 20 ) ) ) << 6 ;
F_23 ( 0x0d , ( T_1 ) ( V_110 & 0xff ) ) ;
F_23 ( 0x0c , ( T_1 ) ( V_110 >> 8 ) & 0xff ) ;
F_24 ( 0x0 , ( ( T_1 ) ( V_110 >> 16 ) & 0xf ) | V_112 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
int V_113 , int V_114 , int V_115 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
int V_122 ;
T_3 V_123 ;
if ( ! V_115 && V_10 ) {
V_119 = F_26 ( V_10 ) ;
V_117 = V_119 -> V_117 ;
V_121 = F_27 ( V_117 ) ;
V_122 = F_28 ( V_121 , false ) ;
if ( V_122 )
return V_122 ;
F_29 ( V_121 ) ;
F_30 ( V_121 ) ;
}
V_119 = F_26 ( V_2 -> V_11 -> V_10 ) ;
V_117 = V_119 -> V_117 ;
V_121 = F_27 ( V_117 ) ;
V_122 = F_28 ( V_121 , false ) ;
if ( V_122 )
return V_122 ;
V_122 = F_31 ( V_121 , V_124 , & V_123 ) ;
if ( V_122 ) {
F_30 ( V_121 ) ;
return V_122 ;
}
if ( & V_7 -> V_125 -> V_126 == V_119 ) {
V_122 = F_32 ( & V_121 -> V_121 , 0 , V_121 -> V_121 . V_127 , & V_121 -> V_128 ) ;
if ( V_122 )
F_33 ( L_2 ) ;
}
F_30 ( V_121 ) ;
F_21 ( V_2 , ( T_2 ) V_123 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_113 , int V_114 ,
struct V_9 * V_129 )
{
return F_25 ( V_2 , V_129 , V_113 , V_114 , 0 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_130 * V_131 ,
struct V_130 * V_132 ,
int V_113 , int V_114 , struct V_9 * V_129 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_9 * V_10 = V_2 -> V_11 -> V_10 ;
int V_133 , V_134 , V_135 , V_136 ;
int V_137 , V_138 , V_139 , V_140 ;
int V_141 ;
int V_142 = 0 , V_143 = 0 ;
int V_12 ;
unsigned char V_144 = 0 ;
unsigned char V_145 [ 6 ] ;
T_1 V_146 ;
static unsigned char V_147 [] = {
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
V_146 = V_7 -> V_148 [ V_10 -> V_16 -> V_17 [ 0 ] - 1 ] ;
switch ( V_7 -> type ) {
case V_96 :
case V_97 :
V_147 [ V_70 ] = 0x03 ;
V_147 [ V_62 ] = V_75 ;
V_147 [ V_149 ] = V_150 |
V_151 |
V_152 ;
if ( V_7 -> V_153 )
V_142 = 0x40049120 ;
else
V_142 = 0x4004d120 ;
V_143 = 0x00008000 ;
break;
case V_98 :
case V_59 :
V_147 [ V_70 ] = 0x07 ;
V_142 = 0x41049120 ;
V_143 = 0x0000b000 ;
break;
case V_99 :
V_147 [ V_62 ] = V_75 ;
V_147 [ V_149 ] = V_151 |
V_152 ;
V_142 = 0x00000120 ;
V_143 = 0x0000b000 ;
break;
case V_100 :
case V_85 :
V_147 [ V_149 ] = V_151 |
V_152 ;
V_142 = 0x00000120 ;
V_143 = 0x0000b000 ;
break;
case V_101 :
break;
}
switch ( V_10 -> V_16 -> V_17 [ 0 ] * 8 ) {
case 8 :
V_147 [ V_154 ] = V_155 ;
break;
case 16 :
if ( V_10 -> V_16 -> V_19 == 15 )
V_147 [ V_154 ] = V_156 ;
else
V_147 [ V_154 ] = V_157 ;
break;
case 24 :
V_147 [ V_154 ] = V_158 ;
break;
case 32 :
V_147 [ V_154 ] = V_159 ;
break;
}
if ( V_131 -> V_160 & V_161 )
V_144 |= 0x40 ;
if ( V_131 -> V_160 & V_162 )
V_144 |= 0x80 ;
for ( V_12 = 0 ; V_12 < sizeof( V_147 ) ; V_12 ++ ) {
if ( ( V_12 <= 0x17 ) ||
( V_12 == 0x1b ) ||
( V_12 == 0x1c ) ||
( ( V_12 >= 0x1f ) && ( V_12 <= 0x29 ) ) ||
( ( V_12 >= 0x30 ) && ( V_12 <= 0x37 ) ) )
continue;
if ( F_36 ( V_7 ) &&
( ( V_12 == 0x2c ) || ( V_12 == 0x2d ) || ( V_12 == 0x2e ) ) )
continue;
if ( ( V_7 -> type == V_99 ||
V_7 -> type == V_98 ||
V_7 -> type == V_100 ||
V_7 -> type == V_59 ||
V_7 -> type == V_85 ) &&
( V_12 >= 0x44 ) && ( V_12 <= 0x4e ) )
continue;
F_11 ( V_12 , V_147 [ V_12 ] ) ;
}
if ( V_7 -> type == V_101 )
F_11 ( 0x90 , 0 ) ;
if ( V_142 )
F_37 ( V_5 -> V_163 , V_164 , V_142 ) ;
if ( V_143 )
F_37 ( V_5 -> V_163 , V_165 , V_143 ) ;
F_38 ( 2 , 0xf ) ;
F_38 ( 3 , 0 ) ;
F_38 ( 4 , 0xe ) ;
V_141 = V_10 -> V_166 [ 0 ] / V_10 -> V_16 -> V_17 [ 0 ] ;
if ( V_10 -> V_16 -> V_17 [ 0 ] * 8 == 24 )
V_141 = ( V_141 * 3 ) >> ( 4 - V_146 ) ;
else
V_141 = V_141 >> ( 4 - V_146 ) ;
V_133 = V_131 -> V_133 / 8 - 1 ;
V_134 = V_131 -> V_167 / 8 - 1 ;
V_135 = V_131 -> V_168 / 8 - 1 ;
V_136 = V_131 -> V_136 / 8 - 1 ;
if ( ( V_136 & 0x07 ) == 0x06 || ( V_136 & 0x07 ) == 0x04 )
V_136 ++ ;
V_137 = V_131 -> V_137 - 1 ;
V_138 = V_131 -> V_169 - 1 ;
V_139 = V_131 -> V_170 - 1 ;
V_140 = V_131 -> V_140 - 2 ;
F_39 ( 0 , 0 ) ;
F_39 ( 1 , 0 ) ;
F_39 ( 2 , 0 ) ;
F_39 ( 3 , 0 ) ;
F_39 ( 4 , 0 ) ;
F_39 ( 5 , 0x40 ) ;
F_39 ( 6 , 0x5 ) ;
F_39 ( 7 , 0xf ) ;
F_39 ( 8 , 0xf ) ;
F_23 ( 0 , V_136 - 4 ) ;
F_23 ( 1 , V_133 ) ;
F_23 ( 2 , V_133 ) ;
F_23 ( 3 , ( V_136 & 0x1F ) | 0x80 ) ;
F_23 ( 4 , V_134 ) ;
F_23 ( 5 , ( ( V_136 & 0x20 ) << 2 ) | ( V_135 & 0x1F ) ) ;
F_23 ( 6 , V_140 & 0xFF ) ;
F_23 ( 7 , ( ( V_140 & 0x100 ) >> 8 ) |
( ( V_137 & 0x100 ) >> 7 ) |
( ( V_138 & 0x100 ) >> 6 ) |
( ( V_137 & 0x100 ) >> 5 ) |
( ( V_137 & 0x100 ) >> 4 ) |
( ( V_140 & 0x200 ) >> 4 ) |
( ( V_137 & 0x200 ) >> 3 ) |
( ( V_138 & 0x200 ) >> 2 ) ) ;
F_23 ( 9 , ( ( V_137 & 0x200 ) >> 4 ) |
( ( V_137 & 0x200 ) >> 3 ) ) ;
F_23 ( 10 , 0 ) ;
F_23 ( 11 , 0 ) ;
F_23 ( 12 , 0 ) ;
F_23 ( 13 , 0 ) ;
F_23 ( 14 , 0 ) ;
F_23 ( 15 , 0 ) ;
F_23 ( 16 , V_138 & 0xFF ) ;
F_23 ( 17 , ( V_139 & 0x0F ) | 0x20 ) ;
F_23 ( 18 , V_137 & 0xFF ) ;
F_23 ( 19 , V_141 & 0xFF ) ;
F_23 ( 20 , 0 ) ;
F_23 ( 21 , V_137 & 0xFF ) ;
F_23 ( 22 , ( V_140 + 1 ) & 0xFF ) ;
F_23 ( 23 , 0xc3 ) ;
F_23 ( 24 , V_137 & 0xFF ) ;
V_145 [ 0 ] = 0 ;
V_145 [ 5 ] = 0 ;
V_145 [ 0 ] |= ( V_141 & 0x300 ) >> 4 ;
V_145 [ 1 ] = ( ( ( V_136 - 4 ) & 0x100 ) >> 8 ) |
( ( V_133 & 0x100 ) >> 7 ) |
( ( V_134 & 0x100 ) >> 6 ) |
( V_136 & 0x40 ) ;
V_145 [ 2 ] = ( ( V_140 & 0xc00 ) >> 10 ) |
( ( V_137 & 0x400 ) >> 8 ) |
( ( V_137 & 0xc00 ) >> 7 ) |
( ( V_138 & 0xc00 ) >> 5 ) |
( ( V_137 & 0x400 ) >> 3 ) ;
if ( V_10 -> V_16 -> V_17 [ 0 ] * 8 == 24 )
V_145 [ 3 ] = ( ( ( 1 << V_146 ) * 3 ) - 1 ) | 0x80 ;
else
V_145 [ 3 ] = ( ( 1 << V_146 ) - 1 ) | 0x80 ;
V_145 [ 4 ] = 0 ;
if ( V_7 -> type == V_98 || V_7 -> type == V_59 )
V_145 [ 1 ] |= 0x88 ;
V_144 = 0x2d ;
F_3 ( V_171 , V_144 ) ;
F_18 ( V_7 , V_131 -> clock ) ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
F_24 ( V_12 , V_145 [ V_12 ] ) ;
}
if ( V_7 -> type == V_101 )
F_24 ( 0x24 , 0x5 ) ;
if ( V_7 -> type == V_59 )
F_24 ( 0x34 , 0x5 ) ;
if ( V_7 -> type == V_99 ) {
F_24 ( 6 , 0 ) ;
}
F_24 ( 0 , V_145 [ 0 ] ) ;
V_144 = 0x2d ;
F_3 ( V_171 , V_144 ) ;
if ( V_132 )
memcpy ( & V_7 -> V_131 , V_131 , sizeof( struct V_130 ) ) ;
F_25 ( V_2 , V_129 , V_113 , V_114 , 0 ) ;
if ( V_7 -> type == V_101 ) {
T_2 V_172 = F_5 ( V_173 ) ;
T_1 V_174 ;
F_3 ( V_78 , 0x01 ) ;
V_174 = F_8 ( V_79 ) | 0x20 ;
F_3 ( V_79 , V_174 ) ;
F_40 ( V_173 , V_172 | 0x00200000 ) ;
F_14 ( 1000 ) ;
F_40 ( V_173 , V_172 & ~ 0x00200000 ) ;
F_3 ( V_79 , V_174 & ~ 0x20 ) ;
}
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_48 >= 0x02 ) {
T_1 V_175 ;
T_2 V_176 ;
T_2 V_177 ;
if ( V_10 -> V_16 -> V_17 [ 0 ] * 8 > 16 )
V_176 = 32 ;
else if ( V_10 -> V_16 -> V_17 [ 0 ] * 8 > 8 )
V_176 = 16 ;
else
V_176 = 8 ;
V_177 = ( V_131 -> clock * V_176 ) / 1000 ;
if ( V_177 > 3100 )
V_175 = 0 ;
else if ( V_177 > 2600 )
V_175 = 1 ;
else if ( V_177 > 1900 )
V_175 = 2 ;
else if ( V_177 > 1160 )
V_175 = 3 ;
else if ( V_177 > 440 )
V_175 = 4 ;
else
V_175 = 5 ;
F_3 ( V_106 , 0x06 ) ;
F_3 ( V_107 , V_175 ) ;
} else {
F_3 ( V_106 , 0x06 ) ;
if ( V_7 -> V_48 >= 0x01 )
F_3 ( V_107 , 0x03 ) ;
else
F_3 ( V_107 , 0x04 ) ;
}
}
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , int V_131 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_174 = 0 , V_178 = 0 ;
switch ( V_131 ) {
case V_179 :
V_174 = 0 ;
V_178 = 0 ;
F_1 ( V_2 ) ;
break;
case V_180 :
V_174 = 0x20 ;
V_178 = 0x10 ;
break;
case V_181 :
V_174 = 0x20 ;
V_178 = 0x20 ;
break;
case V_182 :
V_174 = 0x20 ;
V_178 = 0x30 ;
break;
}
#if 0
if (mode == DRM_MODE_DPMS_OFF) {
mga_suspend(crtc);
}
#endif
F_3 ( V_78 , 0x01 ) ;
V_174 |= F_8 ( V_79 ) & ~ 0x20 ;
F_4 ( V_7 ) ;
F_7 ( V_7 ) ;
F_3 ( V_79 , V_174 ) ;
F_12 ( 20 ) ;
F_3 ( V_106 , 0x01 ) ;
V_178 |= F_8 ( V_107 ) & ~ 0x30 ;
F_3 ( V_107 , V_178 ) ;
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
T_1 V_58 ;
F_3 ( V_60 , 0x11 ) ;
V_58 = F_8 ( V_61 ) ;
F_23 ( 0x11 , V_58 | 0x80 ) ;
if ( V_7 -> type == V_96 || V_7 -> type == V_97 ) {
F_38 ( 0 , 1 ) ;
F_12 ( 50 ) ;
F_38 ( 1 , 0x20 ) ;
F_12 ( 20 ) ;
} else {
F_3 ( V_78 , 0x1 ) ;
V_58 = F_8 ( V_79 ) ;
F_38 ( 0 , 1 ) ;
F_38 ( 1 , V_58 | 0x20 ) ;
}
if ( V_7 -> type == V_98 || V_7 -> type == V_59 )
F_19 ( V_2 ) ;
F_23 ( 17 , 0 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_183 * V_184 = V_2 -> V_185 ;
T_1 V_58 ;
if ( V_7 -> type == V_98 || V_7 -> type == V_59 )
F_20 ( V_2 ) ;
if ( V_7 -> type == V_96 || V_7 -> type == V_97 ) {
F_12 ( 50 ) ;
F_38 ( 1 , 0x0 ) ;
F_12 ( 20 ) ;
F_38 ( 0 , 0x3 ) ;
} else {
F_3 ( V_78 , 0x1 ) ;
V_58 = F_8 ( V_79 ) ;
V_58 &= ~ 0x20 ;
F_38 ( 0x1 , V_58 ) ;
F_38 ( 0 , 3 ) ;
}
V_184 -> V_186 ( V_2 , V_179 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_4 * V_187 , T_4 * V_188 ,
T_4 * V_189 , T_5 V_190 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_190 ; V_12 ++ ) {
V_3 -> V_23 [ V_12 ] = V_187 [ V_12 ] >> 8 ;
V_3 -> V_26 [ V_12 ] = V_188 [ V_12 ] >> 8 ;
V_3 -> V_24 [ V_12 ] = V_189 [ V_12 ] >> 8 ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_3 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_122 ;
F_49 ( L_3 ) ;
F_41 ( V_2 , V_182 ) ;
if ( V_2 -> V_11 -> V_10 ) {
struct V_118 * V_119 = F_26 ( V_2 -> V_11 -> V_10 ) ;
struct V_116 * V_117 = V_119 -> V_117 ;
struct V_120 * V_121 = F_27 ( V_117 ) ;
V_122 = F_28 ( V_121 , false ) ;
if ( V_122 )
return;
F_29 ( V_121 ) ;
F_30 ( V_121 ) ;
}
V_2 -> V_11 -> V_10 = NULL ;
}
static void F_50 ( struct V_6 * V_7 )
{
struct V_3 * V_3 ;
int V_12 ;
V_3 = F_51 ( sizeof( struct V_3 ) +
( V_191 * sizeof( struct V_192 * ) ) ,
V_193 ) ;
if ( V_3 == NULL )
return;
F_52 ( V_7 -> V_5 , & V_3 -> V_194 , & V_195 ) ;
F_53 ( & V_3 -> V_194 , V_22 ) ;
V_7 -> V_196 . V_2 = V_3 ;
for ( V_12 = 0 ; V_12 < V_22 ; V_12 ++ ) {
V_3 -> V_23 [ V_12 ] = V_12 ;
V_3 -> V_26 [ V_12 ] = V_12 ;
V_3 -> V_24 [ V_12 ] = V_12 ;
}
F_54 ( & V_3 -> V_194 , & V_197 ) ;
}
void F_55 ( struct V_1 * V_2 , T_4 V_187 , T_4 V_188 ,
T_4 V_189 , int V_198 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_23 [ V_198 ] = V_187 >> 8 ;
V_3 -> V_26 [ V_198 ] = V_188 >> 8 ;
V_3 -> V_24 [ V_198 ] = V_189 >> 8 ;
}
void F_56 ( struct V_1 * V_2 , T_4 * V_187 , T_4 * V_188 ,
T_4 * V_189 , int V_198 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_187 = ( T_4 ) V_3 -> V_23 [ V_198 ] << 8 ;
* V_188 = ( T_4 ) V_3 -> V_26 [ V_198 ] << 8 ;
* V_189 = ( T_4 ) V_3 -> V_24 [ V_198 ] << 8 ;
}
static void F_57 ( struct V_199 * V_200 ,
struct V_130 * V_131 ,
struct V_130 * V_132 )
{
}
static void F_58 ( struct V_199 * V_200 , int V_201 )
{
return;
}
static void F_59 ( struct V_199 * V_200 )
{
}
static void F_60 ( struct V_199 * V_200 )
{
}
static void F_61 ( struct V_199 * V_200 )
{
struct V_202 * V_202 = F_62 ( V_200 ) ;
F_63 ( V_200 ) ;
F_47 ( V_202 ) ;
}
static struct V_199 * F_64 ( struct V_4 * V_5 )
{
struct V_199 * V_200 ;
struct V_202 * V_202 ;
V_202 = F_51 ( sizeof( struct V_202 ) , V_193 ) ;
if ( ! V_202 )
return NULL ;
V_200 = & V_202 -> V_194 ;
V_200 -> V_203 = 0x1 ;
F_65 ( V_5 , V_200 , & V_204 ,
V_205 , NULL ) ;
F_66 ( V_200 , & V_206 ) ;
return V_200 ;
}
static int F_67 ( struct V_192 * V_207 )
{
struct V_208 * V_208 = F_68 ( V_207 ) ;
struct V_209 * V_209 ;
int V_122 = 0 ;
V_209 = F_69 ( V_207 , & V_208 -> V_210 -> V_211 ) ;
if ( V_209 ) {
F_70 ( V_207 , V_209 ) ;
V_122 = F_71 ( V_207 , V_209 ) ;
F_47 ( V_209 ) ;
}
return V_122 ;
}
static T_5 F_72 ( struct V_130 * V_131 ,
int V_212 )
{
T_5 V_213 , V_214 ;
T_6 V_215 , V_216 , V_217 ;
T_6 V_218 = ( V_212 + 7 ) / 8 ;
V_214 = 1024 ;
if ( ! V_131 -> V_136 || ! V_131 -> V_140 || ! V_131 -> clock )
return 0 ;
V_215 = V_131 -> V_133 * V_131 -> V_137 ;
V_213 = V_131 -> V_136 * V_131 -> V_140 ;
V_216 = V_215 * V_131 -> clock * 1000 ;
F_73 ( V_216 , V_213 ) ;
V_217 = V_216 * V_218 * 100 ;
F_73 ( V_217 , V_214 ) ;
return ( T_5 ) ( V_217 ) ;
}
static int F_74 ( struct V_192 * V_207 ,
struct V_130 * V_131 )
{
struct V_4 * V_5 = V_207 -> V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_5 -> V_8 ;
int V_176 = 32 ;
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_48 == 0x01 ) {
if ( V_131 -> V_133 > 1600 )
return V_219 ;
if ( V_131 -> V_137 > 1200 )
return V_220 ;
if ( F_72 ( V_131 , V_176 )
> ( 24400 * 1024 ) )
return V_221 ;
} else if ( V_7 -> V_48 == 0x02 ) {
if ( V_131 -> V_133 > 1920 )
return V_219 ;
if ( V_131 -> V_137 > 1200 )
return V_220 ;
if ( F_72 ( V_131 , V_176 )
> ( 30100 * 1024 ) )
return V_221 ;
}
} else if ( V_7 -> type == V_98 ) {
if ( V_131 -> V_133 > 1280 )
return V_219 ;
if ( V_131 -> V_137 > 1024 )
return V_220 ;
if ( F_72 ( V_131 ,
V_176 > ( 31877 * 1024 ) ) )
return V_221 ;
} else if ( V_7 -> type == V_99 &&
( F_72 ( V_131 , V_176 )
> ( 32700 * 1024 ) ) ) {
return V_221 ;
} else if ( V_7 -> type == V_100 &&
( F_72 ( V_131 , V_176 )
> ( 37500 * 1024 ) ) ) {
return V_221 ;
} else if ( V_7 -> type == V_101 &&
( F_72 ( V_131 ,
V_176 ) > ( 55000 * 1024 ) ) ) {
return V_221 ;
}
if ( ( V_131 -> V_133 % 8 ) != 0 || ( V_131 -> V_167 % 8 ) != 0 ||
( V_131 -> V_168 % 8 ) != 0 || ( V_131 -> V_136 % 8 ) != 0 ) {
return V_222 ;
}
if ( V_131 -> V_223 > 2048 || V_131 -> V_224 > 4096 ||
V_131 -> V_225 > 4096 || V_131 -> V_226 > 4096 ||
V_131 -> V_227 > 2048 || V_131 -> V_228 > 4096 ||
V_131 -> V_229 > 4096 || V_131 -> V_230 > 4096 ) {
return V_231 ;
}
if ( V_207 -> V_232 . V_233 ) {
if ( V_207 -> V_232 . V_234 )
V_176 = V_207 -> V_232 . V_176 ;
}
if ( ( V_131 -> V_133 * V_131 -> V_137 * ( V_176 / 8 ) ) > V_7 -> V_235 . V_236 ) {
if ( V_207 -> V_232 . V_233 )
V_207 -> V_232 . V_233 = false ;
return V_231 ;
}
return V_237 ;
}
static struct V_199 * F_75 ( struct V_192
* V_207 )
{
int V_238 = V_207 -> V_239 [ 0 ] ;
if ( V_238 )
return F_76 ( V_207 -> V_5 , V_238 ) ;
return NULL ;
}
static void F_77 ( struct V_192 * V_207 )
{
struct V_208 * V_208 = F_68 ( V_207 ) ;
F_78 ( V_208 -> V_210 ) ;
F_79 ( V_207 ) ;
F_47 ( V_207 ) ;
}
static struct V_192 * F_80 ( struct V_4 * V_5 )
{
struct V_192 * V_207 ;
struct V_208 * V_208 ;
V_208 = F_51 ( sizeof( struct V_208 ) , V_193 ) ;
if ( ! V_208 )
return NULL ;
V_207 = & V_208 -> V_194 ;
F_81 ( V_5 , V_207 ,
& V_240 , V_241 ) ;
F_82 ( V_207 , & V_242 ) ;
F_83 ( V_207 ) ;
V_208 -> V_210 = F_84 ( V_5 ) ;
if ( ! V_208 -> V_210 )
F_33 ( L_4 ) ;
return V_207 ;
}
int F_85 ( struct V_6 * V_7 )
{
struct V_199 * V_200 ;
struct V_192 * V_207 ;
int V_122 ;
V_7 -> V_196 . V_243 = true ;
V_7 -> V_5 -> V_244 . V_245 = V_246 ;
V_7 -> V_5 -> V_244 . V_247 = V_248 ;
V_7 -> V_5 -> V_244 . V_249 = V_7 -> V_235 . V_250 ;
F_50 ( V_7 ) ;
V_200 = F_64 ( V_7 -> V_5 ) ;
if ( ! V_200 ) {
F_33 ( L_5 ) ;
return - 1 ;
}
V_207 = F_80 ( V_7 -> V_5 ) ;
if ( ! V_207 ) {
F_33 ( L_6 ) ;
return - 1 ;
}
F_86 ( V_207 , V_200 ) ;
V_122 = F_87 ( V_7 ) ;
if ( V_122 ) {
F_33 ( L_7 ) ;
return V_122 ;
}
return 0 ;
}
void F_88 ( struct V_6 * V_7 )
{
}
