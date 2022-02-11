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
F_10 ( L_1 ) ;
return 1 ;
}
F_11 ( V_49 , V_42 ) ;
F_11 ( V_50 , V_43 ) ;
F_11 ( V_51 , V_41 ) ;
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
unsigned int V_38 , V_39 , V_40 , V_52 ;
unsigned int V_41 , V_42 , V_43 ;
unsigned int V_44 ;
int V_12 , V_53 , V_54 , V_55 ;
bool V_56 = false ;
T_1 V_57 ;
V_42 = V_43 = V_41 = 0 ;
V_35 = 0xffffffff ;
if ( V_7 -> type == V_58 ) {
V_32 = 800000 ;
V_33 = 400000 ;
V_34 = 25000 ;
for ( V_38 = 1 ; V_38 < 8 ; V_38 ++ ) {
for ( V_52 = 1 ; V_52 < 8 ; V_52 ++ ) {
if ( V_38 < V_52 )
continue;
if ( ( clock * V_38 * V_52 ) > V_32 )
continue;
if ( ( clock * V_38 * V_52 ) < V_33 )
continue;
for ( V_39 = 1 ; V_39 < 26 ; V_39 ++ ) {
for ( V_40 = 32 ; V_40 < 2048 ; V_40 ++ ) {
V_44 = ( V_34 * V_40 ) /
( V_39 * V_38 * V_52 ) ;
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
( V_52 << 3 ) |
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
for ( V_12 = 0 ; V_12 <= 32 && V_56 == false ; V_12 ++ ) {
if ( V_12 > 0 ) {
F_3 ( V_59 , 0x1e ) ;
V_57 = F_8 ( V_60 ) ;
if ( V_57 < 0xff )
F_3 ( V_60 , V_57 + 1 ) ;
}
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= V_63 ;
F_3 ( V_62 , V_57 ) ;
F_3 ( V_14 , V_64 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= V_65 ;
F_3 ( V_62 , V_57 ) ;
V_57 = F_8 ( V_66 ) ;
V_57 |= 0x3 << 2 ;
F_3 ( V_67 , V_57 ) ;
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= V_68 | 0x80 ;
F_3 ( V_62 , V_57 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_69 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ 0x04 ;
F_3 ( V_62 , V_57 ) ;
F_14 ( 50 ) ;
F_11 ( V_70 , V_43 ) ;
F_11 ( V_71 , V_42 ) ;
F_11 ( V_72 , V_41 ) ;
F_14 ( 50 ) ;
F_3 ( V_14 , V_69 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= 0x04 ;
F_11 ( V_69 , V_57 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ V_73 ;
V_57 |= V_74 ;
F_3 ( V_62 , V_57 ) ;
F_3 ( V_14 , V_64 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ V_75 ;
V_57 |= V_76 ;
F_3 ( V_62 , V_57 ) ;
F_3 ( V_77 , 1 ) ;
V_57 = F_8 ( V_78 ) ;
V_57 &= ~ 0x8 ;
F_3 ( V_78 , V_57 ) ;
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ V_63 ;
F_3 ( V_62 , V_57 ) ;
V_55 = F_8 ( V_79 ) ;
for ( V_53 = 0 ; V_53 < 30 && V_56 == false ; V_53 ++ ) {
V_54 = F_8 ( V_79 ) ;
if ( V_54 < V_55 )
V_55 = 0 ;
if ( ( V_54 - V_55 ) > 2 )
V_56 = true ;
else
F_14 ( 5 ) ;
}
}
F_3 ( V_14 , V_64 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ V_65 ;
F_11 ( V_64 , V_57 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , long clock )
{
unsigned int V_32 , V_33 , V_34 ;
unsigned int V_35 , V_36 ;
unsigned int V_38 , V_39 , V_40 ;
unsigned int V_41 , V_42 , V_43 ;
unsigned int V_44 ;
T_1 V_57 ;
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
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= V_63 ;
F_3 ( V_62 , V_57 ) ;
V_57 = F_8 ( V_66 ) ;
V_57 |= 0x3 << 2 ;
F_3 ( V_67 , V_57 ) ;
F_3 ( V_14 , V_80 ) ;
V_57 = F_8 ( V_62 ) ;
F_3 ( V_62 , V_57 & ~ 0x40 ) ;
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= V_68 ;
F_3 ( V_62 , V_57 ) ;
F_11 ( V_81 , V_42 ) ;
F_11 ( V_82 , V_43 ) ;
F_11 ( V_83 , V_41 ) ;
F_14 ( 50 ) ;
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ V_68 ;
F_3 ( V_62 , V_57 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ V_73 ;
V_57 |= V_74 ;
F_3 ( V_62 , V_57 ) ;
F_3 ( V_14 , V_80 ) ;
V_57 = F_8 ( V_62 ) ;
F_3 ( V_62 , V_57 | 0x40 ) ;
V_57 = F_8 ( V_66 ) ;
V_57 |= ( 0x3 << 2 ) ;
F_3 ( V_67 , V_57 ) ;
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ V_63 ;
F_3 ( V_62 , V_57 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , long clock )
{
unsigned int V_32 , V_33 , V_34 ;
unsigned int V_35 , V_36 ;
unsigned int V_38 , V_39 , V_40 ;
unsigned int V_41 , V_42 , V_43 ;
unsigned int V_44 ;
int V_12 , V_53 , V_54 , V_55 ;
T_1 V_57 ;
bool V_56 = false ;
V_42 = V_43 = V_41 = 0 ;
if ( V_7 -> type == V_84 ) {
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
for ( V_12 = 0 ; V_12 <= 32 && V_56 == false ; V_12 ++ ) {
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= V_63 ;
F_3 ( V_62 , V_57 ) ;
V_57 = F_8 ( V_66 ) ;
V_57 |= 0x3 << 2 ;
F_3 ( V_67 , V_57 ) ;
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= V_68 ;
F_3 ( V_62 , V_57 ) ;
F_14 ( 500 ) ;
F_11 ( V_85 , V_42 ) ;
F_11 ( V_86 , V_43 ) ;
F_11 ( V_87 , V_41 ) ;
F_14 ( 500 ) ;
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ V_73 ;
V_57 |= V_74 ;
F_3 ( V_62 , V_57 ) ;
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ V_63 ;
V_57 &= ~ V_68 ;
F_3 ( V_62 , V_57 ) ;
V_55 = F_8 ( V_79 ) ;
for ( V_53 = 0 ; V_53 < 30 && V_56 == false ; V_53 ++ ) {
V_54 = F_8 ( V_79 ) ;
if ( V_54 < V_55 )
V_55 = 0 ;
if ( ( V_54 - V_55 ) > 2 )
V_56 = true ;
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
int V_88 , V_40 , V_39 , V_89 ;
unsigned int V_41 , V_42 , V_43 ;
unsigned int V_44 , V_90 ;
int V_57 ;
const unsigned int V_91 [] = { 1 , 2 , 4 , 8 } ;
V_42 = V_43 = V_41 = 0 ;
V_32 = 1488000 ;
V_33 = 1056000 ;
V_34 = 48000 ;
V_35 = 0xffffffff ;
for ( V_88 = 0 ; V_88 < 4 ; V_88 ++ ) {
if ( V_35 == 0 )
break;
for ( V_40 = 5 ; V_40 < 129 ; V_40 ++ ) {
if ( V_35 == 0 )
break;
for ( V_39 = 3 ; V_39 >= 0 ; V_39 -- ) {
if ( V_35 == 0 )
break;
for ( V_89 = 5 ; V_89 < 33 ; V_89 ++ ) {
V_90 = V_34 * ( V_40 + 1 ) /
( V_88 + 1 ) ;
if ( V_90 < V_33 )
continue;
if ( V_90 > V_32 )
continue;
V_44 = V_90 / ( V_91 [ V_39 ] * ( V_89 + 1 ) ) ;
if ( V_44 > clock )
V_36 = V_44 - clock ;
else
V_36 = clock - V_44 ;
if ( V_36 < V_35 ) {
V_35 = V_36 ;
V_42 = V_39 | ( V_89 << 3 ) ;
V_43 = V_40 ;
V_41 = V_88 | ( V_88 << 3 ) ;
}
}
}
}
}
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= V_63 ;
F_3 ( V_62 , V_57 ) ;
F_3 ( V_14 , V_64 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= V_65 ;
F_3 ( V_62 , V_57 ) ;
V_57 = F_8 ( V_66 ) ;
V_57 |= ( 0x3 << 2 ) | 0xc0 ;
F_3 ( V_67 , V_57 ) ;
F_3 ( V_14 , V_61 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ V_63 ;
V_57 |= V_68 ;
F_3 ( V_62 , V_57 ) ;
F_14 ( 500 ) ;
F_11 ( V_92 , V_43 ) ;
F_11 ( V_93 , V_42 ) ;
F_11 ( V_94 , V_41 ) ;
F_14 ( 50 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , long clock )
{
switch( V_7 -> type ) {
case V_95 :
case V_96 :
return F_9 ( V_7 , clock ) ;
break;
case V_97 :
case V_58 :
return F_13 ( V_7 , clock ) ;
break;
case V_98 :
return F_15 ( V_7 , clock ) ;
break;
case V_99 :
case V_84 :
return F_16 ( V_7 , clock ) ;
break;
case V_100 :
return F_17 ( V_7 , clock ) ;
break;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_1 V_57 ;
int V_101 ;
F_3 ( V_14 , V_102 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= 0x10 ;
F_11 ( V_102 , V_57 ) ;
F_3 ( V_14 , V_103 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= 0x10 ;
F_11 ( V_103 , V_57 ) ;
F_3 ( V_14 , V_104 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= 0x80 ;
F_11 ( V_104 , V_57 ) ;
V_101 = 300 ;
while ( ! ( V_57 & 0x1 ) && V_101 ) {
F_3 ( V_14 , V_104 ) ;
V_57 = F_8 ( V_62 ) ;
F_14 ( 1000 ) ;
V_101 -- ;
}
if ( V_101 ) {
V_101 = 300 ;
while ( ( V_57 & 0x2 ) && V_101 ) {
F_3 ( V_14 , V_104 ) ;
V_57 = F_8 ( V_62 ) ;
F_14 ( 1000 ) ;
V_101 -- ;
}
}
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_57 ;
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
F_3 ( V_105 , 1 ) ;
V_57 = F_8 ( V_106 ) ;
F_3 ( V_106 , V_57 | 0x88 ) ;
F_3 ( V_14 , V_107 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= 0x8 ;
F_3 ( V_62 , V_57 ) ;
F_14 ( 10 ) ;
V_57 &= ~ 0x08 ;
F_3 ( V_14 , V_107 ) ;
F_3 ( V_62 , V_57 ) ;
F_3 ( V_14 , V_104 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ 0x80 ;
F_3 ( V_62 , V_57 ) ;
F_3 ( V_14 , V_103 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ 0x10 ;
F_11 ( V_103 , V_57 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned V_108 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_2 V_109 ;
int V_110 ;
T_1 V_111 ;
while ( F_8 ( 0x1fda ) & 0x08 ) ;
while ( ! ( F_8 ( 0x1fda ) & 0x08 ) ) ;
V_110 = F_8 ( V_79 ) + 2 ;
while ( F_8 ( V_79 ) < V_110 ) ;
F_3 ( V_105 , 0 ) ;
V_111 = F_8 ( V_106 ) ;
V_111 &= 0xB0 ;
V_109 = V_108 / 8 ;
F_22 ( V_109 > 0x1fffff ) ;
V_111 |= ( ! ! ( V_109 & ( 1 << 20 ) ) ) << 6 ;
F_23 ( 0x0d , ( T_1 ) ( V_109 & 0xff ) ) ;
F_23 ( 0x0c , ( T_1 ) ( V_109 >> 8 ) & 0xff ) ;
F_24 ( 0x0 , ( ( T_1 ) ( V_109 >> 16 ) & 0xf ) | V_111 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
int V_112 , int V_113 , int V_114 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_115 * V_116 ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
int V_121 ;
T_3 V_122 ;
if ( ! V_114 && V_10 ) {
V_118 = F_26 ( V_10 ) ;
V_116 = V_118 -> V_116 ;
V_120 = F_27 ( V_116 ) ;
V_121 = F_28 ( V_120 , false ) ;
if ( V_121 )
return V_121 ;
F_29 ( V_120 ) ;
F_30 ( V_120 ) ;
}
V_118 = F_26 ( V_2 -> V_11 -> V_10 ) ;
V_116 = V_118 -> V_116 ;
V_120 = F_27 ( V_116 ) ;
V_121 = F_28 ( V_120 , false ) ;
if ( V_121 )
return V_121 ;
V_121 = F_31 ( V_120 , V_123 , & V_122 ) ;
if ( V_121 ) {
F_30 ( V_120 ) ;
return V_121 ;
}
if ( & V_7 -> V_124 -> V_125 == V_118 ) {
V_121 = F_32 ( & V_120 -> V_120 , 0 , V_120 -> V_120 . V_126 , & V_120 -> V_127 ) ;
if ( V_121 )
F_33 ( L_2 ) ;
}
F_30 ( V_120 ) ;
F_21 ( V_2 , ( T_2 ) V_122 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_112 , int V_113 ,
struct V_9 * V_128 )
{
return F_25 ( V_2 , V_128 , V_112 , V_113 , 0 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
struct V_129 * V_131 ,
int V_112 , int V_113 , struct V_9 * V_128 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_9 * V_10 = V_2 -> V_11 -> V_10 ;
int V_132 , V_133 , V_134 , V_135 ;
int V_136 , V_137 , V_138 , V_139 ;
int V_140 ;
int V_141 = 0 , V_142 = 0 ;
int V_12 ;
unsigned char V_143 = 0 ;
unsigned char V_144 [ 6 ] ;
T_1 V_145 ;
static unsigned char V_146 [] = {
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
V_145 = V_7 -> V_147 [ V_10 -> V_16 -> V_17 [ 0 ] - 1 ] ;
switch ( V_7 -> type ) {
case V_95 :
case V_96 :
V_146 [ V_69 ] = 0x03 ;
V_146 [ V_61 ] = V_74 ;
V_146 [ V_148 ] = V_149 |
V_150 |
V_151 ;
if ( V_7 -> V_152 )
V_141 = 0x40049120 ;
else
V_141 = 0x4004d120 ;
V_142 = 0x00008000 ;
break;
case V_97 :
case V_58 :
V_146 [ V_69 ] = 0x07 ;
V_141 = 0x41049120 ;
V_142 = 0x0000b000 ;
break;
case V_98 :
V_146 [ V_61 ] = V_74 ;
V_146 [ V_148 ] = V_150 |
V_151 ;
V_141 = 0x00000120 ;
V_142 = 0x0000b000 ;
break;
case V_99 :
case V_84 :
V_146 [ V_148 ] = V_150 |
V_151 ;
V_141 = 0x00000120 ;
V_142 = 0x0000b000 ;
break;
case V_100 :
break;
}
switch ( V_10 -> V_16 -> V_17 [ 0 ] * 8 ) {
case 8 :
V_146 [ V_153 ] = V_154 ;
break;
case 16 :
if ( V_10 -> V_16 -> V_19 == 15 )
V_146 [ V_153 ] = V_155 ;
else
V_146 [ V_153 ] = V_156 ;
break;
case 24 :
V_146 [ V_153 ] = V_157 ;
break;
case 32 :
V_146 [ V_153 ] = V_158 ;
break;
}
if ( V_130 -> V_159 & V_160 )
V_143 |= 0x40 ;
if ( V_130 -> V_159 & V_161 )
V_143 |= 0x80 ;
for ( V_12 = 0 ; V_12 < sizeof( V_146 ) ; V_12 ++ ) {
if ( ( V_12 <= 0x17 ) ||
( V_12 == 0x1b ) ||
( V_12 == 0x1c ) ||
( ( V_12 >= 0x1f ) && ( V_12 <= 0x29 ) ) ||
( ( V_12 >= 0x30 ) && ( V_12 <= 0x37 ) ) )
continue;
if ( F_36 ( V_7 ) &&
( ( V_12 == 0x2c ) || ( V_12 == 0x2d ) || ( V_12 == 0x2e ) ) )
continue;
if ( ( V_7 -> type == V_98 ||
V_7 -> type == V_97 ||
V_7 -> type == V_99 ||
V_7 -> type == V_58 ||
V_7 -> type == V_84 ) &&
( V_12 >= 0x44 ) && ( V_12 <= 0x4e ) )
continue;
F_11 ( V_12 , V_146 [ V_12 ] ) ;
}
if ( V_7 -> type == V_100 )
F_11 ( 0x90 , 0 ) ;
if ( V_141 )
F_37 ( V_5 -> V_162 , V_163 , V_141 ) ;
if ( V_142 )
F_37 ( V_5 -> V_162 , V_164 , V_142 ) ;
F_38 ( 2 , 0xf ) ;
F_38 ( 3 , 0 ) ;
F_38 ( 4 , 0xe ) ;
V_140 = V_10 -> V_165 [ 0 ] / V_10 -> V_16 -> V_17 [ 0 ] ;
if ( V_10 -> V_16 -> V_17 [ 0 ] * 8 == 24 )
V_140 = ( V_140 * 3 ) >> ( 4 - V_145 ) ;
else
V_140 = V_140 >> ( 4 - V_145 ) ;
V_132 = V_130 -> V_132 / 8 - 1 ;
V_133 = V_130 -> V_166 / 8 - 1 ;
V_134 = V_130 -> V_167 / 8 - 1 ;
V_135 = V_130 -> V_135 / 8 - 1 ;
if ( ( V_135 & 0x07 ) == 0x06 || ( V_135 & 0x07 ) == 0x04 )
V_135 ++ ;
V_136 = V_130 -> V_136 - 1 ;
V_137 = V_130 -> V_168 - 1 ;
V_138 = V_130 -> V_169 - 1 ;
V_139 = V_130 -> V_139 - 2 ;
F_39 ( 0 , 0 ) ;
F_39 ( 1 , 0 ) ;
F_39 ( 2 , 0 ) ;
F_39 ( 3 , 0 ) ;
F_39 ( 4 , 0 ) ;
F_39 ( 5 , 0x40 ) ;
F_39 ( 6 , 0x5 ) ;
F_39 ( 7 , 0xf ) ;
F_39 ( 8 , 0xf ) ;
F_23 ( 0 , V_135 - 4 ) ;
F_23 ( 1 , V_132 ) ;
F_23 ( 2 , V_132 ) ;
F_23 ( 3 , ( V_135 & 0x1F ) | 0x80 ) ;
F_23 ( 4 , V_133 ) ;
F_23 ( 5 , ( ( V_135 & 0x20 ) << 2 ) | ( V_134 & 0x1F ) ) ;
F_23 ( 6 , V_139 & 0xFF ) ;
F_23 ( 7 , ( ( V_139 & 0x100 ) >> 8 ) |
( ( V_136 & 0x100 ) >> 7 ) |
( ( V_137 & 0x100 ) >> 6 ) |
( ( V_136 & 0x100 ) >> 5 ) |
( ( V_136 & 0x100 ) >> 4 ) |
( ( V_139 & 0x200 ) >> 4 ) |
( ( V_136 & 0x200 ) >> 3 ) |
( ( V_137 & 0x200 ) >> 2 ) ) ;
F_23 ( 9 , ( ( V_136 & 0x200 ) >> 4 ) |
( ( V_136 & 0x200 ) >> 3 ) ) ;
F_23 ( 10 , 0 ) ;
F_23 ( 11 , 0 ) ;
F_23 ( 12 , 0 ) ;
F_23 ( 13 , 0 ) ;
F_23 ( 14 , 0 ) ;
F_23 ( 15 , 0 ) ;
F_23 ( 16 , V_137 & 0xFF ) ;
F_23 ( 17 , ( V_138 & 0x0F ) | 0x20 ) ;
F_23 ( 18 , V_136 & 0xFF ) ;
F_23 ( 19 , V_140 & 0xFF ) ;
F_23 ( 20 , 0 ) ;
F_23 ( 21 , V_136 & 0xFF ) ;
F_23 ( 22 , ( V_139 + 1 ) & 0xFF ) ;
F_23 ( 23 , 0xc3 ) ;
F_23 ( 24 , V_136 & 0xFF ) ;
V_144 [ 0 ] = 0 ;
V_144 [ 5 ] = 0 ;
V_144 [ 0 ] |= ( V_140 & 0x300 ) >> 4 ;
V_144 [ 1 ] = ( ( ( V_135 - 4 ) & 0x100 ) >> 8 ) |
( ( V_132 & 0x100 ) >> 7 ) |
( ( V_133 & 0x100 ) >> 6 ) |
( V_135 & 0x40 ) ;
V_144 [ 2 ] = ( ( V_139 & 0xc00 ) >> 10 ) |
( ( V_136 & 0x400 ) >> 8 ) |
( ( V_136 & 0xc00 ) >> 7 ) |
( ( V_137 & 0xc00 ) >> 5 ) |
( ( V_136 & 0x400 ) >> 3 ) ;
if ( V_10 -> V_16 -> V_17 [ 0 ] * 8 == 24 )
V_144 [ 3 ] = ( ( ( 1 << V_145 ) * 3 ) - 1 ) | 0x80 ;
else
V_144 [ 3 ] = ( ( 1 << V_145 ) - 1 ) | 0x80 ;
V_144 [ 4 ] = 0 ;
if ( V_7 -> type == V_97 || V_7 -> type == V_58 )
V_144 [ 1 ] |= 0x88 ;
V_143 = 0x2d ;
F_3 ( V_170 , V_143 ) ;
F_18 ( V_7 , V_130 -> clock ) ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
F_24 ( V_12 , V_144 [ V_12 ] ) ;
}
if ( V_7 -> type == V_100 )
F_24 ( 0x24 , 0x5 ) ;
if ( V_7 -> type == V_58 )
F_24 ( 0x34 , 0x5 ) ;
if ( V_7 -> type == V_98 ) {
F_24 ( 6 , 0 ) ;
}
F_24 ( 0 , V_144 [ 0 ] ) ;
V_143 = 0x2d ;
F_3 ( V_170 , V_143 ) ;
if ( V_131 )
memcpy ( & V_7 -> V_130 , V_130 , sizeof( struct V_129 ) ) ;
F_25 ( V_2 , V_128 , V_112 , V_113 , 0 ) ;
if ( V_7 -> type == V_100 ) {
T_2 V_171 = F_5 ( V_172 ) ;
T_1 V_173 ;
F_3 ( V_77 , 0x01 ) ;
V_173 = F_8 ( V_78 ) | 0x20 ;
F_3 ( V_78 , V_173 ) ;
F_40 ( V_172 , V_171 | 0x00200000 ) ;
F_14 ( 1000 ) ;
F_40 ( V_172 , V_171 & ~ 0x00200000 ) ;
F_3 ( V_78 , V_173 & ~ 0x20 ) ;
}
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_48 >= 0x04 ) {
F_3 ( V_105 , 0x06 ) ;
F_3 ( V_106 , 0 ) ;
} else if ( V_7 -> V_48 >= 0x02 ) {
T_1 V_174 ;
T_2 V_175 ;
T_2 V_176 ;
if ( V_10 -> V_16 -> V_17 [ 0 ] * 8 > 16 )
V_175 = 32 ;
else if ( V_10 -> V_16 -> V_17 [ 0 ] * 8 > 8 )
V_175 = 16 ;
else
V_175 = 8 ;
V_176 = ( V_130 -> clock * V_175 ) / 1000 ;
if ( V_176 > 3100 )
V_174 = 0 ;
else if ( V_176 > 2600 )
V_174 = 1 ;
else if ( V_176 > 1900 )
V_174 = 2 ;
else if ( V_176 > 1160 )
V_174 = 3 ;
else if ( V_176 > 440 )
V_174 = 4 ;
else
V_174 = 5 ;
F_3 ( V_105 , 0x06 ) ;
F_3 ( V_106 , V_174 ) ;
} else {
F_3 ( V_105 , 0x06 ) ;
if ( V_7 -> V_48 >= 0x01 )
F_3 ( V_106 , 0x03 ) ;
else
F_3 ( V_106 , 0x04 ) ;
}
}
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , int V_130 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_173 = 0 , V_177 = 0 ;
switch ( V_130 ) {
case V_178 :
V_173 = 0 ;
V_177 = 0 ;
F_1 ( V_2 ) ;
break;
case V_179 :
V_173 = 0x20 ;
V_177 = 0x10 ;
break;
case V_180 :
V_173 = 0x20 ;
V_177 = 0x20 ;
break;
case V_181 :
V_173 = 0x20 ;
V_177 = 0x30 ;
break;
}
#if 0
if (mode == DRM_MODE_DPMS_OFF) {
mga_suspend(crtc);
}
#endif
F_3 ( V_77 , 0x01 ) ;
V_173 |= F_8 ( V_78 ) & ~ 0x20 ;
F_4 ( V_7 ) ;
F_7 ( V_7 ) ;
F_3 ( V_78 , V_173 ) ;
F_12 ( 20 ) ;
F_3 ( V_105 , 0x01 ) ;
V_177 |= F_8 ( V_106 ) & ~ 0x30 ;
F_3 ( V_106 , V_177 ) ;
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
T_1 V_57 ;
F_3 ( V_59 , 0x11 ) ;
V_57 = F_8 ( V_60 ) ;
F_23 ( 0x11 , V_57 | 0x80 ) ;
if ( V_7 -> type == V_95 || V_7 -> type == V_96 ) {
F_38 ( 0 , 1 ) ;
F_12 ( 50 ) ;
F_38 ( 1 , 0x20 ) ;
F_12 ( 20 ) ;
} else {
F_3 ( V_77 , 0x1 ) ;
V_57 = F_8 ( V_78 ) ;
F_38 ( 0 , 1 ) ;
F_38 ( 1 , V_57 | 0x20 ) ;
}
if ( V_7 -> type == V_97 || V_7 -> type == V_58 )
F_19 ( V_2 ) ;
F_23 ( 17 , 0 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_182 * V_183 = V_2 -> V_184 ;
T_1 V_57 ;
if ( V_7 -> type == V_97 || V_7 -> type == V_58 )
F_20 ( V_2 ) ;
if ( V_7 -> type == V_95 || V_7 -> type == V_96 ) {
F_12 ( 50 ) ;
F_38 ( 1 , 0x0 ) ;
F_12 ( 20 ) ;
F_38 ( 0 , 0x3 ) ;
} else {
F_3 ( V_77 , 0x1 ) ;
V_57 = F_8 ( V_78 ) ;
V_57 &= ~ 0x20 ;
F_38 ( 0x1 , V_57 ) ;
F_38 ( 0 , 3 ) ;
}
V_183 -> V_185 ( V_2 , V_178 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_4 * V_186 , T_4 * V_187 ,
T_4 * V_188 , T_5 V_189 ,
struct V_190 * V_191 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_189 ; V_12 ++ ) {
V_3 -> V_23 [ V_12 ] = V_186 [ V_12 ] >> 8 ;
V_3 -> V_26 [ V_12 ] = V_187 [ V_12 ] >> 8 ;
V_3 -> V_24 [ V_12 ] = V_188 [ V_12 ] >> 8 ;
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
int V_121 ;
F_49 ( L_3 ) ;
F_41 ( V_2 , V_181 ) ;
if ( V_2 -> V_11 -> V_10 ) {
struct V_117 * V_118 = F_26 ( V_2 -> V_11 -> V_10 ) ;
struct V_115 * V_116 = V_118 -> V_116 ;
struct V_119 * V_120 = F_27 ( V_116 ) ;
V_121 = F_28 ( V_120 , false ) ;
if ( V_121 )
return;
F_29 ( V_120 ) ;
F_30 ( V_120 ) ;
}
V_2 -> V_11 -> V_10 = NULL ;
}
static void F_50 ( struct V_6 * V_7 )
{
struct V_3 * V_3 ;
int V_12 ;
V_3 = F_51 ( sizeof( struct V_3 ) +
( V_192 * sizeof( struct V_193 * ) ) ,
V_194 ) ;
if ( V_3 == NULL )
return;
F_52 ( V_7 -> V_5 , & V_3 -> V_195 , & V_196 ) ;
F_53 ( & V_3 -> V_195 , V_22 ) ;
V_7 -> V_197 . V_2 = V_3 ;
for ( V_12 = 0 ; V_12 < V_22 ; V_12 ++ ) {
V_3 -> V_23 [ V_12 ] = V_12 ;
V_3 -> V_26 [ V_12 ] = V_12 ;
V_3 -> V_24 [ V_12 ] = V_12 ;
}
F_54 ( & V_3 -> V_195 , & V_198 ) ;
}
void F_55 ( struct V_1 * V_2 , T_4 V_186 , T_4 V_187 ,
T_4 V_188 , int V_199 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_23 [ V_199 ] = V_186 >> 8 ;
V_3 -> V_26 [ V_199 ] = V_187 >> 8 ;
V_3 -> V_24 [ V_199 ] = V_188 >> 8 ;
}
void F_56 ( struct V_1 * V_2 , T_4 * V_186 , T_4 * V_187 ,
T_4 * V_188 , int V_199 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_186 = ( T_4 ) V_3 -> V_23 [ V_199 ] << 8 ;
* V_187 = ( T_4 ) V_3 -> V_26 [ V_199 ] << 8 ;
* V_188 = ( T_4 ) V_3 -> V_24 [ V_199 ] << 8 ;
}
static void F_57 ( struct V_200 * V_201 ,
struct V_129 * V_130 ,
struct V_129 * V_131 )
{
}
static void F_58 ( struct V_200 * V_201 , int V_202 )
{
return;
}
static void F_59 ( struct V_200 * V_201 )
{
}
static void F_60 ( struct V_200 * V_201 )
{
}
static void F_61 ( struct V_200 * V_201 )
{
struct V_203 * V_203 = F_62 ( V_201 ) ;
F_63 ( V_201 ) ;
F_47 ( V_203 ) ;
}
static struct V_200 * F_64 ( struct V_4 * V_5 )
{
struct V_200 * V_201 ;
struct V_203 * V_203 ;
V_203 = F_51 ( sizeof( struct V_203 ) , V_194 ) ;
if ( ! V_203 )
return NULL ;
V_201 = & V_203 -> V_195 ;
V_201 -> V_204 = 0x1 ;
F_65 ( V_5 , V_201 , & V_205 ,
V_206 , NULL ) ;
F_66 ( V_201 , & V_207 ) ;
return V_201 ;
}
static int F_67 ( struct V_193 * V_208 )
{
struct V_209 * V_209 = F_68 ( V_208 ) ;
struct V_210 * V_210 ;
int V_121 = 0 ;
V_210 = F_69 ( V_208 , & V_209 -> V_211 -> V_212 ) ;
if ( V_210 ) {
F_70 ( V_208 , V_210 ) ;
V_121 = F_71 ( V_208 , V_210 ) ;
F_47 ( V_210 ) ;
}
return V_121 ;
}
static T_5 F_72 ( struct V_129 * V_130 ,
int V_213 )
{
T_5 V_214 , V_215 ;
T_6 V_216 , V_217 , V_218 ;
T_6 V_219 = ( V_213 + 7 ) / 8 ;
V_215 = 1024 ;
if ( ! V_130 -> V_135 || ! V_130 -> V_139 || ! V_130 -> clock )
return 0 ;
V_216 = V_130 -> V_132 * V_130 -> V_136 ;
V_214 = V_130 -> V_135 * V_130 -> V_139 ;
V_217 = V_216 * V_130 -> clock * 1000 ;
F_73 ( V_217 , V_214 ) ;
V_218 = V_217 * V_219 * 100 ;
F_73 ( V_218 , V_215 ) ;
return ( T_5 ) ( V_218 ) ;
}
static int F_74 ( struct V_193 * V_208 ,
struct V_129 * V_130 )
{
struct V_4 * V_5 = V_208 -> V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_5 -> V_8 ;
int V_175 = 32 ;
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_48 == 0x01 ) {
if ( V_130 -> V_132 > 1600 )
return V_220 ;
if ( V_130 -> V_136 > 1200 )
return V_221 ;
if ( F_72 ( V_130 , V_175 )
> ( 24400 * 1024 ) )
return V_222 ;
} else if ( V_7 -> V_48 == 0x02 ) {
if ( V_130 -> V_132 > 1920 )
return V_220 ;
if ( V_130 -> V_136 > 1200 )
return V_221 ;
if ( F_72 ( V_130 , V_175 )
> ( 30100 * 1024 ) )
return V_222 ;
} else {
if ( F_72 ( V_130 , V_175 )
> ( 55000 * 1024 ) )
return V_222 ;
}
} else if ( V_7 -> type == V_97 ) {
if ( V_130 -> V_132 > 1280 )
return V_220 ;
if ( V_130 -> V_136 > 1024 )
return V_221 ;
if ( F_72 ( V_130 ,
V_175 > ( 31877 * 1024 ) ) )
return V_222 ;
} else if ( V_7 -> type == V_98 &&
( F_72 ( V_130 , V_175 )
> ( 32700 * 1024 ) ) ) {
return V_222 ;
} else if ( V_7 -> type == V_99 &&
( F_72 ( V_130 , V_175 )
> ( 37500 * 1024 ) ) ) {
return V_222 ;
} else if ( V_7 -> type == V_100 &&
( F_72 ( V_130 ,
V_175 ) > ( 55000 * 1024 ) ) ) {
return V_222 ;
}
if ( ( V_130 -> V_132 % 8 ) != 0 || ( V_130 -> V_166 % 8 ) != 0 ||
( V_130 -> V_167 % 8 ) != 0 || ( V_130 -> V_135 % 8 ) != 0 ) {
return V_223 ;
}
if ( V_130 -> V_224 > 2048 || V_130 -> V_225 > 4096 ||
V_130 -> V_226 > 4096 || V_130 -> V_227 > 4096 ||
V_130 -> V_228 > 2048 || V_130 -> V_229 > 4096 ||
V_130 -> V_230 > 4096 || V_130 -> V_231 > 4096 ) {
return V_232 ;
}
if ( V_208 -> V_233 . V_234 ) {
if ( V_208 -> V_233 . V_235 )
V_175 = V_208 -> V_233 . V_175 ;
}
if ( ( V_130 -> V_132 * V_130 -> V_136 * ( V_175 / 8 ) ) > V_7 -> V_236 . V_237 ) {
if ( V_208 -> V_233 . V_234 )
V_208 -> V_233 . V_234 = false ;
return V_232 ;
}
return V_238 ;
}
static struct V_200 * F_75 ( struct V_193
* V_208 )
{
int V_239 = V_208 -> V_240 [ 0 ] ;
if ( V_239 )
return F_76 ( V_208 -> V_5 , V_239 ) ;
return NULL ;
}
static void F_77 ( struct V_193 * V_208 )
{
struct V_209 * V_209 = F_68 ( V_208 ) ;
F_78 ( V_209 -> V_211 ) ;
F_79 ( V_208 ) ;
F_47 ( V_208 ) ;
}
static struct V_193 * F_80 ( struct V_4 * V_5 )
{
struct V_193 * V_208 ;
struct V_209 * V_209 ;
V_209 = F_51 ( sizeof( struct V_209 ) , V_194 ) ;
if ( ! V_209 )
return NULL ;
V_208 = & V_209 -> V_195 ;
F_81 ( V_5 , V_208 ,
& V_241 , V_242 ) ;
F_82 ( V_208 , & V_243 ) ;
F_83 ( V_208 ) ;
V_209 -> V_211 = F_84 ( V_5 ) ;
if ( ! V_209 -> V_211 )
F_33 ( L_4 ) ;
return V_208 ;
}
int F_85 ( struct V_6 * V_7 )
{
struct V_200 * V_201 ;
struct V_193 * V_208 ;
int V_121 ;
V_7 -> V_197 . V_244 = true ;
V_7 -> V_5 -> V_245 . V_246 = V_247 ;
V_7 -> V_5 -> V_245 . V_248 = V_249 ;
V_7 -> V_5 -> V_245 . V_250 = V_7 -> V_236 . V_251 ;
F_50 ( V_7 ) ;
V_201 = F_64 ( V_7 -> V_5 ) ;
if ( ! V_201 ) {
F_33 ( L_5 ) ;
return - 1 ;
}
V_208 = F_80 ( V_7 -> V_5 ) ;
if ( ! V_208 ) {
F_33 ( L_6 ) ;
return - 1 ;
}
F_86 ( V_208 , V_201 ) ;
V_121 = F_87 ( V_7 ) ;
if ( V_121 ) {
F_33 ( L_7 ) ;
return V_121 ;
}
return 0 ;
}
void F_88 ( struct V_6 * V_7 )
{
}
