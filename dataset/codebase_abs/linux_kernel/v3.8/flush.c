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
#ifdef F_8
F_9 () ;
#endif
memcpy ( V_12 , V_13 , V_10 ) ;
F_3 ( V_2 , V_7 , V_8 , V_12 , V_10 ) ;
#ifdef F_8
F_10 () ;
#endif
}
void F_11 ( struct V_7 * V_7 )
{
F_5 ( F_12 ( V_7 ) , V_14 ) ;
}
void F_13 ( T_1 V_15 , unsigned long V_11 )
{
unsigned long V_16 ;
struct V_7 * V_7 ;
V_16 = F_14 ( V_15 ) ;
if ( ! F_15 ( V_16 ) )
return;
V_7 = F_16 ( V_16 ) ;
if ( ! F_17 ( V_17 , & V_7 -> V_18 ) ) {
F_11 ( V_7 ) ;
F_2 () ;
} else if ( F_18 () ) {
F_2 () ;
}
}
void F_19 ( struct V_7 * V_7 )
{
struct V_19 * V_20 ;
if ( V_7 == F_20 ( 0 ) )
return;
V_20 = F_21 ( V_7 ) ;
if ( V_20 && F_22 ( V_20 ) ) {
F_11 ( V_7 ) ;
F_2 () ;
F_23 ( V_17 , & V_7 -> V_18 ) ;
} else {
F_24 ( V_17 , & V_7 -> V_18 ) ;
}
}
