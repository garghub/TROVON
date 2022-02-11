static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 == V_6 &&
V_2 -> V_7 == V_8 ) {
struct V_9 V_10 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_11 = true ;
V_10 . V_12 = 0xf ;
V_10 . V_13 = true ;
V_10 . V_14 = true ;
V_10 . V_15 = true ;
V_10 . V_16 = true ;
V_10 . V_17 = true ;
V_10 . V_18 = true ;
V_10 . V_19 = true ;
V_10 . V_20 = true ;
V_10 . V_21 = 1 ;
V_10 . V_22 = true ;
V_10 . V_23 = true ;
V_10 . V_24 = true ;
return F_2 ( V_4 , & V_10 , sizeof( V_10 ) ) ;
}
if ( V_2 -> V_5 == V_25 &&
V_2 -> V_7 == V_26 ) {
struct V_27 * V_28 ;
F_3 ( F_4 ( & V_2 -> V_29 ) ,
V_30 ) ;
V_28 = F_5 ( & V_2 -> V_29 , L_1 , V_31 ) ;
if ( F_6 ( V_28 ) )
return F_7 ( V_28 ) ;
F_8 ( V_28 , 1 ) ;
F_9 ( V_28 ) ;
V_28 = F_5 ( & V_2 -> V_29 , L_2 , V_31 ) ;
if ( F_6 ( V_28 ) )
return F_7 ( V_28 ) ;
if ( V_28 ) {
F_8 ( V_28 , 1 ) ;
F_9 ( V_28 ) ;
F_10 ( 10000 , 11000 ) ;
}
}
if ( V_2 -> V_5 == V_32 &&
( V_2 -> V_7 == V_33 ||
V_2 -> V_7 == V_34 ||
V_2 -> V_7 == V_35 ) ) {
struct V_9 V_10 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_36 = true ;
V_10 . V_11 = true ;
V_10 . V_37 = true ;
return F_2 ( V_4 , & V_10 , sizeof( V_10 ) ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_38 ,
const struct V_39 * V_40 )
{
struct V_41 V_42 [ 2 ] ;
struct V_3 * V_4 ;
int V_43 ;
struct V_7 * V_29 = & V_38 -> V_29 ;
V_43 = F_12 ( V_38 ) ;
if ( V_43 ) {
F_13 ( V_29 , L_3 ) ;
return - V_44 ;
}
F_14 ( V_38 ) ;
V_4 = F_15 ( L_4 , V_45 ) ;
if ( ! V_4 ) {
F_13 ( V_29 , L_5 ) ;
return - V_46 ;
}
memset ( V_42 , 0x00 , sizeof( struct V_41 ) * F_16 ( V_42 ) ) ;
V_42 [ 0 ] . V_47 = F_17 ( V_38 , 0 ) ;
V_42 [ 0 ] . V_48 = F_18 ( V_38 , 0 ) ;
V_42 [ 0 ] . V_49 = L_6 ;
V_42 [ 0 ] . V_50 = V_51 ;
V_42 [ 1 ] . V_47 = V_38 -> V_52 ;
V_42 [ 1 ] . V_49 = L_6 ;
V_42 [ 1 ] . V_50 = V_53 ;
V_43 = F_19 ( V_4 , V_42 , F_16 ( V_42 ) ) ;
if ( V_43 ) {
F_13 ( V_29 , L_7 ) ;
return V_43 ;
}
V_4 -> V_29 . V_54 = V_29 ;
F_20 ( & V_4 -> V_29 , F_4 ( V_29 ) ) ;
V_43 = F_1 ( V_38 , V_4 ) ;
if ( V_43 )
goto V_55;
V_43 = F_21 ( V_4 ) ;
if ( V_43 ) {
F_13 ( V_29 , L_8 ) ;
goto V_55;
}
F_22 ( V_38 , V_4 ) ;
return 0 ;
V_55:
F_23 ( V_4 ) ;
return V_43 ;
}
static void F_24 ( struct V_1 * V_38 )
{
F_25 ( F_4 ( & V_38 -> V_29 ) ) ;
F_26 ( F_27 ( V_38 ) ) ;
}
