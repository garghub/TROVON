static void F_1 ( unsigned long * V_1 , T_1 V_2 )
{
if ( V_2 <= 0 || V_2 >= V_3 )
return;
F_2 ( V_1 , V_1 , V_2 , V_3 ) ;
}
bool F_3 ( void * V_4 , unsigned long * V_1 ,
T_1 V_5 , int V_6 )
{
struct V_7 * V_8 = V_4 ;
if ( V_5 <= 0 && V_5 > - V_3 ) {
if ( V_6 )
F_4 ( V_1 , - V_5 ) ;
return false ;
}
if ( V_5 > 0 && V_5 < V_3 ) {
F_1 ( V_1 , V_5 ) ;
if ( V_6 )
F_4 ( V_1 , 0 ) ;
return true ;
}
if ( V_5 >= V_3 &&
V_5 < V_9 ) {
F_5 ( V_10 , V_8 ,
L_1 ,
V_5 - 1 ) ;
F_6 ( V_1 , V_3 ) ;
if ( V_6 )
F_4 ( V_1 , 0 ) ;
return true ;
}
F_5 ( V_10 , V_8 ,
L_2 ) ;
F_6 ( V_1 , V_3 ) ;
if ( V_6 )
F_4 ( V_1 , 0 ) ;
return true ;
}
