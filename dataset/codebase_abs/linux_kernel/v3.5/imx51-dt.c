static int T_1 F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
F_2 ( V_2 , 128 , 0 , 0 , & V_4 , NULL ) ;
return 0 ;
}
static int T_1 F_3 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
static int V_5 = V_6 + V_7 ;
V_5 -= 32 ;
F_2 ( V_2 , 32 , V_5 , 0 , & V_4 , NULL ) ;
return 0 ;
}
static void T_1 F_4 ( void )
{
struct V_1 * V_8 ;
const struct V_9 * V_10 ;
void (* F_5)( void );
F_6 ( V_11 ) ;
F_7 () ;
V_8 = F_8 ( NULL , V_12 ) ;
if ( V_8 ) {
V_10 = F_9 ( V_12 , V_8 ) ;
F_5 = V_10 -> V_13 ;
F_5 () ;
F_10 ( V_8 ) ;
}
F_11 ( NULL , V_14 ,
V_15 , NULL ) ;
}
static void T_1 F_12 ( void )
{
F_13 () ;
}
