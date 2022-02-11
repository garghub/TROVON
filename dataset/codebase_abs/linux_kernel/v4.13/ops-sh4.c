static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned long V_10 ;
T_1 V_11 ;
F_2 ( & V_12 , V_10 ) ;
F_3 ( V_8 , F_4 ( V_2 , V_3 , V_4 ) , V_13 ) ;
V_11 = F_5 ( V_8 , V_14 ) ;
F_6 ( & V_12 , V_10 ) ;
switch ( V_5 ) {
case 1 :
* V_6 = ( V_11 >> ( ( V_4 & 3 ) << 3 ) ) & 0xff ;
break;
case 2 :
* V_6 = ( V_11 >> ( ( V_4 & 2 ) << 3 ) ) & 0xffff ;
break;
case 4 :
* V_6 = V_11 ;
break;
default:
return V_15 ;
}
return V_16 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned long V_10 ;
int V_17 ;
T_1 V_11 ;
F_2 ( & V_12 , V_10 ) ;
F_3 ( V_8 , F_4 ( V_2 , V_3 , V_4 ) , V_13 ) ;
V_11 = F_5 ( V_8 , V_14 ) ;
F_6 ( & V_12 , V_10 ) ;
switch ( V_5 ) {
case 1 :
V_17 = ( V_4 & 3 ) << 3 ;
V_11 &= ~ ( 0xff << V_17 ) ;
V_11 |= ( ( V_6 & 0xff ) << V_17 ) ;
break;
case 2 :
V_17 = ( V_4 & 2 ) << 3 ;
V_11 &= ~ ( 0xffff << V_17 ) ;
V_11 |= ( ( V_6 & 0xffff ) << V_17 ) ;
break;
case 4 :
V_11 = V_6 ;
break;
default:
return V_15 ;
}
F_3 ( V_8 , V_11 , V_14 ) ;
return V_16 ;
}
