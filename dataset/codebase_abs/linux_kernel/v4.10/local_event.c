static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 V_8 ;
struct V_9 * V_10 = F_2 ( V_6 ) ;
struct V_11 V_12 ;
struct V_13 V_14 ;
struct V_15 V_16 [ 2 ] ;
T_1 V_17 ;
int V_18 ;
F_3 ( L_1 ) ;
if ( F_4 ( & V_12 , V_6 ) < 0 )
return;
V_14 . V_19 = & V_12 . V_20 ;
V_14 . V_21 = V_12 . V_22 ;
V_14 . V_23 = NULL ;
V_14 . V_24 = 0 ;
V_14 . V_25 = 0 ;
V_8 . V_26 = F_5 ( V_10 -> V_4 . V_26 ) ;
V_8 . V_27 = F_5 ( V_10 -> V_4 . V_27 ) ;
V_8 . V_28 = F_5 ( V_10 -> V_4 . V_28 ) ;
V_8 . V_29 = 0 ;
V_8 . V_30 = 0 ;
V_8 . type = V_31 ;
V_8 . V_32 = V_33 | ( ~ V_4 -> V_32 & V_34 ) ;
V_8 . V_35 = 0 ;
V_8 . V_36 = 0 ;
V_8 . V_37 = 0 ;
V_8 . V_38 = F_6 ( V_10 -> V_4 . V_38 ) ;
V_16 [ 0 ] . V_39 = & V_8 ;
V_16 [ 0 ] . V_40 = sizeof( V_8 ) ;
V_16 [ 1 ] . V_39 = ( char * ) V_41 ;
V_16 [ 1 ] . V_40 = sizeof( V_41 ) ;
V_17 = V_16 [ 0 ] . V_40 + V_16 [ 1 ] . V_40 ;
F_7 ( L_2 ) ;
V_18 = F_8 ( V_2 -> V_42 , & V_14 , V_16 , 2 , V_17 ) ;
if ( V_18 < 0 )
F_9 ( L_3 , V_18 ) ;
F_10 ( L_1 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
char V_43 ;
F_3 ( L_1 ) ;
V_6 = F_12 ( & V_2 -> V_44 ) ;
if ( V_6 ) {
struct V_9 * V_10 = F_2 ( V_6 ) ;
F_13 ( V_6 , V_45 ) ;
F_9 ( L_4 , V_2 -> V_46 , V_10 -> V_4 . type ) ;
switch ( V_10 -> V_4 . type ) {
case V_31 :
if ( F_14 ( V_6 , sizeof( struct V_7 ) ,
& V_43 , 1 ) < 0 )
return;
F_7 ( L_5 , V_43 ) ;
if ( V_43 == 0 )
F_1 ( V_2 , & V_10 -> V_4 , V_6 ) ;
break;
default:
break;
}
F_15 ( V_6 , V_47 ) ;
}
F_10 ( L_1 ) ;
}
