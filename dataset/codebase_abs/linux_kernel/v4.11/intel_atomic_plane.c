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
int F_13 ( struct V_18 * V_19 ,
struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_6 . V_3 ;
struct V_20 * V_21 = F_14 ( V_3 -> V_16 ) ;
struct V_12 * V_4 = & V_13 -> V_6 ;
struct V_22 * V_22 = F_15 ( V_3 ) ;
int V_23 ;
if ( ! V_13 -> V_6 . V_24 && ! V_3 -> V_4 -> V_24 )
return 0 ;
V_13 -> V_25 . V_26 = 0 ;
V_13 -> V_25 . y1 = 0 ;
V_13 -> V_25 . V_27 =
V_19 -> V_6 . V_28 ? V_19 -> V_29 : 0 ;
V_13 -> V_25 . V_30 =
V_19 -> V_6 . V_28 ? V_19 -> V_31 : 0 ;
if ( V_4 -> V_32 && F_16 ( V_4 -> V_7 ) ) {
struct V_33 V_34 ;
if ( V_4 -> V_32 -> V_35 != V_36 &&
V_4 -> V_32 -> V_35 != V_37 ) {
F_17 ( L_1 ) ;
return - V_38 ;
}
switch ( V_4 -> V_32 -> V_39 -> V_39 ) {
case V_40 :
case V_41 :
F_17 ( L_2 ,
F_18 ( V_4 -> V_32 -> V_39 -> V_39 ,
& V_34 ) ) ;
return - V_38 ;
default:
break;
}
}
if ( F_19 ( V_21 ) &&
V_4 -> V_7 & V_42 &&
V_4 -> V_7 & V_43 ) {
F_17 ( L_3 ) ;
return - V_38 ;
}
V_13 -> V_6 . V_44 = false ;
V_23 = V_22 -> V_45 ( V_3 , V_19 , V_13 ) ;
if ( V_23 )
return V_23 ;
return F_20 ( & V_19 -> V_6 , V_4 ) ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_12 * V_4 )
{
struct V_46 * V_24 = V_4 -> V_24 ;
struct V_47 * V_47 ;
V_24 = V_24 ? V_24 : V_3 -> V_4 -> V_24 ;
if ( ! V_24 )
return 0 ;
V_47 = F_22 ( V_4 -> V_4 , V_24 ) ;
if ( F_23 ( ! V_47 ) )
return - V_38 ;
return F_13 ( F_24 ( V_47 ) ,
F_8 ( V_4 ) ) ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_12 * V_48 )
{
struct V_22 * V_22 = F_15 ( V_3 ) ;
struct V_1 * V_13 =
F_8 ( V_3 -> V_4 ) ;
struct V_46 * V_24 = V_3 -> V_4 -> V_24 ? : V_48 -> V_24 ;
if ( V_13 -> V_6 . V_44 )
V_22 -> V_49 ( V_3 ,
F_24 ( V_24 -> V_4 ) ,
V_13 ) ;
else
V_22 -> V_50 ( V_3 , V_24 ) ;
}
int
F_26 ( struct V_2 * V_3 ,
const struct V_12 * V_4 ,
struct V_51 * V_52 ,
T_1 * V_53 )
{
F_17 ( L_4 , V_52 -> V_54 ) ;
return - V_38 ;
}
int
F_27 ( struct V_2 * V_3 ,
struct V_12 * V_4 ,
struct V_51 * V_52 ,
T_1 V_53 )
{
F_17 ( L_4 , V_52 -> V_54 ) ;
return - V_38 ;
}
