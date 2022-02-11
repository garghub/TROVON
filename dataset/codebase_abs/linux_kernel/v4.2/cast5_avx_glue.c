static inline bool F_1 ( bool V_1 , unsigned int V_2 )
{
return F_2 ( V_3 , V_4 ,
NULL , V_1 , V_2 ) ;
}
static inline void F_3 ( bool V_1 )
{
return F_4 ( V_1 ) ;
}
static int F_5 ( struct V_5 * V_6 , struct V_7 * V_8 ,
bool V_9 )
{
bool V_1 = false ;
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
const unsigned int V_13 = V_3 ;
unsigned int V_2 ;
void (* F_7)( struct V_10 * V_11 , T_1 * V_14 , const T_1 * V_15 );
int V_16 ;
F_7 = ( V_9 ) ? V_17 : V_18 ;
V_16 = F_8 ( V_6 , V_8 ) ;
V_6 -> V_19 &= ~ V_20 ;
while ( ( V_2 = V_8 -> V_2 ) ) {
T_1 * V_21 = V_8 -> V_15 . V_22 . V_23 ;
T_1 * V_24 = V_8 -> V_14 . V_22 . V_23 ;
V_1 = F_1 ( V_1 , V_2 ) ;
if ( V_2 >= V_13 * V_4 ) {
do {
F_7 ( V_11 , V_24 , V_21 ) ;
V_21 += V_13 * V_4 ;
V_24 += V_13 * V_4 ;
V_2 -= V_13 * V_4 ;
} while ( V_2 >= V_13 * V_4 );
if ( V_2 < V_13 )
goto V_25;
}
F_7 = ( V_9 ) ? V_26 : V_27 ;
do {
F_7 ( V_11 , V_24 , V_21 ) ;
V_21 += V_13 ;
V_24 += V_13 ;
V_2 -= V_13 ;
} while ( V_2 >= V_13 );
V_25:
V_16 = F_9 ( V_6 , V_8 , V_2 ) ;
}
F_3 ( V_1 ) ;
return V_16 ;
}
static int F_10 ( struct V_5 * V_6 , struct V_28 * V_14 ,
struct V_28 * V_15 , unsigned int V_2 )
{
struct V_7 V_8 ;
F_11 ( & V_8 , V_14 , V_15 , V_2 ) ;
return F_5 ( V_6 , & V_8 , true ) ;
}
static int F_12 ( struct V_5 * V_6 , struct V_28 * V_14 ,
struct V_28 * V_15 , unsigned int V_2 )
{
struct V_7 V_8 ;
F_11 ( & V_8 , V_14 , V_15 , V_2 ) ;
return F_5 ( V_6 , & V_8 , false ) ;
}
static unsigned int F_13 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
const unsigned int V_13 = V_3 ;
unsigned int V_2 = V_8 -> V_2 ;
T_2 * V_15 = ( T_2 * ) V_8 -> V_15 . V_22 . V_23 ;
T_2 * V_14 = ( T_2 * ) V_8 -> V_14 . V_22 . V_23 ;
T_2 * V_29 = ( T_2 * ) V_8 -> V_29 ;
do {
* V_14 = * V_15 ^ * V_29 ;
V_26 ( V_11 , ( T_1 * ) V_14 , ( T_1 * ) V_14 ) ;
V_29 = V_14 ;
V_15 += 1 ;
V_14 += 1 ;
V_2 -= V_13 ;
} while ( V_2 >= V_13 );
* ( T_2 * ) V_8 -> V_29 = * V_29 ;
return V_2 ;
}
static int F_14 ( struct V_5 * V_6 , struct V_28 * V_14 ,
struct V_28 * V_15 , unsigned int V_2 )
{
struct V_7 V_8 ;
int V_16 ;
F_11 ( & V_8 , V_14 , V_15 , V_2 ) ;
V_16 = F_8 ( V_6 , & V_8 ) ;
while ( ( V_2 = V_8 . V_2 ) ) {
V_2 = F_13 ( V_6 , & V_8 ) ;
V_16 = F_9 ( V_6 , & V_8 , V_2 ) ;
}
return V_16 ;
}
static unsigned int F_15 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
const unsigned int V_13 = V_3 ;
unsigned int V_2 = V_8 -> V_2 ;
T_2 * V_15 = ( T_2 * ) V_8 -> V_15 . V_22 . V_23 ;
T_2 * V_14 = ( T_2 * ) V_8 -> V_14 . V_22 . V_23 ;
T_2 V_30 ;
V_15 += V_2 / V_13 - 1 ;
V_14 += V_2 / V_13 - 1 ;
V_30 = * V_15 ;
if ( V_2 >= V_13 * V_4 ) {
do {
V_2 -= V_13 * ( V_4 - 1 ) ;
V_15 -= V_4 - 1 ;
V_14 -= V_4 - 1 ;
F_16 ( V_11 , ( T_1 * ) V_14 , ( T_1 * ) V_15 ) ;
V_2 -= V_13 ;
if ( V_2 < V_13 )
goto V_25;
* V_14 ^= * ( V_15 - 1 ) ;
V_15 -= 1 ;
V_14 -= 1 ;
} while ( V_2 >= V_13 * V_4 );
}
for (; ; ) {
V_27 ( V_11 , ( T_1 * ) V_14 , ( T_1 * ) V_15 ) ;
V_2 -= V_13 ;
if ( V_2 < V_13 )
break;
* V_14 ^= * ( V_15 - 1 ) ;
V_15 -= 1 ;
V_14 -= 1 ;
}
V_25:
* V_14 ^= * ( T_2 * ) V_8 -> V_29 ;
* ( T_2 * ) V_8 -> V_29 = V_30 ;
return V_2 ;
}
static int F_17 ( struct V_5 * V_6 , struct V_28 * V_14 ,
struct V_28 * V_15 , unsigned int V_2 )
{
bool V_1 = false ;
struct V_7 V_8 ;
int V_16 ;
F_11 ( & V_8 , V_14 , V_15 , V_2 ) ;
V_16 = F_8 ( V_6 , & V_8 ) ;
V_6 -> V_19 &= ~ V_20 ;
while ( ( V_2 = V_8 . V_2 ) ) {
V_1 = F_1 ( V_1 , V_2 ) ;
V_2 = F_15 ( V_6 , & V_8 ) ;
V_16 = F_9 ( V_6 , & V_8 , V_2 ) ;
}
F_3 ( V_1 ) ;
return V_16 ;
}
static void F_18 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
T_1 * V_31 = V_8 -> V_29 ;
T_1 V_32 [ V_3 ] ;
T_1 * V_15 = V_8 -> V_15 . V_22 . V_23 ;
T_1 * V_14 = V_8 -> V_14 . V_22 . V_23 ;
unsigned int V_2 = V_8 -> V_2 ;
V_26 ( V_11 , V_32 , V_31 ) ;
F_19 ( V_32 , V_15 , V_2 ) ;
memcpy ( V_14 , V_32 , V_2 ) ;
F_20 ( V_31 , V_3 ) ;
}
static unsigned int F_21 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
const unsigned int V_13 = V_3 ;
unsigned int V_2 = V_8 -> V_2 ;
T_2 * V_15 = ( T_2 * ) V_8 -> V_15 . V_22 . V_23 ;
T_2 * V_14 = ( T_2 * ) V_8 -> V_14 . V_22 . V_23 ;
if ( V_2 >= V_13 * V_4 ) {
do {
F_22 ( V_11 , ( T_1 * ) V_14 , ( T_1 * ) V_15 ,
( V_33 * ) V_8 -> V_29 ) ;
V_15 += V_4 ;
V_14 += V_4 ;
V_2 -= V_13 * V_4 ;
} while ( V_2 >= V_13 * V_4 );
if ( V_2 < V_13 )
goto V_25;
}
do {
T_2 V_31 ;
if ( V_14 != V_15 )
* V_14 = * V_15 ;
V_31 = * ( T_2 * ) V_8 -> V_29 ;
F_23 ( ( V_33 * ) V_8 -> V_29 , 1 ) ;
V_26 ( V_11 , ( T_1 * ) & V_31 , ( T_1 * ) & V_31 ) ;
* V_14 ^= V_31 ;
V_15 += 1 ;
V_14 += 1 ;
V_2 -= V_13 ;
} while ( V_2 >= V_13 );
V_25:
return V_2 ;
}
static int F_24 ( struct V_5 * V_6 , struct V_28 * V_14 ,
struct V_28 * V_15 , unsigned int V_2 )
{
bool V_1 = false ;
struct V_7 V_8 ;
int V_16 ;
F_11 ( & V_8 , V_14 , V_15 , V_2 ) ;
V_16 = F_25 ( V_6 , & V_8 , V_3 ) ;
V_6 -> V_19 &= ~ V_20 ;
while ( ( V_2 = V_8 . V_2 ) >= V_3 ) {
V_1 = F_1 ( V_1 , V_2 ) ;
V_2 = F_21 ( V_6 , & V_8 ) ;
V_16 = F_9 ( V_6 , & V_8 , V_2 ) ;
}
F_3 ( V_1 ) ;
if ( V_8 . V_2 ) {
F_18 ( V_6 , & V_8 ) ;
V_16 = F_9 ( V_6 , & V_8 , 0 ) ;
}
return V_16 ;
}
static int T_3 F_26 ( void )
{
const char * V_34 ;
if ( ! F_27 ( V_35 | V_36 , & V_34 ) ) {
F_28 ( L_1 , V_34 ) ;
return - V_37 ;
}
return F_29 ( V_38 , F_30 ( V_38 ) ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( V_38 , F_30 ( V_38 ) ) ;
}
