int F_1 ( struct V_1 * * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
if ( ! V_2 || ! V_5 || ! V_4 )
return - V_10 ;
F_2 ( V_4 , & V_8 ) ;
if ( ! V_8 )
return - V_10 ;
* V_2 = NULL ;
V_6 = F_3 ( sizeof( struct V_1 ) , V_11 ) ;
if ( ! V_6 )
return - V_12 ;
V_6 -> V_13 = V_5 ;
V_6 -> V_14 = V_8 ;
F_4 ( & V_6 -> V_15 ) ;
F_4 ( & V_6 -> V_16 ) ;
F_4 ( & V_6 -> V_17 ) ;
F_5 ( & V_6 -> V_18 ) ;
V_6 -> V_19 =
F_3 ( sizeof( struct V_20 ) , V_11 ) ;
if ( ! V_6 -> V_19 ) {
F_6 ( V_6 ) ;
return - V_12 ;
}
F_7 ( V_6 -> V_19 ) ;
* V_2 = V_6 ;
return V_9 ;
}
int F_8 ( struct V_1 * V_21 , struct V_22 * * V_23 ,
T_2 V_24 , T_2 V_25 , void * V_26 )
{
T_2 V_27 ;
T_2 V_28 = 0 ;
struct V_22 * V_29 ;
int V_9 = 0 ;
if ( ! V_21 || V_23 == NULL )
return - V_10 ;
* V_23 = NULL ;
V_29 = F_3 ( sizeof( struct V_22 ) , V_11 ) ;
if ( ! V_29 )
return - V_12 ;
V_29 -> V_25 = V_25 ;
V_29 -> V_1 = V_21 ;
V_29 -> V_26 = V_26 ;
V_29 -> V_24 = V_24 ;
F_4 ( & V_29 -> V_16 ) ;
F_4 ( & V_29 -> V_17 ) ;
V_29 -> V_19 = F_3 ( sizeof( struct V_20 ) , V_11 ) ;
if ( ! V_29 -> V_19 ) {
V_9 = - V_12 ;
goto V_30;
}
F_7 ( V_29 -> V_19 ) ;
V_29 -> V_31 = F_9 ( sizeof( struct V_32 ) , V_11 ) ;
if ( ! V_29 -> V_31 ) {
V_9 = - V_12 ;
goto V_30;
}
F_10 ( V_29 -> V_31 ) ;
V_29 -> V_33 = F_3 ( sizeof( struct V_20 ) , V_11 ) ;
if ( ! V_29 -> V_33 ) {
V_9 = - V_12 ;
goto V_30;
}
F_7 ( V_29 -> V_33 ) ;
V_29 -> V_34 = F_3 ( sizeof( struct V_20 ) , V_11 ) ;
if ( ! V_29 -> V_34 ) {
V_9 = - V_12 ;
goto V_30;
}
F_7 ( V_29 -> V_34 ) ;
F_11 ( & V_21 -> V_18 ) ;
for ( V_27 = 0 ; V_27 < V_25 && ! V_9 ; V_27 ++ ) {
V_9 = F_12 ( & V_21 -> V_16 ) ;
if ( ! V_9 ) {
V_28 ++ ;
V_9 = F_12 ( & V_29 -> V_16 ) ;
}
}
if ( V_9 ) {
F_13 ( & V_21 -> V_18 ) ;
goto V_30;
}
F_14 ( & V_29 -> V_35 , & V_21 -> V_15 ) ;
* V_23 = V_29 ;
if ( ! F_15 ( & V_21 -> V_16 ) )
F_16 ( V_21 -> V_19 ) ;
F_13 ( & V_21 -> V_18 ) ;
return 0 ;
V_30:
F_17 ( V_29 , V_28 ) ;
return V_9 ;
}
void F_18 ( struct V_1 * V_21 )
{
if ( V_21 )
F_19 ( V_21 ) ;
}
void F_20 ( struct V_22 * V_36 )
{
struct V_1 * V_21 ;
T_2 V_37 ;
if ( ! V_36 || ! V_36 -> V_1 )
return;
V_21 = V_36 -> V_1 ;
V_36 -> V_38 = true ;
V_37 = V_36 -> V_37 ;
while ( V_37 ) {
F_16 ( V_36 -> V_33 ) ;
F_21 ( V_36 -> V_34 , V_39 ) ;
V_37 = V_36 -> V_37 ;
}
F_11 ( & V_21 -> V_18 ) ;
F_22 ( & V_36 -> V_35 ) ;
F_17 ( V_36 , V_36 -> V_25 ) ;
if ( F_15 ( & V_21 -> V_16 ) )
F_23 ( V_21 -> V_19 ) ;
F_13 ( & V_21 -> V_18 ) ;
}
int F_24 ( struct V_22 * V_36 ,
struct V_40 * V_41 , T_2 V_42 )
{
struct V_43 * V_44 ;
struct V_1 * V_21 ;
struct V_20 * V_45 [ 2 ] ;
T_2 V_46 ;
int V_9 = 0 ;
if ( ! V_36 || V_41 == NULL )
return - V_12 ;
V_21 = V_36 -> V_1 ;
F_11 ( & V_21 -> V_18 ) ;
if ( ! F_15 ( & V_36 -> V_17 ) ) {
V_44 = F_25 ( & V_36 -> V_17 ,
struct V_43 , V_35 ) ;
F_22 ( & V_44 -> V_35 ) ;
* V_41 = V_44 -> V_47 . V_48 ;
F_14 ( & V_44 -> V_35 ,
& V_36 -> V_16 ) ;
if ( F_15 ( & V_36 -> V_17 ) )
F_23 ( V_36 -> V_19 ) ;
F_13 ( & V_21 -> V_18 ) ;
return 0 ;
}
if ( V_36 -> V_38 ) {
F_13 ( & V_21 -> V_18 ) ;
return - V_49 ;
}
V_36 -> V_37 ++ ;
F_13 ( & V_21 -> V_18 ) ;
V_45 [ 0 ] = V_36 -> V_19 ;
V_45 [ 1 ] = V_36 -> V_33 ;
V_9 = F_26 ( V_45 , 2 , V_42 , & V_46 ) ;
F_11 ( & V_21 -> V_18 ) ;
if ( V_36 -> V_38 ) {
V_36 -> V_37 -- ;
F_13 ( & V_21 -> V_18 ) ;
F_16 ( V_36 -> V_34 ) ;
return - V_49 ;
}
if ( ! V_9 && ! F_15 ( & V_36 -> V_17 ) ) {
V_44 = F_25 ( & V_36 -> V_17 ,
struct V_43 , V_35 ) ;
F_22 ( & V_44 -> V_35 ) ;
* V_41 = V_44 -> V_47 . V_48 ;
F_14 ( & V_44 -> V_35 ,
& V_36 -> V_16 ) ;
}
V_36 -> V_37 -- ;
if ( ! F_15 ( & V_36 -> V_17 ) )
F_16 ( V_36 -> V_19 ) ;
F_13 ( & V_21 -> V_18 ) ;
return V_9 ;
}
int F_27 ( struct V_22 * V_36 ,
const struct V_40 * V_41 , T_2 V_42 )
{
struct V_43 * V_44 ;
struct V_1 * V_21 ;
struct V_20 * V_45 [ 2 ] ;
T_2 V_46 ;
int V_9 ;
if ( ! V_36 || ! V_41 || ! V_36 -> V_1 )
return - V_10 ;
V_21 = V_36 -> V_1 ;
F_11 ( & V_21 -> V_18 ) ;
if ( ! F_15 ( & V_21 -> V_16 ) ) {
V_44 = F_25 ( & V_21 -> V_16 ,
struct V_43 , V_35 ) ;
F_22 ( & V_44 -> V_35 ) ;
V_44 -> V_47 . V_48 = * V_41 ;
V_44 -> V_47 . V_24 =
V_36 -> V_24 ;
F_14 ( & V_44 -> V_35 ,
& V_21 -> V_17 ) ;
V_21 -> V_50 ++ ;
if ( F_15 ( & V_21 -> V_16 ) )
F_23 ( V_21 -> V_19 ) ;
F_13 ( & V_21 -> V_18 ) ;
F_28 ( V_21 -> V_14 ) ;
return 0 ;
}
if ( V_36 -> V_38 ) {
F_13 ( & V_21 -> V_18 ) ;
return - V_49 ;
}
V_36 -> V_37 ++ ;
F_13 ( & V_21 -> V_18 ) ;
V_45 [ 0 ] = V_21 -> V_19 ;
V_45 [ 1 ] = V_36 -> V_33 ;
V_9 = F_26 ( V_45 , 2 , V_42 , & V_46 ) ;
if ( V_9 )
return V_9 ;
F_11 ( & V_21 -> V_18 ) ;
if ( V_36 -> V_38 ) {
V_36 -> V_37 -- ;
F_13 ( & V_21 -> V_18 ) ;
F_16 ( V_36 -> V_34 ) ;
return - V_49 ;
}
if ( F_15 ( & V_21 -> V_16 ) ) {
F_13 ( & V_21 -> V_18 ) ;
return - V_10 ;
}
V_44 = F_25 ( & V_21 -> V_16 ,
struct V_43 , V_35 ) ;
F_22 ( & V_44 -> V_35 ) ;
V_44 -> V_47 . V_48 = * V_41 ;
V_44 -> V_47 . V_24 = V_36 -> V_24 ;
F_14 ( & V_44 -> V_35 , & V_21 -> V_17 ) ;
V_21 -> V_50 ++ ;
F_28 ( V_21 -> V_14 ) ;
V_36 -> V_37 -- ;
if ( ! F_15 ( & V_21 -> V_16 ) )
F_16 ( V_21 -> V_19 ) ;
F_13 ( & V_21 -> V_18 ) ;
return 0 ;
}
int F_29 ( struct V_22 * V_36 ,
T_2 V_51 , T_2 V_52 ,
struct V_53 * V_54 )
{
int V_9 = 0 ;
if ( ! V_36 || ! V_54 ) {
V_9 = - V_12 ;
goto V_55;
}
if ( ! ( V_51 == V_56 || V_51 == 0 ) ) {
V_9 = - V_49 ;
goto V_55;
}
if ( V_52 != V_57 ) {
V_9 = - V_58 ;
goto V_55;
}
if ( V_51 )
V_9 = F_30 ( V_36 -> V_31 , V_54 ,
V_51 , V_52 ) ;
else
V_9 = F_31 ( V_36 -> V_31 ,
V_54 ) ;
if ( V_9 == - V_59 ) {
V_9 = 0 ;
}
V_55:
return V_9 ;
}
void F_32 ( struct V_22 * V_36 , T_2 V_24 )
{
if ( V_36 )
V_36 -> V_24 = V_24 ;
}
static int F_12 ( struct V_60 * V_61 )
{
struct V_43 * V_41 ;
V_41 = F_3 ( sizeof( struct V_43 ) , V_62 ) ;
if ( ! V_41 )
return - V_12 ;
F_14 ( & V_41 -> V_35 , V_61 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_21 )
{
if ( ! V_21 )
return;
F_33 ( & V_21 -> V_16 ) ;
F_33 ( & V_21 -> V_17 ) ;
F_6 ( V_21 -> V_19 ) ;
F_6 ( V_21 ) ;
}
static void F_17 ( struct V_22 * V_36 , T_2 V_63 )
{
struct V_1 * V_21 ;
struct V_43 * V_41 , * V_64 ;
T_2 V_27 ;
if ( ! V_36 || ! V_36 -> V_1 )
return;
V_21 = V_36 -> V_1 ;
V_27 = 0 ;
F_34 (pmsg, tmp, &hmsg_mgr->msg_free_list,
list_elem) {
F_22 ( & V_41 -> V_35 ) ;
F_6 ( V_41 ) ;
if ( V_27 ++ >= V_63 )
break;
}
F_33 ( & V_36 -> V_16 ) ;
F_33 ( & V_36 -> V_17 ) ;
if ( V_36 -> V_31 ) {
F_35 ( V_36 -> V_31 ) ;
F_6 ( V_36 -> V_31 ) ;
}
F_6 ( V_36 -> V_19 ) ;
F_6 ( V_36 -> V_33 ) ;
F_6 ( V_36 -> V_34 ) ;
F_6 ( V_36 ) ;
}
static void F_33 ( struct V_60 * V_61 )
{
struct V_43 * V_41 , * V_64 ;
if ( ! V_61 )
return;
F_34 (pmsg, tmp, msg_list, list_elem) {
F_22 ( & V_41 -> V_35 ) ;
F_6 ( V_41 ) ;
}
}
