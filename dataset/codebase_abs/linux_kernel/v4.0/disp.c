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
F_4 ( F_5 ( & V_4 -> V_7 ) ) ;
F_6 ( V_2 ) -> V_24 = V_19 ;
F_6 ( V_2 ) -> V_25 = V_26 ;
F_6 ( V_2 ) -> V_27 = V_28 ;
F_6 ( V_2 ) -> V_29 = V_30 ;
F_7 ( V_2 , 1 ) ;
F_8 ( V_2 , 0 ) ;
if ( F_9 ( V_2 ) )
F_8 ( V_2 , 1 ) ;
for ( V_20 = 0 ; V_20 < V_9 -> V_31 ; V_20 ++ ) {
struct V_32 * V_33 = & V_9 -> V_34 [ V_20 ] ;
V_12 = F_10 ( V_2 , V_33 -> V_12 ) ;
if ( F_11 ( V_12 ) )
continue;
switch ( V_33 -> type ) {
case V_35 :
V_21 = F_12 ( V_12 , V_33 ) ;
break;
case V_36 :
case V_37 :
V_21 = F_13 ( V_12 , V_33 ) ;
break;
case V_38 :
if ( V_33 -> V_39 == V_40 )
V_21 = F_14 ( V_12 , V_33 ) ;
else
V_21 = F_15 ( V_12 , V_33 ) ;
break;
default:
F_16 ( V_4 , L_1 , V_33 -> type ) ;
continue;
}
if ( V_21 )
continue;
}
F_17 (connector, ct,
&dev->mode_config.connector_list, head) {
if ( ! V_12 -> V_41 [ 0 ] ) {
F_16 ( V_4 , L_2 ,
V_12 -> V_42 ) ;
V_12 -> V_43 -> V_44 ( V_12 ) ;
}
}
F_18 (encoder, &dev->mode_config.encoder_list, head) {
struct V_45 * V_46 = V_45 ( V_15 ) ;
V_46 -> V_6 = V_6 -> V_47 ( V_6 , V_46 -> V_9 -> V_48 ) ;
}
F_18 (crtc, &dev->mode_config.crtc_list, head)
V_17 -> V_43 -> V_49 ( V_17 ) ;
F_18 (encoder, &dev->mode_config.encoder_list, head) {
struct V_50 * V_51 = V_15 -> V_52 ;
V_51 -> V_49 ( V_15 ) ;
}
F_19 ( V_2 ) ;
return 0 ;
}
void
V_26 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_18 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_18 (crtc, &dev->mode_config.crtc_list, head) {
struct V_53 V_54 = {
. V_17 = V_17 ,
} ;
F_20 ( & V_54 ) ;
}
F_18 (encoder, &dev->mode_config.encoder_list, head) {
struct V_50 * V_51 = V_15 -> V_52 ;
V_51 -> V_55 ( V_15 ) ;
}
F_18 (crtc, &dev->mode_config.crtc_list, head)
V_17 -> V_43 -> V_55 ( V_17 ) ;
F_7 ( V_2 , 0 ) ;
F_6 ( V_2 ) -> V_24 = NULL ;
F_21 ( V_19 ) ;
F_22 ( F_5 ( & V_4 -> V_7 ) ) ;
}
int
V_28 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_18 (encoder, &dev->mode_config.encoder_list, head) {
struct V_50 * V_51 = V_15 -> V_52 ;
V_51 -> V_55 ( V_15 ) ;
}
F_18 (crtc, &dev->mode_config.crtc_list, head)
V_17 -> V_43 -> V_55 ( V_17 ) ;
return 0 ;
}
void
V_30 ( struct V_1 * V_2 )
{
F_23 ( V_2 , 0 , V_56 , 0 ) ;
if ( F_9 ( V_2 ) )
F_23 ( V_2 , 1 , V_56 , 0 ) ;
}
