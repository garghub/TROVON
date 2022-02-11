T_1 F_1 ( T_1 V_1 , const void * V_2 , unsigned int V_3 )
{
struct {
struct V_4 V_5 ;
char V_6 [ F_2 ( V_7 ) ] ;
} V_8 ;
int V_9 ;
V_8 . V_5 . V_7 = V_7 ;
V_8 . V_5 . V_10 = 0 ;
* ( T_1 * ) V_8 . V_6 = V_1 ;
V_9 = F_3 ( & V_8 . V_5 , V_2 , V_3 ) ;
F_4 ( V_9 ) ;
return * ( T_1 * ) V_8 . V_6 ;
}
static int T_2 F_5 ( void )
{
V_7 = F_6 ( L_1 , 0 , 0 ) ;
if ( F_7 ( V_7 ) )
return F_8 ( V_7 ) ;
return 0 ;
}
static void T_3 F_9 ( void )
{
F_10 ( V_7 ) ;
}
