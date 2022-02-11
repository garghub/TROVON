static T_1 int F_1 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_3 V_4 ;
struct V_5 * V_6 ;
const char * V_7 ;
bool V_8 ;
int V_9 ;
F_2 () ;
V_8 = F_3 ( V_2 , & V_4 ) ;
if ( V_8 ) {
V_9 = F_4 ( V_2 , & V_4 ) ;
if ( ! V_9 )
return 0 ;
}
if ( V_2 -> V_10 == V_11 )
V_7 = L_1 ;
else if ( V_2 -> V_10 == V_12 )
V_7 = L_2 ;
else
V_7 = L_3 ;
V_6 = F_5 ( NULL , V_7 , 0 ,
NULL , 0 , V_2 , sizeof( * V_2 ) ) ;
return F_6 ( V_6 ) ;
}
