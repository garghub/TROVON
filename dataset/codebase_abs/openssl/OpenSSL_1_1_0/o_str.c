int F_1 ( const void * V_1 , const void * V_2 , T_1 V_3 )
{
const unsigned char * V_4 = V_1 , * V_5 = V_2 ;
int V_6 = 0 ;
while ( V_3 && ( V_6 = * V_4 - * V_5 ) == 0 )
V_3 -- , V_4 ++ , V_5 ++ ;
return V_6 ;
}
char * F_2 ( const char * V_7 , const char * V_8 , int line )
{
char * V_6 ;
T_1 V_9 ;
if ( V_7 == NULL )
return NULL ;
V_9 = strlen ( V_7 ) + 1 ;
V_6 = F_3 ( V_9 , V_8 , line ) ;
if ( V_6 != NULL )
memcpy ( V_6 , V_7 , V_9 ) ;
return V_6 ;
}
char * F_4 ( const char * V_7 , T_1 V_10 , const char * V_8 , int line )
{
T_1 V_11 ;
char * V_6 ;
if ( V_7 == NULL )
return NULL ;
V_11 = F_5 ( V_7 , V_10 ) ;
V_6 = F_3 ( V_11 + 1 , V_8 , line ) ;
if ( V_6 ) {
memcpy ( V_6 , V_7 , V_11 ) ;
V_6 [ V_11 ] = '\0' ;
}
return V_6 ;
}
void * F_6 ( const void * V_12 , T_1 V_13 , const char * V_8 , int line )
{
void * V_6 ;
if ( V_12 == NULL || V_13 >= V_14 )
return NULL ;
V_6 = F_3 ( V_13 , V_8 , line ) ;
if ( V_6 == NULL ) {
F_7 ( V_15 , V_16 ) ;
return NULL ;
}
return memcpy ( V_6 , V_12 , V_13 ) ;
}
T_1 F_5 ( const char * V_7 , T_1 V_11 )
{
const char * V_17 ;
for ( V_17 = V_7 ; V_11 -- != 0 && * V_17 != '\0' ; ++ V_17 ) ;
return V_17 - V_7 ;
}
T_1 F_8 ( char * V_18 , const char * V_19 , T_1 V_9 )
{
T_1 V_20 = 0 ;
for (; V_9 > 1 && * V_19 ; V_9 -- ) {
* V_18 ++ = * V_19 ++ ;
V_20 ++ ;
}
if ( V_9 )
* V_18 = '\0' ;
return V_20 + strlen ( V_19 ) ;
}
T_1 F_9 ( char * V_18 , const char * V_19 , T_1 V_9 )
{
T_1 V_20 = 0 ;
for (; V_9 > 0 && * V_18 ; V_9 -- , V_18 ++ )
V_20 ++ ;
return V_20 + F_8 ( V_18 , V_19 , V_9 ) ;
}
int F_10 ( unsigned char V_21 )
{
#ifdef F_11
V_21 = V_22 [ V_21 ] ;
#endif
switch ( V_21 ) {
case '0' :
return 0 ;
case '1' :
return 1 ;
case '2' :
return 2 ;
case '3' :
return 3 ;
case '4' :
return 4 ;
case '5' :
return 5 ;
case '6' :
return 6 ;
case '7' :
return 7 ;
case '8' :
return 8 ;
case '9' :
return 9 ;
case 'a' : case 'A' :
return 0x0A ;
case 'b' : case 'B' :
return 0x0B ;
case 'c' : case 'C' :
return 0x0C ;
case 'd' : case 'D' :
return 0x0D ;
case 'e' : case 'E' :
return 0x0E ;
case 'f' : case 'F' :
return 0x0F ;
}
return - 1 ;
}
unsigned char * F_12 ( const char * V_7 , long * V_23 )
{
unsigned char * V_24 , * V_25 ;
unsigned char V_26 , V_27 ;
int V_28 , V_29 ;
const unsigned char * V_17 ;
T_1 V_10 ;
V_10 = strlen ( V_7 ) ;
if ( ( V_24 = F_13 ( V_10 >> 1 ) ) == NULL ) {
F_7 ( V_30 , V_16 ) ;
return NULL ;
}
for ( V_17 = ( const unsigned char * ) V_7 , V_25 = V_24 ; * V_17 ; ) {
V_26 = * V_17 ++ ;
if ( V_26 == ':' )
continue;
V_27 = * V_17 ++ ;
if ( ! V_27 ) {
F_7 ( V_30 ,
V_31 ) ;
F_14 ( V_24 ) ;
return NULL ;
}
V_29 = F_10 ( V_27 ) ;
V_28 = F_10 ( V_26 ) ;
if ( V_29 < 0 || V_28 < 0 ) {
F_14 ( V_24 ) ;
F_7 ( V_30 , V_32 ) ;
return NULL ;
}
* V_25 ++ = ( unsigned char ) ( ( V_28 << 4 ) | V_29 ) ;
}
if ( V_23 )
* V_23 = V_25 - V_24 ;
return V_24 ;
}
char * F_15 ( const unsigned char * V_33 , long V_23 )
{
const static char V_34 [] = L_1 ;
char * V_35 , * V_25 ;
const unsigned char * V_17 ;
int V_36 ;
if ( V_23 == 0 )
{
return F_16 ( 1 ) ;
}
if ( ( V_35 = F_13 ( V_23 * 3 ) ) == NULL ) {
F_7 ( V_37 , V_16 ) ;
return NULL ;
}
V_25 = V_35 ;
for ( V_36 = 0 , V_17 = V_33 ; V_36 < V_23 ; V_36 ++ , V_17 ++ ) {
* V_25 ++ = V_34 [ ( * V_17 >> 4 ) & 0xf ] ;
* V_25 ++ = V_34 [ * V_17 & 0xf ] ;
* V_25 ++ = ':' ;
}
V_25 [ - 1 ] = 0 ;
#ifdef F_11
F_17 ( V_35 , V_35 , V_25 - V_35 - 1 ) ;
#endif
return V_35 ;
}
int F_18 ( int V_38 , char * V_39 , T_1 V_40 )
{
#if F_19 ( V_41 ) && V_41 >= 1400
return ! F_20 ( V_39 , V_40 , V_38 ) ;
#elif F_19 ( V_42 )
return F_21 ( V_38 , V_39 , V_40 ) != NULL ;
#elif ( V_43 >= 200112L || V_44 >= 600 )
return ! F_21 ( V_38 , V_39 , V_40 ) ;
#else
char * V_45 ;
if ( V_40 < 2 )
return 0 ;
V_45 = strerror ( V_38 ) ;
if ( V_45 == NULL )
return 0 ;
strncpy ( V_39 , V_45 , V_40 - 1 ) ;
V_39 [ V_40 - 1 ] = '\0' ;
return 1 ;
#endif
}
