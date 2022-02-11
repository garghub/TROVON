struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 . V_3 = V_3 ;
V_4 -> V_6 . V_7 = V_8 ;
V_4 -> V_9 . V_10 = V_11 ;
return V_4 ;
}
struct V_12 *
F_3 ( struct V_2 * V_3 )
{
struct V_12 * V_4 ;
struct V_1 * V_13 ;
V_13 = F_4 ( V_3 -> V_4 , sizeof( * V_13 ) , V_5 ) ;
if ( ! V_13 )
return NULL ;
V_4 = & V_13 -> V_6 ;
F_5 ( V_3 , V_4 ) ;
V_13 -> V_14 = NULL ;
return V_4 ;
}
void
F_6 ( struct V_2 * V_3 ,
struct V_12 * V_4 )
{
struct V_15 * V_14 ;
V_14 = F_7 ( & F_8 ( V_4 ) -> V_14 ) ;
if ( V_14 ) {
F_9 ( & V_3 -> V_16 -> V_17 ) ;
F_10 ( V_14 ) ;
F_11 ( & V_3 -> V_16 -> V_17 ) ;
}
F_12 ( V_3 , V_4 ) ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_12 * V_4 )
{
struct V_18 * V_19 = F_14 ( V_3 -> V_16 ) ;
struct V_20 * V_21 = V_4 -> V_21 ;
struct V_22 * V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_25 = F_15 ( V_3 ) ;
struct V_1 * V_13 = F_8 ( V_4 ) ;
struct V_26 * V_26 ;
int V_27 ;
V_21 = V_21 ? V_21 : V_3 -> V_4 -> V_21 ;
V_22 = F_16 ( V_21 ) ;
if ( ! V_21 )
return 0 ;
V_26 = F_17 ( V_4 -> V_4 , V_21 ) ;
if ( F_18 ( ! V_26 ) )
return - V_28 ;
V_24 = F_19 ( V_26 ) ;
V_13 -> V_29 . V_30 = 0 ;
V_13 -> V_29 . y1 = 0 ;
V_13 -> V_29 . V_31 =
V_24 -> V_6 . V_32 ? V_24 -> V_33 : 0 ;
V_13 -> V_29 . V_34 =
V_24 -> V_6 . V_32 ? V_24 -> V_35 : 0 ;
if ( V_4 -> V_36 && F_20 ( V_4 -> V_7 ) ) {
struct V_37 V_38 ;
if ( V_4 -> V_36 -> V_39 != V_40 &&
V_4 -> V_36 -> V_39 != V_41 ) {
F_21 ( L_1 ) ;
return - V_28 ;
}
switch ( V_4 -> V_36 -> V_42 ) {
case V_43 :
case V_44 :
F_21 ( L_2 ,
F_22 ( V_4 -> V_36 -> V_42 ,
& V_38 ) ) ;
return - V_28 ;
default:
break;
}
}
if ( F_23 ( V_19 ) &&
V_4 -> V_7 & V_45 &&
V_4 -> V_7 & V_46 ) {
F_21 ( L_3 ) ;
return - V_28 ;
}
V_13 -> V_6 . V_47 = false ;
V_27 = V_25 -> V_48 ( V_3 , V_24 , V_13 ) ;
if ( V_27 )
return V_27 ;
return F_24 ( & V_24 -> V_6 , V_4 ) ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_12 * V_49 )
{
struct V_25 * V_25 = F_15 ( V_3 ) ;
struct V_1 * V_13 =
F_8 ( V_3 -> V_4 ) ;
struct V_20 * V_21 = V_3 -> V_4 -> V_21 ? : V_49 -> V_21 ;
if ( V_13 -> V_6 . V_47 )
V_25 -> V_50 ( V_3 ,
F_19 ( V_21 -> V_4 ) ,
V_13 ) ;
else
V_25 -> V_51 ( V_3 , V_21 ) ;
}
int
F_26 ( struct V_2 * V_3 ,
const struct V_12 * V_4 ,
struct V_52 * V_53 ,
T_1 * V_54 )
{
F_21 ( L_4 , V_53 -> V_55 ) ;
return - V_28 ;
}
int
F_27 ( struct V_2 * V_3 ,
struct V_12 * V_4 ,
struct V_52 * V_53 ,
T_1 V_54 )
{
F_21 ( L_4 , V_53 -> V_55 ) ;
return - V_28 ;
}
