int F_1 ( void )
{
if ( V_1 )
return - V_2 ;
V_1 = F_2 (
L_1 , - 1 , NULL , 0 ) ;
if ( F_3 ( V_1 ) )
return F_4 ( V_1 ) ;
return 0 ;
}
void F_5 ( void )
{
if ( V_1 )
F_6 ( V_1 ) ;
}
void F_7 ( struct V_3 * V_4 )
{
if ( V_4 )
V_5 = V_4 ;
}
void F_8 ( struct V_3 * V_4 )
{
if ( V_4 )
V_6 = V_4 ;
}
void F_9 ( struct V_7 * V_8 )
{
F_10 ( L_2 , __FILE__ ) ;
if ( V_8 )
V_9 = V_8 ;
}
void F_11 ( struct V_10 * V_8 )
{
F_10 ( L_2 , __FILE__ ) ;
if ( V_8 )
V_11 = V_8 ;
}
static bool F_12 ( struct V_12 * V_13 )
{
struct V_14 * V_4 = F_13 ( V_13 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_9 && V_9 -> V_15 )
return V_9 -> V_15 ( V_4 -> V_5 -> V_4 ) ;
return false ;
}
static struct V_16 * F_14 ( struct V_12 * V_13 ,
struct V_17 * V_18 )
{
struct V_14 * V_4 = F_13 ( V_13 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_9 && V_9 -> V_19 )
return V_9 -> V_19 ( V_4 -> V_5 -> V_4 , V_18 ) ;
return NULL ;
}
static int F_15 ( struct V_12 * V_13 , void * V_20 )
{
struct V_14 * V_4 = F_13 ( V_13 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_9 && V_9 -> V_21 )
return V_9 -> V_21 ( V_4 -> V_5 -> V_4 , V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 , int V_22 )
{
struct V_14 * V_4 = F_13 ( V_13 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_9 && V_9 -> V_23 )
return V_9 -> V_23 ( V_4 -> V_5 -> V_4 , V_22 ) ;
return 0 ;
}
static int F_17 ( struct V_12 * V_24 )
{
struct V_14 * V_4 = F_13 ( V_24 ) ;
struct V_25 * V_26 = & V_4 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_28 ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_11 && V_11 -> V_29 )
return V_11 -> V_29 ( V_4 -> V_6 -> V_4 ,
V_28 -> V_30 ) ;
return 0 ;
}
static void F_18 ( struct V_12 * V_24 )
{
struct V_14 * V_4 = F_13 ( V_24 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_11 && V_11 -> V_31 )
return V_11 -> V_31 ( V_4 -> V_6 -> V_4 ) ;
}
static void F_19 ( struct V_12 * V_24 )
{
struct V_14 * V_4 = F_13 ( V_24 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_11 && V_11 -> V_32 )
V_11 -> V_32 ( V_4 -> V_6 -> V_4 ) ;
}
static void F_20 ( struct V_12 * V_24 ,
struct V_17 * V_18 ,
const struct V_33 * V_22 ,
struct V_33 * V_34 )
{
struct V_14 * V_4 = F_13 ( V_24 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_9 && V_9 -> V_35 )
V_9 -> V_35 ( V_4 -> V_5 -> V_4 , V_18 , V_22 ,
V_34 ) ;
}
static void F_21 ( struct V_12 * V_24 , void * V_22 )
{
struct V_14 * V_4 = F_13 ( V_24 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_9 && V_9 -> V_36 )
V_9 -> V_36 ( V_4 -> V_5 -> V_4 , V_22 ) ;
}
static void F_22 ( struct V_12 * V_24 ,
unsigned int * V_37 , unsigned int * V_38 )
{
struct V_14 * V_4 = F_13 ( V_24 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_9 && V_9 -> V_39 )
V_9 -> V_39 ( V_4 -> V_5 -> V_4 , V_37 , V_38 ) ;
}
static void F_23 ( struct V_12 * V_24 )
{
struct V_14 * V_4 = F_13 ( V_24 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_9 && V_9 -> V_40 )
V_9 -> V_40 ( V_4 -> V_5 -> V_4 ) ;
}
static void F_24 ( struct V_12 * V_24 , int V_22 )
{
struct V_14 * V_4 = F_13 ( V_24 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_11 && V_11 -> V_41 )
V_11 -> V_41 ( V_4 -> V_6 -> V_4 , V_22 ) ;
if ( V_9 && V_9 -> V_41 )
V_9 -> V_41 ( V_4 -> V_5 -> V_4 , V_22 ) ;
}
static void F_25 ( struct V_12 * V_24 )
{
struct V_14 * V_4 = F_13 ( V_24 ) ;
int V_42 ;
F_10 ( L_2 , __FILE__ ) ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( ! V_4 -> V_44 [ V_42 ] )
continue;
if ( V_11 && V_11 -> V_45 )
V_11 -> V_45 ( V_4 -> V_6 -> V_4 , V_42 ) ;
}
if ( V_9 && V_9 -> V_40 )
V_9 -> V_40 ( V_4 -> V_5 -> V_4 ) ;
}
static void F_26 ( struct V_12 * V_24 ,
struct V_46 * V_47 )
{
struct V_14 * V_4 = F_13 ( V_24 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_11 && V_11 -> V_48 )
V_11 -> V_48 ( V_4 -> V_6 -> V_4 , V_47 ) ;
}
static void F_27 ( struct V_12 * V_24 , int V_49 )
{
struct V_14 * V_4 = F_13 ( V_24 ) ;
int V_50 = ( V_49 == V_51 ) ? V_52 : V_49 ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_50 < 0 || V_50 > V_43 ) {
F_28 ( L_3 , V_50 ) ;
return;
}
if ( V_11 && V_11 -> V_45 )
V_11 -> V_45 ( V_4 -> V_6 -> V_4 , V_50 ) ;
V_4 -> V_44 [ V_50 ] = true ;
}
static void F_29 ( struct V_12 * V_24 , int V_49 )
{
struct V_14 * V_4 = F_13 ( V_24 ) ;
int V_50 = ( V_49 == V_51 ) ? V_52 : V_49 ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_50 < 0 || V_50 > V_43 ) {
F_28 ( L_3 , V_50 ) ;
return;
}
if ( V_11 && V_11 -> V_53 )
V_11 -> V_53 ( V_4 -> V_6 -> V_4 , V_50 ) ;
V_4 -> V_44 [ V_50 ] = false ;
}
static int F_30 ( struct V_54 * V_55 ,
struct V_12 * V_13 )
{
struct V_25 * V_26 = F_31 ( V_13 ) ;
struct V_14 * V_4 ;
F_10 ( L_2 , __FILE__ ) ;
if ( ! V_5 ) {
F_28 ( L_4 ) ;
return - V_56 ;
}
if ( ! V_6 ) {
F_28 ( L_5 ) ;
return - V_56 ;
}
V_4 = F_32 ( V_26 ) ;
if ( ! V_4 ) {
F_28 ( L_6 ) ;
return - V_56 ;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_5 -> V_55 = V_55 ;
V_4 -> V_6 -> V_55 = V_55 ;
if ( V_11 -> V_57 )
V_11 -> V_57 ( V_4 -> V_6 -> V_4 , true ) ;
return 0 ;
}
static void F_33 ( struct V_54 * V_55 , struct V_12 * V_13 )
{
struct V_14 * V_4 ;
struct V_25 * V_26 = F_31 ( V_13 ) ;
V_4 = F_32 ( V_26 ) ;
if ( V_11 -> V_57 )
V_11 -> V_57 ( V_4 -> V_6 -> V_4 , false ) ;
}
static int F_34 ( struct V_58 * V_59 )
{
struct V_12 * V_13 = & V_59 -> V_13 ;
struct V_25 * V_26 ;
struct V_14 * V_4 ;
F_10 ( L_2 , __FILE__ ) ;
V_4 = F_35 ( & V_59 -> V_13 , sizeof( * V_4 ) , V_60 ) ;
if ( ! V_4 ) {
F_36 ( L_7 ) ;
return - V_61 ;
}
V_26 = & V_4 -> V_26 ;
V_26 -> V_13 = V_13 ;
V_26 -> V_28 = & V_62 ;
V_26 -> V_63 = F_30 ;
V_26 -> remove = F_33 ;
F_37 ( V_59 , V_26 ) ;
F_38 ( V_26 ) ;
return 0 ;
}
static int F_39 ( struct V_58 * V_59 )
{
struct V_14 * V_4 = F_40 ( V_59 ) ;
F_10 ( L_2 , __FILE__ ) ;
F_41 ( & V_4 -> V_26 ) ;
return 0 ;
}
