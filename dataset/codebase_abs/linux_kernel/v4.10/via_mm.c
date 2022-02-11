int F_1 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
T_1 * V_6 = V_3 ;
T_2 * V_7 = ( T_2 * ) V_2 -> V_8 ;
F_2 ( & V_2 -> V_9 ) ;
F_3 ( & V_7 -> V_10 , 0 , V_6 -> V_11 >> V_12 ) ;
V_7 -> V_13 = 1 ;
V_7 -> V_14 = V_6 -> V_15 ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( L_1 , V_6 -> V_15 , V_6 -> V_11 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
T_3 * V_16 = V_3 ;
T_2 * V_7 = ( T_2 * ) V_2 -> V_8 ;
F_2 ( & V_2 -> V_9 ) ;
F_3 ( & V_7 -> V_17 , 0 , V_16 -> V_11 >> V_12 ) ;
V_7 -> V_18 = 1 ;
V_7 -> V_19 = V_16 -> V_15 ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( L_1 , V_16 -> V_15 , V_16 -> V_11 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , int V_20 )
{
T_2 * V_7 = ( T_2 * ) V_2 -> V_8 ;
F_8 ( V_7 , V_20 ) ;
if ( F_9 ( & V_2 -> V_21 ) ) {
F_5 ( L_2 ) ;
F_10 ( V_2 ) ;
F_11 ( V_7 ) ;
F_12 ( V_2 ) ;
}
return 1 ;
}
void F_13 ( struct V_1 * V_2 )
{
T_2 * V_7 = ( T_2 * ) V_2 -> V_8 ;
if ( ! V_7 )
return;
F_2 ( & V_2 -> V_9 ) ;
if ( V_7 -> V_18 ) {
F_14 ( & V_7 -> V_17 ) ;
V_7 -> V_18 = 0 ;
}
if ( V_7 -> V_13 ) {
F_14 ( & V_7 -> V_10 ) ;
V_7 -> V_13 = 0 ;
}
F_4 ( & V_2 -> V_9 ) ;
}
int F_15 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_22 )
{
T_4 * V_23 = V_3 ;
int V_24 = 0 , V_25 ;
struct V_26 * V_27 ;
T_2 * V_7 = ( T_2 * ) V_2 -> V_8 ;
struct V_28 * V_5 = V_22 -> V_29 ;
unsigned long V_30 ;
if ( V_23 -> type > V_31 ) {
F_16 ( L_3 ) ;
return - V_32 ;
}
F_2 ( & V_2 -> V_9 ) ;
if ( 0 == ( ( V_23 -> type == V_33 ) ? V_7 -> V_18 :
V_7 -> V_13 ) ) {
F_16
( L_4 ) ;
F_4 ( & V_2 -> V_9 ) ;
return - V_32 ;
}
V_27 = F_17 ( sizeof( * V_27 ) , V_34 ) ;
if ( ! V_27 ) {
V_24 = - V_35 ;
goto V_36;
}
V_30 = ( V_23 -> V_11 + V_37 ) >> V_12 ;
if ( V_23 -> type == V_31 )
V_24 = F_18 ( & V_7 -> V_10 ,
& V_27 -> V_38 ,
V_30 , 0 , V_39 ) ;
else
V_24 = F_18 ( & V_7 -> V_17 ,
& V_27 -> V_38 ,
V_30 , 0 , V_39 ) ;
if ( V_24 )
goto V_36;
V_24 = F_19 ( & V_7 -> V_40 , V_27 , 1 , 0 , V_34 ) ;
if ( V_24 < 0 )
goto V_41;
V_25 = V_24 ;
F_20 ( & V_27 -> V_42 , & V_5 -> V_43 ) ;
F_4 ( & V_2 -> V_9 ) ;
V_23 -> V_15 = ( ( V_23 -> type == V_33 ) ?
V_7 -> V_19 : V_7 -> V_14 ) +
( ( V_27 -> V_38 . V_44 ) << V_12 ) ;
V_23 -> V_45 = V_25 ;
return 0 ;
V_41:
F_21 ( & V_27 -> V_38 ) ;
V_36:
F_22 ( V_27 ) ;
F_4 ( & V_2 -> V_9 ) ;
V_23 -> V_15 = 0 ;
V_23 -> V_11 = 0 ;
V_23 -> V_45 = 0 ;
F_5 ( L_5 ) ;
return V_24 ;
}
int F_23 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
T_2 * V_7 = V_2 -> V_8 ;
T_4 * V_23 = V_3 ;
struct V_26 * V_46 ;
F_2 ( & V_2 -> V_9 ) ;
V_46 = F_24 ( & V_7 -> V_40 , V_23 -> V_45 ) ;
if ( V_46 == NULL ) {
F_4 ( & V_2 -> V_9 ) ;
return - V_32 ;
}
F_25 ( & V_7 -> V_40 , V_23 -> V_45 ) ;
F_26 ( & V_46 -> V_42 ) ;
F_21 ( & V_46 -> V_38 ) ;
F_22 ( V_46 ) ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( L_6 , V_23 -> V_45 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_2 ,
struct V_4 * V_22 )
{
struct V_28 * V_5 = V_22 -> V_29 ;
struct V_26 * V_47 , * V_48 ;
if ( ! ( V_2 -> V_49 && V_22 -> V_49 -> V_50 . V_51 ) )
return;
F_28 ( & V_22 -> V_49 -> V_50 ) ;
F_2 ( & V_2 -> V_9 ) ;
if ( F_29 ( & V_5 -> V_43 ) ) {
F_4 ( & V_2 -> V_9 ) ;
F_30 ( & V_22 -> V_49 -> V_50 ) ;
return;
}
F_31 ( V_2 ) ;
F_32 (entry, next, &file_priv->obj_list,
owner_list) {
F_26 ( & V_47 -> V_42 ) ;
F_21 ( & V_47 -> V_38 ) ;
F_22 ( V_47 ) ;
}
F_4 ( & V_2 -> V_9 ) ;
F_30 ( & V_22 -> V_49 -> V_50 ) ;
return;
}
