static T_1 F_1 ( int V_1 , void * V_2 )
{
unsigned int V_3 = F_2 ( ( void V_4 * ) V_2 ) ;
F_3 ( F_4 ( V_3 ) ) ;
return V_5 ;
}
static int F_5 ( struct V_6 * V_7 , unsigned int V_8 )
{
return 0 ;
}
static void F_6 ( void V_4 * V_9 , void V_4 * V_10 , int V_11 )
{
unsigned long V_12 = F_2 ( V_9 ) & F_2 ( V_10 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 32 ; V_13 ++ ) {
if ( V_12 & ( 1 << ( 31 - V_13 ) ) ) {
F_3 ( V_11 + V_13 ) ;
F_7 ( ~ ( 1 << ( 31 - V_13 ) ) , V_9 ) ;
}
}
}
static T_1 F_8 ( int V_1 , void * V_2 )
{
F_6 ( V_14 , V_15 , F_9 ( 0 ) ) ;
return V_5 ;
}
static T_1 F_10 ( int V_1 , void * V_2 )
{
F_6 ( V_16 , V_17 , F_11 ( 0 ) ) ;
return V_5 ;
}
void T_2 F_12 ( void )
{
void V_4 * V_18 = F_13 ( 0xf0001000 ) ;
void V_4 * V_19 = F_13 ( 0xf0000100 ) ;
void V_4 * V_20 = F_14 ( 0xffd20100 , V_21 ) ;
F_15 ( 0 , 29 , V_18 , V_19 ) ;
V_22 . V_23 = F_5 ;
F_16 ( & V_24 ) ;
F_16 ( & V_25 ) ;
F_16 ( & V_26 ) ;
V_27 . V_28 = L_1 ;
V_27 . V_29 = F_1 ;
V_27 . V_2 = V_20 ;
F_17 ( F_18 ( 50 ) , & V_27 ) ;
V_30 . V_28 = L_2 ;
V_30 . V_29 = F_8 ;
F_17 ( F_18 ( 33 ) , & V_30 ) ;
V_31 . V_28 = L_3 ;
V_31 . V_29 = F_10 ;
F_17 ( F_18 ( 34 ) , & V_31 ) ;
}
