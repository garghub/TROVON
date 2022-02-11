void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! F_2 ( V_2 , V_4 ) &&
! F_2 ( V_2 , V_5 ) )
return;
F_3 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_7 , V_3 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_8 ;
F_3 ( & V_2 -> V_6 ) ;
V_8 = F_7 ( & V_2 -> V_7 , NULL , V_9 , 0 ,
V_10 ) ;
F_5 ( & V_2 -> V_6 ) ;
return V_8 ;
}
void F_8 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 , V_4 ) &&
! F_2 ( V_2 , V_5 ) )
return;
F_9 ( & V_2 -> V_7 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 , V_4 ) &&
! F_2 ( V_2 , V_5 ) )
return;
F_3 ( & V_2 -> V_6 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
void F_12 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_13 * V_14 , * V_15 ;
if ( ! F_2 ( V_2 , V_4 ) &&
! F_2 ( V_2 , V_5 ) )
return;
F_3 ( & V_2 -> V_16 ) ;
F_13 (pos, tmp, &dev->ctxlist, head) {
if ( V_14 -> V_17 == V_12 &&
V_14 -> V_18 != V_19 ) {
if ( V_2 -> V_20 -> V_21 )
V_2 -> V_20 -> V_21 ( V_2 , V_14 -> V_18 ) ;
F_1 ( V_2 , V_14 -> V_18 ) ;
F_14 ( & V_14 -> V_22 ) ;
F_15 ( V_14 ) ;
}
}
F_5 ( & V_2 -> V_16 ) ;
}
int F_16 ( struct V_1 * V_2 , void * V_23 ,
struct V_11 * V_24 )
{
struct V_25 * V_26 = V_23 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
if ( ! F_2 ( V_2 , V_4 ) &&
! F_2 ( V_2 , V_5 ) )
return - V_31 ;
F_3 ( & V_2 -> V_6 ) ;
V_28 = F_17 ( & V_2 -> V_7 , V_26 -> V_32 ) ;
if ( ! V_28 ) {
F_5 ( & V_2 -> V_6 ) ;
return - V_31 ;
}
V_26 -> V_18 = NULL ;
F_18 (_entry, &dev->maplist, head) {
if ( V_30 -> V_28 == V_28 ) {
V_26 -> V_18 =
( void * ) ( unsigned long ) V_30 -> V_33 ;
break;
}
}
F_5 ( & V_2 -> V_6 ) ;
if ( V_26 -> V_18 == NULL )
return - V_31 ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , void * V_23 ,
struct V_11 * V_24 )
{
struct V_25 * V_26 = V_23 ;
struct V_27 * V_28 = NULL ;
struct V_29 * V_34 = NULL ;
if ( ! F_2 ( V_2 , V_4 ) &&
! F_2 ( V_2 , V_5 ) )
return - V_31 ;
F_3 ( & V_2 -> V_6 ) ;
F_18 (r_list, &dev->maplist, head) {
if ( V_34 -> V_28
&& V_34 -> V_33 == ( unsigned long ) V_26 -> V_18 )
goto V_35;
}
V_36:
F_5 ( & V_2 -> V_6 ) ;
return - V_31 ;
V_35:
V_28 = V_34 -> V_28 ;
if ( ! V_28 )
goto V_36;
if ( F_20 ( F_21 ( & V_2 -> V_7 , V_28 , V_26 -> V_32 ) ) )
goto V_36;
F_5 ( & V_2 -> V_6 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_37 , int V_38 )
{
if ( F_23 ( 0 , & V_2 -> V_39 ) ) {
F_24 ( L_1 ) ;
return - V_40 ;
}
F_25 ( L_2 , V_37 , V_38 ) ;
if ( V_38 == V_2 -> V_41 ) {
F_26 ( 0 , & V_2 -> V_39 ) ;
return 0 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_11 * V_24 , int V_38 )
{
V_2 -> V_41 = V_38 ;
if ( ! F_28 ( V_24 -> V_42 -> V_43 . V_44 -> V_43 ) ) {
F_24 ( L_3 ) ;
}
F_26 ( 0 , & V_2 -> V_39 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , void * V_23 ,
struct V_11 * V_24 )
{
struct V_45 * V_46 = V_23 ;
struct V_47 V_48 ;
int V_49 ;
if ( ! F_2 ( V_2 , V_4 ) &&
! F_2 ( V_2 , V_5 ) )
return - V_31 ;
if ( V_46 -> V_50 >= V_9 ) {
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
for ( V_49 = 0 ; V_49 < V_9 ; V_49 ++ ) {
V_48 . V_18 = V_49 ;
if ( F_30 ( & V_46 -> V_51 [ V_49 ] , & V_48 , sizeof( V_48 ) ) )
return - V_52 ;
}
}
V_46 -> V_50 = V_9 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , void * V_23 ,
struct V_11 * V_24 )
{
struct V_13 * V_53 ;
struct V_47 * V_48 = V_23 ;
if ( ! F_2 ( V_2 , V_4 ) &&
! F_2 ( V_2 , V_5 ) )
return - V_31 ;
V_48 -> V_18 = F_6 ( V_2 ) ;
if ( V_48 -> V_18 == V_19 ) {
V_48 -> V_18 = F_6 ( V_2 ) ;
}
F_25 ( L_4 , V_48 -> V_18 ) ;
if ( V_48 -> V_18 == - 1 ) {
F_25 ( L_5 ) ;
return - V_54 ;
}
V_53 = F_32 ( sizeof( * V_53 ) , V_10 ) ;
if ( ! V_53 ) {
F_25 ( L_6 ) ;
return - V_54 ;
}
F_33 ( & V_53 -> V_22 ) ;
V_53 -> V_18 = V_48 -> V_18 ;
V_53 -> V_17 = V_24 ;
F_3 ( & V_2 -> V_16 ) ;
F_34 ( & V_53 -> V_22 , & V_2 -> V_55 ) ;
F_5 ( & V_2 -> V_16 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 , void * V_23 ,
struct V_11 * V_24 )
{
struct V_47 * V_48 = V_23 ;
if ( ! F_2 ( V_2 , V_4 ) &&
! F_2 ( V_2 , V_5 ) )
return - V_31 ;
V_48 -> V_56 = 0 ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , void * V_23 ,
struct V_11 * V_24 )
{
struct V_47 * V_48 = V_23 ;
if ( ! F_2 ( V_2 , V_4 ) &&
! F_2 ( V_2 , V_5 ) )
return - V_31 ;
F_25 ( L_4 , V_48 -> V_18 ) ;
return F_22 ( V_2 , V_2 -> V_41 , V_48 -> V_18 ) ;
}
int F_37 ( struct V_1 * V_2 , void * V_23 ,
struct V_11 * V_24 )
{
struct V_47 * V_48 = V_23 ;
if ( ! F_2 ( V_2 , V_4 ) &&
! F_2 ( V_2 , V_5 ) )
return - V_31 ;
F_25 ( L_4 , V_48 -> V_18 ) ;
F_27 ( V_2 , V_24 , V_48 -> V_18 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 , void * V_23 ,
struct V_11 * V_24 )
{
struct V_47 * V_48 = V_23 ;
if ( ! F_2 ( V_2 , V_4 ) &&
! F_2 ( V_2 , V_5 ) )
return - V_31 ;
F_25 ( L_4 , V_48 -> V_18 ) ;
if ( V_48 -> V_18 != V_19 ) {
if ( V_2 -> V_20 -> V_21 )
V_2 -> V_20 -> V_21 ( V_2 , V_48 -> V_18 ) ;
F_1 ( V_2 , V_48 -> V_18 ) ;
}
F_3 ( & V_2 -> V_16 ) ;
if ( ! F_39 ( & V_2 -> V_55 ) ) {
struct V_13 * V_14 , * V_57 ;
F_13 (pos, n, &dev->ctxlist, head) {
if ( V_14 -> V_18 == V_48 -> V_18 ) {
F_14 ( & V_14 -> V_22 ) ;
F_15 ( V_14 ) ;
}
}
}
F_5 ( & V_2 -> V_16 ) ;
return 0 ;
}
