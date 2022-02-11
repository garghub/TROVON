static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 V_8 ;
struct V_9 * V_10 = F_2 ( V_6 ) ;
struct V_11 sin ;
struct V_12 V_13 ;
struct V_14 V_15 [ 2 ] ;
T_1 V_16 ;
int V_17 ;
F_3 ( L_1 ) ;
sin . V_18 = V_19 ;
sin . V_20 = F_4 ( V_6 ) -> V_21 ;
sin . V_22 . V_23 = F_5 ( V_6 ) -> V_24 ;
V_13 . V_25 = & sin ;
V_13 . V_26 = sizeof( sin ) ;
V_13 . V_27 = NULL ;
V_13 . V_28 = 0 ;
V_13 . V_29 = 0 ;
V_8 . V_30 = F_6 ( V_10 -> V_4 . V_30 ) ;
V_8 . V_31 = F_6 ( V_10 -> V_4 . V_31 ) ;
V_8 . V_32 = F_6 ( V_10 -> V_4 . V_32 ) ;
V_8 . V_33 = 0 ;
V_8 . V_34 = 0 ;
V_8 . type = V_35 ;
V_8 . V_36 = V_37 | ( ~ V_4 -> V_36 & V_38 ) ;
V_8 . V_39 = 0 ;
V_8 . V_40 = 0 ;
V_8 . V_41 = 0 ;
V_8 . V_42 = F_7 ( V_10 -> V_4 . V_42 ) ;
V_15 [ 0 ] . V_43 = & V_8 ;
V_15 [ 0 ] . V_44 = sizeof( V_8 ) ;
V_15 [ 1 ] . V_43 = ( char * ) V_45 ;
V_15 [ 1 ] . V_44 = sizeof( V_45 ) ;
V_16 = V_15 [ 0 ] . V_44 + V_15 [ 1 ] . V_44 ;
F_8 ( L_2 ) ;
V_17 = F_9 ( V_2 -> V_46 , & V_13 , V_15 , 2 , V_16 ) ;
if ( V_17 < 0 )
F_10 ( L_3 , V_17 ) ;
F_11 ( L_1 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
char V_47 ;
F_3 ( L_1 ) ;
V_6 = F_13 ( & V_2 -> V_48 ) ;
if ( V_6 ) {
struct V_9 * V_10 = F_2 ( V_6 ) ;
F_10 ( L_4 , V_2 -> V_49 , V_10 -> V_4 . type ) ;
switch ( V_10 -> V_4 . type ) {
case V_35 :
if ( F_14 ( V_6 , 0 , & V_47 , 1 ) < 0 )
return;
F_8 ( L_5 , V_47 ) ;
if ( V_47 == 0 )
F_1 ( V_2 , & V_10 -> V_4 , V_6 ) ;
break;
default:
break;
}
F_15 ( V_6 ) ;
}
F_11 ( L_1 ) ;
}
