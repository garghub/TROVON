static inline void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = V_2 -> V_5 . V_6 ( V_2 , V_3 ) ;
V_4 = ( V_4 & 0x2 ) ? ( V_4 & ~ 2 ) : ( V_4 | 2 ) ;
V_2 -> V_5 . V_7 ( V_2 , V_3 , V_4 ) ;
}
static void
F_2 ( struct V_1 * V_2 , T_2 T_3 * V_8 ,
T_2 * V_9 , T_1 V_10 )
{
while ( ( V_10 ) && ( ( unsigned long ) V_8 ) & 7 ) {
F_3 ( * ( V_9 ++ ) , V_8 ++ ) ;
V_10 -- ;
}
F_1 ( V_2 , V_11 ) ;
while ( V_10 >= 8 ) {
F_4 ( * ( ( V_12 * ) V_9 ) , V_8 ) ;
V_8 += 8 ;
V_9 += 8 ;
V_10 -= 8 ;
}
F_1 ( V_2 , V_11 ) ;
while ( V_10 -- )
F_3 ( * ( V_9 ++ ) , V_8 ++ ) ;
}
static void
F_5 ( struct V_1 * V_2 , T_2 T_3 * V_8 ,
T_2 * V_9 , T_1 V_10 )
{
while ( ( V_10 ) && ( ( unsigned long ) V_8 ) & 7 ) {
* ( V_9 ++ ) = F_6 ( V_8 ++ ) ;
V_10 -- ;
}
F_1 ( V_2 , V_11 ) ;
while ( V_10 >= 8 ) {
* ( ( V_12 * ) V_9 ) = F_7 ( V_8 ) ;
V_8 += 8 ;
V_9 += 8 ;
V_10 -= 8 ;
}
F_1 ( V_2 , V_11 ) ;
while ( V_10 -- )
* ( V_9 ++ ) = F_6 ( V_8 ++ ) ;
}
static void
F_8 ( struct V_1 * V_2 , V_12 V_13 ,
T_2 * V_9 , T_1 V_10 , T_1 V_14 )
{
T_1 V_15 = 0 , V_16 = 0 ;
unsigned long V_17 ;
T_2 T_3 * V_8 ;
V_12 V_18 ;
V_18 = V_2 -> V_19 . V_20 ;
if ( V_18 &&
V_18 == ( V_13 & ~ ( V_21 - 1ULL ) ) ) {
int V_22 = V_2 -> V_19 . V_22 ;
V_8 = V_2 -> V_23 [ 1 ] . V_24
+ ( V_22 << F_9 ( V_21 ) )
+ ( V_13 & ( V_21 - 1ULL ) ) ;
if ( V_14 )
F_5 ( V_2 , V_8 , V_9 , V_10 ) ;
else
F_2 ( V_2 , V_8 , V_9 , V_10 ) ;
return;
}
F_10 ( & V_2 -> V_25 , V_17 ) ;
V_16 = V_2 -> V_5 . V_6 ( V_2 , V_11 ) ;
do {
V_2 -> V_5 . V_26 ( V_2 , V_13 , V_11 , 1 ) ;
V_8 = V_2 -> V_23 [ 1 ] . V_24
+ ( V_11 << 22 ) + ( V_13 & 0x3fffff ) ;
if ( ( ( V_13 + V_10 - 1 ) & ~ ( 0x3fffff ) ) != ( V_13 & ~ ( 0x3fffff ) ) ) {
V_15 = ( T_1 ) ( ( ( V_13 & ~ ( 0x3fffff ) ) +
( V_11 << 22 ) ) - V_13 ) ;
} else {
V_15 = V_10 ;
}
if ( V_14 ) {
F_5 ( V_2 , V_8 , V_9 ,
V_15 ) ;
} else {
F_2 ( V_2 , V_8 , V_9 ,
V_15 ) ;
}
V_10 -= V_15 ;
V_13 += V_15 ;
V_9 += V_15 ;
} while ( V_10 );
V_2 -> V_5 . V_7 ( V_2 , V_11 , V_16 ) ;
F_11 ( & V_2 -> V_25 , V_17 ) ;
}
void
F_12 ( struct V_1 * V_2 ,
V_12 V_27 ,
T_2 * V_28 ,
T_1 V_10 )
{
F_8 ( V_2 , V_27 , V_28 , V_10 , 1 ) ;
}
void
F_13 ( struct V_1 * V_2 ,
V_12 V_27 ,
T_2 * V_28 ,
T_1 V_10 )
{
F_8 ( V_2 , V_27 , V_28 , V_10 , 0 ) ;
}
V_12 F_14 ( struct V_1 * V_2 , V_12 V_27 )
{
T_4 V_29 ;
F_8 ( V_2 , V_27 , ( T_2 * ) & V_29 , 8 , 1 ) ;
return F_15 ( V_29 ) ;
}
T_1 F_16 ( struct V_1 * V_2 , V_12 V_27 )
{
T_5 V_29 ;
F_8 ( V_2 , V_27 , ( T_2 * ) & V_29 , 4 , 1 ) ;
return F_17 ( V_29 ) ;
}
void F_18 ( struct V_1 * V_2 , V_12 V_27 ,
T_1 V_30 )
{
T_5 V_31 = F_19 ( V_30 ) ;
F_8 ( V_2 , V_27 , ( T_2 * ) & V_31 , 4 , 0 ) ;
}
