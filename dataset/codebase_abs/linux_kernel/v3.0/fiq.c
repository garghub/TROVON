static int F_1 ( void * V_1 , int V_2 )
{
if ( ! V_2 )
F_2 ( & V_3 , sizeof( V_3 ) ) ;
return 0 ;
}
int F_3 ( struct V_4 * V_5 , int V_6 )
{
if ( V_7 != & V_8 )
F_4 ( V_5 , L_1 , V_6 , L_2 ,
V_7 -> V_9 ) ;
return 0 ;
}
void F_2 ( void * V_10 , unsigned int V_11 )
{
#if F_5 ( V_12 )
memcpy ( ( void * ) 0xffff001c , V_10 , V_11 ) ;
#else
memcpy ( V_13 + 0x1c , V_10 , V_11 ) ;
#endif
F_6 ( 0xffff001c , 0xffff001c + V_11 ) ;
if ( ! F_7 () )
F_6 ( 0x1c , 0x1c + V_11 ) ;
}
int F_8 ( struct V_14 * V_15 )
{
int V_16 = 0 ;
if ( V_7 ) {
V_16 = - V_17 ;
if ( V_7 -> V_18 != NULL )
V_16 = V_7 -> V_18 ( V_7 -> V_19 , 1 ) ;
}
if ( ! V_16 ) {
V_15 -> V_20 = V_7 ;
V_7 = V_15 ;
}
return V_16 ;
}
void F_9 ( struct V_14 * V_15 )
{
if ( V_7 != V_15 ) {
F_10 ( V_21 L_3 ,
V_15 -> V_9 , V_7 -> V_9 ) ;
F_11 () ;
return;
}
do
V_7 = V_7 -> V_20 ;
while ( V_7 -> V_18 ( V_7 -> V_19 , 0 ) );
}
void F_12 ( int V_22 )
{
F_13 ( V_22 + V_23 ) ;
}
void F_14 ( int V_22 )
{
F_15 ( V_22 + V_23 ) ;
}
void T_1 F_16 ( void )
{
V_3 = * ( unsigned long * ) 0xffff001c ;
}
