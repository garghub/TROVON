void F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
void * V_3 ;
V_2 = F_2 ( 2 ) ;
V_3 = F_3 ( V_1 ) ;
F_4 ( ( unsigned long ) V_3 , ( unsigned long ) V_3 + V_4 ) ;
F_5 ( V_3 ) ;
if ( V_2 ) {
F_6 ( 2 , V_2 ) ;
F_7 ( 2 , V_2 ) ;
}
}
void F_8 ( struct V_5 * V_6 , struct V_1 * V_1 ,
unsigned long V_7 , unsigned long V_8 )
{
unsigned long V_2 ;
void * V_3 ;
V_2 = F_2 ( 2 ) ;
V_3 = F_3 ( V_1 ) ;
V_7 = ( V_7 & ~ V_9 ) | ( unsigned long ) V_3 ;
F_9 ( V_7 , V_7 + V_8 ) ;
F_5 ( V_3 ) ;
if ( V_2 ) {
F_6 ( 2 , V_2 ) ;
F_7 ( 2 , V_2 ) ;
}
}
