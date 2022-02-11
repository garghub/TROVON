static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 (connector, &dev->mode_config.connector_list, head) {
if ( V_7 -> V_2 == V_2 ) {
struct V_10 * V_11 =
V_9 -> V_11 ;
F_4 ( L_1 ,
V_7 -> V_12 . V_13 , V_3 ) ;
if ( V_11 && V_11 -> V_14 )
V_11 -> V_14 ( V_9 -> V_5 , V_3 ) ;
}
}
}
static void F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_15 * V_16 = V_9 -> V_17 ;
struct V_18 * V_19 = F_6 ( V_2 ) ;
F_4 ( L_2 , __FILE__ , V_3 ) ;
if ( V_19 -> V_20 == V_3 ) {
F_4 ( L_3 ) ;
return;
}
F_7 ( & V_5 -> V_21 ) ;
switch ( V_3 ) {
case V_22 :
if ( V_16 && V_16 -> V_23 )
V_16 -> V_23 ( V_9 -> V_5 ) ;
F_1 ( V_2 , V_3 ) ;
V_19 -> V_20 = V_3 ;
break;
case V_24 :
case V_25 :
case V_26 :
F_1 ( V_2 , V_3 ) ;
V_19 -> V_20 = V_3 ;
break;
default:
F_8 ( L_4 , V_3 ) ;
break;
}
F_9 ( & V_5 -> V_21 ) ;
}
static bool
F_10 ( struct V_1 * V_2 ,
struct V_27 * V_3 ,
struct V_27 * V_28 )
{
F_4 ( L_5 , __FILE__ ) ;
return true ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_27 * V_3 ,
struct V_27 * V_28 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_15 * V_16 = V_9 -> V_17 ;
struct V_29 * V_30 = V_9 -> V_30 ;
struct V_31 * V_32 = F_12 ( V_5 ,
V_2 -> V_33 ) ;
F_4 ( L_5 , __FILE__ ) ;
V_3 = V_28 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
if ( V_7 -> V_2 == V_2 ) {
if ( V_16 && V_16 -> V_34 )
V_16 -> V_34 ( V_9 -> V_5 , V_3 ) ;
if ( V_30 && V_30 -> V_34 )
V_30 -> V_34 ( V_9 -> V_5 , V_32 ) ;
}
}
}
static void F_13 ( struct V_1 * V_2 )
{
F_4 ( L_5 , __FILE__ ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_15 * V_16 = V_9 -> V_17 ;
F_4 ( L_5 , __FILE__ ) ;
if ( V_16 && V_16 -> V_35 )
V_16 -> V_35 ( V_9 -> V_5 ) ;
}
static struct V_36 *
F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_33 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_18 * V_19 =
F_6 ( V_2 ) ;
F_4 ( L_5 , __FILE__ ) ;
V_19 -> V_9 -> V_37 = - 1 ;
F_17 ( V_2 ) ;
F_18 ( V_19 ) ;
}
static unsigned int F_19 ( struct V_1 * V_2 )
{
struct V_1 * V_38 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_18 * V_19 = F_6 ( V_2 ) ;
struct V_10 * V_11 =
V_19 -> V_9 -> V_11 ;
unsigned int V_39 = 0 ;
int V_40 = 0 ;
F_3 (clone, &dev->mode_config.encoder_list, head) {
switch ( V_11 -> type ) {
case V_41 :
case V_42 :
V_39 |= ( 1 << ( V_40 ++ ) ) ;
break;
default:
continue;
}
}
return V_39 ;
}
void F_20 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_4 ( L_5 , __FILE__ ) ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
V_2 -> V_43 = F_19 ( V_2 ) ;
}
struct V_1 *
F_21 ( struct V_4 * V_5 ,
struct V_8 * V_9 ,
unsigned int V_44 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
F_4 ( L_5 , __FILE__ ) ;
if ( ! V_9 || ! V_44 )
return NULL ;
if ( ! V_9 -> V_5 )
return NULL ;
V_19 = F_22 ( sizeof( * V_19 ) , V_45 ) ;
if ( ! V_19 ) {
F_8 ( L_6 ) ;
return NULL ;
}
V_19 -> V_20 = V_26 ;
V_19 -> V_9 = V_9 ;
V_2 = & V_19 -> V_1 ;
V_2 -> V_44 = V_44 ;
F_4 ( L_7 , V_2 -> V_44 ) ;
F_23 ( V_5 , V_2 , & V_46 ,
V_47 ) ;
F_24 ( V_2 , & V_48 ) ;
F_4 ( L_8 ) ;
return V_2 ;
}
struct V_8 * F_2 ( struct V_1 * V_2 )
{
return F_6 ( V_2 ) -> V_9 ;
}
void F_25 ( struct V_36 * V_33 , void * V_49 ,
void (* F_26)( struct V_1 * , void * ) )
{
struct V_4 * V_5 = V_33 -> V_5 ;
struct V_1 * V_2 ;
struct V_50 * V_51 = V_5 -> V_52 ;
struct V_8 * V_9 ;
F_3 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! V_2 -> V_33 ) {
V_9 = F_6 ( V_2 ) -> V_9 ;
if ( V_9 -> V_37 < 0 ||
V_51 -> V_33 [ V_9 -> V_37 ] != V_33 )
continue;
} else {
if ( V_2 -> V_33 != V_33 )
continue;
}
F_26 ( V_2 , V_49 ) ;
}
}
void F_27 ( struct V_1 * V_2 , void * V_49 )
{
struct V_8 * V_9 =
F_6 ( V_2 ) -> V_9 ;
struct V_15 * V_16 = V_9 -> V_17 ;
int V_33 = * ( int * ) V_49 ;
if ( V_9 -> V_37 == - 1 )
V_9 -> V_37 = V_33 ;
if ( V_16 -> V_53 )
V_16 -> V_53 ( V_9 -> V_5 ) ;
}
void F_28 ( struct V_1 * V_2 , void * V_49 )
{
struct V_8 * V_9 =
F_6 ( V_2 ) -> V_9 ;
struct V_15 * V_16 = V_9 -> V_17 ;
int V_33 = * ( int * ) V_49 ;
if ( V_9 -> V_37 == - 1 )
V_9 -> V_37 = V_33 ;
if ( V_16 -> V_54 )
V_16 -> V_54 ( V_9 -> V_5 ) ;
}
void F_29 ( struct V_1 * V_2 ,
void * V_49 )
{
struct V_8 * V_9 =
F_6 ( V_2 ) -> V_9 ;
struct V_29 * V_30 = V_9 -> V_30 ;
int V_55 = V_56 ;
if ( V_49 )
V_55 = * ( int * ) V_49 ;
if ( V_30 && V_30 -> V_35 )
V_30 -> V_35 ( V_9 -> V_5 , V_55 ) ;
}
void F_30 ( struct V_1 * V_2 , void * V_49 )
{
struct V_8 * V_9 =
F_6 ( V_2 ) -> V_9 ;
int V_33 = * ( int * ) V_49 ;
int V_55 = V_56 ;
F_4 ( L_5 , __FILE__ ) ;
V_9 -> V_37 = V_33 ;
F_29 ( V_2 , & V_55 ) ;
}
void F_31 ( struct V_1 * V_2 , void * V_49 )
{
struct V_18 * V_19 = F_6 ( V_2 ) ;
int V_3 = * ( int * ) V_49 ;
F_4 ( L_5 , __FILE__ ) ;
F_5 ( V_2 , V_3 ) ;
V_19 -> V_20 = V_3 ;
}
void F_32 ( struct V_1 * V_2 , void * V_49 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_18 * V_19 = F_6 ( V_2 ) ;
struct V_8 * V_9 = V_19 -> V_9 ;
struct V_15 * V_16 = V_9 -> V_17 ;
struct V_6 * V_7 ;
int V_3 = * ( int * ) V_49 ;
F_4 ( L_5 , __FILE__ ) ;
if ( V_16 && V_16 -> V_20 )
V_16 -> V_20 ( V_9 -> V_5 , V_3 ) ;
F_3 (connector, &dev->mode_config.connector_list, head)
if ( V_7 -> V_2 == V_2 )
V_7 -> V_20 = V_3 ;
if ( V_3 > V_22 ) {
if ( ! V_2 -> V_33 )
V_9 -> V_37 = - 1 ;
}
}
void F_33 ( struct V_1 * V_2 , void * V_49 )
{
struct V_8 * V_9 =
F_6 ( V_2 ) -> V_9 ;
struct V_29 * V_30 = V_9 -> V_30 ;
struct V_31 * V_32 = V_49 ;
if ( V_30 && V_30 -> V_34 )
V_30 -> V_34 ( V_9 -> V_5 , V_32 ) ;
}
void F_34 ( struct V_1 * V_2 , void * V_49 )
{
struct V_8 * V_9 =
F_6 ( V_2 ) -> V_9 ;
struct V_29 * V_30 = V_9 -> V_30 ;
int V_55 = V_56 ;
F_4 ( L_9 ) ;
if ( V_49 )
V_55 = * ( int * ) V_49 ;
if ( V_30 && V_30 -> V_57 )
V_30 -> V_57 ( V_9 -> V_5 , V_55 ) ;
}
