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
static bool F_5 ( struct V_1 * V_7 ,
struct V_2 * V_3 )
{
bool V_8 , ( * V_4 ) ( struct V_1 * , struct V_2 * );
V_4 = F_2 ( V_9 ) ;
if ( ! V_4 )
return false ;
V_8 = V_4 ( V_7 , V_3 ) ;
F_4 ( V_9 ) ;
return V_8 ;
}
static void F_6 ( struct V_1 * V_1 )
{
void (* V_4)( struct V_1 * );
V_4 = F_2 ( V_10 ) ;
if ( ! V_4 )
return;
V_4 ( V_1 ) ;
F_4 ( V_10 ) ;
}
static void F_7 ( struct V_1 * V_7 , struct V_11 * V_11 )
{
void (* V_4)( struct V_1 * , struct V_11 * );
V_4 = F_2 ( V_12 ) ;
if ( ! V_4 )
return;
V_4 ( V_7 , V_11 ) ;
F_4 ( V_12 ) ;
}
static bool F_8 ( struct V_1 * V_1 )
{
long (* V_4)( struct V_1 * , unsigned long );
long V_8 ;
V_4 = F_2 ( V_13 ) ;
if ( ! V_4 )
return false ;
V_8 = V_4 ( V_1 , V_14 ) ;
F_4 ( V_13 ) ;
return V_8 > 0 ;
}
static int F_9 ( struct V_1 * V_1 )
{
int (* V_4)( struct V_1 * );
int V_8 = - V_6 ;
V_4 = F_2 ( V_15 ) ;
if ( ! V_4 )
return V_8 ;
V_8 = V_4 ( V_1 ) ;
F_4 ( V_15 ) ;
return V_8 ;
}
static struct V_16 * F_10 (
struct V_1 * V_7 )
{
int V_17 = F_9 ( V_7 ) ;
if ( V_17 < 0 )
return NULL ;
return F_11 ( V_17 ) ;
}
static void F_12 ( struct V_11 * V_11 ,
struct V_1 * V_1 )
{
struct V_16 * V_18 = F_10 ( V_1 ) ;
if ( F_13 ( ! V_18 ) )
return;
F_14 ( V_11 , V_18 ) ;
F_15 ( V_18 ) ;
}
static void F_16 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
bool V_24 = false ;
struct V_25 * V_26 ;
F_17 ( & V_22 -> V_27 ) ;
F_18 (kvg, &kv->group_list, node) {
if ( ! F_8 ( V_26 -> V_1 ) ) {
V_24 = true ;
break;
}
}
if ( V_24 != V_22 -> V_24 ) {
V_22 -> V_24 = V_24 ;
if ( V_22 -> V_24 )
F_19 ( V_20 -> V_11 ) ;
else
F_20 ( V_20 -> V_11 ) ;
}
F_21 ( & V_22 -> V_27 ) ;
}
static int F_22 ( struct V_19 * V_20 , long V_28 , T_1 V_29 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_1 * V_1 ;
struct V_25 * V_26 ;
T_2 T_3 * V_30 = ( T_2 T_3 * ) ( unsigned long ) V_29 ;
struct V_31 V_32 ;
T_2 V_31 ;
int V_8 ;
switch ( V_28 ) {
case V_33 :
if ( F_23 ( V_31 , V_30 ) )
return - V_34 ;
V_32 = F_24 ( V_31 ) ;
if ( ! V_32 . V_2 )
return - V_35 ;
V_1 = F_1 ( V_32 . V_2 ) ;
F_25 ( V_32 ) ;
if ( F_26 ( V_1 ) )
return F_27 ( V_1 ) ;
F_17 ( & V_22 -> V_27 ) ;
F_18 (kvg, &kv->group_list, node) {
if ( V_26 -> V_1 == V_1 ) {
F_21 ( & V_22 -> V_27 ) ;
F_6 ( V_1 ) ;
return - V_36 ;
}
}
V_26 = F_28 ( sizeof( * V_26 ) , V_37 ) ;
if ( ! V_26 ) {
F_21 ( & V_22 -> V_27 ) ;
F_6 ( V_1 ) ;
return - V_38 ;
}
F_29 ( & V_26 -> V_39 , & V_22 -> V_40 ) ;
V_26 -> V_1 = V_1 ;
F_30 ( V_20 -> V_11 ) ;
F_21 ( & V_22 -> V_27 ) ;
F_7 ( V_1 , V_20 -> V_11 ) ;
F_16 ( V_20 ) ;
return 0 ;
case V_41 :
if ( F_23 ( V_31 , V_30 ) )
return - V_34 ;
V_32 = F_24 ( V_31 ) ;
if ( ! V_32 . V_2 )
return - V_35 ;
V_8 = - V_42 ;
F_17 ( & V_22 -> V_27 ) ;
F_18 (kvg, &kv->group_list, node) {
if ( ! F_5 ( V_26 -> V_1 ,
V_32 . V_2 ) )
continue;
F_31 ( & V_26 -> V_39 ) ;
F_32 ( V_20 -> V_11 ) ;
#ifdef F_33
F_12 ( V_20 -> V_11 ,
V_26 -> V_1 ) ;
#endif
F_7 ( V_26 -> V_1 , NULL ) ;
F_6 ( V_26 -> V_1 ) ;
F_34 ( V_26 ) ;
V_8 = 0 ;
break;
}
F_21 ( & V_22 -> V_27 ) ;
F_25 ( V_32 ) ;
F_16 ( V_20 ) ;
return V_8 ;
#ifdef F_33
case V_43 : {
struct V_44 V_45 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_1 * V_1 ;
struct V_25 * V_26 ;
struct V_31 V_32 ;
struct V_16 * V_18 ;
if ( F_35 ( & V_45 , ( void T_3 * ) V_29 ,
sizeof( struct V_44 ) ) )
return - V_34 ;
V_32 = F_24 ( V_45 . V_46 ) ;
if ( ! V_32 . V_2 )
return - V_35 ;
V_1 = F_1 ( V_32 . V_2 ) ;
F_25 ( V_32 ) ;
if ( F_26 ( V_1 ) )
return F_27 ( V_1 ) ;
V_18 = F_10 ( V_1 ) ;
if ( F_13 ( ! V_18 ) ) {
F_6 ( V_1 ) ;
return - V_47 ;
}
V_8 = - V_42 ;
F_17 ( & V_22 -> V_27 ) ;
F_18 (kvg, &kv->group_list, node) {
if ( V_26 -> V_1 != V_1 )
continue;
V_8 = F_36 ( V_20 -> V_11 ,
V_45 . V_48 , V_18 ) ;
break;
}
F_21 ( & V_22 -> V_27 ) ;
F_15 ( V_18 ) ;
F_6 ( V_1 ) ;
return V_8 ;
}
#endif
}
return - V_49 ;
}
static int F_37 ( struct V_19 * V_20 ,
struct V_50 * V_28 )
{
switch ( V_28 -> V_7 ) {
case V_51 :
return F_22 ( V_20 , V_28 -> V_28 , V_28 -> V_52 ) ;
}
return - V_49 ;
}
static int F_38 ( struct V_19 * V_20 ,
struct V_50 * V_28 )
{
switch ( V_28 -> V_7 ) {
case V_51 :
switch ( V_28 -> V_28 ) {
case V_33 :
case V_41 :
#ifdef F_33
case V_43 :
#endif
return 0 ;
}
break;
}
return - V_49 ;
}
static void F_39 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_25 * V_26 , * V_53 ;
F_40 (kvg, tmp, &kv->group_list, node) {
#ifdef F_33
F_12 ( V_20 -> V_11 , V_26 -> V_1 ) ;
#endif
F_7 ( V_26 -> V_1 , NULL ) ;
F_6 ( V_26 -> V_1 ) ;
F_31 ( & V_26 -> V_39 ) ;
F_34 ( V_26 ) ;
F_32 ( V_20 -> V_11 ) ;
}
F_16 ( V_20 ) ;
F_34 ( V_22 ) ;
F_34 ( V_20 ) ;
}
static int F_41 ( struct V_19 * V_20 , T_4 type )
{
struct V_19 * V_53 ;
struct V_21 * V_22 ;
F_18 (tmp, &dev->kvm->devices, vm_node)
if ( V_53 -> V_54 == & V_55 )
return - V_56 ;
V_22 = F_28 ( sizeof( * V_22 ) , V_37 ) ;
if ( ! V_22 )
return - V_38 ;
F_42 ( & V_22 -> V_40 ) ;
F_43 ( & V_22 -> V_27 ) ;
V_20 -> V_23 = V_22 ;
return 0 ;
}
int F_44 ( void )
{
return F_45 ( & V_55 , V_57 ) ;
}
void F_46 ( void )
{
F_47 ( V_57 ) ;
}
