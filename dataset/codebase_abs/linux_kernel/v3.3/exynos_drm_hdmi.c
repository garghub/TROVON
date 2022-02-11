void F_1 ( struct V_1
* V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( V_2 )
V_3 = V_2 ;
}
void F_3 ( struct V_4
* V_5 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( V_5 )
V_6 = V_5 ;
}
void F_4 ( struct V_7
* V_8 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( V_8 )
V_9 = V_8 ;
}
static bool F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_6 ( V_11 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_3 && V_3 -> V_14 )
return V_3 -> V_14 ( V_13 -> V_15 -> V_13 ) ;
return false ;
}
static int F_7 ( struct V_10 * V_11 ,
struct V_16 * V_17 , T_1 * V_18 , int V_19 )
{
struct V_12 * V_13 = F_6 ( V_11 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_3 && V_3 -> V_20 )
return V_3 -> V_20 ( V_13 -> V_15 -> V_13 ,
V_17 , V_18 , V_19 ) ;
return 0 ;
}
static int F_8 ( struct V_10 * V_11 , void * V_21 )
{
struct V_12 * V_13 = F_6 ( V_11 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_3 && V_3 -> V_22 )
return V_3 -> V_22 ( V_13 -> V_15 -> V_13 ,
V_21 ) ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 , int V_23 )
{
struct V_12 * V_13 = F_6 ( V_11 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_3 && V_3 -> V_24 )
return V_3 -> V_24 ( V_13 -> V_15 -> V_13 , V_23 ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_25 )
{
struct V_12 * V_13 = F_6 ( V_25 ) ;
struct V_26 * V_27 = & V_13 -> V_27 ;
struct V_28 * V_29 = & V_27 -> V_29 ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_9 && V_9 -> V_30 )
return V_9 -> V_30 ( V_13 -> V_31 -> V_13 ,
V_29 -> V_32 ) ;
return 0 ;
}
static void F_11 ( struct V_10 * V_25 )
{
struct V_12 * V_13 = F_6 ( V_25 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_9 && V_9 -> V_33 )
return V_9 -> V_33 ( V_13 -> V_31 -> V_13 ) ;
}
static void F_12 ( struct V_10 * V_25 , void * V_23 )
{
struct V_12 * V_13 = F_6 ( V_25 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_6 && V_6 -> V_34 )
V_6 -> V_34 ( V_13 -> V_15 -> V_13 , V_23 ) ;
}
static void F_13 ( struct V_10 * V_25 )
{
struct V_12 * V_13 = F_6 ( V_25 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_6 && V_6 -> V_35 )
V_6 -> V_35 ( V_13 -> V_15 -> V_13 ) ;
}
static void F_14 ( struct V_10 * V_25 , int V_23 )
{
struct V_12 * V_13 = F_6 ( V_25 ) ;
F_2 ( L_1 , __FILE__ ) ;
switch ( V_23 ) {
case V_36 :
break;
case V_37 :
case V_38 :
case V_39 :
if ( V_6 && V_6 -> V_40 )
V_6 -> V_40 ( V_13 -> V_15 -> V_13 ) ;
break;
default:
F_2 ( L_2 , V_23 ) ;
break;
}
}
static void F_15 ( struct V_10 * V_25 ,
struct V_41 * V_42 )
{
struct V_12 * V_13 = F_6 ( V_25 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_9 && V_9 -> V_43 )
V_9 -> V_43 ( V_13 -> V_31 -> V_13 , V_42 ) ;
}
static void F_16 ( struct V_10 * V_25 , int V_44 )
{
struct V_12 * V_13 = F_6 ( V_25 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_9 && V_9 -> V_45 )
V_9 -> V_45 ( V_13 -> V_31 -> V_13 , V_44 ) ;
}
static void F_17 ( struct V_10 * V_25 , int V_44 )
{
struct V_12 * V_13 = F_6 ( V_25 ) ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_9 && V_9 -> V_46 )
V_9 -> V_46 ( V_13 -> V_31 -> V_13 , V_44 ) ;
}
static int F_18 ( struct V_47 * V_48 ,
struct V_10 * V_11 )
{
struct V_26 * V_27 = F_19 ( V_11 ) ;
struct V_12 * V_13 ;
struct V_49 * V_50 = F_20 ( V_11 ) ;
struct V_51 * V_52 ;
int V_53 ;
F_2 ( L_1 , __FILE__ ) ;
V_52 = V_50 -> V_11 . V_54 ;
if ( ! V_52 ) {
F_2 ( L_3 ) ;
return - V_55 ;
}
if ( ! V_52 -> V_56 ) {
F_2 ( L_4 ) ;
return - V_55 ;
}
if ( ! V_52 -> V_57 ) {
F_2 ( L_5 ) ;
return - V_55 ;
}
V_53 = F_21 ( & V_58 ) ;
if ( V_53 ) {
F_2 ( L_6 ) ;
return V_53 ;
}
V_53 = F_21 ( & V_59 ) ;
if ( V_53 ) {
F_2 ( L_7 ) ;
goto V_60;
}
V_13 = F_22 ( V_27 ) ;
V_13 -> V_15 = (struct V_61 * )
F_6 ( V_52 -> V_56 ) ;
if ( ! V_13 -> V_15 ) {
F_2 ( L_8 ) ;
V_53 = - V_55 ;
goto V_62;
}
V_13 -> V_15 -> V_48 = V_48 ;
V_13 -> V_31 = (struct V_61 * )
F_6 ( V_52 -> V_57 ) ;
if ( ! V_13 -> V_31 ) {
F_2 ( L_9 ) ;
V_53 = - V_55 ;
goto V_62;
}
V_13 -> V_31 -> V_48 = V_48 ;
return 0 ;
V_62:
F_23 ( & V_59 ) ;
V_60:
F_23 ( & V_58 ) ;
return V_53 ;
}
static void F_24 ( struct V_47 * V_48 )
{
F_2 ( L_1 , __FILE__ ) ;
F_23 ( & V_58 ) ;
F_23 ( & V_59 ) ;
}
static void F_25 ( struct V_63 * V_64 )
{
struct V_12 * V_13 = F_26 ( V_64 ,
struct V_12 , V_64 ) ;
F_27 ( & V_13 -> V_27 ) ;
}
static int T_2 F_28 ( struct V_49 * V_50 )
{
struct V_10 * V_11 = & V_50 -> V_11 ;
struct V_26 * V_27 ;
struct V_12 * V_13 ;
F_2 ( L_1 , __FILE__ ) ;
V_13 = F_29 ( sizeof( * V_13 ) , V_65 ) ;
if ( ! V_13 ) {
F_30 ( L_10 ) ;
return - V_66 ;
}
V_27 = & V_13 -> V_27 ;
V_27 -> V_67 = F_18 ;
V_27 -> remove = F_24 ;
V_27 -> V_29 . V_32 = - 1 ;
V_27 -> V_29 . V_68 = & V_69 ;
V_27 -> V_29 . V_8 = & V_70 ;
V_27 -> V_29 . V_2 = & V_71 ;
V_27 -> V_29 . V_11 = V_11 ;
F_31 ( V_50 , V_27 ) ;
F_32 ( & V_13 -> V_64 , F_25 ) ;
F_33 ( & V_13 -> V_64 ) ;
return 0 ;
}
static int F_34 ( struct V_10 * V_11 )
{
F_2 ( L_1 , __FILE__ ) ;
return 0 ;
}
static int F_35 ( struct V_10 * V_11 )
{
F_2 ( L_1 , __FILE__ ) ;
return 0 ;
}
static int T_3 F_36 ( struct V_49 * V_50 )
{
struct V_12 * V_13 = F_37 ( V_50 ) ;
F_2 ( L_1 , __FILE__ ) ;
F_38 ( & V_13 -> V_27 ) ;
F_39 ( V_13 ) ;
return 0 ;
}
static int T_4 F_40 ( void )
{
int V_53 ;
F_2 ( L_1 , __FILE__ ) ;
V_53 = F_21 ( & V_72 ) ;
if ( V_53 ) {
F_2 ( L_11 ) ;
return V_53 ;
}
return V_53 ;
}
static void T_5 F_41 ( void )
{
F_23 ( & V_72 ) ;
}
