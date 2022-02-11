static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( * (struct V_4 * * ) V_3 ) ;
}
struct V_4 * F_3 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_4 * * V_6 , * V_4 ;
V_6 = F_4 ( F_1 , sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return F_5 ( - V_8 ) ;
V_4 = F_6 ( V_2 , V_5 ) ;
if ( ! F_7 ( V_4 ) ) {
* V_6 = V_4 ;
F_8 ( V_2 , V_6 ) ;
} else {
F_9 ( V_6 ) ;
}
return V_4 ;
}
static int F_10 ( struct V_1 * V_2 , void * V_3 , void * V_9 )
{
struct V_4 * * V_10 = V_3 ;
if ( ! V_10 || ! * V_10 ) {
F_11 ( ! V_10 || ! * V_10 ) ;
return 0 ;
}
return * V_10 == V_9 ;
}
void F_12 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
int V_11 ;
V_11 = F_13 ( V_2 , F_1 , F_10 , V_4 ) ;
F_11 ( V_11 ) ;
}
