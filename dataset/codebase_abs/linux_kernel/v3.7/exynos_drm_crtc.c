static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_1 , V_2 -> V_6 . V_7 , V_3 ) ;
if ( V_5 -> V_8 == V_3 ) {
F_3 ( L_2 ) ;
return;
}
F_4 ( V_2 , & V_3 , V_9 ) ;
V_5 -> V_8 = V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( L_3 , __FILE__ ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_3 , __FILE__ ) ;
F_1 ( V_2 , V_10 ) ;
F_7 ( V_5 -> V_11 ) ;
F_8 ( V_5 -> V_11 , V_10 ) ;
}
static bool
F_9 ( struct V_1 * V_2 ,
const struct V_12 * V_3 ,
struct V_12 * V_13 )
{
F_3 ( L_3 , __FILE__ ) ;
return true ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_12 * V_3 ,
struct V_12 * V_13 , int V_14 , int V_15 ,
struct V_16 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_18 * V_11 = V_5 -> V_11 ;
unsigned int V_19 ;
unsigned int V_20 ;
int V_21 = V_5 -> V_21 ;
int V_22 ;
F_3 ( L_3 , __FILE__ ) ;
memcpy ( & V_2 -> V_3 , V_13 , sizeof( * V_13 ) ) ;
V_19 = V_2 -> V_23 -> V_24 - V_14 ;
V_20 = V_2 -> V_23 -> V_25 - V_15 ;
V_22 = F_11 ( V_11 , V_2 , V_2 -> V_23 , 0 , 0 , V_19 , V_20 ,
V_14 , V_15 , V_19 , V_20 ) ;
if ( V_22 )
return V_22 ;
V_11 -> V_2 = V_2 ;
V_11 -> V_23 = V_2 -> V_23 ;
F_4 ( V_2 , & V_21 , V_26 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_14 , int V_15 ,
struct V_16 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_18 * V_11 = V_5 -> V_11 ;
unsigned int V_19 ;
unsigned int V_20 ;
int V_22 ;
F_3 ( L_3 , __FILE__ ) ;
if ( V_5 -> V_8 > V_10 ) {
F_13 ( L_4 ) ;
return - V_27 ;
}
V_19 = V_2 -> V_23 -> V_24 - V_14 ;
V_20 = V_2 -> V_23 -> V_25 - V_15 ;
V_22 = F_11 ( V_11 , V_2 , V_2 -> V_23 , 0 , 0 , V_19 , V_20 ,
V_14 , V_15 , V_19 , V_20 ) ;
if ( V_22 )
return V_22 ;
F_6 ( V_2 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_3 ( L_3 , __FILE__ ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_3 , __FILE__ ) ;
F_8 ( V_5 -> V_11 , V_28 ) ;
F_1 ( V_2 , V_28 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_16 * V_23 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_23 ;
int V_22 = - V_36 ;
F_3 ( L_3 , __FILE__ ) ;
if ( V_5 -> V_8 > V_10 ) {
F_13 ( L_5 ) ;
return - V_36 ;
}
F_17 ( & V_32 -> V_37 ) ;
if ( V_30 ) {
V_30 -> V_21 = V_5 -> V_21 ;
V_22 = F_18 ( V_32 , V_5 -> V_21 ) ;
if ( V_22 ) {
F_19 ( L_6 ) ;
F_20 ( & V_30 -> V_6 . V_38 ) ;
goto V_39;
}
F_21 ( & V_30 -> V_6 . V_38 ,
& V_34 -> V_40 ) ;
V_2 -> V_23 = V_23 ;
V_22 = F_12 ( V_2 , V_2 -> V_14 , V_2 -> V_15 ,
NULL ) ;
if ( V_22 ) {
V_2 -> V_23 = V_17 ;
F_22 ( V_32 , V_5 -> V_21 ) ;
F_20 ( & V_30 -> V_6 . V_38 ) ;
goto V_39;
}
}
V_39:
F_23 ( & V_32 -> V_37 ) ;
return V_22 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_33 * V_41 = V_2 -> V_32 -> V_35 ;
F_3 ( L_3 , __FILE__ ) ;
V_41 -> V_2 [ V_5 -> V_21 ] = NULL ;
F_25 ( V_2 ) ;
F_26 ( V_5 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_42 * V_43 ,
T_1 V_44 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_3 , V_45 ) ;
if ( V_43 == V_34 -> V_46 ) {
enum V_47 V_3 = V_44 ;
if ( V_3 == V_5 -> V_3 )
return 0 ;
V_5 -> V_3 = V_3 ;
switch ( V_3 ) {
case V_48 :
F_6 ( V_2 ) ;
break;
case V_49 :
F_8 ( V_5 -> V_11 ,
V_28 ) ;
break;
default:
break;
}
return 0 ;
}
return - V_36 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_42 * V_50 ;
F_3 ( L_3 , V_45 ) ;
V_50 = V_34 -> V_46 ;
if ( ! V_50 ) {
V_50 = F_29 ( V_32 , 0 , L_7 , V_51 ,
F_30 ( V_51 ) ) ;
if ( ! V_50 )
return;
V_34 -> V_46 = V_50 ;
}
F_31 ( & V_2 -> V_6 , V_50 , 0 ) ;
}
int F_32 ( struct V_31 * V_32 , unsigned int V_52 )
{
struct V_4 * V_5 ;
struct V_33 * V_41 = V_32 -> V_35 ;
struct V_1 * V_2 ;
F_3 ( L_3 , __FILE__ ) ;
V_5 = F_33 ( sizeof( * V_5 ) , V_53 ) ;
if ( ! V_5 ) {
F_13 ( L_8 ) ;
return - V_54 ;
}
V_5 -> V_21 = V_52 ;
V_5 -> V_8 = V_28 ;
V_5 -> V_11 = F_34 ( V_32 , 1 << V_52 , true ) ;
if ( ! V_5 -> V_11 ) {
F_26 ( V_5 ) ;
return - V_54 ;
}
V_2 = & V_5 -> V_1 ;
V_41 -> V_2 [ V_52 ] = V_2 ;
F_35 ( V_32 , V_2 , & V_55 ) ;
F_36 ( V_2 , & V_56 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
int F_37 ( struct V_31 * V_32 , int V_2 )
{
struct V_33 * V_41 = V_32 -> V_35 ;
struct V_4 * V_5 =
F_2 ( V_41 -> V_2 [ V_2 ] ) ;
F_3 ( L_3 , __FILE__ ) ;
if ( V_5 -> V_8 != V_10 )
return - V_27 ;
F_4 ( V_41 -> V_2 [ V_2 ] , & V_2 ,
V_57 ) ;
return 0 ;
}
void F_38 ( struct V_31 * V_32 , int V_2 )
{
struct V_33 * V_41 = V_32 -> V_35 ;
struct V_4 * V_5 =
F_2 ( V_41 -> V_2 [ V_2 ] ) ;
F_3 ( L_3 , __FILE__ ) ;
if ( V_5 -> V_8 != V_10 )
return;
F_4 ( V_41 -> V_2 [ V_2 ] , & V_2 ,
V_58 ) ;
}
