static int F_1 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 ,
T_3 * V_6 )
{
unsigned int V_7 ;
int V_8 ;
F_2 ( & V_9 ) ;
if ( ! V_10 ) {
F_3 ( & V_9 ) ;
return - V_11 ;
}
V_7 = V_12 ;
V_8 = F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( ! V_8 && V_3 && V_7 != V_12 ) {
V_13 = true ;
F_5 () ;
}
F_3 ( & V_9 ) ;
return V_8 ;
}
int F_6 ( void )
{
F_2 ( & V_9 ) ;
if ( V_10 ) {
F_3 ( & V_9 ) ;
return 0 ;
}
V_14 = F_7 ( V_15 ) ;
if ( ! V_14 ) {
F_3 ( & V_9 ) ;
return - V_16 ;
}
V_10 = true ;
V_12 = 1 ;
V_13 = true ;
F_5 () ;
F_3 ( & V_9 ) ;
return 0 ;
}
void F_8 ( void )
{
F_2 ( & V_9 ) ;
if ( ! V_10 ) {
F_3 ( & V_9 ) ;
return;
}
V_10 = false ;
if ( V_14 ) {
F_9 ( V_14 ) ;
V_14 = NULL ;
}
if ( V_12 ) {
V_12 = 0 ;
V_13 = true ;
F_5 () ;
}
F_3 ( & V_9 ) ;
}
int F_10 ( int V_17 )
{
return F_11 ( V_18 , V_17 ) ;
}
void F_12 ( int V_19 , int V_20 )
{
int V_17 , V_21 = 1 ;
F_13 (cpu, topology_sibling_cpumask(core_cpu)) {
int V_22 ;
V_22 = V_19 * V_23 / V_21 ;
F_11 ( V_18 , V_17 ) = V_22 ;
V_21 ++ ;
}
}
