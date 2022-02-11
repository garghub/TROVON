int F_1 ( const char * V_1 , unsigned int * V_2 , int V_3 ,
unsigned int V_4 )
{
struct V_5 V_6 ;
char V_7 [] = L_1 ;
int V_8 ;
int V_9 ;
int V_10 , V_11 ;
unsigned int V_12 = 0 ;
memset ( & V_6 . V_13 , 0 , sizeof( V_6 . V_13 ) ) ;
V_9 = F_2 ( V_1 , V_2 , V_3 ,
V_14 , & V_6 ,
L_2 ) ;
if ( V_9 < 0 )
goto V_15;
else
V_8 = V_9 ;
V_9 = F_3 ( V_8 , & V_6 ) ;
if ( V_9 < 0 )
goto V_16;
fprintf ( stdout , L_3 ) ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ ) {
fprintf ( stdout , L_4 , V_2 [ V_10 ] ) ;
if ( V_10 != ( V_3 - 1 ) )
fprintf ( stdout , L_5 ) ;
}
fprintf ( stdout , L_6 , V_1 ) ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ ) {
fprintf ( stdout , L_4 , V_6 . V_13 [ V_10 ] ) ;
if ( V_10 != ( V_3 - 1 ) )
fprintf ( stdout , L_5 ) ;
}
fprintf ( stdout , L_7 ) ;
V_11 = 0 ;
while ( 1 ) {
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
V_6 . V_13 [ V_10 ] = ! V_6 . V_13 [ V_10 ] ;
V_9 = F_4 ( V_8 , & V_6 ) ;
if ( V_9 < 0 )
goto V_16;
V_9 = F_3 ( V_8 , & V_6 ) ;
if ( V_9 < 0 )
goto V_16;
fprintf ( stdout , L_8 , V_7 [ V_11 ] ) ;
V_11 ++ ;
if ( V_11 == sizeof( V_7 ) - 1 )
V_11 = 0 ;
fprintf ( stdout , L_9 ) ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ ) {
fprintf ( stdout , L_10 , V_2 [ V_10 ] , V_6 . V_13 [ V_10 ] ) ;
if ( V_10 != ( V_3 - 1 ) )
fprintf ( stdout , L_5 ) ;
}
fprintf ( stdout , L_11 ) ;
fflush ( stdout ) ;
F_5 ( 1 ) ;
V_12 ++ ;
if ( V_4 && V_12 == V_4 )
break;
}
fprintf ( stdout , L_12 ) ;
V_9 = 0 ;
V_16:
F_6 ( V_8 ) ;
V_15:
return V_9 ;
}
void F_7 ( void )
{
fprintf ( V_17 , L_13
L_14
L_15
L_16
L_17
L_18
L_12
L_19
L_20
) ;
}
int main ( int V_18 , char * * V_19 )
{
const char * V_1 = NULL ;
unsigned int V_2 [ V_20 ] ;
unsigned int V_4 = 0 ;
int V_3 ;
int V_21 ;
int V_10 ;
V_10 = 0 ;
while ( ( V_21 = F_8 ( V_18 , V_19 , L_21 ) ) != - 1 ) {
switch ( V_21 ) {
case 'c' :
V_4 = strtoul ( V_22 , NULL , 10 ) ;
break;
case 'n' :
V_1 = V_22 ;
break;
case 'o' :
V_2 [ V_10 ] = strtoul ( V_22 , NULL , 10 ) ;
V_10 ++ ;
break;
case '?' :
F_7 () ;
return - 1 ;
}
}
V_3 = V_10 ;
if ( ! V_1 || ! V_3 ) {
F_7 () ;
return - 1 ;
}
return F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
