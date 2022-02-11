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
static int F_9 ( struct V_6 * V_7 , long clock )
{
unsigned int V_31 , V_32 , V_33 ;
unsigned int V_34 , V_35 , V_36 ;
unsigned int V_37 , V_38 , V_39 ;
unsigned int V_40 , V_41 , V_42 ;
unsigned int V_43 ;
unsigned int V_44 [ V_45 ] = { 16 , 14 , 12 , 10 , 8 , 6 , 4 , 2 , 1 } ;
unsigned int V_46 ;
unsigned int V_12 ;
if ( V_7 -> V_47 <= 0x03 ) {
V_41 = V_42 = V_40 = 0 ;
V_31 = 320000 ;
V_32 = 160000 ;
V_33 = 25000 ;
V_34 = 0xffffffff ;
V_36 = clock * 5 / 1000 ;
for ( V_37 = 8 ; V_37 > 0 ; V_37 /= 2 ) {
if ( clock * V_37 > V_31 )
continue;
if ( clock * V_37 < V_32 )
continue;
for ( V_39 = 17 ; V_39 < 256 ; V_39 ++ ) {
for ( V_38 = 1 ; V_38 < 32 ; V_38 ++ ) {
V_43 = ( V_33 * V_39 ) /
( V_38 * V_37 ) ;
if ( V_43 > clock )
V_35 = V_43 - clock ;
else
V_35 = clock - V_43 ;
if ( V_35 < V_34 ) {
V_34 = V_35 ;
V_41 = V_38 - 1 ;
V_42 = V_39 - 1 ;
V_40 = V_37 - 1 ;
}
}
}
}
} else {
V_41 = V_42 = V_40 = 0 ;
V_31 = 1600000 ;
V_32 = 800000 ;
V_33 = 25000 ;
if ( clock < 25000 )
clock = 25000 ;
clock = clock * 2 ;
V_34 = 0xFFFFFFFF ;
V_36 = clock * 5 / 1000 ;
for ( V_12 = 0 ; V_12 < V_45 ; V_12 ++ ) {
V_37 = V_44 [ V_12 ] ;
if ( ( clock * V_37 ) > V_31 )
continue;
if ( ( clock * V_37 ) < V_32 )
continue;
for ( V_39 = 50 ; V_39 <= 256 ; V_39 ++ ) {
for ( V_38 = 1 ; V_38 <= 32 ; V_38 ++ ) {
V_43 = ( V_33 * V_39 ) /
( V_38 * V_37 ) ;
if ( V_43 > clock )
V_35 = V_43 - clock ;
else
V_35 = clock - V_43 ;
if ( V_35 < V_34 ) {
V_34 = V_35 ;
V_41 = V_38 - 1 ;
V_42 = V_39 - 1 ;
V_40 = V_37 - 1 ;
}
}
}
}
V_46 = V_33 * ( V_42 + 1 ) / ( V_41 + 1 ) ;
V_46 = ( V_46 - 800000 ) / 50000 ;
if ( V_46 > 15 )
V_46 = 15 ;
V_40 |= ( V_46 << 4 ) ;
V_41 |= 0x80 ;
clock = clock / 2 ;
}
if ( V_34 > V_36 ) {
F_10 ( V_48 L_1 ) ;
return 1 ;
}
F_11 ( V_49 , V_41 ) ;
F_11 ( V_50 , V_42 ) ;
F_11 ( V_51 , V_40 ) ;
if ( V_7 -> V_47 >= 0x04 ) {
F_11 ( 0x1a , 0x09 ) ;
F_12 ( 20 ) ;
F_11 ( 0x1a , 0x01 ) ;
}
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , long clock )
{
unsigned int V_31 , V_32 , V_33 ;
unsigned int V_34 , V_35 ;
unsigned int V_37 , V_38 , V_39 , V_52 ;
unsigned int V_40 , V_41 , V_42 ;
unsigned int V_43 ;
int V_12 , V_53 , V_54 , V_55 ;
bool V_56 = false ;
T_1 V_57 ;
V_41 = V_42 = V_40 = 0 ;
V_34 = 0xffffffff ;
if ( V_7 -> type == V_58 ) {
V_31 = 800000 ;
V_32 = 400000 ;
V_33 = 25000 ;
for ( V_37 = 1 ; V_37 < 8 ; V_37 ++ ) {
for ( V_52 = 1 ; V_52 < 8 ; V_52 ++ ) {
if ( V_37 < V_52 )
continue;
if ( ( clock * V_37 * V_52 ) > V_31 )
continue;
if ( ( clock * V_37 * V_52 ) < V_32 )
continue;
for ( V_38 = 1 ; V_38 < 26 ; V_38 ++ ) {
for ( V_39 = 32 ; V_39 < 2048 ; V_39 ++ ) {
V_43 = ( V_33 * V_39 ) /
( V_38 * V_37 * V_52 ) ;
if ( V_43 > clock )
V_35 = V_43 - clock ;
else
V_35 = clock - V_43 ;
if ( V_35 < V_34 ) {
V_34 = V_35 ;
V_41 = ( ( V_39 & 0x100 ) >> 1 ) |
( V_38 ) ;
V_42 = ( V_39 & 0xFF ) ;
V_40 = ( ( V_39 & 0x600 ) >> 3 ) |
( V_52 << 3 ) |
( V_37 ) ;
}
}
}
}
}
} else {
V_31 = 550000 ;
V_32 = 150000 ;
V_33 = 48000 ;
for ( V_37 = 1 ; V_37 < 9 ; V_37 ++ ) {
if ( clock * V_37 > V_31 )
continue;
if ( clock * V_37 < V_32 )
continue;
for ( V_38 = 1 ; V_38 < 17 ; V_38 ++ ) {
for ( V_39 = 1 ; V_39 < 151 ; V_39 ++ ) {
V_43 = ( V_33 * V_39 ) /
( V_38 * V_37 ) ;
if ( V_43 > clock )
V_35 = V_43 - clock ;
else
V_35 = clock - V_43 ;
if ( V_35 < V_34 ) {
V_34 = V_35 ;
V_42 = V_39 - 1 ;
V_41 = ( V_38 - 1 ) |
( ( V_42 >> 1 ) & 0x80 ) ;
V_40 = V_37 - 1 ;
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
F_11 ( V_70 , V_42 ) ;
F_11 ( V_71 , V_41 ) ;
F_11 ( V_72 , V_40 ) ;
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
unsigned int V_31 , V_32 , V_33 ;
unsigned int V_34 , V_35 ;
unsigned int V_37 , V_38 , V_39 ;
unsigned int V_40 , V_41 , V_42 ;
unsigned int V_43 ;
T_1 V_57 ;
V_41 = V_42 = V_40 = 0 ;
V_31 = 550000 ;
V_32 = 150000 ;
V_33 = 50000 ;
V_34 = 0xffffffff ;
for ( V_37 = 16 ; V_37 > 0 ; V_37 -- ) {
if ( clock * V_37 > V_31 )
continue;
if ( clock * V_37 < V_32 )
continue;
for ( V_39 = 1 ; V_39 < 257 ; V_39 ++ ) {
for ( V_38 = 1 ; V_38 < 17 ; V_38 ++ ) {
V_43 = ( V_33 * V_39 ) /
( V_38 * V_37 ) ;
if ( V_43 > clock )
V_35 = V_43 - clock ;
else
V_35 = clock - V_43 ;
if ( V_35 < V_34 ) {
V_34 = V_35 ;
V_42 = V_39 - 1 ;
V_41 = V_38 - 1 ;
V_40 = V_37 - 1 ;
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
F_11 ( V_81 , V_41 ) ;
F_11 ( V_82 , V_42 ) ;
F_11 ( V_83 , V_40 ) ;
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
unsigned int V_31 , V_32 , V_33 ;
unsigned int V_34 , V_35 ;
unsigned int V_37 , V_38 , V_39 ;
unsigned int V_40 , V_41 , V_42 ;
unsigned int V_43 ;
int V_12 , V_53 , V_54 , V_55 ;
T_1 V_57 ;
bool V_56 = false ;
V_41 = V_42 = V_40 = 0 ;
V_31 = 800000 ;
V_32 = 400000 ;
V_33 = 33333 ;
V_34 = 0xffffffff ;
for ( V_37 = 16 ; V_37 > 0 ; V_37 >>= 1 ) {
if ( clock * V_37 > V_31 )
continue;
if ( clock * V_37 < V_32 )
continue;
for ( V_38 = 1 ; V_38 < 33 ; V_38 ++ ) {
for ( V_39 = 17 ; V_39 < 257 ; V_39 ++ ) {
V_43 = ( V_33 * V_39 ) /
( V_38 * V_37 ) ;
if ( V_43 > clock )
V_35 = V_43 - clock ;
else
V_35 = clock - V_43 ;
if ( V_35 < V_34 ) {
V_34 = V_35 ;
V_42 = V_39 - 1 ;
V_41 = ( V_38 - 1 ) ;
V_40 = V_37 - 1 ;
}
if ( ( clock * V_37 ) >= 600000 )
V_40 |= 0x80 ;
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
F_11 ( V_84 , V_41 ) ;
F_11 ( V_85 , V_42 ) ;
F_11 ( V_86 , V_40 ) ;
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
unsigned int V_31 , V_32 , V_33 ;
unsigned int V_34 , V_35 ;
int V_87 , V_39 , V_38 , V_88 ;
unsigned int V_40 , V_41 , V_42 ;
unsigned int V_43 , V_89 ;
int V_57 ;
const unsigned int V_90 [] = { 1 , 2 , 4 , 8 } ;
V_41 = V_42 = V_40 = 0 ;
V_31 = 1488000 ;
V_32 = 1056000 ;
V_33 = 48000 ;
V_34 = 0xffffffff ;
for ( V_87 = 0 ; V_87 < 4 ; V_87 ++ ) {
if ( V_34 == 0 )
break;
for ( V_39 = 5 ; V_39 < 129 ; V_39 ++ ) {
if ( V_34 == 0 )
break;
for ( V_38 = 3 ; V_38 >= 0 ; V_38 -- ) {
if ( V_34 == 0 )
break;
for ( V_88 = 5 ; V_88 < 33 ; V_88 ++ ) {
V_89 = V_33 * ( V_39 + 1 ) /
( V_87 + 1 ) ;
if ( V_89 < V_32 )
continue;
if ( V_89 > V_31 )
continue;
V_43 = V_89 / ( V_90 [ V_38 ] * ( V_88 + 1 ) ) ;
if ( V_43 > clock )
V_35 = V_43 - clock ;
else
V_35 = clock - V_43 ;
if ( V_35 < V_34 ) {
V_34 = V_35 ;
V_41 = V_38 | ( V_88 << 3 ) ;
V_42 = V_39 ;
V_40 = V_87 | ( V_87 << 3 ) ;
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
F_11 ( V_91 , V_42 ) ;
F_11 ( V_92 , V_41 ) ;
F_11 ( V_93 , V_40 ) ;
F_14 ( 50 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , long clock )
{
switch( V_7 -> type ) {
case V_94 :
case V_95 :
return F_9 ( V_7 , clock ) ;
break;
case V_96 :
case V_58 :
return F_13 ( V_7 , clock ) ;
break;
case V_97 :
return F_15 ( V_7 , clock ) ;
break;
case V_98 :
return F_16 ( V_7 , clock ) ;
break;
case V_99 :
return F_17 ( V_7 , clock ) ;
break;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_1 V_57 ;
int V_100 ;
F_3 ( V_14 , V_101 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= 0x10 ;
F_11 ( V_101 , V_57 ) ;
F_3 ( V_14 , V_102 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= 0x10 ;
F_11 ( V_102 , V_57 ) ;
F_3 ( V_14 , V_103 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= 0x80 ;
F_11 ( V_103 , V_57 ) ;
V_100 = 300 ;
while ( ! ( V_57 & 0x1 ) && V_100 ) {
F_3 ( V_14 , V_103 ) ;
V_57 = F_8 ( V_62 ) ;
F_14 ( 1000 ) ;
V_100 -- ;
}
if ( V_100 ) {
V_100 = 300 ;
while ( ( V_57 & 0x2 ) && V_100 ) {
F_3 ( V_14 , V_103 ) ;
V_57 = F_8 ( V_62 ) ;
F_14 ( 1000 ) ;
V_100 -- ;
}
}
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_57 ;
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
F_3 ( V_104 , 1 ) ;
V_57 = F_8 ( V_105 ) ;
F_3 ( V_105 , V_57 | 0x88 ) ;
F_3 ( V_14 , V_106 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 |= 0x8 ;
F_3 ( V_62 , V_57 ) ;
F_14 ( 10 ) ;
V_57 &= ~ 0x08 ;
F_3 ( V_14 , V_106 ) ;
F_3 ( V_62 , V_57 ) ;
F_3 ( V_14 , V_103 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ 0x80 ;
F_3 ( V_62 , V_57 ) ;
F_3 ( V_14 , V_102 ) ;
V_57 = F_8 ( V_62 ) ;
V_57 &= ~ 0x10 ;
F_11 ( V_102 , V_57 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned V_107 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_2 V_108 ;
int V_109 ;
T_1 V_110 ;
while ( F_8 ( 0x1fda ) & 0x08 ) ;
while ( ! ( F_8 ( 0x1fda ) & 0x08 ) ) ;
V_109 = F_8 ( V_79 ) + 2 ;
while ( F_8 ( V_79 ) < V_109 ) ;
F_3 ( V_104 , 0 ) ;
V_110 = F_8 ( V_105 ) ;
V_110 &= 0xB0 ;
V_108 = V_107 / 8 ;
F_22 ( V_108 > 0x1fffff ) ;
V_110 |= ( ! ! ( V_108 & ( 1 << 20 ) ) ) << 6 ;
F_23 ( 0x0d , ( T_1 ) ( V_108 & 0xff ) ) ;
F_23 ( 0x0c , ( T_1 ) ( V_108 >> 8 ) & 0xff ) ;
F_24 ( 0x0 , ( ( T_1 ) ( V_108 >> 16 ) & 0xf ) | V_110 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
int V_111 , int V_112 , int V_113 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
int V_120 ;
T_3 V_121 ;
if ( ! V_113 && V_10 ) {
V_117 = F_26 ( V_10 ) ;
V_115 = V_117 -> V_115 ;
V_119 = F_27 ( V_115 ) ;
V_120 = F_28 ( V_119 , false ) ;
if ( V_120 )
return V_120 ;
F_29 ( V_119 ) ;
F_30 ( V_119 ) ;
}
V_117 = F_26 ( V_2 -> V_11 -> V_10 ) ;
V_115 = V_117 -> V_115 ;
V_119 = F_27 ( V_115 ) ;
V_120 = F_28 ( V_119 , false ) ;
if ( V_120 )
return V_120 ;
V_120 = F_31 ( V_119 , V_122 , & V_121 ) ;
if ( V_120 ) {
F_30 ( V_119 ) ;
return V_120 ;
}
if ( & V_7 -> V_123 -> V_124 == V_117 ) {
V_120 = F_32 ( & V_119 -> V_119 , 0 , V_119 -> V_119 . V_125 , & V_119 -> V_126 ) ;
if ( V_120 )
F_33 ( L_2 ) ;
}
F_30 ( V_119 ) ;
F_21 ( V_2 , ( T_2 ) V_121 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_111 , int V_112 ,
struct V_9 * V_127 )
{
return F_25 ( V_2 , V_127 , V_111 , V_112 , 0 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_128 * V_129 ,
struct V_128 * V_130 ,
int V_111 , int V_112 , struct V_9 * V_127 )
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
case V_94 :
case V_95 :
V_145 [ V_69 ] = 0x03 ;
V_145 [ V_61 ] = V_74 ;
V_145 [ V_147 ] = V_148 |
V_149 |
V_150 ;
if ( V_7 -> V_151 )
V_140 = 0x40049120 ;
else
V_140 = 0x4004d120 ;
V_141 = 0x00008000 ;
break;
case V_96 :
case V_58 :
V_145 [ V_69 ] = 0x07 ;
V_140 = 0x41049120 ;
V_141 = 0x0000b000 ;
break;
case V_97 :
V_145 [ V_61 ] = V_74 ;
V_145 [ V_147 ] = V_149 |
V_150 ;
V_140 = 0x00000120 ;
V_141 = 0x0000b000 ;
break;
case V_98 :
V_145 [ V_147 ] = V_149 |
V_150 ;
V_140 = 0x00000120 ;
V_141 = 0x0000b000 ;
break;
case V_99 :
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
if ( V_129 -> V_158 & V_159 )
V_142 |= 0x40 ;
if ( V_129 -> V_158 & V_160 )
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
if ( ( V_7 -> type == V_97 ||
V_7 -> type == V_96 ||
V_7 -> type == V_98 ||
V_7 -> type == V_58 ) &&
( V_12 >= 0x44 ) && ( V_12 <= 0x4e ) )
continue;
F_11 ( V_12 , V_145 [ V_12 ] ) ;
}
if ( V_7 -> type == V_99 )
F_11 ( 0x90 , 0 ) ;
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
V_131 = V_129 -> V_131 / 8 - 1 ;
V_132 = V_129 -> V_165 / 8 - 1 ;
V_133 = V_129 -> V_166 / 8 - 1 ;
V_134 = V_129 -> V_134 / 8 - 1 ;
if ( ( V_134 & 0x07 ) == 0x06 || ( V_134 & 0x07 ) == 0x04 )
V_134 ++ ;
V_135 = V_129 -> V_135 - 1 ;
V_136 = V_129 -> V_167 - 1 ;
V_137 = V_129 -> V_168 - 1 ;
V_138 = V_129 -> V_138 - 2 ;
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
if ( V_7 -> type == V_96 || V_7 -> type == V_58 )
V_143 [ 1 ] |= 0x88 ;
V_142 = 0x2d ;
F_3 ( V_169 , V_142 ) ;
F_18 ( V_7 , V_129 -> clock ) ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
F_24 ( V_12 , V_143 [ V_12 ] ) ;
}
if ( V_7 -> type == V_99 )
F_24 ( 0x24 , 0x5 ) ;
if ( V_7 -> type == V_58 )
F_24 ( 0x34 , 0x5 ) ;
if ( V_7 -> type == V_97 ) {
F_24 ( 6 , 0 ) ;
}
F_24 ( 0 , V_143 [ 0 ] ) ;
V_142 = 0x2d ;
F_3 ( V_169 , V_142 ) ;
if ( V_130 )
memcpy ( & V_7 -> V_129 , V_129 , sizeof( struct V_128 ) ) ;
F_25 ( V_2 , V_127 , V_111 , V_112 , 0 ) ;
if ( V_7 -> type == V_99 ) {
T_2 V_170 = F_5 ( V_171 ) ;
T_1 V_172 ;
F_3 ( V_77 , 0x01 ) ;
V_172 = F_8 ( V_78 ) | 0x20 ;
F_3 ( V_78 , V_172 ) ;
F_40 ( V_171 , V_170 | 0x00200000 ) ;
F_14 ( 1000 ) ;
F_40 ( V_171 , V_170 & ~ 0x00200000 ) ;
F_3 ( V_78 , V_172 & ~ 0x20 ) ;
}
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_47 >= 0x02 ) {
T_1 V_173 ;
T_2 V_174 ;
T_2 V_175 ;
if ( V_2 -> V_11 -> V_10 -> V_16 > 16 )
V_174 = 32 ;
else if ( V_2 -> V_11 -> V_10 -> V_16 > 8 )
V_174 = 16 ;
else
V_174 = 8 ;
V_175 = ( V_129 -> clock * V_174 ) / 1000 ;
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
F_3 ( V_104 , 0x06 ) ;
F_3 ( V_105 , V_173 ) ;
} else {
F_3 ( V_104 , 0x06 ) ;
if ( V_7 -> V_47 >= 0x01 )
F_3 ( V_105 , 0x03 ) ;
else
F_3 ( V_105 , 0x04 ) ;
}
}
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , int V_129 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_172 = 0 , V_176 = 0 ;
switch ( V_129 ) {
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
F_3 ( V_77 , 0x01 ) ;
V_172 |= F_8 ( V_78 ) & ~ 0x20 ;
F_4 ( V_7 ) ;
F_7 ( V_7 ) ;
F_3 ( V_78 , V_172 ) ;
F_12 ( 20 ) ;
F_3 ( V_104 , 0x01 ) ;
V_176 |= F_8 ( V_105 ) & ~ 0x30 ;
F_3 ( V_105 , V_176 ) ;
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
if ( V_7 -> type == V_94 || V_7 -> type == V_95 ) {
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
if ( V_7 -> type == V_96 || V_7 -> type == V_58 )
F_19 ( V_2 ) ;
F_23 ( 17 , 0 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_181 * V_182 = V_2 -> V_183 ;
T_1 V_57 ;
if ( V_7 -> type == V_96 || V_7 -> type == V_58 )
F_20 ( V_2 ) ;
if ( V_7 -> type == V_94 || V_7 -> type == V_95 ) {
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
V_182 -> V_184 ( V_2 , V_177 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_4 * V_185 , T_4 * V_186 ,
T_4 * V_187 , T_5 V_188 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_188 ; V_12 ++ ) {
V_3 -> V_22 [ V_12 ] = V_185 [ V_12 ] >> 8 ;
V_3 -> V_25 [ V_12 ] = V_186 [ V_12 ] >> 8 ;
V_3 -> V_23 [ V_12 ] = V_187 [ V_12 ] >> 8 ;
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
int V_120 ;
F_49 ( L_3 ) ;
F_41 ( V_2 , V_180 ) ;
if ( V_2 -> V_11 -> V_10 ) {
struct V_116 * V_117 = F_26 ( V_2 -> V_11 -> V_10 ) ;
struct V_114 * V_115 = V_117 -> V_115 ;
struct V_118 * V_119 = F_27 ( V_115 ) ;
V_120 = F_28 ( V_119 , false ) ;
if ( V_120 )
return;
F_29 ( V_119 ) ;
F_30 ( V_119 ) ;
}
V_2 -> V_11 -> V_10 = NULL ;
}
static void F_50 ( struct V_6 * V_7 )
{
struct V_3 * V_3 ;
int V_12 ;
V_3 = F_51 ( sizeof( struct V_3 ) +
( V_189 * sizeof( struct V_190 * ) ) ,
V_191 ) ;
if ( V_3 == NULL )
return;
F_52 ( V_7 -> V_5 , & V_3 -> V_192 , & V_193 ) ;
F_53 ( & V_3 -> V_192 , V_21 ) ;
V_7 -> V_194 . V_2 = V_3 ;
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ ) {
V_3 -> V_22 [ V_12 ] = V_12 ;
V_3 -> V_25 [ V_12 ] = V_12 ;
V_3 -> V_23 [ V_12 ] = V_12 ;
}
F_54 ( & V_3 -> V_192 , & V_195 ) ;
}
void F_55 ( struct V_1 * V_2 , T_4 V_185 , T_4 V_186 ,
T_4 V_187 , int V_196 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_22 [ V_196 ] = V_185 >> 8 ;
V_3 -> V_25 [ V_196 ] = V_186 >> 8 ;
V_3 -> V_23 [ V_196 ] = V_187 >> 8 ;
}
void F_56 ( struct V_1 * V_2 , T_4 * V_185 , T_4 * V_186 ,
T_4 * V_187 , int V_196 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_185 = ( T_4 ) V_3 -> V_22 [ V_196 ] << 8 ;
* V_186 = ( T_4 ) V_3 -> V_25 [ V_196 ] << 8 ;
* V_187 = ( T_4 ) V_3 -> V_23 [ V_196 ] << 8 ;
}
static void F_57 ( struct V_197 * V_198 ,
struct V_128 * V_129 ,
struct V_128 * V_130 )
{
}
static void F_58 ( struct V_197 * V_198 , int V_199 )
{
return;
}
static void F_59 ( struct V_197 * V_198 )
{
}
static void F_60 ( struct V_197 * V_198 )
{
}
static void F_61 ( struct V_197 * V_198 )
{
struct V_200 * V_200 = F_62 ( V_198 ) ;
F_63 ( V_198 ) ;
F_47 ( V_200 ) ;
}
static struct V_197 * F_64 ( struct V_4 * V_5 )
{
struct V_197 * V_198 ;
struct V_200 * V_200 ;
V_200 = F_51 ( sizeof( struct V_200 ) , V_191 ) ;
if ( ! V_200 )
return NULL ;
V_198 = & V_200 -> V_192 ;
V_198 -> V_201 = 0x1 ;
F_65 ( V_5 , V_198 , & V_202 ,
V_203 , NULL ) ;
F_66 ( V_198 , & V_204 ) ;
return V_198 ;
}
static int F_67 ( struct V_190 * V_205 )
{
struct V_206 * V_206 = F_68 ( V_205 ) ;
struct V_207 * V_207 ;
int V_120 = 0 ;
V_207 = F_69 ( V_205 , & V_206 -> V_208 -> V_209 ) ;
if ( V_207 ) {
F_70 ( V_205 , V_207 ) ;
V_120 = F_71 ( V_205 , V_207 ) ;
F_47 ( V_207 ) ;
}
return V_120 ;
}
static T_5 F_72 ( struct V_128 * V_129 ,
int V_16 )
{
T_5 V_210 , V_211 ;
T_6 V_212 , V_213 , V_214 ;
T_6 V_215 = ( V_16 + 7 ) / 8 ;
V_211 = 1024 ;
if ( ! V_129 -> V_134 || ! V_129 -> V_138 || ! V_129 -> clock )
return 0 ;
V_212 = V_129 -> V_131 * V_129 -> V_135 ;
V_210 = V_129 -> V_134 * V_129 -> V_138 ;
V_213 = V_212 * V_129 -> clock * 1000 ;
F_73 ( V_213 , V_210 ) ;
V_214 = V_213 * V_215 * 100 ;
F_73 ( V_214 , V_211 ) ;
return ( T_5 ) ( V_214 ) ;
}
static int F_74 ( struct V_190 * V_205 ,
struct V_128 * V_129 )
{
struct V_4 * V_5 = V_205 -> V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_5 -> V_8 ;
int V_174 = 32 ;
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_47 == 0x01 ) {
if ( V_129 -> V_131 > 1600 )
return V_216 ;
if ( V_129 -> V_135 > 1200 )
return V_217 ;
if ( F_72 ( V_129 , V_174 )
> ( 24400 * 1024 ) )
return V_218 ;
} else if ( V_7 -> V_47 == 0x02 ) {
if ( V_129 -> V_131 > 1920 )
return V_216 ;
if ( V_129 -> V_135 > 1200 )
return V_217 ;
if ( F_72 ( V_129 , V_174 )
> ( 30100 * 1024 ) )
return V_218 ;
}
} else if ( V_7 -> type == V_96 ) {
if ( V_129 -> V_131 > 1280 )
return V_216 ;
if ( V_129 -> V_135 > 1024 )
return V_217 ;
if ( F_72 ( V_129 ,
V_174 > ( 31877 * 1024 ) ) )
return V_218 ;
} else if ( V_7 -> type == V_97 &&
( F_72 ( V_129 , V_174 )
> ( 32700 * 1024 ) ) ) {
return V_218 ;
} else if ( V_7 -> type == V_98 &&
( F_72 ( V_129 , V_174 )
> ( 37500 * 1024 ) ) ) {
return V_218 ;
} else if ( V_7 -> type == V_99 &&
( F_72 ( V_129 ,
V_174 ) > ( 55000 * 1024 ) ) ) {
return V_218 ;
}
if ( ( V_129 -> V_131 % 8 ) != 0 || ( V_129 -> V_165 % 8 ) != 0 ||
( V_129 -> V_166 % 8 ) != 0 || ( V_129 -> V_134 % 8 ) != 0 ) {
return V_219 ;
}
if ( V_129 -> V_220 > 2048 || V_129 -> V_221 > 4096 ||
V_129 -> V_222 > 4096 || V_129 -> V_223 > 4096 ||
V_129 -> V_224 > 2048 || V_129 -> V_225 > 4096 ||
V_129 -> V_226 > 4096 || V_129 -> V_227 > 4096 ) {
return V_228 ;
}
if ( V_205 -> V_229 . V_230 ) {
if ( V_205 -> V_229 . V_231 )
V_174 = V_205 -> V_229 . V_174 ;
}
if ( ( V_129 -> V_131 * V_129 -> V_135 * ( V_174 / 8 ) ) > V_7 -> V_232 . V_233 ) {
if ( V_205 -> V_229 . V_230 )
V_205 -> V_229 . V_230 = false ;
return V_228 ;
}
return V_234 ;
}
static struct V_197 * F_75 ( struct V_190
* V_205 )
{
int V_235 = V_205 -> V_236 [ 0 ] ;
if ( V_235 )
return F_76 ( V_205 -> V_5 , V_235 ) ;
return NULL ;
}
static enum V_237 F_77 ( struct V_190
* V_205 , bool V_238 )
{
return V_239 ;
}
static void F_78 ( struct V_190 * V_205 )
{
struct V_206 * V_206 = F_68 ( V_205 ) ;
F_79 ( V_206 -> V_208 ) ;
F_80 ( V_205 ) ;
F_47 ( V_205 ) ;
}
static struct V_190 * F_81 ( struct V_4 * V_5 )
{
struct V_190 * V_205 ;
struct V_206 * V_206 ;
V_206 = F_51 ( sizeof( struct V_206 ) , V_191 ) ;
if ( ! V_206 )
return NULL ;
V_205 = & V_206 -> V_192 ;
F_82 ( V_5 , V_205 ,
& V_240 , V_241 ) ;
F_83 ( V_205 , & V_242 ) ;
F_84 ( V_205 ) ;
V_206 -> V_208 = F_85 ( V_5 ) ;
if ( ! V_206 -> V_208 )
F_33 ( L_4 ) ;
return V_205 ;
}
int F_86 ( struct V_6 * V_7 )
{
struct V_197 * V_198 ;
struct V_190 * V_205 ;
int V_120 ;
V_7 -> V_194 . V_243 = true ;
V_7 -> V_5 -> V_244 . V_245 = V_246 ;
V_7 -> V_5 -> V_244 . V_247 = V_248 ;
V_7 -> V_5 -> V_244 . V_249 = V_7 -> V_232 . V_250 ;
F_50 ( V_7 ) ;
V_198 = F_64 ( V_7 -> V_5 ) ;
if ( ! V_198 ) {
F_33 ( L_5 ) ;
return - 1 ;
}
V_205 = F_81 ( V_7 -> V_5 ) ;
if ( ! V_205 ) {
F_33 ( L_6 ) ;
return - 1 ;
}
F_87 ( V_205 , V_198 ) ;
V_120 = F_88 ( V_7 ) ;
if ( V_120 ) {
F_33 ( L_7 ) ;
return V_120 ;
}
return 0 ;
}
void F_89 ( struct V_6 * V_7 )
{
}
