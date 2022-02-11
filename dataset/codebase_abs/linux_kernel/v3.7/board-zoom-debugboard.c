static inline void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static inline void T_1 F_3 ( void )
{
int V_2 ;
unsigned long V_3 ;
int V_4 = 0 ;
if ( F_4 ( V_5 ,
V_6 ,
L_1 ) < 0 ) {
F_5 ( L_2 ,
V_5 ) ;
return;
}
V_2 = V_7 ;
if ( F_6 ( V_2 , V_8 , & V_3 ) < 0 ) {
F_5 ( L_3 ) ;
return;
}
V_4 = V_9 ;
if ( F_4 ( V_4 , V_10 , L_1 ) < 0 )
F_7 ( V_11 L_2 ,
V_4 ) ;
V_12 [ 0 ] . V_13 = F_8 ( 102 ) ;
}
static inline int F_9 ( void )
{
int V_14 = 0 ;
int V_15 = 1 ;
V_14 = V_16 ;
if ( F_4 ( V_14 , V_10 ,
L_4 ) < 0 ) {
F_5 ( L_5 ,
V_14 ) ;
return 0 ;
}
if ( ! F_10 ( V_14 ) ) {
V_15 = 0 ;
}
F_11 ( V_14 ) ;
return V_15 ;
}
int T_1 F_12 ( void )
{
if ( ! F_9 () )
return 0 ;
F_13 ( 0 , V_17 , F_14 ( V_17 ) ) ;
F_1 () ;
F_3 () ;
return F_15 ( V_18 , F_14 ( V_18 ) ) ;
}
