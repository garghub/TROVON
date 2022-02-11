static bool
F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
if ( V_13 -> V_2 != V_2 )
continue;
if ( V_11 -> V_14 -> V_15 )
V_11 -> V_14 -> V_15 ( V_11 , V_13 , V_4 ,
V_5 ) ;
}
return true ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
if ( V_11 -> V_14 -> V_16 )
V_11 -> V_14 -> V_16 ( V_11 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
if ( V_11 -> V_14 -> V_17 )
V_11 -> V_14 -> V_17 ( V_11 , V_18 ) ;
if ( V_11 -> V_14 -> V_19 )
V_11 -> V_14 -> V_19 ( V_11 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
if ( V_11 -> V_14 -> V_17 )
V_11 -> V_14 -> V_17 ( V_11 , V_20 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_9 ) ;
}
static unsigned int F_10 ( struct V_1 * V_2 )
{
struct V_1 * V_21 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
unsigned int V_22 = 0 ;
int V_23 = 0 ;
F_3 (clone, &dev->mode_config.encoder_list, head) {
switch ( V_11 -> type ) {
case V_24 :
case V_25 :
case V_26 :
V_22 |= ( 1 << ( V_23 ++ ) ) ;
break;
default:
continue;
}
}
return V_22 ;
}
void F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
V_2 -> V_27 = F_10 ( V_2 ) ;
}
struct V_1 *
F_12 ( struct V_6 * V_7 ,
struct V_10 * V_11 ,
unsigned long V_28 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
if ( ! V_28 )
return NULL ;
V_9 = F_13 ( sizeof( * V_9 ) , V_29 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_11 = V_11 ;
V_2 = & V_9 -> V_1 ;
V_2 -> V_28 = V_28 ;
F_14 ( L_1 , V_2 -> V_28 ) ;
F_15 ( V_7 , V_2 , & V_30 ,
V_31 ) ;
F_16 ( V_2 , & V_32 ) ;
F_14 ( L_2 ) ;
return V_2 ;
}
struct V_10 * F_17 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_11 ;
}
