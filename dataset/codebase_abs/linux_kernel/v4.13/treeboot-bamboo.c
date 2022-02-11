static void F_1 ( void )
{
unsigned long long V_1 ;
V_1 = F_2 ( ( char * ) V_2 , 0 , 16 ) ;
memcpy ( & V_3 , ( char * ) & V_1 + 2 , 6 ) ;
V_1 = F_2 ( ( char * ) V_4 , 0 , 16 ) ;
memcpy ( & V_5 , ( char * ) & V_1 + 2 , 6 ) ;
}
void F_3 ( void )
{
unsigned long V_6 = 0x8000000 ;
unsigned long V_7 = V_6 - ( unsigned long ) V_8 ;
F_4 ( V_8 , V_7 , 32 , 64 ) ;
F_1 () ;
F_5 ( ( V_9 * ) & V_3 , ( V_9 * ) & V_5 ) ;
}
