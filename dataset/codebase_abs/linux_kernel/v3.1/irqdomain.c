void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
V_4 = F_2 ( F_3 ( V_2 , V_5 ) ) ;
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
int V_5 ;
F_5 ( & V_7 ) ;
F_9 ( & V_2 -> V_8 ) ;
F_7 ( & V_7 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
V_4 = F_2 ( F_3 ( V_2 , V_5 ) ) ;
V_4 -> V_2 = NULL ;
}
}
unsigned int F_10 ( struct V_10 * V_11 ,
const T_1 * V_12 , unsigned int V_13 )
{
struct V_1 * V_2 ;
unsigned long V_5 ;
unsigned int V_14 , type ;
int V_15 = - V_16 ;
F_5 ( & V_7 ) ;
F_11 (domain, &irq_domain_list, list) {
if ( ! V_2 -> V_17 -> V_18 )
continue;
V_15 = V_2 -> V_17 -> V_18 ( V_2 , V_11 ,
V_12 , V_13 , & V_5 , & type ) ;
if ( V_15 == 0 )
break;
}
F_7 ( & V_7 ) ;
if ( V_15 != 0 )
return 0 ;
V_14 = F_3 ( V_2 , V_5 ) ;
if ( type != V_19 )
F_12 ( V_14 , type ) ;
F_13 ( L_3 ,
V_11 -> V_20 , ( int ) V_5 , V_14 , type ) ;
return V_14 ;
}
void F_14 ( unsigned int V_14 )
{
}
int F_15 ( struct V_1 * V_4 ,
struct V_10 * V_11 ,
const T_1 * V_12 , unsigned int V_13 ,
unsigned long * V_21 , unsigned int * V_22 )
{
if ( V_4 -> V_23 != V_11 )
return - V_16 ;
if ( V_13 < 1 )
return - V_16 ;
* V_21 = V_12 [ 0 ] ;
* V_22 = V_19 ;
if ( V_13 > 1 )
* V_22 = V_12 [ 1 ] & V_24 ;
return 0 ;
}
void F_16 ( struct V_10 * V_11 , int V_25 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 ) {
F_18 ( 1 ) ;
return;
}
V_2 -> V_25 = V_25 ;
V_2 -> V_23 = F_19 ( V_11 ) ;
V_2 -> V_17 = & V_27 ;
F_1 ( V_2 ) ;
}
void F_20 ( const struct V_28 * V_29 ,
T_2 V_30 , unsigned int V_31 )
{
struct V_10 * V_32 ;
F_21 ( L_4 ,
( unsigned long long ) V_30 , ( int ) V_31 ) ;
V_32 = F_22 ( NULL , V_29 , V_30 ) ;
if ( V_32 )
F_16 ( V_32 , V_31 ) ;
else
F_21 ( L_5 ) ;
}
