static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
int V_12 , V_13 = ( V_4 -> V_14 & V_15 ) ;
unsigned V_16 ;
V_11 = F_3 ( V_6 -> V_17 , V_2 -> V_18 , V_19 ) ;
if ( F_4 ( V_11 == NULL ) )
return - V_20 ;
V_11 -> V_21 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_18 ; V_16 ++ ) {
struct V_22 * V_22 = V_2 -> V_23 [ V_16 ] ;
if ( ! V_22 )
V_22 = V_2 -> V_24 ;
V_11 -> V_23 [ V_11 -> V_21 ++ ] = V_22 ;
}
V_6 -> V_11 = V_11 ;
V_11 -> V_25 = 1 ;
V_11 -> type = ( V_13 ) ? V_26 : V_19 ;
V_12 = F_5 ( V_11 , V_8 -> V_27 ) ;
if ( V_12 )
F_6 (KERN_ERR TTM_PFX L_1 ) ;
return V_12 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
if ( V_6 -> V_11 ) {
if ( V_6 -> V_11 -> V_28 )
return F_8 ( V_6 -> V_11 ) ;
F_9 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
if ( V_6 -> V_11 )
F_7 ( V_2 ) ;
F_11 ( V_2 ) ;
F_12 ( V_6 ) ;
}
struct V_1 * F_13 ( struct V_29 * V_30 ,
struct V_31 * V_17 ,
unsigned long V_32 , T_1 V_33 ,
struct V_22 * V_24 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( sizeof( * V_6 ) , V_34 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_11 = NULL ;
V_6 -> V_17 = V_17 ;
V_6 -> V_2 . V_35 = & V_36 ;
if ( F_15 ( & V_6 -> V_2 , V_30 , V_32 , V_33 , V_24 ) ) {
return NULL ;
}
return & V_6 -> V_2 ;
}
int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 != V_38 )
return 0 ;
return F_17 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
}
