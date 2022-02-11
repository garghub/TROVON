static int F_1 ( void * V_1 , struct V_2 * V_3 ,
struct V_2 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 , struct V_5 , V_7 ) ;
struct V_5 * V_8 = F_2 ( V_4 , struct V_5 , V_7 ) ;
return V_6 -> V_9 - V_8 -> V_9 ;
}
static int F_3 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_11 -> V_16 -> V_17 , * V_18 ;
unsigned long V_19 , V_20 , V_21 ;
struct V_5 * V_22 , * V_23 ;
struct V_2 V_24 ;
unsigned int V_25 ;
int V_26 = 0 ;
F_4 ( & V_24 ) ;
V_19 = F_5 ( V_13 ) ;
V_25 = ( V_15 ) ? F_6 ( V_15 ) + 1 : 1 ;
V_22 = F_7 ( ( V_25 ) * sizeof( * V_22 ) , V_27 ) ;
if ( ! V_22 )
return - V_28 ;
V_23 = & V_22 [ 0 ] ;
F_8 (np, child) {
struct V_12 V_29 ;
V_26 = F_9 ( V_18 , 0 , & V_29 ) ;
if ( V_26 < 0 ) {
F_10 ( V_11 -> V_16 ,
L_1 ,
V_18 -> V_30 ) ;
F_11 ( V_18 ) ;
goto V_31;
}
if ( V_29 . V_9 < V_13 -> V_9 || V_29 . V_32 > V_13 -> V_32 ) {
F_10 ( V_11 -> V_16 ,
L_2 ,
V_18 -> V_30 ) ;
V_26 = - V_33 ;
F_11 ( V_18 ) ;
goto V_31;
}
V_23 -> V_9 = V_29 . V_9 - V_13 -> V_9 ;
V_23 -> V_19 = F_5 ( & V_29 ) ;
F_12 ( & V_23 -> V_7 , & V_24 ) ;
F_13 ( V_11 -> V_16 , L_3 ,
V_23 -> V_9 , V_23 -> V_9 + V_23 -> V_19 ) ;
V_23 ++ ;
}
V_22 [ V_25 - 1 ] . V_9 = V_19 ;
V_22 [ V_25 - 1 ] . V_19 = 0 ;
F_12 ( & V_22 [ V_25 - 1 ] . V_7 , & V_24 ) ;
F_14 ( NULL , & V_24 , F_1 ) ;
V_20 = 0 ;
F_15 (block, &reserve_list, list) {
if ( V_23 -> V_9 < V_20 ) {
F_10 ( V_11 -> V_16 ,
L_4 ,
V_23 -> V_9 , V_20 ) ;
V_26 = - V_33 ;
goto V_31;
}
if ( V_23 -> V_9 == V_20 ) {
V_20 = V_23 -> V_9 + V_23 -> V_19 ;
continue;
}
V_21 = V_23 -> V_9 - V_20 ;
F_13 ( V_11 -> V_16 , L_5 ,
V_20 , V_20 + V_21 ) ;
V_26 = F_16 ( V_11 -> V_34 ,
( unsigned long ) V_11 -> V_35 + V_20 ,
V_13 -> V_9 + V_20 , V_21 , - 1 ) ;
if ( V_26 < 0 )
goto V_31;
V_20 = V_23 -> V_9 + V_23 -> V_19 ;
}
V_31:
F_17 ( V_22 ) ;
return V_26 ;
}
static int F_18 ( struct V_36 * V_37 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
T_1 V_19 ;
int V_26 ;
V_11 = F_19 ( & V_37 -> V_16 , sizeof( * V_11 ) , V_27 ) ;
if ( ! V_11 )
return - V_28 ;
V_11 -> V_16 = & V_37 -> V_16 ;
V_13 = F_20 ( V_37 , V_38 , 0 ) ;
if ( ! V_13 ) {
F_10 ( V_11 -> V_16 , L_6 ) ;
return - V_33 ;
}
V_19 = F_5 ( V_13 ) ;
if ( ! F_21 ( V_11 -> V_16 , V_13 -> V_9 , V_19 , V_37 -> V_39 ) ) {
F_10 ( V_11 -> V_16 , L_7 ) ;
return - V_40 ;
}
V_11 -> V_35 = F_22 ( V_11 -> V_16 , V_13 -> V_9 , V_19 ) ;
if ( F_23 ( V_11 -> V_35 ) )
return F_24 ( V_11 -> V_35 ) ;
V_11 -> V_34 = F_25 ( V_11 -> V_16 ,
F_26 ( V_41 ) , - 1 ) ;
if ( ! V_11 -> V_34 )
return - V_28 ;
V_26 = F_3 ( V_11 , V_13 ) ;
if ( V_26 )
return V_26 ;
V_11 -> V_42 = F_27 ( V_11 -> V_16 , NULL ) ;
if ( F_23 ( V_11 -> V_42 ) )
V_11 -> V_42 = NULL ;
else
F_28 ( V_11 -> V_42 ) ;
F_29 ( V_37 , V_11 ) ;
F_13 ( V_11 -> V_16 , L_8 ,
F_30 ( V_11 -> V_34 ) / 1024 , V_11 -> V_35 ) ;
return 0 ;
}
static int F_31 ( struct V_36 * V_37 )
{
struct V_10 * V_11 = F_32 ( V_37 ) ;
if ( F_33 ( V_11 -> V_34 ) < F_30 ( V_11 -> V_34 ) )
F_10 ( V_11 -> V_16 , L_9 ) ;
if ( V_11 -> V_42 )
F_34 ( V_11 -> V_42 ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
return F_36 ( & V_43 ) ;
}
