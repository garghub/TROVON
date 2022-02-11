static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
F_4 ( V_2 ) ;
F_5 ( V_4 ) ;
V_4 = NULL ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
return F_7 ( V_6 ,
& V_4 -> V_8 [ 0 ] -> V_9 , V_7 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_5 * V_6 , unsigned V_10 ,
unsigned V_11 , struct V_12 * V_13 ,
unsigned V_14 )
{
F_3 ( L_1 , __FILE__ ) ;
return 0 ;
}
struct V_1 *
F_9 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_3 * V_4 ;
int V_21 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 ) {
F_11 ( L_2 ) ;
return F_12 ( - V_23 ) ;
}
V_21 = F_13 ( V_16 , & V_4 -> V_2 , & V_24 ) ;
if ( V_21 ) {
F_11 ( L_3 ) ;
return F_12 ( V_21 ) ;
}
F_14 ( & V_4 -> V_2 , V_18 ) ;
V_4 -> V_8 [ 0 ] = F_15 ( V_20 ) ;
return & V_4 -> V_2 ;
}
static struct V_1 *
F_16 ( struct V_15 * V_16 , struct V_5 * V_6 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_25 ;
int V_26 ;
F_3 ( L_1 , __FILE__ ) ;
V_20 = F_17 ( V_16 , V_6 , V_18 -> V_27 [ 0 ] ) ;
if ( ! V_20 ) {
F_11 ( L_4 ) ;
return F_12 ( - V_28 ) ;
}
F_18 ( V_20 ) ;
V_2 = F_9 ( V_16 , V_18 , V_20 ) ;
if ( F_19 ( V_2 ) )
return V_2 ;
V_4 = F_2 ( V_2 ) ;
V_25 = F_20 ( V_2 -> V_29 ) ;
for ( V_26 = 1 ; V_26 < V_25 ; V_26 ++ ) {
V_20 = F_17 ( V_16 , V_6 ,
V_18 -> V_27 [ V_26 ] ) ;
if ( ! V_20 ) {
F_11 ( L_4 ) ;
F_1 ( V_2 ) ;
return F_12 ( - V_28 ) ;
}
F_18 ( V_20 ) ;
V_4 -> V_8 [ V_26 ] = F_15 ( V_20 ) ;
}
return V_2 ;
}
struct V_30 * F_21 ( struct V_1 * V_2 ,
int V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_30 * V_32 ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_31 >= V_33 )
return NULL ;
V_32 = V_4 -> V_8 [ V_31 ] -> V_32 ;
if ( ! V_32 )
return NULL ;
F_3 ( L_5 ,
( unsigned long ) V_32 -> V_34 ,
( unsigned long ) V_32 -> V_35 ) ;
return V_32 ;
}
static void F_22 ( struct V_15 * V_16 )
{
struct V_36 * V_37 = V_16 -> V_38 ;
struct V_39 * V_40 = V_37 -> V_40 ;
if ( V_40 )
F_23 ( V_40 ) ;
}
void F_24 ( struct V_15 * V_16 )
{
V_16 -> V_41 . V_42 = 0 ;
V_16 -> V_41 . V_43 = 0 ;
V_16 -> V_41 . V_44 = 4096 ;
V_16 -> V_41 . V_45 = 4096 ;
V_16 -> V_41 . V_46 = & V_47 ;
}
