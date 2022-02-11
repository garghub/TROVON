static void
F_1 (
const char * V_1 ,
const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( V_3 && V_3 -> V_6 ) {
F_2 ( L_1 , V_1 , V_3 -> V_6 , V_5 ) ;
return;
}
F_2 ( L_2 , V_1 , V_5 ) ;
}
void
F_3 (
const struct V_2 * V_3 ,
int V_7 ,
const char * V_8 , ... )
{
struct V_4 V_5 ;
T_1 args ;
int V_9 = 0 ;
if ( V_10 && ( V_10 & V_7 ) ) {
F_4 ( V_3 , L_3 ) ;
V_9 = 1 ;
}
va_start ( args , V_8 ) ;
V_5 . V_8 = V_8 ;
V_5 . V_11 = & args ;
F_1 ( V_12 , V_3 , & V_5 ) ;
va_end ( args ) ;
F_5 ( V_9 ) ;
}
void
F_6 ( char * V_13 , char * V_14 , int line )
{
F_7 ( NULL , L_4 ,
V_13 , V_14 , line ) ;
F_8 ( 1 ) ;
}
void
F_9 ( char * V_13 , char * V_14 , int line )
{
F_10 ( NULL , L_4 ,
V_13 , V_14 , line ) ;
if ( V_15 . V_16 )
F_11 () ;
else
F_8 ( 1 ) ;
}
void
F_12 ( void * V_17 , int V_18 )
{
F_13 ( V_12 , L_5 , V_19 , 16 , 1 , V_17 , V_18 , 1 ) ;
}
