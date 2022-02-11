static T_1 F_1 ( const T_1 V_1 , const unsigned int V_2 )
{
static const T_1 V_3 [ 16 ] = { 0 , 1 , 3 , 5 , 7 , 9 , 11 , 13 , 14 ,
12 , 10 , 8 , 6 , 4 , 2 , 0 } ;
static const T_1 V_4 [ 15 ] = { 0x8 , 0x7 , 0x9 , 0x6 , 0xa , 0x5 , 0xb , 0x4 ,
0xc , 0x3 , 0xd , 0x2 , 0xe , 0x1 , 0xf } ;
static const T_1 V_5 [ 15 ] = { 0x0 , 0x6 , 0xf , 0x8 , 0x7 , 0x5 , 0x3 , 0x4 ,
0xc , 0xd , 0xe , 0x1 , 0x2 , 0xb , 0xa } ;
static const T_1 V_6 [ 16 ] = { 0 , 11 , 12 , 6 , 7 , 5 , 1 , 4 ,
3 , 0x00 , 14 , 13 , 8 , 9 , 10 , 2 } ;
const T_1 V_7 = V_1 & 0xf ;
const T_1 V_8 = ( V_1 >> 4 ) & 0xf ;
const T_1 V_9 = ( V_8 == 0x9 ) ? 0x9 : V_5 [ ( V_6 [ V_8 ] + V_2 ) % 15 ] ;
if ( V_3 [ V_7 ] < V_2 )
return 0x00 ;
return ( ( V_4 [ 14 + V_2 - V_3 [ V_7 ] ] ) | ( V_9 << 4 ) ) ;
}
static void F_2 ( struct V_10 * V_11 , T_2 * const V_12 )
{
T_1 * const V_13 = ( T_1 * ) V_12 ;
if ( V_13 [ V_14 ] != 0x00 ) {
V_11 -> V_2 = 0 ;
V_11 -> V_1 = V_13 [ V_14 ] ^ V_11 -> V_15 ;
}
V_13 [ V_14 ] ^= V_11 -> V_15 ;
V_11 -> V_15 = F_1 ( V_11 -> V_1 , ++ ( V_11 -> V_2 ) ) ;
}
int F_3 ( struct V_16 * V_17 , unsigned int V_18 ,
unsigned int V_19 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
int V_23 ;
if ( F_4 ( V_17 ) )
return - V_24 ;
V_23 = F_5 ( V_17 , V_18 , V_19 + 1 ) ;
if ( V_23 < 0 )
return V_23 ;
V_17 -> V_25 = V_26 | V_17 -> V_27 ;
V_21 -> V_19 = V_19 ;
V_21 -> V_28 = V_18 - V_29 * V_17 -> V_30 + 1 ;
return 0 ;
}
static void F_6 ( struct V_16 * V_17 , struct V_31 * V_32 ,
T_2 * V_12 , unsigned int V_33 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
struct V_34 * V_35 = V_32 -> V_35 ;
unsigned int V_36 , V_37 , V_38 , V_39 ;
const T_3 * V_40 ;
V_36 = V_21 -> V_19 ;
V_40 = ( void * ) V_35 -> V_41 +
F_7 ( V_35 , V_17 -> V_42 ) ;
V_37 = V_35 -> V_43 - V_17 -> V_42 ;
V_12 ++ ;
for ( V_38 = 0 ; V_38 < V_33 ; ++ V_38 ) {
for ( V_39 = 0 ; V_39 < V_36 ; ++ V_39 ) {
V_12 [ V_39 ] = F_8 ( ( * V_40 >> 8 ) | 0x40000000 ) ;
F_2 ( & V_21 -> V_11 , & V_12 [ V_39 ] ) ;
V_40 ++ ;
}
V_12 += V_17 -> V_44 ;
if ( -- V_37 == 0 )
V_40 = ( void * ) V_35 -> V_41 ;
}
}
static void F_9 ( struct V_16 * V_17 , struct V_31 * V_32 ,
T_2 * V_12 , unsigned int V_33 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
struct V_34 * V_35 = V_32 -> V_35 ;
unsigned int V_36 , V_37 , V_38 , V_39 ;
T_3 * V_45 ;
V_36 = V_21 -> V_19 ;
V_45 = ( void * ) V_35 -> V_41 +
F_7 ( V_35 , V_17 -> V_42 ) ;
V_37 = V_35 -> V_43 - V_17 -> V_42 ;
V_12 ++ ;
for ( V_38 = 0 ; V_38 < V_33 ; ++ V_38 ) {
for ( V_39 = 0 ; V_39 < V_36 ; ++ V_39 ) {
* V_45 = F_10 ( V_12 [ V_39 ] ) << 8 ;
V_45 ++ ;
}
V_12 += V_17 -> V_44 ;
if ( -- V_37 == 0 )
V_45 = ( void * ) V_35 -> V_41 ;
}
}
static void F_11 ( struct V_16 * V_17 , T_2 * V_12 ,
unsigned int V_46 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
unsigned int V_36 , V_38 , V_39 ;
V_36 = V_21 -> V_19 ;
V_12 ++ ;
for ( V_38 = 0 ; V_38 < V_46 ; ++ V_38 ) {
for ( V_39 = 0 ; V_39 < V_36 ; ++ V_39 )
V_12 [ V_39 ] = F_8 ( 0x40000000 ) ;
V_12 += V_17 -> V_44 ;
}
}
static bool F_12 ( struct V_16 * V_17 , unsigned int V_47 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
int V_48 ;
V_48 = V_21 -> V_49 [ V_47 ] ;
if ( V_48 == 0 )
return true ;
V_48 -= V_29 * V_17 -> V_30 ;
V_48 = F_13 ( V_48 , 0 ) ;
V_21 -> V_49 [ V_47 ] = V_48 ;
return V_48 < V_21 -> V_28 ;
}
static inline void F_14 ( struct V_16 * V_17 ,
unsigned int V_47 , unsigned int V_50 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
V_21 -> V_49 [ V_47 ] += V_51 [ V_17 -> V_27 ] * V_50 ;
}
static void F_15 ( struct V_16 * V_17 , T_2 * V_12 ,
unsigned int V_46 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
unsigned int V_52 , V_47 ;
int V_3 ;
T_1 * V_53 ;
for ( V_52 = 0 ; V_52 < V_46 ; V_52 ++ ) {
V_47 = ( V_17 -> V_54 + V_52 ) % 8 ;
V_53 = ( T_1 * ) & V_12 [ 0 ] ;
V_3 = 0 ;
if ( V_47 < V_55 &&
F_12 ( V_17 , V_47 ) &&
V_21 -> V_56 [ V_47 ] != NULL )
V_3 = F_16 ( V_21 -> V_56 [ V_47 ] , V_53 + 1 , 2 ) ;
if ( V_3 > 0 ) {
if ( V_47 == 2 )
V_53 [ 3 ] = 0xe0 ;
else if ( V_47 == 1 )
V_53 [ 3 ] = 0x20 ;
else
V_53 [ 3 ] = 0x00 ;
V_53 [ 3 ] |= V_3 ;
F_14 ( V_17 , V_47 , V_3 ) ;
} else {
V_53 [ 1 ] = 0 ;
V_53 [ 2 ] = 0 ;
V_53 [ 3 ] = 0 ;
}
V_53 [ 0 ] = 0x80 ;
V_12 += V_17 -> V_44 ;
}
}
static void F_17 ( struct V_16 * V_17 , T_2 * V_12 ,
unsigned int V_46 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
unsigned int V_52 , V_47 , V_3 ;
T_1 * V_53 ;
for ( V_52 = 0 ; V_52 < V_46 ; V_52 ++ ) {
V_53 = ( T_1 * ) & V_12 [ 0 ] ;
V_3 = V_53 [ 3 ] & 0x0f ;
if ( V_3 > 0 ) {
if ( V_53 [ 3 ] >> 4 > 0 )
V_47 = 2 ;
else
V_47 = 0 ;
if ( V_47 < V_55 && V_21 -> V_56 [ V_47 ] )
F_18 ( V_21 -> V_56 [ V_47 ] , V_53 + 1 , V_3 ) ;
}
V_12 += V_17 -> V_44 ;
}
}
int F_19 ( struct V_16 * V_17 ,
struct V_34 * V_35 )
{
int V_23 ;
V_23 = F_20 ( V_35 , 0 , 32 , 24 ) ;
if ( V_23 < 0 )
return V_23 ;
return F_21 ( V_17 , V_35 ) ;
}
void F_22 ( struct V_16 * V_17 , unsigned int V_47 ,
struct V_57 * V_56 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
if ( V_47 < V_55 )
F_23 ( V_21 -> V_56 [ V_47 ] ) = V_56 ;
}
static unsigned int F_24 ( struct V_16 * V_17 ,
T_2 * V_12 ,
unsigned int V_46 ,
unsigned int * V_58 )
{
struct V_31 * V_32 ;
unsigned int V_59 ;
V_32 = F_23 ( V_17 -> V_32 ) ;
if ( V_32 ) {
F_9 ( V_17 , V_32 , V_12 , V_46 ) ;
V_59 = V_46 ;
} else {
V_59 = 0 ;
}
F_17 ( V_17 , V_12 , V_46 ) ;
return V_59 ;
}
static unsigned int F_25 ( struct V_16 * V_17 ,
T_2 * V_12 ,
unsigned int V_46 ,
unsigned int * V_58 )
{
struct V_31 * V_32 ;
unsigned int V_59 ;
V_32 = F_23 ( V_17 -> V_32 ) ;
if ( V_32 ) {
F_6 ( V_17 , V_32 , V_12 , V_46 ) ;
V_59 = V_46 ;
} else {
F_11 ( V_17 , V_12 , V_46 ) ;
V_59 = 0 ;
}
F_15 ( V_17 , V_12 , V_46 ) ;
return V_59 ;
}
int F_26 ( struct V_16 * V_17 , struct V_60 * V_61 ,
enum V_62 V_63 )
{
T_4 V_64 ;
enum V_65 V_66 ;
if ( V_63 == V_67 ) {
V_66 = V_68 ;
V_64 = F_24 ;
} else {
V_66 = V_69 ;
V_64 = F_25 ;
}
return F_27 ( V_17 , V_61 , V_63 , V_66 , V_70 ,
V_64 , sizeof( struct V_20 ) ) ;
}
void F_28 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
V_21 -> V_11 . V_15 = 0x00 ;
V_21 -> V_11 . V_1 = 0x00 ;
V_21 -> V_11 . V_2 = 0 ;
}
