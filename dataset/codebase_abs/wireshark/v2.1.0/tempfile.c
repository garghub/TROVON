static int
F_1 ( char * V_1 , int V_2 )
{
static const char V_3 []
= L_1 ;
char V_4 [ 6 ] ;
T_1 V_5 ;
T_1 V_6 ;
V_5 = strlen ( V_1 ) ;
if ( V_5 < 6 || strncmp ( & V_1 [ V_5 - 6 - V_2 ] , V_7 , 6 ) )
{
F_2 ( V_8 ) ;
return - 1 ;
}
if ( F_3 ( V_4 , 6 , L_2 ,
( unsigned int ) F_4 () % 100000 ) != 5 )
return - 1 ;
memcpy ( & V_1 [ V_5 - 5 - V_2 ] , V_4 , 5 ) ;
for ( V_6 = 0 ; V_6 < sizeof ( V_3 ) ; ++ V_6 )
{
int V_9 ;
V_1 [ V_5 - 6 - V_2 ] = V_3 [ V_6 ] ;
V_9 = F_5 ( V_1 , V_10 | V_11 | V_12 | V_13 , 0600 ) ;
if ( V_9 >= 0 )
return V_9 ;
}
V_1 [ 0 ] = '\0' ;
return - 1 ;
}
char *
F_6 ( char * V_1 )
{
static const char V_3 []
= L_1 ;
T_1 V_5 ;
T_1 V_6 ;
V_5 = strlen ( V_1 ) ;
if ( V_5 < 6 || strcmp ( & V_1 [ V_5 - 6 ] , V_7 ) )
{
F_2 ( V_8 ) ;
return NULL ;
}
if ( F_3 ( & V_1 [ V_5 - 5 ] , 6 , L_2 ,
( unsigned int ) F_4 () % 100000 ) != 5 )
return NULL ;
for ( V_6 = 0 ; V_6 < sizeof ( V_3 ) ; ++ V_6 )
{
int V_14 ;
V_1 [ V_5 - 6 ] = V_3 [ V_6 ] ;
V_14 = F_7 ( V_1 , 0700 ) ;
if ( V_14 >= 0 )
return V_1 ;
}
V_1 [ 0 ] = '\0' ;
return NULL ;
}
char * F_8 ( const char * V_15 )
{
return F_9 ( L_3 V_16 L_3 , F_10 () , V_15 ) ;
}
int
F_11 ( char * * V_17 , const char * V_18 , const char * V_19 )
{
static struct V_20 {
char * V_21 ;
T_1 V_5 ;
} V_22 [ V_23 ] ;
static int V_24 ;
const char * V_25 ;
int V_26 ;
int V_9 ;
T_2 V_27 ;
char V_28 [ 14 + 1 ] ;
T_3 * V_29 ;
T_3 * V_30 ;
T_3 V_31 [ 2 ] = { 0 , 0 } ;
const T_3 * V_32 = L_4
L_5
L_6
L_7 ;
V_30 = F_12 ( V_18 ) ;
V_30 = F_13 ( V_30 , V_32 , '-' ) ;
V_24 = ( V_24 + 1 ) % V_23 ;
if ( V_22 [ V_24 ] . V_21 == NULL ) {
V_22 [ V_24 ] . V_5 = V_33 ;
V_22 [ V_24 ] . V_21 = ( char * ) F_14 ( V_22 [ V_24 ] . V_5 ) ;
}
V_25 = F_10 () ;
#ifdef F_15
F_16 () ;
#endif
V_27 = time ( NULL ) ;
strftime ( V_28 , sizeof( V_28 ) , L_8 , localtime ( & V_27 ) ) ;
V_31 [ 0 ] = V_34 ;
V_29 = F_17 ( V_25 , V_31 , V_30 , L_9 , V_28 , L_9 , V_7 , V_19 , NULL ) ;
F_18 ( V_30 ) ;
if ( strlen ( V_29 ) > V_22 [ V_24 ] . V_5 ) {
V_22 [ V_24 ] . V_5 = strlen ( V_29 ) + 1 ;
V_22 [ V_24 ] . V_21 = ( char * ) F_19 ( V_22 [ V_24 ] . V_21 , V_22 [ V_24 ] . V_5 ) ;
}
F_20 ( V_22 [ V_24 ] . V_21 , V_29 , V_22 [ V_24 ] . V_5 ) ;
F_18 ( V_29 ) ;
if ( V_17 ) {
* V_17 = V_22 [ V_24 ] . V_21 ;
}
V_26 = F_21 ( 0077 ) ;
V_9 = F_1 ( V_22 [ V_24 ] . V_21 , V_19 ? ( int ) strlen ( V_19 ) : 0 ) ;
F_21 ( V_26 ) ;
return V_9 ;
}
const char *
F_22 ( char * * V_17 , const char * V_18 )
{
static char * V_35 [ 3 ] ;
static int V_36 [ 3 ] ;
static int V_24 ;
const char * V_25 ;
V_24 = ( V_24 + 1 ) % 3 ;
if ( V_35 [ V_24 ] == NULL ) {
V_36 [ V_24 ] = V_33 ;
V_35 [ V_24 ] = ( char * ) F_14 ( V_36 [ V_24 ] ) ;
}
V_25 = F_10 () ;
while ( F_3 ( V_35 [ V_24 ] , V_36 [ V_24 ] , L_10 V_7 , V_25 , V_34 , V_18 ) > V_36 [ V_24 ] ) {
V_36 [ V_24 ] *= 2 ;
V_35 [ V_24 ] = ( char * ) F_19 ( V_35 [ V_24 ] , V_36 [ V_24 ] ) ;
}
if ( V_17 ) {
* V_17 = V_35 [ V_24 ] ;
}
return F_6 ( V_35 [ V_24 ] ) ;
}
