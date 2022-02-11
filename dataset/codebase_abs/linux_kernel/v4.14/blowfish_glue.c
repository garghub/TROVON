static inline void F_1 ( struct V_1 * V_2 , T_1 * V_3 , const T_1 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , false ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , true ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_5 ( V_2 , V_3 , V_4 , false ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_5 ( V_2 , V_3 , V_4 , true ) ;
}
static void F_7 ( struct V_5 * V_6 , T_1 * V_3 , const T_1 * V_4 )
{
F_1 ( F_8 ( V_6 ) , V_3 , V_4 ) ;
}
static void F_9 ( struct V_5 * V_6 , T_1 * V_3 , const T_1 * V_4 )
{
F_10 ( F_8 ( V_6 ) , V_3 , V_4 ) ;
}
static int F_11 ( struct V_7 * V_8 , struct V_9 * V_10 ,
void (* F_12)( struct V_1 * , T_1 * , const T_1 * ) ,
void (* F_13)( struct V_1 * , T_1 * , const T_1 * ) )
{
struct V_1 * V_2 = F_14 ( V_8 -> V_6 ) ;
unsigned int V_11 = V_12 ;
unsigned int V_13 ;
int V_14 ;
V_14 = F_15 ( V_8 , V_10 ) ;
while ( ( V_13 = V_10 -> V_13 ) ) {
T_1 * V_15 = V_10 -> V_4 . V_16 . V_17 ;
T_1 * V_18 = V_10 -> V_3 . V_16 . V_17 ;
if ( V_13 >= V_11 * 4 ) {
do {
F_13 ( V_2 , V_18 , V_15 ) ;
V_15 += V_11 * 4 ;
V_18 += V_11 * 4 ;
V_13 -= V_11 * 4 ;
} while ( V_13 >= V_11 * 4 );
if ( V_13 < V_11 )
goto V_19;
}
do {
F_12 ( V_2 , V_18 , V_15 ) ;
V_15 += V_11 ;
V_18 += V_11 ;
V_13 -= V_11 ;
} while ( V_13 >= V_11 );
V_19:
V_14 = F_16 ( V_8 , V_10 , V_13 ) ;
}
return V_14 ;
}
static int F_17 ( struct V_7 * V_8 , struct V_20 * V_3 ,
struct V_20 * V_4 , unsigned int V_13 )
{
struct V_9 V_10 ;
F_18 ( & V_10 , V_3 , V_4 , V_13 ) ;
return F_11 ( V_8 , & V_10 , F_1 , F_4 ) ;
}
static int F_19 ( struct V_7 * V_8 , struct V_20 * V_3 ,
struct V_20 * V_4 , unsigned int V_13 )
{
struct V_9 V_10 ;
F_18 ( & V_10 , V_3 , V_4 , V_13 ) ;
return F_11 ( V_8 , & V_10 , F_10 , V_21 ) ;
}
static unsigned int F_20 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_14 ( V_8 -> V_6 ) ;
unsigned int V_11 = V_12 ;
unsigned int V_13 = V_10 -> V_13 ;
T_2 * V_4 = ( T_2 * ) V_10 -> V_4 . V_16 . V_17 ;
T_2 * V_3 = ( T_2 * ) V_10 -> V_3 . V_16 . V_17 ;
T_2 * V_22 = ( T_2 * ) V_10 -> V_22 ;
do {
* V_3 = * V_4 ^ * V_22 ;
F_1 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_3 ) ;
V_22 = V_3 ;
V_4 += 1 ;
V_3 += 1 ;
V_13 -= V_11 ;
} while ( V_13 >= V_11 );
* ( T_2 * ) V_10 -> V_22 = * V_22 ;
return V_13 ;
}
static int F_21 ( struct V_7 * V_8 , struct V_20 * V_3 ,
struct V_20 * V_4 , unsigned int V_13 )
{
struct V_9 V_10 ;
int V_14 ;
F_18 ( & V_10 , V_3 , V_4 , V_13 ) ;
V_14 = F_15 ( V_8 , & V_10 ) ;
while ( ( V_13 = V_10 . V_13 ) ) {
V_13 = F_20 ( V_8 , & V_10 ) ;
V_14 = F_16 ( V_8 , & V_10 , V_13 ) ;
}
return V_14 ;
}
static unsigned int F_22 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_14 ( V_8 -> V_6 ) ;
unsigned int V_11 = V_12 ;
unsigned int V_13 = V_10 -> V_13 ;
T_2 * V_4 = ( T_2 * ) V_10 -> V_4 . V_16 . V_17 ;
T_2 * V_3 = ( T_2 * ) V_10 -> V_3 . V_16 . V_17 ;
T_2 V_23 [ 4 - 1 ] ;
T_2 V_24 ;
V_4 += V_13 / V_11 - 1 ;
V_3 += V_13 / V_11 - 1 ;
V_24 = * V_4 ;
if ( V_13 >= V_11 * 4 ) {
do {
V_13 -= V_11 * 4 - V_11 ;
V_4 -= 4 - 1 ;
V_3 -= 4 - 1 ;
V_23 [ 0 ] = V_4 [ 0 ] ;
V_23 [ 1 ] = V_4 [ 1 ] ;
V_23 [ 2 ] = V_4 [ 2 ] ;
V_21 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
V_3 [ 1 ] ^= V_23 [ 0 ] ;
V_3 [ 2 ] ^= V_23 [ 1 ] ;
V_3 [ 3 ] ^= V_23 [ 2 ] ;
V_13 -= V_11 ;
if ( V_13 < V_11 )
goto V_19;
* V_3 ^= * ( V_4 - 1 ) ;
V_4 -= 1 ;
V_3 -= 1 ;
} while ( V_13 >= V_11 * 4 );
}
for (; ; ) {
F_10 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
V_13 -= V_11 ;
if ( V_13 < V_11 )
break;
* V_3 ^= * ( V_4 - 1 ) ;
V_4 -= 1 ;
V_3 -= 1 ;
}
V_19:
* V_3 ^= * ( T_2 * ) V_10 -> V_22 ;
* ( T_2 * ) V_10 -> V_22 = V_24 ;
return V_13 ;
}
static int F_23 ( struct V_7 * V_8 , struct V_20 * V_3 ,
struct V_20 * V_4 , unsigned int V_13 )
{
struct V_9 V_10 ;
int V_14 ;
F_18 ( & V_10 , V_3 , V_4 , V_13 ) ;
V_14 = F_15 ( V_8 , & V_10 ) ;
while ( ( V_13 = V_10 . V_13 ) ) {
V_13 = F_22 ( V_8 , & V_10 ) ;
V_14 = F_16 ( V_8 , & V_10 , V_13 ) ;
}
return V_14 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
T_1 * V_25 = V_10 -> V_22 ;
T_1 V_26 [ V_12 ] ;
T_1 * V_4 = V_10 -> V_4 . V_16 . V_17 ;
T_1 * V_3 = V_10 -> V_3 . V_16 . V_17 ;
unsigned int V_13 = V_10 -> V_13 ;
F_1 ( V_2 , V_26 , V_25 ) ;
F_25 ( V_3 , V_26 , V_4 , V_13 ) ;
F_26 ( V_25 , V_12 ) ;
}
static unsigned int F_27 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_14 ( V_8 -> V_6 ) ;
unsigned int V_11 = V_12 ;
unsigned int V_13 = V_10 -> V_13 ;
T_2 * V_4 = ( T_2 * ) V_10 -> V_4 . V_16 . V_17 ;
T_2 * V_3 = ( T_2 * ) V_10 -> V_3 . V_16 . V_17 ;
T_2 V_25 = F_28 ( * ( V_27 * ) V_10 -> V_22 ) ;
V_27 V_28 [ 4 ] ;
if ( V_13 >= V_11 * 4 ) {
do {
if ( V_3 != V_4 ) {
V_3 [ 0 ] = V_4 [ 0 ] ;
V_3 [ 1 ] = V_4 [ 1 ] ;
V_3 [ 2 ] = V_4 [ 2 ] ;
V_3 [ 3 ] = V_4 [ 3 ] ;
}
V_28 [ 0 ] = F_29 ( V_25 ++ ) ;
V_28 [ 1 ] = F_29 ( V_25 ++ ) ;
V_28 [ 2 ] = F_29 ( V_25 ++ ) ;
V_28 [ 3 ] = F_29 ( V_25 ++ ) ;
F_6 ( V_2 , ( T_1 * ) V_3 ,
( T_1 * ) V_28 ) ;
V_4 += 4 ;
V_3 += 4 ;
} while ( ( V_13 -= V_11 * 4 ) >= V_11 * 4 );
if ( V_13 < V_11 )
goto V_19;
}
do {
if ( V_3 != V_4 )
* V_3 = * V_4 ;
V_28 [ 0 ] = F_29 ( V_25 ++ ) ;
F_3 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_28 ) ;
V_4 += 1 ;
V_3 += 1 ;
} while ( ( V_13 -= V_11 ) >= V_11 );
V_19:
* ( V_27 * ) V_10 -> V_22 = F_29 ( V_25 ) ;
return V_13 ;
}
static int F_30 ( struct V_7 * V_8 , struct V_20 * V_3 ,
struct V_20 * V_4 , unsigned int V_13 )
{
struct V_9 V_10 ;
int V_14 ;
F_18 ( & V_10 , V_3 , V_4 , V_13 ) ;
V_14 = F_31 ( V_8 , & V_10 , V_12 ) ;
while ( ( V_13 = V_10 . V_13 ) >= V_12 ) {
V_13 = F_27 ( V_8 , & V_10 ) ;
V_14 = F_16 ( V_8 , & V_10 , V_13 ) ;
}
if ( V_10 . V_13 ) {
F_24 ( F_14 ( V_8 -> V_6 ) , & V_10 ) ;
V_14 = F_16 ( V_8 , & V_10 , 0 ) ;
}
return V_14 ;
}
static bool F_32 ( void )
{
if ( V_29 . V_30 != V_31 )
return false ;
if ( V_29 . V_32 == 0x0f ) {
return true ;
}
return false ;
}
static int T_3 F_33 ( void )
{
if ( ! V_33 && F_32 () ) {
F_34 ( V_34
L_1
L_2
L_3 ) ;
return - V_35 ;
}
return F_35 ( V_36 , F_36 ( V_36 ) ) ;
}
static void T_4 F_37 ( void )
{
F_38 ( V_36 , F_36 ( V_36 ) ) ;
}
