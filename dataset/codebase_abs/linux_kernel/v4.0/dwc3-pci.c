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
return 0 ;
}
static int F_4 ( struct V_1 * V_23 ,
const struct V_24 * V_25 )
{
struct V_26 V_27 [ 2 ] ;
struct V_28 * V_29 ;
int V_30 ;
struct V_5 * V_31 = & V_23 -> V_31 ;
V_30 = F_5 ( V_23 ) ;
if ( V_30 ) {
F_6 ( V_31 , L_1 ) ;
return - V_32 ;
}
F_7 ( V_23 ) ;
V_29 = F_8 ( L_2 , V_33 ) ;
if ( ! V_29 ) {
F_6 ( V_31 , L_3 ) ;
return - V_34 ;
}
memset ( V_27 , 0x00 , sizeof( struct V_26 ) * F_9 ( V_27 ) ) ;
V_27 [ 0 ] . V_35 = F_10 ( V_23 , 0 ) ;
V_27 [ 0 ] . V_36 = F_11 ( V_23 , 0 ) ;
V_27 [ 0 ] . V_37 = L_4 ;
V_27 [ 0 ] . V_38 = V_39 ;
V_27 [ 1 ] . V_35 = V_23 -> V_40 ;
V_27 [ 1 ] . V_37 = L_4 ;
V_27 [ 1 ] . V_38 = V_41 ;
V_30 = F_12 ( V_29 , V_27 , F_9 ( V_27 ) ) ;
if ( V_30 ) {
F_6 ( V_31 , L_5 ) ;
return V_30 ;
}
F_13 ( V_23 , V_29 ) ;
V_30 = F_1 ( V_23 ) ;
if ( V_30 )
goto V_42;
V_29 -> V_31 . V_43 = V_31 ;
V_30 = F_14 ( V_29 ) ;
if ( V_30 ) {
F_6 ( V_31 , L_6 ) ;
goto V_42;
}
return 0 ;
V_42:
F_15 ( V_29 ) ;
return V_30 ;
}
static void F_16 ( struct V_1 * V_23 )
{
F_17 ( F_3 ( V_23 ) ) ;
}
