void F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 . V_9 == V_10 -> V_11 -> V_8 . V_9 )
F_2 ( ( void * ) V_3 , V_4 - V_3 ) ;
}
void F_3 ( unsigned long V_12 )
{
F_2 ( ( void * ) V_12 , V_13 ) ;
}
void F_4 ( void )
{
F_2 ( 0 , 0xffff0000 ) ;
}
void F_5 ( struct V_5 * V_6 )
{
if ( V_10 -> V_11 -> V_8 . V_9 == V_6 -> V_8 . V_9 )
F_4 () ;
}
void F_6 ( struct V_1 * V_2 , unsigned long V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 . V_9 == V_10 -> V_11 -> V_8 . V_9 )
F_2 ( ( void * ) V_12 , V_13 ) ;
}
void F_7 ( unsigned long V_3 , unsigned long V_4 )
{
F_2 ( ( void * ) V_3 , V_4 - V_3 ) ;
}
