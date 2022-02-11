static int F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
unsigned int V_4 , V_5 , V_6 , V_7 ;
extern void V_8 ( void ) ;
V_4 = F_2 ( V_1 ) ;
V_5 = F_3 ( V_4 , 0 ) ;
V_6 = F_3 ( V_4 , 1 ) ;
F_4 ( L_1 ,
V_9 , V_1 , V_5 , V_6 ) ;
F_5 ( V_5 , V_6 , NULL ) ;
V_7 = F_6 ( V_5 , V_6 ) ;
if ( V_7 )
return V_7 ;
F_5 ( V_5 , V_6 , V_8 ) ;
F_7 ( F_8 ( V_1 ) ) ;
F_9 () ;
return 0 ;
}
static void F_10 ( unsigned int V_1 )
{
F_11 () ;
}
static int F_12 ( unsigned int V_1 )
{
return 0 ;
}
static void F_13 ( unsigned int V_1 )
{
unsigned int V_4 , V_5 , V_6 ;
V_4 = F_14 () ;
V_5 = F_3 ( V_4 , 0 ) ;
V_6 = F_3 ( V_4 , 1 ) ;
F_5 ( V_5 , V_6 , NULL ) ;
F_15 () ;
}
void T_1 F_16 ( void )
{
F_17 ( & V_10 ) ;
}
