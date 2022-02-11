static void F_1 ( void )
{
void * V_1 ;
T_1 V_2 [ 3 ] = { 0x0 , 0x0 , 0x80000 } ;
T_2 * V_3 ;
T_2 V_4 = 0x0 ;
V_1 = F_2 ( V_5 ) ;
if ( ! V_1 )
F_3 ( L_1 , V_5 ) ;
if ( F_4 ( V_1 , L_2 , & V_3 , sizeof( V_3 ) ) != sizeof( V_3 ) )
F_3 ( L_3 ,
V_5 ) ;
V_4 = F_5 ( V_3 ) ;
V_1 = F_2 ( V_6 ) ;
if ( ! V_1 )
F_3 ( L_4 ,
V_6 ) ;
if ( F_4 ( V_1 , L_5 , V_2 , sizeof( V_2 ) ) != sizeof( V_2 ) )
F_3 ( L_6 ,
V_6 ) ;
if ( V_4 & V_7 )
V_2 [ 1 ] ^= 0x80000 ;
F_6 ( V_1 , L_5 , V_2 , sizeof( V_2 ) ) ;
}
static void F_7 ( void )
{
unsigned long V_8 = 33000000 ;
F_8 ( V_8 , 6 * 1843200 ) ;
F_9 () ;
F_10 ( L_7 , V_9 ) ;
F_10 ( L_8 , V_10 ) ;
F_11 ( L_9 ) ;
F_1 () ;
}
void F_12 ( void * V_11 , void * V_12 )
{
V_13 . V_14 = F_7 ;
V_13 . exit = V_15 ;
V_9 = V_11 ;
V_10 = V_12 ;
F_13 ( V_16 ) ;
F_14 () ;
}
