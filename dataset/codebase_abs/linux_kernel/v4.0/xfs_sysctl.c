STATIC int
F_1 (
struct V_1 * V_2 ,
int V_3 ,
void T_1 * V_4 ,
T_2 * V_5 ,
T_3 * V_6 )
{
int V_7 , V_8 , * V_9 = V_2 -> V_10 ;
T_4 V_11 ;
V_8 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( ! V_8 && V_3 && * V_9 ) {
F_3 ( NULL , L_1 ) ;
F_4 (c) {
F_5 () ;
V_11 = F_6 ( V_12 , V_7 ) . V_11 ;
memset ( & F_6 ( V_12 , V_7 ) , 0 ,
sizeof( struct V_12 ) ) ;
F_6 ( V_12 , V_7 ) . V_11 = V_11 ;
F_7 () ;
}
V_13 = 0 ;
}
return V_8 ;
}
STATIC int
F_8 (
struct V_1 * V_2 ,
int V_3 ,
void T_1 * V_4 ,
T_2 * V_5 ,
T_3 * V_6 )
{
int V_8 , * V_9 = V_2 -> V_10 ;
V_8 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( ! V_8 && V_3 ) {
V_14 = * V_9 ;
#ifdef F_9
V_14 |= ( V_15 | V_16 ) ;
#endif
}
return V_8 ;
}
int
F_10 ( void )
{
V_17 = F_11 ( V_18 ) ;
if ( ! V_17 )
return - V_19 ;
return 0 ;
}
void
F_12 ( void )
{
F_13 ( V_17 ) ;
}
