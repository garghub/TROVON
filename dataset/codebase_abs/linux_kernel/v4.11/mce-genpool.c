static bool F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 , * V_7 ;
V_6 = & V_2 -> V_5 ;
F_2 (node, &l->llnode, llnode) {
V_7 = & V_4 -> V_5 ;
if ( ! F_3 ( V_6 , V_7 ) )
return true ;
}
return false ;
}
struct V_8 * F_4 ( void )
{
struct V_8 * V_9 ;
F_5 ( V_10 ) ;
struct V_1 * V_4 , * V_2 ;
V_9 = F_6 ( & V_11 ) ;
if ( ! V_9 )
return NULL ;
F_7 (node, t, head, llnode) {
if ( ! F_1 ( V_4 , V_2 ) )
F_8 ( & V_4 -> V_12 , & V_10 ) ;
}
return V_10 . V_13 ;
}
void F_9 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
struct V_1 * V_4 , * V_16 ;
struct V_5 * V_5 ;
V_9 = F_6 ( & V_11 ) ;
if ( ! V_9 )
return;
V_9 = F_10 ( V_9 ) ;
F_7 (node, tmp, head, llnode) {
V_5 = & V_4 -> V_5 ;
F_11 ( & V_17 , 0 , V_5 ) ;
F_12 ( V_18 , ( unsigned long ) V_4 , sizeof( * V_4 ) ) ;
}
}
bool F_13 ( void )
{
return F_14 ( & V_11 ) ;
}
int F_15 ( struct V_5 * V_5 )
{
struct V_1 * V_4 ;
if ( ! V_18 )
return - V_19 ;
V_4 = ( void * ) F_16 ( V_18 , sizeof( * V_4 ) ) ;
if ( ! V_4 ) {
F_17 ( L_1 ) ;
return - V_20 ;
}
memcpy ( & V_4 -> V_5 , V_5 , sizeof( * V_5 ) ) ;
F_8 ( & V_4 -> V_12 , & V_11 ) ;
return 0 ;
}
static int F_18 ( void )
{
struct V_21 * V_22 ;
int V_23 = - V_20 ;
V_22 = F_19 ( F_20 ( sizeof( struct V_1 ) ) , - 1 ) ;
if ( ! V_22 )
goto V_24;
V_23 = F_21 ( V_22 , ( unsigned long ) V_25 , V_26 , - 1 ) ;
if ( V_23 ) {
F_22 ( V_22 ) ;
goto V_24;
}
V_18 = V_22 ;
V_24:
return V_23 ;
}
int F_23 ( void )
{
if ( V_18 )
return 0 ;
return F_18 () ;
}
