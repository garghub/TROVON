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
void F_11 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_19 = V_18 ;
}
unsigned int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_19 ;
}
struct V_1 *
F_13 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 ;
int V_24 ;
V_4 = F_14 ( sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 ) {
F_15 ( L_2 ) ;
return F_16 ( - V_26 ) ;
}
V_24 = F_17 ( V_21 , & V_4 -> V_2 , & V_27 ) ;
if ( V_24 ) {
F_15 ( L_3 ) ;
return F_16 ( V_24 ) ;
}
F_18 ( & V_4 -> V_2 , V_23 ) ;
V_4 -> V_6 [ 0 ] = F_19 ( V_8 ) ;
return & V_4 -> V_2 ;
}
static T_1 F_20 ( struct V_22 * V_23 )
{
unsigned int V_18 = 0 ;
if ( V_23 -> V_28 != V_29 )
return F_21 ( V_23 -> V_28 ) ;
while ( V_18 != V_30 ) {
if ( ! V_23 -> V_31 [ V_18 ] )
break;
V_18 ++ ;
}
if ( V_18 == 2 ) {
if ( V_23 -> V_32 [ 1 ] &&
V_23 -> V_31 [ 0 ] == V_23 -> V_31 [ 1 ] )
V_18 = 1 ;
}
return V_18 ;
}
static struct V_1 *
F_22 ( struct V_20 * V_21 , struct V_10 * V_11 ,
struct V_22 * V_23 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_5 ;
F_3 ( L_1 , __FILE__ ) ;
V_8 = F_23 ( V_21 , V_11 , V_23 -> V_31 [ 0 ] ) ;
if ( ! V_8 ) {
F_15 ( L_4 ) ;
return F_16 ( - V_33 ) ;
}
V_2 = F_13 ( V_21 , V_23 , V_8 ) ;
if ( F_24 ( V_2 ) ) {
F_6 ( V_8 ) ;
return V_2 ;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_19 = F_20 ( V_23 ) ;
F_3 ( L_5 , V_4 -> V_19 ) ;
for ( V_5 = 1 ; V_5 < V_4 -> V_19 ; V_5 ++ ) {
V_8 = F_23 ( V_21 , V_11 ,
V_23 -> V_31 [ V_5 ] ) ;
if ( ! V_8 ) {
F_15 ( L_4 ) ;
F_1 ( V_2 ) ;
return F_16 ( - V_33 ) ;
}
V_4 -> V_6 [ V_5 ] = F_19 ( V_8 ) ;
}
return V_2 ;
}
struct V_34 * F_25 ( struct V_1 * V_2 ,
int V_35 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_34 * V_36 ;
F_3 ( L_1 , __FILE__ ) ;
if ( V_35 >= V_30 )
return NULL ;
V_36 = V_4 -> V_6 [ V_35 ] -> V_36 ;
if ( ! V_36 )
return NULL ;
F_3 ( L_6 ,
( unsigned long ) V_36 -> V_37 ,
( unsigned long ) V_36 -> V_38 ) ;
return V_36 ;
}
static void F_26 ( struct V_20 * V_21 )
{
struct V_39 * V_40 = V_21 -> V_41 ;
struct V_42 * V_43 = V_40 -> V_43 ;
if ( V_43 )
F_27 ( V_43 ) ;
}
void F_28 ( struct V_20 * V_21 )
{
V_21 -> V_44 . V_45 = 0 ;
V_21 -> V_44 . V_46 = 0 ;
V_21 -> V_44 . V_47 = 4096 ;
V_21 -> V_44 . V_48 = 4096 ;
V_21 -> V_44 . V_49 = & V_50 ;
}
