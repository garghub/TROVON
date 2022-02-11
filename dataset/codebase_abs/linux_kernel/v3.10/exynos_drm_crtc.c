static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_1 , V_2 -> V_6 . V_7 , V_3 ) ;
if ( V_5 -> V_8 == V_3 ) {
F_3 ( L_2 ) ;
return;
}
if ( V_3 > V_9 ) {
F_4 ( V_5 -> V_10 ,
F_5 ( & V_5 -> V_11 ) == 0 ) ;
F_6 ( V_2 -> V_12 , V_5 -> V_13 ) ;
}
F_7 ( V_2 , & V_3 , V_14 ) ;
V_5 -> V_8 = V_3 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_3 ( L_3 , __FILE__ ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_3 , __FILE__ ) ;
F_1 ( V_2 , V_9 ) ;
F_10 ( V_5 -> V_15 ) ;
F_11 ( V_5 -> V_15 , V_9 ) ;
}
static bool
F_12 ( struct V_1 * V_2 ,
const struct V_16 * V_3 ,
struct V_16 * V_17 )
{
F_3 ( L_3 , __FILE__ ) ;
return true ;
}
static int
F_13 ( struct V_1 * V_2 , struct V_16 * V_3 ,
struct V_16 * V_17 , int V_18 , int V_19 ,
struct V_20 * V_21 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_22 * V_15 = V_5 -> V_15 ;
unsigned int V_23 ;
unsigned int V_24 ;
int V_13 = V_5 -> V_13 ;
int V_25 ;
F_3 ( L_3 , __FILE__ ) ;
memcpy ( & V_2 -> V_3 , V_17 , sizeof( * V_17 ) ) ;
V_23 = V_2 -> V_26 -> V_27 - V_18 ;
V_24 = V_2 -> V_26 -> V_28 - V_19 ;
V_25 = F_14 ( V_15 , V_2 , V_2 -> V_26 , 0 , 0 , V_23 , V_24 ,
V_18 , V_19 , V_23 , V_24 ) ;
if ( V_25 )
return V_25 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_26 = V_2 -> V_26 ;
F_7 ( V_2 , & V_13 , V_29 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_18 , int V_19 ,
struct V_20 * V_21 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_22 * V_15 = V_5 -> V_15 ;
unsigned int V_23 ;
unsigned int V_24 ;
int V_25 ;
F_3 ( L_3 , __FILE__ ) ;
if ( V_5 -> V_8 > V_9 ) {
F_16 ( L_4 ) ;
return - V_30 ;
}
V_23 = V_2 -> V_26 -> V_27 - V_18 ;
V_24 = V_2 -> V_26 -> V_28 - V_19 ;
V_25 = F_14 ( V_15 , V_2 , V_2 -> V_26 , 0 , 0 , V_23 , V_24 ,
V_18 , V_19 , V_23 , V_24 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_3 ( L_3 , __FILE__ ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_3 , __FILE__ ) ;
F_11 ( V_5 -> V_15 , V_31 ) ;
F_1 ( V_2 , V_31 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_20 * V_26 ,
struct V_32 * V_33 )
{
struct V_34 * V_12 = V_2 -> V_12 ;
struct V_35 * V_36 = V_12 -> V_37 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_26 ;
int V_25 = - V_38 ;
F_3 ( L_3 , __FILE__ ) ;
if ( V_5 -> V_8 > V_9 ) {
F_16 ( L_5 ) ;
return - V_38 ;
}
F_20 ( & V_12 -> V_39 ) ;
if ( V_33 ) {
V_33 -> V_13 = V_5 -> V_13 ;
V_25 = F_21 ( V_12 , V_5 -> V_13 ) ;
if ( V_25 ) {
F_22 ( L_6 ) ;
goto V_40;
}
F_23 ( & V_12 -> V_41 ) ;
F_24 ( & V_33 -> V_6 . V_42 ,
& V_36 -> V_43 ) ;
F_25 ( & V_5 -> V_11 , 1 ) ;
F_26 ( & V_12 -> V_41 ) ;
V_2 -> V_26 = V_26 ;
V_25 = F_15 ( V_2 , V_2 -> V_18 , V_2 -> V_19 ,
NULL ) ;
if ( V_25 ) {
V_2 -> V_26 = V_21 ;
F_23 ( & V_12 -> V_41 ) ;
F_27 ( V_12 , V_5 -> V_13 ) ;
F_28 ( & V_33 -> V_6 . V_42 ) ;
F_26 ( & V_12 -> V_41 ) ;
goto V_40;
}
}
V_40:
F_29 ( & V_12 -> V_39 ) ;
return V_25 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_35 * V_44 = V_2 -> V_12 -> V_37 ;
F_3 ( L_3 , __FILE__ ) ;
V_44 -> V_2 [ V_5 -> V_13 ] = NULL ;
F_31 ( V_2 ) ;
F_32 ( V_5 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
T_1 V_47 )
{
struct V_34 * V_12 = V_2 -> V_12 ;
struct V_35 * V_36 = V_12 -> V_37 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_3 , V_48 ) ;
if ( V_46 == V_36 -> V_49 ) {
enum V_50 V_3 = V_47 ;
if ( V_3 == V_5 -> V_3 )
return 0 ;
V_5 -> V_3 = V_3 ;
switch ( V_3 ) {
case V_51 :
F_9 ( V_2 ) ;
break;
case V_52 :
F_11 ( V_5 -> V_15 ,
V_31 ) ;
break;
default:
break;
}
return 0 ;
}
return - V_38 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_34 * V_12 = V_2 -> V_12 ;
struct V_35 * V_36 = V_12 -> V_37 ;
struct V_45 * V_53 ;
F_3 ( L_3 , V_48 ) ;
V_53 = V_36 -> V_49 ;
if ( ! V_53 ) {
V_53 = F_35 ( V_12 , 0 , L_7 , V_54 ,
F_36 ( V_54 ) ) ;
if ( ! V_53 )
return;
V_36 -> V_49 = V_53 ;
}
F_37 ( & V_2 -> V_6 , V_53 , 0 ) ;
}
int F_38 ( struct V_34 * V_12 , unsigned int V_55 )
{
struct V_4 * V_5 ;
struct V_35 * V_44 = V_12 -> V_37 ;
struct V_1 * V_2 ;
F_3 ( L_3 , __FILE__ ) ;
V_5 = F_39 ( sizeof( * V_5 ) , V_56 ) ;
if ( ! V_5 ) {
F_16 ( L_8 ) ;
return - V_57 ;
}
V_5 -> V_13 = V_55 ;
V_5 -> V_8 = V_31 ;
F_40 ( & V_5 -> V_10 ) ;
F_25 ( & V_5 -> V_11 , 0 ) ;
V_5 -> V_15 = F_41 ( V_12 , 1 << V_55 , true ) ;
if ( ! V_5 -> V_15 ) {
F_32 ( V_5 ) ;
return - V_57 ;
}
V_2 = & V_5 -> V_1 ;
V_44 -> V_2 [ V_55 ] = V_2 ;
F_42 ( V_12 , V_2 , & V_58 ) ;
F_43 ( V_2 , & V_59 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
int F_44 ( struct V_34 * V_12 , int V_2 )
{
struct V_35 * V_44 = V_12 -> V_37 ;
struct V_4 * V_5 =
F_2 ( V_44 -> V_2 [ V_2 ] ) ;
F_3 ( L_3 , __FILE__ ) ;
if ( V_5 -> V_8 != V_9 )
return - V_30 ;
F_7 ( V_44 -> V_2 [ V_2 ] , & V_2 ,
V_60 ) ;
return 0 ;
}
void F_45 ( struct V_34 * V_12 , int V_2 )
{
struct V_35 * V_44 = V_12 -> V_37 ;
struct V_4 * V_5 =
F_2 ( V_44 -> V_2 [ V_2 ] ) ;
F_3 ( L_3 , __FILE__ ) ;
if ( V_5 -> V_8 != V_9 )
return;
F_7 ( V_44 -> V_2 [ V_2 ] , & V_2 ,
V_61 ) ;
}
void F_46 ( struct V_34 * V_12 , int V_2 )
{
struct V_35 * V_36 = V_12 -> V_37 ;
struct V_32 * V_62 , * V_63 ;
struct V_1 * V_1 = V_36 -> V_2 [ V_2 ] ;
struct V_4 * V_5 = F_2 ( V_1 ) ;
unsigned long V_64 ;
F_3 ( L_3 , __FILE__ ) ;
F_47 ( & V_12 -> V_41 , V_64 ) ;
F_48 (e, t, &dev_priv->pageflip_event_list,
base.link) {
if ( V_2 != V_62 -> V_13 )
continue;
F_28 ( & V_62 -> V_6 . V_42 ) ;
F_49 ( V_12 , - 1 , V_62 ) ;
F_27 ( V_12 , V_2 ) ;
F_25 ( & V_5 -> V_11 , 0 ) ;
F_50 ( & V_5 -> V_10 ) ;
}
F_51 ( & V_12 -> V_41 , V_64 ) ;
}
