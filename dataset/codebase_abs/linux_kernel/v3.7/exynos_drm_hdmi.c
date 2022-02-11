void F_1 ( struct V_1 * V_2 )
{
if ( V_2 )
V_3 = V_2 ;
}
void F_2 ( struct V_1 * V_2 )
{
if ( V_2 )
V_4 = V_2 ;
}
void F_3 ( struct V_5 * V_6 )
{
F_4 ( L_1 , __FILE__ ) ;
if ( V_6 )
V_7 = V_6 ;
}
void F_5 ( struct V_8 * V_6 )
{
F_4 ( L_1 , __FILE__ ) ;
if ( V_6 )
V_9 = V_6 ;
}
static bool F_6 ( struct V_10 * V_11 )
{
struct V_12 * V_2 = F_7 ( V_11 ) ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_7 && V_7 -> V_13 )
return V_7 -> V_13 ( V_2 -> V_3 -> V_2 ) ;
return false ;
}
static int F_8 ( struct V_10 * V_11 ,
struct V_14 * V_15 , T_1 * V_16 , int V_17 )
{
struct V_12 * V_2 = F_7 ( V_11 ) ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_7 && V_7 -> V_18 )
return V_7 -> V_18 ( V_2 -> V_3 -> V_2 , V_15 , V_16 ,
V_17 ) ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 , void * V_19 )
{
struct V_12 * V_2 = F_7 ( V_11 ) ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_7 && V_7 -> V_20 )
return V_7 -> V_20 ( V_2 -> V_3 -> V_2 , V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 , int V_21 )
{
struct V_12 * V_2 = F_7 ( V_11 ) ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_7 && V_7 -> V_22 )
return V_7 -> V_22 ( V_2 -> V_3 -> V_2 , V_21 ) ;
return 0 ;
}
static int F_11 ( struct V_10 * V_23 )
{
struct V_12 * V_2 = F_7 ( V_23 ) ;
struct V_24 * V_25 = & V_2 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_27 ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_9 && V_9 -> V_28 )
return V_9 -> V_28 ( V_2 -> V_4 -> V_2 ,
V_27 -> V_29 ) ;
return 0 ;
}
static void F_12 ( struct V_10 * V_23 )
{
struct V_12 * V_2 = F_7 ( V_23 ) ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_9 && V_9 -> V_30 )
return V_9 -> V_30 ( V_2 -> V_4 -> V_2 ) ;
}
static void F_13 ( struct V_10 * V_23 ,
struct V_14 * V_15 ,
const struct V_31 * V_21 ,
struct V_31 * V_32 )
{
struct V_12 * V_2 = F_7 ( V_23 ) ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_7 && V_7 -> V_33 )
V_7 -> V_33 ( V_2 -> V_3 -> V_2 , V_15 , V_21 ,
V_32 ) ;
}
static void F_14 ( struct V_10 * V_23 , void * V_21 )
{
struct V_12 * V_2 = F_7 ( V_23 ) ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_7 && V_7 -> V_34 )
V_7 -> V_34 ( V_2 -> V_3 -> V_2 , V_21 ) ;
}
static void F_15 ( struct V_10 * V_23 ,
unsigned int * V_35 , unsigned int * V_36 )
{
struct V_12 * V_2 = F_7 ( V_23 ) ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_7 && V_7 -> V_37 )
V_7 -> V_37 ( V_2 -> V_3 -> V_2 , V_35 , V_36 ) ;
}
static void F_16 ( struct V_10 * V_23 )
{
struct V_12 * V_2 = F_7 ( V_23 ) ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_7 && V_7 -> V_38 )
V_7 -> V_38 ( V_2 -> V_3 -> V_2 ) ;
}
static void F_17 ( struct V_10 * V_23 , int V_21 )
{
struct V_12 * V_2 = F_7 ( V_23 ) ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_9 && V_9 -> V_39 )
V_9 -> V_39 ( V_2 -> V_4 -> V_2 , V_21 ) ;
if ( V_7 && V_7 -> V_39 )
V_7 -> V_39 ( V_2 -> V_3 -> V_2 , V_21 ) ;
}
static void F_18 ( struct V_10 * V_23 )
{
struct V_12 * V_2 = F_7 ( V_23 ) ;
int V_40 ;
F_4 ( L_1 , __FILE__ ) ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
if ( ! V_2 -> V_42 [ V_40 ] )
continue;
if ( V_9 && V_9 -> V_43 )
V_9 -> V_43 ( V_2 -> V_4 -> V_2 , V_40 ) ;
}
if ( V_7 && V_7 -> V_38 )
V_7 -> V_38 ( V_2 -> V_3 -> V_2 ) ;
}
static void F_19 ( struct V_10 * V_23 ,
struct V_44 * V_45 )
{
struct V_12 * V_2 = F_7 ( V_23 ) ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_9 && V_9 -> V_46 )
V_9 -> V_46 ( V_2 -> V_4 -> V_2 , V_45 ) ;
}
static void F_20 ( struct V_10 * V_23 , int V_47 )
{
struct V_12 * V_2 = F_7 ( V_23 ) ;
int V_48 = ( V_47 == V_49 ) ? V_50 : V_47 ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_48 < 0 || V_48 > V_41 ) {
F_21 ( L_2 , V_48 ) ;
return;
}
if ( V_9 && V_9 -> V_43 )
V_9 -> V_43 ( V_2 -> V_4 -> V_2 , V_48 ) ;
V_2 -> V_42 [ V_48 ] = true ;
}
static void F_22 ( struct V_10 * V_23 , int V_47 )
{
struct V_12 * V_2 = F_7 ( V_23 ) ;
int V_48 = ( V_47 == V_49 ) ? V_50 : V_47 ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_48 < 0 || V_48 > V_41 ) {
F_21 ( L_2 , V_48 ) ;
return;
}
if ( V_9 && V_9 -> V_51 )
V_9 -> V_51 ( V_2 -> V_4 -> V_2 , V_48 ) ;
V_2 -> V_42 [ V_48 ] = false ;
}
static void F_23 ( struct V_10 * V_23 )
{
struct V_12 * V_2 = F_7 ( V_23 ) ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_9 && V_9 -> V_52 )
V_9 -> V_52 ( V_2 -> V_4 -> V_2 ) ;
}
static int F_24 ( struct V_53 * V_54 ,
struct V_10 * V_11 )
{
struct V_24 * V_25 = F_25 ( V_11 ) ;
struct V_12 * V_2 ;
F_4 ( L_1 , __FILE__ ) ;
if ( ! V_3 ) {
F_21 ( L_3 ) ;
return - V_55 ;
}
if ( ! V_4 ) {
F_21 ( L_4 ) ;
return - V_55 ;
}
V_2 = F_26 ( V_25 ) ;
if ( ! V_2 ) {
F_21 ( L_5 ) ;
return - V_55 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_3 -> V_54 = V_54 ;
V_2 -> V_4 -> V_54 = V_54 ;
return 0 ;
}
static int T_2 F_27 ( struct V_56 * V_57 )
{
struct V_10 * V_11 = & V_57 -> V_11 ;
struct V_24 * V_25 ;
struct V_12 * V_2 ;
F_4 ( L_1 , __FILE__ ) ;
V_2 = F_28 ( & V_57 -> V_11 , sizeof( * V_2 ) , V_58 ) ;
if ( ! V_2 ) {
F_29 ( L_6 ) ;
return - V_59 ;
}
V_25 = & V_2 -> V_25 ;
V_25 -> V_11 = V_11 ;
V_25 -> V_27 = & V_60 ;
V_25 -> V_61 = F_24 ;
F_30 ( V_57 , V_25 ) ;
F_31 ( V_25 ) ;
return 0 ;
}
static int T_3 F_32 ( struct V_56 * V_57 )
{
struct V_12 * V_2 = F_33 ( V_57 ) ;
F_4 ( L_1 , __FILE__ ) ;
F_34 ( & V_2 -> V_25 ) ;
return 0 ;
}
