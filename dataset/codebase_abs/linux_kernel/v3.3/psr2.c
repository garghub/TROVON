static void F_1 ( void )
{
F_2 () ;
for (; ; )
continue;
}
static void F_3 ( char * V_1 )
{
F_1 () ;
}
static int T_1 F_4 ( void )
{
unsigned long V_2 = F_5 () ;
if ( F_6 ( V_2 , L_1 ) ) {
return 0 ;
}
if ( ! F_6 ( V_2 , L_2 ) )
return 0 ;
return 1 ;
}
