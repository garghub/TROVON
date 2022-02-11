static void
F_1 ( T_1 * V_1 , const char * V_2 )
{
while ( * V_2 ) {
if ( * V_2 == '"' )
fprintf ( V_1 , L_1 ) ;
else
fputc ( * V_2 , V_1 ) ;
V_2 ++ ;
}
}
int
main ( void )
{
char line [ 1024 ] , * V_2 , * V_3 , V_4 [ 8 ] ;
int V_5 = 0 ;
int V_6 = 0 ;
int V_7 = 0 ;
int V_8 = 0 ;
T_1 * V_9 ;
V_9 = fopen ( L_2 , L_3 ) ;
if ( ! V_9 ) {
fprintf ( V_10 , L_4 ) ;
return 1 ;
}
while ( fgets ( line , sizeof( line ) - 1 , V_11 ) ) {
V_7 ++ ;
if ( ( V_2 = strchr ( line , '\n' ) ) )
* V_2 = 0 ;
if ( ! line [ 0 ] || line [ 0 ] == '#' )
continue;
if ( line [ 0 ] == '\t' ) {
switch ( V_6 ) {
case 1 :
if ( strlen ( line ) > 5 && line [ 5 ] == ' ' ) {
V_2 = line + 5 ;
while ( * V_2 == ' ' )
* V_2 ++ = 0 ;
if ( V_8 + strlen ( V_2 ) + 1 > V_12 ) {
V_3 = strchr ( V_2 , '[' ) ;
if ( V_3 && V_3 > V_2 && V_3 [ - 1 ] == ' ' )
V_3 [ - 1 ] = 0 ;
if ( V_8 + strlen ( V_2 ) + 1 > V_12 ) {
fprintf ( V_10 , L_5 , V_7 ) ;
return 1 ;
}
}
fprintf ( V_9 , L_6 , V_4 , line + 1 ) ;
F_1 ( V_9 , V_2 ) ;
fputs ( L_7 , V_9 ) ;
} else goto V_13;
break;
default:
goto V_13;
}
} else if ( strlen ( line ) > 4 && line [ 4 ] == ' ' ) {
V_2 = line + 4 ;
while ( * V_2 == ' ' )
* V_2 ++ = 0 ;
if ( V_5 )
fputs ( L_8 , V_9 ) ;
V_5 ++ ;
strcpy ( V_4 , line ) ;
V_8 = strlen ( V_2 ) ;
if ( V_8 + 24 > V_12 ) {
fprintf ( V_10 , L_9 , V_7 ) ;
return 1 ;
}
fprintf ( V_9 , L_10 , V_4 ) ;
F_1 ( V_9 , V_2 ) ;
fputs ( L_7 , V_9 ) ;
V_6 = 1 ;
} else {
V_13:
fprintf ( V_10 , L_11 , V_7 , V_6 , line ) ;
return 1 ;
}
}
fputs ( L_12 , V_9 ) ;
fclose ( V_9 ) ;
return 0 ;
}
