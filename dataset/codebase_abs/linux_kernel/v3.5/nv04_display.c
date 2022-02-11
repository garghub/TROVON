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
F_12 ( V_2 , 0 , V_19 , 0 ) ;
if ( F_10 ( V_2 ) )
F_12 ( V_2 , 1 , V_19 , 0 ) ;
return 0 ;
}
void
F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_10 ( V_2 ) )
F_11 ( V_2 , V_4 -> V_7 ) ;
F_9 ( V_2 , true ) ;
}
int
F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = & V_4 -> V_22 . V_21 ;
struct V_23 * V_24 , * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
int V_30 , V_31 ;
F_15 ( V_2 , L_1 ) ;
F_16 ( V_2 , 1 ) ;
F_17 ( V_2 , 0 ) ;
if ( F_10 ( V_2 ) )
F_17 ( V_2 , 1 ) ;
for ( V_30 = 0 ; V_30 < V_21 -> V_32 ; V_30 ++ ) {
struct V_33 * V_34 = & V_21 -> V_35 [ V_30 ] ;
V_24 = F_18 ( V_2 , V_34 -> V_24 ) ;
if ( F_19 ( V_24 ) )
continue;
switch ( V_34 -> type ) {
case V_36 :
V_31 = F_20 ( V_24 , V_34 ) ;
break;
case V_37 :
case V_38 :
V_31 = F_21 ( V_24 , V_34 ) ;
break;
case V_39 :
if ( V_34 -> V_40 == V_41 )
V_31 = F_22 ( V_24 , V_34 ) ;
else
V_31 = F_23 ( V_24 , V_34 ) ;
break;
default:
F_24 ( V_2 , L_2 , V_34 -> type ) ;
continue;
}
if ( V_31 )
continue;
}
F_25 (connector, ct,
&dev->mode_config.connector_list, head) {
if ( ! V_24 -> V_42 [ 0 ] ) {
F_24 ( V_2 , L_3 ,
F_26 ( V_24 ) ) ;
V_24 -> V_43 -> V_44 ( V_24 ) ;
}
}
F_27 (crtc, &dev->mode_config.crtc_list, head)
V_29 -> V_43 -> V_45 ( V_29 ) ;
F_27 (encoder, &dev->mode_config.encoder_list, head) {
struct V_46 * V_47 = V_27 -> V_48 ;
V_47 -> V_45 ( V_27 ) ;
}
F_28 ( V_2 , 24 , V_49 ) ;
F_28 ( V_2 , 25 , V_50 ) ;
return 0 ;
}
void
F_29 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
F_15 ( V_2 , L_1 ) ;
F_30 ( V_2 , 24 ) ;
F_30 ( V_2 , 25 ) ;
F_27 (crtc, &dev->mode_config.crtc_list, head) {
struct V_51 V_52 = {
. V_29 = V_29 ,
} ;
V_29 -> V_43 -> V_53 ( & V_52 ) ;
}
F_27 (encoder, &dev->mode_config.encoder_list, head) {
struct V_46 * V_47 = V_27 -> V_48 ;
V_47 -> V_54 ( V_27 ) ;
}
F_27 (crtc, &dev->mode_config.crtc_list, head)
V_29 -> V_43 -> V_54 ( V_29 ) ;
F_16 ( V_2 , 0 ) ;
}
int
F_31 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
F_27 (encoder, &dev->mode_config.encoder_list, head) {
struct V_46 * V_47 = V_27 -> V_48 ;
V_47 -> V_54 ( V_27 ) ;
}
F_27 (crtc, &dev->mode_config.crtc_list, head)
V_29 -> V_43 -> V_54 ( V_29 ) ;
return 0 ;
}
void
F_32 ( struct V_1 * V_2 )
{
F_12 ( V_2 , 0 , V_19 , 0 ) ;
if ( F_10 ( V_2 ) )
F_12 ( V_2 , 1 , V_19 , 0 ) ;
}
static void
V_49 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_55 , V_56 ) ;
F_33 ( V_2 , 0 ) ;
}
static void
V_50 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_57 , V_56 ) ;
F_33 ( V_2 , 1 ) ;
}
