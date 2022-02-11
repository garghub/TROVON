T_1 * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 . V_5 ;
}
void F_2 ( int * V_6 , int * V_7 , int * V_8 )
{
* V_6 = V_9 ;
* V_7 = V_10 ;
if ( V_8 )
* V_8 = V_11 ;
}
int F_3 ( struct V_1 * V_2 ,
const char * V_12 )
{
int V_6 , V_7 ;
F_2 ( & V_6 , & V_7 , NULL ) ;
V_2 -> V_13 = ( ( ( V_14 ) ( V_6 << 8 ) & 0xFF00 )
| ( ( V_14 ) V_7 & 0x00FF ) ) ;
V_2 -> V_15 = V_16 ;
strncpy ( ( char * ) V_2 -> V_3 . V_4 . V_17 , V_12 ,
V_18 ) ;
V_2 -> V_3 . V_4 . V_19 =
V_20 ;
V_2 -> V_3 . V_4 . V_21 |=
V_22 ;
V_2 -> V_23 . V_24 [ 0 ] = 0 ;
V_2 -> V_23 . V_25 = 0 ;
V_2 -> V_3 . V_4 . V_26 = V_27 ;
V_2 -> V_3 . V_4 . V_21 &= ~ ( V_28 ) ;
return 0 ;
}
