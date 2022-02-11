void F_1 ( T_1 * V_1 ,
const struct V_2 * V_3 )
{
T_2 V_4 = V_1 -> V_5 . V_6 . V_7 ;
T_2 V_8 = V_1 -> V_5 . V_6 . V_9 ;
V_4 = ( V_4 & ~ V_10 ) |
( ( T_2 ) V_3 -> V_11 & 0x000007ff ) |
( ( ( T_2 ) V_3 -> y1 << 16 ) & 0x07ff0000 ) ;
V_8 = ( V_8 & ~ V_10 ) |
( ( ( T_2 ) V_3 -> V_12 - 1 ) & 0x000007ff ) |
( ( ( ( T_2 ) V_3 -> V_13 - 1 ) << 16 ) & 0x07ff0000 ) ;
if ( V_4 != V_1 -> V_5 . V_6 . V_4 ||
V_8 != V_1 -> V_5 . V_6 . V_8 ) {
V_14 ;
F_2 ( 4 ) ;
F_3 ( V_15 | V_16 ) ;
F_4 ( V_17 , 2 ) ;
F_3 ( V_4 ) ;
F_3 ( V_8 ) ;
V_1 -> V_5 . V_6 . V_4 = V_4 ;
V_1 -> V_5 . V_6 . V_8 = V_8 ;
V_1 -> V_18 = 1 ;
F_5 () ;
}
}
void F_6 ( T_1 * V_1 ,
const struct V_2 * V_3 )
{
T_2 V_19 = V_1 -> V_5 . V_20 . V_21 ;
T_2 V_22 = V_1 -> V_5 . V_20 . V_23 ;
V_19 = ( V_19 & ~ V_24 ) |
( ( T_2 ) V_3 -> V_11 & 0x000007ff ) |
( ( ( T_2 ) V_3 -> y1 << 12 ) & 0x00fff000 ) ;
V_22 = ( V_22 & ~ V_24 ) |
( ( ( T_2 ) V_3 -> V_12 - 1 ) & 0x000007ff ) |
( ( ( ( T_2 ) V_3 -> V_13 - 1 ) << 12 ) & 0x00fff000 ) ;
if ( V_19 != V_1 -> V_5 . V_20 . V_19 ||
V_22 != V_1 -> V_5 . V_20 . V_22 ) {
V_14 ;
F_2 ( 4 ) ;
F_3 ( V_15 | V_16 ) ;
F_4 ( V_25 , 2 ) ;
F_3 ( V_19 ) ;
F_3 ( V_22 ) ;
V_1 -> V_5 . V_20 . V_19 = V_19 ;
V_1 -> V_5 . V_20 . V_22 = V_22 ;
V_1 -> V_18 = 1 ;
F_5 () ;
}
}
static int F_7 ( T_1 * V_1 , int V_26 ,
T_2 V_27 )
{
if ( ( V_27 & 6 ) != 2 ) {
F_8 ( L_1 , V_26 , V_27 ) ;
return - V_28 ;
}
if ( ! ( V_27 & 1 ) ) {
V_27 &= ~ 7 ;
if ( V_27 < V_1 -> V_29 ||
V_27 >= V_1 -> V_29 + V_1 -> V_30 ) {
F_8
( L_2 ,
V_26 , V_27 ) ;
return - V_28 ;
}
} else {
if ( ! V_1 -> V_31 ) {
F_8 ( L_3 ,
V_26 , V_27 ) ;
return - V_28 ;
}
V_27 &= ~ 7 ;
if ( V_27 < V_1 -> V_31 -> V_32 ||
V_27 >= ( V_1 -> V_31 -> V_32 +
V_1 -> V_31 -> V_33 ) ) {
F_8
( L_4 ,
V_26 , V_27 ) ;
return - V_28 ;
}
}
return 0 ;
}
static int F_9 ( T_1 * V_1 ,
unsigned int V_34 , unsigned int V_35 ,
const T_2 * V_36 )
{
if ( V_34 < V_37 ||
V_34 + V_35 - 1 > V_38 ) {
F_8 ( L_5 ,
V_34 , V_34 + V_35 - 1 ) ;
return - V_28 ;
}
F_10 ( V_17 , V_6 . V_7 ,
~ V_10 ) ;
F_10 ( V_39 , V_6 . V_9 ,
~ V_10 ) ;
if ( V_34 <= V_40 &&
V_34 + V_35 > V_37 ) {
F_11 ( V_40 , V_6 . V_41 ) ;
F_11 ( V_42 , V_6 . V_43 ) ;
if ( V_1 -> V_5 . V_6 . V_41 & V_44 )
return F_7 ( V_1 , 0 ,
V_1 -> V_5 . V_6 . V_43 ) ;
}
return 0 ;
}
static int F_12 ( T_1 * V_1 ,
unsigned int V_34 , unsigned int V_35 ,
const T_2 * V_36 )
{
int V_45 = 0 ;
if ( V_34 < V_46 ||
V_34 + V_35 - 1 > V_47 ) {
F_8 ( L_5 ,
V_34 , V_34 + V_35 - 1 ) ;
return - V_28 ;
}
F_10 ( V_25 , V_20 . V_21 ,
~ V_24 ) ;
F_10 ( V_48 , V_20 . V_23 ,
~ V_24 ) ;
if ( V_34 <= V_49 &&
V_34 + V_35 > V_50 ) {
F_11 ( V_49 , V_20 . V_51 ) ;
F_11 ( V_52 , V_20 . V_53 ) ;
F_11 ( V_54 , V_20 . V_55 ) ;
if ( V_1 -> V_5 . V_20 . V_51 & V_56 )
V_45 |= F_7 ( V_1 , 0 ,
V_1 -> V_5 . V_20 . V_53 ) ;
if ( V_1 -> V_5 . V_20 . V_51 & V_57 )
V_45 |= F_7 ( V_1 , 1 ,
V_1 -> V_5 . V_20 . V_55 ) ;
}
return V_45 ;
}
static int F_13 ( T_1 * V_1 ,
const T_3 * V_58 ,
const T_2 * V_36 )
{
unsigned int V_35 = V_58 -> V_5 . V_35 ;
unsigned int V_34 = V_58 -> V_5 . V_34 ;
unsigned int V_59 = 0 ;
unsigned int V_60 ;
int V_45 ;
V_14 ;
if ( ! V_35 )
return 0 ;
if ( F_14 ( V_1 -> V_61 ) ) {
V_45 = F_9 ( V_1 , V_34 , V_35 , V_36 ) ;
if ( V_45 != 0 )
return V_45 ;
if ( V_34 < V_17 ) {
if ( V_34 + V_35 > V_39 + 1 )
V_59 = V_35 - ( V_39 + 1 - V_34 ) ;
if ( V_34 + V_35 > V_17 )
V_35 = V_17 - V_34 ;
} else if ( V_34 <= V_39 ) {
if ( V_34 + V_35 > V_39 + 1 ) {
V_35 -= V_39 + 1 - V_34 ;
V_34 = V_39 + 1 ;
} else
return 0 ;
}
} else {
V_45 = F_12 ( V_1 , V_34 , V_35 , V_36 ) ;
if ( V_45 != 0 )
return V_45 ;
if ( V_34 < V_25 ) {
if ( V_34 + V_35 > V_48 + 1 )
V_59 = V_35 -
( V_48 + 1 - V_34 ) ;
if ( V_34 + V_35 > V_25 )
V_35 = V_25 - V_34 ;
} else if ( V_34 <= V_48 ) {
if ( V_34 + V_35 > V_48 + 1 ) {
V_35 -= V_48 + 1 - V_34 ;
V_34 = V_48 + 1 ;
} else
return 0 ;
}
}
V_60 = V_35 + ( V_35 + 254 ) / 255 + V_59 + ( V_59 + 254 ) / 255 ;
if ( V_58 -> V_5 . V_62 ) {
F_2 ( V_60 + 1 ) ;
F_3 ( V_15 | V_16 ) ;
V_1 -> V_18 = 1 ;
} else {
F_2 ( V_60 ) ;
}
do {
while ( V_35 > 0 ) {
unsigned int V_63 = V_35 < 255 ? V_35 : 255 ;
F_4 ( V_34 , V_63 ) ;
F_15 ( V_36 , V_63 ) ;
V_35 -= V_63 ;
V_34 += V_63 ;
V_36 += V_63 ;
}
V_34 += 2 ;
V_36 += 2 ;
V_35 = V_59 ;
V_59 = 0 ;
} while ( V_35 );
F_5 () ;
return 0 ;
}
static int F_16 ( T_1 * V_1 ,
const T_3 * V_58 ,
const struct V_64 * V_65 )
{
unsigned char V_66 = 0 ;
unsigned int V_67 = V_58 -> V_67 . V_67 ;
unsigned int V_68 = V_58 -> V_67 . V_68 ;
unsigned int V_63 = V_58 -> V_67 . V_35 ;
unsigned int V_34 = V_58 -> V_67 . V_34 ;
unsigned int V_69 ;
V_70 ;
if ( ! V_65 ) {
F_8 ( L_6 ) ;
return - V_28 ;
}
if ( ! V_63 )
return 0 ;
switch ( V_67 ) {
case V_71 :
V_66 = 1 ;
V_67 = V_72 ;
case V_72 :
if ( V_63 % 3 != 0 ) {
F_8 ( L_7 ,
V_63 ) ;
return - V_28 ;
}
break;
case V_73 :
case V_74 :
if ( V_63 < 3 ) {
F_8
( L_8 ,
V_63 ) ;
return - V_28 ;
}
break;
default:
F_8 ( L_9 , V_67 ) ;
return - V_28 ;
}
if ( F_14 ( V_1 -> V_61 ) ) {
if ( V_68 != 0 ) {
F_8 ( L_10 , V_68 ) ;
return - V_28 ;
}
} else {
unsigned int V_33 = 10 - ( V_68 & 1 ) - ( V_68 >> 1 & 1 ) -
( V_68 >> 2 & 1 ) - ( V_68 >> 3 & 1 ) - ( V_68 >> 4 & 1 ) -
( V_68 >> 5 & 1 ) - ( V_68 >> 6 & 1 ) - ( V_68 >> 7 & 1 ) ;
if ( V_68 > V_75 || V_33 != 8 ) {
F_8 ( L_10 , V_68 ) ;
return - V_28 ;
}
if ( V_66 ) {
F_8 ( L_11 ) ;
return - V_28 ;
}
}
if ( V_34 + V_63 > V_65 -> V_76 / 32 ) {
F_8 ( L_12 ,
V_34 , V_34 + V_63 - 1 , V_65 -> V_76 / 32 ) ;
return - V_28 ;
}
F_17 () ;
if ( V_65 -> V_77 != V_1 -> V_5 . V_78 . V_79 ) {
F_18 ( 2 ) ;
F_19 ( V_80 , 1 ) ;
F_20 ( V_65 -> V_77 | V_1 -> V_81 ) ;
V_1 -> V_5 . V_78 . V_79 = V_65 -> V_77 ;
}
if ( F_14 ( V_1 -> V_61 ) && V_1 -> V_18 ) {
F_18 ( 63 ) ;
for ( V_69 = 0 ; V_69 < 63 ; ++ V_69 )
F_20 ( V_15 ) ;
V_1 -> V_18 = 0 ;
}
V_67 <<= 25 ;
while ( V_63 != 0 ) {
unsigned int V_35 = V_63 > 255 ? 255 : V_63 ;
if ( V_66 ) {
int V_66 [ 3 ] = { - 1 , - 1 , - 1 } ;
V_66 [ V_34 % 3 ] = 2 ;
F_18 ( ( V_35 + 1 + 1 ) / 2 ) ;
F_21 ( V_35 , V_67 , V_34 + 2 ) ;
for ( V_69 = V_34 + 1 ; V_69 + 1 < V_34 + V_35 ; V_69 += 2 )
F_20 ( ( V_69 + V_66 [ V_69 % 3 ] ) |
( ( V_69 + 1 +
V_66 [ ( V_69 + 1 ) % 3 ] ) << 16 ) ) ;
if ( V_69 < V_34 + V_35 )
F_20 ( V_69 + V_66 [ V_69 % 3 ] ) ;
} else if ( F_14 ( V_1 -> V_61 ) ) {
F_18 ( ( V_35 + 1 + 1 ) / 2 ) ;
F_21 ( V_35 , V_67 , V_34 ) ;
for ( V_69 = V_34 + 1 ; V_69 + 1 < V_34 + V_35 ; V_69 += 2 )
F_20 ( V_69 | ( ( V_69 + 1 ) << 16 ) ) ;
if ( V_69 < V_34 + V_35 )
F_20 ( V_69 ) ;
} else {
F_18 ( ( V_35 + 2 + 1 ) / 2 ) ;
F_22 ( V_35 , V_67 , V_68 ) ;
for ( V_69 = V_34 ; V_69 + 1 < V_34 + V_35 ; V_69 += 2 )
F_20 ( V_69 | ( ( V_69 + 1 ) << 16 ) ) ;
if ( V_69 < V_34 + V_35 )
F_20 ( V_69 ) ;
}
V_34 += V_35 ;
V_63 -= V_35 ;
V_67 |= V_82 ;
}
return 0 ;
}
static int F_23 ( T_1 * V_1 ,
const T_3 * V_58 ,
const T_2 * V_83 , unsigned int V_84 ,
unsigned int V_85 )
{
unsigned char V_66 = 0 ;
unsigned int V_67 = V_58 -> V_67 . V_67 ;
unsigned int V_68 = V_58 -> V_67 . V_68 ;
unsigned int V_63 = V_58 -> V_67 . V_35 ;
unsigned int V_34 = V_58 -> V_67 . V_34 ;
unsigned int V_86 ;
unsigned int V_69 ;
V_14 ;
if ( ! V_63 )
return 0 ;
switch ( V_67 ) {
case V_71 :
V_66 = 1 ;
V_67 = V_72 ;
case V_72 :
if ( V_63 % 3 != 0 ) {
F_8 ( L_7 ,
V_63 ) ;
return - V_28 ;
}
break;
case V_73 :
case V_74 :
if ( V_63 < 3 ) {
F_8
( L_8 ,
V_63 ) ;
return - V_28 ;
}
break;
default:
F_8 ( L_9 , V_67 ) ;
return - V_28 ;
}
if ( F_14 ( V_1 -> V_61 ) ) {
if ( V_68 > V_87 ) {
F_8 ( L_13 , V_68 ) ;
return - V_28 ;
}
V_86 = 8 ;
} else {
if ( V_68 > V_75 ) {
F_8 ( L_13 , V_68 ) ;
return - V_28 ;
}
V_86 = 10 ;
}
V_86 -= ( V_68 & 1 ) + ( V_68 >> 1 & 1 ) +
( V_68 >> 2 & 1 ) + ( V_68 >> 3 & 1 ) + ( V_68 >> 4 & 1 ) +
( V_68 >> 5 & 1 ) + ( V_68 >> 6 & 1 ) + ( V_68 >> 7 & 1 ) ;
if ( V_86 > V_85 ) {
F_8 ( L_14 ,
V_86 , V_85 ) ;
return - V_28 ;
}
if ( V_34 + V_63 > V_84 / ( V_85 * 4 ) ) {
F_8 ( L_12 ,
V_34 , V_34 + V_63 - 1 , V_84 / ( V_85 * 4 ) ) ;
return - V_28 ;
}
V_67 <<= 25 ;
while ( V_63 != 0 ) {
unsigned int V_35 = V_63 > 255 ? 255 : V_63 ;
if ( V_66 ) {
int V_66 [ 3 ] = { - 1 , - 1 , - 1 } ;
V_66 [ V_34 % 3 ] = 2 ;
F_2 ( V_35 * V_86 + 1 ) ;
F_24 ( V_35 , V_67 , V_68 ) ;
for ( V_69 = V_34 ; V_69 < V_34 + V_35 ; ++ V_69 ) {
unsigned int V_88 = V_69 + V_66 [ V_69 % 3 ] ;
F_15 ( & V_83 [ V_85 * V_88 ] , V_86 ) ;
}
F_5 () ;
} else {
F_2 ( V_35 * V_86 + 1 ) ;
F_24 ( V_35 , V_67 , V_68 ) ;
if ( V_85 == V_86 ) {
F_15 ( & V_83 [ V_85 * V_34 ] ,
V_86 * V_35 ) ;
} else {
for ( V_69 = V_34 ; V_69 < V_34 + V_35 ; ++ V_69 ) {
F_15 ( & V_83 [ V_85 * V_69 ] ,
V_86 ) ;
}
}
F_5 () ;
}
V_34 += V_35 ;
V_63 -= V_35 ;
V_67 |= V_82 ;
}
return 0 ;
}
static int F_25 ( T_1 * V_1 ,
const T_3 * V_58 ,
const T_4 * V_89 ,
const struct V_64 * V_65 )
{
unsigned char V_66 = 0 ;
unsigned int V_67 = V_58 -> V_89 . V_67 ;
unsigned int V_68 = V_58 -> V_89 . V_68 ;
unsigned int V_63 = V_58 -> V_89 . V_35 ;
unsigned int V_69 ;
V_70 ;
if ( ! V_65 ) {
F_8 ( L_6 ) ;
return - V_28 ;
}
if ( ! V_63 )
return 0 ;
switch ( V_67 ) {
case V_71 :
V_66 = 1 ;
V_67 = V_72 ;
case V_72 :
if ( V_63 % 3 != 0 ) {
F_8 ( L_15 , V_63 ) ;
return - V_28 ;
}
break;
case V_73 :
case V_74 :
if ( V_63 < 3 ) {
F_8
( L_16 , V_63 ) ;
return - V_28 ;
}
break;
default:
F_8 ( L_9 , V_67 ) ;
return - V_28 ;
}
if ( F_14 ( V_1 -> V_61 ) ) {
if ( V_68 != 0 ) {
F_8 ( L_10 , V_68 ) ;
return - V_28 ;
}
} else {
unsigned int V_33 = 10 - ( V_68 & 1 ) - ( V_68 >> 1 & 1 ) -
( V_68 >> 2 & 1 ) - ( V_68 >> 3 & 1 ) - ( V_68 >> 4 & 1 ) -
( V_68 >> 5 & 1 ) - ( V_68 >> 6 & 1 ) - ( V_68 >> 7 & 1 ) ;
if ( V_68 > V_75 || V_33 != 8 ) {
F_8 ( L_10 , V_68 ) ;
return - V_28 ;
}
if ( V_66 ) {
F_8 ( L_11 ) ;
return - V_28 ;
}
}
F_17 () ;
if ( V_65 -> V_77 != V_1 -> V_5 . V_78 . V_79 ) {
F_18 ( 2 ) ;
F_19 ( V_80 , 1 ) ;
F_20 ( V_65 -> V_77 | V_1 -> V_81 ) ;
V_1 -> V_5 . V_78 . V_79 = V_65 -> V_77 ;
}
if ( F_14 ( V_1 -> V_61 ) && V_1 -> V_18 ) {
F_18 ( 63 ) ;
for ( V_69 = 0 ; V_69 < 63 ; ++ V_69 )
F_20 ( V_15 ) ;
V_1 -> V_18 = 0 ;
}
V_67 <<= 25 ;
while ( V_63 != 0 ) {
unsigned int V_35 = V_63 > 255 ? 255 : V_63 ;
for ( V_69 = 0 ; V_69 < V_35 ; ++ V_69 ) {
if ( V_89 [ V_69 ] > V_65 -> V_76 / 32 ) {
F_8 ( L_17 ,
V_69 , V_89 [ V_69 ] , V_65 -> V_76 / 32 ) ;
return - V_28 ;
}
}
if ( V_66 ) {
int V_66 [ 3 ] = { 2 , - 1 , - 1 } ;
F_18 ( ( V_35 + 1 + 1 ) / 2 ) ;
F_21 ( V_35 , V_67 , V_89 [ 2 ] ) ;
for ( V_69 = 1 ; V_69 + 1 < V_35 ; V_69 += 2 )
F_20 ( V_89 [ V_69 + V_66 [ V_69 % 3 ] ] |
( V_89 [ V_69 + 1 +
V_66 [ ( V_69 + 1 ) % 3 ] ] << 16 ) ) ;
if ( V_69 < V_35 )
F_20 ( V_89 [ V_69 + V_66 [ V_69 % 3 ] ] ) ;
} else if ( F_14 ( V_1 -> V_61 ) ) {
F_18 ( ( V_35 + 1 + 1 ) / 2 ) ;
F_21 ( V_35 , V_67 , V_89 [ 0 ] ) ;
for ( V_69 = 1 ; V_69 + 1 < V_35 ; V_69 += 2 )
F_20 ( V_89 [ V_69 ] | ( V_89 [ V_69 + 1 ] << 16 ) ) ;
if ( V_69 < V_35 )
F_20 ( V_89 [ V_69 ] ) ;
} else {
F_18 ( ( V_35 + 2 + 1 ) / 2 ) ;
F_22 ( V_35 , V_67 , V_68 ) ;
for ( V_69 = 0 ; V_69 + 1 < V_35 ; V_69 += 2 )
F_20 ( V_89 [ V_69 ] | ( V_89 [ V_69 + 1 ] << 16 ) ) ;
if ( V_69 < V_35 )
F_20 ( V_89 [ V_69 ] ) ;
}
V_89 += V_35 ;
V_63 -= V_35 ;
V_67 |= V_82 ;
}
return 0 ;
}
static int F_26 ( T_1 * V_1 ,
const T_3 * V_58 ,
const T_4 * V_89 ,
const T_2 * V_83 ,
unsigned int V_84 , unsigned int V_85 )
{
unsigned char V_66 = 0 ;
unsigned int V_67 = V_58 -> V_89 . V_67 ;
unsigned int V_68 = V_58 -> V_89 . V_68 ;
unsigned int V_63 = V_58 -> V_89 . V_35 ;
unsigned int V_86 ;
unsigned int V_69 ;
V_14 ;
if ( ! V_63 )
return 0 ;
switch ( V_67 ) {
case V_71 :
V_66 = 1 ;
V_67 = V_72 ;
case V_72 :
if ( V_63 % 3 != 0 ) {
F_8 ( L_15 , V_63 ) ;
return - V_28 ;
}
break;
case V_73 :
case V_74 :
if ( V_63 < 3 ) {
F_8
( L_16 , V_63 ) ;
return - V_28 ;
}
break;
default:
F_8 ( L_9 , V_67 ) ;
return - V_28 ;
}
if ( F_14 ( V_1 -> V_61 ) ) {
if ( V_68 > V_87 ) {
F_8 ( L_13 , V_68 ) ;
return - V_28 ;
}
V_86 = 8 ;
} else {
if ( V_68 > V_75 ) {
F_8 ( L_13 , V_68 ) ;
return - V_28 ;
}
V_86 = 10 ;
}
V_86 -= ( V_68 & 1 ) + ( V_68 >> 1 & 1 ) +
( V_68 >> 2 & 1 ) + ( V_68 >> 3 & 1 ) + ( V_68 >> 4 & 1 ) +
( V_68 >> 5 & 1 ) + ( V_68 >> 6 & 1 ) + ( V_68 >> 7 & 1 ) ;
if ( V_86 > V_85 ) {
F_8 ( L_14 ,
V_86 , V_85 ) ;
return - V_28 ;
}
V_67 <<= 25 ;
while ( V_63 != 0 ) {
unsigned int V_35 = V_63 > 255 ? 255 : V_63 ;
for ( V_69 = 0 ; V_69 < V_35 ; ++ V_69 ) {
if ( V_89 [ V_69 ] > V_84 / ( V_85 * 4 ) ) {
F_8 ( L_17 ,
V_69 , V_89 [ V_69 ] , V_84 / ( V_85 * 4 ) ) ;
return - V_28 ;
}
}
if ( V_66 ) {
int V_66 [ 3 ] = { 2 , - 1 , - 1 } ;
F_2 ( V_35 * V_86 + 1 ) ;
F_24 ( V_35 , V_67 , V_68 ) ;
for ( V_69 = 0 ; V_69 < V_35 ; ++ V_69 ) {
unsigned int V_88 = V_89 [ V_69 + V_66 [ V_69 % 3 ] ] ;
F_15 ( & V_83 [ V_85 * V_88 ] , V_86 ) ;
}
F_5 () ;
} else {
F_2 ( V_35 * V_86 + 1 ) ;
F_24 ( V_35 , V_67 , V_68 ) ;
for ( V_69 = 0 ; V_69 < V_35 ; ++ V_69 ) {
unsigned int V_88 = V_89 [ V_69 ] ;
F_15 ( & V_83 [ V_85 * V_88 ] , V_86 ) ;
}
F_5 () ;
}
V_89 += V_35 ;
V_63 -= V_35 ;
V_67 |= V_82 ;
}
return 0 ;
}
static int F_27 ( T_1 * V_1 ,
const T_3 * V_58 ,
const T_3 * V_90 ,
unsigned int V_91 ,
const struct V_2 * V_92 )
{
unsigned int V_93 = V_58 -> V_94 . V_93 ;
unsigned int V_95 ;
unsigned int V_69 , V_96 ;
V_14 ;
if ( V_91 == 0 )
return 0 ;
V_95 = V_97 | V_98 | V_99 |
V_100 | V_101 ;
F_28 ( V_95 , 0xCC ) ;
V_96 = ( ( V_93 & V_102 ) ? 1 : 0 ) +
( ( V_93 & V_103 ) ? 1 : 0 ) + ( ( V_93 & V_104 ) ? 1 : 0 ) ;
if ( V_96 == 0 )
return 0 ;
if ( V_90 -> V_105 . V_106 != 0xffffffff ) {
F_2 ( 2 ) ;
F_4 ( V_107 , 1 ) ;
F_3 ( V_90 -> V_105 . V_106 ) ;
F_5 () ;
}
for ( V_69 = 0 ; V_69 < V_91 ; ++ V_69 ) {
unsigned int V_108 , V_109 , V_110 , V_111 ;
unsigned int V_112 ;
V_108 = V_92 [ V_69 ] . V_11 , V_109 = V_92 [ V_69 ] . y1 ;
V_110 = V_92 [ V_69 ] . V_12 - V_92 [ V_69 ] . V_11 ;
V_111 = V_92 [ V_69 ] . V_13 - V_92 [ V_69 ] . y1 ;
F_2 ( V_96 * 6 ) ;
for ( V_112 = V_102 ; V_112 <= V_104 ; V_112 <<= 1 ) {
if ( ! ( V_93 & V_112 ) )
continue;
F_3 ( V_95 ) ;
switch ( V_112 ) {
case V_102 :
F_3 ( V_1 -> V_113 ) ;
F_3 ( V_1 -> V_114 ) ;
break;
case V_103 :
F_3 ( V_1 -> V_115 ) ;
F_3 ( V_1 -> V_116 ) ;
break;
case V_104 :
F_3 ( V_1 -> V_117 ) ;
F_3 ( V_1 -> V_118 ) ;
break;
}
F_3 ( V_90 -> V_105 . V_119 ) ;
F_3 ( F_29 ( V_108 , V_109 ) ) ;
F_3 ( F_30 ( V_110 , V_111 ) ) ;
}
F_5 () ;
}
if ( V_90 -> V_105 . V_106 != 0xffffffff ) {
F_2 ( 2 ) ;
F_4 ( V_107 , 1 ) ;
F_3 ( 0xffffffff ) ;
F_5 () ;
}
return 0 ;
}
static int F_31 ( T_1 * V_1 ,
unsigned int V_91 , const struct V_2 * V_92 )
{
unsigned int V_120 ;
unsigned int V_69 ;
V_14 ;
if ( V_91 == 0 )
return 0 ;
V_120 = V_97 | V_98 | V_99 |
V_121 | V_122 ;
F_28 ( V_120 , 0xCC ) ;
for ( V_69 = 0 ; V_69 < V_91 ; ++ V_69 ) {
F_2 ( 6 ) ;
F_3 ( V_120 ) ;
F_3 ( V_1 -> V_115 ) ;
F_3 ( V_1 -> V_116 ) ;
F_3 ( F_29 ( V_92 [ V_69 ] . V_11 , V_92 [ V_69 ] . y1 ) ) ;
F_3 ( F_29 ( V_92 [ V_69 ] . V_11 , V_92 [ V_69 ] . y1 ) ) ;
F_3 ( F_30 ( V_92 [ V_69 ] . V_12 - V_92 [ V_69 ] . V_11 ,
V_92 [ V_69 ] . V_13 - V_92 [ V_69 ] . y1 ) ) ;
F_5 () ;
}
return 0 ;
}
static int F_32 ( T_1 * V_1 ,
const T_3 * V_34 ,
const T_3 * V_123 ,
const struct V_64 * V_65 ,
const unsigned int * V_83 ,
unsigned int V_84 , unsigned int V_85 ,
unsigned int V_91 ,
const struct V_2 * V_92 )
{
unsigned int V_69 , V_88 ;
int V_45 ;
for ( V_69 = 0 ; V_69 < V_91 ; ++ V_69 ) {
const T_3 * V_124 ;
V_1 -> V_125 ( V_1 , & V_92 [ V_69 ] ) ;
V_124 = V_34 ;
while ( V_124 < V_123 ) {
T_3 V_58 ;
V_58 = * V_124 ;
V_124 ++ ;
switch ( V_58 . V_126 . V_126 ) {
case V_127 :
V_45 = F_16 (
V_1 , & V_58 , V_65 ) ;
break;
case V_128 :
V_45 = F_23 (
V_1 , & V_58 ,
V_83 , V_84 , V_85 ) ;
break;
case V_129 :
V_88 = ( V_58 . V_89 . V_35 + 3 ) / 4 ;
V_45 = F_25 ( V_1 ,
& V_58 , ( const T_4 * ) V_124 ,
V_65 ) ;
V_124 += V_88 ;
break;
case V_130 :
V_88 = ( V_58 . V_89 . V_35 + 3 ) / 4 ;
V_45 = F_26 ( V_1 ,
& V_58 , ( const T_4 * ) V_124 ,
( const T_2 * ) V_83 , V_84 ,
V_85 ) ;
V_124 += V_88 ;
break;
default:
F_8 ( L_18
L_19 ,
V_58 . V_126 . V_126 ) ;
return - V_28 ;
}
if ( V_45 != 0 )
return V_45 ;
}
}
return 0 ;
}
int F_33 ( struct V_131 * V_132 , void * V_90 , struct V_133 * V_134 )
{
T_1 * V_1 = V_132 -> V_135 ;
struct V_136 * V_137 = V_132 -> V_137 ;
struct V_64 * V_65 ;
T_5 * V_124 = V_90 ;
T_3 * V_138 = NULL ;
T_3 * V_139 ;
unsigned int * V_140 = NULL ;
struct V_2 * V_141 = NULL ;
unsigned int V_69 , V_88 ;
int V_45 = 0 ;
F_34 ( L_20 ) ;
F_35 ( V_132 , V_134 ) ;
if ( V_137 && V_137 -> V_142 ) {
if ( V_124 -> V_143 > V_137 -> V_144 ) {
F_8
( L_21 ,
V_124 -> V_143 , V_137 -> V_144 - 1 ) ;
return - V_28 ;
}
V_65 = V_137 -> V_142 [ V_124 -> V_143 ] ;
} else {
V_65 = NULL ;
}
if ( V_124 -> V_33 ) {
V_138 = F_36 ( V_124 -> V_33 , 8 , V_145 ) ;
if ( V_138 == NULL )
return - V_146 ;
if ( F_37 ( V_138 , V_124 -> V_147 ,
V_124 -> V_33 * 8 ) )
{
F_38 ( V_138 ) ;
return - V_148 ;
}
V_124 -> V_147 = V_138 ;
}
if ( V_124 -> V_84 ) {
V_140 = F_39 ( V_124 -> V_84 , V_145 ) ;
if ( V_140 == NULL ) {
V_45 = - V_146 ;
goto V_149;
}
if ( F_37 ( V_140 , V_124 -> V_150 ,
V_124 -> V_84 ) ) {
V_45 = - V_148 ;
goto V_149;
}
V_124 -> V_150 = V_140 ;
}
if ( V_124 -> V_91 ) {
V_141 = F_36 ( V_124 -> V_91 , sizeof( struct V_2 ) ,
V_145 ) ;
if ( V_141 == NULL ) {
V_45 = - V_146 ;
goto V_149;
}
if ( F_37 ( V_141 , V_124 -> V_151 ,
V_124 -> V_91 * sizeof( struct V_2 ) ) ) {
V_45 = - V_148 ;
goto V_149;
}
V_124 -> V_151 = V_141 ;
}
F_40 () ;
V_1 -> V_18 = 1 ;
V_69 = 0 ;
V_139 = NULL ;
while ( V_69 < V_124 -> V_33 ) {
T_3 V_58 ;
V_58 = * ( T_3 * ) V_124 -> V_147 ;
V_124 -> V_147 ++ ;
V_69 ++ ;
V_88 = 0 ;
switch ( V_58 . V_126 . V_126 ) {
case V_129 :
case V_130 :
V_88 = ( V_58 . V_89 . V_35 + 3 ) / 4 ;
if ( V_69 + V_88 > V_124 -> V_33 ) {
F_8 ( L_22
L_23 ) ;
F_17 () ;
V_45 = - V_28 ;
goto V_149;
}
case V_127 :
case V_128 :
if ( ! V_139 )
V_139 = V_124 -> V_147 - 1 ;
V_124 -> V_147 += V_88 ;
V_69 += V_88 ;
break;
default:
if ( V_139 ) {
V_45 = F_32 (
V_1 , V_139 ,
V_124 -> V_147 - 1 ,
V_65 , V_124 -> V_150 , V_124 -> V_84 ,
V_124 -> V_85 ,
V_124 -> V_91 , V_124 -> V_151 ) ;
if ( V_45 != 0 )
goto V_149;
V_139 = NULL ;
}
}
if ( V_139 )
continue;
switch ( V_58 . V_126 . V_126 ) {
case V_152 :
V_88 = ( V_58 . V_5 . V_35 + 1 ) / 2 ;
if ( V_69 + V_88 > V_124 -> V_33 ) {
F_8 ( L_24
L_23 ) ;
F_17 () ;
V_45 = - V_28 ;
goto V_149;
}
V_45 = F_13 ( V_1 , & V_58 ,
( const T_2 * ) V_124 -> V_147 ) ;
V_124 -> V_147 += V_88 ;
V_69 += V_88 ;
break;
case V_153 :
if ( V_69 + 1 > V_124 -> V_33 ) {
F_8 ( L_25
L_23 ) ;
F_17 () ;
V_45 = - V_28 ;
goto V_149;
}
V_45 = F_27 ( V_1 , & V_58 ,
V_124 -> V_147 ,
V_124 -> V_91 ,
V_124 -> V_151 ) ;
V_124 -> V_147 ++ ;
V_69 ++ ;
break;
case V_154 :
V_45 = F_31 ( V_1 , V_124 -> V_91 ,
V_124 -> V_151 ) ;
break;
default:
F_8 ( L_26 ,
V_58 . V_126 . V_126 ) ;
F_17 () ;
V_45 = - V_28 ;
goto V_149;
}
if ( V_45 != 0 ) {
F_17 () ;
goto V_149;
}
}
if ( V_139 ) {
V_45 = F_32 (
V_1 , V_139 , V_124 -> V_147 , V_65 ,
V_124 -> V_150 , V_124 -> V_84 , V_124 -> V_85 ,
V_124 -> V_91 , V_124 -> V_151 ) ;
if ( V_45 != 0 ) {
F_17 () ;
goto V_149;
}
}
F_17 () ;
if ( V_65 && V_124 -> V_155 ) {
T_6 * V_156 = V_65 -> V_135 ;
T_4 V_157 ;
V_157 = F_41 ( V_1 , V_158 ) ;
F_42 ( & V_156 -> V_159 , V_157 , V_1 -> V_160 ) ;
F_43 ( V_132 , V_65 ) ;
}
V_149:
F_38 ( V_138 ) ;
F_38 ( V_140 ) ;
F_38 ( V_141 ) ;
return V_45 ;
}
