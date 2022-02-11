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
if ( V_4 -> V_11 )
F_7 ( V_4 -> V_11 ) ;
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
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_14 * V_14 ;
struct V_15 * V_15 = F_11 ( V_3 ) ;
struct V_1 * V_10 = F_12 ( V_4 ) ;
V_13 = V_13 ? V_13 : V_3 -> V_13 ;
V_14 = F_13 ( V_13 ) ;
if ( ! V_13 )
return 0 ;
V_10 -> V_16 . V_17 = V_4 -> V_18 ;
V_10 -> V_16 . y1 = V_4 -> V_19 ;
V_10 -> V_16 . V_20 = V_4 -> V_18 + V_4 -> V_21 ;
V_10 -> V_16 . V_22 = V_4 -> V_19 + V_4 -> V_23 ;
V_10 -> V_24 . V_17 = V_4 -> V_25 ;
V_10 -> V_24 . y1 = V_4 -> V_26 ;
V_10 -> V_24 . V_20 = V_4 -> V_25 + V_4 -> V_27 ;
V_10 -> V_24 . V_22 = V_4 -> V_26 + V_4 -> V_28 ;
V_10 -> V_29 . V_17 = 0 ;
V_10 -> V_29 . y1 = 0 ;
V_10 -> V_29 . V_20 =
V_14 -> V_30 ? V_14 -> V_31 -> V_32 : 0 ;
V_10 -> V_29 . V_22 =
V_14 -> V_30 ? V_14 -> V_31 -> V_33 : 0 ;
if ( V_4 -> V_11 == NULL && V_3 -> V_4 -> V_11 != NULL ) {
V_14 -> V_34 . V_35 |=
( 1 << F_14 ( V_3 ) ) ;
}
return V_15 -> V_36 ( V_3 , V_10 ) ;
}
static void F_15 ( struct V_2 * V_3 ,
struct V_9 * V_37 )
{
struct V_15 * V_15 = F_11 ( V_3 ) ;
struct V_1 * V_10 =
F_12 ( V_3 -> V_4 ) ;
if ( ! V_3 -> V_4 -> V_11 && ! V_37 -> V_11 )
return;
V_15 -> V_38 ( V_3 , V_10 ) ;
}
int
F_16 ( struct V_2 * V_3 ,
const struct V_9 * V_4 ,
struct V_39 * V_40 ,
T_1 * V_41 )
{
F_17 ( L_1 , V_40 -> V_42 ) ;
return - V_43 ;
}
int
F_18 ( struct V_2 * V_3 ,
struct V_9 * V_4 ,
struct V_39 * V_40 ,
T_1 V_41 )
{
F_17 ( L_1 , V_40 -> V_42 ) ;
return - V_43 ;
}
