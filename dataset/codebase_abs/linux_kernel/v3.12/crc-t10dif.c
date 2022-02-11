T_1 F_1 ( const unsigned char * V_1 , T_2 V_2 )
{
struct {
struct V_3 V_4 ;
char V_5 [ 2 ] ;
} V_6 ;
int V_7 ;
if ( F_2 ( & V_8 ) )
return F_3 ( 0 , V_1 , V_2 ) ;
V_6 . V_4 . V_9 = V_10 ;
V_6 . V_4 . V_11 = 0 ;
* ( T_1 * ) V_6 . V_5 = 0 ;
V_7 = F_4 ( & V_6 . V_4 , V_1 , V_2 ) ;
F_5 ( V_7 ) ;
return * ( T_1 * ) V_6 . V_5 ;
}
static int T_3 F_6 ( void )
{
V_10 = F_7 ( L_1 , 0 , 0 ) ;
if ( F_8 ( V_10 ) ) {
F_9 ( & V_8 ) ;
V_10 = NULL ;
}
return 0 ;
}
static void T_4 F_10 ( void )
{
F_11 ( V_10 ) ;
}
