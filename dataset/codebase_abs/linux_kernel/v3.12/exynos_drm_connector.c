static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_9 = NULL ;
unsigned int V_10 = 0 ;
int V_11 ;
if ( ! V_8 ) {
F_3 ( L_1 ) ;
return 0 ;
}
if ( V_8 -> V_12 ) {
V_9 = V_8 -> V_12 ( V_6 -> V_13 , V_2 ) ;
if ( F_4 ( V_9 ) ) {
V_11 = F_5 ( V_9 ) ;
V_9 = NULL ;
F_6 ( L_2 , V_11 ) ;
goto V_14;
}
V_10 = F_7 ( V_2 , V_9 ) ;
if ( ! V_10 ) {
F_6 ( L_3 , V_10 ) ;
goto V_14;
}
F_8 ( V_2 , V_9 ) ;
} else {
struct V_15 * V_16 ;
struct V_17 * V_18 = F_9 ( V_2 -> V_13 ) ;
if ( ! V_18 ) {
F_6 ( L_4 ) ;
return 0 ;
}
if ( V_8 -> V_19 )
V_16 = V_8 -> V_19 ( V_6 -> V_13 ) ;
else {
F_10 ( V_2 -> V_13 , V_18 ) ;
return 0 ;
}
F_11 ( & V_16 -> V_20 , V_18 ) ;
V_18 -> V_21 = V_16 -> V_21 ;
V_18 -> V_22 = V_16 -> V_22 ;
V_2 -> V_23 . V_21 = V_18 -> V_21 ;
V_2 -> V_23 . V_22 = V_18 -> V_22 ;
V_18 -> type = V_24 | V_25 ;
F_12 ( V_18 ) ;
F_13 ( V_2 , V_18 ) ;
V_10 = 1 ;
}
V_14:
F_14 ( V_9 ) ;
return V_10 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_11 = V_26 ;
F_3 ( L_5 , __FILE__ ) ;
if ( V_8 && V_8 -> V_27 )
if ( ! V_8 -> V_27 ( V_6 -> V_13 , V_18 ) )
V_11 = V_28 ;
return V_11 ;
}
struct V_29 * F_16 ( struct V_1 * V_2 )
{
struct V_30 * V_13 = V_2 -> V_13 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_31 * V_32 ;
struct V_29 * V_33 ;
V_32 = F_17 ( V_13 , V_4 -> V_34 ,
V_35 ) ;
if ( ! V_32 ) {
F_3 ( L_6 ,
V_4 -> V_34 ) ;
return NULL ;
}
V_33 = F_18 ( V_32 ) ;
return V_33 ;
}
void F_19 ( struct V_1 * V_2 , int V_18 )
{
struct V_29 * V_33 = F_16 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_5 * V_6 = F_20 ( V_33 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_36 == V_18 ) {
F_3 ( L_7 ) ;
return;
}
if ( V_8 && V_8 -> V_37 )
V_8 -> V_37 ( V_6 -> V_13 , V_18 ) ;
V_4 -> V_36 = V_18 ;
}
static void F_21 ( struct V_1 * V_2 ,
int V_18 )
{
F_22 ( V_2 , V_18 ) ;
F_19 ( V_2 , V_18 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned int V_38 , unsigned int V_39 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_40 * V_41 = V_6 -> V_41 ;
unsigned int V_42 , V_43 ;
V_42 = V_38 ;
V_43 = V_39 ;
if ( V_41 && V_41 -> V_44 )
V_41 -> V_44 ( V_6 -> V_13 , & V_42 , & V_43 ) ;
return F_24 ( V_2 , V_42 ,
V_43 ) ;
}
static enum V_45
F_25 ( struct V_1 * V_2 , bool V_46 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 =
V_6 -> V_8 ;
enum V_45 V_47 = V_48 ;
if ( V_8 && V_8 -> V_49 ) {
if ( V_8 -> V_49 ( V_6 -> V_13 ) )
V_47 = V_50 ;
else
V_47 = V_48 ;
}
return V_47 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_14 ( V_4 ) ;
}
struct V_1 * F_29 ( struct V_30 * V_13 ,
struct V_29 * V_33 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = F_20 ( V_33 ) ;
struct V_1 * V_2 ;
int type ;
int V_51 ;
V_4 = F_30 ( sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return NULL ;
V_2 = & V_4 -> V_1 ;
switch ( V_6 -> V_8 -> type ) {
case V_53 :
type = V_54 ;
V_2 -> V_55 = true ;
V_2 -> V_56 = V_57 ;
break;
case V_58 :
type = V_59 ;
V_2 -> V_56 = V_57 ;
break;
default:
type = V_60 ;
break;
}
F_31 ( V_13 , V_2 , & V_61 , type ) ;
F_32 ( V_2 , & V_62 ) ;
V_51 = F_33 ( V_2 ) ;
if ( V_51 )
goto V_63;
V_4 -> V_34 = V_33 -> V_64 . V_65 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_36 = V_66 ;
V_2 -> V_36 = V_66 ;
V_2 -> V_33 = V_33 ;
V_51 = F_34 ( V_2 , V_33 ) ;
if ( V_51 ) {
F_6 ( L_8 ) ;
goto V_67;
}
F_3 ( L_9 ) ;
return V_2 ;
V_67:
F_27 ( V_2 ) ;
V_63:
F_28 ( V_2 ) ;
F_14 ( V_4 ) ;
return NULL ;
}
