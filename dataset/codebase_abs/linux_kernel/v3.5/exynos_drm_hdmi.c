void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( V_2 )
V_3 = V_2 ;
}
void F_3 ( struct V_4 * V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( V_2 )
V_5 = V_2 ;
}
static bool F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_7 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_3 && V_3 -> V_10 )
return V_3 -> V_10 ( V_9 -> V_11 -> V_9 ) ;
return false ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_12 * V_13 , T_1 * V_14 , int V_15 )
{
struct V_8 * V_9 = F_5 ( V_7 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_3 && V_3 -> V_16 )
return V_3 -> V_16 ( V_9 -> V_11 -> V_9 , V_13 , V_14 ,
V_15 ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 , void * V_17 )
{
struct V_8 * V_9 = F_5 ( V_7 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_3 && V_3 -> V_18 )
return V_3 -> V_18 ( V_9 -> V_11 -> V_9 , V_17 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 , int V_19 )
{
struct V_8 * V_9 = F_5 ( V_7 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_3 && V_3 -> V_20 )
return V_3 -> V_20 ( V_9 -> V_11 -> V_9 , V_19 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_21 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
struct V_22 * V_23 = & V_9 -> V_23 ;
struct V_24 * V_25 = V_23 -> V_25 ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_5 && V_5 -> V_26 )
return V_5 -> V_26 ( V_9 -> V_27 -> V_9 ,
V_25 -> V_28 ) ;
return 0 ;
}
static void F_10 ( struct V_6 * V_21 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_5 && V_5 -> V_29 )
return V_5 -> V_29 ( V_9 -> V_27 -> V_9 ) ;
}
static void F_11 ( struct V_6 * V_21 ,
struct V_12 * V_13 ,
struct V_30 * V_19 ,
struct V_30 * V_31 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_3 && V_3 -> V_32 )
V_3 -> V_32 ( V_9 -> V_11 -> V_9 , V_13 , V_19 ,
V_31 ) ;
}
static void F_12 ( struct V_6 * V_21 , void * V_19 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_3 && V_3 -> V_33 )
V_3 -> V_33 ( V_9 -> V_11 -> V_9 , V_19 ) ;
}
static void F_13 ( struct V_6 * V_21 ,
unsigned int * V_34 , unsigned int * V_35 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_3 && V_3 -> V_36 )
V_3 -> V_36 ( V_9 -> V_11 -> V_9 , V_34 , V_35 ) ;
}
static void F_14 ( struct V_6 * V_21 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_3 && V_3 -> V_37 )
V_3 -> V_37 ( V_9 -> V_11 -> V_9 ) ;
}
static void F_15 ( struct V_6 * V_21 , int V_19 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_5 && V_5 -> V_38 )
V_5 -> V_38 ( V_9 -> V_27 -> V_9 , V_19 ) ;
if ( V_3 && V_3 -> V_38 )
V_3 -> V_38 ( V_9 -> V_11 -> V_9 , V_19 ) ;
}
static void F_16 ( struct V_6 * V_21 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
int V_39 ;
F_2 ( L_1 , __FILE__ ) ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
if ( ! V_9 -> V_41 [ V_39 ] )
continue;
if ( V_5 && V_5 -> V_42 )
V_5 -> V_42 ( V_9 -> V_27 -> V_9 , V_39 ) ;
}
if ( V_3 && V_3 -> V_37 )
V_3 -> V_37 ( V_9 -> V_11 -> V_9 ) ;
}
static void F_17 ( struct V_6 * V_21 ,
struct V_43 * V_44 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_5 && V_5 -> V_45 )
V_5 -> V_45 ( V_9 -> V_27 -> V_9 , V_44 ) ;
}
static void F_18 ( struct V_6 * V_21 , int V_46 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
int V_47 = ( V_46 == V_48 ) ? V_49 : V_46 ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_47 < 0 || V_47 > V_40 ) {
F_19 ( L_2 , V_47 ) ;
return;
}
if ( V_5 && V_5 -> V_42 )
V_5 -> V_42 ( V_9 -> V_27 -> V_9 , V_47 ) ;
V_9 -> V_41 [ V_47 ] = true ;
}
static void F_20 ( struct V_6 * V_21 , int V_46 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
int V_47 = ( V_46 == V_48 ) ? V_49 : V_46 ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_47 < 0 || V_47 > V_40 ) {
F_19 ( L_2 , V_47 ) ;
return;
}
if ( V_5 && V_5 -> V_50 )
V_5 -> V_50 ( V_9 -> V_27 -> V_9 , V_47 ) ;
V_9 -> V_41 [ V_47 ] = false ;
}
static int F_21 ( struct V_51 * V_52 ,
struct V_6 * V_7 )
{
struct V_22 * V_23 = F_22 ( V_7 ) ;
struct V_8 * V_9 ;
struct V_53 * V_54 = F_23 ( V_7 ) ;
struct V_55 * V_56 ;
F_2 ( L_1 , __FILE__ ) ;
V_56 = V_54 -> V_7 . V_57 ;
if ( ! V_56 ) {
F_2 ( L_3 ) ;
return - V_58 ;
}
if ( ! V_56 -> V_59 ) {
F_2 ( L_4 ) ;
return - V_58 ;
}
if ( ! V_56 -> V_60 ) {
F_2 ( L_5 ) ;
return - V_58 ;
}
V_9 = F_24 ( V_23 ) ;
V_9 -> V_11 = (struct V_61 * )
F_5 ( V_56 -> V_59 ) ;
if ( ! V_9 -> V_11 ) {
F_2 ( L_6 ) ;
return - V_58 ;
}
V_9 -> V_11 -> V_52 = V_52 ;
V_9 -> V_27 = (struct V_61 * )
F_5 ( V_56 -> V_60 ) ;
if ( ! V_9 -> V_27 ) {
F_2 ( L_7 ) ;
return - V_58 ;
}
V_9 -> V_27 -> V_52 = V_52 ;
return 0 ;
}
static int T_2 F_25 ( struct V_53 * V_54 )
{
struct V_6 * V_7 = & V_54 -> V_7 ;
struct V_22 * V_23 ;
struct V_8 * V_9 ;
F_2 ( L_1 , __FILE__ ) ;
V_9 = F_26 ( sizeof( * V_9 ) , V_62 ) ;
if ( ! V_9 ) {
F_27 ( L_8 ) ;
return - V_63 ;
}
V_23 = & V_9 -> V_23 ;
V_23 -> V_7 = V_7 ;
V_23 -> V_25 = & V_64 ;
V_23 -> V_65 = F_21 ;
F_28 ( V_54 , V_23 ) ;
F_29 ( V_23 ) ;
return 0 ;
}
static int T_3 F_30 ( struct V_53 * V_54 )
{
struct V_8 * V_9 = F_31 ( V_54 ) ;
F_2 ( L_1 , __FILE__ ) ;
F_32 ( & V_9 -> V_23 ) ;
F_33 ( V_9 ) ;
return 0 ;
}
