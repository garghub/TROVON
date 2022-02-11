static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 (ofdma, &of_dma_list, of_dma_controllers)
if ( ( V_4 -> V_5 == V_3 -> V_6 ) &&
( V_4 -> V_7 == V_3 -> V_8 ) )
return V_4 ;
F_3 ( L_1 , V_9 ,
V_3 -> V_6 -> V_10 ) ;
return NULL ;
}
void F_4 ( struct V_11 * V_6 )
{
struct V_1 * V_4 ;
F_5 ( & V_12 ) ;
F_2 (ofdma, &of_dma_list, of_dma_controllers)
if ( V_4 -> V_5 == V_6 ) {
F_6 ( & V_4 -> V_13 ) ;
F_7 ( V_4 ) ;
break;
}
F_8 ( & V_12 ) ;
}
static int F_9 ( struct V_11 * V_6 , const char * V_14 ,
int V_15 , struct V_2 * V_3 )
{
const char * V_16 ;
if ( F_10 ( V_6 , L_2 , V_15 , & V_16 ) )
return - V_17 ;
if ( strcmp ( V_14 , V_16 ) )
return - V_17 ;
if ( F_11 ( V_6 , L_3 , L_4 , V_15 ,
V_3 ) )
return - V_17 ;
return 0 ;
}
struct V_18 * F_12 ( struct V_11 * V_6 ,
const char * V_14 )
{
struct V_2 V_3 ;
struct V_1 * V_4 ;
struct V_18 * V_19 ;
int V_20 , V_21 ;
if ( ! V_6 || ! V_14 ) {
F_13 ( L_5 , V_9 ) ;
return NULL ;
}
V_20 = F_14 ( V_6 , L_2 ) ;
if ( V_20 < 0 ) {
F_13 ( L_6 , V_9 ) ;
return NULL ;
}
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
if ( F_9 ( V_6 , V_14 , V_21 , & V_3 ) )
continue;
F_5 ( & V_12 ) ;
V_4 = F_1 ( & V_3 ) ;
if ( V_4 )
V_19 = V_4 -> V_22 ( & V_3 , V_4 ) ;
else
V_19 = NULL ;
F_8 ( & V_12 ) ;
F_15 ( V_3 . V_6 ) ;
if ( V_19 )
return V_19 ;
}
return NULL ;
}
struct V_18 * F_16 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
int V_20 = V_3 -> V_8 ;
struct V_23 * V_24 = V_4 -> V_25 ;
if ( ! V_24 || ! V_24 -> V_26 )
return NULL ;
if ( V_20 != 1 )
return NULL ;
return F_17 ( V_24 -> V_27 , V_24 -> V_26 ,
& V_3 -> args [ 0 ] ) ;
}
