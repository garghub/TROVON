static int F_1 ( unsigned int V_1 ,
struct V_2 * V_3 )
{
unsigned long V_4 = F_2 ( & V_5 ) ;
int error ;
F_3 ( L_1 ,
V_1 , V_4 ) ;
error = F_4 ( V_6 , V_1 , V_4 ) ;
if ( error )
F_5 ( L_2 , V_1 , error ) ;
return error ;
}
static void T_1 F_6 ( unsigned int V_1 )
{
T_2 * V_7 = F_7 ( 0 ) ;
F_8 ( 1 , F_9 ( V_7 ) + V_8 ) ;
F_10 () ;
}
static inline void T_1 F_6 ( unsigned int V_1 )
{}
