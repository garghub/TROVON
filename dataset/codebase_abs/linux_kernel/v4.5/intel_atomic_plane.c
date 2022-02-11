struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 . V_3 = V_3 ;
V_4 -> V_6 . V_7 = F_3 ( V_8 ) ;
V_4 -> V_9 . V_10 = V_11 ;
return V_4 ;
}
struct V_12 *
F_4 ( struct V_2 * V_3 )
{
struct V_12 * V_4 ;
struct V_1 * V_13 ;
V_13 = F_5 ( V_3 -> V_4 , sizeof( * V_13 ) , V_5 ) ;
if ( ! V_13 )
return NULL ;
V_4 = & V_13 -> V_6 ;
F_6 ( V_3 , V_4 ) ;
V_13 -> V_14 = NULL ;
return V_4 ;
}
void
F_7 ( struct V_2 * V_3 ,
struct V_12 * V_4 )
{
F_8 ( V_4 && F_9 ( V_4 ) -> V_14 ) ;
F_10 ( V_3 , V_4 ) ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_12 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_17 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_20 = F_12 ( V_3 ) ;
struct V_1 * V_13 = F_9 ( V_4 ) ;
struct V_21 * V_21 ;
int V_22 ;
V_16 = V_16 ? V_16 : V_3 -> V_4 -> V_16 ;
V_17 = F_13 ( V_16 ) ;
if ( ! V_16 )
return 0 ;
V_21 = F_14 ( V_4 -> V_4 , V_16 ) ;
if ( F_8 ( ! V_21 ) )
return - V_23 ;
V_19 = F_15 ( V_21 ) ;
V_13 -> V_24 . V_25 = V_4 -> V_26 ;
V_13 -> V_24 . y1 = V_4 -> V_27 ;
V_13 -> V_24 . V_28 = V_4 -> V_26 + V_4 -> V_29 ;
V_13 -> V_24 . V_30 = V_4 -> V_27 + V_4 -> V_31 ;
V_13 -> V_32 . V_25 = V_4 -> V_33 ;
V_13 -> V_32 . y1 = V_4 -> V_34 ;
V_13 -> V_32 . V_28 = V_4 -> V_33 + V_4 -> V_35 ;
V_13 -> V_32 . V_30 = V_4 -> V_34 + V_4 -> V_36 ;
V_13 -> V_37 . V_25 = 0 ;
V_13 -> V_37 . y1 = 0 ;
V_13 -> V_37 . V_28 =
V_19 -> V_6 . V_38 ? V_19 -> V_39 : 0 ;
V_13 -> V_37 . V_30 =
V_19 -> V_6 . V_38 ? V_19 -> V_40 : 0 ;
if ( V_4 -> V_41 && F_16 ( V_4 -> V_7 ) ) {
if ( ! ( V_4 -> V_41 -> V_42 [ 0 ] == V_43 ||
V_4 -> V_41 -> V_42 [ 0 ] == V_44 ) ) {
F_17 ( L_1 ) ;
return - V_23 ;
}
switch ( V_4 -> V_41 -> V_45 ) {
case V_46 :
case V_47 :
F_17 ( L_2 ,
F_18 ( V_4 -> V_41 -> V_45 ) ) ;
return - V_23 ;
default:
break;
}
}
V_13 -> V_48 = false ;
V_22 = V_20 -> V_49 ( V_3 , V_19 , V_13 ) ;
if ( V_22 )
return V_22 ;
return F_19 ( & V_19 -> V_6 , V_4 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_12 * V_50 )
{
struct V_20 * V_20 = F_12 ( V_3 ) ;
struct V_1 * V_13 =
F_9 ( V_3 -> V_4 ) ;
V_20 -> V_51 ( V_3 , V_13 ) ;
}
int
F_21 ( struct V_2 * V_3 ,
const struct V_12 * V_4 ,
struct V_52 * V_53 ,
T_1 * V_54 )
{
F_17 ( L_3 , V_53 -> V_55 ) ;
return - V_23 ;
}
int
F_22 ( struct V_2 * V_3 ,
struct V_12 * V_4 ,
struct V_52 * V_53 ,
T_1 V_54 )
{
F_17 ( L_3 , V_53 -> V_55 ) ;
return - V_23 ;
}
