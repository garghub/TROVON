int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_2 V_5 )
{
struct V_6 * V_7 ;
unsigned int V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_1 * V_13 ;
struct V_14 * V_15 = & V_16 ;
T_1 V_17 = 0 ;
int V_18 = 0 ;
if ( V_3 || V_4 ) {
V_17 = V_4 ;
} else {
F_2 ( & V_15 -> V_19 -> V_20 ) ;
F_3 (__cbq, &dev->cbdev->queue_list,
callback_entry) {
if ( F_4 ( & V_7 -> V_21 . V_21 , & V_2 -> V_21 ) ) {
V_18 = 1 ;
V_17 = V_7 -> V_17 ;
break;
}
}
F_5 ( & V_15 -> V_19 -> V_20 ) ;
if ( ! V_18 )
return - V_22 ;
}
if ( ! V_3 && ! F_6 ( V_15 -> V_23 , V_17 ) )
return - V_24 ;
V_8 = sizeof( * V_2 ) + V_2 -> V_25 ;
V_10 = F_7 ( V_8 , V_5 ) ;
if ( ! V_10 )
return - V_26 ;
V_12 = F_8 ( V_10 , 0 , V_2 -> V_27 , V_28 , V_8 , 0 ) ;
if ( ! V_12 ) {
F_9 ( V_10 ) ;
return - V_29 ;
}
V_13 = F_10 ( V_12 ) ;
memcpy ( V_13 , V_2 , V_8 ) ;
F_11 ( V_10 ) . V_30 = V_17 ;
if ( V_17 )
return F_12 ( V_15 -> V_23 , V_10 , V_3 , V_17 ,
V_5 ) ;
return F_13 ( V_15 -> V_23 , V_10 , V_3 , ! ( V_5 & V_31 ) ) ;
}
static int F_14 ( struct V_9 * V_10 )
{
struct V_6 * V_32 , * V_33 = NULL ;
struct V_14 * V_15 = & V_16 ;
struct V_1 * V_2 = F_10 ( F_15 ( V_10 ) ) ;
struct V_34 * V_35 = & F_11 ( V_10 ) ;
int V_36 = - V_22 ;
F_2 ( & V_15 -> V_19 -> V_20 ) ;
F_3 (i, &dev->cbdev->queue_list, callback_entry) {
if ( F_4 ( & V_32 -> V_21 . V_21 , & V_2 -> V_21 ) ) {
F_16 ( & V_32 -> V_37 ) ;
V_33 = V_32 ;
break;
}
}
F_5 ( & V_15 -> V_19 -> V_20 ) ;
if ( V_33 != NULL ) {
V_33 -> V_38 ( V_2 , V_35 ) ;
F_9 ( V_10 ) ;
F_17 ( V_33 ) ;
V_36 = 0 ;
}
return V_36 ;
}
static void F_18 ( struct V_9 * V_39 )
{
struct V_11 * V_12 ;
struct V_9 * V_10 ;
int V_25 , V_36 ;
V_10 = F_19 ( V_39 ) ;
if ( V_10 -> V_25 >= V_40 ) {
V_12 = F_15 ( V_10 ) ;
V_25 = F_20 ( V_12 ) ;
if ( V_25 < ( int ) sizeof( struct V_1 ) ||
V_10 -> V_25 < V_12 -> F_20 ||
V_25 > V_41 ) {
F_9 ( V_10 ) ;
return;
}
V_36 = F_14 ( V_10 ) ;
if ( V_36 < 0 )
F_9 ( V_10 ) ;
}
}
int F_21 ( struct V_42 * V_21 , const char * V_43 ,
void (* V_38)( struct V_1 * ,
struct V_34 * ) )
{
int V_36 ;
struct V_14 * V_15 = & V_16 ;
if ( ! V_44 )
return - V_45 ;
V_36 = F_22 ( V_15 -> V_19 , V_43 , V_21 , V_38 ) ;
if ( V_36 )
return V_36 ;
return 0 ;
}
void F_23 ( struct V_42 * V_21 )
{
struct V_14 * V_15 = & V_16 ;
F_24 ( V_15 -> V_19 , V_21 ) ;
}
static int F_25 ( struct V_46 * V_47 , void * V_48 )
{
struct V_49 * V_15 = V_16 . V_19 ;
struct V_6 * V_33 ;
F_26 ( V_47 , L_1 ) ;
F_2 ( & V_15 -> V_20 ) ;
F_3 (cbq, &dev->queue_list, callback_entry) {
F_26 ( V_47 , L_2 ,
V_33 -> V_21 . V_43 ,
V_33 -> V_21 . V_21 . V_50 ,
V_33 -> V_21 . V_21 . V_51 ) ;
}
F_5 ( & V_15 -> V_20 ) ;
return 0 ;
}
static int F_27 ( struct V_52 * V_52 , struct V_53 * V_53 )
{
return F_28 ( V_53 , F_25 , NULL ) ;
}
static int F_29 ( void )
{
struct V_14 * V_15 = & V_16 ;
struct V_54 V_55 = {
. V_56 = V_57 + 0xf ,
. V_58 = V_15 -> V_58 ,
} ;
V_15 -> V_23 = F_30 ( & V_59 , V_60 , & V_55 ) ;
if ( ! V_15 -> V_23 )
return - V_61 ;
V_15 -> V_19 = F_31 ( L_3 , V_15 -> V_23 ) ;
if ( ! V_15 -> V_19 ) {
F_32 ( V_15 -> V_23 ) ;
return - V_62 ;
}
V_44 = 1 ;
F_33 ( L_4 , V_63 , V_59 . V_64 , & V_65 ) ;
return 0 ;
}
static void F_34 ( void )
{
struct V_14 * V_15 = & V_16 ;
V_44 = 0 ;
F_35 ( L_4 , V_59 . V_64 ) ;
F_36 ( V_15 -> V_19 ) ;
F_32 ( V_15 -> V_23 ) ;
}
