struct V_1 * F_1 ( struct V_1 * V_1 )
{
return (struct V_1 * ) ( ( V_2 ) V_1 -> V_3 ) ;
}
void * F_2 ( struct V_1 * V_1 )
{
if ( V_1 -> V_4 )
return ( void * ) ( ( V_2 ) V_1 -> V_5 ) ;
if ( V_1 -> V_6 )
return ( void * ) ( ( V_2 ) V_1 -> V_7 ) ;
return NULL ;
}
struct V_8 * F_3 ( struct V_1 * V_1 )
{
return (struct V_8 * ) ( ( V_2 ) V_1 -> V_8 ) ;
}
struct V_9 * F_4 ( struct V_1 * V_1 )
{
return (struct V_9 * ) ( ( V_2 ) V_1 -> V_9 ) ;
}
void F_5 ( struct V_1 * V_1 , int V_4 , int V_6 )
{
memset ( V_1 , 0 , sizeof( struct V_1 ) ) ;
V_1 -> V_10 = V_11 ;
V_1 -> V_12 = F_6 ( V_13 ) ;
if ( V_4 )
V_1 -> V_4 = 1 ;
if ( V_6 )
V_1 -> V_6 = 1 ;
}
static inline T_1 F_7 ( struct V_8 * V_8 )
{
return V_8 -> V_14 . V_15 - 12 ;
}
static T_2 F_8 ( struct V_8 * V_8 )
{
int V_16 ;
struct V_17 * V_17 ;
T_2 V_18 = 0 ;
T_1 V_19 ;
V_19 = F_7 ( V_8 ) ;
for ( V_16 = 0 ; V_16 < V_19 ; ) {
V_17 = (struct V_17 * ) & V_8 -> V_20 [ V_16 ] ;
V_18 += V_17 -> V_18 ;
if ( ! ( V_17 -> V_12 & V_21 ) )
break;
V_16 += sizeof( struct V_17 ) + F_9 ( ( int ) V_17 -> V_22 , 4 ) ;
}
return V_18 ;
}
static T_2 F_10 ( struct V_23 * V_23 , int V_24 )
{
int V_25 ;
T_2 V_26 ;
T_2 V_27 = 0 ;
T_3 V_28 = 0 ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ ) {
if ( V_23 [ V_25 ] . V_12 & V_29 )
break;
V_28 += V_23 [ V_25 ] . V_18 ;
if ( V_23 [ V_25 ] . V_12 & V_30 ) {
V_26 = 4 + F_9 ( V_28 , 4 ) - V_28 ;
V_27 += V_26 ;
V_28 += V_26 ;
}
}
return V_27 ;
}
void F_11 ( struct V_1 * V_1 , int V_31 )
{
struct V_23 * V_23 ;
struct V_8 * V_8 ;
struct V_32 * V_33 ;
T_2 V_18 ;
V_23 = F_2 ( V_1 ) ;
if ( V_31 > 0 )
V_23 [ V_31 - 1 ] . V_12 |= V_29 ;
V_8 = F_3 ( V_1 ) ;
V_33 = (struct V_32 * ) & V_8 -> V_20 [ F_7 ( V_8 ) ] ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_18 = F_8 ( V_8 ) ;
if ( V_1 -> V_6 && ( V_1 -> V_12 & V_34 ) )
V_18 += F_10 ( V_23 , V_31 ) ;
if ( V_1 -> V_4 )
V_1 -> V_35 = V_18 ;
else if ( V_1 -> V_6 )
V_1 -> V_36 = V_18 ;
V_33 -> V_18 = F_9 ( V_18 , 4 ) + 4 ;
V_1 -> V_37 = ( sizeof( struct V_8 ) + F_7 ( V_8 ) +
sizeof( struct V_32 ) - 20 ) >> 2 ;
}
void F_12 ( struct V_1 * V_1 , struct V_1 * V_38 )
{
V_1 -> V_3 = ( T_2 ) ( ( V_2 ) V_38 ) ;
}
void F_13 ( struct V_1 * V_1 , void * V_39 , int V_40 )
{
if ( V_1 -> V_4 ) {
V_1 -> V_5 = ( T_3 ) ( ( V_2 ) V_39 ) ;
if ( V_40 )
V_1 -> V_12 |= V_41 ;
} else if ( V_1 -> V_6 ) {
V_1 -> V_7 = ( T_3 ) ( ( V_2 ) V_39 ) ;
if ( V_40 )
V_1 -> V_12 |= V_34 ;
}
}
void F_14 ( struct V_1 * V_1 , struct V_8 * V_8 )
{
V_1 -> V_8 = ( T_3 ) ( ( V_2 ) V_8 ) ;
}
void F_15 ( struct V_1 * V_1 , struct V_9 * V_9 )
{
V_1 -> V_9 = ( T_3 ) ( ( V_2 ) V_9 ) ;
}
void F_16 ( struct V_8 * V_8 , T_1 V_19 , T_2 V_42 )
{
memset ( V_8 , 0 , V_19 ) ;
V_8 -> V_14 . V_10 = V_43 ;
V_8 -> V_14 . V_42 = V_42 ;
V_8 -> V_14 . V_15 = 12 ;
}
void F_17 ( struct V_9 * V_9 )
{
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
}
struct V_17 * F_18 ( struct V_8 * V_8 , T_1 V_44 , T_4 V_45 , T_4 V_12 ,
void * V_46 , T_4 V_22 , T_2 V_18 )
{
struct V_17 * V_17 ;
int V_19 ;
int V_47 ;
V_47 = F_7 ( V_8 ) ;
V_19 = F_9 ( sizeof( struct V_17 ) + V_22 , 4 ) ;
if ( sizeof( struct V_48 ) + V_47 + V_19 +
sizeof( struct V_32 ) > V_44 )
return F_19 ( - V_49 ) ;
V_17 = (struct V_17 * ) & V_8 -> V_20 [ V_47 ] ;
memset ( V_17 , 0 , V_19 ) ;
V_17 -> V_45 = V_45 ;
V_17 -> V_12 = V_12 ;
V_17 -> V_18 = V_18 ;
V_17 -> V_22 = V_22 ;
if ( V_46 )
memcpy ( & V_17 -> V_46 [ 0 ] , V_46 , V_22 ) ;
V_8 -> V_14 . V_15 += V_19 ;
return V_17 ;
}
struct V_23 * F_20 ( struct V_1 * V_1 , int V_31 , T_4 V_12 ,
void * V_50 , T_2 V_18 )
{
struct V_23 * V_23 ;
V_23 = ( (struct V_23 * ) F_2 ( V_1 ) ) + V_31 ;
memset ( V_23 , 0 , sizeof( struct V_23 ) ) ;
V_23 -> V_12 = V_12 ;
V_23 -> V_18 = V_18 ;
V_23 -> V_50 = ( T_3 ) ( ( V_2 ) V_50 ) ;
return V_23 ;
}
