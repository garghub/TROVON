static void
F_1 ( struct V_1 * V_2 , T_1 T_2 * V_3 ,
T_1 * V_4 , T_3 V_5 )
{
while ( ( V_5 ) && ( ( unsigned long ) V_3 ) & 7 ) {
F_2 ( * ( V_4 ++ ) , V_3 ++ ) ;
V_5 -- ;
}
F_3 ( V_2 , V_6 ) ;
while ( V_5 >= 8 ) {
F_4 ( * ( ( V_7 * ) V_4 ) , V_3 ) ;
V_3 += 8 ;
V_4 += 8 ;
V_5 -= 8 ;
}
F_3 ( V_2 , V_6 ) ;
while ( V_5 -- )
F_2 ( * ( V_4 ++ ) , V_3 ++ ) ;
}
static void
F_5 ( struct V_1 * V_2 , T_1 T_2 * V_3 ,
T_1 * V_4 , T_3 V_5 )
{
while ( ( V_5 ) && ( ( unsigned long ) V_3 ) & 7 ) {
* ( V_4 ++ ) = F_6 ( V_3 ++ ) ;
V_5 -- ;
}
F_3 ( V_2 , V_6 ) ;
while ( V_5 >= 8 ) {
* ( ( V_7 * ) V_4 ) = F_7 ( V_3 ) ;
V_3 += 8 ;
V_4 += 8 ;
V_5 -= 8 ;
}
F_3 ( V_2 , V_6 ) ;
while ( V_5 -- )
* ( V_4 ++ ) = F_6 ( V_3 ++ ) ;
}
static void
F_8 ( struct V_1 * V_2 , V_7 V_8 ,
T_1 * V_4 , T_3 V_5 , T_3 V_9 )
{
T_3 V_10 = 0 , V_11 = 0 ;
unsigned long V_12 ;
T_1 T_2 * V_3 ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
V_11 = V_2 -> V_14 . V_15 ( V_2 , V_6 ) ;
do {
V_2 -> V_14 . V_16 ( V_2 , V_8 , V_6 , 1 ) ;
V_3 = V_2 -> V_17 [ 1 ] . V_18
+ ( V_6 << 22 ) + ( V_8 & 0x3fffff ) ;
if ( ( ( V_8 + V_5 - 1 ) & ~ ( 0x3fffff ) ) != ( V_8 & ~ ( 0x3fffff ) ) ) {
V_10 = ( T_3 ) ( ( ( V_8 & ~ ( 0x3fffff ) ) +
( V_6 << 22 ) ) - V_8 ) ;
} else {
V_10 = V_5 ;
}
if ( V_9 ) {
F_5 ( V_2 , V_3 , V_4 ,
V_10 ) ;
} else {
F_1 ( V_2 , V_3 , V_4 ,
V_10 ) ;
}
V_5 -= V_10 ;
V_8 += V_10 ;
V_4 += V_10 ;
} while ( V_5 );
V_2 -> V_14 . V_19 ( V_2 , V_6 , V_11 ) ;
F_10 ( & V_2 -> V_13 , V_12 ) ;
}
void
F_11 ( struct V_1 * V_2 ,
V_7 V_20 ,
T_1 * V_21 ,
T_3 V_5 )
{
F_8 ( V_2 , V_20 , V_21 , V_5 , 1 ) ;
}
void
F_12 ( struct V_1 * V_2 ,
V_7 V_20 ,
T_1 * V_21 ,
T_3 V_5 )
{
F_8 ( V_2 , V_20 , V_21 , V_5 , 0 ) ;
}
V_7 F_13 ( struct V_1 * V_2 , V_7 V_20 )
{
T_4 V_22 ;
F_8 ( V_2 , V_20 , ( T_1 * ) & V_22 , 8 , 1 ) ;
return F_14 ( V_22 ) ;
}
T_3 F_15 ( struct V_1 * V_2 , V_7 V_20 )
{
T_5 V_22 ;
F_8 ( V_2 , V_20 , ( T_1 * ) & V_22 , 4 , 1 ) ;
return F_16 ( V_22 ) ;
}
void F_17 ( struct V_1 * V_2 , V_7 V_20 ,
T_3 V_23 )
{
T_5 V_24 = F_18 ( V_23 ) ;
F_8 ( V_2 , V_20 , ( T_1 * ) & V_24 , 4 , 0 ) ;
}
