static int F_1 ( void * V_1 , struct V_2 * V_3 ,
struct V_2 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 , struct V_5 , V_7 ) ;
struct V_5 * V_8 = F_2 ( V_4 , struct V_5 , V_7 ) ;
return V_6 -> V_9 - V_8 -> V_9 ;
}
static int F_3 ( struct V_10 * V_11 )
{
void T_1 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 = V_11 -> V_19 . V_20 , * V_21 ;
unsigned long V_22 , V_23 , V_24 ;
struct V_5 * V_25 , * V_26 ;
struct V_2 V_27 ;
unsigned int V_28 ;
int V_29 ;
F_4 ( & V_27 ) ;
V_16 = F_5 ( V_11 , V_30 , 0 ) ;
if ( ! V_16 ) {
F_6 ( & V_11 -> V_19 , L_1 ) ;
return - V_31 ;
}
V_22 = F_7 ( V_16 ) ;
if ( ! F_8 ( & V_11 -> V_19 ,
V_16 -> V_9 , V_22 , V_11 -> V_32 ) ) {
F_6 ( & V_11 -> V_19 , L_2 ) ;
return - V_33 ;
}
V_12 = F_9 ( & V_11 -> V_19 , V_16 -> V_9 , V_22 ) ;
if ( F_10 ( V_12 ) )
return F_11 ( V_12 ) ;
V_14 = F_12 ( & V_11 -> V_19 , sizeof( * V_14 ) , V_34 ) ;
if ( ! V_14 )
return - V_35 ;
V_14 -> V_36 = F_13 ( & V_11 -> V_19 , NULL ) ;
if ( F_10 ( V_14 -> V_36 ) )
V_14 -> V_36 = NULL ;
else
F_14 ( V_14 -> V_36 ) ;
V_14 -> V_37 = F_15 ( & V_11 -> V_19 , F_16 ( V_38 ) , - 1 ) ;
if ( ! V_14 -> V_37 )
return - V_35 ;
V_28 = ( V_18 ) ? F_17 ( V_18 ) + 1 : 1 ;
V_25 = F_18 ( ( V_28 ) * sizeof( * V_25 ) , V_34 ) ;
if ( ! V_25 ) {
V_29 = - V_35 ;
goto V_39;
}
V_26 = & V_25 [ 0 ] ;
F_19 (np, child) {
struct V_15 V_40 ;
V_29 = F_20 ( V_21 , 0 , & V_40 ) ;
if ( V_29 < 0 ) {
F_6 ( & V_11 -> V_19 ,
L_3 ,
V_21 -> V_41 ) ;
goto V_42;
}
if ( V_40 . V_9 < V_16 -> V_9 || V_40 . V_43 > V_16 -> V_43 ) {
F_6 ( & V_11 -> V_19 ,
L_4 ,
V_21 -> V_41 ) ;
V_29 = - V_31 ;
goto V_42;
}
V_26 -> V_9 = V_40 . V_9 - V_16 -> V_9 ;
V_26 -> V_22 = F_7 ( & V_40 ) ;
F_21 ( & V_26 -> V_7 , & V_27 ) ;
F_22 ( & V_11 -> V_19 , L_5 ,
V_26 -> V_9 ,
V_26 -> V_9 + V_26 -> V_22 ) ;
V_26 ++ ;
}
V_25 [ V_28 - 1 ] . V_9 = V_22 ;
V_25 [ V_28 - 1 ] . V_22 = 0 ;
F_21 ( & V_25 [ V_28 - 1 ] . V_7 , & V_27 ) ;
F_23 ( NULL , & V_27 , F_1 ) ;
V_23 = 0 ;
F_24 (block, &reserve_list, list) {
if ( V_26 -> V_9 < V_23 ) {
F_6 ( & V_11 -> V_19 ,
L_6 ,
V_26 -> V_9 , V_23 ) ;
V_29 = - V_31 ;
goto V_42;
}
if ( V_26 -> V_9 == V_23 ) {
V_23 = V_26 -> V_9 + V_26 -> V_22 ;
continue;
}
V_24 = V_26 -> V_9 - V_23 ;
F_22 ( & V_11 -> V_19 , L_7 ,
V_23 , V_23 + V_24 ) ;
V_29 = F_25 ( V_14 -> V_37 ,
( unsigned long ) V_12 + V_23 ,
V_16 -> V_9 + V_23 , V_24 , - 1 ) ;
if ( V_29 < 0 )
goto V_42;
V_23 = V_26 -> V_9 + V_26 -> V_22 ;
}
F_26 ( V_25 ) ;
F_27 ( V_11 , V_14 ) ;
F_22 ( & V_11 -> V_19 , L_8 , V_22 / 1024 , V_12 ) ;
return 0 ;
V_42:
F_26 ( V_25 ) ;
V_39:
if ( V_14 -> V_36 )
F_28 ( V_14 -> V_36 ) ;
return V_29 ;
}
static int F_29 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_30 ( V_11 ) ;
if ( F_31 ( V_14 -> V_37 ) < F_32 ( V_14 -> V_37 ) )
F_22 ( & V_11 -> V_19 , L_9 ) ;
if ( V_14 -> V_36 )
F_28 ( V_14 -> V_36 ) ;
return 0 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_44 ) ;
}
