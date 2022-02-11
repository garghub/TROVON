unsigned int T_1 F_1 ( void )
{
return V_1 / 16 ;
}
static void T_1 F_2 ( unsigned long V_2 )
{
if ( F_3 ( V_2 , L_1 ) )
V_1 = 166666666 ;
else if ( F_3 ( V_2 , L_2 ) ||
F_3 ( V_2 , L_3 ) )
V_1 = 33333333 ;
else if ( F_3 ( V_2 , L_4 ) )
V_1 = 800000000 ;
else
V_1 = 50000000 ;
}
static const void * T_1 F_4 ( const char * const * * V_3 )
{
static const struct V_4 * V_5 = V_6 ;
const struct V_4 * V_7 = V_5 ;
if ( V_7 >= V_8 )
return NULL ;
V_5 ++ ;
* V_3 = V_7 -> V_9 ;
return V_7 ;
}
const struct V_4 * T_1 F_5 ( void * V_10 )
{
const struct V_4 * V_5 ;
unsigned long V_2 ;
if ( ! F_6 ( V_10 ) )
return NULL ;
V_5 = F_7 ( NULL , F_4 ) ;
if ( ! V_5 )
F_8 () ;
V_2 = F_9 () ;
F_2 ( V_2 ) ;
return V_5 ;
}
