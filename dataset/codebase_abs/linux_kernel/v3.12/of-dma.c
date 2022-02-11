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
if ( ! V_6 || ! V_12 ) {
F_13 ( L_5 , V_7 ) ;
return NULL ;
}
V_18 = F_14 ( V_6 , L_2 ) ;
if ( V_18 < 0 ) {
F_13 ( L_6 ,
V_7 , V_6 -> V_8 ) ;
return NULL ;
}
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
if ( F_9 ( V_6 , V_12 , V_19 , & V_3 ) )
continue;
F_5 ( & V_10 ) ;
V_4 = F_1 ( & V_3 ) ;
if ( V_4 )
V_17 = V_4 -> V_20 ( & V_3 , V_4 ) ;
else
V_17 = NULL ;
F_8 ( & V_10 ) ;
F_15 ( V_3 . V_6 ) ;
if ( V_17 )
return V_17 ;
}
return NULL ;
}
struct V_16 * F_16 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
int V_18 = V_3 -> V_21 ;
struct V_22 * V_23 = V_4 -> V_24 ;
if ( ! V_23 || ! V_23 -> V_25 )
return NULL ;
if ( V_18 != 1 )
return NULL ;
return F_17 ( V_23 -> V_26 , V_23 -> V_25 ,
& V_3 -> args [ 0 ] ) ;
}
