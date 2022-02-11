int F_1 ( struct V_1 * V_2 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
int V_5 = - V_6 ;
switch ( V_2 -> V_7 -> type ) {
case V_8 :
case V_9 :
case V_10 :
V_5 = F_2 ( V_2 , V_2 -> V_7 , V_11 , V_4 , V_3 ,
V_2 -> V_12 ) ;
if ( V_5 > 0 )
V_5 = 0 ;
break;
default:
F_3 ( 1 , L_1 , V_2 -> V_7 -> type ) ;
}
return V_5 ;
}
int F_4 ( struct V_13 * V_14 , struct V_1 * V_2 ,
unsigned char * V_15 , unsigned char V_16 )
{
int V_5 ;
F_5 ( V_2 , V_17 , V_14 -> V_18 . V_19 ,
V_16 , V_20 ) ;
F_6 ( V_2 ) ;
V_5 = F_1 ( V_2 , V_2 -> V_7 -> V_21 , V_15 ) ;
if ( F_7 ( ! V_5 ) )
V_5 = F_8 ( V_2 ) ;
return V_5 ;
}
