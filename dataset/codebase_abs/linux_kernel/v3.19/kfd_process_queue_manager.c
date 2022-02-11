static inline struct V_1 * F_1 (
struct V_2 * V_3 , unsigned int V_4 )
{
struct V_1 * V_5 ;
F_2 ( ! V_3 ) ;
F_3 (pqn, &pqm->queues, process_queue_list) {
if ( V_5 -> V_6 && V_5 -> V_6 -> V_7 . V_8 == V_4 )
return V_5 ;
if ( V_5 -> V_9 && V_5 -> V_9 -> V_10 -> V_7 . V_8 == V_4 )
return V_5 ;
}
return NULL ;
}
static int F_4 ( struct V_2 * V_3 ,
unsigned int * V_4 )
{
unsigned long V_11 ;
F_2 ( ! V_3 || ! V_4 ) ;
F_5 ( L_1 , V_12 ) ;
V_11 = F_6 ( V_3 -> V_13 ,
V_14 ) ;
F_5 ( L_2 , V_11 ) ;
if ( V_11 >= V_14 ) {
F_7 ( L_3 ,
V_3 -> V_15 -> V_16 ) ;
return - V_17 ;
}
F_8 ( V_11 , V_3 -> V_13 ) ;
* V_4 = V_11 ;
return 0 ;
}
int F_9 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
F_2 ( ! V_3 ) ;
F_10 ( & V_3 -> V_20 ) ;
V_3 -> V_13 =
F_11 ( F_12 ( V_14 ,
V_21 ) , V_22 ) ;
if ( V_3 -> V_13 == NULL )
return - V_17 ;
V_3 -> V_15 = V_19 ;
return 0 ;
}
void F_13 ( struct V_2 * V_3 )
{
int V_23 ;
struct V_1 * V_5 , * V_24 ;
F_2 ( ! V_3 ) ;
F_5 ( L_4 , V_12 ) ;
F_14 (pqn, next, &pqm->queues, process_queue_list) {
V_23 = F_15 (
V_3 ,
( V_5 -> V_6 != NULL ) ?
V_5 -> V_6 -> V_7 . V_8 :
V_5 -> V_9 -> V_10 -> V_7 . V_8 ) ;
if ( V_23 != 0 ) {
F_16 ( L_5 ) ;
return;
}
}
F_17 ( V_3 -> V_13 ) ;
V_3 -> V_13 = NULL ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_25 * V_26 , struct V_10 * * V_6 ,
struct V_27 * V_28 ,
struct V_29 * V_30 , unsigned int V_4 )
{
int V_23 ;
V_23 = 0 ;
V_28 -> V_31 = NULL ;
V_28 -> V_32 =
F_19 ( V_26 , V_3 -> V_15 , V_4 ) ;
V_28 -> V_33 = 0 ;
V_28 -> V_8 = V_4 ;
V_28 -> type = V_34 ;
V_23 = F_20 ( V_6 , * V_28 ) ;
if ( V_23 != 0 )
goto V_35;
( * V_6 ) -> V_36 = V_26 ;
( * V_6 ) -> V_15 = V_3 -> V_15 ;
F_5 ( L_6 ) ;
return V_23 ;
V_35:
return V_23 ;
}
int F_21 ( struct V_2 * V_3 ,
struct V_25 * V_26 ,
struct V_29 * V_30 ,
struct V_27 * V_7 ,
unsigned int V_37 ,
enum V_38 type ,
unsigned int * V_4 )
{
int V_23 ;
struct V_39 * V_40 ;
struct V_27 V_28 ;
struct V_10 * V_6 ;
struct V_1 * V_5 ;
struct V_41 * V_9 ;
F_2 ( ! V_3 || ! V_26 || ! V_7 || ! V_4 ) ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
memcpy ( & V_28 , V_7 , sizeof( struct V_27 ) ) ;
V_6 = NULL ;
V_9 = NULL ;
V_40 = F_22 ( V_26 , V_3 -> V_15 , 1 ) ;
F_2 ( ! V_40 ) ;
V_23 = F_4 ( V_3 , V_4 ) ;
if ( V_23 != 0 )
return V_23 ;
if ( F_23 ( & V_3 -> V_20 ) ) {
V_40 -> V_42 . V_3 = V_3 ;
V_26 -> V_43 -> V_44 ( V_26 -> V_43 , & V_40 -> V_42 ) ;
}
V_5 = F_11 ( sizeof( struct V_1 ) , V_22 ) ;
if ( ! V_5 ) {
V_23 = - V_17 ;
goto V_45;
}
switch ( type ) {
case V_34 :
if ( ( V_46 == V_47 ) &&
( ( V_26 -> V_43 -> V_48 >= V_49 ) ||
( V_26 -> V_43 -> V_50 >= V_51 * V_52 ) ) ) {
F_16 ( L_7 ) ;
V_23 = - V_53 ;
goto V_54;
}
V_23 = F_18 ( V_3 , V_26 , & V_6 , & V_28 , V_30 , * V_4 ) ;
if ( V_23 != 0 )
goto V_54;
V_5 -> V_6 = V_6 ;
V_5 -> V_9 = NULL ;
V_23 = V_26 -> V_43 -> V_55 ( V_26 -> V_43 , V_6 , & V_40 -> V_42 ,
& V_6 -> V_7 . V_33 ) ;
F_5 ( L_8 , V_23 ) ;
F_24 ( V_6 ) ;
break;
case V_56 :
V_9 = F_25 ( V_26 , V_56 ) ;
if ( V_9 == NULL ) {
V_23 = - V_17 ;
goto V_54;
}
V_9 -> V_10 -> V_7 . V_8 = * V_4 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_6 = NULL ;
V_23 = V_26 -> V_43 -> V_57 ( V_26 -> V_43 , V_9 , & V_40 -> V_42 ) ;
break;
default:
F_26 () ;
break;
}
if ( V_23 != 0 ) {
F_5 ( L_9 ) ;
goto V_54;
}
F_5 ( L_10 ) ;
F_27 ( & V_5 -> V_58 , & V_3 -> V_20 ) ;
if ( V_6 ) {
* V_7 = V_6 -> V_7 ;
F_5 ( L_11 ) ;
F_28 ( V_7 ) ;
}
return V_23 ;
V_54:
F_17 ( V_5 ) ;
V_45:
F_29 ( * V_4 , V_3 -> V_13 ) ;
if ( F_23 ( & V_3 -> V_20 ) )
V_26 -> V_43 -> V_59 ( V_26 -> V_43 , & V_40 -> V_42 ) ;
return V_23 ;
}
int F_15 ( struct V_2 * V_3 , unsigned int V_4 )
{
struct V_1 * V_5 ;
struct V_39 * V_40 ;
struct V_60 * V_43 ;
struct V_25 * V_26 ;
int V_23 ;
V_43 = NULL ;
F_2 ( ! V_3 ) ;
V_23 = 0 ;
F_5 ( L_12 , V_12 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 == NULL ) {
F_16 ( L_13 ) ;
return - V_61 ;
}
V_26 = NULL ;
if ( V_5 -> V_9 )
V_26 = V_5 -> V_9 -> V_26 ;
if ( V_5 -> V_6 )
V_26 = V_5 -> V_6 -> V_36 ;
F_2 ( ! V_26 ) ;
V_40 = F_22 ( V_26 , V_3 -> V_15 , 1 ) ;
F_2 ( ! V_40 ) ;
if ( V_5 -> V_9 ) {
V_43 = V_5 -> V_9 -> V_26 -> V_43 ;
V_43 -> V_62 ( V_43 , V_5 -> V_9 , & V_40 -> V_42 ) ;
F_30 ( V_5 -> V_9 ) ;
}
if ( V_5 -> V_6 ) {
V_43 = V_5 -> V_6 -> V_36 -> V_43 ;
V_23 = V_43 -> V_63 ( V_43 , & V_40 -> V_42 , V_5 -> V_6 ) ;
if ( V_23 != 0 )
return V_23 ;
F_31 ( V_5 -> V_6 ) ;
}
F_32 ( & V_5 -> V_58 ) ;
F_17 ( V_5 ) ;
F_29 ( V_4 , V_3 -> V_13 ) ;
if ( F_23 ( & V_3 -> V_20 ) )
V_43 -> V_59 ( V_43 , & V_40 -> V_42 ) ;
return V_23 ;
}
int F_33 ( struct V_2 * V_3 , unsigned int V_4 ,
struct V_27 * V_19 )
{
int V_23 ;
struct V_1 * V_5 ;
F_2 ( ! V_3 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_5 ( L_14 ,
V_4 ) ;
return - V_64 ;
}
V_5 -> V_6 -> V_7 . V_65 = V_19 -> V_65 ;
V_5 -> V_6 -> V_7 . V_66 = V_19 -> V_66 ;
V_5 -> V_6 -> V_7 . V_67 = V_19 -> V_67 ;
V_5 -> V_6 -> V_7 . V_68 = V_19 -> V_68 ;
V_23 = V_5 -> V_6 -> V_36 -> V_43 -> V_69 ( V_5 -> V_6 -> V_36 -> V_43 , V_5 -> V_6 ) ;
if ( V_23 != 0 )
return V_23 ;
return 0 ;
}
