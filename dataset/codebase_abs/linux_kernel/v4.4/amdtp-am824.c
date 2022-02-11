int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
unsigned int V_5 ,
bool V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_10 ;
unsigned int V_11 ;
int V_12 ;
if ( F_2 ( V_2 ) )
return - V_13 ;
if ( V_4 > V_14 )
return - V_13 ;
V_10 = F_3 ( V_5 , 8 ) ;
if ( V_10 > V_15 )
return - V_13 ;
if ( F_4 ( F_2 ( V_2 ) ) ||
F_4 ( V_4 > V_14 ) ||
F_4 ( V_10 > V_15 ) )
return - V_13 ;
V_12 = F_5 ( V_2 , V_3 ,
V_4 + V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_16 = V_17 | V_2 -> V_18 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_5 = V_5 ;
if ( V_6 )
V_8 -> V_19 = 2 ;
else
V_8 -> V_19 = 1 ;
for ( V_11 = 0 ; V_11 < V_4 ; V_11 ++ )
V_8 -> V_20 [ V_11 ] = V_11 ;
V_8 -> V_21 = V_8 -> V_4 ;
V_8 -> V_22 = V_3 - V_23 * V_2 -> V_24 + 1 ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 , unsigned int V_25 ,
unsigned int V_26 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_25 < V_8 -> V_4 )
V_8 -> V_20 [ V_25 ] = V_26 ;
}
void F_7 ( struct V_1 * V_2 ,
unsigned int V_26 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_21 = V_26 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
T_1 * V_29 , unsigned int V_30 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_31 * V_32 = V_28 -> V_32 ;
unsigned int V_33 , V_34 , V_11 , V_35 ;
const T_2 * V_36 ;
V_33 = V_8 -> V_4 ;
V_36 = ( void * ) V_32 -> V_37 +
F_9 ( V_32 , V_2 -> V_38 ) ;
V_34 = V_32 -> V_39 - V_2 -> V_38 ;
for ( V_11 = 0 ; V_11 < V_30 ; ++ V_11 ) {
for ( V_35 = 0 ; V_35 < V_33 ; ++ V_35 ) {
V_29 [ V_8 -> V_20 [ V_35 ] ] =
F_10 ( ( * V_36 >> 8 ) | 0x40000000 ) ;
V_36 ++ ;
}
V_29 += V_2 -> V_40 ;
if ( -- V_34 == 0 )
V_36 = ( void * ) V_32 -> V_37 ;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
T_1 * V_29 , unsigned int V_30 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_31 * V_32 = V_28 -> V_32 ;
unsigned int V_33 , V_34 , V_11 , V_35 ;
const T_3 * V_36 ;
V_33 = V_8 -> V_4 ;
V_36 = ( void * ) V_32 -> V_37 +
F_9 ( V_32 , V_2 -> V_38 ) ;
V_34 = V_32 -> V_39 - V_2 -> V_38 ;
for ( V_11 = 0 ; V_11 < V_30 ; ++ V_11 ) {
for ( V_35 = 0 ; V_35 < V_33 ; ++ V_35 ) {
V_29 [ V_8 -> V_20 [ V_35 ] ] =
F_10 ( ( * V_36 << 8 ) | 0x42000000 ) ;
V_36 ++ ;
}
V_29 += V_2 -> V_40 ;
if ( -- V_34 == 0 )
V_36 = ( void * ) V_32 -> V_37 ;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
T_1 * V_29 , unsigned int V_30 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_31 * V_32 = V_28 -> V_32 ;
unsigned int V_33 , V_34 , V_11 , V_35 ;
T_2 * V_41 ;
V_33 = V_8 -> V_4 ;
V_41 = ( void * ) V_32 -> V_37 +
F_9 ( V_32 , V_2 -> V_38 ) ;
V_34 = V_32 -> V_39 - V_2 -> V_38 ;
for ( V_11 = 0 ; V_11 < V_30 ; ++ V_11 ) {
for ( V_35 = 0 ; V_35 < V_33 ; ++ V_35 ) {
* V_41 = F_13 ( V_29 [ V_8 -> V_20 [ V_35 ] ] ) << 8 ;
V_41 ++ ;
}
V_29 += V_2 -> V_40 ;
if ( -- V_34 == 0 )
V_41 = ( void * ) V_32 -> V_37 ;
}
}
static void F_14 ( struct V_1 * V_2 ,
T_1 * V_29 , unsigned int V_30 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_11 , V_35 , V_33 = V_8 -> V_4 ;
for ( V_11 = 0 ; V_11 < V_30 ; ++ V_11 ) {
for ( V_35 = 0 ; V_35 < V_33 ; ++ V_35 )
V_29 [ V_8 -> V_20 [ V_35 ] ] = F_10 ( 0x40000000 ) ;
V_29 += V_2 -> V_40 ;
}
}
void F_15 ( struct V_1 * V_2 , T_4 V_42 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( F_4 ( F_16 ( V_2 ) ) )
return;
switch ( V_42 ) {
default:
F_4 ( 1 ) ;
case V_43 :
if ( V_2 -> V_44 == V_45 ) {
V_8 -> V_46 = F_11 ;
break;
}
F_4 ( 1 ) ;
case V_47 :
if ( V_2 -> V_44 == V_45 )
V_8 -> V_46 = F_8 ;
else
V_8 -> V_46 = F_12 ;
break;
}
}
int F_17 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_12 ;
V_12 = F_18 ( V_2 , V_32 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_19 ( V_32 , 0 , 32 , 24 ) ;
}
void F_20 ( struct V_1 * V_2 , unsigned int V_48 ,
struct V_49 * V_50 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_48 < V_8 -> V_5 )
F_21 ( V_8 -> V_50 [ V_48 ] ) = V_50 ;
}
static bool F_22 ( struct V_1 * V_2 , unsigned int V_48 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_51 ;
V_51 = V_8 -> V_52 [ V_48 ] ;
if ( V_51 == 0 )
return true ;
V_51 -= V_23 * V_2 -> V_24 ;
V_51 = F_23 ( V_51 , 0 ) ;
V_8 -> V_52 [ V_48 ] = V_51 ;
return V_51 < V_8 -> V_22 ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_48 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_52 [ V_48 ] += V_53 [ V_2 -> V_18 ] ;
}
static void F_25 ( struct V_1 * V_2 , T_1 * V_29 ,
unsigned int V_30 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_54 , V_48 ;
T_5 * V_55 ;
for ( V_54 = 0 ; V_54 < V_30 ; V_54 ++ ) {
V_55 = ( T_5 * ) & V_29 [ V_8 -> V_21 ] ;
V_48 = ( V_2 -> V_56 + V_54 ) % 8 ;
if ( V_54 < V_57 &&
F_22 ( V_2 , V_48 ) &&
V_8 -> V_50 [ V_48 ] != NULL &&
F_26 ( V_8 -> V_50 [ V_48 ] , & V_55 [ 1 ] , 1 ) == 1 ) {
F_24 ( V_2 , V_48 ) ;
V_55 [ 0 ] = 0x81 ;
} else {
V_55 [ 0 ] = 0x80 ;
V_55 [ 1 ] = 0 ;
}
V_55 [ 2 ] = 0 ;
V_55 [ 3 ] = 0 ;
V_29 += V_2 -> V_40 ;
}
}
static void F_27 ( struct V_1 * V_2 ,
T_1 * V_29 , unsigned int V_30 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_54 , V_48 ;
int V_58 ;
T_5 * V_55 ;
for ( V_54 = 0 ; V_54 < V_30 ; V_54 ++ ) {
V_48 = ( V_2 -> V_56 + V_54 ) % 8 ;
V_55 = ( T_5 * ) & V_29 [ V_8 -> V_21 ] ;
V_58 = V_55 [ 0 ] - 0x80 ;
if ( ( 1 <= V_58 ) && ( V_58 <= 3 ) && ( V_8 -> V_50 [ V_48 ] ) )
F_28 ( V_8 -> V_50 [ V_48 ] , V_55 + 1 , V_58 ) ;
V_29 += V_2 -> V_40 ;
}
}
static unsigned int F_29 ( struct V_1 * V_2 , T_1 * V_29 ,
unsigned int V_59 , unsigned int * V_60 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_27 * V_28 = F_21 ( V_2 -> V_28 ) ;
unsigned int V_61 ;
if ( V_28 ) {
V_8 -> V_46 ( V_2 , V_28 , V_29 , V_59 ) ;
V_61 = V_59 * V_8 -> V_19 ;
} else {
F_14 ( V_2 , V_29 , V_59 ) ;
V_61 = 0 ;
}
if ( V_8 -> V_5 )
F_25 ( V_2 , V_29 , V_59 ) ;
return V_61 ;
}
static unsigned int F_30 ( struct V_1 * V_2 , T_1 * V_29 ,
unsigned int V_59 , unsigned int * V_60 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_27 * V_28 = F_21 ( V_2 -> V_28 ) ;
unsigned int V_61 ;
if ( V_28 ) {
V_8 -> V_46 ( V_2 , V_28 , V_29 , V_59 ) ;
V_61 = V_59 * V_8 -> V_19 ;
} else {
V_61 = 0 ;
}
if ( V_8 -> V_5 )
F_27 ( V_2 , V_29 , V_59 ) ;
return V_61 ;
}
int F_31 ( struct V_1 * V_2 , struct V_62 * V_63 ,
enum V_64 V_65 , enum V_66 V_67 )
{
T_6 V_68 ;
if ( V_65 == V_69 )
V_68 = F_30 ;
else
V_68 = F_29 ;
return F_32 ( V_2 , V_63 , V_65 , V_67 , V_70 ,
V_68 ,
sizeof( struct V_7 ) ) ;
}
