static void F_1 ( T_1 * V_1 , T_1 * V_2 , const T_1 V_3 ,
const T_1 V_4 )
{
register T_1 V_5 , V_6 , V_7 ;
T_1 V_8 [ 8 ] , V_9 = V_3 >> 30 ;
register T_1 V_10 , V_11 , V_12 ;
V_10 = V_3 & ( 0x3FFFFFFF ) ;
V_11 = V_10 << 1 ;
V_12 = V_11 << 1 ;
V_8 [ 0 ] = 0 ;
V_8 [ 1 ] = V_10 ;
V_8 [ 2 ] = V_11 ;
V_8 [ 3 ] = V_10 ^ V_11 ;
V_8 [ 4 ] = V_12 ;
V_8 [ 5 ] = V_10 ^ V_12 ;
V_8 [ 6 ] = V_11 ^ V_12 ;
V_8 [ 7 ] = V_10 ^ V_11 ^ V_12 ;
V_7 = V_8 [ V_4 & 0x7 ] ;
V_6 = V_7 ;
V_7 = V_8 [ V_4 >> 3 & 0x7 ] ;
V_6 ^= V_7 << 3 ;
V_5 = V_7 >> 29 ;
V_7 = V_8 [ V_4 >> 6 & 0x7 ] ;
V_6 ^= V_7 << 6 ;
V_5 ^= V_7 >> 26 ;
V_7 = V_8 [ V_4 >> 9 & 0x7 ] ;
V_6 ^= V_7 << 9 ;
V_5 ^= V_7 >> 23 ;
V_7 = V_8 [ V_4 >> 12 & 0x7 ] ;
V_6 ^= V_7 << 12 ;
V_5 ^= V_7 >> 20 ;
V_7 = V_8 [ V_4 >> 15 & 0x7 ] ;
V_6 ^= V_7 << 15 ;
V_5 ^= V_7 >> 17 ;
V_7 = V_8 [ V_4 >> 18 & 0x7 ] ;
V_6 ^= V_7 << 18 ;
V_5 ^= V_7 >> 14 ;
V_7 = V_8 [ V_4 >> 21 & 0x7 ] ;
V_6 ^= V_7 << 21 ;
V_5 ^= V_7 >> 11 ;
V_7 = V_8 [ V_4 >> 24 & 0x7 ] ;
V_6 ^= V_7 << 24 ;
V_5 ^= V_7 >> 8 ;
V_7 = V_8 [ V_4 >> 27 & 0x7 ] ;
V_6 ^= V_7 << 27 ;
V_5 ^= V_7 >> 5 ;
V_7 = V_8 [ V_4 >> 30 ] ;
V_6 ^= V_7 << 30 ;
V_5 ^= V_7 >> 2 ;
if ( V_9 & 01 ) {
V_6 ^= V_4 << 30 ;
V_5 ^= V_4 >> 2 ;
}
if ( V_9 & 02 ) {
V_6 ^= V_4 << 31 ;
V_5 ^= V_4 >> 1 ;
}
* V_1 = V_5 ;
* V_2 = V_6 ;
}
static void F_1 ( T_1 * V_1 , T_1 * V_2 , const T_1 V_3 ,
const T_1 V_4 )
{
register T_1 V_5 , V_6 , V_7 ;
T_1 V_8 [ 16 ] , V_13 = V_3 >> 61 ;
register T_1 V_10 , V_11 , V_12 , V_14 ;
V_10 = V_3 & ( 0x1FFFFFFFFFFFFFFFULL ) ;
V_11 = V_10 << 1 ;
V_12 = V_11 << 1 ;
V_14 = V_12 << 1 ;
V_8 [ 0 ] = 0 ;
V_8 [ 1 ] = V_10 ;
V_8 [ 2 ] = V_11 ;
V_8 [ 3 ] = V_10 ^ V_11 ;
V_8 [ 4 ] = V_12 ;
V_8 [ 5 ] = V_10 ^ V_12 ;
V_8 [ 6 ] = V_11 ^ V_12 ;
V_8 [ 7 ] = V_10 ^ V_11 ^ V_12 ;
V_8 [ 8 ] = V_14 ;
V_8 [ 9 ] = V_10 ^ V_14 ;
V_8 [ 10 ] = V_11 ^ V_14 ;
V_8 [ 11 ] = V_10 ^ V_11 ^ V_14 ;
V_8 [ 12 ] = V_12 ^ V_14 ;
V_8 [ 13 ] = V_10 ^ V_12 ^ V_14 ;
V_8 [ 14 ] = V_11 ^ V_12 ^ V_14 ;
V_8 [ 15 ] = V_10 ^ V_11 ^ V_12 ^ V_14 ;
V_7 = V_8 [ V_4 & 0xF ] ;
V_6 = V_7 ;
V_7 = V_8 [ V_4 >> 4 & 0xF ] ;
V_6 ^= V_7 << 4 ;
V_5 = V_7 >> 60 ;
V_7 = V_8 [ V_4 >> 8 & 0xF ] ;
V_6 ^= V_7 << 8 ;
V_5 ^= V_7 >> 56 ;
V_7 = V_8 [ V_4 >> 12 & 0xF ] ;
V_6 ^= V_7 << 12 ;
V_5 ^= V_7 >> 52 ;
V_7 = V_8 [ V_4 >> 16 & 0xF ] ;
V_6 ^= V_7 << 16 ;
V_5 ^= V_7 >> 48 ;
V_7 = V_8 [ V_4 >> 20 & 0xF ] ;
V_6 ^= V_7 << 20 ;
V_5 ^= V_7 >> 44 ;
V_7 = V_8 [ V_4 >> 24 & 0xF ] ;
V_6 ^= V_7 << 24 ;
V_5 ^= V_7 >> 40 ;
V_7 = V_8 [ V_4 >> 28 & 0xF ] ;
V_6 ^= V_7 << 28 ;
V_5 ^= V_7 >> 36 ;
V_7 = V_8 [ V_4 >> 32 & 0xF ] ;
V_6 ^= V_7 << 32 ;
V_5 ^= V_7 >> 32 ;
V_7 = V_8 [ V_4 >> 36 & 0xF ] ;
V_6 ^= V_7 << 36 ;
V_5 ^= V_7 >> 28 ;
V_7 = V_8 [ V_4 >> 40 & 0xF ] ;
V_6 ^= V_7 << 40 ;
V_5 ^= V_7 >> 24 ;
V_7 = V_8 [ V_4 >> 44 & 0xF ] ;
V_6 ^= V_7 << 44 ;
V_5 ^= V_7 >> 20 ;
V_7 = V_8 [ V_4 >> 48 & 0xF ] ;
V_6 ^= V_7 << 48 ;
V_5 ^= V_7 >> 16 ;
V_7 = V_8 [ V_4 >> 52 & 0xF ] ;
V_6 ^= V_7 << 52 ;
V_5 ^= V_7 >> 12 ;
V_7 = V_8 [ V_4 >> 56 & 0xF ] ;
V_6 ^= V_7 << 56 ;
V_5 ^= V_7 >> 8 ;
V_7 = V_8 [ V_4 >> 60 ] ;
V_6 ^= V_7 << 60 ;
V_5 ^= V_7 >> 4 ;
if ( V_13 & 01 ) {
V_6 ^= V_4 << 61 ;
V_5 ^= V_4 >> 3 ;
}
if ( V_13 & 02 ) {
V_6 ^= V_4 << 62 ;
V_5 ^= V_4 >> 2 ;
}
if ( V_13 & 04 ) {
V_6 ^= V_4 << 63 ;
V_5 ^= V_4 >> 1 ;
}
* V_1 = V_5 ;
* V_2 = V_6 ;
}
static void F_2 ( T_1 * V_15 , const T_1 V_10 , const T_1 V_16 ,
const T_1 V_17 , const T_1 V_18 )
{
T_1 V_19 , V_20 ;
F_1 ( V_15 + 3 , V_15 + 2 , V_10 , V_17 ) ;
F_1 ( V_15 + 1 , V_15 , V_16 , V_18 ) ;
F_1 ( & V_19 , & V_20 , V_16 ^ V_10 , V_18 ^ V_17 ) ;
V_15 [ 2 ] ^= V_19 ^ V_15 [ 1 ] ^ V_15 [ 3 ] ;
V_15 [ 1 ] = V_15 [ 3 ] ^ V_15 [ 2 ] ^ V_15 [ 0 ] ^ V_19 ^ V_20 ;
}
int F_3 ( T_2 * V_15 , const T_2 * V_3 , const T_2 * V_4 )
{
int V_21 ;
const T_2 * V_22 , * V_23 ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
if ( V_3 -> V_24 < V_4 -> V_24 ) {
V_22 = V_4 ;
V_23 = V_3 ;
} else {
V_22 = V_3 ;
V_23 = V_4 ;
}
if ( F_5 ( V_15 , V_22 -> V_24 ) == NULL )
return 0 ;
for ( V_21 = 0 ; V_21 < V_23 -> V_24 ; V_21 ++ ) {
V_15 -> V_25 [ V_21 ] = V_22 -> V_25 [ V_21 ] ^ V_23 -> V_25 [ V_21 ] ;
}
for (; V_21 < V_22 -> V_24 ; V_21 ++ ) {
V_15 -> V_25 [ V_21 ] = V_22 -> V_25 [ V_21 ] ;
}
V_15 -> V_24 = V_22 -> V_24 ;
F_6 ( V_15 ) ;
return 1 ;
}
int F_7 ( T_2 * V_15 , const T_2 * V_3 , const int V_26 [] )
{
int V_27 , V_28 ;
int V_29 , V_30 , V_31 , V_32 ;
T_1 V_33 , * V_34 ;
F_4 ( V_3 ) ;
if ( ! V_26 [ 0 ] ) {
F_8 ( V_15 ) ;
return 1 ;
}
if ( V_3 != V_15 ) {
if ( ! F_5 ( V_15 , V_3 -> V_24 ) )
return 0 ;
for ( V_27 = 0 ; V_27 < V_3 -> V_24 ; V_27 ++ ) {
V_15 -> V_25 [ V_27 ] = V_3 -> V_25 [ V_27 ] ;
}
V_15 -> V_24 = V_3 -> V_24 ;
}
V_34 = V_15 -> V_25 ;
V_30 = V_26 [ 0 ] / V_35 ;
for ( V_27 = V_15 -> V_24 - 1 ; V_27 > V_30 ; ) {
V_33 = V_34 [ V_27 ] ;
if ( V_34 [ V_27 ] == 0 ) {
V_27 -- ;
continue;
}
V_34 [ V_27 ] = 0 ;
for ( V_28 = 1 ; V_26 [ V_28 ] != 0 ; V_28 ++ ) {
V_29 = V_26 [ 0 ] - V_26 [ V_28 ] ;
V_31 = V_29 % V_35 ;
V_32 = V_35 - V_31 ;
V_29 /= V_35 ;
V_34 [ V_27 - V_29 ] ^= ( V_33 >> V_31 ) ;
if ( V_31 )
V_34 [ V_27 - V_29 - 1 ] ^= ( V_33 << V_32 ) ;
}
V_29 = V_30 ;
V_31 = V_26 [ 0 ] % V_35 ;
V_32 = V_35 - V_31 ;
V_34 [ V_27 - V_29 ] ^= ( V_33 >> V_31 ) ;
if ( V_31 )
V_34 [ V_27 - V_29 - 1 ] ^= ( V_33 << V_32 ) ;
}
while ( V_27 == V_30 ) {
V_31 = V_26 [ 0 ] % V_35 ;
V_33 = V_34 [ V_30 ] >> V_31 ;
if ( V_33 == 0 )
break;
V_32 = V_35 - V_31 ;
if ( V_31 )
V_34 [ V_30 ] = ( V_34 [ V_30 ] << V_32 ) >> V_32 ;
else
V_34 [ V_30 ] = 0 ;
V_34 [ 0 ] ^= V_33 ;
for ( V_28 = 1 ; V_26 [ V_28 ] != 0 ; V_28 ++ ) {
T_1 V_36 ;
V_29 = V_26 [ V_28 ] / V_35 ;
V_31 = V_26 [ V_28 ] % V_35 ;
V_32 = V_35 - V_31 ;
V_34 [ V_29 ] ^= ( V_33 << V_31 ) ;
V_36 = V_33 >> V_32 ;
if ( V_31 && V_36 )
V_34 [ V_29 + 1 ] ^= V_36 ;
}
}
F_6 ( V_15 ) ;
return 1 ;
}
int F_9 ( T_2 * V_15 , const T_2 * V_3 , const T_2 * V_26 )
{
int V_37 = 0 ;
int V_38 [ 6 ] ;
F_4 ( V_3 ) ;
F_4 ( V_26 ) ;
V_37 = F_10 ( V_26 , V_38 , sizeof( V_38 ) / sizeof( V_38 [ 0 ] ) ) ;
if ( ! V_37 || V_37 > ( int ) ( sizeof( V_38 ) / sizeof( V_38 [ 0 ] ) ) ) {
F_11 ( V_39 , V_40 ) ;
return 0 ;
}
V_37 = F_7 ( V_15 , V_3 , V_38 ) ;
F_4 ( V_15 ) ;
return V_37 ;
}
int F_12 ( T_2 * V_15 , const T_2 * V_3 , const T_2 * V_4 ,
const int V_26 [] , T_3 * V_41 )
{
int V_42 , V_21 , V_27 , V_28 , V_37 = 0 ;
T_2 * V_7 ;
T_1 V_43 , V_44 , y1 , y0 , V_33 [ 4 ] ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
if ( V_3 == V_4 ) {
return F_13 ( V_15 , V_3 , V_26 , V_41 ) ;
}
F_14 ( V_41 ) ;
if ( ( V_7 = F_15 ( V_41 ) ) == NULL )
goto V_45;
V_42 = V_3 -> V_24 + V_4 -> V_24 + 4 ;
if ( ! F_5 ( V_7 , V_42 ) )
goto V_45;
V_7 -> V_24 = V_42 ;
for ( V_21 = 0 ; V_21 < V_42 ; V_21 ++ )
V_7 -> V_25 [ V_21 ] = 0 ;
for ( V_27 = 0 ; V_27 < V_4 -> V_24 ; V_27 += 2 ) {
y0 = V_4 -> V_25 [ V_27 ] ;
y1 = ( ( V_27 + 1 ) == V_4 -> V_24 ) ? 0 : V_4 -> V_25 [ V_27 + 1 ] ;
for ( V_21 = 0 ; V_21 < V_3 -> V_24 ; V_21 += 2 ) {
V_44 = V_3 -> V_25 [ V_21 ] ;
V_43 = ( ( V_21 + 1 ) == V_3 -> V_24 ) ? 0 : V_3 -> V_25 [ V_21 + 1 ] ;
F_2 ( V_33 , V_43 , V_44 , y1 , y0 ) ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ )
V_7 -> V_25 [ V_21 + V_27 + V_28 ] ^= V_33 [ V_28 ] ;
}
}
F_6 ( V_7 ) ;
if ( F_7 ( V_15 , V_7 , V_26 ) )
V_37 = 1 ;
F_4 ( V_15 ) ;
V_45:
F_16 ( V_41 ) ;
return V_37 ;
}
int F_17 ( T_2 * V_15 , const T_2 * V_3 , const T_2 * V_4 ,
const T_2 * V_26 , T_3 * V_41 )
{
int V_37 = 0 ;
const int V_46 = F_18 ( V_26 ) + 1 ;
int * V_38 = NULL ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
F_4 ( V_26 ) ;
if ( ( V_38 = ( int * ) F_19 ( sizeof( int ) * V_46 ) ) == NULL )
goto V_45;
V_37 = F_10 ( V_26 , V_38 , V_46 ) ;
if ( ! V_37 || V_37 > V_46 ) {
F_11 ( V_47 , V_40 ) ;
goto V_45;
}
V_37 = F_12 ( V_15 , V_3 , V_4 , V_38 , V_41 ) ;
F_4 ( V_15 ) ;
V_45:
if ( V_38 )
F_20 ( V_38 ) ;
return V_37 ;
}
int F_13 ( T_2 * V_15 , const T_2 * V_3 , const int V_26 [] ,
T_3 * V_41 )
{
int V_21 , V_37 = 0 ;
T_2 * V_7 ;
F_4 ( V_3 ) ;
F_14 ( V_41 ) ;
if ( ( V_7 = F_15 ( V_41 ) ) == NULL )
return 0 ;
if ( ! F_5 ( V_7 , 2 * V_3 -> V_24 ) )
goto V_45;
for ( V_21 = V_3 -> V_24 - 1 ; V_21 >= 0 ; V_21 -- ) {
V_7 -> V_25 [ 2 * V_21 + 1 ] = F_21 ( V_3 -> V_25 [ V_21 ] ) ;
V_7 -> V_25 [ 2 * V_21 ] = F_22 ( V_3 -> V_25 [ V_21 ] ) ;
}
V_7 -> V_24 = 2 * V_3 -> V_24 ;
F_6 ( V_7 ) ;
if ( ! F_7 ( V_15 , V_7 , V_26 ) )
goto V_45;
F_4 ( V_15 ) ;
V_37 = 1 ;
V_45:
F_16 ( V_41 ) ;
return V_37 ;
}
int F_23 ( T_2 * V_15 , const T_2 * V_3 , const T_2 * V_26 , T_3 * V_41 )
{
int V_37 = 0 ;
const int V_46 = F_18 ( V_26 ) + 1 ;
int * V_38 = NULL ;
F_4 ( V_3 ) ;
F_4 ( V_26 ) ;
if ( ( V_38 = ( int * ) F_19 ( sizeof( int ) * V_46 ) ) == NULL )
goto V_45;
V_37 = F_10 ( V_26 , V_38 , V_46 ) ;
if ( ! V_37 || V_37 > V_46 ) {
F_11 ( V_48 , V_40 ) ;
goto V_45;
}
V_37 = F_13 ( V_15 , V_3 , V_38 , V_41 ) ;
F_4 ( V_15 ) ;
V_45:
if ( V_38 )
F_20 ( V_38 ) ;
return V_37 ;
}
int F_24 ( T_2 * V_15 , const T_2 * V_3 , const T_2 * V_26 , T_3 * V_41 )
{
T_2 * V_4 , * V_49 = NULL , * V_50 = NULL , * V_51 = NULL , * V_52 ;
int V_37 = 0 ;
F_4 ( V_3 ) ;
F_4 ( V_26 ) ;
F_14 ( V_41 ) ;
if ( ( V_4 = F_15 ( V_41 ) ) == NULL )
goto V_45;
if ( ( V_49 = F_15 ( V_41 ) ) == NULL )
goto V_45;
if ( ( V_50 = F_15 ( V_41 ) ) == NULL )
goto V_45;
if ( ( V_51 = F_15 ( V_41 ) ) == NULL )
goto V_45;
if ( ! F_9 ( V_50 , V_3 , V_26 ) )
goto V_45;
if ( F_25 ( V_50 ) )
goto V_45;
if ( ! F_26 ( V_51 , V_26 ) )
goto V_45;
# if 0
if (!BN_one(b))
goto err;
while (1) {
while (!BN_is_odd(u)) {
if (BN_is_zero(u))
goto err;
if (!BN_rshift1(u, u))
goto err;
if (BN_is_odd(b)) {
if (!BN_GF2m_add(b, b, p))
goto err;
}
if (!BN_rshift1(b, b))
goto err;
}
if (BN_abs_is_word(u, 1))
break;
if (BN_num_bits(u) < BN_num_bits(v)) {
tmp = u;
u = v;
v = tmp;
tmp = b;
b = c;
c = tmp;
}
if (!BN_GF2m_add(u, u, v))
goto err;
if (!BN_GF2m_add(b, b, c))
goto err;
}
# else
{
int V_21 , V_53 = F_18 ( V_50 ) , V_54 = F_18 ( V_51 ) ,
V_24 = V_26 -> V_24 ;
T_1 * V_55 , * V_56 , * V_57 , * V_58 ;
F_5 ( V_50 , V_24 ) ;
V_55 = V_50 -> V_25 ;
for ( V_21 = V_50 -> V_24 ; V_21 < V_24 ; V_21 ++ )
V_55 [ V_21 ] = 0 ;
V_50 -> V_24 = V_24 ;
F_5 ( V_4 , V_24 ) ;
V_56 = V_4 -> V_25 ;
V_56 [ 0 ] = 1 ;
for ( V_21 = 1 ; V_21 < V_24 ; V_21 ++ )
V_56 [ V_21 ] = 0 ;
V_4 -> V_24 = V_24 ;
F_5 ( V_49 , V_24 ) ;
V_58 = V_49 -> V_25 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ )
V_58 [ V_21 ] = 0 ;
V_49 -> V_24 = V_24 ;
V_57 = V_51 -> V_25 ;
while ( 1 ) {
while ( V_53 && ! ( V_55 [ 0 ] & 1 ) ) {
T_1 V_59 , V_60 , V_18 , V_17 , V_61 ;
V_59 = V_55 [ 0 ] ;
V_18 = V_56 [ 0 ] ;
V_61 = ( T_1 ) 0 - ( V_18 & 1 ) ;
V_18 ^= V_26 -> V_25 [ 0 ] & V_61 ;
for ( V_21 = 0 ; V_21 < V_24 - 1 ; V_21 ++ ) {
V_60 = V_55 [ V_21 + 1 ] ;
V_55 [ V_21 ] = ( ( V_59 >> 1 ) | ( V_60 << ( V_35 - 1 ) ) ) & V_62 ;
V_59 = V_60 ;
V_17 = V_56 [ V_21 + 1 ] ^ ( V_26 -> V_25 [ V_21 + 1 ] & V_61 ) ;
V_56 [ V_21 ] = ( ( V_18 >> 1 ) | ( V_17 << ( V_35 - 1 ) ) ) & V_62 ;
V_18 = V_17 ;
}
V_55 [ V_21 ] = V_59 >> 1 ;
V_56 [ V_21 ] = V_18 >> 1 ;
V_53 -- ;
}
if ( V_53 <= V_35 && V_55 [ 0 ] == 1 )
break;
if ( V_53 < V_54 ) {
V_21 = V_53 ;
V_53 = V_54 ;
V_54 = V_21 ;
V_52 = V_50 ;
V_50 = V_51 ;
V_51 = V_52 ;
V_52 = V_4 ;
V_4 = V_49 ;
V_49 = V_52 ;
V_55 = V_57 ;
V_57 = V_51 -> V_25 ;
V_56 = V_58 ;
V_58 = V_49 -> V_25 ;
}
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
V_55 [ V_21 ] ^= V_57 [ V_21 ] ;
V_56 [ V_21 ] ^= V_58 [ V_21 ] ;
}
if ( V_53 == V_54 ) {
T_1 V_63 ;
int V_64 = ( V_53 - 1 ) / V_35 ;
while ( ( V_63 = V_55 [ V_64 ] ) == 0 && V_64 )
V_64 -- ;
V_53 = V_64 * V_35 + F_27 ( V_63 ) ;
}
}
F_6 ( V_4 ) ;
}
# endif
if ( ! F_26 ( V_15 , V_4 ) )
goto V_45;
F_4 ( V_15 ) ;
V_37 = 1 ;
V_45:
# ifdef F_28
F_6 ( V_49 ) ;
F_6 ( V_50 ) ;
F_6 ( V_51 ) ;
# endif
F_16 ( V_41 ) ;
return V_37 ;
}
int F_29 ( T_2 * V_15 , const T_2 * V_65 , const int V_26 [] ,
T_3 * V_41 )
{
T_2 * V_66 ;
int V_37 = 0 ;
F_4 ( V_65 ) ;
F_14 ( V_41 ) ;
if ( ( V_66 = F_15 ( V_41 ) ) == NULL )
goto V_45;
if ( ! F_30 ( V_26 , V_66 ) )
goto V_45;
V_37 = F_24 ( V_15 , V_65 , V_66 , V_41 ) ;
F_4 ( V_15 ) ;
V_45:
F_16 ( V_41 ) ;
return V_37 ;
}
int F_31 ( T_2 * V_15 , const T_2 * V_67 , const T_2 * V_68 ,
const T_2 * V_26 , T_3 * V_41 )
{
T_2 * V_69 = NULL ;
int V_37 = 0 ;
F_4 ( V_67 ) ;
F_4 ( V_68 ) ;
F_4 ( V_26 ) ;
F_14 ( V_41 ) ;
V_69 = F_15 ( V_41 ) ;
if ( V_69 == NULL )
goto V_45;
if ( ! F_24 ( V_69 , V_68 , V_26 , V_41 ) )
goto V_45;
if ( ! F_17 ( V_15 , V_67 , V_69 , V_26 , V_41 ) )
goto V_45;
F_4 ( V_15 ) ;
V_37 = 1 ;
V_45:
F_16 ( V_41 ) ;
return V_37 ;
}
int F_31 ( T_2 * V_15 , const T_2 * V_67 , const T_2 * V_68 ,
const T_2 * V_26 , T_3 * V_41 )
{
T_2 * V_3 , * V_4 , * V_50 , * V_51 ;
int V_37 = 0 ;
F_4 ( V_67 ) ;
F_4 ( V_68 ) ;
F_4 ( V_26 ) ;
F_14 ( V_41 ) ;
V_3 = F_15 ( V_41 ) ;
V_4 = F_15 ( V_41 ) ;
V_50 = F_15 ( V_41 ) ;
V_51 = F_15 ( V_41 ) ;
if ( V_51 == NULL )
goto V_45;
if ( ! F_9 ( V_50 , V_67 , V_26 ) )
goto V_45;
if ( ! F_9 ( V_3 , V_68 , V_26 ) )
goto V_45;
if ( ! F_26 ( V_4 , V_26 ) )
goto V_45;
while ( ! F_32 ( V_3 ) ) {
if ( ! F_33 ( V_3 , V_3 ) )
goto V_45;
if ( F_32 ( V_50 ) )
if ( ! F_3 ( V_50 , V_50 , V_26 ) )
goto V_45;
if ( ! F_33 ( V_50 , V_50 ) )
goto V_45;
}
do {
if ( F_34 ( V_4 , V_3 ) > 0 ) {
if ( ! F_3 ( V_4 , V_4 , V_3 ) )
goto V_45;
if ( ! F_3 ( V_51 , V_51 , V_50 ) )
goto V_45;
do {
if ( ! F_33 ( V_4 , V_4 ) )
goto V_45;
if ( F_32 ( V_51 ) )
if ( ! F_3 ( V_51 , V_51 , V_26 ) )
goto V_45;
if ( ! F_33 ( V_51 , V_51 ) )
goto V_45;
} while ( ! F_32 ( V_4 ) );
} else if ( F_35 ( V_3 , 1 ) )
break;
else {
if ( ! F_3 ( V_3 , V_3 , V_4 ) )
goto V_45;
if ( ! F_3 ( V_50 , V_50 , V_51 ) )
goto V_45;
do {
if ( ! F_33 ( V_3 , V_3 ) )
goto V_45;
if ( F_32 ( V_50 ) )
if ( ! F_3 ( V_50 , V_50 , V_26 ) )
goto V_45;
if ( ! F_33 ( V_50 , V_50 ) )
goto V_45;
} while ( ! F_32 ( V_3 ) );
}
} while ( 1 );
if ( ! F_26 ( V_15 , V_50 ) )
goto V_45;
F_4 ( V_15 ) ;
V_37 = 1 ;
V_45:
F_16 ( V_41 ) ;
return V_37 ;
}
int F_36 ( T_2 * V_15 , const T_2 * V_70 , const T_2 * V_65 ,
const int V_26 [] , T_3 * V_41 )
{
T_2 * V_66 ;
int V_37 = 0 ;
F_4 ( V_70 ) ;
F_4 ( V_65 ) ;
F_14 ( V_41 ) ;
if ( ( V_66 = F_15 ( V_41 ) ) == NULL )
goto V_45;
if ( ! F_30 ( V_26 , V_66 ) )
goto V_45;
V_37 = F_31 ( V_15 , V_70 , V_65 , V_66 , V_41 ) ;
F_4 ( V_15 ) ;
V_45:
F_16 ( V_41 ) ;
return V_37 ;
}
int F_37 ( T_2 * V_15 , const T_2 * V_3 , const T_2 * V_4 ,
const int V_26 [] , T_3 * V_41 )
{
int V_37 = 0 , V_21 , V_29 ;
T_2 * V_50 ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
if ( F_25 ( V_4 ) )
return ( F_38 ( V_15 ) ) ;
if ( F_35 ( V_4 , 1 ) )
return ( F_26 ( V_15 , V_3 ) != NULL ) ;
F_14 ( V_41 ) ;
if ( ( V_50 = F_15 ( V_41 ) ) == NULL )
goto V_45;
if ( ! F_7 ( V_50 , V_3 , V_26 ) )
goto V_45;
V_29 = F_18 ( V_4 ) - 1 ;
for ( V_21 = V_29 - 1 ; V_21 >= 0 ; V_21 -- ) {
if ( ! F_13 ( V_50 , V_50 , V_26 , V_41 ) )
goto V_45;
if ( F_39 ( V_4 , V_21 ) ) {
if ( ! F_12 ( V_50 , V_50 , V_3 , V_26 , V_41 ) )
goto V_45;
}
}
if ( ! F_26 ( V_15 , V_50 ) )
goto V_45;
F_4 ( V_15 ) ;
V_37 = 1 ;
V_45:
F_16 ( V_41 ) ;
return V_37 ;
}
int F_40 ( T_2 * V_15 , const T_2 * V_3 , const T_2 * V_4 ,
const T_2 * V_26 , T_3 * V_41 )
{
int V_37 = 0 ;
const int V_46 = F_18 ( V_26 ) + 1 ;
int * V_38 = NULL ;
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
F_4 ( V_26 ) ;
if ( ( V_38 = ( int * ) F_19 ( sizeof( int ) * V_46 ) ) == NULL )
goto V_45;
V_37 = F_10 ( V_26 , V_38 , V_46 ) ;
if ( ! V_37 || V_37 > V_46 ) {
F_11 ( V_71 , V_40 ) ;
goto V_45;
}
V_37 = F_37 ( V_15 , V_3 , V_4 , V_38 , V_41 ) ;
F_4 ( V_15 ) ;
V_45:
if ( V_38 )
F_20 ( V_38 ) ;
return V_37 ;
}
int F_41 ( T_2 * V_15 , const T_2 * V_3 , const int V_26 [] ,
T_3 * V_41 )
{
int V_37 = 0 ;
T_2 * V_50 ;
F_4 ( V_3 ) ;
if ( ! V_26 [ 0 ] ) {
F_8 ( V_15 ) ;
return 1 ;
}
F_14 ( V_41 ) ;
if ( ( V_50 = F_15 ( V_41 ) ) == NULL )
goto V_45;
if ( ! F_42 ( V_50 , V_26 [ 0 ] - 1 ) )
goto V_45;
V_37 = F_37 ( V_15 , V_3 , V_50 , V_26 , V_41 ) ;
F_4 ( V_15 ) ;
V_45:
F_16 ( V_41 ) ;
return V_37 ;
}
int F_43 ( T_2 * V_15 , const T_2 * V_3 , const T_2 * V_26 , T_3 * V_41 )
{
int V_37 = 0 ;
const int V_46 = F_18 ( V_26 ) + 1 ;
int * V_38 = NULL ;
F_4 ( V_3 ) ;
F_4 ( V_26 ) ;
if ( ( V_38 = ( int * ) F_19 ( sizeof( int ) * V_46 ) ) == NULL )
goto V_45;
V_37 = F_10 ( V_26 , V_38 , V_46 ) ;
if ( ! V_37 || V_37 > V_46 ) {
F_11 ( V_72 , V_40 ) ;
goto V_45;
}
V_37 = F_41 ( V_15 , V_3 , V_38 , V_41 ) ;
F_4 ( V_15 ) ;
V_45:
if ( V_38 )
F_20 ( V_38 ) ;
return V_37 ;
}
int F_44 ( T_2 * V_15 , const T_2 * V_73 , const int V_26 [] ,
T_3 * V_41 )
{
int V_37 = 0 , V_74 = 0 , V_27 ;
T_2 * V_3 , * V_34 , * V_75 , * V_76 , * V_77 , * V_52 ;
F_4 ( V_73 ) ;
if ( ! V_26 [ 0 ] ) {
F_8 ( V_15 ) ;
return 1 ;
}
F_14 ( V_41 ) ;
V_3 = F_15 ( V_41 ) ;
V_34 = F_15 ( V_41 ) ;
V_76 = F_15 ( V_41 ) ;
if ( V_76 == NULL )
goto V_45;
if ( ! F_7 ( V_3 , V_73 , V_26 ) )
goto V_45;
if ( F_25 ( V_3 ) ) {
F_8 ( V_15 ) ;
V_37 = 1 ;
goto V_45;
}
if ( V_26 [ 0 ] & 0x1 ) {
if ( ! F_26 ( V_34 , V_3 ) )
goto V_45;
for ( V_27 = 1 ; V_27 <= ( V_26 [ 0 ] - 1 ) / 2 ; V_27 ++ ) {
if ( ! F_13 ( V_34 , V_34 , V_26 , V_41 ) )
goto V_45;
if ( ! F_13 ( V_34 , V_34 , V_26 , V_41 ) )
goto V_45;
if ( ! F_3 ( V_34 , V_34 , V_3 ) )
goto V_45;
}
} else {
V_75 = F_15 ( V_41 ) ;
V_77 = F_15 ( V_41 ) ;
V_52 = F_15 ( V_41 ) ;
if ( V_52 == NULL )
goto V_45;
do {
if ( ! F_45 ( V_75 , V_26 [ 0 ] , 0 , 0 ) )
goto V_45;
if ( ! F_7 ( V_75 , V_75 , V_26 ) )
goto V_45;
F_8 ( V_34 ) ;
if ( ! F_26 ( V_76 , V_75 ) )
goto V_45;
for ( V_27 = 1 ; V_27 <= V_26 [ 0 ] - 1 ; V_27 ++ ) {
if ( ! F_13 ( V_34 , V_34 , V_26 , V_41 ) )
goto V_45;
if ( ! F_13 ( V_77 , V_76 , V_26 , V_41 ) )
goto V_45;
if ( ! F_12 ( V_52 , V_77 , V_3 , V_26 , V_41 ) )
goto V_45;
if ( ! F_3 ( V_34 , V_34 , V_52 ) )
goto V_45;
if ( ! F_3 ( V_76 , V_77 , V_75 ) )
goto V_45;
}
V_74 ++ ;
} while ( F_25 ( V_76 ) && ( V_74 < V_78 ) );
if ( F_25 ( V_76 ) ) {
F_11 ( V_79 , V_80 ) ;
goto V_45;
}
}
if ( ! F_13 ( V_76 , V_34 , V_26 , V_41 ) )
goto V_45;
if ( ! F_3 ( V_76 , V_34 , V_76 ) )
goto V_45;
if ( F_34 ( V_76 , V_3 ) ) {
F_11 ( V_79 , V_81 ) ;
goto V_45;
}
if ( ! F_26 ( V_15 , V_34 ) )
goto V_45;
F_4 ( V_15 ) ;
V_37 = 1 ;
V_45:
F_16 ( V_41 ) ;
return V_37 ;
}
int F_46 ( T_2 * V_15 , const T_2 * V_3 , const T_2 * V_26 ,
T_3 * V_41 )
{
int V_37 = 0 ;
const int V_46 = F_18 ( V_26 ) + 1 ;
int * V_38 = NULL ;
F_4 ( V_3 ) ;
F_4 ( V_26 ) ;
if ( ( V_38 = ( int * ) F_19 ( sizeof( int ) * V_46 ) ) == NULL )
goto V_45;
V_37 = F_10 ( V_26 , V_38 , V_46 ) ;
if ( ! V_37 || V_37 > V_46 ) {
F_11 ( V_82 , V_40 ) ;
goto V_45;
}
V_37 = F_44 ( V_15 , V_3 , V_38 , V_41 ) ;
F_4 ( V_15 ) ;
V_45:
if ( V_38 )
F_20 ( V_38 ) ;
return V_37 ;
}
int F_10 ( const T_2 * V_3 , int V_26 [] , int V_46 )
{
int V_21 , V_27 , V_28 = 0 ;
T_1 V_61 ;
if ( F_25 ( V_3 ) )
return 0 ;
for ( V_21 = V_3 -> V_24 - 1 ; V_21 >= 0 ; V_21 -- ) {
if ( ! V_3 -> V_25 [ V_21 ] )
continue;
V_61 = V_83 ;
for ( V_27 = V_35 - 1 ; V_27 >= 0 ; V_27 -- ) {
if ( V_3 -> V_25 [ V_21 ] & V_61 ) {
if ( V_28 < V_46 )
V_26 [ V_28 ] = V_35 * V_21 + V_27 ;
V_28 ++ ;
}
V_61 >>= 1 ;
}
}
if ( V_28 < V_46 ) {
V_26 [ V_28 ] = - 1 ;
V_28 ++ ;
}
return V_28 ;
}
int F_30 ( const int V_26 [] , T_2 * V_3 )
{
int V_21 ;
F_4 ( V_3 ) ;
F_8 ( V_3 ) ;
for ( V_21 = 0 ; V_26 [ V_21 ] != - 1 ; V_21 ++ ) {
if ( F_42 ( V_3 , V_26 [ V_21 ] ) == 0 )
return 0 ;
}
F_4 ( V_3 ) ;
return 1 ;
}
