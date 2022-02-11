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
V_13 = F_3 ( & V_2 -> V_17 ) ;
if ( ! V_13 ) {
F_4 ( L_2 ) ;
return;
}
F_5 ( V_13 ) ;
V_4 = F_6 ( V_13 ) ;
V_14 = * ( T_1 * ) ( F_7 ( V_13 ) + V_4 -> V_18 ) ;
V_15 = V_4 -> V_15 ;
F_8 ( L_3 , & V_14 , F_9 ( V_15 ) ) ;
F_10 ( L_4 , V_13 -> V_19 , V_13 -> V_20 ) ;
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
if ( V_4 -> V_21 . V_22 == V_23 &&
V_4 -> V_21 . V_24 == V_25 &&
V_4 -> V_21 . V_26 == V_27
) {
T_3 V_28 = V_4 -> V_21 . V_29 ;
F_8 ( L_7 , V_28 ) ;
if ( V_28 > 0 && V_11 -> V_30 == 65535 && V_28 < V_11 -> V_30 ) {
V_11 -> V_30 = V_28 ;
F_8 ( L_8 , V_28 ) ;
}
if ( V_28 == 0 ) {
V_28 = V_11 -> V_30 ;
if ( V_28 > 1500 ) {
V_28 >>= 1 ;
if ( V_28 < 1500 )
V_28 = 1500 ;
} else {
V_28 -= 100 ;
if ( V_28 < V_11 -> V_31 )
V_28 = V_11 -> V_31 + 4 ;
}
}
if ( V_28 < V_11 -> V_28 ) {
F_16 ( & V_11 -> V_32 ) ;
V_11 -> V_28 = V_28 ;
V_11 -> V_33 = V_11 -> V_28 - V_11 -> V_31 ;
F_17 ( & V_11 -> V_32 ) ;
F_8 ( L_9 ,
V_11 -> V_28 , V_11 -> V_33 ) ;
}
}
F_15 ( V_11 ) ;
F_18 ( & V_6 -> V_34 , V_13 ) ;
F_19 ( & V_6 -> V_35 ) ;
F_16 ( & V_2 -> V_17 . V_32 ) ;
V_2 -> V_36 = 0 ;
V_13 = F_20 ( & V_2 -> V_17 ) ;
if ( V_13 ) {
V_2 -> V_36 = F_6 ( V_13 ) -> V_21 . V_37 ;
F_17 ( & V_2 -> V_17 . V_32 ) ;
V_2 -> V_38 ( V_2 ) ;
} else {
F_17 ( & V_2 -> V_17 . V_32 ) ;
}
F_4 ( L_10 ) ;
}
void F_21 ( struct V_39 * V_40 )
{
struct V_41 * V_21 ;
struct V_3 * V_4 ;
struct V_5 * V_6 =
F_22 ( V_40 , struct V_5 , V_35 ) ;
struct V_12 * V_13 ;
int V_42 ;
F_2 ( L_10 ) ;
V_13 = F_3 ( & V_6 -> V_34 ) ;
if ( ! V_13 )
return;
V_4 = F_6 ( V_13 ) ;
V_21 = & V_4 -> V_21 ;
F_8 ( L_11 ,
V_21 -> V_22 , V_21 -> V_24 , V_21 -> V_26 , V_21 -> V_37 ) ;
V_42 = V_21 -> V_37 ;
switch ( V_21 -> V_22 ) {
case V_23 :
switch ( V_21 -> V_24 ) {
case V_25 :
switch ( V_21 -> V_26 ) {
case V_43 :
F_8 ( L_12 ) ;
V_42 = V_44 ;
break;
case V_45 :
F_8 ( L_13 ) ;
V_42 = V_46 ;
break;
case V_47 :
F_8 ( L_14 ) ;
V_42 = V_48 ;
break;
case V_27 :
F_8 ( L_7 ,
V_21 -> V_29 ) ;
V_42 = 0 ;
break;
case V_49 :
F_8 ( L_15 ) ;
V_42 = V_44 ;
break;
case V_50 :
F_8 ( L_16 ) ;
V_42 = V_46 ;
break;
default:
F_8 ( L_17 ,
V_21 -> V_26 ) ;
break;
}
break;
case V_51 :
F_8 ( L_18 ) ;
break;
default:
F_23 ( L_19 ,
V_21 -> V_24 , V_21 -> V_26 ) ;
break;
}
break;
case V_52 :
F_23 ( L_20 ,
V_21 -> V_37 ) ;
break;
case V_53 :
case V_54 :
default:
F_23 ( L_21 ,
V_21 -> V_22 ) ;
break;
}
if ( V_42 ) {
struct V_55 * V_56 , * V_57 ;
F_10 ( L_22 , V_42 ) ;
F_16 ( & V_6 -> V_11 -> V_32 ) ;
V_6 -> V_11 -> V_58 = V_42 ;
F_24 (call, _n, &trans->peer->error_targets,
error_link) {
F_25 ( & V_56 -> V_59 ) ;
if ( V_56 -> V_60 != V_61 &&
V_56 -> V_60 < V_62 ) {
V_56 -> V_60 = V_62 ;
F_26 ( V_63 , & V_56 -> V_64 ) ;
F_27 ( V_56 ) ;
}
F_28 ( & V_56 -> V_59 ) ;
F_29 ( & V_56 -> V_65 ) ;
}
F_17 ( & V_6 -> V_11 -> V_32 ) ;
}
if ( ! F_30 ( & V_6 -> V_34 ) )
F_19 ( & V_6 -> V_35 ) ;
F_13 ( V_13 ) ;
F_31 ( V_6 ) ;
F_4 ( L_10 ) ;
}
