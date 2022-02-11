static inline int F_1 ( unsigned char V_1 ,
unsigned int V_2 , int V_3 )
{
if ( V_1 == 0 ) {
if ( F_2 ( V_2 ) < 11 || V_3 > 0xff )
return - V_4 ;
F_3 ( ( 1U << F_2 ( V_2 ) ) | ( F_4 ( V_2 ) << 8 ) |
( V_3 & 0xfc ) , V_5 ) ;
} else {
if ( V_3 > 0xff )
return - V_4 ;
F_3 ( ( ( V_6 ) V_1 << 16 ) | ( ( V_2 & 0xff ) << 8 ) |
( V_3 & 0xfc ) | 1U , V_5 ) ;
}
return 0 ;
}
static int F_5 ( struct V_7 * V_8 , unsigned int V_2 , int V_3 ,
int V_9 , V_6 * V_10 )
{
V_6 V_11 ;
* V_10 = 0xffffffffU ;
if ( F_1 ( V_8 -> V_1 , V_2 , V_3 ) < 0 )
return V_12 ;
V_11 = F_6 ( V_13 ) ;
switch ( V_9 ) {
case 1 :
* V_10 = ( V_11 >> ( ( V_3 & 3 ) << 3 ) ) & 0xffU ;
break;
case 2 :
* V_10 = ( V_11 >> ( ( V_3 & 2 ) << 3 ) ) & 0xffffU ;
break;
case 4 :
* V_10 = V_11 ;
break;
default:
return V_14 ;
}
return V_15 ;
}
static int F_7 ( struct V_7 * V_8 , unsigned int V_2 , int V_3 ,
int V_9 , V_6 V_10 )
{
V_6 V_11 ;
int V_16 ;
if ( F_1 ( V_8 -> V_1 , V_2 , V_3 ) < 0 )
return V_12 ;
V_11 = F_6 ( V_13 ) ;
switch ( V_9 ) {
case 1 :
V_16 = ( V_3 & 3 ) << 3 ;
V_11 &= ~ ( 0xffU << V_16 ) ;
V_11 |= ( ( V_10 & 0xffU ) << V_16 ) ;
break;
case 2 :
V_16 = ( V_3 & 2 ) << 3 ;
V_11 &= ~ ( 0xffffU << V_16 ) ;
V_11 |= ( ( V_10 & 0xffffU ) << V_16 ) ;
break;
case 4 :
V_11 = V_10 ;
break;
default:
return V_14 ;
}
F_3 ( V_11 , V_13 ) ;
return V_15 ;
}
