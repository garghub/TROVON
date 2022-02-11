static T_1 F_1 ( int V_1 , void * V_2 )
{
T_2 type ;
int V_3 ;
F_2 ( & V_4 -> V_5 ) ;
type = F_3 ( V_4 -> V_6 + V_7 ) ;
F_4 ( L_1 , type ) ;
if ( type & V_8 && ! V_4 -> V_9 ) {
F_5 ( V_10 L_2 ) ;
V_3 = - V_11 ;
goto V_12;
}
if ( V_4 -> V_9 && ! ( type & V_8 ) ) {
F_5 ( V_10 L_3 , type ) ;
V_3 = - V_11 ;
goto V_12;
}
V_4 -> V_13 . type = type ;
V_4 -> V_13 . V_14 = F_3 ( V_4 -> V_6 + V_15 ) ;
V_4 -> V_13 . V_16 = F_3 ( V_4 -> V_6 + V_17 ) ;
V_4 -> V_13 . V_18 = F_3 ( V_4 -> V_6 + V_19 ) ;
V_3 = 0 ;
V_12:
F_6 ( & V_4 -> V_5 ) ;
if ( V_3 == - V_11 ) {
V_3 = V_20 ;
goto V_21;
}
if ( V_4 -> V_13 . type & V_8 ) {
F_7 ( V_4 -> V_9 ) ;
V_3 = V_20 ;
goto V_21;
}
F_8 ( & V_4 -> V_22 ) ;
V_3 = V_20 ;
V_21:
return V_3 ;
}
static void F_9 ( struct V_23 * V_22 )
{
struct V_24 * V_25 ;
F_2 ( & V_4 -> V_26 ) ;
F_10 (handler, &data->handler, node) {
F_4 ( L_4 , V_25 ) ;
if ( V_25 -> type == V_4 -> V_13 . type )
V_25 -> V_27 ( V_4 -> V_13 ) ;
}
F_6 ( & V_4 -> V_26 ) ;
}
static int F_11 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_29 . V_32 ;
int V_3 ;
if ( V_4 ) {
F_5 ( V_33 L_5 ) ;
V_3 = - V_34 ;
goto V_21;
}
V_4 = F_12 ( sizeof( struct V_35 ) , V_36 ) ;
if ( ! V_4 ) {
F_5 ( V_33 L_6 ) ;
V_3 = - V_37 ;
goto V_21;
}
V_4 -> V_6 = F_13 ( V_31 , 0 ) ;
if ( ! V_4 -> V_6 ) {
F_5 ( V_33 L_7 ) ;
V_3 = - V_38 ;
goto V_39;
}
F_14 ( & V_4 -> V_25 ) ;
F_15 ( & V_4 -> V_40 ) ;
F_16 ( & V_4 -> V_5 ) ;
F_16 ( & V_4 -> V_26 ) ;
F_17 ( & V_4 -> V_22 , F_9 ) ;
V_4 -> V_29 = V_29 ;
V_4 -> V_1 = F_18 ( V_31 , 0 ) ;
if ( V_4 -> V_1 == V_41 ) {
F_5 ( V_33 L_8 ) ;
V_3 = - V_38 ;
goto V_42;
}
V_3 = F_19 ( V_4 -> V_1 , F_1 , 0 , L_9 , NULL ) ;
if ( V_3 ) {
F_5 ( V_33 L_10 ,
V_4 -> V_1 , V_3 ) ;
goto V_42;
}
F_5 ( V_43 L_11 , V_4 -> V_6 ) ;
goto V_21;
V_42:
F_20 ( V_4 -> V_6 ) ;
V_39:
F_21 ( V_4 ) ;
V_21:
return V_3 ;
}
static int F_22 ( struct V_28 * V_29 )
{
struct V_24 * V_25 , * V_44 ;
F_23 ( V_4 -> V_1 , NULL ) ;
F_20 ( V_4 -> V_6 ) ;
F_2 ( & V_4 -> V_26 ) ;
F_24 (handler, tmp, &data->handler, node)
F_25 ( & V_25 -> V_45 ) ;
F_6 ( & V_4 -> V_26 ) ;
F_21 ( V_4 ) ;
V_4 = NULL ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_46 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_46 ) ;
}
int F_30 ( T_5 V_13 )
{
unsigned long V_47 ;
F_31 ( V_9 ) ;
if ( ! V_4 )
return - V_48 ;
F_32 ( & V_4 -> V_40 ) ;
V_4 -> V_13 = V_13 ;
F_4 ( L_12 , * ( V_49 * ) & V_13 ) ;
V_4 -> V_9 = & V_9 ;
F_33 ( & V_4 -> V_5 , V_47 ) ;
F_34 ( V_13 . V_14 , V_4 -> V_6 + V_50 ) ;
F_34 ( V_13 . V_16 , V_4 -> V_6 + V_51 ) ;
F_34 ( V_13 . V_18 , V_4 -> V_6 + V_52 ) ;
F_34 ( V_13 . type , V_4 -> V_6 + V_53 ) ;
F_35 ( & V_4 -> V_5 , V_47 ) ;
F_4 ( L_13 ) ;
F_36 ( V_4 -> V_9 ,
V_54 ) ;
V_4 -> V_9 = NULL ;
F_37 ( & V_4 -> V_40 ) ;
return 0 ;
}
int F_38 ( struct V_24 * V_25 )
{
if ( ! V_4 )
return - V_48 ;
F_2 ( & V_4 -> V_26 ) ;
F_39 ( & V_25 -> V_45 , & V_4 -> V_25 ) ;
F_6 ( & V_4 -> V_26 ) ;
return 0 ;
}
void F_40 ( struct V_24 * V_25 )
{
if ( ! V_4 )
return;
F_4 ( L_14 , V_25 ) ;
F_2 ( & V_4 -> V_26 ) ;
F_25 ( & V_25 -> V_45 ) ;
F_6 ( & V_4 -> V_26 ) ;
}
