static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 * V_6 )
{
F_2 ( V_7 , F_3 ( V_2 , V_3 , V_4 ) ) ;
switch ( V_5 ) {
case 1 :
* V_6 = ( V_8 ) F_4 ( V_9 + ( V_4 & 3 ) ) ;
break;
case 2 :
* V_6 = ( V_10 ) F_5 ( V_9 + ( V_4 & 2 ) ) ;
break;
case 4 :
* V_6 = F_6 ( V_9 ) ;
break;
}
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 V_6 )
{
F_2 ( V_7 , F_3 ( V_2 , V_3 , V_4 ) ) ;
switch ( V_5 ) {
case 1 :
F_8 ( V_9 + ( V_4 & 3 ) , ( V_8 ) V_6 ) ;
break;
case 2 :
F_9 ( V_9 + ( V_4 & 2 ) , ( V_10 ) V_6 ) ;
break;
case 4 :
F_2 ( V_9 , V_6 ) ;
break;
}
return V_11 ;
}
