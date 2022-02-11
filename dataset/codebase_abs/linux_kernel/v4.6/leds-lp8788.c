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
static int F_3 ( struct V_1 * V_2 ,
enum V_22 V_13 , int V_23 )
{
int V_11 ;
T_1 V_9 = 1 << V_13 ;
T_1 V_10 = V_23 << V_13 ;
V_11 = F_2 ( V_2 -> V_19 , V_17 , V_9 , V_10 ) ;
if ( V_11 == 0 )
V_2 -> V_23 = V_23 ;
return V_11 ;
}
static int F_4 ( struct V_24 * V_25 ,
enum V_26 V_10 )
{
struct V_1 * V_2 =
F_5 ( V_25 , struct V_1 , V_27 ) ;
enum V_22 V_13 = V_2 -> V_16 ;
int V_28 , V_11 ;
F_6 ( & V_2 -> V_29 ) ;
switch ( V_13 ) {
case V_30 :
case V_31 :
case V_32 :
V_11 = F_7 ( V_2 -> V_19 , V_33 [ V_13 ] , V_10 ) ;
if ( V_11 < 0 )
goto V_34;
break;
default:
F_8 ( & V_2 -> V_29 ) ;
return - V_35 ;
}
V_28 = ( V_10 > 0 ) ? 1 : 0 ;
if ( V_28 != V_2 -> V_23 )
V_11 = F_3 ( V_2 , V_13 , V_28 ) ;
V_34:
F_8 ( & V_2 -> V_29 ) ;
return V_11 ;
}
static int F_9 ( struct V_36 * V_37 )
{
struct V_38 * V_19 = F_10 ( V_37 -> V_39 . V_40 ) ;
struct V_3 * V_41 ;
struct V_1 * V_2 ;
struct V_42 * V_39 = & V_37 -> V_39 ;
int V_11 ;
V_2 = F_11 ( V_39 , sizeof( struct V_1 ) , V_43 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_27 . V_45 = V_46 ;
V_2 -> V_27 . V_47 = F_4 ;
V_41 = V_19 -> V_4 ? V_19 -> V_4 -> V_41 : NULL ;
if ( ! V_41 || ! V_41 -> V_48 )
V_2 -> V_27 . V_48 = V_49 ;
else
V_2 -> V_27 . V_48 = V_41 -> V_48 ;
F_12 ( & V_2 -> V_29 ) ;
V_11 = F_1 ( V_2 , V_41 ) ;
if ( V_11 ) {
F_13 ( V_39 , L_1 , V_11 ) ;
return V_11 ;
}
V_11 = F_14 ( V_39 , & V_2 -> V_27 ) ;
if ( V_11 ) {
F_13 ( V_39 , L_2 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
