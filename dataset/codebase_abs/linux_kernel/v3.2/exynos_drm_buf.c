static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_1 , __FILE__ ) ;
V_4 -> V_5 = F_3 ( V_2 -> V_2 , V_4 -> V_6 ,
& V_4 -> V_7 , V_8 ) ;
if ( ! V_4 -> V_5 ) {
F_4 ( L_2 ) ;
return - V_9 ;
}
F_2 ( L_3 ,
( unsigned long ) V_4 -> V_5 ,
( unsigned long ) V_4 -> V_7 ,
V_4 -> V_6 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_4 , __FILE__ ) ;
if ( V_4 -> V_7 && V_4 -> V_6 )
F_6 ( V_2 -> V_2 , V_4 -> V_6 , V_4 -> V_5 ,
( V_10 ) V_4 -> V_7 ) ;
else
F_2 ( L_5 ) ;
}
struct V_3 * F_7 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
struct V_3 * V_4 ;
F_2 ( L_4 , __FILE__ ) ;
F_2 ( L_6 , V_6 ) ;
V_4 = F_8 ( sizeof( * V_4 ) , V_8 ) ;
if ( ! V_4 ) {
F_4 ( L_7 ) ;
return F_9 ( - V_9 ) ;
}
V_4 -> V_6 = V_6 ;
if ( F_1 ( V_2 , V_4 ) < 0 ) {
F_10 ( V_4 ) ;
V_4 = NULL ;
return F_9 ( - V_9 ) ;
}
return V_4 ;
}
void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_4 , __FILE__ ) ;
if ( ! V_4 ) {
F_2 ( L_8 ) ;
return;
}
F_5 ( V_2 , V_4 ) ;
F_10 ( V_4 ) ;
V_4 = NULL ;
}
