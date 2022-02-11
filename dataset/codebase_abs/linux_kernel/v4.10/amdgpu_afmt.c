static void F_1 ( T_1 clock , int * V_1 , int * V_2 , int V_3 )
{
int V_4 , V_5 ;
unsigned long div , V_6 ;
V_4 = 128 * V_3 ;
V_5 = clock * 1000 ;
div = F_2 ( V_4 , V_5 ) ;
V_4 /= div ;
V_5 /= div ;
V_6 = ( ( 128 * V_3 / 1000 ) + ( V_4 - 1 ) ) / V_4 ;
V_4 *= V_6 ;
V_5 *= V_6 ;
if ( V_4 < ( 128 * V_3 / 1500 ) )
F_3 ( V_7 L_1 ) ;
if ( V_4 > ( 128 * V_3 / 300 ) )
F_3 ( V_7 L_2 ) ;
* V_2 = V_4 ;
* V_1 = V_5 ;
F_4 ( L_3 ,
* V_2 , * V_1 , V_3 ) ;
}
struct V_8 V_8 ( T_1 clock )
{
struct V_8 V_9 ;
T_2 V_10 ;
for ( V_10 = 0 ; V_10 < F_5 ( V_11 ) ; V_10 ++ ) {
if ( V_11 [ V_10 ] . clock == clock )
return V_11 [ V_10 ] ;
}
F_1 ( clock , & V_9 . V_12 , & V_9 . V_13 , 32000 ) ;
F_1 ( clock , & V_9 . V_14 , & V_9 . V_15 , 44100 ) ;
F_1 ( clock , & V_9 . V_16 , & V_9 . V_17 , 48000 ) ;
return V_9 ;
}
