T_1 * F_1 ( const T_2 * V_1 ,
const T_3 * V_2 ,
T_4 V_3 ,
T_1 * V_4 , T_5 * V_5 )
{
T_6 V_6 = 0 ;
unsigned char * V_7 ;
V_6 = F_2 ( V_1 , V_2 , V_3 , NULL , 0 , V_5 ) ;
if ( V_6 == 0 )
return NULL ;
if ( ( V_7 = F_3 ( V_6 ) ) == NULL )
return NULL ;
if ( ! F_2 ( V_1 , V_2 , V_3 , V_7 , V_6 , V_5 ) ) {
F_4 ( V_7 ) ;
return NULL ;
}
V_4 = F_5 ( V_7 , V_6 , V_4 ) ;
F_4 ( V_7 ) ;
return V_4 ;
}
T_3 * F_6 ( const T_2 * V_1 ,
const T_1 * V_8 , T_3 * V_2 , T_5 * V_5 )
{
T_6 V_6 = 0 ;
unsigned char * V_7 ;
T_3 * V_4 ;
if ( ( V_6 = F_7 ( V_8 ) ) == 0 )
return NULL ;
V_7 = F_3 ( V_6 ) ;
if ( V_7 == NULL )
return NULL ;
if ( ! F_8 ( V_8 , V_7 ) ) {
F_4 ( V_7 ) ;
return NULL ;
}
if ( V_2 == NULL ) {
if ( ( V_4 = F_9 ( V_1 ) ) == NULL ) {
F_4 ( V_7 ) ;
return NULL ;
}
} else
V_4 = V_2 ;
if ( ! F_10 ( V_1 , V_4 , V_7 , V_6 , V_5 ) ) {
if ( V_2 == NULL )
F_11 ( V_4 ) ;
F_4 ( V_7 ) ;
return NULL ;
}
F_4 ( V_7 ) ;
return V_4 ;
}
char * F_12 ( const T_2 * V_1 ,
const T_3 * V_2 ,
T_4 V_3 , T_5 * V_5 )
{
char * V_4 , * V_9 ;
T_6 V_6 = 0 , V_10 ;
unsigned char * V_7 , * V_11 ;
V_6 = F_2 ( V_1 , V_2 , V_3 , NULL , 0 , V_5 ) ;
if ( V_6 == 0 )
return NULL ;
if ( ( V_7 = F_3 ( V_6 ) ) == NULL )
return NULL ;
if ( ! F_2 ( V_1 , V_2 , V_3 , V_7 , V_6 , V_5 ) ) {
F_4 ( V_7 ) ;
return NULL ;
}
V_4 = ( char * ) F_3 ( V_6 * 2 + 2 ) ;
if ( V_4 == NULL ) {
F_4 ( V_7 ) ;
return NULL ;
}
V_9 = V_4 ;
V_11 = V_7 ;
for ( V_10 = V_6 ; V_10 > 0 ; V_10 -- ) {
int V_12 = ( int ) * ( V_11 ++ ) ;
* ( V_9 ++ ) = V_13 [ V_12 >> 4 ] ;
* ( V_9 ++ ) = V_13 [ V_12 & 0x0F ] ;
}
* V_9 = '\0' ;
F_4 ( V_7 ) ;
return V_4 ;
}
T_3 * F_13 ( const T_2 * V_1 ,
const char * V_7 , T_3 * V_2 , T_5 * V_5 )
{
T_3 * V_4 = NULL ;
T_1 * V_14 = NULL ;
if ( ! F_14 ( & V_14 , V_7 ) )
return NULL ;
V_4 = F_6 ( V_1 , V_14 , V_2 , V_5 ) ;
F_15 ( V_14 ) ;
return V_4 ;
}
