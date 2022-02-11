static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 (ofdma, &of_dma_list, of_dma_controllers)
if ( V_4 -> V_5 == V_3 -> V_6 )
return V_4 ;
F_3 ( L_1 , V_7 ,
V_3 -> V_6 ) ;
return NULL ;
}
static struct V_8 * F_4 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_8 * V_9 ;
struct V_1 * V_10 ;
struct V_2 V_11 ;
void * V_12 ;
memcpy ( & V_11 , V_3 , sizeof( V_11 ) ) ;
V_12 = V_4 -> V_13 ( & V_11 , V_4 ) ;
if ( F_5 ( V_12 ) )
return NULL ;
V_10 = F_1 ( & V_11 ) ;
if ( ! V_10 )
return NULL ;
V_9 = V_10 -> V_14 ( & V_11 , V_10 ) ;
if ( V_9 ) {
V_9 -> V_15 = V_4 -> V_16 ;
V_9 -> V_12 = V_12 ;
} else {
V_4 -> V_16 -> V_17 ( V_4 -> V_16 -> V_18 ,
V_12 ) ;
}
F_6 ( V_11 . V_6 ) ;
return V_9 ;
}
void F_7 ( struct V_19 * V_6 )
{
struct V_1 * V_4 ;
F_8 ( & V_20 ) ;
F_2 (ofdma, &of_dma_list, of_dma_controllers)
if ( V_4 -> V_5 == V_6 ) {
F_9 ( & V_4 -> V_21 ) ;
F_10 ( V_4 ) ;
break;
}
F_11 ( & V_20 ) ;
}
int F_12 ( struct V_19 * V_6 ,
void * (* V_13)
( struct V_2 * , struct V_1 * ) ,
struct V_16 * V_16 )
{
struct V_1 * V_4 ;
if ( ! V_6 || ! V_13 || ! V_16 ) {
F_13 ( L_2 , V_7 ) ;
return - V_22 ;
}
V_4 = F_14 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_4 -> V_5 = V_6 ;
V_4 -> V_14 = F_4 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_16 = V_16 ;
F_8 ( & V_20 ) ;
F_15 ( & V_4 -> V_21 , & V_25 ) ;
F_11 ( & V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_19 * V_6 , const char * V_26 ,
int V_27 , struct V_2 * V_3 )
{
const char * V_28 ;
if ( F_17 ( V_6 , L_3 , V_27 , & V_28 ) )
return - V_29 ;
if ( strcmp ( V_26 , V_28 ) )
return - V_29 ;
if ( F_18 ( V_6 , L_4 , L_5 , V_27 ,
V_3 ) )
return - V_29 ;
return 0 ;
}
struct V_8 * F_19 ( struct V_19 * V_6 ,
const char * V_26 )
{
struct V_2 V_3 ;
struct V_1 * V_4 ;
struct V_8 * V_9 ;
int V_30 , V_31 , V_32 ;
int V_33 = - V_29 ;
static T_1 V_34 ;
if ( ! V_6 || ! V_26 ) {
F_13 ( L_2 , V_7 ) ;
return F_20 ( - V_29 ) ;
}
if ( ! F_21 ( V_6 , L_4 , NULL ) )
return F_20 ( - V_29 ) ;
V_30 = F_22 ( V_6 , L_3 ) ;
if ( V_30 < 0 ) {
F_13 ( L_6 ,
V_7 , V_6 ) ;
return F_20 ( - V_29 ) ;
}
V_32 = F_23 ( & V_34 ) ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
if ( F_16 ( V_6 , V_26 ,
( V_31 + V_32 ) % V_30 ,
& V_3 ) )
continue;
F_8 ( & V_20 ) ;
V_4 = F_1 ( & V_3 ) ;
if ( V_4 ) {
V_9 = V_4 -> V_14 ( & V_3 , V_4 ) ;
} else {
V_33 = - V_35 ;
V_9 = NULL ;
}
F_11 ( & V_20 ) ;
F_6 ( V_3 . V_6 ) ;
if ( V_9 )
return V_9 ;
}
return F_20 ( V_33 ) ;
}
struct V_8 * F_24 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
int V_30 = V_3 -> V_36 ;
struct V_37 * V_38 = V_4 -> V_39 ;
if ( ! V_38 || ! V_38 -> V_40 )
return NULL ;
if ( V_30 != 1 )
return NULL ;
return F_25 ( V_38 -> V_41 , V_38 -> V_40 ,
& V_3 -> args [ 0 ] ) ;
}
struct V_8 * F_26 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_42 * V_18 = V_4 -> V_39 ;
struct V_8 * V_9 , * V_43 = NULL ;
if ( ! V_18 || V_3 -> V_36 != 1 )
return NULL ;
F_2 (chan, &dev->channels, device_node)
if ( V_9 -> V_44 == V_3 -> args [ 0 ] ) {
V_43 = V_9 ;
break;
}
if ( ! V_43 )
return NULL ;
return F_27 ( V_43 ) ;
}
