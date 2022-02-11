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
F_7 ( F_8 ( V_4 ) -> V_14 ) ;
F_9 ( V_3 , V_4 ) ;
}
int F_10 ( struct V_15 * V_16 ,
struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_6 . V_3 ;
struct V_17 * V_18 = F_11 ( V_3 -> V_19 ) ;
struct V_12 * V_4 = & V_13 -> V_6 ;
struct V_20 * V_20 = F_12 ( V_3 ) ;
const struct V_21 * V_22 =
& V_16 -> V_6 . V_22 ;
int V_23 ;
if ( ! V_13 -> V_6 . V_24 && ! V_3 -> V_4 -> V_24 )
return 0 ;
V_13 -> V_25 . V_26 = 0 ;
V_13 -> V_25 . y1 = 0 ;
V_13 -> V_25 . V_27 =
V_16 -> V_6 . V_28 ? V_16 -> V_29 : 0 ;
V_13 -> V_25 . V_30 =
V_16 -> V_6 . V_28 ? V_16 -> V_31 : 0 ;
if ( V_4 -> V_32 && F_13 ( V_4 -> V_7 ) ) {
struct V_33 V_34 ;
if ( V_4 -> V_32 -> V_35 != V_36 &&
V_4 -> V_32 -> V_35 != V_37 ) {
F_14 ( L_1 ) ;
return - V_38 ;
}
switch ( V_4 -> V_32 -> V_39 -> V_39 ) {
case V_40 :
case V_41 :
F_14 ( L_2 ,
F_15 ( V_4 -> V_32 -> V_39 -> V_39 ,
& V_34 ) ) ;
return - V_38 ;
default:
break;
}
}
if ( F_16 ( V_18 ) &&
V_4 -> V_7 & V_42 &&
V_4 -> V_7 & V_43 ) {
F_14 ( L_3 ) ;
return - V_38 ;
}
V_13 -> V_6 . V_44 = false ;
V_23 = V_20 -> V_45 ( V_20 , V_16 , V_13 ) ;
if ( V_23 )
return V_23 ;
if ( V_4 -> V_32 && F_17 ( V_18 ) >= 9 && V_16 -> V_6 . V_28 &&
V_22 -> V_10 & V_46 ) {
if ( V_4 -> V_32 -> V_35 == V_36 ||
V_4 -> V_32 -> V_35 == V_37 ) {
F_14 ( L_4 ) ;
return - V_38 ;
}
}
if ( V_13 -> V_6 . V_44 )
V_16 -> V_47 |= F_18 ( V_20 -> V_48 ) ;
else
V_16 -> V_47 &= ~ F_18 ( V_20 -> V_48 ) ;
return F_19 ( & V_16 -> V_6 , V_4 ) ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_12 * V_4 )
{
struct V_49 * V_24 = V_4 -> V_24 ;
struct V_50 * V_50 ;
V_24 = V_24 ? V_24 : V_3 -> V_4 -> V_24 ;
if ( ! V_24 )
return 0 ;
V_50 = F_21 ( V_4 -> V_4 , V_24 ) ;
if ( F_7 ( ! V_50 ) )
return - V_38 ;
return F_10 ( F_22 ( V_50 ) ,
F_8 ( V_4 ) ) ;
}
static void F_23 ( struct V_2 * V_3 ,
struct V_12 * V_51 )
{
struct V_20 * V_20 = F_12 ( V_3 ) ;
struct V_1 * V_13 =
F_8 ( V_3 -> V_4 ) ;
struct V_49 * V_24 = V_3 -> V_4 -> V_24 ? : V_51 -> V_24 ;
if ( V_13 -> V_6 . V_44 ) {
F_24 ( V_3 ,
F_25 ( V_24 ) ) ;
V_20 -> V_52 ( V_20 ,
F_22 ( V_24 -> V_4 ) ,
V_13 ) ;
} else {
F_26 ( V_3 ,
F_25 ( V_24 ) ) ;
V_20 -> V_53 ( V_20 , F_25 ( V_24 ) ) ;
}
}
int
F_27 ( struct V_2 * V_3 ,
const struct V_12 * V_4 ,
struct V_54 * V_55 ,
T_1 * V_56 )
{
F_14 ( L_5 , V_55 -> V_57 ) ;
return - V_38 ;
}
int
F_28 ( struct V_2 * V_3 ,
struct V_12 * V_4 ,
struct V_54 * V_55 ,
T_1 V_56 )
{
F_14 ( L_5 , V_55 -> V_57 ) ;
return - V_38 ;
}
