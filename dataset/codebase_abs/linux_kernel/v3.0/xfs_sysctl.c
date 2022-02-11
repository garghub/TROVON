STATIC int
F_1 (
T_1 * V_1 ,
int V_2 ,
void T_2 * V_3 ,
T_3 * V_4 ,
T_4 * V_5 )
{
int V_6 , V_7 , * V_8 = V_1 -> V_9 ;
T_5 V_10 ;
V_7 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
if ( ! V_7 && V_2 && * V_8 ) {
F_3 ( NULL , L_1 ) ;
F_4 (c) {
F_5 () ;
V_10 = F_6 ( V_11 , V_6 ) . V_10 ;
memset ( & F_6 ( V_11 , V_6 ) , 0 ,
sizeof( struct V_11 ) ) ;
F_6 ( V_11 , V_6 ) . V_10 = V_10 ;
F_7 () ;
}
V_12 = 0 ;
}
return V_7 ;
}
STATIC int
F_8 (
T_1 * V_1 ,
int V_2 ,
void T_2 * V_3 ,
T_3 * V_4 ,
T_4 * V_5 )
{
int V_7 , * V_8 = V_1 -> V_9 ;
V_7 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
if ( ! V_7 && V_2 ) {
V_13 = * V_8 ;
#ifdef F_9
V_13 |= ( V_14 | V_15 ) ;
#endif
}
return V_7 ;
}
int
F_10 ( void )
{
V_16 = F_11 ( V_17 ) ;
if ( ! V_16 )
return - V_18 ;
return 0 ;
}
void
F_12 ( void )
{
F_13 ( V_16 ) ;
}
