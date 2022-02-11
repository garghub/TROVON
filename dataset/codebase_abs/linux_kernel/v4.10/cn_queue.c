static struct V_1 *
F_1 ( struct V_2 * V_3 , const char * V_4 ,
struct V_5 * V_6 ,
void (* F_2)( struct V_7 * ,
struct V_8 * ) )
{
struct V_1 * V_9 ;
V_9 = F_3 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 ) {
F_4 ( L_1 ) ;
return NULL ;
}
F_5 ( & V_9 -> V_11 , 1 ) ;
F_6 ( & V_3 -> V_11 ) ;
V_9 -> V_12 = V_3 ;
snprintf ( V_9 -> V_6 . V_4 , sizeof( V_9 -> V_6 . V_4 ) , L_2 , V_4 ) ;
memcpy ( & V_9 -> V_6 . V_6 , V_6 , sizeof( struct V_5 ) ) ;
V_9 -> F_2 = F_2 ;
return V_9 ;
}
void F_7 ( struct V_1 * V_9 )
{
if ( ! F_8 ( & V_9 -> V_11 ) )
return;
F_9 ( & V_9 -> V_12 -> V_11 ) ;
F_10 ( V_9 ) ;
}
int F_11 ( struct V_5 * V_13 , struct V_5 * V_14 )
{
return ( ( V_13 -> V_15 == V_14 -> V_15 ) && ( V_13 -> V_16 == V_14 -> V_16 ) ) ;
}
int F_12 ( struct V_2 * V_3 , const char * V_4 ,
struct V_5 * V_6 ,
void (* F_2)( struct V_7 * ,
struct V_8 * ) )
{
struct V_1 * V_9 , * V_17 ;
int V_18 = 0 ;
V_9 = F_1 ( V_3 , V_4 , V_6 , F_2 ) ;
if ( ! V_9 )
return - V_19 ;
F_13 ( & V_3 -> V_20 ) ;
F_14 (__cbq, &dev->queue_list, callback_entry) {
if ( F_11 ( & V_17 -> V_6 . V_6 , V_6 ) ) {
V_18 = 1 ;
break;
}
}
if ( ! V_18 )
F_15 ( & V_9 -> V_21 , & V_3 -> V_22 ) ;
F_16 ( & V_3 -> V_20 ) ;
if ( V_18 ) {
F_7 ( V_9 ) ;
return - V_23 ;
}
V_9 -> V_24 = 0 ;
V_9 -> V_25 = V_9 -> V_6 . V_6 . V_15 ;
return 0 ;
}
void F_17 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_9 , * V_26 ;
int V_18 = 0 ;
F_13 ( & V_3 -> V_20 ) ;
F_18 (cbq, n, &dev->queue_list, callback_entry) {
if ( F_11 ( & V_9 -> V_6 . V_6 , V_6 ) ) {
F_19 ( & V_9 -> V_21 ) ;
V_18 = 1 ;
break;
}
}
F_16 ( & V_3 -> V_20 ) ;
if ( V_18 )
F_7 ( V_9 ) ;
}
struct V_2 * F_20 ( const char * V_4 , struct V_27 * V_28 )
{
struct V_2 * V_3 ;
V_3 = F_3 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 )
return NULL ;
snprintf ( V_3 -> V_4 , sizeof( V_3 -> V_4 ) , L_2 , V_4 ) ;
F_5 ( & V_3 -> V_11 , 0 ) ;
F_21 ( & V_3 -> V_22 ) ;
F_22 ( & V_3 -> V_20 ) ;
V_3 -> V_28 = V_28 ;
return V_3 ;
}
void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_9 , * V_26 ;
F_13 ( & V_3 -> V_20 ) ;
F_18 (cbq, n, &dev->queue_list, callback_entry)
F_19 ( & V_9 -> V_21 ) ;
F_16 ( & V_3 -> V_20 ) ;
while ( F_24 ( & V_3 -> V_11 ) ) {
F_25 ( L_3 ,
V_3 -> V_4 , F_24 ( & V_3 -> V_11 ) ) ;
F_26 ( 1000 ) ;
}
F_10 ( V_3 ) ;
V_3 = NULL ;
}
