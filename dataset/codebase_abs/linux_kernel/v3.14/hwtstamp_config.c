static int
F_1 ( const char * * V_1 , int V_2 , const char * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ )
if ( V_1 [ V_4 ] && strcasecmp ( V_1 [ V_4 ] , V_3 ) == 0 )
return V_4 ;
return - 1 ;
}
static const char *
F_2 ( const char * * V_1 , int V_2 , int V_4 )
{
return ( V_4 >= 0 && V_4 < V_2 ) ? V_1 [ V_4 ] : NULL ;
}
static void F_3 ( T_1 * V_5 , const char * * V_1 , int V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ )
if ( V_1 [ V_4 ] )
fprintf ( V_5 , L_1 , V_1 [ V_4 ] ) ;
}
static void F_4 ( void )
{
fputs ( L_2
L_3 ,
V_6 ) ;
F_3 ( V_6 , V_7 , V_8 ) ;
fputs ( L_4 , V_6 ) ;
F_3 ( V_6 , V_9 , V_10 ) ;
}
int main ( int V_11 , char * * V_12 )
{
struct V_13 V_14 ;
struct V_15 V_16 ;
const char * V_3 ;
int V_17 ;
if ( ( V_11 != 2 && V_11 != 4 ) || ( strlen ( V_12 [ 1 ] ) >= V_18 ) ) {
F_4 () ;
return 2 ;
}
if ( V_11 == 4 ) {
V_16 . V_19 = 0 ;
V_16 . V_20 = F_1 ( V_7 , V_8 , V_12 [ 2 ] ) ;
V_16 . V_21 = F_1 ( V_9 , V_10 , V_12 [ 3 ] ) ;
if ( V_16 . V_20 < 0 || V_16 . V_21 < 0 ) {
F_4 () ;
return 2 ;
}
}
V_17 = F_5 ( V_22 , V_23 , 0 ) ;
if ( V_17 < 0 ) {
perror ( L_5 ) ;
return 1 ;
}
strcpy ( V_14 . V_24 , V_12 [ 1 ] ) ;
V_14 . V_25 = ( V_26 ) & V_16 ;
if ( F_6 ( V_17 , ( V_11 == 2 ) ? V_27 : V_28 , & V_14 ) ) {
perror ( L_6 ) ;
return 1 ;
}
printf ( L_7 , V_16 . V_19 ) ;
V_3 = F_2 ( V_7 , V_8 , V_16 . V_20 ) ;
if ( V_3 )
printf ( L_8 , V_3 ) ;
else
printf ( L_9 , V_16 . V_20 ) ;
V_3 = F_2 ( V_9 , V_10 , V_16 . V_21 ) ;
if ( V_3 )
printf ( L_10 , V_3 ) ;
else
printf ( L_11 , V_16 . V_21 ) ;
return 0 ;
}
