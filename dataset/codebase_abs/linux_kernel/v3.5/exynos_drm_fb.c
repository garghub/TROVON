static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
F_3 ( L_1 , __FILE__ ) ;
F_4 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < F_5 ( V_4 -> V_6 ) ; V_5 ++ ) {
struct V_7 * V_8 ;
if ( V_4 -> V_6 [ V_5 ] == NULL )
continue;
V_8 = & V_4 -> V_6 [ V_5 ] -> V_9 ;
F_6 ( V_8 ) ;
}
F_7 ( V_4 ) ;
V_4 = NULL ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
return F_9 ( V_11 ,
& V_4 -> V_6 [ 0 ] -> V_9 , V_12 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_10 * V_11 , unsigned V_13 ,
unsigned V_14 , struct V_15 * V_16 ,
unsigned V_17 )
{
F_3 ( L_1 , __FILE__ ) ;
return 0 ;
}
struct V_1 *
F_11 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 ;
int V_22 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 ) {
F_13 ( L_2 ) ;
return F_14 ( - V_24 ) ;
}
V_22 = F_15 ( V_19 , & V_4 -> V_2 , & V_25 ) ;
if ( V_22 ) {
F_13 ( L_3 ) ;
return F_14 ( V_22 ) ;
}
F_16 ( & V_4 -> V_2 , V_21 ) ;
V_4 -> V_6 [ 0 ] = F_17 ( V_8 ) ;
return & V_4 -> V_2 ;
}
static struct V_1 *
F_18 ( struct V_18 * V_19 , struct V_10 * V_11 ,
struct V_20 * V_21 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_26 ;
int V_5 ;
F_3 ( L_1 , __FILE__ ) ;
V_8 = F_19 ( V_19 , V_11 , V_21 -> V_27 [ 0 ] ) ;
if ( ! V_8 ) {
F_13 ( L_4 ) ;
return F_14 ( - V_28 ) ;
}
V_2 = F_11 ( V_19 , V_21 , V_8 ) ;
if ( F_20 ( V_2 ) ) {
F_6 ( V_8 ) ;
return V_2 ;
}
V_4 = F_2 ( V_2 ) ;
V_26 = F_21 ( V_2 -> V_29 ) ;
for ( V_5 = 1 ; V_5 < V_26 ; V_5 ++ ) {
V_8 = F_19 ( V_19 , V_11 ,
V_21 -> V_27 [ V_5 ] ) ;
if ( ! V_8 ) {
F_13 ( L_4 ) ;
F_1 ( V_2 ) ;
return F_14 ( - V_28 ) ;
}
V_4 -> V_6 [ V_5 ] = F_17 ( V_8 ) ;
}
return V_2 ;
}
struct V_30 * F_22 ( struct V_1 * V_2 ,
int V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_30 * V_32 ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_31 >= V_33 )
return NULL ;
V_32 = V_4 -> V_6 [ V_31 ] -> V_32 ;
if ( ! V_32 )
return NULL ;
F_3 ( L_5 ,
( unsigned long ) V_32 -> V_34 ,
( unsigned long ) V_32 -> V_35 ) ;
return V_32 ;
}
static void F_23 ( struct V_18 * V_19 )
{
struct V_36 * V_37 = V_19 -> V_38 ;
struct V_39 * V_40 = V_37 -> V_40 ;
if ( V_40 )
F_24 ( V_40 ) ;
}
void F_25 ( struct V_18 * V_19 )
{
V_19 -> V_41 . V_42 = 0 ;
V_19 -> V_41 . V_43 = 0 ;
V_19 -> V_41 . V_44 = 4096 ;
V_19 -> V_41 . V_45 = 4096 ;
V_19 -> V_41 . V_46 = & V_47 ;
}
