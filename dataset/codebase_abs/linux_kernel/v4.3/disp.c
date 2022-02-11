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
int V_20 , V_21 ;
V_19 = F_3 ( sizeof( * V_19 ) , V_22 ) ;
if ( ! V_19 )
return - V_23 ;
F_4 ( & V_4 -> V_7 . V_24 ) ;
F_5 ( V_2 ) -> V_25 = V_19 ;
F_5 ( V_2 ) -> V_26 = V_27 ;
F_5 ( V_2 ) -> V_28 = V_29 ;
F_5 ( V_2 ) -> V_30 = V_31 ;
F_6 ( V_2 , 1 ) ;
F_7 ( V_2 , 0 ) ;
if ( F_8 ( V_2 ) )
F_7 ( V_2 , 1 ) ;
for ( V_20 = 0 ; V_20 < V_9 -> V_32 ; V_20 ++ ) {
struct V_33 * V_34 = & V_9 -> V_35 [ V_20 ] ;
V_12 = F_9 ( V_2 , V_34 -> V_12 ) ;
if ( F_10 ( V_12 ) )
continue;
switch ( V_34 -> type ) {
case V_36 :
V_21 = F_11 ( V_12 , V_34 ) ;
break;
case V_37 :
case V_38 :
V_21 = F_12 ( V_12 , V_34 ) ;
break;
case V_39 :
if ( V_34 -> V_40 == V_41 )
V_21 = F_13 ( V_12 , V_34 ) ;
else
V_21 = F_14 ( V_12 , V_34 ) ;
break;
default:
F_15 ( V_4 , L_1 , V_34 -> type ) ;
continue;
}
if ( V_21 )
continue;
}
F_16 (connector, ct,
&dev->mode_config.connector_list, head) {
if ( ! V_12 -> V_42 [ 0 ] ) {
F_15 ( V_4 , L_2 ,
V_12 -> V_43 ) ;
V_12 -> V_44 -> V_45 ( V_12 ) ;
}
}
F_17 (encoder, &dev->mode_config.encoder_list, head) {
struct V_46 * V_47 = V_46 ( V_15 ) ;
struct V_48 * V_49 =
F_18 ( V_6 , V_47 -> V_9 -> V_50 ) ;
V_47 -> V_6 = V_49 ? & V_49 -> V_6 : NULL ;
}
F_17 (crtc, &dev->mode_config.crtc_list, head)
V_17 -> V_44 -> V_51 ( V_17 ) ;
F_17 (encoder, &dev->mode_config.encoder_list, head) {
const struct V_52 * V_53 = V_15 -> V_54 ;
V_53 -> V_51 ( V_15 ) ;
}
F_19 ( V_2 ) ;
return 0 ;
}
void
V_27 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_18 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_55 V_56 = {
. V_17 = V_17 ,
} ;
F_20 ( & V_56 ) ;
}
F_17 (encoder, &dev->mode_config.encoder_list, head) {
const struct V_52 * V_53 = V_15 -> V_54 ;
V_53 -> V_57 ( V_15 ) ;
}
F_17 (crtc, &dev->mode_config.crtc_list, head)
V_17 -> V_44 -> V_57 ( V_17 ) ;
F_6 ( V_2 , 0 ) ;
F_5 ( V_2 ) -> V_25 = NULL ;
F_21 ( V_19 ) ;
F_22 ( & V_4 -> V_7 . V_24 ) ;
}
int
V_29 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_17 (encoder, &dev->mode_config.encoder_list, head) {
const struct V_52 * V_53 = V_15 -> V_54 ;
V_53 -> V_57 ( V_15 ) ;
}
F_17 (crtc, &dev->mode_config.crtc_list, head)
V_17 -> V_44 -> V_57 ( V_17 ) ;
return 0 ;
}
void
V_31 ( struct V_1 * V_2 )
{
F_23 ( V_2 , 0 , V_58 , 0 ) ;
if ( F_8 ( V_2 ) )
F_23 ( V_2 , 1 , V_58 , 0 ) ;
}
