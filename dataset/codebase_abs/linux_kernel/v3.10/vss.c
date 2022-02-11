static inline void F_1 ( int V_1 )
{
void T_1 * V_2 = ( void T_1 * ) F_2 ( V_1 ) ;
F_3 ( 3 , V_2 + V_3 ) ;
F_4 () ;
F_3 ( 0x01fffffe , V_2 + V_4 ) ;
F_4 () ;
F_3 ( 0x01 , V_2 + V_5 ) ;
F_4 () ;
F_3 ( 0x03 , V_2 + V_5 ) ;
F_4 () ;
F_3 ( 0x07 , V_2 + V_5 ) ;
F_4 () ;
F_3 ( 0x0f , V_2 + V_5 ) ;
F_4 () ;
F_3 ( 0x01ffffff , V_2 + V_4 ) ;
F_4 () ;
F_3 ( 2 , V_2 + V_3 ) ;
F_4 () ;
F_3 ( 0x1f , V_2 + V_5 ) ;
F_4 () ;
}
static inline void F_5 ( int V_1 )
{
void T_1 * V_2 = ( void T_1 * ) F_2 ( V_1 ) ;
F_3 ( 0x0f , V_2 + V_5 ) ;
F_4 () ;
F_3 ( 0 , V_2 + V_4 ) ;
F_4 () ;
F_3 ( 3 , V_2 + V_3 ) ;
F_4 () ;
F_3 ( 1 , V_2 + V_3 ) ;
F_4 () ;
F_3 ( 0 , V_2 + V_5 ) ;
F_4 () ;
}
void F_6 ( int V_1 , int V_6 )
{
unsigned long V_7 ;
if ( F_7 () != V_8 )
return;
F_8 ( & V_9 , V_7 ) ;
if ( V_6 )
F_1 ( V_1 ) ;
else
F_5 ( V_1 ) ;
F_9 ( & V_9 , V_7 ) ;
}
