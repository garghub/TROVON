static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 != 0x11 ) {
V_4 -> V_7 = F_2 ( V_2 , 0 , V_8 ) ;
return;
}
if ( F_3 ( V_2 , V_9 ) & ( 1 << 28 ) )
V_4 -> V_7 = 0x4 ;
else {
T_1 V_10 , V_11 ;
bool V_12 = false ;
bool V_13 = false ;
V_11 = F_2 ( V_2 , 1 , V_14 ) &
0x80 ;
if ( V_11 )
V_13 = ! ( F_2 ( V_2 , 1 , V_15 ) &
F_4 ( V_16 ) ) ;
V_10 = F_2 ( V_2 , 0 , V_14 ) &
0x80 ;
if ( V_10 )
V_12 = ! ( F_2 ( V_2 , 0 , V_15 ) &
F_4 ( V_16 ) ) ;
if ( V_10 && ! V_12 )
V_4 -> V_7 = 0x0 ;
else if ( V_11 && ! V_13 )
V_4 -> V_7 = 0x3 ;
else if ( V_10 )
V_4 -> V_7 = 0x0 ;
else if ( V_11 )
V_4 -> V_7 = 0x3 ;
else
V_4 -> V_7 = 0x0 ;
}
}
int
F_5 ( struct V_1 * V_2 )
{
if ( ! F_6 ( V_2 ) ) {
T_2 V_17 = F_7 ( V_2 , V_18 ) ;
if ( ! ( V_17 & 1 ) )
F_8 ( V_2 , V_18 , V_17 | 1 ) ;
}
F_9 ( V_2 , false ) ;
if ( F_10 ( V_2 ) ) {
F_1 ( V_2 ) ;
F_11 ( V_2 , 0 ) ;
}
return 0 ;
}
void
F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_10 ( V_2 ) )
F_11 ( V_2 , V_4 -> V_7 ) ;
F_9 ( V_2 , true ) ;
}
int
F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_19 * V_20 = & V_4 -> V_21 . V_20 ;
struct V_22 * V_23 , * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_29 , V_30 ;
F_14 ( V_2 , L_1 ) ;
F_15 ( V_2 , 1 ) ;
F_16 ( V_2 , 0 ) ;
if ( F_10 ( V_2 ) )
F_16 ( V_2 , 1 ) ;
for ( V_29 = 0 ; V_29 < V_20 -> V_31 ; V_29 ++ ) {
struct V_32 * V_33 = & V_20 -> V_34 [ V_29 ] ;
V_23 = F_17 ( V_2 , V_33 -> V_23 ) ;
if ( F_18 ( V_23 ) )
continue;
switch ( V_33 -> type ) {
case V_35 :
V_30 = F_19 ( V_23 , V_33 ) ;
break;
case V_36 :
case V_37 :
V_30 = F_20 ( V_23 , V_33 ) ;
break;
case V_38 :
if ( V_33 -> V_39 == V_40 )
V_30 = F_21 ( V_23 , V_33 ) ;
else
V_30 = F_22 ( V_23 , V_33 ) ;
break;
default:
F_23 ( V_2 , L_2 , V_33 -> type ) ;
continue;
}
if ( V_30 )
continue;
}
F_24 (connector, ct,
&dev->mode_config.connector_list, head) {
if ( ! V_23 -> V_41 [ 0 ] ) {
F_23 ( V_2 , L_3 ,
F_25 ( V_23 ) ) ;
V_23 -> V_42 -> V_43 ( V_23 ) ;
}
}
F_26 (crtc, &dev->mode_config.crtc_list, head)
V_28 -> V_42 -> V_44 ( V_28 ) ;
F_26 (encoder, &dev->mode_config.encoder_list, head) {
struct V_45 * V_46 = V_26 -> V_47 ;
V_46 -> V_44 ( V_26 ) ;
}
F_27 ( V_2 , 24 , V_48 ) ;
F_27 ( V_2 , 25 , V_49 ) ;
return 0 ;
}
void
F_28 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
F_14 ( V_2 , L_1 ) ;
F_29 ( V_2 , 24 ) ;
F_29 ( V_2 , 25 ) ;
F_26 (crtc, &dev->mode_config.crtc_list, head) {
struct V_50 V_51 = {
. V_28 = V_28 ,
} ;
V_28 -> V_42 -> V_52 ( & V_51 ) ;
}
F_26 (encoder, &dev->mode_config.encoder_list, head) {
struct V_45 * V_46 = V_26 -> V_47 ;
V_46 -> V_53 ( V_26 ) ;
}
F_26 (crtc, &dev->mode_config.crtc_list, head)
V_28 -> V_42 -> V_53 ( V_28 ) ;
F_15 ( V_2 , 0 ) ;
}
int
F_30 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
F_26 (encoder, &dev->mode_config.encoder_list, head) {
struct V_45 * V_46 = V_26 -> V_47 ;
V_46 -> V_53 ( V_26 ) ;
}
F_26 (crtc, &dev->mode_config.crtc_list, head)
V_28 -> V_42 -> V_53 ( V_28 ) ;
return 0 ;
}
void
F_31 ( struct V_1 * V_2 )
{
}
static void
V_48 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_54 , V_55 ) ;
F_32 ( V_2 , 0 ) ;
}
static void
V_49 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_56 , V_55 ) ;
F_32 ( V_2 , 1 ) ;
}
