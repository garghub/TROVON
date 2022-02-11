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
static void F_6 ( struct V_1 * V_8 , struct V_9 * V_9 )
{
void (* V_4)( struct V_1 * , struct V_9 * );
V_4 = F_2 ( V_10 ) ;
if ( ! V_4 )
return;
V_4 ( V_8 , V_9 ) ;
F_4 ( V_10 ) ;
}
static bool F_7 ( struct V_1 * V_1 )
{
long (* V_4)( struct V_1 * , unsigned long );
long V_11 ;
V_4 = F_2 ( V_12 ) ;
if ( ! V_4 )
return false ;
V_11 = V_4 ( V_1 , V_13 ) ;
F_4 ( V_12 ) ;
return V_11 > 0 ;
}
static void F_8 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
bool V_19 = false ;
struct V_20 * V_21 ;
F_9 ( & V_17 -> V_22 ) ;
F_10 (kvg, &kv->group_list, node) {
if ( ! F_7 ( V_21 -> V_1 ) ) {
V_19 = true ;
break;
}
}
if ( V_19 != V_17 -> V_19 ) {
V_17 -> V_19 = V_19 ;
if ( V_17 -> V_19 )
F_11 ( V_15 -> V_9 ) ;
else
F_12 ( V_15 -> V_9 ) ;
}
F_13 ( & V_17 -> V_22 ) ;
}
static int F_14 ( struct V_14 * V_15 , long V_23 , T_1 V_24 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_1 * V_1 ;
struct V_20 * V_21 ;
T_2 T_3 * V_25 = ( T_2 T_3 * ) ( unsigned long ) V_24 ;
struct V_26 V_27 ;
T_2 V_26 ;
int V_11 ;
switch ( V_23 ) {
case V_28 :
if ( F_15 ( V_26 , V_25 ) )
return - V_29 ;
V_27 = F_16 ( V_26 ) ;
if ( ! V_27 . V_2 )
return - V_30 ;
V_1 = F_1 ( V_27 . V_2 ) ;
F_17 ( V_27 ) ;
if ( F_18 ( V_1 ) )
return F_19 ( V_1 ) ;
F_9 ( & V_17 -> V_22 ) ;
F_10 (kvg, &kv->group_list, node) {
if ( V_21 -> V_1 == V_1 ) {
F_13 ( & V_17 -> V_22 ) ;
F_5 ( V_1 ) ;
return - V_31 ;
}
}
V_21 = F_20 ( sizeof( * V_21 ) , V_32 ) ;
if ( ! V_21 ) {
F_13 ( & V_17 -> V_22 ) ;
F_5 ( V_1 ) ;
return - V_33 ;
}
F_21 ( & V_21 -> V_34 , & V_17 -> V_35 ) ;
V_21 -> V_1 = V_1 ;
F_22 ( V_15 -> V_9 ) ;
F_13 ( & V_17 -> V_22 ) ;
F_6 ( V_1 , V_15 -> V_9 ) ;
F_8 ( V_15 ) ;
return 0 ;
case V_36 :
if ( F_15 ( V_26 , V_25 ) )
return - V_29 ;
V_27 = F_16 ( V_26 ) ;
if ( ! V_27 . V_2 )
return - V_30 ;
V_1 = F_1 ( V_27 . V_2 ) ;
F_17 ( V_27 ) ;
if ( F_18 ( V_1 ) )
return F_19 ( V_1 ) ;
V_11 = - V_37 ;
F_9 ( & V_17 -> V_22 ) ;
F_10 (kvg, &kv->group_list, node) {
if ( V_21 -> V_1 != V_1 )
continue;
F_23 ( & V_21 -> V_34 ) ;
F_5 ( V_21 -> V_1 ) ;
F_24 ( V_21 ) ;
V_11 = 0 ;
break;
}
F_25 ( V_15 -> V_9 ) ;
F_13 ( & V_17 -> V_22 ) ;
F_6 ( V_1 , NULL ) ;
F_5 ( V_1 ) ;
F_8 ( V_15 ) ;
return V_11 ;
}
return - V_38 ;
}
static int F_26 ( struct V_14 * V_15 ,
struct V_39 * V_23 )
{
switch ( V_23 -> V_8 ) {
case V_40 :
return F_14 ( V_15 , V_23 -> V_23 , V_23 -> V_41 ) ;
}
return - V_38 ;
}
static int F_27 ( struct V_14 * V_15 ,
struct V_39 * V_23 )
{
switch ( V_23 -> V_8 ) {
case V_40 :
switch ( V_23 -> V_23 ) {
case V_28 :
case V_36 :
return 0 ;
}
break;
}
return - V_38 ;
}
static void F_28 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_20 * V_21 , * V_42 ;
F_29 (kvg, tmp, &kv->group_list, node) {
F_6 ( V_21 -> V_1 , NULL ) ;
F_5 ( V_21 -> V_1 ) ;
F_23 ( & V_21 -> V_34 ) ;
F_24 ( V_21 ) ;
F_25 ( V_15 -> V_9 ) ;
}
F_8 ( V_15 ) ;
F_24 ( V_17 ) ;
F_24 ( V_15 ) ;
}
static int F_30 ( struct V_14 * V_15 , T_4 type )
{
struct V_14 * V_42 ;
struct V_16 * V_17 ;
F_10 (tmp, &dev->kvm->devices, vm_node)
if ( V_42 -> V_43 == & V_44 )
return - V_45 ;
V_17 = F_20 ( sizeof( * V_17 ) , V_32 ) ;
if ( ! V_17 )
return - V_33 ;
F_31 ( & V_17 -> V_35 ) ;
F_32 ( & V_17 -> V_22 ) ;
V_15 -> V_18 = V_17 ;
return 0 ;
}
int F_33 ( void )
{
return F_34 ( & V_44 , V_46 ) ;
}
void F_35 ( void )
{
F_36 ( V_46 ) ;
}
