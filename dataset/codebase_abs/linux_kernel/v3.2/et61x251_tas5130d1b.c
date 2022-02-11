static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 += F_2 ( V_2 , 0x14 , 0x01 ) ;
V_3 += F_2 ( V_2 , 0x1b , 0x02 ) ;
V_3 += F_2 ( V_2 , 0x02 , 0x12 ) ;
V_3 += F_2 ( V_2 , 0x0e , 0x60 ) ;
V_3 += F_2 ( V_2 , 0x80 , 0x61 ) ;
V_3 += F_2 ( V_2 , 0xf0 , 0x62 ) ;
V_3 += F_2 ( V_2 , 0x03 , 0x63 ) ;
V_3 += F_2 ( V_2 , 0x14 , 0x64 ) ;
V_3 += F_2 ( V_2 , 0xf4 , 0x65 ) ;
V_3 += F_2 ( V_2 , 0x01 , 0x66 ) ;
V_3 += F_2 ( V_2 , 0x05 , 0x67 ) ;
V_3 += F_2 ( V_2 , 0x8f , 0x68 ) ;
V_3 += F_2 ( V_2 , 0x0f , 0x8d ) ;
V_3 += F_2 ( V_2 , 0x08 , 0x8e ) ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
int V_3 = 0 ;
switch ( V_5 -> V_6 ) {
case V_7 :
V_3 += F_4 ( V_2 , 2 , 0x20 ,
0xf6 - V_5 -> V_8 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 ) ;
break;
case V_9 :
V_3 += F_4 ( V_2 , 2 , 0x40 ,
0x47 - V_5 -> V_8 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 ) ;
break;
default:
return - V_10 ;
}
return V_3 ? - V_11 : 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
const struct V_12 V_13 [] = {
{ F_6 ( 0x102c , 0x6251 ) , } ,
{ }
} ;
if ( ! F_7 ( V_2 , V_13 ) )
return - V_14 ;
F_8 ( V_2 , & V_15 ) ;
return 0 ;
}
