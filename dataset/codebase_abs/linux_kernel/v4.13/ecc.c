static inline const struct V_1 * F_1 ( unsigned int V_2 )
{
switch ( V_2 ) {
case V_3 :
return V_4 ? NULL : & V_5 ;
case V_6 :
return & V_7 ;
default:
return NULL ;
}
}
static T_1 * F_2 ( unsigned int V_8 )
{
T_2 V_9 = V_8 * sizeof( T_1 ) ;
if ( ! V_9 )
return NULL ;
return F_3 ( V_9 , V_10 ) ;
}
static void F_4 ( T_1 * V_11 )
{
F_5 ( V_11 ) ;
}
static struct V_12 * F_6 ( unsigned int V_8 )
{
struct V_12 * V_13 = F_3 ( sizeof( * V_13 ) , V_10 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_14 = F_2 ( V_8 ) ;
if ( ! V_13 -> V_14 )
goto V_15;
V_13 -> V_16 = F_2 ( V_8 ) ;
if ( ! V_13 -> V_16 )
goto V_17;
V_13 -> V_8 = V_8 ;
return V_13 ;
V_17:
F_4 ( V_13 -> V_14 ) ;
V_15:
F_7 ( V_13 ) ;
return NULL ;
}
static void F_8 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return;
F_5 ( V_13 -> V_14 ) ;
F_5 ( V_13 -> V_16 ) ;
F_5 ( V_13 ) ;
}
static void F_9 ( T_1 * V_18 , unsigned int V_8 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 ; V_19 ++ )
V_18 [ V_19 ] = 0 ;
}
static bool F_10 ( const T_1 * V_18 , unsigned int V_8 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 ; V_19 ++ ) {
if ( V_18 [ V_19 ] )
return false ;
}
return true ;
}
static T_1 F_11 ( const T_1 * V_18 , unsigned int V_20 )
{
return ( V_18 [ V_20 / 64 ] & ( ( T_1 ) 1 << ( V_20 % 64 ) ) ) ;
}
static unsigned int F_12 ( const T_1 * V_18 , unsigned int V_8 )
{
int V_19 ;
for ( V_19 = V_8 - 1 ; V_19 >= 0 && V_18 [ V_19 ] == 0 ; V_19 -- ) ;
return ( V_19 + 1 ) ;
}
static unsigned int F_13 ( const T_1 * V_18 , unsigned int V_8 )
{
unsigned int V_19 , V_21 ;
T_1 V_22 ;
V_21 = F_12 ( V_18 , V_8 ) ;
if ( V_21 == 0 )
return 0 ;
V_22 = V_18 [ V_21 - 1 ] ;
for ( V_19 = 0 ; V_22 ; V_19 ++ )
V_22 >>= 1 ;
return ( ( V_21 - 1 ) * 64 + V_19 ) ;
}
static void F_14 ( T_1 * V_23 , const T_1 * V_24 , unsigned int V_8 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 ; V_19 ++ )
V_23 [ V_19 ] = V_24 [ V_19 ] ;
}
static int F_15 ( const T_1 * V_25 , const T_1 * V_26 , unsigned int V_8 )
{
int V_19 ;
for ( V_19 = V_8 - 1 ; V_19 >= 0 ; V_19 -- ) {
if ( V_25 [ V_19 ] > V_26 [ V_19 ] )
return 1 ;
else if ( V_25 [ V_19 ] < V_26 [ V_19 ] )
return - 1 ;
}
return 0 ;
}
static T_1 F_16 ( T_1 * V_27 , const T_1 * V_28 , unsigned int V_29 ,
unsigned int V_8 )
{
T_1 V_30 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 ; V_19 ++ ) {
T_1 V_31 = V_28 [ V_19 ] ;
V_27 [ V_19 ] = ( V_31 << V_29 ) | V_30 ;
V_30 = V_31 >> ( 64 - V_29 ) ;
}
return V_30 ;
}
static void F_17 ( T_1 * V_18 , unsigned int V_8 )
{
T_1 * V_32 = V_18 ;
T_1 V_30 = 0 ;
V_18 += V_8 ;
while ( V_18 -- > V_32 ) {
T_1 V_31 = * V_18 ;
* V_18 = ( V_31 >> 1 ) | V_30 ;
V_30 = V_31 << 63 ;
}
}
static T_1 F_18 ( T_1 * V_27 , const T_1 * V_25 , const T_1 * V_26 ,
unsigned int V_8 )
{
T_1 V_30 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 ; V_19 ++ ) {
T_1 V_33 ;
V_33 = V_25 [ V_19 ] + V_26 [ V_19 ] + V_30 ;
if ( V_33 != V_25 [ V_19 ] )
V_30 = ( V_33 < V_25 [ V_19 ] ) ;
V_27 [ V_19 ] = V_33 ;
}
return V_30 ;
}
static T_1 F_19 ( T_1 * V_27 , const T_1 * V_25 , const T_1 * V_26 ,
unsigned int V_8 )
{
T_1 V_34 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 ; V_19 ++ ) {
T_1 V_35 ;
V_35 = V_25 [ V_19 ] - V_26 [ V_19 ] - V_34 ;
if ( V_35 != V_25 [ V_19 ] )
V_34 = ( V_35 > V_25 [ V_19 ] ) ;
V_27 [ V_19 ] = V_35 ;
}
return V_34 ;
}
static T_3 F_20 ( T_1 V_25 , T_1 V_26 )
{
T_1 V_36 = V_25 & 0xffffffffull ;
T_1 V_37 = V_25 >> 32 ;
T_1 V_38 = V_26 & 0xffffffffull ;
T_1 V_39 = V_26 >> 32 ;
T_1 V_40 = V_36 * V_38 ;
T_1 V_41 = V_36 * V_39 ;
T_1 V_42 = V_37 * V_38 ;
T_1 V_43 = V_37 * V_39 ;
T_3 V_27 ;
V_42 += ( V_40 >> 32 ) ;
V_42 += V_41 ;
if ( V_42 < V_41 )
V_43 += 0x100000000ull ;
V_27 . V_44 = ( V_40 & 0xffffffffull ) | ( V_42 << 32 ) ;
V_27 . V_45 = V_43 + ( V_42 >> 32 ) ;
return V_27 ;
}
static T_3 F_21 ( T_3 V_46 , T_3 V_47 )
{
T_3 V_27 ;
V_27 . V_44 = V_46 . V_44 + V_47 . V_44 ;
V_27 . V_45 = V_46 . V_45 + V_47 . V_45 + ( V_27 . V_44 < V_46 . V_44 ) ;
return V_27 ;
}
static void F_22 ( T_1 * V_27 , const T_1 * V_25 , const T_1 * V_26 ,
unsigned int V_8 )
{
T_3 V_48 = { 0 , 0 } ;
T_1 V_49 = 0 ;
unsigned int V_19 , V_50 ;
for ( V_50 = 0 ; V_50 < V_8 * 2 - 1 ; V_50 ++ ) {
unsigned int V_51 ;
if ( V_50 < V_8 )
V_51 = 0 ;
else
V_51 = ( V_50 + 1 ) - V_8 ;
for ( V_19 = V_51 ; V_19 <= V_50 && V_19 < V_8 ; V_19 ++ ) {
T_3 V_52 ;
V_52 = F_20 ( V_25 [ V_19 ] , V_26 [ V_50 - V_19 ] ) ;
V_48 = F_21 ( V_48 , V_52 ) ;
V_49 += ( V_48 . V_45 < V_52 . V_45 ) ;
}
V_27 [ V_50 ] = V_48 . V_44 ;
V_48 . V_44 = V_48 . V_45 ;
V_48 . V_45 = V_49 ;
V_49 = 0 ;
}
V_27 [ V_8 * 2 - 1 ] = V_48 . V_44 ;
}
static void F_23 ( T_1 * V_27 , const T_1 * V_25 , unsigned int V_8 )
{
T_3 V_48 = { 0 , 0 } ;
T_1 V_49 = 0 ;
int V_19 , V_50 ;
for ( V_50 = 0 ; V_50 < V_8 * 2 - 1 ; V_50 ++ ) {
unsigned int V_51 ;
if ( V_50 < V_8 )
V_51 = 0 ;
else
V_51 = ( V_50 + 1 ) - V_8 ;
for ( V_19 = V_51 ; V_19 <= V_50 && V_19 <= V_50 - V_19 ; V_19 ++ ) {
T_3 V_52 ;
V_52 = F_20 ( V_25 [ V_19 ] , V_25 [ V_50 - V_19 ] ) ;
if ( V_19 < V_50 - V_19 ) {
V_49 += V_52 . V_45 >> 63 ;
V_52 . V_45 = ( V_52 . V_45 << 1 ) |
( V_52 . V_44 >> 63 ) ;
V_52 . V_44 <<= 1 ;
}
V_48 = F_21 ( V_48 , V_52 ) ;
V_49 += ( V_48 . V_45 < V_52 . V_45 ) ;
}
V_27 [ V_50 ] = V_48 . V_44 ;
V_48 . V_44 = V_48 . V_45 ;
V_48 . V_45 = V_49 ;
V_49 = 0 ;
}
V_27 [ V_8 * 2 - 1 ] = V_48 . V_44 ;
}
static void F_24 ( T_1 * V_27 , const T_1 * V_25 , const T_1 * V_26 ,
const T_1 * V_53 , unsigned int V_8 )
{
T_1 V_30 ;
V_30 = F_18 ( V_27 , V_25 , V_26 , V_8 ) ;
if ( V_30 || F_15 ( V_27 , V_53 , V_8 ) >= 0 )
F_19 ( V_27 , V_27 , V_53 , V_8 ) ;
}
static void F_25 ( T_1 * V_27 , const T_1 * V_25 , const T_1 * V_26 ,
const T_1 * V_53 , unsigned int V_8 )
{
T_1 V_34 = F_19 ( V_27 , V_25 , V_26 , V_8 ) ;
if ( V_34 )
F_18 ( V_27 , V_27 , V_53 , V_8 ) ;
}
static void F_26 ( T_1 * V_27 , const T_1 * V_52 ,
const T_1 * V_54 , T_1 * V_55 )
{
const unsigned int V_8 = 3 ;
int V_30 ;
F_14 ( V_27 , V_52 , V_8 ) ;
F_14 ( V_55 , & V_52 [ 3 ] , V_8 ) ;
V_30 = F_18 ( V_27 , V_27 , V_55 , V_8 ) ;
V_55 [ 0 ] = 0 ;
V_55 [ 1 ] = V_52 [ 3 ] ;
V_55 [ 2 ] = V_52 [ 4 ] ;
V_30 += F_18 ( V_27 , V_27 , V_55 , V_8 ) ;
V_55 [ 0 ] = V_55 [ 1 ] = V_52 [ 5 ] ;
V_55 [ 2 ] = 0 ;
V_30 += F_18 ( V_27 , V_27 , V_55 , V_8 ) ;
while ( V_30 || F_15 ( V_54 , V_27 , V_8 ) != 1 )
V_30 -= F_19 ( V_27 , V_27 , V_54 , V_8 ) ;
}
static void F_27 ( T_1 * V_27 , const T_1 * V_52 ,
const T_1 * V_54 , T_1 * V_55 )
{
int V_30 ;
const unsigned int V_8 = 4 ;
F_14 ( V_27 , V_52 , V_8 ) ;
V_55 [ 0 ] = 0 ;
V_55 [ 1 ] = V_52 [ 5 ] & 0xffffffff00000000ull ;
V_55 [ 2 ] = V_52 [ 6 ] ;
V_55 [ 3 ] = V_52 [ 7 ] ;
V_30 = F_16 ( V_55 , V_55 , 1 , V_8 ) ;
V_30 += F_18 ( V_27 , V_27 , V_55 , V_8 ) ;
V_55 [ 1 ] = V_52 [ 6 ] << 32 ;
V_55 [ 2 ] = ( V_52 [ 6 ] >> 32 ) | ( V_52 [ 7 ] << 32 ) ;
V_55 [ 3 ] = V_52 [ 7 ] >> 32 ;
V_30 += F_16 ( V_55 , V_55 , 1 , V_8 ) ;
V_30 += F_18 ( V_27 , V_27 , V_55 , V_8 ) ;
V_55 [ 0 ] = V_52 [ 4 ] ;
V_55 [ 1 ] = V_52 [ 5 ] & 0xffffffff ;
V_55 [ 2 ] = 0 ;
V_55 [ 3 ] = V_52 [ 7 ] ;
V_30 += F_18 ( V_27 , V_27 , V_55 , V_8 ) ;
V_55 [ 0 ] = ( V_52 [ 4 ] >> 32 ) | ( V_52 [ 5 ] << 32 ) ;
V_55 [ 1 ] = ( V_52 [ 5 ] >> 32 ) | ( V_52 [ 6 ] & 0xffffffff00000000ull ) ;
V_55 [ 2 ] = V_52 [ 7 ] ;
V_55 [ 3 ] = ( V_52 [ 6 ] >> 32 ) | ( V_52 [ 4 ] << 32 ) ;
V_30 += F_18 ( V_27 , V_27 , V_55 , V_8 ) ;
V_55 [ 0 ] = ( V_52 [ 5 ] >> 32 ) | ( V_52 [ 6 ] << 32 ) ;
V_55 [ 1 ] = ( V_52 [ 6 ] >> 32 ) ;
V_55 [ 2 ] = 0 ;
V_55 [ 3 ] = ( V_52 [ 4 ] & 0xffffffff ) | ( V_52 [ 5 ] << 32 ) ;
V_30 -= F_19 ( V_27 , V_27 , V_55 , V_8 ) ;
V_55 [ 0 ] = V_52 [ 6 ] ;
V_55 [ 1 ] = V_52 [ 7 ] ;
V_55 [ 2 ] = 0 ;
V_55 [ 3 ] = ( V_52 [ 4 ] >> 32 ) | ( V_52 [ 5 ] & 0xffffffff00000000ull ) ;
V_30 -= F_19 ( V_27 , V_27 , V_55 , V_8 ) ;
V_55 [ 0 ] = ( V_52 [ 6 ] >> 32 ) | ( V_52 [ 7 ] << 32 ) ;
V_55 [ 1 ] = ( V_52 [ 7 ] >> 32 ) | ( V_52 [ 4 ] << 32 ) ;
V_55 [ 2 ] = ( V_52 [ 4 ] >> 32 ) | ( V_52 [ 5 ] << 32 ) ;
V_55 [ 3 ] = ( V_52 [ 6 ] << 32 ) ;
V_30 -= F_19 ( V_27 , V_27 , V_55 , V_8 ) ;
V_55 [ 0 ] = V_52 [ 7 ] ;
V_55 [ 1 ] = V_52 [ 4 ] & 0xffffffff00000000ull ;
V_55 [ 2 ] = V_52 [ 5 ] ;
V_55 [ 3 ] = V_52 [ 6 ] & 0xffffffff00000000ull ;
V_30 -= F_19 ( V_27 , V_27 , V_55 , V_8 ) ;
if ( V_30 < 0 ) {
do {
V_30 += F_18 ( V_27 , V_27 , V_54 , V_8 ) ;
} while ( V_30 < 0 );
} else {
while ( V_30 || F_15 ( V_54 , V_27 , V_8 ) != 1 )
V_30 -= F_19 ( V_27 , V_27 , V_54 , V_8 ) ;
}
}
static bool F_28 ( T_1 * V_27 , T_1 * V_52 ,
const T_1 * V_54 , unsigned int V_8 )
{
T_1 V_55 [ 2 * V_8 ] ;
switch ( V_8 ) {
case 3 :
F_26 ( V_27 , V_52 , V_54 , V_55 ) ;
break;
case 4 :
F_27 ( V_27 , V_52 , V_54 , V_55 ) ;
break;
default:
F_29 ( L_1 ) ;
return false ;
}
return true ;
}
static void F_30 ( T_1 * V_27 , const T_1 * V_25 , const T_1 * V_26 ,
const T_1 * V_54 , unsigned int V_8 )
{
T_1 V_52 [ 2 * V_8 ] ;
F_22 ( V_52 , V_25 , V_26 , V_8 ) ;
F_28 ( V_27 , V_52 , V_54 , V_8 ) ;
}
static void F_31 ( T_1 * V_27 , const T_1 * V_25 ,
const T_1 * V_54 , unsigned int V_8 )
{
T_1 V_52 [ 2 * V_8 ] ;
F_23 ( V_52 , V_25 , V_8 ) ;
F_28 ( V_27 , V_52 , V_54 , V_8 ) ;
}
static void F_32 ( T_1 * V_27 , const T_1 * V_56 , const T_1 * V_53 ,
unsigned int V_8 )
{
T_1 V_46 [ V_8 ] , V_47 [ V_8 ] ;
T_1 V_57 [ V_8 ] , V_58 [ V_8 ] ;
T_1 V_30 ;
int V_59 ;
if ( F_10 ( V_56 , V_8 ) ) {
F_9 ( V_27 , V_8 ) ;
return;
}
F_14 ( V_46 , V_56 , V_8 ) ;
F_14 ( V_47 , V_53 , V_8 ) ;
F_9 ( V_57 , V_8 ) ;
V_57 [ 0 ] = 1 ;
F_9 ( V_58 , V_8 ) ;
while ( ( V_59 = F_15 ( V_46 , V_47 , V_8 ) ) != 0 ) {
V_30 = 0 ;
if ( F_33 ( V_46 ) ) {
F_17 ( V_46 , V_8 ) ;
if ( ! F_33 ( V_57 ) )
V_30 = F_18 ( V_57 , V_57 , V_53 , V_8 ) ;
F_17 ( V_57 , V_8 ) ;
if ( V_30 )
V_57 [ V_8 - 1 ] |= 0x8000000000000000ull ;
} else if ( F_33 ( V_47 ) ) {
F_17 ( V_47 , V_8 ) ;
if ( ! F_33 ( V_58 ) )
V_30 = F_18 ( V_58 , V_58 , V_53 , V_8 ) ;
F_17 ( V_58 , V_8 ) ;
if ( V_30 )
V_58 [ V_8 - 1 ] |= 0x8000000000000000ull ;
} else if ( V_59 > 0 ) {
F_19 ( V_46 , V_46 , V_47 , V_8 ) ;
F_17 ( V_46 , V_8 ) ;
if ( F_15 ( V_57 , V_58 , V_8 ) < 0 )
F_18 ( V_57 , V_57 , V_53 , V_8 ) ;
F_19 ( V_57 , V_57 , V_58 , V_8 ) ;
if ( ! F_33 ( V_57 ) )
V_30 = F_18 ( V_57 , V_57 , V_53 , V_8 ) ;
F_17 ( V_57 , V_8 ) ;
if ( V_30 )
V_57 [ V_8 - 1 ] |= 0x8000000000000000ull ;
} else {
F_19 ( V_47 , V_47 , V_46 , V_8 ) ;
F_17 ( V_47 , V_8 ) ;
if ( F_15 ( V_58 , V_57 , V_8 ) < 0 )
F_18 ( V_58 , V_58 , V_53 , V_8 ) ;
F_19 ( V_58 , V_58 , V_57 , V_8 ) ;
if ( ! F_33 ( V_58 ) )
V_30 = F_18 ( V_58 , V_58 , V_53 , V_8 ) ;
F_17 ( V_58 , V_8 ) ;
if ( V_30 )
V_58 [ V_8 - 1 ] |= 0x8000000000000000ull ;
}
}
F_14 ( V_27 , V_57 , V_8 ) ;
}
static bool F_34 ( const struct V_12 * V_60 )
{
return ( F_10 ( V_60 -> V_14 , V_60 -> V_8 ) &&
F_10 ( V_60 -> V_16 , V_60 -> V_8 ) ) ;
}
static void F_35 ( T_1 * V_61 , T_1 * y1 , T_1 * V_62 ,
T_1 * V_54 , unsigned int V_8 )
{
T_1 V_63 [ V_8 ] ;
T_1 V_64 [ V_8 ] ;
if ( F_10 ( V_62 , V_8 ) )
return;
F_31 ( V_63 , y1 , V_54 , V_8 ) ;
F_30 ( V_64 , V_61 , V_63 , V_54 , V_8 ) ;
F_31 ( V_63 , V_63 , V_54 , V_8 ) ;
F_30 ( y1 , y1 , V_62 , V_54 , V_8 ) ;
F_31 ( V_62 , V_62 , V_54 , V_8 ) ;
F_24 ( V_61 , V_61 , V_62 , V_54 , V_8 ) ;
F_24 ( V_62 , V_62 , V_62 , V_54 , V_8 ) ;
F_25 ( V_62 , V_61 , V_62 , V_54 , V_8 ) ;
F_30 ( V_61 , V_61 , V_62 , V_54 , V_8 ) ;
F_24 ( V_62 , V_61 , V_61 , V_54 , V_8 ) ;
F_24 ( V_61 , V_61 , V_62 , V_54 , V_8 ) ;
if ( F_11 ( V_61 , 0 ) ) {
T_1 V_30 = F_18 ( V_61 , V_61 , V_54 , V_8 ) ;
F_17 ( V_61 , V_8 ) ;
V_61 [ V_8 - 1 ] |= V_30 << 63 ;
} else {
F_17 ( V_61 , V_8 ) ;
}
F_31 ( V_62 , V_61 , V_54 , V_8 ) ;
F_25 ( V_62 , V_62 , V_64 , V_54 , V_8 ) ;
F_25 ( V_62 , V_62 , V_64 , V_54 , V_8 ) ;
F_25 ( V_64 , V_64 , V_62 , V_54 , V_8 ) ;
F_30 ( V_61 , V_61 , V_64 , V_54 , V_8 ) ;
F_25 ( V_63 , V_61 , V_63 , V_54 , V_8 ) ;
F_14 ( V_61 , V_62 , V_8 ) ;
F_14 ( V_62 , y1 , V_8 ) ;
F_14 ( y1 , V_63 , V_8 ) ;
}
static void F_36 ( T_1 * V_61 , T_1 * y1 , T_1 * V_65 , T_1 * V_54 ,
unsigned int V_8 )
{
T_1 V_66 [ V_8 ] ;
F_31 ( V_66 , V_65 , V_54 , V_8 ) ;
F_30 ( V_61 , V_61 , V_66 , V_54 , V_8 ) ;
F_30 ( V_66 , V_66 , V_65 , V_54 , V_8 ) ;
F_30 ( y1 , y1 , V_66 , V_54 , V_8 ) ;
}
static void F_37 ( T_1 * V_61 , T_1 * y1 , T_1 * V_67 , T_1 * V_68 ,
T_1 * V_69 , T_1 * V_54 ,
unsigned int V_8 )
{
T_1 V_65 [ V_8 ] ;
F_14 ( V_67 , V_61 , V_8 ) ;
F_14 ( V_68 , y1 , V_8 ) ;
F_9 ( V_65 , V_8 ) ;
V_65 [ 0 ] = 1 ;
if ( V_69 )
F_14 ( V_65 , V_69 , V_8 ) ;
F_36 ( V_61 , y1 , V_65 , V_54 , V_8 ) ;
F_35 ( V_61 , y1 , V_65 , V_54 , V_8 ) ;
F_36 ( V_67 , V_68 , V_65 , V_54 , V_8 ) ;
}
static void F_38 ( T_1 * V_61 , T_1 * y1 , T_1 * V_67 , T_1 * V_68 , T_1 * V_54 ,
unsigned int V_8 )
{
T_1 V_64 [ V_8 ] ;
F_25 ( V_64 , V_67 , V_61 , V_54 , V_8 ) ;
F_31 ( V_64 , V_64 , V_54 , V_8 ) ;
F_30 ( V_61 , V_61 , V_64 , V_54 , V_8 ) ;
F_30 ( V_67 , V_67 , V_64 , V_54 , V_8 ) ;
F_25 ( V_68 , V_68 , y1 , V_54 , V_8 ) ;
F_31 ( V_64 , V_68 , V_54 , V_8 ) ;
F_25 ( V_64 , V_64 , V_61 , V_54 , V_8 ) ;
F_25 ( V_64 , V_64 , V_67 , V_54 , V_8 ) ;
F_25 ( V_67 , V_67 , V_61 , V_54 , V_8 ) ;
F_30 ( y1 , y1 , V_67 , V_54 , V_8 ) ;
F_25 ( V_67 , V_61 , V_64 , V_54 , V_8 ) ;
F_30 ( V_68 , V_68 , V_67 , V_54 , V_8 ) ;
F_25 ( V_68 , V_68 , y1 , V_54 , V_8 ) ;
F_14 ( V_67 , V_64 , V_8 ) ;
}
static void F_39 ( T_1 * V_61 , T_1 * y1 , T_1 * V_67 , T_1 * V_68 , T_1 * V_54 ,
unsigned int V_8 )
{
T_1 V_64 [ V_8 ] ;
T_1 V_70 [ V_8 ] ;
T_1 V_71 [ V_8 ] ;
F_25 ( V_64 , V_67 , V_61 , V_54 , V_8 ) ;
F_31 ( V_64 , V_64 , V_54 , V_8 ) ;
F_30 ( V_61 , V_61 , V_64 , V_54 , V_8 ) ;
F_30 ( V_67 , V_67 , V_64 , V_54 , V_8 ) ;
F_24 ( V_64 , V_68 , y1 , V_54 , V_8 ) ;
F_25 ( V_68 , V_68 , y1 , V_54 , V_8 ) ;
F_25 ( V_70 , V_67 , V_61 , V_54 , V_8 ) ;
F_30 ( y1 , y1 , V_70 , V_54 , V_8 ) ;
F_24 ( V_70 , V_61 , V_67 , V_54 , V_8 ) ;
F_31 ( V_67 , V_68 , V_54 , V_8 ) ;
F_25 ( V_67 , V_67 , V_70 , V_54 , V_8 ) ;
F_25 ( V_71 , V_61 , V_67 , V_54 , V_8 ) ;
F_30 ( V_68 , V_68 , V_71 , V_54 , V_8 ) ;
F_25 ( V_68 , V_68 , y1 , V_54 , V_8 ) ;
F_31 ( V_71 , V_64 , V_54 , V_8 ) ;
F_25 ( V_71 , V_71 , V_70 , V_54 , V_8 ) ;
F_25 ( V_70 , V_71 , V_61 , V_54 , V_8 ) ;
F_30 ( V_70 , V_70 , V_64 , V_54 , V_8 ) ;
F_25 ( y1 , V_70 , y1 , V_54 , V_8 ) ;
F_14 ( V_61 , V_71 , V_8 ) ;
}
static void F_40 ( struct V_12 * V_27 ,
const struct V_12 * V_60 , const T_1 * V_72 ,
T_1 * V_73 , T_1 * V_54 ,
unsigned int V_8 )
{
T_1 V_74 [ 2 ] [ V_8 ] ;
T_1 V_75 [ 2 ] [ V_8 ] ;
T_1 V_65 [ V_8 ] ;
int V_19 , V_76 ;
int V_77 = F_13 ( V_72 , V_8 ) ;
F_14 ( V_74 [ 1 ] , V_60 -> V_14 , V_8 ) ;
F_14 ( V_75 [ 1 ] , V_60 -> V_16 , V_8 ) ;
F_37 ( V_74 [ 1 ] , V_75 [ 1 ] , V_74 [ 0 ] , V_75 [ 0 ] , V_73 , V_54 ,
V_8 ) ;
for ( V_19 = V_77 - 2 ; V_19 > 0 ; V_19 -- ) {
V_76 = ! F_11 ( V_72 , V_19 ) ;
F_39 ( V_74 [ 1 - V_76 ] , V_75 [ 1 - V_76 ] , V_74 [ V_76 ] , V_75 [ V_76 ] , V_54 ,
V_8 ) ;
F_38 ( V_74 [ V_76 ] , V_75 [ V_76 ] , V_74 [ 1 - V_76 ] , V_75 [ 1 - V_76 ] , V_54 ,
V_8 ) ;
}
V_76 = ! F_11 ( V_72 , 0 ) ;
F_39 ( V_74 [ 1 - V_76 ] , V_75 [ 1 - V_76 ] , V_74 [ V_76 ] , V_75 [ V_76 ] , V_54 ,
V_8 ) ;
F_25 ( V_65 , V_74 [ 1 ] , V_74 [ 0 ] , V_54 , V_8 ) ;
F_30 ( V_65 , V_65 , V_75 [ 1 - V_76 ] , V_54 , V_8 ) ;
F_30 ( V_65 , V_65 , V_60 -> V_14 , V_54 , V_8 ) ;
F_32 ( V_65 , V_65 , V_54 , V_60 -> V_8 ) ;
F_30 ( V_65 , V_65 , V_60 -> V_16 , V_54 , V_8 ) ;
F_30 ( V_65 , V_65 , V_74 [ 1 - V_76 ] , V_54 , V_8 ) ;
F_38 ( V_74 [ V_76 ] , V_75 [ V_76 ] , V_74 [ 1 - V_76 ] , V_75 [ 1 - V_76 ] , V_54 , V_8 ) ;
F_36 ( V_74 [ 0 ] , V_75 [ 0 ] , V_65 , V_54 , V_8 ) ;
F_14 ( V_27 -> V_14 , V_74 [ 0 ] , V_8 ) ;
F_14 ( V_27 -> V_16 , V_75 [ 0 ] , V_8 ) ;
}
static inline void F_41 ( const T_1 * V_28 , T_1 * V_78 ,
unsigned int V_8 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 ; V_19 ++ )
V_78 [ V_19 ] = F_42 ( V_28 [ V_8 - 1 - V_19 ] ) ;
}
int F_43 ( unsigned int V_2 , unsigned int V_8 ,
const T_1 * V_79 , unsigned int V_80 )
{
int V_81 ;
const struct V_1 * V_82 = F_1 ( V_2 ) ;
if ( ! V_79 )
return - V_83 ;
V_81 = V_8 << V_84 ;
if ( V_80 != V_81 )
return - V_83 ;
if ( F_10 ( V_79 , V_8 ) )
return - V_83 ;
if ( F_15 ( V_82 -> V_85 , V_79 , V_8 ) != 1 )
return - V_83 ;
return 0 ;
}
int F_44 ( unsigned int V_2 , unsigned int V_8 , T_1 * V_86 )
{
const struct V_1 * V_82 = F_1 ( V_2 ) ;
T_1 V_87 [ V_8 ] ;
unsigned int V_81 = V_8 << V_84 ;
unsigned int V_88 = F_13 ( V_82 -> V_85 , V_8 ) ;
int V_89 ;
if ( V_88 < 160 )
return - V_83 ;
if ( F_45 () )
V_89 = - V_90 ;
V_89 = F_46 ( V_91 , ( V_92 * ) V_87 , V_81 ) ;
F_47 () ;
if ( V_89 )
return V_89 ;
if ( F_10 ( V_87 , V_8 ) )
return - V_83 ;
if ( F_15 ( V_82 -> V_85 , V_87 , V_8 ) != 1 )
return - V_83 ;
F_41 ( V_87 , V_86 , V_8 ) ;
return 0 ;
}
int F_48 ( unsigned int V_2 , unsigned int V_8 ,
const T_1 * V_79 , T_1 * V_93 )
{
int V_94 = 0 ;
struct V_12 * V_95 ;
T_1 V_87 [ V_8 ] ;
const struct V_1 * V_82 = F_1 ( V_2 ) ;
if ( ! V_79 || ! V_82 ) {
V_94 = - V_83 ;
goto V_78;
}
F_41 ( V_79 , V_87 , V_8 ) ;
V_95 = F_6 ( V_8 ) ;
if ( ! V_95 ) {
V_94 = - V_96 ;
goto V_78;
}
F_40 ( V_95 , & V_82 -> V_97 , V_87 , NULL , V_82 -> V_13 , V_8 ) ;
if ( F_34 ( V_95 ) ) {
V_94 = - V_98 ;
goto V_99;
}
F_41 ( V_95 -> V_14 , V_93 , V_8 ) ;
F_41 ( V_95 -> V_16 , & V_93 [ V_8 ] , V_8 ) ;
V_99:
F_8 ( V_95 ) ;
V_78:
return V_94 ;
}
int F_49 ( unsigned int V_2 , unsigned int V_8 ,
const T_1 * V_79 , const T_1 * V_93 ,
T_1 * V_100 )
{
int V_94 = 0 ;
struct V_12 * V_52 , * V_95 ;
T_1 V_87 [ V_8 ] ;
T_1 V_101 [ V_8 ] ;
unsigned int V_81 ;
const struct V_1 * V_82 = F_1 ( V_2 ) ;
if ( ! V_79 || ! V_93 || ! V_82 ) {
V_94 = - V_83 ;
goto V_78;
}
V_81 = V_8 << V_84 ;
F_50 ( V_101 , V_81 ) ;
V_95 = F_6 ( V_8 ) ;
if ( ! V_95 ) {
V_94 = - V_96 ;
goto V_78;
}
V_52 = F_6 ( V_8 ) ;
if ( ! V_52 ) {
V_94 = - V_96 ;
goto V_102;
}
F_41 ( V_93 , V_95 -> V_14 , V_8 ) ;
F_41 ( & V_93 [ V_8 ] , V_95 -> V_16 , V_8 ) ;
F_41 ( V_79 , V_87 , V_8 ) ;
F_40 ( V_52 , V_95 , V_87 , V_101 , V_82 -> V_13 , V_8 ) ;
F_41 ( V_52 -> V_14 , V_100 , V_8 ) ;
if ( F_34 ( V_52 ) )
V_94 = - V_90 ;
F_8 ( V_52 ) ;
V_102:
F_8 ( V_95 ) ;
V_78:
return V_94 ;
}
