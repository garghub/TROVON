static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_4 &&
V_2 -> V_5 == V_6 ) {
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_9 = true ;
V_8 . V_10 = 0xf ;
V_8 . V_11 = true ;
V_8 . V_12 = true ;
V_8 . V_13 = true ;
V_8 . V_14 = true ;
V_8 . V_15 = true ;
V_8 . V_16 = true ;
V_8 . V_17 = true ;
V_8 . V_18 = true ;
V_8 . V_19 = 1 ;
V_8 . V_20 = true ;
V_8 . V_21 = true ;
V_8 . V_22 = true ;
return F_2 ( F_3 ( V_2 ) , & V_8 ,
sizeof( V_8 ) ) ;
}
if ( V_2 -> V_3 == V_23 &&
V_2 -> V_5 == V_24 ) {
struct V_25 * V_26 ;
F_4 ( F_5 ( & V_2 -> V_27 ) ,
V_28 ) ;
V_26 = F_6 ( & V_2 -> V_27 , L_1 , V_29 ) ;
if ( F_7 ( V_26 ) )
return F_8 ( V_26 ) ;
F_9 ( V_26 , 1 ) ;
F_10 ( V_26 ) ;
V_26 = F_6 ( & V_2 -> V_27 , L_2 , V_29 ) ;
if ( F_7 ( V_26 ) )
return F_8 ( V_26 ) ;
if ( V_26 ) {
F_9 ( V_26 , 1 ) ;
F_10 ( V_26 ) ;
F_11 ( 10000 , 11000 ) ;
}
}
if ( V_2 -> V_3 == V_30 &&
( V_2 -> V_5 == V_31 ||
V_2 -> V_5 == V_32 ||
V_2 -> V_5 == V_33 ) ) {
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_34 = true ;
V_8 . V_9 = true ;
V_8 . V_35 = true ;
return F_2 ( F_3 ( V_2 ) , & V_8 ,
sizeof( V_8 ) ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_36 ,
const struct V_37 * V_38 )
{
struct V_39 V_40 [ 2 ] ;
struct V_41 * V_42 ;
int V_43 ;
struct V_5 * V_27 = & V_36 -> V_27 ;
V_43 = F_13 ( V_36 ) ;
if ( V_43 ) {
F_14 ( V_27 , L_3 ) ;
return - V_44 ;
}
F_15 ( V_36 ) ;
V_42 = F_16 ( L_4 , V_45 ) ;
if ( ! V_42 ) {
F_14 ( V_27 , L_5 ) ;
return - V_46 ;
}
memset ( V_40 , 0x00 , sizeof( struct V_39 ) * F_17 ( V_40 ) ) ;
V_40 [ 0 ] . V_47 = F_18 ( V_36 , 0 ) ;
V_40 [ 0 ] . V_48 = F_19 ( V_36 , 0 ) ;
V_40 [ 0 ] . V_49 = L_6 ;
V_40 [ 0 ] . V_50 = V_51 ;
V_40 [ 1 ] . V_47 = V_36 -> V_52 ;
V_40 [ 1 ] . V_49 = L_6 ;
V_40 [ 1 ] . V_50 = V_53 ;
V_43 = F_20 ( V_42 , V_40 , F_17 ( V_40 ) ) ;
if ( V_43 ) {
F_14 ( V_27 , L_7 ) ;
return V_43 ;
}
F_21 ( V_36 , V_42 ) ;
V_43 = F_1 ( V_36 ) ;
if ( V_43 )
goto V_54;
V_42 -> V_27 . V_55 = V_27 ;
F_22 ( & V_42 -> V_27 , F_5 ( V_27 ) ) ;
V_43 = F_23 ( V_42 ) ;
if ( V_43 ) {
F_14 ( V_27 , L_8 ) ;
goto V_54;
}
return 0 ;
V_54:
F_24 ( V_42 ) ;
return V_43 ;
}
static void F_25 ( struct V_1 * V_36 )
{
F_26 ( F_5 ( & V_36 -> V_27 ) ) ;
F_27 ( F_3 ( V_36 ) ) ;
}
