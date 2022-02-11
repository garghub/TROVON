int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 = - 1 ;
struct V_6 {
int V_3 ;
int V_4 ;
} V_7 [ 4 ] ;
int V_8 = 0 ;
while ( V_2 -> V_9 -> V_10 > 0 ) {
V_3 = V_7 [ V_8 ] . V_3 = F_2 ( V_2 -> V_11 ) ;
V_4 = V_7 [ V_8 ] . V_4 = F_3 ( V_2 , V_4 ) ;
V_2 = V_2 -> V_9 -> V_12 ;
V_8 ++ ;
if ( V_8 > 3 ) F_4 ( L_1 ) ;
}
V_3 = F_2 ( V_2 -> V_11 ) ;
if ( ( V_3 < 3 ) || ( V_8 == 0 ) ) {
V_5 = V_13 + F_3 ( V_2 , V_4 ) - 1 ;
} else {
V_8 -- ;
V_3 = V_7 [ V_8 ] . V_3 ;
V_4 = V_7 [ V_8 ] . V_4 ;
if ( V_3 > 0 ) {
F_4 ( L_2 ) ;
} else {
if ( V_8 > 0 ) {
V_8 -- ;
V_3 = V_7 [ V_8 ] . V_3 ;
V_4 = V_7 [ V_8 ] . V_4 ;
V_5 = V_14 + ( V_4 - 1 ) ;
} else {
V_5 = - 1 ;
}
}
}
return V_5 ;
}
