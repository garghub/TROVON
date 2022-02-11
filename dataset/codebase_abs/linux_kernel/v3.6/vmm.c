static int T_1 F_1 ( void )
{
V_1 = V_2 ;
return F_2 ( & V_3 , 1024 , 0 , V_4 ) ;
}
static void T_2 F_3 ( void )
{
F_4 () ;
return ;
}
void F_5 ( T_3 * V_5 )
{
F_6 ( V_5 ) ;
}
void F_7 ( T_3 * V_5 )
{
F_8 ( V_5 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_10 . V_11 ;
long V_12 ;
F_10 ( V_12 ) ;
V_9 -> V_13 = V_14 ;
F_11 ( V_7 ) ;
F_12 ( V_12 ) ;
}
T_4 int F_13 ( const char * V_15 , ... )
{
struct V_6 * V_7 = V_16 ;
T_5 args ;
int V_17 ;
memset ( V_7 -> V_10 . V_18 , 0 , V_19 ) ;
va_start ( args , V_15 ) ;
V_17 = vsnprintf ( V_7 -> V_10 . V_18 , V_19 , V_15 , args ) ;
va_end ( args ) ;
F_9 ( V_7 ) ;
return V_17 ;
}
