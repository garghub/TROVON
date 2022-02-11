int
F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , V_3 , 0 ) ;
if ( F_3 ( V_2 ) )
F_2 ( V_2 , 1 , V_3 , 0 ) ;
return 0 ;
}
void
F_4 ( struct V_1 * V_2 )
{
}
int
F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_8 . V_7 ;
struct V_9 * V_10 , * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 , V_19 ;
F_6 ( V_5 , L_1 ) ;
V_17 = F_7 ( sizeof( * V_17 ) , V_20 ) ;
if ( ! V_17 )
return - V_21 ;
F_8 ( V_2 ) -> V_22 = V_17 ;
F_8 ( V_2 ) -> V_23 = V_24 ;
F_8 ( V_2 ) -> V_25 = V_26 ;
F_8 ( V_2 ) -> V_27 = V_28 ;
F_9 ( V_2 , 1 ) ;
F_10 ( V_2 , 0 ) ;
if ( F_3 ( V_2 ) )
F_10 ( V_2 , 1 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_29 ; V_18 ++ ) {
struct V_30 * V_31 = & V_7 -> V_32 [ V_18 ] ;
V_10 = F_11 ( V_2 , V_31 -> V_10 ) ;
if ( F_12 ( V_10 ) )
continue;
switch ( V_31 -> type ) {
case V_33 :
V_19 = F_13 ( V_10 , V_31 ) ;
break;
case V_34 :
case V_35 :
V_19 = F_14 ( V_10 , V_31 ) ;
break;
case V_36 :
if ( V_31 -> V_37 == V_38 )
V_19 = F_15 ( V_10 , V_31 ) ;
else
V_19 = F_16 ( V_10 , V_31 ) ;
break;
default:
F_17 ( V_5 , L_2 , V_31 -> type ) ;
continue;
}
if ( V_19 )
continue;
}
F_18 (connector, ct,
&dev->mode_config.connector_list, head) {
if ( ! V_10 -> V_39 [ 0 ] ) {
F_17 ( V_5 , L_3 ,
F_19 ( V_10 ) ) ;
V_10 -> V_40 -> V_41 ( V_10 ) ;
}
}
F_20 (crtc, &dev->mode_config.crtc_list, head)
V_15 -> V_40 -> V_42 ( V_15 ) ;
F_20 (encoder, &dev->mode_config.encoder_list, head) {
struct V_43 * V_44 = V_13 -> V_45 ;
V_44 -> V_42 ( V_13 ) ;
}
return 0 ;
}
void
V_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
F_6 ( V_5 , L_1 ) ;
F_20 (crtc, &dev->mode_config.crtc_list, head) {
struct V_46 V_47 = {
. V_15 = V_15 ,
} ;
V_15 -> V_40 -> V_48 ( & V_47 ) ;
}
F_20 (encoder, &dev->mode_config.encoder_list, head) {
struct V_43 * V_44 = V_13 -> V_45 ;
V_44 -> V_49 ( V_13 ) ;
}
F_20 (crtc, &dev->mode_config.crtc_list, head)
V_15 -> V_40 -> V_49 ( V_15 ) ;
F_9 ( V_2 , 0 ) ;
F_8 ( V_2 ) -> V_22 = NULL ;
F_21 ( V_17 ) ;
}
int
V_26 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
F_20 (encoder, &dev->mode_config.encoder_list, head) {
struct V_43 * V_44 = V_13 -> V_45 ;
V_44 -> V_49 ( V_13 ) ;
}
F_20 (crtc, &dev->mode_config.crtc_list, head)
V_15 -> V_40 -> V_49 ( V_15 ) ;
return 0 ;
}
void
V_28 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , V_3 , 0 ) ;
if ( F_3 ( V_2 ) )
F_2 ( V_2 , 1 , V_3 , 0 ) ;
}
