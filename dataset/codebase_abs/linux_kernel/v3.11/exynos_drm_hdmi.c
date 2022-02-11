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
if ( V_10 )
V_11 = V_10 ;
}
void F_10 ( struct V_12 * V_10 )
{
if ( V_10 )
V_13 = V_10 ;
}
static bool F_11 ( struct V_14 * V_15 )
{
struct V_16 * V_6 = F_12 ( V_15 ) ;
if ( V_11 && V_11 -> V_17 )
return V_11 -> V_17 ( V_6 -> V_7 -> V_6 ) ;
return false ;
}
static struct V_18 * F_13 ( struct V_14 * V_15 ,
struct V_19 * V_20 )
{
struct V_16 * V_6 = F_12 ( V_15 ) ;
if ( V_11 && V_11 -> V_21 )
return V_11 -> V_21 ( V_6 -> V_7 -> V_6 , V_20 ) ;
return NULL ;
}
static int F_14 ( struct V_14 * V_15 ,
struct V_22 * V_23 )
{
struct V_16 * V_6 = F_12 ( V_15 ) ;
int V_24 = 0 ;
if ( V_13 && V_13 -> V_25 )
V_24 = V_13 -> V_25 ( V_6 -> V_8 -> V_6 , V_23 ) ;
if ( V_24 )
return V_24 ;
if ( V_11 && V_11 -> V_25 )
return V_11 -> V_25 ( V_6 -> V_7 -> V_6 , V_23 ) ;
return 0 ;
}
static int F_15 ( struct V_14 * V_15 , int V_23 )
{
struct V_16 * V_6 = F_12 ( V_15 ) ;
if ( V_11 && V_11 -> V_26 )
return V_11 -> V_26 ( V_6 -> V_7 -> V_6 , V_23 ) ;
return 0 ;
}
static int F_16 ( struct V_14 * V_27 )
{
struct V_16 * V_6 = F_12 ( V_27 ) ;
struct V_28 * V_29 = & V_6 -> V_29 ;
struct V_30 * V_31 = V_29 -> V_31 ;
if ( V_13 && V_13 -> V_32 )
return V_13 -> V_32 ( V_6 -> V_8 -> V_6 ,
V_31 -> V_33 ) ;
return 0 ;
}
static void F_17 ( struct V_14 * V_27 )
{
struct V_16 * V_6 = F_12 ( V_27 ) ;
if ( V_13 && V_13 -> V_34 )
return V_13 -> V_34 ( V_6 -> V_8 -> V_6 ) ;
}
static void F_18 ( struct V_14 * V_27 )
{
struct V_16 * V_6 = F_12 ( V_27 ) ;
if ( V_13 && V_13 -> V_35 )
V_13 -> V_35 ( V_6 -> V_8 -> V_6 ) ;
}
static void F_19 ( struct V_14 * V_27 ,
struct V_19 * V_20 ,
const struct V_22 * V_23 ,
struct V_22 * V_36 )
{
struct V_22 * V_37 ;
int V_38 ;
F_20 ( V_36 , 0 ) ;
V_38 = F_14 ( V_27 , V_36 ) ;
if ( V_38 == 0 )
return;
F_21 (m, &connector->modes, head) {
V_38 = F_14 ( V_27 , V_37 ) ;
if ( V_38 == 0 ) {
struct V_39 V_40 ;
struct V_41 V_42 ;
F_22 ( L_2 ) ;
F_22 ( L_3 ) ;
F_23 ( L_4 ,
V_37 -> V_43 , V_37 -> V_44 , V_37 -> V_45 ) ;
V_42 = V_36 -> V_42 ;
V_40 = V_36 -> V_40 ;
memcpy ( V_36 , V_37 , sizeof( * V_37 ) ) ;
V_36 -> V_42 = V_42 ;
V_36 -> V_40 = V_40 ;
break;
}
}
}
static void F_24 ( struct V_14 * V_27 , void * V_23 )
{
struct V_16 * V_6 = F_12 ( V_27 ) ;
if ( V_11 && V_11 -> V_46 )
V_11 -> V_46 ( V_6 -> V_7 -> V_6 , V_23 ) ;
}
static void F_25 ( struct V_14 * V_27 ,
unsigned int * V_47 , unsigned int * V_48 )
{
struct V_16 * V_6 = F_12 ( V_27 ) ;
if ( V_11 && V_11 -> V_49 )
V_11 -> V_49 ( V_6 -> V_7 -> V_6 , V_47 , V_48 ) ;
}
static void F_26 ( struct V_14 * V_27 )
{
struct V_16 * V_6 = F_12 ( V_27 ) ;
if ( V_11 && V_11 -> V_50 )
V_11 -> V_50 ( V_6 -> V_7 -> V_6 ) ;
}
static void F_27 ( struct V_14 * V_27 , int V_23 )
{
struct V_16 * V_6 = F_12 ( V_27 ) ;
if ( V_13 && V_13 -> V_51 )
V_13 -> V_51 ( V_6 -> V_8 -> V_6 , V_23 ) ;
if ( V_11 && V_11 -> V_51 )
V_11 -> V_51 ( V_6 -> V_7 -> V_6 , V_23 ) ;
}
static void F_28 ( struct V_14 * V_27 )
{
struct V_16 * V_6 = F_12 ( V_27 ) ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
if ( ! V_6 -> V_54 [ V_52 ] )
continue;
if ( V_13 && V_13 -> V_55 )
V_13 -> V_55 ( V_6 -> V_8 -> V_6 , V_52 ) ;
}
if ( V_11 && V_11 -> V_50 )
V_11 -> V_50 ( V_6 -> V_7 -> V_6 ) ;
}
static void F_29 ( struct V_14 * V_27 ,
struct V_56 * V_57 )
{
struct V_16 * V_6 = F_12 ( V_27 ) ;
if ( V_13 && V_13 -> V_58 )
V_13 -> V_58 ( V_6 -> V_8 -> V_6 , V_57 ) ;
}
static void F_30 ( struct V_14 * V_27 , int V_59 )
{
struct V_16 * V_6 = F_12 ( V_27 ) ;
int V_60 = ( V_59 == V_61 ) ? V_62 : V_59 ;
if ( V_60 < 0 || V_60 >= V_53 ) {
F_31 ( L_5 , V_60 ) ;
return;
}
if ( V_13 && V_13 -> V_55 )
V_13 -> V_55 ( V_6 -> V_8 -> V_6 , V_60 ) ;
V_6 -> V_54 [ V_60 ] = true ;
}
static void F_32 ( struct V_14 * V_27 , int V_59 )
{
struct V_16 * V_6 = F_12 ( V_27 ) ;
int V_60 = ( V_59 == V_61 ) ? V_62 : V_59 ;
if ( V_60 < 0 || V_60 >= V_53 ) {
F_31 ( L_5 , V_60 ) ;
return;
}
if ( V_13 && V_13 -> V_63 )
V_13 -> V_63 ( V_6 -> V_8 -> V_6 , V_60 ) ;
V_6 -> V_54 [ V_60 ] = false ;
}
static int F_33 ( struct V_64 * V_65 ,
struct V_14 * V_15 )
{
struct V_28 * V_29 = F_34 ( V_15 ) ;
struct V_16 * V_6 ;
if ( ! V_7 ) {
F_31 ( L_6 ) ;
return - V_66 ;
}
if ( ! V_8 ) {
F_31 ( L_7 ) ;
return - V_66 ;
}
V_6 = F_35 ( V_29 ) ;
if ( ! V_6 ) {
F_31 ( L_8 ) ;
return - V_66 ;
}
V_6 -> V_7 = V_7 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_7 -> V_65 = V_65 ;
V_6 -> V_8 -> V_65 = V_65 ;
if ( V_13 -> V_67 )
V_13 -> V_67 ( V_6 -> V_8 -> V_6 , true ) ;
return 0 ;
}
static void F_36 ( struct V_64 * V_65 , struct V_14 * V_15 )
{
struct V_16 * V_6 ;
struct V_28 * V_29 = F_34 ( V_15 ) ;
V_6 = F_35 ( V_29 ) ;
if ( V_13 -> V_67 )
V_13 -> V_67 ( V_6 -> V_8 -> V_6 , false ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
struct V_28 * V_29 ;
struct V_16 * V_6 ;
V_6 = F_38 ( V_15 , sizeof( * V_6 ) , V_68 ) ;
if ( ! V_6 ) {
F_39 ( L_9 ) ;
return - V_69 ;
}
V_29 = & V_6 -> V_29 ;
V_29 -> V_15 = V_15 ;
V_29 -> V_31 = & V_70 ;
V_29 -> V_71 = F_33 ;
V_29 -> remove = F_36 ;
F_40 ( V_2 , V_29 ) ;
F_41 ( V_29 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_16 * V_6 = F_43 ( V_2 ) ;
F_44 ( & V_6 -> V_29 ) ;
return 0 ;
}
