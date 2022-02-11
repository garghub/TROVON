void F_1 ( void )
{
F_2 ( V_1 L_1 ) ;
}
int F_3 ( int V_2 )
{
int V_3 ;
V_3 = V_4 ;
V_4 = V_2 ;
return V_3 ;
}
int F_4 ( void )
{
return V_4 ;
}
void F_5 ( struct V_5 * V_6 , char * V_7 )
{
if ( V_6 ) {
F_2 ( V_8 L_2 , V_6 -> V_9 ,
V_6 -> V_10 , V_6 -> V_11 , V_6 -> V_12 ,
V_6 -> V_13 . V_14 . V_15 ) ;
}
}
void F_6 ( T_1 * V_16 , T_2 V_17 )
{
T_2 V_18 ;
int V_19 ;
int V_20 ;
int V_21 ;
int V_22 = 8 ;
V_21 = ( V_17 + V_22 - 1 ) / V_22 ;
if ( V_21 > 8 )
V_21 = 8 ;
for ( V_18 = 0 , V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
F_2 ( V_8 L_3 , ( V_16 + V_18 ) ) ;
for ( V_20 = 0 ; V_20 < V_22 && V_18 < V_17 ; V_18 ++ , V_20 ++ )
F_2 ( L_4 , V_20 == 0 ? L_5 : L_6 , V_16 [ V_18 ] ) ;
F_2 ( L_7 ) ;
}
}
