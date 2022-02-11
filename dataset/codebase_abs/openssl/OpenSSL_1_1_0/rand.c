int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
char * V_4 = NULL , * V_5 = NULL , * V_6 ;
T_2 V_7 ;
int V_8 = V_9 , V_10 , V_11 = - 1 , V_12 , V_13 = 1 ;
V_6 = F_2 ( V_1 , V_2 , V_14 ) ;
while ( ( V_7 = F_3 () ) != V_15 ) {
switch ( V_7 ) {
case V_15 :
case V_16 :
V_17:
F_4 ( V_18 , L_1 , V_6 ) ;
goto V_19;
case V_20 :
F_5 ( V_14 ) ;
V_13 = 0 ;
goto V_19;
case V_21 :
V_5 = F_6 () ;
break;
case V_22 :
( void ) F_7 ( F_6 () , 0 ) ;
break;
case V_23 :
V_4 = F_6 () ;
break;
case V_24 :
V_8 = V_25 ;
break;
case V_26 :
V_8 = V_27 ;
break;
}
}
V_1 = F_8 () ;
V_2 = F_9 () ;
if ( V_1 != 1 || ! F_10 ( V_2 [ 0 ] , & V_11 ) || V_11 < 0 )
goto V_17;
F_11 ( NULL , ( V_4 != NULL ) ) ;
if ( V_4 != NULL )
F_4 ( V_18 , L_2 ,
F_12 ( V_4 ) ) ;
V_3 = F_13 ( V_5 , 'w' , V_8 ) ;
if ( V_3 == NULL )
goto V_19;
if ( V_8 == V_25 ) {
T_1 * V_28 = F_14 ( F_15 () ) ;
if ( V_28 == NULL )
goto V_19;
V_3 = F_16 ( V_28 , V_3 ) ;
}
while ( V_11 > 0 ) {
unsigned char V_29 [ 4096 ] ;
int V_30 ;
V_30 = V_11 ;
if ( V_30 > ( int ) sizeof( V_29 ) )
V_30 = sizeof V_29 ;
V_12 = F_17 ( V_29 , V_30 ) ;
if ( V_12 <= 0 )
goto V_19;
if ( V_8 != V_27 ) {
if ( F_18 ( V_3 , V_29 , V_30 ) != V_30 )
goto V_19;
} else {
for ( V_10 = 0 ; V_10 < V_30 ; V_10 ++ )
if ( F_4 ( V_3 , L_3 , V_29 [ V_10 ] ) != 2 )
goto V_19;
}
V_11 -= V_30 ;
}
if ( V_8 == V_27 )
F_19 ( V_3 , L_4 ) ;
if ( F_20 ( V_3 ) <= 0 || ! F_21 ( NULL ) )
goto V_19;
V_13 = 0 ;
V_19:
if ( V_13 != 0 )
F_22 ( V_18 ) ;
F_23 ( V_3 ) ;
return ( V_13 ) ;
}
