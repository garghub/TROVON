static void F_1 ( char * V_1 )
{
fprintf ( V_2 , L_1
L_2 , V_1 ) ;
exit ( V_3 ) ;
}
static int F_2 ( char * * V_4 )
{
char * V_5 = * V_4 ;
while ( * V_5 == ' ' || * V_5 == '\t' )
V_5 ++ ;
if ( * V_5 != 'U' || V_5 [ 1 ] != '+' ||
! isxdigit ( V_5 [ 2 ] ) || ! isxdigit ( V_5 [ 3 ] ) || ! isxdigit ( V_5 [ 4 ] ) ||
! isxdigit ( V_5 [ 5 ] ) || isxdigit ( V_5 [ 6 ] ) )
return - 1 ;
* V_4 = V_5 + 6 ;
return strtol ( V_5 + 2 , 0 , 16 ) ;
}
static void F_3 ( int V_6 , int V_7 )
{
int V_8 ;
if ( V_7 <= 0xfffe )
{
for ( V_8 = 0 ; V_8 < V_9 [ V_6 ] ; V_8 ++ )
if ( V_10 [ V_6 ] [ V_8 ] == V_7 )
return;
if ( V_9 [ V_6 ] > 254 )
{
fprintf ( V_2 , L_3 ) ;
exit ( V_11 ) ;
}
V_10 [ V_6 ] [ V_9 [ V_6 ] ] = V_7 ;
V_9 [ V_6 ] ++ ;
}
}
int main ( int V_12 , char * V_13 [] )
{
T_1 * V_14 ;
char * V_15 ;
char V_16 [ 65536 ] ;
int V_17 ;
int V_8 , V_18 , V_19 ;
int V_20 , V_21 , V_22 , V_23 ;
char * V_5 , * V_24 ;
if ( V_12 < 2 || V_12 > 5 )
F_1 ( V_13 [ 0 ] ) ;
if ( ! strcmp ( V_13 [ 1 ] , L_4 ) )
{
V_14 = V_25 ;
V_15 = L_5 ;
}
else
{
V_14 = fopen ( V_15 = V_13 [ 1 ] , L_6 ) ;
if ( ! V_14 )
{
perror ( V_15 ) ;
exit ( V_26 ) ;
}
}
V_17 = 256 ;
for ( V_8 = 0 ; V_8 < V_17 ; V_8 ++ )
V_9 [ V_8 ] = 0 ;
while ( fgets ( V_16 , sizeof( V_16 ) , V_14 ) != NULL )
{
if ( ( V_5 = strchr ( V_16 , '\n' ) ) != NULL )
* V_5 = '\0' ;
else
fprintf ( V_2 , L_7 , V_15 ) ;
V_5 = V_16 ;
while ( * V_5 == ' ' || * V_5 == '\t' )
V_5 ++ ;
if ( ! * V_5 || * V_5 == '#' )
continue;
V_20 = strtol ( V_5 , & V_24 , 0 ) ;
if ( V_24 == V_5 )
{
fprintf ( V_2 , L_8 , V_16 ) ;
exit ( V_11 ) ;
}
V_5 = V_24 ;
while ( * V_5 == ' ' || * V_5 == '\t' )
V_5 ++ ;
if ( * V_5 == '-' )
{
V_5 ++ ;
V_21 = strtol ( V_5 , & V_24 , 0 ) ;
if ( V_24 == V_5 )
{
fprintf ( V_2 , L_8 , V_16 ) ;
exit ( V_11 ) ;
}
V_5 = V_24 ;
}
else
V_21 = 0 ;
if ( V_20 < 0 || V_20 >= V_17 )
{
fprintf ( V_2 ,
L_9 ,
V_15 , V_20 ) ;
exit ( V_11 ) ;
}
if ( V_21 && ( V_21 < V_20 || V_21 >= V_17 ) )
{
fprintf ( V_2 ,
L_10 ,
V_15 , V_21 ) ;
exit ( V_11 ) ;
}
if ( V_21 )
{
while ( * V_5 == ' ' || * V_5 == '\t' )
V_5 ++ ;
if ( ! strncmp ( V_5 , L_11 , 4 ) )
{
for ( V_8 = V_20 ; V_8 <= V_21 ; V_8 ++ )
F_3 ( V_8 , V_8 ) ;
V_5 += 4 ;
}
else
{
V_22 = F_2 ( & V_5 ) ;
while ( * V_5 == ' ' || * V_5 == '\t' )
V_5 ++ ;
if ( * V_5 != '-' )
{
fprintf ( V_2 ,
L_12 ,
V_15 ) ;
exit ( V_11 ) ;
}
V_5 ++ ;
V_23 = F_2 ( & V_5 ) ;
if ( V_22 < 0 || V_23 < 0 )
{
fprintf ( V_2 ,
L_13 ,
V_15 , V_20 , V_21 ) ;
exit ( V_11 ) ;
}
if ( V_23 - V_22 != V_21 - V_20 )
{
fprintf ( V_2 ,
L_14 ,
V_15 , V_22 , V_23 , V_20 , V_21 ) ;
exit ( V_11 ) ;
}
for( V_8 = V_20 ; V_8 <= V_21 ; V_8 ++ )
F_3 ( V_8 , V_22 - V_20 + V_8 ) ;
}
}
else
{
while ( ( V_22 = F_2 ( & V_5 ) ) >= 0 )
F_3 ( V_20 , V_22 ) ;
}
while ( * V_5 == ' ' || * V_5 == '\t' )
V_5 ++ ;
if ( * V_5 && * V_5 != '#' )
fprintf ( V_2 , L_15 , V_15 , V_5 ) ;
}
fclose ( V_14 ) ;
V_18 = 0 ;
for ( V_8 = 0 ; V_8 < V_17 ; V_8 ++ )
V_18 += V_9 [ V_8 ] ;
printf ( L_16 , V_13 [ 1 ] , V_17 ) ;
for ( V_8 = 0 ; V_8 < V_17 ; V_8 ++ )
{
printf ( L_17 , V_9 [ V_8 ] ) ;
if ( V_8 == V_17 - 1 )
printf ( L_18 ) ;
else if ( V_8 % 8 == 7 )
printf ( L_19 ) ;
else
printf ( L_20 ) ;
}
printf ( L_21 , V_18 ) ;
V_20 = 0 ;
V_19 = 0 ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ )
{
while ( V_19 >= V_9 [ V_20 ] )
{
V_20 ++ ;
V_19 = 0 ;
}
printf ( L_22 , V_10 [ V_20 ] [ V_19 ++ ] ) ;
if ( V_8 == V_18 - 1 )
printf ( L_18 ) ;
else if ( V_8 % 8 == 7 )
printf ( L_19 ) ;
else
printf ( L_20 ) ;
}
exit ( V_27 ) ;
}
