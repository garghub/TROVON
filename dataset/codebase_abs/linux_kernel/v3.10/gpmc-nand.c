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
V_6 = F_3 ( V_2 -> V_23 , & V_5 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static bool F_4 ( enum V_24 V_25 )
{
if ( ! F_2 () && ! F_5 () ) {
F_6 ( L_1 ) ;
return 0 ;
}
if ( ( V_25 == V_26 ) &&
( ! F_7 () || ( F_8 () == 0 ) ) &&
( ! F_5 () ) ) {
F_6 ( L_2 ) ;
return 0 ;
}
return 1 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 = 0 ;
struct V_27 V_28 ;
struct V_29 * V_30 = & V_31 . V_30 ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_31 . V_30 . V_32 = V_2 ;
V_6 = F_10 ( V_2 -> V_23 , V_33 ,
( unsigned long * ) & V_34 [ 0 ] . V_35 ) ;
if ( V_6 < 0 ) {
F_11 ( V_30 , L_3 ,
V_2 -> V_23 , V_6 ) ;
return V_6 ;
}
V_34 [ 0 ] . V_36 = V_34 [ 0 ] . V_35 +
V_33 - 1 ;
V_34 [ 1 ] . V_35 =
F_12 ( V_37 ) ;
V_34 [ 2 ] . V_35 =
F_12 ( V_38 ) ;
if ( V_4 ) {
V_6 = F_1 ( V_2 , V_4 ) ;
if ( V_6 < 0 ) {
F_11 ( V_30 , L_4 , V_6 ) ;
return V_6 ;
}
if ( V_2 -> V_39 ) {
F_13 ( V_2 -> V_39 , & V_28 ) ;
} else {
V_28 . V_40 = true ;
if ( V_2 -> V_41 ) {
V_28 . V_42 = true ;
V_28 . V_43 = true ;
}
}
if ( V_2 -> V_44 == V_45 )
V_28 . V_46 = V_47 ;
else
V_28 . V_46 = V_48 ;
V_6 = F_14 ( V_2 -> V_23 , & V_28 ) ;
if ( V_6 < 0 )
goto V_49;
V_6 = F_15 ( V_50 , 0 ) ;
if ( V_6 < 0 )
goto V_49;
}
F_16 ( & V_2 -> V_51 , V_2 -> V_23 ) ;
if ( ! F_4 ( V_2 -> V_25 ) )
return - V_52 ;
V_6 = F_17 ( & V_31 ) ;
if ( V_6 < 0 ) {
F_11 ( V_30 , L_5 ) ;
goto V_49;
}
return 0 ;
V_49:
F_18 ( V_2 -> V_23 ) ;
return V_6 ;
}
