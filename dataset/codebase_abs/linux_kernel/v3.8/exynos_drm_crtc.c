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
F_21 ( & V_32 -> V_40 ) ;
F_22 ( & V_30 -> V_6 . V_38 ,
& V_34 -> V_41 ) ;
F_23 ( & V_32 -> V_40 ) ;
V_2 -> V_23 = V_23 ;
V_22 = F_12 ( V_2 , V_2 -> V_14 , V_2 -> V_15 ,
NULL ) ;
if ( V_22 ) {
V_2 -> V_23 = V_17 ;
F_21 ( & V_32 -> V_40 ) ;
F_24 ( V_32 , V_5 -> V_21 ) ;
F_20 ( & V_30 -> V_6 . V_38 ) ;
F_23 ( & V_32 -> V_40 ) ;
goto V_39;
}
}
V_39:
F_25 ( & V_32 -> V_37 ) ;
return V_22 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_33 * V_42 = V_2 -> V_32 -> V_35 ;
F_3 ( L_3 , __FILE__ ) ;
V_42 -> V_2 [ V_5 -> V_21 ] = NULL ;
F_27 ( V_2 ) ;
F_28 ( V_5 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
T_1 V_45 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_3 , V_46 ) ;
if ( V_44 == V_34 -> V_47 ) {
enum V_48 V_3 = V_45 ;
if ( V_3 == V_5 -> V_3 )
return 0 ;
V_5 -> V_3 = V_3 ;
switch ( V_3 ) {
case V_49 :
F_6 ( V_2 ) ;
break;
case V_50 :
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
static void F_30 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_43 * V_51 ;
F_3 ( L_3 , V_46 ) ;
V_51 = V_34 -> V_47 ;
if ( ! V_51 ) {
V_51 = F_31 ( V_32 , 0 , L_7 , V_52 ,
F_32 ( V_52 ) ) ;
if ( ! V_51 )
return;
V_34 -> V_47 = V_51 ;
}
F_33 ( & V_2 -> V_6 , V_51 , 0 ) ;
}
int F_34 ( struct V_31 * V_32 , unsigned int V_53 )
{
struct V_4 * V_5 ;
struct V_33 * V_42 = V_32 -> V_35 ;
struct V_1 * V_2 ;
F_3 ( L_3 , __FILE__ ) ;
V_5 = F_35 ( sizeof( * V_5 ) , V_54 ) ;
if ( ! V_5 ) {
F_13 ( L_8 ) ;
return - V_55 ;
}
V_5 -> V_21 = V_53 ;
V_5 -> V_8 = V_28 ;
V_5 -> V_11 = F_36 ( V_32 , 1 << V_53 , true ) ;
if ( ! V_5 -> V_11 ) {
F_28 ( V_5 ) ;
return - V_55 ;
}
V_2 = & V_5 -> V_1 ;
V_42 -> V_2 [ V_53 ] = V_2 ;
F_37 ( V_32 , V_2 , & V_56 ) ;
F_38 ( V_2 , & V_57 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
int F_39 ( struct V_31 * V_32 , int V_2 )
{
struct V_33 * V_42 = V_32 -> V_35 ;
struct V_4 * V_5 =
F_2 ( V_42 -> V_2 [ V_2 ] ) ;
F_3 ( L_3 , __FILE__ ) ;
if ( V_5 -> V_8 != V_10 )
return - V_27 ;
F_4 ( V_42 -> V_2 [ V_2 ] , & V_2 ,
V_58 ) ;
return 0 ;
}
void F_40 ( struct V_31 * V_32 , int V_2 )
{
struct V_33 * V_42 = V_32 -> V_35 ;
struct V_4 * V_5 =
F_2 ( V_42 -> V_2 [ V_2 ] ) ;
F_3 ( L_3 , __FILE__ ) ;
if ( V_5 -> V_8 != V_10 )
return;
F_4 ( V_42 -> V_2 [ V_2 ] , & V_2 ,
V_59 ) ;
}
void F_41 ( struct V_31 * V_32 , int V_2 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_29 * V_60 , * V_61 ;
struct V_62 V_63 ;
unsigned long V_64 ;
F_3 ( L_3 , __FILE__ ) ;
F_42 ( & V_32 -> V_40 , V_64 ) ;
F_43 (e, t, &dev_priv->pageflip_event_list,
base.link) {
if ( V_2 != V_60 -> V_21 )
continue;
F_44 ( & V_63 ) ;
V_60 -> V_30 . V_65 = 0 ;
V_60 -> V_30 . V_66 = V_63 . V_66 ;
V_60 -> V_30 . V_67 = V_63 . V_67 ;
F_45 ( & V_60 -> V_6 . V_38 , & V_60 -> V_6 . V_68 -> V_69 ) ;
F_46 ( & V_60 -> V_6 . V_68 -> V_70 ) ;
F_24 ( V_32 , V_2 ) ;
}
F_47 ( & V_32 -> V_40 , V_64 ) ;
}
