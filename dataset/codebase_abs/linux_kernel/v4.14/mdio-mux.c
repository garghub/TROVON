static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_11 ;
F_2 ( & V_9 -> V_1 -> V_12 , V_13 ) ;
V_11 = V_9 -> V_14 ( V_9 -> V_15 , V_6 -> V_16 , V_9 -> V_17 ) ;
if ( V_11 )
goto V_18;
V_9 -> V_15 = V_6 -> V_16 ;
V_11 = V_9 -> V_1 -> V_19 ( V_9 -> V_1 , V_3 , V_4 ) ;
V_18:
F_3 ( & V_9 -> V_1 -> V_12 ) ;
return V_11 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_1 V_20 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_11 ;
F_2 ( & V_9 -> V_1 -> V_12 , V_13 ) ;
V_11 = V_9 -> V_14 ( V_9 -> V_15 , V_6 -> V_16 , V_9 -> V_17 ) ;
if ( V_11 )
goto V_18;
V_9 -> V_15 = V_6 -> V_16 ;
V_11 = V_9 -> V_1 -> V_21 ( V_9 -> V_1 , V_3 , V_4 , V_20 ) ;
V_18:
F_3 ( & V_9 -> V_1 -> V_12 ) ;
return V_11 ;
}
int F_5 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
int (* V_14)( int V_26 , int V_27 , void * V_28 ) ,
void * * V_29 ,
void * V_28 ,
struct V_1 * V_30 )
{
struct V_24 * V_31 ;
struct V_24 * V_32 ;
int V_11 , V_33 ;
struct V_1 * V_34 ;
struct V_8 * V_9 ;
struct V_5 * V_6 ;
if ( ! V_25 )
return - V_35 ;
if ( ! V_30 ) {
V_31 = F_6 ( V_25 ,
L_1 , 0 ) ;
if ( ! V_31 )
return - V_35 ;
V_34 = F_7 ( V_31 ) ;
if ( ! V_34 ) {
V_33 = - V_36 ;
goto V_37;
}
} else {
V_31 = NULL ;
V_34 = V_30 ;
F_8 ( & V_34 -> V_23 ) ;
}
V_9 = F_9 ( V_23 , sizeof( * V_9 ) , V_38 ) ;
if ( ! V_9 ) {
V_33 = - V_39 ;
goto V_40;
}
V_9 -> V_17 = V_28 ;
V_9 -> V_14 = V_14 ;
V_9 -> V_15 = - 1 ;
V_9 -> V_41 = V_42 ++ ;
V_9 -> V_1 = V_34 ;
V_33 = - V_35 ;
F_10 (mux_node, child_bus_node) {
int V_43 ;
V_11 = F_11 ( V_32 , L_2 , & V_43 ) ;
if ( V_11 ) {
F_12 ( V_23 ,
L_3 ,
V_32 ) ;
continue;
}
V_6 = F_9 ( V_23 , sizeof( * V_6 ) , V_38 ) ;
if ( ! V_6 ) {
V_33 = - V_39 ;
continue;
}
V_6 -> V_16 = V_43 ;
V_6 -> V_10 = V_9 ;
V_6 -> V_1 = F_13 () ;
if ( ! V_6 -> V_1 ) {
V_33 = - V_39 ;
F_14 ( V_23 , V_6 ) ;
continue;
}
V_6 -> V_1 -> V_7 = V_6 ;
V_6 -> V_1 -> V_44 = L_4 ;
snprintf ( V_6 -> V_1 -> V_45 , V_46 , L_5 ,
V_9 -> V_41 , V_43 ) ;
V_6 -> V_1 -> V_10 = V_23 ;
V_6 -> V_1 -> V_19 = F_1 ;
V_6 -> V_1 -> V_21 = F_4 ;
V_11 = F_15 ( V_6 -> V_1 , V_32 ) ;
if ( V_11 ) {
F_12 ( V_23 ,
L_6 ,
V_32 ) ;
F_16 ( V_6 -> V_1 ) ;
F_14 ( V_23 , V_6 ) ;
} else {
V_6 -> V_47 = V_9 -> V_48 ;
V_9 -> V_48 = V_6 ;
}
}
if ( V_9 -> V_48 ) {
* V_29 = V_9 ;
return 0 ;
}
F_12 ( V_23 , L_7 ) ;
F_14 ( V_23 , V_9 ) ;
V_40:
F_17 ( & V_34 -> V_23 ) ;
V_37:
F_18 ( V_31 ) ;
return V_33 ;
}
void F_19 ( void * V_29 )
{
struct V_8 * V_9 = V_29 ;
struct V_5 * V_6 = V_9 -> V_48 ;
while ( V_6 ) {
F_20 ( V_6 -> V_1 ) ;
F_16 ( V_6 -> V_1 ) ;
V_6 = V_6 -> V_47 ;
}
F_17 ( & V_9 -> V_1 -> V_23 ) ;
}
