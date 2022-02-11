struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 . V_3 = V_3 ;
V_4 -> V_6 . V_7 = F_3 ( V_8 ) ;
return V_4 ;
}
struct V_9 *
F_4 ( struct V_2 * V_3 )
{
struct V_9 * V_4 ;
struct V_1 * V_10 ;
if ( F_5 ( ! V_3 -> V_4 ) )
V_10 = F_1 ( V_3 ) ;
else
V_10 = F_6 ( V_3 -> V_4 , sizeof( * V_10 ) ,
V_5 ) ;
if ( ! V_10 )
return NULL ;
V_4 = & V_10 -> V_6 ;
F_7 ( V_3 , V_4 ) ;
return V_4 ;
}
void
F_8 ( struct V_2 * V_3 ,
struct V_9 * V_4 )
{
F_9 ( V_3 , V_4 ) ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_9 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_13 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_16 = F_11 ( V_3 ) ;
struct V_1 * V_10 = F_12 ( V_4 ) ;
V_12 = V_12 ? V_12 : V_3 -> V_12 ;
V_13 = F_13 ( V_12 ) ;
if ( ! V_12 )
return 0 ;
if ( V_4 -> V_4 ) {
V_15 =
F_14 ( V_4 -> V_4 , V_13 ) ;
if ( F_15 ( V_15 ) )
return F_16 ( V_15 ) ;
} else {
V_15 = V_13 -> V_17 ;
}
V_10 -> V_18 . V_19 = V_4 -> V_20 ;
V_10 -> V_18 . y1 = V_4 -> V_21 ;
V_10 -> V_18 . V_22 = V_4 -> V_20 + V_4 -> V_23 ;
V_10 -> V_18 . V_24 = V_4 -> V_21 + V_4 -> V_25 ;
V_10 -> V_26 . V_19 = V_4 -> V_27 ;
V_10 -> V_26 . y1 = V_4 -> V_28 ;
V_10 -> V_26 . V_22 = V_4 -> V_27 + V_4 -> V_29 ;
V_10 -> V_26 . V_24 = V_4 -> V_28 + V_4 -> V_30 ;
V_10 -> V_31 . V_19 = 0 ;
V_10 -> V_31 . y1 = 0 ;
V_10 -> V_31 . V_22 =
V_15 -> V_6 . V_32 ? V_15 -> V_33 : 0 ;
V_10 -> V_31 . V_24 =
V_15 -> V_6 . V_32 ? V_15 -> V_34 : 0 ;
if ( V_4 -> V_35 == NULL && V_3 -> V_4 -> V_35 != NULL ) {
V_13 -> V_36 . V_37 |=
( 1 << F_17 ( V_3 ) ) ;
}
if ( V_4 -> V_35 && F_18 ( V_4 -> V_7 ) ) {
if ( ! ( V_4 -> V_35 -> V_38 [ 0 ] == V_39 ||
V_4 -> V_35 -> V_38 [ 0 ] == V_40 ) ) {
F_19 ( L_1 ) ;
return - V_41 ;
}
switch ( V_4 -> V_35 -> V_42 ) {
case V_43 :
case V_44 :
F_19 ( L_2 ,
F_20 ( V_4 -> V_35 -> V_42 ) ) ;
return - V_41 ;
default:
break;
}
}
return V_16 -> V_45 ( V_3 , V_10 ) ;
}
static void F_21 ( struct V_2 * V_3 ,
struct V_9 * V_46 )
{
struct V_16 * V_16 = F_11 ( V_3 ) ;
struct V_1 * V_10 =
F_12 ( V_3 -> V_4 ) ;
V_16 -> V_47 ( V_3 , V_10 ) ;
}
int
F_22 ( struct V_2 * V_3 ,
const struct V_9 * V_4 ,
struct V_48 * V_49 ,
T_1 * V_50 )
{
F_19 ( L_3 , V_49 -> V_51 ) ;
return - V_41 ;
}
int
F_23 ( struct V_2 * V_3 ,
struct V_9 * V_4 ,
struct V_48 * V_49 ,
T_1 V_50 )
{
F_19 ( L_3 , V_49 -> V_51 ) ;
return - V_41 ;
}
