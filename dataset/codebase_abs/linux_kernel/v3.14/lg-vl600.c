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
V_2 -> V_11 -> V_12 |= V_14 ;
return V_5 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_10 ;
if ( V_7 -> V_15 )
F_6 ( V_7 -> V_15 ) ;
F_4 ( V_7 ) ;
return F_7 ( V_2 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_22 ;
int V_23 , V_24 ;
struct V_16 * V_25 = V_17 ;
struct V_16 * V_26 ;
struct V_6 * V_7 = V_2 -> V_10 ;
if ( V_7 -> V_15 ) {
V_19 = (struct V_18 * ) V_7 -> V_15 -> V_27 ;
if ( V_17 -> V_28 + V_7 -> V_15 -> V_28 >
F_9 ( & V_19 -> V_28 ) ) {
F_10 ( V_2 , V_29 , V_2 -> V_11 , L_1 ) ;
V_2 -> V_11 -> V_30 . V_31 ++ ;
goto error;
}
V_25 = V_7 -> V_15 ;
memcpy ( F_11 ( V_25 , V_17 -> V_28 ) , V_17 -> V_27 , V_17 -> V_28 ) ;
} else if ( V_17 -> V_28 < 4 ) {
F_10 ( V_2 , V_29 , V_2 -> V_11 , L_2 ) ;
V_2 -> V_11 -> V_30 . V_31 ++ ;
goto error;
}
V_19 = (struct V_18 * ) V_25 -> V_27 ;
if ( F_12 ( V_19 -> V_32 ) != 0x53544448 &&
F_12 ( V_19 -> V_32 ) != 0x44544d48 )
goto error;
if ( V_25 -> V_28 < sizeof( * V_19 ) ||
V_25 -> V_28 != F_9 ( & V_19 -> V_28 ) ) {
if ( V_7 -> V_15 )
return 0 ;
V_7 -> V_15 = F_13 ( V_17 , 0 ,
F_9 ( & V_19 -> V_28 ) , V_33 ) ;
if ( ! V_7 -> V_15 ) {
F_10 ( V_2 , V_29 , V_2 -> V_11 , L_3
L_4 ,
F_9 ( & V_19 -> V_28 ) ) ;
V_2 -> V_11 -> V_30 . V_34 ++ ;
}
return 0 ;
}
V_24 = F_9 ( & V_19 -> V_35 ) ;
F_14 ( V_25 , sizeof( * V_19 ) ) ;
while ( V_24 -- ) {
if ( V_25 -> V_28 < sizeof( * V_21 ) ) {
F_10 ( V_2 , V_29 , V_2 -> V_11 , L_5 ) ;
goto error;
}
V_21 = (struct V_20 * ) V_25 -> V_27 ;
V_23 = sizeof( * V_21 ) + F_9 ( & V_21 -> V_28 ) ;
if ( V_23 > V_25 -> V_28 ) {
F_10 ( V_2 , V_29 , V_2 -> V_11 ,
L_6 ) ;
goto error;
}
V_22 = (struct V_22 * ) V_17 -> V_27 ;
if ( F_15 ( & V_22 -> V_36 ) == V_37 &&
V_25 -> V_28 > 0x26 ) {
memcpy ( V_22 -> V_38 ,
& V_25 -> V_27 [ sizeof( * V_22 ) + 0x8 ] ,
V_39 ) ;
memcpy ( V_22 -> V_40 ,
& V_25 -> V_27 [ sizeof( * V_22 ) + 0x12 ] ,
V_39 ) ;
} else {
memset ( V_22 -> V_38 , 0 , V_39 ) ;
memcpy ( V_22 -> V_40 , V_2 -> V_11 -> V_41 , V_39 ) ;
if ( ( V_25 -> V_27 [ sizeof( * V_22 ) ] & 0xf0 ) == 0x60 )
V_22 -> V_36 = F_16 ( V_42 ) ;
}
if ( V_24 ) {
V_26 = F_17 ( V_25 , V_33 ) ;
if ( ! V_26 )
goto error;
F_18 ( V_26 , V_23 ) ;
F_19 ( V_2 , V_26 ) ;
F_14 ( V_25 , ( V_23 + 3 ) & ~ 3 ) ;
} else {
F_18 ( V_25 , V_23 ) ;
if ( V_7 -> V_15 ) {
F_19 ( V_2 , V_25 ) ;
V_7 -> V_15 = NULL ;
return 0 ;
}
return 1 ;
}
}
error:
if ( V_7 -> V_15 ) {
F_20 ( V_7 -> V_15 ) ;
V_7 -> V_15 = NULL ;
}
V_2 -> V_11 -> V_30 . V_34 ++ ;
return 0 ;
}
static struct V_16 * F_21 ( struct V_1 * V_2 ,
struct V_16 * V_17 , T_1 V_12 )
{
struct V_16 * V_5 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
static T_2 V_43 = 1 ;
int V_44 = V_17 -> V_28 - sizeof( struct V_22 ) ;
int V_45 = ( V_17 -> V_28 + sizeof( struct V_18 ) + 3 ) & ~ 3 ;
V_19 = (struct V_18 * ) V_17 -> V_27 ;
if ( V_17 -> V_28 > sizeof( * V_19 ) && V_17 -> V_28 == F_9 ( & V_19 -> V_28 ) )
return V_17 ;
if ( V_17 -> V_28 < sizeof( struct V_22 ) )
return NULL ;
if ( ! F_22 ( V_17 ) ) {
int V_46 = F_23 ( V_17 ) ;
int V_47 = F_24 ( V_17 ) ;
if ( V_47 >= V_45 - V_17 -> V_28 - sizeof( * V_19 ) &&
V_46 >= sizeof( * V_19 ) )
goto V_48;
if ( V_46 + V_47 + V_17 -> V_28 >= V_45 ) {
V_17 -> V_27 = memmove ( V_17 -> V_49 + sizeof( * V_19 ) ,
V_17 -> V_27 , V_17 -> V_28 ) ;
F_25 ( V_17 , V_17 -> V_28 ) ;
goto V_48;
}
}
V_5 = F_13 ( V_17 , sizeof( struct V_18 ) , V_45 -
V_17 -> V_28 - sizeof( struct V_18 ) , V_12 ) ;
F_20 ( V_17 ) ;
if ( ! V_5 )
return V_5 ;
V_17 = V_5 ;
V_48:
V_21 = (struct V_20 * ) V_17 -> V_27 ;
V_21 -> V_36 = F_26 ( V_50 ) ;
memset ( & V_21 -> V_51 , 0 , sizeof( V_21 -> V_51 ) ) ;
V_21 -> V_28 = F_27 ( V_44 ) ;
V_19 = (struct V_18 * ) F_28 ( V_17 , sizeof( * V_19 ) ) ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_28 = F_27 ( V_45 ) ;
V_19 -> V_43 = F_27 ( V_43 ++ ) ;
V_19 -> V_35 = F_27 ( 1 ) ;
if ( V_17 -> V_28 < V_45 )
F_11 ( V_17 , V_45 - V_17 -> V_28 ) ;
return V_17 ;
}
