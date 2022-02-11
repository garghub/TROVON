T_1 * F_1 ( const char * V_1 , const char * V_2 )
{
T_1 * V_3 = NULL ;
# if F_2 ( V_4 ) && F_2 ( V_5 )
int V_6 , V_7 = ( int ) strlen ( V_1 ) + 1 ;
T_2 V_8 ;
if ( ( V_6 = F_3 ( V_5 , ( V_8 = V_9 ) ,
V_1 , V_7 , NULL , 0 ) ) > 0 ||
( F_4 () == V_10 &&
( V_6 = F_3 ( V_5 , ( V_8 = 0 ) ,
V_1 , V_7 , NULL , 0 ) ) > 0 )
) {
T_3 V_11 [ 8 ] ;
T_3 * V_12 = F_5 ( V_6 * sizeof( T_3 ) ) ;
if ( F_3 ( V_5 , V_8 ,
V_1 , V_7 , V_12 , V_6 ) &&
F_3 ( V_5 , 0 , V_2 , strlen ( V_2 ) + 1 ,
V_11 , F_6 ( V_11 ) ) &&
( V_3 = F_7 ( V_12 , V_11 ) ) == NULL &&
( V_13 == V_14 || V_13 == V_15 )
) {
V_3 = fopen ( V_1 , V_2 ) ;
}
} else if ( F_4 () == V_16 ) {
V_3 = fopen ( V_1 , V_2 ) ;
}
# elif F_2 ( V_17 )
{
char * V_18 = NULL ;
if ( ! F_8 ( V_1 ) ) {
char * V_19 ;
char V_20 ;
V_18 = F_9 ( strlen ( V_1 ) + 1 ) ;
if ( V_18 == NULL )
return NULL ;
for ( V_19 = V_18 , V_20 = '\0' ;
* V_1 ; V_1 ++ , V_19 ++ ) {
if ( V_20 == '/' && V_1 [ 0 ] == '.'
&& V_1 [ 1 ] != '.' && V_1 [ 1 ] != '/' ) {
* V_19 = '_' ;
} else {
* V_19 = * V_1 ;
}
V_20 = * V_1 ;
}
* V_19 = '\0' ;
V_1 = V_18 ;
}
V_3 = fopen ( V_1 , V_2 ) ;
F_10 ( V_18 ) ;
}
# else
V_3 = fopen ( V_1 , V_2 ) ;
# endif
return V_3 ;
}
void * F_1 ( const char * V_1 , const char * V_2 )
{
return NULL ;
}
