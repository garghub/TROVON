static int
F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
F_2 () ;
F_3 ( ! V_3 ) ;
* V_3 = 0xbe ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , int V_4 , int V_5 )
{
F_5 ( L_1 , V_5 ) ;
F_2 () ;
V_2 -> V_6 -> V_7 = V_4 ;
V_2 -> V_6 -> V_8 = V_5 ;
return 0 ;
}
static void
F_6 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_11 * V_13 ;
F_7 ( & V_10 -> V_14 ) ;
if ( V_10 -> V_15 ) {
V_13 = F_8 ( V_12 , V_16 ) ;
F_9 ( V_10 -> V_2 , V_13 , 0xcc ) ;
}
F_10 ( & V_10 -> V_14 ) ;
}
static int
F_11 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_17 * V_18 = V_10 -> V_18 ;
F_2 () ;
F_12 ( & V_18 -> V_14 ) ;
if ( V_10 -> V_19 . V_20 == V_10 -> V_19 . V_21 ) {
F_6 ( V_10 , V_12 ) ;
} else {
struct V_9 * V_22 ;
F_13 (dp, &priv->fake->list, list) {
if ( V_22 != V_10 &&
( V_22 -> V_2 -> V_6 -> V_8 ==
V_10 -> V_2 -> V_6 -> V_8 ) )
F_6 ( V_22 , V_12 ) ;
}
}
F_14 ( & V_18 -> V_14 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 ) {
struct V_9 * V_10 = V_2 -> V_10 ;
int V_23 = 0 ;
F_7 ( & V_10 -> V_14 ) ;
if ( V_10 -> V_15 )
V_23 = - V_24 ;
else
V_10 -> V_15 = 1 ;
F_10 ( & V_10 -> V_14 ) ;
return V_23 ;
}
static void
F_16 ( struct V_1 * V_2 ) {
struct V_9 * V_10 = V_2 -> V_10 ;
F_7 ( & V_10 -> V_14 ) ;
V_10 -> V_15 = 0 ;
F_10 ( & V_10 -> V_14 ) ;
}
static int F_17 ( struct V_25 * V_2 , struct V_17 * V_18 )
{
struct V_9 * V_10 ;
int V_26 ;
struct V_1 * V_27 ;
V_27 = F_18 ( sizeof( * V_10 ) , & V_28 ) ;
if ( ! V_27 )
return - V_29 ;
V_10 = V_27 -> V_10 ;
V_10 -> V_2 = V_27 ;
V_27 -> V_6 -> V_30 [ 0 ] |= 1 ;
V_27 -> V_6 -> V_30 [ 0 ] |= 0x7fe ;
V_27 -> V_6 -> V_30 [ 0 ] |= 0x7FFF800 ;
V_27 -> V_6 -> V_30 [ 1 ] |= 1 ;
V_27 -> V_6 -> V_30 [ 1 ] |= 0x7fe ;
V_27 -> V_6 -> V_30 [ 2 ] |= 1 ;
V_27 -> V_6 -> V_30 [ 2 ] |= 0x7fe ;
V_27 -> V_6 -> V_30 [ 3 ] |= 0x3fff ;
V_27 -> V_6 -> V_30 [ 4 ] |= 1 ;
V_27 -> V_6 -> V_30 [ 4 ] |= 0x1e ;
V_27 -> V_6 -> V_30 [ 4 ] |= 0xffe0 ;
V_27 -> V_6 -> V_30 [ 5 ] |= 0xf ;
V_27 -> V_6 -> V_30 [ 5 ] |= 0xf0 ;
V_27 -> V_6 -> V_30 [ 6 ] |= 0x3ff ;
V_27 -> V_6 -> V_30 [ 6 ] |= 0x3ffc00 ;
F_19 ( & V_10 -> V_19 ) ;
V_10 -> V_18 = V_18 ;
F_20 ( & V_10 -> V_14 ) ;
V_27 -> V_31 = V_2 ;
V_26 = F_21 ( V_27 ) ;
if ( V_26 )
goto V_32;
F_22 ( & V_18 -> V_14 ) ;
F_23 ( & V_10 -> V_19 , & V_18 -> V_19 ) ;
F_24 ( & V_18 -> V_14 ) ;
return 0 ;
V_32:
F_25 ( V_10 -> V_2 ) ;
return V_26 ;
}
static void F_26 ( struct V_9 * V_10 )
{
F_22 ( & V_10 -> V_18 -> V_14 ) ;
F_27 ( & V_10 -> V_19 ) ;
F_24 ( & V_10 -> V_18 -> V_14 ) ;
F_28 ( V_10 -> V_2 ) ;
F_25 ( V_10 -> V_2 ) ;
}
static int F_29 ( struct V_33 * V_34 )
{
struct V_17 * V_10 ;
struct V_9 * V_22 ;
int V_26 = - V_29 ;
int V_35 ;
V_10 = F_30 ( & V_34 -> V_2 , sizeof( struct V_17 ) ,
V_36 ) ;
if ( ! V_10 )
goto V_37;
F_19 ( & V_10 -> V_19 ) ;
F_31 ( & V_10 -> V_14 ) ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
V_26 = F_17 ( & V_34 -> V_2 , V_10 ) ;
if ( V_26 < 0 )
goto V_39;
}
F_32 ( V_34 , V_10 ) ;
F_33 ( & V_34 -> V_2 , L_2 ) ;
return 0 ;
V_39:
F_13 (dp, &priv->list, list)
F_26 ( V_22 ) ;
V_37:
return V_26 ;
}
static int F_34 ( struct V_33 * V_34 )
{
struct V_17 * V_10 = F_35 ( V_34 ) ;
struct V_9 * V_22 , * V_40 ;
F_36 (dp, temp, &priv->list, list)
F_26 ( V_22 ) ;
return 0 ;
}
static T_2 int F_37 ( void )
{
V_41 = F_38 (
L_3 , - 1 , NULL , 0 ) ;
return F_39 ( & V_42 ) ;
}
static T_3 void F_40 ( void )
{
F_41 ( & V_42 ) ;
F_42 ( V_41 ) ;
}
