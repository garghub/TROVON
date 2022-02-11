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
return V_4 ;
}
void
F_7 ( struct V_2 * V_3 ,
struct V_12 * V_4 )
{
F_8 ( V_3 , V_4 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
struct V_12 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_16 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_19 = F_10 ( V_3 ) ;
struct V_1 * V_13 = F_11 ( V_4 ) ;
struct V_20 * V_20 ;
int V_21 ;
V_15 = V_15 ? V_15 : V_3 -> V_4 -> V_15 ;
V_16 = F_12 ( V_15 ) ;
if ( ! V_15 )
return 0 ;
V_20 = F_13 ( V_4 -> V_4 , V_15 ) ;
if ( F_14 ( ! V_20 ) )
return - V_22 ;
V_18 = F_15 ( V_20 ) ;
V_13 -> V_23 . V_24 = V_4 -> V_25 ;
V_13 -> V_23 . y1 = V_4 -> V_26 ;
V_13 -> V_23 . V_27 = V_4 -> V_25 + V_4 -> V_28 ;
V_13 -> V_23 . V_29 = V_4 -> V_26 + V_4 -> V_30 ;
V_13 -> V_31 . V_24 = V_4 -> V_32 ;
V_13 -> V_31 . y1 = V_4 -> V_33 ;
V_13 -> V_31 . V_27 = V_4 -> V_32 + V_4 -> V_34 ;
V_13 -> V_31 . V_29 = V_4 -> V_33 + V_4 -> V_35 ;
V_13 -> V_36 . V_24 = 0 ;
V_13 -> V_36 . y1 = 0 ;
V_13 -> V_36 . V_27 =
V_18 -> V_6 . V_37 ? V_18 -> V_38 : 0 ;
V_13 -> V_36 . V_29 =
V_18 -> V_6 . V_37 ? V_18 -> V_39 : 0 ;
if ( V_4 -> V_40 && F_16 ( V_4 -> V_7 ) ) {
if ( ! ( V_4 -> V_40 -> V_41 [ 0 ] == V_42 ||
V_4 -> V_40 -> V_41 [ 0 ] == V_43 ) ) {
F_17 ( L_1 ) ;
return - V_22 ;
}
switch ( V_4 -> V_40 -> V_44 ) {
case V_45 :
case V_46 :
F_17 ( L_2 ,
F_18 ( V_4 -> V_40 -> V_44 ) ) ;
return - V_22 ;
default:
break;
}
}
V_13 -> V_47 = false ;
V_21 = V_19 -> V_48 ( V_3 , V_18 , V_13 ) ;
if ( V_21 )
return V_21 ;
return F_19 ( & V_18 -> V_6 , V_4 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_12 * V_49 )
{
struct V_19 * V_19 = F_10 ( V_3 ) ;
struct V_1 * V_13 =
F_11 ( V_3 -> V_4 ) ;
V_19 -> V_50 ( V_3 , V_13 ) ;
}
int
F_21 ( struct V_2 * V_3 ,
const struct V_12 * V_4 ,
struct V_51 * V_52 ,
T_1 * V_53 )
{
F_17 ( L_3 , V_52 -> V_54 ) ;
return - V_22 ;
}
int
F_22 ( struct V_2 * V_3 ,
struct V_12 * V_4 ,
struct V_51 * V_52 ,
T_1 V_53 )
{
F_17 ( L_3 , V_52 -> V_54 ) ;
return - V_22 ;
}
