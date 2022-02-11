static inline void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , false ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_2 ( V_2 , V_3 , V_4 , true ) ;
}
static int F_4 ( struct V_5 * V_6 , struct V_7 * V_8 ,
void (* F_5)( struct V_1 * , T_1 * , const T_1 * ) ,
void (* F_6)( struct V_1 * , T_1 * , const T_1 * ) )
{
struct V_1 * V_2 = F_7 ( V_6 -> V_9 ) ;
unsigned int V_10 = V_11 ;
unsigned int V_12 ;
int V_13 ;
V_13 = F_8 ( V_6 , V_8 ) ;
while ( ( V_12 = V_8 -> V_12 ) ) {
T_1 * V_14 = V_8 -> V_4 . V_15 . V_16 ;
T_1 * V_17 = V_8 -> V_3 . V_15 . V_16 ;
if ( V_12 >= V_10 * 3 ) {
do {
F_6 ( V_2 , V_17 , V_14 ) ;
V_14 += V_10 * 3 ;
V_17 += V_10 * 3 ;
V_12 -= V_10 * 3 ;
} while ( V_12 >= V_10 * 3 );
if ( V_12 < V_10 )
goto V_18;
}
do {
F_5 ( V_2 , V_17 , V_14 ) ;
V_14 += V_10 ;
V_17 += V_10 ;
V_12 -= V_10 ;
} while ( V_12 >= V_10 );
V_18:
V_13 = F_9 ( V_6 , V_8 , V_12 ) ;
}
return V_13 ;
}
static int F_10 ( struct V_5 * V_6 , struct V_19 * V_3 ,
struct V_19 * V_4 , unsigned int V_12 )
{
struct V_7 V_8 ;
F_11 ( & V_8 , V_3 , V_4 , V_12 ) ;
return F_4 ( V_6 , & V_8 , V_20 , F_1 ) ;
}
static int F_12 ( struct V_5 * V_6 , struct V_19 * V_3 ,
struct V_19 * V_4 , unsigned int V_12 )
{
struct V_7 V_8 ;
F_11 ( & V_8 , V_3 , V_4 , V_12 ) ;
return F_4 ( V_6 , & V_8 , V_21 , V_22 ) ;
}
static unsigned int F_13 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_7 ( V_6 -> V_9 ) ;
unsigned int V_10 = V_11 ;
unsigned int V_12 = V_8 -> V_12 ;
T_2 * V_4 = ( T_2 * ) V_8 -> V_4 . V_15 . V_16 ;
T_2 * V_3 = ( T_2 * ) V_8 -> V_3 . V_15 . V_16 ;
T_2 * V_23 = ( T_2 * ) V_8 -> V_23 ;
do {
F_14 ( V_3 , V_4 , V_23 ) ;
V_20 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_3 ) ;
V_23 = V_3 ;
V_4 += 1 ;
V_3 += 1 ;
V_12 -= V_10 ;
} while ( V_12 >= V_10 );
F_14 ( ( T_2 * ) V_8 -> V_23 , ( T_2 * ) V_8 -> V_23 , V_23 ) ;
return V_12 ;
}
static int F_15 ( struct V_5 * V_6 , struct V_19 * V_3 ,
struct V_19 * V_4 , unsigned int V_12 )
{
struct V_7 V_8 ;
int V_13 ;
F_11 ( & V_8 , V_3 , V_4 , V_12 ) ;
V_13 = F_8 ( V_6 , & V_8 ) ;
while ( ( V_12 = V_8 . V_12 ) ) {
V_12 = F_13 ( V_6 , & V_8 ) ;
V_13 = F_9 ( V_6 , & V_8 , V_12 ) ;
}
return V_13 ;
}
static unsigned int F_16 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_7 ( V_6 -> V_9 ) ;
unsigned int V_10 = V_11 ;
unsigned int V_12 = V_8 -> V_12 ;
T_2 * V_4 = ( T_2 * ) V_8 -> V_4 . V_15 . V_16 ;
T_2 * V_3 = ( T_2 * ) V_8 -> V_3 . V_15 . V_16 ;
T_2 V_24 [ 3 - 1 ] ;
T_2 V_25 ;
V_4 += V_12 / V_10 - 1 ;
V_3 += V_12 / V_10 - 1 ;
V_25 = * V_4 ;
if ( V_12 >= V_10 * 3 ) {
do {
V_12 -= V_10 * ( 3 - 1 ) ;
V_4 -= 3 - 1 ;
V_3 -= 3 - 1 ;
V_24 [ 0 ] = V_4 [ 0 ] ;
V_24 [ 1 ] = V_4 [ 1 ] ;
V_22 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
F_14 ( V_3 + 1 , V_3 + 1 , V_24 + 0 ) ;
F_14 ( V_3 + 2 , V_3 + 2 , V_24 + 1 ) ;
V_12 -= V_10 ;
if ( V_12 < V_10 )
goto V_18;
F_14 ( V_3 , V_3 , V_4 - 1 ) ;
V_4 -= 1 ;
V_3 -= 1 ;
} while ( V_12 >= V_10 * 3 );
if ( V_12 < V_10 )
goto V_18;
}
for (; ; ) {
V_21 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
V_12 -= V_10 ;
if ( V_12 < V_10 )
break;
F_14 ( V_3 , V_3 , V_4 - 1 ) ;
V_4 -= 1 ;
V_3 -= 1 ;
}
V_18:
F_14 ( V_3 , V_3 , ( T_2 * ) V_8 -> V_23 ) ;
* ( T_2 * ) V_8 -> V_23 = V_25 ;
return V_12 ;
}
static int F_17 ( struct V_5 * V_6 , struct V_19 * V_3 ,
struct V_19 * V_4 , unsigned int V_12 )
{
struct V_7 V_8 ;
int V_13 ;
F_11 ( & V_8 , V_3 , V_4 , V_12 ) ;
V_13 = F_8 ( V_6 , & V_8 ) ;
while ( ( V_12 = V_8 . V_12 ) ) {
V_12 = F_16 ( V_6 , & V_8 ) ;
V_13 = F_9 ( V_6 , & V_8 , V_12 ) ;
}
return V_13 ;
}
static inline void F_18 ( T_3 * V_3 , const T_2 * V_4 )
{
V_3 -> V_26 = F_19 ( V_4 -> V_26 ) ;
V_3 -> V_27 = F_19 ( V_4 -> V_27 ) ;
}
static inline void F_20 ( T_2 * V_3 , const T_3 * V_4 )
{
V_3 -> V_26 = F_21 ( V_4 -> V_26 ) ;
V_3 -> V_27 = F_21 ( V_4 -> V_27 ) ;
}
static inline void F_22 ( T_2 * V_28 )
{
V_28 -> V_27 ++ ;
if ( ! V_28 -> V_27 )
V_28 -> V_26 ++ ;
}
static void F_23 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_7 ( V_6 -> V_9 ) ;
T_1 * V_29 = V_8 -> V_23 ;
T_1 V_30 [ V_11 ] ;
T_1 * V_4 = V_8 -> V_4 . V_15 . V_16 ;
T_1 * V_3 = V_8 -> V_3 . V_15 . V_16 ;
unsigned int V_12 = V_8 -> V_12 ;
V_20 ( V_2 , V_30 , V_29 ) ;
F_24 ( V_30 , V_4 , V_12 ) ;
memcpy ( V_3 , V_30 , V_12 ) ;
F_25 ( V_29 , V_11 ) ;
}
static unsigned int F_26 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_7 ( V_6 -> V_9 ) ;
unsigned int V_10 = V_11 ;
unsigned int V_12 = V_8 -> V_12 ;
T_2 * V_4 = ( T_2 * ) V_8 -> V_4 . V_15 . V_16 ;
T_2 * V_3 = ( T_2 * ) V_8 -> V_3 . V_15 . V_16 ;
T_2 V_29 ;
T_3 V_31 [ 3 ] ;
F_20 ( & V_29 , ( T_3 * ) V_8 -> V_23 ) ;
if ( V_12 >= V_10 * 3 ) {
do {
if ( V_3 != V_4 ) {
V_3 [ 0 ] = V_4 [ 0 ] ;
V_3 [ 1 ] = V_4 [ 1 ] ;
V_3 [ 2 ] = V_4 [ 2 ] ;
}
F_18 ( & V_31 [ 0 ] , & V_29 ) ;
F_22 ( & V_29 ) ;
F_18 ( & V_31 [ 1 ] , & V_29 ) ;
F_22 ( & V_29 ) ;
F_18 ( & V_31 [ 2 ] , & V_29 ) ;
F_22 ( & V_29 ) ;
F_3 ( V_2 , ( T_1 * ) V_3 ,
( T_1 * ) V_31 ) ;
V_4 += 3 ;
V_3 += 3 ;
V_12 -= V_10 * 3 ;
} while ( V_12 >= V_10 * 3 );
if ( V_12 < V_10 )
goto V_18;
}
do {
if ( V_3 != V_4 )
* V_3 = * V_4 ;
F_18 ( & V_31 [ 0 ] , & V_29 ) ;
F_22 ( & V_29 ) ;
V_20 ( V_2 , ( T_1 * ) V_31 , ( T_1 * ) V_31 ) ;
F_14 ( V_3 , V_3 , ( T_2 * ) V_31 ) ;
V_4 += 1 ;
V_3 += 1 ;
V_12 -= V_10 ;
} while ( V_12 >= V_10 );
V_18:
F_18 ( ( T_3 * ) V_8 -> V_23 , & V_29 ) ;
return V_12 ;
}
static int F_27 ( struct V_5 * V_6 , struct V_19 * V_3 ,
struct V_19 * V_4 , unsigned int V_12 )
{
struct V_7 V_8 ;
int V_13 ;
F_11 ( & V_8 , V_3 , V_4 , V_12 ) ;
V_13 = F_28 ( V_6 , & V_8 , V_11 ) ;
while ( ( V_12 = V_8 . V_12 ) >= V_11 ) {
V_12 = F_26 ( V_6 , & V_8 ) ;
V_13 = F_9 ( V_6 , & V_8 , V_12 ) ;
}
if ( V_8 . V_12 ) {
F_23 ( V_6 , & V_8 ) ;
V_13 = F_9 ( V_6 , & V_8 , 0 ) ;
}
return V_13 ;
}
int T_4 F_29 ( void )
{
int V_13 ;
V_13 = F_30 ( & V_32 ) ;
if ( V_13 )
goto V_33;
V_13 = F_30 ( & V_34 ) ;
if ( V_13 )
goto V_35;
V_13 = F_30 ( & V_36 ) ;
if ( V_13 )
goto V_37;
return 0 ;
V_37:
F_31 ( & V_34 ) ;
V_35:
F_31 ( & V_32 ) ;
V_33:
return V_13 ;
}
void T_5 F_32 ( void )
{
F_31 ( & V_36 ) ;
F_31 ( & V_34 ) ;
F_31 ( & V_32 ) ;
}
