static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_2 ( V_2 , V_3 , F_3 ( V_4 ) ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_5 , void * V_6 )
{
switch ( V_5 ) {
case V_7 :
{
int * V_8 = V_6 ;
switch ( * V_8 ) {
case V_9 :
F_1 ( V_2 , 0x00 , 0x1441 ) ;
break;
case V_10 :
F_1 ( V_2 , 0x00 , 0x1241 ) ;
break;
default:
F_5 ( V_11 L_1 ,
* V_8 ) ;
break;
}
break;
}
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_12 * V_13 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( ! F_7 ( V_15 , V_16 ) )
return - V_17 ;
F_5 ( V_18
L_2 ,
V_2 -> V_19 , V_15 -> V_20 ) ;
F_1 ( V_2 , 0x00 , 0x8000 ) ;
F_1 ( V_2 , 0x00 , 0x1241 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return 0 ;
}
