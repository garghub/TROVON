void F_1 ( char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
vfprintf ( V_3 , V_1 , V_2 ) ;
va_end ( V_2 ) ;
exit ( 1 ) ;
}
static void F_2 ( void )
{
F_1 ( L_1 ) ;
}
int main ( int V_4 , char * * V_5 )
{
int V_6 , V_7 , V_8 , V_9 ;
const char * V_10 ;
T_2 * V_11 ;
int V_12 ;
unsigned char V_13 [ V_14 ] ;
V_6 = 0 ;
V_7 = 0 ;
V_8 = 0 ;
V_9 = 0 ;
V_10 = NULL ;
for ( V_12 = 1 ; V_12 < V_4 ; V_12 ++ ) {
char * V_15 = V_5 [ V_12 ] ;
if ( * V_15 == '-' ) {
if ( strcmp ( V_15 , L_2 ) == 0 ) {
V_6 = 1 ;
continue;
}
if ( strcmp ( V_15 , L_3 ) == 0 ) {
V_7 = 1 ;
continue;
}
if ( strcmp ( V_15 , L_4 ) == 0 ) {
V_8 = 1 ;
continue;
}
if ( strcmp ( V_15 , L_5 ) == 0 ) {
V_9 = 1 ;
continue;
}
} else if ( ! V_10 ) {
V_10 = V_15 ;
continue;
}
F_2 () ;
}
if ( ! V_10 )
F_2 () ;
V_11 = fopen ( V_10 , L_6 ) ;
if ( ! V_11 )
F_1 ( L_7 , V_10 , strerror ( V_16 ) ) ;
if ( fread ( & V_13 , 1 , V_14 , V_11 ) != V_14 )
F_1 ( L_8 , V_10 , strerror ( V_16 ) ) ;
rewind ( V_11 ) ;
if ( V_13 [ V_17 ] == V_18 )
F_3 ( V_11 , V_7 , V_8 , V_6 , V_9 ) ;
else
F_4 ( V_11 , V_7 , V_8 , V_6 , V_9 ) ;
fclose ( V_11 ) ;
return 0 ;
}
