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
int V_21 ;
if ( ! V_13 -> V_6 . V_22 && ! V_3 -> V_4 -> V_22 )
return 0 ;
V_13 -> V_23 . V_24 = 0 ;
V_13 -> V_23 . y1 = 0 ;
V_13 -> V_23 . V_25 =
V_16 -> V_6 . V_26 ? V_16 -> V_27 : 0 ;
V_13 -> V_23 . V_28 =
V_16 -> V_6 . V_26 ? V_16 -> V_29 : 0 ;
if ( V_4 -> V_30 && F_13 ( V_4 -> V_7 ) ) {
struct V_31 V_32 ;
if ( V_4 -> V_30 -> V_33 != V_34 &&
V_4 -> V_30 -> V_33 != V_35 ) {
F_14 ( L_1 ) ;
return - V_36 ;
}
switch ( V_4 -> V_30 -> V_37 -> V_37 ) {
case V_38 :
case V_39 :
F_14 ( L_2 ,
F_15 ( V_4 -> V_30 -> V_37 -> V_37 ,
& V_32 ) ) ;
return - V_36 ;
default:
break;
}
}
if ( F_16 ( V_18 ) &&
V_4 -> V_7 & V_40 &&
V_4 -> V_7 & V_41 ) {
F_14 ( L_3 ) ;
return - V_36 ;
}
V_13 -> V_6 . V_42 = false ;
V_21 = V_20 -> V_43 ( V_20 , V_16 , V_13 ) ;
if ( V_21 )
return V_21 ;
if ( V_13 -> V_6 . V_42 )
V_16 -> V_44 |= F_17 ( V_20 -> V_45 ) ;
else
V_16 -> V_44 &= ~ F_17 ( V_20 -> V_45 ) ;
return F_18 ( & V_16 -> V_6 , V_4 ) ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_12 * V_4 )
{
struct V_46 * V_22 = V_4 -> V_22 ;
struct V_47 * V_47 ;
V_22 = V_22 ? V_22 : V_3 -> V_4 -> V_22 ;
if ( ! V_22 )
return 0 ;
V_47 = F_20 ( V_4 -> V_4 , V_22 ) ;
if ( F_7 ( ! V_47 ) )
return - V_36 ;
return F_10 ( F_21 ( V_47 ) ,
F_8 ( V_4 ) ) ;
}
static void F_22 ( struct V_2 * V_3 ,
struct V_12 * V_48 )
{
struct V_20 * V_20 = F_12 ( V_3 ) ;
struct V_1 * V_13 =
F_8 ( V_3 -> V_4 ) ;
struct V_46 * V_22 = V_3 -> V_4 -> V_22 ? : V_48 -> V_22 ;
if ( V_13 -> V_6 . V_42 ) {
F_23 ( V_3 ,
F_24 ( V_22 ) ) ;
V_20 -> V_49 ( V_20 ,
F_21 ( V_22 -> V_4 ) ,
V_13 ) ;
} else {
F_25 ( V_3 ,
F_24 ( V_22 ) ) ;
V_20 -> V_50 ( V_20 , F_24 ( V_22 ) ) ;
}
}
int
F_26 ( struct V_2 * V_3 ,
const struct V_12 * V_4 ,
struct V_51 * V_52 ,
T_1 * V_53 )
{
F_14 ( L_4 , V_52 -> V_54 ) ;
return - V_36 ;
}
int
F_27 ( struct V_2 * V_3 ,
struct V_12 * V_4 ,
struct V_51 * V_52 ,
T_1 V_53 )
{
F_14 ( L_4 , V_52 -> V_54 ) ;
return - V_36 ;
}
