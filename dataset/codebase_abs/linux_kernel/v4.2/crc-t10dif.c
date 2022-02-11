T_1 F_1 ( T_1 V_1 , const unsigned char * V_2 , T_2 V_3 )
{
struct {
struct V_4 V_5 ;
char V_6 [ 2 ] ;
} V_7 ;
int V_8 ;
if ( F_2 ( & V_9 ) )
return F_3 ( V_1 , V_2 , V_3 ) ;
V_7 . V_5 . V_10 = V_11 ;
V_7 . V_5 . V_12 = 0 ;
* ( T_1 * ) V_7 . V_6 = V_1 ;
V_8 = F_4 ( & V_7 . V_5 , V_2 , V_3 ) ;
F_5 ( V_8 ) ;
return * ( T_1 * ) V_7 . V_6 ;
}
T_1 F_6 ( const unsigned char * V_2 , T_2 V_3 )
{
return F_1 ( 0 , V_2 , V_3 ) ;
}
static int T_3 F_7 ( void )
{
V_11 = F_8 ( L_1 , 0 , 0 ) ;
if ( F_9 ( V_11 ) ) {
F_10 ( & V_9 ) ;
V_11 = NULL ;
}
return 0 ;
}
static void T_4 F_11 ( void )
{
F_12 ( V_11 ) ;
}
