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
V_11 = F_9 ( V_9 , 0 , V_2 -> V_26 , V_27 , V_7 - sizeof( * V_11 ) ) ;
V_12 = F_10 ( V_11 ) ;
memcpy ( V_12 , V_2 , sizeof( * V_12 ) + V_2 -> V_24 ) ;
F_11 ( V_9 ) . V_28 = V_16 ;
return F_12 ( V_14 -> V_22 , V_9 , 0 , V_16 , V_4 ) ;
V_29:
F_13 ( V_9 ) ;
return - V_30 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_5 * V_31 , * V_32 = NULL ;
struct V_13 * V_14 = & V_15 ;
struct V_1 * V_2 = F_10 ( F_15 ( V_9 ) ) ;
struct V_33 * V_34 = & F_11 ( V_9 ) ;
int V_35 = - V_21 ;
F_2 ( & V_14 -> V_18 -> V_19 ) ;
F_3 (i, &dev->cbdev->queue_list, callback_entry) {
if ( F_4 ( & V_31 -> V_20 . V_20 , & V_2 -> V_20 ) ) {
F_16 ( & V_31 -> V_36 ) ;
V_32 = V_31 ;
break;
}
}
F_5 ( & V_14 -> V_18 -> V_19 ) ;
if ( V_32 != NULL ) {
V_35 = 0 ;
V_32 -> V_37 ( V_2 , V_34 ) ;
F_13 ( V_9 ) ;
F_17 ( V_32 ) ;
V_35 = 0 ;
}
return V_35 ;
}
static void F_18 ( struct V_8 * V_38 )
{
struct V_10 * V_11 ;
int V_35 ;
struct V_8 * V_9 ;
V_9 = F_19 ( V_38 ) ;
if ( V_9 -> V_24 >= F_7 ( 0 ) ) {
V_11 = F_15 ( V_9 ) ;
if ( V_11 -> V_39 < sizeof( struct V_1 ) ||
V_9 -> V_24 < V_11 -> V_39 ||
V_11 -> V_39 > V_40 ) {
F_13 ( V_9 ) ;
return;
}
V_35 = F_14 ( V_9 ) ;
if ( V_35 < 0 )
F_13 ( V_9 ) ;
}
}
int F_20 ( struct V_41 * V_20 , const char * V_42 ,
void (* V_37)( struct V_1 * , struct V_33 * ) )
{
int V_35 ;
struct V_13 * V_14 = & V_15 ;
if ( ! V_43 )
return - V_44 ;
V_35 = F_21 ( V_14 -> V_18 , V_42 , V_20 , V_37 ) ;
if ( V_35 )
return V_35 ;
return 0 ;
}
void F_22 ( struct V_41 * V_20 )
{
struct V_13 * V_14 = & V_15 ;
F_23 ( V_14 -> V_18 , V_20 ) ;
}
static int F_24 ( struct V_45 * V_46 , void * V_47 )
{
struct V_48 * V_14 = V_15 . V_18 ;
struct V_5 * V_32 ;
F_25 ( V_46 , L_1 ) ;
F_2 ( & V_14 -> V_19 ) ;
F_3 (cbq, &dev->queue_list, callback_entry) {
F_25 ( V_46 , L_2 ,
V_32 -> V_20 . V_42 ,
V_32 -> V_20 . V_20 . V_49 ,
V_32 -> V_20 . V_20 . V_50 ) ;
}
F_5 ( & V_14 -> V_19 ) ;
return 0 ;
}
static int F_26 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_27 ( V_52 , F_24 , NULL ) ;
}
static int T_3 F_28 ( void )
{
struct V_13 * V_14 = & V_15 ;
V_14 -> V_53 = F_18 ;
V_14 -> V_22 = F_29 ( & V_54 , V_55 ,
V_56 + 0xf ,
V_14 -> V_53 , NULL , V_57 ) ;
if ( ! V_14 -> V_22 )
return - V_58 ;
V_14 -> V_18 = F_30 ( L_3 , V_14 -> V_22 ) ;
if ( ! V_14 -> V_18 ) {
F_31 ( V_14 -> V_22 ) ;
return - V_30 ;
}
V_43 = 1 ;
F_32 ( & V_54 , L_4 , V_59 , & V_60 ) ;
return 0 ;
}
static void T_4 F_33 ( void )
{
struct V_13 * V_14 = & V_15 ;
V_43 = 0 ;
F_34 ( & V_54 , L_4 ) ;
F_35 ( V_14 -> V_18 ) ;
F_31 ( V_14 -> V_22 ) ;
}
