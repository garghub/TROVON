int F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 )
{
char V_4 [ 80 ] , V_5 ;
int V_6 ;
if( ! V_2 ) return 1 ;
if( V_2 -> V_7 ) {
V_5 = 1 ;
F_2 ( V_1 , L_1 ,
V_3 , L_2 , V_3 + 2 , L_2 ) ;
for( V_6 = 0 ; V_6 < F_3 ( V_2 -> V_7 ) ; V_6 ++ ) {
if( ! V_5 ) F_4 ( V_1 , L_3 ) ;
else V_5 = 0 ;
F_5 ( V_4 , sizeof V_4 ,
F_6 ( V_2 -> V_7 , V_6 ) , 0 ) ;
F_4 ( V_1 , V_4 ) ;
}
F_4 ( V_1 , L_4 ) ;
} else F_2 ( V_1 , L_5 , V_3 , L_2 ) ;
if( V_2 -> V_8 ) {
V_5 = 1 ;
F_2 ( V_1 , L_6 ,
V_3 , L_2 , V_3 + 2 , L_2 ) ;
for( V_6 = 0 ; V_6 < F_3 ( V_2 -> V_8 ) ; V_6 ++ ) {
if( ! V_5 ) F_4 ( V_1 , L_3 ) ;
else V_5 = 0 ;
F_5 ( V_4 , sizeof V_4 ,
F_6 ( V_2 -> V_8 , V_6 ) , 0 ) ;
F_4 ( V_1 , V_4 ) ;
}
F_4 ( V_1 , L_4 ) ;
} else F_2 ( V_1 , L_7 , V_3 , L_2 ) ;
if( V_2 -> V_9 ) F_2 ( V_1 , L_8 , V_3 , L_2 ,
V_2 -> V_9 -> V_10 ) ;
if( V_2 -> V_11 ) {
F_2 ( V_1 , L_9 , V_3 , L_2 ) ;
for( V_6 = 0 ; V_6 < V_2 -> V_11 -> V_12 ; V_6 ++ )
F_2 ( V_1 , L_10 ,
V_6 ? L_11 : L_2 ,
V_2 -> V_11 -> V_10 [ V_6 ] ) ;
F_7 ( V_1 , L_4 , 1 ) ;
}
return 1 ;
}
