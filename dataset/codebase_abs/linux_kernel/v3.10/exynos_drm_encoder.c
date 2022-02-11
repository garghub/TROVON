static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( F_3 ( V_7 ) == V_2 ) {
F_4 ( L_1 ,
V_7 -> V_8 . V_9 , V_3 ) ;
F_5 ( V_7 , V_3 ) ;
}
}
}
static void F_6 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_10 * V_11 = F_7 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = F_8 ( V_2 ) ;
F_4 ( L_2 , __FILE__ , V_3 ) ;
if ( V_16 -> V_17 == V_3 ) {
F_4 ( L_3 ) ;
return;
}
F_9 ( & V_5 -> V_18 ) ;
switch ( V_3 ) {
case V_19 :
if ( V_13 && V_13 -> V_20 )
if ( ! V_16 -> V_21 )
V_13 -> V_20 ( V_11 -> V_5 ) ;
F_1 ( V_2 , V_3 ) ;
V_16 -> V_17 = V_3 ;
break;
case V_22 :
case V_23 :
case V_24 :
F_1 ( V_2 , V_3 ) ;
V_16 -> V_17 = V_3 ;
V_16 -> V_21 = false ;
break;
default:
F_10 ( L_4 , V_3 ) ;
break;
}
F_11 ( & V_5 -> V_18 ) ;
}
static bool
F_12 ( struct V_1 * V_2 ,
const struct V_25 * V_3 ,
struct V_25 * V_26 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_10 * V_11 = F_7 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
F_4 ( L_5 , __FILE__ ) ;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( V_7 -> V_2 == V_2 )
if ( V_13 && V_13 -> V_27 )
V_13 -> V_27 ( V_11 -> V_5 , V_7 ,
V_3 , V_26 ) ;
}
return true ;
}
static void F_13 ( struct V_4 * V_5 ,
struct V_28 * V_29 ,
struct V_28 * V_30 )
{
struct V_31 * V_32 ;
F_2 (plane, &dev->mode_config.plane_list, head) {
if ( V_32 -> V_33 == V_29 ) {
V_32 -> V_33 = V_30 ;
V_32 -> V_34 -> V_35 ( V_32 ) ;
}
}
}
static void F_14 ( struct V_1 * V_2 ,
struct V_25 * V_3 ,
struct V_25 * V_26 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
F_4 ( L_5 , __FILE__ ) ;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( V_7 -> V_2 == V_2 ) {
struct V_15 * V_16 ;
V_16 = F_8 ( V_2 ) ;
if ( V_16 -> V_29 != V_2 -> V_33 &&
V_16 -> V_29 ) {
F_13 ( V_5 ,
V_16 -> V_29 ,
V_2 -> V_33 ) ;
}
V_11 = F_7 ( V_2 ) ;
V_13 = V_11 -> V_14 ;
if ( V_13 && V_13 -> V_36 )
V_13 -> V_36 ( V_11 -> V_5 ,
V_26 ) ;
V_16 -> V_29 = V_2 -> V_33 ;
}
}
}
static void F_15 ( struct V_1 * V_2 )
{
F_4 ( L_5 , __FILE__ ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_8 ( V_2 ) ;
struct V_10 * V_11 = V_16 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
F_4 ( L_5 , __FILE__ ) ;
if ( V_13 && V_13 -> V_37 )
V_13 -> V_37 ( V_11 -> V_5 ) ;
V_16 -> V_21 = true ;
V_16 -> V_17 = V_19 ;
}
void F_17 ( struct V_38 * V_39 )
{
struct V_15 * V_16 ;
struct V_12 * V_14 ;
struct V_4 * V_5 = V_39 -> V_5 ;
struct V_1 * V_2 ;
F_2 (encoder, &dev->mode_config.encoder_list, head) {
V_16 = F_8 ( V_2 ) ;
V_14 = V_16 -> V_11 -> V_14 ;
if ( V_14 -> V_40 )
V_14 -> V_40 ( V_16 -> V_11 -> V_5 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_6 ( V_2 , V_24 ) ;
F_2 (plane, &dev->mode_config.plane_list, head) {
if ( V_32 -> V_33 == V_2 -> V_33 )
V_32 -> V_34 -> V_35 ( V_32 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_15 * V_16 =
F_8 ( V_2 ) ;
F_4 ( L_5 , __FILE__ ) ;
V_16 -> V_11 -> V_41 = - 1 ;
F_20 ( V_2 ) ;
F_21 ( V_16 ) ;
}
static unsigned int F_22 ( struct V_1 * V_2 )
{
struct V_1 * V_42 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_15 * V_16 = F_8 ( V_2 ) ;
struct V_43 * V_44 =
V_16 -> V_11 -> V_44 ;
unsigned int V_45 = 0 ;
int V_46 = 0 ;
F_2 (clone, &dev->mode_config.encoder_list, head) {
switch ( V_44 -> type ) {
case V_47 :
case V_48 :
case V_49 :
V_45 |= ( 1 << ( V_46 ++ ) ) ;
break;
default:
continue;
}
}
return V_45 ;
}
void F_23 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_4 ( L_5 , __FILE__ ) ;
F_2 (encoder, &dev->mode_config.encoder_list, head)
V_2 -> V_50 = F_22 ( V_2 ) ;
}
struct V_1 *
F_24 ( struct V_4 * V_5 ,
struct V_10 * V_11 ,
unsigned int V_51 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
F_4 ( L_5 , __FILE__ ) ;
if ( ! V_11 || ! V_51 )
return NULL ;
if ( ! V_11 -> V_5 )
return NULL ;
V_16 = F_25 ( sizeof( * V_16 ) , V_52 ) ;
if ( ! V_16 ) {
F_10 ( L_6 ) ;
return NULL ;
}
V_16 -> V_17 = V_24 ;
V_16 -> V_11 = V_11 ;
V_2 = & V_16 -> V_1 ;
V_2 -> V_51 = V_51 ;
F_4 ( L_7 , V_2 -> V_51 ) ;
F_26 ( V_5 , V_2 , & V_53 ,
V_54 ) ;
F_27 ( V_2 , & V_55 ) ;
F_4 ( L_8 ) ;
return V_2 ;
}
struct V_10 * F_7 ( struct V_1 * V_2 )
{
return F_8 ( V_2 ) -> V_11 ;
}
void F_28 ( struct V_28 * V_33 , void * V_56 ,
void (* F_29)( struct V_1 * , void * ) )
{
struct V_4 * V_5 = V_33 -> V_5 ;
struct V_1 * V_2 ;
struct V_57 * V_58 = V_5 -> V_59 ;
struct V_10 * V_11 ;
F_2 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! V_2 -> V_33 ) {
V_11 = F_8 ( V_2 ) -> V_11 ;
if ( V_11 -> V_41 < 0 ||
V_58 -> V_33 [ V_11 -> V_41 ] != V_33 )
continue;
} else {
if ( V_2 -> V_33 != V_33 )
continue;
}
F_29 ( V_2 , V_56 ) ;
}
}
void F_30 ( struct V_1 * V_2 , void * V_56 )
{
struct V_10 * V_11 =
F_8 ( V_2 ) -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_33 = * ( int * ) V_56 ;
if ( V_11 -> V_41 != V_33 )
return;
if ( V_13 -> V_60 )
V_13 -> V_60 ( V_11 -> V_5 ) ;
}
void F_31 ( struct V_1 * V_2 , void * V_56 )
{
struct V_10 * V_11 =
F_8 ( V_2 ) -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_33 = * ( int * ) V_56 ;
if ( V_11 -> V_41 != V_33 )
return;
if ( V_13 -> V_61 )
V_13 -> V_61 ( V_11 -> V_5 ) ;
}
void F_32 ( struct V_1 * V_2 , void * V_56 )
{
struct V_15 * V_16 = F_8 ( V_2 ) ;
struct V_10 * V_11 = V_16 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_3 = * ( int * ) V_56 ;
F_4 ( L_5 , __FILE__ ) ;
if ( V_13 && V_13 -> V_17 )
V_13 -> V_17 ( V_11 -> V_5 , V_3 ) ;
if ( V_3 > V_19 ) {
if ( ! V_2 -> V_33 )
V_11 -> V_41 = - 1 ;
}
}
void F_33 ( struct V_1 * V_2 , void * V_56 )
{
struct V_10 * V_11 =
F_8 ( V_2 ) -> V_11 ;
int V_41 = * ( int * ) V_56 ;
F_4 ( L_5 , __FILE__ ) ;
V_11 -> V_41 = V_41 ;
}
void F_34 ( struct V_1 * V_2 , void * V_56 )
{
struct V_10 * V_11 =
F_8 ( V_2 ) -> V_11 ;
struct V_62 * V_63 = V_11 -> V_63 ;
struct V_64 * V_65 = V_56 ;
F_4 ( L_5 , __FILE__ ) ;
if ( V_63 && V_63 -> V_36 )
V_63 -> V_36 ( V_11 -> V_5 , V_65 ) ;
}
void F_35 ( struct V_1 * V_2 , void * V_56 )
{
struct V_10 * V_11 =
F_8 ( V_2 ) -> V_11 ;
struct V_62 * V_63 = V_11 -> V_63 ;
int V_66 = V_67 ;
F_4 ( L_5 , __FILE__ ) ;
if ( V_56 )
V_66 = * ( int * ) V_56 ;
if ( V_63 && V_63 -> V_37 )
V_63 -> V_37 ( V_11 -> V_5 , V_66 ) ;
}
void F_36 ( struct V_1 * V_2 , void * V_56 )
{
struct V_10 * V_11 =
F_8 ( V_2 ) -> V_11 ;
struct V_62 * V_63 = V_11 -> V_63 ;
int V_66 = V_67 ;
F_4 ( L_5 , __FILE__ ) ;
if ( V_56 )
V_66 = * ( int * ) V_56 ;
if ( V_63 && V_63 -> V_68 )
V_63 -> V_68 ( V_11 -> V_5 , V_66 ) ;
}
void F_37 ( struct V_1 * V_2 , void * V_56 )
{
struct V_10 * V_11 =
F_8 ( V_2 ) -> V_11 ;
struct V_62 * V_63 = V_11 -> V_63 ;
int V_66 = V_67 ;
F_4 ( L_5 , __FILE__ ) ;
if ( V_56 )
V_66 = * ( int * ) V_56 ;
if ( V_63 && V_63 -> V_69 )
V_63 -> V_69 ( V_11 -> V_5 , V_66 ) ;
}
