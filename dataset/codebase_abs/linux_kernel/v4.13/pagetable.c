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
void F_4 ( void )
{
V_9 . F_1 = F_1 ;
V_9 . V_1 = & V_10 ;
V_10 . V_5 = 0 ;
V_11 = F_5 () ;
if ( F_6 ( ( V_12 * ) V_11 , 0 ) == ( V_13 * ) V_14 ) {
F_2 ( L_3 ) ;
V_10 . V_7 = V_14 + V_15 ;
V_10 . V_6 = V_16 - V_15 ;
memset ( V_10 . V_7 , 0 , V_10 . V_6 ) ;
} else {
F_2 ( L_4 ) ;
V_10 . V_7 = V_14 ;
V_10 . V_6 = V_16 ;
memset ( V_10 . V_7 , 0 , V_10 . V_6 ) ;
V_11 = ( unsigned long ) F_1 ( & V_10 ) ;
}
}
void F_7 ( unsigned long V_17 , unsigned long V_18 )
{
unsigned long V_19 = V_17 + V_18 ;
V_17 = F_8 ( V_17 , V_20 ) ;
V_19 = F_9 ( V_19 , V_20 ) ;
if ( V_17 >= V_19 )
return;
F_10 ( & V_9 , ( V_12 * ) V_11 ,
V_17 , V_19 ) ;
}
void F_11 ( void )
{
F_12 ( V_11 ) ;
}
