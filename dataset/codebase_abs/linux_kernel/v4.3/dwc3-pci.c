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
return 0 ;
}
static int F_12 ( struct V_1 * V_30 ,
const struct V_31 * V_32 )
{
struct V_33 V_34 [ 2 ] ;
struct V_35 * V_36 ;
int V_37 ;
struct V_5 * V_27 = & V_30 -> V_27 ;
V_37 = F_13 ( V_30 ) ;
if ( V_37 ) {
F_14 ( V_27 , L_3 ) ;
return - V_38 ;
}
F_15 ( V_30 ) ;
V_36 = F_16 ( L_4 , V_39 ) ;
if ( ! V_36 ) {
F_14 ( V_27 , L_5 ) ;
return - V_40 ;
}
memset ( V_34 , 0x00 , sizeof( struct V_33 ) * F_17 ( V_34 ) ) ;
V_34 [ 0 ] . V_41 = F_18 ( V_30 , 0 ) ;
V_34 [ 0 ] . V_42 = F_19 ( V_30 , 0 ) ;
V_34 [ 0 ] . V_43 = L_6 ;
V_34 [ 0 ] . V_44 = V_45 ;
V_34 [ 1 ] . V_41 = V_30 -> V_46 ;
V_34 [ 1 ] . V_43 = L_6 ;
V_34 [ 1 ] . V_44 = V_47 ;
V_37 = F_20 ( V_36 , V_34 , F_17 ( V_34 ) ) ;
if ( V_37 ) {
F_14 ( V_27 , L_7 ) ;
return V_37 ;
}
F_21 ( V_30 , V_36 ) ;
V_37 = F_1 ( V_30 ) ;
if ( V_37 )
goto V_48;
V_36 -> V_27 . V_49 = V_27 ;
V_37 = F_22 ( V_36 ) ;
if ( V_37 ) {
F_14 ( V_27 , L_8 ) ;
goto V_48;
}
return 0 ;
V_48:
F_23 ( V_36 ) ;
return V_37 ;
}
static void F_24 ( struct V_1 * V_30 )
{
F_25 ( F_5 ( & V_30 -> V_27 ) ) ;
F_26 ( F_3 ( V_30 ) ) ;
}
