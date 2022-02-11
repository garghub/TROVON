static void F_1 ( unsigned int V_1 ,
unsigned int * V_2 , unsigned int * V_3 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_1 ) ;
* V_2 = F_3 ( V_4 , 0 ) ;
* V_3 = F_3 ( V_4 , 1 ) ;
}
static int F_4 ( unsigned int V_1 , struct V_5 * V_6 )
{
unsigned int V_2 , V_3 , V_7 ;
extern void V_8 ( void ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
F_5 ( L_1 ,
V_9 , V_1 , V_2 , V_3 ) ;
F_6 ( V_2 , V_3 , NULL ) ;
V_7 = F_7 ( V_2 , V_3 ) ;
if ( V_7 )
return V_7 ;
F_6 ( V_2 , V_3 , V_8 ) ;
F_8 ( F_9 ( V_1 ) ) ;
F_10 () ;
return 0 ;
}
static void F_11 ( unsigned int V_1 )
{
F_12 () ;
}
static int F_13 ( unsigned int V_1 )
{
unsigned int V_2 , V_3 ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
return ! F_14 ( V_2 , V_3 ) ;
}
static bool F_15 ( unsigned int V_1 )
{
return true ;
}
static void F_16 ( unsigned int V_1 )
{
unsigned int V_4 , V_2 , V_3 ;
V_4 = F_17 () ;
V_2 = F_3 ( V_4 , 0 ) ;
V_3 = F_3 ( V_4 , 1 ) ;
F_6 ( V_2 , V_3 , NULL ) ;
F_18 () ;
}
void T_1 F_19 ( void )
{
F_20 ( & V_10 ) ;
}
