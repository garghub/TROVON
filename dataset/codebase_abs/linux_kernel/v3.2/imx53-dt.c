static int T_1 F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
F_2 ( V_2 , 0 ) ;
return 0 ;
}
static int T_1 F_3 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
static int V_4 = V_5 + V_6 ;
V_4 -= 32 ;
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
static void T_1 F_4 ( void )
{
struct V_1 * V_7 ;
const struct V_8 * V_9 ;
void (* F_5)( void );
F_6 ( V_10 ) ;
V_7 = F_7 ( NULL , V_11 ) ;
if ( V_7 ) {
V_9 = F_8 ( V_11 , V_7 ) ;
F_5 = V_9 -> V_12 ;
F_5 () ;
F_9 ( V_7 ) ;
}
F_10 ( NULL , V_13 ,
V_14 , NULL ) ;
}
static void T_1 F_11 ( void )
{
F_12 () ;
}
