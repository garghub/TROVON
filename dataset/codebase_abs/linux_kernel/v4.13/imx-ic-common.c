static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_6 = F_2 ( & V_2 -> V_8 , sizeof( * V_6 ) , V_9 ) ;
if ( ! V_6 )
return - V_10 ;
F_3 ( V_2 , & V_6 -> V_11 ) ;
V_6 -> V_8 = & V_2 -> V_8 ;
V_4 = V_6 -> V_8 -> V_12 ;
V_6 -> V_13 = V_4 -> V_13 ;
switch ( V_4 -> V_14 ) {
case V_15 :
V_6 -> V_16 = V_17 ;
break;
case V_18 :
V_6 -> V_16 = V_19 ;
break;
case V_20 :
V_6 -> V_16 = V_21 ;
break;
default:
return - V_22 ;
}
F_4 ( & V_6 -> V_11 , V_23 [ V_6 -> V_16 ] -> V_24 ) ;
F_5 ( & V_6 -> V_11 , V_6 ) ;
V_6 -> V_11 . V_25 = V_23 [ V_6 -> V_16 ] -> V_25 ;
V_6 -> V_11 . V_26 . V_27 = V_23 [ V_6 -> V_16 ] -> V_28 ;
V_6 -> V_11 . V_26 . V_29 = V_30 ;
V_6 -> V_11 . V_8 = & V_2 -> V_8 ;
V_6 -> V_11 . V_31 = V_32 ;
V_6 -> V_11 . V_33 = V_34 | V_35 ;
V_6 -> V_11 . V_14 = V_4 -> V_14 ;
strncpy ( V_6 -> V_11 . V_36 , V_4 -> V_37 , sizeof( V_6 -> V_11 . V_36 ) ) ;
V_7 = V_23 [ V_6 -> V_16 ] -> F_6 ( V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_7 ( & V_6 -> V_11 ) ;
if ( V_7 )
V_23 [ V_6 -> V_16 ] -> remove ( V_6 ) ;
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_38 * V_11 = F_9 ( V_2 ) ;
struct V_5 * V_6 = F_10 ( V_11 , struct V_5 , V_11 ) ;
F_11 ( V_11 , L_1 ) ;
V_23 [ V_6 -> V_16 ] -> remove ( V_6 ) ;
F_12 ( V_11 ) ;
F_13 ( & V_11 -> V_26 ) ;
return 0 ;
}
