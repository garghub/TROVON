static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = 0 ;
F_2 ( 0 , L_1 , V_8 ) ;
if( V_4 )
F_3 ( V_4 ) ;
V_7 = F_4 ( V_2 -> V_9 , V_6 -> V_10 ,
V_6 -> V_11 , V_6 -> V_12 , NULL , V_4 ) ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_13 ;
F_2 ( 0 , L_1 , V_8 ) ;
if ( V_4 == NULL ) {
V_13 = F_6 ( V_14 , V_15 ) ;
if ( ! V_13 )
return - V_16 ;
F_7 ( V_13 , V_14 ) ;
} else {
F_8 (skb_headroom(userdata) >= LMP_MAX_HEADER,
return -1;) ;
F_3 ( V_4 ) ;
V_13 = V_4 ;
}
return F_9 ( V_2 -> V_9 , V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_3 * V_13 ;
int V_7 ;
F_2 ( 0 , L_1 , V_8 ) ;
if ( ! V_4 ) {
V_13 = F_6 ( V_14 , V_15 ) ;
if ( ! V_13 )
return - V_16 ;
F_7 ( V_13 , V_14 ) ;
V_4 = V_13 ;
} else {
F_3 ( V_4 ) ;
}
V_7 = F_11 ( V_2 -> V_9 , V_4 ) ;
return V_7 ;
}
static void F_12 ( struct V_3 * V_17 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 ;
int line ;
F_8 (skb != NULL, return;) ;
V_19 = (struct V_18 * ) V_17 -> V_19 ;
F_2 ( 2 , L_1 , V_8 ) ;
line = V_19 -> line ;
V_2 = (struct V_1 * ) F_13 ( V_20 , line , NULL ) ;
if ( ! V_2 ) {
F_2 ( 2 , L_2 , V_8 ) ;
return;
}
F_8 (self != NULL, return;) ;
F_8 (self->magic == IRCOMM_MAGIC, return;) ;
V_2 -> V_21 -- ;
if ( ( V_2 -> V_21 < 2 ) && ( V_2 -> V_22 == V_23 ) ) {
F_2 ( 2 , L_3 , V_8 ) ;
V_2 -> V_22 = V_24 ;
if ( V_2 -> V_25 . V_26 )
V_2 -> V_25 . V_26 ( V_2 -> V_25 . V_27 ,
V_2 , V_24 ) ;
}
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_17 ,
int V_28 )
{
struct V_18 * V_19 ;
int V_7 ;
F_8 (skb != NULL, return -1;) ;
V_19 = (struct V_18 * ) V_17 -> V_19 ;
V_19 -> line = V_2 -> line ;
F_2 ( 4 , L_4 , V_8 ) ;
F_3 ( V_17 ) ;
F_15 ( V_17 ) ;
V_17 -> V_29 = F_12 ;
if ( ( V_2 -> V_21 ++ > 7 ) && ( V_2 -> V_22 == V_24 ) ) {
F_2 ( 2 , L_5 , V_8 ) ;
V_2 -> V_22 = V_23 ;
if ( V_2 -> V_25 . V_26 )
V_2 -> V_25 . V_26 ( V_2 -> V_25 . V_27 ,
V_2 , V_23 ) ;
}
V_7 = F_16 ( V_2 -> V_9 , V_17 ) ;
if ( V_7 ) {
F_17 ( L_6 , V_8 ) ;
}
return V_7 ;
}
static int F_18 ( void * V_27 , void * V_30 ,
struct V_3 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
F_2 ( 4 , L_1 , V_8 ) ;
F_8 (self != NULL, return -1;) ;
F_8 (self->magic == IRCOMM_MAGIC, return -1;) ;
F_8 (skb != NULL, return -1;) ;
F_19 ( V_2 , V_31 , V_17 , NULL ) ;
F_20 ( V_17 ) ;
return 0 ;
}
static void F_21 ( void * V_27 , void * V_30 ,
struct V_32 * V_33 ,
T_1 V_34 ,
T_2 V_35 ,
struct V_3 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_5 V_6 ;
F_2 ( 0 , L_1 , V_8 ) ;
F_8 (self != NULL, return;) ;
F_8 (self->magic == IRCOMM_MAGIC, return;) ;
F_8 (skb != NULL, return;) ;
F_8 (qos != NULL, return;) ;
V_6 . V_36 = V_34 ;
V_6 . V_35 = V_35 ;
V_6 . V_33 = V_33 ;
F_19 ( V_2 , V_37 , V_17 , & V_6 ) ;
F_20 ( V_17 ) ;
}
static void F_22 ( void * V_27 , void * V_30 ,
struct V_32 * V_33 ,
T_1 V_34 ,
T_2 V_35 ,
struct V_3 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_5 V_6 ;
F_2 ( 0 , L_1 , V_8 ) ;
F_8 (self != NULL, return;) ;
F_8 (self->magic == IRCOMM_MAGIC, return;) ;
F_8 (skb != NULL, return;) ;
F_8 (qos != NULL, return;) ;
V_6 . V_36 = V_34 ;
V_6 . V_35 = V_35 ;
V_6 . V_33 = V_33 ;
F_19 ( V_2 , V_38 , V_17 , & V_6 ) ;
F_20 ( V_17 ) ;
}
static void F_23 ( void * V_27 , void * V_30 ,
T_3 V_39 ,
struct V_3 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_5 V_6 ;
F_2 ( 0 , L_1 , V_8 ) ;
F_8 (self != NULL, return;) ;
F_8 (self->magic == IRCOMM_MAGIC, return;) ;
V_6 . V_39 = V_39 ;
F_19 ( V_2 , V_40 , V_17 , & V_6 ) ;
if( V_17 )
F_20 ( V_17 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
T_4 V_25 ;
F_2 ( 0 , L_1 , V_8 ) ;
F_25 ( & V_25 ) ;
V_25 . V_41 = F_18 ;
V_25 . V_42 = F_21 ;
V_25 . V_43 = F_22 ;
V_25 . V_44 = F_23 ;
V_25 . V_27 = V_2 ;
F_26 ( V_25 . V_45 , L_7 , sizeof( V_25 . V_45 ) ) ;
V_2 -> V_9 = F_27 ( V_46 , & V_25 , 0 ) ;
if ( ! V_2 -> V_9 ) {
F_2 ( 0 , L_8 , V_8 ) ;
return - 1 ;
}
V_2 -> V_47 = V_2 -> V_9 -> V_47 ;
V_2 -> V_48 . V_49 = F_14 ;
V_2 -> V_48 . V_50 = F_1 ;
V_2 -> V_48 . V_51 = F_5 ;
V_2 -> V_48 . V_52 = F_10 ;
return 0 ;
}
