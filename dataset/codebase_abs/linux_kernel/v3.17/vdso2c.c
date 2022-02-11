static void F_1 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
fprintf ( V_3 , L_1 ) ;
vfprintf ( V_3 , V_1 , V_2 ) ;
if ( V_4 )
F_2 ( V_4 ) ;
exit ( 1 ) ;
va_end ( V_2 ) ;
}
static void F_3 ( void * V_5 , T_2 V_6 ,
void * V_7 , T_2 V_8 ,
T_3 * V_9 , const char * V_10 )
{
T_4 * V_11 = ( T_4 * ) V_5 ;
if ( V_11 -> V_12 [ V_13 ] == V_14 ) {
F_4 ( V_5 , V_6 , V_7 , V_8 ,
V_9 , V_10 ) ;
} else if ( V_11 -> V_12 [ V_13 ] == V_15 ) {
F_5 ( V_5 , V_6 , V_7 , V_8 ,
V_9 , V_10 ) ;
} else {
F_1 ( L_2 ) ;
}
}
static void F_6 ( const char * V_10 , void * * V_16 , T_2 * V_17 , int V_18 )
{
T_5 V_19 ;
int V_20 = F_7 ( V_10 , V_21 ) ;
if ( V_20 == - 1 )
F_8 ( 1 , L_3 , V_10 ) ;
V_19 = F_9 ( V_20 , 0 , V_22 ) ;
if ( V_19 == ( T_5 ) - 1 )
F_8 ( 1 , L_4 ) ;
* V_17 = ( T_2 ) V_19 ;
* V_16 = F_10 ( NULL , V_19 , V_18 , V_23 , V_20 , 0 ) ;
if ( * V_16 == V_24 )
F_8 ( 1 , L_5 ) ;
F_11 ( V_20 ) ;
}
int main ( int V_25 , char * * V_26 )
{
T_2 V_6 , V_8 ;
void * V_5 , * V_7 ;
T_3 * V_9 ;
char * V_10 , * V_27 ;
int V_28 ;
if ( V_25 != 4 ) {
printf ( L_6 ) ;
return 1 ;
}
V_10 = F_12 ( V_26 [ 3 ] ) ;
V_28 = strlen ( V_10 ) ;
if ( V_28 >= 3 && ! strcmp ( V_10 + V_28 - 3 , L_7 ) ) {
V_10 = NULL ;
} else {
V_27 = strrchr ( V_10 , '/' ) ;
if ( V_27 )
V_10 = V_27 + 1 ;
V_27 = strchr ( V_10 , '.' ) ;
if ( V_27 )
* V_27 = '\0' ;
for ( V_27 = V_10 ; * V_27 ; V_27 ++ )
if ( * V_27 == '-' )
* V_27 = '_' ;
}
F_6 ( V_26 [ 1 ] , & V_5 , & V_6 , V_29 ) ;
F_6 ( V_26 [ 2 ] , & V_7 , & V_8 , V_29 ) ;
V_4 = V_26 [ 3 ] ;
V_9 = fopen ( V_4 , L_8 ) ;
if ( ! V_9 )
F_8 ( 1 , L_3 , V_26 [ 2 ] ) ;
F_3 ( V_5 , V_6 , V_7 , V_8 , V_9 , V_10 ) ;
F_13 ( V_5 , V_6 ) ;
F_13 ( V_7 , V_8 ) ;
fclose ( V_9 ) ;
return 0 ;
}
