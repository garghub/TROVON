static inline int
F_1 ( const struct F_1 * V_1 , int V_2 )
{
while ( V_1 -> V_2 >= 0 ) {
if ( V_1 -> V_2 == V_2 )
return V_1 -> V_3 ;
V_1 ++ ;
}
return - V_4 ;
}
int
F_2 ( struct V_5 * V_6 )
{
int V_7 , V_8 , V_9 = 0 , V_10 = 0 ;
switch ( V_6 -> V_11 -> V_12 . V_13 ) {
case 0x10 :
V_7 = V_6 -> V_11 -> V_12 . V_14 ;
V_8 = V_6 -> V_11 -> V_12 . V_15 ;
V_9 = ! V_6 -> V_11 -> V_12 . V_16 ;
V_10 = V_6 -> V_11 -> V_12 . V_17 & 3 ;
break;
case 0x20 :
V_7 = ( V_6 -> V_11 -> V_12 . V_18 [ 1 ] & 0x0000001f ) ;
V_8 = ( V_6 -> V_11 -> V_12 . V_18 [ 2 ] & 0x007f0000 ) >> 16 ;
break;
default:
return - V_19 ;
}
if ( V_6 -> V_11 -> V_12 . V_13 == 0x20 ||
V_6 -> V_11 -> V_12 . V_20 == 0xff ) {
V_10 = ( V_6 -> V_21 [ 1 ] & 0x004 ) >> 2 |
( V_6 -> V_21 [ 1 ] & 0x040 ) >> 5 ;
}
V_7 = F_1 ( V_22 , V_7 ) ;
V_8 = F_1 ( V_23 , V_8 ) ;
if ( V_7 < 0 || V_8 < 0 )
return - V_4 ;
V_6 -> V_21 [ 0 ] &= ~ 0xf70 ;
V_6 -> V_21 [ 0 ] |= ( V_8 & 0x07 ) << 9 ;
V_6 -> V_21 [ 0 ] |= ( V_7 & 0x07 ) << 4 ;
V_6 -> V_21 [ 1 ] &= ~ 0x045 ;
V_6 -> V_21 [ 1 ] |= ( V_10 & 0x1 ) << 2 ;
V_6 -> V_21 [ 1 ] |= ( V_10 & 0x2 ) << 5 ;
V_6 -> V_21 [ 1 ] |= ! V_9 ;
return 0 ;
}
