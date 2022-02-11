int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( & V_3 ) ;
V_3 . V_4 = V_5 ;
V_3 . V_6 = V_7 ;
V_3 . V_8 = V_9 ;
V_3 . V_10 = V_11 ;
V_3 . V_12 = V_13 ;
V_3 . V_14 = V_2 ;
F_3 ( V_3 . V_15 , L_1 , sizeof( V_3 . V_15 ) ) ;
V_2 -> V_16 = F_4 ( V_17 , V_18 ,
& V_3 ) ;
if ( ! V_2 -> V_16 ) {
F_5 ( L_2 , V_19 ) ;
return - 1 ;
}
V_2 -> V_20 = V_2 -> V_16 -> V_21 ;
V_2 -> V_22 . V_23 = V_24 ;
V_2 -> V_22 . V_25 = V_26 ;
V_2 -> V_22 . V_27 = V_28 ;
V_2 -> V_22 . V_29 = V_30 ;
return 0 ;
}
static int V_26 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_35 = 0 ;
if( V_32 )
F_6 ( V_32 ) ;
V_35 = F_7 ( V_2 -> V_16 , V_34 -> V_36 ,
V_34 -> V_37 , V_34 -> V_38 , NULL ,
V_39 , V_32 ) ;
return V_35 ;
}
static int V_28 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_35 ;
if( V_32 )
F_6 ( V_32 ) ;
V_35 = F_8 ( V_2 -> V_16 , V_39 , V_32 ) ;
return V_35 ;
}
static int V_24 ( struct V_1 * V_2 ,
struct V_31 * V_40 ,
int V_41 )
{
int V_35 ;
F_9 (skb != NULL, return -1;) ;
F_5 ( L_3 , V_19 , V_41 ) ;
F_9 (skb_headroom(skb) >= IRCOMM_HEADER_SIZE, return -1;) ;
F_6 ( V_40 ) ;
F_10 ( V_40 , V_42 ) ;
V_40 -> V_43 [ 0 ] = V_41 ;
V_35 = F_11 ( V_2 -> V_16 , V_40 ) ;
if ( V_35 ) {
F_12 ( L_4 , V_19 ) ;
}
return V_35 ;
}
static int V_5 ( void * V_14 , void * V_44 ,
struct V_31 * V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
F_9 (self != NULL, return -1;) ;
F_9 (self->magic == IRCOMM_MAGIC, return -1;) ;
F_9 (skb != NULL, return -1;) ;
F_13 ( V_2 , V_45 , V_40 , NULL ) ;
F_14 ( V_40 ) ;
return 0 ;
}
static void V_7 ( void * V_14 , void * V_44 ,
struct V_46 * V_47 ,
T_2 V_48 ,
T_3 V_49 ,
struct V_31 * V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
struct V_33 V_34 ;
F_9 (self != NULL, return;) ;
F_9 (self->magic == IRCOMM_MAGIC, return;) ;
F_9 (skb != NULL, return;) ;
F_9 (qos != NULL, goto out;) ;
if ( V_48 != V_39 ) {
F_12 ( L_5 ,
V_19 ) ;
goto V_50;
}
V_34 . V_51 = F_15 ( V_2 -> V_16 )
- V_42 ;
V_34 . V_49 = V_49 + V_42 ;
V_34 . V_47 = V_47 ;
F_13 ( V_2 , V_52 , V_40 , & V_34 ) ;
V_50:
F_14 ( V_40 ) ;
}
static void V_9 ( void * V_14 , void * V_44 ,
struct V_46 * V_47 ,
T_2 V_48 ,
T_3 V_49 ,
struct V_31 * V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
struct V_33 V_34 ;
F_9 (self != NULL, return;) ;
F_9 (self->magic == IRCOMM_MAGIC, return;) ;
F_9 (skb != NULL, return;) ;
F_9 (qos != NULL, goto out;) ;
if ( V_48 != V_39 ) {
F_12 ( L_5 ,
V_19 ) ;
goto V_50;
}
V_34 . V_51 = F_15 ( V_2 -> V_16 )
- V_42 ;
V_34 . V_49 = V_49 + V_42 ;
V_34 . V_47 = V_47 ;
F_13 ( V_2 , V_53 , V_40 , & V_34 ) ;
V_50:
F_14 ( V_40 ) ;
}
static int V_30 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_35 ;
if( V_32 )
F_6 ( V_32 ) ;
V_35 = F_16 ( V_2 -> V_16 , V_32 , V_54 ) ;
return V_35 ;
}
static void V_13 ( void * V_14 , void * V_44 ,
T_4 V_55 ,
struct V_31 * V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
struct V_33 V_34 ;
F_9 (self != NULL, return;) ;
F_9 (self->magic == IRCOMM_MAGIC, return;) ;
V_34 . V_55 = V_55 ;
F_13 ( V_2 , V_56 , V_40 , & V_34 ) ;
if( V_40 )
F_14 ( V_40 ) ;
}
static void V_11 ( void * V_14 , void * V_44 ,
T_5 V_57 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
F_9 (self != NULL, return;) ;
F_9 (self->magic == IRCOMM_MAGIC, return;) ;
if ( V_2 -> V_3 . V_10 )
V_2 -> V_3 . V_10 ( V_2 -> V_3 . V_14 , V_2 , V_57 ) ;
}
