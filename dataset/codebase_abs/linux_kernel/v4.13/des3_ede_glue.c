static inline void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
T_2 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 , V_3 , V_4 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
T_2 * V_7 = V_2 -> V_8 ;
F_2 ( V_7 , V_3 , V_4 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
T_2 * V_5 = V_2 -> V_6 ;
F_5 ( V_5 , V_3 , V_4 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
T_2 * V_7 = V_2 -> V_8 ;
F_5 ( V_7 , V_3 , V_4 ) ;
}
static void F_7 ( struct V_9 * V_10 , T_1 * V_3 , const T_1 * V_4 )
{
F_1 ( F_8 ( V_10 ) , V_3 , V_4 ) ;
}
static void F_9 ( struct V_9 * V_10 , T_1 * V_3 , const T_1 * V_4 )
{
F_3 ( F_8 ( V_10 ) , V_3 , V_4 ) ;
}
static int F_10 ( struct V_11 * V_12 , struct V_13 * V_14 ,
const T_2 * V_15 )
{
unsigned int V_16 = V_17 ;
unsigned int V_18 ;
int V_19 ;
V_19 = F_11 ( V_12 , V_14 ) ;
while ( ( V_18 = V_14 -> V_18 ) ) {
T_1 * V_20 = V_14 -> V_4 . V_21 . V_22 ;
T_1 * V_23 = V_14 -> V_3 . V_21 . V_22 ;
if ( V_18 >= V_16 * 3 ) {
do {
F_5 ( V_15 , V_23 ,
V_20 ) ;
V_20 += V_16 * 3 ;
V_23 += V_16 * 3 ;
V_18 -= V_16 * 3 ;
} while ( V_18 >= V_16 * 3 );
if ( V_18 < V_16 )
goto V_24;
}
do {
F_2 ( V_15 , V_23 , V_20 ) ;
V_20 += V_16 ;
V_23 += V_16 ;
V_18 -= V_16 ;
} while ( V_18 >= V_16 );
V_24:
V_19 = F_12 ( V_12 , V_14 , V_18 ) ;
}
return V_19 ;
}
static int F_13 ( struct V_11 * V_12 , struct V_25 * V_3 ,
struct V_25 * V_4 , unsigned int V_18 )
{
struct V_1 * V_2 = F_14 ( V_12 -> V_10 ) ;
struct V_13 V_14 ;
F_15 ( & V_14 , V_3 , V_4 , V_18 ) ;
return F_10 ( V_12 , & V_14 , V_2 -> V_6 ) ;
}
static int F_16 ( struct V_11 * V_12 , struct V_25 * V_3 ,
struct V_25 * V_4 , unsigned int V_18 )
{
struct V_1 * V_2 = F_14 ( V_12 -> V_10 ) ;
struct V_13 V_14 ;
F_15 ( & V_14 , V_3 , V_4 , V_18 ) ;
return F_10 ( V_12 , & V_14 , V_2 -> V_8 ) ;
}
static unsigned int F_17 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_12 -> V_10 ) ;
unsigned int V_16 = V_17 ;
unsigned int V_18 = V_14 -> V_18 ;
T_3 * V_4 = ( T_3 * ) V_14 -> V_4 . V_21 . V_22 ;
T_3 * V_3 = ( T_3 * ) V_14 -> V_3 . V_21 . V_22 ;
T_3 * V_26 = ( T_3 * ) V_14 -> V_26 ;
do {
* V_3 = * V_4 ^ * V_26 ;
F_1 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_3 ) ;
V_26 = V_3 ;
V_4 += 1 ;
V_3 += 1 ;
V_18 -= V_16 ;
} while ( V_18 >= V_16 );
* ( T_3 * ) V_14 -> V_26 = * V_26 ;
return V_18 ;
}
static int F_18 ( struct V_11 * V_12 , struct V_25 * V_3 ,
struct V_25 * V_4 , unsigned int V_18 )
{
struct V_13 V_14 ;
int V_19 ;
F_15 ( & V_14 , V_3 , V_4 , V_18 ) ;
V_19 = F_11 ( V_12 , & V_14 ) ;
while ( ( V_18 = V_14 . V_18 ) ) {
V_18 = F_17 ( V_12 , & V_14 ) ;
V_19 = F_12 ( V_12 , & V_14 , V_18 ) ;
}
return V_19 ;
}
static unsigned int F_19 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_12 -> V_10 ) ;
unsigned int V_16 = V_17 ;
unsigned int V_18 = V_14 -> V_18 ;
T_3 * V_4 = ( T_3 * ) V_14 -> V_4 . V_21 . V_22 ;
T_3 * V_3 = ( T_3 * ) V_14 -> V_3 . V_21 . V_22 ;
T_3 V_27 [ 3 - 1 ] ;
T_3 V_28 ;
V_4 += V_18 / V_16 - 1 ;
V_3 += V_18 / V_16 - 1 ;
V_28 = * V_4 ;
if ( V_18 >= V_16 * 3 ) {
do {
V_18 -= V_16 * 3 - V_16 ;
V_4 -= 3 - 1 ;
V_3 -= 3 - 1 ;
V_27 [ 0 ] = V_4 [ 0 ] ;
V_27 [ 1 ] = V_4 [ 1 ] ;
F_6 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
V_3 [ 1 ] ^= V_27 [ 0 ] ;
V_3 [ 2 ] ^= V_27 [ 1 ] ;
V_18 -= V_16 ;
if ( V_18 < V_16 )
goto V_24;
* V_3 ^= * ( V_4 - 1 ) ;
V_4 -= 1 ;
V_3 -= 1 ;
} while ( V_18 >= V_16 * 3 );
}
for (; ; ) {
F_3 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
V_18 -= V_16 ;
if ( V_18 < V_16 )
break;
* V_3 ^= * ( V_4 - 1 ) ;
V_4 -= 1 ;
V_3 -= 1 ;
}
V_24:
* V_3 ^= * ( T_3 * ) V_14 -> V_26 ;
* ( T_3 * ) V_14 -> V_26 = V_28 ;
return V_18 ;
}
static int F_20 ( struct V_11 * V_12 , struct V_25 * V_3 ,
struct V_25 * V_4 , unsigned int V_18 )
{
struct V_13 V_14 ;
int V_19 ;
F_15 ( & V_14 , V_3 , V_4 , V_18 ) ;
V_19 = F_11 ( V_12 , & V_14 ) ;
while ( ( V_18 = V_14 . V_18 ) ) {
V_18 = F_19 ( V_12 , & V_14 ) ;
V_19 = F_12 ( V_12 , & V_14 , V_18 ) ;
}
return V_19 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_1 * V_29 = V_14 -> V_26 ;
T_1 V_30 [ V_17 ] ;
T_1 * V_4 = V_14 -> V_4 . V_21 . V_22 ;
T_1 * V_3 = V_14 -> V_3 . V_21 . V_22 ;
unsigned int V_18 = V_14 -> V_18 ;
F_1 ( V_2 , V_30 , V_29 ) ;
F_22 ( V_30 , V_4 , V_18 ) ;
memcpy ( V_3 , V_30 , V_18 ) ;
F_23 ( V_29 , V_17 ) ;
}
static unsigned int F_24 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_12 -> V_10 ) ;
unsigned int V_16 = V_17 ;
unsigned int V_18 = V_14 -> V_18 ;
T_4 * V_4 = ( T_4 * ) V_14 -> V_4 . V_21 . V_22 ;
T_4 * V_3 = ( T_4 * ) V_14 -> V_3 . V_21 . V_22 ;
T_3 V_29 = F_25 ( * ( T_4 * ) V_14 -> V_26 ) ;
T_4 V_31 [ 3 ] ;
if ( V_18 >= V_16 * 3 ) {
do {
V_31 [ 0 ] = F_26 ( V_29 ++ ) ;
V_31 [ 1 ] = F_26 ( V_29 ++ ) ;
V_31 [ 2 ] = F_26 ( V_29 ++ ) ;
F_4 ( V_2 , ( T_1 * ) V_31 ,
( T_1 * ) V_31 ) ;
V_3 [ 0 ] = V_4 [ 0 ] ^ V_31 [ 0 ] ;
V_3 [ 1 ] = V_4 [ 1 ] ^ V_31 [ 1 ] ;
V_3 [ 2 ] = V_4 [ 2 ] ^ V_31 [ 2 ] ;
V_4 += 3 ;
V_3 += 3 ;
} while ( ( V_18 -= V_16 * 3 ) >= V_16 * 3 );
if ( V_18 < V_16 )
goto V_24;
}
do {
V_31 [ 0 ] = F_26 ( V_29 ++ ) ;
F_1 ( V_2 , ( T_1 * ) V_31 , ( T_1 * ) V_31 ) ;
V_3 [ 0 ] = V_4 [ 0 ] ^ V_31 [ 0 ] ;
V_4 += 1 ;
V_3 += 1 ;
} while ( ( V_18 -= V_16 ) >= V_16 );
V_24:
* ( T_4 * ) V_14 -> V_26 = F_26 ( V_29 ) ;
return V_18 ;
}
static int F_27 ( struct V_11 * V_12 , struct V_25 * V_3 ,
struct V_25 * V_4 , unsigned int V_18 )
{
struct V_13 V_14 ;
int V_19 ;
F_15 ( & V_14 , V_3 , V_4 , V_18 ) ;
V_19 = F_28 ( V_12 , & V_14 , V_17 ) ;
while ( ( V_18 = V_14 . V_18 ) >= V_17 ) {
V_18 = F_24 ( V_12 , & V_14 ) ;
V_19 = F_12 ( V_12 , & V_14 , V_18 ) ;
}
if ( V_14 . V_18 ) {
F_21 ( F_14 ( V_12 -> V_10 ) , & V_14 ) ;
V_19 = F_12 ( V_12 , & V_14 , 0 ) ;
}
return V_19 ;
}
static int F_29 ( struct V_9 * V_10 , const T_1 * V_32 ,
unsigned int V_33 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
T_2 V_34 , V_35 , V_36 ;
int V_19 ;
V_19 = F_30 ( V_2 -> V_6 , & V_10 -> V_37 , V_32 , V_33 ) ;
if ( V_19 < 0 )
return V_19 ;
V_35 = V_38 - 2 ;
for ( V_34 = 0 ; V_34 < V_38 ; V_34 += 2 , V_35 -= 2 ) {
V_36 = F_31 ( V_2 -> V_6 [ V_34 + 1 ] , 4 ) ;
V_2 -> V_6 [ V_34 + 1 ] = V_36 ;
V_2 -> V_8 [ V_35 + 0 ] = V_2 -> V_6 [ V_34 + 0 ] ;
V_2 -> V_8 [ V_35 + 1 ] = V_36 ;
}
return 0 ;
}
static bool F_32 ( void )
{
if ( V_39 . V_40 != V_41 )
return false ;
if ( V_39 . V_42 == 0x0f ) {
return true ;
}
return false ;
}
static int T_5 F_33 ( void )
{
if ( ! V_43 && F_32 () ) {
F_34 ( L_1 ) ;
return - V_44 ;
}
return F_35 ( V_45 , F_36 ( V_45 ) ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( V_45 , F_36 ( V_45 ) ) ;
}
