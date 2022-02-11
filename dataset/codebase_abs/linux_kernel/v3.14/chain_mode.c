static unsigned int F_1 ( void * V_1 , struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_1 ;
unsigned int V_7 = V_6 -> V_8 ;
unsigned int V_9 = V_6 -> V_10 % V_7 ;
struct V_11 * V_12 = V_6 -> V_13 + V_9 ;
unsigned int V_14 = F_2 ( V_3 ) ;
unsigned int V_15 ;
unsigned int V_16 = 1 , V_17 ;
if ( V_6 -> V_18 -> V_19 )
V_15 = V_20 ;
else
V_15 = V_21 ;
V_17 = V_14 - V_15 ;
V_12 -> V_22 = F_3 ( V_6 -> V_23 , V_3 -> V_24 ,
V_15 , V_25 ) ;
V_6 -> V_26 [ V_9 ] = V_12 -> V_22 ;
V_6 -> V_27 -> V_12 -> V_28 ( V_12 , 1 , V_15 , V_4 , V_29 ) ;
while ( V_17 != 0 ) {
V_6 -> V_30 [ V_9 ] = NULL ;
V_9 = ( ++ V_6 -> V_10 ) % V_7 ;
V_12 = V_6 -> V_13 + V_9 ;
if ( V_17 > V_15 ) {
V_12 -> V_22 = F_3 ( V_6 -> V_23 ,
( V_3 -> V_24 + V_15 * V_16 ) ,
V_15 , V_25 ) ;
V_6 -> V_26 [ V_9 ] = V_12 -> V_22 ;
V_6 -> V_27 -> V_12 -> V_28 ( V_12 , 0 , V_15 , V_4 ,
V_29 ) ;
V_6 -> V_27 -> V_12 -> V_31 ( V_12 ) ;
V_17 -= V_15 ;
V_16 ++ ;
} else {
V_12 -> V_22 = F_3 ( V_6 -> V_23 ,
( V_3 -> V_24 + V_15 * V_16 ) , V_17 ,
V_25 ) ;
V_6 -> V_26 [ V_9 ] = V_12 -> V_22 ;
V_6 -> V_27 -> V_12 -> V_28 ( V_12 , 0 , V_17 , V_4 ,
V_29 ) ;
V_6 -> V_27 -> V_12 -> V_31 ( V_12 ) ;
V_17 = 0 ;
}
}
return V_9 ;
}
static unsigned int F_4 ( int V_17 , int V_19 )
{
unsigned int V_32 = 0 ;
if ( ( V_19 && ( V_17 > V_20 ) ) ||
( ! V_19 && ( V_17 > V_21 ) ) ) {
V_32 = 1 ;
}
return V_32 ;
}
static void F_5 ( void * V_33 , T_1 V_34 ,
unsigned int V_35 , unsigned int V_36 )
{
int V_16 ;
T_1 V_37 = V_34 ;
if ( V_36 ) {
struct V_38 * V_1 = (struct V_38 * ) V_33 ;
for ( V_16 = 0 ; V_16 < ( V_35 - 1 ) ; V_16 ++ ) {
V_37 += sizeof( struct V_38 ) ;
V_1 -> V_39 . V_40 = ( unsigned int ) V_37 ;
V_1 ++ ;
}
V_1 -> V_39 . V_40 = ( unsigned int ) V_34 ;
} else {
struct V_11 * V_1 = (struct V_11 * ) V_33 ;
for ( V_16 = 0 ; V_16 < ( V_35 - 1 ) ; V_16 ++ ) {
V_37 += sizeof( struct V_11 ) ;
V_1 -> V_40 = ( unsigned int ) V_37 ;
V_1 ++ ;
}
V_1 -> V_40 = ( unsigned int ) V_34 ;
}
}
static void F_6 ( void * V_41 , struct V_11 * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_41 ;
if ( V_6 -> V_42 && ! V_6 -> V_36 )
V_1 -> V_40 = ( unsigned int ) ( V_6 -> V_43 +
( ( ( V_6 -> V_44 ) + 1 ) %
V_6 -> V_45 ) *
sizeof( struct V_11 ) ) ;
}
static void F_7 ( void * V_41 , struct V_11 * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_41 ;
if ( V_6 -> V_27 -> V_12 -> V_46 ( V_1 ) && ! V_6 -> V_36 )
V_1 -> V_40 = ( unsigned int ) ( V_6 -> V_47 +
( ( ( V_6 -> V_48 + 1 ) %
V_6 -> V_8 ) *
sizeof( struct V_11 ) ) ) ;
}
