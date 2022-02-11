static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 )
return V_3 -> V_4 -> V_5 ;
return NULL ;
}
int F_2 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
union V_8 * V_9 ,
char * V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_12 * V_13 = (struct V_12 * ) V_10 ;
if ( ! V_11 )
return - V_14 ;
V_11 -> V_15 = 0 ;
F_3 () ;
if ( V_9 -> V_16 . V_17 > 0 ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_16 . V_17 ; V_18 ++ )
memcpy ( V_11 -> V_19 [ V_18 ] , V_13 [ V_18 ] . V_20 ,
V_21 ) ;
memset ( V_11 -> V_22 , 0 ,
sizeof( struct V_23 ) * V_24 ) ;
}
F_3 () ;
V_11 -> V_15 = V_9 -> V_16 . V_17 ;
return 0 ;
}
int F_4 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
union V_8 * V_9 ,
char * V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_12 * V_13 = (struct V_12 * ) V_10 ;
int V_18 ;
if ( ! V_11 )
return - V_14 ;
V_9 -> V_16 . V_17 = V_11 -> V_15 ;
for ( V_18 = 0 ; V_18 < V_11 -> V_15 ; V_18 ++ ) {
memcpy ( V_13 [ V_18 ] . V_20 , V_11 -> V_19 [ V_18 ] , V_21 ) ;
V_13 [ V_18 ] . V_25 = V_26 ;
}
if ( V_11 -> V_15 > 0 )
memcpy ( V_10 + ( sizeof( struct V_12 ) * V_11 -> V_15 ) ,
V_11 -> V_22 ,
sizeof( struct V_23 ) * V_11 -> V_15 ) ;
for ( V_18 = 0 ; V_18 < V_11 -> V_15 ; V_18 ++ )
V_11 -> V_22 [ V_18 ] . V_27 &= ~ V_28 ;
return 0 ;
}
int F_5 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
union V_8 * V_9 ,
char * V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_29 * V_30 = (struct V_29 * ) V_10 ;
if ( ! V_11 )
return - V_14 ;
memcpy ( & ( V_11 -> V_31 ) , & ( V_30 -> V_32 ) ,
2 * sizeof( struct V_23 ) ) ;
memset ( V_11 -> V_33 , '\0' , sizeof( V_11 -> V_33 ) ) ;
return 0 ;
}
int F_6 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
union V_8 * V_9 ,
char * V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_29 * V_30 = (struct V_29 * ) V_10 ;
if ( ! V_11 )
return - V_14 ;
memcpy ( & ( V_30 -> V_32 ) , & ( V_11 -> V_31 ) ,
2 * sizeof( struct V_23 ) ) ;
return 0 ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_1 * V_11 ,
unsigned char * V_13 ,
struct V_23 * V_34 )
{
union V_8 V_9 ;
struct V_29 V_30 ;
V_9 . V_16 . V_17 = 1 ;
V_9 . V_16 . V_35 = 0 ;
memcpy ( V_30 . V_36 . V_20 , V_13 , V_21 ) ;
V_30 . V_36 . V_25 = V_37 ;
memcpy ( & ( V_30 . V_38 ) , V_34 , sizeof( struct V_23 ) ) ;
memcpy ( & ( V_30 . V_32 ) , & ( V_11 -> V_31 ) ,
2 * sizeof( struct V_23 ) ) ;
F_8 ( V_3 , V_39 , & V_9 , ( char * ) & V_30 ) ;
}
void F_9 ( struct V_2 * V_3 ,
unsigned char * V_13 ,
struct V_23 * V_34 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
int V_18 ;
int V_40 = - 1 ;
if ( ! V_11 )
return;
for ( V_18 = 0 ; V_18 < V_11 -> V_15 ; V_18 ++ )
if ( ! F_10 ( V_13 , V_11 -> V_19 [ V_18 ] ) ) {
memcpy ( & ( V_11 -> V_22 [ V_18 ] ) , V_34 ,
sizeof( struct V_23 ) ) ;
V_40 = V_18 ;
}
if ( V_40 >= 0 ) {
if ( V_11 -> V_33 [ V_40 ] ) {
if ( V_34 -> V_41 > V_11 -> V_42 . V_41 ) {
V_11 -> V_33 [ V_40 ] = 0 ;
F_7 ( V_3 , V_11 ,
V_13 , V_34 ) ;
}
} else {
if ( V_34 -> V_41 < V_11 -> V_31 . V_41 ) {
V_11 -> V_33 [ V_40 ] = 1 ;
F_7 ( V_3 , V_11 ,
V_13 , V_34 ) ;
}
}
}
}
