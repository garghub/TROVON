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
static inline void F_4 ( struct V_1 * V_2 , T_1 * V_3 ,
const T_1 * V_4 )
{
F_5 ( V_2 , V_3 , V_4 ) ;
}
static inline bool F_6 ( bool V_5 , unsigned int V_6 )
{
return F_7 ( V_7 , V_8 ,
NULL , V_5 , V_6 ) ;
}
static inline void F_8 ( bool V_5 )
{
return F_9 ( V_5 ) ;
}
static int F_10 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_13 )
{
bool V_5 = false ;
struct V_1 * V_2 = F_11 ( V_10 -> V_14 ) ;
const unsigned int V_15 = V_7 ;
unsigned int V_6 ;
int V_16 ;
V_16 = F_12 ( V_10 , V_12 ) ;
V_10 -> V_17 &= ~ V_18 ;
while ( ( V_6 = V_12 -> V_6 ) ) {
T_1 * V_19 = V_12 -> V_4 . V_20 . V_21 ;
T_1 * V_22 = V_12 -> V_3 . V_20 . V_21 ;
V_5 = F_6 ( V_5 , V_6 ) ;
if ( V_6 >= V_15 * V_8 ) {
do {
if ( V_13 )
F_1 ( V_2 , V_22 , V_19 ) ;
else
F_4 ( V_2 , V_22 , V_19 ) ;
V_19 += V_15 * V_8 ;
V_22 += V_15 * V_8 ;
V_6 -= V_15 * V_8 ;
} while ( V_6 >= V_15 * V_8 );
if ( V_6 < V_15 )
goto V_23;
}
do {
if ( V_13 )
F_13 ( V_2 , V_22 , V_19 ) ;
else
F_14 ( V_2 , V_22 , V_19 ) ;
V_19 += V_15 ;
V_22 += V_15 ;
V_6 -= V_15 ;
} while ( V_6 >= V_15 );
V_23:
V_16 = F_15 ( V_10 , V_12 , V_6 ) ;
}
F_8 ( V_5 ) ;
return V_16 ;
}
static int F_16 ( struct V_9 * V_10 , struct V_24 * V_3 ,
struct V_24 * V_4 , unsigned int V_6 )
{
struct V_11 V_12 ;
F_17 ( & V_12 , V_3 , V_4 , V_6 ) ;
return F_10 ( V_10 , & V_12 , true ) ;
}
static int F_18 ( struct V_9 * V_10 , struct V_24 * V_3 ,
struct V_24 * V_4 , unsigned int V_6 )
{
struct V_11 V_12 ;
F_17 ( & V_12 , V_3 , V_4 , V_6 ) ;
return F_10 ( V_10 , & V_12 , false ) ;
}
static unsigned int F_19 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_10 -> V_14 ) ;
const unsigned int V_15 = V_7 ;
unsigned int V_6 = V_12 -> V_6 ;
T_2 * V_4 = ( T_2 * ) V_12 -> V_4 . V_20 . V_21 ;
T_2 * V_3 = ( T_2 * ) V_12 -> V_3 . V_20 . V_21 ;
T_2 * V_25 = ( T_2 * ) V_12 -> V_25 ;
do {
* V_3 = * V_4 ^ * V_25 ;
F_13 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_3 ) ;
V_25 = V_3 ;
V_4 += 1 ;
V_3 += 1 ;
V_6 -= V_15 ;
} while ( V_6 >= V_15 );
* ( T_2 * ) V_12 -> V_25 = * V_25 ;
return V_6 ;
}
static int F_20 ( struct V_9 * V_10 , struct V_24 * V_3 ,
struct V_24 * V_4 , unsigned int V_6 )
{
struct V_11 V_12 ;
int V_16 ;
F_17 ( & V_12 , V_3 , V_4 , V_6 ) ;
V_16 = F_12 ( V_10 , & V_12 ) ;
while ( ( V_6 = V_12 . V_6 ) ) {
V_6 = F_19 ( V_10 , & V_12 ) ;
V_16 = F_15 ( V_10 , & V_12 , V_6 ) ;
}
return V_16 ;
}
static unsigned int F_21 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_10 -> V_14 ) ;
const unsigned int V_15 = V_7 ;
unsigned int V_6 = V_12 -> V_6 ;
T_2 * V_4 = ( T_2 * ) V_12 -> V_4 . V_20 . V_21 ;
T_2 * V_3 = ( T_2 * ) V_12 -> V_3 . V_20 . V_21 ;
T_2 V_26 [ V_8 - 1 ] ;
T_2 V_27 ;
int V_28 ;
V_4 += V_6 / V_15 - 1 ;
V_3 += V_6 / V_15 - 1 ;
V_27 = * V_4 ;
if ( V_6 >= V_15 * V_8 ) {
do {
V_6 -= V_15 * ( V_8 - 1 ) ;
V_4 -= V_8 - 1 ;
V_3 -= V_8 - 1 ;
for ( V_28 = 0 ; V_28 < V_8 - 1 ; V_28 ++ )
V_26 [ V_28 ] = V_4 [ V_28 ] ;
F_4 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
for ( V_28 = 0 ; V_28 < V_8 - 1 ; V_28 ++ )
* ( V_3 + ( V_28 + 1 ) ) ^= * ( V_26 + V_28 ) ;
V_6 -= V_15 ;
if ( V_6 < V_15 )
goto V_23;
* V_3 ^= * ( V_4 - 1 ) ;
V_4 -= 1 ;
V_3 -= 1 ;
} while ( V_6 >= V_15 * V_8 );
if ( V_6 < V_15 )
goto V_23;
}
for (; ; ) {
F_14 ( V_2 , ( T_1 * ) V_3 , ( T_1 * ) V_4 ) ;
V_6 -= V_15 ;
if ( V_6 < V_15 )
break;
* V_3 ^= * ( V_4 - 1 ) ;
V_4 -= 1 ;
V_3 -= 1 ;
}
V_23:
* V_3 ^= * ( T_2 * ) V_12 -> V_25 ;
* ( T_2 * ) V_12 -> V_25 = V_27 ;
return V_6 ;
}
static int F_22 ( struct V_9 * V_10 , struct V_24 * V_3 ,
struct V_24 * V_4 , unsigned int V_6 )
{
bool V_5 = false ;
struct V_11 V_12 ;
int V_16 ;
F_17 ( & V_12 , V_3 , V_4 , V_6 ) ;
V_16 = F_12 ( V_10 , & V_12 ) ;
V_10 -> V_17 &= ~ V_18 ;
while ( ( V_6 = V_12 . V_6 ) ) {
V_5 = F_6 ( V_5 , V_6 ) ;
V_6 = F_21 ( V_10 , & V_12 ) ;
V_16 = F_15 ( V_10 , & V_12 , V_6 ) ;
}
F_8 ( V_5 ) ;
return V_16 ;
}
static void F_23 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_10 -> V_14 ) ;
T_1 * V_29 = V_12 -> V_25 ;
T_1 V_30 [ V_7 ] ;
T_1 * V_4 = V_12 -> V_4 . V_20 . V_21 ;
T_1 * V_3 = V_12 -> V_3 . V_20 . V_21 ;
unsigned int V_6 = V_12 -> V_6 ;
F_13 ( V_2 , V_30 , V_29 ) ;
F_24 ( V_30 , V_4 , V_6 ) ;
memcpy ( V_3 , V_30 , V_6 ) ;
F_25 ( V_29 , V_7 ) ;
}
static unsigned int F_26 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_10 -> V_14 ) ;
const unsigned int V_15 = V_7 ;
unsigned int V_6 = V_12 -> V_6 ;
T_2 * V_4 = ( T_2 * ) V_12 -> V_4 . V_20 . V_21 ;
T_2 * V_3 = ( T_2 * ) V_12 -> V_3 . V_20 . V_21 ;
T_2 V_29 = F_27 ( * ( V_31 * ) V_12 -> V_25 ) ;
V_31 V_32 [ V_8 ] ;
int V_28 ;
if ( V_6 >= V_15 * V_8 ) {
do {
for ( V_28 = 0 ; V_28 < V_8 ; V_28 ++ ) {
if ( V_3 != V_4 )
V_3 [ V_28 ] = V_4 [ V_28 ] ;
V_32 [ V_28 ] = F_28 ( V_29 ++ ) ;
}
F_3 ( V_2 , ( T_1 * ) V_3 ,
( T_1 * ) V_32 ) ;
V_4 += V_8 ;
V_3 += V_8 ;
V_6 -= V_15 * V_8 ;
} while ( V_6 >= V_15 * V_8 );
if ( V_6 < V_15 )
goto V_23;
}
do {
if ( V_3 != V_4 )
* V_3 = * V_4 ;
V_32 [ 0 ] = F_28 ( V_29 ++ ) ;
F_13 ( V_2 , ( T_1 * ) V_32 , ( T_1 * ) V_32 ) ;
* V_3 ^= V_32 [ 0 ] ;
V_4 += 1 ;
V_3 += 1 ;
V_6 -= V_15 ;
} while ( V_6 >= V_15 );
V_23:
* ( V_31 * ) V_12 -> V_25 = F_28 ( V_29 ) ;
return V_6 ;
}
static int F_29 ( struct V_9 * V_10 , struct V_24 * V_3 ,
struct V_24 * V_4 , unsigned int V_6 )
{
bool V_5 = false ;
struct V_11 V_12 ;
int V_16 ;
F_17 ( & V_12 , V_3 , V_4 , V_6 ) ;
V_16 = F_30 ( V_10 , & V_12 , V_7 ) ;
V_10 -> V_17 &= ~ V_18 ;
while ( ( V_6 = V_12 . V_6 ) >= V_7 ) {
V_5 = F_6 ( V_5 , V_6 ) ;
V_6 = F_26 ( V_10 , & V_12 ) ;
V_16 = F_15 ( V_10 , & V_12 , V_6 ) ;
}
F_8 ( V_5 ) ;
if ( V_12 . V_6 ) {
F_23 ( V_10 , & V_12 ) ;
V_16 = F_15 ( V_10 , & V_12 , 0 ) ;
}
return V_16 ;
}
static int T_3 F_31 ( void )
{
T_2 V_33 ;
if ( ! V_34 || ! V_35 ) {
F_32 ( L_1 ) ;
return - V_36 ;
}
V_33 = F_33 ( V_37 ) ;
if ( ( V_33 & ( V_38 | V_39 ) ) != ( V_38 | V_39 ) ) {
F_32 ( L_2 ) ;
return - V_36 ;
}
return F_34 ( V_40 , F_35 ( V_40 ) ) ;
}
static void T_4 F_36 ( void )
{
F_37 ( V_40 , F_35 ( V_40 ) ) ;
}
