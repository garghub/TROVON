static void F_1 ( void )
{
void * V_1 , * V_2 ;
int div ;
T_1 V_3 ;
F_2 ( V_4 . V_5 , V_4 . V_6 ) ;
F_3 ( V_4 . V_7 ) ;
F_4 ( V_4 . V_8 , V_4 . V_9 / 4 , V_4 . V_9 ) ;
V_1 = F_5 ( NULL , L_1 ) ;
if ( ! V_1 )
V_1 = F_6 ( NULL , L_2 ) ;
if ( ! V_1 )
V_1 = F_6 ( NULL , L_3 ) ;
if ( V_1 ) {
F_7 ( V_1 , L_4 , & V_4 . V_10 ,
sizeof( V_4 . V_10 ) ) ;
if ( ! F_8 ( V_1 , 0 , ( void * ) & V_2 , NULL ) )
return;
div = F_9 ( V_2 + 0x204 ) & 0x0020 ? 8 : 4 ;
V_3 = V_4 . V_9 * div ;
F_7 ( V_1 , L_5 , & V_3 , sizeof( V_3 ) ) ;
}
}
void F_10 ( unsigned long V_11 , unsigned long V_12 , unsigned long V_13 ,
unsigned long V_14 , unsigned long V_15 )
{
F_11 () ;
F_12 ( V_16 ) ;
F_13 () ;
V_17 . V_18 = F_1 ;
}
