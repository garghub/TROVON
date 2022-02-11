static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
T_1 type ;
type = F_2 ( V_6 -> V_7 [ 0 ] ) ;
switch ( type ) {
case V_8 :
F_3 ( L_1 ) ;
F_4 () ;
break;
case V_9 :
F_3 ( L_2 ) ;
F_5 ( true ) ;
break;
default:
F_6 ( L_3 , type ) ;
}
return 0 ;
}
static int T_2 F_7 ( void )
{
int V_10 ;
V_10 = F_8 ( V_11 ,
& V_12 ) ;
if ( V_10 ) {
F_6 ( L_4 ,
V_13 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
