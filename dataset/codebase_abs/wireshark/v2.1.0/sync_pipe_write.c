T_1
F_1 ( int V_1 , char V_2 , int V_3 )
{
T_2 V_4 [ 1 + 3 ] ;
F_2 ( V_3 <= V_5 ) ;
V_4 [ 0 ] = V_2 ;
V_4 [ 1 ] = ( V_3 >> 16 ) & 0xFF ;
V_4 [ 2 ] = ( V_3 >> 8 ) & 0xFF ;
V_4 [ 3 ] = ( V_3 >> 0 ) & 0xFF ;
return F_3 ( V_1 , V_4 , sizeof V_4 ) ;
}
void
F_4 ( int V_1 , char V_2 , const char * V_6 )
{
T_1 V_7 ;
int V_8 ;
if( V_6 != NULL ) {
V_8 = ( int ) strlen ( V_6 ) + 1 ;
} else {
V_8 = 0 ;
}
V_7 = F_1 ( V_1 , V_2 , V_8 ) ;
if( V_7 == - 1 ) {
return;
}
if( V_8 ) {
V_7 = F_3 ( V_1 , V_6 , V_8 ) ;
if( V_7 == - 1 ) {
return;
}
} else {
}
}
void
F_5 ( int V_1 , const char * V_9 ,
const char * V_10 )
{
F_1 ( V_1 , V_11 , ( int ) ( strlen ( V_9 ) + 1 + 4 + strlen ( V_10 ) + 1 + 4 ) ) ;
F_4 ( V_1 , V_11 , V_9 ) ;
F_4 ( V_1 , V_11 , V_10 ) ;
}
