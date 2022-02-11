static void F_1 ( void )
{
void * V_1 ;
T_1 V_2 [ 3 ] ;
V_1 = F_2 ( L_1 ) ;
if ( ! V_1 )
F_3 ( L_2 ) ;
F_4 ( V_1 , L_3 , V_2 , sizeof( V_2 ) ) ;
if ( V_2 [ 2 ] )
V_3 = V_2 [ 1 ] ;
else
F_5 () ;
}
static void * F_6 ( unsigned long V_4 )
{
return ( void * ) V_3 ;
}
void F_7 ( void )
{
unsigned long V_5 = 0x08000000 ;
unsigned long V_6 = V_5 - ( unsigned long ) V_7 ;
T_1 V_8 ;
F_8 ( V_7 , V_6 , 128 , 64 ) ;
V_9 . V_10 = F_1 ;
V_9 . V_11 = F_6 ;
V_9 . exit = V_12 ;
V_8 = F_9 ( V_13 ) ;
F_10 ( V_14 , V_8 ) ;
F_11 ( V_14 ) ;
F_12 () ;
}
