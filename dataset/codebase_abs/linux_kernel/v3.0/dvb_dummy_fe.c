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
static int F_6 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
if ( V_2 -> V_15 . V_16 . V_17 ) {
V_2 -> V_15 . V_16 . V_17 ( V_2 , V_14 ) ;
if ( V_2 -> V_15 . V_18 )
V_2 -> V_15 . V_18 ( V_2 , 0 ) ;
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
static int F_10 ( struct V_1 * V_2 , T_4 V_19 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_5 V_20 )
{
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 ;
F_13 ( V_22 ) ;
}
struct V_1 * F_14 ( void )
{
struct V_21 * V_22 = NULL ;
V_22 = F_15 ( sizeof( struct V_21 ) , V_24 ) ;
if ( V_22 == NULL ) goto error;
memcpy ( & V_22 -> V_25 . V_15 , & V_26 , sizeof( struct V_27 ) ) ;
V_22 -> V_25 . V_23 = V_22 ;
return & V_22 -> V_25 ;
error:
F_13 ( V_22 ) ;
return NULL ;
}
struct V_1 * F_16 ( void )
{
struct V_21 * V_22 = NULL ;
V_22 = F_15 ( sizeof( struct V_21 ) , V_24 ) ;
if ( V_22 == NULL ) goto error;
memcpy ( & V_22 -> V_25 . V_15 , & V_28 , sizeof( struct V_27 ) ) ;
V_22 -> V_25 . V_23 = V_22 ;
return & V_22 -> V_25 ;
error:
F_13 ( V_22 ) ;
return NULL ;
}
struct V_1 * F_17 ( void )
{
struct V_21 * V_22 = NULL ;
V_22 = F_15 ( sizeof( struct V_21 ) , V_24 ) ;
if ( V_22 == NULL ) goto error;
memcpy ( & V_22 -> V_25 . V_15 , & V_29 , sizeof( struct V_27 ) ) ;
V_22 -> V_25 . V_23 = V_22 ;
return & V_22 -> V_25 ;
error:
F_13 ( V_22 ) ;
return NULL ;
}
