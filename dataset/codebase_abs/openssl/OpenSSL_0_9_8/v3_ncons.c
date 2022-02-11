int F_1 ( T_1 * V_1 ,
void * V_2 , T_2 * V_3 , int V_4 )
{
T_3 * V_5 = V_2 ;
F_2 ( V_1 , V_5 -> V_6 ,
V_3 , V_4 , L_1 ) ;
F_2 ( V_1 , V_5 -> V_7 ,
V_3 , V_4 , L_2 ) ;
return 1 ;
}
static int F_3 ( T_2 * V_3 , T_4 * V_8 )
{
int V_9 , V_10 ;
unsigned char * V_11 ;
V_11 = V_8 -> V_12 ;
V_10 = V_8 -> V_13 ;
F_4 ( V_3 , L_3 ) ;
if( V_10 == 8 )
{
F_5 ( V_3 , L_4 ,
V_11 [ 0 ] , V_11 [ 1 ] , V_11 [ 2 ] , V_11 [ 3 ] ,
V_11 [ 4 ] , V_11 [ 5 ] , V_11 [ 6 ] , V_11 [ 7 ] ) ;
}
else if( V_10 == 32 )
{
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ )
{
F_5 ( V_3 , L_5 , V_11 [ 0 ] << 8 | V_11 [ 1 ] ) ;
V_11 += 2 ;
if ( V_9 == 7 )
F_4 ( V_3 , L_6 ) ;
else if ( V_9 != 15 )
F_4 ( V_3 , L_7 ) ;
}
}
else
F_5 ( V_3 , L_8 ) ;
return 1 ;
}
