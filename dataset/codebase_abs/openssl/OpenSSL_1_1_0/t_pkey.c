int F_1 ( T_1 * V_1 , const unsigned char * V_2 , T_2 V_3 , int V_4 )
{
T_2 V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
if ( ( V_5 % V_6 ) == 0 ) {
if ( V_5 > 0 && F_2 ( V_1 , L_1 ) <= 0 )
return 0 ;
if ( ! F_3 ( V_1 , V_4 , V_7 ) )
return 0 ;
}
if ( F_4 ( V_1 , L_2 , V_2 [ V_5 ] ,
( V_5 == V_3 - 1 ) ? L_3 : L_4 ) <= 0 )
return 0 ;
}
if ( F_5 ( V_1 , L_1 , 1 ) <= 0 )
return 0 ;
return 1 ;
}
int F_6 ( T_1 * V_1 , const char * V_8 , const T_3 * V_9 ,
unsigned char * V_10 , int V_4 )
{
int V_11 , V_12 = 0 ;
const char * V_13 ;
unsigned char * V_2 = NULL , * V_14 = NULL ;
int V_3 ;
if ( V_9 == NULL )
return 1 ;
V_13 = F_7 ( V_9 ) ? L_5 : L_3 ;
if ( ! F_3 ( V_1 , V_4 , V_7 ) )
return 0 ;
if ( F_8 ( V_9 ) ) {
if ( F_4 ( V_1 , L_6 , V_8 ) <= 0 )
return 0 ;
return 1 ;
}
if ( F_9 ( V_9 ) <= V_15 ) {
if ( F_4 ( V_1 , L_7 , V_8 , V_13 ,
( unsigned long ) F_10 ( V_9 ) [ 0 ] , V_13 ,
( unsigned long ) F_10 ( V_9 ) [ 0 ] ) <= 0 )
return 0 ;
return 1 ;
}
V_3 = F_9 ( V_9 ) + 1 ;
V_2 = V_14 = F_11 ( V_3 ) ;
if ( V_2 == NULL )
goto V_16;
V_2 [ 0 ] = 0 ;
if ( F_4 ( V_1 , L_8 , V_8 ,
( V_13 [ 0 ] == '-' ) ? L_9 : L_3 ) <= 0 )
goto V_16;
V_11 = F_12 ( V_9 , V_2 + 1 ) ;
if ( V_2 [ 1 ] & 0x80 )
V_11 ++ ;
else
V_14 ++ ;
if ( F_1 ( V_1 , V_14 , V_11 , V_4 + 4 ) == 0 )
goto V_16;
V_12 = 1 ;
V_16:
F_13 ( V_2 , V_3 ) ;
return V_12 ;
}
