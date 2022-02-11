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
F_1 ( L_1 \
L_2 ) ;
}
int main ( int V_4 , char * * V_5 )
{
int V_6 , V_7 , V_8 ;
int V_9 , V_10 ;
const char * V_11 ;
T_2 * V_12 ;
int V_13 ;
unsigned char V_14 [ V_15 ] ;
V_6 = 0 ;
V_7 = 0 ;
V_8 = 0 ;
V_9 = 0 ;
V_10 = 0 ;
V_11 = NULL ;
for ( V_13 = 1 ; V_13 < V_4 ; V_13 ++ ) {
char * V_16 = V_5 [ V_13 ] ;
if ( * V_16 == '-' ) {
if ( strcmp ( V_16 , L_3 ) == 0 ) {
V_6 = 1 ;
continue;
}
if ( strcmp ( V_16 , L_4 ) == 0 ) {
V_7 = 1 ;
continue;
}
if ( strcmp ( V_16 , L_5 ) == 0 ) {
V_8 = 1 ;
continue;
}
if ( strcmp ( V_16 , L_6 ) == 0 ) {
V_9 = 1 ;
continue;
}
if ( strcmp ( V_16 , L_7 ) == 0 ) {
V_10 = 1 ;
continue;
}
}
else if ( ! V_11 ) {
V_11 = V_16 ;
continue;
}
F_2 () ;
}
if ( ! V_11 ) {
F_2 () ;
}
V_12 = fopen ( V_11 , L_8 ) ;
if ( ! V_12 ) {
F_1 ( L_9 , V_11 , strerror ( V_17 ) ) ;
}
if ( fread ( & V_14 , 1 , V_15 , V_12 ) != V_15 ) {
F_1 ( L_10 , V_11 , strerror ( V_17 ) ) ;
}
rewind ( V_12 ) ;
if ( V_14 [ V_18 ] == V_19 )
F_3 ( V_12 , V_10 , V_9 ,
V_6 , V_7 ,
V_8 ) ;
else
F_4 ( V_12 , V_10 , V_9 ,
V_6 , V_7 ,
V_8 ) ;
fclose ( V_12 ) ;
return 0 ;
}
