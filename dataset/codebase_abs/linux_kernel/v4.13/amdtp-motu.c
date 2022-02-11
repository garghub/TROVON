int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
struct V_5 * V_6 )
{
static const struct {
unsigned int V_7 ;
unsigned int V_8 ;
} V_9 [] = {
[ V_10 ] = { 557 , 123 } ,
[ V_11 ] = { 512 , 0 } ,
[ V_12 ] = { 278 , 282 } ,
[ V_13 ] = { 256 , 0 } ,
[ V_14 ] = { 139 , 141 } ,
[ V_15 ] = { 128 , 0 } ,
} ;
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned int V_19 , V_20 , V_21 ;
unsigned int V_22 ;
unsigned int V_23 ;
int V_24 , V_25 ;
if ( F_2 ( V_2 ) )
return - V_26 ;
for ( V_24 = 0 ; V_24 < F_3 ( V_27 ) ; ++ V_24 ) {
if ( V_27 [ V_24 ] == V_3 ) {
V_23 = V_24 >> 1 ;
break;
}
}
if ( V_24 == F_3 ( V_27 ) )
return - V_28 ;
V_19 = V_6 -> V_29 [ V_23 ] +
V_6 -> V_30 [ V_23 ] ;
V_20 = V_6 -> V_31 + V_19 ;
V_21 = 1 + F_4 ( V_20 * 3 , 4 ) ;
V_25 = F_5 ( V_2 , V_3 , V_21 ) ;
if ( V_25 < 0 )
return V_25 ;
V_17 -> V_19 = V_19 ;
V_17 -> V_32 = V_6 -> V_32 ;
V_17 -> V_4 = V_4 ;
V_17 -> V_33 = V_6 -> V_33 ;
V_17 -> V_34 = V_6 -> V_34 ;
V_17 -> V_35 = 0 ;
V_17 -> V_36 = V_3 / V_37 ;
V_22 = 0x2e00 ;
V_22 += 8000 * 3072 * V_2 -> V_38 / V_3 ;
V_17 -> V_39 = 0 ;
V_17 -> V_40 = V_22 / 3072 ;
V_17 -> V_7 = V_9 [ V_2 -> V_41 ] . V_7 ;
V_17 -> V_8 = V_9 [ V_2 -> V_41 ] . V_8 ;
V_17 -> V_42 = V_22 % 3072 ;
V_17 -> V_43 = 0 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
T_1 * V_46 , unsigned int V_47 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned int V_48 , V_49 , V_24 , V_50 ;
T_2 * V_51 ;
T_3 * V_52 ;
V_48 = V_17 -> V_19 ;
V_52 = ( void * ) V_45 -> V_53 +
F_7 ( V_45 , V_2 -> V_54 ) ;
V_49 = V_45 -> V_55 - V_2 -> V_54 ;
for ( V_24 = 0 ; V_24 < V_47 ; ++ V_24 ) {
V_51 = ( T_2 * ) V_46 + V_17 -> V_32 ;
for ( V_50 = 0 ; V_50 < V_48 ; ++ V_50 ) {
* V_52 = ( V_51 [ 0 ] << 24 ) | ( V_51 [ 1 ] << 16 ) | V_51 [ 2 ] ;
V_51 += 3 ;
V_52 ++ ;
}
V_46 += V_2 -> V_21 ;
if ( -- V_49 == 0 )
V_52 = ( void * ) V_45 -> V_53 ;
}
}
static void F_8 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
T_1 * V_46 , unsigned int V_47 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned int V_48 , V_49 , V_24 , V_50 ;
T_2 * V_51 ;
const T_3 * V_56 ;
V_48 = V_17 -> V_19 ;
V_56 = ( void * ) V_45 -> V_53 +
F_7 ( V_45 , V_2 -> V_54 ) ;
V_49 = V_45 -> V_55 - V_2 -> V_54 ;
for ( V_24 = 0 ; V_24 < V_47 ; ++ V_24 ) {
V_51 = ( T_2 * ) V_46 + V_17 -> V_32 ;
for ( V_50 = 0 ; V_50 < V_48 ; ++ V_50 ) {
V_51 [ 0 ] = ( * V_56 >> 24 ) & 0xff ;
V_51 [ 1 ] = ( * V_56 >> 16 ) & 0xff ;
V_51 [ 2 ] = ( * V_56 >> 8 ) & 0xff ;
V_51 += 3 ;
V_56 ++ ;
}
V_46 += V_2 -> V_21 ;
if ( -- V_49 == 0 )
V_56 = ( void * ) V_45 -> V_53 ;
}
}
static void F_9 ( struct V_1 * V_2 , T_1 * V_46 ,
unsigned int V_47 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned int V_48 , V_24 , V_50 ;
T_2 * V_51 ;
V_48 = V_17 -> V_19 ;
for ( V_24 = 0 ; V_24 < V_47 ; ++ V_24 ) {
V_51 = ( T_2 * ) V_46 + V_17 -> V_32 ;
for ( V_50 = 0 ; V_50 < V_48 ; ++ V_50 ) {
V_51 [ 0 ] = 0 ;
V_51 [ 1 ] = 0 ;
V_51 [ 2 ] = 0 ;
V_51 += 3 ;
}
V_46 += V_2 -> V_21 ;
}
}
int F_10 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
int V_25 ;
V_25 = F_11 ( V_45 , 0 , 32 , 24 ) ;
if ( V_25 < 0 )
return V_25 ;
return F_12 ( V_2 , V_45 ) ;
}
void F_13 ( struct V_1 * V_2 , unsigned int V_57 ,
struct V_58 * V_59 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
if ( V_57 < V_17 -> V_4 )
F_14 ( V_17 -> V_59 , V_59 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 * V_46 ,
unsigned int V_47 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
struct V_58 * V_59 = F_16 ( V_17 -> V_59 ) ;
T_2 * V_60 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_47 ; V_24 ++ ) {
V_60 = ( T_2 * ) V_46 ;
if ( V_59 && V_17 -> V_35 == 0 &&
F_17 ( V_59 , V_60 + V_17 -> V_34 , 1 ) == 1 ) {
V_60 [ V_17 -> V_33 ] = 0x01 ;
} else {
V_60 [ V_17 -> V_34 ] = 0x00 ;
V_60 [ V_17 -> V_33 ] = 0x00 ;
}
V_46 += V_2 -> V_21 ;
if ( -- V_17 -> V_35 < 0 )
V_17 -> V_35 = V_17 -> V_36 ;
}
}
static void F_18 ( struct V_1 * V_2 , T_1 * V_46 ,
unsigned int V_47 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
struct V_58 * V_59 ;
T_2 * V_60 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_47 ; V_24 ++ ) {
V_60 = ( T_2 * ) V_46 ;
V_59 = F_16 ( V_17 -> V_59 ) ;
if ( V_59 && ( V_60 [ V_17 -> V_33 ] & 0x01 ) )
F_19 ( V_59 , V_60 + V_17 -> V_34 , 1 ) ;
V_46 += V_2 -> V_21 ;
}
}
static void T_4 F_20 ( T_3 * V_61 , T_1 * V_46 ,
unsigned int V_47 ,
unsigned int V_21 )
{
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < V_47 ; ++ V_24 ) {
* V_61 = F_21 ( * V_46 ) ;
V_46 += V_21 ;
V_61 ++ ;
}
}
static void T_4 F_22 ( T_5 * V_61 , T_1 * V_46 ,
unsigned int V_47 ,
unsigned int V_21 )
{
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < V_47 ; ++ V_24 ) {
* V_61 = ( F_21 ( V_46 [ 1 ] ) << 16 ) |
( F_21 ( V_46 [ 2 ] ) >> 16 ) ;
V_46 += V_21 ;
V_61 ++ ;
}
}
static unsigned int F_23 ( struct V_1 * V_2 ,
T_1 * V_46 , unsigned int V_47 ,
unsigned int * V_62 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
struct V_63 * V_64 ;
F_24 ( V_2 , V_47 , V_46 ) ;
F_25 ( V_2 , V_47 , V_46 ) ;
if ( V_17 -> V_4 )
F_18 ( V_2 , V_46 , V_47 ) ;
V_64 = F_26 ( V_2 -> V_64 ) ;
if ( V_47 > 0 && V_64 )
F_6 ( V_2 , V_64 -> V_45 , V_46 , V_47 ) ;
return V_47 ;
}
static inline void F_27 ( struct V_16 * V_17 )
{
V_17 -> V_43 += V_17 -> V_8 ;
if ( V_17 -> V_43 >= 441 ) {
V_17 -> V_43 -= 441 ;
V_17 -> V_42 ++ ;
}
V_17 -> V_42 += V_17 -> V_7 ;
if ( V_17 -> V_42 >= 3072 ) {
V_17 -> V_42 -= 3072 ;
V_17 -> V_40 ++ ;
}
if ( V_17 -> V_40 >= 8000 ) {
V_17 -> V_40 -= 8000 ;
V_17 -> V_39 ++ ;
}
if ( V_17 -> V_39 >= 128 )
V_17 -> V_39 -= 128 ;
}
static void F_28 ( struct V_1 * V_2 , T_1 * V_46 ,
unsigned int V_47 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned int V_40 ;
unsigned int V_24 ;
T_3 V_65 ;
for ( V_24 = 0 ; V_24 < V_47 ; V_24 ++ ) {
V_40 = ( V_2 -> V_66 + V_17 -> V_40 ) % 8000 ;
V_65 = ( ( V_40 << 12 ) | V_17 -> V_42 ) & 0x01ffffff ;
* V_46 = F_29 ( V_65 ) ;
F_27 ( V_17 ) ;
V_46 += V_2 -> V_21 ;
}
}
static unsigned int F_30 ( struct V_1 * V_2 ,
T_1 * V_46 , unsigned int V_47 ,
unsigned int * V_62 )
{
struct V_16 * V_17 = (struct V_16 * ) V_2 -> V_18 ;
struct V_63 * V_64 ;
* V_62 = 0xffff ;
if ( V_17 -> V_4 )
F_15 ( V_2 , V_46 , V_47 ) ;
V_64 = F_26 ( V_2 -> V_64 ) ;
if ( V_64 )
F_8 ( V_2 , V_64 -> V_45 , V_46 , V_47 ) ;
else
F_9 ( V_2 , V_46 , V_47 ) ;
F_28 ( V_2 , V_46 , V_47 ) ;
F_31 ( V_2 , V_47 , V_46 ) ;
F_32 ( V_2 , V_47 , V_46 ) ;
return V_47 ;
}
int F_33 ( struct V_1 * V_2 , struct V_67 * V_68 ,
enum V_69 V_70 ,
const struct V_71 * const V_18 )
{
T_6 V_72 ;
int V_73 = V_74 ;
int V_75 = V_76 ;
int V_25 ;
if ( V_70 == V_77 ) {
V_72 = F_23 ;
if ( V_18 == & V_78 ) {
V_75 |= V_79 |
V_80 |
V_81 ;
V_73 = V_82 ;
}
} else {
V_72 = F_30 ;
V_75 |= V_83 ;
}
V_25 = F_34 ( V_2 , V_68 , V_70 , V_75 , V_73 , V_72 ,
sizeof( struct V_16 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_2 -> V_65 = 1 ;
V_2 -> V_84 = V_85 ;
return 0 ;
}
