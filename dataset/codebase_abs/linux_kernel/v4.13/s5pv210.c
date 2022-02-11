static int T_1 F_1 ( unsigned long V_1 , const char * V_2 ,
int V_3 , void * V_4 )
{
struct V_5 V_6 ;
const T_2 * V_7 ;
int V_8 ;
if ( ! F_2 ( V_1 , L_1 ) )
return 0 ;
V_7 = F_3 ( V_1 , L_2 , & V_8 ) ;
if ( V_7 == NULL || V_8 != (sizeof( unsigned long ) * 2 ) )
return 0 ;
V_6 . V_9 = F_4 ( F_5 ( V_7 [ 0 ] ) ) ;
V_6 . V_10 = F_5 ( V_7 [ 1 ] ) - 1 ;
V_6 . V_11 = ( unsigned long ) V_12 ;
V_6 . type = V_13 ;
F_6 ( & V_6 , 1 ) ;
return 1 ;
}
static void T_1 F_7 ( void )
{
F_8 () ;
F_9 ( F_1 , NULL ) ;
}
static void F_10 ( enum V_14 V_15 , const char * V_16 )
{
F_11 ( 0x1 , V_17 ) ;
}
static void T_1 F_12 ( void )
{
F_13 ( L_3 , - 1 , NULL , 0 ) ;
F_14 () ;
}
