static T_1 F_1 ( char * V_1 , T_1 V_2 )
{
T_1 V_3 ;
T_1 V_4 = 0 ;
int V_5 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
V_5 = F_2 ( * V_1 ++ ) ;
V_4 *= 16 ;
if ( V_5 > 0 )
V_4 += V_5 ;
}
return V_4 ;
}
void F_3 ( char * V_6 , struct V_7 * V_8 )
{
T_1 V_9 ;
V_8 -> V_10 = F_1 ( V_6 , 8 ) ;
V_6 += 8 ;
V_6 ++ ;
V_8 -> V_11 = ( V_12 ) F_1 ( V_6 , 4 ) ;
V_6 += 4 ;
V_6 ++ ;
V_8 -> V_13 = ( V_12 ) F_1 ( V_6 , 4 ) ;
V_6 += 4 ;
V_6 ++ ;
V_8 -> V_14 = ( V_15 ) F_1 ( V_6 , 2 ) ;
V_6 += 2 ;
V_8 -> V_16 = ( V_15 ) F_1 ( V_6 , 2 ) ;
V_6 += 2 ;
V_6 ++ ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ ) {
V_8 -> V_17 [ V_9 ] = ( V_15 ) F_1 ( V_6 , 2 ) ;
V_6 += 2 ;
}
}
