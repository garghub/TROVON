static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_3 ( L_1 , V_3 ) ;
if ( V_7 -> V_8 -> V_9 )
V_7 -> V_8 -> V_9 ( V_7 , V_3 ) ;
}
static bool
F_4 ( struct V_1 * V_2 ,
const struct V_10 * V_3 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_14 * V_15 ;
F_5 (connector, &dev->mode_config.connector_list, head) {
if ( V_15 -> V_2 != V_2 )
continue;
if ( V_7 -> V_8 -> V_16 )
V_7 -> V_8 -> V_16 ( V_7 , V_15 , V_3 ,
V_11 ) ;
}
return true ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_10 * V_3 ,
struct V_10 * V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_7 -> V_8 -> V_17 )
V_7 -> V_8 -> V_17 ( V_7 , V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_7 -> V_8 -> V_9 )
V_7 -> V_8 -> V_9 ( V_7 , V_18 ) ;
if ( V_7 -> V_8 -> V_19 )
V_7 -> V_8 -> V_19 ( V_7 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_12 * V_13 = V_2 -> V_13 ;
F_1 ( V_2 , V_22 ) ;
F_10 (plane, &dev->mode_config.plane_list) {
if ( V_21 -> V_23 == V_2 -> V_23 )
V_21 -> V_24 -> V_25 ( V_21 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_12 ( V_2 ) ;
F_13 ( V_5 ) ;
}
static unsigned int F_14 ( struct V_1 * V_2 )
{
struct V_1 * V_26 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
unsigned int V_27 = 0 ;
int V_28 = 0 ;
F_5 (clone, &dev->mode_config.encoder_list, head) {
switch ( V_7 -> type ) {
case V_29 :
case V_30 :
case V_31 :
V_27 |= ( 1 << ( V_28 ++ ) ) ;
break;
default:
continue;
}
}
return V_27 ;
}
void F_15 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
F_5 (encoder, &dev->mode_config.encoder_list, head)
V_2 -> V_32 = F_14 ( V_2 ) ;
}
struct V_1 *
F_16 ( struct V_12 * V_13 ,
struct V_6 * V_7 ,
unsigned long V_33 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
if ( ! V_33 )
return NULL ;
V_5 = F_17 ( sizeof( * V_5 ) , V_34 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_7 = V_7 ;
V_2 = & V_5 -> V_1 ;
V_2 -> V_33 = V_33 ;
F_3 ( L_2 , V_2 -> V_33 ) ;
F_18 ( V_13 , V_2 , & V_35 ,
V_36 ) ;
F_19 ( V_2 , & V_37 ) ;
F_3 ( L_3 ) ;
return V_2 ;
}
struct V_6 * F_20 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_7 ;
}
