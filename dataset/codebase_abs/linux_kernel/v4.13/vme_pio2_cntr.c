static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
T_1 V_5 ;
V_5 = V_6 [ V_3 ] | V_7 | V_2 -> V_8 [ V_3 ] . V_9 ;
V_4 = F_2 ( V_2 -> V_10 , & V_5 , 1 , V_11 [ V_3 ] ) ;
if ( V_4 < 0 )
return V_4 ;
V_5 = V_2 -> V_8 [ V_3 ] . V_12 & 0xFF ;
V_4 = F_2 ( V_2 -> V_10 , & V_5 , 1 , V_13 [ V_3 ] ) ;
if ( V_4 < 0 )
return V_4 ;
V_5 = ( V_2 -> V_8 [ V_3 ] . V_12 >> 8 ) & 0xFF ;
V_4 = F_2 ( V_2 -> V_10 , & V_5 , 1 , V_13 [ V_3 ] ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
int V_14 , V_4 = 0 ;
T_1 V_15 ;
for ( V_14 = 0 ; V_14 < 6 ; V_14 ++ ) {
V_2 -> V_8 [ V_14 ] . V_9 = V_16 ;
V_2 -> V_8 [ V_14 ] . V_12 = 0 ;
V_4 = F_1 ( V_2 , V_14 ) ;
if ( V_4 < 0 )
return V_4 ;
}
do {
V_4 = F_4 ( V_2 -> V_10 , & V_15 , 1 ,
V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
} while ( V_15 != 0 );
return V_4 ;
}
