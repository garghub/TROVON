long F_1 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_4 :
return V_2 -> V_5 . V_6 + sizeof( long ) * 2 + 2 ;
case V_7 :
case V_8 :
return * ( unsigned short * ) ( V_2 -> V_5 . V_9 + V_10 [ V_3 ] ) ;
default:
return * ( unsigned long * ) ( V_2 -> V_5 . V_9 + V_10 [ V_3 ] ) ;
}
}
int F_2 ( struct V_1 * V_2 , int V_3 , unsigned long V_11 )
{
unsigned short V_12 ;
switch ( V_3 ) {
case V_4 :
V_2 -> V_5 . V_6 = V_11 - sizeof( long ) * 2 - 2 ;
case V_7 :
V_12 = * ( unsigned short * ) ( V_2 -> V_5 . V_9 + V_10 [ V_3 ] ) ;
V_12 &= ~ V_13 ;
V_11 &= V_13 ;
V_11 |= V_12 ;
* ( unsigned short * ) ( V_2 -> V_5 . V_9 + V_10 [ V_3 ] ) = V_11 ;
break;
case V_8 :
return - V_14 ;
default:
* ( unsigned long * ) ( V_2 -> V_5 . V_9 + V_10 [ V_3 ] ) = V_11 ;
break;
}
return 0 ;
}
void F_3 ( struct V_1 * V_15 )
{
* ( unsigned short * ) ( V_15 -> V_5 . V_9 + V_10 [ V_8 ] ) &= ~ V_16 ;
}
void F_4 ( struct V_1 * V_15 )
{
* ( unsigned short * ) ( V_15 -> V_5 . V_9 + V_10 [ V_8 ] ) |= V_16 ;
}
T_1 void F_5 ( unsigned long V_17 )
{
( void ) V_17 ;
F_6 ( V_18 , V_19 ) ;
}
