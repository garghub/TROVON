static void F_1 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
fprintf ( V_3 , L_1 ) ;
vfprintf ( V_3 , V_1 , V_2 ) ;
F_2 ( V_4 ) ;
exit ( 1 ) ;
va_end ( V_2 ) ;
}
static void F_3 ( void * V_5 , T_2 V_6 , T_3 * V_7 , const char * V_8 )
{
T_4 * V_9 = ( T_4 * ) V_5 ;
if ( V_9 -> V_10 [ V_11 ] == V_12 ) {
F_4 ( V_5 , V_6 , V_7 , V_8 ) ;
} else if ( V_9 -> V_10 [ V_11 ] == V_13 ) {
F_5 ( V_5 , V_6 , V_7 , V_8 ) ;
} else {
F_1 ( L_2 ) ;
}
}
int main ( int V_14 , char * * V_15 )
{
int V_16 ;
T_5 V_6 ;
void * V_5 ;
T_3 * V_7 ;
char * V_8 , * V_17 ;
int V_18 ;
if ( V_14 != 3 ) {
printf ( L_3 ) ;
return 1 ;
}
V_8 = F_6 ( V_15 [ 2 ] ) ;
V_18 = strlen ( V_8 ) ;
if ( V_18 >= 3 && ! strcmp ( V_8 + V_18 - 3 , L_4 ) ) {
V_8 = NULL ;
} else {
V_17 = strrchr ( V_8 , '/' ) ;
if ( V_17 )
V_8 = V_17 + 1 ;
V_17 = strchr ( V_8 , '.' ) ;
if ( V_17 )
* V_17 = '\0' ;
for ( V_17 = V_8 ; * V_17 ; V_17 ++ )
if ( * V_17 == '-' )
* V_17 = '_' ;
}
V_16 = F_7 ( V_15 [ 1 ] , V_19 ) ;
if ( V_16 == - 1 )
F_8 ( 1 , L_5 , V_15 [ 1 ] ) ;
V_6 = F_9 ( V_16 , 0 , V_20 ) ;
if ( V_6 == ( T_5 ) - 1 )
F_8 ( 1 , L_6 ) ;
V_5 = F_10 ( NULL , V_6 , V_21 | V_22 , V_23 , V_16 , 0 ) ;
if ( V_5 == V_24 )
F_8 ( 1 , L_7 ) ;
V_4 = V_15 [ 2 ] ;
V_7 = fopen ( V_4 , L_8 ) ;
if ( ! V_7 )
F_8 ( 1 , L_5 , V_15 [ 2 ] ) ;
F_3 ( V_5 , ( T_2 ) V_6 , V_7 , V_8 ) ;
F_11 ( V_5 , V_6 ) ;
fclose ( V_7 ) ;
return 0 ;
}
