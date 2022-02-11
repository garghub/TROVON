int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( & V_4 -> V_7 . V_8 ) ;
struct V_9 * V_10 = & V_4 -> V_11 . V_10 ;
struct V_12 * V_13 , * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 , V_24 ;
V_22 = F_3 ( sizeof( * V_22 ) , V_25 ) ;
if ( ! V_22 )
return - V_26 ;
F_4 ( & V_4 -> V_7 . V_8 . V_27 ) ;
F_5 ( V_2 ) -> V_28 = V_22 ;
F_5 ( V_2 ) -> V_29 = V_30 ;
F_5 ( V_2 ) -> V_31 = V_32 ;
F_5 ( V_2 ) -> V_33 = V_34 ;
F_6 ( V_2 , 1 ) ;
F_7 ( V_2 , 0 ) ;
if ( F_8 ( V_2 ) )
F_7 ( V_2 , 1 ) ;
for ( V_23 = 0 ; V_23 < V_10 -> V_35 ; V_23 ++ ) {
struct V_36 * V_37 = & V_10 -> V_38 [ V_23 ] ;
V_13 = F_9 ( V_2 , V_37 -> V_13 ) ;
if ( F_10 ( V_13 ) )
continue;
switch ( V_37 -> type ) {
case V_39 :
V_24 = F_11 ( V_13 , V_37 ) ;
break;
case V_40 :
case V_41 :
V_24 = F_12 ( V_13 , V_37 ) ;
break;
case V_42 :
if ( V_37 -> V_43 == V_44 )
V_24 = F_13 ( V_13 , V_37 ) ;
else
V_24 = F_14 ( V_13 , V_37 ) ;
break;
default:
F_15 ( V_4 , L_1 , V_37 -> type ) ;
continue;
}
if ( V_24 )
continue;
}
F_16 (connector, ct,
&dev->mode_config.connector_list, head) {
if ( ! V_13 -> V_45 [ 0 ] ) {
F_15 ( V_4 , L_2 ,
V_13 -> V_46 ) ;
V_13 -> V_47 -> V_48 ( V_13 ) ;
}
}
F_17 (encoder, &dev->mode_config.encoder_list, head) {
struct V_17 * V_18 = V_17 ( V_16 ) ;
struct V_49 * V_50 =
F_18 ( V_6 , V_18 -> V_10 -> V_51 ) ;
V_18 -> V_6 = V_50 ? & V_50 -> V_6 : NULL ;
}
F_17 (crtc, &dev->mode_config.crtc_list, base.head)
V_20 -> V_52 ( & V_20 -> V_53 ) ;
F_17 (nv_encoder, &dev->mode_config.encoder_list, base.base.head)
V_18 -> V_54 ( & V_18 -> V_53 . V_53 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
void
V_30 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_21 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_17 * V_16 ;
struct V_19 * V_55 ;
F_17 (encoder, &dev->mode_config.encoder_list, base.base.head)
V_16 -> V_56 ( & V_16 -> V_53 . V_53 ) ;
F_17 (nv_crtc, &dev->mode_config.crtc_list, base.head)
V_55 -> V_57 ( & V_55 -> V_53 ) ;
F_6 ( V_2 , 0 ) ;
F_5 ( V_2 ) -> V_28 = NULL ;
F_20 ( V_22 ) ;
F_21 ( & V_4 -> V_7 . V_8 . V_27 ) ;
}
int
V_32 ( struct V_1 * V_2 )
{
struct V_17 * V_16 ;
struct V_19 * V_20 ;
F_17 (crtc, &dev->mode_config.crtc_list, base.head)
V_20 -> V_52 ( & V_20 -> V_53 ) ;
F_17 (encoder, &dev->mode_config.encoder_list, base.base.head)
V_16 -> V_54 ( & V_16 -> V_53 . V_53 ) ;
return 0 ;
}
void
V_34 ( struct V_1 * V_2 )
{
F_22 ( V_2 , 0 , V_58 , 0 ) ;
if ( F_8 ( V_2 ) )
F_22 ( V_2 , 1 , V_58 , 0 ) ;
}
