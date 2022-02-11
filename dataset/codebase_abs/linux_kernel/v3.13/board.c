T_1 F_1 ( void )
{
int V_1 ;
char V_2 [ 10 ] ;
const struct V_3 * V_4 ;
if ( V_5 . V_6 != V_7 )
return;
V_1 = F_2 ( L_1 , V_2 , sizeof( V_2 ) ) ;
if ( V_1 == - V_8 ) {
return;
}
V_4 = F_3 () ;
V_5 . V_6 = V_4 -> V_6 ;
F_4 ( V_5 . V_9 , V_4 -> V_9 ,
V_10 ) ;
}
enum V_5 F_5 ( void )
{
return V_5 . V_6 ;
}
const char * F_6 ( void )
{
return V_5 . V_9 ;
}
