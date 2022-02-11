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
T_2 * V_41 ;
V_33 = V_8 -> V_4 ;
V_41 = ( void * ) V_32 -> V_37 +
F_9 ( V_32 , V_2 -> V_38 ) ;
V_34 = V_32 -> V_39 - V_2 -> V_38 ;
for ( V_11 = 0 ; V_11 < V_30 ; ++ V_11 ) {
for ( V_35 = 0 ; V_35 < V_33 ; ++ V_35 ) {
* V_41 = F_12 ( V_29 [ V_8 -> V_20 [ V_35 ] ] ) << 8 ;
V_41 ++ ;
}
V_29 += V_2 -> V_40 ;
if ( -- V_34 == 0 )
V_41 = ( void * ) V_32 -> V_37 ;
}
}
static void F_13 ( struct V_1 * V_2 ,
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
int F_14 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_12 ;
V_12 = F_15 ( V_2 , V_32 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_16 ( V_32 , 0 , 32 , 24 ) ;
}
void F_17 ( struct V_1 * V_2 , unsigned int V_42 ,
struct V_43 * V_44 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_42 < V_8 -> V_5 )
F_18 ( V_8 -> V_44 [ V_42 ] ) = V_44 ;
}
static bool F_19 ( struct V_1 * V_2 , unsigned int V_42 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_45 ;
V_45 = V_8 -> V_46 [ V_42 ] ;
if ( V_45 == 0 )
return true ;
V_45 -= V_23 * V_2 -> V_24 ;
V_45 = F_20 ( V_45 , 0 ) ;
V_8 -> V_46 [ V_42 ] = V_45 ;
return V_45 < V_8 -> V_22 ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_42 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_46 [ V_42 ] += V_47 [ V_2 -> V_18 ] ;
}
static void F_22 ( struct V_1 * V_2 , T_1 * V_29 ,
unsigned int V_30 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_48 , V_42 ;
T_3 * V_49 ;
for ( V_48 = 0 ; V_48 < V_30 ; V_48 ++ ) {
V_49 = ( T_3 * ) & V_29 [ V_8 -> V_21 ] ;
V_42 = ( V_2 -> V_50 + V_48 ) % 8 ;
if ( V_48 < V_51 &&
F_19 ( V_2 , V_42 ) &&
V_8 -> V_44 [ V_42 ] != NULL &&
F_23 ( V_8 -> V_44 [ V_42 ] , & V_49 [ 1 ] , 1 ) == 1 ) {
F_21 ( V_2 , V_42 ) ;
V_49 [ 0 ] = 0x81 ;
} else {
V_49 [ 0 ] = 0x80 ;
V_49 [ 1 ] = 0 ;
}
V_49 [ 2 ] = 0 ;
V_49 [ 3 ] = 0 ;
V_29 += V_2 -> V_40 ;
}
}
static void F_24 ( struct V_1 * V_2 ,
T_1 * V_29 , unsigned int V_30 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_48 , V_42 ;
int V_52 ;
T_3 * V_49 ;
for ( V_48 = 0 ; V_48 < V_30 ; V_48 ++ ) {
V_42 = ( V_2 -> V_50 + V_48 ) % 8 ;
V_49 = ( T_3 * ) & V_29 [ V_8 -> V_21 ] ;
V_52 = V_49 [ 0 ] - 0x80 ;
if ( ( 1 <= V_52 ) && ( V_52 <= 3 ) && ( V_8 -> V_44 [ V_42 ] ) )
F_25 ( V_8 -> V_44 [ V_42 ] , V_49 + 1 , V_52 ) ;
V_29 += V_2 -> V_40 ;
}
}
static unsigned int F_26 ( struct V_1 * V_2 , T_1 * V_29 ,
unsigned int V_53 , unsigned int * V_54 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_27 * V_28 = F_18 ( V_2 -> V_28 ) ;
unsigned int V_55 ;
if ( V_28 ) {
F_8 ( V_2 , V_28 , V_29 , V_53 ) ;
V_55 = V_53 * V_8 -> V_19 ;
} else {
F_13 ( V_2 , V_29 , V_53 ) ;
V_55 = 0 ;
}
if ( V_8 -> V_5 )
F_22 ( V_2 , V_29 , V_53 ) ;
return V_55 ;
}
static unsigned int F_27 ( struct V_1 * V_2 , T_1 * V_29 ,
unsigned int V_53 , unsigned int * V_54 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_27 * V_28 = F_18 ( V_2 -> V_28 ) ;
unsigned int V_55 ;
if ( V_28 ) {
F_11 ( V_2 , V_28 , V_29 , V_53 ) ;
V_55 = V_53 * V_8 -> V_19 ;
} else {
V_55 = 0 ;
}
if ( V_8 -> V_5 )
F_24 ( V_2 , V_29 , V_53 ) ;
return V_55 ;
}
int F_28 ( struct V_1 * V_2 , struct V_56 * V_57 ,
enum V_58 V_59 , enum V_60 V_61 )
{
T_4 V_62 ;
if ( V_59 == V_63 )
V_62 = F_27 ;
else
V_62 = F_26 ;
return F_29 ( V_2 , V_57 , V_59 , V_61 , V_64 ,
V_62 ,
sizeof( struct V_7 ) ) ;
}
