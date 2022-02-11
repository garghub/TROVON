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
F_3 ( L_1 ) ;
if ( V_4 > ( 128 * V_3 / 300 ) )
F_3 ( L_2 ) ;
* V_2 = V_4 ;
* V_1 = V_5 ;
F_4 ( L_3 ,
* V_2 , * V_1 , V_3 ) ;
}
struct V_7 V_7 ( T_1 clock )
{
struct V_7 V_8 ;
T_2 V_9 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_10 ) ; V_9 ++ ) {
if ( V_10 [ V_9 ] . clock == clock )
return V_10 [ V_9 ] ;
}
F_1 ( clock , & V_8 . V_11 , & V_8 . V_12 , 32000 ) ;
F_1 ( clock , & V_8 . V_13 , & V_8 . V_14 , 44100 ) ;
F_1 ( clock , & V_8 . V_15 , & V_8 . V_16 , 48000 ) ;
return V_8 ;
}
