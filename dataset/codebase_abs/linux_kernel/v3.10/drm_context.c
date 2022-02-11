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
int F_11 ( struct V_1 * V_2 , void * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_2 ( & V_2 -> V_4 ) ;
V_15 = F_12 ( & V_2 -> V_5 , V_13 -> V_18 ) ;
if ( ! V_15 ) {
F_4 ( & V_2 -> V_4 ) ;
return - V_19 ;
}
V_13 -> V_20 = NULL ;
F_13 (_entry, &dev->maplist, head) {
if ( V_17 -> V_15 == V_15 ) {
V_13 -> V_20 =
( void * ) ( unsigned long ) V_17 -> V_21 ;
break;
}
}
F_4 ( & V_2 -> V_4 ) ;
if ( V_13 -> V_20 == NULL )
return - V_19 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , void * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_9 ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_22 = NULL ;
F_2 ( & V_2 -> V_4 ) ;
F_13 (r_list, &dev->maplist, head) {
if ( V_22 -> V_15
&& V_22 -> V_21 == ( unsigned long ) V_13 -> V_20 )
goto V_23;
}
V_24:
F_4 ( & V_2 -> V_4 ) ;
return - V_19 ;
V_23:
V_15 = V_22 -> V_15 ;
if ( ! V_15 )
goto V_24;
if ( F_15 ( F_16 ( & V_2 -> V_5 , V_15 , V_13 -> V_18 ) ) )
goto V_24;
F_4 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_25 , int V_26 )
{
if ( F_18 ( 0 , & V_2 -> V_27 ) ) {
F_19 ( L_1 ) ;
return - V_28 ;
}
F_20 ( L_2 , V_25 , V_26 ) ;
if ( V_26 == V_2 -> V_29 ) {
F_21 ( 0 , & V_2 -> V_27 ) ;
return 0 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_10 * V_11 , int V_26 )
{
V_2 -> V_29 = V_26 ;
V_2 -> V_30 = V_31 ;
if ( ! F_23 ( V_11 -> V_32 -> V_33 . V_34 -> V_33 ) ) {
F_19 ( L_3 ) ;
}
F_21 ( 0 , & V_2 -> V_27 ) ;
F_24 ( & V_2 -> V_35 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , void * V_9 ,
struct V_10 * V_11 )
{
struct V_36 * V_37 = V_9 ;
struct V_38 V_39 ;
int V_40 ;
if ( V_37 -> V_41 >= V_7 ) {
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
for ( V_40 = 0 ; V_40 < V_7 ; V_40 ++ ) {
V_39 . V_20 = V_40 ;
if ( F_26 ( & V_37 -> V_42 [ V_40 ] , & V_39 , sizeof( V_39 ) ) )
return - V_43 ;
}
}
V_37 -> V_41 = V_7 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , void * V_9 ,
struct V_10 * V_11 )
{
struct V_44 * V_45 ;
struct V_38 * V_39 = V_9 ;
V_39 -> V_20 = F_5 ( V_2 ) ;
if ( V_39 -> V_20 == V_46 ) {
V_39 -> V_20 = F_5 ( V_2 ) ;
}
F_20 ( L_4 , V_39 -> V_20 ) ;
if ( V_39 -> V_20 == - 1 ) {
F_20 ( L_5 ) ;
return - V_47 ;
}
V_45 = F_28 ( sizeof( * V_45 ) , V_8 ) ;
if ( ! V_45 ) {
F_20 ( L_6 ) ;
return - V_47 ;
}
F_29 ( & V_45 -> V_48 ) ;
V_45 -> V_20 = V_39 -> V_20 ;
V_45 -> V_49 = V_11 ;
F_2 ( & V_2 -> V_50 ) ;
F_30 ( & V_45 -> V_48 , & V_2 -> V_51 ) ;
++ V_2 -> V_52 ;
F_4 ( & V_2 -> V_50 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , void * V_9 , struct V_10 * V_11 )
{
return 0 ;
}
int F_32 ( struct V_1 * V_2 , void * V_9 , struct V_10 * V_11 )
{
struct V_38 * V_39 = V_9 ;
V_39 -> V_53 = 0 ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , void * V_9 ,
struct V_10 * V_11 )
{
struct V_38 * V_39 = V_9 ;
F_20 ( L_4 , V_39 -> V_20 ) ;
return F_17 ( V_2 , V_2 -> V_29 , V_39 -> V_20 ) ;
}
int F_34 ( struct V_1 * V_2 , void * V_9 ,
struct V_10 * V_11 )
{
struct V_38 * V_39 = V_9 ;
F_20 ( L_4 , V_39 -> V_20 ) ;
F_22 ( V_2 , V_11 , V_39 -> V_20 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 , void * V_9 ,
struct V_10 * V_11 )
{
struct V_38 * V_39 = V_9 ;
F_20 ( L_4 , V_39 -> V_20 ) ;
if ( V_39 -> V_20 != V_46 ) {
if ( V_2 -> V_54 -> V_55 )
V_2 -> V_54 -> V_55 ( V_2 , V_39 -> V_20 ) ;
F_1 ( V_2 , V_39 -> V_20 ) ;
}
F_2 ( & V_2 -> V_50 ) ;
if ( ! F_36 ( & V_2 -> V_51 ) ) {
struct V_44 * V_56 , * V_57 ;
F_37 (pos, n, &dev->ctxlist, head) {
if ( V_56 -> V_20 == V_39 -> V_20 ) {
F_38 ( & V_56 -> V_48 ) ;
F_39 ( V_56 ) ;
-- V_2 -> V_52 ;
}
}
}
F_4 ( & V_2 -> V_50 ) ;
return 0 ;
}
