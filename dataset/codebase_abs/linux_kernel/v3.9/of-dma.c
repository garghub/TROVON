static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
if ( F_3 ( & V_6 ) ) {
F_4 ( & V_5 ) ;
return NULL ;
}
F_5 (ofdma, &of_dma_list, of_dma_controllers)
if ( ( V_4 -> V_7 == V_3 -> V_8 ) &&
( V_4 -> V_9 == V_3 -> V_10 ) ) {
V_4 -> V_11 ++ ;
F_4 ( & V_5 ) ;
return V_4 ;
}
F_4 ( & V_5 ) ;
F_6 ( L_1 , V_12 ,
V_3 -> V_8 -> V_13 ) ;
return NULL ;
}
static void F_7 ( struct V_1 * V_4 )
{
F_2 ( & V_5 ) ;
V_4 -> V_11 -- ;
F_4 ( & V_5 ) ;
}
int F_8 ( struct V_14 * V_8 )
{
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
if ( F_3 ( & V_6 ) ) {
F_4 ( & V_5 ) ;
return - V_15 ;
}
F_5 (ofdma, &of_dma_list, of_dma_controllers)
if ( V_4 -> V_7 == V_8 ) {
if ( V_4 -> V_11 ) {
F_4 ( & V_5 ) ;
return - V_16 ;
}
F_9 ( & V_4 -> V_17 ) ;
F_4 ( & V_5 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
F_4 ( & V_5 ) ;
return - V_15 ;
}
static int F_11 ( struct V_14 * V_8 , char * V_18 , int V_19 ,
struct V_2 * V_3 )
{
const char * V_20 ;
if ( F_12 ( V_8 , L_2 , V_19 , & V_20 ) )
return - V_15 ;
if ( strcmp ( V_18 , V_20 ) )
return - V_15 ;
if ( F_13 ( V_8 , L_3 , L_4 , V_19 ,
V_3 ) )
return - V_15 ;
return 0 ;
}
struct V_21 * F_14 ( struct V_14 * V_8 ,
char * V_18 )
{
struct V_2 V_3 ;
struct V_1 * V_4 ;
struct V_21 * V_22 ;
int V_23 , V_24 ;
if ( ! V_8 || ! V_18 ) {
F_15 ( L_5 , V_12 ) ;
return NULL ;
}
V_23 = F_16 ( V_8 , L_2 ) ;
if ( V_23 < 0 ) {
F_15 ( L_6 , V_12 ) ;
return NULL ;
}
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
if ( F_11 ( V_8 , V_18 , V_24 , & V_3 ) )
continue;
V_4 = F_1 ( & V_3 ) ;
if ( ! V_4 )
continue;
V_22 = V_4 -> V_25 ( & V_3 , V_4 ) ;
F_7 ( V_4 ) ;
F_17 ( V_3 . V_8 ) ;
if ( V_22 )
return V_22 ;
}
return NULL ;
}
struct V_21 * F_18 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
int V_23 = V_3 -> V_10 ;
struct V_26 * V_27 = V_4 -> V_28 ;
if ( ! V_27 || ! V_27 -> V_29 )
return NULL ;
if ( V_23 != 1 )
return NULL ;
return F_19 ( V_27 -> V_30 , V_27 -> V_29 ,
& V_3 -> args [ 0 ] ) ;
}
