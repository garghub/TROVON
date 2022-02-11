int F_1 ( struct V_1 * V_2 , char * V_3 )
{
int V_4 ;
const T_1 * V_5 ;
T_2 V_6 , V_7 ;
unsigned int V_8 ;
if ( V_9 ) {
F_2 ( V_10 L_1
L_2 , V_3 ) ;
return - V_11 ;
}
V_9 = F_3 ( sizeof( struct V_9 ) , V_12 ) ;
if ( ! V_9 ) {
F_2 ( V_10 L_1
L_3 , V_3 ) ;
return - V_13 ;
}
V_5 = F_4 ( V_2 , 0 , & V_7 , NULL ) ;
if ( ! V_5 ) {
F_2 ( V_10 L_1
L_4 , V_3 ) ;
V_4 = - V_14 ;
goto V_15;
}
V_6 = F_5 ( V_2 , V_5 ) ;
V_9 -> V_16 = ( V_17 ) V_6 ;
V_9 -> V_18 = ( unsigned int ) V_7 ;
if ( ! F_6 ( V_9 -> V_16 , V_9 -> V_18 , V_3 ) ) {
F_2 ( V_10 L_1
L_5 , V_3 ) ;
V_4 = - V_11 ;
goto V_15;
}
V_9 -> V_19 = ( void * ) F_7 ( V_9 -> V_16 , V_9 -> V_18 ) ;
if ( ! V_9 -> V_19 ) {
F_2 ( V_10 L_1
L_6 ,
V_3 , ( long ) V_9 -> V_16 , V_9 -> V_18 ) ;
V_4 = - V_13 ;
goto V_20;
}
V_9 -> V_21 = F_8 ( 4 ) ;
#if 0
reg_addr_p = of_get_property(sram_node, "available", &psize);
#else
V_5 = NULL ;
V_8 = 0 ;
#endif
if ( ! V_5 || ! V_8 ) {
F_9 ( V_9 -> V_21 , 0 , V_9 -> V_18 ) ;
} else {
while ( V_8 >= 2 * sizeof( T_1 ) ) {
V_17 V_22 = F_5 ( V_2 , V_5 ) ;
F_9 ( V_9 -> V_21 , V_22 - V_9 -> V_16 , V_5 [ 1 ] ) ;
V_5 += 2 ;
V_8 -= 2 * sizeof( T_1 ) ;
}
}
F_10 ( & V_9 -> V_23 ) ;
return 0 ;
V_20:
F_11 ( V_9 -> V_16 , V_9 -> V_18 ) ;
V_15:
F_12 ( V_9 ) ;
V_9 = NULL ;
return V_4 ;
}
void F_13 ( void )
{
if ( V_9 ) {
F_14 ( V_9 -> V_21 ) ;
F_15 ( ( void V_24 * ) V_9 -> V_19 ) ;
F_11 ( V_9 -> V_16 , V_9 -> V_18 ) ;
F_12 ( V_9 ) ;
V_9 = NULL ;
}
}
void * F_16 ( int V_18 , int V_25 , V_17 * V_26 )
{
unsigned long V_27 ;
F_17 ( & V_9 -> V_23 ) ;
V_27 = F_18 ( V_9 -> V_21 , V_18 , V_25 , NULL ) ;
F_19 ( & V_9 -> V_23 ) ;
if ( F_20 ( V_27 ) )
return NULL ;
* V_26 = V_9 -> V_16 + V_27 ;
return V_9 -> V_19 + V_27 ;
}
void F_21 ( void * V_28 )
{
unsigned long V_27 ;
if ( ! V_28 )
return;
V_27 = V_28 - V_9 -> V_19 ;
F_17 ( & V_9 -> V_23 ) ;
F_22 ( V_9 -> V_21 , V_27 ) ;
F_19 ( & V_9 -> V_23 ) ;
}
