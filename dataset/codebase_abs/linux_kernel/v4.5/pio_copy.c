void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 ,
const void * V_6 , T_2 V_7 )
{
void T_3 * V_8 = V_4 -> V_9 + V_10 ;
void T_3 * V_11 = V_8 + V_12 ;
void T_3 * V_13 ;
F_2 ( V_5 , V_8 ) ;
V_8 += sizeof( T_1 ) ;
V_13 = V_8 + ( ( V_7 >> 1 ) * sizeof( T_1 ) ) ;
if ( V_13 < V_11 ) {
while ( V_8 < V_13 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
} else {
while ( V_8 < V_11 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
V_8 -= V_10 ;
V_13 -= V_10 ;
if ( V_4 -> V_14 <= V_13 ) {
while ( V_8 < V_4 -> V_14 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
V_8 -= V_4 -> V_15 ;
V_13 -= V_4 -> V_15 ;
}
while ( V_8 < V_13 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
}
if ( V_7 & 1 ) {
union V_16 V_17 ;
V_17 . V_18 = 0 ;
V_17 . V_19 [ 0 ] = * ( V_20 * ) V_6 ;
F_2 ( V_17 . V_18 , V_8 ) ;
V_8 += sizeof( T_1 ) ;
}
while ( ( ( unsigned long ) V_8 & V_21 ) != 0 ) {
F_2 ( 0 , V_8 ) ;
V_8 += sizeof( T_1 ) ;
}
F_3 ( * V_4 -> V_22 -> V_23 ) ;
F_4 () ;
}
static inline void F_5 ( struct V_3 * V_4 , const void * V_6 ,
unsigned int V_24 )
{
unsigned long V_25 ;
if ( V_24 == 0 ) {
V_4 -> V_26 . V_18 = 0 ;
} else {
V_25 = ( unsigned long ) V_6 & 0x7 ;
V_6 = ( void * ) ( ( unsigned long ) V_6 & ~ 0x7l ) ;
V_4 -> V_26 . V_18 = ( ( * ( T_1 * ) V_6 )
<< F_6 ( V_24 + V_25 ) )
>> F_6 ( V_24 ) ;
}
V_4 -> V_27 = V_24 ;
}
static inline void F_7 ( struct V_3 * V_4 ,
const void * V_6 , unsigned int V_24 )
{
unsigned long V_25 = ( unsigned long ) V_6 & 0x7 ;
unsigned int V_28 , V_29 ;
V_6 = ( void * ) ( ( unsigned long ) V_6 & ~ 0x7l ) ;
while ( V_24 ) {
V_28 = 8 - V_25 ;
V_29 = V_24 > V_28 ? V_28 : V_24 ;
V_4 -> V_26 . V_18 |= ( ( ( * ( T_1 * ) V_6 )
>> F_8 ( V_25 ) )
<< F_6 ( V_29 ) )
>> F_6 ( V_29 + V_4 -> V_27 ) ;
V_25 = 0 ;
V_4 -> V_27 += V_29 ;
V_24 -= V_29 ;
V_6 += sizeof( T_1 ) ;
}
}
static inline void F_9 ( struct V_3 * V_4 , unsigned int V_30 )
{
unsigned int V_31 ;
if ( V_30 == 0 )
return;
V_31 = V_4 -> V_27 - V_30 ;
if ( V_31 )
V_4 -> V_26 . V_18 = ( V_4 -> V_26 . V_18 << F_6 ( V_31 ) )
>> F_6 ( V_31 ) ;
else
V_4 -> V_26 . V_18 = 0 ;
V_4 -> V_27 = V_31 ;
}
static inline void F_10 (
struct V_3 * V_4 ,
void T_3 * V_8 ,
const void * V_32 )
{
T_1 V_33 , V_34 ;
V_33 = * ( T_1 * ) V_32 ;
V_34 = V_4 -> V_26 . V_18 | ( V_33 << F_8 ( V_4 -> V_27 ) ) ;
F_2 ( V_34 , V_8 ) ;
V_4 -> V_26 . V_18 = V_33 >> F_6 ( V_4 -> V_27 ) ;
}
static inline void F_11 ( union V_16 V_26 , void T_3 * V_8 )
{
F_2 ( V_26 . V_18 , V_8 ) ;
}
static inline int F_12 ( struct V_3 * V_4 , void T_3 * V_8 )
{
if ( V_4 -> V_27 ) {
F_2 ( V_4 -> V_26 . V_18 , V_8 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_13 ( T_4 * V_8 , const T_4 * V_32 , V_20 V_35 )
{
switch ( V_35 ) {
case 7 :
* V_8 ++ = * V_32 ++ ;
case 6 :
* V_8 ++ = * V_32 ++ ;
case 5 :
* V_8 ++ = * V_32 ++ ;
case 4 :
* V_8 ++ = * V_32 ++ ;
case 3 :
* V_8 ++ = * V_32 ++ ;
case 2 :
* V_8 ++ = * V_32 ++ ;
case 1 :
* V_8 ++ = * V_32 ++ ;
}
}
static inline void F_5 ( struct V_3 * V_4 , const void * V_6 ,
unsigned int V_24 )
{
F_13 ( & V_4 -> V_26 . V_36 [ 0 ] , V_6 , V_24 ) ;
V_4 -> V_27 = V_24 ;
}
static inline void F_7 ( struct V_3 * V_4 ,
const void * V_6 , unsigned int V_24 )
{
F_13 ( & V_4 -> V_26 . V_36 [ V_4 -> V_27 ] , V_6 , V_24 ) ;
V_4 -> V_27 += V_24 ;
}
static inline void F_9 ( struct V_3 * V_4 , unsigned int V_30 )
{
V_4 -> V_27 -= V_30 ;
}
static inline void F_10 (
struct V_3 * V_4 ,
void * V_8 ,
const void * V_32 )
{
V_20 V_37 = 8 - V_4 -> V_27 ;
F_13 ( & V_4 -> V_26 . V_36 [ V_4 -> V_27 ] , V_32 , V_37 ) ;
F_2 ( V_4 -> V_26 . V_18 , V_8 ) ;
F_13 ( & V_4 -> V_26 . V_36 [ 0 ] , V_32 + V_37 , V_4 -> V_27 ) ;
}
static inline void F_11 ( union V_16 V_26 , void * V_8 )
{
F_2 ( V_26 . V_18 , V_8 ) ;
}
static inline int F_12 ( struct V_3 * V_4 , void * V_8 )
{
if ( V_4 -> V_27 ) {
T_1 V_38 = 0 ;
F_13 ( & V_4 -> V_26 . V_36 [ V_4 -> V_27 ] , ( T_4 * ) & V_38 ,
8 - V_4 -> V_27 ) ;
F_2 ( V_4 -> V_26 . V_18 , V_8 ) ;
return 1 ;
}
return 0 ;
}
void F_14 ( struct V_3 * V_4 , T_1 V_5 ,
const void * V_6 , T_2 V_24 )
{
void T_3 * V_8 = V_4 -> V_9 + V_10 ;
void T_3 * V_11 = V_8 + V_12 ;
void T_3 * V_13 ;
F_2 ( V_5 , V_8 ) ;
V_8 += sizeof( T_1 ) ;
V_13 = V_8 + ( ( V_24 >> 3 ) * sizeof( T_1 ) ) ;
if ( V_13 < V_11 ) {
while ( V_8 < V_13 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
} else {
while ( V_8 < V_11 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
V_8 -= V_10 ;
V_13 -= V_10 ;
if ( V_4 -> V_14 <= V_13 ) {
while ( V_8 < V_4 -> V_14 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
V_8 -= V_4 -> V_15 ;
V_13 -= V_4 -> V_15 ;
}
while ( V_8 < V_13 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
}
F_5 ( V_4 , V_6 , V_24 & 0x7 ) ;
V_4 -> V_39 = 1 + ( V_24 >> 3 ) ;
}
static void F_15 ( struct V_3 * V_4 , const void * V_6 , T_2 V_24 )
{
void T_3 * V_8 = V_4 -> V_9 + ( V_4 -> V_39 * sizeof( T_1 ) ) ;
void T_3 * V_13 ;
unsigned long V_40 = ( V_4 -> V_27 + V_24 ) >> 3 ;
unsigned long V_41 = ( V_4 -> V_27 + V_24 ) & 0x7 ;
V_13 = V_8 + ( V_40 * sizeof( T_1 ) ) ;
if ( V_4 -> V_39 < V_42 ) {
void T_3 * V_11 ;
void T_3 * V_43 ;
V_11 = V_4 -> V_9 + V_12 ;
V_43 = V_11 < V_13 ? V_11 : V_13 ;
V_8 += V_10 ;
V_43 += V_10 ;
while ( V_8 < V_43 ) {
F_10 ( V_4 , V_8 , V_6 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
V_8 -= V_10 ;
}
if ( V_4 -> V_14 <= V_13 ) {
while ( V_8 < V_4 -> V_14 ) {
F_10 ( V_4 , V_8 , V_6 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
V_8 -= V_4 -> V_15 ;
V_13 -= V_4 -> V_15 ;
}
while ( V_8 < V_13 ) {
F_10 ( V_4 , V_8 , V_6 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
if ( V_4 -> V_27 < V_41 ) {
F_7 ( V_4 , V_6 , V_41 - V_4 -> V_27 ) ;
} else {
F_9 ( V_4 , V_4 -> V_27 - V_41 ) ;
}
V_4 -> V_39 += V_40 ;
}
static void F_16 ( struct V_3 * V_4 ,
const void * V_6 , T_2 V_24 )
{
void T_3 * V_8 = V_4 -> V_9 + ( V_4 -> V_39 * sizeof( T_1 ) ) ;
void T_3 * V_13 ;
V_13 = V_8 + ( ( V_24 >> 3 ) * sizeof( T_1 ) ) ;
if ( V_4 -> V_39 < V_42 ) {
void T_3 * V_11 ;
void T_3 * V_43 ;
V_11 = V_4 -> V_9 + V_12 ;
V_43 = V_11 < V_13 ? V_11 : V_13 ;
V_8 += V_10 ;
V_43 += V_10 ;
while ( V_8 < V_43 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
V_8 -= V_10 ;
}
if ( V_4 -> V_14 <= V_13 ) {
while ( V_8 < V_4 -> V_14 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
V_8 -= V_4 -> V_15 ;
V_13 -= V_4 -> V_15 ;
}
while ( V_8 < V_13 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
F_5 ( V_4 , V_6 , V_24 & 0x7 ) ;
V_4 -> V_39 += V_24 >> 3 ;
}
void F_17 ( struct V_3 * V_4 , const void * V_6 , T_2 V_24 )
{
unsigned long V_44 = ( unsigned long ) V_6 & 0x7 ;
if ( V_4 -> V_27 + V_24 < 8 ) {
F_7 ( V_4 , V_6 , V_24 ) ;
return;
}
if ( V_44 ) {
unsigned long V_45 ;
V_45 = 8 - V_44 ;
if ( V_4 -> V_27 + V_45 < 8 ) {
F_7 ( V_4 , V_6 , V_45 ) ;
V_6 += V_45 ;
V_24 -= V_45 ;
} else {
unsigned long V_46 = 8 - V_4 -> V_27 ;
unsigned long V_47 = V_45 - V_46 ;
void T_3 * V_8 ;
F_7 ( V_4 , V_6 , V_46 ) ;
V_6 += V_46 ;
V_24 -= V_46 ;
V_8 = V_4 -> V_9 + ( V_4 -> V_39 * sizeof( T_1 ) ) ;
if ( V_8 >= V_4 -> V_14 )
V_8 -= V_4 -> V_15 ;
else if ( V_4 -> V_39 < V_42 )
V_8 += V_10 ;
F_11 ( V_4 -> V_26 , V_8 ) ;
V_4 -> V_39 ++ ;
F_5 ( V_4 , V_6 , V_47 ) ;
V_6 += V_47 ;
V_24 -= V_47 ;
}
}
if ( V_4 -> V_27 )
F_15 ( V_4 , V_6 , V_24 ) ;
else
F_16 ( V_4 , V_6 , V_24 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
void T_3 * V_8 = V_4 -> V_9 + ( V_4 -> V_39 * sizeof( T_1 ) ) ;
if ( V_8 >= V_4 -> V_14 )
V_8 -= V_4 -> V_15 ;
else if ( V_4 -> V_39 < V_42 )
V_8 += V_10 ;
if ( F_12 ( V_4 , V_8 ) ) {
V_8 += sizeof( T_1 ) ;
}
while ( ( ( unsigned long ) V_8 & V_21 ) != 0 ) {
F_2 ( 0 , V_8 ) ;
V_8 += sizeof( T_1 ) ;
}
F_3 ( * V_4 -> V_22 -> V_23 ) ;
F_4 () ;
}
