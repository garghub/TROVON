void F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_6 ;
V_2 = F_2 ( & V_7 ) ;
if ( ! V_2 )
return;
V_2 = F_3 ( V_2 ) ;
F_4 (node, tmp, head, llnode) {
V_6 = & V_4 -> V_6 ;
F_5 ( & V_8 , 0 , V_6 ) ;
F_6 ( V_9 , ( unsigned long ) V_4 , sizeof( * V_4 ) ) ;
}
}
bool F_7 ( void )
{
return F_8 ( & V_7 ) ;
}
int F_9 ( struct V_6 * V_6 )
{
struct V_3 * V_4 ;
if ( ! V_9 )
return - V_10 ;
V_4 = ( void * ) F_10 ( V_9 , sizeof( * V_4 ) ) ;
if ( ! V_4 ) {
F_11 ( L_1 ) ;
return - V_11 ;
}
memcpy ( & V_4 -> V_6 , V_6 , sizeof( * V_6 ) ) ;
F_12 ( & V_4 -> V_12 , & V_7 ) ;
return 0 ;
}
static int F_13 ( void )
{
struct V_13 * V_14 ;
int V_15 = - V_11 ;
V_14 = F_14 ( F_15 ( sizeof( struct V_3 ) ) , - 1 ) ;
if ( ! V_14 )
goto V_16;
V_15 = F_16 ( V_14 , ( unsigned long ) V_17 , V_18 , - 1 ) ;
if ( V_15 ) {
F_17 ( V_14 ) ;
goto V_16;
}
V_9 = V_14 ;
V_16:
return V_15 ;
}
int F_18 ( void )
{
if ( V_9 )
return 0 ;
return F_13 () ;
}
