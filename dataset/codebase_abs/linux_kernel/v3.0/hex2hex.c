static int F_1 ( T_1 * V_1 , unsigned char * V_2 )
{
int V_3 = 0 , V_4 , V_5 ;
while ( ( V_4 = getc ( V_1 ) ) != V_6 )
{
if ( V_4 == ':' )
{
int V_7 , V_8 ;
unsigned char V_9 ;
int V_10 ;
int V_11 ;
if ( fscanf ( V_1 , L_1 , & V_7 ) != 1 )
F_2 ( L_2 ) ;
V_9 = V_7 ;
if ( fscanf ( V_1 , L_3 , & V_10 ) != 1 )
F_2 ( L_2 ) ;
V_9 += V_10 / 256 ;
V_9 += V_10 % 256 ;
if ( fscanf ( V_1 , L_1 , & V_11 ) != 1 )
F_2 ( L_2 ) ;
V_9 += V_11 ;
if ( V_11 != 0 )
continue;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
{
if ( fscanf ( V_1 , L_1 , & V_4 ) != 1 )
F_2 ( L_2 ) ;
if ( V_10 >= V_12 )
F_2 ( L_4 ) ;
V_2 [ V_10 ++ ] = V_4 ;
if ( V_10 > V_3 )
V_3 = V_10 ;
V_9 += V_4 ;
}
if ( fscanf ( V_1 , L_1 , & V_8 ) != 1 )
F_2 ( L_2 ) ;
V_9 = ~ V_9 + 1 ;
if ( V_8 != V_9 )
F_2 ( L_5 ) ;
}
}
return V_3 ;
}
int main ( int V_13 , const char * V_14 [] )
{
const char * V_15 ;
int V_5 , V_3 ;
int V_16 = 0 ;
if( V_14 [ 1 ] && strcmp ( V_14 [ 1 ] , L_6 ) == 0 )
{
V_14 ++ ;
V_13 -- ;
V_16 = 1 ;
}
if( V_14 [ 1 ] == NULL )
{
fprintf ( V_17 , L_7 ) ;
exit ( 1 ) ;
}
V_15 = V_14 [ 1 ] ;
V_3 = F_1 ( V_18 , V_2 ) ;
printf ( L_8 ) ;
printf ( L_9 , V_15 , V_3 ) ;
printf ( L_10 , V_15 , V_16 ? L_11 : L_12 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
{
if ( V_5 ) printf ( L_13 ) ;
if ( V_5 && ! ( V_5 % 16 ) ) printf ( L_14 ) ;
printf ( L_15 , V_2 [ V_5 ] ) ;
}
printf ( L_16 ) ;
return 0 ;
}
