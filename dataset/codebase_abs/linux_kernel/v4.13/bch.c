static void F_1 ( struct V_1 * V_2 ,
const unsigned char * V_3 , unsigned int V_4 ,
T_1 * V_5 )
{
int V_6 ;
const T_1 * V_7 ;
const int V_8 = F_2 ( V_2 ) - 1 ;
while ( V_4 -- ) {
V_7 = V_2 -> V_9 + ( V_8 + 1 ) * ( ( ( V_5 [ 0 ] >> 24 ) ^ ( * V_3 ++ ) ) & 0xff ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
V_5 [ V_6 ] = ( ( V_5 [ V_6 ] << 8 ) | ( V_5 [ V_6 + 1 ] >> 24 ) ) ^ ( * V_7 ++ ) ;
V_5 [ V_8 ] = ( V_5 [ V_8 ] << 8 ) ^ ( * V_7 ) ;
}
}
static void F_3 ( struct V_1 * V_2 , T_1 * V_10 ,
const T_2 * V_11 )
{
T_2 V_12 [ 4 ] = { 0 , 0 , 0 , 0 } ;
unsigned int V_6 , V_13 = F_2 ( V_2 ) - 1 ;
for ( V_6 = 0 ; V_6 < V_13 ; V_6 ++ , V_11 += 4 )
V_10 [ V_6 ] = ( V_11 [ 0 ] << 24 ) | ( V_11 [ 1 ] << 16 ) | ( V_11 [ 2 ] << 8 ) | V_11 [ 3 ] ;
memcpy ( V_12 , V_11 , F_4 ( V_2 ) - 4 * V_13 ) ;
V_10 [ V_13 ] = ( V_12 [ 0 ] << 24 ) | ( V_12 [ 1 ] << 16 ) | ( V_12 [ 2 ] << 8 ) | V_12 [ 3 ] ;
}
static void F_5 ( struct V_1 * V_2 , T_2 * V_10 ,
const T_1 * V_11 )
{
T_2 V_12 [ 4 ] ;
unsigned int V_6 , V_13 = F_2 ( V_2 ) - 1 ;
for ( V_6 = 0 ; V_6 < V_13 ; V_6 ++ ) {
* V_10 ++ = ( V_11 [ V_6 ] >> 24 ) ;
* V_10 ++ = ( V_11 [ V_6 ] >> 16 ) & 0xff ;
* V_10 ++ = ( V_11 [ V_6 ] >> 8 ) & 0xff ;
* V_10 ++ = ( V_11 [ V_6 ] >> 0 ) & 0xff ;
}
V_12 [ 0 ] = ( V_11 [ V_13 ] >> 24 ) ;
V_12 [ 1 ] = ( V_11 [ V_13 ] >> 16 ) & 0xff ;
V_12 [ 2 ] = ( V_11 [ V_13 ] >> 8 ) & 0xff ;
V_12 [ 3 ] = ( V_11 [ V_13 ] >> 0 ) & 0xff ;
memcpy ( V_10 , V_12 , F_4 ( V_2 ) - 4 * V_13 ) ;
}
void F_6 ( struct V_1 * V_2 , const T_2 * V_3 ,
unsigned int V_4 , T_2 * V_5 )
{
const unsigned int V_8 = F_2 ( V_2 ) - 1 ;
unsigned int V_6 , V_14 ;
unsigned long V_15 ;
T_1 V_16 , V_17 [ V_8 + 1 ] ;
const T_1 * const V_18 = V_2 -> V_9 ;
const T_1 * const V_19 = V_18 + 256 * ( V_8 + 1 ) ;
const T_1 * const V_20 = V_19 + 256 * ( V_8 + 1 ) ;
const T_1 * const V_21 = V_20 + 256 * ( V_8 + 1 ) ;
const T_1 * V_22 , * V_23 , * V_24 , * V_25 , * V_26 ;
if ( V_5 ) {
F_3 ( V_2 , V_2 -> V_27 , V_5 ) ;
} else {
memset ( V_2 -> V_27 , 0 , sizeof( V_17 ) ) ;
}
V_15 = ( ( unsigned long ) V_3 ) & 3 ;
if ( V_15 ) {
V_14 = ( V_4 < ( 4 - V_15 ) ) ? V_4 : 4 - V_15 ;
F_1 ( V_2 , V_3 , V_14 , V_2 -> V_27 ) ;
V_3 += V_14 ;
V_4 -= V_14 ;
}
V_22 = ( T_1 * ) V_3 ;
V_14 = V_4 / 4 ;
V_3 += 4 * V_14 ;
V_4 -= 4 * V_14 ;
memcpy ( V_17 , V_2 -> V_27 , sizeof( V_17 ) ) ;
while ( V_14 -- ) {
V_16 = V_17 [ 0 ] ^ F_7 ( * V_22 ++ ) ;
V_23 = V_18 + ( V_8 + 1 ) * ( ( V_16 >> 0 ) & 0xff ) ;
V_24 = V_19 + ( V_8 + 1 ) * ( ( V_16 >> 8 ) & 0xff ) ;
V_25 = V_20 + ( V_8 + 1 ) * ( ( V_16 >> 16 ) & 0xff ) ;
V_26 = V_21 + ( V_8 + 1 ) * ( ( V_16 >> 24 ) & 0xff ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
V_17 [ V_6 ] = V_17 [ V_6 + 1 ] ^ V_23 [ V_6 ] ^ V_24 [ V_6 ] ^ V_25 [ V_6 ] ^ V_26 [ V_6 ] ;
V_17 [ V_8 ] = V_23 [ V_8 ] ^ V_24 [ V_8 ] ^ V_25 [ V_8 ] ^ V_26 [ V_8 ] ;
}
memcpy ( V_2 -> V_27 , V_17 , sizeof( V_17 ) ) ;
if ( V_4 )
F_1 ( V_2 , V_3 , V_4 , V_2 -> V_27 ) ;
if ( V_5 )
F_5 ( V_2 , V_5 , V_2 -> V_27 ) ;
}
static inline int F_8 ( struct V_1 * V_2 , unsigned int V_28 )
{
const unsigned int V_29 = F_9 ( V_2 ) ;
while ( V_28 >= V_29 ) {
V_28 -= V_29 ;
V_28 = ( V_28 & V_29 ) + ( V_28 >> F_10 ( V_2 ) ) ;
}
return V_28 ;
}
static inline int F_11 ( struct V_1 * V_2 , unsigned int V_28 )
{
const unsigned int V_29 = F_9 ( V_2 ) ;
return ( V_28 < V_29 ) ? V_28 : V_28 - V_29 ;
}
static inline int F_12 ( unsigned int V_30 )
{
return F_13 ( V_30 ) - 1 ;
}
static inline int F_14 ( unsigned int V_31 )
{
V_31 ^= V_31 >> 1 ;
V_31 ^= V_31 >> 2 ;
V_31 = ( V_31 & 0x11111111U ) * 0x11111111U ;
return ( V_31 >> 28 ) & 1 ;
}
static inline unsigned int F_15 ( struct V_1 * V_2 , unsigned int V_32 ,
unsigned int V_33 )
{
return ( V_32 && V_33 ) ? V_2 -> V_34 [ F_11 ( V_2 , V_2 -> V_35 [ V_32 ] +
V_2 -> V_35 [ V_33 ] ) ] : 0 ;
}
static inline unsigned int F_16 ( struct V_1 * V_2 , unsigned int V_32 )
{
return V_32 ? V_2 -> V_34 [ F_11 ( V_2 , 2 * V_2 -> V_35 [ V_32 ] ) ] : 0 ;
}
static inline unsigned int F_17 ( struct V_1 * V_2 , unsigned int V_32 ,
unsigned int V_33 )
{
return V_32 ? V_2 -> V_34 [ F_11 ( V_2 , V_2 -> V_35 [ V_32 ] +
F_9 ( V_2 ) - V_2 -> V_35 [ V_33 ] ) ] : 0 ;
}
static inline unsigned int F_18 ( struct V_1 * V_2 , unsigned int V_32 )
{
return V_2 -> V_34 [ F_9 ( V_2 ) - V_2 -> V_35 [ V_32 ] ] ;
}
static inline unsigned int F_19 ( struct V_1 * V_2 , int V_6 )
{
return V_2 -> V_34 [ F_8 ( V_2 , V_6 ) ] ;
}
static inline int F_20 ( struct V_1 * V_2 , unsigned int V_31 )
{
return V_2 -> V_35 [ V_31 ] ;
}
static inline int F_21 ( struct V_1 * V_2 , unsigned int V_31 )
{
return F_11 ( V_2 , F_9 ( V_2 ) - V_2 -> V_35 [ V_31 ] ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 * V_5 ,
unsigned int * V_36 )
{
int V_6 , V_37 , V_38 ;
unsigned int V_15 ;
T_1 V_30 ;
const int V_39 = F_23 ( V_2 ) ;
V_38 = V_2 -> V_40 ;
V_15 = ( ( unsigned int ) V_38 ) & 31 ;
if ( V_15 )
V_5 [ V_38 / 32 ] &= ~ ( ( 1u << ( 32 - V_15 ) ) - 1 ) ;
memset ( V_36 , 0 , 2 * V_39 * sizeof( * V_36 ) ) ;
do {
V_30 = * V_5 ++ ;
V_38 -= 32 ;
while ( V_30 ) {
V_6 = F_12 ( V_30 ) ;
for ( V_37 = 0 ; V_37 < 2 * V_39 ; V_37 += 2 )
V_36 [ V_37 ] ^= F_19 ( V_2 , ( V_37 + 1 ) * ( V_6 + V_38 ) ) ;
V_30 ^= ( 1 << V_6 ) ;
}
} while ( V_38 > 0 );
for ( V_37 = 0 ; V_37 < V_39 ; V_37 ++ )
V_36 [ 2 * V_37 + 1 ] = F_16 ( V_2 , V_36 [ V_37 ] ) ;
}
static void F_24 ( struct V_41 * V_10 , struct V_41 * V_11 )
{
memcpy ( V_10 , V_11 , F_25 ( V_11 -> F_12 ) ) ;
}
static int F_26 ( struct V_1 * V_2 ,
const unsigned int * V_36 )
{
const unsigned int V_39 = F_23 ( V_2 ) ;
const unsigned int V_29 = F_9 ( V_2 ) ;
unsigned int V_6 , V_37 , V_42 , V_8 , V_43 = 1 , V_44 = V_36 [ 0 ] ;
struct V_41 * V_45 = V_2 -> V_45 ;
struct V_41 * V_46 = V_2 -> V_47 [ 0 ] ;
struct V_41 * V_48 = V_2 -> V_47 [ 1 ] ;
int V_49 , V_50 = - 1 ;
memset ( V_46 , 0 , F_25 ( 2 * V_39 ) ) ;
memset ( V_45 , 0 , F_25 ( 2 * V_39 ) ) ;
V_46 -> F_12 = 0 ;
V_46 -> V_51 [ 0 ] = 1 ;
V_45 -> F_12 = 0 ;
V_45 -> V_51 [ 0 ] = 1 ;
for ( V_6 = 0 ; ( V_6 < V_39 ) && ( V_45 -> F_12 <= V_39 ) ; V_6 ++ ) {
if ( V_44 ) {
V_49 = 2 * V_6 - V_50 ;
F_24 ( V_48 , V_45 ) ;
V_42 = F_20 ( V_2 , V_44 ) + V_29 - F_20 ( V_2 , V_43 ) ;
for ( V_37 = 0 ; V_37 <= V_46 -> F_12 ; V_37 ++ ) {
if ( V_46 -> V_51 [ V_37 ] ) {
V_8 = F_20 ( V_2 , V_46 -> V_51 [ V_37 ] ) ;
V_45 -> V_51 [ V_37 + V_49 ] ^= F_19 ( V_2 , V_42 + V_8 ) ;
}
}
V_42 = V_46 -> F_12 + V_49 ;
if ( V_42 > V_45 -> F_12 ) {
V_45 -> F_12 = V_42 ;
F_24 ( V_46 , V_48 ) ;
V_43 = V_44 ;
V_50 = 2 * V_6 ;
}
}
if ( V_6 < V_39 - 1 ) {
V_44 = V_36 [ 2 * V_6 + 2 ] ;
for ( V_37 = 1 ; V_37 <= V_45 -> F_12 ; V_37 ++ )
V_44 ^= F_15 ( V_2 , V_45 -> V_51 [ V_37 ] , V_36 [ 2 * V_6 + 2 - V_37 ] ) ;
}
}
F_27 ( L_1 , F_28 ( V_45 ) ) ;
return ( V_45 -> F_12 > V_39 ) ? - 1 : ( int ) V_45 -> F_12 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int * V_52 ,
unsigned int * V_53 , int V_54 )
{
const int V_15 = F_10 ( V_2 ) ;
unsigned int V_42 , V_55 ;
int V_56 , V_51 , V_17 , V_7 , V_49 , V_57 [ V_15 ] ;
V_49 = 0 ;
V_55 = 1 << V_15 ;
for ( V_51 = 0 ; V_51 < V_15 ; V_51 ++ ) {
V_56 = 0 ;
V_7 = V_51 - V_49 ;
for ( V_17 = V_7 ; V_17 < V_15 ; V_17 ++ ) {
if ( V_52 [ V_17 ] & V_55 ) {
if ( V_17 != V_7 ) {
V_42 = V_52 [ V_17 ] ;
V_52 [ V_17 ] = V_52 [ V_7 ] ;
V_52 [ V_7 ] = V_42 ;
}
V_56 = V_17 + 1 ;
break;
}
}
if ( V_56 ) {
V_42 = V_52 [ V_7 ] ;
for ( V_17 = V_56 ; V_17 < V_15 ; V_17 ++ ) {
if ( V_52 [ V_17 ] & V_55 )
V_52 [ V_17 ] ^= V_42 ;
}
} else {
V_57 [ V_49 ++ ] = V_51 ;
}
V_55 >>= 1 ;
}
if ( V_49 > 0 ) {
V_7 = V_49 ;
for ( V_17 = V_15 - 1 ; V_17 >= 0 ; V_17 -- ) {
if ( ( V_17 > V_15 - 1 - V_49 ) && V_52 [ V_17 ] )
return 0 ;
V_52 [ V_17 ] = ( V_7 && ( V_17 == V_57 [ V_7 - 1 ] ) ) ?
V_7 -- , 1u << ( V_15 - V_17 ) : V_52 [ V_17 - V_7 ] ;
}
}
if ( V_54 != ( 1 << V_49 ) )
return 0 ;
for ( V_7 = 0 ; V_7 < V_54 ; V_7 ++ ) {
for ( V_51 = 0 ; V_51 < V_49 ; V_51 ++ )
V_52 [ V_57 [ V_51 ] ] = ( V_52 [ V_57 [ V_51 ] ] & ~ 1 ) | ( ( V_7 >> V_51 ) & 1 ) ;
V_42 = 0 ;
for ( V_17 = V_15 - 1 ; V_17 >= 0 ; V_17 -- ) {
V_55 = V_52 [ V_17 ] & ( V_42 | 1 ) ;
V_42 |= F_14 ( V_55 ) << ( V_15 - V_17 ) ;
}
V_53 [ V_7 ] = V_42 >> 1 ;
}
return V_54 ;
}
static int F_30 ( struct V_1 * V_2 , unsigned int V_32 ,
unsigned int V_33 , unsigned int V_51 ,
unsigned int * V_58 )
{
int V_6 , V_37 , V_49 ;
const int V_15 = F_10 ( V_2 ) ;
unsigned int V_55 = 0xff , V_39 , V_52 [ 16 ] = { 0 ,} ;
V_37 = F_20 ( V_2 , V_33 ) ;
V_49 = F_20 ( V_2 , V_32 ) ;
V_52 [ 0 ] = V_51 ;
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
V_52 [ V_6 + 1 ] = V_2 -> V_34 [ 4 * V_6 ] ^
( V_32 ? V_2 -> V_34 [ F_11 ( V_2 , V_49 ) ] : 0 ) ^
( V_33 ? V_2 -> V_34 [ F_11 ( V_2 , V_37 ) ] : 0 ) ;
V_37 ++ ;
V_49 += 2 ;
}
for ( V_37 = 8 ; V_37 != 0 ; V_37 >>= 1 , V_55 ^= ( V_55 << V_37 ) ) {
for ( V_49 = 0 ; V_49 < 16 ; V_49 = ( V_49 + V_37 + 1 ) & ~ V_37 ) {
V_39 = ( ( V_52 [ V_49 ] >> V_37 ) ^ V_52 [ V_49 + V_37 ] ) & V_55 ;
V_52 [ V_49 ] ^= ( V_39 << V_37 ) ;
V_52 [ V_49 + V_37 ] ^= V_39 ;
}
}
return F_29 ( V_2 , V_52 , V_58 , 4 ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_41 * V_30 ,
unsigned int * V_58 )
{
int V_29 = 0 ;
if ( V_30 -> V_51 [ 0 ] )
V_58 [ V_29 ++ ] = F_11 ( V_2 , F_9 ( V_2 ) - V_2 -> V_35 [ V_30 -> V_51 [ 0 ] ] +
V_2 -> V_35 [ V_30 -> V_51 [ 1 ] ] ) ;
return V_29 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_41 * V_30 ,
unsigned int * V_58 )
{
int V_29 = 0 , V_6 , V_59 , V_60 , V_61 ;
unsigned int V_62 , V_28 , V_17 ;
if ( V_30 -> V_51 [ 0 ] && V_30 -> V_51 [ 1 ] ) {
V_59 = V_2 -> V_35 [ V_30 -> V_51 [ 0 ] ] ;
V_60 = V_2 -> V_35 [ V_30 -> V_51 [ 1 ] ] ;
V_61 = V_2 -> V_35 [ V_30 -> V_51 [ 2 ] ] ;
V_62 = F_19 ( V_2 , V_59 + V_61 + 2 * ( F_9 ( V_2 ) - V_60 ) ) ;
V_17 = 0 ;
V_28 = V_62 ;
while ( V_28 ) {
V_6 = F_12 ( V_28 ) ;
V_17 ^= V_2 -> V_63 [ V_6 ] ;
V_28 ^= ( 1 << V_6 ) ;
}
if ( ( F_16 ( V_2 , V_17 ) ^ V_17 ) == V_62 ) {
V_58 [ V_29 ++ ] = F_8 ( V_2 , 2 * F_9 ( V_2 ) - V_60 -
V_2 -> V_35 [ V_17 ] + V_61 ) ;
V_58 [ V_29 ++ ] = F_8 ( V_2 , 2 * F_9 ( V_2 ) - V_60 -
V_2 -> V_35 [ V_17 ^ 1 ] + V_61 ) ;
}
}
return V_29 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_41 * V_30 ,
unsigned int * V_58 )
{
int V_6 , V_29 = 0 ;
unsigned int V_32 , V_33 , V_51 , V_64 , V_65 , V_66 , V_67 , V_42 [ 4 ] ;
if ( V_30 -> V_51 [ 0 ] ) {
V_67 = V_30 -> V_51 [ 3 ] ;
V_66 = F_17 ( V_2 , V_30 -> V_51 [ 0 ] , V_67 ) ;
V_65 = F_17 ( V_2 , V_30 -> V_51 [ 1 ] , V_67 ) ;
V_64 = F_17 ( V_2 , V_30 -> V_51 [ 2 ] , V_67 ) ;
V_51 = F_15 ( V_2 , V_64 , V_66 ) ;
V_33 = F_15 ( V_2 , V_64 , V_65 ) ^ V_66 ;
V_32 = F_16 ( V_2 , V_64 ) ^ V_65 ;
if ( F_30 ( V_2 , V_32 , V_33 , V_51 , V_42 ) == 4 ) {
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
if ( V_42 [ V_6 ] != V_64 )
V_58 [ V_29 ++ ] = F_21 ( V_2 , V_42 [ V_6 ] ) ;
}
}
}
return V_29 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_41 * V_30 ,
unsigned int * V_58 )
{
int V_6 , V_8 , V_29 = 0 ;
unsigned int V_32 , V_33 , V_51 , V_44 , V_68 = 0 , V_69 , V_64 , V_65 , V_66 , V_70 ;
if ( V_30 -> V_51 [ 0 ] == 0 )
return 0 ;
V_70 = V_30 -> V_51 [ 4 ] ;
V_44 = F_17 ( V_2 , V_30 -> V_51 [ 0 ] , V_70 ) ;
V_51 = F_17 ( V_2 , V_30 -> V_51 [ 1 ] , V_70 ) ;
V_33 = F_17 ( V_2 , V_30 -> V_51 [ 2 ] , V_70 ) ;
V_32 = F_17 ( V_2 , V_30 -> V_51 [ 3 ] , V_70 ) ;
if ( V_32 ) {
if ( V_51 ) {
V_69 = F_17 ( V_2 , V_51 , V_32 ) ;
V_8 = F_20 ( V_2 , V_69 ) ;
V_8 += ( V_8 & 1 ) ? F_9 ( V_2 ) : 0 ;
V_68 = F_19 ( V_2 , V_8 / 2 ) ;
V_44 = F_19 ( V_2 , 2 * V_8 ) ^ F_15 ( V_2 , V_33 , V_69 ) ^ V_44 ;
V_33 = F_15 ( V_2 , V_32 , V_68 ) ^ V_33 ;
}
if ( V_44 == 0 )
return 0 ;
V_66 = F_18 ( V_2 , V_44 ) ;
V_65 = F_17 ( V_2 , V_32 , V_44 ) ;
V_64 = F_17 ( V_2 , V_33 , V_44 ) ;
} else {
V_66 = V_44 ;
V_65 = V_51 ;
V_64 = V_33 ;
}
if ( F_30 ( V_2 , V_64 , V_65 , V_66 , V_58 ) == 4 ) {
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
V_69 = V_32 ? F_18 ( V_2 , V_58 [ V_6 ] ) : V_58 [ V_6 ] ;
V_58 [ V_6 ] = F_21 ( V_2 , V_69 ^ V_68 ) ;
}
V_29 = 4 ;
}
return V_29 ;
}
static void F_35 ( struct V_1 * V_2 ,
const struct V_41 * V_32 , int * V_71 )
{
int V_6 , V_44 = V_32 -> F_12 , V_8 = F_9 ( V_2 ) - F_20 ( V_2 , V_32 -> V_51 [ V_32 -> F_12 ] ) ;
for ( V_6 = 0 ; V_6 < V_44 ; V_6 ++ )
V_71 [ V_6 ] = V_32 -> V_51 [ V_6 ] ? F_11 ( V_2 , F_20 ( V_2 , V_32 -> V_51 [ V_6 ] ) + V_8 ) : - 1 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_41 * V_32 ,
const struct V_41 * V_33 , int * V_71 )
{
int V_72 , V_7 , V_15 ;
unsigned int V_6 , V_37 , * V_51 = V_32 -> V_51 ;
const unsigned int V_44 = V_33 -> F_12 ;
if ( V_32 -> F_12 < V_44 )
return;
if ( ! V_71 ) {
V_71 = V_2 -> V_73 ;
F_35 ( V_2 , V_33 , V_71 ) ;
}
for ( V_37 = V_32 -> F_12 ; V_37 >= V_44 ; V_37 -- ) {
if ( V_51 [ V_37 ] ) {
V_72 = F_20 ( V_2 , V_51 [ V_37 ] ) ;
V_7 = V_37 - V_44 ;
for ( V_6 = 0 ; V_6 < V_44 ; V_6 ++ , V_7 ++ ) {
V_15 = V_71 [ V_6 ] ;
if ( V_15 >= 0 )
V_51 [ V_7 ] ^= V_2 -> V_34 [ F_11 ( V_2 ,
V_15 + V_72 ) ] ;
}
}
}
V_32 -> F_12 = V_44 - 1 ;
while ( ! V_51 [ V_32 -> F_12 ] && V_32 -> F_12 )
V_32 -> F_12 -- ;
}
static void F_37 ( struct V_1 * V_2 , struct V_41 * V_32 ,
const struct V_41 * V_33 , struct V_41 * V_74 )
{
if ( V_32 -> F_12 >= V_33 -> F_12 ) {
V_74 -> F_12 = V_32 -> F_12 - V_33 -> F_12 ;
F_36 ( V_2 , V_32 , V_33 , NULL ) ;
memcpy ( V_74 -> V_51 , & V_32 -> V_51 [ V_33 -> F_12 ] , ( 1 + V_74 -> F_12 ) *sizeof( unsigned int ) ) ;
} else {
V_74 -> F_12 = 0 ;
V_74 -> V_51 [ 0 ] = 0 ;
}
}
static struct V_41 * F_38 ( struct V_1 * V_2 , struct V_41 * V_32 ,
struct V_41 * V_33 )
{
struct V_41 * V_42 ;
F_27 ( L_2 , F_28 ( V_32 ) , F_28 ( V_33 ) ) ;
if ( V_32 -> F_12 < V_33 -> F_12 ) {
V_42 = V_33 ;
V_33 = V_32 ;
V_32 = V_42 ;
}
while ( V_33 -> F_12 > 0 ) {
F_36 ( V_2 , V_32 , V_33 , NULL ) ;
V_42 = V_33 ;
V_33 = V_32 ;
V_32 = V_42 ;
}
F_27 ( L_3 , F_28 ( V_32 ) ) ;
return V_32 ;
}
static void F_39 ( struct V_1 * V_2 , int V_49 ,
const struct V_41 * V_69 , struct V_41 * V_75 ,
struct V_41 * V_76 )
{
const int V_15 = F_10 ( V_2 ) ;
int V_6 , V_37 ;
V_75 -> F_12 = 1 ;
V_75 -> V_51 [ 0 ] = 0 ;
V_75 -> V_51 [ 1 ] = V_2 -> V_34 [ V_49 ] ;
V_76 -> F_12 = 0 ;
memset ( V_76 , 0 , F_25 ( V_69 -> F_12 ) ) ;
F_35 ( V_2 , V_69 , V_2 -> V_73 ) ;
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
for ( V_37 = V_75 -> F_12 ; V_37 >= 0 ; V_37 -- ) {
V_76 -> V_51 [ V_37 ] ^= V_75 -> V_51 [ V_37 ] ;
V_75 -> V_51 [ 2 * V_37 ] = F_16 ( V_2 , V_75 -> V_51 [ V_37 ] ) ;
V_75 -> V_51 [ 2 * V_37 + 1 ] = 0 ;
}
if ( V_75 -> F_12 > V_76 -> F_12 )
V_76 -> F_12 = V_75 -> F_12 ;
if ( V_6 < V_15 - 1 ) {
V_75 -> F_12 *= 2 ;
F_36 ( V_2 , V_75 , V_69 , V_2 -> V_73 ) ;
}
}
while ( ! V_76 -> V_51 [ V_76 -> F_12 ] && V_76 -> F_12 )
V_76 -> F_12 -- ;
F_27 ( L_4 , V_49 , F_28 ( V_76 ) ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_49 , struct V_41 * V_69 ,
struct V_41 * * V_77 , struct V_41 * * V_78 )
{
struct V_41 * V_79 = V_2 -> V_47 [ 0 ] ;
struct V_41 * V_74 = V_2 -> V_47 [ 1 ] ;
struct V_41 * V_80 = V_2 -> V_47 [ 2 ] ;
struct V_41 * V_75 = V_2 -> V_47 [ 3 ] ;
struct V_41 * V_81 ;
F_27 ( L_5 , F_28 ( V_69 ) ) ;
* V_77 = V_69 ;
* V_78 = NULL ;
F_39 ( V_2 , V_49 , V_69 , V_75 , V_80 ) ;
if ( V_80 -> F_12 > 0 ) {
F_24 ( V_79 , V_69 ) ;
V_81 = F_38 ( V_2 , V_79 , V_80 ) ;
if ( V_81 -> F_12 < V_69 -> F_12 ) {
F_37 ( V_2 , V_69 , V_81 , V_74 ) ;
* V_78 = & ( (struct V_82 * ) V_69 ) [ V_81 -> F_12 ] . V_30 ;
F_24 ( * V_77 , V_81 ) ;
F_24 ( * V_78 , V_74 ) ;
}
}
}
static int F_41 ( struct V_1 * V_2 , unsigned int V_49 ,
struct V_41 * V_30 , unsigned int * V_58 )
{
int V_83 ;
struct V_41 * V_84 , * V_79 ;
switch ( V_30 -> F_12 ) {
case 1 :
V_83 = F_31 ( V_2 , V_30 , V_58 ) ;
break;
case 2 :
V_83 = F_32 ( V_2 , V_30 , V_58 ) ;
break;
case 3 :
V_83 = F_33 ( V_2 , V_30 , V_58 ) ;
break;
case 4 :
V_83 = F_34 ( V_2 , V_30 , V_58 ) ;
break;
default:
V_83 = 0 ;
if ( V_30 -> F_12 && ( V_49 <= F_10 ( V_2 ) ) ) {
F_40 ( V_2 , V_49 , V_30 , & V_84 , & V_79 ) ;
if ( V_84 )
V_83 += F_41 ( V_2 , V_49 + 1 , V_84 , V_58 ) ;
if ( V_79 )
V_83 += F_41 ( V_2 , V_49 + 1 , V_79 , V_58 + V_83 ) ;
}
break;
}
return V_83 ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int V_4 ,
struct V_41 * V_7 , unsigned int * V_58 )
{
int V_15 ;
unsigned int V_6 , V_37 , V_36 , V_85 , V_86 = 0 ;
const unsigned int V_49 = 8 * V_4 + V_2 -> V_40 ;
F_35 ( V_2 , V_7 , V_2 -> V_73 ) ;
V_2 -> V_73 [ V_7 -> F_12 ] = 0 ;
V_85 = F_17 ( V_2 , V_7 -> V_51 [ 0 ] , V_7 -> V_51 [ V_7 -> F_12 ] ) ;
for ( V_6 = F_9 ( V_2 ) - V_49 + 1 ; V_6 <= F_9 ( V_2 ) ; V_6 ++ ) {
for ( V_37 = 1 , V_36 = V_85 ; V_37 <= V_7 -> F_12 ; V_37 ++ ) {
V_15 = V_2 -> V_73 [ V_37 ] ;
if ( V_15 >= 0 )
V_36 ^= F_19 ( V_2 , V_15 + V_37 * V_6 ) ;
}
if ( V_36 == 0 ) {
V_58 [ V_86 ++ ] = F_9 ( V_2 ) - V_6 ;
if ( V_86 == V_7 -> F_12 )
break;
}
}
return ( V_86 == V_7 -> F_12 ) ? V_86 : 0 ;
}
int F_43 ( struct V_1 * V_2 , const T_2 * V_3 , unsigned int V_4 ,
const T_2 * V_87 , const T_2 * V_88 ,
const unsigned int * V_36 , unsigned int * V_89 )
{
const unsigned int V_90 = F_2 ( V_2 ) ;
unsigned int V_91 ;
int V_6 , V_92 , V_93 ;
T_1 V_94 ;
if ( 8 * V_4 > ( V_2 -> V_29 - V_2 -> V_40 ) )
return - V_95 ;
if ( ! V_36 ) {
if ( ! V_88 ) {
if ( ! V_3 || ! V_87 )
return - V_95 ;
F_6 ( V_2 , V_3 , V_4 , NULL ) ;
} else {
F_3 ( V_2 , V_2 -> V_27 , V_88 ) ;
}
if ( V_87 ) {
F_3 ( V_2 , V_2 -> V_96 , V_87 ) ;
for ( V_6 = 0 , V_94 = 0 ; V_6 < ( int ) V_90 ; V_6 ++ ) {
V_2 -> V_27 [ V_6 ] ^= V_2 -> V_96 [ V_6 ] ;
V_94 |= V_2 -> V_27 [ V_6 ] ;
}
if ( ! V_94 )
return 0 ;
}
F_22 ( V_2 , V_2 -> V_27 , V_2 -> V_36 ) ;
V_36 = V_2 -> V_36 ;
}
V_92 = F_26 ( V_2 , V_36 ) ;
if ( V_92 > 0 ) {
V_93 = F_41 ( V_2 , 1 , V_2 -> V_45 , V_89 ) ;
if ( V_92 != V_93 )
V_92 = - 1 ;
}
if ( V_92 > 0 ) {
V_91 = ( V_4 * 8 ) + V_2 -> V_40 ;
for ( V_6 = 0 ; V_6 < V_92 ; V_6 ++ ) {
if ( V_89 [ V_6 ] >= V_91 ) {
V_92 = - 1 ;
break;
}
V_89 [ V_6 ] = V_91 - 1 - V_89 [ V_6 ] ;
V_89 [ V_6 ] = ( V_89 [ V_6 ] & ~ 7 ) | ( 7 - ( V_89 [ V_6 ] & 7 ) ) ;
}
}
return ( V_92 >= 0 ) ? V_92 : - V_97 ;
}
static int F_44 ( struct V_1 * V_2 , unsigned int V_30 )
{
unsigned int V_6 , V_31 = 1 ;
const unsigned int V_49 = 1 << F_12 ( V_30 ) ;
if ( V_49 != ( 1u << F_10 ( V_2 ) ) )
return - 1 ;
for ( V_6 = 0 ; V_6 < F_9 ( V_2 ) ; V_6 ++ ) {
V_2 -> V_34 [ V_6 ] = V_31 ;
V_2 -> V_35 [ V_31 ] = V_6 ;
if ( V_6 && ( V_31 == 1 ) )
return - 1 ;
V_31 <<= 1 ;
if ( V_31 & V_49 )
V_31 ^= V_30 ;
}
V_2 -> V_34 [ F_9 ( V_2 ) ] = 1 ;
V_2 -> V_35 [ 0 ] = 0 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , const T_1 * V_77 )
{
int V_6 , V_37 , V_33 , V_44 ;
T_1 V_3 , V_98 , V_99 , * V_100 ;
const int V_8 = F_2 ( V_2 ) ;
const int V_101 = F_46 ( V_2 -> V_40 + 1 , 32 ) ;
const int V_102 = F_46 ( V_2 -> V_40 , 32 ) ;
memset ( V_2 -> V_9 , 0 , 4 * 256 * V_8 * sizeof( * V_2 -> V_9 ) ) ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 ++ ) {
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ ) {
V_100 = V_2 -> V_9 + ( V_33 * 256 + V_6 ) * V_8 ;
V_3 = V_6 << ( 8 * V_33 ) ;
while ( V_3 ) {
V_44 = F_12 ( V_3 ) ;
V_3 ^= V_77 [ 0 ] >> ( 31 - V_44 ) ;
for ( V_37 = 0 ; V_37 < V_102 ; V_37 ++ ) {
V_98 = ( V_44 < 31 ) ? V_77 [ V_37 ] << ( V_44 + 1 ) : 0 ;
V_99 = ( V_37 + 1 < V_101 ) ?
V_77 [ V_37 + 1 ] >> ( 31 - V_44 ) : 0 ;
V_100 [ V_37 ] ^= V_98 | V_99 ;
}
}
}
}
}
static int F_47 ( struct V_1 * V_2 )
{
const int V_15 = F_10 ( V_2 ) ;
int V_6 , V_37 , V_17 ;
unsigned int V_94 , V_31 , V_103 , V_104 , V_105 = 0 , V_106 [ V_15 ] ;
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
for ( V_37 = 0 , V_94 = 0 ; V_37 < V_15 ; V_37 ++ )
V_94 ^= F_19 ( V_2 , V_6 * ( 1 << V_37 ) ) ;
if ( V_94 ) {
V_105 = V_2 -> V_34 [ V_6 ] ;
break;
}
}
V_104 = V_15 ;
memset ( V_106 , 0 , sizeof( V_106 ) ) ;
for ( V_31 = 0 ; ( V_31 <= F_9 ( V_2 ) ) && V_104 ; V_31 ++ ) {
V_103 = F_16 ( V_2 , V_31 ) ^ V_31 ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_17 = F_20 ( V_2 , V_103 ) ;
if ( V_103 && ( V_17 < V_15 ) && ! V_106 [ V_17 ] ) {
V_2 -> V_63 [ V_17 ] = V_31 ;
V_106 [ V_17 ] = 1 ;
V_104 -- ;
F_27 ( L_6 , V_17 , V_31 ) ;
break;
}
V_103 ^= V_105 ;
}
}
return V_104 ? - 1 : 0 ;
}
static void * F_48 ( T_3 V_107 , int * V_92 )
{
void * V_108 ;
V_108 = F_49 ( V_107 , V_109 ) ;
if ( V_108 == NULL )
* V_92 = 1 ;
return V_108 ;
}
static T_1 * F_50 ( struct V_1 * V_2 )
{
const unsigned int V_15 = F_10 ( V_2 ) ;
const unsigned int V_39 = F_23 ( V_2 ) ;
int V_29 , V_92 = 0 ;
unsigned int V_6 , V_37 , V_91 , V_17 , V_110 , * V_58 ;
struct V_41 * V_77 ;
T_1 * V_111 ;
V_77 = F_48 ( F_25 ( V_15 * V_39 ) , & V_92 ) ;
V_58 = F_48 ( ( V_2 -> V_29 + 1 ) * sizeof( * V_58 ) , & V_92 ) ;
V_111 = F_48 ( F_46 ( V_15 * V_39 + 1 , 32 ) * sizeof( * V_111 ) , & V_92 ) ;
if ( V_92 ) {
F_51 ( V_111 ) ;
V_111 = NULL ;
goto V_112;
}
memset ( V_58 , 0 , ( V_2 -> V_29 + 1 ) * sizeof( * V_58 ) ) ;
for ( V_6 = 0 ; V_6 < V_39 ; V_6 ++ ) {
for ( V_37 = 0 , V_17 = 2 * V_6 + 1 ; V_37 < V_15 ; V_37 ++ ) {
V_58 [ V_17 ] = 1 ;
V_17 = F_11 ( V_2 , 2 * V_17 ) ;
}
}
V_77 -> F_12 = 0 ;
V_77 -> V_51 [ 0 ] = 1 ;
for ( V_6 = 0 ; V_6 < F_9 ( V_2 ) ; V_6 ++ ) {
if ( V_58 [ V_6 ] ) {
V_17 = V_2 -> V_34 [ V_6 ] ;
V_77 -> V_51 [ V_77 -> F_12 + 1 ] = 1 ;
for ( V_37 = V_77 -> F_12 ; V_37 > 0 ; V_37 -- )
V_77 -> V_51 [ V_37 ] = F_15 ( V_2 , V_77 -> V_51 [ V_37 ] , V_17 ) ^ V_77 -> V_51 [ V_37 - 1 ] ;
V_77 -> V_51 [ 0 ] = F_15 ( V_2 , V_77 -> V_51 [ 0 ] , V_17 ) ;
V_77 -> F_12 ++ ;
}
}
V_29 = V_77 -> F_12 + 1 ;
V_6 = 0 ;
while ( V_29 > 0 ) {
V_91 = ( V_29 > 32 ) ? 32 : V_29 ;
for ( V_37 = 0 , V_110 = 0 ; V_37 < V_91 ; V_37 ++ ) {
if ( V_77 -> V_51 [ V_29 - 1 - V_37 ] )
V_110 |= 1u << ( 31 - V_37 ) ;
}
V_111 [ V_6 ++ ] = V_110 ;
V_29 -= V_91 ;
}
V_2 -> V_40 = V_77 -> F_12 ;
V_112:
F_51 ( V_77 ) ;
F_51 ( V_58 ) ;
return V_111 ;
}
struct V_1 * F_52 ( int V_15 , int V_39 , unsigned int V_113 )
{
int V_92 = 0 ;
unsigned int V_6 , V_114 ;
T_1 * V_111 ;
struct V_1 * V_2 = NULL ;
const int V_115 = 5 ;
const int V_116 = 15 ;
static const unsigned int V_117 [] = {
0x25 , 0x43 , 0x83 , 0x11d , 0x211 , 0x409 , 0x805 , 0x1053 , 0x201b ,
0x402b , 0x8003 ,
} ;
#if F_53 ( V_118 )
if ( ( V_15 != ( V_119 ) ) || ( V_39 != ( V_120 ) ) ) {
F_54 ( V_121 L_7
L_8 ,
V_119 , V_120 ) ;
goto V_122;
}
#endif
if ( ( V_15 < V_115 ) || ( V_15 > V_116 ) )
goto V_122;
if ( ( V_39 < 1 ) || ( V_15 * V_39 >= ( ( 1 << V_15 ) - 1 ) ) )
goto V_122;
if ( V_113 == 0 )
V_113 = V_117 [ V_15 - V_115 ] ;
V_2 = F_55 ( sizeof( * V_2 ) , V_109 ) ;
if ( V_2 == NULL )
goto V_122;
V_2 -> V_15 = V_15 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_29 = ( 1 << V_15 ) - 1 ;
V_114 = F_46 ( V_15 * V_39 , 32 ) ;
V_2 -> V_123 = F_46 ( V_15 * V_39 , 8 ) ;
V_2 -> V_34 = F_48 ( ( 1 + V_2 -> V_29 ) * sizeof( * V_2 -> V_34 ) , & V_92 ) ;
V_2 -> V_35 = F_48 ( ( 1 + V_2 -> V_29 ) * sizeof( * V_2 -> V_35 ) , & V_92 ) ;
V_2 -> V_9 = F_48 ( V_114 * 1024 * sizeof( * V_2 -> V_9 ) , & V_92 ) ;
V_2 -> V_27 = F_48 ( V_114 * sizeof( * V_2 -> V_27 ) , & V_92 ) ;
V_2 -> V_96 = F_48 ( V_114 * sizeof( * V_2 -> V_96 ) , & V_92 ) ;
V_2 -> V_63 = F_48 ( V_15 * sizeof( * V_2 -> V_63 ) , & V_92 ) ;
V_2 -> V_36 = F_48 ( 2 * V_39 * sizeof( * V_2 -> V_36 ) , & V_92 ) ;
V_2 -> V_73 = F_48 ( 2 * V_39 * sizeof( * V_2 -> V_73 ) , & V_92 ) ;
V_2 -> V_45 = F_48 ( ( V_39 + 1 ) * sizeof( struct V_82 ) , & V_92 ) ;
for ( V_6 = 0 ; V_6 < F_56 ( V_2 -> V_47 ) ; V_6 ++ )
V_2 -> V_47 [ V_6 ] = F_48 ( F_25 ( 2 * V_39 ) , & V_92 ) ;
if ( V_92 )
goto V_122;
V_92 = F_44 ( V_2 , V_113 ) ;
if ( V_92 )
goto V_122;
V_111 = F_50 ( V_2 ) ;
if ( V_111 == NULL )
goto V_122;
F_45 ( V_2 , V_111 ) ;
F_51 ( V_111 ) ;
V_92 = F_47 ( V_2 ) ;
if ( V_92 )
goto V_122;
return V_2 ;
V_122:
F_57 ( V_2 ) ;
return NULL ;
}
void F_57 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
if ( V_2 ) {
F_51 ( V_2 -> V_34 ) ;
F_51 ( V_2 -> V_35 ) ;
F_51 ( V_2 -> V_9 ) ;
F_51 ( V_2 -> V_27 ) ;
F_51 ( V_2 -> V_96 ) ;
F_51 ( V_2 -> V_63 ) ;
F_51 ( V_2 -> V_36 ) ;
F_51 ( V_2 -> V_73 ) ;
F_51 ( V_2 -> V_45 ) ;
for ( V_6 = 0 ; V_6 < F_56 ( V_2 -> V_47 ) ; V_6 ++ )
F_51 ( V_2 -> V_47 [ V_6 ] ) ;
F_51 ( V_2 ) ;
}
}
