static void F_1 ( void )
{
unsigned int V_1 , V_2 = 0 ;
printf ( L_1 , V_3 ) ;
for ( V_1 = 0 ; V_1 < F_2 ( V_4 ) ; V_1 ++ ) {
if ( V_2 < strlen ( V_4 [ V_1 ] . V_5 ) )
V_2 = strlen ( V_4 [ V_1 ] . V_5 ) ;
}
puts ( L_2 ) ;
for ( V_1 = 0 ; V_1 < F_2 ( V_4 ) ; V_1 ++ ) {
printf ( L_3 , V_2 , V_4 [ V_1 ] . V_5 ) ;
puts ( V_4 [ V_1 ] . V_6 ) ;
}
printf ( L_4 ) ;
exit ( 1 ) ;
}
static void F_3 ( int * V_7 , const char * * * V_8 )
{
while ( * V_7 > 0 ) {
const char * V_9 = ( * V_8 ) [ 0 ] ;
if ( V_9 [ 0 ] != '-' )
break;
if ( ! strcmp ( V_9 , L_5 ) || ! strcmp ( V_9 , L_6 ) ) {
V_6 = true ;
break;
} else {
fprintf ( V_10 , L_7 , V_9 ) ;
fprintf ( V_10 , L_8 ,
V_3 ) ;
exit ( 1 ) ;
}
( * V_8 ) ++ ;
( * V_7 ) -- ;
}
}
static void F_4 ( int V_7 , const char * * V_8 )
{
const char * V_9 = V_8 [ 0 ] ;
unsigned int V_1 , V_11 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_4 ) ; V_1 ++ ) {
struct V_12 * V_13 = V_4 + V_1 ;
if ( strcmp ( V_13 -> V_5 , V_9 ) )
continue;
V_11 = V_13 -> V_14 ( V_7 , V_8 ) ;
exit ( V_11 ) ;
}
F_1 () ;
}
int main ( int V_7 , const char * * V_8 )
{
static const char * V_15 = L_9 ;
F_5 ( L_10 , V_15 , V_15 , V_15 ) ;
F_6 ( V_15 ) ;
V_8 ++ ;
V_7 -- ;
F_3 ( & V_7 , & V_8 ) ;
if ( ! V_7 || V_6 )
F_1 () ;
F_4 ( V_7 , V_8 ) ;
return 0 ;
}
