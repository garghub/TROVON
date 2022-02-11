static int
F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
F_2 ( ! V_3 ) ;
* V_3 = 0xbe ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
F_4 ( L_1 , V_5 ) ;
return 0 ;
}
static void
F_5 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_8 * V_10 ;
F_6 ( & V_7 -> V_11 ) ;
if ( V_7 -> V_12 ) {
V_10 = F_7 ( V_9 , V_13 ) ;
F_8 ( V_7 -> V_2 , V_10 , 0xcc ) ;
}
F_9 ( & V_7 -> V_11 ) ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_14 * V_15 = V_7 -> V_15 ;
F_11 ( & V_15 -> V_11 ) ;
if ( V_7 -> V_16 . V_17 == V_7 -> V_16 . V_18 ) {
F_5 ( V_7 , V_9 ) ;
} else {
struct V_6 * V_19 ;
F_12 (dp, &priv->fake->list, list) {
if ( V_19 != V_7 &&
( V_19 -> V_2 -> V_20 -> V_21 ==
V_7 -> V_2 -> V_20 -> V_21 ) )
F_5 ( V_19 , V_9 ) ;
}
}
F_13 ( & V_15 -> V_11 ) ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 ) {
struct V_6 * V_7 = V_2 -> V_7 ;
int V_22 = 0 ;
F_6 ( & V_7 -> V_11 ) ;
if ( V_7 -> V_12 )
V_22 = - V_23 ;
else
V_7 -> V_12 = 1 ;
F_9 ( & V_7 -> V_11 ) ;
return V_22 ;
}
static void
F_15 ( struct V_1 * V_2 ) {
struct V_6 * V_7 = V_2 -> V_7 ;
F_6 ( & V_7 -> V_11 ) ;
V_7 -> V_12 = 0 ;
F_9 ( & V_7 -> V_11 ) ;
}
static int F_16 ( struct V_24 * V_25 , struct V_14 * V_15 )
{
struct V_6 * V_7 ;
int V_26 ;
struct V_1 * V_2 ;
V_2 = F_17 ( sizeof( * V_7 ) , & V_27 ) ;
if ( ! V_2 )
return - V_28 ;
V_7 = V_2 -> V_7 ;
V_7 -> V_2 = V_2 ;
V_2 -> V_20 -> V_29 [ 0 ] |= 1 ;
V_2 -> V_20 -> V_29 [ 0 ] |= 0x7fe ;
V_2 -> V_20 -> V_29 [ 0 ] |= 0x7FFF800 ;
V_2 -> V_20 -> V_29 [ 1 ] |= 1 ;
V_2 -> V_20 -> V_29 [ 1 ] |= 0x7fe ;
V_2 -> V_20 -> V_29 [ 2 ] |= 1 ;
V_2 -> V_20 -> V_29 [ 2 ] |= 0x7fe ;
V_2 -> V_20 -> V_29 [ 3 ] |= 0x3fff ;
V_2 -> V_20 -> V_29 [ 4 ] |= 1 ;
V_2 -> V_20 -> V_29 [ 4 ] |= 0x1e ;
V_2 -> V_20 -> V_29 [ 4 ] |= 0xffe0 ;
V_2 -> V_20 -> V_29 [ 5 ] |= 0xf ;
V_2 -> V_20 -> V_29 [ 5 ] |= 0xf0 ;
V_2 -> V_20 -> V_29 [ 6 ] |= 0x3ff ;
V_2 -> V_20 -> V_29 [ 6 ] |= 0x3ffc00 ;
F_18 ( & V_7 -> V_16 ) ;
V_7 -> V_15 = V_15 ;
F_19 ( & V_7 -> V_11 ) ;
V_2 -> V_30 = V_25 ;
V_26 = F_20 ( V_2 ) ;
if ( V_26 )
goto V_31;
F_21 ( & V_15 -> V_11 ) ;
F_22 ( & V_7 -> V_16 , & V_15 -> V_16 ) ;
F_23 ( & V_15 -> V_11 ) ;
return 0 ;
V_31:
F_24 ( V_7 -> V_2 ) ;
return V_26 ;
}
static void F_25 ( struct V_6 * V_7 )
{
F_21 ( & V_7 -> V_15 -> V_11 ) ;
F_26 ( & V_7 -> V_16 ) ;
F_23 ( & V_7 -> V_15 -> V_11 ) ;
F_27 ( V_7 -> V_2 ) ;
F_24 ( V_7 -> V_2 ) ;
}
static int F_28 ( struct V_32 * V_33 )
{
struct V_14 * V_7 ;
struct V_6 * V_19 ;
int V_26 = - V_28 ;
int V_34 ;
V_7 = F_29 ( & V_33 -> V_25 , sizeof( struct V_14 ) ,
V_35 ) ;
if ( ! V_7 )
goto V_36;
F_18 ( & V_7 -> V_16 ) ;
F_30 ( & V_7 -> V_11 ) ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 ++ ) {
V_26 = F_16 ( & V_33 -> V_25 , V_7 ) ;
if ( V_26 < 0 )
goto V_38;
}
F_31 ( V_33 , V_7 ) ;
F_32 ( & V_33 -> V_25 , L_2 ) ;
return 0 ;
V_38:
F_12 (dp, &priv->list, list)
F_25 ( V_19 ) ;
V_36:
return V_26 ;
}
static int F_33 ( struct V_32 * V_33 )
{
struct V_14 * V_7 = F_34 ( V_33 ) ;
struct V_6 * V_19 , * V_39 ;
F_35 (dp, temp, &priv->list, list)
F_25 ( V_19 ) ;
return 0 ;
}
static T_2 int F_36 ( void )
{
V_40 = F_37 (
L_3 , - 1 , NULL , 0 ) ;
return F_38 ( & V_41 ) ;
}
static T_3 void F_39 ( void )
{
F_40 ( & V_41 ) ;
F_41 ( V_40 ) ;
}
