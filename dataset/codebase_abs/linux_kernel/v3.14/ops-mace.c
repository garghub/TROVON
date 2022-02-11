static inline int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
return ( ( V_2 -> V_5 & 0xff ) << 16 ) |
( ( V_3 & 0xff ) << 8 ) |
( V_4 & 0xfc ) ;
}
static int
F_2 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_6 , T_1 * V_7 )
{
T_1 V_8 = V_9 -> V_10 . V_8 ;
V_9 -> V_10 . V_8 = V_8 & ~ V_11 ;
V_9 -> V_10 . V_12 = F_1 ( V_2 , V_3 , V_4 ) ;
switch ( V_6 ) {
case 1 :
* V_7 = V_9 -> V_10 . V_13 . V_14 [ ( V_4 & 3 ) ^ 3 ] ;
break;
case 2 :
* V_7 = V_9 -> V_10 . V_13 . V_15 [ ( ( V_4 >> 1 ) & 1 ) ^ 1 ] ;
break;
case 4 :
* V_7 = V_9 -> V_10 . V_13 . V_16 ;
break;
}
V_9 -> V_10 . error &= ~ V_17 ;
V_9 -> V_10 . V_8 = V_8 ;
if ( V_2 -> V_5 == 0 && V_4 == 0x40 && V_6 == 4 &&
( V_3 == ( 1 << 3 ) || V_3 == ( 2 << 3 ) ) )
* V_7 |= 0x1000 ;
F_3 ( L_1 , V_6 * 8 , V_4 , * V_7 ) ;
return V_18 ;
}
static int
F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_6 , T_1 V_7 )
{
V_9 -> V_10 . V_12 = F_1 ( V_2 , V_3 , V_4 ) ;
switch ( V_6 ) {
case 1 :
V_9 -> V_10 . V_13 . V_14 [ ( V_4 & 3 ) ^ 3 ] = V_7 ;
break;
case 2 :
V_9 -> V_10 . V_13 . V_15 [ ( ( V_4 >> 1 ) & 1 ) ^ 1 ] = V_7 ;
break;
case 4 :
V_9 -> V_10 . V_13 . V_16 = V_7 ;
break;
}
F_3 ( L_2 , V_6 * 8 , V_4 , V_7 ) ;
return V_18 ;
}
