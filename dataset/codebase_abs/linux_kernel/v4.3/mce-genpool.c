void F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_5 ;
V_2 = F_2 ( & V_6 ) ;
if ( ! V_2 )
return;
V_2 = F_3 ( V_2 ) ;
F_4 (node, head, llnode) {
V_5 = & V_4 -> V_5 ;
F_5 ( & V_7 , 0 , V_5 ) ;
F_6 ( V_8 , ( unsigned long ) V_4 , sizeof( * V_4 ) ) ;
}
}
bool F_7 ( void )
{
return F_8 ( & V_6 ) ;
}
int F_9 ( struct V_5 * V_5 )
{
struct V_3 * V_4 ;
if ( ! V_8 )
return - V_9 ;
V_4 = ( void * ) F_10 ( V_8 , sizeof( * V_4 ) ) ;
if ( ! V_4 ) {
F_11 ( L_1 ) ;
return - V_10 ;
}
memcpy ( & V_4 -> V_5 , V_5 , sizeof( * V_5 ) ) ;
F_12 ( & V_4 -> V_11 , & V_6 ) ;
return 0 ;
}
static int F_13 ( void )
{
struct V_12 * V_13 ;
int V_14 = - V_10 ;
V_13 = F_14 ( F_15 ( sizeof( struct V_3 ) ) , - 1 ) ;
if ( ! V_13 )
goto V_15;
V_14 = F_16 ( V_13 , ( unsigned long ) V_16 , V_17 , - 1 ) ;
if ( V_14 ) {
F_17 ( V_13 ) ;
goto V_15;
}
V_8 = V_13 ;
V_15:
return V_14 ;
}
int F_18 ( void )
{
if ( V_8 )
return 0 ;
return F_13 () ;
}
