void F_1 ( struct V_1 * V_2 , bool V_3 , bool V_4 ,
const char * V_5 , ... )
{
struct V_6 V_7 = {
. V_5 = V_5 ,
} ;
T_1 args ;
va_start ( args , V_5 ) ;
V_7 . V_8 = & args ;
if ( ! V_4 ) {
if ( V_3 )
F_2 ( V_2 , L_1 , & V_7 ) ;
else
F_2 ( V_2 , L_2 , & V_7 ) ;
}
F_3 ( & V_7 ) ;
va_end ( args ) ;
}
void F_4 ( struct V_1 * V_2 ,
T_2 V_9 , bool V_10 , const char * V_11 ,
const char * V_5 , ... )
{
struct V_6 V_7 = {
. V_5 = V_5 ,
} ;
T_1 args ;
va_start ( args , V_5 ) ;
V_7 . V_8 = & args ;
#ifdef F_5
if ( F_6 ( V_9 ) &&
( ! V_10 || F_7 () ) )
F_2 ( V_2 , L_3 , F_8 () ? 'I' : 'U' ,
V_11 , & V_7 ) ;
#endif
F_9 ( V_9 , F_8 () , V_11 , & V_7 ) ;
va_end ( args ) ;
}
