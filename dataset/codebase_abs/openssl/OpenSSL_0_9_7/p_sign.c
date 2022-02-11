void F_1 ( T_1 * V_1 , T_2 * type )
{
F_2 ( V_1 , type ) ;
}
void F_3 ( T_1 * V_1 , unsigned char * V_2 ,
unsigned int V_3 )
{
F_4 ( V_1 , V_2 , V_3 ) ;
}
int F_5 ( T_1 * V_1 , unsigned char * V_4 , unsigned int * V_5 ,
T_3 * V_6 )
{
unsigned char V_7 [ V_8 ] ;
unsigned int V_9 ;
int V_10 , V_11 = 0 , V_12 ;
T_4 T_1 V_13 ;
* V_5 = 0 ;
F_6 ( & V_13 ) ;
F_7 ( & V_13 , V_1 ) ;
F_8 ( & V_13 , & ( V_7 [ 0 ] ) , & V_9 ) ;
F_9 ( & V_13 ) ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
{
V_12 = V_1 -> V_14 -> V_15 [ V_10 ] ;
if ( V_12 == 0 ) break;
if ( V_6 -> type == V_12 )
{
V_11 = 1 ;
break;
}
}
if ( ! V_11 )
{
F_10 ( V_16 , V_17 ) ;
return ( 0 ) ;
}
if ( V_1 -> V_14 -> V_18 == NULL )
{
F_10 ( V_16 , V_19 ) ;
return ( 0 ) ;
}
return ( V_1 -> V_14 -> V_18 ( V_1 -> V_14 -> type , V_7 , V_9 , V_4 , V_5 ,
V_6 -> V_6 . V_20 ) ) ;
}
