static void * F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
unsigned char * V_4 ;
if ( V_3 -> V_5 >= V_3 -> V_6 ) {
F_2 ( L_1 __FILE__ L_2 ) ;
F_3 ( V_3 -> V_5 ) ;
F_3 ( V_3 -> V_6 ) ;
return NULL ;
}
V_4 = V_3 -> V_7 + V_3 -> V_5 ;
V_3 -> V_5 += V_8 ;
return V_4 ;
}
static void F_4 ( void )
{
V_9 . V_5 = 0 ;
V_10 = F_5 () ;
if ( V_10 == ( unsigned long ) V_11 ) {
F_2 ( L_3 ) ;
V_9 . V_7 = V_11 + V_12 ;
V_9 . V_6 = V_13 - V_12 ;
memset ( V_9 . V_7 , 0 , V_9 . V_6 ) ;
} else {
F_2 ( L_4 ) ;
V_9 . V_7 = V_11 ;
V_9 . V_6 = V_13 ;
memset ( V_9 . V_7 , 0 , V_9 . V_6 ) ;
V_10 = ( unsigned long ) F_1 ( & V_9 ) ;
}
}
void F_6 ( unsigned long V_14 , unsigned long V_15 )
{
struct V_16 V_17 = {
. F_1 = F_1 ,
. V_1 = & V_9 ,
. V_18 = V_19 ,
} ;
unsigned long V_20 = V_14 + V_15 ;
if ( ! V_10 )
F_4 () ;
V_14 = F_7 ( V_14 , V_21 ) ;
V_20 = F_8 ( V_20 , V_21 ) ;
if ( V_14 >= V_20 )
return;
F_9 ( & V_17 , ( V_22 * ) V_10 ,
V_14 , V_20 ) ;
}
void F_10 ( void )
{
F_11 ( V_10 ) ;
}
