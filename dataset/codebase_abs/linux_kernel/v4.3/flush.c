void F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
if ( V_2 -> V_5 & V_6 )
F_2 () ;
}
static void F_3 ( struct V_1 * V_2 , struct V_7 * V_7 ,
unsigned long V_8 , void * V_9 ,
unsigned long V_10 )
{
if ( V_2 -> V_5 & V_6 ) {
unsigned long V_11 = ( unsigned long ) V_9 ;
if ( F_4 () ) {
F_5 ( V_9 , V_10 ) ;
F_2 () ;
} else {
F_6 ( V_11 , V_11 + V_10 ) ;
}
}
}
void F_7 ( struct V_1 * V_2 , struct V_7 * V_7 ,
unsigned long V_8 , void * V_12 , const void * V_13 ,
unsigned long V_10 )
{
F_8 () ;
memcpy ( V_12 , V_13 , V_10 ) ;
F_3 ( V_2 , V_7 , V_8 , V_12 , V_10 ) ;
F_9 () ;
}
void F_10 ( T_1 V_14 , unsigned long V_11 )
{
struct V_7 * V_7 = F_11 ( V_14 ) ;
if ( ! F_12 ( V_7 ) )
return;
if ( ! F_13 ( V_15 , & V_7 -> V_16 ) ) {
F_5 ( F_14 ( V_7 ) ,
V_17 << F_15 ( V_7 ) ) ;
F_2 () ;
} else if ( F_16 () ) {
F_2 () ;
}
}
void F_17 ( struct V_7 * V_7 )
{
if ( F_18 ( V_15 , & V_7 -> V_16 ) )
F_19 ( V_15 , & V_7 -> V_16 ) ;
}
void F_20 ( struct V_1 * V_2 , unsigned long V_18 ,
T_2 * V_19 )
{
T_2 V_20 = F_21 ( * V_19 ) ;
F_22 ( V_18 & ~ V_21 ) ;
F_23 ( V_2 -> V_22 , V_18 , V_19 , V_20 ) ;
F_24 () ;
}
