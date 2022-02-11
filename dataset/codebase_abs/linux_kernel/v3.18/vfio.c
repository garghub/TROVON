static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
struct V_1 * ( * V_4 ) ( struct V_2 * ) ;
V_4 = F_2 ( V_5 ) ;
if ( ! V_4 )
return F_3 ( - V_6 ) ;
V_1 = V_4 ( V_3 ) ;
F_4 ( V_5 ) ;
return V_1 ;
}
static void F_5 ( struct V_1 * V_1 )
{
void (* V_4)( struct V_1 * );
V_4 = F_2 ( V_7 ) ;
if ( ! V_4 )
return;
V_4 ( V_1 ) ;
F_4 ( V_7 ) ;
}
static bool F_6 ( struct V_1 * V_1 )
{
long (* V_4)( struct V_1 * , unsigned long );
long V_8 ;
V_4 = F_2 ( V_9 ) ;
if ( ! V_4 )
return false ;
V_8 = V_4 ( V_1 , V_10 ) ;
F_4 ( V_9 ) ;
return V_8 > 0 ;
}
static void F_7 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
bool V_16 = false ;
struct V_17 * V_18 ;
F_8 ( & V_14 -> V_19 ) ;
F_9 (kvg, &kv->group_list, node) {
if ( ! F_6 ( V_18 -> V_1 ) ) {
V_16 = true ;
break;
}
}
if ( V_16 != V_14 -> V_16 ) {
V_14 -> V_16 = V_16 ;
if ( V_14 -> V_16 )
F_10 ( V_12 -> V_20 ) ;
else
F_11 ( V_12 -> V_20 ) ;
}
F_12 ( & V_14 -> V_19 ) ;
}
static int F_13 ( struct V_11 * V_12 , long V_21 , T_1 V_22 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_1 * V_1 ;
struct V_17 * V_18 ;
T_2 T_3 * V_23 = ( T_2 T_3 * ) ( unsigned long ) V_22 ;
struct V_24 V_25 ;
T_2 V_24 ;
int V_8 ;
switch ( V_21 ) {
case V_26 :
if ( F_14 ( V_24 , V_23 ) )
return - V_27 ;
V_25 = F_15 ( V_24 ) ;
if ( ! V_25 . V_2 )
return - V_28 ;
V_1 = F_1 ( V_25 . V_2 ) ;
F_16 ( V_25 ) ;
if ( F_17 ( V_1 ) )
return F_18 ( V_1 ) ;
F_8 ( & V_14 -> V_19 ) ;
F_9 (kvg, &kv->group_list, node) {
if ( V_18 -> V_1 == V_1 ) {
F_12 ( & V_14 -> V_19 ) ;
F_5 ( V_1 ) ;
return - V_29 ;
}
}
V_18 = F_19 ( sizeof( * V_18 ) , V_30 ) ;
if ( ! V_18 ) {
F_12 ( & V_14 -> V_19 ) ;
F_5 ( V_1 ) ;
return - V_31 ;
}
F_20 ( & V_18 -> V_32 , & V_14 -> V_33 ) ;
V_18 -> V_1 = V_1 ;
F_12 ( & V_14 -> V_19 ) ;
F_7 ( V_12 ) ;
return 0 ;
case V_34 :
if ( F_14 ( V_24 , V_23 ) )
return - V_27 ;
V_25 = F_15 ( V_24 ) ;
if ( ! V_25 . V_2 )
return - V_28 ;
V_1 = F_1 ( V_25 . V_2 ) ;
F_16 ( V_25 ) ;
if ( F_17 ( V_1 ) )
return F_18 ( V_1 ) ;
V_8 = - V_35 ;
F_8 ( & V_14 -> V_19 ) ;
F_9 (kvg, &kv->group_list, node) {
if ( V_18 -> V_1 != V_1 )
continue;
F_21 ( & V_18 -> V_32 ) ;
F_5 ( V_18 -> V_1 ) ;
F_22 ( V_18 ) ;
V_8 = 0 ;
break;
}
F_12 ( & V_14 -> V_19 ) ;
F_5 ( V_1 ) ;
F_7 ( V_12 ) ;
return V_8 ;
}
return - V_36 ;
}
static int F_23 ( struct V_11 * V_12 ,
struct V_37 * V_21 )
{
switch ( V_21 -> V_38 ) {
case V_39 :
return F_13 ( V_12 , V_21 -> V_21 , V_21 -> V_40 ) ;
}
return - V_36 ;
}
static int F_24 ( struct V_11 * V_12 ,
struct V_37 * V_21 )
{
switch ( V_21 -> V_38 ) {
case V_39 :
switch ( V_21 -> V_21 ) {
case V_26 :
case V_34 :
return 0 ;
}
break;
}
return - V_36 ;
}
static void F_25 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_17 * V_18 , * V_41 ;
F_26 (kvg, tmp, &kv->group_list, node) {
F_5 ( V_18 -> V_1 ) ;
F_21 ( & V_18 -> V_32 ) ;
F_22 ( V_18 ) ;
}
F_7 ( V_12 ) ;
F_22 ( V_14 ) ;
F_22 ( V_12 ) ;
}
static int F_27 ( struct V_11 * V_12 , T_4 type )
{
struct V_11 * V_41 ;
struct V_13 * V_14 ;
F_9 (tmp, &dev->kvm->devices, vm_node)
if ( V_41 -> V_42 == & V_43 )
return - V_44 ;
V_14 = F_19 ( sizeof( * V_14 ) , V_30 ) ;
if ( ! V_14 )
return - V_31 ;
F_28 ( & V_14 -> V_33 ) ;
F_29 ( & V_14 -> V_19 ) ;
V_12 -> V_15 = V_14 ;
return 0 ;
}
int F_30 ( void )
{
return F_31 ( & V_43 , V_45 ) ;
}
void F_32 ( void )
{
F_33 ( V_45 ) ;
}
