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
V_7 = sizeof( * V_2 ) + V_2 -> V_24 ;
V_9 = F_7 ( V_7 , V_4 ) ;
if ( ! V_9 )
return - V_25 ;
V_11 = F_8 ( V_9 , 0 , V_2 -> V_26 , V_27 , V_7 , 0 ) ;
if ( ! V_11 ) {
F_9 ( V_9 ) ;
return - V_28 ;
}
V_12 = F_10 ( V_11 ) ;
memcpy ( V_12 , V_2 , sizeof( * V_12 ) + V_2 -> V_24 ) ;
F_11 ( V_9 ) . V_29 = V_16 ;
return F_12 ( V_14 -> V_22 , V_9 , 0 , V_16 , V_4 ) ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_5 * V_30 , * V_31 = NULL ;
struct V_13 * V_14 = & V_15 ;
struct V_1 * V_2 = F_10 ( F_14 ( V_9 ) ) ;
struct V_32 * V_33 = & F_11 ( V_9 ) ;
int V_34 = - V_21 ;
F_2 ( & V_14 -> V_18 -> V_19 ) ;
F_3 (i, &dev->cbdev->queue_list, callback_entry) {
if ( F_4 ( & V_30 -> V_20 . V_20 , & V_2 -> V_20 ) ) {
F_15 ( & V_30 -> V_35 ) ;
V_31 = V_30 ;
break;
}
}
F_5 ( & V_14 -> V_18 -> V_19 ) ;
if ( V_31 != NULL ) {
V_34 = 0 ;
V_31 -> V_36 ( V_2 , V_33 ) ;
F_9 ( V_9 ) ;
F_16 ( V_31 ) ;
V_34 = 0 ;
}
return V_34 ;
}
static void F_17 ( struct V_8 * V_37 )
{
struct V_10 * V_11 ;
int V_34 ;
struct V_8 * V_9 ;
V_9 = F_18 ( V_37 ) ;
if ( V_9 -> V_24 >= V_38 ) {
V_11 = F_14 ( V_9 ) ;
if ( V_11 -> V_39 < sizeof( struct V_1 ) ||
V_9 -> V_24 < V_11 -> V_39 ||
V_11 -> V_39 > V_40 ) {
F_9 ( V_9 ) ;
return;
}
V_34 = F_13 ( V_9 ) ;
if ( V_34 < 0 )
F_9 ( V_9 ) ;
}
}
int F_19 ( struct V_41 * V_20 , const char * V_42 ,
void (* V_36)( struct V_1 * ,
struct V_32 * ) )
{
int V_34 ;
struct V_13 * V_14 = & V_15 ;
if ( ! V_43 )
return - V_44 ;
V_34 = F_20 ( V_14 -> V_18 , V_42 , V_20 , V_36 ) ;
if ( V_34 )
return V_34 ;
return 0 ;
}
void F_21 ( struct V_41 * V_20 )
{
struct V_13 * V_14 = & V_15 ;
F_22 ( V_14 -> V_18 , V_20 ) ;
}
static int F_23 ( struct V_45 * V_46 , void * V_47 )
{
struct V_48 * V_14 = V_15 . V_18 ;
struct V_5 * V_31 ;
F_24 ( V_46 , L_1 ) ;
F_2 ( & V_14 -> V_19 ) ;
F_3 (cbq, &dev->queue_list, callback_entry) {
F_24 ( V_46 , L_2 ,
V_31 -> V_20 . V_42 ,
V_31 -> V_20 . V_20 . V_49 ,
V_31 -> V_20 . V_20 . V_50 ) ;
}
F_5 ( & V_14 -> V_19 ) ;
return 0 ;
}
static int F_25 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_26 ( V_52 , F_23 , NULL ) ;
}
static int F_27 ( void )
{
struct V_13 * V_14 = & V_15 ;
struct V_53 V_54 = {
. V_55 = V_56 + 0xf ,
. V_57 = V_14 -> V_57 ,
} ;
V_14 -> V_22 = F_28 ( & V_58 , V_59 , & V_54 ) ;
if ( ! V_14 -> V_22 )
return - V_60 ;
V_14 -> V_18 = F_29 ( L_3 , V_14 -> V_22 ) ;
if ( ! V_14 -> V_18 ) {
F_30 ( V_14 -> V_22 ) ;
return - V_61 ;
}
V_43 = 1 ;
F_31 ( L_4 , V_62 , V_58 . V_63 , & V_64 ) ;
return 0 ;
}
static void F_32 ( void )
{
struct V_13 * V_14 = & V_15 ;
V_43 = 0 ;
F_33 ( L_4 , V_58 . V_63 ) ;
F_34 ( V_14 -> V_18 ) ;
F_30 ( V_14 -> V_22 ) ;
}
