static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
* V_3 = V_4
| V_5
| V_6
| V_7
| V_8 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , T_2 * V_9 )
{
* V_9 = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_3 * V_10 )
{
* V_10 = 0 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_3 * V_11 )
{
* V_11 = 0 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 * V_12 )
{
* V_12 = 0 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 . V_14 . V_15 ) {
V_2 -> V_13 . V_14 . V_15 ( V_2 ) ;
if ( V_2 -> V_13 . V_16 )
V_2 -> V_13 . V_16 ( V_2 , 0 ) ;
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
static int F_10 ( struct V_1 * V_2 , T_4 V_17 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_5 V_18 )
{
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
F_13 ( V_20 ) ;
}
struct V_1 * F_14 ( void )
{
struct V_19 * V_20 = NULL ;
V_20 = F_15 ( sizeof( struct V_19 ) , V_22 ) ;
if ( ! V_20 )
return NULL ;
memcpy ( & V_20 -> V_23 . V_13 , & V_24 , sizeof( struct V_25 ) ) ;
V_20 -> V_23 . V_21 = V_20 ;
return & V_20 -> V_23 ;
}
struct V_1 * F_16 ( void )
{
struct V_19 * V_20 = NULL ;
V_20 = F_15 ( sizeof( struct V_19 ) , V_22 ) ;
if ( ! V_20 )
return NULL ;
memcpy ( & V_20 -> V_23 . V_13 , & V_26 , sizeof( struct V_25 ) ) ;
V_20 -> V_23 . V_21 = V_20 ;
return & V_20 -> V_23 ;
}
struct V_1 * F_17 ( void )
{
struct V_19 * V_20 = NULL ;
V_20 = F_15 ( sizeof( struct V_19 ) , V_22 ) ;
if ( ! V_20 )
return NULL ;
memcpy ( & V_20 -> V_23 . V_13 , & V_27 , sizeof( struct V_25 ) ) ;
V_20 -> V_23 . V_21 = V_20 ;
return & V_20 -> V_23 ;
}
