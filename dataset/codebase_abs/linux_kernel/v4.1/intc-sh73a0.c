static T_1 F_1 ( int V_1 , void * V_2 )
{
unsigned int V_3 = F_2 ( ( void V_4 * ) V_2 ) ;
F_3 ( F_4 ( V_3 ) ) ;
return V_5 ;
}
static void F_5 ( void V_4 * V_6 , void V_4 * V_7 , int V_8 )
{
unsigned long V_9 = F_2 ( V_6 ) & F_2 ( V_7 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < 32 ; V_10 ++ ) {
if ( V_9 & ( 1 << ( 31 - V_10 ) ) ) {
F_3 ( V_8 + V_10 ) ;
F_6 ( ~ ( 1 << ( 31 - V_10 ) ) , V_6 ) ;
}
}
}
static T_1 F_7 ( int V_1 , void * V_2 )
{
F_5 ( V_11 , V_12 , F_8 ( 0 ) ) ;
return V_5 ;
}
static T_1 F_9 ( int V_1 , void * V_2 )
{
F_5 ( V_13 , V_14 , F_10 ( 0 ) ) ;
return V_5 ;
}
void T_2 F_11 ( void )
{
void V_4 * V_15 = F_12 ( 0xf0001000 ) ;
void V_4 * V_16 = F_12 ( 0xf0000100 ) ;
void V_4 * V_17 = F_13 ( 0xffd20100 , V_18 ) ;
F_14 ( V_19 ) ;
F_15 ( 0 , 29 , V_15 , V_16 ) ;
F_16 ( & V_20 ) ;
F_16 ( & V_21 ) ;
F_16 ( & V_22 ) ;
V_23 . V_24 = L_1 ;
V_23 . V_25 = F_1 ;
V_23 . V_2 = V_17 ;
F_17 ( F_18 ( 50 ) , & V_23 ) ;
V_26 . V_24 = L_2 ;
V_26 . V_25 = F_7 ;
F_17 ( F_18 ( 33 ) , & V_26 ) ;
V_27 . V_24 = L_3 ;
V_27 . V_25 = F_9 ;
F_17 ( F_18 ( 34 ) , & V_27 ) ;
}
