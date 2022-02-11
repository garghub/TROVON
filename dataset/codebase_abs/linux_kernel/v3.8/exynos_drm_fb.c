static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
if ( F_2 ( V_2 ) )
return 0 ;
V_5 = V_4 -> V_5 ;
if ( F_3 ( V_5 ) ) {
F_4 ( L_1 ) ;
return - V_6 ;
}
return 0 ;
}
static void F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
unsigned int V_11 ;
F_7 ( L_2 , __FILE__ ) ;
F_8 ( V_8 ) ;
F_9 ( V_8 ) ;
for ( V_11 = 0 ; V_11 < F_10 ( V_10 -> V_4 ) ; V_11 ++ ) {
struct V_12 * V_13 ;
if ( V_10 -> V_4 [ V_11 ] == NULL )
continue;
V_13 = & V_10 -> V_4 [ V_11 ] -> V_14 ;
F_11 ( V_13 ) ;
}
F_12 ( V_10 ) ;
V_10 = NULL ;
}
static int F_13 ( struct V_7 * V_8 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
F_7 ( L_2 , __FILE__ ) ;
return F_14 ( V_16 ,
& V_10 -> V_4 [ 0 ] -> V_14 , V_17 ) ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_15 * V_16 , unsigned V_5 ,
unsigned V_18 , struct V_19 * V_20 ,
unsigned V_21 )
{
F_7 ( L_2 , __FILE__ ) ;
return 0 ;
}
void F_16 ( struct V_7 * V_8 ,
unsigned int V_22 )
{
struct V_9 * V_10 ;
V_10 = F_6 ( V_8 ) ;
V_10 -> V_23 = V_22 ;
}
unsigned int F_17 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_6 ( V_8 ) ;
return V_10 -> V_23 ;
}
struct V_7 *
F_18 ( struct V_1 * V_24 ,
struct V_25 * V_26 ,
struct V_12 * V_13 )
{
struct V_9 * V_10 ;
struct V_3 * V_4 ;
int V_27 ;
V_4 = F_19 ( V_13 ) ;
V_27 = F_1 ( V_24 , V_4 ) ;
if ( V_27 < 0 ) {
F_4 ( L_1 ) ;
return F_20 ( - V_6 ) ;
}
V_10 = F_21 ( sizeof( * V_10 ) , V_28 ) ;
if ( ! V_10 ) {
F_4 ( L_3 ) ;
return F_20 ( - V_29 ) ;
}
F_22 ( & V_10 -> V_8 , V_26 ) ;
V_10 -> V_4 [ 0 ] = V_4 ;
V_27 = F_23 ( V_24 , & V_10 -> V_8 , & V_30 ) ;
if ( V_27 ) {
F_4 ( L_4 ) ;
return F_20 ( V_27 ) ;
}
return & V_10 -> V_8 ;
}
static T_1 F_24 ( struct V_25 * V_26 )
{
unsigned int V_22 = 0 ;
if ( V_26 -> V_31 != V_32 )
return F_25 ( V_26 -> V_31 ) ;
while ( V_22 != V_33 ) {
if ( ! V_26 -> V_34 [ V_22 ] )
break;
V_22 ++ ;
}
if ( V_22 == 2 ) {
if ( V_26 -> V_35 [ 1 ] &&
V_26 -> V_34 [ 0 ] == V_26 -> V_34 [ 1 ] )
V_22 = 1 ;
}
return V_22 ;
}
static struct V_7 *
F_26 ( struct V_1 * V_24 , struct V_15 * V_16 ,
struct V_25 * V_26 )
{
struct V_12 * V_13 ;
struct V_9 * V_10 ;
int V_11 , V_27 ;
F_7 ( L_2 , __FILE__ ) ;
V_13 = F_27 ( V_24 , V_16 , V_26 -> V_34 [ 0 ] ) ;
if ( ! V_13 ) {
F_4 ( L_5 ) ;
return F_20 ( - V_36 ) ;
}
V_10 = F_21 ( sizeof( * V_10 ) , V_28 ) ;
if ( ! V_10 ) {
F_4 ( L_3 ) ;
return F_20 ( - V_29 ) ;
}
F_22 ( & V_10 -> V_8 , V_26 ) ;
V_10 -> V_4 [ 0 ] = F_19 ( V_13 ) ;
V_10 -> V_23 = F_24 ( V_26 ) ;
F_7 ( L_6 , V_10 -> V_23 ) ;
for ( V_11 = 1 ; V_11 < V_10 -> V_23 ; V_11 ++ ) {
struct V_3 * V_4 ;
int V_27 ;
V_13 = F_27 ( V_24 , V_16 ,
V_26 -> V_34 [ V_11 ] ) ;
if ( ! V_13 ) {
F_4 ( L_5 ) ;
F_12 ( V_10 ) ;
return F_20 ( - V_36 ) ;
}
V_4 = F_19 ( V_13 ) ;
V_27 = F_1 ( V_24 , V_4 ) ;
if ( V_27 < 0 ) {
F_4 ( L_1 ) ;
F_12 ( V_10 ) ;
return F_20 ( V_27 ) ;
}
V_10 -> V_4 [ V_11 ] = F_19 ( V_13 ) ;
}
V_27 = F_23 ( V_24 , & V_10 -> V_8 , & V_30 ) ;
if ( V_27 ) {
for ( V_11 = 0 ; V_11 < V_10 -> V_23 ; V_11 ++ ) {
struct V_3 * V_37 ;
V_37 = V_10 -> V_4 [ V_11 ] ;
F_11 ( & V_37 -> V_14 ) ;
}
F_12 ( V_10 ) ;
return F_20 ( V_27 ) ;
}
return & V_10 -> V_8 ;
}
struct V_38 * F_28 ( struct V_7 * V_8 ,
int V_39 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
struct V_38 * V_40 ;
F_7 ( L_2 , __FILE__ ) ;
if ( V_39 >= V_33 )
return NULL ;
V_40 = V_10 -> V_4 [ V_39 ] -> V_40 ;
if ( ! V_40 )
return NULL ;
F_7 ( L_7 , ( unsigned long ) V_40 -> V_41 ) ;
return V_40 ;
}
static void F_29 ( struct V_1 * V_24 )
{
struct V_42 * V_43 = V_24 -> V_44 ;
struct V_45 * V_46 = V_43 -> V_46 ;
if ( V_46 )
F_30 ( V_46 ) ;
}
void F_31 ( struct V_1 * V_24 )
{
V_24 -> V_47 . V_48 = 0 ;
V_24 -> V_47 . V_49 = 0 ;
V_24 -> V_47 . V_50 = 4096 ;
V_24 -> V_47 . V_51 = 4096 ;
V_24 -> V_47 . V_52 = & V_53 ;
}
