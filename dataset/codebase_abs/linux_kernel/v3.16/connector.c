int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_3 V_6 )
{
struct V_7 * V_8 ;
unsigned int V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_1 * V_14 ;
struct V_15 * V_16 = & V_17 ;
T_2 V_18 = 0 ;
int V_19 = 0 ;
if ( V_4 || V_5 ) {
V_18 = V_5 ;
} else {
F_2 ( & V_16 -> V_20 -> V_21 ) ;
F_3 (__cbq, &dev->cbdev->queue_list,
callback_entry) {
if ( F_4 ( & V_8 -> V_22 . V_22 , & V_2 -> V_22 ) ) {
V_19 = 1 ;
V_18 = V_8 -> V_18 ;
break;
}
}
F_5 ( & V_16 -> V_20 -> V_21 ) ;
if ( ! V_19 )
return - V_23 ;
}
if ( ! V_4 && ! F_6 ( V_16 -> V_24 , V_18 ) )
return - V_25 ;
V_9 = sizeof( * V_2 ) + V_3 ;
V_11 = F_7 ( V_9 , V_6 ) ;
if ( ! V_11 )
return - V_26 ;
V_13 = F_8 ( V_11 , 0 , V_2 -> V_27 , V_28 , V_9 , 0 ) ;
if ( ! V_13 ) {
F_9 ( V_11 ) ;
return - V_29 ;
}
V_14 = F_10 ( V_13 ) ;
memcpy ( V_14 , V_2 , V_9 ) ;
F_11 ( V_11 ) . V_30 = V_18 ;
if ( V_18 )
return F_12 ( V_16 -> V_24 , V_11 , V_4 , V_18 ,
V_6 ) ;
return F_13 ( V_16 -> V_24 , V_11 , V_4 , ! ( V_6 & V_31 ) ) ;
}
int F_14 ( struct V_1 * V_2 , T_2 V_4 , T_2 V_5 ,
T_3 V_6 )
{
return F_1 ( V_2 , V_2 -> V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_15 ( struct V_10 * V_11 )
{
struct V_7 * V_32 , * V_33 = NULL ;
struct V_15 * V_16 = & V_17 ;
struct V_1 * V_2 = F_10 ( F_16 ( V_11 ) ) ;
struct V_34 * V_35 = & F_11 ( V_11 ) ;
int V_36 = - V_23 ;
F_2 ( & V_16 -> V_20 -> V_21 ) ;
F_3 (i, &dev->cbdev->queue_list, callback_entry) {
if ( F_4 ( & V_32 -> V_22 . V_22 , & V_2 -> V_22 ) ) {
F_17 ( & V_32 -> V_37 ) ;
V_33 = V_32 ;
break;
}
}
F_5 ( & V_16 -> V_20 -> V_21 ) ;
if ( V_33 != NULL ) {
V_33 -> V_38 ( V_2 , V_35 ) ;
F_9 ( V_11 ) ;
F_18 ( V_33 ) ;
V_36 = 0 ;
}
return V_36 ;
}
static void F_19 ( struct V_10 * V_39 )
{
struct V_12 * V_13 ;
struct V_10 * V_11 ;
int V_3 , V_36 ;
V_11 = F_20 ( V_39 ) ;
if ( V_11 -> V_3 >= V_40 ) {
V_13 = F_16 ( V_11 ) ;
V_3 = F_21 ( V_13 ) ;
if ( V_3 < ( int ) sizeof( struct V_1 ) ||
V_11 -> V_3 < V_13 -> F_21 ||
V_3 > V_41 ) {
F_9 ( V_11 ) ;
return;
}
V_36 = F_15 ( V_11 ) ;
if ( V_36 < 0 )
F_9 ( V_11 ) ;
}
}
int F_22 ( struct V_42 * V_22 , const char * V_43 ,
void (* V_38)( struct V_1 * ,
struct V_34 * ) )
{
int V_36 ;
struct V_15 * V_16 = & V_17 ;
if ( ! V_44 )
return - V_45 ;
V_36 = F_23 ( V_16 -> V_20 , V_43 , V_22 , V_38 ) ;
if ( V_36 )
return V_36 ;
return 0 ;
}
void F_24 ( struct V_42 * V_22 )
{
struct V_15 * V_16 = & V_17 ;
F_25 ( V_16 -> V_20 , V_22 ) ;
}
static int F_26 ( struct V_46 * V_47 , void * V_48 )
{
struct V_49 * V_16 = V_17 . V_20 ;
struct V_7 * V_33 ;
F_27 ( V_47 , L_1 ) ;
F_2 ( & V_16 -> V_21 ) ;
F_3 (cbq, &dev->queue_list, callback_entry) {
F_27 ( V_47 , L_2 ,
V_33 -> V_22 . V_43 ,
V_33 -> V_22 . V_22 . V_50 ,
V_33 -> V_22 . V_22 . V_51 ) ;
}
F_5 ( & V_16 -> V_21 ) ;
return 0 ;
}
static int F_28 ( struct V_52 * V_52 , struct V_53 * V_53 )
{
return F_29 ( V_53 , F_26 , NULL ) ;
}
static int F_30 ( void )
{
struct V_15 * V_16 = & V_17 ;
struct V_54 V_55 = {
. V_56 = V_57 + 0xf ,
. V_58 = V_16 -> V_58 ,
} ;
V_16 -> V_24 = F_31 ( & V_59 , V_60 , & V_55 ) ;
if ( ! V_16 -> V_24 )
return - V_61 ;
V_16 -> V_20 = F_32 ( L_3 , V_16 -> V_24 ) ;
if ( ! V_16 -> V_20 ) {
F_33 ( V_16 -> V_24 ) ;
return - V_62 ;
}
V_44 = 1 ;
F_34 ( L_4 , V_63 , V_59 . V_64 , & V_65 ) ;
return 0 ;
}
static void F_35 ( void )
{
struct V_15 * V_16 = & V_17 ;
V_44 = 0 ;
F_36 ( L_4 , V_59 . V_64 ) ;
F_37 ( V_16 -> V_20 ) ;
F_33 ( V_16 -> V_24 ) ;
}
