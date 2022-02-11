void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
T_1 V_14 ;
T_2 V_15 ;
F_2 ( L_1 , V_2 , V_8 -> V_16 ) ;
V_13 = F_3 ( V_2 ) ;
if ( ! V_13 ) {
F_4 ( L_2 ) ;
return;
}
F_5 ( V_13 ) ;
V_4 = F_6 ( V_13 ) ;
V_14 = * ( T_1 * ) ( F_7 ( V_13 ) + V_4 -> V_17 ) ;
V_15 = V_4 -> V_15 ;
F_8 ( L_3 , & V_14 , F_9 ( V_15 ) ) ;
F_10 ( L_4 , V_13 -> V_18 , V_13 -> V_19 ) ;
V_11 = F_11 ( V_8 , V_14 , V_15 ) ;
if ( F_12 ( V_11 ) ) {
F_13 ( V_13 ) ;
F_4 ( L_5 ) ;
return;
}
V_6 = F_14 ( V_8 , V_11 ) ;
if ( ! V_6 ) {
F_15 ( V_11 ) ;
F_13 ( V_13 ) ;
F_4 ( L_6 ) ;
return;
}
if ( V_4 -> V_20 . V_21 == V_22 &&
V_4 -> V_20 . V_23 == V_24 &&
V_4 -> V_20 . V_25 == V_26
) {
T_3 V_27 = V_4 -> V_20 . V_28 ;
F_8 ( L_7 , V_27 ) ;
if ( V_27 > 0 && V_11 -> V_29 == 65535 && V_27 < V_11 -> V_29 ) {
V_11 -> V_29 = V_27 ;
F_8 ( L_8 , V_27 ) ;
}
if ( V_27 == 0 ) {
V_27 = V_11 -> V_29 ;
if ( V_27 > 1500 ) {
V_27 >>= 1 ;
if ( V_27 < 1500 )
V_27 = 1500 ;
} else {
V_27 -= 100 ;
if ( V_27 < V_11 -> V_30 )
V_27 = V_11 -> V_30 + 4 ;
}
}
if ( V_27 < V_11 -> V_27 ) {
F_16 ( & V_11 -> V_31 ) ;
V_11 -> V_27 = V_27 ;
V_11 -> V_32 = V_11 -> V_27 - V_11 -> V_30 ;
F_17 ( & V_11 -> V_31 ) ;
F_8 ( L_9 ,
V_11 -> V_27 , V_11 -> V_32 ) ;
}
}
F_15 ( V_11 ) ;
F_18 ( & V_6 -> V_33 , V_13 ) ;
F_19 ( & V_6 -> V_34 ) ;
F_4 ( L_10 ) ;
}
void F_20 ( struct V_35 * V_36 )
{
struct V_37 * V_20 ;
struct V_3 * V_4 ;
struct V_5 * V_6 =
F_21 ( V_36 , struct V_5 , V_34 ) ;
struct V_12 * V_13 ;
int V_38 ;
F_2 ( L_10 ) ;
V_13 = F_22 ( & V_6 -> V_33 ) ;
if ( ! V_13 )
return;
V_4 = F_6 ( V_13 ) ;
V_20 = & V_4 -> V_20 ;
F_8 ( L_11 ,
V_20 -> V_21 , V_20 -> V_23 , V_20 -> V_25 , V_20 -> V_39 ) ;
V_38 = V_20 -> V_39 ;
switch ( V_20 -> V_21 ) {
case V_22 :
switch ( V_20 -> V_23 ) {
case V_24 :
switch ( V_20 -> V_25 ) {
case V_40 :
F_8 ( L_12 ) ;
V_38 = V_41 ;
break;
case V_42 :
F_8 ( L_13 ) ;
V_38 = V_43 ;
break;
case V_44 :
F_8 ( L_14 ) ;
V_38 = V_45 ;
break;
case V_26 :
F_8 ( L_7 ,
V_20 -> V_28 ) ;
V_38 = 0 ;
break;
case V_46 :
F_8 ( L_15 ) ;
V_38 = V_41 ;
break;
case V_47 :
F_8 ( L_16 ) ;
V_38 = V_43 ;
break;
default:
F_8 ( L_17 ,
V_20 -> V_25 ) ;
break;
}
break;
case V_48 :
F_8 ( L_18 ) ;
break;
default:
F_23 ( L_19 ,
V_20 -> V_23 , V_20 -> V_25 ) ;
break;
}
break;
case V_49 :
F_23 ( L_20 ,
V_20 -> V_39 ) ;
break;
case V_50 :
case V_51 :
default:
F_23 ( L_21 ,
V_20 -> V_21 ) ;
break;
}
if ( V_38 ) {
struct V_52 * V_53 , * V_54 ;
F_10 ( L_22 , V_38 ) ;
F_16 ( & V_6 -> V_11 -> V_31 ) ;
V_6 -> V_11 -> V_55 = V_38 ;
F_24 (call, _n, &trans->peer->error_targets,
error_link) {
F_25 ( & V_53 -> V_56 ) ;
if ( V_53 -> V_57 != V_58 &&
V_53 -> V_57 < V_59 ) {
V_53 -> V_57 = V_59 ;
F_26 ( V_60 , & V_53 -> V_61 ) ;
F_27 ( V_53 ) ;
}
F_28 ( & V_53 -> V_56 ) ;
F_29 ( & V_53 -> V_62 ) ;
}
F_17 ( & V_6 -> V_11 -> V_31 ) ;
}
if ( ! F_30 ( & V_6 -> V_33 ) )
F_19 ( & V_6 -> V_34 ) ;
F_13 ( V_13 ) ;
F_31 ( V_6 ) ;
F_4 ( L_10 ) ;
}
