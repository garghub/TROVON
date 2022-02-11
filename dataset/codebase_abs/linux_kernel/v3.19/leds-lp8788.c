static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_7 ;
T_1 V_8 , V_9 , V_10 ;
int V_11 ;
if ( V_4 ) {
V_6 -> V_12 = V_4 -> V_12 ;
V_6 -> V_13 = V_4 -> V_13 ;
V_6 -> V_14 = V_4 -> V_15 ;
}
V_2 -> V_16 = V_6 -> V_13 ;
V_8 = V_17 ;
V_9 = 1 << ( V_6 -> V_13 + V_18 ) ;
V_10 = V_6 -> V_12 << ( V_6 -> V_13 + V_18 ) ;
V_11 = F_2 ( V_2 -> V_19 , V_8 , V_9 , V_10 ) ;
if ( V_11 )
return V_11 ;
V_8 = V_20 [ V_6 -> V_13 ] ;
V_9 = V_21 [ V_6 -> V_13 ] ;
V_10 = V_6 -> V_14 ;
return F_2 ( V_2 -> V_19 , V_8 , V_9 , V_10 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
enum V_22 V_13 , int V_23 )
{
T_1 V_9 = 1 << V_13 ;
T_1 V_10 = V_23 << V_13 ;
if ( F_2 ( V_2 -> V_19 , V_17 , V_9 , V_10 ) )
return;
V_2 -> V_23 = V_23 ;
}
static void F_4 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_5 ( V_25 , struct V_1 , V_25 ) ;
enum V_22 V_13 = V_2 -> V_16 ;
int V_26 ;
T_1 V_10 = V_2 -> V_27 ;
F_6 ( & V_2 -> V_28 ) ;
switch ( V_13 ) {
case V_29 :
case V_30 :
case V_31 :
F_7 ( V_2 -> V_19 , V_32 [ V_13 ] , V_10 ) ;
break;
default:
F_8 ( & V_2 -> V_28 ) ;
return;
}
V_26 = ( V_10 > 0 ) ? 1 : 0 ;
if ( V_26 != V_2 -> V_23 )
F_3 ( V_2 , V_13 , V_26 ) ;
F_8 ( & V_2 -> V_28 ) ;
}
static void F_9 ( struct V_33 * V_34 ,
enum V_35 V_36 )
{
struct V_1 * V_2 =
F_5 ( V_34 , struct V_1 , V_37 ) ;
V_2 -> V_27 = V_36 ;
F_10 ( & V_2 -> V_25 ) ;
}
static int F_11 ( struct V_38 * V_39 )
{
struct V_40 * V_19 = F_12 ( V_39 -> V_41 . V_42 ) ;
struct V_3 * V_43 ;
struct V_1 * V_2 ;
struct V_44 * V_41 = & V_39 -> V_41 ;
int V_11 ;
V_2 = F_13 ( V_41 , sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_37 . V_47 = V_48 ;
V_2 -> V_37 . V_49 = F_9 ;
V_43 = V_19 -> V_4 ? V_19 -> V_4 -> V_43 : NULL ;
if ( ! V_43 || ! V_43 -> V_50 )
V_2 -> V_37 . V_50 = V_51 ;
else
V_2 -> V_37 . V_50 = V_43 -> V_50 ;
F_14 ( & V_2 -> V_28 ) ;
F_15 ( & V_2 -> V_25 , F_4 ) ;
F_16 ( V_39 , V_2 ) ;
V_11 = F_1 ( V_2 , V_43 ) ;
if ( V_11 ) {
F_17 ( V_41 , L_1 , V_11 ) ;
return V_11 ;
}
V_11 = F_18 ( V_41 , & V_2 -> V_37 ) ;
if ( V_11 ) {
F_17 ( V_41 , L_2 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static int F_19 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_20 ( V_39 ) ;
F_21 ( & V_2 -> V_37 ) ;
F_22 ( & V_2 -> V_25 ) ;
return 0 ;
}
