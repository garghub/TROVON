static int F_1 ( void * V_1 , struct V_2 * V_3 , int V_4 )
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
if ( F_4 ( V_6 -> V_23 , V_12 -> V_22 ) )
return - 1 ;
V_6 -> V_26 [ V_9 ] . V_27 = V_12 -> V_22 ;
V_6 -> V_28 -> V_12 -> V_29 ( V_12 , 1 , V_15 , V_4 , V_30 ) ;
while ( V_17 != 0 ) {
V_6 -> V_31 [ V_9 ] = NULL ;
V_9 = ( ++ V_6 -> V_10 ) % V_7 ;
V_12 = V_6 -> V_13 + V_9 ;
if ( V_17 > V_15 ) {
V_12 -> V_22 = F_3 ( V_6 -> V_23 ,
( V_3 -> V_24 + V_15 * V_16 ) ,
V_15 , V_25 ) ;
if ( F_4 ( V_6 -> V_23 , V_12 -> V_22 ) )
return - 1 ;
V_6 -> V_26 [ V_9 ] . V_27 = V_12 -> V_22 ;
V_6 -> V_28 -> V_12 -> V_29 ( V_12 , 0 , V_15 , V_4 ,
V_30 ) ;
V_6 -> V_28 -> V_12 -> V_32 ( V_12 ) ;
V_17 -= V_15 ;
V_16 ++ ;
} else {
V_12 -> V_22 = F_3 ( V_6 -> V_23 ,
( V_3 -> V_24 + V_15 * V_16 ) , V_17 ,
V_25 ) ;
if ( F_4 ( V_6 -> V_23 , V_12 -> V_22 ) )
return - 1 ;
V_6 -> V_26 [ V_9 ] . V_27 = V_12 -> V_22 ;
V_6 -> V_28 -> V_12 -> V_29 ( V_12 , 0 , V_17 , V_4 ,
V_30 ) ;
V_6 -> V_28 -> V_12 -> V_32 ( V_12 ) ;
V_17 = 0 ;
}
}
return V_9 ;
}
static unsigned int F_5 ( int V_17 , int V_19 )
{
unsigned int V_33 = 0 ;
if ( ( V_19 && ( V_17 > V_20 ) ) ||
( ! V_19 && ( V_17 > V_21 ) ) ) {
V_33 = 1 ;
}
return V_33 ;
}
static void F_6 ( void * V_34 , T_1 V_35 ,
unsigned int V_36 , unsigned int V_37 )
{
int V_16 ;
T_1 V_38 = V_35 ;
if ( V_37 ) {
struct V_39 * V_1 = (struct V_39 * ) V_34 ;
for ( V_16 = 0 ; V_16 < ( V_36 - 1 ) ; V_16 ++ ) {
V_38 += sizeof( struct V_39 ) ;
V_1 -> V_40 . V_41 = ( unsigned int ) V_38 ;
V_1 ++ ;
}
V_1 -> V_40 . V_41 = ( unsigned int ) V_35 ;
} else {
struct V_11 * V_1 = (struct V_11 * ) V_34 ;
for ( V_16 = 0 ; V_16 < ( V_36 - 1 ) ; V_16 ++ ) {
V_38 += sizeof( struct V_11 ) ;
V_1 -> V_41 = ( unsigned int ) V_38 ;
V_1 ++ ;
}
V_1 -> V_41 = ( unsigned int ) V_35 ;
}
}
static void F_7 ( void * V_42 , struct V_11 * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_42 ;
if ( V_6 -> V_43 && ! V_6 -> V_37 )
V_1 -> V_41 = ( unsigned int ) ( V_6 -> V_44 +
( ( ( V_6 -> V_45 ) + 1 ) %
V_6 -> V_46 ) *
sizeof( struct V_11 ) ) ;
}
static void F_8 ( void * V_42 , struct V_11 * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_42 ;
if ( V_6 -> V_28 -> V_12 -> V_47 ( V_1 ) && ! V_6 -> V_37 )
V_1 -> V_41 = ( unsigned int ) ( V_6 -> V_48 +
( ( ( V_6 -> V_49 + 1 ) %
V_6 -> V_8 ) *
sizeof( struct V_11 ) ) ) ;
}
