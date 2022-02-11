void F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
if ( V_2 -> V_5 & V_6 )
F_2 () ;
}
static void F_3 ( void * V_7 , unsigned long V_8 )
{
unsigned long V_9 = ( unsigned long ) V_7 ;
if ( F_4 () ) {
F_5 ( V_7 , V_8 ) ;
F_2 () ;
} else {
F_6 ( V_9 , V_9 + V_8 ) ;
}
}
static void F_7 ( struct V_1 * V_2 , struct V_10 * V_10 ,
unsigned long V_11 , void * V_7 ,
unsigned long V_8 )
{
if ( V_2 -> V_5 & V_6 )
F_3 ( V_7 , V_8 ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_10 * V_10 ,
unsigned long V_11 , void * V_12 , const void * V_13 ,
unsigned long V_8 )
{
memcpy ( V_12 , V_13 , V_8 ) ;
F_7 ( V_2 , V_10 , V_11 , V_12 , V_8 ) ;
}
void F_9 ( T_1 V_14 , unsigned long V_9 )
{
struct V_10 * V_10 = F_10 ( V_14 ) ;
if ( ! F_11 ( V_10 ) )
return;
if ( ! F_12 ( V_15 , & V_10 -> V_16 ) )
F_3 ( F_13 ( V_10 ) ,
V_17 << F_14 ( V_10 ) ) ;
else if ( F_15 () )
F_2 () ;
}
void F_16 ( struct V_10 * V_10 )
{
if ( F_17 ( V_15 , & V_10 -> V_16 ) )
F_18 ( V_15 , & V_10 -> V_16 ) ;
}
