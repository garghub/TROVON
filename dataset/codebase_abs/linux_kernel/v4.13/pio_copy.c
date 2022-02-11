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
V_8 -= V_4 -> V_15 -> V_16 ;
V_13 -= V_4 -> V_15 -> V_16 ;
}
while ( V_8 < V_13 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
}
if ( V_7 & 1 ) {
union V_17 V_18 ;
V_18 . V_19 = 0 ;
V_18 . V_20 [ 0 ] = * ( V_21 * ) V_6 ;
F_2 ( V_18 . V_19 , V_8 ) ;
V_8 += sizeof( T_1 ) ;
}
while ( ( ( unsigned long ) V_8 & V_22 ) != 0 ) {
F_2 ( 0 , V_8 ) ;
V_8 += sizeof( T_1 ) ;
}
F_3 ( * V_4 -> V_15 -> V_23 ) ;
F_4 () ;
}
static inline void F_5 ( T_4 * V_8 , const T_4 * V_24 , V_21 V_25 )
{
switch ( V_25 ) {
case 7 :
* V_8 ++ = * V_24 ++ ;
case 6 :
* V_8 ++ = * V_24 ++ ;
case 5 :
* V_8 ++ = * V_24 ++ ;
case 4 :
* V_8 ++ = * V_24 ++ ;
case 3 :
* V_8 ++ = * V_24 ++ ;
case 2 :
* V_8 ++ = * V_24 ++ ;
case 1 :
* V_8 ++ = * V_24 ++ ;
}
}
static inline void F_6 ( struct V_3 * V_4 , const void * V_6 ,
unsigned int V_26 )
{
V_4 -> V_27 . V_19 = 0 ;
F_5 ( & V_4 -> V_27 . V_28 [ 0 ] , V_6 , V_26 ) ;
V_4 -> V_29 = V_26 ;
}
static inline void F_7 ( struct V_3 * V_4 ,
const void * V_6 , unsigned int V_26 )
{
F_5 ( & V_4 -> V_27 . V_28 [ V_4 -> V_29 ] , V_6 , V_26 ) ;
V_4 -> V_29 += V_26 ;
}
static inline void F_8 (
struct V_3 * V_4 ,
void T_3 * V_8 ,
const void * V_24 )
{
T_1 V_30 , V_31 ;
V_30 = * ( T_1 * ) V_24 ;
V_31 = V_4 -> V_27 . V_19 | ( V_30 << F_9 ( V_4 -> V_29 ) ) ;
F_2 ( V_31 , V_8 ) ;
V_4 -> V_27 . V_19 = V_30 >> F_10 ( V_4 -> V_29 ) ;
}
static inline void F_11 ( union V_17 V_27 , void T_3 * V_8 )
{
F_2 ( V_27 . V_19 , V_8 ) ;
}
static inline int F_12 ( struct V_3 * V_4 , void T_3 * V_8 )
{
if ( V_4 -> V_29 ) {
F_2 ( V_4 -> V_27 . V_19 , V_8 ) ;
return 1 ;
}
return 0 ;
}
void F_13 ( struct V_3 * V_4 , T_1 V_5 ,
const void * V_6 , T_2 V_26 )
{
void T_3 * V_8 = V_4 -> V_9 + V_10 ;
void T_3 * V_11 = V_8 + V_12 ;
void T_3 * V_13 ;
F_2 ( V_5 , V_8 ) ;
V_8 += sizeof( T_1 ) ;
V_13 = V_8 + ( ( V_26 >> 3 ) * sizeof( T_1 ) ) ;
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
V_8 -= V_4 -> V_15 -> V_16 ;
V_13 -= V_4 -> V_15 -> V_16 ;
}
while ( V_8 < V_13 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
}
F_6 ( V_4 , V_6 , V_26 & 0x7 ) ;
V_4 -> V_32 = 1 + ( V_26 >> 3 ) ;
}
static void F_14 ( struct V_3 * V_4 , const void * V_6 , T_2 V_26 )
{
void T_3 * V_8 = V_4 -> V_9 + ( V_4 -> V_32 * sizeof( T_1 ) ) ;
void T_3 * V_13 ;
unsigned long V_33 = V_26 >> 3 ;
unsigned long V_34 = V_26 & 0x7 ;
V_13 = V_8 + ( V_33 * sizeof( T_1 ) ) ;
if ( V_4 -> V_32 < V_35 ) {
void T_3 * V_11 ;
void T_3 * V_36 ;
V_11 = V_4 -> V_9 + V_12 ;
V_36 = F_15 ( V_11 , V_13 ) ;
V_8 += V_10 ;
V_36 += V_10 ;
while ( V_8 < V_36 ) {
F_8 ( V_4 , V_8 , V_6 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
V_8 -= V_10 ;
}
if ( V_4 -> V_14 <= V_13 ) {
while ( V_8 < V_4 -> V_14 ) {
F_8 ( V_4 , V_8 , V_6 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
V_8 -= V_4 -> V_15 -> V_16 ;
V_13 -= V_4 -> V_15 -> V_16 ;
}
while ( V_8 < V_13 ) {
F_8 ( V_4 , V_8 , V_6 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
V_4 -> V_32 += V_33 ;
if ( V_4 -> V_29 + V_34 >= 8 ) {
unsigned long V_37 ;
V_37 = 8 - V_4 -> V_29 ;
F_7 ( V_4 , V_6 , V_37 ) ;
if ( V_8 >= V_4 -> V_14 )
V_8 -= V_4 -> V_15 -> V_16 ;
else if ( V_4 -> V_32 < V_35 )
V_8 += V_10 ;
F_11 ( V_4 -> V_27 , V_8 ) ;
V_4 -> V_32 ++ ;
V_34 -= V_37 ;
V_6 += V_37 ;
F_6 ( V_4 , V_6 , V_34 ) ;
} else {
F_7 ( V_4 , V_6 , V_34 ) ;
}
}
static void F_16 ( struct V_3 * V_4 ,
const void * V_6 , T_2 V_26 )
{
void T_3 * V_8 = V_4 -> V_9 + ( V_4 -> V_32 * sizeof( T_1 ) ) ;
void T_3 * V_13 ;
V_13 = V_8 + ( ( V_26 >> 3 ) * sizeof( T_1 ) ) ;
if ( V_4 -> V_32 < V_35 ) {
void T_3 * V_11 ;
void T_3 * V_36 ;
V_11 = V_4 -> V_9 + V_12 ;
V_36 = F_15 ( V_11 , V_13 ) ;
V_8 += V_10 ;
V_36 += V_10 ;
while ( V_8 < V_36 ) {
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
V_8 -= V_4 -> V_15 -> V_16 ;
V_13 -= V_4 -> V_15 -> V_16 ;
}
while ( V_8 < V_13 ) {
F_2 ( * ( T_1 * ) V_6 , V_8 ) ;
V_6 += sizeof( T_1 ) ;
V_8 += sizeof( T_1 ) ;
}
F_6 ( V_4 , V_6 , V_26 & 0x7 ) ;
V_4 -> V_32 += V_26 >> 3 ;
}
void F_17 ( struct V_3 * V_4 , const void * V_6 , T_2 V_26 )
{
unsigned long V_38 = ( unsigned long ) V_6 & 0x7 ;
if ( V_4 -> V_29 + V_26 < 8 ) {
F_7 ( V_4 , V_6 , V_26 ) ;
return;
}
if ( V_38 ) {
unsigned long V_39 ;
V_39 = 8 - V_38 ;
if ( V_4 -> V_29 + V_39 < 8 ) {
F_7 ( V_4 , V_6 , V_39 ) ;
V_6 += V_39 ;
V_26 -= V_39 ;
} else {
unsigned long V_40 = 8 - V_4 -> V_29 ;
unsigned long V_41 = V_39 - V_40 ;
void T_3 * V_8 ;
F_7 ( V_4 , V_6 , V_40 ) ;
V_6 += V_40 ;
V_26 -= V_40 ;
if ( V_41 > V_26 )
V_41 = V_26 ;
V_8 = V_4 -> V_9 + ( V_4 -> V_32 * sizeof( T_1 ) ) ;
if ( V_8 >= V_4 -> V_14 )
V_8 -= V_4 -> V_15 -> V_16 ;
else if ( V_4 -> V_32 < V_35 )
V_8 += V_10 ;
F_11 ( V_4 -> V_27 , V_8 ) ;
V_4 -> V_32 ++ ;
F_6 ( V_4 , V_6 , V_41 ) ;
V_6 += V_41 ;
V_26 -= V_41 ;
if ( V_26 == 0 )
return;
}
}
if ( V_4 -> V_29 )
F_14 ( V_4 , V_6 , V_26 ) ;
else
F_16 ( V_4 , V_6 , V_26 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
void T_3 * V_8 = V_4 -> V_9 + ( V_4 -> V_32 * sizeof( T_1 ) ) ;
if ( V_8 >= V_4 -> V_14 )
V_8 -= V_4 -> V_15 -> V_16 ;
else if ( V_4 -> V_32 < V_35 )
V_8 += V_10 ;
if ( F_12 ( V_4 , V_8 ) ) {
V_8 += sizeof( T_1 ) ;
}
while ( ( ( unsigned long ) V_8 & V_22 ) != 0 ) {
F_2 ( 0 , V_8 ) ;
V_8 += sizeof( T_1 ) ;
}
F_3 ( * V_4 -> V_15 -> V_23 ) ;
F_4 () ;
}
