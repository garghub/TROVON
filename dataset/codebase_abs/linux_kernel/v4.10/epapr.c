static void F_1 ( void )
{
if ( ( V_1 != V_2 )
&& ( V_1 != V_3 ) )
F_2 ( L_1 ,
V_1 ) ;
if ( V_4 < ( unsigned long ) V_5 )
printf ( L_2
L_3 , V_5 , V_4 ) ;
if ( V_4 < V_6 )
printf ( L_4
L_5 , V_6 ,
V_4 ) ;
if ( V_4 < V_6 + F_3 ( ( void * ) V_6 ) )
printf ( L_6
L_7 ,
V_6 , F_3 ( ( void * ) V_6 ) , V_4 ) ;
}
void F_4 ( unsigned long V_7 , unsigned long V_8 , unsigned long V_9 ,
unsigned long V_10 , unsigned long V_11 )
{
V_1 = V_10 ;
V_4 = V_11 ;
V_6 = V_7 ;
F_5 ( V_5 , V_4 - ( unsigned long ) V_5 , 32 , 64 ) ;
F_6 ( ( void * ) V_6 ) ;
F_7 () ;
V_12 . V_13 = F_1 ;
}
