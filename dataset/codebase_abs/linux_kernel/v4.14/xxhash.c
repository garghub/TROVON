void F_1 ( struct V_1 * V_2 , const struct V_1 * V_3 )
{
memcpy ( V_2 , V_3 , sizeof( * V_2 ) ) ;
}
void F_2 ( struct V_4 * V_2 , const struct V_4 * V_3 )
{
memcpy ( V_2 , V_3 , sizeof( * V_2 ) ) ;
}
static T_1 F_3 ( T_1 V_5 , const T_1 V_6 )
{
V_5 += V_6 * V_7 ;
V_5 = F_4 ( V_5 , 13 ) ;
V_5 *= V_8 ;
return V_5 ;
}
T_1 F_5 ( const void * V_6 , const T_2 V_9 , const T_1 V_5 )
{
const T_3 * V_10 = ( const T_3 * ) V_6 ;
const T_3 * V_11 = V_10 + V_9 ;
T_1 V_12 ;
if ( V_9 >= 16 ) {
const T_3 * const V_13 = V_11 - 16 ;
T_1 V_14 = V_5 + V_8 + V_7 ;
T_1 V_15 = V_5 + V_7 ;
T_1 V_16 = V_5 + 0 ;
T_1 V_17 = V_5 - V_8 ;
do {
V_14 = F_3 ( V_14 , F_6 ( V_10 ) ) ;
V_10 += 4 ;
V_15 = F_3 ( V_15 , F_6 ( V_10 ) ) ;
V_10 += 4 ;
V_16 = F_3 ( V_16 , F_6 ( V_10 ) ) ;
V_10 += 4 ;
V_17 = F_3 ( V_17 , F_6 ( V_10 ) ) ;
V_10 += 4 ;
} while ( V_10 <= V_13 );
V_12 = F_4 ( V_14 , 1 ) + F_4 ( V_15 , 7 ) +
F_4 ( V_16 , 12 ) + F_4 ( V_17 , 18 ) ;
} else {
V_12 = V_5 + V_18 ;
}
V_12 += ( T_1 ) V_9 ;
while ( V_10 + 4 <= V_11 ) {
V_12 += F_6 ( V_10 ) * V_19 ;
V_12 = F_4 ( V_12 , 17 ) * V_20 ;
V_10 += 4 ;
}
while ( V_10 < V_11 ) {
V_12 += ( * V_10 ) * V_18 ;
V_12 = F_4 ( V_12 , 11 ) * V_8 ;
V_10 ++ ;
}
V_12 ^= V_12 >> 15 ;
V_12 *= V_7 ;
V_12 ^= V_12 >> 13 ;
V_12 *= V_19 ;
V_12 ^= V_12 >> 16 ;
return V_12 ;
}
static T_4 F_7 ( T_4 V_21 , const T_4 V_6 )
{
V_21 += V_6 * V_22 ;
V_21 = F_8 ( V_21 , 31 ) ;
V_21 *= V_23 ;
return V_21 ;
}
static T_4 F_9 ( T_4 V_21 , T_4 V_24 )
{
V_24 = F_7 ( 0 , V_24 ) ;
V_21 ^= V_24 ;
V_21 = V_21 * V_23 + V_25 ;
return V_21 ;
}
T_4 F_10 ( const void * V_6 , const T_2 V_9 , const T_4 V_5 )
{
const T_3 * V_10 = ( const T_3 * ) V_6 ;
const T_3 * const V_11 = V_10 + V_9 ;
T_4 V_26 ;
if ( V_9 >= 32 ) {
const T_3 * const V_13 = V_11 - 32 ;
T_4 V_14 = V_5 + V_23 + V_22 ;
T_4 V_15 = V_5 + V_22 ;
T_4 V_16 = V_5 + 0 ;
T_4 V_17 = V_5 - V_23 ;
do {
V_14 = F_7 ( V_14 , F_11 ( V_10 ) ) ;
V_10 += 8 ;
V_15 = F_7 ( V_15 , F_11 ( V_10 ) ) ;
V_10 += 8 ;
V_16 = F_7 ( V_16 , F_11 ( V_10 ) ) ;
V_10 += 8 ;
V_17 = F_7 ( V_17 , F_11 ( V_10 ) ) ;
V_10 += 8 ;
} while ( V_10 <= V_13 );
V_26 = F_8 ( V_14 , 1 ) + F_8 ( V_15 , 7 ) +
F_8 ( V_16 , 12 ) + F_8 ( V_17 , 18 ) ;
V_26 = F_9 ( V_26 , V_14 ) ;
V_26 = F_9 ( V_26 , V_15 ) ;
V_26 = F_9 ( V_26 , V_16 ) ;
V_26 = F_9 ( V_26 , V_17 ) ;
} else {
V_26 = V_5 + V_27 ;
}
V_26 += ( T_4 ) V_9 ;
while ( V_10 + 8 <= V_11 ) {
const T_4 V_28 = F_7 ( 0 , F_11 ( V_10 ) ) ;
V_26 ^= V_28 ;
V_26 = F_8 ( V_26 , 27 ) * V_23 + V_25 ;
V_10 += 8 ;
}
if ( V_10 + 4 <= V_11 ) {
V_26 ^= ( T_4 ) ( F_6 ( V_10 ) ) * V_23 ;
V_26 = F_8 ( V_26 , 23 ) * V_22 + V_29 ;
V_10 += 4 ;
}
while ( V_10 < V_11 ) {
V_26 ^= ( * V_10 ) * V_27 ;
V_26 = F_8 ( V_26 , 11 ) * V_23 ;
V_10 ++ ;
}
V_26 ^= V_26 >> 33 ;
V_26 *= V_22 ;
V_26 ^= V_26 >> 29 ;
V_26 *= V_29 ;
V_26 ^= V_26 >> 32 ;
return V_26 ;
}
void F_12 ( struct V_1 * V_30 , const T_1 V_5 )
{
struct V_1 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_14 = V_5 + V_8 + V_7 ;
V_31 . V_15 = V_5 + V_7 ;
V_31 . V_16 = V_5 + 0 ;
V_31 . V_17 = V_5 - V_8 ;
memcpy ( V_30 , & V_31 , sizeof( V_31 ) ) ;
}
void F_13 ( struct V_4 * V_30 , const T_4 V_5 )
{
struct V_4 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_14 = V_5 + V_23 + V_22 ;
V_31 . V_15 = V_5 + V_22 ;
V_31 . V_16 = V_5 + 0 ;
V_31 . V_17 = V_5 - V_23 ;
memcpy ( V_30 , & V_31 , sizeof( V_31 ) ) ;
}
int F_14 ( struct V_1 * V_31 , const void * V_6 , const T_2 V_9 )
{
const T_3 * V_10 = ( const T_3 * ) V_6 ;
const T_3 * const V_11 = V_10 + V_9 ;
if ( V_6 == NULL )
return - V_32 ;
V_31 -> V_33 += ( T_1 ) V_9 ;
V_31 -> V_34 |= ( V_9 >= 16 ) | ( V_31 -> V_33 >= 16 ) ;
if ( V_31 -> V_35 + V_9 < 16 ) {
memcpy ( ( T_3 * ) ( V_31 -> V_36 ) + V_31 -> V_35 , V_6 , V_9 ) ;
V_31 -> V_35 += ( T_1 ) V_9 ;
return 0 ;
}
if ( V_31 -> V_35 ) {
const T_1 * V_37 = V_31 -> V_36 ;
memcpy ( ( T_3 * ) ( V_31 -> V_36 ) + V_31 -> V_35 , V_6 ,
16 - V_31 -> V_35 ) ;
V_31 -> V_14 = F_3 ( V_31 -> V_14 , F_6 ( V_37 ) ) ;
V_37 ++ ;
V_31 -> V_15 = F_3 ( V_31 -> V_15 , F_6 ( V_37 ) ) ;
V_37 ++ ;
V_31 -> V_16 = F_3 ( V_31 -> V_16 , F_6 ( V_37 ) ) ;
V_37 ++ ;
V_31 -> V_17 = F_3 ( V_31 -> V_17 , F_6 ( V_37 ) ) ;
V_37 ++ ;
V_10 += 16 - V_31 -> V_35 ;
V_31 -> V_35 = 0 ;
}
if ( V_10 <= V_11 - 16 ) {
const T_3 * const V_13 = V_11 - 16 ;
T_1 V_14 = V_31 -> V_14 ;
T_1 V_15 = V_31 -> V_15 ;
T_1 V_16 = V_31 -> V_16 ;
T_1 V_17 = V_31 -> V_17 ;
do {
V_14 = F_3 ( V_14 , F_6 ( V_10 ) ) ;
V_10 += 4 ;
V_15 = F_3 ( V_15 , F_6 ( V_10 ) ) ;
V_10 += 4 ;
V_16 = F_3 ( V_16 , F_6 ( V_10 ) ) ;
V_10 += 4 ;
V_17 = F_3 ( V_17 , F_6 ( V_10 ) ) ;
V_10 += 4 ;
} while ( V_10 <= V_13 );
V_31 -> V_14 = V_14 ;
V_31 -> V_15 = V_15 ;
V_31 -> V_16 = V_16 ;
V_31 -> V_17 = V_17 ;
}
if ( V_10 < V_11 ) {
memcpy ( V_31 -> V_36 , V_10 , ( T_2 ) ( V_11 - V_10 ) ) ;
V_31 -> V_35 = ( T_1 ) ( V_11 - V_10 ) ;
}
return 0 ;
}
T_1 F_15 ( const struct V_1 * V_31 )
{
const T_3 * V_10 = ( const T_3 * ) V_31 -> V_36 ;
const T_3 * const V_11 = ( const T_3 * ) ( V_31 -> V_36 ) +
V_31 -> V_35 ;
T_1 V_12 ;
if ( V_31 -> V_34 ) {
V_12 = F_4 ( V_31 -> V_14 , 1 ) + F_4 ( V_31 -> V_15 , 7 ) +
F_4 ( V_31 -> V_16 , 12 ) + F_4 ( V_31 -> V_17 , 18 ) ;
} else {
V_12 = V_31 -> V_16 + V_18 ;
}
V_12 += V_31 -> V_33 ;
while ( V_10 + 4 <= V_11 ) {
V_12 += F_6 ( V_10 ) * V_19 ;
V_12 = F_4 ( V_12 , 17 ) * V_20 ;
V_10 += 4 ;
}
while ( V_10 < V_11 ) {
V_12 += ( * V_10 ) * V_18 ;
V_12 = F_4 ( V_12 , 11 ) * V_8 ;
V_10 ++ ;
}
V_12 ^= V_12 >> 15 ;
V_12 *= V_7 ;
V_12 ^= V_12 >> 13 ;
V_12 *= V_19 ;
V_12 ^= V_12 >> 16 ;
return V_12 ;
}
int F_16 ( struct V_4 * V_31 , const void * V_6 , const T_2 V_9 )
{
const T_3 * V_10 = ( const T_3 * ) V_6 ;
const T_3 * const V_11 = V_10 + V_9 ;
if ( V_6 == NULL )
return - V_32 ;
V_31 -> V_38 += V_9 ;
if ( V_31 -> V_35 + V_9 < 32 ) {
memcpy ( ( ( T_3 * ) V_31 -> V_39 ) + V_31 -> V_35 , V_6 , V_9 ) ;
V_31 -> V_35 += ( T_1 ) V_9 ;
return 0 ;
}
if ( V_31 -> V_35 ) {
T_4 * V_40 = V_31 -> V_39 ;
memcpy ( ( ( T_3 * ) V_40 ) + V_31 -> V_35 , V_6 ,
32 - V_31 -> V_35 ) ;
V_31 -> V_14 = F_7 ( V_31 -> V_14 , F_11 ( V_40 ) ) ;
V_40 ++ ;
V_31 -> V_15 = F_7 ( V_31 -> V_15 , F_11 ( V_40 ) ) ;
V_40 ++ ;
V_31 -> V_16 = F_7 ( V_31 -> V_16 , F_11 ( V_40 ) ) ;
V_40 ++ ;
V_31 -> V_17 = F_7 ( V_31 -> V_17 , F_11 ( V_40 ) ) ;
V_10 += 32 - V_31 -> V_35 ;
V_31 -> V_35 = 0 ;
}
if ( V_10 + 32 <= V_11 ) {
const T_3 * const V_13 = V_11 - 32 ;
T_4 V_14 = V_31 -> V_14 ;
T_4 V_15 = V_31 -> V_15 ;
T_4 V_16 = V_31 -> V_16 ;
T_4 V_17 = V_31 -> V_17 ;
do {
V_14 = F_7 ( V_14 , F_11 ( V_10 ) ) ;
V_10 += 8 ;
V_15 = F_7 ( V_15 , F_11 ( V_10 ) ) ;
V_10 += 8 ;
V_16 = F_7 ( V_16 , F_11 ( V_10 ) ) ;
V_10 += 8 ;
V_17 = F_7 ( V_17 , F_11 ( V_10 ) ) ;
V_10 += 8 ;
} while ( V_10 <= V_13 );
V_31 -> V_14 = V_14 ;
V_31 -> V_15 = V_15 ;
V_31 -> V_16 = V_16 ;
V_31 -> V_17 = V_17 ;
}
if ( V_10 < V_11 ) {
memcpy ( V_31 -> V_39 , V_10 , ( T_2 ) ( V_11 - V_10 ) ) ;
V_31 -> V_35 = ( T_1 ) ( V_11 - V_10 ) ;
}
return 0 ;
}
T_4 F_17 ( const struct V_4 * V_31 )
{
const T_3 * V_10 = ( const T_3 * ) V_31 -> V_39 ;
const T_3 * const V_11 = ( const T_3 * ) V_31 -> V_39 +
V_31 -> V_35 ;
T_4 V_26 ;
if ( V_31 -> V_38 >= 32 ) {
const T_4 V_14 = V_31 -> V_14 ;
const T_4 V_15 = V_31 -> V_15 ;
const T_4 V_16 = V_31 -> V_16 ;
const T_4 V_17 = V_31 -> V_17 ;
V_26 = F_8 ( V_14 , 1 ) + F_8 ( V_15 , 7 ) +
F_8 ( V_16 , 12 ) + F_8 ( V_17 , 18 ) ;
V_26 = F_9 ( V_26 , V_14 ) ;
V_26 = F_9 ( V_26 , V_15 ) ;
V_26 = F_9 ( V_26 , V_16 ) ;
V_26 = F_9 ( V_26 , V_17 ) ;
} else {
V_26 = V_31 -> V_16 + V_27 ;
}
V_26 += ( T_4 ) V_31 -> V_38 ;
while ( V_10 + 8 <= V_11 ) {
const T_4 V_28 = F_7 ( 0 , F_11 ( V_10 ) ) ;
V_26 ^= V_28 ;
V_26 = F_8 ( V_26 , 27 ) * V_23 + V_25 ;
V_10 += 8 ;
}
if ( V_10 + 4 <= V_11 ) {
V_26 ^= ( T_4 ) ( F_6 ( V_10 ) ) * V_23 ;
V_26 = F_8 ( V_26 , 23 ) * V_22 + V_29 ;
V_10 += 4 ;
}
while ( V_10 < V_11 ) {
V_26 ^= ( * V_10 ) * V_27 ;
V_26 = F_8 ( V_26 , 11 ) * V_23 ;
V_10 ++ ;
}
V_26 ^= V_26 >> 33 ;
V_26 *= V_22 ;
V_26 ^= V_26 >> 29 ;
V_26 *= V_29 ;
V_26 ^= V_26 >> 32 ;
return V_26 ;
}
