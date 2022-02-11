int F_1 ( const char * V_1 , unsigned long * V_2 )
{
#ifdef F_2
char * V_3 ;
unsigned long V_4 = strtoul ( V_1 , & V_3 , 10 ) ;
if( ( V_1 == V_3 ) || ( * V_3 != '\0' ) )
return 0 ;
if( V_4 == V_5 )
return 0 ;
* V_2 = V_4 ;
return 1 ;
#else
char V_6 [ 2 ] ;
unsigned long V_4 = 0 ;
V_6 [ 1 ] = '\0' ;
if( V_1 == '\0' )
return 0 ;
while( * V_1 != '\0' ) {
if( V_4 && ( ( ( V_5 + 10 ) / V_4 ) < 10 ) )
return 0 ;
V_4 *= 10 ;
if( ! isdigit ( * V_1 ) )
return 0 ;
V_6 [ 0 ] = * V_1 ;
V_4 += atoi ( V_6 ) ;
V_1 ++ ;
}
* V_2 = V_4 ;
return 1 ;
#endif
}
char * F_3 ( const char * V_7 , const char * V_8 )
{
const char * V_9 = V_7 , * V_10 = V_8 ;
unsigned int V_11 = 0 ;
if( ! V_8 )
return V_7 ;
if( ! V_7 )
return NULL ;
while( ( * V_9 != '\0' ) && ( * V_10 != '\0' ) ) {
if( V_9 [ V_11 ] == V_10 ) {
V_11 ++ ;
V_10 ++ ;
} else {
V_9 ++ ;
V_11 = 0 ;
V_10 = V_8 ;
}
}
if( * V_9 == '\0' )
return NULL ;
return V_9 ;
}
