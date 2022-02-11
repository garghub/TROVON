static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 (ofdma, &of_dma_list, of_dma_controllers)
if ( V_4 -> V_5 == V_3 -> V_6 )
return V_4 ;
F_3 ( L_1 , V_7 ,
V_3 -> V_6 -> V_8 ) ;
return NULL ;
}
static struct V_9 * F_4 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_9 * V_10 ;
struct V_1 * V_11 ;
struct V_2 V_12 ;
void * V_13 ;
memcpy ( & V_12 , V_3 , sizeof( V_12 ) ) ;
V_13 = V_4 -> V_14 ( & V_12 , V_4 ) ;
if ( F_5 ( V_13 ) )
return NULL ;
V_11 = F_1 ( & V_12 ) ;
if ( ! V_11 )
return NULL ;
V_10 = V_11 -> V_15 ( & V_12 , V_11 ) ;
if ( V_10 ) {
V_10 -> V_16 = V_4 -> V_17 ;
V_10 -> V_13 = V_13 ;
} else {
V_4 -> V_17 -> V_18 ( V_4 -> V_17 -> V_19 ,
V_13 ) ;
}
F_6 ( V_12 . V_6 ) ;
return V_10 ;
}
void F_7 ( struct V_20 * V_6 )
{
struct V_1 * V_4 ;
F_8 ( & V_21 ) ;
F_2 (ofdma, &of_dma_list, of_dma_controllers)
if ( V_4 -> V_5 == V_6 ) {
F_9 ( & V_4 -> V_22 ) ;
F_10 ( V_4 ) ;
break;
}
F_11 ( & V_21 ) ;
}
int F_12 ( struct V_20 * V_6 ,
void * (* V_14)
( struct V_2 * , struct V_1 * ) ,
struct V_17 * V_17 )
{
struct V_1 * V_4 ;
if ( ! V_6 || ! V_14 || ! V_17 ) {
F_13 ( L_2 , V_7 ) ;
return - V_23 ;
}
V_4 = F_14 ( sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_4 -> V_5 = V_6 ;
V_4 -> V_15 = F_4 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_17 = V_17 ;
F_8 ( & V_21 ) ;
F_15 ( & V_4 -> V_22 , & V_26 ) ;
F_11 ( & V_21 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_6 , const char * V_27 ,
int V_28 , struct V_2 * V_3 )
{
const char * V_29 ;
if ( F_17 ( V_6 , L_3 , V_28 , & V_29 ) )
return - V_30 ;
if ( strcmp ( V_27 , V_29 ) )
return - V_30 ;
if ( F_18 ( V_6 , L_4 , L_5 , V_28 ,
V_3 ) )
return - V_30 ;
return 0 ;
}
struct V_9 * F_19 ( struct V_20 * V_6 ,
const char * V_27 )
{
struct V_2 V_3 ;
struct V_1 * V_4 ;
struct V_9 * V_10 ;
int V_31 , V_32 , V_33 ;
int V_34 = - V_30 ;
static T_1 V_35 ;
if ( ! V_6 || ! V_27 ) {
F_13 ( L_2 , V_7 ) ;
return F_20 ( - V_30 ) ;
}
if ( ! F_21 ( V_6 , L_4 , NULL ) )
return F_20 ( - V_30 ) ;
V_31 = F_22 ( V_6 , L_3 ) ;
if ( V_31 < 0 ) {
F_13 ( L_6 ,
V_7 , V_6 -> V_8 ) ;
return F_20 ( - V_30 ) ;
}
V_33 = F_23 ( & V_35 ) ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
if ( F_16 ( V_6 , V_27 ,
( V_32 + V_33 ) % V_31 ,
& V_3 ) )
continue;
F_8 ( & V_21 ) ;
V_4 = F_1 ( & V_3 ) ;
if ( V_4 ) {
V_10 = V_4 -> V_15 ( & V_3 , V_4 ) ;
} else {
V_34 = - V_36 ;
V_10 = NULL ;
}
F_11 ( & V_21 ) ;
F_6 ( V_3 . V_6 ) ;
if ( V_10 )
return V_10 ;
}
return F_20 ( V_34 ) ;
}
struct V_9 * F_24 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
int V_31 = V_3 -> V_37 ;
struct V_38 * V_39 = V_4 -> V_40 ;
if ( ! V_39 || ! V_39 -> V_41 )
return NULL ;
if ( V_31 != 1 )
return NULL ;
return F_25 ( V_39 -> V_42 , V_39 -> V_41 ,
& V_3 -> args [ 0 ] ) ;
}
struct V_9 * F_26 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_43 * V_19 = V_4 -> V_40 ;
struct V_9 * V_10 , * V_44 = NULL ;
if ( ! V_19 || V_3 -> V_37 != 1 )
return NULL ;
F_2 (chan, &dev->channels, device_node)
if ( V_10 -> V_45 == V_3 -> args [ 0 ] ) {
V_44 = V_10 ;
break;
}
if ( ! V_44 )
return NULL ;
return F_27 ( V_44 ) ;
}
