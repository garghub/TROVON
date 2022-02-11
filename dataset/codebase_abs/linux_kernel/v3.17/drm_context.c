void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 , V_3 ) ;
F_4 ( & V_2 -> V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_6 ;
F_2 ( & V_2 -> V_4 ) ;
V_6 = F_6 ( & V_2 -> V_5 , NULL , V_7 , 0 ,
V_8 ) ;
F_4 ( & V_2 -> V_4 ) ;
return V_6 ;
}
int F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_5 ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_4 ) ;
F_10 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_4 ) ;
}
void F_11 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_12 , * V_13 ;
F_2 ( & V_2 -> V_14 ) ;
F_12 (pos, tmp, &dev->ctxlist, head) {
if ( V_12 -> V_15 == V_10 &&
V_12 -> V_16 != V_17 ) {
if ( V_2 -> V_18 -> V_19 )
V_2 -> V_18 -> V_19 ( V_2 , V_12 -> V_16 ) ;
F_1 ( V_2 , V_12 -> V_16 ) ;
F_13 ( & V_12 -> V_20 ) ;
F_14 ( V_12 ) ;
}
}
F_4 ( & V_2 -> V_14 ) ;
}
int F_15 ( struct V_1 * V_2 , void * V_21 ,
struct V_9 * V_22 )
{
struct V_23 * V_24 = V_21 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
F_2 ( & V_2 -> V_4 ) ;
V_26 = F_16 ( & V_2 -> V_5 , V_24 -> V_29 ) ;
if ( ! V_26 ) {
F_4 ( & V_2 -> V_4 ) ;
return - V_30 ;
}
V_24 -> V_16 = NULL ;
F_17 (_entry, &dev->maplist, head) {
if ( V_28 -> V_26 == V_26 ) {
V_24 -> V_16 =
( void * ) ( unsigned long ) V_28 -> V_31 ;
break;
}
}
F_4 ( & V_2 -> V_4 ) ;
if ( V_24 -> V_16 == NULL )
return - V_30 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , void * V_21 ,
struct V_9 * V_22 )
{
struct V_23 * V_24 = V_21 ;
struct V_25 * V_26 = NULL ;
struct V_27 * V_32 = NULL ;
F_2 ( & V_2 -> V_4 ) ;
F_17 (r_list, &dev->maplist, head) {
if ( V_32 -> V_26
&& V_32 -> V_31 == ( unsigned long ) V_24 -> V_16 )
goto V_33;
}
V_34:
F_4 ( & V_2 -> V_4 ) ;
return - V_30 ;
V_33:
V_26 = V_32 -> V_26 ;
if ( ! V_26 )
goto V_34;
if ( F_19 ( F_20 ( & V_2 -> V_5 , V_26 , V_24 -> V_29 ) ) )
goto V_34;
F_4 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_35 , int V_36 )
{
if ( F_22 ( 0 , & V_2 -> V_37 ) ) {
F_23 ( L_1 ) ;
return - V_38 ;
}
F_24 ( L_2 , V_35 , V_36 ) ;
if ( V_36 == V_2 -> V_39 ) {
F_25 ( 0 , & V_2 -> V_37 ) ;
return 0 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_9 * V_22 , int V_36 )
{
V_2 -> V_39 = V_36 ;
if ( ! F_27 ( V_22 -> V_40 -> V_41 . V_42 -> V_41 ) ) {
F_23 ( L_3 ) ;
}
F_25 ( 0 , & V_2 -> V_37 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , void * V_21 ,
struct V_9 * V_22 )
{
struct V_43 * V_44 = V_21 ;
struct V_45 V_46 ;
int V_47 ;
if ( V_44 -> V_48 >= V_7 ) {
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
for ( V_47 = 0 ; V_47 < V_7 ; V_47 ++ ) {
V_46 . V_16 = V_47 ;
if ( F_29 ( & V_44 -> V_49 [ V_47 ] , & V_46 , sizeof( V_46 ) ) )
return - V_50 ;
}
}
V_44 -> V_48 = V_7 ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , void * V_21 ,
struct V_9 * V_22 )
{
struct V_11 * V_51 ;
struct V_45 * V_46 = V_21 ;
V_46 -> V_16 = F_5 ( V_2 ) ;
if ( V_46 -> V_16 == V_17 ) {
V_46 -> V_16 = F_5 ( V_2 ) ;
}
F_24 ( L_4 , V_46 -> V_16 ) ;
if ( V_46 -> V_16 == - 1 ) {
F_24 ( L_5 ) ;
return - V_52 ;
}
V_51 = F_31 ( sizeof( * V_51 ) , V_8 ) ;
if ( ! V_51 ) {
F_24 ( L_6 ) ;
return - V_52 ;
}
F_32 ( & V_51 -> V_20 ) ;
V_51 -> V_16 = V_46 -> V_16 ;
V_51 -> V_15 = V_22 ;
F_2 ( & V_2 -> V_14 ) ;
F_33 ( & V_51 -> V_20 , & V_2 -> V_53 ) ;
F_4 ( & V_2 -> V_14 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 , void * V_21 ,
struct V_9 * V_22 )
{
struct V_45 * V_46 = V_21 ;
V_46 -> V_54 = 0 ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 , void * V_21 ,
struct V_9 * V_22 )
{
struct V_45 * V_46 = V_21 ;
F_24 ( L_4 , V_46 -> V_16 ) ;
return F_21 ( V_2 , V_2 -> V_39 , V_46 -> V_16 ) ;
}
int F_36 ( struct V_1 * V_2 , void * V_21 ,
struct V_9 * V_22 )
{
struct V_45 * V_46 = V_21 ;
F_24 ( L_4 , V_46 -> V_16 ) ;
F_26 ( V_2 , V_22 , V_46 -> V_16 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 , void * V_21 ,
struct V_9 * V_22 )
{
struct V_45 * V_46 = V_21 ;
F_24 ( L_4 , V_46 -> V_16 ) ;
if ( V_46 -> V_16 != V_17 ) {
if ( V_2 -> V_18 -> V_19 )
V_2 -> V_18 -> V_19 ( V_2 , V_46 -> V_16 ) ;
F_1 ( V_2 , V_46 -> V_16 ) ;
}
F_2 ( & V_2 -> V_14 ) ;
if ( ! F_38 ( & V_2 -> V_53 ) ) {
struct V_11 * V_12 , * V_55 ;
F_12 (pos, n, &dev->ctxlist, head) {
if ( V_12 -> V_16 == V_46 -> V_16 ) {
F_13 ( & V_12 -> V_20 ) ;
F_14 ( V_12 ) ;
}
}
}
F_4 ( & V_2 -> V_14 ) ;
return 0 ;
}
