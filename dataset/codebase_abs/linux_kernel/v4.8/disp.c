int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( & V_4 -> V_7 ) ;
struct V_8 * V_9 = & V_4 -> V_10 . V_9 ;
struct V_11 * V_12 , * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 , V_23 ;
V_21 = F_3 ( sizeof( * V_21 ) , V_24 ) ;
if ( ! V_21 )
return - V_25 ;
F_4 ( & V_4 -> V_7 . V_26 ) ;
F_5 ( V_2 ) -> V_27 = V_21 ;
F_5 ( V_2 ) -> V_28 = V_29 ;
F_5 ( V_2 ) -> V_30 = V_31 ;
F_5 ( V_2 ) -> V_32 = V_33 ;
F_6 ( V_2 , 1 ) ;
F_7 ( V_2 , 0 ) ;
if ( F_8 ( V_2 ) )
F_7 ( V_2 , 1 ) ;
for ( V_22 = 0 ; V_22 < V_9 -> V_34 ; V_22 ++ ) {
struct V_35 * V_36 = & V_9 -> V_37 [ V_22 ] ;
V_12 = F_9 ( V_2 , V_36 -> V_12 ) ;
if ( F_10 ( V_12 ) )
continue;
switch ( V_36 -> type ) {
case V_38 :
V_23 = F_11 ( V_12 , V_36 ) ;
break;
case V_39 :
case V_40 :
V_23 = F_12 ( V_12 , V_36 ) ;
break;
case V_41 :
if ( V_36 -> V_42 == V_43 )
V_23 = F_13 ( V_12 , V_36 ) ;
else
V_23 = F_14 ( V_12 , V_36 ) ;
break;
default:
F_15 ( V_4 , L_1 , V_36 -> type ) ;
continue;
}
if ( V_23 )
continue;
}
F_16 (connector, ct,
&dev->mode_config.connector_list, head) {
if ( ! V_12 -> V_44 [ 0 ] ) {
F_15 ( V_4 , L_2 ,
V_12 -> V_45 ) ;
V_12 -> V_46 -> V_47 ( V_12 ) ;
}
}
F_17 (encoder, &dev->mode_config.encoder_list, head) {
struct V_16 * V_17 = V_16 ( V_15 ) ;
struct V_48 * V_49 =
F_18 ( V_6 , V_17 -> V_9 -> V_50 ) ;
V_17 -> V_6 = V_49 ? & V_49 -> V_6 : NULL ;
}
F_17 (crtc, &dev->mode_config.crtc_list, base.head)
V_19 -> V_51 ( & V_19 -> V_52 ) ;
F_17 (nv_encoder, &dev->mode_config.encoder_list, base.base.head)
V_17 -> V_53 ( & V_17 -> V_52 . V_52 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
void
V_29 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_20 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_16 * V_15 ;
struct V_18 * V_54 ;
F_17 (encoder, &dev->mode_config.encoder_list, base.base.head)
V_15 -> V_55 ( & V_15 -> V_52 . V_52 ) ;
F_17 (nv_crtc, &dev->mode_config.crtc_list, base.head)
V_54 -> V_56 ( & V_54 -> V_52 ) ;
F_6 ( V_2 , 0 ) ;
F_5 ( V_2 ) -> V_27 = NULL ;
F_20 ( V_21 ) ;
F_21 ( & V_4 -> V_7 . V_26 ) ;
}
int
V_31 ( struct V_1 * V_2 )
{
struct V_16 * V_15 ;
struct V_18 * V_19 ;
F_17 (crtc, &dev->mode_config.crtc_list, base.head)
V_19 -> V_51 ( & V_19 -> V_52 ) ;
F_17 (encoder, &dev->mode_config.encoder_list, base.base.head)
V_15 -> V_53 ( & V_15 -> V_52 . V_52 ) ;
return 0 ;
}
void
V_33 ( struct V_1 * V_2 )
{
F_22 ( V_2 , 0 , V_57 , 0 ) ;
if ( F_8 ( V_2 ) )
F_22 ( V_2 , 1 , V_57 , 0 ) ;
}
