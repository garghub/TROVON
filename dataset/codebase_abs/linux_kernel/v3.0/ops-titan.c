static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 * V_6 )
{
T_2 V_7 , V_8 ;
int V_9 , V_10 , V_11 ;
V_10 = V_2 -> V_12 ;
V_9 = F_2 ( V_3 ) ;
V_11 = F_3 ( V_3 ) ;
V_7 = ( V_10 << 16 ) | ( V_9 << 11 ) | ( V_11 << 8 ) |
( V_4 & 0xfc ) | 0x80000000 ;
F_4 ( V_7 , V_13 ) ;
V_8 = F_5 ( V_14 ) >> ( ( V_4 & 3 ) << 3 ) ;
switch ( V_5 ) {
case 1 :
V_8 &= 0xff ;
case 2 :
V_8 &= 0xffff ;
}
* V_6 = V_8 ;
return V_15 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 V_6 )
{
T_2 V_7 ;
int V_9 , V_10 , V_11 ;
V_10 = V_2 -> V_12 ;
V_9 = F_2 ( V_3 ) ;
V_11 = F_3 ( V_3 ) ;
V_7 = ( V_10 << 16 ) | ( V_9 << 11 ) | ( V_11 << 8 ) |
( V_4 & 0xfc ) | 0x80000000 ;
F_4 ( V_7 , V_13 ) ;
switch ( V_5 ) {
case 1 :
F_7 ( V_6 , V_14 + ( ~ V_4 & 0x3 ) ) ;
break;
case 2 :
F_8 ( V_6 , V_14 + ( ~ V_4 & 0x2 ) ) ;
break;
case 4 :
F_4 ( V_6 , V_14 ) ;
break;
}
return V_15 ;
}
