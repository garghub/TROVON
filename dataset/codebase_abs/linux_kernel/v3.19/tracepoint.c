void F_1 ( const char * V_1 , const char * V_2 , ... )
{
struct V_3 V_4 = {
. V_2 = V_2 ,
} ;
T_1 args ;
va_start ( args , V_2 ) ;
V_4 . V_5 = & args ;
F_2 ( L_1 , V_1 , & V_4 ) ;
F_3 ( V_1 , & V_4 ) ;
va_end ( args ) ;
}
