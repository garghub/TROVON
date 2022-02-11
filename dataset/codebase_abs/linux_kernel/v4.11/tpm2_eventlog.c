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
for ( V_14 = 0 ; ( V_14 < V_2 -> V_18 ) && ( V_14 < V_19 ) ;
V_14 ++ ) {
V_11 = sizeof( V_2 -> V_20 [ V_14 ] . V_21 ) ;
memcpy ( & V_13 , V_9 , V_11 ) ;
V_9 = V_9 + V_11 ;
for ( V_15 = 0 ; ( V_15 < V_6 -> V_22 ) ; V_15 ++ ) {
if ( V_13 == V_6 -> V_23 [ V_15 ] . V_21 ) {
V_9 = V_9 +
V_6 -> V_23 [ V_15 ] . V_24 ;
break;
}
}
}
V_8 = (struct V_7 * ) V_9 ;
V_9 = V_9 + sizeof( V_8 -> V_25 )
+ V_8 -> V_25 ;
V_12 = V_9 - V_10 ;
if ( ( V_2 -> V_17 == 0 ) && ( V_8 -> V_25 == 0 ) )
return 0 ;
return V_12 ;
}
static void * F_2 ( struct V_26 * V_27 , T_4 * V_28 )
{
struct V_29 * V_30 = V_27 -> V_31 ;
struct V_32 * log = & V_30 -> log ;
void * V_33 = log -> V_34 ;
void * V_35 = log -> V_36 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_2 V_12 ;
int V_14 ;
V_4 = V_33 ;
V_12 = sizeof( struct V_3 ) - sizeof( V_4 -> V_2 )
+ V_4 -> V_25 ;
if ( * V_28 == 0 ) {
if ( V_33 + V_12 < V_35 ) {
if ( ( V_4 -> V_17 == 0 ) &&
( V_4 -> V_25 == 0 ) )
return NULL ;
return V_37 ;
}
}
if ( * V_28 > 0 ) {
V_33 += V_12 ;
V_2 = V_33 ;
V_12 = F_1 ( V_2 , V_4 ) ;
if ( ( V_33 + V_12 >= V_35 ) || ( V_12 == 0 ) )
return NULL ;
}
for ( V_14 = 0 ; V_14 < ( * V_28 - 1 ) ; V_14 ++ ) {
V_2 = V_33 ;
V_12 = F_1 ( V_2 , V_4 ) ;
if ( ( V_33 + V_12 >= V_35 ) || ( V_12 == 0 ) )
return NULL ;
V_33 += V_12 ;
}
return V_33 ;
}
static void * F_3 ( struct V_26 * V_27 , void * V_38 ,
T_4 * V_28 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_29 * V_30 = V_27 -> V_31 ;
struct V_32 * log = & V_30 -> log ;
void * V_35 = log -> V_36 ;
T_2 V_25 ;
void * V_9 ;
V_4 = log -> V_34 ;
if ( V_38 == V_37 ) {
V_25 = sizeof( struct V_3 ) -
sizeof( V_4 -> V_2 ) + V_4 -> V_25 ;
V_9 = V_4 ;
} else {
V_2 = V_38 ;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( V_25 == 0 )
return NULL ;
V_9 = V_2 ;
}
V_9 = V_9 + V_25 ;
if ( V_9 >= V_35 )
return NULL ;
V_38 = V_9 ;
V_2 = V_38 ;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( ( ( V_38 + V_25 ) >= V_35 ) || ( V_25 == 0 ) )
return NULL ;
( * V_28 ) ++ ;
return V_38 ;
}
static void F_4 ( struct V_26 * V_27 , void * V_38 )
{
}
static int F_5 ( struct V_26 * V_27 , void * V_38 )
{
struct V_29 * V_30 = V_27 -> V_31 ;
struct V_32 * log = & V_30 -> log ;
struct V_3 * V_4 = log -> V_34 ;
struct V_1 * V_2 = V_38 ;
void * V_39 ;
T_2 V_12 ;
if ( V_38 == V_37 ) {
V_12 = sizeof( struct V_3 ) -
sizeof( V_4 -> V_2 ) + V_4 -> V_25 ;
V_39 = V_4 ;
if ( V_12 > 0 )
F_6 ( V_27 , V_39 , V_12 ) ;
} else {
V_12 = F_1 ( V_2 , V_4 ) ;
V_39 = V_2 ;
if ( V_12 > 0 )
F_6 ( V_27 , V_39 , V_12 ) ;
}
return 0 ;
}
