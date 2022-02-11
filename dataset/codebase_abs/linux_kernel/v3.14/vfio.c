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
static void F_6 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
bool V_13 = false ;
struct V_14 * V_15 ;
F_7 ( & V_11 -> V_16 ) ;
F_8 (kvg, &kv->group_list, node) {
V_13 = true ;
break;
}
if ( V_13 != V_11 -> V_13 ) {
V_11 -> V_13 = V_13 ;
if ( V_11 -> V_13 )
F_9 ( V_9 -> V_17 ) ;
else
F_10 ( V_9 -> V_17 ) ;
}
F_11 ( & V_11 -> V_16 ) ;
}
static int F_12 ( struct V_8 * V_9 , long V_18 , T_1 V_19 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_1 * V_1 ;
struct V_14 * V_15 ;
T_2 T_3 * V_20 = ( T_2 T_3 * ) ( unsigned long ) V_19 ;
struct V_21 V_22 ;
T_2 V_21 ;
int V_23 ;
switch ( V_18 ) {
case V_24 :
if ( F_13 ( V_21 , V_20 ) )
return - V_25 ;
V_22 = F_14 ( V_21 ) ;
if ( ! V_22 . V_2 )
return - V_26 ;
V_1 = F_1 ( V_22 . V_2 ) ;
F_15 ( V_22 ) ;
if ( F_16 ( V_1 ) )
return F_17 ( V_1 ) ;
F_7 ( & V_11 -> V_16 ) ;
F_8 (kvg, &kv->group_list, node) {
if ( V_15 -> V_1 == V_1 ) {
F_11 ( & V_11 -> V_16 ) ;
F_5 ( V_1 ) ;
return - V_27 ;
}
}
V_15 = F_18 ( sizeof( * V_15 ) , V_28 ) ;
if ( ! V_15 ) {
F_11 ( & V_11 -> V_16 ) ;
F_5 ( V_1 ) ;
return - V_29 ;
}
F_19 ( & V_15 -> V_30 , & V_11 -> V_31 ) ;
V_15 -> V_1 = V_1 ;
F_11 ( & V_11 -> V_16 ) ;
F_6 ( V_9 ) ;
return 0 ;
case V_32 :
if ( F_13 ( V_21 , V_20 ) )
return - V_25 ;
V_22 = F_14 ( V_21 ) ;
if ( ! V_22 . V_2 )
return - V_26 ;
V_1 = F_1 ( V_22 . V_2 ) ;
F_15 ( V_22 ) ;
if ( F_16 ( V_1 ) )
return F_17 ( V_1 ) ;
V_23 = - V_33 ;
F_7 ( & V_11 -> V_16 ) ;
F_8 (kvg, &kv->group_list, node) {
if ( V_15 -> V_1 != V_1 )
continue;
F_20 ( & V_15 -> V_30 ) ;
F_5 ( V_15 -> V_1 ) ;
F_21 ( V_15 ) ;
V_23 = 0 ;
break;
}
F_11 ( & V_11 -> V_16 ) ;
F_5 ( V_1 ) ;
F_6 ( V_9 ) ;
return V_23 ;
}
return - V_34 ;
}
static int F_22 ( struct V_8 * V_9 ,
struct V_35 * V_18 )
{
switch ( V_18 -> V_36 ) {
case V_37 :
return F_12 ( V_9 , V_18 -> V_18 , V_18 -> V_38 ) ;
}
return - V_34 ;
}
static int F_23 ( struct V_8 * V_9 ,
struct V_35 * V_18 )
{
switch ( V_18 -> V_36 ) {
case V_37 :
switch ( V_18 -> V_18 ) {
case V_24 :
case V_32 :
return 0 ;
}
break;
}
return - V_34 ;
}
static void F_24 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_14 * V_15 , * V_39 ;
F_25 (kvg, tmp, &kv->group_list, node) {
F_5 ( V_15 -> V_1 ) ;
F_20 ( & V_15 -> V_30 ) ;
F_21 ( V_15 ) ;
}
F_6 ( V_9 ) ;
F_21 ( V_11 ) ;
F_21 ( V_9 ) ;
}
static int F_26 ( struct V_8 * V_9 , T_4 type )
{
struct V_8 * V_39 ;
struct V_10 * V_11 ;
F_8 (tmp, &dev->kvm->devices, vm_node)
if ( V_39 -> V_40 == & V_41 )
return - V_42 ;
V_11 = F_18 ( sizeof( * V_11 ) , V_28 ) ;
if ( ! V_11 )
return - V_29 ;
F_27 ( & V_11 -> V_31 ) ;
F_28 ( & V_11 -> V_16 ) ;
V_9 -> V_12 = V_11 ;
return 0 ;
}
