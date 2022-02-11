static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_7 = NULL ;
unsigned int V_8 = 0 ;
int V_9 ;
if ( V_6 -> V_10 -> V_11 ) {
V_7 = V_6 -> V_10 -> V_11 ( V_6 , V_2 ) ;
if ( F_3 ( V_7 ) ) {
V_9 = F_4 ( V_7 ) ;
V_7 = NULL ;
F_5 ( L_1 , V_9 ) ;
goto V_12;
}
V_8 = F_6 ( V_2 , V_7 ) ;
if ( ! V_8 ) {
F_5 ( L_2 , V_8 ) ;
goto V_12;
}
F_7 ( V_2 , V_7 ) ;
} else {
struct V_13 * V_14 ;
struct V_15 * V_16 = F_8 ( V_2 -> V_17 ) ;
if ( ! V_16 ) {
F_5 ( L_3 ) ;
return 0 ;
}
if ( V_6 -> V_10 -> V_18 )
V_14 = V_6 -> V_10 -> V_18 ( V_6 ) ;
else {
F_9 ( V_2 -> V_17 , V_16 ) ;
return 0 ;
}
F_10 ( & V_14 -> V_19 , V_16 ) ;
V_16 -> V_20 = V_14 -> V_20 ;
V_16 -> V_21 = V_14 -> V_21 ;
V_2 -> V_22 . V_20 = V_16 -> V_20 ;
V_2 -> V_22 . V_21 = V_16 -> V_21 ;
V_16 -> type = V_23 | V_24 ;
F_11 ( V_16 ) ;
F_12 ( V_2 , V_16 ) ;
V_8 = 1 ;
}
V_12:
F_13 ( V_7 ) ;
return V_8 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_9 = V_25 ;
F_15 ( L_4 , __FILE__ ) ;
if ( V_6 -> V_10 -> V_26 )
if ( ! V_6 -> V_10 -> V_26 ( V_6 , V_16 ) )
V_9 = V_27 ;
return V_9 ;
}
static struct V_28 * F_16 (
struct V_1 * V_2 )
{
struct V_29 * V_17 = V_2 -> V_17 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_30 * V_31 ;
struct V_28 * V_32 ;
V_31 = F_17 ( V_17 , V_4 -> V_33 ,
V_34 ) ;
if ( ! V_31 ) {
F_15 ( L_5 ,
V_4 -> V_33 ) ;
return NULL ;
}
V_32 = F_18 ( V_31 ) ;
return V_32 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned int V_35 , unsigned int V_36 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_37 , V_38 ;
V_37 = V_35 ;
V_38 = V_36 ;
if ( V_6 -> V_10 -> V_39 )
V_6 -> V_10 -> V_39 ( V_6 , & V_37 , & V_38 ) ;
return F_20 ( V_2 , V_37 ,
V_38 ) ;
}
static enum V_40
F_21 ( struct V_1 * V_2 , bool V_41 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
enum V_40 V_42 = V_43 ;
if ( V_6 -> V_10 -> V_44 ) {
if ( V_6 -> V_10 -> V_44 ( V_6 ) )
V_42 = V_45 ;
else
V_42 = V_43 ;
}
return V_42 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_13 ( V_4 ) ;
}
struct V_1 * F_25 ( struct V_29 * V_17 ,
struct V_28 * V_32 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = F_26 ( V_32 ) ;
struct V_1 * V_2 ;
int type ;
int V_46 ;
V_4 = F_27 ( sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 )
return NULL ;
V_2 = & V_4 -> V_1 ;
switch ( V_6 -> type ) {
case V_48 :
type = V_49 ;
V_2 -> V_50 = true ;
V_2 -> V_51 = V_52 ;
break;
case V_53 :
type = V_54 ;
V_2 -> V_51 = V_52 ;
break;
default:
type = V_55 ;
break;
}
F_28 ( V_17 , V_2 , & V_56 , type ) ;
F_29 ( V_2 , & V_57 ) ;
V_46 = F_30 ( V_2 ) ;
if ( V_46 )
goto V_58;
V_4 -> V_33 = V_32 -> V_59 . V_60 ;
V_4 -> V_6 = V_6 ;
V_2 -> V_61 = V_62 ;
V_2 -> V_32 = V_32 ;
V_46 = F_31 ( V_2 , V_32 ) ;
if ( V_46 ) {
F_5 ( L_6 ) ;
goto V_63;
}
F_15 ( L_7 ) ;
return V_2 ;
V_63:
F_23 ( V_2 ) ;
V_58:
F_24 ( V_2 ) ;
F_13 ( V_4 ) ;
return NULL ;
}
