static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
void * V_9 ;
void * V_10 ;
T_1 V_11 ;
T_2 V_12 ;
T_3 V_13 ;
int V_14 ;
int V_15 ;
V_9 = V_2 ;
V_10 = V_9 ;
V_9 = V_9 + sizeof( V_2 -> V_16 ) + sizeof( V_2 -> V_17 )
+ sizeof( V_2 -> V_18 ) ;
V_6 = (struct V_5 * ) V_4 -> V_2 ;
if ( V_2 -> V_18 > V_6 -> V_19 )
return 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_18 ; V_14 ++ ) {
V_11 = sizeof( V_2 -> V_20 [ V_14 ] . V_21 ) ;
memcpy ( & V_13 , V_9 , V_11 ) ;
V_9 = V_9 + V_11 ;
for ( V_15 = 0 ; V_15 < V_6 -> V_19 ; V_15 ++ ) {
if ( V_13 == V_6 -> V_22 [ V_15 ] . V_21 ) {
V_9 +=
V_6 -> V_22 [ V_15 ] . V_23 ;
break;
}
}
if ( V_15 == V_6 -> V_19 )
return 0 ;
}
V_8 = (struct V_7 * ) V_9 ;
V_9 = V_9 + sizeof( V_8 -> V_24 )
+ V_8 -> V_24 ;
V_12 = V_9 - V_10 ;
if ( ( V_2 -> V_17 == 0 ) && ( V_8 -> V_24 == 0 ) )
return 0 ;
return V_12 ;
}
static void * F_2 ( struct V_25 * V_26 , T_4 * V_27 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_31 * log = & V_29 -> log ;
void * V_32 = log -> V_33 ;
void * V_34 = log -> V_35 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_2 V_12 ;
int V_14 ;
V_4 = V_32 ;
V_12 = sizeof( struct V_3 ) - sizeof( V_4 -> V_2 )
+ V_4 -> V_24 ;
if ( * V_27 == 0 ) {
if ( V_32 + V_12 < V_34 ) {
if ( ( V_4 -> V_17 == 0 ) &&
( V_4 -> V_24 == 0 ) )
return NULL ;
return V_36 ;
}
}
if ( * V_27 > 0 ) {
V_32 += V_12 ;
V_2 = V_32 ;
V_12 = F_1 ( V_2 , V_4 ) ;
if ( ( V_32 + V_12 >= V_34 ) || ( V_12 == 0 ) )
return NULL ;
}
for ( V_14 = 0 ; V_14 < ( * V_27 - 1 ) ; V_14 ++ ) {
V_2 = V_32 ;
V_12 = F_1 ( V_2 , V_4 ) ;
if ( ( V_32 + V_12 >= V_34 ) || ( V_12 == 0 ) )
return NULL ;
V_32 += V_12 ;
}
return V_32 ;
}
static void * F_3 ( struct V_25 * V_26 , void * V_37 ,
T_4 * V_27 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_31 * log = & V_29 -> log ;
void * V_34 = log -> V_35 ;
T_2 V_24 ;
void * V_9 ;
V_4 = log -> V_33 ;
if ( V_37 == V_36 ) {
V_24 = sizeof( struct V_3 ) -
sizeof( V_4 -> V_2 ) + V_4 -> V_24 ;
V_9 = V_4 ;
} else {
V_2 = V_37 ;
V_24 = F_1 ( V_2 , V_4 ) ;
if ( V_24 == 0 )
return NULL ;
V_9 = V_2 ;
}
V_9 = V_9 + V_24 ;
if ( V_9 >= V_34 )
return NULL ;
V_37 = V_9 ;
V_2 = V_37 ;
V_24 = F_1 ( V_2 , V_4 ) ;
if ( ( ( V_37 + V_24 ) >= V_34 ) || ( V_24 == 0 ) )
return NULL ;
( * V_27 ) ++ ;
return V_37 ;
}
static void F_4 ( struct V_25 * V_26 , void * V_37 )
{
}
static int F_5 ( struct V_25 * V_26 , void * V_37 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_31 * log = & V_29 -> log ;
struct V_3 * V_4 = log -> V_33 ;
struct V_1 * V_2 = V_37 ;
void * V_38 ;
T_2 V_12 ;
if ( V_37 == V_36 ) {
V_12 = sizeof( struct V_3 ) -
sizeof( V_4 -> V_2 ) + V_4 -> V_24 ;
V_38 = V_4 ;
if ( V_12 > 0 )
F_6 ( V_26 , V_38 , V_12 ) ;
} else {
V_12 = F_1 ( V_2 , V_4 ) ;
V_38 = V_2 ;
if ( V_12 > 0 )
F_6 ( V_26 , V_38 , V_12 ) ;
}
return 0 ;
}
