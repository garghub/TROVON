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
struct V_6 * V_7 = V_6 ( V_5 -> V_8 ) ;
struct V_9 * V_10 = & V_5 -> V_11 . V_10 ;
struct V_12 * V_13 , * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 , V_22 ;
V_20 = F_6 ( sizeof( * V_20 ) , V_23 ) ;
if ( ! V_20 )
return - V_24 ;
F_7 ( V_2 ) -> V_25 = V_20 ;
F_7 ( V_2 ) -> V_26 = V_27 ;
F_7 ( V_2 ) -> V_28 = V_29 ;
F_7 ( V_2 ) -> V_30 = V_31 ;
F_8 ( V_2 , 1 ) ;
V_22 = F_9 ( F_10 ( V_5 ) , V_32 , 0xd1500000 ,
V_33 , NULL , 0 , & V_20 -> V_34 ) ;
if ( V_22 )
return V_22 ;
F_11 ( V_2 , 0 ) ;
if ( F_3 ( V_2 ) )
F_11 ( V_2 , 1 ) ;
for ( V_21 = 0 ; V_21 < V_10 -> V_35 ; V_21 ++ ) {
struct V_36 * V_37 = & V_10 -> V_38 [ V_21 ] ;
V_13 = F_12 ( V_2 , V_37 -> V_13 ) ;
if ( F_13 ( V_13 ) )
continue;
switch ( V_37 -> type ) {
case V_39 :
V_22 = F_14 ( V_13 , V_37 ) ;
break;
case V_40 :
case V_41 :
V_22 = F_15 ( V_13 , V_37 ) ;
break;
case V_42 :
if ( V_37 -> V_43 == V_44 )
V_22 = F_16 ( V_13 , V_37 ) ;
else
V_22 = F_17 ( V_13 , V_37 ) ;
break;
default:
F_18 ( V_5 , L_1 , V_37 -> type ) ;
continue;
}
if ( V_22 )
continue;
}
F_19 (connector, ct,
&dev->mode_config.connector_list, head) {
if ( ! V_13 -> V_45 [ 0 ] ) {
F_18 ( V_5 , L_2 ,
F_20 ( V_13 ) ) ;
V_13 -> V_46 -> V_47 ( V_13 ) ;
}
}
F_21 (encoder, &dev->mode_config.encoder_list, head) {
struct V_48 * V_49 = V_48 ( V_16 ) ;
V_49 -> V_7 = V_7 -> V_50 ( V_7 , V_49 -> V_10 -> V_51 ) ;
}
F_21 (crtc, &dev->mode_config.crtc_list, head)
V_18 -> V_46 -> V_52 ( V_18 ) ;
F_21 (encoder, &dev->mode_config.encoder_list, head) {
struct V_53 * V_54 = V_16 -> V_55 ;
V_54 -> V_52 ( V_16 ) ;
}
return 0 ;
}
void
V_27 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_19 ( V_2 ) ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_56 V_57 = {
. V_18 = V_18 ,
} ;
F_22 ( & V_57 ) ;
}
F_21 (encoder, &dev->mode_config.encoder_list, head) {
struct V_53 * V_54 = V_16 -> V_55 ;
V_54 -> V_58 ( V_16 ) ;
}
F_21 (crtc, &dev->mode_config.crtc_list, head)
V_18 -> V_46 -> V_58 ( V_18 ) ;
F_8 ( V_2 , 0 ) ;
F_7 ( V_2 ) -> V_25 = NULL ;
F_23 ( V_20 ) ;
}
int
V_29 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
F_21 (encoder, &dev->mode_config.encoder_list, head) {
struct V_53 * V_54 = V_16 -> V_55 ;
V_54 -> V_58 ( V_16 ) ;
}
F_21 (crtc, &dev->mode_config.crtc_list, head)
V_18 -> V_46 -> V_58 ( V_18 ) ;
return 0 ;
}
void
V_31 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , V_3 , 0 ) ;
if ( F_3 ( V_2 ) )
F_2 ( V_2 , 1 , V_3 , 0 ) ;
}
