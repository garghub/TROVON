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
struct V_7 * V_8 = V_7 ( V_6 ) ;
int V_9 , V_10 , V_11 ;
switch ( ! ! V_6 -> V_12 . V_13 * V_6 -> V_12 . V_14 ) {
case 0x20 :
V_9 = ( F_3 ( V_8 , V_6 -> V_12 . V_13 + 0x04 ) & 0x0f80 ) >> 7 ;
V_10 = F_4 ( V_8 , V_6 -> V_12 . V_13 + 0x04 ) & 0x1f ;
V_11 = F_4 ( V_8 , V_6 -> V_12 . V_13 + 0x0a ) & 0x7f ;
break;
default:
return - V_15 ;
}
V_9 = F_1 ( V_16 , V_9 ) ;
V_10 = F_1 ( V_17 , V_10 ) ;
V_11 = F_1 ( V_18 , V_11 ) ;
if ( V_9 < 0 || V_10 < 0 || V_11 < 0 )
return - V_4 ;
V_6 -> V_19 [ 0 ] &= ~ 0xe74 ;
V_6 -> V_19 [ 0 ] |= ( V_11 & 0x07 ) << 9 ;
V_6 -> V_19 [ 0 ] |= ( V_10 & 0x0e ) << 3 ;
V_6 -> V_19 [ 0 ] |= ( V_10 & 0x01 ) << 2 ;
V_6 -> V_19 [ 2 ] &= ~ 0x038 ;
V_6 -> V_19 [ 2 ] |= ( V_9 & 0x07 ) << 3 ;
return 0 ;
}
