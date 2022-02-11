static int F_1 ( void * V_1 , struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_1 ;
unsigned int V_7 = V_6 -> V_8 ;
struct V_9 * V_10 = V_6 -> V_11 + V_7 ;
unsigned int V_12 = F_2 ( V_3 ) ;
unsigned int V_13 ;
unsigned int V_14 = 1 , V_15 ;
if ( V_6 -> V_16 -> V_17 )
V_13 = V_18 ;
else
V_13 = V_19 ;
V_15 = V_12 - V_13 ;
V_10 -> V_20 = F_3 ( V_6 -> V_21 , V_3 -> V_22 ,
V_13 , V_23 ) ;
if ( F_4 ( V_6 -> V_21 , V_10 -> V_20 ) )
return - 1 ;
V_6 -> V_24 [ V_7 ] . V_25 = V_10 -> V_20 ;
V_6 -> V_24 [ V_7 ] . V_15 = V_13 ;
V_6 -> V_26 -> V_10 -> V_27 ( V_10 , 1 , V_13 , V_4 , V_28 ,
0 , false ) ;
while ( V_15 != 0 ) {
V_6 -> V_29 [ V_7 ] = NULL ;
V_7 = F_5 ( V_7 , V_30 ) ;
V_10 = V_6 -> V_11 + V_7 ;
if ( V_15 > V_13 ) {
V_10 -> V_20 = F_3 ( V_6 -> V_21 ,
( V_3 -> V_22 + V_13 * V_14 ) ,
V_13 , V_23 ) ;
if ( F_4 ( V_6 -> V_21 , V_10 -> V_20 ) )
return - 1 ;
V_6 -> V_24 [ V_7 ] . V_25 = V_10 -> V_20 ;
V_6 -> V_24 [ V_7 ] . V_15 = V_13 ;
V_6 -> V_26 -> V_10 -> V_27 ( V_10 , 0 , V_13 , V_4 ,
V_28 , 1 ,
false ) ;
V_15 -= V_13 ;
V_14 ++ ;
} else {
V_10 -> V_20 = F_3 ( V_6 -> V_21 ,
( V_3 -> V_22 + V_13 * V_14 ) , V_15 ,
V_23 ) ;
if ( F_4 ( V_6 -> V_21 , V_10 -> V_20 ) )
return - 1 ;
V_6 -> V_24 [ V_7 ] . V_25 = V_10 -> V_20 ;
V_6 -> V_24 [ V_7 ] . V_15 = V_15 ;
V_6 -> V_26 -> V_10 -> V_27 ( V_10 , 0 , V_15 , V_4 ,
V_28 , 1 ,
true ) ;
V_15 = 0 ;
}
}
V_6 -> V_8 = V_7 ;
return V_7 ;
}
static unsigned int F_6 ( int V_15 , int V_17 )
{
unsigned int V_31 = 0 ;
if ( ( V_17 && ( V_15 > V_18 ) ) ||
( ! V_17 && ( V_15 > V_19 ) ) ) {
V_31 = 1 ;
}
return V_31 ;
}
static void F_7 ( void * V_32 , T_1 V_33 ,
unsigned int V_34 , unsigned int V_35 )
{
int V_14 ;
T_1 V_36 = V_33 ;
if ( V_35 ) {
struct V_37 * V_1 = (struct V_37 * ) V_32 ;
for ( V_14 = 0 ; V_14 < ( V_34 - 1 ) ; V_14 ++ ) {
V_36 += sizeof( struct V_37 ) ;
V_1 -> V_38 . V_39 = ( unsigned int ) V_36 ;
V_1 ++ ;
}
V_1 -> V_38 . V_39 = ( unsigned int ) V_33 ;
} else {
struct V_9 * V_1 = (struct V_9 * ) V_32 ;
for ( V_14 = 0 ; V_14 < ( V_34 - 1 ) ; V_14 ++ ) {
V_36 += sizeof( struct V_9 ) ;
V_1 -> V_39 = ( unsigned int ) V_36 ;
V_1 ++ ;
}
V_1 -> V_39 = ( unsigned int ) V_33 ;
}
}
static void F_8 ( void * V_40 , struct V_9 * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_40 ;
if ( V_6 -> V_41 && ! V_6 -> V_35 )
V_1 -> V_39 = ( unsigned int ) ( V_6 -> V_42 +
( ( ( V_6 -> V_43 ) + 1 ) %
V_44 ) *
sizeof( struct V_9 ) ) ;
}
static void F_9 ( void * V_40 , struct V_9 * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_40 ;
unsigned int V_7 = V_6 -> V_45 ;
if ( V_6 -> V_24 [ V_7 ] . V_46 && ! V_6 -> V_35 &&
V_6 -> V_47 )
V_1 -> V_39 = ( unsigned int ) ( ( V_6 -> V_48 +
( ( V_6 -> V_45 + 1 ) % V_30 ) )
* sizeof( struct V_9 ) ) ;
}
