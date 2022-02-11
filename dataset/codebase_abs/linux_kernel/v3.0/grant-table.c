static int F_1 ( T_1 * V_1 , struct V_2 * V_3 ,
unsigned long V_4 , void * V_5 )
{
unsigned long * * V_6 = ( unsigned long * * ) V_5 ;
F_2 ( & V_7 , V_4 , V_1 , F_3 ( ( * V_6 ) [ 0 ] , V_8 ) ) ;
( * V_6 ) ++ ;
return 0 ;
}
static int F_4 ( T_1 * V_1 , struct V_2 * V_3 ,
unsigned long V_4 , void * V_5 )
{
F_2 ( & V_7 , V_4 , V_1 , F_5 ( 0 ) ) ;
return 0 ;
}
int F_6 ( unsigned long * V_6 , unsigned long V_9 ,
unsigned long V_10 ,
struct V_11 * * V_12 )
{
int V_13 ;
struct V_11 * V_14 = * V_12 ;
if ( V_14 == NULL ) {
struct V_15 * V_16 =
F_7 ( V_17 * V_10 ) ;
F_8 ( V_16 == NULL ) ;
V_14 = V_16 -> V_4 ;
* V_12 = V_14 ;
}
V_13 = F_9 ( & V_7 , ( unsigned long ) V_14 ,
V_17 * V_9 ,
F_1 , & V_6 ) ;
return V_13 ;
}
void F_10 ( struct V_11 * V_14 ,
unsigned long V_9 )
{
F_9 ( & V_7 , ( unsigned long ) V_14 ,
V_17 * V_9 , F_4 , NULL ) ;
}
