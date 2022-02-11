void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 , V_3 ) ;
F_4 ( & V_2 -> V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_6 ;
int V_7 ;
V_8:
if ( F_6 ( & V_2 -> V_5 , V_9 ) == 0 ) {
F_7 ( L_1 ) ;
return - V_10 ;
}
F_2 ( & V_2 -> V_4 ) ;
V_7 = F_8 ( & V_2 -> V_5 , NULL ,
V_11 , & V_6 ) ;
if ( V_7 == - V_12 ) {
F_4 ( & V_2 -> V_4 ) ;
goto V_8;
}
F_4 ( & V_2 -> V_4 ) ;
return V_6 ;
}
int F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_5 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_4 ) ;
F_12 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_4 ) ;
}
int F_13 ( struct V_1 * V_2 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_13 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
F_2 ( & V_2 -> V_4 ) ;
V_19 = F_14 ( & V_2 -> V_5 , V_17 -> V_22 ) ;
if ( ! V_19 ) {
F_4 ( & V_2 -> V_4 ) ;
return - V_23 ;
}
F_4 ( & V_2 -> V_4 ) ;
V_17 -> V_24 = NULL ;
F_15 (_entry, &dev->maplist, head) {
if ( V_21 -> V_19 == V_19 ) {
V_17 -> V_24 =
( void * ) ( unsigned long ) V_21 -> V_25 ;
break;
}
}
if ( V_17 -> V_24 == NULL )
return - V_23 ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_13 ;
struct V_18 * V_19 = NULL ;
struct V_20 * V_26 = NULL ;
F_2 ( & V_2 -> V_4 ) ;
F_15 (r_list, &dev->maplist, head) {
if ( V_26 -> V_19
&& V_26 -> V_25 == ( unsigned long ) V_17 -> V_24 )
goto V_27;
}
V_28:
F_4 ( & V_2 -> V_4 ) ;
return - V_23 ;
V_27:
V_19 = V_26 -> V_19 ;
if ( ! V_19 )
goto V_28;
if ( F_17 ( F_18 ( & V_2 -> V_5 , V_19 , V_17 -> V_22 ) ) )
goto V_28;
F_4 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_29 , int V_30 )
{
if ( F_20 ( 0 , & V_2 -> V_31 ) ) {
F_7 ( L_2 ) ;
return - V_32 ;
}
F_21 ( L_3 , V_29 , V_30 ) ;
if ( V_30 == V_2 -> V_33 ) {
F_22 ( 0 , & V_2 -> V_31 ) ;
return 0 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_14 * V_15 , int V_30 )
{
V_2 -> V_33 = V_30 ;
V_2 -> V_34 = V_35 ;
if ( ! F_24 ( V_15 -> V_36 -> V_37 . V_38 -> V_37 ) ) {
F_7 ( L_4 ) ;
}
F_22 ( 0 , & V_2 -> V_31 ) ;
F_25 ( & V_2 -> V_39 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_40 * V_41 = V_13 ;
struct V_42 V_43 ;
int V_44 ;
if ( V_41 -> V_45 >= V_11 ) {
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
for ( V_44 = 0 ; V_44 < V_11 ; V_44 ++ ) {
V_43 . V_24 = V_44 ;
if ( F_27 ( & V_41 -> V_46 [ V_44 ] , & V_43 , sizeof( V_43 ) ) )
return - V_47 ;
}
}
V_41 -> V_45 = V_11 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_48 * V_49 ;
struct V_42 * V_43 = V_13 ;
V_43 -> V_24 = F_5 ( V_2 ) ;
if ( V_43 -> V_24 == V_50 ) {
V_43 -> V_24 = F_5 ( V_2 ) ;
}
F_21 ( L_5 , V_43 -> V_24 ) ;
if ( V_43 -> V_24 == - 1 ) {
F_21 ( L_6 ) ;
return - V_10 ;
}
V_49 = F_29 ( sizeof( * V_49 ) , V_9 ) ;
if ( ! V_49 ) {
F_21 ( L_7 ) ;
return - V_10 ;
}
F_30 ( & V_49 -> V_51 ) ;
V_49 -> V_24 = V_43 -> V_24 ;
V_49 -> V_52 = V_15 ;
F_2 ( & V_2 -> V_53 ) ;
F_31 ( & V_49 -> V_51 , & V_2 -> V_54 ) ;
++ V_2 -> V_55 ;
F_4 ( & V_2 -> V_53 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , void * V_13 , struct V_14 * V_15 )
{
return 0 ;
}
int F_33 ( struct V_1 * V_2 , void * V_13 , struct V_14 * V_15 )
{
struct V_42 * V_43 = V_13 ;
V_43 -> V_56 = 0 ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_42 * V_43 = V_13 ;
F_21 ( L_5 , V_43 -> V_24 ) ;
return F_19 ( V_2 , V_2 -> V_33 , V_43 -> V_24 ) ;
}
int F_35 ( struct V_1 * V_2 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_42 * V_43 = V_13 ;
F_21 ( L_5 , V_43 -> V_24 ) ;
F_23 ( V_2 , V_15 , V_43 -> V_24 ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_42 * V_43 = V_13 ;
F_21 ( L_5 , V_43 -> V_24 ) ;
if ( V_43 -> V_24 != V_50 ) {
if ( V_2 -> V_57 -> V_58 )
V_2 -> V_57 -> V_58 ( V_2 , V_43 -> V_24 ) ;
F_1 ( V_2 , V_43 -> V_24 ) ;
}
F_2 ( & V_2 -> V_53 ) ;
if ( ! F_37 ( & V_2 -> V_54 ) ) {
struct V_48 * V_59 , * V_60 ;
F_38 (pos, n, &dev->ctxlist, head) {
if ( V_59 -> V_24 == V_43 -> V_24 ) {
F_39 ( & V_59 -> V_51 ) ;
F_40 ( V_59 ) ;
-- V_2 -> V_55 ;
}
}
}
F_4 ( & V_2 -> V_53 ) ;
return 0 ;
}
