int main ( T_1 , T_2 )
int T_1 ;
char * T_2 [] ;
{
char * V_1 = NULL ;
T_3 * V_2 ;
T_4 * V_3 ;
T_5 * V_4 ;
T_6 * V_5 ;
T_7 * V_6 ;
T_8 V_7 ;
T_9 * V_8 = NULL ;
T_3 * V_9 , * V_10 = NULL , * V_11 = NULL ;
char V_12 [ 1024 * 4 ] ;
unsigned char * V_13 ;
int V_14 , V_15 = 0 ;
F_1 ( T_7 ) * V_16 ;
F_2 () ;
V_17 = F_3 ( V_18 , V_19 ) ;
V_9 = F_4 ( F_5 () ) ;
V_13 = NULL ;
while ( T_1 > 1 )
{
T_1 -- ;
T_2 ++ ;
if ( strcmp ( T_2 [ 0 ] , L_1 ) == 0 )
{
V_15 = 1 ;
}
else if ( ( strcmp ( T_2 [ 0 ] , L_2 ) == 0 ) && ( T_1 >= 2 ) ) {
V_1 = T_2 [ 1 ] ;
T_1 -= 1 ;
T_2 += 1 ;
} else if ( ( strcmp ( T_2 [ 0 ] , L_3 ) == 0 ) && ( T_1 >= 2 ) )
{
V_10 = F_4 ( F_5 () ) ;
if ( ! F_6 ( V_10 , T_2 [ 1 ] ) )
goto V_20;
T_1 -= 1 ;
T_2 += 1 ;
}
else break;
}
if ( ! F_6 ( V_9 , T_2 [ 0 ] ) ) goto V_20;
if( ! V_1 ) {
fprintf ( V_18 , L_4 ) ;
goto V_20;
}
if ( ( V_2 = F_7 ( V_1 , L_5 ) ) == NULL ) goto V_20;
if ( ( V_4 = F_8 ( V_2 , NULL , NULL , NULL ) ) == NULL ) goto V_20;
F_9 ( V_2 ) ;
if ( ( V_3 = F_10 ( V_2 , NULL , NULL , NULL ) ) == NULL )
goto V_20;
F_11 ( V_2 ) ;
if ( V_13 == NULL )
F_12 ( V_9 , V_21 , V_19 ) ;
if ( ( V_5 = F_13 ( V_9 , NULL , NULL , NULL ) ) == NULL ) goto V_20;
V_8 = F_14 () ;
F_15 ( V_8 ) ;
F_16 ( V_8 , NULL , L_6 ) ;
F_17 ( V_8 , V_22 ) ;
F_18 () ;
V_11 = F_19 ( V_5 , V_3 , V_10 , V_4 ) ;
if ( V_11 == NULL )
{
printf ( L_7 ) ;
goto V_20;
}
for (; ; )
{
V_14 = F_20 ( V_11 , V_12 , sizeof( V_12 ) ) ;
if ( V_14 <= 0 ) break;
fwrite ( V_12 , 1 , V_14 , stdout ) ;
}
V_16 = F_21 ( V_5 ) ;
if ( V_16 == NULL )
{
fprintf ( V_18 , L_8 ) ;
}
else
{
F_18 () ;
for ( V_14 = 0 ; V_14 < F_22 ( V_16 ) ; V_14 ++ )
{
V_6 = F_23 ( V_16 , V_14 ) ;
V_14 = F_24 ( V_8 , & V_7 , V_11 , V_5 , V_6 ) ;
if ( V_14 <= 0 )
goto V_20;
else
fprintf ( V_18 , L_9 ) ;
}
}
F_25 ( V_8 ) ;
exit ( 0 ) ;
V_20:
F_26 () ;
F_27 ( V_18 ) ;
exit ( 1 ) ;
}
int V_22 ( int V_23 , T_8 * V_24 )
{
char V_12 [ 256 ] ;
T_5 * V_25 ;
int V_20 , V_26 ;
V_25 = F_28 ( V_24 ) ;
V_20 = F_29 ( V_24 ) ;
V_26 = F_30 ( V_24 ) ;
F_31 ( F_32 ( V_25 ) , V_12 , 256 ) ;
F_33 ( V_17 , L_10 , V_26 , V_12 ) ;
if ( ! V_23 )
{
F_33 ( V_17 , L_11 , V_20 ,
F_34 ( V_20 ) ) ;
if ( V_26 < 6 )
{
V_23 = 1 ;
F_35 ( V_24 , V_27 ) ;
}
else
{
V_23 = 0 ;
F_35 ( V_24 , V_28 ) ;
}
}
switch ( V_24 -> error )
{
case V_29 :
F_31 ( F_36 ( V_24 -> V_30 ) , V_12 , 256 ) ;
F_33 ( V_17 , L_12 , V_12 ) ;
break;
case V_31 :
case V_32 :
F_33 ( V_17 , L_13 ) ;
F_37 ( V_17 , F_38 ( V_24 -> V_30 ) ) ;
F_33 ( V_17 , L_14 ) ;
break;
case V_33 :
case V_34 :
F_33 ( V_17 , L_15 ) ;
F_37 ( V_17 , F_39 ( V_24 -> V_30 ) ) ;
F_33 ( V_17 , L_14 ) ;
break;
}
F_33 ( V_17 , L_16 , V_23 ) ;
return ( V_23 ) ;
}
