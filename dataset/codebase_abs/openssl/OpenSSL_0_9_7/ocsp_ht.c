T_1 * F_1 ( T_2 * V_1 , char * V_2 , T_3 * V_3 )
{
T_2 * V_4 = NULL ;
char V_5 [ 1024 ] ;
T_1 * V_6 = NULL ;
char * V_7 , * V_8 , * V_9 ;
int V_10 , V_11 ;
static char V_12 [] =
L_1 ;
V_10 = F_2 ( V_3 , NULL ) ;
if( F_3 ( V_1 , V_12 , V_2 , V_10 ) < 0 ) {
F_4 ( V_13 , V_14 ) ;
goto V_15;
}
if( F_5 ( V_1 , V_3 ) <= 0 ) {
F_4 ( V_13 , V_14 ) ;
goto V_15;
}
if( ! ( V_4 = F_6 ( F_7 () ) ) ) goto V_15;
while ( ( V_10 = F_8 ( V_1 , V_5 , sizeof V_5 ) ) ) {
if( V_10 < 0 ) {
F_4 ( V_13 , V_16 ) ;
goto V_15;
}
F_9 ( V_4 , V_5 , V_10 ) ;
}
if( F_10 ( V_4 , V_5 , 512 ) <= 0 ) {
F_4 ( V_13 , V_17 ) ;
goto V_15;
}
for( V_7 = V_5 ; * V_7 && ! isspace ( ( unsigned char ) * V_7 ) ; V_7 ++ ) continue;
if( ! * V_7 ) {
F_4 ( V_13 , V_17 ) ;
goto V_15;
}
while( * V_7 && isspace ( ( unsigned char ) * V_7 ) ) V_7 ++ ;
if( ! * V_7 ) {
F_4 ( V_13 , V_17 ) ;
goto V_15;
}
for( V_8 = V_7 ; * V_8 && ! isspace ( ( unsigned char ) * V_8 ) ; V_8 ++ ) continue;
if( ! * V_8 ) {
F_4 ( V_13 , V_17 ) ;
goto V_15;
}
* V_8 ++ = 0 ;
V_11 = strtoul ( V_7 , & V_9 , 10 ) ;
if( * V_9 ) goto V_15;
while( * V_8 && isspace ( ( unsigned char ) * V_8 ) ) V_8 ++ ;
if( ! * V_8 ) goto V_15;
for( V_9 = V_8 + strlen ( V_8 ) - 1 ; isspace ( ( unsigned char ) * V_9 ) ; V_9 -- ) * V_9 = 0 ;
if( V_11 != 200 ) {
F_4 ( V_13 , V_18 ) ;
F_11 ( 4 , L_2 , V_7 , L_3 , V_8 ) ;
goto V_15;
}
while( F_10 ( V_4 , V_5 , 512 ) > 0 )
{
for( V_7 = V_5 ; * V_7 && isspace ( ( unsigned char ) * V_7 ) ; V_7 ++ ) continue;
if( ! * V_7 ) break;
}
if( * V_7 ) {
F_4 ( V_13 , V_19 ) ;
goto V_15;
}
if( ! ( V_6 = F_12 ( V_4 , NULL ) ) ) {
F_4 ( V_13 , V_20 ) ;
goto V_15;
}
V_15:
F_13 ( V_4 ) ;
return V_6 ;
}
