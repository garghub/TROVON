int
F_1 ( T_1 * V_1 )
{
int V_2 = 0 ;
int V_3 ;
T_2 V_4 = V_5 ;
V_3 = F_2 ( V_1 ) ;
if ( V_3 == - 1 ) {
F_3 ( V_1 , L_1 ) ;
V_3 = 0 ;
}
while ( 1 ) {
if ( V_2 > V_6 ) {
F_4 ( V_1 , L_2
L_3 ,
V_2 ) ;
break;
}
V_2 ++ ;
F_5 ( V_1 , L_4 , V_2 ) ;
if ( V_7 [ V_3 ] > 0 ) {
F_6 ( V_1 , L_5 ) ;
break;
} else if ( V_7 [ V_3 ] == 0 ) {
V_7 [ V_3 ] ++ ;
}
F_7 ( V_1 -> V_8 ) ;
V_4 = F_8 ( V_1 -> V_9 , V_10 ) ;
F_9 ( V_1 -> V_8 ) ;
if ( V_4 == V_11 ) {
return F_10 ( V_4 ) ;
}
if ( V_4 == V_12 ) {
F_4 ( V_1 , L_6 ) ;
return F_10 ( V_4 ) ;
}
if ( V_4 != V_13 ) {
F_4 ( V_1 , L_7 ) ;
continue;
}
F_11 ( V_1 -> V_9 , & V_1 -> V_14 ) ;
return F_10 ( V_4 ) ;
}
return F_10 ( V_4 ) ;
}
