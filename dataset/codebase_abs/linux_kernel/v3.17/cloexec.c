static int F_1 ( void )
{
struct V_1 V_2 = {
. type = V_3 ,
. V_4 = V_3 ,
} ;
int V_5 ;
int V_6 ;
V_5 = F_2 ( & V_2 , 0 , - 1 , - 1 ,
V_7 ) ;
V_6 = V_8 ;
if ( V_5 >= 0 ) {
F_3 ( V_5 ) ;
return 1 ;
}
F_4 ( V_6 != V_9 ,
L_1 ,
V_6 , strerror ( V_6 ) ) ;
V_5 = F_2 ( & V_2 , 0 , - 1 , - 1 , 0 ) ;
V_6 = V_8 ;
if ( F_4 ( V_5 < 0 ,
L_2 ,
V_6 , strerror ( V_6 ) ) )
return - 1 ;
F_3 ( V_5 ) ;
return 0 ;
}
unsigned long F_5 ( void )
{
static bool V_10 ;
if ( ! V_10 ) {
if ( F_1 () <= 0 )
V_11 = 0 ;
V_10 = true ;
}
return V_11 ;
}
