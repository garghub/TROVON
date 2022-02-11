static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( L_1 , V_2 -> V_8 . V_9 , V_3 ) ;
if ( V_7 -> V_10 == V_3 ) {
F_3 ( L_2 ) ;
return;
}
F_4 ( & V_5 -> V_11 ) ;
F_5 ( V_2 , & V_3 , V_12 ) ;
V_7 -> V_10 = V_3 ;
F_6 ( & V_5 -> V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_3 ( L_3 , __FILE__ ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( L_3 , __FILE__ ) ;
F_9 ( V_7 -> V_13 ) ;
F_10 ( V_7 -> V_13 , V_14 ) ;
}
static bool
F_11 ( struct V_1 * V_2 ,
const struct V_15 * V_3 ,
struct V_15 * V_16 )
{
F_3 ( L_3 , __FILE__ ) ;
return true ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_15 * V_3 ,
struct V_15 * V_16 , int V_17 , int V_18 ,
struct V_19 * V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_21 * V_13 = V_7 -> V_13 ;
unsigned int V_22 ;
unsigned int V_23 ;
int V_24 = V_7 -> V_24 ;
int V_25 ;
F_3 ( L_3 , __FILE__ ) ;
F_1 ( V_2 , V_14 ) ;
memcpy ( & V_2 -> V_3 , V_16 , sizeof( * V_16 ) ) ;
V_22 = V_2 -> V_26 -> V_27 - V_17 ;
V_23 = V_2 -> V_26 -> V_28 - V_18 ;
V_25 = F_13 ( V_13 , V_2 , V_2 -> V_26 , 0 , 0 , V_22 , V_23 ,
V_17 , V_18 , V_22 , V_23 ) ;
if ( V_25 )
return V_25 ;
V_13 -> V_2 = V_2 ;
V_13 -> V_26 = V_2 -> V_26 ;
F_5 ( V_2 , & V_24 , V_29 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_17 , int V_18 ,
struct V_19 * V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_21 * V_13 = V_7 -> V_13 ;
unsigned int V_22 ;
unsigned int V_23 ;
int V_25 ;
F_3 ( L_3 , __FILE__ ) ;
V_22 = V_2 -> V_26 -> V_27 - V_17 ;
V_23 = V_2 -> V_26 -> V_28 - V_18 ;
V_25 = F_13 ( V_13 , V_2 , V_2 -> V_26 , 0 , 0 , V_22 , V_23 ,
V_17 , V_18 , V_22 , V_23 ) ;
if ( V_25 )
return V_25 ;
F_8 ( V_2 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_3 ( L_3 , __FILE__ ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( L_3 , __FILE__ ) ;
F_10 ( V_7 -> V_13 , V_30 ) ;
F_1 ( V_2 , V_30 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_19 * V_26 ,
struct V_31 * V_32 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_33 * V_34 = V_5 -> V_35 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_19 * V_20 = V_2 -> V_26 ;
int V_25 = - V_36 ;
F_3 ( L_3 , __FILE__ ) ;
F_4 ( & V_5 -> V_11 ) ;
if ( V_32 ) {
V_32 -> V_24 = V_7 -> V_24 ;
V_25 = F_18 ( V_5 , V_7 -> V_24 ) ;
if ( V_25 ) {
F_19 ( L_4 ) ;
F_20 ( & V_32 -> V_8 . V_37 ) ;
goto V_38;
}
F_21 ( & V_32 -> V_8 . V_37 ,
& V_34 -> V_39 ) ;
V_2 -> V_26 = V_26 ;
V_25 = F_14 ( V_2 , V_2 -> V_17 , V_2 -> V_18 ,
NULL ) ;
if ( V_25 ) {
V_2 -> V_26 = V_20 ;
F_22 ( V_5 , V_7 -> V_24 ) ;
F_20 ( & V_32 -> V_8 . V_37 ) ;
goto V_38;
}
}
V_38:
F_6 ( & V_5 -> V_11 ) ;
return V_25 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_33 * V_40 = V_2 -> V_5 -> V_35 ;
F_3 ( L_3 , __FILE__ ) ;
V_40 -> V_2 [ V_7 -> V_24 ] = NULL ;
F_24 ( V_2 ) ;
F_25 ( V_7 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
T_1 V_43 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_33 * V_34 = V_5 -> V_35 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( L_3 , V_44 ) ;
if ( V_42 == V_34 -> V_45 ) {
enum V_46 V_3 = V_43 ;
if ( V_3 == V_7 -> V_3 )
return 0 ;
V_7 -> V_3 = V_3 ;
switch ( V_3 ) {
case V_47 :
F_8 ( V_2 ) ;
break;
case V_48 :
F_10 ( V_7 -> V_13 ,
V_30 ) ;
break;
default:
break;
}
return 0 ;
}
return - V_36 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_33 * V_34 = V_5 -> V_35 ;
struct V_41 * V_49 ;
F_3 ( L_3 , V_44 ) ;
V_49 = V_34 -> V_45 ;
if ( ! V_49 ) {
V_49 = F_28 ( V_5 , 0 , L_5 , V_50 ,
F_29 ( V_50 ) ) ;
if ( ! V_49 )
return;
V_34 -> V_45 = V_49 ;
}
F_30 ( & V_2 -> V_8 , V_49 , 0 ) ;
}
int F_31 ( struct V_4 * V_5 , unsigned int V_51 )
{
struct V_6 * V_7 ;
struct V_33 * V_40 = V_5 -> V_35 ;
struct V_1 * V_2 ;
F_3 ( L_3 , __FILE__ ) ;
V_7 = F_32 ( sizeof( * V_7 ) , V_52 ) ;
if ( ! V_7 ) {
F_33 ( L_6 ) ;
return - V_53 ;
}
V_7 -> V_24 = V_51 ;
V_7 -> V_10 = V_30 ;
V_7 -> V_13 = F_34 ( V_5 , 1 << V_51 , true ) ;
if ( ! V_7 -> V_13 ) {
F_25 ( V_7 ) ;
return - V_53 ;
}
V_2 = & V_7 -> V_1 ;
V_40 -> V_2 [ V_51 ] = V_2 ;
F_35 ( V_5 , V_2 , & V_54 ) ;
F_36 ( V_2 , & V_55 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
int F_37 ( struct V_4 * V_5 , int V_2 )
{
struct V_33 * V_40 = V_5 -> V_35 ;
struct V_6 * V_7 =
F_2 ( V_40 -> V_2 [ V_2 ] ) ;
F_3 ( L_3 , __FILE__ ) ;
if ( V_7 -> V_10 != V_14 )
return - V_56 ;
F_5 ( V_40 -> V_2 [ V_2 ] , & V_2 ,
V_57 ) ;
return 0 ;
}
void F_38 ( struct V_4 * V_5 , int V_2 )
{
struct V_33 * V_40 = V_5 -> V_35 ;
struct V_6 * V_7 =
F_2 ( V_40 -> V_2 [ V_2 ] ) ;
F_3 ( L_3 , __FILE__ ) ;
if ( V_7 -> V_10 != V_14 )
return;
F_5 ( V_40 -> V_2 [ V_2 ] , & V_2 ,
V_58 ) ;
}
