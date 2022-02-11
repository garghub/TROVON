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
int
F_8 ( char * * V_13 , const char * V_14 )
{
static struct V_15 {
char * V_16 ;
unsigned long V_3 ;
} V_17 [ V_18 ] ;
static int V_19 ;
const char * V_20 ;
int V_21 ;
int V_7 ;
T_2 V_22 ;
char V_23 [ 14 + 1 ] ;
T_3 * V_24 ;
T_3 * V_25 ;
T_3 V_26 [ 2 ] = { 0 , 0 } ;
const T_3 * V_27 = L_3
L_4
L_5
L_6 ;
V_25 = F_9 ( V_14 ) ;
V_25 = F_10 ( V_25 , V_27 , '-' ) ;
V_19 = ( V_19 + 1 ) % V_18 ;
if ( V_17 [ V_19 ] . V_16 == NULL ) {
V_17 [ V_19 ] . V_3 = V_28 ;
V_17 [ V_19 ] . V_16 = ( char * ) F_11 ( V_17 [ V_19 ] . V_3 ) ;
}
V_20 = F_12 () ;
#ifdef F_13
F_14 () ;
#endif
V_22 = time ( NULL ) ;
strftime ( V_23 , sizeof( V_23 ) , L_7 , localtime ( & V_22 ) ) ;
V_26 [ 0 ] = V_29 ;
V_24 = F_15 ( V_20 , V_26 , V_25 , L_8 , V_23 , L_8 , V_5 , NULL ) ;
F_16 ( V_25 ) ;
if ( strlen ( V_24 ) > V_17 [ V_19 ] . V_3 ) {
V_17 [ V_19 ] . V_3 = ( int ) strlen ( V_24 ) + 1 ;
V_17 [ V_19 ] . V_16 = ( char * ) F_17 ( V_17 [ V_19 ] . V_16 , V_17 [ V_19 ] . V_3 ) ;
}
F_18 ( V_17 [ V_19 ] . V_16 , V_24 , V_17 [ V_19 ] . V_3 ) ;
F_16 ( V_24 ) ;
if ( V_13 ) {
* V_13 = V_17 [ V_19 ] . V_16 ;
}
V_21 = F_19 ( 0077 ) ;
V_7 = F_1 ( V_17 [ V_19 ] . V_16 ) ;
F_19 ( V_21 ) ;
return V_7 ;
}
const char *
F_20 ( char * * V_13 , const char * V_14 )
{
static char * V_30 [ 3 ] ;
static int V_31 [ 3 ] ;
static int V_19 ;
const char * V_20 ;
V_19 = ( V_19 + 1 ) % 3 ;
if ( V_30 [ V_19 ] == NULL ) {
V_31 [ V_19 ] = V_28 ;
V_30 [ V_19 ] = ( char * ) F_11 ( V_31 [ V_19 ] ) ;
}
V_20 = F_12 () ;
while ( F_3 ( V_30 [ V_19 ] , V_31 [ V_19 ] , L_9 V_5 , V_20 , V_29 , V_14 ) > V_31 [ V_19 ] ) {
V_31 [ V_19 ] *= 2 ;
V_30 [ V_19 ] = ( char * ) F_17 ( V_30 [ V_19 ] , V_31 [ V_19 ] ) ;
}
if ( V_13 ) {
* V_13 = V_30 [ V_19 ] ;
}
return F_6 ( V_30 [ V_19 ] ) ;
}
