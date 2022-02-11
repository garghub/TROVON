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
void * V_12 = V_13 ;
unsigned V_14 = V_15 ;
memcpy ( V_12 + V_14 , V_10 , V_11 ) ;
if ( ! F_5 () )
F_6 ( ( unsigned long ) V_12 + V_14 , V_14 +
V_11 ) ;
F_6 ( 0xffff0000 + V_14 , 0xffff0000 + V_14 + V_11 ) ;
}
int F_7 ( struct V_16 * V_17 )
{
int V_18 = 0 ;
if ( V_7 ) {
V_18 = - V_19 ;
if ( V_7 -> V_20 != NULL )
V_18 = V_7 -> V_20 ( V_7 -> V_21 , 1 ) ;
}
if ( ! V_18 ) {
V_17 -> V_22 = V_7 ;
V_7 = V_17 ;
}
return V_18 ;
}
void F_8 ( struct V_16 * V_17 )
{
if ( V_7 != V_17 ) {
F_9 ( V_23 L_3 ,
V_17 -> V_9 , V_7 -> V_9 ) ;
F_10 () ;
return;
}
do
V_7 = V_7 -> V_22 ;
while ( V_7 -> V_20 ( V_7 -> V_21 , 0 ) );
}
void F_11 ( int V_24 )
{
F_12 ( V_24 + V_25 ) ;
}
void F_13 ( int V_24 )
{
F_14 ( V_24 + V_25 ) ;
}
void T_1 F_15 ( int V_10 )
{
unsigned V_14 = V_15 ;
V_3 = * ( unsigned long * ) ( 0xffff0000 + V_14 ) ;
V_25 = V_10 ;
}
