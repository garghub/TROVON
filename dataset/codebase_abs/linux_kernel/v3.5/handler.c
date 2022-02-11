unsigned int F_1 ( T_1 V_1 , unsigned long V_2 )
{
struct V_3 * V_4 ;
if ( ! V_5 ) {
F_2 ( L_1 ) ;
return - V_6 ;
}
F_3 ( & V_7 ) ;
V_4 = F_4 ( V_8 , V_9 ) ;
if ( ! V_4 ) {
F_2 ( L_2 ) ;
F_5 ( & V_7 ) ;
return - V_10 ;
}
V_4 -> V_11 = V_1 ;
V_4 -> V_12 = V_2 ;
F_6 ( & V_4 -> V_13 , & V_14 ) ;
F_5 ( & V_7 ) ;
F_7 ( & V_15 ) ;
return 0 ;
}
static void F_8 ( unsigned long V_16 )
{
struct V_3 * __volatile__ V_4 ;
struct V_17 * V_18 , * V_19 ;
F_3 ( & V_7 ) ;
F_9 (l, n, &signal_queue_head) {
V_4 = F_10 ( V_18 , struct V_3 , V_13 ) ;
F_11 ( & V_4 -> V_13 ) ;
F_5 ( & V_7 ) ;
V_4 -> V_11 ( V_4 -> V_12 ) ;
F_3 ( & V_7 ) ;
F_12 ( V_8 , V_4 ) ;
}
F_5 ( & V_7 ) ;
}
int F_13 ( void )
{
V_8 =
F_14 ( L_3 , sizeof( struct V_3 ) ,
0 , V_20 , NULL ) ;
if ( ! V_8 )
return - V_10 ;
F_15 ( & V_14 ) ;
F_16 ( & V_15 ) ;
V_5 = 1 ;
return 0 ;
}
void F_17 ( void )
{
struct V_17 * V_18 , * V_19 ;
struct V_3 * V_4 ;
if ( ! V_5 )
return;
V_5 = 0 ;
F_18 ( & V_15 ) ;
F_19 ( & V_15 ) ;
F_3 ( & V_7 ) ;
F_9 (l, n, &signal_queue_head) {
V_4 = F_10 ( V_18 , struct V_3 , V_13 ) ;
F_11 ( & V_4 -> V_13 ) ;
F_12 ( V_8 , V_4 ) ;
}
F_5 ( & V_7 ) ;
F_20 ( V_8 ) ;
}
