void F_1 ( struct V_1 * V_2 )
{
extern const unsigned char V_3 [] ;
extern const unsigned int V_4 ;
unsigned long V_5 ;
unsigned long V_6 , V_7 ;
T_1 V_8 ;
F_2 () ;
F_3 () ;
V_5 = V_2 -> V_9 ;
V_6 =
( unsigned long ) F_4 ( V_2 -> V_10 ) ;
V_7 = F_5 ( ( void * ) V_6 ) ;
memcpy ( ( void * ) V_6 , V_3 ,
V_4 ) ;
F_6 ( V_6 ,
V_6 + V_11 ) ;
F_7 ( V_12 L_1 ) ;
V_8 = ( T_1 ) V_6 ;
(* V_8)( V_5 , V_7 , V_2 -> V_13 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
return 0 ;
}
