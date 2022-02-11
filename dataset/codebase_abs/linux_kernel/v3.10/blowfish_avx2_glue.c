static inline bool F_1 ( bool V_1 , unsigned int V_2 )
{
if ( V_1 )
return true ;
if ( V_2 < V_3 * V_4 )
return false ;
F_2 () ;
return true ;
}
static inline void F_3 ( bool V_1 )
{
if ( V_1 )
F_4 () ;
}
static int F_5 ( struct V_5 * V_6 , struct V_7 * V_8 ,
bool V_9 )
{
bool V_1 = false ;
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
const unsigned int V_13 = V_3 ;
unsigned int V_2 ;
int V_14 ;
V_14 = F_7 ( V_6 , V_8 ) ;
V_6 -> V_15 &= ~ V_16 ;
while ( ( V_2 = V_8 -> V_2 ) ) {
T_1 * V_17 = V_8 -> V_18 . V_19 . V_20 ;
T_1 * V_21 = V_8 -> V_22 . V_19 . V_20 ;
V_1 = F_1 ( V_1 , V_2 ) ;
if ( V_2 >= V_13 * V_4 ) {
do {
if ( V_9 )
F_8 ( V_11 , V_21 , V_17 ) ;
else
F_9 ( V_11 , V_21 , V_17 ) ;
V_17 += V_13 * V_4 ;
V_21 += V_13 * V_4 ;
V_2 -= V_13 * V_4 ;
} while ( V_2 >= V_13 * V_4 );
if ( V_2 < V_13 )
goto V_23;
}
if ( V_2 >= V_13 * V_24 ) {
do {
if ( V_9 )
F_10 ( V_11 , V_21 , V_17 ) ;
else
F_11 ( V_11 , V_21 , V_17 ) ;
V_17 += V_13 * V_24 ;
V_21 += V_13 * V_24 ;
V_2 -= V_13 * V_24 ;
} while ( V_2 >= V_13 * V_24 );
if ( V_2 < V_13 )
goto V_23;
}
do {
if ( V_9 )
F_12 ( V_11 , V_21 , V_17 ) ;
else
F_13 ( V_11 , V_21 , V_17 ) ;
V_17 += V_13 ;
V_21 += V_13 ;
V_2 -= V_13 ;
} while ( V_2 >= V_13 );
V_23:
V_14 = F_14 ( V_6 , V_8 , V_2 ) ;
}
F_3 ( V_1 ) ;
return V_14 ;
}
static int F_15 ( struct V_5 * V_6 , struct V_25 * V_22 ,
struct V_25 * V_18 , unsigned int V_2 )
{
struct V_7 V_8 ;
F_16 ( & V_8 , V_22 , V_18 , V_2 ) ;
return F_5 ( V_6 , & V_8 , true ) ;
}
static int F_17 ( struct V_5 * V_6 , struct V_25 * V_22 ,
struct V_25 * V_18 , unsigned int V_2 )
{
struct V_7 V_8 ;
F_16 ( & V_8 , V_22 , V_18 , V_2 ) ;
return F_5 ( V_6 , & V_8 , false ) ;
}
static unsigned int F_18 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
unsigned int V_13 = V_3 ;
unsigned int V_2 = V_8 -> V_2 ;
T_2 * V_18 = ( T_2 * ) V_8 -> V_18 . V_19 . V_20 ;
T_2 * V_22 = ( T_2 * ) V_8 -> V_22 . V_19 . V_20 ;
T_2 * V_26 = ( T_2 * ) V_8 -> V_26 ;
do {
* V_22 = * V_18 ^ * V_26 ;
F_12 ( V_11 , ( T_1 * ) V_22 , ( T_1 * ) V_22 ) ;
V_26 = V_22 ;
V_18 += 1 ;
V_22 += 1 ;
V_2 -= V_13 ;
} while ( V_2 >= V_13 );
* ( T_2 * ) V_8 -> V_26 = * V_26 ;
return V_2 ;
}
static int F_19 ( struct V_5 * V_6 , struct V_25 * V_22 ,
struct V_25 * V_18 , unsigned int V_2 )
{
struct V_7 V_8 ;
int V_14 ;
F_16 ( & V_8 , V_22 , V_18 , V_2 ) ;
V_14 = F_7 ( V_6 , & V_8 ) ;
while ( ( V_2 = V_8 . V_2 ) ) {
V_2 = F_18 ( V_6 , & V_8 ) ;
V_14 = F_14 ( V_6 , & V_8 , V_2 ) ;
}
return V_14 ;
}
static unsigned int F_20 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
const unsigned int V_13 = V_3 ;
unsigned int V_2 = V_8 -> V_2 ;
T_2 * V_18 = ( T_2 * ) V_8 -> V_18 . V_19 . V_20 ;
T_2 * V_22 = ( T_2 * ) V_8 -> V_22 . V_19 . V_20 ;
T_2 V_27 ;
int V_28 ;
V_18 += V_2 / V_13 - 1 ;
V_22 += V_2 / V_13 - 1 ;
V_27 = * V_18 ;
if ( V_2 >= V_13 * V_4 ) {
do {
V_2 -= V_13 * ( V_4 - 1 ) ;
V_18 -= V_4 - 1 ;
V_22 -= V_4 - 1 ;
F_21 ( V_11 , ( T_1 * ) V_22 , ( T_1 * ) V_18 ) ;
V_2 -= V_13 ;
if ( V_2 < V_13 )
goto V_23;
* V_22 ^= * ( V_18 - 1 ) ;
V_18 -= 1 ;
V_22 -= 1 ;
} while ( V_2 >= V_13 * V_4 );
if ( V_2 < V_13 )
goto V_23;
}
if ( V_2 >= V_13 * V_24 ) {
T_2 V_29 [ V_24 - 1 ] ;
do {
V_2 -= V_13 * ( V_24 - 1 ) ;
V_18 -= V_24 - 1 ;
V_22 -= V_24 - 1 ;
for ( V_28 = 0 ; V_28 < V_24 - 1 ; V_28 ++ )
V_29 [ V_28 ] = V_18 [ V_28 ] ;
F_11 ( V_11 , ( T_1 * ) V_22 , ( T_1 * ) V_18 ) ;
for ( V_28 = 0 ; V_28 < V_24 - 1 ; V_28 ++ )
V_22 [ V_28 + 1 ] ^= V_29 [ V_28 ] ;
V_2 -= V_13 ;
if ( V_2 < V_13 )
goto V_23;
* V_22 ^= * ( V_18 - 1 ) ;
V_18 -= 1 ;
V_22 -= 1 ;
} while ( V_2 >= V_13 * V_24 );
if ( V_2 < V_13 )
goto V_23;
}
for (; ; ) {
F_13 ( V_11 , ( T_1 * ) V_22 , ( T_1 * ) V_18 ) ;
V_2 -= V_13 ;
if ( V_2 < V_13 )
break;
* V_22 ^= * ( V_18 - 1 ) ;
V_18 -= 1 ;
V_22 -= 1 ;
}
V_23:
* V_22 ^= * ( T_2 * ) V_8 -> V_26 ;
* ( T_2 * ) V_8 -> V_26 = V_27 ;
return V_2 ;
}
static int F_22 ( struct V_5 * V_6 , struct V_25 * V_22 ,
struct V_25 * V_18 , unsigned int V_2 )
{
bool V_1 = false ;
struct V_7 V_8 ;
int V_14 ;
F_16 ( & V_8 , V_22 , V_18 , V_2 ) ;
V_14 = F_7 ( V_6 , & V_8 ) ;
V_6 -> V_15 &= ~ V_16 ;
while ( ( V_2 = V_8 . V_2 ) ) {
V_1 = F_1 ( V_1 , V_2 ) ;
V_2 = F_20 ( V_6 , & V_8 ) ;
V_14 = F_14 ( V_6 , & V_8 , V_2 ) ;
}
F_3 ( V_1 ) ;
return V_14 ;
}
static void F_23 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
T_1 * V_30 = V_8 -> V_26 ;
T_1 V_31 [ V_3 ] ;
T_1 * V_18 = V_8 -> V_18 . V_19 . V_20 ;
T_1 * V_22 = V_8 -> V_22 . V_19 . V_20 ;
unsigned int V_2 = V_8 -> V_2 ;
F_12 ( V_11 , V_31 , V_30 ) ;
F_24 ( V_31 , V_18 , V_2 ) ;
memcpy ( V_22 , V_31 , V_2 ) ;
F_25 ( V_30 , V_3 ) ;
}
static unsigned int F_26 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
unsigned int V_13 = V_3 ;
unsigned int V_2 = V_8 -> V_2 ;
T_2 * V_18 = ( T_2 * ) V_8 -> V_18 . V_19 . V_20 ;
T_2 * V_22 = ( T_2 * ) V_8 -> V_22 . V_19 . V_20 ;
int V_28 ;
if ( V_2 >= V_13 * V_4 ) {
do {
F_27 ( V_11 , ( T_1 * ) V_22 , ( T_1 * ) V_18 ,
( V_32 * ) V_8 -> V_26 ) ;
V_18 += V_4 ;
V_22 += V_4 ;
V_2 -= V_13 * V_4 ;
} while ( V_2 >= V_13 * V_4 );
if ( V_2 < V_13 )
goto V_23;
}
if ( V_2 >= V_13 * V_24 ) {
V_32 V_33 [ V_24 ] ;
T_2 V_30 = F_28 ( * ( V_32 * ) V_8 -> V_26 ) ;
do {
for ( V_28 = 0 ; V_28 < V_24 ; V_28 ++ ) {
if ( V_22 != V_18 )
V_22 [ V_28 ] = V_18 [ V_28 ] ;
V_33 [ V_28 ] = F_29 ( V_30 ++ ) ;
}
F_30 ( V_11 , ( T_1 * ) V_22 ,
( T_1 * ) V_33 ) ;
V_18 += V_24 ;
V_22 += V_24 ;
V_2 -= V_13 * V_24 ;
} while ( V_2 >= V_13 * V_24 );
* ( V_32 * ) V_8 -> V_26 = F_29 ( V_30 ) ;
if ( V_2 < V_13 )
goto V_23;
}
do {
T_2 V_30 ;
if ( V_22 != V_18 )
* V_22 = * V_18 ;
V_30 = * ( T_2 * ) V_8 -> V_26 ;
F_31 ( ( V_32 * ) V_8 -> V_26 , 1 ) ;
F_32 ( V_11 , ( T_1 * ) V_22 , ( T_1 * ) & V_30 ) ;
V_18 += 1 ;
V_22 += 1 ;
} while ( ( V_2 -= V_13 ) >= V_13 );
V_23:
return V_2 ;
}
static int F_33 ( struct V_5 * V_6 , struct V_25 * V_22 ,
struct V_25 * V_18 , unsigned int V_2 )
{
bool V_1 = false ;
struct V_7 V_8 ;
int V_14 ;
F_16 ( & V_8 , V_22 , V_18 , V_2 ) ;
V_14 = F_34 ( V_6 , & V_8 , V_3 ) ;
V_6 -> V_15 &= ~ V_16 ;
while ( ( V_2 = V_8 . V_2 ) >= V_3 ) {
V_1 = F_1 ( V_1 , V_2 ) ;
V_2 = F_26 ( V_6 , & V_8 ) ;
V_14 = F_14 ( V_6 , & V_8 , V_2 ) ;
}
F_3 ( V_1 ) ;
if ( V_8 . V_2 ) {
F_23 ( V_6 , & V_8 ) ;
V_14 = F_14 ( V_6 , & V_8 , 0 ) ;
}
return V_14 ;
}
static int T_3 F_35 ( void )
{
T_2 V_34 ;
if ( ! V_35 || ! V_36 ) {
F_36 ( L_1 ) ;
return - V_37 ;
}
V_34 = F_37 ( V_38 ) ;
if ( ( V_34 & ( V_39 | V_40 ) ) != ( V_39 | V_40 ) ) {
F_36 ( L_2 ) ;
return - V_37 ;
}
return F_38 ( V_41 , F_39 ( V_41 ) ) ;
}
static void T_4 F_40 ( void )
{
F_41 ( V_41 , F_39 ( V_41 ) ) ;
}
