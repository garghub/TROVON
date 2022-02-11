int F_1 ( unsigned char * V_1 , T_1 V_2 ,
const unsigned char * V_3 , T_1 V_4 ,
const unsigned char * V_5 , T_1 V_6 ,
const T_2 * V_7 )
{
T_3 V_8 ;
int V_9 = 0 ;
unsigned int V_10 ;
T_1 V_11 ;
unsigned char V_12 [ 4 ] ;
if ( V_6 > V_13 || V_2 > V_13
|| V_4 > V_13 )
return 0 ;
V_11 = F_2 ( V_7 ) ;
F_3 ( & V_8 ) ;
for ( V_10 = 1 ; ; V_10 ++ ) {
unsigned char V_14 [ V_15 ] ;
F_4 ( & V_8 , V_7 , NULL ) ;
V_12 [ 3 ] = V_10 & 0xFF ;
V_12 [ 2 ] = ( V_10 >> 8 ) & 0xFF ;
V_12 [ 1 ] = ( V_10 >> 16 ) & 0xFF ;
V_12 [ 0 ] = ( V_10 >> 24 ) & 0xFF ;
if ( ! F_5 ( & V_8 , V_3 , V_4 ) )
goto V_16;
if ( ! F_5 ( & V_8 , V_12 , sizeof( V_12 ) ) )
goto V_16;
if ( ! F_5 ( & V_8 , V_5 , V_6 ) )
goto V_16;
if ( V_2 >= V_11 ) {
if ( ! F_6 ( & V_8 , V_1 , NULL ) )
goto V_16;
V_2 -= V_11 ;
if ( V_2 == 0 )
break;
V_1 += V_11 ;
} else {
if ( ! F_6 ( & V_8 , V_14 , NULL ) )
goto V_16;
memcpy ( V_1 , V_14 , V_2 ) ;
F_7 ( V_14 , V_11 ) ;
break;
}
}
V_9 = 1 ;
V_16:
F_8 ( & V_8 ) ;
return V_9 ;
}
