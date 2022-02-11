static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( sizeof( struct V_6 ) , V_8 ) ;
if ( ! V_7 )
return - V_9 ;
V_5 = F_3 ( V_2 , V_4 ) ;
if ( V_5 ) {
F_4 ( V_7 ) ;
return V_5 ;
}
V_2 -> V_10 = V_7 ;
V_2 -> V_11 -> V_12 |= V_13 ;
return V_5 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_10 ;
if ( V_7 -> V_14 )
F_6 ( V_7 -> V_14 ) ;
F_4 ( V_7 ) ;
return F_7 ( V_2 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_21 ;
int V_22 , V_23 ;
struct V_15 * V_24 = V_16 ;
struct V_15 * V_25 ;
struct V_6 * V_7 = V_2 -> V_10 ;
if ( V_7 -> V_14 ) {
V_18 = (struct V_17 * ) V_7 -> V_14 -> V_26 ;
if ( V_16 -> V_27 + V_7 -> V_14 -> V_27 >
F_9 ( & V_18 -> V_27 ) ) {
F_10 ( V_2 , V_28 , V_2 -> V_11 , L_1 ) ;
V_2 -> V_11 -> V_29 . V_30 ++ ;
goto error;
}
V_24 = V_7 -> V_14 ;
memcpy ( F_11 ( V_24 , V_16 -> V_27 ) , V_16 -> V_26 , V_16 -> V_27 ) ;
} else if ( V_16 -> V_27 < 4 ) {
F_10 ( V_2 , V_28 , V_2 -> V_11 , L_2 ) ;
V_2 -> V_11 -> V_29 . V_30 ++ ;
goto error;
}
V_18 = (struct V_17 * ) V_24 -> V_26 ;
if ( V_24 -> V_27 < sizeof( * V_18 ) ||
V_24 -> V_27 != F_9 ( & V_18 -> V_27 ) ) {
if ( V_7 -> V_14 )
return 0 ;
V_7 -> V_14 = F_12 ( V_16 , 0 ,
F_9 ( & V_18 -> V_27 ) , V_31 ) ;
if ( ! V_7 -> V_14 ) {
F_10 ( V_2 , V_28 , V_2 -> V_11 , L_3
L_4 ,
F_9 ( & V_18 -> V_27 ) ) ;
V_2 -> V_11 -> V_29 . V_32 ++ ;
}
return 0 ;
}
V_23 = F_9 ( & V_18 -> V_33 ) ;
F_13 ( V_24 , sizeof( * V_18 ) ) ;
while ( V_23 -- ) {
if ( V_24 -> V_27 < sizeof( * V_20 ) ) {
F_10 ( V_2 , V_28 , V_2 -> V_11 , L_5 ) ;
goto error;
}
V_20 = (struct V_19 * ) V_24 -> V_26 ;
V_22 = sizeof( * V_20 ) + F_9 ( & V_20 -> V_27 ) ;
if ( V_22 > V_24 -> V_27 ) {
F_10 ( V_2 , V_28 , V_2 -> V_11 ,
L_6 ) ;
goto error;
}
V_21 = (struct V_21 * ) V_16 -> V_26 ;
if ( F_14 ( & V_21 -> V_34 ) == V_35 &&
V_24 -> V_27 > 0x26 ) {
memcpy ( V_21 -> V_36 ,
& V_24 -> V_26 [ sizeof( * V_21 ) + 0x8 ] ,
V_37 ) ;
memcpy ( V_21 -> V_38 ,
& V_24 -> V_26 [ sizeof( * V_21 ) + 0x12 ] ,
V_37 ) ;
} else {
memset ( V_21 -> V_36 , 0 , V_37 ) ;
memcpy ( V_21 -> V_38 , V_2 -> V_11 -> V_39 , V_37 ) ;
}
if ( V_23 ) {
V_25 = F_15 ( V_24 , V_31 ) ;
if ( ! V_25 )
goto error;
F_16 ( V_25 , V_22 ) ;
F_17 ( V_2 , V_25 ) ;
F_13 ( V_24 , ( V_22 + 3 ) & ~ 3 ) ;
} else {
F_16 ( V_24 , V_22 ) ;
if ( V_7 -> V_14 ) {
F_17 ( V_2 , V_24 ) ;
V_7 -> V_14 = NULL ;
return 0 ;
}
return 1 ;
}
}
error:
if ( V_7 -> V_14 ) {
F_18 ( V_7 -> V_14 ) ;
V_7 -> V_14 = NULL ;
}
V_2 -> V_11 -> V_29 . V_32 ++ ;
return 0 ;
}
static struct V_15 * F_19 ( struct V_1 * V_2 ,
struct V_15 * V_16 , T_1 V_12 )
{
struct V_15 * V_5 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
static T_2 V_40 = 1 ;
int V_41 = V_16 -> V_27 - sizeof( struct V_21 ) ;
int V_42 = ( V_16 -> V_27 + sizeof( struct V_17 ) + 3 ) & ~ 3 ;
V_18 = (struct V_17 * ) V_16 -> V_26 ;
if ( V_16 -> V_27 > sizeof( * V_18 ) && V_16 -> V_27 == F_9 ( & V_18 -> V_27 ) )
return V_16 ;
if ( V_16 -> V_27 < sizeof( struct V_21 ) )
return NULL ;
if ( ! F_20 ( V_16 ) ) {
int V_43 = F_21 ( V_16 ) ;
int V_44 = F_22 ( V_16 ) ;
if ( V_44 >= V_42 - V_16 -> V_27 - sizeof( * V_18 ) &&
V_43 >= sizeof( * V_18 ) )
goto V_45;
if ( V_43 + V_44 + V_16 -> V_27 >= V_42 ) {
V_16 -> V_26 = memmove ( V_16 -> V_46 + sizeof( * V_18 ) ,
V_16 -> V_26 , V_16 -> V_27 ) ;
F_23 ( V_16 , V_16 -> V_27 ) ;
goto V_45;
}
}
V_5 = F_12 ( V_16 , sizeof( struct V_17 ) , V_42 -
V_16 -> V_27 - sizeof( struct V_17 ) , V_12 ) ;
F_18 ( V_16 ) ;
if ( ! V_5 )
return V_5 ;
V_16 = V_5 ;
V_45:
V_20 = (struct V_19 * ) V_16 -> V_26 ;
memset ( & V_20 -> V_47 , 0 , sizeof( V_20 -> V_47 ) ) ;
V_20 -> V_27 = F_24 ( V_41 ) ;
V_18 = (struct V_17 * ) F_25 ( V_16 , sizeof( * V_18 ) ) ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_27 = F_24 ( V_42 ) ;
V_18 -> V_40 = F_24 ( V_40 ++ ) ;
V_18 -> V_33 = F_24 ( 1 ) ;
if ( V_16 -> V_27 < V_42 )
F_11 ( V_16 , V_42 - V_16 -> V_27 ) ;
return V_16 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_48 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_48 ) ;
}
