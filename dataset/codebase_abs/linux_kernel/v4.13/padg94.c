void
F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
struct V_8 * V_9 = V_6 -> V_9 ;
const T_1 V_10 = ( V_2 -> V_11 - F_2 ( 0 ) ) * 0x50 ;
switch ( V_4 ) {
case V_12 :
F_3 ( V_9 , 0x00e50c + V_10 , 0x00000001 , 0x00000001 ) ;
break;
case V_13 :
F_3 ( V_9 , 0x00e500 + V_10 , 0x0000c003 , 0x0000c001 ) ;
F_3 ( V_9 , 0x00e50c + V_10 , 0x00000001 , 0x00000000 ) ;
break;
case V_14 :
F_3 ( V_9 , 0x00e500 + V_10 , 0x0000c003 , 0x00000002 ) ;
F_3 ( V_9 , 0x00e50c + V_10 , 0x00000001 , 0x00000000 ) ;
break;
default:
F_4 ( 1 ) ;
break;
}
}
int
F_5 ( struct V_15 * V_7 , int V_11 , struct V_1 * * V_16 )
{
return F_6 ( & V_17 , V_7 , V_11 , V_16 ) ;
}
int
F_7 ( struct V_15 * V_7 , int V_11 , struct V_1 * * V_16 )
{
return F_6 ( & V_18 , V_7 , V_11 , V_16 ) ;
}
