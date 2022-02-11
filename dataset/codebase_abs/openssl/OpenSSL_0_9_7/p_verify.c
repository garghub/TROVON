int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
unsigned int V_3 , T_2 * V_4 )
{
unsigned char V_5 [ V_6 ] ;
unsigned int V_7 ;
int V_8 , V_9 = 0 , V_10 ;
T_3 T_1 V_11 ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ )
{
V_10 = V_1 -> V_12 -> V_13 [ V_8 ] ;
if ( V_10 == 0 ) break;
if ( V_4 -> type == V_10 )
{
V_9 = 1 ;
break;
}
}
if ( ! V_9 )
{
F_2 ( V_14 , V_15 ) ;
return ( - 1 ) ;
}
F_3 ( & V_11 ) ;
F_4 ( & V_11 , V_1 ) ;
F_5 ( & V_11 , & ( V_5 [ 0 ] ) , & V_7 ) ;
F_6 ( & V_11 ) ;
if ( V_1 -> V_12 -> V_16 == NULL )
{
F_2 ( V_14 , V_17 ) ;
return ( 0 ) ;
}
return ( V_1 -> V_12 -> V_16 ( V_1 -> V_12 -> type , V_5 , V_7 ,
V_2 , V_3 , V_4 -> V_4 . V_18 ) ) ;
}
