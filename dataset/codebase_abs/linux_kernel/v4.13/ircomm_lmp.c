static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = 0 ;
if( V_4 )
F_2 ( V_4 ) ;
V_7 = F_3 ( V_2 -> V_8 , V_6 -> V_9 ,
V_6 -> V_10 , V_6 -> V_11 , NULL , V_4 ) ;
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_12 ;
if ( V_4 == NULL ) {
V_12 = F_5 ( V_13 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
F_6 ( V_12 , V_13 ) ;
} else {
F_7 (skb_headroom(userdata) >= LMP_MAX_HEADER,
return -1;) ;
F_2 ( V_4 ) ;
V_12 = V_4 ;
}
return F_8 ( V_2 -> V_8 , V_12 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_3 * V_12 ;
int V_7 ;
if ( ! V_4 ) {
V_12 = F_5 ( V_13 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
F_6 ( V_12 , V_13 ) ;
V_4 = V_12 ;
} else {
F_2 ( V_4 ) ;
}
V_7 = F_10 ( V_2 -> V_8 , V_4 ) ;
return V_7 ;
}
static void F_11 ( struct V_3 * V_16 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
int line ;
F_7 (skb != NULL, return;) ;
V_18 = (struct V_17 * ) V_16 -> V_18 ;
line = V_18 -> line ;
V_2 = (struct V_1 * ) F_12 ( V_19 , line , NULL ) ;
if ( ! V_2 ) {
F_13 ( L_1 , V_20 ) ;
return;
}
F_7 (self != NULL, return;) ;
F_7 (self->magic == IRCOMM_MAGIC, return;) ;
V_2 -> V_21 -- ;
if ( ( V_2 -> V_21 < 2 ) && ( V_2 -> V_22 == V_23 ) ) {
F_13 ( L_2 , V_20 ) ;
V_2 -> V_22 = V_24 ;
if ( V_2 -> V_25 . V_26 )
V_2 -> V_25 . V_26 ( V_2 -> V_25 . V_27 ,
V_2 , V_24 ) ;
}
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_16 ,
int V_28 )
{
struct V_17 * V_18 ;
int V_7 ;
F_7 (skb != NULL, return -1;) ;
V_18 = (struct V_17 * ) V_16 -> V_18 ;
V_18 -> line = V_2 -> line ;
F_13 ( L_3 , V_20 ) ;
F_2 ( V_16 ) ;
F_15 ( V_16 ) ;
V_16 -> V_29 = F_11 ;
if ( ( V_2 -> V_21 ++ > 7 ) && ( V_2 -> V_22 == V_24 ) ) {
F_13 ( L_4 , V_20 ) ;
V_2 -> V_22 = V_23 ;
if ( V_2 -> V_25 . V_26 )
V_2 -> V_25 . V_26 ( V_2 -> V_25 . V_27 ,
V_2 , V_23 ) ;
}
V_7 = F_16 ( V_2 -> V_8 , V_16 ) ;
if ( V_7 ) {
F_17 ( L_5 , V_20 ) ;
}
return V_7 ;
}
static int F_18 ( void * V_27 , void * V_30 ,
struct V_3 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
F_7 (self != NULL, return -1;) ;
F_7 (self->magic == IRCOMM_MAGIC, return -1;) ;
F_7 (skb != NULL, return -1;) ;
F_19 ( V_2 , V_31 , V_16 , NULL ) ;
F_20 ( V_16 ) ;
return 0 ;
}
static void F_21 ( void * V_27 , void * V_30 ,
struct V_32 * V_33 ,
T_1 V_34 ,
T_2 V_35 ,
struct V_3 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_5 V_6 ;
F_7 (self != NULL, return;) ;
F_7 (self->magic == IRCOMM_MAGIC, return;) ;
F_7 (skb != NULL, return;) ;
F_7 (qos != NULL, return;) ;
V_6 . V_36 = V_34 ;
V_6 . V_35 = V_35 ;
V_6 . V_33 = V_33 ;
F_19 ( V_2 , V_37 , V_16 , & V_6 ) ;
F_20 ( V_16 ) ;
}
static void F_22 ( void * V_27 , void * V_30 ,
struct V_32 * V_33 ,
T_1 V_34 ,
T_2 V_35 ,
struct V_3 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_5 V_6 ;
F_7 (self != NULL, return;) ;
F_7 (self->magic == IRCOMM_MAGIC, return;) ;
F_7 (skb != NULL, return;) ;
F_7 (qos != NULL, return;) ;
V_6 . V_36 = V_34 ;
V_6 . V_35 = V_35 ;
V_6 . V_33 = V_33 ;
F_19 ( V_2 , V_38 , V_16 , & V_6 ) ;
F_20 ( V_16 ) ;
}
static void F_23 ( void * V_27 , void * V_30 ,
T_3 V_39 ,
struct V_3 * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_5 V_6 ;
F_7 (self != NULL, return;) ;
F_7 (self->magic == IRCOMM_MAGIC, return;) ;
V_6 . V_39 = V_39 ;
F_19 ( V_2 , V_40 , V_16 , & V_6 ) ;
if( V_16 )
F_20 ( V_16 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
T_4 V_25 ;
F_25 ( & V_25 ) ;
V_25 . V_41 = F_18 ;
V_25 . V_42 = F_21 ;
V_25 . V_43 = F_22 ;
V_25 . V_44 = F_23 ;
V_25 . V_27 = V_2 ;
F_26 ( V_25 . V_45 , L_6 , sizeof( V_25 . V_45 ) ) ;
V_2 -> V_8 = F_27 ( V_46 , & V_25 , 0 ) ;
if ( ! V_2 -> V_8 ) {
F_13 ( L_7 , V_20 ) ;
return - 1 ;
}
V_2 -> V_47 = V_2 -> V_8 -> V_47 ;
V_2 -> V_48 . V_49 = F_14 ;
V_2 -> V_48 . V_50 = F_1 ;
V_2 -> V_48 . V_51 = F_4 ;
V_2 -> V_48 . V_52 = F_9 ;
return 0 ;
}
