static inline void F_1 ( int V_1 , int V_2 )
{
F_2 ( V_1 , V_3 + V_2 ) ;
}
static inline void F_3 ( unsigned long V_4 )
{
if ( ! V_4 )
V_4 = 1 ;
F_1 ( V_4 , V_5 ) ;
F_1 ( 0x0f , V_6 ) ;
}
static inline void F_4 ( void )
{
F_1 ( 0x0 , V_6 ) ;
}
static int F_5 ( unsigned long V_7 ,
struct V_8 * V_9 )
{
F_3 ( V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_8 * V_10 )
{
F_4 () ;
return 0 ;
}
static int F_7 ( struct V_8 * V_10 )
{
F_4 () ;
F_3 ( V_11 ) ;
return 0 ;
}
static T_1 F_8 ( int V_12 , void * V_13 )
{
struct V_8 * V_10 = & V_14 ;
F_9 () ;
V_10 -> V_15 ( V_10 ) ;
return V_16 ;
}
static T_2 void F_10 ( void )
{
F_11 ( V_17 , & V_18 ) ;
V_14 . V_19 = F_12 ( 0 ) ;
F_13 ( & V_14 ,
V_20 , 1 , 0xfffffffe ) ;
}
int T_2 F_14 ( void )
{
int V_21 = - V_22 ;
if ( F_15 () ) {
void T_3 * V_23 ;
struct V_24 * V_25 ;
V_23 = F_16 ( V_26 , V_27 ) ;
if ( ! V_23 ) {
F_17 ( L_1 ) ;
return - V_22 ;
}
V_25 = F_18 ( NULL , L_2 ) ;
if ( ! F_19 ( V_25 ) )
F_20 ( V_25 ) ;
V_21 = F_21 ( V_23 ) ;
}
if ( ! V_21 )
F_10 () ;
return V_21 ;
}
