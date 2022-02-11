static void F_1 ( struct V_1 * V_2 , T_1 * V_3 , const T_1 * V_4 )
{
F_2 ( F_3 ( V_2 ) , V_3 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_3 , const T_1 * V_4 )
{
F_5 ( F_3 ( V_2 ) , V_3 , V_4 ) ;
}
static int F_6 ( struct V_5 * V_6 , struct V_7 * V_8 ,
void (* F_7)( struct V_9 * , T_1 * , const T_1 * ) ,
void (* F_8)( struct V_9 * , T_1 * , const T_1 * ) )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_2 ) ;
unsigned int V_11 = V_12 ;
unsigned int V_13 ;
int V_14 ;
V_14 = F_10 ( V_6 , V_8 ) ;
while ( ( V_13 = V_8 -> V_13 ) ) {
T_1 * V_15 = V_8 -> V_4 . V_16 . V_17 ;
T_1 * V_18 = V_8 -> V_3 . V_16 . V_17 ;
if ( V_13 >= V_11 * 4 ) {
do {
F_8 ( V_10 , V_18 , V_15 ) ;
V_15 += V_11 * 4 ;
V_18 += V_11 * 4 ;
V_13 -= V_11 * 4 ;
} while ( V_13 >= V_11 * 4 );
if ( V_13 < V_11 )
goto V_19;
}
do {
F_7 ( V_10 , V_18 , V_15 ) ;
V_15 += V_11 ;
V_18 += V_11 ;
V_13 -= V_11 ;
} while ( V_13 >= V_11 );
V_19:
V_14 = F_11 ( V_6 , V_8 , V_13 ) ;
}
return V_14 ;
}
static int F_12 ( struct V_5 * V_6 , struct V_20 * V_3 ,
struct V_20 * V_4 , unsigned int V_13 )
{
struct V_7 V_8 ;
F_13 ( & V_8 , V_3 , V_4 , V_13 ) ;
return F_6 ( V_6 , & V_8 , F_2 , V_21 ) ;
}
static int F_14 ( struct V_5 * V_6 , struct V_20 * V_3 ,
struct V_20 * V_4 , unsigned int V_13 )
{
struct V_7 V_8 ;
F_13 ( & V_8 , V_3 , V_4 , V_13 ) ;
return F_6 ( V_6 , & V_8 , F_5 , V_22 ) ;
}
static unsigned int F_15 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_2 ) ;
unsigned int V_11 = V_12 ;
unsigned int V_13 = V_8 -> V_13 ;
T_2 * V_4 = ( T_2 * ) V_8 -> V_4 . V_16 . V_17 ;
T_2 * V_3 = ( T_2 * ) V_8 -> V_3 . V_16 . V_17 ;
T_2 * V_23 = ( T_2 * ) V_8 -> V_23 ;
do {
* V_3 = * V_4 ^ * V_23 ;
F_2 ( V_10 , ( T_1 * ) V_3 , ( T_1 * ) V_3 ) ;
V_23 = V_3 ;
V_4 += 1 ;
V_3 += 1 ;
V_13 -= V_11 ;
} while ( V_13 >= V_11 );
* ( T_2 * ) V_8 -> V_23 = * V_23 ;
return V_13 ;
}
static int F_16 ( struct V_5 * V_6 , struct V_20 * V_3 ,
struct V_20 * V_4 , unsigned int V_13 )
{
struct V_7 V_8 ;
int V_14 ;
F_13 ( & V_8 , V_3 , V_4 , V_13 ) ;
V_14 = F_10 ( V_6 , & V_8 ) ;
while ( ( V_13 = V_8 . V_13 ) ) {
V_13 = F_15 ( V_6 , & V_8 ) ;
V_14 = F_11 ( V_6 , & V_8 , V_13 ) ;
}
return V_14 ;
}
static unsigned int F_17 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_2 ) ;
unsigned int V_11 = V_12 ;
unsigned int V_13 = V_8 -> V_13 ;
T_2 * V_4 = ( T_2 * ) V_8 -> V_4 . V_16 . V_17 ;
T_2 * V_3 = ( T_2 * ) V_8 -> V_3 . V_16 . V_17 ;
T_2 V_24 [ 4 - 1 ] ;
T_2 V_25 ;
V_4 += V_13 / V_11 - 1 ;
V_3 += V_13 / V_11 - 1 ;
V_25 = * V_4 ;
if ( V_13 >= V_11 * 4 ) {
do {
V_13 -= V_11 * 4 - V_11 ;
V_4 -= 4 - 1 ;
V_3 -= 4 - 1 ;
V_24 [ 0 ] = V_4 [ 0 ] ;
V_24 [ 1 ] = V_4 [ 1 ] ;
V_24 [ 2 ] = V_4 [ 2 ] ;
V_22 ( V_10 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
V_3 [ 1 ] ^= V_24 [ 0 ] ;
V_3 [ 2 ] ^= V_24 [ 1 ] ;
V_3 [ 3 ] ^= V_24 [ 2 ] ;
V_13 -= V_11 ;
if ( V_13 < V_11 )
goto V_19;
* V_3 ^= * ( V_4 - 1 ) ;
V_4 -= 1 ;
V_3 -= 1 ;
} while ( V_13 >= V_11 * 4 );
if ( V_13 < V_11 )
goto V_19;
}
for (; ; ) {
F_5 ( V_10 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
V_13 -= V_11 ;
if ( V_13 < V_11 )
break;
* V_3 ^= * ( V_4 - 1 ) ;
V_4 -= 1 ;
V_3 -= 1 ;
}
V_19:
* V_3 ^= * ( T_2 * ) V_8 -> V_23 ;
* ( T_2 * ) V_8 -> V_23 = V_25 ;
return V_13 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_20 * V_3 ,
struct V_20 * V_4 , unsigned int V_13 )
{
struct V_7 V_8 ;
int V_14 ;
F_13 ( & V_8 , V_3 , V_4 , V_13 ) ;
V_14 = F_10 ( V_6 , & V_8 ) ;
while ( ( V_13 = V_8 . V_13 ) ) {
V_13 = F_17 ( V_6 , & V_8 ) ;
V_14 = F_11 ( V_6 , & V_8 , V_13 ) ;
}
return V_14 ;
}
static void F_19 ( struct V_9 * V_10 , struct V_7 * V_8 )
{
T_1 * V_26 = V_8 -> V_23 ;
T_1 V_27 [ V_12 ] ;
T_1 * V_4 = V_8 -> V_4 . V_16 . V_17 ;
T_1 * V_3 = V_8 -> V_3 . V_16 . V_17 ;
unsigned int V_13 = V_8 -> V_13 ;
F_2 ( V_10 , V_27 , V_26 ) ;
F_20 ( V_27 , V_4 , V_13 ) ;
memcpy ( V_3 , V_27 , V_13 ) ;
F_21 ( V_26 , V_12 ) ;
}
static unsigned int F_22 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_2 ) ;
unsigned int V_11 = V_12 ;
unsigned int V_13 = V_8 -> V_13 ;
T_2 * V_4 = ( T_2 * ) V_8 -> V_4 . V_16 . V_17 ;
T_2 * V_3 = ( T_2 * ) V_8 -> V_3 . V_16 . V_17 ;
T_2 V_26 = F_23 ( * ( V_28 * ) V_8 -> V_23 ) ;
V_28 V_29 [ 4 ] ;
if ( V_13 >= V_11 * 4 ) {
do {
if ( V_3 != V_4 ) {
V_3 [ 0 ] = V_4 [ 0 ] ;
V_3 [ 1 ] = V_4 [ 1 ] ;
V_3 [ 2 ] = V_4 [ 2 ] ;
V_3 [ 3 ] = V_4 [ 3 ] ;
}
V_29 [ 0 ] = F_24 ( V_26 ++ ) ;
V_29 [ 1 ] = F_24 ( V_26 ++ ) ;
V_29 [ 2 ] = F_24 ( V_26 ++ ) ;
V_29 [ 3 ] = F_24 ( V_26 ++ ) ;
F_25 ( V_10 , ( T_1 * ) V_3 ,
( T_1 * ) V_29 ) ;
V_4 += 4 ;
V_3 += 4 ;
} while ( ( V_13 -= V_11 * 4 ) >= V_11 * 4 );
if ( V_13 < V_11 )
goto V_19;
}
do {
if ( V_3 != V_4 )
* V_3 = * V_4 ;
V_29 [ 0 ] = F_24 ( V_26 ++ ) ;
F_26 ( V_10 , ( T_1 * ) V_3 , ( T_1 * ) V_29 ) ;
V_4 += 1 ;
V_3 += 1 ;
} while ( ( V_13 -= V_11 ) >= V_11 );
V_19:
* ( V_28 * ) V_8 -> V_23 = F_24 ( V_26 ) ;
return V_13 ;
}
static int F_27 ( struct V_5 * V_6 , struct V_20 * V_3 ,
struct V_20 * V_4 , unsigned int V_13 )
{
struct V_7 V_8 ;
int V_14 ;
F_13 ( & V_8 , V_3 , V_4 , V_13 ) ;
V_14 = F_28 ( V_6 , & V_8 , V_12 ) ;
while ( ( V_13 = V_8 . V_13 ) >= V_12 ) {
V_13 = F_22 ( V_6 , & V_8 ) ;
V_14 = F_11 ( V_6 , & V_8 , V_13 ) ;
}
if ( V_8 . V_13 ) {
F_19 ( F_9 ( V_6 -> V_2 ) , & V_8 ) ;
V_14 = F_11 ( V_6 , & V_8 , 0 ) ;
}
return V_14 ;
}
static bool F_29 ( void )
{
if ( V_30 . V_31 != V_32 )
return false ;
if ( V_30 . V_33 == 0x0f ) {
return true ;
}
return false ;
}
static int T_3 F_30 ( void )
{
if ( ! V_34 && F_29 () ) {
F_31 ( V_35
L_1
L_2
L_3 ) ;
return - V_36 ;
}
return F_32 ( V_37 , F_33 ( V_37 ) ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( V_37 , F_33 ( V_37 ) ) ;
}
