int F_1 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
T_1 * V_6 = V_3 ;
T_2 * V_7 = ( T_2 * ) V_2 -> V_8 ;
int V_9 ;
F_2 ( & V_2 -> V_10 ) ;
V_9 = F_3 ( & V_7 -> V_11 , V_12 , 0 ,
V_6 -> V_13 >> V_14 ) ;
if ( V_9 ) {
F_4 ( L_1 ) ;
F_5 ( & V_2 -> V_10 ) ;
return V_9 ;
}
V_7 -> V_15 = 1 ;
V_7 -> V_16 = V_6 -> V_17 ;
F_5 ( & V_2 -> V_10 ) ;
F_6 ( L_2 , V_6 -> V_17 , V_6 -> V_13 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
T_3 * V_18 = V_3 ;
T_2 * V_7 = ( T_2 * ) V_2 -> V_8 ;
int V_9 ;
F_2 ( & V_2 -> V_10 ) ;
V_9 = F_3 ( & V_7 -> V_11 , V_19 , 0 ,
V_18 -> V_13 >> V_14 ) ;
if ( V_9 ) {
F_4 ( L_3 ) ;
F_5 ( & V_2 -> V_10 ) ;
return V_9 ;
}
V_7 -> V_20 = 1 ;
V_7 -> V_21 = V_18 -> V_17 ;
F_5 ( & V_2 -> V_10 ) ;
F_6 ( L_2 , V_18 -> V_17 , V_18 -> V_13 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , int V_22 )
{
T_2 * V_7 = ( T_2 * ) V_2 -> V_8 ;
F_9 ( V_7 , V_22 ) ;
if ( V_2 -> V_23 == 1 && V_2 -> V_8 ) {
F_6 ( L_4 ) ;
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
F_2 ( & V_2 -> V_10 ) ;
F_14 ( & V_7 -> V_11 ) ;
V_7 -> V_20 = 0 ;
V_7 -> V_15 = 0 ;
F_5 ( & V_2 -> V_10 ) ;
}
int F_15 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
T_4 * V_24 = V_3 ;
int V_25 = 0 ;
struct V_26 * V_27 ;
T_2 * V_7 = ( T_2 * ) V_2 -> V_8 ;
unsigned long V_28 ;
if ( V_24 -> type > V_12 ) {
F_4 ( L_5 ) ;
return - V_29 ;
}
F_2 ( & V_2 -> V_10 ) ;
if ( 0 == ( ( V_24 -> type == V_19 ) ? V_7 -> V_20 :
V_7 -> V_15 ) ) {
F_4
( L_6 ) ;
F_5 ( & V_2 -> V_10 ) ;
return - V_29 ;
}
V_28 = ( V_24 -> V_13 + V_30 ) >> V_14 ;
V_27 = F_16 ( & V_7 -> V_11 , V_24 -> type , V_28 , 0 ,
( unsigned long ) V_5 ) ;
F_5 ( & V_2 -> V_10 ) ;
if ( V_27 ) {
V_24 -> V_17 = ( ( V_24 -> type == V_19 ) ?
V_7 -> V_21 : V_7 -> V_16 ) +
( V_27 -> V_31 ->
V_17 ( V_27 -> V_31 , V_27 -> V_32 ) << V_14 ) ;
V_24 -> V_33 = V_27 -> V_34 . V_35 ;
} else {
V_24 -> V_17 = 0 ;
V_24 -> V_13 = 0 ;
V_24 -> V_33 = 0 ;
F_6 ( L_7 ) ;
V_25 = - V_36 ;
}
return V_25 ;
}
int F_17 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
T_2 * V_7 = V_2 -> V_8 ;
T_4 * V_24 = V_3 ;
int V_9 ;
F_2 ( & V_2 -> V_10 ) ;
V_9 = F_18 ( & V_7 -> V_11 , V_24 -> V_33 ) ;
F_5 ( & V_2 -> V_10 ) ;
F_6 ( L_8 , V_24 -> V_33 ) ;
return V_9 ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
T_2 * V_7 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_10 ) ;
if ( F_20 ( & V_7 -> V_11 , ( unsigned long ) V_5 ) ) {
F_5 ( & V_2 -> V_10 ) ;
return;
}
if ( V_2 -> V_37 -> V_38 )
V_2 -> V_37 -> V_38 ( V_2 ) ;
F_21 ( & V_7 -> V_11 , ( unsigned long ) V_5 ) ;
F_5 ( & V_2 -> V_10 ) ;
return;
}
