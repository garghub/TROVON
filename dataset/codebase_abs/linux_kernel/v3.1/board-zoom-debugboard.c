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
F_7 ( V_9 L_3
L_4 ) ;
return;
}
V_4 = V_10 ;
if ( F_4 ( V_4 , V_11 , L_1 ) < 0 )
F_7 ( V_9 L_2 ,
V_4 ) ;
}
static inline int F_8 ( void )
{
int V_12 = 0 ;
int V_13 = 1 ;
V_12 = V_14 ;
if ( F_4 ( V_12 , V_11 ,
L_5 ) < 0 ) {
F_7 ( V_9 L_6
L_7 , V_12 ) ;
return 0 ;
}
if ( ! F_9 ( V_12 ) ) {
V_13 = 0 ;
}
F_10 ( V_12 ) ;
return V_13 ;
}
int T_1 F_11 ( void )
{
if ( ! F_8 () )
return 0 ;
F_1 () ;
F_3 () ;
return F_12 ( V_15 , F_13 ( V_15 ) ) ;
}
