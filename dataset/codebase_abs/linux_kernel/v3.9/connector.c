int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 ;
unsigned int V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_1 * V_12 ;
struct V_13 * V_14 = & V_15 ;
T_1 V_16 = 0 ;
int V_17 = 0 ;
if ( ! V_3 ) {
F_2 ( & V_14 -> V_18 -> V_19 ) ;
F_3 (__cbq, &dev->cbdev->queue_list,
callback_entry) {
if ( F_4 ( & V_6 -> V_20 . V_20 , & V_2 -> V_20 ) ) {
V_17 = 1 ;
V_16 = V_6 -> V_16 ;
break;
}
}
F_5 ( & V_14 -> V_18 -> V_19 ) ;
if ( ! V_17 )
return - V_21 ;
} else {
V_16 = V_3 ;
}
if ( ! F_6 ( V_14 -> V_22 , V_16 ) )
return - V_23 ;
V_7 = F_7 ( sizeof( * V_2 ) + V_2 -> V_24 ) ;
V_9 = F_8 ( V_7 , V_4 ) ;
if ( ! V_9 )
return - V_25 ;
V_11 = F_9 ( V_9 , 0 , V_2 -> V_26 , V_27 , V_7 - sizeof( * V_11 ) , 0 ) ;
if ( ! V_11 ) {
F_10 ( V_9 ) ;
return - V_28 ;
}
V_12 = F_11 ( V_11 ) ;
memcpy ( V_12 , V_2 , sizeof( * V_12 ) + V_2 -> V_24 ) ;
F_12 ( V_9 ) . V_29 = V_16 ;
return F_13 ( V_14 -> V_22 , V_9 , 0 , V_16 , V_4 ) ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_5 * V_30 , * V_31 = NULL ;
struct V_13 * V_14 = & V_15 ;
struct V_1 * V_2 = F_15 ( F_16 ( V_9 ) ) ;
struct V_32 * V_33 = & F_12 ( V_9 ) ;
int V_34 = - V_21 ;
F_2 ( & V_14 -> V_18 -> V_19 ) ;
F_3 (i, &dev->cbdev->queue_list, callback_entry) {
if ( F_4 ( & V_30 -> V_20 . V_20 , & V_2 -> V_20 ) ) {
F_17 ( & V_30 -> V_35 ) ;
V_31 = V_30 ;
break;
}
}
F_5 ( & V_14 -> V_18 -> V_19 ) ;
if ( V_31 != NULL ) {
V_34 = 0 ;
V_31 -> V_36 ( V_2 , V_33 ) ;
F_10 ( V_9 ) ;
F_18 ( V_31 ) ;
V_34 = 0 ;
}
return V_34 ;
}
static void F_19 ( struct V_8 * V_37 )
{
struct V_10 * V_11 ;
int V_34 ;
struct V_8 * V_9 ;
V_9 = F_20 ( V_37 ) ;
if ( V_9 -> V_24 >= F_7 ( 0 ) ) {
V_11 = F_16 ( V_9 ) ;
if ( V_11 -> V_38 < sizeof( struct V_1 ) ||
V_9 -> V_24 < V_11 -> V_38 ||
V_11 -> V_38 > V_39 ) {
F_10 ( V_9 ) ;
return;
}
V_34 = F_14 ( V_9 ) ;
if ( V_34 < 0 )
F_10 ( V_9 ) ;
}
}
int F_21 ( struct V_40 * V_20 , const char * V_41 ,
void (* V_36)( struct V_1 * ,
struct V_32 * ) )
{
int V_34 ;
struct V_13 * V_14 = & V_15 ;
if ( ! V_42 )
return - V_43 ;
V_34 = F_22 ( V_14 -> V_18 , V_41 , V_20 , V_36 ) ;
if ( V_34 )
return V_34 ;
return 0 ;
}
void F_23 ( struct V_40 * V_20 )
{
struct V_13 * V_14 = & V_15 ;
F_24 ( V_14 -> V_18 , V_20 ) ;
}
static int F_25 ( struct V_44 * V_45 , void * V_46 )
{
struct V_47 * V_14 = V_15 . V_18 ;
struct V_5 * V_31 ;
F_26 ( V_45 , L_1 ) ;
F_2 ( & V_14 -> V_19 ) ;
F_3 (cbq, &dev->queue_list, callback_entry) {
F_26 ( V_45 , L_2 ,
V_31 -> V_20 . V_41 ,
V_31 -> V_20 . V_20 . V_48 ,
V_31 -> V_20 . V_20 . V_49 ) ;
}
F_5 ( & V_14 -> V_19 ) ;
return 0 ;
}
static int F_27 ( struct V_50 * V_50 , struct V_51 * V_51 )
{
return F_28 ( V_51 , F_25 , NULL ) ;
}
static int F_29 ( void )
{
struct V_13 * V_14 = & V_15 ;
struct V_52 V_53 = {
. V_54 = V_55 + 0xf ,
. V_56 = V_14 -> V_56 ,
} ;
V_14 -> V_22 = F_30 ( & V_57 , V_58 , & V_53 ) ;
if ( ! V_14 -> V_22 )
return - V_59 ;
V_14 -> V_18 = F_31 ( L_3 , V_14 -> V_22 ) ;
if ( ! V_14 -> V_18 ) {
F_32 ( V_14 -> V_22 ) ;
return - V_60 ;
}
V_42 = 1 ;
F_33 ( L_4 , V_61 , V_57 . V_62 , & V_63 ) ;
return 0 ;
}
static void F_34 ( void )
{
struct V_13 * V_14 = & V_15 ;
V_42 = 0 ;
F_35 ( L_4 , V_57 . V_62 ) ;
F_36 ( V_14 -> V_18 ) ;
F_32 ( V_14 -> V_22 ) ;
}
