void F_1 ( void * V_1 , unsigned long V_2 )
{
unsigned long V_3 = ( unsigned long ) V_1 ;
if ( F_2 () ) {
F_3 ( V_1 , V_2 ) ;
F_4 () ;
} else {
F_5 ( V_3 , V_3 + V_2 ) ;
}
}
static void F_6 ( struct V_4 * V_5 , struct V_6 * V_6 ,
unsigned long V_7 , void * V_1 ,
unsigned long V_2 )
{
if ( V_5 -> V_8 & V_9 )
F_1 ( V_1 , V_2 ) ;
}
void F_7 ( struct V_4 * V_5 , struct V_6 * V_6 ,
unsigned long V_7 , void * V_10 , const void * V_11 ,
unsigned long V_2 )
{
memcpy ( V_10 , V_11 , V_2 ) ;
F_6 ( V_5 , V_6 , V_7 , V_10 , V_2 ) ;
}
void F_8 ( T_1 V_12 , unsigned long V_3 )
{
struct V_6 * V_6 = F_9 ( V_12 ) ;
if ( ! F_10 ( V_13 , & V_6 -> V_14 ) )
F_1 ( F_11 ( V_6 ) ,
V_15 << F_12 ( V_6 ) ) ;
}
void F_13 ( struct V_6 * V_6 )
{
if ( F_14 ( V_13 , & V_6 -> V_14 ) )
F_15 ( V_13 , & V_6 -> V_14 ) ;
}
