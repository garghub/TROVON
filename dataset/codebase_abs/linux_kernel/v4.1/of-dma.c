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
void F_4 ( struct V_9 * V_6 )
{
struct V_1 * V_4 ;
F_5 ( & V_10 ) ;
F_2 (ofdma, &of_dma_list, of_dma_controllers)
if ( V_4 -> V_5 == V_6 ) {
F_6 ( & V_4 -> V_11 ) ;
F_7 ( V_4 ) ;
break;
}
F_8 ( & V_10 ) ;
}
static int F_9 ( struct V_9 * V_6 , const char * V_12 ,
int V_13 , struct V_2 * V_3 )
{
const char * V_14 ;
if ( F_10 ( V_6 , L_2 , V_13 , & V_14 ) )
return - V_15 ;
if ( strcmp ( V_12 , V_14 ) )
return - V_15 ;
if ( F_11 ( V_6 , L_3 , L_4 , V_13 ,
V_3 ) )
return - V_15 ;
return 0 ;
}
struct V_16 * F_12 ( struct V_9 * V_6 ,
const char * V_12 )
{
struct V_2 V_3 ;
struct V_1 * V_4 ;
struct V_16 * V_17 ;
int V_18 , V_19 ;
int V_20 = - V_15 ;
if ( ! V_6 || ! V_12 ) {
F_13 ( L_5 , V_7 ) ;
return F_14 ( - V_15 ) ;
}
if ( ! F_15 ( V_6 , L_3 , NULL ) )
return F_14 ( - V_15 ) ;
V_18 = F_16 ( V_6 , L_2 ) ;
if ( V_18 < 0 ) {
F_13 ( L_6 ,
V_7 , V_6 -> V_8 ) ;
return F_14 ( - V_15 ) ;
}
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
if ( F_9 ( V_6 , V_12 , V_19 , & V_3 ) )
continue;
F_5 ( & V_10 ) ;
V_4 = F_1 ( & V_3 ) ;
if ( V_4 ) {
V_17 = V_4 -> V_21 ( & V_3 , V_4 ) ;
} else {
V_20 = - V_22 ;
V_17 = NULL ;
}
F_8 ( & V_10 ) ;
F_17 ( V_3 . V_6 ) ;
if ( V_17 )
return V_17 ;
}
return F_14 ( V_20 ) ;
}
struct V_16 * F_18 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
int V_18 = V_3 -> V_23 ;
struct V_24 * V_25 = V_4 -> V_26 ;
if ( ! V_25 || ! V_25 -> V_27 )
return NULL ;
if ( V_18 != 1 )
return NULL ;
return F_19 ( V_25 -> V_28 , V_25 -> V_27 ,
& V_3 -> args [ 0 ] ) ;
}
struct V_16 * F_20 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_29 * V_30 = V_4 -> V_26 ;
struct V_16 * V_17 , * V_31 = NULL ;
if ( ! V_30 || V_3 -> V_23 != 1 )
return NULL ;
F_2 (chan, &dev->channels, device_node)
if ( V_17 -> V_32 == V_3 -> args [ 0 ] ) {
V_31 = V_17 ;
break;
}
if ( ! V_31 )
return NULL ;
return F_21 ( V_31 ) ;
}
