static const T_1 F_1 ( const T_1 V_1 , const unsigned int V_2 )
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
if ( V_17 -> V_28 == V_29 )
V_21 -> V_30 = V_31 ;
else
V_21 -> V_30 = V_32 ;
V_21 -> V_33 = V_18 - V_34 * V_17 -> V_35 + 1 ;
return 0 ;
}
static void F_6 ( struct V_16 * V_17 , struct V_36 * V_37 ,
T_2 * V_12 , unsigned int V_38 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
struct V_39 * V_40 = V_37 -> V_40 ;
unsigned int V_41 , V_42 , V_43 , V_44 ;
const T_3 * V_45 ;
V_41 = V_21 -> V_19 ;
V_45 = ( void * ) V_40 -> V_46 +
F_7 ( V_40 , V_17 -> V_47 ) ;
V_42 = V_40 -> V_48 - V_17 -> V_47 ;
V_12 ++ ;
for ( V_43 = 0 ; V_43 < V_38 ; ++ V_43 ) {
for ( V_44 = 0 ; V_44 < V_41 ; ++ V_44 ) {
V_12 [ V_44 ] = F_8 ( ( * V_45 >> 8 ) | 0x40000000 ) ;
F_2 ( & V_21 -> V_11 , & V_12 [ V_44 ] ) ;
V_45 ++ ;
}
V_12 += V_17 -> V_49 ;
if ( -- V_42 == 0 )
V_45 = ( void * ) V_40 -> V_46 ;
}
}
static void F_9 ( struct V_16 * V_17 , struct V_36 * V_37 ,
T_2 * V_12 , unsigned int V_38 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
struct V_39 * V_40 = V_37 -> V_40 ;
unsigned int V_41 , V_42 , V_43 , V_44 ;
const T_4 * V_45 ;
V_41 = V_21 -> V_19 ;
V_45 = ( void * ) V_40 -> V_46 +
F_7 ( V_40 , V_17 -> V_47 ) ;
V_42 = V_40 -> V_48 - V_17 -> V_47 ;
V_12 ++ ;
for ( V_43 = 0 ; V_43 < V_38 ; ++ V_43 ) {
for ( V_44 = 0 ; V_44 < V_41 ; ++ V_44 ) {
V_12 [ V_44 ] = F_8 ( ( * V_45 << 8 ) | 0x40000000 ) ;
F_2 ( & V_21 -> V_11 , & V_12 [ V_44 ] ) ;
V_45 ++ ;
}
V_12 += V_17 -> V_49 ;
if ( -- V_42 == 0 )
V_45 = ( void * ) V_40 -> V_46 ;
}
}
static void F_10 ( struct V_16 * V_17 , struct V_36 * V_37 ,
T_2 * V_12 , unsigned int V_38 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
struct V_39 * V_40 = V_37 -> V_40 ;
unsigned int V_41 , V_42 , V_43 , V_44 ;
T_3 * V_50 ;
V_41 = V_21 -> V_19 ;
V_50 = ( void * ) V_40 -> V_46 +
F_7 ( V_40 , V_17 -> V_47 ) ;
V_42 = V_40 -> V_48 - V_17 -> V_47 ;
V_12 ++ ;
for ( V_43 = 0 ; V_43 < V_38 ; ++ V_43 ) {
for ( V_44 = 0 ; V_44 < V_41 ; ++ V_44 ) {
* V_50 = F_11 ( V_12 [ V_44 ] ) << 8 ;
V_50 ++ ;
}
V_12 += V_17 -> V_49 ;
if ( -- V_42 == 0 )
V_50 = ( void * ) V_40 -> V_46 ;
}
}
static void F_12 ( struct V_16 * V_17 , T_2 * V_12 ,
unsigned int V_51 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
unsigned int V_41 , V_43 , V_44 ;
V_41 = V_21 -> V_19 ;
V_12 ++ ;
for ( V_43 = 0 ; V_43 < V_51 ; ++ V_43 ) {
for ( V_44 = 0 ; V_44 < V_41 ; ++ V_44 )
V_12 [ V_44 ] = F_8 ( 0x40000000 ) ;
V_12 += V_17 -> V_49 ;
}
}
static bool F_13 ( struct V_16 * V_17 , unsigned int V_52 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
int V_53 ;
V_53 = V_21 -> V_54 [ V_52 ] ;
if ( V_53 == 0 )
return true ;
V_53 -= V_34 * V_17 -> V_35 ;
V_53 = F_14 ( V_53 , 0 ) ;
V_21 -> V_54 [ V_52 ] = V_53 ;
return V_53 < V_21 -> V_33 ;
}
static inline void F_15 ( struct V_16 * V_17 ,
unsigned int V_52 , unsigned int V_55 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
V_21 -> V_54 [ V_52 ] += V_56 [ V_17 -> V_27 ] * V_55 ;
}
static void F_16 ( struct V_16 * V_17 , T_2 * V_12 ,
unsigned int V_51 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
unsigned int V_57 , V_52 ;
int V_3 ;
T_1 * V_58 ;
for ( V_57 = 0 ; V_57 < V_51 ; V_57 ++ ) {
V_52 = ( V_17 -> V_59 + V_57 ) % 8 ;
V_58 = ( T_1 * ) & V_12 [ 0 ] ;
V_3 = 0 ;
if ( V_52 < V_21 -> V_30 &&
F_13 ( V_17 , V_52 ) &&
V_21 -> V_60 [ V_52 ] != NULL )
V_3 = F_17 ( V_21 -> V_60 [ V_52 ] , V_58 + 1 , 2 ) ;
if ( V_3 > 0 ) {
V_58 [ 3 ] = ( 0x10 << V_52 ) | V_3 ;
F_15 ( V_17 , V_52 , V_3 ) ;
} else {
V_58 [ 1 ] = 0 ;
V_58 [ 2 ] = 0 ;
V_58 [ 3 ] = 0 ;
}
V_58 [ 0 ] = 0x80 ;
V_12 += V_17 -> V_49 ;
}
}
static void F_18 ( struct V_16 * V_17 , T_2 * V_12 ,
unsigned int V_51 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
unsigned int V_57 , V_52 , V_3 ;
T_1 * V_58 ;
for ( V_57 = 0 ; V_57 < V_51 ; V_57 ++ ) {
V_58 = ( T_1 * ) & V_12 [ 0 ] ;
V_52 = V_58 [ 3 ] >> 4 ;
V_3 = V_58 [ 3 ] & 0x0f ;
if ( V_52 < V_21 -> V_30 && V_21 -> V_60 [ V_52 ] && V_3 > 0 )
F_19 ( V_21 -> V_60 [ V_52 ] , V_58 + 1 , V_3 ) ;
V_12 += V_17 -> V_49 ;
}
}
int F_20 ( struct V_16 * V_17 ,
struct V_39 * V_40 )
{
int V_23 ;
V_23 = F_21 ( V_40 , 0 , 32 , 24 ) ;
if ( V_23 < 0 )
return V_23 ;
return F_22 ( V_17 , V_40 ) ;
}
void F_23 ( struct V_16 * V_17 , T_5 V_61 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
if ( F_24 ( F_25 ( V_17 ) ) )
return;
switch ( V_61 ) {
default:
F_24 ( 1 ) ;
case V_62 :
if ( V_17 -> V_28 == V_63 ) {
V_21 -> V_64 = F_9 ;
break;
}
F_24 ( 1 ) ;
case V_65 :
if ( V_17 -> V_28 == V_63 )
V_21 -> V_64 = F_6 ;
else
V_21 -> V_64 = F_10 ;
break;
}
}
void F_26 ( struct V_16 * V_17 , unsigned int V_52 ,
struct V_66 * V_60 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
if ( V_52 < V_21 -> V_30 )
F_27 ( V_21 -> V_60 [ V_52 ] ) = V_60 ;
}
static unsigned int F_28 ( struct V_16 * V_17 ,
T_2 * V_12 ,
unsigned int V_51 ,
unsigned int * V_67 )
{
struct V_20 * V_21 = (struct V_20 * ) V_17 -> V_22 ;
struct V_36 * V_37 ;
unsigned int V_68 ;
V_37 = F_27 ( V_17 -> V_37 ) ;
if ( V_37 ) {
V_21 -> V_64 ( V_17 , V_37 , V_12 , V_51 ) ;
V_68 = V_51 ;
} else {
V_68 = 0 ;
}
F_18 ( V_17 , V_12 , V_51 ) ;
return V_68 ;
}
static unsigned int F_29 ( struct V_16 * V_17 ,
T_2 * V_12 ,
unsigned int V_51 ,
unsigned int * V_67 )
{
struct V_20 * V_21 = (struct V_20 * ) V_17 -> V_22 ;
struct V_36 * V_37 ;
unsigned int V_68 ;
V_37 = F_27 ( V_17 -> V_37 ) ;
if ( V_37 ) {
V_21 -> V_64 ( V_17 , V_37 , V_12 , V_51 ) ;
V_68 = V_51 ;
} else {
F_12 ( V_17 , V_12 , V_51 ) ;
V_68 = 0 ;
}
F_16 ( V_17 , V_12 , V_51 ) ;
return V_68 ;
}
int F_30 ( struct V_16 * V_17 , struct V_69 * V_70 ,
enum V_71 V_72 )
{
T_6 V_73 ;
enum V_74 V_75 ;
if ( V_72 == V_29 ) {
V_75 = V_76 | V_77 ;
V_73 = F_28 ;
} else {
V_75 = V_78 ;
V_73 = F_29 ;
}
return F_31 ( V_17 , V_70 , V_72 , V_75 , V_79 ,
V_73 , sizeof( struct V_20 ) ) ;
}
void F_32 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = V_17 -> V_22 ;
V_21 -> V_11 . V_15 = 0x00 ;
V_21 -> V_11 . V_1 = 0x00 ;
V_21 -> V_11 . V_2 = 0 ;
}
