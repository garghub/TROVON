void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 , V_6 ;
F_2 (domain, hwirq, irq) {
V_4 = F_3 ( V_6 ) ;
if ( ! V_4 ) {
F_4 ( 1 , L_1 ) ;
return;
}
if ( V_4 -> V_2 ) {
F_4 ( 1 , L_2 ) ;
return;
}
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_5 ;
}
F_5 ( & V_7 ) ;
F_6 ( & V_2 -> V_8 , & V_9 ) ;
F_7 ( & V_7 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 , V_6 ;
F_5 ( & V_7 ) ;
F_9 ( & V_2 -> V_8 ) ;
F_7 ( & V_7 ) ;
F_2 (domain, hwirq, irq) {
V_4 = F_3 ( V_6 ) ;
V_4 -> V_2 = NULL ;
}
}
unsigned int F_10 ( struct V_10 * V_11 ,
const T_1 * V_12 , unsigned int V_13 )
{
struct V_1 * V_2 ;
unsigned long V_5 ;
unsigned int V_6 , type ;
int V_14 = - V_15 ;
F_5 ( & V_7 ) ;
F_11 (domain, &irq_domain_list, list) {
if ( ! V_2 -> V_16 -> V_17 )
continue;
V_14 = V_2 -> V_16 -> V_17 ( V_2 , V_11 ,
V_12 , V_13 , & V_5 , & type ) ;
if ( V_14 == 0 )
break;
}
F_7 ( & V_7 ) ;
if ( V_14 != 0 )
return 0 ;
V_6 = F_12 ( V_2 , V_5 ) ;
if ( type != V_18 )
F_13 ( V_6 , type ) ;
F_14 ( L_3 ,
V_11 -> V_19 , ( int ) V_5 , V_6 , type ) ;
return V_6 ;
}
void F_15 ( unsigned int V_6 )
{
}
int F_16 ( struct V_1 * V_4 ,
struct V_10 * V_11 ,
const T_1 * V_12 , unsigned int V_13 ,
unsigned long * V_20 , unsigned int * V_21 )
{
if ( V_4 -> V_22 != V_11 )
return - V_15 ;
if ( V_13 < 1 )
return - V_15 ;
if ( V_4 -> V_23 && ( ( V_12 [ 0 ] < V_4 -> V_24 ) ||
( V_12 [ 0 ] >= V_4 -> V_24 + V_4 -> V_23 ) ) )
return - V_15 ;
* V_20 = V_12 [ 0 ] ;
* V_21 = V_18 ;
if ( V_13 > 1 )
* V_21 = V_12 [ 1 ] & V_25 ;
return 0 ;
}
void F_17 ( struct V_10 * V_11 , int V_26 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 ) {
F_19 ( 1 ) ;
return;
}
V_2 -> V_26 = V_26 ;
V_2 -> V_22 = F_20 ( V_11 ) ;
V_2 -> V_16 = & V_28 ;
F_1 ( V_2 ) ;
}
void F_21 ( const struct V_29 * V_30 ,
T_2 V_31 , unsigned int V_32 )
{
struct V_10 * V_33 ;
F_22 ( L_4 ,
( unsigned long long ) V_31 , ( int ) V_32 ) ;
V_33 = F_23 ( NULL , V_30 , V_31 ) ;
if ( V_33 )
F_17 ( V_33 , V_32 ) ;
else
F_22 ( L_5 ) ;
}
