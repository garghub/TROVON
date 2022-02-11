static inline void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static inline void T_1 F_3 ( void )
{
int V_2 ;
unsigned long V_3 ;
int V_4 = 0 ;
V_2 = V_5 ;
if ( F_4 ( V_2 , V_6 , & V_3 ) < 0 ) {
F_5 ( V_7 L_1
L_2 ) ;
return;
}
V_4 = V_8 ;
if ( F_6 ( V_4 , V_9 , L_3 ) < 0 )
F_5 ( V_7 L_4 ,
V_4 ) ;
}
static inline int F_7 ( void )
{
int V_10 = 0 ;
int V_11 = 1 ;
V_10 = V_12 ;
if ( F_6 ( V_10 , V_9 ,
L_5 ) < 0 ) {
F_5 ( V_7 L_6
L_7 , V_10 ) ;
return 0 ;
}
if ( ! F_8 ( V_10 ) ) {
V_11 = 0 ;
}
F_9 ( V_10 ) ;
return V_11 ;
}
int T_1 F_10 ( void )
{
if ( ! F_7 () )
return 0 ;
F_1 () ;
F_3 () ;
return F_11 ( V_13 , F_12 ( V_13 ) ) ;
}
