int F_1 ( const char * V_1 , unsigned int * V_2 , int V_3 ,
unsigned int V_4 )
{
struct V_5 V_6 ;
struct V_7 V_8 ;
char * V_9 ;
char V_10 [] = L_1 ;
int V_11 ;
int V_12 ;
int V_13 , V_14 ;
unsigned int V_15 = 0 ;
V_12 = F_2 ( & V_9 , L_2 , V_1 ) ;
if ( V_12 < 0 )
return - V_16 ;
V_11 = F_3 ( V_9 , 0 ) ;
if ( V_11 == - 1 ) {
V_12 = - V_17 ;
fprintf ( V_18 , L_3 , V_9 ) ;
goto V_19;
}
for ( V_13 = 0 ; V_13 < V_3 ; V_13 ++ )
V_6 . V_20 [ V_13 ] = V_2 [ V_13 ] ;
V_6 . V_21 = V_22 ;
strcpy ( V_6 . V_23 , L_4 ) ;
V_6 . V_2 = V_3 ;
V_12 = F_4 ( V_11 , V_24 , & V_6 ) ;
if ( V_12 == - 1 ) {
V_12 = - V_17 ;
fprintf ( V_18 , L_5
L_6 ,
V_12 ) ;
goto V_19;
}
V_12 = F_4 ( V_6 . V_11 , V_25 , & V_8 ) ;
if ( V_12 == - 1 ) {
V_12 = - V_17 ;
fprintf ( V_18 , L_7
L_8 ,
V_12 ) ;
goto V_19;
}
fprintf ( stdout , L_9 ) ;
for ( V_13 = 0 ; V_13 < V_3 ; V_13 ++ ) {
fprintf ( stdout , L_10 , V_2 [ V_13 ] ) ;
if ( V_13 != ( V_3 - 1 ) )
fprintf ( stdout , L_11 ) ;
}
fprintf ( stdout , L_12 , V_1 ) ;
for ( V_13 = 0 ; V_13 < V_3 ; V_13 ++ ) {
fprintf ( stdout , L_10 , V_8 . V_26 [ V_13 ] ) ;
if ( V_13 != ( V_3 - 1 ) )
fprintf ( stdout , L_11 ) ;
}
fprintf ( stdout , L_13 ) ;
V_14 = 0 ;
while ( 1 ) {
for ( V_13 = 0 ; V_13 < V_3 ; V_13 ++ )
V_8 . V_26 [ V_13 ] = ! V_8 . V_26 [ V_13 ] ;
V_12 = F_4 ( V_6 . V_11 , V_27 , & V_8 ) ;
if ( V_12 == - 1 ) {
V_12 = - V_17 ;
fprintf ( V_18 , L_14
L_8 ,
V_12 ) ;
goto V_19;
}
V_12 = F_4 ( V_6 . V_11 , V_25 , & V_8 ) ;
if ( V_12 == - 1 ) {
V_12 = - V_17 ;
fprintf ( V_18 , L_7
L_8 ,
V_12 ) ;
goto V_19;
}
fprintf ( stdout , L_15 , V_10 [ V_14 ] ) ;
V_14 ++ ;
if ( V_14 == sizeof( V_10 ) - 1 )
V_14 = 0 ;
fprintf ( stdout , L_16 ) ;
for ( V_13 = 0 ; V_13 < V_3 ; V_13 ++ ) {
fprintf ( stdout , L_17 , V_2 [ V_13 ] , V_8 . V_26 [ V_13 ] ) ;
if ( V_13 != ( V_3 - 1 ) )
fprintf ( stdout , L_11 ) ;
}
fprintf ( stdout , L_18 ) ;
fflush ( stdout ) ;
F_5 ( 1 ) ;
V_15 ++ ;
if ( V_4 && V_15 == V_4 )
break;
}
fprintf ( stdout , L_19 ) ;
V_12 = 0 ;
V_19:
if ( F_6 ( V_11 ) == - 1 )
perror ( L_20 ) ;
free ( V_9 ) ;
return V_12 ;
}
void F_7 ( void )
{
fprintf ( V_18 , L_21
L_22
L_23
L_24
L_25
L_26
L_19
L_27
L_28
) ;
}
int main ( int V_28 , char * * V_29 )
{
const char * V_1 = NULL ;
unsigned int V_2 [ V_30 ] ;
unsigned int V_4 = 0 ;
int V_3 ;
int V_31 ;
int V_13 ;
V_13 = 0 ;
while ( ( V_31 = F_8 ( V_28 , V_29 , L_29 ) ) != - 1 ) {
switch ( V_31 ) {
case 'c' :
V_4 = strtoul ( V_32 , NULL , 10 ) ;
break;
case 'n' :
V_1 = V_32 ;
break;
case 'o' :
V_2 [ V_13 ] = strtoul ( V_32 , NULL , 10 ) ;
V_13 ++ ;
break;
case '?' :
F_7 () ;
return - 1 ;
}
}
V_3 = V_13 ;
if ( ! V_1 || ! V_3 ) {
F_7 () ;
return - 1 ;
}
return F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
