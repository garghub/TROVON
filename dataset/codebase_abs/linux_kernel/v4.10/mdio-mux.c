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
int (* V_14)( int V_24 , int V_25 , void * V_26 ) ,
void * * V_27 ,
void * V_26 ,
struct V_1 * V_28 )
{
struct V_29 * V_30 ;
struct V_29 * V_31 ;
int V_11 , V_32 ;
struct V_1 * V_33 ;
struct V_8 * V_9 ;
struct V_5 * V_6 ;
if ( ! V_23 -> V_34 )
return - V_35 ;
if ( ! V_28 ) {
V_30 = F_6 ( V_23 -> V_34 ,
L_1 , 0 ) ;
if ( ! V_30 )
return - V_35 ;
V_33 = F_7 ( V_30 ) ;
if ( ! V_33 ) {
V_32 = - V_36 ;
goto V_37;
}
} else {
V_30 = NULL ;
V_33 = V_28 ;
}
V_9 = F_8 ( V_23 , sizeof( * V_9 ) , V_38 ) ;
if ( V_9 == NULL ) {
V_32 = - V_39 ;
goto V_37;
}
V_9 -> V_17 = V_26 ;
V_9 -> V_14 = V_14 ;
V_9 -> V_15 = - 1 ;
V_9 -> V_40 = V_41 ++ ;
V_9 -> V_1 = V_33 ;
V_32 = - V_35 ;
F_9 (dev->of_node, child_bus_node) {
T_2 V_42 ;
V_11 = F_10 ( V_31 , L_2 , & V_42 ) ;
if ( V_11 )
continue;
V_6 = F_8 ( V_23 , sizeof( * V_6 ) , V_38 ) ;
if ( V_6 == NULL ) {
F_11 ( V_23 ,
L_3 ) ;
V_32 = - V_39 ;
F_12 ( V_31 ) ;
break;
}
V_6 -> V_16 = V_42 ;
V_6 -> V_10 = V_9 ;
V_6 -> V_1 = F_13 () ;
if ( ! V_6 -> V_1 ) {
V_32 = - V_39 ;
F_12 ( V_31 ) ;
break;
}
V_6 -> V_1 -> V_7 = V_6 ;
V_6 -> V_1 -> V_43 = L_4 ;
snprintf ( V_6 -> V_1 -> V_44 , V_45 , L_5 ,
V_9 -> V_40 , V_42 ) ;
V_6 -> V_1 -> V_10 = V_23 ;
V_6 -> V_1 -> V_19 = F_1 ;
V_6 -> V_1 -> V_21 = F_4 ;
V_11 = F_14 ( V_6 -> V_1 , V_31 ) ;
if ( V_11 ) {
F_15 ( V_6 -> V_1 ) ;
F_16 ( V_23 , V_6 ) ;
} else {
F_17 ( V_31 ) ;
V_6 -> V_46 = V_9 -> V_47 ;
V_9 -> V_47 = V_6 ;
}
}
if ( V_9 -> V_47 ) {
* V_27 = V_9 ;
F_18 ( V_23 , L_6 V_48 L_7 ) ;
return 0 ;
}
F_19 ( & V_9 -> V_1 -> V_23 ) ;
V_37:
F_12 ( V_30 ) ;
return V_32 ;
}
void F_20 ( void * V_27 )
{
struct V_8 * V_9 = V_27 ;
struct V_5 * V_6 = V_9 -> V_47 ;
while ( V_6 ) {
F_21 ( V_6 -> V_1 ) ;
F_15 ( V_6 -> V_1 ) ;
V_6 = V_6 -> V_46 ;
}
F_19 ( & V_9 -> V_1 -> V_23 ) ;
}
