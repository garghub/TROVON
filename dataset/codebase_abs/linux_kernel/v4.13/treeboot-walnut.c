static void F_1 ( void )
{
void * V_1 , * V_2 ;
T_1 V_3 [ 3 ] = { 0x0 , 0x0 , 0x80000 } ;
T_1 V_4 [ 3 ] = { 0x0 , 0x0 , 0x80000 } ;
T_2 * V_5 ;
T_2 V_6 = 0x0 ;
V_1 = F_2 ( L_1 ) ;
if ( ! V_1 )
F_3 ( L_2 ) ;
if ( F_4 ( V_1 , L_3 , & V_5 , sizeof( V_5 ) ) != sizeof( V_5 ) )
F_3 ( L_4 ) ;
V_6 = F_5 ( V_5 ) ;
V_1 = F_2 ( L_5 ) ;
if ( ! V_1 )
F_3 ( L_6 ) ;
if ( F_4 ( V_1 , L_7 , V_3 , sizeof( V_3 ) ) != sizeof( V_3 ) )
F_3 ( L_8 ) ;
V_2 = F_2 ( L_9 ) ;
if ( ! V_2 )
F_3 ( L_10 ) ;
if ( F_4 ( V_2 , L_7 , V_4 , sizeof( V_4 ) ) != sizeof( V_4 ) )
F_3 ( L_11 ) ;
if ( V_6 & 0x1 ) {
V_3 [ 1 ] ^= 0x80000 ;
V_4 [ 1 ] ^= 0x80000 ;
}
F_6 ( V_1 , L_7 , V_3 , sizeof( V_3 ) ) ;
F_6 ( V_2 , L_7 , V_4 , sizeof( V_4 ) ) ;
}
static void F_7 ( void )
{
F_8 () ;
F_9 ( 33330000 , 0xa8c000 ) ;
F_10 ( ( T_1 * ) 0xef600800 , NULL ) ;
F_11 ( L_12 ) ;
F_1 () ;
F_12 ( L_13 , ( T_2 * ) V_7 ) ;
}
void F_13 ( void )
{
unsigned long V_8 = 0x2000000 ;
unsigned long V_9 = V_8 - ( unsigned long ) V_10 ;
F_14 ( V_10 , V_9 , 32 , 32 ) ;
V_11 . V_12 = F_7 ;
V_11 . exit = V_13 ;
F_15 ( V_14 ) ;
F_16 () ;
}
