static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
F_3 ( L_1 , __FILE__ , V_3 ) ;
switch ( V_3 ) {
case V_13 :
if ( V_11 && V_11 -> V_14 )
V_11 -> V_14 ( V_9 -> V_5 ) ;
break;
case V_15 :
case V_16 :
case V_17 :
if ( V_11 && V_11 -> V_18 )
V_11 -> V_18 ( V_9 -> V_5 ) ;
break;
default:
F_4 ( L_2 , V_3 ) ;
break;
}
F_5 (connector, &dev->mode_config.connector_list, head) {
if ( V_7 -> V_2 == V_2 ) {
struct V_19 * V_20 =
V_9 -> V_20 ;
F_3 ( L_3 ,
V_7 -> V_21 . V_22 , V_3 ) ;
if ( V_20 && V_20 -> V_23 )
V_20 -> V_23 ( V_9 -> V_5 , V_3 ) ;
}
}
}
static bool
F_6 ( struct V_1 * V_2 ,
struct V_24 * V_3 ,
struct V_24 * V_25 )
{
F_3 ( L_4 , __FILE__ ) ;
return true ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_24 * V_3 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_26 * V_27 = V_9 -> V_27 ;
struct V_28 * V_29 = F_8 ( V_5 ,
V_2 -> V_30 ) ;
F_3 ( L_4 , __FILE__ ) ;
V_3 = V_25 ;
F_5 (connector, &dev->mode_config.connector_list, head) {
if ( V_7 -> V_2 == V_2 ) {
if ( V_11 && V_11 -> V_31 )
V_11 -> V_31 ( V_9 -> V_5 , V_3 ) ;
if ( V_27 && V_27 -> V_31 )
V_27 -> V_31 ( V_9 -> V_5 , V_29 ) ;
}
}
}
static void F_9 ( struct V_1 * V_2 )
{
F_3 ( L_4 , __FILE__ ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
F_3 ( L_4 , __FILE__ ) ;
if ( V_11 && V_11 -> V_14 )
V_11 -> V_14 ( V_9 -> V_5 ) ;
}
static struct V_32 *
F_11 ( struct V_1 * V_2 )
{
return V_2 -> V_30 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_33 * V_34 =
F_13 ( V_2 ) ;
F_3 ( L_4 , __FILE__ ) ;
V_34 -> V_9 -> V_35 = - 1 ;
F_14 ( V_2 ) ;
V_2 -> V_5 -> V_36 . V_37 -- ;
F_15 ( V_34 ) ;
}
struct V_1 *
F_16 ( struct V_4 * V_5 ,
struct V_8 * V_9 ,
unsigned int V_38 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
F_3 ( L_4 , __FILE__ ) ;
if ( ! V_9 || ! V_38 )
return NULL ;
if ( ! V_9 -> V_5 )
return NULL ;
V_34 = F_17 ( sizeof( * V_34 ) , V_39 ) ;
if ( ! V_34 ) {
F_4 ( L_5 ) ;
return NULL ;
}
V_34 -> V_9 = V_9 ;
V_2 = & V_34 -> V_1 ;
V_2 -> V_38 = V_38 ;
F_3 ( L_6 , V_2 -> V_38 ) ;
F_18 ( V_5 , V_2 , & V_40 ,
V_41 ) ;
F_19 ( V_2 , & V_42 ) ;
F_3 ( L_7 ) ;
return V_2 ;
}
struct V_8 * F_2 ( struct V_1 * V_2 )
{
return F_13 ( V_2 ) -> V_9 ;
}
void F_20 ( struct V_32 * V_30 , void * V_43 ,
void (* F_21)( struct V_1 * , void * ) )
{
struct V_4 * V_5 = V_30 -> V_5 ;
struct V_1 * V_2 ;
struct V_44 * V_45 = V_5 -> V_46 ;
struct V_8 * V_9 ;
F_5 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! V_2 -> V_30 ) {
V_9 = F_13 ( V_2 ) -> V_9 ;
if ( V_9 -> V_35 < 0 ||
V_45 -> V_30 [ V_9 -> V_35 ] != V_30 )
continue;
} else {
if ( V_2 -> V_30 != V_30 )
continue;
}
F_21 ( V_2 , V_43 ) ;
}
}
void F_22 ( struct V_1 * V_2 , void * V_43 )
{
struct V_8 * V_9 =
F_13 ( V_2 ) -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_30 = * ( int * ) V_43 ;
if ( V_9 -> V_35 == - 1 )
V_9 -> V_35 = V_30 ;
if ( V_11 -> V_47 )
V_11 -> V_47 ( V_9 -> V_5 ) ;
}
void F_23 ( struct V_1 * V_2 , void * V_43 )
{
struct V_8 * V_9 =
F_13 ( V_2 ) -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_30 = * ( int * ) V_43 ;
if ( V_9 -> V_35 == - 1 )
V_9 -> V_35 = V_30 ;
if ( V_11 -> V_48 )
V_11 -> V_48 ( V_9 -> V_5 ) ;
}
void F_24 ( struct V_1 * V_2 , void * V_43 )
{
struct V_8 * V_9 =
F_13 ( V_2 ) -> V_9 ;
struct V_26 * V_27 = V_9 -> V_27 ;
int V_30 = * ( int * ) V_43 ;
F_3 ( L_4 , __FILE__ ) ;
V_9 -> V_35 = V_30 ;
if ( V_27 && V_27 -> V_14 )
V_27 -> V_14 ( V_9 -> V_5 ) ;
}
void F_25 ( struct V_1 * V_2 , void * V_43 )
{
struct V_8 * V_9 =
F_13 ( V_2 ) -> V_9 ;
struct V_26 * V_27 = V_9 -> V_27 ;
struct V_28 * V_29 = V_43 ;
if ( V_27 && V_27 -> V_31 )
V_27 -> V_31 ( V_9 -> V_5 , V_29 ) ;
}
void F_26 ( struct V_1 * V_2 , void * V_43 )
{
struct V_8 * V_9 =
F_13 ( V_2 ) -> V_9 ;
struct V_26 * V_27 = V_9 -> V_27 ;
F_3 ( L_8 ) ;
if ( V_27 && V_27 -> V_18 )
V_27 -> V_18 ( V_9 -> V_5 ) ;
if ( ! V_2 -> V_30 )
V_9 -> V_35 = - 1 ;
}
