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
V_4 = F_5 ( V_13 ) ;
if ( ! V_13 -> V_17 && V_4 -> V_18 . V_19 == V_20 ) {
F_4 ( L_3 ) ;
F_6 ( V_13 ) ;
return;
}
F_7 ( V_13 ) ;
V_14 = * ( T_1 * ) ( F_8 ( V_13 ) + V_4 -> V_21 ) ;
V_15 = V_4 -> V_15 ;
F_9 ( L_4 , & V_14 , F_10 ( V_15 ) ) ;
F_11 ( L_5 , V_13 -> V_17 , V_13 -> V_22 ) ;
V_11 = F_12 ( V_8 , V_14 , V_15 ) ;
if ( F_13 ( V_11 ) ) {
F_14 ( V_13 ) ;
F_4 ( L_6 ) ;
return;
}
V_6 = F_15 ( V_8 , V_11 ) ;
if ( ! V_6 ) {
F_16 ( V_11 ) ;
F_14 ( V_13 ) ;
F_4 ( L_7 ) ;
return;
}
if ( V_4 -> V_18 . V_19 == V_23 &&
V_4 -> V_18 . V_24 == V_25 &&
V_4 -> V_18 . V_26 == V_27
) {
T_3 V_28 = V_4 -> V_18 . V_29 ;
F_9 ( L_8 , V_28 ) ;
if ( V_28 > 0 && V_11 -> V_30 == 65535 && V_28 < V_11 -> V_30 ) {
V_11 -> V_30 = V_28 ;
F_9 ( L_9 , V_28 ) ;
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
F_17 ( & V_11 -> V_32 ) ;
V_11 -> V_28 = V_28 ;
V_11 -> V_33 = V_11 -> V_28 - V_11 -> V_31 ;
F_18 ( & V_11 -> V_32 ) ;
F_9 ( L_10 ,
V_11 -> V_28 , V_11 -> V_33 ) ;
}
}
F_16 ( V_11 ) ;
F_19 ( & V_6 -> V_34 , V_13 ) ;
F_20 ( & V_6 -> V_35 ) ;
F_4 ( L_11 ) ;
}
void F_21 ( struct V_36 * V_37 )
{
struct V_38 * V_18 ;
struct V_3 * V_4 ;
struct V_5 * V_6 =
F_22 ( V_37 , struct V_5 , V_35 ) ;
struct V_12 * V_13 ;
int V_39 ;
F_2 ( L_11 ) ;
V_13 = F_23 ( & V_6 -> V_34 ) ;
if ( ! V_13 )
return;
V_4 = F_5 ( V_13 ) ;
V_18 = & V_4 -> V_18 ;
F_9 ( L_12 ,
V_18 -> V_19 , V_18 -> V_24 , V_18 -> V_26 , V_18 -> V_40 ) ;
V_39 = V_18 -> V_40 ;
switch ( V_18 -> V_19 ) {
case V_23 :
switch ( V_18 -> V_24 ) {
case V_25 :
switch ( V_18 -> V_26 ) {
case V_41 :
F_9 ( L_13 ) ;
V_39 = V_42 ;
break;
case V_43 :
F_9 ( L_14 ) ;
V_39 = V_44 ;
break;
case V_45 :
F_9 ( L_15 ) ;
V_39 = V_46 ;
break;
case V_27 :
F_9 ( L_8 ,
V_18 -> V_29 ) ;
V_39 = 0 ;
break;
case V_47 :
F_9 ( L_16 ) ;
V_39 = V_42 ;
break;
case V_48 :
F_9 ( L_17 ) ;
V_39 = V_44 ;
break;
default:
F_9 ( L_18 ,
V_18 -> V_26 ) ;
break;
}
break;
case V_49 :
F_9 ( L_19 ) ;
break;
default:
F_24 ( L_20 ,
V_18 -> V_24 , V_18 -> V_26 ) ;
break;
}
break;
case V_50 :
F_24 ( L_21 ,
V_18 -> V_40 ) ;
break;
case V_51 :
case V_52 :
default:
F_24 ( L_22 ,
V_18 -> V_19 ) ;
break;
}
if ( V_39 ) {
struct V_53 * V_54 , * V_55 ;
F_11 ( L_23 , V_39 ) ;
F_17 ( & V_6 -> V_11 -> V_32 ) ;
V_6 -> V_11 -> V_56 = V_39 ;
F_25 (call, _n, &trans->peer->error_targets,
error_link) {
F_26 ( & V_54 -> V_57 ) ;
if ( V_54 -> V_58 != V_59 &&
V_54 -> V_58 < V_60 ) {
V_54 -> V_58 = V_60 ;
F_27 ( V_61 , & V_54 -> V_62 ) ;
F_28 ( V_54 ) ;
}
F_29 ( & V_54 -> V_57 ) ;
F_30 ( & V_54 -> V_63 ) ;
}
F_18 ( & V_6 -> V_11 -> V_32 ) ;
}
if ( ! F_31 ( & V_6 -> V_34 ) )
F_20 ( & V_6 -> V_35 ) ;
F_14 ( V_13 ) ;
F_32 ( V_6 ) ;
F_4 ( L_11 ) ;
}
