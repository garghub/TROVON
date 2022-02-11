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
return F_17 ( V_17 , V_4 -> V_30 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_31 , unsigned int V_32 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_33 , V_34 ;
V_33 = V_31 ;
V_34 = V_32 ;
if ( V_6 -> V_10 -> V_35 )
V_6 -> V_10 -> V_35 ( V_6 , & V_33 , & V_34 ) ;
return F_19 ( V_2 , V_33 ,
V_34 ) ;
}
static enum V_36
F_20 ( struct V_1 * V_2 , bool V_37 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
enum V_36 V_38 = V_39 ;
if ( V_6 -> V_10 -> V_40 ) {
if ( V_6 -> V_10 -> V_40 ( V_6 ) )
V_38 = V_41 ;
else
V_38 = V_39 ;
}
return V_38 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_13 ( V_4 ) ;
}
struct V_1 * F_24 ( struct V_29 * V_17 ,
struct V_28 * V_42 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = F_25 ( V_42 ) ;
struct V_1 * V_2 ;
int type ;
int V_43 ;
V_4 = F_26 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return NULL ;
V_2 = & V_4 -> V_1 ;
switch ( V_6 -> type ) {
case V_45 :
type = V_46 ;
V_2 -> V_47 = true ;
V_2 -> V_48 = V_49 ;
break;
case V_50 :
type = V_51 ;
V_2 -> V_48 = V_49 ;
break;
default:
type = V_52 ;
break;
}
F_27 ( V_17 , V_2 , & V_53 , type ) ;
F_28 ( V_2 , & V_54 ) ;
V_43 = F_29 ( V_2 ) ;
if ( V_43 )
goto V_55;
V_4 -> V_30 = V_42 -> V_56 . V_57 ;
V_4 -> V_6 = V_6 ;
V_2 -> V_58 = V_59 ;
V_2 -> V_42 = V_42 ;
V_43 = F_30 ( V_2 , V_42 ) ;
if ( V_43 ) {
F_5 ( L_5 ) ;
goto V_60;
}
F_15 ( L_6 ) ;
return V_2 ;
V_60:
F_22 ( V_2 ) ;
V_55:
F_23 ( V_2 ) ;
F_13 ( V_4 ) ;
return NULL ;
}
