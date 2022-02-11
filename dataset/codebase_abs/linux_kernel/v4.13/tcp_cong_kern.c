int F_1 ( struct V_1 * V_2 )
{
char V_3 [] = L_1 ;
int V_4 = 0 ;
int V_5 ;
if ( F_2 ( V_2 -> V_6 ) != 55601 &&
V_2 -> V_7 != 55601 )
return - 1 ;
V_5 = ( int ) V_2 -> V_5 ;
#ifdef F_3
F_4 ( L_2 , V_5 ) ;
#endif
if ( V_2 -> V_8 == V_9 &&
V_2 -> V_10 [ 0 ] == V_2 -> V_11 [ 0 ] &&
( F_2 ( V_2 -> V_10 [ 1 ] ) & 0xfff00000 ) ==
( F_2 ( V_2 -> V_11 [ 1 ] ) & 0xfff00000 ) ) {
switch ( V_5 ) {
case V_12 :
V_4 = 1 ;
break;
case V_13 :
V_4 = F_5 ( V_2 , V_14 , V_15 ,
V_3 , sizeof( V_3 ) ) ;
break;
case V_16 :
V_4 = F_5 ( V_2 , V_14 , V_15 ,
V_3 , sizeof( V_3 ) ) ;
break;
default:
V_4 = - 1 ;
}
} else {
V_4 = - 1 ;
}
#ifdef F_3
F_4 ( L_3 , V_4 ) ;
#endif
V_2 -> V_17 = V_4 ;
return 1 ;
}
