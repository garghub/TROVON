void F_1 ( struct V_1 * V_2 )
{
}
void F_2 ( struct V_3 * V_4 , unsigned long V_5 ,
unsigned long V_6 )
{
if ( V_4 -> V_7 & V_8 )
F_3 () ;
}
void F_4 ( struct V_3 * V_4 , unsigned long V_9 ,
unsigned long V_10 )
{
}
static void F_5 ( struct V_3 * V_4 , struct V_11 * V_11 ,
unsigned long V_12 , void * V_13 ,
unsigned long V_14 )
{
if ( V_4 -> V_7 & V_8 ) {
unsigned long V_15 = ( unsigned long ) V_13 ;
if ( F_6 () ) {
F_7 ( V_13 , V_14 ) ;
F_3 () ;
} else {
F_8 ( V_15 , V_15 + V_14 ) ;
}
}
}
void F_9 ( struct V_3 * V_4 , struct V_11 * V_11 ,
unsigned long V_12 , void * V_16 , const void * V_17 ,
unsigned long V_14 )
{
#ifdef F_10
F_11 () ;
#endif
memcpy ( V_16 , V_17 , V_14 ) ;
F_5 ( V_4 , V_11 , V_12 , V_16 , V_14 ) ;
#ifdef F_10
F_12 () ;
#endif
}
void F_13 ( struct V_11 * V_11 )
{
F_7 ( F_14 ( V_11 ) , V_18 ) ;
}
void F_15 ( T_1 V_19 , unsigned long V_15 )
{
unsigned long V_10 ;
struct V_11 * V_11 ;
V_10 = F_16 ( V_19 ) ;
if ( ! F_17 ( V_10 ) )
return;
V_11 = F_18 ( V_10 ) ;
if ( ! F_19 ( V_20 , & V_11 -> V_21 ) ) {
F_13 ( V_11 ) ;
F_3 () ;
} else if ( F_20 () ) {
F_3 () ;
}
}
void F_21 ( struct V_11 * V_11 )
{
struct V_22 * V_23 ;
if ( V_11 == F_22 ( 0 ) )
return;
V_23 = F_23 ( V_11 ) ;
if ( V_23 && F_24 ( V_23 ) ) {
F_13 ( V_11 ) ;
F_3 () ;
F_25 ( V_20 , & V_11 -> V_21 ) ;
} else {
F_26 ( V_20 , & V_11 -> V_21 ) ;
}
}
