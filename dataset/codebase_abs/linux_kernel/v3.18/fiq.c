static int F_1 ( void * V_1 , int V_2 )
{
if ( ! V_2 ) {
F_2 () ;
F_3 ( & V_3 ) ;
F_4 ( & V_4 , sizeof( V_4 ) ) ;
F_5 () ;
}
return 0 ;
}
int F_6 ( struct V_5 * V_6 , int V_7 )
{
if ( V_8 != & V_9 )
F_7 ( V_6 , L_1 , V_7 , L_2 ,
V_8 -> V_10 ) ;
return 0 ;
}
void F_4 ( void * V_11 , unsigned int V_12 )
{
void * V_13 = V_14 ;
unsigned V_15 = V_16 ;
memcpy ( V_13 + V_15 , V_11 , V_12 ) ;
if ( ! F_8 () )
F_9 ( ( unsigned long ) V_13 + V_15 , V_15 +
V_12 ) ;
F_9 ( 0xffff0000 + V_15 , 0xffff0000 + V_15 + V_12 ) ;
}
int F_10 ( struct V_17 * V_18 )
{
int V_19 = 0 ;
if ( V_8 ) {
V_19 = - V_20 ;
if ( V_8 -> V_21 != NULL )
V_19 = V_8 -> V_21 ( V_8 -> V_22 , 1 ) ;
}
if ( ! V_19 ) {
V_18 -> V_23 = V_8 ;
V_8 = V_18 ;
}
return V_19 ;
}
void F_11 ( struct V_17 * V_18 )
{
if ( V_8 != V_18 ) {
F_12 ( V_24 L_3 ,
V_18 -> V_10 , V_8 -> V_10 ) ;
F_13 () ;
return;
}
do
V_8 = V_8 -> V_23 ;
while ( V_8 -> V_21 ( V_8 -> V_22 , 0 ) );
}
void F_14 ( int V_25 )
{
F_15 ( V_25 + V_26 ) ;
}
void F_16 ( int V_25 )
{
F_17 ( V_25 + V_26 ) ;
}
void T_1 F_18 ( int V_11 )
{
unsigned V_15 = V_16 ;
V_4 = * ( unsigned long * ) ( 0xffff0000 + V_15 ) ;
F_19 ( & V_3 ) ;
V_26 = V_11 ;
}
