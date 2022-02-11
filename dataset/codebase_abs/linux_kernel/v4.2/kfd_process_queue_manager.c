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
V_23 = F_20 ( V_6 , * V_28 ) ;
if ( V_23 != 0 )
goto V_34;
( * V_6 ) -> V_35 = V_26 ;
( * V_6 ) -> V_15 = V_3 -> V_15 ;
F_5 ( L_6 ) ;
return V_23 ;
V_34:
return V_23 ;
}
int F_21 ( struct V_2 * V_3 ,
struct V_25 * V_26 ,
struct V_29 * V_30 ,
struct V_27 * V_7 ,
unsigned int V_36 ,
enum V_37 type ,
unsigned int * V_4 )
{
int V_23 ;
struct V_38 * V_39 ;
struct V_27 V_28 ;
struct V_10 * V_6 ;
struct V_1 * V_5 ;
struct V_40 * V_9 ;
int V_41 = 0 ;
struct V_10 * V_42 ;
F_2 ( ! V_3 || ! V_26 || ! V_7 || ! V_4 ) ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
memcpy ( & V_28 , V_7 , sizeof( struct V_27 ) ) ;
V_6 = NULL ;
V_9 = NULL ;
V_39 = F_22 ( V_26 , V_3 -> V_15 ) ;
if ( ! V_39 ) {
F_16 ( L_7 ) ;
return - 1 ;
}
if ( ( V_39 -> V_43 . V_44 ) ||
( type == V_45 ) ) {
F_3 (cur, &pdd->qpd.queues_list, list)
V_41 ++ ;
if ( V_41 >= V_26 -> V_46 -> V_47 / 2 )
return ( - V_48 ) ;
}
V_23 = F_4 ( V_3 , V_4 ) ;
if ( V_23 != 0 )
return V_23 ;
if ( F_23 ( & V_3 -> V_20 ) ) {
V_39 -> V_43 . V_3 = V_3 ;
V_26 -> V_49 -> V_50 . V_51 ( V_26 -> V_49 , & V_39 -> V_43 ) ;
}
V_5 = F_11 ( sizeof( struct V_1 ) , V_22 ) ;
if ( ! V_5 ) {
V_23 = - V_17 ;
goto V_52;
}
switch ( type ) {
case V_53 :
case V_54 :
if ( ( V_55 == V_56 ) &&
( ( V_26 -> V_49 -> V_57 >= V_58 ) ||
( V_26 -> V_49 -> V_59 >= V_60 * V_61 ) ) ) {
F_16 ( L_8 ) ;
V_23 = - V_62 ;
goto V_63;
}
V_23 = F_18 ( V_3 , V_26 , & V_6 , & V_28 , V_30 , * V_4 ) ;
if ( V_23 != 0 )
goto V_63;
V_5 -> V_6 = V_6 ;
V_5 -> V_9 = NULL ;
V_23 = V_26 -> V_49 -> V_50 . V_64 ( V_26 -> V_49 , V_6 , & V_39 -> V_43 ,
& V_6 -> V_7 . V_33 ) ;
F_5 ( L_9 , V_23 ) ;
F_24 ( V_6 ) ;
break;
case V_45 :
V_9 = F_25 ( V_26 , V_45 ) ;
if ( V_9 == NULL ) {
V_23 = - V_17 ;
goto V_63;
}
V_9 -> V_10 -> V_7 . V_8 = * V_4 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_6 = NULL ;
V_23 = V_26 -> V_49 -> V_50 . V_65 ( V_26 -> V_49 ,
V_9 , & V_39 -> V_43 ) ;
break;
default:
F_26 () ;
break;
}
if ( V_23 != 0 ) {
F_5 ( L_10 ) ;
goto V_63;
}
F_5 ( L_11 ) ;
F_27 ( & V_5 -> V_66 , & V_3 -> V_20 ) ;
if ( V_6 ) {
* V_7 = V_6 -> V_7 ;
F_5 ( L_12 ) ;
F_28 ( V_7 ) ;
}
return V_23 ;
V_63:
F_17 ( V_5 ) ;
V_52:
F_29 ( * V_4 , V_3 -> V_13 ) ;
if ( F_23 ( & V_3 -> V_20 ) )
V_26 -> V_49 -> V_50 . V_67 ( V_26 -> V_49 , & V_39 -> V_43 ) ;
return V_23 ;
}
int F_15 ( struct V_2 * V_3 , unsigned int V_4 )
{
struct V_1 * V_5 ;
struct V_38 * V_39 ;
struct V_68 * V_49 ;
struct V_25 * V_26 ;
int V_23 ;
V_49 = NULL ;
F_2 ( ! V_3 ) ;
V_23 = 0 ;
F_5 ( L_13 , V_12 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 == NULL ) {
F_16 ( L_14 ) ;
return - V_69 ;
}
V_26 = NULL ;
if ( V_5 -> V_9 )
V_26 = V_5 -> V_9 -> V_26 ;
if ( V_5 -> V_6 )
V_26 = V_5 -> V_6 -> V_35 ;
F_2 ( ! V_26 ) ;
V_39 = F_22 ( V_26 , V_3 -> V_15 ) ;
if ( ! V_39 ) {
F_16 ( L_7 ) ;
return - 1 ;
}
if ( V_5 -> V_9 ) {
V_49 = V_5 -> V_9 -> V_26 -> V_49 ;
V_49 -> V_50 . V_70 ( V_49 , V_5 -> V_9 , & V_39 -> V_43 ) ;
F_30 ( V_5 -> V_9 ) ;
}
if ( V_5 -> V_6 ) {
V_49 = V_5 -> V_6 -> V_35 -> V_49 ;
V_23 = V_49 -> V_50 . V_71 ( V_49 , & V_39 -> V_43 , V_5 -> V_6 ) ;
if ( V_23 != 0 )
return V_23 ;
F_31 ( V_5 -> V_6 ) ;
}
F_32 ( & V_5 -> V_66 ) ;
F_17 ( V_5 ) ;
F_29 ( V_4 , V_3 -> V_13 ) ;
if ( F_23 ( & V_3 -> V_20 ) )
V_49 -> V_50 . V_67 ( V_49 , & V_39 -> V_43 ) ;
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
F_5 ( L_15 ,
V_4 ) ;
return - V_72 ;
}
V_5 -> V_6 -> V_7 . V_73 = V_19 -> V_73 ;
V_5 -> V_6 -> V_7 . V_74 = V_19 -> V_74 ;
V_5 -> V_6 -> V_7 . V_75 = V_19 -> V_75 ;
V_5 -> V_6 -> V_7 . V_76 = V_19 -> V_76 ;
V_23 = V_5 -> V_6 -> V_35 -> V_49 -> V_50 . V_77 ( V_5 -> V_6 -> V_35 -> V_49 ,
V_5 -> V_6 ) ;
if ( V_23 != 0 )
return V_23 ;
return 0 ;
}
struct V_40 * F_34 (
struct V_2 * V_3 ,
unsigned int V_4 )
{
struct V_1 * V_5 ;
F_2 ( ! V_3 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 && V_5 -> V_9 )
return V_5 -> V_9 ;
return NULL ;
}
