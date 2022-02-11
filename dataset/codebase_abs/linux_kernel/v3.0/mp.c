int
F_1 ( int V_1 , struct V_2 * V_3 , int V_4 , char * V_5 )
{
int V_6 ;
unsigned long V_7 ;
F_2 ( & V_8 , V_7 ) ;
switch( V_9 ) {
case V_10 :
case V_11 :
default:
V_6 = - 1 ;
break;
case V_12 :
V_6 = ( * ( V_13 -> V_14 ) ) ( V_1 , ( int ) V_3 , V_4 , V_5 ) ;
break;
}
F_3 () ;
F_4 ( & V_8 , V_7 ) ;
return V_6 ;
}
