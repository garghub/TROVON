static int F_1 ( void * V_1 , struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_1 ;
unsigned int V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_11 = V_6 -> V_12 ;
unsigned int V_13 , V_14 ;
unsigned int V_15 = 1 , V_16 ;
struct V_17 * V_18 ;
V_18 = V_6 -> V_19 + V_11 ;
if ( V_9 -> V_20 -> V_21 )
V_13 = V_22 ;
else
V_13 = V_23 ;
V_16 = V_7 - V_13 ;
V_14 = F_3 ( V_9 -> V_24 , V_3 -> V_25 ,
V_13 , V_26 ) ;
V_18 -> V_14 = F_4 ( V_14 ) ;
if ( F_5 ( V_9 -> V_24 , V_14 ) )
return - 1 ;
V_6 -> V_27 [ V_11 ] . V_28 = V_14 ;
V_6 -> V_27 [ V_11 ] . V_16 = V_13 ;
V_9 -> V_29 -> V_18 -> V_30 ( V_18 , 1 , V_13 , V_4 , V_31 ,
0 , false , V_3 -> V_16 ) ;
while ( V_16 != 0 ) {
V_6 -> V_32 [ V_11 ] = NULL ;
V_11 = F_6 ( V_11 , V_33 ) ;
V_18 = V_6 -> V_19 + V_11 ;
if ( V_16 > V_13 ) {
V_14 = F_3 ( V_9 -> V_24 ,
( V_3 -> V_25 + V_13 * V_15 ) ,
V_13 , V_26 ) ;
V_18 -> V_14 = F_4 ( V_14 ) ;
if ( F_5 ( V_9 -> V_24 , V_14 ) )
return - 1 ;
V_6 -> V_27 [ V_11 ] . V_28 = V_14 ;
V_6 -> V_27 [ V_11 ] . V_16 = V_13 ;
V_9 -> V_29 -> V_18 -> V_30 ( V_18 , 0 , V_13 , V_4 ,
V_31 , 1 ,
false , V_3 -> V_16 ) ;
V_16 -= V_13 ;
V_15 ++ ;
} else {
V_14 = F_3 ( V_9 -> V_24 ,
( V_3 -> V_25 + V_13 * V_15 ) , V_16 ,
V_26 ) ;
V_18 -> V_14 = F_4 ( V_14 ) ;
if ( F_5 ( V_9 -> V_24 , V_14 ) )
return - 1 ;
V_6 -> V_27 [ V_11 ] . V_28 = V_14 ;
V_6 -> V_27 [ V_11 ] . V_16 = V_16 ;
V_9 -> V_29 -> V_18 -> V_30 ( V_18 , 0 , V_16 , V_4 ,
V_31 , 1 ,
true , V_3 -> V_16 ) ;
V_16 = 0 ;
}
}
V_6 -> V_12 = V_11 ;
return V_11 ;
}
static unsigned int F_7 ( int V_16 , int V_21 )
{
unsigned int V_34 = 0 ;
if ( ( V_21 && ( V_16 > V_22 ) ) ||
( ! V_21 && ( V_16 > V_23 ) ) ) {
V_34 = 1 ;
}
return V_34 ;
}
static void F_8 ( void * V_35 , T_1 V_36 ,
unsigned int V_37 , unsigned int V_38 )
{
int V_15 ;
T_1 V_39 = V_36 ;
if ( V_38 ) {
struct V_40 * V_1 = (struct V_40 * ) V_35 ;
for ( V_15 = 0 ; V_15 < ( V_37 - 1 ) ; V_15 ++ ) {
V_39 += sizeof( struct V_40 ) ;
V_1 -> V_41 . V_42 = F_4 ( ( unsigned int ) V_39 ) ;
V_1 ++ ;
}
V_1 -> V_41 . V_42 = F_4 ( ( unsigned int ) V_36 ) ;
} else {
struct V_17 * V_1 = (struct V_17 * ) V_35 ;
for ( V_15 = 0 ; V_15 < ( V_37 - 1 ) ; V_15 ++ ) {
V_39 += sizeof( struct V_17 ) ;
V_1 -> V_42 = F_4 ( ( unsigned int ) V_39 ) ;
V_1 ++ ;
}
V_1 -> V_42 = F_4 ( ( unsigned int ) V_36 ) ;
}
}
static void F_9 ( void * V_43 , struct V_17 * V_1 )
{
struct V_44 * V_45 = (struct V_44 * ) V_43 ;
struct V_8 * V_9 = V_45 -> V_10 ;
if ( V_9 -> V_46 && ! V_9 -> V_38 )
V_1 -> V_42 = F_4 ( ( unsigned int ) ( V_45 -> V_47 +
( ( ( V_45 -> V_48 ) + 1 ) %
V_49 ) *
sizeof( struct V_17 ) ) ) ;
}
static void F_10 ( void * V_43 , struct V_17 * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_43 ;
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_11 = V_6 -> V_50 ;
if ( V_6 -> V_27 [ V_11 ] . V_51 && ! V_9 -> V_38 &&
V_9 -> V_52 )
V_1 -> V_42 = F_4 ( ( unsigned int ) ( ( V_6 -> V_53 +
( ( V_6 -> V_50 + 1 ) % V_33 ) )
* sizeof( struct V_17 ) ) ) ;
}
