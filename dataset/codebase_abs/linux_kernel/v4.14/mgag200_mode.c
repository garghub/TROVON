static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 -> V_9 ;
T_1 * V_11 , * V_12 , * V_13 ;
int V_14 ;
if ( ! V_2 -> V_15 )
return;
V_11 = V_2 -> V_16 ;
V_12 = V_11 + V_2 -> V_17 ;
V_13 = V_12 + V_2 -> V_17 ;
F_2 ( V_18 + V_19 , 0 ) ;
if ( V_9 && V_9 -> V_20 -> V_21 [ 0 ] * 8 == 16 ) {
int V_22 = ( V_9 -> V_20 -> V_23 == 15 ) ? 8 : 4 ;
T_2 V_24 , V_25 ;
for ( V_14 = 0 ; V_14 < V_26 ; V_14 += V_22 ) {
if ( V_9 -> V_20 -> V_23 == 16 ) {
if ( V_14 > ( V_26 >> 1 ) ) {
V_24 = V_25 = 0 ;
} else {
V_24 = * V_11 ++ >> 8 ;
V_25 = * V_13 ++ >> 8 ;
V_11 ++ ;
V_13 ++ ;
}
} else {
V_24 = * V_11 ++ >> 8 ;
V_25 = * V_13 ++ >> 8 ;
}
F_2 ( V_18 + V_27 , V_24 ) ;
F_2 ( V_18 + V_27 , * V_12 ++ >> 8 ) ;
F_2 ( V_18 + V_27 , V_25 ) ;
}
return;
}
for ( V_14 = 0 ; V_14 < V_26 ; V_14 ++ ) {
F_2 ( V_18 + V_27 , * V_11 ++ >> 8 ) ;
F_2 ( V_18 + V_27 , * V_12 ++ >> 8 ) ;
F_2 ( V_18 + V_27 , * V_13 ++ >> 8 ) ;
}
}
static inline void F_3 ( struct V_5 * V_6 )
{
unsigned long V_28 = V_29 + V_30 / 10 ;
unsigned int V_31 = 0 ;
do {
V_31 = F_4 ( V_32 ) ;
} while ( ( V_31 & 0x08 ) && F_5 ( V_29 , V_28 ) );
V_28 = V_29 + V_30 / 10 ;
V_31 = 0 ;
do {
V_31 = F_4 ( V_32 ) ;
} while ( ! ( V_31 & 0x08 ) && F_5 ( V_29 , V_28 ) );
}
static inline void F_6 ( struct V_5 * V_6 )
{
unsigned long V_28 = V_29 + V_30 ;
unsigned int V_31 = 0 ;
do {
V_31 = F_7 ( V_32 + 2 ) ;
} while ( ( V_31 & 0x01 ) && F_5 ( V_29 , V_28 ) );
}
static int F_8 ( struct V_5 * V_6 , long clock )
{
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 , V_37 , V_38 ;
unsigned int V_39 , V_40 , V_41 ;
unsigned int V_42 , V_43 , V_44 ;
unsigned int V_45 ;
unsigned int V_46 [ V_47 ] = { 16 , 14 , 12 , 10 , 8 , 6 , 4 , 2 , 1 } ;
unsigned int V_48 ;
unsigned int V_14 ;
if ( V_6 -> V_49 <= 0x03 ) {
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
} else {
V_43 = V_44 = V_42 = 0 ;
V_33 = 1600000 ;
V_34 = 800000 ;
V_35 = 25000 ;
if ( clock < 25000 )
clock = 25000 ;
clock = clock * 2 ;
V_36 = 0xFFFFFFFF ;
V_38 = clock * 5 / 1000 ;
for ( V_14 = 0 ; V_14 < V_47 ; V_14 ++ ) {
V_39 = V_46 [ V_14 ] ;
if ( ( clock * V_39 ) > V_33 )
continue;
if ( ( clock * V_39 ) < V_34 )
continue;
for ( V_41 = 50 ; V_41 <= 256 ; V_41 ++ ) {
for ( V_40 = 1 ; V_40 <= 32 ; V_40 ++ ) {
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
V_48 = V_35 * ( V_44 + 1 ) / ( V_43 + 1 ) ;
V_48 = ( V_48 - 800000 ) / 50000 ;
if ( V_48 > 15 )
V_48 = 15 ;
V_42 |= ( V_48 << 4 ) ;
V_43 |= 0x80 ;
clock = clock / 2 ;
}
if ( V_36 > V_38 ) {
F_9 ( L_1 ) ;
return 1 ;
}
F_10 ( V_50 , V_43 ) ;
F_10 ( V_51 , V_44 ) ;
F_10 ( V_52 , V_42 ) ;
if ( V_6 -> V_49 >= 0x04 ) {
F_10 ( 0x1a , 0x09 ) ;
F_11 ( 20 ) ;
F_10 ( 0x1a , 0x01 ) ;
}
return 0 ;
}
static int F_12 ( struct V_5 * V_6 , long clock )
{
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 , V_37 ;
unsigned int V_39 , V_40 , V_41 , V_53 ;
unsigned int V_42 , V_43 , V_44 ;
unsigned int V_45 ;
int V_14 , V_54 , V_55 , V_56 ;
bool V_57 = false ;
T_2 V_58 ;
V_43 = V_44 = V_42 = 0 ;
V_36 = 0xffffffff ;
if ( V_6 -> type == V_59 ) {
V_33 = 800000 ;
V_34 = 400000 ;
V_35 = 25000 ;
for ( V_39 = 1 ; V_39 < 8 ; V_39 ++ ) {
for ( V_53 = 1 ; V_53 < 8 ; V_53 ++ ) {
if ( V_39 < V_53 )
continue;
if ( ( clock * V_39 * V_53 ) > V_33 )
continue;
if ( ( clock * V_39 * V_53 ) < V_34 )
continue;
for ( V_40 = 1 ; V_40 < 26 ; V_40 ++ ) {
for ( V_41 = 32 ; V_41 < 2048 ; V_41 ++ ) {
V_45 = ( V_35 * V_41 ) /
( V_40 * V_39 * V_53 ) ;
if ( V_45 > clock )
V_37 = V_45 - clock ;
else
V_37 = clock - V_45 ;
if ( V_37 < V_36 ) {
V_36 = V_37 ;
V_43 = ( ( V_41 & 0x100 ) >> 1 ) |
( V_40 ) ;
V_44 = ( V_41 & 0xFF ) ;
V_42 = ( ( V_41 & 0x600 ) >> 3 ) |
( V_53 << 3 ) |
( V_39 ) ;
}
}
}
}
}
} else {
V_33 = 550000 ;
V_34 = 150000 ;
V_35 = 48000 ;
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
V_43 = ( V_40 - 1 ) |
( ( V_44 >> 1 ) & 0x80 ) ;
V_42 = V_39 - 1 ;
}
}
}
}
}
for ( V_14 = 0 ; V_14 <= 32 && V_57 == false ; V_14 ++ ) {
if ( V_14 > 0 ) {
F_2 ( V_60 , 0x1e ) ;
V_58 = F_7 ( V_61 ) ;
if ( V_58 < 0xff )
F_2 ( V_61 , V_58 + 1 ) ;
}
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= V_64 ;
F_2 ( V_63 , V_58 ) ;
F_2 ( V_18 , V_65 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= V_66 ;
F_2 ( V_63 , V_58 ) ;
V_58 = F_7 ( V_67 ) ;
V_58 |= 0x3 << 2 ;
F_2 ( V_68 , V_58 ) ;
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= V_69 | 0x80 ;
F_2 ( V_63 , V_58 ) ;
F_13 ( 500 ) ;
F_2 ( V_18 , V_70 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ 0x04 ;
F_2 ( V_63 , V_58 ) ;
F_13 ( 50 ) ;
F_10 ( V_71 , V_44 ) ;
F_10 ( V_72 , V_43 ) ;
F_10 ( V_73 , V_42 ) ;
F_13 ( 50 ) ;
F_2 ( V_18 , V_70 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= 0x04 ;
F_10 ( V_70 , V_58 ) ;
F_13 ( 500 ) ;
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ V_74 ;
V_58 |= V_75 ;
F_2 ( V_63 , V_58 ) ;
F_2 ( V_18 , V_65 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ V_76 ;
V_58 |= V_77 ;
F_2 ( V_63 , V_58 ) ;
F_2 ( V_78 , 1 ) ;
V_58 = F_7 ( V_79 ) ;
V_58 &= ~ 0x8 ;
F_2 ( V_79 , V_58 ) ;
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ V_64 ;
F_2 ( V_63 , V_58 ) ;
V_56 = F_7 ( V_80 ) ;
for ( V_54 = 0 ; V_54 < 30 && V_57 == false ; V_54 ++ ) {
V_55 = F_7 ( V_80 ) ;
if ( V_55 < V_56 )
V_56 = 0 ;
if ( ( V_55 - V_56 ) > 2 )
V_57 = true ;
else
F_13 ( 5 ) ;
}
}
F_2 ( V_18 , V_65 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ V_66 ;
F_10 ( V_65 , V_58 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 , long clock )
{
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 , V_37 ;
unsigned int V_39 , V_40 , V_41 ;
unsigned int V_42 , V_43 , V_44 ;
unsigned int V_45 ;
T_2 V_58 ;
V_43 = V_44 = V_42 = 0 ;
V_33 = 550000 ;
V_34 = 150000 ;
V_35 = 50000 ;
V_36 = 0xffffffff ;
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
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= V_64 ;
F_2 ( V_63 , V_58 ) ;
V_58 = F_7 ( V_67 ) ;
V_58 |= 0x3 << 2 ;
F_2 ( V_68 , V_58 ) ;
F_2 ( V_18 , V_81 ) ;
V_58 = F_7 ( V_63 ) ;
F_2 ( V_63 , V_58 & ~ 0x40 ) ;
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= V_69 ;
F_2 ( V_63 , V_58 ) ;
F_10 ( V_82 , V_43 ) ;
F_10 ( V_83 , V_44 ) ;
F_10 ( V_84 , V_42 ) ;
F_13 ( 50 ) ;
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ V_69 ;
F_2 ( V_63 , V_58 ) ;
F_13 ( 500 ) ;
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ V_74 ;
V_58 |= V_75 ;
F_2 ( V_63 , V_58 ) ;
F_2 ( V_18 , V_81 ) ;
V_58 = F_7 ( V_63 ) ;
F_2 ( V_63 , V_58 | 0x40 ) ;
V_58 = F_7 ( V_67 ) ;
V_58 |= ( 0x3 << 2 ) ;
F_2 ( V_68 , V_58 ) ;
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ V_64 ;
F_2 ( V_63 , V_58 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 , long clock )
{
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 , V_37 ;
unsigned int V_39 , V_40 , V_41 ;
unsigned int V_42 , V_43 , V_44 ;
unsigned int V_45 ;
int V_14 , V_54 , V_55 , V_56 ;
T_2 V_58 ;
bool V_57 = false ;
V_43 = V_44 = V_42 = 0 ;
if ( V_6 -> type == V_85 ) {
V_33 = 3000000 ;
V_34 = 1500000 ;
V_35 = 25000 ;
V_36 = 0xffffffff ;
V_39 = 0 ;
for ( V_40 = 150 ; V_40 >= 6 ; V_40 -- ) {
if ( clock * V_40 > V_33 )
continue;
if ( clock * V_40 < V_34 )
continue;
for ( V_41 = 120 ; V_41 >= 60 ; V_41 -- ) {
V_45 = ( V_35 * V_41 ) / V_40 ;
if ( V_45 > clock )
V_37 = V_45 - clock ;
else
V_37 = clock - V_45 ;
if ( V_37 < V_36 ) {
V_36 = V_37 ;
V_44 = V_41 ;
V_43 = V_40 ;
V_42 = V_39 ;
}
if ( V_36 == 0 )
break;
}
if ( V_36 == 0 )
break;
}
} else {
V_33 = 800000 ;
V_34 = 400000 ;
V_35 = 33333 ;
V_36 = 0xffffffff ;
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
}
for ( V_14 = 0 ; V_14 <= 32 && V_57 == false ; V_14 ++ ) {
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= V_64 ;
F_2 ( V_63 , V_58 ) ;
V_58 = F_7 ( V_67 ) ;
V_58 |= 0x3 << 2 ;
F_2 ( V_68 , V_58 ) ;
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= V_69 ;
F_2 ( V_63 , V_58 ) ;
F_13 ( 500 ) ;
F_10 ( V_86 , V_43 ) ;
F_10 ( V_87 , V_44 ) ;
F_10 ( V_88 , V_42 ) ;
F_13 ( 500 ) ;
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ V_74 ;
V_58 |= V_75 ;
F_2 ( V_63 , V_58 ) ;
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ V_64 ;
V_58 &= ~ V_69 ;
F_2 ( V_63 , V_58 ) ;
V_56 = F_7 ( V_80 ) ;
for ( V_54 = 0 ; V_54 < 30 && V_57 == false ; V_54 ++ ) {
V_55 = F_7 ( V_80 ) ;
if ( V_55 < V_56 )
V_56 = 0 ;
if ( ( V_55 - V_56 ) > 2 )
V_57 = true ;
else
F_13 ( 5 ) ;
}
}
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , long clock )
{
unsigned int V_33 , V_34 , V_35 ;
unsigned int V_36 , V_37 ;
int V_89 , V_41 , V_40 , V_90 ;
unsigned int V_42 , V_43 , V_44 ;
unsigned int V_45 , V_91 ;
int V_58 ;
const unsigned int V_92 [] = { 1 , 2 , 4 , 8 } ;
V_43 = V_44 = V_42 = 0 ;
V_33 = 1488000 ;
V_34 = 1056000 ;
V_35 = 48000 ;
V_36 = 0xffffffff ;
for ( V_89 = 0 ; V_89 < 4 ; V_89 ++ ) {
if ( V_36 == 0 )
break;
for ( V_41 = 5 ; V_41 < 129 ; V_41 ++ ) {
if ( V_36 == 0 )
break;
for ( V_40 = 3 ; V_40 >= 0 ; V_40 -- ) {
if ( V_36 == 0 )
break;
for ( V_90 = 5 ; V_90 < 33 ; V_90 ++ ) {
V_91 = V_35 * ( V_41 + 1 ) /
( V_89 + 1 ) ;
if ( V_91 < V_34 )
continue;
if ( V_91 > V_33 )
continue;
V_45 = V_91 / ( V_92 [ V_40 ] * ( V_90 + 1 ) ) ;
if ( V_45 > clock )
V_37 = V_45 - clock ;
else
V_37 = clock - V_45 ;
if ( V_37 < V_36 ) {
V_36 = V_37 ;
V_43 = V_40 | ( V_90 << 3 ) ;
V_44 = V_41 ;
V_42 = V_89 | ( V_89 << 3 ) ;
}
}
}
}
}
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= V_64 ;
F_2 ( V_63 , V_58 ) ;
F_2 ( V_18 , V_65 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= V_66 ;
F_2 ( V_63 , V_58 ) ;
V_58 = F_7 ( V_67 ) ;
V_58 |= ( 0x3 << 2 ) | 0xc0 ;
F_2 ( V_68 , V_58 ) ;
F_2 ( V_18 , V_62 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ V_64 ;
V_58 |= V_69 ;
F_2 ( V_63 , V_58 ) ;
F_13 ( 500 ) ;
F_10 ( V_93 , V_44 ) ;
F_10 ( V_94 , V_43 ) ;
F_10 ( V_95 , V_42 ) ;
F_13 ( 50 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 , long clock )
{
switch( V_6 -> type ) {
case V_96 :
case V_97 :
return F_8 ( V_6 , clock ) ;
break;
case V_98 :
case V_59 :
return F_12 ( V_6 , clock ) ;
break;
case V_99 :
return F_14 ( V_6 , clock ) ;
break;
case V_100 :
case V_85 :
return F_15 ( V_6 , clock ) ;
break;
case V_101 :
return F_16 ( V_6 , clock ) ;
break;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
T_2 V_58 ;
int V_102 ;
F_2 ( V_18 , V_103 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= 0x10 ;
F_10 ( V_103 , V_58 ) ;
F_2 ( V_18 , V_104 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= 0x10 ;
F_10 ( V_104 , V_58 ) ;
F_2 ( V_18 , V_105 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= 0x80 ;
F_10 ( V_105 , V_58 ) ;
V_102 = 300 ;
while ( ! ( V_58 & 0x1 ) && V_102 ) {
F_2 ( V_18 , V_105 ) ;
V_58 = F_7 ( V_63 ) ;
F_13 ( 1000 ) ;
V_102 -- ;
}
if ( V_102 ) {
V_102 = 300 ;
while ( ( V_58 & 0x2 ) && V_102 ) {
F_2 ( V_18 , V_105 ) ;
V_58 = F_7 ( V_63 ) ;
F_13 ( 1000 ) ;
V_102 -- ;
}
}
}
static void F_19 ( struct V_1 * V_2 )
{
T_2 V_58 ;
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
F_2 ( V_106 , 1 ) ;
V_58 = F_7 ( V_107 ) ;
F_2 ( V_107 , V_58 | 0x88 ) ;
F_2 ( V_18 , V_108 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 |= 0x8 ;
F_2 ( V_63 , V_58 ) ;
F_13 ( 10 ) ;
V_58 &= ~ 0x08 ;
F_2 ( V_18 , V_108 ) ;
F_2 ( V_63 , V_58 ) ;
F_2 ( V_18 , V_105 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ 0x80 ;
F_2 ( V_63 , V_58 ) ;
F_2 ( V_18 , V_104 ) ;
V_58 = F_7 ( V_63 ) ;
V_58 &= ~ 0x10 ;
F_10 ( V_104 , V_58 ) ;
}
static void F_20 ( struct V_1 * V_2 , unsigned V_109 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
T_3 V_110 ;
int V_111 ;
T_2 V_112 ;
while ( F_7 ( 0x1fda ) & 0x08 ) ;
while ( ! ( F_7 ( 0x1fda ) & 0x08 ) ) ;
V_111 = F_7 ( V_80 ) + 2 ;
while ( F_7 ( V_80 ) < V_111 ) ;
F_2 ( V_106 , 0 ) ;
V_112 = F_7 ( V_107 ) ;
V_112 &= 0xB0 ;
V_110 = V_109 / 8 ;
F_21 ( V_110 > 0x1fffff ) ;
V_112 |= ( ! ! ( V_110 & ( 1 << 20 ) ) ) << 6 ;
F_22 ( 0x0d , ( T_2 ) ( V_110 & 0xff ) ) ;
F_22 ( 0x0c , ( T_2 ) ( V_110 >> 8 ) & 0xff ) ;
F_23 ( 0x0 , ( ( T_2 ) ( V_110 >> 16 ) & 0xf ) | V_112 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
int V_113 , int V_114 , int V_115 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
int V_122 ;
T_4 V_123 ;
if ( ! V_115 && V_9 ) {
V_119 = F_25 ( V_9 ) ;
V_117 = V_119 -> V_117 ;
V_121 = F_26 ( V_117 ) ;
V_122 = F_27 ( V_121 , false ) ;
if ( V_122 )
return V_122 ;
F_28 ( V_121 ) ;
F_29 ( V_121 ) ;
}
V_119 = F_25 ( V_2 -> V_10 -> V_9 ) ;
V_117 = V_119 -> V_117 ;
V_121 = F_26 ( V_117 ) ;
V_122 = F_27 ( V_121 , false ) ;
if ( V_122 )
return V_122 ;
V_122 = F_30 ( V_121 , V_124 , & V_123 ) ;
if ( V_122 ) {
F_29 ( V_121 ) ;
return V_122 ;
}
if ( & V_6 -> V_125 -> V_126 == V_119 ) {
V_122 = F_31 ( & V_121 -> V_121 , 0 , V_121 -> V_121 . V_127 , & V_121 -> V_128 ) ;
if ( V_122 )
F_32 ( L_2 ) ;
}
F_29 ( V_121 ) ;
F_20 ( V_2 , ( T_3 ) V_123 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_113 , int V_114 ,
struct V_8 * V_129 )
{
return F_24 ( V_2 , V_129 , V_113 , V_114 , 0 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_130 * V_131 ,
struct V_130 * V_132 ,
int V_113 , int V_114 , struct V_8 * V_129 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 = V_2 -> V_10 -> V_9 ;
int V_133 , V_134 , V_135 , V_136 ;
int V_137 , V_138 , V_139 , V_140 ;
int V_141 ;
int V_142 = 0 , V_143 = 0 ;
int V_14 ;
unsigned char V_144 = 0 ;
unsigned char V_145 [ 6 ] ;
T_2 V_146 ;
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
V_146 = V_6 -> V_148 [ V_9 -> V_20 -> V_21 [ 0 ] - 1 ] ;
switch ( V_6 -> type ) {
case V_96 :
case V_97 :
V_147 [ V_70 ] = 0x03 ;
V_147 [ V_62 ] = V_75 ;
V_147 [ V_149 ] = V_150 |
V_151 |
V_152 ;
if ( V_6 -> V_153 )
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
switch ( V_9 -> V_20 -> V_21 [ 0 ] * 8 ) {
case 8 :
V_147 [ V_154 ] = V_155 ;
break;
case 16 :
if ( V_9 -> V_20 -> V_23 == 15 )
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
for ( V_14 = 0 ; V_14 < sizeof( V_147 ) ; V_14 ++ ) {
if ( ( V_14 <= 0x17 ) ||
( V_14 == 0x1b ) ||
( V_14 == 0x1c ) ||
( ( V_14 >= 0x1f ) && ( V_14 <= 0x29 ) ) ||
( ( V_14 >= 0x30 ) && ( V_14 <= 0x37 ) ) )
continue;
if ( F_35 ( V_6 ) &&
( ( V_14 == 0x2c ) || ( V_14 == 0x2d ) || ( V_14 == 0x2e ) ) )
continue;
if ( ( V_6 -> type == V_99 ||
V_6 -> type == V_98 ||
V_6 -> type == V_100 ||
V_6 -> type == V_59 ||
V_6 -> type == V_85 ) &&
( V_14 >= 0x44 ) && ( V_14 <= 0x4e ) )
continue;
F_10 ( V_14 , V_147 [ V_14 ] ) ;
}
if ( V_6 -> type == V_101 )
F_10 ( 0x90 , 0 ) ;
if ( V_142 )
F_36 ( V_4 -> V_163 , V_164 , V_142 ) ;
if ( V_143 )
F_36 ( V_4 -> V_163 , V_165 , V_143 ) ;
F_37 ( 2 , 0xf ) ;
F_37 ( 3 , 0 ) ;
F_37 ( 4 , 0xe ) ;
V_141 = V_9 -> V_166 [ 0 ] / V_9 -> V_20 -> V_21 [ 0 ] ;
if ( V_9 -> V_20 -> V_21 [ 0 ] * 8 == 24 )
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
F_38 ( 0 , 0 ) ;
F_38 ( 1 , 0 ) ;
F_38 ( 2 , 0 ) ;
F_38 ( 3 , 0 ) ;
F_38 ( 4 , 0 ) ;
F_38 ( 5 , 0x40 ) ;
F_38 ( 6 , 0x5 ) ;
F_38 ( 7 , 0xf ) ;
F_38 ( 8 , 0xf ) ;
F_22 ( 0 , V_136 - 4 ) ;
F_22 ( 1 , V_133 ) ;
F_22 ( 2 , V_133 ) ;
F_22 ( 3 , ( V_136 & 0x1F ) | 0x80 ) ;
F_22 ( 4 , V_134 ) ;
F_22 ( 5 , ( ( V_136 & 0x20 ) << 2 ) | ( V_135 & 0x1F ) ) ;
F_22 ( 6 , V_140 & 0xFF ) ;
F_22 ( 7 , ( ( V_140 & 0x100 ) >> 8 ) |
( ( V_137 & 0x100 ) >> 7 ) |
( ( V_138 & 0x100 ) >> 6 ) |
( ( V_137 & 0x100 ) >> 5 ) |
( ( V_137 & 0x100 ) >> 4 ) |
( ( V_140 & 0x200 ) >> 4 ) |
( ( V_137 & 0x200 ) >> 3 ) |
( ( V_138 & 0x200 ) >> 2 ) ) ;
F_22 ( 9 , ( ( V_137 & 0x200 ) >> 4 ) |
( ( V_137 & 0x200 ) >> 3 ) ) ;
F_22 ( 10 , 0 ) ;
F_22 ( 11 , 0 ) ;
F_22 ( 12 , 0 ) ;
F_22 ( 13 , 0 ) ;
F_22 ( 14 , 0 ) ;
F_22 ( 15 , 0 ) ;
F_22 ( 16 , V_138 & 0xFF ) ;
F_22 ( 17 , ( V_139 & 0x0F ) | 0x20 ) ;
F_22 ( 18 , V_137 & 0xFF ) ;
F_22 ( 19 , V_141 & 0xFF ) ;
F_22 ( 20 , 0 ) ;
F_22 ( 21 , V_137 & 0xFF ) ;
F_22 ( 22 , ( V_140 + 1 ) & 0xFF ) ;
F_22 ( 23 , 0xc3 ) ;
F_22 ( 24 , V_137 & 0xFF ) ;
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
if ( V_9 -> V_20 -> V_21 [ 0 ] * 8 == 24 )
V_145 [ 3 ] = ( ( ( 1 << V_146 ) * 3 ) - 1 ) | 0x80 ;
else
V_145 [ 3 ] = ( ( 1 << V_146 ) - 1 ) | 0x80 ;
V_145 [ 4 ] = 0 ;
if ( V_6 -> type == V_98 || V_6 -> type == V_59 )
V_145 [ 1 ] |= 0x88 ;
V_144 = 0x2d ;
F_2 ( V_171 , V_144 ) ;
F_17 ( V_6 , V_131 -> clock ) ;
for ( V_14 = 0 ; V_14 < 6 ; V_14 ++ ) {
F_23 ( V_14 , V_145 [ V_14 ] ) ;
}
if ( V_6 -> type == V_101 )
F_23 ( 0x24 , 0x5 ) ;
if ( V_6 -> type == V_59 )
F_23 ( 0x34 , 0x5 ) ;
if ( V_6 -> type == V_99 ) {
F_23 ( 6 , 0 ) ;
}
F_23 ( 0 , V_145 [ 0 ] ) ;
V_144 = 0x2d ;
F_2 ( V_171 , V_144 ) ;
if ( V_132 )
memcpy ( & V_6 -> V_131 , V_131 , sizeof( struct V_130 ) ) ;
F_24 ( V_2 , V_129 , V_113 , V_114 , 0 ) ;
if ( V_6 -> type == V_101 ) {
T_3 V_172 = F_4 ( V_173 ) ;
T_2 V_174 ;
F_2 ( V_78 , 0x01 ) ;
V_174 = F_7 ( V_79 ) | 0x20 ;
F_2 ( V_79 , V_174 ) ;
F_39 ( V_173 , V_172 | 0x00200000 ) ;
F_13 ( 1000 ) ;
F_39 ( V_173 , V_172 & ~ 0x00200000 ) ;
F_2 ( V_79 , V_174 & ~ 0x20 ) ;
}
if ( F_35 ( V_6 ) ) {
if ( V_6 -> V_49 >= 0x04 ) {
F_2 ( V_106 , 0x06 ) ;
F_2 ( V_107 , 0 ) ;
} else if ( V_6 -> V_49 >= 0x02 ) {
T_2 V_175 ;
T_3 V_176 ;
T_3 V_177 ;
if ( V_9 -> V_20 -> V_21 [ 0 ] * 8 > 16 )
V_176 = 32 ;
else if ( V_9 -> V_20 -> V_21 [ 0 ] * 8 > 8 )
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
F_2 ( V_106 , 0x06 ) ;
F_2 ( V_107 , V_175 ) ;
} else {
F_2 ( V_106 , 0x06 ) ;
if ( V_6 -> V_49 >= 0x01 )
F_2 ( V_107 , 0x03 ) ;
else
F_2 ( V_107 , 0x04 ) ;
}
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , int V_131 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_174 = 0 , V_178 = 0 ;
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
F_2 ( V_78 , 0x01 ) ;
V_174 |= F_7 ( V_79 ) & ~ 0x20 ;
F_3 ( V_6 ) ;
F_6 ( V_6 ) ;
F_2 ( V_79 , V_174 ) ;
F_11 ( 20 ) ;
F_2 ( V_106 , 0x01 ) ;
V_178 |= F_7 ( V_107 ) & ~ 0x30 ;
F_2 ( V_107 , V_178 ) ;
#if 0
if (mode == DRM_MODE_DPMS_ON && mdev->suspended == true) {
mga_resume(crtc);
drm_helper_resume_force_mode(dev);
}
#endif
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_58 ;
F_2 ( V_60 , 0x11 ) ;
V_58 = F_7 ( V_61 ) ;
F_22 ( 0x11 , V_58 | 0x80 ) ;
if ( V_6 -> type == V_96 || V_6 -> type == V_97 ) {
F_37 ( 0 , 1 ) ;
F_11 ( 50 ) ;
F_37 ( 1 , 0x20 ) ;
F_11 ( 20 ) ;
} else {
F_2 ( V_78 , 0x1 ) ;
V_58 = F_7 ( V_79 ) ;
F_37 ( 0 , 1 ) ;
F_37 ( 1 , V_58 | 0x20 ) ;
}
if ( V_6 -> type == V_98 || V_6 -> type == V_59 )
F_18 ( V_2 ) ;
F_22 ( 17 , 0 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_183 * V_184 = V_2 -> V_185 ;
T_2 V_58 ;
if ( V_6 -> type == V_98 || V_6 -> type == V_59 )
F_19 ( V_2 ) ;
if ( V_6 -> type == V_96 || V_6 -> type == V_97 ) {
F_11 ( 50 ) ;
F_37 ( 1 , 0x0 ) ;
F_11 ( 20 ) ;
F_37 ( 0 , 0x3 ) ;
} else {
F_2 ( V_78 , 0x1 ) ;
V_58 = F_7 ( V_79 ) ;
V_58 &= ~ 0x20 ;
F_37 ( 0x1 , V_58 ) ;
F_37 ( 0 , 3 ) ;
}
V_184 -> V_186 ( V_2 , V_179 ) ;
}
static int F_43 ( struct V_1 * V_2 , T_1 * V_187 , T_1 * V_188 ,
T_1 * V_189 , T_5 V_190 ,
struct V_191 * V_192 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_193 * V_193 = F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_193 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_122 ;
F_49 ( L_3 ) ;
F_40 ( V_2 , V_182 ) ;
if ( V_2 -> V_10 -> V_9 ) {
struct V_118 * V_119 = F_25 ( V_2 -> V_10 -> V_9 ) ;
struct V_116 * V_117 = V_119 -> V_117 ;
struct V_120 * V_121 = F_26 ( V_117 ) ;
V_122 = F_27 ( V_121 , false ) ;
if ( V_122 )
return;
F_28 ( V_121 ) ;
F_29 ( V_121 ) ;
}
V_2 -> V_10 -> V_9 = NULL ;
}
static void F_50 ( struct V_5 * V_6 )
{
struct V_193 * V_193 ;
V_193 = F_51 ( sizeof( struct V_193 ) +
( V_194 * sizeof( struct V_195 * ) ) ,
V_196 ) ;
if ( V_193 == NULL )
return;
F_52 ( V_6 -> V_4 , & V_193 -> V_197 , & V_198 ) ;
F_53 ( & V_193 -> V_197 , V_26 ) ;
V_6 -> V_199 . V_2 = V_193 ;
F_54 ( & V_193 -> V_197 , & V_200 ) ;
}
static void F_55 ( struct V_201 * V_202 ,
struct V_130 * V_131 ,
struct V_130 * V_132 )
{
}
static void F_56 ( struct V_201 * V_202 , int V_203 )
{
return;
}
static void F_57 ( struct V_201 * V_202 )
{
}
static void F_58 ( struct V_201 * V_202 )
{
}
static void F_59 ( struct V_201 * V_202 )
{
struct V_204 * V_204 = F_60 ( V_202 ) ;
F_61 ( V_202 ) ;
F_47 ( V_204 ) ;
}
static struct V_201 * F_62 ( struct V_3 * V_4 )
{
struct V_201 * V_202 ;
struct V_204 * V_204 ;
V_204 = F_51 ( sizeof( struct V_204 ) , V_196 ) ;
if ( ! V_204 )
return NULL ;
V_202 = & V_204 -> V_197 ;
V_202 -> V_205 = 0x1 ;
F_63 ( V_4 , V_202 , & V_206 ,
V_207 , NULL ) ;
F_64 ( V_202 , & V_208 ) ;
return V_202 ;
}
static int F_65 ( struct V_195 * V_209 )
{
struct V_210 * V_210 = F_66 ( V_209 ) ;
struct V_211 * V_211 ;
int V_122 = 0 ;
V_211 = F_67 ( V_209 , & V_210 -> V_212 -> V_213 ) ;
if ( V_211 ) {
F_68 ( V_209 , V_211 ) ;
V_122 = F_69 ( V_209 , V_211 ) ;
F_47 ( V_211 ) ;
}
return V_122 ;
}
static T_5 F_70 ( struct V_130 * V_131 ,
int V_214 )
{
T_5 V_215 , V_216 ;
T_6 V_217 , V_218 , V_219 ;
T_6 V_220 = ( V_214 + 7 ) / 8 ;
V_216 = 1024 ;
if ( ! V_131 -> V_136 || ! V_131 -> V_140 || ! V_131 -> clock )
return 0 ;
V_217 = V_131 -> V_133 * V_131 -> V_137 ;
V_215 = V_131 -> V_136 * V_131 -> V_140 ;
V_218 = V_217 * V_131 -> clock * 1000 ;
F_71 ( V_218 , V_215 ) ;
V_219 = V_218 * V_220 * 100 ;
F_71 ( V_219 , V_216 ) ;
return ( T_5 ) ( V_219 ) ;
}
static int F_72 ( struct V_195 * V_209 ,
struct V_130 * V_131 )
{
struct V_3 * V_4 = V_209 -> V_4 ;
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_7 ;
int V_176 = 32 ;
if ( F_35 ( V_6 ) ) {
if ( V_6 -> V_49 == 0x01 ) {
if ( V_131 -> V_133 > 1600 )
return V_221 ;
if ( V_131 -> V_137 > 1200 )
return V_222 ;
if ( F_70 ( V_131 , V_176 )
> ( 24400 * 1024 ) )
return V_223 ;
} else if ( V_6 -> V_49 == 0x02 ) {
if ( V_131 -> V_133 > 1920 )
return V_221 ;
if ( V_131 -> V_137 > 1200 )
return V_222 ;
if ( F_70 ( V_131 , V_176 )
> ( 30100 * 1024 ) )
return V_223 ;
} else {
if ( F_70 ( V_131 , V_176 )
> ( 55000 * 1024 ) )
return V_223 ;
}
} else if ( V_6 -> type == V_98 ) {
if ( V_131 -> V_133 > 1280 )
return V_221 ;
if ( V_131 -> V_137 > 1024 )
return V_222 ;
if ( F_70 ( V_131 ,
V_176 > ( 31877 * 1024 ) ) )
return V_223 ;
} else if ( V_6 -> type == V_99 &&
( F_70 ( V_131 , V_176 )
> ( 32700 * 1024 ) ) ) {
return V_223 ;
} else if ( V_6 -> type == V_100 &&
( F_70 ( V_131 , V_176 )
> ( 37500 * 1024 ) ) ) {
return V_223 ;
} else if ( V_6 -> type == V_101 &&
( F_70 ( V_131 ,
V_176 ) > ( 55000 * 1024 ) ) ) {
return V_223 ;
}
if ( ( V_131 -> V_133 % 8 ) != 0 || ( V_131 -> V_167 % 8 ) != 0 ||
( V_131 -> V_168 % 8 ) != 0 || ( V_131 -> V_136 % 8 ) != 0 ) {
return V_224 ;
}
if ( V_131 -> V_225 > 2048 || V_131 -> V_226 > 4096 ||
V_131 -> V_227 > 4096 || V_131 -> V_228 > 4096 ||
V_131 -> V_229 > 2048 || V_131 -> V_230 > 4096 ||
V_131 -> V_231 > 4096 || V_131 -> V_232 > 4096 ) {
return V_233 ;
}
if ( V_209 -> V_234 . V_235 ) {
if ( V_209 -> V_234 . V_236 )
V_176 = V_209 -> V_234 . V_176 ;
}
if ( ( V_131 -> V_133 * V_131 -> V_137 * ( V_176 / 8 ) ) > V_6 -> V_237 . V_238 ) {
if ( V_209 -> V_234 . V_235 )
V_209 -> V_234 . V_235 = false ;
return V_233 ;
}
return V_239 ;
}
static struct V_201 * F_73 ( struct V_195
* V_209 )
{
int V_240 = V_209 -> V_241 [ 0 ] ;
if ( V_240 )
return F_74 ( V_209 -> V_4 , V_240 ) ;
return NULL ;
}
static void F_75 ( struct V_195 * V_209 )
{
struct V_210 * V_210 = F_66 ( V_209 ) ;
F_76 ( V_210 -> V_212 ) ;
F_77 ( V_209 ) ;
F_47 ( V_209 ) ;
}
static struct V_195 * F_78 ( struct V_3 * V_4 )
{
struct V_195 * V_209 ;
struct V_210 * V_210 ;
V_210 = F_51 ( sizeof( struct V_210 ) , V_196 ) ;
if ( ! V_210 )
return NULL ;
V_209 = & V_210 -> V_197 ;
F_79 ( V_4 , V_209 ,
& V_242 , V_243 ) ;
F_80 ( V_209 , & V_244 ) ;
F_81 ( V_209 ) ;
V_210 -> V_212 = F_82 ( V_4 ) ;
if ( ! V_210 -> V_212 )
F_32 ( L_4 ) ;
return V_209 ;
}
int F_83 ( struct V_5 * V_6 )
{
struct V_201 * V_202 ;
struct V_195 * V_209 ;
int V_122 ;
V_6 -> V_199 . V_245 = true ;
V_6 -> V_4 -> V_246 . V_247 = V_248 ;
V_6 -> V_4 -> V_246 . V_249 = V_250 ;
V_6 -> V_4 -> V_246 . V_251 = V_6 -> V_237 . V_252 ;
F_50 ( V_6 ) ;
V_202 = F_62 ( V_6 -> V_4 ) ;
if ( ! V_202 ) {
F_32 ( L_5 ) ;
return - 1 ;
}
V_209 = F_78 ( V_6 -> V_4 ) ;
if ( ! V_209 ) {
F_32 ( L_6 ) ;
return - 1 ;
}
F_84 ( V_209 , V_202 ) ;
V_122 = F_85 ( V_6 ) ;
if ( V_122 ) {
F_32 ( L_7 ) ;
return V_122 ;
}
return 0 ;
}
void F_86 ( struct V_5 * V_6 )
{
}
