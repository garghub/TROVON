static int F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 V_5 ;
int V_6 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_7 = V_4 -> V_7 ;
V_5 . V_8 = V_4 -> V_8 ;
V_5 . V_9 = V_4 -> V_9 ;
V_5 . V_10 = V_4 -> V_10 ;
V_5 . V_11 = V_5 . V_9 ;
V_5 . V_12 = V_4 -> V_12 ;
V_5 . V_13 = V_4 -> V_13 ;
V_5 . V_14 = V_4 -> V_14 ;
V_5 . V_15 = V_4 -> V_15 ;
V_5 . V_16 = V_4 -> V_16 ;
V_5 . V_17 = V_5 . V_11 ;
if ( F_2 () ) {
V_5 . V_18 = V_4 -> V_18 ;
V_5 . V_19 = V_4 -> V_19 ;
}
V_5 . V_20 = V_4 -> V_20 ;
V_5 . V_21 = V_4 -> V_21 ;
V_5 . V_22 = V_4 -> V_22 ;
if ( V_2 -> V_23 == V_24 )
F_3 ( V_2 -> V_25 , V_26 , 1 ) ;
else
F_3 ( V_2 -> V_25 , V_26 , 0 ) ;
F_3 ( V_2 -> V_25 ,
V_27 , V_28 ) ;
F_3 ( V_2 -> V_25 , V_29 , 0 ) ;
V_6 = F_4 ( V_2 -> V_25 , & V_5 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static bool T_1 F_5 ( enum V_30 V_31 )
{
if ( ! F_2 () ) {
F_6 ( L_1 ) ;
return 0 ;
}
if ( ( V_31 == V_32 ) &&
( ! F_7 () || ( F_8 () == 0 ) ) ) {
F_6 ( L_2 ) ;
return 0 ;
}
return 1 ;
}
int T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 = 0 ;
struct V_33 * V_34 = & V_35 . V_34 ;
V_35 . V_34 . V_36 = V_2 ;
V_6 = F_10 ( V_2 -> V_25 , V_37 ,
( unsigned long * ) & V_38 [ 0 ] . V_39 ) ;
if ( V_6 < 0 ) {
F_11 ( V_34 , L_3 ) ;
return V_6 ;
}
V_38 [ 0 ] . V_40 = V_38 [ 0 ] . V_39 +
V_37 - 1 ;
V_38 [ 1 ] . V_39 =
F_12 ( V_41 ) ;
V_38 [ 2 ] . V_39 =
F_12 ( V_42 ) ;
if ( V_4 ) {
V_6 = F_1 ( V_2 , V_4 ) ;
if ( V_6 < 0 ) {
F_11 ( V_34 , L_4 , V_6 ) ;
return V_6 ;
}
}
if ( V_2 -> V_43 ) {
F_3 ( V_2 -> V_25 , V_44 , 1 ) ;
}
F_13 ( & V_2 -> V_45 , V_2 -> V_25 ) ;
if ( ! F_5 ( V_2 -> V_31 ) )
return - V_46 ;
V_6 = F_14 ( & V_35 ) ;
if ( V_6 < 0 ) {
F_11 ( V_34 , L_5 ) ;
goto V_47;
}
return 0 ;
V_47:
F_15 ( V_2 -> V_25 ) ;
return V_6 ;
}
