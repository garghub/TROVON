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
static int F_8 ( struct V_1 * V_1 )
{
int (* V_4)( struct V_1 * );
int V_11 = - V_6 ;
V_4 = F_2 ( V_14 ) ;
if ( ! V_4 )
return V_11 ;
V_11 = V_4 ( V_1 ) ;
F_4 ( V_14 ) ;
return V_11 ;
}
static struct V_15 * F_9 (
struct V_1 * V_8 )
{
int V_16 = F_8 ( V_8 ) ;
if ( V_16 < 0 )
return NULL ;
return F_10 ( V_16 ) ;
}
static void F_11 ( struct V_9 * V_9 ,
struct V_1 * V_1 )
{
struct V_15 * V_17 = F_9 ( V_1 ) ;
if ( F_12 ( ! V_17 ) )
return;
F_13 ( V_9 , V_17 ) ;
F_14 ( V_17 ) ;
}
static void F_15 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 ;
bool V_23 = false ;
struct V_24 * V_25 ;
F_16 ( & V_21 -> V_26 ) ;
F_17 (kvg, &kv->group_list, node) {
if ( ! F_7 ( V_25 -> V_1 ) ) {
V_23 = true ;
break;
}
}
if ( V_23 != V_21 -> V_23 ) {
V_21 -> V_23 = V_23 ;
if ( V_21 -> V_23 )
F_18 ( V_19 -> V_9 ) ;
else
F_19 ( V_19 -> V_9 ) ;
}
F_20 ( & V_21 -> V_26 ) ;
}
static int F_21 ( struct V_18 * V_19 , long V_27 , T_1 V_28 )
{
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_1 * V_1 ;
struct V_24 * V_25 ;
T_2 T_3 * V_29 = ( T_2 T_3 * ) ( unsigned long ) V_28 ;
struct V_30 V_31 ;
T_2 V_30 ;
int V_11 ;
switch ( V_27 ) {
case V_32 :
if ( F_22 ( V_30 , V_29 ) )
return - V_33 ;
V_31 = F_23 ( V_30 ) ;
if ( ! V_31 . V_2 )
return - V_34 ;
V_1 = F_1 ( V_31 . V_2 ) ;
F_24 ( V_31 ) ;
if ( F_25 ( V_1 ) )
return F_26 ( V_1 ) ;
F_16 ( & V_21 -> V_26 ) ;
F_17 (kvg, &kv->group_list, node) {
if ( V_25 -> V_1 == V_1 ) {
F_20 ( & V_21 -> V_26 ) ;
F_5 ( V_1 ) ;
return - V_35 ;
}
}
V_25 = F_27 ( sizeof( * V_25 ) , V_36 ) ;
if ( ! V_25 ) {
F_20 ( & V_21 -> V_26 ) ;
F_5 ( V_1 ) ;
return - V_37 ;
}
F_28 ( & V_25 -> V_38 , & V_21 -> V_39 ) ;
V_25 -> V_1 = V_1 ;
F_29 ( V_19 -> V_9 ) ;
F_20 ( & V_21 -> V_26 ) ;
F_6 ( V_1 , V_19 -> V_9 ) ;
F_15 ( V_19 ) ;
return 0 ;
case V_40 :
if ( F_22 ( V_30 , V_29 ) )
return - V_33 ;
V_31 = F_23 ( V_30 ) ;
if ( ! V_31 . V_2 )
return - V_34 ;
V_1 = F_1 ( V_31 . V_2 ) ;
F_24 ( V_31 ) ;
if ( F_25 ( V_1 ) )
return F_26 ( V_1 ) ;
V_11 = - V_41 ;
F_16 ( & V_21 -> V_26 ) ;
F_17 (kvg, &kv->group_list, node) {
if ( V_25 -> V_1 != V_1 )
continue;
F_30 ( & V_25 -> V_38 ) ;
F_5 ( V_25 -> V_1 ) ;
F_31 ( V_25 ) ;
V_11 = 0 ;
break;
}
F_32 ( V_19 -> V_9 ) ;
F_20 ( & V_21 -> V_26 ) ;
#ifdef F_33
F_11 ( V_19 -> V_9 , V_1 ) ;
#endif
F_6 ( V_1 , NULL ) ;
F_5 ( V_1 ) ;
F_15 ( V_19 ) ;
return V_11 ;
#ifdef F_33
case V_42 : {
struct V_43 V_44 ;
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_1 * V_1 ;
struct V_24 * V_25 ;
struct V_30 V_31 ;
struct V_15 * V_17 ;
if ( F_34 ( & V_44 , ( void T_3 * ) V_28 ,
sizeof( struct V_43 ) ) )
return - V_33 ;
V_31 = F_23 ( V_44 . V_45 ) ;
if ( ! V_31 . V_2 )
return - V_34 ;
V_1 = F_1 ( V_31 . V_2 ) ;
F_24 ( V_31 ) ;
if ( F_25 ( V_1 ) )
return F_26 ( V_1 ) ;
V_17 = F_9 ( V_1 ) ;
if ( F_12 ( ! V_17 ) ) {
F_5 ( V_1 ) ;
return - V_46 ;
}
V_11 = - V_41 ;
F_16 ( & V_21 -> V_26 ) ;
F_17 (kvg, &kv->group_list, node) {
if ( V_25 -> V_1 != V_1 )
continue;
V_11 = F_35 ( V_19 -> V_9 ,
V_44 . V_47 , V_17 ) ;
break;
}
F_20 ( & V_21 -> V_26 ) ;
F_14 ( V_17 ) ;
F_5 ( V_1 ) ;
return V_11 ;
}
#endif
}
return - V_48 ;
}
static int F_36 ( struct V_18 * V_19 ,
struct V_49 * V_27 )
{
switch ( V_27 -> V_8 ) {
case V_50 :
return F_21 ( V_19 , V_27 -> V_27 , V_27 -> V_51 ) ;
}
return - V_48 ;
}
static int F_37 ( struct V_18 * V_19 ,
struct V_49 * V_27 )
{
switch ( V_27 -> V_8 ) {
case V_50 :
switch ( V_27 -> V_27 ) {
case V_32 :
case V_40 :
#ifdef F_33
case V_42 :
#endif
return 0 ;
}
break;
}
return - V_48 ;
}
static void F_38 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_24 * V_25 , * V_52 ;
F_39 (kvg, tmp, &kv->group_list, node) {
#ifdef F_33
F_11 ( V_19 -> V_9 , V_25 -> V_1 ) ;
#endif
F_6 ( V_25 -> V_1 , NULL ) ;
F_5 ( V_25 -> V_1 ) ;
F_30 ( & V_25 -> V_38 ) ;
F_31 ( V_25 ) ;
F_32 ( V_19 -> V_9 ) ;
}
F_15 ( V_19 ) ;
F_31 ( V_21 ) ;
F_31 ( V_19 ) ;
}
static int F_40 ( struct V_18 * V_19 , T_4 type )
{
struct V_18 * V_52 ;
struct V_20 * V_21 ;
F_17 (tmp, &dev->kvm->devices, vm_node)
if ( V_52 -> V_53 == & V_54 )
return - V_55 ;
V_21 = F_27 ( sizeof( * V_21 ) , V_36 ) ;
if ( ! V_21 )
return - V_37 ;
F_41 ( & V_21 -> V_39 ) ;
F_42 ( & V_21 -> V_26 ) ;
V_19 -> V_22 = V_21 ;
return 0 ;
}
int F_43 ( void )
{
return F_44 ( & V_54 , V_56 ) ;
}
void F_45 ( void )
{
F_46 ( V_56 ) ;
}
