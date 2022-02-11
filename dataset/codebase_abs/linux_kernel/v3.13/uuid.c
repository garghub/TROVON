static inline T_1 F_1 ( int V_1 , T_2 * * V_2 )
{
T_1 V_3 ;
F_2 ( V_1 <= sizeof( V_3 ) ) ;
for ( V_3 = 0 ; V_1 > 0 ; -- V_1 )
V_3 = ( V_3 << 8 ) | * ( ( * V_2 ) ++ ) ;
return V_3 ;
}
static void F_3 ( T_3 V_4 , T_4 * V_5 , int V_6 )
{
T_2 * V_2 = V_4 ;
F_2 ( V_6 * sizeof( * V_5 ) == sizeof( T_3 ) ) ;
while ( V_6 -- > 0 )
F_4 ( V_5 [ V_6 ] , & V_2 ) ;
}
void F_5 ( T_3 V_5 , struct V_7 * V_8 )
{
T_4 V_9 [ sizeof( T_3 ) / sizeof( T_4 ) ] ;
F_6 ( F_7 ( V_9 ) == 8 ) ;
F_3 ( V_5 , V_9 , F_7 ( V_9 ) ) ;
sprintf ( V_8 -> V_9 , L_1 ,
V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] ,
V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
}
