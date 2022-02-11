void F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
bool V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_10 ;
if ( V_3 ) {
F_2 ( & V_2 -> V_11 ,
V_9 -> V_12 , 0 ) ;
F_2 ( & V_2 -> V_11 ,
V_9 -> V_13 ,
V_3 ) ;
}
if ( V_4 )
F_2 ( & V_2 -> V_11 ,
V_9 -> V_14 , 0 ) ;
if ( V_5 ) {
F_2 ( & V_2 -> V_11 ,
V_9 -> V_15 , 0 ) ;
F_2 ( & V_2 -> V_11 ,
V_9 -> V_16 ,
V_5 ) ;
}
}
int F_3 ( struct V_1 * V_2 ,
int V_17 )
{
T_2 * V_18 , * V_19 , * V_20 ;
int V_21 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_22 = F_4 ( V_17 , sizeof( T_2 ) * 3 ,
V_23 ) ;
if ( ! V_2 -> V_22 ) {
V_2 -> V_17 = 0 ;
return - V_24 ;
}
V_18 = V_2 -> V_22 ;
V_19 = V_18 + V_17 ;
V_20 = V_19 + V_17 ;
for ( V_21 = 0 ; V_21 < V_17 ; V_21 ++ ) {
V_18 [ V_21 ] = V_21 << 8 ;
V_19 [ V_21 ] = V_21 << 8 ;
V_20 [ V_21 ] = V_21 << 8 ;
}
return 0 ;
}
int F_5 ( struct V_6 * V_7 ,
void * V_25 , struct V_26 * V_27 )
{
struct V_28 * V_29 = V_25 ;
struct V_1 * V_2 ;
void * V_18 , * V_19 , * V_20 ;
int V_30 ;
int V_31 = 0 ;
if ( ! F_6 ( V_7 , V_32 ) )
return - V_33 ;
F_7 ( V_7 ) ;
V_2 = F_8 ( V_7 , V_29 -> V_34 ) ;
if ( ! V_2 ) {
V_31 = - V_35 ;
goto V_36;
}
if ( V_2 -> V_37 -> V_38 == NULL ) {
V_31 = - V_39 ;
goto V_36;
}
if ( V_29 -> V_17 != V_2 -> V_17 ) {
V_31 = - V_33 ;
goto V_36;
}
V_30 = V_29 -> V_17 * ( sizeof( T_2 ) ) ;
V_18 = V_2 -> V_22 ;
if ( F_9 ( V_18 , ( void V_40 * ) ( unsigned long ) V_29 -> V_41 , V_30 ) ) {
V_31 = - V_42 ;
goto V_36;
}
V_19 = V_18 + V_30 ;
if ( F_9 ( V_19 , ( void V_40 * ) ( unsigned long ) V_29 -> V_43 , V_30 ) ) {
V_31 = - V_42 ;
goto V_36;
}
V_20 = V_19 + V_30 ;
if ( F_9 ( V_20 , ( void V_40 * ) ( unsigned long ) V_29 -> V_44 , V_30 ) ) {
V_31 = - V_42 ;
goto V_36;
}
V_31 = V_2 -> V_37 -> V_38 ( V_2 , V_18 , V_19 , V_20 , V_2 -> V_17 ) ;
V_36:
F_10 ( V_7 ) ;
return V_31 ;
}
int F_11 ( struct V_6 * V_7 ,
void * V_25 , struct V_26 * V_27 )
{
struct V_28 * V_29 = V_25 ;
struct V_1 * V_2 ;
void * V_18 , * V_19 , * V_20 ;
int V_30 ;
int V_31 = 0 ;
if ( ! F_6 ( V_7 , V_32 ) )
return - V_33 ;
F_7 ( V_7 ) ;
V_2 = F_8 ( V_7 , V_29 -> V_34 ) ;
if ( ! V_2 ) {
V_31 = - V_35 ;
goto V_36;
}
if ( V_29 -> V_17 != V_2 -> V_17 ) {
V_31 = - V_33 ;
goto V_36;
}
V_30 = V_29 -> V_17 * ( sizeof( T_2 ) ) ;
V_18 = V_2 -> V_22 ;
if ( F_12 ( ( void V_40 * ) ( unsigned long ) V_29 -> V_41 , V_18 , V_30 ) ) {
V_31 = - V_42 ;
goto V_36;
}
V_19 = V_18 + V_30 ;
if ( F_12 ( ( void V_40 * ) ( unsigned long ) V_29 -> V_43 , V_19 , V_30 ) ) {
V_31 = - V_42 ;
goto V_36;
}
V_20 = V_19 + V_30 ;
if ( F_12 ( ( void V_40 * ) ( unsigned long ) V_29 -> V_44 , V_20 , V_30 ) ) {
V_31 = - V_42 ;
goto V_36;
}
V_36:
F_10 ( V_7 ) ;
return V_31 ;
}
