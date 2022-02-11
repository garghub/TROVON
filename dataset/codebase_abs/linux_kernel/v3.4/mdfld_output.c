int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return V_5 -> V_7 ;
}
static void F_2 ( struct V_1 * V_2 , int V_8 ,
int V_9 )
{
switch ( V_9 ) {
case V_10 :
F_3 ( V_2 , V_8 , & V_11 ) ;
break;
case V_12 :
F_4 ( V_2 ) ;
F_3 ( V_2 , V_8 , & V_13 ) ;
break;
case V_14 :
F_3 ( V_2 , V_8 , & V_15 ) ;
break;
case V_16 :
break;
}
}
int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_5 -> V_7 = V_12 ;
F_2 ( V_2 , 0 , V_5 -> V_7 ) ;
F_2 ( V_2 , 1 , V_16 ) ;
return 0 ;
}
