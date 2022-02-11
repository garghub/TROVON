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
V_12 = F_6 ( & V_11 -> V_19 , V_16 ) ;
if ( F_7 ( V_12 ) )
return F_8 ( V_12 ) ;
V_22 = F_9 ( V_16 ) ;
V_14 = F_10 ( & V_11 -> V_19 , sizeof( * V_14 ) , V_31 ) ;
if ( ! V_14 )
return - V_32 ;
V_14 -> V_33 = F_11 ( & V_11 -> V_19 , NULL ) ;
if ( F_7 ( V_14 -> V_33 ) )
V_14 -> V_33 = NULL ;
else
F_12 ( V_14 -> V_33 ) ;
V_14 -> V_34 = F_13 ( & V_11 -> V_19 , F_14 ( V_35 ) , - 1 ) ;
if ( ! V_14 -> V_34 )
return - V_32 ;
V_28 = ( V_18 ) ? F_15 ( V_18 ) + 1 : 1 ;
V_25 = F_16 ( ( V_28 ) * sizeof( * V_25 ) , V_31 ) ;
if ( ! V_25 ) {
V_29 = - V_32 ;
goto V_36;
}
V_26 = & V_25 [ 0 ] ;
F_17 (np, child) {
struct V_15 V_37 ;
V_29 = F_18 ( V_21 , 0 , & V_37 ) ;
if ( V_29 < 0 ) {
F_19 ( & V_11 -> V_19 ,
L_1 ,
V_21 -> V_38 ) ;
goto V_39;
}
if ( V_37 . V_9 < V_16 -> V_9 || V_37 . V_40 > V_16 -> V_40 ) {
F_19 ( & V_11 -> V_19 ,
L_2 ,
V_21 -> V_38 ) ;
V_29 = - V_41 ;
goto V_39;
}
V_26 -> V_9 = V_37 . V_9 - V_16 -> V_9 ;
V_26 -> V_22 = F_9 ( & V_37 ) ;
F_20 ( & V_26 -> V_7 , & V_27 ) ;
F_21 ( & V_11 -> V_19 , L_3 ,
V_26 -> V_9 ,
V_26 -> V_9 + V_26 -> V_22 ) ;
V_26 ++ ;
}
V_25 [ V_28 - 1 ] . V_9 = V_22 ;
V_25 [ V_28 - 1 ] . V_22 = 0 ;
F_20 ( & V_25 [ V_28 - 1 ] . V_7 , & V_27 ) ;
F_22 ( NULL , & V_27 , F_1 ) ;
V_23 = 0 ;
F_23 (block, &reserve_list, list) {
if ( V_26 -> V_9 < V_23 ) {
F_19 ( & V_11 -> V_19 ,
L_4 ,
V_26 -> V_9 , V_23 ) ;
V_29 = - V_41 ;
goto V_39;
}
if ( V_26 -> V_9 == V_23 ) {
V_23 = V_26 -> V_9 + V_26 -> V_22 ;
continue;
}
V_24 = V_26 -> V_9 - V_23 ;
F_21 ( & V_11 -> V_19 , L_5 ,
V_23 , V_23 + V_24 ) ;
V_29 = F_24 ( V_14 -> V_34 ,
( unsigned long ) V_12 + V_23 ,
V_16 -> V_9 + V_23 , V_24 , - 1 ) ;
if ( V_29 < 0 )
goto V_39;
V_23 = V_26 -> V_9 + V_26 -> V_22 ;
}
F_25 ( V_25 ) ;
F_26 ( V_11 , V_14 ) ;
F_21 ( & V_11 -> V_19 , L_6 , V_22 / 1024 , V_12 ) ;
return 0 ;
V_39:
F_25 ( V_25 ) ;
V_36:
if ( V_14 -> V_33 )
F_27 ( V_14 -> V_33 ) ;
return V_29 ;
}
static int F_28 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_29 ( V_11 ) ;
if ( F_30 ( V_14 -> V_34 ) < F_31 ( V_14 -> V_34 ) )
F_21 ( & V_11 -> V_19 , L_7 ) ;
if ( V_14 -> V_33 )
F_27 ( V_14 -> V_33 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_42 ) ;
}
