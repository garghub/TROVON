static int F_1 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
* V_4 = V_5
| V_6
| V_7
| V_8
| V_9 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 * V_10 )
{
* V_10 = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_2 * V_11 )
{
* V_11 = 0 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 * V_12 )
{
* V_12 = 0 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_13 )
{
* V_13 = 0 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_15 . V_16 ) {
V_2 -> V_14 . V_15 . V_16 ( V_2 ) ;
if ( V_2 -> V_14 . V_17 )
V_2 -> V_14 . V_17 ( V_2 , 0 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_18 V_19 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
enum V_20 V_21 )
{
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_24 ;
F_13 ( V_23 ) ;
}
struct V_1 * F_14 ( void )
{
struct V_22 * V_23 = NULL ;
V_23 = F_15 ( sizeof( struct V_22 ) , V_25 ) ;
if ( ! V_23 )
return NULL ;
memcpy ( & V_23 -> V_26 . V_14 , & V_27 , sizeof( struct V_28 ) ) ;
V_23 -> V_26 . V_24 = V_23 ;
return & V_23 -> V_26 ;
}
struct V_1 * F_16 ( void )
{
struct V_22 * V_23 = NULL ;
V_23 = F_15 ( sizeof( struct V_22 ) , V_25 ) ;
if ( ! V_23 )
return NULL ;
memcpy ( & V_23 -> V_26 . V_14 , & V_29 , sizeof( struct V_28 ) ) ;
V_23 -> V_26 . V_24 = V_23 ;
return & V_23 -> V_26 ;
}
struct V_1 * F_17 ( void )
{
struct V_22 * V_23 = NULL ;
V_23 = F_15 ( sizeof( struct V_22 ) , V_25 ) ;
if ( ! V_23 )
return NULL ;
memcpy ( & V_23 -> V_26 . V_14 , & V_30 , sizeof( struct V_28 ) ) ;
V_23 -> V_26 . V_24 = V_23 ;
return & V_23 -> V_26 ;
}
