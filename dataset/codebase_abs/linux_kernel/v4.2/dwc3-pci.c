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
V_26 = F_6 ( & V_2 -> V_27 , L_1 ) ;
if ( ! F_7 ( V_26 ) ) {
F_8 ( V_26 , 0 ) ;
F_9 ( V_26 , 1 ) ;
F_10 ( V_26 ) ;
}
V_26 = F_6 ( & V_2 -> V_27 , L_2 ) ;
if ( ! F_7 ( V_26 ) ) {
F_8 ( V_26 , 0 ) ;
F_9 ( V_26 , 1 ) ;
F_10 ( V_26 ) ;
F_11 ( 10000 , 11000 ) ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_29 ,
const struct V_30 * V_31 )
{
struct V_32 V_33 [ 2 ] ;
struct V_34 * V_35 ;
int V_36 ;
struct V_5 * V_27 = & V_29 -> V_27 ;
V_36 = F_13 ( V_29 ) ;
if ( V_36 ) {
F_14 ( V_27 , L_3 ) ;
return - V_37 ;
}
F_15 ( V_29 ) ;
V_35 = F_16 ( L_4 , V_38 ) ;
if ( ! V_35 ) {
F_14 ( V_27 , L_5 ) ;
return - V_39 ;
}
memset ( V_33 , 0x00 , sizeof( struct V_32 ) * F_17 ( V_33 ) ) ;
V_33 [ 0 ] . V_40 = F_18 ( V_29 , 0 ) ;
V_33 [ 0 ] . V_41 = F_19 ( V_29 , 0 ) ;
V_33 [ 0 ] . V_42 = L_6 ;
V_33 [ 0 ] . V_43 = V_44 ;
V_33 [ 1 ] . V_40 = V_29 -> V_45 ;
V_33 [ 1 ] . V_42 = L_6 ;
V_33 [ 1 ] . V_43 = V_46 ;
V_36 = F_20 ( V_35 , V_33 , F_17 ( V_33 ) ) ;
if ( V_36 ) {
F_14 ( V_27 , L_7 ) ;
return V_36 ;
}
F_21 ( V_29 , V_35 ) ;
V_36 = F_1 ( V_29 ) ;
if ( V_36 )
goto V_47;
V_35 -> V_27 . V_48 = V_27 ;
V_36 = F_22 ( V_35 ) ;
if ( V_36 ) {
F_14 ( V_27 , L_8 ) ;
goto V_47;
}
return 0 ;
V_47:
F_23 ( V_35 ) ;
return V_36 ;
}
static void F_24 ( struct V_1 * V_29 )
{
F_25 ( F_5 ( & V_29 -> V_27 ) ) ;
F_26 ( F_3 ( V_29 ) ) ;
}
