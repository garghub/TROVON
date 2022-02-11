void F_1 ( void )
{
struct V_1 * V_2 , * V_3 ;
F_2 (m, &int_list, head) {
if ( V_2 -> type != V_4 )
continue;
F_2 (s, &int_list, head) {
if ( V_3 -> type != V_5 )
continue;
if ( V_3 -> V_6 . V_7 -> V_8 )
continue;
if ( V_3 -> V_6 . V_7 -> V_9 [ 0 ] != 0
&& strncmp ( V_2 -> V_10 , V_3 -> V_6 . V_7 -> V_9 ,
V_11 ) )
continue;
if ( ! F_3 ( V_2 -> V_12 ) )
continue;
V_3 -> V_6 . V_7 -> V_8 = V_2 ;
if ( V_2 -> V_6 . V_8 -> V_13 ( V_3 ) ) {
V_3 -> V_6 . V_7 -> V_8 = NULL ;
F_4 ( V_2 -> V_12 ) ;
continue;
}
}
}
}
static int F_5 ( const void * V_14 , const void * V_15 )
{
const struct V_16 * V_17 = V_14 , * V_18 = V_15 ;
if ( V_17 -> V_19 > V_18 -> V_19 )
return 1 ;
if ( V_17 -> V_19 < V_18 -> V_19 )
return - 1 ;
return 0 ;
}
int F_6 ( struct V_1 * V_20 )
{
if ( V_20 -> type == V_5 )
F_7 ( V_20 -> V_6 . V_7 -> V_21 , V_20 -> V_6 . V_7 -> V_22 ,
sizeof( struct V_16 ) ,
& F_5 , NULL ) ;
F_8 ( & V_23 ) ;
F_9 ( & V_20 -> V_24 , & V_25 ) ;
F_1 () ;
F_10 ( & V_23 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_20 )
{
F_8 ( & V_23 ) ;
F_12 ( & V_20 -> V_24 ) ;
if ( V_20 -> type == V_5
&& V_20 -> V_6 . V_7 -> V_8 != NULL ) {
V_20 -> V_6 . V_7 -> V_8 -> V_6 . V_8 -> V_26 ( V_20 ) ;
F_4 ( V_20 -> V_6 . V_7 -> V_8 -> V_12 ) ;
V_20 -> V_6 . V_7 -> V_8 = NULL ;
}
F_10 ( & V_23 ) ;
}
static T_1 * F_13 ( struct V_27 * V_7 , int V_28 ,
T_1 * V_29 )
{
const struct V_16 * V_30 = V_7 -> V_21 ;
const struct V_16 * V_31 =
V_30 + V_7 -> V_22 - 1 ;
while ( V_30 <= V_31 ) {
const struct V_16 * V_32 ;
V_32 = ( V_31 - V_30 ) / 2 + V_30 ;
if ( V_32 -> V_19 < V_28 )
V_30 = V_32 + 1 ;
else if ( V_32 -> V_19 > V_28 )
V_31 = V_32 - 1 ;
else
return V_32 -> V_33 ;
}
return V_29 ;
}
static int F_14 ( struct V_1 * V_20 )
{
return - V_34 ;
}
int F_15 ( struct V_1 * V_20 , int V_28 )
{
return ( ( V_35 * )
F_13 ( V_20 -> V_6 . V_7 , V_28 ,
( T_1 * ) F_14 ) ) ( V_20 ) ;
}
static int F_16 ( struct V_1 * V_20 , void * V_36 )
{
return - V_34 ;
}
int F_17 ( struct V_1 * V_20 , int V_28 , void * V_36 )
{
return ( ( V_37 * )
F_13 ( V_20 -> V_6 . V_7 , V_28 ,
( T_1 * ) F_16 ) ) ( V_20 , V_36 ) ;
}
