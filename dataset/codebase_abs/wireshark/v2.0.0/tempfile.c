static int
F_1 ( char * V_1 )
{
static const char V_2 []
= L_1 ;
T_1 V_3 ;
T_1 V_4 ;
V_3 = strlen ( V_1 ) ;
if ( V_3 < 6 || strcmp ( & V_1 [ V_3 - 6 ] , V_5 ) )
{
F_2 ( V_6 ) ;
return - 1 ;
}
if ( F_3 ( & V_1 [ V_3 - 5 ] , 6 , L_2 ,
( unsigned int ) F_4 () % 100000 ) != 5 )
return - 1 ;
for ( V_4 = 0 ; V_4 < sizeof ( V_2 ) ; ++ V_4 )
{
int V_7 ;
V_1 [ V_3 - 6 ] = V_2 [ V_4 ] ;
V_7 = F_5 ( V_1 , V_8 | V_9 | V_10 | V_11 , 0600 ) ;
if ( V_7 >= 0 )
return V_7 ;
}
V_1 [ 0 ] = '\0' ;
return - 1 ;
}
char *
F_6 ( char * V_1 )
{
static const char V_2 []
= L_1 ;
T_1 V_3 ;
T_1 V_4 ;
V_3 = strlen ( V_1 ) ;
if ( V_3 < 6 || strcmp ( & V_1 [ V_3 - 6 ] , V_5 ) )
{
F_2 ( V_6 ) ;
return NULL ;
}
if ( F_3 ( & V_1 [ V_3 - 5 ] , 6 , L_2 ,
( unsigned int ) F_4 () % 100000 ) != 5 )
return NULL ;
for ( V_4 = 0 ; V_4 < sizeof ( V_2 ) ; ++ V_4 )
{
int V_12 ;
V_1 [ V_3 - 6 ] = V_2 [ V_4 ] ;
V_12 = F_7 ( V_1 , 0700 ) ;
if ( V_12 >= 0 )
return V_1 ;
}
V_1 [ 0 ] = '\0' ;
return NULL ;
}
char * F_8 ( const char * V_13 )
{
return F_9 ( L_3 V_14 L_3 , F_10 () , V_13 ) ;
}
int
F_11 ( char * * V_15 , const char * V_16 )
{
static struct V_17 {
char * V_18 ;
T_1 V_3 ;
} V_19 [ V_20 ] ;
static int V_21 ;
const char * V_22 ;
int V_23 ;
int V_7 ;
T_2 V_24 ;
char V_25 [ 14 + 1 ] ;
T_3 * V_26 ;
T_3 * V_27 ;
T_3 V_28 [ 2 ] = { 0 , 0 } ;
const T_3 * V_29 = L_4
L_5
L_6
L_7 ;
V_27 = F_12 ( V_16 ) ;
V_27 = F_13 ( V_27 , V_29 , '-' ) ;
V_21 = ( V_21 + 1 ) % V_20 ;
if ( V_19 [ V_21 ] . V_18 == NULL ) {
V_19 [ V_21 ] . V_3 = V_30 ;
V_19 [ V_21 ] . V_18 = ( char * ) F_14 ( V_19 [ V_21 ] . V_3 ) ;
}
V_22 = F_10 () ;
#ifdef F_15
F_16 () ;
#endif
V_24 = time ( NULL ) ;
strftime ( V_25 , sizeof( V_25 ) , L_8 , localtime ( & V_24 ) ) ;
V_28 [ 0 ] = V_31 ;
V_26 = F_17 ( V_22 , V_28 , V_27 , L_9 , V_25 , L_9 , V_5 , NULL ) ;
F_18 ( V_27 ) ;
if ( strlen ( V_26 ) > V_19 [ V_21 ] . V_3 ) {
V_19 [ V_21 ] . V_3 = strlen ( V_26 ) + 1 ;
V_19 [ V_21 ] . V_18 = ( char * ) F_19 ( V_19 [ V_21 ] . V_18 , V_19 [ V_21 ] . V_3 ) ;
}
F_20 ( V_19 [ V_21 ] . V_18 , V_26 , V_19 [ V_21 ] . V_3 ) ;
F_18 ( V_26 ) ;
if ( V_15 ) {
* V_15 = V_19 [ V_21 ] . V_18 ;
}
V_23 = F_21 ( 0077 ) ;
V_7 = F_1 ( V_19 [ V_21 ] . V_18 ) ;
F_21 ( V_23 ) ;
return V_7 ;
}
const char *
F_22 ( char * * V_15 , const char * V_16 )
{
static char * V_32 [ 3 ] ;
static int V_33 [ 3 ] ;
static int V_21 ;
const char * V_22 ;
V_21 = ( V_21 + 1 ) % 3 ;
if ( V_32 [ V_21 ] == NULL ) {
V_33 [ V_21 ] = V_30 ;
V_32 [ V_21 ] = ( char * ) F_14 ( V_33 [ V_21 ] ) ;
}
V_22 = F_10 () ;
while ( F_3 ( V_32 [ V_21 ] , V_33 [ V_21 ] , L_10 V_5 , V_22 , V_31 , V_16 ) > V_33 [ V_21 ] ) {
V_33 [ V_21 ] *= 2 ;
V_32 [ V_21 ] = ( char * ) F_19 ( V_32 [ V_21 ] , V_33 [ V_21 ] ) ;
}
if ( V_15 ) {
* V_15 = V_32 [ V_21 ] ;
}
return F_6 ( V_32 [ V_21 ] ) ;
}
