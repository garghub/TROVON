static T_1 F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
T_1 time = 0 ;
T_1 V_5 = 0 ;
unsigned int V_6 = 0 ;
unsigned int V_7 = ( 1 << V_3 ) - 1 ;
F_2 ( & time ) ;
if ( V_2 )
time ^= V_2 -> V_8 ;
for ( V_6 = 0 ; ( V_9 / V_3 ) > V_6 ; V_6 ++ ) {
V_5 ^= time & V_7 ;
time = time >> V_3 ;
}
return ( V_5 + ( 1 << V_4 ) ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 time ,
T_1 * V_10 , T_1 V_11 )
{
unsigned int V_6 ;
T_1 V_12 = 0 ;
T_1 V_13 = 0 ;
#define F_4 4
#define F_5 0
T_1 V_14 =
F_1 ( V_2 , F_4 , F_5 ) ;
if ( V_11 )
V_14 = V_11 ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 ++ ) {
V_13 = 0 ;
for ( V_6 = 1 ; ( V_9 ) >= V_6 ; V_6 ++ ) {
T_1 V_15 = time << ( V_9 - V_6 ) ;
V_15 = V_15 >> ( V_9 - 1 ) ;
V_13 ^= V_15 ;
}
}
* V_10 = V_13 ;
return V_14 ;
}
static unsigned int F_6 ( struct V_1 * V_2 , T_1 V_11 )
{
unsigned char * V_16 = NULL ;
unsigned int V_17 = 0 ;
T_1 V_6 = 0 ;
#define F_7 7
#define F_8 0
T_1 V_18 =
F_1 ( V_2 , F_7 , F_8 ) ;
if ( NULL == V_2 || NULL == V_2 -> V_19 )
return 0 ;
V_17 = V_2 -> V_20 * V_2 -> V_21 ;
if ( V_11 )
V_18 = V_11 ;
for ( V_6 = 0 ; V_6 < ( V_2 -> V_22 + V_18 ) ; V_6 ++ ) {
V_16 = V_2 -> V_19 + V_2 -> V_23 ;
* V_16 = ( * V_16 + 1 ) & 0xff ;
V_2 -> V_23 = V_2 -> V_23 + V_2 -> V_20 - 1 ;
V_2 -> V_23 = V_2 -> V_23 % V_17 ;
}
return V_6 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_24 )
{
T_2 V_25 = V_2 -> V_26 - V_24 ;
T_2 V_27 = V_25 - V_2 -> V_28 ;
V_2 -> V_26 = V_24 ;
V_2 -> V_28 = V_25 ;
if ( ! V_24 || ! V_25 || ! V_27 )
V_2 -> V_29 = 1 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
T_1 time = 0 ;
T_1 V_8 = 0 ;
T_1 V_24 = 0 ;
F_6 ( V_2 , 0 ) ;
F_2 ( & time ) ;
V_24 = time - V_2 -> V_30 ;
V_2 -> V_30 = time ;
F_3 ( V_2 , V_24 , & V_8 , 0 ) ;
F_9 ( V_2 , V_24 ) ;
return V_8 ;
}
static T_1 F_11 ( struct V_1 * V_31 )
{
do {
T_1 V_32 = F_10 ( V_31 ) ;
T_1 V_33 = F_10 ( V_31 ) ;
if ( V_32 == V_33 )
continue;
if ( 1 == V_32 )
return 1 ;
else
return 0 ;
} while ( 1 );
}
static void F_12 ( struct V_1 * V_31 )
{
union T_3 {
T_1 V_34 ;
T_4 V_35 [ 2 ] ;
};
union T_3 V_36 ;
union T_3 V_37 ;
unsigned int V_6 = 0 ;
V_36 . V_35 [ 1 ] = 0x67452301 ;
V_36 . V_35 [ 0 ] = 0xefcdab89 ;
V_37 . V_35 [ 1 ] = 0x98badcfe ;
V_37 . V_35 [ 0 ] = 0x10325476 ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( ( V_31 -> V_8 >> V_6 ) & 1 )
V_37 . V_34 ^= V_36 . V_34 ;
V_37 . V_34 = F_13 ( V_37 . V_34 , 1 ) ;
}
V_31 -> V_8 ^= V_37 . V_34 ;
}
static void F_14 ( struct V_1 * V_2 )
{
unsigned int V_38 = 0 ;
F_10 ( V_2 ) ;
while ( 1 ) {
T_1 V_8 = 0 ;
if ( V_2 -> V_39 == 1 )
V_8 = F_10 ( V_2 ) ;
else
V_8 = F_11 ( V_2 ) ;
if ( V_2 -> V_29 ) {
V_2 -> V_8 ^= V_8 ;
V_2 -> V_29 = 0 ;
continue;
}
V_2 -> V_8 ^= V_8 ;
V_2 -> V_8 ^= ( ( V_2 -> V_8 >> 63 ) & 1 ) ;
V_2 -> V_8 ^= ( ( V_2 -> V_8 >> 60 ) & 1 ) ;
V_2 -> V_8 ^= ( ( V_2 -> V_8 >> 55 ) & 1 ) ;
V_2 -> V_8 ^= ( ( V_2 -> V_8 >> 30 ) & 1 ) ;
V_2 -> V_8 ^= ( ( V_2 -> V_8 >> 27 ) & 1 ) ;
V_2 -> V_8 ^= ( ( V_2 -> V_8 >> 22 ) & 1 ) ;
V_2 -> V_8 = F_13 ( V_2 -> V_8 , 1 ) ;
if ( ++ V_38 >= ( V_9 * V_2 -> V_40 ) )
break;
}
if ( V_2 -> V_41 )
F_12 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( ! F_16 () )
return;
if ( ! V_2 -> V_42 ) {
V_2 -> V_42 = V_2 -> V_8 ;
F_14 ( V_2 ) ;
}
if ( V_2 -> V_8 == V_2 -> V_42 )
F_17 ( L_1 ) ;
V_2 -> V_42 = V_2 -> V_8 ;
}
int F_18 ( struct V_1 * V_2 , unsigned char * V_8 ,
unsigned int V_43 )
{
unsigned char * V_44 = V_8 ;
if ( ! V_2 )
return - 1 ;
while ( 0 < V_43 ) {
unsigned int V_45 ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( ( V_9 / 8 ) < V_43 )
V_45 = ( V_9 / 8 ) ;
else
V_45 = V_43 ;
F_19 ( V_44 , & V_2 -> V_8 , V_45 ) ;
V_43 -= V_45 ;
V_44 += V_45 ;
}
return 0 ;
}
struct V_1 * F_20 ( unsigned int V_40 ,
unsigned int V_46 )
{
struct V_1 * V_31 ;
V_31 = F_21 ( sizeof( struct V_1 ) ) ;
if ( ! V_31 )
return NULL ;
if ( ! ( V_46 & V_47 ) ) {
V_31 -> V_19 = F_21 ( V_48 ) ;
if ( ! V_31 -> V_19 ) {
F_22 ( V_31 ) ;
return NULL ;
}
V_31 -> V_20 = V_49 ;
V_31 -> V_21 = V_50 ;
V_31 -> V_22 = V_51 ;
}
if ( 0 == V_40 )
V_40 = 1 ;
V_31 -> V_40 = V_40 ;
V_31 -> V_41 = 1 ;
if ( V_46 & V_52 )
V_31 -> V_41 = 0 ;
if ( V_46 & V_53 )
V_31 -> V_39 = 1 ;
F_14 ( V_31 ) ;
return V_31 ;
}
void F_23 ( struct V_1 * V_31 )
{
F_22 ( V_31 -> V_19 ) ;
V_31 -> V_19 = NULL ;
F_22 ( V_31 ) ;
V_31 = NULL ;
}
int F_24 ( void )
{
int V_6 ;
T_1 V_54 = 0 ;
T_1 V_55 = 0 ;
int V_56 = 0 ;
int V_57 = 0 ;
int V_58 = 0 ;
#define F_25 300
#define F_26 100
for ( V_6 = 0 ; ( F_25 + F_26 ) > V_6 ; V_6 ++ ) {
T_1 time = 0 ;
T_1 V_59 = 0 ;
T_1 V_10 = 0 ;
T_1 V_60 = 0 ;
unsigned int V_61 = 0 ;
F_2 ( & time ) ;
F_3 ( NULL , time , & V_10 , 1 << F_5 ) ;
F_2 ( & V_59 ) ;
if ( ! time || ! V_59 )
return V_62 ;
V_60 = V_59 - time ;
if ( ! V_60 )
return V_63 ;
if ( F_26 > V_6 )
continue;
if ( ! ( V_59 > time ) )
V_56 ++ ;
V_61 = V_59 - time ;
if ( ! ( V_61 % 100 ) )
V_58 ++ ;
if ( V_6 ) {
if ( V_60 != V_55 )
V_57 ++ ;
if ( V_60 > V_55 )
V_54 += ( V_60 - V_55 ) ;
else
V_54 += ( V_55 - V_60 ) ;
}
V_55 = V_60 ;
}
if ( 3 < V_56 )
return V_64 ;
if ( ! V_54 )
return V_65 ;
if ( V_54 <= 1 )
return V_66 ;
if ( ( F_25 / 10 * 9 ) < V_58 )
return V_63 ;
return 0 ;
}
