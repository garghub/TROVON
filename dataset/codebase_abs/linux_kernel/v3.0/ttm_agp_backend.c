static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , struct V_4 * * V_5 ,
struct V_4 * V_6 ,
T_1 * V_7 )
{
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
struct V_4 * * V_10 , * * V_11 = V_5 + V_3 ;
struct V_12 * V_13 ;
V_13 = F_3 ( V_9 -> V_14 , V_3 , V_15 ) ;
if ( F_4 ( V_13 == NULL ) )
return - V_16 ;
V_13 -> V_17 = 0 ;
for ( V_10 = V_5 ; V_10 < V_11 ; ++ V_10 ) {
struct V_4 * V_4 = * V_10 ;
if ( ! V_4 )
V_4 = V_6 ;
V_13 -> V_5 [ V_13 -> V_17 ++ ] = V_4 ;
}
V_9 -> V_13 = V_13 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_12 * V_13 = V_9 -> V_13 ;
int V_23 = ( V_19 -> V_24 & V_25 ) ;
int V_26 ;
V_13 -> V_27 = 1 ;
V_13 -> type = ( V_23 ) ? V_28 : V_15 ;
V_26 = F_6 ( V_13 , V_21 -> V_29 ) ;
if ( V_26 )
F_7 (KERN_ERR TTM_PFX L_1 ) ;
return V_26 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
if ( V_9 -> V_13 -> V_30 )
return F_9 ( V_9 -> V_13 ) ;
else
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
struct V_12 * V_13 = V_9 -> V_13 ;
if ( V_13 ) {
F_8 ( V_2 ) ;
F_11 ( V_13 ) ;
}
V_9 -> V_13 = NULL ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
if ( V_9 -> V_13 )
F_10 ( V_2 ) ;
F_13 ( V_9 ) ;
}
struct V_1 * F_14 ( struct V_31 * V_32 ,
struct V_33 * V_14 )
{
struct V_8 * V_9 ;
V_9 = F_15 ( sizeof( * V_9 ) , V_34 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_13 = NULL ;
V_9 -> V_14 = V_14 ;
V_9 -> V_2 . V_35 = & V_36 ;
V_9 -> V_2 . V_32 = V_32 ;
return & V_9 -> V_2 ;
}
