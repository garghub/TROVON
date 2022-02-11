static void F_1 ( void )
{
T_1 V_1 ;
void * V_2 ;
F_2 ( 0 , V_3 ) ;
F_3 ( V_4 ) ;
if ( ! F_4 ( V_4 , V_5 , & V_1 ) ) {
printf ( L_1 ) ;
return;
}
F_5 ( V_1 , 0xa8c000 ) ;
F_6 ( ( V_6 * ) 0xef600800 , NULL ) ;
F_7 ( L_2 ) ;
if ( ! F_4 ( V_4 , V_7 , & V_1 ) ) {
printf ( L_3 ) ;
return;
}
V_2 = F_8 ( L_4 ) ;
if ( V_2 != NULL ) {
V_6 V_8 [ 3 ] = { 4 , 0x200000 , 0 } ;
F_9 ( V_2 , L_5 , V_8 , 3 ) ;
V_8 [ 2 ] = ( V_1 << 10 ) & 0xffffffff ;
F_10 ( V_2 , L_5 , V_8 , 3 ) ;
}
}
void F_11 ( unsigned long V_9 , unsigned long V_10 , unsigned long V_11 ,
unsigned long V_12 , unsigned long V_13 )
{
V_4 = ( char * ) V_9 ;
F_12 ( V_4 ) ;
if ( ! F_4 ( V_4 , V_14 , & V_3 ) )
return;
V_3 *= 1024 * 1024 ;
F_13 ( V_15 , V_3 - ( unsigned long ) V_15 , 32 , 64 ) ;
F_14 ( V_16 ) ;
F_15 ( V_4 ) ;
F_16 () ;
V_17 . V_18 = F_1 ;
}
