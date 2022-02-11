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
