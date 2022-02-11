const struct V_1 * V_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
struct V_5 *
F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
return & V_9 -> V_10 -> V_10 ;
}
void F_4 ( struct V_5 * V_10 )
{
}
void F_5 ( struct V_5 * V_10 ,
struct V_11 * V_12 ,
struct V_11 * V_13 )
{
struct V_14 * V_15 = F_6 ( V_10 ) ;
F_7 ( V_10 -> V_16 , V_15 -> V_17 ) ;
}
void F_8 ( struct V_5 * V_10 )
{
}
int F_9 ( struct V_18 * V_19 , struct V_20 * V_21 ,
struct V_22 * args )
{
unsigned int V_23 = F_10 ( args -> V_24 * args -> V_25 , 8 ) ;
unsigned int V_26 ;
V_26 = 16 * args -> V_25 / 8 ;
args -> V_27 = F_11 ( F_12 ( args -> V_27 , V_23 ) , V_26 ) ;
return F_13 ( V_19 , V_21 , args ) ;
}
static struct V_28 *
F_14 ( struct V_20 * V_21 , struct V_18 * V_29 ,
struct V_30 * V_31 )
{
const struct V_1 * V_32 ;
unsigned int V_26 ;
V_32 = V_1 ( V_31 -> V_33 ) ;
if ( V_32 == NULL ) {
F_15 ( V_21 -> V_21 , L_1 ,
V_31 -> V_33 ) ;
return F_16 ( - V_34 ) ;
}
V_26 = 16 * V_32 -> V_25 / 8 ;
if ( V_31 -> V_35 [ 0 ] & ( V_26 - 1 ) ||
V_31 -> V_35 [ 0 ] >= 8192 ) {
F_15 ( V_21 -> V_21 , L_2 ,
V_31 -> V_35 [ 0 ] ) ;
return F_16 ( - V_34 ) ;
}
if ( V_32 -> V_36 == 2 ) {
if ( V_31 -> V_35 [ 1 ] != V_31 -> V_35 [ 0 ] ) {
F_15 ( V_21 -> V_21 ,
L_3 ) ;
return F_16 ( - V_34 ) ;
}
}
return F_17 ( V_21 , V_29 , V_31 ) ;
}
int F_18 ( struct V_37 * V_38 )
{
struct V_20 * V_21 = V_38 -> V_39 ;
struct V_5 * V_10 ;
unsigned int V_3 ;
int V_40 ;
F_19 ( V_38 -> V_39 ) ;
V_38 -> V_39 -> V_41 . V_42 = 0 ;
V_38 -> V_39 -> V_41 . V_43 = 0 ;
V_38 -> V_39 -> V_41 . V_44 = 4095 ;
V_38 -> V_39 -> V_41 . V_45 = 2047 ;
V_38 -> V_39 -> V_41 . V_46 = & V_47 ;
V_40 = F_20 ( V_38 ) ;
if ( V_40 < 0 )
return V_40 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_38 -> V_48 ) ; ++ V_3 ) {
V_40 = F_21 ( V_38 , V_3 ) ;
if ( V_40 < 0 )
return V_40 ;
}
V_38 -> V_49 = 0 ;
V_38 -> V_50 = V_3 ;
for ( V_3 = 0 ; V_3 < V_38 -> V_51 -> V_52 ; ++ V_3 ) {
const struct V_53 * V_51 =
& V_38 -> V_51 -> V_54 [ V_3 ] ;
if ( V_51 -> V_17 >= F_1 ( V_38 -> V_48 ) ) {
F_22 ( V_38 -> V_21 ,
L_4 ,
V_3 , V_51 -> V_17 ) ;
continue;
}
switch ( V_51 -> V_10 ) {
case V_55 :
F_23 ( V_38 , & V_51 -> V_56 . V_57 , V_51 -> V_17 ) ;
break;
case V_58 :
F_24 ( V_38 , & V_51 -> V_56 . V_59 , V_51 -> V_17 ) ;
break;
default:
break;
}
}
F_25 (encoder, &dev->mode_config.encoder_list, head) {
struct V_14 * V_15 = F_6 ( V_10 ) ;
V_10 -> V_60 = ( 1 << 0 ) | ( 1 << V_15 -> V_17 ) ;
V_10 -> V_61 = 1 << 0 ;
}
V_40 = F_26 ( V_38 ) ;
if ( V_40 < 0 )
return V_40 ;
F_27 ( V_38 -> V_39 ) ;
F_28 ( V_38 -> V_39 ) ;
return 0 ;
}
