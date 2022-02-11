static inline struct V_1 * F_1 (
struct V_2 * V_3 , unsigned int V_4 )
{
struct V_1 * V_5 ;
F_2 (pqn, &pqm->queues, process_queue_list) {
if ( ( V_5 -> V_6 && V_5 -> V_6 -> V_7 . V_8 == V_4 ) ||
( V_5 -> V_9 && V_5 -> V_9 -> V_10 -> V_7 . V_8 == V_4 ) )
return V_5 ;
}
return NULL ;
}
static int F_3 ( struct V_2 * V_3 ,
unsigned int * V_4 )
{
unsigned long V_11 ;
V_11 = F_4 ( V_3 -> V_12 ,
V_13 ) ;
F_5 ( L_1 , V_11 ) ;
if ( V_11 >= V_13 ) {
F_6 ( L_2 ,
V_3 -> V_14 -> V_15 ) ;
return - V_16 ;
}
F_7 ( V_11 , V_3 -> V_12 ) ;
* V_4 = V_11 ;
return 0 ;
}
int F_8 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
F_9 ( & V_3 -> V_19 ) ;
V_3 -> V_12 =
F_10 ( F_11 ( V_13 ,
V_20 ) , V_21 ) ;
if ( ! V_3 -> V_12 )
return - V_16 ;
V_3 -> V_14 = V_18 ;
return 0 ;
}
void F_12 ( struct V_2 * V_3 )
{
int V_22 ;
struct V_1 * V_5 , * V_23 ;
F_13 (pqn, next, &pqm->queues, process_queue_list) {
V_22 = F_14 (
V_3 ,
( V_5 -> V_6 != NULL ) ?
V_5 -> V_6 -> V_7 . V_8 :
V_5 -> V_9 -> V_10 -> V_7 . V_8 ) ;
if ( V_22 != 0 ) {
F_15 ( L_3 ) ;
return;
}
}
F_16 ( V_3 -> V_12 ) ;
V_3 -> V_12 = NULL ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_24 * V_25 , struct V_10 * * V_6 ,
struct V_26 * V_27 ,
struct V_28 * V_29 , unsigned int V_4 )
{
int V_22 ;
V_27 -> V_30 = NULL ;
V_27 -> V_31 =
F_18 ( V_25 , V_3 -> V_14 , V_4 ) ;
V_27 -> V_32 = 0 ;
V_27 -> V_8 = V_4 ;
V_22 = F_19 ( V_6 , V_27 ) ;
if ( V_22 != 0 )
return V_22 ;
( * V_6 ) -> V_33 = V_25 ;
( * V_6 ) -> V_14 = V_3 -> V_14 ;
F_5 ( L_4 ) ;
return V_22 ;
}
int F_20 ( struct V_2 * V_3 ,
struct V_24 * V_25 ,
struct V_28 * V_29 ,
struct V_26 * V_7 ,
unsigned int V_34 ,
enum V_35 type ,
unsigned int * V_4 )
{
int V_22 ;
struct V_36 * V_37 ;
struct V_26 V_27 ;
struct V_10 * V_6 ;
struct V_1 * V_5 ;
struct V_38 * V_9 ;
int V_39 = 0 ;
struct V_10 * V_40 ;
memcpy ( & V_27 , V_7 , sizeof( struct V_26 ) ) ;
V_6 = NULL ;
V_9 = NULL ;
V_37 = F_21 ( V_25 , V_3 -> V_14 ) ;
if ( ! V_37 ) {
F_15 ( L_5 ) ;
return - 1 ;
}
if ( ( V_37 -> V_41 . V_42 ) ||
( type == V_43 ) ) {
F_2 (cur, &pdd->qpd.queues_list, list)
V_39 ++ ;
if ( V_39 >= V_25 -> V_44 -> V_45 / 2 )
return - V_46 ;
}
V_22 = F_3 ( V_3 , V_4 ) ;
if ( V_22 != 0 )
return V_22 ;
if ( F_22 ( & V_3 -> V_19 ) ) {
V_37 -> V_41 . V_3 = V_3 ;
V_25 -> V_47 -> V_48 . V_49 ( V_25 -> V_47 , & V_37 -> V_41 ) ;
}
V_5 = F_10 ( sizeof( * V_5 ) , V_21 ) ;
if ( ! V_5 ) {
V_22 = - V_16 ;
goto V_50;
}
switch ( type ) {
case V_51 :
case V_52 :
if ( ( V_53 == V_54 ) &&
( ( V_25 -> V_47 -> V_55 >= V_56 ) ||
( V_25 -> V_47 -> V_57 >= F_23 ( V_25 -> V_47 ) ) ) ) {
F_15 ( L_6 ) ;
V_22 = - V_58 ;
goto V_59;
}
V_22 = F_17 ( V_3 , V_25 , & V_6 , & V_27 , V_29 , * V_4 ) ;
if ( V_22 != 0 )
goto V_59;
V_5 -> V_6 = V_6 ;
V_5 -> V_9 = NULL ;
V_22 = V_25 -> V_47 -> V_48 . V_60 ( V_25 -> V_47 , V_6 , & V_37 -> V_41 ,
& V_6 -> V_7 . V_32 ) ;
F_5 ( L_7 , V_22 ) ;
F_24 ( V_6 ) ;
break;
case V_43 :
V_9 = F_25 ( V_25 , V_43 ) ;
if ( ! V_9 ) {
V_22 = - V_16 ;
goto V_59;
}
V_9 -> V_10 -> V_7 . V_8 = * V_4 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_6 = NULL ;
V_22 = V_25 -> V_47 -> V_48 . V_61 ( V_25 -> V_47 ,
V_9 , & V_37 -> V_41 ) ;
break;
default:
F_26 ( 1 , L_8 , type ) ;
V_22 = - V_62 ;
}
if ( V_22 != 0 ) {
F_15 ( L_9 ) ;
goto V_59;
}
F_5 ( L_10 ) ;
F_27 ( & V_5 -> V_63 , & V_3 -> V_19 ) ;
if ( V_6 ) {
* V_7 = V_6 -> V_7 ;
F_5 ( L_11 ) ;
F_28 ( V_7 ) ;
}
return V_22 ;
V_59:
F_16 ( V_5 ) ;
V_50:
F_29 ( * V_4 , V_3 -> V_12 ) ;
if ( F_22 ( & V_3 -> V_19 ) )
V_25 -> V_47 -> V_48 . V_64 ( V_25 -> V_47 , & V_37 -> V_41 ) ;
return V_22 ;
}
int F_14 ( struct V_2 * V_3 , unsigned int V_4 )
{
struct V_1 * V_5 ;
struct V_36 * V_37 ;
struct V_65 * V_47 ;
struct V_24 * V_25 ;
int V_22 ;
V_47 = NULL ;
V_22 = 0 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_15 ( L_12 ) ;
return - V_62 ;
}
V_25 = NULL ;
if ( V_5 -> V_9 )
V_25 = V_5 -> V_9 -> V_25 ;
if ( V_5 -> V_6 )
V_25 = V_5 -> V_6 -> V_33 ;
if ( F_30 ( ! V_25 ) )
return - V_66 ;
V_37 = F_21 ( V_25 , V_3 -> V_14 ) ;
if ( ! V_37 ) {
F_15 ( L_5 ) ;
return - 1 ;
}
if ( V_5 -> V_9 ) {
V_47 = V_5 -> V_9 -> V_25 -> V_47 ;
V_47 -> V_48 . V_67 ( V_47 , V_5 -> V_9 , & V_37 -> V_41 ) ;
F_31 ( V_5 -> V_9 ) ;
}
if ( V_5 -> V_6 ) {
V_47 = V_5 -> V_6 -> V_33 -> V_47 ;
V_22 = V_47 -> V_48 . V_68 ( V_47 , & V_37 -> V_41 , V_5 -> V_6 ) ;
if ( V_22 != 0 )
return V_22 ;
F_32 ( V_5 -> V_6 ) ;
}
F_33 ( & V_5 -> V_63 ) ;
F_16 ( V_5 ) ;
F_29 ( V_4 , V_3 -> V_12 ) ;
if ( F_22 ( & V_3 -> V_19 ) )
V_47 -> V_48 . V_64 ( V_47 , & V_37 -> V_41 ) ;
return V_22 ;
}
int F_34 ( struct V_2 * V_3 , unsigned int V_4 ,
struct V_26 * V_18 )
{
int V_22 ;
struct V_1 * V_5 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_5 ( L_13 , V_4 ) ;
return - V_69 ;
}
V_5 -> V_6 -> V_7 . V_70 = V_18 -> V_70 ;
V_5 -> V_6 -> V_7 . V_71 = V_18 -> V_71 ;
V_5 -> V_6 -> V_7 . V_72 = V_18 -> V_72 ;
V_5 -> V_6 -> V_7 . V_73 = V_18 -> V_73 ;
V_22 = V_5 -> V_6 -> V_33 -> V_47 -> V_48 . V_74 ( V_5 -> V_6 -> V_33 -> V_47 ,
V_5 -> V_6 ) ;
if ( V_22 != 0 )
return V_22 ;
return 0 ;
}
struct V_38 * F_35 (
struct V_2 * V_3 ,
unsigned int V_4 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 && V_5 -> V_9 )
return V_5 -> V_9 ;
return NULL ;
}
