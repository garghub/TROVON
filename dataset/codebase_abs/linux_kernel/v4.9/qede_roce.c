bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 . V_5 ;
}
static void F_2 ( struct V_1 * V_6 )
{
if ( ! V_7 )
return;
V_6 -> V_8 . V_9 = V_7 -> V_10 ( V_6 -> V_11 , V_6 -> V_12 ,
V_6 -> V_13 ) ;
}
static int F_3 ( struct V_1 * V_6 )
{
F_4 ( & V_6 -> V_8 . V_14 ) ;
V_6 -> V_8 . V_15 = F_5 ( L_1 ) ;
if ( ! V_6 -> V_8 . V_15 ) {
F_6 ( V_6 , L_2 ) ;
return - V_16 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_6 )
{
struct V_17 * V_18 = & V_6 -> V_8 . V_14 ;
struct V_19 * V_20 ;
F_8 ( V_6 -> V_8 . V_15 ) ;
while ( ! F_9 ( V_18 ) ) {
V_20 = F_10 ( V_18 -> V_21 , struct V_19 ,
V_22 ) ;
F_11 ( & V_20 -> V_23 ) ;
F_12 ( & V_20 -> V_22 ) ;
F_13 ( V_20 ) ;
}
}
static void F_14 ( struct V_1 * V_6 )
{
F_7 ( V_6 ) ;
F_15 ( V_6 -> V_8 . V_15 ) ;
}
int F_16 ( struct V_1 * V_6 )
{
int V_24 = 0 ;
if ( F_1 ( V_6 ) ) {
V_24 = F_3 ( V_6 ) ;
if ( V_24 )
return V_24 ;
F_4 ( & V_6 -> V_8 . V_25 ) ;
F_17 ( & V_26 ) ;
F_18 ( & V_6 -> V_8 . V_25 , & V_27 ) ;
F_2 ( V_6 ) ;
F_19 ( & V_26 ) ;
}
return V_24 ;
}
static void F_20 ( struct V_1 * V_6 )
{
if ( V_7 && V_7 -> remove && V_6 -> V_8 . V_9 )
V_7 -> remove ( V_6 -> V_8 . V_9 ) ;
V_6 -> V_8 . V_9 = NULL ;
}
void F_21 ( struct V_1 * V_6 )
{
if ( ! F_1 ( V_6 ) )
return;
F_14 ( V_6 ) ;
F_17 ( & V_26 ) ;
F_20 ( V_6 ) ;
F_12 ( & V_6 -> V_8 . V_25 ) ;
F_19 ( & V_26 ) ;
}
static void F_22 ( struct V_1 * V_6 )
{
if ( V_7 && V_6 -> V_8 . V_9 && V_7 -> V_28 )
V_7 -> V_28 ( V_6 -> V_8 . V_9 , V_29 ) ;
}
static void F_23 ( struct V_1 * V_6 )
{
if ( ! F_1 ( V_6 ) )
return;
F_17 ( & V_26 ) ;
F_22 ( V_6 ) ;
F_19 ( & V_26 ) ;
}
static void F_24 ( struct V_1 * V_6 )
{
if ( V_7 && V_6 -> V_8 . V_9 && V_7 -> V_28 )
V_7 -> V_28 ( V_6 -> V_8 . V_9 , V_30 ) ;
}
static void F_25 ( struct V_1 * V_6 )
{
if ( ! F_1 ( V_6 ) )
return;
F_17 ( & V_26 ) ;
F_24 ( V_6 ) ;
F_19 ( & V_26 ) ;
}
static void F_26 ( struct V_1 * V_6 )
{
if ( ! F_1 ( V_6 ) )
return;
F_17 ( & V_26 ) ;
if ( V_7 && V_6 -> V_8 . V_9 && V_7 -> V_28 )
V_7 -> V_28 ( V_6 -> V_8 . V_9 , V_31 ) ;
F_19 ( & V_26 ) ;
}
int F_27 ( struct V_32 * V_33 )
{
struct V_1 * V_6 ;
T_1 V_34 = 0 ;
F_17 ( & V_26 ) ;
if ( V_7 ) {
F_19 ( & V_26 ) ;
return - V_35 ;
}
V_7 = V_33 ;
F_28 (edev, &qedr_dev_list, rdma_info.entry) {
struct V_36 * V_13 ;
V_34 ++ ;
F_2 ( V_6 ) ;
V_13 = V_6 -> V_13 ;
if ( F_29 ( V_13 ) && F_30 ( V_13 ) )
F_22 ( V_6 ) ;
}
F_19 ( & V_26 ) ;
F_31 ( V_6 , L_3 ,
V_34 ) ;
return 0 ;
}
void F_32 ( struct V_32 * V_33 )
{
struct V_1 * V_6 ;
F_17 ( & V_26 ) ;
F_28 (edev, &qedr_dev_list, rdma_info.entry) {
if ( V_6 -> V_8 . V_9 )
F_20 ( V_6 ) ;
}
V_7 = NULL ;
F_19 ( & V_26 ) ;
}
static void F_33 ( struct V_1 * V_6 )
{
if ( ! F_1 ( V_6 ) )
return;
if ( V_7 && V_6 -> V_8 . V_9 && V_7 -> V_28 )
V_7 -> V_28 ( V_6 -> V_8 . V_9 , V_37 ) ;
}
struct V_19 * F_34 ( struct V_1
* V_6 )
{
struct V_19 * V_20 = NULL ;
struct V_17 * V_38 = NULL ;
bool V_39 = false ;
F_35 (list_node, &edev->rdma_info.roce_event_list) {
V_20 = F_10 ( V_38 , struct V_19 ,
V_22 ) ;
if ( ! F_36 ( & V_20 -> V_23 ) ) {
V_39 = true ;
break;
}
}
if ( ! V_39 ) {
V_20 = F_37 ( sizeof( * V_20 ) , V_40 ) ;
if ( ! V_20 ) {
F_6 ( V_6 ,
L_4 ) ;
return NULL ;
}
F_18 ( & V_20 -> V_22 ,
& V_6 -> V_8 . V_14 ) ;
}
return V_20 ;
}
static void F_38 ( struct V_41 * V_23 )
{
struct V_19 * V_20 ;
enum V_42 V_43 ;
struct V_1 * V_6 ;
V_20 = F_39 ( V_23 , struct V_19 , V_23 ) ;
V_43 = V_20 -> V_43 ;
V_6 = V_20 -> V_44 ;
switch ( V_43 ) {
case V_29 :
F_23 ( V_6 ) ;
break;
case V_30 :
F_25 ( V_6 ) ;
break;
case V_31 :
F_26 ( V_6 ) ;
break;
case V_37 :
F_33 ( V_6 ) ;
break;
default:
F_6 ( V_6 , L_5 , V_43 ) ;
}
}
static void F_40 ( struct V_1 * V_6 ,
enum V_42 V_43 )
{
struct V_19 * V_20 ;
if ( ! V_6 -> V_8 . V_9 )
return;
V_20 = F_34 ( V_6 ) ;
if ( ! V_20 )
return;
V_20 -> V_43 = V_43 ;
V_20 -> V_44 = V_6 ;
F_41 ( & V_20 -> V_23 , F_38 ) ;
F_42 ( V_6 -> V_8 . V_15 , & V_20 -> V_23 ) ;
}
void F_43 ( struct V_1 * V_6 )
{
F_40 ( V_6 , V_29 ) ;
}
void F_44 ( struct V_1 * V_6 )
{
F_40 ( V_6 , V_30 ) ;
}
void F_45 ( struct V_1 * V_6 )
{
F_40 ( V_6 , V_37 ) ;
}
