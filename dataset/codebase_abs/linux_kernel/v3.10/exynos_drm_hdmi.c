int F_1 ( void )
{
struct V_1 * V_2 ;
if ( V_3 )
return - V_4 ;
V_2 = F_2 (
L_1 , - 1 , NULL , 0 ) ;
if ( F_3 ( V_2 ) )
return F_4 ( V_2 ) ;
V_3 = V_2 ;
return 0 ;
}
void F_5 ( void )
{
if ( V_3 ) {
F_6 ( V_3 ) ;
V_3 = NULL ;
}
}
void F_7 ( struct V_5 * V_6 )
{
if ( V_6 )
V_7 = V_6 ;
}
void F_8 ( struct V_5 * V_6 )
{
if ( V_6 )
V_8 = V_6 ;
}
void F_9 ( struct V_9 * V_10 )
{
F_10 ( L_2 , __FILE__ ) ;
if ( V_10 )
V_11 = V_10 ;
}
void F_11 ( struct V_12 * V_10 )
{
F_10 ( L_2 , __FILE__ ) ;
if ( V_10 )
V_13 = V_10 ;
}
static bool F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_6 = F_13 ( V_15 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_11 && V_11 -> V_17 )
return V_11 -> V_17 ( V_6 -> V_7 -> V_6 ) ;
return false ;
}
static struct V_18 * F_14 ( struct V_14 * V_15 ,
struct V_19 * V_20 )
{
struct V_16 * V_6 = F_13 ( V_15 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_11 && V_11 -> V_21 )
return V_11 -> V_21 ( V_6 -> V_7 -> V_6 , V_20 ) ;
return NULL ;
}
static int F_15 ( struct V_14 * V_15 , void * V_22 )
{
struct V_16 * V_6 = F_13 ( V_15 ) ;
int V_23 = 0 ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_13 && V_13 -> V_24 )
V_23 = V_13 -> V_24 ( V_6 -> V_8 -> V_6 , V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_11 && V_11 -> V_24 )
return V_11 -> V_24 ( V_6 -> V_7 -> V_6 , V_22 ) ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 , int V_25 )
{
struct V_16 * V_6 = F_13 ( V_15 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_11 && V_11 -> V_26 )
return V_11 -> V_26 ( V_6 -> V_7 -> V_6 , V_25 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_27 )
{
struct V_16 * V_6 = F_13 ( V_27 ) ;
struct V_28 * V_29 = & V_6 -> V_29 ;
struct V_30 * V_31 = V_29 -> V_31 ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_13 && V_13 -> V_32 )
return V_13 -> V_32 ( V_6 -> V_8 -> V_6 ,
V_31 -> V_33 ) ;
return 0 ;
}
static void F_18 ( struct V_14 * V_27 )
{
struct V_16 * V_6 = F_13 ( V_27 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_13 && V_13 -> V_34 )
return V_13 -> V_34 ( V_6 -> V_8 -> V_6 ) ;
}
static void F_19 ( struct V_14 * V_27 )
{
struct V_16 * V_6 = F_13 ( V_27 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_13 && V_13 -> V_35 )
V_13 -> V_35 ( V_6 -> V_8 -> V_6 ) ;
}
static void F_20 ( struct V_14 * V_27 ,
struct V_19 * V_20 ,
const struct V_36 * V_25 ,
struct V_36 * V_37 )
{
struct V_36 * V_38 ;
int V_39 ;
F_10 ( L_2 , __FILE__ ) ;
F_21 ( V_37 , 0 ) ;
V_39 = F_15 ( V_27 , V_37 ) ;
if ( V_39 == 0 )
return;
F_22 (m, &connector->modes, head) {
V_39 = F_15 ( V_27 , V_38 ) ;
if ( V_39 == 0 ) {
struct V_40 V_41 ;
struct V_42 V_43 ;
F_23 ( L_3 ) ;
F_23 ( L_4 ) ;
F_10 ( L_5 ,
V_38 -> V_44 , V_38 -> V_45 , V_38 -> V_46 ) ;
V_43 = V_37 -> V_43 ;
V_41 = V_37 -> V_41 ;
memcpy ( V_37 , V_38 , sizeof( * V_38 ) ) ;
V_37 -> V_43 = V_43 ;
V_37 -> V_41 = V_41 ;
break;
}
}
}
static void F_24 ( struct V_14 * V_27 , void * V_25 )
{
struct V_16 * V_6 = F_13 ( V_27 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_11 && V_11 -> V_47 )
V_11 -> V_47 ( V_6 -> V_7 -> V_6 , V_25 ) ;
}
static void F_25 ( struct V_14 * V_27 ,
unsigned int * V_48 , unsigned int * V_49 )
{
struct V_16 * V_6 = F_13 ( V_27 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_11 && V_11 -> V_50 )
V_11 -> V_50 ( V_6 -> V_7 -> V_6 , V_48 , V_49 ) ;
}
static void F_26 ( struct V_14 * V_27 )
{
struct V_16 * V_6 = F_13 ( V_27 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_11 && V_11 -> V_51 )
V_11 -> V_51 ( V_6 -> V_7 -> V_6 ) ;
}
static void F_27 ( struct V_14 * V_27 , int V_25 )
{
struct V_16 * V_6 = F_13 ( V_27 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_13 && V_13 -> V_52 )
V_13 -> V_52 ( V_6 -> V_8 -> V_6 , V_25 ) ;
if ( V_11 && V_11 -> V_52 )
V_11 -> V_52 ( V_6 -> V_7 -> V_6 , V_25 ) ;
}
static void F_28 ( struct V_14 * V_27 )
{
struct V_16 * V_6 = F_13 ( V_27 ) ;
int V_53 ;
F_10 ( L_2 , __FILE__ ) ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
if ( ! V_6 -> V_55 [ V_53 ] )
continue;
if ( V_13 && V_13 -> V_56 )
V_13 -> V_56 ( V_6 -> V_8 -> V_6 , V_53 ) ;
}
if ( V_11 && V_11 -> V_51 )
V_11 -> V_51 ( V_6 -> V_7 -> V_6 ) ;
}
static void F_29 ( struct V_14 * V_27 ,
struct V_57 * V_58 )
{
struct V_16 * V_6 = F_13 ( V_27 ) ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_13 && V_13 -> V_59 )
V_13 -> V_59 ( V_6 -> V_8 -> V_6 , V_58 ) ;
}
static void F_30 ( struct V_14 * V_27 , int V_60 )
{
struct V_16 * V_6 = F_13 ( V_27 ) ;
int V_61 = ( V_60 == V_62 ) ? V_63 : V_60 ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_61 < 0 || V_61 > V_54 ) {
F_31 ( L_6 , V_61 ) ;
return;
}
if ( V_13 && V_13 -> V_56 )
V_13 -> V_56 ( V_6 -> V_8 -> V_6 , V_61 ) ;
V_6 -> V_55 [ V_61 ] = true ;
}
static void F_32 ( struct V_14 * V_27 , int V_60 )
{
struct V_16 * V_6 = F_13 ( V_27 ) ;
int V_61 = ( V_60 == V_62 ) ? V_63 : V_60 ;
F_10 ( L_2 , __FILE__ ) ;
if ( V_61 < 0 || V_61 > V_54 ) {
F_31 ( L_6 , V_61 ) ;
return;
}
if ( V_13 && V_13 -> V_64 )
V_13 -> V_64 ( V_6 -> V_8 -> V_6 , V_61 ) ;
V_6 -> V_55 [ V_61 ] = false ;
}
static int F_33 ( struct V_65 * V_66 ,
struct V_14 * V_15 )
{
struct V_28 * V_29 = F_34 ( V_15 ) ;
struct V_16 * V_6 ;
F_10 ( L_2 , __FILE__ ) ;
if ( ! V_7 ) {
F_31 ( L_7 ) ;
return - V_67 ;
}
if ( ! V_8 ) {
F_31 ( L_8 ) ;
return - V_67 ;
}
V_6 = F_35 ( V_29 ) ;
if ( ! V_6 ) {
F_31 ( L_9 ) ;
return - V_67 ;
}
V_6 -> V_7 = V_7 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_7 -> V_66 = V_66 ;
V_6 -> V_8 -> V_66 = V_66 ;
if ( V_13 -> V_68 )
V_13 -> V_68 ( V_6 -> V_8 -> V_6 , true ) ;
return 0 ;
}
static void F_36 ( struct V_65 * V_66 , struct V_14 * V_15 )
{
struct V_16 * V_6 ;
struct V_28 * V_29 = F_34 ( V_15 ) ;
V_6 = F_35 ( V_29 ) ;
if ( V_13 -> V_68 )
V_13 -> V_68 ( V_6 -> V_8 -> V_6 , false ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
struct V_28 * V_29 ;
struct V_16 * V_6 ;
F_10 ( L_2 , __FILE__ ) ;
V_6 = F_38 ( V_15 , sizeof( * V_6 ) , V_69 ) ;
if ( ! V_6 ) {
F_39 ( L_10 ) ;
return - V_70 ;
}
V_29 = & V_6 -> V_29 ;
V_29 -> V_15 = V_15 ;
V_29 -> V_31 = & V_71 ;
V_29 -> V_72 = F_33 ;
V_29 -> remove = F_36 ;
F_40 ( V_2 , V_29 ) ;
F_41 ( V_29 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_16 * V_6 = F_43 ( V_2 ) ;
F_10 ( L_2 , __FILE__ ) ;
F_44 ( & V_6 -> V_29 ) ;
return 0 ;
}
