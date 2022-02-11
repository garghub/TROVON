void F_1 ()
{
fprintf ( V_1 , L_1
L_2
L_3
L_4
L_5
L_6
L_7 ) ;
exit ( 3 ) ;
}
int main ( int V_2 , char * * V_3 )
{
int V_4 , V_5 ;
int V_6 = 0 ;
int V_7 = 0 ;
int V_8 = V_9 ;
T_1 * V_10 = & V_11 ;
T_2 * V_12 = NULL ;
T_3 V_13 ;
while( ( V_4 = F_2 ( V_2 , V_3 , L_8 ) ) != - 1 )
{
switch ( V_4 )
{
case 'v' : V_6 = 1 ; break;
case 't' : V_10 = & V_14 ; break;
case 'b' : V_8 |= V_15 ; break;
case 'c' :
if ( V_16 )
{
V_12 = fopen ( V_16 , L_9 ) ;
if ( ! V_12 )
{
perror ( V_16 ) ;
exit ( 2 ) ;
}
}
else
{
V_12 = V_17 ;
}
break;
default:
fprintf ( V_1 , L_10 , V_18 ) ;
F_1 () ;
}
}
F_3 ( & V_13 , V_10 ) ;
if ( V_12 )
{
char V_19 [ 65 ] , V_20 [ 65 ] , V_21 [ V_22 ] ;
int V_23 = 0 , V_24 = 0 ; ;
if ( V_12 == V_17 && V_25 < V_2 )
{
V_12 = fopen ( V_3 [ V_25 ] , L_9 ) ;
if ( ! V_12 )
{
perror ( V_3 [ V_25 ] ) ;
exit ( 2 ) ;
}
}
while ( F_4 ( V_12 , V_19 , V_21 ) )
{
if ( ! F_5 ( & V_13 , V_21 , V_20 , V_8 ) )
{
exit ( 2 ) ;
}
V_24 ++ ;
if ( ! strncmp ( V_20 , V_19 , 65 ) )
{
if ( V_6 )
{
fprintf ( V_1 , L_11 , V_21 ) ;
}
}
else
{
if ( V_6 )
{
fprintf ( V_1 , L_12 , V_21 ) ;
}
else
{
fprintf ( V_1 , L_13 ,
V_3 [ 0 ] , V_21 ) ;
}
V_23 ++ ;
}
}
if ( V_6 && V_23 )
{
fprintf ( V_1 , L_14 ,
V_3 [ 0 ] , V_23 , V_24 ) ;
}
exit ( V_23 ? 1 : 0 ) ;
}
if ( V_25 == V_2 )
{
char V_26 [ 65 ] ;
if ( ! F_6 ( & V_13 , fileno ( V_17 ) , V_26 ) )
{
perror ( L_15 ) ;
exit ( 1 ) ;
}
printf ( L_16 , V_26 ) ;
exit ( 0 ) ;
}
for ( V_5 = V_25 ; V_5 < V_2 ; V_5 ++ )
{
char V_26 [ 65 ] ;
if ( ! F_5 ( & V_13 , V_3 [ V_5 ] , V_26 , V_8 ) )
{
V_7 ++ ;
}
else
{
printf ( L_17 , V_26 , V_3 [ V_5 ] ) ;
}
}
exit ( V_7 ? 1 : 0 ) ;
}
int F_5 ( T_3 * V_13 , char * V_21 , char * V_26 , int V_27 )
{
int V_28 ;
if ( ( V_28 = F_7 ( V_21 , V_27 ) ) < 0 )
{
perror ( V_21 ) ;
return 0 ;
}
if ( ! F_6 ( V_13 , V_28 , V_26 ) )
{
perror ( V_21 ) ;
return 0 ;
}
F_8 ( V_28 ) ;
return 1 ;
}
int F_6 ( T_3 * V_13 , int V_28 , char * V_26 )
{
unsigned char V_29 [ V_30 ] ;
T_4 V_31 ;
int V_5 ;
F_9 ( V_13 ) ;
while ( ( V_31 = F_10 ( V_28 , V_29 , V_30 ) ) > 0 )
{
F_11 ( V_13 , V_29 , V_31 ) ;
}
if ( V_31 < 0 )
{
return 0 ;
}
F_12 ( V_13 , V_29 ) ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ )
{
sprintf ( V_26 + 2 * V_5 , L_18 , V_29 [ 31 - V_5 ] ) ;
}
return 1 ;
}
int F_4 ( T_2 * V_32 , char * V_33 , char * V_21 )
{
int V_5 ;
if ( fread ( V_33 , 1 , 64 , V_32 ) < 64 ) return 0 ;
V_33 [ 64 ] = 0 ;
for ( V_5 = 0 ; V_5 < 64 ; V_5 ++ )
{
if ( V_33 [ V_5 ] < '0' || ( V_33 [ V_5 ] > '9' && V_33 [ V_5 ] < 'A' ) || ( V_33 [ V_5 ] > 'F'
&& V_33 [ V_5 ] < 'a' ) || V_33 [ V_5 ] > 'f' )
{
fprintf ( V_1 , L_19 , V_33 ) ;
return 0 ;
}
}
if ( fgetc ( V_32 ) != ' ' )
{
fprintf ( V_1 , L_20 ) ;
return 0 ;
}
V_5 = strlen ( fgets ( V_21 , V_22 , V_32 ) ) ;
while ( V_21 [ -- V_5 ] == '\n' || V_21 [ V_5 ] == '\r' ) V_21 [ V_5 ] = 0 ;
return 1 ;
}
