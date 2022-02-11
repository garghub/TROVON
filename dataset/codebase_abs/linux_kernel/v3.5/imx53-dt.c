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
struct V_8 * V_8 ;
V_8 = F_5 ( NULL , L_1 ) ;
if ( F_6 ( V_8 ) ) {
F_7 ( L_2 ) ;
return;
}
F_8 ( V_8 , NULL , L_3 ) ;
}
static void T_1 F_9 ( void )
{
struct V_1 * V_9 ;
const struct V_10 * V_11 ;
void (* F_10)( void );
F_11 ( V_12 ) ;
F_12 () ;
V_9 = F_13 ( NULL , V_13 ) ;
if ( V_9 ) {
V_11 = F_14 ( V_13 , V_9 ) ;
F_10 = V_11 -> V_14 ;
F_10 () ;
F_15 ( V_9 ) ;
}
if ( F_16 ( L_4 ) )
F_4 () ;
F_17 ( NULL , V_15 ,
V_16 , NULL ) ;
}
static void T_1 F_18 ( void )
{
F_19 () ;
}
