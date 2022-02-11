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
F_7 ( V_4 && F_8 ( V_4 ) -> V_14 ) ;
F_9 ( V_3 , V_4 ) ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_12 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_17 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_20 = F_11 ( V_3 ) ;
struct V_1 * V_13 = F_8 ( V_4 ) ;
struct V_21 * V_21 ;
int V_22 ;
V_16 = V_16 ? V_16 : V_3 -> V_4 -> V_16 ;
V_17 = F_12 ( V_16 ) ;
if ( ! V_16 )
return 0 ;
V_21 = F_13 ( V_4 -> V_4 , V_16 ) ;
if ( F_7 ( ! V_21 ) )
return - V_23 ;
V_19 = F_14 ( V_21 ) ;
V_13 -> V_24 . V_25 = 0 ;
V_13 -> V_24 . y1 = 0 ;
V_13 -> V_24 . V_26 =
V_19 -> V_6 . V_27 ? V_19 -> V_28 : 0 ;
V_13 -> V_24 . V_29 =
V_19 -> V_6 . V_27 ? V_19 -> V_30 : 0 ;
if ( V_4 -> V_31 && F_15 ( V_4 -> V_7 ) ) {
char * V_32 ;
if ( ! ( V_4 -> V_31 -> V_33 [ 0 ] == V_34 ||
V_4 -> V_31 -> V_33 [ 0 ] == V_35 ) ) {
F_16 ( L_1 ) ;
return - V_23 ;
}
switch ( V_4 -> V_31 -> V_36 ) {
case V_37 :
case V_38 :
V_32 = F_17 ( V_4 -> V_31 -> V_36 ) ;
F_16 ( L_2 , V_32 ) ;
F_18 ( V_32 ) ;
return - V_23 ;
default:
break;
}
}
V_13 -> V_6 . V_39 = false ;
V_22 = V_20 -> V_40 ( V_3 , V_19 , V_13 ) ;
if ( V_22 )
return V_22 ;
return F_19 ( & V_19 -> V_6 , V_4 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_12 * V_41 )
{
struct V_20 * V_20 = F_11 ( V_3 ) ;
struct V_1 * V_13 =
F_8 ( V_3 -> V_4 ) ;
struct V_15 * V_16 = V_3 -> V_4 -> V_16 ? : V_41 -> V_16 ;
if ( V_13 -> V_6 . V_39 )
V_20 -> V_42 ( V_3 ,
F_14 ( V_16 -> V_4 ) ,
V_13 ) ;
else
V_20 -> V_43 ( V_3 , V_16 ) ;
}
int
F_21 ( struct V_2 * V_3 ,
const struct V_12 * V_4 ,
struct V_44 * V_45 ,
T_1 * V_46 )
{
F_16 ( L_3 , V_45 -> V_47 ) ;
return - V_23 ;
}
int
F_22 ( struct V_2 * V_3 ,
struct V_12 * V_4 ,
struct V_44 * V_45 ,
T_1 V_46 )
{
F_16 ( L_3 , V_45 -> V_47 ) ;
return - V_23 ;
}
