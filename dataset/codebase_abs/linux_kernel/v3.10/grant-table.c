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
T_2 * * V_6 = ( T_2 * * ) V_5 ;
F_2 ( & V_7 , V_4 , V_1 , F_3 ( ( * V_6 ) [ 0 ] , V_8 ) ) ;
( * V_6 ) ++ ;
return 0 ;
}
static int F_5 ( T_1 * V_1 , struct V_2 * V_3 ,
unsigned long V_4 , void * V_5 )
{
F_2 ( & V_7 , V_4 , V_1 , F_6 ( 0 ) ) ;
return 0 ;
}
int F_7 ( unsigned long * V_6 , unsigned long V_9 ,
unsigned long V_10 ,
void * * V_11 )
{
int V_12 ;
void * V_13 = * V_11 ;
if ( V_13 == NULL ) {
struct V_14 * V_15 =
F_8 ( V_16 * V_10 , NULL ) ;
F_9 ( V_15 == NULL ) ;
V_13 = V_15 -> V_4 ;
* V_11 = V_13 ;
}
V_12 = F_10 ( & V_7 , ( unsigned long ) V_13 ,
V_16 * V_9 ,
F_1 , & V_6 ) ;
return V_12 ;
}
int F_11 ( T_2 * V_6 , unsigned long V_9 ,
unsigned long V_10 ,
T_3 * * V_11 )
{
int V_12 ;
T_3 * V_13 = * V_11 ;
if ( V_13 == NULL ) {
struct V_14 * V_15 =
F_8 ( V_16 * V_10 , NULL ) ;
F_9 ( V_15 == NULL ) ;
V_13 = V_15 -> V_4 ;
* V_11 = V_13 ;
}
V_12 = F_10 ( & V_7 , ( unsigned long ) V_13 ,
V_16 * V_9 ,
F_4 , & V_6 ) ;
return V_12 ;
}
void F_12 ( void * V_13 , unsigned long V_9 )
{
F_10 ( & V_7 , ( unsigned long ) V_13 ,
V_16 * V_9 , F_5 , NULL ) ;
}
