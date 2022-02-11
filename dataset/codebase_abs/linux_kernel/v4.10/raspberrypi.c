static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
F_3 ( & V_5 -> V_6 ) ;
}
static int
F_4 ( struct V_4 * V_5 , T_1 V_7 , T_1 V_8 )
{
T_1 V_9 = F_5 ( V_7 , V_8 ) ;
int V_10 ;
F_6 ( V_8 & 0xf ) ;
F_7 ( & V_11 ) ;
F_8 ( & V_5 -> V_6 ) ;
V_10 = F_9 ( V_5 -> V_7 , & V_9 ) ;
if ( V_10 >= 0 ) {
F_10 ( & V_5 -> V_6 ) ;
V_10 = 0 ;
} else {
F_11 ( V_5 -> V_2 . V_12 , L_1 , V_10 ) ;
}
F_12 ( & V_11 ) ;
return V_10 ;
}
int F_13 ( struct V_4 * V_5 ,
void * V_8 , T_2 V_13 )
{
T_2 V_14 = V_13 + 12 ;
T_1 * V_15 ;
T_3 V_16 ;
int V_10 ;
if ( V_14 & 3 )
return - V_17 ;
V_15 = F_14 ( V_5 -> V_2 . V_12 , F_15 ( V_14 ) , & V_16 ,
V_18 ) ;
if ( ! V_15 )
return - V_19 ;
F_6 ( V_14 >= 1024 * 1024 ) ;
V_15 [ 0 ] = V_14 ;
V_15 [ 1 ] = V_20 ;
memcpy ( & V_15 [ 2 ] , V_8 , V_13 ) ;
V_15 [ V_14 / 4 - 1 ] = V_21 ;
F_16 () ;
V_10 = F_4 ( V_5 , V_22 , V_16 ) ;
F_17 () ;
memcpy ( V_8 , & V_15 [ 2 ] , V_13 ) ;
if ( V_10 == 0 && V_15 [ 1 ] != V_23 ) {
F_11 ( V_5 -> V_2 . V_12 , L_2 ,
V_15 [ 2 ] , V_15 [ 1 ] ) ;
V_10 = - V_17 ;
}
F_18 ( V_5 -> V_2 . V_12 , F_15 ( V_14 ) , V_15 , V_16 ) ;
return V_10 ;
}
int F_19 ( struct V_4 * V_5 ,
T_1 V_24 , void * V_25 , T_2 V_26 )
{
T_4 V_8 [ V_26 + sizeof( struct V_27 ) ] ;
struct V_27 * V_28 =
(struct V_27 * ) V_8 ;
int V_10 ;
V_28 -> V_24 = V_24 ;
V_28 -> V_26 = V_26 ;
V_28 -> V_29 = 0 ;
memcpy ( V_8 + sizeof( struct V_27 ) ,
V_25 , V_26 ) ;
V_10 = F_13 ( V_5 , & V_8 , sizeof( V_8 ) ) ;
memcpy ( V_25 ,
V_8 + sizeof( struct V_27 ) ,
V_26 ) ;
return V_10 ;
}
static void
F_20 ( struct V_4 * V_5 )
{
T_1 V_30 ;
int V_10 = F_19 ( V_5 ,
V_31 ,
& V_30 , sizeof( V_30 ) ) ;
if ( V_10 == 0 ) {
struct V_32 V_32 ;
F_21 ( V_30 , 0 , & V_32 ) ;
F_22 ( V_5 -> V_2 . V_12 ,
L_3 ,
V_32 . V_33 + 1900 , V_32 . V_34 + 1 , V_32 . V_35 ,
V_32 . V_36 , V_32 . V_37 ) ;
}
}
static int F_23 ( struct V_38 * V_39 )
{
struct V_40 * V_12 = & V_39 -> V_12 ;
struct V_4 * V_5 ;
V_5 = F_24 ( V_12 , sizeof( * V_5 ) , V_41 ) ;
if ( ! V_5 )
return - V_19 ;
V_5 -> V_2 . V_12 = V_12 ;
V_5 -> V_2 . V_42 = F_1 ;
V_5 -> V_2 . V_43 = true ;
V_5 -> V_7 = F_25 ( & V_5 -> V_2 , 0 ) ;
if ( F_26 ( V_5 -> V_7 ) ) {
int V_10 = F_27 ( V_5 -> V_7 ) ;
if ( V_10 != - V_44 )
F_11 ( V_12 , L_4 , V_10 ) ;
return V_10 ;
}
F_28 ( & V_5 -> V_6 ) ;
F_29 ( V_39 , V_5 ) ;
F_20 ( V_5 ) ;
return 0 ;
}
static int F_30 ( struct V_38 * V_39 )
{
struct V_4 * V_5 = F_31 ( V_39 ) ;
F_32 ( V_5 -> V_7 ) ;
return 0 ;
}
struct V_4 * F_33 ( struct V_45 * V_46 )
{
struct V_38 * V_39 = F_34 ( V_46 ) ;
if ( ! V_39 )
return NULL ;
return F_31 ( V_39 ) ;
}
